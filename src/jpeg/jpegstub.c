#ifndef	_JPEGSTUB_C
#define	_JPEGSTUB_C

int	JpegColours=1;

#include "jpegstub.h"


static unsigned short int JpegConnect( unsigned short int function_code, unsigned short int parameters )
{
	if ( JpegLibId != -1 )
		return( CallRunTime( 	
				JpegLibId,
				function_code,
				parameters,
				JpegBstack,
				JpegPstack,
				JpegWstack ) );
	else	return( JpegLibId );
}

static unsigned short int JpegInitialise( char * paletteptr )
{
	unsigned short	int	option=JpegColours;
	if (!( JpegDllLoaded )) {
		if (!( JpegLibraryName )) {
			JpegLibraryName = (unsigned char *) "jpeg";
			JpegLibraryFlag = 0;
			}
		(void) InitRunTime((JpegLibId=1),JpegLibraryName,0,&JpegContext,sizeof( BDA_INIT ));
		JpegDllLoaded=1;
		JpegPstack[0]  = (unsigned char *) &option;
		JpegWstack[0]  = 2;
		JpegBstack[0]  = 0x01;
		JpegPstack[1]  = (unsigned char *) paletteptr;
		JpegWstack[1]  = 1024;
		JpegBstack[1]  = 0x03;
		return( JpegConnect( _JPEG_DLL_INITIALISE, 2 ) );
		}
	else	return(-1);
}

static unsigned short int JpegLiberate()
{
	if ( JpegDllLoaded ) {
		(void) JpegConnect( _JPEG_DLL_LIBERATE, 0 );
		(void) FinRunTime(JpegLibId);
		JpegLibId=-1;
		JpegDllLoaded=0;
		return(0);
		}
	else	return(-1);
}

static unsigned short int JpegOpen(char * filename,unsigned short int namelen, unsigned short int options)
{
	unsigned short	int pnamelen=(((namelen & 0xFF) << 8) | ((namelen & 0xFF00) >> 8));
	unsigned short  int poptions=(((options & 0xFF) << 8) | ((options & 0xFF00) >> 8));
	if (!( JpegDllLoaded ))
		if ( JpegInitialise( html_vga::connect_palette() ) == -1 )
			return(-1);
	JpegPstack[0]  = (unsigned char *) filename;
	JpegWstack[0]  = namelen;
	JpegBstack[0]  = 0x03;
	JpegPstack[1]  = (unsigned char *) &pnamelen;
	JpegWstack[1]  = 2;
	JpegBstack[1]  = 0x01;
	JpegPstack[2]  = (unsigned char *) &poptions;
	JpegWstack[2]  = 2;
	JpegBstack[2]  = 0x01;
	return( JpegConnect( _JPEG_DLL_OPENFILE, 3 ) );
}

static unsigned short int JpegClose(unsigned short int handle)
{
	unsigned short	int phandle=(((handle & 0xFF) << 8) | ((handle & 0xFF00) >> 8));
	if (!( JpegDllLoaded ))
		if ( JpegInitialise( html_vga::connect_palette() ) == -1 )
			return(-1);
	JpegPstack[0]  = (unsigned char *) &phandle;
	JpegWstack[0]  = 2;
	JpegBstack[0]  = 0x01;
	return( JpegConnect( _JPEG_DLL_CLOSEFILE, 1 ) );
}

static unsigned short int JpegGetRow(unsigned short int handle,char * pixels,unsigned short int length)
{
	unsigned short	int phandle=(((handle & 0xFF) << 8) | ((handle & 0xFF00) >> 8));
	unsigned short	int plength=(((length & 0xFF) << 8) | ((length & 0xFF00) >> 8));
	if (!( JpegDllLoaded ))
		if ( JpegInitialise( html_vga::connect_palette() ) == -1 )
			return(-1);
	JpegPstack[0]  = (unsigned char *) &phandle;
	JpegWstack[0]  = 2;
	JpegBstack[0]  = 0x01;
	JpegPstack[1]  = (unsigned char *) pixels;
	JpegWstack[1]  = length;
	JpegBstack[1]  = 0x83;
	JpegPstack[2]  = (unsigned char *) &plength;
	JpegWstack[2]  = 2;
	JpegBstack[2]  = 0x01;
	return( JpegConnect( _JPEG_DLL_GETROW, 3 ) );
	return(0);
}

static unsigned short int JpegGetWidth(unsigned short int handle)
{
	unsigned short	int phandle=(((handle & 0xFF) << 8) | ((handle & 0xFF00) >> 8));
	if (!( JpegDllLoaded ))
		if ( JpegInitialise( html_vga::connect_palette() ) == -1 )
			return(-1);
	JpegPstack[0]  = (unsigned char *) &phandle;
	JpegWstack[0]  = 2;
	JpegBstack[0]  = 0x01;
	return( JpegConnect( _JPEG_DLL_GETWIDTH, 1 ) );
	return(0);
}

static unsigned short int JpegGetHeight(unsigned short int handle)
{
	unsigned short	int phandle=(((handle & 0xFF) << 8) | ((handle & 0xFF00) >> 8));
	if (!( JpegDllLoaded ))
		if ( JpegInitialise( html_vga::connect_palette() ) == -1 )
			return(-1);
	JpegPstack[0]  = (unsigned char *) &handle;
	JpegWstack[0]  = 2;
	JpegBstack[0]  = 0x01;
	return( JpegConnect( _JPEG_DLL_GETHEIGHT, 1 ) );
}


#endif	/* _JPEGSTUB_C */
	/* ----------- */





