#ifndef	_parseform_c
#define	_parseform_c

#include "parseform.h"
#include "singmeth.h"
#include "singmemb.h"

private	void	form_use_field( struct abal_parser_context * pptr ) 
{
	struct forms_data_member * mptr;
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	else if (!( mptr = allocate_for_Member() ))
		return;
	else if (!( mptr->name = allocate_string( pptr->operand ))) {
		liberate_Member( mptr );
		return;
		}
	else	{
		mptr->type = _ABAL_FIELD;
		add_Member( fptr, mptr );
		return;
		}
	return;
}

private	void	form_use_filler( struct abal_parser_context * pptr ) 
{
	struct forms_data_member * mptr;
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	else if (!( mptr = allocate_for_Member() ))
		return;
	else if (!( mptr->name = allocate_string( pptr->operand ))) {
		liberate_Member( mptr );
		return;
		}
	else	{
		mptr->type = _ABAL_FILLER;
		mptr->size = pptr->stack[2];
		add_Member( fptr, mptr );
		return;
		}
	return;
}

private	void	form_reset_field( struct abal_parser_context * pptr ) 
{
	struct forms_data_member * mptr;
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	else if (!( mptr = allocate_for_Member() )) {
		return;
		}
	else	{
		mptr->type = _ABAL_FIELD;
		add_Member( fptr, mptr );
		return;
		}
}

private	void	form_use_declaration( struct abal_parser_context * pptr ) 
{
	struct forms_data_member * mptr;
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	else if (!( mptr = allocate_for_Member() ))
		return;
	else if (!( mptr->name = allocate_string( pptr->operand ))) {
		liberate_Member( mptr );
		return;
		}
	else	{
		switch (pptr->stack[0]) {
		case _PARSE_KW_DCL	:
		case _PARSE_KW_PTR	:
		case _PARSE_KW_CONST	:
		case _PARSE_KW_ARG	:
			switch ((mptr->type = pptr->stack[1])) {
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
					mptr->size = pptr->stack[2];
					if ( pptr->level > 3 ) {
						mptr->first = pptr->stack[3];
						if ( pptr->level > 4 )
							mptr->second = pptr->stack[4];
						else	mptr->second = 0;
						}
					else	mptr->second = mptr->first = 0;
				}
			}
		add_Member( fptr, mptr );
		return;
		}
}

private	void	form_flush_bucket(struct form_parser_application * aptr)
{
	char *	tptr;
	int	tl;
	int	bl;
	if (!( aptr ))
		return;
	else if (!( aptr->method ))
		return;
	else if (!( bl = aptr->bytecount ))
		return;
	else	aptr->bytecount=0;

	if (!( tptr = aptr->method->text )) {
		if (!( aptr->method->text = allocate( bl+1 )))
			return;
		else	{
			memcpy(aptr->method->text,aptr->bucket,bl);
			*(aptr->method->text+bl) = 0;
			return;
			}
		}
	else	{
		tl = strlen( tptr );
		if (!( aptr->method->text = allocate( (bl+1+tl) ) )) {
			aptr->method->text = tptr;
			return;
			}
		else	{
			strcpy(aptr->method->text,tptr);
			memcpy(aptr->method->text+tl,aptr->bucket,bl);
			*(aptr->method->text+bl+tl) = 0;
			liberate( tptr );
			return;
			}
		}
}

private	void	bucket_add_byte( struct	form_parser_application  * aptr, int c )
{
	if ((aptr->bytecount + 1) > _PARSE_BUCKET_SIZE) 
		form_flush_bucket(aptr);
	aptr->bucket[aptr->bytecount++] = c;
	return;
}

private	void	bucket_add_token( struct	form_parser_application  * aptr, char * token )
{
	if ((aptr->bytecount + strlen( token )) > _PARSE_BUCKET_SIZE) 
		form_flush_bucket(aptr);
	strcpy( &aptr->bucket[aptr->bytecount], token );
	aptr->bytecount += strlen( token );
	return;
}

private	void	form_close_method( 
	struct abal_parser_context * pptr,
	struct	form_parser_application  * aptr )
{
	form_flush_bucket(aptr);
	pptr->state = _PARSE_KEYWORD;
	return;
}

private	void	form_use_signature( 
	struct abal_parser_context * pptr,
	struct	form_parser_application  * aptr )
{	
	struct	forms_method * mptr;
	int	braces=0;
	int	c;
	if (( c = (pptr->get_punctuation)(pptr)) != '(' )
		form_close_method( pptr, aptr );
	else 	{
		while (1) {
			if ( (pptr->get_token)(pptr) ) {
				bucket_add_token( aptr, pptr->token );
				continue;
				}
			else if ((c = (pptr->get_punctuation)(pptr)) == ')') {
				if (!( braces ))
					break;
				else	braces--;
				}
			else if ( c == '(' )
				braces++;
			bucket_add_byte( aptr, c );
			}
		form_flush_bucket(aptr);
		if (!( mptr = aptr->method ))
			return;
		mptr->type &= ~_METHOD_TYPE;
		mptr->type |=  _METHOD_VOID;
		if ((c = (pptr->get_punctuation)(pptr)) == '\n')
			return;
		else if ( c != ':' ) 
			return;
		else if ((c = (pptr->get_punctuation)(pptr)) == '\n')
			return;
		else	{
			switch ( c ) {
				case	'#'	:
					mptr->type &= ~_METHOD_TYPE;
					mptr->type |=  _METHOD_BYTE;
					break;
				case	0x0025	:
					mptr->type &= ~_METHOD_TYPE;
					mptr->type |=  _METHOD_WORD;
					break;
				case	'$'	:
					mptr->type &= ~_METHOD_TYPE;
					mptr->type |=  _METHOD_STRING;
					break;
				case	'*'	:
					mptr->type &= ~_METHOD_TYPE;
					mptr->type |=  _METHOD_NUMERIC;
					break;
				case	':'	:
					mptr->type &= ~_METHOD_TYPE;
					mptr->type |=  _METHOD_LONG;
					break;
				}
			return;
			}
		}
}

private	void	form_use_procedure( struct abal_parser_context * pptr ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	else if (!( aptr->method = allocate_for_Method() ))
		return;
	else if (!( aptr->method->name = allocate_string( pptr->token ))) {
		aptr->method = liberate_Method( aptr->method );
		return;
		}
	else	{
		aptr->method->type = (_METHOD_PUBLIC | _METHOD_FUNCTION);
		aptr->bytecount=0;
		if ( pptr->stack[0] == _PARSE_KW_EXTERN ) {
			aptr->method->type |= _METHOD_EXTERN;
			pptr->stack[0] = 0;
			}
		add_Method( fptr, aptr->method );
		form_use_signature( pptr, aptr );
		aptr->method->signature = aptr->method->text;
		if ( aptr->method->type & _METHOD_EXTERN )
			pptr->state = _PARSE_KEYWORD;
		aptr->method->text = (char *) 0;
		return;
		}
}

private	void	form_use_segment( struct abal_parser_context * pptr ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	else	{
		aptr->bytecount=0;
		return;
		}
}

private	void	form_use_program( struct abal_parser_context * pptr ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	return;
}

private	void	form_use_module( struct abal_parser_context * pptr ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	return;
}

private	void	form_use_end( struct abal_parser_context * pptr ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	return;
}

private	void	form_use_token( struct abal_parser_context * pptr ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( aptr->method ))
		return;
	else if ( upper_compare( pptr->token , "ENDPROC") ) {
		form_close_method(pptr,aptr);
		}
	else 	{
		bucket_add_token( aptr, pptr->token );
		return;
		}
}


private	void	form_use_punctuation( struct abal_parser_context * pptr ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( aptr->method ))
		return;
	else 	{
		bucket_add_byte( aptr, pptr->punctuation );
		return;
		}
}

private	void	form_use_directive( struct abal_parser_context * pptr )
{
	char *	nptr;
	int	i;
	int	c;
	struct	form_parser_application  * aptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( aptr->form ))
		return;
	else	{
		if (!( strcmp( pptr->operand, "INCLUDE" ))) {
			if (!( (pptr->get_token)(pptr) ))
				return;
			else if (!( nptr = pptr->token ))
				return;
			else if ( *nptr == '"' ) {
				nptr++;
				for (i=0; *(nptr+i) != 0; i++ )
					if ( *(nptr+i) == '"' )
						break;
				*(nptr+i) = 0;													
				}
			if (!( nptr = allocate_string( nptr ) ))
				return;
			else	{
				parse_form_inclusion( nptr, aptr->form, pptr->convert, pptr->echo );
				liberate( nptr );
				}
			}
		while (1) {
			if ( (pptr->get_token)(pptr) )
				continue;
			else if (!(c = (pptr->get_punctuation)(pptr)))
				break;
			else if ( c != '\n' )
				continue;
			else	break;
			}
		return;
		}

}

private	void	form_use_space( struct abal_parser_context * pptr, int c ) 
{
	struct	form_parser_application  * aptr;
	struct	form_control * fptr;
	if (!( pptr ))
		return;
	else if (!( aptr = pptr->application ))
		return;
	else if (!( aptr->method ))
		return;
	else if (!( fptr = aptr->form ))
		return;
	else 	{
		bucket_add_byte( aptr, c );
		return;
		}
}

public	int	parse_form_inclusion(char * nomfic, struct form_control * fptr, int convert, int echo )
{
	struct	abal_relay ProgramRelay = {
		abal_parser_syntax_error,	/* error	*/
		form_use_field,		/* field=m,truc	*/
		form_use_declaration,	/* dcl etc	*/
		form_use_filler,	/* filler 	*/
		form_reset_field,	/* field=m	*/
		form_use_procedure,	/* proc 	*/
		form_use_segment,   	/* segment	*/
		form_use_program,	/* program	*/
		form_use_module,	/* module	*/
		form_use_end,		/* end		*/
		form_use_directive,	/* # directive	*/
		form_use_token,		/* end		*/
		form_use_punctuation,	/* end		*/
		form_use_space		/* end		*/
		};
	struct	form_parser_application PGA;
	if (!( nomfic ))		return(118);
	else if (!( PGA.form = fptr ))	return(118);
	else	{
		PGA.bytecount=0;
		PGA.convert = convert;
		PGA.method  = (struct forms_method *) 0;
		return( parse_abal_inclusion( nomfic, convert, echo, &ProgramRelay, &PGA ) );
		}
}

public	void	import_Forms( struct form_control * fptr )
{
	char	*	nomfic=(char *) 0;
	int		convert=0;
	int		echo=0;
	if ( accept_abal_filename( &nomfic, &convert, &echo ) == 27 )
		return;
	else	{
		(void) parse_form_inclusion( nomfic, fptr, convert, echo );
		liberate( nomfic );
		return;
		}
}


#endif	/* _parseform_c */
	/* ------------ */

