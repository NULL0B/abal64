/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990
 *	Module  : EXA / C
 *	Fichier : EXC.H
 *	Version : 1.4a
 *	Date    : 03/07/90
 *	Systeme : DOS/PRL
 *
 *	Interface entre l'executeur ABAL (ou tout autre programme C)
 *	et les bibliotheques dynamiques.
 *
 *	[Definitions standard]
 *
 */


/* ------------------------------------------------------------------ */
/* Definitions des types
 */

typedef unsigned short int BINAIRE;
typedef char EXABYTE;
typedef enum {FALSE,TRUE} BOOL;


/* ------------------------------------------------------------------ */
/* Definitions generales
 */

#define	EOSTR	'\0'			/* caractere de fin de chaine */
#define	EONAME	'\r'			/* caractere de fin de nom (ANFC) */
#define	VFP	(void far *)		/* definition d'un pointeur 32 bits */


/* ------------------------------------------------------------------ */
/* Definition des types d'utilisation des bibliotheques
 */

#define INIT_PUBLIC	0		/* utilise une bibli publique */
#define INIT_PRIVATE	1		/* utilise une copie privee */
#define INIT_EXPORT	2		/* bibli heritable */
#define INIT_LOCALE	0		/* bibli non heritable */


/* ------------------------------------------------------------------ */
/* Definition des signatures des bibliotheques
 */

#define BDA_ERREUR	0
#define BDA_OK		1
#define BDA_ORDINAIRE	1		/* bibliotheque standard */
#define BDA_CICO	2		/* bibli avec CICO local */


/* ------------------------------------------------------------------ */
/* Definition des particularites des bibli CICO
 */

#define	REDIR_ACTIV	1		/* active la redirection de CICO */
#define REDIR_DESAC	0		/* desactive la redirection */

#define	REDIR_CI	1		/* route le CI */
#define REDIR_CO	2		/* route le CO */
#define REDIR_LO	4		/* route le LO */

#define REDIR_ERREUR	0xffff
#define REDIR_OK	0

#define CICO_NOMBRE	12		/* nombre de fonctions CICO */

/* ------------------------------------------------------------------ */
/* Definition de la structure de renseignements sur la bibliotheque
 */

typedef union {
  BINAIRE signature;			/* bibliotheque ordinaire */

  struct {				/* bibliotheque CICO */
	BINAIRE signature;
#ifdef	prologue
	void far *Relay_Co;
	void far *Relay_Info;
	void far *Relay_Mes;
	void far *Relay_Lo;
	void far *Relay_Ci;
	BINAIRE capacite;
#endif
#ifdef msdos
	BINAIRE numero;
	BINAIRE fonction[CICO_NOMBRE];
#endif
  } cico;

} BDA_INIT;


/* ------------------------------------------------------------------ */
/* Definition de la structure de passage des arguments
 */

typedef struct {
  BINAIRE c;
  void far * far *v;
  EXABYTE far *t;
  BINAIRE far *l;
} BDA_ARG;

