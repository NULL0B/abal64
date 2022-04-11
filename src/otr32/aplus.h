/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990, 1993 Amenesik / Sologic s.a.                 */
/*                                                                      */
/*                                                                      */
/*              File    :       APLUS.H                                 */
/*              Version :       1.1a                                    */
/*              Date    :       27/11/1993                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
#ifndef APLUSH
#define APLUSH
#pragma check_stack-
				/* ------------------------------------ */
				/*  GENERATION MODEL PARAMETER DEFINES  */
				/* ------------------------------------ */
#define MEMBER_FILE_INFOS       /* Activates member source localisation */
#define ALLOCATION_INSPECTION   /* Allows memory allocation inspection  */
#define USE_TOKENS              /* Allows optimisation of name tokens   */
				/* ------------------------------------ */

#include "stdtypes.h"

#include "truser.h"

#define APLUS_VERSION '2'
#define APLUS_INDICE  '1'
#define APLUS_RELEASE 'd'

#define APLUS_ABAL_VERSION      20

#define APLUS_HASH               57
#define MEMBER_HASH              57
#define TOKENMAX                 64
#define MAXINCLUDE               32
#define MACRO_NAME_MAX           64
#define MAXNAMELEN              128
#define MAX_LABEL_SIZE           32
#define MAX_LIBRARY_MODULES      32
#define MIN_SWAP_BUFFERS          3

#define TEXT_MAX                 64
#define NESTED_MACROS            32

#define BLOCK 256
#define FILEPTR   FILE XPTR

/*      ---------------------------------------------   */
/*      Automatic Text Value Block Swapping mechanism   */
/*      ---------------------------------------------   */
#ifndef UNIX
#ifndef VMS

#define SWAP_CTRL
#include "buffers.h"

	/* ---- */
#endif  /* VMS  */
#endif  /* UNIX */
	/* ---- */

#include "value.h"

/*      ------------------------------------            */
/*      Global Structure Pointer Definitions            */
/*      ------------------------------------            */
#define SOURCEPTR struct source_ctrl XPTR
#define MACROPTR  struct aplus_macro XPTR

#define PARAMPTR  struct macro_param XPTR
#define DEFINEPTR struct aplus_define XPTR
#define CONTEXTPTR struct macro_context XPTR
#define PARASTACK  struct para_context XPTR
#define CONTROLPTR struct ctrl_context XPTR
#define MACROHEAP struct macro_heap XPTR
#define TYPEPTR struct param_type XPTR
#define BTREEPTR struct aplus_btree XPTR
#define VARIABLEPTR struct abal_variable XPTR

/*      ----------------------------            */
/*      Global Structure Definitions            */
/*      ----------------------------            */
struct  macro_heap {
	MACROPTR        current;
	MACROHEAP       next;
	};

struct  ctrl_context {
	WORD            status;
	CONTROLPTR      next;
	};

/*      Macro source context structure  */
/*      ------------------------------  */
struct macro_context {
	VALUEPTR        value;
	WORD            lastcharacter;
	WORD            labelcount;
	WORD            mode;
	CONTEXTPTR      next;
	};

/*      Source file management structure        */
/*      --------------------------------        */
struct source_ctrl {
	BPTR            name;
	FILEPTR         handle;
	WORD            linecount;
	WORD            linesize;
	WORD            status;
	SOURCEPTR       next;
	};


/*      Macro management structures     */
/*      ---------------------------     */
struct  param_type {
	WORD            typecheck;      /* Explicite type of data       */
	WORD            length;         /* Length of string data        */
	WORD            first;          /* First dimension              */
	WORD            second;         /* Second dimension             */
	WORD            status;         /* Allows protection of FunArgs */
	VPTR            class;          /* Class linkage pointer        */
	};

struct  abal_variable {
	BPTR            name;
	TYPEPTR         type;
	VARIABLEPTR     next;
	};

struct macro_param {
	BPTR            name;           /* Parameter identifier         */
	TYPEPTR         datatype;       /* Type of Data required        */
	TYPEPTR         paratype;       /* Type of Data Recieved        */
	VPTR            expression;     /* Allows stockage of length    */
	WORD            convert;        /* VRAI : Activates param value */
	WORD            type;           /* Static or Dynamic            */
	WORD            lock;           /* Parameter under expansion    */
	WORD            retval;         /* Explicite Return Value       */
	VALUEPTR        value;          /* Parameter current value      */
	PARAMPTR        next;           /* Pointer to next parameter    */
	};

struct aplus_macro {
	BPTR            name;           /* Pointer to name (ASCIZ)      */
	VALUEPTR        value;          /* Pointer to Macro (ASCIZ)     */
	PARAMPTR        parameter;      /* Pointer to Parameter control */
	MACROPTR        next;           /* Pointer to next in list      */
	WORD            usage;          /* Count of usage for labels    */
	WORD            number;         /* Macro identification number  */
	WORD            lock;           /* Recursivity indicator        */
	WORD            type;
	WORD            users;          /* Indicates number of users    */
	};

struct  aplus_define {
	BPTR            name;           /* Name of token defined        */
	WORD            status;         /* Definition status            */
	WORD            hash;           /* Hash value for quick search  */
	DEFINEPTR       next;           /* Point to next element        */
	};


struct  para_context {
	PARAMPTR        parameters;
	PARASTACK       next;
	};


/*      ---------------------------------------         */
/*      System File access Constant Definitions         */
/*      ---------------------------------------         */
#define READ_STREAM     "r"
#define WRITE_STREAM    "w"
#define RW_STREAM       "rw"

#define SOURCE_DEFINED          0x0004
#define OPTION_DEFINED          0x0002
#define STANDARD_DEFINED        0x0001

#define PROTO_SOURCE            0x0008
#define OBJECT_SOURCE           0x0004
#define LIBRARY_SOURCE          0x0002
#define MASTER_SOURCE           0x0001
#define INCLUDED_SOURCE         0x0000

/*      ---------------------------------------------   */
/*      Character set (special values for ABAL/APLUS)   */
/*      ---------------------------------------------   */
/*      White space     */
/*      -----------     */
#define ESPACE 0x0020
#define TABULATION 0x0009
#define NEWLINE 0x000A
#define NEWPAGE 0x000C
#define RETURN 0x000D
#define CTRL_Z 0x001A


/*      Punctuation characters  */
/*      ----------------------  */
#define EXCLAIM '!'
#define QUOTE '"'
#define DIEZE '#'
#define DOLLAR '$'
#define PERCENT '%'
#define LABEL '&'
#define APOSTROPHE 0x0027
#define LEFTBRACE '('
#define RIGHTBRACE ')'
#define MULTIPLY '*'
#define PLUS '+'
#define COMMA ','
#define MINUS '-'
#define POINT '.'
#define DIVIDE '/'
#define COLON ':'
#define SEMICOLON ';'
#define LESSTHAN '<'
#define EQUAL '='
#define GREATERTHAN '>'
#define QUESTION '?'
#define UNDERSCORE '_'

#define ABAL_ARG        " Arg "
#define ABAL_DCL        " Dcl "
#define ABAL_PTR        " Ptr "
#define ABAL_FIELD      "Field="
#define MEMORY_FIELD    "M"
#define ABAL_FILLER     "Filler="

/*      ------------------------------------    */
/*      Operating system dependant constants    */
/*      ------------------------------------    */

#ifdef DOS
#define MAX_SWAP_BUFFERS 2000
#define MOY_SWAP_BUFFERS 2000
#define HOST_SYSTEM "DOS"
#define OPTION_INDICATOR '-'
#define OPTION_ALTERNATIVE '/'
#define TRANSLATOR      "atr"
#define ABAL_LINKER     "ald"
#define ABAL_EDITOR     "aed"
#define OPTIMISER       "ao"
#define EXTENSION_TCODE ".at"
#define EXTENSION_SWAP  ".swp"
#define EXTENSION_APLUS ".ap"
#define EXTENSION_OBJET ".o"
#define EXTENSION_ERROR ".err"
#define EXTENSION_ABAL  ".aps"
#define EXTENSION_COMMON ".apc"
#define EXTENSION_FORWARD ".apf"
#define EXTENSION_INDIRECT ".app"
#define EXTENSION_OVERLAY ".apo"
#define DEFAULT_EXTENSION  "s"
#define EXTENSION_LIBRARY  "def"
#define EXTENSION_CLASSOBJ "apl"
#define EXTENSION_API      ".api"
#define EXTENSION_PROTO "pro"
#define SEPARATOR         "."
#define CHECK_PROTO_ARGS
#define EXIT_VALUE              0
#define EXIT_ERROR              1
#endif

#ifdef UNIX
#define MAX_SWAP_BUFFERS 2000
#define MOY_SWAP_BUFFERS 2000
#define HOST_SYSTEM "UNIX"
#define OPTION_INDICATOR '-'
#define OPTION_ALTERNATIVE '-'
#define TRANSLATOR      "atr"
#define ABAL_LINKER     "ald"
#define ABAL_EDITOR     "aed"
#define OPTIMISER       "ao"
#define EXTENSION_TCODE ".at"
#define EXTENSION_SWAP  ".swp"
#define EXTENSION_APLUS ".ap"
#define EXTENSION_OBJET ".o"
#define EXTENSION_ABAL  ".aps"
#define EXTENSION_ERROR ".err"
#define EXTENSION_COMMON ".apc"
#define EXTENSION_FORWARD ".apf"
#define EXTENSION_INDIRECT ".app"
#define EXTENSION_OVERLAY ".apo"
#define DEFAULT_EXTENSION "s"
#define EXTENSION_LIBRARY "def"
#define EXTENSION_CLASSOBJ "apl"
#define EXTENSION_API      ".api"
#define EXTENSION_PROTO "pro"
#define SEPARATOR         "."
#define EXIT_VALUE              0
#define EXIT_ERROR              1
#endif

#ifdef PROLOGUE
#define MAX_SWAP_BUFFERS 4000
#define MOY_SWAP_BUFFERS 3000 
#define HOST_SYSTEM "PROLOGUE"
#define OPTION_INDICATOR '-'
#define OPTION_ALTERNATIVE '/'
#define TRANSLATOR      "atr"
#define ABAL_LINKER     "ald"
#define ABAL_EDITOR     "aed"
#define OPTIMISER       "ao"
#define EXTENSION_TCODE ".at"
#define EXTENSION_SWAP  ".swp"
#define EXTENSION_OBJET ".o"
#define EXTENSION_APLUS ".ap"
#define EXTENSION_ABAL  ".aps"
#define EXTENSION_ERROR ".e"
#define EXTENSION_COMMON ".apc"
#define EXTENSION_FORWARD ".apf"
#define EXTENSION_INDIRECT ".app"
#define EXTENSION_OVERLAY ".apo"
#define DEFAULT_EXTENSION "s"
#define EXTENSION_LIBRARY "def"
#define EXTENSION_CLASSOBJ "apl"
#define EXTENSION_API      ".api"
#define EXTENSION_PROTO "pro"
#define SEPARATOR         "."
#define CHECK_PROTO_ARGS
#define EXIT_VALUE              0
#define EXIT_ERROR              1
#endif

#ifdef VMS
#define MAX_SWAP_BUFFERS 2000
#define HOST_SYSTEM "VMS"
#define OPTION_INDICATOR '/'
#define OPTION_ALTERNATIVE '-'
#define TRANSLATOR      "atr"
#define ABAL_LINKER     "ald"
#define ABAL_EDITOR     "aed"
#define OPTIMISER       "ao"
#define EXTENSION_TCODE ".at"
#define EXTENSION_SWAP  ".swp"
#define EXTENSION_OBJET ".o"
#define EXTENSION_APLUS ".ap"
#define EXTENSION_ABAL  ".aps"
#define EXTENSION_ERROR ".err"
#define EXTENSION_COMMON ".apc"
#define EXTENSION_FORWARD ".apf"
#define EXTENSION_INDIRECT ".app"
#define EXTENSION_OVERLAY ".apo"
#define EXTENSION_LIBRARY "def"
#define EXTENSION_CLASSOBJ "apl"
#define EXTENSION_API      ".api"
#define EXTENSION_PROTO "pro"
#define DEFAULT_EXTENSION "s"
#define SEPARATOR         "."
#define unlink(a) delete(a)
#define EXIT_VALUE              1
#define EXIT_ERROR              0
#endif

#define ESCAPE 0x001B


/*      ----------------------------    */
/*      Error code and return values    */
/*      ----------------------------    */

#define FATALE                  MOINS_UN
#define WARNING                 1
#define NON_FATALE              0

#define ALREADY_DEFINED         1
#define SYMBOL_NOT_DEFINED      2
#define SOURCE_FILE_NOT_FOUND   3
#define TARGET_FILE_CREATION    4
#define MEMORY_ALLOCATION       5
#define ILLEGAL_OPTIONS         6 
#define DIRECTIVE_UNKNOWN       7
#define MACRO_NESTING           8       
#define CLASS_STRUCTURE_NESTING 9
#define UNEXPECTED_ENDMACRO     10
#define UNEXPECTED_ENDSTRUCTURE 11
#define TOO_MANY_INCLUDE_LEVELS 12
#define UNEXPECTED_ELSE         13
#define UNEXPECTED_ENDIF        14
#define APLUS_ABORT             15
#define ERROR_FILE_CREATION     16
#define NOT_ENOUGH_PARAMETERS   17
#define UNEXPECTED_ENDCLASS     18
#define ILLEGAL_DIRECTIVE       19
#define CLASS_ALREADY_DECLARED  20
#define ERROR_CREATING_CLASS    21
#define METHOD_INSIDE_STRUCTURE 22
#define ERROR_CREATING_OBJECT   23
#define UNKNOWN_METHOD          24
#define ILLEGAL_PRIVATE_ACCESS  25
#define CLASS_LINKAGE_ERROR     26
#define ILLEGAL_INHERITANCE     27
#define UNKNOWN_OBJECT          28
#define VIRTUAL_CLASS_ERROR     29
#define SYNTAX_ERROR            30
#define VIRTUAL_FILE_ID         31
#define UNEXPECTED_END_OF_FILE  32
#define INCORRECT_OVERLOADING   33
#define OBJECT_OVERLOADING      34
#define RECURSIVE_MACRO         35
#define UNKNOWN_CLASS           36
#define REDECLARATION_OF_OBJECT 37
#define UNEXPECTED_ENDUNION     38
#define CANNOT_CHANGE_FIELD     39
#define UNMATCHED_BRACKETS      40
#define CLASS_PADDING           41
#define CLASS_EXCEEDING_LIMIT   42
#define MEMBER_FUNCTION_ERROR   43
#define RECURSIVE_CLASS         44
#define TOO_MANY_PARAMETERS     45
#define REDEFINE_LIMIT          46
#define TOO_MANY_MODULES        47
#define REDEFINITION_OF_VARIABLE 48
#define INCORRECT_PARAMETER_TYPE 49
#define STRICT_MACRO_NO_PARAM   50
#define INCORRECT_CONSTANT_TYPE 51
#define PROTECTED_MEMBER        52
#define OBJECT_TOO_BIG          53
#define UNKNOWN_PRAGMA          73
#define TOO_MANY_OVERLAYS       74
#define ILLEGAL_OVERLAY_PARAM   75
#define OVERLAY_ALREADY_USED    76
#define LOCAL_OBJECT_OVERLAY    77
#define INCORRECT_CLASS_FILE    78
#define EXTERN_NOT_COMMON       79
#define ILLEGAL_EXTERN_MEMBER   80
#define ROUTINE_IS_INLINE       81
#define PARTIAL_INHERIT_DATA    82
#define ARG_ALREADY_EXISTS      83
#define PARAMETER_MEMBER_CLASH  84
#define VERSION_ERROR           85
#define COMMON_FIELD_ERROR      86
#define COMMON_HIDES_OBJECT     87
#define OVERLAY_BECAME_FUNCTION 105
#define ILLEGAL_OVERLAY_USAGE   106
#define INHIBITED_CLASS_FUNC    107
#define INFORMATION_TITLE_MSG   imessage_text(108)
#define VIRTUAL_CLASS_INSTANCE  109
#define OBJECT_AFFECTATION      110
#define KEYWORD_ERROR           111
#define ILLEGAL_MEMBER_NAME     146
#define INHERIT_STATIC_INDIRECT 147

/*      -----------------------------   */
/*      Translator option flag values   */
/*      -----------------------------   */
#define ATR_OPTIMISE            0x0001
#define ATR_CONSTANTS           0x0002
#define ATR_SYMBOLIC            0x0004
#define ATR_VERBOSE             0x0008
#define ATR_WARNING             0x0010
#define ATR_BIBMATH             0x0020

#define ATR_RESULT              0x0100
#define ATR_INCLUDE             0x0200
#define ATR_ERRORTRACE          0x0400
#define ATR_LISTE               0x0800

/*      ----------------------------------------------------    */
/*      Suplimentary System dependant Macros and Definitions    */
/*      ----------------------------------------------------    */
#ifndef UNIX
#ifndef VMS
#define FARBPTR BYTE far XPTR
#endif
#endif

#ifdef  UNIX
#define systeme(arg1) system(arg1)
#endif

#ifndef UNIX
WORD    fn_parser( FARBPTR , FARBPTR , WORD );
WORD    systeme( FARBPTR );
#endif


BPTR imessage_text(WORD);

#endif
 
