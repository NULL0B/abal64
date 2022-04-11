#ifndef	_HTTPABAL_C
#define	_HTTPABAL_C

#include "httpabal.h"
#include "httpfunc.h"

#ifdef WIN32
#include "bdanetapi.h"
#endif

#ifndef	EXAWORD
#ifdef	VERSION666
#ifdef	ABAL64
#define	EXAWORD unsigned long long
#else
#define	EXAWORD unsigned long
#endif
#else 
#define	EXAWORD unsigned short
#endif
#endif

extern VOID PTR allocate_zone( INT );
extern VOID PTR liberate_zone( VOID PTR );

#ifndef WIN32
static  char	VersionStatus[16]=
{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
static	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','d','0','0','3',0 };

static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[10];

static	char *	Provisoire="\n   Provisoire du %s ";
#endif

extern	int	verbose;

PRIVATE	int	v_putch_handle=0;

extern	int	use_protection( int );

PUBLIC	void	set_v_putch(int v)
{
	if ( v != -1 )
		v_putch_handle=(v+1);
	else	v_putch_handle= 0;
	return;
}

#ifndef WIN32
char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = '.';
			LaVersion[7] = LaPaterne[16];
			LaVersion[8] = LaPaterne[17];
			LaVersion[9] = 0;
			}
		else if ( LaPaterne[15] > '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
			}
		else	LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

void	abalhttp_banner()
{
	printf("\n   Hyper Text Transfer Protocol: Version %s ",getpatternversion());
	if ( VersionStatus[15] == '2' )
		printf(Provisoire,__HTTPABAL_DATE);
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	return;
}
#endif

EXAWORD	DllFailure(WORD e)
{
	return( HttpFailure( e ) );
}

EXAWORD	DllHttpError()
{
	return( HttpError() );
}

EXAWORD	DllHttpVersion()
{
	return( HttpVersion() );
}

/*
 *	Stub FAR Functions
 *	------------------
 *	These functions fall into two categories :
 *
 *	1) 	Functions which do not receive far pointer parameters
 *		These functions simply call the HTTP Equivalent Function
 *
 *	1) 	Functions which receive far pointer parameters !!!
 *		These functions must create near pointer equivalents
 *		prior to calling the HTTP Equivalent Function and must 
 *		release the memory afterwards (what a waste of TIME)
 *
 */

EXAWORD	HttpInitialised=0;

EXAWORD	FAR		DllHttpInitialise(pptr,plen)
	BYTE FAR PTR	pptr;
	EXAWORD		plen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (plen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < plen; i++ )
			*(lptr +i) = *(pptr)++;
		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpInitialise(%s,%u)\r\n",lptr,plen );
		if ( HttpInitialised ) 
			i = HttpConfigure( lptr, plen );
		else if (!( use_protection(1) ))
			i = HttpInitialise( lptr, plen );
		else	i = HttpFailure(221);
		HttpInitialised++;
		lptr = liberate_zone( lptr );
		return( i );
		}
}

EXAWORD	FAR		DllHttpConfigure(pptr,plen)
	BYTE FAR PTR	pptr;
	EXAWORD		plen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (plen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < plen; i++ )
			*(lptr +i) = *(pptr)++;
		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpConfigure(%s,%u)\r\n",lptr,plen );
		i = HttpConfigure( lptr, plen );
		lptr = liberate_zone( lptr );
		return( i );
		}
}

EXAWORD	FAR	DllHttpLiberate()
{
	if ( verbose & 1 )
		printf("DllHttpLiberate()\r\n");
	if (!( HttpInitialised ))
		return(0);
	else	HttpInitialised--;
	if (!( HttpInitialised )) {
		use_protection(0);
		return(HttpLiberate());
		}
	else	return(0);
}

static	void	bdanetenduser()
{
	DllHttpLiberate();
	return;
}

EXAWORD	FAR	DllHttpOpenServer(port,nature)
	EXAWORD	port;
	EXAWORD	nature;
{
	if ( verbose & 1 )
		printf("DllHttpOpenServer(%u,%u)\r\n",port,nature);
	return(HttpOpenServer(port,nature));
}

EXAWORD	FAR	DllHttpClose(handle,mode)
	EXAWORD	handle;
	EXAWORD	mode;
{
	if ( verbose & 1 )
		printf("DllHttpClose(%u,%u)\r\n",handle,mode);
	return(HttpClose(handle,mode));
}

EXAWORD	FAR	DllHttpAccept(handle,timeout)
	EXAWORD	handle;
	EXAWORD	timeout;
{
	if ( verbose & 1 )
		printf("DllHttpAccept(%u,%u)\r\n",handle,timeout);
	return(HttpAccept(handle,timeout));
}

EXAWORD	FAR		DllHttpSetHost(handle,cptr,clen)
	EXAWORD		handle;
	BYTE FAR PTR	cptr;
	EXAWORD		clen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (clen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < clen; i++ )
			*(lptr +i) = *(cptr)++;
		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpSetHost(%u,%s,%u)\r\n",handle,lptr,clen );
		i    = HttpSetHost( handle, lptr );
		lptr = liberate_zone( lptr );
		return( i );
		}
}

EXAWORD	FAR		DllHttpSetHeader(handle,cptr,clen)
	EXAWORD		handle;
	BYTE FAR PTR	cptr;
	EXAWORD		clen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (clen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < clen; i++ )
			*(lptr +i) = *(cptr)++;
		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpSetHeader(%u,%s,%u)\r\n",handle,lptr,clen );
		printf("DllHttpSetHeader(%u,%s)\r\n",handle,lptr);
		i    = HttpSetHeader( handle, lptr );
		lptr = liberate_zone( lptr );
		return( i );
		}
}

EXAWORD	FAR		DllHttpPost(handle,cptr,clen)
	EXAWORD		handle;
	BYTE FAR PTR	cptr;
	EXAWORD		clen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (clen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < clen; i++ )
			*(lptr +i) = *(cptr)++;
		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpPost(%u,%s,%u)\r\n",handle,lptr,clen );
		i    = HttpPost( handle, lptr );
		lptr = liberate_zone( lptr );
		return( i );
		}
}

EXAWORD	FAR		DllHttpSetType(cptr,clen)
	BYTE FAR PTR	cptr;
	EXAWORD		clen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (clen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < clen; i++ )
			*(lptr +i) = *(cptr)++;
		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpSetType(%s,%u)\r\n",lptr,clen );
		i    = HttpSetType( lptr );
		lptr = liberate_zone( lptr );
		return( i );
		}
}

EXAWORD	FAR	DllHttpContentLength(handle,cptr,clen)
	EXAWORD		handle;
	BYTE FAR PTR	cptr;
	EXAWORD		clen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (clen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < clen; i++ )
			*(lptr +i) = *(cptr)++;
		*(lptr +i) = 0;
		HttpContentLength(handle,lptr);
		lptr = liberate_zone( lptr );
		return( i );
		}
}

EXAWORD	FAR		DllHttpCommand(handle,cptr,clen)
	EXAWORD		handle;
	BYTE FAR PTR	cptr;
	EXAWORD		clen;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (clen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < clen; i++ )
			*(lptr +i) = *(cptr)++;
		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpCommand(%u,%s,%u)\r\n",handle,lptr,clen );
		i    = HttpCommand( handle, lptr );
		lptr = liberate_zone( lptr );
		return( i );
		}
}


EXAWORD	FAR		DllHttpOpenClient(nptr,nlen,nature)
	BYTE FAR PTR	nptr;
	EXAWORD		nlen;
	EXAWORD		nature;
{
	BYTE PTR	lptr=(BYTE PTR) 0;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( (nlen+1) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < nlen; i++ )
			*(lptr +i) = *(nptr)++;

		*(lptr +i) = 0;
		if ( verbose & 1 )
			printf("DllHttpOpenClient(%s,%u,%u)\r\n",lptr,nlen,nature );
		i = HttpOpenClient( lptr, nlen, nature );
		lptr = liberate_zone( lptr );
		return(i);
		}
}

EXAWORD	FAR	DllHttpGet( handle, bptr, blen )
	EXAWORD		handle;
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	EXAWORD		e;
#ifdef	PROLOGUE
	BYTE PTR	lptr;
	EXAWORD		i;

	if ((lptr = (BYTE PTR) allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 )
			printf("DllHttpGet(%u,%u)\r\n",handle,blen);
		e = HttpGet(handle, lptr, blen );
		for ( i= 0; i < blen; i++ )
			*(bptr++) = *(lptr +i);
		lptr = liberate_zone( lptr );
		return( e );
		}
#else
	if ( verbose & 1 )
		printf("DllHttpGet(%u,%u)\r\n",handle,blen);
	return((e = HttpGet(handle, bptr, blen )));
#endif
}

EXAWORD	FAR	DllHttpCrypt( handle, bptr, blen, mode )
	EXAWORD		handle;
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
	EXAWORD		mode;
{
	BYTE PTR	lptr;
	EXAWORD		i,e;

	if ((lptr = (BYTE PTR) allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < blen; i++ )
			*(lptr+i) = *(bptr++);
		e = HttpCryptage(handle, lptr, blen, mode );
		lptr = liberate_zone( lptr );
		return( e );
		}
}

EXAWORD	FAR		DllHttpPut( handle, bptr, blen )
	EXAWORD		handle;
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	EXAWORD		e;
#ifdef	PROLOGUE
	BYTE PTR	lptr;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 )
			printf("DllHttpPut(%u,%u)\r\n",handle,blen );
		for ( i= 0; i < blen; i++ )
			*(lptr+i) = *(bptr++);
		e = HttpPut(handle, lptr, blen );
		lptr = liberate_zone( lptr );
		return( e );
		}
	return(0);
#else
	if ( verbose & 1 )
		printf("DllHttpPut(%u,%u)\r\n",handle,blen );
	return((e = HttpPut(handle, bptr, blen )));
#endif
}

EXAWORD	FAR		DllHttpPutFile( handle, nptr, nlen, mode )
	EXAWORD		handle;
	BYTE FAR PTR 	nptr;
	EXAWORD		nlen;
	EXAWORD		mode;
{
	BYTE PTR	lptr;
	EXAWORD		i,e;

	if ((lptr = (BYTE PTR) allocate_zone( nlen+1 )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < nlen; i++ )
			*(lptr+i) = *(nptr++);
		*(lptr+i) = 0;
		if ( verbose & 1 )
			printf("DllHttpPutFile(%u,%s,%u)\r\n",handle,lptr,mode );
		e = HttpPutFile(handle, lptr, nlen, mode );
		lptr = liberate_zone( lptr );
		return( e );
		}
	return(0);
}

EXAWORD	FAR		DllHttpFileSize(
	BYTE FAR PTR	nptr,
	EXAWORD		nlen,
	EXAWORD		mode,
	BYTE FAR PTR 	result
	)
{
	BYTE PTR	lptr;
	EXAWORD		i,e;
	unsigned long	filesize=0L;

	if ((lptr = (BYTE PTR) allocate_zone( nlen+1 )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < nlen; i++ )
			*(lptr+i) = *(nptr++);
		*(lptr+i) = 0;
		if ((filesize = HttpFileSize(lptr, nlen, mode )) != 0xFFFFFFFF) {
			*(result++) = (char)((filesize & 0xFF000000) >> 24);
			*(result++) = (char)((filesize & 0x00FF0000) >> 16);
			*(result++) = (char)((filesize & 0x0000FF00) >> 8);
			*(result++) = (char)(filesize & 0x000000FF);
			e = 0;
			}
		else	{
			*(result++) = 0;
			*(result++) = 0;
			*(result++) = 0;
			*(result++) = 0;
			e = 40;
			}
		lptr = liberate_zone( lptr );
		return( e );
		}
	return(0);
}

EXAWORD	FAR		DllHttpGetFile( handle, nptr, nlen, lobytes, hibytes )
	EXAWORD		handle;
	BYTE FAR PTR 	nptr;
	EXAWORD		nlen;
	EXAWORD		lobytes;
	EXAWORD		hibytes;
{
	BYTE PTR	lptr;
	EXAWORD		i,e;

	unsigned long	bytes;

	if ( hibytes )
		bytes = (((unsigned long)lobytes) | (((unsigned long) hibytes) << 16 ));
	else	bytes = lobytes;


	if ((lptr = (BYTE PTR) allocate_zone( nlen+1 )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		for ( i= 0; i < nlen; i++ )
			*(lptr+i) = *(nptr++);
		*(lptr+i) = 0;
		if ( verbose & 1 )
			printf("DllHttpGetFile(%u,%s,%lu)\r\n",handle,lptr,bytes );
		e = HttpGetFile(handle, lptr, nlen, bytes );
		lptr = liberate_zone( lptr );
		return( e );
		}
	return(0);
}

EXAWORD	FAR		DllHttpResponse( handle, response, bptr, blen )
	EXAWORD		handle;
	EXAWORD		response;
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	EXAWORD		e;
#ifdef	PROLOGUE
	BYTE PTR	lptr;
	EXAWORD		i;
	if ((lptr = (BYTE PTR) allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 ) 
			printf("HttpPutResponse(%u,%u,%u)\r\n",handle,response,blen);
		for ( i= 0; i < blen; i++ )
			*(lptr+i) = *(bptr++);
		e = HttpPutResponse(handle,response, lptr, blen );
		lptr = liberate_zone( lptr );
		return( e );
		}
	return(0);
#else
	if ( verbose & 1 ) 
		printf("HttpPutResponse(%u,%u,%u)\r\n",handle,response,blen);
	return((e = HttpPutResponse(handle,response, bptr, blen )));
#endif
}

EXAWORD	FAR	DllHttpKeepAlive( handle, status )
	EXAWORD		handle;
	EXAWORD		status;
{
	return( HttpKeepAlive(handle, status) );
}

EXAWORD	FAR	DllHttpAddress( handle, bptr, blen )
	EXAWORD		handle;
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	EXAWORD		e;
#ifdef	PROLOGUE
	BYTE PTR	lptr;
	EXAWORD		i;
	if ((lptr = allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 ) 
			printf("HttpGetAddress(%u)\r\n",handle);
		e = HttpGetAddress(handle, lptr, blen );
		for ( i= 0; i < blen; i++ )
			*(bptr++) = *(lptr +i);
		lptr = liberate_zone( lptr );
		return( e );
		}
#else
	if ( verbose & 1 ) 
		printf("HttpGetAddress(%u)\r\n",handle);
	return((e = HttpGetAddress(handle, bptr, blen )));
#endif
}

EXAWORD	FAR	DllHttpLoadTable(  bptr, blen )
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	EXAWORD		e;
#ifdef	PROLOGUE
	BYTE PTR	lptr;
	EXAWORD		i;
	if ((lptr = allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 ) 
			printf("HttpLoadTable()\r\n");
		for ( i= 0; i < blen; i++ )
			*(lptr+i) = *(bptr+i);
		e = HttpLoadTable( lptr, blen );
		lptr = liberate_zone( lptr );
		return( e );
		}
#else
	if ( verbose & 1 ) 
		printf("HttpLoadTable()\r\n");
	return((e = HttpLoadTable( bptr, blen )));
#endif
}

EXAWORD	FAR	DllHttpReadTable(  bptr, blen )
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	EXAWORD		e;
#ifdef	PROLOGUE
	BYTE PTR	lptr;
	EXAWORD		i;
	if ((lptr = allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 ) 
			printf("HttpReadTable()\r\n");
		e = HttpReadTable( lptr, blen );
		for ( i= 0; i < blen; i++ )
			*(bptr+i) = *(lptr+i);
		lptr = liberate_zone( lptr );
		return( e );
		}
#else
	if ( verbose & 1 ) 
		printf("HttpReadTable()\r\n");
	return((e = HttpReadTable( bptr, blen )));
#endif
}



EXAWORD	FAR	DllHttpGetLine( handle, bptr, blen )
	EXAWORD		handle;
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	EXAWORD		e;
#ifdef	PROLOGUE
	EXAWORD		i;
	BYTE PTR	lptr;
	if ((lptr = allocate_zone( blen )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 )
			printf("DllHttpGetLine(%u,%u)\r\n",handle,blen);
		e = HttpGetLine(handle, lptr, blen );
		for ( i= 0; i < blen; i++ ) {
			*(bptr++) = *(lptr +i);
			}
		lptr = liberate_zone( lptr );
		return( e );
		}
#else
	if ( verbose & 1 )
		printf("DllHttpGetLine(%u,%u)\r\n",handle,blen);
	return(( e = HttpGetLine(handle, bptr, blen )));
#endif

}

EXAWORD	FAR	DllHttpPutLine( handle, bptr, blen )
	EXAWORD		handle;
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	BYTE PTR	lptr;
	EXAWORD		i,e;

	if ((lptr = (BYTE PTR) allocate_zone( (blen+3) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );
	else	{
		if ( verbose & 1 )
			printf("DllHttpPutLine(%u,%u)\r\n",handle,blen);
		for ( i= 0; i < blen; i++ )
			*(lptr+i) = *(bptr++);
		*(lptr + i) = '\r'; i++;
		*(lptr + i) = '\n'; i++;
		*(lptr + i) = '0';
		e = HttpPutLine(handle, lptr, (blen+2) );
		lptr = liberate_zone( lptr );
		return( e );
		}
	return(0);
}

EXAWORD	FAR	DllHttpAuthorise( bptr, blen )
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	BYTE PTR	lptr;
	EXAWORD		i,e;

	if ((lptr = (BYTE PTR) allocate_zone( (blen+3) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );

	else	{

		for ( i= 0; i < blen; i++ )
			*(lptr+i) = *(bptr++);

		*(lptr + i) = 0;
		(void) HttpSetAuthorize( lptr );
		lptr = liberate_zone( lptr );
		return( 0 );

		}
	return(0);
}

EXAWORD	FAR	DllHttpProxyAuthorise( bptr, blen )
	BYTE FAR PTR 	bptr;
	EXAWORD		blen;
{
	BYTE PTR	lptr;
	EXAWORD		i,e;

	if ((lptr = (BYTE PTR) allocate_zone( (blen+3) )) == (BYTE PTR) 0)
		return( HttpFailure(27) );

	else	{

		for ( i= 0; i < blen; i++ )
			*(lptr+i) = *(bptr++);

		*(lptr + i) = 0;
		(void) HttpProxyAuthorize( lptr );
		lptr = liberate_zone( lptr );
		return( 0 );

		}
	return(0);
}


EXAWORD	FAR	DllHttpSetConversion( mode )
	EXAWORD	mode;
{
	HttpSetConversion( mode );
	return 0;
}

EXAWORD	FAR	DllHttpSelect( handle, timeout )
	EXAWORD	handle;
	EXAWORD	timeout;
{
	if ( verbose & 1 )
		printf("DllHttpSelect(%u,%u)\r\n",handle,timeout);
	return( HttpSelect( handle, timeout ) );
}

EXAWORD	FAR	DllHttpTranscode( value )
	EXAWORD	value;
{
	return( HttpTranscode( value ) );
}

#include "decode64.c"

EXAWORD	FAR	DllHttpDecodeBase64(rptr,sptr,l)
	BYTE FAR PTR	rptr;
	BYTE FAR PTR	sptr;
	EXAWORD		l;
{
	return( DecodeBase64( rptr, sptr, l ) );
}

#include "encode64.c"

EXAWORD	FAR	DllHttpEncodeBase64(rptr,sptr,i)
	BYTE FAR PTR	rptr;
	BYTE FAR PTR	sptr;
	EXAWORD		i;
{
	return( EncodeBase64( rptr, sptr, i ) );
}

EXAWORD	FAR	DllHttpDuplicate(h)
	EXAWORD	h;
{
	return(HttpDuplicate(h));
}

EXAWORD	FAR	DllHttpSecurity(mode,kptr,cptr,aptr,pptr)
	EXAWORD		mode;
	BYTE FAR PTR	kptr;
	BYTE FAR PTR	cptr;
	BYTE FAR PTR	aptr;
	BYTE FAR PTR	pptr;
{
	return(HttpSecurity(mode,kptr,cptr,aptr,pptr));
}
#ifdef	UNIX

/*	--------------------------------------		*/
/*	Elements of the CICO Access Controller		*/
/*	--------------------------------------		*/

PRIVATE	struct	cico_access_controller	{

	EXAWORD   FunctionCount;
	EXAWORD  (*FunctionRelay[CICO_NOMBRE])();

	} CicoAccessController;


/*	--------------------------------------		*/
/*	Access Controller Basic Initialisation		*/
/*	--------------------------------------		*/

PRIVATE	void	initialise_access_controller()
{
	CicoAccessController.FunctionCount = CICO_NOMBRE;

	CicoAccessController.FunctionRelay[CICO_CI] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_TPCI]	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_PRFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LCFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CONF] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MES] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LIGNE] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_COLONNE]= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_START] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_FLUSH] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MIMA] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_EVENT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_INIT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_GRAPH] 	= (void *) 0;
  	return;
}

/*	-------------------------------------------------	*/
/* 	This function is provided to  perform redirection	*/
/*	--------------------------------------------------	*/

PRIVATE	void *	redirect_access_controller( int	item,  void *	fptr )
{
	void	*	vptr=(void *) 0;
	if ((item >= 0) && ( item < CicoAccessController.FunctionCount )) {
		if ( fptr ) {
			vptr = CicoAccessController.FunctionRelay[item]; 	
			CicoAccessController.FunctionRelay[item] = fptr;
	 		}
 		}
	return( vptr );
}

PRIVATE	void  	connect_access_controller( BDA_INIT * iptr, void * eptr, struct cico_access_controller * cptr )
{
	int	i;
	void *	vptr;
	
	if (!( iptr ))
		return;

	for (i=0; i < CICO_NOMBRE; i++ ) {
		vptr = iptr->cico.fonction[i];
		if ( i != CICO_INIT )
			CicoAccessController.FunctionRelay[i] = vptr;
		}
	return;
}

PRIVATE	EXAWORD	v_putch(EXAWORD i)
{
	if (!( v_putch_handle ))
		return( (CicoAccessController.FunctionRelay[CICO_CO])(i) );
	else	{
		return( HttpPutByte((v_putch_handle-1), i) );
		}
}

#endif /* UNIX */



#ifndef PRLNET_EXPORTS /*** FCH: Version DLL code inutilisé ***/


#if defined(WIN32)

void x_previous_putch( EXAWORD car );

PUBLIC	EXAWORD	v_putch(EXAWORD i)
{
if (!( v_putch_handle ))
	{
	x_previous_putch( i );
	return( HttpSuccess());	
	}
else
	return( HttpPutByte((v_putch_handle-1), i) );
}
#endif


/* ------------------ */
/* DLL initialisation */
/* ------------------ */
VOID FAR PTR InitRelais()
{ 
#if defined(UNIX)
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_REDIRECT;
#elif defined(WIN32)
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_CICO;
#else
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;
#endif

	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) bdanetenduser;

	desrt.nombre = _BDANET_DLL_FUNCTION;

#ifdef vms

	desrt.nom[0] = (BYTE FAR PTR) "_HttpInitialise";
	desrt.nom[1] = (BYTE FAR PTR) "_HttpLiberate";
	desrt.nom[2] = (BYTE FAR PTR) "_HttpOpenServer";
	desrt.nom[3] = (BYTE FAR PTR) "_HttpOpenClient";
	desrt.nom[4] = (BYTE FAR PTR) "_HttpClose";
	desrt.nom[5] = (BYTE FAR PTR) "_HttpAccept";
	desrt.nom[6] = (BYTE FAR PTR) "_HttpCommand";
	desrt.nom[7] = (BYTE FAR PTR) "_HttpGet";
	desrt.nom[8] = (BYTE FAR PTR) "_HttpPut";
	desrt.nom[9] = (BYTE FAR PTR) "_HttpGetLine";
	desrt.nom[10] = (BYTE FAR PTR) "_HttpPutLine";
	desrt.nom[11] = (BYTE FAR PTR) "_HttpAddress";
	desrt.nom[12] = (BYTE FAR PTR) "_HttpSetConversion";
	desrt.nom[13] = (BYTE FAR PTR) "_HttpTranscode";
	desrt.nom[14] = (BYTE FAR PTR) "_HttpSetHost";
	desrt.nom[15] = (BYTE FAR PTR) "_HttpSetType";
	desrt.nom[16] = (BYTE FAR PTR) "_HttpPost";
	desrt.nom[17] = (BYTE FAR PTR) "_HttpKeepAlive";
	desrt.nom[18] = (BYTE FAR PTR) "_HttpAuthorise";
	desrt.nom[19] = (BYTE FAR PTR) "_HttpProxyAuthorise";
	desrt.nom[20] = (BYTE FAR PTR) "_HttpCrypt";
	desrt.nom[21] = (BYTE FAR PTR) "_HttpError";
	desrt.nom[22] = (BYTE FAR PTR) "_HttpVersion";
	desrt.nom[23] = (BYTE FAR PTR) "_HttpEncodeBase64";
	desrt.nom[24] = (BYTE FAR PTR) "_HttpDecodeBase64";
	desrt.nom[25] = (BYTE FAR PTR) "_HttpResponse";
	desrt.nom[26] = (BYTE FAR PTR) "_HttpFile";
	desrt.nom[27] = (BYTE FAR PTR) "_HttpSelect";
	desrt.nom[28] = (BYTE FAR PTR) "_HttpConfigure";
	desrt.nom[29] = (BYTE FAR PTR) "_HttpLoadTable";
	desrt.nom[30] = (BYTE FAR PTR) "_HttpReadTable";
	desrt.nom[31] = (BYTE FAR PTR) "_HttpGetFile";
	desrt.nom[32] = (BYTE FAR PTR) "_HttpFileSize";
	desrt.nom[33] = (BYTE FAR PTR) "_HttpContentLengthSize";
	desrt.nom[34] = (BYTE FAR PTR) "_HttpSetHeader";
	desrt.nom[35] = (BYTE FAR PTR) "_HttpDuplicate";
	desrt.nom[36] = (BYTE FAR PTR) "_HttpSecurity";

	/* ----- */
#elif defined(UNIX) || defined(PROLOGUE)
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;
	desrt.fonction[0]  = (EXAWORD (FAR PTR)()) DllHttpInitialise;
	desrt.fonction[1]  = (EXAWORD (FAR PTR)()) DllHttpLiberate;
	desrt.fonction[2]  = (EXAWORD (FAR PTR)()) DllHttpOpenServer;
	desrt.fonction[3]  = (EXAWORD (FAR PTR)()) DllHttpOpenClient;
	desrt.fonction[4]  = (EXAWORD (FAR PTR)()) DllHttpClose;
	desrt.fonction[5]  = (EXAWORD (FAR PTR)()) DllHttpAccept;
	desrt.fonction[6]  = (EXAWORD (FAR PTR)()) DllHttpCommand;
	desrt.fonction[7]  = (EXAWORD (FAR PTR)()) DllHttpGet;
	desrt.fonction[8]  = (EXAWORD (FAR PTR)()) DllHttpPut;
	desrt.fonction[9]  = (EXAWORD (FAR PTR)()) DllHttpGetLine;
	desrt.fonction[10] = (EXAWORD (FAR PTR)()) DllHttpPutLine;
	desrt.fonction[11] = (EXAWORD (FAR PTR)()) DllHttpAddress;
	desrt.fonction[12] = (EXAWORD (FAR PTR)()) DllHttpSetConversion;
	desrt.fonction[13] = (EXAWORD (FAR PTR)()) DllHttpTranscode;
	desrt.fonction[14] = (EXAWORD (FAR PTR)()) DllHttpSetHost;
	desrt.fonction[15] = (EXAWORD (FAR PTR)()) DllHttpSetType;
	desrt.fonction[16] = (EXAWORD (FAR PTR)()) DllHttpPost;
	desrt.fonction[17] = (EXAWORD (FAR PTR)()) DllHttpKeepAlive;
	desrt.fonction[18] = (EXAWORD (FAR PTR)()) DllHttpAuthorise;
	desrt.fonction[19] = (EXAWORD (FAR PTR)()) DllHttpProxyAuthorise;
	desrt.fonction[20] = (EXAWORD (FAR PTR)()) DllHttpCrypt;
	desrt.fonction[21] = (EXAWORD (FAR PTR)()) DllHttpError;
	desrt.fonction[22] = (EXAWORD (FAR PTR)()) DllHttpVersion;
	desrt.fonction[23] = (EXAWORD (FAR PTR)()) DllHttpEncodeBase64;
	desrt.fonction[24] = (EXAWORD (FAR PTR)()) DllHttpDecodeBase64;
	desrt.fonction[25] = (EXAWORD (FAR PTR)()) DllHttpResponse;
	desrt.fonction[26] = (EXAWORD (FAR PTR)()) DllHttpPutFile;
	desrt.fonction[27] = (EXAWORD (FAR PTR)()) DllHttpSelect;
	desrt.fonction[28] = (EXAWORD (FAR PTR)()) DllHttpConfigure;
	desrt.fonction[29] = (EXAWORD (FAR PTR)()) DllHttpLoadTable;
	desrt.fonction[30] = (EXAWORD (FAR PTR)()) DllHttpReadTable;
	desrt.fonction[31] = (EXAWORD (FAR PTR)()) DllHttpGetFile;
	desrt.fonction[32] = (EXAWORD (FAR PTR)()) DllHttpFileSize;
	desrt.fonction[33] = (EXAWORD (FAR PTR)()) DllHttpContentLength;
	desrt.fonction[34] = (EXAWORD (FAR PTR)()) DllHttpSetHeader;
	desrt.fonction[35] = (EXAWORD (FAR PTR)()) DllHttpDuplicate;
	desrt.fonction[36] = (EXAWORD (FAR PTR)()) DllHttpSecurity;

#else

	desrt.reserve = (VOID FAR PTR) 0L;

	desrt.fonction[0]  = (EXAWORD (FAR PTR)()) _DllHttpInitialise;
	desrt.fonction[1]  = (EXAWORD (FAR PTR)()) _DllHttpLiberate;
	desrt.fonction[2]  = (EXAWORD (FAR PTR)()) _DllHttpOpenServer;
	desrt.fonction[3]  = (EXAWORD (FAR PTR)()) _DllHttpOpenClient;
	desrt.fonction[4]  = (EXAWORD (FAR PTR)()) _DllHttpClose;
	desrt.fonction[5]  = (EXAWORD (FAR PTR)()) _DllHttpAccept;
	desrt.fonction[6]  = (EXAWORD (FAR PTR)()) _DllHttpCommand;
	desrt.fonction[7]  = (EXAWORD (FAR PTR)()) _DllHttpGet;
	desrt.fonction[8]  = (EXAWORD (FAR PTR)()) _DllHttpPut;
	desrt.fonction[9]  = (EXAWORD (FAR PTR)()) _DllHttpGetLine;
	desrt.fonction[10] = (EXAWORD (FAR PTR)()) _DllHttpPutLine;
	desrt.fonction[11] = (EXAWORD (FAR PTR)()) _DllHttpAddress;
	desrt.fonction[12] = (EXAWORD (FAR PTR)()) _DllHttpSetConversion;
	desrt.fonction[13] = (EXAWORD (FAR PTR)()) _DllHttpTranscode;
	desrt.fonction[14] = (EXAWORD (FAR PTR)()) _DllHttpSetHost;
	desrt.fonction[15] = (EXAWORD (FAR PTR)()) _DllHttpSetType;
	desrt.fonction[16] = (EXAWORD (FAR PTR)()) _DllHttpPost;
	desrt.fonction[17] = (EXAWORD (FAR PTR)()) _DllHttpKeepAlive;
	desrt.fonction[18] = (EXAWORD (FAR PTR)()) _DllHttpAuthorise;
	desrt.fonction[19] = (EXAWORD (FAR PTR)()) _DllHttpProxyAuthorise;
	desrt.fonction[20] = (EXAWORD (FAR PTR)()) _DllHttpCrypt;
	desrt.fonction[21] = (EXAWORD (FAR PTR)()) _DllHttpError;
	desrt.fonction[22] = (EXAWORD (FAR PTR)()) _DllHttpVersion;
	desrt.fonction[23] = (EXAWORD (FAR PTR)()) _DllHttpEncodeBase64;
	desrt.fonction[24] = (EXAWORD (FAR PTR)()) _DllHttpDecodeBase64;
	desrt.fonction[25] = (EXAWORD (FAR PTR)()) _DllHttpResponse;
	desrt.fonction[26] = (EXAWORD (FAR PTR)()) _DllHttpPutFile;
	desrt.fonction[27] = (EXAWORD (FAR PTR)()) _DllHttpSelect;
	desrt.fonction[28] = (EXAWORD (FAR PTR)()) _DllHttpConfigure;
	desrt.fonction[29] = (EXAWORD (FAR PTR)()) _DllHttpLoadTable;
	desrt.fonction[30] = (EXAWORD (FAR PTR)()) _DllHttpReadTable;
	desrt.fonction[31] = (EXAWORD (FAR PTR)()) _DllHttpGetFile;
	desrt.fonction[32] = (EXAWORD (FAR PTR)()) _DllHttpFileSize;
	desrt.fonction[33] = (EXAWORD (FAR PTR)()) _DllHttpContentLength;
	desrt.fonction[34] = (EXAWORD (FAR PTR)()) _DllHttpSetHeader;
	desrt.fonction[35] = (EXAWORD (FAR PTR)()) _DllHttpDuplicate;
	desrt.fonction[36] = (EXAWORD (FAR PTR)()) _DllHttpSecurity;

#endif

#ifdef	UNIX
	desrt.fonction[_BDANET_DLL_FUNCTION+1]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+2]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+3]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+4]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+5]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+6]	= (EXAWORD (FAR PTR)()) v_putch;
	desrt.fonction[_BDANET_DLL_FUNCTION+7]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+8]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+9]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+10]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+11]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+12]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+13]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+14]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_BDANET_DLL_FUNCTION+15]	= connect_access_controller;
	desrt.fonction[_BDANET_DLL_FUNCTION+16]	= (EXAWORD (FAR PTR)()) 0;

	if (rt_init != (VOID FAR PTR) 0L) {
#ifdef	_VISUAL_ATB_MANAGER
		rt_init->cico.numero = (16384 | 32);
#else
		rt_init->cico.numero = 16384;
#endif
		rt_init->cico.fonction[CICO_CI]     = desrt.fonction[_BDANET_DLL_FUNCTION+1]; 
	 	rt_init->cico.fonction[CICO_TPCI]   = desrt.fonction[_BDANET_DLL_FUNCTION+2];
	  	rt_init->cico.fonction[CICO_PRFO]   = desrt.fonction[_BDANET_DLL_FUNCTION+3];  	
		rt_init->cico.fonction[CICO_LCFO]   = desrt.fonction[_BDANET_DLL_FUNCTION+4];  	
		rt_init->cico.fonction[CICO_CONF]   = desrt.fonction[_BDANET_DLL_FUNCTION+5]; 	
		rt_init->cico.fonction[CICO_CO]     = desrt.fonction[_BDANET_DLL_FUNCTION+6]; 	
		rt_init->cico.fonction[CICO_MES]    = desrt.fonction[_BDANET_DLL_FUNCTION+7]; 	
		rt_init->cico.fonction[CICO_LIGNE]  = desrt.fonction[_BDANET_DLL_FUNCTION+8]; 	
		rt_init->cico.fonction[CICO_COLONNE]= desrt.fonction[_BDANET_DLL_FUNCTION+9]; 	
		rt_init->cico.fonction[CICO_START]  = desrt.fonction[_BDANET_DLL_FUNCTION+10]; 	
		rt_init->cico.fonction[CICO_FLUSH]  = desrt.fonction[_BDANET_DLL_FUNCTION+11]; 	
		rt_init->cico.fonction[CICO_LO]     = desrt.fonction[_BDANET_DLL_FUNCTION+12]; 	
		rt_init->cico.fonction[CICO_MIMA]   = desrt.fonction[_BDANET_DLL_FUNCTION+13];   
		rt_init->cico.fonction[CICO_EVENT]  = desrt.fonction[_BDANET_DLL_FUNCTION+14];
		rt_init->cico.fonction[CICO_INIT]   = desrt.fonction[_BDANET_DLL_FUNCTION+15];
		rt_init->cico.fonction[CICO_GRAPH]  = desrt.fonction[_BDANET_DLL_FUNCTION+16];
		}
#endif

	return((VOID FAR PTR) &desrt);

}

/* ---------------------- */
/* Library identification */
/* ---------------------- */
static VOID FAR banniere()
{ 
#ifndef WIN32
	abalhttp_banner();
#endif
	return;
}

void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}


#endif  /*** FCH: Version DLL code inutilisé ***/

	/* ----------- */
#endif	/* _HTTPABAL_C */
	/* ----------- */



