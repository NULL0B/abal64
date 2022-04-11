#include <stdio.h>
#include "exdll.h"

int	main(int argc, char * argv[] )
{
	int	verbose=0;
	int	x;
	int	e,r;
	int	argi;
	char *	aptr;
	struct	abal_program_handle * aph;
	if ( argc == 1 ) {
		printf("\n   Exa Dll Tester : Version 3.2a.0.01 ");
		printf("\n   Copyright (c) Amenesik / Sologic \n\n");
		return(0);
		}
	for (	argi=1; argi < argc; argi++ )  {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'v'	:
					verbose=1;
					continue;
				default		:
					printf("\nSyntax Error : %s \n",aptr);
					continue;
				}
			}
		else	{
			if (!( aph = LoadAbalProgram( aptr, 0 ))) {
				if ( verbose ) printf("\tProgram %s : Failure\n",aptr); 
				}
			else	{
				if ( verbose ) printf("\r\nProgram : %s \r\n",aptr);
				for (x=1; x < 256; x++) {
					if ( verbose ) printf("\tSegment : %u \r\n",x);
					if ((e = (aph->segment)(aph,x)) != 0)
						break;
					}
				if ( verbose ) printf("\tError   : %u \r\n",e); 
				for (x=0; x < 4096; x++) {
					if ( verbose ) printf("\tProcedure : %u \r\n",x);
					for ( r=0; r < x; r++ ) {
						(aph->parameter)(aph,0,r,(void *) 0);
						}
					if ((e = (aph->procedure)(aph,x)) != 0)
						break;
					}
				if ( verbose ) printf("\tError   : %u \r\n",e); 
				(aph->stop)(aph);
				}
			}
		}
	return(0);
}

