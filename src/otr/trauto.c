#ifndef	_TRAUTO_C
#define	_TRAUTO_C

#undef  DEBUG_TRACE_ACTIVED
#undef 	_QUALIFY_AUTO_ALLOCATIOND
#ifdef	_QUALIFY_AUTO_ALLOCATION
static	WORD	NombreIn=0;
static	WORD	NombreMn=0;
static	WORD	NombreCn=0;
static	WORD	NombreAn=0;
#endif

static	WORD	AutoIdentity=0;

WORD	allow_error_trapping();

/*	-------------------------	*/
/*	set_enhanced_construction	*/
/*	-------------------------	*/
VOID	set_enhanced_construction( n )
WORD	n;
{
	EnhancedConstruction =n;
	return;
}

/*	--------------------	*/
/*	allocate_auto_method	*/
/*	--------------------	*/
static	TCMBAUTOPTR	allocate_auto_method()
{
	TCMBAUTOPTR	mptr;
	trace("allocate_auto_method(");

	if ((mptr = AutoMethodHeap) != (TCMBAUTOPTR) 0)
		AutoMethodHeap = mptr->next;

	else if ((mptr = (TCMBAUTOPTR) allocate( sizeof(struct tcode_auto_method) )) == (TCMBAUTOPTR) 0)
		return( mptr );

#ifdef	_QUALIFY_AUTO_ALLOCATION
	else	 ++NombreAn;
#endif
	
	mptr->world  = (TCVARPTR) 0;
	mptr->object = (TCVARPTR) 0;
	mptr->member = (TCMEMBERPTR) 0;
	mptr->method = (TCMBMETHPTR) 0;
	mptr->value  = (TCTEXTPTR) 0;
	mptr->next   = (TCMBAUTOPTR) 0;

	return( mptr );
}

/*	---------------------	*/
/*	allocate_auto_context	*/
/*	---------------------	*/
static	TCAUTOPTR	allocate_auto_context()
{
	TCAUTOPTR	aptr;

	if ((aptr = AutoContextHeap) != (TCAUTOPTR) 0)
		AutoContextHeap = aptr->Next;

	else if ((aptr = (TCAUTOPTR) allocate( sizeof( struct tcode_auto_pending ) )) == (TCAUTOPTR) 0)
		return( aptr );
#ifdef	_QUALIFY_AUTO_ALLOCATION
	else	++NombreCn;
#endif
	/* STANDARD CONSTRUCTION MANAGEMENT */
	/* -------------------------------- */
	aptr->ConstructionHeap	  = (TCMBAUTOPTR) 0;
	aptr->DestructionHeap	  = (TCMBAUTOPTR) 0;
	aptr->ConstructorHeap	  = (TCMBAUTOPTR) 0;
	aptr->DestructorHeap	  = (TCMBAUTOPTR) 0;
	aptr->ExpliciteIndirect	  = (TCMBAUTOPTR) 0;
	aptr->ImpliciteIndirect	  = (TCMBAUTOPTR) 0;

	/* ENHANCED CONSTRUCTION MANAGEMENT */
	/* -------------------------------- */
	aptr->Constructors	    = 0;
	aptr->Destructors	    = 0;
	aptr->ImpliciteConstruction = (INSTANCENODE) 0;
	aptr->ImpliciteDestruction  = (INSTANCENODE) 0;
	aptr->ExpliciteConstruction = (INSTANCENODE) 0;
	aptr->ExpliciteDestruction  = (INSTANCENODE) 0;
	aptr->CurrentInstance 	    = (INSTANCENODE) 0;
	aptr->ExceptionLevel 	    = 1;
	aptr->ExceptionEntry 	    = 1;
	aptr->ExceptionLimit 	    = 1;
	aptr->ExceptionLabel 	    = MOINS_UN;
	aptr->ExceptionCatch 	    = MOINS_UN;
	aptr->Catcher		    = (TCVARPTR) 0;
	aptr->Router 		    = (TCVARPTR) 0;
	aptr->Explicite		    = FAUX;
	aptr->Exception		    = (EXCEPTIONPTR) 0;
	aptr->Construction	  = FAUX;
	aptr->Destruction	  = FAUX;
	aptr->Identity		  = ++AutoIdentity;
	aptr->Next 		  = (TCAUTOPTR) 0;
	return( aptr );
}

/*	---------------------------------------------------	*/
/*			local_instance_manager			*/
/*	---------------------------------------------------	*/
/*	Called from TRLOCAL.initialise_method_local		*/
/*	when entering an new local variable environment when 	*/
/*								*/
/*		#PRAGMA ENHANCED LOCAL ON 			*/
/*								*/
/*	---------------------------------------------------	*/

WORD	local_instance_manager()
{
	TCAUTOPTR	aptr;
	if ((aptr = allocate_auto_context()) == (TCAUTOPTR) 0)
		return( allocation_failure() );
	else	
	{
		aptr->Next     = AutoContext;
		AutoContext = aptr;
		return(0);
	}
}

/*	-------------------	*/
/*	drop_local_instance	*/
/*	-------------------	*/
VOID	drop_local_instance()
{
	TCAUTOPTR	aptr;
	if ((aptr = AutoContext) != (TCAUTOPTR) 0) 
	{
		AutoContext = aptr->Next;
		aptr = liberate_auto_context( aptr );
	}
	return;
}

/*	----------------------------------------------------------	*/
/*			initialise_auto_context				*/
/*	----------------------------------------------------------	*/
/*	Called from TABLES.initialise_tcode_context to prepare for	*/
/*	construction/destruction operation collection for the 		*/
/*	global context.							*/
/*	----------------------------------------------------------	*/

WORD		initialise_auto_context()
{
	trace("initialise_auto_context()");
	if ((AutoContext = allocate_auto_context()) == (TCAUTOPTR) 0)
		return( allocation_failure() );
	else	return( 0 );
}

/*	-------------------------	*/
/*	liberate_for_auto_context	*/
/*	-------------------------	*/
static	TCAUTOPTR	liberate_for_auto_context(aptr)
TCAUTOPTR	aptr;
{
	if ( aptr != (TCAUTOPTR) 0) {
		aptr->Next = AutoContextHeap;
		AutoContextHeap = aptr;
		}
	return((TCAUTOPTR) 0);
}

/*	---------------------	*/
/*	liberate_auto_context	*/
/*	---------------------	*/
static	TCAUTOPTR	liberate_auto_context( aptr )
TCAUTOPTR		aptr;
{
	if ( aptr == (TCAUTOPTR) 0)
		return( aptr );

	if ( EnhancedConstruction ) 
	{
		aptr->ImpliciteConstruction = liberate_instance_list( aptr->ImpliciteConstruction );
		aptr->ImpliciteDestruction  = (INSTANCENODE) 0;
		aptr->ExpliciteConstruction = liberate_instance_list( aptr->ExpliciteConstruction );
		aptr->ExpliciteDestruction  = (INSTANCENODE) 0;
		aptr->CurrentInstance 	    = liberate_instance_list( aptr->CurrentInstance );
	}

	return( liberate_for_auto_context( aptr ) );
}

/*	----------------------	*/
/*	terminate_auto_context	*/
/*	----------------------	*/
VOID		terminate_auto_context()
{
	TCAUTOPTR	aptr;
	TCMBAUTOPTR	bptr;
	INSTANCENODE	iptr;
	MEMBERNODE	mptr;

#ifdef	_QUALIFY_AUTO_ALLOCATION
	sysprintf("terminate_auto_context() {\n");
	sysprintf("\tAllocations : \n");
	sysprintf("\t\tAutoContextHeap   : %u\n",NombreCn);
	sysprintf("\t\tAutoInstanceHeap  : %u\n",NombreIn);
	sysprintf("\t\tAutoMemberHeap    : %u\n",NombreMn);
	sysprintf("\t\tAutoMethodHeap    : %u\n",NombreAn);
#endif

	while ((aptr = AutoContext) != (TCAUTOPTR) 0) 
	{
		AutoContext = aptr->Next;
		aptr = liberate_auto_context( aptr );
	}

	while ((aptr = AutoContextHeap) != (TCAUTOPTR) 0) 
	{
		AutoContextHeap = aptr->Next;
#ifdef	_QUALIFY_AUTO_ALLOCATION
		if ( NombreCn )
			NombreCn--;
#endif
		liberate( aptr );
	}

	while ((iptr = AutoInstanceHeap) != (INSTANCENODE) 0) 
	{
		AutoInstanceHeap = iptr->NextInstance;
#ifdef	_QUALIFY_AUTO_ALLOCATION
		if ( NombreIn )
			NombreIn--;
#endif
		liberate( iptr );
	}

	while ((mptr = AutoMemberHeap) != (MEMBERNODE) 0) 
	{
		AutoMemberHeap = mptr->NextMember;
#ifdef	_QUALIFY_AUTO_ALLOCATION
		if ( NombreMn )
			NombreMn--;
#endif
		liberate( mptr );
	}

	while ((bptr = AutoMethodHeap) != (TCMBAUTOPTR) 0) 
	{
		AutoMethodHeap = bptr->next;
#ifdef	_QUALIFY_AUTO_ALLOCATION
		if ( NombreAn )
			NombreAn--;
#endif
		liberate( bptr );
	}

#ifdef	_QUALIFY_AUTO_ALLOCATION
	sysprintf("\tRemaining   : \n");
	sysprintf("\t\tAutoContextHeap   : %u\n",NombreCn);
	sysprintf("\t\tAutoInstanceHeap  : %u\n",NombreIn);
	sysprintf("\t\tAutoMemberHeap    : %u\n",NombreMn);
	sysprintf("\t\tAutoMethodHeap    : %u\n",NombreAn);
	sysprintf("\t}\n");
#endif
	return;
} 

/*	--------------------	*/
/*	liberate_auto_method	*/
/*	--------------------	*/
static 	TCMBAUTOPTR	liberate_auto_method( mptr )
TCMBAUTOPTR		mptr;
{
	if ( mptr != (TCMBAUTOPTR) 0) 
	{
		if ( mptr->value != (TCTEXTPTR) 0)
			liberate_text_value( mptr->value );
		mptr->next = AutoMethodHeap;
		AutoMethodHeap = mptr;
	}
	return((TCMBAUTOPTR) 0);
}

/*	--------------------	*/
/*	allocate_member_node	*/
/*	--------------------	*/
static	MEMBERNODE	allocate_member_node()
{
	MEMBERNODE	nptr;

	if ((nptr = AutoMemberHeap) != (MEMBERNODE) 0)
		AutoMemberHeap = nptr->NextMember;

	else if ((nptr = (MEMBERNODE) allocate( sizeof ( struct otr_auto_member ) )) == (MEMBERNODE) 0)
		return( nptr );

#ifdef	_QUALIFY_AUTO_ALLOCATION
	else	++NombreMn;
#endif

	nptr->Nature			= _INVALID_MEMBER;
	nptr->Method			= (TCMBAUTOPTR) 0;
	nptr->Event			= MOINS_UN;
	nptr->Instance			= (INSTANCENODE) 0;
	nptr->NextMember		= (MEMBERNODE) 0;
	nptr->PreviousMember		= (MEMBERNODE) 0;

	return( nptr );
}

/*	------------------------	*/
/*	liberate_for_member_node	*/
/*	------------------------	*/
static	MEMBERNODE	liberate_for_member_node( iptr )
MEMBERNODE	iptr;
{
	iptr->NextMember = AutoMemberHeap;
	AutoMemberHeap   = iptr;
	return((MEMBERNODE) 0);
}

/*	--------------------	*/
/*	liberate_member_node	*/
/*	--------------------	*/
static	MEMBERNODE	liberate_member_node( iptr )
MEMBERNODE	iptr;
{
	if ( iptr != (MEMBERNODE) 0 ) 
	{
		if ( iptr->Nature & _AUTO_INSTANCE )
			iptr->Instance = liberate_instance_node( iptr->Instance );
		else	iptr->Method   = liberate_auto_method( iptr->Method );
		iptr = liberate_for_member_node( iptr );
	}
	return( (MEMBERNODE) 0 );
}

/*	--------------------	*/
/*	liberate_member_list	*/
/*	--------------------	*/
static	MEMBERNODE	liberate_member_list( lptr )
MEMBERNODE	lptr;
{
	MEMBERNODE	iptr;
	while (( iptr = lptr) != (MEMBERNODE) 0 ) 
	{
		lptr = lptr->NextMember;
		iptr = liberate_member_node( iptr );
	}
	return( (MEMBERNODE) 0 );
}	

/*	----------------------	*/
/*	allocate_instance_node	*/
/*	----------------------	*/
static	INSTANCENODE	allocate_instance_node()
{
	INSTANCENODE	iptr;

	if ((iptr = AutoInstanceHeap) != (INSTANCENODE) 0)
		AutoInstanceHeap = iptr->NextInstance;

	else if ((iptr = (INSTANCENODE) allocate( sizeof ( struct otr_auto_instance ) )) == (INSTANCENODE) 0)
		return( iptr );

#ifdef	_QUALIFY_AUTO_ALLOCATION
	else	++NombreIn;
#endif

	iptr->Instance			= (TCVARPTR) 0;
	iptr->InstanceImt		= (TCVARPTR) 0;
	iptr->InstanceOdc		= (TCVARPTR) 0;
	iptr->Nature			= _INVALID_INSTANCE;
	iptr->Label			= MOINS_UN;
	iptr->Event			= MOINS_UN;
	iptr->BaseConstruction		= (INSTANCENODE) 0;
	iptr->IndirectConstruction	= (MEMBERNODE) 0;
	iptr->MemberConstruction	= (MEMBERNODE) 0;
	iptr->MemberDestruction		= (MEMBERNODE) 0;
	iptr->BaseDestruction		= (INSTANCENODE) 0;
	iptr->NextInstance		= (INSTANCENODE) 0;
	iptr->PreviousInstance		= (INSTANCENODE) 0;

	return( iptr );
}

/*	--------------------------	*/
/*	liberate_for_instance_node	*/
/*	--------------------------	*/
static	INSTANCENODE	liberate_for_instance_node( iptr )
INSTANCENODE	iptr;
{
	iptr->NextInstance = AutoInstanceHeap;
	AutoInstanceHeap   = iptr;
	return((INSTANCENODE) 0);
}

/*	----------------------	*/
/*	liberate_instance_list	*/
/*	----------------------	*/
static	INSTANCENODE	liberate_instance_list( lptr )
INSTANCENODE	lptr;
{
	INSTANCENODE	iptr;
	while (( iptr = lptr) != (INSTANCENODE) 0 ) {
		lptr = lptr->NextInstance;
		iptr = liberate_instance_node( iptr );
		}
	return( (INSTANCENODE) 0 );
}	

/*	----------------------	*/
/*	liberate_instance_node	*/
/*	----------------------	*/
static	INSTANCENODE	liberate_instance_node( iptr )
INSTANCENODE	iptr;
{
	if ( iptr != (INSTANCENODE) 0 ) 
	{
		iptr->BaseDestruction = 
		iptr->BaseConstruction = 
			liberate_instance_list( iptr->BaseConstruction );
		iptr->IndirectConstruction = 
			liberate_member_list( iptr->IndirectConstruction );
		iptr->MemberDestruction = 
		iptr->MemberConstruction = 
			liberate_member_list( iptr->MemberConstruction );
		liberate_for_instance_node( iptr );
	}
	return( (INSTANCENODE) 0 );
}

/*	---------------------	*/
/*	set_exception_handler	*/
/*	---------------------	*/
static	WORD	set_exception_handler( eptr )
EXCEPTIONPTR	eptr;
{
	if ( EnhancedConstruction )
		AutoContext->Exception = eptr;
	return( 0 );
}

/*	----------------------	*/
/*	drop_exception_handler	*/
/*	----------------------	*/
static	WORD	drop_exception_handler()
{
	if ( EnhancedConstruction )
		AutoContext->Exception = (EXCEPTIONPTR) 0;
	return( 0 );
}

/*	-------------------	*/
/*	instance_tabulation	*/
/*	-------------------	*/
static	VOID	instance_tabulation( n )
WORD	n;
{
	for ( ; n > 0; n-- )
		sysprintf("\t");
	return;
}

/*	---------------------------	*/
/*	destruction_exception_label	*/
/*	---------------------------	*/
static	WORD	destruction_exception_label(level, mode)
WORD		level;
WORD		mode;
{
	BYTE	vlabel[32];
	if (( AutoContext->Explicite )
	||  ( AutoContext->Router == (TCVARPTR) 0 ))
		return( 0 );
	if (( AutoContext->ExceptionLevel != MOINS_UN )
	&&  ( AutoContext->ExceptionLabel != AutoContext->ExceptionLevel )) 
	{
		sprintf(vlabel,"&%s%u",AutoContext->Router->name,AutoContext->ExceptionLevel);
		if ( OtrOption.Verbose & 8 ) 
		{
			instance_tabulation( level );
			sysprintf("%s\n",vlabel);
		}
		(void) add_explicite_label( vlabel );
		AutoContext->ExceptionLabel = AutoContext->ExceptionLevel--;
		if ( mode )
			(void) generate_optimised_sti( AutoContext->Router, AutoContext->ExceptionLevel );
	}
	return(0);
}

/*	------------------------	*/
/*	flush_destruction_labels	*/
/*	------------------------	*/
static	WORD	flush_destruction_labels( level )
WORD	level;
{
	WORD	status=0;
	if ( AutoContext->Explicite )
		return( 0 );
	while ((AutoContext->ExceptionLevel) && ( AutoContext->ExceptionLevel != MOINS_UN ))
		if ((status = destruction_exception_label( level, FAUX )) != 0)
			break;
	return( status );
}

/*	----------------	*/
/*	flush_till_event	*/
/*	----------------	*/
static	WORD	flush_till_event( level, event )
WORD	level;
WORD	event;
{
	WORD	status=0;
	if (( event != MOINS_UN )
	&&  ( AutoContext->ExceptionLevel != MOINS_UN )) 
	{
		while  ((AutoContext->ExceptionLevel)
		&&	(AutoContext->ExceptionLevel != MOINS_UN)
		&&	(event < AutoContext->ExceptionLevel)) 
			if ((status = destruction_exception_label( level, FAUX )) != 0)
				break;
	}
	return( status );
}

/*	-------------------------	*/
/*	validate_exception_router	*/
/*	-------------------------	*/
static	WORD	validate_exception_router(mode,level)
			/* ------------------------------------- */
WORD		mode;	/* VRAI : EXPLICITE LOCAL EXCEPTION 	 */
			/* FAUX : IMPLICITE CONSTRUCTION CATCHER */
			/* ------------------------------------- */
WORD		level;
{
	BYTE		vname[MAX_LABEL_SIZE];
	BPTR		nptr;
	RESULTPTR	rptr;

	if ((AutoContext->Router == (TCVARPTR) 0)
	&&  (( AutoContext->Constructors ) ||  ( mode ))) 
	{
		sprintf(vname,"X%u_ROUTER",AutoContext->Identity);
		if ((nptr = allocate_for_string( vname )) == (BPTR) 0)
			return( allocation_failure() );
		else if ((AutoContext->Router = instance_exception_variable( nptr )) == (TCVARPTR) 0)
			return( syntax_error( 5300 ) );

		sprintf(vname,"X%u_CATCHER",AutoContext->Identity);
		if ((nptr = allocate_for_string( vname )) == (BPTR) 0)
			return( allocation_failure() );
		else if ((AutoContext->Catcher = instance_exception_variable( nptr )) == (TCVARPTR) 0)
			return( syntax_error( 5301 ) );
		else	
		{
			if ( OtrOption.Verbose & 8 ) 
			{
				instance_tabulation( level );
				sysprintf("ON ERROR GOTO &%s,%s\n",AutoContext->Catcher->name,AutoContext->Catcher->name);
			}
			if  (!(rptr = variable_result(AutoContext->Catcher)))
				return( syntax_error( 5302 ) );
			else	return( explicite_on_error( rptr->contents, _CTRL_LOCAL, AutoContext->Catcher->name ) );
		}
	}
	else	return(0);	
}

/*	-----------------------------	*/
/*	construction_exception_router	*/
/*	-----------------------------	*/
static	WORD	construction_exception_router( level, label)
WORD		level;
WORD		label;
{
	WORD	status=0;
	if ( AutoContext->Router != (TCVARPTR) 0) 
	{
		if ( OtrOption.Verbose & 8 ) 
		{
			instance_tabulation( level );
			sysprintf("%s = %u\n",AutoContext->Router->name,label);
		}
		(void) generate_optimised_sti( AutoContext->Router, label );
	}
	return(0);
}

/*	------------------------------	*/
/*	construction_exception_catcher	*/
/*	------------------------------	*/
static	WORD	construction_exception_catcher( level, label)
WORD		level;
WORD		label;
{
	WORD	status=0;
	if ( AutoContext->ExceptionCatch != label ) 
	{
		if ((status = validate_exception_router(FAUX,level)) != 0)
			return( status );
		else if ((status = construction_exception_router( level, label )) != 0)
			return( status );
		AutoContext->ExceptionCatch = label;
	}
	return(status);
}

/*	----------------------------	*/
/*	current_construction_catcher	*/
/*	----------------------------	*/
static	WORD	current_construction_catcher( level )
WORD	level;
{
	if ( AutoContext->Explicite )
		return( 0 );
	if ( AutoContext->ExceptionLevel != MOINS_UN )
		return( construction_exception_catcher( 0, AutoContext->ExceptionLevel ) );
	else	return( 0 );
}

/*	---------------------	*/
/*	raise_exception_level	*/
/*	---------------------	*/
static	VOID	raise_exception_level()
{
	AutoContext->ExceptionLevel++;
	if ( AutoContext->ExceptionLevel > AutoContext->ExceptionLimit )
		AutoContext->ExceptionLimit = AutoContext->ExceptionLevel;
	return;
}

/*	----------------------------	*/
/*	construction_exception_label	*/
/*	----------------------------	*/
static	WORD	construction_exception_label(level)
WORD		level;
{
	WORD	status=0;
	if ( AutoContext->Explicite )
		return( 0 );
	if (( AutoContext->ExceptionLevel != MOINS_UN )
	&& ((status = current_construction_catcher( level )) == 0))
		raise_exception_level();
	return( status );
}

/*	------------------------	*/
/*	start_construction_label	*/
/*	------------------------	*/
static	WORD	start_construction_label( iptr )
INSTANCENODE	iptr;
{
	iptr->Event    	= AutoContext->ExceptionLevel 
			= AutoContext->ExceptionLimit;
	return( 0 );
}

/*	----------------------------	*/
/*	terminate_construction_label	*/
/*	----------------------------	*/
static	WORD	terminate_construction_label( iptr )
INSTANCENODE	iptr;
{
	WORD	status=0;
	status = current_construction_catcher( 0 );
	iptr->Label    = AutoContext->ExceptionLevel;
	return( status );
}

/*	-------------------------	*/
/*	 start_destruction_label	*/
/*	-------------------------	*/
static	WORD	start_destruction_label( iptr )
INSTANCENODE	iptr;
{
	AutoContext->ExceptionLevel = iptr->Label;
	return( 0 );
}

/*	---------------------------	*/
/*	terminate_destruction_label	*/
/*	---------------------------	*/
static	WORD	terminate_destruction_label( iptr )
INSTANCENODE	iptr;
{
	WORD	status=0;
	iptr->Label = MOINS_UN;
	return( status );
}

/*	----------	*/
/*	mark_event	*/
/*	----------	*/
static	WORD	mark_event( mptr )
MEMBERNODE	mptr;
{
	mptr->Event = AutoContext->ExceptionLevel;
	return( 0 );
}

/*	--------------------	*/
/*	replay_direct_method	*/
/*	--------------------	*/
static	WORD	replay_direct_method( mptr, aptr, level, nature )
MEMBERNODE	mptr;
TCMBAUTOPTR	aptr;
WORD		level;
WORD		nature;
{
	TCMBMETHPTR	method;
	BPTR		nptr;
	BPTR		optr;
	WORD		status=0;

	if ((method = aptr->method) != (TCMBMETHPTR) 0) 
	{
		if  (method->special == nature ) 
		{
			if ( nature == _CLASS_DESTRUCTOR ) 
			{
				if ((status = flush_till_event( level, mptr->Event )) != 0)
					return( status );
				else if (( mptr->Event == AutoContext->ExceptionLevel )
				     &&  ((status = destruction_exception_label(level,VRAI)) != 0))
					return( status );
			}
			else if ( nature == _CLASS_CONSTRUCTOR ) 
			{
				if ((status = construction_exception_label(level)) != 0)
					return( status );
			}

			if ( OtrOption.Verbose & 8 ) 
			{
				instance_tabulation( level );
				sysprintf("%s ",get_class_keyword( nature ));
				if (( aptr->member == (TCMEMBERPTR) 0)
				||  ((nptr = aptr->member->name) == (BPTR) 0))
					nptr = "<member>";
				if (( aptr->object == (TCVARPTR) 0)
				||  ((optr = aptr->object->name) == (BPTR) 0))
					optr = "<object>";
				sysprintf("%s( %s )\n",nptr,optr);
			}
			if ( nature == _CLASS_CONSTRUCTOR )
				return( activate_constructor( aptr ) );
			else 	return( activate_destructor( aptr )  );
		}
		else if ( nature == _CLASS_CONSTRUCTOR )
			return( mark_event( mptr ) );
	}
	return(0);
}

/*	----------------------	*/
/*	replay_indirect_method	*/
/*	----------------------	*/
static	WORD	replay_indirect_method( aptr, level )
TCMBAUTOPTR	aptr;
WORD		level;
{
	TCMBMETHPTR	method;
	TCMEMBERPTR	member;
	TCVARPTR	object;
	BPTR		nptr;

	if ((method = aptr->method) != (TCMBMETHPTR) 0) 
	{
	   	if  ((member =  aptr->member) != (TCMEMBERPTR) 0) 
		{
			if ( OtrOption.Verbose & 8 ) 
			{
				if ((nptr = member->name) == (BPTR) 0)
					nptr = (BPTR) "<member>";

				instance_tabulation( level );
				switch ( method->nature ) 
				{
				case _CLASS_FUNCTION :
					sysprintf("%s = PROC PTR %s\n",nptr,nptr);
					break;
				case _CLASS_OVERLAY  :
					sysprintf("%s = SEGM PTR %s\n",nptr,nptr);
					break;
				case _CLASS_USER     :
					sysprintf("%s = USER PTR %s\n",nptr,nptr);
					break;
				}
				if (( method->options & (_METHOD_VIRTUAL | _METHOD_OVERLOAD))
				&&  (( object = aptr->object) != (TCVARPTR) 0)) 
				{
					instance_tabulation( level );
					if ( object->name != (BPTR) 0 )
						sysprintf("%s = ALIAS( %s )\n",nptr,object->name);
					else	sysprintf("%s = ALIAS( <object> )\n",nptr);
				}
			}
		}
	   	return( activate_indirect_constructor( aptr ) );
	}
	return( 0 );
}

/*	--------------------------	*/
/*	replay_member_construction	*/
/*	--------------------------	*/
static	WORD	replay_member_construction( mptr, level )
MEMBERNODE	mptr;
WORD		level;
{
	TCMBAUTOPTR	aptr;
	WORD		status=0;
	if ( mptr != (MEMBERNODE) 0) 
	{
		if ( mptr->Nature & _AUTO_INSTANCE )
			return( replay_instance_construction( mptr->Instance, (level+1) ) );
		else if ((aptr = mptr->Method) != (TCMBAUTOPTR) 0) 
		{
			if ( mptr->Nature == _AUTO_DIRECT )
				return( replay_direct_method( mptr, aptr, level, _CLASS_CONSTRUCTOR ) );
			else	return( replay_indirect_method( aptr, level ) );
		}
	}
	return(status);
}

/*	---------------------	*/
/*	ensure_legal_instance	*/
/*	---------------------	*/
static	WORD	ensure_legal_instance( vptr )
TCVARPTR	vptr;
{
	WORD	s=0;
	if (( vptr == (TCVARPTR) 0)
	||  ( vptr->type == (TCTYPPTR) 0)
	||  ((s = vptr->type->size) == 0 )
	||  (( vptr->type->type & _TYPE_POINTER) != _TYPE_POINTER))
		return( 0 );
	else	return( s );
}

/*	-------------------	*/
/*	instance_allocation	*/
/*	-------------------	*/
static	WORD	instance_allocation( vptr , level )
TCVARPTR	vptr;
WORD		level;
{
	WORD	status=0;
	if (!( ensure_legal_instance( vptr ) ))
		return( 0 );
	if ((status = construction_exception_label(level)) != 0)
		return( status );
	if ( OtrOption.Verbose & 8 ) 
	{
		instance_tabulation( level );
		sysprintf("CREATE %s\n",vptr->name);
	}
	if ((status = allocate_indirect_object( vptr )) != 0)
		return( status );
	else	return( 0 );
}

/*	-------------------	*/
/*	instance_liberation	*/
/*	-------------------	*/
static	WORD	instance_liberation( vptr, eptr, level )
TCVARPTR	vptr;
WPTR		eptr;
WORD		level;
{
	WORD	status=0;
	WORD	event;
	if (!( ensure_legal_instance( vptr ) ))
		return( 0 );
	if (((event = *eptr) != MOINS_UN)
	&&  ( event != 0 )) 
	{
		flush_till_event( level, *eptr );
		if ( event == AutoContext->ExceptionLevel ) 
		{
			if ((status = destruction_exception_label(level,VRAI)) != 0)
				return( status );
		}
		*eptr = (event - 1);
	}
	if ( OtrOption.Verbose & 8 ) 
	{
		instance_tabulation( level );
		sysprintf("REMOVE %s\n",vptr->name);
	}
	if ((status = liberate_indirect_object( vptr )) != 0)
		return( status );
	else	return( 0 );
}

/*	----------------------------	*/
/*	replay_instance_construction	*/
/*	----------------------------	*/
static	WORD	replay_instance_construction( iptr, level )
INSTANCENODE	iptr;
WORD		level;
{
	INSTANCENODE	biptr;
	MEMBERNODE	mptr;
	WORD		status=0;

	if ( iptr != (INSTANCENODE) 0 ) 
	{
		if ( iptr->Nature == _POINTER_INSTANCE )  
		{
			if (( iptr->Instance != (TCVARPTR) 0)
			&&  ((status = instance_allocation( iptr->Instance, level )) != 0))
				return( status );
		}
		else if ( iptr->Nature == _INDIRECT_INSTANCE ) 
		{
			if (( iptr->Instance != (TCVARPTR) 0)
			&&  ((status = instance_allocation( iptr->Instance, level )) != 0))
				return( status );
			if ((iptr->InstanceImt != (TCVARPTR) 0)
			&&  ((status = instance_allocation( iptr->InstanceImt, level )) != 0))
				return( status );
			if ((iptr->InstanceOdc != (TCVARPTR) 0)
			&&  ((status = instance_allocation( iptr->InstanceOdc, level )) != 0))
				return( status );
		}

		iptr->Event = AutoContext->ExceptionLevel;

		if ((biptr = iptr->BaseConstruction) != (INSTANCENODE) 0) 
		{
			do	
			{
				if ((status = replay_instance_construction( biptr, (level+1))) != 0)
					return( status );
			}
			while ((biptr = biptr->NextInstance) != (INSTANCENODE) 0);
		}
		if  ((mptr = iptr->IndirectConstruction) != (MEMBERNODE) 0)
		{
			if ((status = current_construction_catcher( level )) != 0)
				return( status );
			do	
			{
				if ((status = replay_member_construction( mptr, level)) != 0)
					return( status );
			}
			while ((mptr = mptr->NextMember) != (MEMBERNODE) 0);
		}
		if ((mptr = iptr->MemberConstruction) != (MEMBERNODE) 0) 
		{
			do	
			{
				if ((status = replay_member_construction( mptr, level)) != 0)
					return( status );
			}
			while ((mptr = mptr->NextMember) != (MEMBERNODE) 0);
		}
	}
	return( status );
}

/*	-------------------------	*/
/*	replay_member_destruction	*/
/*	-------------------------	*/
static	WORD	replay_member_destruction( mptr, level )
MEMBERNODE	mptr;
WORD		level;
{
	TCMBAUTOPTR	aptr;

	if ( mptr != (MEMBERNODE) 0) 
	{
		if ( mptr->Nature & _AUTO_INSTANCE )
			return( replay_instance_destruction( mptr->Instance, (level+1) ) );
		if ((aptr = mptr->Method) != (TCMBAUTOPTR) 0)
			return( replay_direct_method( mptr, aptr, level, _CLASS_DESTRUCTOR ) );
	}
	return(0);
}

/*	---------------------------	*/
/*	replay_instance_destruction	*/
/*	---------------------------	*/
static	WORD	replay_instance_destruction( iptr, level )
INSTANCENODE	iptr;
WORD		level;
{
	INSTANCENODE	biptr;
	MEMBERNODE	mptr;
	WORD		status=0;

	if ( iptr != (INSTANCENODE) 0 ) 
	{
		if ((mptr = iptr->MemberDestruction) != (MEMBERNODE) 0) 
		{
			do	
			{
				if ((status = replay_member_destruction( mptr, level )) != 0)
					return( status );
			}
			while ((mptr = mptr->PreviousMember) != (MEMBERNODE) 0);
		}
		if ((biptr = iptr->BaseDestruction) != (INSTANCENODE) 0) 
		{
			do	
			{
				if ((status = replay_instance_destruction( biptr, (level+1) )) != 0)
					return( status );
			}
			while ((biptr = biptr->PreviousInstance) != (INSTANCENODE) 0);
		}

		flush_till_event( level, iptr->Event );

		if (( iptr->Nature == _POINTER_INSTANCE )  
		&&  ( iptr->Instance != (TCVARPTR) 0 )
		&&  ( iptr->Instance->type->size != 0   )) 
		{
			if ((status = instance_liberation( iptr->Instance,(WPTR) & iptr->Event, level )) != 0)
				return( status );
		}
		else if ( iptr->Nature == _INDIRECT_INSTANCE ) 
		{
			if ((iptr->InstanceOdc != (TCVARPTR) 0)
			&&  ((status = instance_liberation( iptr->InstanceOdc ,(WPTR) & iptr->Event, level)) != 0))
				return( status );
			if ((iptr->InstanceImt != (TCVARPTR) 0)
			&&  ((status = instance_liberation( iptr->InstanceImt ,(WPTR) & iptr->Event, level)) != 0))
				return( status );
			if (( iptr->Instance != (TCVARPTR) 0)
			&&  ((status = instance_liberation( iptr->Instance ,(WPTR) & iptr->Event, level)) != 0))
				return( status );
		}
	}
	return(status);
}

/*	---------------------------	*/
/*	start_instance_construction	*/
/*	---------------------------	*/
WORD		start_instance_construction( object, nature )
TCVARPTR	object;
WORD		nature;
{
	INSTANCENODE	iptr;

	/* #PRAGMA ENHANCED CONSTRUCTION ON */
	/* -------------------------------- */
	if ( EnhancedConstruction ) 
	{
		if ((iptr = allocate_instance_node()) != (INSTANCENODE) 0) 
		{
			iptr->Instance = object;
			if (( nature == _KW1_OBJ ) 
			||  ( nature == _KW1_CMN ))
				iptr->Nature   = _POINTER_INSTANCE;
			else if ( nature == _KW1_IND ) 
			{
				iptr->Nature   = _INDIRECT_INSTANCE;
				iptr->Instance = (TCVARPTR) 0;
			}
			else	iptr->Nature   = _EMBEDED_INSTANCE;
			iptr->PreviousInstance = AutoContext->CurrentInstance;
			AutoContext->CurrentInstance = iptr;
			AutoContext->ExceptionLevel = 0;
			return(0);
		}
		else	return( allocation_failure() );	
	}
	else	return(MOINS_UN);
}

/*	---------------------------------	*/
/*	 terminate_instance_construction	*/
/*	---------------------------------	*/
WORD		terminate_instance_construction( object, mode )
TCVARPTR	object;
WORD		mode;
{
	INSTANCENODE	iptr;

	/* -------------------------------- */
	/* #PRAGMA ENHANCED CONSTRUCTION ON */
	/* -------------------------------- */
	if ( EnhancedConstruction ) 
	{
		if ((iptr = AutoContext->CurrentInstance) == (INSTANCENODE) 0) 
			return( internal_error( 5300 ) );
		else	
		{
			AutoContext->CurrentInstance = iptr->PreviousInstance;
			iptr->PreviousInstance = (INSTANCENODE) 0;

			if (( iptr->BaseConstruction == (INSTANCENODE) 0 )
			&&  ( iptr->IndirectConstruction == (MEMBERNODE) 0)
			&&  ( iptr->MemberConstruction == (MEMBERNODE) 0)
			&&  ( iptr->Nature == _EMBEDED_INSTANCE )) 
			{
				iptr = liberate_instance_node( iptr );
				return( 0 );
			}

			if ( mode ) 
			{
				if ( AutoContext->ImpliciteConstruction == (INSTANCENODE) 0 )
					AutoContext->ImpliciteConstruction = iptr;
				if ( AutoContext->ImpliciteDestruction != (INSTANCENODE) 0 ) 
				{
					AutoContext->ImpliciteDestruction->NextInstance = iptr;
					iptr->PreviousInstance = AutoContext->ImpliciteDestruction;
				}
				AutoContext->ImpliciteDestruction = iptr;
				if ( ensure_legal_instance( iptr->Instance ) ) 
				{
					AutoContext->Constructors++;
					AutoContext->Destructors++;
				}
			}
			else	
			{
				if ( AutoContext->ExpliciteConstruction == (INSTANCENODE) 0 )
					AutoContext->ExpliciteConstruction = iptr;
				if ( AutoContext->ExpliciteDestruction != (INSTANCENODE) 0 ) 
				{
					AutoContext->ExpliciteDestruction->NextInstance = iptr;
					iptr->PreviousInstance = AutoContext->ExpliciteDestruction;
				}
				AutoContext->ExpliciteDestruction = iptr;
			}
		}
	}
	return(0);
}

/*	-------------------------	*/
/*	start_member_construction	*/
/*	-------------------------	*/
WORD		start_member_construction( object, member )
TCVARPTR	object;
TCMEMBERPTR	member;
{
	INSTANCENODE	iptr;
	TCSTRUCTPTR	sptr;

	/* -------------------------------- */
	/* #PRAGMA ENHANCED CONSTRUCTION ON */
	/* -------------------------------- */
	if ( EnhancedConstruction ) 
	{
		if ((iptr = allocate_instance_node()) != (INSTANCENODE) 0) 
		{
			iptr->Instance = object;
			if ((sptr = base_class_componant( member )) != (TCSTRUCTPTR) 0) 
			{
				if ( member->nature != _KW1_IND )
					iptr->Nature = ( _EMBEDED_INSTANCE | _BASE_INSTANCE );
				else	
				{
					iptr->Nature = ( _INDIRECT_INSTANCE | _BASE_INSTANCE );
					iptr->Instance = (TCVARPTR) 0;
				}
			}
			else	
			{
				if ( member->nature != _KW1_IND )
					iptr->Nature   = (_AUTO_INSTANCE | _EMBEDED_INSTANCE);
				else	
				{
					iptr->Nature   = (_AUTO_INSTANCE | _INDIRECT_INSTANCE);
					iptr->Instance = (TCVARPTR) 0;
				}
			}	
			iptr->PreviousInstance = AutoContext->CurrentInstance;
			AutoContext->CurrentInstance = iptr;
		}
		else	return( allocation_failure() );	
	}
	return( 0 );
}

/*	------------------	*/
/*	direct_member_node	*/
/*	------------------	*/
static		WORD	direct_member_node( iptr, nptr, nature )
INSTANCENODE	iptr;
MEMBERNODE	nptr;
WORD		nature;
{
	MEMBERNODE	cptr;

	nptr->Nature = nature;

	if (iptr->MemberConstruction == (MEMBERNODE) 0) 
		iptr->MemberConstruction = nptr;
	if ((cptr = iptr->MemberDestruction) != (MEMBERNODE) 0) 
	{
		nptr->PreviousMember = cptr;
		cptr->NextMember     = nptr;
	}
	iptr->MemberDestruction = nptr;
	return(0);
}

/*	--------------------	*/
/*	indirect_member_node	*/
/*	--------------------	*/
static		WORD	indirect_member_node( iptr, nptr )
INSTANCENODE	iptr;
MEMBERNODE	nptr;
{
	MEMBERNODE	cptr;

	nptr->Nature = _AUTO_INDIRECT;

	if ((cptr = iptr->IndirectConstruction) == (MEMBERNODE) 0)
		iptr->IndirectConstruction = nptr;
	else	
	{
		while ( cptr->NextMember != (MEMBERNODE) 0)
			cptr = cptr->NextMember;
		cptr->NextMember     = nptr;
	}
	return(0);
}

/*	--------------------	*/
/*	instance_method_node	*/
/*	--------------------	*/
WORD		instance_method_node( mptr, mode )
TCMBAUTOPTR	mptr;
WORD		mode;
{

	MEMBERNODE	nptr;
	INSTANCENODE	iptr;

	if (!( EnhancedConstruction ))
		return( MOINS_UN );
	else	
	{
		if ((iptr = AutoContext->CurrentInstance) == (INSTANCENODE) 0) 
		{
			return( internal_error( 5301 ) );
		}
		if ( mode & _AUTO_ALLOCATE ) 
		{
			if (( mptr->method == (TCMBMETHPTR) 0) 
			&&  ( mptr->member == (TCMEMBERPTR) 0)) 
			{
				if ( iptr->Instance == (TCVARPTR) 0)
					iptr->Instance = mptr->world;
				else if ( iptr->InstanceImt == (TCVARPTR) 0)
					iptr->InstanceImt = mptr->world;
				else if ( iptr->InstanceOdc == (TCVARPTR) 0)
					iptr->InstanceOdc = mptr->world;
				mptr = liberate_auto_method( mptr );
				return( 0 );
			}
		}

		if ((nptr = allocate_member_node()) == (MEMBERNODE) 0)
			return( allocation_failure() );

		nptr->Method = mptr;

		if (!( mode & _AUTO_EXPLICITE )) 
		{
			if ( mode & _AUTO_CONSTRUCTION ) 
			{
				AutoContext->Constructors++;
			}
			else if ( mode & _AUTO_DESTRUCTION ) 
			{
				AutoContext->Destructors++;
			}
		}

		if ( mode & _AUTO_ALLOCATE )
			return( indirect_member_node(iptr, nptr ) );
		else	return( direct_member_node(iptr, nptr, _AUTO_DIRECT ) );

	}
}

/*	--------------------	*/
/*	member_instance_node	*/
/*	--------------------	*/
WORD		member_instance_node( mptr )
INSTANCENODE	mptr;
{
	INSTANCENODE	iptr;
	MEMBERNODE	nptr;

	if ((iptr = AutoContext->CurrentInstance) == (INSTANCENODE) 0)
		return( 0 );
	else if ((nptr = allocate_member_node()) == (MEMBERNODE) 0)
		return( allocation_failure() );

	mptr->Nature   &= ~_AUTO_INSTANCE;
	nptr->Instance = mptr;

	return( direct_member_node(iptr, nptr, _AUTO_INSTANCE ) );
}

/*	------------------	*/
/*	base_instance_node	*/
/*	------------------	*/
WORD	base_instance_node( bptr )
INSTANCENODE	bptr;
{
	INSTANCENODE	iptr;
	INSTANCENODE	cptr;
	
	if ((iptr = AutoContext->CurrentInstance) != (INSTANCENODE) 0) 
	{
		bptr->Nature &= ~_BASE_INSTANCE;
		bptr->PreviousInstance = (INSTANCENODE) 0;
		if ( iptr->BaseConstruction == (INSTANCENODE) 0)
			iptr->BaseConstruction = bptr;
		if ((cptr = iptr->BaseDestruction) != (INSTANCENODE) 0) 
		{
			bptr->PreviousInstance = cptr;
			cptr->NextInstance = bptr;
		}
		iptr->BaseDestruction = bptr;
		bptr->NextInstance = (INSTANCENODE) 0;
	}
	return( 0 );
}

/*	-----------------------------	*/
/*	terminate_member_construction	*/
/*	-----------------------------	*/
WORD	terminate_member_construction()
{
	INSTANCENODE	iptr;

	/* -------------------------------- */
	/* #PRAGMA ENHANCED CONSTRUCTION ON */
	/* -------------------------------- */
	if ( EnhancedConstruction ) 
	{
		if ((iptr = AutoContext->CurrentInstance) != (INSTANCENODE) 0) 
		{
			AutoContext->CurrentInstance = iptr->PreviousInstance;
			iptr->PreviousInstance = (INSTANCENODE) 0;
			if (!( iptr->Nature & _BASE_INSTANCE ))
				return( member_instance_node( iptr ) );
			else	return( base_instance_node( iptr ) );
		}
	}
	return(0);
}

/*	-------------------------	*/
/*	 add_construction_method	*/
/*	-------------------------	*/
WORD	add_construction_method( world, object, member, method, valptr, mode )
TCVARPTR	world;
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCTEXTPTR	valptr;
WORD		mode;
{
	TCMBAUTOPTR	mptr;
	TCMBAUTOPTR	wptr;
	TCVARPTR	variables;
	WORD		status=0;

	trace("add_construction_method("); 
	trace(object->name); 
	trace(")\n");

	if ( method->options & _METHOD_STRICT ) 
	{
		variables = explicite_method_parameters( method );
		if (( variables == (TCVARPTR) 0 )
		&&  ( valptr != (TCTEXTPTR) 0 ))
			return( 0 );
		if (( variables != (TCVARPTR) 0 )
		&&  ( valptr == (TCTEXTPTR) 0 ))
			return( 0 );
	}	

	if ((mptr = allocate_auto_method()) == (TCMBAUTOPTR) 0)
		return( allocation_failure() );
	else	
	{
		while  ((world != (TCVARPTR) 0) 
		&&	( world->parent != (TCVARPTR) 0))
			world = world->parent;
		mptr->world  = world;
		while   ((object != (TCVARPTR) 0) 
		&&	 ( object->parent != (TCVARPTR) 0))
			object = object->parent;
		mptr->object = object;
		mptr->member = member;
		mptr->method = method;
		mptr->value  = copy_text_value( valptr );
		mptr->next   = (TCMBAUTOPTR) 0;
		if ((status = instance_method_node(mptr, (mode & ~ _AUTO_DESTRUCTION))) != MOINS_UN)
			return( status );
		status = 0;
		if ( mode & _AUTO_EXPLICITE ) 
		{
			if ((wptr = AutoContext->ConstructorHeap) == (TCMBAUTOPTR) 0)
				AutoContext->ConstructorHeap = mptr;
			else	
			{
				while ( wptr->next != (TCMBAUTOPTR) 0)
					wptr = wptr->next;
				wptr->next = mptr;
			}
		}
		else 	
		{
			if ((wptr = AutoContext->ConstructionHeap) == (TCMBAUTOPTR) 0)
				AutoContext->ConstructionHeap = mptr;
			else	
			{
				while ( wptr->next != (TCMBAUTOPTR) 0)
					wptr = wptr->next;
				wptr->next = mptr;
			}
		}
		return( status );
	}
}

/*	------------------------	*/
/*	 add_destruction_method 	*/
/*	------------------------	*/
WORD	add_destruction_method( world, object,member, method, valptr, mode )
TCVARPTR	world;
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCTEXTPTR	valptr;
WORD		mode;
{
	TCMBAUTOPTR	mptr;
	TCVARPTR	variables;
	WORD		status=0;

	if (( method != (TCMBMETHPTR) 0)
	&&  ( method->options & _METHOD_STRICT )) 
	{
		variables = explicite_method_parameters( method );
		if (( variables == (TCVARPTR) 0 )
		&&  ( valptr != (TCTEXTPTR) 0 ))
			return( 0 );
		if (( variables != (TCVARPTR) 0 )
		&&  ( valptr == (TCTEXTPTR) 0 ))
			return( 0 );
	}	

	if ((mptr = allocate_auto_method()) == (TCMBAUTOPTR) 0)
		return( allocation_failure() );
	else	
	{
		while  ((world != (TCVARPTR) 0) 
		&&	( world->parent != (TCVARPTR) 0))
			world = world->parent;
		mptr->world  = world;
		while   ((object != (TCVARPTR) 0) 
		&&	 ( object->parent != (TCVARPTR) 0))
			object = object->parent;
		mptr->world  = world;
		mptr->object = object;
		mptr->member = member;
		mptr->method = method;
		mptr->value  = copy_text_value( valptr );
		if ((status = instance_method_node(mptr, (mode & ~ _AUTO_CONSTRUCTION) )) != MOINS_UN)
			return( status );
		status = 0;
		if ( mode & _AUTO_EXPLICITE ) 
		{
			mptr->next   = AutoContext->DestructorHeap;
			AutoContext->DestructorHeap = mptr;
		}
		else	
		{
			mptr->next   = AutoContext->DestructionHeap;
			AutoContext->DestructionHeap = mptr;
		}
		return( status );
	}
}

/*	-------------------------	*/
/*	add_indirect_construction	*/
/*	-------------------------	*/
WORD	add_indirect_construction( world, object, member, method, mode )
TCVARPTR	world;
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
WORD		mode;
{
	TCMBAUTOPTR	mptr;
	TCMBAUTOPTR	wptr;
	WORD		status=0;

	if ((mptr = allocate_auto_method()) == (TCMBAUTOPTR) 0)
		return( allocation_failure() );
	else	
	{
		mptr->world  = world;
		mptr->member = member;
		mptr->method = method;
		mptr->object = object;
		mptr->next   = (TCMBAUTOPTR) 0;
		if ((status = instance_method_node(mptr,(mode | _AUTO_ALLOCATE) )) != MOINS_UN) 
			return( status );
		status = 0;
		if ( mode & _AUTO_EXPLICITE ) 
		{
			if ((wptr = AutoContext->ExpliciteIndirect) == (TCMBAUTOPTR) 0)
				AutoContext->ExpliciteIndirect = mptr;
			else	
			{
				while ( wptr->next != (TCMBAUTOPTR) 0)
					wptr = wptr->next;
				wptr->next = mptr;
			}
		}
		else 	
		{
			if ((wptr = AutoContext->ImpliciteIndirect) == (TCMBAUTOPTR) 0)
				AutoContext->ImpliciteIndirect  = mptr;
			else	
			{
				while ( wptr->next != (TCMBAUTOPTR) 0)
					wptr = wptr->next;
				wptr->next = mptr;
			}
		}
		return( status );
	}
}

/*	------------------	*/
/*	detect_auto_method	*/
/*	------------------	*/
WORD	detect_auto_method( world,object, member, method, valptr, mode, allocation )
TCVARPTR	world;
TCVARPTR	object;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
TCTEXTPTR	valptr;
WORD		mode;	/* 1 Construct, 2 Destruct, 3 Both, 4 Immediate */
WORD		allocation;	/* Explicite CREATE:0, ATTACH:1	*/
				/* Implicite MOINS_UN		*/
{
	WORD	status;

	if ( ModuleObject )
		return( 0 );

	if ( world != (TCVARPTR) 0)
		while ( world->parent != (TCVARPTR) 0)
			world = world->parent;

	while ( object->parent != (TCVARPTR) 0)
		object = object->parent;

	switch ( method->special ) 
	{
	case _CLASS_CONSTRUCTOR :
		if (( mode & _AUTO_CONSTRUCTION )
		&&  ((status = add_construction_method( world,object, member, method, valptr, mode )) != 0))
			return( status );
		break;

	case _CLASS_DESTRUCTOR  :
		if (( mode & _AUTO_DESTRUCTION )
		&&  ((status = add_destruction_method( world,object, member, method, valptr, mode )) != 0))
			return( status );
		break;
	}

	/* -------------------------------------------------------- */
	/* Detect IMPLICITE INDIRECT METHODS requiring Construction */
	/* -------------------------------------------------------- */
	if (( method->options & _METHOD_INDIRECT )
	&&  (!( method->options & _METHOD_POINTER ))
	&&  ( allocation != 1 )
	&& ( mode & _AUTO_CONSTRUCTION ))
		return( add_indirect_construction( world, object, member,method, mode ) );
	else	return( 0 );

}

/*	------------------------	*/
/*	allocate_indirect_object	*/
/*	------------------------	*/
static	WORD	allocate_indirect_object( object )
TCVARPTR	object;
{
	RESULTPTR	rptr;
	trace("allocate_indirect_object()\n");
	if ( object == (TCVARPTR) 0)
		return( 0 );
	else if ((rptr = variable_result( object )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else	return( clf_create( rptr ) );
}

/*	------------------------	*/
/*	liberate_indirect_object	*/
/*	------------------------	*/
static	WORD	liberate_indirect_object( object )
TCVARPTR	object;
{
	RESULTPTR	rptr;
	trace("liberate_indirect_object()\n");
	if ( object == (TCVARPTR) 0)
		return( 0 );
	else if ((rptr = variable_result( object )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else	return( clf_remove( rptr ) );
}

/*	 ll_activate_auto_method	*/
/*	-------------------------	*/
static	WORD	ll_activate_auto_method( mptr )
TCMBAUTOPTR	mptr;
{
	TCVARPTR	parameters;
	WORD		status=0;
	WORD		failures=0;
	TCVARPTR	object;
	WORD		option=1;

	if ( mptr != (TCMBAUTOPTR) 0) 
	{
		if (( is_pragma_announce( mptr->method->special ) )
		&&  ((status = generate_announcement( mptr->object,mptr->member )) != 0))
			return( status );

		parameters = explicite_method_parameters( mptr->method );

		if (( mptr->value != (TCTEXTPTR) 0 ) && ( parameters  != (TCVARPTR) 0 )) 
		{
#ifdef	DEBUG_PRE_CONSTR
			if ( mptr->member == (TCMEMBERPTR) 0 )
				trace_value( mptr->value->buffer, "User");
#endif
			if  (((status = establish_value_input( mptr->value->buffer )) != 0)
			||   ((status = continue_translation(0)) != 0 ))
				return( status );
		}	

		object = (TCVARPTR) input_object();

		if ( mptr->member != (TCMEMBERPTR) 0 ) 
		{
			if ( mptr->member->access & _MEMBER_COMMON )
				option = 0;
			establish_input_object( mptr->world );
		}
		else	establish_input_object( mptr->object);

		if ((status = activate_method( mptr->object, mptr->member, mptr->method, (TCMBPARAPTR) 0, 1, option )) == MOINS_UN) 
		{
			if ( mptr->member == (TCMEMBERPTR) 0 ) 
			{
				strcpy( TokenBuffer, mptr->object->name );
				status = syntax_error( 4342 );
			}
			else	status = 0;
		}

		establish_input_object( object );

		if (( mptr->value != (TCTEXTPTR) 0)
		&&  ( parameters  != (TCVARPTR) 0 ))
			(void) pop_source_context(1);

	}
	return( status );
}

/*	--------------------	*/
/*	activate_auto_method	*/
/*	--------------------	*/
static	WORD	activate_auto_method( mptr )
TCMBAUTOPTR	mptr;
{
	WORD	status;
	status = ll_activate_auto_method( mptr );
	release_expressions(1);
	return( status );
}

/*	-----------------------------	*/
/*	activate_indirect_constructor	*/
/*	-----------------------------	*/
static	WORD	activate_indirect_constructor( liste )
TCMBAUTOPTR	liste;
{
	if ( liste->method != (TCMBMETHPTR) 0)
		return( initialise_indirect_method( liste ) );
	else 	return( allocate_indirect_object( liste->world ) );
}

/*	---------------------------	*/
/*	flush_indirect_construction	*/
/*	---------------------------	*/
WORD	flush_indirect_construction( mptr, methods )
TCMBAUTOPTR		mptr;
TCMBAUTOPTR XPTR	methods;
{
	TCMBAUTOPTR	prev=(TCMBAUTOPTR) 0;
	TCMBAUTOPTR	liste;
	TCMBAUTOPTR	holder;
	WORD		status;

	liste = *methods;

	while ( liste != (TCMBAUTOPTR) 0 ) 
	{
		if (( mptr == (TCMBAUTOPTR) 0 )
		||  ( mptr->object->identity == liste->object->identity )) 
		{
			if ((status = activate_indirect_constructor( liste )) != 0)
				return( status );

			holder = liste->next;
			liste = liberate_auto_method( liste );
			if ( prev != (TCMBAUTOPTR) 0 )
				prev->next = holder;
			else	*methods   = holder;
			liste = holder;
		}
		else	
		{
			prev = liste;
			liste = liste->next;
		}
	}
	return( 0 );
}

/*	--------------------	*/
/*	activate_constructor	*/
/*	--------------------	*/
static 	WORD	activate_constructor( mptr )
TCMBAUTOPTR	mptr;
{
	if ( mptr->method != (TCMBMETHPTR) 0 )
		return( activate_auto_method( mptr ) );
	else	return( allocate_indirect_object( mptr->world ) );
}

/*	-------------------	*/
/*	activate_destructor	*/
/*	-------------------	*/
static 	WORD	activate_destructor( mptr )
TCMBAUTOPTR	mptr;
{
	if ( mptr->method != (TCMBMETHPTR) 0 )
		return( activate_auto_method( mptr ) );
	else	return( liberate_indirect_object( mptr->world ) );
}

/*	---------------------------------	*/
/*	 enhanced_implicite_construction	*/
/*	---------------------------------	*/
static	WORD	enhanced_implicite_construction()
{
	INSTANCENODE	iptr;
	WORD		status=0;

	if (!( AutoContext->ImpliciteConstruction ))
		return( allow_error_trapping() );
	else
	{

		while ((iptr = AutoContext->ImpliciteConstruction) != (INSTANCENODE) 0) 
		{
			AutoContext->ImpliciteConstruction = iptr->NextInstance;
			if ((status = start_construction_label(iptr)) != 0)
				break;
			else if ((status = replay_instance_construction( iptr, 0 )) != 0)
				break;
			else if ((status = terminate_construction_label( iptr )) != 0)
				break;
		}
		return( status );
	}
}

/*	---------------------------------	*/
/*	 enhanced_explicite_construction	*/
/*	---------------------------------	*/
static	WORD	enhanced_explicite_construction()
{
	INSTANCENODE	iptr;
	WORD		status=0;
	AutoContext->Explicite = VRAI;
	while ((iptr = AutoContext->ExpliciteConstruction) != (INSTANCENODE) 0) 
	{
		status = replay_instance_construction( iptr, 0 );
		if ((AutoContext->ExpliciteConstruction = iptr->NextInstance) == (INSTANCENODE) 0)
			AutoContext->ExpliciteDestruction = (INSTANCENODE) 0;
		else 	iptr->NextInstance->PreviousInstance = (INSTANCENODE) 0;
		iptr = liberate_instance_node( iptr );
		if ( status )
			break;
	}
	AutoContext->Explicite = FAUX;
	return( status );
}

/*	------------------	*/
/*	flush_constructors	*/
/*	------------------	*/
WORD	flush_constructors()
{
	TCMBAUTOPTR	mptr;
	WORD		status;

	if ( EnhancedConstruction )
		return( enhanced_implicite_construction() );

	else	
	{
		if ((status = flush_indirect_construction( (TCMBAUTOPTR) 0, & AutoContext->ImpliciteIndirect )) != 0)
			return( status );
		while ((mptr = AutoContext->ConstructionHeap) != (TCMBAUTOPTR) 0) 
		{
			AutoContext->ConstructionHeap = AutoContext->ConstructionHeap->next;
			if ((flush_indirect_construction( mptr, & AutoContext->ImpliciteIndirect )) != 0)
				return( status );
			else if ((status = activate_constructor( mptr )) != 0)
				return( status );
			else	mptr = liberate_auto_method( mptr );
		}
		return( 0 );
	}
}

/*	--------------------------------	*/
/*	 enhanced_implicite_destruction 	*/
/*	--------------------------------	*/
static	WORD	enhanced_implicite_destruction()
{
	INSTANCENODE	iptr;
	WORD		status=0;
	WORD		nombre=0;
	while ((iptr = AutoContext->ImpliciteDestruction) != (INSTANCENODE) 0) 
	{
		if ((status = start_destruction_label( iptr )) == 0) 
		{
			status = replay_instance_destruction( iptr, 0 );
			status += terminate_destruction_label(iptr);
		}
		if ((AutoContext->ImpliciteDestruction = iptr->PreviousInstance) == (INSTANCENODE) 0)
			AutoContext->ImpliciteConstruction = (INSTANCENODE) 0;
		else 	iptr->PreviousInstance->NextInstance = (INSTANCENODE) 0;
		iptr = liberate_instance_node( iptr );
		if ( status )
			break;
		else	nombre++;
	}
	if ( status )
		return( status );
	else if ( AutoContext->Router == (TCVARPTR) 0)
		return( 0 );
	else if ( nombre )
		return( flush_destruction_labels( 0 ) );
	else	return( 0 );
}

/*	--------------------------------	*/
/*	 enhanced_explicite_destruction 	*/
/*	--------------------------------	*/
static	WORD	enhanced_explicite_destruction()
{
	INSTANCENODE	iptr;
	WORD		status=0;

	AutoContext->Explicite = VRAI;
	while ((iptr = AutoContext->ExpliciteDestruction) != (INSTANCENODE) 0) 
	{
		status = replay_instance_destruction( iptr, 0 );
		if ((AutoContext->ExpliciteDestruction = iptr->PreviousInstance) == (INSTANCENODE) 0)
			AutoContext->ExpliciteConstruction = (INSTANCENODE) 0;
		else 	iptr->PreviousInstance->NextInstance = (INSTANCENODE) 0;
		iptr = liberate_instance_node( iptr );
		if ( status )
			break;
	}
	AutoContext->Explicite = FAUX;
	return( status );
}

/*	-----------------	*/
/*	flush_destructors	*/
/*	-----------------	*/
WORD	flush_destructors()
{
	TCMBAUTOPTR	mptr;
	WORD		status;
	trace("flush_destructors()\n");
	if ( EnhancedConstruction )
		return( enhanced_implicite_destruction() );
	else	
	{
		while ((mptr = AutoContext->DestructionHeap) != (TCMBAUTOPTR) 0) 
		{
			AutoContext->DestructionHeap = AutoContext->DestructionHeap->next;
			if ((status = activate_destructor( mptr )) != 0)
				return( status );
			else	mptr = liberate_auto_method( mptr );
		}
		return( 0 );
	}
}

/*	---------------------------	*/
/*	flush_explicite_destructors	*/
/*	---------------------------	*/
WORD	flush_explicite_destructors()
{
	TCMBAUTOPTR	mptr;
	WORD		status=0;
	WORD		Hold;
	trace("flush_explicite_destructors()\n");
	Hold = AutoContext->Destruction;
	AutoContext->Destruction = VRAI;
	if ( EnhancedConstruction )
		status = enhanced_explicite_destruction();
	else	
	{
		while ((mptr = AutoContext->DestructorHeap) != (TCMBAUTOPTR) 0) 
		{
			AutoContext->DestructorHeap = AutoContext->DestructorHeap->next;
			if ((status = activate_destructor( mptr )) != 0)
				break;
			else	mptr = liberate_auto_method( mptr );
		}
	}
	AutoContext->Destruction = Hold;
	return(status);
}

/*	----------------------------	*/
/*	flush_explicite_constructors	*/
/*	----------------------------	*/
WORD	flush_explicite_constructors()
{
	TCMBAUTOPTR	mptr;
	WORD		status=0;
	WORD		Hold;
	trace("flush_explicite_constructors()\n");
	Hold = AutoContext->Construction;
	AutoContext->Construction = VRAI;
	if ( EnhancedConstruction )
		status = enhanced_explicite_construction();
	else	
	{
		if ((status = flush_indirect_construction( (TCMBAUTOPTR) 0, & AutoContext->ExpliciteIndirect )) == 0) 
		{
			while ((mptr = AutoContext->ConstructorHeap) != (TCMBAUTOPTR) 0) 
			{
				AutoContext->ConstructorHeap = AutoContext->ConstructorHeap->next;
				if ((status = flush_indirect_construction( mptr, & AutoContext->ExpliciteIndirect )) != 0)
					break;
				else if ((status = activate_constructor( mptr )) != 0)
					break;
				else	mptr = liberate_auto_method( mptr );
			}
		}
	}
	AutoContext->Construction = Hold;
	if (( status )
	||  ( EnhancedConstruction ))
		return( status );
	else	return( flush_indirect_construction( mptr, & AutoContext->ExpliciteIndirect ));
}

/*	-----------------	*/
/*	remove_error_trap	*/
/*	-----------------	*/
WORD	remove_error_trap( TCERRPTR * eptr )
{
	TCERRPTR tptr=(TCERRPTR) 0;
	RESULTPTR rptr=(RESULTPTR) 0;
	WORD	label=0;

	/* -------------------------------- */
	/* ensure error trap location is ok */
	/* -------------------------------- */
	if (!( eptr ))
		return(0);
	/* ---------------------------- */
	/* ensure it has been installed */
	/* ---------------------------- */
	else if (!( tptr = *eptr ))
		return(0);
	else if (!( tptr->variable ))
	{
		tptr = liberate( tptr );
		*eptr = (TCERRPTR) 0;
		return(0);
	}
	else if (!( rptr = variable_result( tptr->variable ) ))
	{
		tptr = liberate( tptr );
		*eptr = (TCERRPTR) 0;
		return(0);
	}
	else
	{
		/* --------------------- */
		/* define the trap label */
		/* --------------------- */
		label = dcl_explicite_label( "X_CATCHER" );

		/* -------------------- */
		/* disactivate the trap */
		/* -------------------- */
		generate_error_abort();
		
		/* --------------------- */
		/* raise the error value */
		/* --------------------- */
		generate_error(rptr);

		/* ------------------------ */
		/* release the trap manager */
		/* ------------------------ */
		tptr = liberate( tptr );
		*eptr = (TCERRPTR) 0;
		return(0);
	}
}

/*	-----------------	*/
/*	install_error_trap	*/
/*	------------------	*/
WORD	install_error_trap( TCERRPTR * eptr )
{
	TCERRPTR tptr=(TCERRPTR) 0;
	RESULTPTR rptr=(RESULTPTR) 0;
	WORD	status=0;

	/* -------------------------------- */
	/* ensure error trap location is ok */
	/* -------------------------------- */
	if (!( eptr ))
		return(0);
	/* -------------------------------- */
	/* ensure it has not been installed */
	/* -------------------------------- */
	else if (( tptr = *eptr ))
		return(0);
	/* ------------------------- */
	/* allocate the trap manager */
	/* ------------------------- */
	else if (!( tptr = allocate( sizeof( struct tcode_error_trap ) ) ))
		return(allocation_failure());
	/* -------------------------- */
	/* declare the error variable */
	/* -------------------------- */
	else if ((tptr->variable = instance_exception_variable( "X_CATCHER" )) == (TCVARPTR) 0)
	{
		tptr = liberate( tptr );
		return( syntax_error( 5300 ) );
	}
	/* ------------------------------ */
	/* create the result for on error */
	/* ------------------------------ */
	else if  (!(rptr = variable_result(tptr->variable)))
	{
		tptr = liberate( tptr );
		return( syntax_error( 5302 ) );
	}
	/* -------------------------- */
	/* generate the on error goto */
	/* -------------------------- */
	else if ((status = explicite_on_error( rptr->contents, _CTRL_LOCAL, tptr->variable->name )) != 0)
	{
		tptr = liberate( tptr );
		return( status );
	}
	else
	{
		/* -------------- */
		/* return success */
		/* -------------- */
		*eptr = tptr;
		return(0);
	}
}

/*	----------------------	*/
/*	release_error_trapping	*/
/*	----------------------	*/
WORD	release_error_trapping()
{
	TCPRCPTR	pptr;
	TCSEGPTR	sptr;
	if ((pptr = Context->PRC) != (TCPRCPTR) 0)  
		return( remove_error_trap( & pptr->ErrorTrap ) );
	else if (!( sptr = Context->CurrentSegment ))
		return( 0 );
	else	return( remove_error_trap( & sptr->ErrorTrap ) );
}

/*	--------------------	*/
/*	allow_error_trapping	*/
/*	--------------------	*/
WORD	allow_error_trapping()
{
	TCPRCPTR	pptr;
	TCSEGPTR	sptr;
	if ((pptr = Context->PRC) != (TCPRCPTR) 0)  
	{
		if (!( pptr->ErrorTrapping ))
			return(0);
		else if (!( pptr->ErrorTrap ))
			return( install_error_trap( & pptr->ErrorTrap ) );
		else	return(0);
	}
	else if (!( sptr = Context->CurrentSegment ))
		return( 0 );
	else
	{
		if (!( sptr->ErrorTrapping ))
			return(0);
		else if (!( sptr->ErrorTrap ))
			return( install_error_trap( & sptr->ErrorTrap ) );
		else	return(0);
	}
}

/*	------------------	*/
/*	allow_construction	*/
/*	------------------	*/
WORD	allow_construction()
{
	WORD		status=0;
	if (( Context->CurrentSegment != (TCSEGPTR) 0)
	||  ( Context->PRC != (TCPRCPTR) 0))  
	{
		if (!( AutoContext->Construction )) 
		{
			AutoContext->Construction = VRAI;
			trace("allow_construction(Implicite)\n");
			status = flush_constructors();
			AutoContext->Construction = FAUX;
		}
	}
	return(status);
}

/*	---------------------------	*/
/*	activate_destruction_router	*/
/*	---------------------------	*/
static	WORD	activate_destruction_router()
{
	TCVARPTR	vptr;
	WORD		status;
	BYTE		lname[32];
	if (( EnhancedConstruction )
	&&  ( AutoContext->Destructors )
	&&  ((vptr = AutoContext->Router) != (TCVARPTR) 0)) 
	{
		sprintf(lname,"&%s",vptr->name);
		if ((status = generate_gosub_label( lname )) != 0)
			return( status );
	}
	return( 0 );
}

/*	------------------------	*/
/*	generate_exception_abort	*/
/*	------------------------	*/
WORD	generate_exception_abort()
{
	if ( AutoContext->Destructors )
		return( activate_destruction_router() );
	else 	return( generate_error_abort() );
}

/*	------------------------	*/
/*	verify_destruction_abort	*/
/*	------------------------	*/
WORD	verify_destruction_abort()
{
	if ( AutoContext->Destructors )
		return( activate_destruction_router() );
	else if ( AutoContext->Catcher != (TCVARPTR) 0 )
		return( generate_error_abort() );
	else	return( 0 );
}

/*	-------------------------	*/
/*	 flush_exception_handler	*/
/*	-------------------------	*/
WORD	flush_exception_handler(label)
WORD	label;
{
	TCVARPTR	cptr;
	RESULTPTR	rptr;
	WORD		status;
	BYTE		lname[32];


	if (( EnhancedConstruction )
	&&  ((cptr = AutoContext->Catcher) != (TCVARPTR) 0)) 
	{
		if (( label == MOINS_UN )
		&&  ( AutoContext->Exception != (EXCEPTIONPTR) 0)) 
		{
			if ((status = generate_exception_abort()) != 0)
				return( status );

			else if ((status = translate_break()) != 0)
				return( status );
		}
		/* ----------- */
		/* &Xn_CATCHER */
		/* ----------- */
		sprintf(lname,"&%s",cptr->name);

		if (add_explicite_label( lname ) == 0 )
			return( syntax_error( 5303 ) );

		/* ---------------------- */
		/* LOCAL EXCEPTION METHOD */
		/* ---------------------- */
		if ( AutoContext->Exception != (EXCEPTIONPTR) 0 ) 
		{
			if ((status = activate_explicite_exception( AutoContext->Exception )) != 0)
				return( status );
		}
		else	
		{
			if (( is_pragma_announce( _CLASS_EXCEPTION ) )
			&&  ((status = pause_announcement( "EXCEPTION" )) != 0))
				return( status );
		}

		if ((status = generate_exception_abort()) != 0)
			return( status );

		/* ---------------- */
		/* ERROR Xn_CATCHER */
		/* ---------------- */
		if ( AutoContext->Exception != (EXCEPTIONPTR) 0 ) 
		{
			if ((status = drop_exception_handler()) != 0)
				return( status );
		}
		else if ((rptr = variable_result( cptr  )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = generate_error( rptr )) != 0)
			return( status );

		AutoContext->Catcher = (TCVARPTR) 0;
	}
	return( 0 );
}

/*	-------------------------	*/
/*	 flush_exception_catcher	*/
/*	-------------------------	*/
WORD	flush_exception_catcher(label)
WORD	label;
{
	WORD	status=0;
	if ( AutoContext->Exception != (EXCEPTIONPTR) 0 ) 
	{
		status = terminate_exception( AutoContext->Exception, label );
		AutoContext->Exception = (EXCEPTIONPTR) 0;
		return( status );
	}
	else 	return( flush_exception_handler( label ) );
}

/*	------------------------	*/
/*	flush_destruction_router	*/
/*	------------------------	*/
WORD	flush_destruction_router(type)
WORD	type;	/* 0 : GOTO, 1 : GOSUB */
{
	BYTE		lname[32];
	TCVARPTR	vptr;
	RESULTPTR	rptr;
	WORD		backpatch;
	WORD		l;
	WORD		label;
	WORD		nombre=0;
	WORD		status;

	if (( EnhancedConstruction )
	&&  ((vptr = AutoContext->Router) != (TCVARPTR) 0)) 
	{
		/* ---------- */
		/* &Xn_ROUTER */
		/* ---------- */
		sprintf(lname,"&%s",vptr->name);

		if (add_explicite_label( lname ) == 0 )
			return( syntax_error( 5304 ) );

		if ( AutoContext->Destructors ) 
		{
			if ((rptr = variable_result( vptr  )) == (RESULTPTR) 0)
				return( allocation_failure() );
			else if ((of_requires_register() != 0)
			     &&  ((rptr = ensure_register( rptr  )) == (RESULTPTR) 0))
				return( allocation_failure() );

			if ( OtrOption.ListFlag & 1 )
				start_echo_of( rptr, type );

			/* -------------------------------------------------------- */
			/* OF Xn_ROUTER [ GOTO | GOSUB ] &Xn_ROUTER1 ,, &Xn_ROUTERm */
			/* -------------------------------------------------------- */
			if ((backpatch = generate_of( rptr, type )) == MOINS_UN)
				return( syntax_error( 5305 ) );

			for ( l = 1; l <= AutoContext->ExceptionLimit; l++ ) 
			{
				sprintf(lname,"&%s%u",vptr->name,l);
				if ( OtrOption.ListFlag & 1 )
					echo_of_label( nombre, lname );
				tcode_label((label = use_explicite_label( lname , 0 )));
				nombre++;
			}
			(void) backpatch_value( backpatch, nombre );
			if ( OtrOption.ListFlag & 1 )
				echo_line();

			/* ------ */
			/* RETURN */
			/* ------ */
			if ((status = generate_return()) != 0)
				return( status );
		}
	}
	return( 0 );
}

/*	--------------------------	*/
/*	generate_destruction_label	*/
/*	--------------------------	*/
static	WORD	generate_destruction_label( label )
WORD		label;
{
	BYTE	lname[32];
	if ( EnhancedConstruction ) 
	{
		sprintf(lname,"&X%llu_DESTRUCTION",AutoContext->Identity);
		(void) add_explicite_label( lname );
	}
	else	dcl_implicite_label( label );
	return(0);
}

/*	-------------------	*/
/*	perform_destruction	*/
/*	-------------------	*/
WORD	perform_destruction(label)
WORD	label;
{
	WORD	status=0;

	if (!( AutoContext->Destruction )) 
	{
		AutoContext->Destruction = VRAI;

		/* ------------------ */
		/* DESTRUCTION ROUTER */
		/* ------------------ */
		if ( label != MOINS_UN ) 
		{
			if ((AutoContext->Exception != (EXCEPTIONPTR) 0)
			&&  ((status = translate_break()) != 0))
				return( status );
			else if ((status = generate_destruction_label( label )) != 0)
				return( status );
			else if ((status = flush_destruction_router( 1 )) != 0)
				return( status );
		}
		else if ((status = flush_destruction_router( 0 )) != 0)
			return( status );

		/* ------------------- */
		/* DESTRUCTION METHODS */
		/* ------------------- */
		status = flush_destructors();

		/* -------------- */
		/* ON ERROR ABORT */
		/* -------------- */
		if (( EnhancedConstruction ) 
		&&  ( AutoContext->Router != (TCVARPTR) 0))
			status = generate_error_abort();	

		/* ------ */
		/* RETURN */
		/* ------ */
		if ( label != MOINS_UN )
			implicite_return();

		if ( AutoContext->Exception != (EXCEPTIONPTR) 0 ) 
		{
			if ((status = flush_exception_catcher(FAUX)) != 0)
				return( status );
		}
		else if ((status = flush_exception_handler(FAUX)) != 0)
			return( status );

		AutoContext->Destruction = FAUX;
	}
	return(status);
}

/*	--------------------------	*/
/*	generate_gosub_destruction	*/
/*	--------------------------	*/
WORD	generate_gosub_destruction()
{
	WORD	label=MOINS_UN;
	BYTE	lname[32];
	WORD	status;

	if ( EnhancedConstruction ) 
	{
		sprintf(lname,"&X%u_DESTRUCTION",AutoContext->Identity);
		if ((status = generate_gosub_label( lname )) != 0)
			return( status );
		else	return( 0 );
	}
	else	
	{
		label = new_implicite_label();
		implicite_gosub( label );
		return( label );
	}
}

/*	------------------	*/
/*	ensure_destruction	*/
/*	------------------	*/
WORD	ensure_destruction(status)
WORD	status;
{
	if (((!( EnhancedConstruction ))
	  && ( AutoContext->DestructionHeap != (TCMBAUTOPTR) 0 ))
	||  (( EnhancedConstruction )
	  && ( AutoContext->Destructors )
	  && ( AutoContext->ImpliciteDestruction != (INSTANCENODE) 0)))
		return( generate_gosub_destruction() );
	else	return( status );
}

/*	------------------	*/
/*	detect_destruction	*/
/*	------------------	*/
WORD	detect_destruction()
{
	if (!( AutoContext->Destruction ))
		return( ensure_destruction( MOINS_UN ) );
	else 	return( MOINS_UN );
}

	/* --------- */
#endif	/* _TRAUTO_C */
	/* --------- */


