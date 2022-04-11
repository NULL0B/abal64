#ifndef	_HTTPFUNC_C
#define	_HTTPFUNC_C

/*
 *	29/08/2001 IJM	Modification to allow a new initialisation parameter
 *			-Sinteger to allow a SELECT timeout to be specified
 *			and to be used by the GETLINE function.
 *			This has been introduced to allow applications to
 *			manage internet virus and worm atacks which connect
 *			but never do anything leaving the socket open for
 *			ever.
 *			The SELECT function will be called prior to each data
 *			read inside GETLINE. If the timeout is reached then
 *			the code 27 will be returned meaning escape.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "basic.h"

#ifndef	EXAWORD
#ifdef	VERSION666
#define	EXAWORD unsigned long
#else
#define	EXAWORD unsigned short
#endif
#endif


/* 
#ifdef	____FAR_DATA
#define	____DEBUG	1
#endif
*/

#include "address.h"
#include "global.h"
#include "url.h"
#include "http.h"
#include "httpssl.h"
#include "abalssl.h"

#define	MAX_CONNECTIONS 128

#define	_HTTP_ABAL_FAILURE 0xFFFF
#define	_HTTP_ABAL_SUCCESS 0

#include "iso.h"


PUBLIC	void	set_v_putch(int v); /* from httpabal.h */

#ifdef	_ANSI_ISO1_H
#define	GetSet Ansi2Twin
#define PutSet Twin2Ansi
#else
PRIVATE	BYTE	GetSet[256];
PRIVATE	BYTE	PutSet[256];
#endif

PRIVATE WORD	SelectTimer=0;
PRIVATE	WORD	TlsMode=5;
PRIVATE	WORD	TransCode=1;
PRIVATE	WORD	Optimised=1;
PRIVATE	WORD	HttpErrorValue=0;
PRIVATE	BYTE	ClientNameBuffer[MAX_NAME_LENGTH];
PRIVATE	BPTR	TransferBuffer=(BPTR) 0;
PRIVATE	WORD	TransferBufferLength=0;
CONNECTIONPTR	ConnectionTable[MAX_CONNECTIONS];

PRIVATE	WORD	IsProtected=0;

/* -------------------------------------------------- */
/* The function returns the value set by HttpSecurity */
/* -------------------------------------------------- */
PUBLIC	WORD	get_tls_mode()		{ return( TlsMode );	}

#ifdef	ABAL64
PUBLIC	int	use_protection(int mode) { return(0); }
/*      ----------------------------    */
/*      Version Demo : No Protection    */
/*      ----------------------------    */
/*       Product Limited Elsewhere      */
/*      ----------------------------    */
int     protConnect()           {       return(1);      }
int     protDisconnect()        {       return(0);      }
int     protLoadPgm( short i, char * v, short * n, int p, int * e )
{
        *e = 0;
        *n = 1;
        return(0);
}

int     protUnloadPgm( short i, char * v, short * n, int p, int * e )
{
        *e = 0;
        *n = 1;
        return(0);
}

#else
fuck off prologue
#include "protection.c"

PUBLIC	int	use_protection( int mode )
{
#ifdef	ABAL32X
	switch ( mode ) {
		case	1 :
			if (!( IsProtected )) { return( UseProtection( &IsProtected, 1 ) ); }
			else	break;
		case	0 :
			if (   IsProtected  ) { UseProtection(&IsProtected,0); }
			break;
		}
#endif
	return(0);
}

#include "blindage.c"
#endif

#include "cryptage.c"

PRIVATE	int	ConnectionNature( nature )
	WORD	nature;
{
	/* note : higher bitvalues indocate SSL */
	/* ------------------------------------ */
	switch (( nature & 0x0007)) {
		case	0 : return(  __URL_RAW 		);
		case	1 : return(  __URL_TCP 		);
		case	2 : return(  __URL_UDP 		);
		case	5 : return( nature /*FCH: ancienne valeur 5, mais on perdait les flags 8 et 16 */ );
		default	  : return( _HTTP_ABAL_FAILURE  );
		}
}


/*		-----------------------------------------		*/
/*									*/
/*		I N T E R F A C E 	F U N C T I O N S		*/
/*									*/
/*		-----------------------------------------		*/


/*	H t t p L o a d T a b l e ( buffer, length )			*/
/*	--------------------------------------------			*/

PUBLIC	int	HttpLoadTable( BPTR bptr, WORD blen )
{
	WORD	i;
	for ( i=0; i < 256; i++ ) {
		if ( i < blen )
			GetSet[i] = *(bptr+i);
		else	break;
		}
	for ( i=0; i < 256; i++ ) {
		if ( (i+256) < blen )
			PutSet[i] = *(bptr+i+256);
		else	break;
		}
	return(0);

}

/*	H t t p R e a d T a b l e ( buffer, length )			*/
/*	--------------------------------------------			*/

PUBLIC	int	HttpReadTable( BPTR bptr, WORD blen )
{
	WORD	i;
	for ( i=0; i < 256; i++ ) {
		if ( i < blen )
			*(bptr+i) = GetSet[i];
		else	break;
		}
	for ( i=0; i < 256; i++ ) {
		if ( (i+256) < blen )
			*(bptr+i+256) = PutSet[i];
		else	break;
		}
	return(0);

}

/*	H t t p F a i l u r e ( error_value )				*/
/*	-------------------------------------				*/
/*	This function is called from all interface functions for 	*/
/*	the management of error conditions encountered and the		*/
/*	preparation of the relevant report code.			*/


PUBLIC	int	HttpFailure( WORD evalue )
{
	if (!(HttpErrorValue = evalue))
		return( _HTTP_ABAL_SUCCESS );
	else	return( _HTTP_ABAL_FAILURE );
}

PUBLIC	int	HttpSuccess()	{	return( HttpFailure(0) );	}

/*	H t t p E r r o r ()					
 *	--------------------					
 *	Simply returns the code of the last error condition	
 *	reported vie the above error reporting function		
 */

PUBLIC	int	HttpError()
{
	return( HttpErrorValue );
}


/*
 *	H t t p S e t T y p e ( types_list_string )
 *	-------------------------------------------
 *	Sets the value of the HTTP Header field variable 
 *
 *	ACCEPTS:
 *
 *	to the value provided by the types_list_string parameter.
 */


PUBLIC	int	HttpGetMajor() {	return(http_get_major());	}
PUBLIC	int	HttpGetMinor() {	return(http_get_minor());	}

PUBLIC	int	HttpVersion()	
{
	return	( 

		((HttpGetMajor() + 0x0030) << 8)

			+

		(HttpGetMinor() + 0x0030)

		);
}

PUBLIC	int	HttpSetType(pptr)
	BPTR	pptr;
{
	return( http_set_content_type( pptr ) );
}

#ifdef	UNIX

/*	----------------------------------	*/
/*	BackGround Child Worker Management	*/
/*	----------------------------------	*/

PRIVATE	int	UseChildWorker=0;
PRIVATE	struct	child_control *	ChildHeap=(struct child_control *) 0;
PRIVATE	int	FlagCount=0;
PRIVATE	int	ChildFlag=-1;
PRIVATE	VPTR	OldChildHandler=(VPTR) 0;

PRIVATE	VOID	DropChildWorker( struct child_control * cptr )
{
	if (!( UseChildWorker )) { return; }
	if (!( cptr )) { return; }
#ifdef	WITH_VERBOSE
	if ( verbose & 512 ) { printf("DropChildWorker(p=%u,s=%u)\r\n",cptr->worker,cptr->socket); }
#endif
	if ( cptr->next )
		cptr->next->previous = cptr->previous;
	if ( cptr->previous )
		cptr->previous->next = cptr->next;
	else	ChildHeap = cptr->next;
	liberate( cptr );
	return;
}

PRIVATE	VOID	AddChildWorker( CONNECTIONPTR	cptr )
{
	struct	child_control *	chptr;

	if (!( UseChildWorker )) { return; }

	if (!( cptr )) { return; }

#ifdef	WITH_VERBOSE
	if ( verbose & 512 ) { printf("AddChildWorker(p=%u,s=%u)\r\n",cptr->worker,cptr->newsocket); }
#endif

	if (!( chptr = allocate( sizeof( struct child_control ) ) )) {
		return;
		}
	else	{
		chptr->worker = cptr->worker;
		chptr->socket = cptr->newsocket;
		chptr->object = cptr->newobject;
		chptr->next     = 
		chptr->previous = (struct child_control *) 0;
		if ((chptr->next = ChildHeap) != (struct child_control *) 0)
			chptr->next->previous = chptr;
		ChildHeap = chptr;
		return;
		}
}

PRIVATE	VOID	HttpCatchWorker( int signum )
{
	struct	child_control * cptr;
	int		status=0;
	int		pid=0;
	if (!( UseChildWorker )) { return; }
#ifdef	WITH_VERBOSE
	if ( verbose & 512 ) { printf("HttpCatchWorker(%u)\r\n",signum); }
#endif
	if ( signum = SIGCHLD ) {
		if ((pid = wait(&status)) > 0) {
#ifdef	WITH_VERBOSE
			if ( verbose & 512 ) { printf("Worker(%u) : %u\r\n",pid,status); }
#endif
			for (	cptr=ChildHeap;
				cptr != (struct child_control *) 0;
				cptr = cptr->next ) {
				if ( cptr->worker != pid )
					continue;
				else	{
					DropChildWorker( cptr );
					break;
					}
				}
			}
		}
	return;
}
#endif

PUBLIC	int	HttpLiberate()
{
#ifdef	UNIX
	struct child_control *	cptr;
#endif

#ifdef	_HTTP11
	HttpClear();
#endif
	liberate_url_services();
	drop_live_connections();

#ifdef WIN32
	WSACleanup();
#endif

#ifndef	PROLOGUE
	if ( TransferBuffer  ) {
		free(TransferBuffer);
		}
#endif
	TransferBuffer = (BPTR) 0;
	TransferBufferLength = 0;

#ifdef	UNIX
	/* --------------------------------------------- */
	/* IMPORTANT NOTICE : CORRECTION IJM 26/01/2006  */
	/* --------------------------------------------- */
	/* PRIOR to VERSION abal 3.2a.0.05		 */
	/* AND              wasp 1.0a.0.18		 */
	/* --------------------------------------------- */
	/* Restore previous Child Death Handler		 */
	/* --------------------------------------------- */
	if ( UseChildWorker ) {
		(void) signal(SIGCHLD,OldChildHandler);
		if ( ChildFlag != -1 ) {
			(void) semctl(ChildFlag,0,IPC_RMID,0);
			ChildFlag = -1;
			}
		while ((cptr = ChildHeap) != (struct child_control *) 0)
			DropChildWorker( cptr );
		}
	ChildHeap=(struct child_control *) 0;
#endif
#ifndef	ABAL64
	(void) (*gps)(3,0,0);
#endif
	return( HttpSuccess() );
}

/*
 *	HttpConfigure(pptr,plen)
 *	--------------------------------------------------------------
 *	Analyse de la ligne de commande.
 * Syntaxes acceptées :
 *   -X
 *   -Xvaleur ou -X"valeur" ou -X'valeur'
 *   --XXXX
 *   --XXXX valeur ou --XXXX "valeur" ou --XXXX 'valeur'
 *
 */

static void parse_string( BPTR value, WORD stop, BPTR* pptr, WORD* plen)
{
	BPTR  In    = *pptr;

	while (*plen > 0)
		{
		(*plen)--;
		if (*In == stop)
			{
			In++;
			break;
			}
		else
			*value++ = *In++;
		}
	*value = '\0';
	*pptr  = In;
}

PUBLIC	int	HttpConfigure(pptr,plen)
	BPTR	pptr;
	WORD	plen;
{
	WORD	i;
	enum _automate_ {
		eWAIT_MINUS1  = 0,
		eWAIT_MINUS2  = 1,
		eWAIT_LONGOPT = 2,
		eWAIT_PARAM   = 3,
		eANAL_OPTION  = 10,
		eANAL_OPTVAL  = 11,
	} etat;

	WORD	memo_option    = 0;
	WORD	memo_encapsule = 0;
	WORD	err;
	WORD	c;
	BPTR	aptr;

	if (!(aptr = allocate(plen)))
		{
		HttpLiberate();
		return( HttpFailure(27) );
				}

	/* Automate d'analyse de la ligne de commande */
	/* Boucle jusqu'à la fin ou erreur de syntaxe */
	/* ------------------------------------------ */		
	err  = 0;
	etat = eWAIT_MINUS1;
	while ( (!err) && (plen > 0))
		{
		c = *pptr;

		switch(etat)
			{
			case eWAIT_MINUS1: 
				/*  Attente 1er '-' */
				/* ---------------- */
				switch(c) 
					{
					case ' ' : pptr++; plen--; break;
					case '-' : etat = eWAIT_MINUS2; pptr++; plen--; break;
					default  : err = 30;  break;
					}
					break;

			case eWAIT_MINUS2: 
				/* Attente 2nd '-' ou option */
				/* ------------------------- */
				switch(c) 
					{
					case ' ' : err = 30; break;
					case '-' : 
						etat = eWAIT_LONGOPT; 
					break;
					default  : 
						memo_option = c;
						etat = eANAL_OPTION ; 
					break;
					}
				pptr++; plen--; 
						break;
							
			case eWAIT_LONGOPT: 
				/* Attente d'une option au format long */
				/* ----------------------------------- */
				parse_string( aptr, ' ', &pptr, &plen);
				for (i=0; *(aptr+i) != 0; i++ )
					if (( *aptr >= 'A' ) && ( *aptr <= 'Z' ))
						*aptr = ( *aptr + ('a'-'A'));
				if (!strcmp( aptr, "sslpass"))
					memo_option = 'A';
				else if (!strcmp( aptr, "sslkeycert"))
					memo_option = 'B';
				else if (!strcmp( aptr, "sslcafile"))
					memo_option = 'C';
				else if (!strcmp( aptr, "debug"))
					memo_option = 'D';
				else if (!strcmp( aptr, "optimised"))
					memo_option = 'O';
				else if (!strcmp( aptr, "persist"))
					memo_option = 'P';
				else if (!strcmp( aptr, "redirect"))
					memo_option = 'R';
				else
					err = 30;

				etat = eANAL_OPTION;
						break;

			case eWAIT_PARAM: 
				/* attente du début d'une valeur ou de ' ou " */
				/* ------------------------------------------ */
				switch(c) 
					{
					case ' ' : pptr++; plen--; break;
					case '\'': 
					case '"' : 
						/* encapsulation */
						memo_encapsule = c; 
						etat = eANAL_OPTVAL; 
						pptr++; plen--; 
						break;
					default  : 
						/* pas d'encapsulation */
						memo_encapsule = ' '; 
						etat = eANAL_OPTVAL; 
						break;
						}
					break;

			case eANAL_OPTION: 
				/* --- Analyse d'une option sans paramètre */
				/* --------------------------------------- */
				switch(memo_option) 
					{
					case	'o' :
					case	'O' :	
						Optimised = 1;
						etat = eWAIT_MINUS1;
						pptr++; plen--;
					break;
					case	'X' :
					case	'x' :	
						TransCode = 0; 
						etat = eWAIT_MINUS1;
						pptr++; plen--;
						break;
					case	'0' :	
					case	'1' :	
					case	'2' :	
					case	'3' :	
					case	'4' :	
					case	'5' :	
					case	'6' :	
					case	'7' :	
					case	'8' :	
					case	'9' :	
						http_set_minor( (c - '0') );
						etat = eWAIT_MINUS1;
						pptr++; plen--;
						break;
				default	    :
						etat = eWAIT_PARAM; 
						break;
						}
				break;

			case eANAL_OPTVAL: 
				/* Analyse d'une valeur jusqu'au séparateur de fin */
				/* ----------------------------------------------- */
				parse_string( aptr, memo_encapsule, &pptr, &plen);
				switch ( memo_option ) 
					{
#ifdef SYSTEM_SSL
					case	'a' :
					case	'A' : https_use_password(aptr); break;
					case	'b' :
					case	'B' : https_use_encryption(aptr); break;
					case	'c' :
					case	'C' : https_use_certificate(aptr); break;
#endif
					case	'd' :
					case	'D' :	set_global_debug( aptr ); break;
					case	'K' :
					case	'k' :	http_use_encryption(integer_option(aptr)); break;
					case	'n' :
					case	'N' :	SetUserAgent( aptr ); break;
#ifdef	_HTTP11
					case	'p' :	
					case	'P' :	err = http_set_persist(integer_option( aptr )); break;
#endif
					case	'r' :
					case	'R' : set_v_putch(integer_option(aptr)); break;
					case  's' :
					case  'S' : SelectTimer = integer_option(aptr); break;
					case  't' :
					case  'T' : err = http_set_accept(aptr); break;
					case	'v' :
					case	'V' : set_global_verbose( aptr ); break;
					default	 : err = 30; break;
					}
				etat = eWAIT_MINUS1;
				break;
				}
			}

	liberate(aptr);
	if (err)
		{
		HttpLiberate();
		return( HttpFailure(err) );
		}
	return( HttpSuccess() );
}


/*
 *	H t t p I n i t i a l i s a t i o n ( options_string, length )
 *	--------------------------------------------------------------
 *	This function performs all necessary operations for the correct
 *	and complete initialisation of the HTTP Library and its component
 *	sub-systems.
 *
 */

PUBLIC	int	HttpInitialise(pptr,plen)
	BPTR	pptr;
	WORD	plen;
{
	WORD	i;
	WORD	status;
#ifdef WIN32
	WSADATA			wsaData; // Contains details of the Winsock implementation
#endif

#ifdef	WITH_VERBOSE
	if ( verbose ) { printf("\nHttpInitialise(WORDSIZE=%u)\n",sizeof(WORD)); }
#endif

#ifdef	UNIX
	/* --------------------------------------------- */
	/* IMPORTANT NOTICE : CORRECTION IJM 26/01/2006  */
	/* --------------------------------------------- */
	/* PRIOR to VERSION abal 3.2a.0.05		 */
	/* AND              wasp 1.0a.0.18		 */
	/* --------------------------------------------- */
	/* the child death handler is important to allow */
	/* the background mode HttpPutFile operation to  */
	/* coordinate between child and parent processes */
	/* to ensure socket liberation is performed 	 */
	/* equally in the child and parent prcocesses.	 */
	/* otherwise socket consumption will cause hang  */
	/* --------------------------------------------- */
	ChildHeap=(struct child_control *) 0;
	if ( UseChildWorker ) {
#ifdef	WITH_VERBOSE
		if ( verbose & 512 ) { printf("Installing Child Handler\r\n"); }
#endif
		OldChildHandler = signal(SIGCHLD,HttpCatchWorker);
		ChildFlag       = semget(IPC_PRIVATE,_HTTP_SEMAPHORES,0666);
#ifdef	WITH_VERBOSE
		if ( verbose & 512 ) { printf("Installing Child Semaphore : %u \r\n",ChildFlag); }
#endif
		}
#endif

#ifdef WIN32
/* Winsowk initialisation required before any socket function */
if ( WSAStartup( MAKEWORD(2,2), &wsaData ) != 0 )
	return HttpFailure(_HTTP_ABAL_FAILURE);

/* Confirm that the WinSock DLL supports 2.2.        */
/* Note that if the DLL supports versions greater    */
/* than 2.2 in addition to 2.2, it will still return */
/* 2.2 in wVersion since that is the version we      */
/* requested.                                        */
if ( LOBYTE( wsaData.wVersion ) != 2 || HIBYTE( wsaData.wVersion ) != 2 ) 
	return HttpFailure(_HTTP_ABAL_FAILURE);
#endif

#ifndef	_ANSI_ISO1_H

	/* ---------------------------------------------------- */
	/* This was the short cut before christophe gave me the */
	/* Ansi to Iso Translation tables			*/
	/* ---------------------------------------------------- */
	for ( i=0; i < 256; i++ ) {
		GetSet[i] = i;
		PutSet[i] = i;
		}

	GetSet[0x0092] = 0x0027; /* These are the single Quote characters */
	GetSet[0x0027] = 0x0092; /* ------------------------------------- */

	GetSet[0x00A9] = '‡';	PutSet['‡'] = 0x00A9;
	GetSet[0x00E9] = '‚';	PutSet['‚'] = 0x00E9;
	GetSet[0x00E0] = '…';	PutSet['…'] = 0x00E0;
	GetSet[0x00E8] = 'Š';	PutSet['Š'] = 0x00E8;
	GetSet[0x00EC] = '';	PutSet[''] = 0x00EC;
	GetSet[0x00F2] = '•';	PutSet['•'] = 0x00F2;
	GetSet[0x00F9] = '—';	PutSet['—'] = 0x00F9;

#endif	/* _ANSI_ISO1_H */

#ifndef	PROLOGUE
	if (!( TransferBuffer = malloc((TransferBufferLength=MAX_BUFFER_SIZE)) ))
		return( HttpFailure(27) );
#else
	TransferBuffer = ClientNameBuffer;
	TransferBufferLength = 256;
#endif

	for ( i= 0; i < MAX_CONNECTIONS; i++ )
 		ConnectionTable[i] = (CONNECTIONPTR) 0;

	if (((status = initialise_url_services()) != 0 )
	||  ((status = initialise_http_service()) != 0 )
	||  ((status = initialise_https_service()) != 0 ))
		return( HttpFailure(status) );

	else if ( pptr != (BPTR) 0) {
#ifdef	_HTTP11
		clear_persistance();
#endif
		return( HttpConfigure( pptr, plen ) );

		}
	else	return( HttpSuccess() );
}

PUBLIC	int	HttpOpenServer(port,nature)
	WORD	port;		/* 0 DEFAULT 80				*/
	WORD	nature;		/* 0 RAW, 1 TCP 2 UDP 			*/
				/* 4 SSL, 8 SSL ENFORCED		*/
{
	URLPTR	uptr;
	int	status;
#ifdef	CLIENT_VERSION
	return( HttpFailure(758) );
#endif
	if ( ConnectionTable[0] != (CONNECTIONPTR) 0)
		return( HttpFailure(44) );

	else if ((nature = ConnectionNature( nature )) == _HTTP_ABAL_FAILURE )
		return( HttpFailure(99) );

	if (!( nature & 4 )) {
 		if ((uptr = allocate_for_url( "http://0.0.0.0/",0L )) == (URLPTR) 0)
			return( HttpFailure(27) );
		else if (!(port))
			port = 80;
		}
 	else if ((uptr = allocate_for_url( "https://0.0.0.0/",0L )) == (URLPTR) 0)
		return( HttpFailure(27) );

	else if (!( port ))
		port = 443;
#ifndef	ABAL64
	if ((status = (*gps)(0,port,nature)) != 0) {
		uptr = liberate_for_url( uptr );
		return( HttpFailure(status) );
		}
#endif
	if ((ConnectionTable[0] = open_connection( nature, port, uptr )) == (CONNECTIONPTR) 0) 
	{
#ifndef	ABAL64
		(void) (*gps)(3,port,nature);
#endif
		uptr = liberate_for_url( uptr );
		return(HttpFailure(40));
	}
	else	
	{
		return(HttpSuccess());
	}
}

PUBLIC	int	HttpSecurity(WORD mode, BPTR kptr, BPTR cptr, BPTR aptr, BPTR pptr)
{
	BYTE	buffer[1025];
	WORD	i;

	TlsMode = mode;

	/* ---------------------------- */
	/* process the private key file */
	/* ---------------------------- */
	for ( i=0; i < 1024; i++)
		if ((buffer[i] = *(kptr+i)) == ' ')
			break;

	buffer[i] = 0;
	https_use_encryption(buffer);

	/* ---------------------------- */
	/* process the certificate file */
	/* ---------------------------- */
	for ( i=0; i < 1024; i++)
		if ((buffer[i] = *(cptr+i)) == ' ')
			break;

	buffer[i] = 0;
	https_use_certificate(buffer);

	/* ----------------------------- */
	/* process the CA authority file */
	/* ----------------------------- */
	for ( i=0; i < 1024; i++)
		if ((buffer[i] = *(aptr+i)) == ' ')
			break;

	buffer[i] = 0;
	https_use_CA_list(buffer);

	/* ----------------------- */
	/* process the pass phrase */
	/* ----------------------- */
	for ( i=0; i < 1024; i++)
		if ((buffer[i] = *(pptr+i)) == ' ')
			break;

	buffer[i] = 0;
	https_use_password(buffer);

	return(0);
}
	
PUBLIC	int	HttpDuplicate(handle)
	WORD	handle;
{
	WORD		i;
	CONNECTIONPTR	cptr;

	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0 ))
		return( HttpFailure(50) );
	else	{
		for ( i= 1; i < MAX_CONNECTIONS; i++ )
			if ( ConnectionTable[i] == (CONNECTIONPTR) 0 )
				break;

		if ( i < MAX_CONNECTIONS ) {
			if (!( ConnectionTable[i] = copy_connection( cptr ) ))
				return( HttpFailure(27) );
			else	{
				cptr->duplicate = 1;
				return( i );
				}
			}
		else	return(HttpFailure(46));
		}
}


PUBLIC	int	HttpOpenClient(urlname,namelen,nature)
	BPTR	urlname;
	WORD	namelen;
	WORD	nature;		/* 0 RAW, 1 TCP 2 UDP */
{
	WORD		i;
	URLPTR		uptr;

	int	status;

#ifndef	ABAL64
	if ((status = (*gps)(0,0,0)) != 0)
		return( HttpFailure(status) );
	else if ((status = (*gps)(2,0,0)) != 0)
		return( HttpFailure(status) );
#endif

	for ( i= 1; i < MAX_CONNECTIONS; i++ )
		if ( ConnectionTable[i] == (CONNECTIONPTR) 0 )
			break;

	if ( i < MAX_CONNECTIONS ) {

		if ( namelen >= MAX_NAME_LENGTH )
			return(HttpFailure( 113 ));

		memcpy( ClientNameBuffer, urlname, namelen );
		ClientNameBuffer[namelen] = 0;

		if ((nature = ConnectionNature( nature )) == _HTTP_ABAL_FAILURE )
			return( HttpFailure(99) );
		else if ((uptr = allocate_for_url( ClientNameBuffer,0L )) == (URLPTR) 0)
			return( HttpFailure(27) );

		if ((ConnectionTable[i] = open_connection( nature, 0, uptr )) == (CONNECTIONPTR) 0) {
			uptr = liberate_for_url( uptr );
			return(HttpFailure(40));
			}
		else	return(i);

		}
	else	return(_HTTP_ABAL_FAILURE);	
}

PUBLIC	int	HttpOpenConnection(urlname,namelen,nature,ipflag,ipaddress)
	BPTR	urlname;
	WORD	namelen;
	WORD	nature;		/* 0 RAW, 1 TCP 2 UDP */
	WORD	ipflag;
	LONG	ipaddress;
{
	WORD		i;
	URLPTR		uptr;

	// ---------------------------------------
	// If the IP Address has not been provided
	// then all the work is yet to do
	// ---------------------------------------
	if (!( ipaddress ))
		return( HttpOpenClient( urlname, namelen, nature ) );

	// -------------------------------
	// If this is a primary connection 
	// -------------------------------
	for ( i= 1; i < MAX_CONNECTIONS; i++ )
		if ( ConnectionTable[i] == (CONNECTIONPTR) 0 )

	break;

	if ( i < MAX_CONNECTIONS ) {

		if ( namelen >= MAX_NAME_LENGTH )
			return(_HTTP_ABAL_FAILURE);

		memcpy( ClientNameBuffer, urlname, namelen );
		ClientNameBuffer[namelen] = 0;

		if ((nature = ConnectionNature( nature )) == _HTTP_ABAL_FAILURE )
			return( nature );

		else if ((uptr = allocate_for_url( ClientNameBuffer, ipaddress )) == (URLPTR) 0)
			return(_HTTP_ABAL_FAILURE);

		if ((ConnectionTable[i] = open_connection( nature, 0, uptr )) == (CONNECTIONPTR) 0) {
			uptr = liberate_for_url( uptr );
			return(_HTTP_ABAL_FAILURE);
			}
		else	return(i);

		}
	else	return(_HTTP_ABAL_FAILURE);	
}

PUBLIC	int	HttpClose(handle,mode)
	WORD	handle;
	WORD	mode;
{
	WORD		flags;
	WORD		service;
	URLPTR		uptr;
	CONNECTIONPTR	cptr;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0 ))
		return( HttpFailure(50) );
	else	{
		service = cptr->service;
		flags   = cptr->flags;
		if (( mode   == 1 )
		&&  ( handle == 0 )) {
			if ((cptr->status & _URL_LISTEN)
			&&  (cptr->status & _URL_ACCEPT))
				drop_connection( cptr );
			}
		else if ( cptr->duplicate ) {
			if ((cptr->status & _URL_LISTEN)
			&&  (cptr->status & _URL_ACCEPT))
				drop_connection( cptr );
			liberate_for_connection( cptr );
			ConnectionTable[handle] = (CONNECTIONPTR) 0;
			}
		else	{
#ifdef	_HTTP11
			if (!( http_may_persist() )) {
#endif
				uptr = cptr->remote;
				(void) close_connection( cptr );
				uptr = liberate_for_url( uptr );
	
#ifdef	_HTTP11
				}
			else if (!( mode & 8 )) {
				uptr = cptr->remote;
				(void) close_connection( cptr );
				uptr = liberate_for_url( uptr );
				}
			else	(void) persist_connection( cptr );
#endif
#ifndef	ABAL64
			(void) (*gps)(3,service,flags);
#endif
			ConnectionTable[handle] = (CONNECTIONPTR) 0;
			}
		return(HttpSuccess());
		}
}

PUBLIC	int	HttpClear()
{
	WORD		i;

	for ( i= 0; i < MAX_CONNECTIONS; i++ )
		(void) HttpClose(i,0);

#ifdef	_HTTP11
	clear_persistance();
#endif
	return(HttpSuccess());
}

PUBLIC	int	HttpAccept(handle,timeout)
	WORD	handle;
	WORD	timeout;
{
	CONNECTIONPTR	cptr;
	int	status;

#ifndef	ABAL64
	if ((status = (*gps)(1,0,0)) != 0)
		return( HttpFailure(status) );
	else
#endif

	if ( handle >= MAX_CONNECTIONS )
		return( HttpFailure(50) );
	else if ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
		return( HttpFailure(50) );
	else if (!( cptr->status & _URL_LISTEN ))
		return( HttpFailure(55) );
	else if ( accept_connection( cptr, timeout ) == (CONNECTIONPTR) 0)
		return( HttpFailure(48) );
#ifndef	ABAL64
	else if ((status = (*gps)(2,0,0)) != 0)
		return( HttpFailure(status) );
#endif
	else	return(  0  );
}

PUBLIC	int	HttpIpAddress(handle)
	WORD	handle;
{
	CONNECTIONPTR	cptr;

	if ( handle >= MAX_CONNECTIONS )
		return( 0L );

	else if ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
		return( 0L );

	if ( cptr->status & _URL_CONNECT )
		return( cptr->connected );
	else if (!( cptr->status & _URL_LISTEN ))
		return( 0L );
	else if (!( cptr->status & _URL_ACCEPT ))
		return( 0L );
	else	return( cptr->remote->address[cptr->remote->adrindex].sin_addr.s_addr);

}

PUBLIC	int	HttpContentLength(handle,buffer)
	WORD	handle;
	BPTR	buffer;
{
	CONNECTIONPTR	cptr;
	WORD		i;

	if ( handle >= MAX_CONNECTIONS )
		return( HttpFailure(50) );
	else if ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
		return( HttpFailure(50) );

	for ( i=0; *(buffer + i) != 0; i++ );

	cptr->length = i;

	return(0);

}

PUBLIC	int	HttpGetAddress(handle,buffer,length)
	WORD	handle;
	BPTR	buffer;
	WORD	length;
{
	CONNECTIONPTR	cptr;
	BPTR		aptr;

	if ( handle >= MAX_CONNECTIONS )
		return( HttpFailure( 50 ));
	else if ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
		return( HttpFailure( 50 ));

	if ( cptr->status & _URL_CONNECT ) {
		if ((aptr = socketname((ADDRPTR) & cptr->remote->address[cptr->remote->adrindex] )) == (BPTR) 0)
			return( HttpFailure( 42 ));
		}
	else if (!( cptr->status & _URL_LISTEN ))
		return( HttpFailure( 55 ));
	else if (!( cptr->status & _URL_ACCEPT ))
		return( HttpFailure( 55 ));
	else if ((aptr = socketname((ADDRPTR) & cptr->remote->address[cptr->remote->adrindex] )) == (BPTR) 0)
		return( HttpFailure( 42 ));

	memset(buffer,' ',length);
	while (( length ) && ( *aptr )) {
		if ( *aptr == ':' )
			*aptr = 0;
		else	{
			*(buffer++) = *(aptr++);
			length--;
			}
		}
	return(HttpFailure(( *aptr ? 63 : 0)));
}


PUBLIC	int	HttpSetHost(handle,hostname)
	WORD	handle;
	BPTR	hostname;
{
	CONNECTIONPTR	cptr;
	URLPTR		uptr;
	WORD		status=0;
	if (( handle >= MAX_CONNECTIONS )
	||  ( hostname == (BPTR) 0)
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
	||  ((uptr = cptr->remote) == (URLPTR) 0))
		return( HttpFailure(50) );
	else 	return( url_set_alt_host( uptr, hostname ) );
}

PUBLIC	int	HttpSetHeader(handle,header)
	WORD	handle;
	BPTR	header;
{
	CONNECTIONPTR	cptr;
	URLPTR		uptr;
	WORD		status=0;
	if (( handle >= MAX_CONNECTIONS )
	||  ( header == (BPTR) 0)
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
	||  ((uptr = cptr->remote) == (URLPTR) 0))
		return( HttpFailure(50) );
	else 	return( url_set_alt_header( uptr, header ) );
}

PRIVATE	BPTR	locatebyte( item, buffer )
	WORD	item;
	BPTR	buffer;
{
	while ( *buffer ) {
		if ( *buffer == item )
			break;
		else	buffer++;
		}
	return( buffer );
}

PUBLIC	int	HttpPost(handle,buffer)
	WORD	handle;
	BPTR	buffer;
{
	CONNECTIONPTR	cptr;
	URLPTR		uptr;
	BPTR		bptr;	/* Boundary */
	WORD		blen=0;
	WORD		status=0;
	WORD		length=0;
	WORD		nuff;
	BPTR		muffer;
	BPTR		nuffer;
	BPTR		vptr;
	WORD		vl;
	if (( handle >= MAX_CONNECTIONS )
	||  ( buffer == (BPTR) 0)
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
	||  ((uptr = cptr->remote) == (URLPTR) 0))
		return( HttpFailure(50) );
	else if ((bptr = http_get_boundary()) != (BPTR) 0) {
		for ( blen=0; *(bptr + blen) != 0; blen++);
		if (!(	http_put( cptr, "--", 2) ))
			return( HttpFailure(2) );
		else if (!( http_put( cptr, bptr, blen ) ))
			return( HttpFailure(2) );
		else if (!( http_put( cptr, "\r\n", 2) ))
			return( HttpFailure(2) );

		while ( *buffer  ) {
			if (!( muffer = locatebyte('=',buffer) ))
				break;
			else if (!( nuffer = locatebyte('&',muffer) ))
				break;
			*(muffer++) = 0;
			nuff = *nuffer; *nuffer = 0;
			for ( vl=0,vptr=__CONTENT_DISPO; *(vptr+vl) != 0; vl++);
			if (!( http_put( cptr, vptr, vl ) )) return( HttpFailure(2) );
			for ( vl=0,vptr=__FORM_DATA; *(vptr+vl) != 0; vl++);
			if (!( http_put( cptr, vptr, vl ) )) return( HttpFailure(2) );
			for ( vl=0,vptr=buffer; *(vptr+vl) != 0; vl++);
			if ((!( http_put( cptr, vptr, vl ) ))
			||  (!( http_put( cptr, "\r\n\r\n", 4 ) )))
				return( HttpFailure(2) );
			for ( vl=0,vptr=muffer; *(vptr+vl) != 0; vl++);
			if ((!( http_put( cptr, vptr,  vl ) ))
			||  (!( http_put( cptr, "\r\n", 2 ) ))
			||  (!( http_put( cptr, "--",   2 ) ))
			||  (!( http_put( cptr, bptr,blen ) ))
			||  (!( http_put( cptr, "\r\n", 2 ) )))
				return( HttpFailure(2) );
			if ( nuff )
				*(nuffer++) = nuff;
			buffer  = nuffer;
			}			
		return( HttpSuccess() );
		}
	else	{
		// URL ENCODED EASY POSTING or should be !!!
		if (!(length =  cptr->length ))
			for ( length=0; *(buffer + length) != 0; length++);
		if ( http_put( cptr, buffer, length ) )
			return( HttpSuccess() );
		else	return( HttpFailure(2) );
		}
}

PUBLIC	int	HttpCommand(handle,command)
	WORD	handle;
	BPTR	command;
{
	CONNECTIONPTR	cptr;
	URLPTR		uptr;
	BPTR		hptr;
	WORD		status=0;
	if (( handle >= MAX_CONNECTIONS )
	||  ( command == (BPTR) 0)
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
	||  ((uptr = cptr->remote) == (URLPTR) 0)
	||  ((hptr = uptr->host) == (BPTR) 0))
		return( HttpFailure(50) );
	else	{
		switch ( http_keyword( command ) ) {
			case	 _HTTP_METHOD_GET	:
			case	 _HTTP_METHOD_POST	:
			case	 _HTTP_METHOD_HEAD	:
#ifdef	HTTP11
			case	 _HTTP_METHOD_PUT	:
			case	 _HTTP_METHOD_DELETE	:
			case	 _HTTP_METHOD_TRACE	:
			case	 _HTTP_METHOD_OPTIONS	:
			case	 _HTTP_METHOD_CONNECT	:
#endif
					/* Method Accepted */
					/* --------------- */
					break;

			default	:	return( HttpFailure( 56 ) );
			}

		if ( uptr->althost )
			hptr = uptr->althost;

		status = HttpSendMessage( cptr, command, hptr, uptr->path );

		/* -1 or 0 already decided */

		return( status );
		}
}

PUBLIC	int	HttpProxyCommand(handle,command,ressource)
	WORD	handle;
	BPTR	command;
	BPTR	ressource;
{
	CONNECTIONPTR	cptr;
	URLPTR		uptr;
	BPTR		hptr;
	WORD		status=0;
	if (( handle >= MAX_CONNECTIONS )
	||  ( command == (BPTR) 0)
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)
	||  ((uptr = cptr->remote) == (URLPTR) 0)
	||  ((hptr = interpret_url( uptr )) == (BPTR) 0))
		return( HttpFailure(50)  );
	else	{
		status = HttpSendMessage( cptr, command, hptr, ressource );
		hptr = liberate_zone( hptr );
		return( status );
		}
	return(0);
}


/*
 *	NB : This function returns the number of bytes NOT READ
 */


PUBLIC	int	HttpGet(handle,buffer,length)
	WORD	handle;
	BPTR	buffer;
	WORD	length;
{
	CONNECTIONPTR	cptr;
	WORD		c;
	WORD		transfered=0;
	WORD		transfer=4096;
	VPTR		object=(VPTR) 0;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure(50) );
	else	{
		handle = (cptr->status & _URL_LISTEN ? cptr->newsocket : cptr->socket );
		object = (cptr->status & _URL_LISTEN ? cptr->newobject : cptr->object );

		if ((SelectTimer)
		&&  (!(select_connection( handle, SelectTimer ))))
			return( -1 );

		if ( Optimised ) {
			while ( transfered < length ) {
				if ( transfer > length ) transfer=length;
#if defined(UNIX) || defined(WIN32)
#ifdef	SYSTEM_SSL
				if ( object ) {
					c = ssl_tcp_read( object, (buffer+transfered), transfer);
					}
				else
#endif
					c = tcp_read( handle, (buffer+transfered), transfer);
				if (!( c )) {
					if (!( transfered ))
						return(-1);
					else	break;
					}
#else
				c = tcp_read( handle, (buffer+transfered), transfer);
#endif
				transfered +=c;
				if ( c != transfer )
					break;
				}
			if ( cptr->cryptage == _decryption ) 
				abal_crypt(&cptr->coding, buffer, transfered );
			return((length - transfered));
			}
		else	{
			memset( buffer,0x001A,length );
			for ( transfered=0; transfered < length; transfered++ ) { 

#if defined(UNIX) || defined(WIN32)
#ifdef	SYSTEM_SSL
				if ( object )
					c = ssl_tcp_readb( object );
				else
#endif
				 	c = tcp_readb( handle );
#else
				 	c = tcp_readb( handle );
#endif
				if ((c > 255 ))
					break;
				*(buffer++) = (char)c;
				}				
			if ( cptr->cryptage == _decryption ) 
				abal_crypt(&cptr->coding, buffer, transfered );
			return(( length - transfered));
			}
		}
}

PUBLIC	int 	TranscodeByte( c )
	int 	c;
{
	if ( TransCode )
		return( GetSet[(c & 0x00FF)] );
	else	return( (c & 0x00FF) );
}

PUBLIC	int	HttpTranscode( c )
	WORD	c;
{
	return( TranscodeByte( c ) );
}

PUBLIC	int	HttpSetConversion( mode )
	WORD	mode;
{
	WORD	rvalue=TransCode;
	TransCode = mode;
	return( rvalue );
}


PUBLIC	int	HttpGetLine(handle,buffer,length)
	WORD	handle;
	BPTR	buffer;
	WORD	length;
{
	BPTR		muffer;
	BPTR		tuffer;
	WORD		bytes;
	WORD		received=0;
	CONNECTIONPTR	cptr;
	WORD		x;
	WORD		y;
	WORD		i;
	WORD		c;
	WORD		cc;
	WORD		status=63;
	VPTR		object=(VPTR) 0;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
	{
		return( HttpFailure(50) );
	}
	else	
	{
		handle = (cptr->status & _URL_LISTEN ? cptr->newsocket : cptr->socket );
		object = (cptr->status & _URL_LISTEN ? cptr->newobject : cptr->object );
  		memset( (tuffer=muffer=buffer), ' ',(bytes=length) );
		while ( length  ) 
		{

			if (( SelectTimer )
			&&  (!(select_connection( handle, SelectTimer ))))
			{
				return( HttpFailure(27) );
			}	
#if defined(UNIX) || defined(WIN32)
#ifdef	SYSTEM_SSL
			if ( object )
				c = ssl_tcp_readb( object );
			else
#endif
			 	c = tcp_readb( handle );
#else
			 	c = tcp_readb( handle );
#endif

			switch ( (c & 0x00FF) ) 
			{
			case   '\r'	: 
				continue;
			case	0xFF00	:
				c = 0x001A;
				length = 0;
				continue;
			case	0  	:
				length = 0;
				continue;
			case	0x001A	:
				length = 0;
				continue;
			case   '\n'	: 
				length = 0;
				continue;
			case	'\t'	:
				c = ' ';
			default		:
				received++;
				*(buffer++) = TranscodeByte( c );
				length -= 1;
			}
		}
		for (i=0; i < bytes; i++ ) 
		{
			switch ((cc = (*(muffer++) & 0x00FF))) 
			{
			case	'%'	:
				x = *(muffer++);
				y = *(muffer++);
				i += 2;
				if (( x >= 'a' ) && ( x <= 'f' ))
					x = (x -'a')+10;
				else if (( x >= 'A' ) && ( x <= 'F' ))
					x = (x -'A')+10;
				else if (( x >= '0' ) && ( x <= '9' ))
					x = (x -'0');
				if (( y >= 'a' ) && ( y <= 'f' ))
					y = (y -'a')+10;
				else if (( y >= 'A' ) && ( y <= 'F' ))
					y = (y -'A')+10;
				else if (( y >= '0' ) && ( y <= '9' ))
					y = (y -'0');
				cc = (x*16) + y;
			default		:
				if ( TransCode )
					*(tuffer++) = GetSet[cc];
				else 	*(tuffer++) = cc;
			}
		}
		return( c );
	}
}

PUBLIC	int	HttpSelect(handle,timeout)
	WORD	handle;
	WORD	timeout;
{
	CONNECTIONPTR	cptr;
	WORD		status=63;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure(50) );
	else	{
		handle = (cptr->status & _URL_LISTEN ? cptr->newsocket : cptr->socket );
		return( select_connection( handle, timeout ) );
		}
}

PUBLIC	int	HttpGetString( handle,buffer,length)
	WORD	handle;
	BPTR	buffer;
	WORD	length;
{
	CONNECTIONPTR	cptr;
	WORD		c;
	WORD		status=63;
	VPTR		object=(VPTR) 0;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( _HTTP_ABAL_FAILURE );
	else	{
		handle = (cptr->status & _URL_LISTEN ? cptr->newsocket : cptr->socket );
		object = (cptr->status & _URL_LISTEN ? cptr->newobject : cptr->object );
  		memset( buffer, ' ',length );
		while ( length  ) {
#if defined(UNIX) || defined(WIN32)
#ifdef	SYSTEM_SSL
			if ( object )
				c = ssl_tcp_readb( object );
			else
#endif
			 	c = tcp_readb( handle );
#else
			 	c = tcp_readb( handle );
#endif
			switch ( (c & 0x00FF) ) {
				case   '\r'	: 
					continue;
				case	0xFF00	:
					c = 0x001A;
				case	0  	:
				case	0x001A	:
				case   '\n'	: 
					length = 0;
					continue;
				case	'\t'	:
					c = ' ';
				default		:
					*( buffer++ ) = TranscodeByte( c );
					length -= 1;
				}
			}
		*(buffer++) = 0;
		return( c );
		}
}

PUBLIC	int	HttpPut(handle,buffer,length)
	WORD	handle;
	BPTR	buffer;
	WORD	length;
{
	WORD		status=0;
	CONNECTIONPTR	cptr;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure(50) );
	else	{
		if ( cptr->cryptage == _encryption ) 
			abal_crypt(&cptr->coding, buffer, length );
		if (!( http_put( cptr, buffer, length ) ))
			return( HttpFailure(2) );
		else	return( HttpSuccess()  );
		}
}

static	WORD	filereader( FILE * fhandle, BPTR buffer, WORD buflen )
{
	int	c;
	WORD	i;
	for (	i=0; i < buflen; i++ )  {
		if ((c = fgetc( fhandle )) == -1)
			break;
		else	*(buffer+i) = (BYTE) c;
		}
	return( i );
}

WORD putfile( CONNECTIONPTR cptr, FILE* fhandle, BPTR xbuffer, WORD xbuflen, WORD mode, void* pInfoThreaded )
{
	WORD		l;
	WORD		i;
	WORD		eoftext=0;
#ifdef	WIN32
	MI_TRACE_CTX((pInfoThreaded, CI_TRA_F_DEBUG,0x0002,"putfile","cptr->socket=%lu",cptr->socket));
	MI_TRACE_CTX((pInfoThreaded, CI_TRA_F_DEBUG,0x0002,"putfile","cptr->newsocket=%lu",cptr->newsocket));
#endif
	while ((l=filereader(fhandle,xbuffer,xbuflen)) != 0 ) 
	{
		if ((mode & 1)) 
		{
			for (i=0; i < l; i++ ) 
			{
				if ((eoftext = xbuffer[i]) == 0x001A ) 
				{
					l = i;
					break;
				}
				if ( TransCode ) 
				{
					*(xbuffer+i) = PutSet[(eoftext & 0X00FF)];
				}
			}
		}
		if ( l > 0 ) 
		{
#ifdef	WIN32
			MI_TRACE_CTX((pInfoThreaded, CI_TRA_F_DEBUG,0x0002,"putfile","avant http_put" ));
			MI_TRACE_CTX((pInfoThreaded, CI_TRA_F_DUMP ,0x0002,"putfile","buffer:", xbuffer, l ));
#endif
			if (!( http_put( cptr, xbuffer, l ) )) 
			{
				fclose( fhandle );
				return 2;
			}
		}
		else	
			break;

		if ( eoftext == 0x001A )
			break;
	}
	fclose( fhandle );
	return 0 ;
}


#ifdef WIN32 ////////////////////////////////////////////////

typedef struct
	{
	WORD				handle;
	CONNECTIONPTR	cptr;
	FILE *			fhandle;
	BPTR				xbuffer;
	WORD				xbuflen;
	WORD				mode;
	} T_ThreadHttpPutFile;


DWORD WINAPI ThreadPutFile( T_ThreadHttpPutFile* pParam )
{
DWORD ret;
URLPTR	uptr;
TI_TRA_CTX* pCtx = allocate(sizeof(TI_TRA_CTX));
TraCtxClone( pCtx, &g_TraCtx);

MI_TRACE_CTX((pCtx,CI_TRA_F_DEBUG,0x0002,"-(ThreadPutFile","begin"));
ret = putfile( pParam->cptr, pParam->fhandle, pParam->xbuffer, pParam->xbuflen, pParam->mode, pCtx);

uptr = pParam->cptr->remote;
(void) close_connection( pParam->cptr );

liberate(pParam->xbuffer);
liberate(pParam);
MI_TRACE_CTX((pCtx, CI_TRA_F_DEBUG,0x0002,"-(ThreadPutFile","end (%d)",ret));
free(pCtx);
return ret; 
}


#endif //////////////////////////////////////////////////////
#ifdef	UNIX
PRIVATE	VOID	HttpSemaphore( int v )
{
	struct sembuf	FlagWork;
	if (!( UseChildWorker )) { return; }
	FlagWork.sem_num = 0;
	FlagWork.sem_op  = v;
	FlagWork.sem_flg = SEM_UNDO; 
#ifdef	WITH_VERBOSE
	if ( verbose & 512 ) {
		switch ( v ) {
			case	0 : printf("%u Child (%u) Await Semaphore \r\n",FlagCount,getpid()); break;
			case	1 : printf("%u Parent(%u) Raise Semaphore \r\n",FlagCount,getpid()); break;
			default	  : printf("%u Parent(%u) Lower Semaphore \r\n",FlagCount,getpid()); break;
			}
		}
#endif
	if ( semop ( ChildFlag, &FlagWork, 1) < 0 ) {
#ifdef	WITH_VERBOSE
		if ( verbose & 512 ) {
			printf("Parent(%u) Semaphore Failure : %u \r\n",getpid(),errno);
			}
#endif
		}
	return;
}
#endif

PUBLIC	int	HttpPutFile(handle,filename,length,mode)
	WORD	handle;
	BPTR	filename;
	WORD	length;
	WORD	mode;		/* Text file : 1, Binary 0 */
				/* 8 : background binary,  */
				/* 9 : background text  ,  */
				/* 16: delete file after   */
{
	CONNECTIONPTR	cptr;
	FILE *		fhandle;
	BPTR		xbuffer=TransferBuffer;
	WORD		xbuflen=TransferBufferLength;
	int		ret;
	int	status;

#ifndef	ABAL64
	if ((status = (*gps)(1,0,0)) != 0)
		return( HttpFailure(status) );
	else if ((status = (*gps)(2,0,0)) != 0)
		return( HttpFailure(status) );
#endif

	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure( 50 ) );
	if ((fhandle = fopen( filename, "rb" )) == (FILE *) 0) {
		return( HttpFailure( 40 ) );
		}
	else	{

#if defined	(UNIX)
		/* Multi-tache possible avec fork */
		if ( mode & 8 ) {

			FlagCount++;
#ifdef	WITH_VERBOSE
			if ( verbose & 512 ) { printf("\r\nBackground Task File Transfer(%u) : %s \r\n",FlagCount,filename); } 
#endif
			/* Raise Mutex */
			/* ----------- */
			HttpSemaphore(1);
			switch (( cptr->worker = fork())) {
				case	-1	:	
					/* Drop  Mutex */
					/* ----------- */
					HttpSemaphore(-1);
					fclose( fhandle );
					return( HttpFailure( 38 ) );
				case	0	:
					/* Await Mutex */
					/* ----------- */
					usleep(5);
					HttpSemaphore(0);
#ifdef	WITH_VERBOSE
					if ( verbose & 512 ) { printf("ChildProcess (%u) starting for HttpPutFile(%s) : mode=%u, length=%u \r\n",getpid(),filename,mode,length); }
#endif
					break;
				default		:

					/* Add Child Control then Drop Semaphore */
					/* ------------------------------------- */
					AddChildWorker( cptr );
					HttpSemaphore(-1);
#ifdef	WITH_VERBOSE
					if ( verbose & 512 ) { printf("ParentProcess(%u) starting for HttpPutFile(%s) : mode=%u, length=%u \r\n",getpid(),filename,mode,length); }
#endif
					fclose( fhandle );
					return( HttpSuccess() );
				}
			}

		ret = putfile( cptr, fhandle, xbuffer, xbuflen, mode, 0);

		/* delete file after transfer */
		/* -------------------------- */
		if ( mode & 16 ) { unlink( filename ); }

		if ( mode & 8 ) {
			switch(ret) {
				case 0:
					HttpClose(handle,1);
#ifdef	WITH_VERBOSE
					if ( verbose & 512 ) { printf("ChildProcess(%u) exiting(0) after HttpPutFile(%s) \r\n",getpid(),filename); }
#endif
					exit(0);
				default:
					HttpClose(handle,1);
#ifdef	WITH_VERBOSE
					if ( verbose & 512 ) { printf("ChildProcess(%u) exiting(%u) during HttpPutFile(%s) \r\n",getpid(),ret,filename); }
#endif
					exit(ret);
				}
			}
		else 	{
			switch(ret) {
				case 0 : return( HttpSuccess() );
				default: return( HttpFailure(ret) );
				}
			}
#elif defined (WIN32)
		/* Multi-tache possible avec les threads */

		if (mode & 8)
			{
			CONNECTIONPTR	cptr_clone;
			HANDLE hThread; 
			T_ThreadHttpPutFile* pParam;
			DWORD ThreadId;

			if ((xbuffer = allocate(xbuflen)) == 0)
				{
				fclose( fhandle );
				return( HttpFailure( 27 ) );
					}

			if ((pParam = allocate(sizeof(T_ThreadHttpPutFile))) == 0)
				{
				liberate(xbuffer);
				fclose( fhandle );
				return( HttpFailure( 27 ) );
				}

			if ((cptr_clone = copy_connection(cptr)) == 0)
				{
				liberate(xbuffer);
				liberate(pParam);
				fclose( fhandle );
				return( HttpFailure( 27 ) );
			}

			pParam->handle  = handle;
			pParam->cptr    = cptr_clone;
			pParam->fhandle = fhandle;
			pParam->xbuffer = xbuffer;
			pParam->xbuflen = xbuflen;
			pParam->mode    = mode;

			MI_TRACE((CI_TRA_F_DEBUG,0x0002,"HttpPutFile","cptr->socket=%lu",cptr->socket));
			MI_TRACE((CI_TRA_F_DEBUG,0x0002,"HttpPutFile","cptr->newsocket=%lu",cptr->newsocket));
			MI_TRACE((CI_TRA_F_DEBUG,0x0002,"HttpPutFile","cptr_clone->socket=%lu",cptr_clone->socket));
			MI_TRACE((CI_TRA_F_DEBUG,0x0002,"HttpPutFile","cptr_clone->newsocket=%lu",cptr_clone->newsocket));
			MI_TRACE((CI_TRA_F_DEBUG,0x0002,"HttpPutFile","avant CreateThread"));
			hThread = CreateThread(NULL,0,ThreadPutFile,pParam,0,&ThreadId);
			MI_TRACE((CI_TRA_F_DEBUG,0x0002,"HttpPutFile","apres CreateThread (%04X)",(WORD)ThreadId));
			if (hThread == NULL) 
				{
				fclose( fhandle );
				return( HttpFailure( 38 ) );
				}
			else 
				{
				cptr->worker=(int)hThread;
				return( HttpSuccess() );
				}
			}
		else
			{
			ret = putfile( cptr, fhandle, xbuffer, xbuflen, mode, &g_TraCtx);
			switch(ret) 
				{
				case 0 : return( HttpSuccess() );
				default: return( HttpFailure(ret) );
				}
			}

#else
		/* Pas de multi-tache */
		ret = putfile( cptr, fhandle, xbuffer, xbuflen, mode);
		switch(ret) {
			case 0 : return( HttpSuccess() );
			default: return( HttpFailure(ret) );
			}

#endif
		}

}


PUBLIC	unsigned long	HttpFileSize(filename,length,mode)
	BPTR	filename;
	WORD	length;
	WORD	mode;		/* Text file : 1, Binary 0 */
{
	WORD		l;
	WORD		i;
	WORD		eoftext=0;
	FILE *		fhandle;
	unsigned long	filesize=0L;
	struct stat info;
	if (!( mode ))
	{
		if ( stat(filename,&info) < 0 )
			return(0);
		else 	return(info.st_size);
	}
	else if ((fhandle = fopen( filename, "rb" )) == (FILE *) 0) {
		return( HttpFailure( 40 ) );
		}
	else	{
		while ((l=filereader(fhandle,ClientNameBuffer,256)) != 0 ) {
			if ((mode)) {
				for (i=0; i < l; i++ ) {
					if ((eoftext = ClientNameBuffer[i]) == 0x001A ) {
						l = i;
						break;
						}
					}
				}
			if (!( l ))
				break;
			filesize += l;
			if ( eoftext == 0x001A )
				break;
			}
		fclose( fhandle );
		return( filesize );
		}

}


PUBLIC	int	HttpGetFile(handle,filename,length,bytes)
	WORD		handle;
	BPTR		filename;
	WORD		length;
	unsigned long	bytes;
{
	unsigned long 	i=0L;
	int		c;
	CONNECTIONPTR	cptr;
	FILE *		fhandle;
	VPTR		object=(VPTR) 0;

	int	status;
#ifndef	ABAL64
	if ((status = (*gps)(1,0,0)) != 0)
		return( HttpFailure(status) );
	else if ((status = (*gps)(2,0,0)) != 0)
		return( HttpFailure(status) );
#endif
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0)) {
		return( HttpFailure( 50 ) );
		}
	handle = (cptr->status & _URL_LISTEN ? cptr->newsocket : cptr->socket );
	object = (cptr->status & _URL_LISTEN ? cptr->newobject : cptr->object );

	if ((fhandle = fopen( filename, "wb" )) == (FILE *) 0) {
		return( HttpFailure( 46 ) );
		}
	else	{
		for (i=0; i < bytes; i++ ) {

			if (( SelectTimer )
			&&  (!(select_connection( handle, SelectTimer ))))
				return( 27 );
	
#if defined(UNIX) || defined(WIN32)
#ifdef	SYSTEM_SSL
			if ( object )
				c = ssl_tcp_readb( object );
			else
#endif
			 	c = tcp_readb( handle );
#else
			 	c = tcp_readb( handle );
#endif
			if ( verbose ) { printf("%u ",(c&0x00FF)); }
			if ( c > 255 )
				break;
			else	{

				if ( TransCode ) { c = GetSet[c]; }
				fputc(c,fhandle);
				}
			}			
#ifdef	PROLOGUE
		fputc(0x001A,fhandle);
#endif
		fclose( fhandle );
		return( HttpSuccess() );
		}

}

PUBLIC	int	HttpPutByte(handle,value)
	WORD	handle;
	WORD	value;
{
	CONNECTIONPTR	cptr;
	BYTE	buffer[2];
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure( 50 ) );
	else	{
		buffer[0] = (value & 0x00FF);
		if ( TransCode )
			buffer[0] = PutSet[buffer[0]];
		if (!( http_put( cptr, buffer, 1 ) ))
			return( HttpFailure(2) );
		else	return( HttpSuccess()  );
		}
}

PUBLIC	int	HttpPutLine(handle,buffer,length)
	WORD	handle;
	BPTR	buffer;
	WORD	length;
{
	WORD	i;
	CONNECTIONPTR	cptr;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure( 50 ) );
	else 	
	{
		if ( TransCode )
			for ( i=0; i < length; i++ )
				*(buffer + i) = PutSet[*(buffer+i)];

		if (!( http_put( cptr, buffer, length ) ))
			return( HttpFailure(2) );
		else	return( HttpSuccess()  );
	}
}

PUBLIC	int	HttpPutResponse(handle,response,message,length)
	WORD	handle;
	WORD	response;
	BPTR	message;
	WORD	length;
{
	WORD	i;
	sprintf(ClientNameBuffer,"HTTP/%c.%c %03u %s\r\n",HttpGetMajor(),HttpGetMinor(),(unsigned int)response,message);
	for (i=0; ClientNameBuffer[i]; i++) {
		if ( ClientNameBuffer[i] = 0x000A ) {
			i++;
			break;
			}
		}			
	return( HttpPutLine( handle, ClientNameBuffer, i ) );
}

PUBLIC	int	HttpKeepAlive(handle,status)
	WORD	handle;
	WORD	status;
{
	CONNECTIONPTR	cptr;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure(50) );
	else 	{
		if ( status ) 
			keep_connection_alive( cptr );
		else	connection_not_alive( cptr );
		return( HttpSuccess() );
		}
}

PUBLIC	VOID	HttpSetAuthorize( pptr )
	BPTR 	pptr;
{
	(void) http_set_authorization( pptr );
	return;
}

PUBLIC	VOID	HttpProxyAuthorize( pptr )
	BPTR 	pptr;
{
	(void) http_set_proxy_authorization( pptr );
	return;
}

PUBLIC	int	HttpCryptage(handle, pptr, blen, mode )
	WORD	handle;
	BPTR 	pptr;
	WORD	blen;
	WORD	mode;
{
	CONNECTIONPTR	cptr;
	if (( handle >= MAX_CONNECTIONS )
	||  ((cptr = ConnectionTable[handle]) == (CONNECTIONPTR) 0))
		return( HttpFailure(50) );
	else	{
		cptr->cryptage = reset_cryptage( &cptr->coding        );
		if ( mode )
			cptr->cryptage = start_cryptage( &cptr->coding, pptr, blen, mode  );
		return( cptr->cryptage );
		}
}

#endif 	/* _HTTPFUNC_C */
	/* ----------- */



