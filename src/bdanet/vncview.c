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
 * vncviewer.c - the Xt-based VNC viewer.
 */

#include <stdio.h>
#include "vncview.h"
#include "random.c"
#include "pixel.h"
#include "guimouse.h"
#include "rfbcico.h"

Display* dpy;

#include "vnc.c"
#include "guimouse.c"


extern	unsigned char * VgaPointers[256];
extern	unsigned char	VgaColours[256][4];

int	cellwidth=10;
int	cellheight=23;

void	FillRectangle( int dath, int tx, int ty, int nx, int ny )
{
	char	*	pptr;

	if (!( usegraphics )) {
		if ( verbose )
			printf("FillRectangle(%u,%u,%u,%u,with %u)\n",
				tx,ty,nx,ny,dath);
		return;
		}

	if ( VncViewerClip & 1 ) {

		if ( tx >= VncViewerWidth  )
			return;
		
		if  ( (tx+nx) >= VncViewerWidth  )
			nx = VncViewerWidth - tx;
		}

	if ( VncViewerClip & 2 ) {

		if ( ty >= VncViewerHeight )
			return;

		if  ( (ty+ny) >= VncViewerHeight  )
			ny = VncViewerHeight - ty;

		}

	if ( PaletteMode > 8 )
		if ((pptr = VgaPointers[(dath & 0x007F)]) != (char *) 0)
			dath = *(pptr + ( dath & 0x00FF ));


	if ( mouseover( tx,ty, nx, ny ) )
		hidemouse();
	filzone( tx,ty,nx,ny, (dath & 0x00FF) );
	return;

}

void	CopyDataFromScreen( int tx, int ty, int nx, int ny, int sx, int sy, char * buffer )
{
	if (!( usegraphics )) {
		if ( verbose )
			printf("CopyDataFromScreen(%u,%u,%u,%u, from %u,%u)\n",
				tx,ty,nx,ny,sx,sy);
		return;
		}

	if ( VncViewerClip & 1 ) {

		if (( tx >= VncViewerWidth  )
		||  ( sx >= VncViewerWidth  ))
			return;
		
		if  ( (tx+nx) >= VncViewerWidth  )
			nx = VncViewerWidth - tx;
		if  ( (sx+nx) >= VncViewerWidth  )
			nx = VncViewerWidth - sx;
		}

	if ( VncViewerClip & 2 ) {

		if (( ty >= VncViewerHeight )
		||  ( sy >= VncViewerHeight ))
			return;

		if  ( (ty+ny) >= VncViewerHeight  )
			ny = VncViewerHeight - ty;
		if  ( (sy+ny) >= VncViewerHeight  )
			ny = VncViewerHeight - ty;

		}

	if (( mouseover( tx,ty, nx, ny ) )
	||  ( mouseover( sx,sy, nx, ny ) ))
		hidemouse();
	for (; ny > 0; ny-- ) {
		getzone( sx,sy++,nx,1,buffer );
		putzone( tx,ty++,nx,1,buffer );
		}
	return;
}

void	CopyDataToScreen( char * buffer, int tx, int ty, int nx, int ny )
{
	int	i;
	char *	pptr;
	char *	sptr;
	char *	tptr;
	int	c;
	int	l;

	if (!( usegraphics )) {
		if ( verbose )
			printf("CopyDataToScreen(%u,%u,%u,%u)\n",tx,ty,nx,ny);
		return;
		}

	if ( VncViewerClip & 1 ) {

		if ( tx >= VncViewerWidth  )
			return;
		
		if  ( (tx+nx) >= VncViewerWidth  )
			nx = VncViewerWidth - tx;

		}

	if ( VncViewerClip & 2 ) {

		if ( ty >= VncViewerHeight )
			return;

		if  ( (ty+ny) >= VncViewerHeight  )
			ny = VncViewerHeight - ty;
		}

	if ( PaletteMode > 8 ) {
		for (sptr=buffer,tptr=buffer,l=0; l < ny; l++)
			for (c=0; c < nx; c++ )
				if ((pptr = VgaPointers[(*(sptr++) & 0x007F)]) != (char *) 0)
					*(tptr++) = *(pptr + ( *(sptr++) & 0x00FF ));
				else	break;
		}
	if ( mouseover( tx,ty, nx, ny ) )
		hidemouse();
	putzone( tx,ty, nx, ny, buffer );
	return;
}

strncasecmp(char * aptr, char * bptr)
{ 
	return(0); 
}

Bool	activate_graphics()
{
	int	h;
	int	w;

	if (!( usegraphics )) {
		initialise_mouse();
		return( True );
		}

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
		
	if ( initialisepixel((BiosMode | 256)) == -1 ) {
		BiosMode = -1;
		return( False );
		}
	else 	{
		if ( VncViewerWidth < GetFrameBufferWidth() )
			VncViewerClip|=1;

		if ( VncViewerHeight < GetFrameBufferHeight() )
			VncViewerClip|=2;

		calibrate_mouse( VncViewerWidth, VncViewerHeight );
		initialise_mouse();
		activate_palette();
		return( True );
		}
}

void	terminate_graphics()
{
	if (!( usegraphics )) 
		terminate_mouse();

	else if (( BiosMode >= 0 ) && ( BiosMode <= 5 )) {
		terminate_mouse();
		liberatepixel();
		}
	return;
}

int	try_and_getch()
{
	if  (!(  mimo_kbhit() ))
		return( 0 );
	else	return( mimo_getch() );
}

Bool	ConsoleEvent()
{
	int	c;
	int	x;
	int	y;
	int	b;
	int	t;

	showmouse();

	switch ((c=try_and_getch())) {

		case	0	:
			break;
		case	256	:

			do	{
				movemouse((x = get_mimo_col()),(y = get_mimo_lin()));
				b= get_mimo_par();
				if ((t = get_mimo_type()) != _MIMO_MOVE)
					break;
				}
			while ((c = try_and_getch()) == 256);

			if (!( SendMouseEvent( x,y,t,b ) ))
				return( False );

			if (!( c & 0x00FF ))
				return( True );

		case	 27	:
	
			switch ((c = mimo_getch())) {
				case	27	:
					break;
				case	13	: /* ESC RC == QUIT */
					return( False );				
				default			:
					return(True);
				}
		default		:
			if (!(  SendCharacter( c ) ))
				return( False );
			else	return( True );

		}

	return( True );
}

	
int	main(int argc, char *argv[])
{
	int	status=0;
	int i;
	int	c;
	programName = argv[0];
	randomiser();

	/* Interpret resource specs and process any remaining command-line arguments
	 (i.e. the VNC server name).	If the server name isn't specified on the
	 command line, getArgsAndResources() will pop up a dialog box and wait
	 for one to be entered. */

	if ( argc == 1 ) {
		banner("VNC Viewer");
		return(0);
		}

	switch ( analyse_command_line( argc, argv ) ) {
		case	1 :
		case	3 :	break;
		default	  :	printf("VNC server host name or address required\n");
				banner("VNC Viewer");
				return(1);
		case	-1:	return(0);

		}


	initialise_client();

	if ( ConnectToRFBServer(vncServerHost, (vncServerPort + SERVER_PORT_OFFSET)) ) {
		if (InitialiseRFBConnection()) {
			if ( SetFormatAndEncodings() ) {
				if ( activate_graphics() ) {
					for ( 	status=SendInitialFramebufferUpdateRequest();
						status != 0;
						status = SendIncrementalFramebufferUpdateRequest()) {
						if (!( ConsoleEvent() ))
							break;
						else if (!( rfbSelectConnection(1) ))
							continue;
						else if (!( HandleRFBServerMessage() ))
							break;
						}
					terminate_graphics();
					}
				}
			}
		}
	Cleanup();

	return( 0 );
}


#endif	/* _vncview_c */



