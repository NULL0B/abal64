/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : TR.C
 *      Version : 2.2b
 *      Date    : 10/08/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Noyau du traducteur]
 *
 */

 /*
 * Mises a jour :
 * ------------
 * 18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 * 27/08/90 : Introduction appel depuis l'ensemble integre 1.4
 * 30/08/90 : Notion de repertoire pour les fichiers include
 * 03/09/90 : Introduction de l'option /b
 * 19/09/90 : Contournement bug bibli C 1.1a / Amenesik / Sologic et lecture de /FF
 *            Idem en ecriture
 * 24/10/90 : Mise en place de l'option /N pour la version 1.4 et la
 *            gestion des codes erreurs en sortie
 * 30/10/90 : Pour la version 1.4, modification de la fermeture de la
 *            traduction
 *            Modification de l'ouverture en mode copie.
 * 31/10/90 : Introduction de l'option /h1
 * 05/11/90 : Suppression de commentaires
 * 07/11/90 : Sous Amenesik / Sologic, EDER(0) en cas d'erreur de traduction
 * 26/11/90 : changement option /c par /f
 * 10/12/90 : option de mise au point de argc et argv
 * 17/12/90 : decalage numero ligne dans fichier liste avec option /x
 * 14/01/91 : levee de l'incompatibilite des options /h et /v
 * 15/01/91 : purge de la ligne source dans fichier liste avant de mettre
 *            a jour la map de mise au point
 * 21/01/91 : fermeture fichier liste en cas d'erreur fatale
 *            parametrage version avec assembleur de T-code
 * 28/01/91 : suppression du fichiers d'erreurs s'il est vide
 * 31/01/91 : adaptations a VMS : pas de delimiteur ajoutee au repertoire
 *            des includes, getnomfic appele par forceext, NomFicDep non
 *            expanse par getnomfic.
 * 20/02/91 : Pas d'embellie du fichier liste si traduction en mode
 *            mise au point.
 * 25/02/91 : Liberation de toute la memoire en fin de traduction
 *            y compris hors de l'integre pour 1.2f / 1.3c
 * 27/03/91 : Evite l'effacement d'ecran par envoi d'une sequence
 *            d'initialisation au terminal sur initerm/finterm sous unix
 * 29/03/91 : Correction sur amelioration du 27/03/91
 * 26/04/91 : Codes de retour VMS mis en accord avec AGF
 *            Insertion des fgets et fputs internes pour contourner
 *            un bug bib C 1.1a et 2.1b sous Amenesik / Sologic
 * ---------- Sortie 1.2f / 1.3c / 1.4a ---------------------------------
 * 12/06/91 : Ajout d'une compilation conditionnelle AGF pour que
 *            l'option /o n'active pas automatiquement l'option /w
 * 19/08/91 : Correction bug repertoire include mnemonique sous-repertoire
 *            sous Amenesik / Sologic
 * 21/08/91 : Introduction de l'option /bc (version 1.5)
 * 18/10/91 : Envoi de ATB(0) en sortie si option 'integre'
 * 31/10/91 : Plus de /W quand /O
 * 20/11/91 : Pas de quick help avec option /v
 * ---------- Sortie 1.2g / 1.3d ----------------------------------------
 * 20/01/92 : Pas de purge du fichier liste apres sa fermeture
 * ---------- Sortie 1.4b -----------------------------------------------
 * 04/11/92 : Plus de retour possible vers versions pre-1.4
 * 24/11/92 : Protection forum sur 1.4b
 * 07/12/92 : Fermetures fichiers apres interruption saisie des segments a traduire
 * 09/03/93 : contournement du bug du ftell sous prologue par fseek lors du fopen
 * 06/09/93 : Erreur Tardive dans finsymb, fingest, etc... 
 * ------------ 2.1d -------------------------------------------------
 * 22/11/95 : version dediee 2.1
 * 10/08/96 : adaptations Windows
 * 12/03/97 : BSA
 * ------------ 2.2a -------------------------------------------------
 * 23/04/97 : initialisation de la variable globale optimise_tables
 * 16/07/97 : initialisation de la variable globale enhanced_debug
 * 15/09/97 : modification du comportement de l'option /f : la longueur
 *            du fichier de commandes n'est plus limitee
 * 23/09/97 : Ajout de l'option /j : lancement de ATR depuis Idra (June...)
 * 16/07/97 : Rajout de l'information ligne a la place de l offset avec le pragma ENHANCED DEBUG
 * 04/12/97 : option W completee, on peut rajoute un niveau (entre 0 et 9), les messages de 
 *            warnings contiennent un niveau. seuls les warnings au dessous du niveau sont générés.
 * 08/10/99 : (#OK) Bug ATR 42 fixed: "segment 0 absent in program".
 * 27/10/99 : (#OK) Enhancement ATR 9: Option -to, -ta.
 * 09/12/99 : (#OK) Bug ATR 6 fixed. "Type d'operande incorrect".
 * 01/03/00 : (#OK) Bug ATR fixed: Option -f.
 * 05/03/00 : (#SP) Bug with output redirection to the file in ATR for Amenesik / Sologic 
 * 10/05/00 : (#OK) ATR 19: Commentaires multilignes.
 * 09/03/00 : (#OK) Bug ATR 48 fixed: Procedure return code in array variable.
 * 02/04/01 : (#OK) Bug ATR 68 fixed. Label in the beginning of the procedure or segment.
 * 08/10/01 : (#BG) ATR 10: Abandon de la traduction si la cible est ouverte.
 * 14/11/01 : (#BG) Suppression de l'option -h sans objet sous Windows.
 * 18/06/02 : (#OK) Bug ATR 71 fixed. Incorrect format in function PRINT.
 *  ------------ 2.2b -------------------------------------------------
 * 16/12/02 : (#BG) Correction régression qui empéchait de cumuler plusieurs options sous un seul tiret (-mb par ex.).
 */

/* Fichier de definition */
/* --------------------- */

#include "tr.h"
#include "tcode.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"

#include "banner.h"

#define _TRNOY
#include "trnoy.hs"
#include "trnoy.he"

#ifdef prologue
#define __Prl3
#define __APPLICATION
#include "aw_syst.h"
#undef BYTE
#undef LPBYTE
#undef INT
#undef LPSTR
#undef LPINT
#undef LONG
#undef LPLONG
#undef BOOL
#undef UCHAR
#undef UINT
#undef USHORT
#undef ULONG
#endif

#ifdef WIN1632
#ifdef WIN32
BINAIRE GetOriginalHandle(h)
#else
BINAIRE _cdecl GetOriginalHandle(h)
#endif
BINAIRE h;
{ return(0);  }
#endif


#ifdef WIN32
BOOL ctReOpenDiagnostic(int JuneHandle);
#endif


                /*---------------------------------------*
                 *      corps principal du traducteur
                 *---------------------------------------*/


/* #SP: 05/03/00 (begin) */
#ifdef prologue
#include <pstdio.h>
#endif
/* #SP: 05/03/00 (end) */

#ifndef WIN1632
int main(argc,argv)
#else
int majn(argc,argv)
#endif
int argc;
char *argv[];
{                                       /* main */

#ifdef ATR_DEBUG
  dbginit("atrdebug.txt");
#endif /* ATR_DEBUG */

        if (Xsetjmp(Tr_Exit) != 0) {    /* breakpoint pour exit */

                remet_ecran();

#ifdef  unix
                /* Libere les verouillages de fichiers par access */
                PurgeLox();
#endif /* unix */

#ifdef  vms
                /* Convertit le code de retour du traducteur en
                 * code de retour VMS, selon la table :
                 *
                 * Traducteur   VMS             Signification
                 * ----------   ---             -------------
                 *    0          1              Pas d'erreur
                 *    1          2              Erreur usuelle
                 *    2          4              Erreur severe
                 *                              (pas de source/traduit/...)
                 *
                 * A cela, on ajoute STS$M_INHIB_MSG pour inhiber les messages.
                 */
                switch(RetCode) {
                        case 0  : return(1 | VAL_RET);
                        case 1  : return(2 | VAL_RET);
                        default : return(4 | VAL_RET);
                }
#else /* vms */

#ifdef prologue
                _prl_eder(0);           /* Provoque l'arret des ASG */
/* #SP: 05/03/00 (begin) */
            /* If there is a redirection to some file we must flush the last buffer to do that we output 256 EOFs. */
            if (stdout->_file>1){
            int i;
              fputc('\r',stdout); fputc('\n',stdout);
              for (i=0;i<256;i++) fputc(0x1A,stdout);
            }
/* #SP: 05/03/00 (end) */
#endif /* prologue */

                return (RetCode | VAL_RET);
#endif /* vms */
        }
        if (init_trad(argc,argv)) {     /* initialisation generale OK ! */
                parser();               /* analyse syntaxique du source */
                fin();                  /* fin de travail */
        }

        remet_ecran();

#ifdef  unix
        /* Libere les verouillages de fichiers par access */
        PurgeLox();
#endif /* unix */

#ifdef  vms
                /* Convertit l'erreur du traducteur en erreur VMS
                 * cf table de conversion ci-dessus.
                 */
                switch(RetCode) {
                        case 0  : return(1 | VAL_RET);
                        case 1  : return(2 | VAL_RET);
                        default : return(4 | VAL_RET);
                }
#else /* vms */

#ifdef prologue
        if (RetCode != 0)
                _prl_eder(0);           /* Provoque l'arret des ASG */
/* #SP: 05/03/00 (begin) */
            /* If there is a redirection to some file we must flush the last buffer to do that we output 256 EOFs. */
            if (stdout->_file>1){
              int i;
              fputc('\r',stdout); fputc('\n',stdout);
              for (i=0;i<256;i++) fputc(0x1A,stdout);
            }
/* #SP: 05/03/00 (end) */
#endif /* prologue */

#ifdef ATR_DEBUG
    dbgstat();
    dbgfin("atrdebug.txt");
#endif /* ATR_DEBUG */

        return(RetCode | VAL_RET);
#endif /* vms */
}                                       /* main */

                /*-------------------------------------------*
                 *      Fonctions de portage du traducteur   *
                 *-------------------------------------------*/

#ifdef	unix
int	iseof=0;
int    unixfeof(fp)
FILE *	fp;
{
	int	result=iseof;
	iseof=0;
	return( result );
}

char * unixfgets(line, nb, fp)

/*      Lecture d'un caractere dans un fichier bufferise.
 *      NB : Sous prologue, cette fonction se substitue a la
 *      fonction de la bibliotheque C 1.1a, qui ne fait pas
 *      la difference entre la lecture d'un caractere FF venant
 *      du fichier, et une reelle fin de fichier.
 */

char *line;
int nb;
FILE *fp;
{                                       /* fgets */
        int c, i;
        char *p;

	iseof=0;
        c = 0;
        i = 1;
        p = line;

        /* Tant que le buffer n'est pas plein et qu'on n'est pas en fin de ligne. */
        while ((c != '\n') && (i < nb)) {

                if ((c = fgetc(fp)) == '\r' )
			continue;
		else if ( c == -1 )
			return( NULL );
		else if ( c == 0x001A ) {
			iseof=1;
			return( NULL );
			}
		else	{
	                /* C'est un caractere valide, on le pose et on continue */
	                *(line++) = (char) c;
	                i++;
			}
	        }
        *line = '\0';
        return (p);
}                                       /* fgets */
#endif


#ifdef prologue

char *fgets(line, nb, fp)

/*      Lecture d'un caractere dans un fichier bufferise.
 *      NB : Sous prologue, cette fonction se substitue a la
 *      fonction de la bibliotheque C 1.1a, qui ne fait pas
 *      la difference entre la lecture d'un caractere FF venant
 *      du fichier, et une reelle fin de fichier.
 */

char *line;
int nb;
FILE *fp;
{                                       /* fgets */
        int c, i;
        char *p;

        c = 0;
        i = 1;
        p = line;

        /* Tant que le buffer n'est pas plein et qu'on n'est
         * pas en fin de ligne.
         */
        while ((c != '\n') && (i < nb)) {
                c = fgetc(fp);

                /* Soit un caractere /FF, soit une fin de fichier */
                if (c == EOF) {
                        if (feof(fp))
                                return (NULL);
                }

                /* C'est un caractere valide, on le pose et on continue */
                *line++ = (char) c;
                i++;
        }
        *line = '\0';
        return (p);
}                                       /* fgets */


int fputs( char * ch, FILE * fp)

/*      Ecriture d'une ligne de caracteres dans un fichier
 *      bufferise.
 *      Meme probleme sous Amenesik / Sologic (bibli 1.1a) que fgets
 */
{                       /* fputs */
        char *p;

        p = ch;

        /* Si la chaine est vide, rien a ecrire */
        if (!*p)
                return (0);

        /* Tant qu'il y a des caracteres dans la ligne */
        while (*p) {

                /* Distingue un caractere /FF d'une erreur d'ecriture */
                if (fputc(*p++,fp) == EOF) {
                        if (ferror(fp))
                                return (EOF);
                }
        }

        /* Retourne le dernier caractere envoye */
        return (*(--p));
}                       /* fputs */
#endif /* prologue */


FILE *XDfopen(nomfic,typ)

/*      Ouverture d'un fichier par 'fopen', en demandant son exclusivite
 *      pour une exploitation 'multi-utilisateurs' et precede dans le
 *      cas VMS par une suppression systematique de celui-ci s'il
 *      existait anterieurement.
 */
char *nomfic;
char *typ;
{                                       /* XDfopen */
#ifdef  vms
        delete(nomfic);
#endif /* vms */

        return(Xfopen(nomfic,typ));
}                                       /* XDfopen */

                /*-----------------*/

FILE *Xfopen(nomfic,typ)

/*      Ouverture d'un fichier par 'fopen', en demandant son exclusivite
 *      pour une exploitation 'multi-utilisateurs' sans suppression
 *      sauf si ouverture en mode lecture seule sous Amenesik / Sologic.
 */
char *nomfic;
char *typ;
{                                       /* Xfopen */
        FILE    *fh;

#ifdef  unix
        int resac;

        /* Teste le fichier en mode partageable.
         * Si l'acces est possible, c'est que le fichier existe
         * et n'est pas bloque en mode exclusif.
         */
        if (strEq(typ,"r")) {
                resac = Access(nomfic,0,0);
                if (resac == 0)
                        return(fopen(nomfic,"r"));
                else {
                        if ((errno == 666) || (errno == 667))
                                erreur(FATALE,erraut);
                        return(GenericNULL(FILE));
                }
        }

        /* Teste le fichier en mode exclusif.
         * Si l'acces est possible, le fichier existe et n'est pas
         * ouvert (ni en mode partageable ni en mode exclusif).
         * Si l'access n'est pas possible, soit le fichier existe
         * et ne peut pas passer en mode exclusif, soit le fichier
         * n'existe pas et il faut le creer puis le bloquer en exclusif.
         */
        else {
                resac = Access(nomfic,0,1);
                if (resac != 0) {
                        if (errno != ENOENT)
                                return(GenericNULL(FILE));

                        /* cree le fichier puisqu'inexistant */
                        fh = fopen(nomfic,typ);
                        if (fh == GenericNULL(FILE))
                                return(GenericNULL(FILE));

                        /* retente un blocage du fichier */
                        resac = Access(nomfic,0,1);
                        if (resac != 0) {
                                fclose(fh);
                                return(GenericNULL(FILE));
                        }
                        else
                                return(fh);
                }
        }
#endif /* unix */

        fh = fopen(nomfic,typ);

#ifdef msdos
/*      pas d'exclusivite sous DOS      */
#endif /* msdos */

#ifdef prologue
        /* Voir la remarque sur Xopen et le mode copie */
        if (fh != GenericNULL(FILE) && !strEq(typ,"r")) {
                if (fmatb(fh,1,1) != 0) {       /* demande exclusif et copie */
                        Xfclose(fh);
                        fh = GenericNULL(FILE); /* refuse */
                }
        }
  /* BUG du ftell !!! */
        if (fh != GenericNULL(FILE))
    Xfseek(fh,0L,0);  
#endif /* prologue */

#ifdef vms
/*      exclusivite non geree sous VMS          */
#endif /* vms */

        return (fh);
}                                       /* Xfopen */


int Xopen(nomfic,typ,mode)

/*      Ouverture d'un fichier par 'open', en demandant son exclusivite
 *      pour une exploitation 'multi-utilisateurs'
 *      sauf si ouverture en mode lecture seule sous Amenesik / Sologic.
 */
char *nomfic;
int typ,mode;
{                                       /* Xopen */
        int     fh;

        fh = open(nomfic,typ,mode);

#ifdef msdos
/*      pas d'exclusivite sous DOS      */
#endif /* msdos */

#ifdef prologue
        /* Si le fichier est destine a etre ecrit, on le passe
         * en mode copie.
         * La bibliotheque C 2.1a definit le mode copie de maniere
         * opposee a la bibliotheque 1.1a !
         */
        if (fh != -1 && ((typ & (int) O_RDWR) != 0) ) {
                if (matb(fh,1,1) != 0) {
                        Xclose(fh);
                        fh = -1;
                }
        }
#endif /* prologue */

#ifdef vms
/*      exclusivite non geree sous VMS          */
#endif /* vms */

/*      On n'utilise pas cette primitive sous UNIX */

        return (fh);
}                                       /* Xopen */


int bincmp(x,y)

/*      comparaison de deux donnees x et y du type BINAIRE
 *      retourne un entier : < 0 si x < y, = 0 si x = y, > 0 si x > y
 */
BINAIRE x,y;
{                                       /* bincmp */
        long int xl, yl;

        xl = bintolong(x);
        yl = bintolong(y);
        return ((int) (xl - yl));
}                                       /* bincmp */


BYTE *bintobyte(b,vbin)

/*      affecter une valeur binaire sur une zone pointee en BYTE
 *      et fait avancer le pointeur BYTE en retour
 */
BYTE *b;
BINAIRE vbin;
{                               /* bintobyte */
        BINAIRE tb;

        tb = SECOND_BYTE(vbin); *b++ = (BYTE) tb;
        tb = FIRST_BYTE(vbin); *b++ = (BYTE) tb;
        return (b);
}                               /* bintobyte */


BINAIRE bytetobin(b)

/*      affecter une valeur pointee en BYTE a un BINAIRE
 *      en tenant compte de la notation utilisee par le processeur
 *      pour pouvoir effectuer des calculs arithmetiques
 */
BYTE *b;
{                               /* bytetobin */
        BINAIRE bin;

        bin = (BINAIRE) (*b++) & 0x00FF;
        bin += ( ((BINAIRE) *b << 8) & (BINAIRE) 0xFF00 );
        return (bin);
}                               /* bytetobin */


long int bintolong(b)

/*      affecter une valeur BINAIRE a un long, en eliminant le signe eventuel
 */
BINAIRE b;
{                                       /* bintolong */
                register long int l;

                l = (long) b;
                if (l < 0L) l += MXSEG;
                return (l);
}                                       /* bintolong */


                /*-------------------------------------------*
                 *      fonctions globales du traducteur
                 *-------------------------------------------*/

void echolst(ligne)

/*      echo sur fichier liste de 'ligne'
 */
char *ligne;
{                               /* echolst */

        lgnfic++; numlgn++;
        /* Si l'on est active depuis l'ensemble de developpement
         * integre, on tient a jour un compteur de lignes traduites
         */
        if (Optintegre) {
                if ((numlgn % 32L) == 0) {
                        outlong(IL_3,IC_1,numlgn);
                }
        }

        if (liste) {                    /* echo sur fichier liste ? */
                purgeL = TRUE;
                ALadrimpl = adrimpl;
                ALligne = ligne;
                ALcomptage = comptage;
                ALputimpl = putimpl;

        /* A partir de la version 1.4, la purge dans le fichier
         * liste est retardee jusqu'a la fin de l'analyse de la
         * ligne en cours
         */

        }
}                               /* echolst */


void purgelst()

/*      Effectue la purge de la ligne courante dans le
 *      fichier liste
 */
{                               /* purgelst */
  char scrlig[20];

        if ((!purgeL) || fliste == GenericNULL(FILE))
                return;

        purgeL = FALSE;

        /* pour map, position courante sur liste */
        AMcurposlst = Mcurposlst;
        nblstln++;
        if (nblstln > DIMPGLST)
                sautpage();
        if (ALcomptage) {
                sprintf(&scrlig[0],"%6.1lu\t",numlgn);
                if (Xfputs(&scrlig[0],fliste) == EOF)
                        erreur(FATALE,errwritlst);
                Mcurposlst += 7L;
        }
        else {
                if (Xfputs("\t",fliste) == EOF)
                        erreur(FATALE,errwritlst);
                Mcurposlst++;
        }
        if (ALputimpl) {
                sprintf(&scrlig[0],"(%04.4X)\t",(BINAIRE) ALadrimpl);
                if (Xfputs(&scrlig[0],fliste) == EOF)
                        erreur(FATALE,errwritlst);
                Mcurposlst += 7L;
        }
        else {
                if (Xfputs("\t",fliste) == EOF)
                        erreur(FATALE,errwritlst);
                Mcurposlst++;
        }
        if (Xfputs(ALligne,fliste) == EOF)
                erreur(FATALE,errwritlst); /* abandon si impossible */
        if (outmap) {
                Mcurposlst += (long) Xstrlen(ALligne);
#ifdef MODMAP
                Mcurposlst++;
#endif /* MODMAP */
        }
}                                       /* purgelst */


void sautpage()

/*      edition d'un saut de page dans le fichier liste
 */
{                               /* sautpage */
#ifdef pretty_printing
    char scrlig[100];
#endif

        if (liste) {
#ifdef pretty_printing
            /* A partir de la version 1.4, on n'embellit plus le fichier
             * liste lors d'une traduction avec options de mise au point.
             */
            if (!outmap)
        {
            BYTE buf[256];
                    sprintf(&scrlig[0],"%c\n%s v%s\n\n",IPAGE,imptitre,Banner_GetVersionID(buf, Banner_GetVersionStatus()));
                        if (Xfputs(&scrlig[0],fliste) == EOF)
                                erreur(FATALE,errwritlst);
            }
#endif /* pretty_printing */

            nblstln = 3;
        }
}                               /* sautpage */


void suplst(force)

/*      suppression temporaire de la liste, prioritaire si force
 *      vaut 'TRUE' en entree, accorde suivant l'option 'lstforce'
 *      sinon.
 */
BOOL force;
{                                       /* suplst */
        if (flg_suplst == 0) {
                orglst = liste;
        }
        flg_suplst++;
        comptage = FALSE;
        if (force)
                liste = FALSE;
        else if (!lstforce)
                liste = FALSE;    /* suppression temporaire de la liste */
}                                       /* suplst */


void retlst(ligne)

/*      retour a l'option liste initiale en commencant par 'ligne'
 */
char *ligne;
{                                       /* retlst */
        if (flg_suplst == 0)
                return; /* demande qui n'a aucun sens */
        flg_suplst--;
        if (flg_suplst == 0) {
                liste = orglst;
        }

        if (liste)
                comptage = TRUE;
        if (!lstforce)
                echolst(ligne);

        lgnfic--; numlgn--;

}                                       /* retlst */


/*      Gestion du fichier "map"        */
/*      ------------------------        */

void newmap(typ,num)

/*      Assigne une nouvelle entree dans la map de mise au point.
 *      Une entree se compose de :
 *              - un caractere indiquant le type de map (passe dans 'typ')
 *                      'P' pour procedure
 *                      'S' pour segment
 *                      'X' pour fin de map
 *              - un numero de map (passe dans 'num') (2 octets)
 *              - un offset de debut dans le fichier liste (3 octets)
 *                      . numero de secteur (2 octets)
 *                      . offset dans le secteur (1 octet)
 *              - un offset de fin dans le fichier liste (3 octets)
 *              - 7 octets a zero
 */
char    typ;
BINAIRE num;
{                                       /* newmap */
        MapRef  *p;

        /* Vide la ligne courante dans le fichier liste pour
         * mettre a jour la position courante dans ce fichier.
         */
        purgelst();

        if (outmap) {
                p = curmap;

                /* Allocation d'un descripteur de map de mise au point */
                curmap = All_Map();
                if (curmap == GenericNULL(MapRef))
                        erreur(FATALE,errmem);

                /* Insertion du descripteur dans la liste chainee des
                 * descripteurs de map.
                 */
                if (p != GenericNULL(MapRef))
                        p->suiv = curmap;
                else    /* 1ere entree dans la map */
                        map = curmap;

                /* Mise a jour du map avec les infos de debut */
                curmap->typ = typ;
                curmap->num = num;
                curmap->sd = (BINAIRE) ((AMcurposlst - 1L) / 256L);
                curmap->od = (BYTE) ((AMcurposlst - 1L) % 256L);
        }
}                                       /* newmap */


void endmap()

/*      fin d'une entree dans la "map" de mise au point
 */
{                                       /* endmap */
        /* Vide la ligne courante dans le fichier liste pour
         * mettre a jour la position courante dans ce fichier.
         */
        purgelst();

        if (outmap) {
                /* Mise a jour de la map courante avec les infos
                 * de fin de map.
                 */
                curmap->sf = (BINAIRE) (Mcurposlst / 256L);
                curmap->of = (BYTE) (Mcurposlst % 256L);
                curmap->suiv = GenericNULL(MapRef);
        }
}                                       /* endmap */


void newtabcor(typ,ptdesc)
BOOL typ;
void *ptdesc;
{
  /* initialisation */
  if ( typ == FALSE ) { /* proc */
    pdescor = (TabProc *) ptdesc;
    pdescor->adtc = 0;
    pdescor->lgtc = 0;
  } else { /* seg */
    sdescor = (TabSeg *) ptdesc;
    sdescor->adtc = 0;
    sdescor->lgtc = 0;
  }
  if ( outmap ) {
    if ( typ == FALSE ) { /* proc */
      pdescor->adtc = getbloc(NODBG);
      pdescor->lgtc = 8;
    } else { /* seg */
      sdescor->adtc = getbloc(NODBG);
      sdescor->lgtc = 8;
    }
    /* 1er a zero pour extension */
    pbin(NODBG,0);
    pbin(NODBG,0);
    pbin(NODBG,0);
    pbin(NODBG,0);
  }
}


void endtabcor(typ)
BOOL typ;
{
  if ( outmap ) {
    if ( typ == FALSE ) {
    } else {
    }
  }
}


void instabcor(typ)
BOOL typ;
{
  long codedLineFic;

  if ( outmap ) {
    if ( typ == FALSE ) {
      pdescor->lgtc += 8;
    } else {
      sdescor->lgtc += 8;
    }
    pbin(NODBG,ncursrc);
    /*  SG le 16/07/97 : Rajout de l'information ligne a la place de 
     *  l offset
     *  SG le 15/10/97 : Codage du numero de ligne pour inserer le no 
     *  de zone de debug
     */
    if (enhanced_debug){
      codedLineFic=ZoneCodeLineNumber (lgnfic, CurrentZoneCode);
      plong(NODBG,codedLineFic);
    }
    else
      plong(NODBG,seekcur);

    pbin(NODBG,(BINAIRE)adrimpl);
  }
}

char *newfics(s,p)

/*      nouveau nom de fichier source : s
 *      la designation complete est retournee dans p
 *      ncurfic est mis a jour avec le contenu de s au retour.
 */
char *s,*p;
{                                       /* newfics */
        getnomfic(p,s,EXTS);    /* construire la designation complete */
  ncursrc=findsrc(s);
        Xstrcpy(ncurfic,s);
        return (s);
}                                       /* newfics */


char *newficdef(s,p)

/*      nouveau nom de fichier definition : s
 *      la designation complete est retournee dans p
 *      ncurfic est mis a jour avec le contenu de s au retour.
 */
char *s,*p;
{                                       /* newficdef */
        getnomfic(p,s,EXTDEF);  /* construire la designation complete */
        Xstrcpy(ncurfic,s);
        return (s);
}                                       /* newficdef */


void tstpause()

/*      teste si une pause est demandee par l'operateur
 *      cette fonction n'est active que sous prologue
 */
{                                       /* tstpause */
  BINAIRE i;

  if (!Optintegre) {
        /*--- Stand alone ---*/

#ifdef prologue
        if (nbpause != 20) {    /* test non systematique */
                nbpause++;
                return;
        }
        nbpause = 0;
        if (kbhit()) {
                i = getch();
                if (i == 0x001B) {      /* ESCAPE ? */
                        do {
                                i = getch();
                        }
                        while ((i != 0x001B) && (i != 0x000D));
                        if (i == 0x000D)
                                erreur(FATALE,arret);
                }
        }
#endif /* prologue */
#ifdef msdos
        if (nbpause != 20) {    /* test non systematique */
                nbpause++;
                return;
        }
        nbpause = 0;
#ifndef WIN1632
        if (kbhit()) {
                i = getch();
                if (i == 0x001B) {      /* ESCAPE ? */
                        do {
                                i = getch();
                        }
                        while ((i != 0x001B) && (i != 0x000D));
                        if (i == 0x000D)
                                erreur(FATALE,arret);
                }
        }
#else
  /* Sous Windows, laisse passer les messages */
#ifndef DLL
  { extern BOOL GetNoWait(void);
    while (GetNoWait() == TRUE) ;
  }
#endif /* DLL */
#endif
        if (sigabort)
                erreur(FATALE,arret);
#endif /* msdos */
#ifdef unix
        if (sigabort)
                erreur(FATALE,arret);
#endif /* unix */
#ifdef vms
        if (sigabort)
                erreur(FATALE,arret);
#endif /* vms */
  }
  else {
        /*--- Ensemble integre ---*/
        if (nbpause != 20) {    /* test non systematique */
                nbpause++;
                return;
        }
        nbpause = 0;
        if (x_kbhit()) {
                i = x_getch();
                if (i == (BINAIRE) 0x001B) {    /* ESCAPE ? */
                        mesg(tradit," ");
                        do {
                                i = x_getch();
                        }
                        while ((i != (BINAIRE) 0x001B) && (i != (BINAIRE) 0x000D))
                                ;
                        if (i == (BINAIRE) 0x000D)
                                erreur(FATALE,arret);
                        else
                                mesg(arret," ");
                }
        }
  }

}                                       /* tstpause */

                /*------------------------------------------*
                 *      fonctions internes du noyau
                 *------------------------------------------*/

static BOOL init_trad(argc,argv)

/*      initialisation generale pour une traduction
 */
int argc;
char *argv[];
{                                       /* init_trad */
        char *infile,  namesrce[LGMXNOM];       /* nom du fichier source */
        char *outfile, nametrad[LGMXNOM];       /* nom du fichier traduit */
        char *lstfile = GenericNULL(char);      /* fichier liste */
        char *errfile = GenericNULL(char), nameerr[LGMXNOM];    /* nom du fichier erreurs */
        char c, *p, *ptemp;
/* #OK: 01/03/00 (begin) */
        char* oldp;
/* #OK: 01/03/00 (end) */
        BOOL fout     = FALSE;  /* destination implicite a priori */
        BOOL debug    = FALSE;  /* pas de debug a priori */
        BOOL prod_T   = TRUE;   /* production d'un fichier traduit a priori */
        BOOL flg_nom  = FALSE;  /* pas encore de nom de fichier source */
        BOOL wait_err = FALSE;
        BOOL wait_lst = FALSE;
        BOOL mapwarn  = FALSE;
        BOOL inmesfait= FALSE;
        int  nbpredef = 0;
        BOOL flg_f = FALSE;
        FILE *fresp;
        char nameresp[LGMXNOM],buf2[1024];
    char* buftemp;
        char ligarg[512];
        BOOL end;
        int tmp,i;
        char copt[LGMXNOM];
    long longfic;
  #ifdef prologue
    char currentChar;
  #endif
  #ifdef WIN1632
    char juneHandleAsText[LGIDENT];
  #endif


        /* Initialisations indispensables avant d'aller plus loin :
         *      - code erreur (en liaison avec ?MAKE)
         *      - messages
         *      - trap des signaux INT et QUIT
         *      - affichage de la banniere
         *      - verification de l'autorisation de traduction
         */

        RetCode = 0;
        initabmes();
        asyncab(0);
        sigabort = FALSE;

#ifdef prologue
      {
        char line[256];    
          // Vérification de la protection BSA
          if (AW_CheckProtection(FALSE)) {
          sprintf(line,"license,%s,%s", argv[0], "Abal_Kit_de_Developpement");
          if(system(line)) {
            printf("Cl‚ de v‚rification absente ou invalide !");
              return(FALSE);
          }
          }
      }
#endif

        /* Au minimum : un nom de fichier a traduire */
        if (argc-- < 2) {
            banniere();
                return(FALSE);
        }

        /* Mise en place des options par defaut :
         *      - pas de repertoire pour les includes
         *      - pas de warnings
         *      - mode muet
         *      - pas de fichier liste
         *      - pas de map de mise au point
         *      - pas de fichier d'erreurs
         *      - traduction totale
         *      - pas d'optimisation
         *      - pas de detection des alias
         *      - reserve les mots-cles des fonctions mathematiques
         *      - appel depuis l'interpreteur de commandes
         *      - et les initialisations "a faire"
         *      - pas de compatibilite BAL pour 0=256
         */
        lexinit    = parsinit = symbinit = gestinit = FALSE;
        fliste     = GenericNULL(FILE);
        ferr       = GenericNULL(FILE);
        NomFicDep  = GenericNULL(char);
        NomFicErr  = GenericNULL(char);
        nowarn     = TRUE;
    maximumWarningLevel = 9;
        verbose    = FALSE;
        lstforce   = liste = orglst = FALSE;
        purgeL     = FALSE;
        nbpause    = 0;
        flg_suplst = 0;
        outmap     = FALSE;
        outerr     = FALSE;
        Optintegre = FALSE;
    /* #OK: 08/10/99 (begin) */
    presentSegment0 = FALSE; 
    /* #OK: 08/10/99 (end) */
    /* #OK: 27/10/99 (begin) */
    optionTA = FALSE;
    optionTO = FALSE;
    /* #OK: 27/10/99 (end) */
   /* #OK: 09/03/00 (begin) */
   nextArray = FALSE;
   /* #OK: 09/03/00 (end) */
   /* #OK: 02/04/01 (begin)*/ 
     beginProcOrSegm = FALSE;
   /* #OK: 02/04/01 (end)*/ 

   /* #OK: 09/12/99 (begin) */
#ifdef __ATR22__
bProcParam = FALSE;
#endif
/* #OK: 09/12/99 (end) */
 
/* #OK: 10/05/00 (begin) */
#ifdef __ATR22__
levelCommentary = 0;    
#endif
/* #OK: 10/05/00 (end) */

/* #OK: 18/06/02 (begin) */
printToVariable = FALSE;
/* #OK: 18/06/02 (end) */

        flg_reg = flg_alias = ignore_BL = FALSE;
    flg_opt    = TRUE;
        balcomp    = FALSE;
    flglcst    = FALSE;  /* Pas de constantes locales par defaut */
    optimise_tables = FALSE;  /* Pas d'optimisation des tables par defaut */
    enhanced_debug = FALSE;   /*Par defaut:pas d'information de debug sous forme de no de ligne */ 
    NewDBGWithOldExtension = FALSE; 
  #ifndef WIN32 
    OptIdra = FALSE;
  #endif



    /* Initialisation de la pile des zones de debug */
    ZoneInitStack();


#ifdef prologue
        /* Verifie l'autorisation d'utiliser le traducteur sur le poste */
        if (autorise() == 0)
                erreur(FATALE,erraut);
#endif /* prologue */


    

        /* Regroupe tous les arguments de la ligne de commande
         * en une seule chaine qui sera analysee de la meme
         * maniere qu'elle vienne de l'interpreteur de commandes
         * ou d'un fichier.
         */
        ligarg[0] = EOSTR;
        while (argc--) {
                p = *(++argv);
                if (Xstrlen(&ligarg[0]) + Xstrlen(p) >= 254)
                        erreur(FATALE,errsynt);
                Xstrcat(&ligarg[0]," ");
                Xstrcat(&ligarg[0],p);
        }

        /* Analyse la ligne de commande. Chaque option est separee
         * de la precedente :
         *      - soit par au moins un espace ou tabulation
         *      - certaines options peuvent etre collees
         *      - un delimiteur / ou - indique la mention d'une option
         */
        end = FALSE;
        p = &ligarg[0];

        while (!end) {
          c = *p++;

          /* Detecte la fin de la ligne de commande,
           * saute les espaces et tabulations en tete.
           */
          if (c == EOSTR) {
                end = TRUE;
          }
          else {
            if ((c != ' ') && (c != '\t')) {

                /* Detecte le debut d'une option ou la mention
                 * du fichier source a traduire.
                 */
#ifdef unix
                if ((c == DELIMOPT)) {
#endif /* unix */
#ifdef vms
                if ((c == DELIMOPT)) {
#endif /* vms */
#ifdef prologue
                if ((c == DELIMOPT) || (c == '-')) {
#endif /* prologue */
#ifdef msdos
                if ((c == DELIMOPT) || (c == '-')) {
#endif /* msdos */

                /* Analyse des options de traduction :
                 *
                 * E/ p -> apres le delimiteur d'option
                 * S/ p -> apres le dernier caractere de l'option traitee
                 *
                 * Options de traduction prises en compte :
                 * s S d l e m x v n g p o w a c (h) i b
     * Option speciale debug : z
                 */
                    do {
                        c = *p++;

                        /* p -> premier caractere de l'option */
                        switch (c) {

                        /* Attention a l'indentation du source */

        /* Option /s : mention explicite de l'extension
         * a utiliser pour les fichiers sources.
         */
        case 's' :
#ifdef vms
        case 'S' :
#endif /* vms */
#ifdef prologue
        case 'S' :
#endif /* prologue */
#ifdef msdos
        case 'S' :
#endif /* msdos */
                if (EndCurOpt(p) || flg_nom)
                        erreur(FATALE,errsynt);
                i = 0;
                while ((i < 3) && (!EndCurOpt(p))) {
                        EXTS[i++] = *p;
                        p++;
                }
                EXTS[i] = EOSTR;
                if (!EndCurOpt(p))
                        erreur(FATALE,errsynt);
                break;

#ifdef unix
        /* Option /S : sous unix uniquement, indique
         * que l'extension des fichiers sources doit
         * etre comprise en majuscules
         */
        case 'S' :
                if (flg_nom)
                        erreur(FATALE,errsynt);
                EXTS[0] = toupper(EXTS[0]);
                EXTS[1] = toupper(EXTS[1]);
                EXTS[2] = toupper(EXTS[2]);
                break;
#endif /* unix */

        /* Option /d : mention explicite du nom du
         * fichier traduit
         */
        case 'd' :
        case 'D' :
                if (EndCurOpt(p))
                        erreur(FATALE,errsynt);
                tmp = OptCopie(&copt[0],p);
                getnomfic(&copt[0],nametrad,EXTT);
                outfile = nametrad;
                fout = TRUE;
                p += tmp;
                if (!EndCurOpt(p))
                        erreur(FATALE,errsynt);
                break;

        /* Option /l : creation d'un fichier liste
         * Si le nom n'est pas precise, le fichier liste
         * portera le meme nom que le source.
         */

    /* #OK: 27/10/99 (begin) */
    case 't' :
    case 'T' : 
               if ((*p == 'O') || (*p == 'o')) 
               {
                  optionTO = TRUE;                       
                  optionTA = FALSE;                       
                  p++;
               }
               else if ((*p == 'A') || (*p == 'a')) 
               {
                  optionTA = TRUE;                       
                  optionTO = FALSE;                       
                  p++;
               }
               break;
    /* #OK: 27/10/99 (end) */

        case 'l' :
        case 'L' :
                if (EndCurOpt(p))
                        wait_lst = TRUE;
                else {
                        tmp = OptCopie(&copt[0],p);
                        getnomfic(&copt[0],namelst,EXTL);
                        lstfile = namelst;
                        p += tmp;
                        if (!EndCurOpt(p))
                                erreur(FATALE,errsynt);
                }
                liste = orglst = comptage = TRUE;
                break;

        /* Option /e : creation d'un fichier erreurs
         * Si le nom n'est pas precise, le fichier erreurs
         * portera le meme nom que le source.
         */
        case 'e' :
        case 'E' :        
                if (EndCurOpt(p))
                        wait_err = TRUE;
                else {
                        tmp = OptCopie(&copt[0],p);
            getnomfic(&copt[0],nameerr,EXTE); 
                        errfile = nameerr;
                        p += tmp;
                        if (!EndCurOpt(p))
                                erreur(FATALE,errsynt);
                }
                
        outerr = TRUE;
            
                break;

  
        /* Option /m : ajout d'informations de mise au
         * point
         * Option /m+ : mise au point APLUS
         */
        case 'm' :
        case 'M' :
                debug = TRUE;
                if (*p == '+') {
                        p++;
      aplus_debug = TRUE;       
                } else {

      aplus_debug = FALSE;
                }

#ifdef WIN1632
      enhanced_debug = TRUE; //Line number
#else
      enhanced_debug = FALSE;
#endif

        if ((*p == 'D') || (*p=='d'))
        {
          enhanced_debug = FALSE;
          p++;
        }
        if ((*p == 'W') || (*p=='w'))
        {
          enhanced_debug = TRUE;
          p++;
        }
        if ((*p == 'X') || (*p=='x'))
        {
          enhanced_debug = TRUE;
          NewDBGWithOldExtension = TRUE;
          p++;
        }

      break;

        /* Option /x : force la liste des lignes non
         * traduites
         */
        case 'x' :
        case 'X' :
                lstforce = TRUE;
                break;

        /* Option /v : rend le traducteur bavard et
         * affiche la banniere.
         */
        case 'v' :
        case 'V' :
                if (!Optintegre) {
                        verbose = TRUE;
#ifndef WIN1632
                /* #OK: 01/03/00 (begin) */
                if (!flg_f)
                /* #OK: 01/03/00 (end) */
                    banniere();
#endif
                }
                break;

        /* Option /n : definit un symbole de traduction
         * Le nom de ce symbole suit.
         * Attention, on prepare un pointeur sur la ligne
         * d'arguments.
         */
        case 'n' :
        case 'N' :
                if (nbpredef == MAXSYMB)
                        erreur(FATALE,errsynt);
                tmp = OptCopie(&copt[0],p);
                p += tmp;
                if (!EndCurOpt(p))
                        erreur(FATALE,errsynt);

                /* Controle de la syntaxe et majusculisation
                 * du symbole */
                if (!isalpha(copt[0]))
                        erreur(FATALE,errsynt);
                copt[0] = toupper(copt[0]);
                for (i = 1 ; i < tmp ; i++) {
                        if (!isalnum(copt[i]) && (copt[i] != '_'))
                                erreur(FATALE,errsynt);
                        else
                                copt[i] = toupper(copt[i]);
                }
                copt[i] = EOSTR;

                /* Controle de longueur */
                if (Xstrlen(&copt[0]) >= lentokmax)
                        copt[lentokmax-1] = EOSTR;

                /* Definition du symbole */
                Xstrcpy(tabsymb[nbpredef++],&copt[0]);
                break;

        /* Option /g : verification de la syntaxe
         * On ne produit alors pas de code (ou plus
         * exactement on n'ecrit pas le code produit
         * dans le fichier traduit
         */
        case 'g' :
        case 'G' :
                prod_T = FALSE;
                break;

        /* Option /o : optimisation de la traduction
         * Attention, celle-ci entraine automatiquement
         * la selection des warnings.(Jusqu'a 1.4a)
   * en 1.5 : toujours optimise (desactivation de l'optimisation)
         */
        case 'o' :
        case 'O' :
    flg_opt = FALSE;
                break;

        /* Option /w : detection des warnings.
         * Ceux-ci sont toujours detectes mais ne sont
         * signales que si cette option est selectee.
         */
        case 'w' :
        case 'W' :
                nowarn = FALSE;
        /* SG041297 rajout de maximumWarningLevel dans l'option */
        if (EndCurOpt(p))
          maximumWarningLevel = 9;
        else
        {
          if (!isdigit(*p))
            /* #BG 16/12/02 erreur(FATALE,errsynt); */
            break;
          else
          {
            maximumWarningLevel = cartoint(*p);
            while (!EndCurOpt(p)) p++;
          }
        }
                break;

        /* Option /a : detection des alias sur les
         * constantes. Attention : tres long.
         * Chaque insertion d'une constante chaine ou
         * bcd entraine le balayage de la table.
         */
        case 'a' :
        case 'A' :
                flg_alias = TRUE;
                break;

        /* Option /h : signale un appel en mode guide
         * /h seul est le seul documente et provoque
         * un effacement d'ecran.
         * /h1 utilise depuis l'integre n'efface pas
         * l'ecran.
         */
#ifndef WIN32 /* #BG 14/11/01 L'option -h est sans objet en WIN32 */
        case 'h' :
        case 'H' :
                Optintegre = TRUE;
                verbose = FALSE;
                if (*p == '1') {
                        p++;
                        init_ecran(FALSE);
                }
                else {
                        init_ecran(TRUE);

                }
#ifdef MODMAP
                initmes(verbose,2L);
#else /* MODMAP */
                initmes(verbose,1L);
#endif /* MODMAP */
                inmesfait = TRUE;
                break;
#endif

#ifdef VERSION_XX
  case  'y' :
  case  'Y' :
    enhanced_tcode_version();
    break;
#endif

#ifdef ATR_DEBUG
        /* Option /z : signale un appel en mode DEBUG interne
   * /zm : debug mem Alloc,Lib
   * /zm : debug mem fichier
         */
        case 'z' :
        case 'Z' :
                if ((*p == 'M') || (*p == 'm')) {
                        p++;
      dbgoption(AMEM);
    } else {
                  if ((*p == 'F') || (*p == 'f')) {
                          p++;
        dbgoption(AFIC);
      } else {
                    if ((*p == 'T') || (*p == 't')) {
                            p++;
          dbgoption(ATRACE);
        }
      }
                }
                break;
#endif /* ATR_DEBUG */

        /* Option /i : definition d'un repertoire de
         * recherche pour les fichiers include.
         */
        case 'i' :
        case 'I' :
                if (EndCurOpt(p))
                        erreur(FATALE,errsynt);

                tmp = OptCopie(&copt[0],p);
    
    insinclude(&copt[0]);

                p += tmp;
                if (!EndCurOpt(p))
                        erreur(FATALE,errsynt);
                break;

        /* Option /b : compatibilite BAL :
         *      - /b seul : ne reserve pas les mots-cles
         *                  ATN/COS/EXP/LOG/SIN/SQR/TAN afin de permettre
         *                  l'utilisation d'une bibliotheque dynamique
         *                  mathematique.
         * A partir de la version 1.5 :
         *      - /bc     : compatibilite BAL sur les fonctions ou 0 = 256
         */
        case 'b' :
        case 'B' :
         if ((*p == 'c') || (*p == 'C')) {
                        p++;
                        balcomp = TRUE;
                }
                else            /* on continue ... */
                ignore_BL = TRUE;
                break;

        /* Option /f : lecture des options complementaires
         * a partir d'un fichier.
         */
        /*case 'f' :
        case 'F' :
                if ((flg_f) || (EndCurOpt(p)))
                        erreur(FATALE,errsynt);

                flg_f = TRUE;
                tmp = OptCopie(&copt[0],p);
                getnomfic(&copt[0],nameresp,"");
                p += tmp;
                if (!EndCurOpt(p))
                        erreur(FATALE,errsynt);

                //Ouvre et lit le fichier d'options
                fresp = Xfopen(nameresp,"r");
                if (fresp == GenericNULL(FILE))
                        erreur(FATALE,errsynt);

        Xfseek(fresp,0L,2);
        longfic=Xftell(fresp);
        Xfseek(fresp,0L,0);
        buftemp = Xmalloc(longfic+1);
        
        buftemp[0] = '\0';
        while (Xfgets(&buf2[0],256,fresp) != GenericNULL(char)) {
          Xstrcat(&buftemp[0],&buf2[0]);
          tmp = Xstrlen(&buftemp[0])-1;
          if ((buftemp[tmp] == '\n')&&(tmp<= longfic))
              buftemp[tmp] = ' ';
        }
        
                if (!Xfeof(fresp)) {
                        Xfclose(fresp);
                        erreur(FATALE,errsynt);
                }
                Xfclose(fresp);

                // Concatene les options dans la ligne d'options actuelle 
        ptemp=Xmalloc(256);
        Xstrcpy(ptemp,p);
        p = Xmalloc(longfic+1);
        Xstrcpy(p, ptemp);
                Xstrcat(p," ");
                Xstrcat(p,&buftemp[0]);

        Xfree(buftemp);
        Xfree(ptemp);
                break;
*/
        case 'f' : /*SG nouveau traitement de l'option -f, la longueur du fichier n'est plus limitée*/
        case 'F' : /* correction de bug prologue */
                if ((flg_f) || (EndCurOpt(p)))
                        erreur(FATALE,errsynt);

                flg_f = TRUE;
                tmp = OptCopie(&copt[0],p);
                getnomfic(&copt[0],nameresp,"");
                p += tmp;
                if (!EndCurOpt(p))
                        erreur(FATALE,errsynt);

#ifndef prologue
                /* Ouvre et lit le fichier d'options */
                fresp = Xfopen(nameresp,"r");
                if (fresp == GenericNULL(FILE))
                        erreur(FATALE,errsynt);

        Xfseek(fresp,0L,2);
        longfic=Xftell(fresp);
        Xfseek(fresp,0L,0);
#else
        fresp = Xfopen(nameresp,"rb");
                if (fresp == GenericNULL(FILE))
                        erreur(FATALE,errsynt);

        currentChar=0;
        //Calcul longueur de fichier
/* #OK: 01/03/00 (begin) */
/* Commented #OK
        while ((currentChar!='\x1A')&&(longfic<=10000000)) 
        { // Recherche fin de fichier arrête apres 10Mo
          currentChar=fgetc(fresp);
*/
            while (!feof(fresp))
        {
          currentChar=fgetc(fresp);
               if (currentChar == -1) 
                  erreur(FATALE,errsynt); 
               else if ((currentChar == '\x1A') || (currentChar == 0))
                  break;
/* #OK: 01/03/00 (end) */
          printf("%c",currentChar);
          longfic++;
        }
        longfic--;

        Xfclose(fresp);

        fresp = Xfopen(nameresp,"r");
            if (fresp == GenericNULL(FILE))
                 erreur(FATALE,errsynt);


#endif
        buftemp = Xmalloc(longfic+1);
        
        buftemp[0] = '\0';

        while (Xfgets(&buf2[0],256,fresp) != GenericNULL(char)) {
          Xstrcat(&buftemp[0],&buf2[0]);
          tmp = Xstrlen(&buftemp[0])-1;
          if (buftemp[tmp] == '\n')
              buftemp[tmp] = ' ';
        }

                if (!Xfeof(fresp)) {

                        Xfclose(fresp);
                        erreur(FATALE,errsynt);
                }

                Xfclose(fresp);

                /* Concatene les options dans la ligne
                 * d'options actuelle */
              
        ptemp=Xmalloc(256);   
        Xstrcpy(ptemp,p);
        p = Xmalloc(longfic+5+Xstrlen(ptemp)+2);        
            /* #OK: 01/03/00 (begin) */
            oldp = p;
            /* #OK: 01/03/00 (end) */
        Xstrcpy(p, &buftemp[0]); 
        Xstrcat(p," ");
        Xstrcat(p, ptemp);
        Xfree(buftemp);
        Xfree(ptemp);

                break;

    #ifdef WIN1632
    case 'j': //Option pour June, passage d'un handle de connexion pour forcer
    case 'J': // la sortie des infos de traduction dans June.
      OptIdra = TRUE;
      //Lecture du handle de connexion
      i = 0;
      if (!EndCurOpt(p))
      {
        while ( (!EndCurOpt(p) && i<LGIDENT) )
        {
          juneHandleAsText[i] = *p;
          p++;
          i++;
        }
        juneHandleAsText[i]='\0';
        ctReOpenDiagnostic(atoi(juneHandleAsText));
      }
      
    break;
    #endif

        /* Option non reconnue */
        default :
                erreur(FATALE,errsynt);
        }
    
        /* Attention, retour a l'indentation standard */

                    } while(!EndCurOpt(p));
                }
                else {
                        /* Ce n'est pas une option : il s'agit de la
                         * designation du fichier source a traduire
                         * p -> le deuxieme caractere du nom
                         */
                        p--;
                        if (flg_nom)
                                erreur(FATALE,errsynt); /* pas 2 fois !! */
                        else {
                                flg_nom = TRUE;
                                tmp = OptCopie(&copt[0],p);
#ifdef vms
                                if ((NomFicDep = (char *) Xmalloc(LGMXNOM)) == GenericNULL(char))
                                        erreur(FATALE,errmem);
                                Xstrcpy(NomFicDep,&copt[0]);
#endif /* vms */
        /* Initialisation de la liste des sources */
              deb_tnsrc = GenericNULL(TabSrc);
                                infile = newfics(namesrce,&copt[0]);
                                p += tmp;
                                if (!EndCurOpt(p))
                                        erreur(FATALE,errsynt);

#ifndef vms
                                if ((NomFicDep = (char *) Xmalloc(LGMXNOM)) == GenericNULL(char))
                                        erreur(FATALE,errmem);
                                Xstrcpy(NomFicDep,infile);
#endif /* vms */
                        }
                }
            }
          }
        }

        /* Preparation des noms des fichiers en fonction des
         * options de traduction precedemment analysees.
         * On commence par verifier qu'un nom de fichier source
         * a ete mentionne.
         */
        if (!flg_nom)
                erreur(FATALE,errsynt);

        /* Si on appelle le traducteur depuis l'ensemble integre
         * on se doit de preparer l'ecran d'acceuil :
         *      - nom du fichier a traduire
         *      - pas de ligne traduite
         *      - pas d'erreur ni de warning
         *      - taille des tables a zero
         */
        if (Optintegre) {
                affsce(infile,0);
                affsce(infile,1);
                outlong(IL_3,IC_1,0L);
                outbin(IL_4,IC_1+2,nberr);
                outbin(IL_5,IC_1+2,nbwarn);
                outbin(IL_3,IC_4+2,0);
                outlong(IL_4,IC_4,0L);
                outbin(IL_5,IC_4+2,0);
        }

        /* Fichier traduit : en l'absence d'option /d, on prend le nom
         * du fichier source et on change son extension.
         */
    /*Ecrit le nom du fichier à traduire sur l'output June */
    if (OptIdra) EditFileName();

#ifdef DLL
    MessFichier(namesrce);
#endif
    if (!fout) {
      FILE *fresp;
      outfile = Xstrcpy(nametrad,namesrce);
      forceext(outfile,outfile,EXTT);
      }

        /* Fichier liste : si on a mentionne une option /l, il faut creer
         * un fichier liste.
         * Son nom sera celui du fichier source (avec une extension specifique)
         * si la designation complete n'a pas ete faite.
         */
        if (liste) {
                if (wait_lst) {
                        lstfile = Xstrcpy(namelst,namesrce);
                        forceext(lstfile,lstfile,EXTL);
                }
                fliste = XDfopen(lstfile,"w");
                if (fliste == GenericNULL(FILE))
                        erreur(FATALE,erropenlst);

                /* Il faut creer une map de mise au point */
                if (debug) {
                        Mcurposlst = AMcurposlst = 0L;
                        outmap = TRUE;
                        map = curmap = GenericNULL(MapRef);
                }
                sautpage();
                DIMPGLST = 60;
        }
        else if (debug) {
                /* no liste, mais demande de mise au point -> avertissement */
    Mcurposlst = AMcurposlst = 0L;
          outmap = TRUE;
          map = curmap = GenericNULL(MapRef);
        }

        /* Fichier erreurs : si on a mentionne une option /e /c, il faut creer
         * un fichier erreurs, ou un fichier d'information contenant les programmes
     * segments, procedures.
         * Son nom sera celui du fichier source (avec une extension specifique)
         * si la designation complete n'a pas ete faite.
         */
        if (outerr) {
                if (wait_err) {
                        errfile = Xstrcpy(nameerr,namesrce);
                        forceext(errfile,errfile,EXTE); 
                }

                /* Sauvegarde du nom de fichier */
                if ((NomFicErr = (char *)Xmalloc(LGMXNOM)) == GenericNULL(char))
                        erreur(FATALE,errmem);
                Xstrcpy(NomFicErr,errfile);

                /* Creation du fichier d'erreurs */
                if (outerr) ferr = XDfopen(errfile,"w");
        else ferr = XDfopen(errfile,"a");
                if (ferr == GenericNULL(FILE))
                        erreur(FATALE,erropenerr);
        }
        lgnfic = 0L; numlgn = 0L;
    
        /* #OK: 01/03/00 (begin) */
        /* if (flg_f) Xfree(p); Commented #OK */
        if (flg_f) Xfree(oldp);
        /* #OK: 01/03/00 (end) */

        if (!inmesfait) {
#ifdef MODMAP
                initmes(verbose,2L);
#else /* MODMAP */
                initmes(verbose,1L);
#endif /* MODMAP */
        }

        if (mapwarn)
                erreur(WARNING,errnomap);

#ifndef prologue
  /* Lecture de la variable d'environnement ABALINCLUDE */
  /* et insertion des repertoires dans la listes des includes */
{
char *pta,*cp;
#ifdef vms
  if ( ((pta=getenv("ABALINCLUDE")) != NULL) && (Xstrcmp(pta,"undefined") != 0) ) {
#else
  if ( (pta=getenv("ABALINCLUDE")) != NULL ) {
#endif 
#ifdef msdos
    while ( (cp=Xstrchr(pta,';')) != NULL ) {
#endif
#ifdef unix
    while ( (cp=Xstrchr(pta,':')) != NULL ) {
#endif
      *cp='\0';
      insinclude(pta);
      pta=++cp;   
    }
    insinclude(pta);
  }
}
#endif /* ! prologue */

/* #BG 08/10/01 Begin */
/*
  A ce stade l'extension est toujours .AT meme s'il s'agit de la traduction d'un module.
  Donc message d'erreur a tord si traduction d'un module de meme nom qu'un AT en cours d'execution.
*/
#ifdef WIN32
      if (!OptIdra)
#endif
        if (IsFileOpened(nametrad))
          erreur(FATALE, errges4);

/* #BG 08/10/01 End */

       /* Preparation a la traduction : initialisation des differents
         * modules.
         */
        initlex(infile,nbpredef);
        initparse(vtr,itr,debug);
        initsymb();
        initgest(prod_T,outfile);

  /* Test de protection Amenesik / Sologic + Forum */
#ifdef prologue
#ifdef forum
  tstprot();
#endif
#endif

        return (TRUE);
}                                       /* init_trad */


static BOOL EndCurOpt(p)
char *p;

/*      Determine si le caractere pointe par 'p' est une fin
 *      d'option ou non.
 *      Ne deplace pas le pointeur.
 */

{                                       /* EndCurOpt */
        switch(*p) {
                case ' '   :
                case '\t'  :
                case DELIMOPT :
#ifdef prologue
                case '-'   :
#endif /* prologue */
#ifdef msdos
                case '-'   :
#endif /* msdos */
                case EOSTR :
                        return(TRUE);

                default :
                        return(FALSE);
        }
}                                       /* EndCurOpt */


static void init_ecran(effecr)
BOOL effecr;

/*      Ouverture de la gestion d'ecran via CICO lors d'un
 *      appel depuis l'ensemble de developpement integre.
 *      Efface l'ecran si 'effecr' vaut TRUE et desactive le curseur.
 */

{                                       /* init_ecran */
        prndest = 1;
        err_val = 0;
#ifdef unix
        /* Empeche l'envoi d'une sequence d'initialisation au terminal
         * qui pourrait effacer l'ecran inopinement
         */
        if (!effecr)
                modterm(0);
#endif /* unix */
#ifndef WIN1632
        initerm();
#endif
        if (effecr)
                x_clear();
        atb(25);
}                                       /* init_ecran */


static void remet_ecran()

/*      Fermeture de la gestion d'ecran via CICO lors d'un
 *      appel depuis l'ensemble de developpement integre.
 *      Reactive le curseur, et se positionne en bas d'ecran
 *      et se remet avec les couleurs/attributs par defaut.
 */

{                                       /* remet_ecran */
        if (Optintegre) {
                pos(20,1);
                atb(26);
                atb(0);
#ifndef WIN1632
                finterm();
#endif
        }
}                                       /* remet_ecran */


static int getnum()

/*      lecture d'un numerique depuis le clavier, retourne :
 *      -1 si la saisie n'a pas eu lieu (validation en premier)
 *      -2 si la saisie est annulee par ESCAPE
 *      -3 si la saisie est erronee
 */
{                                       /* getnum */
        int     v = 0;
        int     i = 0;

        if (Optintegre) {
                i = x_getch();
                if (i == 0x000D) return (-1);
                if (i == 0x001B) return (-2);
                x_putch(i);
                do {
                        if (i == 0x000D) break;
                        if (!isdigit(i))
                                return (-3);
                        v = (v * 10) + cartoint(i);
                        if (v > 255)
                                return (-3);
                        i = x_getch();
                        if (isprint(i)) x_putch(i);
                        else {
                                if (i == 0x000D) break;
                                x_bell();
                        }
                }
                while (1);
                return (v);
        }
        else {
#ifdef prologue
                i = getch(); putch(i);
                if (i == 0x000D) {
                        putch(0x000A); return (-1);
                }
#endif /* prologue */
#ifdef msdos
                i = getch(); putch(i);
                if (i == 0x000D) {
                        putch(0x000A); return (-1);
                }
#endif /* msdos */
#ifdef unix
                i = Xgetchar();
                if (i == '\n')
                        return (-1);
#endif /* unix */
#ifdef vms
                i = Xgetchar();
                if (i == '\n')
                        return (-1);
#endif /* vms */
                if (i == 0x001B) {
                        printf("\n");
                        return (-2);
                }
                do {
#ifdef prologue
                        if (i == 0x000D) break;
#endif /* prologue */
#ifdef msdos
                        if (i == 0x000D) break;
#endif /* msdos */
#ifdef unix
                        if (i == '\n') break;
#endif /* unix */
#ifdef vms
                        if (i == '\n') break;
#endif /* vms */
                        if (!isdigit(i))
                                return (-3);
                        v = (v * 10) + cartoint(i);
                        if (v > 255)
                                return (-3);
#ifdef prologue
                        i = getch(); putch(i);
#endif /* prologue */
#ifdef msdos
                        i = getch(); putch(i);
#endif /* msdos */
#ifdef unix
                        i = Xgetchar();
#endif /* unix */
#ifdef vms
                        i = Xgetchar();
#endif /* vms */
                }
                while (1);
#ifdef prologue
                putch(0x000A);putch(0x000D);
#endif /* prologue */
#ifdef msdos
                putch(0x000A);putch(0x000D);
#endif /* msdos */
                return (v);
        }
}                                       /* getnum */


#ifndef vms
static char *getnomfic(s,buf,ext)
char *s, *buf, *ext;

        /* Ajoute si necessaire une extension 'ext' au nom
         * de fichier propose en entree dans 's' et met
         * le resultat dans 'buf'.
         * Attention 's' et 'buf' peuvent etre identiques. */

{                                       /* getnomfic */
  char buf1[LGMXNOM];
  char buf2[LGMXNOM];
  char buf3[LGMXNOM];

        if (fn_parser(s,&buf1[0],16) < 2) {
                /* Il n'y a pas d'extension : il faut l'ajouter
                   apres le nom du fichier et avant les cles
                   (Amenesik / Sologic) ou le no de version (vms) eventuels */

                fn_parser(s,&buf1[0],1+2+4+8);  /* chemin + nom */
                fn_parser(s,&buf2[0],32+64);    /* cles + version */

                Xstrcpy(buf,&buf1[0]);          /* pose chemin + nom */
                buf1[0] = SEPTYP;
                buf1[1] = EOSTR;
                Xstrcat(buf,&buf1[0]);          /* pose separateur de type */
                Xstrcat(buf,ext);               /* pose extension */
                Xstrcat(buf,&buf2[0]);          /* pose cles + version */
        }
        else {
                /* Une extension est deja presente : il faut recoller
                   les morceaux et mettre un separateur de type valide
                   (NB: sous prologue le '.' peut servir de separateur
                   de type, mais '-' est meilleur */

                fn_parser(s,&buf1[0],1+2+4+8);  /* chemin + nom */
                fn_parser(s,&buf2[0],16);       /* separateur et extension */
                fn_parser(s,&buf3[0],32+64);    /* cles + version */
                buf2[0] = SEPTYP;

                Xstrcpy(buf,&buf1[0]);          /* pose chemin + nom */
                Xstrcat(buf,&buf2[0]);          /* pose BON separateur + type */
                Xstrcat(buf,&buf3[0]);          /* pose cles + version */
        }

        return(buf);
}                                       /* getnomfic */
#endif /* ! vms */


char *forceext(s,buf,ext)
char *s, *buf, *ext;

        /* Remplace l'eventuelle extension de fichier propose
         * en entree dans 's' par celle qui est dans 'ext'.
         * En l'absence d'extension, pose celle de 'ext'.
         * Met le resultat dans 'buf'.
         * Attention 's' et 'buf' peuvent etre identiques. */

{                                       /* forceext */
  char buf1[LGMXNOM];
  char buf2[LGMXNOM];
  char buf3[LGMXNOM];

        if (fn_parser(s,&buf1[0],16) < 2) {
                /* Il n'y a pas d'extension : il faut l'ajouter
                   apres le nom du fichier et avant les cles
                   (Amenesik / Sologic) ou le no de version (vms) eventuels */

                fn_parser(s,&buf1[0],1+2+4+8);  /* chemin + nom */
                fn_parser(s,&buf2[0],32+64);    /* cles + version */

                Xstrcpy(buf,&buf1[0]);          /* pose chemin + nom */
                buf1[0] = SEPTYP;
                buf1[1] = EOSTR;
                Xstrcat(buf,&buf1[0]);          /* pose separateur de type */
                Xstrcat(buf,ext);               /* pose extension */
                Xstrcat(buf,&buf2[0]);          /* pose cles + version */
        }
        else {
                /* Une extension est deja presente : il faut remplacer
                   l'extension presente par celle qui est proposee en
                   entree.
                   De plus, il faut mettre un separateur de type valide.
                   (NB: sous prologue le '.' peut servir de separateur
                   de type, mais '-' est meilleur */

                fn_parser(s,&buf1[0],1+2+4+8);  /* chemin + nom */
                fn_parser(s,&buf3[0],32+64);    /* cles + version */
                buf2[0] = SEPTYP;
                Xstrcpy(&buf2[1],ext);          /* extension */

                Xstrcpy(buf,&buf1[0]);          /* pose chemin + nom */
                Xstrcat(buf,&buf2[0]);          /* pose BON separateur + type */
                Xstrcat(buf,&buf3[0]);          /* pose cles + version */
        }

        return(getnomfic(s,buf,ext));
}                                       /* forceext */


static BINAIRE OptCopie(b,s)
char *b;
char *s;

/*      Copie l'option de traduction pointee par 's' dans
 *      la zone pointee par 'b'.
 *      S'arrete au premier caractere espace ou tabulation
 *      rencontre.
 */

{                                       /* OptCopie */
        char c;
        BINAIRE nb = 0;

        while (((c = *s++) != EOSTR) && (c != ' ') && (c != '\t')) {
                *b++ = c;
                nb++;
        }

        *b = EOSTR;
        return(nb);
}                                       /* OptCopie */


static int fin()
{                                       /* fin */
        BOOL flg_edl;
        int rparse = 0;
        int force;

#ifdef ATR_DEBUG
  dbgprint(ATRACE,"\nfin():debut");
#endif /* ATR_DEBUG */
        if (outmap) {
                vidmap(NODBG,namelst);
        }

        /* A partir de la version 1.4 :
         *      - la memoire est toujours liberee completement
         *      - l'indicateur 'flg_edl' indique si la traduction aurait
         *        du generer un module, independemment de la detection des
         *        erreurs.
         *      - l'indicateur 'force' precise si une erreur ou non a eu
         *        lieu pendant la traduction (non fatale ici).
         */
        rparse = finparse(1);
        flg_edl = ((rparse & 0x0003) != 0) ? TRUE : FALSE;
        force = (rparse < 8) ? 0 : 1;
        finlex(FALSE);
        fingest(flg_edl,force);
    finsymb(TRUE);

  /* Cas des erreurs tardives dans finlex,fingest,finsymb */
  if ( nberr > 0 ) {
    force = 1;
  }

    if (Optintegre)
            outlong(IL_3,IC_1,numlgn);

    statistiques();
    if (orglst) {
            Xfputc(EOTXT,fliste);   /* marque fin de fichier */
            Xfclose(fliste);        /* et fermeture de la liste */
            fliste = GenericNULL(FILE);
    }
    if (outerr) {
            Xfputc(EOTXT,ferr);     /* marque fin de fichier */
            Xfclose(ferr);          /* et fermeture */
            ferr = GenericNULL(FILE);
            /* Supprime le fichier d'erreurs s'il est vide */
            if ((nberr == 0) && (nbwarn == 0)) {
                    Xunlink(NomFicErr);
            }
    }
    liberfin();      
  /* libere la memoire residuelle */

#ifdef WIN32
  FreeProtection();
#endif
#ifdef ATR_DEBUG
  dbgprint(ATRACE,"\nfin():fin");
#endif /* ATR_DEBUG */

        return (0);
}                                       /* fin */


void liberfin()

/*      Libere les zones memoires allouees par l'initialisation
 *      du traducteur.
 */

{                                       /* liberfin */
LstInc *ptrep;

        if (NomFicDep != GenericNULL(char))
                Xfree(NomFicDep);
  while ( lstincl != GenericNULL(LstInc) ) {
      ptrep = lstincl->suiv;
      if ( lstincl->rep != GenericNULL(char) )
        Xfree(lstincl->rep);
                  Xfree(lstincl);
      lstincl=ptrep;
  }

        if (NomFicErr != GenericNULL(char))
                Xfree(NomFicErr);
}                                       /* liberfin */


#ifndef tcodeasm
/*      definitions des fonctions qui ne sont utilisees que dans la version
 *      INTERNE du traducteur (assembleur de T-code)
 */

void masm(b)
BOOL b;
{
}
#endif /* tcodeasm */


int asyncab(signum)
int     signum;

/*      Fonction de capture des signaux INT et QUIT.
 *      On monte un flag qui sera teste de facon asynchrone
 *      et qui indique une demande d'interruption
 */

{                                               /* asyncab */
#ifdef unix
        signal(SIGINT,asyncab);
        signal(SIGQUIT,asyncab);
#endif /* unix */
#ifdef vms
        signal(SIGINT,asyncab);
        signal(SIGQUIT,asyncab);
#endif /* vms */
#ifdef msdos
#ifndef WIN1632
        signal(SIGINT,(void (*)())asyncab);
#endif
#endif /* msdos */
        sigabort = TRUE;        /* monte le flag d'interruption */
        return(signum);
}                                               /* asyncab */


static void insinclude(pta)
char *pta;
{
LstInc *ptrep;

  /* Allocation de la liste des includes */
  /* si ce n'est pas deja fait */

  if ( lstincl == GenericNULL(LstInc) ) {
    if ( (lstincl = (LstInc *) Xmalloc(sizeof(LstInc)))==GenericNULL(LstInc) )
      erreur(FATALE,errmem);
    lstincl->rep = GenericNULL(char);
    lstincl->suiv = GenericNULL(LstInc);
  }
  ptrep = lstincl;
  while ( ptrep->suiv != GenericNULL(LstInc) )
    ptrep=ptrep->suiv;

  if ((ptrep->suiv = (LstInc *) Xmalloc(sizeof(LstInc)))== GenericNULL(LstInc))
          erreur(FATALE,errmem);

  ptrep->suiv->rep = GenericNULL(char);
  ptrep->suiv->suiv = GenericNULL(LstInc);

  if ((ptrep->rep = (char *) Xmalloc(LGMXNOM)) == GenericNULL(char))
          erreur(FATALE,errmem);

                /* Controle le nom de repertoire :
                 * ATTENTION : on doit considerer le "nom
                 * de fichier comme faisant partie du nom
                 * du repertoire
                 */
  if (fn_parser(&pta[0],ptrep->rep,1+2+4+8+16) == 0)
          erreur(FATALE,errsynt);

                /* Ajoute un delimiteur de repertoire,
                 * sauf :
                 *      - sous VMS
                 *      - sous prologue avec mnemoniques sous-repertoire
                 */
#ifndef vms
#ifdef prologue
  if ((Xstrlen(ptrep->rep) != 4) || (*(ptrep->rep+3) != '.')) {
          if (*(ptrep->rep+Xstrlen(ptrep->rep)-1) != DELIMREP) {
                  pta[0] = DELIMREP;
                        pta[1] = EOSTR;
                        Xstrcat(ptrep->rep,&pta[0]);
              }
    }
#else /* prologue */
      if (*(ptrep->rep+Xstrlen(ptrep->rep)-1) != DELIMREP) {
          pta[0] = DELIMREP;
                pta[1] = EOSTR;
                Xstrcat(ptrep->rep,&pta[0]);
      }
#endif /* prologue */
#endif /* ! vms */
}

/* #BG 08/10/01 Begin */

#ifndef WIN32

/* Implementation dans WATR.C pour Windows */

int IsFileOpened(char * FileName)
{      
/*
  A ce stade l'extension est toujours .AT meme s'il s'agit de la traduction d'un module.
  Donc message d'erreur a tord si traduction d'un module de meme nom qu'un AT en cours d'execution.
  
  Sous Twin, Rename devra etre remplacé par un Open exclusif quand la librarie PCRTL sera utilisée a la place de P3LLIBC.
*/

#ifdef prologue 
  if (access(FileName, 0) == 0)
  {
    char  TmpFile[LGMXNOM];
    int Lg;

    Xstrcpy(TmpFile, FileName);
    Lg = Xstrlen(TmpFile);
    TmpFile[Lg-1] = '@';
    TmpFile[Lg-2] = '@';

    if (rename(FileName, TmpFile) != 0)
    {
      return 1;
    }
    else
      rename(TmpFile, FileName);
  }

#endif

#ifdef unix
  // To be implemented
#endif

  return 0;
}

#endif

/* #BG 08/10/01 End */

