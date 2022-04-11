/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Module indetification			*/
/*		------------------------------------			*/
/*									*/
/*		  Copyright (c) 2021 Amenesik / Sologic.		*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	VERSION.H 				*/
/*		Version :	5.1a					*/
/*		Date	:	03/05/2021				*/
/*									*/
/* -------------------------------------------------------------------- */

#ifndef	_VERSION_H
#define	_VERSION_H

/*
 *	Module identification Constants
 *	-------------------------------
 */
#ifdef	ABAL64
#define	MODULE_VERSION      " 5.1a.0.01 "
#else
#ifdef	VERSION666
#define	MODULE_VERSION      " 3.2b.0.01 "
#else
#ifdef	PROLOGUE3
#define	MODULE_VERSION      " 2.1c -P3 "
#else
#define	MODULE_VERSION      " 2.1e "
#endif
#endif
#endif
#define	MODULE_ENVIRONMENT  "\r\n   Environnement Version 1.1a "
#define MODULE_COPYRIGHT    "\r\n   Copyright (c) 2021 Amenesik / Sologic"

#endif	/* _VERSION_H */
	/* ---------- */

