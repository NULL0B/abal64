/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : TR.H
 *      Version : 2.2b
 *      Date    : 25/11/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions globales du traducteur]
 *
 *	------------ 2.2a -------------------------------------------------
 * 17/02/97 : Debut revision 2.2
 * 17/02/97 : Type compose (structure)
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef _TR_H
#define _TR_H

/* La definition de la version 1.5 inclue la version 1.4, etc ... */

#define ver14
#define ver13
#define ver12


/* Definitions des positions lignes et colonnes des messages
 * de l'ensemble integre 1.4, ainsi que des couleurs.
 */

/* Definition des lignes */
#define IL_0    7               /* cadre */
#define IL_1    9               /* source initial */
#define IL_2    10              /* fichier en cours */
#define IL_3    12              /* nb de lignes */
#define IL_4    13              /* nb d'erreurs */
#define IL_5    14              /* nb de warnings */
#define IL_6    16              /* autres messages */

/* Definition des colonnes */
#define IC_0    11              /* a gauche apres le cadre */
#define IC_1    33              /* lignes, erreurs, warnings */
#define IC_2    44              /* barre verticale centrale */
#define IC_3    49              /* */
#define IC_4    59              /* tailles */
#define IC_5    72              /* bord droit du cadre */

/* Definition des couleurs */
#define C_FOND  4               /* bleu */
#define C_CAR   11              /* jaune */
#define CI_FOND 1               /* rouge */
#define CI_CAR  15              /* blanc */

/*      La definition de l'environnement utilise doit etre faite
 *              lors de l'appel au compilateur
 *
 *      En principe, toutes les parties "sensibles" aux portages
 *      sont definies dans ce fichier ou dans le module TR.C
 *      --------------------------------------------------------        */

#ifdef	VERSION_XX
typedef unsigned short  int EXAWORD;     /* type binaire sur 2 octets */
typedef unsigned short  int BINAIRE;     /* type binaire sur 2 octets */
#else
typedef unsigned short  int EXAWORD;     /* type binaire sur 2 octets */
typedef unsigned short int BINAIRE;     /* type binaire sur 2 octets */
#endif
typedef unsigned char BYTE;             /* type binaire sur 1 octet */

/*      Decomposition d'un BINAIRE en deux octets : le 1er et le second    */
/*      sans tenir compte de la notation interne du processeur             */

#define FIRST_BYTE(bin)         (BYTE) ((bin >> 8) & 0x00FF)
#define SECOND_BYTE(bin)        (BYTE) (bin & 0x00FF)

/*      Decomposition d'un LONG en deux octets : le 1er et le second    */
/*      sans tenir compte de la notation interne du processeur             */

#define LFIRST_BYTE(lg)         (BYTE) ((lg >> 24) & 0x000000FF)
#define LSECOND_BYTE(lg)         (BYTE) ((lg >> 16) & 0x000000FF)
#define LTHIRD_BYTE(lg)         (BYTE) ((lg >> 8) & 0x000000FF)
#define LFOURTH_BYTE(lg)        (BYTE) (lg & 0x000000FF)

/*      Test si BINAIRE "negatif" */

#define negbin(bin)     (bin > 32767)

#ifdef	VERSION_XX
#define	islocal(vid)	(vid & ISLOCAL)
#else
#define	islocal(vid)	negbin(vid)
#endif


#define LGNOMPRG 16     /* longueur max d'un nom de programme   */


/*      Conversions dependantes du jeu de caracteres interne    */
/*      ----------------------------------------------------    */

#define cartohex(c) ((c >= 'A') ? (c - '7') : (c - '0'))
#define cartoint(c) (c - '0')
#define inttocar(n) (unsigned char) (n + '0')


/********************
 ***** PROLOGUE *****
 ********************/

#ifdef prologue

#define SEPTYP   '-'    /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'    /* delimiteur des options dans ligne de commande */
#define DELIMREP '\\'   /* delimiteur de repertoire */
#define LGMXNOM 80      /* lg max d'un nom de fichier */

#define EOSTR '\0'            /* caractere terminateur de chaine C */
#define EOTXT '\x1A'            /* caractere fin de fichier de texte */

#define IPAGE   '\x0C'          /* caractere de saut de page sur imprimante */

#define LINT_ARGS

#include <pstdio.h>
#include <pctype.h>
#include <prldef.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>
#include <psetjmp.h>
#include <time.h>

#include <prl.h>

typedef int T_FILE;             /* fichier traduit = fichier direct */

#define LGBLOC  256             /* avec des blocs de 256 octets */

#define XT_ERR -1               /* erreur sur ouverture */
#define XT_OK  LGBLOC           /* compte rendu OK sur lecture/ecriture */

#define XTopen(f) Xopen(f,(int) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY),(int) (S_IREAD | S_IWRITE))
#define XTPopen(f) Xopen(f,(int) (O_RDONLY | O_BINARY),(int) (S_IREAD))
#define XTclose(f) Xclose(f)
#define XTwrite(f,b,l) Xwrite(f,b,l)
#define XTread(f,b,l) Xread(f,b,l)
#define XTseek(f,d) Xlseek(f,d,0)

#define Xunlink(f) unlink(f)

#define VAL_RET 0

#define Xdate(s) xdate(s) /* strcpy(s,"00/00/00") */
#define Xtime(s) xtime(s) /* strcpy(s,"00:00:00") */

#define Xftell(s) ftell(s)

#endif /* prologue */

/******************
 ***** MS/DOS *****
 ******************/

#ifdef msdos

#ifdef WIN16
#define WIN1632
#endif
#ifdef WIN32
#define WIN1632
#endif

#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define DELIMREP '\\' /* delimiteur de repertoire */
#ifdef WIN32
#define LGMXNOM 270     /* lg max d'un nom de fichier */
#else
#define LGMXNOM 63      /* lg max d'un nom de fichier */
#endif

#define EOSTR '\0'            /* caractere terminateur de chaine C */
#define EOTXT '\x1A'            /* caractere fin de fichier de texte */

#define IPAGE   '\x0C'          /* caractere de saut de page sur imprimante */

#define LINT_ARGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include <io.h>
#include <setjmp.h>
#include <signal.h>
#include <dos.h>
#include <time.h>

typedef int T_FILE;             /* fichier traduit = fichier direct */

#define LGBLOC  256             /* avec des blocs de 256 octets */

#define XT_ERR -1               /* erreur sur ouverture */
#define XT_OK  LGBLOC           /* compte rendu OK sur lecture/ecriture */

#define XTopen(f) Xopen(f,(int) (O_CREAT | O_TRUNC | O_RDWR | O_BINARY),(int) (S_IREAD | S_IWRITE))
#define XTPopen(f) Xopen(f,(int) (O_RDONLY | O_BINARY),(int) (S_IREAD))
#define XTclose(f) Xclose(f)
#define XTwrite(f,b,l) Xwrite(f,b,l)
#define XTread(f,b,l) Xread(f,b,l)
#define XTseek(f,d) Xlseek(f,d,0)

#define Xunlink(f) unlink(f)

#define VAL_RET 0

#define Xdate(s) xdate(s)
#define Xtime(s) xtime(s)

#define Xftell(s) ftell(s)

#endif /* msdos */


/****************
 ***** UNIX *****
 ****************/

#ifdef unix

#define buf_cico        /* affichage ecran bufferise */

#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '-'  /* delimiteur des options dans ligne de commande */
#define DELIMREP '/'  /* delimiteur de repertoire */
#define LGMXNOM 80      /* lg max d'un nom de fichier */

#define EOSTR '\0'            /* caractere terminateur de chaine C */
#define EOTXT '\n'              /* caractere fin de fichier de texte */

#define IPAGE   '\x0C'          /* caractere de saut de page sur imprimante */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>

extern char *malloc();

/*      #include "deffnt.h"     */

typedef FILE * T_FILE;          /* fichier traduit = fichier bufferise */

#define LGBLOC  256             /* avec des blocs de 256 octets */

#define XT_ERR (FILE *) NULL    /* erreur sur ouverture */
#define XT_OK  1                /* compte rendu OK sur lecture/ecriture */

#define XTopen(f) Xfopen(f,"w+")
#define XTPopen(f) Xfopen(f,"r")
#define XTclose(f) Xfclose(f)
#define XTwrite(f,b,l) Xfwrite(b,l,1,f)
#define XTread(f,b,l) Xfread(b,l,1,f)
#define XTseek(f,d) Xfseek(f,d,0)

#define Xunlink(f) unlink(f)

#define Xdate(s) xdate(s) /* strcpy(s,"00/00/00") */
#define Xtime(s) xtime(s) /* strcpy(s,"00:00:00") */

#define Xftell(s) ftell(s)

/*LINTLIBRARY*/         /* LINT: laisser tomber les fonctions de la     */
                        /* bibliotheque non utilisees par le programme  */

#define VAL_RET 0

#endif /* unix */

/***************
 ***** VMS *****
 ***************/

#ifdef vms

#define buf_cico        /* affichage ecran bufferise */

#define SEPTYP   '.'  /* separateur entre nom et extension d'un fichier */
#define DELIMOPT '/'  /* delimiteur des options dans ligne de commande */
#define DELIMREP ']'  /* delimiteur de repertoire */
#define LGMXNOM 80      /* lg max d'un nom de fichier */

#define EOSTR '\0'            /* caractere terminateur de chaine C */
#define EOTXT '\n'              /* caractere fin de fichier de texte */

#define IPAGE   '\x0C'          /* caractere de saut de page sur imprimante */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <file.h>
#include <unixio.h>
#include <setjmp.h>
#include <stsdef.h>
#include <signal.h>

typedef int T_FILE;             /* fichier traduit = fichier direct */

#define LGBLOC  256             /* avec des blocs de 256 octets */

#define XT_ERR -1               /* erreur sur ouverture */
#define XT_OK  LGBLOC           /* compte rendu OK sur lecture/ecriture */

#define XTopen(f) open(f,(int) (O_CREAT | O_TRUNC | O_RDWR),0,"ctx=rec","rfm=fix","mrs=256","shr=nil")
#define XTPopen(f) open(f,(int) O_RDONLY, 0)
#define XTclose(f) Xclose(f)
#define XTwrite(f,b,l) Xwrite(f,b,l)
#define XTread(f,b,l) Xread(f,b,l)
#define XTseek(f,d) Xlseek(f,d,0)

#define Xunlink(f) delete(f)

#define VAL_RET STS$M_INHIB_MSG

#define Xdate(s) Xstrcpy(s,"00/00/00")
#define Xtime(s) Xstrcpy(s,"00:00:00")

#define Xftell(s) ftell(s)

#endif /* vms */


/*              R.A.Z. des definitions concernant les noms prives
 *              susceptibles d'avoir ete definis par les includes
 *              -------------------------------------------------
 */
#undef NIL
#undef TRUE
#undef FALSE
#undef WARNING
#undef USUAL
#undef ABORT
#undef BELL
#undef BREAK
#undef CLEAR
#undef ERROR
#undef HOME
#undef ON
#undef READ
#undef TAB
#undef WAIT
#undef WRITE
#undef ILLEGAL

/*              definition des fonctions standards utilisees            */
/*              --------------------------------------------            */
/*              Rem: ces redefinitions sont faites pour faciliter       */
/*              un portage dans un contexte different, cependant,       */
/*              printf et fprintf sont supposees "standard 100%".       */
/*              ainsi que tous les 'is...(i)' (classification CTYPE)    */
/*                   De plus, les fonctions utilisees pour l'acces au   */
/*              fichier traduit dependent du systeme hote.              */

#define Xfclose(f) fclose(f)

#ifdef	unix
#define Xfgets(s,n,f) unixfgets(s,n,f)
#define Xfeof(f) unixfeof(f)
#else
#define Xfgets(s,n,f) fgets(s,n,f)
#define Xfeof(f) feof(f)
#endif

/* Xfopen(n,t) et XDfopen sont des fonctions qui traitent
   l'acces exclusif (voir tr.c) */


#ifdef LINT_ARGS
FILE *Xfopen(char *,char *);
FILE *XDfopen(char *,char *);
#else /* ! LINT_ARGS */
FILE *Xfopen();
FILE *XDfopen();
#endif /* LINT_ARGS */

#define Xfputc(c,f) fputc(c,f)
#define Xfputs(s,f) fputs(s,f)
#define Xfread(b,s,c,f) fread(b,s,c,f)
#define Xfseek(f,d,o) fseek(f,d,o)
#define Xfwrite(b,s,c,f) fwrite(b,s,c,f)

#define Xgetchar() getchar()

#ifdef ATR_DEBUG

#include "atrdebug.he"

#define Xmalloc(n) dbgalloc("",n)
#define XNmalloc(s,n) dbgalloc(s,n)
#define Xfree(p) dbgfree(p)

#else
#define Xmalloc(n) malloc(n)
#define XNmalloc(s,n) malloc(n)
#define Xfree(p) free(p)
#endif /* ATR_DEBUG */
 
#define Xstrcat(s,p) strcat(s,p)
#define Xstrchr(s,c) strchr(s,c)
#define Xstrcmp(s,p) strcmp(s,p)
#define Xstrcpy(d,s) strcpy(d,s)
#define Xstrncpy(d,s,n) strncpy(d,s,n)
#define Xstrlen(s) strlen(s)
#define Xstrrchr(s,c) strrchr(s,c)

/* Xopen(s,m,t) est une fonction qui traite l'acces exclusif (voir tr.c) */

#ifdef LINT_ARGS
int Xopen(char *,int,int);
#else /* ! LINT_ARGS */
int Xopen();
#endif /* LINT_ARGS */

#define Xclose(f) close(f)
#define Xwrite(f,b,l) write(f,b,l)
#define Xread(f,b,l) read(f,b,l)
#define Xlseek(f,d,o) lseek(f,d,o)

#define Xsetjmp(e) setjmp(e)
#define Xlongjmp(e,v) longjmp(e,v)

/*              test d'egalite entre deux chaines               */
/*              ---------------------------------               */

#define strEq(s1,s2) (Xstrcmp(s1,s2) == 0)

/*              definition generique d'un pointeur NULL         */
/*              ---------------------------------------         */

#define GenericNULL(t) (t *) NULL

/*              definition du type logique/BOOLEEN              */
/*              ----------------------------------              */

typedef unsigned char BOOL;

#define NIL ( (BINAIRE) 65535 )
#define TRUE 1
#define FALSE 0

/*              gravite des erreurs             */
/*              -------------------             */

#define WARNING '0'
#define USUAL   '1'
#define FATALE  '2'

/*              parametres au niveau global              */
/*              ---------------------------              */

#define LGIDENT 17      /* lg max d'un ident en comptant le terminateur */
#define LGBCD  12       /* lg max d'un nombre BCD en octets */
#define LGSTR  32767    /* lg max d'une chaine */
#define MXNLOG 64       /* nb max de numeros logiques de fichiers */
#define MXARGS 20       /* nb max d'arguments pour une procedure */

#ifdef	VERSION_XX
#define MAXINCL 256     /* nb max d'inclusion des fichiers sources */
#define MAXSYMB 500     /* nb max de symboles de traduction conditionnelle */
#define LGLIGNE 1024    /* longueur max d'une ligne dans un fichier source */
#else
#define MAXINCL 5       /* nb max d'inclusion des fichiers sources */
#define MAXSYMB 500     /* nb max de symboles de traduction conditionnelle */
#define LGLIGNE (320+1) /* longueur max d'une ligne dans un fichier source */
#endif

#define LGCSTR  255     /* longueur max d'une constante chaine */
#define MXDGCHEX 4      /* nb max digits pour une constante hexadecimale */

#define LGSTDBCD  8     /* lg par defaut d'un BCD */
#define LGSTDSTR  15    /* lg par defaut d'une chaine */

#define typ_in_desc 0x07 /* masque pour isoler le type dans un descripteur */
#define is_typ_ptr 0x90 /* masque pour savoir si un descripteur est un pointeur */

#define TBIN1     0     /* code du type '#' */
#define TBIN2     1     /* code du type '%' */
#define TBIN      (TBIN1 | TBIN2)       /* et type binaire en general */
#define TBCD      2     /* code du type BCD */
#define TSTR      3     /* code du type '$' */

#define TPTR	  8		/* valeur minimal du type pointeur : 8,9,10,11 */
#define TLIKE     4     /* code du type 'LIKE' */
#define LGSTDPTR  5     /* longueur du type PTR */

#define typ_special 0x80 /* masque pour savoir si type special */
#define msk_ptr 0x4F		/* masque pour ne garder que le modele memoire : Normal, etendu, logique */

#define T_ANY     15    /* n'importe quel type ... */

#define BCD_SEP         0x0A
#define BCD_FIN         0x0F
#define BCD_PLUS        0xC0
#define BCD_MOINS       0xB0

#define MXSEG 65536L    /* Taille max d'un bloc de donnees = 64 K octets */
#define MXEXT 0x0FFFFFFFL  /* Taille max des variables etendues = 2 Goctets */
#define MXEXT14 1048576L  /* Taille max des variables etendues = 1 Moctets */


/*              type special : memoire externe          */
/*              ------------------------------          */

#define MEMEXT  64
#define MEMALL	65
#endif /* _TR_H */

