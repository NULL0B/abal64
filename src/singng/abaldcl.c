#ifndef	_abaldcl_c
#define	_abaldcl_c

#include <stdio.h>
#include "abaldcl.h"

private	int	abal_syntax_error( struct abal_parser_context * pptr, int mode )
{
	if ( mode )
		printf("\nsyntax error : incorrect token : %s \n",pptr->token);
	else	printf("\nsyntax error : punctuation     : %c \n",pptr->punctuation);
	return(0);
}



private	void	abal_use_field( struct abal_parser_context * pptr ) 
{
	int	i;
	int	t;
	struct	data_control * dptr;
	if (!( pptr ))
		return;
	else if (!( dptr = pptr->data ))
		return;
	i = (dptr->indexfields+dptr->datafields);
	if (!( dptr->name[ i ] = allocate_string( pptr->operand ) ))
		return;
	else	{
		dptr->type[i] = _ABAL_FIELD;
		dptr->width[i] = 0;
		dptr->special[i] = 1;
		if ( pptr->nature )
			dptr->indexfields++;
		else	dptr->datafields++;
		}
	return;
}
	
private	void	abal_use_filler( struct abal_parser_context * pptr ) 
{
	int	i;
	int	t;
	struct	data_control * dptr;
	if (!( pptr ))
		return;
	else if (!( dptr = pptr->data ))
		return;
	i = (dptr->indexfields+dptr->datafields);
	if (!( dptr->name[ i ] = allocate_string( pptr->operand ) ))
		return;
	else	{
		dptr->type[i] = _ABAL_FILLER;
		dptr->special[i] = 1;
		dptr->width[i] = pptr->stack[2];
		if ( pptr->nature ) 
			dptr->indexfields++;
		else	dptr->datafields++;
		}
	return;
}
	
private	void	abal_reset_field( struct abal_parser_context * pptr ) 
{
	pptr->nature = 0;
	return;
}

private	int	abal_check_declaration( struct abal_parser_context * pptr ) 
{
	if (!( pptr ))
		return;
	if ( pptr->markername ) {
		if (!( strcmp( pptr->operand, pptr->markername ) ))
			return(0);
		}
	if ( pptr->indexname ) {
		if (!( strcmp( pptr->operand, pptr->indexname ) )) {
			pptr->nature = 1;
			}
		}
	if ( pptr->recordname ) {
		if (!( strcmp( pptr->operand, pptr->recordname ) )) {
			pptr->nature = 0;
			}
		}
	return(1);
}

private	void	abal_use_declaration( struct abal_parser_context * pptr ) 
{
	int	i;
	int	t;
	struct	data_control * dptr;
	if (!( pptr ))
		return;
	else if (!( dptr = pptr->data ))
		return;

	else if (!( abal_check_declaration( pptr ) ))
		return;

	switch ( pptr->stack[0] ) {
		case _DCL_KW_DCL	:
		case _DCL_KW_PTR	:
		case _DCL_KW_CONST	:
		case _DCL_KW_ARG	:
			switch ((t = pptr->stack[1])) {
				case	_ABAL_BYTE	:
				case	_ABAL_WORD	:
				case	_ABAL_LONG	:
				case	_ABAL_STRING	:
				case	_ABAL_BCD	:
					switch ( pptr->convert ) {
						case _PARSE_UPPER	:
							if (!( strcmp( pptr->operand, "FILLER" ) )) {
								abal_use_filler( pptr );	
								return;
								}
							else	break;
						case _PARSE_LOWER	:
							if (!( strcmp( pptr->operand, "filler" ) )) {
								abal_use_filler( pptr );	
								return;
								}
							else	break;
						default			:
							if (!( strcmp( pptr->operand, "FILLER" ) )) {
								abal_use_filler( pptr );	
								return;
								}
							else if (!( strcmp( pptr->operand, "filler" ) )) {
								abal_use_filler( pptr );	
								return;
								}
							else	break;
						}
					i = (dptr->indexfields+dptr->datafields);
					if (!( dptr->name[ i ] = allocate_string( pptr->operand ) ))
						break;
					else	{
						dptr->type[i] = t;
						dptr->width[i] = pptr->stack[2];
						if ( pptr->level > 3 ) {
							dptr->first[i] = pptr->stack[3];
							if ( pptr->level > 4 )
								dptr->second[i] = pptr->stack[3];
							else	dptr->second[i] = 0;
							}
						else	dptr->second[i] = dptr->first[i] = 0;
						if ( pptr->nature ) {
							dptr->indexfields++;
							dptr->special[i] = 1;
							}
						else	{
							dptr->datafields++;
							dptr->special[i] = 0;
							}
						}
					break;
				}
			}
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
	else	return( c );
}

private	int	abal_getch( struct abal_parser_context * pptr )
{
	int	c;
	c = ll_abal_getch(pptr);
	if ( pptr->echo )
		printf("%c",c);
	return(c);
}

private	int	abal_eol( struct abal_parser_context * pptr )
{
	int	c;
	while ((c = abal_getch( pptr )) != '\n')
		if (!( c ))
			break;
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
				return(0);
			case	' '	:
			case	'\t'	:
				continue;
			case	'\r'	:
			case	';'	:
				return( abal_eol(pptr) );
			default		:
				return((pptr->ungotc = c));
				
			}
		}	
}

private	int	abal_get_token( struct abal_parser_context * pptr )
{
	int	c;
	int	convert=0;
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
		default			:
			convert = _PARSE_UPPER;
			break;
		}

	while (1) {
		if (!( c = abal_getch(pptr) ))
			break;
		else if (( c >= 'a') && ( c <= 'z' )) {
			if ( convert == _PARSE_UPPER )
				pptr->token[pptr->tokensize++] = ((c - 'a') + 'A');
			else	pptr->token[pptr->tokensize++] = c;
			}
		else if (( c >= 'A') && ( c <= 'Z' )) {
			if ( convert == _PARSE_LOWER )
				pptr->token[pptr->tokensize++] = ((c - 'A') + 'a');
			else	pptr->token[pptr->tokensize++] = c;
			}
		else if (( c >= '0') && ( c <= '9' ))
			pptr->token[pptr->tokensize++] = c;
		else if (( c == '.') && ( c == '_' ))
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
	for ( i=0; i < _MAX_DCL_KEYWORD; i++ )
		if (!( strcmp( sptr, abal_dcl_keyword[i] ) ))
			return(i);
	return(-1);
}

private	int	abal_use_token( struct abal_parser_context * pptr )
{
	int	v;
	switch ( pptr->state ) {
		case	_PARSE_KEYWORD	:
			switch ((v = is_dcl_keyword( pptr->token ))) {
				case _DCL_KW_FIELD	:
					pptr->stack[pptr->level++] = v;
					pptr->state = _PARSE_EQUALS;
					return(1);

				case _DCL_KW_DCL	:
				case _DCL_KW_PTR	:
				case _DCL_KW_CONST	:
				case _DCL_KW_ARG	:
					pptr->stack[pptr->level++] = v;
					pptr->state = _PARSE_NAME;
					return(1);

				case _DCL_KW_FILLER	:
				case _DCL_KW_LIKE	:
				case _DCL_KW_M		:
				case _DCL_KW_E		:

				default			:
					return( abal_syntax_error( pptr, 1 ) );
				}
		case	_PARSE_NAME	:
			strcpy(pptr->operand,pptr->token);
			switch ( pptr->stack[(pptr->level-1)]  ) {
				case _DCL_KW_DCL	:
				case _DCL_KW_PTR	:
				case _DCL_KW_CONST	:
				case _DCL_KW_ARG	:
					pptr->state = _PARSE_TYPE;
					return(1);
				default			:
					return( abal_syntax_error( pptr, 1 ) );
				}
		case	_PARSE_SIZEVALUE	:
			pptr->stack[pptr->level++] = atoi( pptr->token );
			pptr->state = _PARSE_LEFT;
			return(1);
		case	_PARSE_FIRSTVALUE	:
			pptr->stack[pptr->level++] = atoi( pptr->token );
			pptr->state = _PARSE_SECOND;
			return(1);
		case	_PARSE_SECONDVALUE	:
			pptr->stack[pptr->level++] = atoi( pptr->token );
			pptr->state = _PARSE_RIGHT;
			return(1);
		case	_PARSE_TARGET		:
			strcpy(pptr->operand,pptr->token);
			abal_use_field(pptr);
			pptr->level = 0;
			pptr->state = _PARSE_KEYWORD;
			return(1);

		case	_PARSE_FIELD		:
			switch ((v = is_dcl_keyword( pptr->token ))) {
				case _DCL_KW_M		:
				case _DCL_KW_E		:
					pptr->stack[pptr->level++] = _DCL_KW_FIELD;
					pptr->stack[pptr->level++] = v;
					pptr->state = _PARSE_REDEFINE;
					return(1);
				default			:
					return( abal_syntax_error( pptr, 1 ) );
				}
		default			:
			return( abal_syntax_error( pptr, 1 ) );
		}
}

private	int	abal_use_punctuation( struct abal_parser_context * pptr )
{
	switch ( pptr->state ) {
		case	_PARSE_EQUALS	:
			if ( pptr->punctuation != '=' )
				return( abal_syntax_error( pptr, 1 ) );
			else	{
				pptr->state = _PARSE_FIELD;
				return(1);
				}

		case	_PARSE_KEYWORD	:
			if ( pptr->punctuation == '\n' )
				return(1);
		case	_PARSE_NAME	:
			return( abal_syntax_error( pptr, 0 ) );

		case	_PARSE_REDEFINE	:
			switch ( pptr->punctuation ) {
				case	10	:
					abal_reset_field( pptr );
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				case	','	:
					pptr->state = _PARSE_TARGET;
					return(1);

				default		:
					return( abal_syntax_error( pptr, 0 ) );
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
					abal_use_declaration( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_NAME;			
					return(1);

				case '\n'	:
					if ( pptr->level == 2 )
						pptr->level++;
					abal_use_declaration( pptr );
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( abal_syntax_error( pptr, 1 ) );

				}

		case	_PARSE_LEFT	:
			switch ( pptr->punctuation ) {
				case	'('	:
					pptr->state = _PARSE_FIRSTVALUE;
					return(1);
				case ',' 	:
					if ( pptr->level == 2 )
						pptr->level++;
					abal_use_declaration( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_NAME;			
					return(1);

				case '\n'	:
					if ( pptr->level == 2 )
						pptr->level++;
					abal_use_declaration( pptr );
					pptr->level = 0;
					pptr->state = _PARSE_KEYWORD;
					return(1);
				default		:
					return( abal_syntax_error( pptr, 1 ) );
				}
		case	_PARSE_SECOND	:
			switch ( pptr->punctuation ) {
				case	')'	:
					abal_use_declaration( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_MORE;			
					return(1);
				case	','	:
					pptr->state = _PARSE_SECONDVALUE;
					return(1);
				default		:
					return( abal_syntax_error( pptr, 1 ) );
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
					return( abal_syntax_error( pptr, 1 ) );
				}
		case	_PARSE_RIGHT	:
			switch ( pptr->punctuation ) {
				case	')'	:
					abal_use_declaration( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_MORE;			
					return(1);
				default		:
					return( abal_syntax_error( pptr, 1 ) );
				}
		case	_PARSE_TYPE	:
			switch ( pptr->punctuation ) {
				case	'#'	:
					pptr->stack[pptr->level++] = _ABAL_BYTE;
					pptr->stack[pptr->level++] = 1;
					pptr->state = _PARSE_LEFT;
					return(1);
			
				case	0x0025	:
					pptr->stack[pptr->level++] = _ABAL_WORD;
					pptr->stack[pptr->level++] = 2;
					pptr->state = _PARSE_LEFT;
					return(1);
				case	':'	:
					pptr->stack[pptr->level++] = _ABAL_LONG;
					pptr->stack[pptr->level++] = 4;
					pptr->state = _PARSE_LEFT;
					return(1);
				
				case	'$'	:
					pptr->stack[pptr->level++] = _ABAL_STRING;
					pptr->stack[pptr->level] = 15;
					pptr->state = _PARSE_LENGTH;
					return(1);
				case	'='	:
					pptr->stack[pptr->level++] = _ABAL_BCD;
					pptr->stack[pptr->level] = 8;
					pptr->state = _PARSE_LENGTH;
					pptr->ungotc = pptr->punctuation;
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
					abal_use_declaration( pptr );
					pptr->level = 1;
					pptr->state = _PARSE_NAME;			
					return(1);
				default		:
					return( abal_syntax_error( pptr, 1 ) );

				}
		default			:
			return(1);
		}
}

private	void	abal_token_case( char * sptr, int convert)
{
	int	c;
	if (!( sptr ))
		return;
	else 	{
		switch ( convert ) {
			case	_PARSE_PRESERVE	:
				break;
			case	_PARSE_UPPER	:
				while ((c = *sptr) != 0) {
					if ((c >= 'a') && ( c <= 'z'))
						*sptr = ((c - 'a') + 'A');
					sptr++;
					}
				break;
			case	_PARSE_LOWER	:
				while ((c = *sptr) != 0) {
					if ((c >= 'A') && ( c <= 'Z'))
						*sptr = ((c - 'A') + 'a');
					sptr++;
					}
				break;
			}
		return;
		}
}

public	void	recalculate_file_sizes( struct file_control * fptr )
{
	FileManager->current = fptr;
	if ( fptr->payload->indexfields ) {
		fptr->payload->indexlength = 0;
		check_file_indexlength((void*) 0);
		}
	if ( fptr->payload->datafields ) {
		fptr->payload->datalength = 0;
		check_file_datalength((void*) 0);
		}
	return;
}

public	int	parse_abal_inclusion(
	char * nomfic, 
	struct file_control * fptr, 
	int convert, int echo,
	char * iname, char * mname, char * rname)
{
	struct	abal_parser_context Parser;
	Parser.indexname = iname;
	Parser.markername = mname;
	Parser.recordname = rname;
	Parser.ungotc = 
	Parser.tokensize = 
	Parser.punctuation = 
	Parser.state =
	Parser.level = 
	Parser.stack[0] = 0;
	Parser.echo = 0;
	Parser.nature = 0;
	Parser.Echo = echo;
	Parser.convert = convert;
	abal_token_case( iname, convert );
	abal_token_case( mname, convert );
	abal_token_case( rname, convert );
	if (!( Parser.file = fptr))
		return(118);
	else if (!( Parser.data = fptr->payload))
		return(118);
	else if (!( Parser.handle = fopen((Parser.name = nomfic), "r" ) ))
		return(40);
	else	{
		Parser.state = _PARSE_KEYWORD;
		while (1) {
			if ( abal_get_token(&Parser) ) {
				if (!( abal_use_token(&Parser) ))
					break;
				else	continue;
				}
			else if (!( abal_get_punctuation(&Parser) ))
				break;
			else if (!( abal_use_punctuation(&Parser) ))
				break;
			}
		fclose(Parser.handle);
		if (!( fptr ))
			return(0);
		else if (!( fptr->payload ))
			return(0);
		else 	{
			recalculate_file_sizes( fptr );
			return(0);
			}
		}
}


#endif	/* _abaldcl_c */
	/* ---------- */

