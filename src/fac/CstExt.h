// ***********************************************************************************************
// * CstExt.h
// ***********************************************************************************************

#ifndef CSTEXT_H
#define CSTEXT_H

// ---------------------------------------------------------------
// - Codes erreur conforme avec ABAL
// ---------------------------------------------------------------

#define NO_ERRORS       0
#define ERR_WRITE       2
#define ERR_READ        2
#define ERR_PARAM       20
#define ERR_MEM         27
#define ERR_NOFILE      40
#define ERR_EXIST       41
#define ERR_BUSY        44
#define ERR_SIZE        45
#define ERR_FULL        46
#define ERR_ACCESS      47
#define ERR_EOF         48
#define ERR_BAD_NO      50
#define ERR_SEEK        53
#define ERR_BAD_CALL    55
#define ERR_FORMAT      60
#define ERR_LEN         63
#define ERR_SECTION     64
#define ERR_KEY         78

// ---------------------------------------------------------------
// - Flag pour Open Stream
// ---------------------------------------------------------------

// --- Masques
#define CE_STREAM_F_MASK_MODE    0x0007
#define CE_F_MASK_CHK            0x0030
#define CE_STREAM_F_MASK_SET     0x0700

// --- Existence du fichier
#define CE_F_CHK_NOEXIST   0x0010
#define CE_F_CHK_EXIST     0x0020
#define CE_F_NOCHK         0x0030

// --- Mode d'ouverture
#define CE_F_R             0x0020
#define CE_F_W_NEW         0x0001
#define CE_F_W_APPEND      0x0002
#define CE_F_RW            0x0003
#define CE_F_RW_NEW        0x0004
#define CE_F_RW_APPEND     0x0005

// --- Format d'écriture de fichiers texte
#define CE_F_AUTO          0x0000
#define CE_F_SET_NONE      0x0400
#define CE_F_SET_CR        0x0500
#define CE_F_SET_EOF       0x0600 
#define CE_F_SET_CR_EOF    0x0700

// --- Mode Binaire/texte
#define CE_F_BINARY        0x0000
#define CE_F_LINE          0x1000

// --- Compatibilité NGF (taille au granule près)
#define CE_F_NGF           0x4000

// --- Type de comparaison
//     (FileComp)
#define CE_F_SIZE          0x2000

// --- Type de copie
//     (FileCopy)
#define CE_F_CAT           0x2000

// ---------------------------------------------------------------
// - Stream Seek
// ---------------------------------------------------------------
#define CE_SEEK_SET        0
#define CE_SEEK_CUR        1
#define CE_SEEK_END        2

// ---------------------------------------------------------------
// - Constantes pour partie russe
// ---------------------------------------------------------------
/////////////////////
// Error handling: //
/////////////////////
// Table of error numbers:
#define FILE_EXISTS_ERR    1
#define INV_DESCR_ERR      2
#define FILE_CREATE_ERR    3
#define FILE_OPEN_ERR      4
#define INV_EOL_ERR        5
#define INV_PARAM_ERR      6
#define STR_TOOLONG_ERR    7
#define EOF_ERR            8
#define INV_OFS_ERR        9
#define READ_PERMISS_ERR   10
#define WRITE_PERMISS_ERR  11
#define UNKNOWN_ERR        12
#define INTERNAL_LIB_ERR   13
#define RTL_ERROR          14
#define OS_ERROR           15
#define NOT_TEXTFILE_ERR   16
#define BOF_ERR            17

#define CE_F_MASK_MODE         0x07
#define CE_F_MASK_PERMISS      0x18
#define CE_F_MASK_TYPE         0x20

#define CE_F_CREATE_NEW        0x01
#define CE_F_CREATE_ALWAYS     0x02
#define CE_F_OPEN_EXISTING     0x03
#define CE_F_OPEN_ALWAYS       0x04
#define CE_F_TRUNCATE_EXISTING 0x05

#define CE_F_WRITE             0x08
#define CE_F_READ              0x10
#define CE_F_BIN               0x20

                                 
#endif
