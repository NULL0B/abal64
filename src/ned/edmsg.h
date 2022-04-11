#ifndef	_edmsg_h
#define	_edmsg_h

/*---------------------------------------------------------------EDMSG.H -----
 *
 *	Editeur de textes ABAL	  -	Copyright Amenesik / Sologic s.a. (c) 1989
 *
 *		   	Messages de l'editeur
 *
 *		      Revision 1.0 du 20/04/1989
 *
 *--------------------------------------------------------------------------*/

/*	Entete pour utilitaire de traduction	*/
/*	------------------------------------	*/
#define verscfg		"ABALCFG-STX-2"		/* version de config */

#ifdef ver2K
#ifdef verGraphic
#define Mentete "*STX*3AED Fr  24a00"
#define Oentete "*STX*3AED En  24a01"
#else
#define Mentete "*STX*3AED Fr  22a00"
#define Oentete "*STX*3AED En  22a01"
#endif
#else
#ifdef ver21
#define Mentete "*STX*3AED Fr  21c00"
#define Oentete "*STX*3AED En  21c01"
#else
#ifdef ver14
#define Mentete "*STX*3  AED   14c00"
#else

#ifdef ver13
#define Mentete "*STX*3  AED   13e00"
#else

#ifdef ver12
#define Mentete "*STX*3  AED   12g00"
#else
#define Mentete "*STX*3  AED   11g00"
#endif

#endif

#endif

#endif

#endif

#define Ouinon "ON0"
#define Yesno  "YN0"

/*	messages generaux		*/
/*	-----------------		*/

#define M00001 "Editeur de textes ABAL++"
#define M00002 "** Erreur "
#define M00003 "  Abandon de l'edition"
#define M00004 "fichier : "
#define M00005 " INSERER "
#define M00006 " INDENTER "
#define M00007 "abandon (o/n) : "
#define M00008 "ligne : "
#define M00009 "colonne : "
#define M00010 "Commande incorrecte "
#define M01001 "Fichier source inaccessible"
#define M01002 "Acces fichier resultat impossible"
#define M01003 "Debordement capacite memoire"
#define M01004 "Fichier d'erreurs inaccessible"
#define M01005 "Acces fichier d'erreurs impossible"
#define M01006 "Fin du fichier des erreurs"
#define M01007 "Fichier deja existant"
#define M01008 "Ecriture interdite"
#define M01009 "Fichier non trouve"
#define M01010 "Lecture interdite"
#define M01011 "Fichier vide"
#define M01012 "Tampon est vide"
#define M01013 "Chaine non trouvee"
#define M01014 "Changement de fichier source"
#define M01015 "Sauvegarde de l'etat courant (o/n) ? "
#ifdef	ver2K
#define M01016 "Ligne trop longue ( > 2048 caracteres )"
#else
#define M01016 "Ligne trop longue ( > 320 caracteres )"
#endif
#define M01017 "ESCAPE = fin : CR = ../.."
#define M01018 "Utilisation des sous-repertoires interdite"
#define M05001 "Fichier non partageable"
#define M02000 "CORBEILLE"
#define M02001 "cbp"
#define M00011 "Environnement"
#define M06000 "Chemin d'acces   : "
#define M06001 "Nom du fichier   : "
#define M06002 "Appuyer sur une touche pour continuer ..."
#define M07000 "eeca"
#define M08000 "Une erreur est intervenue lors de la sauvegarde."
#define M08001 "Le nouveau fichier a ete sauvegarde sous le nom : "
#define M08002 "fichier de configuration incorrect"
#define M03001 "        Les caracteres de contr“le"
#define M03002 "Ctrl-D  Fleche a droite"
#define M03003 "Ctrl-B  Debut/Fin de ligne"
#define M03004 "Ctrl-Q  Fleche a gauche"
#define M03005 "Ctrl-P  Debut/Fin d'ecran"
#define M03006 "Ctrl-E  Fleche en haut"
#define M03007 "Ctrl-X  Fleche en bas"
#define M03008 "Ctrl-M  Retour Chariot"
#define M03009 "Ctrl-F  Avance par mot"
#define M03010 "Ctrl-A  Recule par mot"
#define M03011 "Ctrl-I  Tabulation"
#define M03012 "Ctrl-C  Ecran suivant"
#define M03013 "Ctrl-R  Ecran precedent"
#define M03014 "Ctrl-L  Centre la ligne courante"
#define M03015 "Ctrl-Y  Supprime la ligne courante"
#define M03016 "Ctrl-U  Supprime le debut de ligne"
#define M03017 "Ctrl-K  Supprime la fin de ligne"
#define M03018 "Ctrl-G  Supprime le caractere suivant"
#define M03019 "Ctrl-H  Supprime le caractere precedent"
#define M03020 "Ctrl-Z  Annule la derniere suppression"
#define M03021 "Ctrl-N  Insertion d'une ligne"
#define M03022 "Ctrl-O  Mode insertion"
#define M03023 "Ctrl-V  Mode indentation"
#define M03024 "Ctrl-J  Affichage ligne, colonne"
#define M03025 "Ctrl-W  Mode corbeille"
#define M03026 "     Mode corbeille"
#define M03027 "A - Debut de la selection"
#define M03028 "B - Fin de la selection"
#define M03029 "C - Copie de la selection en memoire"
#define M03030 "D - Suppression de la selection"
#define M03031 "I - Insere la corbeille entre deux caracteres"
#define B03031 "X - Insere la corbeille ligne par ligne      "
#define M03032 "M - Deplace le contenu de la selection"
#define B03032 "L - Deplace avec insertion ligne par ligne"
#define M03033 "Q - Sortie du mode corbeille"
#define M03034 "R - Annule la selection courante"
#define M03035 "T - Annule la corbeille"
#define M03036 "P - Active/desactive le mode colonne"
#define M03037 "K - Active/desactive le mode bloc"
#define M04001 "     Mode commande"
#define M14001 "Fleche basse    Rappel de la derniere commande"
#define M24001 "Fleche haute    Rappel de la plus ancienne commande"
#define M34001 "INSERT          Ligne de commande en mode insertion"
#define M43001 "CTRL+RC		Prend en compte toute la ligne de commande"
#define M53001 "CTRL-P/CTRL-n   Saisie d'un caractere de contr“le"
#define M04002 "E		Fin normale avec sauvegarde"
#define M04003 "Q		Abandon de l'edition"
#define M04004 "C[!]nomfic   	ecrit la corbeille dans un fichier"
#define M04005 "[n]W[!]nomfic 	ecrit n lignes dans un fichier"
#define M04006 "Ynomfic		Insertion d'un fichier"
#define M04007 "O		Reprise du fichier initial"
#define M14007 "O-nomfic        Abandon du fichier courant puis edition de nomfic"
#define M24007 "                Le contenu de la corbeille reste en memoire"
#define M04008 "H		Sauvegarde en cours de session"
#define M04009 "B		Positionnement au debut du fichier"
#define M04010 "-B		Positionnement en fin de fichier"
#define M04011 "nL		Positionnement a la nieme ligne"
#define M04012 "[+/-]nL		Positionnement +/- n lignes avant la ligne courante"
#define M04013 "[n]QP[$]	Mettre les n lignes dans la memoire de travail"
#define M04014 "[n]QA[$]	Ajoute n lignes dans la memoire de travail"
#define M04015 "[n]QG		Insere le contenu de la memoire de travail"
#define M04016 "Ctrl-A		Symbolise le debut ou la fin de ligne"
#define M04017 "[n][*][!]Nstr	Recherche la nieme occurrence d'une chaine"
#define M14017 "                [*] presence d'un joker (*,?) dans la selection"
#define M24017 "                [!] recherche la selection en majuscule ou en minuscule"
#define M04018 "[n*!]Rs1<ESC>s2	Remplace la nieme occurrence de s1 par s2"
#define M04019 "[n]K 		Supprime n lignes"
#define M04020 "V    		Retour au mode saisie"
#define M04021 "X    		Retour position courante"
#define M04022 "?		Active le memento"
#define M04023 "??		Supprime le memento"
#define M04024 "ESC		Passe du memento a la ligne de commande"
#define M04025 "                la sequence ESC / v permet de travailler avec le memento"
#define M04026 ">n		Saisie d'un caractere en hexadecimal (2 chiffres)"
#define M04027 "F		Affiche l'endroit d'o— a ete lance AED"
#define M04028 "		Puis affiche le chemin du fichier edite"
#define Metx   " "

/*	Padding pour la traduction des messages */
/*	--------------------------------------- */

#define Mfil10  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil11  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil12  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil13  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil14  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil15  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil16  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil17  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil18  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil19  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil20  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil21  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil22  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil23  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil24  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil25  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil26  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil27  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil28  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil29  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil30  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil31  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil32  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil33  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil34  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil35  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil36  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil37  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil38  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil39  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil40  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil41  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil42  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil43  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil44  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil45  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil46  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil47  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil48  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil49  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/

#define Mfin "*ETX*"

/* Les Anglais */

#define O00001 "ABAL++ text editor"
#define O00002 "** Error "
#define O00003 "  Abandon editing"
#define O00004 "file : "
#define O00005 " INSERT "
#define O00006 " INDENT "
#define O00007 "abandon (y/n) : "
#define O00008 "line : "
#define O00009 "column : "
#define O00010 "Incorrect command"
#define O01001 "Source file not accessible"
#define O01002 "Impossible to access result file"
#define O01003 "Memory overflow"
#define O01004 "Error file inaccessible"
#define O01005 "Access to error file impossible"
#define O01006 "End of error file"
#define O01007 "File already exists"
#define O01008 "Write prohibited"
#define O01009 "File not found"
#define O01010 "Read prohibited"
#define O01011 "File empty"
#define O01012 "Buffer is empty"
#define O01013 "String not found"
#define O01014 "Change of source file"
#define O01015 "Save in current state (y/n) ? "
#ifdef	ver2K
#define O01016 "Line too long ( > 2048 characters )"
#else
#define O01016 "Line too long ( > 320 characters )"
#endif
#define O01017 "ESCAPE = end : CR = ../.."
#define O01018 "Subdirectory access forbiden"
#define O05001 "File not sharable"
#define O02000 "BASKET"
#define O02001 "cbp"
#define O00011 "Environment"
#define O06000 "Access path   : "
#define O06001 "File name     : "
#define O06002 "Strike a key to continue ..."
#define O07000 "eeca"
#define O08000 "An error has occured during saving."
#define O08001 "The new file has been saved under the name : "
#define O08002 "Incorrect configuration file"
#define O03001 "        Control characters"
#define O03002 "Ctrl-D  Right arrow"
#define O03003 "Ctrl-B  Start/end of line"
#define O03004 "Ctrl-Q  Left arrow"
#define O03005 "Ctrl-P  Start/end of screen"
#define O03006 "Ctrl-E  Up arrow"
#define O03007 "Ctrl-X  Down arrow"
#define O03008 "Ctrl-M  Carriage return"
#define O03009 "Ctrl-F  Next word"
#define O03010 "Ctrl-A  Previous word"
#define O03011 "Ctrl-I  Tabulation"
#define O03012 "Ctrl-C  Next screen"
#define O03013 "Ctrl-R  Preceding screen"
#define O03014 "Ctrl-L  Center current line"
#define O03015 "Ctrl-Y  Delete current line"
#define O03016 "Ctrl-U  Delete start of the line"
#define O03017 "Ctrl-K  Delete end of the line"
#define O03018 "Ctrl-G  Delete next character"
#define O03019 "Ctrl-H  Delete preceding character"
#define O03020 "Ctrl-Z  Cancel last deletion"
#define O03021 "Ctrl-N  Insert a line"
#define O03022 "Ctrl-O  Insertion mode"
#define O03023 "Ctrl-V  Indentation mode"
#define O03024 "Ctrl-J  Display line, column"
#define O03025 "Ctrl-W  Basket mode"
#define O03026 "     Basket mode"
#define O03027 "A - Start of selection"
#define O03028 "B - End of selection"
#define O03029 "C - Copy selection to memory"
#define O03030 "D - Delete selection"
#define O03031 "I - Insert basket between two characters"
#define C03031 "X - Insert the basket line by line      "
#define O03032 "M - Move contents of selection"
#define C03032 "L - Moves basket with line by line insertion"
#define O03033 "Q - Exit basket mode"
#define O03034 "R - Cancel current selection"
#define O03035 "T - Cancel basket"
#define O03036 "P - Activate/de-activate column mode"
#define O03037 "K - Activate/de-activate block mode"
#define O04001 "     Command mode"
#define O14001 "Down arrow     Retrieve last command"
#define O24001 "Up arrow       Retrieve oldest command"
#define O34001 "INSERT         Command line in insert mode"
#define O43001 "CTRL+RC        Consider the whole command line"
#define O53001 "CTRL-P/CTRL-n  Enter a control character"
#define O04002 "E              Regular end with backup"
#define O04003 "Q              Abandon printout"
#define O04004 "C[!]nomfic     write the basket in a file"
#define O04005 "[n]W[!]nomfic  write n lines in a file"
#define O04006 "Ynomfic        Insertion of a file"
#define O04007 "O              recover initial file"
#define O14007 "O-filman       Abort current file then edit filnam"
#define O24007 "               Basket contents remains in memory"
#define O04008 "H              Save during session"
#define O04009 "B              Positioning at file beginning"
#define O04010 "-B             Positioning at file end"
#define O04011 "nL             Positioning at nth line"
#define O04012 "[+/-]nl        Positioning +/- n lines before current line"
#define O04013 "[n]QP[$]       Store n lines in work memory"
#define O04014 "[n]QA[$]       Add up n lines in work memory"
#define O04015 "[n]QG          Insert contents of working memory"
#define O04016 "Ctrl-A         Symbol for beginning or end of line"
#define O04017 "[n][*][!]Nstr  Search for nth occurence of a string"
#define O14017 "                [*] wildcard substitution character (*,?) in the selection"
#define O24017 "                [!] search for selection in upper case or lower case"
#define O04018 "[n]Rs1<ESC>s2  Replace the nth occurrence of s1 by s2"
#define O04019 "[n]K           Delete n lines"
#define O04020 "V              Return to entry mode"
#define O04021 "X              Return to current position"
#define O04022 "?              Activate memento"
#define O04023 "??             Clear memento"
#define O04024 "ESC            Move from the memento to the command line"
#define O04025 "               the ESC/v sequence lets you work with the memento"
#define O04026 ">n             Enter a character in hexadecimal (2 digits)"
#define O04027 "F              First displays the directory from which AED has been initiated"
#define O04028 "		then the pathname of the edited file"
                                                                                
#ifdef HX                                                                       
                                                                                
/* Francais */

#define LGMEMAX 80			/* longueur du plus grand message */

static BYTE mentete[][LGMEMAX] = { 
Mentete,
Ouinon,
M00001,
M00002, 
M00003, 
M00004, 
M00005, 
M00006, 
M00007, 
M00008, 
M00009, 
M00010, 
M01001, 
M01002, 
M01003, 
M01004, 
M01005, 
M01006, 
M01007, 
M01008, 
M01009, 
M01010, 
M01011, 
M01012, 
M01013, 
M01014, 
M01015, 
M01016, 
M01017, 
M01018, 
M05001, 
M02000, 
M02001, 
M00011, 
M06000, 
M06001, 
M06002, 
M07000, 
M08000, 
M08001, 
M08002, 
M03001, 
M03002, 
M03003, 
M03004, 
M03005, 
M03006, 
M03007, 
M03008, 
M03009, 
M03010, 
M03011, 
M03012, 
M03013, 
M03014, 
M03015, 
M03016, 
M03017, 
M03018, 
M03019, 
M03020, 
M03021, 
M03022, 
M03023, 
M03024, 
M03025, 
M03026, 
M03027, 
M03028, 
M03029, 
M03030, 
M03031, 
B03031, 
M03032, 
B03032, 
M03033, 
M03034, 
M03035, 
M03036, 
M03037, 
M04001, 
M14001, 
M24001, 
M34001, 
M43001, 
M53001, 
M04002, 
M04003, 
M04004, 
M04005, 
M04006, 
M04007, 
M14007, 
M24007, 
M04008, 
M04009, 
M04010, 
M04011, 
M04012, 
M04013, 
M04014, 
M04015, 
M04016, 
M04017, 
M14017, 
M24017, 
M04018, 
M04019, 
M04020, 
M04021, 
M04022, 
M04023, 
M04024, 
M04025, 
M04026, 
M04027, 
M04028, 
Metx,

Mfil10,
Mfil11,
Mfil12,
Mfil13,
Mfil14,
Mfil15,
Mfil16,
Mfil17,
Mfil18,
Mfil19,
Mfil20,
Mfil21,
Mfil22,
Mfil23,
Mfil24,
Mfil25,
Mfil26,
Mfil27,
Mfil28,
Mfil29,
Mfil30,
Mfil31,
Mfil32,
Mfil33,
Mfil34,
Mfil35,
Mfil36,
Mfil37,
Mfil38,
Mfil39,
Mfil40,
Mfil41,
Mfil42,
Mfil43,
Mfil44,
Mfil45,
Mfil46,
Mfil47,
Mfil48,
Mfil49,
Mfin,
};

/* Les Angalis */
static BYTE oentete[][LGMEMAX] = { 
Oentete,
Yesno,
O00001,
O00002, 
O00003, 
O00004, 
O00005, 
O00006, 
O00007, 
O00008, 
O00009, 
O00010, 
O01001, 
O01002, 
O01003, 
O01004, 
O01005, 
O01006, 
O01007, 
O01008, 
O01009, 
O01010, 
O01011, 
O01012, 
O01013, 
O01014, 
O01015, 
O01016, 
O01017, 
O01018, 
O05001, 
O02000, 
O02001, 
O00011, 
O06000, 
O06001, 
O06002, 
O07000, 
O08000, 
O08001, 
O08002, 
O03001, 
O03002, 
O03003, 
O03004, 
O03005, 
O03006, 
O03007, 
O03008, 
O03009, 
O03010, 
O03011, 
O03012, 
O03013, 
O03014, 
O03015, 
O03016, 
O03017, 
O03018, 
O03019, 
O03020, 
O03021, 
O03022, 
O03023, 
O03024, 
O03025, 
O03026, 
O03027, 
O03028, 
O03029, 
O03030, 
O03031, 
C03031, 
O03032, 
C03032, 
O03033, 
O03034, 
O03035, 
O03036, 
O03037, 
O04001, 
O14001, 
O24001, 
O34001, 
O43001, 
O53001, 
O04002, 
O04003, 
O04004, 
O04005, 
O04006, 
O04007, 
O14007, 
O24007, 
O04008, 
O04009, 
O04010, 
O04011, 
O04012, 
O04013, 
O04014, 
O04015, 
O04016, 
O04017, 
O14017, 
O24017, 
O04018, 
O04019, 
O04020, 
O04021, 
O04022, 
O04023, 
O04024, 
O04025, 
O04026, 
O04027, 
O04028, 
Metx,

Mfil10,
Mfil11,
Mfil12,
Mfil13,
Mfil14,
Mfil15,
Mfil16,
Mfil17,
Mfil18,
Mfil19,
Mfil20,
Mfil21,
Mfil22,
Mfil23,
Mfil24,
Mfil25,
Mfil26,
Mfil27,
Mfil28,
Mfil29,
Mfil30,
Mfil31,
Mfil32,
Mfil33,
Mfil34,
Mfil35,
Mfil36,
Mfil37,
Mfil38,
Mfil39,
Mfil40,
Mfil41,
Mfil42,
Mfil43,
Mfil44,
Mfil45,
Mfil46,
Mfil47,
Mfil48,
Mfil49,
Mfin,
};





#else /* HX */                                                                  
                                                                                
/* Francais */                                                                  
static BYTE mentete[] = Mentete;                                                
static BYTE ouinon[] = Ouinon;                                                  
                                                                                
/*	messages generaux		*/
/*	-----------------		*/

static BYTE m00001[] = M00001;
static BYTE m00002[] = M00002;
static BYTE m00003[] = M00003;
static BYTE m00004[] = M00004;
static BYTE m00005[] = M00005;
static BYTE m00006[] = M00006;
static BYTE m00007[] = M00007;
static BYTE m00008[] = M00008;
static BYTE m00009[] = M00009;
static BYTE m00010[] = M00010;

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

static BYTE m01001[] = M01001;
static BYTE m01002[] = M01002;
static BYTE m01003[] = M01003;
static BYTE m01004[] = M01004;
static BYTE m01005[] = M01005;
static BYTE m01006[] = M01006;
static BYTE m01007[] = M01007;
static BYTE m01008[] = M01008;
static BYTE m01009[] = M01009;
static BYTE m01010[] = M01010;
static BYTE m01011[] = M01011;
static BYTE m01012[] = M01012;
static BYTE m01013[] = M01013;
static BYTE m01014[] = M01014;
static BYTE m01015[] = M01015;
static BYTE m01016[] = M01016;
static BYTE m01017[] = M01017;
                      
static BYTE m01018[] = M01018;
static BYTE m05001[] = M05001;

#ifndef integre
/* 	Messages pour la corbeille		*/
/*	--------------------------		*/
static BYTE m02000[] = M02000;
static BYTE m02001[] = M02001;
static BYTE m00011[] = M00011;
#endif /* integre */

#ifdef ver14
static BYTE m06000[] = M06000;
static BYTE m06001[] = M06001;
static BYTE m06002[] = M06002;
static BYTE m07000[] = M07000;
static BYTE m08000[] = M08000;
static BYTE m08001[] = M08001;
static BYTE m08002[] = M08002;
#endif /* ver14 */

#ifdef ver14
/*	Messages pour le memento Ctrl		*/
/*	-----------------------------		*/
static BYTE m03001[] = M03001;
static BYTE m03002[] = M03002;
static BYTE m03003[] = M03003;
static BYTE m03004[] = M03004;
static BYTE m03005[] = M03005;
static BYTE m03006[] = M03006;
static BYTE m03007[] = M03007;
static BYTE m03008[] = M03008;
static BYTE m03009[] = M03009;
static BYTE m03010[] = M03010;
static BYTE m03011[] = M03011;
static BYTE m03012[] = M03012;
static BYTE m03013[] = M03013;
static BYTE m03014[] = M03014;
static BYTE m03015[] = M03015;
static BYTE m03016[] = M03016;
static BYTE m03017[] = M03017;
static BYTE m03018[] = M03018;
static BYTE m03019[] = M03019;
static BYTE m03020[] = M03020;
static BYTE m03021[] = M03021;
static BYTE m03022[] = M03022;
static BYTE m03023[] = M03023;
static BYTE m03024[] = M03024;
static BYTE m03025[] = M03025;
static BYTE m03026[] = M03026;
static BYTE m03027[] = M03027;
static BYTE m03028[] = M03028;
static BYTE m03029[] = M03029;
static BYTE m03030[] = M03030;
static BYTE m03031[] = M03031;
static BYTE b03031[] = B03031;
static BYTE m03032[] = M03032;
static BYTE b03032[] = B03032;
static BYTE m03033[] = M03033;
static BYTE m03034[] = M03034;
static BYTE m03035[] = M03035;
static BYTE m03036[] = M03036;
static BYTE m03037[] = M03037;

/*	Messages pour le memento Commandes	*/
/*	----------------------------------	*/
static BYTE m04001[] = M04001;
static BYTE m14001[] = M14001;
static BYTE m24001[] = M24001;
static BYTE m34001[] = M34001;
static BYTE m43001[] = M43001;
static BYTE m53001[] = M53001;
static BYTE m04002[] = M04002;
static BYTE m04003[] = M04003;
static BYTE m04004[] = M04004;
static BYTE m04005[] = M04005;
static BYTE m04006[] = M04006;
static BYTE m04007[] = M04007;
static BYTE m14007[] = M14007;
static BYTE m24007[] = M24007;
static BYTE m04008[] = M04008;
static BYTE m04009[] = M04009;
static BYTE m04010[] = M04010;
static BYTE m04011[] = M04011;
static BYTE m04012[] = M04012;
static BYTE m04013[] = M04013;
static BYTE m04014[] = M04014;
static BYTE m04015[] = M04015;
static BYTE m04016[] = M04016;
static BYTE m04017[] = M04017;
static BYTE m14017[] = M14017;
static BYTE m24017[] = M24017;
static BYTE m04018[] = M04018;
static BYTE m04019[] = M04019;
static BYTE m04020[] = M04020;
static BYTE m04021[] = M04021;
static BYTE m04022[] = M04022;
static BYTE m04023[] = M04023;
static BYTE m04024[] = M04024;
static BYTE m04025[] = M04025;
static BYTE m04026[] = M04026;
static BYTE m04027[] = M04027;
static BYTE m04028[] = M04028;
static BYTE metx[] = Metx;

#else /* ver14 */

/*	Messages pour le memento Ctrl		*/
/*	-----------------------------		*/
static BYTE m03001[] = M03001;
static BYTE m03002[] = M03002;
static BYTE m03003[] = M03003;
static BYTE m03004[] = M03004;
static BYTE m03005[] = M03005;
static BYTE m03006[] = M03006;
static BYTE m03007[] = M03007;
static BYTE m03008[] = M03008;
static BYTE m03009[] = M03009;
static BYTE m03010[] = M03010;
static BYTE m03011[] = M03011;
static BYTE m03012[] = M03012;
static BYTE m03013[] = M03013;
static BYTE m03014[] = M03014;
static BYTE m03015[] = M03015;
static BYTE m03016[] = M03016;
static BYTE m03017[] = M03017;
static BYTE m03018[] = M03018;
static BYTE m03019[] = M03019;
static BYTE m03020[] = M03020;
static BYTE m03021[] = M03021;
static BYTE m03022[] = M03022;
static BYTE m03023[] = M03023;
static BYTE m03024[] = M03024;

#ifndef integre
static BYTE m03025[] = M03025;
static BYTE m03026[] = M03026;
static BYTE m03027[] = M03027;
static BYTE m03028[] = M03028;
static BYTE m03029[] = M03029;
static BYTE m03030[] = M03030;
static BYTE m03031[] = M03031;
static BYTE m03032[] = M03032;
static BYTE m03033[] = M03033;
static BYTE m03034[] = M03034;
static BYTE m03035[] = M03035;
#endif /* integre */

/*	Messages pour le memento Commandes	*/
/*	----------------------------------	*/
static BYTE m04001[] = M04001;
static BYTE m04002[] = M04002;
static BYTE m04003[] = M04003;
static BYTE m04004[] = M04004;
static BYTE m04005[] = M04005;
static BYTE m04006[] = M04006;
static BYTE m04007[] = M04007;
static BYTE m04008[] = M04008;
static BYTE m04009[] = M04009;
static BYTE m04010[] = M04010;
static BYTE m04011[] = M04011;
static BYTE m04012[] = M04012;
static BYTE m04013[] = M04013;
static BYTE m04014[] = M04014;
static BYTE m04015[] = M04015;
static BYTE m04016[] = M04016;
static BYTE m04017[] = M04017;
static BYTE m04018[] = M04018;
static BYTE m04019[] = M04019;
static BYTE m04020[] = M04020;
static BYTE m04021[] = M04021;
static BYTE m04022[] = M04022;
static BYTE metx[] = Metx;
#endif /* ver14 */

/*	Padding pour la traduction des messages */
/*	--------------------------------------- */
static BYTE mfil10[] = Mfil10;
static BYTE mfil11[] = Mfil11;
static BYTE mfil12[] = Mfil12;
static BYTE mfil13[] = Mfil13;
static BYTE mfil14[] = Mfil14;
static BYTE mfil15[] = Mfil15;
static BYTE mfil16[] = Mfil16;
static BYTE mfil17[] = Mfil17;
static BYTE mfil18[] = Mfil18;
static BYTE mfil19[] = Mfil19;
static BYTE mfil20[] = Mfil20;
static BYTE mfil21[] = Mfil21;
static BYTE mfil22[] = Mfil22;
static BYTE mfil23[] = Mfil23;
static BYTE mfil24[] = Mfil24;
static BYTE mfil25[] = Mfil25;
static BYTE mfil26[] = Mfil26;
static BYTE mfil27[] = Mfil27;
static BYTE mfil28[] = Mfil28;
static BYTE mfil29[] = Mfil29;
static BYTE mfil30[] = Mfil30;
static BYTE mfil31[] = Mfil31;
static BYTE mfil32[] = Mfil32;
static BYTE mfil33[] = Mfil33;
static BYTE mfil34[] = Mfil34;
static BYTE mfil35[] = Mfil35;
static BYTE mfil36[] = Mfil36;
static BYTE mfil37[] = Mfil37;
static BYTE mfil38[] = Mfil38;
static BYTE mfil39[] = Mfil39;
static BYTE mfil40[] = Mfil40;
static BYTE mfil41[] = Mfil41;
static BYTE mfil42[] = Mfil42;
static BYTE mfil43[] = Mfil43;
static BYTE mfil44[] = Mfil44;
static BYTE mfil45[] = Mfil45;
static BYTE mfil46[] = Mfil46;
static BYTE mfil47[] = Mfil47;
static BYTE mfil48[] = Mfil48;
static BYTE mfil49[] = Mfil49;

/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/

static BYTE mfin[] =Mfin;


/* Anglais */
static BYTE oentete[] = Oentete;
static BYTE yesno[] = Yesno;

/*	messages generaux		*/
/*	-----------------		*/

static BYTE o00001[] = O00001;
static BYTE o00002[] = O00002;
static BYTE o00003[] = O00003;
static BYTE o00004[] = O00004;
static BYTE o00005[] = O00005;
static BYTE o00006[] = O00006;
static BYTE o00007[] = O00007;
static BYTE o00008[] = O00008;
static BYTE o00009[] = O00009;
static BYTE o00010[] = O00010;

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

static BYTE o01001[] = O01001;
static BYTE o01002[] = O01002;
static BYTE o01003[] = O01003;
static BYTE o01004[] = O01004;
static BYTE o01005[] = O01005;
static BYTE o01006[] = O01006;
static BYTE o01007[] = O01007;
static BYTE o01008[] = O01008;
static BYTE o01009[] = O01009;
static BYTE o01010[] = O01010;
static BYTE o01011[] = O01011;
static BYTE o01012[] = O01012;
static BYTE o01013[] = O01013;
static BYTE o01014[] = O01014;
static BYTE o01015[] = O01015;
static BYTE o01016[] = O01016;
static BYTE o01017[] = O01017;
                      
static BYTE o01018[] = O01018;
static BYTE o05001[] = O05001;

#ifndef integre
/* 	Messages pour la corbeille		*/
/*	--------------------------		*/
static BYTE o02000[] = O02000;
static BYTE o02001[] = O02001;
static BYTE o00011[] = O00011;
#endif /* integre */

#ifdef ver14
static BYTE o06000[] = O06000;
static BYTE o06001[] = O06001;
static BYTE o06002[] = O06002;
static BYTE o07000[] = O07000;
static BYTE o08000[] = O08000;
static BYTE o08001[] = O08001;
static BYTE o08002[] = O08002;
#endif /* ver14 */

#ifdef ver14
/*	Messages pour le memento Ctrl		*/
/*	-----------------------------		*/
static BYTE o03001[] = O03001;
static BYTE o03002[] = O03002;
static BYTE o03003[] = O03003;
static BYTE o03004[] = O03004;
static BYTE o03005[] = O03005;
static BYTE o03006[] = O03006;
static BYTE o03007[] = O03007;
static BYTE o03008[] = O03008;
static BYTE o03009[] = O03009;
static BYTE o03010[] = O03010;
static BYTE o03011[] = O03011;
static BYTE o03012[] = O03012;
static BYTE o03013[] = O03013;
static BYTE o03014[] = O03014;
static BYTE o03015[] = O03015;
static BYTE o03016[] = O03016;
static BYTE o03017[] = O03017;
static BYTE o03018[] = O03018;
static BYTE o03019[] = O03019;
static BYTE o03020[] = O03020;
static BYTE o03021[] = O03021;
static BYTE o03022[] = O03022;
static BYTE o03023[] = O03023;
static BYTE o03024[] = O03024;
static BYTE o03025[] = O03025;
static BYTE o03026[] = O03026;
static BYTE o03027[] = O03027;
static BYTE o03028[] = O03028;
static BYTE o03029[] = O03029;
static BYTE o03030[] = O03030;
static BYTE o03031[] = O03031;
static BYTE c03031[] = C03031;
static BYTE o03032[] = O03032;
static BYTE c03032[] = C03032;
static BYTE o03033[] = O03033;
static BYTE o03034[] = O03034;
static BYTE o03035[] = O03035;
static BYTE o03036[] = O03036;
static BYTE o03037[] = O03037;

/*	Messages pour le memento Commandes	*/
/*	----------------------------------	*/
static BYTE o04001[] = O04001;
static BYTE o14001[] = O14001;
static BYTE o24001[] = O24001;
static BYTE o34001[] = O34001;
static BYTE o43001[] = O43001;
static BYTE o53001[] = O53001;
static BYTE o04002[] = O04002;
static BYTE o04003[] = O04003;
static BYTE o04004[] = O04004;
static BYTE o04005[] = O04005;
static BYTE o04006[] = O04006;
static BYTE o04007[] = O04007;
static BYTE o14007[] = O14007;
static BYTE o24007[] = O24007;
static BYTE o04008[] = O04008;
static BYTE o04009[] = O04009;
static BYTE o04010[] = O04010;
static BYTE o04011[] = O04011;
static BYTE o04012[] = O04012;
static BYTE o04013[] = O04013;
static BYTE o04014[] = O04014;
static BYTE o04015[] = O04015;
static BYTE o04016[] = O04016;
static BYTE o04017[] = O04017;
static BYTE o14017[] = O14017;
static BYTE o24017[] = O24017;
static BYTE o04018[] = O04018;
static BYTE o04019[] = O04019;
static BYTE o04020[] = O04020;
static BYTE o04021[] = O04021;
static BYTE o04022[] = O04022;
static BYTE o04023[] = O04023;
static BYTE o04024[] = O04024;
static BYTE o04025[] = O04025;
static BYTE o04026[] = O04026;
static BYTE o04027[] = O04027;
static BYTE o04028[] = O04028;
static BYTE oetx[] = Metx;

#else /* ver14 */

/*	Messages pour le memento Ctrl		*/
/*	-----------------------------		*/
static BYTE o03001[] = O03001;
static BYTE o03002[] = O03002;
static BYTE o03003[] = O03003;
static BYTE o03004[] = O03004;
static BYTE o03005[] = O03005;
static BYTE o03006[] = O03006;
static BYTE o03007[] = O03007;
static BYTE o03008[] = O03008;
static BYTE o03009[] = O03009;
static BYTE o03010[] = O03010;
static BYTE o03011[] = O03011;
static BYTE o03012[] = O03012;
static BYTE o03013[] = O03013;
static BYTE o03014[] = O03014;
static BYTE o03015[] = O03015;
static BYTE o03016[] = O03016;
static BYTE o03017[] = O03017;
static BYTE o03018[] = O03018;
static BYTE o03019[] = O03019;
static BYTE o03020[] = O03020;
static BYTE o03021[] = O03021;
static BYTE o03022[] = O03022;
static BYTE o03023[] = O03023;
static BYTE o03024[] = O03024;

#ifndef integre
static BYTE o03025[] = O03025;
static BYTE o03026[] = O03026;
static BYTE o03027[] = O03027;
static BYTE o03028[] = O03028;
static BYTE o03029[] = O03029;
static BYTE o03030[] = O03030;
static BYTE o03031[] = O03031;
static BYTE o03032[] = O03032;
static BYTE o03033[] = O03033;
static BYTE o03034[] = O03034;
static BYTE o03035[] = O03035;
#endif /* integre */

/*	Messages pour le memento Commandes	*/
/*	----------------------------------	*/
static BYTE o04001[] = O04001;
static BYTE o04002[] = O04002;
static BYTE o04003[] = O04003;
static BYTE o04004[] = O04004;
static BYTE o04005[] = O04005;
static BYTE o04006[] = O04006;
static BYTE o04007[] = O04007;
static BYTE o04008[] = O04008;
static BYTE o04009[] = O04009;
static BYTE o04010[] = O04010;
static BYTE o04011[] = O04011;
static BYTE o04012[] = O04012;
static BYTE o04013[] = O04013;
static BYTE o04014[] = O04014;
static BYTE o04015[] = O04015;
static BYTE o04016[] = O04016;
static BYTE o04017[] = O04017;
static BYTE o04018[] = O04018;
static BYTE o04019[] = O04019;
static BYTE o04020[] = O04020;
static BYTE o04021[] = O04021;
static BYTE o04022[] = O04022;

#endif /* ver14 */

/*	Padding pour la traduction des messages */
/*	--------------------------------------- */
static BYTE ofil10[] = Mfil10;
static BYTE ofil11[] = Mfil11;
static BYTE ofil12[] = Mfil12;
static BYTE ofil13[] = Mfil13;
static BYTE ofil14[] = Mfil14;
static BYTE ofil15[] = Mfil15;
static BYTE ofil16[] = Mfil16;
static BYTE ofil17[] = Mfil17;
static BYTE ofil18[] = Mfil18;
static BYTE ofil19[] = Mfil19;
static BYTE ofil20[] = Mfil20;
static BYTE ofil21[] = Mfil21;
static BYTE ofil22[] = Mfil22;
static BYTE ofil23[] = Mfil23;
static BYTE ofil24[] = Mfil24;
static BYTE ofil25[] = Mfil25;
static BYTE ofil26[] = Mfil26;
static BYTE ofil27[] = Mfil27;
static BYTE ofil28[] = Mfil28;
static BYTE ofil29[] = Mfil29;
static BYTE ofil30[] = Mfil30;
static BYTE ofil31[] = Mfil31;
static BYTE ofil32[] = Mfil32;
static BYTE ofil33[] = Mfil33;
static BYTE ofil34[] = Mfil34;
static BYTE ofil35[] = Mfil35;
static BYTE ofil36[] = Mfil36;
static BYTE ofil37[] = Mfil37;
static BYTE ofil38[] = Mfil38;
static BYTE ofil39[] = Mfil39;
static BYTE ofil40[] = Mfil40;
static BYTE ofil41[] = Mfil41;
static BYTE ofil42[] = Mfil42;
static BYTE ofil43[] = Mfil43;
static BYTE ofil44[] = Mfil44;
static BYTE ofil45[] = Mfil45;
static BYTE ofil46[] = Mfil46;
static BYTE ofil47[] = Mfil47;
static BYTE ofil48[] = Mfil48;
static BYTE ofil49[] = Mfil49;

/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/

static BYTE ofin[] = Mfin;

#endif /* HX */

/*	Tableau des messages			*/
/*	--------------------			*/

#ifndef integre
#ifdef unix

#ifdef ver14
#define NBMESS 40
#else
#define NBMESS 32
#endif

#else /* unix */

#ifdef ver14
#define NBMESS 40
#else
#define NBMESS 32
#endif

#endif /* unix */

#else /* integre */

#ifdef unix
#define NBMESS 29
#else
#define NBMESS 29
#endif /* unix */

#endif /* integre */

/* global */ BYTE XPTR edit_msg[NBMESS];


#include "edmsgid.h"

#ifdef ver14

#define MCTRL 75
static BYTE XPTR edit_ctrl[MCTRL];

#else /* ver14 */

#ifndef integre
#define MCTRL 35
#else
#define MCTRL 24
#endif

/* global */ BYTE XPTR edit_ctrl[MCTRL];

#endif /* ver14 */

#define MAXCTRL MCTRL
#define MCOM 	22
#define MAXCOM	MCOM

/* global */ BYTE *edit_com[MCOM];

#endif	/* _edmsg_h */
	/* -------- */


