/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993-98
 *	Module  : T-CODE
 *	Fichier : LKMAIN.C
 *	Version : 2.2b
 *	Date    : 09/10/95
 *	Systeme : Tous
 *
 *	Linker                               
 *
 *	[Noyau ALD - Linker]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	11/01/93 : Debut du codage
 *	09/10/95 : codes de retour
 *
 *
 *	14/07/98		JPH	Add support for diagnostic output (used in Idra).
 *							Transform main into AldMain.
 *							
 * 17/11/99 : (#SP) Bug ALD 2 fixed: modifications in get_module() function.
 *            Corrections to avoid output of all externs as unresolved. 
 *            Now only really unresolved externs are listed.
 *            Explanations of the reason see at #note991711 below.
 *
 * 27/01/00 : (#SP) Bug ALD 5 fixed: added a new function ReConstructMaxDirective(), modifications in reloger() function.
 *  
 * 27/01/00 : (#SP) Bug ALD 1 and 4 fixed: modifications in resoudre() function.
 *            Explanations of the reason see at #note270100 below.
 * 05/09/00 : (#OK) ALD 7:  #pragma LOCAL_CONSTANT.
 * 22/11/00 : (#OK & #SP) Bug fixed bounded with constants and and GV > 32k.
 * 28/03/01 : (#BG) Correction about ALD 7.
 * 08/10/01 : (#BG) Abandon du link si la cible est ouverte.
 * 05/11/01 : (#BG) When the linker is executed without WABAL, don't close the window if errors are displayed.
 * 14/11/01 : (#BG) Suppression de l'option -h sans objet sous Windows.
 *	------------ 2.2b -------------------------------------------------
 */

/********************************
*	Fonctions d'acces au T-Code 
*/
#define _LKMAIN

#include "aldtype.h"
#include "lkstruct.h"

#include "lkmain.h"

#include "lkmes.h"
#include "lkfich.h"
#include "lklib.h"
#include "lklist.h"
#include "lkecran.h"
#include "lkfile.h"
#include "lktable.h"
#include "fn_parse.h"

// YT : include for slist functions
#include "pubslist.h"

#include "display.h"

// YT : global ptmalloc
void * ptmalloc;



/*
	Declaration of module's global variables 
*/

Option			gOption;
BOOL				gIsStrict;
static jmp_buf	gExitLabel;

#ifdef DBGTRC2
	FILE * fdbgtrc;
#endif



#ifdef LINT_ARGS
	#ifndef __WALD__
	PUB int main(int argc , char *argv[]);
	#endif
	PUB int analyse_options(int argc, char *argv[], Option XPTR * pt_option);
	PUB VOID get_module( BYTE XPTR * , Option XPTR * );
	PUB VOID abandon( VOID );
	PUB VOID reloger( Option XPTR * );
	PUB VOID info( Option XPTR * );
	PUB VOID init_general( VOID );
	PUB VOID fin_general( VOID );
	PUB BOOL resoudre( Fichier XPTR * , Fichier XPTR * , C_SLIST FAR *, BOOL, BOOL );
	//SAP PUB BOOL resoudre( Fichier XPTR * , Fichier XPTR * , C_SLIST FAR *, BOOL, BOOL );
	PUB BOOL is_module_solve_segment( Fichier XPTR * , Fichier XPTR * , Fichier XPTR * );
	PUB BOOL is_module_solve_procedure( Fichier XPTR * , Fichier XPTR * , Fichier XPTR * );
	PUB BOOL is_module_solve_variable( Fichier XPTR * , Fichier XPTR * , Fichier XPTR * );
	PUB WORD is_variable_solve_extern( Ancrage XPTR *, Label XPTR *, LstPro XPTR *, Fichier XPTR *, Fichier XPTR * );
	PUB WORD is_procedure_solve_extern( ModPro XPTR * , Fichier XPTR * , Fichier XPTR * );
	PUB WORD is_segment_solve_extern( ModPro XPTR * , Fichier XPTR * , Fichier XPTR * );
	PUB VOID ReConstructMaxDirective(Option XPTR * pt_option, Entete XPTR * ent);
#else 	/* LINT_ARGS */
	#ifndef __WALD__
	PUB int main();
	#endif
	PUB int analyse_options();
	PUB VOID get_module();
	PUB VOID abandon();
	PUB VOID reloger();
	PUB VOID init_general();
	PUB VOID fin_general();
	PUB BOOL resoudre();
	PUB VOID info();
	PUB BOOL is_module_solve_segment();
	PUB BOOL is_module_solve_procedure();
	PUB BOOL is_module_solve_variable();
	PUB WORD is_variable_solve_extern();
	PUB WORD is_procedure_solve_extern();
	PUB WORD is_segment_solve_extern();
	PUB VOID ReConstructMaxDirective();
#endif  /* LINT_ARGS */





/*
	JPH note : output under Windows using diagnostics.
	
	Under WALD (Windows) two modes are availables :
	-	Diagnostic output. The program issue "diagnostic" that are send to 
		the extern program that displays actual messages.
	-	Console output. The program display a console that contains all outputs.
		
			
	Diagnostic are enabled using one (or both) of following methods:
	-	By defining a "environment variable" that contains the handle of the
		"receiver" window, that is the window that receive diagnostic messages.
		
	-	By using -jHandle argument.
	
	
	When diagnostic are used, the console should NOT appear.
	Following algorythm is used.
	
		gUseDiagnostic = FALSE
		gShowConsole = TRUE
	
		Opens console window in "hidden" state.
			Try to open Diagnostic (try to find Receiver handle using environment variable).
			If succeed:
				gUseDiagnostic = TRUE
				gShowConsole = FALSE
			Endif
		
		Analyses arguments
			if find option -jHandle:
				Try to open Diagnostic using provided handle.
				If succeed:
					gUseDiagnostic = TRUE
					gShowConsole = FALSE
				Endif
			endif
			
			when messages are issued:
				if (gUseDiagnostic)
					Output using diagnostics.
				else
					print on console
				endif
				
				if gShowConsole
					force console to show
				else
					force console to hide	
				endif
			endwhen
*/


#ifndef __WALD__

int main(argc, argv)
int argc;
char *argv[];
	{
	int Result = 0;

	Result = AldMain(argc,argv);

	return Result;
	}

#else	// __WALD__

#include "ctexec.h"	// for ctSetProcessResult
#include "ctwincon.h"

// -------------------------------------------------- Console management

void ctBeforeConsoleMain	(ctConsolePtr Console)
	{
	ODS_("CommandLine: "); // Keep these two lines separated!
	ODS(Console->CommandLine);
	
	#define INVISIBLE
	#ifdef INVISIBLE
	ctShowConsole(Console,FALSE);
	#endif
	}

int ctConsoleMain (ctConsolePtr Console)
	{
	int Result = CT_CLOSE_CONSOLE_IF_EMPTY;
	int DosResult = 0;

	#define MAX_ARGUMENT_BUFFER		256*2
	#define MAX_POINTER					50
	
	char 		Buffer[MAX_ARGUMENT_BUFFER];
	ctStr		ArgV[MAX_POINTER];
	int		ArgC;
	int		Err;
	HWND		ConnectionHandle = 0;
	
	Err = ctParseArgument
			(
			Console->CommandLine,
			Buffer,
			MAX_ARGUMENT_BUFFER,
			ArgV,
			MAX_POINTER,
			&ArgC,
			"wald",	// ArgV[0]
			0
			);

	ConnectionHandle = ctGetProcessDiagnosticReceiver(0);
	waOpenDisplay(ConnectionHandle, GetMessageLine(MessageToolName));

	if (GlobalShowConsole)
		{
		ctShowConsole(Console,TRUE);
		}

	DosResult = AldMain(ArgC,ArgV);
	
/* #BG 05/11/01
	if (GlobalShowConsole)
*/
	if (GlobalShowConsole && (Console->PrintCount == 0))
		PostMessage(Console->WindowHandle,WM_CLOSE,(WPARAM)0,(LPARAM)0);

	waCloseDisplay();
	
	ctSetProcessResult(0,DosResult);	

	return Result;
	}


/* #BG 08/10/01 Begin */
WORD IsFileOpened(char * FileName)
{      
	OFSTRUCT		ofStruct;
	HFILE			hFile;

	if (OpenFile((LPCTSTR)FileName, &ofStruct, OF_EXIST) != HFILE_ERROR)
	{
		hFile = OpenFile((LPCTSTR)FileName, &ofStruct, OF_SHARE_EXCLUSIVE);

		if (hFile == HFILE_ERROR)
			return 1;
		else
			_lclose(hFile);
	}

	return 0;
}
/* #BG 08/10/01 End */

#endif


/*********************************
* FCT AldMain
*
* Entree : 
*	le nombre d'argument
*	un tableau de pointeur sur les chaines d'arguments
*
* Sortie :
*	1 -> sortie avec erreur
*	0 -> sortie sans erreur
*	(VMS c'est l'inverse)
*
**********************************/

int AldMain(argc, argv)
int argc;
char *argv[];
	{
	if (setjmp(gExitLabel) != 0) 
		{
#ifndef vms
		return ((int) (1 | VAL_RET));
#else
		return ((int) (0 | STS$M_INHIB_MSG));
#endif
		}

#ifdef __MALLOC__
	dbginit("ALDDEBUG.TXT");
	dbgoption(1);
#endif

	MesInitTab();		/* initialisation de la table des messages */


	/* affichage de la banniere, et sortie si commande vierge */
	if (argc-- < 2) 
		{
	   Banniere();
		
#ifndef vms
		return((int) (0 | VAL_RET) );
#else
		return((int) (1 | STS$M_INHIB_MSG));
#endif
		}

	/* Initialisation du gestionnaire d'alerte */

	InitException();

	EcranInit();

#ifdef DBGTRC2
fdbgtrc = fopen(TranslateLongPathName("wald32.trc"),"w");
#endif


TRY
{
	/* Analyse des options */
	argc = analyse_options(argc, argv, &gOption);

	//MessageBox(NULL,GlobalArgLine,"",1); //###SAP  11/18/99

	/*************/
	//gOption.info=0; //###SAP  11/18/99

	if ( gOption.info ){
		/* Afficher les externes d'un module ou d'un program */
		info( &gOption );
	}else reloger( &gOption );
}

CATCH 
	{
	//MessageBox(NULL,GlobalArgLine,"Finished!",1);
	if ( Xstrcmp( Current.Kind, "TRY BLOC" ) ) 
		{
//SAP{
#ifdef __TRACE
//}SAP
		sprintf(waBuffer,"EXCEPTION : %d",Current.Value);
		waDisplayMessage(waBuffer);
		sprintf(waBuffer,"Type      : %s ",Current.Kind);
		waDisplayMessage(waBuffer);
		sprintf(waBuffer,"Condition : %s ",Current.CheckExpr );
		waDisplayMessage(waBuffer);
		sprintf(waBuffer,"Fichier   : %s ",Current.ExcFilename );
		waDisplayMessage(waBuffer);
		sprintf(waBuffer,"Ligne     : %d ",Current.ExcLinenumber );
		waDisplayMessage(waBuffer);
//SAP{
#endif
//}SAP
		}
	else	
		{
		if (
			(gOption.resol == TRUE) && 
				( 
				(Current.Value == MessageExtvarredef) || 
				(Current.Value == MessageExtprocredef) || 
				(Current.Value == MessageExtsegredef) 
				)
			)
			{
			EcranAffResolus
				(
				(Option XPTR *) &gOption, 
				(Fichier XPTR *) gOption.resultat 
				);
			}

		EcranErreur( Current.Value );
		}
	abandon();	
	}
END_CATCH

#ifdef DBGTRC2
	fclose(fdbgtrc);
#endif

	EcranFin();

	EndException();

#ifdef __TRACE_ERR
	if (arg_trace == TRUE) 
		{
		fputc(CTRL_Z,ftrace);
		fclose( ftrace );
		}
#endif
#ifdef __MALLOC
	dbgstat();
	dbgfin();
#endif

#ifndef vms
	return((int) (0 | VAL_RET) );
#else
	return((int) (1 | STS$M_INHIB_MSG));
#endif
	}


/*************************************************************************/



/***********************************
* FCT analyse_options
*
* Entree : 
* 	le nombre d'argument
*	le tableau des arguments
*	un pointeur sur la structure des options
*		
* Sortie :
*	le nombre d'argument restant
*
**********************************/

int analyse_options(argc, argv, pt_option)
int argc;
char *argv[];
Option XPTR * pt_option;
{
	BYTE nomargu[LGREP];
/*JPH Unused	BYTE ligarg[LGREP];*/
	BYTE txt_arg[LGREP];
	BYTE PathFile[LGREP];
/*JPH Unused	BYTE XPTR * pt_arg;*/
	int ArgCount = argc;
	BYTE XPTR * p,c;
	BYTE XPTR * nextindice;
	
	nomargu[0] = EOSTR;
	gIsStrict = FALSE;
	/* RAZ des options du linker */
	pt_option->info			= 0;
	pt_option->output     		= 0;
	pt_option->rep_destination[0] 	= EOSTR;
	pt_option->rep_module[0] 	= EOSTR;
	pt_option->debug		= 0;
	pt_option->libere_liste_publique= FALSE;
	pt_option->cst_alias		= FALSE;	
	pt_option->bavard		= FALSE;
	pt_option->resol		= FALSE;
	pt_option->strict		= FALSE;
	pt_option->quick_open		= FALSE;

	/* #OK: 05/09/00 ALD 7 (begin) */
	commonPragmaLocalConstant = 2;
	/* #OK: 05/09/00 ALD 7 (end) */

#ifndef VERSION_XX
	/* #AT: 22/11/00 (begin) */
	bIsGlobalVariable = 0;
	/* #AT: 22/11/00 (end) */
#endif

#ifdef DBGTRC
fprintf(fdbgtrc,"\nanalyse_options() - Debut\n");
#endif

	
	ALLOC_SLIST( pt_option->liste_prg );
	ALLOC_SLIST( pt_option->liste_mod );
	INIT_ALLOC( pt_option->current, Fichier );
	
	p = *( ++ argv );

	if (((*p == '-') || (*p == '/' )) && (toupper(*(p+1)) == 'F')) 
		{
		/* la ligne de commande se trouve dans un fichier */
		if (!LibInitArg((BYTE *) p+2, &GlobalArgLine[0] ))
			return ( 0 );
		}
	else 
		{
		GlobalArgLine[0] = EOSTR;

		while (ArgCount--) 
			{
			if (Xstrlen(&GlobalArgLine[0]) + Xstrlen(p) >= 254) 
				{
				THROW( ErreurNoyau01 ); 
				}
			Xstrcat(&GlobalArgLine[0]," ");
         Xstrcat(&GlobalArgLine[0],p);
         p = *(++argv);
         }
		}
	
	p = &GlobalArgLine[0];         	/* p pointe sur la ligne d'argument 	*/
	nextindice = &GlobalArgLine[0];        /* pointe sur le premier element */

	GlobalArgPtr  = &GlobalArgLine[0];

	/* recherche des options eventuelles */

	while (LibNextOpt(&GlobalArgPtr, txt_arg)) 
		{	/* tant que la commande est non vide */
		p = &txt_arg[0];
#ifndef unix
		if (*p == '-' || *p == '/') 
			{
#else
		if (*p == '-') 
			{
#endif
			c = *++p;
			switch (toupper(c)) 
				{
				case 'A':	/* gestion des alias sur les constantes */
					pt_option->cst_alias = TRUE;
					break;

				case 'D':	/* resultat explicite */
					p++;
					if (*p != ' ' && *p != EOSTR) 
						{
						XstrCpySize(pt_option->rep_destination,(BYTE XPTR *) p, sizeof(pt_option->rep_destination));
						}
					break;

	       	case 'F': 
					/* la suite de la ligne de commande se trouve dans un fichier */
			      LibInitArg((BYTE *) p+1, GlobalArgLine );
					GlobalArgPtr = &GlobalArgLine[0];
					break;

#ifndef __WALD__	/* #BG 14/11/01 L'option -h est sans objet en WIN32 */
				case 'H':	/* option integre */
					if (*(p+1) == '1') 
						{
						EcranSetCico( 2 );
						pt_option->output = 2;
						}
					else 
						{
						EcranSetCico( 1 );
						pt_option->output = 1;
						}
					EcranBoite(EcranLH, EcranCH);
					break;
#endif
					
				case 'I': 
					/* la suite de la ligne de commande se trouve dans un fichier */
					pt_option->info = 1;
					if (*(p+1) == '+') 
						{
						pt_option->info = 2;
						p++;
						}
					break;

#ifdef __WALD__
				case 'J': 
					/* J0x1234 ou J1234 : June output (WALD only) */
					{
					/*
						read number behind options
					*/					
					long ConnectionHandle = 0;
					p++;
					sscanf(p,"%ld",&ConnectionHandle);
					
					waDisplaySetConnection((HWND) ConnectionHandle);
					}
					break;
#endif

				case 'L':
					pt_option->libere_liste_publique = TRUE;
					break;

				case 'M':
					/*
						Invert the "default" extension scheme
						
						ALD
							default	 	dbo,dbg
							-M				wdo,wdg
						WALD
							default		wdo,wdg
							-M	 			dbo,dbg
					
					*/
#ifdef __WALD__
					GlobalExtensionDBO = EXTENSION_DBO_ALD;
					GlobalExtensionDBG = EXTENSION_DBG_ALD;
#else
					GlobalExtensionDBO = EXTENSION_DBO_WALD;
					GlobalExtensionDBG = EXTENSION_DBG_WALD;
#endif
					break;

				case 'Q':
					pt_option->quick_open = TRUE;
					break;

				case 'R':	/* repertoire des modules */
					p++;
					if (*p != ' ' && *p != EOSTR) 
						{
						XstrCpySize
							(
							pt_option->rep_module,
							(BYTE XPTR *) p, 
							sizeof(pt_option->rep_module)
							);
						}
					break;

				case 'S':
					pt_option->strict = TRUE;
					gIsStrict = TRUE;
					break;

#ifdef __TRACE_ERR
				case 'T':
					arg_trace = TRUE;
					ftrace = fopen("ald.err","w");
					break;
#endif

				case 'V':
					pt_option->bavard = TRUE;
					EcranSetBavard();
					if (*(p+1) == '+') 
						{
						pt_option->bavard = 2;
						p++;
						}
					break;

				case 'W':
					pt_option->resol = TRUE;
					break;

#ifdef VERSION_XX
				case 'Y':	/* Extended Tcode */
					p++;
					if (!( *p ))
						(void) set_first_version('4');
					else if (( *p == '3' )
					     ||  ( *p == '4' ))
						(void) set_first_version(*p);
					else	(void) set_first_version('3');
					break;
#endif

				case 'Z':
					pt_option->debug = 1;
					break;

				default:
					THROW(ErreurNoyau01);	/* #BG 14/11/01 */
					break;
				}
			}
		else 
			{
			/* pas de - ni / */
			/* c'est un fichier */
			Xfn_parser( p, PathFile, FILE_EXTENSION);
			if (
				(Xstrcmp(PathFile, ".lk")==0) || 
				(Xstrcmp(PathFile, ".LK")==0)
				) 
				{
				/* c'est un fichier ou se trouve la liste des modules */
				/* la suite de la ligne de commande se trouve dans un fichier */
				Xfn_parser(p, PathFile, (FILE_DEVICE | FILE_PATH));
				if (PathFile[0] == EOSTR)
					{
					LibMakeReper(pt_option->rep_module, PathFile);
					Xstrcat(PathFile, p );
					LibInitArg((BYTE *) PathFile, GlobalArgLine );
					}
		      else
					LibInitArg((BYTE *) p, GlobalArgLine );
					
				GlobalArgPtr = &GlobalArgLine[0];
				}
			else
				{
				/* Fichier module */
				get_module( p , pt_option );
				}
			}
		} /* while */

#ifdef DBGTRC
fprintf(fdbgtrc,"\nanalyse_options() - Fin\n");
#endif

	return ( argc ); /* JPH: Makes compiler happier */	
}

/*********************************
* FCT abandon
*
* Entree   : 
*	rien		
*
* Sortie   :
*	rien
*
* Remarque :
*	Abandon brutale du linker retour a l'ethiquette gExitLabel
*       definit au debut de programme
*
**********************************/
VOID abandon()
{

	EcranFin();

	/* Liberation de toutes les listes */

	/* Fermeture des modules */

	fin_general();
	
	if ( gOption.current  ) FichierFermer( gOption.current );
	if ( gOption.resultat ) FichierFermer( gOption.resultat );

	ListVideModule( gOption.liste_mod ); /* Ferme tous les modules */
	INIT_SLIST( gOption.liste_mod );
	
	ListVideModule( gOption.liste_prg ); /* Ferme tous les modules */
	INIT_SLIST( gOption.liste_prg );

	Xlongjmp(gExitLabel, MOINS_UN);
}

//###SAP  11/17/99 {
//This function checks if the node is already in the list

int	FindNode(list,node)
C_SLIST FAR * list;
C_SNODE FAR * node;
{
	C_SNODE FAR * pt_node;

	if (!list || !node) return 0;
	pt_node=SlistGetHead(list);
	while ( pt_node ) {
		if (pt_node==node) return 1;
		pt_node = SlistGetNext(list);
	}
	return 0;
}
//###SAP  11/17/99 }

/*********************************
* FCT get_module
*
* Entree   : 
*	nom de module
*	pointeur sur la structure d'option a mettre a jour
* 
* Sortie   :
*	rien
*
* Remarque :
*	Fait de la purification ethnique d'un cote les programmes
*       de l'autre les modules
*
**********************************/
VOID get_module( nom , pt_option )
BYTE XPTR * 	nom;
Option XPTR * 	pt_option;
{
	C_SNODE FAR *	node;
	BYTE XPTR *	tmp[LGBLOC];
    /* #SP: 17/11/99 ALD 2 (begin) */
	int			must_duplicate=0;
    /* #SP: 17/11/99 ALD 2 (end) */


	/* allocation du noeud */


	ALLOC_STRUCT( pt_option->current, Fichier );

/* #BG 05/09/02
Pas de recherche en cascade:
Si nom complet, pas de recherche dans le répertoire par défaut en cas d'echec,
si nom seul, recherche dans le répertoire par défaut si défini.

TRY 
	{
*/
	FichierInit( pt_option->current, nom, pt_option->rep_module, MODULE );
	FichierOuvrir( pt_option->current );
/* #BG 05/09/02
	}

CATCH 
	{
	// Le repertoire explicite a echoue, tente le repertoire par defaut.
	if ( pt_option->rep_module[0] != EOSTR)
		{
		Xfn_parser( (BYTE XPTR *) nom, (BYTE XPTR *) tmp, FILE_NAME);

		FichierInit( pt_option->current, (BYTE XPTR *) &tmp[0], pt_option->rep_module, MODULE );
		FichierOuvrir( pt_option->current );
		}
	else 
		THROW( ErreurNoyau02 );
	}
	
END_CATCH;
*/

/* #BG 28/03/01 Begin */
	if (commonPragmaLocalConstant == -1)
		THROW(MessageLocalConst);
/* #BG 28/03/01 End */

	ALLOC_SNODE( node );
	SnodeSet( node, pt_option->current );

	/* tester le type de module */
/* #SP: 17/11/99 ALD 2 (begin) */
	/*if ( pt_option->current->ent_code.exec == 2 || pt_option->info == 1)	Commented by #SP */
	if ( pt_option->current->ent_code.exec == 2)
/* #SP: 17/11/99 ALD 2 (end) */
	{
		if (pt_option->info==1) must_duplicate=1;
		/* c'est un Programme */
		SlistAddTail( pt_option->liste_prg, node );
	}

	if ( pt_option->current->ent_dbg.exec == 3)
	{
		/* c'est un module */
		/* ajouter le numero d'ordre du module */

/* #SP: 17/11/99 ALD 2 (begin) */

		if (must_duplicate)
		{
			ALLOC_SNODE( node );
			SnodeSet( node, pt_option->current );
		}

		/*
			#note17/11/99:
				We need to check if the node is already in the list to avoid a dead loop by
				self-referencing. To explain I'll give the sample:
				we have two lists - pt_option->liste_mod and pt_option->liste_prg.
				This two lists contain the same node A (A - is actually the address).
				We've added a node B to the pt_option->liste_prg list 3 lines before.
				So the "next" pointer in the A already has a reference to the B and so the
				pt_option->liste_mod list contains this node too. In order to avoid cycled-referencing
				and promblems with releasing the nodes I've recreated the copy of this node.
		*/
/* #SP: 17/11/99 ALD 2 (end) */

		SlistAddTail( pt_option->liste_mod, node );
		pt_option->current->NUM_PRG = (BYTE) SlistCount( pt_option->liste_mod );

		/* on referme */
		if ( pt_option->quick_open == FALSE && pt_option->info == FALSE) 
		{
			FileClose( &(pt_option->current->code) );
			FileClose( &(pt_option->current->dbg) );
		}
	}

	/* remise a zero de la variable */
	INIT_ALLOC( pt_option->current, Fichier );
}


/* #SP: 27/01/00 ALD 5 (begin) */
//*********************************
//
//
//
// Function : ReConstructMaxDirective
// Description: This function lists all programs and modules in the project and takes
//				the maxumum value of lg_mem (#MEM), lg_stack (#STACK), nb_files (#FILES)
//

VOID ReConstructMaxDirective(pt_option,ent)
Option XPTR * pt_option;
Entete XPTR * ent;
{
	C_SNODE FAR * pt_node;
	Fichier XPTR *  pt_fic;

	if (!pt_option || !ent || !pt_option->liste_prg || !pt_option->liste_mod) return;
	SlistRewind( pt_option->liste_prg);
	SlistRewind( pt_option->liste_mod);
	ent->lg_mem=0;
	ent->lg_stack=0;
	ent->nb_files=0;

	pt_node = SlistGetNext(pt_option->liste_prg);
	while ( pt_node ) {
		pt_fic = SnodeGet( pt_node );
		if (pt_fic){
			if (pt_fic->code.ent->lg_mem>ent->lg_mem) ent->lg_mem=pt_fic->code.ent->lg_mem;
			if (pt_fic->ent_code.lg_mem>ent->lg_mem) ent->lg_mem=pt_fic->ent_code.lg_mem;

			if (pt_fic->code.ent->lg_stack>ent->lg_stack) ent->lg_stack=pt_fic->code.ent->lg_stack;
			if (pt_fic->ent_code.lg_stack>ent->lg_stack) ent->lg_stack=pt_fic->ent_code.lg_stack;

			if (pt_fic->code.ent->nb_files>ent->nb_files) ent->nb_files=pt_fic->code.ent->nb_files;
			if (pt_fic->ent_code.nb_files>ent->nb_files) ent->nb_files=pt_fic->ent_code.nb_files;
		}
		pt_node = SlistGetNext( pt_option->liste_prg );
	}
	pt_node = SlistGetNext(pt_option->liste_mod);
	while ( pt_node ) {
		pt_fic = SnodeGet( pt_node );
		if (pt_fic){
			if (pt_fic->code.ent->lg_mem>ent->lg_mem) ent->lg_mem=pt_fic->code.ent->lg_mem;
			if (pt_fic->ent_code.lg_mem>ent->lg_mem) ent->lg_mem=pt_fic->ent_code.lg_mem;

			if (pt_fic->code.ent->lg_stack>ent->lg_stack) ent->lg_stack=pt_fic->code.ent->lg_stack;
			if (pt_fic->ent_code.lg_stack>ent->lg_stack) ent->lg_stack=pt_fic->ent_code.lg_stack;

			if (pt_fic->code.ent->nb_files>ent->nb_files) ent->nb_files=pt_fic->code.ent->nb_files;
			if (pt_fic->ent_code.nb_files>ent->nb_files) ent->nb_files=pt_fic->ent_code.nb_files;
		}
		pt_node = SlistGetNext( pt_option->liste_mod );
	}
}
/* #SP: 27/01/00 ALD 5 (end) */

/*********************************
* FCT reloger
*
* Entree   : 
*	une structure d'options de la ligne de commamde
* 
* Sortie   :
*	rien
*
* Remarque :
*	Premiere grande boucle pour reloger
*
**********************************/

VOID reloger( pt_option )
Option XPTR * pt_option;
{
	C_SNODE FAR * pt_node;

	Fichier XPTR *  pt_fic;
	BOOL	      tout_resolu;
    /* #SP: 27/01/00 ALD 5 (begin) */
	Entete		  ent_max;
    /* #SP: 27/01/00 ALD 5 (end) */


#ifdef DBGTRC
fprintf(fdbgtrc,"\nReloger() - Debut\n");
#endif


    /* #SP: 27/01/00 ALD 5 (begin) */
	memset(&ent_max,0,sizeof(Entete)); 
	ReConstructMaxDirective(pt_option,&ent_max); 
    /* #SP: 27/01/00 ALD 5 (end) */

	SlistRewind( pt_option->liste_prg) ;

	pt_node = SlistGetNext(pt_option->liste_prg);

	/* Pour chaque programme */
	while ( pt_node ) {

		pt_fic = SnodeGet( pt_node );
#ifdef DBGTRC
fprintf(fdbgtrc,"\nProgramme : %s \n", pt_fic->code.nom);
#endif

		ALLOC_STRUCT( pt_option->resultat, Fichier );

		FichierInit( pt_option->resultat, pt_fic->code.nom, pt_option->rep_destination, RESULTAT );

		FichierCreateResult( pt_fic, pt_option->resultat );

		EcranProgram( pt_option->resultat->code.nom );

		init_general();

		EcranEnCours( pt_fic->code.nom );

		FichierGetInfo( pt_fic, pt_option->resultat );

		tout_resolu = resoudre( pt_fic, pt_option->resultat,  pt_option->liste_mod, pt_option->libere_liste_publique, pt_option->cst_alias );

		if (tout_resolu ) {
			if (pt_option->resol == TRUE) {
				EcranAffResolus( pt_option, pt_option->resultat );
			}
			/* #SP: 27/01/00 ALD 5 (begin) */
                        /* Take maximum values */
			if (pt_fic->code.ent->lg_mem<ent_max.lg_mem) pt_fic->code.ent->lg_mem=ent_max.lg_mem;
			if (pt_fic->ent_code.lg_mem<ent_max.lg_mem) pt_fic->ent_code.lg_mem=ent_max.lg_mem;
			if (pt_fic->ent_dbg.lg_mem<ent_max.lg_mem) pt_fic->ent_dbg.lg_mem=ent_max.lg_mem;

			if (pt_fic->code.ent->nb_files<ent_max.nb_files) pt_fic->code.ent->nb_files=ent_max.nb_files;
			if (pt_fic->ent_code.nb_files<ent_max.nb_files) pt_fic->ent_code.nb_files=ent_max.nb_files;
			if (pt_fic->ent_dbg.nb_files<ent_max.nb_files) pt_fic->ent_dbg.nb_files=ent_max.nb_files;

			if (pt_fic->code.ent->lg_stack<ent_max.lg_stack) pt_fic->code.ent->lg_stack=ent_max.lg_stack;
			if (pt_fic->ent_code.lg_stack<ent_max.lg_stack) pt_fic->ent_code.lg_stack=ent_max.lg_stack;
			if (pt_fic->ent_dbg.lg_stack<ent_max.lg_stack) pt_fic->ent_dbg.lg_stack=ent_max.lg_stack;
            /* #SP: 27/01/00 ALD 5 (end) */
			FichierResultConstruct( pt_fic, pt_option->resultat );
			FichierFermer( pt_option->resultat );
		}
		else {
			EcranAffNonResolus( pt_option, pt_option->resultat );
			FichierDetruire( pt_option->resultat );
		}

		/* liberation de l'allocation faite dans init_fichier */
		FREE_ALLOC( pt_option->resultat, Fichier);

		/* liberation des listes */
		fin_general();

		pt_node = SlistGetNext( pt_option->liste_prg );
	}

	/* Fermeture des modules */
	ListVideModule( pt_option->liste_mod ); /* Ferme tous les modules */
	INIT_SLIST( pt_option->liste_mod );

	
	ListVideModule( pt_option->liste_prg ); /* Ferme tous les modules */
	INIT_SLIST( pt_option->liste_prg );

#ifdef DBGTRC
fprintf(fdbgtrc,"\nReloger() - Fin\n");
#endif
}


VOID info( pt_option )
Option XPTR * pt_option;
{
	C_SNODE FAR * pt_node;
	Fichier XPTR *  pt_fic;
	BOOL	      tout_resolu;

	SlistRewind( pt_option->liste_prg) ;
	pt_node = SlistGetNext(pt_option->liste_prg);

	if ( ! pt_node ) {
		SlistRewind( pt_option->liste_mod) ;
		pt_node = SlistGetNext(pt_option->liste_mod);
	}

	/* Pour chaque programme */
	while ( pt_node ) {
		pt_fic = SnodeGet( pt_node );

    
        /* #SP: 17/11/99 ALD 2 (begin) */
		ALLOC_STRUCT( pt_option->resultat, Fichier );
		FichierInit( pt_option->resultat, "aldtmp.tmp", "", RESULTAT );
		FichierCreateResult( pt_fic, pt_option->resultat );
        /* #SP: 17/11/99 ALD 2 (end) */

		init_general();

		EcranEnCours( pt_fic->code.nom );

        /* #SP: 17/11/99 ALD 2 (begin) */
		/*FichierGetInfo( pt_fic, pt_fic );	Commented by #SP */
    
		FichierGetInfo( pt_fic, pt_option->resultat );
		tout_resolu = resoudre( pt_fic, pt_option->resultat,  pt_option->liste_mod, pt_option->libere_liste_publique, pt_option->cst_alias );
        /* #SP: 17/11/99 ALD 2 (end) */

		if (pt_option->info == 2 ) {
            /* #SP: 17/11/99 ALD 2 (begin) */
			/*EcranAffPublic( pt_option, pt_fic );	Commented by #SP */
			EcranAffPublic( pt_option, pt_option->resultat );
            /* #SP: 17/11/99 ALD 2 (end) */
		}

        /* #SP: 17/11/99 ALD 2 (begin) */
		/*EcranAffNonResolus( pt_option, pt_fic );	Commented by #SP */
		EcranAffNonResolus( pt_option, pt_option->resultat );
        /* #SP: 17/11/99 ALD 2 (end) */
	
        /* #SP: 17/11/99 ALD 2 (begin) */
		/*FichierFermer( pt_fic );	Commented by #SP */
		FichierFermer( pt_option->resultat );
		FichierDetruire( pt_option->resultat );

		FREE_ALLOC( pt_option->resultat, Fichier);
        /* #SP: 17/11/99 ALD 2 (end) */


		/* liberation des listes */
		fin_general();

		pt_node = SlistGetNext( pt_option->liste_prg );
	}

    /* #SP: 17/11/99 ALD 2 (begin) */
	/* Fermeture des modules */
	ListVideModule( pt_option->liste_mod ); /* Ferme tous les modules */
	INIT_SLIST( pt_option->liste_mod );
    /* #SP: 17/11/99 ALD 2 (end) */
	
	ListVideModule( pt_option->liste_prg ); /* Ferme tous les modules */
	INIT_SLIST( pt_option->liste_prg );
}


VOID info_org( pt_option )
Option XPTR * pt_option;
{
	C_SNODE FAR * pt_node;
	Fichier XPTR *  pt_fic;

	SlistRewind( pt_option->liste_prg) ;
	pt_node = SlistGetNext(pt_option->liste_prg);

	/* Pour chaque programme */
	if ( ! pt_node ) {
		SlistRewind( pt_option->liste_mod) ;
		pt_node = SlistGetNext(pt_option->liste_mod);
	}

	while ( pt_node ) {

		pt_fic = SnodeGet( pt_node );

		init_general();

		EcranEnCours( pt_fic->code.nom );

		FichierGetInfo( pt_fic, pt_fic );


		//tout_resolu = resoudre( pt_fic, pt_fic,  pt_option->liste_mod, pt_option->libere_liste_publique, pt_option->cst_alias );

		if (pt_option->info == 2 ) {
			EcranAffPublic( pt_option, pt_fic );
		}

		EcranAffNonResolus( pt_option, pt_fic );
	
		FichierFermer( pt_fic );

		/* liberation des listes */
		fin_general();

		pt_node = SlistGetNext( pt_option->liste_prg );
	}

	ListVideModule( pt_option->liste_prg );
	INIT_SLIST( pt_option->liste_prg );
/*
 //###SAP  11/18/99
	ListVideModule( pt_option->liste_mod );
	INIT_SLIST( pt_option->liste_mod );
 //###SAP  11/18/99
*/


}

VOID init_general( )
{
	ListAllouer();
}

VOID fin_general( )

{
	ListLiberer();
	if (GlobalArgFile) {
		Xfclose( GlobalArgFile );
	}
}

BOOL resoudre( pt_fic, pt_res, liste_modules, libere_liste_publique, cst_alias )
Fichier XPTR * pt_fic;
Fichier XPTR * pt_res;
C_SLIST FAR * liste_modules;
BOOL libere_liste_publique;
BOOL cst_alias;
{
	C_SNODE FAR * pt_node;

	BOOL tout_resolu;

	BOOL SolvedSeg;
	BOOL SolvedPro;
	BOOL SolvedVar;

	WORD passe;

	Fichier XPTR * pt_module;
	Fichier XPTR * pt_prg;

	WORD old_nb_seg_ext;
	WORD old_nb_pro_ext;
	WORD old_nb_var_ext;

#ifdef BROWSE

#endif



	EcranBoiteMaj( EcranLH, EcranCH, pt_res );
	passe    = 1;
	while ( passe != 0 ) {

		EcranPasse( passe );

		SlistRewind( liste_modules );
		pt_node = SlistGetNext( liste_modules );
		
/*
		old_nb_pro_ext = SlistCount( pt_res->liste_pro_ext );
		old_nb_seg_ext = SlistCount( pt_res->liste_seg_ext );
		old_nb_var_ext = ListCountVarExt( pt_res->liste_ancrage );
*/
		old_nb_pro_ext = ListCountProExt( pt_res->liste_pro_ext );
		old_nb_seg_ext = ListCountSegExt( pt_res->liste_seg_ext );
		old_nb_var_ext = ListCountVarExt( pt_res->liste_ancrage );
	
		/* Pour Chaque module */

		while( pt_node ) {
			pt_module = SnodeGet( pt_node );
	
			EcranEnCours( pt_module->code.nom );
#ifdef DBGTRC
fprintf(fdbgtrc,"\n Module : %s -----------------------------\n", pt_module->code.nom);
#endif

			if ( gOption.quick_open == FALSE ) {
				FileOpen( &(pt_module->code) );
				FileOpen( &(pt_module->dbg)  );
			}

			if (passe == 1) FichierGetInfo( pt_module, pt_module );

			SolvedSeg = is_module_solve_segment( pt_fic, pt_res, pt_module );
			SolvedPro = is_module_solve_procedure( pt_fic, pt_res, pt_module );

#ifndef VERSION_XX
			/* #AT: 22/11/00 (begin) */
			bIsGlobalVariable = 1;
			/* #AT: 22/11/00 (end) */
#endif
			SolvedVar = is_module_solve_variable( pt_fic, pt_res, pt_module );
			
#ifndef VERSION_XX
			/* #AT: 22/11/00 (begin) */
			bIsGlobalVariable = 0;
			/* #AT: 22/11/00 (end) */
#endif

			if ( SolvedSeg || SolvedPro || SolvedVar) {
				if ( SolvedVar == FALSE && ( SolvedSeg || SolvedPro ) ) {
#ifndef VERSION_XX
					/* #AT: 22/11/00 (begin) */
					bIsGlobalVariable = 1;
					/* #AT: 22/11/00 (end) */
#endif
					FichierRelocVarMFIN( pt_module, pt_res );
					FichierRelocVarEFIN( pt_module, pt_res );

#ifndef VERSION_XX
					/* #AT: 22/11/00 (begin) */
					bIsGlobalVariable = 0;
					/* #AT: 22/11/00 (end) */
#endif
				}
				FichierEndModule( pt_module, pt_res, cst_alias );
			}

			EcranBoiteMaj( EcranLH, EcranCH, pt_res );

			if (gOption.quick_open == FALSE ) {
				FileClose( &(pt_module->code) );
				FileClose( &(pt_module->dbg) );
			}

			if ( gOption.bavard == 2 ) {
				EcranAffResolus( (Option XPTR *) &gOption, (Fichier XPTR *) gOption.resultat );
			}

/* #SP: 27/01/00 ALD 1 & 4 (begin) */
			/*
			This block is VERY needed :
			to resolve the next problem:
				We have 4 files:  inc.s, main.s, mod1.s, mod2.s

				variable v1 is declared in inc.s
				
				main.s is a program and mod1,mod2 are modules
				inc.s is included directly in main.s and mod2.s
				inc.s is also included as external in mod1.s

				So mod1 should use v1 from main.s
				But when we analyse mod1.o we get v1 as an external and it will be found in the mod2.s 
				and only after that we can look for it in main.s without this block. So the mod2.s is
				useless but w/o this block it was linked too.
				now we analyse main.s at first.

			Also without this block the different sequense 
			of linkage gives different results:

			For example:
			v1 will be used :
			- from main.s in case of order: main.s, mod2.s, mod1.s
			- from mod2.s in case of order: main.s, mod1.s, mod2.s  
			*/
			SolvedSeg = is_module_solve_segment( pt_fic, pt_res, pt_res );
			SolvedPro = is_module_solve_procedure( pt_fic, pt_res, pt_res );

#ifndef VERSION_XX
			/* #AT: 22/11/00 (begin) */
			bIsGlobalVariable = 1;
			/* #AT: 22/11/00 (end) */
#endif

			SolvedVar = is_module_solve_variable( pt_fic, pt_res, pt_res );

#ifndef VERSION_XX
			/* #AT: 22/11/00 (begin) */
			bIsGlobalVariable = 0;
			/* #AT: 22/11/00 (end) */
#endif

/* #SP: 27/01/00 ALD 1 & 4 (end) */

			TEST_STOP
			pt_node = SlistGetNext( liste_modules );
		}

		/* Tous les modules ont ete passe en revue */
		SolvedSeg = is_module_solve_segment( pt_fic, pt_res, pt_res );

		SolvedPro = is_module_solve_procedure( pt_fic, pt_res, pt_res );

#ifndef VERSION_XX
		/* #AT: 22/11/00 (begin) */
		bIsGlobalVariable = 1;
		/* #AT: 22/11/00 (end) */
#endif
		SolvedVar = is_module_solve_variable( pt_fic, pt_res, pt_res );

#ifndef VERSION_XX
		/* #AT: 22/11/00 (begin) */
		bIsGlobalVariable = 0;
		/* #AT: 22/11/00 (end) */
#endif
		EcranBoiteMaj( EcranLH, EcranCH, pt_res );

		TEST_STOP;

		/* 
			On test si tout est bien resolu 
		*/

		if (  ( ListCountProExt( pt_res->liste_pro_ext ) == pt_res->nb_pro_solved ) 
		   && ( ListCountSegExt( pt_res->liste_seg_ext ) == pt_res->nb_seg_solved )
		   && ( ListCountVarExt( pt_res->liste_ancrage ) == pt_res->nb_var_solved ) 
		   ) 
			{
			/* tout a ete resolu */
			tout_resolu = TRUE; 

			/* Et c'est fini */
			passe = 0;
			}
		else 	{
			tout_resolu = FALSE;

			/*
			   On etablit une nouvelle passe a 2 conditions :
				- Tous les externs sont resolus
				- Les listes d'externs n'ont pas boug‚es
			   Sinon
	
			*/

			if (  ( old_nb_pro_ext ==  ListCountProExt( pt_res->liste_pro_ext ) ) 
			   && ( old_nb_seg_ext ==  ListCountSegExt( pt_res->liste_seg_ext ) )
			   && ( old_nb_var_ext ==  ListCountVarExt( pt_res->liste_ancrage ) )
			   )

				/* rien a bouge */
				passe = 0; /* fini */

			else 	{
				passe ++;
				
				if ( gOption.bavard == 2 ) {
					EcranAffNonResolus( (Option XPTR *) &gOption, (Fichier XPTR *) gOption.resultat );
				}
			}
		}
	}

	return( tout_resolu );
}

BOOL is_module_solve_segment(pt_fic, pt_res, pt_module  )
Fichier XPTR * pt_fic;
Fichier XPTR * pt_res;
Fichier XPTR * pt_module;
{
	BOOL retour;
	WORD i;
	C_SNODE FAR * pt_node;
	ModPro XPTR * pp;
	WORD solved;
	retour = FALSE;

#ifdef __TRACE
waDisplayMessage("is_module_solve_segment");
#endif

	/* Pour Chaque Segment Public */
	for (i =0; i<HTV; i++) {
		pt_node = SlistGetHead( pt_module->liste_seg_pub[ i ] );
		while ( pt_node ) {
			/* J'ai un segment public */
			pp = SnodeGet( pt_node );	
#ifdef __TRACE
{
sprintf(waBuffer,"segment public %s num %d",pp->nom,pp->pub.num_seg);
waDisplayMessage(waBuffer);
}
#endif
			solved = is_segment_solve_extern( pp, pt_module, pt_res );
			if ( solved != MOINS_UN ) {
			 	/* OUI */
				if ( pp->num_module != NUM_RES ) {
#ifdef __TRACE
waDisplayMessage("RESOLU");
#endif
					pp->used = solved;	
				}

				pt_res->nb_seg_solved ++;
				retour = TRUE;
			}

			pt_node = SnodeGetNext( pt_node );
		}
	}
#ifdef __TRACE
waDisplayMessage("FinSegment");
#endif
	return( retour );
}

BOOL is_module_solve_procedure( pt_fic, pt_res, pt_module )
Fichier XPTR * pt_fic;
Fichier XPTR * pt_res;
Fichier XPTR * pt_module;
{
	BOOL retour;
	ModPro XPTR * pp;	/* Procedure Publique */
/*JPH unused	LstPro XPTR * pe; /* Procedure Externe */
	WORD solved;	/* Adresse de la procedure relogee. (MOINS_UN -> non relogee) */
	C_SNODE FAR * pt_node;
	WORD i;

	retour = FALSE;

#ifdef __TRACE
waDisplayMessage("is_module_solve_procedure");
#endif
	/* Pour Chaque Procedure Publique */
	for (i =0; i<HTV; i++) {
		pt_node = SlistGetHead( pt_module->liste_pro_pub[ i ] );
		while ( pt_node ) {
			/* J'ai une procedure publique */
			pp = SnodeGet( pt_node );	
#ifdef __TRACE
waDisplay2Message("procedure public",pp->nom);
#endif

			/* Est elle deja relogee ? */	
			solved = is_procedure_solve_extern( pp, pt_module, pt_res );
			if ( solved != MOINS_UN ) {
			 	/* OUI */

				pt_res->nb_pro_solved ++;
			
				retour = TRUE;
			}

			pt_node = SnodeGetNext( pt_node );
		}
	}
#ifdef __TRACE
waDisplayMessage("Fin Procedure");
#endif
	return( retour );
}

BOOL is_module_solve_variable( pt_fic, pt_res, pt_module )
Fichier XPTR * pt_fic;
Fichier XPTR * pt_res;
Fichier XPTR * pt_module;
{
	C_SNODE FAR *	node;
	Ancrage XPTR *	pt_ancrage;
	LstPro  XPTR *	pt_varext;
	ModPro	XPTR *	varpub;
	Label	XPTR *	label_pub;
	BYTE		NomModule[LGREP];
	BOOL		retour;
	WORD		nb_present;
	WORD		solved;
	BOOL		match_module;
	BOOL		FieldM;
	BOOL		FieldE;
	InfoVar		ve;
	InfoVar		vp;

	retour = FALSE;

	FieldM = FALSE;
	FieldE = FALSE;


#ifdef __TRACE
waDisplayMessage("is_module_solve_variable");
#endif
	if (pt_module->dbg.ent->var_static == 1) {
		/* variables privees */
		return( FALSE );
	}

	/* pour chaque point d'ancrage */
	SlistRewind( pt_res->liste_ancrage );
	node = SlistGetNext( pt_res->liste_ancrage );
	while ( node ) {

		pt_ancrage = SnodeGet( node );

		match_module = TRUE;
		/* suis je le bon label */
		/* si ce n'est pas beau c'est de la faute au traducteur */
		if ( pt_ancrage->label[ 0 ] && (pt_ancrage->field == MINSERT || pt_ancrage->field == EINSERT )) {

			label_pub = ListIsLabelPub( pt_module->liste_label, pt_ancrage->label );
			if ( label_pub == GN( Label ) ) {
				match_module = FALSE;
			}
			else {
				if (label_pub->field != pt_ancrage->field) {
					match_module = FALSE;
				}
			}
		}

		if (pt_ancrage->par_qui != MOINS_UN && match_module == TRUE) {
			ListGetNameFromNum( pt_res->liste_mod_ext, pt_ancrage->par_qui, NomModule );
			if (! Xstrcmp( NomModule, &(pt_module->code.ent->nom[0]) ) ) {
				/* je suis le bon module */
				/* condition necessaire sur les externs */

				nb_present = 0;
				SlistRewind( pt_ancrage->liste_varext );
				node = SlistGetNext( pt_ancrage->liste_varext );					
				while ( node ) {
					pt_varext = SnodeGet( node );
					varpub    = ListIsVarPub( pt_module->liste_var_pub, pt_varext, pt_res, pt_module );
					if ( varpub ) {
						/* tester si meme type */
						/* meme nom de variables */
						TableGetVar( &(pt_res->Tvarext), pt_varext->ext.adr_desc, &ve );
						TableGetVar( &(pt_module->Tvar), varpub->num_desc, &vp );
						if ( ListMatchVar( &vp, &ve ) ) {
							nb_present ++;
						}
					}
					node = SlistGetNext( pt_ancrage->liste_varext );
				}

				if (nb_present != SlistCount( pt_ancrage->liste_varext ) ) {
					/* tous les externs ne sont pas relogeables dans ce module */
					match_module = FALSE;
				}
			}
			else	match_module = FALSE;
		}
		if ( match_module == TRUE ) {
			/* C'est bon mon gars tu peux y aller ... */
			SlistRewind(pt_ancrage->liste_varext);
			node = SlistGetNext( pt_ancrage->liste_varext );
			while ( node ) {
				pt_varext = SnodeGet( node );
				solved = is_variable_solve_extern( pt_ancrage, label_pub, pt_varext, pt_module, pt_res  );
				if (solved != MOINS_UN) {
					switch( pt_ancrage->field ) {
						case MINSERT:
						case MFIN:
						case MRECOUVRE:
							FieldM = TRUE;
							break;
						case EINSERT:
						case EFIN:
						case ERECOUVRE:
							FieldE = TRUE;
							break;

					};

					pt_res->nb_var_solved ++;
					retour = TRUE;
				}
				node = SlistGetNext( pt_ancrage->liste_varext );
			}
		}
		node = SlistGetNext( pt_res->liste_ancrage );
	}

	/* m et non e ==> reloger les e */
	if ( FieldM == TRUE && FieldE == FALSE ) {
	
	}
	/* e et non m ==> reloger les m */
	if ( FieldE == TRUE && FieldM == FALSE ) {
		
	}

#ifdef __TRACE
waDisplayMessage("FinVariable");
#endif

	return( retour );
}

WORD is_variable_solve_extern( ancrage, label, pe, pt_module, pt_res )
Ancrage XPTR *	ancrage;
Label	XPTR *	label;
LstPro	XPTR *	pe;
Fichier XPTR *	pt_module;
Fichier XPTR *	pt_res;
{
	C_SNODE FAR *	node;
	ModPro XPTR *	pp;
	BOOL		matched;
	InfoVar		ve; /* variable externe */
	InfoVar		vp; /* variable publique */
	WORD		i;
	BYTE 		NomModule[LGIDENT];
	BYTE		out[100];
	
	/* existe t-il une variable qui resolve l'extern */
	
	for (i=0; i < HTV; i++) {
		SlistRewind( pt_module->liste_var_pub[i] );
		node = SlistGetNext( pt_module->liste_var_pub[i] );
		while ( node ) {
			pp = SnodeGet( node );

			matched = FALSE;
			if (pe->par_qui != MOINS_UN && pe->any != MOINS_UN ) {
				if ( pt_res == pt_module ) {
					/* je suis dans le programme principal */
					if ( pp->num_module == NUM_RES ) {
						/* on ne prend que les procedures declaree dans le programme */

						ListGetNameFromNum( pt_res->liste_mod_ext, pe->par_qui, NomModule );			
						if (! Xstrcmp( NomModule, &(pt_module->code.ent->nom[0]) ) ) {
							/* je suis le bon module */
							matched = TRUE;										
						}
					}
				}
				else {
					/* je suis dans un module */
					ListGetNameFromNum( pt_res->liste_mod_ext, pe->par_qui, NomModule );			
					if (! Xstrcmp( NomModule, &(pt_module->code.ent->nom[0]) ) ) {
						/* je suis le bon module */
						matched = TRUE;										
					}
				}
			}
			else {
				if ( pe->par_qui != MOINS_UN && pe->any == MOINS_UN) {
					if ( gIsStrict == TRUE ) {
						matched = TRUE;
					}
				}
				else matched = TRUE;
			}
			if (pe->hash_code == pp->hash_code && matched == TRUE ) {
				if (! Xstrcmp( pe->nom, pp->nom ) ) {
					/* meme nom de variables */
					TableGetVar( &(pt_res->Tvarext), pe->ext.adr_desc, &ve );
					if ( pp->used == MOINS_UN ) {
						/* nom de variable non encore reloge */
						TableGetVar( &(pt_module->Tvar), pp->num_desc, &vp );
					}
					else {
						/* nom de variable deja reloges IN ANY */
						TableGetVar( &(pt_res->Tvar), pp->used, &vp );
					}
					if ( ListMatchVar( &vp, &ve ) || ancrage->field == MALL) {
						/* c'est (enfin) tout bon */
	
						/* Est ce que la Proc. Ext est deja resolue */
						if ( pe->solved != MOINS_UN && pe->num_module != pp->num_module ) {
							/* ERREUR : Deux Variables resolvent le meme extern */
							out[0] = EOSTR;
							EcranAncrage( ancrage, out );
							Xstrcat( out , " ");
							EcranVar( &ve, pe, (BYTE XPTR *) &out[Xstrlen(out)] );
							EcranWhichError( out );

							THROW( MessageExtvarredef );
						}
	
						if (pp->used == MOINS_UN ) {
							switch( ancrage->field ) {
								case MINSERT:
									FichierRelocVarMINSERT( pt_module, pt_res, ancrage, label );
									break;
									
								case MFIN:
									FichierRelocVarMFIN( pt_module, pt_res );
									break;
	
								case MRECOUVRE:
									FichierRelocVarMRECOUVRE( pt_module, pt_res, ancrage );
									break;
	
								case EINSERT:
									FichierRelocVarEINSERT( pt_module, pt_res, ancrage, label );
									break;
	
								case EFIN:
									FichierRelocVarEFIN( pt_module, pt_res );
									break;
	
								case ERECOUVRE:
									FichierRelocVarERECOUVRE( pt_module, pt_res, ancrage );
									break;
	
								case MALL:	/* Reloc en fonction du type de la variable Publique */
									if (vp.etendue) {
										FichierRelocVarEFIN( pt_module, pt_res );
									}
									else {
										if (vp.virtuelle)
											FichierRelocVarVIRT( pt_module, pt_res );
										else 	FichierRelocVarMFIN( pt_module, pt_res );
									}
									break;
							}
	
							/* la structure pp a ete mise a jour lors de la relocation des vraiables */
							pe->solved = pp->used;
	
						}
						else  { /* procedure deja relogee */
							/* c'est la meme du meme module -> reloge */
	
							if ( pe->solved == pp->used ) {
								/* extern deja traite */
								return( MOINS_UN );
							}
							pe->solved = pp->used;	
						}
	
						pe->num_module = pp->num_module;			

						pe->par_qui = ListAddNameUnique( pt_res->liste_mod_ext, &(pt_module->code.ent->nom[0]) );
	
						/* Relocation des references */
						TableGetVar( &(pt_res->Tvar), pp->used, &vp);
						ListRelocVarPatch(pt_module,  pe->pt_ref, pe->solved, vp.adrvar );
	
						return( pe->solved );
					}
				}
			}
			node = SlistGetNext( pt_module->liste_var_pub[i] );
		}
		
	}

	return( MOINS_UN );
}

WORD is_procedure_solve_extern( pp, pt_module, pt_resultat )
ModPro XPTR * pp;
Fichier XPTR * pt_module;
Fichier XPTR * pt_resultat;
{

	LstPro XPTR * pe;
	BOOL matched;
	BYTE NomModule[LGREP];
	Tabfic XPTR * pt;
	C_SNODE FAR * pt_node;
	BYTE	out[100];
	/* Est que la procedure publique resoud un extern ? */

#ifdef __TRACE
waDisplayMessage("is_procedure_solve_extern");
#endif
	SlistRewind( pt_resultat->liste_pro_ext );
	pt_node = SlistGetNext( pt_resultat->liste_pro_ext );

	while (pt_node ) {
		pe = SnodeGet( pt_node );
		matched = FALSE;
#ifdef __TRACE
waDisplay2Message("       procedure extern",pe->nom);
#endif

/*
		if ( ListMatchPro( pp, pe ) && pe->solved == MOINS_UN ) {
*/
		if ( ListMatchPro( pp, pe ) ) {
			/* OUI */
			pt = &(pt_module->code);
			/* Suis je le bon module */
			if (pe->par_qui != MOINS_UN && pe->any != MOINS_UN) {
				if ( pt_resultat == pt_module ) {
					/* je suis dans le programme principal */
					if ( pp->num_module == NUM_RES ) {
						/* on ne prend que les procedures declaree dans le programme */

						ListGetNameFromNum( pt_resultat->liste_mod_ext, pe->par_qui, NomModule );			
						if (! Xstrcmp( NomModule, &(pt_module->code.ent->nom[0]) ) ) {
							/* je suis le bon module */
							matched = TRUE;										
						
						}
					}
				}
				else {
					/* je suis dans un module */
					ListGetNameFromNum( pt_resultat->liste_mod_ext, pe->par_qui, NomModule );			
					if (! Xstrcmp( NomModule, &(pt_module->code.ent->nom[0]) ) ) {
						/* je suis le bon module */
						matched = TRUE;										
					}
				}
			}
			else {
				if ( pe->par_qui != MOINS_UN && pe->any == MOINS_UN) {
					if ( gIsStrict == TRUE ) {
						matched = TRUE;
					}
				}
				else matched = TRUE;
			}

			if (SlistCount(pe->pt_ref) == 0 ) matched = FALSE;

			if ( matched ) {
				/* Est ce que la Proc. Ext est deja resolue */
				if ( pe->solved != MOINS_UN && pe->num_module != pp->num_module ) {
					/* ERREUR : Deux Procedures resolvent le meme extern */
					out[0] = EOSTR;
					EcranProcedure( pe, (BYTE XPTR *) &out[Xstrlen( out ) ] );
					EcranWhichError( out );
					THROW( MessageExtprocredef );
				}

				if (pp->used == MOINS_UN ) {

#ifdef __TRACE
waDisplayMessage("RELOCATION PROC");
#endif
					/* Reloger toutes les procedures appelees par la procedure */
					FichierRelocProApp( pt_module, pt_resultat, pp );

					/* on reloge la  procedure */
					FichierRelocPro( pt_module, pt_resultat, pp );
					pe->solved = pp->used;
#ifdef __TRACE
waDisplayMessage("FIN RELOC");
#endif
		
				}
				else  { /* procedure deja relogee */
					if (pe->solved == MOINS_UN ) {
						pe->solved = pp->used;	
					}
					else {
						/* deja fait */
						return( MOINS_UN );
					}
				}
			
				pe->num_module = pp->num_module;			

				pe->par_qui = ListAddNameUnique( pt_resultat->liste_mod_ext, &(pt->ent->nom[0]) );

				/* Relocation des references */
				ListRelocPatch(pt_module,  pe->pt_ref, pe->solved, (BYTE) 0 );

#ifdef __TRACE
waDisplayMessage("FIN EXTERN SOLVED");
#endif

				return( pe->solved );
			}
		}
		pt_node = SnodeGetNext( pt_node );
	}
#ifdef __TRACE
waDisplayMessage("FIN EXTERN NON SOLVED");
#endif
	return ( MOINS_UN );
}

WORD is_segment_solve_extern( pp, pt_module, pt_resultat )
ModPro XPTR * pp;
Fichier XPTR * pt_module;
Fichier XPTR * pt_resultat;
{

	LstPro XPTR * pe;
	BOOL matched;
	BYTE NomModule[LGREP];
	Tabfic XPTR * pt;
	C_SNODE FAR * pt_node;
	BYTE	out[100];

	/* Est que le segment public resout un extern ? */

#ifdef __TRACE
waDisplayMessage("is_segment_solved_extern");
#endif
	SlistRewind( pt_resultat->liste_seg_ext );
	pt_node = SlistGetNext( pt_resultat->liste_seg_ext );

	while (pt_node ) {
		pe = SnodeGet( pt_node );
		matched = FALSE;

#ifdef __TRACE
{
sprintf(waBuffer,"segment extern %s num %d",pe->nom,pe->ext.num_seg);
waDisplayMessage(waBuffer);
}
#endif
/*
		if ( ListMatchSeg( pp, pe ) && pe->solved == MOINS_UN ) {

		if (pe->solved != MOINS_UN && pe->num_module == pp->num_module ) {
		}
*/
		if ( ListMatchSeg( pp, pe ) ) {
			/* OUI */
			pt = &(pt_module->code);
			/* Suis je le bon module */
			if (pe->par_qui != MOINS_UN && pe->any != MOINS_UN) {
				if ( pt_resultat == pt_module ) {
					/* je suis dans le programme principal */
					if ( pp->num_module == NUM_RES ) {
						/* on ne prend que les procedures declaree dans le programme */

						ListGetNameFromNum( pt_resultat->liste_mod_ext, pe->par_qui, NomModule );			
						if (! Xstrcmp( NomModule, &(pt_module->code.ent->nom[0]) ) ) {
							/* je suis le bon module */
							matched = TRUE;										
						
						}
					}
				}
				else {
					/* je suis dans un module */
					ListGetNameFromNum( pt_resultat->liste_mod_ext, pe->par_qui, NomModule );			
					if (! Xstrcmp( NomModule, &(pt_module->code.ent->nom[0]) ) ) {
						/* je suis le bon module */
						matched = TRUE;										
					}
				}

			}
			else {
				if ( pe->par_qui != MOINS_UN && pe->any == MOINS_UN) {
					if ( gIsStrict == TRUE ) {
						matched = TRUE;
					}
				}
				else matched = TRUE;
			}

			if (SlistCount(pe->pt_ref) == 0 && pe->ext.num_seg == MOINS_UN) matched = FALSE;

			if ( matched ) {
				/* Est ce que le Segment Ext est deja resolu */
				if ( pe->solved != MOINS_UN && pe->num_module != pp->num_module ) {
					/* ERREUR : Deux Segments resolvent le meme extern */
					out[0] = EOSTR;
					EcranSegment( pe, &out[Xstrlen( out ) ] );
					EcranWhichError( out );
					THROW( MessageExtsegredef ); 
				}

					/* on reloge le  segment */
				if (pp->used == MOINS_UN) {
#ifdef __TRACE
waDisplayMessage("RELOCATION PROC");
#endif
					/* Reloger toutes les procedures appelees par le segment */
					FichierRelocSegApp( pt_module, pt_resultat, pp );

					/* on reloge la  procedure */

					FichierRelocSeg( pt_module, pt_resultat, pp, pe->ext.num_seg );
					pe->solved = pp->used;
#ifdef __TRACE
waDisplayMessage("FIN RELOC");
#endif
	
				}
				else  { /* procedure deja relogee */
					if (pe->solved == MOINS_UN ) {
						pe->solved = pp->used;	
					}
					else 	return( MOINS_UN );/* deja fait */
				}

				pe->num_module = pp->num_module;			

				pe->par_qui = ListAddNameUnique( pt_resultat->liste_mod_ext, &(pt->ent->nom[0]) );

				/* Relocation des references */
				ListRelocPatch(pt_module,  pe->pt_ref, pe->solved, (BYTE) 0 );
#ifdef __TRACE
waDisplayMessage("FIN EXTERN SOLVED");
#endif
				return( pe->solved );
			}
		}
		pt_node = SnodeGetNext( pt_node );
	}
#ifdef __TRACE
waDisplayMessage("FIN EXTERN NOT SOLVED");
#endif
	return ( MOINS_UN );
}




