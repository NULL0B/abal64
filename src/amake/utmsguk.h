#define	begmesman   "*STX*3AMAKEB  21a00"
#define	YesNoMsg    "yn0"
#define	uttalk0001 "ABAL++ program maintanance utility   Version "
#define	uttalk0002 "don't know how to make: "
#define	uttalk0003 "file does not exist: "
#define	uttalk0004 "illegal recursivity "
#define	uttalk0005 "unknown macro definition: "
#define	uttalk0006 "unexpected end of string "
#define	uttalk0007 "Internal Error # 1 "
#define	uttalk0008 "Internal Error # 2 "
#define uttalk0009 "Target     : "
#define uttalk0010 "Dependance : "
#define uttalk0011 "touching file : "
#define uttalk0012 "include file not found : "
#define	uttalk0013 "   Options : "
#define	uttalk0014 "     -a    : Makefile parameters follow "
#define	uttalk0015 "     -b    : Rebuild all dependant targets "
#define	uttalk0016 "     -d    : Activate dependance date tracing "
#define	uttalk0017 "     -e    : Environment variables take preference "
#define	uttalk0018 "     -g    : Generate inference rules "
#define	uttalk0019 "     -i    : Ignore invocation errors "
#define	uttalk0020 "     -n    : Analyse and display without updating targets "
#define	uttalk0021 "     -o    : Allow targets with no source "
#define	uttalk0022 "     -p    : Preprocess to standard output "
#define	uttalk0023 "     -r    : Inhibit default inference rules "
#define	uttalk0024 "     -s    : Inhibit informational messages "
#define	uttalk0025 "     -t    : Touche out of date targets "
#define	uttalk0026 "     -v    : Peform verification phase "
#define	exafill0001 "\0\0\0\0\0\0\0\0"
#define	endmesman "*ETX*"

#ifndef  MSG_HX
static	CHAR	BegMesMan[]   = begmesman;
static	CHAR	YesNo[]      = YesNoMsg;
static	CHAR	UtTalk0001[]  = uttalk0001;
static  CHAR	UtTalk0002[]  = uttalk0002;
static  CHAR	UtTalk0003[]  = uttalk0003;
static  CHAR	UtTalk0004[]  = uttalk0004;
static  CHAR	UtTalk0005[]  = uttalk0005;
static  CHAR	UtTalk0006[]  = uttalk0006;
static  CHAR	UtTalk0007[]  = uttalk0007;
static  CHAR	UtTalk0008[]  = uttalk0008;
static  CHAR	UtTalk0009[]  = uttalk0009;
static  CHAR	UtTalk0010[]  = uttalk0010;
static  CHAR	UtTalk0011[]  = uttalk0011;
static  CHAR	UtTalk0012[]  = uttalk0012;
static  CHAR	UtTalk0013[]  = uttalk0013;
static  CHAR	UtTalk0014[]  = uttalk0014;
static  CHAR	UtTalk0015[]  = uttalk0015;
static  CHAR	UtTalk0016[]  = uttalk0016;
static  CHAR	UtTalk0017[]  = uttalk0017;
static  CHAR	UtTalk0018[]  = uttalk0018;
static  CHAR	UtTalk0019[]  = uttalk0019;
static  CHAR	UtTalk0020[]  = uttalk0020;
static  CHAR	UtTalk0021[]  = uttalk0021;
static  CHAR	UtTalk0022[]  = uttalk0022;
static  CHAR	UtTalk0023[]  = uttalk0023;
static  CHAR	UtTalk0024[]  = uttalk0024;
static  CHAR	UtTalk0025[]  = uttalk0025;
static  CHAR	UtTalk0026[]  = uttalk0026;
static	CHAR	ExaFill0001[] = exafill0001;
static	CHAR	ExaFill0002[] = exafill0001;
static	CHAR	ExaFill0003[] = exafill0001;
static	CHAR	ExaFill0004[] = exafill0001;
static	CHAR	ExaFill0005[] = exafill0001;
static	CHAR	ExaFill0006[] = exafill0001;
static	CHAR	ExaFill0007[] = exafill0001;
static	CHAR	ExaFill0008[] = exafill0001;
static	CHAR	ExaFill0009[] = exafill0001;
static	CHAR	ExaFill0010[] = exafill0001;
static	CHAR	ExaFill0012[] = exafill0001;
static	CHAR	ExaFill0013[] = exafill0001;
static	CHAR	ExaFill0014[] = exafill0001;
static	CHAR	ExaFill0015[] = exafill0001;
static	CHAR	ExaFill0016[] = exafill0001;
static	CHAR	EndMesMan[]   = endmesman;

#else

static CHAR  UtTalk[MSGQTY+16+1][70] = {
	begmesman,YesNoMsg,
	uttalk0001,uttalk0002,uttalk0003,uttalk0004,uttalk0005,
	uttalk0006,uttalk0007,uttalk0008,uttalk0009,uttalk0010,
	uttalk0011,uttalk0012,uttalk0013,uttalk0014,uttalk0015,
	uttalk0016,uttalk0017,uttalk0018,uttalk0019,uttalk0020,
	uttalk0021,uttalk0022,uttalk0023,uttalk0024,uttalk0025,
	uttalk0026,
	exafill0001,exafill0001,exafill0001,exafill0001,
	exafill0001,exafill0001,exafill0001,exafill0001,
	exafill0001,exafill0001,exafill0001,exafill0001,
	exafill0001,exafill0001,exafill0001,exafill0001,
	endmesman
	};

#endif

