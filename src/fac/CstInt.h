// ***********************************************************************************************
// * CstInt.h
// ***********************************************************************************************

#ifndef CSTINT_H
#define CSTINT_H

// ----------------------------------------------------------------------------------
// - Portabilité des fonctions runtime I/O
// ----------------------------------------------------------------------------------
#if defined(BDA_WIN32)
#define  Portable_access   _access
#define  Portable_close    _close
#define  Portable_creat    _creat
#define  Portable_errno    _errno
#define  Portable_lseek    _lseek
#define  Portable_open     _open
#define  Portable_mkdir    _mkdir
#define  Portable_rmdir    _rmdir

#elif defined (BDA_UNIX)
#define  Portable_access   access
#define  Portable_close    close
#define  Portable_creat    creat
#define  Portable_errno    errno
#define  Portable_lseek    lseek
#define  Portable_open     open
#define  Portable_mkdir    mkdir
#define  Portable_rmdir    rmdir

#elif defined(BDA_TWIN16)

#define  Portable_access   _access
#define  Portable_close    _close
#define  Portable_creat    _creat
#define  Portable_errno    _errno
#define  Portable_lseek    _lseek
#define  Portable_open     _open
#define  Portable_mkdir    _mkdir
#define  Portable_rmdir    _rmdir

#else
#error PROLOGUE MSG: OS inconnu
#endif

#endif
