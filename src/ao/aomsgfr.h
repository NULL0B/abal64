
#define	debgesmes   "*STX*3AOF     21a00"
#define	OuiNonMsg   "on0"

/*	Messages and banner strings	*/
/*	---------------------------	*/
#define	aoparl0001 "   ABAL++ Post Optimiseur   Version "
#define	aoparl0002 "Optimisation : " 
#define	aoparl0003 "Erreur a la traduction"
#define	aoparl0004 "Optimisation a effectuer apres l'edition des liens "
#define	aoparl0005 "Optimisation d'un module impossible"
#define	aoparl0006 "Tcode inconnu"
#define	aoparl0007 "a deja ete optimise"
#define	aoparl0008 "Version ABAL++ incorrecte"
#define	aoparl0009 " "
#define	aoparl0010 " : Fichier Tcode incorrecte"
#define	aoparl0011 "Erreur de suivie des registres"
#define	aoparl0012 "reduit : "
#define	aoparl0013 " de "
#define	aoparl0014 " en "
#define	aoparl0015 " Table des Procedures : "
#define	aoparl0016 " Erreur de chargement des constantes"
#define	aoparl0017 " Erreur de chargement variables globales" 
#define	aoparl0018 " Erreur de creation de l'image des donnees"
#define aoparl0019 " Erreur de chargement Table des Procedures"
#define aoparl0020 " Erreur de chargement Table des Segments"
#define	aoparl0021 " Programme "
#define	aoparl0022 " Reduction totale : "
#define	aoparl0023 " Erreur lecture fichier "
#define	aoparl0024 " Erreur d'ouverture fichier "
#define	aoparl0025 " Erreur de supression fichier "
#define	aoparl0026 " Erreur de renommage fichier "
#define	aoparl0027 " Erreur de creation fichier "
#define	aoparl0028 " "
#define	aoparl0029 " "
#define	aoparl0030 " "
#define	aoparl0031 "   Options :  -ovw23"
#define	aoparl0032 "      o    :  activer optimisation niveau 1 "
#define	aoparl0033 "      2    :  niveau 2 optimisation des procedures "
#define	aoparl0034 "      3    :  niveau 3 optimisation des segments "
#define	aoparl0035 "      v    :  activer mode verbose"
#define	aoparl0036 "      w    :  activer messages d'avertissement"

#define	aoremp0001 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define	fingesmes "*ETX*"

#ifndef  MSG_HX
static	char	DebGesMes[]   = debgesmes;
static	char	OuiNon[]      = OuiNonMsg;
static	char	AoParl0001[]  = aoparl0001;
static  char	AoParl0002[]  = aoparl0002;
static  char	AoParl0003[]  = aoparl0003;
static  char	AoParl0004[]  = aoparl0004;
static  char	AoParl0005[]  = aoparl0005;
static  char	AoParl0006[]  = aoparl0006;
static  char	AoParl0007[]  = aoparl0007;
static  char	AoParl0008[]  = aoparl0008;
static  char	AoParl0009[]  = aoparl0009;

static  char	AoParl0010[]  = aoparl0010;
static	char	AoParl0011[]  = aoparl0011;
static  char	AoParl0012[]  = aoparl0012;
static  char	AoParl0013[]  = aoparl0013;
static  char	AoParl0014[]  = aoparl0014;
static  char	AoParl0015[]  = aoparl0015;
static  char	AoParl0016[]  = aoparl0016;
static  char	AoParl0017[]  = aoparl0017;
static  char	AoParl0018[]  = aoparl0018;
static  char	AoParl0019[]  = aoparl0019;

static  char	AoParl0020[]  = aoparl0020;
static	char	AoParl0021[]  = aoparl0021;
static  char	AoParl0022[]  = aoparl0022;
static  char	AoParl0023[]  = aoparl0023;
static  char	AoParl0024[]  = aoparl0024;
static  char	AoParl0025[]  = aoparl0025;
static  char	AoParl0026[]  = aoparl0026;
static  char	AoParl0027[]  = aoparl0027;
static  char	AoParl0028[]  = aoparl0028;
static  char	AoParl0029[]  = aoparl0029;
static  char	AoParl0030[]  = aoparl0030;
static  char	AoParl0031[]  = aoparl0031;
static  char	AoParl0032[]  = aoparl0032;
static  char	AoParl0033[]  = aoparl0033;
static  char	AoParl0034[]  = aoparl0034;
static  char	AoParl0035[]  = aoparl0035;
static  char	AoParl0036[]  = aoparl0036;

static	char	AoRemp0001[] = aoremp0001;
static	char	AoRemp0002[] = aoremp0001;
static	char	AoRemp0003[] = aoremp0001;
static	char	AoRemp0004[] = aoremp0001;
static	char	AoRemp0005[] = aoremp0001;
static	char	AoRemp0006[] = aoremp0001;
static	char	AoRemp0007[] = aoremp0001;
static	char	AoRemp0008[] = aoremp0001;
static	char	AoRemp0009[] = aoremp0001;
static	char	AoRemp0010[] = aoremp0001;
static	char	AoRemp0012[] = aoremp0001;
static	char	AoRemp0013[] = aoremp0001;
static	char	AoRemp0014[] = aoremp0001;
static	char	AoRemp0015[] = aoremp0001;
static	char	AoRemp0016[] = aoremp0001;
static	char	FinGesMes[]   = fingesmes;

#else

/*	Message structure for RISC and M68XXX (Greenhills)	*/
/*	--------------------------------------------------	*/
static char  aoparl[MSGQTY+16+1][60] = {

	debgesmes,OuiNonMsg,

 		   aoparl0001,aoparl0002,aoparl0003,aoparl0004,
	aoparl0005,aoparl0006,aoparl0007,aoparl0008,aoparl0009,

 	aoparl0010,aoparl0011,aoparl0012,aoparl0013,aoparl0014,
	aoparl0015,aoparl0016,aoparl0017,aoparl0018,aoparl0019,

 	aoparl0020,aoparl0021,aoparl0022,aoparl0023,aoparl0024,
	aoparl0025,aoparl0026,aoparl0027,aoparl0028,aoparl0029,

 	aoparl0030, aoparl0031, aoparl0032, aoparl0033, aoparl0034, 
	aoparl0035, aoparl0036, 

	aoremp0001,aoremp0001,aoremp0001,aoremp0001,
	aoremp0001,aoremp0001,aoremp0001,aoremp0001,
	aoremp0001,aoremp0001,aoremp0001,aoremp0001,
	aoremp0001,aoremp0001,aoremp0001,aoremp0001,

	fingesmes

	};

#endif

