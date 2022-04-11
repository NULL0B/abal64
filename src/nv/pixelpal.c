#include <stdio.h>

void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}

int	verbose=0;

#include "vga.c"
#include "palette.c"


int	main(argc,argv)
int	argc;
char  * argv[];
{
	char	*aptr;
	int	argi;
	if ( argc < 2 ) {
		printf("\n   Pixel Palette Manager : Version 1.1a");
		printf("\n   Provisoire du 25/03/1999 ");
		printf("\n   Copyright (c) 1999,2006 Amenesik / Sologic ");
		printf("\n   Usage : ");
		printf("\n         -lfilename ");
		printf("\n         -sfilename \n");
		}
	else  for (argi=1; argi < argc; argi++ )
		if (((aptr = argv[argi]) != (char *) 0)
		&&  ( *(aptr++) == '-' ))
			switch ( *(aptr++) ) {
				case	'l' :
				case	'L' :
					load_palette( aptr);
					continue;
				case	's' :
				case	'S' :
					save_palette( aptr);
					continue;
				case	'v' :
				case	'V' :
					verbose++;
					continue;
				}
	return(0);
}


