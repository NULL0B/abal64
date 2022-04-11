#ifndef _EXMPEGC_C	
#define	_EXMPEGC_C	

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMPEGC.C  				*/
/*		Version :	3.3b 					*/
/*		Date 	:	27/11/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
/*		EXMPEGC	:	Abal Runtime Remote Program Server	*/
/*----------------------------------------------------------------------*/
/*	This module is a test client for the new internet service for 	*/
/*	the processing of remote mpeg attachment requests and remote	*/
/*	procedure calls from distant remote mpeg clients.		*/
/*	The client sends requests for mpeg attachment and procedure	*/
/*	invocation prior to integration of this underneath the standard	*/
/*	ABAL instructions.						*/
/*----------------------------------------------------------------------*/

#include "exmpegs.h"


static	struct  remote_mpeg_server MPEGC = {
	0,
	256,
	_DEFAULT_ABAL_MPEGS_PORT,
	AF_INET,
	2
	};


static	int	failure(char * message, int evalue )
{
	printf("\nerror:%u:%s\n",evalue,message);
	return( evalue );
}

static	int	mpeg_client(char * url )
{
	int	h;
	if ((h = open_mpeg_client( url )) == -1)
		return( failure("open mpeg client",h) );
	else
	{
		h = close_mpeg_client( h );
		return(0);
	}
}

static	int	operation(int argc, char * argv[])
{
	int	status;
	int	argi;
	char *	aptr;
	for (	argi=1; argi < argc; argi++ )
	{
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' )
		{
			if ((status = option_mpeg_client( (aptr+1) )) != 0)
				return(status);
			else 	continue;
		}
		else if ((status = mpeg_client( aptr )) != 0 )
			return(status);
		else 	continue;
	}
	return(0);
}			

static int	banner()
{
	printf("\n   Abal MPEG Client : Version %u.%u%c.%u.%u ",3,3,'b',0,1);
	printf("\n   Provisoire du 27/11/2010 ");
	printf("\n   Copyright (c) 2010 Amenesik / Sologic \n\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv) );
}
	/* ---------- */
#endif	/* _EXMPEGC_C */
	/* ---------- */

