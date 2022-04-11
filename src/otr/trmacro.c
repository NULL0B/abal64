#ifndef	_TRMACRO_C
#define	_TRMACRO_C

/*	-----------------	*/
/*	 translate_macro	*/
/*	-----------------	*/
WORD	translate_macro()
{
	TCMEMBERPTR	member;
	if (!( get_token() ))
		return( syntax_error( 7700 ) );
	else if ((member = allocate_structure_member( TokenBuffer )) == (TCMEMBERPTR) 0)
		return( allocation_failure() );
	else	
	{
		member->next = World->Macros;
		World->Macros = member;
		return( translate_macro_method( member ) );
	}
}

/*	------------------	*/
/*	translate_endmacro	*/
/*	------------------	*/
WORD	translate_endmacro()
{
	return( terminate_macro_text() );
}

/*	------------	*/
/*	expand_macro	*/
/*	------------	*/
WORD	expand_macro()
{
	TCMEMBERPTR	mptr;
	WORD		status;

	if ((mptr = World->Macros) != (TCMEMBERPTR) 0) 
	{
		do	
		{
			if ((TokenHash == mptr->hash)
			&&  ( compare_tokens( TokenBuffer, mptr->name ))) 
			{
				if ((status = activate_macro( mptr, mptr->special )) != 0)
					return( 0 );
				else	return( 1 );
			}
		}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
	}

	return( 0 );
}

	/* ---------- */
#endif 	/* _TRMACRO_C */
	/* ---------- */

