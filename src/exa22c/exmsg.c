/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMSG-C					*/
/*		Version :	1.4c					*/
/*		Date 	:	12/10/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

/*	Messages de l'executeur et moniteur ABAL norme GESMES 		*/
/*	-----------------------------------------------------		*/
/*	Cette fichier permet de generer une version EXA / EXADB qui 	*/
/*	est compatible avec la norme GESMES pour DEC RISC, BULL BOS	*/
/*	--------------------------------------------------------------	*/

/*	Messages d'identification EXA ou EXADB		*/
/*	--------------------------------------		*/

#define	MSGERREUR	13

			/* ----- */
#ifdef	DEBUGGER	/* EXADB */
			/* ----- */

#ifdef	ABAL14

#define	FIRST_MSG_14	109
#define LAST_MSG_14	116

#define	MSGQTY	((MSGERREUR + 106) + 2)
#else
#define	MSGQTY	((MSGERREUR + 96) + 2)
#endif

#define MSGMAXLEN 80
EXBPTR	TalkPtr[MSGQTY];
EXABYTE	TalkBuf[MSGQTY][MSGMAXLEN] = {
	MSG_ID_EXADB,
	"on",
	"Moniteur ABAL",

			/* --- */
#else			/* EXA */
			/* --- */

#ifdef	ABALX11
#define	MSGQTY	((MSGERREUR + 1) + 3)
#else
#define	MSGQTY	((MSGERREUR + 1) + 2)
#endif
#define MSGMAXLEN 40
EXBPTR	TalkPtr[MSGQTY];
EXABYTE	TalkBuf[MSGQTY][MSGMAXLEN] = {
	MSG_ID_EXA,
	"on",
	"Executeur ABAL",
#endif

/*	Messages de reportage des erreurs par eder()	*/
/*	--------------------------------------------	*/
/*	pour EXA et EXADB				*/
/*							*/
	"Erreur",
	"d'E/S", 	 
	"systeme",	 
	"de commande", 
	"fichier",	 
	"systeme",	 
	"fichier",	 
	"graphique", 
	"systeme",	 
	"a l'adresse", 
	"Erreur fatale : Signal systeme numero",

			/* --- */
#ifndef	DEBUGGER	/* EXA */
			/* --- */

	"Environnement version ",
#ifdef	ABALX11
	"Validez",
#endif

			/* ----- */
#else			/* EXADB */
			/* ----- */

/*	Message du Menu Ctrl H  de EXADB seulement	*/
/*	------------------------------------------	*/

	"Ctrl A : Poser un point d'arret permanent",
	"Ctrl B : Poser un point d'arret temporaire",
	"Ctrl C : Deplacer la page vers le bas",
	"Ctrl D : Diminuer la taille de la fenetre",
	"Ctrl E : Deplacer la ligne vers le bas",
	"Ctrl F : Rechercher une chaine (avec joker)",
	"Ctrl G : Agrandir la taille de la fenetre",
	"Ctrl H : Afficher cet ecran",
	"Ctrl I : Redefinir les tabulations",
	"Ctrl J : Basculer la ligne d'aide",
	"Ctrl K : Deplacer la ligne vers le haut",
	"Ctrl L : Definir un marqueur de position",
	"Ctrl M : Revenir a la page d'execution",
	"Ctrl P : Se positionner sur un marqueur",
	"Ctrl R : Deplacer la page vers le haut",
	"Ctrl V : Reafficher l'ecran courant",
	"Ctrl W : Basculer entre l'ecran programme et moniteur",
	"Ctrl X : Lancer l'execution",
	"Ctrl Y : Supprimer un marqueur",
	"Ctrl Z : Zoomer la ligne courante",

/*	Messages du Menu 'H'	EXADB seulement		*/
/*	---------------------------------------		*/
	"AP [PROCID:] [ADRESSE]       : Poser un piege permanent sur une procedure",
	"AS [SEGMID:] [ADRESSE]       : Poser un piege permanent sur un segment",
	"AL OU BL                     : Lister les pieges",
	"AI<NUMERO> OU BI<NUMERO>     : Ignorer un piege",
	"BP [PROCID:] [ADRESSE]       : Poser un piege temporaire sur une procedure",
	"BS [SEGMID:] [ADRESSE]       : Poser un piege temporaire sur un segment",
	"C                            : Continuer l'execution",
	"D[H]<VARIABLE>[(DIM1[,DIM2])]: Afficher une variable en hexa",
	"E                            : Sortir du moniteur ABAL",
	"H                            : Afficher cet ecran",
	"K</XX> , K<NNN> , K<'C'>     : Definir la touche d'interruption",
	"M<VARIABLE>[(DIM1[,DIM2])]   : Modifier une variable",
	"OA<VARIABLE>[(DIM1[,DIM2])]  : Ajouter une variable en observation",
	"OI<VARIABLE>                 : Ignorer l'observation d'une variable",
	"OL                           : Lister les variables en observation",
	"Z                            : Afficher la trace des GOSUB",
	"!<CMD,PARAM>                 : Appeler un utilitaire systeme",

	"   ",

/*	Messages divers des fonctions EXADB		*/
/*	-----------------------------------		*/
	"Liste des points d'arret",
	"Piege",
	"permanent",  
#ifdef	ABAL14
	"Empillage",
#else
	"Pile GOSUB",
#endif
	"Modifie",
	"**FIN**", 
	"Touche d'IT",
	"Voulez-vous sortir du moniteur ABAL",
	"Variable inconnue",
	"Fin normale d'execution",
	"Erreur d'acces au fichier liste",

/*	Messages en mode Verbose	*/
/*	------------------------	*/
#ifdef	ABAL14
	"Adresse de piege incorrecte",
#else
	"La table des pieges est pleine",
#endif
	"Procedure inconnue",
	"Environnement version ",
	"Liste des pieges sur variables ",
	"Arret sur la modification d'une variable ",
	" ",
	" ",
	"Ajout realise",
	"Suppression realisee",
	"Interdit en mode consultation",
	"Procedure / Segment non trouve",
	"Adresse non trouvee",
	"Marqueur a chercher",
	"Longueur des tabulations",
	"Marqueur a supprimer",
	"Marqueur a definir",
	"Fenetre agrandie",
	"Fenetre diminuee",
	"Chaine a chercher",
	"Chaine non trouvee",
	"Appuyer sur une touche pour continuer",
	"ESC pour arreter",
	"Debordement de memoire",
	"Marqueur inexistant",
	"Marqueur supprime",
	"Marqueur ajoute",
	"Marqueur modifie",
	"Debordement de la table des marqueurs",

/*	Extended 1.2a Messages 		*/
/*	----------------------		*/
	"Modifier parametres",
	"Sauver   parametres",
	"parametres",
	"Modification des parametres du Moniteur ABAL",
	"Menu Parametres",
	"Fenetre Pile des Gosubs",
	"Fenetre Liste des Marqueurs",
	"Fenetre Zoom sur Ligne Source",
	"Fenetre d'observation Variables",
	"Fenetre de commande",
	"Fenetre liste Observation",
	"Fenetre Modification Variables",
	"Fenetre Liste des pieges",
	"Fenetre Affichage Hexa",
	"Fenetres d'aide", 
	"Fenetre de Saisie parametres",
	"Fenetre d'erreurs",
	"Fenetre de Sortie",
	"Fenetre de Liste Source",

#ifdef	ABAL14
	"  ",
	"BV <VARIABLE>                : Poser un piege temporaire sur une variable",
	"AV <VARIABLE>                : Poser un piege permanent  sur une variable",
	"F <NUMERO D'ASSIGN>          : Afficher des informations d'un ASSIGN ",
	"G [ NOM DU PROG ] [ , ARG]   : Relancer EXADB ",
	"VI<VARIABLE>                 : Ignorer la piege sur la variable ",
	"VL[VARIABLE]                 : Lister les pieges sur variables ",
	"  ",
	"Saisie limite a 256 caracteres",
#endif

#endif

	"*ETX*"

	};


void	TalkWork()
{
	UBINAIR	x,y;
	EXBPTR	wptr;
	wptr = (EXBPTR) TalkBuf;
	x = 0;
	do	{
		while ( *wptr != (EXABYTE) 0 ) { wptr++; }
		while ( *wptr == (EXABYTE) 0 ) { wptr++; }
		TalkPtr[x++] = (EXBPTR) wptr;
		}
	while ( x < MSGQTY );
	return;
}


