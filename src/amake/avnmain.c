#ifndef	_avnor_c

int	main( int argc, char * argv[] )
{
	int	nb=0;
	int	argi;
	char *	aptr;
	char *	bptr;
	char *	optr;
	aptr = bptr = (char *) 0;
	if ( argc == 1 ) {
		printf("\n   avnor file compare : version 1.0a.0.01");
		printf("\n   Provisoire du 05/01/2004");
		printf("\n   Copyright (c) 2004 Amenesik / Sologic \n\n");
		}
	else	{
		for ( argi=1; argi < argc; argi++ ) {
			if (!( optr = argv[argi]))
				break;
			else if ( *optr == '-' ) {
				if ( *(optr+1) == 'e' )
					echo=1;
				else if ( *(optr+1) == 'v' )
					verbose=1;
				continue;
				}
			else if (!( aptr )) {
				if (!( aptr = argv[argi] ))
					break;	
				else	continue;
				}
			else if (!( bptr = argv[argi] ))
				break;
			else	{
				if ((nb = difference(aptr,bptr)) != 0) {
					if ( verbose ) {
						if  (!( inhibit ))
							printf("%s : %s : %u differences \n",aptr,bptr,nb);
						}
					else	show_differences(aptr,bptr);
					return(nb);
					}
				else	{
					if ( verbose ) {
						if  (!( inhibit ))
							printf("%s : %s : identical files\n",aptr,bptr); 
						}
					return(0);
					}
				}
			}
		}
	return(0);
}
#endif	/* _avnor_c */


