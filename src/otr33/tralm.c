#ifndef _TRALM_C
#define _TRALM_C
#ifdef UNIX
ALM_ERROR 	PUBAPI ALM_initiate() { return( 0 ); }
ALM_HANDLE 	PUBAPI ALM_declare() { return( 0 ); }
ALM_HANDLE 	PUBAPI ALM_new() { return( 0 ); }
ALM_HANDLE 	PUBAPI ALM_sharename() { return( 0 ); }
ALM_HANDLE 	PUBAPI ALM_sharehandle() { return( 0 ); }
ALM_HANDLE 	PUBAPI ALM_overload() { return( 0 ); }
ALM_ERROR 	PUBAPI ALM_load() { return( 0 ); }
ALM_ERROR 	PUBAPI ALM_use() { return( 0 ); }
ALM_ERROR 	PUBAPI ALM_drop() { return( 0 ); }
ALM_ERROR 	PUBAPI ALM_forget() { return( 0 ); }
ALM_ERROR 	PUBAPI ALM_remove() { return( 0 ); }
ALM_ERROR 	PUBAPI ALM_terminate() { return( 0 ); }
PIDT		PUBAPI ALM_getpid() { return( 0 ); }
PIDT		PUBAPI ALM_getppid() { return( 0 ); }
ALM_ERROR 	PUBAPI ALM_whoamI() { return( 0 ); }
#endif
#endif
