/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990,1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	CBPARSER.C				*/
/*		Version :	2.2a					*/
/*		Date	:	26/01/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_CBPARSER_C
#define	_CBPARSER_C

#include "stdtypes.h"

WORD	CobolSyntax=VRAI;

#include "trparser.c"

VOID	set_cobol_syntax()
{
	CobolSyntax = VRAI;
	return;
}

VOID	set_abal_syntax()
{
	CobolSyntax = FAUX;
	return;
}

BPTR	get_parser_buffer()
{
	set_abal_syntax();
	return( LineBuffer );
}

VOID	set_parser_buffer( xptr )
BPTR	xptr;
{
	set_cobol_syntax();
	LineBuffer = xptr;
	return;
}

WORD	is_end_of_sentance()
{
	if (( is_white_space( *LineBuffer ) )
	||  ( *LineBuffer == 0 ))
		return( 1 );
	else	return( 0 );
}

WORD	unget_token()
{
	WORD	l;
	for ( l = strlen(TokenBuffer); l != 0; l-- )
		unget_byte();
	return( 0 );
}


#endif  /* _CBPARSER_C */
	/* ----------- */

