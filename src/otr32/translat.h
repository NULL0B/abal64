#ifdef	DOS
#define	__QUALITY_CONTROL
#endif

/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1995 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRANSLAT.H				*/
/*		Version :	2.1d					*/
/*		Date	:	14/05/1995				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRANSLAT_H
#define	_TRANSLAT_H

#include "trsystem.h"

#ifndef	UNIX
#ifndef	WIN32
#define	SWAP_CTRL
#endif
#endif

#ifdef	DOS
#ifndef WIN32
#define	HUGE	unsigned long
#endif
#endif

#ifdef	PROLOGUE
#define	HUGE	unsigned long
#endif

#ifndef WIN32
#define	sysprintf printf
#endif

#define	TEXT_MAX 	 	64
#define	MAX_BCD_BYTES		12

#define	_TOOL_IDENTITY		"OTR"

/*	---------------------------	*/
/*	Default Tcode Pragma Values	*/
/*	---------------------------	*/

#define	_DIEZEMEM 		2048
#define	_DIEZEFILES		  64
#define	_DIEZESTACK		 256
#define	_DIEZEHEAP		1024
#define	_FIRST_NAMED_SEGMENT	 256
#define	_MAX_NESTED_OPERATIONS	  32
#define	_DEFAULT_ERROR_LIMIT	 256

/*	-------------------------	*/
/*	Tcode Context Definitions	*/
/*	-------------------------	*/
#define	_CONTEXT_PROGRAM	0x0000
#define	_CONTEXT_MODULE		0x0001
#define	_CONTEXT_NOCLR 		0x0002
#define	_CONTEXT_OVERLAY	0x0008
#define	_CONTEXT_OCX    	0x0010

#define	context_is_program (!(Context->options & _CONTEXT_MODULE))
#define	context_is_module  (Context->options & _CONTEXT_MODULE)
#define	context_is_overlay (Context->options & _CONTEXT_OVERLAY)
#define	context_is_ocx     (Context->options & _CONTEXT_OCX)
#define	context_is_noclr   (Context->options & _CONTEXT_NOCLR)

#define	ISLOCAL3	0x8000
#define	TOGLOBAL3	0x7FFF
#define	ISLOCAL4	0x0001
#ifdef	otr32
#define	TOGLOBAL4	0xFFFFFFFE
#else
#define	TOGLOBAL4	0xFFFE
#endif

#define	ISLOCAL		IsLocal
#define	TOGLOBAL	ToGlobal

/*	-------------------------	*/
/*	Tcode Compare Definitions	*/
/*	-------------------------	*/

#define	_CMP_EQ		1
#define	_CMP_NE		2
#define	_CMP_GE		3
#define	_CMP_LE		4
#define	_CMP_GR		5
#define	_CMP_LS		6
#define	_CMP_IN		7
#define	_CMP_NI		8

#ifdef	NO_BUG_WITH_THIS_MACRO
#define	set_operation_pointer( fp ) Context->operation = fp
#endif

/*	---------------------------------------------------	*/
/*	Definitions of pointers to various tcode Structures	*/
/*	---------------------------------------------------	*/

#include "trtype.h"	/* Data Type Definitions and Structure	*/

#define	_LDF_PRIVATE	0
#define	_LDF_PUBLIC	1
#define	_LDF_COMMON	2

#include "tctype.h"
#ifdef	SWAP_CTRL
#include "buffers.h"
#define VALUEPTR  BUFFERHANDLE
#define	VALUEBUF  struct tcode_value XPTR
#else
#define VALUEPTR  struct tcode_value XPTR 
#endif


/*		-----------------------					*/
/*		T C O D E _ M O D U L E					*/
/*		-----------------------					*/
struct	tcode_module	{
	BPTR		name;
	WORD		number;
	TCMODPTR	next;
	};

/*		-----------------------------------			*/
/*		T C O D E _ L O C A L _ E X T E R N 			*/
/*		-----------------------------------			*/

struct	tcode_local_extern	{
	WORD		number;
	WORD		sector;
	WORD		length;
	XTLOCALPTR	next;
	};


/*		-------------------------------				*/
/*		T C O D E _ F I E L D _ N O D E				*/
/*		-------------------------------				*/

struct	tcode_field_node	{
	FIELDPTR	contents;
	FIELDNODEPTR	next;
	};


#include "tclabel.h"

/*		---------------------------------------------		*/
/*		T C O D E _ E X T E R N A L _ V A R I A B L E		*/
/*		---------------------------------------------		*/

struct	tcode_external_variable  	{
	TCVARPTR	variable;
	XTVARPTR	next;
	};


/*		-----------------------------------			*/
/*		T C O D E _ E X T E R N _ F I E L D			*/
/*		-----------------------------------			*/

struct	tcode_extern_field	{
	FIELDPTR	field;
	BPTR		name;		/* Name of explicite field	*/
	HUGE		offset;		/* Offset from field type base	*/
	WORD		nature;		/* mea, MEA, field type		*/
	WORD		sector_XVT;	/* Sector number of members	*/
	WORD		entry_XLT;	/* External Local Table Entry   */
	WORD		module;		/* Module number or -1 if ANY	*/
	XTVARPTR	member;		/* List of associated members	*/
	WORD      	members;	/* Number of members		*/
	WORD		usedmembers;	/* actually used 		*/
	XTFIELDPTR  	next;
	};

/*		---------------------					*/
/*		T C O D E _ F I E L D					*/
/*		---------------------					*/

struct	tcode_field {
	WORD		MaxSmallField;
	WORD		SmallField;
	HUGE		FileField;
	HUGE		BigField;
	HUGE		MaxBigField;
	WORD		Field;
	WORD		Host;
	};

/*		---------------------					*/
/*		T C O D E _ V A L U E					*/
/*		---------------------					*/

struct tcode_value {
	WORD		irite;		/* Write Offset			*/
	WORD		iread;		/* Read  Offset			*/
	VALUEPTR	next;		/* Pointer to next line		*/
	BYTE		text[TEXT_MAX];	/* Line of macro information	*/
	};


#include "trstruct.h"
#include "tcvar.h"

/*			---------------------------			*/
/*			T C O D E _ C O N S T A N T			*/
/*			---------------------------			*/

struct	tcode_constant {
					/* ---------------------------- */
	WORD		identity;	/* Table Offset or Integer val  */
	BPTR		name;		/* Name of constant or NULL	*/
	TCTYPPTR	type;		/* Type of constant		*/
	BPTR		value;		/* Pointer to value for strings	*/
	WORD		length;		/* Length of value string	*/
	WORD		hash;		/* hash value for quick alias	*/
	RELOCPTR	relocation;	/* List of Global Rellocation	*/
	TCCONPTR	redirect;	/* Redirection to Global Entry	*/
	TCCONPTR	next;		/* Next constant in table	*/
					/* ---------------------------- */
	};

#include "tc.h"

/*		-------------------------------				*/
/*		E X T E R N A L _ S E G M E N T				*/
/*		-------------------------------				*/

struct	external_segment	{
	BPTR		name;
	WORD		number;
	WORD		identity;
	BPTR		module_name;
	WORD		module_number;
	WORD		explicite;
	RELOCPTR	relocation;
	XTSEGPTR	next;
	};


/*		---------------------------				*/
/*		T C O D E _ S Y M B O L I C				*/
/*		---------------------------				*/

struct	tcode_symbolic	{
	WORD	sector_SegmentNames;
	WORD	sector_ProcedureNames;
	WORD	sector_ConstantNames;
	WORD	sector_FileNames;
	WORD	sector_ListNames;
	};

/*		-------------------------------------			*/
/*		T C O D E _ C O N T R O L _ T A B L E			*/
/*		-------------------------------------			*/

#include "trexpres.h"


struct	tcode_control_table {

	BYTE		TcodeFileName[128];

	struct tcode_symbolic Symbolic;

	TCMEMBERPTR	DclStruct;

	WORD		ProcedureCount;	/* Number of procedures		*/
	WORD		SegmentCount;	/* Number of Segments		*/
	BPTR		name;		
	BYTE		identity[15];	/* Target  Identity string	*/
	WORD		options;	/* Program Options NOCLR,DB	*/
	WORD		StopLabel;	/* Indicates STOP used		*/
	WORD		SegmentZero;	/* True when generated		*/
	WORD		LeaveLabel;	/* Indicates EXIT/RETSEG used	*/
	WORD		CodeClosed;	/* Indicates Closure Required	*/

	TCMODPTR	XMT;		/* External Modules Table	*/
	TCCONPTR	GCT;		/* Global Constants Table	*/
	TCCONPTR	LCT;		/* Local Constants Table	*/
	TCCONPTR	XCT;		/* External Constants Table	*/
	TCCONPTR	XLCT;		/* Most Recent Local Constant	*/
	TCVDTPTR	GDT;		/* Global Variables Table	*/
	TCVDTPTR	XDT;		/* External Variables Table	*/
	TCSEGPTR	SDT;		/* Internal Segment Table	*/
	TCPRCPTR	PDT;		/* Interal Procedure Table	*/
	TCPRCPTR	XPDT;		/* Most Recent Procedure	*/
	TCPRCPTR	PRC;		/* Current  Procedure		*/
	TCPRCPTR	XPT;		/* External Procedure Table 	*/
	TCVDTPTR	LDT;		/* Local Variable Table		*/

	TCDLBPTR	DLT;		/* Dynamic libraries table	*/
	TCDLBPTR	XDLT;		/* Most recent DLL		*/

	TCLABELPTR	GLT;		/* Global Data Labels List	*/

	TCSEGPTR	CurrentSegment;	/* Current Segment		*/
	XTSEGPTR	XTS;		/* External Segment Table	*/

	XTSEGPTR	RelocateSegment;/* Segment needing Rellocation	*/
	TCPRCPTR	RelocateProc;	/* Proc needing Rellocation	*/
		
	XTFIELDPTR	XFT;		/* External Field Control	*/

	XTFIELDPTR	CurrentXFT;	/* External Field Control	*/

	XTLOCALPTR	XLT;		/* External Local Control	*/
	XTLOCALPTR	CurrentXLT;	/* External Local Control	*/

	WORD		ExternalSegments; 
	WORD		ExternalProcedures;	
	WORD		ExternalFields;
	WORD		ExternalVariables;
	WORD		ExternalLocals;

	struct tcode_field LocalField;
	struct tcode_field GlobalField;

	FIELDPTR	ThisField;
	FIELDNODEPTR	FieldHeap;

	TCVARPTR	TargetVariable;	/* Used by affectation and evaluation of expressions 	*/
	WORD		UseTarget;	/* controls use of above for nested expressions		*/

	WORD		DataCount;
	WORD		DataOffset;

	WORD		DiezeMem;
	WORD		DiezeFiles;
	WORD		DiezeStack;
	WORD		DiezeHeap;
	WORD		ProcedureId;
	WORD		DebugNature;	/* 0 : Offsets, 1 : Lines	   */
	TCVARPTR	Argument;
	WORD		ArgumentVariable;
	WORD		sector_GVT;	/* Sector of Global Variable Table */
	WORD		length_GVT;	/* Length of Global Variable Table */
	WORD		length_LVT;	/* Length of Local Variable Table  */
	WORD		sector_GCT;	/* Sector of Global Constant Table */
	WORD		length_GCT;	/* Length of Global Constant Table */
	WORD		length_LCT;	/* Length of Local  Constant Table */
	WORD		megas_ETD;	/* Mega-Byte Count of Extended Mem */
	WORD		paras_ETD;	/* Paragraph Count of Extended Mem */
	WORD		sector_SDT;	/* Sector of Segment Table	   */
	WORD		length_SDT;	/* Length of Segment Table	   */
	WORD		sector_PDT;	/* Sector of Procedure Table	   */
	WORD		length_PDT;	/* Length of Procedure Table	   */
	WORD		sector_DLT;	/* Sector of Library   Table	   */
	WORD		length_DLT;	/* Length of Library   Table	   */
	WORD		sector_MAP;	/* Sector of 1.4 Debug MAP Table   */
	WORD		sector_LST;	/* Sector of 1.4 Debug LST Table   */

	WORD		sector_XTS;	/* Sector External Segments Table   */
	WORD		length_XTS;	/* Length External Segments Table   */
	WORD		sector_XPT;	/* Sector External Procedure Table  */
	WORD		length_XPT;	/* Length External Procedure Table  */

	WORD		sector_XMT;	/* Sector External Modules Table    */
	WORD		sector_XDT;	/* Sector External Descript.Table   */
	WORD		length_XDT;	/* Length External Descript.Table   */
	WORD		sector_XFT;	/* Sector External Fields Table     */
	WORD		length_XFT;	/* Length External Fields Table     */

	WORD		sector_XLT;	/* Sector of External Local Table   */

	WORD		sector_TRV;	/* Sector of Global Variable Relloc */
	WORD		sector_TRC; 	/* Sector of Global Constant Relloc */
	WORD		sector_TRL;	/* Sector of Library Relocation	    */

	WORD		sector_GLT;	/* Sector of Global Labels Table    */
	WORD		number_GLT;	/* Number of Global Labels 	    */

	WORD		sector_NCT;	/* Sector of Nural Class Table      */
	WORD		length_NCT;	/* Length of Nural Class Table      */

	WORD		Visibility;
	
	WORD		count_DLT;

	WORD		biggest_LDT;
	WORD		biggest_LDS;

	RESULTPTR	(*symbolic_term)();
	WORD		(*operation)();
	WORD		(*xoperation[_MAX_NESTED_OPERATIONS])();

	WORD		xoperindex;
	WORD		scope;
	WORD		SegmentNumber;

	WORD		ConvertType;
	WORD		OperandType;
	WORD		Started;
	WORD		LoadAdresse;	/* Force VPT generation not LDV */
	WORD		Depth;		/* Depth (1->N) of Expression   */

	WORD		LanguageCode;	/* Marks translation language	*/
	WORD		Semaphores;	/* Number of IPC Semaphores	*/
	WORD		Correspondance;	/* Allows collection of debug   */
	};


/*	----------------------------------------	*/
/*	TCODE CONTROL STRUCTURE INSTANCE POINTER 	*/
/*	----------------------------------------	*/

#ifdef	_TRTABLES_C
	WORD		ISLOCAL=ISLOCAL3;
	WORD		TOGLOBAL=TOGLOBAL3;
	TCFDTPTR	Context;
#else
EXTERN	WORD		ISLOCAL;
EXTERN	WORD		TOGLOBAL;
EXTERN	TCFDTPTR	Context;
#endif

/*	-------------------	*/
/*	FUNCTION PROTOTYPES	*/
/*	-------------------	*/

#ifndef	UNIXCANDOTHISNOW
WORD		initialise_source_translation( BPTR );
WORD		initialise_remote_translation( BPTR );
WORD		terminate_translation( WORD );
WORD		line_translation( BPTR );
TCVARPTR	allocate_for_variable();
TCTYPPTR	allocate_for_type( WORD, WORD, WORD, WORD, VPTR );
TCPRCPTR	add_procedure( TCPRCPTR, WORD, WORD );
TCCONPTR	build_implicite_constant( WORD );
TCVARPTR	collect_dimensions( TCVARPTR );
WORD		translator_startup();
XTSEGPTR	locate_external_segment( BPTR );
TCCONPTR	build_explicite_constant( WORD, BPTR);
TCVARPTR	get_variable( WORD );
TCVARPTR	resolve_structure_member( TCVARPTR );
TCVARPTR	temp_variable( TCVARPTR );
#else	/* UNIX */
WORD		initialise_source_translation();
WORD		initialise_remote_translation();
WORD		terminate_translation();
WORD		line_translation();
TCVARPTR	allocate_for_variable();
TCTYPPTR	allocate_for_type();
TCPRCPTR	add_procedure();
TCCONPTR	build_implicite_constant();
TCVARPTR	collect_dimensions();
WORD		translator_startup();
XTSEGPTR	locate_external_segment();
TCCONPTR	build_explicite_constant();
TCVARPTR	get_variable();
TCVARPTR	resolve_structure_member();
TCVARPTR	temp_variable();
#endif

/*	------------------------------		*/
/*	Global Definition Requirements		*/
/*	------------------------------		*/
#include "trmalloc.h"
#include "trtree.h"
#include "trdefine.h"
#include "trworld.h"


#endif 	/* _TRANSLAT_H */

