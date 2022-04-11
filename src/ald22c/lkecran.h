/*------------------------------------------------------------- LKLIB.HE ------
 *
 *	Editeur de liens A.B.A.L.	-   Copyright Amenesik / Sologic s.a. (c) 1993
 *
 *			Declaration des variables publiques 
 *			Declaration des variables et procs. externes
 *
 *			      Creation 2.0 le 07/04/1993
 *
 * Revisions :
 *	
 *
 *---------------------------------------------------------------------------*/

#ifndef __LKECRAN_H__
#define __LKECRAN_H__

#ifdef _LKECRAN

#ifndef vms

PUB BYTE C_CHG = (BYTE) 0x00DA;	/* coin haut et gauche */
PUB BYTE C_LNH = (BYTE) 0x00C4;	/* ligne horizontale */
PUB BYTE C_CHD = (BYTE) 0x00BF;	/* coin haut et droit */
PUB BYTE C_CBG = (BYTE) 0x00C0;	/* coin bas et gauche */
PUB BYTE C_CBD = (BYTE) 0x00D9;	/* coin bas et droit */
PUB BYTE C_LNV = (BYTE) 0x00B3;	/* ligne verticale */

#else

PUB BYTE C_CHG = (BYTE) 0x00F0;	/* coin haut et gauche */
PUB BYTE C_LNH = (BYTE) 0x00BE;	/* ligne horizontale */
PUB BYTE C_CHD = (BYTE) 0x00A4;	/* coin haut et droit */
PUB BYTE C_CBG = (BYTE) 0x00AD;	/* coin bas et gauche */
PUB BYTE C_CBD = (BYTE) 0x00DE;	/* coin bas et droit */
PUB BYTE C_LNV = (BYTE) 0x00A6;	/* ligne verticale */

#endif


#ifdef vms
extern WORD qio_usage_flag;
#endif

#ifndef	EXAWORD
#ifdef	VERSION666
#define	EXAWORD	unsigned long int
#else
#define	EXAWORD	unsigned short int
#endif
#endif

#include "abalcico.h"

#define EcranNbLIG 12
#define EcranNbCOL 63

PUB BYTE EcranCico; /* Variable pour savoir si initerm a ete effectue */
PUB BYTE EcranLH;	/* Ligne Coin Haut Gauche de la boite de dialogue */
PUB BYTE EcranCH;	/* Colonne Coin Haut Gauche de la boite de dialogue */
PUB BYTE EcranLg;	/* index de numero de ligne pour les non resolus */
PUB BYTE EcranBavard;	/*  Mode bavard */

/* prototype des fonctions */


#else 	/* _LKECRAN */ 	/* pour l'exterieur de l'iceberg */

/* Rendre les procedures publiques extern pour les autres */

extern GLOBAL BYTE EcranLH;	/* Ligne Coin Haut Gauche de la boite de dialogue */
extern GLOBAL BYTE EcranCH;	/* Colonne Coin Haut Gauche de la boite de dialogue */

#endif 	/* _LKECRAN */



#ifdef _LKECRAN
#undef PRIMITIVE
#define PRIMITIVE
#endif

#ifdef LINT_ARGS

PRIMITIVE VOID EcranSetLastFileAccessed( char XPTR * FilePath );
PRIMITIVE VOID EcranInit( VOID );
PRIMITIVE VOID EcranSetCico( BYTE );
PRIMITIVE VOID EcranFin( VOID );
PRIMITIVE VOID EcranOutLong(WORD , WORD , ULONG );
PRIMITIVE VOID EcranAffZone( BYTE XPTR * , WORD );
PRIMITIVE VOID EcranCadre( WORD , WORD , WORD , WORD );
PRIMITIVE VOID EcranAtb( BYTE );
PRIMITIVE VOID EcranOutBin( WORD , WORD , WORD );
PRIMITIVE VOID EcranAffInt( WORD );
PRIMITIVE VOID EcranBanniere ( VOID );
PRIMITIVE VOID EcranErreur( WORD );
PRIMITIVE VOID EcranBoite( WORD , WORD );
PRIMITIVE VOID EcranProgram( BYTE XPTR * );
PRIMITIVE VOID EcranEnCours( BYTE XPTR * );
PRIMITIVE VOID EcranWhichError( BYTE XPTR * );
PRIMITIVE VOID EcranAction( WORD );
PRIMITIVE VOID EcranPasse( WORD );
PRIMITIVE VOID EcranAncrage( Ancrage XPTR *, BYTE XPTR * );
PRIMITIVE VOID EcranVar( InfoVar XPTR * , LstPro XPTR *, BYTE XPTR * );
PRIMITIVE VOID EcranArgument( C_SNODE FAR *, BYTE XPTR * );
PRIMITIVE VOID EcranProcedure(LstPro * , BYTE XPTR * );
PRIMITIVE VOID EcranSegment(LstPro * , BYTE XPTR * );
PRIMITIVE VOID EcranInitOutErr( Option XPTR * );
PRIMITIVE VOID EcranEndOutErr( Option XPTR * );
PRIMITIVE WORD EcranOutErr( Option XPTR *, BYTE XPTR * );
PRIMITIVE VOID EcranAffNonResolus( Option XPTR *, Fichier XPTR * );
PRIMITIVE VOID EcranAffPublic( Option XPTR *, Fichier XPTR * );
PRIMITIVE VOID EcranAffResolus( Option XPTR *, Fichier XPTR * );
PRIMITIVE VOID EcranSignalSortie( WORD );
PRIMITIVE VOID EcranSignalSet( WORD );
PRIMITIVE VOID EcranBoiteMaj( WORD, WORD, Fichier XPTR * );
PRIMITIVE VOID EcranClearBox( VOID );
PRIMITIVE WORD EcranMsgMore( VOID );
PRIMITIVE VOID EcranSetBavard( VOID );
PRIMITIVE WORD CheckNonResolus( Fichier XPTR * );
PRIMITIVE void EcranWarningFichier( ctConstStr FilePath );

#else 	/* LINT_ARGS */

PRIMITIVE VOID EcranSetLastFileAccessed();
PRIMITIVE VOID EcranInit();
PRIMITIVE VOID EcranSetCico();
PRIMITIVE VOID EcranFin();
PRIMITIVE VOID EcranOutLong();
PRIMITIVE VOID EcranAffZone();
PRIMITIVE VOID EcranCadre();
PRIMITIVE VOID EcranAtb();
PRIMITIVE VOID EcranOutBin();
PRIMITIVE VOID EcranAffInt();
PRIMITIVE VOID EcranBanniere ();
PRIMITIVE VOID EcranErreur();
PRIMITIVE VOID EcranBoite();
PRIMITIVE VOID EcranProgram();
PRIMITIVE VOID EcranEnCours();
PRIMITIVE VOID EcranWhichError();
PRIMITIVE VOID EcranAction();
PRIMITIVE VOID EcranPasse();
PRIMITIVE VOID EcranAncrage();
PRIMITIVE VOID EcranVar();
PRIMITIVE VOID EcranArgument();
PRIMITIVE VOID EcranProcedure();
PRIMITIVE VOID EcranSegment();
PRIMITIVE VOID EcranInitOutErr();
PRIMITIVE VOID EcranFinOutErr();
PRIMITIVE WORD EcranOutErr();
PRIMITIVE VOID EcranAffPublic();
PRIMITIVE VOID EcranAffNonResolus();
PRIMITIVE VOID EcranAffResolus();
PRIMITIVE VOID EcranSignalSortie();
PRIMITIVE VOID EcranSignalSet();
PRIMITIVE VOID EcranBoiteMaj();
PRIMITIVE VOID EcranClearBox();
PRIMITIVE WORD EcranMsgMore();
PRIMITIVE VOID EcranSetBavard();
PRIMITIVE WORD CheckNonResolus();
PRIMITIVE void EcranWarningFichier();

#endif 	/* LINT_ARGS */


#endif  /* __LKECRAN_H__ */







