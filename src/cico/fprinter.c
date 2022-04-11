#include <stdio.h>

#define	WORD	unsigned short
#define	BYTE	unsigned char 
#define	VOID	void

#include "ixim.h"

static	int	echo=0;
static	int	verbose=1;

int	failure(int v)
{

	if ( v != 0 )
		if ( verbose )
			printf("\nerror: %u \n",v);
	return(v);
}

int	printit( char * pname, char * fname )
{
	FILE *	h;
	int	i;
	BYTE 	c;
	short int 	p=0;

	if (!( pname )) 			return(failure(30));
	if (!( fname )) 			return(failure(31));
	if (!( h = fopen( fname, "r" )))	return(failure(40));

	prnflag = 16;

	if (( p = im_open( pname, 3 )) == -1 )	{
		fclose( h );
		return(failure(1));
		}
	else	{
		if ( verbose )
			printf("printing  %s on %s \n",fname,pname);
		while ((i = fgetc(h)) > 0) {
			c = i;
			if ( echo )
				printf("%c",c);
			im_write(p,&c,1);
			}
		im_close(p);
		fclose(h);
		if ( verbose )
			printf("ok\n");
		return(0);
		}

}

int	option( char * aptr )
{
	switch ( *(aptr++) ) {
		case	'e'	:	echo=1; return(0);
		case	's'	:	verbose=0; return(0);
		case	'v'	:	verbose=1; return(0);
		default		:	return(30);
		}
}

int	doit(int argc, char * argv[] )
{
	char	*	printer;
	int		argi;
	int		status=0;
	char	*	aptr;
	printer=argv[1];
	initform(0,(char *) 0,(char *) 0);
	for ( argi=2; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if (!( status = option( (aptr+1))))
				continue;
			else	break;
			}
		else if (!(status = printit(printer,aptr)))
			continue;
		else	break;
		}
	finform();
	return( status );
}

int	what()
{
	printf("\n   File Printer : Version 1.0.1 ");
//	printf("\n   Provisoire du 29/08/2002 ");
	printf("\n   Copyright (c) 2019 A.P.I. \n");
	printf("\n   Usage : fprinter <printer> <files>\n");
	return(0);
}

int	main(int argc, char * argv[] )
{
	if ( argc <= 2 )
		return( what() );
	else	return( doit(argc,argv) );
}


