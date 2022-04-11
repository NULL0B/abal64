/*
 *	Bibliotheques Dynamiques ABAL
 *	-----------------------------
 *
 *	Copyright (c) 1989 Amenesik Sologic s.a.
 *
 *	bda.h - definitions pour B.D.A.
 *
 *	$Header: /home/Produits/Abal3/include/bda.h,v 1.3 2007/07/13 09:27:59 jamie Exp $
 *
 */

#ifndef	_bda_h
#define _bda_h

#include "_type.h"


/*
 *	types utilises
 *	--------------
 */
#ifndef	EXAWORD
#ifdef	VERSION666
#define	EXAWORD	LONG
#else
#define	EXAWORD	WORD
#endif
#endif


#ifndef _GLOBAL_DEFINED
#ifdef vms
#define GLOBAL	noshare
#else
#define GLOBAL
#endif /* vms */
#define _GLOBAL_DEFINED
#endif /* _GLOBAL_DEFINED */


/*
 *	constantes utilisees
 *	--------------------
 */
#ifdef	unix
#define	BDA_API
#endif

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
#define TYPE_INT8    		0x00
#define TYPE_POURCENT		0x01
#define TYPE_INT16   		0x01
#define TYPE_DEUXPOINT		0x05
#define TYPE_INT32    		0x05
#define TYPE_INT64		0x06
#define TYPE_BCD		0x02
#define TYPE_CHAINE		0x03
#define TYPE_WORD		0x09

#define TYPE			0x0f
#define MODIFIABLE		0x80

/* Comptes-rendus */

#define BDA_ERREUR    0
#define BDA_OK        1
#define BDA_SCRATCH   138
#define BDA_UNKNOWN   139


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

#define BDA_ORDINAIRE		1
#define BDA_ASFUN		2
#define BDA_DLL_WINDOWS   	3
#define	BDA_DLL_SCREENER	4
#define	BDA_REDIRECT		5

/* Codes des fonctions d'appel d'une bibliotheque statique */

#define FC_INIT   0
#define FC_KILL   1
#define FC_CALL   2
#define FC_MAX    2

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
#define CICO_MIMA		12
#define	CICO_EVENT		13
#define	CICO_INIT		14
#define	CICO_GRAPH		15
#define	CICO_CALLBACK		16
#define CICO_NOMBRE		17


/*
 *	structures de description d'une bibliotheque
 *	--------------------------------------------
 */

typedef struct {
	void (FAR * banniere)();
	void (FAR * fin)();
#ifdef vms
	BYTE FAR *nom[MAX_FONCTION];
#else
	void FAR *reserve;
#endif /* vms */
	int nombre;
	// EXAWORD (FAR * fonction[MAX_FONCTION])(void FAR *);
	EXAWORD (FAR * fonction[MAX_FONCTION])();
} BDA;


typedef union {
	struct {
	EXAWORD signature;
	EXAWORD numero;
        } ordinaire;
	struct {
		EXAWORD signature;
#if defined (PRL) 
		void far *Relay_Co;
		void far *Relay_Info;
		void far *Relay_Mes;
		void far *Relay_Mi;
		void far *Relay_Ci;
		EXAWORD capacite;
#else
		EXAWORD numero;
		void * /* EXAWORD */ fonction[CICO_NOMBRE];
#endif /* PRL */
	} cico;
} BDA_INIT;

extern BDA_INIT FAR *rt_init;	/* declaree dans l'entete       */

#define	LPBDA_INIT extern BDA_INIT FAR *


/*
 *	structure d'acces aux arguments
 *	-------------------------------
 */

typedef struct {
	EXAWORD c; 		/* nombre d'arguments           */
/* IJM Linux / Use It */
	void  * v;
	BYTE  * t;
	EXAWORD  * l;
#ifdef	KEEP_THIS_SHIT
	void *v[MAX_ARGUMENT];	/* arguments			*/
	BYTE t[MAX_ARGUMENT];	/* type des arguments		*/
	EXAWORD l[MAX_ARGUMENT];	/* taille des arguments 	*/
#endif
} BDA_ARG;

extern BDA_ARG rt_arg;		/* declaree dans l'entete       */


/*
 *	declaration des fonctions
 *	-------------------------
 */

#if M_I86

EXAWORD InitRunTime(EXAWORD, BPTR , EXAWORD, BPTR , EXAWORD);
EXAWORD CallRunTime(EXAWORD, EXAWORD, EXAWORD, BPTR , BPTR , BPTR );
EXAWORD FinRunTime(EXAWORD);

#else

EXAWORD InitRunTime();
EXAWORD CallRunTime();
EXAWORD FinRunTime();

#endif /* M_I86 */

#define	PASCAL

#ifndef	EXABYTE
#define	EXABYTE	BYTE
#endif

#ifndef	EXALONG
#define	EXALONG	LONG
#endif

/* fin de fichier */
#endif	/* _bda_h */

