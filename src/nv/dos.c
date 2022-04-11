//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef	_dos_system_c
#define	_dos_system_c
#define	DOS
//	----------------------------------------------
//	CICO Global Variables required for DOSCICO.LIB
//	----------------------------------------------
short int	err_val=0;
short int	prndest=1;
unsigned char * prnptr=(unsigned char *) 0;
short int	prnleng=0;
short int	prndex=0;
short int	prnfid=0;

#define	O_BINARY 0x8000

#include "gui.c"

#include "stubsi.c"
#include "stubmc.c"
#include "stubpsu.c"

int	HttpPost() { return(0); }
void	vgapalette() { return; }
int	HttpSetType() { return(0); }
void	BugCatcher() { return; } 
//	---------------------------------------
//	Stub functions to DOSCICO.LIB Functions
//	---------------------------------------
int	cico_max_lines()	{ return(22); }
void	cico_open() 			{ initerm();  return;	}
void	cico_close()			{ finterm();  return;	}
void	cico_foreground( int f ) 	{ foregr( f );return;	}
void	cico_background( int b ) 	{ backgr(( b & 0x0007));return;	}
void	cico_putch( int c )	 	{ x_putch(c); return;	}
void	cico_puts( char * sptr )
{ 
	while ( *sptr )
		cico_putch( *(sptr++) );
	return;
}

int 	wait(int i)
{
	int	j;
	int	k;
	for (; i > 0; i--)
		for ( j=1; j != 0; j++ )
			k += (i*j);
	return(k);
}

void	cico_clear()		 	{ cico_putch(0x000C); return; 	}
void	cico_curser(int l, int c)	{ pos(l,c); return;	}

static	int	MimoLin=1;
static	int	MimoCol=1;
static	int	MimoTyp=1;
static	int	MimoPar=1;
static	int	MimoHit=0;

#include "catcher.c"

#include "encode64.c"

#define	_MACROVALDOS
#include "macroval.h"

int	hostpathsep()	{ return( '\\' ); }

void	abqt()
{
	return;
}
		
int	macro_getch( int c )
{
	return( macrovalue[(c & 0x00FF)] );
}

int	is_macro( int c )
{
	int	i;
	c &= 0x00FF;
	if ( c <= 127 )
		return(c);
	else	{
		for ( i=128; i < 256; i++ )
			if (( macrovalue[i] & 0x00FF) == c )
				return(i);
		return(c);
		}
}

int	is_mouse_active() { return(0); }
void	make_mouse_move() { return;    }

void	mimo_move() { return;    }
void	mimo_nomove() { return;    }

int	trace_control=0;

FILE * trace_handle=(FILE *) 0;
long	trace_alloc;
long	trace_liber;

void	start_alloc_trace(char * mptr)
{
	if ((!( mptr ))
	||  (!( *mptr )))
		mptr = "trace.mem";
	if ((!( trace_control)) 
	&&  (!( trace_handle )))
		if ((trace_handle = fopen( mptr , "w" )) != (FILE *) 0)
			trace_control=1;
	return;
}
		
void	flush_alloc_trace()
{
	if ( trace_control ) {
		if ( trace_handle ) {
			fprintf(trace_handle,"end\n\n%c",0x001A);
			fclose( trace_handle );
			trace_handle = (FILE *) 0;
			}
		}
	return;
}

int 	mimo_getch()	
{ 
	int	c;
	int	state=0;
	MimoHit = 0;
	while ( 1 ) {
		if ( state )
			cico_curser(MimoLin,MimoCol);
		if ((c = x_getch()) == '^') {
			if ( state ) {
				state = 0;
				cico_putch(27); 
				cico_putch('w');
				}
			else	{
				state = 1;
				cico_putch(27); 
				cico_putch('v');
				}
			}
		else if (!( state ))
			return( c );
		else	{
			switch ( c ) {
				case	6	:
					if ( MimoCol < 80 ) {
						MimoCol += 1;
						continue;
						}
					else	MimoCol = 1;

				case	5	:
					if ( MimoLin < 24 )
						MimoLin += 1;
					else	MimoLin = 1;
					continue;

				case	8	:
					if ( MimoCol > 1 ) {
						MimoCol -= 1;
						continue;
						}
					else	MimoCol = 80;
						
				case	11	:
					if ( MimoLin > 1 )
						MimoLin -= 1;
					else	MimoLin = 24;
					continue;

				case	'l'	:
				case	'L'	:
					MimoPar = 1;
					MimoHit = 1;
				cico_putch(27); 
				cico_putch('w');
					return( 256 );
				case	'r'	:
				case	'R'	:
					MimoPar = 2;
					MimoHit = 1;
					cico_putch(27); 
					cico_putch('w');
					return( 256 );
				}
			}
		}

}

// int 	cico_getch()		 	{ return(x_getch()); 	}

int 	cico_getch()		 	{ return(mimo_getch()); 	}
int	cico_kbhit()			{ return(x_kbhit());		}

void	lllo(int c)
{
	prndest = 2;
	prnfid  = 0;
	cico_putch( c );
	prndest = 1;
	return;
}

#include "prllo.c"

int	consoletype()
{
	return(0);
}

int 	cico_event( int i)
{ 
	if ( MimoHit ) {
		switch (i) {
			case	1 : return( MimoLin );
			case	2 : return( MimoCol );
			case	3 : return( MimoTyp );
			case	4 : return( MimoPar );
			}
		}
	return(0);         	

}

int	rawopen( char * nptr )
{
	return( open( nptr, O_BINARY ) );
}

void	rawclose( int handle )
{
	close( handle );
	return;
}

int	rawread( int handle, char * buffer, int length )
{
	return( read(handle,buffer,length) );
	return(0);
}

//	----------------------------------------------------------------
//		S Y S T E M _ U S E B A S E ( RPTR, NPTR, BPTR )
//	----------------------------------------------------------------
//	This function will perform Absolute/Relative Path checking
//	on the new name NPTR and the old name BPTR and return
//	the result in the ALREADY allocated zone (long enough for
//	the storage of both strings and a zero) RPTR.
//	----------------------------------------------------------------

void	system_usebase( char * rptr, char * nptr, char * bptr )
{
	int	nlen=0;
	int	blen=0;
	int	rlen=0;
	int	pathsep;
	int	i;

	// Calculate Length of New String
	// ------------------------------
	if ( nptr )
		while ( *(nptr + nlen) ) nlen++;
	else	return;

	rlen += nlen;

	// -----------------------------------------
	// First Check if NPTR is Absolute : DEVICED
	// -----------------------------------------
	if (( nlen > 2 )
	&&  ( *(nptr + 1) == ':' )
	&&  (   (( *nptr >= 'a' ) && ( *nptr <= 'z' ))
	     || (( *nptr >= 'A' ) && ( *nptr <= 'Z' )) )) {
		for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);
		}
	// --------------------------------------------
	// Otherwise Check if NPTR is Absolute : PATHED
	// --------------------------------------------
	else if (( *nptr == '/'   )
	     ||  ( *nptr == 0x05C )) {
		for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);
		}
	// ---------------------------------------
	// Check if a Valid Base has been provided
	// ---------------------------------------
	else if (!( bptr )) {
		for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);
		}
	// ------------------------------------------------------------
	// So Now locate relevant portion of the Base for concatenation
	// ------------------------------------------------------------
	else	{
		while ( *(bptr + blen) ) blen++;
		switch ((pathsep = *bptr)) {
			case	'/'	:
			case	0x005C	:
				break;
			default		:
				pathsep = 0;
				
				if (( blen > 2 )
				&&  ( *(bptr + 1) == ':' )
				&&  (   (( *bptr >= 'a' ) && ( *bptr <= 'z' ))
				     || (( *bptr >= 'A' ) && ( *bptr <= 'Z' )) ))

					// Has a Device Is a Path Sep There
					// --------------------------------
					switch ((pathsep = *(bptr + 2))) {
						case	'/'	:
						case	0x005C	:
							break;
						default		:
							pathsep = ':';
						}

				if (!( pathsep ))
					for ( i=(blen-1); i != 0; i-- )
						if (( *(bptr + i) == '/' )
						||  ( *(bptr + i) == 0x005C ))
							pathsep = *(bptr + i);
			}

		// ----------------------------------
		// If a path separator has been found
		// ----------------------------------
		if ( pathsep ) {

			// -------------------------------------
			// Special Case for X:FILE type syntax
			// -------------------------------------
			if ( pathsep == '.' )
				blen = 2;

			// ---------------------------------------
			// Scan backwards from the end of the Base
			// trying to find the last path separator
			// ---------------------------------------
			else	for ( blen--; blen != 0; blen-- )
					if ( *(bptr + blen) == pathsep ) {
						blen++;
						break;
						}


			// ---------------------------------------
			// Transfer the Base Portion to the Result
			// ---------------------------------------
			for (rlen=0; rlen < blen; rlen++ )
				*(rptr + rlen) = *(bptr + rlen);

			// ------------------------------------
			// Transfer the New Name to the Result
			// ------------------------------------
			for (blen = 0; blen < nlen; blen++, rlen++ )
				*(rptr + rlen) = *(nptr + blen);
			}

		// -----------------------------------------------------------
		// Otherwise no way of determining what to take so just 
		// return the new name string and keep our fingers crossed
		// -----------------------------------------------------------
		else	{
			for (rlen=0; rlen < nlen; rlen++ ) *(rptr + rlen) = *(nptr + rlen);
			}
		}

	// --------------------------------------------------------
	// Finally Convert Result to Correct System Type Separators
	// --------------------------------------------------------
	*(rptr+rlen) = 0;


	for ( ; *rptr; rptr++ )
		if ( *rptr == '/' )
			*rptr = 0x005C;


	return;
}

//	---------------------------	--------------------------------
//	HTTP LIBRARY STUB FUNCTIONS	( Not available in DOS version )
//	---------------------------	--------------------------------
#include "stubhttp.c"

//	----------------------------	--------------------------------
//	PIXEL LIBRARY STUB FUNCTIONS	( Not available in DOS version )
//	----------------------------	--------------------------------
#include "stubgui.c"


//	----------------------------	--------------------------------
//	DYNAMIC LIBRARY STUB FUNCTIONS	(No DDL loadinig in DOS Version)
//	----------------------------	--------------------------------
#include "stubbda.c"

#endif	// _dos_system_c

