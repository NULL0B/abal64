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

#ifdef	VERSION666
#define	MODULE_VERSION      " 5.1a.0.01 "
#define MODULE_COPYRIGHT    "\r\n   Copyright (c) 2021 Amenesik / Sologic"
#else
#ifdef	PROLOGUE3
#define	MODULE_VERSION      " 2.1d.0.02 "
#else
#define	MODULE_VERSION      " 2.1g.0.01 "
#endif
#define MODULE_COPYRIGHT    "\r\n   Copyright (c) 2021 Amenesik / Sologic"
#endif
#define	MODULE_ENVIRONMENT  "\r\n   Environnement Version 1.1a "

#endif	/* _VERSION_H */
	/* ---------- */

