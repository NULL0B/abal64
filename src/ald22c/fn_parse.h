#ifndef __FN_PARSE_H__
#define __FN_PARSE_H__

/*
	Desc : fnParse.h			FileName Parser
	Proj : Common Tool
	Copyright (c) 1998 Amenesik / Sologic  

	xxx

	Modifications list :
	29 June 1998		JPH	File creation
*/



/* Masque de debug : fonction dbgoption */

#define FILE_NETWORK_NODE			1
#define FILE_DEVICE					2
#define FILE_PATH						4
#define FILE_NAME						8
#define FILE_EXTENSION				16
#define FILE_PROLOGUE_PW			32
#define FILE_VMS_VERSION			64
#define FILE_LOWER_CASE_RESULT	128

#ifdef LINT_ARGS
PRIMITIVE int fn_parser (IN char * FilePath , OUT char * Buffer, IN int ParseMask);
#else
PRIMITIVE int fn_parser();
#endif /* LINT_ARGS */


/* -------------------- Fichier : atrdebug.hs -----------------------*/

#endif
