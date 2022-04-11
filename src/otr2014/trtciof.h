/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	TRTCIOF.H  				*/
/*		Date 	:	15/12/1994				*/
/*		Version :	2.1d 					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_TRTCIOF_H		/* If Not already included		*/
#define	_TRTCIOF_H		/* Avoid multiple inclusions		*/
/*----------------------------------------------------------------------*/
/* 		IOF Sub function codes					*/
/*----------------------------------------------------------------------*/
#define	_IOF_PRINT	0x0000
#define	_IOF_ASK	0x0001
#define	_IOF_PAUSE	0x0002
#define	_IOF_OP		0x0003
#define	_IOF_GET	0x0004
#define	_IOF_PUT	0x0005

#define	_IOF_TAB	0x0000
#define	_IOF_TABV	0x0001
#define	_IOF_PAINT	0x0002
#define	_IOF_ATB	0x0003
#define	_IOF_CLEAR	0x0004
#define	_IOF_BELL	0x0005
#define	_IOF_HOME	0x0006
#define	_IOF_PAGE	0x0007

#endif	/* _TRTCIOF_H */
