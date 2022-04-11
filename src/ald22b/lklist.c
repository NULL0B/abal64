
/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : ALD
 *	Fichier : LKECRAN.C
 *	Version : 2.2b
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
 *	17/12/93 : Correction dans ListPatcher() Offset pour variables Opt
 *	23/02/94 : Ajout de la proc‚dure ListCountExt
 *	25/02/94 : Transformation de ListCountExt En ListCountProExt et
 *			ListCountSegExt
 * 14/04/94 : Rajout d'un else dans ListIsProExtPub
 *			Cas d'un extern pub in ANY
 *			Modif etendue a ListIsSegExtPub et ListIsAncragePub
 * 14/09/00 : (#AT) Changes for extension of tables of global and local variables.
 * 22/11/00 : (#OK & #SP) Bug fixed bounded with constants and and GV > 32k.
 *	------------ 2.2b -------------------------------------------------
 */

#define _LKLIST

#include "aldtype.h"
#include "lkstruct.h"


#include "lklist.h"
#include "lkfich.h"
#include "lkfile.h"
#include "lktable.h"

#include "lkmes.h"
#include "lkecran.h"
#include "lklib.h"

#include "pubslist.h"
#include "fn_parse.h"
#ifndef __PUBSLIST_H__
#include "pubslist.h"
#endif

#include "display.h"

#ifdef DBGTRC
	extern FILE * fdbgtrc;
#endif


/*********************************
*
* FCT ListAllouer
*
* Entree : 
*	rien
*
* Sortie :
*	rien
*
* Remarque :
*	initialise les listes Publiques
*
* Voir aussi:
*
*
**********************************/
VOID ListAllouer()
{
	WORD i;

	for (i=0; i < 10; i ++)
		ListPatch[i] = SlistCreate();

}


VOID ListLiberer()
{
	WORD i;

	ListDelPatch( ListPatchTete );

	for (i=0; i < 10; i ++) {
		ListDelPatch( ListPatch[ i ] );
		INIT_SLIST( ListPatch[i] );
	}
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
VOID ListCalculHashValue( token,  htv,  hlv)
BYTE XPTR * token;
WORD XPTR * htv;
WORD XPTR * hlv;
{
	WORD i;

	for (i = (WORD) 0; *token; i+=*(token++) );
	*htv = (WORD) (i % HTV);
	*hlv = (WORD) (i % HLV);

	return;
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
Args XPTR * ListNewArgs( argu )
BYTE argu ;
{
	Args XPTR * q;

	ALLOC_STRUCT(q, Args);

	q->typ_arg = argu;

	return( q );
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
ModPro XPTR * ListNewPro( nom, num_module, relo, proc_app, adr_map, lg_map, nb_argument, hlv)
BYTE XPTR * nom;
WORD num_module;
WORD relo;
WORD proc_app;
WORD adr_map;
WORD lg_map;
WORD nb_argument;
WORD hlv;
{
//JPH	WORD i;
	ModPro XPTR * proc;
	
	ALLOC_STRUCT( proc, ModPro );

	proc->used = MOINS_UN;
	proc->num_module = num_module;
	proc->hash_code = hlv;

	XstrCpySize(proc->nom, nom, sizeof(proc->nom));

	proc->num_desc = relo;
	proc->proc_app = proc_app;
	proc->adr_map  = adr_map;
	proc->lg_map   = lg_map;

	proc->pub.nb_args = nb_argument;
	INIT_SLIST( proc->pt_args );

	return( proc );	
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
Label XPTR * ListIsLabelPub( liste, label )
C_SLIST FAR *	liste;
BYTE XPTR *	label;
{
	Label XPTR * pp;

//JPH	C_SLIST FAR * pt_liste;
	C_SNODE  FAR * pt_node;
//JPH	WORD htv, hlv;
//JPH	WORD i;	

	/* calcule de la hash liste de la procedure extern */

	if (label[0] != EOSTR ) {

		SlistRewind( liste );
	
		pt_node = SlistGetNext( liste );
		while ( pt_node ) {
	
			/* avant de comparer les noms on test si c'est le meme hash_code */
			/* on compare les noms */

			pp   = SnodeGet( pt_node );

			if ( ! Xstrcmp( pp, label) ) {
				/* C'est bon */
				return( pp );
			}
		
			pt_node = SnodeGetNext( pt_node );
	
		}
	}

	return( GenericNULL( Label ) );
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
ModPro XPTR * ListIsCstPub( liste, pe )
C_SLIST FAR * liste[];
ModPro  XPTR * pe;
{
	ModPro XPTR * pp;

//JPH	C_SLIST FAR * pt_liste;

	C_SNODE  FAR * node;

//JPH	WORD htv, hlv;

	WORD i;	

	/* calcule de la hash liste de la procedure extern */

	if (pe != GenericNULL( ModPro ) ) {
		for (i=0; i < HTV; i++) {
			SlistRewind( liste[i] );
			node = SlistGetNext( liste[ i ] );
			while ( node ) {
				pp = SnodeGet( node );
				if (pp->hash_code == pe->hash_code ) {
					if (! Xstrcmp( pp->nom, pe->nom ) ) {
						return( pp );
					}
				}
				node = SlistGetNext( liste[ i ] );
			}
		}
	}

	return( GenericNULL( ModPro ) );
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
ModPro XPTR * ListIsVarPub( liste, pe, res, mod )
C_SLIST FAR * liste[];
LstPro XPTR * pe;
Fichier XPTR * res;
Fichier XPTR * mod;
{
	ModPro XPTR * pp;

//JPH	C_SLIST FAR * pt_liste;

	C_SNODE  FAR * node;

//JPH	WORD htv, hlv;

	WORD i;	

//JPH	WORD nom;

	/* calcule de la hash liste de la procedure extern */

	if (pe != GenericNULL( LstPro ) ) {
		for (i=0; i < HTV; i++) {
			SlistRewind( liste[i] );
			node = SlistGetNext( liste[ i ] );
			while ( node ) {
				pp = SnodeGet( node );

				if (pp->hash_code == pe->hash_code ) {
					if (! Xstrcmp( pp->nom, pe->nom ) ) {
						if ( res == mod ) {
							/* on traite que les variables du programme */
							if ( pp->num_module == NUM_RES )
								return( pp );							
						}
						else return( pp );
					}
				}
				node = SlistGetNext( liste[ i ] );
			}
		}
	}

	return( GenericNULL( ModPro ) );
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
ModPro XPTR * ListIsProPub( liste, pe )
C_SLIST FAR * liste[];
LstPro XPTR * pe;
{
	ModPro XPTR * pp;

	C_SLIST FAR * pt_liste;

	C_SNODE  FAR * pt_node;

	WORD htv, hlv;

//JPH	WORD i;	

	/* calcule de la hash liste de la procedure extern */

	if (pe != GenericNULL( LstPro ) ) {
		ListCalculHashValue(pe->nom, &htv, &hlv);

		pt_liste = liste[ htv ];

		SlistRewind( pt_liste );
	
		pt_node = SlistGetNext( pt_liste );
		while ( pt_node ) {
	
			/* avant de comparer les noms on test si c'est le meme hash_code */
			/* on compare les noms */

			pp   = SnodeGet( pt_node );

			if ( ListMatchPro( pp, pe) ) {
				/* C'est bon */
				return( pp );
			}
		
			pt_node = SnodeGetNext( pt_node );
	
		}
	}

	return( GenericNULL( ModPro ) );
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
ModPro XPTR * ListIsSegPub( liste, se )
C_SLIST FAR * liste[];
LstPro XPTR * se;
{

	ModPro XPTR * sp;

	C_SLIST FAR * pt_liste;

	C_SNODE  FAR * pt_node;

	WORD htv, hlv;

//JPH	WORD i;	

	/* calcule de la hash liste de la procedure extern */

	if (se != GenericNULL( LstPro ) ) {
		ListCalculHashValue(se->nom, &htv, &hlv);

		pt_liste = liste[ htv ];

		SlistRewind( pt_liste );
	
		pt_node = SlistGetNext( pt_liste );
		while ( pt_node ) {
	
			/* avant de comparer les noms on test si c'est le meme hash_code */
			/* on compare les noms */

			sp   = SnodeGet( pt_node );

			if ( ListMatchSeg( sp, se) ) {
				/* C'est bon */
				return( sp );
			}
		
			pt_node = SnodeGetNext( pt_node );
	
		}
	}

	return( GenericNULL( ModPro ) );

}

/*********************************
* FCT ListIsProExtPub
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*	xxx 
*
**********************************/
LstPro XPTR * ListIsProExtPub( liste, pe, res, mod )
C_SLIST FAR * liste; 
LstPro XPTR * pe;
Fichier XPTR * res;
Fichier XPTR * mod;
{
	LstPro XPTR * pp;
	C_SNODE  FAR * pt_node;
//JPH	WORD htv, hlv;
//JPH	WORD i;	
	BYTE nom_res[LGIDENT];
	BYTE nom_mod[LGIDENT];


	/* calcule de la hash liste de la procedure extern */

	if (pe != GenericNULL( LstPro ) ) {

		SlistRewind( liste );
	
		pt_node = SlistGetNext( liste );
		while ( pt_node ) {
	
			/* avant de comparer les noms on test si c'est le meme hash_code */
			/* on compare les noms */

			pp   = SnodeGet( pt_node );

			if ( ListMatchProExt( pp, pe) ) {
				/* C'est bon */
				if ( pe->par_qui == MOINS_UN ) return( pp ); /* pas de contrainte particulière */
															/* modif du 08/11/94 */
																
				if ( pe->par_qui != MOINS_UN && pp->par_qui != MOINS_UN ) {
					ListGetNameFromNum( mod->liste_mod_ext, pe->par_qui, nom_mod );
					ListGetNameFromNum( res->liste_mod_ext, pp->par_qui, nom_res );

					if (! Xstrcmp(nom_mod, nom_res) )
						return( pp );
				}

				
#ifdef _m14_04_94
				if ( pe->par_qui == MOINS_UN && pp->par_qui == MOINS_UN ) 
					 	return( pp ); /* Modif du 14/04/94 */
					/* Cas d'un extern ANY et pas l'autre */
				
#endif
			}
		
			pt_node = SnodeGetNext( pt_node );
	
		}
	}

	return( GenericNULL( LstPro ) );
}

/*********************************
* FCT ListIsSegExtPub
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*	xx 
*
**********************************/
LstPro XPTR * ListIsSegExtPub( liste, se, res, mod )
C_SLIST FAR * liste;
LstPro XPTR * se;
Fichier XPTR * res;
Fichier XPTR * mod;

{

	LstPro XPTR * sp;
	C_SNODE  FAR * pt_node;
//JPH	WORD htv, hlv;
//JPH	WORD i;	
	BYTE nom_mod[LGIDENT];
	BYTE nom_res[LGIDENT];

	/* calcule de la hash liste de la procedure extern */

	if (se != GenericNULL( LstPro ) ) {

		SlistRewind( liste );
	
		pt_node = SlistGetNext( liste );
		while ( pt_node ) {
	
			/* avant de comparer les noms on test si c'est le meme hash_code */
			/* on compare les noms */

			sp   = SnodeGet( pt_node );

			if ( ListMatchSegExt( sp, se) ) {
				/* C'est bon */
				if ( se->par_qui == MOINS_UN ) return( sp );

				if ( se->par_qui != MOINS_UN && sp->par_qui != MOINS_UN ) {
					ListGetNameFromNum( mod->liste_mod_ext, se->par_qui, nom_mod );
					ListGetNameFromNum( res->liste_mod_ext, sp->par_qui, nom_res );

					if (! Xstrcmp(nom_mod, nom_res) )
						return( sp );
				}
#ifdef _14_04_94
				if ( se->par_qui == MOINS_UN && sp->par_qui == MOINS_UN ) 
					return( sp ); /* Modif du 14/04/94 */
#endif
			}
		
			pt_node = SnodeGetNext( pt_node );
	
		}
	}

	return( GenericNULL( LstPro ) );

}

Ancrage XPTR * ListIsAncragePub( liste, se, res, mod )
C_SLIST FAR * liste;
Ancrage XPTR * se;
Fichier XPTR * res;
Fichier XPTR * mod;
{

	Ancrage XPTR * sp;

	C_SNODE  FAR * pt_node;

//JPH	WORD i;	

	BYTE nom_res[LGIDENT];
	BYTE nom_mod[LGIDENT];

	/* calcule de la hash liste de la procedure extern */

	if (se != GenericNULL( Ancrage) ) {

		SlistRewind( liste );
	
		pt_node = SlistGetNext( liste );
		while ( pt_node ) {
	
			/* avant de comparer les noms on test si c'est le meme hash_code */
			/* on compare les noms */

			sp   = SnodeGet( pt_node );

			if ( ListMatchAncrage( sp, se) ) {
				/* C'est bon */

				if ( se->par_qui == MOINS_UN ) return( sp );

				if ( se->par_qui != MOINS_UN && sp->par_qui != MOINS_UN ) {
					ListGetNameFromNum( mod->liste_mod_ext, se->par_qui, nom_mod );
					ListGetNameFromNum( res->liste_mod_ext, sp->par_qui, nom_res );

					if (! Xstrcmp(nom_mod, nom_res) )
						return( sp );
				}
#ifdef _14_04_94
				if ( se->par_qui == MOINS_UN && sp->par_qui == MOINS_UN )
					return( sp ); /* Modif du 14/04/94 */
#endif
			}
		
			pt_node = SnodeGetNext( pt_node );
	
		}
	}

	return( GenericNULL( Ancrage ) );

}

LstPro XPTR * ListIsVarExtPub( liste, se )
C_SLIST FAR * liste;
LstPro XPTR * se;

{

	LstPro XPTR * sp;
	C_SNODE  FAR * pt_node;
//JPH	WORD htv, hlv;
//JPH	WORD i;	

	/* calcule de la hash liste de la procedure extern */

	if (se != GenericNULL( LstPro ) ) {

		SlistRewind( liste );
	
		pt_node = SlistGetNext( liste );
		while ( pt_node ) {
	
			/* avant de comparer les noms on test si c'est le meme hash_code */
			/* on compare les noms */

			sp   = SnodeGet( pt_node );

			if ( !Xstrcmp(sp->nom, se->nom) ) {
				/* C'est bon */
				return( sp );
			}
		
			pt_node = SnodeGetNext( pt_node );
	
		}
	}
	return( GenericNULL( LstPro ) );
}


/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
VOID ListNewOff( liste, octet, off, valeur)
C_SLIST FAR * liste;
BYTE octet;
WORD off;
WORD valeur;
{
	Offset *o;
	Offset *last;
	Offset *onode;

	C_SNODE FAR * pt_node;
	C_SNODE FAR * last_node;


	SlistRewind( liste );

	last_node = GFN( C_SNODE );
	pt_node = SlistGetNext( liste );

	/* Recherche un off existant */
	while ( pt_node ) {
		o = SnodeGet( pt_node );

		if ( (o->val_off & 0x00ff ) == ( off & 0x00ff ) ) {
			/* Mise a jour de valeur */
			if (valeur != 0xffff) {
				if (valeur != 0xfffe) {
					o->valeur = valeur;
				}
				else {
					if (o->valeur == 0xffff) {
						o->valeur = valeur;
					}
				}
				o->octet = octet;
			}
#ifndef VERSION_XX
		/* #AT: 22/11/00 (begin) */
		if ((bIsGlobalVariable) && (o->val_off & 0xff00))
			o->bIsGlobalVariable = 0;
		else
			o->bIsGlobalVariable = bIsGlobalVariable;
		/* #AT: 22/11/00 (end) */
#endif
			return;			
		}	
		else {
			if ((o->val_off & 0x00ff)  < ( off & 0x00ff ) ) {
				last_node = pt_node;

				pt_node = SlistGetNext( liste );
				if ( pt_node == GFN( C_SNODE ) )
					SlistSetCurrent( liste, last_node );
			}
			else {
				/* on vient de trouver un majorant */
				/* insertion sur last_node */

				ALLOC_SNODE( pt_node );

				if ( last_node == GFN( C_SNODE ) ) {
					SlistAddHead( liste, pt_node );
				}
				else {
					SlistSetCurrent( liste, last_node );
					SlistAddCurrent( liste, pt_node );
				}

				ALLOC_STRUCT( o, Offset);
				SnodeSet(pt_node, o);
		
				o->valeur = valeur;
				o->octet  = octet;
				o->val_off = off;
#ifndef VERSION_XX
		/* #AT: 22/11/00 (begin) */
		if ((bIsGlobalVariable) && (o->val_off & 0xff00))
			o->bIsGlobalVariable = 0;
		else
			o->bIsGlobalVariable = bIsGlobalVariable;
		/* #AT: 22/11/00 (end) */
#endif

#ifdef __TRACE_PATCH
				/* la liste est elle triee */
				SlistRewind( liste );
				last_node = GFN( C_SNODE );
				pt_node = SlistGetNext( liste );
				while ( pt_node ) {
					last_node = pt_node;
					pt_node = SlistGetNext( liste );
					if ( pt_node == GFN( C_SNODE) ) break;
					last = SnodeGet( last_node );
					onode = SnodeGet( pt_node );
					if ( (last->val_off & 0x00ff) > (onode->val_off & 0x00ff))
						{
						waDisplayMessage("Desordre Current");
						}
					else {
						last_node = pt_node;
					}
				}
#endif

				return;
			}
		}
	}

	/* liste vide ou en fin de liste */
	ALLOC_SNODE( pt_node );
	SlistAddCurrent( liste, pt_node );

	ALLOC_STRUCT( o, Offset);
	SnodeSet(pt_node, o);
		
	o->valeur = valeur;
	o->octet  = octet;
	o->val_off = off;
#ifndef VERSION_XX
   /* #AT: 22/11/00 (begin) */
	if ((bIsGlobalVariable) && (o->val_off & 0xff00))
		o->bIsGlobalVariable = 0;
	else
		o->bIsGlobalVariable = bIsGlobalVariable;
   /* #AT: 22/11/00 (end) */
#endif

#ifdef __TRACE_PATCH
	/* la liste est elle triee */
	SlistRewind( liste );
	last_node = GFN( C_SNODE );
	pt_node = SlistGetNext( liste );
	while ( pt_node ) {
		last_node = pt_node;
		pt_node = SlistGetNext( liste );
		if ( pt_node == GFN( C_SNODE) ) break;
		last = SnodeGet( last_node );
		onode = SnodeGet( pt_node );
		if ( (last->val_off & 0x00ff) > (onode->val_off & 0x00ff) ) {
			waDisplayMessage("Desordre Tail");
		}
		else {
			last_node = pt_node;
		}
	}
#endif
}

VOID ListNewBloc( liste, octet, num_mod, fic, bloc, off, valeur)
C_SLIST FAR * liste;
BYTE octet;
BYTE num_mod;
Tabfic XPTR * fic;
WORD bloc;
WORD off;
WORD valeur;
{
	Patch *p;
//JPH	Offset *o;
	
	C_SNODE XPTR * pt_node;
	
	SlistRewind( liste );
	pt_node = SlistGetNext( liste );
	
	while( pt_node ) {
		p = SnodeGet( pt_node );

	
		if (p->bloc == bloc && num_mod == p->fic) {
			ListNewOff(p->off, octet, off, valeur);
			break;
		}	
		else {
			pt_node = SlistGetNext( liste );
		}
	}

	if ( ! pt_node ) {
		/* bloc non trouve insertion d'un nouveau element */
		ALLOC_SNODE( pt_node );
		SlistAddHead( liste, pt_node);

		ALLOC_STRUCT( p, Patch );
		SnodeSet( pt_node, p );

		p->fic = num_mod;
		INIT_SLIST( p->off );

		p->new_fic = fic;
		p->bloc = bloc;
		if (octet == 0xff ) {
			p->new_bloc = bloc;		/* Cas des patch d'adr de la table des noms de var. */
			octet = 0;
		}
		else	p->new_bloc = 0;
 	
		ALLOC_SLIST( p->off );

		/* Je le fais maintenant car si il ya un debordement memoire */
		/* cela ne vient pas alterer la liste des blocs */

		ListNewOff( p->off, octet, off  , valeur );
	}
}

VOID ListRelocVarPatch( fic, liste_ref, valeur , adr )
Fichier XPTR * fic;
C_SLIST FAR * liste_ref;
WORD valeur;
WORD adr;
{
	LstRef XPTR * pt_ref;
	C_SNODE FAR * pt_node;

	SlistRewind( liste_ref );
	pt_node = SlistGetNext( liste_ref );
	while ( pt_node ) {
		pt_ref = SnodeGet( pt_node );
		if ( pt_ref->off & 0xff00 )
			ListMajPatch( 0, pt_ref->prog, &(fic->code), pt_ref->bloc, pt_ref->off, adr); /* pour les optimisations du traducteur */
		else	ListMajPatch( 0, pt_ref->prog, &(fic->code), pt_ref->bloc, pt_ref->off, valeur);
		pt_node = SnodeGetNext( pt_node );
	}
}
VOID ListRelocPatch( fic, liste_ref, valeur , octet )
Fichier XPTR * fic;
C_SLIST FAR * liste_ref;
WORD valeur;
BYTE octet;
{
	LstRef XPTR * pt_ref;
	C_SNODE FAR * pt_node;

	SlistRewind( liste_ref );
	pt_node = SlistGetNext( liste_ref );
	while ( pt_node ) {
		pt_ref = SnodeGet( pt_node );
		ListMajPatch( octet, pt_ref->prog, &(fic->code), pt_ref->bloc, pt_ref->off, valeur);
		pt_node = SnodeGetNext( pt_node );
	}
}

VOID ListMajPatch( octet, num_mod, fic, bloc, off, valeur) 
BYTE octet;
BYTE num_mod;
Tabfic XPTR * fic;
WORD bloc;
WORD off;
WORD valeur;
{
	BYTE bool;
	WORD i;

	/* Parcours les blocs existants */
	bool = 1;
	i = (WORD) (bloc % 10);

	ListNewBloc(ListPatch[ i ],octet,num_mod, fic, bloc, off, valeur);

}


VOID ListMatchPatch( s_fic, s_nb, d_fic, d_nb)
BYTE s_fic;
WORD s_nb;
Tabfic XPTR * d_fic;
WORD d_nb;
{
	Patch *p;
	WORD i;
	
	C_SLIST FAR * pt_liste;
	C_SNODE FAR * pt_node;

	
	i = (WORD) (s_nb % 10);
	pt_liste = ListPatch[i];

	SlistRewind( pt_liste );
	pt_node = SlistGetNext( pt_liste );

	while ( pt_node ) {
		p = SnodeGet( pt_node );
		if ((p->fic == s_fic) && (p->bloc == s_nb)) {
			/* Ce bloc change de place */
			p->new_fic = d_fic;
			p->new_bloc = d_nb;
 			break;
		}
		else {
			pt_node = SlistGetNext( pt_liste );
		}
	}
}

VOID ListReorgPatch()

{
	WORD i;
	WORD precond;
	WORD postcond;

	BOOL  insertion;

	Patch XPTR * item;
	Patch XPTR * patch_item;

	C_SNODE FAR * patch_node;
	C_SNODE FAR * prev_node;

	C_SNODE FAR * node;
		
	
	INIT_SLIST( ListPatchTete );
	ALLOC_SLIST( ListPatchTete );

	precond = ListHLPatchNbOff( ListPatch );

	for (i=0; i< 10; i++) {
		ListGoFirst( ListPatch[ i ] );
		node = SlistExtractNode( ListPatch[ i ] );
		while ( node ) {
			item = SnodeGet( node );
		        if ( SlistIsEmpty( ListPatchTete ) ) {
				/* liste vide -> insertion en tete */
				SlistAddHead( ListPatchTete, node );
				SlistSetCurrent( ListPatchTete, node );
			   }
			   else {

				insertion = FALSE;
/*
				patch_node = SlistGetCurrent( ListPatchTete );
				patch_item = SnodeGet( patch_node );
*/
				ListGoFirst( ListPatchTete );

				patch_node = SlistGetCurrent( ListPatchTete );
				patch_item = SnodeGet( patch_node );

				if ( patch_item->new_bloc > item->new_bloc ) {
					patch_node = SlistGetHead( ListPatchTete );
					patch_item = SnodeGet( patch_node );

					if ( patch_item->new_bloc > item->new_bloc ) {
						/* le nouveau est plus petit que la tete */
						SlistAddHead( ListPatchTete, node );
						SlistSetCurrent( ListPatchTete, SlistGetHead( ListPatchTete ) );
						insertion = TRUE;
					}				
				}
				while ( ! insertion ) {
					if ( patch_item->new_bloc == item->new_bloc ) {									
						/* Concatener les offsets */
						if ( patch_item->new_bloc == 0 ) {
							ListConcat( patch_item->off, item->off );
						}
						ListDelNode( node );

						insertion = TRUE;
					}		
					else {
						prev_node = patch_node;
						patch_node = SlistGetNext( ListPatchTete );

						if ( ! patch_node ) {
							/* fin de liste ajout en queue */
							SlistSetCurrent( ListPatchTete, prev_node );
							SlistAddCurrent( ListPatchTete, node );
							insertion = TRUE;
						}
						else {
							patch_item = SnodeGet( patch_node);
							if ( patch_item->new_bloc > item->new_bloc ) {
								/* On a trouve un majorant */
								SlistSetCurrent( ListPatchTete, prev_node );
								SlistAddCurrent( ListPatchTete, node );
								insertion = TRUE;
							}
						} 
						
					}
				}
			}
			node = SlistExtractNode( ListPatch[ i ] );
		}		
	}

#ifdef __TRACE_PATCH
	SlistRewind( ListPatchTete );
	prev_node = GFN( C_SNODE );
	patch_node = SlistGetNext( ListPatchTete );
	while ( patch_node ) {
		prev_node = patch_node;
		patch_node = SlistGetNext( ListPatchTete );
		if ( patch_node == GFN( C_SNODE) ) break;
		item = SnodeGet( prev_node );
		patch_item = SnodeGet( patch_node );
		if ( item->new_bloc > patch_item->new_bloc) {

			waDisplayMessage("Desordre Reorg Current");
		}
		else {
			prev_node = patch_node;
		}
	}
#endif

	postcond = ListPatchNbOff( ListPatchTete );

	INVARIANT ( precond == postcond );

}

/*********************************
* FCT LibCmpBib
*
* Entree : 
*	bibliotheque A
*	de bibliotheque B 		
*
* Sortie :
*	identiques 	: 0
*	non identiques	: 1
*
* Remarque :
*	Compare deux noms de bib. dyn.
*	Cas particulier :
*	   meme nom mais repertoire different ==> erreur FATALE
*
**********************************/

BOOL ListMatchBib( bib1, bib2 )
Bibli XPTR * bib1;
Bibli XPTR * bib2;
{
	BYTE tmp1[LGNOMBIB];
	BYTE tmp2[LGNOMBIB];

	Xfn_parser( bib1->nom,  tmp1, FILE_NAME);
	Xfn_parser( bib2->nom,  tmp2, FILE_NAME);

	if ( ! Xstrcmp(tmp1, tmp2)) {
		/* les noms sont les memes */
		if ( ! Xstrcmp(bib1->nom, bib2->nom)) {
			return(0);
		}
		else {
			/* meme nom mais repertoire different */
			THROW( MessageConbib );
		}
	}
	return(1);
}


BOOL ListMatchCst( pp, pe )
InfoCst XPTR * pp;
InfoCst XPTR * pe;
{
	WORD i;

	if ( pp->type != pe->type) return( FALSE );
	if (pp->longueur != pe->longueur ) return( FALSE );
	for (i=0; i < pp->longueur; i++) 
		{
		if ( pp->valeur[i] != pe->valeur[i] ) {
			return( FALSE );
		}
	}
	return( TRUE );
}

BOOL ListMatchAncrage( ap, ae )
Ancrage XPTR * ap;
Ancrage XPTR * ae;
{
	if ( ap->field != ae->field ) return( FALSE );
	if ( Xstrcmp( ap->label, ae->label ) ) return( FALSE );

	return( TRUE );
}

BOOL ListMatchVar( pp, pe )
InfoVar XPTR * pp;
InfoVar XPTR * pe;
{
/*
	C'est trop fort pour eux ....
	if ( pp->descripteur != pe->descripteur ) return( FALSE );
	if ( pp->tptr != pe->tptr ) return( FALSE );
*/
	if ( pp->etendue != pe->etendue ) return( FALSE );
	if ( pp->virtuelle != pe->virtuelle ) return( FALSE );
	if ( pp->ptr != pe->ptr ) {
		/*	Prg    	Module 
			Extern	Ptr y$	
			dcl x$  FM, y
					dcl x$
		*/
		if ( pp->tptr != 2 ) return( FALSE );
	}
	if ( pp->type != pe->type ) return( FALSE );
	if ( pp->longueur != pe->longueur) return( FALSE );
	if ( pp->dim1 != pe->dim1 ) return( FALSE );
	if ( pp->dim2 != pe->dim2 ) return( FALSE );

	return( TRUE );
}

BOOL ListMatchPro( pp, pe )
ModPro XPTR * pp;
LstPro XPTR * pe;
{
	C_SNODE FAR * node_pe;
	C_SNODE FAR * node_pp;
	Args XPTR * pe_arg;
	Args XPTR * pp_arg;

	/* test la valeur de hash coding */
	if ( pp->hash_code != pe->hash_code ) return( FALSE );


	/* test les arguments */
/*
	if ( SlistCount( pp->pt_args ) == SlistCount( pe->pt_args ) ) {
*/

	if ( pp->pub.nb_args == pe->ext.nb_args ) {

		/* Les 2 procedures ont le meme nombre d'argument */
		/* et la meme valeur de retour */
		/* On va les comprarer */

		/* test le nom */
		if ( Xstrcmp( pp->nom, pe->nom) ) return( FALSE );

		SlistRewind( pp->pt_args );
		SlistRewind( pe->pt_args );
	
		node_pe = SlistGetNext( pe->pt_args );
		node_pp	= SlistGetNext( pp->pt_args );

		while( node_pp ) {
			pp_arg = SnodeGet( node_pp );
			pe_arg = SnodeGet( node_pe );
					
			if ( pe_arg->typ_arg != pp_arg->typ_arg ) return( FALSE );

			node_pp = SnodeGetNext( node_pp );
			node_pe = SnodeGetNext( node_pe );
		}
		return( TRUE );
	}
	return( FALSE );
}

BOOL ListMatchSeg( sp, se )
ModPro XPTR * sp;
LstPro XPTR * se;
{
//JPH	C_SNODE FAR * node_se;
//JPH	C_SNODE FAR * node_sp;

	/* test la valeur de hash coding */
	if ( sp->hash_code != se->hash_code ) return( FALSE );

	/* test le nom */
	if ( Xstrcmp( sp->nom, se->nom) ) return( FALSE );

	return( TRUE );
}

BOOL ListMatchProExt( pp, pe )
LstPro XPTR * pp;
LstPro XPTR * pe;
{
	C_SNODE FAR * node_pe;
	C_SNODE FAR * node_pp;
	Args XPTR * pe_arg;
	Args XPTR * pp_arg;

	/* test la valeur de hash coding */
	if ( pp->hash_code != pe->hash_code ) return( FALSE );


	/* test les arguments */

	if ( SlistCount( pp->pt_args ) == SlistCount( pe->pt_args ) ) {
		/* Les 2 procedures ont le meme nombre d'argument */
		/* On va les comprarer */

		/* test le nom */
		if ( Xstrcmp( pp->nom, pe->nom) ) return( FALSE );

		SlistRewind( pp->pt_args );
		SlistRewind( pe->pt_args );
	
		node_pe = SlistGetNext( pe->pt_args );
		node_pp	= SlistGetNext( pp->pt_args );

		while( node_pp ) {
			pp_arg = SnodeGet( node_pp );
			pe_arg = SnodeGet( node_pe );
					
			if ( pe_arg->typ_arg != pp_arg->typ_arg ) return( FALSE );

			node_pp = SnodeGetNext( node_pp );
			node_pe = SnodeGetNext( node_pe );
		}
		return( TRUE );
	}
	return( FALSE );
}

BOOL ListMatchSegExt( sp, se )
LstPro XPTR * sp;
LstPro XPTR * se;
{
//JPH	C_SNODE FAR * node_se;
//JPH	C_SNODE FAR * node_sp;

	/* test la valeur de hash coding */
	if ( sp->hash_code != se->hash_code ) return( FALSE );

	/* test le nom */
	if ( Xstrcmp( sp->nom, se->nom) ) return( FALSE );

	return( TRUE );
}

ModPro XPTR * ListGetProCall(liste, num)
C_SLIST FAR * liste[];
WORD num;
{
//JPH	WORD relo;
	ModPro XPTR * p_tmp;

	C_SNODE XPTR * pt_node;

	WORD i;	

	/* calcule de la hash liste de la procedure extern */
	/* La liste est close */

	p_tmp = GenericNULL( ModPro );

	/* Calcul de la hash liste */

	for (i=0; i < HTV; i++) {
		pt_node = SlistGetHead( liste[i] );
		while (pt_node) {
			p_tmp = SnodeGet( pt_node );
			if (p_tmp->num_desc == num) {
				return( p_tmp );
			}
			pt_node = SnodeGetNext( pt_node );
		}
	}
return( p_tmp ); //JPH: Makes compilers happier
}

BOOL ListExtUsed( prog, bloc)
BYTE prog;
WORD bloc;
{
	C_SNODE FAR * pt_node;
	C_SNODE FAR * offset_node;

	WORD index_liste;
	
	Patch *pt_bloc;
	Offset *pt_ofst;


	/* Parcours les blocs existants */
	/*
	   Je selectionne la liste adequate correspondante au numero
	   de bloc recherche dans le but d'elager au maximum
	   le nombre de test inutil 
	*/

	index_liste = bloc % 10;

	SlistRewind( ListPatch[ index_liste ] );

	
	pt_node  = SlistGetNext( ListPatch[index_liste] );
	
	while ( pt_node) {
		pt_bloc = SnodeGet( pt_node );


		if (pt_bloc->bloc == bloc && prog == pt_bloc->fic)  {
		 /* existe il une valeur d'offset == 0xfffe */

			SlistRewind( pt_bloc->off );
			offset_node = SlistGetNext( pt_bloc->off );

			while (offset_node ) {
				pt_ofst = SnodeGet( offset_node );
				if (pt_ofst->valeur == 0xfffe) {
					/* utilisee */
					return( TRUE );
				}
				offset_node = SnodeGetNext( offset_node );
			}
		}
		pt_node = SnodeGetNext( pt_node );
	}	

	/* non trouve */

	return( FALSE );
}


VOID ListGetNomModule( liste, num, nomret)
C_SLIST FAR * liste;
WORD num;
BYTE XPTR * nomret;
{
	C_SNODE FAR * pt_node;
	Fichier XPTR *  pt_fic;
 
	if (num == 0) {
		/* c'est le programme */
		pt_fic = SnodeGet( SlistGetCurrent( liste ));
		Xstrcpy(nomret, pt_fic->code.nom );
		return;
	}

	/* C'est dans un module */

	pt_node = SlistGetHead( liste );
	while (pt_node ) {
		pt_fic = SnodeGet( pt_node );
		if ( pt_fic->NUM_PRG == num ) {
			Xstrcpy(nomret, pt_fic->code.nom );
			return;
		}

		pt_node = SnodeGetNext( pt_node );
	}
}

VOID ListVideModule( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;
	Fichier XPTR * pt_fic;

	if (liste == GFN( C_SLIST) ) return;

	ListGoFirst( liste );
	pt_node = SlistExtractNode( liste );
	while ( pt_node )  {
		
		pt_fic = SnodeGet( pt_node );

		FichierFermer( pt_fic );

		ListDelNode( pt_node );
		pt_node = SlistExtractNode( liste );
	}

	SlistDelete( liste );	
}

VOID ListDelNode( node )
C_SNODE FAR * node;
{
	VOID FAR * item;

	item = SnodeGet( node );
	if ( item ) {
		FREE_ALLOC( item , VOID FAR );
	}
	SnodeDelete( node );
}

VOID ListDelPatch( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;
	Patch XPTR * item;

	if (liste == GFN( C_SLIST) ) return;

	ListGoFirst( liste );
	pt_node  = SlistExtractNode( liste );
	while ( pt_node ) {
		item = SnodeGet( pt_node );

		ListDel( item->off );
		INIT_SLIST( item->off );

		ListDelNode( pt_node );
		pt_node = SlistExtractNode( liste );
	}
	SlistDelete( liste );
}

VOID ListDelPub( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;
	ModPro XPTR * pt_pub;
	
	if (liste == GFN( C_SLIST) ) return;

	ListGoFirst( liste );
	pt_node = SlistExtractNode( liste );
	while ( pt_node ){
		pt_pub = SnodeGet( pt_node );

		ListDel( pt_pub->pt_args );
		INIT_SLIST( pt_pub->pt_args );

		ListDelNode( pt_node );

		pt_node = SlistExtractNode( liste );

	}

	SlistDelete( liste );
}

VOID ListDelExt( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;
	LstPro XPTR * pt_ext;
	
	if (liste == GFN( C_SLIST) ) return;

	ListGoFirst( liste );

	pt_node = SlistExtractNode( liste );
	while ( pt_node ){
		pt_ext = SnodeGet( pt_node );

		ListDel( pt_ext->pt_args );
		INIT_SLIST( pt_ext->pt_args );

		ListDel( pt_ext->pt_ref );
		INIT_SLIST( pt_ext->pt_ref );

		ListDelNode( pt_node );

		pt_node = SlistExtractNode( liste );
	}
	
	SlistDelete( liste );
}

/* Modif 2.1b : Ne prendre en compte que les references externes utilis‚es */

WORD ListCountProExt( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;
	LstPro XPTR * pt_ext;
	WORD nb;

	
	nb = 0;

	if (liste == GFN( C_SLIST) ) return( nb );


	SlistRewind( liste );
	pt_node = SlistGetNext( liste );
	while ( pt_node ){
		pt_ext = SnodeGet( pt_node );

		if (SlistCount( pt_ext->pt_ref )) nb++;

		pt_node = SlistGetNext( liste );
	}
	
	return( nb );
}

WORD ListCountSegExt( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;
	LstPro XPTR * pt_ext;
	WORD nb;

	
	nb = 0;

	if (liste == GFN( C_SLIST) ) return( nb );


	SlistRewind( liste );
	pt_node = SlistGetNext( liste );
	while ( pt_node ){
		pt_ext = SnodeGet( pt_node );

		if (SlistCount( pt_ext->pt_ref ) != 0 || pt_ext->ext.num_seg != MOINS_UN) {
			nb ++;
		}
		pt_node = SlistGetNext( liste );
	}
	
	return( nb );
}

VOID ListDelAncrage( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;
	Ancrage XPTR * pt_ancrage;
//JPH	VarExt  XPTR * pt_varext;
	
	if (liste == GFN( C_SLIST) ) return;

	ListGoFirst( liste );

	pt_node = SlistExtractNode( liste );
	while ( pt_node ) {
		pt_ancrage = SnodeGet( pt_node );

		ListDelExt( pt_ancrage->liste_varext );

		ListDelNode( pt_node );

		pt_node = SlistExtractNode( liste );
	}
	
	SlistDelete( liste );
}



C_SLIST FAR * ListInit()
{
	C_SLIST FAR * liste;

	liste = SlistCreate();

	return ( liste );
}

VOID ListDel( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * pt_node;

	if ( liste == GFN( C_SLIST ) ) return;

	ListGoFirst( liste );
	pt_node = SlistExtractNode( liste );
	while( pt_node ) {
		ListDelNode( pt_node );
		pt_node = SlistExtractNode( liste );
	}

	SlistDelete( liste );
}

VOID ListConcat( liste_d, liste_o )
C_SLIST FAR * liste_d;
C_SLIST FAR * liste_o;
{
	C_SNODE FAR * node;
	WORD lg_o;
	WORD lg_d;

	lg_o = SlistCount( liste_o );
	lg_d = SlistCount( liste_d );


	if (SlistIsEmpty( liste_o ) ) return;

	ListGoFirst( liste_o );
	
	node  = SlistExtractNode( liste_o );
	while ( node ) {
		SlistAddHead( liste_d, node );
		node  = SlistExtractNode( liste_o );
	}

	INVARIANT( SlistCount( liste_d ) == lg_o+lg_d );
}

VOID ListGoFirst( liste )
C_SLIST FAR * liste;
{

	SlistRewind( liste );
	SlistSetCurrent( liste, SlistGetHead( liste ) );

}

WORD ListCountVarExt( liste )
C_SLIST FAR * liste;
{
	Ancrage XPTR *	ancrage;
	C_SNODE FAR *	node;
	WORD		nb;

	nb = 0;

	SlistRewind( liste );
	node = SlistGetNext( liste );
	while ( node ) {
		ancrage = SnodeGet( node );
		nb += SlistCount( ancrage->liste_varext );
		node = SlistGetNext( liste );
	}
	
	return( nb );
}

VOID ListCreateHashList( liste )
C_SLIST FAR * liste[];
{
	WORD i;
	
	for (i = 0; i< HTV; i++ ) {
		ALLOC_SLIST( liste[i] );
	}

}

VOID ListDelHashList( liste )
C_SLIST FAR * liste[];
{
	WORD i;
	
	if ( liste[0] == GFN(C_SLIST) ) return;

	for (i = 0; i< HTV; i++ ) {
		ListDel( liste[i] );
		INIT_SLIST( liste[i] );
	}
}

WORD ListCountHashList( liste )
C_SLIST FAR * liste[];
{
	WORD i;
	WORD nb;

	nb = 0;
	for (i=0; i < HTV; i ++) {
		nb += SlistCount( liste[ i ] );
	}
	return( nb );
}

VOID ListConcatHashList( liste_d, liste_o )
C_SLIST FAR * liste_d[];
C_SLIST FAR * liste_o[];
{
	WORD i;
//JPH	C_SNODE FAR * node;

	for (i=0; i < HTV; i ++) {
		ListConcat( liste_d[ i ], liste_o[ i ] );
	}
}

C_SNODE FAR * SlistExtractNode( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * node;
	C_SNODE FAR * node_next;

	node = SlistGetCurrent( liste );
	/* je supprime le noeud courrant si non vide */

	if (node == GFN( C_SNODE ) ) return( node );

	SlistRemoveCurrent( liste );

	/* le noeud courrant devient le suivant de node */
	
	node_next = SnodeGetNext( node );

	if ( node_next ) SlistSetCurrent( liste, node_next );

	return ( node );
}


VOID ListAddItemEnQueue( liste , item )
C_SLIST FAR * liste;
VOID FAR * item;
{
	C_SNODE FAR * snode;

	snode = SnodeCreate();
	if ( snode ) {
		SnodeSet( snode, item );
		SlistAddTail( liste , snode );
	}
	else FREE_ALLOC( item, VOID FAR );
}

VOID ListAddItemEnTete( liste , item )
C_SLIST FAR * liste;
VOID FAR * item;
{
	C_SNODE FAR * snode;

	snode = SnodeCreate();

	SnodeSet( snode, item );
	SlistAddHead( liste , snode );

}

VOID ListInsertItem( liste, item)
C_SLIST FAR * liste;
VOID FAR * item;
{
	C_SNODE FAR * snode;

	snode = SnodeCreate();
	SnodeSet( snode, item );
	SlistAddCurrent( liste , snode );

}

VOID ListDelItemEnTete( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * snode;
//JPH	VOID FAR * item;

	snode = SlistGetHead( liste );
	SlistRemoveHead( liste );

	ListDelNode( snode );

}

VOID ListDelItemCourant( liste )
C_SLIST FAR * liste;
{
	C_SNODE FAR * snode;
//JPH	VOID FAR * item;

	snode = SlistGetCurrent( liste );
	SlistRemoveCurrent( liste );
	SlistSetCurrent( liste, SnodeGetNext( snode ) );
	
	ListDelNode( snode );
}

WORD ListAddNameUnique( liste, nom )
C_SLIST FAR * liste;
BYTE XPTR * nom;
{
	Name XPTR * pt_name;
	C_SNODE FAR * pt_node;

	pt_name = ListGetNameItemFromName( liste, nom );

	if ( pt_name == GenericNULL( Name ) ) {

		/* Creation d'un nouveau element */
		ALLOC_SNODE( pt_node );
		SlistAddTail( liste, pt_node );
		
		pt_name = ListNewName( nom, SlistCount( liste ) );

		SnodeSet( pt_node, pt_name );
	}
	return( pt_name->num );
}


Name XPTR * ListNewName( nom, num )
BYTE XPTR * nom;
WORD num;
{
	Name XPTR * pt_name;
//JPH	C_SNODE FAR * pt_node;

	ALLOC_STRUCT( pt_name, Name );

	XstrCpySize( pt_name->nom, nom , sizeof(pt_name->nom));
	pt_name->num = num;
	
	return( pt_name );
}

WORD ListAddName( liste, nom, num )
C_SLIST FAR * 	liste;
BYTE XPTR * 	nom;
WORD 		num;
{
	Name XPTR * pt_name;
	C_SNODE FAR * pt_node;

	ALLOC_SNODE( pt_node );
	SlistAddHead( liste, pt_node );

	pt_name = ListNewName( nom, num);	

	SnodeSet( pt_node, pt_name );

	return( pt_name->num );
}

VOID ListGetNameFromNum( liste, num, nom)
C_SLIST FAR * 	liste;
WORD 		num;
BYTE XPTR * 	nom;
{
	Name XPTR * pt_name;

	pt_name = ListGetNameItemFromNum( liste, num );

	nom[0] = EOSTR;

	if ( pt_name ) 
		Xstrcpy( nom, pt_name->nom );

}

WORD ListGetNameNum( liste, nom )
C_SLIST FAR * 	liste;
BYTE XPTR * 	nom;
{
	Name XPTR * pt_name;

	pt_name = ListGetNameItemFromName( liste, nom );

	if ( pt_name ) 
		return( pt_name->num );

	return( MOINS_UN );
}

Name XPTR * ListGetNameItemFromName( liste, nom )
C_SLIST FAR * 	liste;
BYTE XPTR * 	nom;
{
	Name XPTR * pt_name;
	C_SNODE FAR * pt_node;

	SlistRewind( liste );
	pt_node = SlistGetNext( liste );
	while ( pt_node ) {
		pt_name = SnodeGet( pt_node );
		if (! Xstrcmp( pt_name->nom, nom ) ) {
			/* trouve */
			return( pt_name );
		}
		pt_node = SlistGetNext( liste );
	}

	/* Non Trouve */

	return( GenericNULL( Name ) );
}

/*********************************
* FCT List
*
* Entree : 
* 	rien
*
* Sortie :
*	rien
*
* Remarque :
*
*
**********************************/
ModPro XPTR * ListGetNomVarFromDesc( liste, num )
C_SLIST FAR *	liste[];
WORD		num;
{
	ModPro XPTR * pp;
	WORD	htv;
	C_SNODE  FAR * node;

	/* calcule de la hash liste de la procedure extern */

	htv = num % HTV;
	SlistRewind( liste[ htv ] );
	node = SlistGetNext( liste[ htv ] );
	while ( node ) {
		pp = SnodeGet( node );
		if ( pp->num_desc == num ) {
			return( pp );
		}

		node = SlistGetNext( liste[ htv ] );
	}

	return( GenericNULL( ModPro ) );
}

Name XPTR * ListGetNameItemFromNum( liste, num )
C_SLIST FAR * 	liste;
WORD 	 	num;
{
	Name XPTR * pt_name;
	C_SNODE FAR * pt_node;

	SlistRewind( liste );
	pt_node = SlistGetNext( liste );
	while ( pt_node ) {
		pt_name = SnodeGet( pt_node );
		if ( pt_name->num == num ) {
			/* trouve */
			return( pt_name );
		}
		pt_node = SlistGetNext( liste );
	}

	/* Non Trouve */

	return( GenericNULL( Name ) );
}

Bibli XPTR * ListNewBda( nom, nb_fonction, non_util )
BYTE XPTR * nom;
WORD nb_fonction;
BYTE non_util[16];
{
	Bibli XPTR * pt_bda;
	WORD i;

	ALLOC_STRUCT( pt_bda, Bibli) ;

	XstrCpySize( pt_bda->nom, nom , sizeof(pt_bda->nom));
	pt_bda->pgn = nb_fonction;
	for (i=0; i<16; i++) {
		pt_bda->non_util[i] = non_util[i];
	}
	
	return( pt_bda );
}


VOID ListDupliqueVarExt( mod_tabvarext, res_tabvarext, liste, pe, res, mod)
Table XPTR * mod_tabvarext;
Table XPTR * res_tabvarext;
C_SLIST FAR * liste;
LstPro XPTR * pe;
Fichier XPTR * res;
Fichier XPTR * mod;
{
	C_SNODE FAR *	node;
	C_SNODE FAR *	pt_node;
	C_SNODE FAR *	pt_ref;

	LstPro XPTR *	p;
	InfoVar		desc_varext;

	LstRef XPTR *	r;
	LstRef XPTR *	pe_r;
	
//JPH	WORD		j;
	BYTE		nom[LGIDENT];


	ALLOC_SNODE( pt_node );
	SlistAddHead( liste,pt_node );
	
	ALLOC_STRUCT( p , LstPro );

	INIT_SLIST( p->pt_args);
	INIT_SLIST( p->pt_ref );

	SnodeSet( pt_node, p );

	/* Numero de module ou est defini l'extern */
	p->module = pe->module;

	/* numero dans la table des noms de module */
	if ( pe->par_qui == MOINS_UN ) 
		p->par_qui = pe->par_qui;
	else {
		ListGetNameFromNum( mod->liste_mod_ext, pe->par_qui, nom );
		p->par_qui	= ListGetNameNum( res->liste_mod_ext, nom );
	}

	p->any = pe->any;

	XstrCpySize(p->nom, pe->nom, sizeof(p->nom));

	p->hash_code = pe->hash_code;

	/* Par default non resolue */

	p->solved = pe->solved;

	/* Traitement des arguments */

	/* relocation du descripteur de variable externe */

	p->ext.adr_desc = TableGetReloc( res_tabvarext );
	TableGetVar( mod_tabvarext, pe->ext.adr_desc, &desc_varext );
	desc_varext.adrdesc = p->ext.adr_desc;
	TablePutVar( res_tabvarext ,  &desc_varext );

	/* duplication des references dans le code */
	ALLOC_SLIST( p->pt_ref );

	SlistRewind( pe->pt_ref );
	pt_ref = SlistGetNext( pe->pt_ref );

	while (pt_ref) {
		pe_r = SnodeGet( pt_ref );

		ALLOC_SNODE( node );
		SlistAddHead( p->pt_ref, node );
		
		ALLOC_STRUCT( r, LstRef );
		SnodeSet( node, r );

		r->prog = pe_r->prog;
		r->bloc = pe_r->bloc;
		r->off = pe_r->off;

		pt_ref = SnodeGetNext( pt_ref );
	}
}

VOID ListDupliqueAncrage( mod_tabvarext, res_tabvarext, liste, pe, res, mod)
Table XPTR *	mod_tabvarext;
Table XPTR *	res_tabvarext;
C_SLIST FAR * liste;
Ancrage XPTR * pe;
Fichier XPTR * res;
Fichier XPTR * mod;
{
//JPH	C_SNODE FAR * node;
	C_SNODE FAR * pt_node;
//JPH	C_SNODE FAR * pt_ref;

	Ancrage XPTR * p;

//JPH	LstRef XPTR * r;
//JPH	LstRef XPTR * pe_r;
	LstPro XPTR * ve;	
//JPH	WORD j;
	BYTE nom[LGIDENT];


	ALLOC_SNODE( pt_node );
	SlistAddHead( liste,pt_node );
	
	ALLOC_STRUCT( p , Ancrage );

	INIT_SLIST( p->liste_varext );

	SnodeSet( pt_node, p );

	/* numero dans la table des noms de module */
	if ( pe->par_qui == MOINS_UN ) {
		p->par_qui = pe->par_qui;
	}
	else {
		ListGetNameFromNum( mod->liste_mod_ext, pe->par_qui, nom );
		p->par_qui	= ListGetNameNum( res->liste_mod_ext, nom );

	}
	XstrCpySize(p->label, pe->label, sizeof(p->label));
	p->field = pe->field;

	ALLOC_SLIST( p->liste_varext );

	SlistRewind( pe->liste_varext );
	pt_node = SlistGetNext( pe->liste_varext );
	while ( pt_node ) {
		ve = SnodeGet( pt_node );

		ListDupliqueVarExt( mod_tabvarext, res_tabvarext, p->liste_varext, ve, res, mod );
		pt_node = SlistGetNext( pe->liste_varext );
	}
}

VOID ListDupliqueSegExt( liste, pe)
C_SLIST FAR * liste;
LstPro XPTR * pe;
{
	C_SNODE FAR * node;
	C_SNODE FAR * pt_node;
	C_SNODE FAR * pt_ref;

	LstPro XPTR * p;
//JPH	Args XPTR * q;
//JPH	Args XPTR * pe_q;

	LstRef XPTR * r;
	LstRef XPTR * pe_r;
	
	WORD j;


	ALLOC_SNODE( pt_node );
	SlistAddHead( liste,pt_node );
	
	ALLOC_STRUCT( p , LstPro );

	INIT_SLIST( p->pt_args);
	INIT_SLIST( p->pt_ref );

	SnodeSet( pt_node, p );

	/* Numero de module ou est defini l'extern */
	p->module = pe->module;

	/* numero dans la table des noms de module */
	p->par_qui = pe->par_qui;
	p->any = pe->any;

	XstrCpySize(p->nom, pe->nom, sizeof(p->nom));

	p->hash_code = pe->hash_code;

	/* Par default non resolue */

	p->solved = pe->solved;

	/* Traitement des arguments */

	j = pe->ext.nb_args;
	p->ext.nb_args = j;

	/* Creation des listes */

	ALLOC_SLIST( p->pt_args );
	
	/* pas de duplication des argument pour les segments */


	/* duplication des references dans le code */
	ALLOC_SLIST( p->pt_ref );

	SlistRewind( pe->pt_ref );
	pt_ref = SlistGetNext( pe->pt_ref );

	while (pt_ref) {
		pe_r = SnodeGet( pt_ref );

		ALLOC_SNODE( node );
		SlistAddHead( p->pt_ref, node );
		
		ALLOC_STRUCT( r, LstRef );
		SnodeSet( node, r );

		r->prog = pe_r->prog;
		r->bloc = pe_r->bloc;
		r->off = pe_r->off;

		pt_ref = SnodeGetNext( pt_ref );
	}
}

VOID ListDupliqueProExt( liste, pe)
C_SLIST FAR * liste;
LstPro XPTR * pe;
{
	C_SNODE FAR * node;
//JPH	C_SNODE FAR * pt_node;
	C_SNODE FAR * pt_ref;
	C_SNODE FAR * pt_args;

	LstPro XPTR * p;
	Args XPTR * q;
	Args XPTR * pe_q;

	LstRef XPTR * r;
	LstRef XPTR * pe_r;
	
	WORD j;

	ALLOC_SNODE( node );
	SlistAddHead( liste, node );

	ALLOC_STRUCT( p, LstPro );

	INIT_SLIST( p->pt_args );
	INIT_SLIST( p->pt_ref );

	SnodeSet( node, p );

	/* Numero de module ou est defini l'extern */
	p->module = pe->module;

	/* Numero de module ou est reloge l'extern */
	p->num_module = pe->num_module;

	/* numero dans la table des noms de module */
	p->par_qui = pe->par_qui;
	p->any = pe->any;
	XstrCpySize(p->nom, pe->nom, sizeof(p->nom));

	p->hash_code = pe->hash_code;

	/* Par default non resolue */

	p->solved = pe->solved;

	/* Traitement des arguments */

	j = pe->ext.nb_args;
	p->ext.nb_args = j;

	/* Creation des listes */

	j &= MASK_NB_ARGS; /* masque pour le nombre d'argument */
	
	p->pt_args = SlistCreate();

	SlistRewind( pe->pt_args );
	pt_args = SlistGetNext( pe->pt_args);

	while ( pt_args ) {
		ALLOC_SNODE( node );
		SlistAddTail( p->pt_args, node );

		pe_q = SnodeGet( pt_args );

		q = ListNewArgs( pe_q->typ_arg );

		SnodeSet( node, q );

		pt_args = SnodeGetNext( pt_args );
	}

	/* Liste des references dans le code */
	ALLOC_SLIST( p->pt_ref );

	SlistRewind( pe->pt_ref );
	pt_ref = SlistGetNext( pe->pt_ref );

	while (pt_ref) {

		pe_r = SnodeGet( pt_ref );

		ALLOC_SNODE( node );
		SlistAddHead( p->pt_ref, node );

		ALLOC_STRUCT( r , LstRef );
		SnodeSet( node, r );

		r->prog = pe_r->prog;
		r->bloc = pe_r->bloc;
		r->off  = pe_r->off;
			
		pt_ref = SnodeGetNext( pt_ref );
	}
}

VOID ListTestPatch(BYTE s_fic, WORD s_nb, Tabfic XPTR * d_fic, WORD d_nb)
{
	Patch *p;
	WORD i;
	
	C_SLIST FAR * pt_liste;
	C_SNODE FAR * pt_node;

	
	i = (WORD) (s_nb % 10);
	pt_liste = ListPatch[i];

	SlistRewind( pt_liste );
	pt_node = SlistGetNext( pt_liste );

	while ( pt_node ) {
		p = SnodeGet( pt_node );
		if ((p->fic == s_fic) && (p->bloc == s_nb)) {
			/* Ce bloc change de place */
			p->new_fic = d_fic;
			p->new_bloc = d_nb;

			break;
		}
		else {
			pt_node = SlistGetNext( pt_liste );
		}
	}
}

VOID ListPatcher( res )
Fichier XPTR * res;
{
//JPH	WORD i;
	Patch *p;
	Offset *o;

//JPH	BYTE tmp[100];
	WORD old_secteur;

	C_SNODE FAR * pt_node;

//JPH	FILE XPTR * fh;

	ListReorgPatch();
	SlistRewind( ListPatchTete );

	res->code.lg_read = LGBLOC;



	pt_node = SlistGetNext( ListPatchTete );
	while ( pt_node ) {
		p = SnodeGet( pt_node );

		if (p->new_fic == &res->code && p->new_bloc != 0 ) {
			FileSeekBloc(&res->code, p->new_bloc);
			FileReadBloc(&res->code, &res->code, p->new_bloc);

			SlistRewind( p->off );
			pt_node = SlistGetNext( p->off );

			while ( pt_node ) {

				o = SnodeGet( pt_node );
#ifndef VERSION_XX
/* #OK & #SP: 22/11/00 (begin) */
        		if (o->bIsGlobalVariable == 1)
/* #OK & #SP: 22/11/00 (end) */
/* #AT: 14/09/00 (begin)*/
					ChangeGlobVarAdr(&o->valeur);
/* #AT: 14/09/00 (end)*/
#endif
				res->code.ofst = o->val_off & 0x00ff;

				old_secteur = p->new_bloc;			

				if (o->octet == 0) {
					FilePutByte(&res->code,(BYTE) SECOND_BYTE(o->valeur));
		
					if (old_secteur < FileGetNumBloc( &res->code ) ) {
						FileSeekBloc(&res->code, (WORD) (p->new_bloc + 1));
						FileReadBloc(&res->code,&res->code, (WORD) (p->new_bloc + 1));

						old_secteur = FileGetNumBloc( &res->code) ;
					}

					FilePutByte(&res->code,(BYTE) FIRST_BYTE(o->valeur));

					if (old_secteur < FileGetNumBloc( &res->code ) ) {
						FileSeekBloc(&res->code, (WORD) (p->new_bloc + 1));
						FileReadBloc(&res->code,&res->code, (WORD) (p->new_bloc + 1));
					}

				}
				else {
					FilePutByte(&res->code,(BYTE) o->valeur);
					if (old_secteur < FileGetNumBloc( &res->code ) ) {

						FileSeekBloc(&res->code, (WORD) (p->new_bloc + 1));
						FileReadBloc(&res->code,&res->code, (WORD) (p->new_bloc + 1));

					}
				}
				pt_node = SlistGetNext( p->off );
			}



			FileWriteBlocForce(&res->code);

		}
		pt_node = SlistGetNext( ListPatchTete );
	}


	FilePurge( &res->code );


}

WORD ListHLPatchNbOff( hlpatch )
C_SLIST FAR * hlpatch [];
{
	WORD nb_off;
	WORD i;

	nb_off = 0;

	for (i=0; i < 10; i++) {
		nb_off += ListPatchNbOff( hlpatch[i] );
	}

	return( nb_off );

}

WORD ListPatchNbOff( liste )
C_SLIST FAR * liste;
{
//JPH	Offset XPTR * off;
	Patch XPTR * pt_patch;
	C_SNODE FAR * node;
	WORD nb_off;

	
	nb_off = 0;	
	SlistRewind( liste );
	node = SlistGetNext( liste );

	while (node) {
		pt_patch = SnodeGet( node );
		nb_off += SlistCount( pt_patch->off );
#ifdef __TRACE_PATCH
		{
		sprintf(waBuffer,"%d %d", pt_patch->new_bloc, pt_patch->off->nodecount);
		waDisplayMessage(waBuffer);
		}
#endif
		node = SlistGetNext( liste );
	}

	return( nb_off );
}

VOID ListDupliquePro( liste, pp)
C_SLIST FAR * liste[];
ModPro XPTR *  pp;
{
	C_SNODE FAR * node;
//JPH	C_SNODE FAR * pt_node;
//JPH	C_SNODE FAR * pt_ref;
	C_SNODE FAR * pt_args;

	ModPro XPTR * p;
	Args XPTR * q;
	Args XPTR * pp_q;

	WORD j;
	WORD htv, hlv;

	
	ListCalculHashValue(pp->nom, &htv, &hlv);
	
	ALLOC_SNODE( node );
	SlistAddHead( liste[htv], node );

	ALLOC_STRUCT( p, ModPro );

	INIT_SLIST( p->pt_args );

	SnodeSet( node, p );

	p->hash_code 	= pp->hash_code;
	p->num_module	= pp->num_module;
	XstrCpySize(p->nom, pp->nom , sizeof(p->nom));
	p->used		= pp->used;
	p->num_desc	= pp->num_desc;
	p->proc_app	= pp->proc_app;
	p->adr_map	= pp->adr_map;
	p->lg_map	= pp->lg_map;

	p->pub.nb_args	= pp->pub.nb_args;
	
	j = pp->pub.nb_args;

	/* Creation des listes */

	j &= MASK_NB_ARGS; /* masque pour le nombre d'argument */
	
	p->pt_args = SlistCreate();

	SlistRewind( pp->pt_args );
	pt_args = SlistGetNext( pp->pt_args);

	while ( pt_args ) {
		ALLOC_SNODE( node );
		SlistAddHead( p->pt_args, node );

		pp_q = SnodeGet( pt_args );

		q = ListNewArgs( pp_q->typ_arg );

		SnodeSet( node, q );

		pt_args = SnodeGetNext( pt_args );
	}
}

VOID ListDupliqueSeg( liste, pp)
C_SLIST FAR * liste[];
ModPro XPTR *  pp;
{
	C_SNODE FAR * node;
//JPH	C_SNODE FAR * pt_node;
//JPH	C_SNODE FAR * pt_ref;
//JPH	C_SNODE FAR * pt_args;

	ModPro XPTR * p;
//JPH	Args XPTR * q;
//JPH	Args XPTR * pp_q;

//JPH	WORD j;
	WORD htv, hlv;

	
	ListCalculHashValue(pp->nom, &htv, &hlv);
	
	ALLOC_SNODE( node );
	SlistAddHead( liste[htv], node );

	ALLOC_STRUCT( p, ModPro );

	INIT_SLIST( p->pt_args );

	SnodeSet( node, p );

	p->hash_code 	= pp->hash_code;
	p->num_module	= pp->num_module;
	XstrCpySize(p->nom, pp->nom, sizeof(p->nom) );
	p->used		= pp->used;
	p->num_desc	= pp->num_desc;
	p->proc_app	= pp->proc_app;
	p->adr_map	= pp->adr_map;
	p->lg_map	= pp->lg_map;

	p->pub.nb_args	= pp->pub.nb_args;
	
	p->pt_args 	= INIT_SLIST( p->pt_args );

}

VOID ListDupliqueVar( liste, pp)
C_SLIST FAR * liste[];
ModPro XPTR *  pp;
{
	C_SNODE FAR * node;
//JPH	C_SNODE FAR * pt_node;
//JPH	C_SNODE FAR * pt_ref;
//JPH	C_SNODE FAR * pt_args;

	ModPro XPTR * p;
//JPH	Args XPTR * q;
//JPH	Args XPTR * pp_q;

//JPH	WORD j;
//JPH	WORD htv, hlv;

	
	ALLOC_SNODE( node );
	SlistAddHead( liste[pp->used % HTV], node );

	ALLOC_STRUCT( p, ModPro );

	INIT_SLIST( p->pt_args );

	SnodeSet( node, p );

	p->hash_code 	= pp->hash_code;
	p->num_module	= pp->num_module;
	XstrCpySize(p->nom, pp->nom, sizeof(p->nom) );
	p->used		= pp->used;
	p->num_desc	= pp->num_desc;
	p->proc_app	= pp->proc_app;
	p->adr_map	= pp->adr_map;
	p->lg_map	= pp->lg_map;

	p->pub.nb_args	= pp->pub.nb_args;
	
	p->pt_args 	= INIT_SLIST( p->pt_args );

}



