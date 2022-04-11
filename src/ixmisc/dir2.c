/* dir2.c
 *
 * lecture catalogue sous unix (ancienne methode : seulement sous Xenix)
 *
 * Mises a jour :
 * ------------
 *	21/01/91 : introduction recherche de repertoires
 *
 */

#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/stat.h>

char *path;		/* chemin du catalogue de recherche		*/
char *deb;		/* debut du nom apres le chemin			*/
FILE *fp;		/* descripteur du catalogue de recherche	*/
char gene[DIRSIZ + 1];	/* nom generique a rechercher			*/
ushort maskdir;		/* masque pour stat				*/


/* recherche dans un catalogue
 *
 * 'nomgene' peut soit un chemin suivi d'un nom generique soit un nom generique
 *           seul. Un nom generique peut comporter des caracteres joker tel
 *           que '*' (0 ou n caracteres) ou '?' (un caractere quelconque).
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

int FindFind(nomgene, nomfic)
char *nomgene;
char *nomfic;
{
	char *p;			/* pointeur sur la limite entre	*/
					/* le chemin et le nom		*/

	p = strrchr(nomgene, '/');	/* recherche de la fin du chemin */
	if (p != (char *) 0) {
		path = malloc(p - nomgene + DIRSIZ + 2);
		*p = '\0';		/* coupure entre le chemin et le nom */
		strcpy(gene, p + 1);
		strcpy(path, nomgene);
		strcat(path, "/");
		deb = path + strlen(path);
		fp = fopen(nomgene, "r");
		*p = '/';		/* remet 'nomgene' en etat */
	} else {
		path = malloc(DIRSIZ + 1);
		deb = path;
		strcpy(gene, nomgene);
		fp = fopen(".", "r");	/* pas de chemin, catalogue courant */
	}
	if (fp == (FILE *) 0) 
		return (-1);		/* erreur d'ouveture du catalogue */
	if (fseek(fp, (long)(2 * sizeof(struct direct)), 0) == -1)
		return (-1);		/* erreur lors du saut de . et .. */
	if (NextNext(nomfic) == -1)	/* recherche dans le catalogue */
		return (-1);
	else
		return (0);
}

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
	char fic[DIRSIZ + 1];		/* nom du fichier a comparer	*/
	struct direct ent;		/* entree du catalogue		*/
	struct stat sts;		/* status d'un fichier		*/
	
	fic[DIRSIZ] = '\0';		/* force une fin de chaine */
	do {
		do {
			if (fread((char *) &ent, sizeof(ent), 1, fp) < 1)
				return (-1);
			memcpy(fic, ent.d_name, DIRSIZ);
			strcpy(deb, fic);
			if ((ent.d_ino != (ino_t) 0) && stat(path,&sts) == -1)
				return (-1);	/* recherche du mode */
		} while ((ent.d_ino == (ino_t) 0) || 
			 ((maskdir == 0) ? (sts.st_mode & (ushort) 0070000) :
			 ((sts.st_mode & (ushort) 0070000) != 0040000)));
	} while (match(fic, gene) == -1);
	strcpy(nomfic, fic);	/* pour retour */
	return (0);
}

/* fin de recherche dans un catalogue
 * doit obligatoirement terminer une recherche
 */
int EndFile()
{
	free(path);		/* liberation du chemin */ 
	return (fclose(fp));	/* fermeture du catalogue */
}

/* comparaison d'un mot a un maque
 */
int match(mot, masque)
char *mot;
char *masque;
{	
	while ((*mot != '\0') && (*masque != '\0')) {
		switch (*masque) {
		case '*':
			while (*++masque == '*');	/* n '*' vaut 1 '*' */
			if (*masque == '\0')		
				return (0);		/* finit par 1 '*' */
			while (*mot != *masque) {
				if (*(++mot) == '\0')
					return (-1);
			}
			mot++; masque++;
			break;
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

