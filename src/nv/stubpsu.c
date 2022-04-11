#ifndef	_stub_psu_c
#define	_stub_psu_c

#include "stdpsu.h"

PUBLIC	STDPSUPTR	allocate_graphic_storage( WORD a, WORD b, WORD c, WORD d )
{
	return((STDPSUPTR) 0);
}

PUBLIC	STDPSUPTR	allocate_textual_storage( WORD a, WORD b, WORD c, WORD d )
{
	return((STDPSUPTR) 0);
}

PUBLIC	STDPSUPTR	allocate_shadow_storage( STDPSUPTR a )
{
	return((STDPSUPTR) 0);
}

PUBLIC	STDPSUPTR	liberate_pixel_storage( STDPSUPTR  a)
{
	return((STDPSUPTR) 0);
}

PUBLIC	VOID		background_pixel_capture( STDPSUPTR a )	{ return; }
PUBLIC	VOID		foreground_pixel_capture( STDPSUPTR a )	{ return; }
PUBLIC	VOID		cancel_pixel_capture( STDPSUPTR	 a )	{ return; }
PUBLIC	VOID		reset_pixel_row( STDPSUPTR a, WORD b, WORD c, WORD d, WORD e )	{ return; }
PUBLIC	WORD		collect_pixel_row( STDPSUPTR a, WORD b, WORD c, WORD d, BPTR e)	{ return(0); }

#endif // _stub_psu_c

