#ifndef __LKFICH_H__
#define __LKFICH_H__


#ifdef _LKFICH
#undef PRIMITIVE
#define PRIMITIVE
#endif /* _LKFICH */

#ifdef LINT_ARGS
	PRIMITIVE VOID FichierInit( Fichier XPTR *, BYTE XPTR * , BYTE XPTR *, BYTE );
	PRIMITIVE VOID FichierGetInfo( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierLiberer( Fichier XPTR * );
	PRIMITIVE VOID FichierOuvrir( Fichier XPTR * );
	PRIMITIVE VOID FichierFermer( Fichier XPTR * );
	PRIMITIVE VOID FichierDetruire( Fichier XPTR * );
	PRIMITIVE VOID FichierCrypt(WORD , BYTE XPTR * , WORD, WORD);
	PRIMITIVE VOID FichierInitEntete( Tabfic XPTR * );
	PRIMITIVE VOID FichierGetEntete( Tabfic XPTR * );			/* chkprg */
	PRIMITIVE VOID FichierPutEntete( Fichier XPTR * );
	PRIMITIVE VOID FichierCreateResult(Fichier XPTR * , Fichier XPTR *);
	PRIMITIVE VOID FichierResultConstruct(Fichier XPTR * , Fichier XPTR *);
	PRIMITIVE VOID FichierInitCst( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitVar( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitPro( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitSeg( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitNomCst( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitNomVar( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitNomPro( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitNomSeg( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitNomSource( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitNomBda( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitVarExt( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitLabel( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitProExt( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierInitSegExt(Fichier XPTR *, Fichier XPTR *);
	PRIMITIVE VOID FichierInitModExt( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE ULONG FichierGetAdrEtendue( Tabfic XPTR * );
	PRIMITIVE VOID FichierSetRelocEtendue( Tabfic XPTR *, ULONG );
	PRIMITIVE VOID FichierGetRelocEtendue( Tabfic XPTR *, WORD XPTR *, WORD XPTR * );
	PRIMITIVE VOID FichierRelocBda(Fichier XPTR *, Fichier XPTR *);
	PRIMITIVE VOID FichierRelocCst( Fichier XPTR *, Fichier XPTR *, BOOL );
	PRIMITIVE VOID FichierRelocVarMFIN( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierRelocVarEFIN( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierRelocVarMRECOUVRE( Fichier XPTR *, Fichier XPTR *, Ancrage XPTR * );
	PRIMITIVE VOID FichierRelocVarERECOUVRE( Fichier XPTR *, Fichier XPTR *, Ancrage XPTR * );
	PRIMITIVE VOID FichierRelocVarMINSERT( Fichier XPTR *, Fichier XPTR *, Ancrage XPTR *, Label XPTR * );
	PRIMITIVE VOID FichierRelocVarEINSERT( Fichier XPTR *, Fichier XPTR *, Ancrage XPTR *, Label XPTR * );
	PRIMITIVE VOID FichierRelocVarVIRT( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierRelocProExt( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierRelocSegExt( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierRelocPro( Fichier XPTR *, Fichier XPTR *, ModPro XPTR *);
	PRIMITIVE VOID FichierRelocSeg( Fichier XPTR *, Fichier XPTR *, ModPro XPTR *, WORD );
	PRIMITIVE WORD FichierRelocMap( Fichier XPTR *, Fichier XPTR *, WORD );
	PRIMITIVE VOID FichierCopyPro( Fichier XPTR *, Fichier XPTR *, InfoPro XPTR * );
	PRIMITIVE VOID FichierCopySeg( Fichier XPTR *, Fichier XPTR *, InfoSeg XPTR * );
	PRIMITIVE VOID FichierCopyVar( Fichier XPTR *, Fichier XPTR *, WORD, WORD );
	PRIMITIVE VOID FichierCopyCst( Fichier XPTR *, Fichier XPTR *, WORD, WORD );
	PRIMITIVE VOID FichierCopyCode(Fichier XPTR *, Fichier XPTR *, WORD, WORD );		/* getcode */
	PRIMITIVE VOID FichierEndModule( Fichier XPTR *, Fichier XPTR *, BOOL );
	PRIMITIVE VOID FichierCstConstruct( Fichier XPTR * );
	PRIMITIVE VOID FichierVarConstruct( Fichier XPTR * );
	PRIMITIVE VOID FichierProConstruct( Fichier XPTR * , Fichier XPTR * );
	PRIMITIVE VOID FichierSegConstruct( Fichier XPTR * , Fichier XPTR * );
	PRIMITIVE VOID FichierNomProConstruct( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierNomSegConstruct( Fichier XPTR *, Fichier XPTR * );
	PRIMITIVE VOID FichierSourceConstruct( Fichier XPTR * );
	PRIMITIVE VOID FichierBdaConstruct( Fichier XPTR * );
	PRIMITIVE VOID FichierRelocProApp( Fichier XPTR * module, Fichier XPTR * resultat, ModPro XPTR * pp_proc);
	PRIMITIVE VOID FichierRelocSegApp( Fichier XPTR * module, Fichier XPTR * resultat, ModPro XPTR * pp_seg);
	PRIMITIVE VOID FichierRelocModExt( Fichier XPTR * mod, Fichier XPTR * res );
	PRIMITIVE VOID FichierRelocVarExt( Fichier XPTR * mod, Fichier XPTR * res);
	PRIMITIVE WORD IsFileOpened(char * FileName); 
#else 	/* LINT_ARGS */

	PRIMITIVE VOID FichierInit();
	PRIMITIVE VOID FichierGetInfo();
	PRIMITIVE VOID FichierLiberer();
	PRIMITIVE VOID FichierOuvrir();
	PRIMITIVE VOID FichierFermer();
	PRIMITIVE VOID FichierDetruire();
	PRIMITIVE VOID FichierCrypt();
	PRIMITIVE VOID FichierInitEntete();
	PRIMITIVE VOID FichierGetEntete();
	PRIMITIVE VOID FichierPutEntete();
	PRIMITIVE VOID FichierCreateResult();
	PRIMITIVE VOID FichierResultConstruct();
	PRIMITIVE VOID FichierInitCst();
	PRIMITIVE VOID FichierInitVar();
	PRIMITIVE VOID FichierInitPro();
	PRIMITIVE VOID FichierInitSeg();
	PRIMITIVE VOID FichierInitNomCst();
	PRIMITIVE VOID FichierInitNomVar();
	PRIMITIVE VOID FichierInitNomPro();
	PRIMITIVE VOID FichierInitNomSeg();
	PRIMITIVE VOID FichierInitNomSource();
	PRIMITIVE VOID FichierInitNomBda();
	PRIMITIVE VOID FichierInitVarExt();
	PRIMITIVE VOID FichierInitLabel();
	PRIMITIVE VOID FichierInitProExt();
	PRIMITIVE VOID FichierInitSegExt();
	PRIMITIVE VOID FichierInitModExt();
	PRIMITIVE ULONG FichierGetAdrEtendue();
	PRIMITIVE VOID FichierSetRelocEtendue();
	PRIMITIVE VOID FichierGetRelocEtendue();
	PRIMITIVE VOID FichierRelocBda();
	PRIMITIVE VOID FichierRelocCst();
	PRIMITIVE VOID FichierRelocVar();
	PRIMITIVE VOID FichierRelocProExt();
	PRIMITIVE VOID FichierRelocSegExt();
	PRIMITIVE VOID FichierRelocPro();
	PRIMITIVE VOID FichierRelocSeg();
	PRIMITIVE WORD FichierRelocMap();
	PRIMITIVE VOID FichierCopyPro();
	PRIMITIVE VOID FichierCopySeg();
	PRIMITIVE VOID FichierCopyVar();
	PRIMITIVE VOID FichierCopyCst();
	PRIMITIVE VOID FichierCopyCode();
	PRIMITIVE WORD FichierRelocProNum();
	PRIMITIVE WORD FichierRelocSegNum();
	PRIMITIVE VOID FichierEndModule();
	PRIMITIVE VOID FichierCstConstruct();
	PRIMITIVE VOID FichierVarConstruct();
	PRIMITIVE VOID FichierProConstruct();
	PRIMITIVE VOID FichierSegConstruct();
	PRIMITIVE VOID FichierNomProConstruct();
	PRIMITIVE VOID FichierNomSegConstruct();
	PRIMITIVE VOID FichierSourceConstruct();
	PRIMITIVE VOID FichierBdaConstruct();
	PRIMITIVE VOID FichierRelocProApp();
	PRIMITIVE VOID FichierRelocSegApp();
	PRIMITIVE VOID FichierRelocModExt();
	PRIMITIVE VOID FichierRelocVarExt();
	PRIMITIVE WORD IsFileOpened();
#endif	/* LINT_ARGS */

#define _LKFICH_HP

#endif /* __LKFICH_H__ */

