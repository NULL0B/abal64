#define	frdeb     "*STX*3AGRF    21g00"
#define	OuiNonMsg "on0"
#define	FR_Z "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define	frfin	  "*ETX*"

#define FR_MSG_1 "Source fouineur"
#define FR_MSG_2 "Version"
#define FR_MSG_3 "Options"
#define FR_MSG_4 "-a<fichier>       : conversion d'un fichier d'erreurs"
#define FR_MSG_5 "-c                : respect majescules et miniscules"
#define FR_MSG_6 "-e<editeur>       : nom et chemin de l'editeur"
#define FR_MSG_7 "-g                : inhibe pointage automatique"
#define FR_MSG_8 "-i                : analyse des inclusions"
#define FR_MSG_9 "-l                : liste ecran des instances"
#define FR_MSG_10 "-s<pattern>       : pattern a rechercher"
#define FR_MSG_11 "-t<fichier>       : nom du fichier de trace"
#define FR_MSG_12 "-v                : mode verbode"
#define FR_MSG_13 "-w                : pointage des avertissements"
#define FR_MSG_14 "-x                : nombre de instances"
#define FR_MSG_15 "Erreur"
#define FR_MSG_16 "Pattern non-trouve"

#ifndef  MSG_HX

static	char	FrDeb[]  = frdeb;
static	char	OuiNon[] = OuiNonMsg;

static	char	FR_1[]   = FR_MSG_1;
static  char	FR_2[]   = FR_MSG_2;
static  char	FR_3[]   = FR_MSG_3;
static  char	FR_4[]   = FR_MSG_4;
static  char	FR_5[]   = FR_MSG_5;
static  char	FR_6[]   = FR_MSG_6;
static  char	FR_7[]   = FR_MSG_7;
static  char	FR_8[]   = FR_MSG_8;
static  char	FR_9[]   = FR_MSG_9;
static  char	FR_10[]  = FR_MSG_10;
static  char	FR_11[]  = FR_MSG_11;
static  char	FR_12[]  = FR_MSG_12;
static  char	FR_13[]  = FR_MSG_13;
static  char	FR_14[]  = FR_MSG_14;
static  char	FR_15[]  = FR_MSG_15;
static  char	FR_16[]  = FR_MSG_16;


static	char	FR_Z1[]   = FR_Z;
static	char	FR_Z2[]   = FR_Z;
static	char	FR_Z3[]   = FR_Z;
static	char	FR_Z4[]   = FR_Z;
static	char	FR_Z5[]   = FR_Z;
static	char	FR_Z6[]   = FR_Z;
static	char	FR_Z7[]   = FR_Z;
static	char	FR_Z8[]   = FR_Z;
static	char	FR_Z9[]   = FR_Z;
static	char	FR_ZA[]   = FR_Z;
static	char	FR_ZB[]   = FR_Z;
static	char	FR_ZC[]   = FR_Z;
static	char	FR_ZD[]   = FR_Z;
static	char	FR_ZE[]   = FR_Z;
static	char	FR_ZF[]   = FR_Z;
static	char	FR_ZG[]   = FR_Z;

static	char	FrFin[]	       = frfin;

#else

static char  FR_TALK[ MSGQTY+16 +3][ 50 ] = {

	frdeb   , OuiNonMsg,

	FR_MSG_1 , FR_MSG_2 , FR_MSG_3 , FR_MSG_4 , FR_MSG_5 ,
	FR_MSG_6 , FR_MSG_7 , FR_MSG_8 , FR_MSG_9 , FR_MSG_10,
	FR_MSG_11, FR_MSG_12, FR_MSG_13, FR_MSG_14, FR_MSG_15,
	FR_MSG_16, 

	FR_Z, FR_Z, FR_Z, FR_Z,
	FR_Z, FR_Z, FR_Z, FR_Z,
	FR_Z, FR_Z, FR_Z, FR_Z,
	FR_Z, FR_Z, FR_Z, FR_Z,

	frfin

	};

#endif
