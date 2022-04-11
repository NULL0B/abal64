/* Start of Message Texts : Language 0 */
#define L0STX "*STX*3EXAF    21d00"
#define L0MSG0001 "on0"
#define L0MSG0002 "ExÇcuteur ABAL"
#define L0MSG0003 "Erreur"
#define L0MSG0004 "d'E/S"
#define L0MSG0005 "systäme"
#define L0MSG0006 "de commande"
#define L0MSG0007 "fichier"
#define L0MSG0008 "systäme"
#define L0MSG0009 "fichier"
#define L0MSG0010 "graphique"
#define L0MSG0011 "systäme"
#define L0MSG0012 "Ö l'adresse"
#define L0MSG0013 "Erreur fatale : Signal systäme numÇro"
#define L0MSG0014 "Environnement version "
#ifdef	ABALX11
#define L0MSG0015 "Validez"
#endif
#define L0ETX "*ETX*"
#ifdef	ABALX11
#define MSGQTY    17
#else
#define MSGQTY    16
#endif
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L0messages[MSGQTY+ 8][ 39] = {
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
#ifdef	ABALX11
	L0MSG0015,
#endif
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
#ifdef	ABALX11
static char l0msg0015[] = L0MSG0015;
#endif
static char l0pad0001[] = MSG_FILLER;
static char l0pad0002[] = MSG_FILLER;
static char l0pad0003[] = MSG_FILLER;
static char l0pad0004[] = MSG_FILLER;
static char l0pad0005[] = MSG_FILLER;
static char l0pad0006[] = MSG_FILLER;
static char l0pad0007[] = MSG_FILLER;
static char l0pad0008[] = MSG_FILLER;
static char l0etx[] = L0ETX;
#endif
/* Start of Message Texts : Language 1 */
#define L1STX "*STX*3EXAG    21d00"
#define L1MSG0001 "yn1"
#define L1MSG0002 "ABAL Executer "
#define L1MSG0003 "Error"
#define L1MSG0004 "I/O"
#define L1MSG0005 "system"
#define L1MSG0006 "syntax"
#define L1MSG0007 "file"
#define L1MSG0008 "system"
#define L1MSG0009 "file"
#define L1MSG0010 "graphic"
#define L1MSG0011 "system"
#define L1MSG0012 "at addres"
#define L1MSG0013 "Fatal error : System signal number "
#define L1MSG0014 "Environnement version "
#ifdef	ABALX11
#define L1MSG0015 "Press Enter"
#endif
#define L1ETX "*ETX*"
#ifdef	ABALX11
#define MSGQTY    17
#else
#define MSGQTY    16
#endif
#define MSG_FILLER "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#ifdef   MSG_HX
unsigned char L1messages[MSGQTY+ 8][ 37] = {
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
#ifdef	ABALX11
	L1MSG0015,
#endif
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
#ifdef	ABALX11
static char l1msg0015[] = L1MSG0015;
#endif
static char l1pad0001[] = MSG_FILLER;
static char l1pad0002[] = MSG_FILLER;
static char l1pad0003[] = MSG_FILLER;
static char l1pad0004[] = MSG_FILLER;
static char l1pad0005[] = MSG_FILLER;
static char l1pad0006[] = MSG_FILLER;
static char l1pad0007[] = MSG_FILLER;
static char l1pad0008[] = MSG_FILLER;
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
