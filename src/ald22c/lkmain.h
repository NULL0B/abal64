#ifndef __LKMAIN_H__
#define __LKMAIN_H__ 	

/* Trace */
//#define DBGTRC
//#define DBGTRC2

#ifdef _LKMAIN

	/* -------------------	*/
	/* Variables GLOBALES 	*/
	/* ------------------- 	*/

//JPH	WORD cloture;
	FILE XPTR * GlobalArgFile;
	BYTE			GlobalArgLine[256];
	BYTE XPTR * GlobalArgPtr;

	/*
		Note: 
			-M on command line invert the "default" extension scheme.
		
		ALD
			default	 	dbo,dbg
			-M				wdo,wdg
		WALD
			default		wdo,wdg
			-M	 			dbo,dbg
	
	*/
	#ifdef __WALD__
	BYTE XPTR * GlobalExtensionDBO = EXTENSION_DBO_WALD;
	BYTE XPTR * GlobalExtensionDBG = EXTENSION_DBG_WALD;
	#else
	BYTE XPTR * GlobalExtensionDBO = EXTENSION_DBO_ALD;
	BYTE XPTR * GlobalExtensionDBG = EXTENSION_DBG_ALD;
	#endif

	#ifdef prologue
		/*	Variables pour le tas + pile pour prologue */
		/*	------------------------------------------ */
		int 	_mem_res = 1;
		int 	_stkmin = 8192;
		int 	_stklen = 100000;
	#endif

	/* -------------------	*/
	/* Prototype  GLOBAL 	*/
	/* ------------------- 	*/

#else

	/* -------------------	*/
	/* Variables externes 	*/
	/* ------------------- 	*/

//JPH	extern GLOBAL WORD cloture;
	extern FILE XPTR *	GlobalArgFile;
	extern BYTE				GlobalArgLine[];
	extern BYTE XPTR *	GlobalArgPtr;
	extern BYTE XPTR *	GlobalExtensionDBO;
	extern BYTE XPTR *	GlobalExtensionDBG;

	/* -------------------	*/
	/* Prototype  EXTERN 	*/
	/* ------------------- 	*/


#endif 	/* _LKMAIN  	*/



#ifdef LINT_ARGS
	extern GLOBAL VOID abandon( VOID );
	extern int AldMain(int argc , char *argv[]);
#else 	/* LINT_ARGS */
	extern GLOBAL VOID abandon();
	extern int AldMain();
#endif	/* LINT_ARGS */


#endif	/* _LKMAIN_HE 	*/





