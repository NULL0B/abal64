#ifndef	_GLOBAL_C
#define	_GLOBAL_C

/*
 *	This Object contains all global functions and data which 
 *	cannot be classified in any other way but as global to all
 *
 */

#include "basic.h"
#include "address.h"
#include "global.h"

PRIVATE	BYTE  	SocketNameBuffer[64];

#if defined(UNIX) || defined(WIN32) /*FCH*/
PUBLIC	INT	prologue_version()	{	return(0x0601); 	}
#endif

PUBLIC	INT	integer_option( aptr )
	BPTR	aptr;
{
	INT	v=0;
	if (( *aptr == 0 ) || ( *aptr == ' ' ))
		return(1);
	else 	{
		while ((*aptr) && ( *aptr >= '0' ) && ( *aptr <= '9' )) {
			v *= 10;
			v += (*(aptr++) - '0');
			}	
		return( v );
		}
}


PUBLIC	VOID	set_global_verbose( aptr )
	BPTR	aptr;
{
	verbose = integer_option( aptr );
	return;
}

PUBLIC	VOID	set_global_debug( aptr )
	BPTR	aptr;
{
	debug   = integer_option( aptr );
	set_global_verbose( aptr );
	return;
}

PUBLIC	INT	wildcomp( tptr , wptr )
BPTR	tptr;
BPTR	wptr;
{
	INT	wlen,tlen;

	wlen = strlen(wptr); tlen = strlen(tptr);

	while (( tlen > 0 ) && (wlen > 0)) {

		switch ( *wptr ) {
			case '*': 
				if (!( wildcomp( tptr , (wptr + 1)) ))
					return(0);
				else	{
					tptr++; 
					tlen--;
					continue;
					}

			default  : 
				if ( *tptr != *wptr )
					return(1);

			case '?' : 
				wptr++; tptr++; wlen--; tlen--; 
				continue;

			}
		}
	if (( tlen == 0 ) && ( wlen == 0 ))
		return(0);

	if ( tlen == 0 ) {
		while ( wlen > 0 ) {
			if (( *wptr != '*' ) && ( *wptr != '?' ))
				return(1);
			wlen--; wptr++;
			}
		return(0);
		}
	if (( wlen == 0 ) && ( *(wptr - 1) == '*'))
		return(0);
	else	return(1);
}

PUBLIC	INT	compare_tokens( aptr, bptr )
	BPTR	aptr;
	BPTR	bptr;
{

	while (1) {
		if ( *aptr ) {
			if ( *bptr ) {
				if ( *(aptr++) != *(bptr++) )
					return(0);
				}
			else	return( 0 );
			}
		else if ( *bptr )
			return(0);
		else	return(1);
		}
}


PUBLIC	VPTR	liberate_zone( vptr )
VPTR	vptr;
{
	if ( vptr != (VPTR) 0) {
		liberate( vptr );
		vptr = (VPTR) 0;
		}
	return( vptr );
}

PUBLIC	VPTR	allocate_zone( n )
INT	n;
{
	VPTR	vptr=(VPTR) 0;
	return((vptr = (VPTR) allocate( n )));
}

PUBLIC	BPTR 	socketname( sptr )
ADDRPTR 	sptr;
{
	BPTR aptr = (BPTR) & sptr->sin_addr;
	sprintf(SocketNameBuffer,"%u.%u.%u.%u:%u",
			( *(aptr + 0) & 0x00FF),
			( *(aptr + 1) & 0x00FF),
			( *(aptr + 2) & 0x00FF),
			( *(aptr + 3) & 0x00FF),
			ntohs(sptr->sin_port));
	return( (BPTR) SocketNameBuffer);
}

PUBLIC	BPTR	allocate_for_string( sptr )
	BPTR	sptr;
{
	BPTR	rptr=(BPTR) 0;
	if (( sptr != (BPTR) 0)
	&&  ((rptr = (BPTR) allocate_zone( (strlen(sptr) + 1) )) != (BPTR) 0)) {
		strcpy(rptr,sptr);
		}
	return( rptr );
}

PUBLIC 	INT	TryHostByName( nptr, aptr )
	BPTR	nptr;
	ADDRPTR	aptr;
{
	struct  hostent PTR hp=(struct hostent PTR) 0;

	/* ------------------------- */
	/* G E T H O S T B Y N A M E */
	/* ------------------------- */
     	if ((hp = gethostbyname(nptr)) == (struct hostent PTR) 0)
		return(1);
	else	{
		memcpy((BPTR) &aptr->sin_addr,(BPTR)hp->h_addr_list[0],hp->h_length);
		return(0);
		}
}

PUBLIC	VOID	show_global_usage()
{
	printf("         [ -v<level>          ] : Activate Information Messages \n");
	printf("         [ -d<level>          ] : Activate Debug Level Messages \n");
	return;
}


PRIVATE	BYTE	SystemName[32];

PRIVATE	BYTE	UserAgentName[64];

PUBLIC	BPTR 	HostSystemName()
{
	WORD	v;
	switch (((v = prologue_version()) & 0xFF00)>>8) {
#if defined(UNIX)
		case	6 :
			sprintf(SystemName,"UseIt/Twin32/%u.%u",((v>>8)-5),(v & 0x00FF));
			break;
#elif defined(WIN32)
		case	6 :
			sprintf(SystemName,"Windows/Wexa/%u.%u",((v>>8)-5),(v & 0x00FF));
			break;
#endif
		case	5 :
			if (( v & 0x00FF) > 1) {
				sprintf(SystemName,"TwinServer%u.%u",(v>>8),(v &0x00FF)); 
				break;
				}
		case	0 :
		case	1 :
		case	2 :
		case	3 :
		case	4 :
			sprintf(SystemName,"Amenesik / Sologic%u.%u",(v>>8),(v &0x00FF)); break;
		}
	return( SystemName );
}

PUBLIC	BPTR	GetUserAgent()	{ return( UserAgentName ); }

PUBLIC	VOID	SetUserAgent( nptr )
	BPTR	nptr;
{
	sprintf(UserAgentName,"%s(%s)",nptr,HostSystemName());
	return;
}

#endif	/* _GLOBAL_C */
	/* --------- */







