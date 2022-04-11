/*
 *	Bibliotheques Dynamiques ABAL
 *	-----------------------------
 *
 *	bda.h - definitions pour B.D.A.
 *	ABAL - Version 1.4c
 *
 *	(C) Copyright Amenesik / Sologic s.a. 1990, 1993
 */

#include "hosts.h"

#ifndef _BDA_DEFINED
#define _BDA_DEFINED

/*
 *	Controle la definition d'un OS
 *	------------------------------
 */
#ifndef msdos
#ifndef dosext
#ifndef prologue
#ifndef unix
#ifndef vms
int char double;		/* provoque une erreur a coup sur */
#endif
#endif
#endif
#endif
#endif


/* -----------------------------------------------------------------
 *
 *	Definition de l'environnement de compilation.
 *
 * -----------------------------------------------------------------
 */
#ifdef FCT_ENTETE
#undef FCT_ENTETE
#endif /* FCT_ENTETE */

#ifdef unix
#define FCT_ENTETE
#endif /* unix */

#ifdef vms
#define FCT_ENTETE
#endif /* vms */

#ifdef dosext
#define FCT_ENTETE
#endif

/* ----------------------------------------------------------------
 *
 *	Definitions des types utilises dans les bibliotheques
 *	dynamiques.
 *
 * ----------------------------------------------------------------
 */

#ifndef	_TYPEH_DEFINED
#define	_TYPEH_DEFINED

/*
 *	type signe
 *	----------
 */
#ifdef SIGNEDVALUE
#undef SIGNEDVALUE
#endif /* SIGNEDVALUE */

#ifdef __ANSI__COMPILER__
#define SIGNEDVALUE signed
#else
#define SIGNEDVALUE
#endif

/*
 *	octet non signe
 *	---------------
 */
#ifdef BYTE
#undef BYTE
#endif /* BYTE */
#define BYTE unsigned char

/*
 *	octet signe
 *	-----------
 */
#ifdef CHAR
#undef CHAR
#endif /* CHAR */
#define CHAR SIGNEDVALUE char

/*
 *	type "sans type"
 *	----------------
 */
#ifdef VOID
#undef VOID
#endif /* VOID */
#define VOID	void

/*
 *	mot de 16 bits non signe
 *	------------------------
 */
#ifdef WORD
#undef WORD
#endif /* WORD */
#define WORD unsigned short int 

/*
 *	mot de 16 bits signe
 *	--------------------
 */
#ifdef SWORD
#undef SWORD
#endif /* SWORD */
#define SWORD SIGNEDVALUE short int 

/*
 *	mot de 32 bits signe
 *	--------------------
 */
#ifdef LONG
#undef LONG
#endif /* LONG */
#define LONG SIGNEDVALUE long

/*
 *	mot de 32 bits non signe
 *	------------------------
 */
#ifdef DWORD
#undef DWORD
#endif /* DWORD */
#define DWORD unsigned long

/*
 *	booleen
 *	-------
 */
#ifdef BOOL
#undef BOOL
#endif /* BOOL */

#ifdef FALSE
#undef FALSE
#endif /* FALSE */

#ifdef TRUE
#undef TRUE
#endif /* TRUE */

#define FALSE	0
#define TRUE	1
#define BOOL	int		/* pas d'enum car non portable */

/*
 *	type flottant double precision
 *	------------------------------
 */
#ifdef DOUBLE
#undef DOUBLE
#endif /* DOUBLE */
#define DOUBLE double

/*
 *	type pointeur
 *	-------------
 */
#ifdef PTR
#undef PTR
#endif /* PTR */
#define PTR *

/*
 *	modificateur d'allocation
 *	-------------------------
 */
#ifdef FAR
#undef FAR
#endif

#ifdef msdos
#define FAR far
#endif

#ifdef dosext
#define FAR far
#endif

#ifdef prologue
#define FAR far
#endif

#ifdef unix
#define FAR
#endif

#ifdef vms
#define FAR
#endif


/*
 *	modificateur d'appel aux fonctions
 *	----------------------------------
 */
#ifdef PASCAL
#undef PASCAL
#endif

#ifdef dosext
#define	PASCAL pascal
#else
#define PASCAL
#endif

/*
 *	Declaration globale
 *	-------------------
 */
#ifdef GLOBAL
#undef GLOBAL
#endif /* GLOBAL */

#ifdef vms
#define GLOBAL	noshare
#else
#define GLOBAL
#endif /* vms */

/*
 *	Pointeur NULL type
 *	------------------
 */
#ifdef GN
#undef GN
#endif /* GN */
#define GN(x)	(x PTR) NULL

#endif	/* _TYPEH_DEFINED */
	/* -------------- */



/* ------------------------------
 *
 *	Constantes utilisees .
 *
 * ------------------------------
 */

#define NUMERO_VERSION		1

#define MAX_ARGUMENT		20
#define MAX_BDA 		10
#define MAX_FONCTION		255
#define MAX_IDENTIFICATEUR	8


/*
 *	definition des types d'arguments
 *	--------------------------------
 */

#define TYPE_DIESE		0x00
#define TYPE_POURCENT		0x01
#define TYPE_BCD		0x02
#define TYPE_CHAINE		0x03
#define TYPE_WORD		0x09

#define TYPE			0x0f
#define MODIFIABLE		0x80


/*
 *	definition des types d'initialisation
 *	-------------------------------------
 */

#define INIT_PUBLIC		0
#define INIT_PRIVATE		1
#define INIT_EXPORT		2


/*
 *	definition des signatures de bibliotheque
 *	-----------------------------------------
 */

#define BDA_ERREUR		0
#define BDA_OK			1

#define BDA_ORDINAIRE		1
#define BDA_ASFUN		2
#define BDA_REDIRECT		5


/*
 *	definition des fonctions redirigeables de CICO
 *	----------------------------------------------
 */

#define CICO_CI 		0
#define CICO_TPCI		1
#define CICO_PRFO		2
#define CICO_LCFO		3
#define CICO_CONF		4
#define CICO_CO 		5
#define CICO_MES		6
#define CICO_LIGNE		7
#define CICO_COLONNE		8
#define CICO_START		9
#define CICO_FLUSH		10
#define CICO_LO 		11

#define CICO_NOMBRE		12


/*
 *	structures de description d'une bibliotheque
 *	--------------------------------------------
 */

typedef struct {
	VOID (FAR PTR banniere)();
	VOID (FAR PTR fin)();
#ifdef vms
	BYTE FAR PTR nom[MAX_FONCTION];
#else
	VOID FAR PTR reserve;
#endif /* vms */
	WORD nombre;
	WORD (FAR PTR PASCAL fonction[MAX_FONCTION])();
} BDA;


typedef union {
	struct {
		WORD signature;
		WORD numero;
	} ordinaire;
	struct {
		WORD signature;
		WORD numero;
#ifdef prologue
		VOID FAR PTR Relay_Co;
		VOID FAR PTR Relay_Info;
		VOID FAR PTR Relay_Mes;
		VOID FAR PTR Relay_Lo;
		VOID FAR PTR Relay_Ci;
		WORD capacite;			/* bit	fonction	*/
						/*  0	Co		*/
						/*  1	Info		*/
						/*  2	Mes		*/
						/*  3	Lo		*/
						/*  4	Ci		*/
#else
		WORD fonction[CICO_NOMBRE];
#endif /* prologue */
	} cico;
} BDA_INIT;


/*
 *	structure d'acces aux arguments
 *	-------------------------------
 */

typedef struct {
	WORD c; 			/* nombre d'arguments           */
	VOID FAR PTR v[MAX_ARGUMENT];	/* arguments			*/
	BYTE t[MAX_ARGUMENT];		/* type des arguments		*/
	WORD l[MAX_ARGUMENT];		/* taille des arguments 	*/
} I_BDA_ARG;

typedef struct {
	WORD c; 		/* nombre d'arguments           */
	VOID FAR PTR FAR PTR v;	/* arguments			*/
	BYTE FAR PTR t;		/* type des arguments		*/
	WORD FAR PTR l;		/* taille des arguments 	*/
} BDA_ARG;


/*
 *	declaration des fonctions
 *	-------------------------
 */

#ifdef LINT_ARGS

WORD FAR InitRunTime(WORD, BYTE FAR PTR, WORD, BDA_INIT FAR PTR, WORD);
WORD FAR CallRunTime(WORD, WORD, WORD, BYTE FAR [], VOID FAR PTR FAR [], WORD FAR []);
WORD FAR FinRunTime(WORD);

#else

WORD FAR InitRunTime();
WORD FAR CallRunTime();
WORD FAR FinRunTime();

#endif /* LINT_ARGS */

#endif /* BDA_DEFINED */

/* fin de fichier */

