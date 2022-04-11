/* dir1.c
 *
 * lecture catalogue sous unix (Utilise opendir, readdir, closedir)
 * ----------------------------------------------------------------
 *
 * Mises a jour :
 *	20/11/91 : controle de la longueur du nom copie
 *	05/03/93 : amelioration controle precedent pour Dec Ultrix
 *
 */

#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>


/* #define direct dirent */

char *path;		/* chemin du catalogue de recherche		*/
char *deb;		/* debut du nom apres le chemin			*/
DIR *fp;		/* descripteur du catalogue de recherche	*/
char gene[MAXNAMLEN+1];	/* nom generique a rechercher			*/
ushort maskdir;		/* masque pour stat				*/

/* recherche dans un catalogue
 *
 * 'nomgene' peut soit un chemin suivi d'un nom generique soit un nom generique
 *           seul. Un nom generique peut comporter des caracteres joker tel
 *           que '*' (0 ou n caracteres) ou '?' (un caractere quelconque).
 * 'nomfic'  pointe la zone de reception du resultat.
 *
 * En sortie : 0 indique une reussite, -1 un echec
 *
 */
int FindRep(nomgene,nomfic)
char *nomgene;
char *nomfic;
{ maskdir = 1;
  return(FindFind(nomgene,nomfic));
}

int FindFile(nomgene,nomfic)
char *nomgene;
char *nomfic;
{ maskdir = 0;
  return(FindFind(nomgene,nomfic));
}


/* Recherche du premier ...
 */
int FindFind(nomgene, nomfic)
char *nomgene;
char *nomfic;
{
	char *p;			/* pointeur sur la limite entre	*/
					/* le chemin et le nom		*/

	p = strrchr(nomgene, '/');	/* recherche de la fin du chemin */
	if (p != (char *) 0) {
		path = malloc(p - nomgene + MAXNAMLEN + 2);
		*p = '\0';		/* coupure entre le chemin et le nom */
		strcpy(gene, p + 1);
		strcpy(path, nomgene);
		strcat(path, "/");
		deb = path + strlen(path);
		fp = opendir(nomgene);
		*p = '/';		/* remet 'nomgene' en etat */
	} else {
		path = malloc(MAXNAMLEN + 1);
		deb = path;
		strcpy(gene, nomgene);
		fp = opendir(".");	/* pas de chemin, catalogue courant */
	}
	if (fp == (DIR *) 0) 
		return (-1);		/* erreur d'ouveture du catalogue */
	if (NextNext(nomfic) == -1)	/* recherche dans le catalogue */
		return (-1);
	else
		return (0);
}

/* suite de recherche de fichier/repertoire dans un catalogue
 */
int NextFile(nomfic)
char *nomfic;
{
	maskdir = 0;
	return(NextNext(nomfic));
}

int NextRep(nomfic)
char *nomfic;
{
	maskdir = 1;
	return(NextNext(nomfic));
}


/* suite de recherche dans un catalogue
 */
int NextNext(nomfic)
char *nomfic;
{
	char fic[MAXNAMLEN + 1];	/* nom du fichier a comparer	*/
	struct direct *ent;		/* entree du catalogue		*/
	struct stat sts;
	ushort e,f;
	int lgr;

	/* Force une fin de chaine sur le nom en construction */
	fic[MAXNAMLEN] = '\0';

	/* Tant qu'il reste des fichiers dans le repertoire et
	 * que le fichier courant ne correspond pas au masque
	 * de recherche, on continue de boucler.
	 */
	do {
		/* Est-on parvenu a la fin du repertoire ? */
		if ((ent = readdir(fp)) == (struct direct *) 0)
			return (-1);

		/* Controle la longueur a copier */
		lgr = ent->d_reclen;
		if (lgr > MAXNAMLEN)
			lgr = MAXNAMLEN;
		if (lgr != 0) {
			memcpy(fic, ent->d_name,lgr);
		}

		/* Termine correctement le nom du fichier */
		fic[lgr] = '\0';
		strcpy(deb, fic);

		/* Controle l'accessibilite du fichier */
		e = stat(fic,&sts);
		if (e)
			f = 1;
		else
			f = (maskdir == 0) ? (sts.st_mode & (ushort) 0070000) :
		    	    ((sts.st_mode & (ushort) 0070000) - 0040000);
	} while ((match(fic, gene) == -1) || (f));

	/* Le fichier convient : on copie une derniere fois le
	 * nom pour le retourner a l'appelant.
	 */
	strcpy(nomfic,fic);
	return (0);
}

/* fin de recherche dans un catalogue
 * doit obligatoirement terminer une recherche
 */
int EndFile()
{
	free(path);		/* liberation du chemin */ 
	closedir(fp);
	return (0);	/* fermeture du catalogue */
}

/* comparaison d'un mot a un maque
 */
int match(mot, masque)
char *mot;
char *masque;
{
	while (*mot != '\0' && *masque != '\0') {
		switch (*masque) {
		case '*':
			while (*++masque == '*');	/* n '*' vaut 1 '*' */
			if (*masque == '\0')		
				return (0);		/* finit par 1 '*' */
			while (*mot != '\0')
				if (match(mot++, masque) == 0)
					return (0);
			return (-1);
		case '?':
			mot++;
			masque++;
			break;
		default:
			if (*mot++ != *masque++)
			return (-1);
		}
	}
	if (*mot != '\0')	 
		return (-1);		/* il reste des caracteres */
	if (*masque != '\0')
		while (*masque != '\0')		/* il reste des masques */
			if (*masque++ != '*')
				return (-1);	/* si ce ne sont pas des '*' */
	return (0);
}

