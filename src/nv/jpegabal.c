#ifndef	_JPEGABAL_C
#define	_JPEGABAL_C

#include "jpegdef.h"
#include "jpegabal.h"

#include "jinclude.h"
#include "jpeglib.h"
#include "xp_core.h"

#include "jpegfunc.h"
#include "vga.c"
#include "jpegid.c"
#include "jpegfunc.c"

int	_fltused=0;

void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
long	_aFftol()	{	return(0L);	}

/* ------------------ */
/* DLL initialisation */
/* ------------------ */
VOID FAR PTR InitRelais()
{ 
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;

	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;

	desrt.nombre = 9;

#ifdef vms

	desrt.nom[_JPEG_DLL_INITIALISE] = (BYTE FAR PTR) "_JpegInitialise";
	desrt.nom[_JPEG_DLL_LIBERATE]   = (BYTE FAR PTR) "_JpegLiberate";
	desrt.nom[_JPEG_DLL_OPENFILE]   = (BYTE FAR PTR) "_JpegOpen";
	desrt.nom[_JPEG_DLL_CLOSEFILE]  = (BYTE FAR PTR) "_JpegClose";
	desrt.nom[_JPEG_DLL_GETROW]     = (BYTE FAR PTR) "_JpegGetRow";
	desrt.nom[_JPEG_DLL_GETWIDTH]   = (BYTE FAR PTR) "_JpegGetWidth";
	desrt.nom[_JPEG_DLL_GETHEIGHT]  = (BYTE FAR PTR) "_JpegGetHeight";
	desrt.nom[_JPEG_DLL_SETMEMORY]  = (BYTE FAR PTR) "_JpegSetMemory";
	desrt.nom[_JPEG_DLL_GETERROR]   = (BYTE FAR PTR) "_JpegGetError";
	/* ----- */
#else 	/* ! vms */
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;

	desrt.fonction[_JPEG_DLL_INITIALISE]  = (WORD (FAR PTR)()) JpegInitialise;
	desrt.fonction[_JPEG_DLL_LIBERATE]  = (WORD (FAR PTR)()) JpegLiberate;
	desrt.fonction[_JPEG_DLL_OPENFILE]  = (WORD (FAR PTR)()) JpegOpen;
	desrt.fonction[_JPEG_DLL_CLOSEFILE]  = (WORD (FAR PTR)()) JpegClose;
	desrt.fonction[_JPEG_DLL_GETROW]  = (WORD (FAR PTR)()) JpegGetRow;
	desrt.fonction[_JPEG_DLL_GETWIDTH]  = (WORD (FAR PTR)()) JpegGetWidth;
	desrt.fonction[_JPEG_DLL_GETHEIGHT]  = (WORD (FAR PTR)()) JpegGetHeight;
	desrt.fonction[_JPEG_DLL_SETMEMORY]  = (WORD (FAR PTR)()) JpegSetMemory;
	desrt.fonction[_JPEG_DLL_GETERROR]  = (WORD (FAR PTR)()) JpegGetError;
#endif /* vms */

	return((VOID FAR PTR) &desrt);

}

/* ---------------------- */
/* Library identification */
/* ---------------------- */
static VOID FAR banniere()
{ 
	printf("\n   JPEG Image Loader : ABALJPEG ");
	printf("\n   Version %s ",getpatternversion());
	if ( VersionStatus[15] == '2' )
		printf("\n   Provisoire du    %s",__JPEGABAL_DATE);
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	printf("\n\t %u  %% JpegInitialise(options%%)",_JPEG_DLL_INITIALISE);
	printf("\n\t %u  %% JpegLiberate()",_JPEG_DLL_LIBERATE);
	printf("\n\t %u  %% JpegOpen(filename$,namelen%%,option%%,palette$=1024)",_JPEG_DLL_OPENFILE);
	printf("\n\t %u  %% JpegClose(handle%%)",_JPEG_DLL_CLOSEFILE);
	printf("\n\t %u  %% JpegGetRow(handle%%,buffer$?,buflen%%)",_JPEG_DLL_GETROW);
	printf("\n\t %u  %% JpegGetWidth(handle%%)",_JPEG_DLL_GETWIDTH);
	printf("\n\t %u  %% JpegGetHeight(handle%%)",_JPEG_DLL_GETHEIGHT);
	printf("\n\t %u  %% JpegGetError(handle%%,buffer$?,buflen%%)",_JPEG_DLL_GETERROR);
	printf("\n\t %u    JpegSetMemory(kbytes%%)\n",_JPEG_DLL_SETMEMORY);
	return;
}

	/* ----------- */
#endif	/* _JPEGABAL_C */
	/* ----------- */



