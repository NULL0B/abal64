#ifndef	_vncview_c
#define _vncview_c
/*
 *	Copyright (C) 1999 AT&T Laboratories Cambridge.	All Rights Reserved.
 *
 *	This is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This software is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this software; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA	02111-1307,
 *	USA.
 */

/*
 * vncserver.c - the Xt-based VNC viewer.
 */

#include <stdio.h>
#include "vncview.h"
#include "random.c"

Display* dpy;

#include "stdpsu.h"

STDPSUPTR	VncStorage = (STDPSUPTR) 0;

extern	InitialRequest;

#include "vnc.c"
#include "vncfont.c"

int	kbhit()
{
	int	result=0;
	_asm	{
		mov	ah,012H
		int	110
		sahf
		jz	nowt
		mov	result,1
nowt:		
		}
	return( result );
  
}

int	getch()
{
	char	result=0;
	_asm	{
		mov	ah,010H
		int	110		
		mov	result,al
		}
	return(( result  & 0x00FF));
}


void	FillRectangle( int dath, int tx, int ty, int nx, int ny )
{
	return;
}

void	CopyDataFromScreen( int tx, int ty, int nx, int ny, int sx, int sy, char * buffer )
{
	return;
}

void	CopyDataToScreen( char * buffer, int atx, int aty, int nbx, int nby )
{
	return;
}

strncasecmp(char * aptr, char * bptr)
{ 
	return(0); 
}

Bool	old_activate_graphics()
{
	int	h;
	int	w;

	if (!( usegraphics ))
		return( True );

	else if ( BiosMode == -1 ) {

		if (( w = GetFrameBufferWidth() ) > 1200 )
			w = 1200;

		if (( h = GetFrameBufferHeight() ) > 1024 )
			h = 1024;

		if ( w >= 1200 )
			BiosMode = 5;
		else if ( w >= 1024 )
			BiosMode = 4;
		else if ( w >= 800 )
			BiosMode = 3;
		else if ( w >= 640 ) {
			if ( h > 400 )
				BiosMode = 2;
			else	BiosMode = 1;
			}
		else	BiosMode = 0;
		}

	switch ( BiosMode ) {
		case	0	: VncViewerWidth=320;  VncViewerHeight=200;  break;
		case	1	: VncViewerWidth=640;  VncViewerHeight=400;  break;
		case	2	: VncViewerWidth=640;  VncViewerHeight=480;  break;
		case	3	: VncViewerWidth=800;  VncViewerHeight=600;  break;
		case	4	: VncViewerWidth=1024; VncViewerHeight=786;  break;
		case	5	: VncViewerWidth=1200; VncViewerHeight=1024; break;
		default		:
			/* Dummy Screen for Debug */
			if (( debug )
			||  ( verbose ))
				return( True );
			else	return( False );
		}
		
	if ( connectpixel((BiosMode | 512),(void*)0) == -1 ) {
		BiosMode = -1;
		return( False );
		}
	else  if (!( VncStorage = allocate_graphic_storage(0,0,VncViewerWidth, VncViewerHeight ) ))
		return( False );
	else	{
		background_pixel_capture( VncStorage );
		if ( VncViewerWidth < GetFrameBufferWidth() )
			VncViewerClip|=1;

		if ( VncViewerHeight < GetFrameBufferHeight() )
			VncViewerClip|=2;

		(void) start_graphics();

		return( True );
		}
}

int	ClientSocket=0;
int	ServerSocket=0;

int	VncCatcher(void * context, short * descriptor)
{
	int	atcol;
	int	atlin;
	int	nbcol;
	int	nblin;
	atcol = *(descriptor+1);
	atlin = *(descriptor+2);
	nbcol = *(descriptor+3);
	nblin = *(descriptor+4);
	return( AddPendingUpdate( 0, atcol, atlin, nbcol, nblin ) );
}


Bool	activate_graphics()
{
	int	h;
	int	w;

	if (!( usegraphics ))
		return( True );

	else if ((BiosMode = connectpixel((BiosMode | 512),VncCatcher,VncCatching)) == -1 )
		return( False );

	else	{

		switch ( BiosMode ) {
			case	0	: VncViewerWidth=320;  VncViewerHeight=200;  break;
			case	1	: VncViewerWidth=640;  VncViewerHeight=400;  break;
			case	2	: VncViewerWidth=640;  VncViewerHeight=480;  break;
			case	3	: VncViewerWidth=800;  VncViewerHeight=600;  break;
			case	4	: VncViewerWidth=1024; VncViewerHeight=786;  break;
			case	5	: VncViewerWidth=1200; VncViewerHeight=1024; break;
			default		: return( False );
			}
		
		if ( VncViewerWidth < GetFrameBufferWidth() )
			VncViewerClip|=1;
		if ( VncViewerHeight < GetFrameBufferHeight() )
			VncViewerClip|=2;

		return( start_graphics() );

		}
}

void	terminate_graphics()
{
	if ( usegraphics ) {

		if (( BiosMode >= 0 ) && ( BiosMode <= 5 )) {
			cancel_pixel_capture( VncStorage );
			liberatepixel();
			if ( VncStorage )
				VncStorage = liberate_pixel_storage( VncStorage );
			
			}
		}
	return;
}


int	main(int argc, char *argv[])
{
	int	status;
	int i;

	programName = argv[0];

	randomiser();

	/* Interpret resource specs and process any remaining command-line arguments
	 (i.e. the VNC server name).	If the server name isn't specified on the
	 command line, getArgsAndResources() will pop up a dialog box and wait
	 for one to be entered. */

	if ( argc == 1 ) {
		banner("VNC Server");
		return(0);
		}

	if ( analyse_command_line( argc, argv ) == -1 )
		return(0);

	(void) initialise_server( "vncQserver" );

	if (( ServerSocket = ListenAtTcpPort((vncServerPort + SERVER_PORT_OFFSET))) <= 0) {
		return(2);
		}
	else	{
		while ((ClientSocket = AcceptTcpConnection(ServerSocket)) > 0) {

			if ( verbose )
				printf("client connection received on socket %u as socket %u \n",ServerSocket,ClientSocket);

			if ( BiosMode == -1 ) {
				if (!( old_activate_graphics() )) 
					printf("graphics activation failure\n");
				}
			else if (!( activate_graphics() )) 
				printf("graphics activation failure\n");

			if ((status = StartRFBConnection(ClientSocket)) > 0) {
				while ( HandleRFBClientMessage(ClientSocket) );
				terminate_graphics();
				}

			ClientSocket = ReleaseTcpConnection(ClientSocket);


			if ( status == -1 )
				break;
			else if (( kbhit() )
			     &&  ( getch() == 27 ))
				break;

			}
		ServerSocket = 	ReleaseTcpConnection( ServerSocket );

		}


	Cleanup();

	return( 0 );
}


#endif	/* _vncview_c */



