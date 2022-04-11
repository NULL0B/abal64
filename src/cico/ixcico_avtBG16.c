#ifdef	LINUX
#define	_CICO_MIMO
#undef _MOUSE_TRACE
//#define _MOUSE_TRACE
#define MOUSE_TRACE_FILE	
#undef _KEYB_TRACE
//#define _KEYB_TRACE
#endif

#ifdef _MOUSE_TRACE
#define MOUSE_TRACE_FILE	"MouseTrace.txt"
#endif
#ifdef _KEYB_TRACE
#define KEYB_TRACE_FILE		"KeybTrace.txt"
#endif

#include <stdio.h>
#include "exerrcodes.h"
#ifdef EXABAL
#include "exasyslog.h"
#endif


/*
 *	----------------------------------------------
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1989 Amenesik / Sologic s.a.
 *
 *	lincico.c - fonctions interface ecran/clavier/imprimante
 *
 *	$Header: /home/Produits/Abal3/cico/ixcico.c,v 1.26 2008/10/10 08:46:52 jamie Exp $
 *
 *	$Header    cico/src/lincico.c@@	   04 Oct 2001 13:25:00  IJM $
 *
 *
 *	This file is a rework of the standard IXCICO.C file in order to
 *	give access to ABAL tools through the new CicoAccessController
 *	module in EXCICO.C.
 *
 *	The standard functions defined here are now the local versions
 *	used by default by the access controller. They may in fact be
 *	redirected by_ dynalmic libraries but here we do not care !
 *
 */

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

static	int	GetchEscQ=-2;

/* #BG 24/03/11 */
int utf8_flag = 0;

#define	_GETCH_ESC_Q	0x0010

#if unix || M_XENIX

#include <fcntl.h>
#include <unistd.h>
#include <termio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utmp.h>
#ifdef NEW_TEMPO
#ifdef AIX_VERS
#if !defined(UNIXWARE) && !defined(SPARC) && !defined(AVIION) && !defined(LINUX) 
#include <sys/time.h>
#endif
#else  /* AIX_VERS */
#ifdef LINUX
#include <sys/time.h>
#else
#include <sys/itimer.h>
#endif
#endif /* AIX_VERS */
#endif /* NEW_TEMPO */
#endif /* unix || M_XENIX */

#ifdef vms

#include <unixio.h>
#include <file.h>
#include <types.h>

#endif /* vms */

#define UPDATE	"$Date: 2008/10/10 08:46:52 $"

#define	ALSMID "cico"
#include "allocate.h"

#ifdef CICO_BDA
#include "bda_std.h"
#endif /* fin CICO_BDA */

#ifdef ASFCICO
#include "asfcico.h"
#endif /* ASFCICO */

#include "_cico.h"
#include "cico.h"
#include "ixcico.h"
#include "ixmimo.h"

#ifdef	EXABAL
#ifndef	LIBPRINT
#include "ixlo.h"
#include "ixim.h"
#endif
#endif

#ifdef ABALCONF
#include "aconf.h"
#include "aconf.c"
#endif /* ABALCONF */

static	int	C_FORE=C_GREEN;
static	int	C_BACK=C_BLACK;

#include "apush.c"

#ifndef	EXABAL
#define	terminate_local_lo()
#include "ixmima.c"
#else
#define	system(s) exa_system(s)
#endif

/*	-------------------------------------------	*/
/*							*/
/*		-------		-------			*/
/*		C I C O 	M I M O			*/
/*		-------		-------			*/
/*							*/
/*	Mouse management in text mode ( at last ) 	*/	
/*							*/
/*	-------------------------------------------	*/

#ifdef	LINUX
#define	_CICO_MIMO
#endif

#ifdef	_CICO_MIMO
int	useitgo=USEIT_FIRST;
int	useitnb=USEIT_NB;

static	int	is_cico_mouse_event=0;
static	struct  cico_mouse_event {
	WORD	type;
	WORD	param;
	WORD	textlin;
	WORD	textcol;
	WORD	graflin;
	WORD	grafcol;
	WORD	mask;
	WORD	state;
	char   *   detect;	
	char   *   start;
	char   *   stop;
	WORD	limit;
	WORD	buttons;
	WORD	x;
	WORD	y;
	} CicoMimo = { 
		0,0,0,0,0,0,
		0x3333,0, 
		(char *) 0, (char *) 0, (char *) 0,
		3,0,0,0 
		};

#ifdef	_MOUSE_TRACE
FILE	*	MouseTrace=(FILE*) 0;
#endif
#endif

#ifdef	_KEYB_TRACE
FILE	*	KeybTrace=(FILE*) 0;
#endif

#ifdef	_USEIT_FOR_WHATEVER
static	int	signature_version=14;
#endif

#define XCICO_NB 8
WORD XCICO_nbl;
CHAR XCICO_start[XCICO_NB]={'6','9','2','9','3','9','3','9'};

#ifdef CICO_DEBUG
FILE *DEBUG;
#endif /* fin CICO_DEBUG */

int	_co_esc_Q();

static	void	cico_key_event(keycode)
int keycode;
{
#ifdef	_CICO_MIMO
	CicoMimo.type =_MIMO_KEYBOARD;
	CicoMimo.param= (keycode & 0x00FF);
	CicoMimo.textlin=CicoMimo.textcol = CicoMimo.grafcol=CicoMimo.graflin=0;
#endif
	return;
}

#include "cicolang.c"

static	int	cosyswrite(fh,bptr,blen)
	int fh;
	BYTE * bptr;
	unsigned int blen ;
{
	int i = 0;

	while (1) {
		if ( write(fh,bptr,blen) != -1 )
			return( blen );
		else if ( errno == EAGAIN ) {
#ifdef EXABAL
			if (i<20) {
				sprintf(SysLogBuffer, "Error: cosyswrite again, errno=%d", errno);
				ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
				i++;
				}
#endif
			continue;
			}
		else {
#ifdef EXABAL
			sprintf(SysLogBuffer, "Error: cosyswrite failed, bptr=%08lx, blen=%d, errno=%d", bptr, blen, errno);
			ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
			strcpy(SysLogBuffer, "Dump bptr: ");
			for(i=0; i<blen && i<128; i++)
				sprintf(SysLogBuffer+strlen(SysLogBuffer), "%02X ", (BYTE)bptr[i]);
			ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
			return(-1);
			}
		}
}

#ifdef	EXABAL
#ifndef	LIBPRINT
#include "iximploc.c"
#endif
#endif
/*	Inclusion of the Access Controller 	*/
/*	----------------------------------	*/
#include "excico.c"

/*************************************************************************
 *									 *
 *		Primitives de gestion de la saisie au clavier		 *
 *									 *
 *************************************************************************/
#ifdef _DELAY
static BOOL _delay = TRUE;
#endif


/*	This definition is for the form		*/
/*	-------------------------------		*/
#define	INTERFACE	


/*	----------------------------------------------		*/
/*	Detection of keyboard request for Print Screen		*/
/*	----------------------------------------------		*/

INTERFACE	WORD	getch_esc_q( c )
WORD			c;
{
	if ( c != GetchEscQ )
		return( 0 );
	else	return( 1 );
}

PRIVATE		VOID	initialise_printscreen()
{
	char * 	eptr;
	GetchEscQ = -2;
	if (!( eptr = getenv( "GETCHESCQ" )))
		return;
	else	{
		GetchEscQ = atoi( eptr );
		return;
		}
}

	
/* saisie d'un caractere depuis le clavier suivant la norme Amenesik / Sologic
 * -----------------------------------------------------------------
 *
 * appel:	rien
 *
 * retour:	le caractere
 *
 */

INTERFACE 	WORD 	local_x_event(eventid)
WORD eventid;
{
WORD Ret = 0;

#ifdef	_CICO_MIMO
	if (!( CicoMimo.detect ))
		return(0);

#ifdef	_MOUSE_TRACE
	if (MouseTrace == (FILE*)0)
		MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
	fprintf(MouseTrace, "ixcico.c 1: local_x_event(eventid=%u)\r\n", eventid);	
//	fclose(MouseTrace);
//	MouseTrace = (FILE*) 0;
#endif

	switch ( eventid ) {
		case	0	: 
			if (!( CicoMimo.state )) {
				if ( CicoMimo.start )
					_co_capacite( CicoMimo.start );
				CicoMimo.state = 1;
#ifdef	_MOUSE_TRACE
			if (MouseTrace == (FILE*)0)
				MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
			fprintf(MouseTrace, "               CicoMimo.state=%u, CicoMimo.start=%u\r\n", CicoMimo.state, CicoMimo.start);	
#endif
				}
			Ret = 0;
			break;
			
		case 7:
			if ( CicoMimo.state ) {
				while ( x_kbhit() ) (void) x_getch();
				if ( CicoMimo.stop )
					_co_capacite( CicoMimo.stop );
				while ( x_kbhit() ) (void) x_getch();
				CicoMimo.state = 0;
#ifdef	_MOUSE_TRACE
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace, "               CicoMimo.state=%u, CicoMimo.stop=%u\r\n", CicoMimo.state, CicoMimo.stop);	
#endif
				}
			Ret = 0;
			break;
			
		case 1: 
#ifdef	_MOUSE_TRACE
			if (MouseTrace == (FILE*)0)
				MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
			fprintf(MouseTrace, "               CicoMimo.type=%u\r\n", CicoMimo.type);	
#endif
			Ret = CicoMimo.type;
			break;
			
		case 2:
#ifdef	_MOUSE_TRACE
			if (MouseTrace == (FILE*)0)
				MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
			fprintf(MouseTrace, "               CicoMimo.param=%u\r\n", CicoMimo.param);	
#endif
			Ret = CicoMimo.param;
			break;
			
		case 3:
#ifdef	_MOUSE_TRACE
			if (MouseTrace == (FILE*)0)
				MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
			fprintf(MouseTrace, "               CicoMimo.textlin=%u\r\n", CicoMimo.textlin);	
#endif
			Ret = CicoMimo.textlin;
			break;
			
		case 4:
#ifdef	_MOUSE_TRACE
			if (MouseTrace == (FILE*)0)
				MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
			fprintf(MouseTrace, "               CicoMimo.textcol=%u\r\n", CicoMimo.textcol);	
#endif
			Ret = CicoMimo.textcol;
			break;
			
		case 5:
			Ret = CicoMimo.mask;
			break;
			
		case 6:
			while ( x_kbhit() ) (void) x_getch(); 
			Ret = 0;
			break;
			
		case 8:
			Ret = CicoMimo.graflin;
			break;
			
		case 9:
			Ret = CicoMimo.grafcol;
			break;
			
		default:
			Ret = 0;
			break;
		}
	
#ifdef	_MOUSE_TRACE
	if (MouseTrace != (FILE*)0) {
		fclose(MouseTrace);
		MouseTrace = (FILE*) 0;
		}
#endif
	return (Ret);
#else
	return(0);
#endif
}

INTERFACE 	WORD 	local_x_graph(opid,buffer)
		WORD opid;
		VOID * buffer;
{
	return(56);
}

#ifdef	_CICO_MIMO
static	WORD	_mi_lecture()
{
	WORD	c;
	if (!(	c = (WORD)*(turn_lec++) )) {
		if ( is_cico_mouse_event ) {
			c = 256;	
			is_cico_mouse_event=0;
			}
		}
	else	cico_key_event( c );
	return(c);
}
#endif		
INTERFACE 	WORD 	local_x_getch()
{

	WORD c;

#ifdef	_GETCH_ESC_Q
	while (1) {
#endif

#ifdef IMPLOC
		terminate_local_lo();
#endif /*IMPLOC*/

		if (turn_lec == turn_ecr) {

#ifdef _DELAY
			if ( _delay == FALSE ) {
				delay_on();
				_delay = TRUE;
				}
#endif
			_ci_lecture(TRUE);
			}	

/* IJM 05/04/2002 : Extension USEIT for MIMO / MOUSE */
/* ------------------------------------------------- */
#ifdef	_CICO_MIMO
		c = _mi_lecture();
#else	
		c = (WORD)*turn_lec++;
#endif
	
		if (turn_lec == turn_fin)
			turn_lec = turn_buf;
#ifdef	_GETCH_ESC_Q
		if (!( getch_esc_q(c) ))
			return( c );
		else if (!( _co_esc_Q() ))
			return( c );
		else	continue;
		}
#else
		return( c );
#endif
}



/* test si un caractere est disponible dans le buffer clavier
 * ----------------------------------------------------------
 *
 * appel:	rien
 *
 * retour:	0 si rien en entree
 *
 */

INTERFACE	WORD 	local_x_kbhit()
{


#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/
	if (turn_lec == turn_ecr) {
#ifdef _DELAY
		if ( _delay == TRUE ) {
			_delay = FALSE;
			delay_off();
			}
#endif
		_ci_lecture(FALSE);
		}

	if (turn_lec != turn_ecr) {
		if ( *turn_lec != 0 )
			cico_key_event( *turn_lec );
		return (1);
		}
	else	{
		return (0);
		}
}


/*************************************************************************
 *									 *
 *		Primitives internes de la gestion du clavier		 *
 *									 *
 *************************************************************************/

/*#BG 24/03/11*/
#include "ixutf8.c"

#include "ixci.c"


#ifdef	_CICO_MIMO
static	int 	_mimo_detect()
{
	int	values[3];
	int	i;
	int	bs;
//#BG 07/07/17	char buffer[8];
	unsigned char buffer[8];

#ifdef	_MOUSE_TRACE
	if (MouseTrace == (FILE*)0)
		MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
	fprintf(MouseTrace,"ixcico.c 2: mimo_detect() \r\n");	
	fclose(MouseTrace);
	MouseTrace = (FILE*) 0;
#endif
	for (i=0; i < 3; i++ ) values [i] = 0;

	for (i=0; i < 3; i++ ) {
		if ( _read_buf(buffer+i,1,0) == -1 )
			break;
		else
			//#BG 07/07/17 So the maximum value for CicoMimo.textcol is 255-32=223 !
			values[i] = ((buffer[i] & 0x00FF)-0x0020);
		}

#ifdef	_MOUSE_TRACE
	if (MouseTrace == (FILE*)0)
		MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
	fprintf(MouseTrace,"ixcico.c 3: => Count=%u Read: %x %x %x\r\n", i, buffer[0], buffer[1] ,buffer[2]);	
	fclose(MouseTrace);
	MouseTrace = (FILE*) 0;
#endif

	if ( i > 0 ) {
		values[0] &= CicoMimo.limit; /* Was 3; limit to useful button information */
		values[0]++;
		
		/* #BG 18/03/13 */
		if (values[0] == _X_BUTTON_OFF)
		/* # (0x23) is received both for button up and moving button up
		 * (so values[0] = 0x23 - 0x20 + 1 = 4 = _X_BUTTON_OFF)
		 */ 
			if (CicoMimo.type != _MIMO_DOWN)
				/* Case of moving button up */
				if ((CicoMimo.mask & _MIMO_MOVE))
					/* Moving accepted by the mask specified by EVENT(0) = mask */
					values[0]++; /* _X_MOVING */
			
		CicoMimo.textlin=CicoMimo.y=values[2];
		CicoMimo.textcol=CicoMimo.x=values[1];

#ifdef	_MOUSE_TRACE
		if (MouseTrace == (FILE*)0)
			MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
		fprintf(MouseTrace,"ixcico.c 4: => event(%u,%u,%u) buttons = %u : mask : %x \r\n",values[0],values[1],values[2],CicoMimo.buttons,CicoMimo.mask);
		fclose(MouseTrace);
		MouseTrace = (FILE*) 0;
#endif

		switch ( values[0] ) {

			case	_X_BUTTON_1	:
				/* Left goes down */
#ifdef	_MOUSE_TRACE
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace,"               Button 1 (left) down\r\n");	
				fclose(MouseTrace);
				MouseTrace = (FILE*) 0;
#endif
				if (!( CicoMimo.mask & _MIMO_SEND_LEFT ))
					return(0);
				else	{
					CicoMimo.param = CicoMimo.buttons = _MIMO_LEFT;
					if ( CicoMimo.mask & _MIMO_DOWN )
						CicoMimo.type = _MIMO_DOWN;
					else	return(0);
					}
				break;	

			case	_X_BUTTON_2	:		
				/* Middle goes down */
				/* #BG 18/03/13 Button 2 is middle button with Post terminal protocol instead right before */
#ifdef	_MOUSE_TRACE
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace,"               Button 2 (middle) down\r\n");	
				fclose(MouseTrace);
				MouseTrace = (FILE*) 0;
#endif
				if (!( CicoMimo.mask & _MIMO_SEND_MIDDLE ))
					return(0);
				else	{
					CicoMimo.param = CicoMimo.buttons = _MIMO_MIDDLE;
					if ( CicoMimo.mask & _MIMO_DOWN )
						CicoMimo.type = _MIMO_DOWN;
					else	return(0);
					}
				break;

			case	_X_BUTTON_3	:
				/* Right goes down */
				/* #BG 18/03/13 Button 3 is right button with Post terminal protocol instead middle before */
#ifdef	_MOUSE_TRACE
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace,"               Button 3 (right) down\r\n");	
				fclose(MouseTrace);
				MouseTrace = (FILE*) 0;
#endif
				if (!( CicoMimo.mask & _MIMO_SEND_RIGHT ))
					return(0);
				else	{
					CicoMimo.param = CicoMimo.buttons = _MIMO_RIGHT;
					if ( CicoMimo.mask & _MIMO_DOWN )
						CicoMimo.type = _MIMO_DOWN;
					else	return(0);
					}
				break;

			case	_X_BUTTON_OFF	:
#ifdef	_MOUSE_TRACE
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace,"               Button up\r\n");	
				fclose(MouseTrace);
				MouseTrace = (FILE*) 0;
#endif
				if (!( CicoMimo.param = CicoMimo.buttons ))
					return(0);
				else	{
					CicoMimo.buttons=0;
					if ( CicoMimo.mask & _MIMO_UP )
						CicoMimo.type = _MIMO_UP;
					else if (!( CicoMimo.mask & _MIMO_CLICK ))
						return(0);
					else 	CicoMimo.type = _MIMO_CLICK;
					}
				break;

			case	_X_MOVING	:
#ifdef	_MOUSE_TRACE
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace,"               Moving\r\n");	
				fclose(MouseTrace);
				MouseTrace = (FILE*) 0;
#endif
				if (!( CicoMimo.param = CicoMimo.buttons )) {
					if (!( CicoMimo.mask & _MIMO_MOVE ))
						return(0);
					else
						CicoMimo.type = _MIMO_MOVE;
					}
				else if (!( CicoMimo.mask & _MIMO_WHILE_DOWN ))
					return(0);
				else
					CicoMimo.type = _MIMO_WHILE_DOWN;
				break;

			default				:
				return(0);
			}

		/* ------------------------------ */
		/* All legal events arrive here ! */
		/* (filtered out events will have */
		/* returned zero already)	  */
		/* ------------------------------ */
		is_cico_mouse_event=1;
		*turn_ecr++ = 0;
		if (turn_ecr == turn_fin)
			turn_ecr = turn_buf;

		}
	return(is_cico_mouse_event);
}
#endif

/* lecture effective d'un caractere
 * --------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
static 	VOID 	_ci_lecture(delay)
	BOOL 	delay;
{
	int		rbr;
	register 	i, j;
	int 		longueur;
	BYTE 		car;
	BOOL 		scanned;
	BYTE 	*	bp;
	int 		DRAP=0;
#ifdef	_CICO_MIMO
	char *	mimoptr;
	int	mimolen=0;
	if ((mimoptr=CicoMimo.detect) != (char*)0)  
		mimolen = strlen(mimoptr);
	else	mimolen = 0;
	is_cico_mouse_event=0;
#endif

#ifndef _DELAY
	if (delay == FALSE) {
		delay_off();
		}
#endif
	in_nb = 0;
	i = SCAN_FIRST;
#ifdef vms
	scanned = FALSE;
	while (vms$read(scanned, in_buf + in_nb, 1) > 0) {
#else
	while ((rbr = _read_buf(in_buf + in_nb, in_nb, utf8_flag )) > 0) { /*(NEWTEMPO)*/
#endif /* vms */
test:
		in_nb++;
		if ( in_nb >= 128 ) {
			/* whoops this is really no possible  */
			/* it causes severe memory corruption */
			/* ---------------------------------- */
			if (delay == FALSE) {
				turn_lec = turn_ecr;
				return;
				}
			else	{
				in_nb=0;
				continue;
				}
			}
			
		scanned = FALSE;
#ifdef	_CICO_MIMO
		if (( mimoptr != (char *) 0 ) 
		&&  ( mimolen != 0 )) {
			
			for ( j=0; j < mimolen; j++ ) {
				if ( j < in_nb ) {
					if ( *(in_buf+j) != *(mimoptr+j) )
						break;
					}
				else	break;
				}
				
			if ( j == mimolen ) {
				switch ( _mimo_detect() ) {
					case	1 :	
#ifdef	_MOUSE_TRACE
						if (MouseTrace == (FILE*)0)
							MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
						fprintf(MouseTrace,"ixcico.c 5: mimo_detect() : YES \r\n");
						fclose(MouseTrace);
						MouseTrace = (FILE*) 0;
#endif
#ifndef _DELAY
						delay_on(); 
#endif
						return;

					default	:	

#ifdef	_MOUSE_TRACE
						if (MouseTrace == (FILE*)0)
							MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
						fprintf(MouseTrace,"ixcico.c 6: mimo_detect() : NO \r\n");
						fclose(MouseTrace);
						MouseTrace = (FILE*) 0;
#endif
						in_nb = 0;
						i = SCAN_FIRST;
						scanned = FALSE;
						DRAP = 0;
#ifndef _DELAY
						if ( delay == TRUE )
							delay_on(); 
#endif
						continue;
					}
				}
			}
#endif
		while (i < SCAN_FIRST + SCAN_NB) {
			if ((*in_buf == **(term_str + i))
			&&  ( strncmp(in_buf, *(term_str + i), in_nb) == 0)) {
				scanned = TRUE;
				break;
				}
			i++;
			}
		
		if (scanned == TRUE) {
			DRAP=1;
			if (in_nb == strlen(*(term_str + i))) { /* egalite */
				if (i >= PKEY_FIRST) {
					i -= PKEY_FIRST;
					memcpy(in_buf, pkey[i].str, pkey[i].lg);
					in_nb = pkey[i].lg;
					} 
				else if (i >= NKEY_FIRST) {
					i -= NKEY_FIRST;
					bp = term_str[i + NKEY_STR_FIRST];
					longueur = strlen(bp);
					if (longueur > 0) {
						strcpy(in_buf, bp);
						in_nb = strlen(bp);
						} 
					else 	{
						bp = term_str[i + NKEY_FIRST];
						in_nb -= strlen(bp);
						if (delay == TRUE) {
							delay_on();
							i = SCAN_FIRST;
							continue;
							}
						}
					} 
				else 	{
					DRAP=0;
					i -= ACC_FIRST;
					if (accent == NO_ACCENT) {
						accent = i;
						bp = term_str[i + ACC_FIRST];
						in_nb -= strlen(bp);
						if (delay == TRUE)
							continue;
						}
					scanned = FALSE;
					}
				break;
				} 
			else 	{	/* inclusion */
				delay_off();
/*(NEWTEMPO):suppression de la boucle de temporisation sous UNIX */
				continue;
				}
			} 
		else
			break;		/* non egalite */
		}	/* while */

	if (scanned == TRUE) {
		for (i = 0; i < in_nb; i++) {
			*turn_ecr++ = *(in_buf + i);
			if (turn_ecr == turn_fin)
				turn_ecr = turn_buf;
			}
		} 
	else 	{
		if ( DRAP == 0 )  
			in_nb++;
		
		for (i = 0; i < in_nb-1; i++) {
			if (accent != NO_ACCENT) {
				car = tab_in[*(in_buf + i)];
				if ((bp = (BYTE *)strchr(acc[accent].istr, car)) != NULL)
					*turn_ecr++ = acc[accent].ostr[bp - acc[accent].istr];
				else	*turn_ecr++ = car;
				accent = NO_ACCENT;
				} 
			else {
					*turn_ecr++ = tab_in[*(in_buf + i)];
/* #BG 24/03/11 Test inutile si tab_in du fichier CICO est transparente
					if (tab_in[*(in_buf + i)])
						*turn_ecr++ = tab_in[*(in_buf + i)];
					else
						*turn_ecr++ = *(in_buf + i);
*/
				}
			if (turn_ecr == turn_fin)
				turn_ecr = turn_buf;
			}
			
		if (DRAP != 0) {
			*in_buf= (BYTE) *(in_buf+in_nb-1);
 			in_nb=0;
			i = SCAN_FIRST;
			DRAP=0;
			goto test;
			}
		}
#ifndef _DELAY
	delay_on(); 
#endif
}



/****************************************************************
 *								*
 *	Programmation des touches de fonctions			*
 *								*
 ****************************************************************/


/* ecriture d'une touche programmable
 * ----------------------------------
 *
 * appel:	numero de fonction a programmer
 *		pointeur sur la chaine a associer
 *		longueur de la chaine
 *
 * retour:	0 si OK
 *		-1 en cas d'erreur, err_val contient le code erreur
 *
 */
INTERFACE	WORD 	local_x_prfo(numero,chaine,longueur)
		WORD 	numero;
		BYTE 	*chaine;
		WORD 	longueur;
{
	register i;
#if defined(AVIION) || defined(UNIXWARE) || defined(LINUX)
	int j;
 	int lg ;
    lg = longueur;
#endif


#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/

	for (i = 0; i < PKEY_NB + PKEY_F_NB; i++) {
		if (pkey[i].code == (BYTE)numero && pkey[i].act == TRUE) {
			if (longueur > 0) {
				if (longueur > pkey[i].max)
					longueur = pkey[i].max;
#if defined(AVIION) || defined(UNIXWARE) || defined(LINUX)
    			for (j=0;j<longueur;++j)
      			 pkey[i].str[j] = chaine[j];
        			pkey[i].lg = longueur;
#else
				strncpy(pkey[i].str, chaine, longueur);
				pkey[i].lg = longueur;
#endif
			}
			return (0);
		}
	}
	err_val = 56;
	return (-1);
}

#ifdef CPYFO
#ifndef ASFCICO				/* CPYFO */
/* recopie des touches du cico dans asfun
 * --------------------------------------
 *
 * appel:	
 *		
 *		
 *
 * retour:	0 si OK
 *		-1 en cas d'erreur, err_val contient le code erreur
 *
 */
 WORD cpyfo()
{
	register i;
        WORD numero;
        BYTE chaine[128];
        WORD longueur;

	BYTE type[3];
	VOID *argument[3];
	WORD taille[3];

#ifdef CICO_BDA
	if (redir_CI == TRUE)
         {
	   type[0] = TYPE_WORD;
	   type[1] = TYPE_CHAINE;
	   type[2] = TYPE_WORD;
	   taille[0] = 2;
	   taille[2] = 2;

	   argument[0] = (VOID *)&numero;
	   argument[1] = (VOID *)chaine;
	   argument[2] = (VOID *)&longueur;

#ifdef CICO_DEBUG
   	   fprintf(DEBUG,"CallRunTime(CICO_PRFO):%d\n",taille[1]);
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/

	   for (i = 0; i < PKEY_NB + PKEY_F_NB; i++)
             {
		if ( (pkey[i].act == TRUE) && (pkey[i].lg > 0) )
                 {
                        numero = pkey[i].code;
                        longueur =pkey[i].lg;
			strncpy(chaine, pkey[i].str, longueur);
 			taille[1] = strlen(chaine);
			CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_PRFO],
				    3, type, argument, taille);
		 }
	     };

	}		/* fin si redir_CI = TRUE */
#endif /* fin CICO_BDA */

return(0);
}
#endif		/* NOT ASFCICO */
#endif		/* CPYFO */


/* lecture d'une touche programmable
 * ---------------------------------
 *
 * appel:	numero de fonction a lire
 *		pointeur sur la chaine de reception
 *		longueur de la chaine
 *
 * retour:	0 si OK
 *		-1 en cas d'erreur, err_val contient le code erreur
 *
 */
INTERFACE	WORD 	local_x_lcfo(numero,chaine,longueur)
		WORD numero;
		BYTE *chaine;
		WORD longueur;
{
	register i;

#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/

	for (i = 0; i < PKEY_NB + PKEY_F_NB; i++) {
		if (pkey[i].code == (BYTE)numero && pkey[i].act == TRUE) {
			if (longueur > 0) {
				if (longueur > pkey[i].lg)
					longueur = pkey[i].lg;
				strncpy(chaine, pkey[i].str, longueur);
				if (longueur < pkey[i].lg) {
					err_val = 63;
					return (-1);
				}
			}
			return (0);
		}
	}
	err_val = 56;
	return (-1);
}


/************************************************************************
 *									*
 *	Primitives de gestion des affichages / editions 		*
 *									*
 ***********************************************************************/


/* edition d'un caractere
 * ----------------------
 *
 * appel:	le caractere a editer
 *
 * retour:	rien
 *
 */
#if	EXABAL && !MPAGE
extern	WORD	sicico;
extern	WORD	prnflag;
#endif

INTERFACE	WORD	local_x_putch(c)
WORD c;
{

	if (prndest == ECRAN)
		{
		_co(c);
		}
	else 	{
		if (prndest == TAMPON)
			{
			if (prnleng > 0) 
				{
				*prnptr++ = (BYTE)c;
				prnleng--;
				} 
			}
	
		else	{
#if	EXABAL && !MPAGE
			prnflag =sicico;
#endif
			_lo(c);
			}
			
		}

	return(0);
}


/* Affichage d'une chaine sur le peripherique courant
 * --------------------------------------------------
 *
 * appel:	pointeur sur la chaine
 *
 * retour:	rien
 *
 */
 
INTERFACE	WORD 	local_x_cprintf(chaine)
BYTE *chaine;
{

	if (flag_buf == FALSE)
		{
		x_bstart();
		while (*chaine != 0x00) 
			{
			x_putch(*(chaine++));
			}
		x_bflush();
		}
	else	{
		while (*chaine != 0x00)
			{
			x_putch(*(chaine++));
			}
		}
	return(0);
}


/* vidage du buffer de sortie
 * --------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
INTERFACE	WORD 	local_x_bflush()
{

	if ( prndest == ECRAN )
		_co_flush();
#ifdef	EXABAL
	else	_lo_flush();
#endif
	return(0);
}


/* passage en mode bufferise
 * -------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
INTERFACE	WORD	local_x_bstart()
{
	if ( prndest == ECRAN )
		_co_start();
#ifdef	EXABAL
	else	_lo_start();
#endif
	return(0);
}


/* positionnement absolu en ligne et colonne
 * -----------------------------------------
 *
 * appel:	ligne et colonne (a partir de 1)
 *
 * retour:	rien
 *
 */
VOID pos(ligne, colonne)
WORD ligne;
WORD colonne;
{
	register i;

	if (ligne == 0)
		ligne++;
	if (colonne == 0)
		colonne++;
	if (prndest == ECRAN) { 		/* ecran */
		x_putch(ESC);
		x_putch('f');
		x_putch(colonne + 0x001f);
		x_putch(ligne + 0x001f);
		} 
#ifdef	EXABAL
	else if (prndest != TAMPON) { 	/* imprimante */
		im_pos( prnfid, ligne, colonne );
		}
#endif
	return;
}


/* selection d'un attribut d'affichage
 * -----------------------------------
 *
 * appel:	le numero de l'attribut choisi
 *
 * retour:	rien
 *
 */
VOID atb(attribut)
WORD attribut;
{
	switch (attribut) {
	case 0: 		/* visualisation normale */
		attribut = 'a';
		break;
	case 1: 		/* attribut preferentiel */
		attribut = 'p';
		break;
	case 2: 		/* inversion video */
		attribut = 'b';
		break;
	case 3: 		/* clignotement */
		attribut = 'c';
		break;
	case 4: 		/* soulignement */
		attribut = 'd';
		break;
	case 5: 		/* sous-brillance */
		attribut = 'e';
		break;
	case 6: 		/* sur-brillance */
		attribut = 'h';
		break;
	case 7: 		/* lettres forcees majuscules */
		attribut = 'i';
		break;
	case 8: 		/* lettres forcees minuscules */
		attribut = 'j';
		break;
	case 9: 		/* hard copy */
		attribut = 'O';
		break;
	case 10:		/* caracteres penches */
		attribut = 'y';
		break;
	case 11:		/* double largeur */
		attribut = 'z';
		break;
	case 12:
		attribut = 'k';
		break;
	case 13:
		attribut = 'l';
		break;
	case 14:
		attribut = 'm';
		break;
	case 15:
		attribut = 'n';
		break;
	case 16:
		attribut = 'q';
		break;
	case 17:
		attribut = 'r';
		break;
	case 18:
		attribut = 's';
		break;
	case 19:		/* double hauteur */
		attribut = 't';
		break;
	case 20:
		attribut = 'Q';
		break;
	case 21:		/* effacement fin de ligne */
		attribut = 'K';
		break;
	case 22:		/* effacement fin de page */
		attribut = 'J';
		break;
	case 23:		/* insertion de ligne */
		attribut = 'L';
		break;
	case 24:		/* suppression de ligne */
		attribut = 'M';
		break;
	case 25:		/* extinction curseur */
		attribut = 'w';
		break;
	case 26:		/* allumage curseur */
		attribut = 'v';
		break;
	case 27:
		attribut = '*';
		break;
	case 28:
		attribut = '#';
		break;
	case 29:		/* caracteres compactes */
		attribut = 'x';
		break;
	case 30:		/* indice ou push ecran */
/* DLR:18/02/93 */
		attribut = '>';
		break;
	case 31:		/* exposant ou pop ecran */
/* DLR:18/02/93 */
		attribut = '<';
		break;
	case 32 :
		attribut = 'u';
		break;

	default:
		return;
	}
	x_putch(ESC);
	x_putch(attribut);
}


/* selection de la couleur de fond
 * -------------------------------
 *
 * appel:	le numero de couleur
 *
 * retour:	rien
 *
 */
VOID backgr(couleur)
WORD couleur;
{
/* 04/07/2003 : enfin */

	if (couleur <= 9) {
		x_putch(ESC);
		x_putch('s');
		x_putch(couleur + '0');
		}
	else if ((couleur >= 10) && (couleur <= 15)) {
		x_putch(ESC);
		x_putch('s');
		x_putch(couleur - 10 + 'A');
		}
/* -------- */
/* 02/04/93 */
/* -------- */
/*
 *	couleur &= 0x0007;
 *	if ( couleur <= 7) {
 *		x_putch(ESC);
 *		x_putch('s');
 *		x_putch(couleur + '0');
 *		}
 */

}


/* selection de la couleur du texte
 * --------------------------------
 *
 * appel:	le numero de la couleur
 *
 * retour:	rien
 *
 */
VOID foregr(couleur)
WORD couleur;
{
	if (couleur <= 9) {
		x_putch(ESC);
		x_putch('r');
		x_putch(couleur + '0');
		}
	else if ((couleur >= 10) && (couleur <= 15)) {
		x_putch(ESC);
		x_putch('r');
		x_putch(couleur - 10 + 'A');
		}
}


/* effacement d'ecran / saut de page imprimante
 * --------------------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_clear()
{
	BYTE b;
	WORD w;


	switch (prndest) {
	case TAMPON:
		break;
	case ECRAN:
		lcfo(6, &b, 1);
		w = b;
		x_putch(w);
		break;
	default:
		x_putch(FF);
	}
}


/* sonnerie
 * --------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_bell()
{
	x_putch(BEL);
}


/* position colonne sur le peripherique courant
 * --------------------------------------------
 *
 * appel:	rien
 *
 * retour:	la position
 *
 */
INTERFACE	WORD 	local_x_col()
{
	if (prndest == ECRAN)
		return (_co_colonne() + 1);
#ifdef	EXABAL
	else if ( prndest != TAMPON ) {
		return( im_col(prnfid) );
		}
#endif
	else	return(0);
}

	
/* position ligne sur le peripherique courant
 * ------------------------------------------
 *
 * appel:	rien
 *
 * retour:	la position
 *
 */
INTERFACE	WORD 	local_x_lin()
{

#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_LIN\n");
#endif /* fin CICO_DEBUG */

	if (prndest == ECRAN)
		return (_co_ligne() + 1);
#ifdef	EXABAL
	else if ( prndest != TAMPON ) 
		return( im_lin(prnfid) );
#endif
	else	return( 0 );
}

/* conversion minuscule/majuscule
 * ------------------------------
 *
 * appel:	caractere a convertir
 *		0 si conversion en majuscule, 1 pour conversion en minuscule
 *
 * retour:	caractere converti
 *
 */
INTERFACE	WORD 	local_x_mima(c,conv)
WORD c;
WORD conv;

{
	return( ix_case_conversion( c, conv ) );
}

/*	Gestion des imprimantes 	*/
/*	-----------------------		*/
#ifdef	EXABAL
#ifndef	LIBPRINT
#include "ixim.c"
#endif
#endif

/************************************************************************
 *									*
 *	Primitives internes de gestion ecran				*
 *									*
 ***********************************************************************/

/* edition d'un chaine sur ecran
 * -----------------------------
 *
 * appel:	caractere a editer
 *
 * retour:	rien
 *
 */
VOID _co_chaine(chaine, longueur)
BYTE *chaine;
WORD longueur;
{
	while (longueur--)
		_co(*(chaine++));
}


/* edition d'un caractere sur ecran
 * --------------------------------
 *
 * appel:	caractere a editer
 *
 * retour:	rien
 *
 */

VOID	esc_Z(v)
int v;
{
#ifdef	_CICO_MIMO
	if (!( v & (_MIMO_BUTTONS) ))
		v |= _MIMO_SEND_LEFT;
#ifdef	EXABAL
	set_mimo_mask((CicoMimo.mask = v ));
#ifdef	_MOUSE_TRACE
	if (MouseTrace == (FILE*)0)
		MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
	fprintf(MouseTrace,"ixcico.c 7: set_mimo_mask(%x)\r\n",CicoMimo.mask);
	fclose(MouseTrace);
	MouseTrace = (FILE*) 0;
#endif
#endif
#endif
	return;
}

/*	--------------------------	*/
/*	Set Foreground Colour to C	*/
/*	--------------------------	*/
static	void	cico_esc_r(c)
int c;
{
	_co_couleur_texte((courant->holdtext = courant->texte = c));
	return;
}

/*	--------------------------	*/
/*	Set BackGround Colour to C	*/
/*	--------------------------	*/
static	void	cico_esc_s(c)
int c;
{
	_co_couleur_fond((courant->holdfond = courant->fond = c));
	return;
}

/*	--------------------------	*/
/*	Set Screen     Colour to C	*/
/*	--------------------------	*/
static	void	cico_esc_n(c)
int c;
{
#ifdef ABALCONF
	_co_couleur_texte(courant->texte);
	_co_couleur_fond((courant->def_back = c));
#else
	_co_couleur_texte(courant->texte = courant->defaut = c );
#endif /* ABALCONF */
	return;
}

/*	--------------------------	*/
/*	Set Screen     Colour to C	*/
/*	--------------------------	*/
static	void	cico_esc_q(c)
int c;
{
#ifdef ABALCONF
	_co_couleur_texte(courant->texte);
	_co_couleur_fond((courant->def_back = c));
#else
	_co_couleur_texte(courant->texte = courant->defaut = c );
#endif /* ABALCONF */
	C_BACK = c;
	return;
}

/*	------------------------------------------	*/
/*	Clear Atributs : Set Colours to last Paint	*/
/*	------------------------------------------	*/
static	void	cico_esc_a()
{
	_co_capacite(EXIT_ATTRIBUTE);
	courant->attribut = A_NORMAL;
	courant->jeu = NO_CASE;
	if (flag_couleur == TRUE) 
		_co_set_attribut();
	else	_co_attribut(courant->attribut = A_NORMAL);
	_co_couleur_texte((courant->texte = C_FORE));
	_co_couleur_fond((courant->fond=C_BACK));
	return;
}

/*	---------------------------------------------	*/
/*	Inverse Video  : Set Colours to Inverse Paint	*/
/*	---------------------------------------------	*/
static	void	cico_esc_b()
{
	int	c;
	c = courant->fond;
	if ((courant->fond = courant->texte) > 7) courant->fond &= 7;
	courant->texte= c;
	courant->attribut = A_REVERSE;
	if (flag_couleur == TRUE) 
		_co_set_attribut();
	else	_co_attribut(courant->attribut);
	return;
}



#ifdef	EXABAL
#else
#define	terminate_local_lo()
#endif

#ifdef	_USEIT_FOR_WHATEVER
VOID	_co_page(mode)
int mode;
{
	char	*	cptr;
	if ( mode == FALSE ) {
		flag_scroll = TRUE;
		if (((cptr = ENTER_PAGE) != (char *) 0)
		&&   (*cptr != 0 ))
			_co_capacite(cptr);
		}		
	else	{
		flag_scroll = FALSE;
		if (((cptr = EXIT_PAGE) != (char *) 0)
		&&   (*cptr != 0 ))
			_co_capacite(cptr);
		}		
	return;
}
#endif


VOID _co(c)
WORD c;
{
	register i, j;
	static WORD nb_transparent;
	WORD old_prnfid;
	char cc=c;

#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/

/* XCICO actif */
	if ( XCICO_nbl != 0 ) {
#ifdef UNIXWARE
	sighold(SIGALRM);
#endif
	

	(void) cosyswrite(STDOUT, &cc, 1);
#ifdef UNIXWARE
	sigrelse(SIGALRM);
#endif

	}
/***************/
	switch (courant->etat) {
	case ETAT_STANDARD:
		if (c >= ' ' && c <= 0x7f) {            /* caractere ASCII */
			_co_car(c);
		} else if (c == ESC) {			/* debut seq. escape */
			courant->etat = ETAT_ESCAPE;
		} else if (c == PRL_RIGHT) {		/* curseur droit */
			if (courant->colonne == max_colonne) {
				courant->colonne = 0;
				if (courant->ligne == max_ligne)
					courant->ligne = 0;
				else
					courant->ligne++;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->colonne++;
				_co_capacite(CURSOR_RIGHT);
			}
		} else if (c == PRL_LEFT) {		/* curseur gauche */
			if (courant->colonne == 0) {
				courant->colonne = max_colonne;
				if (courant->ligne == 0)
					courant->ligne = max_ligne;
				else
					courant->ligne--;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->colonne--;
				_co_capacite(CURSOR_LEFT);
			}
		} else if (c == PRL_UP) {		/* curseur haut */
			if (courant->ligne == 0) {
				courant->ligne = max_ligne;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->ligne--;
				_co_capacite(CURSOR_UP);
			}
		} else if (c == PRL_DOWN) {		/* curseur bas */
			if (courant->ligne == max_ligne) {
				courant->ligne = 0;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->ligne++;
				_co_capacite(CURSOR_DOWN);
			}
		} else if (c == PRL_HOME) {		/* home */
			courant->ligne = courant->colonne = 0;
			_co_pos(courant->ligne, courant->colonne);
		} else if (c == PRL_CLEAR) {		/* clear */
			courant->ligne = courant->colonne = 0;
			_co_clear();
		} else if (c == CR) {			/* carriage return */
			courant->colonne = 0;
			_co_out(CR);
		} else if (c == LF) {			/* line feed */
			if (flag_scroll == TRUE) {
				if (courant->ligne == max_ligne)
					_co_scroll();
				else
					courant->ligne++;
/* 29/10/92:DLR */
				if ( flag_couleur == FALSE ) {	
					_co_reset_attribut();
					_co_out(LF);
					_co_set_attribut();
				} else {
					if (courant->ligne == max_ligne) {
#ifdef SOL1
						int offset;
						/* couleur caractere suivant */
						offset = courant->ligne * nb_colonne + courant->colonne;
						_co_couleur_texte(*(courant->image.texte + offset));
						_co_couleur_fond(*(courant->image.fond + offset));
						_co_out(LF);
						/* couleur caractere courant */
						_co_couleur_texte(courant->texte);
						_co_couleur_fond(courant->fond);
#else
						/* couleur noire de fond */
#ifdef ABALCONF
						_co_couleur_fond(courant->def_back);
#else
						_co_couleur_fond(C_BACK);
#endif /* ABALCONF */
						_co_out(LF);
						/* couleur caractere courant */
						_co_couleur_fond(courant->fond);
#endif /* SOL1 */
					} else {
						_co_out(LF);
					}
				} 
/* 29/10/92:DLR */
			} else {
				if (courant->ligne == max_ligne)
					courant->ligne = 0;
				else
					courant->ligne++;
				_co_pos(courant->ligne, courant->colonne);
			}
		} else if (c == HT) {			/* horizontal tab */
			courant->colonne = (courant->colonne / 8 + 1) * 8;
			if (flag_scroll == TRUE) {
				if (courant->colonne > max_colonne) {
					courant->colonne -= nb_colonne;
					if (courant->ligne == max_ligne) {
/* 29/10/92:DLR */
						if ( flag_couleur == TRUE ) {
#ifdef SOL1
							int offset;
							/* couleur caractere suivant */
							offset = courant->ligne * nb_colonne + courant->colonne;
							_co_couleur_texte(*(courant->image.texte + offset));
							_co_couleur_fond(*(courant->image.fond + offset));
							_co_out(LF);
							/* couleur caractere courant */
							_co_couleur_texte(courant->texte);
							_co_couleur_fond(courant->fond);
#else
#ifdef ABALCONF
							_co_couleur_fond(courant->def_back);
#else
							/* couleur noire de fond */
							_co_couleur_fond(C_BACK);
#endif /* ABALCONF */
							_co_out(LF);
							/* couleur caractere courant */
							_co_couleur_fond(courant->fond);
#endif /* SOL1 */
						} else {
							_co_reset_attribut();
							_co_out(LF);
							_co_set_attribut();
						}
/* 29/10/92:DLR */
						_co_scroll();
					} else
						courant->ligne++;
				}
			} else {
				if (courant->colonne > max_colonne) {
					courant->colonne -= nb_colonne;
					if (courant->ligne == max_ligne)
						courant->ligne = 0;
					else
						courant->ligne++;
				}
			}
			_co_pos(courant->ligne, courant->colonne);
	} else if (c == BEL) {			/* bell */
			_co_out(BEL);
		} else if (c > ' ') {
			_co_car(c);
		}
		break; /* de ETAT_STANDARD */
	case ETAT_POS_1:
		courant->etat = ETAT_POS_2;
		if ((BYTE)c != 0xff) {
			courant->colonne = c - 0x20;
			if (courant->colonne > max_colonne)
				courant->colonne = max_colonne;
		}
		break;
	case ETAT_POS_2:
		courant->etat = ETAT_STANDARD;
		if ((BYTE)c != 0xff) {
			courant->ligne = c - 0x20;
			if (courant->ligne > max_ligne)
				courant->ligne = max_ligne;
		}
		_co_pos(courant->ligne, courant->colonne);
		break;
	case ETAT_ESCAPE:
		courant->etat = ETAT_STANDARD;
		switch (c) {
		case ESC:
			courant->etat = ETAT_ESCAPE_ESCAPE;
			break;
		case 'Z':
			courant->etat = ETAT_Z_1;
			break;
		case 'f':               /* positionnement curseur */
			courant->etat = ETAT_POS_1;
			break;
		case 'T':               /* mode transparent */
			courant->etat = ETAT_TRANS_1;
			break;
		case 'n':               /* couleur defaut */
			courant->etat = ETAT_DEFAUT;
			break;
		case 'q':               /* couleur defaut */
			courant->etat = ETAT_QUICK;
			break;
		case 'r':               /* couleur caractere */
			courant->etat = ETAT_TEXTE;
			break;

		case '(':               /* couleur fond */
			courant->etat = ETAT_VISUAL;
			break;

		case 's':               /* couleur fond */
			courant->etat = ETAT_FOND;
			break;
		case 'a':               /* visualisation normale */
			cico_esc_a();
			break;

		case 'b':               /* inversion video */
			cico_esc_b();
			break;
		case 'c':               /* clignotement */
			_co_attribut(courant->attribut = A_BLINK);
			break;
		case 'd':               /* soulignement  */
			_co_attribut(courant->attribut = A_UNDERLINE);
			break;
		case 'e':               /* sous_brillance */
			_co_attribut(courant->attribut = A_DIM);
			break;
		case 'h':               /* sur_brillance */
			_co_attribut(courant->attribut = A_BOLD);
			break;
		case 'i':               /* transcodage min/MAJ */
			courant->jeu = UPPER_CASE;
			break;
		case 'j':               /* transcodage MAJ/min */
			courant->jeu = LOWER_CASE;
			break;
		case 'p':               /* attribut preferentiel */
			_co_attribut(courant->attribut = A_STANDOUT);
			break;
		case 'J':               /* effacement fin de page */
			_co_clear_eos();
			break;
		case 'K':               /* effacement fin de ligne */
			_co_clear_eol();
			break;
		case 'L':               /* insertion de ligne */
			_co_ins_line();
			break;
		case 'M':               /* suppression de ligne */
			_co_del_line();
			break;
		case '@':               /* insertion caractere */
			_co_ins_character();
			break;
		case 'Q':		/* graphique */
		case 'O':               /* hard copy */
			if ( _co_esc_Q() )
				break;
#ifdef	EXABAL
			old_prnfid = prnfid;
			prnfid = 0;
#ifdef AIX_VERS
#ifdef SPARC
			for (i = 0; i < nombre_ligne; i++) {
#else
			for (i = 0; i < nb_ligne; i++) {
#endif
#else  /* AIX_VERS */
			for (i = 0; i < nb_ligne; i++) {
#endif /* AIX_VERS */
				for (j = 0; j < nb_colonne; j++)
					im_putch(prnfid, *(courant->image.caractere +
						  i * nb_colonne + j));
				im_putch(prnfid,CR);
				im_putch(prnfid,LF);
				}
			im_close(prnfid);
			prnfid = old_prnfid;
#endif
			break;
		case 'P':               /* suppression caractere */
			_co_del_character();
			break;
		case 'v':               /* allumage curseur */
			_co_cursor(TRUE);
			break;
		case 'w':               /* extinction curseur */
			_co_cursor(FALSE);
			break;
		case '>':               /* push ecran */
			_co_push();
			break;
		case '<':               /* pop ecran */
			_co_pop();
			break;
		case 'u':               /* mode page */
#ifdef	_USEIT_FOR_WHATEVER
			_co_page(TRUE);
#else
			flag_scroll = FALSE;
#endif
			break;
		case 't':               /* mode scroll */
#ifdef	_USEIT_FOR_WHATEVER
			_co_page(FALSE);
#else
			flag_scroll = TRUE;
#endif
			break;
		}
		break;		/* fin de ETAT_ESCAPE */

	case ETAT_Z_1:
		courant->etat = ETAT_Z_2;
		nb_transparent = (c & 0x00FF);
		break;

	case ETAT_Z_2:
		courant->etat = ETAT_STANDARD;
		nb_transparent |= ((c&0x00FF) << 8);
		esc_Z( nb_transparent );
		break;

	case ETAT_TRANS_1:
		courant->etat = ETAT_TRANS_2;
		nb_transparent = c;
		break;

	case ETAT_TRANS_2:
		courant->etat = ETAT_TRANS_3;
		nb_transparent += 256 * c;
		break;

	case ETAT_TRANS_3:
		_co_out(c);
		if (--nb_transparent == 0)
			courant->etat = ETAT_STANDARD;
		break;

	case ETAT_DEFAUT:
		if (flag_couleur == TRUE) {
			if (c >= '0' && c <= '9')
				cico_esc_n((c - '0'));
			else if (c >= 'A' && c <= 'F')
				cico_esc_n(((c - 'A')+10));

			}
		courant->etat = ETAT_STANDARD;
		break;

	case ETAT_QUICK:
		if (flag_couleur == TRUE) {
			if (c >= '0' && c <= '9')
				cico_esc_q((c - '0'));
			else if (c >= 'A' && c <= 'F')
				cico_esc_q(((c - 'A')+10));

			}
		courant->etat = ETAT_STANDARD;
		break;

	case ETAT_TEXTE:
		if (flag_couleur == TRUE) {
			if (c >= '0' && c <= '9')
				cico_esc_r( (c - '0') );
			else if (c >= 'A' && c <= 'F')
				cico_esc_r( ((c - 'A') + 10) );
			}
		courant->etat = ETAT_STANDARD;
		break;

	case ETAT_VISUAL :
		courant->etat = ETAT_STANDARD;
		break;

	case ETAT_FOND:
		if (flag_couleur == TRUE) {
			if (c >= '0' && c <= '9')
				cico_esc_s((c - '0'));	
			else if (c >= 'A' && c <= 'F')
				cico_esc_s(((c - 'A')+10));
			}
		courant->etat = ETAT_STANDARD;
		break;

	case ETAT_ESCAPE_ESCAPE:
		courant->etat = ETAT_STANDARD;
		break;
	}
}

	

/* ajout d'un caractere avec son attribut
 * --------------------------------------
 *
 * appel:	caractere
 *		attribut
 *		couleur
 *
 * retour:	rien
 *
 */
VOID _co_car(c)
WORD c;
{
	register offset;

	if (flag_scroll == TRUE) {

		/* Auto Lastline Scrolling is Active */
		/* --------------------------------- */
		if (courant->colonne == max_colonne) {

			/* Last column position reached */
			/* ---------------------------- */
			courant->colonne = 0;

			if (courant->ligne == max_ligne) {

				/* Last Line reached */
				/* ----------------- */
/* 29/10/92:DLR */
				if ( flag_couleur == TRUE ) {
#ifdef SOL1
					int offset;
					/* couleur caractere suivant */
					offset = courant->ligne * nb_colonne + courant->colonne;
					_co_couleur_texte(*(courant->image.texte + offset));
					_co_couleur_fond(*(courant->image.fond + offset));
					_co_out(LF);
					/* couleur caractere courant */
					_co_couleur_texte(courant->texte);
					_co_couleur_fond(courant->fond);
#else
#ifdef ABALCONF
					_co_couleur_fond(courant->def_back);
#else
					/* couleur noire de fond */
					_co_couleur_fond(C_BACK);
#endif /* ABALCONF */
					_co_out(LF);
					/* couleur caractere courant */
					_co_couleur_fond(courant->fond);
#endif /* SOL1 */
					} 
				else 	{
					_co_reset_attribut();
					_co_out(LF);
					_co_set_attribut();
					}
/* 29/10/92:DLR */
				_co_out(CR);
				_co_pos(courant->ligne - 1, max_colonne);
				c = _co_conv(c);
				_co_pos(courant->ligne, courant->colonne);
				_co_scroll();
				} 
			else 	{
				/* last line not reached */
				/* --------------------- */
				courant->ligne++;
				c = _co_conv(c);
				_co_pos(courant->ligne, courant->colonne);
				}
			}
		 else 	{
			courant->colonne++;
			c = _co_conv(c);
			}
		} 
	else 	{
		/* Asfun Page Mode is Active : No Lastline Scroll */
		/* ---------------------------------------------- */ 
		if (courant->colonne == max_colonne) {
			courant->colonne = 0;
			if (courant->ligne == max_ligne) {
				courant->ligne = 0;
				courant->colonne++;
				}
			else 	courant->ligne++;
			c = _co_conv(c);
			_co_pos(courant->ligne, courant->colonne);
			} 
		else	{
			courant->colonne++;
			c = _co_conv(c);
			}
		}

	/* ecriture dans l'image */
	offset = (((courant->ligne * nb_colonne) + courant->colonne)-1); /* this was -1 but bug in co_pop */ 
	/* needs conversion */
	*(courant->image.caractere + offset) = (BYTE)c;
	*(courant->image.attribut + offset) = courant->attribut;
	if (flag_couleur == TRUE) {
		*(courant->image.texte + offset) = courant->texte;
		*(courant->image.fond + offset) = courant->fond;
		}
}


/* affichage d'un caractere 8 bits
 * -------------------------------
 *
 * appel:	le caractere
 *
 * retour:	rien
 *
 */
WORD	_co_conv(c)
WORD c;
{
	BYTE *bp;

	c &= 0x00FF;

	if (courant->jeu != NO_CASE)
		c = mima(c, (WORD)courant->jeu);
	if (strchr(CHAR_SECOND, c) != NULL) {
		enter_second();
		} 
	else 	{
		exit_second();
		}
	if (tab_out[(unsigned)c] == 0) {
		bp = term_str[COMP_FIRST + (unsigned)c];
		while (*bp != '\0')
			_co_out(*bp++);
		}
	else	{
		_co_out(tab_out[(unsigned)c]);
		}
	return( c );
}


/* positionnement curseur
 * ----------------------
 *
 * appel:	ligne et colonne (origine en 0, 0)
 *
 * retour:	rien
 *
 */
VOID _co_pos(ligne, colonne)
WORD ligne;
WORD colonne;
{
	_co_capacite(CURSOR_ADR_BEG);
	_co_sequence(CURSOR_ADR_P1, ligne, colonne);
	_co_capacite(CURSOR_ADR_MID);
	_co_sequence(CURSOR_ADR_P2, ligne, colonne);
	_co_capacite(CURSOR_ADR_END);
}


/* allumage / extinction curseur
 * -----------------------------
 *
 * appel:	TRUE pour allumage
 *		FALSE pour extinction
 *
 * retour:	rien
 *
 */
VOID _co_cursor(flag)
BOOL flag;
{
	if (flag == TRUE) {
		flag_curseur = TRUE;
		_co_capacite(CURSOR_NORMAL);
	} else {
		flag_curseur = FALSE;
		_co_capacite(CURSOR_INVIS);
	}
}


/* reset des attributs et des couleurs
 * -----------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_reset_attribut()
{
	_co_capacite(EXIT_ATTRIBUTE);
	if (flag_couleur == TRUE)
#ifdef ABALCONF
		_co_couleur_fond(courant->def_back);
#else
		_co_capacite(BACKGR_0);
#endif /* ABALCONF */
}


/* reset des attributs et des couleurs
 * -----------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_set_attribut()
{
	if (flag_couleur == TRUE) {
		_co_couleur_texte(courant->texte);
		_co_couleur_fond(courant->fond);
		}
	else if (courant->attribut != A_NORMAL)
		_co_attribut(courant->attribut);

}


/* positionnement d'attribut
 * -------------------------
 *
 * appel:	numero d'attribut (numerotation BAL)
 *
 * retour:	rien
 *
 */
VOID _co_attribut(attribut)
WORD attribut;
{
	switch (attribut) {
	case A_NORMAL:
		_co_capacite(EXIT_ATTRIBUTE);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			_co_couleur_texte(courant->texte = courant->def_char);
			_co_couleur_fond(courant->fond = courant->def_back);
#else
			_co_couleur_texte(courant->texte = courant->defaut);
			_co_couleur_fond(courant->fond = C_BACK);
#endif /* ABALCONF */
		}
		break;
	case A_STANDOUT:
		if (flag_couleur == TRUE)
			_co_couleur_texte(courant->texte = C_YELLOW);
		else
			_co_capacite(ENTER_STANDOUT);
		break;
	case A_UNDERLINE:
		if (flag_couleur == TRUE)
			_co_couleur_texte(courant->texte = C_LIGHT_CYAN);
		else
			_co_capacite(ENTER_UNDERLINE);
		break;
	case A_REVERSE:
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			_co_couleur_texte(courant->texte = courant->def_back);
			_co_couleur_fond(courant->fond = courant->def_char);
#else
			_co_couleur_texte(courant->texte = C_BACK);
			_co_couleur_fond(courant->fond = courant->defaut);
#endif /* ABALCONF */
		} else
			_co_capacite(ENTER_REVERSE);
		break;
	case A_BLINK:
		_co_capacite(ENTER_BLINK);
		break;
	case A_BOLD:
		if (flag_couleur == TRUE) {
			if (courant->texte < C_GREY)
				_co_couleur_texte(courant->texte += C_GREY);
		} else
			_co_capacite(ENTER_BOLD);
		break;
	case A_DIM:
		if (flag_couleur == TRUE) {
			if (courant->texte >= C_GREY)
				_co_couleur_texte(courant->texte -= C_GREY);
		} else
			_co_capacite(ENTER_DIM);
	}
}


/* positionnement de couleur de texte
 * ----------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_couleur_texte(couleur)
WORD couleur;
{
#ifdef	MOUSE_TRACE
	fprintf(MouseTrace,"foregr=%u\r\n",couleur);
#endif
	switch (couleur) {
	case C_BLACK:
		_co_capacite(FOREGR_0);
		break;
	case C_RED:
		_co_capacite(FOREGR_1);
		break;
	case C_GREEN:
		_co_capacite(FOREGR_2);
		break;
	case C_BROWN:
		_co_capacite(FOREGR_3);
		break;
	case C_BLUE:
		_co_capacite(FOREGR_4);
		break;
	case C_MAGENTA:
		_co_capacite(FOREGR_5);
		break;
	case C_CYAN:
		_co_capacite(FOREGR_6);
		break;
	case C_WHITE:
		_co_capacite(FOREGR_7);
		break;
	case C_GREY:
		_co_capacite(FOREGR_8);
		break;
	case C_LIGHT_RED:
		_co_capacite(FOREGR_9);
		break;
	case C_LIGHT_GREEN:
		_co_capacite(FOREGR_A);
		break;
	case C_YELLOW:
		_co_capacite(FOREGR_B);
		break;
	case C_LIGHT_BLUE:
		_co_capacite(FOREGR_C);
		break;
	case C_LIGHT_MAGENTA:
		_co_capacite(FOREGR_D);
		break;
	case C_LIGHT_CYAN:
		_co_capacite(FOREGR_E);
		break;
	case C_INTENSE_WHITE:
		_co_capacite(FOREGR_F);
	}
#ifdef NPOS_VERSION_7
	if (courant->attribut == A_BLINK)
		_co_capacite(ENTER_BLINK);
		
#endif
}


/* positionnement de couleur de fond
 * ---------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_couleur_fond(couleur)
WORD couleur;
{
#ifdef	MOUSE_TRACE
	fprintf(MouseTrace,"backgr=%u\r\n",couleur);
#endif
	switch ((couleur & 0x0007)) {
	case C_BLACK:
		_co_capacite(BACKGR_0);
		break;
	case C_RED:
		_co_capacite(BACKGR_1);
		break;
	case C_GREEN:
		_co_capacite(BACKGR_2);
		break;
	case C_BROWN:
		_co_capacite(BACKGR_3);
		break;
	case C_BLUE:
		_co_capacite(BACKGR_4);
		break;
	case C_MAGENTA:
		_co_capacite(BACKGR_5);
		break;
	case C_CYAN:
		_co_capacite(BACKGR_6);
		break;
	case C_WHITE:
		_co_capacite(BACKGR_7);
	}
#ifdef NPOS_VERSION_7
	if (courant->attribut == A_BLINK)
		_co_capacite(ENTER_BLINK);
#endif
}


/* effacement d'ecran
 * ------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_clear()
{
	image_st *image;
	int longueur;

	_co_reset_attribut();
	_co_capacite(CLEAR_SCREEN);
	_co_set_attribut();
	image = &courant->image;
#ifdef AIX_VERS
#ifdef SPARC
	longueur = nombre_ligne * nb_colonne;
#else
	longueur = nb_ligne * nb_colonne;
#endif
#else  /* AIX_VERS */
	longueur = nb_ligne * nb_colonne;
#endif /* AIX_VERS */
	memset(image->caractere, ' ', longueur);
	memset(image->attribut, A_NORMAL, longueur);
	if (flag_couleur == TRUE) {
#ifdef ABALCONF
		memset(image->texte, courant->def_char, longueur);
		memset(image->fond, courant->def_back, longueur);
#else
		memset(image->texte, courant->defaut, longueur);
		memset(image->fond, C_BACK, longueur);
#endif /* ABALCONF */
	}
#ifdef ABALCONF
	courant->texte = courant->def_char;
	courant->fond = courant->def_back;
#else
	courant->texte = courant->defaut;
	courant->fond = C_BACK;
#endif /* ABALCONF */
}


/* effacement fin de page
 * ----------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_clear_eos()
{
	image_st *image;
	int longueur;
	int offset;

	if (*CLEAR_EOS != '\0') {
		exit_second();
		_co_reset_attribut();
		_co_capacite(CLEAR_EOS);
		_co_set_attribut();
		_co_pos(courant->ligne, courant->colonne);
		image = &courant->image;
#ifdef AIX_VERS
#ifdef SPARC
		longueur = (nombre_ligne - courant->ligne) * nb_colonne -
#else
		longueur = (nb_ligne - courant->ligne) * nb_colonne -
#endif
#else  /* AIX_VERS */
		longueur = (nb_ligne - courant->ligne) * nb_colonne -
#endif /* AIX_VERS */
			   courant->colonne;
		offset = courant->ligne * nb_colonne + courant->colonne;
		memset(image->caractere + offset, ' ', longueur);
		memset(image->attribut + offset, A_NORMAL, longueur);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + offset,
			       courant->def_char, longueur);
			memset(image->fond + offset,
			       courant->def_back, longueur);
#else
			memset(image->texte + offset,
			       courant->defaut, longueur);
			memset(image->fond + offset,
			       C_BACK, longueur);
#endif /* ABALCONF */
		}
	}
}


/* effacement fin de ligne
 * -----------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_clear_eol()
{
	image_st *image;
	int longueur;
	int offset;

	if (*CLEAR_EOL != '\0') {
		exit_second();
		_co_reset_attribut();
		_co_capacite(CLEAR_EOL);
		_co_set_attribut();
		image = &courant->image;
		longueur = nb_colonne - courant->colonne;
		offset = courant->ligne * nb_colonne + courant->colonne;
		memset(image->caractere + offset, ' ', longueur);
		memset(image->attribut + offset, A_NORMAL, longueur);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + offset, courant->def_char,
			       longueur);
			memset(image->fond + offset, courant->def_back, longueur);
#else
			memset(image->texte + offset, courant->defaut,
			       longueur);
			memset(image->fond + offset, C_BACK, longueur);
#endif /* ABALCONF */
		}
	}
}


/* insertion de ligne
 * ------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_ins_line()
{
	image_st *image;
	register i;
	int source, destination;

	if (*INSERT_LINE != '\0') {
		_co_reset_attribut();
		_co_capacite(INSERT_LINE);
		_co_set_attribut();
		image = &courant->image;
		for (i = max_ligne ; i > courant->ligne; i--) {
			destination = i * nb_colonne;
			source = destination - nb_colonne;
			memcpy(image->caractere + destination,
			       image->caractere + source, nb_colonne);
			memcpy(image->attribut + destination,
			       image->attribut + source, nb_colonne);
			if (flag_couleur == TRUE) {
				memcpy(image->texte + destination,
				       image->texte + source, nb_colonne);
				memcpy(image->fond + destination,
				       image->fond + source, nb_colonne);
			}
		}
		destination = courant->ligne * nb_colonne;
		memset(image->caractere + destination , ' ', nb_colonne);
		memset(image->attribut + destination, A_NORMAL, nb_colonne);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + destination,
			       courant->def_char, nb_colonne);
			memset(image->fond + destination,
			       courant->def_back, nb_colonne);
#else
			memset(image->texte + destination,
			       courant->defaut, nb_colonne);
			memset(image->fond + destination,
			       C_BACK, nb_colonne);
#endif /* ABALCONF */
		}
		courant->colonne = 0;
		_co_out(CR);
	}
}


/* suppression de ligne
 * --------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_del_line()
{
	image_st *image;
	int source, destination;
	int longueur;

	if (*DELETE_LINE != '\0') {
		_co_reset_attribut();
		_co_capacite(DELETE_LINE);
		_co_set_attribut();
		image = &courant->image;
		destination = courant->ligne * nb_colonne;
		source = (courant->ligne + 1) * nb_colonne;
		longueur = (max_ligne - courant->ligne) * nb_colonne;
		memcpy(image->caractere + destination,
		       image->caractere + source, longueur);
		memcpy(image->attribut + destination,
		       image->attribut + source, longueur);
		if (flag_couleur == TRUE) {
			memcpy(image->texte + destination,
			       image->texte + source, longueur);
			memcpy(image->fond + destination,
			       image->fond + source, longueur);
		}
		destination = max_ligne * nb_colonne;
		longueur = nb_colonne;
		memset(image->caractere + destination, ' ', longueur);
		memset(image->attribut + destination, A_NORMAL, longueur);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + destination,
			       courant->def_char, longueur);
			memset(image->fond + destination,
			       courant->def_back, longueur);
#else
			memset(image->texte + destination,
			       courant->defaut, longueur);
			memset(image->fond + destination,
			       C_BACK, longueur);
#endif /* ABALCONF */
		}
		courant->colonne = 0;
		_co_out(CR);
	}
}


/* insertion caractere
 * -------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_ins_character()
{
	image_st *image;
	int longueur;
	int destination;

	if (*INSERT_CHAR != '\0') {
		_co_reset_attribut();
		_co_capacite(INSERT_CHAR);
		_co_set_attribut();
		image = &courant->image;
		destination = courant->ligne * nb_colonne + max_colonne;
		longueur = nb_colonne - courant->colonne;
		while (longueur-- > 0) {
			*(image->caractere + destination + 1) =
			*(image->caractere + destination);
			*(image->attribut + destination + 1) =
			*(image->attribut + destination);
			if (flag_couleur == TRUE) {
				*(image->texte + destination + 1) =
				*(image->texte + destination);
				*(image->fond + destination + 1) =
				*(image->fond + destination);
			}
			destination--;
		}
		destination = courant->ligne * nb_colonne + courant->colonne;
		*(image->caractere + destination) = ' ';
		*(image->attribut + destination) = A_NORMAL;
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			*(image->texte + destination) = courant->def_char;
			*(image->fond + destination) = courant->def_back;
#else
			*(image->texte + destination) = courant->defaut;
			*(image->fond + destination) = C_BACK;
#endif /* ABALCONF */
		}
	}
}


/* suppression caractere
 * ---------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_del_character()
{
	image_st *image;
	int source, destination;
	int longueur;

	if (*DELETE_CHAR != '\0') {
		_co_reset_attribut();
		_co_capacite(DELETE_CHAR);
		_co_set_attribut();
		image = &courant->image;
		destination = courant->ligne * max_colonne + courant->colonne;
		source = destination + 1;
		longueur = max_colonne - courant->colonne;
		memcpy(image->caractere + destination,
		       image->caractere + source, longueur);
		memcpy(image->attribut + destination,
		       image->attribut + source, longueur);
		if (flag_couleur == TRUE) {
			memcpy(image->texte + destination,
			       image->texte + source, longueur);
			memcpy(image->fond + destination,
			       image->fond + source, longueur);
		}
		destination = courant->ligne * nb_colonne + max_colonne;
		*(image->caractere + destination) = ' ';
		*(image->attribut + destination) = A_NORMAL;
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			*(image->texte + destination) = courant->def_char;
			*(image->fond + destination) = courant->def_back;
#else
			*(image->texte + destination) = courant->defaut;
			*(image->fond + destination) = C_BACK;
#endif /* ABALCONF */
		}
	}
}


/* envoi d'une sequence parametrable (ligne ou colonne)
 * ----------------------------------------------------
 *
 * appel:	sequence a envoyer
 *		numero de ligne
 *		numero de colonne
 *
 * retour:	rien
 *
 */
VOID _co_sequence(chaine, y, x)
BYTE *chaine;
WORD y, x;
{
	WORD 	c=0;
	WORD	flag=0;

	while (TRUE) {
		if (*chaine == 'C')
			c = x;
		else if (*chaine == 'L')
			c = y;
		else if (*chaine == '+')
			c += *++chaine;
		else if (*chaine == '-')
			c -= *++chaine;
		else if (*chaine == 'D') {
			flag=0;
			if (c / 100 > 0)
			{
				flag=1;
				_co_out(c / 100 + '0');
			}
			if ((c % 100) / 10 > 0 || flag )
				_co_out((c % 100) / 10 + '0');
			_co_out(c % 10 + '0');
			break;
		} else if (*chaine == 'H') {
			if (c / 16 > 9)
				_co_out(c / 16 + 'A');
			else if (c / 16 > 0)
				_co_out(c / 16 + '0');
			c = c % 16;
			if (c < 10)
				_co_out(c + '0');
			else
				_co_out(c + 'A');
			break;
		} else if (*chaine == '\0') {
			if ( c )  { _co_out(c); }
			break;
		}
		chaine++;
	}
}


/* affichage physique d'un caractere sur ecran
 * -------------------------------------------
 *
 * appel:	caractere a envoyer
 *
 * retour:	rien
 *
 */
VOID _co_out(cx)
WORD cx;
{
	BYTE c;
#ifdef UNIXWARE
	int ret;
#endif

	c=(BYTE) cx;
	if (XCICO_nbl != 0) {	
		if (flag_buf == TRUE) {
			if (out_nb >= DIM_OUT_BUF) {
				out_nb = 0;
			}
			*(out_buf + out_nb++) = (BYTE) c;
		}
		return;
	}

#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/

#ifdef UNIXWARE1
	ret=sighold(SIGALRM);
#endif

	if (flag_buf == TRUE) {
		if (out_nb >= DIM_OUT_BUF) {

#ifdef CICO_DEBUG
			fprintf(DEBUG,"_CO_OUT:BUF:%d\n",out_nb);	
#endif

#ifdef vms
			if (vms$write(STDOUT, out_buf, (unsigned)out_nb) == -1) {
#else
#ifdef UNIXWARE
			sighold(SIGALRM);
#endif
			if (cosyswrite(STDOUT, out_buf, (unsigned int)out_nb) == -1) {
#endif /* vms */
				err_val = EXER_DEVFAIL;	/* erreur */
#ifdef EXABAL
				sprintf(SysLogBuffer, "Error: _co_out failed: Step 1, err_val=%d", err_val);
				ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
			}
			out_nb = 0;
		}
#ifdef UNIXWARE
	sigrelse(SIGALRM);
#endif
		*(out_buf + out_nb++) = (BYTE)c;
	} else {
#ifdef vms
		if (vms$write(STDOUT, &c, 1) == -1) {
#else
#ifdef CICO_DEBUG
		fprintf(DEBUG,"_CO_OUT:%X\n",c);	
#endif
#ifdef UNIXWARE
		sighold(SIGALRM);
#endif
		if (cosyswrite(STDOUT, &c, 1) == -1) {
#endif /* vms */
			err_val = EXER_DEVFAIL;	/* erreur */
#ifdef EXABAL
			sprintf(SysLogBuffer, "Error: _co_out failed: Step 2, err_val=%d", err_val);
			ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
		}
	}
#ifdef UNIXWARE
	sigrelse(SIGALRM);
#endif
#ifdef UNIXWARE1
	if (err_val == EXER_DEVFAIL)
		err_val = 0;
#endif
}


/* envoi d'une sequence fixe
 * -------------------------
 *
 * appel:	sequence a envoyer
 *
 * retour:	rien
 *
 */
VOID _co_capacite(chaine)
BYTE *chaine;
{
	if ( chaine )
		while (*chaine)
			_co_out(*(chaine++));
}


/* scroll sur une ligne
 * --------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_scroll()
{
	image_st *image;
	BYTE *source, *destination;
	int longueur;

	image = &courant->image;

	/* remontee des premieres lignes */
	longueur = max_ligne * nb_colonne;
	destination = image->caractere;
	source = destination + nb_colonne;
	memcpy(destination, source, longueur);
	destination = image->attribut;
	source = destination + nb_colonne;
	memcpy(destination, source, longueur);
	if (flag_couleur == TRUE) {
		destination = image->texte;
		source = destination + nb_colonne;
		memcpy(destination, source, longueur);
		destination = image->fond;
		source = destination + nb_colonne;
		memcpy(destination, source, longueur);
	}

	/* effacement de la derniere ligne */
	longueur = nb_colonne;
	destination = image->caractere + max_ligne * nb_colonne;
	memset(destination, ' ', longueur);
	destination = image->attribut + max_ligne * nb_colonne;
	memset(destination, A_NORMAL, longueur);
	if (flag_couleur == TRUE) {
#ifdef ABALCONF
		destination = image->texte + max_ligne * nb_colonne;
		memset(destination, courant->def_char, longueur);
		destination = image->fond + max_ligne * nb_colonne;
		memset(destination, courant->def_back, longueur);
#else
		destination = image->texte + max_ligne * nb_colonne;
		memset(destination, courant->defaut, longueur);
		destination = image->fond + max_ligne * nb_colonne;
		memset(destination, C_BACK, longueur);
#endif /* ABALCONF */
	}
}


/* push ecran
 * ----------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
int	_co_esc_Q()
{

	int longueur;
	ecran_st *temp;
#ifdef	_apush_c
	int		items=0;
	void	*	buffers[10];
	int		buflens[10];
	int		fg=courant->texte;
	int		bg=courant->fond;
	int		atc=courant->colonne;
	int		atl=courant->ligne;
	int		poptions=get_pushpoptions();

	buffers[items]  = courant->image.caractere;
	buflens[items++]= (nb_colonne * nb_ligne); 
	buffers[items]  = courant->image.attribut;
	buflens[items++]= (nb_colonne * nb_ligne); 
	buffers[items]  = courant->image.texte;
	buflens[items++]= (nb_colonne * nb_ligne); 
	buffers[items]  = courant->image.fond;
	buflens[items++]= (nb_colonne * nb_ligne); 

	if (!( poptions & _INHIBIT_PUSH_COLOUR )) {
		buffers[items]  = &bg;
		buflens[items++]= sizeof( bg );
		buffers[items]  = &fg;
		buflens[items++]= sizeof( fg );
		}

	if (!( poptions & _INHIBIT_PUSH_POSITION )) {
		buffers[items]  = &atc;
		buflens[items++]= sizeof( atc );
		buffers[items]  = &atl;
		buflens[items++]= sizeof( atl );
		}

	return( co_push_to_new_file( items, buffers, buflens ) );

#endif
	return(0);
}

int	PushCounter=0;

VOID _co_push()
{

	int longueur;
	ecran_st *temp;
#ifdef	_apush_c
	int		items=0;
	void	*	buffers[10];
	int		buflens[10];
	int		fg=courant->texte;
	int		bg=courant->fond;
	int		atc=courant->colonne;
	int		atl=courant->ligne;
	int		poptions=get_pushpoptions();

	buffers[items]  = courant->image.caractere;
	buflens[items++]= (nb_colonne * nb_ligne); 
	buffers[items]  = courant->image.attribut;
	buflens[items++]= (nb_colonne * nb_ligne); 

	if (flag_couleur == TRUE) {
		buffers[items]  = courant->image.texte;
		buflens[items++]= (nb_colonne * nb_ligne); 
		buffers[items]  = courant->image.fond;
		buflens[items++]= (nb_colonne * nb_ligne); 
		}
	if (!( poptions & _INHIBIT_PUSH_COLOUR )) {
		if (flag_couleur == TRUE) {
			buffers[items]  = &bg;
			buflens[items++]= sizeof( bg );
			buffers[items]  = &fg;
			buflens[items++]= sizeof( fg );
			}
		}

	if (!( poptions & _INHIBIT_PUSH_POSITION )) {
		buffers[items]  = &atc;
		buflens[items++]= sizeof( atc );
		buffers[items]  = &atl;
		buflens[items++]= sizeof( atl );
		}

	if ( co_push_to_file( items, buffers,buflens ) ) {
		return;
		}

#endif

	if ((temp = (ecran_st *)allocate(sizeof(ecran_st)))
	     == NULL) {
		err_val = 27;
		return;
	}
	*temp = *courant;
#ifdef AIX_VERS
#ifdef SPARC
	longueur = nb_colonne * nombre_ligne;
#else
	longueur = nb_colonne * nb_ligne;
#endif
#else  /* AIX_VERS */
	longueur = nb_colonne * nb_ligne;
#endif /* AIX_VERS */
	if ((temp->image.caractere = (BYTE *)allocate(longueur)) == NULL ||
	    (temp->image.attribut = (BYTE *)allocate(longueur)) == NULL) {
		err_val = 27;
		return;
	}
	memcpy(temp->image.caractere, courant->image.caractere, longueur);
	memcpy(temp->image.attribut, courant->image.attribut, longueur);
	if (flag_couleur == TRUE) {
		if ((temp->image.texte = (BYTE *)allocate(longueur)) == NULL ||
		    (temp->image.fond = (BYTE *)allocate(longueur)) == NULL) {
			err_val = 27;
			return;
		}
		memcpy(temp->image.texte, courant->image.texte, longueur);
		memcpy(temp->image.fond, courant->image.fond, longueur);
	}
	temp->suite = courant->suite;
	courant->suite = temp;
	return;

}


/* pop ecran
 * ---------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_pop()
{
	int		nbc;
	int		fg;
	int		bg;
	int		atc=1;
	int		atl=1;
	register i, j;
	int position;
	BOOL reposition = FALSE;
	BYTE precedent = A_NORMAL;
	BYTE texte_precedente = C_FORE; /* C_GREEN */
	BYTE fond_precedente = C_BACK;  /* C_BLACK */
	BYTE caractere=0;
	BYTE attribut=0;
	BYTE texte=0;
	BYTE fond=0;
	int	courantjeu;
	image_st *image;
	ecran_st *ecran;
	int		mode=0;
	int		items=0;
	void	*	buffers[10];
	int		buflens[10];
	int		poptions=get_pushpoptions();


	if (!( poptions & _INHIBIT_PUSH_POSITION )) {
		buffers[items]	= &atl;
		buflens[items++]= sizeof( atl );
		buffers[items]  = &atc;
		buflens[items++]= sizeof( atc );
		}

	if (!( poptions & _INHIBIT_PUSH_COLOUR )) {
		if (flag_couleur == TRUE) {
			buffers[items]	= &fg;
			buflens[items++]= sizeof( fg );
			buffers[items]  = &bg;
			buflens[items++]= sizeof( bg );
			}
		}

	if (flag_couleur == TRUE) {
		buffers[items]  = courant->image.fond;
		buflens[items++]= (nb_colonne * nb_ligne); 
		buffers[items]  = courant->image.texte;
		buflens[items++]= (nb_colonne * nb_ligne); 
		}

	buffers[items]  = courant->image.attribut;
	buflens[items++]= (nb_colonne * nb_ligne); 
	buffers[items]  = courant->image.caractere;
	buflens[items++]= (nb_colonne * nb_ligne); 

	x_wipe();

	if ((mode = co_pop_from_file( items, buffers,buflens )) != 0 ) {
		ecran = courant;
		}
	else if (!( courant ))
		return;
	else if (!( courant->suite ))
		return;
	else	{
		image = &courant->suite->image;
		ecran = courant->suite;
		if (ecran == NULL)
			return;
		}


	if ( flag_finterm == TRUE ) {
		if (!( mode ))
			x_clear();
		flag_finterm = FALSE;
		}	

	/* affichage de l'ecran en sommet de pile */
	courantjeu = courant->jeu;
	courant->jeu = NO_CASE;
	_co_start();
	_co_attribut(A_NORMAL);
	if (flag_couleur == TRUE) {
#ifdef AIX_VERS
#ifdef SPARC
		for (i = 0; i < nombre_ligne; i++) {
#else
		for (i = 0; i < nb_ligne; i++) {
#endif
#else  /* AIX_VERS */
		for (i = 0; i < nb_ligne; i++) {
#endif /* AIX_VERS */
			_co_pos(i, 0);
			nbc = nb_colonne;
			if ( (i+1) >=  nb_ligne )
				nbc--;
			for (j = 0; j < nbc /* nb__colonne*/ ; j++) {
				position = ((i * nb_colonne) + j);
				caractere = ecran->image.caractere[position];
				attribut = ecran->image.attribut[position];
				texte = ecran->image.texte[position];
				fond = ecran->image.fond[position];
				if ((mode != 0) /* poped from file : ecran == courant */
				||  (caractere != courant->image.caractere[position]	)
				||  ( attribut != courant->image.attribut[position]	)
				||  (    texte != courant->image.texte[position]	)
				||  (     fond != courant->image.fond[position]		)) {
					if (reposition == TRUE) {
						_co_pos(i, j);
						reposition = FALSE;
						}
					if ((precedent != attribut)
					||  (texte_precedente != texte)
					||  (fond_precedente != fond)) {
						_co_attribut(A_NORMAL);
						_co_couleur_texte(texte);
						_co_couleur_fond(fond);
						if (attribut == A_BLINK) {
							_co_attribut(attribut);
							}
						precedent = attribut;
						texte_precedente = texte;
						fond_precedente = fond;
						}
					_co_conv(caractere);
					}
				else	reposition = TRUE;
				}
			}	
		}
	else 	{
#ifdef AIX_VERS
#ifdef SPARC
		for (i = 0; i < nombre_ligne; i++) {
#else
		for (i = 0; i < nb_ligne; i++) {
#endif
#else  /* AIX_VERS */
		for (i = 0; i < nb_ligne; i++) {
#endif /* AIX_VERS */
			_co_pos(i, 0);
			nbc = nb_colonne;
			if ( (i+1) >=  nb_ligne )
				nbc--;
			for (j = 0; j < nbc /* nb__colonne*/ ; j++) {
				position = ((i * nb_colonne) + j);
				caractere = ecran->image.caractere[position];
				attribut = ecran->image.attribut[position];
				if ((mode != 0) /* poped from file : ecran == courant */
				||  (caractere != courant->image.caractere[position]	)
				||  ( attribut != courant->image.attribut[position]	)) {
					if (reposition == TRUE) {
						_co_pos(i, j);
						reposition = FALSE;
						}
					if (precedent != attribut) {
						_co_attribut(A_NORMAL);
						_co_attribut(attribut);
						precedent = attribut;
						}
					_co_conv(caractere);
					}
				else	reposition = TRUE;
				}
			}
		}
	_co_attribut(A_NORMAL);
	_co_flush();
	courant->jeu = courantjeu;
	if (!( poptions & _INHIBIT_PUSH_POSITION )) {
		courant->colonne = atc;
		courant->ligne 	 = atl;
		}
	_co_pos(ecran->ligne, ecran->colonne);
	if (flag_couleur == TRUE) {
		if (!( poptions & _INHIBIT_PUSH_COLOUR )) {
			ecran->holdtext=ecran->texte=fg;
			ecran->holdfond=ecran->fond=bg;
			}
		_co_couleur_texte(ecran->holdtext=ecran->texte);
		_co_couleur_fond(ecran->holdfond=ecran->fond);
		if ( ecran->attribut == A_BLINK )
			_co_attribut(ecran->attribut);
		}
	 else	_co_attribut(ecran->attribut);

	if (!( mode )) {
		/* liberation de l'ecran en sommet de pile */
		/* --------------------------------------- */
		liberate((CHAR *)courant->image.caractere);
		liberate((CHAR *)courant->image.attribut);
		if (flag_couleur == TRUE) {
			liberate((CHAR *)courant->image.texte);
			liberate((CHAR *)courant->image.fond);
			}
		liberate((CHAR *)courant);
		courant = ecran;
		}
	return;
}


/* position ligne
 * --------------
 *
 * appel:	WORD _co_ligne();
 *
 * retour:	position ligne sur l'ecran (origine en 0)
 *
 */
WORD _co_ligne()
{
#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/

	return (courant->ligne);
}


/* position colonne
 * ----------------
 *
 * appel:	WORD _co_colonne();
 *
 * retour:	position colonne sur l'ecran (origine en 0)
 *
 */
WORD _co_colonne()
{

#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/

	return (courant->colonne);
}


VOID _co_start()
{
	if (flag_buf == FALSE) {
		flag_buf = TRUE;
#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/
		}
}


VOID _co_flush()
{

#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/
	if (flag_buf == TRUE) {
		if (out_nb != 0) {
			if (XCICO_nbl == 0) {
#ifdef vms
				if (vms$write(STDOUT, out_buf, (unsigned)out_nb) == -1) {
#else

#ifdef UNIXWARE
				sighold(SIGALRM);
#endif

				if (cosyswrite(STDOUT, out_buf, (unsigned int)out_nb) == -1) {
#endif /* vms */
					err_val = EXER_DEVFAIL;	/* erreur */
#ifdef EXABAL
					sprintf(SysLogBuffer, "Error: _co_flush failed, err_val=%d", err_val);
					ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
				}
			}
			out_nb = 0;
#ifdef UNIXWARE
			sigrelse(SIGALRM);
#endif
		}
		flag_buf = FALSE;
	}
}

#ifdef	EXABAL
#ifndef	LIBPRINT
#include "ixlo.c"
#endif
#endif

/************************************************************************
 *									*
 *	Primitives de gestion de l'image memoire ecran                  *
 *									*
 ***********************************************************************/


/* push ecran
 * ----------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_push()
{
	_co(ESC);
	_co('>');
}


/* pop ecran
 * ---------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_pop()
{
	_co(ESC);
	_co('<');
}


/************************************************************************
 *									*
 *	Primitives d'usage general                                      *
 *									*
 ***********************************************************************/


/* lecture des parametres de configuration
 * ---------------------------------------
 *
 * appel:	le numero de parametre
 *
 * retour:	le parametre
 *
 */

INTERFACE	WORD	local_x_conf(ind)
WORD ind ;
{
	register i, j;

#ifdef IMPLOC
	terminate_local_lo();
#endif /*IMPLOC*/
	i = 0;
	switch (ind) {
	case 1: 	/* nombre de lignes de l'ecran */
#ifdef AIX_VERS
#ifdef SPARC
		i = nombre_ligne;
#else
		i = nb_ligne;
#endif
#else  /* AIX_VERS */
		i = nb_ligne;
#endif /* AIX_VERS */
		break;
	case 2: 	/* nombre de colonnes de l'ecran */
		i = nb_colonne;
		break;
	case 3: 	/* nombre de ligne de l'imprimante */
#ifdef ABALCONF
		if ( abc_printer_flag == FALSE ) {
#endif /* ABALCONF */
		i = 66;
#ifdef ABALCONF
		} else {
			i = abc_printer_nbl;
		}
#endif /* ABALCONF */
		break;
	case 4: 	/* nombre de colonne de l'imprimante */
#ifdef ABALCONF
		if ( abc_printer_flag == FALSE ) {
#endif /* ABALCONF */
		i = 132;
#ifdef ABALCONF
		} else {
			i = abc_printer_nbc;
		}
#endif /* ABALCONF */
		break;
	case 5: 	/* code langue */
		i = get_language_code();
		break;
	case 6: 	/* numero de version Amenesik / Sologic */
		i = '2';
		break;
	case 7: 	/* indice de la version Amenesik / Sologic */
		i = '2';
		break;
	case 8: 	/* bits de protection */
		i = 0000000000110001;
		break;
	case 9: 	/* nombre de touches de fonctions */
		for (j = PKEY_F_FIRST; j < PKEY_F_FIRST + PKEY_F_NB; j++)
			if (*term_str[j] != '\0')
				i++;
		break;
	case 10:	/* identite du systeme d'exploitation   */
	case 15:	/* sous classement des systemes 	*/
#ifdef vms
		i = 2;
#else
		i = 3;
#endif /* vms */
		break;

	case 16:
		return(0);
	case 17:	/* couleur de caractere courant */
		return( courant->holdtext );

	case 18:	/* couleur de fond      courant */
		return( courant->holdfond );

	case 30:	/* initial startup text colour */
		return( C_FORE );
	case 29:	/* initial startup background colour */
		return( C_BACK );

	case 11:	/* fonctions curseur optionelles */
		if (*CLEAR_EOS != '\0')
			i += 1; 	/* effacement fin d'ecran       */
		if (*CLEAR_EOL != '\0')
			i += 2; 	/* effacement fin de ligne	*/
		if (*INSERT_LINE != '\0')
			i += 4; 	/* insertion ligne		*/
		if (*DELETE_LINE != '\0')
			i += 8; 	/* suppression ligne		*/
		if (*INSERT_CHAR != '\0')
			i += 16;	/* insertion caractere		*/
		if (*DELETE_CHAR != '\0')
			i += 32;	/* suppression caractere	*/
		break;
	case 12:	/* attributs n/b optionnels */
		if (*ENTER_STANDOUT != '\0')
			i += 1; 	/* inversion video	*/
		if (*ENTER_BLINK != '\0')
			i += 2; 	/* clignotant		*/
		if (*ENTER_UNDERLINE != '\0')
			i += 4; 	/* souligne		*/
		if (*ENTER_DIM != '\0')
			i += 8; 	/* sous-brillance	*/
		if (*ENTER_BOLD != '\0')
			i += 16;	/* sur-brillance	*/
		break;
	case 13:	/* nombre de colonnes ligne systeme */
		i = 0;
		break;
	case 14:	/* indicateur gestion couleur */
		i = flag_couleur == TRUE ? 1 : 0;
		break;
	default:
		i = 0;
	}
	return (i);
}


/* lecture du numero de poste
 * --------------------------
 *
 * appel:	rien
 *
 * retour:	le numero de poste
 *
 */
/*DLR:02/02/93*/
WORD x_npos()
{
	switch ( process_flag ) {
		case TRUE  : 
			return( process_number );
		default    : return( x_npos14() );
		}
}

static WORD x_npos14()

#ifdef NPOS_SYSTEM_V

/* System V
 * --------
 *
 * lecture du fichier /etc/utmp avec les fonctions getut(3C)
 * Modification Unix Interactive :
 * -----------------------------
 *	Plus de classement alphabetique :
 *		Probleme console fixe vt et console reseau dynamique ttyp
 *	Probleme du nom de ut_line :
 *		au login dans /etc/utmp : /dev/vt01
 *		apres le login : vt01 correction par suppresion de l'ordre
 *		alpha
 * 	Attention sur SCO : la console fonctionne par effet de bord
 *			car PROCESS=0 quand une entree n'est pas trouvee
 *			en effet tty -> /dev/syscon et
 *			/dev/utmp on a /dev/tty01.
 */
{
	static WORD poste = 0xffff;	/* numero de poste		*/
	CHAR *cp;			/* pointeur de caractere	*/
	struct utmp *utbuf;		/* caracteristiques d'un processus */
	BOOL trouve = FALSE;
	int comp;

	if (poste != 0xffff)
		return (poste);
	else
		poste = 0;
	if ((cp = ttyname(STDIN)) == NULL)
		return (poste);
	cp += strlen("/dev/");
	while (TRUE) {
		if ((utbuf = getutent()) == NULL) {
			endutent();
			if (trouve == FALSE)
				poste = 0;
			break;
		}
		if (utbuf->ut_type == INIT_PROCESS ||
		    utbuf->ut_type == LOGIN_PROCESS ||
		    utbuf->ut_type == USER_PROCESS) {

			if ( *(utbuf->ut_line) != '\0' ) {
				comp= strcmp(cp, utbuf->ut_line);
				if (process_seq == FALSE) {
					if (comp == 0) {
						trouve = TRUE;
						endutent();
						break;
					}
					poste++;
				} else {
					if (comp == 0) {
						trouve = TRUE;
						endutent();
						break;
					}
					else if (comp > 0)
						poste++;
				}
			}			
		}
	}
	return (poste);
}

#ifdef ABAL14B
/* System V
 * --------
 *
 * lecture du fichier /etc/utmp avec les fonctions getut(3C)
 *
 */
{
	static WORD poste = 0xffff;	/* numero de poste		*/
	CHAR *cp;			/* pointeur de caractere	*/
	struct utmp *utbuf;		/* caracteristiques d'un processus */
	BOOL trouve = FALSE;
	int comp;

	if (poste != 0xffff)
		return (poste);
	else
		poste = 0;
	if ((cp = ttyname(STDIN)) == NULL)
		return (poste);
	cp += strlen("/dev/");
	while (TRUE) {
		if ((utbuf = getutent()) == NULL) {
			endutent();
			if (trouve == FALSE)
				poste = 0;
			break;
		}
		if (utbuf->ut_type == INIT_PROCESS ||
		    utbuf->ut_type == LOGIN_PROCESS ||
		    utbuf->ut_type == USER_PROCESS) {
/* DLR:05/02/93 */
			if ( *(utbuf->ut_line) != '\0' ) {
				comp= strcmp(cp, utbuf->ut_line);
				if (comp == 0)
					trouve = TRUE;
				else if (comp > 0)
					poste++;
			}
		}
	}
	return (poste);
}
#endif /* ABAL14B */

#endif /* NPOS_SYSTEM_V */

#ifdef NPOS_VERSION_7

/* Version 7
 * ---------
 *
 * SCO Xenix 2.3 - Sinix
 *
 * lecture du fichier /etc/ttys
 *
 */
{
	static WORD poste = 0xffff;	/* numero de poste		*/
	CHAR *cp;			/* pointeur de caractere	*/
	FILE *stream;
	CHAR buf[64];

	if (poste != 0xffff)
		return (poste);
	if ((cp = ttyname(STDIN)) == NULL)
		return (poste = 0);
	cp += strlen("/dev/");
#ifdef EXABAL
	if (Access("/etc/ttys", R_OK, 0) == -1)
#else
	if (access("/etc/ttys", R_OK) == -1)
#endif /* EXABAL */
		return (0);
	if ((stream = fopen("/etc/ttys", "r")) != NULL) {
		do {
			if (fgets(buf, 63, stream) == NULL) {
				poste = 0;
				break;
			}
			poste++;
		} while (strncmp(buf + 2, cp, strlen(buf) - 3) != 0);
#ifdef EXABAL
		liberlox("/etc/ttys");
#endif /* EXABAL */
		fclose(stream);
	} else
		poste = 0;
	return (poste);
}

#endif /* NPOS_VERSION_7 */

#ifdef NPOS_VERSION_DEBUG

/* Version DEBUG
 * ---------
 *
 *
 *
 */
{

#ifdef CICO_DEBUG
	printf("\r\nR_uid:%d,E_uid:%d\r\n",getuid(),geteuid());
#endif /* CICO_DEBUG */
	return( getuid() );
}

#endif /* NPOS_VERSION_DEBUG */

#ifdef NPOS_BSD_4

/* BSD 4.x
 * -------
 *
 * Ultrix
 *
 * utilisation directe de la fonction ttyslot()
 *
 */
{
	return ((WORD)ttyslot());
}

#endif /* NPOS_BSD_4 */

#ifdef vms

{
	return ((WORD)vms$npos());
}

#endif /* vms */


/************************************************************************
 *									*
 *	Initialisations du terminal (ecran/clavier)			*
 *									*
 ***********************************************************************/


/* x_redir - redirection cico
 * --------------------------
 *
 * appel:	WORD x_redir(sens, indicateur, descripteur, taille);
 *		BOOL sens		  = TRUE si activation
 *					    FALSE si desactivation
 *		WORD indicateur 	  = indicateur des fonctions a rediriger
 *		BDA_INIT FAR *descripteur = structture de description de la BDA
 *		WORD taille		  = taille du descripteur
 *
 * retour:	0 si ok, 0xffff en cas d'erreur.
 *
 */
WORD x_redir(sens, indicateur, descripteur, taille)
BOOL sens;
WORD indicateur;
BDA_INIT *descripteur;
WORD taille;
{
	int	r=1;
	int	i;
	void * vptr;	
	WORD (*construction)();	/* BDA_INIT*,ecran_st* */
	
	if ( sens ) {
		/* Ceci est la nouvelle version de cette affreuse affaire ! */
		for (i=0; i < CICO_NOMBRE; i++ ) {
			if ( i != CICO_INIT ) {
				vptr = descripteur->cico.fonction[i];
				if ((vptr = redirect_access_controller(i,vptr))!= (void *) 0)
	  	  			descripteur->cico.fonction[i] = vptr;
	 			}
			}
#ifdef	EXABAL 
		if (((construction = descripteur->cico.fonction[CICO_INIT]) != 0)
		&&   ( descripteur->cico.numero & (8192*2)  )) 
			(void) (*construction)(descripteur,courant,&CicoAccessController);
		redir = *descripteur;
#endif
		}
	else	{
		for ( i=0,r=1; i < CICO_NOMBRE; i++, r <<= 1) {
			if ( descripteur->cico.numero & r ) {
				if ( i != CICO_INIT ) {
					vptr = descripteur->cico.fonction[i];
					if ((vptr = redirect_access_controller(i
						,vptr))!= (void *) 0)  	 	 
						descripteur->cico.fonction[i] = vptr; 
		 	 		else	descripteur->cico.fonction[i] = 0;
	 				}
	 	 		else	descripteur->cico.fonction[i] = 0;
				}
			} 
		} 
	return (0);
}


/*DLR:02/02/93*/
void	establish_process_number( process_filename )
char	* process_filename;
{
	FILE * process_handle;
	char	tty_name_buf[256];
	int	process_id;
	int	version_number;
	char	* cp;

	/* Si le 1er champ est blanc : ancienne methode */
	/* -------------------------------------------- */
	if ( process_filename[0]==' ' ) {
		process_flag = FALSE;
		return;
		}

	/* --------------------------------------------------------- */
	/* Si le 1er champ est vide : No de process dans ABALPROCESS */
	/* --------------------------------------------------------- */
	if ( process_filename[0]==':' ) {
		if ( process_filename[1] == 'S' ) {
			process_flag = FALSE;
			process_seq = TRUE;
			return;
			}	

		process_number = (WORD)atoi( process_filename+1 );
		process_flag = TRUE;
		return;
		}

	else if(( process_filename[0] == 'a' )
	     && ( process_filename[1] == 'c' )
	     && ( process_filename[2] == 'c' )
	     && ( process_filename[3] == 'e' )
	     && ( process_filename[4] == 's' )
	     && ( process_filename[5] == 's' )) {
		process_number = access_process_number();
		process_flag = TRUE;
		return;
		}

	/* -------------------------------------------------- */
	/* Added for ABAL 3 to allow easy use of ABAL PROCESS */
	/* -------------------------------------------------- */
	else if (( process_filename[0] >= '0' )
	     &&  ( process_filename[0] <= '9' )) {
		process_number = (WORD)atoi( process_filename );
		process_flag = TRUE;
		return;
		}

	/* Attempt to open Process to TTY name configuration file */
	/* ------------------------------------------------------ */
	if ((process_handle = fopen( process_filename, "r" )) != (FILE *) 0) {

		/* Collect Current Station File Version Number */
		/* ------------------------------------------- */
		fscanf(process_handle,"%s",&tty_name_buf);
		fscanf(process_handle,"%d",&version_number);
		
		/* Collect current tty name string */
		/* ------------------------------- */
		if ((cp = ttyname(STDIN)) != NULL) {

			cp += strlen("/dev/");

			/* Read Entries from the file */
			/* -------------------------- */
			while ( 1 ) {
				tty_name_buf[0] = 0;
				fscanf(process_handle,"%s",tty_name_buf);
				if ( strlen(tty_name_buf) == 0 )
					break;
				fscanf(process_handle,"%d",&process_id);
				if ( strcmp( tty_name_buf, cp ) == 0 ) {
					process_number = process_id;
					process_flag = TRUE;
					break;
					}
				}

			}
		
		/* Liberate the process config file */
		/* -------------------------------- */
		fclose( process_handle );
		}
	return;

}

/* initialisations pour la gestion du terminal
 * -------------------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */

VOID	set_fore_back(f,b)
int 	f;
int 	b;
{
	C_FORE = f;
	C_BACK = b;
	return;
}

void	set_mimo_limit(sptr)
char * sptr;
{
#ifdef	_CICO_MIMO
	int	slen;
	if (!( sptr ))
		return;
	else if (!( slen = strlen(sptr) ))
		return;
	else if ( slen == 3 ) {
		if (( *(sptr+0) == 27 )
		&&  ( *(sptr+1) == 'm')
		&&  ( *(sptr+2) == '2'))
			CicoMimo.limit = 7;
		else	CicoMimo.limit = 3;
		}
	else if ( slen >= 5 ) {
		sptr += slen;
		sptr -= 5;
		if (( *(sptr+0) == '1' )
		&&  ( *(sptr+1) == '0' )
		&&  ( *(sptr+2) == '0' )
		&&  ( *(sptr+3) == '7' )
		&&  ( *(sptr+4) == 'h' ))
			CicoMimo.limit = 7;
		else	CicoMimo.limit = 3;
		}
	else	CicoMimo.limit = 3;
#endif
	return;
}


static	VOID	check_lines_and_columns()
{
	char *	eptr;

#ifdef SPARC
	if (!( nb_ligne )) {
		if (!( eptr = getenv("LINES") ))
			nb_ligne = 24;
		else if (!(nb_ligne = atoi(eptr))) 
			nb_ligne = 24;
		}
#else
	if (!( nb_ligne )) {
		if (!( eptr = getenv("LINES") ))
			nb_ligne = 24;
		else if (!(nb_ligne = atoi(eptr)))
			nb_ligne = 24;
		}
#endif
	if (!( nb_colonne )) {
		if (!( eptr = getenv("COLUMNS") ))
			nb_colonne = 80;
		else if (!(nb_colonne = atoi(eptr)))
			nb_colonne = 80;
		}
	return;
}


VOID initerm()

{
	int	v;
	register i, j;		/* compteurs de boucles 		*/
	CHAR c; 		/* caractere				*/
	CHAR * dathstr=(CHAR *) 0;
	int longueur;		/*					*/
	CHAR *cp;		/*					*/
	BYTE *bp;		/*					*/
	CHAR *term;		/* variable d'environnement TERM        */
	CHAR *test;		/* champ test				*/
	CHAR *cico;		/* variable d'environnement CICO        */
	CHAR *lo;		/* variable d'environnement LO          */
	CHAR *lang;		/* variable d'environnement LANG        */
	CHAR *path;		/* chemin du fichier parametre		*/
	CHAR *tempo_bis;	/* chaine de la valeur de temporisation */
	CHAR *name;		/* nom complet du fichier parametre	*/
	int fh = -1;		/* handle du fichier parametre		*/

	unsigned lg_nom;	/* LONG. de la section du nom		*/
	unsigned lg_nb; 	/* LONG. de la section des nombres	*/
	unsigned lg_off;	/* LONG. de la section des deplacements */
	unsigned lg_str;	/* LONG. de la section des chaines	*/
	unsigned lg_in; 	/* LONG. de la table conversion clavier */
	unsigned lg_out;	/* LONG. de la table conversion ecran	*/

	BYTE sum;		/* somme calculee			*/
	BYTE sumsum;		/* somme de la somme calculee		*/
	WORD checksum;		/* checksum				*/
	BYTE *buf;		/* buffer de calcul			*/

	LONG lg_calc;		/* LONG. calculee du fichier		*/
	CHAR *entete;		/* entete de fichier parametre		*/
	CHAR *nom;		/* nom du terminal decrit		*/
	CHAR *nb;		/* section des nombres			*/
	CHAR *off;		/* section des deplacements		*/
	int taille_car; 	/* nombre de bits d'un caractere        */

	int	default_esc_r;	/* C_FORE	*/
	int	default_esc_s; 	/* C_BACK	*/
	int	default_esc_n;  /* C_BACK	*/
	
/* #BGI Pour Debug */
/*sleep(30);*/

	if (flag_init == FALSE) {

#ifdef	_MOUSE_TRACE
		MouseTrace = fopen(MOUSE_TRACE_FILE,"w");
#endif
#ifdef	_KEYB_TRACE
		KeybTrace = fopen(KEYB_TRACE_FILE,"w");
#endif

		default_esc_r = C_FORE;
		default_esc_s = C_BACK;
		default_esc_n = C_BACK;

		initialise_access_controller();

		/* initialisation */
		/* -------------- */
		flag_finterm = FALSE;

#ifdef CICO_DEBUG
		if (Access("dbg_cico",W_OK,1) == 0 ) {
			DEBUG=fopen("dbg_cico","w");
			} 
		else 	{
			DEBUG=fopen("dbg_cico2","w");
			}
#endif /* fin CICO_DEBUG */

		/* ignorer les signaux SIGINT et SIGQUIT */
		/* ------------------------------------- */
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);

		/* Redirection du CICO vers CICO extern  si XCICO = nb de lignes existe */
		/* -------------------------------------------------------------------- */
		XCICO_nbl = 0;		
		if ((cp = getenv("XCICO")) != NULL) {
			while (*cp >= '0' && *cp <= '9')
				XCICO_nbl = XCICO_nbl * 10 + *cp++ - '0';
			/* ioctl( STDOUT, le command qu'il me faut pour MV ); */
			/* -------------------------------------------------- */
			cosyswrite(STDOUT,XCICO_start,XCICO_NB);
			}

#ifdef USEIT
		/* #BG 24/03/11 Gestion UTF8 */
		/* ------------------------- */
//#BG 11/05/17 Inutile!
//		if (get_useit_version() >= 4) {
			utf8_flag = TRUE;
			if ((cp = getenv("ABALUTF8")) != NULL) {
				if ( strcmp(cp, "0") == 0)
					utf8_flag = FALSE;
			}
//		}
#endif

#ifdef ABALCONF
		/* Test de l'existence de la variable ABALCONF */
		/* ------------------------------------------- */
		if ((cp = getenv("ABALCONF")) != NULL) {
			establish_config( cp );
			}
#endif /* ABALCONF */

#ifdef ABALCONF
		if ( abc_process_flag == FALSE ) {
#endif /* ABALCONF */

			/* DLR:02/02/93				    */
			/* Test for PROCESS compatible Version 1.5a */
			/* ---------------------------------------- */
			if ((cp = getenv("ABALPROCESS")) != NULL)
				establish_process_number( cp );
			else    process_flag = FALSE;
#ifdef ABALCONF
			}
		else 	{
			process_flag = abc_process_flag;
			process_number = abc_process_number;
			process_seq = FALSE;
			}
#endif /* ABALCONF */

		/* lecture des parametres d'environnement */
		/* -------------------------------------- */
		cico = term = path = NULL;

#ifdef ABALCONF
		if ( abc_screen_flag == FALSE ) {
#endif /* ABALCONF */

			if ((cp = getenv(ENV_ECRAN)) != NULL) {
				if ((cico = allocate(strlen(cp) + 1)) == NULL)
					erreur(E_ALLOC, NULL, fh);
				strcpy(cico, cp);
				term = cico;
				if ((cp = strchr(cico, ENV_SEPARATEUR)) != NULL) {
					*cp = '\0';
					path = ++cp;
					if ((cp = strchr(cp, ENV_SEPARATEUR)) != NULL) {
						*cp = '\0';
						tempo_bis = ++cp;
						if ((cp = strchr(cp, ENV_SEPARATEUR)) != NULL) {
							*cp = '\0';
							dathstr = ++cp;
							/* -------------------------------------------------------------- */
							/* New Default Colour Control : ABAL 2.2b.0.04 and ABAL 3.1a.0.25 */
							/* Tuesday 28/07/2003 : ABAL 3 USeit etc etc			  */
							/* -------------------------------------------------------------- */
							if ( dathstr ) {
								if (( *dathstr >= '0' )
								&&  ( *dathstr <= '9' )) {
									C_FORE = default_esc_r = (*(dathstr++) - '0');
									}
								else if (( *dathstr >= 'A' )
								     &&  ( *dathstr <= 'F' )) {
									C_FORE = default_esc_r = ((*(dathstr++) - 'A')+10);
									}
								else 	dathstr=(char *) 0;
								}
							if ( dathstr ) {
								if (( *dathstr >= '0' )
								&&  ( *dathstr <= '9' )) {
									C_BACK = default_esc_s = (*(dathstr++) - '0');
									}
								else if (( *dathstr >= 'A' )
								     &&  ( *dathstr <= 'F' )) {
									C_BACK = default_esc_s =((*(dathstr++) - 'A')+10);
									}
								else 	dathstr=(char *) 0;
								}
							if ( dathstr ) {
								if (( *dathstr >= '0' )
								&&  ( *dathstr <= '9' )) {
									C_BACK = default_esc_n = (*(dathstr++) - '0');
									}
								else if (( *dathstr >= 'A' )
								     &&  ( *dathstr <= 'F' )) {
									C_BACK = default_esc_n = ((*(dathstr++) - 'A')+10);
									}
								else 	dathstr=(char *) 0;
								}
							}
						tempo = 0;
						while (*tempo_bis >= '0' && *tempo_bis <= '9')
							tempo = tempo * 10 + *tempo_bis++ - '0';
	
						}
					}
				}
			if (term == NULL || *term == '\0')
#ifdef vms
				if ((term = getenv("TERM")) == NULL ||
				    strcmp(term, "undefined") == 0)
#else
				if ((term = getenv("TERM")) == NULL)
#endif /* vms */
					erreur(E_FIND, NULL, fh);

			if (path == NULL || *path == '\0')
				path = ECR_CHEMIN;
			if (tempo == -1)
				erreur(E_TEMPO, NULL, fh);

			if ((test = strchr(term, IMP_SEPARATEUR)) != NULL)
				*test++ = '\0';

#ifdef ABALCONF
			}
		else 	{
			term = abc_screen_name;
			path = abc_screen_path;
			tempo = abc_screen_tempo;
			test = (CHAR *)0;
			}	
#endif /* ABALCONF */

#ifdef ABALCONF
		if ( abc_language_flag == FALSE ) {
#endif /* ABALCONF */
			if (((lang = getenv(ENV_LANGUE))  != NULL)
			||  ((lang = getenv(ENV_LANGUE2)) != NULL)) {
				v = 0;
				while (*lang >= '0' && *lang <= '9')
					v = ((v * 10) + (*(lang++) - '0'));
				set_language_code(v);
				}
#ifdef ABALCONF
			} 
		else 	{
			set_language_code( abc_language );
			}
#endif /* ABALCONF */

#ifdef	EXABAL
#ifdef SHAREDLO
#ifdef ABALCONF
		if ( abc_sharedlo_flag == FALSE ) {
#endif /* ABALCONF */
			if ( getenv(ENV_SHAREDLO)  != NULL) {
				set_shared_lo(1);
				}
#ifdef ABALCONF
			} 
		else 	{
			set_shared_lo( abc_sharedlo_flag );
			}
#endif /* ABALCONF */
#endif

#ifdef ABALCONF
		if ( abc_noreset_flag == FALSE ) {
#endif /* ABALCONF */
			if ( getenv(ENV_RESETTERM)  != NULL) {
				resetterm = 0;
				}
#ifdef ABALCONF
			} 
		else 	{
			resetterm = abc_noreset_flag;
			}
#endif /* ABALCONF */

#endif /* SHAREDLO */

		if ((name = allocate(strlen(path) + 3 + strlen(term))) == NULL)
			erreur(E_ALLOC, NULL, fh);
		strcpy(name, path);
#ifndef vms
		strcat(name, "/");
#endif /* vms */
		strcat(name, term);
#ifdef vms
		if ((fh = open(name, O_RDONLY, 0, "shr=get")) == -1)
			erreur(E_OPEN, name, fh);
#else
#if EXABAL
		if (Access(name, R_OK, 0) == -1) {
			if (errno == 666)
				erreur(E_INSTALL, NULL, fh);
			if (errno == 667)
				erreur(E_ACCESS, NULL, fh);
#else
		if (access(name, R_OK) == -1) {
#endif /* EXABAL */
			erreur(E_OPEN, name, fh);
			}
		fh = open(name, O_RDONLY);
#endif /* vms */

		/* lecture de l'entete */
		if ((entete = allocate(ECR_LONGUEUR_ENTETE)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, entete, ECR_LONGUEUR_ENTETE) == -1)
			erreur(E_READ, name, fh);

		/* verification de la signature */
		
#ifdef	_USEIT_FOR_WHATEVER
		if (memcmp(entete, NEW_SIGNATURE, ECR_LONGUEUR_SIGNATURE) > 0) {
#endif
			if (memcmp(entete, ECR_SIGNATURE, ECR_LONGUEUR_SIGNATURE) > 0)
				erreur(E_BADF, name, fh);
#ifdef	_USEIT_FOR_WHATEVER
			else	signature_version = 14;
			}
		else	signature_version = 22;
#endif
		/* lecture des longueurs */
		bp = (BYTE *)(entete + ECR_LONGUEUR_SIGNATURE);
		lg_nom = *bp + *(bp + 1) * 256; bp += 2;
		lg_nb = *bp + *(bp + 1) * 256; bp += 2;
		lg_off = *bp + *(bp + 1) * 256; bp += 2;
		lg_str = *bp + *(bp + 1) * 256; bp += 2;
		lg_in = *bp + *(bp + 1) * 256; bp += 2;
		lg_out = *bp + *(bp + 1) * 256; bp += 2;
		lg_calc = lg_nom + lg_nb + lg_off + lg_str + lg_in + lg_out;
		if (lg_nom % 2)
			lg_calc++;
		if (lg_str % 2)
			lg_calc++;

		/* lecture de la checksum */
		checksum = *bp + *(bp + 1) * 256;

		/* alloction d'un buffer de calcul */
		if ((buf = (BYTE *)allocate(lg_calc)) == NULL)
			erreur(E_ALLOC, NULL, fh);

		/* lecture des donnees pour le calcul */
		if (read(fh, (CHAR *)buf, lg_calc) != lg_calc)
			erreur(E_READ, name, fh);

		/* calcul de la checksum */
		sum = sumsum = 0;
		for (i = 0; i < lg_calc; i++) {
			sum += buf[i];
			sumsum += sum;
		}
		if (checksum != sum * 256 + sumsum)
			erreur(E_BADF, name, fh);

		/* repositionnment */
		if (lseek(fh, 20L, SEEK_SET) == -1L)
			erreur(E_SEEK, name, fh);

		/* lecture du nom */
		if (lg_nom % 2)
			lg_nom++;
		if ((nom = allocate(lg_nom)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		else	paranom = nom;
		if (read(fh, nom, lg_nom) == -1)
			erreur(E_READ, name, fh);

		/* lecture des nombres */
		if ((nb = allocate(lg_nb)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, nb, lg_nb) == -1)
			erreur(E_READ, name, fh);
		bp = (BYTE *)nb;

#ifdef SPARC
		nombre_ligne = *bp + *(bp + 1) * 256; bp += 2;
#else
		nb_ligne = *bp + *(bp + 1) * 256; bp += 2;
#endif
#ifdef ABALCONF
		if ( abc_screen_nbl != 0 )
#ifdef SPARC
			nombre_ligne = abc_screen_nbl;
#else
			nb_ligne = abc_screen_nbl;
#endif
#endif /* ABALCONF */

/* XCICO actif */
		if ( XCICO_nbl != 0 )
#ifdef SPARC
			nombre_ligne = XCICO_nbl;
#else
			nb_ligne = XCICO_nbl;
#endif
/***************/

		nb_colonne = *bp + *(bp + 1) * 256; bp += 2;
#ifdef ABALCONF
		if ( abc_screen_nbc != 0 )
			nb_colonne = abc_screen_nbc;
#endif /* ABALCONF */

		check_lines_and_columns();
#ifdef SPARC
		max_ligne = nombre_ligne - 1;
#else
		max_ligne = nb_ligne - 1;
#endif
		max_colonne = nb_colonne - 1;
		taille_car = *bp + *(bp + 1) * 256;

		/* lecture des deplacements */
		if ((off = allocate(lg_off)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, off, lg_off) == -1)
			erreur(E_READ, name, fh);

		/* lecture des chaines */
		if ((tab_str = allocate(lg_str)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, tab_str, lg_str) == -1)
			erreur(E_READ, name, fh);
		if (lg_str % 2)
			if (lseek(fh, 1L, SEEK_CUR) == -1)
				erreur(E_READ, name, fh);

		for (i = 0; i < lg_off / 2; i++) {
			bp = (BYTE *)(off + i * 2);
			term_str[i] = (BYTE *)(tab_str + *bp + *(bp + 1) * 256);
			}
#ifdef	_USEIT_FOR_WHATEVER
#ifdef	_CICO_MIMO	
		if ( signature_version >= 22 ) {
			if (!( CicoMimo.detect = MOUSE_EVENT )) {
				CicoMimo.start = CicoMimo.stop = (char *) 0;
				}
			else  	{
				if (!(CicoMimo.start = MOUSE_ON ))
					CicoMimo.stop = (char *) 0;
				else	CicoMimo.stop = MOUSE_OFF;
				set_mimo_limit( CicoMimo.start );
				}
			}
		else	{
			CicoMimo.detect = CicoMimo.start = CicoMimo.stop = (char *) 0;
			}
#endif
#endif

#ifdef IMPLOC
		if ( (lg_off / 2) < NB_CAPA ) {
			for (i = (lg_off / 2); i < NB_CAPA; i++) {
				term_str[i] = (BYTE *) NULL;
				}
			}
#endif /*IMPLOC*/
		/* lecture des tables de conversion */
		if ((tab_out = (BYTE *)allocate(256)) == NULL ||
		    (tab_in = (BYTE *)allocate(256)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, tab_in, 256) == -1 || read(fh, tab_out, 256) == -1)
			erreur(E_READ, name, fh);

		/* affichage banniere */
		if (test != NULL &&
		    (strcmp(test, "test") == 0 ||
		     strcmp(test, "TEST") == 0)) {
			write(STDERR, message[B_VERSION],
			      strlen(message[B_VERSION]));
			write(STDERR, message[B_UPDATE],
			      strlen(message[B_UPDATE]));
			write(STDERR, message[B_COPYRIGHT],
			      strlen(message[B_COPYRIGHT]));
			write(STDERR, "file: ", 6);
			write(STDERR, nom, strlen(nom));
			write(STDERR, "\ntempo: 0x", 8);
			for (i = 1000000, j = tempo; i > 0; i /= 10) {
				if (tempo >= i) {
					c = j / i + '0';
					j = j % i;
					write(STDERR, &c, 1);
					}
				}
			write(STDERR, "\n", 1);
#if EXABAL
			write(STDERR, "(exa)\n", 6);
#endif /* EXABAL */
			sleep(5);
			}

		/* liberation des zones et fermeture du fichier */
		liberate(nb);
		liberate(off);
		liberate(entete);
		if (cico != NULL)
			liberate(cico);
#if defined(EXABAL) && !defined(vms)
		liberlox(name);
#endif /* EXABAL && !vms */
		liberate(name);
		cicoclose(fh);
		fh = -1;

		/* test presence couleur */
		flag_couleur = TRUE;
		for (i = FORE_FIRST; i < FORE_FIRST + FORE_NB; i++) {
			if (*term_str[i] == '\0') {
				flag_couleur = FALSE;
				break;
				}
			}
		if (flag_couleur == TRUE) {
			for (i = BACK_FIRST; i < BACK_FIRST + BACK_NB; i++) {
				if (*term_str[i] == '\0') {
					flag_couleur = FALSE;
					break;
					}
				}
			}

		/* allocation de l'ecran courant */
		if ((courant = (ecran_st *)allocate(sizeof(ecran_st))) == NULL)
			erreur(E_ALLOC, NULL, fh);
		courant->suite = NULL;
		courant->ligne = 0;
		courant->colonne = 0;
		courant->jeu = NO_CASE;
		courant->etat = ETAT_STANDARD;
		courant->attribut = A_NORMAL;
#ifdef ABALCONF
		if ( abc_color_flag == FALSE ) {
			courant->def_char = C_FORE;
			courant->def_back = C_BACK;
			courant->holdtext = courant->texte = C_FORE;
			courant->holdfond = courant->fond = C_BACK;
			} 
		else 	{
			courant->def_char = abc_color_char;
			courant->def_back = abc_color_back;
			courant->holdtext = courant->texte = abc_color_char;
			courant->holdfond = courant->fond = abc_color_back;
			}
#else
		courant->defaut = C_FORE;
		courant->holdtext = courant->texte = C_FORE;
		courant->holdfond = courant->fond = C_BACK;
#endif /* ABALCONF */

		courant->holdtext = courant->def_char = courant->texte = default_esc_r;
		courant->holdfond = courant->fond     = default_esc_s;
		courant->def_back = default_esc_n;

		/* allocation de la zone ecran */
#ifdef AIX_VERS
#ifdef SPARC
		longueur = nombre_ligne * nb_colonne;
#else
		longueur = nb_ligne * nb_colonne;
#endif
#else  /* AIX_VERS */
		longueur = nb_ligne * nb_colonne;
#endif /* AIX_VERS */
		if ((courant->image.caractere = (BYTE *)allocate(longueur+1)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if ((courant->image.attribut = (BYTE *)allocate(longueur+1)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (flag_couleur == TRUE) {
			if ((courant->image.texte = (BYTE *)allocate(longueur+1)) == NULL)
				erreur(E_ALLOC, NULL, fh);
			if ((courant->image.fond = (BYTE *)allocate(longueur+1)) == NULL)
				erreur(E_ALLOC, NULL, fh);
			}

#ifdef	EXABAL
#ifdef ABALCONF
		if ( abc_printer_flag == FALSE ) {
#endif /* ABALCONF */
			if (!( initform(0,(char *) 0, (char *) 0 ) ))
				erreur(E_ALLOC, NULL, fh);
#ifdef ABALCONF
			}
		else 	{
			if (!( initform(1,abc_printer_name,abc_printer_path) ))
				erreur(E_ALLOC, NULL, fh);
			}
#endif /* ABALCONF */
#endif
		/* verification de la presence des touches programmables */
		for (i = 0; i < PKEY_NB + PKEY_F_NB; i++) {
			if (pkey[i].act == FALSE)
				if (*term_str[PKEY_FIRST + i] != '\0')
					pkey[i].act = TRUE;
			}
#ifdef _DELAY 
		_delay = TRUE;
		delay_on();
#endif
		/* initialisation faite */
		flag_init = TRUE;
		}

#ifdef vms
	vms$initerm();
	vms$fcntl(0, 0, O_RDONLY);
#else

#ifdef SHAREDLO
	if (resetterm != 0)
	{
#endif /* SHAREDLO */

	/* lecture des paramtres de la liaison */
	ioctl(STDIN, TCGETA, &confterm);	/* pour sauvegarde */
	ioctl(STDIN, TCGETA, &proterm); 	/* pour programmer */

	/* positionnement des parametres */

	proterm.c_iflag &= ~ICRNL;
	if (taille_car == 8)
		proterm.c_iflag &= ~ISTRIP;
	proterm.c_oflag &= ~OPOST;
	proterm.c_lflag = 0;
	proterm.c_cc[VTIME] = 0;
	proterm.c_cc[VMIN] = 1;
	proterm.c_cc[VINTR] = 0xFF;
	proterm.c_cc[VQUIT] = 0x7F;
#ifdef SHAREDLO
	}
#endif /* SHAREDLO */


/*(NEWTEMPO)*/
	if ( tempo <= 0 )
		tempo=1;	/* Pas de temporisation nulle : tempo defaut=1s */
	else if ( tempo > 100 )
		tempo=1;	/* Temporisation maximale 10s : tempo defaut=1s */

	/* programmation de la liaison */
#ifdef SHAREDLO
	if (resetterm != 0)
#endif /* SHAREDLO */
	ioctl(STDIN, TCSETA, &proterm);
#endif /* vms */

	/* initialisation du terminal */
	/* -------------------------- */
	if ( seqinit == 1 ) { _co_capacite(SET_TERM); }

#ifdef	_CICO_MIMO
	CicoMimo.state = 0;
#endif
	/* positionnement curseur */
	_co_pos(courant->ligne, courant->colonne);

#ifdef	EXABAL
#ifdef	IMPLOC
	initialise_local_lo( ENTER_LOCAL, EXIT_LOCAL );
#endif
#endif
	/* cursor allumee */
	atb(26);
	if (!( pushpopid )) {
		initialise_pushpop();
		initialise_printscreen();
		}

	return;


}


/* fin d'execution : remettre le terminal en etat
 * ----------------------------------------------
 *
 * appel:	VOID finterm(type);
 *		WORD type = type de fermeture (0 definitive, != 0 temporaire)
 *
 * retour:	rien
 *
 */
VOID finterm(type)
WORD type;
{
	register i;

#ifdef	_MOUSE_TRACE
	if ( MouseTrace ) {
		fclose(MouseTrace);
		MouseTrace = (FILE*) 0;
		}
#endif
#ifdef	_KEYB_TRACE
	if ( KeybTrace ) {
		fclose(KeybTrace);
		KeybTrace = (FILE*) 0;
		}
#endif

	/* 31/08/94 */
	/* Toujours retour au jeu primaire avant finterm */
	/* pour eviter une desynchro due au load.go */
	exit_second();

#ifdef	EXABAL
	/* fermeture des imprimantes */
	if (type == 0) terminate_pushpop();
	if (type == 0) finform();
#endif
	/* finterm partiel */
	flag_finterm = TRUE;

	/* vidage du buffer de sortie */
	x_bflush();

	/* fin des attributs en cours */
	atb(0);

	/* sortie du jeu de caractere secondaire */
	if (flag_second == TRUE)
		_co_capacite(EXIT_SECOND);

	/* curseur allume */
	atb(26);

	/* reinitialisation du terminal */

#ifdef	EXABAL
	if ( type == 0 ) {
#ifdef	_CICO_MIMO
	if ( CicoMimo.state ) {
		if ( CicoMimo.stop ) {
			_co_capacite(CicoMimo.stop);
			}
		CicoMimo.state = 0;
		}
#endif
	}
#endif
	if ( seqinit == 1 ) {
		_co_capacite(RESET_TERM);
	}

#ifdef CICO_DEBUG
	fclose(DEBUG);
#endif /* fin CICO_DEBUG */

#ifdef vms
	vms$set_def_term();
	vms$fcntl(STDIN, F_SETFL, O_RDONLY);
#else

#ifdef SHAREDLO
	if (resetterm != 0)
	{
#endif /* SHAREDLO */
	/* fin pour le clavier */
	ioctl(STDIN, TCSETA, &confterm);
	fcntl(STDIN, F_SETFL, O_RDONLY);
#ifdef SHAREDLO
	}
#endif /* SHAREDLO */
#endif /* vms */
}

/* modification terminal : envoie des sequences init/fin TERM ou pas
 * -----------------------------------------------------------------
 *
 * appel:	VOID modterm(etat);
 *		WORD etat = TRUE  si envoie des sequences init/fin TERM
 *			    FALSE sinon
 * retour:	rien
 *
 */
VOID modterm(etat)
WORD etat;
{
	seqinit = etat;
}

/* sortie avec erreur de initerm
 * -----------------------------
 *
 * appel:	numero de message d'erreur
 *
 * retour:	rien
 *
 */
static VOID erreur(err_no, name, fh)
WORD err_no;
BYTE *name;
{
	/* affichage d'un message d'erreur sur erreur standard */
	write(STDERR, "cico: ", 6);
	write(STDERR, message[err_no], (unsigned)strlen(message[err_no]));
	if (name != NULL)
		write(STDERR, name, (unsigned)strlen(name));
	write(STDERR, "\n", 1);

	/* liberation access */
#if EXABAL && !vms
	PurgeLox();
#endif /* EXABAL && !vms */

	/* fermeture du fichier parametre */
	if (fh > 0)
		cicoclose(fh);

	/* Liberate File Manager */
#ifdef EXABAL       
//#BG 22/11/11	si_fin();
	MA_fin();
#endif
	/* fin de process avec status */
	exit(1);
}

BYTE	*	x_capacity(n)
WORD 	n;
{
	return( term_str[n] );
}

BYTE	*	x_table(n)
WORD 	n;
{
	switch (n) {
		case	0 :	return( paranom );
		case	1 :	return( tab_in );
		case 	2 :	return( tab_out );
		default	  :	return((char *) 0);
		}
}

void	select_cico_ecran()
{
	prndest=1;
	return;
}

#ifdef USEIT
int get_useit_version(void)
{
	char tmp[256];		/* Commande a executer			*/
	char szFile[30];	/* Nom du fichier temporaire 		*/
	int iH;				/* Descripteur du fichier temporaire	*/
	FILE *pFS;			/* Handle de fichier resultat		*/
	char* p;
	char* v;
	WORD	fin = 0;
	int	version = 0;
	
	// Creation du fichier temporaire 
	memset(szFile, 0x00, 30);
	sprintf(szFile, "/tmp/useitver_XXXXXX");
	iH = mkstemp(szFile);
	if (iH != -1)
	{
		/* Execute la commande de recuperation de version du systeme Use IT*/
		sprintf(tmp, "/usr/bin/version -v > %s 2>/dev/null", szFile);
		if ( ! (system(tmp)) )
		{
			/* Commande OK, on ouvre le fichier resultat	*/
			pFS = fdopen(iH, "rb+");
			if (pFS)
			{
				do
				{
					/* On peut rechercher la version de UseIT */
					p = fgets(tmp, sizeof(tmp), pFS);
					if (p)
					{
						p = strchr(tmp, '\n');
						if (p)
							*p = 0;
							
						// Recherche de la chaine "Version"
						p = strstr(tmp, "Version");	
						if (p)
						{
							// Le format est "Version m.n[n]"
							strcpy(p, p+8);
							v = strtok(p, ".");
							if (v)
								version = atoi(v);
						}							
					}
					else
					{
						fin = 1;
					}
				}
				while (!fin);
			}
			/* Fermeture du fichier temporaire */
			fclose(pFS);
		}
		/* Suppression du fichier temporaire */
		unlink(szFile);
	}

	return version;
}
#endif /* USEIT */

/* fin de fichier */
/* -------------- */


