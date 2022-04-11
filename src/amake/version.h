/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Module indetification			*/
/*		------------------------------------			*/
/*									*/
/*		  Copyright (c) 1991, 1994 Amenesik / Sologic s.a.		*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	VERSION.H 				*/
/*		Version :	2.1c					*/
/*		Date	:	02/06/1994				*/
/*									*/
/* -------------------------------------------------------------------- */

#ifndef	_VERSION_H
#define	_VERSION_H

/*
 *	Module identification Constants
 *	-------------------------------
 */
#ifdef	UNIX
#define	MODULE_VERSION      " 3.1e.0.01 "
#else

#ifdef	PROLOGUE3
#define	MODULE_VERSION      " 2.1c -P3 "
#else
#define	MODULE_VERSION      " 2.1e "
#endif
#endif

#define	MODULE_ENVIRONMENT  "\r\n   Environnement Version 1.1a "
#define MODULE_COPYRIGHT    "\r\n   Copyright (c) 1989,2006 Amenesik / Sologic "

#endif	/* _VERSION_H */
	/* ---------- */

