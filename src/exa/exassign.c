/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXASSIGN.C
 *		Version :	2.2b
 *		Date 	:	16/12/2012
 */
 
/* Mises a jour :
 * ------------
 *	11/04/97 : Correction bug Find des AGF (A.M.)
 * 17/08/2000 : (#SP)Long names support
 * 27/10/2000 : (#SP)Corrections in the setname() (ASSIGN gives an error if the filename contains symbols with code < 32)
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef	_EXASSIGN_C
#define	_EXASSIGN_C

#ifdef PROLOGUE
#define ASSIGN_NO_ANFC
#endif

#ifdef WIN32
/* AM110497
 * ATTENTION: Si vous modifiez FICBUFFLEN penser aussi a le modifier dans exoth.h !!!
 */
#define	FICBUFFLEN		276
#endif

#ifdef PROLOGUE
struct	prologue_assign	{
	EXAWORD	limit;
	BPTR	storage;
	} PrlAssign;
#endif

EXAWORD	initialise_assign_allocation( nombre, unitsize )
EXAWORD	nombre;
EXAWORD	unitsize;
{
#ifdef	PROLOGUE_SLOW
	if ((PrlAssign.storage = (BPTR) allocate((nombre+1)*unitsize)) == (BPTR) 0) {
		err_val = 27;
		return( SOFTERROR );
		}
	PrlAssign.limit  = unitsize;
#endif
	return( GOODRESULT );
}

void	liberate_assign_allocation()
{
#ifdef	PROLOGUE_SLOW
	if ( PrlAssign.storage != (BPTR) 0 ) {
		liberate( PrlAssign.storage );
		PrlAssign.storage = (BPTR) 0;
		}
#endif
	return;
}

void	liberate_for_assign( nptr ) 
BPTR	nptr;
{
#ifdef	PROLOGUE_SLOW
	EXAWORD	indent;
	EXAWORD	temp;

	if ((indent = selector_check( nptr, PrlAssign.storage )) == 0)
		return;
#endif
	liberate( nptr );
	return;
}

BPTR	allocate_for_assign( fnlen, handle )
EXAWORD	fnlen;
EXAWORD	handle;
{
#ifdef PROLOGUE_SLOW
	if ( fnlen < PrlAssign.limit )
		return((BPTR) (PrlAssign.storage + ((handle-1)  * PrlAssign.limit)) );
#endif
	return( allocate( fnlen ) );
}

extern	EXAWORD	Anfc_Mode;

#ifdef	LINUX_MNEMONICS
/* Workzone used for the substitution of mnemonic values by env values */
EXABYTE	mnemzone[2048];	
EXAWORD	mnemoffs=0;
#endif

EXAWORD	get_assign_event() { return( Anfc_Mode ); }
VOID	set_assign_event(EXAWORD v) { Anfc_Mode = v; return; }

EXAWORD	new_assign_handle(int type)	
{
	EXAWORD	i;
	EXAWORD	first;
	EXAWORD	last;
	if (!( type )) {
		first = 33; last = diezfic;
		}
	else	{
		first = 2;  last = 32;
		}
	for ( i=first; i < last; i++ ) {
		if (!( (*(AssignTable + i)).direcp )) {
			return(i);
			}
		}
	return(0);	
}

EXAWORD	drop_assign_handle( EXAWORD handle )
{
	if (!( handle ))
		return( GOODRESULT );
	/* Check first for correct ASSIGN and Handle */
	/* ----------------------------------------- */
	if ( check_valid_assign_handle( handle ) == SOFTERROR )
		return( SOFTERROR );

	/* Load file table information */
	/* --------------------------- */
	lfh = handle; 
	if ((err_val = loadfich()) != 0)
		return( SOFTERROR );

	sf_close(); 
	fidreel = EX_UNUSED_HANDLE;
	freefich(); 
	savefich();

	return( GOODRESULT );
}


#include "exanfc.c"	/* traitement ABALANFC */


EXAWORD	implicite_convert_mnemonics(EXAWORD workset)
{
	return( convert_mnemonics( workset, Anfc_Mode ) );
}

/*
 *	analyse_file_name( )
 *
 *	#BG 06/02/12: set_file_name() and analyse_file_name() replace old setname() function
 *
 * Analyse les informations d'assignation.
 * Si le service n'est pas specifié, c'est le service de MA par défaut qui s'applique.
 *
 * Format de l'assignation:
 * Path: "<path>\<filename>"
 * Url:  "[<service>://[<host>[:<port>]]]/<filename>[#label?name=value[&name=value]]
 *
 * Ex:   "sqlpgres://LOCALHOST:5432/mabase#CONNECT?user=xxx&pwd=yyy&option=zzz"
 *       "sqlpgres:///mabase"
 *       "abcriteria://LOCALHOST:7777/Z:\database\mabase"
 *       "abcriteria:///Z:\database\fic1"
 *       "cripgres://LOCALHOST:6000/mabase#CONNECT?user=xxx&pwd=yyy&option=zzz"
 *       "Z:\database\fic1"
 *       "FIC1"
 *
 * Notes:
 * - Le format sous forme d'Url avec options est incompatible avec l'utilisation des mnemoniques.
 * - Les pointeurs fidserv, fidhost, fidport, fidname, fidoption pointent sur les zones de fidurl.
 */
EXAWORD	analyse_file_name()
{
	BPTR	ptr0 = fidurl;
	BPTR	ptr;
	int KeepAll = 0;
	int IsPath = 0;
	int IsUrl = 0;

	for (ptr = ptr0; *ptr != (EXABYTE)0; ptr++)
	{
		switch (*ptr)
		{
			case ':':
				if ((KeepAll == 1) || (IsPath == 1))
					break;

				if (fidserv == (BPTR)0)
				{
					if ( (*(ptr+1) == '/') &&  (*(ptr+2) == '/') )
					{
						IsUrl = 1;
						fidserv = ptr0;
						*ptr = (EXABYTE)0;
						ptr +=2;
						ptr0 = ptr+1;
					}
				}
				else
				{
					if (ptr != ptr0)
					{
						fidhost = ptr0;
						*ptr = (EXABYTE)0;
						ptr0 = ptr+1;
					}
					else
					{
						err_val = EXER_SYNTAX; 
						return(SOFTERROR); 
					}
				}
				break;

			case '/':
				if ((IsUrl == 0) || (KeepAll == 1) || (IsPath == 1))
					break;

				if (ptr != ptr0)
				{
					if (fidhost != (EXABYTE)0)
						fidport = ptr0;
					else
						fidhost = ptr0;
					*ptr = (EXABYTE)0;
				}

				ptr0 = ptr+1;
				IsPath = 1;
				break;

			case '#':
				if ((IsUrl == 0) || (KeepAll == 1))
					break;

				IsPath == 0;

				if (ptr != ptr0)
				{
					fidname = ptr0;
					*ptr = (EXABYTE)0;
				}
				else
				{
					err_val = EXER_SYNTAX; 
					return(SOFTERROR); 
				}

				ptr0 = ptr+1;
				break;

			case '&':
				if ((IsUrl == 0) || (KeepAll == 1))
					break;

				if (fidoption != (BPTR)0)
					*ptr = ';';
				break;

			case ' ':
				// Blancs autorisés dans les chemins sous Win.
				// #BG 03/05/19 Sous UiLS4 aussi!
				if ((IsUrl == 0) || (IsPath == 1))
					break;
				if (KeepAll == 0)
				{
					err_val = EXER_SYNTAX; 
					return(SOFTERROR); 
				}
				break;

			case '(':
				KeepAll = 1;
				break;

			case ')':
				KeepAll = 0;
				break;

			default:
				if (IsUrl == 0)
					break;
				if (*(ptr+1) == (EXABYTE)0)
				{
					if (ptr != ptr0)
					{
						if (IsPath == 1)
							fidname = ptr0;
						else
							fidoption = ptr0;
					}
					else
					{
						err_val = EXER_SYNTAX; 
						return(SOFTERROR); 
					}
				}
				break;		
		}
	}

	if (KeepAll == 1)
	{
		err_val = EXER_SYNTAX; 
		return(SOFTERROR); 
	}

	if (IsUrl)
	{
		if ((fidserv == (BPTR)0) || (fidname == (BPTR)0))
		{
			err_val = EXER_SYNTAX; 
			return(SOFTERROR); 
		}

		if (fidoption != (BPTR)0)
		{
			if (cstrncmpi(fidoption, "CONNECT?", 8))
			{
				err_val = EXER_SYNTAX; 
				return(SOFTERROR); 
			}
			else
				fidoption = ptr + 8;
		}
	}
	else
		fidname = ptr0;

#ifdef	UNIX
	/* #IJM+FCH: 14/05/2002 
	   CRITERIA gets grummpy about filenames that begin with './' so this is
	   necessary to avoid silly error 30 values being returned
	*/
	if ( (*(fidname) == '.') && (*(fidname+1) == '/') && (*(fidname+2) != (BPTR)0) )
		fidname += 2;
#endif

	return( GOODRESULT );
}

/*
 *	set_file_name( )
 *
 *	#BG 06/02/12: set_file_name() and analyse_file_name() replace old setname() function
 *
 *	Allocates URL/Filename storage zone
 *	Get Assign informations.
 *	Ensures correct termination W.R.T. operating systeme requirements.
 *	Convert file name and mnemonic (ABALANFC)
 */

EXAWORD set_file_name()
{
	EXAWORD	z;
	BPTR	ptr;
	USINT	fidurl_size;

	/* Verifications preliminaires */
	/* --------------------------- */

	if (worktyp1 != VARB_STR)
	{ 
		err_val = EXER_SYNTAX; 
		return(SOFTERROR);
	}

	/* Check for starting blanks */
	while ((*workptr1 == IO_ESP) && (worklen1 > 0))
	{ 
		workptr1++; worklen1--; 
	} 

	/* Check for length */
	if (worklen1 == 0)
	{ 
		err_val = EXER_SYNTAX; 
		return(SOFTERROR); 
	}

	for (z=0; z < worklen1; z++)
	{
		if (*( workptr1 + z ) == IO_RC)
		{
			worklen1 = z;
			break;
		}
	}

#ifdef WIN32
	if ((worklen1 = lenuzend(workptr1, worklen1)) == 0) 
#else
	if ((worklen1 = lenuze(workptr1, worklen1)) == 0)
#endif
	{
		err_val = EXER_SYNTAX; 
		return(SOFTERROR); 
	}
	
	/* Check for invalid chars */
	for (ptr = workptr1; ptr - workptr1 < worklen1; ptr++)
	{
		if (*ptr < 0x20)
		{
			err_val = EXER_SYNTAX; 
			return(SOFTERROR); 
		}
	}

#ifdef	UNIX
	/* 14/05/2002 : Today we (me and fred) discovered that CRITERIA */
	/* gets grummpy about filenames that begin with './' so this is */
	/* necessary to avoid silly error 30 values being returned	*/
	/* USEIT 2.1f.27						*/
	/* ------------------------------------------------------------ */
	if ((*(workptr1+0) == '.')
	&&  (*(workptr1+1) == '/')
	&&  ( worklen1 > 2)) {
		workptr1+= 2;
		worklen1-= 2;
		}
#endif

	/* Allocate permenant storage in ASSIGN TABLE */
	/* ------------------------------------------ */

	if (Anfc_Mode & 8)
		/* Allocates 256 bytes more for Mnemonic conversion */
		fidurl_size = (USINT)(worklen1 + 256 + 6);	/* #BG Pourquoi +6? */
	else
		fidurl_size = (USINT)(worklen1 + 6);	/* #BG Pourquoi +6? */
		
	if ((fidurl = (BPTR) allocate_for_assign(fidurl_size, lfh)) == (BPTR)0)
	{
		err_val = EXER_MEMFULL; 
		return(SOFTERROR); 
	}
	ptr = fidurl;

	/* Fill Storage Zone */
	/* ----------------- */
	while (worklen1 > 0)
	{ 
		*(ptr++) = *(workptr1++); 
		worklen1--;
	}
	*(ptr++) = FILETERM;
	*(ptr++) = (EXABYTE)0;

	/* Analyse file name */
	/* ----------------- */
	if (analyse_file_name() != GOODRESULT)
	{
		liberate_for_assign(fidurl);
		return( SOFTERROR );
	}

	/* Convert file name and mnemonic (ABALANFC) */
	/* ----------------------------------------- */
	/* Prepare workptr1 for convert_mnemonics() */
	workptr1=fidname;
	worklen1=strlen(fidname);
	if (implicite_convert_mnemonics(1) != GOODRESULT)
	{
		liberate_for_assign(fidurl);
		return( SOFTERROR );
	}
	else if (fidname + worklen1 < fidurl + fidurl_size)
		/* Saves the result */
		strcpy(fidname, workptr1);
	else
	{
		liberate_for_assign(fidurl);
		return( SOFTERROR );
	}
	
	/* OK No Syntax Problems */

	return(1);
}


EXAWORD	check_implicite_join_file( jptr )
BPTR	jptr;
{
	EXAWORD	l;

	if (((l = fn_parser( (BPTR) jptr, (BPTR) askbuf, 0x0007 )) == 0)
	&&  ((l = fn_parser( (BPTR) fidname, (BPTR) askbuf, 0x0007 )) != 0)) {
		l += fn_parser((BPTR) jptr, (BPTR) (& askbuf[l]), 0x0078 );
			return( l );
			}
	else	return( 0 );
}

EXAWORD	check_implicite_base_file()
{
	EXAWORD	l;

	/* Check for implicite base file with no path device or network infos */
	/* ------------------------------------------------------------------ */
	if (((l = fn_parser( (BPTR) fidname, (BPTR) askbuf, 0x0007 )) == 0)
	&&  ((l = fn_parser( (BPTR) (*(AssignTable + fidbd)).direcp, (BPTR) askbuf, 0x0007 )) != 0)) {
		l += fn_parser((BPTR) fidname, (BPTR) (& askbuf[l]), 0x0078 );
/* #BG 06/02/12		liberate_for_assign(fidname);*/
		liberate_for_assign(fidurl);
#ifndef	UNIX
		askbuf[l++] = ' ';
#endif
		askbuf[l] = 0;

		/* Allocate permenant storage in ASSIGN TABLE */
		/* ------------------------------------------ */
/* #BG 06/02/12		if((fidname = (BPTR) allocate_for_assign((USINT) (strlen((BPTR) askbuf)+6),lfh)) == (BPTR) 0) {*/
		if ((fidurl = (BPTR) allocate_for_assign((USINT)(strlen((BPTR) askbuf) + 6),lfh)) == (BPTR) 0) {	/* #BG Pourquoi +6 */
			err_val = EXER_MEMFULL; 
			return(SOFTERROR); 
			}
/*#BG 06/02/12		memcpy( (BPTR) fidname, (BPTR) askbuf, strlen(askbuf)+1 );*/
		memcpy( (BPTR) fidurl, (BPTR) askbuf, strlen(askbuf)+1 );
		fidname = fidurl;
		}
	return(GOODRESULT);

}


/*
 *	S F _ A S S ( )
 *	---------------
 *	Voir EXSF-DOC
 */

EXAWORD	assign_failure( error_value )
EXAWORD	error_value;
{
	freefich();
	return( error_value );
}

#ifdef ASSIGN_NO_ANFC
BPTR	_DV_CTRL=(BPTR) "0_NO_CTRL";
				/* 0_NO_CTRL	avec ANFC ctrl */
				/* 1_NO_CTRL	sans ANFC ctrl */				

EXAWORD	file_or_ressource()
{
	switch ( frsplit(fidname) ) {
		case 0  :	
			/* A Ressource name */
			/* ---------------- */
			switch ( (fidperm & NGF_TYP) ) {
				case NGF_SQ   :
				case NGF_SI   :
				case NGF_MC   :
				case NGF_BD   :
				case NGF_MCBD :
#ifdef	ABALSQL
				case NGF_SQL  :
#endif

					/* These access methods fail */
					/* ------------------------- */
					return(assign_failure((err_val = 119)));
	
				default       :
	
					/* Convert to Device Type */
					/* ---------------------- */
					fidperm |= NGF_DV;
	
				}

		case 1  :	/* A file name */
				/* ----------- */
				break;
		default : return(assign_failure(errno));
		}
	return( 0 );
}
#endif


EXAWORD sf_assign()
{
	EXAWORD	dbperm;
	EX_FILE_HANDLE tmplog;
	EXAWORD	dblinkid;
	EXAWORD err;
#ifdef ASSIGN_NO_ANFC
	EXAWORD	lerrno;
	BPTR	lfidnom;
#endif

	MI_TRACE_DCL_TFN("sf_assign");
	MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- Begin"));

	/* Avoid RE-ASSIGN of Current Tcode */
	/* -------------------------------- */
	if ( lfh == 0 )
	{
		MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End (NL=0) Error0=56"));
		return( 56 );
	}

	check_debug_assign(lfh);

	/* Liberate Table entry if needed */
	/* ------------------------------ */
	if ( fidperm & ASS_NAME_VALID ) 
	{
		if ((IsExaSysLog() & SYSLOG_ASSIGN) || ((IsExaSysLog() & SYSLOG_ASSIGN_OPEN) && (fidreel != EX_UNUSED_HANDLE)))
		{
			sprintf(SysLogBuffer, "ASSIGN: WARNING: NL already used !!!! => Liberate entry: NL=%d, Handle=%08lX, Url='%s', Name='%s', Perm=%u, fidbuff=%08lX, fidblen=%u, uln=%u", lfh, fidreel, fidurl, fidname, fidperm, fidbuff, fidblen, bUserLongNames);
			ExaSysLog(EXA_SYSLOG_WARNING, SysLogBuffer);
		}
		MI_TRACE((CI_TRA_F_INFO_HIGH,ID_ASSIGN,TFN, "WARNING: NL already used !!!! => Liberate entry: NL=%d, Handle=%08lX, Url='%s', Name='%s', Perm=%u, fidbuff=%08lX, fidblen=%u, uln=%u", lfh, fidreel, fidurl, fidname, fidperm, fidbuff, fidblen, bUserLongNames));		
		(VOID) freefich();
		MI_TRACE((CI_TRA_F_INFO_HIGH,ID_ASSIGN,TFN, "NL=%d, Handle=%08lX, Url=%s, Name=%s, Perm=%u, fidbuff=%08lX, fidblen=%u, uln=%u", lfh, fidreel, fidurl, fidname, fidperm, fidbuff, fidblen, bUserLongNames));
	}

	/* Collect and establish File information pointer */
	/* ---------------------------------------------- */
	if ( fargset(1) == SOFTERROR )  
	{
		MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error1=%d", err_val));
		return(razfich(err_val));
	}

	if ( set_file_name() == SOFTERROR ) 	
	{
		MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error2=%d", err_val));
		return(razfich(err_val));
	}

	/* Collect and establish File permissions  */
	/* --------------------------------------  */
	if ( fargset(1) == SOFTERROR ) 	
	{
		MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error3=%d", err_val));
		return(assign_failure(err_val));
	}

	/* Establish File Permissions WORDSIZE */
	/* ------------------------------- */
	fidperm = ((((EXAWORD) workval1) & 0x00FF) | ASS_NAME_VALID);

	/* Establish Long Names Control */
	/* ---------------------------- */
	if (((EXAWORD) workval1) & NGF_LN)
		bUserLongNames=1;
	else
		bUserLongNames=0;

	/* Test for ASSIGN ACCESS METHOD Available */
	/* --------------------------------------- */
	if ((err_val = Available_Option((fidperm & NGF_TYP))) != 0)
	{
		MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error4=%d", err_val));
		return(assign_failure(err_val));
	}

#ifndef UNIX
#ifndef VMS

/*
 *	Ressource ou Fichier ?
 *	----------------------
 *	Due to the different actions to be performed (eg READ=1,/40 Disque  )
 *						     (.. READ=1,/60 Fichier )
 *	It is neccessary to separate the Ressource I.D mnemonics from
 *	the real file names using the special device / file separator
 */
	if ((fidperm & NGF_TYP) != NGF_IM)
	{
#ifdef ASSIGN_NO_ANFC
		if ( *_DV_CTRL != '1' )
		{
			if ((lerrno = file_or_ressource()) != 0)
				return( lerrno );
		}
		else
		{
			if (!(fidperm & NGF_TYP))
			{
				for (lfidnom = (BPTR) fidname; *lfidnom != 0; lfidnom++ )
				{
					if (( *lfidnom == '(' )
					&&  (( *(lfidnom+1) == 'd' ) || ( *(lfidnom+1) == 'D'))
					&&  (( *(lfidnom+2) == 'v' ) || ( *(lfidnom+2) == 'V'))
					&&  (  *(lfidnom+3) == ')' ))
					{
						fidperm |= NGF_DV;
						*lfidnom = 0;
						break;
					}
				}
			}		
		}
#else

		switch ( frsplit(fidname) )
		{
			case 0  :	
				/* A Ressource name */
				/* ---------------- */
				switch ( (fidperm & NGF_TYP) )
				{
					case NGF_SQ   :
					case NGF_SI   :
					case NGF_MC   :
					case NGF_BD   :
					case NGF_MCBD :
#ifdef	ABALSQL
					case NGF_SQL  :
#endif

						/* These access methods fail */
						/* ------------------------- */
						err_val = 119;
						MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error5=%d", err_val));
						return(assign_failure((err_val)));
	
					default       :
						/* Convert to Device Type */
						/* ---------------------- */
						fidperm |= NGF_DV;
				}

			case 1:
					/* A file name */
					/* ----------- */
					break;

			default :
				MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error6=%d", errno));
				return(assign_failure(errno));
		}
#endif
	}

#endif	/* VMS */
#endif	/* UNIX */

#ifdef ABALMC
	/* Special treatement for MC and MCBD Files */
	/* ---------------------------------------- */
	if ((fidperm & (NGF_MC | NGF_DV))==NGF_MC)
	{
		/* Get KEY workzone buffer pointer */
		/* ------------------------------- */
		if ( fargset(1) == SOFTERROR )
		{ 
			/* If MCBD alors Error else MC sans Tampon */
			/* --------------------------------------- */
			if (fidperm & NGF_BD) 
			{
				MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error7=%d", err_val));
				return(assign_failure(err_val));
			}
			else
			{ 
				worktyp1 = 0; workptr1 = (BPTR) 0;
			}
		}

		if ( workptr1 != (BPTR) 0 )
		{	/* Got Something 	 */
			dblinkid = workval1;	/* Keep Possible Link ID */
			fidbuff = workptr1;	/* And Buffer Pointer	 */
			fidblen = worklen1;	/* And Buffer Length     */
			/* Get KEY workzone buffer Length  */
			/* ------------------------------  */
			if ( fargset(1) == SOFTERROR )
			{ 
				if (fidperm & NGF_BD)
				{
					fidbuff = (BPTR) 0;
					fidblen = 0;
				}
			}
			else
				fidblen = (EXAWORD) workval1;
		}
		else
		{
			fidbuff = (BPTR) 0;
			fidblen = 0;

			//#BG 09/09/19 KEY auto
			if (fidperm & NGF_MC)
			{
				// Alloc initiale ici et non ds addrubr_auto() au cas ou des KEY sont a declarer explicitement
				if ( (fidbuff = (BPTR) allocate(FIC_BUFFMC_LEN)) != (BPTR) 0)
				{
					fidblen = FIC_BUFFMC_LEN;
					fidperm |= ASS_BUFF_VALID;
				}
				else
				{
					MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error8=%d", ABAL_MEMORY));
					return( assign_failure(ABAL_MEMORY) );
				}
			}
		}

#ifdef ABALBD
		/* Check if the MC file is a DATA BASE FILE (BD | MC) */
		/* -------------------------------------------------- */
		if (fidperm & NGF_BD)
		{
			MI_TRACE((CI_TRA_F_INFO_HIGH,ID_ASSIGN,TFN, "NL=%d, MC file into a DataBase, Handle=%08lX, Url='%s', Name='%s', Perm=%u, fidbuff=%08lX, fidblen=%u", lfh, fidreel, fidurl, fidname, fidperm, fidbuff, fidblen));

			/* Get DataBase linkage Number */
			/* --------------------------- */
			if (( fidblen != 0 ) && ( fidbuff != (BPTR) 0))
			{
				if ( fargset(1) == SOFTERROR ) 
				{
					MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error9=%d", err_val));
					return(assign_failure(err_val));
				}
			}
			else
				workval1 = dblinkid;

			fidbd = (EXAWORD) workval1;

			/* Check for Incorrect DATA BASE linkage */
			/* ------------------------------------- */
			if ( fidbd == lfh ) 
			{
				MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error10=%d", ABAL_NUMLOG116));
				return(assign_failure(ABAL_NUMLOG116));
			}

			/* Collect and Duplicate DATA BASE file permissions */
			/* ------------------------------------------------ */
			dbperm = (*(AssignTable + fidbd)).permf;

			/* Ensure the linkage is a DATA BASE entry */
			/* --------------------------------------- */
			if ((dbperm & NGF_TYP) != NGF_BD) 
			{
				MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error11=%d", ABAL_NUMLOG116));
				return(assign_failure(ABAL_NUMLOG116));
			}

			/* Create permissions for this SUB file */
			/* ------------------------------------ */
			fidperm |= ( dbperm & 0x000F);

			/* Handle Long Names for base files */
			/* -------------------------------- */
			bUserLongNames=(*(AssignTable + fidbd)).bUserLongNamesMode;

			/* Attempt to open the database if required */
			/* ---------------------------------------- */
			if ( (*(AssignTable + fidbd)).unlog == EX_UNUSED_HANDLE )
			{
				/* Save current context and Collect DB context */
				/* ------------------------------------------- */
				if ((err_val = savefich()) != 0)
				{
					MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error12=%d", err_val));
					return( err_val ); 
				}

				dbperm = lfh;
				lfh = fidbd;

				if ((err_val = loadfich()) != 0)
				{
					MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error13=%d", err_val));
					return( err_val ); 
				}
		
				/* Attempt to open the DATA BASE now */
				/* --------------------------------- */
				(VOID) sf_open();

				/* Check for SUCCESS and save context if OK */
				/* ---------------------------------------- */
				if (((tmplog = fidreel) != EX_UNUSED_HANDLE) &&  ((err_val = savefich()) != 0))
				{
					MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error14=%d", err_val));
					return( err_val );
				}

				/* Recover DATA BASE FILE context */
				/* ------------------------------ */
				lfh = dbperm; 
				if ((err_val = loadfich()) != 0)
				{
					MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error15=%d", err_val));
					return( err_val );
				}

				/* Check for DATA BASE SUCCESS : Else Error */
				/* ---------------------------------------- */
				if ( tmplog == EX_UNUSED_HANDLE )
				{
					MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error16=%d", err_val));
					return(assign_failure(err_val));
				}
			}

			/* Add this file to the list of DATA BASE files */
			/* -------------------------------------------- */
			MI_TRACE((CI_TRA_F_INFO_HIGH,ID_ASSIGN,TFN, "NL=%d, Add the file to the DataBase, Handle=%08lX, Url='%s', Name='%s', Perm=%u, fidbuff=%08lX, fidblen=%u, uln=%u", lfh, fidreel, fidurl, fidname, fidperm, fidbuff, fidblen, bUserLongNames));
		
			(VOID) basefile(1);

			check_implicite_base_file();
		}

#endif	/* ABALBD */
	}
#endif	/* ABALMC */

#ifdef ABALBD

	/* Establish RECORD Management Zone for Pure BD files */
	/* -------------------------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_BD ) 
	{
		err = makebase();
		MI_TRACE((CI_TRA_F_INFO_HIGH,ID_ASSIGN,TFN, "NL =%d, BD file, Handle=%08lX, Url='%s', Name='%s', Perm=%u, fidbuff=%08lX, fidblen=%u, uln=%u", lfh, fidreel, fidurl, fidname, fidperm, fidbuff, fidblen, bUserLongNames));
		MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Ret=%d", err));
		return(err);
	}

#endif	/* ABALBD */

	/* Establish Print Buffer for PRINTER Files (IM) */
	/* --------------------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_IM )
	{ 
		if ( fargset(1) != SOFTERROR ) 
			fidbuff = workptr1;
		else 
		{
			if ( (fidbuff = (BPTR) allocate((USINT) IMPR_BUF)) == (BPTR) 0) 
			{
				MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error17=%d", ABAL_MEMORY));
				return( assign_failure(ABAL_MEMORY) );
			}
			worklen1 = IMPR_BUF; 
			fidperm |= ASS_BUFF_VALID;
		}

		if ( fargset(2) != SOFTERROR ) 
			fidblen = workval2;
		else 
			fidblen = worklen1;
	}

#ifdef ABALMSG
	/* Establish MSG File ID if MSG MODULE */
	/* ----------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_CM )
	{
		fidbuff = (BPTR) 0;
		if ( fargset(1) != SOFTERROR ) 	
			fidblen = workval1;
		else
			fidblen = 0; 	
		(VOID) fargset(1);	/* Ignore possible leng */
		return(0);
	}	
#endif	/* ABALMSG */

#ifndef PROLOGUE
#ifdef  ABALSQ
	/* SQ Buffer management for Non Amenesik / Sologic O.S. 's */
	/* --------------------------------------------- */
	if (( fidperm & NGF_TYP ) == NGF_SQ )
	{
		/* Allocate Sector buffer for SQ Structure */
		/* --------------------------------------- */
#ifdef WIN32
			/* AM110497 : Sinon pb avec le find */
		if ((fidbuff = (BPTR) allocate((USINT)  FICBUFFLEN )) == (BPTR) 0 ) 
#else
		if ((fidbuff = (BPTR) allocate((USINT)  BLOCK )) == (BPTR) 0 ) 
#endif
		{
			MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Error18=%d", ABAL_MEMORY));
			return(assign_failure( ABAL_MEMORY ));
		}

		/* Set BUF FREE Flag bit */
		/* --------------------- */
		fidperm |= ASS_BUFF_VALID;
	}
#endif	/* ABALSQ */
#endif	/* ! PRL  */

#ifdef	UNIX
	if ((*fidname     == '/')
	&&  (*(fidname+1) == 'd')
	&&  (*(fidname+2) == 'e')
	&&  (*(fidname+3) == 'v')
	&&  (*(fidname+4) == '/'))
	{
		fidperm |= NGF_DV;
	}
#endif

	err = fargcheck();

	MI_TRACE((CI_TRA_F_INFO_HIGH,ID_ASSIGN,TFN, "NL=%d, Handle=%08lX, Url='%s', Name='%s', fidbuff=%08lX, fidblen=%u, fiderm=%u, buffalloc=%u, uln=%u", lfh, fidreel, fidurl, fidname, fidbuff, fidblen, fidperm, fidperm & ASS_BUFF_VALID, bUserLongNames ));
	MI_TRACE((CI_TRA_F_FUNCTION,ID_ASSIGN,TFN, "-- End Ret=%d", err));
	return(err);
}


#ifdef	ABAL21

EXAWORD	sf_name()
{
	EXAWORD	mode,xlen;
	EXAWORD	error_status;
	EXAWORD	shortsize=sizeof(short int);

	/* Collect Result Buffer Arguament */
	/* ------------------------------- */
	if ( fargset(0) == SOFTERROR )
		return( err_val );

	/* Collect Possible Buffer Length */
	/* ------------------------------ */
	if ( fargset(2) != SOFTERROR )
		worklen1 = workval2;

	/* Ensure Buffer is EXALONG enough for at least the Type */
	/* -------------------------------------------------- */
	if ( worklen1 < 2 )
		return( 30 );
	
	/* Establish FILE RIGHTS and NGF ACCESS METHOD */
	/* ------------------------------------------- */
	mode = ( fidperm & 0x00FF );
	xlen = 0;
	balputw( mode, workptr1 ); 
	

#ifdef	ABAL_LONG_NAMES
	/* Detect Long Names Options */
	/* ------------------------- */
	if ((workptr1[shortsize]  =='?')
	&&  (workptr1[shortsize+1]=='T')
	&&  (workptr1[shortsize+2]=='L')) {
		if (bUserLongNames) 
			*workptr1 |=  0x80;
		else 
			*workptr1 &= ~0x80;
		workptr1[shortsize]=' ';
		}
	else if ((workptr1[shortsize] =='?')
	     &&	(workptr1[shortsize+1]=='T')
	     &&	(workptr1[shortsize+2]=='C')) {
		if (bSystemLongNames) 
			*workptr1 |= 0x40;
		else 
			*workptr1 &= ~0x40;
		workptr1[shortsize]=' ';
		}
#endif
	workptr1 += shortsize; worklen1 -= shortsize;

	/* Calculate Assigned Name Length */
	/* ------------------------------ */ 
	while (( *(fidname + xlen) != 0 ) && ( *(fidname + xlen) != 0x000D ))
 		xlen++;

	/* Check for Data Loss : ERROR 63 */
	/* ------------------------------ */
	if ( xlen > worklen1 ) {
		error_status = 63;
		xlen = worklen1;
		}
	else	error_status = 0;

	/* Transfer FileName to Result Buffer */
	/* ---------------------------------- */	
	if ( xlen > 0 )
		memcpy( workptr1, fidname, xlen ); 

	worklen1 -= xlen;

	/* Padd String With Spaces */
	/* ----------------------- */
	if ( worklen1 > 0 ) 
		memset( (workptr1 + xlen), ' ', worklen1 );

	return( error_status );
}

	/* ------ */
#endif	/* ABAL21 */
	/* ------ */

	/* ----------- */
#endif	/* _EXASSIGN_C */
	/* ----------- */
