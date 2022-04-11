#define	debgesmes   "*STX*3AMAKEF  21a00"
#define	OuiNonMsg   "on0"
#define	utparl0001 "Utilitaire de reconstruction ABAL   Version "                          
#define	utparl0002 "Je ne sais pas reconstruire: "                                         
#define	utparl0003 "Fichier inexistant: "                                                  
#ifndef AIX_VERS
#define	utparl0004 "R‚cursivit‚ incorrecte "                                               
#else /* AIX_VERS */
#define	utparl0004 "Recursivite incorrecte "                                               
#endif /* AIX_VERS */
#define	utparl0005 "Macro non d‚finie: "                                                   
#ifndef AIX_VERS
#define	utparl0006 "Fin de chaŒne inattendue "                                             
#else /* AIX_VERS */
#define	utparl0006 "Fin de chaine inattendue "                                             
#endif /* AIX_VERS */
#define	utparl0007 "Erreur interne # 1 "                                                   
#define	utparl0008 "Erreur interne # 2 "                                                   
#define utparl0009 "Cible      : "                                                         
#ifndef AIX_VERS
#define utparl0010 "D‚pendance : "                                                         
#define utparl0011 "Mise … jour de : "                                                     
#define utparl0012 "Fichier inclus non trouv‚"                                             
#else /* AIX_VERS */
#define utparl0010 "Dependance : "                                                         
#define utparl0011 "Mise a jour de : "                                                     
#define utparl0012 "Fichier inclus non trouve"                                             
#endif /* AIX_VERS */
#define	utparl0013 "   Options : "                                                         
#ifndef AIX_VERS
#define	utparl0014 "     -a    : Presence d'arguments sans nom de fichier "                
#else /* AIX_VERS */
#define	utparl0014 "     -a    : Presence d'arguments sans nom de fichier "                
#endif /* AIX_VERS */
#define	utparl0015 "     -b    : Reconstruction de toutes les cibles "                     
#define	utparl0016 "     -d    : Active le mode debug "                                    
#define	utparl0017 "     -e    : Regarde d'abord les variables d'environnement "           
#ifndef AIX_VERS
#define	utparl0018 "     -g    : Generation des regles par defaut "                        
#else /* AIX_VERS */
#define	utparl0018 "     -g    : Generation des regles par defaut "                        
#endif /* AIX_VERS */
#define	utparl0019 "     -i    : Ignorer les erreurs "                                     
#ifndef AIX_VERS
#define	utparl0020 "     -n    : Inhibe les actions de mise a jour "                       
#define	utparl0021 "     -o    : Permettre des cibles sans regles de dependance "          
#define	utparl0022 "     -p    : Liste des macros et regles "                              
#define	utparl0023 "     -r    : Inhiber les regles par defaut "                           
#else /* AIX_VERS */
#define	utparl0020 "     -n    : Inhibe les actions de mise a jour "                       
#define	utparl0021 "     -o    : Permettre des cibles sans regles de dependance "          
#define	utparl0022 "     -p    : Liste des macros et regles "                              
#define	utparl0023 "     -r    : Inhiber les regles par defaut "                           
#endif /* AIX_VERS */
#define	utparl0024 "     -s    : Mode silencieux "                                         
#define	utparl0025 "     -t    : Retouche les dates des cibles seulement "                 
#ifndef AIX_VERS
#define	utparl0026 "     -v    : Verification syntaxique "                                 
#else /* AIX_VERS */
#define	utparl0026 "     -v    : Verification syntaxique "                                 
#endif /* AIX_VERS */
#define	exaremp0001 "\0\0\0\0\0\0\0\0"
#define	fingesmes "*ETX*"

#ifndef  MSG_HX
static	CHAR	DebGesMes[]   = debgesmes;
static	CHAR	OuiNon[]      = OuiNonMsg;
static	CHAR	UtParl0001[]  = utparl0001;
static  CHAR	UtParl0002[]  = utparl0002;
static  CHAR	UtParl0003[]  = utparl0003;
static  CHAR	UtParl0004[]  = utparl0004;
static  CHAR	UtParl0005[]  = utparl0005;
static  CHAR	UtParl0006[]  = utparl0006;
static  CHAR	UtParl0007[]  = utparl0007;
static  CHAR	UtParl0008[]  = utparl0008;
static  CHAR	UtParl0009[]  = utparl0009;
static  CHAR	UtParl0010[]  = utparl0010;
static  CHAR	UtParl0011[]  = utparl0011;
static  CHAR	UtParl0012[]  = utparl0012;
static  CHAR	UtParl0013[]  = utparl0013;
static  CHAR	UtParl0014[]  = utparl0014;
static  CHAR	UtParl0015[]  = utparl0015;
static  CHAR	UtParl0016[]  = utparl0016;
static  CHAR	UtParl0017[]  = utparl0017;
static  CHAR	UtParl0018[]  = utparl0018;
static  CHAR	UtParl0019[]  = utparl0019;
static  CHAR	UtParl0020[]  = utparl0020;
static  CHAR	UtParl0021[]  = utparl0021;
static  CHAR	UtParl0022[]  = utparl0022;
static  CHAR	UtParl0023[]  = utparl0023;
static  CHAR	UtParl0024[]  = utparl0024;
static  CHAR	UtParl0025[]  = utparl0025;
static  CHAR	UtParl0026[]  = utparl0026;
static	CHAR	ExaRemp0001[] = exaremp0001;
static	CHAR	ExaRemp0002[] = exaremp0001;
static	CHAR	ExaRemp0003[] = exaremp0001;
static	CHAR	ExaRemp0004[] = exaremp0001;
static	CHAR	ExaRemp0005[] = exaremp0001;
static	CHAR	ExaRemp0006[] = exaremp0001;
static	CHAR	ExaRemp0007[] = exaremp0001;
static	CHAR	ExaRemp0008[] = exaremp0001;
static	CHAR	ExaRemp0009[] = exaremp0001;
static	CHAR	ExaRemp0010[] = exaremp0001;
static	CHAR	ExaRemp0012[] = exaremp0001;
static	CHAR	ExaRemp0013[] = exaremp0001;
static	CHAR	ExaRemp0014[] = exaremp0001;
static	CHAR	ExaRemp0015[] = exaremp0001;
static	CHAR	ExaRemp0016[] = exaremp0001;
static	CHAR	FinGesMes[]   = fingesmes;

#else

static CHAR  UtParl[MSGQTY+16+1][70] = {
	debgesmes,OuiNonMsg,
	utparl0001,utparl0002,utparl0003,utparl0004,utparl0005,
	utparl0006,utparl0007,utparl0008,utparl0009,utparl0010,
	utparl0011,utparl0012,utparl0013,utparl0014,utparl0015,
	utparl0016,utparl0017,utparl0018,utparl0019,utparl0020,
	utparl0021,utparl0022,utparl0023,utparl0024,utparl0025,
	utparl0026,
	exaremp0001,exaremp0001,exaremp0001,exaremp0001,
	exaremp0001,exaremp0001,exaremp0001,exaremp0001,
	exaremp0001,exaremp0001,exaremp0001,exaremp0001,
	exaremp0001,exaremp0001,exaremp0001,exaremp0001,
	fingesmes
	};

#endif

