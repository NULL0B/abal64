#ifndef	_gestfic_c
#define	_gestfic_c

#define _OPT_VAR_EXTERN
#define _TEST_BUF
/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : GESTFIC.C
 *      Version : 2.2b
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Gestion du fichier traduit]
 *
 */

 /*
 * Mises a jour :
 * ------------
 * 18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *	27/08/90 : utilisation de fn_parser pour adjoindre les extensions
 * 23/10/90 : notion de segment resident / public
 * 30/10/90 : Modification cycle de creation des traduits
 * 07/11/90 : Mise a jour de la date et heure des fichiers (Amenesik / Sologic/DOS)
 * 04/12/90 : Modifications mineures du style d'ecriture
 * 08/01/91 : Mise a jour de la date et heure des fichiers (Unix)
 * 14/01/91 : Evite le bouclage erreur -> fingest -> erreur en cas
 *            d'erreur fatale
 * 15/01/91 : Verrouillage du fichier a renommer avant sa suppression
 * 21/01/91 : Pas de controle de la suppression du fichier a renommer
 *            mais uniquement de la possibilite de le supprimer.
 * 31/01/91 : Date des traduits sous VMS
 * 06/02/91 : Liberation verrou sur fichier traduit anterieur, lors
 *            d'une traduction partielle.
 * ---------- Sortie 1.2f / 1.3c / 1.4a -------------------------------
 * 19/08/91 : Fermeture du fichier de travail avant sa suppression lors
 *            d'une erreur fatale sur traduction partielle
 * ---------- Sortie 1.2g / 1.3d --------------------------------------
 * 26/12/91 : Suppression minuscules accentuees dans les sources
 * ---------- Debut 1.5 --------------------------------------
 * 23/11/92 : Modification de la gestion de fichier
 *                 table localisee et non plus en global
 *	21/07/93 : 0 Fin des tables des noms ( const binaire ) : vid_tnoms
 *	14/09/93 : Probleme sur les listes de variables externes vides
 * 	--------- 2.1c ------------------------------------------
 *	31/05/94 : sauvegarde dans l'entete DBG du dernier segment nomme 
 *	31/05/94 : Mise d'un terminateur en fin de table de noms de sources
 *	03/06/94 : Mise d'un terminateur en fin de table des segments
 *	------------ 2.1d -------------------------------------------------
 *	22/11/95 : version dediee 2.1
 *  ------------ 2.2a -------------------------------------------------
 * 01/08/97 : creation de vid_tInitGlobalVariable() qui cree la table des
 *            image ds variables globales après initialisation
 * 02/11/97 : Modification de la fonction vid_tseg : la longueur de la table des segments
 *            n'était pas bonne pour un source avec un grand nombre de segments
 * 13/05/98 : Changement extensions des fichiers (suivant option de debug)
 *	29/10/98 : correction lgr table segments quand > 4Ko
 * 23/01/00 : #SP : Bug ATR 2 fixed: Mofifications in fingest() function in order to
 *            delete the AT,TAT,TBD files if there were errors.
 * 09/05/00 : #BG : Enhancement ATR 9: Option -to, -ta.
 *	------------ 2.2b -------------------------------------------------
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"
#include "tcode.h"
#include "abal.h"

#define _GESTFIC
#include "gestfic.hs"
#include "gestfic.he"

#ifdef WIN32
extern void Epoch(BYTE *);
#endif

#ifdef VERSION_XX
void enhanced_tcode_version()
{
	icode = icode4;
	is_local  = IS_LOCAL4;
	to_global = TO_GLOBAL4;
	return;
}
#endif

        /***********************************/
        /*** Version 1.4 et posterieures ***/
        /***********************************/

void initgest(prod,outfile)

/*      Initialisation de la gestion du fichier traduit
 */
BOOL prod;
char *outfile;
{                                       /* initgest */
	int i;
	//SG
	struct_index=0;
	//SG

	t_prod = prod;
	if (t_prod) {
		/* Prepare les noms des fichiers traduits :
		*      .AT  : resultat definitif
		*      .TAT : fichier de travail
		*/
		Xstrcpy(nametrad,outfile);
		Xstrcpy(fic[NOAT].name,outfile);
		forceext(fic[NOAT].name,fic[NOAT].name,EXTTMPA);

		/* Creation du fichier de travail :
		* il s'agit ici d'un fichier temporaire.
		* Ceci permet de ne pas detruire l'original en
		* cas d'erreur de traduction.
		*/
		fic[NOAT].fcode = XTopen(fic[NOAT].name);
		if ( fic[NOAT].fcode == XT_ERR)
			erreur(FATALE,errges0);

		/* Ecrit le premier bloc du fichier temporaire
		* de facon a verifier les droits d'acces a ce
		* fichier. Le contenu de ce bloc est initialise
		* a FF et sera re-ecrit de toutes facons a la fin
		* de la traduction
		*/
		for (i = 0; i < LGBLOC; i++)
			fic[NOAT].tampon[i]= (BYTE) -1;
		if (XTwrite(fic[NOAT].fcode,fic[NOAT].tampon,LGBLOC) != XT_OK)
			erreur(FATALE,errges1);

		/* Prepare les noms des fichiers d'info symbolique :
		*      .DBG  : resultat definitif
		*      .TDB : fichier de travail
		*/
		Xstrcpy(fic[NODBG].name,outfile);
		forceext(fic[NODBG].name,fic[NODBG].name,EXTTMPD);

		/* Creation du fichier de travail :
		* il s'agit ici d'un fichier temporaire.
		* Ceci permet de ne pas detruire l'original en
		* cas d'erreur de traduction.
		*/
		fic[NODBG].fcode = XTopen(fic[NODBG].name);
		if ( fic[NODBG].fcode == XT_ERR)
			erreur(FATALE,errges0);

		/* Ecrit le premier bloc du fichier temporaire
		* de facon a verifier les droits d'acces a ce
		* fichier. Le contenu de ce bloc est initialise
		* a FF et sera re-ecrit de toutes facons a la fin
		* de la traduction
		*/
		for (i = 0; i < LGBLOC; i++)
			fic[NODBG].tampon[i]= (BYTE) -1;
		if (XTwrite(fic[NODBG].fcode,fic[NODBG].tampon,LGBLOC) != XT_OK)
			erreur(FATALE,errges1);
	}

	hd_tcode.typ = icode;   /* version de T-code produite */

	fic[NOAT].cur_bloc = 1;           /* bloc courant */
	fic[NOAT].cur_ofst = 0;

	fic[NODBG].cur_bloc = 1;           /* bloc courant */
	fic[NODBG].cur_ofst = 0;

	gestinit = TRUE;
}                                       /* initgest */


void fingest(edl,force)

/*      Fin d'utilisation du fichier traduit.
 *      'edl' indique si une edition de liens est necessaire,
 *      'force' vaut :
 *              0 si pas d'erreur et pas d'abandon
 *              1 si des erreurs et pas d'abandon
 *              2 si des erreurs et abandon
 */
BOOL edl;
int force;
{                                       /* fingest */
	char    nameobj[LGMXNOM];
	char    namedbo[LGMXNOM];
	char    namedbg[LGMXNOM];

	/* Force le code d'erreur de retour du traducteur.
	* Si une erreur est detectee, fatale ou non, elle doit
	* interrompre un MAKE en cours.
	*/
	RetCode = force;
	if (!gestinit)
		return;

	/* Signale que la fermeture a deja eu lieu pour ne pas la refaire */
	gestinit = FALSE;

	if (t_prod) {

		/* Prepare le nom du fichier objet eventuel */
		Xstrcpy(nameobj,nametrad);
		forceext(nameobj,nameobj,EXTO);

		/* Prepare le nom du fichier debug objet eventuel */
		Xstrcpy(namedbo,nametrad);

		/* Prepare le nom du fichier debug eventuel */
		Xstrcpy(namedbg,nametrad);


#ifdef WIN1632
		//SG
		if (edl)
			enhanced_debug = TRUE; //Force un WDO 

		if (!enhanced_debug) //affecté aussi par le pragma
		{
			forceext(namedbg,namedbg,EXTDBG);
			forceext(namedbo,namedbo,EXTDBO);
		}
		else
		{
			if (!NewDBGWithOldExtension)
			{
				forceext(namedbg,namedbg,EXTWDB); //extension pour debugger windows
				forceext(namedbo,namedbo,EXTWDO); //extension pour debugger windows
			}
			else
			{
				forceext(namedbg,namedbg,EXTDBG);
				forceext(namedbo,namedbo,EXTDBO);
			}
		}
		//SG
#else
		forceext(namedbg,namedbg,EXTDBG);
		forceext(namedbo,namedbo,EXTDBO);					
#endif

		/* #BG: 09/05/00 (begin) */
		if (optionTO && !edl)
			erreur(USUAL,errtargetTO);
		if (optionTA && edl)
			erreur(USUAL,errtargetTA);
		/* #BG: 09/05/00 (end) */

		if ((force == 0) && edl) {

			/* Edition de liens necessaire, et pas d'erreurs :
			 * il suffit de renommer le fichier de travail en
			 * .o apres avoir supprime son predecesseur
			 */

			if (!xrename(NOAT, nameobj)) {
#if prologue || msdos || vms
				XTclose(fic[NOAT].fcode);
				XTclose(fic[NODBG].fcode);
#endif /* prologue */
				Xunlink(fic[NOAT].name);
				Xunlink(fic[NODBG].name);
				erreur(FATALE,errges3);
			}

//			if (outmap)  {//SG 210798
			if (!xrename(NODBG, namedbo)) {

#if prologue || msdos || vms
				XTclose(fic[NODBG].fcode);
#endif /* prologue */

				Xunlink(fic[NODBG].name);
				erreur(FATALE,errges3);
			}
		}
		else {

		/* Traduction totale.
		* Si pas d'erreur, alors pas d'edition de liens
		* (car deja teste) : on renomme le fichier de
		* travail en .at.
		* En cas d'erreur, selon qu'une edition de liens
		* aurait du ou non etre faite, on renomme le
		* fichier de travail en .at ou .o.
		* De plus, on force la date du nouveau fichier
		* a la date minimale du systeme, de facon a
		* indiquer a AMAKE que le fichier n'est pas a jour.
		*/

			switch (force) {
				/* Pas d'erreur de traduction */
				case 0 :
					if (!xrename(NOAT, nametrad)) {
#if prologue || msdos || vms
						XTclose(fic[NOAT].fcode);
						XTclose(fic[NODBG].fcode);
#endif /* prologue */
						Xunlink(fic[NOAT].name);
						Xunlink(fic[NODBG].name);
						erreur(FATALE,errges3);
					}
					if ( edl || outmap ) {
						if (!xrename(NODBG, namedbg)) {
#if prologue || msdos || vms
							XTclose(fic[NODBG].fcode);
#endif /* prologue */
							Xunlink(fic[NODBG].name);
							erreur(FATALE,errges3);
						}
					} else {
#if prologue || msdos || vms
						XTclose(fic[NODBG].fcode);
#endif /* prologue */
						Xunlink(fic[NODBG].name);
						Xunlink(namedbg);
					}	
					break;

           /* Erreur(s) usuelle(s) : pas d'abandon */
           case 1 :
					if (!xrenold(NOAT, (edl) ? (nameobj) : (nametrad) )) {
#if prologue || msdos || vms
						XTclose(fic[NOAT].fcode);
						XTclose(fic[NODBG].fcode);
#endif /* prologue */
						Xunlink(fic[NOAT].name);
						Xunlink(fic[NODBG].name);

						erreur(FATALE,errges3);
					}

					if ( edl || outmap ) {	
						if (!xrenold(NODBG, (edl || outmap) ? (namedbo) : (namedbg) )) {
#if prologue || msdos || vms
							XTclose(fic[NODBG].fcode);
#endif /* prologue */
							Xunlink(fic[NODBG].name);
							erreur(FATALE,errges3);
						}
					} else {
#if prologue || msdos || vms
						XTclose(fic[NODBG].fcode);
#endif /* prologue */
						Xunlink(fic[NODBG].name);
					}

					/* Si erreur pas de .at */ 
/* #SP 23/01/00 (begin) */
					Xunlink(nametrad);
					Xunlink(nameobj); 
					Xunlink(namedbo);
/* #SP 23/01/00 (end) */
					break;

				/* Erreur fatale : on ne teste pas le compte-rendu
				* de facon a ne pas risquer le bouclage.
				*/
				case 2 :
					xrenold(NOAT, (edl) ? (nameobj) : (nametrad));
					if ( edl || outmap ) {
						xrenold(NODBG, (edl || outmap) ? (namedbo) : (namedbg));
					} else {
#if prologue || msdos || vms
						XTclose(fic[NODBG].fcode);
#endif /* prologue */
						Xunlink(fic[NODBG].name);
					}
/* #SP 23/01/00 (begin) */
					Xunlink(nametrad);
					Xunlink(namedbo);
/* #SP 23/01/00 (end) */
					break;
			}
		}

		/* #BG: 09/05/00 (begin) */
		if ((optionTO && !edl) || (optionTA && edl)) {
			if (edl) {
				Xunlink(nameobj); 
				Xunlink(namedbo);
			} else {
				Xunlink(nametrad);
				Xunlink(namedbg);
			}
		}
		/* #BG: 09/05/00 (end) */
	}
}                                       /* fingest */


void putentete(no)

/*      Ecriture du bloc d'entete du fichier traduit
 */
BINAIRE no;
{                                       /* putentete */
	posit(no,0,TRUE,TRUE);             /* posit en debut physique du fichier */
	fic[no].cur_ofst = 0;

	pbyte(no,hd_tcode.ver);
	pbyte(no,hd_tcode.ind);
	pbyte(no,hd_tcode.typ);
	pstr(no,&hd_tcode.nom[0],(LGNOMPRG-1));

	if ( no == NOAT ) {
				pbyte(no,hd_tcode.opt); /* option traduction */
				pbyte(no,hd_tcode.exec); /* option etat traduit */
				pbin(no,hd_tcode.adr_arg); 
				pbin(no,hd_tcode.adr_tcg); pbin(no,hd_tcode.lng_tcg);
				pbin(no,hd_tcode.adr_tvg); pbin(no,hd_tcode.lng_tvg);
				pbin(no,hd_tcode.reserve);
				pbin(no,hd_tcode.lng_xtm);
				pbin(no,hd_tcode.adr_tsg); pbin(no,hd_tcode.lng_tsg);
				pbin(no,hd_tcode.adr_tpr); pbin(no,hd_tcode.lng_tpr);
				pbin(no,0);
				pbin(no,hd_tcode.l_mxvl); pbin(no,hd_tcode.t_mxdl);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,hd_tcode.nb_regs); pbin(no,hd_tcode.nb_files);
				pbin(no,hd_tcode.lg_mem); pbin(no,hd_tcode.lg_stack);
				pbin(no,hd_tcode.secret);
	} else {
/* x12 */	pbyte(no,hd_tcode.opt); /* option debug */
				pbyte(no,hd_tcode.exec); /* option etat debug */
/* x14 */	pbin(no,0);
/* x16 */	pbin(no,0); pbin(no,0);
/* x1A */	pbin(no,0); pbin(no,0);
/* x1E */	pbin(no,0);
/* x20 */	pbin(no,0);
/* x22 */	pbin(no,0); pbin(no,0);
/* x26 */	pbin(no,0); pbin(no,0);
/* x2A */	pbin(no,hd_tcode.adr_npr);
/* x2C */	pbin(no,0); pbin(no,0);
/* x30 */	pbin(no,hd_tcode.adr_xpro); /* table des procedures externes */
/* x32 */	pbin(no,hd_tcode.adr_xvar); /* table de reloc var */
/* x34 */	pbin(no,hd_tcode.adr_xcst); /* table de reloc cst */
				pbin(no,0);pbin(no,0);
				pbin(no,0);pbin(no,0);
				pbin(no,hd_tcode.secret);
	}

	crypt(hd_tcode.secret,&fic[no].tampon[18],44,TRUE);

	if ( no == NOAT ) {
				pbin(no,0);
				pbin(no,0);

				pbin(no,hd_tcode.adr_tfu); /* relais fonctions utilisateur */
				pbin(no,hd_tcode.lng_tfu);
				pbin(no,0);
				pbin(no,hd_tcode.fact_blk); /* ? Pourquoi pas en 1.4 !!! */
				pbin(no,hd_tcode.adr_ivg);
				pbin(no,hd_tcode.lng_ivg);
				pbin(no,hd_tcode.t_pageme);
				pbin(no,hd_tcode.nb_pageme);
				pbin(no,hd_tcode.nivmx_opt);
				pbin(no,hd_tcode.ext_opt);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
	} else {
				pbin(no,0);
				pbin(no,hd_tcode.adr_lst); /* adr de la liste des fichiers listes */ 
				pbin(no,0);
				pbin(no,0);
				pbin(no,hd_tcode.adr_xtfu); /* adr de reloc des bib dyn */
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,0);
				pbin(no,hd_tcode.nivmx_opt);
				pbin(no,hd_tcode.adr_nsg);   /* table des noms de segment */
				pbin(no,hd_tcode.adr_xsg);   /* table des segments externes */
				pbin(no,hd_tcode.adr_xvg);   /* table des points d'ancrage des vars externes */
				pbin(no,hd_tcode.adr_nmod);  /* nom de module */
				pbin(no,0);   		     /* adr cor variables globales (pas utilise) */
				pbin(no,0 /* hd_tcode. */);  /* adr table corr constantes (pas utilise) */
				pbin(no,0 /* hd_tcode. */);  /* lng table corr constantes (pas utilise */
				pbin(no,hd_tcode.adr_nsrc);  /* nom de sources */
				pbin(no,hd_tcode.adr_etv);   /* adr etiquette var */
				pbin(no,hd_tcode.adr_xdesc); /* adr table desc var ext */
				pbin(no,hd_tcode.lng_xdesc); /* long table desc var ext */
				pbin(no,hd_tcode.adr_ncbin); /* adr table des noms de cst bin */
				pbin(no,hd_tcode.adr_ncbcd); /* adr table des noms de cst bcd */
				pbin(no,hd_tcode.flg_plus);  /* flag variables privees */	
				pbin(no,hd_tcode.max_seg);  /* dernier segment nomme */	
	}

	purge(no);
}                                       /* putentete */


BINAIRE vid_tusr(no,plg)

/*      Ecriture d'une table de description des runtimes externes
 *      dans le fichier traduit.
 *      On retourne le numero de bloc de depart de la table
 *      et sa longueur dans *plg
 */

BINAIRE no,*plg;
{                                       /* vid_tusr */
        BINAIRE n,i,k;
        TabRt   *trt;
        BYTE    c;

        n = getbloc(no);  /* demander un nouveau bloc dans le traduit */
        pbin(no,nortusr);  /* placer le nombre de RT */

        trt = RacTabRt;
        *plg = 2;

        for (k = 0 ; k < nortusr ; k++) {       /* vidage dans l'ordre */
                trt = RacTabRt;
                while (trt->nort != k)
                        trt = trt->suiv;

                for (i = 0 ; i < LGNRT ; i++,(*plg)++) {
                        c = trt->nom[i];        /* on vide le nom */
                        pbyte(no,c);
                        if (c == EOSTR)
                                break;
                }
                pbin(no,trt->nbfct);               /* on vide le nb de fct */
                (*plg) += 2;
		pbyte(no,trt->options);
                for (i = 0 ; i < 15 ; i++,(*plg)++)
                        pbyte(no,(BYTE) 0);        /* reserve pour extensions */
        }

        (*plg) = ((*plg) + LGBLOC - 1) / LGBLOC;
        return(n);
}                                       /* vid_tusr */


BINAIRE vid_xuref(no,tref)

/*      Ecriture de la table de relogeabilite des numeros de
 *      runtime dans le fichier traduit.
 *      On retourne le numero de bloc de depart de la table.
 */
BINAIRE no;
TabuRef *tref;
{                                       /* vid_xuref */
        BINAIRE n;

        n = getbloc(no);
        while (tref != GenericNULL(TabuRef)) {  /* tant qu'il y a des ref */
                pbyte(no,tref->nort);
                pbin(no,tref->bloc);
                pbin(no,tref->offst);
                tref = tref->suiv;
        }
	pbyte(no,0xFF);

        return(n);
}                                       /* vid_xuref */


BINAIRE vid_lien(no,pr,lien)
/*
 *      si pr == TRUE :
 *              Ecriture de la liste des relocations des procedures
 *              appelees par la procedure courante d'un module.
 *      sinon
 *              Ecriture de la liste des relocations des segments et
 *              des procedures appelees par le segment courant d'un module.
 *
 *      'lien' pointe la liste. Au retour, numero du bloc
 *      alloue pour la liste.
 */
BINAIRE no;
BOOL pr;
LienRef *lien;
{                                       /* vid_lien */
        BINAIRE n;

        n = getbloc(no);          /* alloue un nouveau bloc */

        if ( pr == TRUE ) { /* Cas des procs appelees par une proc */

                while (lien != GenericNULL(LienRef)) {
                        if (lien->desc.dproc->ext) {
                                pbyte(no,1);
                                pbin(no,0);        /* a revoir sur EXTERN PROC ds module */
                        } else {
                                pbyte(no,0);
                                pbin(no,lien->desc.dproc->ads);
                        }
                        pbin(no,lien->bloc);
                        pbin(no,lien->ofst);

                        lien = lien->suiv;      /* passe au suivant */
                }
                pbyte(no,0xff);

        } else { /* Cas des segs et des procs appeles par un seg */

                while (lien != GenericNULL(LienRef)) {
                        if ( lien->proc_or_seg == TRUE ) {
                        /* Proc */
                                if (lien->desc.dproc->ext) {
                                        pbyte(no,1);
                                        pbin(no,0);        /* a revoir sur EXTERN PROC ds module */
                                } else {
                                        pbyte(no,0);
                                        pbin(no,lien->desc.dproc->ads);
                                }
                        } else {
                        /* Seg */
                                if (lien->desc.dseg->ext) {
                                        pbyte(no,3);
                                        /* a revoir sur EXTERN SEG ds module */
                                        pbin(no,0);
                                } else {
                                        pbyte(no,2);
                                        pbin(no,lien->desc.dseg->ads);
                                }
                        }
                        pbin(no,lien->bloc);
                        pbin(no,lien->ofst);

                        lien = lien->suiv;      /* passe au suivant */
                }
                pbyte(no,0xff);

        }
        return(n);
}                                       /* vid_lien */


BINAIRE vid_tcst(no,lg_tdesc,pdesc)

/*      Ecriture de la table des constantes dans le fichier traduit
 */
BINAIRE no,lg_tdesc;
BYTE    **pdesc;
{                                       /* vid_tcst */
        register BYTE *d;
        register BINAIRE i;
        BINAIRE n,k=0;

        n = getbloc(no);  /* demander un nouveau bloc dans le traduit */
        d = *pdesc;     /* d pointe sur le debut du premier descripteur */
        for (i=0; i < lg_tdesc; i++) {  /* vidage table des descripteurs */
                pbyte(no,*d++); k++;
                if (k == SIZETDESC) {
                        d = *(++pdesc); k = 0;
                }
        }
        return (n);
}                                       /* vid_tcst */


BINAIRE vid_tvar(no,nbvar,noms,lg_alloc,lg_tdesc,pdesc)

/*      Ecriture d'une table de variables dans le fichier traduit
 */
BINAIRE no,nbvar,lg_alloc,lg_tdesc;
BOOL    noms;
BYTE    **pdesc;
{                                       /* vid_tvar */
        register BYTE *d;
        register BINAIRE i;
        BINAIRE k,n;

        n = getbloc(no);  /* demander un nouveau bloc dans le traduit */
        pbin(no,nbvar);
        if (noms) {     /* table des noms sera presente dans le fichier DBG */
		if ( fic[NODBG].cur_ofst )
	                pbin(no,fic[NODBG].cur_bloc+1);
		else
	                pbin(no,fic[NODBG].cur_bloc);
        }
        else            /* sinon : adresse nulle = pas de table de noms */
                pbin(no,0);
        pbin(no,lg_alloc); /* espace a allouer par l'executeur */
        d = (*pdesc)+6; /* d pointe sur le debut du premier descripteur */
        k = 6;
        for (i=0; i < lg_tdesc; i++) {  /* vidage table des descripteurs */
                pbyte(no,*d++); k++;
                if (k == SIZETDESC) {
                        d = *(++pdesc); k = 0;
                }
        }
        return (n);
}                                       /* vid_tvar */


BINAIRE vid_tInitGlobalVariable(no, nb_desc, pdesc)

/*      Ecriture d'une table vide de l'image des variables globales
 */
BINAIRE no, nb_desc;
BYTE    **pdesc;
{       
		BYTE* initTable; /*table temporaire de l image des variables globales*/

      register BYTE *d; /*pointeur courant dans la table des descripteurs*/
		register BYTE *offsetptr; /*pointeur sur l'offset du descripteur courant*/
      register BINAIRE i, j, longueurImage, offset, offsetMax;
      BINAIRE k,n,currentDescSize;
		initTable=Xmalloc(0xFFFF);
      n = getbloc(no);	/* demander un nouveau bloc dans le traduit */       
      d = (*pdesc)+6;		/* d pointe sur le debut du premier descripteur */	 
		k = 6;
		offsetMax = 0;
		currentDescSize = 0; /*Pour tester le depassememt d'une sous table de descripteur*/

      for (i=0; i < nb_desc; i++){  /* Pour chaque descripteur */
			 /* deplacement sur l offset du descripteur*/
			offsetptr = d+2;
			 
			/* affectation de l offset du descripteur */
			offset=bytetobin(offsetptr);

			switch (typdesc(d)) { /* Type du descripteur ? */

			case TSTR :  /* type string */
					/* deplacement jusqu a la longueur */
					d+= 4; 
					longueurImage=bytetobin(d);
					/* remplissage de l'image (vide) de la chaine*/
					for (j=0; j< longueurImage; j++) initTable[offset+j]=0x20;
					if ((offset+j-1)>offsetMax) offsetMax=offset+j-1;	
					
					d+=2; /* decalage au prochain descripteur*/
					currentDescSize = 6;
				break;

			case TBIN1 :  /* type '#' */
					/* remplissage de l'image (vide) de l entier*/
					initTable[offset]=0;
					if ((offset)>offsetMax) offsetMax=offset;

					d+=4; /* decalage au prochain descripteur*/
					currentDescSize = 4;
				break;

			case TBIN2 : /* type '%' */
					/* remplissage de l'image (vide) de l entier*/
					initTable[offset]=0x00;
					initTable[offset+1]=0x00;
					if ((offset+1)>offsetMax) offsetMax=offset+1;

					d+=4; /* decalage au prochain descripteur*/
					currentDescSize = 4;
				break;

			case TBCD :  /* type BCD */
					/* BCD Vide de longueur :  1 er Byte : C0, puis FF pour les autres*/
					initTable[offset]=0xC0;

					/* deplacement jusqu a la longueur */
					d+= 4;
					longueurImage=bytetobin(d);	

					/* remplissage */
					for (j=1; j<=longueurImage-1; j++) initTable[offset+j]=0xFF;
					if ((offset+j-1)>offsetMax) offsetMax=offset+j-1;					
					
					d+=2; /* decalage au prochain descripteur*/
					currentDescSize = 6;
				break;

			case TPTR :	 /* type pointeur*/
					/* remplissage */
					for (j=1; j<=5; j++) initTable[offset+j-1]=0x00;
					if ((offset+j-1)>offsetMax) offsetMax=offset+j-1;

					d+=6; /* decalage au prochain descripteur*/
					currentDescSize = 6;
				break;

			default:
				break;

			}
				
				adsGlobalVarImage=offsetMax+1; /*longueur de la table des images */

				k+=currentDescSize;
                if (k == SIZETDESC) {
                         d = *(++pdesc);k = 0;
                }
        }//fin For

		//vidage de InitTable dans le fichier traduit

		for (j=0; j < adsGlobalVarImage ;j++)
			pbyte(no, initTable[j]);

		Xfree(initTable);
        return (n);
}     

BINAIRE vid_tnoms(no,s)

/*      Ecriture d'une table de noms de variables dans le fichier traduit
 *      cette fonction doit etre appelee immediatement apres vid_tvar, et
 *      seulement si l'option outmap est vrai.
 */
BINAIRE no;
TabSymb *s;
{ 
                                      /* vid_tnoms */
BINAIRE res;

        res=getbloc(no);              /* passer au bloc suivant */
        pnom(no,s);
	pbyte(no,'\0');
	return(res);
}                                       /* vid_tnoms */


BINAIRE vid_tproc(no, lg_tdesc, pdesc )

/*      Ecriture de la table des procedures dans le fichier traduit
 */
BINAIRE no,lg_tdesc;
BYTE **pdesc;
{                                       /* vid_tproc */
        register BYTE *d;
        register BINAIRE i;
        BINAIRE n , k = 0;

        n = getbloc(no);
        d = (*pdesc);   /* d pointe sur le debut du premier descripteur */
        for (i=0; i < lg_tdesc; i++) {  /* vidage table des descripteurs */
                pbyte(no,*d++); k++;
                if (k == SIZETDESC) {
                        d = *(++pdesc); k = 0;
                }
        }
        return (n);
}					/* vid_tproc */


BINAIRE vid_nomspr ( no, nbp , ptr )

/*      Ecriture des noms des procedures dans le fichier traduit
 */
BINAIRE no,nbp;
TabProc * ptr;
{                                       /* vid_nomspr */
        BINAIRE n;

        n = getbloc(no);
        pbin(no,nbp);
        pprnom(no,FALSE,ptr);
        return (n);
}                                       /* vid_nomspr */


BINAIRE vid_xproc (no, nbp , ptr )

/*      Ecriture des references aux procedures externes dans le fichier traduit
 */
BINAIRE no,nbp;
TabProc * ptr;
{                                       /* vid_xproc */
        BINAIRE n;

        n = getbloc(no);
        pbin(no,nbp);
        pprnom(no,TRUE,ptr);
        return (n);
}                                       /* vid_xproc */


BINAIRE vid_xobj(no,p)

/*      Ecriture d'un table de relogeabilite dans le fichier traduit
 */
BINAIRE no;
RelRef *p;
{                                       /* vid_xobj */
        BINAIRE n;
        ExtRef *r;

        n = getbloc(no);
        do {
                pbin(no,p->ads);
                r = p->lref;
                do {
                        pbin(no,r->bloc); pbin(no,r->ofst); r = r->suiv;
                }
                while (r != GenericNULL(ExtRef));
                pbin(no,0);
                p = p->suiv;
        }
        while (p != GenericNULL(RelRef));
        pbin(no,(BINAIRE) 0xFFFF);

        return (n);
}                                       /* vid_xobj */


BINAIRE vid_tseg(no, lg_tdesc, pdesc )

/*      Ecriture de la table des segments dans le fichier traduit
 */
BINAIRE no;
BINAIRE* lg_tdesc;
BYTE **pdesc;
{                                       /* vid_tproc */
        register BYTE *d;
        register BINAIRE i;
        BINAIRE n , k = 0;

        n = getbloc(no);
        d = (*pdesc);   /* d pointe sur le debut du premier descripteur */
        for (i=0; i < *lg_tdesc; i++) {  /* vidage table des descripteurs */
                pbyte(no,*d++); k++;
                if (k == (SIZETDESC -16) ) {
						 d = *(++pdesc); k = 0;
						 (*lg_tdesc) -= 16; 	/* 29/10/98: ajuste lgr table seg */
                }
        }
        pbyte(no,(BYTE) -1); pbyte(no,(BYTE) -1);
        return (n);
}					/* vid_tseg */


BINAIRE vid_nomseg (no, nbs , ptr )

/*      Ecriture des noms des segments dans le fichier traduit
 */
BINAIRE no,nbs;
TabSeg * ptr;
{                                       /* vid_nomseg */
        BINAIRE n;

        n = getbloc(no);
        pbin(no,nbs);
        ssrnom(no,FALSE,ptr);
        return (n);
}                                       /* vid_nomseg */


BINAIRE vid_xseg ( no, nbs , ptr )

/*      Ecriture des references aux segments externes dans le fichier traduit
 */
BINAIRE no,nbs;
TabSeg * ptr;
{                                       /* vid_xseg */
        BINAIRE n;

        n = getbloc(no);
        pbin(no,nbs);
        ssrnom(no,TRUE,ptr);
        return (n);
}                                       /* vid_xseg */


static void ssrnom(no,ext,s)

/*      Ecriture de l'ensemble "interface" d'un segment
 *      avec la distinction entre externe et interne
 */
BINAIRE no;
BOOL ext;
TabSeg *s;
{                       /* ssrnom */
        ExtRef *r;

        while ( s != GenericNULL(TabSeg) ) {
                if ( s->ext == ext ) { 

                        if ( s->ext ) /* segment externe : mettre les references */
/* Numero du module */
                                pbin(no,s->mod);

/* Nom du segment */
                        pstrzero(no,s->nom);  /* nom du segment */

/* Numero du segment */
                        pbin(no,s->num);

                        if ( s->ext ) { /* segment externe : mettre les references */
                                r = s->lref;
                                while (r != GenericNULL(ExtRef)) {
                                        pbin(no,r->bloc); pbin(no,r->ofst); r = r->suiv;
                                }
                                pbin(no,0);
                        } else { /* segment interne */
/* Adresse du segment */
       	                        pbin(no,s->ads);

/* Adresse de la table des procs et segs appeles */
	                        pbin(no,s->blien);

/* Adresse de la table de correspondance NEWLINE */
				pbin(no,s->adtc);

/* Longueur de la table de correspondance NEWLINE */
				pbin(no,s->lgtc);
			}
                }
                s = s->suiv;
        }
}                       /* ssrnom */


BINAIRE vid_tnmod(no, tmodule )

/*      Ecriture de la table des noms de modules dans le fichier traduit
 */
BINAIRE no;
TabMod *tmodule;
{                                       /* vid_tnmod */
        BINAIRE n = 0;

        n = getbloc(no);
        while ( tmodule != GenericNULL(TabMod) ) {
                pbin(no,tmodule->num);
                pstrzero(no,tmodule->nom);
                tmodule=tmodule->suiv;
        }
        return(n);
}


BINAIRE vid_tnsrc(no, tsrc )

/*      Ecriture de la table des noms de modules dans le fichier traduit
 */
BINAIRE no;
TabSrc *tsrc;
{                                       /* vid_tsrc */
        BINAIRE n = 0;

        n = getbloc(no);
        while ( tsrc != GenericNULL(TabSrc) ) {
                pbin(no,tsrc->num);
                pstrzero(no,tsrc->nom);
                tsrc=tsrc->suiv;
        }
	pbin(no,(BINAIRE) 0xFFFF);
        return(n);
}					/* vid_tsrc */


void vidmap(no,namelst)

/*      Ecriture de la "map" de mise au point dans le fichier traduit
 */
BINAIRE no;
char *namelst;
{                                       /* vidmap */
        int     i;
        MapRef  *p;

        hd_tcode.adr_map = getbloc(no);
        while ((p = map) != GenericNULL(MapRef)) {
                pbyte(no,(BYTE) p->typ); pbin(no,p->num);
                pbin(no,p->sd); pbyte(no,p->od);
                pbin(no,p->sf); pbyte(no,p->of);
                for (i = 0; i < 7; i++) {
                        pbyte(no,0);
                }
                map = p->suiv; Free_Map(p);
        }
        pbyte(no,(BYTE) 'X');
        hd_tcode.adr_lst = getbloc(no);
        while (*namelst != EOSTR) {
                pbyte(no,(BYTE) *namelst++);
        }
        pbyte(no,0);
}                                       /* vidmap */


void pbyte(no,b)

/*      Ecriture d'un octet dans le fichier traduit
 */
BINAIRE no;
BYTE b;
{                                       /* pbyte */
#ifdef _TEST_BUF_
	if ( flgcode == FALSE ) {
#endif
	        fic[no].tampon[fic[no].cur_ofst++] = b;
        	if (fic[no].cur_ofst == LGBLOC) {
                	getbloc(no);
        	}
#ifdef _TEST_BUF_
	} else {
		mbyte(b);
	}
#endif 
}                                       /* pbyte */


void pbin(no,b)

/*      Ecriture d'un binaire (2 octets) dans le fichier traduit
 *      en realisant l'inversion requise pour le T-Code
 */
BINAIRE no;
BINAIRE b;
{                                       /* pbin */
        BINAIRE tb;

        tb = SECOND_BYTE(b);
        pbyte(no,(BYTE) tb);
        tb = FIRST_BYTE(b);
        pbyte(no,(BYTE) tb);
        return;
}                                       /* pbin */


void plong(no,l)

/*      Ecriture d'un long (4 octets) dans le fichier traduit
 *      en realisant l'inversion requise pour le T-Code
 */
BINAIRE no;
long l;
{                                       /* plong */
        BYTE tb;

        tb = LFOURTH_BYTE(l);
        pbyte(no,tb);
        tb = LTHIRD_BYTE(l);
        pbyte(no,tb);
        tb = LSECOND_BYTE(l);
        pbyte(no,tb);
        tb = LFIRST_BYTE(l);
        pbyte(no,tb);
        return;
}                                       /* plong */


void pstrzero(no,s)

/*      Ecriture d'une chaine de caracteres dans le fichier traduit
 *      sur une longueur de l, en cadrant au besoin avec des blancs
 */
BINAIRE no;
char *s;
{                                       /* pstrzero */
        while (*s) {
                pbyte(no, (BYTE) *s++);
        }
        pbyte(no,0);
}                                       /* pstrzero */


void pstr(no,s,l)

/*      Ecriture d'une chaine de caracteres dans le fichier traduit
 *      sur une longueur de l, en cadrant au besoin avec des blancs
 */
BINAIRE no;
char *s;
int l;
{                                       /* pstr */
        while (*s) {
                pbyte(no, (BYTE) *s++); l--;
        }
        while (l) {
                pbyte(no,padstr); l--;
        }
}                                       /* pstr */


BINAIRE getbloc(no)
BINAIRE no;
/*      Retourne le 1er bloc libre dans le fichier traduit, qui
 *      devient le bloc courant pour les acces suivant.
 */
{                                       /* getlgbloc */
        if (fic[no].cur_ofst != 0) {    /* sinon bloc suivant = bloc courant */
                purge(no);
                fic[no].cur_bloc++;
                fic[no].cur_ofst = 0;
        }
        return (fic[no].cur_bloc);
}                                       /* getlgbloc */

#ifdef _TEST_BUF_

void backres(no,b,r,a)

/*      resolution de la reference sur l'adresse 'a' a l'offset 'r'
 *      du bloc d'instructions de numero 'b', et du chainage eventuel.
 *      cette fonction effectue des retours en arriere dans le fichier
 *      traduit, mais elle laisse en sortie le bloc courant positionne comme
 *      lors de l'appel.
 */
BINAIRE no,b,r,a;
{                                       /* backres */
        BINAIRE cb,ab;          /* garder la position initiale */
        BINAIRE nb;             /* numero de bloc necessaire */
        BINAIRE ar;             /* et adresse de la reference dans ce bloc */
        BINAIRE nr;             /* reference courante a traiter */
        BINAIRE b1,b2;

        if (!t_prod)
                return;         /* pas de production de fichier traduit */

	cb=ppcode; ab=pscode; nr = r;

        /* decomposer l'adresse a patcher */
        b1 = FIRST_BYTE(a); b2 = SECOND_BYTE(a);

        /* pour chaque reference de la liste */
        do {
                /* positionner le bloc necessaire pour la reference courante */

		/* posit */
                nb = nr / NBBYTEBUF;
		ppcode = nb;

                /* chercher la reference et la mettre a jour */
                ar = nr % NBBYTEBUF;

                /* les binaires sont toujours en notation inversee dans
                 * le fichier traduit ...
                 */
                nr = (BINAIRE) ( *(pcode[nb]+ar) & 0x00FF);
                *(pcode[nb]+ar) = (BYTE) b2;
                if (ar != (NBBYTEBUF-1)) {
                        nr |= ((BINAIRE) *(pcode[nb]+ar+1) << 8) & (BINAIRE) 0xFF00;
                        *(pcode[nb]+ar+1) = (BYTE) b1;
                }
                else {
			/* posit */
			nb = nb + 1;
                        nr |= ((BINAIRE) *(pcode[nb]+0) << 8) & (BINAIRE) 0xFF00;
                        *(pcode[nb]+0) = (BYTE) b1;
                }
        }
        while (nr != (BINAIRE) 0xFFFF);

        /* remettre la position initiale */
        ppcode = cb;
        pscode = ab;
}                                       /* backres */

#else

void backres(no,b,r,a)

/*      resolution de la reference sur l'adresse 'a' a l'offset 'r'
 *      du bloc d'instructions de numero 'b', et du chainage eventuel.
 *      cette fonction effectue des retours en arriere dans le fichier
 *      traduit, mais elle laisse en sortie le bloc courant positionne comme
 *      lors de l'appel.
 */
BINAIRE no,b,r,a;
{                                       /* backres */
        BINAIRE cb,ab;          /* garder la position initiale */
        BINAIRE nb;             /* numero de bloc necessaire */
        BINAIRE ar;             /* et adresse de la reference dans ce bloc */
        BINAIRE nr;             /* reference courante a traiter */
        BINAIRE b1,b2;
        BOOL flpur;             /* indicateur de purge necessaire */
        BOOL flrel;             /* indicateur de relecture necessaire */

        if (!t_prod)
                return;         /* pas de production de fichier traduit */

        cb = fic[no].cur_bloc; ab = fic[no].cur_ofst; nr = r;

        flpur = TRUE;
        flrel = TRUE;

        /* interdire une purge destructrice par des (-1) */
        fic[no].cur_ofst = LGBLOC;

        /* decomposer l'adresse a patcher */
        b1 = FIRST_BYTE(a); b2 = SECOND_BYTE(a);
        /* pour chaque reference de la liste */
        do {
                /* positionner le bloc necessaire pour la reference courante */

                nb = b + (nr / LGBLOC);
                flpur = ((cb == fic[no].cur_bloc) ? FALSE : TRUE);
                flrel = ((cb == nb) ? FALSE : TRUE);
                posit(no,nb,flpur,flrel);

                /* chercher la reference et la mettre a jour */
                ar = nr % LGBLOC;
                /* les binaires sont toujours en notation inversee dans
                 * le fichier traduit ...
                 */
                nr = (BINAIRE) (fic[no].tampon[ar] & 0x00FF);
                fic[no].tampon[ar] = (BYTE) b2;
                if (ar != (LGBLOC-1)) {
                        nr |= ((BINAIRE) fic[no].tampon[ar+1] << 8) & (BINAIRE) 0xFF00;
                        fic[no].tampon[ar+1] = (BYTE) b1;
                }
                else {
                        flpur = ((cb == fic[no].cur_bloc) ? FALSE : TRUE);
                        flrel = ((cb == nb+1) ? FALSE : TRUE);
                        posit(no,nb+1,flpur,flrel);
                        nr |= ((BINAIRE) fic[no].tampon[0] << 8) & (BINAIRE) 0xFF00;
                        fic[no].tampon[0] = (BYTE) b1;
                }
        }
        while (nr != (BINAIRE) 0xFFFF);

        /* remettre la position initiale */
        flpur = ((cb == fic[no].cur_bloc) ? FALSE : TRUE);
        posit(no,cb,flpur,FALSE);
        fic[no].cur_ofst = ab;
}                                       /* backres */
#endif /* _TEST_BUF */


/*              Primitives internes             */
/*              --------------------            */

static void pnom(no,s)

/*      Ecriture du couple nom-adrdesc d'un symbole dans une table de noms
 */
BINAIRE no;
TabSymb *s;

{                                       /* pnom */
	/*	if (s)
		{
			if (s->g != GenericNULL(TabSymb))
                pnom(no,s->g);
			pstrzero(no,s->pid);
			pbin(no,s->ads);

			if (s->d != GenericNULL(TabSymb))
                pnom(no,s->d);
		}*/
#ifdef __STRUCT__	/* Structures */
	char* charTemp;
#endif

	if (s)
		{
			if (s->g != GenericNULL(TabSymb))
                pnom(no,s->g);
			
#ifdef __STRUCT__	/* Structures */
			if (s->prev)
			{
				if ((s->prev->type->pStruct)) 
				{
					charTemp= (char *) Xmalloc(LGIDENT);
					sprintf(charTemp,"%13s%d",s->pid,struct_index);
					pstrzero(no,charTemp);
					struct_index++;
					Xfree(charTemp);
				}
			}
			else
#endif
				pstrzero(no,s->pid);

			pbin(no,s->ads);

			if (s->d != GenericNULL(TabSymb))
                pnom(no,s->d);

#ifdef __STRUCT__	/* Structures */
			if (s->next!=GenericNULL(TabSymb))	
				pnom(no,s->next);
#endif
			

		}
}  
/*
static void pInitGlobal(no,s)

//      Ecriture de l 'initialisation des globales
 
BINAIRE no;
TabSymb *s;
{                                       

        if (s->g != GenericNULL(TabSymb))
                pnom(no,s->g);
        pstrzero(no,s->pid);
        pbin(no,s->ads);

        if (s->d != GenericNULL(TabSymb))
                pnom(no,s->d);
}                                     

*/
static void pprnom(no,ext,s)

/*      Ecriture de l'ensemble "interface" d'une procedure
 *      avec la distinction entre externe et interne
 */
BINAIRE no;
BOOL ext;
TabProc *s;
{                                       /* pprnom */
        register BINAIRE i;
        register BYTE *p;
        ExtRef *r;

        if (s->g != GenericNULL(TabProc))
                pprnom(no,ext,s->g);

        if (s->ext == ext) {

           if (s->ext && ext) /* procedure externe : mettre numero de module */
                pbin(no,s->mod);

           pstrzero(no,s->pid);       /* nom de la procedure */

           if ((!s->ext) && (!ext)) {
		if ( s->forward == TRUE ) {
			if ( s->util ) 
				err2(USUAL,ersynt17,s->pid);
			else
				err2(WARNING,ersymb7,s->pid);
		}
		/* procedure interne : mettre adr. desc. */
                pbin(no,s->ads);
		/* procedure interne : mettre table proc appelees */
		pbin(no,s->blien);
		/* table correspondance et sa longueur */
		pbin(no,s->adtc); pbin(no,s->lgtc);
	   }		

           i = s->nba; pbin(no,i); /* chaine des arguments */
           p = s->adta;
           i &= MNBARG;
           while(i--)
                pbyte(no,*p++);

           if ((s->ext) && (ext)) { /* proc externe : mettre les references */
                r = s->lref;
		if ( r == GenericNULL(ExtRef) )
			err2(WARNING,ersymb7,s->pid);
                while (r != GenericNULL(ExtRef)) {
                        pbin(no,r->bloc); pbin(no,r->ofst); r = r->suiv;
                }
                pbin(no,0);
           }
        }

        if (s->d != GenericNULL(TabProc))
                pprnom(no,ext,s->d);
}                                       /* pprnom */


static void posit(no,numb,flpur,flrel)

/*      posit sur bloc de numero 'numb' dans le traduit
 *      effectue une purge si 'flpur' est vrai, et
 *      lit effectivement le bloc suivant si 'flrel' est vrai.
 */
BINAIRE no;     /* numero fichier dans la table */
BINAIRE numb;
BOOL flpur;
BOOL flrel;
{                                       /* posit */
        long int depl;
        int i;

        if (flpur) {
                if (numb == fic[no].cur_bloc)
                        return;         /* deja fait */
                purge(no);                /* purge si necessaire */
        }
        else {
        /* recopie bloc courant dans zone locale et evite la
           purge du bloc courant */
                for (i=0 ; i<LGBLOC ; i++)
                        tamloc[i] = fic[no].tampon[i];
        }

        if (numb == fic[no].cur_bloc)
                return;

        depl = bintolong(numb);
        depl *= (long) LGBLOC;
        if (t_prod) {
                if (flrel) {
                        if(XTseek(fic[no].fcode,depl) == -1L)
                                erreur(FATALE,errges2);
                        if (XTread(fic[no].fcode,fic[no].tampon,LGBLOC) != XT_OK)
                                erreur(FATALE,errges2);
                }
                else {
                        for (i=0 ; i<LGBLOC ; i++)
                                fic[no].tampon[i] = tamloc[i];
                }
                XTseek(fic[no].fcode,depl);
        }
        fic[no].cur_bloc = numb;
}                                       /* posit */


static void purge(no)

/*      purge bloc courant
 */
BINAIRE no;     /* numero du fichier dans la table */
{                                       /* purge */
        while (fic[no].cur_ofst < LGBLOC)
                fic[no].tampon[fic[no].cur_ofst++] = (BYTE) -1;
        if (t_prod)
                if (XTwrite(fic[no].fcode,fic[no].tampon,LGBLOC) != XT_OK)
                        erreur(FATALE,errges1);

}                                       /* purge */


static BOOL xrename(no,nouvnom)

/*      Renommer le fichier de travail, en detruisant si necessaire le
 *      fichier portant le nom definitif.
 *      Le fichier est ensuite ferme.
 *      NB: Sous MS/DOS, PROLOGUE et VMS, on renomme un fichier
 *      ferme. Sous UNIX, on renomme un fichier ouvert.
 */
char *nouvnom;
BINAIRE no;     /* numero du fichier */
{                                       /* xrename */

        /* Il faut supprimer le fichier portant le nouveau nom.
         * Pour cela, il faut reserver ce fichier (blocage exclusif)
         * et refuser la suppression si ce blocage n'est pas possible.
         * Si le fichier a deja ete ouvert en partageable (traduction
         * partielle), il faut d'abord liberer le verrou.
         */
#ifdef unix
        liberlox(nouvnom);
        if ((Access(nouvnom,0,1) != 0) && (errno != ENOENT))
                return(FALSE);
#endif /* unix */
        Xunlink(nouvnom);

#ifdef prologue
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);
        if (rename(fic[no].name,nouvnom) != 0)
                return (FALSE);
#endif /* prologue */
#ifdef msdos
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);
        if (rename(fic[no].name,nouvnom) != 0)
                return (FALSE);
#endif /* msdos */
#ifdef unix
        if (link(fic[no].name,nouvnom) != 0)
                return (FALSE);
        Xunlink(fic[no].name);
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);
#endif /* unix */
#ifdef vms
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);
        if (rename(fic[no].name,nouvnom) != 0)
                return (FALSE);
#endif /* vms */
        return (TRUE);
}                                       /* xrename */


static BOOL xrenold(no,nouvnom)

/*      Renommer le fichier de travail, en detruisant si necessaire le
 *      fichier portant le nom definitif.
 *      Le fichier est ensuite ferme.
 *      Le nouveau fichier doit prendre la date de la
 *      naissance du Christ (ou de MS/DOS, UNIX, ...) !!!
 */
char *nouvnom;
BINAIRE no;     /* numero dans la table des fichiers */
{                                       /* xrenold */
#ifdef prologue
        char ngfdd[64];
        BINAIRE nolog;
        _PRL_ANFC zone;
        dword lgr;

        /* On supprime l'ancien fichier portant le nouveau nom
         * de celui que l'on desire renommer.
         * On commence par verifier si ce fichier existe.
         * S'il existe, et que le fichier est ouvert par un autre
         * poste, la suppression ne sera pas possible, mais
         * il faut tout de meme fermer le fichier temporaire.
         */
        if (access(nouvnom,0) == 0) {
                if (Xunlink(nouvnom) == EOF) {
                        XTclose(fic[no].fcode);
                        return(FALSE);
                }
        }

        /* On renomme le fichier : on travaille sur un fichier ferme.
        */
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);
        if (rename(fic[no].name,nouvnom) != 0)
                return (FALSE);

        /* On lit le descripteur disque principal du fichier de nouveau
         * nom, on remet a zero les informations de date et heure, et
         * on reecrit le descripteur disque principal.
         * On utilise les primitives Amenesik / Sologic de "bas niveau".
         */
        if (_prl_anfc(nouvnom,&zone,(word *)&lgr) != 0)
                return(FALSE);

        if (_ngf_xopen(&zone,&nolog,&lgr) != 0)
                return(FALSE);

        if (_ngf_getdd(nolog,&ngfdd[0]) != 0) {
                _ngf_close(nolog);
                return(FALSE);
        }

        ngfdd[44] &= 0x1f;              /* RAZ date */
        ngfdd[47] &= 0x1f;
        ngfdd[50] &= 0x1f;
        ngfdd[53] &= 0x1f;
        ngfdd[56] &= 0x1f;
        ngfdd[62] = 0;                  /* RAZ heure */
        ngfdd[63] = 0;
        if (_ngf_putdd(nolog,&ngfdd[0]) != 0) {
                _ngf_close(nolog);
                return(FALSE);
        }

        _ngf_close(nolog);
        return(TRUE);
#endif /* prologue */

#ifdef msdos
#ifndef WIN32
        int fh;
#endif
        /* On supprime l'ancien fichier portant le nouveau nom
         * de celui que l'on desire renommer.
         * Pas de probleme car monotache.
         */
        Xunlink(nouvnom);

        /* On renomme le fichier : on travaille sur un fichier ferme.
        */
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);
        if (rename(fic[no].name,nouvnom) != 0)
                return (FALSE);

#ifdef WIN32
	{ 
		Epoch(nouvnom);
	}
#else
        /* On ouvre le fichier en mode lecture seule, et on remet
         * a zero l'heure de derniere modification.
         */
        if (_dos_open(nouvnom,O_RDONLY,&fh) != 0) {
                return(FALSE);
        }
        if (_dos_setftime(fh,0x0021,0) != 0) {
                _dos_close(fh);
                return(FALSE);
        }
        _dos_close(fh);
#endif
        return(TRUE);
#endif /* msdos */

#ifdef unix
        struct {
          time_t actime;
          time_t modtime;
        } utb;
        int resac;

        /* On supprime l'ancien fichier portant le nouveau nom
         * de celui que l'on desire renommer.
         * Pour cela, il faut reserver ce fichier (blocage exclusif)
         * et refuser la suppression si ce blocage n'est pas possible,
         * a moins que ce ne soit que parce que le fichier n'existe pas.
         * Si le fichier a deja ete ouvert en partageable (traduction
         * partielle), il faut d'abord liberer le verrou.
         */
        liberlox(nouvnom);
        resac = Access(nouvnom,0,1);
        if (resac != 0) {
                if (errno != ENOENT) {
                        XTclose(fic[no].fcode);
                        return(FALSE);
                }
        }
        Xunlink(nouvnom);

        /* On cree un nouveau lien vers le fichier, avec le
         * nouveau nom, et on supprime le lien avec l'ancien
         * nom. On travaille sur un fichier ouvert.
         */
        if (link(fic[no].name,nouvnom) != 0)
                return (FALSE);
        Xunlink(fic[no].name);

        /* On ferme ensuite le fichier renomme */
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);

        /* On change la date et heure du fichier renomme en la
         * fixant au 31/12/1969.
         */
        utb.actime = 0;
        utb.modtime = 0;
        if (utime(nouvnom,&utb) != 0)
                return(FALSE);

        return(TRUE);
#endif /* unix */

#ifdef vms
        /* Il n'est pas possible sous VMS de changer la date
         * d'un fichier, sauf en le modifiant et en lui faisant
         * donc prendre la date de la derniere modification.
         */

        Xunlink(nouvnom);
        if (XTclose(fic[no].fcode) == EOF)
                return (FALSE);
        if (rename(fic[no].name,nouvnom) != 0)
                return (FALSE);

        return(TRUE);
#endif /* vms */
}                                       /* xrenold */


static void crypt(pkey,sptr,slen,mode)

/*      Fonction pour la protection du  T-Code
 *      retourne un pointeur sur le buffer converti
 */
BINAIRE pkey;   /* code de la protection */
BYTE    *sptr;  /* buffer a convertir (sur lui meme) */
BINAIRE slen;   /* longueur du buffer */
BOOL    mode;   /* codage si TRUE, decodage si FALSE */
{                                       /* crypt */
        BYTE    *rptr;
        BYTE    exkm[16][16];

        short int       kdex,kdey;
        EXAWORD         x,y,rotor,cmpt,phase;

        rptr = sptr; cmpt = 0;
        for (x = 0; x < 16 ; x++) {
                for ( y =0; y < 16; y++ ) {
                        exkm[x][y] = (BYTE) cmpt; cmpt++;
                }
        }
        rotor = 1; phase = pkey & 0x0007;
        while ( slen > 0 ) {
                if ( mode ) {
                        kdex = ((int) *sptr) / 16;
                        kdey = ((int) *sptr) % 16;
                        switch ( phase ) {
                                case 1 : kdey++;
                                case 0 : kdex--; break;
                                case 2 : kdey++; break;
                                case 3 : kdey++;
                                case 4 : kdex++; break;
                                case 5 : kdex++;
                                case 6 : kdey--; break;
                                case 7 : kdex--; kdey--;
                        }
                }
                else    {
                        for ( x = 0; x < 16; x++ ) {
                                for ( y = 0; y < 16; y++ ) {
                                        if ( exkm[x][y] == *sptr ) {
                                                kdex = x; x = 16;
                                                kdey = y; y = 16;
                                        }
                                }
                        }
                        switch ( phase ) {
                                case 1 : kdey--;
                                case 0 : kdex++; break;
                                case 2 : kdey--; break;
                                case 3 : kdey--;
                                case 4 : kdex--; break;
                                case 5 : kdex--;
                                case 6 : kdey++; break;
                                case 7 : kdex++; kdey++;
                        }
                }
                if ( kdex > 15 ) { kdex = 0; }
                if ( kdey > 15 ) { kdey = 0; }
                if ( kdex < 0 ) { kdex = 15; }
                if ( kdey < 0 ) { kdey = 15; }
                if ((pkey & rotor ) != 0 ) {
                        phase++;
                        if ( phase > 7 ) { phase = 0; }
                }
                rotor <<= 1;
                if ( rotor == 0 ) { rotor = 1; }
                *(sptr++) = exkm [ kdex ][ kdey ]; slen--;
        }
}                                       /* crypt */


BINAIRE vid_xvar ( no, nbx , ptr )

/*      Ecriture des references aux variables externes dans le fichier traduit
 */
BINAIRE no,nbx;
LstAncr * ptr;
{                                       /* vid_xvar */
BINAIRE n;
LstAncr *ptr2;

	/* 1ere etape : vider les listes de variables externes */
	ptr2 = ptr;
	while ( ptr2 != GenericNULL(LstAncr) ) {
		/* m.a.j adresse dans .dbg */
		ptr2->adrxvar = vid_lxvar(no,ptr2->nbxvar,ptr2->xvar);
		ptr2 = ptr2->suiv;
	}

#ifdef _OPT_VAR_EXTERN
	ptr2 = ptr;

	/* Parcours de la liste des points d'ancrages */
	while ( ptr2 != GenericNULL(LstAncr) ) {

		if (ptr2->adrxvar == 0)
			nbx--;

		/* passage au suivant */
		ptr2 = ptr2->suiv;
	}
	if ( nbx == 0 ) {
	/* Pas du tout de variables externes utilisees */
		return(0);	
	}
#endif /* _OPT_VAR_EXTERN */

	/* 2eme etape : vider la liste des points d'ancrage */
	ptr2 = ptr;
	n = getbloc(no);

	/* Memorisation du nombres de point d'ancrage */
	pbin(no,nbx);

	/* Parcours de la liste des points d'ancrages */
	while ( ptr2 != GenericNULL(LstAncr) ) {

#ifdef _OPT_VAR_EXTERN
		if ( ptr2->adrxvar != 0 ) {
			/* Numero du module */
			pbin(no,ptr2->mod);

			/* Nom de la variable ancrage */
		        pstrzero(no,ptr2->nom);
		
			/* type de mem : M/E */
			pbyte(no,ptr2->type);

			/* Adresse du point d'ancrage : 4 octets */
			plong(no,ptr2->ads);

			/* Adresse de la table des var externes */
			pbin(no,ptr2->adrxvar);
		}
#else
		/* Numero du module */
		pbin(no,ptr2->mod);

		/* Nom de la variable ancrage */
	        pstrzero(no,ptr2->nom);
		
		/* type de mem : M/E */
		pbyte(no,ptr2->type);

		/* Adresse du point d'ancrage : 4 octets */
		plong(no,ptr2->ads);

		/* Adresse de la table des var externes */
		pbin(no,ptr2->adrxvar);
#endif /* _OPT_VAR_EXTERN */

		/* passage au suivant */
		ptr2 = ptr2->suiv;
	}

	return(n);
}                                       /* vid_xvar */


BINAIRE vid_lxvar ( no, nbx , ptr )

/*      Ecriture des listes de variables externes 
 */
BINAIRE no,nbx;
LstXvar * ptr;
{                                       /* vid_lxvar */

	BINAIRE n;
	ExtRef *r;

#ifdef _OPT_VAR_EXTERN
	LstXvar *ptr2;

	ptr2 = ptr;
	/* Parcours de la liste des variables externes */

	while ( ptr2 != GenericNULL(LstXvar) ) {
		if ( ptr2->info->lref == GenericNULL(ExtRef) ) {
			nbx--;
		}
		/* passage au suivant */
		ptr2 = ptr2->suiv;
	}
	if ( nbx == 0 ) {
	/* pas de variables utilisees */
		return (0);
	}
#endif
	n = getbloc(no);

	/* Memorisation du nombre de  variables externes */
	pbin(no,nbx);

	/* Parcours de la liste des variables externes */

	while ( ptr != GenericNULL(LstXvar) ) {

#ifdef _OPT_VAR_EXTERN
		if ( ptr->info->lref != GenericNULL(ExtRef) ) {

			/* Nom de la variable externe */
		        pstrzero(no,ptr->info->pid);
		
			/* descripteur de la variable externe */
			pbin(no,ptr->info->ads);
		
			/* adresse de relocation */	
			/* Si il y a des relocations */
			/* La 1ere reference est bidon : Tete fixe */
/* 14/09/93 */
			r = ptr->info->lref->suiv;
        	        while (r != GenericNULL(ExtRef)) {
	        	        pbin(no,r->bloc); pbin(no,r->ofst); r = r->suiv;
                	}
	                pbin(no,0);
		}
#else
		/* Nom de la variable externe */
	        pstrzero(no,ptr->info->pid);
		
		/* descripteur de la variable externe */
		pbin(no,ptr->info->ads);
		
		/* adresse de relocation */	
		/* Si il y a des relocations */
		/* La 1ere reference est bidon : Tete fixe */
/* 14/09/93 */
		if ( ptr->info->lref != GenericNULL(ExtRef) ) {
			r = ptr->info->lref->suiv;
        	        while (r != GenericNULL(ExtRef)) {
	        	        pbin(no,r->bloc); pbin(no,r->ofst); r = r->suiv;
                	}
		}
                pbin(no,0);
#endif /* _OPT_VAR_EXTERN */

		/* passage au suivant */
		ptr = ptr->suiv;
	}
	return(n);

}                                       /* vid_lxvar */


BINAIRE vid_etv ( no, nbe , ptr )

/*      Ecriture des references aux etiquettes de variables dans le fichier traduit
 */
BINAIRE no,nbe;
LstEtiqvar * ptr;
{                                       /* vid_etv */
BINAIRE n;

	n = getbloc(no);

	/* Memorisation du nombres d'etiquettes de variable */
	pbin(no,nbe);

	/* Parcours de la liste des etiquettes */
	while ( ptr != GenericNULL(LstEtiqvar) ) {

		/* Nom de l'etiquette : 1er element de la liste des var ext */
	        pstrzero(no,ptr->nom);
		
		/* type de l'etiquette : M/E */
		pbyte(no,ptr->type);

		/* Adresse d'implantation sur 4 octets */
		plong(no,ptr->adr);

		/* passage au suivant */
		ptr = ptr->suiv;
	}
	return(n);
}                                       /* vid_etv */


/*
	Allocation du 1er buffer memoire et positionne le flag
	indiquant a pbyte que l'on ecrit en mem
*/
void initcode()
{
#ifdef _TEST_BUF_
int i;
	/* Initialisation des pointeurs Tampons de code */
	for (i=0;i<NBBUFCODE; i++)
		pcode[i] = GenericNULL(BYTE);

	/* Allocation du 1er */
	if ( ( pcode[0] = Xmalloc(NBBYTEBUF) ) == GenericNULL(BYTE) )
		erreur(FATALE,errmem);

	flgcode = TRUE;
	ppcode = 0;
	pscode = 0;
#endif
}


void mbyte(b)
BYTE b;
{
#ifdef _TEST_BUF_
        *(pcode[ppcode]+pscode) = b;
	pscode++;
       	if ( pscode == NBBYTEBUF) {
		ppcode++;
		pscode=0;
		if ( ( pcode[ppcode] = Xmalloc(NBBYTEBUF) ) == GenericNULL(BYTE) )
			erreur(FATALE,errmem);
	}
#endif
}


void videcode(no)
BINAIRE no;
{
#ifdef _TEST_BUF_
int i,j;
	flgcode = FALSE;

	/* recopie sur disque et liberation des buffers complets */
	for ( i=0; i<ppcode; i++) {
		for (j=0; j<NBBYTEBUF; j++) {
			pbyte(no, *(pcode[i]+j));
		}
		Xfree(pcode[i]);
	}

	/* recopie du dernier */
	for (j=0; j<pscode; j++) {
		pbyte(no, *(pcode[ppcode]+j));
	}
	Xfree(pcode[ppcode]);
#endif 
}

#endif	/* _gestfic_c */

/* ------------------- Fin du fichier : gestfic.c ---------------------- */



