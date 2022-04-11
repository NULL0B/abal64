#ifndef	_parseabal_c
#define	_parseabal_c

#include <stdio.h>

#include "parseabal.h"

public	int	abal_parser_syntax_error( struct abal_parser_context * pptr, int code )
{
	if ( code )
		printf("\nsyntax error : incorrect token : %s \n",pptr->token);
	else	printf("\nsyntax error : punctuation     : %c \n",pptr->punctuation);
	return(0);
}

public	void	abal_parser_not_implemented( struct abal_parser_context * pptr )
{
	return;
}

private	int	ll_abal_getch( struct abal_parser_context * pptr )
{
	int	c;
	if (( c = pptr->ungotc )) {
		pptr->ungotc = 0;
		return(c);
		}
	else if ((c = fgetc(pptr->handle)) == -1)
		return(0);
	else if ( c == 0x001A )
		return( 0 );
	else	{
		if ( pptr->echo )
			printf("%c",c);
		return( c );
		}
}

private	int	abal_getch( struct abal_parser_context * pptr )
{
	int	c;
	c = ll_abal_getch(pptr);
	if ( c == '\n') {
		pptr->linecount++;
		pptr->columncount = 0;
		}
	return(c);
}

private	int	abal_eol( struct abal_parser_context * pptr )
{
	int	c;
	while ((c = abal_getch( pptr )) != '\n') {
		if (!( c ))
			break;
		else	(pptr->relay->use_space)(pptr,c);
		}
	(pptr->relay->use_space)(pptr,c);
	return((pptr->ungotc = c));
}

private	int	abal_white_space( struct abal_parser_context * pptr )
{
	int	c;
	while (1) {
		switch ((c = abal_getch( pptr ))) {
			case	0	:
			case	-1	:
			case	0x001A	:
				pptr->ungotc = c;
				(pptr->relay->use_space)(pptr,c);
				return(0);
			case	' '	:
			case	'\t'	:
				(pptr->relay->use_space)(pptr,c);
				continue;
			case	'.'	:
			case	'*'	:
				if ( pptr->columncount != 0 )
					return((pptr->ungotc = c));
				
			case	'\r'	:
			case	';'	:
				(pptr->relay->use_space)(pptr,c);
				return( abal_eol(pptr) );
			default		:
				pptr->columncount++;
				return((pptr->ungotc = c));
				
			}
		}	
}

private	int	abal_get_token( struct abal_parser_context * pptr )
{
	int	c;
	int	convert=0;
	int	quoting=0;
	if (!(c = abal_white_space( pptr ) ))
		return(0);
	else if (c == '\n')
		return(0);
	else	pptr->tokensize = 0;

	switch ( pptr->state ) {
		case	_PARSE_NAME	:
		case	_PARSE_TARGET	:
			convert = pptr->convert;
			break;
		case	_PARSE_CODE	:
			break;
		default			:
			convert = _PARSE_UPPER;
			break;
		}

	while (1) {
		if (!( c = abal_getch(pptr) ))
			break;
		else if ( c == '"' ) {
			pptr->token[pptr->tokensize++] = c;
			if (!( quoting ))
				quoting=1;
			else	{
				quoting=0;
				break;
				}
			}
		else if (( c >= 'a') && ( c <= 'z' )) {
			if (( convert == _PARSE_UPPER ) && (!( quoting )))
				pptr->token[pptr->tokensize++] = ((c - 'a') + 'A');
			else	pptr->token[pptr->tokensize++] = c;
			}
		else if (( c >= 'A') && ( c <= 'Z' )) {
			if (( convert == _PARSE_LOWER ) && (!( quoting )))
				pptr->token[pptr->tokensize++] = ((c - 'A') + 'a');
			else	pptr->token[pptr->tokensize++] = c;
			}
		else if (( c >= '0') && ( c <= '9' ))
			pptr->token[pptr->tokensize++] = c;
		else if (( c == '.') || ( c == '_' ))
			pptr->token[pptr->tokensize++] = c;
		else if ( quoting )
			pptr->token[pptr->tokensize++] = c;
		else	{
			pptr->ungotc = c;
			break;
			}
		}
	pptr->token[pptr->tokensize] = 0;
	return(pptr->tokensize);
}

private	int	abal_get_punctuation( struct abal_parser_context * pptr )
{
	int	c;
	if (!(c = abal_white_space( pptr ) ))
		return(0);
	else 	return((pptr->punctuation = abal_getch(pptr)));
}

private	int	is_dcl_keyword( char * sptr )
{
	int	i;
	for ( i=0; i < _MAX_PARSE_KEYWORD; i++ )
		if (!( strcmp( sptr, abal_parse_keyword[i] ) ))
			return(i);
	return(-1);
}

private	int	abal_token_hash( char * tptr )
{
	int	h=0;
	if (!( tptr ))
		return(0);
	for ( h=0; *tptr != 0; tptr++)
		h += *tptr;
	return(( h % 57 ));
}

private	int	abal_drop_constant( struct abal_parser_constant * cptr )
{
	if ( cptr ) {
		if ( cptr->name )
			liberate( cptr->name );
		if ( cptr->value)
			liberate( cptr->value);
		liberate( cptr );
		}
	return( 0 );
}

private	int	abal_drop_constants( struct abal_parser_context * pptr )
{
	struct	abal_parser_constant * cptr;
	if (!( pptr ))
		return(0);
	while ((cptr = pptr->firstconstant) != (struct abal_parser_context *) 0) {
		pptr->firstconstant = cptr->next;
		abal_drop_constant( cptr );
		}
	return(0);
}

private	int	abal_use_constant( struct abal_parser_context * pptr )
{
	struct	abal_parser_constant * cptr;
	if (!( pptr ))
		return(0);
	else if (!(cptr = allocate( sizeof( struct abal_parser_constant ) ) ))
		return(0);
	else	{
		cptr->previous = cptr->next  = (struct abal_parser_constant *) 0;
		cptr->name     = cptr->value = (char *) 0;
		cptr->type     = cptr->hash  = 0;
		if (!( cptr->name = allocate( strlen( pptr->operand ) + 1 ))) {
			abal_drop_constant( cptr );
			return(0);
			}
		else	strcpy(cptr->name,pptr->operand);
		if (!( cptr->value = allocate( strlen( pptr->token ) + 1 ))) {
			abal_drop_constant( cptr );
			return(0);
			}
		else	strcpy(cptr->value,pptr->token);
		cptr->hash = abal_token_hash( cptr->name );
		if (!( cptr->previous = pptr->lastconstant ))
			pptr->firstconstant = cptr;
		else	pptr->lastconstant->next = cptr;
		pptr->lastconstant = cptr;
		return(0);
		}
}

private	int	htoi( char * hptr )
{
	int	result=0;
	int	c;
	if ( *(hptr++) != '/' )
		return(0);
	while ((c = *(hptr++)) != 0) {
		if (( c >= 'a' ) && ( c <= 'f' ))
			result = ((result * 16) + ((c - 'a') + 10));
		else if (( c >= 'A' ) && ( c <= 'F' ))
			result = ((result * 16) + ((c - 'A') + 10));
		else if (( c >= '0' ) && ( c <= '9' ))
			result = ((result * 16) + (c - '0'));
		else	break;
		}
	return( result );
}

private	int	abal_atoi_token( struct abal_parser_context * pptr )
{
	struct	abal_parser_constant * cptr;
	int	h;
	if (!( pptr ))
		return(0);
	else if (( pptr->token[0] >= '0' ) && ( pptr->token[0] <= '9' ))
		return(atoi( pptr->token ));
	else if ( pptr->token[0] == '/' )
		return(htoi( pptr->token ));
	
	h = abal_token_hash( pptr->token );
	for (	cptr = pptr->firstconstant;
		cptr != (struct abal_parser_constant *) 0;
		cptr = cptr->next ) {
		if ( cptr->hash != h )
			continue;
		else if ( strcmp( pptr->token, cptr->name ) )
			continue;
		else if (!( cptr->value ))
			return( 0 );
		else if ( *cptr->value == '/' )
			return(htoi( cptr->value ));
		else	return(atoi( cptr->value ));
		}
	return( 0 );
}

private	int	abal_use_token( struct abal_parser_context * pptr )
{
	int	v;
	switch ( pptr->state ) {
		case	_PARSE_VALUE	:
			abal_use_constant( pptr );
			(pptr->relay->use_declaration)( pptr );
			pptr->level = 0;
			pptr->state = _PARSE_KEYWORD;
			return(1);

		case	_PARSE_KEYWORD	:
			switch ((v = is_dcl_keyword( pptr->token ))) {
				case _PARSE_KW_FIELD	:
					pptr->stack[pptr->level++] = v;
					pptr->state = _PARSE_EQUALS;
					return(1);

				case _PARSE_KW_END	:
					return( (pptr->relay->use_end)( pptr ) );

				case _PARSE_KW_EXTERN	:
				case _PARSE_KW_FORWARD	:
					pptr->stack[pptr->level++] = v;
					return(1);

				case _PARSE_KW_PROC	:
				case _PARSE_KW_SEGMENT	:
				case _PARSE_KW_PROGRAM	:
				case _PARSE_KW_MODULE	:
				case _PARSE_KW_DCL	:
				case _PARSE_KW_PTR	:
				case _PARSE_KW_CONST	:
				case _PARSE_KW_ARG	:
					pptr->stack[pptr->level++] = v;
					pptr->state = _PARSE_NAME;
					return(1);

				case _PARSE_KW_FILLER	:
				case _PARSE_KW_LIKE	:
				case _PARSE_KW_M		:
				case _PARSE_KW_E		:

				default			:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}

		case	_PARSE_CODE	:
			return( (pptr->relay->use_token)( pptr ) );

		case	_PARSE_DIRECTIVE	:
			strcpy(pptr->operand,pptr->token);
			pptr->state = _PARSE_KEYWORD;			
			pptr->level = 0;
			return( (pptr->relay->use_directive)( pptr ) );

		case	_PARSE_NAME	:
			strcpy(pptr->operand,pptr->token);
			switch ( pptr->stack[0]  ) {
				case _PARSE_KW_PROC	:
					pptr->level = 0;
					pptr->state = _PARSE_CODE;
					return( (pptr->relay->use_procedure)( pptr ) );
				case _PARSE_KW_SEGMENT	:
					pptr->level = 0;
					pptr->state = _PARSE_CODE;
					return( (pptr->relay->use_segment)( pptr ) );
				case _PARSE_KW_PROGRAM	:
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return( (pptr->relay->use_program)( pptr ) );
				case _PARSE_KW_MODULE	:
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return( (pptr->relay->use_module)( pptr ) );
				case _PARSE_KW_DCL	:
				case _PARSE_KW_PTR	:
				case _PARSE_KW_CONST	:
				case _PARSE_KW_ARG	:
					pptr->state = _PARSE_TYPE;
					return(1);
				default			:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}
		case	_PARSE_SIZEVALUE	:
			pptr->stack[pptr->level++] = abal_atoi_token( pptr );
			pptr->state = _PARSE_LEFT;
			return(1);
		case	_PARSE_FIRSTVALUE	:
			pptr->stack[pptr->level++] = abal_atoi_token( pptr );
			pptr->state = _PARSE_SECOND;
			return(1);
		case	_PARSE_SECONDVALUE	:
			pptr->stack[pptr->level++] = abal_atoi_token( pptr );
			pptr->state = _PARSE_RIGHT;
			return(1);
		case	_PARSE_TARGETFIRST	:
			pptr->stack[pptr->level++] = abal_atoi_token( pptr );
			pptr->state = _PARSE_TARGETNEXT;
			return(1);
		case	_PARSE_TARGETSECOND	:
			pptr->stack[pptr->level++] = abal_atoi_token( pptr );
			pptr->state = _PARSE_TARGETRIGHT;
			return(1);
		case	_PARSE_TARGET		:
			strcpy(pptr->operand,pptr->token);
			pptr->state = _PARSE_TARGETLEFT;
			pptr->stack[3] = pptr->stack[4] = 0;
			return(1);

		case	_PARSE_FIELD		:
			switch ((v = is_dcl_keyword( pptr->token ))) {
				case _PARSE_KW_M		:
					pptr->stack[pptr->level++] = _PARSE_KW_FIELD;
					pptr->stack[pptr->level++] = 0;
					pptr->state = _PARSE_REDEFINE;
					return(1);
				case _PARSE_KW_E		:
					pptr->stack[pptr->level++] = _PARSE_KW_FIELD;
					pptr->stack[pptr->level++] = 64;
					pptr->state = _PARSE_REDEFINE;
					return(1);
				default			:
					/* should be a field = file */
					pptr->stack[pptr->level++] = _PARSE_KW_FIELD;
					pptr->stack[pptr->level++] = abal_atoi_token( pptr );
					pptr->state = _PARSE_REDEFINE;
					return(1);
				}
		default			:
			return( (pptr->relay->syntax_error)( pptr, 1 ) );
		}
}

private	int	abal_use_punctuation( struct abal_parser_context * pptr )
{
	switch ( pptr->state ) {
		case	_PARSE_VALUE	:
			return( (pptr->relay->syntax_error)( pptr, 1 ) );

		case	_PARSE_EQUALS	:
			if ( pptr->punctuation != '=' )
				return( (pptr->relay->syntax_error)( pptr, 1 ) );
			else	{
				switch ( pptr->stack[0]  ) {
					case	_PARSE_KW_CONST	:
						pptr->state = _PARSE_VALUE;
						return(1);
					default			:
						pptr->state = _PARSE_FIELD;
						return(1);
					}
				}

		case	_PARSE_KEYWORD	:
			if ( pptr->punctuation == '\n' )
				return(1);
			else if ( pptr->punctuation == '#' ) {
				pptr->state = _PARSE_DIRECTIVE;
				return(1);
				}

		case	_PARSE_DIRECTIVE	:
		case	_PARSE_NAME		:
			return( (pptr->relay->syntax_error)( pptr, 0 ) );

		case	_PARSE_CODE	:
			return( (pptr->relay->use_punctuation)( pptr ) );

		case	_PARSE_REDEFINE	:
			switch ( pptr->punctuation ) {
				case	10	:
					(pptr->relay->reset_field)( pptr );
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				case	','	:
					pptr->state = _PARSE_TARGET;
					return(1);

				default		:
					return( (pptr->relay->syntax_error)( pptr, 0 ) );
				}
	
		case	_PARSE_LENGTH	:
			switch ( pptr->punctuation ) {
				case '=' 	:
					pptr->state = _PARSE_SIZEVALUE;
					return(1);
				case '(' 	:
					pptr->level++;
					pptr->state = _PARSE_LEFT;
					pptr->ungotc = pptr->punctuation;
					return(1);
				case ',' 	:
					if ( pptr->level == 2 )
						pptr->level++;
					(pptr->relay->use_declaration)( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_NAME;			
					return(1);

				case '\n'	:
					if ( pptr->level == 2 )
						pptr->level++;
					(pptr->relay->use_declaration)( pptr );
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );

				}

		case	_PARSE_TARGETRIGHT	:
			switch ( pptr->punctuation ) {
				case 	')'	:
					(pptr->relay->use_field)(pptr);
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}

		case	_PARSE_TARGETNEXT	:
			switch ( pptr->punctuation ) {
				case	','	:
					pptr->state = _PARSE_TARGETSECOND;
					return(1);
				case 	')'	:
					(pptr->relay->use_field)(pptr);
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}

		case	_PARSE_TARGETLEFT	:
			switch ( pptr->punctuation ) {
				case	'('	:
					pptr->state = _PARSE_TARGETFIRST;
					return(1);
				case '\n'	:
					(pptr->relay->use_field)(pptr);
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}

		case	_PARSE_LEFT	:
			switch ( pptr->punctuation ) {
				case	'('	:
					pptr->state = _PARSE_FIRSTVALUE;
					return(1);
				case ',' 	:
					if ( pptr->level == 2 )
						pptr->level++;
					(pptr->relay->use_declaration)( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_NAME;			
					return(1);

				case '\n'	:
					if ( pptr->level == 2 )
						pptr->level++;
					(pptr->relay->use_declaration)( pptr );
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}
		case	_PARSE_SECOND	:
			switch ( pptr->punctuation ) {
				case	')'	:
					(pptr->relay->use_declaration)( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_MORE;			
					return(1);
				case	','	:
					pptr->state = _PARSE_SECONDVALUE;
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}

		case	_PARSE_MORE	:
			switch ( pptr->punctuation ) {
				case	','	:
					pptr->level = 1;
					pptr->state = _PARSE_NAME;			
					return(1);
				case	'\n'	:
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}
		case	_PARSE_RIGHT	:
			switch ( pptr->punctuation ) {
				case	')'	:
					(pptr->relay->use_declaration)( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_MORE;			
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );
				}
		case	_PARSE_TYPE	:
			switch ( pptr->punctuation ) {
				case	'#'	:
					pptr->stack[pptr->level++] = _ABAL_BYTE;
					pptr->stack[pptr->level++] = 1;
					switch ( pptr->stack[0]  ) {
						case	_PARSE_KW_CONST	:
							pptr->state = _PARSE_EQUALS;
							return(1);
						default			:
							pptr->state = _PARSE_LEFT;
							return(1);
						}
			
				case	0x0025	:
					pptr->stack[pptr->level++] = _ABAL_WORD;
					pptr->stack[pptr->level++] = 2;
					switch ( pptr->stack[0]  ) {
						case	_PARSE_KW_CONST	:
							pptr->state = _PARSE_EQUALS;
							return(1);
						default			:
							pptr->state = _PARSE_LEFT;
							return(1);
						}

				case	':'	:
					pptr->stack[pptr->level++] = _ABAL_LONG;
					pptr->stack[pptr->level++] = 4;
					switch ( pptr->stack[0]  ) {
						case	_PARSE_KW_CONST	:
							pptr->state = _PARSE_EQUALS;
							return(1);
						default			:
							pptr->state = _PARSE_LEFT;
							return(1);
						}

				case	'$'	:
					pptr->stack[pptr->level++] = _ABAL_STRING;
					pptr->stack[pptr->level] = 15;
					switch ( pptr->stack[0]  ) {
						case	_PARSE_KW_CONST	:
							pptr->state = _PARSE_EQUALS;
							return(1);
						default			:
							pptr->state = _PARSE_LENGTH;
							return(1);
						}
				case	'='	:
					pptr->stack[pptr->level++] = _ABAL_BCD;
					pptr->stack[pptr->level] = 8;
					pptr->ungotc = pptr->punctuation;
					switch ( pptr->stack[0]  ) {
						case	_PARSE_KW_CONST	:
							pptr->state = _PARSE_EQUALS;
							return(1);
						default			:
							pptr->state = _PARSE_LENGTH;
							return(1);
						}
					pptr->state = _PARSE_LENGTH;
					return(1);
				case	'('	:
					pptr->stack[pptr->level++] = _ABAL_BCD;
					pptr->stack[pptr->level++] = 8;
					pptr->state = _PARSE_LEFT;
					pptr->ungotc = pptr->punctuation;
					return(1);
				case	','	:
					pptr->stack[pptr->level++] = _ABAL_BCD;
					pptr->stack[pptr->level++] = 8;
					(pptr->relay->use_declaration)( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_NAME;			
					return(1);
				default		:
					return( (pptr->relay->syntax_error)( pptr, 1 ) );

				}

		default			:
			return(1);
		}
}

private	int	abal_parse_file( struct abal_parser_context * pptr, char * nomfic )
{
	if (!( pptr->handle = fopen( nomfic, "r" ) ))
		return(40);
	else	{
		pptr->state = _PARSE_KEYWORD;
		while (1) {
			if ( (pptr->get_token)(pptr) ) {
				if (!( abal_use_token(pptr) ))
					break;
				else	continue;
				}
			else if (!( (pptr->get_punctuation)(pptr) ))
				break;
			else if (!( abal_use_punctuation(pptr) ))
				break;
			}
		fclose(pptr->handle);
		return ( 0 );
		}
}

public	int	parse_abal_inclusion(
		char * nomfic,
		int convert, int echo,
		struct abal_relay * rptr, 
		void * vptr )
{
	char *	eptr;
	int	result;
	struct	abal_parser_context Parser;
	if (!( Parser.relay = rptr ))
		return(118);
	else if (!( Parser.application = vptr ))
		return(118);
	else	{
		Parser.firstconstant =
		Parser.lastconstant = (struct abal_parser_constant *) 0;
		Parser.linecount = 0;
		Parser.columncount = 0;
		Parser.ungotc = 
		Parser.tokensize = 
		Parser.punctuation = 
		Parser.state =
		Parser.level = 
		Parser.stack[0] = 0;
		if (!( eptr = getenv( "ABALECHO" )))
			Parser.echo = echo;
		else if ( *eptr != '0' )
			Parser.echo = 1;
		else	Parser.echo = 0;

		Parser.convert = convert;
		Parser.get_token = abal_get_token;
		Parser.get_punctuation = abal_get_punctuation;
		Parser.parse_file = abal_parse_file;
		}
	result = (*Parser.parse_file)(&Parser,nomfic);
	abal_drop_constants( &Parser );
	return( result );
}

#include "parsefile.c"
#include "parseform.c"

#endif	/* _parseabal_c */
	/* ------------ */


