//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_prllo_c
#define _prllo_c

#include <stdio.h>

#define	_LO_BUFFER_MAX 4096

static	char * 	LoBuffer=(char *) 0;
static	int	LoIndex=0;
static	int	LoHandle=0;
	
int	systemlowrite()
{
	int	e;
	int	i;
	int	c;
	if ((!( LoIndex  ))
	||  (!( LoHandle ))
	||  (!( LoBuffer )))
		return(0);
	else	{
		// Direct LO
		// ---------
		for ( i=0; i < LoIndex; i++ ) {
			c = *(LoBuffer+i);
#ifdef	DOS
			lllo( c );
#else
			_asm	{
				push	ax
				push	cx
				mov	ah,013h		;** Funtion LO
				mov	cx,c
				int	110
				sahf	
				mov	e,ax
				pop	cx
				pop	ax
				}
			e &= 0x00FF;
			if ( e ) 
				break;
#endif

			}
		LoIndex = 0;
		return(e);
		}
}

int	systemloclose()
{
	int	e=0;
	if ( LoBuffer ) {
		if ( LoIndex > 0 )
			(void) systemlowrite();
#ifdef	DOS
			lllo( 0x001A );
#else
		_asm	{
			push	ax
			push	cx
			mov	ah,013h		;** Funtion LO
			mov	cx,001AH	;** Close LO
			int	110
			sahf
			mov	e,ax
			pop	cx
			pop	ax
			}
#endif
		e &= 0x00FF;
		free( LoBuffer );
		LoBuffer = (char *) 0;
		LoHandle = 0;
		LoIndex  = 0;
		}
	return(e);
}

int	systemloopen()
{
	if ( LoBuffer )
		return(1);

	else if (!( LoBuffer = (char *) malloc( _LO_BUFFER_MAX )))
		return(0);

	else	{
		LoIndex  = 0;
		return((LoHandle=1));
		}
}

int	systemtplo()
{
	return(1);
}


int	systemlo( int c )
{
	int	e=0;
	if (!( LoBuffer )) 
		if (!(systemloopen()))
			return(27);

	if ( LoBuffer ) {
		if ( LoIndex >= _LO_BUFFER_MAX )
			if ((e = systemlowrite()) != 0)
				return(e);
		*(LoBuffer + (LoIndex++)) = (c & 0x00FF);
		}
	return(0);
}


#endif	// _prllo_c



