/* Start of Message Texts : Language 0 */
#define L0STX "*STX*3AOF     21b00"
#define L0MSG0001 "on0"
#define L0MSG0002 "   ABAL++ Post Optimiseur   Version "
#define L0MSG0003 "Optimisation : "
#define L0MSG0004 "Erreur a la traduction"
#define L0MSG0005 "Optimisation a effectuer apres l'edition des liens "
#define L0MSG0006 "Optimisation d'un module impossible"
#define L0MSG0007 "Tcode inconnu"
#define L0MSG0008 "a deja ete optimise"
#define L0MSG0009 "Version ABAL++ incorrecte"
#define L0MSG0010 " "
#define L0MSG0011 " : Fichier Tcode incorrecte"
#define L0MSG0012 "Erreur de suivie des registres"
#define L0MSG0013 "reduit : "
#define L0MSG0014 " de "
#define L0MSG0015 " en "
#define L0MSG0016 " Table des Procedures : "
#define L0MSG0017 " Erreur de chargement des constantes"
#define L0MSG0018 " Erreur de chargement variables globales"
#define L0MSG0019 " Erreur de creation de l'image des donnees"
#define L0MSG0020 " Erreur de chargement Table des Procedures"
#define L0MSG0021 " Erreur de chargement Table des Segments"
#define L0MSG0022 " Programme "
#define L0MSG0023 " Reduction totale : "
#define L0MSG0024 " Erreur lecture fichier "
#define L0MSG0025 " Erreur d'ouverture fichier "
#define L0MSG0026 " Erreur de supression fichier "
#define L0MSG0027 " Erreur de renommage fichier "
#define L0MSG0028 " Erreur de creation fichier "
#define L0MSG0029 " "
#define L0MSG0030 " "
#define L0MSG0031 " "
#define L0MSG0032 "   Options :  -ovw23"
#define L0MSG0033 "      o    :  activer optimisation niveau 1 "
#define L0MSG0034 "      2    :  niveau 2 optimisation des procedures "
#define L0MSG0035 "      3    :  niveau 3 optimisation des segments "
#define L0MSG0036 "      v    :  activer mode verbose"
#define L0MSG0037 "      w    :  activer messages d'avertissement"
#define L0ETX "*ETX*"
#define MSGQTY    39
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L0messages[MSGQTY+16][ 53] = {
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
	L0MSG0028,
	L0MSG0029,
	L0MSG0030,
	L0MSG0031,
	L0MSG0032,
	L0MSG0033,
	L0MSG0034,
	L0MSG0035,
	L0MSG0036,
	L0MSG0037,
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
static char l0msg0028[] = L0MSG0028;
static char l0msg0029[] = L0MSG0029;
static char l0msg0030[] = L0MSG0030;
static char l0msg0031[] = L0MSG0031;
static char l0msg0032[] = L0MSG0032;
static char l0msg0033[] = L0MSG0033;
static char l0msg0034[] = L0MSG0034;
static char l0msg0035[] = L0MSG0035;
static char l0msg0036[] = L0MSG0036;
static char l0msg0037[] = L0MSG0037;
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
#define L1STX "*STX*3AOG     21b00"
#define L1MSG0001 "yn0"
#define L1MSG0002 "   ABAL++ Post Optimiser    Version "
#define L1MSG0003 "Optimising : "
#define L1MSG0004 "Translator phase terminated incorrectly "
#define L1MSG0005 "Optimisation must be performed after the link phase "
#define L1MSG0006 "Pre-Link Optimisation of Modules is not possible "
#define L1MSG0007 "Unknown T-Code Status "
#define L1MSG0008 "has already been optimised "
#define L1MSG0009 "Incorrect ABAL++ Version "
#define L1MSG0010 " "
#define L1MSG0011 " : Incorrect Tcode File "
#define L1MSG0012 "Register shadowing error"
#define L1MSG0013 "optimised : "
#define L1MSG0014 " from "
#define L1MSG0015 " to "
#define L1MSG0016 " Procedure Table : "
#define L1MSG0017 " Error loading constants "
#define L1MSG0018 " Error loading global variables"
#define L1MSG0019 " Error creating global variable image"
#define L1MSG0020 " Error loading Procedure Table "
#define L1MSG0021 " Error loading Segment Table "
#define L1MSG0022 " Program "
#define L1MSG0023 " Tcode Reduced by : "
#define L1MSG0024 " Error reading Control sector "
#define L1MSG0025 " Error opening file : "
#define L1MSG0026 " Error deleting file : "
#define L1MSG0027 " Error renaming file : "
#define L1MSG0028 " Error creating file : "
#define L1MSG0029 " "
#define L1MSG0030 " "
#define L1MSG0031 " "
#define L1MSG0032 "   Options :  -ovw23"
#define L1MSG0033 "      o    :  activate optimisation level 1 "
#define L1MSG0034 "      2    :  level 2 optimisation of procedures "
#define L1MSG0035 "      3    :  level 3 optimisation of segments "
#define L1MSG0036 "      v    :  activate information messages "
#define L1MSG0037 "      w    :  activate warning messages "
#define L1ETX "*ETX*"
#define MSGQTY    39
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L1messages[MSGQTY+16][ 54] = {
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
	L1MSG0028,
	L1MSG0029,
	L1MSG0030,
	L1MSG0031,
	L1MSG0032,
	L1MSG0033,
	L1MSG0034,
	L1MSG0035,
	L1MSG0036,
	L1MSG0037,
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
static char l1msg0028[] = L1MSG0028;
static char l1msg0029[] = L1MSG0029;
static char l1msg0030[] = L1MSG0030;
static char l1msg0031[] = L1MSG0031;
static char l1msg0032[] = L1MSG0032;
static char l1msg0033[] = L1MSG0033;
static char l1msg0034[] = L1MSG0034;
static char l1msg0035[] = L1MSG0035;
static char l1msg0036[] = L1MSG0036;
static char l1msg0037[] = L1MSG0037;
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
EXAWORD   x=0;
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
for  (;x < MSGQTY;x++) {
while   ( *wptr ) wptr++;
while   (! (*wptr) ) wptr++;
TalkPtr[x] = wptr;
}
return  ;
}

