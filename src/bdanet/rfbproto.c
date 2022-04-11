/*
 *  Copyright (C) 1999 AT&T Laboratories Cambridge.  All Rights Reserved.
 *
 *  This is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This software is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this software; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 *  USA.
 */

/*
 * rfbproto.c - functions to deal with client side of RFB protocol.
 */

#ifndef	_rfbproto_c
#define	_rfbproto_c

#define	_RAW_ENCODING		True
#define	_COPY_ENCODING		True
#define	_RRE_ENCODING		True
#define	_RRE_ENCODING16		True
#define	_CORRE_ENCODING		True
#define	_CORRE_ENCODING16	True

extern	int	MaxMode;
extern	int	usegraphics;
extern	int	cellwidth;
extern	int	cellheight;

#define	Random() (random() & 0x7FFF)

int	ClientIsReady=0;
int	InitialRequest=1;
int	UpdatePending=0;

int	TopCol=0;
int	TopLin=0;
int	EndCol=0;
int	EndLin=0;

char	RfbSemaphore=0;



/*
 * The following definitions may eventually be used to activate
 * the various optional encodings.
 * They are all un-supported for now
 */

/* #define	_RRE_ENCODING32		False	*/
/* #define	_CORRE_ENCODING32	False	*/
/* #define	_HEXTILE_ENCODING	False	*/



#ifdef	UNIX
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include "vncview.h"
#include "vncauth.h"
#else
#include <errno.h>
#include ".\include\sys\types.h"
#include ".\include\netdb.h"
#include ".\include\sys\socket.h"
#include ".\include\netinet\in.h"
unsigned long inet_addr( char * );

int	MouseButtons=0;
int	RefreshRequired=0;

#include "boolean.h"
#include "vncerror.h"
#include "vncview.h"
#include "vncauth.h"
#include "guimouse.h"
#include "rfbcico.h"

#endif

#include "ipx.h"
extern	int	VncTransport;
extern	unsigned char	VgaBgr233[256];
extern	unsigned short	VgaBgr555[256];



#ifdef	_RRE_ENCODING
static Bool HandleRRE8(int rx, int ry, int rw, int rh);
#endif
#ifdef	_RRE_ENCODING16
static Bool HandleRRE16(int rx, int ry, int rw, int rh);
#endif
#ifdef	_RRE_ENCODING32
static Bool HandleRRE32(int rx, int ry, int rw, int rh);
#endif
#ifdef	_CORRE_ENCODING
static Bool HandleCoRRE8(int rx, int ry, int rw, int rh);
#endif
#ifdef	_CORRE_ENCODING16
static Bool HandleCoRRE16(int rx, int ry, int rw, int rh);
#endif
#ifdef	_CORRE_ENCODING32
static Bool HandleCoRRE32(int rx, int ry, int rw, int rh);
#endif
#ifdef	_HEXTILE_ENCODING
static Bool HandleHextile8(int rx, int ry, int rw, int rh);
static Bool HandleHextile16(int rx, int ry, int rw, int rh);
static Bool HandleHextile32(int rx, int ry, int rw, int rh);
#endif

int rfbsock;
char *desktopName;
rfbPixelFormat myFormat;
rfbServerInitMsg si;
char *serverCutText = NULL;
Bool newServerCutText = False;

int endianTest = 1;


/* note that the CoRRE encoding uses this buffer and assumes it is big enough
   to hold 255 * 255 * 32 bits -> 260100 bytes.  640*480 = 307200 bytes */
/* also hextile assumes it is big enough to hold 16 * 16 * 32 bits */

#define BUFFER_SIZE 4096		/* 2 * 1200  plus a lot more in case */

static char buffer[BUFFER_SIZE];


Bool	CheckRFBVersion( char * vptr, int * major, int * minor )
{
	*major = *minor = 0;

	if (( *vptr     == 'R' )
	&&  ( *(vptr+1) == 'F' )
	&&  ( *(vptr+2) == 'B' )
	&&  ( *(vptr+3) == ' ' )
	&&  ( *(vptr+7) == '.' )
	&&  ( *(vptr+11) == 10 )) {
		
		vptr = convert_integer( ( vptr + 4), major );
		if ( *(vptr++) != '.' )
			return( False );
		
		vptr = convert_integer( vptr, minor );

		if ( *vptr != 10 )
			return( False );

		if ( *major != rfbProtocolMajorVersion )
			return( False );
		else	return( True );

		}
	else	return( False );

}

/*
 * ConnectToRFBServer.
 */

Bool	ConnectToRFBServer(const char *hostname, int port)
{
#ifdef	UNIX
	unsigned int host;
#else
	unsigned long host;
#endif
	if ( debug )
		printf("ConnectToRFBServer(%s,%u)\n",hostname,port);

	if ( VncTransport == IPX_TRANSPORT ) {
		if ((rfbsock = ConnectToIpxHost( hostname )) < 0) {
			vnc_connect_error();
			return( False );
			}
		else	return( True );
		}
	else if (!StringToIPAddr(hostname, &host)) {
		vnc_name_error();
		return( False );
		}
	else if (( rfbsock = ConnectToTcpAddr(host, port)) < 0) {
		vnc_connect_error();
		return( False );
		}
	else	return( SetNonBlocking(rfbsock) );
}


int	GetFramebufferWidth() { return( si.framebufferWidth ); }
int	GetFramebufferHeight() { return( si.framebufferHeight ); }

static	void	swap_si_fields()
{
	si.framebufferWidth = Swap16IfLE(si.framebufferWidth);
	si.framebufferHeight = Swap16IfLE(si.framebufferHeight);
	si.format.redMax = Swap16IfLE(si.format.redMax);
	si.format.greenMax = Swap16IfLE(si.format.greenMax);
	si.format.blueMax = Swap16IfLE(si.format.blueMax);
	si.nameLength = Swap32IfLE(si.nameLength);
	return;
}


/*
 * InitialiseRFBConnection.
 */

Bool	InitialiseRFBConnection()
{
	rfbProtocolVersionMsg pv;
	int major,minor;
	CARD32 authScheme, reasonLen, authResult;
	char *reason;
	CARD8 challenge[CHALLENGESIZE];
	char *passwd;
	int i;
	rfbClientInitMsg ci;

	/* if the connection is immediately closed, don't report anything, so
			 that pmw's monitor can make test connections */

#ifdef	UNIX
	if (listenSpecified)
#endif
		errorMessageOnReadFailure = False;

	if (!ReadFromRFBServer(pv, sz_rfbProtocolVersionMsg)) return False;

	errorMessageOnReadFailure = True;

	pv[sz_rfbProtocolVersionMsg] = 0;

	if (!(  CheckRFBVersion( & pv, &major, &minor ) )) {
		vnc_server_error();
		return False;
		}

	if ( verbose )
		printf("VNC server supports protocol version %d.%d (viewer %d.%d)\n",
			major, minor, rfbProtocolMajorVersion, rfbProtocolMinorVersion);

	major = rfbProtocolMajorVersion;
	minor = rfbProtocolMinorVersion;

	sprintf(pv,rfbProtocolVersionFormat,major,minor);

	if (!WriteExact(rfbsock, pv, sz_rfbProtocolVersionMsg)) return False;

	if (!ReadFromRFBServer((char *)&authScheme, 4)) return False;

	authScheme = Swap32IfLE(authScheme);

	switch (authScheme) {

	case rfbConnFailed:
		
		if (!ReadFromRFBServer((char *)&reasonLen, 4)) return False;
		reasonLen = Swap32IfLE(reasonLen);

		reason = malloc(reasonLen);

		if (!ReadFromRFBServer(reason, reasonLen)) {
			free( reason );
			return False;
			}

		if ( verbose )
			printf("VNC connection failed: %.*s\n",(int)reasonLen, reason);

		free( reason );
		return False;

	case rfbNoAuth:
		if ( verbose )
			printf("No authentication needed\n");
		break;

	case rfbVncAuth:
		if (!ReadFromRFBServer((char *)challenge, CHALLENGESIZE)) 
			return False;

		if (appData.passwordFile) {
			passwd = vncDecryptPasswdFromFile(appData.passwordFile);
			if (!passwd) {
				if ( verbose )
					printf("Cannot read valid password from file \"%s\"\n",	appData.passwordFile);
				return False;
				}
			} 
		else if (appData.passwordDialog) {
			passwd = DoPasswordDialog();
			} 
		else 	{
			passwd = getpass("Password: ");
			}

		if ((!passwd) || (strlen(passwd) == 0)) {
			if ( verbose )
				printf("Reading password failed\n");
			return False;
			}
		if (strlen(passwd) > 8) {
			passwd[8] = '\0';
			}

		vncEncryptBytes(challenge, passwd);

		/* Lose the password from memory */
		for (i = strlen(passwd); i >= 0; i--) {
			passwd[i] = '\0';
			}

		if (!WriteExact(rfbsock, challenge, CHALLENGESIZE)) 
			return False;

		if (!ReadFromRFBServer((char *)&authResult, 4)) 
			return False;

		authResult = Swap32IfLE(authResult);

		switch (authResult) {

			case rfbVncAuthOK:
				if ( verbose )
					printf("VNC authentication succeeded\n");
				break;

			case rfbVncAuthFailed:
				if ( verbose )
					printf("VNC authentication failed\n");
				return False;

			case rfbVncAuthTooMany:
				if ( verbose )
					printf("VNC authentication failed - too many tries\n");
				return False;

			default:
				if ( verbose )
					printf("Unknown VNC authentication result: %d\n",(int)authResult);
				return False;
				}

		break;

	default:
		if ( verbose )
			printf("Unknown authentication scheme from VNC server: %d\n", (int)authScheme);
		return False;
	}

	if ( terminate )
		ci.shared = 2;
	else	ci.shared = (IsExclusive ? 0 : 1 );	/* Was appData.shareDesktop ? 1 : 0 */

	if (!WriteExact(rfbsock, (char *)&ci, sz_rfbClientInitMsg)) 
		return False;

	if ( debug )
		printf("get server characteristics\n");

	if (!ReadFromRFBServer((char *)&si, sz_rfbServerInitMsg)) 
		return False;

	swap_si_fields();

	desktopName = malloc(si.nameLength + 1);

	if ( debug )
		printf("get server desktop name\n");

	if (!ReadFromRFBServer(desktopName, si.nameLength)) 
		return False;

	desktopName[si.nameLength] = 0;

	if ( verbose ) {
		printf("Desktop name \"%s\"\n",desktopName);

		printf("Connected to VNC server, using protocol version %d.%d\n",
			rfbProtocolMajorVersion, rfbProtocolMinorVersion);

		printf("VNC server default format:\n");

		PrintPixelFormat(&si.format);
		}

	return True;
}

int	StartRFBConnection(int sock)
{
	rfbProtocolVersionMsg pv;
	int major,minor;
	CARD32 authScheme, reasonLen, authResult;
	char *reason;
	CARD8 challenge[CHALLENGESIZE];
	CARD8 authority[CHALLENGESIZE];
	char *passwd;
	int i;
	rfbClientInitMsg ci;

	major = rfbProtocolMajorVersion;
	minor = rfbProtocolMinorVersion;

	sprintf(pv,rfbProtocolVersionFormat,major,minor);

	if (!WriteExact(sock, pv, sz_rfbProtocolVersionMsg)) return False;

	if (!ReadFromRFBClient(sock, pv, sz_rfbProtocolVersionMsg)) return False;

	pv[sz_rfbProtocolVersionMsg] = 0;

	if (!(  CheckRFBVersion( & pv, &major, &minor ) )) {
		vnc_client_error();
		return False;
		}

	if ( verbose )
		printf("VNC client protocol version %d.%d (server %d.%d)\n",
			major, minor, rfbProtocolMajorVersion, rfbProtocolMinorVersion);

	/* If no password has been provided then no authentication is needed */
	
	if (appData.passwordDialog) {
		passwd = DoPasswordDialog();
		} 

	else 	{
		passwd = getpass("Password: ");
		}

	if (!( passwd )) {
		authScheme = rfbNoAuth;
		authScheme = Swap32IfLE(authScheme);
		if ( verbose )
			printf("no authentication scheme\n");
		if (!WriteExact(sock,(char *) &authScheme, 4 )) return(False);
		}
	else	{
		authScheme = rfbVncAuth;
		authScheme = Swap32IfLE(authScheme);
		if ( verbose )
			printf("authentication required\n");

		if (!WriteExact(sock,(char *) &authScheme, 4 )) return(False);

		/* Generate and issue challenge bytes */
		vncRandomBytes(& challenge );
		if (!WriteExact(sock, challenge, CHALLENGESIZE))  return False;

		vncEncryptBytes(challenge, passwd);

		if (!ReadFromRFBClient(sock,(char *)authority, CHALLENGESIZE)) return False;

		for (i=0; i < CHALLENGESIZE; i++ )
			if ( authority[i] != challenge[i] )
				break;

		if ( i < CHALLENGESIZE ) {
			/* Whoops failure */
			authResult = rfbVncAuthFailed;
			if (!WriteExact(sock,(char *) &authResult, 4 )) return(False);
			if ( verbose )
				printf("authentication failure\n");

			return(False);

			}
		else	{
			/* Yes */

			authResult = rfbVncAuthOK;
			if (!WriteExact(sock,(char *) &authResult, 4 )) return(False);
			if ( verbose )
				printf("authentication success\n");

			}
		}

	if (!ReadFromRFBClient(sock,(char *)&ci,sz_rfbClientInitMsg)) 
		return False;

	switch ( ci.shared ) {
		case	1	:
			if ( verbose )
				printf("client sharing application\n");
			break;

		case	0	:
			if ( verbose )
				printf("client exclusive\n");
			break;

		case	2	:
			if ( verbose )
				printf("client request for termination ");

			if ( terminate ) {
				if ( verbose )
					printf("accepted\n");
				return( -1 );
				}
			else if ( verbose )
				printf("ignored\n");

		}

	/* Server Initialisation */

	if ( debug )
		printf("send server characteristics\n");

	swap_si_fields();

	if (!(WriteExact(sock,(char *)&si, sz_rfbServerInitMsg)))
		return(False);

	swap_si_fields();

	if ( debug )
		printf("send server desktopname : %s\n",desktopName);

	if (!(WriteExact(sock,desktopName, si.nameLength )))
		return(False);

	return( True );
}


/*
 * SetFormatAndEncodings.
 */

void	pixel_format_bgr233_8()
{
	myFormat.bitsPerPixel = 8;
	myFormat.depth = 8;
	myFormat.trueColour = 1;
	myFormat.bigEndian = 0;
	myFormat.redMax = 7;
	myFormat.greenMax = 7;
	myFormat.blueMax = 3;
	myFormat.redShift = 0;
	myFormat.greenShift = 3;
	myFormat.blueShift = 6;
	return;
}

void	pixel_format_bgr555_16()
{
	myFormat.bitsPerPixel = 16;
	myFormat.depth = 32;
	myFormat.trueColour = 1;
	myFormat.bigEndian = 1;
	myFormat.redMax = 0x01F;
	myFormat.greenMax = 0x01F;
	myFormat.blueMax = 0x01F;
	myFormat.redShift = 0;
	myFormat.greenShift = 5;
	myFormat.blueShift = 10;
	return;
}

Bool	SetFormatAndEncodings()
{
	rfbSetPixelFormatMsg spf;
	char buf[sz_rfbSetEncodingsMsg + MAX_ENCODINGS * 4];
	rfbSetEncodingsMsg *se = (rfbSetEncodingsMsg *)buf;
	CARD32 *encs = (CARD32 *)(&buf[sz_rfbSetEncodingsMsg]);
	int len = 0;

	spf.type = rfbSetPixelFormat;
	spf.format = myFormat;
	spf.format.redMax = Swap16IfLE(spf.format.redMax);
	spf.format.greenMax = Swap16IfLE(spf.format.greenMax);
	spf.format.blueMax = Swap16IfLE(spf.format.blueMax);

	if (!WriteExact(rfbsock, (char *)&spf, sz_rfbSetPixelFormatMsg))
		return False;

	spf.format.redMax = Swap16IfLE(spf.format.redMax);
	spf.format.greenMax = Swap16IfLE(spf.format.greenMax);
	spf.format.blueMax = Swap16IfLE(spf.format.blueMax);

	se->type = rfbSetEncodings;
	se->nEncodings = 0;

#ifdef	UNIX
	if (appData.encodingsString) {
		char *encStr = appData.encodingsString;
		int encStrLen;
		do {
			char *nextEncStr = strchr(encStr, ' ');
			if (nextEncStr) {
				encStrLen = nextEncStr - encStr;
				nextEncStr++;
				} 
			else 	{
				encStrLen = strlen(encStr);
				}
			if (strncasecmp(encStr,"raw",encStrLen) == 0) {
				encs[se->nEncodings++] = Swap32IfLE(rfbEncodingRaw);
				} 
			else if (strncasecmp(encStr,"copyrect",encStrLen) == 0) {
				encs[se->nEncodings++] = Swap32IfLE(rfbEncodingCopyRect);
				} 
			else if (strncasecmp(encStr,"hextile",encStrLen) == 0) {
				encs[se->nEncodings++] = Swap32IfLE(rfbEncodingHextile);
				} 
			else if (strncasecmp(encStr,"corre",encStrLen) == 0) {
				encs[se->nEncodings++] = Swap32IfLE(rfbEncodingCoRRE);
				} 
			else if (strncasecmp(encStr,"rre",encStrLen) == 0) {
				encs[se->nEncodings++] = Swap32IfLE(rfbEncodingRRE);
				} 
			else 	{
				printf("Unknown encoding '%.*s'\n",encStrLen,encStr);
				}
			encStr = nextEncStr;
			} 
		while (encStr && se->nEncodings < MAX_ENCODINGS);
		} 
	else 	{
		if (SameMachine(rfbsock)) {
			printf("Same machine: preferring raw encoding\n");
			encs[se->nEncodings++] = Swap32IfLE(rfbEncodingRaw);
			}

		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingCopyRect);
		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingHextile);
		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingCoRRE);
		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingRRE);

		}

#else

	/* Not UNIX : Must be PROLOGUE : indicate encoding supported */
	/* --------------------------------------------------------- */

#ifdef	_HEXTILE_ENCODING	
	if ( MaxMode >= 4 )
		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingHextile);
#endif

#ifdef	_CORRE_ENCODING		
	if ( MaxMode >= 3 )
		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingCoRRE);
#endif

#ifdef	_RRE_ENCODING		
	if ( MaxMode >= 2 )
		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingRRE);
#endif

#ifdef	_COPY_ENCODING		
	if ( MaxMode >= 1 )
		encs[se->nEncodings++] = Swap32IfLE(rfbEncodingCopyRect);
#endif
	/* Raw encoding must always be true */
	encs[se->nEncodings++] = Swap32IfLE(rfbEncodingRaw);

#endif
	len = sz_rfbSetEncodingsMsg + se->nEncodings * 4;

	se->nEncodings = Swap16IfLE(se->nEncodings);

	if (!WriteExact(rfbsock, buf, len)) return False;

	return True;
}


/*
 * SendIncrementalFramebufferUpdateRequest.
 */

Bool	SendIncrementalFramebufferUpdateRequest()
{
	if (!( RefreshRequired ))
		return( True );

	if ( verbose )
		printf("sending rfbIncrementalFrameBufferUpdateRequest()\n");

	RefreshRequired = 0;

	return (
		SendFramebufferUpdateRequest(
			0, 0, si.framebufferWidth,
			si.framebufferHeight, True
			)
		);
}


/*
 * SendInitialFramebufferUpdateRequest.
 */

Bool	SendInitialFramebufferUpdateRequest()
{
	if ( verbose )
		printf("sending rfbInitialFrameBufferUpdateRequest()\n");

	RefreshRequired = 0;

	return (
		SendFramebufferUpdateRequest(
			0, 0, si.framebufferWidth,
			si.framebufferHeight, False
			)
		);
}


/*
 * SendFramebufferUpdateRequest.
 */

Bool	SendFramebufferUpdateRequest(int x, int y, int w, int h, Bool incremental)
{
	rfbFramebufferUpdateRequestMsg fur;

	fur.type = rfbFramebufferUpdateRequest;
	fur.incremental = incremental ? 1 : 0;
	fur.x = Swap16IfLE(x);
	fur.y = Swap16IfLE(y);
	fur.w = Swap16IfLE(w);
	fur.h = Swap16IfLE(h);

	if (!WriteExact(rfbsock, (char *)&fur, sz_rfbFramebufferUpdateRequestMsg))
		return False;

	return True;
}


/*
 * SendPointerEvent.
 */

Bool	SendPointerEvent(int x, int y, int buttonMask)
{
	rfbPointerEventMsg pe;

	pe.type = rfbPointerEvent;
	pe.buttonMask = buttonMask;
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if ( verbose )
		printf("sending rfbPointerEvent(x=%u,y=%u,0x00%x)\n",x,y,buttonMask);
	pe.x = Swap16IfLE(x);
	pe.y = Swap16IfLE(y);
	return WriteExact(rfbsock, (char *)&pe, sz_rfbPointerEventMsg);
}


/*
 * SendKeyEvent.
 */

Bool	SendKeyEvent(CARD32 key, Bool down)
{
	rfbKeyEventMsg ke;
	int		ikey;
	if ( verbose ) {
		ikey = key;
		printf("sending rfbKeyEvent(k=0x%x,%u)\n",ikey,down);
		}
	ke.type = rfbKeyEvent;
	ke.down = down ? 1 : 0;
	ke.key = Swap32IfLE(key);
	return WriteExact(rfbsock, (char *)&ke, sz_rfbKeyEventMsg);
}


Bool	SendCharacter( int c )
{
	c &= 0x00FF;
	switch ( c ) {
		case	_CICO_INSERT : c = _RFB_INSERT; break;
		case	_CICO_DELETE : c = _RFB_DELETE; break;
		case	_CICO_DOWN   : c = _RFB_DOWN; break;
		case	_CICO_UP     : c = _RFB_UP; break;
		case	_CICO_LEFT   : c = _RFB_LEFT; break;
		case	_CICO_RIGHT  : c = _RFB_RIGHT; break;
		case	_CICO_PUP    : c = _RFB_PUP; break;
		case	_CICO_PDOWN  : c = _RFB_PDOWN; break;
		case	_CICO_HOME   : c = _RFB_HOME; break;
		case	_CICO_END    : c = _RFB_END; break;
		case	_CICO_ESC    : c = _RFB_ESC; break;
		case	_CICO_TAB    : c = _RFB_TAB; break;
		case	_CICO_CR     : c = _RFB_CR; break;
		}

	if (! SendKeyEvent( c , 1 ) )
		return( False );
	else if (! SendKeyEvent( c, 0 ) )
		return( False );
	else	return( True );

}

Bool	SendMouseEvent( int c, int l, int t, int b )
{
	int	x=0;
	int	y=0;

	switch ( t ) {

		case	_MIMO_WHILE_DOWN	:
			MouseButtons |= b;
			if ( verbose )
				printf("MIMO WHILE DOWN( %u, %u, %u)\n",c,l,b);
			break;

		case	_MIMO_DOWN		:

			MouseButtons |= b;
			if ( verbose )
				printf("MIMO DOWN( %u, %u, %u)\n",c,l,b);
			break;

		case	_MIMO_UP	:
			if ( b )
				MouseButtons &= ~b;
			if ( verbose )
				printf("MIMO UP( %u, %u, %u)\n",c,l,b);
			break;

		case	_MIMO_DOUBLE	:
			if ( verbose )
				printf("MIMO DOUBLE( %u, %u, %u)\n",c,l,b);
			if (!( SendMouseEvent( c,l, _MIMO_CLICK, b ) ))
				return(False);
			else if (!( SendMouseEvent( c,l, _MIMO_CLICK, b ) ))
				return(False);
			else	return(True );

		case	_MIMO_CLICK	:
			if ( verbose )
				printf("MIMO CLICK( %u, %u, %u)\n",c,l,b);
			if (!( SendMouseEvent( c,l, _MIMO_DOWN, b ) ))
				return(False);
			else if (!( SendMouseEvent( c,l, _MIMO_UP, b ) ))
				return(False);
			else	return(True );

		case	_MIMO_MOVE		:

			MouseButtons = 0;
			if ( verbose )
				printf("MIMO MOVE( %u, %u, %u)\n",c,l,b);
			break;

		default		:
			if ( verbose )
				printf("MIMO EVENT(0x%x, %u, %u, %u)\n",t,c,l,b);
		

		}

	c--; l--;

	x = (int) (( ((long) c) * si.framebufferWidth) / 140);
	y = (int) (( ((long) l) * si.framebufferHeight) / 140);

	return( SendPointerEvent(x, y, MouseButtons ) );

}

/*
 * SendClientCutText.
 */

Bool	SendClientCutText(char *str, int len)
{
	rfbClientCutTextMsg cct;

	if (serverCutText)
		free(serverCutText);
	serverCutText = NULL;

	cct.type = rfbClientCutText;
	cct.length = Swap32IfLE(len);
	return	(WriteExact(rfbsock, (char *)&cct, sz_rfbClientCutTextMsg) &&
		 WriteExact(rfbsock, str, len));
}


Bool	 HandleSetPixelFormat(int sock,int type) 
{
	rfbSetPixelFormatMsg	msg;
	if (!( ReadFromRFBClient(sock,(((char *) &msg)+1),(sz_rfbSetPixelFormatMsg-1)) ))
		return( False );
	else	{
		if ( verbose )
			printf("rfbSetPixelFormat()\n");
		return( True );
		}
}

Bool	 HandleFixColourMapEntries(int sock,int type) 
{
	rfbFixColourMapEntriesMsg	msg;
	if (!( ReadFromRFBClient(sock,(((char *) &msg)+1),(sz_rfbFixColourMapEntriesMsg-1)) ))
		return( False );
	else	{
		if ( verbose )
			printf("rfbFixColourMapEntries()\n");
		return( True );
		}
}

Bool	 HandleSetEncodings(int sock,int type) 
{
	int	i;
	char buf[sz_rfbSetEncodingsMsg + MAX_ENCODINGS * 4];
	rfbSetEncodingsMsg *se = (rfbSetEncodingsMsg *)buf;
	CARD32 *encs = (CARD32 *)(&buf[sz_rfbSetEncodingsMsg]);

	if (!( ReadFromRFBClient(sock,(((char *)se)+1),(sz_rfbSetEncodingsMsg-1)) ))
		return( False );
	if ( verbose )
		printf("rfbSetEncodings()\n");

	se->nEncodings = Swap16IfLE(se->nEncodings);

	ClientEncodings = 1;

	if ( se->nEncodings > 0 ) {
		if (!( ReadFromRFBClient(sock,(char *)encs,(se->nEncodings * 4)) ))
			return( False );

		for (ClientEncodings=0, i=0; i < se->nEncodings; i++ ) {
			*encs = Swap32IfLE( *encs );

			switch ( *encs ) {
				case	0	: ClientEncodings |= 1; break;
				case	1	: ClientEncodings |= 2; break;
				case	2	: ClientEncodings |= 4; break;
				case	4	: ClientEncodings |= 8; break;
				case	5	: ClientEncodings |= 16; break;
				default		: printf("unrecognised encoding type ignored\n");
				}
			encs++;
			}

		}

	if (!( ClientEncodings & 1 ))
		ClientEncodings |= 1;

	if ( verbose ) {
		printf("Client Encodings : ");
		if ( ClientEncodings & 1 )
			printf("raw ");
		if ( ClientEncodings & 2 )
			printf("copy ");
		if ( ClientEncodings & 4 )
			printf("RRE ");
		if ( ClientEncodings & 8 )
			printf("CoRRE ");
		if ( ClientEncodings & 16 )
			printf("hextile ");
		}


	return( True );

}

Bool	 AddPendingUpdate(int type, int atcol, int atlin, int tocol, int tolin )
{
	// Ensure mutual exclusion
	// -----------------------
	raiselock( & RfbSemaphore );
 
 	if ( InitialRequest ) {
		// An initial request must ignore and update all
		// ---------------------------------------------
		TopCol = 1;
		TopLin = 1;
		EndCol = pixel_info(3);
		EndLin = pixel_info(4);
		}

	else if (!( UpdatePending )) {
		// Otherwise if nothing waiting then set this info
		// -----------------------------------------------
		TopCol = atcol;
		TopLin = atlin;
		EndCol = tocol;
		EndLin = tolin;
		}

	else	{
		// Otherwise integrate this info into zone
		// ---------------------------------------
		if (atcol < TopCol)
			TopCol = atcol;
		if ( atlin < TopLin )
			TopLin = atlin;
		if ( tocol > EndCol )
			EndCol = tocol;
		if ( tolin > EndLin )
			EndLin = tolin;
		}

	// Indicate Update Pending and lower the semaphore
	// -----------------------------------------------
	UpdatePending = 1;
 	InitialRequest= 0;
	droplock( & RfbSemaphore );
 	return(0);
}

Bool	 HandlePendingUpdate(int sock)
{
	int	gratcol;
	int	gratlin;
	int	grnbcol;
	int	grnblin;
	int	r;
	int	i;
	int	v;
	rfbFramebufferUpdateRequestMsg	ctosmsg;
	rfbServerToClientMsg stocmsg;
	rfbFramebufferUpdateRectHeader rect;
	rfbCopyRect cr;

	raiselock( & RfbSemaphore );

	if ( InitialRequest ) {
		TopCol = 1;
		TopLin = 1;
		EndCol = pixel_info(3);
		EndLin = pixel_info(4);
		UpdatePending = 1;
		InitialRequest= 0;
		droplock( & RfbSemaphore );
		}
    
	if (!( UpdatePending )) {
		droplock( & RfbSemaphore );
		return(ClientIsReady=True);
		}
	else	{

		ClientIsReady = UpdatePending = 0;

		gratcol = rect.r.x = ((TopCol-1) * cellwidth);
		gratlin = rect.r.y = ((TopLin-1) * cellheight);
		grnbcol = rect.r.w = (((EndCol-TopCol)+1)*cellwidth);
		grnblin = rect.r.h = (((EndLin-TopLin)+1)*cellheight);

		droplock( & RfbSemaphore );

		// Send Frame Buffer Update Here 
		// -----------------------------
		stocmsg.type = 	rfbFramebufferUpdate;
		stocmsg.fu.nRects = 1;
		stocmsg.fu.nRects = Swap16IfLE(stocmsg.fu.nRects);

		if (!(WriteExact(sock,(char *)&stocmsg, sz_rfbFramebufferUpdateMsg)))
 			return(False);

		rect.encoding = rfbEncodingRaw;

		if ( verbose )
			printf("rfbEncodingRaw(%u,%u,%u,%u)\n",
				rect.r.x,rect.r.y, 
				rect.r.w,rect.r.h );

		rect.r.x = Swap16IfLE(rect.r.x);
		rect.r.y = Swap16IfLE(rect.r.y);
		rect.r.w = Swap16IfLE(rect.r.w);
		rect.r.h = Swap16IfLE(rect.r.h);
	
		rect.encoding = Swap32IfLE(rect.encoding);

		if (!(WriteExact(sock,(char *)&rect, sz_rfbFramebufferUpdateRectHeader)))
			return( False );

		for (r=0; r < grnblin; r++ ) {

			getzone(gratcol,gratlin+r,grnbcol,1,buffer);
   
			if ( PaletteMode > 8 ) {
				for (i=0; i < grnbcol; i++ ) {
					v = VgaBgr233[ (buffer[i] & 0x00FF) ];
					buffer[(grnbcol+(i*2))]   = ((v >> 8) & 0x00FF);
					buffer[(grnbcol+(i*2)+1)] = (v & 0x00FF);
					}

				if (!(WriteExact(sock,&buffer[grnbcol],(grnbcol*2))))
					return( False );

				}
			else	{
				for (i=0; i < grnbcol; i++ ) {
					buffer[i] = (VgaBgr233[ (buffer[i] & 0x00FF) ] & 0x00FF);
					}
				if (!(WriteExact(sock,buffer,grnbcol)))
					return( False );
				}
			}
			
		return( True );
		}
}

Bool	 HandleFramebufferUpdateRequest(int sock,int type) 
{
	int	dath;
	int	dathiosal;
	int	dathard;
	int	r;
	int	c;
	int	nbc;
	int	nbr;
	rfbFramebufferUpdateRequestMsg	ctosmsg;
	rfbServerToClientMsg stocmsg;
	rfbFramebufferUpdateRectHeader rect;
	rfbCopyRect cr;

	if (!( ReadFromRFBClient(sock,(((char *) &ctosmsg)+1),(sz_rfbFramebufferUpdateRequestMsg-1)) ))
		return( False );

	else	{

		if ( verbose )
			printf("rfbFrameBufferUpdateRequest()\n");

		if ( usegraphics )
			return( HandlePendingUpdate(sock) );

		else	{
			// Generate Test Data direct to output
			// -----------------------------------

			// Send Frame Buffer Update Here 
			// -----------------------------
			stocmsg.type = 	rfbFramebufferUpdate;
			stocmsg.fu.nRects = 1;
			stocmsg.fu.nRects = Swap16IfLE(stocmsg.fu.nRects);

			if (!(WriteExact(sock,(char *)&stocmsg, sz_rfbFramebufferUpdateMsg)))
				return(False);

			r = Random();
	
			if (( ClientEncodings & 2 )
			&&  ( r & 2 	  ))
			 	rect.encoding = rfbEncodingCopyRect;
			else 	rect.encoding = rfbEncodingRaw;
	
			rect.r.x = (Random() % 800);
			rect.r.y = (Random() % 600);
			rect.r.w = ((Random() % (800 - rect.r.x))+1);
			nbc = rect.r.w;
			rect.r.h = ((Random() % (600 - rect.r.y))+1);
			nbr = rect.r.h;
	
			if ( rect.encoding == rfbEncodingCopyRect ) {
	
				cr.srcX  = (Random() % 800);
				cr.srcY  = (Random() % 600);
	
				if ( verbose )
					printf("rfbEncodingCopyRect(%u,%u,%u,%u from %u,%u )\n",
						rect.r.x,rect.r.y, 
						rect.r.w,rect.r.h,
						cr.srcX,cr.srcY );
	
				rect.r.x = Swap16IfLE(rect.r.x);
				rect.r.y = Swap16IfLE(rect.r.y);
				rect.r.w = Swap16IfLE(rect.r.w);
				rect.r.h = Swap16IfLE(rect.r.h);
	
				rect.encoding = Swap32IfLE(rect.encoding);
	
				if (!(WriteExact(sock,(char *)&rect, sz_rfbFramebufferUpdateRectHeader)))
					return( False );
	
				cr.srcX = Swap16IfLE(cr.srcX);
				cr.srcY = Swap16IfLE(cr.srcY);
	
				if (!(WriteExact(sock,(char *)&cr, sz_rfbCopyRect)))
					return( False );
				else	return( True );
	
				}
	
			else if ( rect.encoding == rfbEncodingRaw ) {
	
				if ( PaletteMode > 8 )
					dath = Random();
				else	dath = (Random() & 0x00FF);
	
				if ( verbose )
					printf("rfbEncodingRaw(%u,%u,%u,%u)\n",
						rect.r.x,rect.r.y, 
						rect.r.w,rect.r.h );
	
				rect.r.x = Swap16IfLE(rect.r.x);
				rect.r.y = Swap16IfLE(rect.r.y);
				rect.r.w = Swap16IfLE(rect.r.w);
				rect.r.h = Swap16IfLE(rect.r.h);
	
				rect.encoding = Swap32IfLE(rect.encoding);
	
				if (!(WriteExact(sock,(char *)&rect, sz_rfbFramebufferUpdateRectHeader)))
					return( False );

				if ( PaletteMode > 8 ) {
					for (	dathiosal = (dath & 0x00FF),
						dathard   = (dath >> 8),
						c=0; c < nbc; c++) {
						buffer[(c*2)]=dathiosal;
						buffer[(c*2)+1]=dathard;
						}
					nbc *= 2;
					}
				else	{
					for (c=0; c < nbc; c++)
						buffer[c] = dath;
					}
	
				for (r=0; r < nbr; r++ )
					if (!(WriteExact(sock,buffer,nbc)))
						return( False );
	
				return( True );
				}
			}

		}
}


#include "stdevent.c"

Bool	 HandleKeyEvent(int sock,int type) 
{
	rfbKeyEventMsg	msg;
	int		atc;
	int		atl;
	if (!(ReadFromRFBClient(sock,(((char *) &msg)+1),(sz_rfbKeyEventMsg-1)) ))
		return( False );
	else 	{
		msg.key = Swap32IfLE( msg.key );
		if ( verbose ) 
			printf("rfbKeyEvent( key=%u, mode=%u )\n",((int) msg.key & 0xFFFF),msg.down);

		if (!( StandardKeyEvent(msg.key, msg.down) ))
			return( False );
		if ( usegraphics ) {
			if (!( msg.down )) {
				atc = pixel_info(1);
				atl = pixel_info(2);
				PixelPutc( (msg.key & 0x00FF) );
				raiselock( & RfbSemaphore );
				if (!(UpdatePending)) {
					TopCol = EndCol = atc;
					TopLin = EndLin = atl;
					}
				else	{
					if ( atc < TopCol )
						TopCol = atc;
					if ( atc > EndCol )
						EndCol = atc;
					if ( atl < TopLin )
						TopLin = atl;
					if ( atl > EndLin )
						EndLin = atl;
					}
				UpdatePending=1;
				droplock( & RfbSemaphore );
				if ( ClientIsReady )
					return( HandlePendingUpdate( sock ) );					
				}
    			}
		return(True);
		}
}

Bool	 HandlePointerEvent(int sock,int type) 
{
	rfbPointerEventMsg	msg;
	if (!( ReadFromRFBClient(sock,(((char *) &msg)+1),(sz_rfbPointerEventMsg-1)) ))
		return( False );
	else 	{
		msg.x = Swap16IfLE( msg.x );
		msg.y = Swap16IfLE( msg.y );
		if ( verbose )
			printf("rfbPointerEvent(x=%u,y=%u,buttons=%x)\n",msg.x,msg.y,msg.buttonMask);

		return( StandardPointerEvent( msg.x, msg.y, msg.buttonMask ) );

		}
}

Bool	 HandleClientCutText(int sock,int type) 
{
	rfbClientCutTextMsg	msg;
	return( ReadFromRFBClient(sock,(((char *) &msg)+1),(sz_rfbClientCutTextMsg-1)));
}


/*
 * HandleRFBClientMessage.
 */

Bool	HandleRFBClientMessage(int sock)
{
	rfbServerToClientMsg msg;

	if ( UpdatePending )
		if ( ClientIsReady )
			 if (!( HandlePendingUpdate(sock) ))
				return( False );
	
	if (!ReadFromRFBClient(sock,(char *)&msg, 1))
		return( False );

	switch (msg.type) {

		case rfbSetPixelFormat 		:
			return( HandleSetPixelFormat(sock,msg.type) );
		case rfbFixColourMapEntries 	:
			return( HandleFixColourMapEntries(sock,msg.type) );
		case rfbSetEncodings 		:
			return( HandleSetEncodings(sock,msg.type) );
		case rfbFramebufferUpdateRequest:
			return( HandleFramebufferUpdateRequest(sock,msg.type) );
		case rfbKeyEvent 		:
			return( HandleKeyEvent(sock,msg.type) );
		case rfbPointerEvent 		:
			return( HandlePointerEvent(sock,msg.type) );
		case rfbClientCutText 		:
			return( HandleClientCutText(sock,msg.type) );


		default:
			printf("Unknown message type %d from VNC client\n",msg.type);
			return( False );
		}


}


Bool	select_connection( int sock, int delay )
{
	int		status;
	struct timeval TimeOut;
	fd_set	       rfds;
	fd_set	       wfds;
	fd_set	       xfds;
	FD_ZERO( & rfds );
	FD_ZERO( & wfds );
	FD_ZERO( & xfds );
	FD_SET( sock, & rfds );
	TimeOut.tv_sec  = (long) (delay & 0xFFFF);
	TimeOut.tv_usec = 0L;
	if ((status = select((sock+1),(void *) & rfds ,(void *) & wfds, (void *) & xfds ,(void *) & TimeOut )) > 0 )
		return(1);
	else if ( status == 0 )
		return( 0 );
	else 	{
		printf("**Error** cnx.select : %u ** \n",errno);
		return( 0 );
		}
}

Bool	rfbSelectConnection(int delay)
{
	if ( VncTransport == IPX_TRANSPORT )
		return( select_connection_ipx( rfbsock, delay ) );

	else	return( select_connection( rfbsock, delay ) );
}

/*
 * HandleRFBServerMessage.
 */

Bool	HandleRFBServerMessage()
{
	rfbServerToClientMsg msg;

	if (!ReadFromRFBServer((char *)&msg, 1))
		return False;

	switch (msg.type) {

	case rfbSetColourMapEntries:
	if ( verbose )
		printf("rfbSetColourMapEntries()\n");
	{
		int i;
		CARD16 rgb[3];
		XColor xc;

		if (!ReadFromRFBServer(((char *)&msg) + 1,
				 sz_rfbSetColourMapEntriesMsg - 1))
			return False;

		msg.scme.firstColour = Swap16IfLE(msg.scme.firstColour);
		msg.scme.nColours = Swap16IfLE(msg.scme.nColours);

		for (i = 0; i < msg.scme.nColours; i++) {
			if (!ReadFromRFBServer((char *)rgb, 6))
				return False;
			xc.pixel = msg.scme.firstColour + i;
			xc.red = Swap16IfLE(rgb[0]);
			xc.green = Swap16IfLE(rgb[1]);
			xc.blue = Swap16IfLE(rgb[2]);
			xc.flags = DoRed|DoGreen|DoBlue;
			XStoreColor(dpy, cmap, &xc);
			}

		break;
	}

	case rfbFramebufferUpdate:

	if ( verbose )
		printf("rfbFramebufferUpdate()\n");

	// This allows sender of refresh request to operate
	RefreshRequired++;

	{
		rfbFramebufferUpdateRectHeader rect;
		int linesToRead;
		int bytesPerLine;
		int i;
		int usecs;

		if (!ReadFromRFBServer(((char *)&msg.fu) + 1,
				 sz_rfbFramebufferUpdateMsg - 1))
			return False;

		msg.fu.nRects = Swap16IfLE(msg.fu.nRects);

		for (i = 0; i < msg.fu.nRects; i++) {
			if (!ReadFromRFBServer((char *)&rect, sz_rfbFramebufferUpdateRectHeader))
				return False;

			rect.r.x = Swap16IfLE(rect.r.x);
			rect.r.y = Swap16IfLE(rect.r.y);
			rect.r.w = Swap16IfLE(rect.r.w);
			rect.r.h = Swap16IfLE(rect.r.h);

			rect.encoding = Swap32IfLE(rect.encoding);

			if ((rect.r.x + rect.r.w > si.framebufferWidth) 
			||  (rect.r.y + rect.r.h > si.framebufferHeight)) {
				if ( verbose )
					printf("Rect too large: %dx%d at (%d, %d)\n",rect.r.w, rect.r.h, rect.r.x, rect.r.y);
				return False;
				}

			if ((rect.r.w == 0 )
			||  (rect.r.h == 0 )) {
				if ( verbose )
					printf("Zero size rectangle (w=%u,h=%u) - ignoring\n",
						rect.r.w,rect.r.h );
				continue;
				}
			switch (rect.encoding) {

			case rfbEncodingRaw:

#ifdef	_RAW_ENCODING
				/* ------------------------------------- */
				/* At very least RAW ENCODING must be	 */
				/* implemented otherwise nowt can happen */
				/* ------------------------------------- */
				bytesPerLine = rect.r.w * myFormat.bitsPerPixel / 8;
				linesToRead = BUFFER_SIZE / bytesPerLine;

				if ( verbose )
					printf("rfbEncodingRaw(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);

				while (rect.r.h > 0) {
					if (linesToRead > rect.r.h)
						linesToRead = rect.r.h;

					if (!ReadFromRFBServer(buffer,bytesPerLine * linesToRead))
						return False;


					CopyDataToScreen(buffer, rect.r.x, rect.r.y, rect.r.w,linesToRead);

					rect.r.h -= linesToRead;
					rect.r.y += linesToRead;

					}
				break;
#else
				return( False );
#endif

			case rfbEncodingCopyRect:

#ifdef	_COPY_ENCODING
			{
				rfbCopyRect cr;

				if (!ReadFromRFBServer((char *)&cr, sz_rfbCopyRect))
					return False;

				cr.srcX = Swap16IfLE(cr.srcX);
				cr.srcY = Swap16IfLE(cr.srcY);

#ifdef	UNIX
				if (appData.copyRectDelay != 0) {
					XFillRectangle(dpy, desktopWin, srcGC, cr.srcX, cr.srcY,
						 rect.r.w, rect.r.h);
					XFillRectangle(dpy, desktopWin, dstGC, rect.r.x, rect.r.y,
						 rect.r.w, rect.r.h);
					XSync(dpy,False);
					usleep(appData.copyRectDelay * 1000);
					XFillRectangle(dpy, desktopWin, dstGC, rect.r.x, rect.r.y,
						 rect.r.w, rect.r.h);
					XFillRectangle(dpy, desktopWin, srcGC, cr.srcX, cr.srcY,
						 rect.r.w, rect.r.h);
					}

				XCopyArea(dpy, desktopWin, desktopWin, gc, cr.srcX, cr.srcY,
					rect.r.w, rect.r.h, rect.r.x, rect.r.y);

#else
				if ( verbose )
					printf("rfbCopyEncoding(%u,%u,%u,%u, from %u, %u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h,cr.srcX,cr.srcY);

				CopyDataFromScreen( rect.r.x, rect.r.y, rect.r.w,rect.r.h,cr.srcX, cr.srcY, buffer);
#endif
				break;
			}
#else
				vnc_copy_error();
				return( False );
#endif

			case rfbEncodingRRE:
#ifdef	_RRE_ENCODING

			{
				switch (myFormat.bitsPerPixel) {
					case 8:
						if ( verbose )
							printf("rfbEncodingRRE8(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleRRE8(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
					case 16:
#ifdef	_RRE_ENCODING16
						if ( verbose )
							printf("rfbEncodingRRE16(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleRRE16(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
#else
						vnc_rre_error();
						return( False );
#endif
					case 32:
#ifdef	_RRE_ENCODING32
						if ( verbose )
							printf("rfbEncodingRRE32(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleRRE32(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
#else
						vnc_rre_error();
						return( False );
#endif
					}
				break;
			}
#else
				vnc_rre_error();
				return( False );
#endif

			case rfbEncodingCoRRE:
#ifdef	_CORRE_ENCODING
			{
				switch (myFormat.bitsPerPixel) {
					case 8:
						if ( verbose )
							printf("rfbEncodingCoRRE8(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleCoRRE8(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
					case 16:
#ifdef	_CORRE_ENCODING16
						if ( verbose )
							printf("rfbEncodingCoRRE16(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleCoRRE16(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
#else
						vnc_corre_error();
						return( False );
#endif
					case 32:
#ifdef	_CORRE_ENCODING32
						if ( verbose )
							printf("rfbEncodingCoRRE32(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleCoRRE32(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
#else
						vnc_corre_error();
						return( False );
#endif
					}
				break;
			}
#else
				vnc_corre_error();
				return( False );
#endif

			case rfbEncodingHextile:
#ifdef	_HEXTILE_ENCODING
			{
				switch (myFormat.bitsPerPixel) {
					case 8:
						if ( verbose )
							printf("rfbEncodingHextile8(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleHextile8(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
					case 16:
						if ( verbose )
							printf("rfbEncodingHextile16(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleHextile16(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
					case 32:
						if ( verbose )
							printf("rfbEncodingHextile32(%u,%u,%u,%u)\n",rect.r.x,rect.r.y,rect.r.w,rect.r.h);
						if (!HandleHextile32(rect.r.x,rect.r.y,rect.r.w,rect.r.h))
							return False;
						else	break;
					}
				break;
			}
#else
				vnc_hextile_error();
				return( False );
#endif

			default:
				if ( verbose )
					printf("Unknown rect encoding %d\n",(int)rect.encoding);
				return False;
			}
		}

#ifdef MITSHM
		/* if using shared memory PutImage, make sure that the X server has
			 updated its framebuffer before we reuse the shared memory.	This is
			 mainly to avoid copyrect using invalid screen contents - not sure
			 if we'd need it otherwise. */

		if (appData.useShm)
			XSync(dpy, False);
#endif

		break;
	}

	case rfbBell:
		XBell(dpy,100);
		break;

	case rfbServerCutText:
	{
		if (!ReadFromRFBServer(((char *)&msg) + 1,
				 sz_rfbServerCutTextMsg - 1))
			return False;

		msg.sct.length = Swap32IfLE(msg.sct.length);

		if (serverCutText)
			free(serverCutText);

		serverCutText = malloc(msg.sct.length+1);

		if (!ReadFromRFBServer(serverCutText, msg.sct.length))
			return False;

		serverCutText[msg.sct.length] = 0;

		newServerCutText = True;

		break;
	}

	default:
		printf("Unknown message type %d from VNC server\n",msg.type);
		return False;
	}

	return True;
}


#define GET_PIXEL8(pix, ptr) ((pix) = *(ptr)++)

#define GET_PIXEL16(pix, ptr) (((CARD8*)&(pix))[0] = *(ptr)++, \
						 ((CARD8*)&(pix))[1] = *(ptr)++)

#define GET_PIXEL32(pix, ptr) (((CARD8*)&(pix))[0] = *(ptr)++, \
						 ((CARD8*)&(pix))[1] = *(ptr)++, \
						 ((CARD8*)&(pix))[2] = *(ptr)++, \
						 ((CARD8*)&(pix))[3] = *(ptr)++)

/* CONCAT2 concatenates its two arguments.	CONCAT2E does the same but also
	 expands its arguments if they are macros */

#define CONCAT2(a,b) a##b
#define CONCAT2E(a,b) CONCAT2(a,b)


/*	Multiple Inclusion of the files providing the various optional
 *	encoding mechanisms.
 */

#define BPP 8

#ifdef	_RRE_ENCODING
#include "rre8.c"
#endif

#ifdef	_CORRE_ENCODING
#include "corre8.c"
#endif

#ifdef	_HEXTILE_ENCODING
#include "hextile.c"
#endif

#undef BPP

#define BPP 16

#ifdef	_RRE_ENCODING16
#include "rre16.c"
#endif

#ifdef	_CORRE_ENCODING16
#include "corre16.c"
#endif

#ifdef	_HEXTILE_ENCODING16
#include "hextile.c"
#endif

#undef BPP
#define BPP 32

#ifdef	_RRE_ENCODING32
#include "rre.c"
#endif

#ifdef	_CORRE_ENCODING32
#include "corre.c"
#endif

#ifdef	_HEXTILE_ENCODING32
#include "hextile.c"
#endif
#undef BPP


/*
 * PrintPixelFormat.
 */

void		PrintPixelFormat( rfbPixelFormat *format )
{
	if (format->bitsPerPixel == 1) {
		printf("	Single bit per pixel.\n");
		printf(	"	%s significant bit in each byte is leftmost on the screen.\n",
			(format->bigEndian ? "Most" : "Least"));
		} 
	else 	{
		printf("	%d bits per pixel.\n",format->bitsPerPixel);
		if (format->bitsPerPixel != 8) {
			printf("	%s significant byte first in each pixel.\n",
				(format->bigEndian ? "Most" : "Least"));
			}
		if (format->trueColour) {
			printf("	True colour: max red %d green %d blue %d",
				format->redMax, format->greenMax, format->blueMax);
			printf(", shift red %d green %d blue %d\n",
				format->redShift, format->greenShift, format->blueShift);
			} 
		else 	{
			printf("	Colour map (not true colour).\n");
			}
		}
	return;
}

void	initialise_server( char * dtn )
{
	si.framebufferWidth 	= 800;
	si.framebufferHeight 	= 600;
	si.format.redMax 	= 255;
	si.format.greenMax 	= 255;
	si.format.blueMax 	= 255;
	si.nameLength 		= strlen(dtn);
	desktopName = malloc(si.nameLength + 1);
	strcpy( desktopName, dtn );
	return;
}

void	initialise_client()
{
	appData.passwordFile=(char*)0;
	appData.passwordDialog=0;
	return;
}

#endif	/* _rfbproto_c */

