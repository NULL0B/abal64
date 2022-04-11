/*
 *	ABAL DLL
 *	--------
 *
 *	bda.h - definitions pour DLL.
 *	ABAL - Version 1.4
 *
 *	(C) Copyright Prologue s.a. 1990, 1991
 */

#ifndef _BDA_DEFINED
#define _BDA_DEFINED

/* -----------------------------------------------------------------
 *
 *	Compilation set definition.
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


/* ----------------------------------------------------------------
 *
 *	Definitions of types used in DLL.
 *
 * ----------------------------------------------------------------
 */

#ifndef	_TYPEH_DEFINED
#define	_TYPEH_DEFINED

/*
 *	unsigned byte
 *	-------------
 */
#ifdef BYTE
#undef BYTE
#endif /* BYTE */
#define BYTE unsigned char

/*
 *	signed byte
 *	-----------
 */
#ifdef CHAR
#undef CHAR
#endif /* CHAR */
#define CHAR signed char

/*
 *	"without type" type
 *	-------------------
 */
#ifdef VOID
#undef VOID
#endif /* VOID */
#define VOID	void

/*
 *	unsigned 16 bits word
 *	---------------------
 */
#ifdef WORD
#undef WORD
#endif /* WORD */
#define WORD unsigned short int 

/*
 *	signed 16 bits word
 *	-------------------
 */
#ifdef SWORD
#undef SWORD
#endif /* SWORD */
#define SWORD short int 

/*
 *	signed 32 bits word
 *	-------------------
 */
#ifdef LONG
#undef LONG
#endif /* LONG */
#define LONG long

/*
 *	unsigned 32 bits word
 *	---------------------
 */
#ifdef DWORD
#undef DWORD
#endif /* DWORD */
#define DWORD unsigned long

/*
 *	boolean
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
#define BOOL	int		

/*
 *	float
 *	-----
 */
#ifdef DOUBLE
#undef DOUBLE
#endif /* DOUBLE */
#define DOUBLE double

/*
 *	pointer
 *	-------
 */
#ifdef PTR
#undef PTR
#endif /* PTR */
#define PTR *

/*
 *	allocation modificator
 *	----------------------
 */
#ifndef FAR

#ifdef msdos
#define FAR far
#else
#ifdef prologue
#define FAR far
#else
#if M_I8086 || M_I186 || M_I286 || __TURBOC__
#define FAR far
#else
#define FAR
#endif /* M_I8086 || M_I186 || M_I286 || __TURBOC__ */
#endif /* prologue */
#endif /* msdos */

#endif /* FAR */

/*
 *	Global Declaration
 *	------------------
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
 *	NULL pointer type
 *	-----------------
 */
#ifdef GN
#undef GN
#endif /* GN */
#define GN(x)	(x PTR) NULL

#endif	/* _TYPEH_DEFINED */
	/* -------------- */



/* ------------------------------
 *
 *	Used constants .
 *
 * ------------------------------
 */

#define NUMERO_VERSION		1

#define MAX_ARGUMENT		20
#define MAX_BDA 		10
#define MAX_FONCTION		255
#define MAX_IDENTIFICATEUR	8


/*
 *	argument type definition
 *	------------------------
 */

#define TYPE_DIESE		0x00
#define TYPE_POURCENT		0x01
#define TYPE_DEUXPOINT		0x05
#define TYPE_BCD		0x02
#define TYPE_CHAINE		0x03
#define TYPE_WORD		0x09

#define TYPE			0x0f
#define MODIFIABLE		0x80


/*
 *	initialization type definition
 *	------------------------------
 */

#define INIT_PUBLIC		0
#define INIT_PRIVATE		1
#define INIT_EXPORT		2


/*
 *	library signing definition
 *	--------------------------
 */

#define BDA_ERREUR		0
#define BDA_OK			1

#define BDA_ORDINAIRE		1
#define BDA_ASFUN		2
#define BDA_REDIRECT		5


/*
 *	definition of CICO functions
 *	----------------------------
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
 *	library description structure
 *	-----------------------------
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
	WORD (FAR PTR fonction[MAX_FONCTION])();
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
		WORD capacite;			/* bit	function	*/
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
 *	argument access structure
 *	-------------------------
 */

typedef struct {
	WORD c; 			/* argument number              */
	VOID FAR PTR v[MAX_ARGUMENT];	/* arguments			*/
	BYTE t[MAX_ARGUMENT];		/* argument type     		*/
	WORD l[MAX_ARGUMENT];		/* argument length      	*/
} I_BDA_ARG;

typedef struct {
	WORD c; 		/* argument number              */
	VOID FAR PTR FAR PTR v;	/* arguments			*/
	BYTE FAR PTR t;		/* argument type     		*/
	WORD FAR PTR l;		/* argument length      	*/
} BDA_ARG;


/*
 *	functions declaration    
 *	---------------------
 */

#if M_I86 || __TURBOC__ || unix

WORD InitRunTime(WORD, BYTE FAR PTR, WORD, WORD FAR PTR, BYTE FAR PTR, BDA_INIT FAR PTR, WORD);
WORD CallRunTime(WORD, WORD, WORD, BYTE FAR [], VOID FAR PTR FAR [], WORD FAR []);
WORD FinRunTime(WORD);

#else

WORD InitRunTime();
WORD CallRunTime();
WORD FinRunTime();

#endif /* M_I86 || __TURBOC__ */

#endif /* BDA_DEFINED */

/* end of file    */

