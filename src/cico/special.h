#ifndef	_special_h
#define _special_h

#define	STDIN	0
#define	STDOUT	1
#define	VOID	void

#ifdef	AIX
#define	PSEUDO_DEVICE_MASTER "/dev/ptc"
#else
#define	PSEUDO_DEVICE_MASTER "/dev/ptmx"
#endif

#ifndef	SA_ONESHOT
#ifndef SA_RESETHAND
#define SA_ONESHOT 0
#else
#define	SA_ONESHOT SA_RESETHAND
#endif
#endif

#endif	/* _special_h */
	/* ---------- */

