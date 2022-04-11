#ifndef	_x_graph_c
#define	_x_graph_c

#include "xgraph.h"
#include "stdpsu.h"
#include "pixel.h"

#define	_TRACE_XGRAPH

#ifdef	_TRACE_XGRAPH
#include <stdio.h>
static	int	firstime=1;
static	FILE * 	xgraph_handle=(FILE *) 0;
static	char * 	xgraph_name=(char *) 0;
#endif

int	xgr_rescale( int vv )
{
	return( scaled_dimension( vv ) );
}


void	xgr_set_scale( int v )
{
	XGC.scale = v;
	return;
}

int	xgr_get_scale()
{
	return( XGC.scale );
}


int	textalign(int x, int y, int w , int h, int f, char * mptr, int mlen, int a)
{
	return(0);
}

int	xgr_graph(int operation, struct x_graph_descriptor * dptr )
{
	int	v=0;
#ifdef	_TRACE_XGRAPH
	if ( firstime ) {
		if ((xgraph_name = getenv("XGRAPH_TRACE")) != (char *) 0)
			xgraph_handle = fopen( xgraph_name, "w" );
		firstime = 0;
		}
	if ( xgraph_handle != (FILE *) 0 ) {
		fprintf(xgraph_handle,"xgr( scale=%u op=0x%04.4x, mode=%u ,x=%u,y=%u,w=%u,h=%u ,buffer=%lu, l=%u, font=%u, fg=%u, bg=%u )\r\n",
			XGC.scale,
			operation,
			dptr->biosmode,
			scaled_coordinate(dptr->zone.x),
			scaled_coordinate(dptr->zone.y),
			scaled_dimension(dptr->zone.w),
			scaled_dimension(dptr->zone.h),
			dptr->buffer,dptr->length,
			dptr->fontnumber,
			dptr->foreground,dptr->background);
		}
#endif
	switch (operation) {
		case	0	:
			return(0);

		case	_XGR_LINE	:
			return( 
				drawline( 
					scaled_coordinate(dptr->zone.x),
					scaled_coordinate(dptr->zone.y),
					scaled_dimension(dptr->zone.w),
					scaled_dimension(dptr->zone.h), 
					scaled_dimension(dptr->length),
					dptr->foreground ) );

		case	_XGR_CIRCLE	:
				drawcircle(
				 	scaled_coordinate(dptr->zone.x),
					scaled_coordinate(dptr->zone.y),
					scaled_dimension(dptr->zone.w),
					scaled_dimension(dptr->zone.h), 
					dptr->foreground, 
					dptr->length );
			return(0);

		case	_XGR_IMAGE	:
				drawimage( 	
					scaled_coordinate(dptr->zone.x),
					scaled_coordinate(dptr->zone.y),
					scaled_dimension(dptr->zone.w),
					scaled_dimension(dptr->zone.h), 
					dptr->buffer,
					dptr->length );
			return(0);

		case 	_XGR_GETHQFONT	:
			dptr->value = gethqfont();
			return(0);
		case 	_XGR_SETHQFONT	:
			sethqfont(dptr->value);
			return(0);

		case	_XGR_GETSCALE	:
			dptr->zone.x = xgr_get_scale();
			return(0);

		case	_XGR_SETSCALE	:
			xgr_set_scale(dptr->zone.x);
			return(0);

		case	_XGR_INIPIXEL	:
			if ( dptr->biosmode > 0xFFFF )
				return( activatepixel(dptr->biosmode>>16,dptr->biosmode& 0xFFFF, dptr->zone.x) );
			else	return( initialisepixel(dptr->biosmode) );
		case	_XGR_LIBPIXEL	:
			return( liberatepixel() );

		case	_XGR_PIXELTYPE	:
			return( get_pixel_format() );

		case	_XGR_PIXELSIZE	:
			return( get_pixel_size() );

		case	_XGR_SETPIXELTYPE	:
			return( set_pixel_format(dptr->zone.x) );

		case	_XGR_SETPIXELSIZE	:
			return( set_pixel_size(dptr->zone.x) );
	
		case	_XGR_DEPIXEL	:
			return( pixel_to_rgb( dptr->zone.x, dptr->rptr, dptr->gptr, dptr->bptr ) );

		case	_XGR_RGBPIXEL	:
			return( put_logical_pixel( dptr->buffer, dptr->zone.x, dptr->zone.y, dptr->zone.w ) );

		case	_XGR_GETRGB	:
			return( get_logical_pixel( dptr->buffer, dptr->rptr, dptr->gptr, dptr->bptr ) );

		case	_XGR_NEWRGB	:
			return( make_rgb_pixel( dptr->zone.x, dptr->zone.y, dptr->zone.w ) );

		case	_XGR_BUILDRGB	:
			dptr->pixel = get_rgb_pixel( dptr->zone.x, dptr->zone.y, dptr->zone.w );
			return( 0 );

		case	_XGR_PALPIXEL	:
			put_palette_pixel( dptr->buffer, dptr->zone.x );
			return 0;

		case	_XGR_GETPALPIXEL	:
			return( get_palette_pixel( dptr->zone.x ) );

		case	_XGR_HIDE	:
			return( hide() );
		case	_XGR_SHOW 	:
			show( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h) );
			return 0;
		case	_XGR_SHADZONE 	:
			shadzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->foreground );
			return 0;
		case	_XGR_FILZONE 	:
			filzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->foreground );
			return 0;
		case	_XGR_XFILZONE 	:
			xfilzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->foreground );
			return 0;
		case	_XGR_ROUNDFILZONE 	:
			rounded_filzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->foreground );
			return 0;
		case	_XGR_ROUNDFRAME 	:
			rounded_frame( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->foreground );
			return 0;
		case	_XGR_PUTZONE 	:
			putzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->buffer     );
			return 0;
		case	_XGR_PUTZONE8 	:
			putzone8( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->buffer     );
			return 0;
		case	_XGR_MIXZONE 	:
			mixzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->buffer     );
			return 0;
		case	_XGR_MIXZONE8 	:
			mixzone8( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->buffer     );
			return 0;
		case	_XGR_XORZONE 	:
			xorzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->foreground );
			return 0;
		case	_XGR_GETZONE 	:
			getzone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->buffer     );
			return 0;
		case	_XGR_MOVZONE 	:
			/* rq: fg et bg représente en réalité nbx et nby */
			movezone( scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h), dptr->foreground, dptr->background );
			return 0;

		case	_XGR_PUTC	:
			return( PixelPutC( dptr->value ) );
		case	_XGR_FONTC	:
			return( PixelFontC( dptr->fontnumber,dptr->value ) );
		case	_XGR_PUTCAT	:
			return( PixelPutCat( scaled_coordinate(dptr->zone.x), scaled_coordinate(dptr->zone.y), dptr->value ) );
		case	_XGR_FONTCAT	:
			return( PixelFontCat( scaled_coordinate(dptr->zone.x), scaled_coordinate(dptr->zone.y), dptr->fontnumber,dptr->value ) );

		case	_XGR_PUTS	:
			return( PixelPutS( dptr->buffer ) );
		case	_XGR_FONTS	:
			return( PixelFontS( dptr->fontnumber,dptr->buffer ) );
		case	_XGR_PUTSAT	:
			return( PixelPutSat( scaled_coordinate(dptr->zone.x), scaled_coordinate(dptr->zone.y), dptr->buffer ) );
		case	_XGR_FONTSAT	:
			return( PixelFontSat( scaled_coordinate(dptr->zone.x), scaled_coordinate(dptr->zone.y), dptr->fontnumber,dptr->buffer ) );

		case	_XGR_PUTL	:
			return( PixelPutL( dptr->buffer, dptr->length ) );
		case	_XGR_FONTL	:
			return( PixelFontL( dptr->fontnumber,dptr->buffer, dptr->length ) );
		case	_XGR_PUTLAT	:
			return( PixelPutLat( scaled_coordinate(dptr->zone.x), scaled_coordinate(dptr->zone.y), dptr->buffer, dptr->length ) );
		case	_XGR_FONTLAT	:
			return( PixelFontLat( scaled_coordinate(dptr->zone.x), scaled_coordinate(dptr->zone.y), dptr->fontnumber,dptr->buffer, dptr->length ) );

		case	_XGR_SETCOL 	:
			return( SetCicoPixelColumn( scaled_coordinate(dptr->zone.x) ) );

		case	_XGR_MARGIN 	:
			return( CicoFontMargin( scaled_coordinate(dptr->zone.x) ) );

		case	_XGR_TEXTSIZE	:
			
			v = textsizelen( dptr->fontnumber,dptr->buffer, dptr->length );
			return(scaled_reduction(v));

		case	_XGR_ALIGN	:
			return( textalign(
					scaled_coordinate(dptr->zone.x),
					scaled_coordinate(dptr->zone.y),
					scaled_dimension(dptr->zone.w),
					scaled_dimension(dptr->zone.h),
					dptr->fontnumber,
					dptr->buffer,dptr->length,
					dptr->value) );
			
		case	_XGR_LOADFONT	:
			return( loadguifont( dptr->fontnumber, dptr->buffer, dptr->length ) );	
		
		case	_XGR_FONTSIZE	:
			return( guifontsize( dptr->fontnumber ) );

		case	_XGR_USEFONT  	:
			return( use_base_font( dptr->fontnumber ) );
		
		case	_XGR_COLOUR  	:
			return( cicocolour( dptr->foreground, dptr->background ) );
		case	_XGR_PALET   	:
			return( cicopalette( dptr->foreground, dptr->background ) );
		case	_XGR_CURSOR  	:
			return( cicocursor( scaled_coordinate(dptr->zone.x), scaled_coordinate(dptr->zone.y) ) );

		case	_XGR_SYSFILE	:
			dptr->buffer = sysfilename( dptr->buffer );
			return(0);

		case	_XGR_VGAPAL	:
			return( vgapalette(dptr->buffer, dptr->value,dptr->length) );

		case	_XGR_ALLOCPSU	:
				dptr->buffer = allocate_graphic_storage( (WORD)scaled_coordinate(dptr->zone.x), (WORD)scaled_coordinate(dptr->zone.y), (WORD)scaled_dimension(dptr->zone.w), (WORD)scaled_dimension(dptr->zone.h));
			return(0);

		case	_XGR_CAPTURE 	:
			capture_pixel_storage( dptr->buffer );
			return(0);

		case	_XGR_REFRESH 	:
			refresh_pixel_storage( dptr->buffer );
			return(0);

		case	_XGR_LIBERPSU	:

			dptr->buffer = liberate_pixel_storage(dptr->buffer);
			return(0);

		case	_XGR_CONNECT 	:
			dptr->buffer = connect_pixel_row(dptr->buffer, (WORD)dptr->value);
			return(0);

		case	_XGR_MOVEWARE	:
			move_pixel_capture(dptr->buffer,scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y));
			return(0);

		case	_XGR_SHAREWARE	:
			foreground_pixel_capture(dptr->buffer);
			return(0);

		case	_XGR_SOFTWARE	:
			background_pixel_capture(dptr->buffer);
			return(0);

		case	_XGR_HARDWARE	:
			cancel_pixel_capture(dptr->buffer);
			return(0);

		case	_XGR_ATRIBUT	:
			cicoatribut(dptr->zone.x);
			return(0);

		case	_XGR_VIEWPORT	:
			cicowindow(scaled_coordinate(dptr->zone.x),scaled_coordinate(dptr->zone.y),scaled_dimension(dptr->zone.w),scaled_dimension(dptr->zone.h));
			return(0);

		case	_XGR_WMNAME	:
			windowtitle(dptr->buffer);
			return(0);

		case	_XGR_WMICON 	:
			windowicon(dptr->buffer);
			return(0);
		case	_XGR_PUBLISH	:
			publish_selection(dptr->buffer,dptr->length);
			return(0);

		case	_XGR_PASTE	:
			paste_selection(dptr->buffer,dptr->length);
			return(0);

		case	_XGR_MOUSEMASK	:
			set_mimo_mask( dptr->zone.x );
			return(0);

		case	_XGR_FONTLOAD	:
			return( standard_load_font( dptr->buffer ) );

		case	_XGR_FONTDROP	:
			return( standard_drop_font( dptr->length ) );

		case	_XGR_FONTSPACE	:
			return( set_letter_spacing( dptr->length ) );

		case	_XGR_LINESPACE	:
			return( set_line_spacing( dptr->length ) );

		case	_XGR_SHADOWFG	:
			return( set_shadow_colour( dptr->length ) );

		case	_XGR_SHADOWX	:
			return( set_shadow_width( dptr->length ) );

		case	_XGR_SHADOWY	:
			return( set_shadow_height( dptr->length ) );

		case	_XGR_FONTNAME	:
			dptr->buffer = guifontname( dptr->length );
			return(0);
		case	_XGR_FONTINFO	:
			dptr->buffer = guifontinfo( dptr->length );
			return(0);

		case	_XGR_COLOURMAP	:
			dptr->buffer = get_vga_palette();
			return(0);

		default		:	
			return(56);
		}
}


#endif	/* _x_graph */




