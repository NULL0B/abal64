/*----------------------------------------------------------------- ED.H -----
 *
 *	Editeur de textes ABAL	  -	Copyright Amenesik / Sologic s.a. (c) 1988, 1995
 *
 *		   Definitions globales de l'editeur
 *
 * Maj : 20/09/95 : cf EDNOY.C
 *
 *--------------------------------------------------------------------------*/

#define YT230298

#define	INDENT Indenter
#ifdef ver21
#ifndef	ver14
#define ver14
#endif
#endif

#define AEDPLUSPLUS "AED++\0\0"

/*	La definition de l'environnement utilise doit etre faite
 *		lors de l'appel au compilateur
 *
 *	En principe, toutes les parties "sensibles" aux portages
 *	sont definies dans ce fichier ou dans le module ED.C
 *	--------------------------------------------------------	*/
typedef void VOID;
typedef int SWORD;		/* type binaire signe */
typedef unsigned int BINAIRE;	/* type binaire sur 2 octets */
typedef unsigned char BYTE;		/* type binaire sur 1 octet */
typedef unsigned long int ULONG;
typedef long int LONG;
typedef unsigned short int WORD;
typedef char * BPTR;

#define cartoint(c) (c - '0')
#define inttocar(n) (BYTE) (n + '0')

#define XPTR *
#if small || unix || vms
#define FPTR *
#else
#ifdef ver14
#define FPTR far *
#else
#define FPTR *
#endif
#endif

#ifdef ver21

#include "traceman.h"

#endif

/*	Parametres dependants du systeme hote 		*/
/*	-------------------------------------		*/

#ifdef prologue

#ifndef ver14
#define anc_bib
#endif

#define LINT_ARGS
#define LGREP 80

#define SEPTYP   '-'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define LGMXNOM 63	/* lg max d'un nom de fichier */
#define DELIMREP '.'

#define EXTDEST	"$"   /* extension fichier destination */
#define EXTRET	"#"   /* extension fichier retour */

#define ONNLCR	1	/* fin de ligne = CR-LF sous cet O.S. */
#undef LGEXACTE	/* fichiers doivent avoir un delimiteur de fin */

#ifdef anc_bib
#include <pstdio.h>
#include <pctype.h>
#include <prldef.h>

#else
#include <stdio.h>
#include <ctype.h>
#include "c:\obair\include\prl.h"
#endif

#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>
#include <setjmp.h>
#include <errno.h>
#include <io.h>
#include <time.h>
#include <sys\types.h>
#include <sys\stat.h>

#include "palet.h"

#define	pos(a,b) x_pos(a,b)
#define foregr(a) x_foregr(a)
#define backgr(a) x_backgr(a)
#define prfo(a,b,c) x_prfo(a,b,c)
#define lcfo(a,b,c) x_lcfo(a,b,c)
#define	atb(a) x_atb(a)

#define XRDopen(f) XTopen(f, (SWORD) O_RDONLY, S_IREAD)
#define Topen(f) open(f,(int) (O_CREAT | O_BINARY),(int) (S_IREAD | S_IWRITE))

/* YT131097*/
/*#ifdef anc_bib*/
#ifndef anc_bib
#define Xcreat(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY),(SWORD) (S_IREAD | S_IWRITE))
#define Xopen(f) XTopen(f,(SWORD) (O_RDWR | O_BINARY),(SWORD) (S_IREAD | S_IWRITE))
#else
#define Xcreat(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_LOCK | O_BINARY),(SWORD) (S_IREAD | S_IWRITE))
#define Xopen(f) XTopen(f,(SWORD) (O_LOCK | O_BINARY),(SWORD) (S_IREAD | S_IWRITE))
#endif

#define Xunlink(n) unlink(n)

#define MOINS_UN -1
#endif

#ifdef msdos

#define LINT_ARGS

#define MOINS_UN 0xffff

#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define LGMXNOM 63	/* lg max d'un nom de fichier */
#define DELIMREP '\\'

#define LGREP 80

#define EXTDEST	"$$$"   /* extension fichier destination */
#define EXTRET	"###"   /* extension fichier retour */

/* #undef  ONNLCR	*/	/* fin de ligne = LF seulement sous cet O.S. */
#define ONNLCR 	1  /* fin de ligne = CR-LF sous cet O.S. */
#undef  LGEXACTE   /* fichiers doivent avoir un delimiteur de fin */

#include <dos.h>	/* Pour anfc  */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#ifdef BORLAND
#include <alloc.h>
#else
#include <malloc.h>
#endif
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <setjmp.h>
#include <stddef.h>
#include <errno.h>
#include <io.h>

#define XRDopen(f) XTopen((BYTE XPTR) f, (SWORD) O_RDONLY, S_IREAD)
#define Topen(f) open((char *) f,(int) (O_CREAT | O_RDWR | O_BINARY),(int) (S_IREAD | S_IWRITE))
#define Xopen(f) XTopen((BYTE XPTR) f,(SWORD) (O_RDWR | O_BINARY),(SWORD) (S_IREAD | S_IWRITE))
#define Xcreat(f) XTopen((BYTE XPTR) f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY),(SWORD) (S_IREAD | S_IWRITE))
#define Xcreat_mode(f) XTopen((BYTE XPTR) f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY), buf.st_mode)

#define Xunlink(n) unlink((char *) n)

#endif

#ifdef unix

#define LGREP 80
#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '-'  /* delimiteur des options dans ligne de commande */
#define LGMXNOM 80	/* lg max d'un nom de fichier */
#define DELIMREP '/'
#define MOINS_UN 0xFFFF
#define EXTDEST	"$$$"   /* extension fichier destination */
#define EXTRET	"###"   /* extension fichier retour */
#undef  ONNLCR		/* fin de ligne = LF seulement sous cet O.S. */
#define LGEXACTE 1	/* fichiers accessibles a l'octet pres */

#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <setjmp.h>
#include <time.h>

#define Topen(f)  open(f,(SWORD) (O_CREAT | O_RDWR),(int) (S_IREAD | S_IWRITE))
#define XRDopen(f) XTopen(f, (int) O_RDONLY, S_IREAD)
#define Xopen(f)  open(f,(SWORD) O_RDWR,(SWORD) (S_IREAD | S_IWRITE))
#define Xcreat(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR),(SWORD) 0666)
#define Xcreat_mode(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR), buf.st_mode)

/* #define Xunlink(n) { printf("\r\nUNLINK:%s",n); getch(); unlink(n); } */
#define Xunlink(n) unlink(n)

/*LINTLIBRARY*/		/* LINT: laisser tomber les fonctions de la	*/
			/* bibliotheque non utilisees par le programme  */

#endif

#ifdef vms
#define MOINS_UN 0xffff
#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define LGMXNOM 80	/* lg max d'un nom de fichier */
#define DELIMREP ']'

#define EXTDEST	"$1"   /* extension fichier destination */
#define EXTRET	"$2"   /* extension fichier retour */

#undef  ONNLCR		/* fin de ligne = LF seulement sous cet O.S. */
#define LGEXACTE 1	/* fichiers accessibles a l'octet pres */
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <file.h>
#include <setjmp.h>
#include <unixio.h>
#include <stsdef.h>
#include <time.h>

#ifdef old
#define Topen(f) XTopen(f,(SWORD) (O_CREAT | O_RDWR), 0, "rfm=var" , "shr=nil" )
/* uniquement pour le fichier source */
/* pour ne pas changer la date lors de la sortie par q */
#define XRDopen(f) XTopen(f, (SWORD) O_RDWR, 1)
#define Xopen(f) XTopen(f,(SWORD) O_RDWR, 0, "rfm=var", "shr=nil" )
#define Xcreat(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR), 0, "rfm=var" , "shr=nil" )
#define Xcreat_mode(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY), 0, "rfm=var" , "shr=nil")
#else
#define Topen(f) XTopen(f,(SWORD) (O_CREAT | O_RDWR), 0)
/* uniquement pour le fichier source */
/* pour ne pas changer la date lors de la sortie par q */
#define XRDopen(f) XTopen(f, (SWORD) O_RDWR, 1)
#define Xopen(f) XTopen(f,(SWORD) O_RDWR, 0)
#define Xcreat(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR), 0)
#define Xcreat_mode(f) XTopen(f,(SWORD) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY), 0)

#endif
#define Xunlink(n) delete(n)

#define LGREP 80
#endif

#ifdef vms
static int VAL_RET = 1;
#else
static int VAL_RET = 0;
#endif


/* 	Declaration des extentions */
/*	-------------------------- */

#define LGEXT 5

#ifndef integre
static BYTE EXTS[LGEXT];
static BYTE EXTE[LGEXT];
static BYTE EXTSAV[LGEXT];
#else
extern BYTE EXTS[LGEXT];
extern BYTE EXTE[LGEXT];
extern BYTE EXTSAV[LGEXT];
#endif

/*		Definition du trait 					*/
/*		--------------------					*/

#ifdef vms
static SWORD TRAIT = 0x00BE;
#else
static SWORD TRAIT = 0x00C4;
#endif

/*		definition des fonctions standards utilisees		*/
/*		--------------------------------------------		*/
/*		Rem: ces redefinitions sont faites pour faciliter	*/
/*		un portage dans un contexte different, cependant,	*/
/*		printf et fprintf sont supposees "standard 100%".	*/
/*		ainsi que tous les 'is...(i)' (classification CTYPE)	*/

#ifdef ver14
#define Xmemento(p) Memento(p)
#else
#define Xmemento(p) mememto()
#endif

#ifdef ver14
#ifndef unix
#define Xfn_parser(s,d,m) fn_parser(s,d,m | 128) /* Upper case result please */
#else
#define Xfn_parser(s,d,m) fn_parser(s,d,m)
#endif
#endif

#ifndef unix
#define Xaccess(p,m) access((char *) p, (int) m)
#else
#ifdef vms
#define Xaccess(p,m) vms$access(f,0)
#else
#define Xaccess(p,m) Access(p,4,m) 
#endif
#endif

#ifndef	UNIX
/* SWORD nballoc; */
#define Xfree(p) free((BYTE *) p)
#define Xmalloc(n) malloc( n )
void XXfree(BYTE *);
void * XXmalloc(int);
#endif

#define Xstrcat(s,p) strcat( (char *) s, (char *) p)
#define Xstrchr(s,c) strchr((char *) s, (char) c)
#define Xstrrchr(s,c) strchr((char *) s, (char) c)
#define Xstrcmp(s,p) strcmp( (char *) s,  (char *) p)
#define Xstrncmp(s,p,n) strncmp( (char *) s, (char *) p, (int) n)
#define Xstrcpy(d,s) strcpy( (char *) d, (char * ) s)
#define Xstrlen(s) strlen( (char *) s)



/* XTopen(s,m,t) est une fonction qui traite l'acces exclusif */
#ifdef LINT_ARGS
/*global*/ SWORD XTopen(BYTE XPTR ,SWORD , SWORD);
FILE XPTR XAfopen(BYTE XPTR, BYTE XPTR);
#else
/*global*/ int XTopen();
FILE XPTR XAfopen();
#endif
#define Xclose(f) close( f)
#define Xwrite(f,b,l) write(f,b,l)
#define Xread(f,b,l) read((int) f, (char *) b, (int) l)
#define Xseek(f,d) lseek(f,d,0)
#define Xfseek(f,o,w) fseek(f,o,w)
#define Xfopen(s,m) XAfopen((BYTE XPTR) s, (BYTE XPTR) m)
#define Xfeof(f) feof(f)
#define Xfclose(f) fclose((FILE *) f)
#define Xfputs(l,f) fputs((char *) l, (FILE *) f)
#define Xfputc(c,f) fputc((char) c, (FILE *) f)
#define XXfgets(s,n,f) fgets((char *) s, (int) n, (FILE *) f)
#define Xfgetc(c) fgetc((char) c)
#define Xsetjmp(e) setjmp(e)
#define Xlongjmp(e,v) longjmp(e,v)

#ifdef prologue
#define Xgetdd(n,s) _ngf_getdd(n,s)
#define Xputdd(n,s) _ngf_putdd(n,s)
#endif

/* #define x_cprintf(p) XX_cprintf(p) */


/*		test d'egalite entre deux chaines		*/
/*		---------------------------------		*/

#define strEq(s1,s2) (Xstrcmp(s1,s2) == 0)

/*	 	definition generique d'un pointeur NULL 	*/
/*		---------------------------------------		*/

#define GenericNULL(t) (t *) NULL

/*		definition du type logique/BOOLEEN		*/
/*		----------------------------------		*/

typedef unsigned char BOOL;

#define TRUE 1
#define FALSE 0

/*		gravite des erreurs			*/
/*		-------------------			*/

#define USUAL	'1'
#define FATALE	'2'

/*		parametres au niveau global		 */
/*		---------------------------		 */

#define MXSEG 65536L	/* Taille max d'un bloc de donnees = 64 K octets */
#define LGBLOC 256	/* Facteur de 'sectorisation a la mode Amenesik / Sologic'*/

#define EOSTR '\0'            /* caractere terminateur de chaine C */
#define EOTXT '\x1A'		/* caractere fin de fichier de texte */

#define CR	'\r'
#define NL	'\n'
#define TABUL	'\t'
#define LIMLIG 	1		/* Marque de debut et de fin de ligne */

/*	description d'un fichier source		*/
/*	-------------------------------		*/

#ifndef vms
#define LGBUF	4096
#else 
#define LGBUF	12288
#endif

#define TFILE struct _tf
TFILE {
	SWORD	nl;		/* numero logique systeme */
	BYTE	buf[LGBUF+1];	/* buffer general de traitement */
	BYTE	*pbuf;		/* pointeur courant */
	BYTE	*fbuf;		/* fin du buffer courant */
	LONG	curofst;	/* position courante */

	LONG	nblgn;		/* numero / nombre de lignes */



	BOOL	Feof;		/* fin de fichier */
};

#ifdef ver21
#define StrCor struct _MTCO
StrCor {
	BYTE FPTR lgn;
	StrCor FPTR suiv;
};
#endif
#define FNIL ((StrCor FPTR) 0)

