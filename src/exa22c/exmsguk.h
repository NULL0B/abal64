#ifdef	DEBUGGER

#ifdef	ABAL21
#define MSG_ID_EXADB_UK "*STX*3EXADBG  21b00"
#else
#define MSG_ID_EXADB_UK "*STX*3EXADBG  14d00"
#endif

#ifdef	ABAL14

/*	These two control the Second Help Screen of Command 'H'		*/
/*	------------------------------------------------------- 	*/
#define	FIRST_MSG_14 109
#define LAST_MSG_14  116

#define	MSGQTY	(MSGERREUR + 171)
#else
#define	MSGQTY	(MSGERREUR +  96)
#endif	/* ABAL14 */

static	char	begmesman[]   = MSG_ID_EXADB_UK;
static	char	YesNo[]	      ="yn1";
#ifdef	ABAL21
static	char	exatalk0001[] ="ABAL Debugger ";
#else
static	char	exatalk0001[] ="ABAL Debugger ";
#endif

#else

/*	EXECUTER MESSAGES	*/
/*	-----------------	*/

#ifdef	ABAL21
#define MSG_ID_EXA_UK   "*STX*3EXAG    21b00"
#else
#define MSG_ID_EXA_UK   "*STX*3EXAG    14d00"
#endif

#define	MSGQTY	(MSGERREUR + 1)

static	char	begmesman[]   = MSG_ID_EXA_UK;
static	char	YesNo[]	      ="yn1";

#ifdef	EXAMINE
static	char	exatalk0001[] ="Application Profiler ";
#else
#ifdef	ABAL21
static	char	exatalk0001[] ="ABAL Executer ";
#else
static	char	exatalk0001[] ="ABAL Executer ";
#endif
#endif

#endif

/*	Messages de reportage des erreurs par eder()	*/
/*	--------------------------------------------	*/
/*	pour EXA et EXADB				*/
/*							*/

static	char	exatalk0002[] ="Error";
static	char	exatalk0003[] ="I/O"; 	 
static	char	exatalk0004[] ="system";	 
static	char	exatalk0005[] ="syntax"; 
static	char	exatalk0006[] ="file";	 
static	char	exatalk0007[] ="system";	 
static	char	exatalk0008[] ="file";	 
static	char	exatalk0009[] ="graphic"; 
static	char	exatalk0010[] ="system";	 
static	char	exatalk0011[] ="at addres"; 
static	char	exatalk0012[] ="Fatal error : System signal number ";

#ifndef	DEBUGGER
static	char	exatalk0013[] ="Environnement version ";
#ifdef	ABALX11
static	char	exatalk0013[] ="Press Enter";
#endif
#endif

#ifdef	DEBUGGER

/*	Message du Menu Ctrl H  de EXADB seulement	*/
/*	------------------------------------------	*/

static	char	exatalk0013[] ="Ctrl A : Establish permenant break point";
static	char	exatalk0014[] ="Ctrl B : Establish temporary break point";
static	char	exatalk0015[] ="Ctrl C : Source window page down";
static	char	exatalk0016[] ="Ctrl D : Shrink source window";
static	char	exatalk0017[] ="Ctrl E : Source curser line down";
static	char	exatalk0018[] ="Ctrl F : Wildcard token search";
static	char	exatalk0019[] ="Ctrl G : Expand source window";
static	char	exatalk0020[] ="Ctrl H : Display this help screen";
static	char	exatalk0021[] ="Ctrl I : Redefine tabulation size";
static	char	exatalk0022[] ="Ctrl J : Toggle information line";
static	char	exatalk0023[] ="Ctrl K : Source curser line up";
static	char	exatalk0024[] ="Ctrl L : Define source position label";
static	char	exatalk0025[] ="Ctrl M : Return to execution page";
static	char	exatalk0026[] ="Ctrl P : Position at source label";
static	char	exatalk0027[] ="Ctrl R : Source window page up";
static	char	exatalk0028[] ="Ctrl V : Refresh source window display";
static	char	exatalk0029[] ="Ctrl W : Toggle program/debug display";
static	char	exatalk0030[] ="Ctrl X : Continue execution";
static	char	exatalk0031[] ="Ctrl Y : Delete source position label";
static	char	exatalk0032[] ="Ctrl Z : Zoom current source line";

/*	Messages du Menu 'H'	EXADB seulement		*/
/*	---------------------------------------		*/

static	char	exatalk0033[] ="AP [PROCID:] [ADRESSE]       : Set permenant break in procedure";
static	char	exatalk0034[] ="AS [SEGMID:] [ADRESSE]       : Set permenant break in segment";
static	char	exatalk0035[] ="AL OU BL                     : List break points";
static	char	exatalk0036[] ="AI<NUMBER> OU BI<NUMBER>     : Delete break point";
static	char	exatalk0037[] ="BP [PROCID:] [ADRESS]        : Set temporary break in procedure";
static	char	exatalk0038[] ="BS [SEGMID:] [ADRESS]        : Set temporary break in segment";
static	char	exatalk0039[] ="C                            : Continue execution";
static	char	exatalk0040[] ="D[H]<VARIABLE>[(DIM1[,DIM2])]: Display variable memory in hexa";
static	char	exatalk0041[] ="E                            : Leave ABAL Debugger";
static	char	exatalk0042[] ="H                            : Display this help screen";
static	char	exatalk0043[] ="K</XX> , K<NNN> , K<'C'>     : Redefine Interrupt key";
static	char	exatalk0044[] ="M<VARIABLE>[(DIM1[,DIM2])]   : Modify variable";
static	char	exatalk0045[] ="OA<VARIABLE>[(DIM1[,DIM2])]  : Add observation variable";
static	char	exatalk0046[] ="OI<VARIABLE>                 : Delete observation variable";
static	char	exatalk0047[] ="OL                           : List observation variables";
static	char	exatalk0048[] ="Z                            : Examine stack trace";
static	char	exatalk0049[] ="!<CMD,PARAM>                 : Activate system command";
static	char	exatalk0050[] ="  ";


/*	Messages divers des fonctions EXADB		*/
/*	-----------------------------------		*/

static	char	exatalk0051[] ="List of break points";
static	char	exatalk0052[] ="List of observation variables";
static	char	exatalk0053[] ="permenant";  
#ifdef	ABAL14
static	char	exatalk0054[] ="Context Stack";
#else
static	char	exatalk0054[] ="Context Stack";
#endif
static	char	exatalk0055[] ="Modified";
static	char	exatalk0056[] ="**END**"; 
static	char	exatalk0057[] ="Interrupt KEY";
static	char	exatalk0058[] ="Do you really want to leave the ABAL Debugger";
static	char	exatalk0059[] ="Unknown variable";
static	char	exatalk0060[] ="Normal completion";
static	char	exatalk0061[] ="List file access error";

/*	Messages en mode Verbose	*/
/*	------------------------	*/
#ifdef	ABAL14
static	char	exatalk0062[] ="Incorrect break point adresse";
#else
static	char	exatalk0062[] ="Too many break points";
#endif
static	char	exatalk0063[] ="Unknown procedure";
static	char	exatalk0064[] ="Environnement version ";
static	char	exatalk0065[] ="List of Watch variables";
static	char	exatalk0066[] ="Watch variable modified";
static	char	exatalk0067[] =" ";
static	char	exatalk0068[] =" ";
static	char	exatalk0069[] ="Item has been added";
static	char	exatalk0070[] ="Item has been deleted";
static	char	exatalk0071[] ="Requires execution mode";
static	char	exatalk0072[] ="Unknown Procedure or Segment";
static	char	exatalk0073[] ="Adress not found";
static	char	exatalk0074[] ="Source position label";
static	char	exatalk0075[] ="Tabulation size";
static	char	exatalk0076[] ="Source label to be deleted";
static	char	exatalk0077[] ="Source label to be defined";
static	char	exatalk0078[] ="Window expanded";
static	char	exatalk0079[] ="Window decreased";
static	char	exatalk0080[] ="Search for ";
static	char	exatalk0081[] ="Search pattern not found";
static	char	exatalk0082[] ="Press any key to continue";
static	char	exatalk0083[] ="ESC to abandon";
static	char	exatalk0084[] ="Not enough memory";
static	char	exatalk0085[] ="Unknown source label";
static	char	exatalk0086[] ="Source label deleted";
static	char	exatalk0087[] ="Source label added";
static	char	exatalk0088[] ="Source label modified";
static	char	exatalk0089[] ="Too many source position labels";

/*	Extended 1.2a Messages 		*/
/*	----------------------		*/

static	char	exatalk0090[] ="Alter  parameters";
static	char	exatalk0091[] ="Save   parameters";
static	char	exatalk0092[] ="Load   parameters";
static	char	exatalk0093[] ="ABAL Debugger parameter modification";

static	char	exatalk0094[] ="Parameter menu window";
static	char	exatalk0095[] ="Stack trace window";
static	char	exatalk0096[] ="Source label list window";
static	char	exatalk0097[] ="Source line zoom window";
static	char	exatalk0098[] ="Observation Variables";
static	char	exatalk0099[] ="Command window";
static	char	exatalk0100[] ="Observation Variables";
static	char	exatalk0101[] ="Variable modification window";
static	char	exatalk0102[] ="Break point list window";
static	char	exatalk0103[] ="Memory display window";
static	char	exatalk0104[] ="Help window";
static	char	exatalk0105[] ="This parameter window";
static	char	exatalk0106[] ="Error report window";
static	char	exatalk0107[] ="Exit window";
static	char	exatalk0108[] ="Source display window";

#ifdef	ABAL14
static	char	exatalk0109[] ="  ";
static	char	exatalk0110[] ="BV <VARIABLE>                : Set one-shot memory watch";
static	char	exatalk0111[] ="AV <VARIABLE>                : Set permenant memory watch";
static	char	exatalk0112[] ="F <ASSIGN HANDLE>            : Examine file table entry";
static	char	exatalk0113[] ="G [ PROGRAMNAME ] [ , ARG]   : Restart current program ";
static	char	exatalk0114[] ="VI<VARIABLE>                 : Delete memory watch";
static	char	exatalk0115[] ="VL[VARIABLE]                 : List memory watch events";
static  char    exatalk0116[] =" ";
static	char	exatalk0117[] ="Data input is limited to 256 characters";

#ifdef	ABAL21
static	char	exatalk9117[] ="Execution Mode";
static	char	exatalk0118[] ="Consultation Mode";
static	char	exatalk0119[] ="Stack trace examination";
static	char	exatalk0120[] ="Break point examination";
static	char	exatalk0121[] ="ABAL Error ";
static	char	exatalk0122[] ="Validate to abandon or Escape";
static	char	exatalk0123[] ="Sources";
static	char	exatalk0124[] ="Adresse";
static	char	exatalk0125[] ="Optimised variable";
static	char	exatalk0126[] ="Help";
static	char	exatalk0127[] ="Globals";
static	char	exatalk0128[] ="Locals";
static	char	exatalk0129[] ="Procedures";
static	char	exatalk0130[] ="Segments";
static	char	exatalk0131[] ="Run";
static	char	exatalk0132[] ="Goto This";
static	char	exatalk0133[] ="Step Into";
static	char	exatalk0134[] ="Step Over";
static	char	exatalk0135[] ="Return";
static	char	exatalk0136[] ="File";
static	char	exatalk0137[] ="Break";
static	char	exatalk0138[] ="Menu";
static	char	exatalk0139[] ="Set Break";
static	char	exatalk0140[] ="INTR:YES";
static	char	exatalk0141[] ="INTR:NO ";
static	char	exatalk0142[] ="PRINT";
static	char	exatalk0143[] ="HEX";
static	char	exatalk0144[] ="DEBUG";
static	char	exatalk0145[] ="Symbols Menu";
static	char	exatalk0146[] ="Functions Menu";
static	char	exatalk0147[] ="Command syntax ";
static	char	exatalk0148[] ="Tcode Offset";
static	char	exatalk0149[] ="Command file ";
static	char	exatalk0150[] ="Loading configuration";
static	char	exatalk0151[] ="End of file";
static	char	exatalk0152[] ="Line too long";
static	char	exatalk0153[] ="File not found";
static	char	exatalk0154[] ="Target filename";
static	char	exatalk0155[] ="Writing to file";
static	char	exatalk0156[] ="Error creating file";
static	char	exatalk0157[] ="Break points";
static	char	exatalk0158[] ="Stack trace";
static	char	exatalk0159[] ="Memory Watch events";
static	char	exatalk0160[] ="Observation Variables";
static	char	exatalk0161[] ="Trace Regions";
static	char	exatalk0162[] ="Assign Table";
static	char	exatalk0163[] ="Load configuration";
static	char	exatalk0164[] ="Save configuration";
static	char	exatalk0165[] ="Requires Execution Mode";
static	char	exatalk0166[] ="Start of Trace Region";
static	char	exatalk0167[] ="Source Consultation";
static	char	exatalk0168[] ="Local Variables";
static	char	exatalk0169[] ="Search for ";
static	char	exatalk0170[] = "<End de list>";
static	char	exatalk0171[] = "Symbolic file error";
static	char	exatalk0172[] = "Trace activation error";
static	char	exatalk0173[] = "Trace activated";
static	char	exatalk0174[] = "Define Trace Region";
static	char	exatalk0175[] = "Trace Region Added";
static	char	exatalk0176[] = "Sources";
static	char	exatalk0177[] = "Lists";
static	char	exatalk0178[] = "Variables";
static	char	exatalk0179[] = "Constants";
static	char	exatalk0180[] = "Procedures";
static	char	exatalk0181[] = "Segments";
static	char	exatalk0182[] = "Libraries";

#endif

#endif

#endif

static	char	exafill0001[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0002[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0003[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0004[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0005[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0006[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0007[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0008[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0009[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0010[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0012[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0013[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0014[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0015[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0016[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

#ifdef	DEBUGGER
static	char	exafill0021[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0022[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0023[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0024[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0025[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0026[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0027[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0028[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0029[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0030[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0032[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0033[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0034[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0035[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
static	char	exafill0036[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
#endif

static	char	endmsgman[] = "*ETX*";
