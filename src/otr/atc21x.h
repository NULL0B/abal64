#ifndef _translator_messages
#define _translator_messages

/* Start of Message Texts : Language 0 */
#define L0STX "*STX*3OTRF    21e00"
#define L0MSG0001 "on0"
#define L0MSG0002 "ABAL++ to C Object Traducteur "
#define L0MSG0003 "traduction de"
#define L0MSG0004 "Erreur de syntaxe"
#define L0MSG0005 "Directive inconu"
#define L0MSG0006 "Trops de parameters pour procedure"
#define L0MSG0007 "Pas assez de parameters pour procedure"
#define L0MSG0008 "Erreur d'allocation memoire"
#define L0MSG0009 "Erreur Interne du traducteur"
#define L0MSG0010 "#endif inattendu"
#define L0MSG0011 "#else inattendu"
#define L0MSG0012 "#endif attendu"
#define L0MSG0013 "parenthese froite attendu"
#define L0MSG0014 "Symbole deja defini"
#define L0MSG0015 "Type de donnees incorrect"
#define L0MSG0016 "Pas encore disponible"
#define L0MSG0017 "Attention"
#define L0MSG0018 "Punctuation incorrecte"
#define L0MSG0019 "s"
#define L0MSG0020 "ettiquette non-definie"
#define L0MSG0021 "Variable attendue"
#define L0MSG0022 "Etiquette attendu"
#define L0MSG0023 "mot-clef attendu"
#define L0MSG0024 "Segment attendu"
#define L0MSG0025 "Fichier attendu"
#define L0MSG0026 "Recursivite illegale"
#define L0MSG0027 "Erreur fichier"
#define L0ETX "*ETX*"
#define MSGQTY    29
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L0messages[MSGQTY+16][ 64] = {
	L0STX,
	L0MSG0001,
	L0MSG0002,
	L0MSG0003,
	L0MSG0004,
	L0MSG0005,
	L0MSG0006,
	L0MSG0007,
	L0MSG0008,
	L0MSG0009,
	L0MSG0010,
	L0MSG0011,
	L0MSG0012,
	L0MSG0013,
	L0MSG0014,
	L0MSG0015,
	L0MSG0016,
	L0MSG0017,
	L0MSG0018,
	L0MSG0019,
	L0MSG0020,
	L0MSG0021,
	L0MSG0022,
	L0MSG0023,
	L0MSG0024,
	L0MSG0025,
	L0MSG0026,
	L0MSG0027,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
	L0ETX
	};
#else
static char l0stx[] = L0STX;
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
static char l0msg0027[] = L0MSG0027;
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
#endif
/* Start of Message Texts : Language 1 */
#define L1STX "*STX*3OTRG    21d01"
#define L1MSG0001 "yn0"
#define L1MSG0002 "ABAL++ to C Object Traducteur "
#define L1MSG0003 "translation of"
#define L1MSG0004 "Syntax Error"
#define L1MSG0005 "Unknown directive"
#define L1MSG0006 "Too many parameters for procedure"
#define L1MSG0007 "Not enough parameters for procedure"
#define L1MSG0008 "Memory allocation Failure"
#define L1MSG0009 "Internal translator error"
#define L1MSG0010 "Unexpected #endif"
#define L1MSG0011 "Unexpected #else"
#define L1MSG0012 "Expected #endif"
#define L1MSG0013 "Expected closing brace"
#define L1MSG0014 "Symbol Already Defined"
#define L1MSG0015 "Incorrect data type"
#define L1MSG0016 "Not yet available"
#define L1MSG0017 "Warning"
#define L1MSG0018 "Incorrect punctuation"
#define L1MSG0019 "s"
#define L1MSG0020 "Undefined label"
#define L1MSG0021 "Variable expected"
#define L1MSG0022 "Label expected"
#define L1MSG0023 "Expected keyword"
#define L1MSG0024 "Expected segment identifier"
#define L1MSG0025 "Expected file identifier"
#define L1MSG0026 "Illegal Recursivity"
#define L1MSG0027 "File error"
#define L1ETX "*ETX*"
#define MSGQTY    29
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L1messages[MSGQTY+16][ 64] = {
	L1STX,
	L1MSG0001,
	L1MSG0002,
	L1MSG0003,
	L1MSG0004,
	L1MSG0005,
	L1MSG0006,
	L1MSG0007,
	L1MSG0008,
	L1MSG0009,
	L1MSG0010,
	L1MSG0011,
	L1MSG0012,
	L1MSG0013,
	L1MSG0014,
	L1MSG0015,
	L1MSG0016,
	L1MSG0017,
	L1MSG0018,
	L1MSG0019,
	L1MSG0020,
	L1MSG0021,
	L1MSG0022,
	L1MSG0023,
	L1MSG0024,
	L1MSG0025,
	L1MSG0026,
	L1MSG0027,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
MSG_FILLER  ,
	L1ETX
	};
#else
static char l1stx[] = L1STX;
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
static char l1msg0027[] = L1MSG0027;
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
#endif

BPTR TalkPtr[MSGQTY];

void TalkWork()
{
	WORD   x=0;
#ifdef   MSG_HX
	BPTR   wptr=(BPTR) &L0messages[1];
	if   ( *(wptr + 2) == '0' )
		wptr   = (BPTR) L0messages;
	else   wptr = (BPTR) L1messages;
#else
	BPTR   wptr=(BPTR) l0msg0001;
	if   ( *(wptr + 2) == '0' )
		wptr   = (BPTR) l0stx;
	else   wptr = (BPTR) l1stx;
#endif
	for  (;x < MSGQTY;x++) 
	{
		while   ( *wptr ) wptr++;
		while   (! (*wptr) ) wptr++;
		TalkPtr[x] = wptr;
	}
	return;
}

#endif

