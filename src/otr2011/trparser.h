/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990,1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRPARSER.H				*/
/*		Version :	2.2a					*/
/*		Date	:	29/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRPARSER_H
#define	_TRPARSER_H

#define	_MAX_OTR_TOKEN 511

#ifdef	_TRPARSER_C

static	WORD		SemiColonComment=1;
static	WORD		ApostrophComment=1;
	BPTR		LinePointer;
	BPTR		LineBuffer;
	BYTE		TokenBuffer[_MAX_OTR_TOKEN+1];
	WORD		TokenHash=0;
#else

EXTERN	BPTR		LineBuffer;
EXTERN	BYTE		TokenBuffer[_MAX_OTR_TOKEN+1];
EXTERN	WORD		TokenHash;

#endif


#ifndef	UNIX
WORD	is_white_space( WORD );
WORD	is_punctuation( WORD );
WORD	new_input_line( VOID );
WORD	is_punctuation_or_white_space( WORD );
WORD	block_comment( VOID );
WORD	remove_white_space( VOID );
WORD	verify_end_of_line( VOID );
WORD	ll_get_byte( VOID );
WORD	get_byte( VOID );
WORD	uppercase_byte( VOID );
VOID	unget_byte( VOID );
WORD	is_comma( VOID );
WORD	is_hash( VOID );
WORD	is_equals( VOID );
WORD	is_greater( VOID );
WORD	is_less( VOID );
WORD	is_divide( VOID );
WORD	is_minus( VOID );
WORD	is_period( VOID );
WORD	is_star( VOID );
WORD	is_left_brace( VOID );
WORD	is_open_block( VOID );
WORD	is_close_block( VOID );
WORD	is_open_bracket( VOID );
WORD	is_close_bracket( VOID );
WORD	next_is_left_brace( VOID );
WORD	is_right_brace( VOID );
WORD	is_dieze( VOID );
WORD	is_dollar( VOID );
WORD	is_percent( VOID );
WORD	is_quote( VOID );
WORD	dieze_constants( VOID );
WORD	collect_string_litteral( VOID );
WORD	is_colon( VOID );
WORD	is_semi_colon( VOID );
WORD	is_ampersand( VOID );
WORD	is_plus( VOID );
WORD	is_question( VOID );
WORD	is_newline( VOID );
WORD	not_newline( VOID );
WORD	soft_newline( VOID );
WORD	is_operator( VOID );
WORD	arithmetical_operator( VOID );
WORD	is_hexa_digit( WORD );
WORD	is_decimal_digit( WORD );
WORD	token_is_not_numeric( WORD);
WORD	ll_get_token( VOID );
WORD	get_uppercase_token( VOID );
WORD	expand_token( VOID );
WORD	expand_macros( VOID );
WORD	get_token( VOID );
WORD	evaluate_token( VOID );
WORD	get_filename( VOID );
WORD	is_hexadecimal( VOID );
WORD	is_decimal( VOID );
WORD	is_numeric( VOID );
WORD	is_string_token( BPTR );
WORD	is_numeric_token( BPTR );
WORD	collect_hexadecimal( VOID );
WORD	collect_decimal( VOID );
WORD	collect_integer( VOID );
WORD	convert_hex_token( BPTR );
WORD	convert_int_token( BPTR );
WORD	convert_numeric_token( BPTR );
WORD	convert_integer_token( BPTR );
WORD	integer_term( VOID );
#ifndef	otr32
WORD	integer_overflow( WORD, WORD, WORD );
#endif
WORD	evaluate_integer( WORD, WORD, WORD );
WORD	integer_expression( VOID );
WORD	strindex( BPTR, WORD );
WORD	test_digit( WORD, WORD );
WORD	is_integer( BPTR );
WORD	get_label( VOID );
WORD	detect_label( WORD );
WORD	is_mnemonic( BPTR );
WORD	get_format( VOID );
WORD	detect_bal_comment( VOID );
WORD	is_star_comment( VOID );
BPTR	parser_line_buffer( VOID );
VOID	set_parser_line_buffer( BPTR );
WORD	initialise_line_parser( BPTR );
WORD	inhibit_semi_colon_comment( VOID );
VOID	inhibit_label_status( VOID );
VOID	inhibit_dieze_constants( VOID );
VOID	restore_dieze_constants( VOID );
WORD	restore_semi_colon_comment( WORD );
WORD	inhibit_apostrophe_comment( VOID );
WORD	inhibit_bal_comments( VOID );
WORD	inhibit_star_comments( VOID );
WORD	restore_bal_comments( WORD );
WORD	restore_star_comments( WORD );
WORD	restore_apostrophe_comment( WORD );
VOID	terminate_line_parser( VOID );
void	trace_line_buffer( VOID );
VOID	cancel_token_buffer( VOID );

#else

WORD	is_string_token();
WORD	is_numeric_token();
WORD	integer_expression();
WORD	is_mnemonic();
WORD	initialise_line_parser();
WORD	remove_white_space();
WORD	get_byte();
VOID	unget_byte();
WORD	get_token();
WORD	is_punctuation();
WORD	is_white_space();
WORD	is_punctuation_or_white_space();
VOID	inhibit_dieze_constants();
VOID	restore_dieze_constants();
#endif

#endif	/* _TRPARSER_H */
	/* ----------- */

