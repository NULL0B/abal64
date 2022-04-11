/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 2002
 *	Module  : T-CODE
 *	Fichier : LKTABLE.H
 *	Version : 2.2b
 *	Date    : 09/10/95
 *	Systeme : Tous
 *
 *	Linker                               
 *
 *	[Noyau ALD - Linker]
 *
 */

 /* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 * 14/09/00 : (#AT) Changes for extension of tables of global and local variables.
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef __LKTABLE__H__
#define __LKTABLE__H__

#ifdef _LKTABLE
#undef PRIMITIVE
#define PRIMITIVE
#endif /* _LKTABLE */

/* #AT: 14/09/00 (begin)*/
//#define  MAX_VAR_DESC_OFFSET  32766
//65515 = 65535 - 6(header of the descriptors table) - 14(reserve)
#define  MAX_VAR_DESC_OFFSET  65515L
void CheckReloc(Table * pTab,unsigned long lngMax,int iErrNumb);

#ifndef VERSION_XX
void ChangeGlobVarAdr(WORD * wAdr);
#endif
/* #AT: 14/09/00 (end)*/

#ifdef LINT_ARGS

PRIMITIVE VOID TableInit( Table XPTR * );
PRIMITIVE BOOL TableIsVide( Table XPTR * );
PRIMITIVE VOID TableClose( Table XPTR * );
PRIMITIVE VOID TableSeek( Table XPTR * , WORD );
PRIMITIVE WORD TableGetReloc( Table XPTR * );
PRIMITIVE WORD TableGetVarReloc( Table XPTR * );
PRIMITIVE VOID TableGetFromFile( Tabfic XPTR *, Table XPTR *, WORD, WORD );
PRIMITIVE VOID TablePutToFile( Tabfic XPTR *, Table XPTR * );
PRIMITIVE VOID TableGetString( Table XPTR * , BYTE XPTR * );
PRIMITIVE VOID TableGetStringLg( Table XPTR * , BYTE XPTR * , WORD , BOOL );
PRIMITIVE BYTE TableGetByte( Table XPTR * );
PRIMITIVE WORD TableGetBin( Table  XPTR * );
PRIMITIVE VOID TablePutByte( Table XPTR * , BYTE );
PRIMITIVE VOID TablePutBin( Table XPTR * , WORD );
PRIMITIVE VOID TablePutStringLg( Table XPTR * , BYTE XPTR * , WORD );
PRIMITIVE VOID TablePutString( Table XPTR * , BYTE XPTR * );

PRIMITIVE VOID TableGetCst( Table XPTR *, WORD , InfoCst XPTR *);
PRIMITIVE VOID TableGetVar( Table XPTR *, WORD, InfoVar XPTR * );
PRIMITIVE WORD TableGetVarNb( Table XPTR * );
PRIMITIVE WORD TableGetVarNom( Table XPTR * );
PRIMITIVE WORD TableGetVarTaille( Table XPTR * );
PRIMITIVE VOID TableGetPro( Table XPTR *, WORD , InfoPro XPTR * );
PRIMITIVE VOID TableGetSeg( Table XPTR *, WORD , InfoSeg XPTR * );
PRIMITIVE VOID TablePutCst( Table XPTR *, InfoCst XPTR * );
PRIMITIVE VOID TablePutVar( Table XPTR *, InfoVar XPTR * );
PRIMITIVE VOID TablePutVarNb( Table XPTR *, WORD );
PRIMITIVE VOID TablePutVarNom( Table XPTR *, WORD );
PRIMITIVE VOID TablePutVarTaille( Table XPTR *, WORD );
PRIMITIVE VOID TablePutPro( Table XPTR *, InfoPro XPTR * );
PRIMITIVE VOID TablePutSeg( Table XPTR *, InfoSeg XPTR * );
PRIMITIVE VOID TableGetCstAlias( Table XPTR *, InfoCst XPTR * );

#else 	/* LINT_ARGS */

PRIMITIVE VOID TableInit();
PRIMITIVE BOOL TableIsVide();
PRIMITIVE VOID TableClose();
PRIMITIVE VOID TableSeek();
PRIMITIVE WORD TableGetReloc();
PRIMITIVE WORD TableGetVarReloc();
PRIMITIVE VOID TableGetFromFile();
PRIMITIVE VOID TablePutToFile();
PRIMITIVE VOID TableGetString();
PRIMITIVE VOID TableGetStringLg();
PRIMITIVE BYTE TableGetByte();
PRIMITIVE WORD TableGetBin();
PRIMITIVE VOID TablePutByte();
PRIMITIVE VOID TablePutBin();
PRIMITIVE VOID TablePutStringLg();
PRIMITIVE VOID TablePutString();

PRIMITIVE VOID TableGetCst();
PRIMITIVE VOID TableGetVar();
PRIMITIVE WORD TableGetVarNb();
PRIMITIVE WORD TableGetVarNom();
PRIMITIVE WORD TableGetVarTaille();
PRIMITIVE VOID TableGetPro();
PRIMITIVE VOID TableGetSeg();
PRIMITIVE VOID TablePutCst();
PRIMITIVE VOID TablePutVar();
PRIMITIVE VOID TablePutVarNb();
PRIMITIVE VOID TablePutVarNom();
PRIMITIVE VOID TablePutVarTaille();
PRIMITIVE VOID TablePutPro();
PRIMITIVE VOID TablePutSeg();
PRIMITIVE VOID TableGetCstAlias();

#endif	/* LINT_ARGS */

#endif /* __LKTABLE__H__ */


