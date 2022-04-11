/* ------------------------------------------------------------------------------------------- 	*/
/* GRAPHIC.C											*/
/* ------------------------------------------------------------------------------------------- 	*/
/* this source shows the minimum required for the construction of a basic graphical program	*/
/* built around the pixel library. this may be used to derive more complicated programs.	*/
/* -------------------------------------------------------------------------------------------	*/

/* --------------------------- */
/* these are required for cico */
/* --------------------------- */
int	err_val;
int	prndest=1;
int	prnleng=0;
int	prnfid=0; 
char * 	prnptr;

int	panic() 	{ 	return(0); 			}
int	open_graphics()	{	return( open_console() );	}
int	close_graphics(){	return( close_console() );	}

/* --------------------------------- */
/* the program operation entry point */
/* --------------------------------- */
int	operation(char * aptr)
{
	set_desktop_name( aptr );
	set_desktop_icon( aptr );

	if ( open_graphics() != 0) {

		/* ---------------------------------------------- */
		/* this should be replaced by the required action */
		/* ---------------------------------------------- */
		x_getch();

		close_graphics();
		}
	return(0);
}

/* ------------------------------- */
/* standard C language entry point */
/* ------------------------------- */
int	main(int argc, char * argv[])
{
	return( operation(argv[0]) );
}


