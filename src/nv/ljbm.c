#ifndef	_LJBM_C
#define	_LJBM_C

#include "lodriver.h"
#include "ljbm.h"

#define	putlo(v) *(result+(rlen++))=v
#define	escapeT( v ) rlen = packethead(result,rlen,v)

int	RowLength=0;
char *	PaletteBuffer=(char *) 0;

int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

int	DriverInitialise(char * palette, int dpi, int grnbcol, int options)
{
	PaletteBuffer = palette;
	return(((RowLength=grnbcol)+256));
}

int	DriverConnect( char * bptr, char * wptr, char * result )
{
	strcpy(result,"LJBM");
	return( 4 );
}

int	DriverStartRaster(char * result)
{
	*result = '[';
	return(1);
}

int	DriverEndRaster(char * result)
{
	*(result++) = 0;
	*(result++) = 0;
	*(result++) = ']';
	return(3);
}

int	DriverLiberate(char * result)
{
	*result = 0x001A;
	return(1);
}

int	DriverPrintRow(char * result, char * rowbuffer)
{
	int	r;
	*(result++) = (RowLength & 0x00FF);
	*(result++) = ((RowLength & 0xFF00)>>8);
	for ( r=0; r < RowLength; r++ )
		*(result+r) = *(rowbuffer+r);
	return(RowLength+2);
}

int	DriverColours()	{	return(256); 	}


#include "lodriver.c"



	/* ----------- */
#endif	/* _DRIVERABAL_C */
	/* ----------- */




