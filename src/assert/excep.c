/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : EXCEP.C
 *	Version : 1.1a
 *	Date    : 25/05/93
 *	Systeme : Windows 3/NT
 *
 *	Traitement des exceptions
 *
 *	[Code]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	05/01/93 : Debut du codage
 *
 */
#ifdef UNIX
#define __PORTABLE__			/* source portable */
#else
#define __WINDOWS_SOURCE__		/* source Windows */
#endif
/* Inclusions importees */

#include "wabaldef.h"
#include "pubslist.h"
#include "pubalbox.h"


/* Inclusions exportees et privees */

#ifndef PRIMITIVE
#define PRIMITIVE GLOBAL
#endif

#include "pubexcep.h"
#include "excep.h"

/*T--------------------------------------------------------------------------
 *
 * Le gestionnaire d'exceptions est charge de toutes les operations
 * sur les exceptions.
 * La definition d'une exception est decrite dans le document AW3/7.
 *
 * Les exceptions peuvent etre declenchees de deux manieres differentes :
 *	- soit par violation d'une assertion
 *	- soit par decision volontaire du programmeur en un point
 *	  precis du programme
 *
 * Une exception peut declencher deux comportements de l'application,
 * selon qu'elle est ou non "disciplinee" :
 *	- une exception disciplinee est une exception dont la
 *	  survenue etait prevue par le developpeur. Celui-ci a donc
 *	  prevu un "point de reprise".
 *	  Le role du gestionnaire est de transmettre le controle a
 *	  ce point de reprise (cf les blocs TRY)
 *	- une exception indisciplinee est une exception dont on
 *	  n'avait pas prevu la cause. Sa detection doit arreter
 *	  le programme au plus vite, non sans avoir pris la peine
 *	  de le signaler a l'utilisateur par un message d'alerte
 *	  (cf fonction AlertBox).
 *
 * On manipule en outre deux concepts supplementaires :
 *	- le contexte d'exception (structure EXCEPTION_CONTEXT)
 *	  qui renferme les informations sur l'exception : type,
 *	  coordonnees de l'appelant et du lieu de l'exception.
 *        Les contextes d'exceptions sont alloues dynamiquement
 *	  et leur trace est conservee dans une liste.
 *	- le bloc de controle des exceptions qui n'est autre qu'une
 *	  autre liste, de points de reprise, donc ordonnee selon
 *	  les blocs TRY rencontres.
 *
 * Fonctions disponibles :
 *	InitException   : initialisation du gestionnaire d'exceptions
 *	EndException    : fermeture du gestionnaire d'exceptions
 *	_ExcThrow       : emet un exception et se branche au traitement
 *	_ExcPushCtx     : empile un contexte d'exception
 *	_ExcSetCtx      : met a jour le contexte d'exception de tete
 *	_ExcPushLink    : empile un bloc de controle d'exception
 *	_ExcPopLink     : depile un bloc de controle d'exception
 *	_ExcPopCtx      : depile un contexte d'exception
 *	_ExcPopBoth     : depile contexte et bloc de controle
 *	_ExcSetAndThrow : traitement des violations d'assertions
 *
 * Notes de compilation :
 *	Definir __VERBOSE_ASSERT__ si on desire avoir le texte
 *	des expressions dans les boites d'alerte en cas de violation
 *	d'assertion. A defaut, on n'aura que l'indication de la localisation
 *	dans le source.
 *
 * ------------------------------------------------------------------------- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*		INITIALISATION DU GESTIONNAIRE D'EXCEPTIONS		     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT InitException
 *
 *	Initialisation des structures de controle du
 *	gestionnaire d'exception.
 *
 *	E/ rien
 *	S/ rien
 *
 */
void InitException()
{ EXCEPTION_CONTEXT FAR * FirstCtx;
  C_SNODE FAR * node;

	/* Initialisation des listes d'exceptions et de contextes */
	ExceptionList = SlistCreate();
	ExceptionContextList = SlistCreate();

	/* Alimente la liste de contextes avec un contexte par defaut
	 * correspondant aux exceptions indisciplinees.
	 */
	OBCREATE(FirstCtx,EXCEPTION_CONTEXT);
	FirstCtx->Value = 1;
	FirstCtx->Kind = "Indisciplinee";
	FirstCtx->CheckExpr = "";
	FirstCtx->CallerFilename = "No file";
	FirstCtx->CallerLinenumber = 0;
	FirstCtx->ExcFilename = "No file";
	FirstCtx->ExcLinenumber = 0;

	/* Ajoute ce contexte a la liste des contextes */
	node = SnodeCreate();
	SnodeSet(node,(void FAR *)FirstCtx);
	SlistAddHead(ExceptionContextList,node);
}

/* --------------------------------------------------------------------------
 *
 * FCT EndException
 *
 *	Desallocation des structures de controle du
 *	gestionnaire d'exception.
 *
 *	E/ rien
 *	S/ rien
 *
 */
void EndException()
{ EXCEPTION_CONTEXT FAR * Ctx;
  C_SNODE FAR * node;

	/* Tant que la liste des contextes n'est pas vide, on
	 * supprime le noeud courant de la liste et son contenu.
	 */
	while (SlistIsEmpty(ExceptionContextList) == FALSE) {
		node = SlistGetHead(ExceptionContextList);
		Ctx  = (EXCEPTION_CONTEXT FAR *)SnodeGet(node);
		SlistRemoveHead(ExceptionContextList);
		SnodeDelete(node);
		Xfree(Ctx);
	}

	/* Supprime la liste des contextes */
	SlistDelete(ExceptionContextList);

	/* Tant que la liste des exceptions n'est pas vide, on
	 * supprime le noeud courant de la liste, mais pas son
	 * contenu que l'on n'a pas nous-meme alloue.
	 */
	while (SlistIsEmpty(ExceptionList) == FALSE) {
		node = SlistGetHead(ExceptionList);
		SlistRemoveHead(ExceptionList);
		SnodeDelete(node);
	}

	/* Supprime la liste des exceptions */
	SlistDelete(ExceptionList);
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			EMISSION DES EXCEPTIONS				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT _ExcThrow
 *
 *	Emission d'une exception et branchement a son traitement
 *
 *	E/ valeur de l'exception
 *	   pointeur sur le nom de fichier ou elle s'est produite
 *	   numero de ligne dans ce fichier
 *	S/ rien
 *
 * Notes :
 *	Si un gestionnaire d'exception a ete declare, l'exception est
 *	transmise a ce gestionnaire.
 *	Dans le cas contraire, il s'agit d'une exception indisciplinee
 *	dont le contexte est affiche a l'ecran avant la sortie brutale
 *	de l'application.
 *	Le gestionnaire emet ses messages eventuels vers une fonction
 *	AlertBox qui est supposee definie ailleurs.
 *
 */
void _ExcThrow( ExceptionValue , ExceptionFilename , ExceptionLinenumber)
WORD ExceptionValue;
BYTE FAR * ExceptionFilename;
WORD ExceptionLinenumber;
{ C_SNODE FAR * ExcTop;
  C_SNODE FAR * ExcCtxTop;
  EXCEPTION_CONTEXT FAR * Current;

	/* Controle des assertions : pour eviter un bouclage sans fin
	 * on n'utilise pas ici les macros predefinies.
	 */
	if ((ExceptionList == (C_SLIST FAR *)NULL) ||
	    (ExceptionContextList == (C_SLIST FAR *)NULL) ||
	    (SlistIsEmpty(ExceptionContextList))) {
		AlertBox((BYTE FAR *)"Gestionnaire d'exception non initialise");
		exit(1);
	}
	/* Recupere des informations sur le point de reprise
	 * courant.
	 */
	ExcTop = SlistGetHead(ExceptionList);

	/* Recupere les informations sur le contexte de
	 * l'exception courante.
	 */
	ExcCtxTop = SlistGetHead(ExceptionContextList);
	Current = SnodeGet(ExcCtxTop);

	/* Range les informations sur le type de l'exception */
	Current->Value = ExceptionValue;
	Current->ExcFilename = ExceptionFilename;
	Current->ExcLinenumber = ExceptionLinenumber;

	/* S'il n'y a pas de point de reprise defini,
	 * l'exception est dite indisciplinee et provoque une
	 * sortie du programme.
	 */
	if (ExcTop == (C_SNODE FAR *)NULL) {
		BYTE buf[512];

		/* Construit le libelle du message d'avertissement */
		sprintf(&buf[0],"Exception indisciplinee\n\nType :\t%s (%d)\nExpr :\t%s"
				 "\nDans :\t%s, ligne %d\nDepuis :\t%s, ligne %d",
				Current->Kind,Current->Value,Current->CheckExpr,
				Current->ExcFilename,Current->ExcLinenumber,
				Current->CallerFilename,Current->CallerLinenumber);
		AlertBox((BYTE FAR *)&buf[0]);
		exit(1);
	}
	else {
		jmp_buf FAR * CatchPoint;

		/* Recupere le point de reprise et provoque un
		 * debranchement.
		 */
		CatchPoint = SnodeGet(ExcTop);

		Xlongjmp(*((jmp_buf *)CatchPoint),ExceptionValue);
	}
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			CONTROLE DES EXCEPTIONS				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT _ExcPushCtx
 *
 *	Empile un contexte d'exception
 *
 *	E/ pointeur sur le contexte a empiler
 *	   pointeur sur le nom de fichier du bloc appelant
 *	   numero de ligne dans ce fichier
 *	S/ rien
 *
 */
void _ExcPushCtx(Current,filename,linenumber)
EXCEPTION_CONTEXT FAR * Current;
BYTE FAR * filename;
WORD linenumber;
{ C_SNODE FAR * ExcCtx;

	/* Controle des assertions */
	PRECOND(ExceptionContextList != (C_SLIST FAR *)NULL);
	PRECOND(Current != (EXCEPTION_CONTEXT FAR *)NULL);

	/* Prepare le contexte de l'exception */
	Current->Kind = "TRY BLOC";
	Current->CheckExpr = "";
	Current->CallerFilename = filename;
	Current->CallerLinenumber = linenumber;
	Current->ExcFilename = "";
	Current->ExcLinenumber = 0;

	/* Ajoute le contexte de l'exception courante a la liste des
	 * contextes d'exceptions.
	 */
	ExcCtx = SnodeCreate();
	SnodeSet(ExcCtx,(void FAR *)Current);
	SlistAddHead(ExceptionContextList,ExcCtx);
}

/* --------------------------------------------------------------------------
 *
 * FCT _ExcSetCtx
 *
 *	Mise a jour du contexte d'exception en tete de liste
 *
 *	E/ pointeur sur le texte decrivant l'appelant
 *	   pointeur sur le texte decrivant l'expression non verifiee
 *	S/ rien
 *
 */
void _ExcSetCtx( texte,expr )
BYTE FAR * texte;
BYTE FAR * expr;
{ C_SNODE FAR * node;
  EXCEPTION_CONTEXT FAR * HeadCtx;

	/* Pas de controle standard des assertions car utilise par
	 * le mecanisme d'assertions lui-meme.
	 */
	if (ExceptionContextList == (C_SLIST FAR *)NULL)
		return;

	/* Retrouve le contexte d'exception courant */
	node = SlistGetHead(ExceptionContextList);
	HeadCtx = (EXCEPTION_CONTEXT FAR *)SnodeGet(node);

	/* Met a jour ce contexte */
	HeadCtx->Kind = texte;
	HeadCtx->CheckExpr = expr;
}

/* --------------------------------------------------------------------------
 *
 * FCT _ExcPushLink
 *
 *	Empile un bloc de controle d'exception
 *
 *	E/ pointeur sur la structure jmp_buf du bloc de controle
 *	S/ rien
 *
 */
void _ExcPushLink(tx)
jmp_buf FAR * tx;
{ C_SNODE FAR * ExcLink;

	/* Controle des assertions */
	PRECOND(ExceptionList != (C_SLIST FAR *)NULL);

	/* Ajoute l'exception courante a la liste des exceptions */
	ExcLink = SnodeCreate();
	SnodeSet(ExcLink,(void FAR *)tx);
	SlistAddHead(ExceptionList,ExcLink);
}

/* --------------------------------------------------------------------------
 *
 * FCT _ExcPopLink
 *
 *	Depile un bloc de controle d'exception et retourne le contexte
 *	d'exception actif
 *
 *	E/ pointeur sur le contexte d'exception a renseigner
 *	S/ rien
 *
 */
void _ExcPopLink( Current )
EXCEPTION_CONTEXT FAR * Current;
{ C_SNODE FAR * node;
  EXCEPTION_CONTEXT FAR * HeadCtx;

	/* Agit sur la liste des exceptions :
	 *	- recupere le noeud de tete
	 *	- ote l'exception de la liste
	 *	- detruit le noeud decrivant cette exception
	 */
	node = SlistGetHead(ExceptionList);
	SlistRemoveHead(ExceptionList);
	SnodeDelete(node);

	/* Recupere le contexte d'exception en tete de liste et
	 * le recopie dans le parametre effectif.
	 */
	if (Current != (EXCEPTION_CONTEXT FAR *)NULL) {
		node = SlistGetHead(ExceptionContextList);
		HeadCtx = (EXCEPTION_CONTEXT FAR *)SnodeGet(node);

		Current->Value = HeadCtx->Value;
		Current->Kind = HeadCtx->Kind;
		Current->CheckExpr = HeadCtx->CheckExpr;
		Current->CallerFilename = HeadCtx->CallerFilename;
		Current->CallerLinenumber = HeadCtx->CallerLinenumber;
		Current->ExcFilename = HeadCtx->ExcFilename;
		Current->ExcLinenumber = HeadCtx->ExcLinenumber;
	}
}

/* --------------------------------------------------------------------------
 *
 * FCT _ExcPopCtx
 *
 *	Depile un contexte d'exception.
 *
 *	E/ rien
 *	S/ rien
 *
 */
void _ExcPopCtx()
{ C_SNODE FAR * node;

	/* Agit sur la liste des contextes d'exceptions :
	 *	- recupere le noeud de tete
	 *	- ote le contexte d'exception de la liste
	 *	- detruit le noeud decrivant ce contexte
	 */
	node = SlistGetHead(ExceptionContextList);
	SlistRemoveHead(ExceptionContextList);
	SnodeDelete(node);
}

/* --------------------------------------------------------------------------
 *
 * FCT _ExcPopBoth
 *
 *	Depile une exception et son contexte.
 *
 *	E/ rien
 *	S/ rien
 *
 */
void _ExcPopBoth()
{	_ExcPopLink((EXCEPTION_CONTEXT FAR *)NULL);
	_ExcPopCtx();
}

#ifdef __VERBOSE_ASSERT__

/* --------------------------------------------------------------------------
 *
 * FCT _ExcSetAndThrow
 *
 *	Violation d'assertion (forme verbeuse).
 *
 *	E/ pointeur sur le texte decrivant le type d'assertion
 *	   pointeur sur le texte decrivant l'expression non verifiee
 *	   pointeur sur le nom de fichier de la violation
 *	   numero de ligne dans ce fichier
 *	S/ rien
 *
 */
void _ExcSetAndThrow( Kind,CheckExpr,filename,linenumber )
BYTE FAR * Kind;
BYTE FAR * CheckExpr;
BYTE FAR * filename;
WORD linenumber;
{
	_ExcSetCtx(Kind,CheckExpr);
	_ExcThrow(1,filename,linenumber);
}

#else

/* --------------------------------------------------------------------------
 *
 * FCT _ExcSetAndThrow
 *
 *	Violation d'assertion (forme laconique).
 *
 *	E/ type d'assertion
 *	   pointeur sur le nom de fichier de la violation
 *	   numero de ligne dans ce fichier
 *	S/ rien
 *
 */
void _ExcSetAndThrow( KindNum,filename,linenumber )
WORD KindNum;
BYTE FAR * filename;
WORD linenumber;
{ BYTE FAR * Kind;
  BYTE FAR * CheckExpr;

	/* Regenere le texte du type d'assertion */
	switch(KindNum) {
		case VAL_PRECOND :
			Kind = (BYTE FAR *)TXT_PRECOND;
			break;

		case VAL_POSTCOND :
			Kind = (BYTE FAR *)TXT_POSTCOND;
			break;

		case VAL_INVARIANT :
			Kind = (BYTE FAR *)TXT_INVARIANT;
			break;

		case VAL_CHECK :
			Kind = (BYTE FAR *)TXT_CHECK;
			break;

		case VAL_NULLPTR :
			Kind = (BYTE FAR *)TXT_NULLPTR;
			break;

		default :
			Kind = (BYTE FAR *)TXT_UNKNOWN;
			break;
	}

	/* Regenere le texte de l'expression fautive */
	CheckExpr = TXT_CHECKEXPR;

	_ExcSetCtx(Kind,CheckExpr);
	_ExcThrow(1,filename,linenumber);
}

#endif


