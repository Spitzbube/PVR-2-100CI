/******************************************************************************
** \file        adi/test/src/shell.c
**
** \brief       A generic command shell implemntation
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. GOKE MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS
**
** (C) Copyright 2013-2014 by GOKE MICROELECTRONICS CO.,LTD
**
*****************************************************************************
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "adi_types.h"
#include "adi_sys.h"
#include "shell.h"

#include <termio.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <dirent.h>
#include <unistd.h>
#include <assert.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>

//***************************************************************************
//***************************************************************************
//** Defines and Macros
//***************************************************************************
//***************************************************************************

#define SHELL_ColorFgBlack     ""
#define SHELL_ColorFgRed       ""
#define SHELL_ColorFgGreen     ""
#define SHELL_ColorFgBlue      ""
#define SHELL_ColorBgWhite     ""
#define SHELL_CommandTableSize  64
#define SHELL_ArgvSize          32
#define SHELL_PostTableSize     64

#define SHELL_COMMAND_STRING_SIZE   160
#define SHELL_CCAHE     (10)
#define SHELL_CMD       "shell "

inline int char_is_number(char ch)
{
    return (ch >= '0' && ch <= '9');
}

inline int char_is_point(char ch)
{
    return (ch == '.');
}

inline int char_is_nagative(char ch)
{
    return (ch == '-');
}

inline int char_is_char(char ch)
{
    return (ch >= ' ' && ch <= 126);
}

//***************************************************************************
//***************************************************************************
//** Local Types
//***************************************************************************
//***************************************************************************
typedef struct SHELL_CommandStruct
{
    char     *command;
    char     *brief;
    char     *description;
    int (*function)(int, char**);
} SHELL_CommandStr;

typedef struct
{
    GADI_U8 readIndex;
    GADI_U8 writeIndex;
    char    count;
    char    postCommandTable[SHELL_PostTableSize][SHELL_COMMAND_STRING_SIZE];
    int     mutex;
} SHELL_POST_CommandListT;


//***************************************************************************
//***************************************************************************
//** Local Data
//***************************************************************************
//***************************************************************************
static SHELL_CommandStr   commandTable[SHELL_CommandTableSize];
static char               inputCommand[SHELL_COMMAND_STRING_SIZE];
static SHELL_POST_CommandListT postList;
static struct termios gterm;
static int gtext_offset = 0;
//*****************************************************************************
//*****************************************************************************
//** Local Function declaration
//*****************************************************************************
//*****************************************************************************

static void function_thread(void *data);
static void shell_signal_setup(void);
static void shell_signal_restore(void);
static void shell_interrupt_reset_lock();
static void shell_interrupt_reset_unlock();

//*****************************************************************************
//*****************************************************************************
//** API Functions
//*****************************************************************************
//*****************************************************************************

int shell_helpcommand(int argc, char* argv[])
{
    int length;
    int index;

    if(argc == 1)
    {
        printf("\n");
        printf("Available commands:\n");
        printf("-------------------\n");

        for(index = 0; index < SHELL_CommandTableSize; index++)
        {
            if(commandTable[index].description != NULL)
            {
                length = (int)strlen((const char *)commandTable[index].description);

                if((length > 0)
                        && (commandTable[index].description[length - 1] == '\n'))
                    commandTable[index].description[length - 1] = '\0';

                if((commandTable[index].command  != NULL)
                        && (commandTable[index].function != NULL)
                        && (commandTable[index].brief    != NULL))
                {
                    if (strlen(commandTable[index].command) <= 6) {
                        printf("[%s%s%s\t\t] : %s\n",
                                         SHELL_ColorFgBlue,
                                         commandTable[index].command,
                                         SHELL_ColorFgBlack,
                                         commandTable[index].brief);
                    }
                    else {
                        printf("[%s%s%s\t] : %s\n",
                                         SHELL_ColorFgBlue,
                                         commandTable[index].command,
                                         SHELL_ColorFgBlack,
                                         commandTable[index].brief);
                    }
                }
            }
        }

        printf("\n");
        return 0;
    }

    if(argc == 2)
    {
        printf("Command help:\n");
        printf("-------------\n");

        for(index = 0; index < SHELL_CommandTableSize; index++)
        {
            if(commandTable[index].command != NULL)
            {
                if(strcmp((char *)commandTable[index].command, (char *)argv[1]) == 0)
                {
                    if(commandTable[index].description != NULL)
                    {
                        length = (int)strlen((char *)commandTable[index].description);

                        if((length > 0)
                                && (commandTable[index].description[length - 1] == '\n'))
                            commandTable[index].description[length - 1] = '\0';

                        if((commandTable[index].command  != NULL)
                                && (commandTable[index].function != NULL)
                                && (commandTable[index].brief    != NULL))
                        {
                            printf("[%s%s%s] : %s\n",
                                             SHELL_ColorFgBlue,
                                             commandTable[index].command,
                                             SHELL_ColorFgBlack,
                                             commandTable[index].brief);

                            if(commandTable[index].description
                                    && commandTable[index].description[0])
                                     printf("%s\n",
                                                 commandTable[index].description);
                        }
                    }
                }
            }
        }

        printf("\n");
        return 0;
    }

    return -1;
}

int shell_docommand(char* command)
{
    int   i, argc, index;
    char    *argv[SHELL_ArgvSize + 1];
    int  result;

    if(command && command[0])
    {
        if(inputCommand != command)
        {
            strcpy(inputCommand, command);
        }

        /* split string */
        i = argc = 0;
        while(command[i] == ' ')
        {
            i++;
        }

        argv[argc] = &command[i];

        while(command[i] != '\0')
        {
            if(command[i] == ' ')
            {
                while(command[i] == ' ')
                {
                    command[i++] = '\0';
                }

                argv[++argc] = &command[i];
            }
            else
            {
                i++;
            }
        }

        argv[++argc] = &command[i];

        if(strlen(argv[0]) == 0)
        {
            return -1;
        }

        /* check command */
        for(index = 0; index < SHELL_CommandTableSize; index++)
        {
            if((commandTable[index].command  != NULL)
                    && (commandTable[index].function != NULL)
                    && (strcmp(commandTable[index].command, argv[0]) == 0))
            {
                result = commandTable[index].function(argc, argv);
                if(result != 0)
                {
                    printf("%s\nError: bad/unknown sub command(s) for \"%s\"\n%s",
                                     SHELL_ColorFgRed, argv[0], SHELL_ColorFgBlack);
                    strcpy(inputCommand, "? ");
                    strcat(inputCommand, argv[0]);
                    shell_docommand(inputCommand);
                    return -1;
                }
                return 0;
            }
        }

        //printf("%s\nError: unknown command \"%s\"\n%s",
        //                SHELL_ColorFgRed, argv[0], SHELL_ColorFgBlack);
    }

    return -2;
}


int shell_registercommand(char  *command,
                          int (*function)(int, char**),
                          char  *brief,
                          char  *description)
{
    int status = -100;
    int index;

    if(!(command && function && brief))
        return -1;

    for(index = 0; index < SHELL_CommandTableSize; index++)
    {
        if(commandTable[index].command == NULL)
        {
            if(description == NULL)
                description = " ";

            commandTable[index].command  =
                (char*)gadi_sys_malloc(strlen(command) + 1);
            commandTable[index].brief =
                (char*)gadi_sys_malloc(strlen(brief) + 1);
            commandTable[index].description =
                (char*)gadi_sys_malloc(strlen(description) + 1);

            if((commandTable[index].command     == NULL)
                    || (commandTable[index].brief       == NULL)
                    || (commandTable[index].description == NULL))
            {
                gadi_sys_free((commandTable[index].command));
                gadi_sys_free((commandTable[index].brief));
                gadi_sys_free((commandTable[index].description));
                commandTable[index].command     = NULL;
                commandTable[index].brief       = NULL;
                commandTable[index].description = NULL;
                commandTable[index].function    = NULL;
                status = -2;
                printf("%s\nError: cannot register command\n%s",
                                 SHELL_ColorFgRed, SHELL_ColorFgBlack);
                break;
            }
            strcpy(commandTable[index].command, command);
            strcpy(commandTable[index].brief, brief);
            strcpy(commandTable[index].description, description);
            commandTable[index].function = function;
            status = 0;
            break;
        }
    }

    return(status);
}


int shell_postcommand(char* command)
{
    int comLen ;

    if(command == NULL)
    {
        return -1;
    }

    comLen = strlen(command);

    if(comLen >= SHELL_COMMAND_STRING_SIZE)
    {
        printf("shell_postcommand: command 's length exceed the max length\n");
        return -1;
    }


    if(postList.count == SHELL_PostTableSize)
    {
        printf("shell_postcommand: command list is full\n");
        return -1;
    }

    gadi_sys_sem_wait(postList.mutex);
    strcpy(postList.postCommandTable[postList.writeIndex++], command);
    postList.writeIndex %= SHELL_PostTableSize;
    postList.count++;
    gadi_sys_sem_post(postList.mutex);
    return 0;
}

int shell_getcommand(char *command)
{
    if(postList.count == 0 || command == NULL)
    {
        return -1;
    }

    gadi_sys_sem_wait(postList.mutex);
    strcpy(command, postList.postCommandTable[postList.readIndex++]);
    postList.readIndex %= SHELL_PostTableSize;
    postList.count--;
    gadi_sys_sem_post(postList.mutex);
    return 0;
}

void shell_init(int priority)
{

    memset(&postList, 0, sizeof(postList));
    memset(commandTable, 0, sizeof(commandTable));
    memset(inputCommand, 0, sizeof(inputCommand));
    postList.mutex = gadi_sys_sem_create(1);

    gadi_sys_thread_create(function_thread, NULL, priority, GADI_SYS_THREAD_STATCK_SIZE_DEFAULT, "shell input", NULL);
}

int shell_system(const char *cmd)
{
    typedef void (*sighandler_t)(int);
	pid_t pid;
    sighandler_t chld_handle = NULL;
	int ret;

	if(cmd == NULL) {
		return 1;
	}

	shell_interrupt_reset_lock();
	shell_signal_restore();
    chld_handle = signal(SIGCHLD, SIG_DFL);
	if((pid = vfork()) < 0) {
		printf("create new proccess failed\n");
        signal(SIGCHLD, chld_handle);
		ret = -1;
	} else if (pid == 0) {
		//printf("  #%s\n", cmd);
		execl("/bin/sh", "sh", "-c", cmd, (char *)0);
		exit(127);
	} else {
		//printf("enter waitpid\n");
		shell_signal_setup();
		while(waitpid(pid, &ret, 0) < 0){
			if (errno != EINTR) {
				ret = -1;
				break;
			}
		}
		//printf("exit waitpid[%d]\n", ret);
	}
	shell_interrupt_reset_unlock();
    signal(SIGCHLD, chld_handle);
	return ret;
}

int get_value_to_str(PARAMS_STRCUT *sub_params, char *strbuf, int buf_len)
{
    int len = 0;
    switch (sub_params->type) {
        case PARAMS_CHAR:
            len = snprintf(strbuf, buf_len, "%c",
                *((char *)sub_params->addr));
            break;
        case PARAMS_UCHAR:
            len = snprintf(strbuf, buf_len, "%u",
                *((unsigned char *)sub_params->addr));
            break;
        case PARAMS_SCHAR:
            len = snprintf(strbuf, buf_len, "%d",
                *((signed char *)sub_params->addr));
            break;
        case PARAMS_SHORT:
            len = snprintf(strbuf, buf_len, "%d",
                *((short *)sub_params->addr));
            break;
        case PARAMS_USHORT:
            len = snprintf(strbuf, buf_len, "%u",
                *((unsigned short *)sub_params->addr));
            break;
        case PARAMS_UINT:
            len = snprintf(strbuf, buf_len, "%u",
                *((unsigned int *)sub_params->addr));
            break;
        case PARAMS_INT:
        case PARAMS_ENUM:
            len = snprintf(strbuf, buf_len, "%d",
                *((int *)sub_params->addr));
            break;
        case PARAMS_STRING:
            strncpy(strbuf, *((char **)(sub_params->addr)), buf_len);
            len = strlen(strbuf) + 1;
            break;
        case PARAMS_FLOAT:
            len = snprintf(strbuf, buf_len, "%f",
                *((float *)sub_params->addr));
            break;
        case PARAMS_DOUBLE:
            len = snprintf(strbuf, buf_len, "%lf",
                *((double *)sub_params->addr));
            break;
        default:
            strcpy(strbuf, "");
            break;
    }

    return len;
}

void set_value_by_str(PARAMS_STRCUT *sub_params, char *strbuf)
{
    switch (sub_params->type) {
        case PARAMS_CHAR:
            *((char *)sub_params->addr) = strbuf[0];
            break;
        case PARAMS_UCHAR:
            *((unsigned char *)sub_params->addr) = (unsigned char)atoi(strbuf);
            break;
        case PARAMS_SCHAR:
            *((signed char *)sub_params->addr) = (signed char)atoi(strbuf);
            break;
        case PARAMS_SHORT:
            *((short *)sub_params->addr) = (short)atoi(strbuf);
            break;
        case PARAMS_USHORT:
            *((unsigned short *)sub_params->addr) =
                (unsigned short)atoi(strbuf);
            break;
        case PARAMS_UINT:
            *((unsigned int *)sub_params->addr) = (unsigned int)atoi(strbuf);
            break;
        case PARAMS_INT:
        case PARAMS_ENUM:
            *((int *)sub_params->addr) = atoi(strbuf);
            break;
        case PARAMS_STRING:
            strcpy(*(char **)sub_params->addr, strbuf);
            break;
        case PARAMS_FLOAT:
            *(float *)sub_params->addr = (float)atof(strbuf);
            break;
        case PARAMS_DOUBLE:
            *(double *)sub_params->addr = atof(strbuf);
            break;
        default:
            *(int *)sub_params->addr = 0;
            break;
    }
}

void display_parameters(PARAMS_STRCUT *sub_params)
{
    switch (sub_params->type) {
        case PARAMS_CHAR:
            fprintf(stderr, "  %-30.30s = [%c] | %-40s\n", sub_params->name,
                *(char *)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_UCHAR:
            fprintf(stderr, "  %-30.30s = [%u] | %-40s\n", sub_params->name,
                *(unsigned char *)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_SCHAR:
            fprintf(stderr, "  %-30.30s = [%d] | %-40s\n", sub_params->name,
                *(signed char *)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_SHORT:
            fprintf(stderr, "  %-30.30s = [%d] | %-40s\n", sub_params->name,
                *(short *)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_USHORT:
            fprintf(stderr, "  %-30.30s = [%u] | %-40s\n", sub_params->name,
                *(unsigned short *)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_UINT:
            fprintf(stderr, "  %-30.30s = [%u] | %-40s\n", sub_params->name,
                *(unsigned int *)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_INT:
        case PARAMS_ENUM:
            fprintf(stderr, "  %-30.30s = [%d] | %-40s\n", sub_params->name,
                *(int *)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_STRING:
            fprintf(stderr, "  %-30.30s = [%s] | %-40s\n", sub_params->name,
                *(char **)sub_params->addr, sub_params->hint);
            break;
        case PARAMS_FLOAT:
        case PARAMS_DOUBLE:
            fprintf(stderr, "  %-30.30s = [%f] | %-40s\n", sub_params->name,
                *(double *)sub_params->addr, sub_params->hint);
            break;
        default:
            fprintf(stderr, "  %-30.30s = [%d] | %-40s\n", sub_params->name,
                *(int *)sub_params->addr, sub_params->hint);
            break;
    }
}

static int g_esc_menu = 1;
static pthread_mutex_t menu_mutex = PTHREAD_MUTEX_INITIALIZER;
void esc_sig_handle(int sig)
{
    g_esc_menu = 0;
    fprintf(stderr, "\033[2J\033[0;0H");
}

int shell_get_param_by_menu(const char* s_name, PARAMS_STRCUT *sub_params, int size)
{
    int i;
    char ch;
    int lines = size - 1;
    int content_len[size];
    char contents[size][20];
    int cur_flag_y = 0;
    int cur_flag_x = 0;
    const int left_offset = 37;
    void (*int_sig_bk)(int) = NULL;

    pthread_mutex_lock(&menu_mutex);
    g_esc_menu = 1;
    memset(contents, 0, sizeof(contents));

    fprintf(stderr, "\033[2J\033[0;0H");
    fprintf(stderr, "Please enter %s params:\n", s_name);
    for (i = 0; i < size ; i++) {
        content_len[i] = get_value_to_str(&sub_params[i], contents[i], sizeof(contents[0]));
        fprintf(stderr, "  %-30.30s = [%s] | %-40s\n", sub_params[i].name,
             contents[i], sub_params[i].hint);
    }
    fprintf(stderr, "\033[2;%dH", left_offset);

    int_sig_bk = signal(SIGINT, esc_sig_handle);

    while (g_esc_menu) {
        ch = getc(stdin);
        /* 1. control char process. */
        if (g_esc_menu == 0)
            break;
        /* delete one char */
        if ((ch == '\b' || ch == 8) && (cur_flag_x > 0)) {
            memmove(&contents[cur_flag_y][cur_flag_x - 1],
                    &contents[cur_flag_y][cur_flag_x],
                    20 - cur_flag_x);
            cur_flag_x --;
            content_len[cur_flag_y] --;
        /* move current flag */
        } else if(ch == 27) {
            getc(stdin);
            ch = getc(stdin);
            if(ch == 'A'){
                /* pre history*/
                if (cur_flag_y > 0) {
                    cur_flag_y --;
                    if (cur_flag_x > content_len[cur_flag_y])
                        cur_flag_x = content_len[cur_flag_y];
                }
            } else if(ch == 'B') {
                /* next history*/
                if (cur_flag_y < lines) {
                    cur_flag_y ++;
                    if (cur_flag_x > content_len[cur_flag_y])
                        cur_flag_x = content_len[cur_flag_y];
                }
            } else if(ch == 'C') {
                /* right move */
                if(cur_flag_x < content_len[cur_flag_y])
                    cur_flag_x ++;
            } else if(ch == 'D') {
                /* right move */
                if(cur_flag_x > 0)
                    cur_flag_x --;
            }
        }
        else if (ch == '\n') {
            if (cur_flag_y < lines) {
                cur_flag_y ++;
                if (cur_flag_x > content_len[cur_flag_y])
                    cur_flag_x = content_len[cur_flag_y];
            }
            else if (cur_flag_y >= lines)
                break;
        } else if (cur_flag_x < 19) {
            int match_success = 0;
            /* match input data type */
            switch (sub_params[cur_flag_y].type) {
                case PARAMS_CHAR:
                    if (cur_flag_x == 0 && char_is_char(ch)) {
                        match_success = 1;
                    } else {
                        match_success = 0;
                    }
                    break;
                case PARAMS_USHORT:
                case PARAMS_UINT:
                case PARAMS_UCHAR:
                    if (char_is_number(ch)) {
                        match_success = 1;
                    } else {
                        match_success = 0;
                    }
                case PARAMS_SCHAR:
                case PARAMS_SHORT:
                case PARAMS_INT:
                case PARAMS_ENUM:
                    if (cur_flag_x == 0 && char_is_nagative(ch)) {
                        match_success = 1;
                    } else if (char_is_number(ch)) {
                        match_success = 1;
                    } else {
                        match_success = 0;
                    }
                    break;
                case PARAMS_STRING:
                    if (char_is_char(ch)) {
                        match_success = 1;
                    } else {
                        match_success = 0;
                    }
                    break;
                case PARAMS_FLOAT:
                case PARAMS_DOUBLE:
                    if (cur_flag_x == 0 && char_is_nagative(ch)) {
                        match_success = 1;
                    } else if (char_is_number(ch)) {
                        match_success = 1;
                    } else {
                        match_success = 0;
                    }
                    break;
                default:
                    match_success = 0;
                    break;
            }

            if (match_success) {
                memmove(&contents[cur_flag_y][cur_flag_x + 1],
                        &contents[cur_flag_y][cur_flag_x],
                        19 - cur_flag_x);
                contents[cur_flag_y][cur_flag_x++] = ch;
                content_len[cur_flag_y] ++;
            } else {
                continue;
            }
        }
        fprintf(stderr, "\033[%d;1H", cur_flag_y + 2);
        fprintf(stderr, "\r  %-30.30s = [%s] | %-40s", sub_params[cur_flag_y].name,
            contents[cur_flag_y], sub_params[cur_flag_y].hint);
        fprintf(stderr, "\033[%d;%dH", cur_flag_y + 2, left_offset + cur_flag_x);
    }

    signal(SIGINT, int_sig_bk);
    pthread_mutex_unlock(&menu_mutex);

    if (g_esc_menu == 0)
        return -1;

    for (i = 0; i < size ; i++) {
        if (content_len[i] != 0) {
            set_value_by_str(&sub_params[i], contents[i]);
        }
    }
    fprintf(stderr, "\033[2J\033[0;0H");
    fprintf(stderr, "\nResult %s params:\n", s_name);
    for (i = 0; i < size ; i++) {
        display_parameters(&sub_params[i]);
    }

    return 0;
}

static inline int shell_dir_display(char *match_str, int len, char const *path, char *filename, int name_sz)
{
    struct dirent *entry = NULL;
    int num = 0;

    DIR* dir_t = opendir(path);
    if(!dir_t)
        return 0;
    while((entry = readdir(dir_t)) != NULL)
    {
        if(strncmp(entry->d_name, ".", 1) == 0)
            continue;
        else if(strncmp(entry->d_name, "..", 2) == 0)
            continue;
        if(strncmp(entry->d_name, match_str, len) == 0){
            num ++;
            fprintf(stderr, "%s", entry->d_name);
            int name_lenth = strlen(entry->d_name);
            name_lenth = 15 - name_lenth;
            if(name_lenth < 0)
                name_lenth = 0;
            name_lenth /= 8;
            do{
                fputc('\t', stderr);
            }while(name_lenth-- > 0);

            if(++gtext_offset >= 4) {
                gtext_offset = 0;
                fputc('\n', stderr);
            }
        }
    }
    closedir(dir_t);

    if(num == 1){
        dir_t = opendir(path);
        if(!dir_t)
            return 0;
        while((entry = readdir(dir_t)) != NULL)
        {
            if(strncmp(entry->d_name, ".", 1) == 0)
                continue;
            else if(strncmp(entry->d_name, "..", 2) == 0)
                continue;
            if(strncmp(entry->d_name, match_str, len) == 0){
                strncpy(filename, entry->d_name, name_sz);
                return 1;
            }
        }
        closedir(dir_t);
    }

    return num;
}

static int auto_make_up_shell_cmd(char *match_str, int cur_len, int max_len)
{
    int number = 0;
    char filename[128];

    if((cur_len >= 1 && match_str[0] == '/')
        || (cur_len >= 2 && match_str[0] == '.' && match_str[1] == '/')){
        int path_len = cur_len;
        char path[cur_len + 1];
        while(path_len-- > 0){
            if(match_str[path_len] == '/'){
                strncpy(path, match_str, ++path_len);
                path[path_len] = '\0';
                break;
            }
        }
        if(path_len > 0) {
            number = shell_dir_display(match_str + path_len, cur_len - path_len, path, filename, sizeof(filename));
            if(number == 1) {
                struct stat file_stat;
                int len = MIN(max_len, strlen(filename));
                assert(len >= 0);
                strncpy(match_str + path_len, filename, len);
                if((stat(match_str, &file_stat) == 0)
                && (file_stat.st_mode & S_IFDIR)){
                    strcat(match_str, "/");
                } else {
                    strcat(match_str, " ");
                }
            }
        }
    } else {
        char *env_path = getenv("PATH");
        if(!env_path)
            return 0;
        /* backup PATH env */
        int env_size = strlen(env_path) + 1;
        char path_backup[env_size], *path = path_backup;
        memset(path_backup, 0, sizeof(path_backup));
        strncpy(path_backup, env_path, sizeof(path_backup));

        char *path_end = path + strlen(path);
        char *path_spl = NULL;
        while((path_end > path) && (path_spl = strtok(path, ":")) != NULL){
            number += shell_dir_display(match_str, cur_len, path_spl, filename, sizeof(filename));
            path += strlen(path_spl) + 1;
        }

        if(number == 1) {
            struct stat file_stat;
            int len = MIN(max_len, strlen(filename));
            assert(len >= 0);
            strncpy(match_str, filename, len);
            if((stat(match_str, &file_stat) == 0)
                && (file_stat.st_mode & S_IFDIR)){
                strcat(match_str, "/");
            } else {
                strcat(match_str, " ");
            }
        }
    }
    if(number > 0) {
        gtext_offset = 0;
        fputc('\n', stderr);
    }

    return number;
}

static inline int shell_local_cmd_display(char *match_str, int len, char *filename, int name_sz)
{
    int index;
    int num = 0;
    for(index = 0; index < SHELL_CommandTableSize; index++)
    {
        if(commandTable[index].command != NULL)
        {
            if(strncmp(commandTable[index].command, match_str, len) == 0){
                num ++;
                fprintf(stderr, "%s ", commandTable[index].command);
                int name_lenth = strlen(commandTable[index].command);
                name_lenth = 15 - name_lenth;
                if(name_lenth < 0)
                    name_lenth = 0;
                name_lenth /= 8;
                do{
                    fputc('\t', stderr);
                }while(name_lenth-- > 0);
                if(++gtext_offset >= 4) {
                    gtext_offset = 0;
                    fputc('\n', stderr);
                }
            }
        }
    }

    if(num == 1){
        for(index = 0; index < SHELL_CommandTableSize; index++)
        {
            if(commandTable[index].command != NULL)
            {
                if(strncmp(commandTable[index].command, match_str, len) == 0){
                    strncpy(filename, commandTable[index].command, name_sz);
                    return 1;
                }
            }
        }
    }
    return num;
}

static int auto_make_up_local_cmd(char *match_str, int cur_len, int max_len)
{
    int number = 0;
    char filename[128];

    if((cur_len >= 1 && match_str[0] == '/')
        || (cur_len >= 2 && match_str[0] == '.' && match_str[1] == '/')){
        int path_len = cur_len;
        char path[cur_len + 1];
        while(path_len-- > 0){
            if(match_str[path_len] == '/'){
                strncpy(path, match_str, ++path_len);
                path[path_len] = '\0';
                break;
            }
        }
        if(path_len > 0) {
            number = shell_dir_display(match_str + path_len, cur_len - path_len, path, filename, sizeof(filename));
            if(number == 1) {
                struct stat file_stat;
                int len = MIN(max_len, strlen(filename));
                assert(len >= 0);
                strncpy(match_str + path_len, filename, len);
                if((stat(match_str, &file_stat) == 0)
                && (file_stat.st_mode & S_IFDIR)){
                    strcat(match_str, "/");
                } else {
                    strcat(match_str, " ");
                }
            }
        }
    } else {
        number = shell_local_cmd_display(match_str, cur_len, filename, sizeof(filename));
        if(number == 1) {
            int len = MIN(max_len, strlen(filename));
            assert(len >= 0);
            strncpy(match_str, filename, len);
            match_str[len++] = ' ';
            match_str[len] = '\0';
        }
    }
    if(number > 0) {
        gtext_offset = 0;
        fputc('\n', stderr);
    }

    return number;
}

static int set_disp_disable(void)
{
    struct termios term;
    if(tcgetattr(fileno(stdin), &gterm) == -1)
        return -1;
    term = gterm;
    term.c_lflag &= ~(ECHO | ICANON);
    if(tcsetattr(fileno(stdin), TCSAFLUSH, &term) == -1)
        return -1;
    return 0;
}

static int set_disp_enable(void)
{
    struct termios term;
    term = gterm;
    if(tcsetattr(fileno(stdin), TCSAFLUSH, &term) == -1)
        return -1;
    return 0;
}

static void shell_sig(int sig)
{
    set_disp_enable();
    GADI_INFO("recv signal: %d\n", sig);
    perror("");
    exit(0);
}

static int quit_command(int argc, char* argv[])
{
    set_disp_enable();
    exit(0);
}

static GADI_ERR shell_quit_register_testcase(void)
{
    GADI_ERR   retVal =  GADI_OK;
    (void)shell_registercommand (
        "quit",
        quit_command,
        "shell command",
        NULL
    );

    return retVal;
}

static int cd_command(int argc, char* argv[])
{
    if (argc != 2){
        printf("Input parameters error.\n");
        return 0;
    }
    chdir(argv[1]);
    return 0;
}

static GADI_ERR shell_cd_register_testcase(void)
{
    GADI_ERR   retVal =  GADI_OK;
    (void)shell_registercommand (
        "cd",
        cd_command,
        "shell command",
        NULL
    );

    return retVal;
}


int shell_get_strbysys(const char *cmd, char *buff, int bufsize)
{
    FILE *fp = NULL;
    if (NULL == (fp = popen(cmd, "r")))
    {
        goto err;
    }
    if (buff != NULL && NULL == fgets(buff, bufsize, fp))
    {
        goto err;
    }
    pclose(fp);
    return 0;
err:
    pclose(fp);
    return -1;
}

static GADI_S16 gIndex = 0;
static GADI_S16 gHistoryIndex = 0;
static GADI_U16 i = 0;
static GADI_U16 cur_flag = 0;
static GADI_U16 args_buff_len[SHELL_CCAHE];
static GADI_CHAR args_buff[SHELL_CCAHE][SHELL_COMMAND_STRING_SIZE];
static GADI_CHAR tmp_buff[SHELL_COMMAND_STRING_SIZE];
static GADI_BOOL gResetCmdFlg = GADI_TRUE;

static void shell_interrupt_reset_lock()
{
	gResetCmdFlg = GADI_FALSE;
}

static void shell_interrupt_reset_unlock()
{
	gResetCmdFlg = GADI_TRUE;
}

static void reset_cmd_line(int sig)
{
	if (gResetCmdFlg) {
	    i = cur_flag = 0;
	    gHistoryIndex = gIndex;
	    memset(tmp_buff, 0, sizeof(tmp_buff));
	    fprintf(stderr, "\nadi@goke# ");
	}
}

static void shell_signal_setup(void)
{
	signal(SIGINT, reset_cmd_line);
    signal(SIGQUIT, shell_sig);
    signal(SIGKILL, shell_sig);
    signal(SIGSEGV, shell_sig);
    signal(SIGABRT, shell_sig);
}

static void shell_signal_restore(void)
{    
	signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGKILL, SIG_DFL);
    signal(SIGSEGV, SIG_DFL);
    signal(SIGABRT, SIG_DFL);
}

static void function_thread(void *data)
{
    GADI_CHAR ch = 0;
    int pre_i = 0;

	shell_signal_setup();
    set_disp_disable();
    shell_quit_register_testcase();
    shell_cd_register_testcase();
    fprintf(stderr, "###########################################################\n");
    fprintf(stderr, "#  ADI Demo shell uage: \n");
    fprintf(stderr, "#    Input \"quit\" is quit program.\n");
    fprintf(stderr, "#    example: \n");
    fprintf(stderr, "#      adi@goke# quit\n");
    fprintf(stderr, "###########################################################\n");
    /*2 seconds for background running.*/
    memset(args_buff, 0, sizeof(args_buff));
    memset(args_buff_len, 0, sizeof(args_buff_len));
    while(1)
    {
        i = cur_flag = 0;
        gHistoryIndex = gIndex;
        memset(tmp_buff, 0, sizeof(tmp_buff));
        fprintf(stderr, "\nadi@goke# ");
        while((ch = getc(stdin)) == ' ')
            usleep(10000);;
        /* get command string */
        do
        {
            if((ch == '\n') || (ch == '\r') || (i >= (SHELL_COMMAND_STRING_SIZE - 2)))
            {
                /* enter is command over */
                break;
            }
            else if(ch == '\b' || ch == 8)
            {
                /* delete one char */
                if (cur_flag >= i && i > 0) {
                    tmp_buff[--i] = '\0';
                    cur_flag = i;
                } else if(cur_flag > 0) {
                    assert(cur_flag < i);
                    memmove(&tmp_buff[cur_flag - 1], &tmp_buff[cur_flag], (i - cur_flag));
                    tmp_buff[--i] = '\0';
                    cur_flag--;
                }
            }
            else if(ch == 27){
                getc(stdin);
                ch = getc(stdin);
                if(ch == 'A'){
                    /* pre history*/
					if (args_buff_len[(gHistoryIndex+SHELL_CCAHE-1)%SHELL_CCAHE] > 0||
						((gHistoryIndex+SHELL_CCAHE-1)%SHELL_CCAHE) == gIndex) {
	                    gHistoryIndex--;
	                    if(gHistoryIndex < 0)
	                        gHistoryIndex = SHELL_CCAHE - 1;
						
						/* reset current flag point */
						int clear_len = pre_i - cur_flag;
		                while(clear_len -- > 0)
		                    fputc(' ', stderr);
						
	                    memcpy(tmp_buff, args_buff[gHistoryIndex], sizeof(tmp_buff));
	                    cur_flag = i = args_buff_len[gHistoryIndex];
					}
                } else if(ch == 'B') {
                    /* next history*/
					if (args_buff_len[(gHistoryIndex+1)%SHELL_CCAHE] > 0||
						(gHistoryIndex+1) == gIndex) {
	                    //args_buff_len[gHistoryIndex] = i;
	                    gHistoryIndex++;
	                    if(gHistoryIndex >= SHELL_CCAHE)
	                        gHistoryIndex = 0;

						/* reset current flag point */
						int clear_len = pre_i - cur_flag;
		                while(clear_len -- > 0)
		                    fputc(' ', stderr);
						
	                    memcpy(tmp_buff, args_buff[gHistoryIndex], sizeof(tmp_buff));
	                    cur_flag = i = args_buff_len[gHistoryIndex];
					}
                } else if(ch == 'C') {
                    /* right move */
                    if(cur_flag < i)
                        cur_flag++;
                } else if(ch == 'D') {
                    /* right move */
                    if(cur_flag > 0)
                        cur_flag--;
                }
            }
            else if (ch == '\t')
            {
                int ret = 0;
                int arg_offset = cur_flag;

                while(tmp_buff[arg_offset] != ' ' && arg_offset > 0){
                    arg_offset--;
                }

                while (tmp_buff[arg_offset] == ' ')
                    arg_offset++;

                if(cur_flag > arg_offset) {
                    fputc('\n', stderr);
                    ret = auto_make_up_local_cmd(&(tmp_buff[arg_offset]),
                        (int)(cur_flag - arg_offset), SHELL_COMMAND_STRING_SIZE - arg_offset);
                    if (ret == 0) {
                        ret = auto_make_up_shell_cmd(&(tmp_buff[arg_offset]),
                            (int)(cur_flag - arg_offset), SHELL_COMMAND_STRING_SIZE - arg_offset);
                    }
                }
                else
                    ret = 0;

                if(ret == 1){
                    cur_flag = i = strlen(tmp_buff);
                }
            }
            else
            {
                /* add one char */
                if (cur_flag >= i) {
                    tmp_buff[i++] = ch;
                    cur_flag = i;
                } else {
                    int move_size = 0;

                    if(i > (SHELL_COMMAND_STRING_SIZE - 2))
                        move_size = SHELL_COMMAND_STRING_SIZE - 2 - cur_flag;
                    else
                        move_size = i - cur_flag;
                    if(move_size > 0)
                        memmove(&tmp_buff[cur_flag + 1], &tmp_buff[cur_flag], move_size);
                    tmp_buff[cur_flag++] = ch;
                    i++;
                }
            }

            if(i < pre_i) {
                /* clear rubbish char*/
                int clear_len = pre_i - i;
                while(clear_len -- > 0)
                    fputc(8, stderr);
                clear_len = pre_i - cur_flag;
                while(clear_len -- > 0)
                    fputc(' ', stderr);
            }
            /* save current char number */
            pre_i = i;
			
            fprintf(stderr, "\radi@goke# %s", tmp_buff);
            if(cur_flag < i) {
                int clear_len = i - cur_flag;
                while(clear_len --){
                    fputc(8, stderr);
                }
            }
        } while((ch = getc(stdin))!= '\r' && ch != '\n');

        if(i > 0){
            int ret_val = 0;
            GADI_CHAR docommand_buff[SHELL_COMMAND_STRING_SIZE];
            /* do command */
            fputc('\n', stderr);
            memcpy(docommand_buff, tmp_buff, sizeof(docommand_buff));
            ret_val = shell_docommand(docommand_buff);
            if (ret_val == -2) {
                //system call.
                set_disp_enable();
                shell_system(tmp_buff);
                set_disp_disable();
            } 

			if ((i != args_buff_len[((gIndex+SHELL_CCAHE-1)%SHELL_CCAHE)]) ||
				(strcmp(tmp_buff, args_buff[((gIndex+SHELL_CCAHE-1)%SHELL_CCAHE)]) != 0)) {
                memcpy(args_buff[gIndex], tmp_buff, sizeof(tmp_buff));
                args_buff_len[gIndex] = i;
                gIndex++;
			}

            if(gIndex >= SHELL_CCAHE)
                gIndex = 0;
			
            args_buff_len[gIndex] = 0;
            args_buff[gIndex][0] = '\0';
        }
    }
}


