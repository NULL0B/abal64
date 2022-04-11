#include <stdio.h>

#define	LL_BUF_MAX 256

#ifdef	DOS
FILE *	llhandle=(FILE *) 0;
#else
int	llhandle=-1;
int	llindent=0;
int	llbufmax=0;
char	llbuffer[LL_BUF_MAX];
#endif

int		echo=0;
int		verbose=0;
int		ungrotch=0;
int		pages=0;
int		rastering=0;

char		PacketBuffer[2048];

int	report_error( char * message )
{
	printf("\nERROR : %s \n",message);
	return(0);
}

void	ungretch( int c )
{
	ungrotch = c;
	return;
}

void	llclose()
{
#ifdef	DOS
	if ( llhandle != (FILE *) 0 )
		fclose( llhandle );
	llhandle = (FILE *) 0;
#else
	if ( llhandle != -1 ) {
		close( llhandle );
		llhandle = -1;
		}
#endif
	return;	
}

int	gretch()
{
	int	c;
	if ((c = ungrotch )!=0)
		ungrotch = 0;
#ifdef	DOS
	else if ( llhandle != (FILE *) 0 )
		c = fgetc( llhandle );
	else	c = -1;
#else
	else if ( llhandle == -1 )
		c == llhandle;
	else 	{
		if ( llindent >= llbufmax ) {
			llbufmax = read( llhandle, llbuffer, LL_BUF_MAX );
			llindent = 0;
			}
		if ( llindent < llbufmax )
			c = llbuffer[llindent++];
		else	c = -1;
		}
	if ( c == -1 ) {
		llclose();
		}
	else
#endif
	 if ( echo )
		printf("[%02.1X]",c);
	return( c );
}
	
int	llopen(char * nptr )
{
#ifdef	DOS
	if ((llhandle = fopen( nptr, "rb" )) != (FILE *) 0) {
#else
	if (( llhandle = open( nptr, 0 )) != -1 ) {
		llindent=0;
		llbufmax =0;
#endif
		return(1);
		}
	else	return(0);
}

void	formfeed()
{
	pages++;
	if ( verbose ) printf("\n Form Feed %u \n",pages);
	return;
}

int	escapeT()
{
	int	h;
	int	l;
	int	c;
	if (((c = gretch()) == 27)
	&&  ((c = gretch()) == 'T')) {
		if (((l = gretch()) != -1)
		&&  ((h = gretch()) != -1))
			return( (((h & 0x00FF) << 8) | (l & 0x00FF)) );
		else	return(0);
		}
	else	{
		ungretch( c );
		return(0);
		}
}

int	readpacket( int nombre )
{
	int	i;
	int	c;
	for ( i=0; i < nombre; i++ ) {
		if ((c = gretch()) == -1)
			return(0);
		else if ( c == 27 )
			PacketBuffer[i] = '[';
		else	PacketBuffer[i] = c;
		}
	PacketBuffer[i] = 0;
	return( nombre );
}

int	getpacket()
{
	int	counter;
	if (!(counter = escapeT() ))
		return( report_error( "expected escape T" ) );
	else 	return( readpacket( counter ) );
}


int	check_command( char * cptr, int counter)
{
	int	variable=-1;
	int	i=0;

	if ( verbose )
		printf("\ncheck_command( %s, %u , %s )\n",cptr,counter,PacketBuffer);

	while (( *cptr )
	&&     ( i < counter )) {

		if ( *cptr == '#' ) {
			variable=0;
			while ( i < counter ) {
				if (( PacketBuffer[i] >= '0' )
				&&  ( PacketBuffer[i] <= '9' ))
					variable = ((variable * 10) + (PacketBuffer[(i++)] - '0'));
				else	break;
				}
			}
		else if ( *cptr != PacketBuffer[(i++)] )
			break;
		cptr++;			
		}
	if ( *cptr )
		return( 0 );
	else if ( variable != -1 )
		return( variable );
	else	return( counter );
}

int	is_command( char * cptr )
{
	int	counter;
	if (!(counter = getpacket()))
		return( report_error( "expected packet" ) );
	else	return( check_command( cptr, counter ) );
}

int	start_raster()
{
	int	dotsperinch;
	if (!(dotsperinch = is_command( "[*t#R" )))
		return( report_error( "expected dots per inch" ) );
	else if (!( is_command( "[*r0A" ) ))
		return( report_error( "expected set left margin" ) );
	else if (!( is_command( "[*r0F" ) ))
		return( report_error( "expected in X direction" ) );
	else if (!( is_command( "[*r1N" ) )) 
		return( report_error( "expected set opaque" ) );
	else	return( dotsperinch );
}

int	collect_raster( int counter )
{
	int	i;
	int	c;
	for (i=0; i < counter; i++ )
		if ((c = gretch()) == -1)
			return(i);
	return( counter );
}
 
int	get_rasters(int dpi)
{
	int	counter;
	int	rastersize;
	if ( verbose )
		printf("Raster Collection %u dpi \n",dpi);
	
	while (1) {

		if (!(counter =  getpacket() ))
			return(0);
		else if (!( rastersize = check_command("[*b#W", counter) )) {
			if (!( check_command( "[*rC", counter )))
				return( report_error("expected raster") );
			else	return(1);
			}
		}
}
int	graphics_packet()
{
	int	dpi;
	if (!(dpi = start_raster() ))
		return( 0 );
	else	return( get_rasters(dpi) );
}

void	banner()
{
	printf("\n   Lyne, The Laser Jet Escape File Analyser : Version 1.1a ");
	printf("\n   Provisoire du 18/08/1999 ");
	printf("\n   Copyright (c) 1999,2006 Amenesik / Sologic \n");
	return;
}

int	initialise_printer()
{
	int	c;
	if (!( is_command( "[E" ) ))
		return( report_error( "initialisation failure" ) );
	else	return(1);
}

int	analyse_file( char * nptr )
{		
	int	status=1;
	int	c;
	if ( llopen( nptr ) ) {
		
		// Check for Initialisation Sequence
		// ---------------------------------
		if ((status = initialise_printer()) !=0) {
			while ((c = gretch()) != -1) {
				switch ( c ) {
					case	0x000C	:
						formfeed();
						continue;
					case	0x001B	:
						ungretch( c );
						if ( graphics_packet() )
							continue;
						else	break;
					default		:
						status = report_error("unexpected character");
						break;
					}
				break;
				}
			}			

		llclose();
		return(status);
		}
	else	return( report_error( "file error" ) );
}

int 	analyse_option( char * optr )
{
	switch ( *(optr++) ) {
		case	'v' :
		case	'V' :	return((verbose=1));
		case	'e' :
		case	'E' :	return((echo=1));
		default	    :	return( report_error( "incorrect option" ) );
		}
}

int	main( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	if ( argc == 1 )
		banner();

	for ( argi=1; argi < argc; argi++ ) {

		if (!(aptr = argv[argi]))
			break;
		else if ( *aptr == '-' ) {
			if (!( analyse_option( aptr + 1 ) ))
				break;
			}
		else if (!( analyse_file( aptr ) ))
			break;
		}
	return(0);
}


