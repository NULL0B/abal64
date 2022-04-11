#define	begmesman   "*STX*3GENMAKEG21a00"
#define	YesNoMsg      "yn0"

/*	Messages and banner strings	*/
/*	---------------------------	*/
#define	gmtalk0001 "ABAL++ makefile generation utility   Version "
#define	gmtalk0002 "Syntaxe" 
#define	gmtalk0003 "Analysis of all included files "
#define	gmtalk0004 "Source type ABAL++ (program or object) "
#define	gmtalk0005 "Specification of Source->Object <syntax> "
#define	gmtalk0006 "Generate included file list to <filename> "
#define	gmtalk0007 "Echo all sources to standard output "
#define	gmtalk0008 "Generate indented list of included files "
#define	gmtalk0009 "Include_File search path componant "
#define	gmtalk0010 "Specification of Object->Result <syntax> "
#define	gmtalk0011 "Generate to amake compatible makefile "
#define	gmtalk0012 "Specification of compiler, linker or library options "
#define	gmtalk0013 "Specification of Result <filename> "
#define	gmtalk0014 "Supress transient error messages "
#define	gmtalk0015 "Supress <Action Field> and Symbols "
#define	gmtalk0016 "Generate object group symbol "
#define	gmtalk0017 "Declaration of an elimination group "
#define	gmtalk0018 " file1 ... fileN "
#define gmtalk0019 "Memory allocation error"
#define gmtalk0020 "Error opening file"

/*	Research tokens		*/
/*	---------------		*/
#define	gmtalk0021 "program"
#define	gmtalk0022 "module"
#define	gmtalk0023 "extern"
#define	gmtalk0024 "#include"
#define	gmtalk0025 "#user"
#define	gmtalk0026 "#use"
#define	gmtalk0027 " "
#define	gmtalk0028 " "
#define	gmtalk0029 " "


/*	Tokens used to Generate makefile 	*/
/*	--------------------------------	*/
#define	gmtalk0030 "$(COMPILE)"
#define	gmtalk0031 "$(OPTION)"

#define	gmtalk0032 "$(LINKER)"
#define	gmtalk0033 "$(LINKOPT)"
#define gmtalk0034 "$(LIBRARY)"

#define	gmtalk0035 "$(SP"
#define	gmtalk0036 "$(POBJ)"
#define	gmtalk0037 "$(PBIN)"
#define	gmtalk0038 "$(PATHBIN)"

#define	gmtalk0039 "$(OBJ)"
#define	gmtalk0040 "$(EXE)"

#define	gmtalk0041 "cc -c "
#define	gmtalk0042 "cc -o "
#define gmtalk0043 "atr "
#ifdef	UNIX
#define gmtalk0044 "ald -D"
#else
#define gmtalk0044 "ald /D"
#endif

#ifdef PRL
#define gmtalk0045 "-o"
#define gmtalk0046 "-at"
#else
#define gmtalk0045 ".o"
#define gmtalk0046 ".at"
#endif

#define gmtalk0047 "make"
#define gmtalk0048 "Symbole"
#define gmtalk0049 "Fichier"
#define gmtalk0050 " "
#define gmtalk0051 "Elimination group limit exceeded "
#define gmtalk0052 "Search path limit exceeded "
#define gmtalk0053 ".obj"
#define	exafill0001 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define	endmesman "*ETX*"

#ifndef  MSG_HX
static	char	BegMesMan[]   = begmesman;
static	char	YesNo[]       = YesNoMsg;
static	char	GmTalk0001[]  = gmtalk0001;
static  char	GmTalk0002[]  = gmtalk0002;
static  char	GmTalk0003[]  = gmtalk0003;
static  char	GmTalk0004[]  = gmtalk0004;
static  char	GmTalk0005[]  = gmtalk0005;
static  char	GmTalk0006[]  = gmtalk0006;
static  char	GmTalk0007[]  = gmtalk0007;
static  char	GmTalk0008[]  = gmtalk0008;
static  char	GmTalk0009[]  = gmtalk0009;

static  char	GmTalk0010[]  = gmtalk0010;
static	char	GmTalk0011[]  = gmtalk0011;
static  char	GmTalk0012[]  = gmtalk0012;
static  char	GmTalk0013[]  = gmtalk0013;
static  char	GmTalk0014[]  = gmtalk0014;
static  char	GmTalk0015[]  = gmtalk0015;
static  char	GmTalk0016[]  = gmtalk0016;
static  char	GmTalk0017[]  = gmtalk0017;
static  char	GmTalk0018[]  = gmtalk0018;
static  char	GmTalk0019[]  = gmtalk0019;

static  char	GmTalk0020[]  = gmtalk0020;
static	char	GmTalk0021[]  = gmtalk0021;
static  char	GmTalk0022[]  = gmtalk0022;
static  char	GmTalk0023[]  = gmtalk0023;
static  char	GmTalk0024[]  = gmtalk0024;
static  char	GmTalk0025[]  = gmtalk0025;
static  char	GmTalk0026[]  = gmtalk0026;
static  char	GmTalk0027[]  = gmtalk0027;
static  char	GmTalk0028[]  = gmtalk0028;
static  char	GmTalk0029[]  = gmtalk0029;

static  char	GmTalk0030[]  = gmtalk0030;
static	char	GmTalk0031[]  = gmtalk0031;
static  char	GmTalk0032[]  = gmtalk0032;
static  char	GmTalk0033[]  = gmtalk0033;
static  char	GmTalk0034[]  = gmtalk0034;
static  char	GmTalk0035[]  = gmtalk0035;
static  char	GmTalk0036[]  = gmtalk0036;
static  char	GmTalk0037[]  = gmtalk0037;
static  char	GmTalk0038[]  = gmtalk0038;
static  char	GmTalk0039[]  = gmtalk0039;

static  char	GmTalk0040[]  = gmtalk0040;
static	char	GmTalk0041[]  = gmtalk0041;
static  char	GmTalk0042[]  = gmtalk0042;
static  char	GmTalk0043[]  = gmtalk0043;
static  char	GmTalk0044[]  = gmtalk0044;
static  char	GmTalk0045[]  = gmtalk0045;
static  char	GmTalk0046[]  = gmtalk0046;
static  char	GmTalk0047[]  = gmtalk0047;
static  char	GmTalk0048[]  = gmtalk0048;
static  char	GmTalk0049[]  = gmtalk0049;

static  char	GmTalk0050[]  = gmtalk0050;
static  char	GmTalk0051[]  = gmtalk0051;
static  char	GmTalk0052[]  = gmtalk0052;
static  char	GmTalk0053[]  = gmtalk0053;

static	char	ExaFill0001[] = exafill0001;
static	char	ExaFill0002[] = exafill0001;
static	char	ExaFill0003[] = exafill0001;
static	char	ExaFill0004[] = exafill0001;
static	char	ExaFill0005[] = exafill0001;
static	char	ExaFill0006[] = exafill0001;
static	char	ExaFill0007[] = exafill0001;
static	char	ExaFill0008[] = exafill0001;
static	char	ExaFill0009[] = exafill0001;
static	char	ExaFill0010[] = exafill0001;
static	char	ExaFill0012[] = exafill0001;
static	char	ExaFill0013[] = exafill0001;
static	char	ExaFill0014[] = exafill0001;
static	char	ExaFill0015[] = exafill0001;
static	char	ExaFill0016[] = exafill0001;
static	char	EndMesMan[]   = endmesman;

#else

/*	Message structure for RISC and M68XXX (Greenhills)	*/
/*	--------------------------------------------------	*/
static char  gmtalk[MSGQTY+16+1][78] = {

	begmesman,YesNoMsg,

 		   gmtalk0001,gmtalk0002,gmtalk0003,gmtalk0004,
	gmtalk0005,gmtalk0006,gmtalk0007,gmtalk0008,gmtalk0009,

 	gmtalk0010,gmtalk0011,gmtalk0012,gmtalk0013,gmtalk0014,
	gmtalk0015,gmtalk0016,gmtalk0017,gmtalk0018,gmtalk0019,

 	gmtalk0020,gmtalk0021,gmtalk0022,gmtalk0023,gmtalk0024,
	gmtalk0025,gmtalk0026,gmtalk0027,gmtalk0028,gmtalk0029,

 	gmtalk0030,gmtalk0031,gmtalk0032,gmtalk0033,gmtalk0034,
	gmtalk0035,gmtalk0036,gmtalk0037,gmtalk0038,gmtalk0039,

 	gmtalk0040,gmtalk0041,gmtalk0042,gmtalk0043,gmtalk0044,
	gmtalk0045,gmtalk0046,gmtalk0047,gmtalk0048,gmtalk0049,

	gmtalk0050,gmtalk0051,gmtalk0052,gmtalk0053,

	exafill0001,exafill0001,exafill0001,exafill0001,
	exafill0001,exafill0001,exafill0001,exafill0001,
	exafill0001,exafill0001,exafill0001,exafill0001,
	exafill0001,exafill0001,exafill0001,exafill0001,

	endmesman

	};

#endif

