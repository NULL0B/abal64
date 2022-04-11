/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXINIT.H  				*/
/*		Version	:	2.1a					*/
/*		Date 	:	03/12/1992				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXINIT_H
#define	_EXINIT_H

#include "exerrno.h"			/* Error code definitions	*/
#include "exask.h"			/* ASK control definitions	*/
#include "extmp.h"			/* Temporary allocation 	*/
#include "excico.h"			/* CICO interface definition	*/
#include "extimer.h"			/* TIMER control mechanism	*/
#include "exdieze.h"			/* Dieze Constants values	*/
#include "exovl.h"			/* Overlay control variables	*/

EXTERN	EXAWORD	simcbd;
EXTERN	EXAWORD	LastErreur;

#ifdef	VMS
EXTERN	EXAWORD	VmsBatchFlag;
#endif

/*	Structure du premier BLOC du fichier traduit -T			*/
/*	-----------------------------------------------			*/

EXTERN EXABYTE	trad_ver;	/* Version de Traducteur 		*/
EXTERN EXABYTE	trad_ind;	/* Indice Traducteur     		*/
EXTERN EXABYTE	trad_typ;	/* Marquer ABAL ='2'     		*/
EXTERN EXABYTE	trad_nom[15];	/* Nom du fichier source 		*/
EXTERN EXABYTE	trad_opt;	/* Options de traducteur
				   Bit 0	Debug / Nodebug
				   Bit 1	Clear / Noclear
				   Bit 2	Commande initial ou pas */
EXTERN EXABYTE	trad_perm;	/* Permissions de la Traducteur
				   Bit 7	Executable Oui/Non	*/
EXTERN EXAWORD  	adr_arg;	/* Adr Variable de reception Commande Init */
EXTERN EXAWORD  	adr_tcg;	/* Adresse table constantes globales 	*/
EXTERN EXAWORD  	lng_tcg;	/* Longeur de table 			*/
EXTERN EXAWORD  	adr_tvg;	/* Adr Table variable Globales 		*/
EXTERN EXAWORD  	lng_tvg;	/* Longeur de table 			*/
EXTERN EXAWORD  	adr_tfu;	/* Adr de table fonctions utilisateur 	*/
EXTERN EXAWORD  	lng_tfu;	/* Longeur de table 			*/
EXTERN EXAWORD  	adr_tsg;	/* Adr table des segments		*/
EXTERN EXAWORD  	lng_tsg;	/* Longeur de table 			*/
EXTERN EXAWORD  	adr_tpr;	/* Adr table des procedures 		*/
EXTERN EXAWORD  	lng_tpr;	/* Longeur de table 			*/
EXTERN EXAWORD	adr_npr;	/* Adr tables des noms procs		*/
EXTERN EXAWORD  	l_max_vls;	/* Longeur max tables Var Local  	*/

#ifdef DEBUGGER
EXTERN EXAWORD	MapSect;	/* Sector of Map Start			*/
EXTERN EXAWORD	LstSect;	/* Sector of List file Names		*/
EXTERN EXAWORD	StopStatus;	/* Execution of a STOP has occured	*/
#endif

#ifdef	ABAL14
EXTERN	EXAWORD	DataImageSector;
EXTERN	EXAWORD	DataImageLength;
#endif

/*		Variables globale de l'Executeur			*/
/*		--------------------------------			*/
EXTERN	EXAWORD	FuseCount;	/* Nombre de fonctions utilisateurs	*/

EXTERN	EX_FILE_HANDLE TcodeFileHandle;	/* Tcode file system handle	*/

EXTERN	struct fichdt   PTR AssignTable;      /* Tcode File Table	   */
EXTERN	struct segmform PTR TcodeSegmentTable;/* Tcode Segment Table      */
EXTERN  struct procform PTR TcodeProcTable;   /* Tcode Procedure Table    */
EXTERN	ERRORPTR	     GlobalErrorTrap;  /* On Error Goto Management */

EXTERN	BPTR  	TcodeSegment;	  /* Block of Tcode under execution     */
EXTERN	BPTR  	TcodeConstants;	  /* Current Constant Table Pointer  	*/
EXTERN	BPTR	GlobalConstants;  /* Global Constant Table Pointer	*/
EXTERN	BPTR  	GlobalDataTable;  /* Global variables description table	*/
EXTERN	BPTR  	GlobalDataSegment;/* Global variables memory storage    */
EXTERN	BPTR 	GlobalNamesTable; /* Global variables names table  	*/
EXTERN	BPTR  	LocalDataTable;	  /* Local variables description table  */
EXTERN	BPTR  	LocalDataSegment; /* Local variables memory storage   	*/
EXTERN	BPTR 	LocalNamesTable;  /* Local variables names table   	*/

EXTERN	BPTR  	fdex;		/* Pointeur des T-Codes			*/
EXTERN	BPTR  	fieldex;	/* Virtuel memory Transfer buffer	*/
EXTERN	EXAWORD	fieldlen;	/* Length of Virtuel memory Buffer	*/

EXTERN	BPTR 	proc_tabl;	/* Descripteurs varlocale Procedures	*/
EXTERN	BPTR 	proc_data;	/* Memoire des variables Procedures	*/

EXTERN	EXAWORD 	cur_seg;	/* Index Segment Courrant		*/
EXTERN	EXAWORD	ip_next;	/* Index Matrice des adresses retour	*/
EXTERN	EXAWORD 	mindex;		/* Index of pointer stack		*/
EXTERN	EXAWORD 	(*smach[16]) (); /* Matrice fonctions CLF 0 -> 16 	*/

EXTERN	EXAWORD 	var_glob,var_locl,nom_glob,len_glob,MaxOverlayCode;

#ifndef	ABAL21
EXTERN	EXABYTE	sepdec;
EXTERN	EXABYTE	defmil;
#endif

EXTERN	EXAWORD	datamax,datadex,datapnt;
EXTERN	EXAWORD	SegmentCount;
EXTERN	BPTR 	segdata;
EXTERN	EXALONG 	int rnd_var;
EXTERN	EXABYTE 	ymtabl[12];
EXTERN	EXAWORD	chain;
EXTERN	EXAWORD	loadgo;
EXTERN	EXAWORD	lfh;
EXTERN	EXABYTE	inbuf[];
EXTERN	EXAWORD	sicico;
EXTERN	EXAWORD	ExFlgSgn;
EXTERN	EXAWORD	procmaxid;
EXTERN	EXAWORD	extwrite;

#ifndef FixedRegisters
EXTERN	WPTR	Freg,Xreg,Ireg,Areg;
#else
EXTERN	EXAWORD	freg[],xreg[],ireg[],areg[];
#endif

EXTERN	EXAWORD	StackHold;
EXTERN	WPTR	TcodeWordStack;
EXTERN	BPTR (PTR TcodePtrStack);

EXTERN	EX_FILE_HANDLE VmemFid;	/* Buffer  File ID   	*/
EXTERN	EXAWORD	VmemLng;	/* Buffer  Length    	*/
EXTERN	EXALONG	VmemOfs;	/* Buffer  offset    	*/
EXTERN	EXAWORD	VmemDif;	/* = 1;			*/
EXTERN	EXAWORD	VmemExt;	/* = VmemAdj;		*/
EXTERN	EXALONG	VmemWot;	/* = adr_phy_fich;	*/
EXTERN	EXAWORD	VmemHow;	/* = dleng;		*/

/*	Executeur Speciale Functions	CLF xxxx YYYY : YYYY(xxxx) 
 *	----------------------------	--------------------------
 */

EXTERN	EXAWORD	f_clf0();
EXTERN	EXAWORD	f_clf1();
EXTERN	EXAWORD	f_clf2();
EXTERN	EXAWORD	f_clf3();
EXTERN	EXAWORD	f_clf4();
EXTERN	EXAWORD	f_clf5();
EXTERN	EXAWORD	f_clf6();
EXTERN	EXAWORD	f_clf7();
EXTERN	EXAWORD	f_clf8();
EXTERN	EXAWORD	f_clf9();
EXTERN	EXAWORD	f_clfa();
EXTERN	EXAWORD	f_clfb();
EXTERN	EXAWORD	f_clfc();
EXTERN	EXAWORD	f_clfd();
EXTERN	EXAWORD	f_clfe();
EXTERN	EXAWORD	f_clff();
#ifdef LINEAR_MEM
EXTERN	BPTR 	ExtendedMemory;
#endif
EXTERN	EXAWORD	ProcSwap;
EXTERN	EXALONG	SystemError;

#include "exvtype.h"

EXTERN	EXAWORD	lreg[64];
EXTERN	BPTR	preg[64];
#ifdef PRL_SF
EXTERN	LSEEKTYPE	fidseek;
#endif

#include "exatropt.h"			/* Translator options flags	*/
#include "exmissing.h"			/* missing prototypes 		*/

#endif	/* _EXINIT_H */
	/* --------- */
