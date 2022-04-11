#include <stdio.h>
#include "stdpsu.h"
#include "guipixel.h"

void	*	malloc( int );
void		free( void * );

void *	allocate( int n ) { return( malloc( n ) ); }
void *	liberate(void *p ) { free(p); return((void *) 0);	}


int	main(int argc, char * argv[] )
{
	int	status;
	int	mode;
	int	argi;
	char * aptr;
	STDPSU * pptr=(STDPSU *) 0;
	if ( argc > 1 ) {
		for ( argi = 1; argi < argc; argi++ ) {

			if ((aptr = argv[argi]) != (char *) 0) {
				mode = 0;
				if ( *aptr == '-' ) {
					autoflag=1;
					continue;
					}
				else	{
					while (( *aptr >= '0' ) && ( *aptr <= '9'))
						mode = ((mode * 10)  + ( *(aptr++) - '0' ));
					}
				}
			else	mode = 0;
			
			(void) initialisepixel( mode );

				liberatepixel();
				}
			}

		}
	else	{
		printf("\n   Pheinteadh : Version 2.1a ");
		printf("\n   Provisoire du 16/08/1999 ");
		printf("\n   Copyright (c) Amenesik / Sologic \n");
		}
	return(0);
}



