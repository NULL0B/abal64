#ifndef _TRWORLD_H
#define _TRWORLD_H

#ifdef  PROLOGUE
#define _WORLD_ERROR_FILE "etrace.e"
#define _WORLD_LIST_FILE "elist.e"
#define _WORLD_TRACE_FILE "xtrace.e"
#else
#define _WORLD_ERROR_FILE "etrace.err"
#define _WORLD_LIST_FILE "elist.lst"
#define _WORLD_TRACE_FILE "xtrace.err"
#endif

#define _WORLD_EDITOR "aed"

#define CLASS_TREE_HASH 27
#define WORLDPTR        struct otr_world XPTR
#define PRAGMAPTR       struct otr_user_pragma XPTR
#define HOSTPTR		struct otr_host XPTR

#define _SWAP_BUFFERS   3500

struct  otr_user_pragma {
	BPTR            name;
	WORD            state;
	PRAGMAPTR       next;
	};

struct	otr_host	{
	WORD		nature;		/* dotted type			*/
	WORD		line;		/* current stream line number	*/ 
	BPTR		prefix;		/* object or file 		*/
	BPTR		postfix;	/* method ... 	  		*/
	HOSTPTR		previous;
	};


struct  otr_world       {
	BPTR            ErrorFile;
	BPTR            ListFile;
	FILEPTR         ListHandle;
	BPTR		PragmaFile;
	BPTR            TraceFile;
	BPTR            Editor;
	TCSTRUCTPTR     FirstStructure;        
	TCSTRUCTPTR     Structures;
	TCSTRUCTPTR     CurrentStructure;
	COMMONPTR       Common;
	COMMONPTR       LastCommon;
	TCMEMBERPTR     Macros;
	DEFINEPTR       DefineList;
	STATEPTR        StateHeap;
	WORD            SwapBuffers;
	WORD            Scope;
	WORD            Virtual;
	TREEPTR         TreesUsed;
	TREEPTR         ClassTree[CLASS_TREE_HASH];
	TCVARPTR        VariableHeap;
	PRAGMAPTR       DefinedPragmas;
	HOSTPTR		SymbolicHost;
	BPTR		StyleSheet;
	};



#ifdef  _TRDIRECT_C
	WORLDPTR        World=(WORLDPTR) 0;
#else
EXTERN  WORLDPTR        World;
#endif


#ifndef UNIX
VOID    terminate_world_list( VOID );
WORD    terminate_world( VOID );
WORD    set_world_virtual( VOID );
WORD    get_world_virtual( VOID );
WORD    initialise_world( VOID );
WORD    enter_world( VOID );
WORD    leave_world( VOID );
WORD    flush_world_members( VOID );
WORD    class_enhanced_indirect( TCSTRUCTPTR );
WORD    member_enhanced_indirect( TCMEMBERPTR );
BPTR    world_editor( VOID );
BPTR    world_errorfile( WORD );
BPTR    world_listfile( WORD );
BPTR    world_tracefile( WORD );
WORD    set_world_editor( BPTR );
WORD    set_world_errorfile( BPTR, BPTR );
WORD    set_world_listfile( BPTR, BPTR );
WORD    set_world_tracefile( BPTR );
WORD    flush_module_commons( TCSTRUCTPTR );

#else
BPTR    world_editor();
WORD    set_world_editor();
BPTR    world_errorfile();
BPTR    world_tracefile();
BPTR    world_listfile();
WORD    set_world_listfile();
WORD    set_world_errorfile();
WORD    initialise_world();
WORD    terminate_world();
#endif

#endif  /* _TRWORLD_H */
