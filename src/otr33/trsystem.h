#ifndef	_TRSYSTEM_H
#define	_TRSYSTEM_H

#ifdef	PROLOGUE
#define	_HOST_ENVIRONMENT "PROLOGUE"
#else
#ifdef	WIN32
#define	_HOST_ENVIRONMENT "WINDOWS"
#else
#ifdef	DOS
#define	_HOST_ENVIRONMENT "DOS"
#else
#ifdef	UNIX
#define	_HOST_ENVIRONMENT "UNIX"
#else
#ifdef	VMS
#define	_HOST_ENVIRONMENT "VMS"
#endif
#endif
#endif
#endif
#endif

#endif	/* _TRSYSTEM_H */
	/* ----------- */

