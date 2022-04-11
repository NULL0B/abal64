#include <stdio.h>

char	basefontbuffer[256];
char *	textfontbuffer=(char *) 0;
int	textfontsize=0;
int	textfontheight=0;
int	textfontwidth=0;
int	special=0;

void	*	malloc(int);
void		free( void *);

void	*	allocate( int n )
{
	return( malloc(n) );
}

void	*	liberate( void * vptr )
{
	free( vptr );
	return(0);
}

int	extractint( char * bptr )
{
	return( ( 
		 (* bptr    & 0x00FF) +
		((*(bptr+1) & 0x00FF) << 8 )
		)
		);
}


static	void	loadtextfont( char * nptr )
{
	FILE	* handle;
	int	status = 0;
	if ((handle = fopen( nptr, "rb")) != (FILE *) 0) {
		if ( fread(basefontbuffer,256,1,handle) == 1 ) {
			textfontsize = extractint( (basefontbuffer+16) );
			textfontheight = extractint( (basefontbuffer+18) );
			textfontwidth  = extractint( (basefontbuffer+20) );
			special        = extractint( (basefontbuffer+22) );
			if ((textfontbuffer = allocate( textfontsize )) != (char *) 0 ) {
				memcpy( textfontbuffer, basefontbuffer, 256 );
				if ( fread((textfontbuffer+256),(textfontsize - 256),1,handle) != 1 ) {
					textfontbuffer = liberate( textfontbuffer );
					textfontsize   = 0;
					}
				}
			}
		fclose( handle );
		}
	return;
}


void	operation( char * nptr )
{
	char	*	iptr;
	char	*	cptr;
	int		i;
	int		o;
	int		w;
	int		h;
	int		c;
	int		l;
	int 		r;

	printf("\nFont filename : %s\n",nptr);

	loadtextfont( nptr );

	if ( textfontbuffer ) {
		printf("symbolic name : %c",0x0022); 
		for ( i=0; i < 16; i++ ) {
			if (!( *(textfontbuffer+i) ))
				break;
			else	printf("%c",*(textfontbuffer+i));
			}
		printf("%c\n",0x0022);
		printf("file size     : %u \n",textfontsize);
		printf("cell width    : %u \n",textfontwidth);
		printf("cell height   : %u \n",textfontheight);
		if ( special == 0x2020 )
			printf("proportional font (perhaps)\n");

		iptr = (textfontbuffer+32);

		for (i=0; i < 256; i++ ) {
			o    = extractint( iptr ); iptr += 2;
			cptr = (textfontbuffer+o);
			h = extractint(cptr);
			w = extractint((cptr+2));
			cptr += 8;
			if ( i > 32 )
				printf("%c : ",i);
			else    printf("xx : ");

			printf("item=%u, offset=%x, height=%u, width=%u \n data",i,o,h,w);

			r = 0x0080;

			if ( special == 0x2020 ) {
				for (c=0; c < (w-1); c++ ) {
					r >>= 1;
					if (!( r )) {
						r = 0x0080;
						cptr++;
						}
					}
				}

			for (l=0; l < h; l++ ) {
				printf("\t");
				for (c=0; c < w; c++ ) {
					if ( *cptr & r )
						printf("þ");
					else	printf("ú");
					r >>= 1;
					if (!( r )) {
						cptr++;
						r = 0x0080;
						}					
					}
				printf("\n");
				}

			printf("\n");
			}

		textfontbuffer = liberate( textfontbuffer );
		}
	else	printf("file not found\n");

	return;
}

int	main( int argc, char * argv[] )
{
	int	argi;
	
	if ( argc == 1 )
		printf("\n   Font Manager File List Utility : Version 1.1a.0.01\n   Provisoire du 22/01/2001\n   Copyright (c) 2001,2006 Amenesik / Sologic \n");
	else for ( argi=1; argi < argc; argi++ )
		operation( argv[argi] );
	return(0);
}

