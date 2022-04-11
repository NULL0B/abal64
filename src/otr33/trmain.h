/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 2003 Amenesik / Sologic Softawre			*/
/*									*/
/*									*/
/*		File	:	TRMAIN.H				*/
/*		Version :	3.01					*/
/*		Date	:	28/08/03				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRMAIN_H
#define	_TRMAIN_H

#ifndef	UNIX
WORD	show_class_dependance( VOID );
VOID	translator_identification( VOID );
VOID	initialise_option_pointers( VOID );
VOID	liberate_for_options( VOID );
VOID	set_global_error( WORD );
WORD	error_limit_reached( VOID );
WORD	analyse_option_file( BPTR );
WORD	analyse_translator_options( BPTR );
WORD	translator_command_line( BPTR );
VOID	banner( VOID );;
VOID	verbalise_options( BPTR );
WORD	run_linker( BPTR );
int	is_target_file_busy( BPTR );
BPTR	x_getenv(BPTR);
#ifdef WIN32
int majn( int, BPTR *);
#else 
int main( int, BPTR *);
#endif
#else
#endif

#endif 	/* _TRMAIN_H */

