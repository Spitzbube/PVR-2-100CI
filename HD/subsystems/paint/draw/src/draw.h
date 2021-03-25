/*!
*****************************************************************************
**
** \file        ./subsystems/paint/draw/src/draw.h
**
** \brief       DRAW Driver
**
** This file contains the declaration of the DRAW driver API.
**
** \attention   THIS SAMPLE CODE IS PROVIDED AS IS. FUJITSU MICROELECTRONICS
**              ACCEPTS NO RESPONSIBILITY OR LIABILITY FOR ANY ERRORS OR
**              OMMISSIONS.
**
** (C) Copyright 2008 - 2009 by Fujitsu Microelectronics Europe GmbH
**
*****************************************************************************
*/

#ifndef DRAW_H
    #define DRAW_H

    #include <stdint.h>
    #include <fapi/sys_error.h>

    //***********************************************************************
    //***********************************************************************
    //** Defines and Macros
    //***********************************************************************
    //***********************************************************************
    #define DRAW_ENABLE_RESIZE          1

    #define DRAW_ENABLE_PNG             1

    #define DRAW_PNG_SIGNATURE_BYTES    8 // do not modify

    /*!
    ********************************************************************************
    ** Standard error codes for the DRAW driver
    ********************************************************************************
    */

    /*! Bad parameter passed. */
    #define DRAW_ERR_BAD_PARAMETER \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_BAD_PARAMETER)

    /*! Memory allocation failed. */
    #define DRAW_ERR_OUT_OF_MEMORY \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_OUT_OF_MEMORY)

    /*! Device already initialised. */
    #define DRAW_ERR_ALREADY_INITIALIZED \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_ALREADY_INITIALIZED)

    /*! Device not initialised. */
    #define DRAW_ERR_NOT_INITIALIZED \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_NOT_INITIALIZED)

    /*! Feature or function is not available. */
    #define DRAW_ERR_FEATURE_NOT_SUPPORTED \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_FEATURE_NOT_SUPPORTED)

    /*! Timeout occured. */
    #define DRAW_ERR_TIMEOUT \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_TIMEOUT)

    /*! The device is busy, try again later. */
    #define DRAW_ERR_DEVICE_BUSY \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_DEVICE_BUSY)

    /*! Invalid handle was passed. */
    #define DRAW_ERR_INVALID_HANDLE \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_INVALID_HANDLE)

    /*! Semaphore could not be created. */
    #define DRAW_ERR_SEMAPHORE_CREATE \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_SEMAPHORE_CREATE)

    /*! The driver's used version is not supported. */
    #define DRAW_ERR_UNSUPPORTED_VERSION \
            (int32_t)(SUBSYS_PAINT_DRAW_MODULE_BASE + FAPI_ERR_UNSUPPORTED_VERSION)

    /*!
    ****************************************************************************
    ** Additional DRAW driver error codes.
    **
    ** Each error code shall be decreased in steps of 1.
    ****************************************************************************
    */
    /* \brief DRAW specific error code offset */
    #define DRAW_ERR_BASE \
            (int32_t) (SUBSYS_PAINT_DRAW_MODULE_BASE - 100)

    /*! Returned when attemped to write at coordinates that are out of bounds
    **  of the OSD or CP plane.
    */
    #define DRAW_ERR_OUT_OF_OSD_SIZE            (int32_t) (DRAW_ERR_BASE - 0)

    /*! The content that should be drawn does not fit for the colour mode
    **  that is currently selected for the OSD/CP.
    */
    #define DRAW_ERR_WRONG_COLOUR_MODE          (int32_t) (DRAW_ERR_BASE - 1)

    /*! The selected OSDHANDLER_OsdLayoutEnumT that the OSD/CP is running
    **  is not supported for drawing the desired picture.
    */
    #define DRAW_ERR_WRONG_LAYOUT_MODE          (int32_t) (DRAW_ERR_BASE - 2)

    /*! The DRAW driver is not able to process the passed bitmap file. */
    #define DRAW_ERR_BITMAP_NOT_SUPPORTED       (int32_t) (DRAW_ERR_BASE - 3)

    /*! The file type is unknown.   */
    #define DRAW_ERR_UNKNOWN_FILE_TYPE          (int32_t) (DRAW_ERR_BASE - 4)

    /*! DRAW is not able to process the passed PNG file. */
    #define DRAW_ERR_PNG_NOT_SUPPORTED          (int32_t) (DRAW_ERR_BASE - 5)

    /*! An error occured while setting up the PNG library. */
    #define DRAW_ERR_PNG_INIT                   (int32_t) (DRAW_ERR_BASE - 6)

    /*! An error occured while decoding the PNG file. It may be corrupted. */
    #define DRAW_ERR_PNG_DECODE                 (int32_t) (DRAW_ERR_BASE - 7)

    //***********************************************************************
    //***********************************************************************
    //** Data types
    //***********************************************************************
    //***********************************************************************

    /*!
    ** \brief       Data structure that contains all members that are stored
    **              within the header of a bitmap file.
    **
    ** \note        The word length of the individual members may differ from
    **              that of the space used within the file structure. So
    **              DO NOT simply CAST a pointer to the file header into
    **              this structure but PARSE the file into this structure
    **              by #DRAW_ParseBitmap in order to access the properties
    **              of a bitmap.
    */
    typedef struct
    {
        /*! identifies the bitmap type: 0x4D42 stands for windows 3.1x, 95, nt
        */
        uint32_t  identifier;

        /*! complete file size in bytes */
        uint32_t  fileSize;

        /*! reserved for later use */
        uint32_t  reserved;

        /*! offset from beginning of file to the beginning of the bitmap data */
        uint32_t  bitmapDataOffset;

        /*! length of the bitmap info header used to describe the bitmap colours,
        **  compression, the following sizes are possible:
        **  - 28h - windows 3.1x, 95, nt
        **  - 0ch - os/2 1.x
        **  - f0h - os/2 2.x
        */
        uint32_t  bitmapHeaderSize;

        /*! horizontal width of bitmap in pixels */
        uint32_t  width;

        /*! vertical height of bitmap in pixels */
        uint32_t  height;

        /*! number of planes in this bitmap */
        uint32_t  planes;

        /*! bits per pixel used to store palette entry information.
        **  this also identifies in an indirect way the number of possible
        **  colours. possible values are:
        **  - 1 - monochrome bitmap (CLUT)
        **  - 4 - 16 colour bitmap   (CLUT)
        **  - 8 - 256 colour bitmap  (CLUT)
        **  - 16 - 16bit (high colour) bitmap    (5551 mode)
        **  - 24 - 24bit (true colour) bitmap    (RGBA mode)
        **  - 32 - 32bit (true colour) bitmap    (RGBA mode, high byte not used)
        */
        uint32_t  bitsPerPixel;

        /*! compression specifications. the following values are possible:
        **  - 0 - none (also identified by bi_rgb)
        **  - 1 - rle 8-bit / pixel (also identified by bi_rle4)
        **  - 2 - rle 4-bit / pixel (also identified by bi_rle8)
        **  - 3 - bitfields (also identified by bi_bitfields)
        */
        uint32_t  compression;

        /*! Size of the bitmap data in bytes.
        **  This number must be rounded to the next 4 byte boundary.
        */
        uint32_t  bitmapDataSize;

        /*! horizontal resolution expressed in pixel per meter */
        uint32_t  hResolution;

        /*! vertical resolution expressed in pixels per meter */
        uint32_t  vResolution;

        /*! Number of colours used by this bitmap.
        **  For a 8-bit / pixel bitmap this will be 0x100 or 256.
        */
        uint32_t  colours;

        /*! Number of important colours. This number will be equal
        **  to the number of colours when every colour is important.
        */
        uint32_t  importantColours;

        /*! The palette specification. For every entry in the palette
        **  four bytes are used to describe the rgb values of the colour:
        **  - 1 byte for the blue component
        **  - 1 byte for the green component
        **  - 1 byte for the red component
        **  - 1 byte serves as a filler
        */
        uint8_t* palettePtr;

        /*! Depending on the compression specifications, this field contains
        **  all the bitmap data bytes which represent indices in the colour
        **  palette.
        */
        uint8_t* bitmapDataPtr;

    } DRAW_BmpFileHeadT;


    /*!
    *************************************************************************
    ** \brief   Specifies whether the Colour Lookup Table of 1-, 4- and 8-bit
    **          bitmaps will be copied to the OSD while drawing bitmap files
    **          on an OSD/CP.
    *************************************************************************
    */
    typedef enum
    {
        //! Set up the CLUT in the hardware when drawing bitmap files.
        DRAW_SET_UP_CLUT = (int32_t)0,

        //! Leave the CLUT in the hardware as is when drawing bitmap files.
        DRAW_DO_NOT_SET_UP_CLUT

    } DRAW_ModeEnumT;

    /*!
    *************************************************************************
    ** \brief   Specifies the dimensions of a rectangle.
    *************************************************************************
    */
    typedef struct
    {
        uint32_t xPos;      //!< top left corner of area
        uint32_t yPos;      //!< top left corner of area
        uint32_t width;     //!< area width
        uint32_t height;    //!< area height
    } DRAW_RectangleT;

    /*!
    *************************************************************************
    ** \brief   Fujitsu specific bitmap files related colour modes.
    *************************************************************************
    */
    typedef enum
    {
    /*! 1-Bit CLUT mode */
    DRAW_COLOURMODE_1BIT = (int32_t)0,

    /*! 2-Bit CLUT mode */
    DRAW_COLOURMODE_2BIT = (int32_t)1,

    /*! 4-Bit CLUT mode */
    DRAW_COLOURMODE_4BIT = (int32_t)2,

    /*! 8-Bit CLUT mode */
    DRAW_COLOURMODE_8BIT = (int32_t)3,

    /*! True colour with common transparency */
    DRAW_COLOURMODE_24BIT = (int32_t)10,

    /*! True colour with individual transparency */
    DRAW_COLOURMODE_32BIT = (int32_t)11,

    /*! 1-Bit CLUT mode */
    DRAW_COLOURMODE_1BIT_RGB = (int32_t)0x00010000,

    /*! 2-Bit CLUT mode */
    DRAW_COLOURMODE_2BIT_RGB = (int32_t)0x00010001,

    /*! 4-Bit CLUT mode */
    DRAW_COLOURMODE_4BIT_RGB = (int32_t)0x00010002,

    /*! 8-Bit CLUT mode */
    DRAW_COLOURMODE_8BIT_RGB = (int32_t)0x00010003,

    /*! 16-Bit 5551 with 1 bit alpha*/
    DRAW_COLOURMODE_16BIT_RGB = (int32_t)0x00010009,

    /*! True colour with common transparency */
    DRAW_COLOURMODE_24BIT_RGB = (int32_t)0x0001000A,

    /*! True colour with individual transparency (RGBA)*/
    DRAW_COLOURMODE_32BIT_RGB = (int32_t)0x0001000B

    } DRAW_ColourModeEnumT;

    /*!
    *************************************************************************
    ** \brief   Specifies picture file types.
    *************************************************************************
    */
    typedef enum
    {
        /*! Format is unknown. */
        DRAW_PIC_FILE_TYPE_UNKNOWN = (int32_t)0,

        /*! Bitmap format: First two bytes are always 0x42, 0x4d ("BM") */
        DRAW_PIC_FILE_TYPE_BMP,

        /*! Fujitsu specific bitmap format. Contains colour mode, horizontal
        **  and vertical resolution, all entries are 32 bits wide. The file
        **  contains CLUT entries or true colour RGB values. The CLUT may
        **  be provided seperately and is not contained within a FBM file.
        */
        DRAW_PIC_FILE_TYPE_FBM,

        /*! The Fujitsu DAT format contains colour mode, horizontal
        **  and vertical resolution. It may contain CLUT entries or
        **  YCrCb values.
        */
        DRAW_PIC_FILE_TYPE_DAT,

        /*! PNG format: First 4 bytes are always: 0x89, 0x50, 0x4E, 0x47 */
        DRAW_PIC_FILE_TYPE_PNG

    } DRAW_PictureFileTypeT;


    /*!
    *************************************************************************
    ** \brief   Header structure of a Fujitsu specific bitmap file (.fbm).
    *************************************************************************
    */
    typedef struct
    {
        DRAW_ColourModeEnumT colourMode; //0 //!< picture colour mode
        uint32_t width;                  //4 //!< picture width
        uint32_t height;                 //8 //!< picture height
    } DRAW_FbmHeaderT;

    /*!
    *************************************************************************
    ** \brief   Fujitsu specific bitmap file (.fbm) structure.
    *************************************************************************
    */
    typedef struct
    {
        /*! picture identifier */
        uint32_t id; //0

        /*! Contains dimensions and colour mode of the picture. */
        DRAW_FbmHeaderT* fbmHeaderPtr; //4

        /*! Points to picture raw data in fbm format without header information. */
        uint32_t* dataPtr; //8

        /*! Optional pointer. May be used to hold the CLUT of the picture. */
        uint32_t* clutPtr; //12

        /*! Identifies the CLUT that is used by the corresponding Hardware
        **  Layer or Virtual Layer. The clutId is coded as the groupId that
        **  used for the OSDHANDLER. The clutId will always precede the
        **  clutPtr that may store a local CLUT for the bitmap file.
        **  If the clutId equals 0x00000000, the clutPtr will be used.
        */
        uint32_t clutId; //16

        /*! If the DRAW_PicItemT is used as input (e.g. for DRAW_ScalePicture()),
        **  the clutStartIdx defines the first CLUT entry of the CLUT 'clutId'
        **  that can be used by the called function. If DRAW_PicItemT is used
        **  as output, clutStartIdx can be set by the called function
        **  to indicate the first used CLUT entry. Default is 0.
        */
        uint16_t clutStartIdx; //20

        /*! If the DRAW_PicItemT is used as input (e.g. for DRAW_ScalePicture()),
        **  the clutEndIdx defines the last CLUT entry of the CLUT 'clutId'
        **  that can be used by the called function. If DRAW_PicItemT is used
        **  as output, clutEndIdx can be set by the called function
        **  to indicate the last used CLUT entry. Default is 0.
        */
        uint16_t clutEndIdx; //22

        /*! Specifies a global alpha value for this bitmap. If this value is
        **  in the range of 0-255, the global alpha value will be used for
        **  the alpha value of each pixel. If it is 256, the alpha value of
        **  each pixel (or the related CLUT entry) will be used instead.
        **  For the 24-bit mode there is no alpha value information at all.
        **  This mode will behave as if the global alpha value was 255.
        */
        uint16_t globalAlpha; //24

        /*! Indicates which members of the structure have been allocated
        **  dynamically by DRAW. The least significant bit (bit 0) indicates
        **  whether the headerPtr has been allocated. Bit 1 identifies the
        **  the dataPtr. Bit 2 identifies the clutPtr.
        **  If memory has been allocated dynamically, the corresponding
        **  bit is set to 1, otherwise 0.
        **  Do not modify this member! It is used by the DRAW library only.
        **  Use DRAW_FreeFbm() in order to free automatically allocated memory!
        */
        uint16_t allocInformation; //26
    } DRAW_PicItemT;

    /*!
    *************************************************************************
    ** \brief   This structure is used for bitmap transformations.
    *************************************************************************
    */
    typedef struct
    {
        //! picture identifier
        uint32_t        id; //0

        //! width, height and pointer to picture raw data of original picture
        DRAW_PicItemT   orgPic; //4

        //! width, height and pointer to picture raw data of converted picture
        DRAW_PicItemT   convPic; //32
        //60
    } DRAW_PicT;

    //***********************************************************************
    //***********************************************************************
    //** Global Data
    //***********************************************************************
    //***********************************************************************


    //***********************************************************************
    //***********************************************************************
    //** API Functions
    //***********************************************************************
    //***********************************************************************

    #ifdef __cplusplus
    extern "C" {
    #endif

    int32_t DRAW_Init(void);
    void    DRAW_Exit(void);
    int32_t DRAW_RoundRectangle(const uint32_t layer,
                                const uint32_t xx,
                                const uint32_t yy,
                                const uint32_t width,
                                const uint32_t height,
                                const uint32_t roundRadius,
                                const uint32_t colour);
    int32_t DRAW_RectangleArray(const uint32_t  layerId,
                                const uint32_t count,
                                DRAW_RectangleT* rectPtr,
                                const uint32_t colour);
    int32_t DRAW_ParseBitmap(DRAW_BmpFileHeadT* headPtr, uint8_t* filePtr);
    int32_t DRAW_Bitmap(const uint32_t  layerId,
                        const uint32_t  xx,
                        const uint32_t  yy,
                        const DRAW_ModeEnumT mode,
                        uint8_t* bmpPtr,
                        uint32_t* errorCodePtr);
    int32_t DRAW_DetectFile(DRAW_PictureFileTypeT* typePtr, uint8_t* filePtr);
    int32_t DRAW_ReadFile_DAT(uint32_t* filePtr, DRAW_PicItemT* picItemPtr);
    int32_t DRAW_ReadFile_BMP(uint32_t* filePtr, DRAW_PicItemT* picItemPtr);
    int32_t DRAW_ReadFile_PNG(uint32_t* filePtr, DRAW_PicItemT* picItemPtr);
    int32_t DRAW_ReadFile_FBM(uint32_t* filePtr, DRAW_PicItemT* picItemPtr);
    int32_t DRAW_Fbm(const uint32_t layer,
                     const uint32_t xx,
                     const uint32_t yy,
                     DRAW_FbmHeaderT* hdrPtr,
                     uint32_t* picPtr);
    int32_t DRAW_Fbm_Overlay(const uint32_t layerId,
                             const uint32_t xx,
                             const uint32_t yy,
                             DRAW_FbmHeaderT* hdrPtr,
                             uint32_t* picPtr,
                             uint32_t  maskColour);
    void    DRAW_FreeFbm(DRAW_PicItemT* picItemPtr);
    int32_t DRAW_PNG   (const uint32_t  layerId,
                        const uint32_t  xx,
                        const uint32_t  yy,
                        const DRAW_ModeEnumT mode,
                        uint8_t* pngPtr,
                        uint32_t* errorCodePtr);
#if DRAW_ENABLE_RESIZE
    int32_t DRAW_ScalePicture( const uint32_t* clutPtr,
                               const DRAW_PicItemT* picPtr,
                               DRAW_PicItemT* convPicPtr,
                               const uint32_t newWidth,
                               const uint32_t newHeight);
#endif

    int32_t DRAW_ScalePicture_1(const DRAW_PicItemT* picPtr,
                               DRAW_PicItemT* convPicPtr,
                               const uint32_t newWidth,
                               const uint32_t newHeight);


    #ifdef __cplusplus
    }
    #endif
#endif
