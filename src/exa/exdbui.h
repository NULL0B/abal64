/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBUI.H  				*/
/*		Date 	:	03/08/1993				*/
/*		Version :	2.1a       				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBUI_H
#define	_EXDBUI_H

#ifndef UNIX
VOID 	draw_box( EXAWORD, EXAWORD, EXAWORD, EXAWORD );
VOID 	draw_space( EXAWORD );
VOID 	left_string( EXAWORD, EXAWORD,EXAWORD, BPTR );
VOID 	centered_string( EXAWORD, EXAWORD, EXAWORD, BPTR );
VOID 	message_box( EXAWORD, EXAWORD, EXAWORD, EXAWORD, BPTR );
VOID 	draw_liste( EXAWORD, EXAWORD, EXAWORD, EXAWORD, SYMBOLPTR );
VOID	clear_screen( VOID );
VOID 	push_view( VOID );
VOID 	pop_view( VOID );
VOID 	standard_text_editor( BPTR );
EXAWORD 	display_integer( EXAWORD );
VOID 	display_hexint( EXAWORD );
EXAWORD 	display_variable_declaration( BPTR,EXAWORD );
VOID 	display_local_variables( SYMBOLPTR );
VOID 	display_correspondance(EXAWORD,EXAWORD,EXAWORD,EXAWORD, CORRESPTR );
VOID 	source_correspondance( SYMBOLPTR );
VOID 	zoom_code_block( SYMBOLPTR );
EXAWORD 	zoom_symbol( SYMBOLPTR );
EXAWORD	display_symbols( EXAWORD, EXAWORD, SYMBOLPTR );
VOID 	symbols_browser( VOID );
VOID	symbol_selector( EXAWORD );

EXAWORD 	display_menu( EXAWORD, EXAWORD, EXAWORD, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR );
EXAWORD 	tcode_correspondance( EXAWORD,EXAWORD,EXAWORD,EXAWORD );
#else
VOID 	draw_box();	/* EXAWORD, EXAWORD, EXAWORD, EXAWORD */
VOID 	draw_space();	/* EXAWORD );
VOID 	left_string();	/* EXAWORD, EXAWORD,EXAWORD, BPTR */
VOID 	centered_string();	/* EXAWORD, EXAWORD, EXAWORD, BPTR */
VOID 	message_box();	/* EXAWORD, EXAWORD, EXAWORD, EXAWORD, BPTR */
VOID 	draw_liste();	/* EXAWORD, EXAWORD, EXAWORD, EXAWORD, SYMBOLPTR */
VOID	clear_screen();	/* VOID */
VOID 	push_view();	/* VOID */
VOID 	pop_view();	/* VOID */
VOID 	standard_text_editor();	/* BPTR */
EXAWORD 	display_integer();	/* EXAWORD */
VOID 	display_hexint();	/* EXAWORD */
EXAWORD 	display_variable_declaration();	/* BPTR,EXAWORD */
VOID 	display_local_variables();	/* SYMBOLPTR */
VOID 	display_correspondance();	/*EXAWORD,EXAWORD,EXAWORD,EXAWORD, CORRESPTR */
VOID 	source_correspondance();	/* SYMBOLPTR */
VOID 	zoom_code_block();	/* SYMBOLPTR */
EXAWORD 	zoom_symbol();	/* SYMBOLPTR */
EXAWORD	display_symbols();	/* EXAWORD, EXAWORD, SYMBOLPTR */
VOID 	symbols_browser();	/* VOID */
VOID	symbol_selector();	/* EXAWORD */

EXAWORD 	display_menu();	/* EXAWORD, EXAWORD, EXAWORD, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR, BPTR */
EXAWORD 	tcode_correspondance();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD */
#endif

#endif	/* _EXDBUI_H */
	/* --------- */

