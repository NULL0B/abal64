#ifndef	_JPEGSTUB_H
#define	_JPEGSTUB_H

#ifdef	_JPEGSTUB_C

extern	"C"	{

#include "bda.h"

	};
			

#define	_JPEG_DLL_INITIALISE	0
#define	_JPEG_DLL_LIBERATE	1
#define	_JPEG_DLL_OPENFILE	2
#define	_JPEG_DLL_CLOSEFILE 	3
#define	_JPEG_DLL_GETROW    	4
#define	_JPEG_DLL_GETWIDTH  	5
#define	_JPEG_DLL_GETHEIGHT 	6


static	unsigned short int	JpegDllLoaded=0;
static	unsigned short int	JpegLibId=-1;
static	void __far *	JpegPstack[4];
static 	unsigned short int 	JpegWstack[4];
static	unsigned char 		JpegBstack[4];

static	BDA_INIT	JpegContext;

static	unsigned char *	JpegLibraryName=(unsigned char *)"jpeg";
static	unsigned int    JpegLibraryFlag=0;

#endif	/* _JPEGSTUB_C */
#endif	/* _JPEGSTUB_H */
	/* ----------- */






