
/*
 *	-------------------------------------------------------------------
 *	PROJECT	:	ABAL for USE IT		or 	USE IT for ABAL	
 *	------------------------------------------------------------------- 
 *
 * 	FILE	:	EXCICO.C
 *
 *	DATE	:	04/10/2001	
 *
 *	BY	:	Iain James Marshall
 *
 *	WHY	:	This file has been created to normalise the CICO
 *			recurring nightmare code into something that most
 *			regular zombies will be able to handle.
 *			No offence meant, Zombie mode is active !
 *
 *	HOW	:	The ABAL tools all use the standard 
 *			CICO function interface calls for the
 *			activation of the corresponding console input
 *			output function.
 *			The idea is quite simple :
 *
 *				- the operational CICO function must be
 *				made available to the ABAL tool, and to
 *				any cooperating bits of code, dynamic
 *				libraries etc.
 *
 *				- The initiating tool will instance a
 *				CICO access controller and the usual
 *				standard CICO interface functions.
 *
 *				- These interface functions will simply
 *				activate the relevant relay in the CICO
 *				access controller.
 *
 *				- The redirection controller of a dynamic
 *				library will exchange its offered relays for
 *				those of the hosting tool.
 *
 */

#ifndef	_excico_c
#define	_excico_c

#include "bda_std.h"

/*	-----------------------------------------------------		*/
/*	Prototype definitions of the low level CICO functions		*/
/*	-----------------------------------------------------		*/
#ifdef	_PROTOTYPES
WORD	local_x_getch();
WORD	local_x_kbhit();
WORD	local_x_prfo(WORD,BYTE *, WORD);
WORD	local_x_lcfo(WORD,BYTE *, WORD);
WORD	local_x_conf(WORD);
WORD	local_x_putch(WORD);
WORD	local_x_cprintf(BYTE *);
WORD	local_x_lin();
WORD	local_x_col();
WORD	local_x_bstart();
WORD	local_x_bflush();
#ifdef	EXABAL
WORD	local_x_lo(WORD);
#endif
WORD	local_x_mima(WORD,WORD);
WORD	local_x_event(WORD);
WORD	local_x_graph(WORD,VOID *);
WORD	local_x_callback(WORD,VOID *);
#else /* ! PROTOTYPES */
WORD	local_x_getch();
WORD	local_x_kbhit();
WORD	local_x_prfo();
WORD	local_x_lcfo();
WORD	local_x_conf();
WORD	local_x_putch();
WORD	local_x_cprintf();
WORD	local_x_lin();
WORD	local_x_col();
WORD	local_x_bstart();
WORD	local_x_bflush();
#ifdef	EXABAL
WORD	local_x_lo();
#endif
WORD	local_x_mima();
WORD	local_x_event();
WORD	local_x_graph();
WORD	local_x_callback();
#endif	/* PROTOTYPES */


#ifndef	EXABAL
WORD	local_x_bidon(v)
WORD	v;
{ 
	return(0); 
}
#endif


/*	--------------------------------------		*/
/*	Elements of the CICO Access Controller		*/
/*	--------------------------------------		*/

int	AccessControllerLock=0;

struct	cico_access_controller	{
	WORD   	FunctionCount;
	WORD  (*FunctionRelay[CICO_NOMBRE])();

	} CicoAccessController = { 0,0 };

/*	--------------------------------------		*/
/*	 Access Controller Protection Locking  		*/
/*	--------------------------------------		*/
void	lock_access_controller()
{
	AccessControllerLock = 1;
	return;
}

void	unlock_access_controller()
{
	AccessControllerLock = 0;
	return;
}

int	islocked_access_controller()
{
	return( AccessControllerLock );
}

/*	--------------------------------------		*/
/*	Access Controller Basic Initialisation		*/
/*	--------------------------------------		*/

void	initialise_access_controller()
{
	if ( AccessControllerLock != 0 ) { return; }

	CicoAccessController.FunctionCount = CICO_NOMBRE;

	CicoAccessController.FunctionRelay[CICO_CI] 		= (VOID*) local_x_getch;
	CicoAccessController.FunctionRelay[CICO_TPCI]		= (VOID*) local_x_kbhit;
	CicoAccessController.FunctionRelay[CICO_PRFO] 		= (VOID*) local_x_prfo;
	CicoAccessController.FunctionRelay[CICO_LCFO] 		= (VOID*) local_x_lcfo;
	CicoAccessController.FunctionRelay[CICO_CONF] 		= (VOID*) local_x_conf;
	CicoAccessController.FunctionRelay[CICO_CO] 		= (VOID*) local_x_putch;
	CicoAccessController.FunctionRelay[CICO_MES] 		= (VOID*) local_x_cprintf; 
	CicoAccessController.FunctionRelay[CICO_LIGNE] 		= (VOID*) local_x_lin; 
	CicoAccessController.FunctionRelay[CICO_COLONNE]	= (VOID*) local_x_col; 
	CicoAccessController.FunctionRelay[CICO_START] 		= (VOID*) local_x_bstart; 
	CicoAccessController.FunctionRelay[CICO_FLUSH] 		= (VOID*) local_x_bflush; 
#ifdef	EXABAL
	CicoAccessController.FunctionRelay[CICO_LO] 		= (VOID*) local_x_lo;
#else
	CicoAccessController.FunctionRelay[CICO_LO] 		= (VOID*) local_x_bidon;
#endif
	CicoAccessController.FunctionRelay[CICO_MIMA] 		= (VOID*) local_x_mima;
	CicoAccessController.FunctionRelay[CICO_EVENT]		= (VOID*) local_x_event;
	CicoAccessController.FunctionRelay[CICO_INIT] 		= (VOID*)  0;	
	CicoAccessController.FunctionRelay[CICO_GRAPH] 		= (VOID*) local_x_graph;	
#ifdef	EXABAL
	CicoAccessController.FunctionRelay[CICO_CALLBACK] 	= (VOID*) local_x_callback;	
#else
	CicoAccessController.FunctionRelay[CICO_CALLBACK]	= (VOID*) local_x_bidon;
#endif
   	return;
}

/*	-------------------------------------------------	*/
/* 	This function is provided to  perform redirection	*/
/*	--------------------------------------------------	*/

void *	redirect_access_controller(item,fptr)
int	item;
void *	fptr;
{
	void	*	vptr=(void *) 0;
	if ((item >= 0) && ( item < CicoAccessController.FunctionCount ))
		{
		vptr = CicoAccessController.FunctionRelay[item];
		if ( fptr != (void *) 0 )
			CicoAccessController.FunctionRelay[item] = fptr;
			
		}
	return( vptr );
}

/*	The CICO Interface functions 		*/
/*	----------------------------		*/
/*	These functions simply call through	*/
/*	on the corresponding relay		*/
/*	These relays will have been set by	*/
/*	the initialisation code, or the		*/
/*	redirection code.			*/

WORD	x_getch() 
{ 
	if (!( CicoAccessController.FunctionRelay[CICO_CI] ))
		return(27);
	else	return( (CicoAccessController.FunctionRelay[CICO_CI])() ); 
}

WORD	x_kbhit() 
{ 
	if (!( CicoAccessController.FunctionRelay[CICO_TPCI] ))
		return(0);
	return( (CicoAccessController.FunctionRelay[CICO_TPCI])() ); 
}

WORD	x_putch(c)
WORD 	c; 
{ 
	if (!( CicoAccessController.FunctionRelay[CICO_CO] ))
		return(0);
	else if ( prndest == 1 )
		return( (CicoAccessController.FunctionRelay[CICO_CO])(c) ); 
	else	return( local_x_putch(c) );
}

WORD	lcfo(n,buffer,blen)
WORD 	n;
BYTE * buffer;
WORD blen;
{ 
	if (!( CicoAccessController.FunctionRelay[CICO_LCFO] ))
		return(0);
	else 	return( (CicoAccessController.FunctionRelay[CICO_LCFO])(n,buffer,blen) ); 
} 

WORD	prfo(n,buffer,blen)
WORD 	n;
BYTE * buffer;
WORD blen;
{ 
	if (!( CicoAccessController.FunctionRelay[CICO_PRFO] ))
		return(0);
	else	return( (CicoAccessController.FunctionRelay[CICO_PRFO])(n,buffer,blen) ); 
}

WORD	conf(item)
WORD item;
{
	if (!( CicoAccessController.FunctionRelay[CICO_CONF] ))
		return(0);
	else	return( (CicoAccessController.FunctionRelay[CICO_CONF])(item));
}
	
WORD	x_cprintf(mptr)
BYTE * mptr;
{
	if (!( CicoAccessController.FunctionRelay[CICO_MES] ))
		return(0);
	else if ( prndest == 1 )
		return( (CicoAccessController.FunctionRelay[CICO_MES])(mptr) );
	else	return( local_x_cprintf( mptr ) );
}

WORD	x_bstart()
{
	if (!( CicoAccessController.FunctionRelay[CICO_START] ))
		return(0);
	else if ( prndest == 1 )
		return( (CicoAccessController.FunctionRelay[CICO_START])() ); 
	else	return( local_x_bstart() );
}

WORD	x_bflush()
{
	if (!( CicoAccessController.FunctionRelay[CICO_FLUSH] ))
		return(0);
	else if ( prndest == 1 )
		return( (CicoAccessController.FunctionRelay[CICO_FLUSH])() ); 
	else	return( local_x_bflush() );
}

WORD	x_col()
{
	if (!( CicoAccessController.FunctionRelay[CICO_COLONNE] ))
		return(0);
	else if ( prndest == 1 )
		return( (CicoAccessController.FunctionRelay[CICO_COLONNE])() ); 
	else	return( local_x_col() );

}
WORD	x_lin()
{
	if (!( CicoAccessController.FunctionRelay[CICO_LIGNE] ))
		return(0);
	else if ( prndest == 1 )
		return( (CicoAccessController.FunctionRelay[CICO_LIGNE])() ); 
	else	return( local_x_lin() );
}

WORD	x_event(n)
int n;
{
	if (!( CicoAccessController.FunctionRelay[CICO_EVENT] ))
		return(0);
	else	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(n) ); 
}

WORD	x_graph(n,buffer)
int 	n;
char * buffer;
{
	if (!( CicoAccessController.FunctionRelay[CICO_GRAPH] ))
		return(0);
	else	return( (CicoAccessController.FunctionRelay[CICO_GRAPH])(n,buffer) ); 
}

WORD	x_callback(n,buffer)
int 	n;
char * buffer;
{
	if (!( CicoAccessController.FunctionRelay[CICO_CALLBACK] ))
		return(0);
	else	return( (CicoAccessController.FunctionRelay[CICO_CALLBACK])(n,buffer) ); 
}

WORD	_lo(c)
WORD 	c;
{
	if (!( CicoAccessController.FunctionRelay[CICO_LO] ))
		return(0);
	else 	return( (CicoAccessController.FunctionRelay[CICO_LO])(c) ); 
}

WORD	mima(c,mode)
WORD 	c;
WORD 	mode;
{
	if (!( CicoAccessController.FunctionRelay[CICO_MIMA] ))
		return(0);
	else	return( (CicoAccessController.FunctionRelay[CICO_MIMA])(c,mode) ); 
}

#endif	/* _excico_c */
	/* ---------- */


