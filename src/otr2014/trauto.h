#ifndef	_TRAUTO_H
#define	_TRAUTO_H

#define	_AUTO_CONSTRUCTION 	0x0001
#define	_AUTO_DESTRUCTION 	0x0002
#define	_AUTO_EXPLICITE		0x0004
#define	_AUTO_ALLOCATE 		0x0008

#define	INSTANCENODE		struct otr_auto_instance XPTR
#define	MEMBERNODE		struct otr_auto_member   XPTR
#define	INDIRECTNODE		struct otr_auto_indirect XPTR

#define	TCMBAUTOPTR		struct tcode_auto_method  XPTR
#define	TCAUTOPTR		struct tcode_auto_pending XPTR

#define	_INVALID_MEMBER		0x0000
#define	_AUTO_DIRECT		0x0001
#define	_AUTO_INDIRECT		0x0002
#define	_AUTO_INSTANCE		0x0080

struct	otr_auto_member	{
	WORD		Nature;
	WORD		Event;
	MEMBERNODE	PreviousMember;
	INSTANCENODE	Instance;
	TCMBAUTOPTR    	Method;
	MEMBERNODE	NextMember;
	};

#define	_INVALID_INSTANCE	0x0000
#define	_EMBEDED_INSTANCE	0x0001
#define	_POINTER_INSTANCE	0x0002
#define	_INDIRECT_INSTANCE	0x0004
#define	_BASE_INSTANCE		0x0008

struct	otr_auto_instance	{
	WORD		Nature;
	WORD		Label;
	WORD		Event;
	TCVARPTR	Instance;
	TCVARPTR	InstanceImt;
	TCVARPTR	InstanceOdc;
	INSTANCENODE	PreviousInstance;
	INSTANCENODE	BaseConstruction;
	MEMBERNODE  	IndirectConstruction;
	MEMBERNODE	MemberConstruction;
	MEMBERNODE	MemberDestruction;
	INSTANCENODE	BaseDestruction;
	INSTANCENODE	NextInstance;
	};

struct	tcode_auto_method	{
	TCVARPTR	world;
	TCVARPTR	object;
	TCMEMBERPTR	member;
	TCMBMETHPTR	method;
	TCTEXTPTR	value;
	TCMBAUTOPTR	next;
	};

struct	tcode_auto_pending	{

	WORD		Construction;		/* Construction Underway */
	WORD		Destruction;		/* Destruction  Underway */
	WORD		Identity;		/* Current Context ID	 */
	TCAUTOPTR	Next;			/* Next Pending Context	 */

	/* Enhanced Construction : OFF */
	/* --------------------------- */
	TCMBAUTOPTR	ConstructionHeap;
	TCMBAUTOPTR	DestructionHeap;
	TCMBAUTOPTR	ConstructorHeap;
	TCMBAUTOPTR	DestructorHeap;
	TCMBAUTOPTR	ExpliciteIndirect;
	TCMBAUTOPTR	ImpliciteIndirect;

	/* Enhanced Construction : ON  */
	/* --------------------------  */
	WORD		Constructors;
	WORD		Destructors;
	INSTANCENODE	ImpliciteConstruction;
	INSTANCENODE	ImpliciteDestruction;
	INSTANCENODE	ExpliciteConstruction;
	INSTANCENODE	ExpliciteDestruction;
	INSTANCENODE	CurrentInstance;
	WORD		Explicite;
	EXCEPTIONPTR	Exception;

	TCVARPTR	Catcher;
	TCVARPTR	Router;
	WORD		ExceptionEntry;
	WORD		ExceptionLevel;
	WORD		ExceptionLimit;
	WORD		ExceptionLabel;
	WORD		ExceptionCatch;

	};


VOID	set_enhanced_construction( WORD );
WORD	local_instance_manager( VOID );
VOID	drop_local_instance( VOID );
WORD	initialise_auto_context( VOID );
VOID	terminate_auto_context( VOID );
WORD	start_instance_construction( TCVARPTR, WORD );
WORD	terminate_instance_construction( TCVARPTR, WORD );
WORD	start_member_construction( TCVARPTR, TCMEMBERPTR );
WORD	instance_method_node( TCMBAUTOPTR, WORD );
WORD	member_instance_node( INSTANCENODE );
WORD	base_instance_node( INSTANCENODE );
WORD	terminate_member_construction( VOID );
WORD	add_construction_method( TCVARPTR, TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, TCTEXTPTR, WORD );
WORD	add_destruction_method( TCVARPTR, TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, TCTEXTPTR, WORD );
WORD	add_indirect_construction( TCVARPTR, TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, WORD );
WORD	detect_auto_method( TCVARPTR, TCVARPTR, TCMEMBERPTR, TCMBMETHPTR, TCTEXTPTR, WORD, WORD );
WORD	flush_indirect_construction( TCMBAUTOPTR, TCMBAUTOPTR XPTR );
WORD	flush_constructors( VOID );
WORD	flush_destructors( VOID );
WORD	flush_explicite_destructors( VOID );
WORD	flush_explicite_constructors( VOID );
WORD	allow_construction( VOID );
WORD	generate_exception_abort( VOID );
WORD	verify_destruction_abort( VOID );
WORD	flush_exception_handler( WORD );
WORD	flush_exception_catcher( WORD );
WORD	flush_destruction_router( WORD );
WORD	perform_destruction( WORD );
WORD	generate_gosub_destruction( VOID );
WORD	ensure_destruction( WORD );
WORD	detect_destruction( VOID );


#ifdef	_TRMETHOD_C

#ifndef	UNIX

static	WORD		set_exception_handler( EXCEPTIONPTR );
static	WORD		validate_exception_router(WORD,WORD);
static	TCAUTOPTR	liberate_auto_context( TCAUTOPTR );
static	TCMBAUTOPTR	liberate_auto_method( TCMBAUTOPTR );
static	INSTANCENODE	liberate_instance_list( INSTANCENODE );
static	INSTANCENODE	liberate_instance_node( INSTANCENODE );
static	MEMBERNODE	liberate_member_list( MEMBERNODE );
static	MEMBERNODE	liberate_member_node( MEMBERNODE );
static	WORD		liberate_indirect_object( TCVARPTR );
static	WORD		allocate_indirect_object( TCVARPTR );
static	WORD		activate_indirect_constructor( TCMBAUTOPTR );
static 	WORD		activate_constructor( TCMBAUTOPTR );
static 	WORD		activate_destructor( TCMBAUTOPTR );
static	WORD		replay_instance_construction( INSTANCENODE,WORD );
static	WORD		replay_instance_destruction( INSTANCENODE,WORD );
static	TCMBAUTOPTR	allocate_auto_method(VOID);
static	TCAUTOPTR	allocate_auto_context(VOID);


#else

	WORD		local_instance_manager();
	VOID		drop_local_instance();
	TCSTRUCTPTR	base_class_componant();
	TCVARPTR	instance_exception_variable();
	RESULTPTR	ensure_register();

static	WORD		set_exception_handler();
static	WORD		validate_exception_router();
static	TCAUTOPTR	liberate_auto_context();
static	TCMBAUTOPTR	liberate_auto_method();
static	INSTANCENODE	liberate_instance_list();
static	INSTANCENODE	liberate_instance_node();
static	MEMBERNODE	liberate_member_list();
static	MEMBERNODE	liberate_member_node();
static	WORD		liberate_indirect_object();
static	WORD		allocate_indirect_object();
static	WORD		activate_indirect_constructor();
static 	WORD		activate_constructor();
static 	WORD		activate_destructor();
static	WORD		replay_instance_construction();
static	WORD		replay_instance_destruction();
static	TCMBAUTOPTR	allocate_auto_method();
static	TCAUTOPTR	allocate_auto_context();

#endif

/*	The Current Construction/Destruction Instance Context	*/
/*	-----------------------------------------------------	*/
	TCAUTOPTR	AutoContext=(TCAUTOPTR) 0;

/*	The quick allocation heap for auto method nodes		*/
/*	-----------------------------------------------		*/
static	TCMBAUTOPTR	AutoMethodHeap=(TCMBAUTOPTR) 0;

/*	The quick allocation heap for auto context nodes	*/
/*	-----------------------------------------------		*/
static	TCAUTOPTR	AutoContextHeap=(TCAUTOPTR) 0;

/*	The quick allocation heap for auto member nodes		*/
/*	-----------------------------------------------		*/
static	MEMBERNODE 	AutoMemberHeap=(MEMBERNODE) 0;

/*	The quick allocation heap for auto instance nodes	*/
/*	------------------------------------------------	*/
static	INSTANCENODE	AutoInstanceHeap=(INSTANCENODE) 0;


/* 	Enhanced Construction Variables (will be incorperated)	*/
/*	------------------------------------------------------	*/ 
static	WORD		EnhancedConstruction=VRAI;

#endif	/* _TRMETHOD_C */
	/* ----------- */

#endif	/* _TRAUTO_H */
	/* --------- */




