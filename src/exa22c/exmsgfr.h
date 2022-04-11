#ifdef	DEBUGGER

#ifdef	ABAL21
#define MSG_ID_EXADB_FR "*STX*3EXADBF  21b00"
#else
#define MSG_ID_EXADB_FR "*STX*3EXADBF  14e00"
#endif

#ifdef	ABAL14
/*	These two control the Second Help Screen of Command 'H'		*/
/*	------------------------------------------------------- 	*/
#define	FIRST_MSG_14 109
#define LAST_MSG_14  116
#define	MSGQTY	(MSGERREUR + 171)
#else
#define	MSGQTY	(MSGERREUR +  96)
#endif	/* ABAL14 */

static	char	debgesmes[]   = MSG_ID_EXADB_FR;
static	char	OuiNon[]      = "on0";
#ifdef	ABAL21
static	char	exaparle0001[] ="Moniteur ABAL";
#else
static	char	exaparle0001[] ="Moniteur ABAL";
#endif

#else

#ifdef	ABAL21
#define MSG_ID_EXA_FR   "*STX*3EXAF    21b00"
#else
#define MSG_ID_EXA_FR   "*STX*3EXAF    14e00"
#endif

#define	MSGQTY	(MSGERREUR + 1)
static	char	debgesmes[]   = MSG_ID_EXA_FR;
static	char	OuiNon[]      ="on0";

#ifdef	EXAMINE
static	char	exaparle0001[] ="Profileur d'applications ";
#else
#ifdef	ABAL21
static	char	exaparle0001[] ="Executeur ABAL";
#else
static	char	exaparle0001[] ="Executeur ABAL";
#endif
#endif

#endif

/*	Messages de reportage des erreurs par eder()	*/
/*	--------------------------------------------	*/
/*	pour EXA et EXADB				*/
/*							*/

static	char	exaparle0002[] ="Erreur";
static	char	exaparle0003[] ="d'E/S"; 	 
static	char	exaparle0004[] ="systeme";	 
static	char	exaparle0005[] ="de commande"; 
static	char	exaparle0006[] ="fichier";	 
static	char	exaparle0007[] ="systeme";	 
static	char	exaparle0008[] ="fichier";	 
static	char	exaparle0009[] ="graphique"; 
static	char	exaparle0010[] ="systeme";	 
static	char	exaparle0011[] ="a l'adresse"; 
static	char	exaparle0012[] ="Erreur fatale : Signal systeme numero";

#ifndef	DEBUGGER
static	char	exaparle0013[] ="Environnement version ";
#ifdef	ABALX11
static	char	exaparle0014[] ="Validez";
#endif
#endif

#ifdef	DEBUGGER

/*	Message du Menu Ctrl H  de EXADB seulement	*/
/*	------------------------------------------	*/

static	char	exaparle0013[] ="Ctrl A : Poser un point d'arret permanent";
static	char	exaparle0014[] ="Ctrl B : Poser un point d'arret temporaire";
static	char	exaparle0015[] ="Ctrl C : Deplacer la page vers le bas";
static	char	exaparle0016[] ="Ctrl D : Diminuer la taille de la fenetre";
static	char	exaparle0017[] ="Ctrl E : Deplacer la ligne vers le bas";
static	char	exaparle0018[] ="Ctrl F : Rechercher une chaine (avec joker)";
static	char	exaparle0019[] ="Ctrl G : Agrandir la taille de la fenetre";
static	char	exaparle0020[] ="Ctrl H : Afficher cet ecran";
static	char	exaparle0021[] ="Ctrl I : Redefinir les tabulations";
static	char	exaparle0022[] ="Ctrl J : Basculer la ligne d'aide";
static	char	exaparle0023[] ="Ctrl K : Deplacer la ligne vers le haut";
static	char	exaparle0024[] ="Ctrl L : Definir un marqueur de position";
static	char	exaparle0025[] ="Ctrl M : Revenir a la page d'execution";
static	char	exaparle0026[] ="Ctrl P : Se positionner sur un marqueur";
static	char	exaparle0027[] ="Ctrl R : Deplacer la page vers le haut";
static	char	exaparle0028[] ="Ctrl V : Reafficher l'ecran courant";
static	char	exaparle0029[] ="Ctrl W : Basculer entre l'ecran programme et moniteur";
static	char	exaparle0030[] ="Ctrl X : Lancer l'execution";
static	char	exaparle0031[] ="Ctrl Y : Supprimer un marqueur";
static	char	exaparle0032[] ="Ctrl Z : Zoomer la ligne courante";

/*	Messages du Menu 'H'	EXADB seulement		*/
/*	---------------------------------------		*/

static	char	exaparle0033[] ="AP [PROCID:] [ADRESSE]       : Poser un piege permanent sur une procedure";
static	char	exaparle0034[] ="AS [SEGMID:] [ADRESSE]       : Poser un piege permanent sur un segment";
static	char	exaparle0035[] ="AL OU BL                     : Lister les pieges";
static	char	exaparle0036[] ="AI<NUMERO> OU BI<NUMERO>     : Ignorer un piege";
static	char	exaparle0037[] ="BP [PROCID:] [ADRESSE]       : Poser un piege temporaire sur une procedure";
static	char	exaparle0038[] ="BS [SEGMID:] [ADRESSE]       : Poser un piege temporaire sur un segment";
static	char	exaparle0039[] ="C                            : Continuer l'execution";
static	char	exaparle0040[] ="D[H]<VARIABLE>[(DIM1[,DIM2])]: Afficher une variable en hexa";
static	char	exaparle0041[] ="E                            : Sortir du moniteur ABAL";
static	char	exaparle0042[] ="H                            : Afficher cet ecran";
static	char	exaparle0043[] ="K</XX> , K<NNN> , K<'C'>     : Definir la touche d'interruption";
static	char	exaparle0044[] ="M<VARIABLE>[(DIM1[,DIM2])]   : Modifier une variable";
static	char	exaparle0045[] ="OA<VARIABLE>[(DIM1[,DIM2])]  : Ajouter une variable en observation";
static	char	exaparle0046[] ="OI<VARIABLE>                 : Ignorer l'observation d'une variable";
static	char	exaparle0047[] ="OL                           : Lister les variables en observation";
static	char	exaparle0048[] ="Z                            : Afficher la trace des GOSUB";
static	char	exaparle0049[] ="!<CMD,PARAM>                 : Appeler un utilitaire systeme";
static	char	exaparle0050[] ="  ";


/*	Messages divers des fonctions EXADB		*/
/*	-----------------------------------		*/

static	char	exaparle0051[] ="Liste des points d'arret";
static	char	exaparle0052[] ="Liste des variables en observation";
static	char	exaparle0053[] ="permanent";  
#ifdef	ABAL14
static	char	exaparle0054[] ="Empillage";
#else
static	char	exaparle0054[] ="Pile GOSUB";
#endif
static	char	exaparle0055[] ="Modifie";
static	char	exaparle0056[] ="**FIN**"; 
static	char	exaparle0057[] ="Touche d'IT";
static	char	exaparle0058[] ="Voulez-vous sortir du moniteur ABAL";
static	char	exaparle0059[] ="Variable inconnue";
static	char	exaparle0060[] ="Fin normale d'execution";
static	char	exaparle0061[] ="Erreur d'acces au fichier liste";

/*	Messages en mode Verbose	*/
/*	------------------------	*/
#ifdef	ABAL14
static	char	exaparle0062[] ="Adresse de piege incorrecte";
#else
static	char	exaparle0062[] ="La table des pieges est pleine";
#endif
static	char	exaparle0063[] ="Procedure inconnue";
static	char	exaparle0064[] ="Environnement version ";
static	char	exaparle0065[] ="Liste des pieges sur variables";
static	char	exaparle0066[] ="Arret sur une variable ";
static	char	exaparle0067[] =" ";
static	char	exaparle0068[] =" ";
static	char	exaparle0069[] ="Ajout realise";
static	char	exaparle0070[] ="Suppression realisee";
static	char	exaparle0071[] ="Interdit en mode consultation";
static	char	exaparle0072[] ="Procedure / Segment non trouve";
static	char	exaparle0073[] ="Adresse non trouvee";
static	char	exaparle0074[] ="Marqueur a chercher";
static	char	exaparle0075[] ="Longueur des tabulations";
static	char	exaparle0076[] ="Marqueur a supprimer";
static	char	exaparle0077[] ="Marqueur a definir";
static	char	exaparle0078[] ="Fenetre agrandie";
static	char	exaparle0079[] ="Fenetre diminuee";
static	char	exaparle0080[] ="Chaine a chercher";
static	char	exaparle0081[] ="Chaine non trouvee";
static	char	exaparle0082[] ="Appuyer sur une touche pour continuer";
static	char	exaparle0083[] ="ESC pour arreter";
static	char	exaparle0084[] ="Debordement de memoire";
static	char	exaparle0085[] ="Marqueur inexistant";
static	char	exaparle0086[] ="Marqueur supprime";
static	char	exaparle0087[] ="Marqueur ajoute";
static	char	exaparle0088[] ="Marqueur modifie";
static	char	exaparle0089[] ="Debordement de la table des marqueurs";

/*	Extended 1.2a Messages 		*/
/*	----------------------		*/

static	char	exaparle0090[] ="Modifier parametres";
static	char	exaparle0091[] ="Sauver   parametres";
static	char	exaparle0092[] ="Charger  parametres";
static	char	exaparle0093[] ="Modification des parametres du Moniteur ABAL";

static	char	exaparle0094[] ="Fenetre Menu Parametres";
static	char	exaparle0095[] ="Fenetre Pile des Gosubs";
static	char	exaparle0096[] ="Fenetre Liste des Marqueurs";
static	char	exaparle0097[] ="Fenetre Zoom sur Ligne Source";
static	char	exaparle0098[] ="Fenetre d'observation Variables";
static	char	exaparle0099[] ="Fenetre de commande";
static	char	exaparle0100[] ="Fenetre liste Observation";
static	char	exaparle0101[] ="Fenetre Modification Variables";
static	char	exaparle0102[] ="Fenetre Liste des pieges";
static	char	exaparle0103[] ="Fenetre Affichage Hexa";
static	char	exaparle0104[] ="Fenetres d'aide"; 
static	char	exaparle0105[] ="Fenetre de Saisie parametres";
static	char	exaparle0106[] ="Fenetre d'erreurs";
static	char	exaparle0107[] ="Fenetre de Sortie";
static	char	exaparle0108[] ="Fenetre de Liste Source";

#ifdef	ABAL14
static	char	exaparle0109[] ="  ";
static	char	exaparle0110[] ="BV <VARIABLE>                : Poser un piege temporaire sur une variable";
static	char	exaparle0111[] ="AV <VARIABLE>                : Poser un piege permanent  sur une variable";
static	char	exaparle0112[] ="F <NUMERO D'ASSIGN>          : Afficher des informations d'un ASSIGN ";
static	char	exaparle0113[] ="G [ NOM DU PROG ] [ , ARG]   : Relancer EXADB ";
static	char	exaparle0114[] ="VI<VARIABLE>                 : Ignorer la piege sur une variable ";
static	char	exaparle0115[] ="VL[VARIABLE]                 : Lister les pieges sur variables ";
static  char    exaparle0116[] =" ";
static	char	exaparle0117[] ="Saisie limite a 256 caracteres";

#ifdef	ABAL21
static	char	exaparle9117[] ="Mode Execution";
static	char	exaparle0118[] ="Mode Consultation";
static	char	exaparle0119[] ="Interrogation d'empilages";
static	char	exaparle0120[] ="Interrogation points d'arret";
static	char	exaparle0121[] ="Erreur ABAL";
static	char	exaparle0122[] ="Validez pour Quiter ou Escape";
static	char	exaparle0123[] ="Sources";
static	char	exaparle0124[] ="Adresse";
static	char	exaparle0125[] ="Variable optimisee";
static	char	exaparle0126[] ="Aide";
static	char	exaparle0127[] ="Globales";
static	char	exaparle0128[] ="Locales";
static	char	exaparle0129[] ="Procedures";
static	char	exaparle0130[] ="Segments";
static	char	exaparle0131[] ="Lancer";
static	char	exaparle0132[] ="Va ici";
static	char	exaparle0133[] ="Pas dedans";
static	char	exaparle0134[] ="Pas desus";
static	char	exaparle0135[] ="Retour";
static	char	exaparle0136[] ="Fichier";
static	char	exaparle0137[] ="Arret";
static	char	exaparle0138[] ="Menu";
static	char	exaparle0139[] ="Poser arret";
static	char	exaparle0140[] ="INTR:OUI";
static	char	exaparle0141[] ="INTR:NON";
static	char	exaparle0142[] ="PRINT";
static	char	exaparle0143[] ="HEX";
static	char	exaparle0144[] ="DEBUG";
static	char	exaparle0145[] ="Menu Symboles";
static	char	exaparle0146[] ="Menu Fonctions";
static	char	exaparle0147[] ="Syntaxe de commande";
static	char	exaparle0148[] ="Offset Tcode";
static	char	exaparle0149[] ="Fichier de commandes";
static	char	exaparle0150[] ="Chargement du configuration";
static	char	exaparle0151[] ="Fin du fichier";
static	char	exaparle0152[] ="Ligne trop longue";
static	char	exaparle0153[] ="Fichier non-trouve";
static	char	exaparle0154[] ="Fichier resultat";
static	char	exaparle0155[] ="Ecriture du fichier";
static	char	exaparle0156[] ="Erreur de creation";
static	char	exaparle0157[] ="Points d'arret";
static	char	exaparle0158[] ="Empillages";
static	char	exaparle0159[] ="Surveillance memoire";
static	char	exaparle0160[] ="Variables en observation";
static	char	exaparle0161[] ="Regions de trace";
static	char	exaparle0162[] ="Table d'assign";
static	char	exaparle0163[] ="Charger configuration";
static	char	exaparle0164[] ="Sauver configuration";
static	char	exaparle0165[] ="Mode execution requise";
static	char	exaparle0166[] ="Debut de region de trace";
static	char	exaparle0167[] ="Consultation sources";
static	char	exaparle0168[] ="Variables locales";
static	char	exaparle0169[] ="Chaine a rechercher";
static	char	exaparle0170[] = "<Fin de liste>";
static	char	exaparle0171[] = "Erreur fichier symbolique";
static	char	exaparle0172[] = "Erreur d'activation du trace";
static	char	exaparle0173[] = "Trace activate";
static	char	exaparle0174[] = "Ajout d'un region de trace";
static	char	exaparle0175[] = "Regions de trace";
static	char	exaparle0176[] = "Sources";
static	char	exaparle0177[] = "Listes";
static	char	exaparle0178[] = "Variables";
static	char	exaparle0179[] = "Constantes";
static	char	exaparle0180[] = "Procedures";
static	char	exaparle0181[] = "Segments";
static	char	exaparle0182[] = "Bibliotheques";

#endif

#endif

#endif

static	char	exaremp0001[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0002[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0003[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0004[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0005[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0006[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0007[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0008[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0009[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0010[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0012[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0013[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0014[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0015[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0016[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

#ifdef	DEBUGGER
static	char	exaremp0021[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0022[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0023[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0024[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0025[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0026[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0027[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0028[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0029[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0030[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0032[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0033[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0034[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0035[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exaremp0036[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
#endif

static	char	fingesmes[] = "*ETX*";


