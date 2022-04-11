/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Editeur de liens A.B.A.L.
 *	Fichier : LKDEF.H
 *	Version : 2.2b
 *	Date    : 01/06/93
 *	Systeme : Tous
 *
 *	Gestion Fichier des acces de fichier
 *
 *	[Noyau TCode- Gestion de table]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	14/12/93 : Modification de la constane LGIDENT de 16 a 17 
 *		+1 pour EOSTR pour les noms de 16 de long
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef __LKDEF_H__
#define __LKDEF_H__

/*	La definition de l'environnement utilise doit etre faite
 *		lors de l'appel au compilateur
 */



/* #define LINT_ARGS */
/*JPH #define __PORTABLE__ */
/* #define __TRACE  */
#include "wabaldef.h"
#include "pubslist.h"
#include "pubsnode.h"

typedef unsigned long int ULONG;

/*JPH changed typedef void  VOID;*/
#define VOID void

#define UN_MEGA 0xfffff 
#define UN_PARA 0x10

#ifdef vms
	#define GLOBAL noshare
#else
	#define GLOBAL
#endif
#define PUB

/*	Decomposition d'un WORD en deux octets : le 1er et le second	   */
/*	sans tenir compte de la notation interne du processeur		   */

#define FIRST_BYTE(bin)		((bin >> 8) & 0x00FF)
#define SECOND_BYTE(bin)	(bin & 0x00FF)

#ifndef __ABALDEF_H__  // #SP: 26/01/2000
#define MOINS_UN 0xffff
#endif
#define MOINS_DEUX 0xfffe

#ifndef VERSION_XX
#define TEST_STOP if ( x_kbhit() ) if (x_getch() == 0x03 ) \
				if (EcranMsgMore() == MOINS_UN ) THROW( MessageStop );
#else
#define TEST_STOP
#endif


/* TYPE LONGUEUR DE TYPE du Traducteur */
#define TBIN1 		0
#define TBIN2 		1
#define TBCD 		2
#define TSTR 		3

#define LGSTDPTR 	5
#define MALL		0x61	/* Reloc des externs field non definis */
#define MINSERT	0x4d	/* Reloc des field=m en Insertion    */
#define MFIN		0x6d	/* Reloc des field=m en fin de table */
#define MRECOUVRE	0xcd	/* Reloc des field=m en recouvrement */
#define EINSERT	0x45	/* Reloc des field=e en Insertion    */
#define EFIN		0x65	/* Reloc des field=e en fin de table */
#define ERECOUVRE	0xc5	/* Reloc des field=e en recouvrement */

/* Mask pour determiner le nombre d'argument */
#define MASK_NB_ARGS 0x7ff

/*	POINTEUR	*/
/*	--------	*/

/*JPH replace 
#define XPTR *
in code ::
XPTR ==> XPTR *
*/
// #SP: 26/01/2000 (begin)
// XPTR defined resently as * and now it must be empty cause everywhere used BYTE XPTR *
// XPTR is user for _far, _near and so on.
#ifdef XPTR 
#undef XPTR
#endif
// #SP: 26/01/2000 (end)
#define XPTR 

#define TABUL 0x07	/* Definition de la tabulation */

/*      Hash Liste */

#define HTV 36
#define HLV 19

/* 	Type d'access au fichier */

#define LECTURE 	0
#define ECRITURE 	1
#define RESULTAT	2
#define MODULE		3

/* 	Appel au fichier */

#define Gbyte()		gbyte(pt)
#define Gbin()		gbin(pt)

/* 	Test si WORD "negatif" */

#define negbin(bin)	(bin > 32767)
#define inttocar(n)	(BYTE) (n+'0')

/* 	Extension des fichiers temporaires */

#define EXTCST	"cst"	/* Table des constantes */
#define EXTTVG	"tvg"	/* Table des variables globale */
#define EXTCOD	"cod"	/* Tampon pour le code  + vl des procedures */
#define EXTPRO	"pro"	/* Table des procedures */
#define EXTNOV	"nov"	/* Table des nom de variables globales */
#define EXTNOP	"nop"	/* Table des noms de procedures */
#define EXTMP	"tmp"	/* Extension temporaire pour un at */


#define EXTENSION_SEG		"seg"		/* Table des segments */
#define EXTENSION_DBG_ALD  "dbg"		/* fichier de debug */
#define EXTENSION_DBO_ALD  "dbo"		/* fichier debug des modules */

#define EXTENSION_DBG_WALD  "wdg"   /* fichier de debug */
#define EXTENSION_DBO_WALD  "wdo"   /* fichier debug des modules */



/*		----------------- Limites -----------------		*/


#define MXINT			65536L			/* Taille max d'un bloc de donnees = 64 K octets */
#define MAX_NB_SEG 	0x800	/* Nombre Maximum de segment */

#define LGNOMPRG		16		/* longueur max d'un nom de programme	*/
#define LGIDENT		17		/* long max d'un ident au sens ABAL 16 + 1 (EOSTR) */


#define LGBUF 4096
#define LGNOMBIB 64			/* ? nom bibliotheque ? */

#ifdef prologue 
	#define NOMLST 22
#else
	#define NOMLST 80
#endif

#define LGREP 	256
#ifdef prologue
	#define LGMXNOM 63		/* lg max d'un nom de fichier */
	#define LGBLOC	256		/* avec des blocs de 256 octets */
#else
#ifdef msdos
	#ifdef __WALD__
		#define LGMXNOM LGREP	/* lg max d'un nom de fichier */
	#else
		#define LGMXNOM 63		/* lg max d'un nom de fichier */
	#endif
	#define LGBLOC	256		/* avec des blocs de 256 octets */
#endif
#endif
#ifdef unix
	#define LGMXNOM 63
	#define LGBLOC	256		/* avec des blocs de 256 octets */
#endif
#ifdef vms
	#define LGMXNOM 80		/* lg max d'un nom de fichier */
	#define LGBLOC	256		/* avec des blocs de 256 octets */
#endif

#define NIL 0


/*	Parametres dependants du systeme hote 		*/
/*	-------------------------------------		*/


#ifdef prologue
	#define SEPVOL "."
	#define DREP "\\"
	#define DELIMREP '\\'  /* delimiteur entre repertoire et nom de fichier */
#endif

#ifdef msdos
	#define SEPVOL ":"
	#define DREP "\\"
	#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
	#define DELIMREP '\\'
#endif

#ifdef unix
	#define SEPVOL ""
	#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
	#define DREP "/"  /* delimiteur entre repertoire et nom de fichier */
	#define DELIMREP '/'
#endif

#ifdef vms
	#define SEPVOL ":"
	#define DREP   ""
	#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
	#define DELIMREP ']'  /* delimiteur entre repertoire et nom de fichier */
#endif


#ifdef prologue
	#define SEPTYP   '-'  /* separateur entre nom et extension d'un fichier */
	#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
	#define EXTENSION_O		"O"	/* extension par defaut fichier a linker */
	#define EXTENSION_AT		"AT"    /* extension par defaut fichier traduit */
	#define EXTENSION_TEMP	"OT"    /* extension par fichier temporaire */

	#define LINT_ARGS

	#define EOSTR '\0'            /* caractere terminateur de chaine C */
	#define EOTXT '\x1A'		/* caractere fin de fichier de texte */

	#include <stdio.h>
	#include <ctype.h>
	#include <prl.h>

	#include <stdlib.h>
	#include <string.h>
	#include <malloc.h>
	#include <fcntl.h>
	#include <setjmp.h>
	#include <io.h>


	#define XT_ERR -1		/* erreur sur ouverture */
	#define XT_OK  LGBLOC		/* compte rendu OK sur lecture/ecriture */

	#define XTWopen(f) FileXopen((BYTE XPTR *) f,(WORD) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY), (WORD) O_LOCK)
	#define XTRopen(f) FileXopen((BYTE XPTR *) f,(WORD) (O_RDONLY | O_BINARY),(WORD) O_LOCK)

	#define Topen(f,d,a) open((char *) f, (int) d, (int) a)

	#define XTclose(f) Xclose(f)
	#define XTwrite(f,b,l) Xwrite(f,b,l)
	#define XTread(f,b,l) Xread(f,b,l)
	#define XTseek(f,d) Xlseek(f,d,0)

	#define Xunlink(f) unlink((char *) f)

#endif


#ifdef msdos

	#define SEPTYP   '.'		/* separateur entre nom et extension d'un fichier */
	#define DELIMOPT '/'		/* delimiteur des options dans ligne de commande */

	#define EXTENSION_O		"o"	/* extension par defaut fichier a linker */
	#define EXTENSION_AT		"at"  /* extension par defaut fichier traduit */
	#define EXTENSION_TEMP	"ot"  /* extension par fichier temporaire */

	#define EOSTR '\0'            /* caractere terminateur de chaine C */
	#define EOTXT '\x1A'				/* caractere fin de fichier de texte */

	#define LINT_ARGS

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
	#include <setjmp.h>
	#include <sys\types.h>
	#include <sys\stat.h>
	#include <io.h>


	#define XT_ERR -1		/* erreur sur ouverture */
	#define XT_OK  LGBLOC		/* compte rendu OK sur lecture/ecriture */

	#define XTWopen(f) FileXopen((BYTE XPTR *) f, (WORD) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY), (WORD) (S_IREAD | S_IWRITE))
	#define XTRopen(f) FileXopen((BYTE XPTR *) f, (WORD) (O_RDONLY | O_BINARY), (WORD) 0)
	#define XTclose(f) Xclose(f)
	#define XTwrite(f,b,l) Xwrite(f,b,l)
	#define XTread(f,b,l) Xread(f,b,l)
	#define XTseek(f,d) Xlseek(f,d,0)

	#define Xunlink(f) unlink((char *) f)

#endif


#ifdef unix
	#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
	#define DELIMOPT '-'  /* delimiteur des options dans ligne de commande */
	#define EXTENSION_O	"o"	/* extension par defaut fichier a linker */
	#define EXTENSION_AT	"at"     /* extension par defaut fichier traduit */
	#define EXTENSION_TEMP	"ot"    /* extension par fichier temporaire */

	#define EOSTR '\0'            /* caractere terminateur de chaine C */
	#define EOTXT '\n'		/* caractere fin de fichier de texte */

	#include <stdio.h>
	#include <ctype.h>
	#include <string.h>
	#include <fcntl.h>
	#include <setjmp.h>
	#include <errno.h>
	#include <sys/types.h>
	#include <sys/stat.h>


	#define XT_ERR NULL	/* erreur sur ouverture */
	#define XT_OK  LGBLOC	/* compte rendu OK sur lecture/ecriture */

	#define XTWopen(f) FileXopen(f,(int) (O_CREAT | O_TRUNC | O_RDWR),(int) (S_IREAD | S_IWRITE))
	#define XTRopen(f) FileXopen(f,(int) (O_RDONLY),0)
	#define XTclose(f) Xclose(f)
	#define XTwrite(f,b,l) Xwrite(f,b,l)
	#define XTread(f,b,l) Xread(f,b,l)
	#define XTseek(f,d) Xlseek(f,d,0)

	#define Xcreat(f) FileOpen(f,(int) (O_CREAT | O_TRUNC | O_RDWR),(int) (S_IREAD | S_IWRITE))
	#define Xcreat_mode(f) FileOpen(f,(int) (O_CREAT | O_TRUNC | O_RDWR), buf.st_mode)
	/*
	extern char *malloc();
	*/
	/*LINTLIBRARY*/		/* LINT: laisser tomber les fonctions de la	*/
				/* bibliotheque non utilisees par le programme  */

	#define Xunlink(f) unlink(f)

#endif


#ifdef vms
	/*
		#define DELIMREP "]"
		#define DELIMREP1 ":"
		#define DELIMREP2 ">"
	*/
	#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
	#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
	#define EXTENSION_O	"O"	/* extension par defaut fichier a linker */
	#define EXTENSION_AT	"AT"     /* extension par defaut fichier traduit */
	#define EXTENSION_TEMP	"OT"    /* extension par fichier temporaire */

	#define EOSTR '\0'            /* caractere terminateur de chaine C */
	#define EOTXT '\x1A'		/* caractere fin de fichier de texte */

	#include <stdio.h>
	#include <ctype.h>
	#include <string.h>
	#include <file.h>
	#include <setjmp.h>
	#include <unixio.h>
	#include <stsdef.h>


	#define XT_ERR -1		/* erreur sur ouverture */
	#define XT_OK  LGBLOC		/* compte rendu OK sur lecture/ecriture */

	#define XTWopen(f) open(f,(int) (O_CREAT | O_RDWR), 0, "ctx=rec","rfm=fix","mrs=256","shr=nil")
	#define XTRopen(f) open(f,(int) O_RDONLY, 0)
	#define XTclose(f) Xclose(f)
	#define XTwrite(f,b,l) Xwrite(f,b,l)
	#define XTread(f,b,l) Xread(f,b,l)
	#define XTseek(f,d) Xlseek(f,d,0)

	#define Xunlink(f) delete(f)

#endif

#ifdef vms
	static int VAL_RET = 	1;
#else
	static int VAL_RET=0;
#endif

/*		definition des fonctions standards utilisees		*/
/*		--------------------------------------------		*/
/*		Rem: ces redefinitions sont faites pour faciliter	*/
/*		un portage dans un contexte different, cependant,	*/
/*		printf et fprintf sont supposees "standard 100%".	*/
/*		ainsi que tous les 'is...(i)' (classification CTYPE)	*/
/*		     De plus, les fonctions utilisees pour l'acces au	*/
/*		fichier traduit dependent du systeme hote.		*/

#define Xexit(n) exit(n)

#ifdef __TRACE_ERR
	FILE * ftrace;
	BOOL   arg_trace;

	#ifdef __TRACE
		#define TRACE {if (arg_trace == TRUE) fprintf(ftrace,"%s %d 1 %s \n", __FILE__, __LINE__, "trace");};
	#endif

#else
	#define TRACE
#endif

#ifdef __MALLOC__

	#undef Xmalloc
	#undef Xfree

	#include "lkdebug.he"
	#define Xmalloc(n) dbgalloc("",n)
	#define Xfree(p) dbgfree((VOID *) p)

#endif /* __MALLOC__ */


/*
#define Xsetjmp(k) setjmp(k)
#define Xlongjmp(k,r) longjmp(k,r)
*/

#ifdef unix
	#define Xaccess(p,m) Access(p,0,m)
#else
	#ifdef vms
		#define Xaccess(p,m) vms$access(p,0)
	#else
		#define Xaccess(p,m) access((char *) p, (int) m)
	#endif
#endif

#define Xmemcpy(d,s,lg) memcpy((char *) d, (char *) s, (int) lg)

#define Init_bloc(pt) memset((char *) pt,(char) 0xff, (int) LGBLOC)

#define Xstrlen(s) (PRECOND( s != 0),strlen((char *) s))
#define Xstrcat(s,p) ( (PRECOND( s != 0), PRECOND( p != 0)),strcat((char *) s, (char *) p))
#define Xstrchr(s,c) strchr((char *) s, (char) c)
#define Xstrcmp(s,p) (PRECOND( s != 0), PRECOND( p != 0 ), strcmp((char *) s,(char *) p))
#define Xstrcpy(d,s) (PRECOND( d != 0), PRECOND( s != 0), strcpy((char *) d, (char *) s))
#define Xstrrchr(s,c) (BYTE XPTR *) strrchr((char *) s, (char) c)
#define Xclose(f) close((int) f)
#define Xwrite(f,b,l) write((int) f, (char *) b, (int) l)
#define Xread(f,b,l) read((int) f, (char *) b, (int) l)
#define Xlseek(f,d,o) lseek((int) f, (long) d, (int) o)

#ifndef unix
	#define Xfn_parser(s,d,m) fn_parser(s,d,m | 128) /* Lower case result please */
#else
	#define Xfn_parser(s,d,m) fn_parser(s,d,m)
#endif


#define Xfopen(s,m) FileXfopen(s)
#define Xfeof(f) feof((FILE *) f)
#define Xfclose(f) fclose((FILE *) f)
#define Xfputs(l,f) fputs((char *) l, (FILE *) f)
#define Xfputc(c,f) fputc((char) c, (FILE *) f)
#define Xfgets(s,n,f) fgets((char *) s, (int) n, (FILE *) f)
#define Xfgetc(c) fgetc((char) c)

/*		test d'egalite entre deux chaines		*/
/*		---------------------------------		*/

#define strEq(s1,s2) (Xstrcmp(s1,s2) == 0)

/*	 	definition generique d'un pointeur NULL 	*/
/*		---------------------------------------		*/

#define GenericNULL(t) (t *) NULL
#define GFN(t) (t FAR *) NULL
#define GN(t)  (t *) NULL

/*		definition du type logique/BOOLEEN		*/
/*		----------------------------------		*/


#define TRUE 1
#define FALSE 0


/*		----------------- Macro -----------------		*/

/* quelques Macro */
#define INIT_SLIST(p)	p = (C_SLIST FAR *) 0
#define INIT_SNODE(p)   p = (C_SNODE FAR *) 0
#define INIT_ALLOC(p,t) p = (t *) 0;

#define GET_ALLOC(p, t, l) p = (t *) Xmalloc( l );\
				if ( p == (t *) 0) {THROW(ErreurMoteur02);}

#define GET_CALLOC(p, t, l) p = (t *) Xmalloc( l );\
				if ( p == (t *) 0) {THROW(ErreurMoteur02);} \
				memset( p, 0, l);

#define ALLOC_TAMPON(p, l) GET_CALLOC( p , BYTE , l)
#define ALLOC_STRUCT(p, s) GET_ALLOC( p, s, sizeof( s ))

#define ALLOC_SLIST( p ) p = SlistCreate();\
			if ( p == (C_SLIST FAR *) 0 ) { THROW(ErreurMoteur02); }

#define ALLOC_SNODE( p ) p = SnodeCreate();\
			if ( p == (C_SNODE FAR *) 0 ) { THROW(ErreurMoteur02); }

#define FREE_ALLOC(p, t) Xfree(p)

#define _LKDEF_DEF

#else 	/* _LKDEF_H */
#endif 	/* _LKDEF_H */



