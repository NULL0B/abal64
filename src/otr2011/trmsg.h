#ifndef	_translator_messages
#define	_translator_messages

/* Start of Message Texts : Language 0 FRANCAIS */

#define L0STX		"*STX*3OTRF    31a01"
#define L0MSG0000	"on0"

#ifdef	_TRABMSG_C
#define L0MSG0001 "ABAL++ Traducteur Objet"
#endif

#ifdef	_TRCBMSG_C
#define L0MSG0001 "COBOL++ Traducteur Objet"
#endif

#ifdef	_TRJVMSG_C
#define L0MSG0001 "JAVA++ Traducteur Objet"
#endif

#define L0MSG0002 "Traduction de"
#define L0MSG0003 "Erreur de syntaxe"
#define L0MSG0004 "Directive inconue"
#define L0MSG0005 "Trop de paramŠtres pour proc‚dure"
#define L0MSG0006 "Pas assez de paramŠtres pour proc‚dure"
#define L0MSG0007 "Erreur d'allocation memoire"
#define L0MSG0008 "Erreur Interne du traducteur"
#define L0MSG0009 "#endif inattendu"
#define L0MSG0010 "#else inattendu"
#define L0MSG0011 "#endif attendu"
#define L0MSG0012 "ParenthŠse droite attendue"
#define L0MSG0013 "Symbole d‚ja defini"
#define L0MSG0014 "Type de donn‚e incorrect"
#define L0MSG0015 "Pas encore disponible"
#define L0MSG0016 "Avertissement"
#define L0MSG0017 "Punctuation incorrecte"
#define L0MSG0018 "s"
#define L0MSG0019 "Ettiquette non d‚finie"
#define L0MSG0020 "Variable attendue"
#define L0MSG0021 "Etiquette attendue"
#define L0MSG0022 "Mot-cl‚ attendu"
#define L0MSG0023 "Segment attendu"
#define L0MSG0024 "Fichier attendu"
#define L0MSG0025 "R‚cursivit‚ illegale"
#define L0MSG0026 "Erreur fichier"
#ifdef WIN32
#define L0MSG0027 "Source incompatible avec le type de cible attendu"
#define L0MSG0028 "Ligne de commande invalide"
#define L0MSG0029 "Cible en cours d'utilisation"
#define L0MSG0030 "Ouverture du fichier source impossible"
#ifdef otr32
#define L0MSG0031 "ABAL3: Traduction 32 bits..."
#else
#define L0MSG0031 "ABAL3: Traduction 16 bits..."
#endif
#endif
#define L0MSG0032 "D‚finir"
#define L0ETX		"*ETX*"

#ifdef WIN32
#define MSGQTY    35
#else
#define MSGQTY    30
#endif

#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

static char l0stx[] = L0STX;
static char l0msg0000[] = L0MSG0000;
static char l0msg0001[] = L0MSG0001;
static char l0msg0002[] = L0MSG0002;
static char l0msg0003[] = L0MSG0003;
static char l0msg0004[] = L0MSG0004;
static char l0msg0005[] = L0MSG0005;
static char l0msg0006[] = L0MSG0006;
static char l0msg0007[] = L0MSG0007;
static char l0msg0008[] = L0MSG0008;
static char l0msg0009[] = L0MSG0009;
static char l0msg0010[] = L0MSG0010;
static char l0msg0011[] = L0MSG0011;
static char l0msg0012[] = L0MSG0012;
static char l0msg0013[] = L0MSG0013;
static char l0msg0014[] = L0MSG0014;
static char l0msg0015[] = L0MSG0015;
static char l0msg0016[] = L0MSG0016;
static char l0msg0017[] = L0MSG0017;
static char l0msg0018[] = L0MSG0018;
static char l0msg0019[] = L0MSG0019;
static char l0msg0020[] = L0MSG0020;
static char l0msg0021[] = L0MSG0021;
static char l0msg0022[] = L0MSG0022;
static char l0msg0023[] = L0MSG0023;
static char l0msg0024[] = L0MSG0024;
static char l0msg0025[] = L0MSG0025;
static char l0msg0026[] = L0MSG0026;
#ifdef WIN32
static char l0msg0027[] = L0MSG0027;
static char l0msg0028[] = L0MSG0028;
static char l0msg0029[] = L0MSG0029;
static char l0msg0030[] = L0MSG0030;
static char l0msg0031[] = L0MSG0031;
#endif
static char l0msg0032[] = L0MSG0032;
static char l0pad0001[] = MSG_FILLER;
static char l0pad0002[] = MSG_FILLER;
static char l0pad0003[] = MSG_FILLER;
static char l0pad0004[] = MSG_FILLER;
static char l0pad0005[] = MSG_FILLER;
static char l0pad0006[] = MSG_FILLER;
static char l0pad0007[] = MSG_FILLER;
static char l0pad0008[] = MSG_FILLER;
static char l0pad0009[] = MSG_FILLER;
static char l0pad0010[] = MSG_FILLER;
static char l0pad0011[] = MSG_FILLER;
static char l0pad0012[] = MSG_FILLER;
static char l0pad0013[] = MSG_FILLER;
static char l0pad0014[] = MSG_FILLER;
static char l0pad0015[] = MSG_FILLER;
static char l0pad0016[] = MSG_FILLER;
static char l0etx[] = L0ETX;


/* Start of Message Texts : Language 1 ENGLISH */

#define L1STX		"*STX*3OTRG    31a01"
#define L1MSG0000 "yn0"
#define L1MSG0001 "ABAL++ Object Translator"
#define L1MSG0002 "Translation of"
#define L1MSG0003 "Syntax Error"
#define L1MSG0004 "Unknown directive"
#define L1MSG0005 "Too many parameters for procedure"
#define L1MSG0006 "Not enough parameters for procedure"
#define L1MSG0007 "Memory allocation Failure"
#define L1MSG0008 "Internal translator error"
#define L1MSG0009 "Unexpected #endif"
#define L1MSG0010 "Unexpected #else"
#define L1MSG0011 "Expected #endif"
#define L1MSG0012 "Expected closing brace"
#define L1MSG0013 "Symbol Already Defined"
#define L1MSG0014 "Incorrect data type"
#define L1MSG0015 "Not yet available"
#define L1MSG0016 "Warning"
#define L1MSG0017 "Incorrect punctuation"
#define L1MSG0018 "s"
#define L1MSG0019 "Undefined label"
#define L1MSG0020 "Variable expected"
#define L1MSG0021 "Label expected"
#define L1MSG0022 "Expected keyword"
#define L1MSG0023 "Expected segment identifier"
#define L1MSG0024 "Expected file identifier"
#define L1MSG0025 "Illegal Recursivity"
#define L1MSG0026 "File error"
#ifdef WIN32
#define L1MSG0027 "Source uncompatible with the expected target type"
#define L1MSG0028 "Incorrect command line"
#define L1MSG0029 "Target still busy"
#define L1MSG0030 "Cannot open source"
#ifdef otr32
#define L1MSG0031 "ABAL3: Translation 32 bits..."
#else
#define L1MSG0031 "ABAL3: Translation 16 bits..."
#endif
#endif
#define L1MSG0032 "Define"
#define L1ETX		"*ETX*"

#ifdef WIN32
#define MSGQTY    35
#else
#define MSGQTY    30
#endif

#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

static char l1stx[] = L1STX;
static char l1msg0000[] = L1MSG0000;
static char l1msg0001[] = L1MSG0001;
static char l1msg0002[] = L1MSG0002;
static char l1msg0003[] = L1MSG0003;
static char l1msg0004[] = L1MSG0004;
static char l1msg0005[] = L1MSG0005;
static char l1msg0006[] = L1MSG0006;
static char l1msg0007[] = L1MSG0007;
static char l1msg0008[] = L1MSG0008;
static char l1msg0009[] = L1MSG0009;
static char l1msg0010[] = L1MSG0010;
static char l1msg0011[] = L1MSG0011;
static char l1msg0012[] = L1MSG0012;
static char l1msg0013[] = L1MSG0013;
static char l1msg0014[] = L1MSG0014;
static char l1msg0015[] = L1MSG0015;
static char l1msg0016[] = L1MSG0016;
static char l1msg0017[] = L1MSG0017;
static char l1msg0018[] = L1MSG0018;
static char l1msg0019[] = L1MSG0019;
static char l1msg0020[] = L1MSG0020;
static char l1msg0021[] = L1MSG0021;
static char l1msg0022[] = L1MSG0022;
static char l1msg0023[] = L1MSG0023;
static char l1msg0024[] = L1MSG0024;
static char l1msg0025[] = L1MSG0025;
static char l1msg0026[] = L1MSG0026;
#ifdef WIN32
static char l1msg0027[] = L1MSG0027;
static char l1msg0028[] = L1MSG0028;
static char l1msg0029[] = L1MSG0029;
static char l1msg0030[] = L1MSG0030;
static char l1msg0031[] = L1MSG0031;
#endif
static char l1msg0032[] = L1MSG0032;
static char l1pad0001[] = MSG_FILLER;
static char l1pad0002[] = MSG_FILLER;
static char l1pad0003[] = MSG_FILLER;
static char l1pad0004[] = MSG_FILLER;
static char l1pad0005[] = MSG_FILLER;
static char l1pad0006[] = MSG_FILLER;
static char l1pad0007[] = MSG_FILLER;
static char l1pad0008[] = MSG_FILLER;
static char l1pad0009[] = MSG_FILLER;
static char l1pad0010[] = MSG_FILLER;
static char l1pad0011[] = MSG_FILLER;
static char l1pad0012[] = MSG_FILLER;
static char l1pad0013[] = MSG_FILLER;
static char l1pad0014[] = MSG_FILLER;
static char l1pad0015[] = MSG_FILLER;
static char l1pad0016[] = MSG_FILLER;
static char l1etx[] = L1ETX;

BPTR TalkPtr[MSGQTY];

#ifdef WIN32
extern int IsFrench;
#endif


#endif	/* _translator_messages */



