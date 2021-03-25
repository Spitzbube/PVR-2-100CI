
#ifndef FLASH_H_
#define FLASH_H_


extern int32_t SYS_FlashInit(uint32_t a, uint32_t b);
extern int32_t SYS_FlashWriteFcData(const void* buf);
extern int32_t SYS_FlashReadFcData(void* buf);


#endif /* FLASH_H_ */
