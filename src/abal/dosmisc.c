/*--------------------------------------------------------- DOSMISC.C ---------
 *
 *	Projet ABAL		-*-		Copyright (c) Amenesik / Sologic s.a.
 *
 *	     Fonctions diverses pour l'ensemble integre
 *	    assurant la portabilite sous differents O.S.
 *
 *		     Version DOS du 14/05/1988
 *
 *---------------------------------------------------------------------------*/
typedef unsigned char BOOL;
typedef unsigned short int BINAIRE;	/* type binaire sur 2 octets */
typedef unsigned char BYTE;		/* type binaire sur 1 octet */
typedef short int SWORD; 		/* int 16 octet signe */
typedef void VOID;
#define MOINS_UN -1
#define XPTR *

#include <process.h>
#include <stdio.h>
#include <stddef.h>
#include <dos.h>
#include <direct.h>
#include <string.h>

/*global*/ struct find_t c_file;
static  BYTE	commande[128];

#define Xstrcat(s,p) strcat( (char *) s, (char *) p)
#define Xstrchr(s,c) strchr((char *) s, (char) c)
#define Xstrcmp(s,p) strcmp( (char *) s,  (char *) p)
#define Xstrncmp(s,p,n) strncmp( (char *) s, (char *) p, (int) n)
#define Xstrcpy(d,s) strcpy( (char *) d, (char * ) s)
#define Xstrlen(s) strlen( (char * ) s)
#define Xstrrchr(s,c) strrchr( (char *) s, (char) c)


#ifdef LINT_ARGS
SWORD internal(BYTE XPTR);
SWORD GetReper(BYTE XPTR XPTR, SWORD);
SWORD LoadGo(BYTE XPTR , BYTE XPTR , BYTE XPTR);
SWORD FindFile(BYTE XPTR, BYTE XPTR );
SWORD NextFile(BYTE XPTR );
SWORD FindRep(BYTE XPTR, BYTE XPTR);
SWORD NextRep(BYTE XPTR);
SWORD SetDisk(BINAIRE);
SWORD Xchdir(BYTE XPTR);
#else
 SWORD internal();
SWORD GetReper();
SWORD LoadGo();
SWORD FindFile();
SWORD NextFile();
SWORD FindRep();
SWORD NextRep();
SWORD SetDisk();
SWORD Xchdir();
#endif



SWORD GetReper(BYTE XPTR XPTR rp, SWORD lg)

/*	Retourne la designation du repertoire courant
 */
{						/* GetReper */
	*rp = (BYTE XPTR) getcwd(*rp ,lg);
	if (*rp == (char *) 0)
		return (-1);
	return (0);
}						/* GetReper */

SWORD LoadGo(BYTE XPTR reper, BYTE XPTR prog, BYTE XPTR param)

/*	Chargement et execution du programme 'prog' avec le parametre 'param'
 *	a chercher dans le repertoire 'reper' en priorite, ou en deuxieme
 *	tentative, via le 'path' courant.
 *
 *	Retourne 0 si Ok, -1 si il y a eu une erreur
 */
{						/* LoadGo */
	SWORD	rep;

	if (internal(prog) == 1) {
		Xstrcpy(commande,prog);
		if ((BYTE) *param != (BYTE) '\0') {
			Xstrcat(commande," "); Xstrcat(commande,param);
		}
  		rep = system(commande);
	}
	else {
		Xstrcpy(commande,reper); Xstrcat(commande,"\\");
		Xstrcat(commande,prog);
/*		if (*param != '\0') {
			strcat(commande," "); strcat(commande,param);
		}*/
/*rep = system(commande);*/
		rep = spawnl(P_WAIT,commande,commande,param,NULL);
	}
	return (rep);
}						/* LoadGo */
#define NBINT 21
 BYTE comint[NBINT] [7] = {
"CD","CHDIR","CLS","COPY","DATE","DEL","DIR","ERASE","MKDIR","MD","PATH",
"RD","REN","RENAME","RMDIR","SET","TIME","TYPE","VER","VERIFY","VOL"
};

 SWORD internal(BYTE XPTR prog)

/*	teste si prog est une commande SWORDerne du DOS
 *	et si oui retourne la valeur 1
 */
{						/* internal */
	SWORD	i,c;

	for (i = 1; i < NBINT; i++) {
		c = Xstrcmp(comint[i],prog);
		if (c == 0)
			return (1);
		else if (c > 0)
			break;
	}
	return (0);
}						/* internal */

SWORD FindFile(BYTE XPTR nomgene, BYTE XPTR nomfic)

/*	Recherche du premier fichier correspondant au modele 'nomgene'
 *	et retourne son nom dans 'nomfic'.
 *	retourne -1 si aucun fichier n'est trouve.
 */
{						/* FindFile */
	if (_dos_findfirst(nomgene,(_A_NORMAL | _A_RDONLY),&c_file) != 0)
		return (MOINS_UN);
	Xstrcpy(nomfic,c_file.name);
	return (0);
}						/* FindFile */

SWORD NextFile(BYTE XPTR nomfic)

/*	Recherche du fichier suivant correspondant au modele 'nomgene'
 *	et retourne son nom dans 'nomfic'
 *	Doit suivre un appel a FindFile
 *	retourne -1 si aucun fichier n'est trouve
 */
{						/* NextFile */
	if (_dos_findnext(&c_file) != 0)
		return (MOINS_UN);
	Xstrcpy(nomfic,c_file.name);
	return (0);
}						/* NextFile */

SWORD FindRep(BYTE XPTR nomgene, BYTE XPTR nomfic)

/*	Recherche du premier fichier correspondant au modele 'nomgene'
 *	et retourne son nom dans 'nomfic'.
 *	retourne -1 si aucun fichier n'est trouve.
 */
{						/* FindFile */
	if (_dos_findfirst(nomgene,_A_SUBDIR,&c_file) != 0)
		return (MOINS_UN);
	Xstrcpy(nomfic,c_file.name);
	return (0);
}						/* FindFile */

SWORD NextRep(BYTE XPTR nomfic)

/*	Recherche du fichier suivant correspondant au modele 'nomgene'
 *	et retourne son nom dans 'nomfic'
 *	Doit suivre un appel a FindFile
 *	retourne -1 si aucun fichier n'est trouve
 */

{						/* NextFile */
	while(1) {
		if (_dos_findnext(&c_file) != 0)
			return (MOINS_UN);
		if (c_file.attrib & _A_SUBDIR) break;
	}
	Xstrcpy(nomfic,c_file.name);
	return (0);
}						/* NextFile */

SWORD SetDisk(BINAIRE nd)
{
	SWORD nbdrive;

	_dos_setdrive(nd,&nbdrive);
	if (nd > nbdrive) 	return(MOINS_UN); /* erreur */
	else 		  	return(0); /* bien pass‚ */

}

SWORD Xchdir(BYTE XPTR pt)
{
	return((SWORD) (chdir((char *) pt)));
}
