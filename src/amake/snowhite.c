#include <stdio.h>

int	verbose=0;
int	isobject=0;

char	ibuffer[1024];

char *	source="s";
char *	target="\0";
char *	makename="makefile";
char *	trace="\0";
char *	debug="\0";

char	whitebuffer[4096];

int	dofile( char * aptr )
{
	FILE	*	h;
	FILE	*	th;
	int		windex=0;
	int		working=0;
	int	c;
	int	i;
	if (!( h = fopen( aptr, "r" ) ))
		return(40);
	else if (!( th = fopen( "tempfile.out","w" ))) {
		fclose(h);
		return(46);
		}
	else	{
		while ((c = fgetc(h)) != -1) {
			switch ( c ) {
				case	'\n'	:
					if (!( working )) {
						windex=0;
						continue;
						}
					else	break;

				case	'\r'	:
				case	' '	:
				case	'\t'	:
					if (!( working )) {
						whitebuffer[windex++] = c;
						continue;
						}
				}
			if (!( working )) {
				for ( i=0; i < windex; i++ )
					fputc(whitebuffer[i],th);
				windex=0;
				}
			working++;
			fputc(c,th);
			if ( c == '\n' ) {
				working=windex=0;
				}
			}
		fclose(h);
		fclose(th);
		sprintf(whitebuffer,"mv tempfile.out %s",aptr);
		system(whitebuffer);
		return(0);
		}
}


int	banner()
{
	printf("\n   White Line Remover : Version 1.0a.0.01 \n\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	int	i;
	int	argi;
	char *	aptr;
	int	status=0;
	if ( argc == 1 )
		return(banner());
	else	{
		for (argi=1; argi < argc; argi++ ) {
			if (!( aptr = argv[argi]))
				break;
			else if ( *aptr == '-' ) {
				switch ( *(aptr+1) ) {
					case	'v'	:
					case	'V'	:
						verbose=1;
						break;
					}
				continue;
				}
			else  if (!( status = dofile( aptr ) ))
				continue;
			else	return( status );
			}
		}
	return(0);
}


