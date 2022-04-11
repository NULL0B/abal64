#include <stdio.h>
#include "stdpsu.h"
#include "rtbda.c"
#include "cico.c"

#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
extern	int	image_error;
extern	int	high_resolution;

#define	_IVIEW_DATE	"15/03/2007"

static	char	*	controle="\0=DEBUG";

#define	MSGQTY		20
#define	MSGMAXLEN	60

static  char	VersionStatus[16]=
	{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
static	char 	LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'2','1','a','0','0','1',0 };
static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[10];
static	char *	Provisoire="\n   Provisoire du %s ";
static	int	domakefit=0;
static	int	mready=0;
static	int	gifloader=0;
static	char *	message_table[MSGQTY];
static	int	mouse_is_down=0;
static	int	mouse_down_x=0;
static	int	mouse_down_y=0;
static	int	showname=0;
static	char * 	imagename=(char *) 0;
static	char *	DefaultSmall="\0   =sAlign   ";
static	char *	DefaultBig  ="T\0  =bAlign   ";

void	standard_image_quality( int, int );

char	message_buffer[MSGQTY+10][MSGMAXLEN] = {
	"*STX*3IVIEW   11a00",
	"yn",
	"Options",
	"a<lrtb>        : align top/bottom/left/right",
	"c<colour>      : set clear screen colour",
	"f              : load driver base font",
	"j<0|1>         : high resolution (true colour) on/off",
	"k              : no keyboard",
	"m<biosmode>    : set screen bios mode 0->5",
	"p              : load palette from file",
	"q<count>       : qualification routines",
	"s              : load driver mouse cursor",
	"t<0|1>         : transparent image",
	"u              : load driver saver sprite",
	"w<delay>       : wait indicated delay",
	"x<column>      : set absolute x position",
	"y<row>         : set absolute y position",
	"z              : activate absolute position",
	"error",
	"bmp,gif,jpeg,png,ico",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
	"*ETX*"
	};

void	initialise_messages()
{
	int	x;
	char *	wptr;
	wptr = 	& message_buffer[0][0];
	x = 0;

	do	{
		while ( *wptr )  wptr++;
		while (!(*wptr)) wptr++;
		message_table[x++] = wptr;
		}

	while ( x < MSGQTY );
	mready = MSGQTY;
	return;
}

char *	getmessage(int n)
{
	if (!( mready ))
		initialise_messages();
	if ( n < MSGQTY )
		return( message_table[n] );
	else	return( "message[?]" );
}

char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] > '0' ) {
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

int	banner()
{
	printf("\n   Image Viewer : Version %s ",getpatternversion());

	if ( VersionStatus[15] == '2' )
		printf(Provisoire,_IVIEW_DATE);

	printf("\n   Copyright (c) 2001,2007 Amenesik / Sologic \n");
	printf("\n   %s : \n",getmessage(1));	/* Options */
	printf("\n   -%s ",getmessage(2));	/* -a[lrtb]        : align top/bottom/left/right " */
	printf("\n   -%s ","b              : best fit to screen size    " );
	printf("\n   -%s ",getmessage(3));	/* -ccolour        : set clear screen colour     " */
#ifdef	PROLOGUE
	printf("\n   -%s ",getmessage(4));	/* -f              : load driver base font       "	*/
#endif
	printf("\n   -%s ","g              : activate gif skin loadtest " );
	printf("\n   -%s ",getmessage(5)); 	/* -j[0|1]         : high resolution jpeg on/off "	*/
	printf("\n   -%s ",getmessage(6));	/* -k              : no keyboard                 "	*/
	printf("\n   -%s ","l              : make fit  : screen size    " );
	printf("\n   -%s ",getmessage(7));	/* -mbiosmode      : set screen bios mode 0->5   "	*/
	printf("\n   -%s ","n              : display filenames as text  " );
	printf("\n   -%s ",getmessage(8));	/* -pfilename      : load palette from file      "	*/
	printf("\n   -%s ",getmessage(9));	/* -q              : qualification routines      "	*/
#ifdef	PROLOGUE
	printf("\n   -%s ",getmessage(10));	/* -s              : load driver mouse cursor    "	*/
#endif
	printf("\n   -%s ",getmessage(11));	/* -t[0|1]         : transparent image           "	*/
#ifdef	PROLOGUE
	printf("\n   -%s ",getmessage(12));	/* -u              : load driver saver sprite    "	*/
#endif
	printf("\n   -%s ",getmessage(13));	/* -wdelay         : wait indicated delay        "	*/
	printf("\n   -%s ",getmessage(14));	/* -xcolumn        : set absolute x position     "	*/
	printf("\n   -%s ",getmessage(15));	/* -yrow           : set absolute y position     "	*/
	printf("\n   -%s \n",getmessage(16)); 	/* -z              : activate absolute position  \n\n"	*/
	printf("\n    %s \n\n",getmessage(18)); /* bmp,gif,jpeg,png,ico \n\n"				*/

	return(0);
}

char	SetMouseBuffer[1024+16];
int	setpalflag=0;
int	setfontflag=0;
int	setmouseflag=0;
int	setspriteflag=0;
int	absolute=0;
int	xposition=0;
int	yposition=0;
int	GraphMode=-1;
int	prompter=1;
int	screenwidth=800;
int	screenheight=600;
static	char * BiosMode="\3=BIOSMODE";
int	screenmode=-1;
int	alignment=0;
int	blignment=0;
int	clearscreen=15;
int	transparent=0;
int	timeout=0;
#ifdef	UNIX
char	* PaletteFileName="/opt/prologue/images/standard.rgb\0     \0";
#else
char	* PaletteFileName="is\\images\\standard.rgb\0              \0";
#endif
int	PaletteFlag=0;

#include "vmouse.c"

int	integer( char * sptr )
{
	int	v=0;
	while ( *sptr ) {
		if ((*sptr >= '0') && ( *sptr <= '9' ))
			v = ((v * 10) + ( *(sptr++) - '0' ));
		else	break;
		}
	return(v);
}

void	setscreenmode( int mode )
{
	switch ((screenmode=mode)) {
		case	0 : screenwidth = 320; screenheight=200; break;
		case	1 : screenwidth = 640; screenheight=400; break;
		case	2 : screenwidth = 640; screenheight=480; break;
		case	3 : screenwidth = 800; screenheight=600; break;
		case	4 : screenwidth =1024; screenheight=768; break;
		case	5 : screenwidth =1280; screenheight=1024; break;
		case	6 : screenwidth =1280; screenheight=1280; break;
		default	  : setscreenmode(*BiosMode);
		}
	return;
}

#include "zalloc.c"
#ifndef	UNIX
#include "zwait.c"
#else
#define	zwait(n) sleep(n);
#endif
int	get_keyboard()
{
	int	c;

	if ( timeout ) {
		zwait(timeout);
		return(-1);
		}

	else if (!( prompter ))
		return(-1);

	else	return( mimo_getch() );
}


void	check_palette()
{
	if ( *PaletteFileName ) {
		if (!( PaletteFlag )) {
			load_palette(PaletteFileName);
			put_palette();
			PaletteFlag = 1;
			}
		}
	return;
}

void	reset_flags()
{
	setpalflag=0;
	setfontflag=0;
	setmouseflag=0;
	setspriteflag=0;
	return;
}

int	open_graphics()
{
	if ( screenmode == -1 )
		setscreenmode( *BiosMode );

	if ( GraphMode != screenmode ) {
		if ( initialisepixel( (screenmode+(high_resolution ? 512 : 256)) ) != -1 )
			GraphMode = screenmode;
		else	GraphMode = -1;
		initialise_mouse();
		set_mimo_mask((
			_MIMO_WHILE_DOWN |
			_MIMO_DOWN 	 |
			_MIMO_UP 	 |
			_MIMO_CLICK	 |
			_MIMO_SEND_RIGHT |
			_MIMO_SEND_LEFT   	   ));
		}

	check_palette();

	standard_image_quality( get_pixel_size(), get_pixel_format() );

	return(GraphMode);
}

int	mouse_image(struct standard_image * iptr ) 
{
	int	r;
	char *	tptr;
	char *	bptr;
	int	status=0;

	if ( open_graphics() != -1) {

		if ( iptr ) {

			if ((iptr->columns * iptr->rows ) > 1024)
				status = 46;
			else if ((iptr->columns * iptr->rows ) <= 0 )
				status = 46;
			else	{
				SetMouseBuffer[0] = (char) iptr->columns;
				SetMouseBuffer[1] = (char) iptr->rows;
				for (r=0,tptr= &SetMouseBuffer[2]; r < iptr->rows; r++ ) {
					if ((bptr = connect_pixel_row( iptr->storage, r )) != (char *) 0) {
						memcpy(tptr, bptr,iptr->columns);
						tptr += iptr->columns;
						}
					else	break;	
					}
				setmouse((char *) SetMouseBuffer);
				}
			iptr = drop_image( iptr );
			}
		}	
	else	status = 56;
	reset_flags();
	return(status);
}

int	sprite_image(struct standard_image * iptr ) 
{
	int	r;
	char *	tptr;
	char *	bptr;
	int	status=0;

	if ( open_graphics() != -1) {

		if ( iptr ) {

			if ((iptr->columns * iptr->rows ) > 1024)
				status = 46;
			else if ((iptr->columns * iptr->rows ) <= 0)
				status = 46;
			else	{
				SetMouseBuffer[0] = (char) iptr->columns;
				SetMouseBuffer[1] = (char) iptr->rows;
				for (r=0,tptr= &SetMouseBuffer[2]; r < iptr->rows; r++ ) {
					if ((bptr = connect_pixel_row( iptr->storage, r )) != (char *) 0) {
						memcpy(tptr, bptr,iptr->columns);
						tptr += iptr->columns;
						}
					else	break;	
					}
				setsprite((char *) SetMouseBuffer);
				}
			iptr = drop_image( iptr );
			}
		}	
	else	status = 56;
	reset_flags();
	return(status);
}

int	flush_queue(int retcode)
{
	while ( mimo_kbhit() )
		(void) mimo_getch();
	return( retcode);
}



int	mouse_event(int * icol,int maxXecart, int *irow,int maxYecart)
{
	int	type = get_mimo_type();
	int	button  = get_mimo_par();
	int	event_y = get_mimo_row();
	int	event_x = get_mimo_column();
	int	xpos=*icol;
	int	ypos=*irow;
	
	if ( *controle )
		printf("mouse_event(%x,%u,%u,%u)\n",type,button,event_x,event_y);

	switch (type) {



		case	_MIMO_UP	:

			if ( mouse_is_down & button ) {

				/* Adjust row start by mouse movement */
				/* ---------------------------------- */
				if ( event_y > mouse_down_y ) {
					if ( button != _MIMO_LEFT )
						ypos = 0;
					else	ypos -= (event_y - mouse_down_y);
					}
				else if ( event_y < mouse_down_y ) {
					if ( button != _MIMO_LEFT )
						ypos = maxYecart;
					ypos += (mouse_down_y - event_y);
					}

				/* Limit row adjust to legal value */
				/* ------------------------------- */
				if ( ypos > maxYecart )
					ypos = maxYecart;
				else if ( ypos < 0 )
					ypos = 0;

				/* Adjust column start by mouse movement */
				/* ------------------------------------- */
				if ( event_x > mouse_down_x ) {
					if ( button != _MIMO_LEFT )
						xpos = 0;
					else	xpos -= (event_x - mouse_down_x);
					}
				else if ( event_x < mouse_down_x ) {
					if ( button != _MIMO_LEFT )
						xpos = maxXecart;
					else	xpos += (mouse_down_x - event_x);
					}

				/* Limit column adjust to legal value */
				/* ---------------------------------- */
				if ( xpos > maxXecart )
					xpos = maxXecart;
				else if ( xpos < 0 )
					xpos = 0;

				/* clear movement control and detect change */
				/* ---------------------------------------- */
				mouse_is_down &= ~button;

				/* Check for double button action */
				/* ------------------------------ */
				if ( mouse_is_down & _MIMO_LEFT ) {
					/* LEFT held, RIGHT click */
					/* ESCAPE 		  */
					mouse_is_down = mouse_down_x = mouse_down_y = 0;
					return(flush_queue(27));
					}

				else if ( mouse_is_down ) {
					/* OTHER held, LEFT click */
					/* VALID  		  */
					mouse_is_down = mouse_down_x = mouse_down_y = 0;
					return(flush_queue(13));
					}
				else 	mouse_is_down = mouse_down_x = mouse_down_y = 0;

				if (( xpos == *icol )
				&&  ( ypos == *irow ))
					return(0);
				else	{
					/* signal change */
					/* ------------- */
					*icol = xpos;
					*irow = ypos;
					return(flush_queue(256));
					}
				}
			else	return(0);

		case	_MIMO_WHILE_DOWN:
		case	_MIMO_DOWN	:
			if (!( mouse_is_down )) {
				mouse_down_x = event_x;
				mouse_down_y = event_y;
				}
			mouse_is_down |= button;
			return(0);

		case	_MIMO_CLICK	:
			if ( button == _MIMO_LEFT )
				return( 13 );
			else	return( 27 );

		default			:
			return(0);
		}
}


int	show_image( struct standard_image * iptr ) 
{
	int	pixelsize=1;
	int	truecolour=0;
	int	movable=0;
	int	x;
	int	atrow=0;
	int	gratrow=0;
	int	atcol=0;
	int	nbr;
	int	nbc;
	int	row;
	int	maxYecart=0;
	int	maxXecart=0;
	int	irow=0;
	int	icol=0;
	int	redraw=1;
	char *	bptr;
	int	status=0;
	pixelsize = get_pixel_size();

	/* Ensure that graphics have started */
	/* --------------------------------- */
	if ( open_graphics() != -1) {

		mouse_down_y = mouse_down_x = mouse_is_down = 0;

		/* Ensure valid Image to display */
		/* ----------------------------- */
		if ( iptr ) {

			if ((iptr->columns >= screenwidth )
			&&  (iptr->rows >= screenheight)
			&&  (iptr->storage != (void *) 0 ))
				clearscreen = 0;

			/* Test for and calculate absolute position */
			/* ---------------------------------------- */
			if ( absolute ) {
				atcol = xposition;
				atrow = yposition;
				nbr = iptr->rows;
				if ((nbr +atrow) > screenheight)
					nbr = (screenheight-atrow);
				nbc = iptr->columns;
				if ((nbc +atcol) > screenwidth)
					nbr = (screenwidth-atcol);
				irow=maxYecart=maxXecart=0;
				}
			else	{
				/* Test for rows exceeding screen */
				/* ------------------------------ */
				if ((nbr = iptr->rows) > screenheight) {
					movable++;
					maxYecart = (iptr->rows - screenheight);
					nbr = screenheight;
					switch ((blignment & 0x000C) ) {
						case	0x0000 :
							irow = (maxYecart/2);
							break;
						case	0x0004 :
							irow = maxYecart;
							break;
						default		:
							irow = 0;
							break;
						}
					}
				/* Apply vertical alignment */
				/* ------------------------ */
				else if ( nbr < screenheight ) {
					icol = 0;
					switch ((alignment & 0x000C) ) {
						case	0x0000 :
							atrow = ((screenheight - nbr) / 2);
							break;
						case	0x0004 :
							atrow = (screenheight - nbr);
							break;
						}
					}
	
				/* Test for columns exceeding width */
				/* -------------------------------- */
				if ((nbc = iptr->columns) > screenwidth) {
					maxXecart = (iptr->columns - screenwidth);
					nbc = screenwidth;
					movable++;
					switch (( blignment & 0x003) ) {
						case	0x0000 :
							icol = (maxXecart/2);
							break;
						case	0x0002 :
							icol = maxXecart;
							break;
						default		:
							icol = 0;
							break;
						}
					}

				/* Apply horizontal alignment */
				/* -------------------------- */
				else if ( nbc < screenwidth ) {
					icol = 0;
					switch (( alignment & 0x003) ) {
						case	0x0000 :
							atcol = ((screenwidth - nbc) / 2);
							break;
						case	0x0002 :
							atcol = ((screenwidth - nbc));
							break;
						}
					}	
				}
			}
	
		/* Detect and perform Screen Clear Requests */
		/* ---------------------------------------- */
		if ( clearscreen )
			filzone( 0,0, screenwidth,screenheight,clearscreen);

		/* Ensure valid image */
		/* ------------------ */
		if ( iptr ) {

			/* Establish Image Palette Now */
			/* --------------------------- */
			put_palette();

#ifdef	UNIX
			if (!( pixelsize = iptr->format )) {
				pixelsize = get_pixel_size();
				truecolour= 0;
				}
			else	truecolour=1;
			/* establish very image specific palette */
			/* ------------------------------------- */
			if (!( truecolour )) {
				if ( iptr->palette != (char *) 0 ) {
					vgapalette(iptr->palette, 0,256);
					}
				}
#endif
			while (1) {

				/* Freeze Graphic Output */
				/* --------------------- */
				if ( redraw ) {
					hide();

					/* handle makefit and best fit requests */
					/* ------------------------------------ */
					if ( domakefit == 1 )
						imakefit( 0,0, screenwidth, screenheight, iptr );
					else if ( domakefit == 2 )
						ibestfit( 0,0, screenwidth, screenheight, iptr );

					/* Separate between Transparent and Opaque */
					/* --------------------------------------- */
					else if ( transparent ) {
						for ( gratrow=atrow, row=0; row < nbr; row++ ) {
							if ((bptr = connect_pixel_row( iptr->storage, (row+irow) )) != (char *) 0) {
								if ( truecolour )
									mixzone( atcol, gratrow++, nbc, 1, (bptr+icol) );
								else	mixzone8( atcol, gratrow++, nbc, 1, (bptr+icol) );
								}
							}
						}
					else	{
						/* Opaque display of Image */
						/* ----------------------- */
						for ( gratrow=atrow, row=0; row < nbr; row++ ) {
							if ((bptr = connect_pixel_row( iptr->storage, (row+irow) )) != (char *) 0) {
								if ( truecolour )
									putzone( atcol, gratrow++, nbc, 1, (bptr+icol) );
								else	putzone8( atcol, gratrow++, nbc, 1, (bptr+icol) );
								}
							}
						}
	
					/* Unfreeze graphical output */
					/* ------------------------- */
					show(atcol,atrow,nbc,nbr);
					show(atcol,atrow,nbc,nbr);
					
					}

				/* Rearm the refresh control flag */
				/* this will be cleared as needed */
				/* ------------------------------ */
				redraw=1;

				/* display image name for sylvie */
				/* ----------------------------- */
				if (( showname ) && ( imagename != (char *) 0)) {
					printf("image : %s\r\n",imagename);
					}

				/* Get keyboard or Mouse event */
				/* --------------------------- */
				while ((status =  get_keyboard()) == 256) {
					if (!( movable ))
						break;
					else if (!(status = mouse_event(&icol,maxXecart,&irow,maxYecart))) {
						continue;
						}
					else	break;
					}

				/* Ignore keyboard if not movable */
				/* ------------------------------ */
				if ( movable ) {

					/* Determine Keyboard Action */
					/* ------------------------- */
					switch ( status ) {
						case	256:
							/* The mouse event will     */
							/* have set the coordinates */
							continue;

						case	-1 :
							status = 0;
							break;

						case	2 :
							if ( irow != maxYecart ) 
								irow = maxYecart;
							else	redraw=0;
							continue;
	
						case	0x000F : /* INS */
							icol = (maxXecart/2);
							irow = (maxYecart/2);
							continue;

						case	0x001C:
						case	0x000C:
							if ( irow )
								irow=icol=0;
							else	redraw=0;
							continue;
	
						case	3 :
							if ( irow < maxYecart ) {
								for (x=0; x < 16; x++ ) {
									if ( irow < maxYecart )
										irow++;
									else	break;
									}
								}
							else	redraw=0;
							continue;

						case	0x0012:
							if (!( irow ))
								redraw=0;
							else for (x=0; x < 16; x++ ) {
								if ( irow > 0 )
									irow--;
								else	break;
								}
							continue;

						case	5 :
							if ( irow < maxYecart )
								irow++;
							else	redraw=0;
							continue;

						case	11:
							if ( irow )
								irow--;
							else	redraw=0;
							continue;

						case	 8 :
							if ( icol >= pixelsize )
								icol -= pixelsize;
							else	redraw=0;
							continue;
						case	 6 :
							if ( (icol+pixelsize) < maxXecart ) 
								icol+= pixelsize;
							else	redraw=0;
							continue;
						case	 9 :	/* Tabulation */
							if ( (icol+pixelsize) < maxXecart ) {
								for (x=0; x < 16; x++ ) {
									if ( (icol+pixelsize) < maxXecart )
										icol+=pixelsize;
									else	break;
									}
								}
							else	redraw=0;
							continue;
						case	 0 :	/* Back Tabulation */
							if (!( icol ))
								redraw=0;
							else for (x=0; x < 16; x++ ) {
								if ( icol >= pixelsize )
									icol-= pixelsize;
								else	break;
								}
							continue;
						}
					if ( status == '=' ) {
						domakefit += 1;
						domakefit %= 3;
						continue;
						}
					}
				break;
				}
			iptr = drop_image( iptr );
			}
		}
	return(status);
}

int	load_driver_font( char * fptr )
{
	sysfont( fptr );
	reset_flags();
	return(0);
}

int	load_driver_palette( char * fptr )
{
	PaletteFileName=fptr;
	PaletteFlag=0;
	check_palette();
	reset_flags();
	return(0);
}

int	load_and_show( char * aptr )
{
	struct standard_image * iptr=(struct standard_image *)0;

	imagename = aptr;	

	if ( open_graphics() == -1)
		return(56);
	else if ( setpalflag  )
		return( load_driver_palette(aptr) );		
	else if ( setfontflag )
		return( load_driver_font(aptr) );		
	else if ( gifloader ) {
		if (!( iptr = palette_gif_loader( aptr ) )) {
			if ( image_error != 0 )
				return( image_error );
			else	return( 56 );
			}
		else	{
			if ( setspriteflag )
				return( sprite_image( iptr ) );
			else if ( show_image( iptr ) == 27 )
				return(27);
			else	return(0);
			}
		}		
	else if  (!(iptr = image_loader( aptr ))) {
		if ( image_error != 0 )
			return( image_error );
		else	return( 56 );
		}
	else if ( setmouseflag )
		return( mouse_image( iptr ) );
	else if ( setspriteflag )
		return( sprite_image( iptr ) );
	else if ( show_image( iptr ) == 27 )
		return(27);
	else	return(0);
}

char	IMN[1024];

char	*	get_name(FILE * handle)
{
	int	idex;
	int	c;
	while (((c = fgetc(handle)) == ' ') || (c == '\r') || (c=='\t') || ( c == '\n'));
	if ( c <= 0 )
		return( (char *) 0 );
	for (idex=0; idex < 1000; idex++) {
		switch ((c = fgetc(handle))) {
			case ' '  :
			case '\r' :
			case '\t' :
			case '\n' :
				IMN[idex] = 0;
				break;
			default	  :
				IMN[idex]=c;
				continue;
			}
		break;
		}
	IMN[idex] = 0;
	return( IMN );
}

int	script_loader( char * sptr )
{
	char	* aptr;
	FILE	*handle;
	int	status=0;
	if (!(handle = fopen(sysfilename(sptr), "r")))
		return(40);
	else	{
		while ((( aptr = get_name(handle)) != (char *) 0)
		&& (!(status = load_and_show( aptr ) )));
		fclose( handle );
		return((status==27?0:status));
		}
}


void	close_graphics()
{
	if ( GraphMode != -1 ) {
		terminate_mouse();
		liberatepixel();
		GraphMode = -1;
		}
	return;
}

#include "random.c"

void	qualification(char * aptr)
{
	unsigned int  	h;
	unsigned int	w;
	unsigned int	x;
	unsigned int	y;
	unsigned int	d;
	unsigned int	n;
	unsigned int	i=0;

	if ( open_graphics() != -1) {

		for (i=0,n = integer(aptr);
			i < n;
			i++ ) {
			if (!(h = (random() % (screenheight/2))))
				continue;
			else if (!( w = (random() % (screenwidth/2)) ))
				continue;
			x = (random() % (screenwidth - w));
			y = (random() % (screenheight- h));
			d = (random() % 256);
			hide();
			filzone( x,y,w,h,d);
			(void) show(x,y,w,h);
			(void) show(x,y,w,h);
			if ( timeout )
				zwait(timeout);
			}
		}
	return;
}


static	int	set_alignment( char * aptr )
{
	int	valignment = 0;
	while ( *aptr ) {
		switch ( *(aptr++) ) {
			case	'l'	:
			case	'L'	:
				valignment &= ~2;
				valignment |=  1;
				continue;
			case	'r'	:
			case	'R'	:
				valignment &= ~1;
				valignment |=  2;
				continue;
			case	't'	:
			case	'T'	:
				valignment &= ~4;
				valignment |=  8;
				continue;
			case	'b'	:
			case	'B'	:
				valignment &= ~8;
				valignment |=  4;
				continue;
			}
		}
	return(valignment);
}

int	operation( int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	status=0;

#ifdef	UNIX
	set_desktop_name("Image Viewer");
	set_desktop_icon("iView");
#endif
#ifndef	UNIX
	jpeg_options( ((_JPEG_DEFAULT)) );
#endif
	alignment = set_alignment( DefaultSmall );
	blignment = set_alignment( DefaultBig   );
	for ( argi=1; argi < argc; argi++ ) {

		if (!( aptr = argv[argi] ))
			break;

		else if ( *aptr == '-' ) {
			aptr++;
			switch ( *(aptr++) ) {
				case	'a'	:
				case	'A'	:
					alignment = set_alignment( aptr );
					blignment = set_alignment( aptr );
					continue;
				case	'b'	:
				case	'B'	:
					domakefit = 2;
					continue;

				case	'd'	:
				case	'D'	:
					*controle = 1;
					continue;

				case	'c'	:
				case	'C'	:
					clearscreen = integer(aptr);
					continue;
				case	'j'	:
				case	'J'	:
#ifndef	BADUNIX
					if ((high_resolution = integer( aptr )) != 0)
						jpeg_options( ((_JPEG_DEFAULT) | _JPEG_SOLO) );
					else	jpeg_options( ((_JPEG_DEFAULT)) );
#endif
					continue;

				case	'p'	:
				case	'P'	:
					reset_flags();
					setpalflag=1;
					continue;

				case	't'	:
				case	'T'	:
					transparent = integer( aptr );
					continue;

				case	'f'	:
				case	'F'	:
					reset_flags();
					setfontflag=1;
					continue;

				case	's'	:
				case	'S'	:
					reset_flags();
					setmouseflag=1;
					continue;					

				case	'u'	:
				case	'U'	:
					reset_flags();
					setspriteflag=1;
					continue;					
				case	'n'	:
				case	'N'	:
					showname=1;
					continue;
				case	'l'	:
					domakefit = 1;
					continue;
				case	'm'	:
				case	'M'	:
					close_graphics();
					setscreenmode( integer( aptr ) );
					continue;

				case	'k'	:
				case	'K'	:
					prompter = integer(aptr);
					continue;
				case	'z'	:
				case	'Z'	:
					absolute = integer(aptr);
					continue;
				case	'x'	:
				case	'X'	:
					xposition = integer(aptr);
					continue;
				case	'g'	:
				case	'G'	:
					gifloader=1;
					continue;

				case	'q'	:
				case	'Q'	:
					qualification(aptr);
					continue;
				case	'y'	:
				case	'Y'	:
					yposition = integer(aptr);
					continue;
				case	'w'	:
				case	'W'	:
					timeout = integer(aptr);
					continue;
	
				default		:
					status = 30;
					break;
				}
			break;
			}
		else if ( *aptr == ':' ) {
			if ((status= script_loader((aptr+1))) == 40 )
				break;
			else	continue;
			}
		else if ((status = load_and_show( aptr ))!=0 ) 
			break;
		else	continue;

		}

	close_graphics();
	if (( status != 0 ) && ( status != 27 ))
		printf("\n%s : %u \n",getmessage(17),status);
	return((status==27?0:status));
}

int	main( int argc, char * argv[] )
{
	struct standard_image * iptr=(struct standard_image *)0;

	if (( argc == 1 )
	||  (!(consoletype())))
		return( banner() );
	else	return( operation(argc,argv) );
}





