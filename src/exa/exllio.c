/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLLIO - C				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	04/02/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Low-Level IO for Amenesik / Sologic and DOS				*/
/*	---------------------------------				*/
/*	VERSION 1.4A BUFFERISED CICO					*/
/* 	----------------------------					*/

#include "ex.h"
#include "exfich.h"
#include "experm.h"
#include "abalcico.h"

extern	struct fichdt PTR AssignTable;
extern	EX_FILE_HANDLE prnfid;
extern	EXAWORD sicico;
#define	MAXIO	33

#define	IoStdState	1	/* Standard Output State		*/
#define	IoEscState	2	/* Escape State waiting			*/
#define	IoExtState	4	/* Extended State			*/
#define	IoExtState2	5	/* Extended State 2			*/
#define	IoBypass	8	/* Transparant output mode		*/
#define	IoHexDump	16	/* Hexadecimal dump mode		*/

EXAWORD	IoCol[MAXIO];		/* Current Column Count			*/
EXAWORD	IoLin[MAXIO];		/* Current line count			*/
EXAWORD	IoFlg[MAXIO];		/* Current Device status		*/
EXAWORD	IoArg[MAXIO];		/* Bypass packet length counter		*/
EXABYTE	IoTru[MAXIO];		/* Flags indicating usage		*/
#ifdef	ABAL14
EXAWORD	EscapeConsole;
EXAWORD	EscapeTlength;
EXAWORD	cico_use_mes;
EXAWORD	cico_use_abqt;
#endif

#ifdef	ABAL14 
EXAWORD	cico_bufferise;		/* Indicates buffering active		*/
EXAWORD	cico_buffer_index;	/* Buffer Index				*/
EXABYTE	cico_buffer[256];	/* CICO buffer				*/
EXAWORD	IoFlag;			/* Indicates IO Status to Printer LO	*/
#endif

/*	LL CO   management function prototypes		*/
/*	--------------------------------------		*/

VOID	x_putch();		/* Output Character to Device 	*/
VOID	pos();			/* Position [Line,Column]	*/
EXAWORD	x_lin();		/* Consult Line Number		*/
EXAWORD	x_col();		/* Consult Column Number	*/
VOID	atb();			/* Establish CO/LO Attribut	*/

/*	I N I T E R M ( )
 *	-----------------
 *	Initialisation of terminal and terminal management
 *
 */

EXAWORD	initerm()
{
	EXAWORD	x;

	/* Initialise local Table */
	/* ---------------------- */
	for (x=0; x<MAXIO; x++) { 
		IoCol[x] = 1; 	
		IoLin[x] = 1; 
		IoFlg[x] = IoStdState; 
		IoTru[x] = 0;
		}

#ifdef	ABAL14
	EscapeConsole = 0;	/* Standard character mode 	*/
	EscapeTlength = 0;	/* Escape T length ZERO		*/
#endif

	/* Initialise low level controller */
	/* ------------------------------- */
	initcico();

#ifdef	ABAL14

	/* Bufferisation OFF */
	/* ----------------- */
	cico_bufferise    = 0;
	cico_buffer_index = 0;
#endif

	/* Return to Caller */
	/* ---------------- */
	return(0);
}


#ifdef	ABAL14

/*
 *	X _ B S T A R T ( )
 *	-------------------
 *	Activate bufferised CICO if not already active.
 *
 */

VOID	x_bstart()
{
	/* Indicate Active bufferisation */
	/* ----------------------------- */
	if (!( cico_bufferise )) {
		cico_bufferise = cico_use_mes; 
		cico_buffer_index = 0; 
		}
	return;
}

/*
 *	X _ B F L U S H ( )
 *	-------------------
 *	Flush any bufferised CICO data and dis-activate bufferisation.
 *
 */

VOID	x_bflush()
{
	/* if Bufferisation currently active */
	/* --------------------------------- */
	if ( cico_bufferise ) {

		/* If Buffer contains bufferised data */
		/* ---------------------------------- */
		if ( cico_buffer_index > 0 ) {

			/* Terminate Bufferised Data */
			/* ------------------------- */
			cico_buffer[cico_buffer_index] = 0;

			/* Output Bufferised data via MES */
			/* ------------------------------ */
			xprl_mes((BPTR) cico_buffer , cico_buffer_index );

			/* Reset buffer index */
			/* ------------------ */
			cico_buffer_index = 0;

			}

		/* Dis-activate bufferisation */
		/* -------------------------- */
		cico_bufferise = 0;

		}

	/* Return to Caller */
	/* ---------------- */
	return;
			
}
#endif

/* 
 *	X _ P U T C H ( c )
 *	-------------------
 *	Output (direct or bufferised) of one character to
 *	the currently selected output device. (prndest)
 *
 */


VOID	x_putch( c )
EXAWORD	c;
{
	/* If Requested device is the screen */
	/* --------------------------------- */
	if ( prndest == 1 ) {

#ifdef	ABAL14
		if ( cico_use_mes ) {

			switch ( EscapeConsole ) {

				case 0 :	/* Nothing Waiting */
						/* --------------- */
						if (( c == 0 ) || ( c == 3 )) {
							x_bflush();
							prl_direct_co( c );	
							x_bstart();
							}
						else	{
							if ( c != 0x01B )	prl_co( c );
							else			EscapeConsole = 1;
							}
						return;

				case 1 :	/* Escape Waiting */
						/* -------------- */
						if ( c != 'T' ) {
							prl_co( 0x001B );
							prl_co( c );
							EscapeConsole = 0;
							}
						else	{
							x_bflush();
							prl_direct_co( 0x001B );
							prl_direct_co( 'T' );
							EscapeConsole = 2;
							}				 
						return;

				case 2 :	/* Awaiting Esc T first length byte */
						/* -------------------------------- */
						prl_direct_co( c );
						EscapeTlength = (c & 0x00FF);
						EscapeConsole = 4;
						return;

				case 4 :	/* Awaiting Esc T first length byte */
						/* -------------------------------- */
						prl_direct_co( c );
						EscapeTlength |= ((c & 0x00FF) << 8);
						if ( EscapeTlength != 0 )
							EscapeConsole = 8;
						else	EscapeConsole = 0;
						return;

				case 8 :	/* Escape T Mode is Active */
						/* ----------------------- */
	
						prl_direct_co( c );
						EscapeTlength--;
						if ( EscapeTlength == 0 ) {
							EscapeConsole = 0;
							x_bstart();
							}
				default :
						return;

				}
			}
		else	{
#endif
			/* Output byte and return */
			/* ---------------------- */
			prl_co( c );  
			return; 
#ifdef	ABAL14
			}
#endif
		}

	/* If Requested Device is memory */
	/* ----------------------------- */
	if ( prndest == 0 ) { 

		/* Print to memory if able then return */
		/* ----------------------------------- */
		if ( prnleng > 0 ) { *(prnptr++) = (EXABYTE) c; prnleng--; }
		return;

		}
	/* Ensure file handle does not exceed limits */
	/* ----------------------------------------- */
	if ( prndest > 32 ) {
		err_val = 40;
		return;
		}

	/* DEVICE must be a printer : Perform ESC character analysis */
	/* --------------------------------------------------------- */
	switch ((IoFlag = IoFlg[prndest])) {

		/* Currently in Non-Escaped Standard state */
		/* --------------------------------------- */
		case	IoStdState :

			/* Selectivly filter special characters */
			/* ------------------------------------ */
			switch ( c ) {

				case	0x0007 :	/* BELL */
					return;

				case	0x000C :	/* PAGE	*/
				case	0x001C :	/* HOME */
					IoTru[prndest] = 1;
					lo(c); lo(0x000D);
					IoCol[prndest] = 1; IoLin[prndest] = 1;
					return;

				case	0x000D :	/*  RC  */
					IoCol[prndest] = 1; break;

				case	0x000A :	/*  LF  */
					IoTru[prndest] = 1;
					lo(c); lo(0x000D);
					IoLin[prndest]++; IoCol[prndest] = 1;
					return;

	/*	For Real TABULATION management
	 *	------------------------------
	 *			case	0x0009 :	** TAB  **
	 *				do { x_putch(' '); }
	 *				while (( IoCol[prndest] % 8 ) != 0); 
	 *				return;
	 *
	 *	Remarque : BAL does not manage the Tabulation character
	 *		   during printer output.
	 *	Exemple  : Print=2:tabv(1),chr$(9),"."
	 *		   X = Col(2) =>> Value of X is 3 not 10 !!!!!	
	 */

				case	0x0008 :	/*  BS  */
					if (--IoCol[prndest] < 1 )
						IoCol[prndest] = 1;
					break;

				case	0x001B :	/* ESC  */
					IoFlg[prndest] = IoEscState;
					return;
/*			break;	*/

				case    0x001A  : /* Fermeture Imprimante */
						  /* -------------------- */

					/* If Something has been printed */
					/* ----------------------------- */
					if ( IoTru[prndest] != 0 ) {

						/* Send Close Spool Commande */
						/* ------------------------- */
						lo( c );

						/* Indicate Printer Closed */
						/* ----------------------- */
						IoTru[prndest] = 0;
						}

					/* Return Direct to Caller */
					/* ----------------------- */
					return;

				case	0x0006  : c = ' ';

				default		: IoCol[prndest]++;

				}

				break;

		/* Currently in ESCAPE STATE : Check Escape code value */
		/* --------------------------------------------------- */
		case	IoEscState :

			IoFlg[prndest] = IoStdState;
			switch ( c ) {
				case 'T' :	/* Request for Transparant */
					IoFlg[prndest] = IoExtState;
					return;
				default	 :
					lo( 0x001B );
					break;
				}
			break;

		/* PRIMARY EXTENDED ESCAPE state */
		/* ----------------------------- */
		case	IoExtState :
			IoArg[prndest] = c; 
			IoFlg[prndest] = IoExtState2;
			return;
/*	break;	*/

		/* SECONDARY EXTENDED ESCAPE state */
		/* ------------------------------- */
		case	IoExtState2:
			IoArg[prndest] += ( c * 256 );
			if (IoArg[prndest] != 0) {
				lo(0x001B);
				lo('T');
				lo((IoArg[prndest] & 0x00FF ));
				IoFlg[prndest] = IoBypass;
				}
			else	{
				IoFlg[prndest] = IoStdState;
				return;
				}
			break;

		/* HEXDECIMAL DUMP STATE */
		/* --------------------- */
		case	IoHexDump  :

		/* Currently in Transparent Mode */
		/* ----------------------------- */
		case	IoBypass   :

			/* Send Character to Printer */
			/* ------------------------- */
			lo(c);
	
			/* Test for Error */
			/* -------------- */
			if ( err_val == 0 ) {

				IoTru[prndest] = 1;

				/* Decrement and Transmit Character untouched */
				/* ------------------------------------------ */
				if (( --IoArg[prndest] ) == 0 )

					/* Transparence over return to NORMAL state */
					/* ---------------------------------------- */
					IoFlg[prndest] = IoStdState;

				}

			return;

		}

	/* Send Character to Printer */
	/* ------------------------- */
	lo(c);

	/* Test for Error */
	/* -------------- */
	if ( err_val == 0 ) 
		IoTru[prndest] = 1;

	/* Return to Caller */
	/* ---------------- */
	return;
}

/*
 *	X _ C P R I N T F ( sptr )
 *	--------------------------
 *	Peforms repeated XPUTCH output of characters in string
 *	until NUL character is reached.
 *	Function is provided for STRING MESSAGE OUTPUT
 *	
 */

VOID	x_cprintf( sptr )
BPTR	sptr;
{
	/* Output via X_PUTCH until end of string */
	/* -------------------------------------- */
	while ( *sptr != (EXABYTE) 0 ) 
		x_putch( *(sptr++) );

	/* Return to caller */
	/* ---------------- */
	return;
}

VOID	prnclear()
{
	char	lobuff[16];
	EXAWORD	x;
	EXAWORD	holdtrap;

	holdtrap = sicico; sicico |= ONSEM_TRP;
	for ( x = 2; x < MAXIO; x++ ) {
		if ( IoTru[x] != 0 ) {
			if (( (*(AssignTable +x)).permf & NGF_TYP ) == NGF_IM ) {
				prndest = x; 
				IoFlag = IoFlg[ prndest ];
				if ((prnfid = (*(AssignTable + x)).unlog) == EX_UNUSED_HANDLE)
					prnfid = 0;
				if ( (prnptr = (*(AssignTable + x )).asptr) == (BPTR) 0 ) {
					prnptr  = (BPTR) lobuff;
					prnleng = 16;
					prndex  = 0;
					}
				else	{
					prnleng = (*(AssignTable + x)).aslen;
					prndex  = (*(AssignTable + x)).mcext;
					}
				lo( 0x001A);
				(*(AssignTable + x)).unlog = EX_UNUSED_HANDLE;
				}
			else	{
				if ( x == 2 ) {
					prndest = 2; prnfid = 0;
					lo( 0x001A);
					}
				}
			}
		}
	prndest = 1; prnfid = 0;
	sicico  = holdtrap;
	return;
}

EXAWORD	x_col()
{
	switch ( prndest ) {
		case 0  :	return(prndex);
		case 1  :	x_bflush();
				return(xprl_col());
		default :	return(IoCol[prndest]);
		}
}

EXAWORD	x_lin()
{
	switch ( prndest ) {
		case 0  :	return(1);
		case 1  :	x_bflush();
				return(xprl_lin());
		default :	return(IoLin[prndest]);
		}
}

VOID	pos(lno,cno)
EXAWORD	lno,cno;
{
	switch ( prndest ) {
		case	0 : 		       return;
		case 	1 : xprl_pos(lno,cno); return;
		default   : 
			if ( cno == IoCol[prndest] )   
				return;	  
			if ( cno <  IoCol[prndest] )   
				x_putch(0x000D);
			while ( cno > x_col() ) 
				x_putch(' ');	  
			return;
		}
}

VOID	atb( atbid )
EXAWORD	atbid;
{
	switch ( atbid ) {
		case 0 : atbid = 'a'; break;
		case 1 : atbid = 'p'; break;
		case 2 : atbid = 'b'; break;
		case 3 : atbid = 'c'; break;
		case 4 : atbid = 'd'; break;
		case 5 : atbid = 'e'; break;
		case 6 : atbid = 'h'; break;
		case 7 : atbid = 'i'; break;
		case 8 : atbid = 'j'; break;
		case 9 : atbid = 'O'; break;
		case 10: atbid = 'y'; break;
		case 11: atbid = 'z'; break;
		case 12: atbid = 'k'; break;
		case 13: atbid = 'l'; break;
		case 14: atbid = 'm'; break;
		case 15: atbid = 'n'; break;
		case 16: atbid = 'q'; break;
		case 17: atbid = 'r'; break;
		case 18: atbid = 's'; break;
		case 19: atbid = 't'; break;
		case 20: atbid = 'Q'; break;
		case 21: atbid = 'K'; break;
		case 22: atbid = 'J'; break;
		case 23: atbid = 'L'; break;
		case 24: atbid = 'M'; break;
		case 25: atbid = 'w'; break;
		case 26: atbid = 'v'; break;
		case 27: atbid = '*'; break;
		case 28: atbid = '#'; break;
		case 29: atbid = 'x'; break;
		case 30: atbid = '>'; break;
		case 31: atbid = '<'; break;
		default: return;
		}
	x_putch(0x001B); x_putch( atbid );
	return;
}

EXAWORD	ShitCatcher(atbid)
EXAWORD	atbid;
{
	atbid = 2;
	switch ( atbid ) {
		case 0 : atbid = 'a'; break;
		case 1 : atbid = 'p'; break;
		case 2 : atbid = 'b'; break;
		case 3 : atbid = 'c'; break;
		case 4 : atbid = 'd'; break;
		case 5 : atbid = 'e'; break;
		case 6 : atbid = 'h'; break;
		case 7 : atbid = 'i'; break;
		case 8 : atbid = 'j'; break;
		case 9 : atbid = 'O'; break;

		}
	return(atbid);
}

