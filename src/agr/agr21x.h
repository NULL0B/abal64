/* Start of Message Texts : Language 0 */
#define L0STX "*STX*3AGRF    21g00"
#define L0MSG0001 "on0"
#define L0MSG0002 "Source fouineur"
#define L0MSG0003 "Version"
#define L0MSG0004 "Options"
#define L0MSG0005 "-a<fichier>       : conversion d'un fichier d'erreurs"
#define L0MSG0006 "-c                : respect majuscules et miniscules"
#define L0MSG0007 "-e<editeur>       : nom et chemin de l'‚diteur"
#define L0MSG0008 "-g                : inhibe pointage automatique"
#define L0MSG0009 "-i                : analyse des inclusions"
#define L0MSG0010 "-l                : liste ‚cran des instances"
#define L0MSG0011 "-s<pattern>       : pattern a rechercher"
#define L0MSG0012 "-t<fichier>       : nom du fichier de trace"
#define L0MSG0013 "-v                : mode verbose"
#define L0MSG0014 "-w                : pointage des avertissements"
#define L0MSG0015 "-x                : nombre d'instances"
#define L0MSG0016 "Erreur"
#define L0MSG0017 "Pattern non-trouv‚"
#define L0ETX "*ETX*"
#define MSGQTY    19
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L0messages[MSGQTY+16][ 55] = {
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
#define L1STX "*STX*3AGRG    21c00"
#define L1MSG0001 "yn0"
#define L1MSG0002 "Source file browsing utility"
#define L1MSG0003 "Version"
#define L1MSG0004 "Options"
#define L1MSG0005 "-a<filename>      : convert and trace error file"
#define L1MSG0006 "-c                : force case sensitive compare"
#define L1MSG0007 "-e<editor>        : specify trace editor"
#define L1MSG0008 "-g                : generate trace list only"
#define L1MSG0009 "-i                : analysis of inclusions"
#define L1MSG0010 "-l                : list matching lines to stdout"
#define L1MSG0011 "-s<pattern>       : specify search pattern"
#define L1MSG0012 "-t<filename>      : specify explicite trace file"
#define L1MSG0013 "-v                : activate verbose mode"
#define L1MSG0014 "-w                : allow trace of warnings"
#define L1MSG0015 "-x                : quantify matched patterns"
#define L1MSG0016 "Error"
#define L1MSG0017 "No match found"
#define L1ETX "*ETX*"
#define MSGQTY    19
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L1messages[MSGQTY+16][ 51] = {
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
for  (;x < MSGQTY;x++) {
while   ( *wptr ) wptr++;
while   (! (*wptr) ) wptr++;
TalkPtr[x] = wptr;
}
return  ;
}
