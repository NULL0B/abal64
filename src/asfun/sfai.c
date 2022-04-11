/************************************
* Services Fenetres - Aide          *
*-----------------------------------*
* Source : sfai.c                   *
*-----------------------------------*
* Version : 1.1b                    *
* Mise a jour le : 07/06/1990   sb  *
* correction le 26/08/90: suppression forcage chapitre a 1 pour esc
* 		11.10.91 (llb) 	pb portage BOS
*				remplir les structures d'une maniere propre !	
* version 1.3
*		18/12/92 (llb)  adapt appel le_creatc (No elem = 0)
*				pb ajouter/inserer
* version 1.4
*		10/05/93 (llb)  style > 5 (ombrage )
*		04/06/93 (llb)	ld_creatc type 2 au lieu de 0 !!!! 
*		07/06/93 (llb)	Souris
*************************************
* Fonctions                         *
*                                   *
* - sa_activ     activation aide    *
* - sa_desac     desactivation      *
* - sa_aid       aide               *
* - sa_aiddef    aide par defaut    *
*************************************/

/****************************************************
* SERVICES FENETRES VERSION 0.0                     *
*****************************************************/
#include "sfundef.h"
#include "bda.h"
#include "mouse.h"

#include <stdio.h>
#include <fcntl.h>

#ifndef SEEK_SET
#define SEEK_SET	0
#endif /* SEEK_SET */

#define sa_vers '1'
#define sa_ind '1'
#define sa_niv 'a'

#define CH_LGN 20
#define CH_NMAX 99

#define SC_LGN 18
#define SC_NMAX 99

#define MC_LGN 8

/*********************************************************
* ENTETE DU FICHIER
**********************************************************/

typedef struct SA_DESC {

	char a_n[3];		/* aid pour controle bon fichier */
	char a_vers;		/* version */
	char a_ind;		/*indice */
	char a_niv;		/* niveau */
	char a_rs1[2];		/* reserve */

	BYTE a_ptch[4];		/* pointeur table des chapitres */
	BYTE a_nbch;		/* nombre de chapitres */

	BYTE a_ptsc[4];		/* pointeur table des sous-chapitres */
	BYTE a_nbsc;		/* nombre de sous-chapitres */

	BYTE a_ptmc[4];		/* pointeur table des mots-cles */
	WORD a_nbmc;		/* nombre de mot-cles */

	BYTE a_ptt1[4];		/* pointeur premier texte */

	BYTE a_stfd;		/* style par defaut */
	BYTE a_dligd;		/* ligne debut par defaut */
	BYTE a_dcold;		/* colonne debut par defaut */
	BYTE a_nligd;		/* nombre lignes par defaut */
	BYTE a_ncold;		/* nombre colonnes par defaut */

} sa_desc;

typedef struct SA_CHDESC {

	char a_chnom[CH_LGN];	/* nom de chapitre */
	BYTE a_chch1;		/* no de chapitre */
	BYTE a_chsc1;		/* no 1er sous chapitre */
	char a_chrs1[2];	/* reserve usage ulterieur */

} sa_chdesc;

typedef struct SA_SCDESC {

	char a_scnom[SC_LGN];	/*  nom de sous-chapitre */
BYTE a_scch1;		/* no du chapitre        */
	BYTE a_scsc1;		/* no de sous-chapitre   */
	BYTE a_scadt[4];	/*  adresse texte        */

} sa_scdesc;

typedef struct SA_MCDESC {

	char a_mcnom[MC_LGN];	/*  mot-cle              */
	BYTE a_mcch1;		/* no du chapitre        */
	BYTE a_mcsc1;		/* no du sous-chapitre   */
	BYTE a_mcadt[4];	/*  adresse 1er texte    */
	BYTE a_mcrsc1[2];	/* reserve               */
} mc_desc;

typedef struct SA_ENTTXT {

	char a_ennom[MC_LGN];	/*  mot-cle              */

	BYTE a_ennpg;		/* numero de page        */
	BYTE a_ench1;		/* numero de chapitre    */
	BYTE a_ensc1;		/* numero de sous-chap   */

	BYTE a_stf;		/* style                 */
	BYTE a_nlig;		/* nombre lignes         */
	BYTE a_ncol;		/* nombre colonnes       */
	BYTE a_dlig;		/* ligne debut           */
	BYTE a_dcol;		/* colonne debut         */

	WORD  a_lgtxt;		/* longueur du texte     */
	BYTE a_pttxs[4];	/* pointeur texte suiv   */
	BYTE a_pttxp[4];	/* pointeur texte prec   */
	BYTE a_ptmcs[4];	/* pointeur texte mot-cle suiv   */
	BYTE a_ptmcp[4];	/* pointeur texte mot-cle prec   */

} sa_entxt;
/*********************************
* variables globales aide        *
*********************************/

long	a_adch;			/* adresse 1er ch */
long    a_adsc;			/* adresse 1er s/ch */
long	a_admc;			/* adresse 1er mot cle */
long    a_adt1;			/* adresse 1er texte */

/*FILE*	sa_ptf= (FILE*) NULL;*/	/* structure fichier aide */

sa_desc ae;			/* entete du fichier */
mc_desc mc_buf;			/* mot-cle en cours  */
sa_scdesc sc_buf;		/* sous-chapitre     */
sa_chdesc ch_buf;		/* chapitre */

char a_mcd[MC_LGN+1] = "";	/* mot-cle par defaut */


/*********************************
* variables globales externes    *
*********************************/

extern	EVENT_STR event;
extern  GLOBAL BDA_ARG rt_arg; 

#define HELP_EVENTS	KEYBOARD+MOUSE_UP	/*+MOUSE_DOWN+MOUSE_M_W_DOWN+MOUSE_IS_DOWN */

/*******************************************************************
* conversion des pointeurs prologue en pointeurs longs dans fichier
********************************************************************/
long convadf(pt_prl)

	BYTE * pt_prl;
{
	long res;

	res = *(pt_prl);
	res = res << 8;
	res += *(pt_prl+1);
	res = res << 8;
	res += *(pt_prl+2);
	res = res << 8;
	res += *(pt_prl+3);

	return(res);
}

/**********************************************
* Activation de l'aide
***********************************************/
TYPF	sa_activ(tf,nomf)
	BYTE tf;
	BPTR nomf;
{


/* variables externes */
	extern BYTE fen_ini;
	extern sa_desc ae;
	extern BYTE tc[MAX_TOUCHES];
	extern BYTE sa_touche;

	extern char sa_mcled[8];
	extern FILE* sa_ptf;

	extern	long a_adch;
	extern	long a_adsc;
	extern	long a_admc;
	extern	long a_adt1;


/* variables internes */
	char nomfic[128];
	WORD sa_er;
	int i,j,k;
	char mode[3] ;
	BYTE	*tampon;
	WORD lg_fic;

/* corps de la fonction */
	if (fen_ini != 2) return(werr_ini);
	if (sa_ptf != (FILE *) NULL) return(werr_exist);

	if(rt_arg.t[1] != TYPE_CHAINE)
	       return(RT_err_typ);
	if(rt_arg.l[1] > 128)
	     return(werr_desc);

	lg_fic = rt_arg.l[1];
	/* compatibilite avec les anciens programmes C (casfun.obj */
	if (( lg_fic == 2)&&(nomf[2] != ' '))
		lg_fic = 16;

	if (nomf != (BPTR) NULL)
	 {
	   for (i=0;(i < lg_fic) && (nomf[i] != ' ');++i) nomfic[i] = nomf[i];
	   nomfic[i] = EOS;
	}

	mode[0] = 'r'; mode[1] = 'b'; mode[2] = EOS;

#ifndef PROL
#ifdef AVIION
   if (Access(nomfic, R_OK, 0) == -1)
#else
   if (Access(nomfic, R_OK, 0) == -1)
#endif
        return(werr_desc);
#endif

	/* boucle de sortie avec erreur */

	sa_ptf = (FILE *) fopen((char *)nomfic,(char *)mode); 

	if (sa_ptf == (FILE *) NULL)
		return(sferr_inex);

/* llb 11.10.91 */
	if ( (tampon = (BYTE*)malloc(sizeof(ae))) == (BYTE*) NULL )
		return(werr_mem);

	j = fread(tampon, sizeof(ae), 1, sa_ptf);

	if (j < 1) return(werr_desc);
/* remplir la structure … partir du fichier lu */

ae.a_n[0] 	= tampon[0];		/* "stf" */
ae.a_n[1] 	= tampon[1];
ae.a_n[2] 	= tampon[2];

ae.a_vers 	= tampon[3];		/* version*/
ae.a_ind  	= tampon[4];		/*indice */
ae.a_niv  	= tampon[5];		/* niveau */
ae.a_rs1[0] 	= tampon[6];		/* reserve */
ae.a_rs1[1] 	= tampon[7];		/* reserve */

ae.a_ptch[0] 	= tampon[8];		/* pointeur table des chapitres */
ae.a_ptch[1] 	= tampon[9];
ae.a_ptch[2] 	= tampon[10];
ae.a_ptch[3] 	= tampon[11];

ae.a_nbch	= tampon[12];		/* nombre de chapitres */

ae.a_ptsc[0]	= tampon[13];		/* pointeur table des sous-chapitres */
ae.a_ptsc[1]	= tampon[14];
ae.a_ptsc[2]	= tampon[15];
ae.a_ptsc[3]	= tampon[16];

ae.a_nbsc	= tampon[17];		/* nombre de sous-chapitres */

ae.a_ptmc[0]	= tampon[18];		/* pointeur table des mots-cles */
ae.a_ptmc[1]	= tampon[19];
ae.a_ptmc[2]	= tampon[20];
ae.a_ptmc[3]	= tampon[21];

ae.a_nbmc	= (WORD) (tampon[22]*256);	/* nombre de mot-cles */
ae.a_nbmc	+=  (WORD) tampon[23];		/* notation directe dans le fichier */

ae.a_ptt1[0] 	= tampon[24];		/* pointeur premier texte */
ae.a_ptt1[1] 	= tampon[25];
ae.a_ptt1[2] 	= tampon[26];
ae.a_ptt1[3] 	= tampon[27];


ae.a_stfd	= tampon[28];		/* style par defaut */
ae.a_dligd	= tampon[29];		/* ligne debut par defaut */
ae.a_dcold	= tampon[30];		/* colonne debut par defaut */
ae.a_nligd	= tampon[31];		/* nombre lignes par defaut */
ae.a_ncold	= tampon[32];		/* nombre colonnes par defaut */

free(tampon);

/* llb 11.10.91 fin*/

	if ( (ae.a_n[0] != 'a') || (ae.a_n[1] != 'i') || (ae.a_n[2] != 'd') || (ae.a_vers != sa_vers) ) return(werr_desc);


	a_adch = convadf((char *) &(ae.a_ptch[0]));
	a_adsc = convadf((char *) &(ae.a_ptsc[0]));
	a_admc = convadf((char *) &(ae.a_ptmc[0]));
	a_adt1 = convadf((char *) &(ae.a_ptt1[0]));

	if (tf != 0)
		sa_touche = tf;
	else
		sa_touche = tc[T_AIDE - 1];

	return(OK);
}

/**********************************************
* Desactivation de l'aide
***********************************************/
TYPF	sa_desac()
{


/* variables externes */
	extern BYTE sa_touche;
	extern FILE* sa_ptf;

/* variables internes */
	int j;



/* corps de la fonction */

	if (sa_ptf == (FILE *) NULL) return(sferr_inex);

	j = fclose(sa_ptf);

	if (j < 0) return(sferr_inex);

	sa_ptf = (FILE *) NULL;

	sa_touche = 0;

	return(OK);
}


/***************************************************
* affichage de la liste des chapitres/sous-chapitres
****************************************************/

TYPF sa_afch(pt_chpos,pt_scpos,niv)
WPTR pt_chpos;			/* pointeur positionne */
WPTR pt_scpos;			/* pointeur positionne */
BYTE niv;			/* 1= chapitre 2= sous-chapitre */
{
/* fonctions appelees */

TYPF	ld_creatc();
TYPF	le_creatc();
TYPF	ld_close();
TYPF	ld_choixc();
TYPF	ld_sup();

/* variables externes */

extern sa_desc ae;
extern FILE* sa_ptf;
extern	ld_tab	ld[MAXLD];
extern long a_adch;
extern long a_adsc;
extern char * tabmes[MAXMES];
extern sa_scdesc sc_buf;
extern sa_chdesc ch_buf;
/* variables internes */

ld_desc ld_ch;
WORD i,j,k;
long pt_fic;
int ai_er;
BYTE sa_ldno;

BYTE ai_typc;
WORD ch_no;
WORD ch_dpg;
WORD ch_pos;
WORD sc_pos;
WORD sc_no;
WORD maxel;
char * ptit;		/* pointeur sur titre */
BYTE *tampon;
BYTE codret;		/* param "exit" sur appel md_choixc */
WORD zero;

/* debut fonction */

if (sa_ptf == NULL) return(sferr_inex);

if (ae.a_nbch == 0) return(sferr_inex);

if ((niv == 0) || (niv > 2)) return(werr_desc);

/* recherche si liste libre */

sa_ldno = MAXLD-1;
while ((sa_ldno > 0) && (ld[sa_ldno].l_nofen !=0)) --sa_ldno;

if (sa_ldno == 0) return(werr_max);


/* definition de la liste des chapitres */

ld_ch.ld_stlf = ae.a_stfd;
ld_ch.ld_plig = ae.a_dligd;
ld_ch.ld_pcol = ae.a_dcold;
ld_ch.ld_nlig = ae.a_nligd;
ld_ch.ld_typa = 2;
ld_ch.ld_typd = 2;
ld_ch.ld_nelh = 1;
ld_ch.ld_pscrol = 1;
ld_ch.ld_cadre = 1;
ld_ch.ld_lcom = 0;
for (i=0;i<32;++i) ld_ch.ld_titr[i] = ' ';
i = 0;

/* definition chapitres ou sous-chapitres */
ch_pos = *pt_chpos;
sc_pos = *pt_scpos;

if (niv == 1)
  {
	ld_ch.ld_lel = CH_LGN + 4;
	ld_ch.ld_laff = CH_LGN;
	maxel = ae.a_nbch;
	ptit = tabmes [MESAIC];
	pt_fic = a_adch;
  }
else
  {
	ld_ch.ld_lel = SC_LGN + 6;
	ld_ch.ld_laff = SC_LGN;
	ptit = tabmes[MESAIS];
	if (ch_buf.a_chch1 != ch_pos) /* restauration du chapitre */
	{
		pt_fic = a_adch;
		pt_fic += (*pt_chpos-1)*sizeof(sa_chdesc);
		ai_er = fseek(sa_ptf,pt_fic,SEEK_SET);

		/* llb 11.10.91 */
		if ( (tampon = (BYTE*)malloc(sizeof(sa_chdesc))) == (BYTE*) NULL ) 
			return(werr_mem);
		
		ai_er = fread( tampon , sizeof(sa_chdesc), 1 , sa_ptf);

		for ( i = 0 ; i < CH_LGN ; i++ )
			ch_buf.a_chnom[i] = tampon[i];		/* nom de chapitre */
		ch_buf.a_chch1	= tampon[CH_LGN];		/* no de chapitre */
		ch_buf.a_chsc1	= tampon[CH_LGN+1];		/* no 1er sous chapitre */
		ch_buf.a_chrs1[0] = tampon[CH_LGN+2];		/* reserve usage ulterieur */
		ch_buf.a_chrs1[1] = tampon[CH_LGN+3];	
		
		free(tampon);
		/* llb fin */
	};

	maxel = ae.a_nbsc - ch_buf.a_chsc1+1;

	pt_fic = a_adsc;
	if (*pt_scpos > 0) pt_fic += (ch_buf.a_chsc1-1)*sizeof(sa_scdesc);
   };
  i = 0;
  while (*ptit != EOS) ld_ch.ld_titr[i++] = *ptit++;

ld_ch.ld_mxel = maxel;

/* llb 04.06.93 type = 2 -> 1 */
ai_er = ld_creatc(sa_ldno,(ld_desc_ptr) &(ld_ch.ld_stlf),0,0,NULL);

if (ai_er) return(ai_er);

/* insertion des elements dans la liste */

ai_typc = 3;			/* n'inserer que si demande */
ch_no = 0;			/*!060990 */
ch_dpg = 1;
ch_pos = *pt_chpos;
sc_pos = *pt_scpos + ch_buf.a_chsc1 ;
sc_no = *pt_scpos;

ai_er = fseek(sa_ptf,pt_fic,SEEK_SET);

/* chargement des ‚l‚ments en 1 seule fois (modif du 25/09/90) */

while (ch_no < maxel)
  {
	if (niv == 1)
	{
		/* llb 11.10.91 */
		if ( (tampon = (BYTE*)malloc(sizeof(sa_chdesc))) == (BYTE*) NULL ) 
			return(werr_mem);
		ai_er = fread(tampon, sizeof(sa_chdesc), 1, sa_ptf);
		if (ai_er == 0) return(werr_desc);

		for ( i = 0 ; i < CH_LGN ; i++ )
			ch_buf.a_chnom[i] = tampon[i];		/* nom de chapitre */
		ch_buf.a_chch1	= tampon[CH_LGN];		/* no de chapitre */
		ch_buf.a_chsc1	= tampon[CH_LGN+1];		/* no 1er sous chapitre */
		ch_buf.a_chrs1[0] = tampon[CH_LGN+2];		/* reserve usage ulterieur */
		ch_buf.a_chrs1[1] = tampon[CH_LGN+3];	
		free(tampon);
		/* llb fin */
		zero = 0;
		ai_er = le_creatc(sa_ldno,(WPTR) &zero,1,2,(BPTR) &(ch_buf.a_chnom[0]),(BPTR) NULL);
		ch_no++;
	}/*niv = 1*/

	else
	   {
		/* llb 11.10.91 */
		if ( (tampon = (BYTE*)malloc(sizeof(sa_scdesc))) == (BYTE*) NULL ) 
			return(werr_mem);
		ai_er = fread(tampon, sizeof(sa_chdesc), 1, sa_ptf);
		if (ai_er == 0) return(werr_desc);

		for ( i = 0 ; i < SC_LGN ; i++ )
			sc_buf.a_scnom[i] = tampon[i];		/*  nom de sous-chapitre */
		sc_buf.a_scch1  = tampon[SC_LGN];		/* no du chapitre        */
		sc_buf.a_scsc1  = tampon[SC_LGN+1];		/* no de sous-chapitre   */
		sc_buf.a_scadt[0] = tampon[SC_LGN+2];	/*  adresse texte        */
		sc_buf.a_scadt[1] = tampon[SC_LGN+3];
		sc_buf.a_scadt[2] = tampon[SC_LGN+4];
		sc_buf.a_scadt[3] = tampon[SC_LGN+5];
		free(tampon);
		

		ai_er = 0;

		if ( sc_buf.a_scch1 == ch_pos)
		  {
			zero = 0;
			ai_er = le_creatc(sa_ldno,(WPTR) &zero,1,2,(BPTR) &(sc_buf.a_scnom[0]),(BPTR) NULL);
			ch_no++;
		}
		else
			ch_no = maxel;
	    };
   };

if (ai_er) return (ai_er);

ai_er = ld_close(sa_ldno);


/* demande de choix utilisateur */

if (niv == 1)
    {
 	ch_dpg = (ch_pos <= ld_ch.ld_nlig)? 1:ch_pos;

	ai_er = ld_choixc(sa_ldno,(WPTR)&ch_dpg,(WPTR)&ch_pos,(BPTR) &ai_typc,(BPTR) &(ch_buf.a_chnom[0]), (BPTR) &codret);

    }
else
    {
 	ch_dpg = (sc_no <= ld_ch.ld_nlig)? 1:sc_no;

	ai_er = ld_choixc(sa_ldno,(WPTR)&ch_dpg,(WPTR)&sc_no,(BPTR) &ai_typc,(BPTR) &(sc_buf.a_scnom[0]),(BPTR) &codret);

    };

if (ai_er) return(ai_er);

/* choix effectue */
ld_sup(sa_ldno);

if (niv == 1)
   {
	if (ai_typc == 1)
		{
		  *(pt_chpos) = ch_pos;		/* positionnement chapitre */
		  *(pt_scpos) = 1;              /* sous-chap par defaut */
		}
	else
		{
		  *(pt_chpos) = (ai_typc == 4)? ch_pos: 0;

		  *(pt_scpos) = 0;
		};
   }
else
   {
	if (ai_typc == 1)
		{
		  *(pt_scpos) = sc_no;		/* positionnement sous-chapitre */
		}
	else
		{
		  *(pt_scpos) = 0;		/* aide generale */
		  if (ai_typc != 4) *(pt_chpos) = 0; /* sortie */
		};
   }

return(ai_er);

}

/****************************************************
* aide generale depuis un chapitre ou sous-chapitre *
*****************************************************/
TYPF sa_aidg(pt_chpos,pt_scpos)

WPTR pt_chpos;		/* chapitre positionne ou 0 */
WPTR pt_scpos;		/* sous-chapitre positionne ou 0 */

{
/* fonctions appelees */

TYPF	sa_afch();

/* variables externes */
extern FILE * sa_ptf;
extern sa_desc ae;

/* variables internes */

WORD i,j,k;
int ai_er;
WORD ch_no, sc_no;

/* debut fonction */

if (sa_ptf == NULL) return(sferr_inex);

if (ae.a_nbch == 0) return(sferr_inex);
if (ae.a_nbsc == 0) return(sferr_inex);

if (*pt_chpos > ae.a_nbch) return(werr_desc);
if (*pt_scpos > ae.a_nbsc) return(werr_desc);

ch_no = *pt_chpos;
sc_no = *pt_scpos;

if ( (sc_no != 0) && (ch_no != 0) )
	  {
/* choix du sous-chapitre */
		ai_er = sa_afch( (WPTR) &ch_no, (WPTR) &sc_no , 2);
		if (ai_er) return(ai_er);
	  };


/* if (ch_no == 0) ch_no = 1; */	/* modif du 26/07/90 */

/* positionnement sur un chapitre */

	while ((sc_no == 0) && (ch_no != 0))
	{
	if (sc_no == 0)
	  {
/* choix du chapitre */
		ai_er = sa_afch( (WPTR) &ch_no , (WPTR) &sc_no , 1);
		if (ai_er) return(ai_er);

	   };

	if ( (sc_no != 0) && (ch_no != 0) )
	  {
/* choix du sous-chapitre */
		ai_er = sa_afch( (WPTR) &ch_no, (WPTR) &sc_no , 2);
		if (ai_er) return(ai_er);
	  };
	};

*pt_chpos = ch_no;
*pt_scpos = sc_no;

return(OK);

}

/**************************************************
* comparaison sur 8 octets par rapport au mot-cle
**************************************************/
int comp8(pt_mcle,noel)
BPTR pt_mcle;
int  noel;
{
/* variables externes */
extern FILE* sa_ptf;
extern long a_admc;
extern mc_desc mc_buf;

/* variables internes */
long pt_fic;
int ret;
int i;
BYTE	*tampon;

/* debut de fonction */

/* lecture de l'element */
pt_fic = a_admc + (sizeof(mc_desc)*(noel-1));
ret = fseek(sa_ptf,pt_fic,SEEK_SET);

/* llb 11.10.91 */
if ( (tampon = (BYTE*)malloc(sizeof(mc_desc))) == (BYTE*) NULL ) 
	return(werr_mem);

ret = fread( tampon , sizeof(mc_desc), 1 , sa_ptf);
if (ret == 0) return(0);

for ( i = 0 ; i < MC_LGN ; i++ )
	mc_buf.a_mcnom[i] = tampon[i];		/*  mot-cle              */
mc_buf.a_mcch1    = tampon[MC_LGN];		/* no du chapitre        */
mc_buf.a_mcsc1    = tampon[MC_LGN+1];		/* no du sous-chapitre   */
mc_buf.a_mcadt[0] = tampon[MC_LGN+2];		/*  adresse 1er texte    */
mc_buf.a_mcadt[1] = tampon[MC_LGN+3];
mc_buf.a_mcadt[2] = tampon[MC_LGN+4];
mc_buf.a_mcadt[3] = tampon[MC_LGN+5];
mc_buf.a_mcrsc1[0] = tampon[MC_LGN+6];		/* reserve               */
mc_buf.a_mcrsc1[1] = tampon[MC_LGN+7];
free(tampon);
/*llb fin */
/* comparaison */


for (i= 0;( (ret == 1) && (i < MC_LGN) );++i)
  {
	if ( *(pt_mcle+i) < mc_buf.a_mcnom[i] )
		ret = 2;
	else
		if ( *(pt_mcle+i) > mc_buf.a_mcnom[i] )
			ret = 3;
   };
return(ret);
}

/*************************
* aide sur un texte      *
*************************/
TYPF sa_aidt(pt_txt)

	long pt_txt;
{
/* variables externes */

extern FILE* sa_ptf;
extern long a_adch;
extern long a_adsc;
extern long a_adt1;
extern long a_admc;
extern mc_desc mc_buf;
extern sa_scdesc sc_buf;
extern BYTE sa_touche;

extern stf_desc stf[MAXSTF+1];
extern stc_desc stc[MAXSTC];
extern BYTE tc[MAX_TOUCHES];
extern char * tabmes[MAXMES];
extern BYTE tb_style[MAXSTF];

/* variables internes */

WORD i,j,k;

long pt_fic;
int ai_er;

WORD ch_no;
WORD sc_no;
BYTE mc_nom[MC_LGN];
BYTE stf_no;		/* reserve style de fenetre */

int ret;
WORD lg_txt;
WORD lg_lu;
WDESC_APP ftx;
stf_desc * syf;
WORD nftx;		/* fenetre d'aide */

char tx_buf[256];
sa_entxt en_buf;

BYTE touche;
BYTE val;
BYTE sens;
BYTE * tampon;
WORD o;

/* debut fonction */


pt_fic = NULL;
nftx = 0;
stf_no = 0;
lg_txt = 0;

ftx.Amere_nbr = 0;
ftx.Apos_lig = 2;
ftx.Apos_col = 40;
ftx.Anb_lig = 22;
ftx.Anb_col = 38;

while (TRUE)
 {

   if (pt_fic != pt_txt)

/* chargement du nouveau texte */
     {
	pt_fic = pt_txt;


	/* lecture de l'entete */

	ret = fseek(sa_ptf,pt_fic,SEEK_SET);
/* llb 11.10.91 */
	if ( (tampon = (BYTE*)malloc(sizeof(sa_entxt))) == (BYTE*) NULL ) 
		return(werr_mem);

	ret = fread( tampon , sizeof(sa_entxt), 1 , sa_ptf);
	if (ret == 0) return(sferr_inex);

	for ( i = 0; i < MC_LGN; i++ )
		en_buf.a_ennom[i] = tampon[i];	/*  mot-cle              */

	en_buf.a_ennpg = tampon[MC_LGN];	/* numero de page        */
	en_buf.a_ench1 = tampon[MC_LGN+1];	/* numero de chapitre    */
	en_buf.a_ensc1 = tampon[MC_LGN+2];	/* numero de sous-chap   */

	en_buf.a_stf  = tampon[MC_LGN+3];	/* style                 */
	en_buf.a_nlig = tampon[MC_LGN+4];	/* nombre lignes         */
	en_buf.a_ncol = tampon[MC_LGN+5];	/* nombre colonnes       */
	en_buf.a_dlig = tampon[MC_LGN+6];	/* ligne debut           */
	en_buf.a_dcol = tampon[MC_LGN+7];	/* colonne debut         */

	en_buf.a_lgtxt = (WORD) tampon[MC_LGN+9];	/* longueur du texte     */
	en_buf.a_lgtxt +=(WORD) (tampon[MC_LGN+8]*256);

	for ( i = 0; i < 4; i++ )
		en_buf.a_pttxs[i] = tampon[i+10+MC_LGN]; /* pointeur texte suiv   */
	for ( i = 0; i < 4; i++ )
		en_buf.a_pttxp[i] = tampon[i+14+MC_LGN]; /* pointeur texte prec   */
	for ( i = 0; i < 4; i++ )
		en_buf.a_ptmcs[i] = tampon[i+18+MC_LGN]; /* pointeur texte mot-cle suiv   */
	for ( i = 0; i < 4; i++ )
		en_buf.a_ptmcp[i] = tampon[i+22+MC_LGN]; /* pointeur texte mot-cle prec   */

	free(tampon);
/*llb fin*/

	lg_txt = en_buf.a_lgtxt;

	/* sauvegarde des valeurs de reference */

	ch_no = en_buf.a_ench1;
	sc_no = en_buf.a_ensc1;
	for (i=0;i<MC_LGN;++i) mc_nom[i] = en_buf.a_ennom[i];


	/* creation de la fenetre */
	if ( (nftx == 0) || (ftx.Apos_lig != en_buf.a_dlig) || (ftx.Apos_col != en_buf.a_dcol) || (ftx.Anb_lig != en_buf.a_nlig) || (ftx.Anb_col != en_buf.a_ncol) || (stf_no != en_buf.a_stf) )

	  {
	   if (nftx != 0) wsup(nftx);

	   ftx.Apos_lig = en_buf.a_dlig;
	   ftx.Apos_col = en_buf.a_dcol;
	   ftx.Anb_lig = en_buf.a_nlig;
	   ftx.Anb_col = en_buf.a_ncol;
	   stf_no = en_buf.a_stf;
	   ai_er = swcreatc((WPTR)&nftx, ftx.Apos_lig, ftx.Apos_col,
			    ftx.Anb_lig,ftx.Anb_col, stf_no,INVISIBLE,(BPTR)tabmes[MESAID]);
	   if (ai_er) return(ai_er);
	   }
	else
		wfgen(nftx,CLFUN);

/* chargement et affichage du texte */
	while (lg_txt > 0)
	  {
		lg_lu = (lg_txt < 256) ? lg_txt : 256 ;
		ret = fread( &(tx_buf[0]) , 1 , lg_lu , sa_ptf);
		ai_er = wwrite( nftx , ret , (BPTR) &(tx_buf[0]) );
		lg_txt -= lg_lu;
	  };
    };

     /* fin de chargement du texte */

  /* demande de saisie */

  wselect(nftx);
  wvis(nftx);

/* mise en attente d'un evenement */

put_item_mouse_list(nftx);

Wkup_in();


while ( TRUE)
  {
    if(event.event == NO_EVENT)
	wait_eventc(HELP_EVENTS, (EVENT_PTR)&event);

    if(event.event != KEYBOARD)
     if((get_item_mouse_list(event.plig, event.pcol)) == nftx)
	 {
	   /* si event la fenetre d'aide  on l'ignore */
	  event.event = NO_EVENT;
	  continue;
	}
	else
	  {
	  touche = 27;
	  break;
	}
     else
       {
	touche = event.arg;
	event.event = NO_EVENT;
	break;
     }
  }/*while*/


del_item_mouse_list(nftx);

  if (touche == sa_touche)
    val = T_AIDE;
  else
    for (i=0,val=0;(i<MAX_TOUCHES) && (val == 0);++i) if (tc[i] == touche) val = i+1;

  switch(val)
    {
	/* curseur bas = page suivante meme mot-cle */
	case F_BAS:
		pt_txt = convadf(&(en_buf.a_pttxs[0]));
		sens = 2;
		if (pt_txt == NULL) pt_txt = pt_fic;
		break;

	/* curseur haut = page precedente meme mot-cle */
	case F_HAUT:
		pt_txt = convadf(&(en_buf.a_pttxp[0]));
		sens = 3;
		if (pt_txt == NULL) pt_txt = pt_fic;
		break;

	/* page bas = mot-cle suivant */
	case PG_DOWN:
		pt_txt = convadf(&(en_buf.a_ptmcs[0]));
		sens = 4;
		if (pt_txt == NULL) pt_txt = pt_fic;
		break;

	/* page haut = mot-cle precedent */
	case PG_UP:
		pt_txt = convadf(&(en_buf.a_ptmcp[0]));
		sens = 5;
		if (pt_txt == NULL) pt_txt = pt_fic;
		break;

	/* aide */
	case T_AIDE:

		wsup(nftx);
		nftx = 0;
		ai_er = sa_aidg( (WPTR) &ch_no , (WPTR) &sc_no);
		if (ai_er) 
		  {
		    Wkup_out();
		    return(OK);
		}
		if ((ch_no == 0) || (sc_no == 0)) 
		  {
			Wkup_out();
			return(OK);
		}
		pt_txt = convadf(&(sc_buf.a_scadt[0]));
		pt_fic = 0;
		sens = 0;
		break;

/* abandon */
	case T_ESC:

		wsup(nftx);
		nftx = 0;
		pt_fic = 0;
		Wkup_out();
		return(OK);

/* autre touche */
	default:

		pt_txt = pt_fic;
		break;
   };


/* traitement au niveau des mots-cles */
if ( (pt_txt != NULL) && (pt_txt != pt_fic) )
   {
	/* verification precedent ou suivant existe */
	ret = fseek(sa_ptf,pt_txt,SEEK_SET);

/* llb 11.10.91 */
	if ( (tampon = (BYTE*)malloc(sizeof(sa_entxt))) == (BYTE*) NULL )
	   {
		Wkup_out();
		return(werr_mem);
	}
	ret = fread( tampon , sizeof(sa_entxt), 1 , sa_ptf);
	if (ret != 0)
	{

		for ( i = 0; i < MC_LGN; i++ )
			en_buf.a_ennom[i] = tampon[i];	/*  mot-cle              */

		en_buf.a_ennpg = tampon[MC_LGN];	/* numero de page        */
		en_buf.a_ench1 = tampon[MC_LGN+1];	/* numero de chapitre    */
		en_buf.a_ensc1 = tampon[MC_LGN+2];	/* numero de sous-chap   */

		en_buf.a_stf  = tampon[MC_LGN+3];	/* style                 */
		en_buf.a_nlig = tampon[MC_LGN+4];	/* nombre lignes         */
		en_buf.a_ncol = tampon[MC_LGN+5];	/* nombre colonnes       */
		en_buf.a_dlig = tampon[MC_LGN+6];	/* ligne debut           */
		en_buf.a_dcol = tampon[MC_LGN+7];	/* colonne debut         */
	
		en_buf.a_lgtxt = (WORD) tampon[MC_LGN+9];	/* longueur du texte     */
		en_buf.a_lgtxt +=(WORD) (tampon[MC_LGN+8]*256); /* notation directe dans le fichier */

		for ( i = 0; i < 4; i++ )
			en_buf.a_pttxs[i] = tampon[i+10+MC_LGN]; /* pointeur texte suiv   */
		for ( i = 0; i < 4; i++ )
			en_buf.a_pttxp[i] = tampon[i+14+MC_LGN]; /* pointeur texte prec   */
		for ( i = 0; i < 4; i++ )
			en_buf.a_ptmcs[i] = tampon[i+18+MC_LGN]; /* pointeur texte mot-cle suiv   */
		for ( i = 0; i < 4; i++ )
			en_buf.a_ptmcp[i] = tampon[i+22+MC_LGN]; /* pointeur texte mot-cle prec   */

		free(tampon);
	/*llb fin*/


		if ( (sens == 2) || (sens == 3) )
		{
		/* recherche si meme mot cle */
			i = 0;
			while  ((i < MC_LGN) && (en_buf.a_ennom[i] == mc_nom[i])) ++i;
			if (i < MC_LGN) ret = 0;
		};

		if ((sens == 4) || (sens == 5))
		{
		/* verification meme chap */
			i = 0;
			while  ((i < MC_LGN) && (en_buf.a_ennom[i] == mc_nom[i])) ++i;
			if ( (i == MC_LGN) || (en_buf.a_ensc1 != sc_no) || (en_buf.a_ench1 != ch_no)) ret = 0; /* plus de mot-cle */
 	        };

	} /* (ret != 0) */
	else {		/* si anomalie restitution de l'entete en cours */

		ret = fseek(sa_ptf,pt_fic,SEEK_SET);
		/* llb 11.10.91 */
		if ( (tampon = (BYTE*)malloc(sizeof(sa_entxt))) == (BYTE*) NULL ) 
		   {
			Wkup_out();
			return(werr_mem);
		}
		ret = fread( tampon , sizeof(sa_entxt), 1 , sa_ptf);

		for ( i = 0; i < MC_LGN; i++ )
			en_buf.a_ennom[i] = tampon[i];	/*  mot-cle              */

		en_buf.a_ennpg = tampon[MC_LGN];	/* numero de page        */
		en_buf.a_ench1 = tampon[MC_LGN+1];	/* numero de chapitre    */
		en_buf.a_ensc1 = tampon[MC_LGN+2];	/* numero de sous-chap   */

		en_buf.a_stf  = tampon[MC_LGN+3];	/* style                 */
		en_buf.a_nlig = tampon[MC_LGN+4];	/* nombre lignes         */
		en_buf.a_ncol = tampon[MC_LGN+5];	/* nombre colonnes       */
		en_buf.a_dlig = tampon[MC_LGN+6];	/* ligne debut           */
		en_buf.a_dcol = tampon[MC_LGN+7];	/* colonne debut         */
	
		en_buf.a_lgtxt = (WORD) tampon[MC_LGN+8];	/* longueur du texte     */
		en_buf.a_lgtxt +=(WORD) (tampon[MC_LGN+9]*256);

		for ( i = 0; i < 4; i++ )
			en_buf.a_pttxs[i] = tampon[i+10+MC_LGN]; /* pointeur texte suiv   */
		for ( i = 0; i < 4; i++ )
			en_buf.a_pttxp[i] = tampon[i+14+MC_LGN]; /* pointeur texte prec   */
		for ( i = 0; i < 4; i++ )
			en_buf.a_ptmcs[i] = tampon[i+18+MC_LGN]; /* pointeur texte mot-cle suiv   */
		for ( i = 0; i < 4; i++ )
			en_buf.a_ptmcp[i] = tampon[i+22+MC_LGN]; /* pointeur texte mot-cle prec   */

		free(tampon);
	/*llb fin*/

		ret = fread(&(en_buf.a_ennom[0]),sizeof(sa_entxt),1,sa_ptf);

		pt_txt = pt_fic;
	};

    };		/* fin du pt_txt  diff de zero */

  }; 		/* fin du while pt_txt diff de NULL */

}


/********************
* aide sur un mot-cle
*********************/

TYPF sa_aid(pt_mcle)

BPTR pt_mcle;		/* pointeur sur un mot-cle */
{
/* fonctions appelees */




TYPF	sa_aidg();
TYPF 	sa_aidt();

/* variables externes */
extern sa_desc ae;
extern FILE* sa_ptf;
extern long a_adch;
extern long a_adsc;
extern long a_adt1;
extern long a_admc;
extern mc_desc mc_buf;
extern sa_scdesc sc_buf;
extern char a_mcd[MC_LGN+1];

/* variables internes */

WORD i,j,k;
long pt_fic;
int ai_er;
WORD ch_no;
WORD sc_no;
int pel,del,mel;		/* pour dichotomie */
long pt_txt;
BYTE test;			/* test de comparaison */



/* debut fonction */

if (sa_ptf == NULL) return(sferr_inex);

if (pt_mcle == (BPTR) NULL) pt_mcle = (BPTR) a_mcd;

test = 0;

if (*pt_mcle != EOS)
  {
/* test si inferieur au premier mot-cle */

	test = comp8(pt_mcle,1);
	if (test == 2)  test = 0;

	if (test != 1)
/* test si superieur au dernier mot-cle */
	{
	 del = ae.a_nbmc;
	 test = comp8(pt_mcle,del);
	 if (test == 3) test = 0;
	}
/* dichotomie */
	if (test != 1)
	{
	 pel = 1;
	 del = ae.a_nbmc;

	 while (test > 1)
	   {
		mel = (pel + del) / 2;
		if ( (mel == pel) || (mel == del)) break;	/* non trouve */
		test = comp8(pt_mcle,mel);
		if (test < 2) break;

		if (test == 2)
			del = mel;
		else
			pel = mel;
	   };
	};
   };

 if (test == 1)
  {
/* mot-cle trouve */
	pt_txt = convadf(&(mc_buf.a_mcadt[0]));
  }

else

  {
/* pas de mot-cle */
	ch_no = 1;
	sc_no = 0;

	ai_er = sa_aidg( (WPTR) &ch_no , (WPTR) &sc_no);
	if (ch_no == 0) return(OK);
	pt_txt = convadf(&(sc_buf.a_scadt[0]));

   };

   ai_er = sa_aidt (pt_txt);
   return(ai_er);
}


TYPF sa_aiddef(mcdef)
	BPTR mcdef;
{
	extern char a_mcd[MC_LGN+1];



	int i;

	for (i=0;i<MC_LGN;++i)
	  {
	   if (mcdef[i] != EOS)
		 a_mcd[i] = mcdef[i];
	   else
		 for (;i<MC_LGN;++i) a_mcd[i] = ' ';
	   };
	return(OK);
}

/* fin du source */
