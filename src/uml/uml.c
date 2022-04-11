/* ------------------------------------------------------------------------------------------- 	*/
/* UML.C : Derivation of GRAPHIC.C											*/
/* ------------------------------------------------------------------------------------------- 	*/
/* this source shows the minimum required for the construction of a basic graphical program	*/
/* built around the pixel library. this may be used to derive more complicated programs.	*/
/* -------------------------------------------------------------------------------------------	*/
#include "allocate.h"
#include "guimouse.h"

/* --------------------------- */
/* these are required for cico */
/* --------------------------- */
int	err_val;
int	prndest=1;
int	prnleng=0;
int	prnfid=0; 
char * 	prnptr;

void	enter_modal()	{	return;		}
void	leave_modal()	{	return;		}

int	panic() 	{ 	return(0); 	}

void	inhibit_text_cursor()
{
	x_putch(27); x_putch('w');
	return;
}

void	activate_text_cursor()
{
	x_putch(27); x_putch('v');
	return;
}

void	mouse_move_on()
{
	set_mimo_mask((
		_MIMO_ALT	 |
		_MIMO_WHILE_DOWN |
		_MIMO_MOVE 	 |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_SEND_WHEEL |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT   	   ));
	return;
}

void	mouse_move_off()
{
	set_mimo_mask((
		_MIMO_ALT	 |
		_MIMO_WHILE_DOWN |
		_MIMO_DOWN 	 |
		_MIMO_UP 	 |
		_MIMO_SEND_WHEEL |
		_MIMO_SEND_RIGHT |
		_MIMO_SEND_LEFT   	   ));
	return;
}

int	open_graphics()
{
	if ( open_console() != 2 ) {
		return(0);
		}
	else	{
		initialise_mouse();
		mouse_move_off();
		cicopalette(0,0);
		inhibit_text_cursor();
		return(1);
		}
}

int	close_graphics()
{
	activate_text_cursor();
	terminate_mouse();
	return( close_console() );
}

/* --------------------------------- */
/* the program operation entry point */
/* --------------------------------- */
int	operation(char * aptr)
{
	set_desktop_name( aptr );
	set_desktop_icon( aptr );

	if ( open_graphics() != 0) {

		configuration_load("uml");
		umledit();

		close_graphics();
		}
	return(0);
}

int	banner()
{
	printf("\n   UML Modeling Tool for Sing : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 20/05/2006 ");
	printf("\n   Copyright (c) 2006 Amenesik / Sologic \n\n");
	return(0);
}


/* ------------------------------- */
/* standard C language entry point */
/* ------------------------------- */

int	main(int argc, char * argv[])
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argv[0]) );
}



