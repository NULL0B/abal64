#include <stdio.h>

int	verbose=0;
int	echo=0;

int	efgetc( FILE * h )
{
	int c;
	if (( c = fgetc(h)) != -1 )
		if ( echo )
			printf("%02.2X ",c);
	return(c);
}

void	efputc(int c, FILE * h )
{
	fputc(c,h);
	if ( echo )
		printf("%02.2X ",c);
}

unsigned 	long	getlong(FILE * h)
{
	int	c;
	unsigned	long	value=0L;
	if ((c = efgetc(h)) == -1)
		return( value );
	else 	value = (c & 0x00FF);
	if ((c = efgetc(h)) == -1)
		return( value );
	else 	value = (value  | ((c & 0x00FF) << 8));
	if ((c = efgetc(h)) == -1)
		return( value );
	else 	value = (value | ((c & 0x00FF) << 16));
	if ((c = efgetc(h)) == -1)
		return( value );
	else 	value = (value | ((c & 0x00FF) << 24));
	return( value );
}

void	putlong(FILE * h, unsigned long v)
{
	int	c;
	c = (v & 0x00FF);
	efputc(c,h);
	c = ((v >> 8) & 0x00FF);
	efputc(c,h);
	c = ((v >> 16) & 0x00FF);
	efputc(c ,h);
	c = ((v >> 24) & 0x00FF);
	efputc(c,h);
	return;
}

int	extract( FILE * h, char * prefix, int number )
{
	char	filename[256];
	unsigned long	filesize=0;
	FILE * r;
	int	i;
	int	c;
	sprintf(filename,"%s%u.wav",prefix,number);
	if (!( r = fopen( filename, "wb" ) ))
		return( 55 );

	fprintf(r,"RIFF");
	filesize = getlong(h);
	putlong( r, filesize );
	printf("wave file : %s : size %lu\n",filename,filesize);
	for ( i=0; i < filesize; i++ ) {
		if ((c = efgetc(h)) == -1)
			break;
		else	fputc(c,r);
		}
	fclose( r );
	return( 0 );
}


int	extractor( char * device , char * prefix )
{
	FILE * h;
	int	c;
	int	item=0;
	char *	pattern="RIFF";
	char *	pptr=pattern;

	/* Attempt to open source file */
	/* --------------------------- */
	if (!( h = fopen( device, "rb") )) {
  		return(40);
		}

	else 	{
		pptr = pattern;
		while ((c = efgetc(h)) != -1) {
			if ( *pptr != c ) {
				pptr=pattern;
				continue;
				}
			else 	{
				pptr++;
				if ( *pptr )
					continue;
				else if (!( extract( h, prefix, ++item ))) {
					pptr = pattern;
					continue;
					}
				else	break;
				}
			}
		fclose(h);
		return(0);
		}
}

int	doit( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	char *	prefix="cd";

	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-' ) {
			if (extractor( aptr, prefix ) != 0)
				break;
			else	continue;
			}
		else if ( *(aptr+1) == 'p' ) {
			prefix = (aptr+2);
			continue;
			}
		else if ( *(aptr+1) == 'v' ) {
			verbose=1;
			continue;
			}
		else if ( *(aptr+1) == 'e' ) {
			echo=1;
			continue;
			}
		}
	return(0);
}

int	banner()
{
	printf("\n   CD Wave File Extractor : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 28/09/2004 ");
	printf("\n   Copyright (c) Iain James Marshall \n\n ");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( doit( argc, argv ) );
}

