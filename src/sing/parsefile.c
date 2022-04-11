#ifndef	_parsefile_c
#define	_parsefile_c

#include	"parsefile.h"

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

private	void	file_use_field( struct abal_parser_context * pptr ) 
{
	int	i;
	int	t;
	struct	data_control * dptr;
	struct	file_parser_application * aptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application))
		return;
	else if (!( dptr = aptr->data ))
		return;
	i = (dptr->indexfields+dptr->datafields);
	if (!( dptr->name[ i ] = allocate_string( pptr->operand ) ))
		return;
	else	{
		dptr->type[i] = _ABAL_FIELD;
		dptr->width[i] = 0;
		dptr->special[i] = 1;
		dptr->first[i] = pptr->stack[3];
		dptr->second[i] = pptr->stack[4];
		if ( aptr->nature )
			dptr->indexfields++;
		else	dptr->datafields++;
		}
	return;
}
	
private	void	file_use_filler( struct abal_parser_context * pptr ) 
{
	int	i;
	int	t;
	struct	data_control * dptr;
	struct	file_parser_application * aptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application))
		return;
	else if (!( dptr = aptr->data ))
		return;
	i = (dptr->indexfields+dptr->datafields);
	if (!( dptr->name[ i ] = allocate_string( pptr->operand ) ))
		return;
	else	{
		dptr->type[i] = _ABAL_FILLER;
		dptr->special[i] = 1;
		dptr->width[i] = pptr->stack[2];
		if ( aptr->nature ) 
			dptr->indexfields++;
		else	dptr->datafields++;
		}
	return;
}
	
private	void	file_reset_field( struct abal_parser_context * pptr ) 
{
	struct	data_control * dptr;
	struct	file_parser_application * aptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application))
		return;
	else	{
		aptr->nature = 0;
		return;
		}
}

private	int	file_check_declaration( struct abal_parser_context * pptr ) 
{
	struct	file_parser_application * aptr;
	if (!( pptr ))
		return(1);
	else if (!( aptr = pptr->application))
		return(1);

	if ( aptr->markername ) {
		if (!( strcmp( pptr->operand, aptr->markername ) ))
			return(0);
		}
	if ( aptr->indexname ) {
		if (!( strcmp( pptr->operand, aptr->indexname ) )) {
			aptr->nature = 1;
			}
		}
	if ( aptr->recordname ) {
		if (!( strcmp( pptr->operand, aptr->recordname ) )) {
			aptr->nature = 0;
			}
		}
	return(1);
}

private	void	file_use_declaration( struct abal_parser_context * pptr ) 
{
	int	i;
	int	t;
	struct	data_control * dptr;
	struct	file_parser_application * aptr;
	if (!( pptr ))
		return;
	else if ( pptr->stack[0] == _PARSE_KW_CONST )
		return;		
	else if (!( aptr = pptr->application))
		return;
	else if (!( dptr = aptr->data ))
		return;

	else if (!( file_check_declaration( pptr ) ))
		return;

	switch ( pptr->stack[0] ) {
		case _PARSE_KW_DCL	:
		case _PARSE_KW_PTR	:
		case _PARSE_KW_ARG	:
			switch ((t = pptr->stack[1])) {
				case	_ABAL_BYTE	:
				case	_ABAL_WORD	:
				case	_ABAL_LONG	:
				case	_ABAL_STRING	:
				case	_ABAL_BCD	:
					switch ( pptr->convert ) {
						case _PARSE_UPPER	:
							if (!( strcmp( pptr->operand, "FILLER" ) )) {
								(pptr->relay->use_filler)( pptr );	
								return;
								}
							else	break;
						case _PARSE_LOWER	:
							if (!( strcmp( pptr->operand, "filler" ) )) {
								(pptr->relay->use_filler)( pptr );	
								return;
								}
							else	break;
						default			:
							if (!( strcmp( pptr->operand, "FILLER" ) )) {
								(pptr->relay->use_filler)( pptr );	
								return;
								}
							else if (!( strcmp( pptr->operand, "filler" ) )) {
								(pptr->relay->use_filler)( pptr );	
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
						if ( aptr->nature ) {
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

public	void	recalculate_file_sizes( struct file_control * fptr )
{
	FileManager->current = fptr;
	switch ((fptr->nature & 0x000F)) {
		case	_VMEMORY_FRAME	:
			return;
		}
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

public	int	parse_file_inclusion(char * nomfic, struct file_control * fptr, int convert, char * iname, char * mname, char * rname)
{
	int	status;
	struct	abal_relay FileRelay = {
		abal_parser_syntax_error, 	/* error	*/
		file_use_field,			/* field=m,truc	*/
		file_use_declaration,		/* dcl etc	*/
		file_use_filler,		/* filler 	*/
		file_reset_field,		/* field=m	*/
		abal_parser_not_implemented,	/* proc 	*/
		abal_parser_not_implemented,	/* segment	*/
		abal_parser_not_implemented,	/* program	*/
		abal_parser_not_implemented,	/* module	*/
		abal_parser_not_implemented,	/* end		*/
		abal_parser_not_implemented,	/* directive	*/
		abal_parser_not_implemented,	/* token	*/
		abal_parser_not_implemented,	/* punctuation  */
		abal_parser_not_implemented	/* space	*/

		};
	struct	file_parser_application FDA;

	if (!( FDA.file	= fptr ))
		return;
	else if (!( FDA.data = fptr->payload ))
		return;
	else	{
		if (!( iname ))
			FDA.indexname = (char *) 0;
		else	FDA.indexname = allocate_string(iname);
		abal_token_case( FDA.indexname, convert );

		if (!( mname ))
			FDA.markername = (char *) 0;
		else	FDA.markername 	= allocate_string(mname);
		abal_token_case( FDA.markername, convert );

		if (!( iname ))
			FDA.recordname = (char *) 0;
		else	FDA.recordname = allocate_string(rname);
		abal_token_case( FDA.recordname, convert );
		FDA.nature = 0;
		status = parse_abal_inclusion( nomfic, convert, 0, &FileRelay, &FDA );
		if ( FDA.indexname  )	{ liberate( FDA.indexname  ); }
		if ( FDA.markername )	{ liberate( FDA.markername ); }
		if ( FDA.recordname )	{ liberate( FDA.recordname ); }
		if ( status != 0 )
			return( status );
		else	{
			if ( FDA.file )
				recalculate_file_sizes( FDA.file );
			return(0);
			}
		}
}

#endif 	/* _parsefile_c */
	/* ------------ */

