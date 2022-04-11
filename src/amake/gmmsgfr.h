#define	debgesmes   "*STX*3GENMAKEF21a00"
#define	OuiNonMsg   "on0"

/*	Messages and banner strings	*/
/*	---------------------------	*/
#define	gmparl0001 "G‚n‚rateur de fichier de description de projet ABAL   Version " 
#define	gmparl0002 "Syntaxe"                                                        
#define	gmparl0003 "Parcours de tous les fichiers inclus "                          
#define	gmparl0004 "Source ABAL++ (programme ou module) "                             
#define	gmparl0005 "Syntaxe de la traduction/compilation "                          
#define	gmparl0006 "Genere la liste des fichiers inclus vers <fichier> "            
#define	gmparl0007 "Affiche tous les sources sur la sortie standard "               
#define	gmparl0008 "GenŠre une liste indent‚e des fichiers inclus "                 
#define	gmparl0009 "R‚pertoire de recherche des fichiers inclus "                   
#define	gmparl0010 "Syntaxe de l'‚dition de liens "                                 
#define	gmparl0011 "G‚n‚ration vers un fichier compatible AMAKE "                   
#define	gmparl0012 "Options de compilation/‚dition de liens "                       
#define	gmparl0013 "D‚nomination du r‚sultat <fichier> "                            
#define	gmparl0014 "Suppression des messages d'erreurs superflus "                  
#define	gmparl0015 "Ne g‚nŠre pas d'action ni de macro "                            
#define	gmparl0016 "G‚nŠre une macro de groupe d'objets "                           
#define	gmparl0017 "Liste les fichiers … exclure "                                  
#define	gmparl0018 " fichier1 ... fichierN "                                        
#define gmparl0019 "Erreur d'allocation m‚moire"                                    
#define gmparl0020 "Ouverture fichier impossible"                                   

/*	Research tokens		*/
/*	---------------		*/
#define	gmparl0021 "program"
#define	gmparl0022 "module"
#define	gmparl0023 "extern"
#define	gmparl0024 "#include"
#define	gmparl0025 "#user"
#define	gmparl0026 "#use"
#define	gmparl0027 " "
#define	gmparl0028 " "
#define	gmparl0029 " "


/*	Tokens used to Generate makefile 	*/
/*	--------------------------------	*/
#define	gmparl0030 "$(COMPILE)"
#define	gmparl0031 "$(OPTION)"

#define	gmparl0032 "$(LINKER)"
#define	gmparl0033 "$(LINKOPT)"
#define gmparl0034 "$(LIBRARY)"

#define	gmparl0035 "$(SP"
#define	gmparl0036 "$(POBJ)"
#define	gmparl0037 "$(PBIN)"
#define	gmparl0038 "$(PATHBIN)"

#define	gmparl0039 "$(OBJ)"
#define	gmparl0040 "$(EXE)"

#define	gmparl0041 "cc -c "
#define	gmparl0042 "cc -o "
#define gmparl0043 "atr "
#ifdef	UNIX
#define gmparl0044 "ald -D"
#else
#define gmparl0044 "ald /D"
#endif

#ifdef PRL
#define gmparl0045 "-o"
#define gmparl0046 "-at"
#else
#define gmparl0045 ".o"
#define gmparl0046 ".at"
#endif

#define gmparl0047 "make"
#define gmparl0048 "Symbole"
#define gmparl0049 "Fichier"
#define gmparl0050 " "
#define gmparl0051 "D‚bordement capacit‚ de groupage "
#define gmparl0052 "D‚bordement du chemin de recherche "
#define gmparl0053 ".obj"
#define	exaremp0001 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define	fingesmes "*ETX*"

#ifndef  MSG_HX
static	char	DebGesMes[]   = debgesmes;
static	char	OuiNon[]      = OuiNonMsg;
static	char	GmParl0001[]  = gmparl0001;
static  char	GmParl0002[]  = gmparl0002;
static  char	GmParl0003[]  = gmparl0003;
static  char	GmParl0004[]  = gmparl0004;
static  char	GmParl0005[]  = gmparl0005;
static  char	GmParl0006[]  = gmparl0006;
static  char	GmParl0007[]  = gmparl0007;
static  char	GmParl0008[]  = gmparl0008;
static  char	GmParl0009[]  = gmparl0009;

static  char	GmParl0010[]  = gmparl0010;
static	char	GmParl0011[]  = gmparl0011;
static  char	GmParl0012[]  = gmparl0012;
static  char	GmParl0013[]  = gmparl0013;
static  char	GmParl0014[]  = gmparl0014;
static  char	GmParl0015[]  = gmparl0015;
static  char	GmParl0016[]  = gmparl0016;
static  char	GmParl0017[]  = gmparl0017;
static  char	GmParl0018[]  = gmparl0018;
static  char	GmParl0019[]  = gmparl0019;

static  char	GmParl0020[]  = gmparl0020;
static	char	GmParl0021[]  = gmparl0021;
static  char	GmParl0022[]  = gmparl0022;
static  char	GmParl0023[]  = gmparl0023;
static  char	GmParl0024[]  = gmparl0024;
static  char	GmParl0025[]  = gmparl0025;
static  char	GmParl0026[]  = gmparl0026;
static  char	GmParl0027[]  = gmparl0027;
static  char	GmParl0028[]  = gmparl0028;
static  char	GmParl0029[]  = gmparl0029;

static  char	GmParl0030[]  = gmparl0030;
static	char	GmParl0031[]  = gmparl0031;
static  char	GmParl0032[]  = gmparl0032;
static  char	GmParl0033[]  = gmparl0033;
static  char	GmParl0034[]  = gmparl0034;
static  char	GmParl0035[]  = gmparl0035;
static  char	GmParl0036[]  = gmparl0036;
static  char	GmParl0037[]  = gmparl0037;
static  char	GmParl0038[]  = gmparl0038;
static  char	GmParl0039[]  = gmparl0039;

static  char	GmParl0040[]  = gmparl0040;
static	char	GmParl0041[]  = gmparl0041;
static  char	GmParl0042[]  = gmparl0042;
static  char	GmParl0043[]  = gmparl0043;
static  char	GmParl0044[]  = gmparl0044;
static  char	GmParl0045[]  = gmparl0045;
static  char	GmParl0046[]  = gmparl0046;
static  char	GmParl0047[]  = gmparl0047;
static  char	GmParl0048[]  = gmparl0048;
static  char	GmParl0049[]  = gmparl0049;

static  char	GmParl0050[]  = gmparl0050;
static  char	GmParl0051[]  = gmparl0051;
static  char	GmParl0052[]  = gmparl0052;
static  char	GmParl0053[]  = gmparl0053;

static	char	ExaRemp0001[] = exaremp0001;
static	char	ExaRemp0002[] = exaremp0001;
static	char	ExaRemp0003[] = exaremp0001;
static	char	ExaRemp0004[] = exaremp0001;
static	char	ExaRemp0005[] = exaremp0001;
static	char	ExaRemp0006[] = exaremp0001;
static	char	ExaRemp0007[] = exaremp0001;
static	char	ExaRemp0008[] = exaremp0001;
static	char	ExaRemp0009[] = exaremp0001;
static	char	ExaRemp0010[] = exaremp0001;
static	char	ExaRemp0012[] = exaremp0001;
static	char	ExaRemp0013[] = exaremp0001;
static	char	ExaRemp0014[] = exaremp0001;
static	char	ExaRemp0015[] = exaremp0001;
static	char	ExaRemp0016[] = exaremp0001;
static	char	FinGesMes[]   = fingesmes;

#else

/*	Message structure for RISC and M68XXX (Greenhills)	*/
/*	--------------------------------------------------	*/
static char  gmparl[MSGQTY+16+1][78] = {

	debgesmes,OuiNonMsg,

 		   gmparl0001,gmparl0002,gmparl0003,gmparl0004,
	gmparl0005,gmparl0006,gmparl0007,gmparl0008,gmparl0009,

 	gmparl0010,gmparl0011,gmparl0012,gmparl0013,gmparl0014,
	gmparl0015,gmparl0016,gmparl0017,gmparl0018,gmparl0019,

 	gmparl0020,gmparl0021,gmparl0022,gmparl0023,gmparl0024,
	gmparl0025,gmparl0026,gmparl0027,gmparl0028,gmparl0029,

 	gmparl0030,gmparl0031,gmparl0032,gmparl0033,gmparl0034,
	gmparl0035,gmparl0036,gmparl0037,gmparl0038,gmparl0039,

 	gmparl0040,gmparl0041,gmparl0042,gmparl0043,gmparl0044,
	gmparl0045,gmparl0046,gmparl0047,gmparl0048,gmparl0049,

	gmparl0050,gmparl0051,gmparl0052,gmparl0053,

	exaremp0001,exaremp0001,exaremp0001,exaremp0001,
	exaremp0001,exaremp0001,exaremp0001,exaremp0001,
	exaremp0001,exaremp0001,exaremp0001,exaremp0001,
	exaremp0001,exaremp0001,exaremp0001,exaremp0001,

	fingesmes

	};

#endif

