/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLOADGO.C				*/
/*		Version :	1.4d / 2.1d				*/
/*		Date 	:	10/04/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	05/11/93 IJM : Save and restore MIMO context			*/
/*  04/09/20 BG : Gestion mode LOAD.GO interne (VE LOADGO=1)		*/
/*----------------------------------------------------------------------*/
#ifndef EXLOADGOC		/* If not already included		*/
#define EXLOADGOC		/* Avoid multiple inclusions		*/

#include "exngf.h"


#ifdef	UNIX
static 	BPTR	UnixExecuteur(int);
#endif

#ifdef NOMIMO
#include "exmimo.c"
#endif

#ifdef NOGIGO
#include "exgigo.c"
#else
public      int     close_console_panic()   {	return(0);	}
#endif

static	EXAWORD	Robotic=0;

#define	INTERNAL_LOADGO_AT	/* Mode LOADGO=1 */

#ifdef	INTERNAL_LOADGO_AT

#include "exmacro.h"
#include "exattach.h"
#include "extimer.h"
#include "exevent.h"
#include "exptr.h"

static	EXAWORD	LoadGoMode=0;

EXTERN	EXAWORD	ExaRetCode;

struct	loadgo_context
{
	struct	loadgo_context*	previous;

	EXABYTE			trad_opt;	//#BG 25/09/20

	OVLOBJPTR		TcodeContext;			/* Program execution context */
	OVLOBJPTR		TcodeKontext;			/* Copy execution context */
	struct fichdt PTR	AssignTable;		/* Table of assigned files */
	DYNOPTR			DynamixHeap;			/* Dynamic allocation heap base */
	ATTLOGPTR		AttachmentLog;			/* Attached programs list */
	struct fusework PTR	FuseBase;			/* Dynamic libraries table */
	EXAWORD			FuseCount;				/* Number of dynamic libraries */

	EXAWORD			diezfic;
	EXAWORD			dieztmp;
	EXAWORD			diezstk;

	EXAWORD			VmemFid;
	EXAWORD			VmemLng;
	EXAWORD			VmemOfs;
	EXAWORD			VmemDif;
	EXAWORD			VmemExt;
	EXAWORD			VmemWot;
	EXAWORD			VmemHow;

	EXAWORD			ip_next; 
	EXAWORD			mindex;
	EXAWORD			worktop;
	EXAWORD			pushtop; 
	EXAWORD			pushhold; 
	EXAWORD			workhold;
	EXAWORD			StackHold;

	WPTR			TcodeWordStack;
	WPTR			TcodePushStack;
	BPTR PTR		TcodePtrStack;
	BPTR			fieldex;
	EXAWORD			fieldlen;
	BPTR			fdex;
	EXAWORD			sicico;

	EXAWORD			eventadr;
	EXAWORD			HardEvent;

	EXAWORD			timersem;
	EXAWORD			timeradr;
	EXAWORD			timercpt;

	EXABYTE			timerproc[5];
	EXABYTE			eventproc[5];

	EXAWORD			cur_seg;
	EXAWORD			SegmentCount;
	EXAWORD			procid;
	EXAWORD			procmaxid;

	EXAWORD			datadex;
	EXAWORD			datapnt;
	EXAWORD			datamax;

	BPTR			LocalDataTable;
	BPTR			GlobalDataTable;
	BPTR			TcodeByteStack;
	BPTR			LocalDataSegment;
	BPTR			GlobalDataSegment;
	BPTR			GlobalNamesTable;
	BPTR			LocalNamesTable;
	BPTR			segdata;
	BPTR			TcodeSegment;
	BPTR			TcodeConstants;
	BPTR			GlobalConstants;
	struct segmform PTR 	TcodeSegmentTable;
	ERRORPTR		GlobalErrorTrap;
	struct procform PTR	TcodeProcTable;
	BPTR			LDS_base;
	EXAWORD			LDS_dex;
	EXAWORD			extwrite;
	BPTR			Overlay_Code;
	BPTR			Overlay_Data;
	BPTR			Overlay_Const;
	BPTR			Overlay_Map;
	EXAWORD			Overlay_User;
	EXAWORD			MaxOverlayConst;
	EXAWORD			MaxOverlayCode;

	EXAWORD			IsLocal;
	EXAWORD			ToGlobal;
	EXAWORD			WordSize;
	EXAWORD			lfh;
	EX_FILE_HANDLE		TcodeFileHandle;
	/* #BG 09/09/13 */
	EXAWORD			askmask;
	EXAWORD			askcolour;
	EXAWORD			LastFore;
	EXAWORD			LastBack;

	/* ------------------------------------	*/
	/* A faire ...                          */
	/* ------------------------------------	*/
	/* reset_indirection_control(); 	*/
	/* initialise_dynamic_allocation(); 	*/
	/* initialise_attachments(); 		*/
	/* liberate_attachments();		*/
	/* liberate_indirection_control();	*/
	/* liberate_dynamic_allocation();	*/
	/* ------------------------------------	*/
	};

static	struct	loadgo_context * LoadGoHeap=(struct loadgo_context *) 0;
static	EXAWORD			 LoadGoCount=0;

extern	EXABYTE		trad_opt;	//#BG 25/09/20
extern	WORD		fieldlen;
extern	BPTR		TcodeConstants;
extern	BPTR		GlobalConstants;
extern	BPTR		LocalDataTable;
extern	BPTR		GlobalDataTable;
extern	BPTR		LocalDataSegment;
extern	BPTR		GlobalDataSegment;
extern	BPTR		GlobalNamesTable;
extern	BPTR		LocalNamesTable;
extern	BPTR		segdata;
extern	struct segmform PTR 	TcodeSegmentTable;
extern	ERRORPTR	GlobalErrorTrap;
extern	BPTR		LDS_base;
extern	EXAWORD		LDS_dex;
extern	BPTR		Overlay_Code;
extern	BPTR		Overlay_Data;
extern	EXAWORD		Overlay_User;
extern	EXAWORD		MaxOverlayConst;
extern	EXAWORD		MaxOverlayCode;
extern	BPTR		Overlay_Const;
extern	struct fusework PTR	FuseBase;
extern	EXAWORD		FuseCount;
extern	ATTLOGPTR	AttachmentLog;
extern	DYNOPTR		DynamixHeap;
extern	struct procform PTR	TcodeProcTable;
extern	OVLOBJPTR	TcodeContext;
extern	EXAWORD		pushtop;
extern	EXAWORD		pushhold;
extern	EXAWORD		cur_seg;
extern	EXAWORD		SegmentCount;
extern	EXAWORD		procid;
extern	EXAWORD		procmaxid;
extern	EXAWORD		datadex;
extern	EXAWORD		datapnt;
extern	EXAWORD		datamax;
extern	EXAWORD		StackHold;
extern	EXAWORD		eventadr;
extern	EXAWORD		HardEvent;
extern	EXAWORD		diezfic;
extern	EXAWORD		dieztmp;
extern	EXAWORD		diezstk;
extern  EXABYTE 	inbuf[];

extern	VOID			establish_indirection_control();
extern	BPTR			CopyOverlayMap();
extern	VOID			UseOverlayMap();

extern	VOID			RestoreMasterContext();
extern	OVLOBJPTR		SaveMasterContext();


EXAWORD	push_loadgo_context()
{
	struct	loadgo_context * lptr;
	/* ------------------------- */
	/* Allocate a LoadGo Context */
	/* ------------------------- */
	if (!( lptr = allocate( sizeof( struct loadgo_context ) )))
		return( 27 );
	else
	{
		/* ----------------------------- */
		/* Link to current stack context */
		/* ----------------------------- */
		lptr->previous = LoadGoHeap;
		LoadGoHeap     = lptr;
		LoadGoCount++;

		/* ----------------------- */
		/* Save all crucial values */
		/* ----------------------- */

		lptr->trad_opt = trad_opt;	//#BG 25/09/20

		lptr->lfh    = lfh;
		savefich();

		lptr->AssignTable = AssignTable;

		lptr->IsLocal=ISLOCAL;
		lptr->ToGlobal=TOGLOBAL;
		lptr->WordSize=WORDSIZE;

		lptr->diezfic=diezfic;
		lptr->dieztmp=dieztmp;
		lptr->diezstk=diezstk;

		lptr->FuseBase = FuseBase;
		lptr->FuseCount = FuseCount;
		lptr->AttachmentLog=AttachmentLog;
		lptr->DynamixHeap=DynamixHeap;
		lptr->TcodeContext=TcodeContext;


		lptr->VmemFid=VmemFid;
		lptr->VmemLng=VmemLng;
		lptr->VmemOfs=VmemOfs;
		lptr->VmemDif=VmemDif;
		lptr->VmemExt=VmemExt;
		lptr->VmemWot=VmemWot;
		lptr->VmemHow=VmemHow;
		lptr->fieldex=fieldex;
		lptr->fieldlen=fieldlen;

		lptr->StackHold=StackHold;
		lptr->ip_next=ip_next;
		lptr->mindex=mindex;
		lptr->worktop=worktop;
		lptr->pushtop=pushtop; 
		lptr->pushhold=pushhold; 
		lptr->workhold=workhold;
		lptr->TcodeWordStack=TcodeWordStack;
		lptr->TcodePushStack=TcodePushStack;
		lptr->TcodePtrStack=TcodePtrStack;

		lptr->datadex		= datadex;
		lptr->datapnt		= datapnt;
		lptr->datamax		= datamax;
		lptr->procid  		= procid;
		lptr->procmaxid		= procmaxid;
		lptr->cur_seg		= cur_seg;
		lptr->SegmentCount 	= SegmentCount;
		lptr->timersem		= timersem;
		lptr->timeradr		= timeradr;
		lptr->timercpt		= timercpt;

		memcpy( lptr->eventproc, eventproc,PTRSIZE );
		memcpy( lptr->timerproc, timerproc,PTRSIZE );

		lptr->eventadr=eventadr;
		lptr->HardEvent=HardEvent;
		lptr->fdex = fdex;
		lptr->sicico=sicico;
		lptr->TcodeConstants=TcodeConstants;
		lptr->GlobalConstants=GlobalConstants;
		lptr->LocalDataTable=LocalDataTable;
		lptr->GlobalDataTable=GlobalDataTable;
		lptr->TcodeByteStack=TcodeByteStack;
		lptr->LocalDataSegment=LocalDataSegment;
		lptr->GlobalDataSegment=GlobalDataSegment;
		lptr->GlobalNamesTable=GlobalNamesTable;
		lptr->LocalNamesTable=LocalNamesTable;
		lptr->segdata=segdata;
		lptr->TcodeSegment=TcodeSegment;
		lptr->TcodeSegmentTable=TcodeSegmentTable;
		lptr->GlobalErrorTrap=GlobalErrorTrap;
		lptr->TcodeProcTable=TcodeProcTable;
		lptr->LDS_base=LDS_base;
		lptr->LDS_dex=LDS_dex;
		lptr->extwrite=extwrite;
		lptr->Overlay_Code=Overlay_Code;
		lptr->Overlay_Data=Overlay_Data;
		lptr->Overlay_User=Overlay_User;
		lptr->Overlay_Const=Overlay_Const;

		lptr->Overlay_Map  = CopyOverlayMap();

		lptr->MaxOverlayConst=MaxOverlayConst;
		lptr->MaxOverlayCode=MaxOverlayCode;
		lptr->TcodeFileHandle = TcodeFileHandle;

		lptr->TcodeKontext=SaveMasterContext();

		lptr->askmask = askmask;
		lptr->askcolour = askcolour;
		lptr->LastFore = LastFore;
		lptr->LastBack = LastBack;
		
		return(0);
		}
}


EXAWORD	pop_loadgo_context()
{
	struct	loadgo_context * lptr;

	if (!( lptr = LoadGoHeap ))
		return(118);
	else
	{
		if ( LoadGoCount )
			LoadGoCount--;

		LoadGoHeap = lptr->previous;

		/* ----------------------- */
		/* Restore all crucial values */
		/* ----------------------- */

		trad_opt = lptr->trad_opt;	//#BG 25/09/20

		ISLOCAL = lptr->IsLocal;
		TOGLOBAL= lptr->ToGlobal;
		WORDSIZE= lptr->WordSize;

		diezfic=lptr->diezfic;
		dieztmp=lptr->dieztmp;
		diezstk=lptr->diezstk;

		FuseBase = lptr->FuseBase;
		FuseCount = lptr->FuseCount;
		AttachmentLog=lptr->AttachmentLog;
		DynamixHeap=lptr->DynamixHeap;

		TcodeContext=lptr->TcodeContext;

		VmemFid=lptr->VmemFid;
		VmemLng=lptr->VmemLng;
		VmemOfs=lptr->VmemOfs;
		VmemDif=lptr->VmemDif;
		VmemExt=lptr->VmemExt;
		VmemWot=lptr->VmemWot;
		VmemHow=lptr->VmemHow;
		ip_next=lptr->ip_next;
		mindex=lptr->mindex;
		worktop=lptr->worktop;
		pushtop=lptr->pushtop; 
		pushhold=lptr->pushhold; 
		workhold=lptr->workhold;

		StackHold=lptr->StackHold;
		TcodeWordStack=lptr->TcodeWordStack;
		TcodePushStack=lptr->TcodePushStack;
		TcodePtrStack=lptr->TcodePtrStack;
		fieldex=lptr->fieldex;
		fieldlen=lptr->fieldlen;

		procid  		= lptr->procid;
		procmaxid		= lptr->procmaxid;
		cur_seg 		= lptr->cur_seg;
		SegmentCount 		= lptr->SegmentCount;

		datadex			= lptr->datadex;
		datapnt			= lptr->datapnt;
		datamax			= lptr->datamax;

		timersem		= lptr->timersem;
		timeradr		= lptr->timeradr;
		timercpt		= lptr->timercpt;

		memcpy( eventproc, lptr->eventproc,PTRSIZE );
		memcpy( timerproc, lptr->timerproc,PTRSIZE );

		eventadr=lptr->eventadr;
		HardEvent=lptr->HardEvent;
		fdex = lptr->fdex;
		sicico=lptr->sicico;
		TcodeConstants=lptr->TcodeConstants;
		GlobalConstants=lptr->GlobalConstants;
		LocalDataTable=lptr->LocalDataTable;
		GlobalDataTable=lptr->GlobalDataTable;
		TcodeByteStack=lptr->TcodeByteStack;
		LocalDataSegment=lptr->LocalDataSegment;
		GlobalDataSegment=lptr->GlobalDataSegment;
		GlobalNamesTable=lptr->GlobalNamesTable;
		LocalNamesTable=lptr->LocalNamesTable;
		segdata=lptr->segdata;
		TcodeSegment=lptr->TcodeSegment;
		TcodeSegmentTable=lptr->TcodeSegmentTable;
		GlobalErrorTrap=lptr->GlobalErrorTrap;
		TcodeProcTable=lptr->TcodeProcTable;
		LDS_base=lptr->LDS_base;
		LDS_dex=lptr->LDS_dex;
		extwrite=lptr->extwrite;
		Overlay_Code=lptr->Overlay_Code;
		Overlay_Data=lptr->Overlay_Data;
		Overlay_User=lptr->Overlay_User;

		UseOverlayMap( lptr->Overlay_Map );

		MaxOverlayConst=lptr->MaxOverlayConst;
		MaxOverlayCode=lptr->MaxOverlayCode;
		Overlay_Const=lptr->Overlay_Const;
		TcodeFileHandle = lptr->TcodeFileHandle;
		AssignTable = lptr->AssignTable;

		RestoreMasterContext(lptr->TcodeKontext);
		
		askmask = lptr->askmask;
		askcolour = lptr->askcolour;
		LastFore = lptr->LastFore;
		LastBack = lptr->LastBack;
		
		establish_indirection_control();

		lfh = lptr->lfh;
		loadfich();

		liberate( lptr );
		
		return(0);
		}
}


EXAWORD	InternalExaCute( nptr, xl )
BPTR	nptr;
EXAWORD	xl;
{
	EXAWORD		i;
	EXAWORD		argc;
	EXAWORD		lerr;
	EX_FILE_HANDLE	lnlog;
	BPTR		largptr;
	EXAWORD		status;
	EXAWORD		HoldRetCode;
	EXAWORD		ThisRetCode;
	EXAWORD		HoldLastTcode;	//#BG 04/09/20
	
	/* Handle Command Line Type Argument */
	/* --------------------------------- */
	*(nptr+xl) = 0;
	strcpy(inbuf,nptr);
	largptr    = (nptr+xl+1);

	if ( *largptr == 0x000D )
		argc=2;
	else if ( *largptr == 0 )
		argc=2;
	else
		argc=3;
		
	/* Avoid explicite quoted arg for uce */
	/* ---------------------------------- */
	if (*largptr == '"')
	{
		largptr++;
		i = 0;
		while (1)
		{
			if ( (!(*(largptr+i))) || (*(largptr+i) == 13) )
				break;
			else if (*(largptr+i) == '"')
			{
				*(largptr+i) = ' ';
				break;
			}
			else
				i++;
		}
	}
			
	/* save current execution context */
	/* ------------------------------ */
	if ((status = push_loadgo_context()) != 0)
		return(status);

	/* Attempt to open the target file */
	/* ------------------------------- */
	else if ( (lnlog = open_tcode_file((BPTR) inbuf )) == EX_UNUSED_HANDLE )
	{

		/* restore previous context prior to error return */
		/* ---------------------------------------------- */
		pop_loadgo_context();
		return( err_val );
	}

	/* Load and Validate Tcode Header Control Block */
	/* -------------------------------------------- */
	else if ( TcodeHeader(argc,lnlog) == 0 )
	{
		/* Whoops Invalid File */
		/* ------------------- */
		lerr = err_val;
		lnlog = CloseTcodeFile( lnlog );

		(VOID) TcodeHeader(1,TcodeFileHandle);

		err_val = lerr;
		
		/* Restore previous context prior to error return */
		/* ---------------------------------------------- */
		pop_loadgo_context(); 		return( err_val );
	}
	else
	{
		/* Reset all crucial aspects of the virtual machine */
		/* ------------------------------------------------ */
		exzero();

		/*	Restart the T-Code 	*/
		/*	------------------	*/
		TcodeFileHandle = lnlog;
		loadgo = 1; sicico = 0;

		if ( tkodgo( argc , largptr ) == GOODRESULT )
		{
			loadgo=0; timersem = 0;
			HoldRetCode = ExaRetCode;
			ThisRetCode = ExaRetCode = 0;
#ifdef	DEBUGGER
			//#BG 04/09/20 Il faut memoriser LastTcode et l'initialiser a -1 pour dbmotor()
			HoldLastTcode = LastTcode;
			LastTcode = MOINS_UN;
			dbmotor();
			LastTcode = HoldLastTcode;
#else
			motor();
#endif
			ThisRetCode = ExaRetCode;
			ExaRetCode = HoldRetCode;
			pop_loadgo_context();
			return(ThisRetCode);
		}
		else
		{
			loadgo=0;
			TcodeFileHandle = CloseTcodeFile( TcodeFileHandle );
			pop_loadgo_context();
			return(err_val);
		}
	}
}

#endif	//INTERNAL_LOADGO_AT


EXAWORD	get_robotic()		{	return( Robotic );	}
VOID   	set_robotic(EXAWORD v)	{	Robotic=v;		}

VOID	get_default_loadgo_mode()
{
	BPTR	eptr;

	if (!( eptr = (BPTR) getenv("LOADGO")))
		LoadGoMode=0;
	else
		LoadGoMode = (*eptr -'0');
	if (LoadGoMode > 2)
		LoadGoMode = 0;
	return;
}


EXAWORD	get_loadgo_counter() { return( LoadGoCount ); }
EXAWORD	get_loadgo_mode() { return( LoadGoMode ); }
//VOID	set_loadgo_mode(int v) { LoadGoMode=(v&3); }	// Possible values: 0 1 2 3
VOID	set_loadgo_mode(int v) { if (v < 3) LoadGoMode=v; }	// Possible values: 0 1 2


/*
 *	I s T c o d e N a m e ( filename )
 *	----------------------------------
 *	Uses the file name parser to test for the presence of the tcode
 *	file type extension to detect tcode file names for LOAD.GO
 *
 *	Returns : 	ZERO (0)	Failure not a tcode name
 *			TRUE (1)	Success it is a tcode name
 *
 */

EXAWORD	IsTcodeName( nptr )
BPTR	nptr;
{
	EXABYTE	buffer[FNMAX];

	/* Parse filename for Extension */
	/* ---------------------------- */
	if ( fn_parser(nptr , (BPTR)buffer, 0x0010) == 3 )
	{
		/* Test for correct separator type */
		if ( (buffer[0] == '-') || (buffer[0] == '.') )
		{
			/* Test for 'at' or 'AT' etc */
			if ( (buffer[1] == 'a') || (buffer[1] == 'A') )
			{
				if ( (buffer[2] == 't') || (buffer[2] == 'T') )
					/* Success it is a Tcode Filename */
					return(1);
			}
		}
	}

	/* Failure: Not a T-Code filename */
	/* ----------------------------- */
	return(0);
}

#ifdef	UNIX

#define	EXACUTE

EXAWORD	ExaCute( BPTR cmdline, int multitask )
{
	EXAWORD	result;
	BPTR	execptr = UnixExecuteur(multitask);

	check_push_before();

//#BG 09/11/20	if ( LoadGoMode & 2 )
	if ( LoadGoMode == 2 )
		suspend_standard_events();

//#BG 09/11/20	result = x_exec( execptr, cmdline, (multitask | 256 | ((LoadGoMode & 2) ? 512 : 0)) );
	result = x_exec( execptr, cmdline, (multitask | 256 | ((LoadGoMode == 2) ? 512 : 0)) );

//#BG 09/11/20	if ( LoadGoMode & 2 )
	if ( LoadGoMode == 2 )
		resume_standard_events();

	check_pop_after();
	return( result );
}

#endif


EXAWORD	standard_loadgo(special)
EXAWORD	special;
{
	MI_TRACE_DCL_TFN("standard_loadgo");

	EXAWORD	mode;
	EXAWORD	l;
	BPTR	execptr;
	BPTR	execbuf=(BPTR)0;
	EXAWORD	result;
	EXABYTE	thismimo[32];
	EXAWORD	xl;

	EXAWORD	multitask=special&2;

	/* Check for Automatic Executeur Call */
	/* ---------------------------------- */
	if ((mode = IsTcodeName( fidname )) != 0)
	{
		/* LOAD.GO of an ABAL program */
		/* -------------------------- */

		/* #BG 22/07/16 Trace */
		MI_TRACE((CI_TRA_F_INFO_HIGH, ID_KERNEL, TFN, "LOAD.GO: pid=%u, progname=%s", getpid(), fidname));
		if (IsExaSysLog() & SYSLOG_LOAD) 
		{
			sprintf(SysLogBuffer, "LOAD.GO: progname=%s", fidname);
			ExaSysLog(EXA_SYSLOG_INFO, SysLogBuffer);
		}

		/* Prepare and analyse tcode filename */
		/* ---------------------------------- */
		if (!( execbuf = allocate( strlen( fidname ) + worklen2 + 256 )))
			return( 27 );

		l = TcodeFileName((BPTR)execbuf, fidname);
		xl = l;

		//FCH25052004 si l'appelé n'est pas trouvé, on quitte tout de suite
		if (l==0)
			return 40;

		/* Prepare parameters */
		/* ------------------ */
		if (( worklen2 > 0 ) && ( *workptr2 != 0 ) && ( *workptr2 != 0x000D ))
		{
		  	execbuf[l++] = (EXABYTE) CMDFIELD;

			while (( worklen2 > 0 ) && ( *workptr2 != 0 ) && ( *workptr2 != 0x000D ))
			{
				execbuf[l++] = *(workptr2++);
				worklen2--;
			}
		}

		worklen2 = l;
		workptr2 = (BPTR)execbuf;

#ifdef	INTERNAL_LOADGO_AT
//#BG 09/11/20		if ( LoadGoMode & 1 )
		if ( LoadGoMode == 1 )
		{
			/* New Internal Loadgo whitout flash */
			/* --------------------------------- */

			*(workptr2 + worklen2) = (EXABYTE) 0x000D;
			*(workptr2 + worklen2+1) = (EXABYTE) 0;

			save_mimo_context( (BPTR) thismimo );
			fin_mimo();
	
			// #BG 05/09/13 Sauvegarde l'ecran de l'appelant avant LOAD.GO
// Par defaut, l'affichage du programme appele reste
//#BG 25/09/20			check_push_before();

			result = InternalExaCute(workptr2,xl);

			// #BG 05/09/13 Restaure l'ecran de l'appelant apres LOAD.GO
//#BG 25/09/20			check_pop_after();

			init_mimo();
			restore_mimo_context((BPTR) thismimo );

			if ( execbuf )
				liberate( execbuf );

			return( result );
		}
		else
#endif //INTERNAL_LOADGO_AT
		{
			/* Old Windowed Loadgo */
			/* ------------------- */

			*(workptr2 + worklen2) = (EXABYTE) 0x000D;

			save_mimo_context( (BPTR) thismimo );
			fin_mimo();

			result = ExaCute((BPTR) workptr2, multitask);

			init_mimo();
			restore_mimo_context((BPTR) thismimo );

			/* # BG 26/08/20 */
			if ( execbuf )		
				liberate( execbuf );

			return( result );
		}
	}
	else
	{
		/* LOAD.GO of a System utility */
		/* --------------------------- */

		execptr = fidname;

#ifdef	ABALX11
		if (!multitask)
		{
			if (!( Robotic ))
				release_input_focus();
		}
#endif

		save_mimo_context( (BPTR) thismimo );
		fin_mimo();

		result = (EXAWORD) x_exec(execptr, workptr2, multitask);

		init_mimo();
		restore_mimo_context( (BPTR) thismimo );

#ifdef	ABALX11
		if (!multitask)
		{
			if (!( Robotic ))
				restore_input_focus();
		}
#endif

		if ( execbuf )
			liberate( execbuf );

		return (result);
	}
}

#ifdef	UNIX

EXTERN	BPTR	Exa;	/* ARGV 0 : EXA */
static 	EXABYTE	UnixExaName[256];
EXTERN	EXAWORD	AtbContext;
EXTERN	EXAWORD	LastFore;
EXTERN	EXAWORD	LastBack;
EXTERN	int	exa_is_X11;

static BPTR	UnixExecuteur(int multitask)
{
	unsigned long x_window();
	unsigned long windowid=0L;

//#BG 09/11/20	if (( exa_is_X11 > 1 ) && (!( multitask )) && (LoadGoMode & 2))
	if (( exa_is_X11 > 1 ) && (!( multitask )) && (LoadGoMode == 2))
		windowid = x_window();
	else	
		windowid = 0L;

	sprintf(UnixExaName,"%s \'-x%u:%u:%u:%u:%u:f%u:w%lu\' ", /* quote avant et apres -x */
			(BPTR) Exa,
			x_lin(1),
			x_col(1),
			AtbContext,
			LastBack,
			LastFore,
			get_pushpopid(),
			windowid 
			);

#ifdef LINUX_DB
	fprintf(stderr,"UNIXEXANAME %s\n\r",UnixExaName);
#endif
	return((BPTR) UnixExaName );
}

#endif //UNIX

/*
 *	S F _ L O A D G O ()
 *	--------------------
 *	Called from SF_NGF performs the tcode analysis and arguament
 *	preparation for the LOAD.GO functions of ABAL.
 *
 *	Two possible cases exist :
 *	- 1: Execution of a native system command or batch
 *	- 2: Execution of a Tcode Program then Return 
 *
 *	The Second case is detected by the precence of one of the tcode 
 *	standard filename extensions :
 *		.at	.At	.AT	.aT
 *		-at	-At	-AT	-aT
 *	which activates the later case.
 *	All other syntax's are submited with an eventual arguament to
 *	the systeme command executeur (Shell etc)
 *
 */
EXAWORD	sf_loadgo()
{
	EXAWORD	mode;
	EXABYTE	d[2];
	EXAWORD	special=0;

	/* Collect arguament [R] */
	/* --------------------- */
#ifdef	ABAL32A
	/* (TASK),(CAPTURE) */
	worklen3 = workval3 = special = (EXAWORD) *(fdex++);
	mode = 0;
#else
	worklen3 = workval3 = (EXAWORD) *(fdex++); mode = 0;
#endif

	/* Collect possible Arguament */
	/* -------------------------- */
	if ( fargset(2) != SOFTERROR )
	{ 
		/* Check for String (Refuse others) */
		if ( worktyp2 != VARB_STR ) 
			return(ABAL_TCODCODE);

		/* Limit to useable string length */
		worklen2 = lenuse((BPTR) workptr2 , worklen2 );
	}
	else 
	{
		/* Pas d'arguament alors Retour Chariot */
#ifdef PROLOGUE
		d[0] = (EXABYTE) 0x000D; 
#else
		d[0] = (EXABYTE) 0; 
#endif
		d[1] = (EXABYTE) 0;

		workptr2 = (BPTR) &d[0];  worklen2 = 1;
	}

	return (standard_loadgo(special));
}

#endif	/* EXLOADGOC */

/* ----- */
/* E.O.F */
/* ----- */

