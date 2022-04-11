/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1989 Amenesik / Sologic s.a.
 *
 *	ixcico.c - fonctions interface ecran/clavier/imprimante
 *
 *	$Header: /home/Produits/Abal3/cico/ixcicosp.c,v 1.2 2007/01/11 09:39:55 jamie Exp $
 *
	Modif 28/10/91 : Impression bouclage sur erreur quand pas on error
	Modif 25/02/93 : Modification temporisation pour SCO et UNIX SVR 4
			 definir SVR4_TEMPO : temporisation en 1/10 s
	Modif 08/03/93 : sigaction pour systeme BSD definir SYS_BSD
	Modif 02/04/93 : Comportement couleur backgr ( modulo 8 )
	Modif 23/06/93 : Parametre longueur dans lcfo pour redirection
	Modif 01/06/93 : Sparc Sun _co_conv c &= 0x00FF;
	-------------- 1.4d - 2.1a ---------------------------------------
	Modif 23/06/93 : Bufferisation imprimante meme principe que pour
			 l'ecran 	
			 Correction du bug pas d'impression lorsque
			 pas de redirection
	Modif 13/04/94 : fichier de configuration CICO
			 define ABALCONF
	-------------- 2.1c --------------------------------------------
	Modif 30/05/94 : autorisation d'imprimer sur un pipe
 */

#include <stdio.h>
#include <string.h>
#include <allocate.h>
#include <signal.h>
#include <errno.h>

#if unix || M_XENIX

#include <fcntl.h>
#include <unistd.h>
#include <termio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utmp.h>
#ifdef SVR4_TEMPO
#include <sys/itimer.h>
#endif
#endif /* unix || M_XENIX */

#ifdef vms

#include <unixio.h>
#include <file.h>
#include <types.h>

#endif /* vms */

#define UPDATE	"$Date: 2007/01/11 09:39:55 $"

#define ALSMID "ixcicosp"
#include "allocate.h"
#ifdef CICO_BDA
#include "bda.h"
#endif /* fin CICO_BDA */

#ifdef ASFCICO
#include "asfcico.h"
#endif /* ASFCICO */

#include "_cico.h"
#include "cico.h"
#include "ixcicosp.h"

#ifdef ABALCONF
#include "aconf.h"
#include "aconf.c"
#endif /* ABALCONF */


#define XCICO_NB 8
WORD XCICO_nbl;
CHAR XCICO_start[XCICO_NB]={'6','9','2','9','3','9','3','9'};

#ifdef CICO_DEBUG
FILE *DEBUG;
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
/*
	 variables utilises pour la gestion d'une imprimante locale
*/
static BOOL	IMP_LOC_ACTIVE=FALSE;

/* Envoie de la sequence d'initialisation de l'imprimante locale
*/
static deb_imp_loc(fh)
int fh;
{
	BYTE *pt;

	pt=ENTER_LOCAL;
	while(*pt)
		write(fh,pt++,1);
}
/* Envoie de la sequence de fermeture de l'imprimante locale
*/
static fin_imp_loc(fh)
int fh; 
{
	BYTE *pt;

	pt=EXIT_LOCAL;
	while(*pt)
		write(fh,pt++,1);
}
#endif

/*************************************************************************
 *									 *
 *		Primitives de gestion de la saisie au clavier		 *
 *									 *
 *************************************************************************/
#ifdef _DELAY
static BOOL _delay = TRUE;
#endif
/* saisie d'un caractere depuis le clavier suivant la norme Amenesik / Sologic
 * -----------------------------------------------------------------
 *
 * appel:	rien
 *
 * retour:	le caractere
 *
 */
WORD x_getch()
{
	WORD c;

#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_GETCH\n");
#endif /* fin CICO_DEBUG */

#ifdef CIFIC
	if (cific_ok == TRUE)
	  {
		c = fgetc(cific_ptr);
		if ( (ferror(cific_ptr)) || feof(cific_ptr))
		   {
			fclose(cific_ptr);
			cific_ok = FALSE;
		   }
		else
		   {
			if (c == 0x0a) c=0x0d;
			if (cofic_ok == TRUE)
			  {
				if (c == 0x0d)
					 { fputc((int) 0x0a,cofic_ptr); }
				    else 
					 { fputc(c,cofic_ptr); };
		
				if (ferror(cofic_ptr) || feof(cofic_ptr))
				    {
					fclose(cofic_ptr);
					cofic_ok = FALSE;
				    };
			  };
			return(c);
		   };
	   };
#endif

#ifdef CICO_BDA
	if (redir_CI == TRUE) {

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_CI)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

		c = CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_CI],
				    0, NULL, NULL, NULL);
	}
	else
	{
#endif /* fin CICO_BDA */
	
	if (turn_lec == turn_ecr) {
#ifdef _DELAY
		if ( _delay == FALSE ) {
			delay_on();
			_delay = TRUE;
		}
#endif
		_ci_lecture(TRUE);
	}
	c = (WORD)*turn_lec++;
	if (turn_lec == turn_fin)
		turn_lec = turn_buf;
#ifdef CICO_BDA
	}
#endif


#ifdef CIFIC
	if (cofic_ok == TRUE)
	  {
		if (c == 0x0d)
			 { fputc((int) 0x0a,cofic_ptr); }
		    else 
			 { fputc(c,cofic_ptr); };

		if (ferror(cofic_ptr) || feof(cofic_ptr))
		    {
			fclose(cofic_ptr);
			cofic_ok = FALSE;
		    };
	  };
#endif
	return (c);
}


/* test si un caractere est disponible dans le buffer clavier
 * ----------------------------------------------------------
 *
 * appel:	rien
 *
 * retour:	0 si rien en entree
 *
 */
WORD x_kbhit()
{
int c;
#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_KBHIT\n");
#endif /* fin CICO_DEBUG */

#ifdef CIFIC
	if (cific_ok == TRUE)
	  {
		c = fgetc(cific_ptr);
		if ( (ferror(cific_ptr)) || feof(cific_ptr))
		   {
			fclose(cific_ptr);
			cific_ok = FALSE;
			return(0);
		   }
		else
		   {
			ungetc(c,cific_ptr);
			return(1);
		   };
	   };
#endif

#ifdef CICO_BDA
	if (redir_CI == TRUE) {

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_TPCI)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

		return (CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_TPCI],
				    0, NULL, NULL, NULL));
	}
#endif /*fin CICO_BDA */

	if (turn_lec == turn_ecr) {
#ifdef _DELAY
		if ( _delay == TRUE ) {
			_delay = FALSE;
			delay_off();
		}
#endif
		_ci_lecture(FALSE);
	}
	if (turn_lec != turn_ecr)
		return (1);
	else
		return (0);
}


/*************************************************************************
 *									 *
 *		Primitives internes de la gestion du clavier		 *
 *									 *
 *************************************************************************/

/* trap du signal ALARM (NEW_TEMPO)
 * --------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
static int _trap_signal_alarm(nb)
int nb;
{
	(VOID) signal(SIGALRM,_trap_signal_alarm);
	return 0;
}

/* lecture d'un caractere et mise dans le tampon clavier (NEWTEMPO)
 * ----------------------------------------------------------------
 *
 * appel:	adresse du tampon buf, position dans le tampon du car a lire
 *
 * retour:	nb de caractere effectivement lu ( negatif si erreur)
 *
 */
static int _read_buf(buf,nb)
CHAR *buf;
int nb;
{
	int n;
	int (*sv_signal) ();		
	int r_err;

#ifdef SVR4_TEMPO
struct itimerval value,ovalue;
int sv_alarm;
#else
#ifdef SYS_BSD
struct sigaction act,oact;	
#endif /* SYS_BSD */
unsigned sv_alarm;
#endif /* SVR4_TEMPO */
			
	if (nb>0) {
		delay_on();
		sv_signal=signal(SIGALRM,_trap_signal_alarm);

#ifndef SVR4_TEMPO
#ifdef SYS_BSD
		sigaction(SIGALRM,NULL,&act);
		act.sa_flags |= SV_INTERRUPT;
		sigaction(SIGALRM,&act,&oact);
#endif /* SYS_BSD */
		sv_alarm=alarm(tempo);
#else
		value.it_interval.tv_sec=tempo/10;
		value.it_interval.tv_usec=(tempo%10)*100000;
		value.it_value.tv_sec=tempo/10;
		value.it_value.tv_usec=(tempo%10)*100000;
		sv_alarm=setitimer(ITIMER_REAL,&value,&ovalue);
#endif /* SVR4_TEMPO */

#ifdef CICO_DEBUG
		printf("\r\nREAD_ALARM\r\n");
#endif
		n=read(STDIN,buf,1);
		r_err=errno;

#ifndef SVR4_TEMPO
#ifdef SYS_BSD
		sigaction(SIGALRM,&oact,NULL);
#endif /* SYS_BSD */
		(VOID) alarm(sv_alarm);
#else
		sv_alarm=setitimer(ITIMER_REAL,&ovalue,&value);
#endif /* SVR4_TEMPO */

		(VOID) signal(SIGALRM,sv_signal);
		delay_off();
		if (( n<1 ) && ( r_err==EINTR )) {
			return 0;
		} else {
			return n;
		}
	} else {
#ifdef CICO_DEBUG 
		printf("\r\nREAD\r\n");
#endif
		n=read(STDIN,buf,1);
		return n; 
	}
}

/* lecture effective d'un caractere
 * --------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
static VOID _ci_lecture(delay)
BOOL delay;
{
	register i, j;
	int longueur;
	BYTE car;
	BOOL scanned;
	BYTE *bp;
	int DRAP=0;

#ifndef _DELAY
	if (delay == FALSE) {
		delay_off();
	}
#endif
	in_nb = 0;
	i = SCAN_FIRST;
#ifdef vms
	scanned = FALSE;
	while (vms$read(scanned, in_buf + in_nb, 1) > 0) {
#else
	while (_read_buf(in_buf + in_nb,in_nb) > 0) { 		/*(NEWTEMPO)*/
#endif /* vms */
test:
		in_nb++;
		scanned = FALSE;
		while (i < SCAN_FIRST + SCAN_NB) {
			if (*in_buf == **(term_str + i) &&
			    strncmp(in_buf, *(term_str + i), in_nb) == 0) {
				scanned = TRUE;
				break;
			}
			i++;
		}
		if (scanned == TRUE) {
			DRAP=1;
			if (in_nb == strlen(*(term_str + i))) { /* egalite */
				if (i >= PKEY_FIRST) {
					i -= PKEY_FIRST;
					memcpy(in_buf, pkey[i].str, pkey[i].lg);
					in_nb = pkey[i].lg;
				} else if (i >= NKEY_FIRST) {
					i -= NKEY_FIRST;
					bp = term_str[i + NKEY_STR_FIRST];
					longueur = strlen(bp);
					if (longueur > 0) {
						strcpy(in_buf, bp);
						in_nb = strlen(bp);
					} else {
						bp = term_str[i + NKEY_FIRST];
						in_nb -= strlen(bp);
						if (delay == TRUE) {
							delay_on();
							i = SCAN_FIRST;
							continue;
						}
					}
				} else {
					DRAP=0;
					i -= ACC_FIRST;
					if (accent == NO_ACCENT) {
						accent = i;
						bp = term_str[i + ACC_FIRST];
						in_nb -= strlen(bp);
						if (delay == TRUE)
							continue;
					}
					scanned = FALSE;
				}
				break;
			} else {				/* inclusion */
				delay_off();
/*(NEWTEMPO):suppression de la boucle de temporisation sous UNIX */
				continue;
			}
		} else
			break;				/* non egalite */
	}
	if (scanned == TRUE) {
		for (i = 0; i < in_nb; i++) {
			*turn_ecr++ = *(in_buf + i);
			if (turn_ecr == turn_fin)
				turn_ecr = turn_buf;
		}
	} else {
		if ( DRAP == 0 )  in_nb++;
		for (i = 0; i < in_nb-1; i++) {
			if (accent != NO_ACCENT) {
				car = tab_in[*(in_buf + i)];
				if ((bp = (BYTE *)strchr(acc[accent].istr, car)) != NULL)
					*turn_ecr++ = acc[accent].ostr[bp - acc[accent].istr];
				else
					*turn_ecr++ = car;
				accent = NO_ACCENT;
			} else
				*turn_ecr++ = tab_in[*(in_buf + i)];
			if (turn_ecr == turn_fin)
				turn_ecr = turn_buf;
		}
		if (DRAP != 0) {
			*in_buf= (BYTE) *(in_buf+in_nb-1);
   			in_nb=0;
			i = SCAN_FIRST;
			DRAP=0;
			goto test;
		}
	}
#ifndef _DELAY
	delay_on(); 
#endif
}



/****************************************************************
 *								*
 *	Programmation des touches de fonctions			*
 *								*
 ****************************************************************/


/* ecriture d'une touche programmable
 * ----------------------------------
 *
 * appel:	numero de fonction a programmer
 *		pointeur sur la chaine a associer
 *		longueur de la chaine
 *
 * retour:	0 si OK
 *		-1 en cas d'erreur, err_val contient le code erreur
 *
 */
WORD prfo(numero, chaine, longueur)
WORD numero;
BYTE *chaine;
WORD longueur;
{
	register i;

#ifdef CICO_BDA
	if (redir_CI == TRUE) {
		BYTE type[3];
		VOID *argument[3];
		WORD taille[3];

		type[0] = TYPE_WORD;
		type[1] = TYPE_CHAINE;
		type[2] = TYPE_WORD;
		argument[0] = (VOID *)&numero;
		argument[1] = (VOID *)chaine;
		argument[2] = (VOID *)&longueur;
		taille[0] = 2;
		taille[1] = strlen(chaine);
		taille[2] = 2;

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_PRFO):%d\n",taille[1]);
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

		return (CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_PRFO],
				    3, type, argument, taille));
	}
#endif /* fin CICO_BDA */

	for (i = 0; i < PKEY_NB + PKEY_F_NB; i++) {
		if (pkey[i].code == (BYTE)numero && pkey[i].act == TRUE) {
			if (longueur > 0) {
				if (longueur > pkey[i].max)
					longueur = pkey[i].max;
				strncpy(pkey[i].str, chaine, longueur);
				pkey[i].lg = longueur;
			}
			return (0);
		}
	}
	err_val = 56;
	return (-1);
}


/* lecture d'une touche programmable
 * ---------------------------------
 *
 * appel:	numero de fonction a lire
 *		pointeur sur la chaine de reception
 *		longueur de la chaine
 *
 * retour:	0 si OK
 *		-1 en cas d'erreur, err_val contient le code erreur
 *
 */
WORD lcfo(numero, chaine, longueur)
WORD numero;
BYTE *chaine;
WORD longueur;
{
	register i;

#ifdef CICO_BDA
	if (redir_CI == TRUE) {
		BYTE type[3];
		VOID *argument[3];
		WORD taille[3];

		type[0] = TYPE_WORD;
		type[1] = TYPE_CHAINE | MODIFIABLE;
		type[2] = TYPE_WORD;
		argument[0] = (VOID *)&numero;
		argument[1] = (VOID *)chaine;
		argument[2] = (VOID *)&longueur;
		taille[0] = 2;
		taille[1] = longueur;
		taille[2] = 2;

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_LCFO):%d\n",taille[1]);
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

		return (CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_LCFO],
				    3, type, argument, taille));
	}
#endif /* fin CICO_BDA */

	for (i = 0; i < PKEY_NB + PKEY_F_NB; i++) {
		if (pkey[i].code == (BYTE)numero && pkey[i].act == TRUE) {
			if (longueur > 0) {
				if (longueur > pkey[i].lg)
					longueur = pkey[i].lg;
				strncpy(chaine, pkey[i].str, longueur);
				if (longueur < pkey[i].lg) {
					err_val = 63;
					return (-1);
				}
			}
			return (0);
		}
	}
	err_val = 56;
	return (-1);
}


/************************************************************************
 *									*
 *	Primitives de gestion des affichages / editions 		*
 *									*
 ***********************************************************************/


/* edition d'un caractere
 * ----------------------
 *
 * appel:	le caractere a editer
 *
 * retour:	rien
 *
 */
VOID x_putch(c)
WORD c;
{

#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_PUTCH\n");
#endif /* fin CICO_DEBUG */

	if (prndest == ECRAN)
		_co(c);
	else if (prndest == TAMPON) {
		if (prnleng > 0) {
			*prnptr++ = (BYTE)c;
			prnleng--;
		} 
	} else
		_lo(c);
}


/* Affichage d'une chaine sur le peripherique courant
 * --------------------------------------------------
 *
 * appel:	pointeur sur la chaine
 *
 * retour:	rien
 *
 */
VOID x_cprintf(chaine)
BYTE *chaine;
{
#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_CPRINTF\n");
#endif /* fin CICO_DEBUG */

	if (flag_buf == FALSE) {
		x_bstart();
		while (*chaine != 0x00)
			x_putch(*(chaine++));
		x_bflush();
	} else
		while (*chaine != 0x00)
			x_putch(*(chaine++));
}


/* vidage du buffer de sortie
 * --------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_bflush()
{
#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_BFLUSH\n");
#endif /* fin CICO_DEBUG */

	if ( prndest == ECRAN )
		_co_flush();
	else
		_lo_flush();
}


/* passage en mode bufferise
 * -------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_bstart()
{
#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_BSTART\n");
#endif /* fin CICO_DEBUG */
	if ( prndest == ECRAN )
		_co_start();
	else
		_lo_start();
}


/* positionnement absolu en ligne et colonne
 * -----------------------------------------
 *
 * appel:	ligne et colonne (a partir de 1)
 *
 * retour:	rien
 *
 */
VOID pos(ligne, colonne)
WORD ligne;
WORD colonne;
{
	register i;

	if (ligne == 0)
		ligne++;
	if (colonne == 0)
		colonne++;
	if (prndest == ECRAN) { 		/* ecran */
		_co(ESC);
		_co('f');
		_co(colonne + 0x001f);
		_co(ligne + 0x001f);
	} else if (prndest != TAMPON) { 	/* imprimante */
		if (courante == NULL)
			if (prnfid == 0) {
				if (_lo_defaut() != 0)
					return;
			} else {
				err_val = 42;
				return;
			}
		ligne--;
		colonne--;
		if (ligne > courante->ligne) {
			for (i = courante->ligne; i < ligne; i++)
				_lo_out(LF);
			courante->ligne = ligne;
		}
		if (colonne < courante->colonne) {
			_lo_out(CR);
			i = 0;
		} else
			i = courante->colonne;
		for (; i < colonne; i++)
			_lo_out(' ');
		courante->colonne = colonne;
	}
}


/* selection d'un attribut d'affichage
 * -----------------------------------
 *
 * appel:	le numero de l'attribut choisi
 *
 * retour:	rien
 *
 */
VOID atb(attribut)
WORD attribut;
{
	switch (attribut) {
	case 0: 		/* visualisation normale */
		attribut = 'a';
		break;
	case 1: 		/* attribut preferentiel */
		attribut = 'p';
		break;
	case 2: 		/* inversion video */
		attribut = 'b';
		break;
	case 3: 		/* clignotement */
		attribut = 'c';
		break;
	case 4: 		/* soulignement */
		attribut = 'd';
		break;
	case 5: 		/* sous-brillance */
		attribut = 'e';
		break;
	case 6: 		/* sur-brillance */
		attribut = 'h';
		break;
	case 7: 		/* lettres forcees majuscules */
		attribut = 'i';
		break;
	case 8: 		/* lettres forcees minuscules */
		attribut = 'j';
		break;
	case 9: 		/* hard copy */
		attribut = 'O';
		break;
	case 10:		/* caracteres penches */
		attribut = 'y';
		break;
	case 11:		/* double largeur */
		attribut = 'z';
		break;
	case 12:
		attribut = 'k';
		break;
	case 13:
		attribut = 'l';
		break;
	case 14:
		attribut = 'm';
		break;
	case 15:
		attribut = 'n';
		break;
	case 16:
		attribut = 'q';
		break;
	case 17:
		attribut = 'r';
		break;
	case 18:
		attribut = 's';
		break;
	case 19:		/* double hauteur */
		attribut = 't';
		break;
	case 20:
		attribut = 'Q';
		break;
	case 21:		/* effacement fin de ligne */
		attribut = 'K';
		break;
	case 22:		/* effacement fin de page */
		attribut = 'J';
		break;
	case 23:		/* insertion de ligne */
		attribut = 'L';
		break;
	case 24:		/* suppression de ligne */
		attribut = 'M';
		break;
	case 25:		/* extinction curseur */
		attribut = 'w';
		break;
	case 26:		/* allumage curseur */
		attribut = 'v';
		break;
	case 27:
		attribut = '*';
		break;
	case 28:
		attribut = '#';
		break;
	case 29:		/* caracteres compactes */
		attribut = 'x';
		break;
	case 30:		/* indice ou push ecran */
/* DLR:18/02/93 */
		attribut = '>';
		break;
	case 31:		/* exposant ou pop ecran */
/* DLR:18/02/93 */
		attribut = '<';
		break;
	default:
		return;
	}
	x_putch(ESC);
	x_putch(attribut);
}


/* selection de la couleur de fond
 * -------------------------------
 *
 * appel:	le numero de couleur
 *
 * retour:	rien
 *
 */
VOID backgr(couleur)
WORD couleur;
{
/* 02/04/93 */
	couleur &= 0x0007;
	if (couleur >= 0 && couleur <= 7) {
		_co(ESC);
		_co('s');
		_co(couleur + '0');
	}
}


/* selection de la couleur du texte
 * --------------------------------
 *
 * appel:	le numero de la couleur
 *
 * retour:	rien
 *
 */
VOID foregr(couleur)
WORD couleur;
{
	if (couleur >= 0 && couleur <= 9) {
		_co(ESC);
		_co('r');
		_co(couleur + '0');
	} else if (couleur >= 10 && couleur <= 15) {
		_co(ESC);
		_co('r');
		_co(couleur - 10 + 'A');
	}
}


/* effacement d'ecran / saut de page imprimante
 * --------------------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_clear()
{
	BYTE b;
	WORD w;


#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_CLEAR\n");
#endif /* fin CICO_DEBUG */

	switch (prndest) {
	case TAMPON:
		break;
	case ECRAN:
		lcfo(6, &b, 1);
		w = b;
		_co(w);
		break;
	default:
		_lo(FF);
	}
}


/* sonnerie
 * --------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_bell()
{

#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_BELL\n");
#endif /* fin CICO_DEBUG */

	x_putch(BEL);
}


/* position colonne sur le peripherique courant
 * --------------------------------------------
 *
 * appel:	rien
 *
 * retour:	la position
 *
 */
WORD x_col()
{

#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_COL\n");
#endif /* fin CICO_DEBUG */

	if (prndest == ECRAN)
		return (_co_colonne() + 1);
	else {
		if (courante == NULL)
			if (prnfid == 0) {
				if (_lo_defaut() != 0)
					return (0);
			} else {
				err_val = 42;
				return (0);
			}
		return (courante->colonne + 1);
	}
}


/* position ligne sur le peripherique courant
 * ------------------------------------------
 *
 * appel:	rien
 *
 * retour:	la position
 *
 */
WORD x_lin()
{

#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_LIN\n");
#endif /* fin CICO_DEBUG */

	if (prndest == ECRAN)
		return (_co_ligne() + 1);
	else {
		if (courante == NULL)
			if (prnfid == 0) {
				if (_lo_defaut() != 0)
					return (0);
			} else {
				err_val = 42;
				return (0);
			}
		return (courante->ligne + 1);
	}
}


/* conversion minuscule/majuscule
 * ------------------------------
 *
 * appel:	caractere a convertir
 *		0 si conversion en majuscule, 1 pour conversion en minuscule
 *
 * retour:	caractere converti
 *
 */
WORD mima(c, conv)
WORD c;
WORD conv;
{
	c &= 0xff;
	if (conv == UPPER_CASE) {
		if (c >= 'a' && c <= 'z')
			c -= 0x20;
		else if (c >= 0x80 && c <= 0xcf)
			c = min_to_maj[c - 0x80][(code_lang > 1) ? 0 : 1];
	} else if (conv == LOWER_CASE) {
		if (c >= 'A' && c <= 'Z')
			c += 0x20;
		else if (c >= 0x80 && c <= 0xcf)
			c = maj_to_min[c - 0x80];
	}
	return (c);
}


/* ouverture d'un imprimante
 * -------------------------
 *
 * appel:	nom imprimante et autorisation
 *
 * retour:	valeur de prnfid
 *		-1 en cas d'erreur et code erreur dans err_val
 */
WORD im_open(name, mode)
BYTE *name;
WORD mode;
{
	register i;			/* compteur de boucles		*/

	/* recherche d'une structure de description disponible */
	for (i = 1; i < NB_IMPRIMANTE; i++)
		if (imprimante[i] == NULL)
			break;
	if (i == NB_IMPRIMANTE) {
		err_val =  1;
		return (-1);
	}
	prnfid = i;

	/* ouverture de l'imprimante */
	return (_lo_open(name, mode));
}


/* fermeture d'un imprimante
 * -------------------------
 *
 * appel:	rien (prnfid doit etre positionne)
 *
 * retour:	rien
 *
 */
VOID im_close()
{
	_lo_close();
}


/************************************************************************
 *									*
 *	Primitives internes de gestion ecran				*
 *									*
 ***********************************************************************/

/* edition d'un chaine sur ecran
 * -----------------------------
 *
 * appel:	caractere a editer
 *
 * retour:	rien
 *
 */
VOID _co_chaine(chaine, longueur)
BYTE *chaine;
WORD longueur;
{
	while (longueur--)
		_co(*(chaine++));
}


/* edition d'un caractere sur ecran
 * --------------------------------
 *
 * appel:	caractere a editer
 *
 * retour:	rien
 *
 */
VOID _co(c)
WORD c;
{
	register i, j;
	static WORD nb_transparent;
	WORD old_prnfid;

#ifdef CICO_BDA
	if (redir_CO == TRUE) {
		if (flag_buf == TRUE) {
			if (out_nb >= DIM_OUT_BUF) {
				BYTE type[2];
				VOID *argument[2];
				WORD taille[2];

				type[0] = TYPE_CHAINE;
				type[1] = TYPE_WORD;
				argument[0] = (VOID *)out_buf;
				argument[1] = (VOID *)&out_nb;
				taille[0] = out_nb;
				taille[1] = 2;

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_MES):%d:BUFF\n",out_nb);
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

				CallRunTime(redir.cico.numero,
					    redir.cico.fonction[CICO_MES],
					    2, type, argument, taille);
				out_nb = 0;
			}
			*(out_buf + out_nb++) = (BYTE)c;
		} else {
			BYTE type[1];
			VOID *argument[1];
			WORD taille[1];

			type[0] = TYPE_WORD;
			argument[0] = (VOID *)&c;
			taille[0] = 2;

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_CO)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

			CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_CO],
				    1, type, argument, taille);
		}
		return;
	}
#endif /*fin CICO_BDA*/

/* XCICO actif */
	if ( XCICO_nbl != 0 ) {
		write(STDOUT, &c, 1);
	}
/***************/
	switch (courant->etat) {
	case ETAT_STANDARD:
		if (c >= ' ' && c <= 0x7f) {            /* caractere ASCII */
			_co_car(c);
		} else if (c == ESC) {			/* debut seq. escape */
			courant->etat = ETAT_ESCAPE;
		} else if (c == PRL_RIGHT) {		/* curseur droit */
			if (courant->colonne == max_colonne) {
				courant->colonne = 0;
				if (courant->ligne == max_ligne)
					courant->ligne = 0;
				else
					courant->ligne++;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->colonne++;
				_co_capacite(CURSOR_RIGHT);
			}
		} else if (c == PRL_LEFT) {		/* curseur gauche */
			if (courant->colonne == 0) {
				courant->colonne = max_colonne;
				if (courant->ligne == 0)
					courant->ligne = max_ligne;
				else
					courant->ligne--;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->colonne--;
				_co_capacite(CURSOR_LEFT);
			}
		} else if (c == PRL_UP) {		/* curseur haut */
			if (courant->ligne == 0) {
				courant->ligne = max_ligne;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->ligne--;
				_co_capacite(CURSOR_UP);
			}
		} else if (c == PRL_DOWN) {		/* curseur bas */
			if (courant->ligne == max_ligne) {
				courant->ligne = 0;
				_co_pos(courant->ligne, courant->colonne);
			} else {
				courant->ligne++;
				_co_capacite(CURSOR_DOWN);
			}
		} else if (c == PRL_HOME) {		/* home */
			courant->ligne = courant->colonne = 0;
			_co_pos(courant->ligne, courant->colonne);
		} else if (c == PRL_CLEAR) {		/* clear */
			courant->ligne = courant->colonne = 0;
			_co_clear();
		} else if (c == CR) {			/* carriage return */
			courant->colonne = 0;
			_co_out(CR);
		} else if (c == LF) {			/* line feed */
			if (flag_scroll == TRUE) {
				if (courant->ligne == max_ligne)
					_co_scroll();
				else
					courant->ligne++;
/* 29/10/92:DLR */
				if ( flag_couleur == FALSE ) {	
					_co_reset_attribut();
					_co_out(LF);
					_co_set_attribut();
				} else {
					if (courant->ligne == max_ligne) {
#ifdef SOL1
						int offset;
						/* couleur caractere suivant */
						offset = courant->ligne * nb_colonne + courant->colonne;
						_co_couleur_texte(*(courant->image.texte + offset));
						_co_couleur_fond(*(courant->image.fond + offset));
						_co_out(LF);
						/* couleur caractere courant */
						_co_couleur_texte(courant->texte);
						_co_couleur_fond(courant->fond);
#else
						/* couleur noire de fond */
#ifdef ABALCONF
						_co_couleur_fond(courant->def_back);
#else
						_co_couleur_fond(C_BLACK);
#endif /* ABALCONF */
						_co_out(LF);
						/* couleur caractere courant */
						_co_couleur_fond(courant->fond);
#endif /* SOL1 */
					} else {
						_co_out(LF);
					}
				} 
/* 29/10/92:DLR */
			} else {
				if (courant->ligne == max_ligne)
					courant->ligne = 0;
				else
					courant->ligne++;
				_co_pos(courant->ligne, courant->colonne);
			}
		} else if (c == HT) {			/* horizontal tab */
			courant->colonne = (courant->colonne / 8 + 1) * 8;
			if (flag_scroll == TRUE) {
				if (courant->colonne > max_colonne) {
					courant->colonne -= nb_colonne;
					if (courant->ligne == max_ligne) {
/* 29/10/92:DLR */
						if ( flag_couleur == TRUE ) {
#ifdef SOL1
							int offset;
							/* couleur caractere suivant */
							offset = courant->ligne * nb_colonne + courant->colonne;
							_co_couleur_texte(*(courant->image.texte + offset));
							_co_couleur_fond(*(courant->image.fond + offset));
							_co_out(LF);
							/* couleur caractere courant */
							_co_couleur_texte(courant->texte);
							_co_couleur_fond(courant->fond);
#else
#ifdef ABALCONF
							_co_couleur_fond(courant->def_back);
#else
							/* couleur noire de fond */
							_co_couleur_fond(C_BLACK);
#endif /* ABALCONF */
							_co_out(LF);
							/* couleur caractere courant */
							_co_couleur_fond(courant->fond);
#endif /* SOL1 */
						} else {
							_co_reset_attribut();
							_co_out(LF);
							_co_set_attribut();
						}
/* 29/10/92:DLR */
						_co_scroll();
					} else
						courant->ligne++;
				}
			} else {
				if (courant->colonne > max_colonne) {
					courant->colonne -= nb_colonne;
					if (courant->ligne == max_ligne)
						courant->ligne = 0;
					else
						courant->ligne++;
				}
			}
			_co_pos(courant->ligne, courant->colonne);
	} else if (c == BEL) {			/* bell */
			_co_out(BEL);
		} else if (c > ' ') {
			_co_car(c);
		}
		break; /* de ETAT_STANDARD */
	case ETAT_POS_1:
		courant->etat = ETAT_POS_2;
		if ((BYTE)c != 0xff) {
			courant->colonne = c - 0x20;
			if (courant->colonne > max_colonne)
				courant->colonne = max_colonne;
		}
		break;
	case ETAT_POS_2:
		courant->etat = ETAT_STANDARD;
		if ((BYTE)c != 0xff) {
			courant->ligne = c - 0x20;
			if (courant->ligne > max_ligne)
				courant->ligne = max_ligne;
		}
		_co_pos(courant->ligne, courant->colonne);
		break;
	case ETAT_ESCAPE:
		courant->etat = ETAT_STANDARD;
		switch (c) {
		case ESC:
			courant->etat = ETAT_ESCAPE_ESCAPE;
			break;
		case 'f':               /* positionnement curseur */
			courant->etat = ETAT_POS_1;
			break;
		case 'T':               /* mode transparent */
			courant->etat = ETAT_TRANS_1;
			break;
		case 'n':               /* couleur defaut */
			courant->etat = ETAT_DEFAUT;
			break;
		case 'r':               /* couleur caractere */
			courant->etat = ETAT_TEXTE;
			break;
		case 's':               /* couleur fond */
			courant->etat = ETAT_FOND;
			break;
		case 'a':               /* visualisation normale */
			_co_attribut(courant->attribut = A_NORMAL);
			courant->jeu = NO_CASE;
			break;
		case 'b':               /* inversion video */
			_co_attribut(courant->attribut = A_REVERSE);
			break;
		case 'c':               /* clignotement */
			_co_attribut(courant->attribut = A_BLINK);
			break;
		case 'd':               /* soulignement  */
			_co_attribut(courant->attribut = A_UNDERLINE);
			break;
		case 'e':               /* sous_brillance */
			_co_attribut(courant->attribut = A_DIM);
			break;
		case 'h':               /* sur_brillance */
			_co_attribut(courant->attribut = A_BOLD);
			break;
		case 'i':               /* transcodage min/MAJ */
			courant->jeu = UPPER_CASE;
			break;
		case 'j':               /* transcodage MAJ/min */
			courant->jeu = LOWER_CASE;
			break;
		case 'p':               /* attribut preferentiel */
			_co_attribut(courant->attribut = A_STANDOUT);
			break;
		case 'J':               /* effacement fin de page */
			_co_clear_eos();
			break;
		case 'K':               /* effacement fin de ligne */
			_co_clear_eol();
			break;
		case 'L':               /* insertion de ligne */
			_co_ins_line();
			break;
		case 'M':               /* suppression de ligne */
			_co_del_line();
			break;
		case '@':               /* insertion caractere */
			_co_ins_character();
			break;
		case 'O':               /* hard copy */
			old_prnfid = prnfid;
			prnfid = 0;
			for (i = 0; i < nb_ligne; i++) {
				for (j = 0; j < nb_colonne; j++)
					_lo_conv(*(courant->image.caractere +
						  i * nb_colonne + j));
				_lo_out(CR);
				_lo_out(LF);
			}
			_lo_close();
			prnfid = old_prnfid;
			break;
		case 'P':               /* suppression caractere */
			_co_del_character();
			break;
		case 'v':               /* allumage curseur */
			_co_cursor(TRUE);
			break;
		case 'w':               /* extinction curseur */
			_co_cursor(FALSE);
			break;
		case '>':               /* push ecran */
			_co_push();
			break;
		case '<':               /* pop ecran */
			_co_pop();
			break;
		case 'u':               /* mode page */
			flag_scroll = FALSE;
			break;
		case 't':               /* mode scroll */
			flag_scroll = TRUE;
			break;
		}
		break;		/* fin de ETAT_ESCAPE */
	case ETAT_TRANS_1:
		courant->etat = ETAT_TRANS_2;
		nb_transparent = c;
		break;
	case ETAT_TRANS_2:
		courant->etat = ETAT_TRANS_3;
		nb_transparent += 256 * c;
		break;
	case ETAT_TRANS_3:
		_co_out(c);
		if (--nb_transparent == 0)
			courant->etat = ETAT_STANDARD;
		break;
	case ETAT_DEFAUT:
		if (flag_couleur == TRUE) {
			if (c >= '0' && c <= '9')
#ifdef ABALCONF
			{
				_co_couleur_texte(courant->texte = courant->def_char = c - '0');
				_co_couleur_fond(courant->def_back);
			}
#else
				_co_couleur_texte(courant->texte = courant->defaut = c - '0');
#endif /* ABALCONF */
			else if (c >= 'A' && c <= 'F')
#ifdef ABALCONF
			{
				_co_couleur_texte(courant->texte = courant->def_char = c - 'A' + 10);
				_co_couleur_fond(courant->def_back);
			}
#else
				_co_couleur_texte(courant->texte = courant->defaut = c - 'A' + 10);
#endif /* ABALCONF */
		}
		courant->etat = ETAT_STANDARD;
		break;
	case ETAT_TEXTE:
		if (flag_couleur == TRUE)
			if (c >= '0' && c <= '9')
				_co_couleur_texte(courant->texte = c - '0');
			else if (c >= 'A' && c <= 'F')
				_co_couleur_texte(courant->texte = c - 'A' + 10);
		courant->etat = ETAT_STANDARD;
		break;
	case ETAT_FOND:
		if (flag_couleur == TRUE)
			if (c >= '0' && c <= '7')
				_co_couleur_fond(courant->fond = c - '0');
		courant->etat = ETAT_STANDARD;
		break;
	case ETAT_ESCAPE_ESCAPE:
		courant->etat = ETAT_STANDARD;
		break;
	}
}


/* ajout d'un caractere avec son attribut
 * --------------------------------------
 *
 * appel:	caractere
 *		attribut
 *		couleur
 *
 * retour:	rien
 *
 */
VOID _co_car(c)
WORD c;
{
	register offset;

	if (flag_scroll == TRUE) {
		if (courant->colonne == max_colonne) {
			courant->colonne = 0;
			if (courant->ligne == max_ligne) {
/* 29/10/92:DLR */
				if ( flag_couleur == TRUE ) {
#ifdef SOL1
						int offset;
						/* couleur caractere suivant */
						offset = courant->ligne * nb_colonne + courant->colonne;
						_co_couleur_texte(*(courant->image.texte + offset));
						_co_couleur_fond(*(courant->image.fond + offset));
						_co_out(LF);
						/* couleur caractere courant */
						_co_couleur_texte(courant->texte);
						_co_couleur_fond(courant->fond);
#else
#ifdef ABALCONF
						_co_couleur_fond(courant->def_back);
#else
						/* couleur noire de fond */
						_co_couleur_fond(C_BLACK);
#endif /* ABALCONF */
						_co_out(LF);
						/* couleur caractere courant */
						_co_couleur_fond(courant->fond);
#endif /* SOL1 */
				} else {
					_co_reset_attribut();
					_co_out(LF);
					_co_set_attribut();
				}
/* 29/10/92:DLR */
				_co_out(CR);
				_co_pos(courant->ligne - 1, max_colonne);
				_co_conv(c);
				_co_pos(courant->ligne, courant->colonne);
				_co_scroll();
			} else {
				courant->ligne++;
				_co_conv(c);
				_co_pos(courant->ligne, courant->colonne);
			}
		} else {
			courant->colonne++;
			_co_conv(c);
		}
	} else {
		if (courant->colonne == max_colonne) {
			courant->colonne = 0;
			if (courant->ligne == max_ligne)
				courant->ligne = 0;
			else {
				courant->ligne++;
				_co_conv(c);
			}
			_co_pos(courant->ligne, courant->colonne);
		} else {
			courant->colonne++;
			_co_conv(c);
		}
	}

	/* ecriture dans l'image */
	offset = courant->ligne * nb_colonne + courant->colonne - 1;
	*(courant->image.caractere + offset) = (BYTE)c;
	*(courant->image.attribut + offset) = courant->attribut;
	if (flag_couleur == TRUE) {
		*(courant->image.texte + offset) = courant->texte;
		*(courant->image.fond + offset) = courant->fond;
	}
}


/* affichage d'un caractere 8 bits
 * -------------------------------
 *
 * appel:	le caractere
 *
 * retour:	rien
 *
 */
VOID _co_conv(c)
WORD c;
{
	BYTE *bp;

	c &= 0x00FF;

	if (courant->jeu != NO_CASE)
		c = mima(c, (WORD)courant->jeu);
	if (strchr(CHAR_SECOND, c) != NULL) {
		enter_second();
	} else {
		exit_second();
	}
	if (tab_out[(unsigned)c] == 0) {
		bp = term_str[COMP_FIRST + (unsigned)c];
		while (*bp != '\0')
			_co_out(*bp++);
	} else
		_co_out(tab_out[(unsigned)c]);
}


/* positionnement curseur
 * ----------------------
 *
 * appel:	ligne et colonne (origine en 0, 0)
 *
 * retour:	rien
 *
 */
VOID _co_pos(ligne, colonne)
WORD ligne;
WORD colonne;
{
	_co_capacite(CURSOR_ADR_BEG);
	_co_sequence(CURSOR_ADR_P1, ligne, colonne);
	_co_capacite(CURSOR_ADR_MID);
	_co_sequence(CURSOR_ADR_P2, ligne, colonne);
	_co_capacite(CURSOR_ADR_END);
}


/* allumage / extinction curseur
 * -----------------------------
 *
 * appel:	TRUE pour allumage
 *		FALSE pour extinction
 *
 * retour:	rien
 *
 */
VOID _co_cursor(flag)
BOOL flag;
{
	if (flag == TRUE) {
		flag_curseur = TRUE;
		_co_capacite(CURSOR_NORMAL);
	} else {
		flag_curseur = FALSE;
		_co_capacite(CURSOR_INVIS);
	}
}


/* reset des attributs et des couleurs
 * -----------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_reset_attribut()
{
	_co_capacite(EXIT_ATTRIBUTE);
	if (flag_couleur == TRUE)
#ifdef ABALCONF
		_co_couleur_fond(courant->def_back);
#else
		_co_capacite(BACKGR_0);
#endif /* ABALCONF */
}


/* reset des attributs et des couleurs
 * -----------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_set_attribut()
{
	if (flag_couleur == TRUE) {
		_co_couleur_texte(courant->texte);
		_co_couleur_fond(courant->fond);
	}
	if (courant->attribut != A_NORMAL)
		_co_attribut(courant->attribut);
}


/* positionnement d'attribut
 * -------------------------
 *
 * appel:	numero d'attribut (numerotation BAL)
 *
 * retour:	rien
 *
 */
VOID _co_attribut(attribut)
WORD attribut;
{
	switch (attribut) {
	case A_NORMAL:
		_co_capacite(EXIT_ATTRIBUTE);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			_co_couleur_texte(courant->texte = courant->def_char);
			_co_couleur_fond(courant->fond = courant->def_back);
#else
			_co_couleur_texte(courant->texte = courant->defaut);
			_co_couleur_fond(courant->fond = C_BLACK);
#endif /* ABALCONF */
		}
		break;
	case A_STANDOUT:
		if (flag_couleur == TRUE)
			_co_couleur_texte(courant->texte = C_YELLOW);
		else
			_co_capacite(ENTER_STANDOUT);
		break;
	case A_UNDERLINE:
		if (flag_couleur == TRUE)
			_co_couleur_texte(courant->texte = C_LIGHT_CYAN);
		else
			_co_capacite(ENTER_UNDERLINE);
		break;
	case A_REVERSE:
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			_co_couleur_texte(courant->texte = courant->def_back);
			_co_couleur_fond(courant->fond = courant->def_char);
#else
			_co_couleur_texte(courant->texte = C_BLACK);
			_co_couleur_fond(courant->fond = courant->defaut);
#endif /* ABALCONF */
		} else
			_co_capacite(ENTER_REVERSE);
		break;
	case A_BLINK:
		_co_capacite(ENTER_BLINK);
		break;
	case A_BOLD:
		if (flag_couleur == TRUE) {
			if (courant->texte < C_GREY)
				_co_couleur_texte(courant->texte += C_GREY);
		} else
			_co_capacite(ENTER_BOLD);
		break;
	case A_DIM:
		if (flag_couleur == TRUE) {
			if (courant->texte >= C_GREY)
				_co_couleur_texte(courant->texte -= C_GREY);
		} else
			_co_capacite(ENTER_DIM);
	}
}


/* positionnement de couleur de texte
 * ----------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_couleur_texte(couleur)
WORD couleur;
{
	switch (couleur) {
	case C_BLACK:
		_co_capacite(FOREGR_0);
		break;
	case C_RED:
		_co_capacite(FOREGR_1);
		break;
	case C_GREEN:
		_co_capacite(FOREGR_2);
		break;
	case C_BROWN:
		_co_capacite(FOREGR_3);
		break;
	case C_BLUE:
		_co_capacite(FOREGR_4);
		break;
	case C_MAGENTA:
		_co_capacite(FOREGR_5);
		break;
	case C_CYAN:
		_co_capacite(FOREGR_6);
		break;
	case C_WHITE:
		_co_capacite(FOREGR_7);
		break;
	case C_GREY:
		_co_capacite(FOREGR_8);
		break;
	case C_LIGHT_RED:
		_co_capacite(FOREGR_9);
		break;
	case C_LIGHT_GREEN:
		_co_capacite(FOREGR_A);
		break;
	case C_YELLOW:
		_co_capacite(FOREGR_B);
		break;
	case C_LIGHT_BLUE:
		_co_capacite(FOREGR_C);
		break;
	case C_LIGHT_MAGENTA:
		_co_capacite(FOREGR_D);
		break;
	case C_LIGHT_CYAN:
		_co_capacite(FOREGR_E);
		break;
	case C_INTENSE_WHITE:
		_co_capacite(FOREGR_F);
	}
#ifdef NPOS_VERSION_7
	if (courant->attribut == A_BLINK)
		_co_capacite(ENTER_BLINK);
		
#endif
}


/* positionnement de couleur de fond
 * ---------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_couleur_fond(couleur)
WORD couleur;
{
	switch (couleur) {
	case C_BLACK:
		_co_capacite(BACKGR_0);
		break;
	case C_RED:
		_co_capacite(BACKGR_1);
		break;
	case C_GREEN:
		_co_capacite(BACKGR_2);
		break;
	case C_BROWN:
		_co_capacite(BACKGR_3);
		break;
	case C_BLUE:
		_co_capacite(BACKGR_4);
		break;
	case C_MAGENTA:
		_co_capacite(BACKGR_5);
		break;
	case C_CYAN:
		_co_capacite(BACKGR_6);
		break;
	case C_WHITE:
		_co_capacite(BACKGR_7);
	}
#ifdef NPOS_VERSION_7
	if (courant->attribut == A_BLINK)
		_co_capacite(ENTER_BLINK);
#endif
}


/* effacement d'ecran
 * ------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_clear()
{
	image_st *image;
	int longueur;

	_co_reset_attribut();
	_co_capacite(CLEAR_SCREEN);
	_co_set_attribut();
	image = &courant->image;
	longueur = nb_ligne * nb_colonne;
	memset(image->caractere, ' ', longueur);
	memset(image->attribut, A_NORMAL, longueur);
	if (flag_couleur == TRUE) {
#ifdef ABALCONF
		memset(image->texte, courant->def_char, longueur);
		memset(image->fond, courant->def_back, longueur);
#else
		memset(image->texte, courant->defaut, longueur);
		memset(image->fond, C_BLACK, longueur);
#endif /* ABALCONF */
	}
#ifdef ABALCONF
	courant->texte = courant->def_char;
	courant->fond = courant->def_back;
#else
	courant->texte = courant->defaut;
	courant->fond = C_BLACK;
#endif /* ABALCONF */
}


/* effacement fin de page
 * ----------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_clear_eos()
{
	image_st *image;
	int longueur;
	int offset;

	if (*CLEAR_EOS != '\0') {
		exit_second();
		_co_reset_attribut();
		_co_capacite(CLEAR_EOS);
		_co_set_attribut();
		_co_pos(courant->ligne, courant->colonne);
		image = &courant->image;
		longueur = (nb_ligne - courant->ligne) * nb_colonne -
			   courant->colonne;
		offset = courant->ligne * nb_colonne + courant->colonne;
		memset(image->caractere + offset, ' ', longueur);
		memset(image->attribut + offset, A_NORMAL, longueur);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + offset,
			       courant->def_char, longueur);
			memset(image->fond + offset,
			       courant->def_back, longueur);
#else
			memset(image->texte + offset,
			       courant->defaut, longueur);
			memset(image->fond + offset,
			       C_BLACK, longueur);
#endif /* ABALCONF */
		}
	}
}


/* effacement fin de ligne
 * -----------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_clear_eol()
{
	image_st *image;
	int longueur;
	int offset;

	if (*CLEAR_EOL != '\0') {
		exit_second();
		_co_reset_attribut();
		_co_capacite(CLEAR_EOL);
		_co_set_attribut();
		image = &courant->image;
		longueur = nb_colonne - courant->colonne;
		offset = courant->ligne * nb_colonne + courant->colonne;
		memset(image->caractere + offset, ' ', longueur);
		memset(image->attribut + offset, A_NORMAL, longueur);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + offset, courant->def_char,
			       longueur);
			memset(image->fond + offset, courant->def_back, longueur);
#else
			memset(image->texte + offset, courant->defaut,
			       longueur);
			memset(image->fond + offset, C_BLACK, longueur);
#endif /* ABALCONF */
		}
	}
}


/* insertion de ligne
 * ------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_ins_line()
{
	image_st *image;
	register i;
	int source, destination;

	if (*INSERT_LINE != '\0') {
		_co_reset_attribut();
		_co_capacite(INSERT_LINE);
		_co_set_attribut();
		image = &courant->image;
		for (i = max_ligne ; i > courant->ligne; i--) {
			destination = i * nb_colonne;
			source = destination - nb_colonne;
			memcpy(image->caractere + destination,
			       image->caractere + source, nb_colonne);
			memcpy(image->attribut + destination,
			       image->attribut + source, nb_colonne);
			if (flag_couleur == TRUE) {
				memcpy(image->texte + destination,
				       image->texte + source, nb_colonne);
				memcpy(image->fond + destination,
				       image->fond + source, nb_colonne);
			}
		}
		destination = courant->ligne * nb_colonne;
		memset(image->caractere + destination , ' ', nb_colonne);
		memset(image->attribut + destination, A_NORMAL, nb_colonne);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + destination,
			       courant->def_char, nb_colonne);
			memset(image->fond + destination,
			       courant->def_back, nb_colonne);
#else
			memset(image->texte + destination,
			       courant->defaut, nb_colonne);
			memset(image->fond + destination,
			       C_BLACK, nb_colonne);
#endif /* ABALCONF */
		}
		courant->colonne = 0;
		_co_out(CR);
	}
}


/* suppression de ligne
 * --------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_del_line()
{
	image_st *image;
	int source, destination;
	int longueur;

	if (*DELETE_LINE != '\0') {
		_co_reset_attribut();
		_co_capacite(DELETE_LINE);
		_co_set_attribut();
		image = &courant->image;
		destination = courant->ligne * nb_colonne;
		source = (courant->ligne + 1) * nb_colonne;
		longueur = (max_ligne - courant->ligne) * nb_colonne;
		memcpy(image->caractere + destination,
		       image->caractere + source, longueur);
		memcpy(image->attribut + destination,
		       image->attribut + source, longueur);
		if (flag_couleur == TRUE) {
			memcpy(image->texte + destination,
			       image->texte + source, longueur);
			memcpy(image->fond + destination,
			       image->fond + source, longueur);
		}
		destination = max_ligne * nb_colonne;
		longueur = nb_colonne;
		memset(image->caractere + destination, ' ', longueur);
		memset(image->attribut + destination, A_NORMAL, longueur);
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			memset(image->texte + destination,
			       courant->def_char, longueur);
			memset(image->fond + destination,
			       courant->def_back, longueur);
#else
			memset(image->texte + destination,
			       courant->defaut, longueur);
			memset(image->fond + destination,
			       C_BLACK, longueur);
#endif /* ABALCONF */
		}
		courant->colonne = 0;
		_co_out(CR);
	}
}


/* insertion caractere
 * -------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_ins_character()
{
	image_st *image;
	int longueur;
	int destination;

	if (*INSERT_CHAR != '\0') {
		_co_reset_attribut();
		_co_capacite(INSERT_CHAR);
		_co_set_attribut();
		image = &courant->image;
		destination = courant->ligne * nb_colonne + max_colonne;
		longueur = nb_colonne - courant->colonne;
		while (longueur-- > 0) {
			*(image->caractere + destination + 1) =
			*(image->caractere + destination);
			*(image->attribut + destination + 1) =
			*(image->attribut + destination);
			if (flag_couleur == TRUE) {
				*(image->texte + destination + 1) =
				*(image->texte + destination);
				*(image->fond + destination + 1) =
				*(image->fond + destination);
			}
			destination--;
		}
		destination = courant->ligne * nb_colonne + courant->colonne;
		*(image->caractere + destination) = ' ';
		*(image->attribut + destination) = A_NORMAL;
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			*(image->texte + destination) = courant->def_char;
			*(image->fond + destination) = courant->def_back;
#else
			*(image->texte + destination) = courant->defaut;
			*(image->fond + destination) = C_BLACK;
#endif /* ABALCONF */
		}
	}
}


/* suppression caractere
 * ---------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_del_character()
{
	image_st *image;
	int source, destination;
	int longueur;

	if (*DELETE_CHAR != '\0') {
		_co_reset_attribut();
		_co_capacite(DELETE_CHAR);
		_co_set_attribut();
		image = &courant->image;
		destination = courant->ligne * max_colonne + courant->colonne;
		source = destination + 1;
		longueur = max_colonne - courant->colonne;
		memcpy(image->caractere + destination,
		       image->caractere + source, longueur);
		memcpy(image->attribut + destination,
		       image->attribut + source, longueur);
		if (flag_couleur == TRUE) {
			memcpy(image->texte + destination,
			       image->texte + source, longueur);
			memcpy(image->fond + destination,
			       image->fond + source, longueur);
		}
		destination = courant->ligne * nb_colonne + max_colonne;
		*(image->caractere + destination) = ' ';
		*(image->attribut + destination) = A_NORMAL;
		if (flag_couleur == TRUE) {
#ifdef ABALCONF
			*(image->texte + destination) = courant->def_char;
			*(image->fond + destination) = courant->def_back;
#else
			*(image->texte + destination) = courant->defaut;
			*(image->fond + destination) = C_BLACK;
#endif /* ABALCONF */
		}
	}
}


/* envoi d'une sequence parametrable (ligne ou colonne)
 * ----------------------------------------------------
 *
 * appel:	sequence a envoyer
 *		numero de ligne
 *		numero de colonne
 *
 * retour:	rien
 *
 */
VOID _co_sequence(chaine, y, x)
BYTE *chaine;
WORD y, x;
{
	WORD c;

	while (TRUE) {
		if (*chaine == 'C')
			c = x;
		else if (*chaine == 'L')
			c = y;
		else if (*chaine == '+')
			c += *++chaine;
		else if (*chaine == '-')
			c -= *++chaine;
		else if (*chaine == 'D') {
			if (c / 100 > 0)
				_co_out(c / 100 + '0');
			if ((c % 100) / 10 > 0)
				_co_out((c % 100) / 10 + '0');
			_co_out(c % 10 + '0');
			break;
		} else if (*chaine == 'H') {
			if (c / 16 > 9)
				_co_out(c / 16 + 'A');
			else if (c / 16 > 0)
				_co_out(c / 16 + '0');
			c = c % 16;
			if (c < 10)
				_co_out(c + '0');
			else
				_co_out(c + 'A');
			break;
		} else if (*chaine == '\0') {
			_co_out(c);
			break;
		}
		chaine++;
	}
}


/* affichage physique d'un caractere sur ecran
 * -------------------------------------------
 *
 * appel:	caractere a envoyer
 *
 * retour:	rien
 *
 */
VOID _co_out(cx)
WORD cx;
{
BYTE c;
c=(BYTE) cx;
if (XCICO_nbl != 0) {	
	if (flag_buf == TRUE) {
		if (out_nb >= DIM_OUT_BUF) {
			out_nb = 0;
		}
		*(out_buf + out_nb++) = (BYTE) c;
	}
	return;
}
#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

	if (flag_buf == TRUE) {
		if (out_nb >= DIM_OUT_BUF) {

#ifdef CICO_DEBUG
		fprintf(DEBUG,"_CO_OUT:BUF:%d\n",out_nb);	
#endif /* fin CICO_DEBUG */

#ifdef vms
			if (vms$write(STDOUT, out_buf, (unsigned)out_nb) == -1)
#else
			if (write(STDOUT, out_buf, (unsigned)out_nb) == -1)
#endif /* vms */
				err_val = 1;	/* erreur */
			out_nb = 0;
		}
		*(out_buf + out_nb++) = (BYTE)c;
	} else {
#ifdef vms
		if (vms$write(STDOUT, &c, 1) == -1)
#else
#ifdef CICO_DEBUG
		fprintf(DEBUG,"_CO_OUT:%X\n",c);	
#endif /* fin CICO_DEBUG */
		if (write(STDOUT, &c, 1) == -1)
#endif /* vms */
			err_val = 1;	/* erreur */
	}
}


/* envoi d'une sequence fixe
 * -------------------------
 *
 * appel:	sequence a envoyer
 *
 * retour:	rien
 *
 */
VOID _co_capacite(chaine)
BYTE *chaine;
{
	while (*chaine)
		_co_out(*(chaine++));
}


/* scroll sur une ligne
 * --------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_scroll()
{
	image_st *image;
	BYTE *source, *destination;
	int longueur;

	image = &courant->image;

	/* remontee des premieres lignes */
	longueur = max_ligne * nb_colonne;
	destination = image->caractere;
	source = destination + nb_colonne;
	memcpy(destination, source, longueur);
	destination = image->attribut;
	source = destination + nb_colonne;
	memcpy(destination, source, longueur);
	if (flag_couleur == TRUE) {
		destination = image->texte;
		source = destination + nb_colonne;
		memcpy(destination, source, longueur);
		destination = image->fond;
		source = destination + nb_colonne;
		memcpy(destination, source, longueur);
	}

	/* effacement de la derniere ligne */
	longueur = nb_colonne;
	destination = image->caractere + max_ligne * nb_colonne;
	memset(destination, ' ', longueur);
	destination = image->attribut + max_ligne * nb_colonne;
	memset(destination, A_NORMAL, longueur);
	if (flag_couleur == TRUE) {
#ifdef ABALCONF
		destination = image->texte + max_ligne * nb_colonne;
		memset(destination, courant->def_char, longueur);
		destination = image->fond + max_ligne * nb_colonne;
		memset(destination, courant->def_back, longueur);
#else
		destination = image->texte + max_ligne * nb_colonne;
		memset(destination, courant->defaut, longueur);
		destination = image->fond + max_ligne * nb_colonne;
		memset(destination, C_BLACK, longueur);
#endif /* ABALCONF */
	}
}


/* push ecran
 * ----------
 *
 * appel:	rien
-ncouran *
 * retour:	rien
 *
 */
VOID _co_push()
{
	int longueur;
	ecran_st *temp;

	if ((temp = (ecran_st *)allocate(sizeof(ecran_st)))
	     == NULL) {
		err_val = 27;
		return;
	}
	*temp = *courant;
	longueur = nb_colonne * nb_ligne;
	if ((temp->image.caractere = (BYTE *)allocate(longueur)) == NULL ||
	    (temp->image.attribut = (BYTE *)allocate(longueur)) == NULL) {
		err_val = 27;
		return;
	}
	memcpy(temp->image.caractere, courant->image.caractere, longueur);
	memcpy(temp->image.attribut, courant->image.attribut, longueur);
	if (flag_couleur == TRUE) {
		if ((temp->image.texte = (BYTE *)allocate(longueur)) == NULL ||
		    (temp->image.fond = (BYTE *)allocate(longueur)) == NULL) {
			err_val = 27;
			return;
		}
		memcpy(temp->image.texte, courant->image.texte, longueur);
		memcpy(temp->image.fond, courant->image.fond, longueur);
	}
	temp->suite = courant->suite;
	courant->suite = temp;
}


/* pop ecran
 * ---------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID _co_pop()
{
	register i, j;
	int position;
	BOOL reposition = FALSE;
	BYTE precedent = A_NORMAL;
	BYTE texte_precedente = C_GREEN;
	BYTE fond_precedente = C_BLACK;
	BYTE caractere;
	BYTE attribut;
	BYTE texte;
	BYTE fond;
	image_st *image;
	ecran_st *ecran;


	image = &courant->suite->image;
	ecran = courant->suite;
	if (ecran == NULL)
		return;

/* 17/03 */

	if ( flag_finterm == TRUE ) {
		x_clear();
		flag_finterm = FALSE;
	}	

/* 17/03 */

	/* affichage de l'ecran en sommet de pile */
	_co_start();
	_co_attribut(A_NORMAL);
	if (flag_couleur == TRUE) {
		for (i = 0; i < nb_ligne; i++) {
			_co_pos(i, 0);
			for (j = 0; j < nb_colonne; j++) {
				position = i * nb_colonne + j;
				caractere = *(ecran->image.caractere + position);
				attribut = *(ecran->image.attribut + position);
				texte = *(ecran->image.texte + position);
				fond = *(ecran->image.fond + position);
				if (caractere != courant->image.caractere[position] || attribut != courant->image.attribut[position] || texte != courant->image.texte[position] || fond != courant->image.fond[position]) {
					if (reposition == TRUE) {
						_co_pos(i, j);
						reposition = FALSE;
					}
					if (precedent != attribut || texte_precedente != texte || fond_precedente != fond) {
						_co_attribut(A_NORMAL);
						_co_couleur_texte(texte);
						_co_couleur_fond(fond);
/*DLR:*/
/*
						if (attribut != A_NORMAL)
							_co_attribut(attribut);
*/
						if (attribut == A_BLINK)
							_co_attribut(attribut);
						precedent = attribut;
						texte_precedente = texte;
						fond_precedente = fond;
					}
					_co_conv(caractere);
				} else
					reposition = TRUE;
			}
		}
	} else {
		for (i = 0; i < nb_ligne; i++) {
			_co_pos(i, 0);
			for (j = 0; j < nb_colonne; j++) {
				position = i * nb_colonne + j;
				caractere = *(ecran->image.caractere + position);
				attribut = *(ecran->image.attribut + position);
				if (caractere != courant->image.caractere[position] || attribut != courant->image.attribut[position]) {
					if (reposition == TRUE) {
						_co_pos(i, j);
						reposition = FALSE;
					}
					if (precedent != attribut) {
						_co_attribut(A_NORMAL);
						_co_attribut(attribut);
						precedent = attribut;
					}
					_co_conv(caractere);
				} else
					reposition = TRUE;
			}
		}
	}
	_co_attribut(A_NORMAL);
	_co_flush();

	_co_pos(ecran->ligne, ecran->colonne);
	if (flag_couleur == TRUE) {
		_co_couleur_texte(ecran->texte);
		_co_couleur_fond(ecran->fond);
		if ( ecran->attribut == A_BLINK )
			_co_attribut(ecran->attribut);
	} else
		_co_attribut(ecran->attribut);

	/* liberation de l'ecran en sommet de pile */
	liberate((CHAR *)courant->image.caractere);
	liberate((CHAR *)courant->image.attribut);
	if (flag_couleur == TRUE) {
		liberate((CHAR *)courant->image.texte);
		liberate((CHAR *)courant->image.fond);
	}
	liberate((CHAR *)courant);
	courant = ecran;
}


/* position ligne
 * --------------
 *
 * appel:	WORD _co_ligne();
 *
 * retour:	position ligne sur l'ecran (origine en 0)
 *
 */
WORD _co_ligne()
{
#ifdef CICO_BDA
	if (redir_CO == TRUE) {

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_LIGNE)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

		return (CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_LIGNE],
				    0, NULL, NULL, NULL));
	}
#endif /* fin CICO_BDA */

	return (courant->ligne);
}


/* position colonne
 * ----------------
 *
 * appel:	WORD _co_colonne();
 *
 * retour:	position colonne sur l'ecran (origine en 0)
 *
 */
WORD _co_colonne()
{
#ifdef CICO_BDA
	if (redir_CO == TRUE) {

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_COLONNE)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

		return (CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_COLONNE],
				    0, NULL, NULL, NULL));
	}
#endif /* fin CICO_BDA */

	return (courant->colonne);
}


VOID _co_start()
{
	if (flag_buf == FALSE) {
		flag_buf = TRUE;
#ifdef CICO_BDA
		if (redir_CO == TRUE) {

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_START)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/
		
			CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_START],
				    0, NULL, NULL, NULL);
		}
#endif /* fin CICO_BDA */
	}
}


VOID _co_flush()
{

#ifdef CICO_BDA
	if (redir_CO == TRUE) {
		if (flag_buf == TRUE) {
			if (out_nb != 0) {
				BYTE type[2];
				VOID *argument[2];
				WORD taille[2];

				type[0] = TYPE_CHAINE;
				type[1] = TYPE_WORD;
				argument[0] = (VOID *)out_buf;
				argument[1] = (VOID *)&out_nb;
				taille[0] = out_nb;
				taille[1] = 2;

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_MES):%d:FLUSH\n",out_nb);
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

				CallRunTime(redir.cico.numero,
					    redir.cico.fonction[CICO_MES],
					    2, type, argument, taille);
				out_nb = 0;
			}

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_FLUSH)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

			CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_FLUSH],
				    0, NULL, NULL, NULL);
			flag_buf = FALSE;
		}
		return;
	}
#endif /* fin CICO_BDA */

	if (flag_buf == TRUE) {
		if (out_nb != 0) {
			if (XCICO_nbl == 0) {
#ifdef vms
				if (vms$write(STDOUT, out_buf, (unsigned)out_nb) == -1)
#else

#ifdef CICO_DEBUG
	fprintf(DEBUG,"_CO_FLUSH:%d\n",out_nb);
#endif /* fin CICO_DEBUG */

				if (write(STDOUT, out_buf, (unsigned)out_nb) == -1)
#endif /* vms */
					err_val = 1;	/* erreur */
			}
			out_nb = 0;
		}
		flag_buf = FALSE;
	}
}

/************************************************************************
 *									*
 *	Primitives internes de gestion imprimante			*
 *									*
 ***********************************************************************/


static VOID _lo_start()
{
	if (flag_buflo == FALSE) {
		flag_buflo = TRUE;
	}
}


static VOID _lo_flush()
{
	if (flag_buflo == TRUE) {
		if (out_nblo != 0) {
#ifdef CICO_DEBUG
	fprintf(DEBUG,"_LO_FLUSH:%d\n",out_nblo);
#endif /* fin CICO_DEBUG */
			if (write(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo)
				err_val = 1;	/* erreur */
			out_nblo = 0;
		}
		flag_buflo = FALSE;
	}
}


/* edition d'un caractere sur imprimante
 * -------------------------------------
 *
 * appel:	caractere a editer
 *
 * retour:	rien
 *
 */
VOID _lo(c)
WORD c;
{
	register i;
	WORD colonne;

	if (courante == NULL)
		if (prnfid == 0) {
			if (c == SUB)
				return;
			if (_lo_defaut() != 0)
				return;
		} else {
			if (c != SUB)
				err_val = 42;
			return;
		}
	switch (courante->etat) {
	case ETAT_STANDARD:
		switch (c) {
		case ESC:
			courante->etat = ETAT_ESCAPE;
			break;
#if EXABAL && !MPAGE
		case ACK:
			_lo_out(' ');
			courante->colonne++;
			break;
#endif /* EXABAL && !MPAGE */
		case BEL:
#if EXABAL && !MPAGE
			_co_out(BEL);
#else
			_lo_out(BEL);
#endif /* EXABAL && !MPAGE */
			break;
		case CR:
			_lo_out(CR);
			courante->colonne = 0;
			break;
		case LF:
			courante->ligne++;
			_lo_out(LF);
#if EXABAL && !MPAGE
			_lo_out(CR);
			courante->colonne = 0;
#endif /* EXABAL && !MPAGE */
			break;
		case BS:
			if (courante->colonne > 0)
				courante->colonne--;
			_lo_out(BS);
			break;
		case HT:
			colonne = (courante->colonne / 8 + 1) * 8;
			for (i = courante->colonne; i < colonne; i++)
				_lo_out(' ');
			courante->colonne = colonne;
			break;
		case FF:
			courante->ligne = courante->colonne = 0;
			_lo_out(FF);
#if EXABAL && !MPAGE
			_lo_out(CR);
#endif /* EXABAL && !MPAGE */
			break;
		case SUB:
#if EXABAL && !MPAGE
			if (courante->flag == TRUE) {
				_lo_out(CR);
#ifdef vms
				_lo_out(LF);
#endif /* vms */
			}
#endif /* EXABAL && !MPAGE */
			_lo_close();
			break;
#if EXABAL && !MPAGE
		case FS:
			_lo_out(FS);
			_lo_out(CR);
			break;
#endif /* EXABAL && !MPAGE */
		default:
			if (c >= ' ') {
				courante->colonne++;
				if (courante->jeu != NO_CASE)
					c = mima(c, courante->jeu);
				_lo_conv(c);
			}
		}
		break;
	case ETAT_ESCAPE:
		courante->etat = ETAT_STANDARD;
		switch (c) {
		case 'a':               /* fin de tous les attributs */
			_lo_tbl_attribut(3);
			_lo_tbl_attribut(5);
			_lo_tbl_attribut(9);
			_lo_tbl_attribut(11);
			_lo_tbl_attribut(13);
			_lo_tbl_attribut(25);
			_lo_tbl_attribut(27);
			courante->jeu = NO_CASE;
			break;
		case 'd':               /* souligne */
			_lo_tbl_attribut(4);
			break;
		case 'p':               /* preferentiel */
			_lo_tbl_attribut(2);
			break;
		case 'x':               /* compacte */
			_lo_tbl_attribut(24);
			break;
		case 'y':               /* penche */
			_lo_tbl_attribut(12);
			break;
		case 'z':               /* double largeur */
			_lo_tbl_attribut(26);
			break;
		case '<':               /* exposant */
			_lo_tbl_attribut(8);
			break;
		case '>':               /* indice */
			_lo_tbl_attribut(10);
			break;
		case 'i':               /* transcodage min/MAJ */
			courante->jeu = UPPER_CASE;
			break;
		case 'j':               /* transcodage MAJ/min */
			courante->jeu = LOWER_CASE;
			break;
		case 'T':               /* mode transparent */
			courante->etat = ETAT_TRANS_1;
		}
		break;
	case ETAT_TRANS_1:
		courante->etat = ETAT_TRANS_2;
		courante->nb_transparent = c;
		break;
	case ETAT_TRANS_2:
		courante->etat = ETAT_TRANS_3;
		courante->nb_transparent += c * 256;
		break;
	case ETAT_TRANS_3:
		_lo_out(c);
		if (--courante->nb_transparent == 0)
			courante->etat = ETAT_STANDARD;
	}
}


/* edition d'un caractere 8 bits
 * -----------------------------
 *
 * appel:	caractere a envoyer
 *
 * retour:	rien
 *
 */
static VOID _lo_conv(c)
BYTE c;
{
	register i;
	BYTE *p;
	BYTE longueur;

	if (courante == NULL)
		if (prnfid == 0) {
			if (_lo_defaut() != 0)
				return;
		} else {
			err_val = 42;
			return;
		}
	if (courante->tbl_table != NULL) {
		if (courante->tbl_table[c] == 0xff) {
			if ((p = (BYTE *)memchr(courante->tbl_tampon, c, courante->tbl_lg_tampon)) == NULL) {
				err_val = 1;
				return;
			}
			p++;
			longueur = *p;
			p++;
			while (longueur--)
				_lo_out(*p++);
			return;
		} else
			c = courante->tbl_table[c];
	}
	_lo_out(c);
}

/* edition physique d'un caractere sur imprimante
 * ----------------------------------------------
 *
 * appel:	caractere a envoyer
 *
 * retour:	rien
 *
 */

/* Modif : 28/10/91 */

#ifdef EXABAL
extern WORD sicico;
#endif /* EXABAL */

static VOID _lo_out(c)
BYTE c;
{
	if (courante == NULL)
		if (prnfid == 0) {
			if (_lo_defaut() != 0)
				return;
		} else {
			err_val = 42;
			return;
		}

	if (courante->flag == FALSE)
		courante->flag = TRUE;

#ifdef IMPLOC
	if ( courante->local == TRUE ) {
		if ( IMP_LOC_ACTIVE == FALSE ) {
			/* ouverture de l'imprimante locale */
			deb_imp_loc(courante->handle);
			/* activation de l'imprimante locale */
			IMP_LOC_ACTIVE=TRUE;
		}
	} else {
		if ( IMP_LOC_ACTIVE == TRUE ) {
			/* fermeture de l'imprimante locale */
			fin_imp_loc(courante->handle);
			/* desactivation de l'imprimante locale */
			IMP_LOC_ACTIVE=FALSE;
		}
	}
/* Modif : 28/10/91 - TEST du flag : ON ERROR GOTO ACTIF */

#ifdef EXABAL
	if ( flag_buflo == TRUE ) {
		if ( out_nblo >= DIM_OUT_BUF ) {
			if ( sicico & 0x0010 ) {
				/* On Error actif */
				if ( write(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo )
					err_val = 1;
			} else {
				while ( write(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo );
			}			
			out_nblo = 0;
		}
		*(out_buflo + out_nblo++) = c;
	} else {
		if ( sicico & 0x0010 ) {
			/* On Error actif */
			if (write(courante->handle, (CHAR *)&c, 1) != 1)
				err_val = 1;
		} else {
			while ( write(courante->handle, (CHAR *)&c, 1) != 1 );
		}
	}	
#else
	if ( flag_buflo == TRUE ) {
		if ( out_nblo >= DIM_OUT_BUF ) {
			if ( write(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo )
				err_val = 1;
			out_nblo = 0;
		}
		*(out_buflo + out_nblo++) = c;
	} else {
		if (write(courante->handle, (CHAR *)&c, 1) != 1)
			err_val = 1;
	}	
#endif /* EXABAL */

#else
	if (write(courante->handle, (CHAR *)&c, 1) != 1)
		err_val = 1;
#endif /*IMPLOC*/
	if ( (courante->sleep != 0) && (c == CR) && (courante->colonne != 0) ) 
		sleep(courante->sleep);
}

/* chargement d'un fichier tbl
 * ---------------------------
 *
 * appel:	nom du fichier tbl
 *
 * retour:	rien
 *
 */
static WORD _lo_tbl_charge(nom)
BYTE *nom;
{
	int fh = -1;			/* handle du fichier tbl	*/
	BYTE *complet;			/* nom complet du fichier tbl	*/
	BYTE entete[64];		/* entete du fichier tbl	*/
	BYTE mot[2];			/* mot de 16 bits		*/
	WORD longueur = 0;		/* longueur			*/
	WORD status = 0;		/* etat du chargement		*/

	/* constitution du nom complet */
	if (tbl_chemin != NULL) {
		longueur = strlen(tbl_chemin);
#ifndef vms
		if (*(tbl_chemin + longueur - 1) != '/')
			longueur++;
#endif /* vms */
	}
	if (strcmp(nom + strlen(nom) - 4, IMP_TBL_EXTENSION) != 0)
		longueur += 4;
	longueur += strlen(nom);
	if ((complet = (BYTE *)allocate(longueur + 1)) == NULL)
		return (27);
	if (tbl_chemin != NULL) {
		strcpy(complet, tbl_chemin);
#ifndef vms
		if (*(complet + strlen(complet) - 1) != '/')
			strcat(complet, "/");
#endif /* vms */
	} else
		*complet = '\0';
	strcat(complet, nom);
	if (strcmp(nom + strlen(nom) - 4, IMP_TBL_EXTENSION) != 0)
		strcat(complet, IMP_TBL_EXTENSION);

	/* ouverture du fichier et positionnment au debut */
#ifdef vms
	if ((fh = open(complet, O_RDONLY, 0, "shr=get")) == -1)
		return (1);
#else
#if EXABAL
	if (Access(complet, R_OK, 0) == -1)
#else
	if (access(complet, R_OK) == -1)
#endif /* EXABAL */
		return (1);
	fh = open(complet, O_RDONLY);
#endif /* vms */

	/* boucle de sortie avec erreur */
	while (TRUE) {

		/* lecture de l'entete */
		if (read(fh, (CHAR *)entete, sizeof(entete)) != sizeof(entete)) {
			status = 1;
			break;
		}

		/* verification de la signature */
		if (memcmp(entete, IMP_TBL_SIGNATURE, IMP_TBL_LONGUEUR_SIGNATURE) != 0) {
			status = 1;
			break;
		}

		/* allocation de la table des initialisations */
		longueur = entete[61];
		courante->tbl_lg_init = longueur;
		if ((courante->tbl_init = (BYTE *)allocate(3 * longueur)) == NULL) {
			status = 27;
			break;
		}

		/* lecuture de la table des initialisations */
		longueur = entete[46] + entete[47] * 256;
		if (lseek(fh, (LONG)longueur, SEEK_SET) != (LONG)longueur) {
			status = 1;
			break;
		}
		if (read(fh, (CHAR *)courante->tbl_init, 3 * courante->tbl_lg_init) != 3 * courante->tbl_lg_init) {
			status = 1;
			break;
		}

		/* allocation de la table des attributs */
		longueur = entete[60];
		courante->tbl_lg_attribut = longueur;
		if ((courante->tbl_attribut = (BYTE *)allocate(32 * longueur)) == NULL) {
			status = 27;
			break;
		}

		/* lecture de la table des attributs */
		longueur = entete[56] + entete[57] * 256;
		if (lseek(fh, (LONG)longueur, SEEK_SET) != (LONG)longueur) {
			status = 1;
			break;
		}
		if (read(fh, (CHAR *)courante->tbl_attribut, 32 * courante->tbl_lg_attribut) != 32 * courante->tbl_lg_attribut) {
			status = 1;
			break;
		}

		/* allocation de la table de conversion */
		if ((courante->tbl_table = (BYTE *)allocate(256)) == NULL) {
			status = 27;
			break;
		}

		/* lecture de la table de conversion */
		longueur = entete[58] + entete[59] * 256;
		if (lseek(fh, (LONG)longueur, SEEK_SET) != (LONG)longueur) {
			status = 1;
			break;
		}
		if (read(fh, (CHAR *)courante->tbl_table, 256) != 256) {
			status = 1;
			break;
		}

		/* lecture de la longueur du tampon de conversion */
		if (read(fh, mot, 2) != 2) {
			status = 1;
			break;
		}
		courante->tbl_lg_tampon = mot[0] + mot[1] * 256;

		/* allocation du tampon de conversion */
		if ((courante->tbl_tampon = (BYTE *)allocate(courante->tbl_lg_tampon)) == NULL) {
			status = 27;
			break;
		}

		/* lecture du tampon de conversion */
		if (read(fh, (CHAR *)courante->tbl_tampon, courante->tbl_lg_tampon) != courante->tbl_lg_tampon)
			status = 1;
		break;
	}

	/* fermeture du fichier tbl */
#if EXABAL && !vms
	liberlox(complet);
#endif /* EXABAL && !vms */
	liberate(complet);
	cicoclose(fh);
	return (status);
}


/* envoi d'une initialisation de tbl
 * ---------------------------------
 *
 * appel:	numero de sequence
 *
 * retour:	rien
 *
 */
static VOID _lo_tbl_init(numero)
WORD numero;
{
	register i;
	BYTE *p;

	if (courante->tbl_init == NULL)
		return;
	p = courante->tbl_init + courante->tbl_lg_init * numero;
	for (i = 0; i < courante->tbl_lg_init && p[i] != '\0'; i++)
		_lo_out(p[i]);
}


/* envoi d'un attribut de tbl
 * --------------------------
 *
 * appel:	numero d'attribut
 *
 * retour:	rien
 *
 */
static VOID _lo_tbl_attribut(numero)
WORD numero;
{
	register i;
	BYTE *p;

	if (courante->tbl_attribut == NULL)
		return;
	p = courante->tbl_attribut + courante->tbl_lg_attribut * numero;
	for (i = 0; i < courante->tbl_lg_attribut && p[i] != '\0'; i++)
		_lo_out(p[i]);
}


/* conversion de la commande sommeil SLEEP=<n>
 * -------------------------------------------
 *
 * appel:	chaine contenant la commande
 *
 * retour:	<n> si ok, -1 en cas d'erreur
 *
 */
static int  _conv_sleep(cmd, spl)
BYTE *cmd,*spl;
{
	int n=0;
	BYTE *ptr;
	
	/* si pas de commande SLEEP=0 */	
	if ( cmd == NULL )
		return(0);

	/* si impression spool pas de tempo */
	if ( spl != NULL ) {
		while ( (*spl != '\0') && (*spl == ' ') ) {
			spl++;
		}
		if (*spl != '\0')
			return(0);
	}

	/* suppression des blancs */ 
	while ( *cmd == ' ' )
		cmd++;

	/* conversion de la commande en majuscule */
	ptr=cmd;
	while ( *ptr != '\0' ) {
		*ptr=(BYTE) mima( (WORD) *ptr, 0);
		ptr++;
	}

	if ( (strncmp(cmd,"SLEEP",5) == 0 ) ) {
		cmd=cmd+5;
		
		/* suppression des blancs */ 
		while ( *cmd == ' ' )
			cmd++;

		if ( *cmd++ != '=' )
			return(-1);

		/* suppression des blancs */ 
		while ( *cmd == ' ' )
			cmd++;

		n = 0;

		/* suppression des zeros */ 
		while ( *cmd == '0' )
			cmd++;
		
		if ( *cmd < '1' || *cmd > '9' )
			return (-1);

		while (*cmd >= '0' && *cmd <= '9')
			n = n * 10 + *cmd++ - '0';

		if ((n < 0) || (n > 10))
			return(-1);

		return(n);	
	}

	return(-1);	
}

/* ouverture d'un imprimante
 * -------------------------
 *
 * appel:	nom de l'imprimante de mode
 *
 * retour:	0 si ok, -1 en cas d'erreur
 *
 */
static WORD _lo_open(name, mode)
BYTE *name;
WORD mode;
{
	register i;			/* compteur de boucles		*/
	BYTE *p;			/* pointeur de travail		*/
	BYTE *nom = NULL;		/* duplication du nom d'appel   */
	BYTE *tbl = NULL;		/* nom du fichier TBL		*/
	BYTE *spool = NULL;		/* nom de l'utilitaire de spool */
	BYTE *sommeil = NULL;		/* commande de la tempo imp	*/
	struct stat stbuf;		/* caracteristiques du fichier	*/
	int fh; 			/* handle du fichier imprimante */
	int oflag;			/* flag d'ouverture imprimante  */

	/* recherche d'une structure de description disponible */
	if ((courante = (imprimante_st *)allocate(sizeof(imprimante_st))) == NULL) {
		err_val = 27;
		return (-1);
	}
	courante->nom = NULL;
#ifdef IMPLOC
	courante->local = FALSE;
#endif /*IMPLOC*/
	courante->spool = NULL;
	courante->handle = -1;
	courante->flag = FALSE;
	courante->ligne = 0;
	courante->colonne = 0;
	courante->jeu = NO_CASE;
	courante->etat = ETAT_STANDARD;
	courante->tbl_init = NULL;
	courante->tbl_attribut = NULL;
	courante->tbl_table = NULL;
	courante->tbl_tampon = NULL;

	/* allocation d'une zone de recopie du nom */
	if ((nom = (BYTE *)allocate(strlen(name) + 1)) == NULL) {
		_lo_close();
		err_val = 27;
		return (-1);
	}
	strcpy(nom, name);

	/* recherche du nom */
	if ((p = (BYTE *)strchr(nom, '(')) != NULL) {
		*p = '\0';
		tbl = ++p;
		if ((p = (BYTE *)strchr(p, IMP_SEPARATEUR)) != NULL) {
			*p = '\0';
			spool = ++p;
			if ((p = (BYTE *)strchr(p, IMP_SEPARATEUR)) != NULL) {
				*p = '\0';
				if ( *spool == *p)
					spool = NULL;
				sommeil = ++p;
			} else
				p = spool;
		} else
			p = tbl;
		if ((p = (BYTE *)strchr(p, ')')) != NULL)
			*p = '\0';
	}

	/* calcul de la temporisation de l'imprimante */
	
	if ( (courante->sleep = _conv_sleep(sommeil,spool)) == -1 ) {
			err_val = 30; /* parametre incorrect */
			_lo_close();
			return(-1);			
	}
	
	/* rangement du nom */
#ifndef vms
#ifdef IMPLOC
	/* suppression des blancs */
	while ( *nom == ' ' )
		nom++;

	if ( strcmp(nom,"LOCAL") == 0 ) {
		if ( ENTER_LOCAL == NULL ) {
			err_val = 58;
			_lo_close();
			return(-1);			
		}
		if ((courante->nom = (BYTE *)allocate(strlen(ttyname(STDOUT))+1)) == NULL) {
			err_val = 27;
			_lo_close();
			return (-1);
		}
		strcpy(courante->nom, ttyname(STDOUT));
	} else {
#endif /*IMPLOC*/
	if ((courante->nom = (BYTE *)allocate(strlen(nom) + 1)) == NULL) {
		err_val = 27;
		_lo_close();
		return (-1);
	}
	strcpy(courante->nom, nom);
#ifdef IMPLOC
	} 
#endif /*IMPLOC*/
#endif /* vms */

	/* chargement du fichier tbl */
	if (tbl != NULL && *tbl != '\0') {
		if ((err_val = _lo_tbl_charge(tbl)) != 0) {
			_lo_close();
			return (-1);
		}
	}

	/* ouverture du fichier imprimante */
#ifdef vms
	if ((fh = creat(nom, 0)) == -1) {
		err_val = 1;
		_lo_close();
		return (-1);
	}
#else
#ifdef EXABAL
	if (Access(courante->nom, W_OK, 1) == 0) {
#else
	if (access(courante->nom, W_OK) == 0) {
#endif /* EXABAL */
		if (stat(courante->nom, &stbuf) != 0) {
			err_val = 1;
			_lo_close();
			return (-1);
		}
/* 30/05/94 */
		if (((stbuf.st_mode & 0020000) != 0020000) && ((stbuf.st_mode & 0010000) != 0010000)) {
			err_val = 41;
			_lo_close();
			return (-1);
		}
#ifdef IMPLOC
		if ( strcmp(nom,"LOCAL") == 0 ) {
			courante->local=TRUE;
		}
#endif /*IMPLOC*/
		spool = NULL;
		oflag = O_WRONLY | O_SYNC;
		if (mode & 4)
			oflag &= ~O_SYNC;
		if ((fh = open(courante->nom, oflag, 0)) == -1) {
			err_val = 1;
			_lo_close();
			return (-1);
		}
	} else if (errno == ENOENT) {
		errno = 0;
		oflag = O_WRONLY | O_CREAT | O_SYNC;
		if (mode & 4)
			oflag &= ~O_SYNC;
		if ((fh = open(courante->nom, oflag, 0666)) == -1) {
			err_val = 1;
			_lo_close();
			return (-1);
		}
#ifdef EXABAL
		Access(nom, W_OK, 1);
#endif /* EXABAL */
	} else {
#ifdef EXABAL
		if (errno == 44)
			err_val = errno;
		else
			err_val = 1;
#else
		err_val = 1;
#endif /* EXABAL */
		_lo_close();
		return (-1);
	}
#endif /* vms */
	courante->handle = fh;
#ifdef IMPLOC
	if ( courante->local == TRUE ) {
		if ( IMP_LOC_ACTIVE == FALSE ) {
			/* ouverture de l'imprimante locale */
			deb_imp_loc(courante->handle);
			/* Activation de l'imprimante locale */
			IMP_LOC_ACTIVE=TRUE;
		}
	}
#endif /*IMPLOC*/
	/* rangement du nom */
#ifdef vms
	if ((courante->nom = (BYTE *)allocate(256)) == NULL) {
		err_val = 27;
		_lo_close();
		return (-1);
	}
	if (getname(fh, courante->nom, 1) == 0) {
		err_val = 1;
		_lo_close();
		return (-1);
	}
#endif /* vms */

	/* constitution de la commande de spool */
	if (spool != NULL && *spool != '\0') {

		/* suppression des blancs */
		while ( *spool == ' ' )
			spool++;

		if ((courante->spool = (BYTE *)allocate(strlen(courante->nom) +
						      strlen(spool) +
						      2)) == NULL) {
			err_val = 27;
			_lo_close();
			return (-1);
		}
#ifdef IMPLOC
		if ((ENTER_LOCAL == NULL ) && (strncmp(spool,"LOCAL",5) == 0 )) {
			err_val = 58;
			_lo_close();
			return (-1);
		}
#endif /*IMPLOC*/
		strcpy(courante->spool, spool);
		strcat(courante->spool, " ");
		strcat(courante->spool, courante->nom);
	}

	/* envoi de la sequence d'initialisation */
	_lo_tbl_init(0);

	/* retourne le numero de l'imprimante */
	return (prnfid);
}


/* fermeture d'une imprimante
 * --------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
static VOID _lo_close()
{
	if (courante != NULL) {
		_lo_tbl_init(1);
#if EXABAL && !vms
		if (courante->nom != NULL && *courante->nom != '\0')
			liberlox(courante->nom);
#endif /* EXABAL && !vms */
#ifdef IMPLOC
		if ( (courante->local == TRUE) && (IMP_LOC_ACTIVE == TRUE) ) {
				/* sequence d'arret */
				fin_imp_loc(courante->handle);
				/* fermeture de l'imprimante locale */
				IMP_LOC_ACTIVE=FALSE; 
		}
#endif /*IMPLOC*/
		if (courante->handle != -1) {
			cicoclose(courante->handle);
		}
		if (courante->spool != NULL) {
#ifdef IMPLOC
			if ( strncmp(courante->spool, "LOCAL",5) == 0 ) {
				BYTE *sp_loc;
 				int fh;	
 				int oflag;		

				if ((sp_loc = (BYTE *)allocate(strlen(courante->spool)*2+10)) == NULL) {
					err_val = 27;
				} else {
 					oflag = O_WRONLY;
 					if ((fh = open(ttyname(STDOUT), oflag, 0)) == -1) {
 						err_val = 1;
 					} else {
						deb_imp_loc(fh);
						IMP_LOC_ACTIVE=TRUE;
						strcpy(sp_loc,"cat ");
						strcat(sp_loc, courante->spool+5);
						strcat(sp_loc,";rm ");
						strcat(sp_loc, courante->spool+5);
						system(sp_loc);
						fin_imp_loc(fh);
						IMP_LOC_ACTIVE=FALSE;
 						if (fh != -1)
 							cicoclose(fh);
					}
					liberate(sp_loc); 
				}
			} else {
#endif /*IMPLOC*/
#ifdef vms
			if (system(courante->spool) != 1)
#else
			if (system(courante->spool) != 0)
#endif /* vms */
				err_val = 1;
#ifndef vms
			if (courante->nom != NULL && *courante->nom != '\0')
				unlink(courante->nom);
#endif /* vms */
			liberate((CHAR *)courante->spool);
#ifdef IMPLOC
			}
#endif /* IMPLOC */
		}
		if (courante->nom != NULL)
			liberate((CHAR *)courante->nom);
		if (courante->tbl_init != NULL)
			liberate((CHAR *)courante->tbl_init);
		if (courante->tbl_attribut != NULL)
			liberate((CHAR *)courante->tbl_attribut);
		if (courante->tbl_table != NULL)
			liberate((CHAR *)courante->tbl_table);
		if (courante->tbl_tampon != NULL)
			liberate((CHAR *)courante->tbl_tampon);
		liberate((CHAR *)courante);
		courante = NULL;
	}
}


/* ouverture de l'imprimante par defaut
 * ------------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
static WORD _lo_defaut()
{
	if (tbl_defaut != NULL && *tbl_defaut != '\0') {
		prnfid = 0;
		if (_lo_open(tbl_defaut, 4) != 0) {
/* DIT:1053     */
			if ( err_val != 44 )
				err_val = 1;
/* FIN DIT:1053 */
			return (1);
		}
	} else {
		err_val = 1;
		return (1);
	}
	return (0);
}


/************************************************************************
 *									*
 *	Primitives de gestion de l'image memoire ecran                  *
 *									*
 ***********************************************************************/


/* push ecran
 * ----------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_push()
{
	_co(ESC);
	_co('>');
}


/* pop ecran
 * ---------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID x_pop()
{
	_co(ESC);
	_co('<');
}


/************************************************************************
 *									*
 *	Primitives d'usage general                                      *
 *									*
 ***********************************************************************/


/* lecture des parametres de configuration
 * ---------------------------------------
 *
 * appel:	le numero de parametre
 *
 * retour:	le parametre
 *
 */
WORD conf(ind)
WORD ind;
{
	register i, j;

#ifdef CICO_BDA
	if (redir_CO == TRUE) {
		BYTE type[1];
		VOID *argument[1];
		WORD taille[1];

		type[0] = TYPE_WORD;
		argument[0] = (VOID *)&ind;
		taille[0] = 2;

#ifdef CICO_DEBUG
	fprintf(DEBUG,"CallRunTime(CICO_CONF)\n");
#endif /* fin CICO_DEBUG */

#ifdef IMPLOC
	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		fin_imp_loc(courante->handle);
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
	}	
#endif /*IMPLOC*/

		return (CallRunTime(redir.cico.numero,
				    redir.cico.fonction[CICO_CONF],
				    1, type, argument, taille));
	}
#endif /* fin CICO_BDA */

	i = 0;
	switch (ind) {
	case 1: 	/* nombre de lignes de l'ecran */
		i = nb_ligne;
		break;
	case 2: 	/* nombre de colonnes de l'ecran */
		i = nb_colonne;
		break;
	case 3: 	/* nombre de ligne de l'imprimante */
#ifdef ABALCONF
		if ( abc_printer_flag == FALSE ) {
#endif /* ABALCONF */
		i = 66;
#ifdef ABALCONF
		} else {
			i = abc_printer_nbl;
		}
#endif /* ABALCONF */
		break;
	case 4: 	/* nombre de colonne de l'imprimante */
#ifdef ABALCONF
		if ( abc_printer_flag == FALSE ) {
#endif /* ABALCONF */
		i = 132;
#ifdef ABALCONF
		} else {
			i = abc_printer_nbc;
		}
#endif /* ABALCONF */
		break;
	case 5: 	/* code langue */
		i = code_lang;
		break;
	case 6: 	/* numero de version Amenesik / Sologic */
		i = '2';
		break;
	case 7: 	/* indice de la version Amenesik / Sologic */
		i = '2';
		break;
	case 8: 	/* bits de protection */
		i = 0000000000110001;
		break;
	case 9: 	/* nombre de touches de fonctions */
		for (j = PKEY_F_FIRST; j < PKEY_F_FIRST + PKEY_F_NB; j++)
			if (*term_str[j] != '\0')
				i++;
		break;
	case 10:	/* identite du systeme d'exploitation   */
	case 15:	/* sous classement des systemes 	*/
#ifdef vms
		i = 2;
#else
		i = 3;
#endif /* vms */
		break;
	case 11:	/* fonctions curseur optionelles */
		if (*CLEAR_EOS != '\0')
			i += 1; 	/* effacement fin d'ecran       */
		if (*CLEAR_EOL != '\0')
			i += 2; 	/* effacement fin de ligne	*/
		if (*INSERT_LINE != '\0')
			i += 4; 	/* insertion ligne		*/
		if (*DELETE_LINE != '\0')
			i += 8; 	/* suppression ligne		*/
		if (*INSERT_CHAR != '\0')
			i += 16;	/* insertion caractere		*/
		if (*DELETE_CHAR != '\0')
			i += 32;	/* suppression caractere	*/
		break;
	case 12:	/* attributs n/b optionnels */
		if (*ENTER_STANDOUT != '\0')
			i += 1; 	/* inversion video	*/
		if (*ENTER_BLINK != '\0')
			i += 2; 	/* clignotant		*/
		if (*ENTER_UNDERLINE != '\0')
			i += 4; 	/* souligne		*/
		if (*ENTER_DIM != '\0')
			i += 8; 	/* sous-brillance	*/
		if (*ENTER_BOLD != '\0')
			i += 16;	/* sur-brillance	*/
		break;
	case 13:	/* nombre de colonnes ligne systeme */
		i = 0;
		break;
	case 14:	/* indicateur gestion couleur */
		i = flag_couleur == TRUE ? 1 : 0;
		break;
	default:
		i = 0;
	}
	return (i);
}


/* lecture du numero de poste
 * --------------------------
 *
 * appel:	rien
 *
 * retour:	le numero de poste
 *
 */
/*DLR:02/02/93*/
WORD x_npos()
{
	switch ( process_flag ) {
		case TRUE  : return( process_number );
		default    : return( x_npos14() );
		}
}

static WORD x_npos14()

#ifdef NPOS_SYSTEM_V

/* System V
 * --------
 *
 * lecture du fichier /etc/utmp avec les fonctions getut(3C)
 * Modification Unix Interactive :
 * -----------------------------
 *	Plus de classement alphabetique :
 *		Probleme console fixe vt et console reseau dynamique ttyp
 *	Probleme du nom de ut_line :
 *		au login dans /etc/utmp : /dev/vt01
 *		apres le login : vt01 correction par suppresion de l'ordre
 *		alpha
 * 	Attention sur SCO : la console fonctionne par effet de bord
 *			car PROCESS=0 quand une entree n'est pas trouvee
 *			en effet tty -> /dev/syscon et
 *			/dev/utmp on a /dev/tty01.
 */
{
	static WORD poste = 0xffff;	/* numero de poste		*/
	CHAR *cp;			/* pointeur de caractere	*/
	struct utmp *utbuf;		/* caracteristiques d'un processus */
	BOOL trouve = FALSE;
	int comp;

	if (poste != 0xffff)
		return (poste);
	else
		poste = 0;
	if ((cp = ttyname(STDIN)) == NULL)
		return (poste);
	cp += strlen("/dev/");
	while (TRUE) {
		if ((utbuf = getutent()) == NULL) {
			endutent();
			if (trouve == FALSE)
				poste = 0;
			break;
		}
		if (utbuf->ut_type == INIT_PROCESS ||
		    utbuf->ut_type == LOGIN_PROCESS ||
		    utbuf->ut_type == USER_PROCESS) {

			if ( *(utbuf->ut_line) != '\0' ) {
				comp= strcmp(cp, utbuf->ut_line);
				if (process_seq == FALSE) {
					if (comp == 0) {
						trouve = TRUE;
						endutent();
						break;
					}
					poste++;
				} else {
					if (comp == 0) {
						trouve = TRUE;
						endutent();
						break;
					}
					else if (comp > 0)
						poste++;
				}
			}			
		}
	}
	return (poste);
}

#ifdef ABAL14B
/* System V
 * --------
 *
 * lecture du fichier /etc/utmp avec les fonctions getut(3C)
 *
 */
{
	static WORD poste = 0xffff;	/* numero de poste		*/
	CHAR *cp;			/* pointeur de caractere	*/
	struct utmp *utbuf;		/* caracteristiques d'un processus */
	BOOL trouve = FALSE;
	int comp;

	if (poste != 0xffff)
		return (poste);
	else
		poste = 0;
	if ((cp = ttyname(STDIN)) == NULL)
		return (poste);
	cp += strlen("/dev/");
	while (TRUE) {
		if ((utbuf = getutent()) == NULL) {
			endutent();
			if (trouve == FALSE)
				poste = 0;
			break;
		}
		if (utbuf->ut_type == INIT_PROCESS ||
		    utbuf->ut_type == LOGIN_PROCESS ||
		    utbuf->ut_type == USER_PROCESS) {
/* DLR:05/02/93 */
			if ( *(utbuf->ut_line) != '\0' ) {
				comp= strcmp(cp, utbuf->ut_line);
				if (comp == 0)
					trouve = TRUE;
				else if (comp > 0)
					poste++;
			}
		}
	}
	return (poste);
}
#endif /* ABAL14B */

#endif /* NPOS_SYSTEM_V */

#ifdef NPOS_VERSION_7

/* Version 7
 * ---------
 *
 * SCO Xenix 2.3 - Sinix
 *
 * lecture du fichier /etc/ttys
 *
 */
{
	static WORD poste = 0xffff;	/* numero de poste		*/
	CHAR *cp;			/* pointeur de caractere	*/
	FILE *stream;
	CHAR buf[64];

	if (poste != 0xffff)
		return (poste);
	if ((cp = ttyname(STDIN)) == NULL)
		return (poste = 0);
	cp += strlen("/dev/");
#ifdef EXABAL
	if (Access("/etc/ttys", R_OK, 0) == -1)
#else
	if (access("/etc/ttys", R_OK) == -1)
#endif /* EXABAL */
		return (0);
	if ((stream = fopen("/etc/ttys", "r")) != NULL) {
		do {
			if (fgets(buf, 63, stream) == NULL) {
				poste = 0;
				break;
			}
			poste++;
		} while (strncmp(buf + 2, cp, strlen(buf) - 3) != 0);
#ifdef EXABAL
		liberlox("/etc/ttys");
#endif /* EXABAL */
		fclose(stream);
	} else
		poste = 0;
	return (poste);
}

#endif /* NPOS_VERSION_7 */

#ifdef NPOS_VERSION_DEBUG

/* Version DEBUG
 * ---------
 *
 *
 *
 */
{

#ifdef CICO_DEBUG
	printf("\r\nR_uid:%d,E_uid:%d\r\n",getuid(),geteuid());
#endif /* CICO_DEBUG */
	return( getuid() );
}

#endif /* NPOS_VERSION_DEBUG */

#ifdef NPOS_BSD_4

/* BSD 4.x
 * -------
 *
 * Ultrix
 *
 * utilisation directe de la fonction ttyslot()
 *
 */
{
	return ((WORD)ttyslot());
}

#endif /* NPOS_BSD_4 */

#ifdef vms

{
	return ((WORD)vms$npos());
}

#endif /* vms */


/************************************************************************
 *									*
 *	Initialisations du terminal (ecran/clavier)			*
 *									*
 ***********************************************************************/

#ifdef CICO_BDA

/* x_redir - redirection cico
 * --------------------------
 *
 * appel:	WORD x_redir(sens, indicateur, descripteur, taille);
 *		BOOL sens		  = TRUE si activation
 *					    FALSE si desactivation
 *		WORD indicateur 	  = indicateur des fonctions a rediriger
 *		BDA_INIT FAR *descripteur = structture de description de la BDA
 *		WORD taille		  = taille du descripteur
 *
 * retour:	0 si ok, 0xffff en cas d'erreur.
 *
 */
WORD x_redir(sens, indicateur, descripteur, taille)
BOOL sens;
WORD indicateur;
BDA_INIT *descripteur;
WORD taille;
{

#ifdef CICO_DEBUG
	fprintf(DEBUG,"X_REDIR\n");
#endif /* fin CICO_DEBUG */

	if (descripteur->cico.signature != BDA_ASFUN)
		return (0xffff);
	if ((indicateur & CO) == CO) {
		if (redir_CO == sens)
			return (0xffff);
		redir_CO = sens;
	}
	if ((indicateur & CI) == CI) {
		if (redir_CI == sens)
			return (0xffff);
		redir_CI = sens;
	}
	if ((indicateur & LO) == LO) {
		if (redir_LO == sens)
			return (0xffff);
		redir_LO = sens;
	}
	redir = *descripteur;
	return (0);
}

#endif /* fin CICO_BDA */

/*DLR:02/02/93*/
void	establish_process_number( process_filename )
char	* process_filename;
{
	FILE * process_handle;
	char	tty_name_buf[256];
	int	process_id;
	int	version_number;
	char	* cp;

	/* Si le 1er champ est blanc : ancienne methode */
	if ( process_filename[0]==' ' ) {
		process_flag = FALSE;
		return;
	}
	/* Si le 1er champ est vide : No de process dans ABALPROCESS*/
	if ( process_filename[0]==':' ) {
		if ( process_filename[1] == 'S' ) {
			process_flag = FALSE;
			process_seq = TRUE;
			return;
		}	
		process_number = (WORD)atoi( process_filename+1 );
		process_flag = TRUE;
		return;
	}

	/* Attempt to open Process to TTY name configuration file */
	/* ------------------------------------------------------ */
	if ((process_handle = fopen( process_filename, "r" )) != (FILE *) 0) {

		/* Collect Current Station File Version Number */
		/* ------------------------------------------- */
		fscanf(process_handle,"%s",&tty_name_buf);
		fscanf(process_handle,"%d",&version_number);
		
		/* Collect current tty name string */
		/* ------------------------------- */
		if ((cp = ttyname(STDIN)) != NULL) {

			cp += strlen("/dev/");

			/* Read Entries from the file */
			/* -------------------------- */
			while ( 1 ) {
				tty_name_buf[0] = 0;
				fscanf(process_handle,"%s",tty_name_buf);
				if ( strlen(tty_name_buf) == 0 )
					break;
				fscanf(process_handle,"%d",&process_id);
				if ( strcmp( tty_name_buf, cp ) == 0 ) {
					process_number = process_id;
					process_flag = TRUE;
					break;
					}
				}

			}
		
		/* Liberate the process config file */
		/* -------------------------------- */
		fclose( process_handle );
		}


}

/* initialisations pour la gestion du terminal
 * -------------------------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
VOID initerm()
{
	register i, j;		/* compteurs de boucles 		*/
	CHAR c; 		/* caractere				*/
	int longueur;		/*					*/
	CHAR *cp;		/*					*/
	BYTE *bp;		/*					*/
	CHAR *term;		/* variable d'environnement TERM        */
	CHAR *test;		/* champ test				*/
	CHAR *cico;		/* variable d'environnement CICO        */
	CHAR *lo;		/* variable d'environnement LO          */
	CHAR *lang;		/* variable d'environnement LANG        */
	CHAR *path;		/* chemin du fichier parametre		*/
	CHAR *tempo_bis;	/* chaine de la valeur de temporisation */
	CHAR *name;		/* nom complet du fichier parametre	*/
	int fh = -1;		/* handle du fichier parametre		*/

	unsigned lg_nom;	/* LONG. de la section du nom		*/
	unsigned lg_nb; 	/* LONG. de la section des nombres	*/
	unsigned lg_off;	/* LONG. de la section des deplacements */
	unsigned lg_str;	/* LONG. de la section des chaines	*/
	unsigned lg_in; 	/* LONG. de la table conversion clavier */
	unsigned lg_out;	/* LONG. de la table conversion ecran	*/

	BYTE sum;		/* somme calculee			*/
	BYTE sumsum;		/* somme de la somme calculee		*/
	WORD checksum;		/* checksum				*/
	BYTE *buf;		/* buffer de calcul			*/

	LONG lg_calc;		/* LONG. calculee du fichier		*/
	CHAR *entete;		/* entete de fichier parametre		*/
	CHAR *nom;		/* nom du terminal decrit		*/
	CHAR *nb;		/* section des nombres			*/
	CHAR *off;		/* section des deplacements		*/
	int taille_car; 	/* nombre de bits d'un caractere        */

	if (flag_init == FALSE) {

/* initialisation */

		flag_finterm = FALSE;

#ifdef CIFIC
/* Ouverture du fichier de traces entrees si defini */
	if ( (cp = getenv(ENV_CIFIC)) != NULL)
	  {
	    if (Access(cp,R_OK,1) == 0 )
	      {
		cific_ptr = fopen(cp,"r");
		if (cific_ptr != (FILE *) 0) {cific_ok = TRUE;};
	      };
	  };
		
/* Ouverture du fichier de traces sorties si defini */
	if ( (cp = getenv(ENV_COFIC)) != NULL)
	  {
	    if (Access(cp,W_OK,1) == 0 )
	      {
		cofic_ptr = fopen(cp,"a+");
		if (cofic_ptr != (FILE *) 0) {cofic_ok = TRUE;};
	      };
	  };
#endif

#ifdef CICO_DEBUG
		if (Access("dbg_cico",W_OK,1) == 0 ) {
			DEBUG=fopen("dbg_cico","w");
		} else {
			DEBUG=fopen("dbg_cico2","w");
		}
#endif /* fin CICO_DEBUG */

		/* ignorer les signaux SIGINT et SIGQUIT */
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
/*
	Redirection du CICO vers CICO extern 
	si XCICO = nb de lignes existe
*/

		XCICO_nbl = 0;		
		if ((cp = getenv("XCICO")) != NULL) {
			while (*cp >= '0' && *cp <= '9')
				XCICO_nbl = XCICO_nbl * 10 + *cp++ - '0';
			write(STDOUT,XCICO_start,XCICO_NB);
		}

#ifdef ABALCONF
		/* Test de l'existence de la variable ABALCONF */

		if ((cp = getenv("ABALCONF")) != NULL) {
			establish_config( cp );
		}
#endif /* ABALCONF */

#ifdef ABALCONF
		if ( abc_process_flag == FALSE ) {
#endif /* ABALCONF */
/*DLR:02/02/93*/
/*
	Test for PROCESS compatible Version 1.5a
*/
		if ((cp = getenv("ABALPROCESS")) != NULL)
			establish_process_number( cp );
		else    process_flag = FALSE;
#ifdef ABALCONF
		} else {
			process_flag = abc_process_flag;
			process_number = abc_process_number;
			process_seq = FALSE;
		}
#endif /* ABALCONF */

		/* lecture des parametres d'environnement */

		cico = term = path = NULL;

#ifdef ABALCONF
		if ( abc_screen_flag == FALSE ) {
#endif /* ABALCONF */

		if ((cp = getenv(ENV_ECRAN)) != NULL) {
			if ((cico = allocate(strlen(cp) + 1)) == NULL)
				erreur(E_ALLOC, NULL, fh);
			strcpy(cico, cp);
			term = cico;
			if ((cp = strchr(cico, ENV_SEPARATEUR)) != NULL) {
				*cp = '\0';
				path = ++cp;
				if ((cp = strchr(cp, ENV_SEPARATEUR)) != NULL) {
					*cp = '\0';
					tempo_bis = ++cp;
					if ((cp = strchr(cp, ENV_SEPARATEUR)) != NULL)
						*cp = '\0';
					tempo = 0;
					while (*tempo_bis >= '0' && *tempo_bis <= '9')
						tempo = tempo * 10 + *tempo_bis++ - '0';
				}
			}
		}
		if (term == NULL || *term == '\0')
#ifdef vms
			if ((term = getenv("TERM")) == NULL ||
			    strcmp(term, "undefined") == 0)
#else
			if ((term = getenv("TERM")) == NULL)
#endif /* vms */
				erreur(E_FIND, NULL, fh);

		if (path == NULL || *path == '\0')
			path = ECR_CHEMIN;
		if (tempo == -1)
			erreur(E_TEMPO, NULL, fh);

		if ((test = strchr(term, IMP_SEPARATEUR)) != NULL)
			*test++ = '\0';

#ifdef ABALCONF
		} else {
			term = abc_screen_name;
			path = abc_screen_path;
			tempo = abc_screen_tempo;
			test = (CHAR *)0;
		}	
#endif /* ABALCONF */

#ifdef ABALCONF
		if ( abc_language_flag == FALSE ) {
#endif /* ABALCONF */
		if (((lang = getenv(ENV_LANGUE))  != NULL)
		||  ((lang = getenv(ENV_LANGUE2)) != NULL)) {
			code_lang = 0;
			while (*lang >= '0' && *lang <= '9')
				code_lang = code_lang * 10 + *lang++ - '0';
		}
#ifdef ABALCONF
		} else {
			code_lang = abc_language;
		}
#endif /* ABALCONF */

		if ((name = allocate(strlen(path) + 3 + strlen(term))) == NULL)
			erreur(E_ALLOC, NULL, fh);
		strcpy(name, path);
#ifndef vms
		strcat(name, "/");
#endif /* vms */
		strcat(name, term);
#ifdef vms
		if ((fh = open(name, O_RDONLY, 0, "shr=get")) == -1)
			erreur(E_OPEN, name, fh);
#else
#if EXABAL
		if (Access(name, R_OK, 0) == -1) {
			if (errno == 666)
				erreur(E_INSTALL, NULL, fh);
			if (errno == 667)
				erreur(E_ACCESS, NULL, fh);
#else
		if (access(name, R_OK) == -1) {
#endif /* EXABAL */
			erreur(E_OPEN, name, fh);
		}
		fh = open(name, O_RDONLY);
#endif /* vms */

		/* lecture de l'entete */
		if ((entete = allocate(ECR_LONGUEUR_ENTETE)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, entete, ECR_LONGUEUR_ENTETE) == -1)
			erreur(E_READ, name, fh);

		/* verification de la signature */
		
		if (memcmp(entete, ECR_SIGNATURE, ECR_LONGUEUR_SIGNATURE) > 0)
			erreur(E_BADF, name, fh);

		/* lecture des longueurs */
		bp = (BYTE *)(entete + ECR_LONGUEUR_SIGNATURE);
		lg_nom = *bp + *(bp + 1) * 256; bp += 2;
		lg_nb = *bp + *(bp + 1) * 256; bp += 2;
		lg_off = *bp + *(bp + 1) * 256; bp += 2;
		lg_str = *bp + *(bp + 1) * 256; bp += 2;
		lg_in = *bp + *(bp + 1) * 256; bp += 2;
		lg_out = *bp + *(bp + 1) * 256; bp += 2;
		lg_calc = lg_nom + lg_nb + lg_off + lg_str + lg_in + lg_out;
		if (lg_nom % 2)
			lg_calc++;
		if (lg_str % 2)
			lg_calc++;

		/* lecture de la checksum */
		checksum = *bp + *(bp + 1) * 256;

		/* alloction d'un buffer de calcul */
		if ((buf = (BYTE *)allocate(lg_calc)) == NULL)
			erreur(E_ALLOC, NULL, fh);

		/* lecture des donnees pour le calcul */
		if (read(fh, (CHAR *)buf, lg_calc) != lg_calc)
			erreur(E_READ, name, fh);

		/* calcul de la checksum */
		sum = sumsum = 0;
		for (i = 0; i < lg_calc; i++) {
			sum += buf[i];
			sumsum += sum;
		}
		if (checksum != sum * 256 + sumsum)
			erreur(E_BADF, name, fh);

		/* repositionnment */
		if (lseek(fh, 20L, SEEK_SET) == -1L)
			erreur(E_SEEK, name, fh);

		/* lecture du nom */
		if (lg_nom % 2)
			lg_nom++;
		if ((nom = allocate(lg_nom)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, nom, lg_nom) == -1)
			erreur(E_READ, name, fh);

		/* lecture des nombres */
		if ((nb = allocate(lg_nb)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, nb, lg_nb) == -1)
			erreur(E_READ, name, fh);
		bp = (BYTE *)nb;

		nb_ligne = *bp + *(bp + 1) * 256; bp += 2;
#ifdef ABALCONF
		if ( abc_screen_nbl != 0 )
			nb_ligne = abc_screen_nbl;
#endif /* ABALCONF */

/* XCICO actif */
		if ( XCICO_nbl != 0 )
			nb_ligne = XCICO_nbl;
/***************/

		nb_colonne = *bp + *(bp + 1) * 256; bp += 2;
#ifdef ABALCONF
		if ( abc_screen_nbc != 0 )
			nb_colonne = abc_screen_nbc;
#endif /* ABALCONF */

		max_ligne = nb_ligne - 1;
		max_colonne = nb_colonne - 1;
		taille_car = *bp + *(bp + 1) * 256;

		/* lecture des deplacements */
		if ((off = allocate(lg_off)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, off, lg_off) == -1)
			erreur(E_READ, name, fh);

		/* lecture des chaines */
		if ((tab_str = allocate(lg_str)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, tab_str, lg_str) == -1)
			erreur(E_READ, name, fh);
		if (lg_str % 2)
			if (lseek(fh, 1L, SEEK_CUR) == -1)
				erreur(E_READ, name, fh);

		for (i = 0; i < lg_off / 2; i++) {
			bp = (BYTE *)(off + i * 2);
			term_str[i] = (BYTE *)(tab_str + *bp + *(bp + 1) * 256);
		}
#ifdef IMPLOC
		if ( (lg_off / 2) < NB_CAPA ) {
			for (i = (lg_off / 2); i < NB_CAPA; i++) {
				term_str[i] = (BYTE *) NULL;
			}
		}
#endif /*IMPLOC*/
		/* lecture des tables de conversion */
		if ((tab_out = (BYTE *)allocate(256)) == NULL ||
		    (tab_in = (BYTE *)allocate(256)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (read(fh, tab_in, 256) == -1 || read(fh, tab_out, 256) == -1)
			erreur(E_READ, name, fh);

		/* affichage banniere */
		if (test != NULL &&
		    (strcmp(test, "test") == 0 ||
		     strcmp(test, "TEST") == 0)) {
			write(STDERR, message[B_VERSION],
			      strlen(message[B_VERSION]));
			write(STDERR, message[B_UPDATE],
			      strlen(message[B_UPDATE]));
			write(STDERR, message[B_COPYRIGHT],
			      strlen(message[B_COPYRIGHT]));
			write(STDERR, "file: ", 6);
			write(STDERR, nom, strlen(nom));
			write(STDERR, "\ntempo: 0x", 8);
			for (i = 1000000, j = tempo; i > 0; i /= 10) {
				if (tempo >= i) {
					c = j / i + '0';
					j = j % i;
					write(STDERR, &c, 1);
				}
			}
			write(STDERR, "\n", 1);
#if EXABAL
			write(STDERR, "(exa)\n", 6);
#endif /* EXABAL */
			sleep(5);
		}

		/* liberation des zones et fermeture du fichier */
		liberate(nb);
		liberate(off);
		liberate(entete);
		if (cico != NULL)
			liberate(cico);
#if EXABAL && !vms
		liberlox(name);
#endif /* EXABAL && !vms */
		liberate(name);
		cicoclose(fh);
		fh = -1;

		/* test presence couleur */
		flag_couleur = TRUE;
		for (i = FORE_FIRST; i < FORE_FIRST + FORE_NB; i++)
			if (*term_str[i] == '\0') {
				flag_couleur = FALSE;
				break;
			}
		if (flag_couleur == TRUE)
			for (i = BACK_FIRST; i < BACK_FIRST + BACK_NB; i++)
				if (*term_str[i] == '\0') {
					flag_couleur = FALSE;
					break;
				}

		/* allocation de l'ecran courant */
		if ((courant = (ecran_st *)allocate(sizeof(ecran_st))) == NULL)
			erreur(E_ALLOC, NULL, fh);
		courant->suite = NULL;
		courant->ligne = 0;
		courant->colonne = 0;
		courant->jeu = NO_CASE;
		courant->etat = ETAT_STANDARD;
		courant->attribut = A_NORMAL;
#ifdef ABALCONF
		if ( abc_color_flag == FALSE ) {
			courant->def_char = C_GREEN;
			courant->def_back = C_BLACK;
			courant->texte = C_GREEN;
			courant->fond = C_BLACK;
		} else {
			courant->def_char = abc_color_char;
			courant->def_back = abc_color_back;
			courant->texte = abc_color_char;
			courant->fond = abc_color_back;
		}
#else
		courant->defaut = C_GREEN;
		courant->texte = C_GREEN;
		courant->fond = C_BLACK;
#endif /* ABALCONF */

		/* allocation de la zone ecran */
		longueur = nb_ligne * nb_colonne;
		if ((courant->image.caractere =
		    (BYTE *)allocate(longueur)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if ((courant->image.attribut =
		    (BYTE *)allocate(longueur)) == NULL)
			erreur(E_ALLOC, NULL, fh);
		if (flag_couleur == TRUE) {
			if ((courant->image.texte =
			    (BYTE *)allocate(longueur)) == NULL)
				erreur(E_ALLOC, NULL, fh);
			if ((courant->image.fond =
			    (BYTE *)allocate(longueur)) == NULL)
				erreur(E_ALLOC, NULL, fh);
		}

#ifdef ABALCONF
		if ( abc_printer_flag == FALSE ) {
#endif /* ABALCONF */
		/* lecture de la variable LO */
		if ((cp = getenv(ENV_IMPRIMANTE)) != NULL) {
			if ((lo = allocate(strlen(cp) + 1)) == NULL)
				erreur(E_ALLOC, NULL, fh);
			strcpy(lo, cp);
			tbl_defaut = lo;
			if ((cp = strchr(lo, ENV_SEPARATEUR)) != NULL) {
				*cp = '\0';
				tbl_chemin = ++cp;
			}
		}
#ifdef ABALCONF
		} else {
			tbl_defaut = abc_printer_name;
			tbl_chemin = abc_printer_path;
		}
#endif /* ABALCONF */

		/* verification de la presence des touches programmables */
		for (i = 0; i < PKEY_NB + PKEY_F_NB; i++)
			if (pkey[i].act == FALSE)
				if (*term_str[PKEY_FIRST + i] != '\0')
					pkey[i].act = TRUE;
#ifdef _DELAY 
		_delay = TRUE;
		delay_on();
#endif
		/* initialisation faite */
		flag_init = TRUE;
	}

#ifdef vms
	vms$initerm();
	vms$fcntl(0, 0, O_RDONLY);
#else

	/* lecture des paramtres de la liaison */
	ioctl(STDIN, TCGETA, &confterm);	/* pour sauvegarde */
	ioctl(STDIN, TCGETA, &proterm); 	/* pour programmer */

	/* positionnement des parametres */

	proterm.c_iflag &= ~ICRNL;
	if (taille_car == 8)
		proterm.c_iflag &= ~ISTRIP;
	proterm.c_oflag &= ~OPOST;
	proterm.c_lflag = 0;
	proterm.c_cc[VTIME] = 0;
	proterm.c_cc[VMIN] = 1;
	proterm.c_cc[VINTR] = 0xFF;
	proterm.c_cc[VQUIT] = 0x7F;

/*(NEWTEMPO)*/
	if ( tempo <= 0 )
		tempo=1;	/* Pas de temporisation nulle : tempo defaut=1s */
#ifndef SVR4_TEMPO
	if ( tempo > 10 )
		tempo=1;	/* Temporisation maximale 10s : tempo defaut=1s */
#else
	if ( tempo > 100 )
		tempo=1;	/* Temporisation maximale 10s : tempo defaut=1s */
#endif /* SVR4_TEMPO */

	/* programmation de la liaison */
	ioctl(STDIN, TCSETA, &proterm);

#endif /* vms */

	/* initialisation du terminal */
	if ( seqinit == 1 ) {
		_co_capacite(SET_TERM);
	}
	
	/* positionnement curseur */
	_co_pos(courant->ligne, courant->colonne);
}


/* fin d'execution : remettre le terminal en etat
 * ----------------------------------------------
 *
 * appel:	VOID finterm(type);
 *		WORD type = type de fermeture (0 definitive, != 0 temporaire)
 *
 * retour:	rien
 *
 */
VOID finterm(type)
WORD type;
{
	register i;

	/* fermeture des imprimantes */
	if (type == 0)
		for (i = 0; i < NB_IMPRIMANTE; i++)
			if (imprimante[i] != NULL) {
				prnfid = i;
				im_close();
			}

	/* finterm partiel */
	flag_finterm = TRUE;

	/* vidage du buffer de sortie */
	x_bflush();

	/* fin des attributs en cours */
	atb(0);

	/* sortie du jeu de caractere secondaire */
	if (flag_second == TRUE)
		_co_capacite(EXIT_SECOND);

	/* curseur allume */
	atb(26);

	/* reinitialisation du terminal */

	if ( seqinit == 1 ) {
		_co_capacite(RESET_TERM);
	}

#ifdef CICO_DEBUG
	fclose(DEBUG);
#endif /* fin CICO_DEBUG */

#ifdef CIFIC
	if (cific_ok == TRUE) { fclose(cific_ptr); };
	if (cofic_ok == TRUE) { fclose(cofic_ptr); };
#endif


#ifdef vms
	vms$set_def_term();
	vms$fcntl(STDIN, F_SETFL, O_RDONLY);
#else
	/* fin pour le clavier */
	ioctl(STDIN, TCSETA, &confterm);
	fcntl(STDIN, F_SETFL, O_RDONLY);
#endif /* vms */
}
/* modification terminal : envoie des sequences init/fin TERM ou pas
 * -----------------------------------------------------------------
 *
 * appel:	VOID modterm(etat);
 *		WORD etat = TRUE  si envoie des sequences init/fin TERM
 *			    FALSE sinon
 * retour:	rien
 *
 */
VOID modterm(etat)
WORD etat;
{
	seqinit = etat;
}

/* sortie avec erreur de initerm
 * -----------------------------
 *
 * appel:	numero de message d'erreur
 *
 * retour:	rien
 *
 */
static VOID erreur(err_no, name, fh)
WORD err_no;
BYTE *name;
{
	/* affichage d'un message d'erreur sur erreur standard */
	write(STDERR, "cico: ", 6);
	write(STDERR, message[err_no], (unsigned)strlen(message[err_no]));
	if (name != NULL)
		write(STDERR, name, (unsigned)strlen(name));
	write(STDERR, "\n", 1);

	/* liberation access */
#if EXABAL && !vms
	PurgeLox();
#endif /* EXABAL && !vms */

	/* fermeture du fichier parametre */
	if (fh > 0)
		cicoclose(fh);

	/* fin de process avec status */
	exit(1);
}

/* fin de fichier */

