#ifndef	_MODEL_C
#define	_MODEL_C

#include "lodriver.h"

#include "model.h"
#include "paper.c"

private	char * PaletteBuffer=(char *) 0;
private	char * PaletteBuffer=(char *) 0;
int	_fltused=0;
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

int	luminence( int v );

/*	---------------------------------------------------------------------------	*/
/*	D r i v e r I n i t i a l i s e ( palette, dpi, grnbcol, grnbrow, options )	*/
/*	---------------------------------------------------------------------------	*/
int	DriverInitialise(char * palette, int dpi, int grnbcol, int grnbrow, int options)
{
	PaletteBuffer = palette;
	return(0);
}

/*	---------------------------------------------------------------------------	*/
/*		    D r i v e r C o n n e c t ( bptr, wptr, result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverConnect( char * bptr, char * wptr, char * result )
{
	return(0);
}

/*	---------------------------------------------------------------------------	*/
/*			D r i v e r S t a r t R a s t e r ( result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverStartRaster(char * result)
{
	return(0);
}


/*	---------------------------------------------------------------------------	*/
/*		 	D r i v e r E n d R a s t e r ( result )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverEndRaster(char * result)
{
	return(0);
}

/*	---------------------------------------------------------------------------	*/
/*			D r i v e r L i b e r a t e ( result )				*/
/*	---------------------------------------------------------------------------	*/
int	DriverLiberate(char * result)
{
	return(0);
}

/*	---------------------------------------------------------------------------	*/
/*		D r i v e r P r i n t R o w ( result, rowbuffer )			*/
/*	---------------------------------------------------------------------------	*/
int	DriverPrintRow(char * result, char * rowbuffer)
{
	return(0);	
}

/*	---------------------------------------------------------------------------	*/
/*				D r i v e r C o l o u r s () 				*/
/*	---------------------------------------------------------------------------	*/
int	DriverColours()	
{	
	return(0); 	
}

#include "lodriver.c"

	/* ---------*/
#endif	/* _MODEL_C */
	/* ---------*/




