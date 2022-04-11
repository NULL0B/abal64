
/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : LEXICAL.C
 *      Version : 2.2b
 *      Date    : 28/09/86
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Analyseur lexical]
 *
 */

 /*
 * Mises a jour :
 * ------------
 * 18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 * 23/08/90 : Autorise \ dans une chaine pour entrer un backslach ou
 *            un code ASCII exprime en decimal
 * 27/08/90 : Introduction appel depuis ensemble integre 1.4
 * 30/08/90 : Notion de repertoire de recherche des fichiers a inclure
 * 03/09/90 : Introduction option /b
 * 14/09/90 : Permet plus de 200 lignes de commentaires en continu sans
 *            declencher un debordement de pile
 * 19/09/90 : Contournement bug bibli C / Amenesik / Sologic et lecture caractere FF
 * 20/09/90 : Propagation modif erreur sur fichier liste a postick
 * 24/10/90 : Introduction /N pour version 1.4
 * 03/12/90 : Reprise modif 23/08/90. C'est un \\ qui est requis !
 * 14/01/91 : Changement de caractere \\ devient &&
 *            Evite double fermeture du lexical en cas d'erreur fatale
 * 16/01/91 : Prise en compte de l'effacement de reponse sur #rdef
 * 28/01/91 : Accepte &&010 dans une constante chaine de caracteres
 * 31/01/91 : Adaptation reprac a VMS : accepte les noms logiques
 * 13/02/91 : Accepte &_toto comme etiquette
 * ---------- Sortie 1.2f / 1.3c / 1.4a -----------------------------
 * 20/08/91 : Rallongement des tables type et mode de passage des
 *            arguments des fonctions externes pour support du nombre
 *            d'arguments variable
 * 25/10/91 : Accepte lignes de 320 caracteres et non 319
 * ---------- Sortie 1.2g / 1.3d --------------------------------------
 * 26/12/91 : Suppression minuscules accentuees dans les sources
 *	---------- Sortie 1.4b (sauf DOS etendu) ---------------------------
 *	10/07/92 : Affichage du #rdef par putch au lieu de printf pour
 *		   contourner un bug Phar Lap, dans la version DOS etendu
 *	20/07/92 : modif correction 10/07/92
 *	----------- Version 2.1 --------------------------------------------
 *	21/07/93 : PRAGMA : PRIVATE_VARIABLE,TOKEN_SIZE
 *	31/08/93 : PRAGMA : PAGESIZE valeur quelconque
 *	03/09/93 : liberation de la ligne lexicale : ligne : finlex()
 *	24/02/93 : regression en mode mise au point (decalage offset)
 *	------- 2.1c --------------------------------------------------------
 *	20/06/94 : 2 nouveaux pragmas qui active (des..) la conversion en BCD
 *		   des constantes binaires.
 *	25/08/94 : autorise les numeros de fct user > 255
 *	16/11/94 : Reprise sur erreur ouverture fichier include traitincl et
 *		   ouinon.
 *	17/11/94 : probleme blocage des fichiers include et def sous unix
 *		   liberlox()
 *	17/11/94 : probleme #include fic	;-s
 *		   getstr ne prend pas seulement le nom de fichier !!!
 *	------- 2.1d--------------------------------------------------------
 *	19/09/95 : TOKENSIZE en plus de TOKEN_SIZE pour bug doc 
 *	22/11/95 : version dediee 2.1
 *	11/12/95 : on se passe de ftell sous DOS et PROLOGUE
 *	10/08/96 : adaptations Windows
 *	28/09/96 : traitement correct du #RDEF sous Windows
 *	------------ 2.2a -------------------------------------------------
 * 23/04/97 : PRAGMA : OPTIMISE TABLES ON/OFF
 * 16/07/97 : PRAGMA : ENHANCED DEBUG ON/OFF
 * 24/10/97 : PRAGMA : ZONE
 * 22/03/97 : Parametre ! dans les BDA
 * 10/04/98 : Modification de la fonction preprocess (pour #ONCE)
 * 27/05/98 : Correction #pragma tokensize
 * 22/11/99 : (#AT) Enhancement ATR ??: BINARY function.
 * 10/05/00 : (#OK) Enhancement ATR 19: Commentaires multilignes.
 * -------------------------------------------------------------------------
 * 29/02/00 : (#AT) Amelioration EXA-57 - LOAD.GO modifications for ABAL v.2.2a
 * -------------------------------------------------------------------------
 * 05/09/00 : (#OK) ALD 7:  #pragma LOCAL_CONSTANT 
 * 29/03/01 : (#OK) Bug EXA-139 fixed. Problem was with #pragma KEYBOARD_FLUSH.
 * 17/06/02 : (#OK) Bug "Incorrect WDG-file" fixed.
 *	------------ 2.2b -------------------------------------------------
 */	

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"
#include "tcode.h"

#define _LEXICAL
#include "lexical.hs"
#include "lexical.he"

#include "fn_parse.c"

/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
#include "expr.he"
#endif
/* #AT: 29/02/00, EXA-57 (end)*/


#ifdef WIN32
	/* ctType.h inclue Windows.h, le define permet d'éviter toutes
	   les définitions de Windows.h */	
	#define _WINDOWS_
#endif


#include "cttype.h"
#include "watrmess.h"

void lexical();
void xlexical();
/* #AT: 22/11/99 (begin)*/
#ifdef __ATR22__
char getcar();
#endif
/* #AT: 22/11/99 (fin)*/

/*
        Enregistrement des codes lexicaux
        Pour restitution plus tard, si echec dans l'analyse syntaxique
        Seul les codes simples sont sauvegardes ( mots cle, separateur)
*/

/*      Definition de la file de memorisation du lexical */

#define MAXFILE 20
static Code_Synt filelex[MAXFILE];

static int wrfilephysique=0;            /* pointeur en ecriture */
static int wrfilelogique=0;             /* pointeur en ecriture */
static int rdfilelogique=0;             /* pointeur en lecture  */

#define MAXMQ 20
static int pilemq[MAXMQ];
static int ptpilemq=0;

#define WRFILE 0
#define RDFILE 1
static int etatlogique;

/*      Etat de l'analyseur lexical     */

#define LEX_MEMO 1      /* Etat de memorisation des lexicaux    */
#define LEX_RESUME 2    /* Etat de restauration des lexicaux jqa fin de file */
#define LEX_STD 3       /* Etat standard : idem 1.4 */

int etatlex=LEX_STD;    /*      Etat de l'analyseur lexical     */

/*
 * Gestion de la file physique
 */

static void initfilephysique()
{
int i;
        wrfilephysique=0;

        for ( i=0; i<MAXFILE; i++)
                filelex[i]=0;

}       /* initfilelex */


static BOOL filephysiquevide()
{
        return( (wrfilephysique == 0) ? TRUE : FALSE );
}


static BOOL filephysiquepleine()
{
        return( (wrfilephysique == MAXFILE) ? TRUE : FALSE );
}


static void writefilephysique(lex)
Code_Synt lex;
{
        if ( filephysiquepleine() == TRUE ) {
#ifndef WIN1632
                printf("<<< FILE PHYSIQUE PLEINE >>>\n");
#endif
                return;
        }
        filelex[wrfilephysique++]=lex;
}


/*
 * Gestion des files logiques
 */

static void initfilelogique(mode, pos)
int mode;
int pos;
{
        switch (mode)  {
                case WRFILE:
                        etatlogique=WRFILE;
                        wrfilelogique=pos;
                        break;
                case RDFILE:
                        etatlogique=RDFILE;
                        rdfilelogique=pos;
                        break;
        }
}


static BOOL filelogiquevide()
{
        switch(etatlogique) {
                case WRFILE:
                        return( (wrfilelogique >= wrfilephysique) ? TRUE : FALSE );
                case RDFILE:
                        return( (rdfilelogique >= wrfilephysique) ? TRUE : FALSE );
        }
}


static BOOL filelogiquepleine()
{
        return( filephysiquepleine() );
}


static Code_Synt readfilelogique()
{
        switch(etatlogique) {
                case WRFILE:
                        return( filelex[wrfilelogique++] );
                case RDFILE:
                        return( filelex[rdfilelogique++] );
        }
}


static void writefilelogique(lex)
Code_Synt lex;
{
        if ( wrfilelogique == wrfilephysique )
                writefilephysique(lex);

        wrfilelogique++;
}


/*
 * Gestion de la pile des marqueurs de file logique
 */

static void initpilemq()
{
        ptpilemq=0;
}


static BOOL pilemqvide()
{
        return( (ptpilemq==0) ? TRUE : FALSE );

}


static void pushmq(mq)
int mq;
{
        pilemq[ptpilemq++]=mq;

}


int popmq()
{
        return(pilemq[--ptpilemq]);
}


int readmq()
{
        return(pilemq[ptpilemq-1]);
}


/*
 * Etat de la machine lexicale
 */

void standardlex()
{
        etatlex = LEX_STD;
        initfilephysique();
        initpilemq();
}


void memolex()
{
int pos;
        switch ( etatlex ) {
                case LEX_STD:
                        pos=0;
                        break;
                case LEX_MEMO:
                        pos=wrfilelogique-1;
                        break;
                case LEX_RESUME:
                        pos=rdfilelogique-1;
                        break;
        }
        etatlex=LEX_MEMO;
        pushmq(pos);
        initfilelogique(WRFILE, pos);
        writefilelogique(usc.code);
}


void resumelex()
{
int pos;
        switch ( etatlex ) {
                case LEX_STD:
#ifndef WIN1632
                        printf("<<< ERREUR STD->RESUME >>>");
#endif
                        return;
                case LEX_MEMO:
                        break;
                case LEX_RESUME:
                        break;
        }
        pos=popmq();
        initfilelogique(RDFILE, pos);
        etatlex=LEX_RESUME;
        usc.code=readfilelogique();
}


void mlexical()
{
        if ( filelogiquevide() == TRUE ) {
                xlexical();
                writefilelogique(usc.code);
        } else {
                usc.code = readfilelogique();
        }
}


void rlexical()
{
        if ( filelogiquevide() == TRUE ) {
                if ( pilemqvide() == TRUE ) {
                        standardlex();
                        xlexical();
                } else {
                        initfilelogique(RDFILE, popmq());
                        etatlex=LEX_RESUME;
                        usc.code=readfilelogique();
                }
        } else {
                usc.code = readfilelogique();
        }
}


void lexical()
{
/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
  if (WAS_PUSHBACK) { RESET_PUSHBACK; return;}
#endif
/* #AT: 29/02/00, EXA-57 (end)*/
        switch ( etatlex ) {
                case LEX_STD:
                        xlexical();
                        break;
                case LEX_MEMO:
                        mlexical();
                        break;
                case LEX_RESUME:
                        rlexical();
                        break;
        }
}

static BOOL verrue_pre = FALSE;

/*              Corps principal du lexical                              */
/*              --------------------------                              */


void xlexical()

/*      Met a jour l'unite syntaxique courante a chaque appel
 *
 *      Peut arreter la traduction sur fin anormale du source, ou sur
 *      erreur d'entree/sortie sur le fichier source.
 *
 *      Dans tous les cas la variable globale usc : unite syntaxique courante,
 *      est affectee du resultat.
 *      Si le code de usc est ILLEGAL, l'erreur a deja ete signalee par le
 *      lexical.
 */
{                                       /* lexical */
        char c;         /* caractere courant */
        BOOL end;

 end = FALSE;
 NDBLN = TRUE;
 while (!end) {
   end = TRUE;
   if (!fmt_verrue) {
        c = getcar();           /* 1er car non blanc suivant */

        NDBLN = TRUE;
        if (isdebidt(c))        /* debut identificateur, motcle ou fct util. */
                getident(c);
        else if (isdigit(c)) {  /* chiffre = debut de constante numerique */
                getnum(c);
        }
        else {                  /* autres cas => separateur ou operateur */
          switch (c) {
            case '"':           /* constante chaine */
                getchn(); break;
            case '(':           /* parenthese gauche */
                usc.code = PAG; break;
            case ')':           /* parenthese droite */
                usc.code = PAD; break;
            case '=':           /* operateur d'affectation ou egalite */
                c = nextcar();  /* il faut quand meme voir le car suivant */
                if (c == '=') { /* pour le cas "egalite de chaines" */
                        usc.code = EQSTR; break;
                }
                remettre();     /* sinon on en a trop lu ! */
                usc.code = EGAL; break;
            case ',':           /* separateur virgule */
                usc.code = VIG; break;
            case '+':           /* operateur d'addition */
                usc.code = PLUS; break;
            case '-':           /* operateur de soustraction */
                usc.code = MOINS; break;
            case '*':           /* operateur de multiplication */
                usc.code = MUL; break;
            case '/':           /* operateur de division ou constante hexa */
                if (div_verrue)
                        usc.code = DIV;
                else
                        gethex();
                break;
            case '<':           /* relation "inferieur a" */
                c = nextcar();  /* il faut quand meme voir le car suivant */
                if (c == '>') { /* pour le cas "different" */
                        usc.code = DIFF;break;
                }
                if (c == '=') { /* et le cas "inferieur ou egal" */
                        usc.code = INFE; break;
                }
                remettre();     /* sinon on en a trop lu ! */
                usc.code = INF; break;
            case '>':           /* relation "superieur a" */
                c = nextcar();  /* il faut quand meme voir le car suivant */
                if (c == '=') { /* pour le cas "superieur ou egal" */
                        usc.code = SUPE;break;
                }
                remettre();     /* sinon on en a trop lu ! */
                usc.code = SUP; break;
            case '.':           /* peut etre separateur decimal pour BCD */
                c = nextcar();  /* donc voir caractere suivant ... */
                remettre();     /* sans le saisir pour le moment */
                if (isdigit(c))
                        getnum('.');    /* OK pour numerique */
                else
                        usc.code = SPT; /* simple point */
                break;
            case '&':           /* etiquette */
                getetq(); break;
            case '#':           /* declarateur binaire 1 octet */
		c=nextcar();
		remettre();
		if (isalpha(c)) {
			preprocess();
			if ( verrue_pre ) {
				usc.code = CSTR;
				usc.v.pval = bufstr;
				verrue_pre = FALSE;
			} else {
		                usc.code = DIESE;
			}
			break;
		} else {
	                usc.code = DIESE; break;
		}
            case '%':           /* declarateur binaire 2 octets */
                usc.code = PCENT; break;
            case '$':           /* declarateur chaine */
                usc.code = STR; break;
            case ':':           /* separateur deux-points */
                c = nextcar();  /* il faut quand meme voir le car suivant */
                if (c == ':') { /* pour le cas separateur d'instructions */
                        usc.code = FDLN; break;
                }
                remettre();     /* sinon on en a trop lu ! */
                usc.code = DPT; break;
            case '?':           /* point d'interrogation */
                usc.code = INTERRO; break;
            case '!':           /* point d'exclamation */
                c = nextcar();  /* il faut quand meme voir le car suivant */
                if (c == '=') { /* pour le cas "non inclusion de chaines" */
                        usc.code = NIN; break;
                }
                remettre();     /* sinon on en a trop lu ! */
                usc.code = EXCLAM; break;
            case ';':           /* commentaire en fin de ligne */
                jmpfdln();
            case '\n':          /* fin de ligne */
                usc.code = FDLN; break;
 		      /* #OK: 10/05/00 (begin) */
            #ifdef __ATR22__
		      case '{':           				
                jmpcomment();
				    lexical();
				    return;     /* passer a la suite */
            #endif  
            /* #OK: 10/05/00 (end) */
            case '\'' :         /* fin de ligne physique mais pas logique */
                jmpfdln();
                NDBLN = FALSE;
                end = FALSE;
                break;
            default:            /* sinon : illegal */
					erreur(USUAL,errlex10);
					usc.code = ILLEGAL;
          }
       }
   }
   else { /* un format est attendu : le rendre comme une chaine */
        NDBLN = TRUE;
        getfmt();
   }
 }
}                                       /* lexical */


/*              Primitives globales de l'analyseur lexical              */
/*              ------------------------------------------              */

void initlex(infile,nbpred)
/*      initialisation de l'analyseur lexical
 */
char *infile;
int nbpred;
{                                       /* initlex */
        int i;
	char buf[LGMXNOM];

        /* Pas de test a partir de la version 1.4 car deja effectue
         * lors de l'analyse de la ligne de commandes.
         */
        NDBLN = TRUE;
        forceupr = TRUE;
        cstbcd_verrue = div_verrue = fmt_verrue = FALSE;
        verrue_user = FALSE;
        nortusr = 0;
        nivincl = nivcond = 0;

	/* Allocation du buffer ligne lexical */
        ligne = Xmalloc(LGLIGNE);
        if (ligne == GenericNULL(char))
		erreur(FATALE,errmem);
	lglignemax = LGLIGNE;
        *ligne = EOSTR;
        lptr = ligne;

	clncur = 0;

        for (i = nbpred ; i < MAXSYMB; i++)
                tabsymb[i][0] = EOSTR;

        /* Controle existence chemin d'acces */
        if ((fn_parser(infile,buf,1+2) != 0) ||(reprac(infile,buf)))
	{
        	input = Xfopen(infile,"r");
	}
	else {
		inclrecherche('"',lstincl,infile,buf);
        	input = Xfopen(buf,"r");		
	}
	
        if (input == GenericNULL(FILE))
                erreur(FATALE,errlex0);
	poslgn = 0;
	posinsce = 0L;

	/* Activation de tous les mots cles par defaut */
/* #BG 26/11/02	for (i = 0; i < Max_KEY; i++ ) */
	for (i = 0; i <= Max_KEY; i++ )
		ActKeyWords[i]=TRUE;
#ifndef __STRUCT__	/* Structures */
		ActKeyWords[STRUCT]=FALSE;
		ActKeyWords[ENDSTRUCT]=FALSE;
		ActKeyWords[WITH]=FALSE;
		ActKeyWords[ENDWITH]=FALSE;
#endif
	verrue_activekey = IDENT;

	bcd_priority = TRUE;

        lexinit = TRUE;
}                                       /* initlex */


void finlex(force)

/*      fin de travail du lexical : fermeture des fichiers sources
 */
BOOL    force;
{                               /* finlex */
        if (!lexinit)
                return;
        if (nivincl != 0) {             /* arrive en cours d'inclusion */
                if (!force)
                        erreur(WARNING,errlex22); /* ce qui merite un signal */
                while (nivincl) {               /* fermeture tous fichiers */
                        Xfclose(hinput[--nivincl]);
                        Xfree(incfic[nivincl]);
                }
        }
        if (input != GenericNULL(FILE)) {
                Xfclose(input);         /* fermeture fichier source */
                input = GenericNULL(FILE);
        }
        if ((Optintegre) && (!force))
                affsce(" ",1);          /* plus de source en cours */
        purgelst();                     /* vide la derniere ligne dans le fichier liste */
        if ((nivcond) && (!force))     /* arrive en cours de directive IFDEF */
                erreur(WARNING,errlex23);       /* ca merite aussi un signal */

	/* Liberation de la ligne lexicale */
	Xfree(ligne);

        /* Signale que la fermeture a deja eu lieu : ne pas la refaire */
        lexinit = FALSE;


}                               /* finlex */


void postick(fh)

/*      affiche le nombre necessaire de blancs pour cadrer avec le dernier
 *      caractere etudie dans le source lors de l'edition d'un message d'erreur
 *      sur le fichier designe par fh.
 */
FILE *fh;
{                               /* postick */
        int ptr;
        char *pptr;
        int c;

        pptr = ligne;
        for (ptr = (int) (lptr - pptr); ptr > 0; ptr--) {
                c = (*pptr++ == '\t') ?  '\t' : ' ';
                if (Xfputc(c,fh) == EOF)
                        erreur(FATALE,errwritlst);
        }
}                               /* postick */


void tfdln()

/*      traitement de la fin de la ligne courante
 *      seuls des espaces (blanc ou tabulation) sont acceptes, sauf si le
 *      delimiteur de commentaire ";" apparait.
 *      pour conformite avec la suite des traitements, cette fonction affecte
 *      la valeur "FIN DE LIGNE" a l'unite syntaxique courante
 */
{                               /* tfdln */
        char c;

        c = getcar();           /* car non blanc suivant */
        if (c != '\n') {        /* pas en fin de ligne ? */
           if (c != ';') {      /* si ce n'est pas un commentaire ? */
                if (c == ':') { /* fin de ligne quand meme si '::' */
                        c = nextcar();
                        if (c == ':') {
                                usc.code = FDLN; return;
                        }
                        else
                                remettre();
                }       
                /* #OK: 10/05/00 (begin) */
                #ifdef __ATR22__
                else if (c == '{')  {  
					    jmpcomment(); 
						 tfdln();
					    return;
				       }
                #endif
				    /* #OK: 10/05/00 (end) */
				/* sinon erreur : fin de ligne incorrecte */
                erreur(USUAL,errlex8);
           }
           do           /* puis avancer jusqu'a fin ligne */
                c = nextcar();
           while (c != '\n');
        }
        usc.code = FDLN;
}                               /* tfdln */


void sfdln()

/*      by pass fin de la ligne courante, en tenant compte du cas
 *      ou la ligne courante est vide : deja traitee
 *      pour conformite avec la suite des traitements, cette fonction affecte
 *      la valeur "FIN DE LIGNE" a l'unite syntaxique courante
 */
{                               /* sfdln */
        if ((*lptr) == EOSTR)           /* ligne courante est vide */
                return;         /* c.a.d. : deja en fin de ligne */
        /* sinon : avancer tantque pas FDLN */
        while (*lptr != '\n') {
                if (*lptr++ == ':') { /* cas particulier de '::' */
                        if (*lptr == ':') {
                                lptr++; usc.code = FDLN; return;
                        }
                }
        }
        lptr++; usc.code = FDLN;
}                               /* sfdln */


void jmpfdln()

/*      by pass fin de la ligne courante, en tenant compte du cas
 *      ou la ligne courante est vide : deja traitee, mais sans tenir
 *      compte de l'eventuel separateur '::' ....
 *      pour conformite avec la suite des traitements, cette fonction affecte
 *      la valeur "FIN DE LIGNE" a l'unite syntaxique courante
 */
{                               /* jmpfdln */
        if ((*lptr) == EOSTR)           /* ligne courante est vide */
                return;         /* c.a.d. : deja en fin de ligne */
        while (*lptr++ != '\n');
        usc.code = FDLN;
}                               /* jmpfdln */

/* #OK: 10/05/00 (begin) */
#ifdef __ATR22__
void jmpcomment()
{                               /* jmpcomment */	            
  levelCommentary++;

  while (levelCommentary)
	{
     while (((*lptr) != '\n') && levelCommentary)
		{
		  clncur++;		  
		  switch (*lptr++)
		  {
		     case '{': levelCommentary++; break;
 			 case '}': levelCommentary--; break;
		  }		  
		}
       
	  if (!levelCommentary) break;
		
	  lptr = Xfgets(ligne, lglignemax, input); /* lire ligne suivante */

      clncur = 0;
 
      if (lptr == GenericNULL(char)) 
         if (Xfeof(input)) erreur(FATALE,errlex25);  /* lecture impossible */
      
	  /* Met a jour la position absolue dans le fichier source,
	  * en tenant compte du saut de ligne :
	  *	LgCRLF = 1 sous Unix et VMS, 2 sous DOS et Amenesik / Sologic
	  *	et \n vaut 1 caractere dans la chaine.
	  */
	  posinsce += ((long int)(Xstrlen(lptr)-1))+LgCRLF;


	  lgnfic++;     	  
	}
}                               /* jmpcomment */
#endif
/* #OK: 10/05/00 (end) */


/*              Primitives internes de l'analyseur lexical              */
/*              ------------------------------------------              */

static void getident(c)

/*      recherche d'un identificateur, d'un mot-cle ou
 *      d'une fonction utilisateur dont le premier
 *      caractere est communique en parametre.
 */
char c;
{                               /* getident */
        char *pnom;
		BOOL isLongKeyword; /*SG*/

	verrue_activekey = IDENT;

        nom[0] = c;             /* debut du nom ... */
        pnom = &nom[1];
        isLongKeyword= buildidt(pnom);         /* construction du nom */
        /* recherche prioritaire d'un mot reserve du langage */
        if ((!isLongKeyword) && (isnotakey(nom))) {
                if (isnotausr(nom)) {
                        /* traitement du cas particulier A0 = A */
                        if ((Xstrlen(nom) == 2) && (nom[1] == '0'))
                                nom[1] = EOSTR;
                        usc.code = IDENT;
                        usc.v.pval = nom;
			c=nextcar();
			if ( c == '.' ) {
				usc.excode = MODULE;
			} else {
				if ( usc.code != IDENT )
					usc.excode = 0;
				remettre();
			}
                } else
			usc.excode = 0;
        }
        else {
                usc.v.pval = nom;
		usc.excode = 0;
	}
}                               /* getident */


static BOOL buildidt(p)

/*      construction d'un identificateur par lecture du source
 */
char *p;
{                               /* buildidt */
		/*SG  27/05/98 : modification de la fonction*/
		/*Les mots clés etaient tronqués, comme les ident. dans le cas */
		/*lentokmax=8 (Pragma tokensize=8)*/
		/*retourne desormais un BOOL   Ident = mot cle -> True*/
      char c;
		char *q;
      BYTE l;
		BOOL isLongKeyword;
		int i;
		isLongKeyword = FALSE;
#ifdef USE_LONG_NAMES // Non défini
		char longName[255];
#endif
        l = 2;
        c = nextcar();
		  q = p;
        while (isalnum(c) || c == '_') { /* lettre, chiffre ou souligne */
			    /* #OK: 17/06/02 (begin) */
			    if (l < /*lentokmax*/LGIDENT) { /* uncommented */
						*p++ = c;
                        l++;
                } /* uncommented */
				/* #OK: 17/06/02 (end) */
                c = nextcar();
        }
		
        remettre();     /* on a lu un car de trop */
        *p = EOSTR;     /* terminateur de chaine */

		/* nouveau debut SG*/
		
		if (l>=lentokmax) // on verifie si c'est un mot cle long
		{
			isLongKeyword=!(isnotakey(nom));			
		

			if (!isLongKeyword) //identificateur long -> on le raccourcit
			{
#ifdef USE_LONG_NAMES // Non défini
		/* GESTION DES NOMS LONGS: DLL de JPH */
		/* Reconstitution du nom ,	la première lettre a deja ete mangee */
		longName[0] = nom[0];
		i = 1;
		p = q;
		while (*p)
			longName[i++] = *p++;
		longName[i] = '\0';

		lnLongToShort2 (longName,shortName,sizeof(shortName));
		shortName[sizeof(shortName)-1] = '\0';
		p = q;
		i = 2;

		while (i < LGIDENT)
		{
			*p++ = shortName[i-1];
			i++;
		}
		*p++='\0';
		p = q;
#else
		for (i=2;i<lentokmax;i++)
			q++;
		*q = EOSTR;
		p = q;
		l = lentokmax-1;
#endif				

			}
		}
		return isLongKeyword;
		/* nouveau fin SG*/
}                               /* buildidt */


static BOOL isnotakey(p)

/*      recherche dans la table des mots reserves si l'ident pointe par p
 *      existe, et si oui lui affecte son code syntaxique pour le retour.
 */
char *p;
{                               /* isnotakey */
	Code_Synt c;
	int i;
	Code_Synt maxKEY, minKEY;
	char     cc;

	minKEY = First_KEY; maxKEY = Last_KEY; c = maxKEY / 2;

	do {
		i = Xstrcmp(p,KeyWords[c]);
		if (i == 0) {   /* trouve ! */
			if (c == CHR) { /* cas particulier de CHR$ !! */
				cc = nextcar();
				if (cc != '$') { /* non : ident CHR */
					remettre(); return(TRUE);
				}
			}
			else if (c == LDGOSEG) { /* cas du LDGO.SEG */
				if (!lookseg())
					return(TRUE);
			}
			else if (c == RETSEG) { /* cas du RET.SEG */
				if (!lookseg())
					return(TRUE);
			}
			else if (c == LOADGO) { /* cas du LOAD.GO */
				if (!lookgo())
					return(TRUE);
			}
			else if (c == READ) { /* cas du READ=0 */
				if (looknl0()) {
					usc.code = READMEM; return(FALSE);
				}
			}
			else if (c == BACKSPACE) { /* cas du BACKSPACE */
				cc = *(lptr-1); cc = toupper(cc);
				if (cc != 'E') /* on vient de remettre E ? */
					return (TRUE); /* sinon c'est un ident */
			}

			/* Traite le cas de l'instruction END.SEG */
			else if (c == END) {
				if (lookseg())
					c = ENDSEG;
				else if (lookproc())
					c = ENDDPTPROC;
				else if (lookuser())
					c = ENDUSER;
			}

			/* Si l'option /b a ete utilisee, les mots-cles des
			* fonctions mathematiques ne sont plus reserves
			* de facon a pouvoir etre surcharges avec les
			* definitions d'une bibliotheque dynamique
			*/
			else if (ignore_BL) {
				switch(c) {
					case ATN :
					case COS :
					case EXP :
					case LOG :
					case SIN :
					case SQR :
					case TAN :
					return(TRUE);
				}
			}

			/* Si le mot est desactive ne pas le reconnaitre */
			if ( ActKeyWords[c] == FALSE ) {
				verrue_activekey = c;
				return (TRUE);
			}

			usc.code = c;
			return (FALSE);
		}
		else {
			if (i < 0) { /* chercher plus petit */
				maxKEY = c - 1;
			}
			else { /* chercher plus grand */
				minKEY = c + 1;
			}
		
			c = (minKEY + maxKEY) / 2;
		}
	}
	while (minKEY <= maxKEY);

	return (TRUE);
}                               /* isnotakey */


static BOOL isnotausr(p)

/*      Recherche dans la table des fonctions utilisateur
 *      si l'ident pointe par p existe
 */
char *p;
{                               /* isnotausr */
        Tbusr   *s;
        int i;

        s = RacTbusr;           /* debute a la racine de l'arbre */
        while (s != GenericNULL(Tbusr)) {
                i = Xstrcmp(p,s->nom);
                if (i < 0)
                        s = s->g;       /* avant, on part a gauche */
                else if (i > 0)
                        s = s->d;       /* apres, on part a droite */
                else {                  /* on a trouve */
                        usc.code = FUSER;
                        usc.v.ptusr = s;
                        return(FALSE);
                }
        }
        return(TRUE);
}                               /* isnotausr */


static BOOL looknl0()

/*      Pour le cas de READ, cette fonction verifie que la suite
 *      n'est pas '=0' afin de distinguer READ de READMEM.
 */
{                               /* looknl0 */
        char    cc;
        int     nb;

        cc = nextcar();
        if (cc != '=') {
                remettre(); return (FALSE);
        }
        cc = nextcar(); nb = 2;
        while (isblanc(cc)) {
                cc = nextcar(); nb++;
        }
        if (cc != '0') {
		nremettre(nb); return(FALSE);
	}
        cc = nextcar(); remettre();
        /* test du cas READ=01 ... */
        if (isdigit(cc)) {
		nremettre(nb); return(FALSE);
        }
        return (TRUE);
}                               /* looknl0 */


static BOOL lookseg()

/*      Pour le cas de LDGO et RET, cette fonction verifie que la suite
 *      est bien '.SEG' afin de completer le mot reserve
 */
{                               /* lookseg */
        char    cc;

        cc = nextcar();
        if (cc != '.') {
                remettre(); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'S') {
		nremettre(2); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'E') {
		nremettre(3); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'G') {
		nremettre(4); return (FALSE);
        }
        return (TRUE);
}                               /* lookseg */


static BOOL lookproc()

/*      Pour le cas de END.PROC, cette fonction verifie que la suite
 *      est bien '.PROC' afin de completer le mot reserve
 */
{                               /* lookproc */
        char    cc;

        cc = nextcar();
        if (cc != '.') {
                remettre(); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'P') {
		nremettre(2); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'R') {
		nremettre(3); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'O') {
		nremettre(4); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'C') {
		nremettre(5); return (FALSE);
        }
        return (TRUE);
}                               /* lookproc */


static BOOL lookuser()

/*      Pour le cas de END.USER, cette fonction verifie que la suite
 *      est bien '.USER' afin de completer le mot reserve
 */
{                               /* lookuser */
        char    cc;

        cc = nextcar();
        if (cc != '.') {
                remettre(); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'U') {
		nremettre(2); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'S') {
		nremettre(3); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'E') {
		nremettre(4); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'R') {
		nremettre(5); return (FALSE);
        }
        return (TRUE);
}                               /* lookuser */


static BOOL lookgo()

/*      Pour le cas de LOADGO cette fonction verifie que la suite
 *      est bien '.GO' afin de completer le mot reserve
 */
{                               /* lookgo */
        char    cc;

        cc = nextcar();
        if (cc != '.') {
                remettre(); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'G') {
		nremettre(2); return (FALSE);
        }
        cc = nextcar();
        if (cc != 'O') {
		nremettre(3); return (FALSE);
        }
        return (TRUE);
}                               /* lookgo */


BOOL lookexpstr()

/*      Regarde si un caractere '+' ou '!' suit une constante chaine
 *      ce qui serait le signe d'une expression chaine.
 *      (Dans le PRINT, les constantes chaines sont traitees a part.)
 *      Dans tous les cas, le caractere lu est remis en place
 */
{                               /* lookexpstr */
        char cc;

        cc = getcar();          /* 1er caractere suivant NON BLANC */
        remettre();

        return((cc == '+' || cc == '!') ? (TRUE) : (FALSE));
}                               /* lookexpstr */


static void gethex()

/*      recherche d'une constante hexadecimale qui est traduite en
 *      notation BCD si le contexte l'exige (flg 'cstbcd_verrue')
 */
{                               /* gethex */
        int i = 1;
        char *p;
        char c,*q,*r;

        usc.v.val = 0;
        c = nextcar();
        while (isxdigit(c) && (i++ <= MXDGCHEX))
                usc.v.val = (usc.v.val << 4) + cartohex(c), c = nextcar();
        if ((i > (MXDGCHEX+1)) || (i == 1))
                erreur(USUAL,errlex12);
        remettre();     /* trop lu */
        if (cstbcd_verrue) {    /* forcer une constante BCD */
                p = q = bufstr; i = 1;  /* ajouter signe a la longueur */
                do {
                        *p++ = inttocar(usc.v.val % 10); i++;
                }
                while ((usc.v.val /= 10) > 0);
                r = p;
                while (q < --p) {
                        c = *q; *q++ = *p; *p = c;
                }
                if ((i % 2) != 0) { /* lg impaire : ajouter un terminateur */
                        *r = inttocar(BCD_FIN); i++;
                }
                else if (i < (LGBCD*2)) { /* lg paire et inf.au max possible */
                        *r++ = inttocar(BCD_FIN); *r++ = '0'; i += 2;
                }
                cvascnum(FALSE,i);
        }
        else
                usc.code = CBIN;
}                               /* gethex */


static void getnum(c)

/*      recherche d'une constante numerique dont le premier caractere
 *      est communique en parametre.
 */
char c;
{                               /* getnum */
        char *pbuf = bufstr;
        char cc;
        int lg = 2;     /* forcement signe + 1er digit pour un BCD */
        BOOL v = FALSE;

        cc = nextcar();
        /* Traite 0.xxx comme .xxx -> produit CAxxx et non C0Axxx */
        if ((c == '0') && (cc == '.')) {
                c = '.';
                cc = nextcar();
        }
        if (c == '.') {         /* constante commence par separateur decimal */
                v = TRUE; *pbuf++ = inttocar(BCD_SEP);
                if (!isdigit(cc)) {
                        erreur(USUAL,errlex14); usc.code = ILLEGAL;
                        return;
                }
                do
                        *pbuf++ = cc, lg++, cc = nextcar();
                while (isdigit(cc));
        }
        else {
                *pbuf++ = c;
                while (isdigit(cc))
                        *pbuf++ = cc, lg++, cc = nextcar();
                if (cc == '.') {        /* il y a une partie decimale */
                        v = TRUE; *pbuf++ = inttocar(BCD_SEP);
                        lg++; cc = nextcar();
                        if (!isdigit(cc)) {
                                erreur(USUAL,errlex14); usc.code = ILLEGAL;
                                return;
                        }
                        do
                                *pbuf++ = cc, lg++, cc = nextcar();
                        while (isdigit(cc));
                }
        }
        if ((lg % 2) != 0) {    /* lg impaire : ajouter un terminateur */
                *pbuf++ = inttocar(BCD_FIN); lg++;
        }
        else if (lg < (LGBCD*2)) { /* lg paire et inferieure au max possible */
                *pbuf++ = inttocar(BCD_FIN); *pbuf++ = '0'; lg += 2;
        }
        if (lg > (LGBCD*2)) {   /* pas de representation possible */
                erreur(USUAL,errlex14); usc.code = ILLEGAL;
                return;
        }
        remettre();             /* remettre dernier caractere lu */
        cvascnum(v,lg);         /* conversion du buffer */
}                               /* getnum */


static void cvascnum(v,lg)

/*      conversion d'un numerique en ASCII dans le buffer 'bufstr'
 *      et mise a jour de l'unite syntaxique courante, en fonction
 *      du resultat (constante binaire ou BCD)
 */
BOOL v;
int lg;
{                               /* cvascnum */
        char *p1 = bufstr;
        BYTE *p2 = bufbcd;
        BYTE *p3;
        short cpt;
        long resbin = 0;
        BYTE digit;

        if (!cstbcd_verrue) /* pas de BCD force par l'appelant */
           if ((!v) && (lg < 9)) { /* pas de virgule et moins de 8 digits :
                                   peut donc etre un binaire */
                for (cpt=1;
                     ((cpt <= (lg -1)) && (*p1 != inttocar(BCD_FIN))); cpt++) {
                        resbin = (resbin * 10L) + (long) cartoint(*p1); p1++;
                }
                if (resbin <= 65535L) {
                        usc.code = CBIN; usc.v.val = (BINAIRE) resbin;
                        return;
                }
                else
                        p1 = bufstr; /* reprendre buffer pour conversion BCD */
           }
        /* dans tous les cas : arrivee ici implique constante BCD */
        p3 = p2;
        *p2++ = (BYTE) (lg / 2);
        digit = (BYTE) BCD_PLUS;        /* signe tjs positif pour constantes */
        digit |= (BYTE) cartoint(*p1); p1++;
        *p2++ = digit;  /* 1er digit : 2 caracteres traites */
        for (cpt = 2; cpt < lg; cpt += 2) {
                digit = ((BYTE) cartoint(*p1)) << 4; p1++;
                digit |= (BYTE) cartoint(*p1); p1++;
                *p2++ = digit;
        }
        /* Enleve le marqueur de fin de BCD si la longueur est paire */
        if ((*--p2) == (BCD_FIN << 4))
                (*p3)--;

        usc.code = CBCD;
        usc.v.pbcd = bufbcd;
}                               /* cvascnum */


static void getchn()

/*      recherche d'une constante chaine
 */
{                               /* getchn */
        remettre();     /* remettre la guillemet pour getstr */
        usc.v.pval = getstr('"',bufstr,LGCSTR);     /* lire la constante */
        if (usc.v.pval == GenericNULL(char))
                usc.code = ILLEGAL;
        else
                usc.code = CSTR;
}                               /* getchn */


static void getetq()

/*      recherche d'une etiquette == identificateur
 */
{                               /* getetq */
        char    *pnom;
        char    c;

        c = nextcar();

        /* Jusqu'a la version 1.3, on accepte une lettre ou un chiffre
         * en tete. A partir de la version 1.4, on accepte egalement
         * le caractere souligne en tete.
         */
        if ((isalnum(c)) || (c == '_')) {
                nom[0] = c; pnom = &nom[1];
                buildidt(pnom);
                usc.code = ETIQ; usc.v.pval = nom;
        }
        else {
                erreur(USUAL,errlex11);
                usc.code = ILLEGAL;
        }
}                               /* getetq */


static void getfmt()

/*      retourne directement le source comme chaine de format
 */
{                               /* getfmt */
        char c;
        char *p;
        int nbcar = 0, nbpar = 0, nbguil = 0;

        c = getcar();
        if (c == '(') {
           /* commence par une parenthese ouvrante : reference par variable */
           usc.code = PAG; return;
        }

        if (c == ')') { /* ne pas commencer par une parenthese fermante ! */
                usc.code = ILLEGAL; return;
        }
        p = &bufstr[0];
        while (1) {     /* sortie par BREAK     */
                if ((nbcar == LGCSTR) || (c == '\n')) {
                        forceupr = TRUE; usc.code = ILLEGAL; return;
                }
                *p++ = c; nbcar++;
                if (c == '"') {
                        if (forceupr) forceupr = FALSE; else forceupr = TRUE;
                        if (nbguil == 0) nbguil = 1; else nbguil = 0;
                }
                else if ((c == '(') && (nbguil == 0))
                        nbpar++;
                else if ((c == ')') && (nbguil == 0)) {
                        if (nbpar == 0) {
                                p--; break;
                        }
                        nbpar--;
                }
                c = nextcar();
        }
        *p = EOSTR; remettre(); forceupr = TRUE;
        usc.code = CSTR; usc.v.pval = &bufstr[0];
}                               /* getfmt */


/* #AT: 22/11/99 (begin)*/
#ifndef __ATR22__
static char getcar()
#else
char getcar()
#endif
/* #AT: 22/11/99 (end)*/

/*      obtention du caractere non blanc suivant
 */
{                               /* getcar */
        char c;

        do {                    /* by pass des espaces en tete */
                c = nextcar();
        }
        while (isblanc(c));
        return (c);
}                               /* getcar */


static char *getstr(clim,str,lg)

/*      recherche d'une chaine encadree de guillemets, en remplissant le
 *      buffer "str" avec sa valeur, sur une longueur max de "lg" caracteres.
 *      retourne un pointeur sur ce buffer si OK,
 *      retourne NULL sinon, apres avoir signale la cause de l'erreur :
 *                      chaine incorrecte ou chaine trop longue
 */

char clim; /* caractere de limitation */ 
char *str;
int lg;
{                               /* getstr */
        char c;
        char *p;
        int  nb;
        int i,tmp;

        p = str;
        c = getcar();
        if (c != clim) {         /* guillemet ? */
		if ( clim == '\0' ) {
			remettre();
			clim='\n';
		} else {
                	erreur(USUAL,errlex6);
                	return (GenericNULL(char));     /* abandon sinon ... */
		} 
        }

	/* cas particulier : "<" et ">" */
	if ( clim == '<' )
		clim = '>';

        forceupr = FALSE;       /* majuscules <> minuscules dans les chaines */
        nb = 1;
        do {
                c = nextcar();
if ( c == clim ) {
/* double clim -> simple clim dans chaine */
	if (clim != '\n') {
		c = nextcar();
        	if (c == clim) {
        		*p++ = c;
                	nb++;
		} else {
			remettre();
			c = '\n';
		}
	} else {
		remettre();
	}
} 
else if ( c == '\n' ) {
/* fin de ligne trouvee avant le clim fermant */
	remettre();
        forceupr = TRUE;
        erreur(USUAL,errlex8);
        return (GenericNULL(char));
}
else if ( c == '&' ) {
/* backslach -> deux possibilites :
	code entre en decimal
        backslach dans une chaine
        Si le code est entre en decimal, le backslach
        est double.
*/
	c = nextcar();
        if (c != '&') {
        	remettre();
                c = '&';
	} else {
        	for (tmp = 0,i = 0 ; i < 3 ; i++) {
                	c = nextcar();
                        if (!isdigit(c)) {
                        	erreur(USUAL,errlex10);
                                c = '0';
                        }
                        tmp = 10*tmp + cartoint(c);
		}
                if ((tmp == 0) || (tmp > 255)) {
                	erreur(USUAL,errlex15);
                        tmp = '?';
                }
                c = (BYTE) tmp;
	}
        if (nb < lg) {
        	*p++ = c;
                nb++;
                c = '\0';
        } else {
        /* au-dela de la taille limite */
        	forceupr = TRUE;
                erreur(USUAL,errlex9);
                return (GenericNULL(char));
	}
}
else {
/* caractere normal : tient-il dans la chaine ? */
	if (nb < lg) {
        	*p++ = c;
                nb++;
	} else {
        /* au-dela de la taille limite */
		forceupr = TRUE;
        	erreur(USUAL,errlex9);
                return (GenericNULL(char));
	}
}
        } while (c != '\n');

        forceupr = TRUE;

        /* La constante chaine est-elle de longueur nulle ? */
        if (nb == 1) {
                erreur(USUAL,errlex6);
                return (GenericNULL(char));
        }

        *p = EOSTR;

	if ( clim == '\n' ) {
		p = str;
		while ( (*p != '\t') && (*p != EOSTR) && (*p != ' ') && (*p != ';') ) 
			p++;
		*p = EOSTR;
	}
        return (str);
}                               /* getstr */


static char carsuiv()

/*   lecture du caractere suivant dans le fichier source courant,
 *   si le caractere retourne est le premier d'une ligne, l'indicateur DBLN
 *   est positionne avec la valeur TRUE, et FALSE sinon.
 *   la fonction echolst est utilisee pour l'echo de la ligne lue sur fliste
 *   si il est necessaire de lire une nouvelle ligne de source, cette fonction
 *   peut provoquer l'arret de traduction pour l'une des raisons suivantes :
 *      - ligne de source plus longue que LGLIGNE caracteres
 *      - erreur de lecture du fichier source courant
 *   elle retourne le caractere EOSTR si fin de fichier
 */
{                               /* carsuiv */
	if ( *lptr == 0x001A )	/* #IJM 06/11/02 */
		return( EOSTR );

	if ((*lptr) == EOSTR) {                 /* ligne courante est vide */
		/* A partir de la version 1.4, l'ecriture effective
		 * de la ligne courante dans le fichier liste a lieu
		 * lors de la lecture de la ligne suivante.
		 */
		purgelst();
		clncur = 0;

		/* Conserve la position absolue dans le fichier source
		 * afin de permettre les retour arriere dans le cadre
		 * de l'analyse des expressions conditionnelles :
		 * on ne peut pas utiliser ftell qui est bugge en C5.10.
		 */
#ifdef msdos
		seekcur = posinsce;
#endif
#ifdef prologue
		seekcur = posinsce;
#endif
#ifdef unix
		seekcur = Xftell(input);
#endif
#ifdef vms
		seekcur = Xftell(input);
#endif
		lptr = Xfgets(ligne, lglignemax, input); /* lire ligne suivante */
		if (lptr == GenericNULL(char)) {
			if (Xfeof(input))
				return (EOSTR);
			else	return (EOSTR);
			/* erreur(FATALE,errlex2);*/
  /* lecture impossible */
		}

		/* Met a jour la position absolue dans le fichier source,
		 * en tenant compte du saut de ligne :
		 *	LgCRLF = 1 sous Unix et VMS, 2 sous DOS et Amenesik / Sologic
		 *	et \n vaut 1 caractere dans la chaine.
		 */
		posinsce += ((long int)(Xstrlen(lptr)-1))+LgCRLF;
		if (ligne[Xstrlen(lptr)-1] != '\n') {
			erreur(FATALE,errlex3);  /* ligne trop longue */
		}
		DBLN = NDBLN;

		echolst(ligne);
	}
	else {
		DBLN = FALSE; clncur++;
	}
	
	return (*lptr++);               /* retour caractere courant */

}                               /* carsuiv */


static char nextcar()

/*   obtention du caractere suivant dans le fichier source.
 *   cette fonction utilise carsuiv() pour lire un caractere dans le fichier
 *   source courant, elle detecte les lignes de commentaires et les directives
 *   de traduction qu'elle execute independamment.
 *   elle detecte egalement les lignes vides, qui sont considerees comme
 *   des commentaires.
 *   elle peut arreter la traduction dans le cas ou la fin de fichier source
 *   est atteinte alors qu'il n'y a pas d'inclusion en cours.
 *   on refuse les directives lorsqu'on est en train de traiter un #USER
 */
{                               /* nextcar */

        char c;
        int i;
        char *p;

debut:  c = carsuiv();
debut2:   if (c == EOSTR)  /* fin de fichier source en entree */
           if (nivincl == 0 || verrue_user)
                         /* irreparrable si pas en cours d'inclusion */
                         /* ou si en evaluation de #USER */
                erreur(FATALE,errlex1);
           else {        /* sinon reprendre l'ancien source */
		/* Pour reprendre l'ancien source :
		 * 	- fermer le source courant
		 *	- recuperer les informations concernant
		 *	  ce source : nom fichier, position, ...
		 */
		Xfclose(input);
#ifdef unix
		liberlox(ncurfic);
#endif /* unix */
		input = hinput[--nivincl];
		lgnfic = curlgn[nivincl];

		posinsce = pinput[nivincl];
		seekcur = pinput[nivincl];

                Xstrcpy(ncurfic,incfic[nivincl]);
		ncursrc = incsrc[nivincl];
                /* Affiche le nom du source courant */
                if (Optintegre)
                        affsce(ncurfic,1);

                Xfree(incfic[nivincl]);
                ligne[0] = 0;           /* reinit du buffer ligne courante */
                lptr = &ligne[0];
                return (nextcar());     /* et "redo" */
           }
        if (DBLN && NDBLN) {    /* si debut de ligne, traiter les cas speciaux */
           while (isblanc(c))   /* filtrer les blancs et les tabulations en */
                c = carsuiv();  /* debut de chaque ligne */

           if (!verrue_user) {
                switch (c) {
                        case '#':       /* directive de traduction */
                                if (preprocess())           /* la traiter */
									return (nextcar());     /* et "redo" */
								else
								{
									c=EOSTR;
									goto debut2;
								}
                        case '.':       /* commentaire avec saut de page */
                                sautpage();
                                jmpfdln();              /* by pass fin ligne */
                                return (nextcar());     /* et "redo" */
                        case '<':       /* reprendre la liste */
                                retlst(ligne);
                                jmpfdln();
                                return (nextcar());     /* et "redo" */
                        case '>':       /* arreter la liste */
                                suplst(TRUE);   /* prioritaire */
                                jmpfdln();
                                return (nextcar());     /* et "redo" */
                        case '/':       /* comment. + echo force sur stdout */
                                if (Optintegre) {
                                        prepdlig();
                                        p = lptr;
                                        for (i=0 ; (i < IC_5-IC_0-1) && (*p != EOSTR) ; i++) {
                                                x_putch(*p++);
                                        }
                                }
                                else
#ifdef WIN1632
					{ BYTE buf[512];
                                          sprintf(buf,"\r\n%s",lptr);
                                          x_cprintf(buf);
															if (OptIdra)  ctOutputMessageDiagnostic2(lptr, NULL);
					}
#else
                                        printf("\n%s",lptr);
#endif
                        case ';':       /* commentaire simple */
                        case '*':
                                jmpfdln();              /* by pass fin ligne */
                        case '\n':      /* ligne vide */
                                goto debut;
/*                              return (nextcar());*/   /* passer a la suite */
                        
					         /* #OK: 10/05/00 (begin) */
                        #ifdef __ATR22__
						      case '{':							    
                                jmpcomment();              /* by pass fin ligne */
								        return (nextcar());     /* passer a la suite */
                        #endif
                        /* #OK: 10/05/00 (end) */
                   }
                }
                else {
                        switch(c) {
                                case ';':       /* commentaire simple */
                                        jmpfdln();              /* by pass fin ligne */
                                case '\n':      /* ligne vide */
                                        return (nextcar());     /* passer a la suite */
					            
							           /* #OK: 10/05/00 (begin) */
                                #ifdef __ATR22__
						              case '{':
                                        jmpcomment();              /* by pass fin ligne */
								                return (nextcar());     /* passer a la suite */
                                #endif
                                /* #OK: 10/05/00 (end) */
                        }
                }
        }
        if (forceupr)
                c = toupper(c);
        return (c);
}                               /* nextcar */


static BOOL preprocess()

/*      traitement des directives de traduction
retour : TRUE la traduction du fichier courant continue
		FALSE la traduction du fichier courant s'arrete (pour #ONCE)
*/
{              
	/* preprocess */
		BOOL result;
        int     i;
        char    rep,ryes,rno;

		result = TRUE;

        ryes = *yesno;
        rno = *(yesno+1);

        if (!recupidt(USUAL))   /* lire le nom de la directive dans nom */
                return result;         /* et fin si impossible */

		if (strEq(nom,"ONCE")) {
                if (!recupidt(USUAL))
                        return result;
                for (i = 0; i < MAXSYMB; i++)
                        if (strEq(tabsymb[i],nom))  /* trouve ! */
                                break;
				if (i < MAXSYMB) {		/* symbole defini */
					result = FALSE;		/* arret de la traduction */
                    return result;            
                }
                else {                          /* symbole indefini */

					traitdef(TRUE); //si le nom nest pas défini
					return result;
				}
		}
		else
        if (strEq(nom,"INCLUDE")) {
                traitincl(); /* inclusion d'un fichier source */
        }
        else if (strEq(nom,"DEF")) {
                /* definition symbole de traduction conditionnelle */
                if (!recupidt(USUAL))
                        return result;
                traitdef(TRUE);
                return result;
        }
        else if (strEq(nom,"UNDEF")) {
                /* non-definition symbole de traduction conditionnelle */
                if (!recupidt(USUAL))
                        return result;
                traitudef(TRUE);
                return result;
        }
        else if (strEq(nom,"RDEF")) {
                /* lecture definition symbole de traduction conditionnelle */
                if (!recupidt(USUAL))
                        return result;

                /* Interaction utilisateur pour lire la reponse */
                while (TRUE) {
					#ifdef WIN1632 /*SG*/
						//if (OptIdra)
							rep = ouinonInMsgBox(GetUserMessage(msgrdef),ncurfic,nom,ryes,rno,0);
						//else
					#else
							rep = ouinon(msgrdef,nom,ryes,rno);
					#endif
                        if (rep == ryes) {
                                traitdef(FALSE);
                                return result;
                        }
                        if (rep == rno) {
                                traitudef(FALSE);
                                return result;
                        }
                } /* Sortie par O/N */
        }
        else if (strEq(nom,"IFDEF")) {
                /* debut de traduction conditionnelle */
                if (!recupidt(USUAL))
                        return result;
                for (i = 0; i < MAXSYMB; i++)
                        if (strEq(tabsymb[i],nom))  /* trouve ! */
                                break;
                tfdln();
                nivcond++;
                if (i < MAXSYMB) {              /* symbole defini */
                        return result;            /* et continuer */
                }
                else {                          /* symbole indefini */
                    nbemb = 0;        /* traiter l'emboitement des IFDEF */
                    suplst(FALSE);    /* suppression temporaire de la liste */
                    while (1) {       /* by pass du cas "then" */
                         /* boucle sans fin : sortie par return */
                        nextdirective();
                        if (recupidt(WARNING))
                                if (strEq(nom,"IFDEF")) {
                                        nbemb++; sfdln();
                                }
                                if (strEq(nom,"IFNDEF")) {
                                        nbemb++; sfdln();
                                }
                                else if (strEq(nom,"ENDIF")) {
                                        if (nbemb != 0) {
                                                sfdln(); nbemb--; continue;
                                        }
                                        tfdln();
                                        nivcond--;      /* fin trad. cond. */
                                        retlst(ligne);
                                        return result;
                                }
                                else if (strEq(nom,"ELSE") && (nbemb == 0)) {
                                        tfdln();
                                        retlst(ligne);
                                        return result;
                                     }
                                else
                                        sfdln();
                    }
                }
        }
        else if (strEq(nom,"IFNDEF")) {
                /* debut de traduction conditionnelle */
                if (!recupidt(USUAL))
                        return result;
                for (i = 0; i < MAXSYMB; i++)
                        if (strEq(tabsymb[i],nom))  /* trouve ! */
                                break;
                tfdln();
                nivcond++;
                if (i == MAXSYMB) {        /* symbole indefini */
                        return result;            /* et continuer */
                }
                else {                  /* symbole defini */
                    nbemb = 0;        /* traiter l'emboitement des IFDEF */
                    suplst(FALSE);    /* suppression temporaire de la liste */
                    while (1) {       /* by pass du cas "then" */
                         /* boucle sans fin : sortie par return */
                        nextdirective();
                        if (recupidt(WARNING))
                                if (strEq(nom,"IFDEF")) {
                                        nbemb++; sfdln();
                                }
                                if (strEq(nom,"IFNDEF")) {
                                        nbemb++; sfdln();
                                }
                                else if (strEq(nom,"ENDIF")) {
                                        if (nbemb != 0) {
                                                sfdln(); nbemb--; continue;
                                        }
                                        tfdln();
                                        nivcond--;      /* fin trad. cond. */
                                        retlst(ligne);
                                        return result;
                                }
                                else if (strEq(nom,"ELSE") && (nbemb == 0)) {
                                        tfdln();
                                        retlst(ligne);
                                        return result;
                                     }
                                else
                                        sfdln();
                    }
                }
        }
        else if (strEq(nom,"ELSE")) {
                /* alternative de traduction conditionnelle */
                if (nivcond == 0) {     /* il n'y en a pas en cours ! */
                        erreur(USUAL,errlex16);
                        sfdln();
                        return result;
                }
                tfdln();
                nbemb = 0;        /* traiter l'emboitement des IFDEF */
                suplst(FALSE);    /* suppression temporaire de la liste */
                while (1) {       /* by pass du cas "else" */
                         /* boucle sans fin : sortie par return */
                        nextdirective();
                        if (recupidt(WARNING))
                                if (strEq(nom,"IFDEF")) {
                                        nbemb++; sfdln();
                                }
                                if (strEq(nom,"IFNDEF")) {
                                        nbemb++; sfdln();
                                }
                                else if (strEq(nom,"ENDIF")) {
                                        if (nbemb != 0) {
                                                sfdln(); nbemb--; continue;
                                        }
                                        tfdln();
                                        nivcond--;      /* fin trad. cond. */
                                        retlst(ligne);
                                        return result;
                                }
                                else
                                        sfdln();
                }
        }
        else if (strEq(nom,"ENDIF")) {
                /* fin de traduction conditionnelle */
                if (nivcond == 0) {     /* il n'y en a pas en cours ! */
                        erreur(USUAL,errlex17);
                        sfdln();
                        return result;
                }
                tfdln();
                nivcond--;
                return result;
        }
#ifdef interne
        else if (strEq(nom,"ASM")) {
                /* passage a l'etat 'Macro-Assembleur' */
                if (etat_tr != S_PARS)
                        erreur(USUAL,errlex24); /* directive incoherente */
                else
                        etat_tr = S_MASM;
                tfdln(); return result;
        }
        else if (strEq(nom,"ENDASM")) {
                /* retour a l'etat 'traducteur A.B.A.L.' */
                if (etat_tr != S_MASM)
                        erreur(USUAL,errlex24); /* directive incoherente */
                else
                        etat_tr = S_PARS;
                tfdln(); return result;
        }
#endif /* interne */

      else if (strEq(nom,"USER")) {
        if (debprog) {          /* interdit apres PROGRAM/MODULE */
                erreur(FATALE,errfu16);
                sfdln();
        }
        else {
                /* traitement des directives #USER */
                traituser();
                return result;
        }
      }
        else if (strEq(nom,"HEAP")) {
                /* taille du heap */
                recbin(FALSE,&heapsize); return result;
        }
        else if (strEq(nom,"FILES")) {
                /* nombre de fichiers utilises */
                recbin(FALSE,&maxfiles); return result;
        }
        else if (strEq(nom,"STACK")) {
                /* dimension de la pile interne */
                recbin(FALSE,&lgstack); return result;
        }
        else if (strEq(nom,"MEM")) {
                /* dimension de la zone de memoire temporaire */
                recbin(FALSE,&lgmem); return result;
        }
        else if (strEq(nom,"DATE")) {
                /* Macro definissant la date de traduction */
		Xdate(bufstr);
		verrue_pre=TRUE;
                return result;
        }
        else if (strEq(nom,"TIME")) {
                /* Macro definissant l'heure de traduction */
		Xtime(bufstr);
		verrue_pre=TRUE;
                return result;
        }
        else if (strEq(nom,"FILE")) {
                /* Macro definissant le nom du fichier courant */
		Xstrcpy(bufstr,ncurfic);
		verrue_pre=TRUE;
                return result;
        }
        else if (strEq(nom,"LINE")) {
                /* Macro definissant la ligne courante */
		sprintf(bufstr,"%lu",lgnfic);
		verrue_pre=TRUE;
               return result;
        }
        else if (strEq(nom,"PRAGMA")) {
                /* Gestion des PRAGMA etendues */
		trtpragma();
		return result;
        }
        else {
                /* autres cas non traites pour le moment */
                erreur(USUAL,errlex7);
                sfdln();
        }
return result;
}                               /* preprocess */

static BOOL _lex_echo=FALSE;

static void trtpragma()
{	BINAIRE tmp;
	BINAIRE EnteredZoneCode;

	if ( ! recupidt(USUAL) )
		return;
	/* resultat dans nom[] */

        if (strEq(nom,"VALIDPTR")) {
                /* Methode de controle de la validite des pointeurs */
		hd_tcode.ext_opt = hd_tcode.ext_opt | 0x01;
		sfdln();
		return;
        }
        else if (strEq(nom,"REMOVEALL")) {
                /* Option de liberation des pointeurs (Performance/securite) */
		hd_tcode.ext_opt = hd_tcode.ext_opt | 0x02;
		sfdln();
                return;
        }
        else if (strEq(nom,"NOINITFIELDE")) {
                /* Pas d'initialisation des FIELD=E en debut de prog */
		hd_tcode.ext_opt = hd_tcode.ext_opt | 0x04;
		sfdln();
                return;
        }
        else if (strEq(nom,"APLUS")) {
                /* Directive d'assouplissement du controle de type pour A+ */
		/* A faire */
		sfdln();
                return;
        }
        else if (strEq(nom,"HEAP")) {
                /* taille du heap */
                recbin(FALSE,&heapsize); return;
        }
        else if (strEq(nom,"FILES")) {
                /* nombre de fichiers utilises */
                recbin(FALSE,&maxfiles); return;
        }
        else if (strEq(nom,"STACK")) {
                /* dimension de la pile interne */
                recbin(FALSE,&lgstack); return;
        }
        else if (strEq(nom,"MEM")) {
                /* dimension de la zone de memoire temporaire */
               recbin(FALSE,&lgmem); return;
        }
        else if (strEq(nom,"PAGESIZE")) {
                /* Taille page memoire etendue */
                recbin(FALSE,&hd_tcode.t_pageme);
	        if ( (hd_tcode.t_pageme < 1) ||	(hd_tcode.t_pageme > 32) ) {
			hd_tcode.t_pageme=0x0800;
        	        erreur(USUAL,errlex7); sfdln();
        	} else {
			hd_tcode.t_pageme=hd_tcode.t_pageme*64;
		}
		return;
        }
        else if (strEq(nom,"PAGENUMBER")) {
                /* Nombre de page de memoire etendue */
                recbin(FALSE,&hd_tcode.nb_pageme); return;
        }
        else if (strEq(nom,"PRINTER_TITLE")) {
                /* Titre du Listing */
		/* A faire */
		sfdln();
                return;
        }
        else if (strEq(nom,"PRINTER_NB_LINES")) {
                /* Nb de lignes par page sur l'imprimante */
		/* A faire */
                recbin(FALSE,&DIMPGLST); return;
        }
        else if (strEq(nom,"PRINTER_NB_COLUM")) {
                /* Nb de colonnes par page sur l'imprimante */
                recbin(FALSE,&DIMPCLST); return;
        }
        else if (strEq(nom,"LOCAL_CONSTANT")) {
		flglcst=TRUE;
		/* #OK: 05/09/00 ALD 7 (begin) */
		/* Add bit in heading for LOCAL_CONSTANT */
		hd_tcode.flg_plus |= 4;
		/* #OK: 05/09/00 ALD 7 (end) */
		sfdln();
                return;
        }
        else if (strEq(nom,"PRIVATE_VARIABLE")) {
                /* Macro pour indiquer que les variables sont privees */
		hd_tcode.flg_plus = hd_tcode.flg_plus | 0x01;
		sfdln();
                return;
        }
        else if ((strEq(nom,"TOKEN_SIZE")) || (strEq(nom,"TOKENSIZE"))) {
                /* Taille des tokens 8 ou 16 */
                recbin(FALSE,&tmp);
		lentokmax = (BYTE)tmp+1;
	        if ((lentokmax != 9) &&
		(lentokmax != LGIDENT) ) {
			lentokmax=LGIDENT;
        	        erreur(USUAL,errlex7); sfdln();
        	}
		return;
        }
        else if (strEq(nom,"ATR_LINE_BUFFER")) {
                /* Taille du buffer ligne */
                recbin(FALSE,&lglignemax);
		lglignemax++;
	        if (lglignemax <= LGIDENT) {
			lglignemax=LGIDENT;
        	        erreur(USUAL,errlex7); sfdln();
        	} else {
			Xfree(ligne);
			ligne = Xmalloc(lglignemax);
		        if (ligne == GenericNULL(char))
				erreur(FATALE,errmem);
		}
		return;
        }
        else if (strEq(nom,"ECHO")) {
                /* Macro ecrivant un message a l'ecran */
		if ( _lex_echo ) {
		*(ligne + Xstrlen(ligne)-1)='\0';
#ifdef WIN1632
		{ BYTE buf[256];
		  sprintf(buf,"\r\n%s",ligne+13);
		  x_cprintf(buf);
		}
#else
		printf("\n%s",ligne+13);
#endif
		*(ligne + Xstrlen(ligne)-1)='\n';
		}
		sfdln();
                return;
        }
        else if (strEq(nom,"ECHO_OFF")) {
                /* Macro desactivant les messages ECHO */
		_lex_echo = FALSE;	
		sfdln();
                return;
        }
        else if (strEq(nom,"ECHO_ON")) {
                /* Macro activant les messages ECHO */
		_lex_echo = TRUE;	
		sfdln();
                return;
        }
	else if (strEq(nom,"KEYWORD")) {
                /* Macro active/desactive un mot cle */
		trkeyword();
		sfdln();
                return;
        }
        else if (strEq(nom,"KEYBOARD_FLUSH")) {
                recbin(FALSE,&kbdflush);
		switch ( kbdflush ) {
			case 0: /* BAL-FLUSH */
				/* #OK: 29/03/01 (begin) */
				/* 0x10 = 0 , 0x08 = 0 , 0x04 = 0 */
				//hd_tcode.ext_opt = hd_tcode.ext_opt & 0xE3; // commented by #OK
				hd_tcode.opt = hd_tcode.opt & 0xE3;
				/* #OK: 29/03/01 (end) */
				break;
			case 1: /* PRE-FLUSH */
				/* #OK: 29/03/01 (begin) */
				/* 0x10 = 0 , 0x08 = 1 , 0x04 = 1 */ // It's bug!
				//hd_tcode.ext_opt = (hd_tcode.ext_opt | 0x0C) & 0xEF; // commented by #OK
				/* 0x10 = 0 , 0x08 = 0 , 0x04 = 1 */
				hd_tcode.opt = (hd_tcode.opt | 0x04) & 0xE7;
				/* #OK: 29/03/01 (end) */
				break;
			case 2: /* POST-FLUSH */
				/* #OK: 29/03/01 (begin) */
				/* 0x10 = 1 , 0x08 = 1 , 0x04 = 0 */
				//hd_tcode.ext_opt = (hd_tcode.ext_opt | 0x18) & 0xFB; // commented by #OK
				hd_tcode.opt = (hd_tcode.opt | 0x18) & 0xFB;
				/* #OK: 29/03/01 (end) */
				break;
			case 3: /* PRE/POST-FLUSH */
				/* #OK: 29/03/01 (begin) */
				/* 0x10 = 1 , 0x08 = 1 , 0x04 = 1 */
				//hd_tcode.ext_opt = hd_tcode.ext_opt | 0x1C; // commented by #OK
				hd_tcode.opt = hd_tcode.opt | 0x1C;
				/* #OK: 29/03/01 (end) */
				break;
			case 4: /* NO-FLUSH */
				/* #OK: 29/03/01 (begin) */
				/* 0x10 = 0 , 0x08 = 1 , 0x04 = 0 */
				//hd_tcode.ext_opt = hd_tcode.ext_opt | 0x1C; // commented by #OK
				hd_tcode.opt = (hd_tcode.opt | 0x08) & 0xEB;
				/* #OK: 29/03/01 (end) */
				break;
			default: 
	        	        erreur(USUAL,errlex7); sfdln();
		}
		return;
        }
        else if (strEq(nom,"BCD_PRIORITY")) {
                /* Macro activant la conversion constante BIN en BCD */
		/* Actif par defaut */
		bcd_priority = TRUE;	
		sfdln();
                return;
        }
        else if (strEq(nom,"BIN_PRIORITY")) {
                /* Macro desactivant la conversion des constantes BIN en BCD */
		bcd_priority = FALSE;	
		sfdln();
                return;
        }
		/* BMS le 23/4/1997, Macros pour activation/desactivation
			des optimisations */
		else if (strEq(nom,"OPTIMISE")) {
			recupidt(USUAL);
			if (strEq(nom,"TABLES")) {
				recupidt(USUAL);
				optimise_tables = strEq(nom,"ON") ? TRUE : FALSE;
			}
			sfdln();
			return;
		}

		/* SG le 16/07/1997, Macros pour activation/desactivation
			des optimisations */
		else if (strEq(nom,"ENHANCED")) {
			recupidt(USUAL);
			if (strEq(nom,"DEBUG")) {
				recupidt(USUAL);
				enhanced_debug = strEq(nom,"ON") ? TRUE : FALSE;
			}
			sfdln();
			return;
		}
		/* SG Macro Zone + noZone pour debug selectif*/
		else if (strEq(nom,"ZONE")) {
			char c;

			c = getcar();
			if (isdigit(c)) {
				getnum(c);
				if (usc.code != CBIN) {
					erreur(USUAL,errlex7); sfdln(); 
				}
				EnteredZoneCode = usc.v.val;
				CurrentZoneCode = EnteredZoneCode;
				if (!(ZonePushStack (CurrentZoneCode))) {
					erreur(USUAL, errlex7); sfdln();
				}
			}
			else {
					if (c =='.')
					{
						if (ZoneStackIsEmpty()){
							erreur(USUAL, errlex7); sfdln();
						}
						else {
							CurrentZoneCode = ZonePopStack();
						}
						
					}
					else {
						erreur(USUAL, errlex7); sfdln();
					}
			}						
		}//else if

        else {
                /* autres cas Pas d'erreur */
                sfdln();
        }
}




static char ouinon(nomess,messi,ryes,rno)
int nomess;
char *messi;
char ryes;
char rno;

/*	Lecture de la reponse de l'utilisateur a la demande
 *	de definition ou non d'un symbole.
 *	'ryes' et 'rno' correspondent aux caracteres attendus pour
 *	les reponses positives et negatives.
 */

{				/* ouinon */
	int i;
	char rep;

	BOOL endi,ende;
	char buf[16];

	/* Affiche le message "Definir" et le nom du symbole
	 * sur la ligne d'information, ou la prochaine ligne.
	 */
	mesg(nomess,messi);
#ifndef WIN1632
	if (Optintegre) {
#endif
		/* Complete la ligne d'information avec les caracteres
		 * possibles de reponse.
		 */
		x_putch(' ');
		x_putch(ryes);
		x_putch('/');
		x_putch(rno);
		x_cprintf(" : ");
		atb(26);

		/* Lecture de la reponse :
		 * Seuls les deux caracteres possibles sont acceptes (en
		 * minuscules ou majuscules).
		 * Apres leur frappe, une validation confirme le choix, et
		 * backspace permet de changer ce choix.
		 * Toute erreur est signalee par un bip sonore.
		 */
		ende = FALSE;
		while (!ende) {
			i = x_getch();
			rep = toupper((char) i);
			if ((rep != ryes) && (rep != rno)) {
				x_bell();
				endi = TRUE;
			}
			else {
				x_putch(rep);
				endi = FALSE;
			}
			while (!endi) {
				i = x_getch();
				switch(i) {
					case '\r' :   endi = TRUE;
						      ende = TRUE;
						      break;

					case 0x0008 : endi = TRUE;
						      sprintf(&buf[0],"%c %c",0x0008,0x0008);
						      x_cprintf(&buf[0]);
						      break;

					default   :   x_bell();
						      break;
				}
			}
		}
		atb(25);
		if (Optintegre) 	prepdlig();
		return(rep);

#ifndef WIN1632
	}	else
#endif /* WIN1632 */

	/* Appel en mode non "integre" : meme probleme mais sans
	 * utiliser les primitives CICO, mais celles de la bibliotheque
	 * C standard.
	 */
	{
#ifdef msdos
	/* A caude de DOS etendu, on affiche le message (O/N) sur
	 * la ligne suivante, et avec putch.
	 */
		{ BYTE bufp[32];
		  BINAIRE i,l;

		  sprintf(&bufp[0],"\n\n--------> (%c/%c) : ",ryes,rno);
		  l = Xstrlen(&bufp[0]);
		  for (i=0 ; i<l ; i++)   x_putch(bufp[i]);
		}
#else
		printf(" (%c/%c) : ",ryes,rno);
#endif
		ende = FALSE;
		while (!ende) {

			/* Saisie un caractere et effectue l'echo */
#ifdef prologue
			i = getch();
			putch(i);
#endif
#ifdef msdos
			i = x_getch();
			x_putch(i);
#endif
#ifdef unix
			i = Xgetchar();
#endif
#ifdef vms
			i = Xgetchar();
#endif
			/* Backspace : refuse en tete, recale le curseur
			 * et emet un signal sonore si possible, ou
			 * reaffiche le message.
			 */
			if (i == 0x0008) {
#ifdef prologue
				printf(" %c",0x0007);
#endif
#ifdef msdos
				x_putch(0x0020); x_putch(0x0007);
/*				printf(" %c",0x0007);     */
#endif
#ifdef unix
				return(0);
#endif
#ifdef vms
				return(0);
#endif
				endi = TRUE;
			}

			/* Validation en tete : emet un signal sonore
			 * si possible, et provoque un reaffichage du
			 * message.
			 */
#ifdef msdos
			else if (i == 0x000D) {
				x_putch(0x0007);
/*				printf("%c",0x0007); */
#endif
#ifdef prologue
			else if (i == 0x000D) {
				printf("%c",0x0007);
#endif
#ifdef unix
			else if (i == '\n') {
#endif
#ifdef vms
			else if (i == '\n') {
#endif
				return(0);
			}

			/* Autre caractere en tete : accepte le oui/non et
			 * refuse les autres.
			 */
			else {
				rep = toupper((char) i);
				if ((rep != ryes) && (rep != rno)) {
#ifdef prologue
					printf("%c %c%c",0x0008,0x0008,0x0007);
#endif
#ifdef msdos
					x_putch(0x0008); x_putch(0x0020);
					x_putch(0x0008); x_putch(0x0007);
#endif
#ifdef unix
					return(0);
#endif
#ifdef vms
					return(0);
#endif
					endi = TRUE;
				}
				else
					endi = FALSE;
			}

			/* Attend une validation ou un effacement */
			while (!endi) {
#ifdef prologue
				i = getch();
				putch(i);
#endif
#ifdef msdos
				i = x_getch();
				x_putch(i);
#endif
#ifdef unix
				i = Xgetchar();
#endif
#ifdef vms
				i = Xgetchar();
#endif
				switch(i) {
#ifdef prologue
					case '\r' :
#endif
#ifdef msdos
					case '\r' :
#endif
#ifdef unix
					case '\n' :
#endif
#ifdef vms
					case '\n' :
#endif
						      endi = TRUE;
						      ende = TRUE;
						      break;

					case 0x0008 : endi = TRUE;
#ifdef msdos
						      x_putch(0x0020);
						      x_putch(0x0008);
#endif
#ifdef prologue
						      printf(" %c",0x0008);
#endif
#ifdef unix
						      return(0);
#endif
#ifdef vms
						      return(0);
#endif
						      break;

					default   :
#ifdef prologue
						      printf("%c%c %c",0x0007,0x0008,0x0008);
#endif
#ifdef msdos
						      x_putch(0x0007);
						      x_putch(0x0008);
						      x_putch(0x0020);
						      x_putch(0x0008);
#endif
#ifdef unix
						      return(0);
#endif
#ifdef vms
						      return(0);
#endif
						      break;
				}
			}
		}

	/* Effectue un saut de ligne */
#ifdef prologue
		putch(0x000D);
		putch(0x000A);
#endif
#ifdef msdos
		x_putch(0x000D);
		x_putch(0x000A);
#endif
	}

	return(rep);
}				/* ouinon */


static void traituser()

/*      Traitement de l'inclusion d'un fichier de definitions
 *      de fonctions utilisateur
 */
{                                               /* traituser */
	TabRt *trt;
	BOOL usclu,nomdef,ident,differ;
	char rnom[LGNRT];

	verrue_user = nomdef = ident = TRUE;
	differ = FALSE;

	traitincl();            /* simule un #include */

	if ( verrue_usrfic == TRUE )
		lexical();

	lexical();
	if (usc.code == IDENT && Xstrcmp(usc.v.pval,"VERSION") ==0) {
		lexical();      /* mention "VERSION=1" obligatoire */
		if (usc.code != EGAL)
			erreur(FATALE,errfu1);

		lexical();
		if (usc.code != CBIN || usc.v.val != 1) {
			erreur(FATALE,errfu2);
		}

		wan = FALSE;    /* mention ",NUM" optionnelle */
		lexical();
		if (usc.code != FDLN) {
			if (usc.code != VIG) {
				erreur(FATALE,errfu3);
			}
			lexical();
			if (usc.code != IDENT || Xstrcmp(usc.v.pval,"NUM")!=0) {
				erreur(FATALE,errfu4);
			} else {
				wan=TRUE;
				tfdln();
			}
		}

		lexical();
		usclu = TRUE;
		if (usc.code == IDENT && Xstrcmp(usc.v.pval,"RUNTIME") == 0) {
			usclu = FALSE;
	
			lexical();
			if (usc.code != EGAL) {
				erreur(USUAL,errfu5);
				sfdln();
			}
			else {
				lexical();
				if (usc.code != CSTR || Xstrlen(usc.v.pval) > LGNRT) {
					erreur(USUAL,errfu6);
					sfdln();
				} else {
					Xstrcpy(rnom,usc.v.pval);
					nomdef = FALSE;
					lexical();
					if (usc.code != FDLN) {
						if (usc.code != VIG) {
							erreur(FATALE,errfu3);
						}

						lexical();
						if (usc.code != IDENT || Xstrcmp(usc.v.pval,"D")!=0) {
							erreur(FATALE,errfu4);
						}
						/* User a chargement differe */	
						differ = TRUE;
					}
				}
			}
		}
		else {
			erreur(USUAL,errfu5);   /* pas de mention RUNTIME */
			sfdln();
		}

		trt = All_TabRt();              /* alloue descripteur RT */
		if (trt == GenericNULL(TabRt))
			erreur(FATALE,errmem);

		if (nomdef)
			Xstrcpy(&trt->nom[0],ncurfic);  /* ATTENTION EXTENSION */
		else
			Xstrcpy(&trt->nom[0],rnom);

		if ( differ )
			trt->options = 1;
		else
			trt->options = 0;

		if (!usclu)
			sfdln();        /* saute la fin de la ligne */

		lexical();
		usclu = TRUE;
		if (usc.code == NAME) {
			usclu = FALSE;

			lexical();
			if (usc.code != EGAL) {
				erreur(USUAL,errfu5);
				sfdln();
			}
			else {
				lexical();
				if (usc.code != IDENT) {
					erreur(USUAL,errfu6);
					sfdln();
				} else {
					ident = FALSE;
				}
			}
		}

		if (ident)
			Xstrcpy(&trt->ident[0]," ");  /* ATTENTION EXTENSION */
		else
			Xstrcpy(&trt->ident[0],usc.v.pval);

		if (!usclu)
			sfdln();        /* saute la fin de la ligne */

		nofctusr=0;
		do {                    /* tant qu'il y a des fonctions */
			getfusr(usclu);
			usclu = FALSE;
		} while (usc.code != END);

		trt->nort = nortusr++;          /* remplit descripteur RT */
		trt->nbfct = nofctusr;
		trt->suiv = RacTabRt;           /* chainage simple */
		RacTabRt = trt;

		if ( verrue_usrfic == FALSE ) {
			Xfclose(input);		/* reprendre l'ancien source */
			#ifdef unix
			liberlox(ncurfic);
			#endif /* unix */
			input    = hinput[--nivincl];
			lgnfic   = curlgn[nivincl];
			posinsce = pinput[nivincl];
			seekcur = pinput[nivincl];
			Xstrcpy(ncurfic,incfic[nivincl]);

			ncursrc = incsrc[nivincl];

			/* Mettre a jour l'affichage du nom du fichier source
			* en cours de traitement pour l'ensemble integre
			*/
			if (Optintegre)
				affsce(ncurfic,1);

			Xfree(incfic[nivincl]);
			ligne[0] = 0;           /* reinit du buffer ligne courante */
			lptr = &ligne[0];
		} else {
			lexical();
		} 
	}
	else {
		erreur(FATALE,errfu7);
	}
	
	verrue_user = FALSE;
}                                               /* traituser */


static void getfusr(b)

/*      Gere une declaration de fonction utilisateur :
 *      si NUM, chaque ligne doit commencer par l'indication
 *      du numero de fonction, sinon celui-ci est determine
 *      par l'ordre d'apparition de la fonction.
 *      Le booleen b indique si l'unite lexicale suivante a deja
 *      ete lue.
 */

 BOOL   b;

{                                               /* getfusr */
        Tbusr *t;
        Tbusr *f;
        Tbusr *p;
        BYTE typa[MXARGS];
        BYTE moda[MXARGS];
        int i;
        BINAIRE locnfct,nelem,j;
        BOOL varia;

        varia = FALSE;
        if (wan) {              /* numerotation explicite des fonctions */
                if (!b)
                        lexical();
                if (usc.code == END)
                        return;
                if (usc.code != CBIN) {
                        erreur(USUAL,errfu8);
                        sfdln();
                        return;
                }
                else {
                        locnfct = usc.v.val;
                        lexical();
                        if (usc.code != DPT) {
                                erreur(USUAL,errfu9);
                                sfdln();
                                return;
                        }
                }
        }

        t = All_Tbusr();                /* alloue un noeud */
        if (t == GenericNULL(Tbusr))
                erreur(FATALE,errmem);

        t->tres = TVOID;                /* par defaut, fct sans retour */

        t->g = GenericNULL(Tbusr);      /* prepare le noeud */
        t->d = GenericNULL(Tbusr);
        t->nort = nortusr;
        t->nofct = ((wan) ? (locnfct) : (nofctusr));

	if ( wan )
       	        lexical();
	else
		if (!b)
			lexical();

        /* Recupere le type de retour de la fonction
         * et teste la fin des definitions de fonctions */

        switch(usc.code) {
                case PCENT:     t->tres = TBIN; lexical(); break;
                case STR:       t->tres = TSTR; lexical(); break;
                case MUL:       t->tres = TBCD; lexical(); break;
                case END:       Free_Tbusr(t); return;
        }

        /* Recupere le nom de la fonction */
        if (usc.code != IDENT) {
                erreur(USUAL,errfu10);
                sfdln();
                Free_Tbusr(t);
                return;
        }

        Xstrcpy(&t->nom[0],usc.v.pval); /* mise en place du nom */
        lexical();
        if (usc.code != PAG) {
                erreur(USUAL,ersynt19);
                sfdln();
                Free_Tbusr(t);
                return;
        }

        /* Recupere le nombre, les types et les modes de passage
         * des arguments.
         * A partir de la version 1.4, un nombre d'argument variable
         * est possible, et ses caracteristiques de passage sont notes
         * dans le n+1 eme argument
         */
        t->nba = getfuarg(&typa[0],&moda[0],&varia);
        nelem = (varia) ? (t->nba + 1) : (t->nba);

        if (nelem != 0) {
                /* A partir de la version 1.4, le support des fonctions
                 * a nombre d'arguments variable necessite que l'analyse
                 * des expressions puisse propager le type et le mode
                 * de passage des arguments supplementaires, donc que
                 * la taille des tables correspondantes soit suffisante.
                 */
                t->typa = (BYTE *) Xmalloc((MXARGS+1) * sizeof(BYTE));
                t->moda = (BYTE *) Xmalloc((MXARGS+1) * sizeof(BYTE));

                if (t->typa == GenericNULL(BYTE) ||
                    t->moda == GenericNULL(BYTE)) {
                        Free_Tbusr(t);
                        erreur(FATALE,errmem);
                }
                for (j = 0 ; j < nelem ; j++) {
                        t->typa[j] = typa[j];
                        t->moda[j] = moda[j];
                }
        }
        else {
                t->typa = GenericNULL(BYTE);
                t->moda = GenericNULL(BYTE);
        }

        t->nbavar = varia;

        /* Controle la presence d'une parenthese droite a la fin
         * de la liste des arguments
         */
        if (usc.code != PAD) {
                erreur(USUAL,ersynt20);
                sfdln();
                if (t->typa != GenericNULL(BYTE))
                        Free_BYTE(t->typa);
                if (t->moda != GenericNULL(BYTE))
                        Free_BYTE(t->moda);
                Free_Tbusr(t);
                return;
        }

        /* Insere le nom de la fonction dans la table des fonctions
         * utilisateur
         */
        if (RacTbusr == GenericNULL(Tbusr)) {
                RacTbusr = t;           /* si pas de racine, noeud le devient */
        }
        else {
                f = RacTbusr;           /* part de la racine */
                while (f != GenericNULL(Tbusr)) {
                        p = f;
                        i = Xstrcmp(t->nom,f->nom);
                        if (i < 0)
                                f = f->g;
                        else if (i > 0)
                                f = f->d;
                        else {          /* la fonction existe deja */
                                erreur(USUAL,errfu11);
                                sfdln();
                                if (t->typa != GenericNULL(BYTE))
                                        Free_BYTE(t->typa);
                                if (t->moda != GenericNULL(BYTE))
                                        Free_BYTE(t->moda);
                                Free_Tbusr(t);
                                return;
                        }
                }
                if (i < 0)              /* insere une feuille */
                        p->g = t;
                else
                        p->d = t;

        }

        sfdln();                        /* saute la fin de la ligne*/
        if (wan) {
                if (locnfct > nofctusr)
                        nofctusr = locnfct;
        }
        else
                nofctusr++;
}                                               /* getfusr */


static BINAIRE getfuarg(typa,moda,varia)

/*      Dresse la liste des arguments d'appel d'une fonction
 *      utilisateur, et de leur mode d'appel
 */

BYTE typa[];
BYTE moda[];
BOOL *varia;
{                                               /* getfuarg */
        BINAIRE narg;
        BYTE ptyp;

        *varia = FALSE;

        narg = 0;
        do {
                if (narg == MXARGS) {
                        erreur(USUAL,errfu12);
                        sfdln();
                        return(narg);
                }
                lexical();
                switch (usc.code) {
                        case PCENT : ptyp=1; break;
                        case DIESE : ptyp=0; break;
                        case STR :   ptyp=3; break;
                        case MUL :   ptyp=2; break;
                        case SPT :   ptyp=T_ANY; *varia = TRUE; break;
                        case PAD : if (narg == 0)
                                        return(narg);   /* ...!!!... */
                        default : erreur(USUAL,errfu13);
                                  sfdln();
                                  return(0);
                }
                typa[narg]=ptyp;
                lexical();
                if (usc.code == INTERRO) {
                        moda[narg] = 1;		/* passage par adresse */
                        lexical();
                }
                else if (usc.code == EXCLAM) {
                        moda[narg] = 2;		/* passage par valeur ou adresse */
                        lexical();
                }
                else
                        moda[narg] = 0;		/* passage par valeur */

                if (!(*varia))
                        narg++;
                else {
                        /* L'indication d'un nombre d'arguments variable
                         * doit etre la derniere de la liste des arguments
                         */
                        if (usc.code != PAD) {
                                erreur(USUAL,errfu13);
                                sfdln();
                                return(0);
                        }
                }
        } while (usc.code == VIG);

        if (usc.code != PAD) {
                erreur(USUAL,errfu13);
                sfdln();
                return(0);
        }
        return(narg);
}                                               /* getfuarg */


static void traitincl()

/*      traitement de l'inclusion d'un fichier source
 */
{                                               /* traitincl */
        char   *pnom,*p,c;

        char    rep,ryes,rno;

        ryes = *yesno;
        rno = *(yesno+1);

	c=getcar();
	remettre();
	/* Traitement du cas #USER<RC> */ 
	if ( c == '\n' ) {
		verrue_usrfic = TRUE;
		return;
	} else
		verrue_usrfic = FALSE;

        if (nivincl == MAXINCL)         /* impossible si debordement */
                erreur(FATALE,errlex5); /* et l'erreur est fatale */

	if ( (c == '"') || (c == '<') ) {
        	pnom = getstr(c,bufstr,LGMXNOM);  /* lire nom de ce fichier */
	} else {
	        pnom = getstr('\0',bufstr,LGMXNOM);  /* lire nom de ce fichier */
	}

        if (pnom == GenericNULL(char)) { /* et si incorrect, */
                sfdln();                 /* by pass fin de la ligne */
        }
        else {
                tfdln();        /* traiter la fin de la ligne */
                pnom = Xmalloc(LGMXNOM);
                if (pnom == GenericNULL(char))
                        erreur(FATALE,errmem);
                p = Xmalloc(LGMXNOM);
                if (p == GenericNULL(char)) {
                        Xfree(pnom);
                        erreur(FATALE,errmem);
                }

		/* On conserve des informations sur le fichier courant
		 * de facon a preparer la reprise a la sortie de l'include :
		 * nom du fichier courant, handle du fichier, position,
		 * numero de ligne courante.
		 */
		curlgn[nivincl]   = lgnfic;
		incfic[nivincl]   = Xstrcpy(pnom,ncurfic);

#ifdef msdos
		pinput[nivincl]   = posinsce;
#endif
#ifdef prologue
		pinput[nivincl]   = posinsce;
#endif
#ifdef unix
		pinput[nivincl]   = seekcur;
#endif
#ifdef vms
		pinput[nivincl]   = seekcur;
#endif

		incsrc[nivincl] = ncursrc;
		hinput[nivincl++] = input; /* garder le fichier courant */

                /* Regles de constitution d'un nom de fichier inclus :
                 *      - si aucun chemin n'est specifie, on prend le
                 *        chemin des includes s'il existe, sinon on laisse
                 *        le nom de fichier tel quel
                 *      - si un chemin est specifie depuis la racine, il est
                 *        utilise
                 *      - si un chemin est specifie en relatif, deux cas se
                 *        presentent :
                 *              . le fichier originel est compose d'un chemin
                 *                d'acces depuis la racine : on utilise la
                 *                relativite par rapport a celui-ci
                 *              . sinon, on garde le nom de fichier tel quel
                 */

                /* Controle existence chemin d'acces */
                if ((fn_parser(&bufstr[0],p,1+2) != 0) ||
			(reprac(&bufstr[0],p)))
			Xfree(p);
		else {
			inclrecherche(c,lstincl,bufstr,p);
			Xfree(p);
		}

                /* Ajoute l'extension (si necessaire) au nom de fichier */
                if (verrue_user)
                        pnom = newficdef(bufstr,bufstr);
                else
                        pnom = newfics(bufstr,bufstr);

                /* Affiche le nom du fichier source a traiter */
                if (Optintegre)
                        affsce(pnom,1);
                lgnfic = 0L;
                /* Interaction sur erreur ouverture include */
                while (TRUE) {
        	        input = Xfopen(pnom,"r"); /* et ouvrir le nouveau */
                	if (input == GenericNULL(FILE)) {
						#ifdef WIN1632
							//if (OptIdra)
								rep = ouinonInMsgBox(GetUserMessage(errlex0),ncurfic,pnom,ryes,rno,1);
							//else
						#else
								rep = ouinon(errlex0,pnom,ryes,rno);
						#endif
        	                if (rep == rno) 
	                                break;
                        } else
				break;
                } /* Sortie par N ou pas d'erreur */
                if (input == GenericNULL(FILE)) {
                        /* en abandonnant si c'est impossible */
                        nivincl--; input = hinput[nivincl];
                        pnom = Xstrcpy(ncurfic,incfic[nivincl]);
			ncursrc = incsrc[nivincl];
                        Xfree(incfic[nivincl]); lgnfic = curlgn[nivincl];
                        erreur(FATALE,errlex0);
                }

		/* Indique que l'on est en debut de fichier */
		posinsce = 0L;	
        }
}                                               /* traitincl */


static BOOL inclrecherche(type,prep,buf,pnom)
char type;
LstInc *prep;
char *buf;
char *pnom;
{
FILE *fh;
char *pp;
BOOL trouve=FALSE;

	pp = Xmalloc(LGMXNOM);
	if (pp == GenericNULL(char)) {
		Xfree(pnom);
		erreur(FATALE,errmem);
	}

	switch ( type ) {
		case '<':
			if ( prep == GenericNULL(LstInc) ) {
				Xstrcpy(pnom,buf);
				goto _irb;
			}
			break;
		case '"':
			Xstrcpy(pnom,buf);
			goto _irb;
		default:
			Xstrcpy(pnom+fn_parser(NomFicDep,pnom,1+2+4),buf);
_irb:
	                /* Ajoute l'extension (si necessaire) au nom de fichier */
			if (verrue_user)
				newficdef(pnom,pnom);
                	else
                        	newfics(pnom,pnom);
        	        fh = Xfopen(pnom,"r"); /* et ouvrir le nouveau */
			if ( fh != GenericNULL(FILE) ) {
				trouve=TRUE;
				Xfclose(fh);
#ifdef unix
				liberlox(pnom);
#endif /* unix */
			}
			break;
	}
	if ( trouve == FALSE ) {
	/* Recherche dans la liste des Includes */
	if ( prep != GenericNULL(LstInc) ) {
	if ( prep->suiv != GenericNULL(LstInc) ) {
		do {	
			Xstrcpy(pp,buf);
			Xstrcpy(pnom, prep->rep);
			Xstrcpy(pnom+Xstrlen(pnom),pp);
			Xstrcpy(pp,pnom);

	                /* Ajoute l'extension (si necessaire) au nom de fichier */
			if (verrue_user)
				newficdef(pp,pp);
                	else
                        	newfics(pp,pp);
			Xstrcpy(pnom,pp);

        	        fh = Xfopen(pnom,"r"); /* et ouvrir le nouveau */
			if ( fh != GenericNULL(FILE) ) {
				trouve=TRUE;
				Xfclose(fh);
#ifdef unix
				liberlox(pnom);
#endif /* unix */
			} else {
				prep=prep->suiv;
				if ( prep->rep == GenericNULL(char) )
					break;								
			}
		} while (trouve == FALSE);	
	}
	}
	}
	Xstrcpy(buf,pnom);
	Xfree(pp);
	return(trouve);
}


static BOOL reprac(pnom,p)
char *pnom;
char *p;

/*      Repere si le nom de fichier 'pnom' comporte une
 *      indication de chemin d'acces depuis la racine.
 *      Utilise 'p' comme zone de travail.
 */

{                                               /* reprac */
#ifdef vms
  return(((fn_parser(pnom,p,4) > 2) && ((*p == '[') && (*(p+1) != '.') && (*(p+1) != '-')) || (*p != ']')) ? TRUE : FALSE);
#else /* ! vms */
  return(((fn_parser(pnom,p,4) != 0) && (*p == DELIMREP)) ? TRUE : FALSE);
#endif /* vms */
}                                               /* reprac */


static void nextdirective()

/*      recherche directive de traduction suivante sans passer par nextcar
 *      pour eviter l'action automatique du preprocesseur ...
 */
{                                       /* nextdirective */
        char c;

        do {
                do
                        c = carsuiv();
                while (isblanc(c));
                if ((c != '#') && (c != '\n'))
                        do {
                                if (c == EOSTR) /* fin du source en entree */
                                        erreur(FATALE,errlex1);
                                c = carsuiv();
                        }
                        while (c != '\n');
        }
        while (c != '#');
}                                       /* nextdirective */


static BOOL recupidt(gravite)

/*      recupere un ident a la position courante et le met dans "nom"
 */
BYTE gravite;
{                               /* recupidt */
        nom[0] = getcar();
        if ((!isalpha(nom[0])) && (nom[0] != '_') ) { 
	      /* il faut un ident derriere le '#' */
                erreur(gravite,errlex7);/* sinon signaler l'erreur */
                sfdln();                /* et by pass fin de la ligne */
                return (FALSE);
        }
        buildidt(&nom[1]);
        return (TRUE);
}                               /* recupidt */


static void traitdef(signal)

/*      traitement de la definition d'un symbole de traduction conditionnelle
 */
BOOL signal;
{                                               /*traitdef */
        int i;
        int j = MAXSYMB;

        for (i = 0; i < MAXSYMB; i++)
                if (tabsymb[i][0] == EOSTR) /* entree libre */
                        if (j == MAXSYMB) j = i;
                else if (signal && strEq(tabsymb[i],nom)) { /* deja defini */
                        erreur(WARNING,errlex20); sfdln();
                        return;
                }
        if (j == MAXSYMB) /* pas de libre : erreur fatale pour debordement */
                erreur(FATALE,errlex15);
        else {
                Xstrcpy(tabsymb[j],nom); tfdln();
                return;
        }
}                                               /*traitdef */


static void traitudef(signal)

/*      traitement de non-definition d'un symbole de traduction conditionnelle
 */
BOOL signal;
{                                       /* traitudef */
        int i;

        for (i = 0; i < MAXSYMB; i++)
                if (strEq(tabsymb[i],nom)) { /* trouve */
                        tabsymb[i][0] = EOSTR; tfdln();
                        return;
                }
        if (signal)
                erreur(WARNING,errlex21);       /* ident absent */
        sfdln();
}                                       /* traitudef */


static void recbin(nofdln,v)

/*      recuperation d'une constante binaire
 */
BOOL nofdln;
BINAIRE *v;
{                                       /* recbin */
        char c;

        c = getcar();
        if (!isdigit(c)) {
                erreur(USUAL,errlex7); sfdln(); return;
        }
        getnum(c);
        if (usc.code != CBIN) {
                erreur(USUAL,errlex7); sfdln(); return;
        }
        *v = usc.v.val;
	if ( ! nofdln )
        	tfdln();
	return;
}                                       /* recbin */


void trkeyword()
{					/* trkeyword */
char c;
        c = getcar();           /* 1er car non blanc suivant */
        NDBLN = TRUE;
        if (isdebidt(c))        /* debut identificateur, motcle ou fct util. */
                getident(c);
        else {
                erreur(USUAL,errlex7); sfdln(); return;
	}

	if ( usc.code <= Last_KEY ) {
		c = getcar();
		remettre();
		if ( ! recupidt(USUAL) )
			return;
        	if (strEq(nom,"OFF")) {
	                /* desactivation du mot cle */
			ActKeyWords[usc.code] = FALSE;
		} else {
	                erreur(USUAL,errlex7); sfdln(); return;
		}
	} else {
		if ( usc.code == IDENT ) {
			c = getcar();
			remettre();
			if ( ! recupidt(USUAL) )
				return;
        		if (strEq(nom,"ON")) {
	                	/* activation du mot cle */
				if ( verrue_activekey <= Last_KEY ) {
					ActKeyWords[verrue_activekey] = TRUE;
				} else {
		                	erreur(USUAL,errlex7); sfdln(); return;
				}
			} else {
	                	erreur(USUAL,errlex7); sfdln(); return;
			}
		} else {
                	erreur(USUAL,errlex7); sfdln(); return;
		}
	}
	
	sfdln();
}					/* trkeyword */

/* ----------------------------- Fin de fichier : lexical.c ------------- */

