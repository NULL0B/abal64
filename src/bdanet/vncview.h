#ifndef	_vncview_h
#define	_vncview_h

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
 * vncview.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include <unistd.h>

#ifdef	UNIX
#include <X11/IntrinsicP.h>
#include <X11/StringDefs.h>
#include <X11/Shell.h>
#include <X11/Xmd.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
#include <X11/Xmu/StdSel.h>
#else
#include "vncmem.h"
#include "cards.h"
#include "strings.h"
#include "colormap.h"
#include "xcolour.h"
#include "xdisplay.h"
#include "xdesktop.h"
#endif

#include "rfbproto.h"

extern int endianTest;

#define Swap16IfLE(s) \
    (*(char *)&endianTest ? ((((s) & 0xff) << 8) | (((s) >> 8) & 0xff)) : (s))

#define Swap32IfLE(l) \
    (*(char *)&endianTest ? ((((l) & 0xff000000) >> 24) | \
			     (((l) & 0x00ff0000) >> 8)  | \
			     (((l) & 0x0000ff00) << 8)  | \
			     (((l) & 0x000000ff) << 24))  : (l))

#define MAX_ENCODINGS 10

#define FLASH_PORT_OFFSET 5400
#define LISTEN_PORT_OFFSET 5500
#define SERVER_PORT_OFFSET 5900


/* argsresources.c */

typedef struct {
  Bool shareDesktop;
  Bool viewOnly;
  Bool fullScreen;

  String encodingsString;

  Bool useBGR233;
  int nColours;
  Bool useSharedColours;
  Bool forceOwnCmap;
  Bool forceTrueColour;
  int requestedDepth;

  Bool useShm;

  int wmDecorationWidth;
  int wmDecorationHeight;

  char *passwordFile;
  Bool passwordDialog;

  int rawDelay;
  int copyRectDelay;

  Bool debug;

  int popupButtonCount;

  int bumpScrollTime;
  int bumpScrollPixels;

} AppData;


extern char *fallback_resources[];
extern Bool listenSpecified;
extern int listenPort, flashPort;

#ifdef	_X_Windowing
extern XrmOptionDescRec cmdLineOptions[];
extern int numCmdLineOptions;
#endif

extern void GetArgsAndResources(int argc, char **argv);

#ifdef	_prototype_all_functions
/* colour.c */


#ifdef	_X_colouring
extern unsigned long BGR233ToPixel[];
extern Visual *vis;
extern unsigned int visdepth, visbpp;
extern void SetVisualAndCmap();
#endif

/* desktop.c */

#ifdef	_X_desktop
extern Atom wmDeleteWindow;
extern Widget form, viewport, desktop;
extern Window desktopWin;
extern GC gc;
extern GC srcGC, dstGC;
extern Dimension dpyWidth, dpyHeight;

extern void DesktopInitBeforeRealization();
extern void DesktopInitAfterRealization();
extern void SendRFBEvent(Widget w, XEvent *event, String *params,
			 Cardinal *num_params);
extern void CopyDataToScreen(char *buf, int x, int y, int width, int height);
extern void SynchroniseScreen();
#endif

/* dialogs.c */
#ifdef	_X_dialogs
extern void ServerDialogDone(Widget w, XEvent *event, String *params,
			     Cardinal *num_params);
extern char *DoServerDialog();
extern void PasswordDialogDone(Widget w, XEvent *event, String *params,
			     Cardinal *num_params);
extern char *DoPasswordDialog();
#endif

/* fullscreen.c */
#ifdef	_X_Fullscreen
extern void ToggleFullScreen(Widget w, XEvent *event, String *params,
			     Cardinal *num_params);
extern void SetFullScreenState(Widget w, XEvent *event, String *params,
			       Cardinal *num_params);
extern Bool BumpScroll(XEvent *ev);
extern void FullScreenOn();
extern void FullScreenOff();
#endif

/* listen.c */

#ifdef	_X_Listen
extern void listenForIncomingConnections();
#endif

/* misc.c */

extern void ToplevelInitBeforeRealization();
extern void ToplevelInitAfterRealization();
extern Time TimeFromEvent(XEvent *ev);
extern void Pause(Widget w, XEvent *event, String *params,
		  Cardinal *num_params);
extern void Quit(Widget w, XEvent *event, String *params,
		 Cardinal *num_params);
extern void Cleanup();

/* popup.c */

extern Widget popup;
extern void ShowPopup(Widget w, XEvent *event, String *params,
		      Cardinal *num_params);
extern void HidePopup(Widget w, XEvent *event, String *params,
		      Cardinal *num_params);
extern void CreatePopup();

/* rfbproto.c */

extern int rfbsock;
extern Bool canUseCoRRE;
extern Bool canUseHextile;
extern char *desktopName;
extern rfbPixelFormat myFormat;
extern rfbServerInitMsg si;
extern char *serverCutText;
extern Bool newServerCutText;

extern Bool ConnectToRFBServer(const char *hostname, int port);
extern Bool InitialiseRFBConnection();
extern Bool SetFormatAndEncodings();
extern Bool SendIncrementalFramebufferUpdateRequest();
extern Bool SendFramebufferUpdateRequest(int x, int y, int w, int h,
					 Bool incremental);
extern Bool SendPointerEvent(int x, int y, int buttonMask);
extern Bool SendKeyEvent(CARD32 key, Bool down);
extern Bool SendClientCutText(char *str, int len);
extern Bool HandleRFBServerMessage();


/* selection.c */

extern void InitialiseSelection();
extern void SelectionToVNC(Widget w, XEvent *event, String *params,
			   Cardinal *num_params);
extern void SelectionFromVNC(Widget w, XEvent *event, String *params,
			     Cardinal *num_params);

/* shm.c */

extern XImage *CreateShmImage();
extern void ShmCleanup();

/* sockets.c */


extern Bool ReadFromRFBServer(char *out, unsigned int n);
extern Bool WriteExact(int sock, char *buf, int n);
extern int ListenAtTcpPort(int port);
extern int ConnectToTcpAddr(unsigned int host, int port);
extern int AcceptTcpConnection(int listenSock);
extern Bool SetNonBlocking(int sock);

extern int StringToIPAddr(const char *str, unsigned int *addr);
extern Bool SameMachine(int sock);

/* vncviewer.c */

extern XtAppContext appContext;
extern Widget toplevel;

#endif

extern Bool errorMessageOnReadFailure;
extern Display* dpy;

extern char * getpass();
extern void PrintPixelFormat(rfbPixelFormat *format);


#ifdef	_vncview_c
int	terminate=0;
int	verbose=0;
int	debug=0;
char	vncServerHost[256];
int	vncServerPort=0;
char *	vncServerPassword=(char *) 0;
char *	programName=(char *) 0;
AppData appData;
Colormap cmap;
int	ClientEncodings=1;
int	BiosMode=-1;
int	PaletteMode=8;
int	IsExclusive=0;
int	VncViewerClip=0;
int	VncViewerWidth=0;
int	VncViewerHeight=0;
#else
extern	int	terminate;
extern	int	verbose;
extern	int	debug;
extern	char	vncServerHost[256];
extern	int	vncServerPort;
extern	char *	vncServerPassword;
extern	char *programName;
extern 	AppData appData;
extern 	Colormap cmap;
extern	int	ClientEncodings;
extern	int	BiosMode;
extern	int	PaletteMode;
extern	int	IsExclusive;
#endif

extern	char * convert_integer( char * , int * );

#define	getword(p) (((*p & 0x00FF) << 8) | (*(p+1) & 0x00FF))


#endif	/* _vncview_h */
	
