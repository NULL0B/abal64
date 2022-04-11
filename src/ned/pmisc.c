#include "prl.h"
#include <stdlib.h>
#include <string.h>
#include "def.h"
#define MOINS_UN -1
#ifdef small
#define XPTR *
#define FPTR *
#else
#define XPTR *
#define FPTR far *
#endif

#define EOSTR 0
#define LGREP 50
#pragma pack(1)
typedef struct {
	_PRL_RESS 	num;
	BYTE		blanc;
	VOID  far 	*off;
	BINAIRE		lg;
	BYTE		nom[8];
	BYTE		ext[3];
	BINAIRE		entree;
	BYTE		sel;

} _PRL_FIND;
#pragma pack()

#pragma pack(1)
typedef struct {
	BYTE		fic[8];
	BYTE		suf[3];
	SWORD		n_entree;
	BYTE		buf[6];
	BYTE		typ;
	BYTE		buf1[3];
} _PRL_RETFIND;
#pragma pack()

       BYTE path[70];
       BYTE nom[70];
       _PRL_FIND PRL_ffile;
       BYTE tmp[70];

       SWORD	 num;
       _PRL_MEMO pmemo;
       _PRL_RESS nume;
       _PRL_PPOS pppos;
       _PRL_ANFC desc;


       _PRL_RETFIND rfile;


 SWORD   resultat;
union REGS rgistre;

#pragma pack(1)
typedef struct{  /* descripteur MF fenetre */
    BINAIRE  mere_nbr;
    BINAIRE extend;	
    BINAIRE Fpos_lig;
    BINAIRE Fpos_col;
    BINAIRE Fnb_lig;
    BINAIRE Fnb_col;
    BINAIRE Vpos_lig;
    BINAIRE Vpos_col;
    BINAIRE Vnb_lig;
    BINAIRE Vnb_col;
    BINAIRE bas_atb;		/* attribut  fenetre */
    BINAIRE tit_atb;		/* atb titre si fenetre en Avant plan   */
    BINAIRE cad_atb;		/* attribut cadre 			*/
} WDESC;
#pragma pack()

#pragma pack(1)
typedef struct{
 BINAIRE no_f;
 SWORD atb_f;
 SWORD atb_t;
 SWORD atb_c;
} WATBDESC;
#pragma pack()

#pragma pack(1)
typedef struct{
 BINAIRE no_f;
 VOID far *off_desc;
 SWORD lg_recep;
} W_ETAT;
#pragma pack()

#pragma pack(1)
typedef struct{
 BYTE  car;
 BINAIRE  atb;
} W_SET_FILLER;
#pragma pack()

WDESC fdesc;         /* descripteur fenetre pour multifenetrage */
WATBDESC fatbdesc;   /* descripteur atribut fenetre		*/


#define Xstrcat(s,p) strcat( (char *) s, (char *) p)
#define Xstrchr(s,c) strchr((char *) s, (char) c)
#define Xstrcmp(s,p) strcmp( (char *) s,  (char *) p)
#define Xstrncmp(s,p,n) strncmp( (char *) s, (char *) p, (int) n)
#define Xstrcpy(d,s) strcpy( (char *) d, (char * ) s)
#define Xstrlen(s) strlen( (char * ) s)
#define Xstrrchr(s,c) strrchr( (char *) s, (char) c)


/* Proto des fonctions */
#ifdef LINT_ARGS
/*global*/ SWORD Xchdir(BYTE XPTR);  
/*global*/ VOID GetReper(BYTE XPTR , BINAIRE);
/*global*/ SWORD FindFile(BYTE XPTR, BYTE XPTR);
/*global*/ SWORD FindRep(BYTE XPTR, BYTE XPTR);
/*global*/ SWORD NextFile(BYTE XPTR);
/*global*/ SWORD NextRep(BYTE XPTR);
/*global*/ SWORD FiFile(BYTE XPTR, BYTE XPTR, BYTE);
/*global*/ SWORD PRL_NFile(BYTE XPTR);
/*global*/ VOID analyse(BYTE XPTR, BYTE XPTR, SWORD);
/*global*/ SWORD IsRessource(BYTE XPTR);
/*global*/ VOID Abort(VOID);
/*global*/ SWORD w_conf(BINAIRE);
/*global*/ SWORD wetat(VOID);
/*global*/ VOID  x_set_filler(BINAIRE);
extern BINAIRE fn_parser(BYTE FPTR, BYTE FPTR, BINAIRE);

#else
/*global*/ SWORD Xchdir();  
/*global*/ VOID GetReper();
/*global*/ SWORD FindFile();
/*global*/ SWORD FindRep();
/*global*/ SWORD NextFile();
/*global*/ SWORD NextRep();
/*global*/ SWORD FiFile();
/*global*/ SWORD PRL_NFile();
/*global*/ VOID analyse();
/*global*/ SWORD IsRessource();
/*global*/ VOID Abort();
/*global*/ SWORD w_conf();
/*global*/ SWORD wetat();
/*global*/ VOID  x_set_filler();
extern BINAIRE fn_parser();

#endif

#ifndef unix
#define Xfn_parser(s,d,m) fn_parser(s,d,m | 128) /* Upper case result please */
#else
#define Xfn_parser(s,d,m) fn_parser(s,d,m)
#endif



/***********************/


/*global*/ SWORD Xchdir(BYTE XPTR p)
{
	if (_prl_anfc((BYTE *) p, (_PRL_ANFC XPTR) &desc, (SWORD XPTR) &resultat)) {
		return(-1);
	}
	else {
		_prl_ppos_read(&pppos);	/* lecture des parametres */
		pppos.imp_fic = desc.ress;
		_prl_ppos_write(&pppos);
	}
	return(0);
}

/*global*/ VOID GetReper(BYTE XPTR p, BINAIRE lg)
{

	_prl_ppos_read(&pppos);	/* lecture des parametres */

	nume = pppos.imp_fic;

	rgistre.h.ah = 13;
	rgistre.h.al = 1;
	rgistre.h.dh = nume.no_ress;
	rgistre.h.dl = nume.no_unit;
	rgistre.h.ch = LGREP;
	rgistre.x.bx = (SWORD) p;
	resultat = _prl_call(&rgistre, &rgistre);

	if (rgistre.h.al != 0) {
		_prl_memo(nume.no_ress,&pmemo);
		p[0] = pmemo.mnemo[0];
		p[1] = pmemo.mnemo[1];
		p[2] = (BYTE) (nume.no_unit + '0');
		p[3] = '.';
		p[4] = 0;
	}
	else {
		*(Xstrchr( p,13)) = (BYTE) 0;	/* terminateur C */
	}
}

/*global*/ SWORD FindFile(BYTE XPTR p_ask, BYTE XPTR nom_ret)
{
	return(FiFile(p_ask, nom_ret, 0));
}

/*global*/ SWORD FindRep(BYTE XPTR p_ask, BYTE XPTR nom_ret)
{
	BINAIRE ret;
#ifdef prl2
	return(-1);
#endif

	ret = FiFile(p_ask, nom_ret, (BYTE) 0x40);
	return(ret);
}

/*global*/ SWORD NextFile(BYTE XPTR pt)
{
	BINAIRE ret;
	
	ret = PRL_NFile(pt);
	return(ret);
}

/*global*/ SWORD NextRep(BYTE XPTR pt)
{
	BINAIRE ret;
	
	ret = PRL_NFile(pt);
	return(ret);
}

/*global*/ SWORD FiFile(BYTE XPTR p_ask, BYTE XPTR nom_ret, BYTE typ)
{
	BYTE tmp[LGREP]; 
	BINAIRE i,j;
	

	nom[0] = EOSTR;
	tmp[0] = EOSTR;

	Xfn_parser((BYTE FPTR) p_ask, (BYTE FPTR) nom, 1+2);
	Xfn_parser((BYTE FPTR) p_ask,(BYTE FPTR) tmp,4);

	Xstrcat(nom,tmp);

	j = Xstrlen(nom);
	tmp[0] = EOSTR;
	Xfn_parser((BYTE FPTR) p_ask, (BYTE FPTR) tmp, 8);

	analyse(tmp,(BYTE *) (&(nom[j])),8);

	tmp[0] = EOSTR;

	Xfn_parser((BYTE FPTR) p_ask, (BYTE FPTR) tmp, 16);
	if (tmp[0] == (BYTE) 0) tmp[1] = (BYTE) 0;

	nom[j+8] = '-';

	analyse(&tmp[1], &nom[j + 9], 3); 
	nom[j + 9 + 3] = (BYTE) 0;

	if (_prl_anfc((BYTE *) nom, &desc, &resultat)) {
		return(MOINS_UN);
	}
	else {

		/* Mise en place de la structure d'appel  */		
		
		PRL_ffile.num = desc.ress;
		PRL_ffile.off = (VOID far *) &rfile;

		memcpy(PRL_ffile.nom, desc.nom, 11);

		PRL_ffile.lg  = 23;
		PRL_ffile.sel = typ;
		PRL_ffile.entree = 0; 

		rgistre.h.ah = 0x20;
		rgistre.h.al = 0x54;
		rgistre.x.bx = (SWORD) &PRL_ffile;
		resultat = _prl_call(&rgistre, &rgistre);

		if (rgistre.h.al != 0 && rgistre.h.al != 63) {
			/* erreur */
			return(-1);
		}
		else {
			/* on recopie  le nom trouv‚ */
			i = 0;
			for (j=0; j < 8; j++) {
				if (rfile.fic[j] == ' ') break;
				*(nom_ret + i++) = rfile.fic[j];
			}
			if (rfile.typ == (BYTE) 0) *(nom_ret + i++) = '-';
			for (j=0; j < 3; j++) {
				if (rfile.suf[j] == ' ') break;
				*(nom_ret + i++) = rfile.suf[j];
			}	

			*(nom_ret + i) = (BYTE) 0; /* fin de chaine */

			/* on prepare le prochain accŠs */
			PRL_ffile.entree = rfile.n_entree;
		}
	}
	return(0);
}


/*global*/ SWORD PRL_NFile(BYTE XPTR nom_ret)
{
	BYTE i,j;

	rgistre.h.ah = 0x20;
	rgistre.h.al = 0x54;
	rgistre.x.bx = (SWORD) &PRL_ffile;

	resultat = _prl_call(&rgistre, &rgistre);
	if (rgistre.h.al == 0 || rgistre.h.al == 63) {
		/* on recopie  le nom trouv‚ */
		i = 0;
		for (j=0; j < 8; j++) {
			if (rfile.fic[j] == ' ') break;
			*(nom_ret + i++) = rfile.fic[j];
		}
		if (rfile.typ == (BYTE) 0) *(nom_ret + i++) = '-'; /* c'est un fichier */
		for (j=0; j < 3; j++) {
			if (rfile.suf[j] == ' ') break;
			*(nom_ret + i++) = rfile.suf[j];
		}	
		*(nom_ret + i) = (BYTE) 0; /* fin de chaine */

			/* on prepare le prochain accŠs */
		PRL_ffile.entree = rfile.n_entree;
		return(0);
	}
	else return(-1);
}

/*global*/ VOID analyse(BYTE XPTR pd,BYTE XPTR pr,SWORD  lg)
{
	SWORD i, j, k;

	j = 0;
	i = 0;
	while ((*(pd+i) != '*') && (*(pd+i) != (BYTE) 0)) {
		*(pr+i) = *(pd+i);
		i++;
	}

	k = i;

	if (*(pd+i) == '*') {
		k = (SWORD) (i + 1); /* k sauvegarde la prochaine valeur de pd */

		j = (SWORD) ( lg - (SWORD) Xstrlen((pd+k)));

		/* j = le nombre ? a inserer dans pr */

		for (; i < j; i++) {
			*(pr+i) = '?'; 
		}

		/* i est en avance sur k */

		for (; i < lg; i++) {
			*(pr+i) = *(pd+(k++));
		}

		*(pr+i) = 0;
	}
	if ((*(pd+k) == (BYTE) 0) && (i < lg)) {
		for (; i < lg; i++) {
			*(pr+i) = ' ';
		}
		*(pr+i) = 0;
	}
}


/*global*/ SWORD IsRessource(BYTE XPTR pt)
{
	BINAIRE ret;
	
	/* repond 1 si ressource */
	/*        0 sinon	*/

	ret = _prl_anfc((BYTE XPTR) pt, &desc, &resultat);

	if (resultat != _ANFC_FICHIER) 	return(1);
	else				return(0);
}

/*global*/ VOID Abort()
{
	x_cprintf((BYTE FPTR) nom);
	x_getch();
}

/*global*/ SWORD w_conf( BINAIRE quoi )
 {
	if (wetat()) {                   /* lire caract‚ristique fenetre */
		switch (quoi) {
			case 1:
				/* Nb lignes visibles */
				return(fdesc.Vnb_lig);
				break;
			case 2:
				/* Nb colonnes visibles */	
				return(fdesc.Vnb_col);
				break;
			case 17:
				/* Couleur Texte */
				return((SWORD) (fdesc.bas_atb & 0x000F));
				break;
			case 18:
				/* Couleur fond */	
				return((SWORD) (fdesc.bas_atb & 0x00F0));
				break;

			default:
				break;
		}
	} 
}

/*global*/ SWORD wetat()
{
	W_ETAT ap_etat;

		/* recuperer le numero de la fenetre */
	
		rgistre.h.ah = 0x1d;
		rgistre.h.al = 0x14;
		resultat = _prl_call(&rgistre, &rgistre);

		if (rgistre.h.al != 0 && rgistre.h.al != 63) {
			/* erreur */
			return(0);
		}


		/* on recopie  le num console trouv‚ */

		ap_etat.no_f = rgistre.x.cx;

		ap_etat.off_desc = (VOID far *) &fdesc;
		ap_etat.lg_recep = 26;

		rgistre.h.ah = 0x1d;
		rgistre.h.al = 0x0c;
		rgistre.x.bx = (SWORD) &ap_etat;
		resultat = _prl_call(&rgistre, &rgistre);

		/* recupere le numero console-fenetre */
		fdesc.mere_nbr = rgistre.x.cx;
		if (rgistre.h.al != 0 && rgistre.h.al != 63) {
			/* erreur */
			return(0);
		}
		else {
			/* on recopie  le nom trouv‚ */
			return( 1 );
		} 
}

VOID x_set_filler( coul )
BINAIRE coul;
{
	W_SET_FILLER setatb;

 	setatb.car   = (BYTE) coul & 0x00ff;
	setatb.atb   = (BINAIRE) ((coul & 0xff00) >> 8);

	rgistre.h.ah = 0x1d;
	rgistre.h.al = 0x1d;
	rgistre.x.bx = (SWORD) &setatb;
	resultat = _prl_call(&rgistre, &rgistre);
}

BINAIRE x_get_filler()
{
	W_SET_FILLER setatb;
	BINAIRE ret;

 	setatb.car   = 0;
	setatb.atb   = 0;

	rgistre.h.ah = 0x1d;
	rgistre.h.al = 0x1d;
	rgistre.x.bx = (SWORD) &setatb;
	resultat = _prl_call(&rgistre, &rgistre);

	ret =  (BINAIRE) ((setatb.atb & 0x00ff) << 8);
	
	ret |= setatb.car ;
	return( ret );
}

