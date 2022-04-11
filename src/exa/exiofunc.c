/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXIOFUNC.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 
#ifndef	_EXIOFUNC_C
#define	_EXIOFUNC_C

/* 03/01/97: Pour agf */
#include "pubagf.h"

#include "exio.h"
#include "exiof.h"
#include "extmp.h"
#include "exhotkey.h"

#ifdef	UNIX
WORD	cico_use_abqt=1;
#endif

#ifdef	ABALX11
int	exa_is_X11=0;
#endif

EXAWORD	CutKey=0;

#ifdef DEBUGGER
#include "exproto1.h"
#endif

#ifdef	PROLOGUE
EXTERN	EXAWORD	prologue_colour;
#endif

#ifdef UNIX
//#BG 24/05/19 16 couleurs de fond
extern int signature_version;
#endif

#ifdef	ABAL21
struct	ask_context {
	EXAWORD	Flags;
	EXAWORD	CurserFore;
	EXAWORD	CurserBack;
	EXAWORD	CurserAtb;
	EXAWORD	Start;
	EXAWORD	Finish;
	} AskContext;
#endif	
void	iof_backgr();
void	iof_foregr();
#ifdef	ABAL64
void	iof_backgr();
void	iof_foregr();
#endif
EXAWORD	iof_atb();

#ifdef	ABAL21
#ifdef	PROLOGUE
EXAWORD		prnmode;		/* Type of Printer Device		*/
LSEEKTYPE	prnseek;		/* Print file seek value		*/
#endif
#endif

#ifdef	LIBPRINT
#define SCOPE EXTERN
#else
#define	SCOPE
#endif

extern	EXAWORD	DbinitOk;	/* Debug Init Control Status		*/

EXAWORD	tabflg;			/*					*/
EXAWORD	preference;		/* Preferential Print Length		*/
EXAWORD	holdline;		/* TAB(Line) Tabulation Contoller	*/
#ifdef	ABAL_RTL
extern  EXAWORD	syskey[9];	/* Executeur Console curser Keys	*/
#else
EXAWORD	syskey[9];	/* Executeur Console curser Keys	*/
#endif
EXAWORD	LastErreur;		/* Last Tcode Error Adresse		*/
EXAWORD	sicico;			/* SI and CICO State Controller		*/
EXAWORD	MimaFlag;		/* ATB(7) and ATB(8) Follower		*/
EXAWORD	LangFlag;		/* Indicates Language Overloaded	*/
EXALONG	SystemError;		/* System specific actual error code	*/

EXAWORD	iof_format_string( BPTR fptr, EXAWORD flen );

#ifdef	UNIX
/* #BG 16/06/20
50 microsec => 5 ms pour eviter une conso CPU de 12% sur ON TIMER + ASK
Cette fct etait etrangement initialement ds exaigcri.c.
*/
VOID	abqt()
{
/* First way obsolete
	usleep(50);		// 50 microsec (_DEFAULT_YOUSLEEP): 12% CPU !
	usleep(5000);	// 5000 microsec = 5 millisec: 0,7% CPU
*/

/* Another way to do it */
	struct	timespec ts;
	ts.tv_sec  = 0;
	ts.tv_nsec = 5000000;	// 5000000 nanosec = 5 millisec
	nanosleep(&ts, (struct timespec *) 0);

/* Another way to do it
	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 5000;	// 5000 microsec = 5 millisec
	select(0, NULL, NULL, NULL, &tv);
*/
	return;
}
#endif

#ifndef	PROLOGUE
EXAWORD	LocalLink( nb )
EXAWORD	nb;
{
	switch ( nb ) {
		case XCOL  :	return(x_col());
		case XLIN  :	return(x_lin());
		case CONF2 :	return(conf(2));
		case CONF1 :	return(conf(1));
		}
	return(nb);
}
#endif

#ifdef	PROLOGUE
EXAWORD	prologue_foreground()
{
	return((prologue_colour & 15));
}

EXAWORD	prologue_background()
{
	return(((prologue_colour >> 8) & 7));
}
#endif

EXAWORD	GetAskMask()	{	return( askmask );		}
EXAWORD	GetEventMask()	{	return( get_mimo_mask() );	}

EXAWORD	AskInfos( nb )
EXAWORD	nb;
{
	EXAWORD	x;

	x_bflush();
	x = LocalLink( nb );
	if ( ll_ask_flag == 0 )
		x_bstart();
	return( x );
}

/*
 *	UniSys and Aix offer the possibility of blocking
 *	signals and then unblocking signals
 *	to avoid problems with TIMER/PRINT interaction
 */

#ifdef	UNISYS
#include <signal.h>
#endif
#ifdef	AIX
#include <signal.h>
#endif

#ifdef INTEL
#include "exprag0.h"
#endif

#ifndef UNIX
#ifndef	VMS
#ifndef DEBUGGER
#ifndef DOS
VOID	x_clear()
{
	if ( prndest == 1 ) 	{ x_putch(syskey[IO_CLS]); 	}
	else			{ x_putch(0x000C);		}
	return;
}
#endif
#endif
#endif
#endif

/*	Format Functions 	*/
/*	----------------	*/
#include "exfmt.c"

EXAWORD	get_cut_key()		{	return( CutKey );	}
VOID	set_cut_key(EXAWORD v)	{	CutKey=v; return;	}

/*
 *	L S Y S K E Y ( )
 *	-----------------
 *	Initialisation function Reads the systeme keys at startup
 *	for use in ASK , HOTKEYS and DEBUG Command Functions
 *
 */

VOID	lsyskey()
{
	EXAWORD	x;
	EXABYTE	kbfc[4];

	/* Read First Seven Systeme Keys */
	/* ----------------------------- */
	for ( x = 1; x <= 7; x++ ) {
		/* Reset Error Variable for Test */
		/* ----------------------------- */
		err_val = 0;
		/* Attempt to Read Function Key */
		/* ---------------------------- */
		lcfo(x,(BPTR) &kbfc[0], 1);
		/* If No Error Then Store Returned Value */
		/* ------------------------------------- */
		if ( err_val == 0 ) {
			syskey[x] = (EXAWORD) kbfc[0];
			}
		/* In Case Of Error Use Default Values */
		/* ----------------------------------- */
		else	{
			switch ( x ) {
/* Right Arrow  */		case 1 : syskey[x] = 0x06; break;
/* Left Arrow   */		case 2 : syskey[x] = 0x08; break;
/* Down Arrow   */		case 3 : syskey[x] = 0x0B; break;
/* Up Arrow     */		case 4 : syskey[x] = 0x05; break;
/* Home Key     */		case 5 : syskey[x] = 0x1C; break;
/* Clear Screen */		case 6 : syskey[x] = 0x0C; break;
/* Annulation   */		case 7 : syskey[x] = 0x01; break;
				}
			}
		}
	return;
}

/* 
 *	A S K V I S I ( c )
 *	-------------------
 *
 * 	Affichage sur l'Ecran avec controle du mode SECRET (MASK_SECRET)
 *	du caractere 'c' pendant la saisie d'ASK.
 *
 */
#ifdef	PROLOGUE
VOID	exputch( c )
EXAWORD	c;
{
	if ( MimaFlag & 1 )
		x_putch( minimaji( c ) );
	else if ( MimaFlag & 2 )
		x_putch( majimini( c ) );
	else	x_putch( c );
	return;
}
#endif

VOID askvisi(c)
EXABYTE	c;
{
	if ((askmask & MASK_SECRET) == 0) 
	exputch(c);
   return;
}

/*
 *	F M T A C T ( x )
 *	-----------------
 *	Gestion des Formats de PRINT et d'ASK
 *	
 *	Performs format ACTION elements : LF,TAB,ESP,PRN,ATB etc
 *	Returns environ or filter code to level - 1
 */


EXAWORD	fmtact( x )
EXAWORD	x;			/* Format Action Code	*/
{

				/* ---------------------------- */
	EXAWORD	dynasem;	/* Dynamic format Semaphore 	*/
	dynasem = 0;		/* Reset Dynamic Format		*/
				/* ---------------------------- */

do {
	switch ( x ) {		/* Select Format ACTION */
				/* -------------------- */
#ifdef	ABAL14
		case	FMT_DYN : dynasem = 1; break;
#endif
		case	FMT_LF	: exputch(IO_RC); 
				  x = (EXAWORD) *(fmtptr++);
#ifdef	ABAL14
			 	  if ((dynasem == 1 ) && ( dynadex < dynamax))
					x = dynamat [dynadex++];
				  dynasem = 0;
#endif
				  for ( ; x > 0; x-- )
					exputch(IO_LF); 
				  break;
		case	FMT_ESP	: x = (EXAWORD) *(fmtptr++);
#ifdef	ABAL14
			 	  if ((dynasem == 1 ) && ( dynadex < dynamax))
					x = dynamat [dynadex++];
				  dynasem = 0;
#endif
				  for ( ; x > 0; x--) 
					exputch(IO_ESP);

				  break;
		case	FMT_TAB	: x = (EXAWORD) *(fmtptr++);
#ifdef	ABAL14
			 	  if ((dynasem == 1 ) && ( dynadex < dynamax))
					x = dynamat [dynadex++];
				  dynasem = 0;
#endif
				  for ( ; x > 0; x--)
					exputch(IO_TAB);
				  break;	
		case	FMT_PR	: for (x = (EXAWORD) *(fmtptr++); x > 0; x-- )
				  	exputch(*(fmtptr++));
				  break;
		case	FMT_ATB	: x = (EXAWORD) *(fmtptr++);
#ifdef	ABAL14
			 	  if ((dynasem == 1 ) && ( dynadex < dynamax))
					x = dynamat [dynadex++];
				  dynasem = 0;
#endif
				  iof_atb( x );
				  break;
		case	FMT_H	: fmthex = 1; 
				  return( x );
		case	FMT_SEP	: break;
		case	FMT_DEB	: fmtdex = 0; break;
		case	FMT_FIN	: fmtflg &= 0xFFFC; fmtchk = 0; 
				  askmust = 0; 
		default		: if ( dynasem == 1 ) {
					while ((x = *fmtptr) != FMT_DYN ) 
						fmtptr--;
					dynasem = 0;
					}
				  return(x);
		}	
	x = (EXAWORD) *(fmtptr++);
	}
while ( x != FMT_FIN );
return(x);
}

/*
 *	E N V S T R ( x )
 *	-----------------
 *
 */

VOID envstr(x)
EXAWORD	x;
{
	EXAWORD	y,dolx,dynasem;
	EXAWORD	tempor;

	DollarLength = 0; y = 0;
	dynasem = 0;
do 	{	
	switch ( x ) {
#ifdef	ABAL14
		case FMT_INH :	InhibitZero = 1; break;
		case FMT_MNB :
#endif
#ifdef	ABAL21
		case FMT_PCH :
#endif
		case FMT_MCH : 	fmtptr++;
		case FMT_MIL : 	break;
		case FMT_ZER : 	zpadn = '*'; break;
		case FMT_ZCH : 	zpadn = *(fmtptr++); 
#ifdef	ABAL14
			 	if ((dynasem == 1 ) && ( dynadex < dynamax)) {
					zpadn = (EXABYTE) dynamat [dynadex++];
					}
				dynasem = 0;
#endif
				break;
#ifdef	ABAL21
		case FMT_Q   :	preference = *(fmtptr++);
			 	if ((dynasem == 1 ) && ( dynadex < dynamax)) {
					preference = (EXABYTE) dynamat [dynadex++];
					}
				dynasem = 0;
				break;
#endif	
		case FMT_JL  : 	fbcdc |= 0x8000; break;
		case FMT_JR  : 	fbcdc |= 0x4000; break;
		case FMT_STR : 	fmtbass(1); DollarLength = worklen1;break; 
		case FMT_DOL : 	DollarLength = lenuse(workptr1,worklen1);
			       	worklen1 = DollarLength; break;
		case FMT_DCH : 	tempor   = *(fmtptr++);
#ifdef	ABAL14
			 	if ((dynasem == 1 ) && ( dynadex < dynamax))
					tempor = (EXABYTE) dynamat [dynadex++];
				dynasem = 0;
#endif
				for (DollarLength = 0, dolx = worklen1 ; dolx > 0; dolx--, DollarLength++ )			       	
					if ( *(workptr1 + DollarLength) == (EXABYTE) tempor ) 
						break;
			       	worklen1 = DollarLength; 
			       	break;
		case FMT_DYN : 	dynasem = 1; break;
#ifdef	ABAL14
		case FMT_H   :	/* Hexa Display    (Normally Numeric) */
				fmthex = 1; break;
		case FMT_O   :	/* Optimal display (Normally Numeric) */ 
#endif
		case FMT_K   :
		case FMT_U   :
		case FMT_A   :
		case FMT_W   :
		case FMT_B   :
		case FMT_C   :
		case FMT_D   :
		case FMT_Z   :
		case FMT_N   : 	if ((dynasem == 1 ) && ( dynadex < dynamax)) {
					DollarLength += dynamat [dynadex++];
					fmtptr++; dynasem = 0; 
					break;
					}
			       	if ( *fmtptr == (EXABYTE) 0 ) { 
					DollarLength += 256; fmtptr++; 
					}
			       	else 	DollarLength += (EXAWORD) *(fmtptr++); 
			       	dynasem = 0; 
			       	break;
		case FMT_SEP : 	y = 1; continue;
		case FMT_FIN : 	y = 1; fmtflg &= 0xFFFC; continue;
		default	     : 	y = 1; continue;
		}
	x = (EXAWORD) *(fmtptr++);
	}
while ( y == 0 );
return;
}

/*
 *	I F O R M ( )
 *	-------------
 *	Initialisation des Format Numeriques par defaut
 *
 *	'Format Libre'
 *	--------------
 *
 *	#		:	-3Z
 *	%		:	-5Z
 *	B.C.D		:	-14Z.N14
 *
 */

VOID	iform( wtyp )
EXAWORD	wtyp;
{
	switch ( wtyp ) {
		case VARB_BCD  :
			fbcdc  = 0x1100;	/* Decimal place and sign required */
			fbcde  = 15 ; fbcdf = 14;
			fmtdex = 3  ; break;
		case VARB_INT64 :
		case VARB_INT32 :
		case VARB_INT16 :
		case VARB_INT8  :
		case VARB_FOUR  :
			fbcdc = 0x0100;
			fbcde = (worklen1 * 2 ) + 2;
			fbcdf = 0; fmtdex = 2;
			break;
		}
	fbcdp  = ' '   ; fbcdm  = '-';
	fbcdd  = sepdec; fbcdxe = ' ';
	fbcdxf = ' '   ; zpadn  = ' ';
	fmtmil = ' '; fbcdv = 0;
	if ( fmtdex == 3 ) {
		fmthld[0] = (FMT_N | 0x0040); 
		fmtgod[0] = fbcde - 1;
		fmthld[1] = FMT_Z; 
		fmtgod[1] = 1;
		fmthld[2] = FMT_N; 
		fmtgod[2] = fbcdf; 
		}
	else 	{
		fmthld[0] = (FMT_N | 0x0040); 
		fmtgod[0] = ( fbcde - 2 ) + 1;
		fmthld[1] = FMT_Z; 
		fmtgod[1] = 1;
		}
	fmtmax = fmtdex;
	return;
}

/*
 *	U F O R M ( x )
 *	---------------
 *	Format filter matrix management for PRINT
 *
 *	X is the format character to place in the matrix
 */

VOID	uform(fmx,dynasem)
EXAWORD	fmx,dynasem;
{
	EXAWORD	x;
	if (( dynasem == 1 ) && ( dynadex < dynamax )) {
		x = dynamat [dynadex++]; 
		fmtptr++;
		if ( x == 0 ) 
			return;
		}
	else	x = (EXAWORD) *(fmtptr++);
	fmthld[fmtdex] = fmx;
	fbcdc |= (fmx & 0x0040) << 5;
	switch ( fbcdc & 0x3000 ) {
		case 0x1000	:	/* Partie reelement decimale 	*/
					fbcdf += x; break;
		case 0x0000	:	/* Partie Encore entier		*/
					fbcde += x; break;
		case 0x2000	:	/* Partie suplimentaire V interne */
					fbcdv += x; break;
		}
	fmtgod[fmtdex++] = x;		/* Save filter character counter */
	return;
}

/*
 *	E N V N U M ( x )
 *	-----------------
 *	Analyses du chaine de formatage pour affiche Numerique (Int ou BCD)
 *
 *	Le variable de resultat / control FBCDC etant comme ci-dessous
 *
 *	15	14	13	12	11	10	9	8
 *	+---+---+	|	|			|	+-- Affichage
 *	    |		|	|			|	    du signe
 *	    |		|	|			|
 *	    |		|	|			+---------- Separateur
 *	    |		|	|				    milliers
 *	    |		|	|
 *	    |		|	+------------- Presence d'un separateur Decimal
 *	    |		|
 *	    |		+--------------------- Separateur Type Interne/Externe
 *	    |
 *	    +--------------------------------- Justification Droit / Gauche
 *
 *	15 	14
 *	----------		
 *	0 	0		No justification ( defaut )
 *	0 	1		Justify Right
 *	1 	0		Justify Left
 *	1 	1		Justify Centered
 *	----------
 *
 *	Les bits 7 - 0 representant la nombre d'elements dans la matrice
 *	du formatage a prendre en compte pendant l'affichage
 *
 */

VOID envnum(xx)
EXAWORD	xx;
{
	register EXAWORD	y,x;
		 EXAWORD	dynasem;

	fmtdex = 0; dynasem = 0;	
	fbcdc  = 0; fbcde   = 0; 
	fbcdf  = 0; fbcdv   = 0;
	InhibitZero = 0;

	zpadn = ' '; fbcdp  = ' ';  y = 0; 
	fbcdm = ' '; fmtmil = ' ';  x = xx;

do {
	if ( x & 0x0040 ) {	/* If .NOT. Character filter element UZAN etc */
		switch ( x ) {

			case	FMT_DYN : dynasem = 1; break;
#ifdef	ABAL21
			case	FMT_Q   : 
#endif
			case	FMT_DCH : fmtptr++; break;
			case 	FMT_JL	:	/* Left   Justify Output */
					fbcdc |= 0x8000; break;
			case	FMT_JR	:	/* Right  Justify Output */
					break;
#ifdef	ABAL14
			case 	FMT_INH :
					InhibitZero = 1; break;
			case    FMT_H   :
					fmthex = 1; break;
#endif
			case	FMT_ZER	:	/* Padd zeros with '*'	 */
					zpadn = '*'; break;
			case	FMT_ZCH	:

					/* Collect Explicite Padd Character */
					/* -------------------------------- */
					zpadn = *(fmtptr++); 
#ifdef	ABAL14
					/* Allow dynamic substitution */
					/* -------------------------- */
			 		if ((dynasem == 1 ) && ( dynadex < dynamax))
						zpadn = dynamat [dynadex++];

					/* Reset Dynamic format Request Flag */
					/* --------------------------------- */
					dynasem = 0;
#endif
					break;

			case	FMT_MIL	:	/* Separateur Milliers */
						/* ------------------- */
					fmtmil = defmil; 
					fbcdc |= 0x0200; 
					fmtmilcount = 3; 
					break;

			case	FMT_MCH	:	/* Separateur Milliers ? */
						/* --------------------- */

					/* Collect Explicite separator */
					/* --------------------------- */
					fmtmil = *(fmtptr++);
#ifdef	ABAL14
					/* Allow dynamic substitution */
					/* -------------------------- */
			 		if ((dynasem == 1 ) && ( dynadex < dynamax))
						fmtmil = dynamat [dynadex++];

					/* Reset Dynamic format Request Flag */
					/* --------------------------------- */
					dynasem = 0;
#endif
					/* Establish Default Position */
					/* -------------------------- */
					if (( fbcdc & 0x0200 ) == 0) {
						fbcdc |= 0x0200; 
						fmtmilcount = 3;
						}
					break;
#ifdef	ABAL21
			case FMT_PCH :
					/* Collect Explicite separator */
					/* --------------------------- */
					sepdec = *(fmtptr++);
					/* Allow dynamic substitution */
					/* -------------------------- */
			 		if ((dynasem == 1 ) && ( dynadex < dynamax))
						sepdec = dynamat [dynadex++];
					dynasem = 0;
					break;

#endif

#ifdef	ABAL14
			case	FMT_MNB :	/* Separation count */
						/* ---------------- */

					/* Collect explicite Position */
					/* -------------------------- */
					fmtmilcount = *(fmtptr++);

					/* Allow dynamic substitution */
					/* -------------------------- */
			 		if ((dynasem == 1 ) && ( dynadex < dynamax))
						fmtmilcount = dynamat [dynadex++];

					/* Reset Dynamic format Request Flag */
					/* --------------------------------- */
					dynasem = 0;

					/* Establish default Character */
					/* --------------------------- */
					if (( fbcdc & 0x0200) == 0 ) {
						fmtmil = defmil;
						fbcdc |= 0x0200;
						}

					break;
#endif
			case	FMT_POS	:	/* Print +ve sign only */
						/* ------------------- */
				 	fbcdc |= 0x0100;
					fbcdp = '+'; fbcdm = ' ';
					uform((FMT_N | 0x0040),dynasem); 
					dynasem = 0;
					break;
			case	FMT_DOL :	/* Does not apply to Num */
					break;
			case	FMT_NEG	:	/* Print -ve sign only	 */
				 	fbcdc |= 0x0100;
					fbcdp = ' '; fbcdm = '-'; 
					uform((FMT_N | 0x0040),dynasem);
					dynasem = 0;
					break;
			case	FMT_PNG	:	/* Print both signs	 */
				 	fbcdc |= 0x0100;
					fbcdp = '+'; fbcdm = '-';
					uform((FMT_N | 0x0040),dynasem);
					dynasem = 0;
					break;
			case	FMT_DEB	:	/* Debut du Format	 */
						y = 0; break;
			case	FMT_FIN :	/* Fin du Format	 */
						y = 1; fmtflg &= 0xFFFC;
						continue;
			case	FMT_STR	:	/* Retour Fmt Libre	 */
					fmtbass(2);  break;
			case	FMT_CUT	:	/* N'imprime blanc a droite */
					oblig = 1;
					y = 0; break;
			default		:	/* Erreur du Format	 */
				err_val = 112; return;
			}	/* End switch ( x )	*/
		}		/* Endif		*/

	else		{	/* Character filter elements		 */
		switch ( x ) {
			case	FMT_P	:	/* Virgule etant le sepdec */
					fbcdc |= 0x1000; 
					fbcdd = sepdec;
					break;
			case	FMT_V	:	/* Virgule interne	 */
					fbcdv = (BINAIRE) ReadSchar( fmtptr ); fmtptr++; 
					break;
			case	FMT_SEP	:	/* Format separatuer	 */
						y = 1; continue;
			default		:	/* All filters		 */
				if ( x & 2 ) {	/* If numeric filter	 */
					uform(x,dynasem);
					dynasem = 0;
					}				
				else { fmtptr++; dynasem = 0; }
				break;
			}	/* End switch ( x )	*/ 
		}		/* Endif		*/

	x = (EXAWORD) *(fmtptr++);
	}			/* End do		*/
while (	y == 0 );
fmtmax = fmtdex;
return;
}


void	reset_format_control()
{
	EXAWORD	x;
	for ( x = 0; x < fmtmax; x++ ) 
		fmtgod[x] = 0;
	askmust = 0; fmtdex = 0;
	return;
}

/* 
 *	A S K B A K ( )
 *	---------------
 *
 * 	Low level ASK routine BACKSPACE operations manager
 * 	with parallel format management
 *
 */

VOID	askbak()
{
	askvisi(syskey[IO_BAK]); 

	abufdex--;

	if ( abufdex == 0 ) 
		reset_format_control();
	else	{
		if ( askmust == 0 ) {	
			fmtgod[fmtdex] = 0;
			while ( fmtdex > 0 ) {
				if ( fmtgod[--fmtdex] > 0 )
					break; 
				}
			askmust = fmtgod[fmtdex];
			}
		if ( askmust > 0 ) 
			askmust--;
		}
	return;
}

/* 
 *	S F _ A T B ( fx )
 *	------------------
 *
 *	Attributes de visualisation
 *	
 *	0	:	Normal Video
 *	1	:	Preferential
 *	2	:	Inverse Video
 *	3	:	Clignotement
 *	4	:	Soulignement
 *	5	: 	Sous brilliance
 *	6	:	Sur brilliance
 *	7	:	Forcee majescules
 *	8	:	Forcee minescules
 */


VOID	reset_mima_lang()
{
	LangFlag = 0;
	MimaFlag = 0;
}

#ifdef UNIX

/* #BG 21/04/20 ASK VIRTUAL KBD */
static void SetVirtKeybChar(EXAWORD v)
{
	askvirtkbdchar = v;
}

static EXAWORD GetVirtKeybChar(void)
{
	EXAWORD v = askvirtkbdchar;
	askvirtkbdchar = 0;
	return v;
}

static EXAWORD VirtKeybHit(void)
{
	return( (askvirtkbdchar ? 1 : 0 ) );
}

#endif

VOID	set_ask_event(n,v)
EXAWORD	n;
EXAWORD	v;
{
	switch ( n ) {
		case 50 : AskContext.Start = v; 	break;
		case 51 : AskContext.CurserFore = v; 	break;
		case 52 : AskContext.CurserBack = v; 	break;
		case 53 : AskContext.CurserAtb  = v; 	break;
		case 54 : AskFont   = v;		break;
		case 55 : PrintFont = v;		break;

		case 56 :
			if (!(ForeGroundMask = v));
				ForeGroundMask = 0x000F;
			break;

		case 57 :
			if (!(BackGroundMask = v)) {
#ifdef UNIX
//#BG 24/05/19 16 couleurs de fond
				if (signature_version >= 41)
					BackGroundMask = 0x000F;
				else
					BackGroundMask = 0x0007;
#else
				BackGroundMask = 0x000F; /*FCH06012005 par compatibilite avec Wexa2, on met 15 et non pas 7*/
#endif
			}
			break;

#ifdef UNIX
		case 62:	/* #BG 21/04/20 ASK VIRTUAL KBD: Envoi du code ASCII specifie (caracteres affichables uniquement) */
			if ((askmask & MASK_VIRT_KBD) != 0)
				SetVirtKeybChar(v);
			break;
#else
		case 62:	/* #BG 21/04/20 ASK VIRTUAL KBD: Envoi du code ASCII specifie (caracteres affichables uniquement) */
			if ((askmask & MASK_VIRT_KBD) != 0)
				SendVirtKeybChar((WORD)v);
			break;

		case 63:	/* #BG 21/04/20 ASK VIRTUAL KBD: Envoi du Virtual Key Code comme si clavier physique */
			if ((askmask & MASK_VIRT_KBD) == 0)
				break;

			if (v == 0x99)	// ALTGR = CTRL + ALT
			{
				OnWmVirtKeyboardKey(0x11);	// CTRL
				OnWmVirtKeyboardKey(0x12);	// ALT
			}
			else
				OnWmVirtKeyboardKey(v);
			break;
#endif
	}
	return;
}

EXAWORD	get_ask_event(n)
EXAWORD	n;
{
	switch ( n ) {
		case 50 : return( AskContext.Finish );
		case 51 : return( AskContext.CurserFore );
		case 52 : return( AskContext.CurserBack );
		case 53 : return( AskContext.CurserAtb  );
		case 54 : return( AskFont );
		case 55 : return( PrintFont );
		case 56 : return( ForeGroundMask );
		case 57 : return( BackGroundMask );
		}
	return(0);
}

EXAWORD	get_op_event()	
{
return( cico_use_abqt ); 
}

#define	_FIRST_VISUAL_ATB	100
#define	_LAST_VISUAL_ATB	125+26

VOID	visual_atb( int v )
{
	x_putch(27); x_putch('('); 
	if ( v > 25 )
		x_putch('A'+(v-26));
	else	x_putch('a'+v);
	return;
}


VOID	interpret_atributs( workval1 )
BINAIRE	workval1;
{

	if (( workval1 & 0x04000 ) != 0 ) {
		atb(0);
		if (( workval1 & 0x0001 ) != 0 ) 
			atb(1);
		if (( workval1 & 0x0002 ) != 0 ) 
			atb(2);
		if (( workval1 & 0x0004 ) != 0 ) 
			atb(3);
		if (( workval1 & 0x0008 ) != 0 ) 
			atb(4);
		if (( workval1 & 0x0010 ) != 0 ) 
			atb(5);
		if (( workval1 & 0x0020 ) != 0 ) 
			atb(6);
		if (( workval1 & 0x0040 ) != 0 ) 
			atb(7);
		if (( workval1 & 0x0080 ) != 0 ) 
			atb(8);
		if (( workval1 & 0x0100 ) != 0 ) 
			atb(25);
		if (( workval1 & 0x0200 ) != 0 ) 
			atb(27);
		if (( workval1 & 0x0400 ) != 0 ) 
			atb(10);
		if (( workval1 & 0x0800 ) != 0 ) 
			atb(11);
		AtbContext = (EXAWORD) workval1;
		return;
		}
	else	{
		switch ( workval1 ) {
			case 0 : AtbContext = 0; 
				 LastFore   = conf(30); 
				 LastBack   = conf(29);
				 MimaFlag   = 0;
				 break;
			case 1 : AtbContext |= 0x0001; break;
			case 2 : AtbContext |= 0x0002; break;
			case 3 : AtbContext |= 0x0004; break;
			case 4 : AtbContext |= 0x0008; break;
			case 5 : AtbContext |= 0x0010; break;
			case 6 : AtbContext |= 0x0020; break;
			case 7 : AtbContext |= 0x0040; 
				 if ( LangFlag ) {
					MimaFlag = 1; /* Force Maji */
					return;
					}
				 break;
			case 8 : AtbContext |= 0x0080; 
				 if ( LangFlag ) {
					 MimaFlag = 2; /* Force Mini */
					 return;
					 }
				 break;
			case 25: AtbContext |= 0x0100; break;
			case 26: AtbContext &= 0x7EFF; break;
			case 27: AtbContext |= 0x0200; break;
			case 28: AtbContext &= 0x7DFF; break;
			case 10: AtbContext |= 0x0400; break;
			case 11: AtbContext |= 0x0800; break;

			case 40: /* DO ABQT 	 */
				abqt();
				return;
			case 41: /* OP ABQT:ON   */
				cico_use_abqt = 1;
				return;
			case 42: /* OP ABQT:OFF  */  
				cico_use_abqt = 0;
				return;

			case 43: /* CICO MES:ON  */
			case 44: /* CICO MES:OFF */
#ifdef	PROLOGUE
				prologue_special_atb( workval1 );
#else
				return;
#endif
#ifdef	ABAL21
			case 50 : /* OVERWRITE MODE */
				AskContext.Flags &= 0xFFFE; return;
			case 51 : /* INSERT MODE    */
				AskContext.Flags |= 0x0001; return;
			case 52 : /* BLINK CURSER   */
				AskContext.Flags &= 0xFFFD; return;
			case 53 : /* BLOCK CURSER   */
				AskContext.Flags |= 0x0002; return;
			case 54 : /* SHOW $ HOTKEYS */
				AskContext.Flags &= 0xFFFB; return;
			case 55 : /* HIDE $ HOTKEYS */
				AskContext.Flags |= 0x0004; return;
#endif

			default	:
				/* check for and avoid printers */
				/* ---------------------------- */
				if ( prndest != 1 )
					break;

				/* this has been added to allow ease of use of the new visual library */
				/* ------------------------------------------------------------------ */
				if (( workval1 >= _FIRST_VISUAL_ATB ) && ( workval1 <= _LAST_VISUAL_ATB )) {
					visual_atb( (workval1-_FIRST_VISUAL_ATB) );
					return;
					}		
			}

		if ( workval1 < 32 )
			atb( workval1 );
		return;

		}
}


#include "exiocode.c"

/*
 *	C L E O L ()
 *	------------
 *	Clear to End of Zone ( if not FMT_F )
 *
 */
VOID	cleol()
{
	register EXAWORD x;

	if (( oblig == 0 ) && ( fmtlen > abufdex )) {
		x = (fmtlen - abufdex);
		x_bstart();
		for ( ; x > 0; x-- )
			askvisi(IO_ESP);
		x_bflush();
		}
	return;
}

EXAWORD	fmtverif( y )
EXAWORD	y;
{
	EXAWORD	x,xrun,xf,bufrun;
	EXAWORD	kk,ii,jj;
	xrun = 0; x = 0; bufrun = 0;
	xf = (fmthld[y] & 0x000F);
	while ( x < y ) {
		/* Test for MANDATORY filter element */
		/* --------------------------------- */
		if (( fmthld[x] & 0x0080 ) == 0) { 
			if ( fmthld[x] != FMT_V ) {
				/* Test for Filter type match */
				/* -------------------------- */
				if ( (fmthld[x] & 0x000F) == xf ) { 
					/* Test for Current Filter Element */
					/* ------------------------------- */
					if ( x == fmtdex ) 
						jj = askmust;  
					else	jj = fmtgod[x]; 
					for (kk = 0,ii = 0; ii < jj ; ii++)
						if ( (xf & kodchk( askbuf[ bufrun + ii] )) != 0 ) 
							kk++; 
					xrun += kk;
					}
				}
			else	xrun = 0;
			}
		/* Mandatory filters reset the running total */
		/* ----------------------------------------- */
		else	xrun = 0;
		if ( x == fmtdex ) 
			bufrun += askmust;
		else	bufrun += fmtgod[x];
		x++;
		}
	if ( x == fmtdex )
		kk = askmust;
	else	kk = 0;
	if ((xrun + kk) >= fmtcpt[y] ) 
		return(1);
	else	return(0);		
}

EXAWORD	fmtotal( y )
EXAWORD	y;
{
	EXAWORD	z;
do {
   if (fmthld[fmtdex+y] == FMT_V)
	for ( z = 1; (( fmtdex + y + z) < fmtmax ) ; z++ )
		if ((fmthld[fmtdex+y+z] & 0x0080) != 0)
			return(0);

   /* If current Filter is Mandatory */
   /* ------------------------------ */
   if ((fmthld[fmtdex+y] & 0x0080) != 0)  { 
	/* If mandatory filter cannot be fulfilled */
	/* --------------------------------------- */
	if ( fmtverif((fmtdex + y)) == 0 ) 
		return(0);
	}
     y++;
   }
while (( fmtdex + y ) < fmtmax );
return(1);
}

/* 
 *	A S K O U T ( n )
 *	-----------------
 *
 *	This routine "ASKOUT" manages the exit from the
 *	low level ask main body function.
 *
 */

EXAWORD	askout(n,m)
EXAWORD	n;
EXAWORD	m;
{

register EXAWORD y,yy;

y = 0;

/* IF not waiting for RC already */ 
/* ----------------------------- */
if ( n != 2 ) { 

	/* Check for Last Format Element */
	/* ----------------------------- */
	if ( fmtdex == (fmtmax - 1)) {	

		/* Check for Not First Format Element */
		/* ---------------------------------- */
		if ( fmtdex > 0 ) {

			y = 1;

			/* Check for Current Obligatory Format */
			/* ----------------------------------- */
			if ( (fmthld[fmtdex] & 0x0080) != 0 )   {

				/* Check if Last was a Decimal Separator */
				/* ------------------------------------- */ 
				if ( fmthld[fmtdex -y] != FMT_V ) {

					/* -------------------------------------- */
					/* Check if last was oblig and must be OK */
					/* Bug fix : Dit 2590 du 16/07/1993 IJM   */
					/* -------------------------------------- */
					if ( fmthld[fmtdex-y] & 0x0080 )
						return( 0 );

					/* Check if Last was Non obligatory or Similar */
					/* ------------------------------------------- */
					if (( fmthld[fmtdex] & fmthld[fmtdex -y] ) != 0 ) {

					/* Check if Obligations Satisfied */
					/* ------------------------------ */
					if ( fmtcpt[fmtdex] > (askmust + fmtgod[fmtdex-y]) )

						/* Not Satisfied so FALSE */
						/* ---------------------- */
						return(0);
					}
				     }
				/* Last Was a Decimal Place */
				/* ------------------------ */
				else {	/* Check if Obligations Satisfied */
					/* ------------------------------ */
					if ( fmtcpt[fmtdex] > askmust )

						/* Not Satisfied So FALSE */
						/* ---------------------- */
						return(0);
				     }
				}
			}
		else 	{
			/* fmtdex == 0 Single Format filter */
			/* -------------------------------- */
			if ( (fmthld[fmtdex] & 0x0080) != 0 ) 
				return(0);
			}
		}
	else 	{	
		if ( fmtotal(y) == 0 ) 
			return(0);
		}
	}
/* Check for BCD Variable */
/* ---------------------- */
if ( worktyp1 == 2 ) {

	/* Check for Preceeding Sign Character or Spaces */
	/* --------------------------------------------- */
	for ( yy = 0; yy < abufdex; yy++ )
		if (( askbuf[yy] == '+' ) || ( askbuf[yy] == '-' ) || ( askbuf[yy] == ' ' ))
			continue;
		else	break;

	/* Check for Length overflow */
	/* ------------------------- */
	if ( (abufdex+1-yy) > ( worklen1 * 2 ) ) {
		/* ---------------------------------- 	*/
		/* String too EXALONG for a Bcd Variable 	*/
		/* ---------------------------------- 	*/
		/* Perform Ctrl A Before Return		*/
		/* ----------------------------		*/
		if ( m ) { x_bell();  }
		bufwipe(); return(0);
		}
	}
askbuf[abufdex] = IO_NUL; 
if ( m ) { cleol(); }
abufdex++; 
#ifdef	BUF_CICO
if ( m ) { x_bstart(); } 	/* Activate CICO bufferisation	*/
#endif
while ( (BINAIRE) abufdex <= fmtlen) { askbuf[abufdex++] = IO_ESP; } 
#ifdef	BUF_CICO
if ( m ) { x_bflush(); } 	/* Activate CICO bufferisation	*/
#endif
return(1);
}

/* 
 *	B U F W I P E ( )
 *	-----------------
 *
 * 	Erase the ASK buffer and reset display line .
 * 	and clear format Cumulation values per filter.
 */

VOID bufwipe()
{
	register EXAWORD x,y;
	
	askl += ((BINAIRE) (AskInfos(XLIN) - (askl + ((abufdex + (askc-1)) / AskInfos(CONF2)))));
	pos(askl,askc);
	x = 0;
	y = abufbig;
#ifdef	BUF_CICO
	x_bstart();		/* Activate CICO bufferisation	*/
#endif
	while ( x < y ) { askbuf[x]=IO_ESP; x++; askvisi(IO_ESP); }
#ifdef	BUF_CICO
	x_bflush();		/* Activate CICO bufferisation	*/
#endif
	askbuf[x]=IO_ESP;
	reset_format_control();

	abufdex = 0; abufbig = 0;
	askl += ((BINAIRE) (AskInfos(XLIN) - (askl + ((y + (askc-1)) / AskInfos(CONF2)))));
	pos(askl,askc);
	return;
}

#ifndef	ABAL_RTL
void	calculate_jump_target( tstdex )
EXAWORD	tstdex;
{
	/* Watch out for Gosub and Return Type */
	/* ----------------------------------- */
	if ((asktst[tstdex] & 0x8000 ) != 0)

		/* Stack up the Return Adresse */
		/* --------------------------- */
#ifdef	WIN32
		ip_hold [ip_next++] = (EXAWORD) ((lineptr - TcodeSegment) -1);
#else
#ifndef	UNIX
		ip_hold [ip_next++] = (EXAWORD) get_lineptr_ip();
#else
		ip_hold [ip_next++] = (EXAWORD) ((lineptr - TcodeSegment) -1);
#endif
#endif

	/* Load the new tcode adresse as indicated */
	/* --------------------------------------- */
	fdex = (BPTR) (TcodeSegment + askjmp[tstdex]);
	
	return;
}
#endif

/* 
 *	H O T K E Y ( c )
 *	-----------------
 *	Test for KEY recieved in first position
 *	to see if key is defined as a hot key.
 */

EXAWORD is_hotkey(c)
EXAWORD c;
{
register EXAWORD tstdex;

/* Perform if HOT KEYS have been defined */
/* ------------------------------------- */
if ( jmpdex > 0 ) {

	/* For defined number of keys */
	/* -------------------------- */
	for ( tstdex = 0; tstdex < jmpdex; tstdex++ ) {

		/* If key value is declared as a HOT KEY */
		/* ------------------------------------- */
		if ( c == (asktst[tstdex] & 0x01FF )) {

			/* Store for possible retrieval */
			/* ---------------------------- */
			LastJumpKey = (c & 0x01FF); 

			/* Check for required visualisation */
			/* -------------------------------- */
			if (( asktst[tstdex] & _VISIBLE_HOTKEY )
#ifdef ABAL21
			&& (!(AskContext.Flags & 4))) 
#else
								)
#endif
				askvisi( c );

#ifndef	ABAL_RTL
			calculate_jump_target( tstdex );
#endif
			/* ZERO MEANS JUMP TRUE SO EXIT NOW */
			/* -------------------------------- */
			return(0); 
			} 
		} 
	}

/* NO JUMP SO CONTINUE */
/* ------------------- */
return(1);
}


EXAWORD	fwdverif( typemask )
EXAWORD	typemask;
{
	/* Test Previous Format Filter Type for Compatiblillity */
	/* ---------------------------------------------------- */
	if (!(fmthld[(fmtdex-1)] & typemask))
		return(0);

	/* Test Previous Format Filter Mandatory Type */
	/* ------------------------------------------ */
	if (!(fmthld[(fmtdex-1)] & 0x0080)) {
		if ( fmtcpt[(fmtdex-1)] == fmtgod[(fmtdex-1)] )
			return(0);
		}
	else if ( fmtdex <= 1 )
		return(0);
	else if (!(fmthld[(fmtdex-2)] & typemask))
		return(0);
	else if ( fmtcpt[(fmtdex-2)] == fmtgod[(fmtdex-2)] )
		return(0);
	else	{
		fmtgod[(fmtdex-2)]++;
		fmtgod[(fmtdex-1)]--;
		}

	fmtdex--;
	askmust = fmtcpt[(fmtdex-1)];
	return(1);
}

/*
 *	C H K F M T ( c )
 *	-----------------
 *
 *	Format character filtering for data Input (ASK)
 *	The character filtering system will return 1 TRUE to allow accept
 *	and 0 FALSE to reject character
 *
 */

EXAWORD	chkfmt(c)
EXABYTE	c;
{
	register EXAWORD	x,y;
	
	x = kodchk(c);		/* Perform character type analysis	*/
	y = 0;			/* Format matrix extra Index		*/

	do 	{
		/* Test for Separateur Decimale Filter */
		/* ----------------------------------- */
		if (  ((fmthld[fmtdex + y] & 0x000F) == 0x0008)
		&&    (( x & 0x0008 ) == 0 )) {
			if (( y == 0 ) && ( fmtdex != 0 ))
				return( fwdverif(x) );
			else	return( 0 );	
			}

		/* If character accepted by filter */
		/* ------------------------------- */
		if ( (fmthld[fmtdex + y] & x)      != 0 )   {	
		    if ( y > 0 ) {
			fmtgod[fmtdex] = askmust;
			for ( x = (fmtdex + 1); x < (fmtdex + y); x++ )
				fmtgod[x] = 0; 
			fmtdex += y; 	/* ADJUST format    */
			askmust = 0; 	/* RESET  Count     */ 
			}
		     return(1); 	/* ACCEPT character */
		     } 	

		/* If filter type is mandatory */
		/* --------------------------- */
		if (  ((fmthld[fmtdex + y] & 0x0080) != 0 )
		&&    ((fmthld[fmtdex + y] & 0x000F) != 0 )
		&&    (fmtverif((fmtdex + y)) == 0) ) 
			/* Reject Character */
			return(0); 

		y++;	/* Next Filter Element */
		}
	while (( fmtdex + y ) < fmtmax );
	return(0);	/* Reject character since no more filter elements */
}

/*
 *	F M T B A S S ( ap )
 *	--------------------
 *	Parametres du Format Libre
 *
 */

VOID fmtbass( EXAWORD ap)
		/* Type of format underway FILTER or ACTION */
{
	EXAWORD	apx;

	if ( ap == 1 ) 
	{
		if ( worktyp1 < VARB_STR ) 
		{
			fbcdp = '+'; 
			fbcdm = '-'; 
		}
		else 	
		{
			fbcdc = 0; 
			zpadn = ' '; 
		}
		apx = fmtdex;

		/*	Format Libre type NUMERIQUE	*/
		/*	---------------------------	*/
		if ( worktyp1 < VARB_STR ) 
		{
			fmthld[fmtdex] = FMT_SGN;
			fmtgod[fmtdex] = 0;
			fmtcpt[fmtdex] = 1;
			fmtdex++;
			fmthld[fmtdex] = FMT_N;
			fmtgod[fmtdex] = 0;

			switch ( worktyp1 & VARB_ISOL ) 
			{
			case	VARB_FOUR	:
			case	VARB_INT8	:
			case	VARB_INT16	:
				fmtcpt[fmtdex] = ((worktyp1 + 1) * 2);
				break;
			case	VARB_INT32	:
				fmtcpt[fmtdex] = 9;
				break;
			case	VARB_INT64	:
				fmtcpt[fmtdex] = 18;
				break;
			case	VARB_BCD	:
				fmtcpt[fmtdex] = 13;
			}

			fmtdex++;
			fmthld[fmtdex] = FMT_Z;
			fmtgod[fmtdex] = 0;
			fmtcpt[fmtdex] = 1;
			fmtdex++;

			if ( worktyp1 == VARB_BCD ) 
			{
				fmthld[fmtdex] = (FMT_P & 0x007F);
				fmtgod[fmtdex] = 0;
				fmtcpt[fmtdex] = 1;
				fmtdex++;
				fmthld[fmtdex] = FMT_N;
				fmtgod[fmtdex] = 0;
				fmtcpt[fmtdex] = 14;
				fmtdex++;
			}
		}

		/*	Format Libre type CHAINE	*/
		/*	------------------------	*/
		else	
		{
			fmthld[fmtdex] = FMT_W;
			fmtgod[fmtdex] = 0;
			fmtcpt[fmtdex] = worklen1;
			fmtdex++;
		}

		fmtmax = fmtdex;
		for ( ; apx < fmtmax; apx++)
			fmtlen += fmtcpt[apx];
	}

	if ( ap == 2 ) 
		iform( worktyp1 );
	return;
}


/*
 *	A S _ F M T ( ap )
 *	------------------
 *	Ask input formating
 *
 *	2 operating modes are provided :
 *	- 3 )	Collect format details for ASK control
 *		performs action elements.
 *	- 1 )	Perform Action elements only
 */

VOID as_fmt(ap)
EXAWORD	ap;		/* Format INIT = 1, Format Clear = 3 */
{

register EXAWORD x,fctrl;
	 EXAWORD dynasem;

	fmtdex  = 0; fctrl   = 0; 
	fmtmax  = 0; dynasem = 0;
	fbcdp = ' '; fbcdm = ' ';
	askmust = 0; fmtlen  = 0; 
	InhibitZero = 0;
	if ( (fmtflg & 0x007F) == 0 ) 
		fmtbass(ap);
	else 	{ 
		if (( ap == 3 ) && (( fmtflg & 3 ) == 0 )) 
			return;
		fmtlen = 0;
		do 	{
			if ((x = (EXAWORD) *(fmtptr++)) & 0x0020)
				x = fmtact( x );
			switch ( x ) {
				case	FMT_DYN : dynasem = 1; continue;
				case	FMT_V	: fbcdv = (BINAIRE) ReadSchar( fmtptr ); fmtptr++; 
						  continue;
				case	FMT_P	: askmust = 1; x &= 0x007F; break;
				case 	FMT_CUT : oblig = 1; continue;
#ifdef	ABAL14	
				case 	FMT_INH : InhibitZero = 1; continue;
				case	FMT_H   : fmthex = 1; 
						  continue;	
#endif
#ifdef	ABAL21
				case 	FMT_PCH :
				case	FMT_Q   :
#endif
				case	FMT_MCH :
				case	FMT_MNB :
				case	FMT_DCH :
				case    FMT_ZCH :

				  /* -------------------------------------- */ 
				  /* These format codes expect an aditional */
				  /* Information byte which does not apply  */
				  /* To the ASK expression and hence must   */
				  /* Be ignored when in the pre ASK format  */
				  /* analysis mode. Otherwise in post ASK   */
				  /* Format analysis mode the algorithm is  */
				  /* The same as for their counterparts     */
				  /* which do not require the additional    */
				  /* Information			    */
				  /* 4/2/1992 Dit 1710 I.J.M		    */
				  /* -------------------------------------- */ 
				   	if ( ap != 3 ) {
						fmtptr++; 
						continue;
						}

				case	FMT_JL	:
				case	FMT_JR	:
				case	FMT_DOL :
				case	FMT_MIL :
				case	FMT_ZER : 

					if ( ap == 3 ) { 
						fctrl = 1; 
						fmtptr--; 
						}
					  continue;

				case	FMT_STR : 
					fmtbass(ap); 
					fctrl = 0; 
					continue;

				case	FMT_DEB	: 
					fmtdex = 0; 
					fmtlen = 0; 
					continue;

				case	FMT_FIN	: 
					fmtflg &= 0xFFFC;
				case	FMT_SEP	: 
					fctrl = 1; 
					continue;
				case	FMT_POS : 
				case	FMT_PNG :
				case	FMT_NEG : 
					if ((x == FMT_POS) 
					||  (x == FMT_PNG))
						/* Sign Obligatoire */
						x = ((FMT_SGN | 0x0080) & 0x00F0);
					else  	x = FMT_SGN;
					fbcdm = '-';
					fbcdp = '+';
					if ((dynasem == 1) && (dynadex < dynamax)) {
						fmtptr++;
						if ((askmust = dynamat [dynadex++]) == 0)
							continue;
						}
					else 	if ((askmust = (EXAWORD) *(fmtptr++)) == 0)
							askmust = 256;
					dynasem = 0;
					if ( askmust > 1 ) { 
						askmust--; fmtlen++;
						fmthld[fmtdex] = x;
						fmtcpt[fmtdex] = 1; 
						fmtgod[fmtdex] = 0;
						x = FMT_N; fmtdex++;
						}
				  	break;
				default		: 
					if ( ap == 3 ) { 
						fctrl = 1; 
						fmtptr--; 
						continue; 
						}
				  	else 	{ 
						if (( x & 0x0040 ) == 0 ) {
							if ((dynasem == 1) && (dynadex < dynamax)) {
								fmtptr++;
								if ((askmust = dynamat [dynadex++]) == 0)
									continue;
								}
							else 	if ((askmust = (EXAWORD) *(fmtptr++)) == 0)
									askmust = 256;
							dynasem = 0;				
							}
						else 	{ 
							fmtptr++; 
							dynasem = 0; 
							continue; 
							}
						}
				}
			fmtlen += askmust; 
			fmtgod[fmtdex] = 0; 
			fmthld[fmtdex] = x; 
			fmtcpt[fmtdex] = askmust;
			fmtdex++;
			}
		while ( fctrl == 0 );
		} /* End else */
	fmtmax = fmtdex; 
	fmtdex = 0; 
	askmust = 0;
	return;
}

/*
 *	P R _ F M T ( ap )
 *	------------------
 *	Print output formating
 *
 */

VOID pr_fmt(ap)
EXAWORD	ap;
{

	EXAWORD	x,fctrl;

	fmtmax = 0;

	/* ------------------------------------ */
	/* Check for and Establish FORMAT LIBRE */
	/* ------------------------------------ */
	if ( (fmtflg & 0x007F) == 0 ) 
	{
		fmtbass(ap); 
		return; 
	}
	fctrl = 0;

	do 	
	{
		/* ---------------------------------------- */
		/* Collect FORMAT CODE and Check for Action */
		/* ---------------------------------------- */
		if ((x = (EXAWORD) *(fmtptr++)) & 0x0020)
			x = fmtact( x );

		/* -------------------------- */
		/* Select current Format Code */
		/* -------------------------- */
		switch ( x ) 
		{
		case	FMT_FIN	: fmtflg &= 0xFFFC; fctrl = 1; 
		case 	FMT_CUT : continue;
		case	FMT_SEP	: fmtdex = 0; continue;

		default		:
			/* ----------------------------------- */
			/* Check for and Perform POST ACTIONS */
			/* ----------------------------------- */
			if ( ap == 3 ) { fctrl = 1; fmtptr--; continue; }
			else 	
			{
				/* -------------------------- */
				/* Perform FORMAT ENVIRONMENT */
				/* -------------------------- */
				if ( worktyp1 == VARB_STR ) 
					envstr(x);
				else 	envnum(x);
				fctrl = 1;
			}			
		}
	}
	while ( fctrl == 0 );
	return;
}

/*
 *	B U F E N D ()
 *	--------------
 *	Signals the buffer manager exit condition
 *
 *	0 )	Continue keyboard input
 *	1 )	End of keyboard input
 *	2 )	Wait for Return or Editor speciale keys
 *
 */

EXAWORD	bufend(int noise)
{
	if ((abufdex >= fmtlen ) || (fmtdex >= fmtmax)) 
	{
		askbuf[abufdex] = (EXABYTE) 0;
		if ((askmask & MASK_NO_CR) != 0 )	
		{
			/* Saisie Complete but Check for BCD Possibility */
			/* --------------------------------------------- */
			/* Check for BCD Variable */
			/* ---------------------- */
			if ( worktyp1 == 2 ) 
			{
				/* Check for Length overflow */
				/* ------------------------- */
				if ( (abufdex+1) > ( worklen1 * 2 ) ) 
				{
					/* ---------------------------------- 	*/
					/* String too LONG for a Bcd Variable 	*/
					/* ---------------------------------- 	*/
					/* Perform Ctrl A Before Return		*/
					/* ----------------------------		*/
					if ( noise )
						x_bell();
					 bufwipe(); return(0);
				}
			}
			return(1); 
		}
		else 	{ return(2); } /* Await RC */
	}
	else	return(0); 	/* Continue Saisie */
}

/*
 *	M A S K W O R K ( )
 *	-------------------
 *	Performs MASKED error handling options
 *	
 *	Returns :	Zero  => Debranchement en erreur
 *			 1    => Rejection
 *			 2    => Ok 
 */

EXAWORD	maskwork()
{
	if ((askmask & MASK_ACTIV_JUMP_E) != 0 ) {
#ifndef	ABAL_RTL
		
		is_hotkey( _ERROR_HOTKEY );
#endif
		return(0);
		}
	if ((askmask & MASK_BELL) != 0 ) 
		x_bell();
	if ((askmask & MASK_RESET_INV) != 0 ) {
		bufwipe(); 
		return(3);
		}
	if ( (askmask & MASK_REJECT_INV) != 0 ) 
		return(1);
	return(2);
}

/*
 *	B U F G E S T ( c )
 *	-------------------
 *	Performs buffer management for ASK
 *
 */

void	position_ask_curser()
{
	pos( (askl + (((askc-1) + abufdex) / AskInfos(CONF2))) ,((((askc-1) + abufdex) % AskInfos(CONF2))+1));
	return;
}

EXAWORD	bufgest( c )
EXABYTE	c;
{
	BINAIRE x;
	BINAIRE y;
	if ( abufdex < fmtlen ) {
		if ( insflg == 0 ) {
			/* Normal OverWrite Mode */
			/* --------------------- */

			askvisi(c);		/* Affichage du character */
			askbuf[abufdex++] = c;	/* Store character	  */
			if ( abufdex > abufbig ) 
				abufbig = abufdex;
			}
		else 	{
			/* Character Insertion Mode */
			/* ------------------------ */
			/* Calculate usable Length of Input string */
			/* --------------------------------------- */
			y = abufbig;

			/* Check for Right Arrow */
			/* --------------------- */
			if ( c != syskey[IO_FOR] ) {
			 
				/* Move all characters from the end of String up
				 * up to current character 1 place to the right
				 * --------------------------------------------- */
				if ( y > 0 ) {
					for ( x = (y-1); x > abufdex; x-- )
						askbuf[x+1] = askbuf[x];
						
					askbuf[x+1] = askbuf[x];
					}

				/* Insert New character and adjust String length */
				/* --------------------------------------------- */
				askbuf[abufdex] = c; 
				if ( abufbig < fmtlen ) { y++; abufbig++; }
			
				/* Display the New Character string to the right */
				/* --------------------------------------------- */
				for ( x = abufdex; x < y; x++ ) 
					askvisi(askbuf[x]);

				/* Calculate New line position (Scroll trap) */
				/* ----------------------------------------- */
				askl += ((BINAIRE) (AskInfos(XLIN) - (askl + ((y + (askc-1)) / AskInfos(CONF2)))));
				}
			/* Increment Buffer Index */
			/* ---------------------- */
			abufdex++; 
			if ( abufdex > abufbig ) 
				abufbig = abufdex;

			/* Re-Position the curseur */
			/* ----------------------- */
			position_ask_curser();
			pos( (askl + (((askc-1) + abufdex) / AskInfos(CONF2))) ,((((askc-1) + abufdex) % AskInfos(CONF2))+1));

			}
		askmust++;		/* Increment count recieved	*/
		if ( askmust >= fmtcpt[fmtdex] ) {
			fmtgod[fmtdex] = askmust; askmust = 0; fmtdex++;
			}
		return( bufend(1) ) ;
		}
	else 	return(0);		/* TEMP*******			*/
}

EXAWORD	blindbufgest( c )
EXABYTE	c;
{
	if ( abufdex < fmtlen ) {
		/* Normal OverWrite Mode */
		/* --------------------- */
		askbuf[abufdex++] = c;	/* Store character	  */
		if ( abufdex > abufbig ) 
			abufbig = abufdex;
		askmust++;		/* Increment count recieved	*/
		if ( askmust >= fmtcpt[fmtdex] ) {
			fmtgod[fmtdex] = askmust; askmust = 0; fmtdex++;
			}
		return( bufend(0) ) ;
		}
	else 	return(0);		/* TEMP*******			*/
}

#ifdef MODEL_DBGT
VOID	showabuf( x )
BINAIRE	x;
{
	BINAIRE	y;
	x_newlyne();
	y = 0;
	while ( y < x ) {
		if ( y == abufdex ) 
			atb(2);
		showword( askbuf[y],2 ); 
		x_putch(' ');
		if ( y == abufdex ) 
			atb(0);
		y++;
	}
	return;
}

VOID	infos()
{
	EXAWORD	x;
	showabuf( fmtlen );
	x_newlyne(); x_cprintf((BPTR)"Mask : "); showword(askmask,4);
	x_cprintf((BPTR) " Format Filters : ");
	for ( x = 0; x < fmtmax; x++ ) {
		 if ( x == fmtdex ) { atb(2); }
		 x_cprintf((BPTR)" [(");
		 showword( fmtcpt[x],4 ); x_putch(')');
		 showword( fmthld[x],4 ); x_putch(':');
		 intvisi( fmtgod[x] ); x_putch(']'); x_putch(' ');
		 if ( x == fmtdex ) { atb(0); }
		 }
	x_newlyne();
	x_cprintf((BPTR) "Counter = ");
	intvisi(askmust);
	pos(askl,(askc + abufdex));
	return;
}
#endif
/*
 *	S E E K F I N ( )
 *	-----------------
 *	Recherche du fin de zone de saisie pour l'ASK
 *	REM Fin du zone de Format Valable !
 */

EXAWORD	seekfin(caller)
EXAWORD	caller;
{
	BINAIRE	x,y,z;
	EXAWORD	i;

	i = insflg; insflg = 0; 

	x = ( abufbig > 0 ? abufbig : lenuze((BPTR) askbuf, fmtlen) );

	if ( fmtgod[fmtdex] < askmust ) 
		fmtgod[fmtdex] = askmust;

	askl += ((BINAIRE) (AskInfos(XLIN) - (askl + ((abufdex + (askc-1)) / AskInfos(CONF2)))));
	abufdex = 0; askmust = 0; fmtdex = 0; abufbig = 0;
	pos(askl,askc);

	if ( caller ) {
		/* remove leading space */
		/* -------------------- */
		for ( y = 0; y < x; y++ )
			if ( askbuf[y] != ' ' )
				break;
		}		
	else
		y = 0;

	for (  ; y < x; y++ )
		if ( ( chkfmt(askbuf[y]) ==  0 ) || ((z = bufgest(askbuf[y])) != 0 ) )
			break;

	if ( x > 0 ) 
		x--;

	for ( ; y < x; y++ ) 
		askvisi(IO_ESP); 

	pos( (askl + (((askc-1) + abufdex) / AskInfos(CONF2))) ,((((askc-1) + abufdex) % AskInfos(CONF2))+1));
	return(z);
}

/*
 *	Signals the Status after pressing the insert Key
 *	BELL BELL 	: INSERT NOT ACTIVE
 *	BELL BELL BELL  : INSERT     ACTIVE
 *
 */

VOID	SignalStatus(n)
EXAWORD	n;
{
	if ((askmask & MASK_REPLACE_QUITE) == 0)
		for ( n += 2; n > 0; n-- ) 
			x_bell(); n--;
}

/*
 *	Called from PAUSE in EXCALC.C
 *	to allow Ctrl W to be active inside a pause
 *
 */

EXAWORD	exio_getch()
{
	return( x_getch() );
}

VOID	exio_putch( c )
EXAWORD	c;
{
	exputch( c );
}


#ifdef	ABAL21
EXAWORD	HCFore;
EXAWORD	HCBack;

VOID	ask_curser_on()
{
   if ((askmask & MASK_SECRET) == 0) {
	position_ask_curser();
	if ( conf(14) ) {
		HCFore = LastFore;
		HCBack = LastBack;
		(void) iof_foregr( AskContext.CurserFore );	
		(void) iof_backgr( AskContext.CurserBack );	
		}
	else	{
		HCFore = AtbContext;
		(void) iof_atb( AskContext.CurserAtb );
		}
	exputch( askbuf[abufdex] );
	position_ask_curser();
	}
}

VOID	ask_curser_off()
{
   if ((askmask & MASK_SECRET) == 0) {
	if ( conf(14) ) {
		(void) iof_foregr( HCFore );
		(void) iof_backgr( HCBack );
		}
	else	(void) iof_atb(HCFore);
	exputch( askbuf[abufdex] );
	position_ask_curser();
	}
}
#endif

EXAWORD	iof_check_format( EXAWORD bufmax, BPTR fptr, EXAWORD flen )
{
	EXAWORD	x;
	EXAWORD	y;
	EXAWORD	z;
	BPTR	wptr;
	if ( *fptr == '(' ) {

		/* ascii format requires conversion */
		/* -------------------------------- */
		wptr = (TcodeByteStack + worktop);

		if ( atofmt( fptr, flen,wptr, (flen*2) ) == SOFTERROR )
			return( SOFTERROR );
		else 	worktop += (flen * 2);
		}
	else	wptr = fptr;

	iof_format_string( wptr, 0 );

	as_fmt(1);

	abufdex = 0; askmust = 0; fmtdex = 0; abufbig = 0;

	for (y=0,x=0; y < bufmax; y++ )
		if ( askbuf[y] != ' ' )
			x = (y+1);

	abufbig = x;
	
	for ( z=0,y = 0; y < x; y++ ) {
		if (!( chkfmt(askbuf[y])))
			return((y+1));
		else if (!( z = blindbufgest(askbuf[y])))
			continue;
		else if (( y + 1) == x)
			return( 0 );
		else	return( (y+1) );
		}
	if (!( askout(z,0) ))
		return(y);
	else	return(0);
}

/*	C L O S E  V I S U A L  F O N T (ret) 	*/
/*	--------------------------------	*/	
EXAWORD	CloseVisualFont( retcode )
EXAWORD	retcode;
{
	if (!( IofFontHolder ))
		return( retcode );
	else	{
		IofFontHolder = cancel_font_margin();
		return( retcode );
		}
}

/*	O P E N  V I S U A L  A S K ( ) 	*/
/*	-------------------------------		*/	
EXAWORD	OpenVisualAsk()
{
	if (!( AskFont ))
		return( GOODRESULT );
	else	{

#ifdef ABALX11
		if ( exa_is_X11 > 1 ) 
			IofFontHolder = apply_font_margin( AskFont );
		else	IofFontHolder = 0;
#endif

		return( GOODRESULT );
		}
}

/*	O P E N  V I S U A L  P R I N T ( ) 	*/
/*	-----------------------------------	*/	

EXAWORD	OpenVisualPrint()
{
	if (!( PrintFont ))
		return( GOODRESULT );
	else	{

#ifdef ABALX11
		if ( exa_is_X11 > 1 ) 
			IofFontHolder = apply_font_margin( PrintFont );
		else	IofFontHolder = 0;
#endif

		return( GOODRESULT );
		}
}
	 
/* 
 *	L L _ A S K ( bufmax )
 *	----------------------
 *
 *	Low level ASK Keyboard entry function
 *	-------------------------------------
 *
 */

EXAWORD	niceopb()
{
	EXAWORD	holder=cico_use_abqt;
	EXAWORD	result;
	cico_use_abqt = 1;
	result = opb();
	cico_use_abqt = holder;
	return( result );
}

/*	-------------------------------------	*/
/*	F I L T E R _ E X T E R N _ E V E N T 	*/
/*	-------------------------------------	*/
/*	Extern event checking occurs in the	*/
/*	main tcode execution cycle and may	*/
/*	require filtering to allow the OP	*/
/*	to continue receiving keyboard codes	*/
/*	whilst distributing events to the	*/
/*	event catcher : IJM 23/09/2005		*/
/*	for Alliance   / Alliadis	*/
/*	-------------------------------------	*/

EXAWORD	filter_extern_event(EXAWORD type)
{
	if ( type != 2 )
		return(1);
#ifdef	MASKKBD
	else if (!( askmask & MASKKBD ))
		return(1);
#endif
	else	return(0);
}

/*	As for above but for the Ask Instruction	*/

EXAWORD	detect_extern_event()
{
	EXAWORD	et;

	/* ------------------------------------------------- */
	/* await event, mouse indicates true, otherwise zero */
	/* ------------------------------------------------- */
	if (!(et = mimo_detect()))
		return(0);

	printf("mimo_detect() ==> %x askmask : %08.8lx \r\n",et,askmask);

	/* Detect Keyboard Event and Test for Exclusion */
	/* -------------------------------------------- */
#ifdef	MASKKBD
	if (!( askmask & MASKKBD ))
		return(1);
	else 
#endif
	if (!( et & 2 ))
		return(1);
	else	return(0);
}

EXAWORD	low_level_ask(bufmax)
EXAWORD	bufmax;			/* Default Length of Input zone	*/
{
	EXAWORD	c;		/* Current keyboard character	*/
	EXAWORD	x,z;		/* Working variables		*/
	EXAWORD	et;		/* Event type			*/
	
	/* Get first Format Info If any */
	/* ---------------------------- */
#ifdef	BUG_ALTHOFF
	trace_open_files();
#endif

	fmtlen = bufmax;	/* Establish limit value	*/	

	as_fmt(1);		/* 
					 * Perform Format Actions
					 * Install Format environment options
					 * Initialise Format matrix with Format filters
					 */

	if ( fmtlen > 0 )
	{ 
		/* Check for Format Length Too Long */
		/* -------------------------------- */
		if ( fmtlen > 256 )
		{ 
			err_val = ABAL_VAR2BIG; 
			return(SOFTERROR); 
		}
 
		/* Establish entry curser details and buffer pointer 	*/
		/* ------------------------------------------------- 	*/
		ll_ask_flag = 1;

		askl = AskInfos(XLIN); 
		askc = AskInfos(XCOL); 
		abufdex = 0; z = 0; 

		/* Establish Entry Conditions for String ASK */
		/* ----------------------------------------- */
		if ( worktyp1 != VARB_STR )
			abufbig = 0;
		else if ( fmtlen > worklen1 )
				abufbig = worklen1;
			else
				abufbig = fmtlen;

		/* FCH06012005 */
		/* Ce n'est qu'ici que l'on sait qu'il faut convertir en hexa   */
		/* askbuf contient la chaine correspondant a la valeur decimale */
		/* (fait par l'appelant qui ne connait pas le format)           */
		/* donc, on le fait ici */
		if (fmthex)
		{
			switch ( worktyp1 )
			{
				case VARB_FOUR  : 
				case VARB_INT8  : 
				case VARB_INT16 : (VOID) itohex(workval1,(BPTR) askbuf, bufmax); break;
				case VARB_INT32 : (VOID) ltohex(workval1,(BPTR) askbuf, bufmax); break;
				case VARB_INT64 : (VOID) ltohex(workval1,(BPTR) askbuf, bufmax); break;
			}
		}

		/* Visual ASK for alliance ! */
		/* ------------------------- */
		if ( AskFont != 0 )
			if ( OpenVisualAsk() == SOFTERROR )
				return( SOFTERROR );

		/* --------------------------------------------------------- */
		/* MASK_ACTIV_EDIT_KEYS and MASK_CURSOR_END	                 */
		/* If these two masks are set then the ask will start at the */
		/* end of the current input string			     */
		/* --------------------------------------------------------- */
/* #BG 11/08/20 ASK VIRTUAL KBD
		if ( (askmask & MASK_CURSOR_END) && (askmask & MASK_ACTIV_EDIT_KEYS) )
*/
		if ( ((askmask & MASK_CURSOR_END) && (askmask & MASK_ACTIV_EDIT_KEYS)) || (askmask & MASK_VIRT_KBD) )
		{
			/* #BG 11/08/20 ASK VIRTUAL KBD (bug anterieur a MASK_VIRT_KBD)
			   Sans ce test sur AskContext.Start, MASK_CURSOR_END & MASK_ACTIV_EDIT_KEYS provoque une saisie initialisee a 0 pour un ASK sur numerique !
			   #BG 29/09/20 Mais ce traitement est necessaire pour MASK_CURSOR_END si MASK_VIRT_KBD inactif.
			   Donc soit supprimer le test, soit faire ce traitement si MASK_VIRT_KBD inactif.
			*/
			if ( ((askmask & MASK_VIRT_KBD) == 0) || (AskContext.Start > 0) )
			{
				abufbig = lenuze((BPTR) askbuf, fmtlen);
				seekfin(0);

				if (( AskContext.Start != 0 ) && ( AskContext.Start < abufbig ))
				{
					abufdex = AskContext.Start;
					position_ask_curser();
				}
				AskContext.Start = 0;	// Pas de pb si MASK_VIRT_KBD
			}
		}

		/* Enter main DO/WHILE loop reading and filtering keys */
		/* --------------------------------------------------- */
		do
		{
#ifndef	ABAL_RTL
			/* ====================================================== */
			/* NB: The timer is not offered in the RII ABAL C Library */
			/* ====================================================== */

			/* Test for TIMER ACTIVE */
			/* --------------------- */
			if ( ((timersem & TIME_ACTIF) != 0) && ((askmask & MASK_DEACTIV_JUMP_TIMER) == 0) )
			{
#ifdef DOS
				x_event(EVT_TOGGLE_CARET);
#endif
/* #BG 21/04/20 ASK VIRTUAL KBD
				// Tant qu'il n'y a pas de caractere entre ni de timer echu
				while ( (!niceopb()) && (((EXAWORD)descarto[0] & TIME_ALARM) != 0) )
*/
				// Tant qu'il n'y a pas de caractere entre au clavier ou par EVENT ni de timer echu
				while ( (!niceopb()) && (!VirtKeybHit()) && (((EXAWORD)descarto[0] & TIME_ALARM) != 0) )
				{
#ifdef DOS
						dos_arto(1);
#endif
				}

#ifdef DOS
				x_event(EVT_TOGGLE_CARET);
#endif

				if ( ((EXAWORD) descarto[0] & TIME_ALARM ) == 0)
				{ 
					/* Timer echu */
					is_hotkey( _TIMER_HOTKEY );
					if ((askmask & MASK_RAZ_TIMER) == 0 )	
					{ 
						z = 1; 
						continue; 	 
					}
 					else
					{ 
						bufwipe(); 
						/* ------------------------- */
						/* Visual ASK for alliance ! */
						/* ------------------------- */
						return( CloseVisualFont( SOFTERROR ) );
					}
				}		/* Endif Timer Event Occured		*/
			} 			/* Endif Timer_Actif and Allowed	*/


			/* ----------------------- */
			/* Test for EXTERN ACTIVE  */
			/* ----------------------- */
#ifdef	MASK_DETECT_EXT_EV
			if ( (timersem & 0x1000) && (askmask & MASK_DETECT_EXT_EV) )
			{
				if ( mimo_detect() )
				{
					/* Detect_extern_event() */

					/* ---------------------- */
					/* Reposition Instruction */
					/* ---------------------- */
					if (!(askmask & MASK_EXT_EV_NEXT))
						fdex = (lineptr-1);

					/* ------------------------- */
					/* Keep till cursor position */
					/* ------------------------- */
					if (askmask & MASK_RAZ_TIMER)
					{
						/* ---------------------------- */
						/* Keep current column position */
						/* ---------------------------- */
/* #BG 11/08/20 ASK VIRTUAL KBD
						if ( (askmask & MASK_CURSOR_END) && (askmask & MASK_ACTIV_EDIT_KEYS) )
*/
						if ( ((askmask & MASK_CURSOR_END) && (askmask & MASK_ACTIV_EDIT_KEYS)) || (askmask & MASK_VIRT_KBD) )
							AskContext.Start = abufdex;

						z = 1; 
						continue; 	 
					}
	 				else
					{ 
						bufwipe(); 
						/* ------------------------- */
						/* Visual ASK for alliance ! */
						/* ------------------------- */
						return( CloseVisualFont( SOFTERROR ) );
					}
				}
			}
#endif
#endif	/* ! ABAL_RTL */

			if ( AskContext.Flags & 2)
				ask_curser_on();

			/* Read Keyboard Character */
			/* ----------------------- */
/* #BG 21/04/20 ASK VIRTUAL KBD */
			if (!(c = GetVirtKeybChar()))
				c = x_getch();

			if ( AskContext.Flags & 2)
				ask_curser_off();

			AskContext.Finish = abufdex;	

/* #BG 11/08/20 ASK VIRTUAL KBD
			if ( (abufdex == 0) || ((askmask & MASK_ACTIV_JUMP_ANY) != 0) )
*/
			if ( (abufdex == 0) || ((askmask & MASK_ACTIV_JUMP_ANY) != 0) || ((askmask & MASK_VIRT_KBD) !=0) )
			{
				if ( is_hotkey( (EXAWORD) c ) == 0 )
				{ 
					/* Check for Keep Data Input */
					/* ------------------------- */
					if ((askmask & MASK_VIRT_KBD) == 0)	/* #BG 11/08/20 ASK VIRTUAL KBD */
						if ((askmask & (MASK_ACTIV_JUMP_ANY | MASK_KEEP_DATA)) != (MASK_ACTIV_JUMP_ANY | MASK_KEEP_DATA) )
						{
							/* Both Options needed so do nothing */
							/* --------------------------------- */ 
							/* Visual ASK for alliance ! */
							/* ------------------------- */
							return( CloseVisualFont( SOFTERROR ) );
						}

					/* Exit Due to HotKey and Keep Data already Input */
					/* ---------------------------------------------- */
					if ( (askmask & (MASK_ACTIV_JUMP_ANY | MASK_KEEP_DATA | MASK_DONOT_TRUNK)) == (MASK_ACTIV_JUMP_ANY | MASK_KEEP_DATA | MASK_DONOT_TRUNK) )
					{
						/* Keep up to End of String */
						/* ------------------------ */
#ifdef	VERSION666
						if ( askmask & MASK_SHIFT_LEFT )
							seekfin(1);
						else
#endif
							seekfin(0);
					}
/* #BG 11/08/20 ASK VIRTUAL KBD */
					if ((askmask & MASK_VIRT_KBD) !=0)
					{
						// Sauvegarde la position courante du curseur
						EXAWORD v = abufdex;

						seekfin(1);

						// Restaure la position courante du curseur pour le retour ds le ASK apres debranchement
						AskContext.Start = v;
					}

					z = askout(2,1); 
					continue;
				}
			}

			/* ------------------------ */
			/* Remove Mouse information */
			/* ------------------------ */
			c &= 0x00FF;   

			/* ------------------------------------- */
			/* If now a NULL character then Continue */
			/* ------------------------------------- */
			if ( c == 0 )
				continue;	

			if ( (abufdex == 0) && ((askmask & MASK_CR_KEEP) != 0) && (c == IO_RC) )
			{
				/* ------------------------- */
				/* Visual ASK for alliance ! */
				/* ------------------------- */
				return( CloseVisualFont( SOFTERROR ) );
			}

			if ((CutKey != 0) && ( c == CutKey ))
			{
#ifdef	UNIX
				if ((abufbig - abufdex) > 0 )
					publish_selection( &askbuf[abufdex], (abufbig-abufdex) );
#endif
				continue;
			}

			/* --------------------------------------------- */	
			/* Perform Special key checking ANNUL BACKSP etc	*/
			/* ---------------------------------------------	*/	
			if ( (EXAWORD) c == syskey[IO_CAN] )
			{ 
				bufwipe(); 
				z = 0; 
				continue;
			}

			if ( (EXAWORD) c == syskey[IO_BAK] )
			{ 
				if ( abufdex == 0 )
				{
					switch ( maskwork() )
					{
						case 0  :	return( CloseVisualFont( SOFTERROR ) );
						case 3  :	z = 0;
						default :	continue;
					}
				}

				askbak();   

				z = 0;	
				continue;
			}

			if ( (EXAWORD) c == syskey[IO_BAS] )
			{
				switch ( maskwork() )
				{
					case 0  :  	return( CloseVisualFont( SOFTERROR ) );
					case 3  :	z = 0;
					default :	continue;
				}
			}

			if ( (EXAWORD) c == syskey[IO_UP]  )
			{
				switch ( maskwork() )
				{
					case 0  : 	return( CloseVisualFont( SOFTERROR ) );
					case 3  :	z = 0;
					default :	continue;
				}
			}

			if (( (EXAWORD) c == syskey[IO_TOP] ) || ( (EXAWORD) c == 0x001C ))
			{	
				if (askmask & MASK_ACTIV_EDIT_KEYS)
				{
					if ( fmtgod[fmtdex] < askmust )
						fmtgod[fmtdex] = askmust; 

					askl += ((BINAIRE) (AskInfos(XLIN) - (askl + ( (abufdex + (askc-1)) / AskInfos(CONF2) ))));
					askmust = 0; z = 0;
					abufdex = 0; fmtdex = 0; 
					pos(askl,askc); 
				}
				else
				{
					switch ( maskwork() )
					{
						case 0  :	return( CloseVisualFont( SOFTERROR ) );
						case 3  :	z = 0;
						default :	continue;
					}
				}

				continue;
			}

			if ( (EXAWORD) c == syskey[IO_FOR] )
			{ 
				if ( z == 2 )
				{
					switch ( maskwork() )
					{
						case  0 : return( CloseVisualFont( SOFTERROR ) );
						case  3 : z = 0;
						default : continue;
					}
				}

				/* Check for Data Input Not Started */
				/* -------------------------------- */
				abufbig = lenuze((BPTR) askbuf, fmtlen);

				/* Check for Mode insert or overwrite */
				/* ---------------------------------- */
				if ( insflg == 0 )
				{
					/* Check for Legal Character Available */
					/* ----------------------------------- */
					if ( abufdex < abufbig )
					{
						/* Insert Not Active so get Character */
						/* ---------------------------------- */
						c = askbuf[abufdex];
						if ((x = chkfmt(c)) == 0)
						{	
							/* If REJECTED	*/
							switch ( maskwork() )
							{
								case 0 : return( CloseVisualFont( SOFTERROR ) );
								case 3 : z = 0;
								default: continue;
							}
						}
					}
					else
					{
						/* Test for Requirements not Fullfilled */
						/* ------------------------------------ */
						if ( abufdex < fmtlen )
						{
							/* Collect the current Character */
							/* ----------------------------- */
							c = askbuf[abufdex];
							if ((x = chkfmt(c)) == 0)
							{	
								/* If REJECTED	*/
								switch ( maskwork() )
								{
									case 0 : return( CloseVisualFont( SOFTERROR ) );
									case 3 : z = 0;
									default: continue;
								}
							}
							z = bufgest( c ); 
							continue;
						}
						else
						{
							/* Character not available Test MASK Errors */
							/* ---------------------------------------- */
							switch ( maskwork() )
							{
								case  0 : return( CloseVisualFont( SOFTERROR ) );
								case  3 : z = 0;
								default : continue;
							}
						}
					}
				}

				/* Perform Buffer Management */
				/* ------------------------- */
				if ( c > 0 )
				{
					if ( insflg == 0 )
					{
						/* Perform FORMAT and MASK Validity checks		*/
						/* ---------------------------------------		*/
						if ((x = chkfmt(c)) == 0)
						{	/* If REJECTED	*/
							switch ( maskwork() )
							{
								case 0 : return( CloseVisualFont( SOFTERROR ) );
								case 3 : z = 0;
								default: continue;
							}
						}
					}

					z = bufgest( c ); 
				}
				continue;
			}
			else
			{	
				/* Select Key code and filter speciale Keys */
				/* ---------------------------------------- */
				switch ( c )
				{
					/* ASK KEY      : ESCAPE   : No effect at this stage of an ask */
					/* ----------------------------------------------------------- */
					case IO_ESC	: 
						switch ( maskwork() )
						{
							case 0  : return( CloseVisualFont( SOFTERROR ) );
							case 3  : z = 0;
							default : continue;
						}

					/* ASK KEY      : RETURN    : Accepts current input if FMT OK  */
					/* ----------------------------------------------------------  */
					case IO_RC	:
						z = askout(z,1);
						continue;

					/* ASK Editor KEY : FIN/END : position at end of current input */
					/* ----------------------------------------------------------- */
					case IO_FIN	:
						if (askmask & MASK_ACTIV_EDIT_KEYS)
						{ 
							abufbig = lenuze((BPTR) askbuf, fmtlen);
							z = seekfin(0);
						}
						else
						{
							switch ( maskwork() )
							{
								case 0  : return( CloseVisualFont( SOFTERROR ) );
								case 3  : z = 0;
								default : continue;
							}
						}
						continue;

					/* ASK Editor KEY : INSERT  : Toggle the insert status flag */
					/* -------------------------------------------------------- */
					case IO_INS	:
						if ( ( z == 0 ) && (askmask & MASK_ACTIV_EDIT_KEYS) ) 
						{
							abufbig = lenuze((BPTR) askbuf, fmtlen);
							if ( insflg == 0 )
								{ insflg = 1; }
							else 
								{ insflg = 0; }
							SignalStatus(insflg);
						}
						continue;

					/* ASK Editor KEY : DELETE  : Deletes character to Left */
					/* ---------------------------------------------------- */ 
					case IO_DEL	:  
						if ( (z==0) && (askmask & MASK_ACTIV_EDIT_KEYS) ) 
						{
							abufbig = lenuze((BPTR) askbuf, abufbig);
							if ( abufdex < abufbig )
							{
								z = abufdex; x = abufbig;
								if ( x > 0 )
								{
									x--; abufbig--;

									while ( z < x )
									{
										askbuf[z] = askbuf[z+1];
										askvisi(askbuf[z++]);
									}

									askbuf[z] = IO_ESP; askvisi(IO_ESP);
									/* askl += ((BINAIRE) (AskInfos(XLIN) - (askl + ((z + (askc-1)) / AskInfos(CONF2))))); */
									pos( (askl + (((askc-1) + abufdex) / AskInfos(CONF2))) ,((((askc-1) + abufdex) % AskInfos(CONF2))+1));
								}
								z = 0;
							}
						}
						continue;	

					default		:
						/* If awaiting RC then filter all other keys */
						/* ----------------------------------------- */
						if ( z == 2 )
						{ 
							switch ( maskwork() )
							{
								case 0 : return( CloseVisualFont( SOFTERROR ) );
								case 3 :	z = 0; 
								default: continue;
							}
						}
				}	/* switch */
			}

			/* Perform FORMAT and MASK Validity checks		*/
			/* ---------------------------------------		*/
			if ((x = chkfmt(c)) == 0)
			{	/* If REJECTED		*/
				switch ( maskwork() )
				{
					case 0 :	return( CloseVisualFont( SOFTERROR ) );
					case 3 : z = 0;
					default:	continue;
				}
			}

			/*
			 *	Valid character so display (MASK_SECRET controled) and
			 *	Place it in the keyboard buffer
			 */

			z = bufgest( c );	/* Try and put byte into Input buffer	*/
		}
		while ( z != 1 );

		/* Clear to end of input line   */
		/* ---------------------------- */
		 cleol();
		 
	} /* Endif Fmtlen > 0 */
	else
		askbuf[0] = IO_NUL;

	as_fmt(3);		/* Clear any further FORMAT actions */

	return( CloseVisualFont( GOODRESULT ) );
}


EXAWORD	ll_ask(bufmax)
EXAWORD	bufmax;
{
	return( low_level_ask(bufmax) );
}



/*
 *	V S H I F T ( )
 *	---------------
 *	This function performs the FMT_V decimale place shifting for
 *	the sf_ask function.
 *
 */
#ifdef	DIT826

VOID vshift( )
{
	register BINAIRE x,y;
	BINAIRE	w,z;

if ( fbcdv != 0 ) { 		     /* Zero means no change ! 	*/
	x = strlen((BPTR) askbuf); /* Length of String in buffer 	*/
				     /* Then find the decimale point */

	for ( z = 0, y = x; z < x ; z++ ) { if (askbuf[z] == '.') {y = z;} }
	if ( fbcdv < 0 ) { fbcdv++; } /* Adjust towards -1 	*/
	if ( y < x ) { /* Alors Virgule existante -- Avale le	*/
		for ( z = y; z < x; z++ ) { askbuf[z] = askbuf[z + 1]; }
		}
	z = y - fbcdv;		/* Calculate new point	*/
	if ( z < 0 ) {	/* Alors inserer abs(z) zeros entete */
		z *= -1; w = (x - 1); z++;
		while ( w >= 0 ) {
			askbuf[w + z] = askbuf[w]; w--;
			}
		x += z; z--; w = z;
		while ( w >= 0 ) { askbuf[w] = '0';w--; }
		z = 1;
		}
	else	{ if ( z >= x ) { /* Alors inserer (z-x)+1 zeros entail */
			for ( w = x; w <= z; w++ ) { askbuf[w] = '0'; }
			x += z;
			}
		}

	/* Deplacer les chiffres pour pouvoir inserer le virgule	*/
	for ( w = x; w > z; w-- ) { askbuf[w] = askbuf[w - 1]; }
	askbuf[z] = '.'; 	/* Set Sepdec later		*/ 
	askbuf[x+1] = 0;	/* Set String end 		*/
	}
return;
}

#endif

EXAWORD	set_preferentiel()
{
	EXAWORD	askholder=MOINS_UN;

	/* Check for default */
	/* ----------------- */
	if ( conf( 14 ) != 0 ) {

		/* Set Default colour */
		/* ------------------ */
		if ( askcolour != MOINS_UN ) {
			askholder = ((LastFore << 8) | LastBack);
			iof_backgr(( askcolour & 0x000F ));
			iof_foregr((( askcolour >> 8 ) & 0x000F));
			}
		}
	else	{
		/* Set Default Atributs */
		/* -------------------- */
		if ( askatrib != MOINS_UN ) {
			askholder = AtbContext;
			interpret_atributs( askatrib );
			}
		}
 
	return( askholder );

}

VOID	reset_preferentiel( askholder )
EXAWORD	askholder;
{
	if ( conf( 14 ) != 0 ) {
		/* Set Default colour */
		/* ------------------ */
		if ( askcolour != MOINS_UN ) {
			iof_backgr(( askholder & 0x000F ));
			iof_foregr((( askholder >> 8 ) & 0x000F));
			}
		}
	else	{
		/* Set Default Atributs */
		/* -------------------- */
		if ( askatrib != MOINS_UN )
			interpret_atributs( askholder );
		}
	return;

}

#ifndef	ABAL_RTL

/*  
 *		Function Standard ASK=1 
 *		-----------------------
 *
 *	Syntax	:	IOF	ASK=1:*varptr	
 */

VOID	undo_ask_action( sfx )
EXAWORD	sfx;
{
	EXAWORD	HoldHotKey;
	BPTR	HoldFDEX;
	HoldHotKey = LastJumpKey;
	if ( askaction != 0 ) {
#ifndef	ABAL_RTL
		HoldFDEX = fdex;
#endif
		pos( actionlin, actioncol );
		dynadex = AskDynamic;
		fdex   = AskActionFdex;
		fmtptr = AskActionFormat;
		fmtflg = AskActionFlag;
		(void) sf_print( sfx );
#ifndef	ABAL_RTL
		fdex = HoldFDEX;
#endif
		}
	LastJumpKey = HoldHotKey;
	return;
}
#endif


/*
 *	S I G N S H O W ( xig )
 *	-----------------------
 *
 *	Affichage du signe pour Numeriques
 *
 */

VOID	signshow( xig )
EXAWORD	xig;
{
 if ( (JUSTIF_L) == 0 ) { 	/* If ! left Justified 	*/
	exputch( xig );		/* Display Sign		*/
	SIGN_OFF;		/* Clear Sign Bit	*/
	}
return;
}

/*
 *	N G E S T F M T ( )
 *	-------------------
 *	Controls access to format codes during Numeric PRINT output
 *	REM: Converts Sign formats to FMT_N if no further sign to show
 */

EXAWORD	ngestfmt()
{
	/* Collect Next format Element Avoiding ZERO counts */
	/* ------------------------------------------------ */
	while ( fmtgod[fmtdex] == 0 ) {
		fmtdex++;
		if ( fmtdex >= fmtmax ) 
			return(0);
		}
	fmthld[fmtdex] &= 0x00F0;	/* Reset Filter Bits */
	return(1);
}



EXAWORD	nbcddig()
{
	EXAWORD	x;
	do 	{
		if ( bcdphc == 2 ) {
			x = ydigit; 
			bcdphc = 1;
			}
		else 	{
			x = (EXAWORD) *(workptr1++); 
			worklen1--; 
			ydigit = (x & 0x000F);
			x >>= 4; bcdphc = 2;
			}
		if (( x == 0 ) && ( dgfl == 0 )) { 
			continue; 
			}
		dgfl = 1;
		if ( x >  0x000A ) 
			x = MOINS_UN;
		}
	while (( dgfl == 0) || ( x == 0x000A)); 
	return(x);
}

/*
 *	V I S I H F I L L ( )
 *	---------------------
 *	Displays a formated header character
 *
 */

VOID	visihfill( vctrl )
EXAWORD	vctrl;
{
	EXAWORD	sflg;

sflg=0;

while ( vctrl > 0 ) {
	switch ( fmthld[fmtdex] ) {
		case 0x0040 : if (SIGN_CHK) {
				      if (( fmtgod[fmtdex] == 1 ) || ( vctrl == 1)) {
					   sflg = 1; break;
					   }
					}
			      if (JUSTIF_L) { xdigit++; break;	}
			      exputch(zpadn);   break;
#ifdef	ABAL14
		case 0x0090 : fmthld[fmtdex] = 0x0000;
#endif
		case 0x0000 : exputch(zpadn); 	break;
		case 0x0080 : if (SIGN_CHK) { signshow(xsign); }
			      exputch('0'); 	break;
		default	    : exputch('e');
		}
	fbcde--;
	if (MILSEP_CHK) {
		if ((( fbcde % fmtmilcount ) == 0 ) && ( fbcde != 0 )) {
			if ( fmthld[fmtdex] & 0x0080 ) { exputch(fmtmil); }
			else  { if ((JUSTIF_L) && ( fmthld[fmtdex] == 0x0040 )) { 
						xdigit++; 	
						}
				else          { exputch(zpadn); } 
				}
			}
		}
	if ( sflg == 1 ) { sflg = 0; signshow(xsign); }
	fmtgod[fmtdex]--;
	if ( fmtgod[fmtdex] == 0 ) { 
		(VOID) ngestfmt(); 
		}
	vctrl--;
	}

return;
}

/*
 *	V I S I H E A D ( vctrl )
 *	-------------------------
 *	Displays a formated header character
 *
 */

VOID	visihead( vctrl , hpadd)
EXAWORD	vctrl,hpadd;
{
	EXAWORD	sflg;
	EXAWORD	xchf;

		 if (SIGN_CHK) { 
		   if (MILSEP_CHK) {
		     if ((( fbcde % fmtmilcount ) == 0 ) && ( fbcde != 0 )) {
			if ( hpadd == 0 ) {
				if ((JUSTIF_L) && ( fmthld[fmtdex] == 0x0040 )) 
					xdigit++;
				else 	exputch(zpadn);
				} /* HPADDCHK */
			} 	  /* MOD3CHECK */
		      }   	  /* MILSEPCHK */
		   signshow(xsign);
		   }      	  /* SIGNCHECK */
sflg=0;
while ( vctrl > 0 ) {
	xchf = nbcddig();
	if ( xchf != MOINS_UN ) { exputch( xchf | 0x0030); }
	else {
		switch ( fmthld[fmtdex] ) {
			case 0x0040 : 
#ifdef	ABAL14
			case 0x0090 :
#endif
			case 0x0000 : exputch(zpadn); 	break;
			case 0x0080 : exputch('0'); 	break;
			default	    : exputch('e');
			}
		}
	fbcde--;
	if (MILSEP_CHK) {
		if ((( fbcde % fmtmilcount ) == 0 ) && ( fbcde != 0 )) { exputch(fmtmil);  }
			}
	fmtgod[fmtdex]--;
	if ( fmtgod[fmtdex] == 0 ) { 
		(VOID) ngestfmt(); 
		}
	vctrl--;
	}
return;
}

VOID	visitail( wot,vctrl )
EXAWORD	wot,vctrl;
{
	EXAWORD	xchf;

#ifdef	ABAL14
if (( wot == 1 ) && ( fmthld[fmtdex] == 0x0090 ) && ( vctrl > 0 )) {
	fmthld[fmtdex] = 0x0080;
	}
#endif

while ( vctrl > 0 ) {
	if ( wot == 0 ) {	/* Filler Bytes */
		switch ( fmthld[fmtdex] ) {
			case 0x0040 :
#ifdef	ABAL14
			case 0x0090 :
#endif
			case 0x0000 : exputch(zpadn);	break;
			case 0x0080 :	if (SEPDEC_CHK) {
						exputch(fbcdd); 
						SEPDEC_OFF;
						}
				      exputch('0');
				      break;
			default     : exputch('e');
			}
		}
	else	{		/* String Bytes	*/
		if (SEPDEC_CHK) { exputch(fbcdd); SEPDEC_OFF; }
		xchf = nbcddig();
		if ( xchf != MOINS_UN ) { exputch( xchf | 0x0030); }
		else {
			switch ( fmthld[fmtdex] ) {
				case 0x0040 : 
				case 0x0000 : exputch(zpadn); 	break;
#ifdef	ABAL14
				case 0x0090 : 
#endif
				case 0x0080 : exputch('0'); 	break;
				default	    : exputch('e');
				}
			}
		}
	fmtgod[fmtdex]--;
	if ( fmtgod[fmtdex] == 0 ) { 

		/* Locate next valid Format Element */
		/* -------------------------------- */
		(VOID) ngestfmt();
#ifdef	ABAL14
		/* Check for FMT_O */
		/* --------------- */
		if ( fmthld[fmtdex] == 0x0090 ) {

			/* If Fractional Digits then FMT_Z */
			/* ------------------------------- */
			if ( wot == 1 ) {
				fmthld[fmtdex] = 0x0080;
				}
			/* Otherwise FMT_N */
			/* --------------- */
			else	{
				fmthld[fmtdex] = 0x0000;
				}
			}
	/* ------ */
#endif	/* ABAL14 */
	/* ------ */
		}
	vctrl--;
	}
return;
}

/* 
 *	N U M F M T ( )
 *	---------------
 *	Affichage formatee numeriques : CHAR(#)  INT(%)  et BCD
 *	REM using WORKPTR1 / WORKLEN1 as Source BCD string to display
 *
 */


EXAWORD	numfmt()
{
	EXAWORD	inh,infh;
	EXAWORD	oo;

	/* Ensure Correct BCD format (avoid FIX inversions) */
	/* ------------------------------------------------ */
	if ((((EXAWORD) *workptr1 ) & 0x00F0 ) == 0x0040 ) 
	{
		workptr1 = negbcdcpy(workptr1,worklen1);
	}

	/* Ensure Bcd String is Correct */
	/* ---------------------------- */
	switch ((((EXAWORD) *workptr1 ) & 0x00F0 )) 
	{
	case 0x00C0 :
	case 0x00B0 : break;
	default     : err_val = ABAL_BCDFORM; return( SOFTERROR );
	}

	/* Calculate Real Digit count in string with FMT_V adjust */
	/* ------------------------------------------------------ */	
	if ( fbcdv < 0 ) fbcdv++; 		/* Control FMT_V Value	*/

	/* Reorganise BCD String for Format V */
	/* ---------------------------------- */
	if ( fbcdv != 0) 
	{
		(VOID) std2bcd((BPTR) workptr1,(EXAWORD) worklen1,(BPTR) PowerZone,(EXAWORD) BCDMAX,(BINAIRE) fbcdv);
		workptr1 = (BPTR) PowerZone;
		worklen1 = BCDMAX;
		fbcdv    = 0;
	}

	/* Perform BCD Evaluation : Digit Count */
	/* ------------------------------------ */
	if ((infh = bcdeval(workptr1,worklen1)) != 0) 
	{

		/* If Not Zero then Adjust for Format V */
		/* ------------------------------------ */
		tail = (infh & 0x00FF) - fbcdv;	/* Calc Fractions	*/
		head = (infh >> 8    ) + fbcdv;	/* Calc Entiers		*/
		if ( head < 0 ) { head = 0; }	/* Control Entiers	*/
		if ( tail < 0 ) { tail = 0; }	/* Control Fractions	*/
	}
	else	
	{
		/* Else Ensure ZERO */
		/* ---------------- */
		head = 0; tail = 0;
	}

	/* Calculate Real/Required Digit control counters */
	/* ---------------------------------------------- */

	if ( head > fbcde )	{ hfill = 0; saute = ( head  - fbcde ); }
	else			{ saute = 0; hfill = ( fbcde - head  );	}

	if ( tail > fbcdf )	{ tfill = 0; tail = fbcdf; }
	else			{ tfill = ( fbcdf - tail); }

	/* Sign Adjustments */
	/* ---------------- */
	xsign  = (EXAWORD) *(workptr1++); 	worklen1--;
	ydigit = xsign & 0x000F; 		bcdphc = 2;	
	oo = 0;

#ifdef	ABAL14
	/* Check for Zero Inhibit Required */
	/* ------------------------------- */
	if ( InhibitZero != 0 ) {

		/* If Bcd is Zero */
		/* -------------- */
		if (infh == 0 ) {

			/* Generate and Output Blank Zone */
			/* ------------------------------ */
			for (inh=0; inh < fmtmax; inh++) {
				switch ( fmthld[inh] ) {
					case FMT_Z : /* FMT_Z */
					case FMT_O : /* FMT_O */

						fmthld[inh] = FMT_N;

					}
				} 			
			/* Raz Sign Values */
			/* --------------- */
			fbcdp = zpadn; fbcdm = zpadn; fbcdd = zpadn;
			}
		}	
#endif
	if (SIGN_CHK) {

		/* Convert to ASCII Sign character */
		/* ------------------------------- */
		if ( (xsign & 0x00F0) == 0x00C0 ) 	{ xsign = fbcdp; }
		else					{ xsign = fbcdm; }
		/* Convert FMT_SIGNs to FMT_N */
		/* -------------------------- */
		if ( xsign == IO_ESP )  { SIGN_OFF;	 }
		else	{ 
			if (hfill == 0) { 
					saute++; fbcde--; oo = 1; 
					} 
			}
		}


	/* Initialise Format Matrix */
	/* ------------------------ */
	fmtdex = 0; dgfl = 0; xdigit = 0;
	if ( ngestfmt() == 0 ) 
		return(	GOODRESULT);

	fmtgod[fmtdex] -= oo;
	if ( fmtgod[fmtdex] == 0 )
		if ( ngestfmt() == 0 )
			return(	GOODRESULT);

	/* Display Header filler Digits	*/
	/* ---------------------------- */
	visihfill(hfill); 

	/* Ignore unwanted Head  Digits	*/
	/* ---------------------------- */
	while ( saute > 0 ) { (VOID) nbcddig(); saute--; head--;}

	/* Display Header String Digits	*/
	/* ---------------------------- */
	visihead(head,hfill);

	/* Display Tailer String Digits	*/
	/* ---------------------------- */
	visitail(1,tail);

	/* Display Tailer filler Digits	*/
	/* ---------------------------- */
	visitail(0,tfill);

	if (SEPDEC_CHK) { exputch(zpadn); }
	if (JUSTIF_L) {
		if (SIGN_CHK) { exputch(xsign); }
		if ( xsign != ' ' )  { zpadn = ' '; } 
		while ( xdigit > 0 ) { exputch(zpadn); xdigit--; }
		}

	return(	GOODRESULT );
}

VOID	HexFormat(workval1)
EXAWORD	workval1;
{
	EXAWORD	digits;
	EXAWORD prefix;
	EXAWORD	index;

	if ( fbcde == 0 ) return;

	/* Convert integer value to Hexa String and collect digit count */
	/* ------------------------------------------------------------ */
	switch ( (worktyp1 & VARB_ISOL ) ) 
	{
	case	VARB_FOUR	:
	case	VARB_INT8	:
	case	VARB_INT16	:
		digits = itohex( workval1 , (BPTR) askbuf , (((worktyp1 & 3)+1)*2));
		break;
	case	VARB_INT32	:	
		digits = ltohex( workval1 , (BPTR) askbuf , 8 );
		break;
	case	VARB_INT64	:	
		digits = ltohex( workval1 , (BPTR) askbuf , 16 );
	}

	/* digit count for ZERO value */
	/* -------------------------- */
	if ((digits == 1) && (askbuf[0] == '0')) { digits = 0; }

	/* Determination of possible leading zeros (filler bytes) */
	/* ------------------------------------------------------ */ 
	if ( fbcde >= digits ) 	{ prefix = fbcde - digits; index  = 0; }
	else	{ index  = digits - fbcde; digits = fbcde; prefix = 0; }

	/* Initialise Format Matrix */
	/* ------------------------ */
	fmtdex = 0; dgfl = 0; xdigit = 0;
	if ( ngestfmt() == 0 ) { return; }

	/* Display Prefix filler Digits	*/
	/* ---------------------------- */
	if ( prefix > 0 ) visihfill(prefix); 

	/* Display Actual Digits */
	/* --------------------- */
	while ( digits > 0 ) 
	{

		/* Display current digit adjusting count and index */
		/* ----------------------------------------------- */
		exputch(askbuf[index++]); digits--;

	}

	/* Perform Left alignement Padding */
	/* ------------------------------- */
	if (JUSTIF_L) 
	{
		while ( xdigit > 0 ) { exputch(zpadn); xdigit--; }
	}

	return;

}

EXAWORD	device_verification()
{
	/* Verify Establish Device */
	/* ----------------------- */
	switch ( prndest ) 
	{
		case 0  :
			/* Print to Buffer */
			/* --------------- */
			if ( prnptr == (BPTR) 0 ) 
				return(SOFTERROR);
			else	return(GOODRESULT);

		case 1  :	
			/* Print to Screen */
			/* --------------- */
			prnfid = 0; 
			return( GOODRESULT );

		default :	
			/* Set up Cico Printer Interface */
			/* ----------------------------- */
			return( activate_cico_printer( prndest ) );
	}
}

/*	----------------------------------------------------------------    */
/*	E X E C U T E U R    and     L I B R A R Y     I N T E R F A C E    */
/*	----------------------------------------------------------------    */

/*	-----------------	*/
/*	I O F _ F L U S H 	*/
/*	-----------------	*/

EXAWORD	iof_flush()
{
#ifdef	ABAL_RTL
	if ( iof_started ) {
#endif
#ifdef BUF_CICO
		x_bflush();		/* Flush CICO buffers now !!! */
#endif

		/* Check for Memory Device and Clear to End of Zone */
		/* ------------------------------------------------ */
		if (( prndest == 0 ) && (!oblig))
			for ( ; prnleng > 0; prnleng-- )
				*(prnptr++) = ' ';

		/* Check for and Liberate Format infos */
		/* ----------------------------------- */
		if ( (fmtflg & 0x0080) != 0 ) 
			liberate(fmtbase);

		fmtflg = 0;

#ifndef	ABAL_RTL
		/* Check for EXTERNAL VARIABLE Keep Flag */
		/* ------------------------------------- */	
		if ( sicico & ONSEM_XVRB ) {
			extwrite = 1; sicico &= OFSEM_XVRB;
			descptrw  = (*extv_base).descw;
			worktypw  = (*extv_base).typew;
			workeepw  = (*extv_base).keepw;
			worklenw  = (*extv_base).lengw;
			workptrw  = (*extv_base).wptrw;
			liberate(extv_base);
			}
#endif
	
		/* Check for Print File Device and update File Table */
		/* ------------------------------------------------- */
		if (( prndest > 1 )
		&&  (( fidperm & NGF_TYP) == NGF_IM))
			update_cico_printer();

		prndest = 1;

#ifdef UNISYS
		if (( timersem & TIME_ACTIF ) != 0 )
			(VOID) sigrelse( SIGALRM );
#endif

#ifdef AIXXXX
		/* ---------------------------------------------- */
		/* 4/4/2005 : IJM				  */
		/* this has been removed for the GFI AIX 5.1 port */
		/* ---------------------------------------------- */
		if (( timersem & TIME_ACTIF ) != 0 ) 
			(VOID) sigsetmask( signalmask );
#endif

#ifdef	ABAL_RTL
		iof_started = 0;
#endif

		/* Check for CICO errors */
		/* --------------------- */
		if ( err_val == 0 ) 
			return(GOODRESULT);
		else 	return(SOFTERROR);
#ifdef	ABAL_RTL
		}
	else	return( GOODRESULT );
#endif

}

/*	-----------------	*/
/*	I O F _ S T A R T	*/
/*	-----------------	*/

void	iof_start()
{
#ifdef	AIXXXX
	int	signalmask;
#endif
#ifdef	ABAL_RTL
	if ( iof_started )
		(void) iof_flush();
#endif

	ll_ask_flag = 0;

#ifdef	AIXXXX
	if (( timersem & TIME_ACTIF ) != 0 ) {	
		signalmask = sigblock((1 << (SIGALRM - 1)) );
		}
#endif

#ifdef UNISYS 
	if (( timersem & TIME_ACTIF ) != 0 ) {	
		(VOID) sighold( SIGALRM );
		}
#endif

	/* Reset all PRINT/ASK Control Values */
	/* ---------------------------------- */
	jmpdex  = 0; 
	askmust = 0; 	
	fmtflg  = 0; 
	prndest = 1;
	fmtchk  = 0x000F; 	
	oblig   = 0;
	dynadex = 0; 
	dynamax = 0; 	
	err_val = 0;

#ifdef	BUF_CICO
	x_bstart();		/* Activate CICO bufferisation	*/
#endif
#ifdef	ABAL_RTL
	iof_started = 1;
#endif
	return;

}

/*	-------------		*/
/*	I O F _ A T B		*/
/*	-------------		*/

EXAWORD	iof_atb( atb_number )
EXAWORD	atb_number;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
#ifdef	ABAL14
	interpret_atributs( atb_number );
#else
 	atb(atb_number); 
#endif

	return(GOODRESULT);
}

#ifdef	ABAL64
/*	----------------------------------------	*/
/*		I O F _ E B A C K G R 			*/
/*	----------------------------------------	*/
/*							*/
/*	Set Extended Background Colour:			*/
/*							*/
/*		Standard Colour Name 			*/
/*		RGB HEX VALUE	#RRGGBB			*/
/*		RGB KEY TRIAD	RGB(R,G,B)		*/
/*		RGBA VECTOR	RGBA(R,G,B,A)		*/
/*							*/
/*	----------------------------------------	*/

void	iof_ebackgr( BPTR sptr, EXAWORD slen )
{
	BYTE	c;
	x_putch(0x001B);
	x_putch('S');
	while ( slen-- != 0 )
	{
		if ((c = *(sptr++)) == ' ')
			continue;
		else if ( c == ';' )
			break;
		else	x_putch(c);
	}
	x_putch( ';' );
	return;
}

/*	----------------------------------------	*/
/*		I O F _ E F O R E G R 			*/
/*	----------------------------------------	*/
/*							*/
/*	Set Extended Foreground Colour:			*/
/*							*/
/*		Standard Colour Name 			*/
/*		RGB HEX VALUE	#RRGGBB			*/
/*		RGB KEY TRIAD	RGB(R,G,B)		*/
/*		RGBA VECTOR	RGBA(R,G,B,A)		*/
/*							*/
/*	----------------------------------------	*/

void	iof_eforegr( BPTR sptr, EXAWORD slen )
{
	BYTE	c;
	x_putch(0x001B);
	x_putch('R');
	while ( slen-- != 0 )
	{
		if ((c = *(sptr++)) == ' ')
			continue;
		else if ( c == ';' )
			break;
		else	x_putch(c);
	}
	x_putch( ';' );
	return;
}

#endif /* ABAL64 */

/*	-------------------	*/
/*	I O F _ B A C K G R 	*/
/*	-------------------	*/

void	iof_backgr( couleur )
EXAWORD	couleur;
{
#ifdef	ABAL_RTL
	couleur &= 0x0007;
	if ( ! iof_started )
		iof_start();
#endif
	if ( prndest != 0 )
		backgr((LastBack = couleur)); 
	else	{
		if ( prnleng >= 3 ) {
			*(prnptr++) = 0x001B;
			*(prnptr++) = 's';
			*(prnptr++) = ((couleur & 0x000F) | 0x0030);
			prnleng -= 3;
			}
		}
	return;
}

/*	-------------------	*/
/*	I O F _ F O R E G R 	*/
/*	-------------------	*/

void	iof_foregr( couleur )
EXAWORD	couleur;
{
#ifdef	ABAL_RTL
	couleur &= 0x000F;
	if ( ! iof_started )
		iof_start();
#endif
	if ( prndest != 0 )
		foregr((LastFore = couleur));
	else	{
		if ( prnleng >= 3) {
			*(prnptr++) = 0x001B;
			*(prnptr++) = 'r';
			if ((couleur = ((couleur & 0x000F) + 0x0030)) >= 0x003A)
				couleur += 7;
			*(prnptr++) = couleur;
			prnleng -= 3;
			}
		}
	return;
}



/*	-------------------	*/
/*	I O F _ D E V I C E 	*/
/*	-------------------	*/

EXAWORD	iof_device( nb )
EXAWORD	nb;
{
	iof_flush();
	prnptr  = (BPTR) askbuf;
	prndex  = 0; 
	prnleng = 0;
	prndest = nb;

#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	return( device_verification() );
}

/*	---------------------------------	*/
/*	I O F _ D E V I C E _ B U F F E R 	*/
/*	---------------------------------	*/

EXAWORD	iof_device_buffer ( mptr, mlen )
BPTR	mptr;
EXAWORD	mlen;
{
	iof_flush();
	prndest = 0; prnptr  = mptr; 
	prnfid  = 0; prnleng = mlen;

#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	return( device_verification() );
}


void	iof_gosub_num_hotkey( keycode, adresse )
EXAWORD	keycode;
EXAWORD	adresse;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	asktst[jmpdex]   = (EXAWORD) ((keycode & 0x01FF) | (_GOSUB_HOTKEY | _HIDDEN_HOTKEY));
	askjmp[jmpdex++] = adresse;
	return;
}


void	iof_goto_num_hotkey( keycode, adresse )
EXAWORD	keycode;
EXAWORD	adresse;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	asktst[jmpdex]    = (EXAWORD) ((keycode & 0x01FF) | _HIDDEN_HOTKEY);
	askjmp[jmpdex++]  = adresse;
	return;
}

EXAWORD	is_known_hotkey( keycode )
EXAWORD	keycode;
{
	EXAWORD	x;

	for ( x = 0; x < jmpdex; x++ )
		if ((asktst[x] & 0x01FF) == (EXAWORD) keycode )
			break;
	return( x );
}


void	iof_gosub_hotkeys( wptr, wlen, adresse )
BPTR	wptr;
EXAWORD	wlen;
EXAWORD	adresse;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif

	while ( wlen > 0 ) {

		if ( is_known_hotkey( *wptr ) == jmpdex ) {
			
			asktst[jmpdex]   = (EXAWORD) ((*wptr & 0x00FF) | (_GOSUB_HOTKEY | _VISIBLE_HOTKEY));
		 	askjmp[jmpdex++] = adresse;

 			}

		wlen--; wptr++; 

		}

	  return;
}

void	iof_goto_hotkeys( wptr, wlen, adresse )
BPTR	wptr;
EXAWORD	wlen;
EXAWORD	adresse;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif

	while ( wlen > 0 ) {

		if ( is_known_hotkey( *wptr ) == jmpdex ) {
			
			asktst[jmpdex]   = (EXAWORD) ((*wptr & 0x00FF) | _VISIBLE_HOTKEY);
		 	askjmp[jmpdex++]   = adresse;

 			}

		wlen--; wptr++; 

		}

	  return;
}

/*	-------------	*/
/*	iof_print_int	*/
/*	-------------	*/
EXAWORD	iof_print_int( valeur, type )
EXAWORD	valeur;
EXAWORD	type;
{
	EXAWORD	lerror;
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif

	InhibitZero = 0; 
	zpadn = IO_ESP; 
	fbcdc = 0; 
	fmthex = 0; 
	preference = 0;

	worktyp1 = type;

	if ( !(fmtflg & 0x0001)) 
		iform( type );
	else 	pr_fmt(2);

	if ( fmthex ) 
	{
		HexFormat(valeur);
		lerror = GOODRESULT;
	}
	else if ( worktyp1 == VARB_INT32 ) 
	{
	    	ltobcd(valeur,(BPTR) askbuf,(worklen1=BCDMAX));
		worktyp1 = VARB_BCD;
		workptr1 = (BPTR) &askbuf[0]; 
		lerror   = numfmt();
	}
	else if ( worktyp1 == VARB_INT64 ) 
	{
	    	htobcd(valeur,(BPTR) askbuf,(worklen1=BCDMAX));
		worktyp1 = VARB_BCD;
		workptr1 = (BPTR) &askbuf[0]; 
		lerror   = numfmt();
	}
	else	
	{
	    	itobcd(valeur,(BPTR) askbuf,(worklen1=BCDMAX));
		worktyp1 = VARB_BCD;
		workptr1 = (BPTR) &askbuf[0]; 
		lerror   = numfmt();
	}
	if ( fmtflg & 0x0001)
		pr_fmt(3); 
	return(lerror);

}

EXAWORD	iof_print_bcd( wptr, wlen )
BPTR	wptr;
EXAWORD	wlen;
{
	EXAWORD	lerror;
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif

	InhibitZero = 0; 
	zpadn       = IO_ESP; 
	fbcdc       = 0; 
	fmthex      = 0;
	preference  = 0;

	workptr1 = wptr; 
	worklen1 = wlen; 
	worktyp1 = 2;

	if (! (fmtflg & 0x0001) ) 
		iform( 2 );
	else 	pr_fmt(2); 

	lerror = numfmt();

	if (fmtflg & 0x0001) 
		pr_fmt(3); 

	return(lerror);

}

EXAWORD	iof_print_str( wptr, wlen )
BPTR	wptr;
EXAWORD	wlen;
{
	EXAWORD	maxi;
	EXAWORD	prnholder;
	EXAWORD	ej;
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif

	InhibitZero = 0; 
	zpadn 	    = IO_ESP; 
	preference  = 0;
	fbcdc       = 0; 
	fmthex      = 0;

	workptr1    = wptr; 
	worklen1    = wlen; 
	worktyp1    = 3;


	if ( fmtflg & 0x0001 ) { 
		pr_fmt(2); 
		maxi = DollarLength;
		}
	else	maxi = wlen; 

	/* Justification Droite et Gauche */
	/* ------------------------------ */
	if ( JUSTIF_L ) { /* Alors tie left margin */
		while (( *wptr == IO_ESP ) && ( wlen > 0 )) {
			wptr++; wlen--;
			}
		}

	if ( JUSTIF_R ) { /* Alors Right Justified */

		if ((ej = lenuse(wptr,wlen)) > maxi )
			ej = 0;
		else 	ej = maxi - ej;

		if ( JUSTIF_L ) { ej /= 2; }

		while (( ej > 0 ) && (maxi > 0)) { 
			exputch(zpadn); 
			ej--; maxi--; 
			}
		}	
#ifdef	ABAL21

	if (( preference != 0 )
	&&  (( prnholder = set_preferentiel()) != MOINS_UN )) {

		/* Affichage du Contenu */
		/* -------------------- */
		while (( wlen > 0 ) && ( maxi > 0 ) && (preference > 0 )) {

			if ( *wptr != IO_ESP ) 
				exputch(*wptr);
			else	exputch(zpadn);
	
			preference--; wlen--; maxi--; wptr++;

			}
		reset_preferentiel( prnholder );
		}
#endif

	/* Affichage du Contenu */
	/* -------------------- */
	while (( wlen > 0 ) && ( maxi > 0 )) {

		if ( *wptr != IO_ESP ) 
			exputch(*wptr);
		else	exputch(zpadn);

		wlen--; maxi--; wptr++;

		}

	/* Trailing spaces */
	/* --------------- */
	while ( maxi > 0 ) {
		exputch(zpadn); maxi--; 
		}

	if ( (fmtflg & 0x0001) != 0 ) 
		pr_fmt(3);

	return( GOODRESULT );
}

/*	---------------		*/
/*	I O F _ T A B V		*/
/*	---------------		*/

void	iof_tabv( nmb )
EXAWORD	nmb;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	if ( prndest > 1 ) {
		if ( nmb == 0 ) { exputch(IO_RC); }
		else	{
			while ( nmb > 0 ) {
				exputch(IO_LF);
				nmb--;
				}
			}
		}
	else	{
		exputch(IO_RC);
		while ( nmb > 0 ) { 
			exputch(IO_LF); nmb--; 
			}
		}

	return;

}

/*	---------------		*/
/*	I O F _ T A B C		*/
/*	---------------		*/

void	iof_tabc( nbc )
EXAWORD	nbc;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	if ( tabflg == 0) 
		holdline = AskInfos(XLIN);
	if (prndest >= 1) 
		pos(holdline,nbc );
	tabflg = 0;
	return; 

}

/*	---------------		*/
/*	I O F _ T A B L		*/
/*	---------------		*/

void	iof_tabl( nbl )
EXAWORD	nbl;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	holdline = (EXAWORD) nbl; 
	tabflg = 1;
	return;
}


EXAWORD	iof_format_string( fptr, flen )
BPTR	fptr;				/* Pointer to format string 	*/
EXAWORD 	flen;				/* Length  of format string 	*/
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif

	/* Check for currently allocated format zone */
	/* ----------------------------------------- */
	if ( (fmtflg  & 0x0080) != 0 ) { 

		/* Liberate and reset zone */
		/* ----------------------- */
		liberate(fmtbase);  fmtflg = 0; 

		}

	/* Reset dynamic controllers */
	/* ------------------------- */ 
	dynamax = 0; 	dynadex = 0;

	/* Set default format pointer and type */
	/* ----------------------------------- */
	fmtbase = fptr; fmtflg = 7;

	/* Check for ABAL FORMAT Code type */
	/* ------------------------------- */
	if ( *fmtbase != (EXABYTE) 0x00FE ) {

		/* Attempt conversion from BAL to ABAL format code */
		/* ----------------------------------------------- */
		if (( fmtbase = (BPTR) abalfmt((BPTR) fmtbase)) == (BPTR) 0) 
			fmtflg = 0;
		else	fmtflg = 0x0087;

		}

	/* Establish Format control pointers and flags */
	/* ------------------------------------------- */
	fmtptr = fmtbase;

	/* Clear all error values */
	/* ---------------------- */
	err_val = 0; errno = 0;

	/* Indicate success */
	/* ---------------- */
	return( GOODRESULT );

}

EXAWORD	iof_format_value( fvalue )
EXAWORD 	fvalue;
{
#ifdef	ABAL_RTL
	if ( ! iof_started )
		iof_start();
#endif
	/* Check for Exceeding limits */
	/* -------------------------- */
	if ( dynamax < DYNASIZE ) 
		dynamat [dynamax++] = fvalue;

	/* Reset errors and return */
	/* ----------------------- */
	err_val = 0; 	errno = 0;
	return(GOODRESULT);

}

VOID	set_national_characteristics( natid )
EXAWORD	natid;
{
	if (( natid == ENGLISH )
	||  ( natid == MONGOL  )	
	||  ( natid == CYRILUK )) { sepdec = '.'; defmil = ','; }
	else  			  { sepdec = ','; defmil = '.'; }
#ifndef	UNIX
#ifndef	VMS
#ifndef	WIN32

	/* This allows visibillity for EXBCD.ASM */
	/* ------------------------------------- */
	set_decimal_point( sepdec );
#endif
#endif
#endif
	return;
}


/*	-----------------	*/
/*	I O F _ R E S E T 	*/
/*	-----------------	*/

VOID	iof_reset()
{
	BPTR	cptr;
#ifdef	ABAL21
	cptr = (BPTR) " NATLANG";
	if ( *cptr != ' ' ) {
		LangFlag = 1;
		if (( *cptr >= '0' ) && ( *cptr <= '9' )) 
			NationalLanguage = ( *cptr - '0' );
		else if (( *cptr >= 'A' ) && ( *cptr <= 'Z' ))
			NationalLanguage = (( *cptr - 'A' ) + 10);
		else if (( *cptr >= 'a' ) && ( *cptr <= 'a' ))
			NationalLanguage = (( *cptr - 'a' ) + 10);
		else	NationalLanguage = conf(5);
		}
	else	{
		LangFlag = 0;
		NationalLanguage = conf(5);
		}

	set_national_characteristics(NationalLanguage);
#else
	set_national_characteristics(conf(5));
#endif

	prncol 	  = 1; prnlin = 1;	/* Printer curseur control	*/
	prndest   = 1; prnfid = 0;	/* CICO Output control reset	*/
	askmask   = MASK_DEF;		/* ASK MASK default value	*/

#ifdef	ABAL14
#ifdef	PROLOGUE
	LastFore  = prologue_foreground();
	LastBack  = prologue_background();
#else
#ifdef LINUX
	LastFore  = 2;			/* vert */
#else
	LastFore  = 7;			/* blanc gris */
#endif
	LastBack  = 0;
#endif
	AtbContext= 0;
	askcolour = MOINS_UN;
	askatrib  = MOINS_UN;
#endif
	return;
}

#ifdef UNIX
static	BPTR 	CicoContext=(BPTR) 0;

VOID	SetCicoContext( iptr )
BPTR	iptr;
{
	BPTR		xptr;
	EXAWORD		mode;
	unsigned long	Wid=0L;
	if ((xptr = iptr) != (BPTR) 0 ) {
		/* printf("SetCicoContext(%s)\r\n",iptr); */
		while ( *xptr ) {
			if  ( *(xptr++) != ':' )
				continue;
			else if  (((mode = *(xptr++)) != 'w' )
			     &&   (mode != 'f'))
				continue;
			else	{
				Wid=0;
				while (( *xptr >= '0' ) && ( *xptr <= '9'))
					Wid = ((Wid*10) + ( *(xptr++) - '0' ));
				/* printf("Mode = %c, Wid = %u\r\n",mode,Wid); */
				if ( mode == 'f' ) {
					set_pushpopid(Wid);
					}
				else if ( Wid ) {
					use_parent_window( Wid ); 		
					}
				continue;
				}
			}

		} 
	CicoContext = (BPTR) iptr;
	return;
}

EXAWORD	CicoContextItem( iptr )
BPTR	PTR iptr;
{
	BPTR	xptr;
	EXAWORD	n=0;
	EXAWORD	c;
	xptr = *iptr;
	while ( *xptr ) {
		if ((c = *(xptr++)) == ':' )
			break;
		else if ((c >= '0') && ( c <= '9' ))
			n = ((n * 10) + ( c - '0' ));
		else 	*xptr = 0;
		}
	*iptr = xptr;
	return( n );
}

PopCicoContext()
{
	iof_atb(AtbContext);
	iof_backgr( LastBack );
	iof_foregr( LastFore );
	return;
}

VOID	UseCicoContext( xptr )
BPTR xptr;
{
	EXAWORD	n;
	if ((n = CicoContextItem( (BPTR PTR) & xptr )) != 0)
		iof_tabl(n);
	else	iof_tabl(1);
	if ((n = CicoContextItem( (BPTR PTR) & xptr )) != 0)
		iof_tabc(n);
	else	iof_tabc(1);
	if ((n = CicoContextItem( (BPTR PTR) & xptr )) != 0)
		iof_atb(n);
	else	iof_atb(0);
	if ((n = CicoContextItem( (BPTR PTR) & xptr )) != 0)
		iof_backgr(n);
	else	iof_backgr(LastBack);
	if ((n = CicoContextItem( (BPTR PTR) & xptr )) != 0)
		iof_foregr(n);
	else	iof_foregr(LastFore);
	return;
}
#endif

/*	---------------------------------------------	*/
/*		s c r e e n _ m a n a g e r () 		*/
/*	---------------------------------------------	*/
/*	Called from the load go mechanisms to ensure	*/
/*	screen refresh performed for the waiting task	*/
/*	---------------------------------------------	*/
int	get_application_window()
{
	if ( exa_is_X11 > 1 )
		return( pixel_application_window(0) );
	else	return(0);
}

void	set_application_window(int v)
{
	if ( exa_is_X11 > 1 )
		(void) pixel_application_window(v);
	return;
}

void	iof_screen_manager() 
{
	if ( exa_is_X11 > 1 ) {
		pixel_screen_manager();
		}
	return;
}

void	iof_initialisation()
{
#ifdef	UNIX
	char * eptr;
	char * iptr;

	if ((eptr = getenv("ABQTOP")) != (char *) 0) 
	{
		if (( *eptr >= '0' ) && ( *eptr <= '9'))
			cico_use_abqt = (*eptr -'0');
	}
#endif
	if ((eptr = getenv("ABALCUTKEY")) != (char *) 0)
	{
		CutKey = 0;
		if ( *eptr != '/' )
		{
			while ((*eptr >= '0') && ( *eptr <= '9'))
				CutKey=((CutKey*10)+( *(eptr++) - '0' ));
		}
		else
		{
			while ( *eptr )
			{
				if ((*eptr >= '0') && ( *eptr <= '9'))
					CutKey=((CutKey*16)+( *(eptr++) - '0' ));
				else if ((*eptr >= 'a') && ( *eptr <= 'f'))
					CutKey=((CutKey*16)+( *(eptr++) - 'a' )+10);
				else if ((*eptr >= 'A') && ( *eptr <= 'F'))
					CutKey=((CutKey*16)+( *(eptr++) - 'A' )+10);
				else	break;
			}
		}
	}

#ifdef VMS_CHARSET
/* 	Check for Environment Variable PROLOGUE defined 	*/
/* 	----------------------------------------------- 	*/
#ifndef AGFVERSION	
	if ( getenv((BPTR) "PROLOGUE" ) == (BPTR) 0 )
		VmsCico = 0;	/* Indicate Vms/Vax default char set	*/
	else	VmsCico = 1;	/* Indicate Amenesik / Sologic Character Set	*/
#else
	BPTR BuffVarEnv;
	if ( (BuffVarEnv=getenv((BPTR) "PROLOGUE" )) == (BPTR) 0 )
		VmsCico = 0;	/* Indicate Vms/Vax default char set	*/
	else
	{
		if(BuffVarEnv[0]=='0')
			VmsCico = 0;
		else
			VmsCico = 1;
	}
#endif


#endif
#ifdef WMS
	qio_usage_flag = 0;
	curser_on_off  = 0; 
#endif

/*	Initialise Console IO manager		*/
/*	-----------------------------		*/
#ifdef	DOS
#ifndef	DEBUGGER
	initermexa(0);
#else
	initerm();
#endif
#endif

#ifdef WIN32
	SetDefaultWindowTitle();
#endif

	PrintFont=0; 
	IofFontHolder = 0;
	AskFont=0; 
	ForeGroundMask = 0x000F;
#ifdef UNIX
//#BG 24/05/19 16 couleurs de fond
	if (signature_version >= 41)
		BackGroundMask = 0x000F;
	else
		BackGroundMask = 0x0007;
#else
	BackGroundMask = 0x000F; /*FCH06012005 par compatibilite avec Wexa2, on met 15 et non pas 7*/
#endif

#ifndef	DOS
#ifdef UNIX
#ifdef	ABALX11
#ifndef	DEMUGGER
	if (!( eptr = getenv( "ABALXTITLE" )))
		eptr = "Abal Application";

	set_desktop_name(eptr);
	
	if (!( iptr = getenv( "ABALXICON" )))
		iptr = "exa";

	set_desktop_icon(iptr);

	if (!( exa_is_X11 = open_console() ))
	{
#else
		exa_is_X11 = 0;
#endif
#endif
		if ( CicoContext != (BPTR) 0 )
			modterm(0);
		else
			modterm(1);

		initerm();
#ifdef	ABALX11
#ifndef	DEMUGGER
	}
#ifdef	DEBUGGER
	else
	{
		db_initerm();
	}
#endif
#endif
#endif
#else
	initerm();
#endif
#endif

#ifdef	ABAL21
#ifndef DEBUGGER
	init_mimo();
#endif
#endif

#ifdef	ABAL_RTL
	lsyskey();
	iof_reset();
	iof_started = 0;
#endif
#ifdef	ABAL21
	AskContext.Flags	=  0;
	AskContext.CurserFore 	= 15;
	AskContext.CurserBack   =  1;
	AskContext.CurserAtb    =  1;
	AskContext.Start        =  0;
	AskContext.Finish       =  0;
#endif
	prndest = 1;

	/* correction to ensure preservation of colours over loadgo */
	/* -------------------------------------------------------- */
	LastFore  = conf(30);
	LastBack  = conf(29);

#ifdef	UNIX
	if ( CicoContext != (BPTR) 0 )
		UseCicoContext( CicoContext );
#endif

	/* Do this for text mode now */
	/* ------------------------- */
	if ( exa_is_X11 < 2)
		check_autopop(); 

	return;
}

void	iof_liberation()
{

	check_autopush();

#ifdef	ABAL21
#ifndef	DEBUGGER
	fin_mimo();
#endif
#endif

#ifdef	ABALX11
#ifndef	DEMUGGER
	if ( close_console() != 0 )
#endif
#endif
		finterm(0);
	return;
}

void	iof_insert_flag()
{
#ifdef	ABAL21
	insflg = (AskContext.Flags & 1);
#else
	insflg = 0;
#endif
	return;
}

#ifdef	ABAL_RTL

void	iof_clear()
{
	if ( ! iof_started )
		iof_start();

	if ( prndest > 1 ) 
		x_clear(); 
	else	{ 
		atb(0); x_clear(); 
		}
	return;
}

#ifdef	UNIX
VOID	useit_special_atb(int v)
{
	switch ( v ) {
		case 40: /* DO ABQT 	 */
			abqt();
			return;
		case 41: /* OP ABQT:ON   */
			cico_use_abqt = 1;
			return;
		case 42: /* OP ABQT:OFF  */  
			cico_use_abqt = 0;
			return;
		}
	return;
}
#endif

EXAWORD	iof_op()
{
	if ( x_kbhit() )
		return( x_getch() );
	else	{
#ifdef	UNIX
		if ( cico_use_abqt )
			abqt();
#endif
		return( 0 );
		}
}

void	iof_chr( c )
EXAWORD	c;
{
	if ( ! iof_started )
		iof_start();
	x_putch( c );	
	return;
}

void	iof_gener( n, p, l)
EXAWORD	n;
BPTR	p;
{
	if ( ! iof_started )
		iof_start();
	for ( ; n != 0; n-- )
		x_putch( *p );
	return;
}

void	iof_bell()
{
	if ( ! iof_started )
		iof_start();
	x_bell();
	return;
}	

EXAWORD	iof_setlang( langvalue )
EXAWORD	langvalue;
{
	EXAWORD	h;
	h = NationalLanguage;
	set_national_characteristics((NationalLanguage = langvalue));
	return( h );
}
EXAWORD	iof_getlang()
{
	return( NationalLanguage );
}

EXAWORD	iof_setmask( maskvalue )
EXAWORD	maskvalue;
{
	EXAWORD	h;
	h = askmask;
	askmask = maskvalue;
	return(h);
}

EXAWORD	iof_getmask( )
{
	return( askmask );
}

EXAWORD	iof_sethotkey( keyvalue )
EXAWORD	keyvalue;
{
	EXAWORD	h;
	h = LastJumpKey;
	LastJumpKey = keyvalue;
	return(h);
}

EXAWORD	iof_gethotkey( )
{
	return( LastJumpKey );
}


static	EXABYTE	RtlGlobalFormat[256];

void	iof_format( fptr )
BPTR	fptr;
{
	EXAWORD	flen;
	if ( ! iof_started )
		iof_start();
	for ( flen = 0; *(fptr + flen); flen++);
	atofmt((BPTR) fptr, flen, (BPTR) RtlGlobalFormat, 256);	
	iof_format_string((BPTR) RtlGlobalFormat, 256 );
	return;
}

EXAWORD	iof_print( vptr, vlen, vtyp )
BPTR	vptr;
EXAWORD	vlen;
EXAWORD	vtyp;
{
	EXAWORD	status;
	switch ( vtyp ) {
		case 1  :
		case 4  : 
		case 0  : status = iof_print_int( vlen, vtyp ); break;
		case 2  : status = iof_print_bcd( vptr, vlen ); break;
		case 3  : status = iof_print_str( vptr, vlen ); break;	
		default : return( 56 );
		}
	if ( (( fmtflg & 3 ) == 0 ) && ((fmtflg & 4) != 0)) {
		fmtptr = fmtbase;
		fmtflg |= 3;
		dynadex = 0;	
		}
	return( (status == 1 ? 0 : err_val ) );
}


EXAWORD	iof_ask( vptr, vlen , vtyp )
BPTR	vptr;
EXAWORD	vlen;
EXAWORD	vtyp;
{
	BPTR	d;
	EXAWORD	lerr;
	EXAWORD	asklen;

	if ( ! iof_started )
		iof_start();

	workptr1 = vptr; 
	worklen1 = vlen;

	switch ((worktyp1 = vtyp)) {

		case VARB_INT8  : 
		case VARB_FOUR  : 
		
			(void) itoa((ReadSchar(workptr1)),(BPTR) askbuf,(asklen = 4));
			break;

		case VARB_INT16 : 
			
			(void) itoa((balgetw(workptr1)),(BPTR) askbuf, (asklen = 6));
			break;

		case VARB_INT32 : 
			
			(void) ltoa((balgetl(workptr1)),(BPTR) askbuf, (asklen = 24));
			break;

		case VARB_INT64 : 
			
			(void) ltoa((balget64(workptr1)),(BPTR) askbuf, (asklen = 48));
			break;

		case VARB_BCD   : 

			(void) bcdtoa(workptr1,worklen1,(BPTR) askbuf, ((asklen = (worklen1 * 2))) );
			break;

		case VARB_STR   : 

			/* Limit To Maximum ASKBUF length */
			/* ------------------------------ */
			 if (( asklen = worklen1 ) > ASKBUFMAX ) { 
				err_val = ABAL_VAR2BIG; 
				return(MOINS_UN);
				}

			 memcpy((BPTR)askbuf,workptr1,asklen); 
			 break;

		default : return(MOINS_UN);

		}

	fmthex = 0;			/* Reset Hexa control		*/
	fbcdv  = 0;			/* To control the FMT_V options */
	iof_insert_flag();		/* Collect Default Insert Mode 	*/
	LastJumpKey = 0;		/* Reset Last Jump Key		*/


	/* Enter Low Level ASK function */
	/* ---------------------------- */
	lerr = ll_ask(asklen);

	ll_ask_flag = 0;

	/* Check for and return Last HotKey or Error,Mouse, Timer,Event */
	/* ------------------------------------------------------------ */
	if (lerr == SOFTERROR) {
		iof_flush(); 
		return( LastJumpKey );
		}

	/* Something to Save to Variable */
	/* ----------------------------- */
	switch ( worktyp1 ) {

		case VARB_FOUR  : 
		case VARB_INT8  : 

			if ( fmthex == 0 ) 
				*workptr1 = (EXABYTE) exatoi((BPTR) askbuf,asklen); 
			else	*workptr1 = (EXABYTE) hextoi((BPTR) askbuf,asklen); 
			break;

		case VARB_INT32 : 
			if ( fmthex == 0 )
				workval1 = exatol((BPTR) askbuf,asklen);
			else	workval1 = hextol((BPTR) askbuf,asklen);
			balputl(workval1,workptr1);
			break;

		case VARB_INT64 : 
			if ( fmthex == 0 )
				workval1 = exatoh((BPTR) askbuf,asklen);
			else	workval1 = hextoh((BPTR) askbuf,asklen);
			balput64(workval1,workptr1);
			break;

		case VARB_INT16 : 

			if ( fmthex == 0 )
				workval1 = exatoi((BPTR) askbuf,asklen);
			else	workval1 = hextoi((BPTR) askbuf,asklen);
			StoreAbalWord(workptr1,workval1);
			break;

		case VARB_BCD   : 

			/* Convert to BCD String */
			/* --------------------- */				
			atobcd((BPTR) &askbuf[0],workptr1,worklen1,strlen((BPTR) &askbuf[0])); 

			/* Adjust power conversion factor if required */
			/* ------------------------------------------ */	
			if ( fbcdv < 0 ) 
				fbcdv++;

			/* Convert Power with respect to power desired */
			/* ------------------------------------------- */
			if ( fbcdv != 0 ) {
				(VOID) std2bcd((BPTR) workptr1,(EXAWORD) worklen1,(BPTR) askbuf,(EXAWORD) worklen1 ,(BINAIRE) ((BINAIRE) fbcdv * -1));
				(VOID) memcpy((BPTR) workptr1 , (BPTR) askbuf, (USINT) worklen1);
				}

			break;

		case VARB_STR   : 

			d = (BPTR) &askbuf[0];

			/* Perform String Transfer to Result */
			/* --------------------------------- */
			while ( worklen1 > 0 ) { 
				if ( *d != IO_NUL) {
					*(workptr1++) = *(d++); 
					worklen1--; 
					}
				else 	break;
				}

			/* Perform String Space Filler */
			/* --------------------------- */
			for ( ; worklen1 > 0; worklen1-- )
				*(workptr1++) = IO_ESP;

		}

	/* Return Last HotKey */
	/* ------------------ */
	iof_flush(); return( LastJumpKey );

}

void	iof_hotkeys( hp, hl )
BPTR	hp;
EXAWORD	hl;
{
	if ( ! iof_started )
		iof_start();
	for ( ; hl != 0; hl--)
		iof_goto_num_hotkey( *(hp++), 0 );
	return;

}

void	iof_hotkey( hk )
EXAWORD	hk;
{
	if ( ! iof_started )
		iof_start();
	iof_goto_num_hotkey( hk, 0 );
	return;
}

#endif

/* 
 *	I O F _ S P E C I A L _ H O T K E Y  ( fx, type )
 *	-------------------------------------------------
 *	Insertion d'une regle de debranchement STANDARD dans la table
 *	des descripteurs de debranchement.
 *
 *	0	I = &ettiq	:	Touche ESCAPE
 *	1	L = &ettiq	:	Touche Fleche GAUCHE
 *	2	U = &ettiq	:	Touche Fleche HAUT
 *	3	D = &ettiq	:	Touche Fleche BAS
 *	4	E = &ettiq	:	Gestion des Erreurs
 *
 *	From ABAL 2.1 onwards 
 *
 *	5	T = &ettiq	:	Timer Event
 *	6	M = &ettiq	:	Mouse Event
 *
 *	7	UNUSED
 *
 *	The type indicates whether Goto or Gosub type HotKey
 */

EXAWORD	iof_special_hotkey(fx,goto_gosub)
EXAWORD	fx;
EXAWORD	goto_gosub;
{
	switch (((fx & 0x00F0) >> 4)) {
		case 0 :
			if ((askmask & MASK_DEACTIV_JUMP_I) == 0) { 
				fx = IO_ESC; 
				break; 				/* Escape */
				}
			else 	{ 
#ifndef	ABAL_RTL
				fdex += WORDSIZE; 
#endif
				return(1); 
				}
		case 1 : fx = syskey[IO_BAK]; 	break; 		/* Left   */
		case 2 : fx = syskey[IO_UP]; 	break; 		/* Up     */
		case 3 : fx = syskey[IO_BAS]; 	break; 		/* Down   */
		case 4 : fx = _ERROR_HOTKEY;	break;		/* Error  */
#ifdef	ABAL21
		case 5 : fx = _TIMER_HOTKEY;	break;		/* Timer  */
		case 6 : fx = _MOUSE_HOTKEY;	break;		/* Mouse  */
#endif	
		default: err_val = 115;		return( SOFTERROR );
		}
#ifndef	ABAL_RTL
	asktst[jmpdex] 	 = ( fx | goto_gosub );
	askjmp[jmpdex++] = Tcodeword( fdex); 
	fdex += WORDSIZE; 
#endif

#ifdef WEXADBDLL
/* #BG #OK: 25/07/02 (begin) */
	if (goto_gosub != _GOTO_HOTKEY)	/* ASK */
/* #BG #OK: 25/07/02 (end) */
		StepOverTrapWork(0);
#endif

	return(GOODRESULT);
}


#ifdef INTEL
#include "exprag1.h"
#endif

#endif	/* _EXIOFUNC_C */
	/* ----------- */


