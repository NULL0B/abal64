/* Start of Message Texts : Language 0 : FRANCAIS */

#define L0STX		"*STX*3OTRF    30e01"
#define L0MSG0000	"on0"
#define L0MSG0001 "ABAL++ Linker Objet"
#define L0MSG0002	"Erreur"
#define L0MSG0003	"Avertissement"
#define L0MSG0004	"Trace source"
#define L0MSG0005	"Trace cible"
#define L0MSG0006	"Linker"
#define L0MSG0007	"SystŠme"
#define L0MSG0008	"Solution"
#define L0MSG0009 "dcl externe inutilis‚"
#define L0MSG0010 "ABAL3: Edition des liens..."
#define L0MSG0011 "Cible en cours d'utilisation"
#define L0ETX		"*ETX*"

#define MSGQTY    14

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

#define L1STX		"*STX*3OTRG    30e01"
#define L1MSG0000 "yn0"
#define L1MSG0001 "ABAL++ Object Linker"
#define L1MSG0002 "Error"
#define L1MSG0003 "Warning"
#define L1MSG0004	"Source trace"
#define L1MSG0005	"Target trace"
#define L1MSG0006	"Linker"
#define L1MSG0007	"System"
#define L1MSG0008	"Solution"
#define L1MSG0009 "Unused extern dcl"
#define L1MSG0010 "ABAL3: Linking..."
#define L1MSG0011 "Target still busy"
#define L1ETX		"*ETX*"

#define MSGQTY    14

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
