/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBTRAP.C				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	12/08/1992				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	EXDBTRAPH		/* If not already defined		*/
#define EXDBTRAPH		/* Avoid multiple inclusions		*/
				/* ------------------------------------ */

#define	TRAPTR struct exadb_trap PTR

#define	DBTRAP_MODE	0x0001
#define	DBTRAP_PROC	0x0002
#define	DBTRAP_LOAD	0x0004
#define DBTRAP_EXEC	0x0008

struct	exadb_trap {
				/* ------------------------------------ */
	TRAPTR	next;		/* Pointer to next trap in list		*/
	TRAPTR	previous;	/* Pointer to next trap in list		*/
				/* ------------------------------------ */
	EXAWORD	trap_block;	/* Segment or Procedure ID		*/
	BPTR	trap_owner;	/* Program or Attachment Name		*/
	EXAWORD	trap_offset;	/* Offset into segment or procedure	*/
				/* ------------------------------------ */
	EXAWORD	trap_state;	/* Status Flags				*/
				/* ------------				*/
				/* Bit : 0	: Permenant = 1		*/
				/* Bit : 1	: Procedure = 1		*/
				/* Bit : 2      : Present   = 1		*/
				/* ------------------------------------ */
	EXAWORD	trap_code;	/* Tcode Value Replaced by NOP		*/
				/* ------------------------------------ */

	/* added for EXADB ABAL 3 */
	/* ---------------------- */
	EXAWORD	file_number;	
	EXAWORD	file_line;
	};


#ifdef	_EXDBTRAP_C
	TRAPTR	TrapBase;
	EXAWORD	TrapChanges;
#else	
EXTERN	TRAPTR	TrapBase;
EXTERN	EXAWORD	TrapChanges;
#endif

/*	Function Prototypes	*/
/*	-------------------	*/
#ifndef	UNIX

TRAPTR	TrapExist( EXAWORD, EXAWORD, EXAWORD );
BPTR	TcodeLocation( TRAPTR );
EXAWORD	XchgTcode4Nop( TRAPTR );
EXAWORD	TrapNumber( EXAWORD, EXAWORD, EXAWORD );
EXAWORD	HexaTcodeId( BPTR );
EXAWORD	TrapSearch( EXAWORD );
EXAWORD	checkpiege( EXAWORD, EXAWORD, EXAWORD );
VOID	XchgNop4Tcode( TRAPTR );
VOID	SegmentTrapWork( EXAWORD );
VOID	dismantle_trap( TRAPTR );
VOID	wipepiege( EXAWORD, EXAWORD, EXAWORD,BPTR );
TRAPTR	posepiege( EXAWORD, EXAWORD, EXAWORD, EXAWORD,BPTR );
VOID	showtrap( EXAWORD, EXAWORD, EXAWORD, EXAWORD, TRAPTR );
VOID	showtraps( EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, TRAPTR );
VOID	trap_correspondance( TRAPTR );
VOID	listpieges( VOID );
VOID	raztrap( EXAWORD );
VOID	traper( EXAWORD, BPTR );
VOID	initialise_trap_manager( VOID );
VOID	terminate_trap_manager( VOID );
#else
TRAPTR	TrapExist( );
BPTR	TcodeLocation( );
EXAWORD	XchgTcode4Nop( );
EXAWORD	TrapNumber( );
EXAWORD	HexaTcodeId( );
EXAWORD	TrapSearch( );
EXAWORD	checkpiege( );
VOID	XchgNop4Tcode( );
VOID	SegmentTrapWork( );
VOID	dismantle_trap( );
VOID	wipepiege( );
TRAPTR	posepiege( );
VOID	showtrap( );
VOID	showtraps( );
VOID	trap_correspondance();
VOID	listpieges( );
VOID	raztrap( );
VOID	traper( );
VOID	initialise_trap_manager( );
VOID	terminate_trap_manager( );
#endif

#endif	/* ! EXDBTRAPH */
	/* ----------- */
