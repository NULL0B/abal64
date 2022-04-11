/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1989 Prologue s.a.
 *
 *	mkp.c - creation de fichiers parametres ecran/clavier
 *
 *	$Header:   C:/cico/mkp.c@@   1.2   26 Sep 1989 15:15:00   NS  $
 *
 */


#include <stdio.h>
#ifdef vms
#include <file.h>
#else
#include <fcntl.h>
#ifndef MSDOS
#include <unistd.h>
#endif
#endif


/*
 * oublis de certains systemes
 */

#ifndef SEEK_SET
#define SEEK_SET	0
#endif

#ifndef SEEK_CUR
#define SEEK_CUR	1
#endif


/*
 * constantes diverses
 */

#define SIGNATURE	"CICO14"        /* signature du fichier         */
#define MODE		0644		/* mode de creation du fichier	*/


/*
 * variables diverses
 */

static int fd;			/* descripteur du fichier		*/
static int i;			/* compteur de boucles			*/
static int offset;		/* deplacement dans le table des chaines*/
static int lg_nom;		/* longueur du nom			*/
static int lg_nb;		/* longueur de la table des nombres	*/
static int lg_off;		/* longueur de la table des deplacements*/
static int lg_str;		/* longueur de la table des chaines	*/
static int lg_in = 256; 	/* longueur de la table conv. clavier	*/
static int lg_out = 256;	/* longueur de la table conv. ecran	*/
static int lg_totale;		/* longueur totale			*/
static unsigned short mot;	/* mot de 16 bits non signe		*/
static unsigned char octet[2];	/* octets de calcul de la checksum	*/
static unsigned char *buf;	/* buffer de reception des donnees	*/


/*
 * messages
 */

static char *mes[] = {
	"Creation fichier parametres pour CICO - le 07/08/1989",
	"Copyright (c) Prologue s.a. 1988, 1989",
	"terminal:",
	"cree",
	"creation impossible",
	"ecriture impossible",
	"positionnemt impossible",
	"lecture impossible",
	"allocation impossible",
};

#define MES_BANNIERE		mes[0]
#define MES_COPYRIGHT		mes[1]
#define MES_TERMINAL		mes[2]
#define MES_CREE		mes[3]
#define ERR_CREATION		mes[4]
#define ERR_ECRITURE		mes[5]
#define ERR_POSITIONNEMENT	mes[6]
#define ERR_LECTURE		mes[7]
#define ERR_ALLOCATION		mes[8]


/*
 * variables externes
 */

extern char *fichier;		/* nom du fichier			*/
extern char *nom;		/* nom du terminal			*/
extern int tab_nb[];		/* table des nombres			*/
extern char *tab_str[]; 	/* table des chaines			*/
extern char tab_in[];		/* table de conversion clavier		*/
extern char tab_out[];		/* table de conversion ecran		*/


/*
 * declaration des fonctions
 */

void aligne();
void itonorm();
void fin();


main()
{
	/* banniere */
	printf("%s\n%s %s\n%s\n\n", MES_BANNIERE, MES_TERMINAL, nom, MES_COPYRIGHT);

	/* creation du fichier */
#ifdef MSDOS
	if ((fd = open(fichier, O_RDWR | O_TRUNC | O_CREAT | O_BINARY, MODE)) == -1)
#else
	if ((fd = open(fichier, O_RDWR | O_TRUNC | O_CREAT, MODE)) == -1)
#endif
		fin(ERR_CREATION);

	/* ecriture de la signature */
	if (write(fd, SIGNATURE, 6) == -1)
		fin(ERR_ECRITURE);

	/* calcul des longueurs */
	lg_nom = strlen(nom) + 1;
	for (i = 0; tab_nb[i] != -1; i++)
		lg_nb +=2;
	for (i = 0; tab_str[i] != NULL; i++) {
		lg_off += 2;
		lg_str += strlen(tab_str[i]) + 1;
	}

	/* ecriture des longueurs */
	itonorm(lg_nom, &mot);
	if (write(fd, (char *)&mot, 2) == -1)
		fin(ERR_ECRITURE);
	itonorm(lg_nb, &mot);
	if (write(fd, (char *)&mot, 2) == -1)
		fin(ERR_ECRITURE);
	itonorm(lg_off, &mot);
	if (write(fd, (char *)&mot, 2) == -1)
		fin(ERR_ECRITURE);
	itonorm(lg_str, &mot);
	if (write(fd, (char *)&mot, 2) == -1)
		fin(ERR_ECRITURE);
	itonorm(lg_in, &mot);
	if (write(fd, (char *)&mot, 2) == -1)
		fin(ERR_ECRITURE);
	itonorm(lg_out, &mot);
	if (write(fd, (char *)&mot, 2) == -1)
		fin(ERR_ECRITURE);

	/* calcul de la longueur totale */
	lg_totale = lg_nom + lg_nb + lg_off + lg_str + lg_in + lg_out;
	if (lg_nom % 2)
		lg_totale++;
	if (lg_str % 2)
		lg_totale++;

	/* reservation de l'emplacement de la checksum */
	if (lseek(fd, 2L, SEEK_CUR) == -1L)
		fin(ERR_POSITIONNEMENT);

	/* ecriture du nom */
	if (write(fd, nom, lg_nom) == -1)
		fin(ERR_ECRITURE);
	aligne(lg_nom);

	/* ecriture des nombres */
	for (i = 0; tab_nb[i] != -1; i++) {
		itonorm(tab_nb[i], &mot);
		if (write(fd, (char *)&mot, 2) == -1)
			fin(ERR_ECRITURE);
	}
	aligne(lg_nb);

	/* ecriture de la table des deplacement */
	offset = 0;
	for (i = 0; tab_str[i] != NULL; i++) {
		itonorm(offset, &mot);
		offset += strlen(tab_str[i]) + 1;
		if (write(fd, (char *)&mot, 2) == -1)
			fin(ERR_ECRITURE);
	}
	aligne(lg_off);

	/* ecriture de la table des chaines */
	for (i = 0; tab_str[i] != NULL; i++)
		if (write(fd, tab_str[i], strlen(tab_str[i]) + 1) == -1)
			fin(ERR_ECRITURE);
	aligne(lg_str);

	/* ecriture de la table de conversion clavier */
	if (write(fd, tab_in, lg_in) == -1)
		fin(ERR_ECRITURE);
	aligne(lg_in);

	/* ecriture de la table de conversion ecran */
	if (write(fd, tab_out, lg_out) == -1)
		fin(ERR_ECRITURE);

	/* allocation du buffer de calcul de la checksum */
	if ((buf = (unsigned char *)malloc(lg_totale)) == NULL)
		fin(ERR_ALLOCATION);

	/* positionnement en debut de donnees */
	if (lseek(fd, 20L, SEEK_SET) == -1L)
		fin(ERR_POSITIONNEMENT);

	/* relecture des donnees */
	if (read(fd, (char *)buf, lg_totale) != lg_totale)
		fin(ERR_LECTURE);

	/* calcul de la checksum */
	octet[0] = octet[1] = 0;
	for (i = 0; i < lg_totale; i++) {
		octet[0] += buf[i];
		octet[1] += octet[0];
	}
	mot = octet[0] * 256 + octet[1];

	/* ecriture de la checksum */
	if (lseek(fd, 18L, SEEK_SET) == -1L)
		fin(ERR_POSITIONNEMENT);
	itonorm(mot, &mot);
	if (write(fd, (char *)&mot, 2) == -1)
		fin(ERR_ECRITURE);

	/* fermeture du fichier */
	close(fd);

	/* message de creation correcte */
	printf("%s %s\n", fichier, MES_CREE);
	fin(0);
}


/* normalisation d'un entier (conversion en mot de 16 bits notation inversee)
 * --------------------------------------------------------------------------
 *
 */
void itonorm(i, n)
int i;
unsigned short *n;
{
	unsigned char *p;

	p = (unsigned char *)n;
	*(p + 1) = i /256;
	i -= i / 256 * 256;
	*p = i;
}


/* alignement sur une adresse paire
 * --------------------------------
 *
 */
void aligne(longueur)
int longueur;
{
	char c = '\0';

	if (longueur % 2)
		if (write(fd, &c, 1) == -1)
			fin(ERR_ECRITURE);
}


/* fin du programme
 * ----------------
 *
 */
void fin(mes)
char *mes;
{
	close(fd);
	if (mes == NULL)
		exit(0);
	else {
		printf("%s: %s\n", fichier, mes);
		exit(1);
	}
}
