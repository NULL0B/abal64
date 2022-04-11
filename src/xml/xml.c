
#ifndef	_xml_c
#define	_xml_c

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#include "xml.h"

#define	allocate	malloc
#define	liberate	free

static	int	verbose=0;
static	int	echo=0;

char *	allocate_string( char * sptr )
{
	char  * rptr;
	if ((rptr = allocate( strlen(sptr)+1 )) != (char *) 0)
		strcpy(rptr,sptr);
	return( rptr);
}

struct	source_context * xml_close( struct source_context * h )
{
	if ( h ) {
		if ( h->handle )
			fclose(h->handle);
		if ( h->name )
			liberate( h->name );
		liberate( h );
		}
	return((struct source_context *) 0);
}

struct	source_context * xml_open( char * nptr )
{
	struct	source_context	*	sptr;
	FILE * h;
	if (!( h = fopen(nptr,"r")))
		return((struct source_context*) 0);

	else if (!( sptr = allocate( sizeof( struct source_context ) ) )) {
		fclose(h);
		return( sptr);
		}
	else	{
		sptr->handle = h;
		sptr->lines  =
		sptr->length = 
		sptr->column =
		sptr->ungotch= 0;
		sptr->punctuation=0;
		sptr->state = _TAG_IDLE;
		sptr->nesting = 0;
		sptr->name = allocate_string( nptr );
		return( sptr );
		}
}

static	void	xml_ungetch(
	struct	source_context	*	sptr,
	int				c
	)
{
	sptr->ungotch = c;
	return;
}

static	int	xml_getch(
	struct	source_context	*	sptr
	)
{
	int	c;
	if ((c = sptr->ungotch) != 0) {
		sptr->ungotch = 0;
		return(c);
		}
	while(1) {
		switch ((c = fgetc(sptr->handle))) {
			case	-1	:
			case	0	: return( 0 );
			case	'\r'	: continue;
			case	'\n'	:
				sptr->lines++;
				sptr->column=0;
				return(c);
			case	'\t'	:
				c = ' ';
			default		:
				sptr->column++;
				return((c & 0x00FF));					
			}
		}

}

static	int	xml_remove_space(
	struct	source_context	*	sptr
	)
{
	int	c;
	while ((c = xml_getch(sptr)) != 0) {
		switch ( c ) {
			case	'\n'	:
				if ( echo )
					printf("\r\n");
			case	' '	:
			case	'\r'	:
			case	'\t'	:
				continue;
			default		:
				xml_ungetch(sptr,c);
				return(c);
			}			
		}
	return(0);

}

static	int	xml_get_token( 
	struct	source_context	*	sptr
	)
{
	int	quoting=0;
	int	c;
	sptr->length = 0;
	while(1) {
		if (!( c = xml_getch( sptr )))
			break;
		/* Alphabetical Characters */
		/* ----------------------- */
		else if (( c >= 'a') && ( c <= 'z' )) {
			sptr->token[sptr->length++] = c;
			continue;
			}
		else if (( c >= 'A') && ( c <= 'Z' )) {
			sptr->token[sptr->length++] = c;
			continue;
			}
		/* International Characters */
		/* ------------------------ */
		else if (( c >= 128) && ( c <= 165 )) {
			sptr->token[sptr->length++] = c;
			continue;
			}
		/* Numerical Figures */
		/* ----------------- */
		else if (( c >= '0') && ( c <= '9' )) {
			sptr->token[sptr->length++] = c;
			continue;
			}
		else if ( quoting ) {
			if ( c != quoting ) {
				sptr->token[sptr->length++] = c;
				continue;
				}
			else	{
				sptr->token[sptr->length++] = c;
				break;
				}
			}
		else if ( c == '"' ) {
			quoting = c;
			sptr->token[sptr->length++] = c;
			continue;
			}
		else if (( c == '_' ) || ( c == '-' ) || ( c == '.' )) {
			sptr->token[sptr->length++] = c;
			continue;
			}
		else	{
			xml_ungetch(sptr,c);
			break;
			}
		}
	sptr->token[sptr->length] = 0;
	return( sptr->length );
}

static	int	failure(int v)
{
	printf("\n * * failure * *\n");
	return(v);
}

static	int	use_token( struct source_context * sptr )
{
	switch ( sptr->state ) {

		case	_TAG_OPEN	:
		case	_TAG_IDLE	:
			break;

		case	_TAG_NAME	:
			sptr->state = _TAG_ATBNAME;
			break;

		case	_TAG_ATBNAME 	:
			sptr->state = _TAG_ATBEQUAL;
			break;

		case	_TAG_ATBEQUAL	:
			return( failure(1) );
			break;

		case	_TAG_CLOSE	:
			sptr->state = _TAG_FINAL;
			break;

		case	_TAG_ATBVALUE	:
			sptr->state = _TAG_ATBVALUE;
			break;

		case	_TAG_QUESTION	:
			break;

		case	_TAG_ENDQUESTION :
			sptr->state = _TAG_QUESTION;
			break;

		case	_TAG_EXCLAIM 	:
			break;

		case	_TAG_ENDEXCLAIM :
			sptr->state = _TAG_EXCLAIM;
			break;
		}

	if ( echo )
		printf(" %s ",sptr->token);
	return(0);
}

static	int	use_punctuation( struct source_context * sptr )
{
	switch ( sptr->state ) {

		case	_TAG_FINAL	:
			if ( sptr->punctuation == '>' ) {
				if ( sptr->nesting )
					sptr->nesting--;
				else	return( failure(2) );
				if ( sptr->nesting )
					sptr->state = _TAG_OPEN;
				else	sptr->state = _TAG_IDLE;
				break;
				}
			else	return( failure(1) );

		case	_TAG_OPEN	:

		case	_TAG_IDLE	:
			if ( sptr->punctuation == '<' )
				sptr->state = _TAG_NAME;
			break;

		case	_TAG_NAME	:
			if ( sptr->punctuation == '-' ) {
				sptr->state = _TAG_COMMENT;
				break;
				}
			else if ( sptr->punctuation == '/' ) {
				sptr->state = _TAG_CLOSE;
				break;
				}
			else if ( sptr->punctuation == '?' ) {
				sptr->state = _TAG_QUESTION;
				break;
				}
			else if ( sptr->punctuation == '!' ) {
				sptr->state = _TAG_EXCLAIM;
				break;
				}
			else	return( failure(1) );

		case	_TAG_QUESTION	:
			if ( sptr->punctuation == '?' )
				sptr->state = _TAG_ENDQUESTION;
			break;

		case	_TAG_ENDQUESTION :
			if ( sptr->punctuation == '>' ) {
				if ( sptr->nesting )
					sptr->state = _TAG_OPEN;
				else	sptr->state = _TAG_IDLE;
				}
			else	sptr->state = _TAG_QUESTION;
			break;

		case	_TAG_EXCLAIM 	:
			if ( sptr->punctuation == '!' )
				sptr->state = _TAG_ENDEXCLAIM;
			break;

		case	_TAG_ENDEXCLAIM :
			if ( sptr->punctuation == '>' ) {
				if ( sptr->nesting )
					sptr->state = _TAG_OPEN;
				else	sptr->state = _TAG_IDLE;
				}
			else	sptr->state = _TAG_EXCLAIM;
			break;

		case	_TAG_ATBNAME 	:
			if ( sptr->punctuation == '>' ) {
				sptr->nesting++;
				sptr->state = _TAG_OPEN;
				break;
				}
			else if ( sptr->punctuation == '/' ) {
				sptr->state = _TAG_FINAL;
				break;
				}
			else	return( failure(1) );

		case	_TAG_ATBEQUAL	:
			if ( sptr->punctuation == '=' ) {
				sptr->state = _TAG_ATBVALUE;
				break;
				}
			else	return( failure(1) );

		case	_TAG_ATBVALUE	:
			return( failure(1) );

		case	_TAG_CLOSE	:
			return( failure(1) );

		}

	if ( echo )
		printf(" %c ",sptr->punctuation);
	return(0);
}

int	xml_parse(char * nptr)
{
	int	status=0;
	int	c;
	struct	source_context	*	sptr;
	if ( verbose )
		printf("\nxml : %s\n",nptr);
	if (!( sptr = xml_open( nptr )))
		return(failure(40));
	else	{
		while ((c = xml_remove_space( sptr )) != 0) {
			if ( xml_get_token( sptr ) ) {
				if ((status = use_token(sptr)) != 0)
					break;
				}
			else if (!( sptr->punctuation = xml_getch(sptr) ))
				break;
			else if ((status = use_punctuation( sptr )) != 0)
				break;
			}
		if ( status ) {
			sptr = xml_close( sptr );
			return( status );
			}
		else if (!( sptr->nesting )) {
			sptr = xml_close( sptr );
			return( 0 );
			}
		else	{
			sptr = xml_close( sptr );
			return( failure( 2 ) );
			}
		}
}

int	banner()
{
	printf("\n   Xml Parse Engine : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 31/10/2003 ");
	printf("\n   Copyright (c) 2003 Amenesik / Sologic   \n\n");
	return(0);
}


static	int	option( char * aptr )
{
	while ( *aptr ) {
		switch ( *(aptr++) ) {
			case	'e'	:
			case	'E'	:
				echo=1; continue;
			case	'v'	:
			case	'V'	:
				verbose=1; continue;
			default		:
				return(failure(1));
			}
		}
	return(0);
}

int	main(int argc,  char * argv[] )
{
	int	argi;
	char *	aptr;
	if ( argc == 1 )
		return(banner());
	else	{
		for ( argi=1; argi < argc; argi++ ) {
			if (!( aptr = argv[argi] ))
				break;
			else if ( *aptr != '-' ) {
				if (!( xml_parse( argv[argi] ) ))
					continue;
				else	break;
				}
			else if (!( option( (aptr+1) ) ))
				continue;
			else	break;
			}
		return(0);
		}
}

#endif	/* _xml_c */
	/* ------ */


