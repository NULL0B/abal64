unsigned short int sicico=0;

#ifndef	_edmain_c

int     cicopagemargins(int lm, int rm, int tm, int bm )
{

}

#ifndef	_nededit_c
void	cicowindow()
{
	return;
}

int visual_scrollbar(
	unsigned int atx, unsigned int aty, 
	unsigned int nbx, unsigned int nby, 
	int f, int fg, int bg, 
	unsigned int item, unsigned int limit, unsigned int total, 
	int style )
{
	return(0);
}

void	initialise_mouse()
{
	initialise_editor_mouse();
	return;
}

void	terminate_mouse()
{
	terminate_editor_mouse();
	return;
}

#endif
#endif

#ifdef	_edmain_c
int	editorOnCommand(char * nptr, int l )
{
	return(27);
}
#endif

extern	int	UseEdExit;
extern	jmp_buf Ed_Exit;

int	editorOnError(int gravite, char * msg, char * nptr )
{
	show_editor_error(gravite,msg,nptr);
	return(0);
}

int	editorOnStatus( int option, int value )
{
	return(0);
}


void	si_fin() { return; }



