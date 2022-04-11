/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 2021 Amenesik / Sologic			*/
/*									*/
/*									*/
/*		File	:	TRPARSER.C				*/
/*		Version :	5.1 					*/
/*		Date	:	01/05/2021				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRPARSER_C
#define	_TRPARSER_C

#define	DEBUG

#include <stdio.h>		/* Standard IO handling routines	*/
#include <string.h>

#include "stdtypes.h"
#include "tctype.h"
#include "translat.h"
#include "trparser.h"
#include "troption.h"
#include "trlabels.h"
#include "trinput.h"
#include "trdebug.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"
#include "trerrors.h"
#include "trmethod.h"
#include "trsymbol.h"
#include "trdirect.h"
#include "trclass.h"
#include "trecho.h"

static	WORD	BalComment=1;
static	WORD	StarComment=1;
static	WORD	LabelStatus=1;
static	WORD	DiezeConstants=1;

/*	--------------	*/
/*	is_white_space	*/
/*	--------------	*/
WORD	is_white_space( c )
WORD	c;
{
	switch ((c)) 
	{
	case	0x0027	: /* ' */
	case	' '	:
	case	'@'	:
	case	'\t'	:
	case	'\r'	:
	case	'\n'	:
	case	0x000C	:	return(VRAI);
	default		:	return(FAUX);
	}
}

/*	--------------	*/
/*	is_punctuation	*/
/*	--------------	*/
WORD	is_punctuation( c )
WORD	c;
{
	switch ((c)) 
	{
	case 	0x0027	:

		if ( ApostrophComment )
			return( FAUX );
		else	return( c );

	case	'-'	:
#ifdef	_CBPARSER_C
		if ( CobolSyntax )
			return( FAUX );
#endif
	case	',' 	:
	case	':'	:
	case	'.'	:
	case	';'	:
	case	'!'	:
	case	'?'	:
	case	'('	:
	case	')'	:
	case	'='	:
	case	'<'	:
	case	'>'	:
	case	'+'	:
	case	'/'	:

	case	'{'	:
	case	'}'	:

	case	'['	:
	case	']'	:
	case	'\\'	:
	case	'~'	:

	/* These three have been added  */
	/* as punctuation 		*/
	case	'$'	:
	case	'#'	:
	case	'%'	:
	case	'*'	:	return(c);
	default		:	return(FAUX);
	}
}

/*	-------------	*/
/*	new_input_line	*/
/*	-------------	*/
WORD	new_input_line()
{
	BPTR	lptr;
	if ((lptr = get_input_line()) != (BPTR) 0) 
	{
		LineBuffer = lptr;
		return( VRAI );
	}
	else	return(FAUX);
}

/*	-----------------------------	*/
/*	is_punctuation_or_white_space	*/
/*	-----------------------------	*/
WORD	is_punctuation_or_white_space( c )
WORD	c;
{
	if (( is_white_space( c ) )
	||  ( is_punctuation( c ) ))
		return( c );
	else	return( FAUX );
}

/*	-------------	*/
/*	block_comment	*/
/*	-------------	*/
WORD	block_comment()
{
	do	
	{
		while ( *LineBuffer ) 
		{
			switch ( *(LineBuffer++) ) 
			{
			case	'}' : 
				return(1);
			case	'{' : 
				if (!(block_comment()))
					return(0);
			}
		}
	}
	while ( new_input_line() );
	return(0);
}

/*	----------------	*/
/*	auto_line_loader	*/
/*	----------------	*/
WORD	auto_line_loader()
{
	if (!( OtrOption.AutoGetLine ))
		return( 0 );
	else	return( new_input_line() );
}

/*	------------------	*/
/*	remove_white_space	*/
/*	------------------	*/
WORD	remove_white_space()
{
	if (!( LineBuffer )) { return(0); }
	do	
	{
		while ( *LineBuffer ) 
		{
			switch ((*LineBuffer)) 
			{
			case	0x0027	:
#ifdef	_CBPARSER_C
				if (!( CobolSyntax )) 
				{
#endif
					if (( ApostrophComment )
					&&  ( new_input_line() ))
						continue;
#ifdef	_CBPARSER_C
				}
				else	
				{
					if (is_white_space( *LineBuffer )) 
					{
						LineBuffer++;
						continue;
					}
					else	return(1);
				}
#endif
				if ( ApostrophComment )
					return(0);
				else	return(1);
	
			case	0x001A	:
			case	0	:
				if (!( recover_input_context() ))
					return( 0 );
				else	continue;

			case	'{'	:	
				if (!( OtrOption.BlockComment )) 
					return(1);
				else	
				{
					LineBuffer++;
					if (!( block_comment() ))
						return(0);
					else	continue;
				}

			case	';'	:	
				if ( SemiColonComment )
					return(generate_comment(1));
				else	return(1);

			case	':'	:
				if ( *(LineBuffer+1) == ':' )
					return( 0 );

			default		: 
				if (is_white_space( *LineBuffer )) 
				{
					LineBuffer++;
					continue;
				}
				else	return(1);
			}
		}
	}
	while ( auto_line_loader() );

	return( 0 );
}

/*	------------------	*/
/*	verify_end_of_line	*/
/*	------------------	*/
WORD	verify_end_of_line()
{
	if ( remove_white_space() )
		return( syntax_error( 599 ) );
	else	return( 0 );
}

/*	-----------	*/
/*	ll_get_byte	*/
/*	-----------	*/
WORD	ll_get_byte()
{
	while (1) 
	{
		if (( LineBuffer != (BPTR) 0)
		&&  ( *LineBuffer ))
			return( *(LineBuffer++) );
		else	return( 0 );
	}
}

/*	--------	*/
/*	get_byte	*/
/*	--------	*/
WORD	get_byte()
{
	WORD	c;
	if (((c = ll_get_byte()) != 0)
	&&  ( OtrOption.SourceTrace & 1 )) 
	{
		if ( c != 0x001A )
			sysprintf("%c",c);
		else	sysprintf("[EOF]\n");
	}
	return(c);
}

/*	--------------	*/
/*	uppercase_byte	*/
/*	--------------	*/
WORD	uppercase_byte()
{
	WORD	c;
	if (((c = get_byte()) != 0)
	&&  (c >= 'a') 
	&&  (c <= 'z'))
		return(( c - 'a') + 'A');
	else	return( c );
}

/*	----------	*/
/*	unget_byte	*/
/*	----------	*/
VOID	unget_byte()
{
	LineBuffer--;
	return;
}

/*	--------	*/
/*	is_comma	*/
/*	--------	*/
WORD	is_comma()
{
	if ( remove_white_space() ) {
		if (get_byte() == ',')
			return(VRAI);
		else	unget_byte();
		}
	return(FAUX);
}

/*	---------	*/
/*	 is_hash	*/
/*	---------	*/
WORD	is_hash()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '#')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	----------	*/
/*	is_exclaim	*/
/*	----------	*/
WORD	is_exclaim()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '!')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	---------	*/
/*	is_equals	*/
/*	---------	*/
WORD	is_equals()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '=')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	----------	*/
/*	is_greater	*/
/*	----------	*/
WORD	is_greater()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '>')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	---------	*/
/*	 is_less 	*/
/*	---------	*/
WORD	is_less()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '<')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	---------	*/
/*	is_divide	*/
/*	---------	*/
WORD is_divide()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '/')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	--------	*/
/*	is_minus	*/
/*	--------	*/
WORD is_minus()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '-')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	---------	*/
/*	is_period	*/
/*	---------	*/
WORD	is_period()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '.')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	---------	*/
/*	 is_star 	*/
/*	---------	*/
WORD	is_star()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '*')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	-------------	*/
/*	is_left_brace	*/
/*	-------------	*/
WORD	is_left_brace()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '(')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	-------------	*/
/*	is_open_block	*/
/*	-------------	*/
WORD	is_open_block()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '{')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	--------------	*/
/*	is_close_block	*/
/*	--------------	*/
WORD	is_close_block()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '}')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	-----------------	*/
/*	 is_open_bracket	*/
/*	-----------------	*/
WORD	is_open_bracket()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '[')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	----------------	*/
/*	is_close_bracket	*/
/*	----------------	*/
WORD	is_close_bracket()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == ']')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	------------------------------------------------------------	*/
/*	N E X T _ I S _ L E F T _ B R A C E
/*	------------------------------------------------------------	*/
/*	Called during translation of method signatures in TRMETHOD.C	*/
/*	to detect the presence of formal parameters for the method.	*/
/*	This requires that the next character after the colon be	*/
/*	an opening left brace.						*/
/*	------------------------------------------------------------	*/

WORD	next_is_left_brace()
{
	if (( LineBuffer != (BPTR) 0)
	&&  ( *LineBuffer == '(' ))
		return( VRAI );
	else	return( FAUX );
}

/*	--------------	*/
/*	is_right_brace	*/
/*	--------------	*/
WORD	is_right_brace()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == ')')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	--------	*/
/*	is_dieze	*/
/*	--------	*/
WORD	is_dieze()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '#')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	---------	*/
/*	is_dollar	*/
/*	---------	*/
WORD	is_dollar()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '$')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	----------	*/
/*	is_percent	*/
/*	----------	*/
WORD	is_percent()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '%')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	--------	*/
/*	is_quote	*/
/*	--------	*/
WORD	is_quote()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '"')
			return(VRAI);
		else	unget_byte();
#ifdef	_CBPARSER_C
		if ( CobolSyntax ) 
		{
			if ( get_byte() == 0x0027 )
				return( VRAI );
			else	unget_byte();
		}
#endif
	}
	return(FAUX);
}

#include "trdate.c"

/*	-----------------	*/
/*	 dieze_constants	*/
/*	-----------------	*/
WORD	dieze_constants()
{
	BPTR	source_file_name();
	WORD	source_file_line();

	if ( is_mnemonic("FILE") ) 
	{
		sprintf(TokenBuffer,"%c%s%c",0x0022,source_file_name(),0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else if ( is_mnemonic("LINE") ) 
	{
		sprintf(TokenBuffer,"%c%u%c",0x0022,source_file_line(),0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else if ( is_mnemonic("DATE") ) 
	{
		return( directive_date() );
	}
	else if ( is_mnemonic("TIME") ) 
	{
		return( directive_time() );
	}
	else if ( is_mnemonic("TRUE") ) 
	{
		strcpy(TokenBuffer,"1");
		return(strlen(TokenBuffer));
	}
	else if ( is_mnemonic("FALSE") ) 
	{
		strcpy(TokenBuffer,"0");
		return(strlen(TokenBuffer));
	}
	else if ( is_mnemonic("WORDSIZE") ) 
	{
		sprintf(TokenBuffer,"%llu",OtrOption.WordSize);
		return(strlen(TokenBuffer));
	}
	else if ( is_mnemonic("PTRSIZE") ) 
	{
		sprintf(TokenBuffer,"%llu",OtrOption.PointerSize);
		return(strlen(TokenBuffer));
	}
	else if ( is_mnemonic("TYPE") ) 
	{
		if (!( context_is_module ))
			sprintf(TokenBuffer,"%c%s%c",0x0022,"PROGRAM",0x0022);
		else	sprintf(TokenBuffer,"%c%s%c",0x0022,"MODULE",0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else if ( is_mnemonic("NAME") ) 
	{
		sprintf(TokenBuffer,"%c%s%c",0x0022,Context->identity,0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else if ( is_mnemonic("SEGM") ) 
	{
		if (!( Context->CurrentSegment ))
			sprintf(TokenBuffer,"%c %c",0x0022,0x0022);
		else if (!( Context->CurrentSegment->name ))
			sprintf(TokenBuffer,"%c %c",0x0022,0x0022);
		else sprintf(TokenBuffer,"%c%s%c",0x0022,Context->CurrentSegment->name,0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else if ( is_mnemonic("PROC") ) {
		if (!( Context->PRC ))
			sprintf(TokenBuffer,"%c %c",0x0022,0x0022);
		else if (!( Context->PRC->name ))
			sprintf(TokenBuffer,"%c %c",0x0022,0x0022);
		else sprintf(TokenBuffer,"%c%s%c",0x0022,Context->PRC->name,0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else	
	{
		unget_byte();
		return(0);
	}
}

/*	-------------------------	*/
/*	 collect_string_litteral	*/
/*	-------------------------	*/
WORD	collect_string_litteral()
{
	WORD	i=0;
	WORD	c=0;

	if ( is_quote() ) 
	{
		TokenBuffer[0] = '"';

		while ((c = *(LineBuffer++)) != 0) 
		{
			switch ( c ) 
			{
			case	'\n' :
			case	'\r' :
				return( 0 );

			case	'"' :
				if ( *LineBuffer != '"' ) 
				{
					if (( i > 255 )
					||  ( i == 0  ))
						return( 0 );
					else	
					{
						TokenBuffer[1+(i++)] = '"';
						TokenBuffer[1+i] = 0;
						return((i+2));
					}
				}
				else if ( i >= 255 )
					return( 0 );
				else	
				{
					if ( OtrOption.KeepQuote )
						TokenBuffer[1+(i++)] = c;
					TokenBuffer[1+(i++)] = *(LineBuffer++);
					continue;
				}

			case    '&' :
				if ( *LineBuffer == '&' ) 
				{
					LineBuffer++;
					if ( *LineBuffer == '&' ) 
					{
						if ( OtrOption.KeepQuote )
							TokenBuffer[1+(i++)] = c;
						c = *(LineBuffer++);
					}
					else	
					{
						if ( OtrOption.KeepQuote ) 
						{
							TokenBuffer[1+(i++)] = c;
							continue;
						}
						else if (( *LineBuffer >= '0' ) && ( *LineBuffer <= '9' ))
							c = ((*(LineBuffer++) - '0') * 100);
						else	return( 0 );

						if (( *LineBuffer >= '0' ) && ( *LineBuffer <= '9' ))
							c += ((*(LineBuffer++) - '0') * 10);
						else	return( 0 );

						if (( *LineBuffer >= '0' ) && ( *LineBuffer <= '9' ))
							c += (*(LineBuffer++) - '0');
						else	return( 0 );

						if (( c > 0x00FF )
						||  ( c ==     0 ))
							return( 0 ); 
					}
				}

			default	     :
				if ( i > 255 )
					return( 0 );
				else	
				{
					TokenBuffer[1+(i++)] = (BYTE) c;
					continue;
				}
			}
		}		
	}
	return( 0 );
}

/*	--------	*/
/*	is_colon	*/
/*	--------	*/
WORD	is_colon()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == ':') 
		{
			if ( get_byte() != ':' ) 
			{
				unget_byte();
				return(VRAI);
			}
			unget_byte();
		}
		unget_byte();
	}
	return(FAUX);
}

/*	-------------	*/
/*	is_semi_colon	*/
/*	-------------	*/
WORD	is_semi_colon()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == ';')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	------------	*/
/*	is_ampersand	*/
/*	------------	*/
WORD	is_ampersand()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '&')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	---------	*/
/*	 is_plus 	*/
/*	---------	*/
WORD	is_plus()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '+')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	-----------	*/
/*	is_question	*/
/*	-----------	*/
WORD	is_question()
{
	if ( remove_white_space() ) 
	{
		if (get_byte() == '?')
			return(VRAI);
		else	unget_byte();
	}
	return(FAUX);
}

/*	----------	*/
/*	is_newline	*/
/*	----------	*/
WORD	is_newline()
{
	WORD	c;

	while (1) 
	{
		if ((c = get_byte()) == 0)
			return( MOINS_UN );
		else if (c == 0x001A)
			pop_source_context(1);
		else if ( is_white_space(c) )
			continue;
		else	break;
	}
	if ( c == ':' ) 
	{
		if ((c = get_byte()) == ':') 
			return( VRAI );
		unget_byte();
	}
	else if ( c == ';' ) 
	{
		if ( SemiColonComment ) 
		{
			generate_comment(0);
			return( MOINS_UN );
		}
	}
	unget_byte();
	return(FAUX);
}

/*	-----------	*/
/*	not_newline	*/
/*	-----------	*/
WORD	not_newline()
{
	if ( is_newline() )
		return( FAUX );
	else	return( VRAI );
}

/*	------------	*/
/*	soft_newline	*/
/*	------------	*/
WORD	soft_newline()
{
	if ( is_newline() != MOINS_UN ) 
	{
		if (!( OtrOption.Optimise & _OPTIMISE_NEWLINE ))
			signal_new_line( VRAI );
		return( remove_white_space() );
	}
	else	return( FAUX );
}

/*	-----------	*/
/*	is_operator	*/
/*	-----------	*/
WORD	is_operator()
{
	WORD	c;
	if ( remove_white_space() )
	{
		switch ((c = get_byte())) 
		{
		case ';' :
		case ':' :
		case ',' : 
		case ')' : unget_byte();
		case '%' :
		case '+' :
		case '\\':
		case '/' :
		case '*' :
		case '&' :
		case '|' :
		case '~' :
		case '^' : return( c );
		case '!' : 
			if (!( is_equals() ))
				return(c);
			else	
			{
				unget_byte();	/* = */
				unget_byte();	/* ! */
				return(FAUX);
			}				

		case '-' :
#ifdef	_CBPARSER_C
			if ( CobolSyntax ) 
			{
				unget_byte();
				break;
			}					
#endif
			return(c);

		default  : 
			unget_byte();
#ifdef	_CBPARSER_C
			if ( CobolSyntax )
				break;
#endif
			if ( is_mnemonic( "AND" ) )
				return( '&' );
			else if ( is_mnemonic( "OR" ) )
				return( '|' );
			else if ( is_mnemonic( "OX" ) )
				return( '^' );
		}
	}
	return(FAUX);
}

/*	---------------------	*/
/*	arithmetical_operator	*/
/*	---------------------	*/
WORD	arithmetical_operator()
{
	WORD	c;
	switch ((c = is_operator())) 
	{
	case ';' :
	case ':' :
	case ',' : 
	case ')' :
		c = 0;
	default	 :	
		return(c);
	}
}

/*	-------------	*/
/*	is_hexa_digit	*/
/*	-------------	*/
WORD	is_hexa_digit( c )
WORD	c;
{
	if (( c >= '0' )
	&&  ( c <= '9' ))
		return( VRAI);
	else if (( c >= 'a' )
	     &&  ( c <= 'f' ))
		return( VRAI);
	else if (( c >= 'A' )
	     &&  ( c <= 'F' ))
		return( VRAI);
	else	return( FAUX );
}

/*	----------------	*/
/*	is_decimal_digit	*/
/*	----------------	*/
WORD	is_decimal_digit( c )
WORD	c;
{
	if (( c >= '0' )
	&&  ( c <= '9' ))
		return( VRAI);
	else if ( c == '-' )
		return( VRAI );
	else	return( FAUX );
}

/*	--------------	*/
/*	not_hexa_digit	*/
/*	--------------	*/
WORD	not_hexa_digit( c )
WORD	c;
{
	if ( is_hexa_digit( c ))
		return( FAUX );
	else	return( VRAI );
}

/*	--------------------	*/
/*	token_is_not_numeric	*/
/*	--------------------	*/
WORD	token_is_not_numeric(n)
WORD	n;
{
	WORD	i;
	if (( TokenBuffer[0] == '-' )
	||  ( TokenBuffer[0] == '+' ))
		i = 1;
	else	i = 0;
	for ( ; i < n; i++ )
		if  (( TokenBuffer[i] < '0' )
		||  ( TokenBuffer[i] > '9'  ))
			return( VRAI );
#ifdef	_CBPARSER_C
	if (CobolSyntax)
		if (( *LineBuffer < '0' )
		||  ( *LineBuffer > '9' ))
			return( VRAI );
#endif
	return( FAUX );
}


/*	-------------------------	*/
/*	 l l _ g e t _ t o k e n 	*/
/*	-------------------------	*/
/*	fetch one token from line	*/
/*	-------------------------	*/

static	char * ForceTokenSize="\1ForceTokenSize";

WORD	ll_get_token()
{
	WORD	i=0;
	WORD	quote=0;
	WORD	c;

	if (remove_white_space()) 
	{
		TokenHash = 0;
		if ( DiezeConstants ) 
		{
			if ( is_dieze() )
				if ((i = dieze_constants()) != 0)
					return(i);
		}
		if ( is_quote() ) 
		{
			unget_byte();
			return( collect_string_litteral() );
		}
		while (i < _MAX_OTR_TOKEN) 
		{
			if (c = get_byte()) 
			{
				if (!(quote)) 
				{
					if (( c == '&' )
					&&  ( i != 0   )) 
					{
						unget_byte();
						break;
					}
					else if (is_punctuation_or_white_space(c)) 
					{
						if ( c == '-' ) 
						{
							if (( i != 0 )
							||  ( *LineBuffer < '0' )
							||  ( *LineBuffer > '9' )) 
							{
								unget_byte();
								break;
							}
						}
						else if ( c == '/' ) 
						{
							if (( i != 0 )
							||  ( not_hexa_digit( *LineBuffer ))) 
							{
								unget_byte();
								break;
							}
						}
						else if ( c == '.' ) 
						{
							if ( i != 0 ) 
							{
								if ( token_is_not_numeric(i) ) 
								{
									unget_byte();
									break;
								}
							}
							else if (( *LineBuffer < '0' )
							     ||  ( *LineBuffer > '9' )) 
							{
								unget_byte();
								break;
							}
							else	
							{
								TokenBuffer[i++] = '0';
								TokenHash += '0';
							}
						}
						else	
						{
							unget_byte();
							break;
						}
					}

					if ( c == '"' ) 
					{
						if ( i != 0 ) 
						{
							unget_byte();
							break;
						}
					}
					/* ----------------------------- */
					/* Convert token to upper case ? */
					/* ----------------------------- */
					if (( OtrOption.UpperCase )
					&&  (c >= 'a') 
					&&  (c <= 'z'))
						c -= ('a' - 'A');
					if ((TokenBuffer[i++] = c) == '"' )
						quote = 1;
					TokenHash += c;
				}
				else 	
				{
					TokenHash += c;
					if ((TokenBuffer[i++] = c) == '"') 
					{
						quote = 0;
						break;
					}
				}
			}
			else if ( quote ) 
			{
				(void) syntax_error(3733);
				return( 0 );
			}
			else	break;
		}
	}
	/* ----------------------------- */
	/* check for token size clipping */
	/* ----------------------------- */
	if ( *ForceTokenSize ) 
	{
		/* --------------------------------------------- */
		/* check if token exceeds maxiumum declared size */
		/* --------------------------------------------- */
		if ( i > OtrOption.TokenSize ) 
		{
			/* --------------------------------------- */
			/* do not clip massive bcd constant tokens */
			/* --------------------------------------- */
			if (( TokenBuffer[0] != '-' )
			/* ------------------------------- */
			/* nor massive hex constant tokens */
			/* ------------------------------- */
			&&  ( TokenBuffer[0] != '/' ))
				/* -------------------------- */
				/* do not clip numeric values */
				/* -------------------------- */
				if (( TokenBuffer[0] < '0' ) ||  ( TokenBuffer[0] > '9' ))
					i = OtrOption.TokenSize;
		}
	}

	/* --------------------------------- */
	/* terminate the token string buffer */
	/* --------------------------------- */
	TokenBuffer[i] = 0;
	return(i);
}

/*	-------------------	*/
/*	get_uppercase_token	*/
/*	-------------------	*/
WORD	get_uppercase_token()
{
	WORD	holder;
	WORD	l;
	holder    =  OtrOption.UpperCase;
	OtrOption.UpperCase = VRAI;
	l = ll_get_token();
	OtrOption.UpperCase = holder;
	return(l);
}

/*	------------	*/
/*	expand_token	*/
/*	------------	*/
WORD	expand_token()
{
	WORD	c;
	if ((TokenBuffer[0] == '"')
	||  ((c = is_numeric_token( TokenBuffer )) != 0))
		return( FAUX );
	if (( expand_parameter() )
	||  ( expand_member()    ))
		return( VRAI );
	else	return( FAUX );
}

/*	-------------	*/
/*	expand_macros	*/
/*	-------------	*/
WORD	expand_macros()
{
	WORD	c;
	if ((TokenBuffer[0] == '"')
	||  ((c = is_numeric_token( TokenBuffer )) != 0))
		return( FAUX );
	if (( expand_parameter() )
	||  ( expand_macro()     ))
		return( VRAI );
	else	return( expand_this() );
}

/*	---------	*/
/*	get_token	*/
/*	---------	*/
WORD	get_token()
{
	WORD	l;

	while (((l = ll_get_token())) && (expand_macros()));

	if (( l == 2 ) && ( TokenBuffer[1] == '0' )) 
	{
		if (((TokenBuffer[0] >= 'A' ) &&  (TokenBuffer[0] <= 'Z' ))
		||  ((TokenBuffer[0] >= 'a' ) &&  (TokenBuffer[0] <= 'z' ))) 
		{
			TokenBuffer[1] = 0;
			l = 1;
		}
	}

	reset_symbol_module();

	return( l );
}

/*	--------------	*/
/*	evaluate_token	*/
/*	--------------	*/
WORD	evaluate_token()
{
	WORD	l;
	
	while (((l = get_token())) && (expand_token()));

	return( l );
}
		
/*	------------	*/
/*	get_filename	*/
/*	------------	*/
WORD	get_filename()
{
	WORD	i=0;
	WORD	c;
	WORD	quote=FAUX;
	if ( remove_white_space() ) 
	{
		TokenHash = 0;
		while (1) 
		{
			if (is_white_space((c = get_byte())))
				break;
#ifdef	_CBPARSER_C
			if ( CobolSyntax )
				if ((!(quote)) && ( c == '.' ))
					break;
#endif
			TokenBuffer[i++] = c;
			TokenHash += c;
#ifdef	_CBPARSER_C
			if ( CobolSyntax ) 
			{
				if ( quote == c )
					break;
				if ( c == '"' )
					quote = c;
				else if ( c == 0x0027 )
					quote = c;
			}
#endif
		}
	}
	TokenBuffer[i] = 0;
	slash_conversion( TokenBuffer );
	return( i );
}

/*	--------------	*/
/*	is_hexadecimal	*/
/*	--------------	*/
WORD	is_hexadecimal()
{
	WORD	c;

	c = get_byte();

	if ((c >= '0') && (c <= '9'))
		return((c - '0'));
	else if ((c >= 'A') && (c <= 'F'))
		return(((c - 'A')+10));
	else if ((c >= 'a') && (c <= 'f'))
		return(((c - 'a')+10));
	else	
	{
		unget_byte();
		return( MOINS_UN );
	}
}

/*	----------	*/
/*	is_decimal	*/
/*	----------	*/
WORD	is_decimal()
{
	WORD	c;
	c = get_byte();

	if ((c >= '0') && (c <= '9'))
		return((c - '0'));
	else	
	{
		unget_byte();
		return( MOINS_UN );
	}
}

/*	----------	*/
/*	is_numeric	*/
/*	----------	*/
WORD	is_numeric()
{
	WORD	c;
	if ( remove_white_space() ) 
	{
		c = get_byte();
		unget_byte();
		if (((c >= '0') && (c <= '9')) 
		||  ( c == '/' )
		||  ( c == '-' ))
			return(c);
	}
	return(0);
}

/*	-----------------	*/
/*	 is_string_token	*/
/*	-----------------	*/
WORD	is_string_token( token )
BPTR	token;
{
	WORD	c;
	trace("is_string_token("); trace( token ); trace(")\n");
	if ((c = *token) == '"' )
		return( c );
	else	return( 0 );
}

/*	----------------	*/
/*	is_numeric_token	*/
/*	----------------	*/
WORD	is_numeric_token( token )
BPTR	token;
{
	WORD	c;
	if (( c = *token) != 0) 
	{
		if (((c >= '0') && (c <= '9')) 
		||  ( c == '/' )
		||  ( c == '-' ))
			return(c);
	}
	return(0);
}

/*	-------------------	*/
/*	collect_hexadecimal	*/
/*	-------------------	*/
WORD	collect_hexadecimal()
{
	WORD	result=0;
	WORD	c;
	while ((c = is_hexadecimal()) != MOINS_UN)
		result = ((result << 4) | c);
	return( result );
}

/*	-----------------	*/
/*	 collect_decimal	*/
/*	-----------------	*/
WORD	collect_decimal()
{
	WORD	result=0;
	WORD	c;
	WORD	sign;

	if ( is_minus() )
		sign = 1;
	else	sign = 0;

	while ((c = is_decimal()) != MOINS_UN)
		result = ((result * 10) + c);

	if ( sign )
		return( -result );
	else	return( result  );
}

/*	-----------------	*/
/*	 collect_integer	*/
/*	-----------------	*/
WORD	collect_integer()
{
	if (remove_white_space()) 
	{
		if ( is_divide() )
			return( collect_hexadecimal() );
		else	return( collect_decimal() );
	}
	else	return( syntax_error(30) );
}

/*	-----------------	*/
/*	convert_hex_token	*/
/*	-----------------	*/
WORD	convert_hex_token( token )
BPTR	token;
{
	WORD	r=0;
	WORD	i=1;
	WORD	c;
	trace("convert_hex()\n");
	while ((c = *(token + i)) ) 
	{
		if ( is_decimal_digit( c ) )
			r = ((r << 4) | (c - '0'));
		else if (( c >= 'a' )
		     &&  ( c <= 'f' ))
			r = ((r << 4) | ((c - 'a') + 10));
		else if (( c >= 'A' )
		     &&  ( c <= 'F' ))
			r = ((r << 4) | ((c - 'A') + 10));
		else	break;
		i++;
	}
	return( r );
}

/*	-----------------	*/
/*	convert_int_token	*/
/*	-----------------	*/
WORD	convert_int_token(token)
BPTR	token;
{
#if otr32 || otr64
	unsigned 	long l=0L;
#endif
	WORD	r=0;
	WORD	i=0;
	WORD	c;
	WORD	s=0;
	WORD	ws=sizeof(WORD);
	if ( token == (BPTR) 0 )
		return( internal_error(777) );

	trace("convert_int()\n");

	if ( *token == '-' ) 
	{
		s = 1;
		token++;
	}
		
	while ((c = *(token++)) != 0) 
	{
#if otr32 || otr64
	// TODO
		l = ((l * 10) + (c - '0'));
		r = l;
#else	
		r = ((r * 10) + (c - '0'));
#endif
	}
#ifdef	CHECKERROR778
#if otr32 || otr64
	// TODO
	if ( l & 0xFFFF0000 )
		return( internal_error(778) );
	else	r = l;
#endif
#endif
	return(( s != 0 ? -r : r));
}

/*	---------------------	*/
/*	convert_numeric_token	*/
/*	---------------------	*/
WORD	convert_numeric_token( token )
BPTR	token;
{
	WORD	ws=sizeof(WORD);
	trace("convert_num()\n");
	if ( *token == '/' )
		ws = convert_hex_token( token );
	else	ws = convert_int_token( token );
	return( ws );
}

/*	---------------------	*/
/*	convert_integer_token	*/
/*	---------------------	*/
WORD	convert_integer_token( token )
BPTR	token;
{
	if ( *token == '/' )
		return( convert_hex_token( token ) );
	else if ( is_decimal_digit( *token ) )
		return( convert_int_token( token ) );
	else	return( resolve_symbolic_integer( token ) );
}

/*	------------	*/
/*	integer_term	*/
/*	------------	*/
WORD	integer_term()
{
	WORD	r;
	trace("integer_term()\n");
	if ( is_left_brace() ) 
	{
		r = integer_expression();
		if (!( is_right_brace() ))
			(void) unmatched_braces();
		return( r );
	}
	else if ( evaluate_token() )
		return( convert_integer_token(TokenBuffer) );
	else	return(0);
}

#if	otr32 || otr64
/*	----------------	*/
/*	integer_overflow	*/
/*	----------------	*/
WORD	integer_overflow( op, l , r )
WORD	op;
WORD	l;
WORD	r;
{
	unsigned 	long result=0L;
	switch ( op ) 
	{
	case '+' : result = (l + r); break;
	case '*' : result = (l * r); break;
	default	 : return(0);
	}
	// TODO
	if ( result & 0xFFFF0000 )
		return( 1 );
	else	return( 0 );
}
#endif

/*	----------------	*/
/*	evaluate_integer	*/
/*	----------------	*/
WORD	evaluate_integer( op, l, r )
WORD	op;
WORD	l;
WORD	r;
{
#if	otr32 || otr64
	// TODO
	unsigned 	long result=0L;
#else
	WORD		result=0;
#endif	
	trace("evaluate_integer()\n");
	switch ( op ) 
	{
	case '-' : return((l - r));
	case '~' : return((r - l));
#if	otr32 || otr64
	// TODO
	case '+' : result = (l + r); break;
	case '*' : result = (l * r); break;
#else
	case '+' : return((l+r)); break;
	case '*' : return((l*r)); break;
#endif
	case '/' : return((l / r));
	case '\\': return((r / l));
	case '%' : return((l % r));
	case '&' : return((l & r));
	case '|' : return((l | r));
	case '^' : return((l ^ r));
	default	 : return( internal_error(778) );
	}
#if	otr32 || otr64
	// TODO
	if ( result & 0xFFFF0000 )
		return( internal_error(778) );
	return((result & 0x0000FFFF));
#endif
}

/*	------------------	*/
/*	integer_expression	*/
/*	------------------	*/
WORD	integer_expression()
{
	WORD	l=0;
	WORD	r=0;
	WORD	operation;
	trace("integer_expression()\n");
	l = integer_term();
	while ( 1 ) 
	{
		switch ((operation = is_operator())) 
		{
		case    ':' :
		case    ',' :
		case	')' :
		case	0   :
			return( l );
		}
		r = integer_term();
		l = evaluate_integer( operation, l, r );
	}
	return( l );
}

/*	--------	*/
/*	strindex	*/
/*	--------	*/
WORD	strindex( token, c )
BPTR	token;
WORD	c;
{
	WORD	result=0;
	while	( *token ) 
	{
		if ( *(token++) == c )
			return( result );
		else	result++;
	}
	return( MOINS_UN );
}

/*	----------	*/
/*	test_digit	*/
/*	----------	*/
WORD	test_digit( t, c )
WORD	t;
WORD	c;
{
	if ( t < c )
		return( VRAI );
	else if ( t > c )
		return( FAUX );
	else	return( MOINS_UN );
}

/*	----------	*/
/*	is_integer	*/
/*	----------	*/
WORD	is_integer( token )
BPTR	token;
{
	WORD	l;
	BPTR	iptr;
	if ( strindex( token , '.' ) != MOINS_UN )
		return( FAUX );
	else if ((l = strlen( token )) < 5 )
		return( VRAI );
	
	if ( *token == '-' ) 
	{
		token++; l--;
	}
	while ( *token == '0' ) 
	{
		token++; l--;
	}
#if	otr32 || otr64
	// TODO
	if ( l < 10 )
		return( VRAI );
	else if ( l > 10 )
		return( FAUX );
	else 	
	{
		/* for chantal : 23/3/2006 : ijm */
		if ( convert_int_token( token ) & 0x80000000 )
			return(FAUX);
		iptr = (BPTR) "4294967295";
		while (( *iptr ) && ( *token ))
			if ((l = test_digit( *(token++), *(iptr++) )) != MOINS_UN)
				return( l );
		return( FAUX );
	}
#else
	if ( l < 5 )
		return( VRAI );
	else if ( l > 5 )
		return( FAUX );
	else 	
	{
		/* for chantal : 23/3/2006 : ijm */
		if ( *token < '3' )
			return( VRAI );
		if ( *token > '3' )
			return( FAUX );
		
		if ( *(token+1) < '2' )
			return( VRAI );
		if ( *(token+1) > '2' )
			return( FAUX );
		
		if ( *(token+2) < '7' )
			return( VRAI );
		if ( *(token+2) > '7' )
			return( FAUX );
			
		if ( *(token+3) < '6' )
			return( VRAI );
		if ( *(token+3) > '6' )
			return( FAUX );
			
		if ( *(token+4) < '7' )
			return( VRAI );
		if ( *(token+4) > '7' )
			return( FAUX );
		if ( convert_int_token( token ) & 0x8000 )
			return(FAUX);
			
		return( VRAI );
	}
#endif
}

/*	---------	*/
/*	get_label	*/
/*	---------	*/
WORD	get_label()
{
	WORD	hs=OtrOption.TokenSize;
	WORD	result;
	OtrOption.TokenSize = OtrOption.LabelSize;
	result = get_token();
	if ( is_dollar() )
		sprintf(&TokenBuffer[result],"%u",current_invocation_counter());
	OtrOption.TokenSize = hs;
	return( result );
}

/*	------------	*/
/*	detect_label	*/
/*	------------	*/
WORD	detect_label( status )
WORD	status;
{
	if (( status )
	&&  ( is_active_region() )
	&&  (LabelStatus)
	&&  ( is_ampersand() )) 
	{
		unget_byte();
		if (!( get_label() ))
			return( syntax_error(31) );
		else if ( add_explicite_label( TokenBuffer ) ) 
		{
			if ((status = remove_white_space()) != 0)
				return( status );
			else if ( *LineBuffer != ':' )
				return(status );
			else if ( *(LineBuffer + 1) != ':' )
				return( status );
			else	
			{
				/* -------------------------- */
				/* remove rediculous new line */
				/* -------------------------- */
				get_byte(); get_byte();
				return( detect_label(1) );
			}
		}
		else	return( syntax_error(31) );
	}
	return( status );
}

/*	-----------	*/
/*	is_mnemonic	*/
/*	-----------	*/
WORD	is_mnemonic( mptr )
BPTR	mptr;
{
	WORD	l;
	WORD	i;
	WORD	c;

	if (!( remove_white_space() ))
		return(0);

	l = strlen(mptr);
	for ( i = 0; i < l; i++ ) 
	{
		c = get_byte();
		if ((c >= 'a') && (c <= 'z'))
			c -= ('a' - 'A');
		if ( c != *(mptr + i) )
			break;
	}
	if ( i == l ) 
	{
		if ( is_punctuation_or_white_space(get_byte()) ) 
		{
			unget_byte();			
			return( VRAI );
		}
	}
	while (1) 
	{
		unget_byte();
		if ( i )
			i--;
		else	break;
	}
	return( FAUX );
}

/*	----------	*/
/*	get_format	*/
/*	----------	*/
WORD	get_format()
{
	WORD	i=0;
	WORD	quote=0;
	WORD	c;
	WORD	braces=0;

	if ( remove_white_space() ) 
	{
		while (1) 
		{
			switch ((c = get_byte())) 
			{
			case '\t':
			case ' ' :
				if ( quote )
					break;
			case '\r':
				continue; 
			case '"' :
				if ( quote )
					quote = 0;
				else	quote = 1;
				break;
			case '(' :
				if (!(quote))
					braces++;
				break;
			case ')' :
				if ( quote )
					break;
				else if ( braces ) 
				{
					braces--;
					break;
					}
				else	unget_byte();
			case 0	 :
			case '\n':
				if (( braces ) || ( quote ))
					return( syntax_error(32) );
				TokenBuffer[i] = 0;
				return(i);
			}
			TokenBuffer[i++] = c;
		}
	}
	return(0);
}

/*	------------------	*/
/*	detect_bal_comment	*/
/*	------------------	*/
WORD	detect_bal_comment()
{
	switch( *LineBuffer ) 
	{
	case '/' : /* Display Message 	*/
		if (!(BalComment))
			return(1);
		else if (BalComment == 2) 
		{
			if (*(LineBuffer+1) != '/' )
				return(1);
			else	return( generate_comment(1));
		}

		if (( OtrOption.Verbose  )
		&&  (!( OtrOption.Verbose & 32  )))
			sysprintf("%s",LineBuffer);
		return(generate_comment(1));

	case ';' : /* Standard Comment 	*/
		if (!( SemiColonComment ))
			break;
	case '*' : /* Star Comment 	*/
		if (!(StarComment))
			break;
	case '>' : /* Printer On   	*/
	case '<' : /* Printer Off  	*/
	case '.' : /* Who knows what 	*/
		if (!(BalComment))
			return(1);
		else 	return(generate_comment(1));
	}
	return( 1 );
}

/*	-----------------	*/
/*	 is_star_comment	*/
/*	-----------------	*/
WORD	is_star_comment()
{	
	return( StarComment );
}

/*	------------------	*/
/*	parser_line_buffer	*/
/*	------------------	*/
BPTR	parser_line_buffer()
{
	return( LineBuffer );
}

/*	----------------------	*/
/*	set_parser_line_buffer	*/
/*	----------------------	*/
VOID	set_parser_line_buffer(lptr)
BPTR	lptr;
{
	LineBuffer = lptr;
	trace("set_parser_line_buffer()\n");
	return;
}

/*	----------------------	*/
/*	initialise_line_parser	*/
/*	----------------------	*/
WORD	initialise_line_parser( buffer )
BPTR	buffer;
{
	WORD	status;
	Context->IsExport=0;
	if ( buffer != (BPTR) 0) 
	{
		LineBuffer = buffer;
		LinePointer = buffer;
		if ((status = is_method_definition()) != 0)
			return( status );
		else if (( is_newline() != MOINS_UN )
		     &&  ((status = detect_bal_comment()) != 0)) 
		{
			return(detect_label(status));
		}
		else	return( 0 );
	}
	else	return(0);
}

/*	--------------------------	*/
/*	inhibit_semi_colon_comment	*/
/*	--------------------------	*/
WORD	inhibit_semi_colon_comment()
{
	WORD	current=SemiColonComment;
	SemiColonComment = 0;
	return(current);
}

/*	--------------------	*/
/*	restore_label_status	*/
/*	--------------------	*/
VOID	restore_label_status()
{
	LabelStatus = 1;
	return;
}

/*	--------------------	*/
/*	inhibit_label_status	*/
/*	--------------------	*/
VOID	inhibit_label_status()
{
	LabelStatus = 0;
	return;
}

/*	-----------------------	*/
/*	inhibit_dieze_constants	*/
/*	-----------------------	*/
VOID	inhibit_dieze_constants()
{
	DiezeConstants=0;
	return;
}

/*	-----------------------	*/
/*	restore_dieze_constants	*/
/*	-----------------------	*/
VOID	restore_dieze_constants()
{
	DiezeConstants=1;
	return;
}

/*	--------------------------	*/
/*	restore_semi_colon_comment	*/
/*	--------------------------	*/
WORD	restore_semi_colon_comment( state )
WORD	state;
{
	WORD	current=SemiColonComment;
	SemiColonComment = state;
	return(current);
}

/*	--------------------------	*/
/*	inhibit_apostrophe_comment	*/
/*	--------------------------	*/
WORD	inhibit_apostrophe_comment()
{
	WORD	current=ApostrophComment;
	ApostrophComment = 0;
	return(current);
}

/*	--------------------	*/
/*	inhibit_bal_comments	*/
/*	--------------------	*/
WORD	inhibit_bal_comments()
{
	WORD	current=BalComment;
	BalComment = 0;
	return(current);
}

/*	-------------------	*/
/*	double_bal_comments	*/
/*	-------------------	*/
WORD	double_bal_comments()
{
	WORD	current=BalComment;
	BalComment = 2;
	return(current);
}

/*	---------------------	*/
/*	inhibit_star_comments	*/
/*	---------------------	*/
WORD	inhibit_star_comments()
{
	WORD	current=StarComment;
	StarComment = 0;
	return(current);
}

/*	--------------------	*/
/*	restore_bal_comments	*/
/*	--------------------	*/
WORD	restore_bal_comments( state )
WORD	state;
{
	WORD	current=BalComment;
	BalComment = state;
	return(current);
}

/*	---------------------	*/
/*	restore_star_comments	*/
/*	---------------------	*/
WORD	restore_star_comments( state )
WORD	state;
{
	WORD	current=StarComment;
	StarComment = state;
	return(current);
}

/*	--------------------------	*/
/*	restore_apostrophe_comment	*/
/*	--------------------------	*/
WORD	restore_apostrophe_comment( state )
WORD	state;
{
	WORD	current=ApostrophComment;
	ApostrophComment = state;
	return(current);
}

/*	---------------------	*/
/*	terminate_line_parser	*/
/*	---------------------	*/
VOID	terminate_line_parser()
{
	if ( LineBuffer != (BPTR) 0 )
		while ( *LineBuffer )
			LineBuffer++;
	return;
}

/*	-----------------	*/
/*	trace_line_buffer	*/
/*	-----------------	*/
void	trace_line_buffer()
{
	trace("LineBuffer[ ");
	trace(LineBuffer);
	trace(" ]\n");
	return;
}

/*	-------------------	*/
/*	cancel_token_buffer	*/
/*	-------------------	*/
VOID	cancel_token_buffer()
{
	TokenBuffer[0] = 0;
	return;
}

	/* ----------- */
#endif 	/* _TRPARSER_C */
	/* ----------- */


