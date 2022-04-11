// ****************************************************************************
// * zsoExt.h
// * Constants, types,... used by external caller
// ****************************************************************************
#ifndef _ZSOEXT_H
#define _ZSOEXT_H

// --- PARAMETERS -----------------------------------------------

// Zac APIs
#define CE_ZAC_MODE_NOPLINE 0
#define CE_ZAC_MODE_PLINE   1


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
