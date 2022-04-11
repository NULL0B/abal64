/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TREVENT.H				*/
/*		Version :	2.1d					*/
/*		Date	:	20/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TREVENT_H
#define	_TREVENT_H

#define	_ev_RAZ		0x00	/* Clears Event processing		*/
#define	_ev_DCL		0x01	/* Establish Event processing		*/
#define	_ev_FAUX	0x02	/* Event expression FAUX signal		*/
#define	_ev_STOP	0x04	/* Event annulation (THEN or GOTO)	*/
#define	_ev_HALT	0x08	/* Event supension (DO or GOSUB type)	*/
#define	_ev_START	0x10	/* Event restart (after GOSUB)		*/
#define	_ev_CLP  	0x62	/* GLOBAL PROCEDURE HANDLER INTEGER	*/
#define	_ev_CLV  	0x63	/* GLOBAL PROCEDURE HANDLER VARIABLE	*/
#define	_ev_JMI   	0x60	/* LOCAL GOTO HANDLER                	*/
#define	_ev_GSB   	0x61	/* LOCAL GOSUB HANDLER               	*/
#define	_ev_POP		0x64	/* POP after EVENT CALL			*/
#define	_ev_OCXCLP  	0x6A	/* OCX    PROCEDURE HANDLER INTEGER	*/
#define	_ev_OCXCLV  	0x6B	/* OCX    PROCEDURE HANDLER VARIABLE	*/
#define	_ev_OCXPOP  	0x6C	/* OCX    POP after Event Call      	*/

/*	Executeur EVENT semaphores			*/
/*	--------------------------			*/


#endif	/* _TREVENT_H */
	/* ---------- */
