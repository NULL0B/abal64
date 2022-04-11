/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXTIMER - C				*/
/*		Version :	2.1d					*/
/*		Date 	:	07/10/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
/* Gestion des Fonctions de ON TIMER etc				*/
/* -------------------------------------				*/
/* Include file for EXCALC - C						*/
/*----------------------------------------------------------------------*/

#ifdef UNIXWARE1
#include <sys/time.h>
#endif
#ifdef	ABAL21
EXAWORD	TimeFactor;
#else
#define	TimeFactor 10
#endif

#ifndef PROLOGUE
#ifndef DOS
#include <signal.h>
/*
 *	T I M E R _ T R A P ( )
 *	-----------------------
 *	Performs ALARM signal reception for UNIX ON TIMER operation
 *
 */

timer_trap(nbs)
int	nbs;
{
	if ( nbs == SIGALRM ) {
		(VOID) signal(SIGALRM,timer_trap);
		descarto[0] = (EXABYTE) 0;
		}
	return(0);
}

#endif	/* ! DOS */
#endif	/* ! PRL */


#ifdef DOS

#ifndef	WIN16
#ifndef	WIN32
long	artogo,artostp;		/* DOS timer management variables	*/
extern	long calcsec();		/* Second calculator function		*/
#endif
#endif

/*
 *	D O S _ A R T O ( )
 *	-------------------
 *	Checks current timer condition if timer is active
 */

VOID	dos_arto()
{

#ifdef	WIN1632

	/* ------------------------------------ */
	/* WINDOWS NT : purge the message queue */
	/* ------------------------------------ */
EXTERN	int __fastcall GetNoWait(void);
	while (GetNoWait() != 0);

#else	/* ! WINDOWS */

	/* ----------------------- */
	/* MSDOS REAL and EXTENDED */
	/* ----------------------- */

 	long	nowarto;
 	nowarto = calcsec();
 	if ( nowarto < artogo ) { nowarto += 86400; }
 	if ( nowarto < artostp) { return; }
 	descarto[0] &= (EXABYTE) TIME_REARM;
	return;

#endif	/* WIN1632 */

} 

#endif

/*
 *	I N I T _ T I M E R ( )
 *	-----------------------
 *	Initialises the systeme alarm timer
 */

VOID	init_timer()
{
#ifdef UNIXWARE1
struct itimerval value;
int ret_alarm;
struct itimerval sv_alarm;
#endif

#ifdef	PROLOGUE
	descarto[0] = (EXABYTE) TIME_ALARM; TcodePmot( &descarto[1] , timercpt);
	(VOID) arto(descarto);
#endif

#ifdef DOS
#ifdef	WIN1632
	/* WINDOWS */
EXTERN int __fastcall MTimerCreate(VPTR,VPTR,EXALONG,EXALONG);
	descarto[0] = (EXABYTE) TIME_ALARM; TcodePmot( &descarto[1] , timercpt);
	(void) MTimerCreate((VPTR)&descarto[0],(VPTR) 0, (EXALONG) 0, (EXALONG) 0);

#else	/* ! WIN1632 */

	/* DOS REAL and EXTENDED */
	descarto[0] = (EXABYTE) TIME_ALARM; TcodePmot( &descarto[1] , timercpt);
	artogo  = calcsec(); artostp = artogo + (timercpt / TimeFactor);
#endif	/* WIN1632 */
#endif	/* DOS	 */

#ifndef DOS
#ifndef PROLOGUE
	(VOID) signal(SIGALRM,timer_trap);
#ifdef UNIXWARE1
	value.it_interval.tv_sec=0L;
	value.it_interval.tv_usec=0L;
	value.it_value.tv_sec=timercpt;
	value.it_value.tv_usec=0L;
	ret_alarm=setitimer(ITIMER_REAL,&value,&sv_alarm);
#else
	(VOID) alarm( (timercpt / TimeFactor) );
#endif
	descarto[0] = (EXABYTE) TIME_ALARM;
#endif
#endif
	return;
}

/*
 *	R A Z _ T I M E R ( )
 *	---------------------
 *	Disactivates any systeme timers currently active
 */

VOID	raz_timer()
{
#ifdef UNIXWARE1
struct itimerval value;
int ret_alarm;
struct itimerval sv_alarm;
#endif

	if (( timersem & TIME_ACTIF ) != 0 ) {

#ifdef	PROLOGUE
		(VOID) drto( descarto );
		descarto[0] = (EXABYTE) 0;
#endif


#ifdef DOS
#ifdef	WIN1632
	/* WINDOWS */
EXTERN	void __fastcall MTimerDelete(VPTR);
	MTimerDelete((VPTR)&descarto[0]);
	descarto[0] = (EXABYTE) 0;

#else
	/* DOS */
	artogo = 0; artostp = 0;
	descarto[0] = (EXABYTE) 0;

#endif	/* WIN1632 */
#endif	/* DOS	 */

#ifndef	PROLOGUE
#ifndef	DOS
#ifdef UNIXWARE1
		value.it_interval.tv_sec=0L;
		value.it_interval.tv_usec=0L;
		value.it_value.tv_sec=0;
		value.it_value.tv_usec=0L;
		ret_alarm=setitimer(ITIMER_REAL,&value,&sv_alarm);
#else
		(VOID) alarm(0);
#endif
		(VOID) signal(SIGALRM,SIG_IGN);
		descarto[0] = (EXABYTE) 0;
#endif
#endif
		}
	timersem &= TIME_RAZ;
	return;
}

/*
 *	T I M E R W O R K ( )
 *	---------------------
 *	Interface for TIMER functions ( from Main T-Code Switching Motor )
 *
 *	Returns 0 = > Error else any Value
 */

EXAWORD	timerwork()
{
	EXAWORD	timex,timext;
	timext = 0;
	switch ( (timex = (EXAWORD) *(fdex++)) & 0x000F ) {	
		case 0 : /* TIMER OFF 	   */
			(VOID) raz_timer(); return(1);
		case 2 : /* ON TIMER GOSUB */
			timext = TIME_GOSUB;
		case 1 : /* ON TIMER GOTO  */
			 break;
		default: err_val = 56; return(SOFTERROR);
		}
	if ( argset((timex & 0x00E0) >> 5 ,0,1) == SOFTERROR ) { return(SOFTERROR); }
	switch ( worktyp1 ) { /* Perform Auto Convert to Integer */
			      /* ------------------------------- */	
		case VARB_BCD : workval1 = bcdtoi(workptr1,worklen1); break;
		case VARB_STR : workval1 = atoi(workptr1,worklen1);   break;
		}
	timercpt = (EXAWORD) workval1 * TimeFactor;
	timeradr = Tcodeword(fdex); fdex += WORDSIZE;
	if (timercpt == 0) return(1);	/* On Timer Zero Does Nothing */
	(VOID) init_timer();
	timersem &= TIME_RAZ; timersem |= ( timext | TIME_ACTIF );
	return(1);
}

#ifdef	ABAL21
VOID	set_time_factor( n )
EXAWORD	n;
{
	if ( n != 0 )
		TimeFactor = n;
	else	TimeFactor = 10;
	return;
}
#endif

