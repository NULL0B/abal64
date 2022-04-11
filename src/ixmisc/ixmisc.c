/*--------------------------------------------------------- IXMISC.C ---------
 *
 *	Projet ABAL		-*-		Copyright (c) Amenesik / Sologic s.a.
 *
 *	     Fonctions diverses pour l'ensemble integre
 *	    assurant la poratibilite sous differents O.S.
 *
 *		     Version UNIX du 01/06/1989
 *
 *---------------------------------------------------------------------------*/

#include <string.h>
#include <unistd.h>

extern char *getcwd();
extern int system();

static char	commande[128];

int GetReper(rp,lg)

/*	Retourne la designation du repertoire courant
 */
char **rp;
int lg;
{						/* GetReper */
	*rp = getcwd(*rp ,lg);
	if (*rp == (char *) 0)
		return (-1);
	if (strlen(*rp) == 1)
		*(*(rp)) = '\0';	/* root directory ! */
	return (0);
}						/* GetReper */

int LoadGo(reper,prog,param)

/*	Chargement et execution du programme 'prog' avec le parametre 'param'
 *	a chercher dans le repertoire 'reper' en priorite, ou en deuxieme
 *	tentative, via le 'path' courant.
 *
 *	Retourne 0 si Ok, -1 si il y a eu une erreur
 */
char *reper,*prog,*param;
{						/* LoadGo */
	int	coderet;

 	strcpy(commande,reper); strcat(commande,"/");	/* modif du 01/06/89 */
	strcat(commande,prog);
	if (access(commande,0) != -1) {
		if (*param != '\0') {
			strcat(commande," "); strcat(commande,param);
		}
		coderet = system(commande);
	}
	else
		coderet = 1;
	if (coderet != 0) {
		strcpy(commande,prog);
		if (*param != '\0') {
			strcat(commande," "); strcat(commande,param);
		}
		coderet = system(commande);
		if (coderet != 0)
			return (-1);
	}
	return (0);
}						/* LoadGo */

int MkNom (nom,buf,ext,rep)

/*	construit la designation complete d'un fichier dans 'nom'
 *	a partir du contenu de 'buf', en tenant compte de l'extension 'ext'
 *	et du repertoire 'rep'. le repertoire 'rep' n'est mis en place
 *	que si 'buf' ne contient pas deja un repertoire, ou si 'buf'est vide.
 *	l'extension 'ext' n'est mise en place que si elle est non nulle.
 *	sinon, elle est enlevee de la designation.
 */
char *nom,*buf,*ext,*rep;
{						/* MkNom */
	*nom = '\0';
	if (buf == (char *) 0) {	/* buf est vide */
		strcpy(nom,rep);
		strcat(nom,"/");
	}
	else if (*buf != '/') {	/* pathname incomplet */
		if ((*buf == '\0') || (strchr(buf,'/') == (char *) 0)) {
			strcpy(nom,rep);
			strcat(nom,"/");
		}
	}
	strcat(nom,buf);
	if ((ext != (char *) 0) && (*ext != '\0')) {
		if (strchr(buf,'.') == (char *) 0) {
			strcat(nom,".");
			strcat(nom,ext);
		}
	}
	else {
		if (ext == (char *) 0) {
			if (strchr(nom,'.') != (char *) 0)
				*strchr(nom,'.') = '\0';
		}
	}
}						/* MkNom */
