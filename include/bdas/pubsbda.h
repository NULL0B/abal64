/*
 *  Projet  : ABAL      Copyright Prologue s.a. (c) 1992, 2000
 *  Module  : bibliothèque dynamique pour WEXA
 *  Fichier : PUBSBDA.H
 *  Version : 2.00
 *  Date    : 20/04/2000
 *  Systeme : Windows 3/95/98/NT/2000
 *
 *  Bibliotheques dynamiques ABAL
 *
 *  [Interface avec les bibliotheques dynamiques - Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *  20/04/2000 : mise à jour v2.00
 *  28/11/2000 : mise à jour v2.01 FCH ajout compatibilité Twin16
 */

#ifndef __PUBSBDA_H__
#define __PUBSBDA_H__


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*      EXTRAIT DE BDA.H                                                     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */


/* Definition du type d'interface de BDA */
#ifdef FCT_ENTETE
#undef FCT_ENTETE
#endif 

#if defined(BDA_UNIX) || defined(BDA_VMS) || defined(BDA_WIN16) || defined(BDA_WIN32)
#define FCT_ENTETE
#endif 


/* Quelques constantes d'usage des BDA */

#define NUMERO_VERSION      1
#define MAX_ARGUMENT        20
#define MAX_BDA             10
#define MAX_FONCTION        255
#define MAX_IDENTIFICATEUR  8
#define INIT_PUBLIC         0
#define INIT_PRIVATE        1
#define INIT_EXPORT         2


/* Types des donnees manipulees */

#define TYPE_DIESE      0x00
#define TYPE_INT8       0x00
#define TYPE_POURCENT   0x01
#define TYPE_INT16      0x01
#define TYPE_DEUXPOINT	0x05
#define TYPE_INT32    	0x05
#define TYPE_INT64    	0x06
#define TYPE_BCD        0x02
#define TYPE_CHAINE     0x03
#define TYPE_WORD       0x09
#define TYPE            0x0f
#define MODIFIABLE      0x80


/* Comptes-rendus */

#define BDA_ERREUR    0
#define BDA_OK        1
#define BDA_SCRATCH   138
#define BDA_UNKNOWN   139


/* Types de bibliotheques */

#define BDA_ORDINAIRE     	1
#define BDA_ASFUN         	2
#define BDA_ASFUN11   		3
#define	BDA_ZGR     		4
#define BDA_REDIRECT      	5


/* Codes des fonctions d'appel d'une bibliotheque statique */

#define FC_INIT   0
#define FC_KILL   1
#define FC_CALL   2
#define FC_MAX    2


/* Fonctions de CICO redirigees */

#define CICO_CI       0
#define CICO_TPCI     1
#define CICO_PRFO     2
#define CICO_LCFO     3
#define CICO_CONF     4
#define CICO_CO       5
#define CICO_MES      6
#define CICO_LIGNE    7
#define CICO_COLONNE  8
#define CICO_START    9
#define CICO_FLUSH    10
#define CICO_LO       11
#define CICO_MIMA     12
#define CICO_EVENT    13
#define	CICO_INIT     14
#define	CICO_GRAPH    15
#define	CICO_CALLBACK 16
#define CICO_NOMBRE   17


// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//  DESCRIPTION DES STRUCTURES DE DONNEES
//
//  Note:
//  Alignement des membres de structures:
//    Ces structures doivent être compatibles avec Wexa
//    - en 16 bits, alignement sur des octets
//    - en 32 bits, alignement sur des ??????
//  ==> utilisation de pragma pack, ou alignement "à la main" 
//      selon les compilateurs
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifdef BDA_BORLAND
#define BDA_BORLAND_ALIGN_FILLER(TYPE)    int :sizeof(TYPE)*8;
#else
#define BDA_BORLAND_ALIGN_FILLER(TYPE)
#endif

#if (defined(BDA_WIN16) || defined(BDA_TWIN16)) && defined(BDA_VC)
#pragma pack(1)
#endif

// Structure de definition d'une BDA : remplie par la BDA
typedef struct 
  {
  VOID (FAR PTR banniere)();
  VOID (FAR PTR fin)();
  
#ifdef BDA_VMS
  BYTE FAR PTR nom[MAX_FONCTION];
#else
  VOID  FAR PTR reserve;
#endif
  EXAWORD nombre;
    BDA_BORLAND_ALIGN_FILLER(WORD)
  EXAWORD (PASCAL FAR PTR fonction[MAX_FONCTION])();
  } BDA;


// Structure de passage des arguments a une BDA
typedef struct 
  {
  EXAWORD c;                     /* nombre d'arguments       */
    BDA_BORLAND_ALIGN_FILLER(WORD)
  void FAR* v[MAX_ARGUMENT];  /* arguments                */
  BYTE t[MAX_ARGUMENT];       /* type des arguments       */
  EXAWORD l[MAX_ARGUMENT];       /* taille des arguments     */
  } I_BDA_ARG;

typedef struct 
  {
  EXAWORD c;                     /* nombre d'arguments       */
    BDA_BORLAND_ALIGN_FILLER(WORD)
  void FAR * FAR * v;         /* arguments                */
  BYTE FAR * t;               /* type des arguments       */
  EXAWORD FAR * l;               /* taille des arguments     */
  
  #if defined (BDA_WIN16) || defined(BDA_WIN32)
  HINSTANCE hInstance;        /* instance appelante       */
  HWND hWnd;                  /* handle fenetre principale*/
  FARPROC lpfnHook;           /* ptr fonction de hook     */
  #endif
  } BDA_ARG;


// Description de la bibliotheque dynamique
typedef union 
  {
  struct 
    {
    EXAWORD signature;
    EXAWORD numero;
    } ordinaire;
  struct 
    {
    EXAWORD signature;
    EXAWORD numero;
    
    #if defined (BDA_TWIN16) 
    VOID FAR PTR Relay_Co;
    VOID FAR PTR Relay_Info;
    VOID FAR PTR Relay_Mes;
    VOID FAR PTR Relay_Lo;
    VOID FAR PTR Relay_Ci;
    EXAWORD capacite;      /* bit  function  */
                        /*  0 Co          */
                        /*  1 Info        */
                        /*  2 Mes         */
                        /*  3 Lo          */
                        /*  4 Ci          */
    #else
    VOID FAR PTR /* WORD */ fonction[CICO_NOMBRE];
    #endif
    } cico;
  } BDA_INIT;

#if (defined(BDA_WIN16) || defined(BDA_TWIN16)) && defined(BDA_VC)
#pragma pack()
#endif

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//  POINTEURS SUR LES STRUCTURES DE DONNEES
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
typedef BDA         FAR PTR LPBDA;
typedef I_BDA_ARG   FAR PTR LPI_BDA_ARG;
typedef BDA_ARG     FAR PTR LPBDA_ARG;
typedef BDA_INIT    FAR PTR LPBDA_INIT;

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//  DECLARATION DE FONCTIONS
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

EXAWORD InitRunTime(
		EXAWORD, BYTE FAR PTR, EXAWORD, 
		EXAWORD FAR PTR, BYTE FAR PTR, /* these 2 are new for ABAL 3 */
		BDA_INIT FAR PTR, EXAWORD);

EXAWORD CallRunTime(EXAWORD, EXAWORD, EXAWORD, BYTE FAR [], VOID FAR PTR FAR [], EXAWORD FAR []);
EXAWORD FinRunTime(EXAWORD);

VOID FAR PTR InitRelais();

#endif /* __PUBSBDA_H__ */

