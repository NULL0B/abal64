// ****************************************************************************
// * zInt.h
// * Constants, types,... for internal usage
// ****************************************************************************
#ifndef _ZINT_H
#define _ZINT_H

// *******************************************************
// * CONSTANTS
// *******************************************************

// Portability separator for path
#if defined(BDA_TWIN16) || defined(BDA_WIN32)
#define CI_STRING_SLASH "\\"
#define CI_CHAR_SLASH   '\\'
#else
#define CI_STRING_SLASH "/"
#define CI_CHAR_SLASH   '/'
#endif

// Indice of colors in the palette

#define CI_COL_TRANSPARENT        0

// ABAL colors (used by CICO)
#define CI_COL_CICO_BLACK         0x00
#define CI_COL_CICO_RED           0x01
#define CI_COL_CICO_GREEN         0x02
#define CI_COL_CICO_BROWN         0x03
#define CI_COL_CICO_BLUE          0x04
#define CI_COL_CICO_MAGENTA       0x05
#define CI_COL_CICO_CYAN          0x06
#define CI_COL_CICO_HIGRAY        0x07
#define CI_COL_CICO_LOGRAY        0x08
#define CI_COL_CICO_HIRED         0x09
#define CI_COL_CICO_HIGREEN       0x0A
#define CI_COL_CICO_YELLOW        0x0B
#define CI_COL_CICO_HIBLUE        0x0C
#define CI_COL_CICO_HIMAGENTA     0x0D
#define CI_COL_CICO_HICYAN        0x0E
#define CI_COL_CICO_WHITE         0x0F

// Reserved colors for Zlib (10 to 1F)
#define CI_COL_BLACK              0x10
#define CI_COL_DARK_LOW           0x11
#define CI_COL_DARK               0x12
#define CI_COL_GRAYED             0x13
#define CI_COL_NEUTRAL_LOW        0x14
#define CI_COL_NEUTRAL            0x15
#define CI_COL_LIGHT              0x16
#define CI_COL_LIGHT_HIGH         0x17
#define CI_COL_WHITE              0x18
#define CI_COL_TITLE_FG_ACTIVE    0x19
#define CI_COL_TITLE_BK_ACTIVE    0x1A
#define CI_COL_BUBBLE_FG          0x1B
#define CI_COL_BUBBLE_BK          0x1C
#define CI_COL_FOCUS              0x1D
#define CI_COL_RESERVED1          0x1E
#define CI_COL_RESERVED2          0x1F

// Invalid number to force a default value (given by the skin, for example)
#define CI_COL_CHOOSEN_BY_ZLOOK   0xFFFF

// Skin flags
#define CI_SKNF_L1C1              0x0001               
#define CI_SKNF_L1C2              0x0002               
#define CI_SKNF_L1C3              0x0004               
#define CI_SKNF_L2C1              0x0008               
#define CI_SKNF_L2C2              0x0010               
#define CI_SKNF_L2C3              0x0020               
#define CI_SKNF_L3C1              0x0040               
#define CI_SKNF_L3C2              0x0080               
#define CI_SKNF_L3C3              0x0100               
#define CI_SKNF_L4C1              0x0200               
#define CI_SKNF_L4C2              0x0400               
#define CI_SKNF_L4C3              0x0800              

#define CI_SKNF_3ZONES            (CI_SKNF_L1C1 | CI_SKNF_L1C2 | CI_SKNF_L1C3)
#define CI_SKNF_3ZONES_MIDDLE     (CI_SKNF_L2C1 | CI_SKNF_L2C2 | CI_SKNF_L2C3)
#define CI_SKNF_3ZONES_BOTTOM     (CI_SKNF_L3C1 | CI_SKNF_L3C2 | CI_SKNF_L3C3)
#define CI_SKNF_3ZONES_EXT        (CI_SKNF_L4C1 | CI_SKNF_L4C2 | CI_SKNF_L4C3)

#define CI_SKNF_2ZONES            (CI_SKNF_L1C1 | CI_SKNF_L1C2)
#define CI_SKNF_2ZONES_MIDDLE     (CI_SKNF_L2C1 | CI_SKNF_L2C2)
#define CI_SKNF_2ZONES_BOTTOM     (CI_SKNF_L3C1 | CI_SKNF_L3C2)

#define CI_SKNF_9ZONES            0x01FF
#define CI_SKNF_9ZONES_NOCENTER   0x01EF

#define CI_SKNF_3ZONES_V          (CI_SKNF_L1C1 | CI_SKNF_L2C1 | CI_SKNF_L3C1)
#define CI_SKNF_3ZONES_V_MIDDLE   (CI_SKNF_L1C2 | CI_SKNF_L2C2 | CI_SKNF_L3C2)
#define CI_SKNF_3ZONES_V_RIGHT    (CI_SKNF_L1C3 | CI_SKNF_L2C3 | CI_SKNF_L3C3)

#define CI_SKNF_6ZONES_V          (CI_SKNF_3ZONES_V|CI_SKNF_3ZONES_V_RIGHT)

// State of window
#define CI_WINSTA_NOFRAME         0
#define CI_WINSTA_FRAME_NOTITLE   1
#define CI_WINSTA_FRAME_TITLE     2

// Type of Escape sequence analyse for print texts
#define CI_ESC_NOCONTROL          0x0000
#define CI_ESC_PROCESS            0x1000
#define CI_CLIP_ON                0x2000

#define CI_ESC_F_NOTHING          0x0000
#define CI_ESC_F_ALL              0x0FFF
#define CI_ESC_F_FG               0x0001
#define CI_ESC_F_BG               0x0002
#define CI_ESC_F_FONT             0x0004
#define CI_ESC_F_POSIT            0x0008

// some keys of the keyboard 
#define CI_KEY_TAB                0x09
#define CI_KEY_SHTAB              0x00
#define CI_KEY_HOME               0x1C
#define CI_KEY_END                0x02
#define CI_KEY_PGUP               0x12
#define CI_KEY_PGDOWN             0x03
#define CI_KEY_UP                 0x11
#define CI_KEY_DOWN               0x05
#define CI_KEY_LEFT               0xFD
#define CI_KEY_RIGHT              0x06
#define CI_KEY_CR                 0x0D
#define CI_KEY_ESC                0x1B

// Graphic mode
#define CI_GR_320X200             0
#define CI_GR_640X400             1
#define CI_GR_640X480             2
#define CI_GR_800X600             3
#define CI_GR_1024X768            4
#define CI_GR_1280X1024           5
#define CI_GR_UNKNOWN				 99

// Draw constants
#define CI_BRUSH_SOLID            0
#define CI_BRUSH_TRANSPARENT      1
#define CI_BRUSH_SHADED           2

#define CI_PEN_SOLID              0
#define CI_PEN_DOTTED1            1
#define CI_PEN_DOTTED2            2
#define CI_PEN_DOTTED3            3

// *******************************************************
// * STRUCTURES
// *******************************************************

// --------------------------
// Graphic basic structures
// --------------------------
typedef struct{
  WORD x;
  WORD y;
}TI_POINT, FAR PTR PTI_POINT;

typedef struct{
  WORD cx;
  WORD cy;
}TI_SIZE, FAR PTR PTI_SIZE;

typedef struct{
  WORD x1;
  WORD x2;
  WORD y1;
  WORD y2;
}TI_RECTANGLE, FAR PTR PTI_RECTANGLE;

// --------------------------
// Memory storage
// --------------------------
typedef struct{
  BYTE FAR PTR  Ptr;        // pointer on a memory zone (NULL if unitialised)
  WORD          Size;       // size of a zone (0 if unknown)
  WORD          IsDyn;      // True=allocation (must be liberate), False=static (no liberate)
} TI_MEMORY, FAR PTR PTI_MEMORY;

// *******************************************************
// * MACROS
// *******************************************************

#endif
