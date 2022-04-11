#ifndef	_ixlo_c
#define	_ixlo_c

#include "ixlo.h"
#include "exaccess.h"
#include "ixmima.c"

/************************************************************************
 *									*
 *	Primitives internes de gestion imprimante			*
 *									*
 ***********************************************************************/

VOID _lo_pushpage()
{
	char *	nptr;
	int	mode;
	/* Copy Current Syntax */
	/* ------------------- */
	mode = courante->mode;
	if ((nptr = (BYTE *)allocate(strlen(courante->syntaxe) + 1)) == NULL) {
		_lo_close();
		err_val = 27;
		return;
		}
	strcpy(nptr,courante->syntaxe);
	_lo_close();

	_lo_open( nptr );
	liberate( nptr );
	return;
}

	
VOID _lo_start()
{
	if (flag_buflo == FALSE) {
		flag_buflo = TRUE;
	}
}


VOID _lo_flush()
{
	if (flag_buflo == TRUE) {
		if (out_nblo != 0) {
			if (losyswrite(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo) {
				err_val = EXER_DEVFAIL;	/* erreur */
#ifdef EXABAL
				sprintf(SysLogBuffer, "Error: _lo_flush failed, err_val=%d", err_val);
				ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
			}
			out_nblo = 0;
		}
		flag_buflo = FALSE;
	}
}

int	euroconv=-1;
int	default_euro_conversion()
{
	char *	eptr;
	int	e=0;
	if ( euroconv != -1 )
		return( euroconv );
	else if (( eptr = getenv("ABALEUROCHAR") ) != (char *) 0)
		return((euroconv=*eptr));
	else if (( eptr = getenv("ABALEUROVAL") ) != (char *) 0)
		return((euroconv=atoi(eptr)));
	else	return((euroconv=0));
}

/* edition d'un caractere sur imprimante
 * -------------------------------------
 *
 * appel:	caractere a editer
 *
 * retour:	rien
 *
 */
INTERFACE	WORD 	local_x_lo(c)
WORD 		c;
{
	WORD	e=0;
	int	i;
	WORD colonne;

	if (courante == NULL) {
		if (prnfid == 0) {
			if (c == SUB)
				return(0);
			if (_lo_defaut() != 0)
				return(0);
			}
		else 	{
			if (c != SUB)
				err_val = 42;
			return(0);
			}
		}

	/* Detect request for Transparence */
	/* ------------------------------- */
	if ( courante->xcico ) {
		_lo_out(c);
		return(0);
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
#if EXABAL___ && !MPAGE
			_co_out(BEL);
#else
			_lo_out(BEL);
#endif /* EXABAL && !MPAGE */
			break;
		case CR:
			if (!( courante->carriage ))
				_lo_out(CR);
			courante->colonne = 0;
			break;
		case LF:
			courante->ligne++;
			if (!( courante->linefeed ))
				_lo_out(LF);
#if EXABAL && !MPAGE
			if (!( courante->carriage ))
				_lo_out(CR);
			courante->colonne = 0;
#endif /* EXABAL && !MPAGE */
			if ( courante->feeding ) {
				courante->feedcount++;
				if ( courante->feedcount >= courante->feeding )
					_lo_pushpage();
				}
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
			if (!( courante->formfeed ))
				_lo_out(FF);
#if EXABAL && !MPAGE
			if (!( courante->carriage ))
				_lo_out(CR);
#endif /* EXABAL && !MPAGE */
			break;
		case SUB:
#if EXABAL && !MPAGE
			if (courante->flag == TRUE) {
				if (!( courante->carriage ))
					_lo_out(CR);
#ifdef vms
				if (!( courante->linefeed ))
					_lo_out(LF);
#endif /* vms */
				}
#endif /* EXABAL && !MPAGE */
			_lo_close();
			break;
#if EXABAL && !MPAGE
		case FS:
			_lo_out(FS);
			if (!( courante->carriage ))
				_lo_out(CR);
			break;
#endif /* EXABAL && !MPAGE */
		default:
			if (c >= ' ') {
				if ( c == 0x009B ) {
					if ((e = default_euro_conversion()) != 0) {
						local_x_lo('C');
						local_x_lo( 8 );
						local_x_lo( e );
						break;
						}
					}					
				courante->colonne++;
				if (courante->jeu != NO_CASE)
					c = ix_case_conversion(c, courante->jeu);
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
		/*—	--------------------- 	*/
		/* 	extensions for abal 3 	*/
		/*—	--------------------- 	*/
			courante->linefeed=0;
			courante->carriage=0;
			courante->formfeed=0;
			break;

		case 'A': courante->linefeed=1; break;	/* inhibits linefeed 		*/
		case 'D': courante->carriage=1; break;	/* inhibits carriage return	*/
		case 'C': courante->formfeed=1; break;	/* inhibits formfeed		*/

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
	return(0);
}


/* edition d'un caractere 8 bits
 * -----------------------------
 *
 * appel:	caractere a envoyer
 *
 * retour:	rien
 *
 */

PRIVATE VOID _lo_conv(c)
BYTE c;
{
	int	i;
	BYTE *p;
	BYTE longueur;

	if (courante == NULL) {
		if (prnfid == 0) {
			if (_lo_defaut() != 0)
				return;
			} 
		else 	{
			err_val = 42;
			return;
			}
		}

	if (( c > ' ' )
	&&  (courante->tbl_table != NULL)) {
		if (courante->tbl_table[c] == 0xff) {
			if ((p = (BYTE *)memchr(courante->tbl_tampon, c, courante->tbl_lg_tampon)) == NULL) {
				err_val = EXER_DEVFAIL;
#ifdef EXABAL
				sprintf(SysLogBuffer, "Error: _lo_conv failed, err_val=%d", err_val);
				ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
				return;
				}
			p++;
			longueur = *p;
			p++;
			while (longueur--)
				_lo_out(*p++);
			return;
			} 
		else	c = courante->tbl_table[c];
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

PRIVATE VOID _lo_out(c)
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
			activate_local_lo(courante->handle);
			/* activation de l'imprimante locale */
			IMP_LOC_ACTIVE=TRUE;
			}
		}
	else 	terminate_local_lo();
/* Modif : 28/10/91 - TEST du flag : ON ERROR GOTO ACTIF */

#ifdef EXABAL
	if ( flag_buflo == TRUE ) {
		if ( out_nblo >= DIM_OUT_BUF ) {
			if ( prnflag & 0x0010 ) {
				/* On Error actif */
				if ( losyswrite(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo ) {
					err_val = EXER_DEVFAIL;
					sprintf(SysLogBuffer, "Error: _lo_out failed: Step 1, err_val=%d", err_val);
					ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
				}
			} else {
				while ( losyswrite(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo );
			}			
			out_nblo = 0;
		}
		*(out_buflo + out_nblo++) = c;
	} else {
		if ( prnflag & 0x0010 ) {
			/* On Error actif */
			if (losyswrite(courante->handle, (CHAR *)&c, 1) != 1) {
				err_val = EXER_DEVFAIL;
				sprintf(SysLogBuffer, "Error: _lo_out failed: Step 2, err_val=%d", err_val);
				ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
			}
		} else {
			while ( losyswrite(courante->handle, (CHAR *)&c, 1) != 1 );
		}
	}	
#else
	if ( flag_buflo == TRUE ) {
		if ( out_nblo >= DIM_OUT_BUF ) {
			if ( losyswrite(courante->handle, out_buflo, (unsigned) out_nblo) != out_nblo ) {
				err_val = EXER_DEVFAIL;
			}
			out_nblo = 0;
		}
		*(out_buflo + out_nblo++) = c;
	} else {
		if (losyswrite(courante->handle, (CHAR *)&c, 1) != 1) {
			err_val = EXER_DEVFAIL;
		}
	}	
#endif	/* EXABAL */

#else	/*IMPLOC*/
	if (losyswrite(courante->handle, (CHAR *)&c, 1) != 1) {
		err_val = EXER_DEVFAIL;
#ifdef EXABAL
		sprintf(SysLogBuffer, "Error: _lo_out failed: Step 3, err_val=%d", err_val);
		ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
	}
#endif	/*IMPLOC*/
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
PRIVATE WORD _lo_tbl_charge(nom)
BYTE *nom;
{
	int fh = -1;			/* handle du fichier tbl	*/
	BYTE *complet;			/* nom complet du fichier tbl	*/
	BYTE entete[64];		/* entete du fichier tbl	*/
	BYTE mot[2];			/* mot de 16 bits		*/
	WORD longueur = 0;		/* longueur			*/
	WORD status = 0;		/* etat du chargement		*/

	/* Detect Request for Transparence */
	/* ------------------------------- */
	if (!( strcmp( nom, "XCICO" ) )) {
		courante->xcico=1;			
		return(0);
		}

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
		}
	else	*complet = '\0';
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
#if defined(EXABAL) && !defined(vms)
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
PRIVATE VOID _lo_tbl_init(numero)
WORD numero;
{
	int i;
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
PRIVATE VOID _lo_tbl_attribut(numero)
WORD numero;
{
	int i;
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
PRIVATE int  _conv_sleep(cmd, spl)
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
		*ptr=(BYTE) ix_case_conversion( (WORD) *ptr, 0);
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
PRIVATE WORD _lo_open(name, mode)
BYTE *name;
WORD mode;
{
	BYTE *envname=NULL;
	int i;			/* compteur de boucles		*/
	BYTE *p;			/* pointeur de travail		*/
	BYTE *nom = NULL;		/* duplication du nom d'appel   */
	BYTE *tbl = NULL;		/* nom du fichier TBL		*/
	BYTE *spool = NULL;		/* nom de l'utilitaire de spool */
	BYTE *sommeil = NULL;		/* commande de la tempo imp	*/
	BYTE *feeder = NULL;		/* nombre de lignes spool flush */
	struct stat stbuf;		/* caracteristiques du fichier	*/
	int	feeding=0;		/* line counter for flush	*/
	int fh; 			/* handle du fichier imprimante */
	int oflag;			/* flag d'ouverture imprimante  */
#ifdef SHAREDLO
	WORD accmode;

	if (sharedlo != 0)		/* partageabilite imprimante 	*/
	 {
		accmode = (mode & 2)? 1:0;
	 }
	else
	 {
		accmode = 1;
	 };
#endif

	/* recherche d'une structure de description disponible */
	if ((courante = (imprimante_st *)allocate(sizeof(imprimante_st))) == NULL) {
		err_val = 27;
		return (-1);
	}
	courante->syntaxe=NULL;
	courante->nom = NULL;
#ifdef IMPLOC
	courante->local = FALSE;
#endif /*IMPLOC*/
	courante->mode=0;
	courante->feeding=0;
	courante->feedcount=0;
	courante->linefeed=0;
	courante->carriage=0;
	courante->formfeed=0;
	courante->xcico = 0;
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
#ifdef SHAREDLO
	/* pour compatibilit‚ impressions Amenesik / Sologic */

	envname = getenv(name);
	if ( envname  != NULL)
	  {
		if ((nom = (BYTE *)allocate(strlen(getenv(name)) + 1)) != NULL)
		  strcpy (nom,getenv(name));
	  }
	else
	  {
		if ((nom = (BYTE *)allocate(strlen(name) + 1)) != NULL)
		  strcpy (nom,name);
          }
	if (nom == NULL)
	  {
		_lo_close();
		err_val = 27;
		return (-1);
	  }
#else
	if ((nom = (BYTE *)allocate(strlen(name) + 1)) == NULL) {
		_lo_close();
		err_val = 27;
		return (-1);
	}
	strcpy(nom, name);

#endif
	courante->mode = mode;
	if ((courante->syntaxe = (BYTE *)allocate(strlen(nom) + 1)) == NULL) {
		_lo_close();
		err_val = 27;
		return (-1);
		}
	strcpy(courante->syntaxe,nom);


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
				if ((p = (BYTE *)strchr(p, IMP_SEPARATEUR)) != NULL) {
					*p = '\0';
					if ( *sommeil == *p)
						sommeil = NULL;
					feeder = ++p;
					feeding=0;
					while ( *feeder ) {
						if (( *feeder >= '0' ) && ( *feeder <= '9' ))
							feeding += ((feeding * 10) + ( *(feeder++) - '0' ));
						else	break;
						}

					}
				else	p = sommeil;
				} 
			else	p = spool;
			} 
		else	p = tbl;
		if ((p = (BYTE *)strchr(p, ')')) != NULL)
			*p = '\0';
		}

	courante->feeding = feeding;

	/* calcul de la temporisation de l'imprimante */
	/* ------------------------------------------ */	
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
		if ( enter_local == NULL ) {
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
		err_val = EXER_DEVFAIL;
		_lo_close();
		return (-1);
	}
#else
#ifdef EXABAL
#ifdef SHAREDLO
	if (Access(courante->nom, W_OK, accmode) == 0) {
#else
	if (Access(courante->nom, W_OK, 1) == 0) {
#endif
#else
	if (access(courante->nom, W_OK) == 0) {
#endif /* EXABAL */
		if (stat(courante->nom, &stbuf) != 0) {
			err_val = EXER_DEVFAIL;
			_lo_close();
#ifdef EXABAL
			sprintf(SysLogBuffer, "Error: _lo_open failed: Step 1, err_val=%d", err_val);
			ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
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
			err_val = EXER_DEVFAIL;
			_lo_close();
#ifdef EXABAL
			sprintf(SysLogBuffer, "Error: _lo_open failed: Step 2, err_val=%d", err_val);
			ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
			return (-1);
		}
	} else if (errno == ENOENT) {
		errno = 0;
		oflag = O_WRONLY | O_CREAT | O_SYNC;
		if (mode & 4)
			oflag &= ~O_SYNC;
		if ((fh = open(courante->nom, oflag, 0666)) == -1) {
			err_val = EXER_DEVFAIL;
			_lo_close();
#ifdef EXABAL
			sprintf(SysLogBuffer, "Error: _lo_open failed: Step 3, err_val=%d", err_val);
			ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
			return (-1);
		}
#ifdef EXABAL
#ifdef SHAREDLO
		Access(nom, W_OK, accmode);
#else
		Access(nom, W_OK, 1);
#endif
#endif /* EXABAL */
	} else {
#ifdef EXABAL
		if (errno == 44)
			err_val = errno;
		else {
			err_val = EXER_DEVFAIL;
			sprintf(SysLogBuffer, "Error: _lo_open failed: Step 4, err_val=%d", err_val);
			ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
		}
#else
		err_val = EXER_DEVFAIL;
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
			activate_local_lo(courante->handle );
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
		err_val = EXER_DEVFAIL;
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
		if ((enter_local == NULL ) && (strncmp(spool,"LOCAL",5) == 0 )) {
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
#ifdef	VERSION666
extern	void	iof_screen_manager();
extern	void	set_worker(void *);
extern	int	x_system(char *);

/*	For CICO and external callers 	*/
/*	-----------------------------	*/
int	exa_system(char * command)
{
	int	x;
	set_worker( iof_screen_manager );
	x = x_system( command );
	set_worker( (void *) 0);
}
#else
#define exa_system(c) system(c)
#endif


/* fermeture d'une imprimante
 * --------------------------
 *
 * appel:	rien
 *
 * retour:	rien
 *
 */
PRIVATE VOID _lo_close()
{
	int	lo_failure=0;
	if (courante != NULL) {
		if (courante->handle != -1) {
			_lo_tbl_init(1);
			}
		else	lo_failure=1;

#if EXABAL && !vms
		if (courante->nom != NULL && *courante->nom != '\0')
			liberlox(courante->nom);
#endif /* EXABAL && !vms */
#ifdef IMPLOC
		if ( courante->local == TRUE) {
			terminate_local_lo();	
			}
#endif /*IMPLOC*/
		if (courante->handle != -1) {
			cicoclose(courante->handle);
			}
		if (!( lo_failure )) {

			if (courante->spool != NULL) {
#ifdef IMPLOC
				if ( strncmp(courante->spool, "LOCAL",5) == 0 ) {
					BYTE *sp_loc;
	 				int fh;	
	 				int oflag;		

					if ((sp_loc = (BYTE *)allocate(strlen(courante->spool)*2+10)) == NULL) {
						err_val = 27;
						} 
					else	{
 						oflag = O_WRONLY;
 						if ((fh = open(ttyname(STDOUT), oflag, 0)) == -1) {
 							err_val = EXER_DEVFAIL;
#ifdef EXABAL
							sprintf(SysLogBuffer, "Error: _lo_close failed: Step 1, err_val=%d", err_val);
							ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
 							}
						else 	{
							activate_local_lo(fh);
							strcpy(sp_loc,"cat ");
							strcat(sp_loc, courante->spool+5);
							strcat(sp_loc,";rm ");
							strcat(sp_loc, courante->spool+5);
							exa_system(sp_loc);
							cancel_local_lo(fh);
 							if (fh != -1)
 								cicoclose(fh);
							}
							liberate(sp_loc); 
						}
					} 
				else 	{
#endif /*IMPLOC*/
#ifdef vms
					if (exa_system(courante->spool) != 1) {
#else
					if (exa_system(courante->spool) != 0) {
#endif /* vms */
						err_val = EXER_DEVFAIL;
#ifdef EXABAL
						sprintf(SysLogBuffer, "Error: _lo_close failed: Step 2, err_val=%d", err_val);
						ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
					}
#ifndef vms
					if (courante->nom != NULL && *courante->nom != '\0')
						unlink(courante->nom);
#endif /* vms */
#ifdef IMPLOC
					}
#endif /* IMPLOC */

				}
			}
		if (courante->spool )
			liberate((CHAR *)courante->spool);
		if (courante->syntaxe != NULL)
			liberate((CHAR *)courante->syntaxe);
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
PRIVATE WORD _lo_defaut()
{
	if (tbl_defaut != NULL && *tbl_defaut != '\0') {
		prnfid = 0;
		if (_lo_open(tbl_defaut, 4) != 0) {
/* DIT:1053     */
			if ( err_val != 44 ) {
				err_val = EXER_DEVFAIL;
#ifdef EXABAL
				sprintf(SysLogBuffer, "Error: _lo_defaut failed: Step 1, err_val=%d", err_val);
				ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
			}
/* FIN DIT:1053 */
			return (1);
		}
	} else {
		err_val = EXER_DEVFAIL;
#ifdef EXABAL
		sprintf(SysLogBuffer, "Error: _lo_defaut failed: Step 2, err_val=%d", err_val);
		ExaSysLog(2 /*LOG_ERROR*/, SysLogBuffer);
#endif
		return (1);
	}
	return (0);
}

PRIVATE	VOID	_lo_pos(ligne,colonne)
int ligne;
int colonne;
{
	int	i;
	if (courante == NULL) {
		if (prnfid == 0) {
			if (_lo_defaut() != 0)
				return;
			}
		 else 	{
			err_val = 42;
			return;
			}
		}
	ligne--;	colonne--;
	if (ligne > courante->ligne) {
		for (i = courante->ligne; i < ligne; i++)
			_lo_out(LF);
		courante->ligne = ligne;
		}
	if (colonne < courante->colonne) {
		_lo_out(CR);
		i = 0;
		}
	else	i = courante->colonne;
	for (; i < colonne; i++)
		_lo_out(' ');
	courante->colonne = colonne;
	return;
}

PRIVATE	WORD	_lo_col()
{
	if (courante == NULL) {
		if (prnfid == 0) {
			if (_lo_defaut() != 0)
				return (0);
			}
		 else	{
			err_val = 42;
			return (0);
			}
		}
	return (courante->colonne + 1);
}

PRIVATE	WORD	_lo_lin()
{
	if (courante == NULL) {
		if (prnfid == 0) {
			if (_lo_defaut() != 0)
				return (0);
			}
		 else	{
			err_val = 42;
			return (0);
			}
		}
	return (courante->ligne + 1);
}

#endif	/* ix_lo_c */

