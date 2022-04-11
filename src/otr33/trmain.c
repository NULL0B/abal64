/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRMAIN.C  				*/
/*		Version :	3.1a					*/
/*		Date	:	23/05/2003				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_TRMAIN_C
#define	_TRMAIN_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <string.h>
#include "stdtypes.h"
#include "translat.h"
#include "trerrors.h"
#include "troption.h"
#include "trabmsg.h"
#include "trworld.h"
#include "trabmsg.h"
#include "trmain.h"
#include "trsymbol.h"
#include "trabal.h"
#include "trinput.h"
#include "trdirect.h"
#include "trtables.h"
#include "trvalue.h"
#include "trexpres.h"
#include "trsyntax.h"
#ifdef	WIN32
#include "trecho.h"
#endif

/*
#ifdef PROLOGUE
#include "aw_syst.h"
#endif
*/
#ifdef WIN32
#include "wotrmess.h"
#include "trver.h"

extern int OptIdra;
#endif

#ifndef	UNIX
#else
BPTR	allocate_for_string();
WORD	translator_command_line();
VOID	verbalise_options();
#endif

	WORD	GlobalError=0;
static  WORD	ClassDependance=FAUX;

EXTERN	BYTE	TokenBuffer[];

#ifdef	PROLOGUE
BPTR	sysgetenv(BPTR nom)
{
	return((BPTR) 0);
}
#endif

#ifdef WIN32
BPTR	sysgetenv(BPTR nom)
{
	return ((BPTR) x_getenv(nom));
}
#endif

WORD	show_class_dependance()
{
	return( ClassDependance );
}


#define	MODULE_PROVISOIRE  "\n   Provisoire du 11/01/2007 "
#define	MODULE_ENVIRONMENT "\n   Environnement Version 1.1a "
#define	MODULE_COPYRIGHT   "\n   Copyright (c) 1989,2007 Amenesik / Sologic "


static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[16];

static  char	VersionStatus[16]=
	{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
#ifdef	ABAL33A
#ifdef	otr32
static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','3','a','0','0','5',1 };
#else
static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','3','a','0','0','5',1 };
#endif

#else

#ifdef	ABAL32A
#ifdef	otr32
static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','2','a','0','0','5',1 };
#else
static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','2','a','0','0','5',1 };
#endif

#else

#ifdef	otr32
static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','1','e','0','0','5',1 };
#else
static	char 	LaPaterne[32] = { '*','P','R','L','@','I','N','F','O','*','#',6,'3','1','e','0','0','5',1 };
#endif

#endif
#endif

char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = '.';
			LaVersion[7] = LaPaterne[16];
			LaVersion[8] = LaPaterne[17];
			LaVersion[9] = 0;
			}
		else if ( LaPaterne[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
			}
		else	LaVersion[4] = 0;

		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

VOID	translator_identification()
{
	initialise_text_messages();
	sysprintf("\n   %s  Version %s ",imessage_text(1) /*ABAL++ Object Translator*/,getpatternversion());
#ifdef	otr32
	sysprintf("-32");
#endif
#ifdef	otr16
	sysprintf("-16");
#endif
#ifdef	ABALSQL
	sysprintf(" -SQL");
#endif
	if ( VersionStatus[15] == '2' ) 
		sysprintf("%s",MODULE_PROVISOIRE);
	sysprintf("%s",MODULE_ENVIRONMENT);
	sysprintf("%s",MODULE_COPYRIGHT);
#ifdef	UNIX
	sysprintf(" \n\n");
#else
	sysprintf(" \n");
#endif
	return;
}

VOID	initialise_option_pointers()
{
	BPTR	eptr;

	OtrOption.Extension     = (BPTR) 0;
	OtrOption.TargetName	= (BPTR) 0;
	OtrOption.ErrorFile	= (BPTR) 0;
	OtrOption.ListFile	= (BPTR) 0;
	OtrOption.Inclusion	= (BPTR) 0;
#ifdef ABAL33A
	OtrOption.AutoLink	= (BPTR) 0;
	if ((eptr = sysgetenv("AUTOLINK")) != (BPTR)0)
		OtrOption.AutoLink	= allocate_for_string(eptr);
#endif
	return;
}

static	VOID	initialise_options()
{
	initialise_option_pointers();
	OtrOption.ExternCommon=0;
	OtrOption.Strict = 0;
	OtrOption.DirectiveDate=1;
	OtrOption.PublicCommon=0;
	OtrOption.InitLocal=0;
	OtrOption.KeepQuote=0;
	OtrOption.Invocation=0;
	OtrOption.Con = 0;
	OtrOption.InhibitAlias = 0;
	OtrOption.KeyboardFlush= 0;
	OtrOption.NoFlush= 0;
#ifdef	otr32	
	OtrOption.TcodeVersion	= '3';
	OtrOption.WordSize    	= WORD32SIZE;
	ISLOCAL = ISLOCAL4;
	TOGLOBAL= TOGLOBAL4;
#else
	OtrOption.TcodeVersion	= '2';
	OtrOption.WordSize    	= WORD16SIZE;
#endif
	OtrOption.DuplicateSymbols = 1;
	OtrOption.Special 	= FAUX;
	OtrOption.Priority	= FAUX;
	OtrOption.TokenSize     = 16;
	OtrOption.LabelSize     = 32;
	OtrOption.Verbose	= FAUX;
	OtrOption.SourceTrace	= FAUX;
	OtrOption.TargetTrace	= FAUX;
	OtrOption.UpperCase     = VRAI;
	OtrOption.BlockComment  = VRAI;
	OtrOption.AutoGetLine   = FAUX;
	OtrOption.BibMath	= FAUX;
	OtrOption.Symbolic	= 0x1002;
	OtrOption.Generate	= VRAI;
	OtrOption.Optimise	= _ALL_OPTIMISATIONS;
	OtrOption.Optimise	&= ~ _OPTIMISE_TABLES;
	OtrOption.Enhanced	= _ALL_ENHANCEMENTS;
	OtrOption.Warning	= FAUX;
	OtrOption.Aliasing	= FAUX;
	OtrOption.LocalConstant = FAUX;
	OtrOption.TraceErrors   = FAUX;
	OtrOption.ErrorLimit	= 0;
	OtrOption.ErrorCount	= 0;
	OtrOption.Extension	= allocate_for_string((BPTR) imessage_text(18));
	OtrOption.ListFlag	= 0;
	OtrOption.TargetType	= 0;	/* 0: Do not check, 1: .AT waited, 2: .O waited */
#ifdef	ABAL33A
	OtrOption.NoAutoLink	= FAUX;
#endif
	default_language_options();
	return;
}

VOID	liberate_for_options()
{
	if ( OtrOption.Extension != (BPTR) 0 )
		liberate( OtrOption.Extension );
	if ( OtrOption.TargetName != (BPTR) 0 )
		liberate( OtrOption.TargetName );
	if ( OtrOption.ListFile != (BPTR) 0 )
		liberate( OtrOption.ListFile );
	if ( OtrOption.ErrorFile != (BPTR) 0 )
		liberate( OtrOption.ErrorFile );
#ifdef	ABAL33A
	if ( OtrOption.AutoLink != (BPTR) 0 )
		liberate( OtrOption.AutoLink );
#endif
	initialise_option_pointers();
	return;
}

VOID	set_global_error( n )
WORD	n;
{
	GlobalError += n;
	return;
}

WORD	error_limit_reached()
{
	if ( GlobalError >= OtrOption.ErrorLimit )
		return( VRAI );
	else	return( FAUX );
}

static	WORD	OtrStatistics=0;

WORD	analyse_option_file( aptr )
BPTR	aptr;
{
	FILEPTR	handle;
	WORD	status=0;
	WORD	c;
	WORD	i=0;
	WORD	QuotedData=0;

	if ((handle = fopen( aptr, "r" )) != (FILEPTR) 0) {
		while (1) {
			switch ((c = fgetc(handle))) {
				case	0x001A	:
				case	MOINS_UN:
				case	0	:
					c = 0;
				case	' '     :
					if (QuotedData) {
						TokenBuffer[i++] = c;
						continue;
						}
				case	'\t'	:
				case	0x000C	:
				case	0x001C	:
				case	'\r'	:
				case	'\n'	:
					if ( i ) {
						TokenBuffer[i++] = 0;
						if ((status = translator_command_line((BPTR) TokenBuffer)) != 0)
							break;
						else	i = 0;
						}
		
					if ( c )
						continue;
					else	return( 0 );

				case '"':
					QuotedData = !QuotedData;
					TokenBuffer[i++] = c;
					continue;

				default		:
					TokenBuffer[i++] = c;
					continue;
				}
			break;
			}
		fclose( handle );
		return( status );
		}
	else	return( 40 );
}

BPTR	set_pragma_output( BPTR );

WORD	analyse_translator_options( aptr )
BPTR	aptr;
{
	WORD	status=0;
	WORD	v=0;
	BPTR	aptr0 = aptr;

	while ( *aptr ) {
		switch ( *(aptr++) ) {
			case 'a' :
			case 'A' :
				OtrOption.Aliasing = VRAI;
				break;
			case 'b' :
			case 'B' :
				OtrOption.BibMath = VRAI;
				break;
			case 'c' :
			case 'C' :
				ClassDependance = VRAI;
				break;
			case 'd' :
			case 'D' : 
				if ( OtrOption.TargetName != (BPTR) 0 )
					liberate( OtrOption.TargetName );
				OtrOption.TargetName = allocate_for_string(aptr);
				while ( *aptr )
					aptr++;
				break;
			case 'e' :
			case 'E' :
				OtrOption.TraceErrors = VRAI;
				OtrOption.ErrorLimit  = _DEFAULT_ERROR_LIMIT;
				if ( OtrOption.ErrorFile != (BPTR) 0 )
					liberate( OtrOption.ErrorFile );
				OtrOption.ErrorFile   = allocate_for_string(aptr);
				if ( strlen( OtrOption.ErrorFile ) )
					set_world_errorfile( OtrOption.ErrorFile, (BPTR) 0 );
				while ( *aptr )
					aptr++;
				break;
			case 'f' :
			case 'F' :
				if ((status = analyse_option_file( aptr )) != 0 ) {
					break;
					}

			   	while ( *aptr )
					aptr++;
				break;
			case 'g' :
			case 'G' : 
				if (( *aptr == 'd')
				||  ( *aptr == 'D')) {
					OtrOption.DirectiveDate=0;
					aptr++;
					}
				else	{
				OtrOption.Generate = 0;
				aptr = set_pragma_output( aptr );
					}
				break;
			case 'h' :
			case 'H' : 
				break;
			case 'i' :
			case 'I' :
				add_include_path( aptr );
				while ( *aptr )
					aptr++;
				break;
			case 'j' :
			case 'J' :
				add_library_path( aptr );
				while ( *aptr )
					aptr++;
				break;
			case 'k' :
			case 'K' :
				OtrOption.Con = VRAI;
				break;
			case 'l' :
			case 'L' :
				OtrOption.SourceTrace = 2;
				OtrOption.ListFlag    = 2; 
				if ( OtrOption.ListFile != (BPTR) 0 )
					liberate( OtrOption.ListFile );
				if (!( *aptr )) {
					OtrOption.ListFile = (BPTR) 0;
					}
				else	{
				OtrOption.ListFile = allocate_for_string(aptr);
				if ( strlen( OtrOption.ListFile ) )
					set_world_listfile( OtrOption.ListFile, (BPTR) 0 );
				while ( *aptr )
					aptr++;
					}
				break;
			case '+' :
				OtrOption.Strict |= 2;
				break;

			case 'm' :
			case 'M' : 
				OtrOption.Symbolic |= VRAI;
				if ( *aptr == '+' ) {
					OtrOption.Symbolic |= 2;
					aptr++;
					}
				else if ( *aptr == '-' ) {
					OtrOption.Symbolic &= ~2;
					aptr++;
					}
				break;
			case 'n' :
			case 'N' :
				if ((status = add_host_definition( aptr )) != 0 ) {
					status = 27;
					break;
					}
				while ( *aptr )
					aptr++;
				break;
			case 'o' :
			case 'O' : 
				OtrOption.Optimise = FAUX;
				break;
			case 'p' :
			case 'P' : 
				OtrOption.Special = VRAI;
				break;
			case 's' :
			case 'S' : 
				if ( OtrOption.Extension != (BPTR) 0 )
					liberate( OtrOption.Extension );
				OtrOption.Extension = allocate_for_string(aptr);
				while ( *aptr )
					aptr++;
				break;
			case 't' :
			case 'T' : 
				if (( *aptr == 'a' )
				||  ( *aptr == 'A' ))	
					OtrOption.TargetType = 1;
				else if (( *aptr == 'o' )
				     ||  ( *aptr == 'O' ))	
					OtrOption.TargetType = 2;
				aptr++;
				break;
			case '-' :
#ifdef ABAL33A
				if (uppercase_compare(aptr, "NOAUTOLINK")) {			
					OtrOption.NoAutoLink = VRAI;
					}
				else if (uppercase_ncompare(aptr, "AUTOLINK", 8))	{
					aptr += 8;
					if ( OtrOption.AutoLink != (BPTR) 0 )
						liberate( OtrOption.AutoLink );
					if (*aptr == '"') {
						aptr++;
						aptr[strlen(aptr) - 1] = 0;
						}

					if (*aptr != 0) {
						OtrOption.AutoLink = allocate_for_string(aptr);
						while ( *aptr )
							aptr++;
						}
					}
				else 	{
#endif
					OtrOption.UpperCase = 0;
					if ( *aptr ) {
						v = 0;
						while ( *aptr ) {
							if (( *aptr >= '0' ) && ( *aptr <= '9' ))
								v = ((v * 10) + ( *(aptr++) - '0' ));
							else	break;
							}
						while ( *aptr ) aptr++;
						if ( v ) OtrOption.TokenSize = v;
						}
#ifdef ABAL33A
					}
#endif
				break;

			case 'u' :
			case 'U' :
				OtrOption.UpperCase =1;
				if ( *aptr ) {
					v = 0;
					while ( *aptr ) {
						if (( *aptr >= '0' ) && ( *aptr <= '9' ))
							v = ((v * 10) + ( *(aptr++) - '0' ));
						else	break;
						}
					while ( *aptr ) aptr++;
					if ( v ) OtrOption.TokenSize = v;
					}
				break;

			case 'v' :
			case 'V' : 
				if (!( *aptr ))
				OtrOption.Verbose = 1;
				else	{
					OtrOption.Verbose = 0;
					while ( *aptr ) {
						switch ( *(aptr++) ) {
							case	'r'	:
							case	'R'	:
								OtrOption.Verbose = 33;
								continue;
							case	'i'	:
							case	'I'	:
								OtrOption.Verbose |= 1;
								continue;
							case	'v'	:
							case	'V'	:
								OtrOption.Verbose |= 2;
								continue;
							case	'f'	:
							case	'F'	:
								OtrOption.Verbose |= 4;
								continue;
							case	'o'	:
							case	'O'	:
							case	'+'	:
								OtrOption.Verbose |= 8;
								continue;
							case	's'	:
							case	'S'	:
								OtrOption.Verbose |= 16;
								continue;
							}
						break;
						}
					if (!( OtrOption.Verbose ))
						OtrOption.Verbose = 1;
					}
				break;
			case 'w' :
			case 'W' : 
				if ( *aptr == '+' ) {
					OtrOption.Strict |=1;
					aptr++;
					}
				activate_warnings( aptr );
				while ( *aptr )
					aptr++;
				break;
			case 'x' :
			case 'X' :
				OtrOption.TraceErrors = 2;
				OtrOption.ErrorLimit  = _DEFAULT_ERROR_LIMIT;
				if ( OtrOption.ErrorFile != (BPTR) 0 )
					liberate( OtrOption.ErrorFile );
				OtrOption.ErrorFile   = allocate_for_string(aptr);
				if ( strlen( OtrOption.ErrorFile ) )
					set_world_errorfile( OtrOption.ErrorFile, (BPTR) 0 );
				while ( *aptr )
					aptr++;
				break;
			case 'y' :
			case 'Y' : 
#ifdef	otr32
				OtrOption.TcodeVersion 	= '2';
				OtrOption.WordSize	= WORD16SIZE;
				ISLOCAL = ISLOCAL3;
				TOGLOBAL = TOGLOBAL3;
				OtrOption.Enhanced = _ALL_ENHANCEMENTS;
#else
				OtrOption.Enhanced |= _ENHANCED_64K;
				ISLOCAL = ISLOCAL4;


				TOGLOBAL = TOGLOBAL4;
#endif
				break;
			case 'z' :
			case 'Z' : 
				if (( *aptr == 't' )
				||  ( *aptr == 'T' ))	
					OtrOption.TargetTrace = 1;
				else if (( *aptr == 's' )
				     ||  ( *aptr == 'S' ))	
					OtrOption.SourceTrace = 1;
				else if (( *aptr == 'l' )
				     ||  ( *aptr == 'L' ))	
					OtrOption.SourceTrace = 2;
				aptr++;
				break;
			case ' ' :
			case '/' :
				break;
			case 'r' :
			case 'R' :
				OtrOption.TokenSize = 8;
				if (( *aptr == 'l' )
				||  ( *aptr == 'L' )) {
					OtrOption.LabelSize = 8;
					aptr++;
					}
				break;

			case 'q' :
			case 'Q' :
				OtrStatistics = VRAI;
				break;
			default	 :	/* cjkqrtu */
				status=30;
				break;
			}
		}

#ifdef	WIN32
	if ( status != 0) 
		incorrect_command_line(aptr0);
#endif
	return( status );
}

#include "trqual.c"

static	WORD	source_translation( filename )
BPTR	filename;
{
	WORD	status;
	if ((status = initialise_source_translation( filename )) == 0 ) {
		if ( World->PragmaFile ) { strcpy(TokenBuffer,World->PragmaFile ); }
		/* include this default pragma file */
		/* -------------------------------- */
		if (( World->PragmaFile )
		&&  ((status = include_source_file( World->PragmaFile, OtrOption.Extension )) != 0))
			report_error( status );
		else	{
		report_error( terminate_translation( (status = file_translation()) ));
			}
		}

	if ( OtrOption.TraceErrors )
		terminate_errors();

	while ( tcode_garbage_collector() );

	if ( OtrStatistics ) {
		value_statistics();
#ifdef	__QUALITY
		memory_statistics();
#endif
		symbol_statistics();
		rmv_statistics();
		kc_statistics();
		}
	terminate_world();
	return((GlobalError?1:0));
}

static  WORD	is_option_prefix( c )
WORD	c;
{
	if ( c == '-' )
		return( VRAI );
#ifndef	UNIX
	else if ( c == '/' )
		return( VRAI );
#endif
	else	return( FAUX );
}		
		
WORD	translator_command_line( aptr )
BPTR	aptr;
{		
	if ( is_option_prefix( *aptr ) )
		return( analyse_translator_options( ++aptr ) );
#ifndef	_TRDLL_C
	else	{

		verbalise_options(aptr);
		return( source_translation( aptr  ) );

		}
#else
	return(30);
#endif
}

#ifndef WIN32

/* Implementation in WOTR.C for Windows */

int	is_target_file_busy(BPTR FileName)
{      
#ifdef PROLOGUE
	/* TwinServer: Open with exclusive flag is not available with P3LLIBC (OK with PCRTL). */
	if (access(FileName, 0) == 0)
	{
		char  TmpFile[LGMXNOM];
		int	Lg;

		strcpy(TmpFile, FileName);
		Lg = strlen(TmpFile);
		/* Replace the last char by @. */
		TmpFile[Lg-1] = '@';

		if (rename(FileName, TmpFile) != 0)
			return 1;
		else
			rename(TmpFile, FileName);
	}
#else
#endif

  return 0;
}
#endif


#ifndef	_TRDLL_C

/*	-------------------------------------------------	*/
/*	Generation of the Stand Alone Version is Required	*/
/*	-------------------------------------------------	*/

VOID	banner()
{
/*	translator_identification();*/

	/* Functions Banner_xxx() implemented in bancode.h and banner.h. */
	BYTE Buf[256];
#ifdef	WIN32

	/* Product name */
	x_cprintf(Banner_GetProductName(Buf));

	/* Version */
	x_cprintf("\n");
	x_cprintf(Banner_GetVersionID(Buf, Banner_GetVersionStatus()));

	/* Build */
	x_cprintf("\n");
	x_cprintf(Banner_GetBuild(Buf));
	x_cprintf("\n");

	/* Copyright */
	x_cprintf(Banner_GetCopyright(Buf));
	x_cprintf("\n");

/* Internal name */
//	x_cprintf(Banner_GetInternalName(Buf));
//	x_cprintf("\n");

/* Commente */
//	x_cprintf(Banner_GetComment(Buf));
//	x_cprintf("\n");

#else

#ifdef PROLOGUEEEE

	/* Product name */
	sysprintf(Banner_GetProductName(buf));

	/* Version */
	sysprintf("\n");
	sysprintf(Banner_GetVersionID(Buf, Banner_GetVersionStatus()));

	/* Build */
	sysprintf(" ");
	sysprintf(Banner_GetBuild(buf));
/*
	// Unformated serial number
	AW_GetSerial(UserName);
	// Format the serial number with spaces as block separator
	AW_FormatSerial(SerialNo, UserName, ' ');
	// Company name
	AW_GetId(UserName, DeptName);
	UserName[sizeof(UserName)-1] = '\0';
	DeptName[sizeof(DeptName)-1] = '\0';
	// BSA informations
	sysprintf("\r\n%s %s","Serial number :        ", SerialNo);
	sysprintf("\r\n%s %s","User name :            ", UserName);
	sysprintf("\r\n%s %s","Company :              ", DeptName);
*/
	/* Copyright */
	sysprintf("\n");
	sysprintf(Banner_GetCopyright(Buf));

/* Internal name */
/*	sysprintf(Banner_GetInternalName(Buf));
	sysprintf("\n");
*/
/* Comment */
/*	sysprintf(Banner_GetComment(Buf));
	sysprintf("\n");
*/
#else
	/* UNIX */

	initialise_text_messages();
	sysprintf("\n   %s  Version %s ",imessage_text(1) /*ABAL++ Object Translator*/,getpatternversion());
#ifdef	otr32
	sysprintf("-32");
#endif
#ifdef	otr16
	sysprintf("-16");
#endif
	if ( VersionStatus[15] == '2' ) 
		sysprintf("%s",MODULE_PROVISOIRE);
	sysprintf("%s",MODULE_ENVIRONMENT);
	sysprintf("%s",MODULE_COPYRIGHT);
	sysprintf(" \n\n");

#endif
#endif /* WIN32 */

	return;
}

VOID	oldbanner()
{
	translator_identification();
	return;
}

/*	----------	*/
/*	M A I N	()	*/
/*	----------	*/


VOID	verbalise_options(filename)
BPTR	filename;
{
	if ( OtrOption.Verbose & 2 ) {

		sysprintf("%s : %s \n",imessage_text(2) /*Translation of*/,filename);
#ifdef	otr32
		if ( OtrOption.TcodeVersion == '3' )
			sysprintf("32 Bit Tcode     : ON   \n");
#endif
		if ( OtrOption.Optimise )
			sysprintf("Optimisation     : ON   \n");
		if ( OtrOption.Enhanced )
			sysprintf("Enhancements     : ON   \n");
		if ( OtrOption.LocalConstant )
			sysprintf("Local Constants  : ON   \n");
		if ( OtrOption.Aliasing      )
			sysprintf("Alias Constants  : ON   \n");
		if (!( OtrOption.Generate   ))
			sysprintf("Tcode Generation : ON   \n");
		if (   OtrOption.Warning     )
			sysprintf("Warning Messages : ON   \n");
		if (   OtrOption.TraceErrors )
			sysprintf("Error Tracing    : ON   \n");
		}
	return;
}


WORD _cropzeros() { return(0); }
WORD _cfltcvt()   { return(0); }

#ifndef	WIN32
int  main( argc, argv )
#else
int  majn( argc, argv )
#endif
int	argc;
BPTR	argv[];
{
	WORD	status=0;
	WORD	argi=1;
	BPTR	aptr;
	WORD	apadd=0;

	GlobalError = 0;
/*
#if !defined(UNIX) && !defined(WIN32)
	{
		char line[256];    

		// Vérification de la protection BSA
		if (AW_CheckProtection(FALSE))
		{
			sprintf(line,"license,%s,%s", argv[0], "Abal_Kit_de_Developpement");
			if (system(line))
			{
				sysprintf("Cl‚ de v‚rification absente ou invalide !");
				return(FALSE);
			}
		}
	}
#endif
*/
	if ((aptr = (BPTR) sysgetenv("ALLOCPADD")) != (BPTR) 0) {
		for ( apadd=0; *aptr != 0; aptr++ ) {
			if ((*aptr <= '0') || ( *aptr >='9' ))
				break;
			else	apadd = ((apadd * 10) + ( *aptr - '0' ));
			}
		}

#ifdef	UNIX
	set_allocate_padding(apadd);
	start_allocation_trace();
#endif
	initialise_text_messages();
/*
#ifdef WIN32
	if (OptIdra)
		// Display the source file to translate.
		ctOutputMessageDiagnostic2(argv[argc-1], NULL);
#endif
*/
	if ( argc == 1 )
#ifdef	WIN32
		if (!OptIdra)
#endif
			banner();

	initialise_options();

	initialise_world();

	/* Interprete option switches */
	/* -------------------------- */
	while ( argi < argc )
		if ((status = translator_command_line( argv[argi++] )) != 0)
			break;

	terminate_world();

#ifdef	WIN32
	/* Force to send possible last diagnostic message */
	sysprintf("\n");
#endif
	return(status);
}

#else	/* _TRDLL_C */

/*	-----------------------------------------	*/
/*	Generation of the Dynamic Library Version 	*/
/*	-----------------------------------------	*/
/*	% trinit($)					*/
/*	% trliber()					*/
/*	% trline($)					*/
/*	% troption($)					*/
/*	% trfile($,$)					*/
/*	-----------------------------------------	*/

SWORD	translator_initialisation( filename )
BPTR	filename;
{
	WORD	status;

	GlobalError = 0;

	initialise_text_messages();
	initialise_options();
	initialise_world();

	if ((status = initialise_remote_translation( filename )) != 0) {
		status = terminate_translation(status);
		if ( OtrOption.TraceErrors )
			terminate_errors();
		terminate_world();
		}
	return( status );
}

SWORD	translator_termination()
{
	(void) terminate_translation( 0 );
	if ( OtrOption.TraceErrors )
		terminate_errors();
	terminate_world();
	return((GlobalError?1:0));
}

SWORD	translate_line( lptr )
BPTR	lptr;
{
	return( line_translation( lptr ) );
}

SWORD	translator_options( optr )
BPTR	optr;
{
	return( analyse_translator_options( optr ) );
}

SWORD	translate_file( filename, options )
BPTR	filename;
BPTR	options;
{
	WORD	status;

	GlobalError = 0;
	initialise_text_messages();
	initialise_options();
	initialise_world();
	if ((status = translator_options( options )) != 0)
		return( status );
	else	return( source_translation( filename ) );

}

SWORD	translate_block( lptr )
BPTR	lptr;
{
	return( block_translation( lptr ) );
}

#endif	/* _TRDLL_C */
	/* -------- */

#ifndef	WIN32
#include "trtrace.c"
#endif

#endif	/* _TRMAIN_C */
	/* --------- */


