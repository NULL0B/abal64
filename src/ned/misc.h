#define __MSC
/*-------------------------------------------------------------- ABAL.H -----
 *
 *	Ensemble integre ABAL	  -	Copyright (c) Amenesik / Sologic s.a. 1989
 *
 *		   Definitions globales de l'ensemble
 *
 *		      Revision 1.2 du 11/07/1989
 *
 *--------------------------------------------------------------------------*/

/*	La definition de l'environnement utilise doit etre faite
 *		lors de l'appel au compilateur
 */

#if small || unix || vms
#define XPTR *
#define FPTR *
#else 
#define XPTR *
#define FPTR far *
#endif

typedef unsigned char BOOL;
#ifdef	VERSION666
typedef unsigned int BINAIRE;	/* type binaire sur 2 octets */
#else
typedef unsigned short int BINAIRE;	/* type binaire sur 2 octets */
#endif
typedef unsigned char BYTE;		/* type binaire sur 1 octet */
typedef short int SWORD; 		/* int 16 octet signe */
typedef void VOID;

#define MOINS_UN -1
#define MOINS_CINQ -5
#define cartoint(c) (c - '0')
#define inttocar(n) (unsigned char) (n + '0')

#define LGEXT 5

#define NULL 0

/*	Parametres dependants du systeme hote 		*/
/*	-------------------------------------		*/

#ifdef prologue
#define LINT_ARGS
#define SEPTYP   '-'  /* separateur entre nom et extension d'un fichier */

#define SEPVOL "."

#define DREP "\\"
#define DELIMREP '\\'  /* delimiteur entre repertoire et nom de fichier */

#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define LGMXNOM 78	/* lg max d'un nom de fichier */
#define LGREP	80 	/* lg nom de repertoire = volume */

#define VAL_RET	0

#endif

#ifdef msdos
#define LINT_ARGS
#define SEPVOL ":"

#define DREP "\\"
#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define DELIMREP '\\'
#define LGMXNOM 78	/* lg max d'un nom de fichier ex 248 */
#define LGREP	80	/* lg d'un repertoire */

#define VAL_RET	0

#endif

#ifdef unix
#define SEPVOL ""
#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '-'  /* delimiteur des options dans ligne de commande */
#define DREP "/"  /* delimiteur entre repertoire et nom de fichier */
#define DELIMREP '/'
#define LGMXNOM 248	/* lg max d'un nom de fichier */
#define LGREP	250	/* lg d'un repertoire */


/*LINTLIBRARY*/		/* LINT: laisser tomber les fonctions de la	*/
			/* bibliotheque non utilisees par le programme  */

#define VAL_RET	0

#endif

#ifdef vms
#define SEPVOL ":"
#define DREP   ""
#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define DELIMREP ']'  /* delimiteur entre repertoire et nom de fichier */
#define LGMXNOM 248	/* lg max d'un nom de fichier */
#define LGREP	250	/* lg nom de repertoire = volume */

#define VAL_RET	STS$M_INHIB_MSG

#endif

	/* includes a prendre en compte */
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
	/* Longueur de la zone de parametre */

#define LGPARAM 250


/*		definition des fonctions standards utilisees		*/
/*		--------------------------------------------		*/
/*		Rem: ces redefinitions sont faites pour faciliter	*/
/*		un portage dans un contexte different, cependant,	*/
/*		printf et fprintf sont supposees "standard 100%".	*/
/*		ainsi que tous les 'is...(i)' (classification CTYPE)	*/

extern	VOID fn_parser( BYTE FPTR, BYTE FPTR, BINAIRE);

#ifndef unix
#define Xfn_parser(s,d,m) fn_parser(s,d,m | 128) 
#else
#define Xfn_parser(s,d,m) fn_parser(s,d,m)
#endif


#define Xexit(n) exit(n)

#ifdef DBmalloc
#define Xfree(p) XXfree(p)
#define Xmalloc(n) XXmalloc(n)
extern BINAIRE nballoc;
#else
#define Xmalloc(n) malloc(n)
#define Xfree(n) free(n)
#endif
#ifdef unix

#define Mstrcpy(d,s) strcpy(d,s)
#define Mstrlen(s) strlen(s)

#define allocate(n) malloc(n)
#define liberate(n) free(n)
#endif

#ifdef msdos
#define allocate(n) (BYTE FPTR) _fmalloc(n)
#define liberate(n) _ffree((BYTE FPTR) n)
#endif
#ifdef prologue
extern BYTE FPTR allocate( BINAIRE );
extern void	  liberate( BYTE FPTR );
#endif

#define Xstrcat(s,p) strcat( (char *) s, (char *) p)
#define Xstrchr(s,c) strchr((char *) s, (char) c)
#define Xstrcmp(s,p) strcmp( (char *) s,  (char *) p)
#define Xstrncmp(s,p,n) strncmp( (char *) s, (char *) p, (int) n)
#define Xstrcpy(d,s) strcpy( (char *) d, (char * ) s)
#define Xstrlen(s) strlen( (char * ) s)
#define Xstrrchr(s,c) strrchr( (char *) s, (char) c)

#ifdef vms
#define Xaccess(f,m) vms$access()
#else
#define Xaccess(f,m) access(f,m)
#endif

#define Xfopen(f,m) fopen(f,m)
#define Xfclose(f) fclose(f)
#define Xfputc(c,f) fputc(c,f)
#define Xfgetc(c) fgetc(c)

/*		test d'egalite entre deux chaines		*/
/*		---------------------------------		*/

#define strEq(s1,s2) (Xstrcmp(s1,s2) == 0)

/*	 	definition generique d'un pointeur NULL 	*/
/*		---------------------------------------		*/

#define GenericNULL(t) (t *) NULL
#define GenericFNULL(t) (t FPTR) NULL


#define TRUE 1
#define FALSE 0

/*		gravite des erreurs			*/
/*		-------------------			*/

#define USUAL	'1'
#define FATALE	'2'

/*		parametres au niveau global		 */
/*		---------------------------		 */


#define EOSTR '\0'            /* caractere terminateur de chaine C */

#define CR	'\r'
#define NL	'\n'
#define PLUS	'+'

/* Modif 2.1c */
FILE * Mainfarg;
BYTE Mainligarg[256];
BYTE XPTR Mainpt_arg;
#define Xfgets(s,n,f) fgets((char *) s, (int) n, (FILE *) f)
#define TABUL 0x09

/* Prototypes */
/* ---------- */
