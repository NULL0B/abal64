#define	begmesman   "*STX*3AOG     21a00"
#define	YesNoMsg    "on0"

/*	Messages and banner strings	*/
/*	---------------------------	*/
#define	aotalk0001 "   ABAL++ Post Optimiser    Version "
#define	aotalk0002 "Optimising : " 
#define	aotalk0003 "Translator phase terminated incorrectly "
#define	aotalk0004 "Optimisation must be performed after the link phase "
#define	aotalk0005 "Pre-Link Optimisation of Modules is not possible "
#define	aotalk0006 "Unknown T-Code Status "
#define	aotalk0007 "has already been optimised "
#define	aotalk0008 "Incorrect ABAL++ Version "
#define	aotalk0009 " "
#define	aotalk0010 " : Incorrect Tcode File "
#define	aotalk0011 "Register shadowing error"
#define	aotalk0012 "optimised : "
#define	aotalk0013 " from "
#define	aotalk0014 " to "
#define	aotalk0015 " Procedure Table : "
#define	aotalk0016 " Error loading constants "
#define	aotalk0017 " Error loading global variables" 
#define	aotalk0018 " Error creating global variable image"
#define aotalk0019 " Error loading Procedure Table "
#define aotalk0020 " Error loading Segment Table "
#define	aotalk0021 " Program "
#define	aotalk0022 " Tcode Reduced by : "
#define	aotalk0023 " Error reading Control sector "
#define	aotalk0024 " Error opening file : "
#define	aotalk0025 " Error deleting file : "
#define	aotalk0026 " Error renaming file : "
#define	aotalk0027 " Error creating file : "
#define	aotalk0028 " "
#define	aotalk0029 " "
#define	aotalk0030 " "
#define	aotalk0031 "   Options :  -ovw23"
#define	aotalk0032 "      o    :  activate optimisation level 1 "
#define	aotalk0033 "      2    :  level 2 optimisation of procedures "
#define	aotalk0034 "      3    :  level 3 optimisation of segments "
#define	aotalk0035 "      v    :  activate information messages "
#define	aotalk0036 "      w    :  activate warning messages "

#define	aofill0001 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define	endmesman "*ETX*"

#ifndef  MSG_HX
static	char	BegMesMan[]   = begmesman;
static	char	YesNo[]       = YesNoMsg;
static	char	AoTalk0001[]  = aotalk0001;
static  char	AoTalk0002[]  = aotalk0002;
static  char	AoTalk0003[]  = aotalk0003;
static  char	AoTalk0004[]  = aotalk0004;
static  char	AoTalk0005[]  = aotalk0005;
static  char	AoTalk0006[]  = aotalk0006;
static  char	AoTalk0007[]  = aotalk0007;
static  char	AoTalk0008[]  = aotalk0008;
static  char	AoTalk0009[]  = aotalk0009;

static  char	AoTalk0010[]  = aotalk0010;
static	char	AoTalk0011[]  = aotalk0011;
static  char	AoTalk0012[]  = aotalk0012;
static  char	AoTalk0013[]  = aotalk0013;
static  char	AoTalk0014[]  = aotalk0014;
static  char	AoTalk0015[]  = aotalk0015;
static  char	AoTalk0016[]  = aotalk0016;
static  char	AoTalk0017[]  = aotalk0017;
static  char	AoTalk0018[]  = aotalk0018;
static  char	AoTalk0019[]  = aotalk0019;

static  char	AoTalk0020[]  = aotalk0020;
static	char	AoTalk0021[]  = aotalk0021;
static  char	AoTalk0022[]  = aotalk0022;
static  char	AoTalk0023[]  = aotalk0023;
static  char	AoTalk0024[]  = aotalk0024;
static  char	AoTalk0025[]  = aotalk0025;
static  char	AoTalk0026[]  = aotalk0026;
static  char	AoTalk0027[]  = aotalk0027;
static  char	AoTalk0028[]  = aotalk0028;
static  char	AoTalk0029[]  = aotalk0029;
static  char	AoTalk0030[]  = aotalk0030;
static  char	AoTalk0031[]  = aotalk0031;
static  char	AoTalk0032[]  = aotalk0032;
static  char	AoTalk0033[]  = aotalk0033;
static  char	AoTalk0034[]  = aotalk0034;
static  char	AoTalk0035[]  = aotalk0035;
static  char	AoTalk0036[]  = aotalk0036;

static	char	AoFill0001[] = aofill0001;
static	char	AoFill0002[] = aofill0001;
static	char	AoFill0003[] = aofill0001;
static	char	AoFill0004[] = aofill0001;
static	char	AoFill0005[] = aofill0001;
static	char	AoFill0006[] = aofill0001;
static	char	AoFill0007[] = aofill0001;
static	char	AoFill0008[] = aofill0001;
static	char	AoFill0009[] = aofill0001;
static	char	AoFill0010[] = aofill0001;
static	char	AoFill0012[] = aofill0001;
static	char	AoFill0013[] = aofill0001;
static	char	AoFill0014[] = aofill0001;
static	char	AoFill0015[] = aofill0001;
static	char	AoFill0016[] = aofill0001;
static	char	EndMesMan[]   = endmesman;

#else

/*	Message structure for RISC and M68XXX (Greenhills)	*/
/*	--------------------------------------------------	*/
static char  aotalk[MSGQTY+16+1][60] = {

	begmesman,YesNoMsg,

 		   aotalk0001,aotalk0002,aotalk0003,aotalk0004,
	aotalk0005,aotalk0006,aotalk0007,aotalk0008,aotalk0009,

 	aotalk0010,aotalk0011,aotalk0012,aotalk0013,aotalk0014,
	aotalk0015,aotalk0016,aotalk0017,aotalk0018,aotalk0019,

 	aotalk0020,aotalk0021,aotalk0022,aotalk0023,aotalk0024,
	aotalk0025,aotalk0026,aotalk0027,aotalk0028,aotalk0029,

 	aotalk0030, aotalk0031, aotalk0032, aotalk0033, aotalk0034, 
	aotalk0035, aotalk0036, 

	aofill0001,aofill0001,aofill0001,aofill0001,
	aofill0001,aofill0001,aofill0001,aofill0001,
	aofill0001,aofill0001,aofill0001,aofill0001,
	aofill0001,aofill0001,aofill0001,aofill0001,

	endmesman

	};

#endif

