#ifndef	_runco_c
#define	_runco_c

/**********************************************
* fichier:	RUNCO.C  UNIX
* description: Emulation print caractere
*	       dans une fenetre sous UNIX
* creation:	18.01.90
* maj		08.03.90
* maj		05.11.92 llb: si (color_impl), 
*		tenir compte couleur fenetre
**********************************************/

#include <stdio.h>
#include "fundef.h"

/* IJM pour LINUX/USE IT 05/10/2001 */
#define _LTS_ESC_X
#define _LTS_ESC_V
#define _LTS_ESC_I
#define _LTS_ESC_R
#define _LTS_ESC_S

#define	_co(a) x_putch(a)

/* variables externes de CICO */

#ifdef AIX_VERS
WORD	prndest;
WORD	prnfid;
WORD	prnleng;
WORD	err_val;
#else  /* AIX_VERS */
WORD prndest, prnfid, prnleng, err_val;
#endif /* AIX_VERS */
BYTE *prnptr;

/* variables externes fenetrages */

extern BYTE fen_ini;				/* flag winit 			*/
extern WORD MAXLIG, MAXCOL;			/* taille ecran			*/
extern WORD SBARCOL, SBARLIG, COULEUR;		/* couleur ecran 		*/
extern WORD fimpl;				/* fenetre implicite 		*/
extern WORD win_coltxt, win_colfon, color_impl;	/* couleurs fenetre		*/

/* fonctions du module	*/

void FAR Run_Co(WORD);				/* emulation Co un caractere 	*/
void FAR Run_Mes( BYTE FAR *mess, WORD lgr ); 	/* emulation co n caracteres 	*/
WORD FAR Run_Conf();				/* emulation de conf	     	*/
WORD FAR Run_Col();				/* position colonne relative 	*/
WORD FAR Run_Lin();				/* position ligne   relative 	*/
void FAR Run_Str();				/* emulation co n caracteres 	*/
void AFICAR();					/* affichage physique 1 car  	*/
WORD emco_ini();				/* init emulation	     	*/
void emco_fin();				/* fin	emulation	     	*/

/* define specifiques */
#define COUL_TXT	1
#define COUL_FOND	2
#define COUL_BAS	3
#define COUL_TXT_ETD	4
#define COUL_FOND_ETD	5
#define	ETAT_IMAGE	6
#define	ETAT_VIDEO	7
#define	ETAT_LABEL	8
#define	UPLOADER	9

#define MIMA		1
#define MAMI		2

//	--------------------------------------------------
//	fonctions fenetres appelees
//	--------------------------------------------------
//	wwrite : ecriture caractere
//	wposcur: positionnement curseur
//	wfgen  : fonctions specifiques d'affichage
//	watb   : positionnement attributs N/B ou couleur
//	winfo  : position et nombre lignes/colonnes
//	--------------------------------------------------

/* fonctions CICO appelees */

extern WORD mima();			/* conversion		*/
extern WORD x_col();			/* position col		*/
extern WORD x_lin();			/* position ligne	*/
extern WORD conf(WORD);			/* configuration	*/
extern void x_bell();			/* sonnette		*/
extern void x_bstart(); 		/* debut bufferisation	*/
extern void x_bflush(); 		/* fin bufferisation	*/
extern void x_cprintf(); 		/* ecriture d'une chaine*/

/* fonctions fenetrage */

extern WORD winfo();

FILE * tHandle=(FILE*)0;

/* structure globale etat console pour emulation */

struct 
{
	BYTE fesc;				/* indicateur escape 	*/
	BYTE fsecret;				/* indic secret 	*/
	WORD fposcur;				/* indic positionnement */
	WORD fcouleur;				/* indic couleur 	*/
	WORD fminmaj;				/* indic conversion m/M */
	WORD ftransp;				/* indic transparent 	*/
	WORD cpt_trans; 			/* compteur transparent */
	WORD atb;				/* attribut monochrome	*/
	WORD coltxt;				/* couleur caractere	*/
	WORD colfond;				/* couleur fond 	*/
	WORD colbas;				/* couleur de base car	*/
	WORD fescesc;				/* flag esc/esc 	*/
	WORD fmask;				/* set mouse mask	*/
	WORD extra;				/* extra ESC bytes	*/
	BYTE bytes[2048];			/* extra bytes storage	*/
} etat_c;

/*	------	*/
/*	Run_Co	*/
/*	------	*/
void FAR Run_Co(WORD car)
{
	WORD c;
	BYTE mes=0;				/* message wwrite */

	/* ensure its a byte */
	car &= 0x00ff;

	/* pas de fenetrage active */
	if ((fen_ini == 0) || (fimpl == 0)) 
	{
		/* traitement normal */
		_co(car);
	}
	else 	
	{
		/* traitement specifique si fenetre implicite */
		if (( etat_c.cpt_trans > 0) && (!(etat_c.ftransp ))) 
		{
			/* transparent en cours */
			--etat_c.cpt_trans;
			_co(car);
		} 
		/* is this an escape character */
		else if (car == ESCAPE) 
		{
			if (etat_c.fesc == FALSE)
				/* passage etat escape */
				etat_c.fesc = TRUE;
			else if ( etat_c.ftransp == FALSE ) 
			{
				/* etat double escape  */
				etat_c.fescesc = TRUE;
			}
			else if (etat_c.ftransp == 1) 
			{
				etat_c.ftransp++;
				etat_c.cpt_trans = (car & 0x00FF);
			}
			else 	
			{
				_co(ESCAPE);
				_co('T');
				_co(etat_c.cpt_trans);
				_co(car);
				etat_c.cpt_trans |= ((car<<8) & 0xFF00);
				etat_c.fesc = 0;
				etat_c.ftransp = 0;
			}
		} 
		/* an escape sequence is not active */
		else if (etat_c.fesc == FALSE) 
		{
			/* caractere normal */
			if (etat_c.fsecret == FALSE) 
			{
				if (etat_c.fminmaj != FALSE) 
				{
					if (etat_c.fminmaj == MAMI)
						/* passage min/MAJ */
						car = mima(car, 0);
					else	car = mima(car, 1);
				}
				mes = car;
				wwrite(fimpl,1,(BYTE FAR *)&mes);
			}
		} 
		/* determine the escape sequence */
		else if (etat_c.fmask   > 0) 
		{
			if ( etat_c.fmask == 1 ) 
			{
				etat_c.fmask++;
				etat_c.fposcur = car;
				return;
			}
			else	
			{
				_co(27); _co('Z');
				_co(etat_c.fposcur & 0x00FF);
				_co(car & 0x00FF);
				etat_c.fesc = etat_c.fmask = etat_c.fposcur = 0;
				return;
			}
		}
		/* cursor positioning ESC F */
		else if (etat_c.fposcur > 0) 
		{
			/* posit en cours */
			if ( car < 0x20) 
			{
				etat_c.fposcur = 0;	    /* mauvais parametre */
				etat_c.fesc = 0;
			}
			else if (etat_c.fposcur == 1) 
			{
				etat_c.fposcur = car;	  /* Esc f */
			} 
			else 	
			{				 /* Esc fx */
				c = car - 0x1f;
				wposcur(fimpl, c , etat_c.fposcur - 0x1f);
				etat_c.fposcur = 0;
				etat_c.fesc = 0;
			}
		}
		/* double escape sequence */
		else if (etat_c.fescesc == TRUE) 
		{
			etat_c.fesc = FALSE;
			etat_c.fescesc = FALSE;
			switch (car) 
			{
			case '[':
				x_bstart();
				break;
			case ']':
				x_bflush();
				break;
			}
		}
		/* colour parameter processing */
		else if (etat_c.fcouleur > 0) 
		{
			car = (car <= '9') ? car - '0' : car + 10 - 'A';
			switch (etat_c.fcouleur) 
			{
			case ETAT_LABEL	:
				if ((etat_c.bytes[etat_c.extra++]=car) == ';')
				{
					etat_c.bytes[etat_c.extra] = 0;
					wimg(fimpl,etat_c.bytes);
				}
				etat_c.fesc = 0;
				etat_c.fcouleur = 0;
				return;
			case ETAT_VIDEO :
				if ((etat_c.bytes[etat_c.extra++]=car) == ';')
				{
					etat_c.bytes[etat_c.extra] = 0;
					wimg(fimpl,etat_c.bytes);
				}
				etat_c.fesc = 0;
				etat_c.fcouleur = 0;
				return;
			case ETAT_IMAGE	:
				if ((etat_c.bytes[etat_c.extra++]=car) == ';')
				{
					etat_c.bytes[etat_c.extra] = 0;
					wimg(fimpl,etat_c.bytes);
				}
				etat_c.fesc = 0;
				etat_c.fcouleur = 0;
				return;
			case UPLOADER	:
				_co(ESCAPE);
				_co('!');
				_co(car);
				etat_c.fesc = 0;
				etat_c.fcouleur = 0;
				return;

			case COUL_FOND_ETD :
				if ((etat_c.bytes[etat_c.extra++]=car) == ';')
				{
					etat_c.bytes[etat_c.extra] = 0;
					wetd(fimpl,0,etat_c.bytes);
				}
				etat_c.fesc = 0;
				etat_c.fcouleur = 0;
				return;

			case COUL_TXT_ETD :
				if ((etat_c.bytes[etat_c.extra++]=car) == ';')
				{
					etat_c.bytes[etat_c.extra] = 0;
					wetd(fimpl,1,etat_c.bytes);
				}
				etat_c.fesc = 0;
				etat_c.fcouleur = 0;
				return;
			case COUL_BAS:
				etat_c.colbas = car;
				break;
			case COUL_FOND:
				etat_c.colfond = car;
				break;
			case COUL_TXT:
				etat_c.coltxt  = car;
				break;
			}
			etat_c.fesc = 0;
			etat_c.fcouleur = 0;
			watb(fimpl,etat_c.atb,etat_c.coltxt,etat_c.colfond);
		} 
		/* transparent packet processing */
		else if (etat_c.ftransp != 0) 
		{
			if (etat_c.ftransp == 1) 
			{
				etat_c.cpt_trans = (car & 0x00FF);
				etat_c.ftransp++;
			}
			else 	
			{
				_co(ESCAPE);
				_co('T');
				_co(etat_c.cpt_trans);
				_co(car);
				etat_c.cpt_trans |= ((car<<8) & 0xFF00);
				etat_c.fesc = 0;
				etat_c.ftransp = 0;
			}
		} 
		/* determine the NEW escape sequence */
		else 	
		{
			etat_c.fesc = FALSE;
			switch (car) 
			{
			case 'Z':	/* mouse mask */
				etat_c.fposcur=0;
				etat_c.fmask  = 
				etat_c.fesc   = TRUE;
				break;
			case 'T':           /* transparent */
				etat_c.ftransp = 1;
				etat_c.fesc = TRUE;
				break;
#ifdef	_LTS_ESC_X
			case 'X':	/* screen label draw  */
				etat_c.extra = 0;
				etat_c.bytes[etat_c.extra++]=car;
				etat_c.fcouleur = ETAT_LABEL;
				etat_c.fesc = TRUE;
				break;
#endif
#ifdef	_LTS_ESC_V
			case 'V':	/* screen video draw  */
				etat_c.extra = 0;
				etat_c.bytes[etat_c.extra++]=car;
				etat_c.fcouleur = ETAT_VIDEO;
				etat_c.fesc = TRUE;
				break;
#endif
#ifdef	_LTS_ESC_I
			case 'I':	/* screen image draw  */
				etat_c.extra = 0;
				etat_c.bytes[etat_c.extra++]=car;
				etat_c.fcouleur = ETAT_IMAGE;
				etat_c.fesc = TRUE;
				break;
#endif
#ifdef	_LTS_ESC_N
			case 'N':	/* redimension screen */
				etat_c.fcouleur = COUL_SCREEN_SIZE;
				etat_c.fesc = TRUE;
				break;
#endif
			case 'n':           /* couleur base */
				etat_c.fcouleur = COUL_BAS;
				etat_c.fesc = TRUE;
				break;
#ifdef	_LTS_ESC_R
			case 'R':	/* extended text colour	*/	
				etat_c.fcouleur = COUL_TXT_ETD;
				etat_c.fesc = TRUE;
				etat_c.extra = 0;
				break;
#endif
			case 'r':       /* couleur texte 	*/
				etat_c.fcouleur = COUL_TXT;
				etat_c.fesc = TRUE;
				break;
#ifdef	_LTS_ESC_S
			case 'S':	/* extended back colour	*/	
				etat_c.fcouleur = COUL_FOND_ETD;
				etat_c.fesc = TRUE;
				etat_c.extra = 0;
				break;
#endif
			case '!':           /* upload window*/
				etat_c.fcouleur = UPLOADER;
				etat_c.fesc = TRUE;
				break;
			case 's':           /* couleur fond */
				etat_c.fcouleur = COUL_FOND;
				etat_c.fesc = TRUE;
				break;

			case 'h':           /* surbrillant */
				if (COULEUR == TRUE)
					etat_c.coltxt = etat_c.coltxt | 0x8;
				etat_c.atb = SURINT;
				watb(fimpl,etat_c.atb,etat_c.coltxt,etat_c.colfond);
				break;

			case 'e':           /* sousbrillant */
				if (COULEUR == TRUE)
					etat_c.coltxt = etat_c.coltxt & 0x7;
				etat_c.atb = SOUSINT;
				watb(fimpl,etat_c.atb,etat_c.coltxt,etat_c.colfond);
				break;

			case 'd':           /* souligned */
				if (COULEUR == TRUE)
					etat_c.coltxt = CYAN_CL;
				etat_c.atb = SOULIGNE;
				watb(fimpl,etat_c.atb,etat_c.coltxt,etat_c.colfond);
				break;

			case 'c':           /* clignotant */
				etat_c.atb = CLIGNOT;
				watb(fimpl,etat_c.atb,etat_c.coltxt,etat_c.colfond);
				break;

			case 'p':           /* preferentiel */
			case 'b':           /* inverse */
				if (COULEUR == TRUE) 
				{
					if (car == 'p')
						etat_c.coltxt = JAUNE;
					else 
					{
						c = etat_c.coltxt;
						etat_c.coltxt = etat_c.colfond;
						etat_c.colfond = c & 7;
					}
				}
				etat_c.atb = VIDEO;
				watb(fimpl,etat_c.atb,etat_c.coltxt,etat_c.colfond);
				break;

			case 'w':           /* curseur OFF */
				wfgen(fimpl,CUROF);
				break;

			case 'v':           /* curseur ON */
				wfgen(fimpl,CURON);
				break;

			case 'Q':            /* hard-copy G */
				_co(ESCAPE);
				_co('Q');
				break;

			case 'O':           /* hard-copy NG*/
				_co(ESCAPE);
				_co('O');
				break;

			case 'P':           /* sup caractere*/
				wfgen(fimpl,SUP_CAR);
				break;

			case '@':           /* ins caractere*/
				wfgen(fimpl,INS_CAR);
				break;

			case 'M':           /* sup ligne*/
				wfgen(fimpl,SUP_LIG);
				break;

			case 'L':           /* ins ligne */
				wfgen(fimpl,INS_LIG);
				break;

			case 'K':           /* sup fin ligne*/
				wfgen(fimpl,CLEOL);
				break;

			case 'J':           /* sup fin ecran*/
				wfgen(fimpl,CLEOF);
				break;

			case 'j':           /* large */
				etat_c.fminmaj = MIMA;
				break;

			case 'i':           /* small */
				etat_c.fminmaj = MAMI;
				break;

			case 'a':           /* reset attrib */
				etat_c.fsecret = FALSE;
				etat_c.fminmaj = FALSE;
				etat_c.atb = NORMAL;
				etat_c.coltxt = etat_c.colbas;
				etat_c.colfond = NOIR;
				if (color_impl) 
				{
				    etat_c.coltxt = win_coltxt;
				    etat_c.colfond = win_colfon;
				}
				watb(fimpl,etat_c.atb,etat_c.coltxt,etat_c.colfond);
				break;
			case 'f':           /* debut posit */
				etat_c.fposcur = TRUE;
				etat_c.fesc = TRUE;
				break;
#ifndef	_LTS_ESC_S
			case 'S':           /* mode secret actif*/
				etat_c.fsecret = TRUE;
				break;
#endif
#ifndef	_LTS_ESC_R
			case 'R':          /* mode secret inactif*/
				etat_c.fsecret = FALSE;
				break;
#endif
			}
		}
	}
}

/**********************************************
* routine d'affichage d'un caractere          *
* provisoire sous UNIX			      *
***********************************************/

void AFICAR(car)
WORD car;
{
	_co(car);
}

/**********************************************
* routine d'initialisation de l'emulation     *
***********************************************/

WORD emco_ini()
{
	/* init de l'etat console par defaut */
	etat_c.fesc = FALSE;
	etat_c.fmask = 0;
	etat_c.fposcur = 0;
	etat_c.fminmaj = FALSE;
	etat_c.fsecret = FALSE;
	etat_c.ftransp = FALSE;
	etat_c.atb = NORMAL;
	etat_c.coltxt = VERT;
	etat_c.colfond = NOIR;
	etat_c.colbas = VERT;

	return (OK);
}

/**********************************************
* routine de fin emulation		      *
***********************************************/

void emco_fin()
{
	return;
}

/**********************************************
* informations generales sur une console      *
* module provisoire			      *
***********************************************/

void get_cons()
{
	MAXLIG = conf(1);
	MAXCOL = conf(2);
	if (!( SBARCOL= conf(13) ))
		SBARLIG=0;
	else	SBARLIG=1;
	COULEUR = conf(14);
	return;
}

/**********************************************
* informations generales sur une console      *
* module provisoire			      *
***********************************************/

WORD cons_cur(type_info)
WORD type_info;
{
	WORD ret_info;

	switch (type_info) {
	case 1:
		ret_info = x_col();
		break;
	case 2:
		ret_info = x_lin();
		break;
	default:
		ret_info = conf(type_info);
		break;
	}
	return (ret_info);
}

/************************************************
* equivalent du conf (cico)			*
*  routine appelee par ABAL			*
*************************************************/

WORD FAR Run_Conf(type_info)
WORD type_info;
{
	switch (type_info) 
	{
	case 1: 		   /* nombre de lignes */
		if (fen_ini == 0)
			return(conf(1)); /*MAXLIG*/
		else
			return(winfo(4));
	case 2: 		   /* nombre de colonnes	 */
		if (fen_ini == 0)
			return(conf(2)); /*MAXCOL*/
		else
			return(winfo(3));
	default:
		return(conf(type_info));
	}
}

/***********************************************
* envoi d'une chaine                           *
*----------------------------------------------*
* routine provisoire appelee par ABAL	       *
************************************************/

#define BUFSIZE 1024
BYTE mes_buffer[BUFSIZE];

void FAR Run_Mes( BYTE FAR *mess, WORD lgr )
{
	int	i;
	int	mes_buffer_index;

	if ( ( fen_ini == 0 ) || ( fimpl == 0 ) ) 
	{
		for (i = 0; i < lgr; ++i)
			Run_Co(mess[i]);
		return;
	}
	
	i = 0; mes_buffer_index = 0;

	while ( i < lgr ) 
	{

		while (( etat_c.fesc != FALSE ) && ( i < lgr ) ) Run_Co(mess[(i++)]);
		if ( i >= lgr ) return;

		while (( i < lgr ) && ( mess[i] != ESCAPE )) 
		{

			while (( mes_buffer_index < BUFSIZE ) && ( i < lgr )) 
			{
				if ( mess[i] != ESCAPE ) 
				{
					if (etat_c.fminmaj != FALSE) 
					{
						if (etat_c.fminmaj == MAMI)
							mess[i] = (BYTE) mima( (WORD) mess[i], 0);
						else	mess[i] = (BYTE) mima( (WORD) mess[i], 1);
					}
					mes_buffer[mes_buffer_index++] = mess[i++];
				} 
				else	break;
			}
			if ( mes_buffer_index > 0 ) 
			{
				if ((fen_ini == 0) || (fimpl == 0)) 
				{
					mes_buffer[mes_buffer_index]='\0';
					x_cprintf(mes_buffer);
				} 
				else 	
				{
					wwrite(fimpl,mes_buffer_index,mes_buffer);
				}
			mes_buffer_index = 0;
			}
		}

		if ( i < lgr ) 
			Run_Co(mess[i++]);
	}		
}

void FAR Run_Str(mess)
BYTE FAR * mess;
{
	WORD	l=0;
	while ( *(mess+l) != 0 )
		l++;
	Run_Mes( mess, l );
	return;
}

/************************************************
* position colonne				*
*  routine appelee par ABAL			*
*************************************************/

WORD FAR Run_Col()
{
	if (fen_ini == 0)
		return( x_col() );
		/* IJM : return(_co_colonne()); */
	else
		return(winfo(1));
}


/************************************************
* position ligne				*
*  routine appelee par ABAL			*
*************************************************/

WORD FAR Run_Lin()
{
	if (fen_ini == 0)
		return(x_lin());
		/* return(_co_ligne()); */
	else
		return(winfo(2));
}

#endif 	/* _runco_c */
	
