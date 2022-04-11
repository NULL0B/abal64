#ifndef	_modem_h
#define	_modem_h

/*	This file is intended to establish the correct options		*/
/*	for the 	activation of modem control signals		*/
/*	for ABAL TTY dynamic library for UNIX and LINUX			*/
/*	There are so many different BIT flag names that might exist	*/
/*	This works for USEIT (11/09/2003 : IJM)				*/

/* On est pass‚ par ici un jour sous USEIT : les definitions CTSFLOW, RTSFLOW sont indefini ! IJM/JS */

#ifndef	CTSFLOW
#define		CTSFLOW		0
#endif
#ifndef	RTSFLOW
#define		RTSFLOW		0
#endif

#define	RIEN		(CLOCAL)
#define	SOFTWARE	(CLOCAL)

/* On est pass‚ par ici le meme jour sous USEIT : les definition CNEW_RTSCTS n'existe pas non plus IJM/JS */

#ifdef	CNEW_RTSCTS
#define	HARDWARE (CNEW_RTSCTS | CLOCAL)
#else
#ifdef CRTSCTS
/* On a rajout‚ ceci apres avoir regarder le bible tty de gigi et les fichier .h sous useit : 02/09/2003 IJM/JS */
/* HARDWARE etait toujours zero !!!! alors pas de control de signaux de modem jamais jamais */
#define	HARDWARE (CRTSCTS | CLOCAL)
#else
#define	(HARDWARE (CTSFLOW | RTSFLOW) | CLOCAL)
#endif
#endif


#endif	/* _modem_h */


