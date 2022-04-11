/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Object Oriented ABAL			*/
/*									*/
/*		 Copyright (c) 2021 Amenesk / Sologic 			*/
/*									*/
/*									*/
/*		File	:	BROWSE.C				*/
/*		Version :	5.1a					*/
/*		Date	:	03/05/2021				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_BROWSE_C
#define	_BROWSE_C

#include <stdio.h>
#include <errno.h>
#include "stdtypes.h"		/* Standardised type definitions	*/
#include "browse.h"		/* Specific utility definitions		*/
#include "filefind.h"		/* Wild card file finder definitions	*/
#include "version.h"

#include "agrmsg.c"		/* National message management		*/

#define	MODULE_PROVISOIRE "\n   Provisoire du 28/02/2006"

static	int	bodge=1;


void	_aFchkstk()
{
	return;
}

void	banner()
{
	printf("   ABAL++ : %s   %s %s ",natmsg(1),natmsg(2),MODULE_VERSION);
	printf("%s",MODULE_PROVISOIRE);
	printf("   %s\n\n",MODULE_COPYRIGHT);
	printf("   %s : \n\n",natmsg(3));
	printf("   %s \n",natmsg(4));
	printf("   %s \n",natmsg(5));
	printf("   %s \n",natmsg(6));
	printf("   %s \n",natmsg(7));
	printf("   %s \n",natmsg(8));
	printf("   %s \n",natmsg(9));
	printf("   %s \n",natmsg(10));
	printf("   %s \n",natmsg(11));
	printf("   %s \n",natmsg(12));
	printf("   %s \n",natmsg(13));
	printf("   %s \n\n",natmsg(14));
	return;
}

void	error_message( mptr )
BPTR	mptr;
{
	printf("%s: %s : %s\n\r",Identity,natmsg(15),mptr); 
	return;
}

WORD	token_legal( c )
WORD	c;
{
	if ((( c >= 'a' ) && ( c <= 'z'))
	||  (( c >= 'A' ) && ( c <= 'Z'))
	||  (( c >= '0' ) && ( c <= '9'))
	||   ( c == '_' ) || ( c == '.') )
  		return( 1 );
	else	return( 0 );

}

void	initialise_file_follower()
{
	Follower = (FOLLOWPTR) 0;
	return;
}

void	liberate_file_follower()
{
	FOLLOWPTR	fptr;

	while (( fptr = Follower ) != (FOLLOWPTR) 0) {
		Follower = fptr->next;
		free( fptr->name );
		free( fptr );
		}
	return;

}

WORD	calculate_hash_value( sptr )
BPTR	sptr;
{
	WORD	result;
	for ( result = 0; *sptr; result += *(sptr++) );	
	return( (result % 147) );
}

WORD	check_file_follower( nptr )
BPTR	nptr;
{
	FOLLOWPTR	fptr;
	WORD		h;

	if (( fptr = Follower ) != (FOLLOWPTR) 0) {

		/* Check for already known */
		/* ----------------------- */
		h = calculate_hash_value( nptr );

		do	{
			/* Check for match and signal INHIBIT analysis */
			/* ------------------------------------------- */
			if (( fptr->hash == h)
			&&  ( strcmp( nptr, fptr->name ) == 0 ))
				return( VRAI ); 			
			else	fptr = fptr->next;
			}
		while ( fptr != (FOLLOWPTR) 0 );

		}

	/* Add new entry and indicate ok analysis required */
	/* ----------------------------------------------- */
	if (( fptr = (FOLLOWPTR) malloc( sizeof( struct file_follower ) )) != (FOLLOWPTR) 0) {
		if ((fptr->name = (BPTR) malloc( strlen( nptr ) + 1 )) != (BPTR) 0) {
			strcpy( fptr->name, nptr );
			fptr->hash = calculate_hash_value( nptr );
			fptr->next = Follower;
			Follower = fptr;
			}
		else	free( fptr );
		}

	return( FAUX );

}



void	execute_command( cptr )
BPTR	cptr;
{
	if ( Options.verbose )
		printf("%s\n",cptr );

	systeme( cptr );
	return;
}


void	add_search_pattern( sptr )
BPTR	sptr;
{
	WORD	l;

	if ( MaxSearchPattern < MAX_SEARCH_PATTERN ) {

		/* Check for and Remove quotes */
		/* --------------------------- */
		if ( *sptr == '"' ) {
			sptr++;
			l = strlen( sptr );
			if ( *(sptr + l - 1) == '"' )
				*(sptr + l - 1) == 0;
			}

		Search[MaxSearchPattern].pattern  = sptr;
		Search[MaxSearchPattern].quantity = 0;
		Search[MaxSearchPattern].total    = 0;
		Search[MaxSearchPattern].files    = 0;

		if ( Options.ignore ) {
			while ( *sptr ) {
				*sptr = toupper( *sptr );
				sptr++;
				}
			}
	

		Search[MaxSearchPattern].indent  = 0;
		Search[MaxSearchPattern].ligne   = 0;
		Search[MaxSearchPattern].column  = 0;
		Collect[MaxSearchPattern++].status = 0;

		}

	return;
}

void	add_replace_pattern( rptr )
BPTR	rptr;
{

	return;
}
void	reset_search_control( entry )
WORD	entry;
{
	Search[entry].indent  = 0;
	Search[entry].column  = Context.columns;
	Search[entry].ligne   = Context.lines;
	return;
}



void	initialise_options()
{
	Options.master[0] = 0;
	Options.paths    = 0;
	Options.inhibit  = FAUX;
	Options.collect  = 0;
	Options.account  = FAUX;
	Options.warnings = FAUX;
	Options.editor = (BPTR) 0;
	Options.trace   = VRAI;
	Options.expand  = FAUX;
	Options.ignore  = VRAI;
	Options.verbose = FAUX;
	Options.echo    = FAUX; 
	Options.tracename = (BPTR) 0;
	Options.tracehandle = (FILEPTR) 0;
	MaxSearchPattern = 0;
	initialise_file_follower();
	return;
}

BPTR	trace_file_name( tptr )
BPTR	tptr;
{
	strcpy( name_buffer, tptr );
	strcat( name_buffer, ERROR_EXTENSION );
	return( name_buffer );

}

void	check_for_trace_file()
{

	if ( Options.tracehandle == (FILEPTR) 0) {

		/* Establish default name if necessary */
		/* ----------------------------------- */
		if (( Options.tracename == (BPTR) 0) 
		||  ( strlen(Options.tracename) == 0 ))
			Options.tracename = (BPTR) BROWSE_FILE;
			
		Options.tracehandle = fopen( trace_file_name( Options.tracename ),"w" );
		}
	return;
}

void	add_converted_item( lptr )
BPTR	lptr;
{
	check_for_trace_file();
	if ( Options.tracehandle != (FILEPTR) 0 )
		fprintf( Options.tracehandle, "%s\n", lptr );
	return;
}

void	activate_collection( nomfic, entry )
BPTR	nomfic;
WORD	entry;
{
	Collect[entry].filename = nomfic;
	Collect[entry].status = 1;
	Collect[entry].indent = 0;
	Collect[entry].line   = Search[entry].ligne;
	Collect[entry].column = Search[entry].column;
	Collect[entry].token[0] = 0;
	return;
}


void	output_pattern_match( entry )
WORD	entry;
{
	if ( Options.account ) {
		Search[entry].quantity++;
		Search[entry].total++;
		}
	else	{
		if (!( Options.trace )) 
			printf("%s %u %u %s\n",Context.name,Search[entry].ligne, Search[entry].column-1, Search[entry].pattern );
		else	{

			if ( Options.echo ) {
				if (!(Options.echo & 2)) {
					printf("%s",Search[entry].pattern );
					Options.echo |= 2;
					}
				}
			else	{
				/* Ensure trace file is open */
				/* ------------------------- */
				check_for_trace_file();

				/* Output if valid trace stream */
				/* ---------------------------- */
				if ( Options.tracehandle != (FILEPTR) 0) {

					if ( Options.collect )
						activate_collection( Context.name, entry );
					else	fprintf(Options.tracehandle,"%s %u %u %s\n",Context.name,Search[entry].ligne, Search[entry].column-1, Search[entry].pattern );

					}
				}
			}
		}
	return;

}

void	check_search_pattern( c, entry )
WORD	c;
WORD	entry;
{
	WORD	v;

	/* Test character checking for wild cards */
	/* -------------------------------------- */
	switch ((v = *( Search[entry].pattern + Search[entry].indent ))) {

		case '*' : if ( *( Search[entry].pattern + Search[entry].indent + 1 ) != c )
				return;

			   Search[entry].indent++;

		case '?' : Search[entry].indent++;
			   break;

		default  :

			/* Check for character match */
			/* ------------------------- */
			if ( c == v ) {
				Search[entry].indent++;
				break;
				}
			else	reset_search_control( entry );
			return;

		}

	/* Pre-analyse next character for wild card checking and match found */
	/* ----------------------------------------------------------------- */
	switch ( *( Search[entry].pattern + Search[entry].indent ) ) {
		case '*' :
			if ( *( Search[entry].pattern + Search[entry].indent + 1 ) != 0 )
				break;
		case 0 	 :
			output_pattern_match( entry );
			reset_search_control( entry );

		}
	return;

}

void	generate_collection( entry )
WORD	entry;
{
	if ( Collect[entry].indent != 0 ) {
		Collect[entry].token[Collect[entry].indent++] = 0;
		fprintf(Options.tracehandle,"%s %u %u %s\n",Collect[entry].filename,Collect[entry].line, Collect[entry].column-1, Collect[entry].token );
		}
	Collect[entry].status = 0;
	return;
}

void	reset_search_controller()
{
	WORD	entry;

	if ( Options.collect )
		for (entry = 0; entry < MaxSearchPattern; entry++ ) 
			if ( Collect[entry].status == 2 )
				generate_collection( entry ); 

	for ( entry = 0; entry < MaxSearchPattern; entry++ )
		reset_search_control( entry );

	if (Options.echo & 2) {
		printf("\n");
		Options.echo = 0xFFFD;
		}
	return;
}


void	check_collection( c, entry )
WORD	c;
WORD	entry;
{
	switch  ( Collect[entry].status ) {
		case 0 : return;
		case 1 : if ( token_legal(c) ) 
				Collect[entry].status = 2;
			 else	return;
		case 2 : if (( token_legal(c) )
			 &&  ( Collect[entry].indent < 64 ))
				Collect[entry].token[Collect[entry].indent++] = c;
			else	generate_collection(entry);
		}
	return;
}

void	check_search_patterns( c )
WORD	c;
{
	WORD	entry;
	WORD	etat;

	if ( Options.collect )
		for ( entry = 0; entry < MaxSearchPattern; entry++ )
			check_collection( c, entry );	

	etat = Options.echo;

	for ( entry = 0; entry < MaxSearchPattern; entry++ )
		check_search_pattern( c, entry ); 

	if ((etat & 2) && (etat == Options.echo))
		printf("%c",c); 

	return;
}

void	start_accountancy_report()
{
	WORD	entry;
	printf("<html><head></html><body>");
	printf("\n<table border=1><tr><th>file");
	for ( entry = 0; entry < MaxSearchPattern; entry++ )
		printf("<th>%s",Search[entry].pattern);
	printf("<th>Total");
	Options.account |= 16;
	return;
}

void	close_accountancy_report()
{
	printf("\n</table>");
	printf("\n</body></html>\n");
	Options.account &= ~16;
	return;
}

void	file_accountancy_results(char * filename)
{
	WORD	entry;
	long	nombre=0L;
	if ( Options.account & 4 ) {
		/* html reporting */
		if (( Options.account & 8 )
		&&  (!(Options.account & 16)))
			start_accountancy_report();

		printf("\n<tr><th>%s",filename);
		for ( entry = 0; entry < MaxSearchPattern; entry++ ) {
			nombre += Search[entry].total;
			if ( Search[entry].total )
				printf("<td>%lu",Search[entry].total);
			else	printf("<td>");
			Search[entry].total = 0;
			}
		if ( nombre )
			printf("<th>%lu",nombre);
		}
	else	{
		for ( entry = 0; entry < MaxSearchPattern; entry++ ) {
			if (Search[entry].total != 0 ) {
				printf("%s: %s: %lu\n",filename,Search[entry].pattern,Search[entry].total );
				Search[entry].total = 0;
				}
			}		
		}
	return;
}

void	final_accountancy_results()
{
	WORD	entry;
	long	nombre=0L;
	
	if ( Options.account & 4 ) {
		/* html reporting */
		if (( Options.account & 8 )
		&&  (!(Options.account & 16)))
			start_accountancy_report();

		printf("\n<tr><th>%s",Options.master);
		for ( entry = 0; entry < MaxSearchPattern; entry++ ) {
			nombre += Search[entry].quantity;
			if ( Search[entry].quantity )
				printf("<td>%lu",Search[entry].quantity);
			else	printf("<td>");
			}
		if ( nombre )
			printf("<th>%lu",nombre);
		if (( Options.account & 8 )
		&&  ( Options.account & 16))
			close_accountancy_report();

		}
	else	{
		for ( entry = 0; entry < MaxSearchPattern; entry++ )
			if (Search[entry].quantity != 0 )
				printf("%s: %lu\n",Search[entry].pattern,Search[entry].quantity );
		}
	return;
}

WORD	trace_results( mode )
WORD	mode;
{
	WORD	status;

	if ( Options.account ) {
		if ( Options.account & 1 )
			final_accountancy_results();
		}
	else	{
		/* Trace output has been started */
		/* ----------------------------- */
		if (( Options.trace ) 
		&&  ( Options.tracehandle != (FILEPTR) 0 )) {

			if ( Options.editor == (BPTR) 0 )
				Options.editor = (BPTR) TRACE_EDITOR;

			/* Close trace and execute AED /T<trace_filename> */
			/* ---------------------------------------------- */
	 		fclose( Options.tracehandle );
			strcpy( name_buffer, Options.editor );
			strcat( name_buffer, TRACE_OPTIONS  );
			strcat( name_buffer, Options.tracename );
			if ( !( Options.inhibit ) )
				execute_command( name_buffer );

			/* Implicite default trace files must be removed */
			/* --------------------------------------------- */
			if (( Options.trace != 2 ) && (!(Options.inhibit)))
				unlink( trace_file_name( Options.tracename ) );

			status = 1;

			}
	
		else	{
			if ( Options.verbose )
				printf("%s: %s \n",Identity,natmsg(16) );
			status = 0;
			}
		}
	liberate_file_follower();
	return( ( mode != 0 ? status : 0 ) );
}


void	file_analysis( fptr )
BPTR	fptr;
{
	WORD	c;

	/* Check for analysis already performed */
	/* ------------------------------------ */
	if ( check_file_follower( fptr ) == VRAI )
		return;

	/* Attempt to open the file */
	/* ------------------------ */
	if ((Context.handle = fopen( (Context.name = fptr), "r" )) != (FILEPTR) 0 ) {

		if ( Options.verbose )
			printf(" %s\n",fptr );

		Context.lines   = 1;
		Context.columns = 1;

		reset_search_controller();

		/* Scan till end of file */
		/* --------------------- */
		while (( c = fgetc( Context.handle )) != MOINS_UN ) {

			if ( Options.ignore ) {
				c = toupper( c );
				}
	
			switch ( c ) {

				case 0x000A : 	Context.lines++;
					      	Context.columns = 1;
					      	reset_search_controller();
						continue;
				}


			Context.columns++;
			check_search_patterns( c );

			}

		/* Close the file now */
		/* ------------------ */
		fclose( Context.handle );

		if ( Options.account & 2 )
			file_accountancy_results( fptr );

		}
	return;
}

BPTR	member_list_file()
{
	return( MEMBER_LIST_FILE );
}

WORD	generate_inclusion_list( fptr )
BPTR	fptr;
{
	WORD	i;
	BPTR	nptr;
	/* Check for valid filename pointer */
	/* -------------------------------- */
	if ( fptr != (BPTR) 0 ) {

		/* Remove file as a precaution to ensure clean context */
		/* --------------------------------------------------- */
		unlink( member_list_file() );
	
		/* Generate command syntax for GENMAKE then execute command */
		/* -------------------------------------------------------- */
		sprintf( name_buffer, "genmake -u -f%s ",member_list_file());
		for ( i=0; i < Options.paths; i++ ) {
			strcat( name_buffer, Options.path[i]);
			strcat( name_buffer," ");
			}
		strcat( name_buffer, fptr );
		strcpy( Options.master, fptr );
		execute_command( name_buffer );
		return( VRAI );
		}
	else	return( MOINS_UN );

}

BYTE	member_name[256];
FILEPTR	group_handle;
WORD	member_end;

WORD	fscan_token( handle, result )
FILEPTR	handle;
BPTR	result;
{
	
	WORD	c;
	WORD	l;

	if ( member_end == VRAI )
		return( MOINS_UN );

	l = 0;

	while ( 1 ) {

		switch ((c = fgetc( handle ))) {
			case MOINS_UN :
			case 0x001A   : 
				if ( l == 0 )		
					return( MOINS_UN );
				member_end = VRAI;

			case 0x0020   :
			case 0x0009   :
			case 0x000A   :
			case 0x000D   :
			case 0x000C   : 
				if ( l == 0 )
					continue;
				else	{
					*(result++) = 0;
					return( l );
					}
			}
		*(result++) = c; l++;
		}

}

BYTE	wild_buffer[256];

BPTR	first_wild_file( fptr )
BPTR	fptr;
{
	WORD	r;
#ifdef	WILD_FIND
	if ((r = FFile( fptr, wild_buffer )) == MOINS_UN)
		return( (BPTR) 0 );
	else	return( wild_buffer );
#else
	return( fptr );
#endif
}

BPTR	next_wild_file()
{
	WORD	r;
#ifdef	WILD_FIND
	if ((r = NFile( wild_buffer )) == MOINS_UN)
		return( (BPTR) 0 );
	else	return( wild_buffer );
#else
	return( (BPTR) 0 );
#endif
}
 

BPTR	next_inclusion_member()
{
	WORD	l;
	BPTR	first_inclusion_member();

	while ( 1 ) {

		/* Collect token from file */
		/* ----------------------- */
		if ((l = fscan_token( group_handle, member_name )) == MOINS_UN) {

			/* -------------------------------------------- */
			/* Close file then remove it before signaling 	*/
			/* 		End of list condition		*/
			/* -------------------------------------------- */
			fclose( group_handle );
			unlink( member_list_file() );
			if ( generate_inclusion_list( next_wild_file() ) == MOINS_UN )
				return( (BPTR) 0 );
			else	return( first_inclusion_member() );
			}

		/* Avoid empty lines and dependance header syntax */
		/* ---------------------------------------------- */
		if (( l = strlen( member_name )) > 0) {
			if ( member_name[(l-1)] != ':' )
				return( member_name );
			}
		}

}

BPTR	first_inclusion_member()
{
	member_end = FAUX;
	if (( group_handle = fopen( member_list_file(), "r" )) == (FILEPTR) 0)
		return( (BPTR) 0 );
	else	return( next_inclusion_member() );
}



BPTR	locate_first_file( fptr )
BPTR	fptr;
{
	/* Check for Inclusion expansion required */
	/* -------------------------------------- */
	if (!(Options.expand ))
		return( first_wild_file( fptr ) );

	/* Expand inclusions */
	/* ----------------- */
	if ( generate_inclusion_list( first_wild_file( fptr ) ) == MOINS_UN )
		return( (BPTR) 0 );

	return( first_inclusion_member() );	

}

BPTR	locate_next_file()
{

	/* Check for Inclusion expansion required */
	/* -------------------------------------- */
	if (!(Options.expand))
		return( next_wild_file() );

	return( next_inclusion_member() );

}


void	multiple_file_analysis( fptr )
BPTR	fptr;
{
	BPTR	nptr;

	if ((nptr = locate_first_file( fptr )) != (BPTR) 0) {
	
		do	{
			file_analysis( nptr );
			}
		while ((nptr = locate_next_file()) != (BPTR) 0);
		}
	return;
}

void	unix_converted_item( char * fname, char * message, int lnumber )
{
	char	buffer[1024];
	if ( *fname == '*' )
		return;
	if (!( Options.warnings )) {
		if ( wildcomp( (BPTR) message, (BPTR) "*warning*"  ) == 0)
			return;
		else if ( wildcomp( (BPTR) message, (BPTR) "*attention*"  ) == 0)
			return;
		}
	sprintf(buffer,"%s %u 1 %s\n",fname,lnumber,message);
	add_converted_item(buffer);
	return;
}

int	convert_integer(char * sptr)
{
	int	result=0;
	while (*sptr ) {
		if ((*sptr < '0') || (*sptr > '9'))
			break;
		else	result = ((result*10)+(*(sptr++)-'0'));
		}
	return(result);
}

void	compile_trace_analysis( lptr )
BPTR	lptr;
{
	WORD	i;
	WORD	item=0;
	WORD	mode=0;
	BPTR	iptr;
	BPTR	fptr=(BPTR) 0;
	WORD	lnumber=0;
	if ( Options.verbose )
		printf("%s\n",lptr);
	for (iptr=lptr,i=0; *(lptr +i); i++) {
		switch ( *(lptr + i) ) {
			case ' ' : if ( bodge ) return;
			case '(' : break;
			case ':' : 
				if (!( bodge )) {		
					lptr += (i+1); i = 0; 
					}
				else	{
					if (!(mode)) {
						fptr = iptr;
						iptr = lptr = (lptr + i);
						*iptr = 0;
						i=0;
						mode=1;
						}
					else 	{
						if ( mode == 1 ) {
							lnumber=convert_integer((iptr+1));
							unix_converted_item(fptr,(lptr+1),lnumber);
							return;
							}

						break;
						}	
					}
			default  : continue;
			}
		break;
		}

	if ( bodge ) 
		if (!( fptr ))
			return;

	for (i=0; *(lptr +i) != '('; i++ )
		if (!( *(lptr +i) ))
			return;
	*(lptr+i) = ' ';
	for (; *(lptr +i) != ')'; i++ )
		if (!( *(lptr +i) ))
			return;
	*(lptr+i) = ' ';
	for (; *(lptr +i) != ':'; i++ )
		if (!( *(lptr +i) ))
			return;
	*(lptr+i) = '1';
	
	if (!(Options.warnings)) {
		for (i++; *(lptr +i) == ' '; i++ );
		if ( wildcomp( (BPTR) (lptr+i), (BPTR) "warning*"  ) == 0)
			return;
		}
	add_converted_item( lptr );
	return;
}

void	trace_convertor( handle )
FILEPTR	handle;
{
	BYTE	buffer[512];
	WORD	bindex;
	WORD	c;

	bindex = 0;

	while (1) {
		switch ((c = fgetc( handle))) {
			case 0x000D :
				continue;

			case MOINS_UN	:
			case 0x001A :
			case 0 :
				if (!( bindex ))
					return;

			case 0x000A :

				if (!(bindex))
					continue;

				buffer[bindex] = 0;
				compile_trace_analysis( buffer );
				bindex = 0;
				continue;

			default :
				buffer[ bindex++ ] = c;
			}

		}

}

void	compiler_tracing( fptr )
BPTR	fptr;
{
	FILEPTR	handle;

	/* Attempt to open trace file */
	/* -------------------------- */
	if ((handle = fopen( fptr, "r" )) != (FILEPTR) 0) {

		/* Perform trace conversion */
		/* ------------------------ */
		trace_convertor( handle );
		
		/* Close input trace file */
		/* ---------------------- */
		fclose( handle );

		}

	return;
}

WORD	is_option_indicator( c )
WORD	c;
{
	if ( c == '-' )
		return( 1 );
#ifndef	UNIX
	if ( c == '/' )
		return( 1 );
#endif
#ifdef	VMS
	if ( c == '/' )
		return( 1 );
#endif
	return( 0 );
}

WORD	main( argc, argv )
WORD	argc;
BPTR	argv[];
{
	WORD	argn;
	WORD	raise_result=0;

	initialise_text_messages();

	/* Check for identification request */
	/* -------------------------------- */
	if ( argc == 1 ) {
		banner();
		return(0);
		}

	/* Establish module message identity */
	/* --------------------------------- */
#ifdef	PROLOGUE_111
	Identity = (BPTR) "agr";
#else
	Identity = (BPTR) argv[0];
#endif	

	initialise_options();

	/* Argument analysis and option dispatching */
	/* ---------------------------------------- */
	for ( argn = 1; argn < argc; argn++ ) {

		/* Check for option prefix character */
		/* --------------------------------- */
		if ( is_option_indicator( *(argv[argn]) ) ) {
			
			/* Detect and receive option */
			/* ------------------------- */
			switch ( *(argv[argn] + 1) ) {

				case 'a' : /* Analysis if Compiler Trace */
					   /* -------------------------- */
					   raise_result = 1;
					   compiler_tracing((BPTR) (argv[argn] + 2));
					   continue;

				case 'E' : /* Activate Echo stream */
				case 'e' : Options.editor = (BPTR) (argv[argn] + 2);
					   continue;
	
				case 'g' : /* No Editor, generate trace only */
				case 'G' : /* ------------------------------ */
					   Options.inhibit = VRAI;
					   continue;
	
				case 'T' : /* Trace file generation */
				case 't' : Options.trace = 2;
					   Options.tracename = (BPTR) (argv[argn] + 2);
					   continue;

				case 'I' : /* Include stream activation */
				case 'i' : Options.expand = VRAI;
					   Options.path[Options.paths++] = argv[argn];
					   continue;

				case 'L' :
				case 'l' : /* Perform Stdout Listing	 */
					   Options.echo = VRAI;
					   continue;
 
				case 'n' :
				case 'N' : /* Collect next token	*/
					   Options.collect = 1;
					   continue;

				case 'S' : /* Search pattern declaration */
				case 's' : add_search_pattern( (argv[argn] + 2) );
					   continue;

				case 'R' : /* Replacement token syntax */
				case 'r' : add_replace_pattern( (argv[argn] + 2) );
					   continue;

				case 'C' : /* Indicate case sensitive  */
				case 'c' : Options.ignore = FAUX;
					   continue;

				case 'V' : /* Verbalise operations     */
				case 'v' : Options.verbose = VRAI;
					   continue;

				case 'W' :
				case 'w' : /* Trace warnings */
					   Options.warnings = VRAI;
					   continue;

				case 'X' :
				case 'x' : /* Token count */
					   /* ----------- */
					Options.account |= 1;
					switch ( *(argv[argn] + 2) ) {
						case	'r'	: /* qunatize page  */
						case	'R'	:
							Options.account |= 8;
						case	'l'	: /* quantize lines */
						case	'L'	:
							Options.account |= 4;
							break;
						}
					continue;

				case 'Q' :
				case 'q' : /* Quantify by File */
					   /* ---------------- */
					Options.account |= 2;
					switch ( *(argv[argn] + 2) ) {
						case	'r'	: /* qunatize page  */
						case	'R'	:
							Options.account |= 8;
						case	'l'	: /* quantize lines */
						case	'L'	:
							Options.account |= 4;
							break;
						}
					   continue;
				}

			continue;

			}
		else	
			/* Analysis of this file if work to do */
			/* ----------------------------------- */
			if ( MaxSearchPattern != 0 )
				multiple_file_analysis( argv[argn] );


		}

	/* Perform interactive tracing */
	/* --------------------------- */
	return( trace_results( raise_result ) );

}

#endif	/* _BROWSE_C */

