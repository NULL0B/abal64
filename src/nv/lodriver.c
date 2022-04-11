#ifndef	_lodriver_c
#define	_lodriver_c


/* DLL Pattern Management */
/* ---------------------- */

static	char 	LaPaterne[16] = { 
	'*','P','R','L','@','I','N','F','O','*',
	'#',3,
	__DRIVER_MAJOR,__DRIVER_MINOR,__DRIVER_INDEX,
	0 };

static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[8];
char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

/* ------------------ */
/* DLL initialisation */
/* ------------------ */
VOID FAR PTR InitRelais()
{ 
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;

	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;

	desrt.nombre = 7;

#ifdef vms

	desrt.nom[_DRIVER_DLL_INITIALISE] 	= (BYTE FAR PTR) "_DriverInitialise";
	desrt.nom[_DRIVER_DLL_COLOUR]  		= (BYTE FAR PTR) "_DriverColours";
	desrt.nom[_DRIVER_DLL_CONNECT] 		= (BYTE FAR PTR) "_DriverConnect";
	desrt.nom[_DRIVER_DLL_START]   		= (BYTE FAR PTR) "_DriverStartRaster";
	desrt.nom[_DRIVER_DLL_PRINT]     	= (BYTE FAR PTR) "_DriverPrintRow";
	desrt.nom[_DRIVER_DLL_END]  		= (BYTE FAR PTR) "_DriverEndRaster";
	desrt.nom[_DRIVER_DLL_LIBERATE]   	= (BYTE FAR PTR) "_DriverLiberate";
	/* ----- */
#else 	/* ! vms */
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;

	desrt.fonction[_DRIVER_DLL_INITIALISE]  = (WORD (FAR PTR)()) DriverInitialise;
	desrt.fonction[_DRIVER_DLL_COLOUR]  	= (WORD (FAR PTR)()) DriverColours;
	desrt.fonction[_DRIVER_DLL_CONNECT]  	= (WORD (FAR PTR)()) DriverConnect;
	desrt.fonction[_DRIVER_DLL_START]  	= (WORD (FAR PTR)()) DriverStartRaster;
	desrt.fonction[_DRIVER_DLL_PRINT]  	= (WORD (FAR PTR)()) DriverPrintRow;
	desrt.fonction[_DRIVER_DLL_END]  	= (WORD (FAR PTR)()) DriverEndRaster;
	desrt.fonction[_DRIVER_DLL_LIBERATE]  	= (WORD (FAR PTR)()) DriverLiberate;
#endif /* vms */

	return((VOID FAR PTR) &desrt);

}

/* ---------------------- */
/* Library identification */
/* ---------------------- */
static VOID FAR banniere()
{ 
	printf("\n   Graphics Printer Driver : %s ",__DRIVER_NAME);
	printf("\n   Version %s ",getpatternversion());
	printf("\n   Provisoire du %s ",__DRIVER_DATE);
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	printf("\n\t %u  %% DriverInitialise(palette$?,dpi%%,width%%,height%%,options%%)",_DRIVER_DLL_INITIALISE);
	printf("\n\t %u  %% DriverColours()",_DRIVER_DLL_COLOUR);
	printf("\n\t %u  %% DriverConnect(bufferA$,bufferB$,result$)",_DRIVER_DLL_CONNECT);
	printf("\n\t %u  %% DriverStartRaster(result$?)",_DRIVER_DLL_START);
	printf("\n\t %u  %% DriverPrintRow(result$?,source$?)",_DRIVER_DLL_PRINT);
	printf("\n\t %u  %% DriverEndRaster(result$?)",_DRIVER_DLL_END);
	printf("\n\t %u  %% DriverLiberate(result$?)\n",_DRIVER_DLL_LIBERATE);
	return;
}

#endif	/* _lodriver_c */



