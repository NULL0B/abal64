
#ifndef __LKLIST_H_
#define __LKLIST_H_

#ifdef _LKLIST

/* -------------------	*/
/* Variables GLOBAL 	*/
/* ------------------- 	*/

PUB C_SLIST FAR * ListPatchTete;
PUB C_SLIST FAR * ListPatch[10];

#else

/* -------------------	*/
/* Variables externs 	*/
/* ------------------- 	*/

extern GLOBAL  C_SLIST FAR *ListPatchTete;
extern GLOBAL  C_SLIST FAR *LlistPatch[10];
#endif 	/* _LKLIST  	*/

#ifdef _LKLIST
#undef PRIMITIVE
#define PRIMITIVE
#endif /* _LKLIST */


#ifdef LINT_ARGS
	PRIMITIVE VOID ListAllouer( VOID );
	PRIMITIVE VOID ListLiberer( VOID );
	PRIMITIVE VOID ListCalculHashValue( BYTE XPTR * ,  WORD XPTR * ,  WORD XPTR * );
	PRIMITIVE Args XPTR * 	ListNewArgs( BYTE );
	PRIMITIVE ModPro XPTR * 	ListNewPro( BYTE XPTR * , WORD, WORD , WORD, WORD, WORD, WORD, WORD);
	PRIMITIVE VOID 		ListNewOff(C_SLIST FAR * , BYTE , WORD , WORD );
	PRIMITIVE VOID 		ListConcatOff(C_SLIST FAR * , C_SLIST FAR * );
	PRIMITIVE VOID 		ListNewBloc(C_SLIST FAR * , BYTE , BYTE , Tabfic XPTR * , WORD , WORD , WORD );
	PRIMITIVE Label XPTR * ListIsLabelPub( C_SLIST FAR * , BYTE XPTR * );
	PRIMITIVE ModPro XPTR * ListIsProPub( C_SLIST FAR *[], LstPro XPTR * );
	PRIMITIVE ModPro XPTR * ListIsCstPub( C_SLIST FAR *[], ModPro XPTR * );
	PRIMITIVE ModPro XPTR * ListIsVarPub( C_SLIST FAR *[], LstPro XPTR *, Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE ModPro XPTR * ListIsSegPub( C_SLIST FAR *[] , LstPro XPTR * );
	PRIMITIVE LstPro XPTR * ListIsProExtPub(C_SLIST FAR * , LstPro XPTR *, Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE LstPro XPTR * ListIsSegExtPub(C_SLIST FAR * , LstPro XPTR *, Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE Ancrage XPTR * ListIsAncragePub(C_SLIST FAR * , Ancrage XPTR *, Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE LstPro XPTR * ListIsVarExtPub(C_SLIST FAR * , LstPro XPTR * );
	PRIMITIVE VOID ListRelocVarPatch( Fichier XPTR * , C_SLIST FAR *, WORD , WORD );
	PRIMITIVE VOID ListRelocPatch( Fichier XPTR * , C_SLIST FAR *, WORD , BYTE );
	PRIMITIVE VOID ListMajPatch( BYTE, BYTE, Tabfic XPTR * , WORD , WORD , WORD); 

	PRIMITIVE VOID ListReorgPatch( VOID );
	PRIMITIVE VOID ListMatchPatch(BYTE , WORD , Tabfic XPTR * , WORD );
	PRIMITIVE BOOL ListMatchBib( Bibli XPTR *, Bibli XPTR * );
	PRIMITIVE BOOL ListMatchAncrage( Ancrage XPTR * , Ancrage XPTR * );
	PRIMITIVE BOOL ListMatchCst( InfoCst XPTR * , InfoCst XPTR * );
	PRIMITIVE BOOL ListMatchVar( InfoVar XPTR * , InfoVar XPTR * );
	PRIMITIVE BOOL ListMatchPro( ModPro XPTR * , LstPro XPTR * );
	PRIMITIVE BOOL ListMatchSeg( ModPro XPTR * , LstPro XPTR * );
	PRIMITIVE BOOL ListMatchProExt( LstPro XPTR *, LstPro XPTR * );
	PRIMITIVE BOOL ListMatchSegExt( LstPro XPTR *, LstPro XPTR * );
	PRIMITIVE ModPro XPTR * ListGetProCall( C_SLIST FAR * [], WORD);
	PRIMITIVE BOOL ListExtUsed(BYTE , WORD );
	PRIMITIVE VOID ListGetNomModule( C_SLIST FAR *, WORD , BYTE XPTR * );
	PRIMITIVE VOID ListVideModule( C_SLIST FAR * );
	PRIMITIVE VOID ListDelNode( C_SNODE FAR *  );
	PRIMITIVE VOID ListDelPatch( C_SLIST FAR * );
	PRIMITIVE VOID ListDelPub( C_SLIST FAR * );
	PRIMITIVE VOID ListDelExt( C_SLIST FAR * );
	PRIMITIVE WORD ListCountProExt( C_SLIST FAR * );
	PRIMITIVE WORD ListCountSegExt( C_SLIST FAR * );
	PRIMITIVE VOID ListDelAncrage( C_SLIST FAR * );
	PRIMITIVE C_SLIST FAR * ListInit( VOID );
	PRIMITIVE VOID ListDel( C_SLIST FAR * );
	PRIMITIVE VOID ListGoFirst( C_SLIST FAR * );
	PRIMITIVE VOID ListCreateHashList( C_SLIST FAR * []);
	PRIMITIVE VOID ListDelHashList( C_SLIST FAR * []);
	PRIMITIVE WORD ListCountHashList( C_SLIST FAR * []);
	PRIMITIVE WORD ListCountVarExt( C_SLIST FAR * );
	PRIMITIVE VOID ListConcat( C_SLIST FAR *, C_SLIST FAR * );
	PRIMITIVE VOID ListConcatHashList( C_SLIST FAR * [] , C_SLIST FAR * [] );
	PRIMITIVE C_SNODE FAR * SlistExtractNode( C_SLIST FAR * );
	PRIMITIVE VOID ListAddItemEnQueue( C_SLIST FAR *  , VOID FAR * );
	PRIMITIVE VOID ListAddItemEnTete( C_SLIST FAR * , VOID FAR * );
	PRIMITIVE VOID ListInsertItem( C_SLIST FAR *, VOID FAR * );
	PRIMITIVE VOID ListDelItemEnTete( C_SLIST FAR * );
	PRIMITIVE VOID ListDelItemCourant( C_SLIST FAR * );
	PRIMITIVE WORD ListAddNameUnique( C_SLIST FAR *, BYTE XPTR * );
	PRIMITIVE Name XPTR * ListNewName( BYTE XPTR * , WORD );
	PRIMITIVE WORD ListAddName( C_SLIST FAR *, BYTE XPTR *, WORD );
	PRIMITIVE VOID ListGetNameFromNum( C_SLIST FAR *, WORD, BYTE XPTR *);
	PRIMITIVE WORD ListGetNameNum( C_SLIST FAR *, BYTE XPTR * );
	PRIMITIVE Name XPTR * ListGetNameItemFromName( C_SLIST FAR *, BYTE XPTR * );
	PRIMITIVE Name XPTR * ListGetNameItemFromNum( C_SLIST FAR *, WORD );
	PRIMITIVE ModPro XPTR * ListGetNomVarFromDesc( C_SLIST FAR *[], WORD );
	PRIMITIVE Bibli XPTR * ListNewBda( BYTE XPTR *, WORD, BYTE []);
	PRIMITIVE VOID ListDupliqueProExt( C_SLIST FAR * , LstPro XPTR * );
	PRIMITIVE VOID ListDupliqueSegExt( C_SLIST FAR * , LstPro XPTR * );
	PRIMITIVE VOID ListDupliqueAncrage( Table XPTR *, Table XPTR *, C_SLIST FAR * , Ancrage XPTR *, Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID ListDupliqueVarExt( Table XPTR *, Table XPTR *, C_SLIST FAR * , LstPro XPTR *, Fichier XPTR *, Fichier XPTR *  );
	PRIMITIVE VOID ListTestPatch(BYTE , WORD , Tabfic XPTR * , WORD );
	PRIMITIVE VOID ListPatcher( Fichier XPTR * );
	PRIMITIVE WORD ListHLPatchNbOff( C_SLIST FAR * [] );
	PRIMITIVE WORD ListPatchNbOff( C_SLIST FAR * );
	PRIMITIVE VOID ListDupliquePro( C_SLIST FAR * [], ModPro * );
	PRIMITIVE VOID ListDupliqueSeg( C_SLIST FAR * [], ModPro * );
	PRIMITIVE VOID ListDupliqueVar( C_SLIST FAR * liste[], ModPro XPTR *  pp);

#else 	/* LINT_ARGS */
	PRIMITIVE VOID ListAllouer();
	PRIMITIVE VOID ListLiberer();
	PRIMITIVE VOID ListCalculHashValue();
	PRIMITIVE Args XPTR * ListNewArgs();
	PRIMITIVE ModPro XPTR * ListNewPro();
	PRIMITIVE Label XPTR * ListIsLabelPub();
	PRIMITIVE ModPro XPTR * ListIsCstPub();
	PRIMITIVE ModPro XPTR * ListIsVarPub();
	PRIMITIVE ModPro XPTR * ListIsProPub();
	PRIMITIVE ModPro XPTR * ListIsSegPub();
	PRIMITIVE LstPro XPTR * ListIsProExtPub();
	PRIMITIVE LstPro XPTR * ListIsSegExtPub();
	PRIMITIVE LstPro XPTR * ListIsVarExtPub();
	PRIMITIVE Ancrage XPTR * ListIsAncragePub();
	PRIMITIVE VOID ListNewOff();
	PRIMITIVE VOID ListConcatOff();
	PRIMITIVE VOID ListNewBloc();
	PRIMITIVE VOID ListRelocPatch();
	PRIMITIVE VOID ListMajPatch(); 
	PRIMITIVE VOID ListMatchPatch();
	PRIMITIVE VOID ListReorgPatch();
	PRIMITIVE BOOL ListMatchBib();
	PRIMITIVE BOOL ListMatchPro();
	PRIMITIVE BOOL ListMatchVar();
	PRIMITIVE BOOL ListMatchCst();
	PRIMITIVE BOOL ListMatchSeg();
	PRIMITIVE BOOL ListMatchProExt();
	PRIMITIVE BOOL ListMatchSegExt();
	PRIMITIVE ModPro XPTR * ListGetProCall();
	PRIMITIVE BOOL ListExtUsed();
	PRIMITIVE VOID ListGetNomModule();
	PRIMITIVE VOID ListVideModule();
	PRIMITIVE VOID ListDelNode();
	PRIMITIVE VOID ListDelPatch();
	PRIMITIVE VOID ListDelPub();
	PRIMITIVE VOID ListDelExt();
	PRIMITIVE C_SLIST FAR * ListInit();
	PRIMITIVE VOID ListDel();
	PRIMITIVE VOID ListConcat();
	PRIMITIVE VOID ListGoFirst();
	PRIMITIVE VOID ListCreateHashList();
	PRIMITIVE VOID ListDelHashList();
	PRIMITIVE WORD ListCountHashList();
	PRIMITIVE WORD ListCountVarExt();
	PRIMITIVE VOID ListConcatHashList();
	PRIMITIVE C_SNODE FAR * SlistExtractNode();
	PRIMITIVE VOID ListAddItemEnQueue();
	PRIMITIVE VOID ListAddItemEnTete();
	PRIMITIVE VOID ListInsertItem();
	PRIMITIVE VOID ListDelItemEnTete();
	PRIMITIVE VOID ListDelItemCourant();
	PRIMITIVE WORD ListAddNameUnique();
	PRIMITIVE Name XPTR * ListNewName();
	PRIMITIVE WORD ListAddName();
	PRIMITIVE VOID ListGetNameFromNum();
	PRIMITIVE WORD ListGetNameNum();
	PRIMITIVE Name XPTR * ListGetNameItemFromName();
	PRIMITIVE Name XPTR * ListGetNameItemFromNum();
	PRIMITIVE ModPro XPTR * ListGetNomVarFromDesc();
	PRIMITIVE Bibli XPTR * ListNewBda();
	PRIMITIVE VOID ListDupliqueProExt();
	PRIMITIVE VOID ListDupliqueSegExt();
	PRIMITIVE VOID ListTestPatch();
	PRIMITIVE VOID ListPatcher();
	PRIMITIVE WORD ListHLPatchNbOff();
	PRIMITIVE WORD ListPatchNbOff();
	PRIMITIVE VOID ListDupliquePro();
	PRIMITIVE VOID ListDupliqueSeg();
	PRIMITIVE VOID ListDupliqueAncrage();
	PRIMITIVE VOID ListDupliqueVarExt();
	PRIMITIVE VOID ListDelAncrage();
	PRIMITIVE VOID ListDupliqueVar();
#endif	/* LINT_ARGS */


#endif	/* __LKLIST_H_ 	*/

