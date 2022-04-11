/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBMENU - C				*/
/*		Version :	1.4b / 2.1a				*/
/*		Date 	:	19/09/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
#define DEBUGGER		/* IDENTIFY EXADB FOR INCLUDE FILES	*/
#define	EXDBMENUC		/* DEFINE SOURCE IDENTITY CONSTANT	*/
				/* ------------------------------------ */
#include "exdebug.h"		/* General Executeur definitions	*/
#include "exdbgrsy.h"		/* Graphique Symbols			*/
#include "exctype.h"		/* Character types and macros		*/
#include "exdbkeys.h"		/* Debug command key definitions	*/
#include "exdbtrap.h"		/* Trap management structure		*/
#include "exdbmenu.h"		/* Local Header for this file		*/
#include "exptr.h"
				/* ------------------------------------ */
#include "exproto1.h"

#define PROC_SEG_NAME_LG		16

#ifndef UNIX
VOID	raise_db_entry(VOID);
VOID	drop_db_entry(VOID);
#else
VOID	raise_db_entry();
VOID	drop_db_entry();
#endif

EXAWORD	monitor_execution_mode;
EXAWORD	DebugAssign=0;
EXAWORD	AssignBreak=0;

BPTR	interface_message( nombre )
EXAWORD	nombre;
{
	return((BPTR) TalkPtr[ 117+ nombre ] );
}

BPTR	interface_msg( nombre )
EXAWORD	nombre;
{
	return((BPTR) TalkPtr[ nombre ] );
}

EXAWORD	valid_local_data()
{
	if (( LocalDataTable   != (BPTR) 0) 
	&&  ( LocalDataSegment != (BPTR) 0 ))
		return( 1 );
	else	return( 0 );
}

EXAWORD	change_local_data()
{
	/* Test for Local Names User is current Code Block */
	/* ----------------------------------------------- */
	if (( Local_User.segproc != Local_Identity.segproc ) 
	||  ( Local_User.number != Local_Identity.number ))
		return( 1 );
	else	return( 0 );

}

EXAWORD	CurrentTcodeOffset(adjust)
EXAWORD	adjust;
{
	adjust = (fdex - TcodeSegment);
	if ( LastTcode != MOINS_UN ) 
		adjust--;
	return( adjust );
}



VOID	Establish_Local_Identity()
{
	if ((sicico & ONSEM_PRC) != 0 ) {
		Local_Identity.segproc = 1;
		Local_Identity.number  = procid;
		}
	else	{
		Local_Identity.segproc = 0;
		Local_Identity.number  = cur_seg;
		}
	return;
}

EXAWORD	identify_local_data()
{
	Establish_Local_Identity();
	return;
}

void	specify_local_data(segproc,number)
{
	Local_User.segproc = segproc;
	Local_User.number  = number;
	return;
}

#ifndef	ABAL21

/*
 *	L I S T T R A P ()
 *	------------------
 *	Affichage du liste des pieges courantes
 *
 */
VOID	listtrap()
{
	TRAPTR	ltrap;
	EXAWORD	trapdex;
	EXAWORD	x,lno,c,nbl;
	EXAWORD	width;

	/* Do nothing if no traps declared */
	/* ------------------------------- */
	if ((ltrap = TrapBase) == (TRAPTR) 0) { return; }

	/* Count Traps */
	/* ----------- */
	trapdex = 1;
	while ((ltrap = ltrap->next) != (TRAPTR) 0) { trapdex++; }

	/* Calculate Maximum Window Size */
	/* ----------------------------- */
	if (( ScreenCol - 3 ) < 52 ) 	{ c = (ScreenCol - 3);  }
	else				{ c = 52;		}
	nbl = (trapdex > 16 ? 19 : trapdex + 3);
	WdwLimit(8,nbl,c);

	/* Create Window */
	/* ------------- */
	if (PushZone(WindCord[8][0],WindCord[8][1],(trapdex > 16 ? 19 : trapdex + 3),c,0x0013,Couleurs[8][0],Couleurs[8][1]) != 0) {
		Debordement();
		return;
		}

	/* Display Description Text */
	/* ------------------------ */
	db_xcprintf((BPTR)TalkPtr[51]);
	db_xcprintf((BPTR)" : "); 
	lno = 2; x = 0;
	ltrap = TrapBase;

	/* Repeat until Not End of Liste */
	/* ----------------------------- */
	while ( ltrap != (TRAPTR) 0 ) {

		/* Display Trap Identification Number */
		/* ---------------------------------- */
		wdw_xpos(lno++,2); db_xcprintf((BPTR) " ");
		db_xcprintf((BPTR)" # "); showword(x,4);
		db_xcprintf((BPTR)"   :   ");

		/* Indicate Segment or Procedure */
		/* ----------------------------- */
		if ((ltrap->trap_state & DBTRAP_PROC) == 0) {
			db_xcprintf((BPTR)"Segment   "); 
			intvisi(ltrap->trap_block);
			}
		else	{ 
			db_xcprintf((BPTR)"Proc "); 
			AffProcName( (ltrap->trap_block * 16 ));
			}

		/* Display Offset into Code Block */
		/* ------------------------------ */
		db_xputch(':'); showword(ltrap->trap_offset,4);

		/* Indicate Permenace or OneShot */
		/* ----------------------------- */
		if ((ltrap->trap_state & DBTRAP_MODE) == DBTRAP_MODE) { 
			db_xputch(' ');
			db_xcprintf((BPTR)TalkPtr[53]);
			db_xputch(' ');
			}

		/* If Physical Page End Reached */
		/* ---------------------------- */
		if (((x + 1) % 16) == 0 ) {
			Validate(0); lno = 4;
			}

		/* Next Trap Context */
		/* ----------------- */
		x++; ltrap = ltrap->next;

		}

	/* Perform Standard Function Exit Wait */
	/* ----------------------------------- */
	switch ( ExitMethod(1) ) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		}

	/* Return without error */
	/* -------------------- */
	return;
}
VOID	listpieges()
{
	listtrap();
	return;
}
#endif


/*
 *	L o c a l _ L o a d e r ( segproc,number,old_zone)
 *	--------------------------------------------------
 *	Liberates previous and attempts to load current names
 *	table to satisfy a variable name search request.
 *
 */

#ifdef	ABAL21
VOID	version2_local_loader( segproc, number )
EXAWORD	segproc;
EXAWORD	number;
{
	collect_local_variables( segproc, (segproc ? (number * 16) : number) );

	/* Establish current user identity of local names */
	/* ---------------------------------------------- */
	specify_local_data(segproc,number);

	return;
}
#endif
 
BPTR	Local_Loader ( segproc , number , old_names , table_ptr )
EXAWORD	segproc;
EXAWORD	number;
BPTR	old_names;
BPTR	table_ptr;
{
	EXAWORD	secteur;
	EXAWORD	nb_bytes;

	/* Liberate previously allocated local names zone */
	/* ---------------------------------------------- */
	if ( old_names != (BPTR) 0 ) {
		liberate( old_names ); 
		old_names = (BPTR) 0;
		}

	/* Collect Names retrieval information */
	/* ----------------------------------- */
	var_locl =  Tcodeword( (table_ptr) );
	nb_bytes = (var_locl * 10);
	secteur  =  Tcodeword( (table_ptr + 2) );

	/* Attempt to read Local Variable Names from Disk */
	/* ---------------------------------------------- */
	old_names = (BPTR) kode_lode( secteur , nb_bytes );
	
	/* Establish current user identity of local names */
	/* ---------------------------------------------- */
	specify_local_data(segproc,number);

	/* Return a pointer to the Local Names zone */
	/* ---------------------------------------- */
	return( old_names );

}


EXAWORD	CmdWindow( nbc )
EXAWORD	nbc;
{
	EXAWORD	z;
	EXAWORD	c;
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;

	for ( z = 0; z <= nbc; z++) 
		askbuf[z] = (EXABYTE) 0;

#ifdef	BEFORE_011295
#ifdef	ABAL21
	if ( trad_ver > '1' )
		z = standard_ask( (BPTR) askbuf,nbc, (BPTR) "EXADB COMMAND SYNTAX",0 );
	else	{
#endif
		HistCtrl = 0;
		if (( ScreenCol - 6 ) < 70 ) 
			c = (ScreenCol - 6);
		else	c = 70;
		WdwLimit(5,3,c);
		if (trad_ver < '2') {
			topcol = WindCord[5][1];
			toplin = WindCord[5][0];
			}
		if (PushZone(toplin,topcol,3,c,0x0013,Couleurs[5][0],Couleurs[5][1]) != 0) {
			Debordement();
			return(0);
			}
		z = dbstrget( nbc , 1 );
		PopZone();
#ifdef	ABAL21
		}
#endif
#else
		z = standard_ask( (BPTR) askbuf,nbc, (BPTR) "EXADB COMMAND SYNTAX",0 );
#endif
	Verbose((BPTR)" ");
	HistCtrl = 0;
	return(z);
}

EXAWORD	propause()
{
	if ( ( opb() )
	&&   ( x_getch() == IO_ESC ))
		while ( 1 )
			if ( opb() ) 
				switch ((x_getch())) {
					case IO_ESC : return(0);
					case IO_RC  : return(1);
					}

	return(0);
}

#ifdef	ABAL21
EXAWORD	display_abal_variable( vnom, vid, vind, vand )
BPTR	vnom;
EXAWORD	vid;
EXAWORD	vind;
EXAWORD	vand;
{
	ColourAtb(0);
	db_xcprintf((BPTR) vnom );
	ColourAtb(2); 
	(VOID) abalprn( vid,vind,vand); 
	ColourAtb(0); 
	return;
}
#endif

/*
 *	V A R M O D ( cmdptr , modo )
 *	-----------------------------
 *	Modification des variables
 *	This routine uses the actual executeur functions to perform
 *		ASK=1:tabv(1),Variable,tabv(1)=Variable
 *	by generating a false T-Code
 *
 *	modo & 1 == 0 : Hex dump
 *	modo & 1 == 1 : Print=1:tabv(1),Variable
 *	modo & 2 == 2 : Ask=1,tabv(1)=Variable
 *
 *	modo & 4 == 4 : Indicates Permenate/Temporay Watch Variables
 *	modo & 8 == 8 : On Event ( Variable <> Previous_Value ) Debug_Break
 *
 */
EXABYTE	localname[32];

EXAWORD varmod(cmdptr,modo)
BPTR	cmdptr;
EXAWORD	modo;
{
	EXAWORD	result=0;
	EXAWORD	vid,vind,vand,plen;
	BPTR	eptr;
	BPTR	wptr;
	BPTR	xmdptr;
	EXAWORD	wlen;
	BPTR	xptr;
	EXAWORD	xlen;
	EXABYTE	c;
	EXAWORD	wlno;
	EXAWORD	width;
	EXAWORD	i;
	EXAWORD	global_flag;
	EXAWORD	topcol=1;
	EXAWORD	toplin=1;
	EXAWORD	varbnamelen=0;
#ifdef	ABAL21
	EXAWORD 	code_flag=0;
	BPTR	code_name;
	BPTR    get_code_name_by_ptr(BPTR,EXAWORD);
#endif

if ( *cmdptr == IO_NUL ) 
	return(0);
c = *cmdptr; c = toupper( c );

/* Duplicate Initial pointer for Watch Work */
/* ---------------------------------------- */	
eptr = cmdptr;

/*	Check for WATCH VARIBLE SYNTAX		*/
/*	------------------------------		*/
if ((modo & 8) == 0) {

	/* Detect and remove possible hexa request */
	/* --------------------------------------- */
	if (( c == 'H' ) && ( modo == 0 )) 
		cmdptr++;
	else	modo |= 0x0001;

	}

/* Enter Variable name parsing loop */
/* -------------------------------- */
while ( 1 ) {

	/* Eliminate White space and return if End of String */
	/* ------------------------------------------------- */
	cmdptr = CmdShift(cmdptr); 
	if ( *cmdptr == IO_NUL)
		return(0);
#ifdef	ABAL21
	/* ------------------------------------------------- */
	/* When the symbol ':' is found prefixed to the name */
	/* show procedure or segment name pointed by code ptr*/
	/* ------------------------------------------------- */ 
	if( *cmdptr == ':') {
		code_flag = 1;
		cmdptr++;
	        }
	/* ------------------------------------------------- */
	/* When the symbol '$' is found prefixed to the name */
	/* Then the search order Global / Local must be used */
	/* ------------------------------------------------- */ 
	if ( *cmdptr == '$' ) {
		global_flag = 1;
		cmdptr++;
		}
	else
#endif	
		global_flag = 0; 

	/* Scan till end of variable name */
	/* ------------------------------ */
	wptr = cmdptr; wlen = 0; i = 0;

	/* Copy the variable to display buffer */
	/* ----------------------------------- */
	while ( i < 31 ) {
		localname[i] = *(wptr + i);
		switch ( *(wptr + i) ) {
			case ' ' :
			case ')' :
			case ';' :
			case 0   : break;
			default  : i++; continue;
			}
		localname[++i] = 0; break;
		}

	while ((*wptr != ' ') && (*wptr != '(') && (*wptr != ',') && (*wptr != IO_NUL)) {
		wptr++; wlen--;
		}

	/* Establish Default Dimensions */
	/* ---------------------------- */
	vind = 1; vand = 1;

	/* Select termination character */
	/* ---------------------------- */
	switch ( *wptr ) {
		case ' '    :
		case ','    : 
			/* Terminate Name */
			/* -------------- */
			*(wptr++) = IO_NUL;

			/* Remove Separator and white space */
			/* -------------------------------- */
			wptr = CmdShift(wptr);

		case IO_NUL :

			/* Establish Name Start and Next Start pointers */
			/* -------------------------------------------- */
			xptr = wptr; wptr = cmdptr; cmdptr = xptr; break;

		case '('    :

			/* Collect Specified Dimensions */
			/* ---------------------------- */
			*(wptr++) = (EXABYTE) 0; xptr = wptr; xlen = 0;
			while (( *xptr != ',' ) && ( *xptr != IO_NUL) && ( *xptr != ')')) { 
				xptr++; xlen++; 
				}
			/* Convert 1st Dimension */
			/* --------------------- */
			vind = atoi(wptr,xlen);

			/* Check for 2nd Dimension Provided */
			/* -------------------------------- */
			if ( *xptr != ',' ) {

				/* Eliminate Right hand bracket */
				/* ---------------------------- */
				if ( *xptr == ')' ) { xptr++; }

				/* Establish Default 2nd Dimension */
				/* ------------------------------- */
				vand = 1; 

				}

			else 	{	
				/* Collect and Convert 2nd Dimension */
				/* --------------------------------- */
				xptr++;
				xlen = strlen(xptr);
				vand = atoi(xptr,xlen);
				}

			/* Point to NameStart and Next Element */
			/* ----------------------------------- */
			wptr = cmdptr; cmdptr = xptr;

			}

#ifdef	MODEL_DBGT
	/* Test for Variable identifier [XXXX] token */
	/* ----------------------------------------- */
	if ( *wptr == '[' )
		vid = HexaTcodeId( wptr );
	else
#endif
	/* Test for Variable Name Existance */
	/* -------------------------------- */
		vid = nametest( wptr, global_flag );

	if ( vid != 0 ) {

		/* Evaluate This Variable */
		/* ---------------------- */
		if ( thisvarb(vid,vind,vand,1) == SOFTERROR )
			return;

		if ( workptr1 == (BPTR) 0)
			return;

		/* Separate Display modes : HEXA or STANDARD */
		/* ----------------------------------------- */
		if (( modo & 1 ) == 0 ) { 

			if ((modo & 8) == 0 ) {
				/* Display in HexaDecimal mode */
				/* --------------------------- */
				(VOID) dumpzone(workptr1,worklen1,0);
				continue;
				}
#ifdef	ABAL14
			else	{
				/* Detect Value Supplied */
				/* --------------------- */
				cmdptr = CmdShift(cmdptr);
				switch ( *cmdptr ) {
					case '=' :
					case '!' :
					case '<' :
					case '>' :
						cmdptr = (BPTR) WatchValue((BPTR) cmdptr);
						modo |= 32;
					}
				/* Ajout d'un variable en Watch */
				/* ---------------------------- */
				(VOID) WatchMake( eptr , modo , vind , vand , vid );
				}
#endif

			}

		else	{ 
	
			if (modo & 8) {
#ifdef	ABAL14
				/* Detect Value Supplied */
				/* --------------------- */
				cmdptr = CmdShift(cmdptr);
				switch ( *cmdptr ) {
					case '=' :
					case '!' :
					case '<' :
					case '>' :
						cmdptr = (BPTR) WatchValue((BPTR) cmdptr);
						modo |= 32;
					}
				/* Ajout d'un variable en Watch */
				/* ---------------------------- */
				(VOID) WatchMake( wptr , modo , vind , vand , vid );
#endif
				}
			else	{
				/* Establish Data Type */
				/* ------------------- */
				switch ( worktyp1 & 3 ) {
					case 0 : 
					case 1 :	plen = 11; break;
					case 2 :	plen = 41; break;
					case 3 :
#ifdef ABAL21	
						if((*workptr1==PROGRAM_POINTER|| *workptr1==SEGMENT_POINTER
						||*workptr1 == PROCEDURE_POINTER)
						&&(worklen1==ABALPTRSIZE)&&code_flag)
							plen = PROC_SEG_NAME_LG +1;
						else
#endif
							plen = (worklen1+1);
					}
	
				varbnamelen = strlen((BPTR) localname );

				if (trad_ver < '2') {
					topcol = WindCord[7][1];
					toplin = WindCord[7][0];
					}
				

				/* Calculate initial coordinates */
				/* ----------------------------- */
				if (( plen + (varbnamelen+3) ) < (ScreenCol - WindCord[7][1]) ) {
					width = plen + (varbnamelen+3);
					wlno  = 3;
					}
				else	{	
					width = (ScreenCol - topcol);
					wlno = (((plen + varbnamelen) / width ) + 3 );
					}
	
				/* Limit Coordinates then Display Window */
				/* ------------------------------------- */
				WdwLimit(7,wlno,width);
				if (PushZone(toplin,topcol,wlno,width,0x0013,Couleurs[7][0],Couleurs[7][1]) != 0 ) {
					(VOID) dumpzone(workptr1,worklen1,0);
					continue;
					}
#ifdef	ABAL21
				set_mouse_control( topcol, toplin, width, wlno );
#endif
				/* Display variable identification */
				/* ------------------------------- */
				db_xcprintf((BPTR) localname );
		
				/* -------------------------------------------- */
				/* Perform TCODE GENERATION/EXECUTION of 	*/
				/* -------------------------------------------- */
				/* PRINT=1:ATB(2),VARIABLE,ATB(0),TAB(1,LIN(1)) */
				/* -------------------------------------------- */
#ifdef	ABAL21
				   if(code_flag)
				   {
					db_xputch('>');
					wlno = db_xcol();
					ColourAtb(2); 
					code_name=get_code_name_by_ptr(workptr1,worklen1);
						if(code_name != (BPTR)0)
					       	      db_xcprintf(code_name);
						else
						      (VOID) abalprn( vid,vind,vand); 	
					ColourAtb(0); 
				   }	
				   else
#endif
				   {
					db_xputch('=');
					wlno = db_xcol();
					ColourAtb(2); 
					(VOID) abalprn( vid,vind,vand); 
					ColourAtb(0); 
				   }

				wdw_xpos(1,(varbnamelen+3));
	
				}

			}	
		/* Detect Variable modification request */
		/* ------------------------------------ */
		if (( modo & 2 ) != 0 ) { 	

			if ( worklen1 > 256 )
				Verbose((BPTR) TalkPtr[117] );

			/* Perform modification via ASK */
			/* ---------------------------- */
			result = abalask( vid,vind,vand); 

			/* Leave modified value displayed */
			/* ------------------------------ */
			switch ( result ) {
				case	0	:
				case	256	:
				case	13	: LibZone(); break; 
				case	5	:
				case	11	:
				case	27	: PopZone();
				}
#ifdef	ABAL21
			pop_mouse();	
#endif
			}
		else	{

			/* Check for not Watch Variable request */
			/* ------------------------------------ */
			if (( modo & 8 ) == 0) {

				/* Variable display require validation */
				/* ----------------------------------- */
				switch ( ExitMethod(1) ) {
					case 0 : PopZone(); break;
					case 1 : LibZone(); break;
					}
#ifdef	ABAL21
				pop_mouse();
#endif
				}
			 }
		}

	else 	{ 
		Verbose((BPTR)TalkPtr[59]);
		/* "Variable inconnue" */
		/* ------------------- */
		}

	}

return(result);
}

/*
 *	S E G T A B ()
 *	--------------
 *
 */

#ifdef	MODEL_DBGT

VOID	segtab(x)
EXAWORD	x;
{
	EXABYTE	c;
	struct segmform SPTR wptr;
	wptr = (struct segmform SPTR) TcodeSegmentTable;
	newlyne();	db_xcprintf((BPTR)"Segment ID          : ");
			intvisi( (*(wptr + x) ).segm_ID );
	newlyne();	db_xcprintf((BPTR)"Adresse disque CODE : ");
			intvisi( (*(wptr + x) ).segm_AC );
	db_xputch('\t');	db_xcprintf((BPTR)"Longeur totale CODE : ");
			intvisi( (*(wptr + x) ).segm_LC );
	newlyne();	db_xcprintf((BPTR)"Adresse disque DATA : ");
			intvisi( (*(wptr + x) ).segm_AD );
	db_xputch('\t');	db_xcprintf((BPTR)"Longeur totale DATA : ");
			intvisi( (*(wptr + x) ).segm_LD );
	newlyne();
	return;
}


/*
 *	I N F O G E N ()
 *	----------------
 *	Informations suplimentaire sur l'etat courante de l'execution
 *
 */

VOID	infogen()
{
	EXABYTE	c;
	EXAWORD	lno;
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;
	if (trad_ver < '2') {
		topcol = WindCord[5][1];
		toplin = WindCord[5][0];
		}

	if (PushZone(WindCord[5][0],WindCord[5][1],10,60,0x0013,Couleurs[5][0],Couleurs[5][1]) != 0) {
		Debordement();
		return;
		}

	lno = 1;
	wdw_xpos(lno++,2);
	db_xcprintf((BPTR)"Tableaux de bord de l'executeur"); 
	wdw_xpos(lno++,2);

	wdw_xpos(lno++,2);
	db_xcprintf((BPTR)"Table Var.Gl : "); showptr(GlobalDataTable);
	db_xputch('\t');	db_xcprintf((BPTR)"Zone  Var.Gl : "); showptr(GlobalDataSegment);
	wdw_xpos(lno++,2);
	db_xcprintf((BPTR)"Table Var.Lo : "); showptr(LocalDataTable);
	db_xputch('\t');	db_xcprintf((BPTR)"Zone  Var.Lo : "); showptr(LocalDataSegment);
	wdw_xpos(lno++,2);
	db_xcprintf((BPTR)"Table Segs   : "); showptr(TcodeSegmentTable);
	db_xputch('\t');	db_xcprintf((BPTR)"Zone  Segs   : "); showptr(TcodeSegment);
	wdw_xpos(lno++,2);
	db_xcprintf((BPTR)"Table Procs  : "); showptr(TcodeProcTable);
	db_xputch('\t');	db_xcprintf((BPTR)"Zone  Const  : "); showptr(TcodeConstants);
	wdw_xpos(lno++,2);
	db_xcprintf((BPTR)"Travail Temp : "); showptr(TcodeByteStack);
	db_xputch('\t');	db_xcprintf((BPTR)"Travail Indx : "); showword(worktop,4);

	/* Perform Standard Function Exit Wait */
	/* ----------------------------------- */
	switch ( ExitMethod(1) ) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		}

	return;
}


/*
 *	G E T P T R ()
 *	--------------
 *	Saisie d'un valeur type Pointeur en Hexadecimale
 *
 */
BPTR	getptr()
{
#ifdef HALFSIZE
	return( (BPTR) gethint() );
#else
	EXALONG	l;
	EXAWORD	z;
	z = gethint();
	l = (EXALONG) z;
	l <<= 16;
	z = gethint();
	l |= (EXALONG) z;
	return((BPTR) l);
#endif
}

EXAWORD	DebLine( lno , cno )
EXAWORD	lno,cno;
{
	db_xpos(lno++,cno); db_xputch(GRSYM_B3); db_xputch(' ');
	return(lno);
}

VOID	FinLine( cno )
EXAWORD	cno;
{
	while ( db_xcol() < cno ) { db_xputch(' '); }
	db_xputch(GRSYM_B3);
	return;
}
#endif	/* MODEL_DBGT */



/*
 *	D U M P Z O N E ()
 *	------------------
 *	Affichage en forme d'une ligne d'octets ( x 16 )
 *	d'une zone memoire
 *
 */
VOID	show_nibble(natb,topcol,toplin, paragraph, offset, nibble, mptr )
EXAWORD	natb;
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	paragraph;
EXAWORD	offset;
EXAWORD	nibble;
BPTR	mptr;
{
	EXAWORD	c;
	BPTR	wptr;

	wdw_xpos( toplin+paragraph, topcol+(offset*3));
	wptr = (mptr + ((paragraph-1) * 16) + offset);
	if ( VerifPtr( wptr ) == 0 ) {
		ColourAtb( natb );
		showword( *wptr, 2 );
		}
	else	{
		db_xputch(' ');
		db_xputch(' ');
		}
	wdw_xpos( toplin+paragraph, topcol+(offset*3)+nibble);
	return;
}

VOID	put_nibble(v,paragraph, offset, nibble, mptr )
EXAWORD	v;
EXAWORD	paragraph;
EXAWORD	offset;
EXAWORD	nibble;
BPTR	mptr;
{
	EXAWORD	c;
	BPTR	wptr;

	wptr = (mptr + ((paragraph-1) * 16) + offset);
	if ( VerifPtr( wptr ) == 0 ) {
		if ( nibble )
			*wptr = ((*wptr & 0x00F0) | v);
		else	*wptr = ((*wptr & 0x000F) | (v << 4));
		}
	return;
}

VOID	attempt_zoom_pointer( memptr )
BPTR	memptr;
{
#ifdef	ABAL21
	BPTR	wptr;
	BPTR	ReadPtrVariable( BPTR );

	switch ( *memptr ) {
		case 1 :
		case 3 :
			if ((wptr = ReadPtrVariable( memptr )) != (BPTR) 0)
				dumpzone( wptr, 1, 1 );
		}
#endif
	return;
}


#include "exdbdump.c"

#ifdef	MODEL_DBGT

/*	Help screen for advanced Moniteur/Debugger	*/
/*	------------------------------------------	*/
/*	List of valid TCODE segment Mnemonics		*/

VOID	dumphelp()
{
	EXAWORD	lno;
	/* Attempt to open a window */
	/* ------------------------ */
	if (PushZone(6,2,10,65,0x0013,Couleurs[0][0],Couleurs[0][1]) != 0) {
		Debordement();
		return;
		}

	lno = 2;
	db_xpos(lno++,3); db_xcprintf((BPTR) "Aide memoire des mnemonics des segments de l'executeur ABAL : ");
	db_xpos(lno++,3);
	db_xpos(lno++,3); db_xcprintf((BPTR) "CS   ... T-Code Segment    CT   ...  Table des segments ");
	db_xpos(lno++,3); db_xcprintf((BPTR) "GS   ... Memoire Globale   GT   ...  Table Variable Globales");
	db_xpos(lno++,3); db_xcprintf((BPTR) "LS   ... Memoire Locale    LT   ...  Table Variable Locales ");
	db_xpos(lno++,3); db_xcprintf((BPTR) "WS   ... Zone temporaire   KS   ...  Zone Constantes ");
	db_xpos(lno++,3); db_xcprintf((BPTR) "Seg:offs Zone quelconque   PT   ...  Table Procedures");
	db_xpos(lno++,3); 

	/* Allow Choice of ESCAPE of VALIDATION */
	/* ------------------------------------ */
	switch ( ExitMethod(1) ) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		}
	return;
}

/*
 *	I N F O V I E W ( cmdptr )
 *	--------------------------
 *	Informations concernant l'executeur Moniteur
 */

VOID	infoview( cmdptr )
BPTR	cmdptr;
{
	EXAWORD	xl,cid;
	EXAWORD	csval,ipval;
	EXAWORD	modo;
	EXALONG	dwork;
	BPTR	wptr;
	BPTR	dptr;
	EXABYTE	c;

	cmdptr = CmdShift(cmdptr);
	c = *cmdptr; c = toupper(c); cmdptr++;
	if (( c == 'S' ) || ( c == 'P' )) {
		xl = strlen(cmdptr); cid = atoi(cmdptr,xl);
		}
	switch ( c ) {
		case 'E'	: /* Bascule Flag d'action des erreurs */
				  /* --------------------------------- */
				  if ( ErrorMode == 0 ) { ErrorMode = 1; }
				  else			{ ErrorMode = 0; }
				  return;
		case 'D'	: cmdptr = CmdShift(cmdptr);
				  wptr = cmdptr; xl = 0;
				  while (( *wptr != ':') && ( *wptr != IO_NUL)) {
					wptr++; xl++;
					}
				  if ( *wptr != ':' ) dptr = GlobalDataSegment;
				  else {
					c = *cmdptr; c = toupper(c);
					modo = 0;
					switch ( c ) {
						case 'H' : dumphelp(); return;
						case 'T' : modo++;
						case 'P' : modo++;
						case 'W' : modo++;
						case 'K' : modo++;
						case 'C' : modo++;
						case 'G' : modo++; 
						case 'L' : modo++;
						}
					if ( modo != 0 ) {
						c = *(cmdptr + 1);
						c = toupper(c);
						if ( c == 'S' ) { modo |= 0x0080; }
						if ( c == 'T' ) { modo |= 0x0040; }
						}
					switch ( modo ) {
						default:
						case 3 :
						case 2 :
						case 1 :
						case 0 : csval = hextoi(cmdptr,xl);
							 dwork = (EXALONG) csval;
							 dwork <<= 16; 
							 dptr = (BPTR) dwork;
							 break;
						case 0x0081 : dptr = LocalDataSegment; break;
						case 0x0041 : dptr = LocalDataTable; break;
						case 0x0082 : dptr = GlobalDataSegment; break;
						case 0x0042 : dptr = GlobalDataTable; break;
						case 0x0083 : dptr = TcodeSegment; 	break;
						case 0x0084 : dptr = TcodeConstants; break;
						case 0x0085 : dptr = TcodeByteStack; break;
						case 0x0045 : dptr = (BPTR) TcodeProcTable; break;
						case 0x0087 : dptr = (BPTR) IP_Hold; break;
						case 0x0047 : dptr = (BPTR) Minder; break;
						case 0x0043 : dptr = (BPTR) TcodeSegmentTable; break;	
						}
					cmdptr += xl;
					cmdptr++;
					}
				  xl = strlen(cmdptr); ipval = hextoi(cmdptr,xl);
				  dptr += ipval;
				  (VOID) dumpzone(dptr,0,0); break;
		case 'V'	: c = *cmdptr; c = toupper(c);
				  varlook((EXAWORD) c);
				  break;
		case IO_NUL 	:
		case 'G'	: infogen(); break;
		case 'S'	: xl = seg_find(cid);
				  if ( xl != MOINS_UN ) { (VOID) segtab(xl); }
				  break;
		case 'P'	: break;
		}
	return;
}

#endif


/*
 *	E X E C S Y S ()
 *	----------------
 *	Chargement et appel d'un utilitaire systeme
 *
 */
VOID	execsys(cmdptr)
BPTR	cmdptr;
{
	BPTR	wptr;
	BPTR	aptr;
	BPTR  pptr;
	EXAWORD	err;
	EXAWORD	lno,cno;

	/* Remove all leading white space */
	/* ------------------------------ */
	while (((*cmdptr == ' ') || (*cmdptr == 0x0009)) && (*cmdptr != IO_NUL)) {
		cmdptr++;
		}
	/* Check for Nothing to be done */
	/* ---------------------------- */
	if ( *cmdptr == IO_NUL ) {
		return;
		}

	/* Establish pointer to start of command */
	/* ------------------------------------- */
	err = 0; wptr = cmdptr;

	/* First Clear the Screen */	
	/* ---------------------- */
	lno = db_xlin(); cno = db_xcol(); db_Cls();

	/* Then Execute Command */
	/* -------------------- */

#ifndef	PROLOGUE
#ifndef	DOS
	/* ----------- */
	/* UNIX or VMS */
	/* ----------- */

	/* Execute command with systeme IO context */
	/* --------------------------------------- */
	finterm(1); err = system(wptr); initerm();
	err = 0;
#endif
#endif

#ifndef	UNIX
#ifndef	VMS
	/* ---------- */
	/* DOS or PRL */
	/* ---------- */

	/* Point to command name */
	/* --------------------- */
	aptr = wptr;

	/* Scan past the command to the parameters */
	/* --------------------------------------- */
	while ((*aptr != IO_NUL) && (*aptr != IO_ESP) && (*aptr != '\t') && (*aptr != ',')) {
		aptr++; 
		}
#ifdef	PROLOGUE

	/* Terminate the command Name */
	/* -------------------------- */
	*(aptr++) = RETCHAR;

#else
	*(aptr++) = IO_NUL;

#endif

	/* Scan to start of parameters */
	/* --------------------------- */
	while (( *aptr == IO_ESP ) || ( *aptr == '\t' ) || ( *aptr == ',')) {
		aptr++; 
		}

	/* Point to start of parameters */
	/* ---------------------------- */
	pptr = aptr; worklen2 = 0;

	/* Count parameter length */
	/* ---------------------- */
	while ( *aptr != IO_NUL ) { aptr++; worklen2++; }

#ifdef	PROLOGUE

	*(aptr++) = RETCHAR;

#else	

	*(aptr++) = IO_NUL;

#endif

	/* -------- */
#ifdef	   PROLOGUE
	/* -------- */
	err = exec((BPTR) wptr,(BPTR) pptr,0);

	/* ----- */
#else	/* MSDOS */
	/* ----- */

	err = x_exec((BPTR) wptr,(BPTR)pptr);
#endif
#endif
#endif

	/* Pause then Refresh Screen */
	/* ------------------------- */
	Validate(0);			/* Perform Pause 	*/
	db_Refresh(); 			/* Refresh Screen	*/
	db_xpos(lno,cno);		/* Restore Curser	*/
	return;				/* Return to Caller	*/

}


VOID	ShowHelp(firstmsg,lastmsg,nbl )
EXAWORD	firstmsg;
EXAWORD	lastmsg;
EXAWORD	nbl;
{
	EXAWORD	msgid;
	EXAWORD	lno;

#ifdef	BUF_CICO
	/* Activate Screen buffering Now */
	/* ----------------------------- */
	x_bstart();
#endif		
	/* Display the Help Messages FirstMsg to LastMsg */
	/* --------------------------------------------- */
	for (lno=1,msgid=firstmsg; msgid <= lastmsg, nbl > 0; msgid++, nbl--) {

		/* Check for Messages too EXALONG */
		/* --------------------------- */
		if ( strlen((BPTR) TalkPtr[msgid]) >= (ScreenCol - 4)) {

			/* Limit Message Length */
			/* -------------------- */
			*((BPTR) (TalkPtr[msgid] + (ScreenCol - 4))) = (EXABYTE) 0;
			}

		/* Position Curser and Display Message */
		/* ----------------------------------- */
		wdw_xpos(lno++,2);
		db_xcprintf((BPTR) TalkPtr[msgid] );
		}
		
#ifdef	BUF_CICO
	/* Flush Buffers */
	/* ------------- */
	x_bflush();
#endif		

	return;
}

EXAWORD	HelpWindow( firstmsg, lastmsg )
EXAWORD	firstmsg;
EXAWORD	lastmsg;
{
	EXAWORD	nbl;
	EXAWORD	topcol=2;
	EXAWORD	toplin=2;

	/* Calculate Number of Lines Needed */
	/* -------------------------------- */
	nbl = (lastmsg - firstmsg + 3); 
	if ( nbl >= (ScreenLin - 1) ) { nbl = (ScreenLin - 1); }

	WdwLimit(10,nbl,(ScreenCol - 2));
	if (trad_ver < '2' ) {
		topcol = WindCord[10][1];
		toplin = WindCord[10][0];
		}

	/*	Establish Help Window 	*/
	/*	---------------------	*/
	if (PushZone(toplin,topcol,nbl,(ScreenCol - 2),0x0013,Couleurs[10][0],Couleurs[10][1]) != 0 ) {
		Debordement();
		return(0);
		}

	nbl -= 2;
	return(nbl);

}
	
/*
 *	H E L P S C R (firstmsg,lastmsg)
 *	--------------------------------
 *	Affichage d'ecran d'aide du Moniteur
 *
 *	Aide Niveau 1	'H'	: Commandes compatible moniteur BAL
 *	Aide Niveau 2  Ctrl H	: Commandes suplimentaire EXADB
 *
 *	'H' 	: 33 to 49
 *
 * 	V 1.4a 	: 33 to 50 then FIRSTMSG14 to LASTMSG14
 *
 *
 *	 Ctrl H : 13 to 32
 *
 */

VOID	helpscr(firstmsg,lastmsg)
EXAWORD	firstmsg,lastmsg;
{
	EXAWORD	lno,msgid,nbl;

#ifdef	ABAL14
	if ( firstmsg == 33 ) { lastmsg = 50; }
#endif
	/* Display the Help Window */
	/* ----------------------- */
	if ((nbl = HelpWindow( firstmsg, lastmsg)) == 0)  {
		return;
		}

	/* Display the required Help Screen */
	/* -------------------------------- */	
	ShowHelp(firstmsg,lastmsg,nbl );


#ifdef	ABAL14

	/* Display Secondary help screen of NEW commands */
	/* --------------------------------------------- */
	if ( firstmsg == 33 ) {

		/* Allow validation */
		/* ---------------- */
		Validate(2);

		/* Create a New Window */
		/* ------------------- */
		if (( nbl = HelpWindow(FIRST_MSG_14,LAST_MSG_14)) != 0 ) {

			/* Display the NEW 1.4A Help Screen */
			/* -------------------------------- */	
			ShowHelp(FIRST_MSG_14,LAST_MSG_14,nbl );

			/* Liberate last pushed Zone */
			/* ------------------------- */
			LibZone();

			}
		}
#endif
	/* Await Validation : Restore Zone Contents */
	/* ---------------------------------------- */
	Validate(2);
	PopZone(); 

	return;

}

#ifdef  ABAL21
EXAWORD	Nouvelle( lno )
EXAWORD	lno;
{
	if ( lno < (WindCord[1][0]+19)) {
		db_xpos(lno++,(WindCord[1][1]+1));
		return( lno );
		}

	switch ( ExitMethod(3) ) {
		case 0 : PopZone(); return(0);
		case 1 : LibZone(); return(0);
		}
		
	db_xpos((lno = (WindCord[1][0]+2)),(WindCord[1][1]+1));
	return( ++lno );

}

#else
#include "exdbstac.c"
#endif

#ifdef	ABAL21
#define	DB_INFO_ZONE_SIZE 40
#else
#define	DB_INFO_ZONE_SIZE 30
#endif

VOID	WhereAreWe( lno , cno )
EXAWORD	lno,cno;
{
	EXAWORD	x;
	BPTR	current_tcode_filename();
#ifdef	ABAL21
	BPTR	get_procedure_name( EXAWORD );
#endif
	
	/* Check for source following or Offset following mode */
	/* --------------------------------------------------- */
	if ( lno == 1 ) { 

		/* Next line and clear till end of line */
		/* ------------------------------------ */
		x_newlyne(); db_xatb(21);
		}
	else		{ 
		/* Position to indicated position and wipe till end of zone */
		/* -------------------------------------------------------- */
		db_xpos(lno,cno);
		for ( x = 1; x < DB_INFO_ZONE_SIZE; x++) { db_xputch(' '); }
		db_xpos(lno,cno);
 		}

#ifdef	ABAL21
	/* Display Tcode Program Identity */
	/* ------------------------------ */
	db_xcprintf((BPTR) current_tcode_filename());
#endif

	/* Display Current Segment Identity */
	/* -------------------------------- */
	db_xputch('('); x_intvisi(cur_seg);	db_xputch(':');

	/* Display current procedure if in procedure */
	/* ----------------------------------------- */
	if ( sicico & ONSEM_PRC ) { 
#ifdef	ABAL21
		if ( trad_ver > '1' )
			db_xcprintf((BPTR) get_procedure_name((procid * 16)) );
		else
#endif
			AffProcName(( procid * 16 )); 
		db_xputch(':'); 
		}

	/* Display current tcode adresse offset value */
	/* ------------------------------------------ */
	showword( (EXAWORD) CurrentTcodeOffset(0) , 4); db_xputch(')');

	return;
}

#ifndef	ABAL21
EXAWORD	watchdex;		/* Watch counter			*/
EXAWORD	watchmat[16];		/* Watch matrix				*/
EXAWORD	watchind[16];		/* 1st Index				*/
EXAWORD	watchand[16];		/* 2nd index				*/
EXAWORD	watchtyp[16];		/* Type de Variable			*/
EXAWORD	watchgod[16];		/* Procedure ou Segment (for locales )	*/
VOID	Observe()
{
	EXAWORD	lwatch;
	EXAWORD	lno,x,y;
	EXABYTE	lbuf[8];

if ( watchdex > 0 ) {
	/* Count the Observation Variables to Be Displayed */
	/* ----------------------------------------------- */
	lwatch = 0; 
	for ( lwatch = 0, x = 0; x < watchdex; x++ ) {
		if ( watchmat[x] & ISLOCAL ) { /* Alors VARLOC */
			if ( sicico & ONSEM_PRC ) {
				if (( watchtyp[x] & 0x0010 ) == 0 ) 	{ continue; }
				if ( procid != watchgod[x] ) 		{ continue; }
				}
			else	{
				if (( watchtyp[x] & 0x0010 ) != 0 ) 	{ continue; }
				if ( cur_seg != watchgod[x]) 		{ continue; }
				}
			}
		lwatch++;
		}
	/* Immediate return if no Observations Active */
	/* ------------------------------------------ */
	if ( lwatch == 0 ) { return; }

	ColourAtb(0); 
	WdwLimit(4,(lwatch+2),(ScreenCol-2));
	if ( PushZone(WindCord[4][0],WindCord[4][1],(lwatch+2),(ScreenCol-2),0x0013,Couleurs[4][0],Couleurs[4][1]) != 0 ) {
		Debordement();
		return;
		}

#ifdef	BUF_CICO
	x_bstart();
#endif		
	/* Start of actual Observation Cycle */
	/* --------------------------------- */
	for (lno = 1, x = 0; x < watchdex; x++ ) {

		y = watchmat[x];

		/* Filter Out Invisible Local Variables */
		/* ------------------------------------ */
		if ( y & ISLOCAL ) { /* Alors VARLOC */
			if ( sicico & ONSEM_PRC ) {
				if (( watchtyp[x] & 0x0010 ) == 0 ) 	{ continue; }
				if ( procid != watchgod[x] ) 		{ continue; }
				}
			else	{
				if (( watchtyp[x] & 0x0010 ) != 0 ) 	{ continue; }
				if ( cur_seg != watchgod[x]) 		{ continue; }
				}
			}

		/* Display Variable and Indices */
		/* ---------------------------- */
		wdw_xpos(lno,1); TcodePmot((BPTR) &lbuf[0] , y);
		ColourAtb(2); (VOID) affvarb((BPTR) &lbuf[0]); 
		if (( watchtyp[x] & 0x0040 ) != 0 ) { 
			db_xputch('('); 
			if ( watchind[x] != 0 ) { intvisi( watchind[x] ); }
			else			{ db_xputch('*');	  }
			if (( watchtyp[x] & 0x0020 ) != 0 ) {
				db_xputch(','); 
				if ( watchand[x] != 0 ) { intvisi( watchand[x] ); }
				else			{ db_xputch('*');	  }
				}
			db_xputch(')');
			}
		wdw_xpos(lno++,18); ColourAtb(0);
		freg [COPYREG] = watchmat[x]; ireg [COPYREG] = watchind[x];
		areg [COPYREG] = watchand[x]; xreg [COPYREG] = 0x0002;
		if ( argset(4,COPYREG,2) != SOFTERROR ) {
			y = 16;
			while (( worklen2 > 0 ) && ( y > 0 )) {
				db_xputch(' ');
				showword( ((EXAWORD) *(workptr2++)) , 2);
				worklen2--; y--;
				}
			}
		else	{
			/* Handle Variable Display Errors (127 etc ) */
			/* ----------------------------------------- */
			db_xcprintf((BPTR)TalkPtr[2]);
			db_xcprintf((BPTR)" # ");
			intvisi( err_val );
			}
		}
#ifdef	BUF_CICO
	x_bflush();
#endif		
	if ( lno > (ScreenLin - ListLigne)) { 
		switch ( ExitMethod(1) ) {
			case 0 : PopZone(); break;
			case 1 : LibZone(); break;
			}

		} 
	else	{ LibZone(); }
	}
ColourAtb(0);
return;
}
#endif

#ifdef	BEFORE_011295
/*
 *	P R O M P T ( )
 *	---------------
 *	Regeneration of Current T-Code Execution point page
 *
 */

VOID	prompt_version1()
{
	EXAWORD	lnoprmt;
	EXAWORD	RetStatus;
	EXAWORD	HoldView;

	/* Fenetre de suivi du liste */
	/* ------------------------- */
	if ( ListStatus & 0x0001 ) {

#ifdef	MODEL_DBGT
		HoldView = ScreenFlg;
		ScreenFlg &= 0xFFFE;
#endif

		/* Update Screen Window Infos */
		/* -------------------------- */
		if (sicico & ONSEM_PRC) {
			RetStatus = idb_window((procid * 16),(EXAWORD) CurrentTcodeOffset(0) ,1);
			}
		else	{
			RetStatus = idb_window(cur_seg,(EXAWORD) CurrentTcodeOffset(0),0);
			}

#ifdef	MODEL_DBGT
		/* Update Tcode assembler window */
		/* ----------------------------- */
		if (( WindCord[14][1] - 1 ) > 12 ) {
			ListeTcode((ScreenLin - ListLigne - 1),1 ,(ListLigne + 1),(WindCord[14][1] - 1));
			}

		ScreenFlg = HoldView;

		if (( ScreenFlg & 1 ) != 0 ) {
			db_Refresh();
			}
#endif
		ListStatus = ((ListStatus & 0x0008) | RetStatus);

		if ( RetStatus == 0x0005 ) {

			if ( ListStatus & 0x0008 ) 
				WhereAreWe(ScreenLin,1);

			/* Variables en Observation */
			/* ------------------------ */
			(VOID) Observe(0);
			db_xpos((ScreenLin - ((ListLigne / 2) - 1))  , (WindCord[14][1] + 1));
			return;
			}
		}

	/* Variables en Observation */
	/* ------------------------ */
	(VOID) Observe(0);

	/* Default EXADB prompt if no list following */
	/* ----------------------------------------- */
	WhereAreWe(1,1); db_xcprintf((BPTR)" ->> "); 
	return;
}
#endif

#ifdef	ABAL21

EXAWORD	current_tcode_block_type()
{
	return((sicico & ONSEM_PRC ? 1 : 0 ));
}
EXAWORD	current_tcode_identity()
{
	return( (sicico & ONSEM_PRC ? (procid * 16) : cur_seg) );
}

EXAWORD	current_tcode_offset()
{
	return( CurrentTcodeOffset(0) );
}

EXAWORD	check_tcode_location( bt, bi, bo )
EXAWORD	bt;
EXAWORD	bi;
EXAWORD	bo;
{
	if ( ( bt == current_tcode_block_type() )
	&&   ( bi == current_tcode_identity()   )
	&&   ( bo == current_tcode_offset()     ) ) 
		return( 1 );
	else	return( 0 );

}

VOID	prompt_version2()
{
	/* Variables en Observation */
	/* ------------------------ */
	(VOID) Observe(0);

	store_function_keys();

	/* Source Correspondance Information */
	/* --------------------------------- */
	db_ungetch( tcode_correspondance( current_tcode_block_type(),
					  current_tcode_identity(),
					  current_tcode_offset(),0     ) );
	restore_function_keys();

	return;
}
#endif

void	prompt()
{
#ifdef	BEFORE_011295
#ifdef	ABAL21
	if ( trad_ver > '1' )
		prompt_version2();
	else
#endif
		prompt_version1();

#else
		prompt_version2();
#endif
	return;
}

EXAWORD	dbvartyp( vid )
EXAWORD	vid;
{

if (( vid & ISLOCAL ) != 0 ) { 
	return( Tcodeword( (LocalDataTable + (vid & TOGLOBAL)) ) ); 
	}
return( Tcodeword( (GlobalDataTable + vid) ) );

}

EXAWORD	dbvarind( vid )
EXAWORD	vid;
{

	EXAWORD	www;
	BPTR	dptr;
if (( vid & ISLOCAL ) != 0 ) { 
	www = Tcodeword( (LocalDataTable + (vid & TOGLOBAL)) ); 
	dptr = LocalDataTable;
	}
else	{ 
	www = Tcodeword( (GlobalDataTable + vid) );
	dptr = GlobalDataTable;
	}
if (( www & 0x0040 ) == 0 ) 	{ return(1); 	}
if ( www & 0xFF00 )		{ dptr += WORDSIZE;	}
if (( www & 3 ) > 1 )		{ dptr += WORDSIZE; }
return( Tcodeword( (dptr + (2 * WORDSIZE)) ) );

}

EXAWORD	dbvarand( vid )
EXAWORD	vid;
{

	EXAWORD	www;
	BPTR	dptr;
if (( vid & ISLOCAL ) != 0 ) { 
	www = Tcodeword( (LocalDataTable + (vid & TOGLOBAL)) ); 
	dptr = LocalDataTable;
	}
else	{ 
	www = Tcodeword( (GlobalDataTable + vid) );
	dptr = GlobalDataTable;
	}
if (( www & 0x0020 ) == 0 ) 	{ return(1); 	}
if ( www & 0xFF00 )		{ dptr += WORDSIZE;	}
if (( www & 3 ) > 1 )		{ dptr += WORDSIZE; }
return( Tcodeword( (dptr + (3 * WORDSIZE)) ) );

}

EXAWORD	dbvarlen( vid )
EXAWORD	vid;
{
	EXAWORD	www;
	BPTR	dptr;
if (( vid & ISLOCAL ) != 0 ) { 
	www = Tcodeword( (LocalDataTable + (vid & TOGLOBAL)) ); 
	dptr = LocalDataTable;
	}
else	{ 
	www = Tcodeword( (GlobalDataTable + vid) );
	dptr = GlobalDataTable;
	}
if (( www & 3 ) == 0 ) 	{ return(1); 	}
if (( www & 3 ) == 1 ) 	{ return(2); 	}
if ( www & 0xFF00 )	{ dptr += WORDSIZE;	}
return( Tcodeword( (dptr + (2 * WORDSIZE)) ) );

}




/*
 *	D B C M D G E T ( )
 *	-------------------
 *	Displays the DB prompt and then ...
 *	Returns a pointer to the Command line input OR a NUL pointer
 *	if Escape Key was pressed.
 */

EXAWORD	dbcmdget()
{
#ifdef	BEFORE_011295
	if ( trad_ver < '2' ) {
		if (( noprompt == 1 ) && (Konsult == 0 )) { 
			prompt(); 
			noprompt = 0; 
			}
		return(dbstrget( 32 , 0 ));
		}
#endif
#ifdef	ABAL21
#ifdef	BEFORE_011295
	else	{
#endif
		prompt();
		return( standard_command_input( 32, 0 ) );
#ifdef	BEFORE_011295
		}
#endif
#endif
}

/*
 *	L I B T R A P ( x )
 *	-------------------
 */

EXAWORD	libtrap(ltrap)
TRAPTR	ltrap;
{
	return(0);
}

/*
 *	T E S T T R A P ()
 *	------------------
 *	Test for trap adresse to stop Tcode execution
 *
 */

EXAWORD	testtrap()
{
	return(1);
}

/*
 *	T E S T S T O P ()
 *	------------------
 *	Test for Keyboard break key recieved
 */

EXAWORD	teststop()
{
	if ( opb() ) { if ( (EXAWORD) x_getch() == (EXAWORD) brayk ) { return(0); } }
	return(1);
}


/*
 *	C H E C K S ( perm )
 *	--------------------
 *	Perform execution control checks for trap or break key
 *
 */

EXAWORD checks(perm)
EXAWORD perm;
{
	EXABYTE	lbuf[4];
	EXAWORD x;

#ifdef MODEL_DBGT
	if ( ritewatch != 0 ) { /* Alors Modif of a writewatch variable */
		TcodePmot( (BPTR) &lbuf[0] , ritewatch );
		(VOID) affvarb((BPTR) &lbuf[0]); 
		db_xputch(' ');
		db_xcprintf((BPTR)TalkPtr[55]);
		db_xputch(' ');
		ritewatch = 0;
		return(0);
		}
#endif

	if ( (perm & DBONSEM_TRC) != 0 ) { 
		x = (EXAWORD) CurrentTcodeOffset(0);
		db_xputch('('); showword(x,4); db_xputch(')');
#ifdef MODEL_DBGT
		db_xputch(' '); db_xcprintf((BPTR) _tc_mnem[ (((EXAWORD) *fdex ) & 0x007F) ] );
		db_xputch(' ');
#endif
		}

	if ( (perm & DBONSEM_TRP) != 0 ) { if (testtrap() == 0) { return(0); } }
	if ( (perm & DBONSEM_KEY) != 0 ) { if (teststop() == 0) { return(0); } }
	return(1);
}


/*
 *	Establishes the PROGRAM window context as standard output
 *	whatever the initial conditions.
 */

VOID	use_program_window()
{

	/* Select program window for Console Output */
	/* ---------------------------------------- */
	LoadWindow((EXAWORD) 1); 

	/* Ensure ASFUN library has correct implicite */
	/* ------------------------------------------ */
	asfun_program_implicite();

	/* Ensure Program Sends to Screen for ASFUN */
	/* ---------------------------------------- */
	ForceProgram();

	return;

}

/*
 *	Establishes the MONITEUR window context as standard output
 *	whatever the initial conditions.
 */

VOID	use_monitor_window()
{
	/* Restore Context before STEP FORCE for ASFUN */
	/* ------------------------------------------- */
	UnForceProgram();

	/* Ensure ASFUN library has correct implicite */
	/* ------------------------------------------ */
	asfun_monitor_implicite();

	/* Select Moniter window for Console Output */
	/* ---------------------------------------- */
	LoadWindow((EXAWORD) 0);

}

VOID	check_for_stop_status()
{
	if ( StopStatus == 1 )
		/* Display Stopped Message */
		/* ----------------------- */
		Verbose((BPTR) TalkPtr[60]);
	return;
}

EXAWORD	test_stop_status()
{
	return( StopStatus );
}

VOID	IndicateStop()
{
	/* Test for STOP or ERROR */
	/* ---------------------- */
	if ( err_val != 0 ) { 

#ifdef	ABAL21
		/* Display Error value */
		/* ------------------- */
		standard_errors( err_val );
#endif
		/* Release stopped condition */
		/* ------------------------- */
		StopStatus = 0;

		/* Restore to start of Line */
		/* ------------------------ */
		fdex      = lineptr-1;
		worktop   = workhold;
		LastTcode = *(fdex++);

		}
	else	{

		/* Enforce Stopped Condition */
		/* ------------------------- */
		StopStatus = 1;

		check_for_stop_status();

		/* Enforce Stopped Condition */
		/* ------------------------- */
		StopStatus = 1;

		}

	/* Return to Caller */
	/* ---------------- */
	return;
}


/*
 *	D B M O T O R ( )
 *	-----------------
 *	Execute tcode (called from 'Ctrl X' or 'C' until :
 *		STOP
 *		ERROR
 *		TRAP ADRESSE
 *
 */
EXAWORD	InhibitEder;


VOID dbmotor()
{
	EXAWORD	broken;
	EXAWORD	break_type;

	AssignBreak = 0;

	broken = 0; InhibitEder = 1; break_type = 0; err_val = 0;

	/* Permenant Loop for BREAK KEY Checking */
	/* ------------------------------------- */
	while ( 1 ) {

		/* Check for : Restart after break or START */
		/* ---------------------------------------- */
		if ( LastTcode != MOINS_UN ) 
			LastTcode = dbentry((LastTcode & 0x007F));
		else	LastTcode = llmotor();

		prndest = 1;

		/* Check first for Break point encountered */
		/* --------------------------------------- */
		if ( LastTcode == _tc_NOP )  {  

			/* Collect substituted tcode from storage */
			/* -------------------------------------- */
			LastTcode = TrapSearch(1);	  

			/* Return to Debug Mode */
			/* -------------------- */
			break;

			}


		/* Exit Event was Stop or Error */
		/* ---------------------------- */
		if ( StopStatus != 0 ) 
			break;

		if ( db_step_ctrl & 8 ) {
			if ( AssignBreak ) {
				AssignBreak = 0;
				break;
				}
			}
#ifdef	ABAL14
		/* Watch out for Break Watch */
		/* ------------------------- */
		if ( db_step_ctrl & 4 ) {

			/* Perform Watch list compare */
			/* -------------------------- */
			if ( WatchMan(0) == 0 )

				/* Continue Execution */
				/* ------------------ */
				continue;

			else	{
				broken = 1;
				break;
				}
			}
#endif
		/* Watch out for possible Break Key Exit */
		/* ------------------------------------- */
		if (( db_step_ctrl & 2 )
		&&  ( opb() != 0 )) {
			if ( x_getch() != brayk )
				continue;
			else	broken = 1;
			}
		break;
		}

	InhibitEder = 0;
		
	/* Return to Caller */
	/* ---------------- */
	return;
}

/*
 *	D B S T E P ( )
 *	---------------
 *	Execution of next Tcode Sequence up till next new Line
 *	Called via debug syntax : ' ' or 'S'
 *
 */


VOID	dbstep()
{
	/* Ensure Correct Entry Identity */
	/* ----------------------------- */
	ExQui = 0;

	InhibitEder = 1; err_val = 0;

	/* Establish Program Window Context as STDOUT */
	/* ------------------------------------------ */
	use_program_window();

	/* Ensure entrance by Side Door */
	/* ---------------------------- */
	if (( LastTcode == MOINS_UN ) 
		
	/* Collect Next Tcode (Watch out for Break) */
	/* ---------------------------------------- */
	&&  ((LastTcode = (EXAWORD) *(fdex++)) == _tc_NOP))

		/* Collect from Trap Table / Liste */
		/* ------------------------------- */
		LastTcode = TrapSearch(0);


	/* Enter Motor by Side Door Please */
	/* ------------------------------- */
	db_step_ctrl |= 1; 
	LastTcode    = dbentry((LastTcode & 0x007F)); 
	db_step_ctrl &= 0xFFFE;
	prndest = 1;


	/* Convert any NOP into Trapped Code */
	/* --------------------------------- */
	if ( LastTcode == _tc_NOP )  
		LastTcode = TrapSearch(0);

	/* Establish Moniteur Window Context as STDOUT */
	/* ------------------------------------------- */
	use_monitor_window();

	InhibitEder = 0;


	/* Return to Debug Main Function */
	/* ----------------------------- */
	return;
}



#ifdef	MODEL_DBGT

EXAWORD setkurs(l,c)
EXAWORD	l;
EXAWORD	c;
{

	if (l > (ScreenLin - 1)) {
		db_xputch('\n'); db_xputch('\r');
		l = (ScreenLin - 1);
		db_xpos(l,c);
		}
	else db_xpos(l,c);
	return(l);
}


EXAWORD getreg()
{
	db_xcprintf((BPTR)"\t#"); return(getint());
}
BPTR 	affreg(cp)
BPTR	cp;
{
	EXABYTE	c;
	db_xcprintf((BPTR)"#"); c = *(cp++); 
	showword((EXAWORD) c,2);
	return(cp);
}

EXAWORD getint()
{
	EXABYTE	b[10]; 
	b[0] = 10; return(atoi((BPTR) dbcgets( (BPTR) &b[0]),12 ) );		
}

EXAWORD gethint()
{
	EXABYTE	b[10];
	BPTR	cp;
	EXAWORD	x;
	db_xputch(':'); b[0] = 10; 
	cp = (BPTR) dbcgets((BPTR) &b[0] );
	x = strlen(cp);
	return((EXAWORD) hextoi(cp,x) );		

}

BPTR	affint(cp)
BPTR	cp;
{
	BINAIRE	x;
	db_xputch(' ');
	showword( Tcodeword( cp ) , 4 ); cp += WORDSIZE;
	return(cp);
}

EXAWORD getcon()
{
	BINAIRE	x;		
	db_xcprintf((BPTR)"\t{"); x = gethint(); db_xputch('}'); return(x);
}
BPTR	affcon(cp)
BPTR	cp;
{
	EXAWORD	x,y;
	BPTR	xp,dp;
	db_xcprintf((BPTR)"{"); x = Tcodeword(cp); cp += WORDSIZE;
	xp = (TcodeConstants + x); 
	while (1) {
		if ((y = *(xp++)))
			break;
		else if ((y = *(xp++)) & 0x0080)
			xp = (GlobalConstants + (Tcodeword((xp))));
		else 	{ 	
			bcdtoa(xp,y,(BPTR) &askbuf[0],24);
			xp = (BPTR) &askbuf[0]; 
			y = strlen(xp); 
			break;
			}
		}
	dp = (BPTR) allocate( y + 1);
	memcpy(dp,xp,y);
	*( dp + y ) = (EXABYTE) 0;
	db_xcprintf(dp);
	liberate(dp);
	db_xcprintf((BPTR)"}"); return(cp);
}

EXAWORD getett()
{
	EXAWORD	x;
	db_xcprintf((BPTR)"\t&"); return(gethint());
}
BPTR	affett(cp)
BPTR	cp;
{
	BINAIRE	x;
	db_xcprintf((BPTR)"&"); x = Tcodeword(cp); cp += WORDSIZE;
	showword(x,4);
	return(cp);
}

EXAWORD getvarb()
{
	EXAWORD	x;
	db_xcprintf((BPTR)"\t["); x = gethint(); db_xcprintf((BPTR)"]"); return(x);
}
#endif	/* MODEL_DBGT */


VOID	check_for_local_load()
{
	identify_local_data();
#ifdef	ABAL21
	if ( change_local_data() )
		version2_local_loader(Local_Identity.segproc,Local_Identity.number);
#endif
}

EXAWORD	nameseek( nptr , np , npx )
BPTR 	nptr;
BPTR	np;
EXAWORD	npx;
{
	BPTR tptr;
	EXAWORD	y,vl,x,z;
	EXABYTE	c;

	if ( np == (BPTR) 0) 
		return(0);
	y = 0;
	while ( y < npx ) {
		tptr = nptr; 
		x = 0;
		if ((vl = lenuze(nptr,8)) == 0)
			return(0);
		while ( (x < 8) && ( vl > 0) ) {
			c = *(tptr); c = toupper(c);
			if ( *(np + x) == c ) { 
				tptr++; x++; vl--; 
				continue; 
				}
			else 	break;
			}
		if ( vl == 0 ) {
			if (( *(np + x ) == IO_ESP ) || ( x == 8 )) {
				return( Tcodeword( (BPTR) ( np + 8 ) ) );
				}
			}
		np += (8 + WORDSIZE); y++;
		}

	return(0);		
}

/*	Locate the Variable Name token		*/
/*	------------------------------		*/
/*	The option : SEARCH_MODE allows		*/
/*	The search order to be specified	*/
/*	0 : Search LOCAL then GLOBAL		*/
/*	1 : Search Global then Local		*/

EXAWORD	nametest( nptr, search_mode)
BPTR	nptr;
EXAWORD	search_mode;
{
	EXAWORD	x;
	EXAWORD	resolve_variable_identity( BPTR, EXAWORD );

	/* Establish identity of this Code block */
	/* ------------------------------------- */
	Establish_Local_Identity();


#ifdef	ABAL21
	/* Check if Global search first required */
	/* ------------------------------------- */
	check_global_load();
	if ( search_mode == 1 ) {
		if ( trad_ver > '1' ) {
			if ((x = resolve_global_variable( (BPTR) nptr )) != 0)
				return(x);
			}
		else if ((x = nameseek(nptr,GlobalNamesTable,var_glob)) != 0 ) 
			return(x);
		}
#endif

	/* If Local Data Table is Valid */
	/* ---------------------------- */
	if ( valid_local_data() ) {


#ifdef	ABAL21
		if ( trad_ver > '1' )
			check_for_local_load();
		else
#endif
			if ( change_local_data() ) 
				/* Load new block of Local Variable Names */
				/* -------------------------------------- */
				LocalNamesTable = Local_Loader(Local_Identity.segproc,Local_Identity.number , LocalNamesTable , LocalDataTable );


		/* Then Search in LOCAL Names Table */
		/* -------------------------------- */
#ifdef	ABAL21
		if ( trad_ver > '1' ) {
			if ((x = resolve_local_variable( (BPTR) nptr )) != 0)
				return((x | ISLOCAL));
			}
		else 
#endif
			if ((x = nameseek(nptr,LocalNamesTable,var_locl)) != 0 ) 
				return((x | ISLOCAL)); 

		}

	/* Else : SEARCH GLOBAL names table */
	/* -------------------------------- */
#ifdef	ABAL21
	if ( search_mode == 0 ) {
		if ( trad_ver > '1' ) {
			if ((x = resolve_global_variable( (BPTR) nptr )) != 0)
				return(x);
			}
		else 
#endif
			if ((x = nameseek(nptr,GlobalNamesTable,var_glob)) != 0 ) 
			 	return(x);
#ifdef	ABAL21
		}
#endif

	/* Variable name not found */
	/* ----------------------- */
	return(0);
}

BPTR	affvarb(cp)
BPTR	cp;
{
	register EXAWORD	x,y;
	BPTR	np;
	x = Tcodeword(cp); cp += WORDSIZE;
	np = varbname(x);
	if ( np == (BPTR) 0) { db_xputch('['); showword(x,4); db_xputch(']'); }
	else { 	
		for ( y=0; y < 8; y++ ) {
			if ( *np != IO_ESP) { db_xputch(*np) ; }
			np++;
			}
		}
	return(cp);
}

BPTR	varbname(x)
EXAWORD	x;
{
register	BPTR	np;
register	EXAWORD	y,vc;

	if (( x & ISLOCAL) == 0 ) { np = GlobalNamesTable; vc = var_glob; }
	else { np = LocalNamesTable; x &= TOGLOBAL; vc = Tcodeword( LocalDataTable ); }
	if ( np == (BPTR) 0 ) { return((BPTR) 0); }
	y = 0;
	while ( y < vc ) {
		if ( Tcodeword( (np + 8)) == x ) { return( np ); }
		else { y++; np += 10; }
		}
	return((BPTR) 0);
}

EXAWORD	thisvarb( x , vind , vand, flg )
EXAWORD	x,vind,vand,flg;
{
	EXAWORD	svind,svand;	/* SV registre index 0		*/

	svind = ireg [ 0 ];	ireg [ 0 ] = vind;
	svand = areg [ 0 ];	areg [ 0 ] = vand;
	
	if ( argset1(5,x) == SOFTERROR ) {
#ifdef	ABAL21
		standard_errors( err_val );
#endif
		ireg [ 0 ] = svind; 	
		areg [ 0 ] = svand;
		return(SOFTERROR);
		}
	ireg [ 0 ] = svind; areg [ 0 ] = svand;
	if ( flg == 1 ) 
		return(GOODRESULT);
	else 	return(variable_value());
}		

#ifdef MODEL_DBGT
EXAWORD varlook(c)
EXAWORD	c;
{
	if ( c == 'G' ) { return(varbtab((BPTR)GlobalDataTable,0));}
	if ( c == 'L' ) { return(varbtab((BPTR)LocalDataTable,1)); }
	return(0);
}
#endif

EXAWORD variable_value()
{
	EXAWORD	lno,cno;
	while ( db_xcol() < 20 ) 
		db_xputch(' ');
	lno = db_xlin();
	switch ( worktyp1 ) {
		case 0 : showword(workval1,2); break;
		case 1 : showword(workval1,4); break;
		case 2 :
		case 3 : while ( worklen1 > 0 ) { 
				if ((cno = db_xcol()) >= 75) {
					while (db_xcol() < 79) 
						db_xputch(' ');
					db_xputch(GRSYM_B3);
					db_xpos(++lno,1);
					db_xputch(GRSYM_B3);
					while (db_xcol() < 20)
						db_xputch(' ');
					}
				showword((EXAWORD) *(workptr1++),2);	
				db_xputch(' '); worklen1--;
				}
			 break;
		}
	return(GOODRESULT);
}


#ifdef MODEL_DBGT
EXAWORD varbtab(vb,flg)
BPTR	vb;
EXAWORD	flg;
{
	EXAWORD	x,y,z,l,i,oo,vmax,tabmax;
	BPTR	tb;
	EXAWORD	whou;
	EXABYTE	ltrav[16];
	whou = 0; tb = vb;
	if ( vb == (BPTR) 0) { return(0); }
	vmax = Tcodeword( vb );
	vb += (3 * WORDSIZE);
	do {
		newlyne(); tabmax = 3;
	
		/* Calculate Variable Descriptor ID */
		/* -------------------------------- */
		oo = (EXAWORD) (vb - tb); 
		if ( flg > 0 ) { oo |= ISLOCAL; }

		/* Get Variable Type Word */
		/* ---------------------- */
		do {	x = Tcodeword( vb);  
			if ( x == 0xFFFF ) { newlyne(); db_xcprintf((BPTR)TalkPtr[56]); return(1); }
			vb += WORDSIZE; 
			}
		while (( x & 0x0010 ) != 0);

		/* Get 1st part of Storage pointer */
		/* ------------------------------- */
		y = Tcodeword( vb ); vb += WORDSIZE;

		/* If External Get 2nd Part */
		/* ------------------------ */
		if ( x & 0x7F00 ) { z = Tcodeword(vb); vb += WORDSIZE; }
		else 		  { z = 0; }

		/* If BCD or String get Length */
		/* --------------------------- */
		if ( x & 0x0002 ) { l = Tcodeword(vb); vb += WORDSIZE; }
		else 		  { l = 0; }


		/* Field directive (Change back to memory) */
		/* --------------------------------------- */
		if ((( x & 0x7F00) == 0) && (whou == 1)) {
			db_xcprintf((BPTR)"Field = M ");
			newlyne(); whou = 0;
			}

		/* Field Directive (Change to File Number) */
		/* --------------------------------------- */
		if ((( x & 0x7F00) != 0) && (whou == 0)) {
			db_xcprintf((BPTR)"Field = "); 
			if ( x & 0x4000 ) { db_xputch('E'); }
			else { showword( ((x & 0x3F00) >> 8),4); }
			newlyne(); whou = 1;
			}

		/* Mot Cle et Variable ID */
		/* ---------------------- */
		db_xputch('\t'); db_xcprintf((BPTR)"DCL ");
		db_xputch('['), showword( oo , 4 ); db_xputch(']');
		TcodePmot( ((BPTR) &ltrav[0]) , oo);
		affvarb((BPTR) &ltrav[0]);

		/* Variable Type Sign , Length and Size */
		/* ------------------------------------ */
		switch ( x & 0x0003 ) {
			case 0 : db_xputch('#'); db_xcprintf((BPTR)"     "); break;
			case 1 : db_xputch('%'); db_xcprintf((BPTR)"     "); break;
			case 3 : db_xcprintf((BPTR)"$=");  x_intvisi( l ); break;
			case 2 : db_xcprintf((BPTR)" =");  x_intvisi( l ); break;
			}
		if ((x & 0x0040 ) != 0 ) {
			db_xputch('('); i = Tcodeword( vb ); vb += WORDSIZE;
			x_intvisi( i );
			if ((x & 0x0020 ) != 0 ) {
				db_xputch(',');
				i = Tcodeword( vb ); vb += WORDSIZE; 
				x_intvisi( i );
				db_xputch(')');
				}
			else { db_xcprintf((BPTR)")     "); }
			}
		else { db_xcprintf((BPTR)"           "); }
		db_xputch('\t');
		if ( (x & 0x0008) != 0) {  db_xcprintf((BPTR)"ARG "); }
		else { db_xcprintf((BPTR)"    "); }
		db_xcprintf((BPTR)" Offset : ");
		if (( x & 0x7F00) != 0) {
			showword(z,4); db_xputch(':');
			showword(y,4);
			}
		else {  showword(y,4); }
		}
	while ( db_xgetch() != IO_ESC );
	return(0);
}
#endif


/*
 *	D B E R R E U R ( ErrKod )
 *	--------------------------
 *	Gestion des Erreurs en cours de debug
 *
 */

EXAWORD dberreur(errkod)
BPTR	errkod;
{
if (( permdb & 0x0010 ) == 0 ) {
	db_xcprintf((BPTR)"  Erreur  #"); showword(err_val,4);
	db_xputch('\t'); 
	db_xcprintf((BPTR)" Segment : "); showword( cur_seg , 2 );
	db_xcprintf((BPTR)" Adresse : "); showword( (EXAWORD) ( errkod - TcodeSegment ),4 );
	erreurs(); brayk = 3; db_step_ctrl |= 2;
	trace = 0x0001; permdb |= 1;
	return(0);
	}
else { return(erreurs()); }
}

/*
 *	K E Y E R ( cmdptr )
 *	--------------------
 *	Gestion de la touche 'BREAK'
 *
 */

VOID	keyer(cmdptr)
BPTR	cmdptr;
{
	EXAWORD	xl;
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;

	/* Remove leading white space */
	/* -------------------------- */
	cmdptr = CmdShift(cmdptr);

	/* Empty String means default Key Value */
	/* ------------------------------------ */
	if ( *cmdptr == IO_NUL ) { brayk = IO_ESC; }
	else	{	

		/* Analyse Command String */
		/* ---------------------- */
		switch ( *cmdptr ) {
			case '?' :
			case 'L' : 
				/* Display current break key value */
				/* ------------------------------- */
				   WdwLimit(5,3,32);
				   if (trad_ver < '2') {
					topcol = WindCord[5][1];
					toplin = WindCord[5][0];
					}
				   if (PushZone(toplin,topcol,3,32,0x0013,Couleurs[5][0],Couleurs[5][1]) != 0) {
					Debordement();
					return;
					}
				   db_xcprintf((BPTR)TalkPtr[57]);
				   db_xcprintf((BPTR)" = ");
				   showword( brayk , 2 ); 
				   switch ( ExitMethod(1) ) {
					case 0 : PopZone(); break;
					case 1 : LibZone(); break;
					}
 				   break;
			case '/' : cmdptr++;
				   xl = strlen(cmdptr);
				   brayk = hextoi(cmdptr,xl); break;			   
			case '(' :
			case '\'':
			case '"' : brayk = (EXAWORD) *(cmdptr + 1); break;
			default  : xl = strlen(cmdptr);
				   brayk = atoi(cmdptr,xl);
			}
		}

	/* Establish Break key Semaphore bit values */
	/* ---------------------------------------- */
	if ( brayk == 0 ) { 
		permdb &= 0xFFF7;
		db_step_ctrl &= 0xFFFD; 
		}
	else	{
		permdb |= 0x0008;
		db_step_ctrl |= 0x0002;
		}
	return;
}



/*
 *	E X I T C H K ( )
 *	-----------------
 */

EXAWORD	exitchk()
{
	EXABYTE	x;
	EXABYTE	y;
	EXAWORD	z;
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;
#ifdef	ABAL21
	if ( trad_ver > '1' )
		return( standard_exit_check() );
#endif 
	WdwLimit(13,3,50);
	if (trad_ver < '2') {
		topcol = WindCord[13][1];
		toplin = WindCord[13][0];
		}
	if ( (z = PushZone(toplin,topcol,3,50,0x0013,Couleurs[13][0],Couleurs[13][1])) != 0) {
		db_xpos(ScreenLin,1);
		}
	db_xcprintf((BPTR)TalkPtr[58]);
	db_xputch(' ');
	db_xputch(toupper( (*(TalkPtr[0]))));
	db_xputch('/');
	db_xputch(toupper( (*(TalkPtr[0] + 1))));
	db_xcprintf((BPTR) " ? ");
	do 	{
#ifdef	ABAL21
		switch ((x = mouse_or_keyboard())) {
#else
		switch ((x = db_xgetch())) {
#endif
			case 0x0004	:
			case IO_RC	: if ( z == 0 ) { PopZone(); }
					  return(0);
			case IO_ESC	: if ( z == 0 ) { PopZone(); }
					  return(1);
			default		:
				x = toupper(x);
				if (( x == (toupper( (*(TalkPtr[0]))))) || ( x == (toupper( (*(TalkPtr[0]+1)))))) {
					db_xputch( x );
					do	{ y = db_xgetch(); }
					while (( y != IO_RC ) && ( y != syskey[IO_BAK] ));
					if ( y == IO_RC ) { continue; }
					db_xputch(y); x = y;			
					}
			}
		}
	while (( x != toupper( (*(TalkPtr[0]+1))) ) && ( x != toupper( (*(TalkPtr[0]))) ));
	if ( x == toupper( (*(TalkPtr[0]+1))) ) 	{ if ( z == 0 ) { PopZone(); } return(1); }
	else 			{ if ( z == 0 ) { PopZone(); } return(0); }
}
#ifndef	ABAL21
VOID	watcher(cmdptr)
BPTR	cmdptr;
{
	EXABYTE	c;
	EXAWORD	x,y,v,w;
	EXABYTE	lbuf[16];
	EXAWORD	vid,vind,vand;
	BPTR	wptr;
	EXAWORD	wlen;
	BPTR	xptr;
	EXAWORD	xlen;
	EXAWORD	lno;
	EXAWORD	global_flag;
	c = toupper(*cmdptr); cmdptr++;
	switch ( c ) {
		case 'L' :
			if ( watchdex > 0 ) {
				WdwLimit(6,(watchdex+2),16);
				if (PushZone(WindCord[6][0],WindCord[6][1],(watchdex + 2),16,0x0013,Couleurs[6][0],Couleurs[6][1]) != 0) {
					Debordement();
					return;
					}
				lno = 1;
#ifdef	BUF_CICO
				x_bstart();
#endif		
				for ( x = 0; x < watchdex; x++ ) {
					y = watchmat[x];
					if ( y & ISLOCAL ) { /* Alors VARLOC */
						if ( sicico & ONSEM_PRC ) { 
							if (( watchtyp[x] & 0x0010 ) == 0 ) 	{ continue; }
							if (  procid != watchgod[x] ) 		{ continue; } 
							}
						else	{
							if (( watchtyp[x] & 0x0010 ) != 0 ) 	{ continue; }
							if ( cur_seg != watchgod[x]) 		{ continue; }
							}
						}
					wdw_xpos(lno++,2);	
					TcodePmot((BPTR) &lbuf[0] , y);
					(VOID) affvarb((BPTR) &lbuf[0]);
					if (( watchtyp[x] & 0x0040 ) != 0 ) { 
						db_xputch('('); 
						if ( watchind[x] != 0 ) { intvisi( watchind[x] ); }
						else			{ db_xputch('*');	  }
						if (( watchtyp[x] & 0x0020 ) != 0 ) {
							db_xputch(','); 
							if ( watchand[x] != 0 ) { intvisi( watchand[x] ); }
							else			{ db_xputch('*');	  }
							}
						db_xputch(')');
						}
					}
#ifdef	BUF_CICO
				x_bflush();
#endif		
				switch ( ExitMethod(1) ) {
					case 0 : PopZone(); break;
					case 1 : LibZone(); break;
					}
				}
			break;
		case 'A' :
		case 'I' :
			/* Avoid White Space */
			/* ----------------- */
			cmdptr = CmdShift(cmdptr);
			if ( *cmdptr == IO_NUL ) { return; }
#ifdef	ABAL15
			if ( *cmdptr == '$' ) {
				global_flag = 1;
				cmdptr++;
				}
			else
#endif
				global_flag = 0;
				
			/* Seek End of Identifier */
			/* ---------------------- */
			wptr = cmdptr; wlen = 0;
			while (( *wptr != '(' ) && ( *wptr != IO_NUL)) { wptr++; wlen++; }

			/* Check for ETOILE total liberation of Observations */
			/* ------------------------------------------------- */
			if ((strlen((BPTR) cmdptr) == 1) && (*cmdptr == '*')) {
				watchdex = 0; return;
				}
			/* End of Identifier : Check for Dimensions */
			/* ---------------------------------------- */
			if ( *wptr == IO_NUL ) { 
				/* Simple Variable */
				/* --------------- */
				vind = 1; vand = 1; 
				}
			else {	/* Complex Variable */
				/* ---------------- */
				*(wptr++) = (EXABYTE) 0; 	/* Terminate for Name Seeker */
				xptr = wptr; xlen = 0;

				/* Seek dimension Separator or Terminator */
				/* -------------------------------------- */
				while (( *xptr != ',' ) && ( *xptr != IO_NUL) && ( *xptr != ')')) { 
					xptr++; xlen++; 
					}
				/* Convert and Collect 1st Dimension Value */
				/* --------------------------------------- */
				if ( *wptr == '*' ) { vind = 0; } 
				else { vind = atoi(wptr,xlen);  }

				/* Seek for 2nd Dimension OR default == 1 */
				/* -------------------------------------- */
				if (( *xptr == IO_NUL ) || ( *xptr == ')' )) { vand = 1; } 
				else {	
					/* Collect 2nd Dimension Value */
					/* --------------------------- */
					xptr++;
					xlen = strlen(xptr);
					if ( *xptr == '*' ) { vand = 0; }
					else { vand = atoi(xptr,xlen);  }
					}
				}
		/* Separate Ajout / Suprime */
		/* ------------------------ */
		if ( c == 'A' ) {
			/* Avoid Error 102 due to Variable(*,*) */
			/* ------------------------------------ */
			if ( vind == 0 ) { vind = 1; }
			if ( vand == 0 ) { vand = 1; }

			/* Control Variable Identitifier Validity */
			/* -------------------------------------- */
			if (( vid = nametest( cmdptr, global_flag )) != 0 ) {
				watchmat[watchdex] = vid;
				watchind[watchdex] = vind;
				watchand[watchdex] = vand;
				watchtyp[watchdex] = dbvartyp(vid);

				/* Check for a Local Variable */
				/* -------------------------- */
				if ( vid & ISLOCAL ) {	/* If VARLOC */

					/* If Currently inside a Procedure */
					/* ------------------------------- */
					if ( sicico & ONSEM_PRC ) {

						/* Store Procedure identifier */
						/* -------------------------- */
						watchgod[watchdex] =  procid;
						watchtyp[watchdex] |= 0x0010;
						}
					else	{
						/* Store Segment Identity */
						/* ---------------------- */ 
						watchgod[watchdex] = cur_seg;
						watchtyp[watchdex] &= 0xFFEF;
						}
					}
				else	{ 
					/* Global Variable */
					/* --------------- */
					watchgod[watchdex] = 0; 
					}
				/* Advance Observation Counter */
				/* --------------------------- */ 
				watchdex++;
				/* Indicate Success */
				/* ---------------- */
				Verbose((BPTR)TalkPtr[69]);
				/* "Ajout realise" */
				/* --------------- */
				}
			else 	{ 
				Verbose((BPTR)TalkPtr[59]);
				/* "Variable inconnue" */
				/* ------------------- */
				}
			break;
			}
		/* Otherwise Suprssion */
		/* ------------------- */
		else	{
			if (( vid = nametest( cmdptr, global_flag )) != 0 ) {
				v = 0;
				while ( v < watchdex ) {
					y = watchmat[v];
					if ( y & ISLOCAL ) { /* Alors VARLOC */
						if ( sicico & ONSEM_PRC ) {
							if (( watchtyp[x] & 0x0010 ) == 0 ) 	{ v++; continue; }
							if ( procid != watchgod[v] ) 		{ v++; continue; }
							}
						else	{
							if (( watchtyp[x] & 0x0010 ) != 0 ) 	{ v++; continue; }
							if ( cur_seg != watchgod[v]) 		{ v++; continue; }
							}
						}	
					if ( watchmat[v] == vid ) { 
						if (( watchind[v] == vind ) || ( vind == 0 )) {
							if (( watchand[v] == vand ) || ( vand == 0 )) {
								if ( v < watchdex ) {
									for ( w = v; w < watchdex; w++ ) {
										watchmat[w] = watchmat[w+1];
										watchind[w] = watchind[w+1];
										watchand[w] = watchand[w+1];
										watchtyp[w] = watchtyp[w+1];
										watchgod[w] = watchgod[w+1];
										}
									}
								if ( watchdex > 0) { watchdex--; }
								continue;
								}
							}
						}
					v++; 
					}
				Verbose((BPTR)TalkPtr[70]);
				/* "Supression realise" */
				/* -------------------- */
				}
			else 	{	 
				Verbose((BPTR)TalkPtr[59]);
				/* "Variable inconnue" */
				/* ------------------- */
				}
			break;
			}
		}
	return;
}
#endif


/*
 *	I D B _ L I B E R A T E ( CtrlProc )
 *	------------------------------------
 *	Liberatation of IDB Control structures
 *
 */

VOID	idb_liberate(CtrlProc)
EXAWORD	CtrlProc;
{
	/* Liberate procedure names */
	/* ------------------------ */
#ifdef	ABAL21
	if ( trad_ver < '2' )
#endif
		if ( CtrlProc != 0 ) 
			LibNomProc();

#ifdef	ABAL21
	liberate_trace_control();
#endif
	/* Liste File Management */
	/* --------------------- */
#ifdef	BEFORE_011295
#ifdef	ABAL21
	if ( trad_ver > '1' )
		liberate_symbols_manager();
	else
#endif
		if ( ListStatus & 1 ) { 	  /* If List is Active 	 */
			while ( LibInfo() == 0 ); /* Liberate Info Stack */
			idb_flclose(); 		  /* Close and Lib Liste */
			}

#else
		liberate_symbols_manager();
#endif	

	/* Liberate all Trap Contexts */
	/* -------------------------- */
	terminate_trap_manager();
#ifdef	ABAL21
	liberate_observations();
#endif

#ifdef	ABAL14
	/* Liberate Watch management */
	/* ------------------------- */
	WatchRaz();
#endif	

	return;

}

/*
 *	I D B _ S T A R T U P ( )
 *	-------------------------
 *	General Initialisation of IDB
 *
 */

VOID	idb_startup()
{
	EXAWORD	x;

#ifdef	ABAL14
	/* Initialise the Watch Manager */
	/* ---------------------------- */
	WatchInit();
#endif

#ifdef	ABAL21
	initialise_trace_control();
#endif

	/* Initialise Procedure Names */
	/* -------------------------- */
#ifdef	ABAL21
	if ( trad_ver < '2' )
#endif
		if ( adr_npr != 0 ) 
			InitNomProc(); 

	/* Dis-activate current Local names user */
	/* ------------------------------------- */
	Local_User.segproc = MOINS_UN;
	Local_User.number  = MOINS_UN;

#ifdef	BEFORE_011295
#ifdef	ABAL21
	if ( trad_ver > '1' ) {
		(void) initialise_symbols_manager();
		(void) activate_symbols_manager( (BPTR) exadb_file_root );
		(void) initial_symbols_manager();
		}
	else	{
#endif
		/* Open and init List file */
		/* ----------------------- */
		if ( (ListStatus = idb_listgogo()) != 0)

			/* Establish Full Screen Page List */
			/* ------------------------------- */
			ListLigne = (ScreenLin - 2);
		else	
#ifdef	MODEL_DBGT
			ListLigne = (ScreenLin - 2);
#else
			ListLigne = 6; 
#endif
#ifdef	ABAL21
		}
#endif
#else
		(void) initialise_symbols_manager();
		(void) activate_symbols_manager( (BPTR) exadb_file_root );
		(void) initial_symbols_manager();
#endif



	trace     = 1; 		
	permdb = 8;
	brayk  = IO_ESC;
#ifdef	ABAL21
	initialise_observations();
#endif
	initialise_trap_manager();

	LastTcode = MOINS_UN;	db_step_ctrl = 2;
	LastDebug.segproc = MOINS_UN;
	ExadbGoFunction = 0;
	return;

}

/*
 *	I D B _ R E S T A R T ( )
 *	-------------------------
 *	Restarts the IDB control mechanisms after liberation
 *	due to CHAIN operations
 *
 */

VOID	idb_restart(CtrlProc)
EXAWORD	CtrlProc;
{
	idb_liberate(CtrlProc);		/* Liberate IDB 		*/
	idb_startup();			/* Restart  IDB 		*/
	return;				/* Return to EXSTOP()		*/
}

VOID	save_last_tcode_adresse( xptr )
struct code_block * xptr;
{
#ifdef	ABAL21
	xptr->segproc = current_tcode_block_type();
	xptr->number  = current_tcode_identity();
	xptr->offset  = current_tcode_offset();
#endif
	return;
}

VOID	save_last_debug_tcode()
{
#ifdef	ABAL21
	save_last_tcode_adresse(& LastDebug );
#endif
	return;
}


VOID	save_last_exec_tcode()
{
#ifdef	ABAL21
	save_last_tcode_adresse(& LastExec );
#endif
	return;
}

VOID	previous_correspondance()
{
#ifdef	ABAL21
	EXAWORD	c;
	if ( LastDebug.segproc != MOINS_UN ) {
		if ((c = tcode_correspondance( 	LastDebug.segproc,
						LastDebug.number,
						LastDebug.offset,1)) != 27)
		db_ungetch( c );
		}
	return;
#endif
}


VOID	execute_single_step()
{
	save_last_debug_tcode();

	monitor_execution_mode = 0;

#ifdef	BEFORE_011295
	/* Pop Execution Screen if in Consult Mode */
	/* --------------------------------------- */
	if ( Konsult == 1 ) 
		PopInfo();

#endif
	Konsult = 0;

	/* Check for 'STOP' having inhibited Execution */
	/* ------------------------------------------- */
	if ( StopStatus == 0 ) {

		/* Establish Program Implicite Window */
		/* ---------------------------------- */
		/* asfun_program_implicite();	*/

		/* Perform Tcode Execution */
		/* ----------------------- */
		dbstep(); 

		/* Establish Monitor Implicite Window */
		/* ---------------------------------- */
		/* asfun_monitor_implicite(); 	*/

		if ( StopStatus != 0 ) 
			IndicateStop();

		}
	return;
}

VOID	execute_till_break()
{
	save_last_debug_tcode();

	monitor_execution_mode = 1;

#ifdef	BEFORE_011295
	/* Pop Execution Screen if in Consult Mode */
	/* --------------------------------------- */
	if ( Konsult == 1 ) 
		PopInfo();
#endif	
	Konsult = 0;

	/* Check for 'STOP' having inhibited Execution */
	/* ------------------------------------------- */
	if ( StopStatus == 0 ) {

		/* Ensure program window Active */
		/* ---------------------------- */
		ProgramWindow();

		/* Establish Program Implicite Window */
		/* ---------------------------------- */
		asfun_program_implicite();
#ifdef	ABAL21
#ifdef	PROLOGUE
		drop_db_entry();
#endif
#endif
		/* Enter execution cycle */
		/* --------------------- */
		dbmotor(); 

#ifdef	ABAL21
#ifdef	PROLOGUE
		raise_db_entry();
#endif
#endif
		/* Ensure debug window active */
		/* -------------------------- */
		MoniteurWindow();

		/* Establish Monitor Implicite Window */
		/* ---------------------------------- */
		asfun_monitor_implicite(); 

		if ( StopStatus != 0 )
			IndicateStop();
		}


	monitor_execution_mode = 0;

	return;
}

VOID	debug_syntax_error()
{
	x_bell();
#ifdef	ABAL21
	standard_error((BPTR) "Syntax Error");
#endif
	return;
}

#ifdef	ABAL21
VOID	pointer_memory_manager()
{
	return;
}

VOID	pointer_management( cmdptr )
BPTR	cmdptr;
{
	EXAWORD	operation;
	EXAWORD	variable;
	EXABYTE	buffer[8];
	BPTR	holdfdex=fdex;
	EXAWORD	flag=0;
	EXAWORD	f_clf6( EXAWORD );

	cmdptr = CmdShift( (BPTR) cmdptr );

	switch ( *(cmdptr++) ) {
		case 'c' :
		case 'C' : 	operation = 0;
				break;
		case 'f' :
		case 'F' :	operation = 2;
				break;
		case 'r' :
		case 'R' :	operation = 1;
				break;
		case 'm' :
		case 'M' : 	pointer_memory_manager();
				return;
		default  :	debug_syntax_error();
				return;
		}

	cmdptr = CmdShift( (BPTR) cmdptr );

	if ( *cmdptr == '$' )
		flag = 1;

	if ((variable = nametest( (BPTR) (cmdptr+flag), flag )) != 0 ) {
		buffer[0] = 0x0040;
		buffer[1] = (variable & 0x00FF);
		buffer[2] = ((variable >> 8) & 0x00FF);
		fdex = (BPTR) buffer;
		if ((flag = f_clf6( operation )) == SOFTERROR)
			standard_errors( err_val );
		fdex = holdfdex;
		}
	else	Verbose((BPTR) "Variable unknown" );
	return;

}
#endif

EXAWORD	UseWindowCoords;

VOID	cancel_window_coordinates()
{
	UseWindowCoords = 0;
	return;
}

EXAWORD	use_window_coordinates()
{
	return( UseWindowCoords );
}

VOID	window_parameter_manager( cmdptr )
BPTR	cmdptr;
{
	EXAWORD	mode;
	EXAWORD	xcoord;
	EXAWORD	pvalue;
	EXAWORD	c;

	UseWindowCoords = 1;

	cmdptr = CmdShift((BPTR) cmdptr );

	xcoord = 0;
	while ( 1 ) {
		if (((c = *(cmdptr++)) >= '0')
		&&  (c <= '9' )) {
			xcoord *= 10;
			xcoord += (c - '0');
			}
		else	break;
		}

	if ( xcoord > 15 )
		return;

	while ( 1 ) {

		cmdptr = CmdShift((BPTR) cmdptr ); 

		switch (( mode = *(cmdptr++) )) {
			case 'R' :
			case 'r' : cancel_window_coordinates();
				   return;
			case 'F' :
			case 'f' : mode = 'F'; break;
			case 'B' :
			case 'b' : mode = 'B'; break;
			case 'C' :
			case 'c' : mode = 'C'; break;
			case 'L' :
			case 'l' : mode = 'L'; break;
			default  : return;
			}

		cmdptr = CmdShift((BPTR) cmdptr ); 

		pvalue = 0;

		while ( 1 ) {
			if (((c = *(cmdptr++)) >= '0')
			&&  (c <= '9' )) {
				pvalue *= 10;
				pvalue += (c - '0');
				}
			else	break;
			}

		switch ( mode ) {
			case 'F' :	Couleurs[xcoord][0] = pvalue; break;
			case 'B' :	Couleurs[xcoord][1] = pvalue; break;
			case 'L' :	WindCord[xcoord][0] = pvalue; break;
			case 'C' :	WindCord[xcoord][1] = pvalue; break;
			}
		}
}

EXAWORD	window_ccoord( which )
EXAWORD	which;
{
	return( WindCord[which][1] );
}

EXAWORD	window_lcoord( which )
EXAWORD	which;
{
	return( WindCord[which][0] );
}

EXAWORD	window_fcoord( which )
EXAWORD	which;
{
	return( Couleurs[which][0] );
}

EXAWORD	window_bcoord( which )
EXAWORD	which;
{
	return( Couleurs[which][1] );
}

VOID	uppercase_command( cptr )
BPTR	cptr;
{
	EXAWORD	c;
	while ((c = *cptr)) {
		*(cptr++) = toupper(c);
		}
	return;
}

EXAWORD	command_interpreter( lcmdptr, noprompt )
BPTR	lcmdptr;
EXAWORD	noprompt;
{
	EXAWORD	c;

	c = toupper( *lcmdptr ); 	lcmdptr++;

	if ( c != '!' )
		uppercase_command( lcmdptr );

	switch ( c ) {

		case	'$'	:
			alter_hexa_switch();
			break;

		/* Pose d'un point d'arret ONE SHOT   */
		/* ---------------------------------  */
		/* B<[S][P]>[segment:][proc:][offset] */
		/* ---------------------------------- */
		case 'B' :	
			traper(0,lcmdptr);  
			break;

		/* Pose d'un point d'arret MULTIPLE   */
		/* ---------------------------------  */
		/* A<[S][P]>[segment:][proc:][offset] */
		/* ---------------------------------- */
		case 'A' :	
			traper(1,lcmdptr);  
			break;

		/* Execution Pas a Pas               */
		/* --------------------------------- */
		/* S				     */
		/* ' '				     */
		/* --------------------------------- */
		case 'S' :
		case ' ' :

			/* Perform single line execution */
			/* ----------------------------- */
			execute_single_step();

			/* Perform Window Buffer Manipulation */
			/* ---------------------------------- */
			MoniteurWindow();

			return((noprompt = 1 ));

		/* Variable Interogation 	     */
		/* --------------------------------- */
		/* D <nom variable> [i[,a]]          */
		/* DH <nom variable> [i[,a]]         */
		/* --------------------------------- */
		case 'D' :	varmod(lcmdptr,0); 
				break;

		/* Modification d'un Variable	     */
		/* --------------------------	     */
		/* M <nom variable> [i[,a]]          */
		/* --------------------------------- */
		case 'M' :	varmod(lcmdptr,3); 
				break;
#ifdef	ABAL21
		/* RUN UNTIL PROVIDED ADRESSE         */
		/* ---------------------------------  */
		/* U<[S][P]>[segment:][proc:][offset] */
		/* ---------------------------------- */
		case 'U' :	
			traper(0,lcmdptr);  
#endif

		/* Continue l'Execution              */
		/* --------------------------------- */
		/* C                                 */
	        /* --------------------------------- */
		case 'C' :

			/* Perform execution till break */
			/* ---------------------------- */
			execute_till_break();
			return((noprompt = 1));

		/* Fin d'execution (Moniteur)        */
		/* --------------------------------- */
		/* E <[RC][ESC]>		     */
		/* --------------------------------- */
		case 'E' :

			if ( exitchk() == 0 )
				return( MOINS_UN );

			break;


		/* Operations advancees de le Moniteur ABAL DB	*/
		/* -------------------------------------------- */

#ifdef	ABAL14
		/* -------------------------------------- */
		/* Relancer l'execution a partir du debut */
		/* -------------------------------------- */
		/* This operation is performed by a CHAIN */
		/* to the current TCODE FILE (ASSIGN=0)	  */
		/* with the contents of LCMDPTR passed as */
		/* ARG (watch out for error 30 !!)	  */
		/* -------------------------------------- */
		/* G [nom du program] [,arguament]	  */
		/* -------------------------------------- */
		case 'G' :
				Relancer( lcmdptr );
				return((noprompt = 1));

		/* -------------------------------------- */
		/* Visualisation of File Table Entry	  */
		/* ---------------------------------	  */
		/* F <numero d'assign>                    */
		/* -------------------------------------- */
		case 'F' :
				fichview(lcmdptr); 
				break;

		/* -------------------------------------- */
		/* Watch list handling functions          */
		/* -----------------------------	  */
		/* Display list of watch statements	  */
		/* --------------------------------	  */
		/* VL					  */
		/* Remove watch event(s) from list	  */
		/* -------------------------------	  */
		/* VIsyntax				  */
		/* -------------------------------------- */
		case 'V' :

			WatchFunctions(lcmdptr);
			break;

#endif

#ifdef	ABAL21
		/* Activation/Disactivation of Debug Tracing */
		/* ----------------------------------------- */
		case 'T' :

			trace_control( lcmdptr ); 
			break;
		case 'P' :
			pointer_management( lcmdptr );
			break;

		case 'X' :
			attachment_manager( lcmdptr );
			break;

#endif

		/* Affichage de l'ecran d'Aide	     */
		/* --------------------------------- */
		/* H                     	     */
		/* --------------------------------- */
		case 'H' :	

			helpscr((EXAWORD) 33 , (EXAWORD) 49); 
			break;

		/* Lancement d'une commande SHELL    */
		/* --------------------------------- */
		/* !<command>[parametres]	     */
		/* --------------------------------- */
		case '!' :	
			execsys(lcmdptr); 
			break;

		/* Affichage de trace GOSUB / RET    */
		/* --------------------------------- */
		/* Z                     	     */
		/* --------------------------------- */
		case 'Z' :	
			stack_trace(); 
			break;

		/* Declaration de la touche BREAK    */
		/* --------------------------------- */
		/* K[[/XX]['C'][nnn]][?]             */
		/* --------------------------------- */
		case 'K' :	
			keyer(lcmdptr); 
			break;

		/* Observation des variables	     */
		/* --------------------------------- */
		/* OL                                */
		/* OI<[*][nom variable]>             */
		/* OA<nom variable>[i[,a]]           */
		/* --------------------------------- */
		case 'O' :	
#ifdef	ABAL21
			observation_management(lcmdptr);
#else
			watcher(lcmdptr);
#endif
			break;

#ifdef	ABAL21
		case 'J' :	
			if ( trad_ver > '1' )
				symbols_browser();
			break;
		case 'N' :
			if ( trad_ver > '1' )
				offer_list_menu(1);
			break;
#endif
		case 'I' :	
			set_tabulation_size((BPTR) lcmdptr );
			break;

		case 'Y' :
			set_debug_search_path( (BPTR) lcmdptr );
			break;

#ifdef MODEL_DBGT
		case 'R' :	registre(lcmdptr); break;
		case 'L' :	traper(MOINS_UN,lcmdptr); break;
#endif
		case 'W' :	
			window_parameter_manager((BPTR) lcmdptr );
			break;

		default	 :	debug_syntax_error();
				return((noprompt = 0)); 

		}

	return( noprompt );

}
/*	Executeur Moniteur advanced functions	*/
/*	-------------------------------------	*/
/*
 *	D B M A I N ()
 *	--------------
 *	Debuger operations entry point
 *
 */

EXAWORD	dbmain()
{
	EXABYTE	c;
	EXAWORD	x,dbctrl;
	EXABYTE	lcmdbuf[32];
	BPTR	lcmdptr;
	EXAWORD	lcmdlen;

	DbWindow = 1; ExWindow = 0; ErrorMode = 0;
	noprompt = 1; TabSize  = 8; Konsult = 0;
	StopStatus=0;
#ifdef	ABAL21
	set_debug_search_path((BPTR) "\0");
#endif

#ifdef	ABAL14
	/* Ensure Clean window status */
	/* -------------------------- */
	AsFunInitialise();
#endif

	for ( x = 0; x < 16; x++ ) { History[x] = (BPTR) 0; }

	HistDex  = 0; HistMax  = 0;

	db_xclear(); x_newlyne();

	Abuse = 0;

	(VOID) idb_startup();

	fdex    = TcodeSegment;		

	dbctrl   = 1;

#ifdef	ABAL21
	execute_debug_script((BPTR) "exadb21.cfg", 0 );
#endif	

	do 	{
		 switch ( dbcmdget() ) {
			case 0   	: lcmdptr = (BPTR) askbuf; break;
			case DB_STEP 	: 

				/* Perform single line execution */
				/* ----------------------------- */
				execute_single_step();

				noprompt = 1; continue;

			case DB_RUN	: 

				/* Enter continuous execution */
				/* -------------------------- */
				execute_till_break();

				noprompt = 1; continue;

			case DB_EXITKEY :
					if ( exitchk() == 0 ) { dbctrl = 0;} /* Test Quit   */
					continue;
			default 	: 
					continue;
			}

		lcmdlen = strlen((BPTR) lcmdptr);
		for ( x = 0; x < lcmdlen; x++ ) 
			lcmdbuf[x] = *(lcmdptr++); 

		lcmdbuf[x] = (EXABYTE) 0; 
		lcmdptr = (BPTR) lcmdbuf;

		if ((noprompt = command_interpreter((BPTR) lcmdptr, noprompt )) == MOINS_UN )
			dbctrl = 0;

		}
	while ( dbctrl == 1 );

	db_xpos(ScreenLin ,1); 
	db_xatb(21); Painter(Vert,Noir);
	db_xpos((ScreenLin - 1),1); 

	/* Liberation des commandes Historique */
	/* ----------------------------------- */
	for (x=0; x<HistMax; x++ )
		if (History[x] != (BPTR) 0) 
			liberate(History[x]);

	/* Liberate IDB Controlers */
	/* ----------------------- */
	(VOID)	idb_liberate(adr_npr);

	/* Liberate EXA machine and Return */
	/* ------------------------------- */
	liberate_virtual_machine();

	return(0);

}
void	list_colours( natb )
EXAWORD	natb;
{
	ColourAtb(0);
	Painter(Couleurs[14][0],Couleurs[14][1]);
	switch ( natb ) {
		case 0 : Painter(Couleurs[14][0],Couleurs[14][1]); break;
		case 1 : Painter(15,Couleurs[14][1]); break;
		case 2 : ColourAtb(2);
		}
	return;
}



void	check_debug_assign(int handle) 	
{ 
	if ( DebugAssign != 0 )
		if ( handle == DebugAssign )
			AssignBreak=1;

	return; 
} 

void	set_debug_assign( int v )
{
	if (!(  DebugAssign = v ))
		db_step_ctrl &= ~ 8;
	else	db_step_ctrl |=   8;
	return;
}

