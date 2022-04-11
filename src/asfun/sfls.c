/************************************
* Services Fenetres / Ligne Status  *
*-----------------------------------*
* Source : sfls.c                   *
*-----------------------------------*
* Version : 1.1b                    *
* Mise a jour le : 15/06/1990   sb  *
*************************************
* Fonctions                         *
*                                   *
* - lsmess     envoi d'un message   *
* - lsclear    clear du message     *
* - lsactiv    activation status    *
* - lsdesac    desactivation status *
*                                   *
*************************************/

#include "sfundef.h"

/**********************************************
* Creation d'une fenetre status
***********************************************/
TYPF	lscreatc(ls_nofen)
	WPTR ls_nofen;

{
/* variables externes */
	extern ls_tab ls;
	extern WORD ls_nfenu;
	extern BYTE fen_ini;

/* variables internes */
	WORD	ls_er;
	WDESC_APP  	fls;		/* descripteur fenetre */

/* test init */
	if (fen_ini != 2) return(werr_ini);

/* parametres fenetre */

	fls.Amere_nbr = 0;
	fls.Apos_lig = ls.s_plig;
	fls.Apos_col = ls.s_pcol;
	fls.Anb_lig = 1;
	fls.Anb_col = (MAXCOL+2) - (ls.s_pcol*2);
	fls.Acontrol = 1;
	fls.Aln_tit = 0;
	fls.Aatb_vid = ls.s_impt.atbc;
	fls.Aatbcol_text = ls.s_impt.colc;
	fls.Aatbcol_fond = ls.s_impt.colf;

/* creation fenetre */
	ls_er = wcreatc((WPTR)ls_nofen,(WDESC_APP_PTR)&fls);
	if (ls_er) return(ls_er);
	return(OK);

}

/**********************************************
* Envoi d'un message interne
**********************************************/
/* fonction lsmessc */

TYPF	lsmessc(ls_nofen,lg_mess,ls_mess)

WORD	ls_nofen;		/* no de fenetre */
BYTE	lg_mess;			/* longueur message */
BPTR	ls_mess;			/* message */

{
/* variables externes */
	extern ls_tab ls;

/* variables internes */
	int		ls_er;		/* erreur retournee */
	int		lg;		/* longueur interne */
	int		lgs;		/* longueur ligne status */
	int		ps_mess;	/* position message */
	char		lispace[256];	/* pour effacer */

	ls_er = wposcur(ls_nofen, 1 ,1);

/* mise a blanc de la ligne */
	if (MAXCOL < 256)
		memset(lispace,' ',MAXCOL);
	else
		memset(lispace,' ',255);
/* longueur message */

	lgs = (MAXCOL+2) - (ls.s_pcol*2);
	lg = (lg_mess < lgs)? lg_mess:lgs;
	while ((lg) && (ls_mess[lg-1] == ' ')) --lg;

/* ecriture du message cadre par des blancs */

/*	ps_mess = (lgs - lg)/2;
	if (ps_mess) ls_er = wwrite(ls_nofen,ps_mess,(BPTR) lispace); */

	ls_er = wwrite(ls_nofen,lg,(BPTR) ls_mess);

/*	lg = lgs - (ps_mess + lg); */

	lg = lgs - lg;
	if (lg > 0 ) ls_er = wwrite(ls_nofen,lg,(BPTR) lispace);

/* rendre la fenetre visible et en avant-plan */

	ls_er = wvis(ls_nofen);
	ls_er = wselect(ls_nofen);

	return(ls_er);
}

/**********************************************
* Envoi d'un message en ligne status
**********************************************/
/* fonction lsmess */

TYPF	lsmess(ls_type,lg_mess,ls_mess)

BYTE	ls_type;			/* type de message */
BYTE	lg_mess;			/* longueur message */
BPTR	ls_mess;			/* message */

{
/* variables externes */
	extern ls_tab ls;
	extern WORD ls_nfenu;
	extern BYTE fen_ini;
/* variables internes */
	int		ls_er;		/* erreur retournee */

/* test status actif */

	 if (ls_nfenu == 0) return(werr_ini);

/* test validite parametres */

	if ((ls_type == 0) || (ls_type > 3))
		return(werr_desc);

	if (lg_mess == 0) return(werr_desc);

/* mise a jour des attributs */

	if (ls_type == 1)
		ls_er = watb(ls_nfenu,ls.s_warn.atbc,ls.s_warn.colc,ls.s_warn.colf);
	else
          {
		if (ls_type == 2)
			ls_er = watb(ls_nfenu,ls.s_impt.atbc,ls.s_impt.colc,ls.s_impt.colf);
		else
			ls_er = watb(ls_nfenu,ls.s_ess.atbc,ls.s_ess.colc,ls.s_ess.colf);
	   };
	if (ls_er) return(ls_er);

	ls_er = lsmessc(ls_nfenu,lg_mess,ls_mess);
	if (ls_er) return(ls_er);

	return(OK);
}

/* fonction lsacti */

TYPF	lsacti()
{

/* variables externes */
	extern WORD ls_nfenu;
	extern BYTE fen_ini;

/* variables internes */
	int	ls_er;


	if (fen_ini != 2)
		return(werr_ini);
	if ( ls_nfenu != NULL) 
#if defined(HPUX) || defined(UNIXWARE)
	   lsdesac();
#else
	   return(werr_desc);	/* deja cree 29.10.92 */
#endif

	ls_er =	lscreatc((WPTR) &ls_nfenu);
	if (ls_er) return(ls_er);
	return(OK);
}

TYPF	lsdesac()
{
/* variables externes */
	extern WORD ls_nfenu;
	extern BYTE fen_ini;

/* variables internes */
	int	ls_er;

	if (fen_ini != 2) return(werr_ini);
	if (ls_nfenu == 0) return(werr_ini);
	ls_er = wsup(ls_nfenu);
	if (ls_er) return(ls_er);

	ls_nfenu = 0;
	return(OK);
}

TYPF	lsclear()
{
/* variables externes */
	extern WORD ls_nfenu;
	extern BYTE fen_ini;
/* variables internes */

	int ls_er;


	if (fen_ini != 2) return(werr_ini);
	if (ls_nfenu == 0) return(werr_ini);
	ls_er = winv(ls_nfenu);

	return(ls_er);
}

/* fin de fichier */





