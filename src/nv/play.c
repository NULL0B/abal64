#include <stdio.h>

int	delay=10;
int	tempo=100;
int	aoi(char * sptr)
{
	int	r=0;
	while (*sptr) {
		if ((*sptr >= '0') && ( *sptr <= '9'))
			r = ((r * 10) + (*(sptr++) - '0'));
		else	break;
		}
	return(r);

}

int	play( int h )
{
	speaker(h);
	wait(delay);
	speaker(0);
}

int	option(char * aptr)
{
	int	i;
	switch ( *(aptr++) ) {
		case	't'	:
		case	'T'	:
			tempo = aoi(aptr);
			break;
		case	'r'	:
		case	'R'	:
			if ((i = aoi(aptr)) != 0)
				wait(i);
			speaker(0);
			break;
		case	'n'	:
		case	'N'	:
			if (!( delay = aoi(aptr )))
				delay = 10;
			break;
		}
	return;
}

banner()
{
	printf("\n   Note Play Utility : Version 1.1a.01 ");
	printf("\n   Provisoire du 09/05/2001 ");
	printf("\n   Copyright (me) 2001 \n");
	return;
}

int	main( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	if ( argc == 1 )
		banner();
	else for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' )
			option(aptr+1);
		else	play( aoi( argv[argi] ) );
		}
	return(0);
}

