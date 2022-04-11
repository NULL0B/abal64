// ****************************************************************************
// * zExt.h
// * Constants, types,... used by external caller
// ****************************************************************************
#ifndef _ZEXT_H
#define _ZEXT_H

// --- PARAMETERS -----------------------------------------------

// font ID
#define	CE_FONTID_ADJUST  64
#define CE_FONTID_MENU    -2 
#define CE_FONTID_INPUT   -1 
#define CE_FONTID_FIXE    0
#define CE_FONTID_PROP    1 
#define CE_FONTID_SMALL   2 
#define CE_FONTID_USER    3 

// Frames
#define CE_FRAME_LIST           -1
#define CE_FRAME_INPUTFIELD     -2
#define CE_FRAME_VMENU          -3
#define CE_FRAME_COLORBOX       -4
#define CE_FRAME_HMENU          -5
#define CE_FRAME_THIN           1
#define CE_FRAME_BOLD           2
#define CE_FRAME_THINBOLD       3
#define CE_FRAME_BOLDTHIN       4
#define CE_FRAME_OUTSET         5
#define CE_FRAME_INSET          6
#define CE_FRAME_BUTTON         7
#define CE_FRAME_TABVIEW        8
#define CE_FRAME_RIDGE          9
#define CE_FRAME_GROOVE         10
#define CE_FRAME_BUBBLE         11

// Look of controls
#define CE_FIELDLOOK_NORMAL      0
#define CE_FIELDLOOK_FOCUSED     1
#define CE_FIELDLOOK_GRAYED      2
#define CE_FIELDLOOK_HIDDEN      3

#define CE_BUTTONLOOK_NORMAL     0
#define CE_BUTTONLOOK_FOCUSED    1
#define CE_BUTTONLOOK_PUSHED     2
#define CE_BUTTONLOOK_GRAYED     3
#define CE_BUTTONLOOK_HIDDEN     4
// add for internal message boxes:
#define CE_BUTTONLOOK_CLICK      8

#define CE_BUTTONTYPE_MIDDLE     0
#define CE_BUTTONTYPE_BIG        2
#define CE_BUTTONTYPE_SMALL      1

#define CE_TABVIEWLOOK_BACK      0
#define CE_TABVIEWLOOK_FRONT     1
#define CE_TABVIEWLOOK_FOCUSED   2
#define CE_TABVIEWLOOK_GRAYED    3
#define CE_TABVIEWLOOK_HIDDEN    4

#define CE_VARIATOR_NORMAL       0
#define CE_VARIATOR_UP           1
#define CE_VARIATOR_DOWN         2
#define CE_VARIATOR_GRAYED       3
#define CE_VARIATOR_HIDDEN       4

// Drawing APIs 
#define CE_COLOR_RED        1
#define CE_COLOR_GREEN      2
#define CE_COLOR_BLUE       3

// Mouse APIs
#define CE_MOUSE_ARROW      0
#define CE_MOUSE_BUSY       1
#define CE_MOUSE_HELP       2
#define CE_MOUSE_MOVE       3

// Zac APIs
#define CE_ZAC_MODE_NOPLINE 0
#define CE_ZAC_MODE_PLINE   1

// Title bar buttons
#define CE_TIT_X            1
#define CE_TIT_XPUSH        2
#define CE_TIT_H_X          3
#define CE_TIT_H_XPUSH      4
#define CE_TIT_HPUSH_X      5

// Radio state
#define CE_RADIO_OFF        0
#define CE_RADIO_ON         1

// Radio state
#define CE_CHECK_OFF        2
#define CE_CHECK_ON         1
#define CE_CHECK_ON2        3

// Horizontal and Vertical scrollbar
#define CE_SCR_B1_B2        0
#define CE_SCR_B1PUSH       1
#define CE_SCR_B1           2
#define CE_SCR_B2PUSH       3
#define CE_SCR_B2           4
#define CE_SCR_Z1           5
#define CE_SCR_Z2           6
#define CE_SCR_DISABLED     7
#define CE_SCR_HIDDEN       8
#define CE_SCR_SLIDER       9

// Vertical File scrollbar
#define CE_FSCR_NORMAL       0
#define CE_FSCR_DWNPUSH      1
#define CE_FSCR_DWN          2
#define CE_FSCR_UPPUSH       3
#define CE_FSCR_UP           4
#define CE_FSCR_PGDWNPUSH    5
#define CE_FSCR_PGDWN        6
#define CE_FSCR_PGUPPUSH     7
#define CE_FSCR_PGUP         8
#define CE_FSCR_TOPPUSH      9
#define CE_FSCR_TOP          10
#define CE_FSCR_BOTPUSH      11
#define CE_FSCR_BOT          12
#define CE_FSCR_DISABLED     13
#define CE_FSCR_HIDDEN       14

// --- ERRORS ---------------------------------------------------

// Stretch
#define CE_XBMP_MASK_MODE         0x000F
#define CE_XBMP_MASK_SUBMODE      0xFFF0

#define CE_XBMP_MODE_STRETCH      0x0000
#define CE_XBMP_MODE_PROP         0x0001
#define CE_XBMP_MODE_VOID         0x0002
#define CE_XBMP_MODE_EXPERT       0x0003
#define CE_XBMP_MODE_OULESIAN     0x000F

// pour mode EXPERT
#define CE_XBMP_STRETCH           0x0010
#define CE_XBMP_PROP              0x0020
#define CE_XBMP_CENTER            0x0040
#define CE_XBMP_ERASE             0x0080
#define CE_XBMP_FLIPFLOP          0x0100
#define CE_XBMP_MIRROR            0x0200

// mode VOID
#define CE_XBMP_COLOR             0x0010
#define ME_XBMP_VALUECOLOR(a)     (((a)&0xFF00) >> 8)

// --- ERRORS ---------------------------------------------------

// common errors
#define CE_OK                 0
#define CE_ERR                0xFFFF
#define CE_ERR2               0xFFFE
#define CE_ERR3               0xFFFD

// same as ABAL errors
#define CE_ERR_MEMORY           27
#define CE_ERR_FILENAME         30
#define CE_ERR_FILEACCESS       40
#define CE_ERR_FILEOPEN         43
#define CE_ERR_FILENOTSHAREABLE 44
#define CE_ERR_FULL             46
#define CE_ERR_BADNOLOG         50
#define CE_ERR_TOOMANYFILES     51
#define CE_ERR_INCOHERENT       55
#define CE_ERR_UNSUPPORTED      56
#define CE_ERR_FILETYPE         60
#define CE_ERR_NOKEY            78
#define CE_ERR_NOLOGID          116

#define CE_ERR_USER             1000

#define CE_ERR_BADFONTFILE			1001
#define CE_ERR_BADFONTSYSTEM		1002
#define CE_ERR_FONTACCESS		    1003

#endif
