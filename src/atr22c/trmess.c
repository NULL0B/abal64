/*
 *  Projet  : ABAL      Copyright Amenesik / Sologic s.a. (c) 1990, 1999
 *  Module  : ATR
 *  Fichier : TRMESS.C
 *  Version : 2.2b
 *  Date    : 29/03/1999
 *  Systeme : DOS / PRL / UNIX / VMS
 *
 *  Traducteur ABAL
 *
 *  [Gestion des messages du traducteur]
 *
 */

 /*
 * Mises a jour :
 * ------------
 *  18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *  27/08/90 : Introduction de l'appel depuis l'ensemble integre 1.4
 *  30/08/90 : Mise en couleur
 *  10/09/90 : Evite le bourrage en cas d'erreurs en cascade
 *  18/09/90 : Remise en etat de #ifdef en vue de la 1.2e
 *  19/09/90 : Correction des debordements de volume : fprintf interdit !
 *  20/09/90 : Propagation de la modification du 19/09 aux "statistiques"
 *  24/10/90 : Introduction de la gestion du code erreur de retour
 *  30/10/90 : Deplacement de la gestion du code erreur dans GESTFIC
 *       Modification de la fermeture de la traduction
 *  03/12/90 : Affichage conditionnel du nombre d'erreurs/warnings
 *  21/01/91 : Comptabilisation des erreurs, meme fatales
 *       Parametrage version avec assembleur de T-code
 *  20/02/91 : Suppression double mention du nombre d'erreurs dans le
 *       fichier liste
 *  25/02/91 : Liberation memoire complete en sortie du traducteur
 *  ---------- Sortie 1.2f / 1.3c / 1.4a --------------------------------
 *  21/08/91 : Ajout message d'aide rapide apres banniere
 *  02/10/91 : Correction ajout precedent pour Amenesik / Sologic ou le printf
 *       est limite a 128 caracteres
 *  18/10/91 : Sous Amenesik / Sologic, on n'affiche pas les cles d'acces aux fichiers
 *  20/11/91 : Pas de quick help si option /v
 *  ---------- Sortie 1.4b ----------------------------------------------
 *  04/09/92 : Bufferisation de quelques affichages CICO
 *  07/12/92 : Plus de retour possible vers avant 1.4
 *  ------------ 2.1d -------------------------------------------------
 *  22/11/95 : version dediee 2.1
 *  10/08/96 : adaptations Windows
 *  12/03/97 : BSA dans la banniere
 *  01/03/99 : Correction no ligne en long
 *  -------------------------------------------------------------
 * 14/11/99 : (#SP) Bug ATR ?? fixed: Modifications in erreur() to avoid overflow
 *            in the non-WIN branch.
 * 28/11/99 : (#SP) Error expanding error 118 (erexp6) with the name of unknown variable
 *               IsIdentifierRequired() fntc added and error() is modified.
 * 28/02/00 : (#OK) Bug ATR fixed: Option -v: bad caracters.
 * 29/02/00 : (#AT) Amelioration EXA-57 - LOAD.GO modifications for ABAL v.2.2a
 * 14/11/01 : (#BG) Suppression de l'option -h sans objet sous Windows.
 *  ------------ 2.2b -------------------------------------------------
 * 13/12/02 : (#BG) Nouvelle gestion de la bannière.
 */

/* Fichier de definition */
/* --------------------- */

#include "tr.h"
#include "trnoy.hs"   /* #IJM 06/11/02 */
#include "tcode.h"
#include "tsymb.h"
#include "fuser.h"
#include "syntaxe.h"

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

#ifdef WIN32
  /* ctType.h inclue Windows.h, le define permet d'éviter toutes
     les définitions de Windows.h */  
  #define _WINDOWS_
#endif

/* Bannière */
#ifdef prologue
#define __Prl
#endif

#include "atrver.h"

#ifdef WIN1632
#include "clclient.h"
#include "cttype.h"
#include "watrmess.h"
#endif



#define _TRMESS
#include "trmess.hs"
#include "trmess.he"


/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
#include "expr.he"
#endif
/* #AT: 29/02/00, EXA-57 (end)*/

////////////////////////////////////////////////////////////////////////////////////
// #FC 21/01/2003 (begin)
// NOUVELLE GESTION DE LA TABLE DES MESSAGES
////////////////////////////////////////////////////////////////////////////////////
#ifndef HX

// ****************************************************************
// * MessFichier
// ****************************************************************
void MessFichier(char* szNom)
{
  //ODS_(szNom);
  //ODS(":");

}

// ****************************************************************
// * initabmes
// ****************************************************************
void initabmes()
{
// L'initialisation de ces variables sont des résidus de l'ancienne méthode.
// Elles n'ont plus vraiment d'intérêt, mais on les laisse 
// car on est pressé par le temps 
#ifdef US_VERSION
yesno    = Yesno;
isFrench = FALSE;
#else
yesno    = Ouinon;
isFrench = TRUE;
#endif

#ifdef vms
  /* Jeux de caractere prologue */
  if (getenv("PROLOGUE") != GenericNULL(char) ) {
    C_CHG = (BYTE) 0x00DA;  /* coin haut et gauche */
    C_LNH = (BYTE) 0x00C4;  /* ligne horizontale */
    C_CHD = (BYTE) 0x00BF;  /* coin haut et droit */
    C_CBG = (BYTE) 0x00C0;  /* coin bas et gauche */
    C_CBD = (BYTE) 0x00D9;  /* coin bas et droit */
    C_LNV = (BYTE) 0x00B3;  /* ligne verticale */
  }
#endif
}

#endif
////////////////////////////////////////////////////////////////////////////////////
// FIN NOUVELLE GESTION DE LA TABLE DES MESSAGES
// #FC 21/01/2003 (end)
////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////
// VERSION HX
////////////////////////////////////////////////////////////////////////////////////
#ifdef HX /* unix mini */

VOID MesInitTab()

/*  Initialisation de la table des messages
 */

{         /* initabmes */
  BYTE XPTR p;
  WORD   i;
  BOOL  other;

  other = FALSE;
  p = &mentete[0];
  for (i = 0 ; i < 2 ; i++) { /* saute en-tete GESMES et O/N */
    if ( i == 1 ) {
      if (*(p+2) == '1') {
        other = TRUE;
      }
    }
    p += Xstrlen(p)+1;
    while (*p == EOSTR)
      p++;
  }
  if ( other == TRUE ) {
    p = &oentete[0];
    for (i = 0 ; i < 2 ; i++) { /* saute en-tete GESMES et O/N */
      if ( i == 1 ) {
        if (*(p+2) == '1') {
          other = TRUE;
        }
      }
      p += Xstrlen(p)+1;
      while (*p == EOSTR)
        p++;
    }
  }

  for (i = 0 ; i < NBMESS ; i++) {
    messages[i] = p;
    p += Xstrlen(p) + 1;
    while (*p == EOSTR)
      p++;
  }

  etxmes = p;

}         /* initabmes */


void initabmes()

/*  Initialisation de la table des messages
 */

{         /* initabmes */
  char  *p;
  int i;
  BOOL  other;

  other = FALSE;

#ifdef vms
  /* Jeux de caractere prologue */
  if (getenv("PROLOGUE") != GenericNULL(char) ) {
    C_CHG = (BYTE) 0x00DA;  /* coin haut et gauche */
    C_LNH = (BYTE) 0x00C4;  /* ligne horizontale */
    C_CHD = (BYTE) 0x00BF;  /* coin haut et droit */
    C_CBG = (BYTE) 0x00C0;  /* coin bas et gauche */
    C_CBD = (BYTE) 0x00D9;  /* coin bas et droit */
    C_LNV = (BYTE) 0x00B3;  /* ligne verticale */
  }
#endif

  p = &mentete[0][0];
  for (i = 0 ; i < 2 ; i++) { /* saute en-tete GESMES et O/N */
    if (i == 1) {
      if (*(p+2) == '1') {
        other = TRUE;
      }
      yesno = p;
      if ( other ) break;
    }
    p += Xstrlen(p)+1;
    while (*p == EOSTR)
      p++;
  }

  if (other == TRUE) {
    /* autre zone gesmetable */
    p = &oentete[0][0];
    for (i = 0 ; i < 2 ; i++) { /* saute en-tete GESMES et O/N */
      p += Xstrlen(p)+1;
      while (*p == EOSTR)
        p++;
    }
  }

  for (i = 0 ; i < NBMESS ; i++) {
    messages[i] = p;
    p += Xstrlen(p) + 1;
    while (*p == EOSTR)
      p++;
  }

}         /* initabmes */

#endif
////////////////////////////////////////////////////////////////////////////////////
// FIN VERSION HX
////////////////////////////////////////////////////////////////////////////////////


          

void initmes(flgverb,modmap)

/*  initialisation de la gestion des erreurs
 *  Rem: la fonction 'erreur' peut cependant etre utilisee avant
 *  cette initialisation dans le cas d'une erreur fatale
 */
BOOL  flgverb;
long int modmap;
{           /* initmes */
  verbose = flgverb;
  nberr = nbwarn = 0;
  LgCRLF = modmap;
  bourrage = FALSE;

  /* Si on est appele depuis l'ensemble de developpement integre,
   * on a la charge de preparer l'ecran d'affichage de la
   * progression de la traduction.
   */
  if (Optintegre) {
    /* Si on est en mode couleur, on choisit des caracteres
     * jaunes sur un fond bleu
     */
    if (conf(14) == 1) {
      backgr(4);
      foregr(11);
    }

                /* Dessin du cadre */
                cadre(IL_0,IC_0-2,IL_6+1,IC_5);
#ifdef buf_cico
    x_bstart();
#endif
    pos(IL_1,IC_0); x_cprintf(messages[msitg2]);
    pos(IL_2,IC_0); x_cprintf(messages[msitg1]);
    pos(IL_3,IC_0); x_cprintf(messages[msitg3]);
    pos(IL_4,IC_0); x_cprintf(messages[msitg4]);
    pos(IL_5,IC_0); x_cprintf(messages[msitg5]);
    pos(IL_3,IC_2); x_putch(C_LNV); x_cprintf("    Field=m : ");
    pos(IL_4,IC_2); x_putch(C_LNV); x_cprintf("    Field=e : ");
    pos(IL_5,IC_2); x_putch(C_LNV); x_cprintf("      Const : ");
#ifdef buf_cico
    x_bflush();
#endif
  }

}           /* initmes */


static void cadre(ld,cd,lf,cf)

/*  dessin d'un 'cadre' avec les caracteres semi-graphiques
 *  qui a pour positions diagonales (ld,cd) et (lf,cf)
 */
BINAIRE ld,cd,lf,cf;
{         /* cadre */
  BINAIRE i,j,k,lg,ht;

#ifdef buf_cico
  x_bstart();
#endif
  /* Dessine la ligne du haut */
  lg = cf - cd;
  pos(ld,cd);
  x_putch(C_CHG);
  for (i = 1; i < lg; i++)
    x_putch(C_LNH);
  x_putch(C_CHD);

  /* Dessine la ligne du bas */
  pos(lf,cd);
  x_putch(C_CBG);
  for (i = 1; i < lg; i++)
    x_putch(C_LNH);
  x_putch(C_CBD);

  /* Dessine les lignes intermediaires */
  ht = lf - ld;
  j = ld + 1;
  for (i = 1; i < ht; i++, j++) {
    pos(j,cd); x_putch(C_LNV);
    for (k = 1 ; k < lg ; k++)
      x_putch(' ');
    x_putch(C_LNV);
  }

#ifdef buf_cico
  x_bflush();
#endif
}         /* cadre */


static void ivon()

/*  Si l'ecran est monochrome, passe en video inversee.
 *  Si l'ecran est "couleurs", change les couleurs
 *  de fond et de forme.
 */

{         /* ivon */
  if (conf(14) == 1) {
    backgr(CI_FOND);
    foregr(CI_CAR);
  }
  else
    atb(2);
}         /* ivon */


static void ivoff()

/*  Revient a la video normale. */

{         /* ivoff */
  if (conf(14) == 1) {
    backgr(C_FOND);
    foregr(C_CAR);
  }
  else
    atb(0);
}         /* ivoff */


void banniere(void)

/*  affichage de la banniere du traducteur
 */
{         /* banniere */

#ifdef prl3
  BYTE UserName[48+1];  /* +1 : pour la gestion d'une chaine de caracteres */
  BYTE DeptName[48+1];
  BYTE SerialNo[20+4];  /* +1+3 : gestion chaine + prise en compte de 3 blancs*/
#endif

  BYTE buf[256];

#ifdef WIN32

  /* Affiche le nom de produit */
  x_cprintf(Banner_GetProductName(buf));

  /* Affiche la version */
  x_cprintf("\n");
    x_cprintf(Banner_GetVersionID(buf, Banner_GetVersionStatus()));

  /* Affiche la mention de build */
  x_cprintf("\n");
  x_cprintf(Banner_GetBuild(buf));
  x_cprintf("\n");

  /* Affiche la mention de copyright */
  x_cprintf(Banner_GetCopyright(buf));
  x_cprintf("\n");

  /* Affiche l'internal name */
//  x_cprintf(Banner_GetInternalName(buf));
//  x_cprintf("\n");

  /* Affiche le commentaire */
//  x_cprintf(Banner_GetComment(buf));
//  x_cprintf("\n");

#else /* WIN32 */

  /* Affiche le nom de produit */
  printf(Banner_GetProductName(buf));

  /* Affiche la version */
  printf("\n");
    printf(Banner_GetVersionID(buf, Banner_GetVersionStatus()));

  /* Affiche la mention de build */
  printf(" ");
  printf(Banner_GetBuild(buf));

#ifdef prl3
  /* Lecture du no de serie non formate */
  AW_GetSerial(UserName);
  /* Formattage du no de serie avec insertion de blancs comme separateur de blocs */
  AW_FormatSerial(SerialNo, UserName, ' ');
   /* Lecture du nom et de la societe */
  AW_GetId(UserName, DeptName);
  UserName[sizeof(UserName)-1] = '\0';
  DeptName[sizeof(DeptName)-1] = '\0';
  /* Informations BSA */
  printf("\r\n%s %s","Cl‚ d'identification : ", SerialNo);
  printf("\r\n%s %s","Nom :                  ", UserName);
  printf("\r\n%s %s","Soci‚t‚ :              ", DeptName);
#endif

  /* Affiche la mention de copyright */
  printf("\n");
  printf(Banner_GetCopyright(buf));

  /* Affiche l'internal name */
//  printf(Banner_GetInternalName(buf));
//  printf("\n");

  /* Affiche le commentaire */
//  printf(Banner_GetComment(buf));
//  printf("\n");

#endif /* WIN1632 */

  help();
}         /* banniere */


void help()
{         /* help */
int i;
char *pmes;

  /* Sous prologue, il faut gagner de la place
    On enlève le 'Syntaxe : atr [' et le ']' plus bas et les options -t */
#ifdef prologue
  i = quickhelp+1;
#else
  i = quickhelp;
#endif

  while ( (pmes = messages[i++]) != GenericNULL(char) ) {
#ifdef prologue
    if ( i > (NBHELP - 4) )
#else
    if ( i > NBHELP )
#endif
      break;
#ifdef WIN1632
    if (i != Help008 + 1)   /* #BG 14/11/01 L'option -h est sans objet en WIN32 */
    { BYTE buf[256];
      sprintf(buf,"\r\n%s",pmes);
      x_cprintf(buf);
    }
#else
    printf("\n%s",pmes);
#endif
  }

/* Sous prologue, il faut gagner de la place */
#ifndef prologue
#ifndef WIN1632
  printf("\n");
#endif
#endif
}         /* help */




/* #SP: 28/11/99 (begin) */
BYTE IsIdentifierRequired(int numes){
  switch (numes){
  case erexp6: //118
    return 1;
  }
  return 0;
}
/* #SP: 28/11/99 (end) */


void erreur(gravite,numes)

/*  Signale une erreur en cours de traduction, avec la possibilite
 *  d'arreter la traduction si cette erreur est fatale.
 *  il y a un echo sur l'eventuel fichier liste.
 *  Si une erreur fatale est survenue avant, toute erreur / warning
 *  sera traite comme une erreur fatale.
 *  Si une erreur survient pendant le traitement d'une erreur
 *  (impossibilite d'ecrire dans le fichier liste ou d'erreurs),
 *  un indicateur est monte pour eviter les reentrances.
 */
BYTE gravite;
int  numes;
{       /* erreur */
  char *msg;
  long noliger;
  char buf[256];
  int rparse;
  int warningLevel;

  /* Evite le bourrage */
  if (bourrage)
    return;

  /* Elimine la sortie des warnings non desires par l'utilisateur */
  if ((gravite == WARNING) && nowarn)
    return;

  /* Traite l'erreur d'ecriture survenant pendant l'ecriture
   * du fichier liste ou du fichier d'erreurs.
   * Meme si elle n'est pas signalee comme telle, il s'agit
   * d'une erreur fatale et il ne faut surtout pas completer
   * les fichiers liste et d'erreurs.
   */
  if (errfat || (numes == errwritlst) || (numes == errwriterr))
  {
    errfat = TRUE;
    gravite = FATALE;
  }

  /* Recupere le message d'erreur/warning a afficher */
  msg = messages[numes];

 /* #SP: 28/11/99 (begin) */
  if (IsIdentifierRequired(numes))
  {
    char  buf[256];

    strcpy(buf," :");
    if (usc.v.pval == (char *)0)
      strcat(buf," ?");
    else
      strcat(buf,(char*)usc.v.pval);

    err2(gravite,numes,buf);
    return;
  }
 /* #SP: 28/11/99 (end) */

  noliger = (lgnfic == 0L) ? 1L : lgnfic;

  /* Comptabilise le nombre d'erreurs et de warnings */
  if (gravite != FATALE)
  {
    if (gravite != WARNING)
    {
      nberr++;
      if (isdigit(*msg)) msg++;

      /* Affiche soit le nombre d'erreurs rencontrees,
       * soit le nom du fichier, le numero de ligne et le message
       * d'erreur.
       */
      if (Optintegre)
        outbin(IL_4,IC_1+2,nberr);
      else
      {
#ifdef WIN1632
        sprintf(buf,"\r\n%s (%lu) : %s", ncurfic, noliger, msg);
        x_cprintf(buf);
        //ODS(buf);
        if (OptIdra)  
          ctOutputErrorDiagnostic2(0, ncurfic, noliger, clncur ,msg, NULL);
#else
        printf("\n%s (%lu) : %s", ncurfic, noliger, msg);
#endif
      }
    }
    /* Affiche soit le nombre de warnings rencontres,
     * soit le nom du fichier, le numero de ligne et le message
     * d'avertissement.
     */
    else
    {
      if (isdigit(*msg)) 
      {
        warningLevel=cartoint(*msg);
        msg++;
      }
      else
        warningLevel = 0;

      if (warningLevel <= maximumWarningLevel)
      {
        nbwarn++;
        if (Optintegre)
          outbin(IL_5,IC_1+2,nbwarn);
        else
        {
  #ifdef WIN1632
          sprintf(buf,"\r\n%s (%lu) %s : %s", ncurfic, noliger, messages[msgwrg], msg);
          x_cprintf(buf);
          //ODS(buf);
          if (OptIdra)
            ctOutputWarningDiagnostic2(warningLevel, ncurfic, noliger, clncur, msg, NULL);
  #else
        printf("\n%s (%lu) %s : %s", ncurfic, noliger, messages[msgwrg], msg);
  #endif
        }
      }
    }

    /* Signale les erreurs / warnings dans le fichier liste
     * si l'utilisateur l'a demande.
     */
    if (liste)
    {
      purgelst();

      /* Gestion des erreurs usuelles */
      if (gravite == USUAL)
      {
        nblstln += 4;
        if (nblstln > DIMPGLST)
          sautpage();
        if (Xfputs("\t\t",fliste) == EOF)
        {
          errfat = TRUE;
          goto errerr;
        }
        postick(fliste);
        sprintf(&buf[0],"\n%s : %s\n\n", messages[msgerr], msg);
        if (Xfputs(&buf[0],fliste) == EOF)
        {
          errfat = TRUE;
          goto errerr;
        }

      }

      /* Gestion des warnings */
      else
      {
        nblstln += 3;
        if (nblstln > DIMPGLST)
          sautpage();
        sprintf(&buf[0],"\n%s : %s\n\n", messages[msgwrg], msg);
        if (Xfputs(&buf[0],fliste) == EOF)
        {
          errfat = TRUE;
          goto errerr;
        }

        if (outmap)
        {
          Mcurposlst += (LgCRLF * 3L) + 2L;
          Mcurposlst += (long) Xstrlen(messages[msgwrg]);
          Mcurposlst += (long) Xstrlen(msg);
        }
      }
    }

    /* Signale les erreurs / warnings dans le fichier d'erreurs
     * si l'utilisateur l'a demande.
     */
    if (outerr)
    {
      sprintf(&buf[0],"%s %lu %u %s", ncurfic, noliger, clncur, msg);
      if (Xfputs(&buf[0],ferr) == EOF)
      {
        errfat = TRUE;
        goto errerr;
      }

      if (glproc != GenericNULL(BYTE))
      {
        sprintf(&buf[0]," (Proc: %s)",glproc);
        if (Xfputs(&buf[0],ferr) == EOF)
        {
          errfat = TRUE;
          goto errerr;
        }

      }
      else
      {
        if (glseg != 255)
        {
          sprintf(&buf[0]," (Seg: %d)",glseg);
          if (Xfputs(&buf[0],ferr) == EOF)
          {
            errfat = TRUE;
            goto errerr;
          }
        }
      }
      if (Xfputs("\n",ferr) == EOF)
      {
        errfat = TRUE;
        goto errerr;
      }
    }
  }

  /* Gestion des erreurs fatales : elles forcent l'interruption
   * de la traduction.
   * On monte immediatement un semaphore pour eviter le "bourrage"
   * c'est-a-dire qu'une autre erreur soit detectee pendant le
   * traitement de l'erreur fatale.
   * Par exemple, ceci peut se produire lorsque la detection des
   * warnings est active et qu'une erreur fatale se produit en
   * milieu de traduction d'un segment/procedure : les messages
   * "identificateur declare et non utilise", ... vont sortir
   * lors de la fermeture du traducteur.
   */
  else
  {
    nberr++;
    bourrage = TRUE;

    /* Signale la cause de l'erreur */
    purgelst();
    if (Optintegre)
    {
      /* Affichage de la cause de l'erreur sur la derniere
       * ligne de la boite.
       */
      prepdlig();
#ifdef buf_cico
      x_bstart();
#endif
      x_bell();
      ivon();
      sprintf(&buf[0]," %s %s ", msg, messages[msgabort]);
      buf[IC_5-IC_0-1] = EOSTR;
      x_cprintf(&buf[0]);
      ivoff();
#ifdef buf_cico
      x_bflush();
#endif
    }
    else
    {
#ifdef WIN1632
      sprintf(buf,"\r\n%s(%lu) : %s %s\n", ncurfic, noliger, msg, messages[msgabort]);
      x_cprintf(buf);
      sprintf(buf,"%s(%lu) : %s %s", ncurfic, noliger, msg, messages[msgabort]);
      if (OptIdra)  
        ctOutputErrorDiagnostic2(-1, ncurfic, noliger, clncur, msg, messages[msgabort]);
      //ODS(buf);
#else
      printf("\n%s(%lu) : %s %s\n", ncurfic, noliger, msg, messages[msgabort]);
#endif
    }

    /* Signale l'erreur dans le fichier liste, si
     * l'utilisateur l'a demande sauf si l'erreur
     * provient d'une impossibilite d'ecrire dans
     * le fichier liste.
     */
errerr:   bourrage = TRUE;

    if (!errfat)
      retlst("\n");

    if ((fliste != GenericNULL(FILE)) && orglst)
    {
      if (!errfat)
      {
        nblstln += 2;
        if (nblstln > DIMPGLST)
          sautpage();
        sprintf(&buf[0],"\n%s : %s %s\n%c", messages[msgerr], msg, messages[msgabort], EOTXT);
        if (Xfputs(&buf[0],fliste) == EOF)
        {
          errfat = TRUE;
        }
      }
      Xfclose(fliste);
      fliste = GenericNULL(FILE);
    }

    /* Signale l'erreur dans le fichier erreurs si
     * l'utilisateur l'a demande sauf si l'erreur
     * provient de l'impossibilite d'ecrire dans
     * le fichier erreur.
     */
    if ((ferr != GenericNULL(FILE)) && outerr)
    {
      if (!errfat)
      {
        sprintf(&buf[0],"%s %lu %u %s", ncurfic, noliger, clncur, msg);
        if (Xfputs(&buf[0],ferr) == EOF)
        {
          errfat = TRUE;
          goto errerr2;
        }

        if (glproc != GenericNULL(BYTE))
        {
          sprintf(&buf[0]," (Proc: %s)",glproc);
          if (Xfputs(&buf[0],ferr) == EOF)
          {
            errfat = TRUE;
            goto errerr2;
          }
        }
        else
        {
          if (glseg != 255)
          {
            sprintf(&buf[0]," (Seg: %d)",glseg);
            if (Xfputs(&buf[0],ferr) == EOF)
            {
              errfat = TRUE;
              goto errerr2;
            }
          }
        }
        sprintf(&buf[0],"%s\n%c",messages[msgabort],EOTXT);
        if (Xfputs(&buf[0],ferr) == EOF)
        {
          errfat = TRUE;
          goto errerr2;
        }
      }
errerr2:
      Xfclose(ferr);
      ferr = GenericNULL(FILE);
    }

    /* Fermetures forcees avec abandon avant
     * retour brutal a l'appelant.
     * Liberation memoire :
     *  - que dans l'integre jusqu'a la version 1.2e / 1.3b
     *  - toujours a partir de la version 1.4 et 1.2f / 1.3c
     * Par ailleurs, on indique lors de la fermeture du
     * traduit, si une edition de liens aurait ete necessaire.
     */
    finlex(TRUE);
    rparse = finparse(2);
    fingest((BOOL)((rparse & 0x0003) != 0 ? TRUE : FALSE),2);
    finsymb(TRUE);

    /* Liberation de la memoire residuelle et retour */
    liberfin();
#ifdef ATR_DEBUG
    dbgstat();
    dbgfin("atrdebug.txt");
#endif /* ATR_DEBUG */    
    Xlongjmp(Tr_Exit,1);
  }
}       /* erreur */


void err2(gravite,numes,msg2)

/*  Signale une erreur commentee en cours de traduction,
 *  il y a un echo sur l'eventuel fichier liste.
 *  Si une erreur se produit pendant l'ecriture du fichier
 *  liste ou du fichier erreurs, un indicateur d'erreur fatale
 *  est monte, MAIS le retour a l'appelant est toujours assure.
 */
BYTE gravite;
int numes;
char *msg2;
{       /* err2 */
  char *msg;
  long noliger;
  char buf[256];
  int warningLevel;

  /* Evite le bourrage */
  if (bourrage)
    return;

  /* Recupere le message d'erreur */
  msg = messages[numes];

  noliger = (lgnfic == 0L) ? 1L : lgnfic;

  /* Affiche soit le nombre d'erreurs, soit le
   * fichier, la ligne et la cause de l'erreur.
   */
  if (gravite != WARNING)
  {
    /* On enlève le premier caractère qui est un niveau de warning*/
    if (isdigit(*msg)) msg++;
    nberr++;
    if (Optintegre)
      outbin(IL_4,IC_1+2,nberr);
    else
    {
#ifdef WIN1632
      sprintf(buf,"\r\n%s (%lu) : %s %s", ncurfic, noliger, msg, msg2);
      x_cprintf(buf);
      //ODS(buf);
      if (OptIdra) 
        ctOutputErrorDiagnostic2(0, ncurfic, noliger, clncur, msg, msg2);
#else
      printf("\n%s (%lu) : %s %s", ncurfic, noliger, msg, msg2);
#endif
    }
  }

  /* Affiche soit le nombre d'erreurs, soit le
   * fichier, la ligne et la cause de l'erreur, sauf
   * si l'utilisateur ne desire pas les warnings.
   */
  else
  {
    if (nowarn)
      return;
    if (isdigit(*msg)) 
    {
      warningLevel=cartoint(*msg);
      msg++;
    }
    else
      warningLevel = 0;
    
    if (warningLevel <= maximumWarningLevel)
    {
      nbwarn++;
      if (Optintegre)
        outbin(IL_5,IC_1+2,nbwarn);
      else
      {
#ifdef WIN1632
        sprintf(buf,"\r\n%s (%lu) %s : %s %s",ncurfic, noliger, messages[msgwrg], msg, msg2);
        x_cprintf(buf);
        //ODS(buf);
        if (OptIdra)
          ctOutputWarningDiagnostic2(warningLevel, ncurfic, noliger, clncur, msg, msg2);
#else
        printf("\n%s (%lu) %s : %s %s", ncurfic, noliger, messages[msgwrg], msg, msg2);
#endif
      }
    }
  }

  /* Signale l'erreur / warning dans le fichier liste
   * si l'utilisateur l'a demande.
   */
  if (liste) {
    nblstln += 2;
    if (nblstln > DIMPGLST)
      sautpage();

    if (gravite == USUAL) {
      sprintf(&buf[0],"\n%s : %s %s\n",messages[msgerr],msg,msg2);
      if (Xfputs(&buf[0],fliste) == EOF) {
        errfat = TRUE;
        return;
      }
    }
    else {
      sprintf(&buf[0],"\n%s : %s %s\n",messages[msgwrg],msg,msg2);
      if (Xfputs(&buf[0],fliste) == EOF) {
        errfat = TRUE;
        return;
      }
      if (outmap) {
        Mcurposlst += (LgCRLF * 2L) + 2L;
        Mcurposlst += (long) Xstrlen(messages[msgwrg]);
        Mcurposlst += (long) Xstrlen(msg);
        Mcurposlst += (long) Xstrlen(msg2);
      }
    }
  }

  /* Signale l'erreur / warning dans le fichier erreurs
   * si l'utilisateur l'a demande.
   */
  if (outerr) {
    sprintf(&buf[0],"%s %lu %u %s %s\n",ncurfic,noliger,clncur,msg,msg2);
    if (Xfputs(&buf[0],ferr) == EOF) {
      errfat = TRUE;
      return;
    }
  }
}       /* err2 */



void statistiques()

/*  Vidage des informations generales en fin de traduction :
 *  il s'agit du nombre d'erreurs et de warnings, sauf si ces
 *  derniers ne sont pas demandes par l'utilisateur.
 */
{         /* statistiques */
  char buf[100];

  /* Affiche les informations statistiques a l'ecran :
   * A partir de la version 1.4, le nombre d'erreurs
   * et de warnings ne sont affiches que si :
   *  - l'option verbose est selectee
   *  - ou au moins une erreur/warning a ete detecte
   */
  if (!Optintegre) {
    if ((verbose) || (nberr != 0) || ((nbwarn != 0) && (!nowarn))) {
#ifdef WIN1632
      {   
        BYTE buf[256];
/* #BG 16/08/01
        if (verbose)
        {
          // Informe l'utilisateur sur le nombre de segments
          sprintf(buf,"\r\n   %s : %u\r\n",messages[msgvidseg],nbSegment);
            x_cprintf(buf); 
          // Informe l'utilisateur sur le nombre de procédures
          sprintf(buf,"   %s : %u\r\n",messages[msgvidproc],nbProcedure);
            x_cprintf(buf); 
        }
*/
        /* Informe l'utilisateur sur le nombre d'erreurs */
          sprintf(buf,"\r\n   %s : %u\r\n",messages[msgviderr],nberr);
          x_cprintf(buf);
          //sprintf(buf,"   %s : %u",messages[msgviderr],nberr);
        //ODS(buf);
        //if ((OptIdra)&&(verbose))  ctOutputMessageDiagnostic2(buf, NULL);

          if (!nowarn)
        {
          /* Informe l'utilisateur sur le nombre d'avertissements */
            sprintf(buf,"   %s : %u\r\n",messages[msgvidwrg],nbwarn);
              x_cprintf(buf);
            //sprintf(buf,"   %s : %u",messages[msgvidwrg],nbwarn);
          //ODS(buf);
          //if ((OptIdra)&&(verbose))  ctOutputMessageDiagnostic2(buf,NULL);
        }

          sprintf(buf,"\r\n\r\n");
          x_cprintf(buf);
        
      }
#else
/*  #BG 16/08/01
      if (verbose)
      {
         printf("\n   %s : %u\n",messages[msgvidseg],nbSegment);
          printf("   %s : %u\n",messages[msgvidproc],nbProcedure);
      }
*/
      printf("\n\n   %s : %u\n",messages[msgviderr],nberr);
      if (!nowarn)
        printf("   %s : %u\n",messages[msgvidwrg],nbwarn);

        printf("\r\n\r\n");
#endif
    }
  }

  /* Vidage des informations statistiques dans le fichier
   * liste, si l'utilisateur l'a demande.
   * On traite le cas de l'erreur survenant en cours d'ecriture
   * du le fichier liste.
   */
  if (liste) {
    nblstln += 4;
    if (nblstln > DIMPGLST)
      sautpage();
    sprintf(&buf[0],"\n\n   %s : %u\n",messages[msgviderr],nberr);
    if (Xfputs(&buf[0],fliste) == EOF) {
      errfat = TRUE;
      return;
    }
    if (!nowarn) {
      sprintf(&buf[0],"   %s : %u\n",messages[msgvidwrg],nbwarn);
      if (Xfputs(&buf[0],fliste) == EOF) {
        errfat = TRUE;
        return;
      }
    }
  }
}         /* statistiques */


void affsce(nc,opt)
char *nc;
int opt;

  /* Affiche le nom du fichier source pointe par 'nc'
   * si 'opt' vaut 0, il s'agit du source initial
   * si 'opt' vaut 1, c'est le fichier en cours.
   */

{         /* affsce */
  char *p;
  int i,tmp;
#ifdef prologue
  char buf1[LGMXNOM];
#endif

  tmp = Xstrlen(messages[msitg2]);
  pos((opt == 0) ? (IL_1) : (IL_2),IC_0+tmp);

  /* Efface la fin de la ligne courante */
#ifdef buf_cico
  x_bstart();
#endif
  for (i = 0 ; i < IC_5-IC_0-tmp-1 ; i++)
    x_putch(' ');
  pos((opt == 0) ? (IL_1) : (IL_2),IC_0+tmp);

  /* Sous Amenesik / Sologic, on n'affiche pas les eventuelles cles
   * d'acces aux fichiers.
   */
#ifdef prologue
  (void) fn_parser(nc,&buf1[0],1+2+4+8+16);
  p = &buf1[0];
#else
  p = nc;
#endif

  /* Evite le debordement du cadre.
   * Met les noms en majuscule (sauf sous unix et Windows 32 bits).
   */
  for (i=0 ; (i < IC_5-IC_0-1-tmp) && (*p != EOSTR) ; i++) {
#ifdef unix
    x_putch(*p++);
#else
#ifdef WIN32
    x_putch(*p++);
#else
    x_putch(((*p >= 'a') && (*p <= 'z')) ? (toupper(*p)) : (*p));
    p++;
#endif
#endif
  }
#ifdef buf_cico
  x_bflush();
#endif
}         /* affsce */


void prepdlig()

/*  Prepare la derniere ligne de la boite de l'ensemble integre
 *  pour un affichage. Nettoyage et remise du bord droit.
 *  Place le curseur au debut utile de cette derniere ligne.
 */

{         /* prepdlig */
  int i;

#ifdef buf_cico
  x_bstart();
#endif
  pos(IL_6,IC_0);
  for (i = 0 ; i < IC_5-IC_0-1 ; i++)
    x_putch(' ');

  pos(IL_6,IC_0);
#ifdef buf_cico
  x_bflush();
#endif
}         /* prepdlig */


void mesg(msg1,msg2)

/*  Affiche un message en cours de traduction :
 *  'msg1' contient un numero de message fixe,
 *  'msg2' pointe sur un message dependant du contexte.
 *  Ce message est affiche sur la derniere ligne de la boite.
 */
int msg1;
char *msg2;
{       /* mesg */
  char buf[80];

  if (Optintegre) {
    prepdlig();
#ifdef buf_cico
    x_bstart();
#endif
    sprintf(&buf[0],"%s %s",messages[msg1],msg2);
    buf[IC_5-IC_0-10] = EOSTR;
    x_cprintf(&buf[0]);
#ifdef buf_cico
    x_bflush();
#endif
  }
  else
#ifdef WIN1632
    { BYTE buf[256];
      sprintf(buf,"\r\n%s %s",messages[msg1],msg2);
      x_cprintf(buf);
      sprintf(buf,"%s %s",messages[msg1],msg2);
      //ODS(buf);
      if (OptIdra)  ctOutputMessageDiagnostic2(buf, NULL);

    }
#else
    printf("\n%s %s",messages[msg1],msg2);
#endif
}       /* mesg */


void messch(msg1,msg2)

/*  Affiche le message de numero 'msg1', eventuellement suivi
 *  par celui qui est pointe par 'msg2'.
 *  Affichage systematique sur le cadre dans le cas de l'appel
 *  depuis l'ensemble integre, et en cas d'option verbose
 *  lors de l'appel depuis l'interpreteur de commandes.
 */
int msg1;
char *msg2;
{       /* messch */
  int i,tmp=0;

  if (Optintegre) {
#ifdef buf_cico
    x_bstart();
#endif
    pos(IL_0,IC_0+2);
    x_putch(' ');
    x_cprintf(messages[msg1]);
    if (msg2 != GenericNULL(char)) {
      x_cprintf(msg2);
      tmp = Xstrlen(msg2);
    }
    x_putch(' ');
    tmp += Xstrlen(messages[msg1]);
    for (i=0 ; i < IC_5-IC_0-10-tmp ; i++)
      x_putch(C_LNH);
#ifdef buf_cico
    x_bflush();
#endif
  }
  else {
    if ((verbose) && (msg2 != GenericNULL(char)))
#ifdef WIN1632
      { BYTE buf[256];
        sprintf(buf,"\r\n%s %s",messages[msg1],msg2);
        x_cprintf(buf);
        sprintf(buf,"%s %s",messages[msg1],msg2);
        //ODS(buf);
        if (OptIdra)  ctOutputMessageDiagnostic2(buf, NULL);

      }
#else
      printf("\n%s %s",messages[msg1],msg2);
#endif
  }
}       /* messch */


void messint(msg,val)

/*  Affiche le message de numero 'msg1', suivi de l'entier 'val'.
 *  Affichage systematique sur le cadre dans le cas de l'appel
 *  depuis l'ensemble integre, et en cas d'option verbose
 *  lors de l'appel depuis l'interpreteur de commandes.
 */
int msg;
BINAIRE val;
{       /* messint */
  char buf[10];
  int i,tmp;

  if (Optintegre) {
#ifdef buf_cico
    x_bstart();
#endif
    pos(IL_0,IC_0+2);
    x_putch(' ');
    x_cprintf(messages[msg]);
    sprintf(&buf[0]," %u ",val);
    x_cprintf(&buf[0]);
    tmp = Xstrlen(messages[msg])+Xstrlen(&buf[0]);
    for (i=0 ; i < IC_5-IC_0-10-tmp ; i++)
      x_putch(C_LNH);
#ifdef buf_cico
    x_bflush();
#endif
  }
  else {
    if (verbose)
#ifdef WIN1632
      { BYTE buf[256];
        sprintf(buf,"\r\n%s %u",messages[msg],val);
        x_cprintf(buf);
        sprintf(buf,"%s %u",messages[msg],val);
        //ODS(buf);
        if (OptIdra)  ctOutputMessageDiagnostic2(buf, NULL);

      }
#else
      printf("\n%s %u",messages[msg],val);
#endif
  }
}       /* messint */


void messlong(msg,val)

/*  message en cours de traduction, si l'option 'verbose' est active
 */
int msg;
long int val;
{       /* messlong */
  if (!Optintegre && verbose)
#ifdef WIN1632
    { BYTE buf[256];
      sprintf(buf,"\r\n%s %lu",messages[msg],val);
      x_cprintf(buf);
      sprintf(buf,"%s %lu",messages[msg],val);
      //ODS(buf);
      if (OptIdra)  ctOutputMessageDiagnostic2(buf, NULL);

    }
#else
    printf("\n%s %lu",messages[msg],val);
#endif
}       /* messlong */


void outbin(ln,cl,val)

/*  edition d'une valeur numerique en cours de traduction
 */
int ln,cl,val;
{       /* outbin */
  char  *p,*q,c,valeur[6],valcad[6];
  unsigned int  n;

  p = q = &valeur[0]; n = (unsigned) val;
  do {
    *p++ = inttocar(n % 10);
  }
  while ((n /= 10) != 0);
  *p = EOSTR;
  while (q < --p) {
    c = *q; *q++ = *p; *p = c;
  }
  Xstrcpy(&valcad[0],"     ");
  Xstrcpy(&valcad[5-Xstrlen(&valeur[0])],&valeur[0]);
  pos(ln,cl);
  x_cprintf(&valcad[0]);
}       /* outbin */


void outlong(ln,cl,val)

/*  edition d'une valeur numerique (longue) en cours de traduction
 */
int ln,cl;
long int val;
{       /* outlong */
  char  *p,*q,c,valeur[8],valcad[8];
  unsigned long int n;

  p = q = &valeur[0]; n = (unsigned long int) val;
  do {
    *p++ = inttocar(n % 10L);
  }
  while ((n /= 10L) != 0L);
  *p = EOSTR;
  while (q < --p) {
    c = *q; *q++ = *p; *p = c;
  }
  Xstrcpy(&valcad[0],"       ");
  Xstrcpy(&valcad[7-Xstrlen(&valeur[0])],&valeur[0]);
  pos(ln,cl);
  x_cprintf(&valcad[0]);
}       /* outlong */


const char* GetUserMessage(noMes)
  int noMes;
{
  if (noMes <= NBMESS ) 
    return messages[noMes];
  else
    return 0;
}

void EditFileName(void)
{
#ifdef WIN1632
  if (OptIdra) ctOutputMessageDiagnostic2 (ncurfic, NULL);
#endif
}

void FreeProtection(void)
{
#ifdef WIN1632
  clFreeResource (requestHandle);
#endif
}
/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
///////////////////////////////////
void SET_PUSHBACK(char * sProcName)
{
  char buf[256]; 
  if (gboolIsPushBack){
sprintf(buf,"Internal error (%s) %s ",sProcName,messages[msgabort]);
x_cprintf(&buf[0]);
  }
  gboolIsPushBack = TRUE;
}
#endif
/* #AT: 29/02/00, EXA-57 (end)*/
