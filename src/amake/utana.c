/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1993 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	UTANA.C				*/
/*		Version		:	1.4c				*/
/*		Date		:	06/10/1993			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_UTANA_C
#define	_UTANA_C

#include "stdtypes.h"
#define	ALSMID "utana"
#include "allocate.h"
#include "utdef.h"		/* Constants and Structure definitions	*/
#include "amake.h"		/* Structures and constants of AMAKE	*/

#ifndef PRL
#ifndef DOS
#include <time.h>
#endif
#endif


/*
 *	Make File Data Structure declarations
 *	-------------------------------------
 */

EXTERN	WORD	Debug;
EXTERN	WORD	getchwatch;
EXTERN	BPTR	program_id;	/* Pointer to argv[0]			*/
BPTR		workbuf;	/* Pointer to Parser work zone		*/
EXTERN CONSTREE	Konstack;	/* Pointer to local Variable/Constants	*/
ARBRE		TreeRoot[HASH_MAX];	/* Pointer to File quick find liste	*/
RULETREE	Regstack;	/* Pointer to Dependance structure base */
RULETREE	Sufstack;	/* Suffixes stack root			*/
RULETREE	ThisRule;	/* Pointer to Current dependance base 	*/
RULETREE	DefRegle;	/* Pointer to Current Default Actions	*/
BPTR		ThisTarget;	/* Pointer to Current Target to Make	*/
BPTR		ThisSource;	/* Pointer to Current Source 		*/
LINKLIST	ThisDependance;	/* Pointer to Current dependancies	*/

int	IfStack[64];		/* Stacked Up Conditions		*/
int	IfDex;			/* Stack Pointer			*/
int	action_status;		/* Indicates that action performed	*/

BYTE    TempStringCopy[1024];


/*
 *	Function Prototypes
 *	-------------------
 */

#ifndef UNIX
#ifndef VMS
#include "utmacro.h"
BPTR	Substitute(BPTR);
VOID    ToucheTarget();
int	system(BPTR);
int	mf_action(BPTR);

#endif
#endif

#ifndef PRL
#ifndef DOS
#include "utmacro.h"
int	mf_action();
BPTR	Substitute();
VOID    ToucheTarget();
#endif
#endif

/*
 *	External Data references
 *	------------------------
 */
EXTERN	int	GetchCtrl;
EXTERN	BPTR	TalkPtr[];
EXTERN	int	UserMode;

/*
 *	General purpose compare function 
 *	--------------------------------
 *
 */

int	CountFields(sptr , compte ) 
BPTR	sptr;
int	compte;
{
	while ( *sptr != 0 ) if ( *(sptr++) == ',' ) compte++;
	return( compte );
}


int	IsSeparator( c )
int	c;
{
	if ( c == '.' ) return(0);
#ifdef	PRL
	if ( c == '-' ) return(0);
#endif
	return(-1);
}

int	mfcompare( xptr , yptr )
BPTR	xptr;
BPTR	yptr;
{
	while (( *xptr != 0 ) && ( *yptr != 0 )) {
		if ( *xptr == *yptr ) 	{ xptr++; yptr++; }
		else			{ break;	  }
		}
	return((int) ( *xptr - *yptr) );
}

/* 	
 *	S F X _ C O M P A R E  ( tptr , sptr ) 
 *	--------------------------------------
 *
 *	Tests a target / Source combination for suffix rule validity
 *
 */

int	Sfx_Compare( tptr , sptr )
BPTR	tptr;
BPTR	sptr;
{
	int	compte;
	BYTE	c;
	int	i;
	int	result;

	/* Establish default result : FAILURE */
	/* ---------------------------------- */
	result = -1;

        strcpy(TempStringCopy,sptr); sptr = TempStringCopy;

	/* Count number of fields in Test string (at least one) */
	/* ---------------------------------------------------- */
	compte = CountFields(sptr,1);

	/* Perform for all fields until end of string or Success */
	/* ----------------------------------------------------- */
	while (( compte > 0 ) && ( result != 0)) {

		/* Decrement field count */
		/* --------------------- */
		compte--; i = 0;

		/* If not last field */
		/* ----------------- */
		if ( compte > 0 ) {

			/* Scan to end of field */
			/* -------------------- */
			while ( *(sptr + i) != ',' ) i++;

			/* Collect and save byte then terminate field */
			/* ------------------------------------------ */
			c = *(sptr + i); *(sptr + i) = (BYTE) 0;

			}

		/* Perform string compare */
		/* ---------------------- */
		result = mfcompare( tptr , sptr );

		/* Repair the string if necessary */
		/* ------------------------------ */
		if ( compte > 0 ) { *(sptr + i) = c; sptr += i; sptr++; }

		}

	return(result);


}

/*
 *	C H E C K _ S U F F I X ( tptr , sptr )
 *	--------------------------------------- 
 *	Test for existance of a source suffix for this target suffix
 *
 */

int	Check_Suffix( tptr , sptr )
BPTR	tptr;
BPTR	sptr;
{
	int	i;

	/* SPTR points to a suffixs rule pair (.c.o,.h.o,etc) */
	/* -------------------------------------------------- */
	/* Jump First */
	/* ---------- */
	while (1) {
		sptr++;
		switch ( *sptr ) {
			
			case 0   :
			case ',' : break;
			default  : 
				if ( IsSeparator( *(sptr) ) == 0 ) {
					break;
					}
				else	{
					continue;
					}
			}
		break;
		}
	/* Check for 2nd half of suffix pair */
	/* --------------------------------- */
	if ( IsSeparator( *(sptr) ) == 0 ) {
		i = 0;
		while ( *(tptr + i) == *(sptr + i) ) {
			if (( *(tptr + i) != 0 ) && (*(tptr + i) != ',')) {
				i++;
				}
			else	{
				break;
				}
			}
		if ( *(tptr + i) == *(sptr + i) ) {

			/* Found the Suffix Match */
			/* ---------------------- */
			return(0);
			}
		}
		 
	return( -1 );
}




VOID	xliberate_list( lroot )
LINKLIST	lroot;
{
	if ( lroot != (LINKLIST) 0 ) {
		xliberate_list( lroot->suite );
		liberate((BPTR) lroot->value );
		liberate((BPTR) lroot );
		}
	return;
}

/*
 *	I S  I N F E R E N C E  R U L E  ( iptr )
 *	-----------------------------------------
 *	Tests for a string containing a valid inference rule
 *	returns 0 if false
 */

int	IsInferenceRule( iptr )
BPTR	iptr;
{
	int	dotcount;
	BYTE	buffer[256];

	/* Remove leading white space */
	/* -------------------------- */
	while ( *iptr == ' ') iptr++;

	/* Check for existance of device/path infos */
	/* ---------------------------------------- */
	if ( fn_parser( iptr ,(BPTR) buffer , 0x0007 ) != 0 ) {
		return(0);
		}

	/* Must be a preceeding DOT */
	/* ------------------------ */
	if ( IsSeparator( *(iptr) ) != 0 ) {
		return(0);	
		}
	else	{	
		return(1);	
		}

}


/*
 *	Establish and allocate new Rule Tree Level at the Root
 *	------------------------------------------------------
 *
 */

int	NewRoot( value )
BPTR	value;
{
	RULETREE	lroot;
	RULETREE	yroot;

	/* Attempt to Allocate new structure */
	/* --------------------------------- */
	if ((lroot = (RULETREE) allocate(sizeof(struct Rules))) != (RULETREE) 0) {

		/* Initialise the Structure */
		/* ------------------------ */
		lroot->suite     = (RULETREE) 0;
		lroot->Nom       = value;
		lroot->Status    = 0;
		lroot->Depend    = (LINKLIST) 0;
		lroot->Action    = (LINKLIST) 0;

		/* Establish trace debug info */
		/* -------------------------- */
		establish_trace_info( lroot );

		/* Check for Inherent suffixes or Dependance Root */
		/* ---------------------------------------------- */
		if ( IsInferenceRule( value ) != 0 ) {

			/* Add to Head of Suffix liste to override default */
			/* ----------------------------------------------- */
			lroot->suite = Sufstack;
			Sufstack     = lroot;

			}

		else	{
			/* If This is the First then Simply affect to Root Ptr */
			/* --------------------------------------------------- */
			if ( Regstack == (RULETREE) 0) {
				Regstack      = lroot;	
				}
			else	{
				/* Scan till End of Tree and then Add */
				/* ---------------------------------- */
				yroot = Regstack;
				while (yroot->suite != (RULETREE) 0) {
					yroot = yroot->suite;
					}
				yroot->suite = lroot;
				}
			}

		/* Indicate Current structure */
		/* -------------------------- */
		ThisRule = lroot; return(0);
		}

	/* Signal Allocation Error */
	/* ----------------------- */
	return(-1);
}

int	NewDepend( value )
BPTR	value;
{
	LINKLIST	lroot;
	LINKLIST	droot;

	if ((lroot = (LINKLIST) allocate(sizeof(struct LinkList))) != (LINKLIST) 0) {

		/* Initialise the Structure */
		/* ------------------------ */
		lroot->suite     = (LINKLIST) 0;
		lroot->value     = value;

		/* Watch out for first dependance */
		/* ------------------------------ */
		if ( ThisRule->Depend == (LINKLIST) 0 ) {

			/* Initialise Dependance list */
			/* -------------------------- */
			ThisRule->Depend = lroot;	
			}
		else	{
			/* Descend to end of list */
			/* ---------------------- */
			droot = ThisRule->Depend;
			while ( droot->suite != (LINKLIST) 0) {
				droot = droot->suite;
				}
			/* Add to end of list */
			/* ------------------ */
			droot->suite = lroot;
			}

		return(0);
		}

	/* Signal Allocation Error */
	/* ----------------------- */
	return(-1);
}

int	NewAction( value )
BPTR	value;
{
	LINKLIST	lroot;

	if ((lroot = (LINKLIST) allocate(sizeof(struct LinkList))) != (LINKLIST) 0) {

		/* Initialise the Structure */
		/* ------------------------ */
		lroot->suite     = ThisRule->Action;
		lroot->value     = value;
		ThisRule->Action = lroot;	
		return(0);
		}

	/* Signal Allocation Error */
	/* ----------------------- */
	return(-1);
}
int	IsList( buff , l )
BPTR	buff;
int	l;
{
	int	x;
	if ((*buff == '$') && ( *(buff + l - 1) == ')' )) {
		/* Scan for Left Bracket */
		/* --------------------- */
		for ( x = 1; x < l; x++ ) {
			if ( *(buff +x) == ')' ) {
				if ( x != (l - 1) ) {
					return(x);
					}					
				}
			}
		return(0);
		}
	return(1);
}

int	ignore_tokens( bptr )
BPTR	bptr;
{
	switch ( *bptr ) {
		case '*'	:
		case '='	:
		case '?'	:
			return( 0 );
		default		:
			return( 1 );
		}
}

int	mf_storage(l,buff,mode)
int	l;
BPTR	buff;
int	mode;
{
	BPTR 		wptr;
	int		x;
	BYTE		c;

	/* Ignore Crazy tokens */
	/* ------------------- */
	if ( ignore_tokens((BPTR) buff) == 0 )
		return( 0 );

	/* Check for Dependance List Element */
	/* --------------------------------- */
	if ( mode == 1 ) {

		/* Watch out for Variables which contain lists of files */
		/* ---------------------------------------------------- */
		if ( IsList((BPTR) buff , l ) == 0 ) {
 
			do	{
				/* Collect Variable Value */
				/* ---------------------- */
				if ((buff = Recherche((BPTR) (buff + 2))) == (BPTR) 0) {
					return( -1 );
					}
				/* Ignore White Space */
				/* ------------------ */
				while (( *buff == ' ' ) || ( *buff == ',')) { buff++; }
	
				/* Ignore Empty Tokens */
				/* ------------------- */
				if ((l = strlen((BPTR) buff )) == 0) {
					return(0);
					}

				/* Ignore Crazy tokens */
				/* ------------------- */
				if ( ignore_tokens((BPTR) buff) == 0 )
					return( 0 );
				}
			while ( IsList((BPTR) buff , l ) == 0 );
	
			/* Now Cut up String */
			/* ----------------- */
			while ( *buff != (BYTE) 0 ) {

				/* Ignore leading White Space */
				/* -------------------------- */
				while (( *buff == ' ' ) || ( *buff == ',')) { buff++; }
	
				x = 0;
	
				/* Scan to End of Element */
				/* ---------------------- */
				while ((*(buff+x) != ',') && ( *(buff+x) != ' ' ) && ( *(buff+x) != (BYTE) 0 )) {
					x++;
					}
				if ( x > 0 ) {
					/* Perform Storage */
					/* --------------- */
					c = *(buff + x);
					*(buff + x) = (BYTE) 0;
					if (mf_storage(x,(BPTR) buff, mode ) == -1) {	
						*(buff + x) = c;
						return(-1);
						}
					*(buff + x) = c;
					buff += x;
					}
				}
			return(0);
			}
		}
		
	/* Allocate a local Buffer */
	/* ----------------------- */
	if ((wptr = (BPTR) allocate((l + 1))) == (BPTR) 0 ) {
		errno = 28;
		return(-1);
		} 

	/* Copy contents to Allocated Buffer */
	/* --------------------------------- */
	memcpy((BPTR) wptr,(BPTR) buff,(l+1));

	switch ( mode ) {
		case 0 : return( NewRoot   (wptr) );
		case 1 : return( NewDepend (wptr) );
		case 2 : return( NewAction (wptr) );
		default: errno = mode; return(-1);
		}

}

int	GetToken( bptr,mode)
BPTR	bptr;
int	mode;	/* 0 => Force upper case , 1 leave as is */
{
	int	c,i;
	int	g;

	g = GetchCtrl; GetchCtrl = 0;

	/* Parse out White Space */
	/* --------------------- */
	do	{
		c = z_getch();
		}
	while (( c == ' ') || ( c == 0x0009 ));

	/* Collect KeyWord */
	/* --------------- */
	i = 0;
	while ( i < 64 ) {
		if ( mode == 0 ) { c = toupper( c ); }
		switch (c ) {
			case 0x001A	:
			case 0		: if ( i == 0 ) { 
						GetchCtrl = g;
						return(0); 
						}
			case ' ' 	:
			case 0x0009	: 
			case 0x000D	:
			case 0x000A	: *(bptr + i) = (BYTE) 0;
					  GetchCtrl = g;
					  return(i);
			default         : *(bptr + i) = c; i++;
					  if ( i < 64 ) {
						c = z_getch();
						}
			}
		}
	*(bptr + i) =(BYTE) 0;
	GetchCtrl = g;
	return(i); 
}

BYTE	ShellBuf[256];

int	ERROR_ECHO(error_value)
int	error_value;
{
	int	c;
	int	shelldex;
	BPTR	fptr;
	
	if ( GetchCtrl == 0 ) {
		c = 1; shelldex = 0;
		while ((shelldex < 255) && (c != 0)) {
			switch ((c = z_getch())) {
				case 0x000D : continue;
				case 0x000A : 
				case 0      : c = 0; break;
				default     : ShellBuf[shelldex] = c;
					      shelldex++;
				}
			}
		ShellBuf[shelldex] = 0;
		if ( shelldex > 0 ) {
			if ((fptr = Substitute((BPTR) ShellBuf)) == (BPTR) 0)
				return(-1);

			while ( *fptr != 0 ) 
				llmf_co( (*(fptr++)) );
			}
		utline();
		return( error_value );
		}
	return(0);
}


VOID	ensure_path_terminated( pptr , l )
BPTR	pptr;
int	l;
{
#ifdef	VMS
	switch( *pptr ) {
		case ':' :
		case ']' : break;
		default  : *(++pptr) = ':';
			   *(++pptr) = 0;
		}
#else
#ifdef	UNIX
	if ( *pptr != '/' ) {
		*(++pptr) = '/';
		*(++pptr) = 0;
		}
#else
#ifdef	DOS
	if (( *pptr != '\\' ) && ( *pptr != ':' )) {
		*(++pptr) = '\\';
		*(++pptr) = 0;
		}
#else
	if (( *pptr != '\\' ) && (*pptr != '.' )) {
		if (( l == 3 ) && ( *pptr >= '0' ) && (*pptr <= '9' )) {
			*(++pptr) = '.';
			}
		else	{
			*(++pptr) = '\\';
			}
		*(++pptr) = 0;
		}

#endif	/* PRL / DOS 	*/
#endif	/* UNIX 		*/		
#endif	/* VMS 		*/
	return;

}


BYTE	IncludeName[128];

BPTR  IncludePath( fptr )
BPTR	fptr;
{
	BPTR	eptr;
	int l;

	if ( *fptr != '<' ) 
		return( fptr );

	memset((BPTR) IncludeName , 0 , 128 );

	if ((eptr = getenv((BPTR)"INCLUDE")) == (BPTR) 0)
		return((BPTR) 0);

	strcpy((BPTR) IncludeName, (BPTR) eptr );

	l = strlen((BPTR) IncludeName );
	if ( l != 0 )
		ensure_path_terminated((BPTR) & IncludeName[(l - 1)] , l); 

	strcat((BPTR) IncludeName , (fptr + 1));

	for ( l = 0; l < 128; l++) {
		if ( IncludeName[l] == '>' ) {
			IncludeName[l] = (BYTE) 0;
			break;
			}
		}

	return((BPTR) IncludeName );
}

void	generate_error_condition( msgid, extra )
WORD	msgid;
BPTR	extra;
{
	utline();
	mf_message((BPTR) program_id);
	llmf_co(':'); 
	print_trace_info(); 
	llmf_co(':');
	llmf_co(' ');
	mf_message((BPTR)TalkPtr[msgid]);
	mf_message((BPTR) extra );
	utline();
	return;
}

void	generate_warning_condition( msgid, extra, lRule )
WORD		msgid;
BPTR		extra;
RULETREE	lRule;
{
	utline();
	mf_message((BPTR) program_id);
	llmf_co(':'); 
	warning(lRule); 
	llmf_co(':');
	llmf_co(' ');
	mf_message((BPTR)TalkPtr[msgid]);
	mf_message((BPTR) extra );
	utline();
	return;
}

VOID	interprete_option_character( c )
WORD	c;
{
	switch ( c ) {
		/* Force Rebuild of all targets */
		/* ---------------------------- */
		case 'b' :
		case 'B' :
			UserMode |= _FORCE_REBUILD;
			break;

		/* Activate detailed DEBUG output   */
		/* -------------------------------- */
		case 'D' :
		case 'd' : 
			UserMode |= _DEBUG_DATE;
			Debug   = 1; 
			break;

		/* Environnement variables take     */
		/* precedance over internal macros  */
		/* -------------------------------- */
		case 'e' : 
		case 'E' : 
			UserMode |= _ENVIRON;
			break;

		/* Generate and Check default Dependance */
		/* ------------------------------------- */
		case 'g' :
		case 'G' : 
			UserMode |= _INFERENCE;
			break;

		/* Ignore Invocation errors         */
		/* -------------------------------- */
		case 'I' :
		case 'i' : 
			UserMode |= _IGNORE_ERRORS; 
			break;

		/* Display but do not execute	    */
		/* -------------------------------- */
		case 'N' :
		case 'n' : 
			UserMode |= (_INHIBIT_ACTION | _IGNORE_ERRORS); 
			break;

		/* No error : when source missing   */
		/* and object already created       */
		/* -------------------------------- */
		case 'o' :
		case 'O' : 
			UserMode |= _TARGET_OK;
			break;

		/* PreProcess to Standard OutPut    */
		/* -------------------------------- */
		case 'P' :
		case 'p' : 
			UserMode |= _PREPROCESS; 
			break;

		/* Dissable default Inference rules */
		/* -------------------------------- */
		case 'r' :
		case 'R' : 
			UserMode &= 0xFFDF;
			break;

		/* Execute in silent mode */
		/* ---------------------- */
		case 'S' :
		case 's' : 
			UserMode |= _SILENCE; 
			break;
	
		/* Touche files rather than Execute */
		/* -------------------------------- */
		case 't' :
		case 'T' : 
			UserMode |= _TOUCH_TARGET;
			break;

		/* Activate mode verbose */
		/* --------------------- */
		case 'V' :
		case 'v' : 
			UserMode |= _VERIFICATION;
			getchwatch = 1;
			break;

#ifdef	ABAL21
		case 'w' :
		case 'W' :
			getchwatch = 1;
			break;
		case 'x' :
		case 'X' :
			UserMode |= (_RETURN_TO_USER | _SILENCE);
			break;
#endif
		}
	return;
}

#ifdef	ABAL21
VOID	analyse_explicite_options()
{
	WORD	c;
	WORD	state=1;
	while ( 1 ) {
		switch ((c = z_getch())) {
			case 0x000A 	: 
			case 0	    	: 
			case 0x000D 	: break;
			case ' '    	:
			case 0x0009 	: continue;
			case '-'	: state = 0;	/* Force inhibit */
					  continue;
			case '+'	: state = 1;	/* Force Active  */
					  continue;
			default		: interprete_option_character( c );
					  continue;
			}
		break;
		}
	return;
}
#endif	/* ABAL21 */

/*
 *	Evaluation of MAKEFILE CONDITIONAL BLOCK Statements
 *	---------------------------------------------------
 *	!IFDEF	!IFNDEF		- start of conditional block
 *	!ELSE			- inverse of conditional block
 *	!ENDIF			- end of conditional block
 *	!MAKE			- perform updating now
 *	!ERROR			- abandon and display message
 *	!ECHO			- Display Message and continue 
 *	!INCLUDE		- read and use included makefile
 *	!UNDEF			- Undefine a Constant
 *	!SHELL			- Execution of a system command
 *	!OPTION			- Command line option control
 */


int	Conditions()
{
	BYTE	Token[65];
	int	c;
	int	shelldex;
	BPTR	fptr;

	/* Collect Key Word Token */
	/* ---------------------- */
	if (GetToken((BPTR) Token , 0) == 0) {
		return(-1);
		}

	/* Identify Key Word */
	/* ----------------- */
	if ( mfcompare((BPTR) Token, (BPTR) "IFDEF") == 0 ) {

		IfStack[IfDex++] = GetchCtrl;

		/* Collect Conditional TOKEN String */
		/* -------------------------------- */
		if (GetToken((BPTR) Token,1) == 0) {
			return(-1);
			}
		
		/* Check token only if Currently Active */
		/* ------------------------------------ */
		if ( GetchCtrl == 0 ) {
	

			/* Allow dynamic substitution */
			/* -------------------------- */
			if ((fptr = Substitute((BPTR) Token)) == (BPTR) 0)
				return(-1);

			/* Check for Token is Defined */
			/* -------------------------- */
			if ( SearchName((BPTR) fptr ) == (BPTR) 0)

				/* Token Not Defined so Scan to Avoid Region */
				/* ----------------------------------------- */
				GetchCtrl = 1;

			}

		}
	else if ( mfcompare((BPTR) Token, (BPTR) "IFNDEF") == 0 ) {

		IfStack[IfDex++] = GetchCtrl;

		/* Collect Conditional TOKEN String */
		/* -------------------------------- */
		if (GetToken((BPTR) Token,1) == 0)
			return(-1);

		if ( GetchCtrl == 0 ) {

			/* Allow dynamic substitution */
			/* -------------------------- */
			if ((fptr = Substitute((BPTR) Token)) == (BPTR) 0)
				return(-1);

			/* Check for Token is not Defined */
			/* ------------------------------ */
			if ( SearchName((BPTR) fptr ) != (BPTR) 0)

				/* Token Not Defined so Scan to Avoid Region */
				/* ----------------------------------------- */
				GetchCtrl = 1;
			}
		}

#ifdef	VERSION666
	else if ( mfcompare((BPTR) Token, (BPTR) "IFNUL") == 0 ) {

		IfStack[IfDex++] = GetchCtrl;

		/* Collect Conditional TOKEN String */
		/* -------------------------------- */
		if (GetToken((BPTR) Token,1) == 0) {
			return(-1);
			}
		
		/* Check token only if Currently Active */
		/* ------------------------------------ */
		if ( GetchCtrl == 0 ) {
	

			/* Allow dynamic substitution */
			/* -------------------------- */
			if ((fptr = Substitute((BPTR) Token)) == (BPTR) 0)
				return(-1);

			/* Check for Token is Defined */
			/* -------------------------- */
			if ((fptr = SearchName((BPTR) fptr )) == (BPTR) 0)

				/* Token Not Defined so Scan to Avoid Region */
				/* ----------------------------------------- */
				GetchCtrl = 1;
			else 	{
				/* Check if NULL */
				/* ------------- */
				while ( *fptr != 0 ) {
					if ( *fptr == ' ' ) {
						fptr++; 
						continue;
						}
					else	break;
					}
				if ( *fptr != 0 ) {
					/* token defined and not empty  */
					/* so avoid scan		*/
					GetchCtrl = 1;
					}
				}
			}

		}
#endif
	else if ( mfcompare((BPTR) Token, (BPTR) "ENDIF") == 0 ) {

		/* End of Conditional BLOCK expression */
		/* ----------------------------------- */
		GetchCtrl = IfStack[--IfDex];
		}

	else if ( mfcompare((BPTR) Token, (BPTR) "MAKE") == 0 ) {

		/* Check for Make file Action Request NOW */
		/* -------------------------------------- */
		if ( GetchCtrl == 0 ) {

			if ((UserMode & (_PREPROCESS | _VERIFICATION)) == 0) {

				/* Perform MAKEFILE Dependance Checking */
				/* ------------------------------------ */
				if ( mf_Maker() != 0 ) 	return(-1);
				else			return(1);

				}
			}
		}
	else if ( mfcompare((BPTR) Token, (BPTR) "ELSE") == 0 ) 	{

		/* Conditional ELSE statement */
		/* -------------------------- */
		if ( IfDex > 0 ) {
			if ( IfStack[IfDex-1] == 0 ) {
				if ( GetchCtrl == 0 ) 	GetchCtrl = 1;
				else			GetchCtrl = 0;
				}
			}
		else	{
			if ( GetchCtrl == 0 ) 	
				GetchCtrl = 1;
			else	GetchCtrl = 0;
			}
		}
	else if ( mfcompare((BPTR) Token, (BPTR) "ERROR") == 0 ) 	{

		/* Abandon and After Message display */
		/* --------------------------------- */
		if ( ERROR_ECHO(2) == 2 )
			return(2);

		}
	else if ( mfcompare((BPTR) Token, (BPTR) "INCLUDE") == 0 ) {

		/* Inclusion of MakeFile */
		/* --------------------- */

		/* If Expession is in active Region */
		/* -------------------------------- */
		if ( GetchCtrl == 0 ) {

			/* Collect Key Word Token */
			/* ---------------------- */
			if (GetToken((BPTR) Token,1) == 0)
				return(-1);

			/* Allow dynamic substitution */
			/* -------------------------- */
			if ((fptr = Substitute((BPTR) Token)) == (BPTR) 0)
				return(-1);

			/* Allow path additions */
			/* -------------------- */
			if ((fptr = IncludePath((BPTR) fptr)) == (BPTR) 0)
				return(-1);

			/* Save the current Context */
			/* ------------------------ */
			if ( PushContext() != 0 )
				return(-1);

			if ( mf_open( (BPTR) fptr ) == -1 ) {
				PopContext();
				generate_error_condition( 12, fptr );
				return(-1);
				}
			}
		}
	else if ( mfcompare((BPTR) Token, (BPTR) "UNDEF") == 0 ) {

		if ( GetchCtrl == 0 ) {
			do	{
				/* Collect Key Word Token */
				/* ---------------------- */
				if (GetToken((BPTR) Token,1) == 0)
					return(-1);

				/* Allow dynamic substitution */
				/* -------------------------- */
				if ((fptr = Substitute((BPTR) Token)) == (BPTR) 0) 
					return(-1);

				if ( Remove_Macro((BPTR) fptr ) == -1 )
					return(-1);
				}
			while ( not_white_space() == ',' );
			}
		}
	else if ( mfcompare((BPTR) Token, (BPTR) "ECHO") == 0) {
		/* Display Message and Continue */
		/* ---------------------------- */
		(VOID) ERROR_ECHO(0);
		}
#ifdef	ABAL21
	else if ( mfcompare((BPTR) Token, (BPTR) "OPTION") == 0) {
		/* Analyse options and Continue */
		/* ---------------------------- */
		if ( GetchCtrl == 0 ) 
			analyse_explicite_options();
		}
#endif
	else if ( mfcompare((BPTR) Token, (BPTR) "SHELL") == 0) {

		/* Execute system command via shell or Command interpreter */
		/* ------------------------------------------------------- */
		if ( GetchCtrl == 0 ) {

			/* Locate Commande Value */
			/* --------------------- */
			shelldex = 0; c = 1;
			while ((c != 0) && (c != 0x000A) && (shelldex < 255)) {
				switch ((c = z_getch())) {
					case 0x000A : 
					case 0	    : 
					case 0x000D : continue;
					case ' '    :
					case 0x0009 : if ( shelldex == 0 ) 
								continue;
					default	    :
						ShellBuf[shelldex] = (BYTE) c;
						shelldex++;
					}
				}

			if ( shelldex > 255 ) 
				return(-1);

			ShellBuf[shelldex] = (BYTE) 0;

			/* Perform Command and Check for Errors */
			/* ------------------------------------ */
			if ( mf_action((BPTR) ShellBuf ) != 0 )
				return(-1);

			}
		}
	else	/* Unknown Conditional KeyWord */
		/* --------------------------- */
		return(-1);

	return(0);

}

/*
 *	I N I T I A L I S E _ S U F F I X E S
 *	-------------------------------------
 *	Initialisation of inference rule liste dictated by default
 *	suffix analysis when no action is provided for target creation.
 *	This function is called before the makefile is parsed but only
 *	if the makefile has been opened.
 *
 */

int	Initialise_Suffixes()
{
#ifdef AIX_VERS
#ifdef AVIION
 BYTE buf[60];
#endif
#endif /* AIX_VERS */
	/* Check for default suffixes not disabled by '-r' option */
	/* ------------------------------------------------------ */
	if ((UserMode & _DEFAULT_SUFFIX) == 0 ) {
		return(0);
		}

	/* Standard 'C' Compilation and link rules */
	/* --------------------------------------- */
#ifdef AIX_VERS
#ifdef AVIION
	memcpy(buf,".c.o,.h.o",10);
	if ( NewRoot( (BPTR) buf) == -1 ) {
		return(-1);
		}
	memcpy(buf,"cc -c $(@R).c",17);
	if (NewAction( (BPTR) buf) == -1 ) {
		return(-1);
		}
	memcpy(buf,".c,.o",6 ) ;
	if ( NewRoot( (BPTR) buf) == -1 ) {
		return(-1);
		}

	memcpy(buf,"cc -c $@ $(R).c",30);
	if ( NewRoot( (BPTR) buf) == -1) {
		return(-1);
		}
	/* Standard 'ABAL' Translation and Link Rules */
	/* ------------------------------------------ */
	memcpy(buf,".s.o,.s.at",11);
	if ( NewRoot( (BPTR) buf) == -1 ) {
		return( -1 );
		}
	if ( NewAction( (BPTR) "atr $(@R)" ) == -1 ) {
		return( -1 );
		}
	memcpy(buf,".as.o,.as.at",13);
	if ( NewRoot( (BPTR) buf) == -1 ) {
		return( -1 );
		}
	memcpy(buf,"atr -sas $(@R)",15);
	if (NewAction( (BPTR) buf) == -1 ) {
		return( -1 );
		}

	memcpy(buf,".o.at",6);
	if ( NewRoot( (BPTR) buf) == -1 ) {
		return( -1 );
		}
	memcpy(buf,"ald -D$(@R).at $?",18);
	if (NewAction( (BPTR) buf) == -1 ) {
		return( -1 );
		}
	/* Standard COBOL  Translation and Link Rules */
	/* ------------------------------------------ */
	memcpy(buf,".cob.o,.cob.at,.cbl.o,cbl.at",26);
	if ( NewRoot( (BPTR) buf) == -1 ) {
		return( -1 );
		}
	memcpy(buf,"ctr $(@R)",11);
	if (NewAction( (BPTR) buf) == -1 ) {
		return( -1 );
	}
	return(0);
}
#endif /* AVIION */
#endif /* AIX_VERS */
	if ( NewRoot( (BPTR) ".c.o,.h.o" ) == -1 ) {
		return( -1 );
		}
	if ( NewAction( (BPTR) "cc -c $(@R).c" ) == -1 ) {
		return( -1 );
		}
	if ( NewRoot( (BPTR) ".c,.o" ) == -1 ) {
		return( -1 );
		}
	if ( NewAction( (BPTR) "cc -o $@ $(@R).c" ) == -1 ) {
		return( -1 );
		}

	/* Standard 'ABAL' Translation and Link Rules */
	/* ------------------------------------------ */
	if ( NewRoot( (BPTR) ".s.o,.s.at" ) == -1 ) {
		return( -1 );
		}
	if ( NewAction( (BPTR) "atr $(@R)" ) == -1 ) {
		return( -1 );
		}
	if ( NewRoot( (BPTR) ".as.o,.as.at" ) == -1) {
		return( -1 );
		}
	if ( NewAction( (BPTR) "atr -sas $(@R)" ) == -1) {
		return( -1 );
		}
	if ( NewRoot( (BPTR) ".o.at" ) == -1 ) {
		return( -1 );
		}
	if ( NewAction( (BPTR) "ald -D$(@R).at $?" ) == -1 ) {
		return( -1 );
		}
	/* Standard COBOL  Translation and Link Rules */
	/* ------------------------------------------ */
	if ( NewRoot( (BPTR) ".cob.o,.cob.at,.cbl.o,cbl.at" ) == -1 ) {
		return( -1 );
		}
	if ( NewAction( (BPTR) "ctr $(@R)" ) == -1 ) {
		return( -1 );
		}

	return(0);
}


/*
 *	Makefile Analysis Parser
 *	------------------------
 *	Prepares internal structures for makefile operation
 *
 */

int	mf_parser(DollarMake)
BPTR	DollarMake;
{
	int	mode;
	int	c;
	int	l;
	int	line;
	int	i;
	BPTR 	wptr;
	BPTR	xptr;
	BPTR	yptr;
	BPTR	zptr;
	BPTR	buff;

	/* Allocate Parser Work Buffer */
	/* --------------------------- */
	if ((buff = (BPTR) allocate( PARSER_BUFFER_SIZE )) == (BPTR) 0 ) {
		errno = 27; return(-1);
		} 

	/* Initialise all Variables */
	/* ------------------------ */
	line=0; mode = -1; IfDex = 0;

	/* Initialise Collection Buffer */
	/* ---------------------------- */
	*buff = (BYTE) 0;

	/* Initialise Linked List Pointers */
	/* ------------------------------- */
	DefRegle = (RULETREE) 0;	/* Initialise Default Rule	*/
	Regstack = (RULETREE) 0;	/* Initialise Rules Tree Root 	*/
	Sufstack = (RULETREE) 0;	/* Initialise suffixes Stack	*/
	for ( i = 0; i < HASH_MAX; i++)
		TreeRoot[i] = (ARBRE) 0; /* Initialise Quick find Root	*/


	/* Initialise Suffixes : Inference rules */
	/* ------------------------------------- */
	if ( Initialise_Suffixes() == -1 ) {
		liberate ((BPTR) buff );
		errno = 27; return(-1);
		}

	/* Establish Variable $MAKE */
	/* ------------------------ */
	if ((xptr = (BPTR) allocate( 5 )) == (BPTR) 0 ) {
		liberate ((BPTR) buff ); 
		errno = 27; return(-1);
		}

	if ((yptr = (BPTR) allocate((l = (strlen((BPTR) DollarMake )+1)))) == (BPTR) 0 ) {
		liberate ((BPTR) xptr );
		liberate ((BPTR) buff ); 
		errno = 27; return(-1);
		}
	memcpy ( (BPTR) xptr , (BPTR) "MAKE" , 5);
	memcpy ( (BPTR) yptr , (BPTR) DollarMake , l );

	Add_Macro((BPTR) xptr , (BPTR) yptr );

 	l = 0;


	/* Enter Makefile Parser Loop */
	/* -------------------------- */
	while (1) {

		/* Select Character from File */
		/* -------------------------- */
		switch ((c = z_getch())) {

			/* Makefile Conditional Expressions */
			/* -------------------------------- */
			case '!'	:
				if ( l != 0 ) { break; }
				switch ( Conditions() ) {
					case -1 : liberate(buff); return(-1);
					case 2  : liberate(buff); return(0);
					case 1  : l = 0; mode = -1;
					}
				continue;

			/* Tabulation Character switch to Action Mode */
			/* ------------------------------------------ */
			case 0x0009	: if ( l == 0 ) { 
						if ( mode == 1 ) { mode = 2; }
						}
					
			/* Carriage Return is Ignored */
			/* -------------------------- */
			case 0x000D	: continue;

			/* Special Line Joining Character */
			/* ------------------------------ */
			case FINLYN	: if ( line == 0 ) { line = 1; }
					  else		   { line = 0; }
					  continue;

			/* End of Physical Line */
			/* -------------------- */
			case 0x000A	: if ( line != 0 ) {
						line = 0;
						continue;
						}
					  goto thislyne;

				
			/* Indicator of Dependance List */
			/* ---------------------------- */
			case ':'        :
				/* Analysis on Next Character */
				/* -------------------------- */
				switch ((c = z_getch())) {
					case 0		: liberate(buff); return(-1);
					case ' ' 	:
					case 0x000D	:
					case 0x000A 	:
					case 0x0009	: 
						/* Dependance Rule Start */
						/* --------------------- */
						*(buff +l) = ':'; l++; 
						goto ruler;
	
					default		:
						/* Keep The ':' Symbol Please */
						/* -------------------------- */
						*(buff+l) = ':'; l++;
					}
				break;

			/* Space Character separates Tokens */
			/* -------------------------------- */
			case ' '	:

				/* Check for Action Syntax Collection Mode */
				/* --------------------------------------- */
				if ( mode == 2 ) { break; }

			/* End of File */
			/* ----------- */
			case 0  	:

			/* Token Type analysis and Handling */
			/* -------------------------------- */
thislyne:			/* Ignore Empty Tokens Please */
				/* -------------------------- */
				if ( l > 0 ) {
ruler:					/* Terminate the Token Buffer String */
					/* --------------------------------- */
					*(buff + l) = (BYTE) 0;

					/* Check for Dependance Identifier */
					/* ------------------------------- */
					if ( *(buff + l - 1) == ':' ) { 

						/* Remove the Dependance Symbol */
						/* ---------------------------- */
						*(buff + l - 1) = (BYTE) 0;
	
						/* Dependance Rule Start */
						/* --------------------- */
						mode = 0; 
						}

					/* If Dependance Rule Active */
					/* ------------------------- */
					if ( mode != -1 ) {

						/* Store the Element Now */
						/* --------------------- */
						if ( mf_storage(l,(BPTR) buff , mode ) == -1 ) {

							/* Liberate Buffer if Error */
							/* ------------------------ */
							liberate((BPTR) buff );
							return(-1);
							}

						/* Perform Mode Switch if Needed */
						/* ----------------------------- */
						if ( mode == 0 ) { mode = 1; }
						}

					/* Reset The Buffer Index */
					/* ---------------------- */
					l = 0;
					}

				/* Check for and Exit on EOF */
				/* ------------------------- */
				if ( c == 0 ) { liberate((BPTR) buff); return(0); }

				/* Continue MakeFile Analysis */
				/* -------------------------- */
				continue;

			/* Variable Affectation */
			/* -------------------- */
			case '='	: 

				if ( l == 0 ) {
					/* Perform Substitution */
					/* -------------------- */
					zptr = Substitute((BPTR) buff);

					/* Calculate length of String */
					/* -------------------------- */
					if ((l = strlen((BPTR) zptr)) == 0)
						continue;

					/* Save Variable Name */
					/* ------------------ */
					if ((wptr = (BPTR) allocate( l + 1 )) == (BPTR) 0) {
						liberate((BPTR) buff);
						errno = 27;
						return(-1);
						}
					memcpy((BPTR) wptr,(BPTR) zptr,(l+1));
					
					/* Locate Variable Value */
					/* --------------------- */
					l = 0;
					while ((c != 0) && (c != 0x000A)) {
						switch ((c = z_getch())) {
							case 0x000A : 
							case 0	    : 
							case 0x000D : continue;
							case ' '    :
							case 0x0009 : if ( l == 0 ) { continue; }
							default	    :
								*(buff +l) = (BYTE) c;
								l++;
							}
						}
					*(buff+l) = (BYTE) 0;

					/* Perform Substitution */
					/* -------------------- */
					if ((xptr = Substitute( (BPTR) buff )) == (BPTR) 0) {
						liberate((BPTR) buff);
						liberate((BPTR) wptr );
						return(-1);
						}

					/* Save Variable Value */
					/* ------------------- */
					if ((yptr = (BPTR) allocate((l = strlen((BPTR)  xptr )) + 1 )) == (BPTR) 0) {
						liberate((BPTR) buff);
						liberate((BPTR) wptr );	
						errno = 27;
						return(-1);
						}					
					memcpy((BPTR) yptr,(BPTR) xptr,(l+1));

					if ((errno = Add_Macro((BPTR) wptr , (BPTR) yptr )) != 0) {
						liberate((BPTR) buff);
						return(-1);
						}
					l = 0; *buff = (BYTE) 0;
					continue;
					}
				else	break;

			}
		/* Collect all other characters to Buffer */
		/* -------------------------------------- */
		*(buff+l) = (BYTE) c; l++;
		}


}


/*
 *	Special Macros
 *	--------------
 *
 *	Returns the number of Characters transfered
 */

int	DollarMacro( ModeFile , rptr , mode )
int	ModeFile; /* Target(0) or Dependant(1)				*/
BPTR	rptr;	  /* Pointer to Result Buffer 				*/
int	mode;	  /* File Cutting Mask for FN_PARSER			*/

{
	BPTR	objptr;

	if ( ModeFile == 0 ) {

		/* Collect current target or Error */
		/* ------------------------------- */
		if ((objptr = ThisTarget) == (BPTR) 0 ) { 
			return(0); 
			}
		}
	else	{
		/* Collect current Source or Error */
		/* ------------------------------- */
		if ((objptr = ThisSource) == (BPTR) 0) {
			return(0);
			}
		}

	/* Calculate and Test String Length */
	/* -------------------------------- */
	if (strlen((BPTR) objptr ) == 0) {
		return( 0 );
		}

	*rptr = (BYTE) 0;

	/* Extract Portion via fn parser call */
	/* ---------------------------------- */ 
	return( fn_parser((BPTR) objptr,(BPTR) rptr, mode ));

}

unsigned int	Hexa2Digit( cp )
BPTR	cp;
{	
	unsigned int x;
	x = 0;
	if (( *cp >= '0' ) && ( *cp <= '9' )) {
		x = *cp - '0';
		}
	else	{
		if (( *cp >= 'A') && ( *cp <= 'F' )) {
			x = ((*cp - 'A') + 10);
			}
		else	{
			return(0);
			}
		}
	cp++; x <<= 8;
	if (( *cp >= '0' ) && ( *cp <= '9' )) {
		x += (*cp - '0');
		}
	else	{
		if (( *cp >= 'A') && ( *cp <= 'F' )) {
			x += ((*cp - 'A') + 10);
			}
		else	{
			return(0);
			}
		}
	return(x);
}


/*
 *	D E P E N D L I S T ( result , portion )
 *	----------------------------------------
 *	Constructs the dependance list of files for the current target
 *	Respects the 'portion' arguament which indicates the fnparser
 *	file name cutting method required.
 *
 *	Called to fulfil special macros : $?
 *				        : $(? )
 *
 *	Usually used to construct a list of objects for a link phase
 *	syntax. 
 *	
 *	N.B. : 	The files in the resulting list will be separated by the
 *		system dependant DEPEND_FIELD_SEP which is normally SPACE
 *		but must be COMMA for VMS
 *
 */


int	DependList( rptr , portion )

				/* ---------------------------------------- */
BPTR	rptr;			/* Pointer to buffer for result storage	    */
int     portion;		/* Filename portion cutting flags FN_PARSER */
				/* ---------------------------------------- */
{
	BPTR		xptr;
	BPTR		hptr;
	LINKLIST	dptr;
	int		adjuster;
	int		indent;
	int		longeur;
	int		dependance_count;

	/* If rule has no dependancies then nothing can be done */
	/* ---------------------------------------------------- */
	if ( ThisDependance == (LINKLIST) 0 ) { return(0); }

	/* Attempt to allocate new buffer */
	/* ------------------------------ */
	if ((xptr = (BPTR) allocate(( DIMAX+1 ))) == (BPTR) 0) { return(0); }

	/* Store old and affect new buffer Pointer */
	/* --------------------------------------- */
	hptr = workbuf; workbuf = xptr;

	dependance_count = 0;

	/* Transfer with macro expansion the current Dependancy list */
	/* --------------------------------------------------------- */
	dptr = ThisDependance; indent = 0; adjuster = 0; longeur = 0;

	/* Repeat until end of list */
	/* ------------------------ */	
	while ( dptr != (LINKLIST) 0 ) {

		/* Allow substitution to be performed */
		/* ---------------------------------- */
		if ( Substitute((BPTR) dptr->value ) != (BPTR) 0 ) {

			/* Calculate string length and transfer if not 0 */
			/* --------------------------------------------- */
			if ((longeur = strlen( (BPTR) xptr )) != 0) { 

				/* Precede by OS dependant field separator
				 * if not first element in the list
				 */
				if (dependance_count != 0) 
					*(rptr + indent) = DEPEND_FIELD_SEP;

				/* Copy and cut filename portion */
				/* ----------------------------- */
				if ((longeur = fn_parser((BPTR) xptr,(BPTR) (rptr + indent + dependance_count) , portion)) != 0 ) {

					/* Adjust values after transfer */
					/* ---------------------------- */
					longeur  += dependance_count;
					adjuster += longeur;
					indent   += longeur;
					dependance_count = 1;
					}

				}
			
			}

		/* Next element in the list */
		/* ------------------------ */
		dptr = dptr->suite;
		}

	/* Restore original buffer */
	/* ----------------------- */
	workbuf = hptr;

	/* Liberate xallocated buffer */
	/* ------------------------- */
	liberate ( xptr );

	return(adjuster);


}


/*
 *	S U B S T I T U T E ( fnom )
 *	----------------------------
 *	Expands any macros found in fnom and returns a pointer
 *	to the Buffer containing the Result.
 *	The Result is always NUL terminated and may be of NUL length
 *	The Source must be NUL terminated and may be of NUL Length
 *	The Source and Result must never be the same physical memory
 *	zone : this may cause catastrophic results (Exceptions etc).
 *
 */

EXTERN	BPTR	CurrentSymbol;

void	substitution_error()
{
	generate_error_condition(  5, CurrentSymbol );
	return;
}

BPTR Substitute( source )
BPTR source;
{
	if ((source = (BPTR) Expand_Macros((BPTR) workbuf, (BPTR) source )) == (BPTR) 0)
		substitution_error();
	return( source );
}



/*
 *	F I L E S E E K ( filename )
 *	----------------------------
 *	Performs research for a specified dependant to locate and perform
 *	any construction actions required
 *
 *	Returns a pointer to the makefile structure record
 *
 */

RULETREE	FileSeek( tptr )
BPTR		tptr;
{
	int		i,j,k;
	BPTR		sptr;
	RULETREE	lroot;

	/* Initialise to Start of TREE */
	/* --------------------------- */
	lroot = Regstack;

	/* Repeat while current level is still Valid */
	/* ----------------------------------------- */
	while ( lroot != (RULETREE) 0 ) {

		if ( lroot->Depend == (LINKLIST) 0 ) {

			/* Currently Ignores empty dependance Lists */
			/* ---------------------------------------- */

			/* Will Create IMPLICITE dependance List    */
			/* -------------------------------------    */

			}

		else	{

			/* Perform Dynamic substitution */
			/* ---------------------------- */
			if ((sptr = (BPTR) Substitute((BPTR)lroot->Nom)) != (BPTR) 0)

				/* Compare the two file names */
				/* -------------------------- */
				if ( mfcompare((BPTR) sptr, (BPTR) tptr) == 0)
	
					/* Return Pointer to Dependance Rule */
					/* --------------------------------- */
					return( lroot );


			}

		/* Get Next Dependance Rule */
		/* ------------------------ */
		lroot = lroot->suite;
		}

	/* Return Error Result   */
	/* --------------------- */
	return((RULETREE) 0);

}

long	FileStamp();

long	Qlong;

/*	
 *	L I B E R A R B E ( tree_root_pointer )
 *	---------------------------------------
 *	Dismantles the quick find list of already known files
 *
 */

VOID	LiberArbre( lroot )
ARBRE	lroot;
{
	if ( lroot != (ARBRE) 0 ) {
		LiberArbre(lroot->suite);
		liberate((BPTR) lroot->Nom);
		liberate((BPTR) lroot );
		}
	return;
}

unsigned short int	hash_value( filename )
BPTR	filename;
{
	unsigned short int hw;
	hw = 0;
	while (	*filename ) hw += (unsigned short int) *(filename++);
	return( (hw % HASH_MAX) );

}

/*
 *	A D D B R A N C H ( file_time , filename )
 *	------------------------------------------
 *	Adds a file and it's current time info to the quick find list
 *	of already known filenames (avoids repetitive system calls)
 *
 */

long	AddBranch( ftime , fnom )
long	ftime;
BPTR	fnom;
{
	ARBRE	lroot;
	unsigned short int i;

	/* Attempt allocation of a QuickFind Node structure */
	/* ------------------------------------------------ */
	if ((lroot = (ARBRE) allocate( sizeof(struct Arbre) )) != (ARBRE) 0) {

		/* Attempt to allocate space for the file name */
		/* ------------------------------------------- */
		if ((lroot->Nom = (BPTR) allocate((strlen((BPTR)fnom)+1))) != (BPTR) 0) { 

			/* Store thr filename and time into this node */
			/* ------------------------------------------ */
			memcpy((BPTR)lroot->Nom,(BPTR) fnom,(strlen((BPTR) fnom)+1));

			/* Add this node to the top of the tree */
			/* ------------------------------------ */
			lroot->suite = TreeRoot[(i = hash_value( fnom ))];
			lroot->filetime = ftime;
			TreeRoot[i] = lroot;
			}
		else	{
			/* Liberate the xallocated Node structure */
			/* ------------------------------------- */
			liberate((BPTR) lroot);
			}
		}

	/* Return the File_Time value to caller */
	/* ------------------------------------ */
	return( ftime );
}

/*
 *	K E E P T I M E ( filename )
 *	----------------------------
 *	Update the filename time info or add to the QuickFind list 
 *	of already known filenames
 *
 */
 
VOID	KeepTime( name )
BPTR	name;
{
	BPTR	xptr;
	ARBRE	lroot;
	unsigned int i;

	/* Perform Dynamic Substitution */
	/* ---------------------------- */
	if ((xptr = (BPTR) Substitute((BPTR) name )) != (BPTR) 0) {

		/* Scan the Existing file names for an entry for this file */
		/* ------------------------------------------------------- */
		lroot = TreeRoot[(i = hash_value( xptr ))];

		while ( lroot != (ARBRE) 0 ) {

			/* If existing entry found for this file */
			/* ------------------------------------- */
			if ( mfcompare((BPTR) lroot->Nom, (BPTR) xptr ) == 0 ) {

				if ((UserMode & _INHIBIT_ACTION) == 0 )

					/* Establish New Time if Action was performed */
					/* ------------------------------------------ */
					lroot->filetime = FileStamp((BPTR) xptr );
					
				else	/* Force a Remake Time */
					/* ------------------- */
					lroot->filetime = 0x7FFFFFFFL;
					
				return;
				}
			/* Next QuickFind Node */
			/* ------------------- */
			lroot = lroot->suite;
			} 
		}
	if ((UserMode & _INHIBIT_ACTION) != 0 )
		AddBranch(0x7FFFFFFF,xptr);

	return;
}

/*
 *	Q W I K F I N D E R ( filename )
 *	--------------------------------
 *	A quick method of locating already known filenames for Existance
 *	checking
 *
 */

int	QwikFinder( name )
BPTR	name;
{
	ARBRE	lroot;
	lroot = TreeRoot[hash_value(name)];
	while ( lroot != (ARBRE) 0 ) {
		if ( mfcompare((BPTR) lroot->Nom, (BPTR) name ) == 0 ) {
			return( 0 );
			}
		lroot = lroot->suite;
		}
	return(-1);
}

/*
 *	F I L E T I M E ( filename )
 *	----------------------------
 *	Scans the QuickFind file list to locate the file update time
 *	for the specified file.
 *	If no entry exists then it collects the system time and adds
 *	an entry for this file
 */
 
long	FileTime( fnom )
BPTR	fnom;
{
	ARBRE	lroot;
	lroot = TreeRoot[hash_value(fnom)];
	while ( lroot != (ARBRE) 0 ) {
		if ( mfcompare((BPTR) lroot->Nom, (BPTR) fnom ) == 0 ) {
			return( lroot->filetime );
			}
		lroot = lroot->suite;
		}
	return(AddBranch(FileStamp((BPTR) fnom ), (BPTR) fnom));
}

int	CreateImpliciteRule( filename )
BPTR	filename;
{

	return(-1);

}


RULETREE CreateRule( target , dependance )
BPTR	target;
BPTR	dependance;
{
	RULETREE	lroot;
	RULETREE	yroot;

		
	/* Attempt to Allocate new structure */
	/* --------------------------------- */
	if ((lroot = (RULETREE) allocate(sizeof(struct Rules))) != (RULETREE) 0) {

		/* Initialise the Structure */
		/* ------------------------ */
		lroot->suite  = (RULETREE) 0;
		lroot->Status = 0;
		lroot->Action = (LINKLIST) 0;
		lroot->Depend = (LINKLIST) 0;

		establish_trace_info( lroot );

		/* Allocate Target Dependancy */
		/* -------------------------- */
		if (( lroot->Nom = (BPTR) allocate( strlen((BPTR) target) + 1)) != (BPTR) 0) {

			/* Store target Filename */
			/* --------------------- */
			memcpy((BPTR) lroot->Nom, (BPTR) target, (strlen((BPTR) target) + 1));

			/* Create Dependance list */
			/* ---------------------- */
			if (( lroot->Depend = (LINKLIST) allocate(sizeof(struct LinkList))) != (LINKLIST) 0) { 
	
				lroot->Depend->suite = (LINKLIST) 0;

				/* Allocate Dependance value zone */
				/* ------------------------------ */
				if (( lroot->Depend->value = (BPTR) allocate(strlen((BPTR) dependance) + 1 )) != (BPTR) 0) {

					/* Copy dependance value to Structure */
					/* ---------------------------------- */
					memcpy((BPTR) lroot->Depend->value,(BPTR) dependance,(strlen((BPTR) dependance) + 1 ));

					/* Add new rule to end of list */
					/* --------------------------- */
					yroot = Regstack;
					while (yroot->suite != (RULETREE) 0) {
						yroot = yroot->suite;
						}
					yroot->suite = lroot;
		
					return((RULETREE) lroot );
					}

				/* Liberate Dependance Structure */
				/* ----------------------------- */
				liberate((BPTR) lroot->Depend );
				}
			/* Liberate Allocated Name Zone */
			/* ---------------------------- */
			liberate((BPTR) lroot->Nom );
			}
		liberate((BPTR) lroot);

		}

	/* Signal Allocation Error */
	/* ----------------------- */
	return((RULETREE) 0);
}


RULETREE CreateDependanceRule( filename )
BPTR	filename;
{
	RULETREE lsuff;
	BYTE	 ThisSuffix[64];
	int	 i;
	BPTR	 wptr;

	/* Note : Filename has already been MacroExpanded */
	/* ---------------------------------------------- */
	/* Collect Target Suffix			  */
	/* ---------------------			  */
	if ((i = fn_parser((BPTR) filename , (BPTR) ThisSuffix , 0x0010 )) != 0) {

		/* Attempt to locate a Source file Expression from Suffixes */
		/* -------------------------------------------------------- */
		lsuff = Sufstack;
		
		/* Repeat till end of suffixes Tree */
		/* -------------------------------- */
		while ( lsuff != (RULETREE) 0 ) {

			/* Test for Current Suffix Match Found */
			/* ----------------------------------- */
			if ( Check_Suffix((BPTR) ThisSuffix,(BPTR) lsuff->Nom ) == 0 ) {

				/* Suffixes Expression found so Create New Rule Node */
				/* ------------------------------------------------- */
				/* 1st Element of First Field is the Suffix */
				/* ---------------------------------------- */
				i    = fn_parser((BPTR) filename, (BPTR) ThisSuffix, 0x000F);
				wptr = (BPTR) lsuff->Nom;
				do	{
					ThisSuffix[i++] = *(wptr++);
					if ( IsSeparator( *(wptr) ) == 0 ) {
						break;
						}
					}
				while ((*wptr != ',') && (*wptr != 0));
				ThisSuffix[i] = 0;
				return(CreateRule((BPTR) filename,(BPTR) ThisSuffix));

				}

			/* Collect next suffix Pointer */
			/* --------------------------- */
			lsuff = lsuff->suite;

			} 		

		}

	/* No Default Rule to be created */
	/* ----------------------------- */
	return((RULETREE) 0);	
}

/*
 *	D i s p l a y _ F i l e _ T i m e ( filetime )
 *	----------------------------------------------
 *	Displays the file time for option -D (Debug/Date)
 *
 */

VOID	display_file_time( filetime )
long	filetime;
{

#ifndef	PRL
#ifndef	DOS
	struct tm * LocalTime;

	/* Convert to Local Time */
	/* --------------------- */
	LocalTime = (struct tm * ) localtime(&filetime);
	printf(" (%d-%d-%d  %d:%d:%d) ",LocalTime->tm_mday,LocalTime->tm_mon,1900+LocalTime->tm_year,LocalTime->tm_hour,LocalTime->tm_min,LocalTime->tm_sec);
#endif
#endif

#ifndef UNIX
#ifndef VMS
	union  prl_dos_time {
		long	  longvalue;
		short int wordvalue[2];
		} work;

	work.longvalue = filetime;

	/* Convert Date and Time Word to structure */
	/* --------------------------------------- */
	llmf_co('('); llmf_co(' ');
	DecimalWord(( work.wordvalue[1] & 0x001F ));		/* DAY */
	llmf_co('-');
	DecimalWord((( work.wordvalue[1] >> 5) & 0x00F ));	/* MONTH */
	llmf_co('-');
	DecimalWord(((( work.wordvalue[1] >> 9) & 0x07F )+1980)); /* YEAR */
	llmf_co(' ');
	DecimalWord((( work.wordvalue[0] >> 11) & 0x01F ));	/* HOUR */
	llmf_co(':');
	DecimalWord((( work.wordvalue[0] >> 5) & 0x003F ));	/* MIN	*/
	llmf_co(':');
	DecimalWord((( work.wordvalue[0] & 0x001F ) * 2));	/* SEC */
	llmf_co(' ');
	llmf_co(')');
#endif
#endif
	return;
}


/*
 *	M F _ C H E C K ( makefile_rule_node )
 *	--------------------------------------
 *
 */

int	mf_check( lRule )
RULETREE	lRule;
{
	LINKLIST	lroot;	/* Local Linked List Pointer	   	*/
	BPTR		nptr;	/* Name Pointer after Substitution 	*/
	int		status;	/* Status of this File		   	*/
	int		x;
	RULETREE	y;	/* Possible Sub-Dependance Rule		*/
	RULETREE	LocalDef;
	BPTR		fptr;
	BPTR		lptr;
	long		ptime;
	long		dtime;

	/* Perform Substitution */
	/* -------------------- */
	if ((nptr = Substitute( (BPTR) lRule->Nom )) == (BPTR) 0) {
		errno = 77;
		return(-1);
		}

	/* Check for Debug / Dates Option */
	/* ------------------------------ */
	if ((UserMode & _DEBUG_DATE) != 0 ) {
		mf_message((BPTR) TalkPtr[9] );
		mf_message((BPTR) nptr );
		}

	/* Check for File Existance */
	/* ------------------------ */
	if ( Existance((BPTR) nptr , 0 , 1 ) != 0 ) {

		/* Check for Silence Required */
		/* -------------------------- */
		if ( (UserMode & _SILENCE) == 0 ) {

			/* If not Silence then Check if in NoExecute Mode */
			/* ---------------------------------------------- */
			if ((UserMode & _INHIBIT_ACTION) == 0)
				generate_warning_condition( 3, nptr, lRule );

			}
		/* If Neither Force Nor Error Ignore */
		/* --------------------------------- */
		if ((UserMode & (_INHIBIT_ACTION | _IGNORE_ERRORS)) == 0 )
			status = MISSING;
		else	status = NOBUILD;
		}
	else	{
		if ( UserMode & _FORCE_REBUILD ) 
			status = REBUILD;
		else	status = NOBUILD;

		/* Perform Date Checking Here Please */
		/* --------------------------------- */
		if ((ptime = FileTime( (BPTR) nptr )) == -1L ) {
			if ((UserMode & (_IGNORE_ERRORS | _INHIBIT_ACTION)) == 0 ) {
				errno = 35;
				return( -1 );
				}
			}
		}
	x = 0;

	/* Check for Debug / Dates Option */
	/* ------------------------------ */
	if ((UserMode & _DEBUG_DATE) != 0 ) {
		display_file_time( ptime );
		utline();
		}

	/* Check each of the dependance files for Actuality */
	/* ------------------------------------------------ */
	lroot = lRule->Depend;

	while ( lroot != (LINKLIST) 0 ) {

		/* First create substituted Version of FileName */
		/* -------------------------------------------- */
		if (( fptr = Substitute( lroot->value )) == (BPTR) 0 ) {
			errno = 36;
			return(-1);
			}

		/* Allocate a local storage buffer */
		/* ------------------------------- */
		if ((lptr = (BPTR) allocate(strlen((BPTR) fptr)+1)) == (BPTR) 0) {
			errno = 37;
			return(-1);
			}

		/* Transfer to Private Buffer */
		/* -------------------------- */
		memcpy((BPTR) lptr,(BPTR) fptr, strlen((BPTR) fptr)+1);

		LocalDef = DefRegle;

		/* Test to see if a dependance rule exists for the file */
		/* ---------------------------------------------------- */
		if ((y = FileSeek((BPTR) lptr)) == (RULETREE) 0) {

			/* Test for generate default dependances */
			/* ------------------------------------- */
			if (( UserMode & _INFERENCE ) != 0 )

				/* Allow possible creation of a Dependance Rule */
				/* -------------------------------------------- */
				y = (RULETREE) CreateDependanceRule( (BPTR) lptr );
		
			}

		/* If a dependance rule has been found or Created */
		/* ---------------------------------------------- */
		if ( y != (RULETREE) 0 ) {

			/* Evaluate Dependance Rule */
			/* ------------------------ */
			if ( ll_Maker( y ) == -1 ) {

				/* Check for Ignore Errors */
				/* ----------------------- */
				if ((UserMode & (_INHIBIT_ACTION | _IGNORE_ERRORS)) == 0 ) {

					if ( (UserMode & _SILENCE) == 0 ) 
						generate_warning_condition( 2, lptr, lRule );

					/* Liberate Private buffer before return */
					/* ------------------------------------- */
					DefRegle = LocalDef;
					liberate((BPTR) lptr);
					return( -1 );
					}
				}
			}

		DefRegle = LocalDef;

		/* Check for Debug Option */
		/* ---------------------- */
		if ((UserMode & _DEBUG_DATE) != 0 ) {
			mf_message((BPTR) TalkPtr[10] );
			mf_message((BPTR) lptr );
			}

		/* Now check for Existance */
		/* ----------------------- */
		if ( Existance( lptr , 0 , 1 ) != 0 ) {

			/* See if Rule Exists */
			/* ------------------ */
			if ( y == (RULETREE) 0) {

				if ((UserMode & (_TARGET_OK | _INHIBIT_ACTION | _IGNORE_ERRORS )) == 0) {
					errno = 36;
					return(-1);
					}

				/* Ignore the FILE NOT FOUND ERROR */
				/* ------------------------------- */
				if (( UserMode & _INHIBIT_ACTION ) != 0 ) {
					KeepTime((BPTR) lptr );
					dtime = 0x7FFFFFFF;
					}
				if (( UserMode & _TARGET_OK ) != 0 )
					dtime = 0;
					

				}

			else	{
				/* -----------------------------------*/
				/* File does not exist:No Rule Exists */
				/* ---------------------------------- */
				/* Check for Message Display Required */
				/* ---------------------------------- */
				if ( (UserMode & _SILENCE ) == 0 )
					if ((UserMode & _INHIBIT_ACTION) == 0 )
						generate_warning_condition( 2, lptr, lRule );

				if ((UserMode & (_INHIBIT_ACTION | _IGNORE_ERRORS)) == 0 ) {
					errno = 38;
					return(-1);				
					}
				}	
			}
		else	{

			/* File Exists to Perform Date Stamp Read */
			/* -------------------------------------- */
			if ((dtime = FileTime( (BPTR) lptr )) == -1L ) {
				if ((UserMode & (_INHIBIT_ACTION | _IGNORE_ERRORS)) == 0 ) {
					errno = 39;
					return( -1 );
					}
				else    {
					if ((UserMode & _INHIBIT_ACTION) != 0 ) {
						KeepTime( (BPTR) lptr );
						dtime = 0x7FFFFFFFL;
						}
					}
				}
			}

		/* Check for Debug / Dates Option */
		/* ------------------------------ */
		if ((UserMode & _DEBUG_DATE) != 0 ) {
			display_file_time(dtime);
			utline();
			}

		/* Test Dependant make time with Produce Make Time */
		/* ----------------------------------------------- */
		if (( status != MISSING )
		&&  ( dtime > ptime     )) 
			status = REBUILD;

		/* Liberate Private buffer */
		/* ----------------------- */
		liberate((BPTR) lptr);
		x++;

		/* Next Dependance file List Element */
		/* --------------------------------- */ 
		lroot = lroot->suite;
		}	
	/* Return Rebuild status */
	/* --------------------- */
	return(status);
}

int	DollarCheck( wptr )
BPTR	wptr;
{
	int	c;

	/* While not end of String */
	/* ----------------------- */
	while ( *wptr != (BYTE) 0 ) {

		/* If Variable Indicator Detected */
		/* ------------------------------ */
		if ( *wptr == '$' ) {

			/* If String long enough */
			/* --------------------- */
			if ( strlen((BPTR) wptr) > 6 ) {

				/* Save Byte and Compare for $MAKE */
				/* ------------------------------- */
				c = *(wptr + 7);
				*(wptr + 7) = (BYTE) 0;
				if ( mfcompare((BPTR) wptr , (BPTR) "$(MAKE)" ) == 0 ) {

					/* Compare TRUE so Return 1 OK */
					/* --------------------------- */
					*(wptr + 7) = (BYTE) c;
					return(1);
					}
				*(wptr + 7) = (BYTE) c;
				wptr++;
				}
			else	return(0);
			}
		else	wptr++;
		}
	return(0);
}

/*
 *	mf_action ( cmdptr )
 *	--------------------
 *	LowLevel command which performs the SYSTEM command 
 *	required by dependace rules
 *
 */

int	mf_action( cmdptr )
BPTR cmdptr;
{
	BPTR	xptr;
	int	flags;
	int	DollarForce;
	int	Error_Limit;

	/* If Mode is -n Display but do not execute */
	/* ---------------------------------------- */	
	if ((UserMode & _INHIBIT_ACTION) != 0 ) 
		DollarForce = DollarCheck( cmdptr );

	/* Test for dynamic substitution needed */
	/* ------------------------------------ */
	if ((xptr = (BPTR) Substitute( (BPTR) cmdptr )) == (BPTR) 0 )
		return( -1 );

	/* Establish Line Option Flags */
	/* --------------------------- */
	flags = 0;
	while (( flags & 1 ) == 0 ) {
		switch ( *xptr ) {
			case ' ' : xptr++; continue;

			case 0   : return(0);

			case '@' : flags |= 2; xptr++; continue;

			case '-' : flags |= 4; xptr++;

				   /* Check for Error limit to Ignore */
				   /* ------------------------------- */
				   if (( *xptr >= '0' ) && ( *xptr <= '9' )) {
					flags |= 8;
					Error_Limit = 0;
					while (( *xptr >= '0' ) && ( *xptr <= '9' )) {
						Error_Limit *= 10;
						Error_Limit += ( *(xptr++) - '0');
						}
					}
				   continue;

			default  : flags |= 1;
			}
		}
	
	/* Check for Display Required */
	/* -------------------------- */

	if ((( (UserMode & _SILENCE) == 0 ) && (( flags & _INHIBIT_ACTION ) == 0)) || ((UserMode & _INHIBIT_ACTION) != 0 )) { 

		/* Display Result String for Now */
		/* ----------------------------- */
		mf_message((BPTR) xptr );
		utline();
		}

	/* Execute System Command if not inhibited by -F */
	/* --------------------------------------------- */
	if (((UserMode & _INHIBIT_ACTION) == 0 ) || ( DollarForce == 1)) 
		errno = system((BPTR) xptr ); 

	/* Check for Error Limit Declared */
	/* ------------------------------ */
	if (( flags & 0x000C ) == 0x000C )
		if ( errno >= Error_Limit )
			flags &= 0x000B;
			
	/* Check for Error Returns and return if needed  */
	/* --------------------------------------------  */
	if ((( flags & 4 ) == 0 ) && ((UserMode & _IGNORE_ERRORS) == 0 )) {
		if ((errno & 0xFFFF) == EXIT_VALUE ) 
			return(0); 
		else	return(-1);
		}
	else	{
		/* Clear Errors and Return SUCCESS */
		/* ------------------------------- */
		errno = 0;
		return(0);
		}
}

#ifdef PRL
EXTERN VOID touche(BPTR);
VOID	NowStamp( lRule )
RULETREE	lRule;
{
	BPTR	nptr;

	/* Perform Substitution */
	/* -------------------- */
	if ((nptr = Substitute( (BPTR) lRule->Nom )) == (BPTR) 0)
		return;
		
	/* Perform File Time Update */
	/* ------------------------ */
	touche((BPTR) nptr);	

	return;
}
#endif


/*
 *	T O U C H E T A R G E T ( )
 *	----------------------------
 *	Updates by touching the target to be created
 *
 */

VOID	ToucheTarget()
{
	BPTR	nptr;

	/* Allow substitution */
	/* ------------------ */
	if ((nptr = (BPTR) Substitute((BPTR) ThisTarget )) != (BPTR) 0) {

		/* Update File Time */
		/* ---------------- */
		touche( nptr );

		/* Collect and keep current file time */
		/* ---------------------------------- */
		KeepTime( nptr );

		}
	return;
}

/*
 *	Performs the list of required actions for the current
 *	dependance rule (Recursive Function)
 *
 */

int	hl_action( lroot )
LINKLIST	lroot;
{
	/* If Current Level Valid */
	/* ---------------------- */
	if ( lroot != (LINKLIST) 0 ) {

		/* Activate next Level */
		/* ------------------- */
		if ( hl_action( lroot->suite ) == 0 ) {

			/* OK so far so do Current Action */
			/* ------------------------------ */
			if ( mf_action((BPTR) lroot->value ) != 0 )

				/* Ensure Errors are not lost */
				/* -------------------------- */
				return(-1);

			/* Indicate that a rule action has been performed */
			/* ---------------------------------------------- */
			action_status = 1;

			/* Indicate this level SUCCESS */
			/* --------------------------- */
			return(0);
			}

		/* Retransmit error due to Previous Level */
		/* -------------------------------------- */
		else	return(-1);
			
		}				
	/* Nothing to Do so No Error */
	/* ------------------------- */
	return(0);
}

unsigned int  	EvalDex;
BYTE	 	EvalBuff[512];

BPTR	Evaluate( fnom )
BPTR	fnom;
{
	BPTR		wptr;
	unsigned int	debut;

	if ((wptr = (BPTR) Substitute((BPTR) fnom)) == (BPTR) 0)
		return( (BPTR) 0 );
		
	debut = EvalDex;	
	memcpy ((BPTR) & EvalBuff[EvalDex] , (BPTR) wptr, (strlen((BPTR) wptr) + 1));
	EvalDex += (strlen((BPTR) wptr) + 1);

	return( (BPTR) & EvalBuff[debut] );

}


/*
 *	S E A R C H S U F F I X E S ( lRule )
 *	-------------------------------------
 *	Attempts to locate a default suffixes action block
 *	for the current rule under evaluation
 *
 */

LINKLIST	SearchSuffixes( lRule )
RULETREE	lRule;
{
	RULETREE	lsuff;
	BYTE	ThisSuffix[64];
	BPTR	tptr;
	int	i;
	LINKLIST	TheseActions;


	/* Watch out for no suffixe list */
	/* ----------------------------- */
	if ( Sufstack != (RULETREE) 0 ) {

		/* Initialise local variables */
		/* -------------------------- */
		lsuff = Sufstack; i = 0; ThisSuffix[0] = 0;

		/* Allow substitution of Target Name */
		/* --------------------------------- */
		if ( lRule->Depend == (LINKLIST) 0) 
			return((LINKLIST) 0);

		if ( lRule->Depend->value == (BPTR) 0) 
			return((LINKLIST) 0);

		if (( tptr = (BPTR) Substitute((BPTR) lRule->Depend->value )) == (BPTR) 0)
			return((LINKLIST) 0);


		/* Collect Target Suffix */
		/* --------------------- */
		i = fn_parser((BPTR) tptr , (BPTR) ThisSuffix , 0x0010 );

		/* Allow substitution of Target Name */
		/* --------------------------------- */
		if (( tptr = (BPTR) Substitute((BPTR) lRule->Nom )) == (BPTR) 0)
			return((LINKLIST) 0);

		/* Collect Target Suffix */
		/* --------------------- */
		i += fn_parser((BPTR) tptr , (BPTR) &(ThisSuffix[i]) , 0x0010 );


		/* Now Scan till End of Suffixs list */
		/* --------------------------------- */
		while ( lsuff != (RULETREE) 0) {

			/* Check for suffixs compare is true */
			/* --------------------------------- */
			if ( Sfx_Compare((BPTR) ThisSuffix,(BPTR) lsuff->Nom ) == 0 )
				
				/* Suffixes Rule Has been Found */
				/* ---------------------------- */
				return((LINKLIST) lsuff->Action);


			/* Collect next Pointer */
			/* -------------------- */
			lsuff = lsuff->suite;
			}


		}

	/* Return to Caller */
	/* ---------------- */
	return((LINKLIST) 0);

}


/*
 *	L L _ M A K E R ( lrule )
 *	-------------------------
 *	Performs intermediate level make rule scan functions
 *	(Recursive Function Via mf_check() )
 *
 */

int	ll_Maker( lRule )
RULETREE	lRule;
{
	int		x;
	int		build_status;
	int		hold_action;
	LINKLIST	TheseActions;

	/* Check for Default Actions */
	/* ------------------------- */
	if ( lRule->Depend == (LINKLIST) 0 )
		DefRegle = lRule;

	hold_action   = action_status;
	action_status = 0;

	/* Check status of current Rule */
	/* ---------------------------- */
	if ( lRule->Status == UNKNOWN ) {

		/* Indicate WORKING to avoid re-entrance */
		/* ------------------------------------- */
		lRule->Status = WORKING;

		/* Select WRT result of MAKEFILE CHECKING */
		/* -------------------------------------- */
		switch ((build_status = mf_check(lRule))) {


			case REBUILD :	/* Target Exists but needs rebuild */
					/* ------------------------------- */
				if ( action_status == 1 ) {
					build_status = MISSING;
					action_status = 0;
					hold_action   = 1;
					}

			case MISSING :	/* Target does not exist 	   */
					/* ------------------------------- */

				/* Establish Current Dependance List */
				/* --------------------------------- */
				ThisDependance = lRule->Depend;

				EvalDex = 0;

				/* Establish Current Source file */
				/* ----------------------------- */
				ThisSource = Evaluate((BPTR) lRule->Depend->value );

				/* Establish Current Object */
				/* ------------------------ */
				ThisTarget = Evaluate((BPTR) lRule->Nom );

				/* Check for file out of date not missing */
				/* -------------------------------------- */
				if ( build_status != MISSING ) {

					/* Check for TOUCHE TARGET option */
					/* ------------------------------ */
					if ((UserMode & _TOUCH_TARGET) != 0) {

						/* Check for VERBOSE active */
						/* ------------------------ */
						if ((UserMode & _SILENCE) == 0) { 

							/* Verbalise Touche */
							/* ---------------- */
							mf_message((BPTR) TalkPtr[11] );

							mf_message((BPTR) ThisTarget );
							utline();

							}

						/* Touche the target file */
						/* ---------------------- */
						if (( UserMode & _INHIBIT_ACTION) == 0)
							ToucheTarget();
						else	KeepTime((BPTR) ThisTarget );

						errno = EXIT_VALUE;	
						lRule->Status = KNOWN;   
						break;
						}
					}

				/* Check for Default Actions */
				/* ------------------------- */
				if ((TheseActions = lRule->Action) == (LINKLIST) 0 )
					
					/* Perform Suffixes Tree Search */
					/* ---------------------------- */
					TheseActions = SearchSuffixes( lRule );

				/* Check for Still Default Actions */
				/* ------------------------------- */
				if (TheseActions == (LINKLIST) 0 ) {

					/* Check for Default Actions available */
					/* ----------------------------------- */
					if ( DefRegle != (RULETREE) 0 ) {

						/* Perform Default Action Work */
						/* --------------------------- */
						if ( hl_action( DefRegle->Action ) == -1 ) {

							/* Status UNKNOWN due to Error */
							/* --------------------------- */
							lRule->Status = UNKNOWN;
							action_status = hold_action;
							return(-1);
							}

						action_status = 0;
						hold_action   = 1;

						/* Correct the Time in Qwik File List */
						/* ---------------------------------- */
						KeepTime( lRule->Nom );
						}
					else	{
						/* Neither Declared nor Default Actions */
						/* ------------------------------------ */ 
						lRule->Status = UNKNOWN;

						/* Check for Silence Required */
						/* -------------------------- */
						if ( (UserMode & _SILENCE) == 0 )
							generate_warning_condition( 2, lRule->Nom, lRule );

						action_status = hold_action;
						return(-1);
						}
					}
				else	{
					/* Perform Declared Actions for Update */
					/* ----------------------------------- */
					if ( hl_action( TheseActions ) == -1 ) {

						/* Status UNKNOWN due to Error */
						/* --------------------------- */
						lRule->Status = UNKNOWN;
						action_status = hold_action;
						return(-1);
						}
					action_status = 0;
					hold_action   = 1;
					}
#ifdef	PRL_BEFORE_WE_MODIFIED_IT
				NowStamp( lRule );
#endif
				KeepTime((BPTR) lRule->Nom );

			case NOBUILD : lRule->Status = KNOWN;   break;

			default: lRule->Status = UNKNOWN; 
				 if ( (UserMode & _SILENCE) == 0 )
					generate_warning_condition( 2, lRule->Nom, lRule );

				 action_status = hold_action;
				 return(-1);

			}
		}
	else	{
		/* Check for Status currently Working */
		/* ---------------------------------- */
		if ( lRule->Status == WORKING ) {

			/* Check for Silence Required */
			/* -------------------------- */
			if ( (UserMode & _SILENCE) == 0 )
				generate_warning_condition( 4,(BPTR) " ", lRule );

			action_status = hold_action;
			return(-1);
			}
		else	{
			/* Return SUCCESS */
			/* -------------- */
			action_status = hold_action;
			return(0);
			}
		}
	/* Return SUCCESS */
	/* -------------- */
	action_status = hold_action;
	return(0);
}


/*
 *	Entry Point for dependance rule Analysis
 *	----------------------------------------
 *	Called from main() after parser function
 *
 */

int	mf_Maker()
{
	RULETREE	LastRegle;

	Qlong   =  0;

	/* Indicate Parser phase ended for Substituter */
	/* ------------------------------------------- */
	SetParseEnd();

	ThisRule = Regstack;

	action_status = 0;

	while ( ThisRule != (RULETREE) 0 ) {

		/* Check for Default Actions */
		/* ------------------------- */
		if ( ThisRule->Depend == (LINKLIST) 0 )
			DefRegle = ThisRule;
		else	{
			/* Save current Default Action Ptr   */
			/* --------------------------------- */
			LastRegle = DefRegle;

			/* Perform Rule Analysis and actions */
			/* --------------------------------- */
			if ( ll_Maker( ThisRule ) != 0 ) {
				DefRegle = LastRegle; 
				ResetParseEnd();
				action_status = 0;
				return(-1); 
				}

			/* Restore Current Default Action Ptr */
			/* ---------------------------------- */
			action_status = 0;
			DefRegle = LastRegle;
			}

		/* Position to next dependance Rule */
		/* -------------------------------- */
		ThisRule = ThisRule->suite;
		}

	ResetParseEnd();
	return(0);

}

/*
 *	Display of Constants Values (Recursive function)
 *	------------------------------------------------
 *
 */

VOID	list_cons()
{
	int	ret_cod;
	BPTR	xptr;
	BPTR  yptr;

	/* Position to First Macro Name in List */
	/* ------------------------------------ */
	ret_cod = First_Macro( (BPTR XPTR) & xptr , (BPTR XPTR) & yptr);

	while ( ret_cod == 0 ) { 

		/* Perform Name Field Substitution */
		/* ------------------------------- */
		if((xptr = (BPTR) Substitute((BPTR)xptr )) != (BPTR) 0)

			/* Display if Successful */
			/* --------------------- */
 			mf_message((BPTR) xptr  );

		/* Perform Value Field Substitution */
		/* -------------------------------- */
		if ((yptr = (BPTR) Substitute((BPTR)yptr)) != (BPTR) 0) {

			/* Display if Successful */
			/* --------------------- */
			mf_message((BPTR) " = ");
			mf_message((BPTR) yptr  );
			}

		/* Force New Line */
		/* -------------- */
		utline();

		/* Position to Next Macro Name in List */
		/* ----------------------------------- */
		ret_cod = Next_Macro( (BPTR XPTR) & xptr , (BPTR XPTR) & yptr);

		}

	/* Return from this Level */
	/* ---------------------- */
	return;
}

BPTR	lrxptr;

/*
 *	Display list of Dependant files (Recursive Function)
 *	----------------------------------------------------
 *
 */ 

VOID	list_Depend( lroot )
LINKLIST	lroot;
{
	if ( lroot != (LINKLIST) 0 ) {
		list_Depend( lroot->suite );
		if ((lrxptr = (BPTR) Substitute((BPTR) lroot->value)) != (BPTR) 0) {
 			llmf_co(' ');
			mf_message((BPTR) lrxptr );
			}
		}
	return;
}

/*
 *	Display list of Action (Recursive Function)
 *	-------------------------------------------
 *
 */

VOID	list_Action( lroot )
LINKLIST	lroot;
{
	if ( lroot != (LINKLIST) 0 ) {
		list_Action( lroot->suite );
		if ((lrxptr = (BPTR) Substitute((BPTR) lroot->value)) != (BPTR) 0) {
			utline();
			llmf_co(0x0009);
			mf_message((BPTR) lrxptr );
			}
		}
	return;
}

/*
 *	Display list of Dependance Rules (Recursive Function)
 *	-----------------------------------------------------
 *
 */

VOID	list_rule(lroot)
RULETREE	lroot;
{

	if ( lroot != (RULETREE) 0 ) {
		list_rule( lroot->suite );
		if ((lrxptr = (BPTR) Substitute((BPTR) lroot->Nom)) != (BPTR) 0 ) {
			mf_message((BPTR) lrxptr );
			llmf_co(':');
			list_Depend((BPTR) lroot->Depend );
			list_Action((BPTR) lroot->Action );
			utline();
			}
		}
	return;
}

/*
 *	Liberate dependance root tree of structures (Recursive Function)
 *	----------------------------------------------------------------
 *
 */

VOID	xliberate_rule(lroot)
RULETREE	lroot;
{
	if ( lroot != (RULETREE) 0 ) {
		xliberate_rule( lroot->suite );
		xliberate_list( lroot->Depend);
		xliberate_list( lroot->Action);
		liberate((BPTR) lroot->Nom );
		liberate((BPTR) lroot->MakeFile);
		liberate((BPTR) lroot );
		}
	return;

}

#endif	/* _UTANA_C */
	/* -------- */


