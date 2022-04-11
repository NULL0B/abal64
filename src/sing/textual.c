#ifndef	_TEXTUAL_C
#define	_TEXTUAL_C

/*	The function definitions	*/
/*	------------------------	*/
#include	<stdio.h>
#include	<stdlib.h>
#include	"bda.h"
#include 	"vcico.h"
#include 	"stdimage.h"

#include 	"singpix.h"

#ifdef	UNIX
#include "cico.c"
#include "rgraph.c"
#endif

#define	__TEXTUAL_DATE    "06/07/2003"
#ifndef	public
#define	public	
#endif
#ifndef	private
#define	private	static
#endif
#ifndef	BPTR
#define	BPTR BYTE FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif
#include "vcommand.h"
#include "visilib.h"
#include "stdpsu.h"
#include "fnparser.c"
#define	MAX_V_BUFFER 10

private	STDPSUPTR	TextualBufferHeap[ MAX_V_BUFFER ];
private	EXAWORD		ActiveTextualBuffer=-1;

private  char	VersionStatus[16]={ 
	'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' 
	};
private	char 	LaPaterne[20] = { 
	'*','P','R','L','@','I','N','F','O','*','#',6,'1','1','a','0','0','1',0 
	};
private	char *	LaPointeur=(char*)0;
private	char 	LaVersion[8];

private	int	convert_integer( char * sptr )
{
	int result=0;
	int	i;
	if (!( sptr ))
		return( result );
	for ( i=0; *(sptr+i) != 0; i++ ) {
		if (( *(sptr+i) >= '0' )
		&&  ( *(sptr+i) <= '9' ))
			result = ((result*10)+( *(sptr+i) - '0' ));
		else	break;
		}
	return( result );
}

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
		else if ( LaPaterne[15] != '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
			}
		else	LaVersion[4] = 0;

		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

BDA	desrt;				/* library description */
extern BDA_INIT FAR PTR rt_init;	/* library signing */
extern BDA_ARG rt_arg;			/* arguments description */

#include "visual.h"
#include "vframe.h"
#include "vconf.h"
#include "vbuffer.h"

/*	Bits to complete the link	*/
/*	-------------------------	*/
public	int	_fltused=0;
public	void	_cfltcvt()	{ 	return; 	}
public	void	_cropzeros()	{ 	return; 	}
public	long	_aFftol()	{	return(0L);	}

#define	MAX_STRING_BUFFER 4096
private	char	stringbuffer[MAX_STRING_BUFFER+1];

public	VOID	allocation_failure( int nb ) { return; } 

BPTR	terminate_string( BPTR sptr, int slen )
{
	int	i;

	for (i=0; i < slen; i++ ) {
		if ( i < MAX_STRING_BUFFER )
			stringbuffer[i] = *(sptr+i);
		else	break;
		}
	stringbuffer[i] = 0;
	return( stringbuffer );
}

BPTR	prefix_string(BPTR pptr, BPTR sptr, int slen )
{
	int	i=0;
	int	j;
	if ( pptr != (BPTR) 0 )
		for (i=0; *(pptr+i) != 0; i++ )
			stringbuffer[i] = *(pptr+i);

	for (j=0; j < slen; j++ ) {
		if ( (i+j) < MAX_STRING_BUFFER )
			stringbuffer[(i+j)] = *(sptr+j);
		else	break;
		}
	stringbuffer[(i+j)] = 0;
	return( stringbuffer );
}

#include "guimouse.h"
#include "visilib.h"

private	void	visual_configuration()
{
	char	*	vptr;
	if ((vptr = configuration_item( "REPLAY" )) != (char *) 0)
		activate_replay( vptr );
	else if ((vptr = configuration_item( "RECORD" )) != (char *) 0)
		activate_record( vptr );
	return;
}

/*	The library stub functions	*/
/*	--------------------------	*/
private EXAWORD AbalTextualInitialise(WORD mode )
{
	EXAWORD	retcode;
	WORD	i;
	for ( i=0; i < MAX_V_BUFFER; i++ )
		TextualBufferHeap[i] = (STDPSUPTR) 0;

	ActiveTextualBuffer = -1;

	visual_configuration();

	return(0);
}

private EXAWORD AbalTextualActivate(WORD width, WORD height)
{
	EXAWORD	retcode;
	WORD	i;
	for ( i=0; i < MAX_V_BUFFER; i++ )
		TextualBufferHeap[i] = (STDPSUPTR) 0;

	ActiveTextualBuffer = -1;

	visual_configuration();

	return(0);
}

private EXAWORD AbalTextualLiberate()
{
	WORD		i;
	STDPSUPTR	pptr;
	for ( i=0; i < MAX_V_BUFFER; i++ ) {
		if (!( pptr = TextualBufferHeap[i] ))
			continue;
		else	TextualBufferHeap[i] = liberate_pixel_storage( pptr );
		}		

	return(0);
}

private EXAWORD AbalTextualZone(WORD x,WORD y,WORD w,WORD h,WORD style)
{
	return(0);
}


private EXAWORD AbalTextualFill(WORD x,WORD y,WORD w,WORD h,WORD pixel,WORD  mode)
{
	return(0);
}

private EXAWORD AbalTextualLine(WORD fx,WORD fy,WORD tx,WORD ty,WORD thick ,WORD pixel)
{
	return(0);
}


private EXAWORD AbalTextualFont(BPTR filename,WORD length)
{
	filename = terminate_string(filename,length);
	return(VisualFont(filename,length));
}


private EXAWORD AbalTextualText(WORD x,WORD y,WORD w,WORD h,WORD fid,
			WORD fg, WORD bg, BPTR message,WORD length, WORD options)
{
	message = terminate_string(message,length);
	return(0);
}

private EXAWORD AbalTextualEdit(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR buffer,WORD length)
{
	char	*	stuffer;
	int		status;
	stuffer = terminate_string(buffer,length);
	return( 0 );
}

private EXAWORD AbalTextualWindow(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR title,WORD length,WORD options)
{
	title = terminate_string(title,length);
	return(0);
}

private EXAWORD AbalTextualViewPort(WORD x,WORD y,WORD w,WORD h,WORD fid)
{
	return(0);
}

private EXAWORD AbalTextualButton(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg,BPTR message,WORD length,WORD state)
{
	message = terminate_string(message,length);
	return(0);
}

private EXAWORD AbalTextualCheck(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD state)
{
	message = terminate_string( message, length );
	return(0);
}

private EXAWORD AbalTextualSwitch(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD state)
{
	message = terminate_string( message, length );
	return(0);
}

private EXAWORD AbalTextualGraph(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR values,WORD length,WORD state)
{
	return(0);
}

private EXAWORD AbalTextualRadio(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, BPTR message,WORD length,WORD storage, WORD value)
{
	message = terminate_string( message, length );
	return(0);
}

private EXAWORD AbalTextualProgress(WORD x,WORD y,WORD w,WORD h,WORD f, WORD fg, WORD bg, WORD l,WORD v, WORD o)
{
	return(0);
}

/*
 *	-------------------------------------------------------------------
 *
 *	--------------------	-------------------------------
 *	INTERFACE FUNCTION :	TEXTUAL BUFFER ( width, height )
 *	--------------------	-------------------------------
 *
 *	Allocates a pixel capture buffer mechanism of the w*h dimensions
 *	and returns a none zero buffer identifier to show Success or ZERO
 *	to indicate (usually memory allocation) Failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualBuffer( WORD width, WORD height )
{
	WORD	i;
	for (i=0; i < MAX_V_BUFFER; i++ )
		if (!( TextualBufferHeap[i] ))
			break;
	if ( i < MAX_V_BUFFER ) {
		if (!( TextualBufferHeap[i] = visual_buffer(0,0, width, height ) ))
			return( -1 );
		else	return((i+1));
		}
	else	return( -1 );
}

/*
 *	-------------------------------------------------------------------
 *
 *		--------------------	-------------------
 *		INTERFACE FUNCTION :	TEXTUAL PAGE ( bid )
 *		--------------------	-------------------
 *
 *	Establishs the buffer mechanism identified by bid as the current 
 *	output catching mechanism. All pixel output will be caught and
 *	made available for pixel input.
 *
 *	Returns the buffer id or ZERO if none.
 *
 *	This function will disactivate any current buffer output mechanism
 *	prior to attempting its operation.
 *
 *	The buffer id ZERO indicates return to screen output !
 *	
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualPage( WORD number )
{
	if ( ActiveTextualBuffer != -1 ) {
		cancel_pixel_capture(TextualBufferHeap[ActiveTextualBuffer]);
		ActiveTextualBuffer = -1;
		}
	if (( number > 0 )
	&&  ( number <= MAX_V_BUFFER )) {
		background_pixel_capture(TextualBufferHeap[(ActiveTextualBuffer=(number-1))]);
		return( number );
		}
	else	return(0);
}

/*
 *	-------------------------------------------------------------------
 *
 *		--------------------	-------------------
 *		INTERFACE FUNCTION :	TEXTUAL DROP ( bid )
 *		--------------------	-------------------
 *	
 *	Disactivates and current active buffer and liberates the
 *	buffer identified by bid.
 *	
 *	Returns bid if ok otherwise zero to indicate failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualDrop( WORD number )
{
	STDPSUPTR	pptr;
	if ( ActiveTextualBuffer != -1 ) {
		cancel_pixel_capture(TextualBufferHeap[ActiveTextualBuffer]);
		ActiveTextualBuffer = -1;
		}
	if (( number > 0 )
	&&  ( number <= MAX_V_BUFFER )) {
		if (!( pptr = TextualBufferHeap[(number-1)] ))
			return(0);
		else	{
			TextualBufferHeap[(number-1)] = visual_drop(pptr);
			return(number);
			}
		}
	else	return(0);
}


/*
 *	--------------------	----------------------------
 *	INTERFACE FUNCTION :	TEXTUAL GET ( bid, atx, aty )
 *	--------------------	----------------------------
 *	
 *	Captures pixels to the buffer identified by bid from the pixel top 
 *	left corner atx,aty of the current Textual Buffer mechanism or from
 *	the Screen if none active, 
 *	
 *	Pixel coordinate values are numbered from 0 to N. 
 *
 *	Returns an indication of its status
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualGet( WORD bid, WORD atx, WORD aty )
{
	STDPSUPTR	pptr;

	/* BID numbering from 1 please */
	/* --------------------------- */
	if (!( bid ))	return(bid);

	/* No need for this */
	/* ---------------- */
	else if ((bid-1) == ActiveTextualBuffer)
		return(0);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( pptr = TextualBufferHeap[ (bid-1) ] ))
		return( 0 );
	
	else if ( visual_buffer_get( pptr, atx, aty ) )
		return( bid );
	else	return( 0 );
}


/*
 *	--------------------	--------------------------------------
 *	INTERFACE FUNCTION :	TEXTUAL GET ROW ( row, result, length )
 *	--------------------	--------------------------------------
 *	
 *	Returns a row of pixels into result up to length from the current
 *	Textual Buffer mechanism or from the Screen if none active.
 *	
 *	Rows are numbered from 1 to N for ABAL convenience
 *
 *	Returns confirmation of the row number or ZERO if failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualGetRow( WORD row, BPTR buffer, WORD length )
{
	STDPSUPTR	pptr;

	/* Row numbering from 1 please */
	/* --------------------------- */
	if (!( row ))	return( 0 );

	/* Check for no buffer active : get from screen */
	/* -------------------------------------------- */
	else if ( ActiveTextualBuffer == -1 )
		getzone( 0,(row-1),length,1, buffer);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( pptr = TextualBufferHeap[ ActiveTextualBuffer ] ))
		return( 0 );

	/* Collect from buffer mechanisms */
	/* ------------------------------ */
	else	collect_pixel_row( pptr, 0, (row-1), length, buffer );

	/* Success */
	/* ------- */
	return( row );
}

/*
 *	--------------------	--------------------------------------
 *	INTERFACE FUNCTION :	TEXTUAL PUT ROW ( row, source, length )
 *	--------------------	--------------------------------------
 *	
 *	Outputs a row of pixels from source up to length into the current
 *	Textual Buffer mechanism or into the Screen if none active.
 *	
 *	Rows are numbered from 1 to N for ABAL convenience
 *
 *	Returns confirmation of the row number or ZERO if failure.
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualPutRow( WORD row, BPTR buffer, WORD length )
{
	BPTR		bptr;
	STDPSUPTR	pptr;

	/* Row numbering from 1 please */
	/* --------------------------- */
	if (!( row ))	return( 0 );

	/* Check for no buffer active : get from screen */
	/* -------------------------------------------- */
	else if ( ActiveTextualBuffer == -1 )
		putzone( 0,(row-1),length,1, buffer);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( pptr = TextualBufferHeap[ ActiveTextualBuffer ] ))
		return( 0 );

	/* Collect row buffer from buffer mechanisms */
	/* ----------------------------------------- */
	else if (!( bptr = connect_pixel_row( pptr, (row-1) ) ))
		return(0);

	/* and fill it from the source buffer */
	/* ---------------------------------- */
	else	memcpy( bptr, buffer, length );

	/* Success */
	/* ------- */
	return( row );
}

EXAWORD AbalTextualPutZone( WORD x, WORD y, WORD w, WORD h,BPTR buffer )
{
	putzone(x,y,w,h,buffer);
	return(0);
}

/*
 *	--------------------	----------------------------
 *	INTERFACE FUNCTION :	TEXTUAL PUT ( bid, atx, aty )
 *	--------------------	----------------------------
 *	
 *	Outputs the contents of the buffer identified by bid at the
 *	pixel top left corner position identifier by atx,aty to the 
 *	current Textual Buffer mechanism or to the Screen if none active.
 *	
 *	Pixel coordinate values are numbered from 0 to N. 
 *
 *	Returns an indication of its status
 *
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualPut( WORD bid, WORD atx, WORD aty )
{
	STDPSUPTR	pptr;

	/* BID numbering from 1 please */
	/* --------------------------- */
	if (!( bid ))	return(bid);

	/* No need for this */
	/* ---------------- */
	else if ((bid-1) == ActiveTextualBuffer)
		return(0);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( pptr = TextualBufferHeap[ (bid-1) ] ))
		return( 0 );

	else if (!( visual_buffer_put( pptr, atx, aty ) ))
		return( 0);
	else	return( bid );

}

/*
 *	--------------------	------------------------------------
 *	INTERFACE FUNCTION :	TEXTUAL TRANSFORM (bid, cmd, p1, p2 )
 *	--------------------	------------------------------------
 *	
 *	Performs transformation described by cmd on buffer identified
 *	by bid activetool operation dependant parameters p1 and p2
 *
 *	0 :	Rotate	p1 distance, 90, 180, 270
 *	1 :	Reflect	p1 direction 0:vertical axis, 1:horizontal axis
 *	2 :	Resize  p1,p2 provides new coordinates for cut or fill
 *	3 :	Makefit p1,p2 provides new coordinates for squash or stretc
 *
 */

EXAWORD AbalTextualTransform( WORD bid, WORD cmd, WORD p1, WORD p2 )
{
	WORD		sw;
	WORD		sh;
	STDPSUPTR	pptr;
	STDPSUPTR	rptr;

	if ( ActiveTextualBuffer != -1 ) {
		cancel_pixel_capture(TextualBufferHeap[ActiveTextualBuffer]);
		ActiveTextualBuffer = -1;
		}

	/* BID numbering from 1 please */
	/* --------------------------- */
	if (!( bid ))	
		return(56);

	/* Failure on invalid buffer control */
	/* --------------------------------- */
	else if (!( pptr = TextualBufferHeap[ (bid-1) ] ))
		return(56);

	switch ( cmd ) {

		case	_TRANSFORM_ROTATE	:
			if ( p1 == 180 )
				return( vrotate180( pptr ) );
			else if (!( rptr = allocate_graphic_storage( 0,0, 
					pptr->descriptor[1],pptr->descriptor[0] ) ))
				return(27);
			else 	{
				if ( p1 == 90 )
					p1 = vrotate(1, rptr, pptr  );
				else	p1 = vrotate(0, rptr, pptr  );
				if (!( p1 )) {
					pptr = liberate_pixel_storage( pptr );
					TextualBufferHeap[ (bid-1) ] = rptr;
					}
				else	rptr = liberate_pixel_storage( rptr );
				return( p1 );
				}

		case	_TRANSFORM_REFLECT	:
		case	_TRANSFORM_RESIZE	:
		case	_TRANSFORM_MAKEFIT	:

		default				:

			return( 55 );

		}

}

/*
 *	--------------------	-------------------------------------------
 *	INTERFACE FUNCTION :	TEXTUAL COLOUR  ( cmd, buffer, first, last )
 *	--------------------	-------------------------------------------
 *	
 *	Performs the indicated colour operation activetool the buffer from the
 *	the first to last colour map entries.
 *
 *	-------------------------------------------------------------------
 *	Commands ARE :	0	Get colours
 *			1	Put colours
 *	-------------------------------------------------------------------
 *	others MAY be:	2	Increment Red
 *			3	Increment Green
 *			4	Increment Blue
 *			5	Decrement Red
 *			6	Decrement Green
 *			7	Decrement Blue
 *	-------------------------------------------------------------------
 *	Returns the status of the requested operation which may fail 
 *	due to an incorrect command.
 *	-------------------------------------------------------------------
 */

EXAWORD AbalTextualColour( WORD cmd, BPTR buffer, WORD first, WORD last )
{
	return(0);
}


EXAWORD AbalTextualTable( WORD x, WORD y, WORD w, WORD h, WORD f, WORD fg, WORD bg,
		BPTR tptr, WORD tlen, BPTR vptr, WORD vlen, WORD options,BPTR fptr, WORD flen )
{
	tptr = terminate_string( tptr, tlen);
	return(0);
}

private EXAWORD AbalTextualImage(WORD x,WORD y,WORD w,WORD h,BPTR filename,WORD length, WORD options) 
{
	struct standard_image * iptr;
	filename = terminate_string(filename,length);
	return(0);
}


private EXAWORD AbalTextualTabPage(WORD x,WORD y,WORD w,WORD h,WORD fid,BPTR title,WORD length,WORD offset,WORD control)
{
	title = terminate_string( title, length );
	return(0);
}

private EXAWORD AbalTextualSelect(
		WORD x,WORD y,WORD w,WORD h,
		WORD fid, WORD fg, WORD bg, 
		BPTR message,WORD length,BPTR iptr,WORD state)
{
	WORD	item;
	int	keycode;
	struct  select_control * Selection;

	message = terminate_string( message, length );
	if ((item = AbalGetWord( iptr )) > 0)
		item--;

	return(0);
}


	
private EXAWORD AbalTextualScroll(WORD x,WORD y,WORD w,WORD h,WORD fid,WORD fg, WORD bg, WORD item, WORD limit, WORD total, WORD style)
{
	return(0);
}

private EXAWORD AbalTextualPalette(BPTR filename,WORD length)
{
	filename = terminate_string(filename,length);
	return(0);
}

private EXAWORD AbalTextualFreeze()
{
	return(0);
}

private EXAWORD AbalTextualThaw(WORD x,WORD y,WORD w,WORD h)
{
	return(0);
}

private	VOID	PutAbalWord( BPTR rptr, WORD v )
{
	*(rptr+1) = (v & 0x00FF);
	*(rptr)   = ((v>>8) & 0x00FF);
	return;
}

private EXAWORD AbalTextualEvent(BPTR result)
{
	WORD	v;
	WORD	e;
	e = VisualEvent(1);
	PutAbalWord(result,e);
	v = VisualEvent(2);
	PutAbalWord(result+2,v);
	if (((v = VisualEvent(7)) != 0)
	||  (e != _MIMO_UP ))
		PutAbalWord(result+4,v);
	if (((v = VisualEvent(6)) != 0)
	||  (e != _MIMO_UP ))
		PutAbalWord(result+6,v);
	return(256);
}

private EXAWORD AbalTextualKey(WORD mode)
{
	switch ( mode ) {
		case	0 :	return( VisualKbhit() );
		case 	2 :	if (!( VisualKbhit() )) 
					break;
		case	1 :	return( VisualGetch() );
		}
	return(-1);
}

private EXAWORD AbalTextualControl(WORD command, BPTR buffer, WORD buflen )
{
	FILE	*	handle;
	char	*	vptr;
	int	i;
	switch ( command ) {
		case	_VISUAL_VERSION		:
			if (!( vptr = getpatternversion() ))
				return(56);
			else if ( buflen < strlen(vptr ) )
				return(63);
			else	{
				memset(buffer,' ',buflen );
				while ( *vptr )
					*(buffer++) = *(vptr++);
				return(0);
				}

		case	_VISUAL_RECORD 		:
			buffer = terminate_string(buffer,buflen);
			return( activate_record( buffer ) );

		case	_VISUAL_REPLAY 		:
			buffer = terminate_string(buffer,buflen);
			return( activate_replay( buffer ) );

		case	_VISUAL_CONFIG		:
			buffer = terminate_string(buffer,buflen);
			terminate_configuration();
			return( initialise_configuration( buffer ) );
			break;

		case	_VISUAL_FONTWIDTH	:
			if (!(i = convert_integer( buffer )))
				return(0);
			else if (!( i = guifontsize(i) ))
				return(0);
			else	return( i & 0x00FF );

		case	_VISUAL_FONTHEIGHT	:
			if (!(i = convert_integer( buffer )))
				return(0);
			else if (!( i = guifontsize(i) ))
				return(0);
			else	return(( i >> 8) & 0x00FF );

		case	_VISUAL_TRACE  		:
			buffer = terminate_string(buffer,buflen);
			printf("%s\r\n",buffer);
			return(0);

		case	_VISUAL_TITLE 		:
			buffer = terminate_string(buffer,buflen);
			return( windowtitle( buffer ) );


		case	_VISUAL_ICON 		:
			buffer = terminate_string(buffer,buflen);
			return( windowicon( buffer ) );

		case	_VISUAL_HELP 		:
			buffer = terminate_string(buffer,buflen);
			return( visual_help( buffer ) );

		case	_VISUAL_HOTKEY	:
			return( visual_hotkeys( buffer, buflen ) );

		default				:
			return(56);
		}
	return(0);
}


/*	----------------------		*/
/*	Library identification		*/
/*	----------------------		*/
private	VOID FAR banniere()
{ 
	printf("\n   AbalTextual Library : TEXTUAL ");
	printf("\n   Version %s ",getpatternversion());

	if ( VersionStatus[15] == '2' )
		printf("\n   Provisoire du    %s",__TEXTUAL_DATE);

	printf("\n   Copyright (c) 2002 Amenesik / Sologic \n");
	printf("\n\t %u  %% TextualZone(x%%,y%%,w%%,h%,p%%)",_VISUAL_DLL_ZONE);
	printf("\n\t %u  %% TextualLine(x%%,y%%,x%%,y%%,n%%,p%%)",_VISUAL_DLL_LINE);
	printf("\n\t %u  %% TextualFont(fontname$,lng%%)",_VISUAL_DLL_FONT);
	printf("\n\t %u  %% TextualText(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,options%%)",_VISUAL_DLL_TEXT);
	printf("\n\t %u  %% TextualEdit(x%%,y%%,w%%,h%%,fid%%,buffer$?,lng%%)",_VISUAL_DLL_EDIT);
	printf("\n\t %u  %% TextualWindow(x%%,y%%,w%%,h%%,fid%%,msg$,lng%%,opt%%)",_VISUAL_DLL_WINDOW);
	printf("\n\t %u  %% TextualButton(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_BUTTON);
	printf("\n\t %u  %% TextualCheck(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_CHECK);
	printf("\n\t %u  %% TextualRadio(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_RADIO);
	printf("\n\t %u  %% TextualImage(x%%,y%%,w%%,h%%,filename$,lng%%)",_VISUAL_DLL_IMAGE);
	printf("\n\t %u  %% TextualTabPage(x%%,y%%,w%%,h%%,fid%%,msg$,lng%%,offset%%,state%%)",_VISUAL_DLL_TABPAGE);
	printf("\n\t %u  %% TextualSelect(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,item%%,state%%)",_VISUAL_DLL_SELECT);
	printf("\n\t %u  %% TextualScroll(x%%,y%%,w%%,h%%,fid%%,nombre%%)",_VISUAL_DLL_SCROLL);
	printf("\n\t %u  %% TextualPalette(filename$,lng%%)",_VISUAL_DLL_PALETTE);
	printf("\n\t %u  %% TextualInitialise(options%%)",_VISUAL_DLL_INITIALISE);
	printf("\n\t %u  %% TextualLiberate()",_VISUAL_DLL_LIBERATE);
	printf("\n\t %u  %% TextualFreeze()",_VISUAL_DLL_FREEZE);
	printf("\n\t %u  %% TextualThaw(x%%,y%%,w%%,h%%)",_VISUAL_DLL_THAW);
	printf("\n\t %u  %% TextualEvent(buffer$?)",_VISUAL_DLL_EVENT);
	printf("\n\t %u  %% TextualFill(x%%,y%%,w%%,h%%,colour%%)",_VISUAL_DLL_FILL);
	printf("\n\t %u  %% TextualKey(mode%%)",_VISUAL_DLL_KEY);
	printf("\n\t %u  %% TextualControl(option%%,buffer$?,length%%)",_VISUAL_DLL_CONTROL);
	printf("\n\t %u  %% TextualProgress(x%%,y%%,w%%,h%%,f%%,fg%%,bg%%,l%%,v%%,o%%)",_VISUAL_DLL_PROGRESS);
	printf("\n\t %u  %% TextualTable(x%%,y%%,w%%,h%%,f%%,fg%%,bg%%,tptr$,tlen%%,vptr$,vlen%%,o%%)",_VISUAL_DLL_TABLE);
	printf("\n\t %u  %% TextualColour(buffer$?,first%%,last%%)",_VISUAL_DLL_COLOUR);

	printf("\n\t %u  %% TextualBuffer(width%%,height%%)",_VISUAL_DLL_BUFFER);
	printf("\n\t %u  %% TextualPage(number%%)",_VISUAL_DLL_PAGE);
	printf("\n\t %u  %% TextualGet(number%%,x%%,y%%)",_VISUAL_DLL_GET);
	printf("\n\t %u  %% TextualGetRow(r%%,buffer$?,buflin%)",_VISUAL_DLL_GETROW);
	printf("\n\t %u  %% TextualPutRow(r%%,buffer$,buflin%)",_VISUAL_DLL_PUTROW);
	printf("\n\t %u  %% TextualPut(number%%,x%%,y%%)",_VISUAL_DLL_PUT);
	printf("\n\t %u  %% TextualDrop(number%%)",_VISUAL_DLL_DROP);
	printf("\n\t %u  %% TextualTransform(number%%,cmd%%,p1%%,p2%%)",_VISUAL_DLL_TRANSFORM);
	printf("\n\t %u  %% TextualSwitch(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,msg$,lng%%,state%%)",_VISUAL_DLL_SWITCH);
	printf("\n\t %u  %% TextualGraph(x%%,y%%,w%%,h%%,fid%%,fg%%,bg%%,values$,lng%%,state%%)",_VISUAL_DLL_GRAPH);
	printf("\n\t %u  %% TextualActivate(width%%,height%%)\n",_VISUAL_DLL_ACTIVATE);
	return;
	
}

#ifdef	UNIX

/*	--------------------------------------		*/
/*	Elements of the CICO Access Controller		*/
/*	--------------------------------------		*/

struct	cico_access_controller	{

	WORD   FunctionCount;
	WORD  (*FunctionRelay[CICO_NOMBRE])();

	} CicoAccessController;


/*	--------------------------------------		*/
/*	Access Controller Basic Initialisation		*/
/*	--------------------------------------		*/

void	initialise_access_controller()
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

void *	redirect_access_controller( int	item,  void *	fptr )
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

void  	connect_access_controller( BDA_INIT * iptr, void * eptr )
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

public	int	x_graph(int i, void * dptr )
{
	return( (CicoAccessController.FunctionRelay[CICO_GRAPH])(i,dptr) );
}

public	int	x_event(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(i) );

}
public	int	x_putch(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CO])(i) );

}
public	int	x_conf(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CONF])(i) );

}
#endif

/* 	------------------	*/
/* 	DLL initialisation	*/
/* 	------------------	*/
VOID FAR PTR InitRelais()
{ 
#ifdef	UNIX
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_REDIRECT;
#else
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;
#endif
	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;

	desrt.nombre = _VISUAL_DLL_FUNCTION;
#ifdef	UNIX
	initialise_access_controller();
#endif

#ifdef vms

	desrt.nom[_VISUAL_DLL_ZONE]	= (BYTE FAR PTR) "_AbalTextualZone";
	desrt.nom[_VISUAL_DLL_LINE]	= (BYTE FAR PTR) "_AbalTextualLine";
	desrt.nom[_VISUAL_DLL_FONT]	= (BYTE FAR PTR) "_AbalTextualFont";
	desrt.nom[_VISUAL_DLL_TEXT]	= (BYTE FAR PTR) "_AbalTextualText";
	desrt.nom[_VISUAL_DLL_EDIT]	= (BYTE FAR PTR) "_AbalTextualEdit";
	desrt.nom[_VISUAL_DLL_WINDOW]	= (BYTE FAR PTR) "_AbalTextualWindow";
	desrt.nom[_VISUAL_DLL_BUTTON]	= (BYTE FAR PTR) "_AbalTextualButton";
	desrt.nom[_VISUAL_DLL_CHECK]	= (BYTE FAR PTR) "_AbalTextualCheck";
	desrt.nom[_VISUAL_DLL_RADIO]	= (BYTE FAR PTR) "_AbalTextualRadio";
	desrt.nom[_VISUAL_DLL_IMAGE]	= (BYTE FAR PTR) "_AbalTextualImage";
	desrt.nom[_VISUAL_DLL_TABPAGE]	= (BYTE FAR PTR) "_AbalTextualTabPage";
	desrt.nom[_VISUAL_DLL_SELECT]	= (BYTE FAR PTR) "_AbalTextualSelect";
	desrt.nom[_VISUAL_DLL_SCROLL]	= (BYTE FAR PTR) "_AbalTextualScroll";
	desrt.nom[_VISUAL_DLL_PALETTE]	= (BYTE FAR PTR) "_AbalTextualPalette";
	desrt.nom[_VISUAL_DLL_INITIALISE]=(BYTE FAR PTR) "_AbalTextualInitialise";
	desrt.nom[_VISUAL_DLL_LIBERATE] = (BYTE FAR PTR) "_AbalTextualLiberate";
	desrt.nom[_VISUAL_DLL_FREEZE]   = (BYTE FAR PTR) "_AbalTextualFreeze";
	desrt.nom[_VISUAL_DLL_THAW]     = (BYTE FAR PTR) "_AbalTextualThaw";
	desrt.nom[_VISUAL_DLL_EVENT]    = (BYTE FAR PTR) "_AbalTextualEvent";
	desrt.nom[_VISUAL_DLL_FILL]     = (BYTE FAR PTR) "_AbalTextualFill";
	desrt.nom[_VISUAL_DLL_KEY ]     = (BYTE FAR PTR) "_AbalTextualKey";
	desrt.nom[_VISUAL_DLL_CONTROL]  = (BYTE FAR PTR) "_AbalTextualControl";
	desrt.nom[_VISUAL_DLL_PROGRESS] = (BYTE FAR PTR) "_AbalTextualProgress";
	desrt.nom[_VISUAL_DLL_TABLE]  	= (BYTE FAR PTR) "_AbalTextualTable";
	desrt.nom[_VISUAL_DLL_COLOUR]	= (BYTE FAR PTR) "_AbalTextualColour";
	desrt.nom[_VISUAL_DLL_BUFFER]  	= (BYTE FAR PTR) "_AbalTextualBuffer";
	desrt.nom[_VISUAL_DLL_PAGE] 	= (BYTE FAR PTR) "_AbalTextualPage";
	desrt.nom[_VISUAL_DLL_GET]  	= (BYTE FAR PTR) "_AbalTextualGet";
	desrt.nom[_VISUAL_DLL_GETROW]  	= (BYTE FAR PTR) "_AbalTextualGetRow";
	desrt.nom[_VISUAL_DLL_PUTROW]  	= (BYTE FAR PTR) "_AbalTextualPutRow";
	desrt.nom[_VISUAL_DLL_PUT]  	= (BYTE FAR PTR) "_AbalTextualPut";
	desrt.nom[_VISUAL_DLL_DROP]  	= (BYTE FAR PTR) "_AbalTextualDrop";
	desrt.nom[_VISUAL_DLL_TRANSFORM]= (BYTE FAR PTR) "_AbalTextualTransform";
	desrt.nom[_VISUAL_DLL_PUTZONE]= (BYTE FAR PTR) "_AbalTextualPutZone";
	desrt.nom[_VISUAL_DLL_SWITCH]	= (BYTE FAR PTR) "_AbalTextualSwitch";
	desrt.nom[_VISUAL_DLL_GRAPH]	= (BYTE FAR PTR) "_AbalTextualGraph";
	desrt.nom[_VISUAL_DLL_ACTIVATE] =(BYTE FAR PTR) "_AbalTextualActivate";
	desrt.nom[_VISUAL_DLL_VIEWPORT] =(BYTE FAR PTR) "_AbalTextualViewPort";

	/* ----- */
#else 	/* ! vms */
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;

	desrt.fonction[_VISUAL_DLL_ZONE]	= (WORD (FAR PTR)()) AbalTextualZone;
	desrt.fonction[_VISUAL_DLL_LINE]	= (WORD (FAR PTR)()) AbalTextualLine;
	desrt.fonction[_VISUAL_DLL_FONT]	= (WORD (FAR PTR)()) AbalTextualFont;
	desrt.fonction[_VISUAL_DLL_TEXT]	= (WORD (FAR PTR)()) AbalTextualText;
	desrt.fonction[_VISUAL_DLL_EDIT]	= (WORD (FAR PTR)()) AbalTextualEdit;
	desrt.fonction[_VISUAL_DLL_WINDOW]	= (WORD (FAR PTR)()) AbalTextualWindow;
	desrt.fonction[_VISUAL_DLL_BUTTON]	= (WORD (FAR PTR)()) AbalTextualButton;
	desrt.fonction[_VISUAL_DLL_CHECK]	= (WORD (FAR PTR)()) AbalTextualCheck;
	desrt.fonction[_VISUAL_DLL_RADIO]	= (WORD (FAR PTR)()) AbalTextualRadio;
	desrt.fonction[_VISUAL_DLL_IMAGE]	= (WORD (FAR PTR)()) AbalTextualImage;
	desrt.fonction[_VISUAL_DLL_TABPAGE]	= (WORD (FAR PTR)()) AbalTextualTabPage;
	desrt.fonction[_VISUAL_DLL_SELECT]	= (WORD (FAR PTR)()) AbalTextualSelect;
	desrt.fonction[_VISUAL_DLL_SCROLL]	= (WORD (FAR PTR)()) AbalTextualScroll;
	desrt.fonction[_VISUAL_DLL_PALETTE]	= (WORD (FAR PTR)()) AbalTextualPalette;
	desrt.fonction[_VISUAL_DLL_INITIALISE]  = (WORD (FAR PTR)()) AbalTextualInitialise;
	desrt.fonction[_VISUAL_DLL_LIBERATE]  	= (WORD (FAR PTR)()) AbalTextualLiberate;
	desrt.fonction[_VISUAL_DLL_FREEZE]      = (WORD (FAR PTR)()) AbalTextualFreeze;
	desrt.fonction[_VISUAL_DLL_THAW]        = (WORD (FAR PTR)()) AbalTextualThaw;
	desrt.fonction[_VISUAL_DLL_EVENT]      	= (WORD (FAR PTR)()) AbalTextualEvent;
	desrt.fonction[_VISUAL_DLL_FILL]      	= (WORD (FAR PTR)()) AbalTextualFill;
	desrt.fonction[_VISUAL_DLL_KEY ]      	= (WORD (FAR PTR)()) AbalTextualKey;
	desrt.fonction[_VISUAL_DLL_CONTROL ]   	= (WORD (FAR PTR)()) AbalTextualControl;
	desrt.fonction[_VISUAL_DLL_PROGRESS ]   = (WORD (FAR PTR)()) AbalTextualProgress;
	desrt.fonction[_VISUAL_DLL_TABLE ]	= (WORD (FAR PTR)()) AbalTextualTable;
	desrt.fonction[_VISUAL_DLL_COLOUR]	= (WORD (FAR PTR)()) AbalTextualColour;  
	desrt.fonction[_VISUAL_DLL_BUFFER]	= (WORD (FAR PTR)()) AbalTextualBuffer;
	desrt.fonction[_VISUAL_DLL_PAGE  ]	= (WORD (FAR PTR)()) AbalTextualPage; 
	desrt.fonction[_VISUAL_DLL_GET   ]	= (WORD (FAR PTR)()) AbalTextualGet;  
	desrt.fonction[_VISUAL_DLL_GETROW]	= (WORD (FAR PTR)()) AbalTextualGetRow;
	desrt.fonction[_VISUAL_DLL_PUTROW]	= (WORD (FAR PTR)()) AbalTextualPutRow;
	desrt.fonction[_VISUAL_DLL_PUT   ]	= (WORD (FAR PTR)()) AbalTextualPut;
	desrt.fonction[_VISUAL_DLL_DROP  ]	= (WORD (FAR PTR)()) AbalTextualDrop;
	desrt.fonction[_VISUAL_DLL_TRANSFORM]	= (WORD (FAR PTR)()) AbalTextualTransform;
	desrt.fonction[_VISUAL_DLL_PUTZONE]	= (WORD (FAR PTR)()) AbalTextualPutZone;
	desrt.fonction[_VISUAL_DLL_SWITCH]	= (WORD (FAR PTR)()) AbalTextualSwitch;
	desrt.fonction[_VISUAL_DLL_GRAPH]	= (WORD (FAR PTR)()) AbalTextualGraph;
	desrt.fonction[_VISUAL_DLL_ACTIVATE]    = (WORD (FAR PTR)()) AbalTextualActivate;
	desrt.fonction[_VISUAL_DLL_VIEWPORT]    = (WORD (FAR PTR)()) AbalTextualViewPort;
#ifdef	UNIX
	desrt.fonction[_VISUAL_DLL_FUNCTION+1]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+2]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+3]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+4]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+5]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+6]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+7]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+8]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+9]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+10]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+11]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+12]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+13]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+14]	= (WORD (FAR PTR)()) 0;
	desrt.fonction[_VISUAL_DLL_FUNCTION+15]	= connect_access_controller;
	desrt.fonction[_VISUAL_DLL_FUNCTION+16]	= (WORD (FAR PTR)()) 0;

	if (rt_init != (VOID FAR PTR) 0L) {
		rt_init->cico.numero = 16384;
		rt_init->cico.fonction[CICO_CI]     = desrt.fonction[_VISUAL_DLL_FUNCTION+1]; 
	 	rt_init->cico.fonction[CICO_TPCI]   = desrt.fonction[_VISUAL_DLL_FUNCTION+2];
	  	rt_init->cico.fonction[CICO_PRFO]   = desrt.fonction[_VISUAL_DLL_FUNCTION+3];  	
		rt_init->cico.fonction[CICO_LCFO]   = desrt.fonction[_VISUAL_DLL_FUNCTION+4];  	
		rt_init->cico.fonction[CICO_CONF]   = desrt.fonction[_VISUAL_DLL_FUNCTION+5]; 	
		rt_init->cico.fonction[CICO_CO]     = desrt.fonction[_VISUAL_DLL_FUNCTION+6]; 	
		rt_init->cico.fonction[CICO_MES]    = desrt.fonction[_VISUAL_DLL_FUNCTION+7]; 	
		rt_init->cico.fonction[CICO_LIGNE]  = desrt.fonction[_VISUAL_DLL_FUNCTION+8]; 	
		rt_init->cico.fonction[CICO_COLONNE]= desrt.fonction[_VISUAL_DLL_FUNCTION+9]; 	
		rt_init->cico.fonction[CICO_START]  = desrt.fonction[_VISUAL_DLL_FUNCTION+10]; 	
		rt_init->cico.fonction[CICO_FLUSH]  = desrt.fonction[_VISUAL_DLL_FUNCTION+11]; 	
		rt_init->cico.fonction[CICO_LO]     = desrt.fonction[_VISUAL_DLL_FUNCTION+12]; 	
		rt_init->cico.fonction[CICO_MIMA]   = desrt.fonction[_VISUAL_DLL_FUNCTION+13];   
		rt_init->cico.fonction[CICO_EVENT]  = desrt.fonction[_VISUAL_DLL_FUNCTION+14];
		rt_init->cico.fonction[CICO_INIT]   = desrt.fonction[_VISUAL_DLL_FUNCTION+15];
		rt_init->cico.fonction[CICO_GRAPH]  = desrt.fonction[_VISUAL_DLL_FUNCTION+16];
		}
#endif

#endif /* vms */

	return((VOID FAR PTR) &desrt);

}

	/* ----------- */
#endif	/* _TEXTUAL_C  */
	/* ----------- */



