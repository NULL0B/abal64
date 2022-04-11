#define	UDP_TRANSPORT 0
#define	TCP_TRANSPORT 1

#include "ipx.h"

int	VncTransport=TCP_TRANSPORT;
int	MaxMode=5;
int	usegraphics=1;

#include "vncmem.c"
#include "vncstub.c"


char * convert_integer( char * sptr, int * iptr )
{
	int	result=0;
	int	neg=0;

	if ( *sptr == '-' )
		neg = *(sptr++);
	else	neg = 0;
 		
	while ( *sptr ) {
		if (( *sptr >= '0' ) && ( *sptr <= '9' ))
			result = ((result * 10) + ( *(sptr++) - '0'));
		else	break;
		}

	if ( neg )
		*iptr = ( result * -1 );
	else	*iptr = result;
	return( sptr );
}

void	usage()
{
	printf("\n   usage:");
	printf("\n   -a<password>     host user password ");
	printf("\n   -b<biosmode>     force bios mode 0 to 5 ");
	printf("\n   -c<colours>      set true colour 8 or 16 ");
	printf("\n   -d               activate debug messages ");
	printf("\n   -g               inhibit graphics ");
	printf("\n   -h<host>         name or address ");
	printf("\n   -ip              using TCP/IP protocol ");
	printf("\n   -ipx             using SF/IPX protocol ");
	printf("\n   -l<mode>         raw 0, hextile,4 ");
	printf("\n   -p<screen>       number of host screen ");
	printf("\n   -tshutdown       experimental only ");
	printf("\n   -v               activate verbose messages ");
	printf("\n   -x               exclusive access \n");
	return;
}

void	banner(char * title)
{
	printf("\n   %s Version 1.1a.0.04 - P3",title);
	printf("\n   Provisoire du 26/12/2000");
	printf("\n   Copyright (c) 2000 Amenesik / Sologic  \n");
	usage();
	return;
}

int	analyse_command_line(int argc, char *argv[])
{
	int	argi;
	int	i;
	int	status=0;
	char *	aptr;

	initialise_colours(PaletteMode);

	if ( argc <= 1 )
		return(0);

	for (argi=1; argi < argc; argi++ ) {

		if (!(aptr = argv[argi]))
			return(-1);
		else if (*(aptr++) != '-' )
			return(-1);

		while ( *aptr ) {
			switch ( *(aptr++) ) {

				case	'a'	:
					vncServerPassword = aptr;
					break;

				case	'b'	:

					aptr = convert_integer( aptr, & BiosMode );
					break;

				case	'c'	:

					aptr = convert_integer( aptr, & PaletteMode );
					if ( PaletteMode > 8 )
						PaletteMode = 16;
					else 	PaletteMode =  8;
					break;

				case	'd'	:	
					debug   = 1; 
					continue;

				case	'g'	:	
					usegraphics = 0;
					continue;

				case	'h'	:	
					for ( i=0; *aptr != 0; aptr++, i++) {
						if ( *aptr == ':' )
							break;
						else	vncServerHost[i] = *aptr;
						}
					vncServerHost[i] = 0;
					status|=1;

					if ( *aptr != ':' )
						break;
					else	aptr++;

				case	'?'	:
					banner( programName );
					return(-1);
								
				case	'l'	:
					aptr = convert_integer( aptr, & MaxMode  );
					if ( MaxMode > 5 )
						MaxMode = 5;
					else if ( MaxMode < 0 )
						MaxMode = 0;
					break;					

				case	'p'	:	
					aptr = convert_integer( aptr, & vncServerPort );
					status|=2;
					break;

				case	't'	:
					terminate = 1; 
					continue;

				case	'v'	:
					verbose = 1; 
					continue;

				case	'x'	:
					IsExclusive = 1;
					continue;

				case	'i'	:
				case	'I'	:
					if (( *aptr != 'p' )
					&&  ( *aptr != 'P' ))
						return(-1);
					else if (!( *(aptr +1) )) {
						VncTransport=TCP_TRANSPORT;
						continue;
						}
					else if (( *(aptr+1) != 'x' )
					     &&  ( *(aptr+1) != 'X' ))
						return(-1);
					else	{
						VncTransport=IPX_TRANSPORT;
						continue;
						}

				default		:	return(-1);
	
				}
			break;
			}
		}
	initialise_colours(PaletteMode);
	return( status );

}


