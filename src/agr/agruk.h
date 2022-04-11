#define	ukdeb     "*STX*3AGRG    21g00"
#define	YesNoMsg  "on0"
#define	UK_Z "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define	ukfin     "*ETX*"



#define UK_MSG_1 "Source file browsing utility"
#define UK_MSG_2 "Version"
#define UK_MSG_3 "Options"
#define UK_MSG_4 "-a<filename>      : convert and trace error file"
#define UK_MSG_5 "-c                : force case sensitive compare"
#define UK_MSG_6 "-e<editor>        : specify trace editor"
#define UK_MSG_7 "-g                : generate trace list only"
#define UK_MSG_8 "-i                : analysis of inclusions"
#define UK_MSG_9 "-l                : list matching lines to stdout"
#define UK_MSG_10 "-s<pattern>       : specify search pattern"
#define UK_MSG_11 "-t<filename>      : specify explicite trace file"
#define UK_MSG_12 "-v                : activate verbose mode"
#define UK_MSG_13 "-w                : allow trace of warnings"
#define UK_MSG_14 "-x                : quantify matched patterns"
#define UK_MSG_15 "Error"
#define UK_MSG_16 "No match found"

#ifndef  MSG_HX

static	char	UkDebut[]     = ukdeb;
static	char	YesNo[]       = YesNoMsg;

static	char	UK_1[]   = UK_MSG_1;
static  char	UK_2[]   = UK_MSG_2;
static  char	UK_3[]   = UK_MSG_3;
static  char	UK_4[]   = UK_MSG_4;
static  char	UK_5[]   = UK_MSG_5;
static  char	UK_6[]   = UK_MSG_6;
static  char	UK_7[]   = UK_MSG_7;
static  char	UK_8[]   = UK_MSG_8;
static  char	UK_9[]   = UK_MSG_9;
static  char	UK_10[]  = UK_MSG_10;
static  char	UK_11[]  = UK_MSG_11;
static  char	UK_12[]  = UK_MSG_12;
static  char	UK_13[]  = UK_MSG_13;
static  char	UK_14[]  = UK_MSG_14;
static  char	UK_15[]  = UK_MSG_15;
static  char	UK_16[]  = UK_MSG_16;


static	char	UK_Z1[]   = UK_Z;
static	char	UK_Z2[]   = UK_Z;
static	char	UK_Z3[]   = UK_Z;
static	char	UK_Z4[]   = UK_Z;
static	char	UK_Z5[]   = UK_Z;
static	char	UK_Z6[]   = UK_Z;
static	char	UK_Z7[]   = UK_Z;
static	char	UK_Z8[]   = UK_Z;
static	char	UK_Z9[]   = UK_Z;
static	char	UK_ZA[]   = UK_Z;
static	char	UK_ZB[]   = UK_Z;
static	char	UK_ZC[]   = UK_Z;
static	char	UK_ZD[]   = UK_Z;
static	char	UK_ZE[]   = UK_Z;
static	char	UK_ZF[]   = UK_Z;
static	char	UK_ZG[]   = UK_Z;

static	char	UkFin[]     = ukfin;

#else

static char  UK_TALK[ MSGQTY+16 +3][ 50 ] = {

	ukdeb   , YesNoMsg,

	UK_MSG_1 , UK_MSG_2 , UK_MSG_3 , UK_MSG_4 , UK_MSG_5 ,
	UK_MSG_6 , UK_MSG_7 , UK_MSG_8 , UK_MSG_9 , UK_MSG_10,
	UK_MSG_11, UK_MSG_12, UK_MSG_13, UK_MSG_14, UK_MSG_15,
	UK_MSG_16, 

	UK_Z, UK_Z, UK_Z, UK_Z,
	UK_Z, UK_Z, UK_Z, UK_Z,
	UK_Z, UK_Z, UK_Z, UK_Z,
	UK_Z, UK_Z, UK_Z, UK_Z,

	ukfin

	};

#endif
