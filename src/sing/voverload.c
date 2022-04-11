#ifndef	_voverload_c
#define	_voverload_c

#include "xgraph.h"

/*	---------------------------------------------------------------------------	*/
/*				v i s u a l _ o v e r l o a d
/*	---------------------------------------------------------------------------	*/
/*	This file provides a standard mechanism for the overloading of the x_graph	*/
/*	descriptor based interface to the underlying pixel graphics mechanisms.		*/
/*	The postscript printer library makes use of this technique but does not 	*/
/*	currently make use of this file.						*/
/*	---------------------------------------------------------------------------	*/

/*	---------------------------------	*/
/*	The various overlaod state values	*/
/*	---------------------------------	*/
#define	_OVERLOAD_ACTIVE	1		/* if not active ... nothing happens	*/
#define	_OVERLOAD_SWITCH	2		/* if not active only buffer switching	*/
#define	_OVERLOAD_PASSTHRU	4		/* if not active no pass through echo	*/

/*	---------------------------------	*/
/*	The relay value that was overload	*/
/*	---------------------------------	*/
#define previous_x_graph (*XgraphRelay)

/*	---------------------------------	*/
/*	the overloaded function pointers	*/
/*	---------------------------------	*/
struct	overload_interface
{
	int	status;
	int	font;
	int	attribute;
	int	foreground;
	int	background;
	int	(*fill_item)( int x, int y, int w , int h, int colour );
	int	(*xfill_item)( int x, int y, int w , int h, int colour );
	int	(*circle_item)( int x, int y, int w , int h, int colour, int length );
	int	(*roundfill_item)( int x, int y, int w , int h, int colour );
	int	(*roundframe_item)( int x, int y, int w , int h, int colour);
	int	(*line_item)( int x, int y, int w , int h,int length, int colour );
	int	(*image_item)( int x, int y, int w , int h, char * buffer, int length );
	int	(*print_colour)( int foregr, int backgr );
	int	(*text_item)(  int x, int y, int font, char * buffer, int length, int w, int h, int value );

} overload = {
	0,
	0,
	0,
	0,0,
	(void *) 0, 	
	(void *) 0, 
	(void *) 0, 
	(void *) 0, 
	(void *) 0, 
	(void *) 0, 
	(void *) 0, 
	(void *) 0, 
	(void *) 0, 
	(void *) 0
	};


/*	-------------------------------------------	*/
/*	s e t _ o v e r l o a d _ i n t e r f a c e	*/
/*	-------------------------------------------	*/
/*	called to set or unset a particular item in	*/
/*	the overloaded function interface table.	*/
/*	-------------------------------------------	*/
void	set_overload_interface( int item, void * vptr )
{
	switch( item )
	{
	case	1	:	overload.fill_item	= vptr; break; 
	case	2	:	overload.xfill_item	= vptr; break; 
	case	3	:	overload.circle_item	= vptr; break; 
	case	4	:	overload.roundfill_item	= vptr; break; 
	case	5	:	overload.roundframe_item= vptr; break; 
	case	6	:	overload.line_item	= vptr; break; 
	case	7	:	overload.image_item	= vptr; break; 
	case	8	:	overload.print_colour	= vptr; break; 
	case	9	:	overload.text_item	= vptr; break; 
	}
}
	
/*	-------------------------------------------	*/
/*	      o v e r l o a d _ x _ g r a p h		*/
/*	-------------------------------------------	*/
/*	this function is called through the normal	*/
/*	x_graph relay and performs function filter	*/
/*	pass through or new operations depending on	*/
/*	the current internal state of the interface	*/
/*	-------------------------------------------	*/
public	int	overload_x_graph( int xgcode, struct x_graph_descriptor * dptr )
{
	char	*	cptr;
	int		i;
	int		l;
	char	*	wptr;
	char		character[2];

	if (!( overload.status & _OVERLOAD_ACTIVE ))
		return( previous_x_graph(xgcode,dptr) );

	switch ( xgcode ) {

		case	_XGR_HARDWARE	:
			overload.status &= ~(_OVERLOAD_ACTIVE | _OVERLOAD_SWITCH);
			return( previous_x_graph(xgcode,dptr) );

		case	_XGR_SOFTWARE	:
			overload.status |= (_OVERLOAD_ACTIVE | _OVERLOAD_SWITCH);
			return( previous_x_graph(xgcode,dptr) );
					
		}

	if (!( overload.status & _OVERLOAD_SWITCH ))
		return( previous_x_graph(xgcode,dptr) );

	switch ( xgcode ) {
		case	_XGR_XFILZONE	:
			(*overload.xfill_item)( 
				dptr->zone.x,
				dptr->zone.y,
				dptr->zone.w,
				dptr->zone.h, 
				dptr->foreground);
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_FILZONE	:
			(*overload.fill_item)( 
				dptr->zone.x,
				dptr->zone.y,
				dptr->zone.w,
				dptr->zone.h, 
				dptr->foreground);
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_CIRCLE 	:
			if ( dptr->buffer )
				(*overload.circle_item)( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->foreground,
					dptr->length  );

			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_ROUNDFILZONE 	:
			if ( dptr->buffer )
				(*overload.roundfill_item)( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->foreground);

			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_ROUNDFRAME 	:
			if ( dptr->buffer )
				(*overload.roundframe_item)( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->foreground);

			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );


		case	_XGR_LINE 	:
			if ( dptr->buffer )
				(*overload.line_item)( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->length,
					dptr->foreground  );
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_IMAGE	:
			if ( dptr->buffer )
				(*overload.image_item)( dptr->zone.x, dptr->zone.y, dptr->zone.w, dptr->zone.h, dptr->buffer, dptr->length );
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_FONTSIZE	:
			return( previous_x_graph(xgcode,dptr) );

		case	_XGR_USEFONT  	:
			overload.font = dptr->fontnumber;			
			return( previous_x_graph(xgcode,dptr) );
		
		case	_XGR_ATRIBUT	:
			overload.attribute = dptr->zone.x;
			return( previous_x_graph(xgcode,dptr) );

		case	_XGR_COLOUR  	:
			(*overload.print_colour)( dptr->foreground,dptr->background);
			return( previous_x_graph(xgcode,dptr) );

		case	_XGR_PUTC	:
			return( previous_x_graph(xgcode,dptr) );

		case	_XGR_FONTC	:
			return( previous_x_graph(xgcode,dptr) );

		case	_XGR_PUTCAT	:
			return( previous_x_graph(xgcode,dptr) );

		case	_XGR_FONTCAT	:
			if ( dptr->buffer )
			{
				character[0] = dptr->value;
				character[1] = 0;
				(*overload.text_item)( dptr->zone.x, dptr->zone.y, dptr->fontnumber, character, 1, 0,0, -1 );
			}
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else 	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_PUTS	:
			if ( dptr->buffer )
				(*overload.text_item)( -1,-1, overload.font,dptr->buffer, strlen(dptr->buffer), 0,0, -1);
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_FONTS	:
			if ( dptr->buffer )
				(*overload.text_item)( -1,-1, dptr->fontnumber,dptr->buffer, strlen(dptr->buffer), 0,0, -1);
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_PUTSAT	:
			if ( dptr->buffer )
				(*overload.text_item)( dptr->zone.x, dptr->zone.y, overload.font,dptr->buffer, strlen(dptr->buffer), 0,0, -1 );
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_PUTL	:
			if ( dptr->buffer )
				(*overload.text_item)( -1,-1, overload.font,dptr->buffer, dptr->length, 0,0, -1);
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_FONTL	:
			if ( dptr->buffer )
				(*overload.text_item)( -1,-1, dptr->fontnumber,dptr->buffer, dptr->length, 0,0, -1);
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_PUTLAT	:
			if ( dptr->buffer )
				(*overload.text_item)( dptr->zone.x, dptr->zone.y, overload.font,dptr->buffer, dptr->length, 0,0, -1 );
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_FONTSAT	:
			if ( dptr->buffer )
				(*overload.text_item)( dptr->zone.x, dptr->zone.y, dptr->fontnumber,dptr->buffer, strlen( dptr->buffer), 0,0, -1 );
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_ALIGN	:
			if ((cptr = dptr->buffer) != (char *) 0) {
				if (!( wptr =allocate( strlen( cptr ) + 1 )))
					return(0);
				else	{
					strcpy(wptr,cptr);
					cptr = wptr;
					}
				while ( *cptr == ' ' ) {
					cptr++;
					if ( dptr->length )
						dptr->length--;
					}
				for ( l=0,i=0; i < dptr->length; i++ ) {
					if ( *(cptr+i) != ' ' )
						l = (i+1);
					}
				*(cptr+l) = 0;
				dptr->length = l;
				(*overload.text_item)( dptr->zone.x, dptr->zone.y, dptr->fontnumber,cptr, dptr->length, dptr->zone.w, dptr->zone.h, dptr->value );
				liberate( wptr );
				}
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );


		case	_XGR_FONTLAT	:
			if ( dptr->buffer )
				(*overload.text_item)( dptr->zone.x, dptr->zone.y, dptr->fontnumber,dptr->buffer, dptr->length, 0,0, -1 );
			if (!( overload.status & _OVERLOAD_PASSTHRU ))
				return(0);
			else	return( previous_x_graph(xgcode,dptr) );

		case	_XGR_TEXTSIZE	:
			return( previous_x_graph(xgcode,dptr) );

		default			:
			return( previous_x_graph(xgcode,dptr) );
		}
}

	/* ------------ */
#endif	/* _voverload_c */
	/* ------------ */



