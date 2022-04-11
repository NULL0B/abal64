/*------------------------------------------------------------- NOYAU.H -------
 *
 *		Ensemble integre de developpement en ABAL
 *
 *
 *			Definitions du noyau
 *
 *				-*-
 *
 *		   Copyright (c) Prologue s.a. 1991,1993
 *
 *
 *		      Revision 2.1a
 *
 *
 *--------------------------------------------------------------------------*/


/*	version	*/
/*	------- */

#ifdef	VERSION666
#define	vabal	'3'
#define iabal	'1'
#define rabal	'e'
#define nabal	".0.03"
#define pabal	""	/* Version provisoire */
#define copyright	" Copyright (c) 1988,2006 Prologue "
#else
#define	vabal	'2'
#define iabal	'2'
#define rabal	'a'
//#define pabal	".0.04"	/* Version provisoire */
#define pabal	""	/* Version provisoire */
#define copyright	" Copyright (c) 1988,2001 Prologue "
#endif

/*	nom par defaut du fichier de configuration	*/
/*	------------------------------------------	*/

#ifdef prologue
#define nomficcfg	"ABAL-CFG"
#endif
#ifdef msdos
#define nomficcfg	"ABAL.CFG"
#endif
#ifdef unix
#define nomficcfg	"abal.cfg"
#endif
#ifdef vms
#define nomficcfg	"ABAL.CFG"
#endif

#define verscfg		"ABALCFG-STX-2"		/* version de config */

/*	Variable oui non		*/
/*	----------------		*/
static char ryes;
static char rno;

/*  	Wrep option dans le l'argument  */
/*      ------------------------------  */

static  BINAIRE wrep;
static  BOOL 	arg_verrue;

/* 	banniere ABAL		*/
/*	-------------		*/

#define NB_BAN 9
#define LG_BAN 35
#if unix || vms
#define CAR_FON 0x20
#define CAR_DEV 0x20
#define CAR_PLUS 
#else 
#define CAR_FON 0xB0
#define CAR_DEV 0xdd
#endif

static BYTE l1[] = "                                   ";
static BYTE l2[] = "     **    ***              ***    ";
static BYTE l3[] = "    ****    **               **    ";
static BYTE l4[] = "   **  **   **      ****     **    ";
static BYTE l5[] = "   **  **   *****      **    **    ";
static BYTE l6[] = "   ******   **  **  *****    **    ";
static BYTE l7[] = "   **  **   **  ** **  **    **    ";
static BYTE l8[] = "   **  **  ** ***   *** **  ****   ";
static BYTE l9[] = "                                   ";

static BYTE XPTR ban[NB_BAN] = { 
	&l1[0], &l2[0], &l3[0], &l4[0], &l5[0], &l6[0], &l7[0], &l8[0], &l9[0]
};



/*--------------------------------------------------------------------------*
 *
 *		   	Messages du moteur/noyau
 *
 *--------------------------------------------------------------------------*/

/*	Entete pour utilitaire de traduction	*/
/*	------------------------------------	*/


#ifdef	VERSION666
#define Mentete "*STX*3INTEGRE 31d00"
#define Oentete "*STX*3ABAL En 31d00"
#else
#define Mentete "*STX*3INTEGRE 22a00"
#define Oentete "*STX*3ABAL En 22a00"
#endif

#define Ouinon "ON0"
#define Yesno  "YN0"


#define Msgoui	 	"(X)"
#define Msgnon	 	"( )"
#define Msgesc	 	"ESC"
#define Msgcr	 	"CR"
#define Msgctr	 	"Ctrl-"
#define Msgnouval 	"Nouvelle valeur : "
#define Msgprog	  	"Commande   : "
#define Msgparam  	"Parametres : "
#define Msgetnom	" Fichier : "
#define Msgbadrun	" Erreur "
#define Msgnofile	" Aucun fichier "
#define Msgnomore	" Plus de fichier "
#define Msgaucun	" Liste vide "
#define Msgplein	" Liste pleine "
#define Msgcomed	" Commandes d'edition "
#define Msgfonct        " Touches de fonction "
#define Msgexcom	" Commande deja attribuee, confirmation (o/n) "
#define Msgreser	" Desole : combinaison reservee en interne "
#define Msgincfic	" Fichier inaccessible ou incorrect "
#define Msgexfic	" Fichier deja existant, continuer (o/n) "
#define Msgnomods	" Aucun module n'est defini en implicite "

#define Msgargerr 	"\n   Syntaxe d'appel incorrecte \n"
#define Msgficerr	"\n   Parametre fichier incorrect \n"
#define Msgficonf       "\n   Fichier de configuration incorrect \n"

/*	messages generaux		*/
/*	-----------------		*/

#define N00001 " Ensemble de developpement integre "
#define N00002 " Projet  : "
#define N00003 " Fichier : "
#define N00004 " Appuyez sur une touche pour continuer "
#define N00005 " "
#define N00006 " Nouveau fichier courant : "
#define N00007 " Designation : "

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

#define N01001 "Debordement capacite memoire"
#define N01002 " Erreur : pas de fichier courant selectionne "
#define N01003 "Segment : "

/*	messages contenus dans les menus	*/
/*	--------------------------------	*/

#define N02001 " Selection "
#define N02002 " Edition "
#define N02003 " Generation "
#define N02004 " eXecution "
#define N02005 " Utilitaire "
#define N02006 " Configuration "
#define N02007 " Fin "

#define N02008 " Oui "
#define N02009 " Non "

#define N02010 " Fichier courant    "
#define N02011 " Liste des modules  "
#define N02012 " Ouverture   projet "
#define N02013 " Edition     projet "
#define N02014 " feRmeture   projet "

#define N02015 " Trace des erreurs  "
#define N02016 " Lecture seule      "
#define N02017 " fichier Sauvegarde "
#define N02018 " editeur Configure  "

#define N02019 " sYsteme     "
#define N02020 " Traducteur  "
#define N02021 " Editeur     "
#define N02022 " Fichiers    "
#define N02023 " Repertoires "
#define N02024 " Macros      "
#define N02025 " fOnctions   "
#define N02026 " Sauvegarde  "
#define N02027 " rePrise     "

#define Mama05 " Actions posssibles "
#define Hama05 " Affichage des actions a entreprendre sans les executer "

#define N02030 " Source     "
#define N02031 " Liste      "
#define N02032 " Erreur     "
#define N02033 " sAuvegarde "
#define N02034 " Include    "
#define N02035 " Projet     "
#define N02036 " Makefile   "

#define N02037 " Mise a jour projet "
#define N02038 " Traduction         "
#define N02039 " Edition des liens  "
#define N02040 " options trAducteur "

#define N02041 " Normal         "
#define N02042 " Mise au point  "
#define N02043 " Argument       "

#define N02044 " Sources     "
#define N02045 " Traduits    "
#define N02046 " Utilitaires "
#define N02047 " Includes    "
#define N02048 " Projet      "

#define N02049 " Dedicat    "
#define N02050 " Ecran      "
#define N02051 " tRansbal   "
#define N02052 " Tsf        "
/*#define N02053 " svsI       "*/
/*#define N02054 " rtSi       "*/
#define N02053 " Svam       "
#define N02054 " rtAm       "	 
#define N02055 " frecupMc   "
#define N02056 " frecupBd   "
#define N02057 " sYsteme    "

/*	options de la configuration du traducteur		*/
/*	-----------------------------------------		*/

#define N03001 "Simple verification syntaxique          "
#define N03002 "Preparation a la mise au point          "
#define N03003 "Creation d'un fichier liste             "
#define N03004 "Liste des lignes non traduites          "
#define N03005 "Trace automatique des erreurs           "
#define N03006 "messages d'Avertissements               "
#define N03007 "Traduction de source pre-processe       "
#define N03008 "Detection des Alias sur les constantes  "
#define N03009 "Edition de liens enchainee              "

/*	commandes configurables de l'editeur		*/
/*	------------------------------------		*/

#define N04001 " Debut/Fin de page     "
#define N04002 " Debut/Fin de ligne    "
#define N04003 " Page suivante         "
#define N04004 " Page precedente       "
#define N04005 " Centrage ligne        "
#define N04006 " Mot suivant           "
#define N04007 " Mot precedent         "
#define N04008 " Insertion d'une ligne "
#define N04009 " Suppression ligne     "
#define N04010 " Suppression caractere courant   "
#define N04011 " Suppression caractere precedent "
#define N04012 " Suppression fin de ligne        "
#define N04013 " Suppression debut de ligne      "
#define N04014 " Annulation suppression          "
#define N04015 " Mode insertion (oui/non)        "
#define N04016 " Mode indentation (oui/non)      "
#define N04017 " Rappel position (oui/non)       "
#define N04018 " Erreur suivante (Trace)         "

/* 	Touche de fonction	*/
/* 	------------------	*/
#define N05001 " f1  : "
#define N05002 " f2  : "
#define N05003 " f3  : "
#define N05004 " f4  : "
#define N05005 " f5  : "
#define N05006 " f6  : "
#define N05007 " f7  : "
#define N05008 " f8  : "
#define N05009 " f9  : "
#define N05010 " F10 : "

/*	Messages d'aide 	*/
/*	---------------		*/
#define Msgscroll 	"\n"
#define N00008		"Version "
#define Msgsrep  	" "
#define Msgenv 		"    Environnement    "
#define Msgplu 		"Memoire insuffisante - Il faut sortir de l'ensemble integre"

/*	Messages d'aide "en ligne" associes aux menus	*/
/*	---------------------------------------------	*/
#define Help01 " Selection des fichiers courants (fichier, modules, projet) "
#define Help02 " Edition du fichier courant "
#define Help03 " Mise a jour du fichier courant "
#define Help04 " Execution ou mise au point d'un programme "
#define Help05 " Execution d'un utilitaire ABAL ou systeme "
#define Help06 " Configuration de l'environnement de travail "

#define Help07 " Selection d'un fichier courant "
#define Help08 " Selection des modules necessaires pour l'edition de liens "
#define Help09 " Activation d'un fichier de description de projet "
#define Help10 " Edition du fichier courant de description de projet "
#define Help11 " Desactivation du fichier courant de description de projet "

#define Help12 " Mise a jour des fichiers decrits dans le projet "
#define Help13 " Traduction du fichier courant "
#define Help14 " Edition des liens du fichier courant "
#define Help15 " Definir les options de la prochaine traduction "

#define Help16 " Execution du programme courant "
#define Help17 " Mise au point du programme courant "
#define Help18 " Argument a passer lors du lancement de l'application "

#define Help19 " Dedier un ou plusieurs programmes ABAL "
#define Help20 " Generer des masques de saisie "
#define Help21 " Convertir un source BAL en ABAL "
#define Help22 " Transferer ou archiver des fichiers via disquette "
#define Help23 " Sauvegarde d'un fichier Sequentiel Indexe "
#define Help24 " Restauration d'un fichier Sequentiel Indexe "
#define Help25 " Sauvegarde et/ou restauration d'un fichier Multicritere "
#define Help26 " Sauvegarde et/ou restauration d'un fichier Base de Donnees "
#define Help27 " Execution d'un utilitaire systeme "

#define Help28 " Configuration de l'ecran lors du lancement d'un utilitaire "
#define Help29 " Configuration du Traducteur "
#define Help30 " Configuration de l'editeur de texte "
#define Help31 " Configuration des extensions implicites "
#define Help32 " Configuration des repertoires implicites "
#define Help33 " Gestions des macros "
#define Help34 " Configuration des touches de fonctions "
#define Help35 " Sauvegarde de la configuration courante "
#define Help36 " Restauration d'une configuration "
#define Help37 " Confirmez vous la sortie de l'ensemble integre ? "
#define Help38 " Retour a l'ensemble integre "
#define Help39 " Sortie de l'ensemble integre "

/*	Messages d'aide "en ligne" associes aux menus	*/
/*	---------------------------------------------	*/
/*	options de configuration */

#define N06000 " Options     "
#define N06001 " Definitions "
#define N06002 " Liste des definitions : "
#define N06003 " Commandes         "
#define N06004 " touches fOnctions "
#define N06005 " Tabulation        "

#define Help40 " Selection des options de traduction "
#define Help41 " Definition de symboles de traduction conditionnelle "
#define Help42 " Liste des definitions pour la traduction "
#define Help43 " Personnaliser les commandes d'edition "
#define Help44 " Touches de fonctions de l'editeur "
#define Help45 " Choix de la valeur de tabulation pour l'edition "

#define Help46 " Fichier  "
#define Help47 " Module   "
#define Help48 " Projet   "
#define Help49 " Sauv cfg "
#define Help50 " Edition  "
#define Help51 " Maj PRJ  "
#define Help52 " Exec. AT "
#define Help53 " Recherche"
#define Help54 " Systeme  "
#define Help55 " Sortie   "

/*	Libelle extention */
#define N07001 " Sources     "
#define N07002 " Erreurs     "
#define N07003 " Listes      "
#define N07004 " sAuvegardes "
#define N07005 " Projets     "

/*	Libelle Repertoires */
#define N07100 " Sources    "
#define N07101 " Includes   "
#define N07102 " Modules    "
#define N07103 " Traduits   "
#define N07104 " Binaires   "

/* 	Pour le nom de projet par defaut */
#define N07200 " Plein ecran  "
#define N07201 " Outils abal3 "
#define Help56 " Mode plein ecran pour les utilitaires "

/* 	Add menu traduction */
/* 	------------------- */
#define N03000 "Post optimiseur enchaine                "
#define N03010 "Mots cles fonction math. non reserves   "


/*	help des extentions et des repertoires 		*/
/*	--------------------------------------		*/

/*	Libelle extention */
#define Hepl57 " Extentions des fichiers SOURCES par defaut "
#define Help58 " Extentions des fichiers ERREURS par defaut "
#define Help59 " Extentions des fichiers LISTES par defaut "
#define Help60 " Extentions des fichiers de SAUVEGARDES par defaut "
#define Help61 " Extentions des fichiers PROJETS par defaut "

/*	Libelle Repertoires */
#define Help62 " Repertoires des fichiers sources "
#define Help63 " Repertoires des fichiers includes "
#define Help64 " Repertoires des modules "
#define Help65 " Repertoires des traduits "
#define Help66 " Repertoires des binaires "

/*	Help sur les options editeur	*/
/*	----------------------------	*/
#define Help67 " Choix actif / non actif "	/* pour les help vides */
#define Help68 " Recherche d'erreurs apres traduction "
#define Help69 " Ne permet pas la modification du fichier "
#define Help70 " Conserver une copie du fichier d'origine "
#define Help71 " Editer avec les options de l'editeur et les extensions par defaut "

#define Notfind " Utilitaire non trouve "

/*-----------------*/
/* noms des listes */
/*-----------------*/
#define Lstfic " Fichier "
#define Lstrep " Repertoire "
#define Lstsrc " Historique des sources "
#define Lstprj " Historique des projets "
#define Lsttra " Historique des traduits "
#define Lstsys " Historique des commandes systemes "

#define Libpau " <ESC> stoppe l'enchainement prevu sinon appuyez sur une touche "
#define Nosrc  " Attention aucun FICHIER n'a ete selectionne "
#define Notra  " Attention aucun TRADUIT n'a ete selectionne "
#define Nomod  " Attention aucun MODULE n'a ete selectionne "
#define Warni  " Un probleme a ete detecte par l'utilitaire "
#define Selec  " Selection : "
#define Tmpcfg " Impossible de creer un fichier intermediaire "

#ifdef ver21

#define Skimsg " sKipper    "
#define Skihlp " Generateur d'interface utilisateur "

#define Pbrows " recHercher "
#define Hbrows " Rechercher une chaine dans un ou plusieurs fichiers ( <chaine> <ficn> ) "
#define Optobj " "
#define Hptobj " "
#define Lclass " "
#define Hclass " "

/* menu d'activation objet */

#define Mobj01 " Options       " 
#define Mobj02 " Unite de swap "
#define Mobj03 " "

#define Hobj01 " Options de mise en oeuvre du pre-processeur Objet "
#define Hobj02 " Designation de l'unite disque pour le swapping "
#define Hobj03 " "

/* Objet option activation */

#define Mobj12 " Traduction enchainee    "
#define Mobj13 " source genere stYlise   "
#define Mobj14 " Verification syntaxique "
#define Mobj15 " erreurs niveau1         "
#define Mobj16 " erreurs niveau2         "
#define Mobj17 " Ignorer les librairies  "
#define Mobj18 " Librairie -> include    "
#define Mobj19 " liste des Classes       " 
#define Mobj20 " Generer une librairie   "

#define Hobj12 " Appel du traducteur a la fin de la conversion OBJET -> ABAL "
#define Hobj13 " Respect des regles d'ecriture d'un programme ABAL "
#define Hobj14 " Pre-processe seulement. n'active pas la phase de generation "
#define Hobj15 " Trace des erreurs situees dans le source en entree "
#define Hobj16 " Concordance des erreurs entre le source en entree et le source genere "
#define Hobj17 " Ignorer les librairie utilisee dans le programme objet "
#define Hobj18 " Conversion des librairies en fichier include "
#define Hobj19 " Listes des interfaces des classes rencontrees "
#define Hobj20 " Generation d'une librairie. (pas de source genere). "
 
/* Objet option generation */

#define Mobj21 " Avertissement " 
#define Hobj21 " Prise en compte des directives #PRAGMA WARNING n "

#define Mobj22 " "
#define Mobj23 " "

#define Hobj22 " "
#define Hobj23 " "
 
/* Objet option optimisation */

/* configuration */

#define Mobj24 " obJets      "
#define Mobj25 " optimIseur  "

#define Hobj24 " Definition des options du pre-processeur Objet "     
#define Hobj25 " Definition des options de l'optimiseur de fichier traduit " 

#define Mobj26 " "
#define Mobj27 " "
#define Mobj28 " "
#define Mobj29 " "
#define Mobj30 " "
#define Mobj31 " "
#define Mobj32 " "
#define Mobj33 " "

#define Hobj26 " "
#define Hobj27 " "
#define Hobj28 " "
#define Hobj29 " "
#define Hobj30 " "
#define Hobj31 " "
#define Hobj32 " "
#define Hobj33 " "

/* configuration */

#define Mobj34 " Texte    "
#define Mobj35 " Fichiers "
#define Mobj36 " "
#define Mobj37 " "
#define Mobj38 " "
#define Mobj39 " "
#define Mobj40 " "
#define Mobj41 " "
#define Mobj42 " "
#define Mobj43 " "

#define Hobj34 " Liste des chaines a retrouver "
#define Hobj35 " Liste des fichiers dans lesquels chercher "
#define Hobj36 " "
#define Hobj37 " "
#define Hobj38 " "
#define Hobj39 " "
#define Hobj40 " "
#define Hobj41 " "
#define Hobj42 " "
#define Hobj43 " "
 
/*  generer  */

#define Mobj44 " Objet -> ABAL      "
#define Mobj45 " oPtimisation       "
#define Mobj46 " options obJets     "
#define Mobj47 " options poSt-opt.  "

#define Hobj44 " Conversion d'un source objet en source ABAL "
#define Hobj45 " Optimisations globales d'un fichier traduit "
#define Hobj46 " Definir les options du pre-processeur objet "
#define Hobj47 " Definir les options du post-optimiseur "


/* options ald */

#define Mald01 " References externes  "
#define Mald02 " "

#define Hald01 " References externes du module ( Variables, Procedures , Segments. ) "
#define Hald02 " "

/* options du post-optimiseur */

#define Mobj50 " Avertissements "
#define Mobj51 " Global         "
#define Mobj52 " Procedure      "
#define Mobj53 " Segment        "

#define Hobj50 " Indication du taux de reduction effectue "
#define Hobj51 " Elimination des redondances , du code non utilise , ... "
#define Hobj52 " Transposition en GOSUB des procedures sans argument "
#define Hobj53 " Transposition en GOSUB des segments "

#define Mama01 " Regeneration des cibles   "
#define Mama02 " Ignore les erreurs        "
#define Mama03 " Affiche les dependances   "
#define Mama04 " Force la maj de la date des cibles " 

#define Hama01 " Regeneration de toutes les cibles du projet "
#define Hama02 " Continue en sequence apres avoir rencontre une erreur "
#define Hama03 " Affiche les dependances testees "
#define Hama04 " la date de tous les fichiers cibles est forcee a la date du jour "

#define Mbro01 " Majuscule / minuscule "
#define Mbro02 " Inclusion             "
#define Mbro03 " Editer les occurences "
#define Mbro04 " Nombre d'occurence    "

#define Hbro01 " Distinction Majuscule / minuscule "
#define Hbro02 " Recherche dans tous  les fichiers inclus "
#define Hbro03 " Visualisation des recherches via l'editeur AED "
#define Hbro04 " Nombre d'occurrence de la chaine cherchee "

#define Mprj01 " Creation projet    "
#define Hprj01 " Creation automatique d'un projet "

#define Make01 " definition "
#define Make02 " outils "
#define Make03 " dependances par defaut "
#define Make04 " dependances explicites "
#define Make05 " Fin "

#define Mtfp00 "\006SF\015"
#define Mtfp01 "\006SL"
#define Mtfp02 "\006SC"
#define Mtfp03 "\006CS"
#define Mtfp04 "\006E\015"
#define Mtfp05 "\006GM"
#define Mtfp06 "\006XN"
#define Mtfp07 "\006UHT"
#define Mtfp08 "\006UY"
#define Mtfp09 "\006FO"
#define Mtfp10 "\006SF\011\030\030"
#define Mcou01 "*CB*28848"
#define Mcou02 "*CN*01824"
#define NN07201 " Abal 3      "
#define HHelp99 " Utilisation outils abal 3      "

#endif

/* Messages Anglais */

#define MMsgoui "(X)"
#define MMsgnon "( )"
#define MMsgesc "ESC"
#define MMsgcr  "CR"
#define MMsgctr "Ctrl-"
#define MMsgnouval "New value       : "
#define MMsgprog "Command    : "
#define MMsgparam "Parameters : "
#define MMsgetnom " File    : "
#define MMsgbadrun " Error "
#define MMsgnofile " No file "
#define MMsgnomore " No more files "
#define MMsgaucun " List empty "
#define MMsgplein " List full "
#define MMsgcomed " Print commands "
#define MMsgfonct " Function keys "
#define MMsgexcom " Command already assigned, confirmation (y/n)"
#define MMsgreser " Sorry:  combination reserved internally "
#define MMsgincfic " File not accessible or incorrect "
#define MMsgexfic " File already exists, continue (y/n) "
#define MMsgnomods " No module is implicitly defined "

#define MMsgargerr "\n   Call syntax incorrect \n"
#define MMsgficerr "\n   Incorrect file parameter \n"
#define MMsgficonf "\n   Incorrect configuration file \n"

/*	messages generaux		*/
/*	-----------------		*/

#define NN00001  "   Integrated development set    "
#define NN00002  " Project : "
#define NN00003 " File    : "
#define NN00004 "      Press any key to continue       "
#define NN00005 " "
#define NN00006 " New current file : "
#define NN00007 " Designation : "

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

#define NN01001 "Memory overflow"
#define NN01002 " Error:  no current file selected"
#define NN01003 "Segment : "

/*	messages contenus dans les menus	*/
/*	--------------------------------	*/

#define NN02001 " Selection "
#define NN02002 " Edit    "
#define NN02003 " Generation "
#define NN02004 " eXecution "
#define NN02005 " Utilities   "
#define NN02006 " Configuration "
#define NN02007 " End "

#define NN02008 " Yes "
#define NN02009 " No  "

#define NN02010 " Current file      "
#define NN02011 " List of modules   "
#define NN02012 " Open the project  "
#define NN02013 " Edit the project  "
#define NN02014 " close the pRoject "

#define NN02015 " Track of error    "
#define NN02016 " Read only         "
#define NN02017 " file Saved        "
#define NN02018 " editor Configured "

#define NN02019 " sYsteme     "
#define NN02020 " Translator  "
#define NN02021 " Editor      "
#define NN02022 " Files       "
#define NN02023 " Directories "
#define NN02024 "             "
#define NN02025 " functiOns   "
#define NN02026 " Save        "
#define NN02027 " Retry       "

#define MMama05 " Possible actions   "                                    
#define HHama05 " Display actions witout execute "

#define NN02030 " Source     "
#define NN02031 " List       "
#define NN02032 " Error      "
#define NN02033 " sAve       "
#define NN02034 " Include    "
#define NN02035 " Project    "
#define NN02036 " Makefile   "

#define NN02037 " Update the project "
#define NN02038 " Translation        "
#define NN02039 " Linkage editing    "
#define NN02040 " translator Options "

#define NN02041 " Normal         "
#define NN02042 " Debugging      "
#define NN02043 " Argument       "

#define NN02044 " Sources     "
#define NN02045 " Translated  "
#define NN02046 " Utilities   "
#define NN02047 " Includes    "
#define NN02048 " Projects    "

#define NN02049 "            "
#define NN02050 " Screen     "
#define NN02051 " trAnsbal   "
#define NN02052 " Tsf        "
/*#define NN02053 " svsI       "*/
/*#define NN02054 " RtSi       "*/
#define NN02053 " Svam       "
#define NN02054 " rtAm       "
#define NN02055 " frecovMc   "
#define NN02056 " frecovDb   "
#define NN02057 " sYstem     "

/*	options de la configuration du traducteur		*/
/*	-----------------------------------------		*/

#define NN03001 "sYntax checked only                    "
#define NN03002 "Preparation for debugging              "
#define NN03003 "Creation of a list file                "
#define NN03004 "List of all untranslated lines         "
#define NN03005 "Return to editor in case of errors     "
#define NN03006 "Warning messages                       "
#define NN03007 "Source generated by APLUS              "
#define NN03008 "Detection of aliases on constants      "
#define NN03009 "Automatic linking                      "

/*	commandes configurables de l'editeur		*/
/*	------------------------------------		*/

#define NN04001 "Start/end of page     "
#define NN04002 " Start/end of line     "
#define NN04003 " Next page             "
#define NN04004 " Preceding page        "
#define NN04005 " Line centering        "
#define NN04006 " Next word             "
#define NN04007 " Preceding word        "
#define NN04008 " Insertion of a line   "
#define NN04009 " Line deletion         "
#define NN04010 " Deletion current character      "
#define NN04011 " Deletion preceding character    "
#define NN04012 " Deletion end of line            "
#define NN04013 " Deletion start of line          "
#define NN04014 " Cancel deletion                 "
#define NN04015 " Insertion mode (yes/no)         "
#define NN04016 " Indentation mode (yes/no)       "
#define NN04017 " Recall position (yes/no)        "
#define NN04018 " Next error (Trace)              "

/* 	Touche de fonction	*/
/* 	------------------	*/

#define NN05001 " f1  : "
#define NN05002 " f2  : "
#define NN05003 " f3  : "
#define NN05004 " f4  : "
#define NN05005 " f5  : "
#define NN05006 " f6  : "
#define NN05007 " f7  : "
#define NN05008 " f8  : "
#define NN05009 " f9  : "
#define NN05010 " F10 : "
/*	Messages d'aide 	*/
/*	---------------		*/

#define MMsgscroll "\n"
#define NN00008 "Version  "
#define MMsgsrep " "
#define MMsgenv "    Environment  "
#define MMsgplu " "

/*	Messages d'aide "en ligne" associes aux menus	*/
/*	---------------------------------------------	*/

#define HHelp01 " Select current files (file, modules, project) "
#define HHelp02 " Edit current file "
#define HHelp03 " Update current file "
#define HHelp04 " Execute or debug a program "
#define HHelp05 " Execute an ABAL or system utility "
#define HHelp06 " Configuration of work environment "

#define HHelp07 " Select a current file "
#define HHelp08 " Select modules required for linkage editing "
#define HHelp09 " Activate a project description file "
#define HHelp10 " Edit project description current file "
#define HHelp11 " De-activate project description project file "

#define HHelp12 " Update files described in the project "
#define HHelp13 " Translation of current file "
#define HHelp14 " Linkage editing of current file "
#define HHelp15 " Define options for next translation "

#define HHelp16 " Execute current program "
#define HHelp17 " Start debugging monitor "
#define HHelp18 " Argument supply "

#define HHelp19 " "
#define HHelp20 " Generate entry forms "
#define HHelp21 " Convert a BAL program into an ABAL source program "
#define HHelp22 " Transfer or archive floppy disk files "
#define HHelp23 " Save an Indexed Sequential file "
#define HHelp24 " Restore an indexed Sequential file "
#define HHelp25 " Save and/or restore a Multicriteria file "
#define HHelp26 " Save and/or restore a Data Base file "
#define HHelp27 " Execute a system utility "

#define HHelp28 " Screen configuration at utility initiation"
#define HHelp29 " Translator configuration "
#define HHelp30 " Text editor configuration "
#define HHelp31 " Default extensions configuration "
#define HHelp32 " Default directories configuration "
#define HHelp33 " "
#define HHelp34 " Function keys configuration "
#define HHelp35 " Save current configuration "
#define HHelp36 " Restore a configuration "
#define HHelp37 " Are sure you want to exit from the integrated set ? "
#define HHelp38 " Return to integrated set "
#define HHelp39 " Exit from the integrated set "

/*	Messages d'aide "en ligne" associes aux menus	*/
/*	---------------------------------------------	*/
/*	options de configuration */

#define NN06000 " Options     "
#define NN06001 " Definitions "
#define NN06002 " List of definitions : "
#define NN06003 " Commands          "
#define NN06004 " functiOn keys     "
#define NN06005 " Tabbing           "

#define HHelp40 " Select translation options "
#define HHelp41 " Define conditional translation symbols "
#define HHelp42 " List of definitions for translation "
#define HHelp43 " Customize editing commands "
#define HHelp44 " Program editor function keys "
#define HHelp45 " Select tabbing value for editing "

#define HHelp46 "F1 key"
#define HHelp47 "F2 key"
#define HHelp48 "F3 key"
#define HHelp49 "F4 key"
#define HHelp50 "F5 key"
#define HHelp51 "F6 key"
#define HHelp52 "F7 key"
#define HHelp53 "F8 key"
#define HHelp54 "F9 key"
#define HHelp55 "F10 key"

/*	Libelle extention */
#define NN07001 " Sources     "
#define NN07002 " Errors      "
#define NN07003 " Lists       "
#define NN07004 " sAve        "
#define NN07005 " Projects    "

/*	Libelle Repertoires */
#define NN07100 " Sources     "
#define NN07101 " Includes    "
#define NN07102 " Modules     "
#define NN07103 " Translated  "
#define NN07104 " Utility     "

/* 	Pour le nom de projet par defaut */
#define NN07200 " Full screen "
#define HHelp56 " Full screen mode for utilities "
#define NN07201 " Abal 3      "
#define HHelp99 " Use Abal 3 Tools               "

/* 	Add menu traduction */
/* 	------------------- */

#define NN03000 " Activate post-optimiser               " /***/
#define NN03010 "Use mathematical library               "

/*	help des extentions et des repertoires 		*/
/*	--------------------------------------		*/

/*	Libelle extention */
#define HHepl57 " Extensions of SOURCE files by default "
#define HHelp58 " Extensions of ERROR files by default "
#define HHelp59 " Extensions LIST files by default "
#define HHelp60 " Extensions of BACKUP files by default "
#define HHelp61 " Extensions of PROJECT files by default "

/*	Libelle Repertoires */
#define HHelp62 " Directories of source files "
#define HHelp63 " Directories of includes files "
#define HHelp64 " Directories of modules "
#define HHelp65 " Directories of translated programs "
#define HHelp66 " Directories of utilities "

/*	Help sur les options editeur	*/
/*	----------------------------	*/

#define HHelp67 " Active / inactive choice "
#define HHelp68 " Search for errors after translation "
#define HHelp69 " Does not allow file to be modified "
#define HHelp70 " Keep a copy of the original file "
#define HHelp71 " Edit with editor options and default extensions "

#define NNotfind " Utility not found "


/*-----------------*/
/* noms des listes */
/*-----------------*/
#define LLstfic " File "
#define LLstrep " Directory "
#define LLstsrc " History of sources "
#define LLstprj " History of projects "
#define LLsttra " History of translated programs "
#define LLstsys " History of system commands "

#define LLibpau " <ESC> interrupts concatenation otherwise strike a key "
#define NNosrc  " Caution no FILE has been selected "
#define NNotra  " Caution no TRANSLATED PROGRAM has been selected "
#define NNomod  " Caution no MODULE has been selected "
#define WWarni  " A problem has been detected by the utility "
#define SSelec  " Selection : "
#define TTmpcfg " Impossible to create an intermediate file "                               

#ifdef ver21

#define SSkimsg " sKipper    "
#define SSkihlp " Man interface generator "

#define PPbrows " Find  "
#define HHbrows " Find token in files ( <token> <file> ) "
#define OOptobj " "
#define HHptobj " "
#define LLclass " "
#define HHclass " "

/* menu d'activation objet */

#define MMobj01 " Options       " 
#define MMobj02 " Swap unit "
#define MMobj03 " "
#define HHobj01 " Object integrator options "
#define HHobj02 " Set disk file for swapping "
#define HHobj03 " "

/* Objet option activation */

#define MMobj12 " Translation phase       "
#define MMobj13 " sOurce styling          "
#define MMobj14 " Syntax verification     "
#define MMobj15 " errors  level 1         "
#define MMobj16 " errors  level 2         "
#define MMobj17 " Ignore  libraries       "
#define MMobj18 " liBrairy  -> include    "
#define MMobj19 " Class list generation   " 
#define MMobj20 " Library generation      "

#define HHobj12 " Activate traductor after  OBJECT -> ABAL convertion "
#define HHobj13 " ABAL source styling "
#define HHobj14 " Inhibit translation phase "
#define HHobj15 " Activate source file errors "
#define HHobj16 " Activate extended error tracing "
#define HHobj17 " Ignore library used " 
#define HHobj18 " Library -> include convertion " 
#define HHobj19 " Class public interface generation "
#define HHobj20 " Libray generation (no target source generated) "
 
/* Objet option generation */

#define MMobj21 " Warnings " 
#define HHobj21 " Activate pragmas #PRAGMA WARNING n "

#define MMobj22 " "
#define MMobj23 " "

#define HHobj22 " "
#define HHobj23 " "
 
/* Objet option optimisation */

/* configuration */

#define MMobj24 " obJects     "
#define MMobj25 " optimIser  "

#define HHobj24 " Object integrator options set "
#define HHobj25 " Post optimiser options set "

#define MMobj26 " "
#define MMobj27 " "
#define MMobj28 " "
#define MMobj29 " "
#define MMobj30 " "
#define MMobj31 " "
#define MMobj32 " "
#define MMobj33 " "

#define HHobj26 " "
#define HHobj27 " "
#define HHobj28 " "
#define HHobj29 " "
#define HHobj30 " "
#define HHobj31 " "
#define HHobj32 " "
#define HHobj33 " "

/* configuration */

#define MMobj34 " Pattern  "
#define MMobj35 " Files    "
#define MMobj36 " "
#define MMobj37 " "
#define MMobj38 " "
#define MMobj39 " "
#define MMobj40 " "
#define MMobj41 " "
#define MMobj42 " "
#define MMobj43 " "

#define HHobj34 " Set patterns to find "
#define HHobj35 " Set Files checking "
#define HHobj36 " "
#define HHobj37 " "
#define HHobj38 " "
#define HHobj39 " "
#define HHobj40 " "
#define HHobj41 " "
#define HHobj42 " "
#define HHobj43 " "
 
/*  generer  */

#define MMobj44 " Object -> ABAL     "
#define MMobj45 " oPtimisation       "
#define MMobj46 " obJect options     "
#define MMobj47 " poSt-opt.  options "

#define HHobj44 " Convertion of an object source in  an ABAL source "
#define HHobj45 " Activate global optimisations "
#define HHobj46 " Object integrator options set "
#define HHobj47 " Post optimiser options set "

/* options ald */

#define MMald01 " External references  "
#define MMald02 " "

#define HHald01 " External references of module ( Variables, Procedures , Segments. ) "
#define HHald02 " "

/* options du post-optimiseur */

#define MMobj50 " Warnings       "
#define MMobj51 " Global         "
#define MMobj52 " Procedure      "
#define MMobj53 " Segment        "

#define HHobj50 " Indication of the reduced rate  "
#define HHobj51 " Strip not used code, variables, ... "
#define HHobj52 " Procedure into Gosub convertion if possible "
#define HHobj53 " Segment into Gosub convertion if possible "

#define MMama01 " Rebuilt all               "
#define MMama02 " Ignore errors             "
#define MMama03 " Display dependance        "
#define MMama04 " Touche target             " 

#define HHama01 " Build all dependant targets"
#define HHama02 " Ignore invocation errors "
#define HHama03 " Analyse and display without updating target "
#define HHama04 " Touche out of date targets "

#define MMbro01 " Case sensitive        "
#define MMbro02 " Inclusion             "
#define MMbro03 " Edit result           "
#define MMbro04 " Number found          "

#define HHbro01 " Force case sensitive compare "
#define HHbro02 " Analysis of inclusion "
#define HHbro03 " Edit patterns found "
#define HHbro04 " Quantify matched patterns  "

#define MMprj01 " create   Project   "
#define HHprj01 " Automatic project creation with all current options "

#define MMake01 " definition "
#define MMake02 " tools      "
#define MMake03 " Default  depandances "
#define MMake04 " Explicit dependances "
#define MMake05 " End "

#define MMtfp00 "\006SF\015"
#define MMtfp01 "\006SL"
#define MMtfp02 "\006SC"
#define MMtfp03 "\006CS"
#define MMtfp04 "\006E\015"
#define MMtfp05 "\006GM"
#define MMtfp06 "\006XN"
#define MMtfp07 "\006UHT"
#define MMtfp08 "\006UY"
#define MMtfp09 "\006FO"
#define MMtfp10 "\006SF\011\030\030"
#define MMcou01 "*CB*28848"
#define MMcou02 "*CN*01824"

#define MNN07201 " Abal 3      "
#define MHHelp99 " Use Abal 3 Tools               "

#endif
               
/*	Paddour la traduction des messages */
/*	--------------------------------------- */
               
#define Mfil10   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" 
#define Mfil11   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil12   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil13   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil14   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil15   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil16   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil17   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil18   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil19   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil20   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil21   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil22   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil23   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil24   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil25   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil26   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil27   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil28   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil29   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil30   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil31   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil32   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil33   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil34   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil35   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil36   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil37   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil38   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil39   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define Mfil40   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
               
/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/
               
#define Mfin "*ETX*"

               
#ifdef HX      
/*	Entete pour utilitaire de traduction	*/
/*	------------------------------------	*/
#define LGMAX 80
               
static char mentete[][LGMAX] = {
Mentete , 

Ouinon ,

Msgoui,
Msgnon,
Msgesc,
Msgcr,
Msgctr,
Msgnouval,
Msgprog,
Msgparam,
Msgetnom,
Msgbadrun,
Msgnofile,
Msgnomore,
Msgaucun,
Msgplein,
Msgcomed,
Msgfonct,
Msgexcom,
Msgreser,
Msgincfic,
Msgexfic,
Msgnomods,

Msgargerr,
Msgficerr,
Msgficonf,

/*	messages generaux		*/
/*	-----------------		*/

N00001,
N00002,
N00003,
N00004,
N00005,
N00006,
N00007,

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

N01001,
N01002,
N01003,

/*	messages contenus dans les menus	*/
/*	--------------------------------	*/

N02001,
N02002,
N02003,
N02004,
N02005,
N02006,
N02007,

N02008,
N02009,

N02010,
N02011,
N02012,
N02013,
N02014,

N02015,
N02016,
N02017,
N02018,

N02019,
N02020,
N02021,
N02022,
N02023,
N02024,
N02025,
N02026,
N02027,

Mama05,
Hama05,

N02030,
N02031,
N02032,
N02033,
N02034,
N02035,
N02036,

N02037,
N02038,
N02039,
N02040,

N02041,
N02042,
N02043,

N02044,
N02045,
N02046,
N02047,
N02048,

N02049,
N02050,
N02051,
N02052,
N02053,
N02054,	 
N02055,
N02056,
N02057,

/*	options de la configuration du traducteur		*/
/*	-----------------------------------------		*/

N03001 ,
N03002 ,
N03003 ,
N03004 ,
N03005 ,
N03006 ,
N03007 ,
N03008 ,
N03009 ,

/*	commandes configurables de l'editeur		*/
/*	------------------------------------		*/

N04001, 
N04002, 
N04003,
N04004, 
N04005 ,
N04006 ,
N04007, 
N04008, 
N04009, 
N04010, 
N04011, 
N04012, 
N04013, 
N04014, 
N04015, 
N04016, 
N04017, 
N04018, 

/* 	Touche de fonction	*/
/* 	------------------	*/
N05001 ,
N05002 ,
N05003 ,
N05004 ,
N05005 ,
N05006 ,
N05007 ,
N05008 ,
N05009 ,
N05010 ,

/*	Messages d'aide 	*/
/*	---------------		*/
Msgscroll 	,
N00008		,
Msgsrep  	,
Msgenv 		,
Msgplu 		,

/*	Messages d'aide , associes aux menus	*/
/*	---------------------------------------------	*/
Help01 ,
Help02 ,
Help03 ,
Help04 ,
Help05 ,
Help06 ,

Help07 ,
Help08 ,
Help09 ,
Help10 ,
Help11 ,

Help12 ,
Help13 ,
Help14 ,
Help15 ,

Help16 ,
Help17 ,
Help18 ,

Help19 ,
Help20 ,
Help21 ,
Help22 ,
Help23 ,
Help24 ,
Help25 ,
Help26 ,
Help27 ,

Help28 ,
Help29 ,
Help30 ,
Help31 ,
Help32 ,
Help33 ,
Help34 ,
Help35 ,
Help36 ,
Help37 ,
Help38 ,
Help39 ,

/*	Messages d'aide , associes aux menus	*/
/*	---------------------------------------------	*/
/*	options de configuration */

N06000 ,
N06001 ,
N06002 ,
N06003 ,
N06004 ,
N06005 ,

Help40 ,
Help41 ,
Help42 ,
Help43 ,
Help44 ,
Help45 ,

Help46 ,
Help47 ,
Help48 ,
Help49 ,
Help50 ,
Help51 ,
Help52 ,
Help53 ,
Help54 ,
Help55 ,

/*	Libelle extention */
N07001 ,
N07002 ,
N07003 ,
N07004 ,
N07005 ,

/*	Libelle Repertoires */
N07100 ,
N07101 ,
N07102 ,
N07103 ,
N07104 ,

/* 	Pour le nom de projet par defaut */
N07200 ,
Help56 ,

/* 	Add menu traduction */
/* 	------------------- */
N03000 ,
N03010 ,


/*	help des extentions et des repertoires 		*/
/*	--------------------------------------		*/

/*	Libelle extention */
Hepl57 ,
Help58 ,
Help59 ,
Help60 ,
Help61 ,

/*	Libelle Repertoires */
Help62 ,
Help63 ,
Help64 ,
Help65 ,
Help66 ,

/*	Help sur les options editeur	*/
/*	----------------------------	*/
Help67 ,	/* pour les help vides */
Help68 ,
Help69 ,
Help70 ,
Help71 ,

Notfind ,

/*-----------------*/
/* noms des listes */
/*-----------------*/
Lstfic ,
Lstrep ,
Lstsrc ,
Lstprj ,
Lsttra ,
Lstsys ,

Libpau ,
Nosrc  ,
Notra  ,
Nomod  ,
Warni  ,
Selec  ,
Tmpcfg ,

#ifdef ver21
Skimsg ,
Skihlp ,
Pbrows,
Hbrows,
Optobj,
Hptobj,

Lclass, 
Hclass, 

Mobj01,
Mobj02,
Mobj03,

Hobj01,
Hobj02,
Hobj03,

Mobj12,
Mobj13,
Mobj14,
Mobj15,
Mobj16,
Mobj17,
Mobj18,
Mobj19,
Mobj20,

Hobj12,
Hobj13,
Hobj14,
Hobj15,
Hobj16,
Hobj17,
Hobj18,
Hobj19,
Hobj20,

Mobj21,
Hobj21,

Mobj22,
Mobj23,
Hobj22,
Hobj23,

Mobj24,
Mobj25,
Hobj24,
Hobj25,

Mobj26,
Mobj27,
Mobj28,
Mobj29,
Mobj30,
Mobj31,
Mobj32,
Mobj33,

Hobj26,
Hobj27,
Hobj28,
Hobj29,
Hobj30,
Hobj31,
Hobj32,
Hobj33,

Mobj34,
Mobj35,
Mobj36,
Mobj37,
Mobj38,
Mobj39,
Mobj40,
Mobj41,
Mobj42,
Mobj43,

Hobj34,
Hobj35,
Hobj36,
Hobj37,
Hobj38,
Hobj39,
Hobj40,
Hobj41,
Hobj42,
Hobj43,

Mobj44,
Mobj45,
Mobj46,
Mobj47,

Hobj44,
Hobj45,
Hobj46,
Hobj47,

Mald01,
Mald02,
Hald01,
Hald02,

Mobj50,
Mobj51,
Mobj52,
Mobj53,

Hobj50,
Hobj51,
Hobj52,
Hobj53,


Mama01,
Mama02,
Mama03,
Mama04,

Hama01,
Hama02,
Hama03,
Hama04,

Mbro01,
Mbro02,
Mbro03,
Mbro04,

Hbro01,
Hbro02,
Hbro03,
Hbro04,
Mprj01,
Hprj01,

Make01,
Make02,
Make03,
Make04,
Make05,

Mtfp00,
Mtfp01,
Mtfp02,
Mtfp03,
Mtfp04,
Mtfp05,
Mtfp06,
Mtfp07,
Mtfp08,
Mtfp09,
Mtfp10,
Mcou01,
Mcou02,
#endif

NN07201 ,
HHelp99 ,

/***	Padding pour la traduction des messages */
/*	--------------------------------------- */

Mfil10  ,
Mfil11  ,
Mfil12  ,
Mfil13  ,
Mfil14  ,
Mfil15  ,
Mfil16  ,
Mfil17  ,
Mfil18  ,
Mfil19  ,
Mfil20  ,
Mfil21  ,
Mfil22  ,
Mfil23  ,
Mfil24  ,
Mfil25  ,
Mfil26  ,
Mfil27  ,
Mfil28  ,
Mfil29  ,
Mfil30  ,
Mfil31  ,
Mfil32  ,
Mfil33  ,
Mfil34  ,
Mfil35  ,
Mfil36  ,
Mfil37  ,
Mfil38  ,
Mfil39  ,
Mfil40  ,

/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/

Mfin

};

static char oentete[][LGMAX] = {
Oentete , 

Yesno ,

MMsgoui,	MMsgnon,	MMsgesc,	MMsgcr,		MMsgctr,
MMsgnouval,	MMsgprog,	MMsgparam,	MMsgetnom,	MMsgbadrun,
MMsgnofile,	MMsgnomore,	MMsgaucun,	MMsgplein,	MMsgcomed,
MMsgfonct,	MMsgexcom,	MMsgreser,	MMsgincfic,	MMsgexfic,
MMsgnomods,	MMsgargerr,	MMsgficerr,	MMsgficonf,

/*	messages generaux		*/
/*	-----------------		*/

NN00001,
NN00002,
NN00003,
NN00004,
NN00005,
NN00006,
NN00007,

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

NN01001,
NN01002,
NN01003,

/*	messages contenus dans les menus	*/
/*	--------------------------------	*/

NN02001,
NN02002,
NN02003,
NN02004,
NN02005,
NN02006,
NN02007,

NN02008,
NN02009,

NN02010,
NN02011,
NN02012,
NN02013,
NN02014,

NN02015,
NN02016,
NN02017,
NN02018,

NN02019,
NN02020,
NN02021,
NN02022,
NN02023,
NN02024,
NN02025,
NN02026,
NN02027,

MMama05,
HHama05,

NN02030,
NN02031,
NN02032,
NN02033,
NN02034,
NN02035,
NN02036,

NN02037,
NN02038,
NN02039,
NN02040,

NN02041,
NN02042,
NN02043,

NN02044,
NN02045,
NN02046,
NN02047,
NN02048,

NN02049,
NN02050,
NN02051,
NN02052,
NN02053,
NN02054,	 
NN02055,
NN02056,
NN02057,

/*	options de la configuration du traducteur		*/
/*	-----------------------------------------		*/

NN03001 ,
NN03002 ,
NN03003 ,
NN03004 ,
NN03005 ,
NN03006 ,
NN03007 ,
NN03008 ,
NN03009 ,

/*	commandes configurables de l'editeur		*/
/*	------------------------------------		*/

NN04001, 
NN04002, 
NN04003,
NN04004, 
NN04005 ,
NN04006 ,
NN04007, 
NN04008, 
NN04009, 
NN04010, 
NN04011, 
NN04012, 
NN04013, 
NN04014, 
NN04015, 
NN04016, 
NN04017, 
NN04018, 

/* 	Touche de fonction	*/
/* 	------------------	*/
NN05001 ,
NN05002 ,
NN05003 ,
NN05004 ,
NN05005 ,
NN05006 ,
NN05007 ,
NN05008 ,
NN05009 ,
NN05010 ,

/*	MMessages d'aide 	*/
/*	---------------		*/
MMsgscroll 	,
NN00008		,
MMsgsrep  	,
MMsgenv 		,
MMsgplu 		,

/*	MMessages d'aide , associes aux menus	*/
/*	---------------------------------------------	*/
HHelp01 ,
HHelp02 ,
HHelp03 ,
HHelp04 ,
HHelp05 ,
HHelp06 ,

HHelp07 ,
HHelp08 ,
HHelp09 ,
HHelp10 ,
HHelp11 ,

HHelp12 ,
HHelp13 ,
HHelp14 ,
HHelp15 ,

HHelp16 ,
HHelp17 ,
HHelp18 ,

HHelp19 ,
HHelp20 ,
HHelp21 ,
HHelp22 ,
HHelp23 ,
HHelp24 ,
HHelp25 ,
HHelp26 ,
HHelp27 ,

HHelp28 ,
HHelp29 ,
HHelp30 ,
HHelp31 ,
HHelp32 ,
HHelp33 ,
HHelp34 ,
HHelp35 ,
HHelp36 ,
HHelp37 ,
HHelp38 ,
HHelp39 ,

/*	MMessages d'aide , associes aux menus	*/
/*	---------------------------------------------	*/
/*	options de configuration */

NN06000 ,
NN06001 ,
NN06002 ,
NN06003 ,
NN06004 ,
NN06005 ,

HHelp40 ,
HHelp41 ,
HHelp42 ,
HHelp43 ,
HHelp44 ,
HHelp45 ,

HHelp46 ,
HHelp47 ,
HHelp48 ,
HHelp49 ,
HHelp50 ,
HHelp51 ,
HHelp52 ,
HHelp53 ,
HHelp54 ,
HHelp55 ,

/*	Libelle extention */
NN07001 ,
NN07002 ,
NN07003 ,
NN07004 ,
NN07005 ,

/*	Libelle Repertoires */
NN07100 ,
NN07101 ,
NN07102 ,
NN07103 ,
NN07104 ,

/* 	Pour le nom de projet par defaut */
NN07200 ,
HHelp56 ,

/* 	Add menu traduction */
/* 	------------------- */
NN03000 ,
NN03010 ,


/*	help des extentions et des repertoires 		*/
/*	--------------------------------------		*/

/*	Libelle extention */
HHepl57 ,
HHelp58 ,
HHelp59 ,
HHelp60 ,
HHelp61 ,

/*	Libelle Repertoires */
HHelp62 ,
HHelp63 ,
HHelp64 ,
HHelp65 ,
HHelp66 ,

/*	HHelp sur les options editeur	*/
/*	----------------------------	*/
HHelp67 ,	/* pour les help vides */
HHelp68 ,
HHelp69 ,
HHelp70 ,
HHelp71 ,

NNotfind ,

/*-----------------*/
/* noms des listes */
/*-----------------*/
LLstfic ,
LLstrep ,
LLstsrc ,
LLstprj ,
LLsttra ,
LLstsys ,

LLibpau ,
NNosrc  ,
NNotra  ,
NNomod  ,
WWarni  ,
SSelec  ,
TTmpcfg ,

#ifdef ver21
SSkimsg ,
SSkihlp ,
PPbrows,
HHbrows,
OOptobj,
HHptobj,

LLclass, 
HHclass, 

MMobj01,
MMobj02,
MMobj03,

HHobj01,
HHobj02,
HHobj03,

MMobj12,
MMobj13,
MMobj14,
MMobj15,
MMobj16,
MMobj17,
MMobj18,
MMobj19,
MMobj20,

HHobj12,
HHobj13,
HHobj14,
HHobj15,
HHobj16,
HHobj17,
HHobj18,
HHobj19,
HHobj20,

MMobj21,
HHobj21,

MMobj22,
MMobj23,
HHobj22,
HHobj23,

MMobj24,
MMobj25,
HHobj24,
HHobj25,

MMobj26,
MMobj27,
MMobj28,
MMobj29,
MMobj30,
MMobj31,
MMobj32,
MMobj33,

HHobj26,
HHobj27,
HHobj28,
HHobj29,
HHobj30,
HHobj31,
HHobj32,
HHobj33,

MMobj34,
MMobj35,
MMobj36,
MMobj37,
MMobj38,
MMobj39,
MMobj40,
MMobj41,
MMobj42,
MMobj43,

HHobj34,
HHobj35,
HHobj36,
HHobj37,
HHobj38,
HHobj39,
HHobj40,
HHobj41,
HHobj42,
HHobj43,

MMobj44,
MMobj45,
MMobj46,
MMobj47,

HHobj44,
HHobj45,
HHobj46,
HHobj47,

MMald01,
MMald02,
HHald01,
HHald02,

MMobj50,
MMobj51,
MMobj52,
MMobj53,

HHobj50,
HHobj51,
HHobj52,
HHobj53,


MMama01,
MMama02,
MMama03,
MMama04,

HHama01,
HHama02,
HHama03,
HHama04,

MMbro01,
MMbro02,
MMbro03,
MMbro04,

HHbro01,
HHbro02,
HHbro03,
HHbro04,
MMprj01,
HHprj01,

MMake01,
MMake02,
MMake03,
MMake04,
MMake05,

MMtfp00,
MMtfp01,
MMtfp02,
MMtfp03,
MMtfp04,
MMtfp05,
MMtfp06,
MMtfp07,
MMtfp08,
MMtfp09,
MMtfp10,
MMcou01,
MMcou02,
#endif

MNN07201 ,
MHHelp99 ,


/***	Padding pour la traduction des messages */
/*	--------------------------------------- */

Mfil10  ,
Mfil11  ,
Mfil12  ,
Mfil13  ,
Mfil14  ,
Mfil15  ,
Mfil16  ,
Mfil17  ,
Mfil18  ,
Mfil19  ,
Mfil20  ,
Mfil21  ,
Mfil22  ,
Mfil23  ,
Mfil24  ,
Mfil25  ,
Mfil26  ,
Mfil27  ,
Mfil28  ,
Mfil29  ,
Mfil30  ,
Mfil31  ,
Mfil32  ,
Mfil33  ,
Mfil34  ,
Mfil35  ,
Mfil36  ,
Mfil37  ,
Mfil38  ,
Mfil39  ,
Mfil40  ,

/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/

Mfin

};

#else /* HX */

static char mentete[] = Mentete;
static char ouinon[]  = Ouinon;

static char msgoui[]    =     Msgoui;
static char msgnon[]    =     Msgnon;
static char msgesc[]    =     Msgesc;
static char msgcr[]     =     Msgcr;
static char msgctr[]    =     Msgctr;
static char msgnouval[] =     Msgnouval;
static char msgprog[]   =     Msgprog;
static char msgparam[]  =     Msgparam;
static char msgetnom[]  =     Msgetnom;
static char msgbadrun[] =      Msgbadrun;
static char msgnofile[] =      Msgnofile;
static char msgnomore[] =      Msgnomore;
static char msgaucun[]  =     Msgaucun;
static char msgplein[]  =     Msgplein;
static char msgcomed[]  =     Msgcomed;
static char msgfonct[]  =     Msgfonct;
static char msgexcom[]  =     Msgexcom;
static char msgreser[]  =     Msgreser;
static char msgincfic[] =      Msgincfic;
static char msgexfic[]  =     Msgexfic;
static char msgnomods[] =     Msgnomods;
                              
static char msgargerr[] =     Msgargerr;
static char msgficerr[] =     Msgficerr;
static char msgficonf[] =     Msgficonf;

/*	messages generaux		*/
/*	-----------------		*/

static char m00001[] = N00001;
static char m00002[] = N00002;
static char m00003[] = N00003;
static char m00004[] = N00004;
static char m00005[] = N00005;
static char m00006[] = N00006;
static char m00007[] = N00007;
                       
/*	messages specifiques du noyau	*/
/*	-----------------------------	*/
                       
static char m01001[] = N01001;
static char m01002[] = N01002;
static char m01003[] = N01003;
                       
/*	messages contenus dans les menus	*/
/*	--------------------------------	*/
                       
static char m02001[] = N02001;
static char m02002[] = N02002;
static char m02003[] = N02003;
static char m02004[] = N02004;
static char m02005[] = N02005;
static char m02006[] = N02006;
static char m02007[] = N02007;
                       
static char m02008[] = N02008;
static char m02009[] = N02009;
                       
static char m02010[] = N02010;
static char m02011[] = N02011;
static char m02012[] = N02012;
static char m02013[] = N02013;
static char m02014[] = N02014;
                       
static char m02015[] = N02015;
static char m02016[] = N02016;
static char m02017[] = N02017;
static char m02018[] = N02018;
                       
static char m02019[] = N02019;
static char m02020[] = N02020;
static char m02021[] = N02021;
static char m02022[] = N02022;
static char m02023[] = N02023;
static char m02024[] = N02024;
static char m02025[] = N02025;
static char m02026[] = N02026;
static char m02027[] = N02027;
                       
static char mama05[] = Mama05;
static char hama05[] = Hama05;
                       
static char m02030[] = N02030;
static char m02031[] = N02031;
static char m02032[] = N02032;
static char m02033[] = N02033;
static char m02034[] = N02034;
static char m02035[] = N02035;
static char m02036[] = N02036;
                       
static char m02037[] = N02037;
static char m02038[] = N02038;
static char m02039[] = N02039;
static char m02040[] = N02040;
                       
static char m02041[] = N02041;
static char m02042[] = N02042;
static char m02043[] = N02043;
                       
static char m02044[] = N02044;
static char m02045[] = N02045;
static char m02046[] = N02046;
static char m02047[] = N02047;
static char m02048[] = N02048;
                       
static char m02049[] = N02049;
static char m02050[] = N02050;
static char m02051[] = N02051;
static char m02052[] = N02052;
static char m02053[] = N02053;
static char m02054[] = N02054;	 
static char m02055[] = N02055;
static char m02056[] = N02056;
static char m02057[] = N02057;
                       
/*	options de la configuration du traducteur		*/
/*	-----------------------------------------		*/
                       
static char m03001[] = N03001 ;
static char m03002[] = N03002 ;
static char m03003[] = N03003 ;
static char m03004[] = N03004 ;
static char m03005[] = N03005 ;
static char m03006[] = N03006 ;
static char m03007[] = N03007 ;
static char m03008[] = N03008 ;
static char m03009[] = N03009 ;
                       
/*	commandes configurables de l'editeur		*/
/*	------------------------------------		*/
                       
static char m04001[] = N04001; 
static char m04002[] = N04002; 
static char m04003[] = N04003;
static char m04004[] = N04004; 
static char m04005[] = N04005 ;
static char m04006[] = N04006 ;
static char m04007[] = N04007; 
static char m04008[] = N04008; 
static char m04009[] = N04009; 
static char m04010[] = N04010; 
static char m04011[] = N04011; 
static char m04012[] = N04012; 
static char m04013[] = N04013; 
static char m04014[] = N04014; 
static char m04015[] = N04015; 
static char m04016[] = N04016; 
static char m04017[] = N04017; 
static char m04018[] = N04018; 
                       
/* 	Touche de fonction	*/
/* 	------------------	*/
static char m05001[] = N05001 ;
static char m05002[] = N05002 ;
static char m05003[] = N05003 ;
static char m05004[] = N05004 ;
static char m05005[] = N05005 ;
static char m05006[] = N05006 ;
static char m05007[] = N05007 ;
static char m05008[] = N05008 ;
static char m05009[] = N05009 ;
static char m05010[] = N05010 ;

/*	Messages d'aide 	*/
/*	---------------		*/
static char msgscroll[] = Msgscroll;
static char m00008[]    = N00008;
static char msgsrep[]   = Msgsrep;
static char msgenv[]    = Msgenv;
static char msgplu[]    = Msgplu;

/*	Messages d'aide ; associes aux menus	*/
/*	---------------------------------------------	*/
static char help01[] = Help01 ;
static char help02[] = Help02 ;
static char help03[] = Help03 ;
static char help04[] = Help04 ;
static char help05[] = Help05 ;
static char help06[] = Help06 ;
                       
static char help07[] = Help07 ;
static char help08[] = Help08 ;
static char help09[] = Help09 ;
static char help10[] = Help10 ;
static char help11[] = Help11 ;
                       
static char help12[] = Help12 ;
static char help13[] = Help13 ;
static char help14[] = Help14 ;
static char help15[] = Help15 ;
                       
static char help16[] = Help16 ;
static char help17[] = Help17 ;
static char help18[] = Help18 ;
                       
static char help19[] = Help19 ;
static char help20[] = Help20 ;
static char help21[] = Help21 ;
static char help22[] = Help22 ;
static char help23[] = Help23 ;
static char help24[] = Help24 ;
static char help25[] = Help25 ;
static char help26[] = Help26 ;
static char help27[] = Help27 ;
                       
static char help28[] = Help28 ;
static char help29[] = Help29 ;
static char help30[] = Help30 ;
static char help31[] = Help31 ;
static char help32[] = Help32 ;
static char help33[] = Help33 ;
static char help34[] = Help34 ;
static char help35[] = Help35 ;
static char help36[] = Help36 ;
static char help37[] = Help37 ;
static char help38[] = Help38 ;
static char help39[] = Help39 ;
                       
/*	Messages d'aide ; associes aux menus	*/
/*	---------------------------------------------	*/
/*	options de configuration */
                       
static char m06000[] = N06000 ;
static char m06001[] = N06001 ;
static char m06002[] = N06002 ;
static char m06003[] = N06003 ;
static char m06004[] = N06004 ;
static char m06005[] = N06005 ;
                       
static char help40[] = Help40 ;
static char help41[] = Help41 ;
static char help42[] = Help42 ;
static char help43[] = Help43 ;
static char help44[] = Help44 ;
static char help45[] = Help45 ;
                       
static char help46[] = Help46 ;
static char help47[] = Help47 ;
static char help48[] = Help48 ;
static char help49[] = Help49 ;
static char help50[] = Help50 ;
static char help51[] = Help51 ;
static char help52[] = Help52 ;
static char help53[] = Help53 ;
static char help54[] = Help54 ;
static char help55[] = Help55 ;
                       
/*	Libelle extention */
static char m07001[] = N07001 ;
static char m07002[] = N07002 ;
static char m07003[] = N07003 ;
static char m07004[] = N07004 ;
static char m07005[] = N07005 ;
                       
/*	Libelle Repertoires */
static char m07100[] = N07100 ;
static char m07101[] = N07101 ;
static char m07102[] = N07102 ;
static char m07103[] = N07103 ;
static char m07104[] = N07104 ;
                       
/* 	Pour le nom de projet par defaut */
static char m07200[] = N07200 ;
static char help56[] = Help56 ;
                       
/* 	Add menu traduction */
/* 	------------------- */
static char m03000[] = N03000 ;
static char m03010[] = N03010 ;
                       
                       
/*	help des extentions et des repertoires 		*/
/*	--------------------------------------		*/

/*	Libelle extention */
static char hepl57[] = Hepl57 ;
static char help58[] = Help58 ;
static char help59[] = Help59 ;
static char help60[] = Help60 ;
static char help61[] = Help61 ;
                       
/*	Libelle Repertoires */
static char help62[] = Help62 ;
static char help63[] = Help63 ;
static char help64[] = Help64 ;
static char help65[] = Help65 ;
static char help66[] = Help66 ;
                       
/*	Help sur les options editeur	*/
/*	----------------------------	*/
static char help67[] = Help67 ;	/* pour les help vides */
static char help68[] = Help68 ;
static char help69[] = Help69 ;
static char help70[] = Help70 ;
static char help71[] = Help71 ;
                       
static char notfind[] =Notfind ;
                       
/*-----------------*/
/* noms des listes */
/*-----------------*/
static char lstfic[] = Lstfic ;
static char lstrep[] = Lstrep ;
static char lstsrc[] = Lstsrc ;
static char lstprj[] = Lstprj ;
static char lsttra[] = Lsttra ;
static char lstsys[] = Lstsys ;
                       
static char libpau[] = Libpau ;
static char nosrc[]  = Nosrc  ;
static char notra[]  = Notra  ;
static char nomod[]  = Nomod  ;
static char warni[]  = Warni  ;
static char selec[]  = Selec  ;
static char tmpcfg[] = Tmpcfg ;
                       
#ifdef ver21
static char skimsg[] = Skimsg ;
static char skihlp[] = Skihlp ;

static char pbrows[] = Pbrows;
static char hbrows[] = Hbrows;
static char optobj[] = Optobj;
static char hoptob[] = Hptobj;
static char lclass[] = Lclass;
static char hclass[] = Hclass;

static char mobj01[] = Mobj01;
static char mobj02[] = Mobj02;
static char mobj03[] = Mobj03;
                   
static char hobj01[] = Hobj01;
static char hobj02[] = Hobj02;
static char hobj03[] = Hobj03;
                   
static char mobj12[] = Mobj12;
static char mobj13[] = Mobj13;
static char mobj14[] = Mobj14;
static char mobj15[] = Mobj15;
static char mobj16[] = Mobj16;
static char mobj17[] = Mobj17;
static char mobj18[] = Mobj18;
static char mobj19[] = Mobj19;
static char mobj20[] = Mobj20;
                   
static char hobj12[] = Hobj12;
static char hobj13[] = Hobj13;
static char hobj14[] = Hobj14;
static char hobj15[] = Hobj15;
static char hobj16[] = Hobj16;
static char hobj17[] = Hobj17;
static char hobj18[] = Hobj18;
static char hobj19[] = Hobj19;
static char hobj20[] = Hobj20;
                   
static char mobj21[] = Mobj21;
static char hobj21[] = Hobj21;

static char mobj22[] = Mobj22;
static char mobj23[] = Mobj23;
static char hobj22[] = Hobj22;
static char hobj23[] = Hobj23;
                   
static char mobj24[] = Mobj24;
static char mobj25[] = Mobj25;
static char hobj24[] = Hobj24;
static char hobj25[] = Hobj25;

static char mobj26[] = Mobj26;
static char mobj27[] = Mobj27;
static char mobj28[] = Mobj28;
static char mobj29[] = Mobj29;
static char mobj30[] = Mobj30;
static char mobj31[] = Mobj31;
static char mobj32[] = Hobj32;
static char mobj33[] = Hobj33;

static char hobj26[] = Hobj26;
static char hobj27[] = Hobj27;
static char hobj28[] = Hobj28;
static char hobj29[] = Hobj29;
static char hobj30[] = Hobj30;
static char hobj31[] = Hobj31;
static char hobj32[] = Hobj32;
static char hobj33[] = Hobj33;
                   
static char mobj34[] = Mobj34;
static char mobj35[] = Mobj35;
static char mobj36[] = Mobj36;
static char mobj37[] = Mobj37;
static char mobj38[] = Mobj38;
static char mobj39[] = Mobj39;
static char mobj40[] = Mobj40;
static char mobj41[] = Mobj41;
static char mobj42[] = Mobj42;
static char mobj43[] = Mobj43;
                   
static char hobj34[] = Hobj34;
static char hobj35[] = Hobj35;
static char hobj36[] = Hobj36;
static char hobj37[] = Hobj37;
static char hobj38[] = Hobj38;
static char hobj39[] = Hobj39;
static char hobj40[] = Hobj40;
static char hobj41[] = Hobj41;
static char hobj42[] = Hobj42;
static char hobj43[] = Hobj43;
                   
static char mobj44[] = Mobj44;
static char mobj45[] = Mobj45;
static char mobj46[] = Mobj46;
static char mobj47[] = Mobj47;

static char hobj44[] = Hobj44;
static char hobj45[] = Hobj45;
static char hobj46[] = Hobj46;
static char hobj47[] = Hobj47;

static char mald01[] = Mald01;
static char mald02[] = Mald02;
static char hald01[] = Hald01;
static char hald02[] = Hald02;
                   
static char mobj50[] = Mobj50;
static char mobj51[] = Mobj51;
static char mobj52[] = Mobj52;
static char mobj53[] = Mobj53;
                   
static char hobj50[] = Hobj50;
static char hobj51[] = Hobj51;
static char hobj52[] = Hobj52;
static char hobj53[] = Hobj53;
                   
static char mama01[] = Mama01;
static char mama02[] = Mama02;
static char mama03[] = Mama03;
static char mama04[] = Mama04;

static char hama01[] = Hama01;
static char hama02[] = Hama02;
static char hama03[] = Hama03;
static char hama04[] = Hama04;

static char mbro01[] = Mbro01;
static char mbro02[] = Mbro02;
static char mbro03[] = Mbro03;
static char mbro04[] = Mbro04;

static char hbro01[] = Hbro01;
static char hbro02[] = Hbro02;
static char hbro03[] = Hbro03;
static char hbro04[] = Hbro04;

static char mprj01[] = Mprj01;
static char hprj01[] = Hprj01;

static char make01[] = Make01;
static char make02[] = Make02;
static char make03[] = Make03;
static char make04[] = Make04;
static char make05[] = Make05;

static char mtfp00[] = Mtfp00;
static char mtfp01[] = Mtfp01;
static char mtfp02[] = Mtfp02;
static char mtfp03[] = Mtfp03;
static char mtfp04[] = Mtfp04;
static char mtfp05[] = Mtfp05;
static char mtfp06[] = Mtfp06;
static char mtfp07[] = Mtfp07;
static char mtfp08[] = Mtfp08;
static char mtfp09[] = Mtfp09;
static char mtfp10[] = Mtfp10;
static char mcou01[] = Mcou01;
static char mcou02[] = Mcou02;
#endif

/*	Padding pour la traduction des messages */
/*	--------------------------------------- */
                     
static char mfil10[] = Mfil10  ;
static char mfil11[] = Mfil11  ;
static char mfil12[] = Mfil12  ;
static char mfil13[] = Mfil13  ;
static char mfil14[] = Mfil14  ;
static char mfil15[] = Mfil15  ;
static char mfil16[] = Mfil16  ;
static char mfil17[] = Mfil17  ;
static char mfil18[] = Mfil18  ;
static char mfil19[] = Mfil19  ;
static char mfil20[] = Mfil20  ;
static char mfil21[] = Mfil21  ;
static char mfil22[] = Mfil22  ;
static char mfil23[] = Mfil23  ;
static char mfil24[] = Mfil24  ;
static char mfil25[] = Mfil25  ;
static char mfil26[] = Mfil26  ;
static char mfil27[] = Mfil27  ;
static char mfil28[] = Mfil28  ;
static char mfil29[] = Mfil29  ;
static char mfil30[] = Mfil30  ;
static char mfil31[] = Mfil31  ;
static char mfil32[] = Mfil32  ;
static char mfil33[] = Mfil33  ;
static char mfil34[] = Mfil34  ;
static char mfil35[] = Mfil35  ;
static char mfil36[] = Mfil36  ;
static char mfil37[] = Mfil37  ;
static char mfil38[] = Mfil38  ;
static char mfil39[] = Mfil39  ;
static char mfil40[] = Mfil40  ;
                     
/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/
                     
static char mfin[] = Mfin;


/* Zone message pour Les English */

static char oentete[] = Oentete;
static char yesno[]  = Yesno;

static char mmsgoui[]    =     MMsgoui;
static char mmsgnon[]    =     MMsgnon;
static char mmsgesc[]    =     MMsgesc;
static char mmsgcr[]     =     MMsgcr;
static char mmsgctr[]    =     MMsgctr;
static char mmsgnouval[] =     MMsgnouval;
static char mmsgprog[]   =     MMsgprog;
static char mmsgparam[]  =     MMsgparam;
static char mmsgetnom[]  =     MMsgetnom;
static char mmsgbadrun[] =      MMsgbadrun;
static char mmsgnofile[] =      MMsgnofile;
static char mmsgnomore[] =      MMsgnomore;
static char mmsgaucun[]  =     MMsgaucun;
static char mmsgplein[]  =     MMsgplein;
static char mmsgcomed[]  =     MMsgcomed;
static char mmsgfonct[]  =     MMsgfonct;
static char mmsgexcom[]  =     MMsgexcom;
static char mmsgreser[]  =     MMsgreser;
static char mmsgincfic[] =      MMsgincfic;
static char mmsgexfic[]  =     MMsgexfic;
static char mmsgnomods[] =     MMsgnomods;
                              
static char mmsgargerr[] =     MMsgargerr;
static char mmsgficerr[] =     MMsgficerr;
static char mmsgficonf[] =     MMsgficonf;

/*	messages generaux		*/
/*	-----------------		*/

static char mm00001[] = NN00001;
static char mm00002[] = NN00002;
static char mm00003[] = NN00003;
static char mm00004[] = NN00004;
static char mm00005[] = NN00005;
static char mm00006[] = NN00006;
static char mm00007[] = NN00007;
                       
/*	messages specifiques du noyau	*/
/*	-----------------------------	*/
                       
static char mm01001[] = NN01001;
static char mm01002[] = NN01002;
static char mm01003[] = NN01003;
                       
/*	messages contenus dans les menus	*/
/*	--------------------------------	*/
                       
static char mm02001[] = NN02001;
static char mm02002[] = NN02002;
static char mm02003[] = NN02003;
static char mm02004[] = NN02004;
static char mm02005[] = NN02005;
static char mm02006[] = NN02006;
static char mm02007[] = NN02007;
                       
static char mm02008[] = NN02008;
static char mm02009[] = NN02009;
                       
static char mm02010[] = NN02010;
static char mm02011[] = NN02011;
static char mm02012[] = NN02012;
static char mm02013[] = NN02013;
static char mm02014[] = NN02014;
                       
static char mm02015[] = NN02015;
static char mm02016[] = NN02016;
static char mm02017[] = NN02017;
static char mm02018[] = NN02018;
                       
static char mm02019[] = NN02019;
static char mm02020[] = NN02020;
static char mm02021[] = NN02021;
static char mm02022[] = NN02022;
static char mm02023[] = NN02023;
static char mm02024[] = NN02024;
static char mm02025[] = NN02025;
static char mm02026[] = NN02026;
static char mm02027[] = NN02027;
                       
static char mmama05[] = MMama05;
static char hhama05[] = HHama05;
                       
static char mm02030[] = NN02030;
static char mm02031[] = NN02031;
static char mm02032[] = NN02032;
static char mm02033[] = NN02033;
static char mm02034[] = NN02034;
static char mm02035[] = NN02035;
static char mm02036[] = NN02036;
                       
static char mm02037[] = NN02037;
static char mm02038[] = NN02038;
static char mm02039[] = NN02039;
static char mm02040[] = NN02040;
                       
static char mm02041[] = NN02041;
static char mm02042[] = NN02042;
static char mm02043[] = NN02043;
                       
static char mm02044[] = NN02044;
static char mm02045[] = NN02045;
static char mm02046[] = NN02046;
static char mm02047[] = NN02047;
static char mm02048[] = NN02048;
                       
static char mm02049[] = NN02049;
static char mm02050[] = NN02050;
static char mm02051[] = NN02051;
static char mm02052[] = NN02052;
static char mm02053[] = NN02053;
static char mm02054[] = NN02054;	 
static char mm02055[] = NN02055;
static char mm02056[] = NN02056;
static char mm02057[] = NN02057;
                       
/*	options de la configuration du traducteur		*/
/*	-----------------------------------------		*/
                       
static char mm03001[] = NN03001 ;
static char mm03002[] = NN03002 ;
static char mm03003[] = NN03003 ;
static char mm03004[] = NN03004 ;
static char mm03005[] = NN03005 ;
static char mm03006[] = NN03006 ;
static char mm03007[] = NN03007 ;
static char mm03008[] = NN03008 ;
static char mm03009[] = NN03009 ;
                       
/*	commandes configurables de l'editeur		*/
/*	------------------------------------		*/
                       
static char mm04001[] = NN04001; 
static char mm04002[] = NN04002; 
static char mm04003[] = NN04003;
static char mm04004[] = NN04004; 
static char mm04005[] = NN04005 ;
static char mm04006[] = NN04006 ;
static char mm04007[] = NN04007; 
static char mm04008[] = NN04008; 
static char mm04009[] = NN04009; 
static char mm04010[] = NN04010; 
static char mm04011[] = NN04011; 
static char mm04012[] = NN04012; 
static char mm04013[] = NN04013; 
static char mm04014[] = NN04014; 
static char mm04015[] = NN04015; 
static char mm04016[] = NN04016; 
static char mm04017[] = NN04017; 
static char mm04018[] = NN04018; 
                       
/* 	Touche de fonction	*/
/* 	------------------	*/
static char mm05001[] = NN05001 ;
static char mm05002[] = NN05002 ;
static char mm05003[] = NN05003 ;
static char mm05004[] = NN05004 ;
static char mm05005[] = NN05005 ;
static char mm05006[] = NN05006 ;
static char mm05007[] = NN05007 ;
static char mm05008[] = NN05008 ;
static char mm05009[] = NN05009 ;
static char mm05010[] = NN05010 ;

/*	Messages d'aide 	*/
/*	---------------		*/
static char mmsgscroll[] = MMsgscroll;
static char mm00008[]    = NN00008;
static char mmsgsrep[]   = MMsgsrep;
static char mmsgenv[]    = MMsgenv;
static char mmsgplu[]    = MMsgplu;

/*	Messages d'aide ; associes aux menus	*/
/*	---------------------------------------------	*/
static char hhelp01[] = HHelp01 ;
static char hhelp02[] = HHelp02 ;
static char hhelp03[] = HHelp03 ;
static char hhelp04[] = HHelp04 ;
static char hhelp05[] = HHelp05 ;
static char hhelp06[] = HHelp06 ;
                       
static char hhelp07[] = HHelp07 ;
static char hhelp08[] = HHelp08 ;
static char hhelp09[] = HHelp09 ;
static char hhelp10[] = HHelp10 ;
static char hhelp11[] = HHelp11 ;
                       
static char hhelp12[] = HHelp12 ;
static char hhelp13[] = HHelp13 ;
static char hhelp14[] = HHelp14 ;
static char hhelp15[] = HHelp15 ;
                       
static char hhelp16[] = HHelp16 ;
static char hhelp17[] = HHelp17 ;
static char hhelp18[] = HHelp18 ;
                       
static char hhelp19[] = HHelp19 ;
static char hhelp20[] = HHelp20 ;
static char hhelp21[] = HHelp21 ;
static char hhelp22[] = HHelp22 ;
static char hhelp23[] = HHelp23 ;
static char hhelp24[] = HHelp24 ;
static char hhelp25[] = HHelp25 ;
static char hhelp26[] = HHelp26 ;
static char hhelp27[] = HHelp27 ;
                       
static char hhelp28[] = HHelp28 ;
static char hhelp29[] = HHelp29 ;
static char hhelp30[] = HHelp30 ;
static char hhelp31[] = HHelp31 ;
static char hhelp32[] = HHelp32 ;
static char hhelp33[] = HHelp33 ;
static char hhelp34[] = HHelp34 ;
static char hhelp35[] = HHelp35 ;
static char hhelp36[] = HHelp36 ;
static char hhelp37[] = HHelp37 ;
static char hhelp38[] = HHelp38 ;
static char hhelp39[] = HHelp39 ;
                       
/*	Messages d'aide ; associes aux menus	*/
/*	---------------------------------------------	*/
/*	options de configuration */
                       
static char mm06000[] = NN06000 ;
static char mm06001[] = NN06001 ;
static char mm06002[] = NN06002 ;
static char mm06003[] = NN06003 ;
static char mm06004[] = NN06004 ;
static char mm06005[] = NN06005 ;
                       
static char hhelp40[] = HHelp40 ;
static char hhelp41[] = HHelp41 ;
static char hhelp42[] = HHelp42 ;
static char hhelp43[] = HHelp43 ;
static char hhelp44[] = HHelp44 ;
static char hhelp45[] = HHelp45 ;
                       
static char hhelp46[] = HHelp46 ;
static char hhelp47[] = HHelp47 ;
static char hhelp48[] = HHelp48 ;
static char hhelp49[] = HHelp49 ;
static char hhelp50[] = HHelp50 ;
static char hhelp51[] = HHelp51 ;
static char hhelp52[] = HHelp52 ;
static char hhelp53[] = HHelp53 ;
static char hhelp54[] = HHelp54 ;
static char hhelp55[] = HHelp55 ;
                       
/*	Libelle extention */
static char mm07001[] = NN07001 ;
static char mm07002[] = NN07002 ;
static char mm07003[] = NN07003 ;
static char mm07004[] = NN07004 ;
static char mm07005[] = NN07005 ;
                       
/*	Libelle Repertoires */
static char mm07100[] = NN07100 ;
static char mm07101[] = NN07101 ;
static char mm07102[] = NN07102 ;
static char mm07103[] = NN07103 ;
static char mm07104[] = NN07104 ;
                       
/* 	Pour le nom de projet par defaut */
static char mm07200[] = NN07200 ;
static char hhelp56[] = HHelp56 ;
                       
/* 	Add menu traduction */
/* 	------------------- */
static char mm03000[] = NN03000 ;
static char mm03010[] = NN03010 ;
                       
                       
/*	hhelp des extentions et des repertoires 		*/
/*	--------------------------------------		*/

/*	Libelle extention */
static char hhepl57[] = HHepl57 ;
static char hhelp58[] = HHelp58 ;
static char hhelp59[] = HHelp59 ;
static char hhelp60[] = HHelp60 ;
static char hhelp61[] = HHelp61 ;
                       
/*	Libelle Repertoires */
static char hhelp62[] = HHelp62 ;
static char hhelp63[] = HHelp63 ;
static char hhelp64[] = HHelp64 ;
static char hhelp65[] = HHelp65 ;
static char hhelp66[] = HHelp66 ;
                       
/*	HHelp sur les options editeur	*/
/*	----------------------------	*/
static char hhelp67[] = HHelp67 ;	/* pour les hhelp vides */
static char hhelp68[] = HHelp68 ;
static char hhelp69[] = HHelp69 ;
static char hhelp70[] = HHelp70 ;
static char hhelp71[] = HHelp71 ;
                       
static char nnotfind[] =NNotfind ;
                       
/*-----------------*/
/* noms des listes */
/*-----------------*/
static char llstfic[] = LLstfic ;
static char llstrep[] = LLstrep ;
static char llstsrc[] = LLstsrc ;
static char llstprj[] = LLstprj ;
static char llsttra[] = LLsttra ;
static char llstsys[] = LLstsys ;
                       
static char llibpau[] = LLibpau ;
static char nnosrc[]  = NNosrc  ;
static char nnotra[]  = NNotra  ;
static char nnomod[]  = NNomod  ;
static char wwarni[]  = WWarni  ;
static char sselec[]  = SSelec  ;
static char ttmpcfg[] = TTmpcfg ;
                       
#ifdef ver21
static char sskimsg[] = SSkimsg ;
static char sskihlp[] = SSkihlp ;

static char ppbrows[] = PPbrows;
static char hhbrows[] = HHbrows;
static char ooptobj[] = OOptobj;
static char hhoptob[] = HHptobj;
static char llclass[] = LLclass;
static char hhclass[] = HHclass;

static char mmobj01[] = MMobj01;
static char mmobj02[] = MMobj02;
static char mmobj03[] = MMobj03;
                   
static char hhobj01[] = HHobj01;
static char hhobj02[] = HHobj02;
static char hhobj03[] = HHobj03;
                   
static char mmobj12[] = MMobj12;
static char mmobj13[] = MMobj13;
static char mmobj14[] = MMobj14;
static char mmobj15[] = MMobj15;
static char mmobj16[] = MMobj16;
static char mmobj17[] = MMobj17;
static char mmobj18[] = MMobj18;
static char mmobj19[] = MMobj19;
static char mmobj20[] = MMobj20;
                   
static char hhobj12[] = HHobj12;
static char hhobj13[] = HHobj13;
static char hhobj14[] = HHobj14;
static char hhobj15[] = HHobj15;
static char hhobj16[] = HHobj16;
static char hhobj17[] = HHobj17;
static char hhobj18[] = HHobj18;
static char hhobj19[] = HHobj19;
static char hhobj20[] = HHobj20;
                   
static char mmobj21[] = MMobj21;
static char hhobj21[] = HHobj21;

static char mmobj22[] = MMobj22;
static char mmobj23[] = MMobj23;
static char hhobj22[] = HHobj22;
static char hhobj23[] = HHobj23;
                   
static char mmobj24[] = MMobj24;
static char mmobj25[] = MMobj25;
static char hhobj24[] = HHobj24;
static char hhobj25[] = HHobj25;

static char mmobj26[] = MMobj26;
static char mmobj27[] = MMobj27;
static char mmobj28[] = MMobj28;
static char mmobj29[] = MMobj29;
static char mmobj30[] = MMobj30;
static char mmobj31[] = MMobj31;
static char mmobj32[] = HHobj32;
static char mmobj33[] = HHobj33;

static char hhobj26[] = HHobj26;
static char hhobj27[] = HHobj27;
static char hhobj28[] = HHobj28;
static char hhobj29[] = HHobj29;
static char hhobj30[] = HHobj30;
static char hhobj31[] = HHobj31;
static char hhobj32[] = HHobj32;
static char hhobj33[] = HHobj33;
                   
static char mmobj34[] = MMobj34;
static char mmobj35[] = MMobj35;
static char mmobj36[] = MMobj36;
static char mmobj37[] = MMobj37;
static char mmobj38[] = MMobj38;
static char mmobj39[] = MMobj39;
static char mmobj40[] = MMobj40;
static char mmobj41[] = MMobj41;
static char mmobj42[] = MMobj42;
static char mmobj43[] = MMobj43;
                   
static char hhobj34[] = HHobj34;
static char hhobj35[] = HHobj35;
static char hhobj36[] = HHobj36;
static char hhobj37[] = HHobj37;
static char hhobj38[] = HHobj38;
static char hhobj39[] = HHobj39;
static char hhobj40[] = HHobj40;
static char hhobj41[] = HHobj41;
static char hhobj42[] = HHobj42;
static char hhobj43[] = HHobj43;
                   
static char mmobj44[] = MMobj44;
static char mmobj45[] = MMobj45;
static char mmobj46[] = MMobj46;
static char mmobj47[] = MMobj47;

static char hhobj44[] = HHobj44;
static char hhobj45[] = HHobj45;
static char hhobj46[] = HHobj46;
static char hhobj47[] = HHobj47;

static char mmald01[] = MMald01;
static char mmald02[] = MMald02;
static char hhald01[] = HHald01;
static char hhald02[] = HHald02;
                   
static char mmobj50[] = MMobj50;
static char mmobj51[] = MMobj51;
static char mmobj52[] = MMobj52;
static char mmobj53[] = MMobj53;
                   
static char hhobj50[] = HHobj50;
static char hhobj51[] = HHobj51;
static char hhobj52[] = HHobj52;
static char hhobj53[] = HHobj53;
                   
static char mmama01[] = Mama01;
static char mmama02[] = Mama02;
static char mmama03[] = Mama03;
static char mmama04[] = Mama04;

static char hhama01[] = HHama01;
static char hhama02[] = HHama02;
static char hhama03[] = HHama03;
static char hhama04[] = HHama04;

static char mmbro01[] = MMbro01;
static char mmbro02[] = MMbro02;
static char mmbro03[] = MMbro03;
static char mmbro04[] = MMbro04;

static char hhbro01[] = HHbro01;
static char hhbro02[] = HHbro02;
static char hhbro03[] = HHbro03;
static char hhbro04[] = HHbro04;

static char mmprj01[] = MMprj01;
static char hhprj01[] = HHprj01;

static char mmake01[] = MMake01;
static char mmake02[] = MMake02;
static char mmake03[] = MMake03;
static char mmake04[] = MMake04;
static char mmake05[] = MMake05;

static char mmtfp00[] = MMtfp00;
static char mmtfp01[] = MMtfp01;
static char mmtfp02[] = MMtfp02;
static char mmtfp03[] = MMtfp03;
static char mmtfp04[] = MMtfp04;
static char mmtfp05[] = MMtfp05;
static char mmtfp06[] = MMtfp06;
static char mmtfp07[] = MMtfp07;
static char mmtfp08[] = MMtfp08;
static char mmtfp09[] = MMtfp09;
static char mmtfp10[] = MMtfp10;
static char mmcou01[] = MMcou01;
static char mmcou02[] = MMcou02;
#endif

/*	Padding pour la traduction desmmessages */
/*	--------------------------------------- */
                     
static char mmfil10[] = Mfil10  ;
static char mmfil11[] = Mfil11  ;
static char mmfil12[] = Mfil12  ;
static char mmfil13[] = Mfil13  ;
static char mmfil14[] = Mfil14  ;
static char mmfil15[] = Mfil15  ;
static char mmfil16[] = Mfil16  ;
static char mmfil17[] = Mfil17  ;
static char mmfil18[] = Mfil18  ;
static char mmfil19[] = Mfil19  ;
static char mmfil20[] = Mfil20  ;
static char mmfil21[] = Mfil21  ;
static char mmfil22[] = Mfil22  ;
static char mmfil23[] = Mfil23  ;
static char mmfil24[] = Mfil24  ;
static char mmfil25[] = Mfil25  ;
static char mmfil26[] = Mfil26  ;
static char mmfil27[] = Mfil27  ;
static char mmfil28[] = Mfil28  ;
static char mmfil29[] = Mfil29  ;
static char mmfil30[] = Mfil30  ;
static char mmfil31[] = Mfil31  ;
static char mmfil32[] = Mfil32  ;
static char mmfil33[] = Mfil33  ;
static char mmfil34[] = Mfil34  ;
static char mmfil35[] = Mfil35  ;
static char mmfil36[] = Mfil36  ;
static char mmfil37[] = Mfil37  ;
static char mmfil38[] = Mfil38  ;
static char mmfil39[] = Mfil39  ;
static char mmfil40[] = Mfil40  ;
                     
/*	Fin pour utilitaire de traduction	*/
/*	---------------------------------	*/
                     
static char mmfin[] = Mfin;

#endif /* HHX */

/*		Definition des numeros demmessages		*/
/*		----------------------------------		*/

#define MSGoui	0
#define MSGnon	1
#define MSGesc 	2
#define MSGcr	3
#define MSGctr	4
#define MSGnouval 5
#define MSGprog	 6
#define MSGparam 7
#define MSGetnom 8
#define MSGbadrun 9
#define MSGnofile 10
#define MSGnomore 11
#define MSGaucun 12
#define MSGplein 13
#define MSGcomed 14
#define MSGfonct 15
#define MSGexcom 16
#define MSGreser 17
#define MSGincfic 18
#define MSGexfic 19
#define MSGnomods 20
#define MSGargerr 21
#define MSGficerr 22
#define MSGficonf 23
#define M00001 	24
#define M00002 	25
#define M00003	26
#define M00004	27
#define M00005	28
#define M00006	29
#define M00007	30
#define M01001	31
#define M01002	32
#define M01003	33
#define M02001	34
#define M02002	35
#define M02003	36
#define M02004	37
#define M02005	38
#define M02006	39
#define M02007	40
#define M02008	41
#define M02009	42
#define M02010	43
#define M02011	44
#define M02012	45
#define M02013	46
#define M02014	47
#define M02015	48
#define M02016	49
#define M02017	50
#define M02018	51
#define M02019	52
#define M02020	53
#define M02021	54
#define M02022	55
#define M02023	56
#define M02024	57
#define M02025	58
#define M02026	59
#define M02027	60
#define MAMA05	61  
#define HAMA05	62
#define M02030	63
#define M02031	64
#define M02032	65
#define M02033	66
#define M02034	67
#define M02035	68
#define M02036	69
#define M02037	70
#define M02038	71
#define M02039	72
#define M02040	73
#define M02041	74
#define M02042	75
#define M02043	76
#define M02044	77
#define M02045	78
#define M02046  79
#define M02047  80
#define M02048  81
#define M02049  82
#define M02050  83
#define M02051  84
#define M02052  85
#define M02053  86
#define M02054  87
#define M02055  88
#define M02056  89
#define M02057  90

#define M03001	91
#define M03002	92

#define M03003	93
#define M03004	94
#define M03005	95
#define M03006	96
#define M03007	97
#define M03008	98
#define M03009	99
#define M04001	100
#define M04002	101
#define M04003	102
#define M04004	103
#define M04005	104
#define M04006	105
#define M04007	106
#define M04008	107
#define M04009	108
#define M04010	109
#define M04011	110
#define M04012	111
#define M04013	112
#define M04014	113
#define M04015	114
#define M04016	115
#define M04017	116
#define M04018	117
#define M05001	118
#define M05002	119
#define M05003	120
#define M05004	121
#define M05005	122
#define M05006	123
#define M05007	124
#define M05008	125
#define M05009	126
#define M05010	127


#define MSGscr  128
#define M00008	129	/* Rajout de Version */
#define MSGsrep 130
#define	Plupla	132

/*	Messages daide	*/
/*	--------------	*/
#define HELP01	133
#define HELP02  134
#define HELP03	135
#define HELP04	136
#define HELP05  137
#define HELP06	138
#define HELP07	139
#define HELP08	140
#define HELP09	141
#define HELP10	142
#define HELP11	143
#define HELP12	144
#define HELP13	145
#define HELP14	146
#define HELP15	147
#define HELP16	148
#define HELP17	149
#define HELP18	150
#define HELP19	151
#define HELP20	152
#define HELP21 	153
#define HELP22	154
#define HELP23	155
#define HELP24	156
#define HELP25	157
#define HELP26	158
#define HELP27	159
#define HELP28	160
#define HELP29	161
#define HELP30	162
#define HELP31	163
#define HELP32	164
#define HELP33	165
#define HELP34	166
#define HELP35	167
#define HELP36	168
#define HELP37	169
#define HELP38  170
#define HELP39  171 

#define M06000  172
#define M06001	173
#define M06002  174
#define M06003	175
#define M06004	176
#define M06005	177
#define HELP40	178
#define HELP41	179
#define HELP42 	180
#define HELP43	181
#define HELP44	182
#define HELP45  183
#define HELP46	184
#define HELP47	185
#define HELP48	186
#define HELP49	187
#define HELP50	188
#define HELP51	189
#define HELP52	190
#define HELP53	191
#define HELP54	192
#define HELP55  193

#define M07001	194
#define M07002  195
#define M07003  196
#define M07004	197
#define M07005	198

#define M07101	199
#define M07102  200
#define M07103  201
#define M07104	202
#define M07105	203
#define M07200  204
#define HELP56  205

#define M03000  206
#define M03010  207

#define HELP57  208
#define HELP58  209
#define HELP59  210
#define HELP60  211
#define HELP61  212
#define HELP62  213
#define HELP63  214
#define HELP64  215
#define HELP65  216
#define HELP66	217
#define HELP67  218
#define HELP68  219
#define HELP69  220
#define HELP70  221
#define HELP71  222
#define NOTFIND 223

#define LSTFIC  224
#define LSTREP  225
#define LSTSRC  226
#define LSTPRJ  227
#define LSTTRA  228
#define LSTSYS  229
#define LIBPAU  230

#define NOSRC 231
#define NOTRA 232
#define NOMOD 233
#define WARNI 234
#define SELEC 235
#define CFGTM 236

#ifdef ver21

#define SKIPM 237
#define SKIPH 238
#define PBROWS 239
#define HBROWS 240
#define OPTOBJ 241
#define HOPTOB 242
#define LCLASS 243
#define HCLASS 244

#define MOBJ01 245
#define MOBJ02 246
#define MOBJ03 247

#define HOBJ01 248
#define HOBJ02 249
#define HOBJ03 250
       
#define MOBJ12 251
#define MOBJ13 252
#define MOBJ14 253
#define MOBJ15 254
#define MOBJ16 255
#define MOBJ17 256
#define MOBJ18 257
#define MOBJ19 258
#define MOBJ20 259
      
#define HOBJ12 260
#define HOBJ13 261
#define HOBJ14 262
#define HOBJ15 263
#define HOBJ16 264
#define HOBJ17 265
#define HOBJ18 266
#define HOBJ19 267
#define HOBJ20 268
      

#define MOBJ21 269
#define HOBJ21 270

#define MOBJ22 271
#define MOBJ23 272

#define HOBJ22 273
#define HOBJ23 274
      
#define MOBJ24 275
#define MOBJ25 276
#define HOBJ24 277
#define HOBJ25 278

#define MOBJ26 279
#define MOBJ27 280
#define MOBJ28 281
#define MOBJ29 282
#define MOBJ30 283
#define MOBJ31 284
#define MOBJ32 285
#define MOBJ33 286

#define HOBJ26 287
#define HOBJ27 288
#define HOBJ28 289
#define HOBJ29 290
#define HOBJ30 291
#define HOBJ31 292
#define HOBJ32 293
#define HOBJ33 294
      
#define MOBJ34 295
#define MOBJ35 296
#define MOBJ36 297
#define MOBJ37 298
#define MOBJ38 299
#define MOBJ39 300
#define MOBJ40 301
#define MOBJ41 302
#define MOBJ42 303
#define MOBJ43 304
       
#define HOBJ34 305
#define HOBJ35 306
#define HOBJ36 307
#define HOBJ37 308 
#define HOBJ38 309
#define HOBJ39 310
#define HOBJ40 311
#define HOBJ41 312
#define HOBJ42 313
#define HOBJ43 314
      
#define MOBJ44 315
#define MOBJ45 316
#define MOBJ46 317
#define MOBJ47 318

#define HOBJ44 319
#define HOBJ45 320
#define HOBJ46 321
#define HOBJ47 322

#define MALD01 323
#define MALD02 324
#define HALD01 325
#define HALD02 326

#define MOBJ50 327
#define MOBJ51 328
#define MOBJ52 329
#define MOBJ53 330

#define HOBJ50 331
#define HOBJ51 332
#define HOBJ52 333
#define HOBJ53 334

#define MAMA01 335
#define MAMA02 336
#define MAMA03 337
#define MAMA04 338

#define HAMA01 339
#define HAMA02 340
#define HAMA03 341
#define HAMA04 342 

#define MBRO01 343
#define MBRO02 344 
#define MBRO03 345
#define MBRO04 346

#define HBRO01 347
#define HBRO02 348
#define HBRO03 349
#define HBRO04 350

#define MPRJ01 351
#define HPRJ01 352

#define MAKE01 353
#define MAKE02 354
#define MAKE03 355
#define MAKE04 356
#define MAKE05 357

#define MTFP00 358
#define MTFP01 359
#define MTFP02 360
#define MTFP03 361
#define MTFP04 362
#define MTFP05 363
#define MTFP06 364
#define MTFP07 365
#define MTFP08 366
#define MTFP09 367
#define MTFP10 368
#define MCOU01 369
#define MCOU02 370

#define M07201  371
#define HELP99  372

#else

#define M07201  237
#define HELP99  238

#endif



/*	Designation desmmessages pour lesmmodules utilisateurs		*/
/*	------------------------------------------------------		*/

/*	messages generaux		*/
/*	-----------------		*/

static int titre 	= 0;	/* titre dummodule */
static int msgprj	= 1;	/* Projet  courant */
static int msgfic	= 2;	/* Fichier courant : */
static int msgwait	= 3;	/* Appuyez sur une touche pour continuer */
static int bid001	= 4;	/* *libre* */
static int msgsel	= 5;	/*  Nouveau fichier courant : */
static int msgdes	= 6;	/*  Designation : */

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

static int ernoy01	= 7;	/* Debordement capacitemmemoire */
static int ernoy02	= 8;	/* Erreur : pas de fichier courant */
static int msgseg	= 9;	/* Segment : */
static int vers		= 10;	/* Version */

/*	definition des menus	*/
/*	--------------------	*/

	/* definition des caracteres semi graphiques (norme Prologue) */

#ifndef vms

static BYTE C_CHG =	(BYTE) 0x00DA;	/* coin hhaut et gauche */
static BYTE C_LNH =	(BYTE) 0x00C4;	/* ligne hhorizontale */
static BYTE C_CHD =	(BYTE) 0x00BF;	/* coin hhaut et droit */
static BYTE C_CBG =	(BYTE) 0x00C0;	/* coin bas et gauche */
static BYTE C_CBD =	(BYTE) 0x00D9;	/* coin bas et droit */
static BYTE C_LNV =	(BYTE) 0x00B3;	/* ligne verticale */

#else
static BOOL slachP = 0; /* Bool  pour les vt... */

static BYTE C_CHG = (BYTE) 0x00F0;	/* coin hhaut et gauche */
static BYTE C_LNH =	(BYTE) 0x00BE;	/* ligne hhorizontale */
static BYTE C_CHD =	(BYTE) 0x00A4;	/* coin hhaut et droit */
static BYTE C_CBG =	(BYTE) 0x00AD;	/* coin bas et gauche */
static BYTE C_CBD =	(BYTE) 0x00DE;	/* coin bas et droit */
static BYTE C_LNV = (BYTE) 0x00A6;	/* ligne verticale */

#endif


	/* options du menu de traduction */

static BINAIRE coptrad;

	/* definition des segments a traduire si traduction partielle */

#define MXSEGTP 12
/* global */ BINAIRE Tp_NbSeg; Tp_Tseg[MXSEGTP];

	/* options dummenu dummoniteur */

static char Largu[50];	/* Argument */
static BINAIRE coptmon;

	/* option plein ecran systeme */
static BOOL coptsys;
static int strsys[] =  { M07200, M07201 };
static int htrsys[] =  { HELP67, HELP99 };
static BOOL vsysopt[2];

	/* options dummenu d'edition */

static BINAIRE coptedit;

	/* options dummenu des utilitaires */

static BINAIRE coptutil;

	/* options dummenu de configuration */

static BINAIRE coptconf;

	/* options dummenu de configuration du traducteur */

static BINAIRE coptcftr;

static BINAIRE coptdefs;

	/* options de traduction */

static BINAIRE coptoptr;
static BOOL vtropt[11];

	/*mmenu de configuration des types des fichiers */

static BINAIRE coptcfic;

	/*mmenu de selection des repertoires de travail */

static BINAIRE coptcfrep;

#define MAXSYMB 9
#define LGIDENT 9

static int nbpredef;
static char XPTR predef[MAXSYMB];

	/*mmenu de configuration de l'editeur de textes */

static BINAIRE coptcfed;

static BINAIRE coptcmed;

static BOOL efface;		/* Booleen pour eviter atb(22) dans cadre() */

#ifdef vms
#define SEPREP 0		/* Le delimiteur de repertoire est inclus */
#else
#define SEPREP 1
#endif

/* 	Touches de fonction	*/
/*	-------------------     */

#define VEOF 0x001A
#define LGTFP 33
static BINAIRE ctfp;
		/* Libelle des touches de fonction de l'integre */

static BYTE ltf1[LGTFP];
static BYTE ltf2[LGTFP];
static BYTE ltf3[LGTFP];
static BYTE ltf4[LGTFP];
static BYTE ltf5[LGTFP];
static BYTE ltf6[LGTFP];
static BYTE ltf7[LGTFP];
static BYTE ltf8[LGTFP];
static BYTE ltf9[LGTFP];
static BYTE ltf10[LGTFP];

static BYTE XPTR pltfp [] = { &ltf1[0], &ltf2[0], &ltf3[0], &ltf4[0], &ltf5[0],
			 &ltf6[0], &ltf7[0], &ltf8[0], &ltf9[0], &ltf10[0]
};


		/* Libelle des touches de fonction de AED */
static BINAIRE ectfp;

static BYTE eltf1[LGTFP];
static BYTE eltf2[LGTFP];
static BYTE eltf3[LGTFP];
static BYTE eltf4[LGTFP];
static BYTE eltf5[LGTFP];
static BYTE eltf6[LGTFP];
static BYTE eltf7[LGTFP];
static BYTE eltf8[LGTFP];
static BYTE eltf9[LGTFP];
static BYTE eltf10[LGTFP];

static BYTE XPTR epltfp[] = { &eltf1[0], &eltf2[0], &eltf3[0], &eltf4[0], &eltf5[0],
			 &eltf6[0], &eltf7[0], &eltf8[0], &eltf9[0], &eltf10[0]
};
		/* Sauvegarde des touches de fonction */

#ifdef prologue
static BYTE sltf1[LGTFP];
static BYTE sltf2[LGTFP];
static BYTE sltf3[LGTFP];
static BYTE sltf4[LGTFP];
static BYTE sltf5[LGTFP];
static BYTE sltf6[LGTFP];
static BYTE sltf7[LGTFP];
static BYTE sltf8[LGTFP];
static BYTE sltf9[LGTFP];
static BYTE sltf10[LGTFP];

static BYTE XPTR pstfp[] = { &sltf1[0], &sltf2[0], &sltf3[0], &sltf4[0], &sltf5[0],
			 &sltf6[0], &sltf7[0], &sltf8[0], &sltf9[0], &sltf10[0]
};

#endif

	/*	definitions pour l'acces aux commandes d'edition	*/

/* global */ BYTE vcomed[18];
	     BYTE ypadding[256];
/* global */ BYTE ESCAPE,CURD,CURG,CURH,CURB;
/* global */ BYTE CTRLB, CTRLH;
	     BYTE xpadding[256];

#define	PHOME	vcomed[0]
#define	PDEBFIN	vcomed[1]
#define	PGDN	vcomed[2]
#define	PGUP	vcomed[3]
#define	CENTER	vcomed[4]
#define	NEXTWORD vcomed[5]
#define	PREVWORD vcomed[6]
#define	ILINE	vcomed[7]
#define	DLINE	vcomed[8]
#define	DELCAR	vcomed[9]
#define	DELBACK vcomed[10]
#define	DEOLN	vcomed[11]
#define	DBOLN	vcomed[12]
#define	UNDEL	vcomed[13]
#define	INSERT	vcomed[14]
#define	INDENT	vcomed[15]
#define	NUMLN	vcomed[16]
#define	NEXTERR	vcomed[17]

static BINAIRE lg_tab;	/* longueur tabulation pour editeur */

static BYTE SAVCURD[32], SAVCURG[32], SAVCURB[32], SAVCURH[32];
static BYTE T7F;
static BYTE ST7F[32];

BOOL    boolESC;
#define CTRLC 0x0006

/*	Affichage des messages d'aide en permanence oui/non	*/
/*	---------------------------------------------------	*/

BOOL	flg_help;

/*	Nouvelle definition des menus pour GESMES		*/
/*	-----------------------------------------		*/

/*		Definition de la table des messages		*/
/*	$$	-----------------------------------		*/


#define NBINTMES 374


static char XPTR inte_msg[NBINTMES];
 
/*	messages generaux		*/
/*	-----------------		*/

static int messages[] = {

 M00001,  M00002,  M00003,  M00004,  M00005,
 M00006,  M00007,  M01001,  M01002,  M01003,
 M00008
};

	/* options du menu general */

static int cogene;
static int ogene[] = { M02001, M02002, M02003, M02004,
			 M02005, M02006, M02007 };
static int hgene[] = { HELP01, HELP02, HELP03, HELP04,
			 HELP05, HELP06, HELP39 };

	/* options projet */
static int coprojet;
static int oprojet[] = { M02010, M02011, MPRJ01, M02012, M02013, M02014 };
static int hprojet[] = { HELP07, HELP08, HPRJ01, HELP09, HELP10, HELP11 };

	/* options du menu d'edition */

static int coedit;
static int oedit[] = { M02015, M02016, M02017, M02018 };
static int hedit[] = { HELP68, HELP69, HELP70, HELP71 };
static BOOL vaedopt[4]; /* reponse oui/non */

	/* options generation */
static int cogener;
static int ogener[] = { M02037/*#BG, MOBJ44*/, M02038, M02039/*#BG, MOBJ45*/, MOBJ46, M02040, MOBJ47 };
static int hgener[] = { HELP12/*#BG, HOBJ44*/, HELP13, HELP14/*#BG, HOBJ45*/, HOBJ46, HELP15, HOBJ47 };
	
	/* options execution */
static int coexec;
static int oexec[] = { M02041, M02042, M02043 };
static int hexec[] = { HELP16, HELP17, HELP18 };

	/* options utilitaires */
static int coutil;
static int outil[] = { M02050, M02051, M02052, M02053, M02054/*#BG,
		   	M02055, M02056*/, PBROWS, M02057 };
static int hutil[] = { HELP20, HELP21, HELP22, HELP23, HELP24/*#BG,
			HELP25, HELP26*/, HBROWS, HELP27 };

#ifdef ver21
static int outil2[] = { M02050, M02051, M02052, M02053, M02054/*#BG,
		   	M02055, M02056*/, PBROWS, M02057/*#BG, SKIPM*/ };

static int hutil2[] = { HELP20, HELP21, HELP22, HELP23, HELP24/*#BG,
			HELP25, HELP26*/, HBROWS, HELP27/*#BG, SKIPH*/ };
#endif

	/* options de configuration */
static int coconf;
static int oconf[] = { M02019, M02021/*#BG, MOBJ24*/, M02020, /*MOBJ25,*/
			M02022, M02023, M02025, M02026, M02027 };

static int hconf[] = { HELP28, HELP30/*#BG, HOBJ24*/, HELP29, /*HOBJ25,*/ 
			HELP31, HELP32, HELP34, HELP35, HELP36 };
	/* options fin */
static int cofin;
static int ofin [] = { M02008, M02009 };
static int hfin [] = { HELP37, HELP38 };


	/* options du menu de configuration du traducteur */

static int ocftr [] = { M06000, M06001 };
static int hcftr [] = { HELP40, HELP41 };

static int oclajm [] = { M06002 };
static int hclajm [] = { HELP42 };

	/* options de traduction */

static int stropt [] = {  /*#BGM03007,*/ M03002, M03003, M03004, M03005,
		  M03006, M03001, M03008, M03010, M03009/*#BG, M03000*/
};

static int htropt [] = { /*#BGHELP67,*/ HELP67, HELP67, HELP67, HELP67,
	  HELP67, HELP67, HELP67, HELP67, HELP67/*#BG, HELP67*/
};

	/* menu de configuration de l'editeur de texte */

static int ocfedit [] = { M06003, M06004, M06005};
static int hcfedit [] = { HELP43, HELP44, HELP45};

static int ocfcmed[18] = { M04001, M04002, M04003, M04004,
			     M04005, M04006, M04007, M04008,
			     M04009, M04010, M04011, M04012,
			     M04013, M04014, M04015, M04016,
			     M04017, M04018
};

/* 	touches de fonction	*/
/*	-------------------     */

static int vtfp [] = { M05001, M05002, M05003, M05004,
			M05005, M05006, M05007, M05008,
			M05009, M05010
};
static int htfp [] = { HELP46, HELP47, HELP48, HELP49,
			HELP50, HELP51, HELP52, HELP53,
			HELP54, HELP55
};

/* Liste des extentions */
/* -------------------- */

static int lext [] = { M07001, M07002, M07003, M07004, M07005 };
static int hext [] = { HELP57, HELP58, HELP59, HELP60, HELP61 };

/* Liste des repertoires */
/* --------------------- */
#ifdef ver21
static int lrep [] = { M07101, M07102, M07103, M07104, M07105/*#BG, SKIPM*/ };
static int hrep [] = { HELP62, HELP63, HELP64, HELP65, HELP66/*#BG, SKIPH*/ };
#else
static int lrep [] = { M07101, M07102, M07103, M07104, M07105 };
static int hrep [] = { HELP62, HELP63, HELP64, HELP65, HELP66 };
#endif

#ifdef ver21

static int laplus [] = { MOBJ01, MOBJ02 };
static int haplus [] = { HOBJ01, HOBJ02 };
static int eaplus;

static int lacti[] = { MOBJ12, MOBJ13, MOBJ14, MOBJ21, MOBJ15, MOBJ16, MOBJ17, MOBJ18, MOBJ19, MOBJ20 };
static int hacti[] = { HOBJ12, HOBJ13, HOBJ14, HOBJ21, HOBJ15, HOBJ16, HOBJ17, HOBJ18, HOBJ19, HOBJ20 };
static BOOL vacti[10]; /* reponse oui/non */
static int eacti;

static int lfich[] = { MOBJ19, MOBJ20, MOBJ21, MOBJ22, MOBJ23 };
static int hfich[] = { HOBJ19, HOBJ20, HOBJ21, HOBJ22, HOBJ23 };
static int efich;
static BOOL vfich[5]; /* reponse oui/non */

static int lopti[] = { MOBJ24, MOBJ25, MOBJ26, MOBJ27, MOBJ28, MOBJ29, MOBJ30, MOBJ31, MOBJ32, MOBJ33 };
static int hopti[] = { HOBJ24, HOBJ25, HOBJ26, HOBJ27, HOBJ28, HOBJ29, HOBJ30, HOBJ31, HOBJ32, HOBJ33 };
static BOOL vopti[10]; /* reponse oui/non */

static int lcon[] = { MOBJ34, MOBJ35, MOBJ36, MOBJ37, MOBJ38 };
static int hcon[] = { HOBJ34, HOBJ35, HOBJ36, HOBJ37, HOBJ38 };

		/* Configuration d'APLUS */

static BYTE swapunit[LGREP];
static BINAIRE eobjp;

static BYTE eobj1[LGREP];
static BYTE eobj2[LGREP];
static BYTE eobj3[LGREP];
static BYTE eobj4[LGREP];
static BYTE eobj5[LGREP];
static BYTE eobj6[LGREP];
static BYTE eobj7[LGREP];
static BYTE eobj8[LGREP];
static BYTE eobj9[LGREP];
static BYTE eobj10[LGREP];

static BYTE XPTR epobjp[] = { &eobj1[0], &eobj2[0], &eobj3[0], &eobj4[0], &eobj5[0] 
};

/* options ALD */
static int coptald;
static int clocoptald;
static int loptald[] = { MALD01 };
static int hoptald[] = { HALD01 };

static BOOL voptald[1]; /* reponse oui/non */
static BOOL locoptald[1];

/* options AO */
static int coptao;
static int clocoptao;
static int loptao[] = { MOBJ50, MOBJ51, MOBJ52, MOBJ53 };
static int hoptao[] = { HOBJ50, HOBJ51, HOBJ52, HOBJ53 };

static BOOL voptao[4]; /* reponse oui/non */
static BOOL locoptao[4];

/* options amake */

static int coptam;
static int loptam[] = { MAMA01, MAMA02, MAMA03, MAMA04, MAMA05 };
static int hoptam[] = { HAMA01, HAMA02, HAMA03, HAMA04, HAMA05 };
static BOOL voptam[5];

/* options browse */
static int coptbr;
static int loptbr[] = { MBRO01, MBRO02, MBRO03, MBRO04 };
static int hoptbr[] = { HBRO01, HBRO02, HBRO03, HBRO04 };
static BOOL voptbr[4];
static BYTE argbrowse[LGARGU];

/* valeur des touches de fonction */
static int msg_tfp[] = { MTFP00, MTFP01, MTFP02, MTFP03, MTFP04,
			MTFP05, MTFP06, MTFP07, MTFP08, MTFP09 };

#endif

/*	----------------------------------	*/
/*	prototypes des fonctions dummodule	*/
/*	----------------------------------	*/

#ifdef LINT_ARGS

int main (int,char **);

static void initabmes(void);
static BOOL init (void);
static BOOL definit (void);
static void initscreen (void);
static void final (void);
static void finscreen (void);
static void banniere (void);
static int  pause(void);
static void attendre (void);
static void menugene (void);
static void entete (void);
static void affnomfic (void);
static void affnomprj (void);
static BINAIRE  hmenu (BOOL,BINAIRE,int [],int []);
static char selopt( BYTE XPTR );
static int arreter (void);
static int selection (void);
static void getmods (BINAIRE,BINAIRE,BINAIRE);
static int catalog (char XPTR);
static int edition (void);
static int traduction (BOOL [] , BYTE XPTR);
/* #BGstatic int aplus( BOOL [], BOOL [], BOOL [], BYTE XPTR );*/
static int ao (BOOL [] , BYTE XPTR);
static int getnseg (void);
static int moniteur (void);
static int utilitaires (void);
static int configurer (void);
static void conftrad (void);
static void getdefs (void);
static void confedit (void);
static void cfcomedit (void);
static void conffic (void);
/* #BGstatic void confobj (void);*/
static void objagr (BINAIRE, BINAIRE);
/* #BGstatic void confao (void);*/
static void confrep (void);
static void toufonc (void);
static BOOL lecconf (BYTE XPTR);
static BOOL lectfp (BYTE XPTR);
static BOOL ecrconf (BYTE XPTR);

static int ask (BINAIRE,BINAIRE, BINAIRE, BINAIRE, BYTE XPTR );
static void errnonfic (void);
static int vmenu (BINAIRE,BINAIRE,BINAIRE,BINAIRE,int [], int []);
static int affmenu(BINAIRE,BINAIRE,BINAIRE,BINAIRE,int [], int []);
static int vselect (BINAIRE,BINAIRE,BINAIRE,BINAIRE,int [], BOOL[],int []);
static int run (BYTE XPTR,BYTE XPTR);
static int tfpask(BINAIRE,BINAIRE,BYTE XPTR,BINAIRE,int);
static void tfpaff(BYTE XPTR);
static void argu(void);
static void etoufonc(void);
static BINAIRE xx_getch(void);
static void Print(BYTE XPTR, BINAIRE,BINAIRE);
static void XPrint( BYTE XPTR, BINAIRE );
static void HPrint( BYTE XPTR );
static void ini_boite(void);
static void fin_boite(void);
static void Xfgets(BYTE XPTR,BINAIRE,FILE XPTR);
static void Xscanf(BYTE XPTR,BINAIRE XPTR,BINAIRE XPTR);

static int projet(void);
static void liste_mod(void);
static int editer(BOOL [], BYTE XPTR);
static int generer(void);
static int miseajour(BYTE XPTR);
static int linker( BYTE XPTR, BYTE XPTR );
static int executer(void);
static int runexa(BYTE, BYTE XPTR);
static void run_argu(void);
static int util(void);
static int run_util(BYTE);
static void msg_erreur(BINAIRE);
static int config(void);
static void confsys(void);
static void confext(void);
static void aff_zone(BYTE XPTR, int);
static void ecrcfg(void);
static void leccfg(void);    
static void affprj(void);

static void Selopt(BYTE XPTR);

static void init_tfp(void);
static void rest_tfp(void); 
static void reinit_tfp(void);

FILE *XAfopen(BYTE XPTR, BYTE XPTR);
static void makenom(BYTE XPTR, BYTE);
static char conv_base (BYTE);
static void conv_poste ( BYTE XPTR, BINAIRE );
static void create_prj( void );
static void itoh( BYTE XPTR, BINAIRE);
static void get_atr_opt( BYTE XPTR);
/* #BGstatic void get_aplus_opt( BYTE XPTR );*/
static BINAIRE max_largeur( BINAIRE [], BINAIRE );
static void Xset_filler( BOOL );
/*global*/ void cadre (BINAIRE, BINAIRE, BINAIRE, BINAIRE);
/*global*/ void  hcadre (BINAIRE, BINAIRE, BINAIRE, BINAIRE);
/*global*/ void Xatb(BINAIRE);

#ifdef unix
extern void modterm(BINAIRE);
#endif

extern int  boite(BINAIRE, BINAIRE, BYTE XPTR, BYTE XPTR, StrGen XPTR, StrGen XPTR, StrGen XPTR, BYTE XPTR);
extern BOOL NextOpt(BYTE XPTR XPTR, BYTE XPTR);
extern void fn_parser(BYTE FPTR, BYTE FPTR, BINAIRE);
extern void purge(StrGen XPTR);

extern void maj_histo(StrGen XPTR, BYTE XPTR);
extern void liste_histo(StrGen XPTR, BYTE XPTR);
extern void init_boite(StrGen XPTR, BINAIRE, BINAIRE, BINAIRE,BINAIRE, BINAIRE, BINAIRE, BINAIRE, BYTE XPTR);
extern void initerm (void);
extern void finterm (void);
extern void x_clear (void);
extern void pos (BINAIRE,BINAIRE);
extern void x_putch(BINAIRE);
extern void x_cprintf(char FPTR);
extern BINAIRE x_getch (void);
extern void atb (BINAIRE);
extern void x_bell (void);
extern int prfo(int,BYTE FPTR,int);
extern int lcfo(int,BYTE FPTR,int);
extern void pauseb (void);
extern BINAIRE conf(BINAIRE);
#ifdef buf_cico
extern void x_bstart(void);
extern void x_bflush(void);
#endif

extern int GetReper (char XPTR XPTR, int);
extern int LoadGo (char XPTR, char XPTR, char XPTR);
extern int FindFile (char XPTR, char XPTR);
extern int NextFile (char XPTR);

extern int systemd(char FPTR, int, int, int);
extern int systeme(char FPTR);
#else

int main ();

static void etoufonc();
static void initabmes();
static BOOL init ();
static BOOL definit ();
static void initscreen ();
static void final ();
static void finscreen ();
static void banniere ();
static void attendre ();
static int pause();
static void menugene ();
static void entete ();
static void affnomfic ();
static void affnomfic ();
static BINAIRE hmenu ();
static char selopt();
static int arreter ();
static int selection ();
static void getmods ();
static int catalog ();
static int edition ();
static int traduction ();
/* #BGstatic int aplus();*/
static int ao ();
static int getnseg ();
static int moniteur ();
static int utilitaires ();
static int configurer ();
static void liens ();
static void conftrad ();
static void getdefs ();
static void confedit ();
static void cfcomedit ();
static void conffic ();
static void confrep ();
/* #BGstatic void confobj();*/
static void objagr();
/* #BGstatic void confao();*/
static void toufonc ();
static BOOL lecconf ();
static BOOL lectfp ();
static BOOL ecrconf ();
static int tfpask();
static void tfpaff();

static int ask ();
static void errnonfic ();
static int vmenu ();
static int vselect ();
static int run ();
static void argu();
static void etoufonc();
static BINAIRE xx_getch();
static void Print();
static void XPrint();
static void HPrint();
static void ini_boite();
static void fin_boite();
static void Xfgets();
static void Xscanf();

static int projet();
static void liste_mod();
static int editer();
static int generer();
static int miseajour();
static int linker();
static int executer();
static int runexa();
static void run_argu();
static int util();
static int run_util();
static void msg_erreur();
static int config();
static void confsys();
static void confext();
static void aff_zone();
static void ecrcfg();
static void leccfg();    
static void affprj();
#define Selopt();
static void init_tfp();
static void rest_tfp(); 
static void reinit_tfp();

FILE *XAfopen();
static void makenom();
static char conv_base ();
static void conv_poste();
static void create_prj();
static void itoh();

static void get_atr_opt();
/* #BG static void get_aplus_opt();*/
static BINAIRE max_largeur();
static void Xset_filler();
/*global*/ void cadre ();
/*global*/ void hcadre ();
/*global*/ void Xatb();

#ifdef unix
extern void modeterm();
#endif

extern int  boite();
extern void liste_histo();
extern void purge();
extern BOOL NextOpt();
extern void fn_parser();
extern void initerm ();
extern void finterm ();
extern void x_clear ();
extern void pos ();
extern void x_putch();
extern void x_cprintf();
extern BINAIRE x_getch ();
extern void atb ();
extern void x_bell ();
extern int prfo();
extern int lcfo();
extern void pauseb ();
extern BINAIRE conf();
#ifdef buf_cico
extern void x_bstart();
extern void x_bflush();
#endif

extern int GetReper ();
extern int LoadGo ();
extern int FindFile ();
extern int NextFile ();
extern int MkNom ();

extern int editeur();
extern int traducteur();
extern int linker();
extern int systemd();
extern int systeme();

#endif


