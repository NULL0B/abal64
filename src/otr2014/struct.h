/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1991, 1993 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	STRUCT.H				*/
/*		Version :	1.1a					*/
/*		Date	:	28/07/1993				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	STRUCTH
#define	STRUCTH
#define	HASH_CLASS	17
#define	HASH_OBJECT	17
#define	CLASSPTR	struct aplus_struct_class XPTR
#define	MEMBERPTR	struct aplus_struct_member XPTR
#define	OBJECTPTR	struct aplus_structure XPTR
#define	CCONSTPTR	struct class_const XPTR
#define	AUTOPTR		struct auto_manager XPTR
#define	HASHCLASS	struct hash_class XPTR
#define	HASHOBJECT	struct hash_object XPTR
#define	GOSUBPTR	struct inline_gosub XPTR
#define	EXPRESSPTR	struct aplus_expression XPTR
#define	USERPTR		struct member_user XPTR
#define	CLSLIBPTR	struct class_library XPTR

#include "relation.h"	/* Class usage relationships 	*/

struct	class_library	{
	BPTR		name;
	WORD		members;
	WORD		status;
	CLSLIBPTR	next;
	};

struct	aplus_expression {
	WORD		type;	/* Type of usage 		*/
	VALUEPTR	value;	/* Value ptr	 		*/
	EXPRESSPTR	next;	/* next in list of expressions	*/
	};

struct	class_const {
	WORD		type;	/* # % $ or Bcd type		*/
	WORD		value;	/* Value for integer constants	*/
	VALUEPTR	text;	/* Value block text for others	*/
	};

/*	Structure describing CLASS.member composition		*/
/*	----------------------------------------------		*/
struct	aplus_struct_member {
	BPTR		name;	/* identification name of member 	*/
	WORD		hash;	/* name hash value			*/
	TYPEPTR		dcltype; /* Used by variable management		*/
	EXPRESSPTR	expression;
	USERPTR		userlist;
/*	--------------------------------------------------------------- */
/*	WORD		argument;  Indicates Command Reception Member	*/
/* 	--------------------------------------------------------------- */
	WORD		condition;
	WORD		length;	/* Memory size of member (LEN)		*/
	WORD		type;	/* Data Type of member #,%,N,$		*/
	WORD		number; /* Variable number in class		*/
	WORD		dim1;	/* 1st Dimension			*/
	WORD		dim2;	/* Second dimension			*/
	WORD		adjust;	/* Number of members in this member	*/
	WORD		members; /* Static Structure Member count	*/
/* 	--------------------------------------------------------------- */
/*	WORD		access;    PRIVATE , PROTECT , PUBLIC           */
/* 	--------------------------------------------------------------- */
	WORD		common;	/* Indicates Common variable (VRAI)	*/
/* 	--------------------------------------------------------------- */
/*	WORD		cmnlock;   Locks auto methods of common class	*/
/* 	--------------------------------------------------------------- */
	WORD		function; /* Indicates Not InLine (VRAI)	*/
	WORD		overlay; /* Indicates an overlay segment method */
	TYPEPTR		rettype; /* Procedural return type (ABAL 1.5)	*/
	WORD		routine;/* Indicates a Gosub Inline		*/
/* 	--------------------------------------------------------------- */
/*	WORD		flag;		End of Union Flag		*/
/* 	--------------------------------------------------------------- */
	WORD		istatic; /* Static linkage number		*/
	WORD		special; /* Identifies constructors / destruct  */
/* 	--------------------------------------------------------------- */
/*	WORD		crossref;  Indicates an external Data member  	*/

#ifdef	MEMBER_FILE_INFOS
/*	--------------------------------------------------------------- */
/*	The following two fields manage source file localisation of the	*/
/*	member described by the current structure if a method member	*/
/*	for debug and error tracing					*/
/*	--------------------------------------------------------------- */
	BPTR		filename; /* Filename in which class is defined	*/
	WORD		fileline; /* Line in source file		*/
	LONG		filebyte; /* For Debug APLUS Source following	*/
/* 	--------------------------------------------------------------- */
#endif

	WORD		users;	/* Counts usage of local members	*/
	MEMBERPTR	local;	/* Local variables for Methods		*/
	CCONSTPTR	cconst;	/* Constant description for constants	*/
	CLASSPTR	class;	/* Class linkage for inherited class	*/
	CLASSPTR	iclass; /* Class ID for Common/Function		*/
	MACROPTR	macro;	/* Function macro pointer		*/
	MEMBERPTR	next;	/* Pointer to next member in class	*/
	};

struct	member_user {
	MEMBERPTR	member;
	USERPTR		next;
	};

#include "friend.h"

/*	Structure managing declared classes			*/
/*	-----------------------------------			*/
struct	aplus_struct_class {
	BPTR		name;	/* identification of structure class	*/
	MEMBERPTR	member; /* Descriptive list of class members 	*/ 
	WORD		size;	/* Size of complete structure		*/
	WORD		count;	/* Number of members in this CLASS	*/
	WORD		cumul;	/* Cumulate Members in class		*/
	WORD		type;	/* Class or Structure header type	*/
	WORD		limit;	/* Explicite Class Size 		*/
	WORD		number;	/* Unique Class Number			*/
	WORD		status; /* Inhibited class functions flag	*/
#ifdef	USING_DLL
	WORD		structure;
#endif
	WORD		functions; /* Number of functions		*/
	MEMBERPTR	condition; /* List of conditions and exceptions */
	CLSLIBPTR	library; /* List of user libraries		*/
	FRIENDPTR	friend;	/* List of 'FRIEND' classes		*/
	BCLASSPTR	baselist; /* List of 'BASE' classes		*/
	BCLASSPTR	searchlist; /* Resolved list of base classes	*/
	RELATIONPTR	users;	/* List of class usage members		*/
	CLASSPTR	next;	/* Pointer to next class in list	*/
	};

/*	Structure managing Instanced Objects				*/
/*	------------------------------------				*/
struct	aplus_structure {
	BPTR		name;	/* identification name of object   	*/
	WORD		number;	/* identification number allocated 	*/
	WORD		type;	/* Normally 0 : Global : 1 : Local	*/
	WORD		status; /* Extern, Common etc			*/
	WORD		field;	/* Current Memory Field			*/
	CLASSPTR	class;	/* Pointer to object class information	*/
	MACROPTR	macro;	/* Formal parameters for Constructors	*/
	OBJECTPTR	next;	/* pointer to next object instance   	*/
	};

/*	Structure list of Auto Objects Constructors/Desctructors 	*/
/*	--------------------------------------------------------	*/
struct	auto_manager {
	OBJECTPTR	object;
	AUTOPTR		last;
	AUTOPTR		next;
	};

/*	Quick find structure for CLASS names	*/
/*	------------------------------------	*/
struct	hash_class	{
	CLASSPTR	class;
	HASHCLASS	next;
	};

/*	Quick find structure for OBJECT names	*/
/*	-------------------------------------	*/
struct	hash_object	{
	OBJECTPTR	object;
	HASHOBJECT	next;
	};

struct	inline_gosub	{
	MEMBERPTR	member;
	OBJECTPTR	object;
	CLASSPTR	class;
	WORD		adjust;
	MEMBERPTR	father;
	WORD		idpere;
	WORD		number;
	WORD		common;
	WORD		field;
	GOSUBPTR	next;
	};

	
/*	Data type internal representation constants	*/
/*	-------------------------------------------	*/

#define	_DATA_TYPE		0x0003
#define	_TYPE_DIEZE		0x0000
#define	_TYPE_PERCENT		0x0001
#define	_TYPE_BCD		0x0002
#define	_TYPE_DOLLAR		0x0003
#define	_TYPE_UNION		0x0004
#define	_TYPE_UNION_END		0x0004
#define	_TYPE_INHERIT		0x0008
#define	_TYPE_REDEFINE		0x0010
#define	_TYPE_SECOND		0x0020
#define	_TYPE_FIRST		0x0040
#define	_TYPE_METHOD		0x0080
#define	_TYPE_EXTERN		0x0400
#define	_TYPE_ARGUMENT		0x0800
#define	_TYPE_FIELD		0x7F00
#define _TYPE_POINTER		0x8000
#define	_TYPE_FUNCTION		0x2000

#define	_TYPE_CONSTRUCTOR	0x0040
#define	_TYPE_DESTRUCTOR	0x0080

#define	_LOCK_CONSTRUCTOR	0x0100
#define	_LOCK_DESTRUCTOR	0x0200
#define	_LOCK_COMMON_AUTO	( _LOCK_CONSTRUCTOR | _LOCK_DESTRUCTOR )

/*	Detection of Special member types	*/
/*	---------------------------------	*/
#define	SPECIAL_CONSTRUCTOR( mbm ) (mbm->special & _TYPE_CONSTRUCTOR)
#define	SPECIAL_AUTO( mbm )	   (mbm->special & (_TYPE_CONSTRUCTOR | _TYPE_DESTRUCTOR) )
#define	SPECIAL_DESTRUCTOR( mbm )  (mbm->special & _TYPE_DESTRUCTOR)
#define	SPECIAL_INHERIT( mbm )     (mbm->special & _TYPE_INHERIT)
#define	SPECIAL_EXTERN( mbm ) 	   (mbm->special & _TYPE_EXTERN)
#define	SPECIAL_ARGUMENT( mbm )    (mbm->special & _TYPE_ARGUMENT)
#define	SPECIAL_PRIVATE( mbm )     (mbm->special & _TYPE_PRIVATE)
#define	SPECIAL_PROTECT( mbm )     (mbm->special & _TYPE_PROTECT)
#define	SPECIAL_UNION_END( mbm )   (mbm->special & _TYPE_UNION_END)


/*	Memory field constants and type definitions	*/
/*	-------------------------------------------	*/
#define	_MAIN_MEMORY		0x8000
#define	_EXTENDED_MEMORY	0x4000
#define	_FILE_MEMORY		0x3F00

#define	_UNION_CLASS		0x0004
#define	_VIRTUAL_CLASS		0x0010
#define _STATIC_CLASS		0x0020
#define	_AUTO_CONSTRUCT		0x0040
#define	_AUTO_DESTRUCT		0x0080
#define _AUTO_CLASS		(_AUTO_CONSTRUCT | _AUTO_DESTRUCT)
#define _AUTO_ARGUMENT		0x0100


/*	------------------------------------------------------  */	
/*	Class Procedure Pointer Table Control Constants		*/
/*	-----------------------------------------------		*/ 
/*	These values are added to "class->status" to indicate	*/
/*	That the various phases have been performed for the	*/
/*	Class : 						*/
/*								*/
/*	EXISTS	Table Source Generation, during initial		*/
/*		instance of this class.				*/
/*	ALLOC	Table allocation via CREATE during first	*/
/*		implicite construction for an object of this 	*/
/*		Class.						*/
/*	READY	Pointer affectation during the implicite	*/
/*		construction of an object of this class		*/
/*								*/
/*	------------------------------------------------------  */	
#define	_TABLE_ALLOC		0x0200
#define	_TABLE_EXISTS		0x0400
#define	_TABLE_READY 		0x0800
#define	_TABLE_DELETE 		0x1000
#define _TABLE_LOCAL		0x2000
#define _TABLE_CANCEL		0xC1FF
#define _INDIRECT_CLASS		0x4000	/* field ->status	*/
#define	_CLASS_LOCK		0x8000	/* field ->status	*/

#define	_LIBRARY_CLASS		0x4000	/* field ->type		*/


/*	Strict Method Definition Values				*/
/*	-------------------------------				*/
#define	_CHK_NB_PARA		0x0001
#define	_CHK_TYP_PARA		0x0002


/*	Common Member Control Definitions			*/
/*	---------------------------------			*/
#define	_COMMON_DONE		0x0002
#define	_COMMON_LOCAL		0x0004
#define	_COMMON_BASE		0x0008


/*	Function method control values				*/
/*	------------------------------				*/
#define	_FUNCTION_USER		0x8000
#define	_FUNCTION_DONE		0x4000
#define	_FUNCTION_EXTERN	0x0080
#define	_FUNCTION_STATIC	0x0040
#define _FUNCTION_INDIRECT	0x2000

#define	_INHERITED_STATIC	0x0100
#define	_FUNCTION_STATIC_I	0x0200	

#define	_ACCESS_PUBLIC 		0x0000
#define	_ACCESS_PRIVATE		0x0001
#define	_ACCESS_PROTECT		0x0002
#define	_OBJECT_CONSTRUIT	0x0040
#define	_OBJECT_DETRUIT		0x0080
#define	_OBJECT_EXTERN		0x0001
#define	_OBJECT_COMMON		0x0002

/*	Explicite Object instance pointer 	*/
/*	---------------------------------	*/
#define _OBJECT_POINTER		0x8000
#define	_OBJECT_OVERLAY		0x4000

#define SIZEOF_POINTER 5

#ifdef	STRUCTC

/*	Declaration of structure and class management variables		*/
/*	-------------------------------------------------------		*/
HASHCLASS	HashClass[HASH_CLASS ];	/* Hash list for classes	*/
HASHOBJECT	HashObject[HASH_OBJECT];/* Hash list for Objects	*/
CLASSPTR 	ClassBase;	/* Root pointer for class management	*/
CLASSPTR 	ClassProto;	/* Root pointer for class Prototypes	*/
OBJECTPTR	ObjectHeap;	/* Root pointer for Object management	*/
MEMBERPTR	CommonHeap;	/* List of common variables		*/
MEMBERPTR	FunctionHeap;	/* List of Method function Procedures	*/
AUTOPTR	 	AutoConstruct;	/* Objects requiring construction	*/
AUTOPTR		AutoDestruct;	/* List of Objects with destructors 	*/
GOSUBPTR	GosubHeap;	/* List of inline methods as gosubs	*/
GOSUBPTR	GosubStack;	/* List of Allocated Gosub Buffers	*/

	/* --------- */
#else	/* ! STRUCTC */
	/* --------- */

EXTERN CLASSPTR  ClassBase;	/* Root pointer for class management	*/
EXTERN OBJECTPTR ObjectHeap;	/* Root pointer for Object management	*/
EXTERN MEMBERPTR CommonHeap;	/* List of common variables		*/
EXTERN MEMBERPTR FunctionHeap;	/* List of Method function Procedures	*/
EXTERN AUTOPTR   AutoConstruct;	/* Objects requiring construction	*/
EXTERN AUTOPTR	 AutoDestruct;	/* List of Objects with destructors 	*/
EXTERN GOSUBPTR	 GosubHeap;	/* List of inline methods as gosubs	*/
EXTERN GOSUBPTR	 GosubStack;	/* List of Allocated Gosub Buffers	*/

	/* ------- */
#endif	/* STRUCTC */
	/* ------- */

/*	Globally visible structure manipulation function prototypes	*/
/*	-----------------------------------------------------------	*/
#ifndef CHECK_PROTO_ARGS
void		initialise_structures();
void		liberate_structures();
CLASSPTR	is_class();
OBJECTPTR	is_object();
#else
void		initialise_structures( void );
void		liberate_structures( void );
CLASSPTR	is_class( BPTR );
OBJECTPTR	is_object( BPTR );
#endif

#ifndef STRUCTC

#ifdef CHECK_PROTO_ARGS
WORD		start_struct( WORD );
WORD		end_struct( VOID );
WORD		create_class_member( BPTR ,WORD, WORD );
WORD		declare_class_structure( CLASSPTR, WORD );
WORD		inherit_class_structure( CLASSPTR, WORD );
WORD		generate_structure_member( OBJECTPTR );
CCONSTPTR	is_class_constant( BPTR );
MEMBERPTR	resolve_member_linkage( MEMBERPTR, MEMBERPTR XPTR );
#else
WORD		start_struct();
WORD		end_struct();
WORD		create_class_member();
WORD		declare_class_structure();
WORD		inherit_class_structure();
WORD		generate_structure_member();
CCONSTPTR	is_class_constant();
MEMBERPTR	resolve_member_linkage();
#endif

#endif	/* ! STRUCTC */
	/* --------- */

#endif	/* STRUCTH */
	/* ------- */
