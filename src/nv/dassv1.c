//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_DASSV1_C
#define _DASSV1_C

#include "dassv1.h"




static	void	putabalword( char * p, int v )
{
	*(p++) = ((v & 0xFF00) >> 8);
	*(p++) = (v & 0x00FF);
	return;
}

static	int 	getabalword( char * p )
{
	int	v;
	v = ((*(p++) & 0x00FF) << 8);
	v |= (*(p++) & 0x00FF);
	return(v);
}


static unsigned short int DasSv1Connect( unsigned short int function_code, unsigned short int parameters )
{
	int	lerr;
	if ( DasSv1LibId != -1 ) {
		lerr = CallRunTime( 	
				DasSv1LibId,
				function_code,
				parameters,
				DasSv1Bstack,
				DasSv1Pstack,
				DasSv1Wstack );
		printf("%u = CallRunTime(%u,%u,%u)\n",lerr,DasSv1LibId,function_code,parameters);
		return( lerr );
		}
	else	return( DasSv1LibId );
}

short int  InitDassv1(int n)
{
	int	lerr;
	if (!( DasSv1DllLoaded )) {
		if (!( DasSv1LibraryName )) {
			DasSv1LibraryName = (unsigned char *) "dassv1";
			DasSv1LibraryFlag = 0;
			}
		lerr = InitRunTime((DasSv1LibId=n),DasSv1LibraryName,0,&DasSv1Context,sizeof( BDA_INIT ));
		DasSv1DllLoaded=1;
		return(0);
		}
	else	return(-1);
}

short int  FinDassv1()
{
	int	lerr;
	if ( DasSv1DllLoaded ) {
		lerr = FinRunTime(DasSv1LibId);
		DasSv1LibId=-1;
		DasSv1DllLoaded=0;
		return(0);
		}
	else	return(-1);
}

unsigned short int DasConnect(
		char * buffer,		/* Buffer to receive hancle 	*/
		char * pptr,		/* Profile Name			*/
		char * nptr, 		/* Alternative telephone	*/
		char * uptr,		/* Alternative username		*/
		char * wptr,		/* alternative pass word	*/
{
	BdaByteResult( buffer ); 



void	BdaParameter( void * bptr, int blen, int btype )
{
	LongHeap[HeapIndex] = bptr;
	WordHeap[HeapIndex] = (blen & 0xFFFF);
	ByteHeap[HeapIndex] = (btype & 0x00FF) ;
	HeapIndex += 1;
	return;
}



	DasSv1Pstack[0]  = (unsigned char *) buffer;
	DasSv1Wstack[0]  = 1;
	DasSv1Bstack[0]  = 0x80;

	DasSv1Pstack[1]  = (unsigned char *) pptr;
	DasSv1Wstack[1]  = plen;
	DasSv1Bstack[1]  = 0x03;

	DasSv1Pstack[2]  = (unsigned char *) nptr;
	DasSv1Wstack[2]  = nlen;
	DasSv1Bstack[2]  = 0x03;

	DasSv1Pstack[3]  = (unsigned char *) uptr;
	DasSv1Wstack[3]  = ulen;
	DasSv1Bstack[3]  = 0x03;

	DasSv1Pstack[4]  = (unsigned char *) wptr;
	DasSv1Wstack[4]  = wlen;
	DasSv1Bstack[4]  = 0x03;


	return( DasSv1Connect( _DASSV1_DLL_CONNECT, 5 ) );
}

unsigned short int DasDisconnect(char * buffer)			
{

	DasSv1Pstack[0]  = (unsigned char *) buffer;
	DasSv1Wstack[0]  = 1;
	DasSv1Bstack[0]  = 0x00;

	return( DasSv1Connect( _DASSV1_DLL_DISCONNECT, 1 ) );

}

unsigned short int DasGetProfile(char * pname, char * pbuffer, int pblen )
{
	*pbuffer = 0;
	putabalword( (pbuffer+1), (len -3));

	DasSv1Pstack[0]  = (unsigned char *) pname;
	DasSv1Wstack[0]  = namelen;
	DasSv1Bstack[0]  = 0x03;

	DasSv1Pstack[1]  = (unsigned char *) (pbuffer + 3);
	DasSv1Wstack[1]  = (len-3);
	DasSv1Bstack[1]  = 0x083;

	DasSv1Pstack[2]  = (unsigned char *) (pbuffer+1);
	DasSv1Wstack[2]  = 2;
	DasSv1Bstack[2]  = 0x081;

	DasSv1Pstack[3]  = (unsigned char *) pbuffer;
	DasSv1Wstack[3]  = 1;
	DasSv1Bstack[3]  = 0x080;

	return( DasSv1Connect( _DASSV1_DLL_GETPROFILE, 4 ) );

}

unsigned short int DasSetProfile(char * pname, int namelen, char * pbuffer, int len )
{
	if ( DasInitialise() != 0 )
		return( -1);

	else	{

		putabalword( (pbuffer+1), (len -2));

		DasSv1Pstack[0]  = (unsigned char *) pname;
		DasSv1Wstack[0]  = namelen;
		DasSv1Bstack[0]  = 0x03;

		DasSv1Pstack[1]  = (unsigned char *) (pbuffer + 2);
		DasSv1Wstack[1]  = (len-3);
		DasSv1Bstack[1]  = 0x083;

		DasSv1Pstack[2]  = (unsigned char *) pbuffer;
		DasSv1Wstack[2]  = 2;
		DasSv1Bstack[2]  = 0x081;

		return( DasSv1Connect( _DASSV1_DLL_SETPROFILE, 3 ) );
		}

}

unsigned short int DasDelProfile(char * pname, int namelen )
{
	if ( DasInitialise() != 0 )
		return( -1);

	else	{
		DasSv1Pstack[0]  = (unsigned char *) pname;
		DasSv1Wstack[0]  = namelen;
		DasSv1Bstack[0]  = 0x03;
		return( DasSv1Connect( _DASSV1_DLL_DELPROFILE, 1 ) );
		}

}

unsigned short int DasGetLineStatus( char * buffer  )
{
	if ( DasInitialise() != 0 ) 
		return( -1);

	else	{

		*(buffer+1) = 0; *(buffer+2) = 0;

		DasSv1Pstack[0]  = (unsigned char *) buffer;
		DasSv1Wstack[0]  = 1;
		DasSv1Bstack[0]  = 0x00;

		DasSv1Pstack[1]  = (unsigned char *) (buffer+1);
		DasSv1Wstack[1]  = 2;
		DasSv1Bstack[1]  = 0x81;

		return( DasSv1Connect( _DASSV1_DLL_GETSTATUS, 2 ) );
		}

}

unsigned short int DasGetPPPPhase( char * buffer  )
{
	if ( DasInitialise() != 0 ) 
		return( -1);
	else	{

		*(buffer+1) = 0; *(buffer+2) = 0;

		DasSv1Pstack[0]  = (unsigned char *) buffer;
		DasSv1Wstack[0]  = 1;
		DasSv1Bstack[0]  = 0x00;

		DasSv1Pstack[1]  = (unsigned char *) (buffer+1);
		DasSv1Wstack[1]  = 2;
		DasSv1Bstack[1]  = 0x81;

		return( DasSv1Connect( _DASSV1_DLL_GETPHASE, 2 ) );

		}

}


#endif	// _DASSV1_C





