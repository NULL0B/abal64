/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : ALD
 *	Fichier : LKECRAN.C
 *	Version : 2.1a
 *	Date    : 02/06/93
 *	Systeme : Tous
 *
 *	Gestion Fichier des acces ecrans
 *
 *	[Noyau ALD - Gestion ecran ]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	11/01/93 : Debut du codage
 *	17/12/93 : Affichage du code retoure d'une fonction
 *	18/11/94 : Avec /h la boite affichait pour la taille des Field=M
 *		la taille des descripteurs au lieu de la taille
 * 18/11/99 : (#OK) Bug ALD 3 fixed: if reference unresolved then generate error message.
 * 12/04/00 : (#SP) Bug ALD 11 fixed: bug with -I option.
 * 28/06/01 : Prefixage des messages d'erreur par "** Erreur:" suivant la langue en console WIN32 et Twin.
              Affichage du nom de fichier si non trouvé (ex: ALD aaa bbb).
 * 07/11/01 : En mode console Windows uniquement, pas d'affichage du nom de la cible.
 *	------------ 2.2b -------------------------------------------------
 */

#define _LKECRAN

#include "aldtype.h"
#include "lkdef.h"
#include "lkstruct.h"

#include "lkecran.h"
#include "lkfich.h"
#include "lkmes.h"
#include "lklist.h"
#include "lktable.h"
#include "lklib.h"
#ifndef	unix
#include "display.h"
#else
char	waBuffer[256];
void waDisplayAppendString(char * a)			{	printf("%s",a);					}
void waDisplayAppendChar  (char   a) 			{ 	printf("%c",a);					}
void waDisplayError       (char * a) 			{	printf("\n** error:%s **\n",a);			}
void waDisplayMessage     (char * a) 			{	printf("%s\n",a);				}
void waDisplay2Message    (char * a,char * b)		{ 	printf("%s %s\n",a,b);				}
void waDisplayWarningAtLine(char * a,int b,int c,int d)	{	printf("\nwarning %s %u %u %u %u\n",a,b,c,d);	}
void waDisplayLastMessage()				{	printf("\n");					}
#endif
#define waDISPLAY

char gLastFileName[LGREP];




VOID EcranSetLastFileAccessed( char XPTR * FilePath )
	{
	Xstrcpy(gLastFileName,FilePath);
	}

/*T*******************************
*	Fonction d'acces Ecran
*/

/*********************************
* FCT EcranInit
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*	Initialise les variables d' affichage 
*
**********************************/
VOID EcranInit()
	{
	EcranCico 	= 0;
	EcranLH		= 7;
	EcranCH		= 9;
	EcranBavard 	= 0;

	EcranSetLastFileAccessed("");

	#ifdef unix
	EcranSignalSet( 0 );
	#endif
	}

/*********************************
* FCT EcranSetCico
*
* Entree : 
*	le type d'effacement de l'ecran 0 ou 1 ou 2
*
* Sortie :
*	rien
*
* Remarques :
*
*	- verbose sert sous unix a ne pas effacer l'ecran pour l'integre
*	- init_term sert sous unix pour trapper les signaux 
*
**********************************/

int	init_term=0;

VOID EcranSetCico( typ )
BYTE typ;
	{
	/* init du cadre */
	#ifdef vms
	/* Jeux de caractere prologue */
	if (getenv("PROLOGUE") != GenericNULL(char) ) {
		C_CHG = (BYTE) 0x00DA;	/* coin haut et gauche */
		C_LNH =	(BYTE) 0x00C4;	/* ligne horizontale */
		C_CHD =	(BYTE) 0x00BF;	/* coin haut et droit */
		C_CBG =	(BYTE) 0x00C0;	/* coin bas et gauche */
		C_CBD =	(BYTE) 0x00D9;	/* coin bas et droit */
		C_LNV = (BYTE) 0x00B3;	/* ligne verticale */
	}
	#endif
	
	prndest = 1;
	prnfid  = 0;

	#ifdef vms
	qio_usage_flag = 0;
	#endif
	
	#ifdef unix
	if (typ == 2) 
		modterm(0);  /* sans effacement de l'ecran */
	#endif
	initerm();
	init_term=1;
	if ( typ == 1 ) 
		x_clear();

	EcranCico = 1;
	}


/*********************************
* FCT EcranFin
*
* Entree : 
*	rien
*		
* Sortie :
*	rien
*
**********************************/
VOID EcranFin()
	{
	if ( EcranCico ) 
		{
		pos(24,1);
		atb(26);
		atb(0);
		finterm(1);
		EcranCico = 0;
		}

	else 	
	   if (EcranBavard) 
			{
			waDisplayLastMessage();
			}

	#ifdef unix
	EcranSignalSet( 99 );  /* Liberation des signaux */
	#endif
	init_term = 0;
	}

/*********************************
* FCT EcranOutLong
*
* Entree : 
*	ligne
*	colonne	
*	valeur
* Sortie :
*	rien
*
* Remarque :
*	affichage d'un long
*
**********************************/

VOID EcranOutLong(ln,cl,val)
WORD ln;
WORD cl;
ULONG val;
/*	edition d'une valeur numerique (longue) en cours de traduction  */

{				/* outlong */
	#define MAX_DIGIT_FOR_LONG 8

	BYTE *p,*q,c,valeur[MAX_DIGIT_FOR_LONG],valcad[MAX_DIGIT_FOR_LONG];
	ULONG n;

	p = q = &valeur[0]; n = val;
	do 
		{
		*p++ = inttocar(n % 10L);
		}
	while ((n /= 10L) != 0L);
	*p = EOSTR;
	while (q < --p) 
		{
		c = *q; *q++ = *p; *p = c;
		}
		
	Xstrcpy(&valcad[0],"       ");
	Xstrcpy(&valcad[MAX_DIGIT_FOR_LONG-1-Xstrlen(&valeur[0])],&valeur[0]);
	pos(ln,cl);
	x_cprintf(&valcad[0]);
}				/* outlong */

/*********************************
* FCT EcranAffZone
*
* Entree : 
*	un message
*	longueur d'affichage
*	
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/

VOID EcranAffZone( pt, lgaff )
BYTE XPTR * 	pt;
WORD 		lgaff;
{
	WORD i;
	BOOL finlgn = FALSE;
/*	BYTE tmp[LGREP];*/

	for (i=0; i < lgaff; i++) 
		{
		if (!finlgn) 
			if (*pt == EOSTR) 
				finlgn = TRUE;

		if (finlgn)
			x_putch(' ');
		else	
			{
			x_putch((BYTE) (*pt));
			}
		pt++;
		}
	}

/*********************************
* FCT EcranCadre
*
* Entree : 
*	ligne haute gauche
*	colonne haute gauche
*	ligne basse droite
*	colonne basse droite
*
* Sortie :
*	rien
*
* Remarque :
*	dessin d'un 'cadre' avec les caracteres semi-graphiques
*	qui a pour positions diagonales (ld,cd) et (lf,cf)
*
**********************************/

VOID EcranCadre( ld, cd, lf, cf)
WORD ld;
WORD cd;
WORD lf;
WORD cf;
	{
	/* cadre */
	
#ifndef __WALD__
	/*
	Ne pas afficher de cadre dans la version windows
	*/

	WORD i,j,lg,ht,k;

	X_BSTART();

	EcranAtb(0);
	
	lg = (WORD) (cf - cd);
	pos(ld,cd); 

	x_putch(C_CHG);
	for (i = 1; i < lg; i++) 
		{
		x_putch(C_LNH);
		}
	x_putch(C_CHD);

	ht = (WORD) (lf - ld);
	j = (WORD) (ld + 1);
	for (i = 1; i < ht; i++, j++) 
		{
		pos(j,cd); x_putch(C_LNV);
		for (k=(WORD) (cd+1); k < cf; k++) x_putch(' ');
		pos(j,cf); x_putch(C_LNV);
		}
		
	pos(lf,cd); x_putch(C_CBG);
	for (i = 1; i < lg; i++)
		x_putch(C_LNH);
	x_putch(C_CBD);

	X_BFLUSH();
#endif /* __WALD__ */
	}					/* cadre */

/*********************************
* FCT EcranAtb
*
* Entree : 
*	attribut
*
* Sortie :
*	rien
*
* Remarque :
*	Gere la couleur sur les attributs video si le systeme le permet
*
**********************************/

VOID EcranAtb( c )
BYTE c;
	{
	if (c == 2) 
		{
	   if (conf(14) == 1) 
			{ 
			backgr(1);
			foregr(15);
			return;
		   }
		}
	if (c == 0) 
		{
		if (conf(14) == 1) 
			{ 
			backgr(4);
			foregr(11);
			return;
			}
		}
	atb(c);  	
	}

/*********************************
* EcranOutBin
*
* Entree : 
*	ligne
*	colonne
*	valeur
* Sortie :
*	rien
*
* Remarque :
*	Affichage d'une valeur binaire a une position 
*
**********************************/

VOID EcranOutBin( ln, cl, val)
WORD ln;
WORD cl;
WORD val;
	{				/* outbin */
	pos(ln,cl);
	EcranAffInt( val );
	}				/* outbin */

/*********************************
* FCT EcranAffInt
*
* Entree : 
*	valeur
*
* Sortie :
*	rien
*
* Remarque :
*	Affiche a une valeur WORD
*
**********************************/

VOID EcranAffInt( val )
WORD val;
	{
	#define MAX_DIGIT_FOR_INT 6
	
	BYTE 	*p,*q,c;
	BYTE	valeur[MAX_DIGIT_FOR_INT],valcad[MAX_DIGIT_FOR_INT];
	WORD n;

	p = q = &valeur[0]; 
	n = val;
	do {
		*p++ = inttocar(n % 10);
		}
	while ((n /= 10) != 0);
	*p = EOSTR;
	
	/*Invert the string */
	while (q < --p) 
		{
		c = *q; 
		*q++ = *p; 
		*p = c;
		}
		
	Xstrcpy(&valcad[0],"     ");
	Xstrcpy(&valcad[MAX_DIGIT_FOR_INT-1-Xstrlen(&valeur[0])],&valeur[0]);
	x_cprintf(&valcad[0]);
	}

/*********************************
* FCT EcranErreur
*
* Entree : 
*	numero de l'erreur
*		
* Sortie :
*	rien
* Remarque :
*	Affichage du libele d'erreur
*
**********************************/

VOID EcranErreur( err )
WORD err;

/*	affichage d'un message d'erreur
 */

{					
	/* msgerr */
	
	WORD j;
	if ( EcranCico ) 
	{
		X_BSTART();

		pos((WORD) (EcranLH+11),(WORD) (EcranCH+2));
		EcranAtb(2);
		x_cprintf(GetMessageLine(err));
		/* efface les eventuels messages plus grands */
		for (j = Xstrlen( GetMessageLine(err) ); j < EcranNbCOL - 2; j++)
			x_putch(' ');
		EcranAtb(0);

		X_BFLUSH();
	}
#ifdef	waDISPLAY
	else 
	{
#ifdef __WALD__
		if (GlobalShowConsole)
#endif
			waDisplayAppendString(GetMessageLine(MessageErr));

		if ((err == ErreurNoyau02) || (err == MessagePartage) || (err == MessageNonResol))
		{
			waDisplayAppendString(GetMessageLine(err));
			waDisplayAppendChar(' ');
			waDisplayError(gLastFileName);
		}
		else
		{
			waDisplayError(GetMessageLine(err));
		}
	}
#endif
}					/* msgerr */

/*********************************
* FCT EcranBoite
*
* Entree : 
* 	ligne	
*	colonne
* Sortie :
*	Composition du cadre d'information
*
**********************************/

VOID EcranBoite(LH, CH)
WORD LH;
WORD CH;
	{
#ifdef merde
	BYTE n_path[LGREP];
	#ifdef prologue
	/* JPH: replaced LGMXNOM by LGREP*/
	GetReper(n_path,LGREP); /* Implicite fichier */
	#else
	getcwd(n_path);
	#endif
#endif


	X_BSTART();

	atb(25);
	
	EcranCadre(LH,CH,(WORD)(LH+EcranNbLIG),(WORD)(CH+EcranNbCOL));
	pos((WORD) (LH+2),(WORD) (CH+3)); x_cprintf((BYTE XPTR *) GetMessageLine(MessageProg));
	pos((WORD) (LH+3),(WORD) (CH+3)); x_cprintf((BYTE XPTR *) GetMessageLine(MessageEncours));
	pos((WORD) (LH+4),(WORD) (CH+3)); x_cprintf((BYTE XPTR *) GetMessageLine(MessageAction));
		
	pos((WORD) (LH+6),(WORD) (CH+16) );
	x_cprintf((BYTE XPTR *) GetMessageLine(MessageProc));

	pos((WORD)(LH+7),(WORD)(CH+3));
	x_cprintf((BYTE XPTR *) GetMessageLine(MessageVariable) );
	pos((WORD)(LH+7),(WORD)(CH+23)); 
	x_putch('/');
	pos((WORD)(LH+7),(WORD)(CH+35)); 
	x_putch(C_LNV);
	pos((WORD)(LH+7),(WORD)(CH+40)); 
	x_cprintf((BYTE XPTR *) fieldm);


	pos((WORD)(LH+8),(WORD)(CH+3));  
	x_cprintf((BYTE XPTR *) GetMessageLine(MessageProcedure) );
	pos((WORD)(LH+8),(WORD)(CH+23)); 
	x_putch('/');
	pos((WORD)(LH+8),(WORD)(CH+35)); 
	x_putch(C_LNV);
	pos((WORD)(LH+8),(WORD)(CH+40)); 
	x_cprintf((BYTE XPTR *) fielde );

	pos((WORD)(LH+9),(WORD)(CH+3));  
	x_cprintf((BYTE XPTR *) GetMessageLine(MessageSegment) );
	pos((WORD)(LH+9),(WORD)(CH+23)); 
	x_putch('/');
	pos((WORD)(LH+9),(WORD)(CH+35)); 
	x_putch(C_LNV);
	pos((WORD)(LH+9),(WORD)(CH+40)); 
	x_cprintf((BYTE XPTR *) MesConst);

	X_BFLUSH();
	}

/*********************************
* FCT EcranProgram
*
* Entree : 
* 	un nom de programme
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage du programme en cours de traitement 
*
**********************************/
VOID EcranProgram( pt_nom )
BYTE XPTR * pt_nom;
{
	if ( EcranCico ) 
		{
		X_BSTART();
		
		pos((WORD) (EcranLH+2),(WORD) (EcranCH+3 + Xstrlen(GetMessageLine(MessageProg))));
		EcranAffZone(pt_nom,40);

		X_BFLUSH();
		}
#ifdef	waDISPLAY
	else 
		{
		if ( EcranBavard )
			{
			/* Affichage long */
			waDisplay2Message(GetMessageLine(MessageProg),pt_nom);
			}
		else
			{
			/* Affichage court */
			/* #BG 07/11/01 En mode console Windows, pas d'affichage du nom de la cible
			pour éviter que la fenêtre reste ouverte s'il n'y a pas d'erreur.
			Indispensable sous WABAL pour avoir le message "Edition des liens..."
			*/
#ifdef __WALD__
			if (!GlobalShowConsole)
#endif
				waDisplayMessage(pt_nom); 
			}
		}
#endif
}

/*********************************
* FCT EcranEnCours
*
* Entree : 
* 	un nom de programme
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage du module en cours de traitement 
*
**********************************/
VOID EcranEnCours( pt_nom )
BYTE XPTR * pt_nom;
{
	if ( EcranCico ) 
		{
		X_BSTART();
		
		pos
			(
			(WORD) (EcranLH+3),
			(WORD) (EcranCH+3 + Xstrlen(GetMessageLine(MessageEncours)))
			);
		EcranAffZone(pt_nom,40);
		
		X_BFLUSH();
		}
#ifdef	waDISPLAY
	else 
		{
		if (EcranBavard)
			{
			waDisplay2Message(GetMessageLine(MessageEncours), pt_nom);
			}
		}
#endif
}
/*********************************
* FCT EcranWhichError
*
* Entree : 
* 	un nom de programme
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage du module en cours de traitement 
*
**********************************/
VOID EcranWhichError( pt_nom )
BYTE XPTR * pt_nom;
{
	if ( EcranCico ) 
		{
		X_BSTART();
		
		pos((WORD)(EcranLH+10),(WORD)(EcranCH+2));
		EcranAtb(2);
		EcranAffZone(pt_nom,(WORD)(EcranNbCOL-2));
		EcranAtb(0);

		X_BFLUSH();
		}
#ifdef	waDISPLAY
	else 
		{
		waDisplayMessage(pt_nom);
		}
#endif
}

/*********************************
* FCT EcranAction
*
* Entree : 
* 	un numero d'action
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage du traitement en cours
*
**********************************/
VOID EcranAction( action )
WORD action;
{
	if ( EcranCico ) 
		{
		/*
			Show on panel
		*/
		/* clear action */
		X_BSTART();
		
		pos((WORD)(EcranLH+4),(WORD)(EcranCH+2+Xstrlen(GetMessageLine(MessageAction))) );
		EcranAffZone(GetMessageLine(action), 40 );
		
		X_BFLUSH();
		}
#ifdef	waDISPLAY
	else if (EcranBavard) 
		{
		waDisplay2Message(GetMessageLine(MessageAction),GetMessageLine(action));
		}
#endif
}

/*********************************
* FCT EcranPasse
*
* Entree : 
* 	le numero de passe
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage du nombre de passe
*
**********************************/
VOID EcranPasse( numero )
WORD numero;
{
	if ( EcranCico ) 
		{
		/* clear action */

		X_BSTART();

		pos((WORD)(EcranLH+4),(WORD)(EcranCH+2+Xstrlen( GetMessageLine(MessageAction) )));
		EcranAtb(0);
		EcranAffZone(GetMessageLine(MessagePasse), 40);
		EcranOutBin
			(
			(WORD)(EcranLH+4), 
			(WORD)
				(
				EcranCH+2 + Xstrlen( GetMessageLine(MessageAction) ) + 
				Xstrlen( GetMessageLine(MessagePasse) ) + 1
				), 
			numero
			);

		X_BFLUSH();
		}
#ifdef	waDISPLAY
	else 
		if (EcranBavard)
			{
			sprintf 
				(
				waBuffer,
				"%s%s %d",
				GetMessageLine(MessageAction), GetMessageLine(MessagePasse), numero
				);
		
			waDisplayMessage(waBuffer);
			}
#endif
}

/*********************************
* FCT EcranAncrage
*
* Entree : 
* 	un noeud pointant sur un argument
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage d'un ancrage
*
**********************************/
VOID EcranAncrage(pt_anc, out)
Ancrage XPTR *	pt_anc;
BYTE XPTR *	out;
	{
	switch (pt_anc->field) 
		{
		case MFIN:
			sprintf(&out[Xstrlen(out)],"%s ", GetMessageLine(MessageMFin) );
			break;

		case MINSERT:
			sprintf
				(
				&out[Xstrlen(out)],
				"%s %s ", GetMessageLine(MessageMIns), 
				pt_anc->label 
				);
			break;

		case MRECOUVRE:
			sprintf(&out[Xstrlen(out)],"%s ", GetMessageLine(MessageMRec) );
			break;

		case EFIN:
			sprintf(&out[Xstrlen(out)],"%s ", GetMessageLine(MessageEFin) );
			break;

		case EINSERT:
			sprintf(&out[Xstrlen(out)],"%s %s ", GetMessageLine(MessageEIns), pt_anc->label );
			break;

		case ERECOUVRE:
			sprintf(&out[Xstrlen(out)],"%s ", GetMessageLine(MessageERec) );
			break;
		};
	}

/*********************************
* FCT EcranVar
*
* Entree : 
* 	un noeud pointant sur un argument
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage d'une variable
*
**********************************/
VOID EcranVar( infvar, pt_var, out)
InfoVar XPTR *	infvar;
LstPro XPTR *	pt_var;
BYTE XPTR *	out;
	{
 
	sprintf(&out[Xstrlen(out)]," %s", GetMessageLine(MessageAncParathese) );
	
	if (infvar->ptr & 0x02 ) 
		{
		sprintf( &out[Xstrlen(out)], " %s ", GetMessageLine(MessagePtr) );
		}

	if (infvar->ptr == 1) 
		{
		sprintf( &out[Xstrlen(out)], " %s ", GetMessageLine(MessagePt) );
		}
	
	sprintf( &out[Xstrlen(out)], " %s", pt_var->nom );
	switch ( infvar->type ) 
		{
		case TBCD:
			sprintf( &out[Xstrlen(out)], "=%d", infvar->longueur );
			
			break;
		case TSTR:
			sprintf( &out[Xstrlen(out)], "%s=%d", "$", infvar->longueur );

			break;
		case TBIN1:
			sprintf( &out[Xstrlen(out)], "%s", "#" );
			break;
		case TBIN2:
			sprintf( &out[Xstrlen(out)], "%s", "%" );
			break;
		}
		
	if (infvar->dim1) 
		{
		sprintf( &out[Xstrlen(out)], "(%d", infvar->dim1 );
		if (infvar->dim2) 
			{
			sprintf( &out[Xstrlen(out)], ",%d", infvar->dim2 );
			}
		sprintf( &out[Xstrlen(out)], ")");
		}
	}

/*********************************
* FCT EcranArgument
*
* Entree : 
* 	un noeud pointant sur un argument
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage d'un argument de procedure
*
**********************************/
VOID EcranArgument(pt_node, out)
C_SNODE FAR *	pt_node;
BYTE XPTR *	out;
	{
	Args XPTR * r;

	if ( pt_node ) 
		{
		EcranArgument( SnodeGetNext( pt_node ), out );

		if ( SnodeGetNext( pt_node ) ) 
			{
			Xstrcat(&out[Xstrlen(out)],",");
			}

		r = SnodeGet( pt_node );

		switch (r->typ_arg & 0x03) 
			{
			case TBIN1:
				Xstrcat(&out[Xstrlen(out)],"#");
				break;
			case TBIN2:
				Xstrcat(&out[Xstrlen(out)],"%");
				break;
			case TBCD:
				Xstrcat(&out[Xstrlen(out)],"*");
				break;
			case TSTR:
				Xstrcat(&out[Xstrlen(out)],"$");
				break;
			}
		}
	}

/*********************************
* FCT EcranProcedure
*
* Entree : 
* 	un nom de procedure
*	le nom du module ou est declaree la procedure
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage d'une procedure
*
*/

VOID EcranProcedure(LstPro * p, BYTE XPTR * out )
	{
	BYTE bufout[LGREP];
	BYTE type_retour;

 	/* Affichage du nom */
	sprintf(bufout," %s %s(", GetMessageLine(MessageProcParathese),p->nom );
	Xstrcat( out, bufout );

	/* affichage des arguments */
	SlistRewind( p->pt_args );
	EcranArgument( SlistGetNext(p->pt_args), out );	
	Xstrcat(out,")");

	/* affichage du type de retour */
	if ( p->ext.nb_args & 0x800 ) 
		{
		/* c'est une fonction */
		Xstrcat(out," : ");
		if (p->ext.nb_args & 0x8000) 
			{
			/* la valeur de retour est un pointeur */
			Xstrcat(out,"Ptr ");
			}
		type_retour =  (BYTE) ((p->ext.nb_args & 0x3000) >> 12);
		switch( type_retour ) 
			{
			case TBIN1:
				Xstrcat(out,"#");
				break;
			case TBIN2:
				Xstrcat(out,"%");
				break;
			case TBCD:
				Xstrcat(out,"*");
				break;
			case TSTR:
				Xstrcat(out,"$");
				break;
			};
		}
	}

/*********************************
* FCT EcranSegment
*
* Entree : 
* 	un nom de segment
*	un nom de module ou est declare le segment
*
* Sortie :
*	rien
*
* Remarque :
*	Affichage d'un segment 
*
**********************************/
VOID EcranSegment(LstPro * p, BYTE XPTR * out)
	{
	BYTE bufout[LGREP];

 	/* Affichage du nom */
	sprintf(bufout," %s %s", GetMessageLine(MessageSegParathese),p->nom );
	Xstrcat( out, bufout );

	if (p->ext.num_seg != MOINS_UN)
		{
		sprintf( bufout, " as %d ", p->ext.num_seg );
		Xstrcat( out, bufout );
		}
	}

VOID EcranBoiteMaj( LH, CH, fic )
WORD LH;
WORD CH;	
Fichier XPTR * fic;
	{
	if (EcranCico != 0)
		{
	
		/*
			Met a jour les statistiques dans l'ecran ?
	
		*/
	
		X_BSTART();

		EcranOutBin
			(
			(WORD)(LH+7),
			(WORD)(CH+3 +  Xstrlen( GetMessageLine(MessageVariable)) + 1 ), 
			fic->nb_var_solved 
			);
		EcranOutBin
			(
			(WORD)(LH+7),
			(WORD)(CH+3 +  Xstrlen( GetMessageLine(MessageVariable) )+ 1 + 5 + 5 ), 
			ListCountVarExt( fic->liste_ancrage ) 
			);
		EcranOutBin
			(
			(WORD)(LH+7),
			(WORD)(CH+40+  Xstrlen( fieldm ) + 2), 
			TableGetVarTaille( &(fic->Tvar) ) 
			);
		
	
		EcranOutBin
			(
			(WORD)(LH+8),
			(WORD)(CH+3 + Xstrlen(GetMessageLine(MessageProcedure))+1), 
			fic->nb_pro_solved 
			);
		EcranOutBin
			(
			(WORD)(LH+8),
			(WORD)(CH+3 + Xstrlen(GetMessageLine(MessageProcedure))+1+ 5 + 5 ), 
			ListCountProExt( fic->liste_pro_ext ) 
			);
		EcranOutLong
			(
			(WORD)(LH+8),
			(WORD)(CH+40+ Xstrlen( fielde )),  
			(ULONG) FichierGetAdrEtendue( &(fic->code) ) 
			);
	
		EcranOutBin
			(
			(WORD)(LH+9),
			(WORD)(CH+3 + Xstrlen( GetMessageLine(MessageSegment) )+1 ), 
			fic->nb_seg_solved 
			);
		EcranOutBin
			(
			(WORD)(LH+9),
			(WORD)(CH+3 + Xstrlen( GetMessageLine(MessageSegment) )+1+ 5 + 5 ), 
			ListCountSegExt( fic->liste_seg_ext ) 
			);
		EcranOutBin
			(
			(WORD)(LH+9),
			(WORD)(CH+40+ Xstrlen( MesConst ) + 2 ), 
			TableGetReloc( &(fic->Tcst) ) 
			);
	
		X_BFLUSH();
		}
	//else
	//
	//	Output statistic ? (Which one ?)
	//
	}


VOID EcranAffNonResolus( option, fic )
Option * option;
Fichier XPTR * fic;
{
	C_SNODE FAR * pt_node;
	LstPro XPTR * pt_extern;
	Ancrage XPTR * pt_anc;
	InfoVar varext;
	
	BYTE buf[LGREP];
	BYTE out[LGREP];

/*	WORD lg;*/
/*	BYTE c;*/

			
	if ( option->output ) 
		EcranClearBox();

	EcranBavard = 1;

	EcranInitOutErr(option);

/* #OK: 18/11/99 ALD 3 (begin) */
/*	EcranOutErr( option, GetMessageLine(MessageNonResol) );	Commented by #OK */
/* #SP: 12/04/00 ALD 11(begin) */
/*	EcranErreur(MessageNonResol); Commented by #SP */

  if (!CheckNonResolus(fic)) {
      EcranOutErr(option, GetMessageLine(MessageNonResol) );
      EcranOutErr(option, GetMessageLine(MessageToutResol) );
  } else EcranErreur(MessageNonResol); 

/* #SP: 12/04/00 ALD 11 (end) */
/* #OK: 18/11/99 ALD 3 (end) */

	/* Liste des variables externes non resolues */
	SlistRewind( fic->liste_ancrage );
	pt_node = SlistGetNext( fic->liste_ancrage );
	while ( pt_node ) 
		{
		pt_anc = SnodeGet( pt_node );

		out[0] = EOSTR;

		SlistRewind( pt_anc->liste_varext );
		pt_node = SlistGetNext( pt_anc->liste_varext );
		if ( pt_node ) 
			{
			if (option->bavard == 2) 
				{
				EcranAncrage( pt_anc, out );
				if ( EcranOutErr( option, out ) ) 
					return;
				}
			}
			
		while( pt_node ) 
			{
			pt_extern = SnodeGet( pt_node );

			out[0] = EOSTR;

			if ( pt_extern->solved == MOINS_UN ) 
				{
				/* recherche ou est definit l'extern */
				if ( pt_extern->module ) 
					{
					ListGetNomModule( option->liste_mod , pt_extern->module, buf );
					}
				else 
					{
					/* extern definit dans le programme principal */
					ListGetNomModule( option->liste_prg, pt_extern->module, buf );
					}

				Xstrcat( out, buf ); 
				TableGetVar
					(
					&(fic->Tvarext), 
					pt_extern->ext.adr_desc, 
					&varext 
					);
				if ( pt_anc->field == MALL) 
					{
					/* On n'affiche que le nom */
					sprintf
						(
						&out[Xstrlen(out)], 
						" %s %s", 
						GetMessageLine(MessageAncParathese),
						pt_extern->nom
						);
					}
				else 
					EcranVar( &varext, pt_extern, out);
					
				if (pt_extern->par_qui != MOINS_UN ) 
					{
					Xstrcat( out, " in " );
					ListGetNameFromNum
						(
						fic->liste_mod_ext, 
						pt_extern->par_qui, 
						buf 
						);
					Xstrcat( out, buf );
					}

				if (EcranOutErr( option, out )) 
					return;
				}
			pt_node = SlistGetNext( pt_anc->liste_varext );
			}
		pt_node = SlistGetNext( fic->liste_ancrage );
		}

	/* Liste des procedures externes non resolues */

	SlistRewind( fic->liste_pro_ext );
	pt_node = SlistGetNext( fic->liste_pro_ext );
	while ( pt_node ) 
		{
		pt_extern = SnodeGet( pt_node );
		out[0] = EOSTR;
		buf[0] = EOSTR;
		if ( pt_extern->solved == MOINS_UN && SlistCount(pt_extern->pt_ref) != 0) 
			{
			/* recherche ou est definit l'extern */
			if ( pt_extern->module ) 
				{
				ListGetNomModule
					(option->liste_mod , pt_extern->module, buf);
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule
					(option->liste_prg, pt_extern->module, buf);
				}

			Xstrcat( out, buf ); 
			EcranProcedure( pt_extern, out);
			if (pt_extern->par_qui != MOINS_UN ) 
				{
				Xstrcat( out, " in " );
				ListGetNameFromNum
					(fic->liste_mod_ext, pt_extern->par_qui, buf);
				Xstrcat( out, buf );
				}

			if ( EcranOutErr( option, out ) ) 
				return;

			}
		pt_node = SnodeGetNext( pt_node );
		}

	/* Liste des segments externes non resolues */

	SlistRewind( fic->liste_seg_ext );
	pt_node = SlistGetNext( fic->liste_seg_ext );
	while ( pt_node ) 
		{
		pt_extern = SnodeGet( pt_node );
		out[0] = EOSTR;

		if (
			(pt_extern->solved == MOINS_UN) && 
				(
				SlistCount(pt_extern->pt_ref) ||
				(pt_extern->ext.num_seg != MOINS_UN)
				)
			) 
			{
			/* recherche ou est definit l'extern */
			if ( pt_extern->module ) 
				{
				ListGetNomModule( option->liste_mod , pt_extern->module, buf );
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule
					(option->liste_prg, pt_extern->module, buf );
				}

			Xstrcat( out, buf ); 
			EcranSegment( pt_extern, out);
			if (pt_extern->par_qui != MOINS_UN ) 
				{
				Xstrcat( out, " in " );
				ListGetNameFromNum
					( fic->liste_mod_ext, pt_extern->par_qui, buf );
				Xstrcat( out, buf );
				}

			if ( EcranOutErr( option, out ) ) 
				return;
			}
		pt_node = SnodeGetNext( pt_node );
		}

	/* Liste des variables externes non resolues */
	}

VOID EcranAffPublic( option, fic )
Option * option;
Fichier XPTR * fic;
	{
	C_SNODE FAR * node;
	ModPro XPTR * proc_pub;

	LstPro pt_extern;		/* variable de travail */
	
	BYTE out[LGREP];

	WORD i;

#ifdef Merde
	Ancrage XPTR * pt_anc;
	InfoVar varext;
	BYTE buf[LGREP];
	WORD lg;
	BYTE c;
#endif
			
	if ( option->output ) EcranClearBox();

	EcranBavard = 1;

	EcranInitOutErr(option);
	EcranOutErr( option, " Pub " );

#ifdef Merde
	/* Liste des externs variables */
	SlistRewind( fic->liste_ancrage );
	pt_node = SlistGetNext( fic->liste_ancrage );
	while ( pt_node ) 
		{
		pt_anc = SnodeGet( pt_node );

		out[0] = EOSTR;

		EcranAncrage( pt_anc, out );

		if ( EcranOutErr( option, out ) ) 
			return;

		SlistRewind( pt_anc->liste_varext );
		pt_node = SlistGetNext( pt_anc->liste_varext );
		while( pt_node ) 
			{
			pt_extern = SnodeGet( pt_node );
			out[0] = EOSTR;

			if ( pt_extern->solved == MOINS_UN ) 
				{
				/* recherche ou est definit l'extern */
				if ( pt_extern->module ) 
					{
					ListGetNomModule( option->liste_mod , pt_extern->module, buf );
					}
				else 
					{
					/* extern definit dans le programme principal */
					ListGetNomModule( option->liste_prg, pt_extern->module, buf );
					}

				Xstrcat( out, buf ); 
				TableGetVar( &(fic->Tvarext), pt_extern->ext.adr_desc, &varext );
				if ( pt_anc->field == MALL) 
					{
					/* On affiche que le nom */
					sprintf( &out[Xstrlen(out)], " %s %s", GetMessageLine(MessageAncParathese),pt_extern->nom );
					}
				else 
					EcranVar( &varext, pt_extern, out);
					
				if (pt_extern->par_qui != MOINS_UN ) 
					{
					Xstrcat( out, " in " );
					ListGetNameFromNum( fic->liste_mod_ext, pt_extern->par_qui, buf );
					Xstrcat( out, buf );
					}

				if (EcranOutErr( option, out )) 
					return;
				}
			pt_node = SlistGetNext( pt_anc->liste_varext );
			}
		pt_node = SlistGetNext( fic->liste_ancrage );
		}

	/* Liste des extern proc non resol */

	SlistRewind( fic->liste_pro_ext );
	pt_node = SlistGetNext( fic->liste_pro_ext );
	while ( pt_node ) 
		{
		pt_extern = SnodeGet( pt_node );
		out[0] = EOSTR;
		buf[0] = EOSTR;
		
		if ( pt_extern->solved == MOINS_UN && SlistCount(pt_extern->pt_ref) != 0) {
			/* recherche ou est definit l'extern */
			if ( pt_extern->module ) 
				{
				ListGetNomModule( option->liste_mod , pt_extern->module, buf );
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule( option->liste_prg, pt_extern->module, buf );
				}

			Xstrcat( out, buf ); 
			EcranProcedure( pt_extern, out);
			if (pt_extern->par_qui != MOINS_UN ) 
				{
				Xstrcat( out, " in " );
				ListGetNameFromNum( fic->liste_mod_ext, pt_extern->par_qui, buf );
				Xstrcat( out, buf );
				}

			if ( EcranOutErr( option, out ) ) 
				return;

			}
		pt_node = SnodeGetNext( pt_node );
		}

	/* Liste des externs seg non resol */

	SlistRewind( fic->liste_seg_ext );
	pt_node = SlistGetNext( fic->liste_seg_ext );
	while ( pt_node ) 
		{
		pt_extern = SnodeGet( pt_node );
		out[0] = EOSTR;

		if ( pt_extern->solved == MOINS_UN && ( SlistCount(pt_extern->pt_ref)  || pt_extern->ext.num_seg != MOINS_UN )) 
			{
			/* recherche ou est definit l'extern */
			if ( pt_extern->module ) 
				{
				ListGetNomModule( option->liste_mod , pt_extern->module, buf );
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule( option->liste_prg, pt_extern->module, buf );
				}

			Xstrcat( out, buf ); 
			EcranSegment( pt_extern, out);
			if (pt_extern->par_qui != MOINS_UN ) 
				{
				Xstrcat( out, " in " );
				ListGetNameFromNum( fic->liste_mod_ext, pt_extern->par_qui, buf );
				Xstrcat( out, buf );
				}

			if ( EcranOutErr( option, out ) ) 
				return;

			}
		pt_node = SnodeGetNext( pt_node );
		}
	/* Liste des externs var non resol */
#endif

	/* liste des variables public */
	for (i=0; i < HTV; i++) 
		{
		SlistRewind( fic->liste_var_pub[i] );
		node = SlistGetNext( fic->liste_var_pub[i] );
		while ( node ) 
			{
			proc_pub = SnodeGet( node );

			XstrCpySize(pt_extern.nom, proc_pub->nom ,sizeof(pt_extern.nom));
			pt_extern.ext.nb_args = 0;
			pt_extern.pt_args = 0;

			out[0] = EOSTR;

			sprintf(out,"(V) %s ", pt_extern.nom);
			if (EcranOutErr( option, out )) return;

			node = SlistGetNext( fic->liste_var_pub[i] );
			}
		}


	/* liste des procedures publiques */
	for (i=0; i < HTV; i++) 
		{
		SlistRewind( fic->liste_pro_pub[i] );
		node = SlistGetNext( fic->liste_pro_pub[i] );
		while ( node ) 
			{
			proc_pub = SnodeGet( node );

			XstrCpySize(pt_extern.nom, proc_pub->nom, sizeof(pt_extern.nom) );
			pt_extern.ext.nb_args = proc_pub->pub.nb_args;
			pt_extern.pt_args = proc_pub->pt_args;

			out[0] = EOSTR;

			EcranProcedure( &pt_extern, out);
			if (EcranOutErr( option, out )) 
				return;

			node = SlistGetNext( fic->liste_pro_pub[i] );
			}
		}
	}

VOID EcranAffResolus( option, fic )
Option * option;
Fichier XPTR * fic;
	{
	C_SNODE FAR * pt_node;
	LstPro XPTR * pt_extern;
	Ancrage XPTR * pt_anc;
	InfoVar varext;
	
	BYTE buf[LGREP];
	BYTE out[LGREP];

/*	WORD lg;*/
/*	BYTE c;*/

			
	if ( option->output ) 
		EcranClearBox();

	EcranBavard = 1;

	EcranInitOutErr(option);
/*
	EcranOutErr( option, GetMessageLine(MessageNonResol) );
*/
	/* Liste des externs variables */
	SlistRewind( fic->liste_ancrage );
	pt_node = SlistGetNext( fic->liste_ancrage );
	while ( pt_node ) 
		{
		pt_anc = SnodeGet( pt_node );

		out[0] = EOSTR;


		SlistRewind( pt_anc->liste_varext );
		pt_node = SlistGetNext( pt_anc->liste_varext );
		if ( pt_node ) 
			{
			if (option->bavard == 2) 
				{
				EcranAncrage( pt_anc, out );
				if ( EcranOutErr( option, out ) ) 
					return;
				}
			}
			
		while( pt_node ) 
			{
			pt_extern = SnodeGet( pt_node );


			out[0] = EOSTR;

			if ( pt_extern->solved != MOINS_UN ) 
				{
				/* recherche ou est definit l'extern */
				if ( pt_extern->module ) 
					{
					ListGetNomModule( option->liste_mod , pt_extern->module, buf );
					}
				else
					{
					/* extern definit dans le programme principal */
					ListGetNomModule( option->liste_prg, pt_extern->module, buf );
					}

				Xstrcat( out, buf ); 
				TableGetVar( &(fic->Tvarext), pt_extern->ext.adr_desc, &varext );
				if ( pt_anc->field == MALL) 
					{
					/* On affiche que le nom */
					sprintf( &out[Xstrlen(out)], " %s %s", GetMessageLine(MessageAncParathese), pt_extern->nom );
					}
				else 
					EcranVar( &varext, pt_extern, out);
					
				if (pt_extern->par_qui != MOINS_UN ) 
					{
					Xstrcat( out, " in " );
					ListGetNameFromNum( fic->liste_mod_ext, pt_extern->par_qui, buf );
					Xstrcat( out, buf );
					}

				Xstrcat( out,"(");
				if ( pt_extern->par_qui ) 
					{
					ListGetNomModule( option->liste_mod , pt_extern->par_qui, buf );
					}
				else 
					{
					/* extern definit dans le programme principal */
					ListGetNomModule( option->liste_prg, pt_extern->par_qui, buf );
					}
				Xstrcat( out, buf ); 
				Xstrcat( out, ")");

				if (EcranOutErr( option, out )) 
					return;
				}
			pt_node = SlistGetNext( pt_anc->liste_varext );
			}
		pt_node = SlistGetNext( fic->liste_ancrage );
		}

	/* Liste des extern proc non resol */

	SlistRewind( fic->liste_pro_ext );
	pt_node = SlistGetNext( fic->liste_pro_ext );
	while ( pt_node ) 
		{
		pt_extern = SnodeGet( pt_node );
		out[0] = EOSTR;
		buf[0] = EOSTR;
		if ( pt_extern->solved != MOINS_UN ) 
			{
			/* recherche ou est definit l'extern */
			if ( pt_extern->module ) 
				{
				ListGetNomModule( option->liste_mod , pt_extern->module, buf );
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule( option->liste_prg, pt_extern->module, buf );
				}

			Xstrcat( out, buf ); 
			EcranProcedure( pt_extern, out);
			if (pt_extern->par_qui != MOINS_UN ) 
				{
				Xstrcat( out, " in " );
				ListGetNameFromNum( fic->liste_mod_ext, pt_extern->par_qui, buf );
				Xstrcat( out, buf );
				}

			Xstrcat( out,"(");
			if ( pt_extern->par_qui ) 
				{
				ListGetNomModule( option->liste_mod , pt_extern->par_qui, buf );
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule( option->liste_prg, pt_extern->par_qui, buf );
				}
			Xstrcat( out, buf ); 
			Xstrcat( out, ")");

			if ( EcranOutErr( option, out ) ) 
				return;

			}
		pt_node = SnodeGetNext( pt_node );
		}

	/* Liste des externs seg non resol */

	SlistRewind( fic->liste_seg_ext );
	pt_node = SlistGetNext( fic->liste_seg_ext );
	while ( pt_node ) 
		{
		pt_extern = SnodeGet( pt_node );

		out[0] = EOSTR;

		if ( pt_extern->solved != MOINS_UN ) 
			{
			/* recherche ou est definit l'extern */
			if ( pt_extern->module ) 
				{
				ListGetNomModule( option->liste_mod , pt_extern->module, buf );
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule( option->liste_prg, pt_extern->module, buf );
				}

			Xstrcat( out, buf ); 
			EcranSegment( pt_extern, out);
			if (pt_extern->par_qui != MOINS_UN ) 
				{
				Xstrcat( out, " in " );
				ListGetNameFromNum( fic->liste_mod_ext, pt_extern->par_qui, buf );
				Xstrcat( out, buf );
				}

			Xstrcat( out,"(");
			if ( pt_extern->par_qui ) 
				{
				ListGetNomModule( option->liste_mod , pt_extern->par_qui, buf );
				}
			else 
				{
				/* extern definit dans le programme principal */
				ListGetNomModule( option->liste_prg, pt_extern->par_qui, buf );
				}
			Xstrcat( out, buf ); 
			Xstrcat( out, ")");

			if ( EcranOutErr( option, out ) ) 
				return;

			}
		pt_node = SnodeGetNext( pt_node );
		}

	/* Liste des externs var non resol */
	}

VOID EcranInitOutErr( pt_option )
Option XPTR * pt_option;
{
	if (pt_option->output) 
		{
		EcranLg = 1;
		}
	
}

VOID EcranEndOutErr( pt_option )
Option XPTR * pt_option;
{

}

WORD EcranOutErr( pt_option, out ) 
Option XPTR * pt_option;
BYTE XPTR * out;
{
	/*	BYTE c;*/

	/* je possede une ligne a afficher */
	if ( pt_option->output ) 
		{
		/* sortie sous integre */
		pos( (WORD)(EcranLH + EcranLg), (WORD)(EcranCH + 3));
		EcranAffZone( out, EcranNbCOL - 4 );
		EcranLg ++;
		if ( EcranLg == EcranNbLIG - 1 ) 
			{

			if (EcranMsgMore() == MOINS_UN ) 
				return( MOINS_UN );

			EcranClearBox();
			EcranLg = 1;
			}
		}
#ifdef	waDISPLAY
	else 
		{
		/* sortie a la ligne de commande */
		waDisplayMessage(out);
		}

#endif
	return( 0 );
}


VOID EcranClearBox()
	{
#ifndef __WALD__
	WORD i,j;

	X_BSTART();

	EcranAtb(0);
	
	for (i=2; i < EcranNbLIG; i ++) 
		{
		pos((WORD)(EcranLH+i), (WORD)(EcranCH+2));
		for (j=1; j < EcranNbCOL-1; j++) 
			x_putch(' ');
		}

	X_BFLUSH();
#endif
	}

WORD EcranMsgMore()
{
	#ifdef __WALD__
	waDisplayPause(GetMessageLine(MessageMore));
	#else
	BYTE c;

#if (defined (_DOS) || defined (PRL))
	EcranErreur( MessageMore );
	EcranErreur( MessageMore );
#else
	EcranErreur( MessageMore );
	EcranErreur( MessageMore );
#endif
	

	c = (BYTE) x_getch();
	if ( c == CR ) 
		return( MOINS_UN );
	#endif

	return 0;	// JPH added
	}

VOID EcranSetBavard()
	{
	EcranBavard = 1;
	}
	
	
	
VOID EcranWarningFichier( ctConstStr FilePath )
	{
	if ( EcranCico ) 
		{
		/*
			Show on panel
		*/
		/* TO_BE ... implemented */
		}
#ifdef	waDISPLAY
	else if (EcranBavard) 
		{
		waDisplayAppendString(GetMessageLine(ErreurNoyau02));
		waDisplayAppendChar(' ');
		waDisplayWarningAtLine(FilePath,0,0,1);
		}
#endif
}


/* #SP: 12/04/00 ALD 11 (begin) */
/* This new function detects if there were any unresolved references */
WORD CheckNonResolus(fic)
Fichier XPTR * fic;
{
	C_SNODE FAR * pt_node;
	LstPro XPTR * pt_extern;
	Ancrage XPTR * pt_anc;

	/* Liste des externs variables */
	SlistRewind( fic->liste_ancrage );
	pt_node = SlistGetNext( fic->liste_ancrage );
	while ( pt_node ){
		pt_anc = SnodeGet( pt_node );
		SlistRewind( pt_anc->liste_varext );
		pt_node = SlistGetNext( pt_anc->liste_varext );
		while( pt_node ){
			pt_extern = SnodeGet( pt_node );
			if ( pt_extern->solved == MOINS_UN )
				return 1;
			pt_node = SlistGetNext( pt_anc->liste_varext );
		}
		pt_node = SlistGetNext( fic->liste_ancrage );
	}

	/* Liste des extern proc non resol */
	SlistRewind( fic->liste_pro_ext );
	pt_node = SlistGetNext( fic->liste_pro_ext );
	while ( pt_node ){
		pt_extern = SnodeGet( pt_node );
		if ( pt_extern->solved == MOINS_UN && SlistCount(pt_extern->pt_ref) != 0)
			return 1;
		pt_node = SnodeGetNext( pt_node );
	}

	/* Liste des externs seg non resol */
	SlistRewind( fic->liste_seg_ext );
	pt_node = SlistGetNext( fic->liste_seg_ext );
	while ( pt_node ) {
		pt_extern = SnodeGet( pt_node );
		if ((pt_extern->solved == MOINS_UN) && (SlistCount(pt_extern->pt_ref) || (pt_extern->ext.num_seg != MOINS_UN)))
		  return 1;
		pt_node = SnodeGetNext( pt_node );
	}

	return 0;
}
/* #SP: 12/04/00 (end) */
	
	
/********************* 	Gestion Des Signaux *********************/

#ifdef unix

#ifndef  prologue
#ifndef  msdos

#include <signal.h>		/* Signal function definitions header	*/

/*
 *	EcranSignalSortie ( sigid )
 *	-----------------
 *	Allows reception of the signal SIGTERM : SOFTWARE TERMINATION
 *	and performs a graceful exit to the operating system after
 *	terminal liberation and Purge of Co-Executeur Locking Infos
 */

static	void EcranSignalSortie( sigid )
int	sigid;
	{
					/* -------------------- */
	if ( EcranCico ) 
		(void) finterm(0);	/* stty sane please	*/
	
	#ifndef __WALD__
	lkprintf("\r\n");
	#endif

	(void) PurgeLox();		/* liberate all files	*/

	exit(0);			/* and die gracefully	*/

					/* -------------------- */
	}

/*
 *	EcranSignalSet ( sigid )
 *	-------------------------
 *	Performs system exception signal management for Executeur under 
 *	UNIX like operating systems that offer the SIGNAL() function
 *		sigid = Signal number
 *	Note : 
 *		Sigid = 0	==>	Initialise signal trapping
 *		Sigid = 99	==>	Liberate signal trapping
 *
 */	

VOID EcranSignalSet( sigid )
WORD sigid;
	{
	switch ( sigid ) 
		{
		case 0  :	/* Initialisation of SIGNAL TRAP */
			/* ----------------------------- */
/* #IJM 06/11/02
			(void) signal(SIGBUS , EcranSignalSet);
			(void) signal(SIGSEGV, EcranSignalSet);
*/
			(void) signal(SIGTERM, EcranSignalSortie);
			break;

		case 99 :	/* Liberation of Trapped Signals */
			/* ----------------------------- */
/* #IJM 06/11/02
			(void) signal(SIGBUS , SIG_DFL );
			(void) signal(SIGSEGV, SIG_DFL );
*/
			(void) signal(SIGTERM, SIG_DFL );
			break;

		default :	/* Handling of Received signals  */
			/* ----------------------------- */

			if ( EcranCico ) 
				{
				(void) x_cprintf("\r\n");
				(void) x_cprintf("  ALD Signal : ");
				(void) x_putch(' ');
				(VOID) EcranAffInt ( (WORD) sigid );
				}
			else 
				{
				lkprintf("\r\n    ALD Signal : %d", sigid);
				}
			(void) EcranSignalSet( 99 );
			EcranSignalSortie( 99 );				
		}
	return;
	}

	/* ------------ */
#endif	/* ! DOS 	*/
#endif	/* ! PROLOGUE	*/
	/* ------------ */
#endif	/* unix 	*/




