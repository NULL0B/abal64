/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXEVENT.C				*/
/*		Date 	:	19/04/2001				*/
/*		Version :	1.4d / 2.1g                		*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXEVENT_C
#define	_EXEVENT_C


#include "exmimo.h"
#include "excico.h"
#include "exevent.h"

EXTERN	BPTR	TcodeSegment;
EXTERN	BPTR	fdex;

#include <time.h>

EXAWORD	get_event_parameter( item )
EXAWORD	item;
{
	switch ( item )
	{
		/* MOUSE type EVENTS */
		/* ----------------- */
#ifdef	UNIX 
		case	0 :
		case	1 :
		case	2 :
		case	3 :
		case	4 :
		case	5 :
		case	6 :
		case	7 :
		case	8 :
		case	9 :	return( x_event( item ) );
#else
		case 0 : return( activate_mimo() );
		case 1 : return( get_mimo_type() ); 
		case 2 : return( get_mimo_par()  ); 
		case 3 : return( get_mimo_lin()  ); 
		case 4 : return( get_mimo_col()  ); 
		case 5 : return( get_mimo_mask() );
		case 6 : return( flush_mimo() );
		case 7 : return( inhibit_mimo()  );
#endif
		/* TASK type EVENTS */
		/* ---------------- */
		case 10 : return( event_spawn() );
#ifndef	DOS
		case 11: return( get_parent_identity() );
#endif

// FCH 19/12/2003(ancien code #ifndef WIN32 ?)
#ifdef XXX
		case 15 : return( get_mimo_lock() );
#endif

		case 20 : return( getpid() );		/* PID  */
#ifdef UNIX
		case 21 : return( getppid() );		/* PPID */
		case 22 : return( getuid() );		/* UID  */
		case 23 : return( getgid() );		/* GID  */
		case 24 : return((unsigned short)(EventTime = time((unsigned long *) 0)) );	/* TIME */
		case 25 : return((unsigned short)(EventTime >> 16));						/* TIME */
		case 26 : return( EventSignal );	/* TERM */
#endif

		case 27 : return( x_kbhit() );		/* KBHIT*/
		case 28 : return( x_getch() );		/* GETCH*/
		case 29 :	/* OP CURSE */
		case 30 :	/* OP HIDE  */
		case 31 :	/* ALT 800  */
		case 32 :	/* ALT OFF  */
			return( x_event(item));
#ifdef WIN32
		case 33 :	/* MOUSEDISP */
		case 34 :	/* MOUSEDISP */
		case 35 :	/* MOUSEDISP */
		case 36 :	/* MOUSEDISP */
		case 37 :	/* MOUSEDISP */
			return( x_event(item));
#endif
		case 40 :	/* EXIT ON  */
		case 41 :	/* EXIT OFF */
		case 42 :	/* SIZE ON  */
		case 43 :	/* SIZE OFF */
			return( x_event(item));
#ifdef UNIX
		case 44 :	/* EXIT MIMO*/
		case 45 :	/* SIZE MIMO*/
			return( x_event(item));
#endif
		case 50 :
		case 51 :
		case 52 :
		case 53 : 
		case 54 :	/* ASKFONT  */	 
		case 55 :	/* PRNFONT */	 
		case 56 :	/* FGRN MASK */	 
		case 57 :	/* BGRN MASK */	
			return(get_ask_event(item));

#ifdef UNIX
		case 58 : return(get_cut_key());
#endif
		case 59 : return(gethqfont());
		case 60 : return(get_assign_event()); 
		case 61 : return(get_op_event()); 
		case 66 : return(get_bda_null_pointer());
		case 67 : return(get_transparence_status());
#ifdef UNIX
		case 70 : return( get_application_window() );
		case 74 : return( get_yousleep() );			/* E74S */
#endif
		case 75 : return( get_gigo_cursor() );		/* CURSOR */

		case 77 : return( new_assign_handle(0) );	/* HANDLE   */
		case 78 : return( new_assign_handle(2) );	/* HANDLE   */
#ifdef UNIX
		case 80 : return( get_loadgo_mode() );		/* LOADGO   */
		case 81 : return( get_loadgo_counter() );	/* LOADGO   */
#endif
		case 82 : return( x_event(82) );
#ifdef UNIX
		case 88 :	/* get_cyrillic_base() */
#endif
		case 90 :	/* HIDE-SHOW */
		case 91 : 
		case 92 :
			return( x_event(item) );
#ifdef UNIX
		case 95 : return( get_reconfiguration() );
#endif
		case 98 :	/* grab status  */
		case 99 :	/* toggle grab 	*/
			return( x_event(item) );
#ifdef ABAL32A
#ifdef UNIX
		case 133 : return(is_loadgo_task());
#endif

/*	--------------------------------------	*/
/*	EVENT 666 informs of ABAL architecture	*/
/*	--------------------------------------	*/
#ifdef	ABAL64
		case 666 : return(64);
#else
#ifdef	ABAL32
		case 666 : return(32);
#else
		case 666 : return(16);
#endif
#endif
		case 667 : return(WORDSIZE);

		/* ---------------------- */
		/* Tcode Execution Thread */
		/* ---------------------- */
		case 160 : return( create_thread() );
		case 161 : return( get_thread_id() );
		case 162 : return( get_thread_parent() );
		case 163 : return( get_thread_priority() );
		case 164 : return( get_thread_duration() );
		case 165 : return( get_thread_event() );
		case 167 : return( get_thread_count() );
#endif	/* ABAL32A */

		case 200 :	/* top margin	*/
		case 201 :	/* right margin	*/
		case 202 :	/* bottom margin*/
		case 203 :	/* left margin	*/
		case 204 :	/* grid font height */
		case 205 :	/* grid font width  */
		case 206 :	/* grid y indent : for print or ask font */
		case 207 :	/* grid x indent : for print or ask font */
		case 208 :	/* cico page height */
		case 209 :	/* cico page width  */
		case 210 :	/* cico font number */
#ifdef WIN32
		case 222 :	/* (EVT_CHARSET) FCH03112004 nouvelle gestion OEM/ANSI */
		case 223 :	/* (EVT_LL_PASTE) FCH19102005 */
		case 224 :	/* (EVT_KEY_COPY_PASTE) FCH19102005 */
#endif
			return( x_event( item ) );

#ifdef UNIX
		case 300 : return( push_freeze() );
		case 301 : return( pop_freeze() );
		case 303 : return( get_allow_close_zero() );
		case 304 : return( get_gigo_direction() );
		case 305 : return( get_robotic() );
#endif
		case 997 : return( worktop );
		case 998 : return(get_argset_special());
		case 999 : return(get_stop_event());

		default :
			if (( item >= 100 ) && ( item <= 115 ))
				return( get_gigo_colour( (item-100) ) );
			else
				return( 0 );
	}
}

#ifdef	ABAL32A
EXAWORD	is_on_extern_event()
{
	if ((timersem & EVENT_FLAG) != 0)
		return(1);
	else	return(0);
}
#endif

EXAWORD	set_event_parameter( item, v )
EXAWORD	item;
EXAWORD	v;
{
	switch ( item ) {
#ifdef UNIX 
		case 0 :								/* MOUSE type EVENT */
			/* Redirected CICO/MIMO/GIGO special case */
			x_putch(27); x_putch('Z');
			x_putch((v & 0x00FF));
			x_putch(((v>>8) & 0x00FF));
			break;
#else
		case 0 : set_mimo_mask(v); break;		/* MOUSE type EVENT */
#endif
		case 1 : set_mimo_curser(v); break;		/* MOUSE type EVENT */
		case 2 : set_time_factor(v); break;		/* MOUSE type EVENT */
		case 3 : EventChannel = v; break;		/* MOUSE type EVENT */
		case 4 : IpcRaise(_SEMAPHORES_EXA +v); break;	/* Raise IPC Semaphore number 'v' */
		case 5 : IpcDrop(_SEMAPHORES_EXA+v);	/* Drop  IPC Semaphore number 'v' */
#ifdef PROLOGUE
			 /* Abandon Time Quantum */
			 /* -------------------- */
			 prologue_special_atb( 40 );
#endif
			 break;

		case 6 : IpcSynch(_SEMAPHORES_EXA+v); break;	/* Synch IPC Semaphore number 'v' : Wait Till DROP */

#ifdef WIN32
		case 7 : break;	/* loudspeaker, jamais implémenté */
#endif
		case 8 :	/* Allow or Inhibit Interruption By Event */
			if ( v & 1 )
				timersem |= EVENT_FLAG; /* Reactivate */
			 else
				 timersem &= 0xE000; /* Suspend    */
			 break;

		case 9 : IpcIncrement(_SEMAPHORES_EXA+v); break;

		case 10 : event_kill(v); break;	/* KILL Process 'v' */

		case 11 : IpcInterrupt(v); break;	/* Interrupt IPC Process number 'v' */

		case 12 : IpcDecrement(_SEMAPHORES_EXA+v); break;

		case 13 : ExaRetCode = v; break;

		case 14 : set_wait_factor(v); break;

// FCH 19/12/2003(ancien code #ifndef WIN32 ?)
#ifdef XXX
		case 15 : set_mimo_lock(v); break;
#endif

#ifdef UNIX
		case 26 :
			/* SIGNAL TERM */
			if (!( EventSignal )) {
				/* Default State */
				if ( v ) ignore_sigterm();
				}
			else if (!( v )) 
				catch_sigterm();

			EventSignal = v;
			break;
#endif

		case 50 :
		case 51 :
		case 52 :
		case 53 :
		case 54 :	/* ASK FONT  */
		case 55 :	/* PRN FONT  */
		case 56 :	/* FOREGROUND MASK */
		case 57 :	/* BACKGROUND MASK */
			set_ask_event(item,v); break;
#ifdef UNIX
		case 58 : set_cut_key(v); break;
#endif

		case 59 : sethqfont(v); break;
		case 60 : set_assign_event(v); break;
		case 62 : set_ask_event(item,v); break;		/* #BG 21/04/20 ASK VIRTUAL KBD */
		case 66 : set_bda_null_pointer(v); break;
		case 67 : set_transparence_status(v); break;
#ifdef	UNIX
		case 70 : set_application_window(v); break;
		case 74 : set_yousleep(v); break;
#endif
		case 75 : set_gigo_cursor(v); break;
		case 76 : x_configure(v); break;

		case 77:	/* HANDLE */
			if ( drop_assign_handle(v) == SOFTERROR )
				return( SOFTERROR );
			else	break;
#ifdef	UNIX
		case 80 : set_loadgo_mode(v); break;	/* LOADGO   */
#endif
		case 82 : break;	/* activate/disactivate graphique windows */
#ifdef	UNIX
		case 88 : set_cyrillic_base(v); break;
		case 95 : set_reconfiguration(v); break;
		case 97 : exa_event_failure( v ); break;	/* Generate a log message type v */
			
#ifdef	ABAL32A
		case 133: 
			set_loadgo_task(v);
			break;
#endif
#endif
#ifdef	ABAL32A
		/* ---------------------- */
		/* Tcode Execution Thread */
		/* ---------------------- */
		case 161: set_thread_id(v);		break;
		case 162: set_thread_parent(v);		break;
		case 163: set_thread_priority(v);	break;
		case 164: set_thread_duration(v);	break;
		case 165: send_thread_event(v);		break;
		case 166: 
			if ( remove_thread(v) != SOFTERROR )
				break;
			else	return( SOFTERROR );
		case 168: 
			if ( synchronise_thread(v) != SOFTERROR )
				break;
			else	return( SOFTERROR );
		case 169:
			if ( abqt_thread() != SOFTERROR )
				break;
			else	return( SOFTERROR );

#endif	/* ABAL32A */

#ifdef WIN32
		case 223:   /* (EVT_LL_PASTE) FCH19102005 */
		case 224:   /* (EVT_KEY_COPY_PASTE) FCH19102005 */
			x_event_val((WORD)item, (WORD)v); break;
#endif

#ifdef	UNIX
		case 300 :
#ifndef	DEBUGGER
			tcode_trace_control(v);
#endif
			break;
#ifdef	ABAL32A
		case 302 : set_xml_echo( v ); break;
#endif
		case 303 : set_allow_close_zero(v); break;
		case 304 : set_gigo_direction(v); break;
		case 305 : set_robotic(v); break;
#endif	/* UNIX */

#ifdef	ABAL32A
		case 998: set_argset_special(v);	break;
		case 999: set_stop_event(v);		break;
#endif

		default	:
			if (( item >= 100 ) && ( item <= 115 ))
				set_gigo_colour( (item-100), v );
			break;

		}

	return(GOODRESULT);
}

EXAWORD	check_extern_event()
{
	if ( timersem & EVENT_FLAG )
		return( GOODRESULT );
	else if (!( timersem & 0xC000 ))
		return( GOODRESULT );
	else if (( *fdex != _tc_WHN ))
		return( GOODRESULT );
	else if (( *(fdex+1) != ( _ec_POP | _ec_EXTERN) ))
		return( GOODRESULT );
	else	{
		disactivate_procedure();
		return( GOODRESULT );
		}
}

EXAWORD	activate_external_event( mode , arg )
EXAWORD	mode;
EXAWORD	arg;
{
	HardEvent = arg;

	if ((!(timersem & EVENT_FLAG)) && ( EventChannel == 0 ))
		start_mimo_alarm();

	switch ( mode & 0x003F ) {
		case	_ec_POP   : disactivate_procedure(); break;
		case	_ec_CALLI : 
			if ( attach_procedure_pointer( eventproc, HardEvent ) == SOFTERROR )
				return( SOFTERROR );
			else	{
				timersem |= EVENT_CALL; 
				break;
				}
		case	_ec_CALLV : timersem |= EVENT_VARB; break;
		case	_ec_GOTO  : timersem |= EVENT_GOTO; break;
		case	_ec_GOSUB : timersem |= EVENT_GSUB; break;
		default		  :
			err_val = 56;
			return( SOFTERROR );
		}

	return(1);
}

EXAWORD	disactivate_external_event()
{
	if ( timersem & EVENT_FLAG ) {
		cancel_mimo_alarm();
		timersem &= EVENT_WIPE;	/* Clear all External Event Bits */
		}
	return(1);
}

VOID	enable_hard_event()
{
	switch ((timersem & EVENT_KEEP)) {
		case	EVENT_GSUB	:
		case	EVENT_GOTO	: start_mimo_alarm();
		}
	return;
}

VOID	disable_hard_event()
{
	switch ((timersem & EVENT_KEEP)) {
		case	EVENT_GSUB	:
		case	EVENT_GOTO	: disactivate_external_event();
		}
	return;
}

/*
 *	H A N D L E _ E X T E R N A L _ E V E N T
 *	-----------------------------------------	
 *
 *	This function is called by the motor on reception of an
 *	interrupt driven event.
 *	
 *	The event may come from the mouse sub-system
 *	or from the task to task communication mechanism.
 *	or from the signam management sub system
 */

EXAWORD	handle_external_event()
{
	/* If event reception is active */
	/* ---------------------------- */
	if ( timersem & EVENT_KEEP )
		clear_wakeup_status();

	/* Activate Event Handler */
	/* ---------------------- */
	switch ((timersem & EVENT_KEEP)) {

		case	EVENT_GSUB :

			/* EXTERN EVENT GOSUB */
			/* ------------------ */
			if ( push_tcode_offset() != 0 )
				return( SOFTERROR );

		case	EVENT_GOTO :

			/* EXTERN EVENT GOTO */
			/* ----------------- */
			fdex = (TcodeSegment + HardEvent);
			timersem &= EVENT_HOLD;
			break;

		case	EVENT_CALL :
		case	EVENT_VARB :

			/* EXTERN EVENT CALL */
			/* ----------------- */
			return( activate_procedure( HardEvent, (timersem & EVENT_KEEP) ) );
		}
	return(1);
}

#endif	/* _EXEVENT_C */
		/* ---------- */

