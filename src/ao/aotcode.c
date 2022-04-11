/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	TCODE.C   				*/
/*		Version :	1.4d / 2.1b				*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_TCODE_C
#define	_TCODE_C

#define	OPTIMISEUR

#include "aomain.h"		/* Global Constants			*/
#include "aobib.h"		/* Library functions			*/
#include "aotcode.h"		/* T-Code Definitions			*/
#include "aotcesc.h"		/* ESC T-Codes				*/
#include "aotcngf.h"		/* NGF T-Codes				*/
#include "aostat.h"		/* Statistics control values and data	*/
#include "aostruct.h"		/* Program Control Structure Analysis	*/


#define	ISDYNAMIC	0x8000		/* Indicates a special type	*/
#define	ISMEMBER  	0x2000		/* Indicates a member type	*/
#define	ISPOINTER	0x1000		/* Indicates a pointer type	*/

extern	BYTE	ControlZone[256];
extern	EXAWORD	debug;
extern	EXAWORD	statix;
extern	BYTE	trad_ver;

#ifndef	VISUAL_DEBUGER
#include "aomnem.h"		/* T-Code Mnemonics			*/

extern	BPTR	tcLCT;		/* Local Constants  table		*/
extern	BPTR	tcGKT;		/* Global constants table		*/
extern	BPTR	tcLDT;		/* Local  variables Table		*/
extern	BPTR	tcLNT;		/* Local  variables Names		*/
extern	BPTR	tcGDT;		/* Global variables Table		*/
extern	BPTR	tcGNT;		/* Global variables Names		*/
extern	BPTR	tcPNT;
extern	EXAWORD	lnPNT;

#ifdef	AO_STATS
	EXAWORD _tc_stat[256];
	EXAWORD _io_stat[16];
	EXAWORD _esc_stat[256];
	EXAWORD _ngf_stat[64];
	EXAWORD _clf_stat[256];
#endif

#else	/* VISUAL DEBUGER */

#include "aomnem.h"		/* T-Code Mnemonics			*/

extern	BPTR	TcodeConstants;
extern	BPTR	GlobalConstants;
extern	BPTR	LocalNamesTable;
extern	BPTR	GlobalNamesTable;
extern	BPTR	GlobalDataTable;
extern	BPTR	LocalDataTable;

#define	tcLCT   TcodeConstants
#define	tcGKT   GlobalConstants
#define	tcLDT	LocalDataTable
#define	tcGDT	GlobalDataTable
#define	tcGNT	GlobalNamesTable
#define	tcLNT	LocalNamesTable

#ifdef	AO_STATS
	EXAWORD _tc_stat[256];
	EXAWORD _io_stat[16];
	EXAWORD _esc_stat[256];
	EXAWORD _ngf_stat[64];
	EXAWORD _clf_stat[256];
#endif
#endif

#include "aostream.h"

void	VarbName( EXAWORD varbid );
BPTR	ResolveVariableName( EXAWORD variable );

#ifdef	AO_STATS
void	flush_stats();
#endif

void	AffLine()
{
	StreamLine();
}

void	AffMsg( mptr )
BPTR	mptr;
{
	StreamString( mptr );
}

/*	External Decimal and Hexa Display Functions	*/
/*	-------------------------------------------	*/
extern	void	DecimalWord( EXAWORD );
extern	void	HexaOctet( EXAWORD );
extern	void	HexWord( EXAWORD );
extern	void	HexLong( long );
extern 	void	HexAdresse( EXAWORD );
	EXAWORD	tcGetw( BPTR );

/*	Affichage d'un Registre		*/
/*	-----------------------		*/
void	AffReg( regid )
EXAWORD	regid;
{
	oputb('R');
	DecimalWord( regid );
	return;
}

/*	
 * 	Generates an Ascii string from an ABAL Format code string
 *	---------------------------------------------------------
 * 
 */

#include "aofmt.h"

#ifndef	VISUAL_DEBUGER

EXAWORD	fmtoa(fptr)
BPTR	fptr;		
{
	EXAWORD	xtrl,x,y,n;
	BPTR	nptr;
	BPTR	hptr;
	BYTE	valu[4];
	EXAWORD	fmtlng;
	EXAWORD	fmtret;

fmtlng	= (EXAWORD) *(fptr++); fmtret = fmtlng;

if ( *fptr != (BYTE) 0x00FE ) { 
	return(fmtret); 
	}

fptr++; oputb('('); xtrl = 0;

do 	{ 
	y = (EXAWORD) *(fptr++); 
	switch ( y ) {
		case	FMT_D	: x = 'D' ; break;
		case	FMT_A	: x = 'A' ; break;
		case	FMT_N	: x = 'N' ; break;
		case	FMT_Z	: x = 'Z' ; break;
		case	FMT_K	: x = 'K' ; break;
		case	FMT_O	: x = 'O' ; break;
		case	FMT_C	: x = 'C' ; break;
		case	FMT_B	: x = 'B' ; break;
		case	FMT_W	: x = 'W' ; break;
		case	FMT_U	: x = 'U' ; break;
		case	FMT_V   : oputb('V'); fptr++;  continue;
		case	FMT_P	: oputb('.'); continue;
		case	FMT_DOL : oputb('$'); continue;
		case	FMT_PR	: oputb('"'); 
				  x = *(fptr++);
				  while (x > 0) { oputb(*(fptr++)); x--;}
				  oputb('"'); continue;
		case	FMT_LF  : x = '/' ; break;
		case	FMT_ATB	: x = '\\' ; break;
		case	FMT_TAB	: x = 'T' ; break;
		case	FMT_ESP	: x = 'X' ; break;
		case	FMT_SEP	: oputb(',');  continue;
		case	FMT_STR	: oputb('E');  continue;
		case	FMT_CUT	: oputb('F');  continue;
		case	FMT_ZER	: oputb('*');  continue;
		case	FMT_JL	: oputb('L');  continue;
		case	FMT_JR	: oputb('R');  continue;
		case	FMT_NEG	: x = '-'; break;
		case	FMT_PNG	: x = '+'; break;
		case 	FMT_H   : oputb('H');  continue;
		case 	FMT_INH : oputb('I');  continue;
		case	FMT_MIL : oputb('S');  continue;
		case	FMT_DYN : oputb('?');  continue;
		case	FMT_MCH	: oputb('S');
				  oputb('(');
				  oputb(*(fptr++)); 
				  oputb(')');
				  continue;
		case	FMT_DCH	: oputb('$');
				  oputb('(');
				  oputb(*(fptr++)); 
				  oputb(')');
				  continue;
		case	FMT_ZCH	: oputb('*');
				  oputb('(');
				  oputb(*(fptr++)); 
				  oputb(')');
				  continue;
		case	FMT_FIN	:
		default		: oputb(')'); xtrl = 1; continue;
		}
	oputb( x ); 

	x = (EXAWORD) *(fptr++);
	
	if (( x != 1 ) || ( y & 0x0020 )) {
		DecimalWord( x );
		}
	}
while ( xtrl == 0 );
return(fmtret);

}

#endif


/*	Displays a Global Variable Name		*/
/* 	-------------------------------		*/ 
void	GlobalName( variable )
EXAWORD	variable;
{
	EXAWORD	nombre;
	EXAWORD	compte;
	BPTR	nptr;
	BPTR	get_global_name( EXAWORD );

	if ( trad_ver > '1' ) {
		/* ABAL TCODE VERSION 2 */
		/* -------------------- */
		if (((nptr = get_global_name( variable )) != (BPTR) 0) 
		&&  ( *nptr != '{' )) {
			oputs( nptr );
#ifndef	VISUAL_DEBUGER
			if ( Options.Liste == 'l' ) {
#endif
				oputb(':');
				HexWord(variable);
#ifndef	VISUAL_DEBUGER
				}
#endif
			return;
			}			
		else 	{
			oputs( "GV" );
			HexWord(variable);
			return;
			}
		}
#ifndef	VISUAL_DEBUGER
	else	{

		/* ABAL TCODE VERSION 1 */
		/* -------------------- */
		if ( tcGNT != (BPTR) 0) {
			nptr = tcGNT;
			if ( tcGDT != (BPTR) 0 ) {
				nombre = tcGetw( tcGDT );
				for (compte = 0; compte < nombre; compte++ ) {
					if ( variable == (tcGetw(( nptr + 8 ))) ) {
						for ( compte = 0; compte < 8; compte++ ) {
							if ( *nptr == ' ' ) { return; }
							else	{
								oputb ( *(nptr++) );
								}
							}
						return;
						}
					nptr += 10;
					}
				}		
			}

		HexWord(variable);
		return;
		}
#endif
}

/*	Displays a Local  Variable Name		*/
/* 	-------------------------------		*/ 
void	LocalName( variable )
EXAWORD	variable;
{
	EXAWORD	nombre;
	EXAWORD	compte;
	BPTR	nptr;
	BPTR	get_local_name( EXAWORD );

	if ( trad_ver > '1' ) {
		/* ABAL TCODE VERSION 2 */
		/* -------------------- */
		if (((nptr = get_local_name( (variable & TOGLOBAL) )) != (BPTR) 0)
		&&   (*nptr != '{' )) {
			oputs( nptr );
#ifndef	VISUAL_DEBUGER
			if ( Options.Liste == 'l' ) {
#endif
				oputb(':');
				HexWord(variable);
#ifndef	VISUAL_DEBUGER
				}
#endif
			}
		else 	{
			oputs( "LV" );
			HexWord(variable);
			}
		return;
		}
#ifndef	ABALIDB
	else	{
		if ( tcLNT != (BPTR) 0) {
			nptr = tcLNT;
			if ( tcLDT != (BPTR) 0 ) {
				nombre = tcGetw( tcLDT );
				for (compte = 0; compte < nombre; compte++ ) {
					if ( (variable & TOGLOBAL) == (tcGetw(( nptr + 8 ))) ) {
						for ( compte = 0; compte < 8; compte++ ) {
							if ( *nptr == ' ' ) { return; }
							else	{
								oputb ( *(nptr++) );
								}
							}
						return;
						}
					else	{
						nptr += 10;
						}
					}
				}		
			}
		HexWord(variable);
		return;
		}
#endif
}

BPTR	get_variable_name( EXAWORD );
BPTR	get_local_name( EXAWORD );
BPTR	get_global_name( EXAWORD );

/* 	------------------------	*/ 
/*	Displays a Variable Name	*/
/* 	------------------------	*/ 
void	VariableName( variable , nptr , nombre, glflag )
EXAWORD	variable;
BPTR	nptr;
EXAWORD	nombre;
EXAWORD	glflag;
{
	EXAWORD	compte;

	if ( trad_ver > '1' ) 
	{
		/* ABAL TCODE VERSION 2 */
		/* -------------------- */
		if ( glflag )
			nptr = get_local_name( (variable  & TOGLOBAL) );
		else	nptr = get_global_name( (variable & TOGLOBAL) );
		if ( nptr != (BPTR) 0) 
		{
			oputs( nptr );
#ifndef	VISUAL_DEBUGER
			if ( Options.Liste == 'l' ) 
			{
#endif
				oputb(':');
				HexWord(variable);
#ifndef	VISUAL_DEBUGER
			}
#endif
		}
		else	
		{
			VarbName(variable | ( glflag ? ISLOCAL : 0 ));
		}
		return;
	}
	else	
	{
		/* ABAL TCODE VERSION 1 */
		/* -------------------- */
		if ( nptr != (BPTR) 0 ) 
		{
			for (compte = 0; compte < nombre; compte++ ) 
			{
				if ( (variable & TOGLOBAL) == (tcGetw(( nptr + 8 ))) ) 
				{
					for ( compte = 0; compte < 8; compte++ ) 
					{
						if ( *nptr == ' ' ) { return; }
						else	
						{
							oputb ( *(nptr++) );
						}
					}
					return;
				}
				else	nptr += 10;
			}
		}
		HexWord(variable);
		return;
	}
}

/*	Displays a Variable TOKEN	*/
/*	-------------------------	*/
void	VarbName( varbid )
EXAWORD	varbid;
{
	if ((varbid & ISLOCAL) != 0) {
		LocalName( varbid & TOGLOBAL );
		}
	else	{
		GlobalName( varbid );
		}
	return;
}

void	AffVarb( varbid )
EXAWORD	varbid;
{
#ifndef	VISUAL_DEBUGER
	if ( Options.Liste == 'l' )
#endif
		oputb('[');
	VarbName( varbid );
#ifndef	VISUAL_DEBUGER
	if ( Options.Liste == 'l' )
#endif
		oputb(']');
	return;
}

void	DumpConstantTable( cptr, clen )
BPTR	cptr;
EXAWORD	clen;
{
	EXAWORD	consid=0;
	EXAWORD	l;
	EXAWORD	x;
	EXAWORD	y;
	BPTR	tcXKT;
	BYTE	muffer[16];

	if ((!( cptr )) || (!( clen )))
		return;

	oline();
	oputs("GlobalConstantTable");
	oline();

	while ( consid < clen ) {

		oputs("Const ");

		HexWord(consid);

		if ((x = (EXAWORD) *(cptr + consid)) != 0 ) {
			/* Display String Constant */
			/* ----------------------- */
			oputb('$');
			oputb('=');
			DecimalWord(x);
			oputb(' ');
			oputb('"');
			while ( x > 0 ) {
				consid++;
				if ( *(cptr + consid) >= ' ' ) {
					oputb( *(cptr + consid) );
					}
				else	{
					sprintf(muffer,"%u",(*(cptr + consid) & 0x00FF));
					oputb( '&' ); oputb( '&' );
					for (l=strlen(muffer); l < 3; l++ )
						oputb( '0' );
					for ( l=0; muffer[l] != 0; l++ )
						oputb( muffer[l] );
					}
				x--;
				}
			oputb('"');
			}
		else	{ 
			/* Display Bcd Constant */
			/* -------------------- */
			consid++;

			x = (EXAWORD) *(cptr + consid);
			oputb('*');
			oputb('=');
			DecimalWord(x);
			oputb(' ');

			while ( x > 0 ) {
				consid++;
				HexaOctet( *(cptr + consid) );
				x--;
				}
			}
		consid++;
		oline();
		}
	oline();
	return;
}

void	AffCons( consid )
EXAWORD	consid;
{
	EXAWORD	l;
	EXAWORD	x;
	EXAWORD	y;
	BPTR	tcXKT;
	BYTE	muffer[16];
	EXAWORD	konsid;

	if ((tcXKT = tcLCT) == (BPTR) 0)
		tcXKT = tcGKT;
	
#ifndef	VISUAL_DEBUGER
	if ( Options.Alliance )
		konsid = 0;
	else	konsid = consid;
#else	
	konsid = consid;
#endif
#ifndef	VISUAL_DEBUGER
	if ( Options.Liste == 'l' ){
#endif
		HexWord(konsid);
		oputb('-');
		oputb('>');
#ifndef	VISUAL_DEBUGER
		}
#endif
	while ( 1 ) {

		if ((x = (EXAWORD) *(tcXKT + consid)) != 0 ) {
			/* Display String Constant */
			/* ----------------------- */
			oputb('"');
			while ( x > 0 ) {
				consid++;
				if ( *(tcXKT + consid) >= ' ' ) {
					oputb( *(tcXKT + consid) );
					}
				else	{
					sprintf(muffer,"%u",(*(tcXKT + consid) & 0x00FF));
					oputb( '&' ); oputb( '&' );
					for (l=strlen(muffer); l < 3; l++ )
						oputb( '0' );
					for ( l=0; muffer[l] != 0; l++ )
						oputb( muffer[l] );
					}
				x--;
				}
			oputb('"');
			break;
			}
		else	{ 
			/* Display Bcd Constant */
			/* -------------------- */
			consid++;
			x = (EXAWORD) *(tcXKT + consid);
			/* Check for Redirected to Global Table */
			/* ------------------------------------ */
			if ( x & 0x0080 ) {
				consid = tcGetw( (tcXKT + consid + 1) );
				HexWord( consid );
				oputb('-');
				oputb('>');
				tcXKT = tcGKT;
				continue;
				}
			else	{
				while ( x > 0 ) {
					consid++;
					HexaOctet( *(tcXKT + consid) );
					x--;
					}
				break;
				}
			}
		}
	return;
}

void	AffEtt( ettid )
EXAWORD	ettid;
{
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if ( Options.Alliance )
		ettid = 0;
#endif
#endif
	oputb('&');
	oputb('L');
	HexWord(ettid);
	return;
}

void	AffProc( prcid )
EXAWORD	prcid;
{
	EXAWORD	offset;
	EXAWORD	value;
	EXAWORD	limite;
	EXAWORD	nombre;
	BYTE	ProcName[64];
	BPTR	get_procedure_name( EXAWORD );
	BPTR	nptr;

	if ( trad_ver > '1' ) {

		/* ABAL TCODE VERSION 2 */
		/* -------------------- */
		if ((nptr = get_procedure_name( prcid )) != (BPTR) 0) {
			oputs( nptr );
#ifndef	VISUAL_DEBUGER
			if ( Options.Liste == 'l' ) {
#endif
				oputs(":");
				HexWord(prcid);
#ifndef	VISUAL_DEBUGER
				}
#endif
			return;
			}
		else	{
			oputs("PRC");
			HexWord(prcid);
			return;
			}
		}
#ifndef	VISUAL_DEBUGER
	else	{

		/* ABAL TCODE VERSION 1 */
		/* -------------------- */
		if ( tcPNT != (BPTR) 0 ) {

			limite = tcGetw((tcPNT));	

			/* Attempt to find a Procedure Name */
			/* -------------------------------- */
			for (offset = 2, nombre = 0;nombre < limite; nombre++ ) {

				value = tcGetw((tcPNT + offset + 8));
	
				if ( value == prcid ) {

					/* Found it so Display It */
					/* ---------------------- */
					memcpy((BPTR) ProcName, (tcPNT + offset), 8);
					ProcName[8] = ' '; ProcName[9] = 0; 
					oputs( ProcName );
					return;

					}

				/* Calculate Next Entry */
				/* -------------------- */
				offset += 10;
				value = tcGetw((tcPNT + offset));
				offset += 2;
				offset += value;

				}
			}
		}
#endif
	HexWord(prcid);
}

void	Comment( comment )
EXAWORD	comment;
{
	if ( comment != 0 ) 
		oputs(";** ");
	if ( comment & 0x8000 )
		oputs(" (REDUNDANT) ");
	if ( comment & 0x4000 )
		oputs(" (RECOVERY)  ");

	return;
}

/*	FORMAT strings implemented for PRINT LABELS 	*/
/*	-------------------------------------------	*/

void	LabelFormat( sptr , si , comment )
BPTR	sptr;
EXAWORD	si;
EXAWORD	comment;
{
	Comment(comment); AffEtt( si ); oputs(" FMT");
	fmtoa( (sptr + si) ); oline();
	return;

}

EXAWORD	DefineField( dptr , voffs )
BPTR	dptr;
EXAWORD	voffs;
{
	EXAWORD	ti;
	EXAWORD	vtype;
	EXAWORD	compte;
	EXAWORD	thisvarb;
	EXAWORD	lastvarb;

	/* Collect variable count value */
	/* ---------------------------- */
	compte  = tcGetw( dptr ); ti = (3*WORDSIZE); lastvarb = (3*WORDSIZE);

	while ( compte > 0 ) {

		thisvarb = ti;

		/* Collect Variable type */
		/* --------------------- */
		vtype = tcGetw( (dptr + ti) ); ti += WORDSIZE;

		/* Avoid translator Holes */
		/* ---------------------- */
		if (( vtype & 0x0010 ) == 0 ) {

			if (( vtype & 0xFF00 ) == 0 ) {
				if ( (tcGetw((dptr + ti))) == voffs ) {
					return( thisvarb );
					}
				if ( (tcGetw((dptr + ti))) > voffs ) {
					return( lastvarb );
					}
				ti += WORDSIZE;
				}
			else	{
				ti += (2*WORDSIZE);
				}

			if ((vtype & 0x0003) > 1 ) {
				ti += WORDSIZE;
				}
			if ((vtype & 0x0040) != 0) {
				ti += WORDSIZE;
				if ((vtype & 0x0020) != 0) {
					ti += WORDSIZE;
					}
				}
			/* Decrement variable Counter */
			/* -------------------------- */
			compte--;
			lastvarb = thisvarb;
			}
		}
	return(0);
}


EXAWORD	generate_memory_field( type, current, base, flag )
EXAWORD	type;
EXAWORD	current;
EXAWORD	base;
EXAWORD	flag;
{
	EXAWORD	newfield;
	EXAWORD	isptr=0;

	switch ((newfield = (type & 0xFF00))) {
		case	0x9000	: /* First level pointer */
			newfield = 0;
		case	0	:
		case	0x4000	:
			break;
			
		case	0xA000	: /* Member of pointer	 */
		case	0xB000	: /* pointer of pointer	 */
			newfield = (base & TOGLOBAL);
			isptr    = 1;
			break;
		}

	/* Test for Field Change */
	/* --------------------- */
	if ( newfield != current ) {
		oputs( "FIELD=" );
		if ( isptr ) 
			AffVarb( (newfield | (flag ? ISLOCAL : 0)) );
		else if ( newfield & 0x4000 )
			oputb( 'E' );
		else if ( newfield & 0x3F00 )
			DecimalWord( ((newfield & 0x3F00) >> 8) ); 
		else    oputb( 'M' );
		oline();
		}

	return( newfield );
}

static	EXAWORD	DataVariable( dptr, ti, glflag, comment, nptr, nombre )
BPTR 	dptr;
EXAWORD ti;
EXAWORD	glflag;
EXAWORD	comment;
BPTR	nptr;
EXAWORD	nombre;
{
	EXAWORD	v;
	EXAWORD	vi;
	EXAWORD	type;
	EXAWORD	l,i,a;
	EXAWORD	field;
	EXAWORD	fieldi;
	EXAWORD	fieldl;
	EXAWORD	rdpv;

	/* Duplicate Variable Identity */
	/* --------------------------- */
	vi = ti;

	/* Collect Variable Type */
	/* --------------------- */
	type   = tcGetw((dptr + ti)); ti += WORDSIZE;

	/* Check for not a Translator Hole */
	/* ------------------------------- */
	if (( type & 0x0010 ) == 0 ) 
	{

		/* Collect Field Indent offset */
		/* --------------------------- */
		fieldi = tcGetw((dptr + ti)); ti += WORDSIZE;
	
		/* Allow field management intervantion */
		/* ----------------------------------- */
		field = generate_memory_field(type, field, fieldi, glflag );

		/* Check for Dynamic element */
		/* ------------------------- */
		if (( type & ISDYNAMIC )

		/* Check for Redefinition of Dynamic element */
		/* ----------------------------------------- */
		&&  ( type & ISMEMBER )) 
		{

			/* Collect Field Indent offset */
			/* --------------------------- */
			fieldi = tcGetw((dptr + ti)); ti += WORDSIZE;
		}

		/* Check for and Avoid 32 bit Adressing */
		/* ------------------------------------ */
		if (((type & 0x7F00 ) != 0) && (!(type & ISDYNAMIC))) 
		{
			fieldl = tcGetw((dptr + ti));
			ti += WORDSIZE;
		}

		/* Identify possible ARG'S   */
		/* ------------------------- */
		Comment(comment);
		
		oputb('&');
		if (( type & 0x7F00 ) && (!(type & ISDYNAMIC))) 
		{
			HexWord( fieldl );
			HexWord( fieldi );
		}
		else	
		{
			HexWord( fieldi );
			oputs("    ");
		}
		switch ( (type & 0xF000) ) 
		{
		case ISDYNAMIC | ISPOINTER :
		case ISDYNAMIC | ISPOINTER | ISMEMBER :
			oputs(" PTR " );
			break;
		default	    :	
			if ((type & 0x0008) != 0) 
			{
				oputs(" ARG ");
			}
			else	
			{
				oputs(" DCL ");
			}
		}
		/* Display Variable identity */
		/* ------------------------- */
		VariableName( vi , nptr , nombre, glflag );

		/* Analyse variable type */
		/* --------------------- */
		switch ( (type & 0x0007) ) 
		{
			case 0 : oputb('#'); break;
			case 1 : oputb('%'); break;
			case 5 : oputb(':'); break;
			case 6 : oputb('&'); break;
			case 3 : oputb('$'); break;
		}

		/* Separate String variables */
		/* ------------------------- */
		switch ( type & 0x0007 )
		{
		case	0x0006	: l = 8; break;
		case	0x0005	: l = 4; break;
		case	0x0001	: l = 2; break;
		case	0x0000	: l = 1; break;
		default		:	
			oputb('=');
			DecimalWord( (l=(tcGetw((dptr + ti)))) );
			ti += WORDSIZE;
		}
		i = 1; a = 1;

		/* Check for Indexing */
		/* ------------------ */
		if (( type & 0x0040 ) != 0 ) 
		{
			oputb('(');
			DecimalWord( (i=(tcGetw((dptr + ti)))) );
			ti += WORDSIZE;

			/* Check for Additional indexing */
			/* ----------------------------- */
			if ((type & 0x0020 ) != 0 ) 
			{
				oputb(',');	
				DecimalWord( (a=(tcGetw((dptr + ti)))) );
				ti += WORDSIZE;
			} 
			oputb(')');
		}
		oline();
	}
	return(ti-vi);
}

/*	Displays a Data Table Structure		*/
/* 	-------------------------------		*/ 
void	DataTable( dptr ,comment , nptr, glflag )
BPTR	dptr;
EXAWORD	comment;
BPTR	nptr;
EXAWORD	glflag;
{
	EXAWORD	adjust;
	EXAWORD	compte;
	EXAWORD	ti,vi;
	EXAWORD	type;
	EXAWORD	nombre;
	EXAWORD	l,i,a;
	EXAWORD	field;
	EXAWORD	fieldi;
	EXAWORD	fieldl;
	EXAWORD	rdpv;

	/* Collect variable count value */
	/* ---------------------------- */
	compte  = tcGetw( dptr ); ti = (3*WORDSIZE);

	nombre  = compte; 

	/* Establish UnKnown Field */
	/* ----------------------- */
	field = MOINS_UN;

	/* While more variables to be analysed */
	/* ----------------------------------- */
	while ( compte > 0 ) {
		if ((adjust = DataVariable( dptr, ti, glflag, comment, nptr, nombre )) > WORDSIZE)
			compte--;
		ti += adjust;
		}
;

	return;
}


void	ProgStart( comment , xHeap , xFile , xTemp , xPile )
EXAWORD	comment;
EXAWORD	xHeap;
EXAWORD	xFile;
EXAWORD	xTemp;
EXAWORD	xPile;
{
	EXAWORD	x;

	oline();
	Comment(comment);
	switch ( ControlZone[19] ) {
		case 0 : 
		case 2 : 	oputs("PROGRAM ");
				break;
		case 1 : 
		case 3 : 	oputs("MODULE ");
				break;
		}

	oputb('"');
	for ( x= 0; x < 15; x++) oputb(ControlZone[(x+3)]);
	oputb('"');
	if ( ControlZone[18] & 0x00C0 )
		oputs("  POST OPTIMISED ");
	oline();
	oputs("#LOCAL "); DecimalWord( xHeap ); oline();
	oputs("#FILES "); DecimalWord( xFile ); oline();
	oputs("#MEM   "); DecimalWord( xTemp ); oline();
	oputs("#STACK "); DecimalWord( xPile ); oline();

	return;
}

void	ProgEnd( comment )
EXAWORD	comment;
{
	Comment(comment);
	oputs("END ");
	oline();
	return;
}

#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
void	raz_stats()
{
	memset((BPTR) _tc_stat,  0, (256*WORDSIZE) );
	memset((BPTR) _esc_stat, 0, (256*WORDSIZE) );
	memset((BPTR) _clf_stat, 0, (256*WORDSIZE) );
	memset((BPTR) _io_stat,  0, (16 *WORDSIZE) );
	memset((BPTR) _ngf_stat, 0, (64 *WORDSIZE) );
	return;

}
#endif
#endif

void	SegmentStart( segid , comment )
EXAWORD	segid;
EXAWORD	comment;
{
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if ( Options.Stats & STAT_CODE )
		raz_stats();
#endif
#endif
	oline();
	Comment(comment); 
	if ( statix & 1 )
		oputs("RESIDENT ");
	oputs("SEGMENT "); DecimalWord( segid ); oline();
	if (tcLDT != (BPTR) 0) {
		if ( statix & 2 ) {
			oputs("STATIC"); oline();
			}
		DataTable( tcLDT ,comment , tcLNT, 1 );
		Comment(comment); oputs("ENDLOC "); oline();
		}
}

void	SegmentEnd( segid , comment )
EXAWORD	segid;
EXAWORD	comment;
{
	Comment(comment); oputs("ESEG "); DecimalWord( segid ); oline();
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		flush_stats();
#endif
#endif
	return;
}

void	ProcedureStart( prcid , comment )
EXAWORD	prcid;
EXAWORD	comment;
{
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if ( Options.Stats & STAT_CODE )
		raz_stats();
#endif
#endif
	oline();
	Comment(comment); oputs("PROC "); AffProc( prcid ); oputs("( ... )");
	oline();
	if (tcLDT != (BPTR) 0) {
		if ( statix & 2 ) {
			oputs("STATIC"); oline();
			}
		DataTable( tcLDT ,comment , tcLNT, 1 );
		oputs("ENDLOC "); oline();
		}
}

void	ProcedureEnd( prcid , comment )
EXAWORD	prcid;
EXAWORD	comment;
{
	Comment( comment ); oputs("ENDPROC "); oline();
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		flush_stats();
#endif
#endif
	return;
}

void	IoMnemonic( tcode ) 
EXAWORD	tcode;
{
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_io_stat[ tcode ]++;
#endif
#endif
	oputs( "      " );
	oputs( &_io_mnem[ tcode ][0] );
	oputb(' ');
	return;
}

void	Mnemonic( tcode )
EXAWORD	tcode;
{
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_tc_stat[ tcode ]++;
#endif
#endif
	oputs( & _tc_mnem[ tcode ][0] );
	oputb(' ');
	return;
}


void	EscMnemonic( tcode )
EXAWORD	tcode;
{
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_esc_stat[ tcode ]++;
#endif
#endif
	oputs( & _esc_mnem[ tcode ][0] );
	oputb(' ');
	return;
}

/* Display operation arguaments */
/* ---------------------------- */
EXAWORD	ArgMnemonic( cptr , si )
BPTR	cptr;
EXAWORD	si;
{

	switch ((((EXAWORD) *(cptr + si)) & 0x00F0)) {
		case 0x0000 : 	HexWord( (tcGetw((cptr + si + 1))) ); 
				si += (WORDSIZE+1); break;
		case 0x0020 :	AffCons( (tcGetw((cptr + si + 1))) );
				si += (WORDSIZE+1); break;
		case 0x0040 :	AffVarb( (tcGetw((cptr + si + 1))) );
				si += (WORDSIZE+1); break;
		case 0x0060 : 	AffReg( *(cptr + si + 1) ); 
				si += (2*1); break;
		case 0x0080 :	si++;
				oputb('"');
				while ( *(cptr + si) != (BYTE) 0 ) {
					oputb( *(cptr + si) );
					si++;
					}
				oputb('"');
				si++;
		}
	return( si );

}

/* Display operation arguaments */
/* ---------------------------- */
EXAWORD	ConsumeArgMnemonic( cptr , si )
BPTR	cptr;
EXAWORD	si;
{

	switch ((((EXAWORD) *(cptr + si)) & 0x00F0)) {
		case 0x0000 : 	si += (WORDSIZE+1); break;
		case 0x0020 :	si += (WORDSIZE+1); break;
		case 0x0040 :	si += (WORDSIZE+1); break;
		case 0x0060 : 	si += (2*1); break;
		case 0x0080 :	si++;
				while ( *(cptr + si) != (BYTE) 0 ) {
					si++;
					}
				si++;
		}
	return( si );

}

	EXAWORD	ClfProcPtr=0;
static	EXAWORD	ArgMask=0;
static	EXAWORD	ArgBuffer=0;
static	EXAWORD	ArgLength=0;

static	EXAWORD	LastArg=0;
static	EXAWORD	LastInt=0;
static	EXAWORD	LastCon=0;
static	EXAWORD	LastVar=0;
static	EXAWORD	LastReg=0;

BPTR	Arguaments(argt , aptr, amax )
EXAWORD	argt;
BPTR	aptr;
EXAWORD amax;
{
	EXAWORD	Mode;
	EXAWORD	v;

	if ( argt > amax ) 
	{
		argt &= 0x0003;
		Mode = 1;
	}
	else	
	{
		Mode = 0;
	}

	switch ((LastArg = argt)) 
	{
		case 0x0000 : 	

			if ( ClfProcPtr ) 
			{
				ClfProcPtr = 0;
				AffProc( (tcGetw((aptr))) );
				oputb(':');
				HexWord( (tcGetw((aptr))) ); 
				aptr += WORDSIZE;
			}
			else	
			{
				LastInt = (tcGetw((aptr)));
				HexWord( LastInt );
				aptr += WORDSIZE; 
				if ( ArgMask == 8 )
					ArgLength = LastInt;
			}
			break;

		case 0x0001 :
			LastCon	= (tcGetw((aptr)));
			AffCons( LastCon );
			aptr += WORDSIZE; 
			break;

		case 0x0002 :	
			LastVar = (tcGetw((aptr)));
			AffVarb( LastVar );
			aptr += WORDSIZE; 
			if ( ArgMask == 4 )
				ArgBuffer = LastVar;
			break;

		case 0x0003 : 	
			LastReg = *(aptr++);
			AffReg( LastReg );
			break;

		case 0x0004 :	

			oputb('"');
			while ( *(aptr) != (BYTE) 0 ) 
			{
				oputb( *(aptr++) );
			}
			oputb('"');
			aptr++;
	}

	/* Check for DL return value */
	/* ------------------------- */
	if ( Mode != 0 ) { oputs(" ? "); }

	return( aptr );
}

/*	----------	*/
/*	ProcSyntax	*/
/*	----------	*/
EXAWORD	ProcSyntax( cptr ,si )
BPTR	cptr;
EXAWORD	si;
{
	BPTR	vptr;
	EXAWORD	phase;
	EXAWORD	argflag;
	BPTR	dptr;

	ArgMask = 0;

	dptr = (cptr + si);

	/* Position to Values */
	/* ------------------ */
	vptr = (BPTR) (cptr + si); while ( *(vptr++) & 1 );

	/* Affichage Procedure ID */
	/* ---------------------- */
	switch (( *(cptr +si) & 0x0060 )) 
	{
	case 0x0040 : AffVarb( tcGetw((vptr)) ); vptr += WORDSIZE; break;
	case 0x0000 : AffProc( tcGetw((vptr)) ); vptr += WORDSIZE; break;
	case 0x0060 : AffReg( *(vptr++) ); break;
	}

	phase = 5;
	oputb('(');

	/* Display Function Arguaments */
	/* --------------------------- */
	argflag = 0;
	while ( 1 ) 
	{
		if ( phase == 1 ) 
		{
			if ( *(cptr + si) & 1 ) 
			{
			si++;
			phase = 5;
			}
			else	
			{
				break;
			}
		}
		else	
		{
			if ( *(cptr + si) & 0x0010 ) 
			{
				phase = 1;
			}
			else	
			{
				break;
			}
		}
		if ( argflag == 0 ) 
		{
			argflag = 1;
		}
		else	
		{
			oputb(',');
		}
		vptr = Arguaments( ( (*(cptr + si) & (0x000E << (phase -1))) >> phase), vptr, 3 );

	}
	/* Close function brackets and Return */
	/* ---------------------------------- */
	oputb(')');
	return((EXAWORD) (vptr - dptr));

}

/*	---------	*/
/*	EscSyntax	*/
/*	---------	*/
EXAWORD	EscSyntax( cptr , si )
BPTR	cptr;
EXAWORD	si;
{
	EXAWORD	y;
	EXAWORD	x;
	EXAWORD	i;
	EXAWORD	di;
	EXAWORD	dd;

	di = si;

#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_esc_stat[ *(cptr + si + 1) ]++;
#endif
	switch ( *(cptr + si + 1) ) 
	{
	case _esc_GEC	:
		oputs("GEC ");
		AffVarb((tcGetw((cptr + si + 2))));
		oputs(", ");
		AffProc((tcGetw((cptr + si + 2 + WORDSIZE))));
		si += (2+(2 * WORDSIZE));
		break;

	case _esc_LEC	:
		oputs("LEC ");
		AffVarb((tcGetw((cptr + si + 2))));
		oputs(", ");
		AffProc((tcGetw((cptr + si + 2 + WORDSIZE))));
		si += (2+(2 * WORDSIZE));
		break;

	case _esc_SPN :
		dd = *(cptr + si + 2); i = 0;
		switch ( dd ) 
		{
		case 0x0000 : 	
			i = WORDSIZE;
			HexWord((tcGetw((cptr + si + 3 +WORDSIZE))));
 			break;
		case 0x0020 : 	
			i = WORDSIZE;
			AffCons((tcGetw((cptr + si + 3 + WORDSIZE))));
			break;
		case 0x0040 : 	
			i = WORDSIZE;
			AffVarb((tcGetw((cptr + si + 3 + WORDSIZE))));
			break;
		case 0x0060 : 	
			i = 1;
			AffReg( *(cptr + si + 3 + WORDSIZE) );
		}
		oputs(" = SPAWN ");
		AffEtt ( (tcGetw((cptr + si + 3 )) ) );
		si += ( i + (2 + WORDSIZE) );
		break;

	case _esc_LIB :
		oputs("KILL ");
		dd = *(cptr + si + 2); i = 0;
		switch ( dd ) 
		{
		case 0x0000 : 	
			i = WORDSIZE;
			HexWord((tcGetw((cptr + si + 3))));
 			break;
		case 0x0020 : 	
			i = WORDSIZE;
			AffCons((tcGetw((cptr + si + 3))));
			break;
		case 0x0040 : 	
			i = WORDSIZE;
			AffVarb((tcGetw((cptr + si + 3))));
			break;
		case 0x0060 : 	
			i = 1;
			AffReg( *(cptr + si + 3) );
		}
		si += ( i + 2 );
		break;
	case _esc_SGR :
		oputs("SGR ");
		AffReg( *(cptr + si + 2) );
		si += 3;
		break;
	case _esc_SGI :
		oputs("SGI ");
		HexaOctet( *(cptr + si + 2) );
		si += 3;
		break;
	case _esc_SGV :
		oputs("SGV ");
		AffVarb((tcGetw((cptr + si + 2))));
		si += (2+WORDSIZE);
		break;
	case _esc_SGW :
		oputs("SGW ");
		HexWord((tcGetw((cptr + si + 2))));
		si += (2+WORDSIZE);
		break;
	case _esc_RGT :
		oputs("RGT ");
		AffReg( *(cptr + si +2));
		si += 3;
		break;
	case _esc_RGS :
		oputs("RGS ");
		AffReg( *(cptr + si +2));
		si += 3;
		break;
	case _esc_JMT :
		oputs("JMT ");
		AffReg( *(cptr + si + 2) ); oputb(' ');
		x = tcGetw((cptr + si + 3));
		y = 0;
		i = WORDSIZE;
		while ( x > 0 ) 
		{
			x--;
			AffEtt ( (tcGetw((cptr + si + 3 + i)) ) );
			i += WORDSIZE;
			if ( x > 0 ) { oputb(','); }
			if ( y > 15 ) 
			{
				oline();
				y = 0;
				}
			else	y++;
			}
		si += (i + 3);
		break;
	case _esc_GST :
		oputs("GST ");
		AffReg( *(cptr + si + 2) ); oputb(' ');
		x = tcGetw((cptr + si + 3));
		y = 0;
		i = WORDSIZE;
		while ( x > 0 ) 
		{
			x--;
			AffEtt ( (tcGetw((cptr + si + 3 + i)) ) );
			i += WORDSIZE;
			if ( x > 0 )  { oputb(','); }
			if ( y > 15 ) 
			{
				oline();
				y = 0;
				}
			else	y++;
			}
		si += (i + 3);
		break;
	case _esc_PSI :
		oputs("PSI ");
		HexWord((tcGetw((cptr + si + 2))));
		si += (2+WORDSIZE);
		break;
	case _esc_PSC :
		oputs("PSC ");
		AffCons((tcGetw((cptr + si + 2))));
		si += (2+WORDSIZE);
		break;
	case _esc_PSV :
		oputs("PSV ");
		AffVarb((tcGetw((cptr + si + 2))));
		si += (2+WORDSIZE);
		break;
	case _esc_PSR :
		oputs("PSR ");
		AffReg( *(cptr + si + 2) );
		si += 3;
		break;
	case _esc_ETS :
		oputs("ETS ");
		si += 2;
		break;
	case _esc_RTS :
		oputs("RTS ");
		si += 2;
		break;
	case _esc_RTP :
		oputs("RTP ");
		si += 2;
		break;
	case _esc_ETP :
		oputs("ETP ");
		si += 2;
		break;
	case _esc_STP :
		oputs("STP ");
		si += 2;
		break;
	case _esc_RTI :
		oputs("RTI ");
		HexWord((tcGetw((cptr + si + 2))));
		si += (2+WORDSIZE);
		break;
	case _esc_RTV :
		oputs("RTV ");
		AffVarb((tcGetw((cptr + si + 2))));
		si += (2+WORDSIZE);
		break;
	case _esc_RTR :
		oputs("RTR ");
		AffReg( *(cptr + si + 2) );
		si += 3;
		break;
	case _esc_CLP :
		oputs("CLP ");
		return((ProcSyntax( cptr , (si + 2) ) + 2));
	case _esc_FMT : 
		oputs("FMT ");
		si+= 2;
		si+= *(cptr + si);			
		break;
	case	_esc_SGL	:
		oputs("SGL ");
		HexWord((tcGetw((cptr + si + 2)))); 
		oputs(", offset ");
		HexWord((tcGetw((cptr + si + 2 + WORDSIZE))));
		si += ((2*WORDSIZE)+1); 
		break;
	case	_esc_SLL	:
		oputs("SGL ");
		HexWord((tcGetw((cptr + si + 2)))); 
		oputs(", offset ");
		HexWord((tcGetw((cptr + si + 2 + WORDSIZE))));
		si += ((2*WORDSIZE)+1); 
		break;
	case	_esc_GLS	:
		oputs("GLS ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
		break;
	case	_esc_LLS	:
		oputs("LLS ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
		break;
	case	_esc_GLL	:
		oputs("GLL ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
		break;
	case	_esc_LLL	:
		oputs("LLL ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
		break;
	case	_esc_SGH	:
		oputs("SGH ");
		HexWord((tcGetw((cptr + si + 2)))); 
		oputs(", offset ");
		HexWord((tcGetw((cptr + si + 2 + WORDSIZE))));
		si += ((2*WORDSIZE)+1); 
		break;
	case	_esc_SLH	:
		oputs("SGH ");
		HexWord((tcGetw((cptr + si + 2)))); 
		oputs(", offset ");
		HexWord((tcGetw((cptr + si + 2 + WORDSIZE))));
		si += ((2*WORDSIZE)+1); 
		break;
	case	_esc_GHS	:
		oputs("GHS ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
		break;
	case	_esc_LHS	:
		oputs("LHS ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
		break;
	case	_esc_GHL	:
		oputs("GHL ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
		break;
	case	_esc_LHL	:
		oputs("LHL ");
		AffReg ( *(cptr + si + 2) ); oputs(", offset ");
		HexWord((tcGetw((cptr + si + 3))));
		si += (3+WORDSIZE); 
	}
	return((si-di));
}

EXAWORD	EscAnalysis( cptr , si , comment )
BPTR	cptr;
EXAWORD	si;
EXAWORD	comment;
{
	EXAWORD	y;
	EXAWORD	x;
	EXAWORD	i;
	EXAWORD	di;
	EXAWORD	dd;

	di = si;

#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_esc_stat[ *(cptr + si + 1) ]++;
#endif
	switch ( *(cptr + si + 1) ) {
		case _esc_SPN :
			dd = *(cptr + si + 2); i = 0;
			switch ( dd ) {
				case 0x0000 : 	i = WORDSIZE;
						HexWord((tcGetw((cptr + si + 3 +WORDSIZE))));
 						break;
				case 0x0020 : 	i = WORDSIZE;
						AffCons((tcGetw((cptr + si + 3 + WORDSIZE))));
						break;
				case 0x0040 : 	i = WORDSIZE;
						AffVarb((tcGetw((cptr + si + 3 + WORDSIZE))));
						break;
				case 0x0060 : 	i = 1;
						AffReg( *(cptr + si + 3 + WORDSIZE) );
				}
			oputs(" = SPAWN ");
			AffEtt ( (tcGetw((cptr + si + 3 )) ) );
			si += ( i + (2 + WORDSIZE) );
			break;

		case _esc_LIB :
			oputs("KILL ");
			dd = *(cptr + si + 2); i = 0;
			switch ( dd ) {
				case 0x0000 : 	i = WORDSIZE;
						HexWord((tcGetw((cptr + si + 3))));
 						break;
				case 0x0020 : 	i = WORDSIZE;
						AffCons((tcGetw((cptr + si + 3))));
						break;
				case 0x0040 : 	i = WORDSIZE;
						AffVarb((tcGetw((cptr + si + 3))));
						break;
				case 0x0060 : 	i = 1;
						AffReg( *(cptr + si + 3) );
				}
			si += ( i + 2 );
			break;

		case _esc_SGR :
			oputs("LDGO.SEG ");
			AffReg( *(cptr + si + 2) );
			si += 3;
			break;

		case _esc_SGI :
			oputs("LDGO.SEG ");
			HexaOctet( *(cptr + si + 2) );
			si += 3;
			break;

		case _esc_SGV :
			oputs("LDGO.SEG ");
			AffVarb((tcGetw((cptr + si + 2))));
			si += (2+WORDSIZE);
			break;

		case _esc_SGW :
			oputs("LDGO.SEG ");
			HexWord((tcGetw((cptr + si + 2))));
			si += (2+WORDSIZE);
			break;
		
		case _esc_RGT :
			oputs("RGT ");
			AffReg( *(cptr + si +2));
			si += 3;
			break;

		case _esc_RGS :
			oputs("RGS ");
			AffReg( *(cptr + si +2));
			si += 3;
			break;

		case _esc_JMT :
			oputs("JMT ");
			AffReg( *(cptr + si + 2) ); oputb(' ');
			x = tcGetw((cptr + si + 3));
			y = 0;
			i = WORDSIZE;
			while ( x > 0 ) {
				x--;
				AffEtt ( (tcGetw((cptr + si + 3 + i)) ) );
				i += WORDSIZE;
				if ( x > 0 ) { oputb(','); }
				if ( y > 15 ) {
					oline();
					y = 0;
					}
				else	y++;
				}
			si += (i + 3);
			break;

		case _esc_GST :
			oputs("GST ");
			AffReg( *(cptr + si + 2) ); oputb(' ');
			x = tcGetw((cptr + si + 3));
			y = 0;
			i = WORDSIZE;
			while ( x > 0 ) {
				x--;
				AffEtt ( (tcGetw((cptr + si + 3 + i)) ) );
				i += WORDSIZE;
				if ( x > 0 )  { oputb(','); }
				if ( y > 15 ) {
					oline();
					y = 0;
					}
				else	y++;
				}
			si += (i + 3);
			break;

		case _esc_PSI :
			oputs("PAUSE ");
			HexWord((tcGetw((cptr + si + 2))));
			si += (2+WORDSIZE);
			break;

		case _esc_PSC :
			oputs("PAUSE ");
			AffCons((tcGetw((cptr + si + 2))));
			si += (2+WORDSIZE);
			break;

		case _esc_PSV :
			oputs("PAUSE ");
			AffVarb((tcGetw((cptr + si + 2))));
			si += (2+WORDSIZE);
			break;

		case _esc_PSR :
			oputs("PAUSE ");
			AffReg( *(cptr + si + 2) );
			si += 3;
			break;

		case _esc_ETS :
			oputs("END.SEG ");
			si += 2;
			break;

		case _esc_RTS :
			oputs("RET.SEG ");
			si += 2;
			break;

		case _esc_RTP :
			oputs("EXIT ");
			si += 2;
			break;

		case _esc_ETP :
			oputs("END.PROC ");
			si += 2;
			break;

		case _esc_STP :
			oputs("STOP ");
			si += 2;
			break;

		case _esc_RTI :
			oputs("RTI ");
			HexWord((tcGetw((cptr + si + 2))));
			si += (2+WORDSIZE);
			break;

		case _esc_RTV :
			oputs("RTV ");
			AffVarb((tcGetw((cptr + si + 2))));
			si += (2+WORDSIZE);
			break;

		case _esc_RTR :
			oputs("RTR ");
			AffReg( *(cptr + si + 2) );
			si += 3;
			break;

		case _esc_CLP :
			oputs("CALL ");
			return((ProcSyntax( cptr , (si + 2) ) + 2));

		case _esc_FMT : 
			oputs("FMT ");
			si+= 2;
			si+= *(cptr + si);			
			break;
		case	_esc_SGL	:
			oputs("SGL ");
			HexWord((tcGetw((cptr + si + 2)))); 
			oputs(", offset ");
			HexWord((tcGetw((cptr + si + 2 + WORDSIZE))));
			si += ((2*WORDSIZE)+1); 
			break;

		case	_esc_SLL	:
			oputs("SGL ");
			HexWord((tcGetw((cptr + si + 2)))); 
			oputs(", offset ");
			HexWord((tcGetw((cptr + si + 2 + WORDSIZE))));
			si += ((2*WORDSIZE)+1); 
			break;

		case	_esc_GLS	:
			oputs("GLS ");
			AffReg ( *(cptr + si + 2) ); oputs(", offset ");
			HexWord((tcGetw((cptr + si + 3))));
			si += (3+WORDSIZE); 
			break;
		case	_esc_LLS	:
			oputs("LLS ");
			AffReg ( *(cptr + si + 2) ); oputs(", offset ");
			HexWord((tcGetw((cptr + si + 3))));
			si += (3+WORDSIZE); 
			break;
		case	_esc_GLL	:
			oputs("GLL ");
			AffReg ( *(cptr + si + 2) ); oputs(", offset ");
			HexWord((tcGetw((cptr + si + 3))));
			si += (3+WORDSIZE); 
			break;
		case	_esc_LLL	:
			oputs("LLL ");
			AffReg ( *(cptr + si + 2) ); oputs(", offset ");
			HexWord((tcGetw((cptr + si + 3))));
			si += (3+WORDSIZE); 
			break;

		}
	return((si-di));
}

#include "aoclftc.c"

#ifdef	AO_STATS

void	flush_stats()
{
	EXAWORD	maintc;
	EXAWORD	subtc;
	EXAWORD	HoldStat;

	if ( !(Options.Liste) )
		StreamStatus(1);
	HoldStat = Options.Stats;	Options.Stats = FAUX;

	oline(); oputs("QUANTATIVE REPORT");
	oline();
	for ( maintc = 0; maintc < 128; maintc++ ) {

		if ( _tc_stat[maintc] == 0 )
			continue;

		oline();	oputs((BPTR) &_tc_mnem[ maintc ][0] );
				oputs((BPTR) "  : ");
				DecimalWord( _tc_stat[ maintc ] );

		switch ( maintc ) {

			case _tc_NGF :

				for ( subtc = 0; subtc < 40; subtc++ ) {

					if ( _ngf_stat[subtc] != 0 ) {

						oline();	oputs((BPTR) "        ");
								oputs((BPTR) &ngfmnem[ subtc ][0] );
								oputs((BPTR) "  : ");
								DecimalWord( _ngf_stat[ subtc ] );
						}
					}

				break;

			case _tc_ESC :

				for ( subtc = 0; subtc < 128; subtc++ ) {

					if ( _esc_stat[subtc] != 0 ) {

						oline();	oputs((BPTR) "        ");
								oputs((BPTR) &_esc_mnem[ subtc ][0] );
								oputs((BPTR) "  : ");
								DecimalWord( _esc_stat[ subtc ] );
						}
					}
				break;

			case _tc_CLF :

				for ( subtc = 0; subtc < 256; subtc++ ) {

					if ( _clf_stat[subtc] != 0 ) {

						oline();	oputs((BPTR) "        ");
								ClfMnemonic( subtc );
								oputs((BPTR) ")  : ");
								DecimalWord( _clf_stat[ subtc ] );
						}
					}

				break;

			case _tc_IOF :

				for ( subtc = 0; subtc < 16; subtc++ ) {

					if ( _io_stat[subtc] != 0 ) {

						oline();	oputs((BPTR) "        ");
								oputs((BPTR) &_io_mnem[ subtc ][0] );
								oputs((BPTR) "  : ");
								DecimalWord( _io_stat[ subtc ] );
						}
					}


			}		

		}

	oline();
	Options.Stats = HoldStat;
	if ( !(Options.Liste) )
		StreamStatus(0);
	return;
}
#endif

EXAWORD	LibMnemonics( cptr , si , Mode )
BPTR	cptr;
EXAWORD	si;
EXAWORD	Mode;
{
	EXAWORD	channel=0;
	EXAWORD	clfcode;
	BPTR	vptr;
	EXAWORD	phase;
	EXAWORD	format;
	EXAWORD	argflag;
	BPTR	dptr;
	EXAWORD	fl;

	ArgMask = 0;

	dptr = (cptr + si);	

	if ( Mode == _tc_CLF ) {

		/* Collect Function Code */
		/* --------------------- */
		si++; clfcode = (EXAWORD) *(cptr + si ); si++;

		/* Watch out for the function FM and PROCPTR*/
		/* -----------------------------------------*/
		switch (clfcode) {

			case 0x005A 	: format = 0x0054; break;
			case 0x006A 	: format = 0x0056; break;
			case 0x007A 	: format = 0x0040; break;
			default		: format = 0; break;
			
			}

		/* Separate FM functions */
		/* --------------------- */
		if ( format != 0 ) {

			AffVarb((tcGetw((cptr + si)))); oputb('=');
			si += WORDSIZE;
			ClfMnemonic( clfcode );
			
			switch ( format ) {

				case 0x0054 : 	AffVarb((tcGetw((cptr + si))));
						fl = (2+(2*WORDSIZE));
					      	break;
				case 0x0056 : 	AffReg( *(cptr + si ) );
						fl = (2+1+WORDSIZE);
					      	break;
				case 0x0040 :	fl = fmtoa( (cptr + si) );
						fl += (3+WORDSIZE);
						break;
								
				}
			oputb(')');
			return( fl );
			}

		/* Position to Values */
		/* ------------------ */
		vptr = (BPTR) (cptr + si); while ( *(vptr++) & 1 );

		/* Check for Preceeding Result Value */
		/* --------------------------------- */
		if ((( clfcode & 0x000F ) != 0x0007 )
		&&  (( clfcode & 0x000F ) != 0x0003 )
		&&  (( clfcode & 0x000F ) != 0x0001 )) {

			vptr = Arguaments( ((*(cptr + si) & 0x00E0) >> 5) , vptr, 4 );

			oputb('=');
			phase = 5;

			}
		else	{
			phase = 0;
			}

		/* Display Function Mnemonic */
		/* ------------------------- */
		ClfMnemonic( clfcode );

		if ( clfcode == 0x00BD )
			ClfProcPtr = clfcode;
		else	ClfProcPtr = 0;

		}
	else	{
		/* USER LIBRARY FUNCTIONS */
		/* ---------------------- */
		/* Collect Library  ID    */
		/* ---------------------- */
		si++;
		if ( Mode == _tc_LDF ) {
			clfcode = (EXAWORD) *(cptr + si ); 
			si++;
			}

		/* Position to Values */
		/* ------------------ */
		vptr = (BPTR) (cptr + si); while ( *(vptr++) & 1 );

		/* Check for Preceeding Integer return value */
		/* ----------------------------------------- */
		if ((((EXAWORD) *(cptr + si) ) & 0x0080 ) == 0x0080) {

			/* Display Result Arguament */
			/* ------------------------ */
			vptr = Arguaments( ((*(cptr + si) & 0x0060) >> 5) , vptr, 4 );
			oputs(" =");
			phase = 5;
			}
		else	{
			phase = 0;
			}

		/* Display Dynamic library Number */
		/* ------------------------------ */
		if ( Mode == _tc_LDF ) {
			oputs(" USER"); 
			HexaOctet( clfcode ); 
			}

		oputb('(');

		}

	argflag = 0;
	while ( 1 ) {
		if ( phase == 1 ) {
			if ( *(cptr + si) & 1 ) {
				si++;
				phase = 5;
				}
			else	{
				break;
				}
			}
		else	{
			if ( phase == 5 ) {
				if ( *(cptr + si) & 0x0010 ) {
					phase = 1;
					}
				else	{
					break;
					}
				}
			else	{
				phase = 5;
				}
			}

		if ( argflag == 0 ) {
			argflag = 1;
			}
		else	{
			oputb(',');
			}
		vptr = Arguaments( ( (*(cptr + si) & (0x000E << (phase -1))) >> phase), vptr, 4 );

		}
	/* Close function brackets and Return */
	/* ---------------------------------- */
	oputb(')');
	return((EXAWORD) (vptr - dptr));

}

void	NgfMnemonic( ngfcode )
EXAWORD	ngfcode;
{
	oputs( & ngfmnem[ ngfcode ][0] );
	return;
}

static	EXAWORD	NgfBufferFlag=0;

VOID	set_ngf_buffer_flag()
{
	NgfBufferFlag=1;
	return;
}

struct	buffer_variable
{
	EXAWORD	identity;	/* variable identity	*/
	EXAWORD	type;		/* variable type	*/
	BPTR	key;		/* declaration key	*/
	BPTR	name;		/* variable name	*/
	BYTE	work[64];	/* fall back storage	*/
	EXAWORD	offset;		/* offset from host	*/
	EXAWORD	host;		/* host identity	*/
	EXAWORD	length;		/* unit length		*/
	EXAWORD	primary;	/* primary dimension	*/
	EXAWORD	secondary;	/* secondary dimension	*/
	EXAWORD	size;		/* description size 	*/
	EXAWORD	occupation;	/* memory occupation	*/
	EXAWORD	indent;		/* offset into field	*/
};

EXAWORD	AnalyseBufferVariable( EXAWORD variable, struct buffer_variable * vptr )
{
	BPTR	bptr;
	BPTR	dptr;
	EXAWORD	indent;

	if (!( vptr->name = ResolveVariableName( variable ) ))
		sprintf(vptr->name = vptr->work,"[%cV%08X]",(variable & ISLOCAL ?'L':'G'),variable);

	if (( variable & ISLOCAL) != 0)  
		bptr = tcLDT;
	else	bptr = tcGDT;

	if (!( bptr )) 	
		return(MOINS_UN);
	else if (!( dptr = (bptr + (variable & TOGLOBAL)) ))
		return(MOINS_UN);
	else	indent = 0;

	if ((vptr->type = tcGetw( (dptr+indent) )) == MOINS_UN)
		return(MOINS_UN);
	else	indent += WORDSIZE;

	if ( vptr->type & 0x9000 ) 
	{
		vptr->host = tcGetw( (dptr+indent) );
		indent += WORDSIZE;
		vptr->key = "PTR";
	}
	else 	
	{
		vptr->host = 0;
		vptr->key = "DCL";
	}

	vptr->offset = tcGetw( (dptr+indent) );
	indent += WORDSIZE;

	if ( vptr->type & 0x0002 )
	{
		vptr->length = tcGetw( (dptr+indent) );
		indent += WORDSIZE;
	}
	else if (( vptr->type & 0x0005 ) == 5)
		vptr->length = 4;
	else 	vptr->length = ((vptr->type & 1) + 1);

	if ( vptr->type & 0x0040 )
	{
		vptr->primary = tcGetw( (dptr+indent) );
		indent += WORDSIZE;
		if ( vptr->type & 0x0020 )
		{
			vptr->secondary = tcGetw( (dptr+indent) );
			indent += WORDSIZE;
		}
		else
		{
			vptr->secondary = 1;
		}
	}
	else
	{
		vptr->primary = vptr->secondary = 1;
	}
	vptr->occupation = (vptr->length * vptr->primary * vptr->secondary);
	vptr->indent = 0;
	vptr->size = indent;
	return( (variable+indent) );
}

void	DisplayBufferVariable( struct buffer_variable * vptr )
{
	fprintf(stderr,"%08X:  ",vptr->offset);
	switch ( vptr->type & 0x0007 )
	{
	case	0	:
		fprintf(stderr,"%s %s%c",vptr->key,vptr->name,'#');
		break;
	case	1	:
		fprintf(stderr,"%s %s%c",vptr->key,vptr->name,'%');
		break;
	case	2	:
		fprintf(stderr,"%s %s%c%u",vptr->key,vptr->name,'=',vptr->length);
		break;
	case	3	:
		fprintf(stderr,"%s %s$%c%u",vptr->key,vptr->name,'=',vptr->length);
		break;
	case	4	:
		fprintf(stderr,"%s %s%c",vptr->key,vptr->name,'#');
		break;
	case	5	:
		fprintf(stderr,"%s %s%c",vptr->key,vptr->name,':');
		break;
	default		:
		return;
	}
	/* handle dimensions */
	if ( vptr->type & 0x0040 )
	{
		fprintf(stderr,"(%u",vptr->primary);
		if ( vptr->type & 0x0020 )
			fprintf(stderr,",%u",vptr->secondary);
		fprintf(stderr,")");
	}
	fprintf(stderr,"\n");
}

void	NgfBufferStructure( EXAWORD bv, EXAWORD occupation )
{
	struct	buffer_variable V;
	struct	buffer_variable N;

	EXAWORD	next;

	if (( next = AnalyseBufferVariable( bv, &V )) == MOINS_UN)
		return;
	else
	{
		DisplayBufferVariable( &V );

		if ( occupation )
			V.occupation = occupation;

		while ((next = AnalyseBufferVariable(next, &N)) != MOINS_UN)
		{
			if ( N.host != V.host )
				break;
			else if ( N.offset < V.offset )
				break;
			else if ( N.offset >= (V.offset + V.occupation) )
				break;
			else if ( (N.offset+N.occupation) >= (V.offset + V.occupation) )
				break;
			else 
			{
				if (!( V.indent ))
					fprintf(stderr,"FIELD=M,%s\n",V.name);
				if ( (N.offset-V.offset) > V.indent )
					fprintf(stderr,"DCL FILLER=%u\n",((N.offset-V.offset)-V.indent));

				DisplayBufferVariable( &N );		
				V.indent += N.occupation;

				continue;
			}
		}
		fprintf(stderr,"------------------------------------------\n");
		return;
	}
}

EXAWORD	NgfSyntax( cptr , si , comment )
BPTR	cptr;
EXAWORD	si;
EXAWORD	comment;
{
	BPTR	vptr;
	EXAWORD	ngfcode;
	EXAWORD	phase;
	EXAWORD	argflag;
	BPTR	dptr;
	EXAWORD	NgfOptions=0;

	ArgMask=0; ArgBuffer = 0; ArgLength = 0;

	dptr = (cptr + si);

	/* Display NGF FUNCTION code */
	/* ------------------------- */
	si++; oputs( & ngfmnem[ (ngfcode = ((EXAWORD) *(cptr + si))) ][0] );

#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_ngf_stat[ ngfcode ]++;
#endif
	/* Scan past arguament descriptors */
	/* ------------------------------- */
	si++; vptr = (BPTR) (cptr + si); while ( *(vptr++) & 1 );

	/* Check for and Display LOCAL ERROR TRAP */
	/* -------------------------------------- */
	if (( *(cptr + si) & 0x0080 ) != 0 ) {
		phase = 1;
		oline();
		Comment(comment);
		oputs("      ERR ");			
		AffEtt( (tcGetw( vptr )) ); vptr +=WORDSIZE;
		oputb(',');

		/* Check for Register and display */
		/* ------------------------------ */
		if (( *(cptr + si) & 0x0060 ) == 0x0060 ) {
			AffReg( *(vptr++) );
			}
		else	{
			/* Display Error Variable */
			/* ---------------------- */
			AffVarb( (tcGetw( vptr)) );
			vptr += WORDSIZE;
			}
		}
	else	{
		phase = 5;
		}

	/* Display File Table Identifier */
	/* ----------------------------- */
	oline(); Comment(comment); oputs("      FTI ");

	vptr = Arguaments( ( (*(cptr + si) & (0x000E << (phase -1))) >> phase), vptr, 4 );

	/* Clear Extra status Byte */
	/* ----------------------- */
	switch ( ngfcode ) {
		case _NGF_MODIFY :
		case _NGF_INSERT :
		case _NGF_DOWN   :
		case _NGF_UP     :
		case _NGF_DELETE :
		case _NGF_SEARCH :
				ArgMask=1;
		case _NGF_ATB	 :
		case _NGF_ERASE  :
		case _NGF_CREATE :
		case _NGF_POSIT	 :
		case _NGF_COUNT	 : 
		case _NGF_COLLECT: 
		case _NGF_EXEC	 :
				oline(); Comment(comment);
				oputs("      OPT ");			
				HexaOctet( (NgfOptions = (*(vptr++) & 0x00FF)) );
				break;
		default		:
			NgfOptions = 0;
			ArgMask=0;
		}

	if (( ArgMask ) && (NgfOptions )) {
		while (!( ArgMask & NgfOptions )) {
			ArgMask <<= 1;
			if (!( ArgMask ))
				break;
			}
		}

	/* Display Remaining Arguaments */
	/* ---------------------------- */
	argflag = 0; 
	while ( 1 ) {
		if ( phase == 1 ) {
			if ( *(cptr + si) & 1 ) {
				si++;
				phase = 5;
				}
			else	{
				break;
				}
			}
		else	{
			if ( *(cptr + si) & 0x0010 ) {
				phase = 1;
				}
			else	{
				break;
				}
			}
		if ( argflag == 0 ) {
			oline(); Comment(comment);
			oputs("      ARG (");
			argflag = 1;
			}
		else	{
			argflag++;
			oputb(',');
			}
		switch ( ngfcode ) {
			case _NGF_SEARCH :
			case _NGF_MODIFY :
			case _NGF_INSERT :
			case _NGF_DOWN   :
			case _NGF_UP     :
				break;
			}
		vptr = Arguaments( ( (*(cptr + si) & (0x000E << (phase -1))) >> phase), vptr, 4 );
		switch ( ngfcode ) {
			case _NGF_SEARCH :
			case _NGF_MODIFY :
			case _NGF_INSERT :
			case _NGF_DOWN   :
			case _NGF_UP     :
				do	{
					ArgMask <<= 1;
					if (!( ArgMask ))
						break;
					}
				while (!( ArgMask & NgfOptions ));
			}
		}
	if ( argflag != 0 ) {
		oputb(')');
		}

	ArgMask=0; ArgBuffer = 0; ArgLength = 0;

	return((EXAWORD) (vptr - dptr));

}

/*	-------------------------------------------	*/
/*	   R e s o l v e V a r i a b l e N a m e	*/
/*	-------------------------------------------	*/
BPTR	ResolveVariableName( EXAWORD variable )
{
	if ( variable & ISLOCAL )
		return( get_local_name ( (variable & TOGLOBAL) ) );
	else	return( get_global_name( (variable & TOGLOBAL) ) );
}

/*	-----------------------------------------------	*/
/*		L a s t V a r i a b l e N a m e		*/
/*	-----------------------------------------------	*/
/*	display the last variable name with punctuation	*/
/*	-----------------------------------------------	*/
void	LastVariableName( BPTR prefix, EXAWORD variable )
{
	BPTR	vname;
	if (!( vname = ResolveVariableName( variable ) ))
	{
		fprintf(stderr,"%s[%cV",prefix,(variable & ISLOCAL?'L':'G'));
		switch ( sizeof( EXAWORD ) )
		{
		case	2	: fprintf(stderr,"%04X",variable); break;
		case	4	: fprintf(stderr,"%08lx",variable); break;
		case	8	: fprintf(stderr,"%016llx",variable); break;
		}
		fprintf(stderr,"]");
	}
	else 	fprintf(stderr,"%s%s",prefix,vname);
}

/*	-----------------------------------------------------	*/
/*			N g f A n a l y s i s 			*/
/*	-----------------------------------------------------	*/
/*	When Advanced Listing is active this will display the	*/
/*	ABAL instruction like version of the NGF operation.	*/
/*	It will also intercept SI/MC/BD RECORD operation with	*/
/*	an aim to providing FILE RECORD Structure assiatnce.	*/
/*	-----------------------------------------------------	*/

EXAWORD	NgfAnalysis( cptr , si , comment )
BPTR	cptr;
EXAWORD	si;
EXAWORD	comment;
{
	EXAWORD	elabel;
	EXAWORD	etype;
	EXAWORD	evalue;
	EXAWORD	LastFunction=0;
	EXAWORD	LastHandle=0;
	EXAWORD	LastOption=0;
	EXAWORD	LastPrimary=0;
	EXAWORD	LastRecord=0;
	EXAWORD	LastMarker=0;
	EXAWORD	LastLength=0;
	BPTR	LastName;
	BPTR	vptr;
	EXAWORD	ngfcode;
	EXAWORD	phase;
	EXAWORD	argflag;
	BPTR	dptr;
	EXAWORD	NgfOptions=0;

	ArgMask=0; ArgBuffer = 0; ArgLength = 0;

	dptr = (cptr + si);

	/* ------------------------- */
	/* Display NGF FUNCTION code */
	/* ------------------------- */
	si++; oputs( & ngfmnem[ (ngfcode = ((EXAWORD) *(cptr + si))) ][0] );

#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_ngf_stat[ ngfcode ]++;
#endif
	/* ------------------------------- */
	/* Scan past arguament descriptors */
	/* ------------------------------- */
	si++; vptr = (BPTR) (cptr + si); while ( *(vptr++) & 1 );

	/* -------------------------------------- */
	/* Check for and Display LOCAL ERROR TRAP */
	/* -------------------------------------- */
	if (( *(cptr + si) & 0x0080 ) != 0 ) 
	{
		phase = 1;
		elabel = tcGetw( vptr ); vptr +=WORDSIZE;

		if ((etype = ( *(cptr + si) & 0x0060 )) == 0x0060 ) 
		{
			evalue = *(vptr++);
		}
		else	
		{
			/* ---------------------- */
			/* Display Error Variable */
			/* ---------------------- */
			evalue = tcGetw( vptr);
			vptr += WORDSIZE;
		}
		etype >>= 5;
		etype += 1;
	}
	else	
	{
		etype = 0;
		phase = 5;
	}

	oputs("=");

	vptr = Arguaments( ( (*(cptr + si) & (0x000E << (phase -1))) >> phase), vptr, 4 );

	if (!( LastArg )) { LastHandle = LastInt; } else { LastHandle = 0; }

	if ( etype != 0 ) 
	{
		oputs(":"); AffEtt( elabel ); oputs(",");
		switch ( etype ) 
		{
			case	1 :	HexWord( evalue ); break;
			case	2 :	AffCons( evalue ); break;
			case	3 :	AffVarb( evalue ); break;
			case	4 :	AffReg( evalue ); break;
		}
	}

	/* ----------------------- */
	/* Clear Extra status Byte */
	/* ----------------------- */
	LastFunction = 0;
	switch ( ngfcode ) 
	{
		case _NGF_MODIFY :
		case _NGF_INSERT :
		case _NGF_DOWN   :
		case _NGF_UP     :
		case _NGF_DELETE :
		case _NGF_SEARCH :
				LastFunction = ngfcode;
				ArgMask=1;
		case _NGF_ATB	 :
		case _NGF_ERASE  :
		case _NGF_CREATE :
		case _NGF_POSIT	 :
		case _NGF_COUNT	 : 
		case _NGF_EXEC	 :
				oputs(",(");			
				HexaOctet( (NgfOptions = (*(vptr++) & 0x00FF)) );
				oputs(")");			
				break;
		default		:
			NgfOptions = 0;
			ArgMask=0;
	}

	/* -------------------------------------------------- */
	/* detect an SI/MC/BD RECORD Function with INT Handle */
	/* -------------------------------------------------- */
	if (( LastFunction != 0 ) && ( LastHandle != 0 ))
		LastOption = NgfOptions;
	else	LastOption = 0;

	if (( ArgMask ) && ( NgfOptions )) 
	{
		while (!( ArgMask & NgfOptions )) 
		{
			ArgMask <<= 1;
			if (!( ArgMask ))
				break;
		}
	}

	/* ---------------------------- */
	/* Process Remaining Arguaments */
	/* ---------------------------- */
	argflag = 0; 
	while ( 1 ) 
	{
		if ( phase == 1 ) 
		{
			if ( *(cptr + si) & 1 ) 
			{
				si++;
				phase = 5;
			}
			else	
			{
				break;
			}
		}
		else	
		{
			if ( *(cptr + si) & 0x0010 ) 
			{
				phase = 1;
			}
			else	
			{
				break;
			}
		}
		if ( argflag == 0 ) 
		{
			oputs(",");
			argflag = 1;
		}
		else	
		{
			argflag++;
			oputb(',');
		}
		switch ( ngfcode ) 
		{
			case _NGF_SEARCH :
			case _NGF_MODIFY :
			case _NGF_INSERT :
			case _NGF_DOWN   :
			case _NGF_UP     :
				break;
		}
		vptr = Arguaments( ( (*(cptr + si) & (0x000E << (phase -1))) >> phase), vptr, 4 );
		switch ( ngfcode ) 
		{
			case _NGF_SEARCH :
			case _NGF_MODIFY :
			case _NGF_INSERT :
			case _NGF_DOWN   :
			case _NGF_UP     :
				switch ( ArgMask )
				{
				case	1	: 
					if ( LastArg == 2 )
						LastPrimary = LastVar; 
					break;
				case	2	: 
					if ( LastArg == 2 )
						LastMarker = LastVar; 
					break;
				case	4	: 
					if ( LastArg == 2 )
						LastRecord = LastVar; 
					break;
				case	8	: 
					if ( LastArg == 0 )
						LastLength = LastInt; 
					break;
				}
				do	
				{
					ArgMask <<= 1;
					if (!( ArgMask ))
						break;
				}
				while (!( ArgMask & NgfOptions ));
		}
	}
	ArgMask=0; ArgBuffer = 0; ArgLength = 0;

	if (( LastHandle ) && ( LastFunction ))
	{
		fprintf(stderr,"%s=%lu", & ngfmnem[LastFunction][0], LastHandle );
		if ( LastPrimary )
			LastVariableName( ",", LastPrimary );
		if ( LastRecord  )
			LastVariableName( ":", LastRecord  );
		if ( LastLength )
			fprintf(stderr,",%u",LastLength);
		fprintf(stderr,"\n------------------------------------------\n");
		if ( LastPrimary)
			NgfBufferStructure( LastPrimary, 0 );
		if ( LastRecord )
			NgfBufferStructure( LastRecord, LastLength );
	}

	return((EXAWORD) (vptr - dptr));

}

EXAWORD	EventSyntax( cptr )
BPTR	cptr;
{

	switch ( *(cptr + 1) ) {
		case _ec_STOP : oputs(" STOP ");  return(2);
		case _ec_RAZ  : oputs(" RAZ ");   return(2);
		case _ec_START: oputs(" START "); return(2);
		case _ec_FAUX : oputs(" FALSE "); return(2);
		case _ec_HALT : oputs(" HALT ");  return(2);
		case _ec_DCL  : oputs(" DCL "); 
				AffEtt((tcGetw((cptr + 2)))); return( 2 + WORDSIZE );
		default	      : 
			if ( *(cptr + 1) & _ec_EXTERN ) {
				switch (( *(cptr + 1) & 0x003F )) {
					case _ec_CALLI : oputs("CALL ");
							 HexWord((tcGetw((cptr + 2)))); 
							 return( 2 + WORDSIZE );
					case _ec_CALLV : oputs("CALL ");
							 AffVarb((tcGetw((cptr + 2)))); 
							 return( 2 + WORDSIZE );
					case _ec_GOTO  : oputs("JMI  ");
							 AffEtt((tcGetw((cptr + 2)))); 
							 return( 2 + WORDSIZE );
					case _ec_GOSUB : oputs("GSB  ");
							 AffEtt((tcGetw((cptr + 2)))); 
							 return( 2 + WORDSIZE );
					case _ec_RAZ   : oputs("RAZ ");
							 return(2);

					}
				}
			return( 1 );
		}
}

/*
 *	ABAL virtual machine assembly list function
 *	-------------------------------------------
 *
 */

#include "aotclist.c"

void	AffBcdString( sptr , slen )
BPTR	sptr;
EXAWORD	slen;
{
	while ( slen != 0 ) {
		HexaOctet( *(sptr++) );
		slen--;
		}
	return;
}

void	AffAlphaString( sptr , slen )
BPTR	sptr;
EXAWORD	slen;
{
	oputb('"');
	while ( slen != 0 ) {
		oputb( *(sptr++) );
		slen--;
		}
	oputb('"');
	return;
}


void	data_list_file( sptr , si , extra, comment )
BPTR	sptr;
EXAWORD	si;
EXAWORD	extra;
EXAWORD	comment;
{
	EXAWORD	data_length;

	/* Adjust for Item Count and Segment End */
	/* ------------------------------------- */
	extra -= (3 * WORDSIZE);

	/* Repeat till end of Data */
	/* ----------------------- */
	while ( extra != 0 ) {

		/* Check for and perform Comment for Compiler */
		/* ------------------------------------------ */
		Comment(comment);

		/* Display the T-Code adresse */
		/* -------------------------- */
		AffEtt( si ); oputs(" DATA ");
	
		if (( data_length = *(sptr + si++) ) == 0 ) {
			extra--;
			data_length = *(sptr + si++);
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
			if (!( Options.Alliance ))
#endif
#endif
				AffBcdString( (sptr + si), data_length );

			}
		else	{
			/* Display AlphaNumeric String Data */
			/* -------------------------------- */
#ifndef	VISUAL_DEBUGER
#ifdef	AO_STATS
			if (!( Options.Alliance ))
#endif
#endif
				AffAlphaString( (sptr + si), data_length );

			}

		oline();

		si 	+= data_length;
		extra	-= (data_length+1);

		}
	return;
}


#endif	/* _TCODE_C */
	/* -------- */

