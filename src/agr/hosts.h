/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990,1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	HOSTS.H					*/
/*		Version :	1.1a					*/
/*		Date	:	03/05/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_HOSTS_H
#define _HOSTS_H

/*	-----------------------------------------------			*/
/*	Verification of HOST system Identity Definition			*/
/*	-----------------------------------------------			*/

#ifdef PROLOGUE
#define prologue
#else
#ifdef DOS
#define msdos
#else
#ifdef UNIX
#define unix
#else
#ifdef VMS
#define vms
#else
#ifdef dosext
#else
host is undefined
#endif
#endif
#endif
#endif
#endif

#endif	/* _HOSTS_H */
	/* -------- */






