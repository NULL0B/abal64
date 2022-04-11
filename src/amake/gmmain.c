/*----------------------------------------------------------------------*/
/*									*/
/*		---------------------------------------			*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		---------------------------------------			*/
/*		Project		:	ABAL MAKE			*/
/*		Module		:	GMMAIN-C			*/
/*		Version		:	2.1c				*/
/*		Date		:	18/10/1994			*/
/*		---------------------------------------			*/
/*									*/
/*----------------------------------------------------------------------*/
#include "stdtypes.h"
#include "version.h"

#include "gmhead.h"
#include "allocate.h"
#include "gmfile.h"
#include "gmbib.h"
#include "gmgesmes.c"
#include "fnparser.h"

#define	MODULE_PROVISOIRE  "\r\n   Provisoire du 27/07/2006 "
#define	MODULE_IDENTITY    "genmake"

#define NULSYMBOL "  "
#define RULE_FIELD ": "
#define	QUOTE  '"'
#define LESSTHAN '<'
#define SPACE ' '
#define TABULATION '\t'
#define NEWLINE '\n'
#define RETURN '\r'
#define FAUX 0
#define VRAI 1
#define	SIMPLE_QUOTE 0x0027
#define	MAX_LINE_LENGTH	300

#ifndef	VMS
#define	ABAL_EXT_FLAG	"-s"
#define	ABAL_INC_FLAG	"-i"
#define	SYST_INC_FLAG	"-I"
#else
#define	ABAL_EXT_FLAG	"/S"
#define	ABAL_INC_FLAG	"/I"
#define	SYST_INC_FLAG	"/INCLUDE("
#endif

#define	DIEZ_USER_EXT	".def"
#define	DIEZ_USE_EXT	".apl"

#define	MASTER_SOURCE	1
#define	SLAVE_SOURCE	2

#ifndef UNIX
#define OPTION_FLAG_1 '-'
#define OPTION_FLAG_2  '/'
#else
#define OPTION_FLAG_1  '-'
#define OPTION_FLAG_2  '-'
#endif

#define	_GM_ABAL_SOURCE	1
#define	_GM_C_SOURCE	0

#define	FILETREE struct filetree XPTR
#define	PATHTREE struct pathtree XPTR
#define	CONSTREE struct constree XPTR

struct	constree {
	BPTR		name;
	BPTR		value;
	CONSTREE	suite;
	} XPTR consroot;

CONSTREE	deffroot;

WORD		GenMakeExitStatus;

struct	filetree {
	FILETREE	liste;
	FILETREE	tree;
	BPTR			filename;
	};

FILETREE Racine;
FILETREE RacineMaster;
WORD	line_length;
WORD	FoundType;
WORD	SourceMode;	
WORD	option;
WORD	niveau;
WORD	InhibitDuplicates=1;	
WORD	VerboseHelp;		/* Activates Verbose Help		*/
WORD	InclusionUsed;		/* Flag indicates inclusion used	*/
WORD	ExtensionAdded;		/* Flag indicates extension added	*/
BPTR	GenmakeId;		/* Current genmake identification	*/
BPTR	Binary;			/* Link result file name to generate	*/
BPTR	compiler;		/* Compiler definition			*/
BPTR	BibliOpt;		/* Library symbol value definition	*/
BPTR	CompiOpt;		/* Compile phase options		*/
BPTR	LinkOpt;		/* Link phase options			*/
BPTR	linker;			/* Linker defintion			*/
BPTR	PathPtr;		/* Current default path pointer		*/
BPTR	DefaultExt;		/* Current default extension pointer	*/
WORD	PathDex;		/* Search path list count		*/
BPTR	ObjGroupName;

WORD	Echo;
WORD	Debug;
WORD	Exturnal;
WORD	ObjFlag;
WORD	ObjGroup;
WORD	ElimDex;
BPTR	ElimGroup[ELIMINMAX];
BPTR	SearchPath[SEARCHMAX];
WORD	SearchDex;

#ifdef	VMS
#define	EXIT_VALUE 1
#else
#define	EXIT_VALUE 0
#endif

EXTERN	WORD	whoops;

FILEINFO	StreamInfo=(FILEINFO) 0;


WORD	is_option_indicator( c )
WORD	c;
{
	if ( c == OPTION_FLAG_1 ) return(1);
#ifndef	UNIX
	if ( c == OPTION_FLAG_2 ) return(1);
#endif
#ifdef	VMS
	if ( c == OPTION_FLAG_2 ) return(1);
#endif
	return(0);
}

void	StreamByte( c )
WORD	c;
{
	if ( c != RETURN ) {
		if ( c == NEWLINE )
			line_length = 0;
		else	line_length++;
		}

	/* Check for Stream Open */
	/* --------------------- */
	if ( StreamInfo != (FILEINFO) 0 ) {
		gm_putch( StreamInfo , c );
		}
	else	{
		llmf_co( c );
		}
	return;
}



void	StreamOut( msgptr )
BPTR	msgptr;
{
	while ( *msgptr != (BYTE) 0 ) {
		StreamByte( (WORD) *(msgptr++) );
		}
	return;
}

void	ResolvedStreamOut( symbptr )
BPTR	symbptr;
{
	BPTR	Substitute();
	if ( *symbptr == '$' )
		symbptr = Substitute( symbptr );
	if ( symbptr != (BPTR) 0 )
		StreamOut( symbptr );
	return;
}

void	SautLigne()
{
#ifndef	UNIX
#ifndef	VMS
	llmf_co(RETURN);
#endif
#endif
	llmf_co(NEWLINE);
}
		
void	LineFeed()
{
#ifndef	UNIX
#ifndef	VMS
	StreamByte(RETURN);
#endif
#endif
	StreamByte(NEWLINE);
}

void	check_line_length( msglen )
WORD	msglen;
{
	if (( line_length + msglen ) > MAX_LINE_LENGTH ) {
		StreamByte(SIMPLE_QUOTE);
		LineFeed();
		}
	return;
}

void	indentation(i)
WORD	i;
{
	WORD	x;

	if ( option & 16 ) {
		LineFeed();
		for (x = 0; x < (niveau+i); x++) {
			StreamOut((BPTR)"  ");
			}
		}
	else	{
		StreamByte(SPACE);
		}
}

void	liberate_constants( rptr )
CONSTREE	rptr;
{
	if ( rptr != (CONSTREE) 0 ) {
		liberate_constants( rptr->suite );
		liberate((BPTR) rptr->name );
		liberate((BPTR) rptr->value);
		liberate((BPTR) rptr );
		}
	return;
}

WORD	genmake_failure( result, thiserr )
WORD	result;
{
	BYTE	buffer[8];
	WORD	bindex;
	WORD	rindex;


	GenMakeExitStatus = thiserr;
	return( result );
}


/*
 *	A D D _ C O N S T A N T ( name , value )
 *	----------------------------------------
 *	Adds the constant 'name' with value 'value' to the list
 *	of constants to be generated as output
 *
 */

void	add_constant( name , value )
BPTR	name;
BPTR	value;
{
	CONSTREE	lroot;
	if ((lroot = (CONSTREE) allocate( sizeof(struct constree) )) != (CONSTREE) 0) {
		if ((lroot->name = (BPTR) allocate((strlen(name)+1))) != (BPTR) 0) {
			if ((lroot->value = (BPTR) allocate((strlen(value)+1))) != (BPTR) 0) {
				strcpy((BPTR)lroot->name,(BPTR)name);
				strcpy((BPTR)lroot->value,(BPTR)value);
				lroot->suite = consroot;
				consroot = lroot;
				return;
				}
			liberate((BPTR) lroot->name );
			}
		liberate((BPTR) lroot );
		}
	genmake_failure(0,27);
	return;
}

#ifdef	INTERPRET_DEFINITIONS

void	add_definition( name , value )
BPTR	name;
BPTR	value;
{
	CONSTREE	lroot;
	if ((lroot = (CONSTREE) allocate( sizeof(struct constree) )) != (CONSTREE) 0) {
		if ((lroot->name = (BPTR) allocate((strlen(name)+1))) != (BPTR) 0) {
			if ((lroot->value = (BPTR) allocate((strlen(value)+1))) != (BPTR) 0) {
				strcpy((BPTR)lroot->name,(BPTR)name);
				strcpy((BPTR)lroot->value,(BPTR)value);
				lroot->suite = deffroot;
				deffroot = lroot;
				mf_message((BPTR) name );
				llmf_co(SPACE);
				return;
				}
			liberate((BPTR) lroot->name );
			}
		liberate((BPTR) lroot );
		}
	genmake_failure(0,27);
	return;
}

#endif


void	liberate_file_list( listptr )
FILETREE listptr;
{
	if ( listptr != (FILETREE) 0 ) {
		if ( listptr->filename != (BPTR) 0 ) {
			if ( option & 2 ) {
				StreamByte(SPACE);
				StreamOut((BPTR)listptr->filename );
				}
			}
		liberate_file_list(listptr->liste);
		if ( listptr->filename != (BPTR) 0 ) {
			liberate( listptr->filename );
			}
		liberate( (BPTR) listptr );
			
		}
	return;
}

void	liberate_file_tree( treeptr )
FILETREE treeptr;
{
	if ( treeptr != (FILETREE) 0 ) {
		liberate_file_tree(treeptr->tree);
		if ( option & 2 ) {
			LineFeed();
			StreamOut((BPTR)treeptr->filename);
			StreamOut((BPTR)RULE_FIELD);
			}
		liberate_file_list(treeptr->liste);
		liberate((BPTR) treeptr->filename);
		liberate((BPTR) treeptr);
		}
	return;
}

WORD	gmcompare( xptr , yptr )
BPTR	xptr;
BPTR	yptr;
{
	while (( *xptr != 0 ) && ( *yptr != 0 )) {
		if ( *xptr != *yptr ) {
			return((WORD) ( *xptr - *yptr) );
			}
		else	{
			xptr++; yptr++;
			}
		}
	if (( *xptr == 0 ) && ( *yptr == 0 )) 
		return( 0 );
	return((WORD) ( *xptr - *yptr) );

}

BPTR	ConstValue( name )
BPTR	name;
{
	CONSTREE	lroot;
	lroot = consroot;

	while ( lroot != (CONSTREE) 0 ) {
		if ( gmcompare((BPTR) lroot->name , (BPTR) name ) == 0 ) {
			return((BPTR) lroot->value );
			}
		lroot = lroot->suite;
		}
	return((BPTR) 0);
}

BPTR	CheckPath( value )
BPTR	value;
{
	CONSTREE	lroot;
	lroot = consroot;

	while ( lroot != (CONSTREE) 0 ) {
		if ( gmcompare((BPTR) lroot->value , (BPTR) value ) == 0 ) {
			return((BPTR) lroot->name );
			}
		lroot = lroot->suite;
		}
	return((BPTR) 0);
}

WORD	is_include( filename )
BPTR	filename;
{
	FILETREE	ltree;
	FILETREE	llist;

	/* Establish Tree Root Pointer */
	/* --------------------------- */
	ltree = Racine;

	/* While Tree pointer is Valid */
	/* --------------------------- */
	while ( ltree != (FILETREE) 0 ) {

		/* Establish Liste Root Pointer */
		/* ---------------------------- */
		llist = ltree;

		/* While liste pointer is valid */
		/* ---------------------------- */
		while ((llist = llist->liste) != (FILETREE) 0) {

			/* If Valid Filename detected */
			/* -------------------------- */
			if ( llist->filename != (BPTR) 0 ) {

				/* If Filenames match */
				/* ------------------ */
				if ( gmcompare((BPTR) llist->filename,(BPTR) filename) == 0 ) {

					/* Then indicate TRUE is included */
					/* ------------------------------ */
					return(1);
					}
				}
			}

		/* Next Tree Root Pointer */
		/* ---------------------- */
		ltree = ltree->tree;
		}	

	/* Return FALSE not included */
	/* ------------------------- */
	return(0);
}


FILETREE	find_dependance_node( filename )
BPTR		filename;
{
	FILETREE	ltree;

	ltree = Racine;

	while ( ltree != (FILETREE) 0) {

		/* If Current Level Filename is the one saught */
		/* ------------------------------------------- */
		if ( gmcompare((BPTR) ltree->filename ,(BPTR) filename ) == 0 ) 
			break;

		ltree = ltree->tree;
		}
	return( ltree );
}

/*
 *	I S _ A L R E A D Y _ K N O W N ( filename )
 *	--------------------------------------------
 *	A root source must include each file only once
 *	This function will detect wether the file has already been included
 *	and hence eliminate the double inclusion
 *
 */

WORD	is_already_included( ltree , filename )
FILETREE	ltree;
BPTR		filename;
{
	FILETREE	xtree;

	while ( ltree != (FILETREE) 0 ) {

		/* If Current Level Filename is the one saught */
		/* ------------------------------------------- */
		if ( gmcompare((BPTR) ltree->filename ,(BPTR) filename ) == 0 ) 
			return(VRAI);

		/* Locate the dependance list for this entry */
		/* ----------------------------------------- */
		if ((xtree = find_dependance_node( ltree->filename )) != (FILETREE) 0)

			/* Check this entry for inclusion of this file */
			/* ------------------------------------------- */
			if ( is_already_included( xtree->liste ,(BPTR) filename ) == VRAI )
				return(InhibitDuplicates);

		ltree = ltree->liste;
		}

	/* File has not been already included */
	/* ---------------------------------- */
	return(FAUX);

}

WORD	isknown( filename )
BPTR	filename;
{
	FILETREE 	ltree;
	WORD		idtree;

	ltree = Racine;	idtree = 1;

	/* While not end of TREE structure */
	/* ------------------------------- */
	while ( ltree != (FILETREE) 0 ) {

		/* If Current Level Filename is the one saught */
		/* ------------------------------------------- */
		if ( gmcompare((BPTR) ltree->filename ,(BPTR) filename ) == 0 ) {

			/* Return the current Tree level Counter */
			/* ------------------------------------- */
			return( idtree );
			}
		else	{
			/* Collect Next tree Linkage pointer */
			/* --------------------------------- */
			idtree++;
			ltree = ltree->tree;
			}
		}
	return(0);
}

/*
 *	A D D _ N O D E _ T O _ T R E E ( filename )
 *	--------------------------------------------
 *	Attempts to add this node to the filename tree
 *
 */

WORD	add_node_to_tree( filename )
BPTR	filename;
{
	WORD		idtree;
	FILETREE	ltree;

	/* Test for Filename already known */
	/* ------------------------------- */
	if ((idtree = isknown((BPTR) filename)) == 0 ) {

		/* Attempt to allocate for this NODE */
		/* --------------------------------- */
		if ((ltree = (FILETREE) allocate( sizeof(struct filetree) ) ) != (FILETREE) 0) {

			/* Attempt to allocate for name storage */
			/* ------------------------------------ */
			if ((ltree->filename = (BPTR) allocate( (strlen((BPTR) filename) + 1))) != (BPTR) 0) {

				/* Store filename and initialise NODE */
				/* ---------------------------------- */
				strcpy((BPTR)ltree->filename,(BPTR)filename);
				ltree->tree = Racine;
				ltree->liste = (FILETREE) 0;
				Racine = ltree;

				/* Indicate Success */
				/* ---------------- */
				return(0);
				}
			liberate((BPTR) ltree );
			}
		if (( option & 4 ) == 0 ) {
			LineFeed();
			StreamOut((BPTR)TalkPtr[19]);
			/* Memory allocation error */
			LineFeed();
			}
		genmake_failure(0,27);
		return( 0 );
		}

	/* Return Pointer to NODE in tree */
	/* ------------------------------ */
	return( idtree );
}

void 	showtree( idtree , xniveau )
WORD	idtree;
WORD	xniveau;
{
	WORD	x;
	WORD	level;
	FILETREE 	ltree;

	ltree = Racine;

	/* Position to Tree Level */
	/* ---------------------- */
	for (x=1; x < idtree; x++) {
		ltree = ltree->tree;
		}
	if ( option & 1 ) {
		indentation(xniveau);
		check_line_length(strlen((BPTR) ltree->filename) );
		if ( option & 16 )
			ResolvedStreamOut((BPTR) ltree->filename );
		else	StreamOut((BPTR) ltree->filename );
		}
	while (( ltree = ltree->liste ) != (FILETREE) 0 ) {
		if ( ltree->filename != (BPTR) 0 ) {
			if (( level = isknown((BPTR) ltree->filename )) == 0 ) {
				if (option & 1 ) {
					indentation(xniveau);
					check_line_length(strlen((BPTR) ltree->filename) );
					if ( option & 16 )
						ResolvedStreamOut((BPTR) ltree->filename );
					else	StreamOut((BPTR) ltree->filename );
					}
				}
			else	{
				showtree( level , (xniveau+1) );
				}
			}
		}
	return;
}

/*
 *	E X T E N S I O N ( filename )
 *	------------------------------
 *	Checks for filename with extension and adds default 
 *	filename extension if required.
 *	Returns a pointer to the resulting filename string.
 */

BYTE	ExtenZone[128];		/* File name extension Buffer	*/

BPTR	add_extension( filename, mode )
BPTR	filename;
WORD	mode;
{
	WORD	l;

	/* Test for Extension not supplied */
	/* ------------------------------- */
	if ( fn_parser((BPTR) filename , (BPTR) ExtenZone , _FILE_EXTENSION ) == 0 ) {
		
		l = fn_parser((BPTR) filename , (BPTR) ExtenZone , _NO_EXTENSION );

		switch ( mode ) {
			case 0 :	
				if ( DefaultExt != (BPTR) 0 ) {
					strcpy((BPTR) &ExtenZone[l], (BPTR) DefaultExt );
					l = strlen((BPTR) ExtenZone);
					ExtensionAdded = VRAI;
					}
				break;
			case 1 :
				strcpy((BPTR) &ExtenZone[l], (BPTR) DIEZ_USER_EXT );
				l = strlen((BPTR) ExtenZone );
				break;
			case 2 :
				strcpy((BPTR) &ExtenZone[l], (BPTR) DIEZ_USE_EXT );
				l = strlen((BPTR) ExtenZone );
			}			

		l = fn_parser((BPTR) filename , (BPTR) &ExtenZone[l] ,_SYSTEM_SUPPLIMENT );
		}

	else	l = fn_parser((BPTR) filename , (BPTR) ExtenZone, _ENTIRE_FILE_SPEC );

	return((BPTR) ExtenZone );

}

void	ensure_path_terminated( pptr , l )
BPTR	pptr;
WORD	l;
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
	if ( *pptr  != '/' ) {
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

BYTE	PathZone[128];		/* Constructed filename buffer	*/
WORD	CaseConvert=0;

VOID	InitialiseCaseConvertor()
{
#ifdef	UNIX
	BPTR	eptr;
	if (!( eptr = getenv( "ABALANFC" ) ))
		return;
	else if ( *(eptr++) != '=' )
		return;
	else	{
		CaseConvert = *eptr;
		return;
		}
#else
	return;
#endif

}

BPTR	PathManager( filename , mode )
BPTR	filename;
WORD	mode;			/* 0 : Include 1 : User : 2 Class Library */
{
	WORD	x;
	WORD	y;
	WORD	l;

	switch ( CaseConvert ) {
		case	0	:	break;
		case	'U'	:	// upper
		case	'u'	:	// -----
			for ( y=0; *(filename+y) != 0; y++ )
				if (( *(filename+y) >= 'a' )
				&&  ( *(filename+y) <= 'z' ))
					*(filename+y) = ((*(filename+y) - 'a') + 'A');
			break;

		case	'l'	:	// lower
		case	'L'	:	// ----r
			for ( y=0; *(filename+y) != 0; y++ )
				if (( *(filename+y) >= 'A' )
				&&  ( *(filename+y) <= 'Z' ))
					*(filename+y) = ((*(filename+y) - 'A') + 'a');
			break;


		}
	/* Avoid Implicite include Path extensions */
	/* --------------------------------------- */
	if ( *filename == LESSTHAN ) 
		return( filename );
	
	if ( *filename == QUOTE ) 
		filename++;

	if ((x = strlen((BPTR) filename)) > 0 ) {

		if ( *(filename + x - 1) == QUOTE )
			*(filename + x - 1) = (BYTE) 0;

		/* Test for Ressource or Network Node Specified */
		/* -------------------------------------------- */
		if ( fn_parser( (BPTR) filename , (BPTR) PathZone , ( _NETWORK_NODE_NAME | _DEVICE_NAME ) ) != 0 )

			/* File name preceded by an Ressource mnemonic */
			/* ------------------------------------------- */
			return((BPTR) add_extension((BPTR) filename, mode ) );
		
		/* Check to see if Default Path Name May be Added */
		/* ---------------------------------------------- */
		if ( *filename != CHEMINSEP ) { 

			/* Check for Default path exists */
			/* ----------------------------- */
			if ( PathPtr   != (BPTR) 0  ) { 

				/* Add the Default Path */
				/* -------------------- */
				strcpy((BPTR) PathZone, (BPTR) PathPtr);
				strcpy((BPTR) &PathZone[ strlen((BPTR) PathZone) ], (BPTR) filename );
				}
			else	strcpy((BPTR) PathZone, (BPTR) filename );

			if ( Access( add_extension((BPTR) PathZone, mode) , 0 , 0 )== 0 )

				/* Return after Extension Checking */
				/* ------------------------------- */
				return((BPTR) add_extension((BPTR) PathZone, mode ));

			/* Now Check for Default -D Path declarations */
			/* ------------------------------------------ */
			x = 0;
			while ( x < SearchDex ) {

				strcpy((BPTR) PathZone, (BPTR) SearchPath[x]);

				if ((l = strlen((BPTR) PathZone)) != 0 )

					ensure_path_terminated( (BPTR) & PathZone[(l - 1)] , l );

				/* Add filename to Path information */
				/* -------------------------------- */
				strcpy((BPTR) &PathZone[ strlen((BPTR) PathZone) ], (BPTR) filename );

				/* Test for existance after adding extension */
				/* ----------------------------------------- */
				if ( Access( add_extension((BPTR) PathZone, mode) , 0 ,0 )== 0 ) {

					InclusionUsed = VRAI;

					/* Return after Extension Checking */
					/* ------------------------------- */
					return((BPTR) add_extension((BPTR) PathZone, mode ));
	
					}
					x++;

				}
			}
		}
	/* Return after extension concatenation */
	/* ------------------------------------ */
	return((BPTR) add_extension( (BPTR) filename, mode));
}

FILEINFO dependance_file( filename , master_slave_status )
BPTR	filename;
WORD	master_slave_status;
{
	WORD	x;
	WORD	idtree;
	FILEINFO lptr;
	
	lptr = (FILEINFO) 0;


	if ( *filename != LESSTHAN ) {

		if ((idtree = add_node_to_tree((BPTR) filename )) == 0 ) {
			if ((lptr = gm_open((BPTR) filename)) != (FILEINFO) 0 ) {
				if ( option & 1 ) {
					indentation(0);
					if ( option & 16 )
						ResolvedStreamOut((BPTR) filename );
					else	StreamOut((BPTR) filename );
					}
				}
			}
		else	{
			showtree( idtree , 1 );
			}
		}
	else	{
		if ( option & 8 ) {
			if ( option & 1 ) {
				indentation(0);
				if ( option & 16 )
					ResolvedStreamOut((BPTR) filename );
				else	StreamOut((BPTR) filename );
				}
			add_node_to_tree((BPTR) filename);
			}
		}
	if ( master_slave_status == MASTER_SOURCE )
		RacineMaster = Racine;

	return( lptr );
}

/*
 *	A D D _ I N C L U S I O N ( filename , liste )
 *	----------------------------------------------
 *	Adds the 'filename' to the left of the linked 'liste'
 *
 */

FILETREE add_inclusion( filename , liste )
BPTR		filename;
FILETREE 	liste;
{
	int	x;

	/* Check for system include directory */
	/* ---------------------------------- */
	if ( *filename != LESSTHAN ) {
		if ( *filename == QUOTE ) 
			filename++;

		if ((x = strlen((BPTR) filename)) > 0 )
			if ( *(filename + x - 1) == QUOTE )
				*(filename + x - 1) = (BYTE) 0;
		}	

	else if (( option & 8 ) == 0 )
		return( liste );


	/* Attempt to allocate NODE structure */
	/* ---------------------------------- */
	if ((liste->liste = (FILETREE) allocate( sizeof(struct filetree) )) != (FILETREE) 0 ) {

		/* Attempt to allocate storage for name */
		/* ------------------------------------ */
		if ((liste->liste->filename = (BPTR) allocate( (strlen(filename)+1) )) != (BPTR) 0) {

			/* Storage name to storage */
			/* ----------------------- */
			strcpy((BPTR) liste->liste->filename,(BPTR) filename);

			/* Initialise NODE structure */
			/* ------------------------- */
			liste->liste->tree = (FILETREE) 0;
			liste->liste->liste = (FILETREE) 0;
			liste = liste->liste;
			return( liste );
			}
		else	liberate( (BPTR) liste->liste );
		}
	genmake_failure(0, 27);
	return( liste );
}

/*
 *	A D D G R O U P ( grouptr )
 *	---------------------------
 * 	Adds a new Group of files to the elimination liste.
 * 	Option '-z' : the elimination groups allow the elimination
 *	of certain files from the result dependance stream.
 */

WORD	add_elimination_group( gptr )

				/* ---------------------------------------- */
BPTR	gptr;			/* Pointer to elimination group to be added */
				/* ---------------------------------------- */
{
	WORD	l;

	/* Check for Elimination group limit exceeded */
	/* ------------------------------------------ */
	if ( ElimDex < ELIMINMAX ) {

		/* Remove white space and quotes */
		/* ----------------------------- */
		while (( *gptr == SPACE ) || ( *gptr == QUOTE )) 
			gptr++;

		/* If not an empty string */
		/* ---------------------- */
		if ( *gptr != 0 ) {

			/* Remove trailing quote */
			/* --------------------- */
			if ( *(gptr + (l = strlen( gptr ))) == QUOTE ) 
				*(gptr +l) = 0;

			/* Store elimination group pointer */
			/* ------------------------------- */
			ElimGroup[ElimDex] = gptr;

			/* Adjust elimination group count */
			/* ------------------------------ */
			ElimDex++;
			}

		/* Indicate Success */
		/* ---------------- */
		return(0);
		}
	/* Failure : Too Many Elimination Groups */
	/* ------------------------------------- */
	return(genmake_failure(1,56));
}


/*
 *	E L M I N A T I O N ( fptr )
 *	----------------------------
 *	Checks to see if the filename 'fptr' is a member of an
 *	elimination group and should thus be ignored
 *
 */

WORD	Elimination( fptr )
BPTR	fptr;
{
	WORD	x;

	/* Scan list of elimination groups */
	/* ------------------------------- */
	for (x = 0; x < ElimDex; x++) 

		/* If file is a member of current group */
		/* ------------------------------------ */
		if ( wildcomp( fptr , ElimGroup[x] ) == 0 ) 

			/* Indicate elimination required */
			/* ----------------------------- */
			return( VRAI );

	/* Test for already included */
	/* ------------------------- */
	return(is_already_included(RacineMaster->liste , fptr ));

}

void	set_abal_source_type( stype )
WORD	stype;
{
	FoundType = stype;

	if ( VerboseHelp) {

		switch (FoundType) {

			case 0  : mf_message((BPTR) "ABAL Source type : Unknown ");
				  break;	 

			case 1  : mf_message((BPTR) "ABAL Source type : Module  ");
				  break;	 

			case 2  : mf_message((BPTR) "ABAL Source type : Program ");
				  break;	 

			default : mf_message((BPTR) "ABAL Source type : Other   ");
				  break;	 

			}
		SautLigne();
		}
	return;
}

#ifdef	ABAL21
FILETREE	handle_class_library(pere, liste )
FILEINFO 	pere;
FILETREE	liste;
{
	BPTR	wptr;

	/* Repeat word retrieval until non-blank */
	/* ------------------------------------- */
	do	{

		/* Get Next Word and check for Error */
		/* --------------------------------- */
		if ((wptr = gm_getw( pere )) == (BPTR) 0)

			return( liste );
		}
	while ( strlen((BPTR) wptr) == 0 );

	/* Perform Path Info Analysis */
	/* -------------------------- */
	wptr = (BPTR) PathManager((BPTR) wptr , 2 );
			
	/* Add this filename to current linked list */
	/* ---------------------------------------- */
	return((liste = add_inclusion(wptr , liste)));
}
#endif

void	dependance_trace( pere , liste )
FILEINFO 	pere;
FILETREE	liste;
{
	BPTR	wptr;
	FILEINFO rootptr;
	WORD	x,y,i;
	WORD	nest;
	WORD	c;

	/* Adjust to new level */
	/* ------------------- */
	niveau++;

	/* While not End of Current file */
	/* ----------------------------- */
	while ((wptr = gm_getw( pere )) != (BPTR) 0 ) {

		/* If not an empty string */
		/* ---------------------- */
		if ( strlen(wptr) > 0 ) {

			switch ( SourceMode ) {

				case _GM_C_SOURCE :

				/* Check for 'C' Comment String */
				/* ---------------------------- */
				if (( *wptr == '/' ) && ( *(wptr + 1) == '*' )) {

					/* Init Nested comment Count */
					/* ------------------------- */
					nest = 1;
					wptr += 2;
					c = *(wptr++);
					while ( c > 1 ) {
						switch ( c ) {
							case '/' : 
								if (( c = *(wptr++)) == '*') {
									nest++;
									break;
									}
								continue;
							case '*' :
								if (( c = *(wptr++)) == '/' ) {
									nest--;
									if ( nest == 0 ) { c = 1; continue; }
									break;
									}
								continue;
							}
						c = *(wptr++);
						}
					if ( c == 0 ) {
						c = gm_getch( pere );
						while (c != 0 ) {
							switch ( c ) {
								case '/' :
									if ((c = gm_getch( pere )) == '*') {
										nest++;
										break;
										}
	 								continue;
	
								case '*' :
									if ((c = gm_getch( pere )) == '/') {
										nest--;
										if ( nest == 0 ) { c = 0; continue; }
										break;
										}
	 								continue;
								}
							c = gm_getch( pere );
							}
						/* Go Around Again */
						/* --------------- */
						continue;
						}
				     case _GM_ABAL_SOURCE :

						/* ABAL Source comments */
						/* -------------------- */
						if ( *wptr == ';' ) {
							gm_finline( pere );
							continue;
							} 
						else if ( *wptr == '*' ) {
							gm_finline( pere );
							continue;
							} 
				     }
				}
			
			/* Convert to Lower Case */
			/* --------------------- */
			i = 0;
			while ( *(wptr + i) != (BYTE) 0 ) {

				if (( *(wptr +i) >= 'A' ) && ( *(wptr +i) <= 'Z' )) {
					*(wptr +i) |= (BYTE) 0x0020;
					}
				i++;
				}

			/* Detection of ABAL Source type : PROGRAM / MODULE */
			/* ------------------------------------------------ */
			/* Modules generate objects , Programs Generate AT  */
			/* Translated files unless they contain EXTERNal    */
			/* References in which case they generate objects   */
			/* ------------------------------------------------ */
			if ( SourceMode == _GM_ABAL_SOURCE ) {

				if ( FoundType != 1 ) {

					/* Test for PROGRAM or MODULE */
					/* -------------------------- */
					if ( gmcompare((BPTR)wptr,(BPTR) TalkPtr[21])  == 0 )
						set_abal_source_type(2);
					else if ( gmcompare((BPTR)wptr,(BPTR) TalkPtr[22]) == 0 ) {
						set_abal_source_type(1);
						}
					}
				else if ( FoundType == 2 ) {
						if ( gmcompare((BPTR)wptr,(BPTR) TalkPtr[23]) == 0 )
							set_abal_source_type(1);

						}
				}
	

			/* Compare against Test word */
			/* ------------------------- */
			if ( gmcompare((BPTR)wptr,(BPTR) TalkPtr[24] ) == 0 ) {

				/* Repeat word retrieval until non-blank */
				/* ------------------------------------- */
				do	{

					/* Get Next Word and check for Error */
					/* --------------------------------- */
					if ((wptr = gm_getw( pere )) == (BPTR) 0) {

						/* Restore callers level count and Return */
						/* -------------------------------------- */
						niveau--; return;
						}
					}
				while ( strlen((BPTR) wptr) == 0 );

				/* Perform Path Info Analysis */
				/* -------------------------- */
				wptr = (BPTR) PathManager((BPTR) wptr , 0);
			
				/* Test for Elimination Group file */
				/* ------------------------------- */
				if ( Elimination( wptr ) == FAUX ) {

					/* Add this filename to current linked list */
					/* ---------------------------------------- */
					liste = add_inclusion(wptr , liste);

					/* Attempt to open or locate file */
					/* ------------------------------ */
					if ((rootptr = dependance_file(wptr,SLAVE_SOURCE)) != (FILEINFO) 0) { 
	
						/* Recursivly evaluate file */
						/* ------------------------ */
						dependance_trace( rootptr , Racine );

						/* Close the file now */
						/* ------------------ */
						gm_close( rootptr );
						}
					}
				}
			else	{
				/* If Parsing ABAL source file */
				/* --------------------------- */
				if ( SourceMode == _GM_ABAL_SOURCE ) {	
#ifdef	ABAL21
					/* Watch out for Class libraries */
					/* ----------------------------- */
					if ( gmcompare((BPTR)wptr,(BPTR) TalkPtr[26] ) == 0 ) {
						liste = handle_class_library(pere,liste);
						continue;
						}
					else 
#endif
					/* Watch out for #USER statements */
					/* ------------------------------ */
						if ( gmcompare((BPTR)wptr,(BPTR) TalkPtr[25] ) == 0 ) {

						/* Repeat word retrieval until non-blank */
						/* ------------------------------------- */
						do	{

							/* Get Next Word and check for Error */
							/* --------------------------------- */
							if ((wptr = gm_getw( pere )) == (BPTR) 0) {

								/* Restore callers level count and Return */
								/* -------------------------------------- */
								niveau--; return;
								}
							}
						while ( strlen((BPTR) wptr) == 0 );

						/* Perform Path Info Analysis */
						/* -------------------------- */
						wptr = (BPTR) PathManager((BPTR) wptr , 1 );
			
						/* Add this filename to current linked list */
						/* ---------------------------------------- */
						liste = add_inclusion(wptr , liste);

						/* Attempt to open or locate file */
						/* ------------------------------ */
						if ((rootptr = dependance_file(wptr,SLAVE_SOURCE)) != (FILEINFO) 0) { 

							/* Recursivly evaluate file */
							/* ------------------------ */
							dependance_trace( rootptr , Racine );

							/* Close the file now */
							/* ------------------ */
							gm_close( rootptr );
							}
						}
					}
				}
			}
		}

	/* Restore callers level count and Return */
	/* -------------------------------------- */
	niveau--; return;
}

void	Tabulation(n)
WORD	n;
{
	while ( n > 0 ) {
		StreamByte(TABULATION);
		n--;
		}
	StreamOut((BPTR)RULE_FIELD);
	return;
}

/*
 *	B A N N E R ( )
 *	---------------
 *	Display of GENMAKE's identification and help information
 *
 */

void	banner()
{
	/* Display banner */
	/* -------------- */
	StreamOut((BPTR)"   ");
	StreamOut((BPTR)TalkPtr[1]          ); 
	StreamOut((BPTR) MODULE_VERSION     );
	StreamOut((BPTR) MODULE_PROVISOIRE  );
	StreamOut((BPTR) MODULE_ENVIRONMENT );
	StreamOut((BPTR) MODULE_COPYRIGHT   );
	LineFeed();

	StreamOut((BPTR)"   ");
	StreamOut((BPTR)TalkPtr[2]);		/* "Syntax" */ 
	StreamOut((BPTR)" : genmake ["); 
	LineFeed();

	StreamOut((BPTR)"   -a"); Tabulation(3);
	StreamOut((BPTR)TalkPtr[3]); /* All include files displayed " 	*/
	LineFeed();

	StreamOut((BPTR)"   -b[t][o]"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[4]); /* Source type ABAL else C "	*/
	LineFeed();

	StreamOut((BPTR)"   -c<");
	StreamOut((BPTR)TalkPtr[2]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[5]); /* Compiler phase syntax specification "	*/
	LineFeed();

	StreamOut((BPTR)"   -d<");
	StreamOut((BPTR)TalkPtr[49]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[6]); /* Include structure to <filename> 	*/
	LineFeed();

	StreamOut((BPTR)"   -e"); Tabulation(3);
	StreamOut((BPTR)TalkPtr[7]); /* Echos all sources to StdOut 	*/
	LineFeed();

	StreamOut((BPTR)"   -f<");
	StreamOut((BPTR)TalkPtr[49]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[8]); /* Formated indentation structure 	*/
	LineFeed();

	StreamOut((BPTR)"   -i<");
	StreamOut((BPTR)TalkPtr[2]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[9]); /* Include search path 	*/
	LineFeed();

	StreamOut((BPTR)"   -l<");
	StreamOut((BPTR)TalkPtr[2]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[10]); /* Link phase syntax specification  */
	LineFeed();

	StreamOut((BPTR)"   -m<");
	StreamOut((BPTR)TalkPtr[49]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[11]); /* Generate MAKEFILE to <filename>  */
	LineFeed();

	StreamOut((BPTR)"   -o[l][b]<");
	StreamOut((BPTR)TalkPtr[2]);
	StreamOut((BPTR)">"); Tabulation(1);
	StreamOut((BPTR)TalkPtr[12]); /* Compiler options specification */
	LineFeed();

	StreamOut((BPTR)"   -r<");
	StreamOut((BPTR)TalkPtr[49]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[13]); /* Generate Linker result as <filename> */
	LineFeed();

	StreamOut((BPTR)"   -s"); Tabulation(3);
	StreamOut((BPTR)TalkPtr[14]); /* Supress transient error messages  */
	LineFeed();

	StreamOut((BPTR)"   -x"); Tabulation(3);
	StreamOut((BPTR)TalkPtr[15]); /* Supress constant generation  */
	LineFeed();

	StreamOut((BPTR)"   -y<");
	StreamOut((BPTR)TalkPtr[48]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[16]); /* Generate Object Group Symbole */
	LineFeed();

	StreamOut((BPTR)"   -z<");
	StreamOut((BPTR)TalkPtr[2]);
	StreamOut((BPTR)">"); Tabulation(2);
	StreamOut((BPTR)TalkPtr[17]); /* Declare Elimination group */
	LineFeed();

	StreamOut((BPTR)"                    ][");
	StreamOut((BPTR)TalkPtr[18]); /* file1 ... fileN */
	StreamOut((BPTR)"] ");
	LineFeed();
	return;
}

/*
 *	I S _ S E P A R A T O R ( c )
 *	-----------------------------
 *	Test whether 'c' is a legal OS dependant filename/ extension
 *	separator.
 *
 */

WORD	is_separator( c )
WORD	c;
{
	if ( c == '.' ) return(0);
#ifdef	PRL
	if ( c == '-' ) return(0);
#endif
	return(-1);
}

WORD	bytecount( filename )
BPTR	filename;
{
	WORD	i;
	i = 0;
	while ( *(filename + i) != (BYTE) 0 ) { i++; }
	return(i);
}

BYTE	PathTrav[64];

/*
 *	G E N _ P A T H _ S Y M B ()
 *	----------------------------
 *	Generation of the next PATH symbol ( $(SP01) etc )
 *	
 */

BPTR	generate_path_symbol()
{
	strcpy((BPTR) PathTrav, (BPTR) TalkPtr[35] );
	PathDex++;
	if ((PathDex & 0x00F0) > 0x0090 ) {
		PathTrav[4] = (BYTE) ((((PathDex & 0x00F0) >> 4) - 9) | 0x0040);
		}
	else	{
		PathTrav[4] = (BYTE) (((PathDex & 0x00F0) >> 4) | 0x0030);
		}
	if ((PathDex & 0x000F) > 0x0009 ) {
		PathTrav[5] = (BYTE) (((PathDex & 0x000F)  - 9) | 0x0040);
		}
	else	{
		PathTrav[5] = (BYTE) ((PathDex & 0x000F) | 0x0030);
		}
	PathTrav[6] = ')'; PathTrav[7] = (BYTE) 0;
	return((BPTR) PathTrav );
}

/*
 *	E S T A B L I S H _ P A T H ( filename )
 *	----------------------------------------
 *	Collects and converts to PATH_SYMBOL any provided path information.
 *	Collects and establishs as the default any filename extension. 
 *	Returns a pointer to the resulting filename string.
 *
 */

BYTE	ThisTerm[16];
BYTE	ThisPath[128];

BPTR	establish_path( filename )
BPTR	filename;
{
	WORD	len;
	BYTE	c;
	BPTR	PathSymb;

	PathPtr    = (BPTR) 0;
	DefaultExt = (BPTR) 0;

	/* Determine wether path information exists */
	/* ---------------------------------------- */
	if (fn_parser((BPTR) filename , (BPTR) ThisPath ,( _PATHPART_ONLY | 0x0100)) != 0) {

		/* Path information exists in 'THISPATH' */
		/* ------------------------------------- */
		/* Scan Path Constants Table for Doubles */
		/* ------------------------------------- */
		if ((PathPtr = CheckPath((BPTR) ThisPath )) == (BPTR) 0 ) 

			/* Generate new Path Symbol and Save in Constants Table */
			/* ---------------------------------------------------- */
			add_constant((BPTR)(PathPtr = generate_path_symbol()),(BPTR) ThisPath );

		/* Copy resulting Path symbol to FileName construction zone */
		/* -------------------------------------------------------- */
		strcpy((BPTR) ThisPath, (BPTR) PathPtr);
			
		/* Transfer filename portion to filename construction zone */
		/* ------------------------------------------------------- */
		(void) fn_parser((BPTR) filename,(BPTR) &(ThisPath[strlen((BPTR) ThisPath)]), _FILEPART_ONLY );

		/* Point to New filename */
		/* --------------------- */
		filename = (BPTR) ThisPath;

		}

	/* Test for filename extension provided */
	/* ------------------------------------ */
	if (fn_parser((BPTR) filename , (BPTR) ThisTerm , (_FILE_EXTENSION | 0x0100)) != 0)

		/* Establish current default Extension */
		/* ----------------------------------- */
		DefaultExt = (BPTR) ThisTerm;

	/* Return to pointer to filename */
	/* ----------------------------- */
	return((BPTR) filename ); 
  
}

/*
 *	O B J E C T _ F I L E N A M E ( filename )
 *	------------------------------------------
 *	Generation of the object extended version of the filename
 *	string provided
 *
 */

void	object_file( filename )
BPTR	filename;
{
	WORD	l,p;
	BYTE	c;
	BYTE	object_name[64];
	
	/* Remove Filename Portion of string */
	/* --------------------------------- */
	if ((l = fn_parser((BPTR) filename ,(BPTR) object_name, _FILE_NAME)) == 0) 
		return;

	/* Ensure correctly terminated */
	/* --------------------------- */
	object_name[ l ] = 0;	


	/* Display Target filename */
	/* ----------------------- */
	if ( ObjFlag == 0 ) {
		check_line_length( (strlen((BPTR) TalkPtr[36])+strlen((BPTR) object_name)+strlen((BPTR) TalkPtr[39])) );
		StreamOut((BPTR) TalkPtr[36] );
		StreamOut((BPTR) object_name );
		StreamOut((BPTR) TalkPtr[39] );
		}
	else	{
		check_line_length( (strlen((BPTR) TalkPtr[37])+strlen((BPTR) object_name)+strlen((BPTR) TalkPtr[40])) );
		StreamOut((BPTR) TalkPtr[37] );
		StreamOut((BPTR) object_name );
		StreamOut((BPTR) TalkPtr[40] );
		}

	/* Return to Caller */
	/* ---------------- */
	return;
}

/*
 *	F I N D _ F I R S T ( file_selection )
 *	--------------------------------------
 *	This function and it's counterpart 'find_next' will be fully
 *	implimented in future versions to handle wild card specifiers
 *	recieved in the command line 'genmake ex*.c'
 *
 */
BPTR	FindCritere;
BPTR	RootCritere;

BPTR	find_first( filecrit )
BPTR	filecrit;
{
	WORD	mode;
	WORD	l;
	BPTR	lptr;
#ifdef	GM_DEBUG
	printf("\n Find_first(%s) = ",filecrit);
#endif
	/* Initialise find mechanism */
	/* ------------------------- */
	if ((l = strlen((BPTR) filecrit)) == 0 )
		return((BPTR) 0);
	
	if ((RootCritere = (BPTR) allocate((l + 1))) == (BPTR) 0) {
		genmake_failure(0,27);
		return((BPTR) 0);
		}
	
	memcpy((BPTR) RootCritere , (BPTR) filecrit , (l + 1));

	FindCritere = RootCritere;

	/* Remove any preceding white space */
	/* -------------------------------- */
	while (( *FindCritere ) && (( *FindCritere == ' ') || ( *FindCritere == '\t' ) || (*FindCritere == ',') || (*FindCritere == '"')))
		FindCritere++;

	lptr = FindCritere;

	/* Scan till separator or end of string */
	/* ------------------------------------ */
	while (( *FindCritere ) && ( *FindCritere != ',') && ( *FindCritere != ' ') && (*FindCritere != '"')) {
		FindCritere++;
		mode = VRAI;
		}

	/* Terminate string if required */
	/* ---------------------------- */
	if ( *FindCritere )
		*(FindCritere++) = 0;

	if ( mode == VRAI ) {
#ifdef	GM_DEBUG
		printf(" %s \n",lptr);
#endif
		return( lptr );
		}
	else	{
#ifdef	GM_DEBUG
		printf(" No find \n");
#endif
		return((BPTR) 0);
		}
}

BPTR	find_next( filecrit )
BPTR	filecrit;
{
	BPTR	lptr;
#ifdef	GM_DEBUG
	printf("\n Find_next(%s) = ",FindCritere);
#endif
	/* Remove any preceding white space */
	/* -------------------------------- */
	while (( *FindCritere ) && (( *FindCritere == ' ') || ( *FindCritere == '\t' ) || (*FindCritere == ',') || (*FindCritere == '"')))
		FindCritere++;

	/* Watch out for end of string */
	/* --------------------------- */
	if ( *FindCritere == 0 ) {
#ifdef	GM_DEBUG
		printf(" No more (EOS after white space)\n");
#endif
		liberate((BPTR) RootCritere );
		return((BPTR) 0);
		}

	/* Keep current pointer */
	/* -------------------- */
	lptr = FindCritere;

	/* Scan till separator or end of string */
	/* ------------------------------------ */
	while (( *FindCritere ) && ( *FindCritere != ',') && ( *FindCritere != ' ') && ( *FindCritere != '"') )
		FindCritere++;

	/* Terminate string if required */
	/* ---------------------------- */
	if ( *FindCritere ) 
		*(FindCritere++) = 0;

#ifdef	GM_DEBUG
	printf(" %s \n",lptr );
#endif

	/* Return pointer to string */
	/* ------------------------ */
	return((BPTR) lptr );

}

/*
 *	D I S P L A Y _ C O N S ( table_root )
 *	--------------------------------------
 *	Displays or outputs the constant table indentifed by 'table_root'
 *
 */

void	display_constants( lroot )
CONSTREE	lroot;
{
	BYTE	c;
	WORD	i;

	if ( lroot != (CONSTREE) 0 ) {
		display_constants( lroot->suite );
		LineFeed();
		i = 2;
		while (( *(lroot->name + i) != (BYTE) 0 ) && ( *(lroot->name + i) != ')' )) { i++; }
		c = *(lroot->name + i);
		*(lroot->name + i) = (BYTE) 0;
		StreamOut((BPTR) (lroot->name + 2));			
		*(lroot->name + i) = c;
		StreamOut((BPTR) " = ");
		StreamOut((BPTR) lroot->value ); 
		}
	return;
}


void	force_make_now()
{
	LineFeed(); 
	StreamByte('!');
	StreamOut((BPTR)TalkPtr[47]); 	/* MAKE */
	return;
}

void	generate_compiler_action()
{
	StreamByte(TABULATION);
	StreamOut((BPTR) TalkPtr[30] );	/* $(COMPILE) */
	StreamByte(SPACE);
	StreamOut((BPTR) TalkPtr[31] );	/* $(OPTION)  */
	StreamByte(SPACE);

	/* Watch out for Translator Action */
	/* ------------------------------- */
	if ( SourceMode == _GM_ABAL_SOURCE ) {

		/* Specify explicite Result filename */
		/* --------------------------------- */
		StreamOut((BPTR) "-d$@ ");
		}

	return;
}

void	add_compiler_options()
{
	if ( strlen((BPTR) CompiOpt) != 0 ) 
		add_constant((BPTR) TalkPtr[31] ,(BPTR) CompiOpt);
	else	
		add_constant((BPTR) TalkPtr[31],(BPTR) NULSYMBOL);
}

BYTE	CompilerOptions[16000];

void	establish_compiler_options()
{
	CompilerOptions[0] = 0;
	if ( CompiOpt != (BPTR) 0 )
		strcpy((BPTR) CompilerOptions ,(BPTR) CompiOpt );	

	/* Establish Options pointer */
	/* ------------------------- */
	CompiOpt = (BPTR) CompilerOptions;
}

void	genmake_warning( message_id , supliment )
WORD	message_id;
BPTR	supliment;
{
	LineFeed();
	StreamOut((BPTR) GenmakeId );
	StreamByte(':');
	StreamOut((BPTR) TalkPtr[message_id] );
	if ( supliment != (BPTR) 0 ) {
		StreamByte(SPACE);
		StreamOut((BPTR) supliment );
		}
	LineFeed();
	return;
}


/*
 *	M A I N ( arg_count , arg_vectors )
 *	-----------------------------------
 *	Entry point from and Exit point to OS
 *
 */

main( argc , argv )
WORD	argc;
char *  argv[];
{
	WORD	x;
	WORD	i,argdex;
	FILEINFO rootptr;
	BPTR	RootFile;
	WORD	idtree;
	BPTR	ObjVal;
	WORD	ObjectStatus;

	start_xallocate();
	InitialiseCaseConvertor();

#ifdef	PRL
	GenmakeId = (BPTR) "genmake";
#else
	GenmakeId = (BPTR) argv[0];
#endif
	GenMakeExitStatus = EXIT_VALUE;

	Debug = 0;

	ExtensionAdded = FAUX;
	InclusionUsed  = FAUX;

	/* Initialise Message Tables */
	/* ------------------------- */
	TalkWork();

	/* Indicate No Stream */
	/* ------------------ */
	StreamInfo = (FILEINFO) 0;

#ifdef PRL
	LineFeed();
#endif

	/* No args then display banner and Exit */
	/* ------------------------------------ */
	if ( argc == 1 ) { banner(); return(flush_xallocate(EXIT_VALUE)); }

	/* Initialise Global Variables */
	/* --------------------------- */
	consroot  	= (CONSTREE) 0;
	deffroot  	= (CONSTREE) 0;
	Racine    	= (FILETREE) 0; 
	Binary    	= (BPTR) 0;
	PathPtr   	= (BPTR) 0; 
	option    	= 0; 
	argdex    	= 1; 
	niveau    	= 0; 
	Echo      	= 0; 
	SourceMode  	= _GM_C_SOURCE; 
	FoundType 	= 0;
	PathDex   	= 0; 
	Exturnal  	= 0; 
	ObjGroup  	= 0;
	ElimDex   	= 0; 
	ObjFlag   	= 0;
	SearchDex 	= 0;
	ObjectStatus	= 0;

	/* Establish default compilation and link constants */
	/* ------------------------------------------------ */
	compiler = (BPTR) TalkPtr[41];	/* cc -c */
	linker   = (BPTR) TalkPtr[42];  /* cc */
#ifdef	UNIX
	ObjVal   = (BPTR) TalkPtr[45];	/* .o	 */
#else
	ObjVal   = (BPTR) TalkPtr[53];	/* .obj for VMS PRL and DOS (1.4b) */
#endif
	CompiOpt = (BPTR) 0;
	LinkOpt  = (BPTR) 0;
	BibliOpt = (BPTR) 0;
	VerboseHelp = 0;

	/* Analyse arguaments for OPTIONS */
	/* ------------------------------ */
	while ((is_option_indicator( *(argv[argdex]) ) == 1 ) && ( argdex < argc )) {

		/* Analyse detected option */
		/* ----------------------- */
		switch ( *(argv[argdex] + 1) ) {

			/* Activate display of file names before analysis */
			/* ---------------------------------------------- */
			case 'u' :
			case 'U' : InhibitDuplicates = 0; break;

			case 'v' :
			case 'V' : VerboseHelp = 1; break;
			
			/* Declaration of an 'include search path'*/
			/* -------------------------------------- */
			case 'i' :
			case 'I' : if ( SearchDex < SEARCHMAX ) {
					SearchPath[SearchDex] = (BPTR) (argv[argdex] +2);
					SearchDex++;
					}
				   else {
					genmake_warning( 52 , argv[argdex]);
					}
				   break;

			/* Request for SOURCE ECHO */
			/* ----------------------- */
			case 'e' :
			case 'E' : Echo = 1; break;

			/* Declaration of the binary target file for link */
			/* ---------------------------------------------- */
			case 'R' :
			case 'r' : option |= 0x0020;
				   Binary = (BPTR) (argv[argdex] + 2);
				   break;

			/* Request for STRICT AMAKE/MAKE formated makefile */
			/* ----------------------------------------------- */
			case 'm' :
			case 'M' : option |= 0x0040; 

				   /* Check for File Name Provided */
				   /* ---------------------------- */
				   if ( strlen((BPTR) (argv[argdex] +2)) > 0 ) {

					/* Attempt to initialise Stream Output file */
					/* ---------------------------------------- */
					StreamInfo = (FILEINFO) gm_creat((BPTR)(argv[argdex] +2));
					}
				   break;

			case 'd' :
			case 'D' : option |= 0x0002; 

				   /* Check for File Name Provided */
				   /* ---------------------------- */
				   if ( strlen((BPTR) (argv[argdex] +2)) > 0 ) {

					/* Attempt to initialise Stream Output file */
					/* ---------------------------------------- */
					StreamInfo = (FILEINFO) gm_creat((BPTR)(argv[argdex] +2));
					}
				   break;

			case 's' :
			case 'S' : option |= 0x0004; break;

			case 'a' :
			case 'A' : option |= 0x0008; break;

			case 'f' :
			case 'F' : option |= 0x0010; 
				   /* Check for File Name Provided */
				   /* ---------------------------- */
				   if ( strlen((BPTR) (argv[argdex] +2)) > 0 ) {

					/* Attempt to initialise Stream Output file */
					/* ---------------------------------------- */
					StreamInfo = (FILEINFO) gm_creat((BPTR)(argv[argdex] +2));
					}

				   break;

			/* Declaration of linker syntax */
			/* ---------------------------- */
			case 'l' :
			case 'L' : linker = (BPTR) (argv[argdex] + 2);
				   break;

			/* Declaration of compiler syntax */
			/* ------------------------------ */
			case 'c' :
			case 'C' : compiler = (BPTR) (argv[argdex] + 2);
				   break;

			/* Declaration of Options for Compile or Link */
			/* ------------------------------------------ */
			case 'o' :
			case 'O' :
				   switch ( *(argv[argdex] + 2) ) {
			
					case 'l' : /*  LINK OPTIONS  */
					case 'L' : /*  ------------  */
						LinkOpt = (BPTR) (argv[argdex]+ 3);
						break;

					case 'c' : /*  COMPILER OPTIONS  */
					case 'C' : /*  ----------------  */
						CompiOpt = (BPTR) (argv[argdex] + 3);
						break;

					case 'b' : /*  LIBRARY OPTIONS  */
						   /*  ---------------  */
						BibliOpt = (BPTR) (argv[argdex] + 3);
						break;

					default :
						CompiOpt = (BPTR) (argv[argdex] + 2);
						break;
					}

				   break;

			/* Declaration of BAL / ABAL source mode */
			/* ------------------------------------- */
			case 'B' :
			case 'b' : SourceMode = _GM_ABAL_SOURCE;
				   switch ( *(argv[argdex] + 2) ) {
					case 't' :
					case 'T' : ObjVal = (BPTR) TalkPtr[46]; /* -at */ 
						   ObjectStatus = 1;
						   ObjFlag = 1; break;
					case 'o' :
					case 'O' : ObjVal = (BPTR) TalkPtr[45]; /* -o  */ 
						   ObjectStatus = 1;
						   ObjFlag = 0; break;
					}
				   compiler = (BPTR) TalkPtr[43]; /* atr */
				   linker   = (BPTR) TalkPtr[44]; /* ald */
				   break;	

			/* Request for External usage formating */
			/* ------------------------------------ */
			case 'x' :
			case 'X' : Exturnal = 1;
				   break;

			/* Request for OBJECT GROUP symbol generation */
			/* ------------------------------------------ */
			case 'y' :
			case 'Y' : ObjGroup = 1; 
				   ObjGroupName = (BPTR) (argv[argdex]+2);
				   break;

			/* Declaration of elimination group */
			/* -------------------------------- */
			case 'z' :
			case 'Z' : 
			
			if (add_elimination_group((BPTR)(argv[argdex] + 2)) != 0) 
				genmake_warning( 51 , (BPTR) argv[argdex] );
			break;
			}
		argdex++;
		}

	/* Establish default option if None Selected */
	/* ----------------------------------------- */
	if ( (option & 0x0043) == 0 ) option |= 1; 

	/* Generate Default constants */
	/* -------------------------- */
	if ( (option & 0x0061) != 0 ) {

		add_constant((BPTR) TalkPtr[30] ,(BPTR) compiler);

		add_constant((BPTR) TalkPtr[32] ,(BPTR) linker);
		if ( LinkOpt != (BPTR) 0 ) 
			add_constant((BPTR) TalkPtr[33] ,(BPTR) LinkOpt);
		else	add_constant((BPTR) TalkPtr[33] ,(BPTR) NULSYMBOL );

		if ( BibliOpt != (BPTR) 0)
			add_constant((BPTR) TalkPtr[34] ,(BPTR) BibliOpt  );
		else	add_constant((BPTR) TalkPtr[34] ,(BPTR) NULSYMBOL );

		if ( SourceMode == _GM_C_SOURCE) 
			add_constant((BPTR) TalkPtr[39] ,(BPTR) ObjVal);

		add_constant((BPTR) TalkPtr[36] ,(BPTR) NULSYMBOL );
		add_constant((BPTR) TalkPtr[37] ,(BPTR) NULSYMBOL );

		if ((option & 0x0020) != 0) 
			add_constant((BPTR) TalkPtr[38] ,(BPTR) NULSYMBOL);

		}

/* Check for verbose option for list of files analysed */
/* --------------------------------------------------- */
if ( VerboseHelp ) 
	SautLigne();

/* Enter main function loop */
/* ------------------------ */
for (i = argdex; i < argc; i++) {

	/* Perform File search function init */
	/* --------------------------------- */
	RootFile = find_first((BPTR) argv[i]);

	/* Repeat while file valid */
	/* ----------------------- */
	while ( RootFile != (BPTR) 0 ) {

		set_abal_source_type( 0 );

		/* Display file to be analysed if in Verbose mode */
		/* ---------------------------------------------- */
		if ( VerboseHelp ) {
			mf_message((BPTR) "Dependance analysis : ");
			mf_message((BPTR) RootFile );
			SautLigne();
			}

		/* If standard MAKEFILE Generation inhibited */
		/* ----------------------------------------- */
		if (( option & 1 ) != 0 ) {

			/* Display Current Root File Name */
			/* ------------------------------ */
			LineFeed();
			object_file((BPTR)RootFile);
			StreamOut((BPTR)RULE_FIELD);
			}

		/* Attempt to open Current Root File */
		/* --------------------------------- */
		if (( rootptr = (FILEINFO) dependance_file((BPTR) establish_path((BPTR) RootFile) , MASTER_SOURCE)) != (FILEINFO) 0) {

			/* Perform dependance tracing */
			/* -------------------------- */
			dependance_trace( rootptr , Racine );

			/* Liberate Local Definitions */
			/* -------------------------- */
			liberate_constants( deffroot );

			deffroot = (CONSTREE) 0;

			/* Check for Makefile generation */
			/* ----------------------------- */
			if (((option & 1) != 0 ) && ((option & 0x0010) == 0)) {

				if ( Exturnal == 0 ) {
					generate_compiler_action();
					StreamOut((BPTR)establish_path((BPTR) RootFile));
					}

				}
	
			/* Close current Root File Now */
			/* --------------------------- */
			gm_close( rootptr );
			}

		/* Display Error Message */
		/* --------------------- */
		else	{

			/* If not in SILENT OPTION */
			/* ----------------------- */
			if (( option & 4 ) == 0 ) {	

				/* Display the error message */
				/* ------------------------- */
				StreamOut((BPTR) "   ");
				StreamOut((BPTR) argv[0]);
				StreamOut((BPTR) RULE_FIELD);
				StreamOut((BPTR)TalkPtr[20]);
				/* Error opening file */
				StreamOut((BPTR) RootFile);
				StreamOut((BPTR) " #");
				StreamByte((whoops | 0x0030));
				LineFeed();
				genmake_failure(0,40);
				}
			}

		/* Locate Next file if Any */
		/* ----------------------- */
		RootFile = (BPTR) find_next((BPTR) argv[i]);
		}
	}

	/* Establish compiler options */
	/* -------------------------- */
	establish_compiler_options();

	/* Check for Constant Update Required */
	/* ---------------------------------- */
	if ( SourceMode == _GM_ABAL_SOURCE ) {

		if (!( ObjectStatus )) {

			if ( FoundType == 2 ) {
				ObjVal = (BPTR) TalkPtr[46]; 
				ObjFlag = 1; 
				}
			else	{ 
				ObjVal = (BPTR) TalkPtr[45];  
				ObjFlag = 0;
				}
			}

		/* Generate Extension symbol OBJ or EXE */
		/* ------------------------------------ */
		if ( ObjFlag ) 
			add_constant((BPTR) TalkPtr[40] ,(BPTR) ObjVal);
		else
			add_constant((BPTR) TalkPtr[39] ,(BPTR) ObjVal);

		/* Check for Mode ABAL and extensions added */
		/* ---------------------------------------- */
		if ( ExtensionAdded == VRAI ) {

			strcat((BPTR) CompilerOptions , (BPTR) " ");
			strcat((BPTR) CompilerOptions , (BPTR) ABAL_EXT_FLAG );
			strcat((BPTR) CompilerOptions , (BPTR) & DefaultExt[1] );

			}
		}

	/* Check for inclusion paths used */
	/* ------------------------------ */
	if (( InclusionUsed == VRAI ) || ( SourceMode == _GM_ABAL_SOURCE )) {

		for ( x = 0; x < SearchDex; x++ ) {

			strcat((BPTR) CompilerOptions , (BPTR) " ");

			if ( SourceMode == _GM_ABAL_SOURCE )
				strcat((BPTR) CompilerOptions , (BPTR) ABAL_INC_FLAG );
			else
				strcat((BPTR) CompilerOptions , (BPTR) SYST_INC_FLAG );

			strcat((BPTR) CompilerOptions , (BPTR) SearchPath[x] );

			}

		} 	

	/* Generate compiler options Now please */
	/* ------------------------------------ */
	add_compiler_options();


	if ( Exturnal == 0 ) {

		/* Generate Makefile */
		/* ----------------- */
		if ((option & 0x0060) != 0 ) {

			/* Display Constants */
			/* ----------------- */
			display_constants(consroot);

			}
		}
	
	/* Check for Result syntax generation */
	/* ---------------------------------- */
	if (((option & 0x0020) != 0 ) || ( ObjGroup != 0)) {

		/* If OBJECT GROUP not required */
		/* ---------------------------- */
		if ( ObjGroup == 0 ) {

			LineFeed();

			/* Generate Result Name */
			/* -------------------- */
			if ( Binary != (BPTR) 0 ) {
				StreamOut((BPTR) TalkPtr[38] );
				StreamOut((BPTR)Binary);
				}
			StreamOut((BPTR)RULE_FIELD);
			}
		else	{
			/* Generate OBJECT GROUP CONSTANT */
			/* ------------------------------ */
			force_make_now();
			LineFeed();
			StreamOut((BPTR) ObjGroupName);
			StreamOut((BPTR)" = ");
			}

		/* Display controlled Dependance list */
		/* ---------------------------------- */
		for (i = argdex; i < argc; i++) {

			/* Initialise File search function */
			/* ------------------------------- */
			RootFile = find_first((BPTR) argv[i]);

			/* Repeat while file valid */
			/* ----------------------- */
			while ( RootFile != (BPTR) 0 ) {

				/* Check for Inclusion by other files */
				/* ---------------------------------- */
				if ( is_include((BPTR)RootFile) == 0 ) {

					/* Not included so ok for Object */
					/* ----------------------------- */
					StreamByte(SPACE);
					object_file((BPTR)RootFile);
					}

				/* Locate next file from search critere */
				/* ------------------------------------ */
				RootFile = (BPTR) find_next((BPTR) argv[i]);
				}
			}

		/* Generate Linker PHASE Syntax */
		/* ---------------------------- */
		if ( Exturnal == 0 ) {
			LineFeed();
			StreamByte(TABULATION);
			StreamOut((BPTR) TalkPtr[32] );

			switch ( SourceMode ) {

				case _GM_C_SOURCE :
					StreamOut((BPTR) " -o " );
					break;

				case _GM_ABAL_SOURCE :
					StreamOut((BPTR) " -D" );
					break;

				}
	
			/* Generate Result file Name */
			/* ------------------------- */
			if ( Binary != (BPTR) 0 ) {
				StreamOut((BPTR) TalkPtr[38] );
				StreamOut((BPTR)Binary);
				}

			/* Generate list of composant objects */
			/* ---------------------------------- */
			for (i = argdex; i < argc; i++) {

				/* Initialise File search function */
				/* ------------------------------- */
				RootFile = find_first((BPTR) argv[i]);

				/* Repeat while file valid */
				/* ----------------------- */
				while ( RootFile != (BPTR) 0 ) {

					/* Check for inclusion by other sources */
					/* ------------------------------------ */
					if ( is_include((BPTR)RootFile) == 0 ) {

						/* Ok if not included */
						/* ------------------ */
						StreamByte(SPACE);
						object_file((BPTR) RootFile);
						}

					/* Locate next file from search critere */
					/* ------------------------------------ */
					RootFile = (BPTR) find_next((BPTR) argv[i]);
					}
				}

			/* Output LIBRARY Constant */
			/* ----------------------- */
			check_line_length((BPTR) TalkPtr[34] );
			StreamByte(SPACE);
			StreamOut((BPTR) TalkPtr[34] );

			/* Output LINK OPT Constant */
			/* ------------------------ */
			check_line_length((BPTR) TalkPtr[33] );
			StreamByte(SPACE);
			StreamOut((BPTR) TalkPtr[33]);

			}

		}

	/* Generate Object Dependancies */
	/* ---------------------------- */
	if ((option & 0x0040) != 0) {

		for (i = argdex; i < argc; i++) {

			/* Initialise File search function */
			/* ------------------------------- */
			RootFile = find_first((BPTR) argv[i]);

			/* Repeat while file valid */
			/* ----------------------- */
			while ( RootFile != (BPTR) 0 ) {

				/* Check for inclusion by other sources */
				/* ------------------------------------ */
				if ( is_include((BPTR)RootFile) == 0 ) {

					/* Ok if not included */
					/* ------------------ */
					LineFeed();
					object_file((BPTR) RootFile);
					StreamOut((BPTR)RULE_FIELD);

					/* Perform Dependance list construction */
					/* ------------------------------------ */
					option |= 1;
					if ((idtree = isknown((BPTR) establish_path((BPTR) RootFile))) != 0 ) {
						showtree( idtree , 0 );
						}	
					option &= 0xFFFE;

					/* Generate Compiler Syntax */
					/* ------------------------ */
					if ( Exturnal == 0 ) {
						LineFeed();
						generate_compiler_action();
						StreamOut((BPTR)establish_path((BPTR) RootFile));
						}
					}

				/* Locate next file from search critere */
				/* ------------------------------------ */
				RootFile = (BPTR) find_next((BPTR) argv[i]);
				}
			}

		}

	if ( Exturnal == 0 ) {

		/* Generate do Make symbol Now */
		/* --------------------------- */
		if ((option & 0x0060) != 0 ) {
			force_make_now();
		
			}
		}

	/* Liberate Qwick Tree structure */
	/* ----------------------------- */
	liberate_file_tree( Racine );

	LineFeed(); LineFeed();

	/* Liberate Constants */
	/* ------------------ */
	liberate_constants( consroot );

	/* Flush the stream if needed */
	/* -------------------------- */
	if ( StreamInfo != (FILEINFO) 0 ) {
		OutFlush( StreamInfo );
		}

	/* Return Zero No Errors */
	/* --------------------- */
	return(flush_xallocate(GenMakeExitStatus));

}


