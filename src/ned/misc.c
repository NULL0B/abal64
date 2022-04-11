#include "misc.h"

 BYTE misctmp[LGREP];
 BYTE misctmpA[LGREP];
 BYTE misctmpB[LGREP];

#ifdef LINT_ARGS
extern	SWORD FindFile(BYTE XPTR, BYTE XPTR);
extern	SWORD NextFile(BYTE XPTR);
extern	SWORD FindRep(BYTE XPTR, BYTE XPTR);
extern	SWORD NextRep(BYTE XPTR);

/*global*/ BINAIRE nb_niveau(BYTE XPTR);
/*global*/ VOID MakeNom(BYTE XPTR, BYTE XPTR, BYTE XPTR, BYTE XPTR);
/*global*/ BOOL NextOpt(BYTE XPTR XPTR, BYTE XPTR);
/*global*/ BOOL LibInitArg(BYTE XPTR, BYTE XPTR);
/*global*/ BOOL LibNextOpt(BYTE XPTR XPTR, BYTE XPTR);
/*global*/ VOID MakeReper(BYTE XPTR , BYTE XPTR);
/*global*/ SWORD FFile(BYTE XPTR, BYTE XPTR);
/*global*/ SWORD NFile(BYTE XPTR);
/*global*/ SWORD FRep(BYTE XPTR, BYTE XPTR);
/*global*/ SWORD NRep(BYTE XPTR);
/*global*/ VOID  diff_repfich(BYTE XPTR, BYTE XPTR, BYTE XPTR);
/*global*/ VOID make_full_path(BYTE XPTR, BYTE XPTR, BYTE XPTR);

#else
extern	SWORD FindFile();
extern	SWORD NextFile();
extern	SWORD FindRep();
extern	SWORD NextRep();

/*global*/ BINAIRE nb_niveau();
/*global*/ VOID MakeNom();
/*global*/ BOOL NextOpt();
/*global*/ VOID MakeReper();
/*global*/ SWORD FFile();
/*global*/ SWORD NFile();
/*global*/ SWORD FRep();
/*global*/ SWORD NRep();
/*global*/ VOID  diff_repfich();
/*global*/ VOID make_full_path();
/*global*/ BOOL LibInitArg();
/*global*/ BOOL LibNextOpt();

#endif

/*global*/ VOID MakeNom(BYTE XPTR rep, BYTE XPTR nom, BYTE XPTR ext, BYTE XPTR pt)
{
	BYTE m_ext[5];
	if (*nom == ' ' || *nom == EOSTR) {
		*pt = EOSTR;
	}
	else {
		Xstrcpy( m_ext, ext);
		if (m_ext[0] == '.' && m_ext[1] == EOSTR) m_ext[0] = EOSTR;
		if (m_ext[0] == '.' && m_ext[1] == ' ') m_ext[0] = EOSTR;
		if (m_ext[0] == '-' && m_ext[1] == EOSTR) m_ext[0] = EOSTR;
		if (m_ext[0] == '-' && m_ext[1] == EOSTR) m_ext[0] = EOSTR;
	
		if ((Xstrcmp(rep,"..")) == 0) {
			Xstrcpy(pt,rep);	
			Xstrcat(pt, DREP);
		}
		else {
			Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) misctmp, 1+2+4);
			if (misctmp[0] == EOSTR) MakeReper(rep,pt);
			else 	Xstrcpy(pt, misctmp);

		}

		Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) &misctmp[0], 8 );
		Xstrcat(pt,misctmp);
		Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) misctmp, 16);

		if (misctmp[0] == EOSTR) Xstrcat(pt, m_ext);
		else 	Xstrcat(pt,misctmp);
		
		Xfn_parser((BYTE FPTR) nom, (BYTE FPTR) &misctmp[0], 32|64);
		Xstrcat(pt,misctmp);	
	}
}


/*global*/ BOOL NextOpt(BYTE XPTR  XPTR pp, BYTE XPTR  dest)
{

	/* pp pointeur courant de chaine */

	while (1) {
		while (*(*pp) == ' ') {
			(*pp) ++; /* Padding des blancs */
		}
		if ((BYTE) *(*pp) ==  (BYTE) EOSTR) {
		   *dest = EOSTR;
		   return(FALSE);	/* fin de la ligne de commande */
		}
		else 	{
			/* termine les tokens par un zero */
			while (*(*pp) != ' ' && *(*pp) != EOSTR) {
				*dest++ = *(*pp);
				(*pp) ++;
			}

			*dest = EOSTR;

			return(TRUE);
		}
	}
}

/*global*/ VOID MakeReper(BYTE XPTR Nrep, BYTE XPTR Dnom)
{
	BINAIRE index;
	BYTE XPTR p;

	p = Nrep;
	NextOpt(&p, &misctmp[0]);

	if (misctmp[0] == EOSTR) {
		Dnom[0] = EOSTR;
	}
	else if ((Xstrcmp(misctmp,".")) == 0)  {
		Xstrcpy(Dnom,".");
		Xstrcat(Dnom,DREP);	
	}
	else {
		Xfn_parser((BYTE FPTR) misctmp,(BYTE FPTR) &Dnom[0], 2);
		if (Dnom[0] != EOSTR) {
			if ((BYTE) Dnom[Xstrlen(Dnom)-1] != (BYTE) SEPVOL[0]) {
				Xstrcat(Dnom, SEPVOL);
			}
		}

		Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) &Dnom[Xstrlen(Dnom)], 4);
		if (Dnom[0] != 0) {
			index = (BINAIRE) Xstrlen(Dnom);
			if ((BYTE) Dnom[index-1] != (BYTE) DELIMREP) {
				if (Dnom[index - 1] != (BYTE) SEPVOL[0])
					Xstrcat(Dnom, DREP);
			}
			else {
				if (index > 1) {
#ifdef prologue
					if (Dnom[index-2] == SEPVOL[0])
						Dnom[index-1] = EOSTR;
#endif
				}
/*
#ifdef msdos
				else {
					if (Dnom[0] == DELIMREP)  Xstrcat(Dnom,DREP); 
				}
#endif
*/
			}
		}

		Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) &Dnom[Xstrlen(Dnom)], 8);
#ifdef prologue
		if (Dnom[0] != 0) {
			if (Xstrlen(Dnom) == 3) {
				if ((isascii(Dnom[0])) && (isascii(Dnom[1])) && (isdigit(Dnom[2]))) {
					Xstrcat(Dnom, SEPVOL);
					return;
				}
			}
		}
#endif
		if ((Xstrcmp(misctmp,"..")) == 0)  {
			Xstrcpy(Dnom,"..");
		}
		else	{
			if ((BYTE) Dnom[Xstrlen(Dnom) - 1] != (BYTE) DELIMREP && (BYTE) Dnom[Xstrlen(Dnom)-1] != (BYTE) SEPVOL[0]) {
				Xstrcat(Dnom,DREP);
			}
		}
	}
}

/*global*/ SWORD FFile(BYTE XPTR what, BYTE XPTR res)
{
	SWORD ret;

#ifndef vms
	ret = (SWORD) FindFile(what,res);
#else
	ret = (SWORD) FindFile(what, misctmp);
#endif
	if (ret == MOINS_UN) return(ret);

#ifndef vms
	if ((Xstrcmp(res,".")) != 0) {
		return(ret);
	}
#else
	Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,16);
	if ((Xstrcmp(res,".DIR")) != 0) {
		Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,8);
		return(ret);
	}
#endif
	return((SWORD) (NFile(res)) );
}

/* global*/ SWORD NFile(BYTE XPTR res)
{
	SWORD ret;

	while (1) {
#ifndef vms
		ret = (SWORD) NextFile(res);
		/* pas de filtrage particulier */
		return(ret);
		
#else
		ret = (SWORD) NextFile(misctmp);
		if (ret == MOINS_UN) return(ret);
		Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,16);
		if ((Xstrcmp(res,".DIR")) != 0) {
			Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,8);
			return(ret);
		}
#endif
	}
}

/*global*/ SWORD FRep(BYTE XPTR what,BYTE XPTR res)
{
	SWORD ret;

#ifndef vms
	ret = (SWORD) FindRep(what, res);
#else
	ret = (SWORD) FindFile(what,misctmp);
#endif

	if (ret == MOINS_UN) return(ret);

#ifndef vms
	if ((Xstrcmp(res,".")) != 0) {
		 return(ret);
	}
#else
	if (ret == MOINS_UN) return(ret);
	Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,16);
	if ((Xstrcmp(res,".DIR")) == 0) {
		Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,8);
		return(ret);
	}
#endif		
	return((SWORD) (NRep(res)));
}

/*global*/ SWORD NRep(BYTE XPTR res)
{
	SWORD ret;

	while (1) {
#ifndef vms
		ret = (SWORD) NextRep(res);
		if (ret == MOINS_UN) return(ret);
		if ((Xstrcmp(res,".")) != 0)  return(ret);
#else
		ret = (SWORD) NextFile(misctmp);
		if (ret == MOINS_UN) return(ret);
		Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,16);
		if ((Xstrcmp(res,".DIR")) == 0) {
			Xfn_parser((BYTE FPTR) misctmp, (BYTE FPTR) res,8);
			return(ret);
		}
#endif
	}
}

VOID  diff_repfich(BYTE XPTR repertoire, BYTE XPTR fichier, BYTE XPTR resultat)
{
	BYTE misctmpA[LGREP];
	BYTE misctmpB[LGREP];
	BYTE misctmp[LGREP];
	BINAIRE niveauA;
	BINAIRE niveauB;
	BINAIRE i;
	BINAIRE boule;
	BINAIRE niveau;

	resultat[0] = EOSTR;
#ifndef diff
	
	/* Teste si cle d'acces */
	Xfn_parser((BYTE FPTR) fichier, (BYTE FPTR) resultat, 32);
	if (resultat[0] == EOSTR) {
		Xstrcpy(resultat,fichier);
	}
	else {
		Xfn_parser((BYTE FPTR) fichier, (BYTE FPTR) resultat, 1+2+4+8+16);
	}
	return;
#else

	Xfn_parser((BYTE FPTR) fichier, (BYTE FPTR) misctmp, 1 + 2 + 4);
	if (misctmp[0] == EOSTR ) {
		Xstrcpy(resultat, fichier);
		return;
	}

	/* cas du volume */
	Xfn_parser((BYTE FPTR) repertoire, (BYTE FPTR) misctmpA, 1 + 2);
	Xfn_parser((BYTE FPTR) fichier, (BYTE FPTR) misctmpB, 1 + 2);

	if (misctmpB[0] != EOSTR) {
		if (Xstrcmp(misctmpA, misctmpB) != 0) {
			Xstrcpy(resultat, misctmpB);
		}		
	}

	Xfn_parser((BYTE FPTR) repertoire, (BYTE FPTR) misctmpA, 4);
	Xfn_parser((BYTE FPTR) fichier, (BYTE FPTR) misctmpB, 4);
	if (misctmpB[0] != EOSTR) {
		make_full_path(misctmpA, misctmpB, misctmp);
		Xstrcpy(misctmpB, misctmp);
		boule = 0;
		i = 0;	
		while (boule == 0) {
			if (misctmpA[i] != misctmpB[i]) {
				if (misctmpA[i] == DELIMREP ||misctmpB[i] == DELIMREP) i -- ;
				boule = 2;
			}
			else if (misctmpA[i] == EOSTR && misctmpB[i] == EOSTR) {
				boule = 1;
			}
			else i++;
		}
		/* Si EOSTR : egal */
		switch (boule) {
			case 2:
				/* on se repositionne sur le delimiteur */
				/* pour le repertoire */
				niveauA = i;
				while (1) {
					if (niveauA == 0) break;
					if (misctmpA[niveauA] == DELIMREP) {
						niveauA++;
						break;
					}
					niveauA --;
				}
				/* pour le fichier */
				niveauB = i;
				while (1) {
					if (niveauB == 0) break;
					if (misctmpB[niveauB] == DELIMREP) {
						niveauB++;
						break;
					}
	
					niveauB --;
				}

				/* difference */

				niveau = (BINAIRE) nb_niveau((BYTE XPTR) &misctmpA[niveauA]);
				while (niveau > 0) {
					Xstrcat(&resultat[Xstrlen(resultat)], "..");
					Xstrcat(&resultat[Xstrlen(resultat)],DREP);
					niveau --;
				}
		
				/* on recopie les repertoires du fichier */
				i = (BINAIRE) Xstrlen(resultat);
				while ((BYTE) misctmpB[niveauB] != (BYTE) EOSTR) {
					resultat[i++] = misctmpB[niveauB++]; 
				}
				resultat[i] = EOSTR;
		}
	}

	Xfn_parser((BYTE FPTR) fichier, (BYTE FPTR) &resultat[Xstrlen(resultat)], 8 + 16);
#endif
}

BINAIRE nb_niveau(BYTE XPTR pt)
{	
	BINAIRE nb;

	nb = 0;

	while (*pt++) {
		if (*pt == DELIMREP) nb ++;
	}

	return(nb);
}

VOID make_full_path(BYTE XPTR prep, BYTE XPTR pfic,BYTE XPTR pres)
{
	BINAIRE i,j;
	BINAIRE nb_pp,nb_ni;
	BYTE xcase;


	nb_ni = nb_niveau(prep);
	
	nb_pp = 0;
	i = 0;
	xcase = 0;
	while (xcase != 1) {
		switch (xcase) {

			case 0 :
				if (*(pfic + i) == '.') {
					xcase = 2;
					i ++;
				}
				else xcase = 1;
				break;
			case 1:
				break;

			case 2:
				if (*(pfic + i) == DELIMREP) {
					xcase = 0;
					i ++;
				}
				else if (*(pfic + i) == '.') {
					xcase = 3;
					i ++;
				}
				else 	xcase = 1;			
				break;

			case 3:
				if (*(pfic + i) == DELIMREP) {
      					xcase = 4;
				}
				else 	{
					i = 0;
					xcase = 1;
				}

				break;
	
			case 4:
				/* un niveau de point point */
				nb_pp ++;
				i ++;
				xcase = 0;
				break;
	
		};
	}

	if (nb_ni >= nb_pp && nb_pp != 0) {
		/* reconstruction du nom complet */
		j = 0;
		while (1) {
			if (*(prep + j) == DELIMREP) {
				if (j) nb_pp --;
				if (nb_pp == 0) break;
			}
			*(pres + j) = *(prep + j);

			j ++;

			/* Mise a blanc */
			*(pres + j ) = EOSTR;

		}
		if (*(pres + j ) == EOSTR) {
			*(pres + j++) = DELIMREP;
			*(pres + j) = EOSTR;			
		}		
		/* on recopie le reste de l'arborescence */
		Xstrcat(pres, pfic + i);
	}
	else Xstrcpy(pres, pfic);
}
/*********************************
* FCT LibNextOpt
*
* Entree : 
*	un pointeur sur le pointeur de la ligne d'argument		
*	un pointeur  sur la variable de reception de la prochaine option
*
* Sortie :
*	TRUE  : option recopie
*	FALSE : fin de la ligne d'argument
*
* Remarque :
*	retourne le prochain argument situe dans une chaine
* 
**********************************/

BOOL LibNextOpt(BYTE XPTR XPTR pp, BYTE XPTR dest)
{
	BYTE XPTR lptr;

	/* pp pointeur courant de chaine */

	while (1) {
		while ((*(*pp) == ' ') || (*(*pp) == TABUL) || (*(*pp) == ',') ) {
			(*pp) ++; /* Padding des blancs et de la tabulation */
		}

		if ( (BYTE) *(*pp) == 0x0a || (BYTE) *(*pp) == 0x0d ) {
			/* passage a la ligne suivante */
			lptr = (BYTE XPTR) Xfgets((char *) Mainligarg,(BINAIRE) 256,(FILE *) Mainfarg);
			if (lptr == GenericNULL(BYTE)) {
				/* fin de fichier atteinte */
				   *dest = EOSTR;
				   return(FALSE);
			}
			Mainpt_arg = &Mainligarg[0];
			pp = &Mainpt_arg;
	
		}
		else {

			if (((BYTE) *(*pp) ==  (BYTE) EOSTR) || ((BYTE) *(*pp) == 0x1a 
				|| ((BYTE) *(*pp) == 0x0a) || ((BYTE) *(*pp) == 0x0d) ) ) {
			   *dest = EOSTR;
			   return(FALSE);
	
			  /* fin de la ligne de commande */
			}
			else 	{

				/* termine les tokens par un zero */
				while (*(*pp) != ' ' && *(*pp) != EOSTR && ((BYTE) *(*pp) != 0x0a) && ((BYTE) *(*pp) != 0x0d) && ((BYTE) *(*pp) != ',')) {
					*dest++ = *(*pp);
					(*pp) ++;
				}
	
				*dest = EOSTR;
				return(TRUE);
			}
		}
	}
}
	
/*********************************
* FCT LibInitArg
*
* Entree : 
*	la ligne d'argument se trouve dans le fichier p
*	recopie de la ligne du fichier dans 		
*
* Sortie :
*	rien
* 
* Remarque :
*	Va chercher dans le fichier la suite de la ligne d'argument
*
**********************************/

BOOL LibInitArg(BYTE XPTR p, BYTE XPTR ligarg)

/*	initialisations de la ligne de commande dans un fichier 
 *	a partir du fichier designe par la chaine 'p'
 */

{					/* init_arg */
	BYTE *lptr;
	BYTE nomargu[LGREP];
/*
	FILE *farg;
*/
	nomargu[0] = EOSTR;
	Xstrcpy(nomargu,(BYTE *) p);

	Mainfarg = Xfopen(nomargu,"r");
	if (Mainfarg == GenericNULL(FILE)) {
		return( FALSE );
	}

	lptr = (BYTE XPTR) Xfgets((char *) ligarg,(BINAIRE) 256,(FILE *) Mainfarg);
	if (lptr == GenericNULL(BYTE)) {
		*ligarg = EOSTR;
		return( FALSE );
	}
#ifdef merde
	/* enlever le dernier 0a */
	ligarg[Xstrlen(ligarg) - 1] = EOSTR;
#endif
	return (TRUE);
}					/* init_arg */

