#ifndef	_EXEVENT_C
#define	_EXEVENT_C

#include "exmimo.h"

EXAWORD	EventChannel;
#ifdef	ABAL21

EXAWORD	HardEvent=0;
EXAWORD	EventSignal=0;

unsigned	long	EventTime=0L;

EXAWORD	get_event_parameter( item )
EXAWORD	item;
{
	unsigned long time(unsigned long *);
	switch ( item ) {

		/* MOUSE type EVENTS */
		/* ----------------- */
#ifdef	LINUX
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
		case 10: return( event_spawn()   );
#ifndef	DOS
		case 11: return( get_parent_identity() );
		
#endif
#ifdef	UNIX
/* PID  */	case 20: return( getpid() );
/* PPID */	case 21: return( getppid() );
/* UID  */	case 22: return( getuid() );
/* GID  */	case 23: return( getgid() );
/* TIME */	case 24: return((unsigned short)(EventTime = time((unsigned long *) 0)) );
/* TIME */	case 25: return((unsigned short)(EventTime >> 16));
/* TERM */	case 26: return( EventSignal ); 
/* KBHIT*/      case 27: return( x_kbhit() );
/* GETCH*/      case 28: return( x_getch() );
/* OP CURSE */ 	case 29: return( x_event(29) );
/* OP HIDE  */ 	case 30: return( x_event(30) );
/* E74S */	case 74: return( get_yousleep() ); 
/* CURSOR */	case 75: return( set_gigo_cursor(-1) ); 
#endif
		case 90 : return( x_event( 90 ) );
		case 91 : return( x_event( 91 ) );
		case 92 : return( x_event( 92 ) );

		case 50 :
		case 51 :
		case 52 :
		case 53 : return(get_ask_event(item)); 
		case 60 : return(get_assign_event()); break;
		case 61 : return(get_op_event()); break;
		case 66 : return(get_bda_null_pointer()); break;
/* TEST KBG */ 	case 98 : return( x_event(98) );
/* TOGG KBG */ 	case 99 : return( x_event(99) );
		default : return( 0 );
		}
}


EXAWORD	set_event_parameter( item, v )
EXAWORD	item;
EXAWORD	v;
{
	switch ( item ) {
		/* MOUSE type EVENTS */
		/* ----------------- */
#ifdef	LINUX
		case 0 :
			/* Redirected CICO/MIMO/GIGO special case */
			x_putch(27); x_putch('Z');
			x_putch((v & 0x00FF));
			x_putch(((v>>8) & 0x00FF));
			break;
#else
		case 0 : set_mimo_mask(v);   break;
#endif
		case 1 : set_mimo_curser(v); break;
		case 2 : set_time_factor(v); break;
		case 3 : EventChannel = v;   break;

		/* Raise IPC Semaphore number 'v' */
		/* ------------------------------ */
		case 4 : IpcRaise(_SEMAPHORES_EXA +v);	     break;
		case 9 : IpcIncrement(_SEMAPHORES_EXA+v);    break;

		/* Drop  IPC Semaphore number 'v' */
		/* ------------------------------ */
		case 5 : IpcDrop(_SEMAPHORES_EXA+v);
#ifdef	PROLOGUE
			 /* Abandon Time Quantum */
			 /* -------------------- */
			 prologue_special_atb( 40 );
#endif
			 break;
		case 12: IpcDecrement(_SEMAPHORES_EXA+v);    break;

		/* Synch IPC Semaphore number 'v' : Wait Till DROP */
		/* ----------------------------------------------- */
		case 6 : IpcSynch(_SEMAPHORES_EXA+v);	     break;

#ifndef	UNIX
		case 7 : loudspeaker(v);     break;
#endif
		/* Allow or Inhibit Interruption By Event */
		/* -------------------------------------- */
		case 8 : if ( v & 1 )
				timersem |= 0x1000; /* Reactivate */
			 else   timersem &= 0xE000; /* Suspend    */
			 break;

		/* KILL Process 'v' */
		/* ---------------- */
		case 10 : event_kill(v);	     break;

		/* Interrupt IPC Process number 'v' */
		/* -------------------------------- */
		case 11 : IpcInterrupt(v);   break;
		case 13 : ExaRetCode = v; break;

#ifdef	UNIX
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

		case 74 : set_yousleep(v); 		break;
		case 75 : set_gigo_cursor(v);		break;
#endif
	
		case 50 :
		case 51 :
		case 52 :
		case 53 : set_ask_event(item,v); 	break; 
		case 60 : set_assign_event(v);		break;
		case 66 : set_bda_null_pointer(v);	break;
		case 67 : set_transparence_status(v);	break;
		default	:
			if (( item >= 100 ) && ( item <= 115 ))
				set_gigo_colour( (item-100), v );
			break;




		}

	return(GOODRESULT);
}

EXAWORD	activate_external_event( mode , arg )
EXAWORD	mode;
EXAWORD	arg;
{
	HardEvent = arg;

	if ((!(timersem & 0x1000)) && ( EventChannel == 0 ))
		start_mimo_alarm();

	switch ( mode & 0x003F ) {
		case	_ec_POP   : disactivate_procedure(); break;
		case	_ec_CALLI : timersem |= 0x5000; break;
		case	_ec_CALLV : timersem |= 0x9000; break;
		case	_ec_GOTO  : timersem |= 0x1000; break;
		case	_ec_GOSUB : timersem |= 0x3000; break;
		default		  :
			err_val = 56;
			return( SOFTERROR );
		}

	return(1);
}

EXAWORD	disactivate_external_event()
{
	if ( timersem & 0x1000 ) {
		cancel_mimo_alarm();
		timersem &= 0x0FFF;	/* Clear all External Event Bits */
		}
	return(1);
}

VOID	enable_hard_event()
{
	switch ((timersem & 0xF000)) {
		case	0x3000 : 
		case	0x1000 : start_mimo_alarm();
		}
	return;
}

VOID	disable_hard_event()
{
	switch ((timersem & 0xF000)) {
		case	0x3000 : 
		case	0x1000 : disactivate_external_event();
		}
	return;
}

EXTERN	BPTR	TcodeSegment;
EXTERN	BPTR	fdex;

/*
 *	H A N D L E _ E X T E R N A L _ E V E N T
 *	-----------------------------------------	
 *
 *	This function is called by the motor on reception of an
 *	interrupt driven event.
 *	
 *	The event may come from the mouse sub-system or from the task
 *	to task communication mechanism.
 *	
 */

EXAWORD	handle_external_event()
{
	/* If event reception is active */
	/* ---------------------------- */
	if ( timersem & 0xF000 )
		clear_wakeup_status();

	/* Activate Event Handler */
	/* ---------------------- */
	switch ((timersem & 0xF000)) {

		case	0x3000 :

			/* EXTERN EVENT GOSUB */
			/* ------------------ */
			if ( push_tcode_offset() != 0 )
				return( SOFTERROR );

		case	0x1000 :

			/* EXTERN EVENT GOTO */
			/* ----------------- */
			fdex = (TcodeSegment + HardEvent);
			timersem &= 0xEFFF;
			break;

		case	0x5000 : 
		case	0x9000 :

			/* EXTERN EVENT CALL */
			/* ----------------- */
			return( activate_procedure( HardEvent, (timersem & 0xF000) ) );
		}
	return(1);
}
#endif

#endif	/* _EXEVENT_C */
	/* ---------- */

