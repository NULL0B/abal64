#ifndef _TRWORLD_C
#define _TRWORLD_C

/*	----------------------	*/
/*	initialise_class_trees	*/
/*	----------------------	*/
static  VOID    initialise_class_trees()
{
	WORD    i;
	trace("initialise_class_trees()\n");
	for ( i=0; i < CLASS_TREE_HASH; i++ )
		World->ClassTree[i] =(TREEPTR) 0;
	World->TreesUsed = (TREEPTR) 0;
	return;
}

/*	--------------------	*/
/*	liberate_class_trees	*/
/*	--------------------	*/
static  VOID    liberate_class_trees()
{
	TREEPTR tptr;

	trace("liberate_class_trees()\n");
	while ((tptr = World->TreesUsed) != (TREEPTR) 0) {
		World->TreesUsed = tptr->next;
		liberate( tptr );
		}
	initialise_class_trees();
	return;
}

/*	--------------------	*/
/*	terminate_world_list	*/
/*	--------------------	*/
VOID    terminate_world_list()
{
	if ( World->ListHandle != (FILEPTR) 0 ) 
	{
		fclose( World->ListHandle );
		World->ListHandle = (FILEPTR) 0;
	}
	return;
}

/*	-----------------	*/
/*	 terminate_world	*/
/*	-----------------	*/
WORD    terminate_world()
{
	TCSTRUCTPTR     sptr;
	TCMEMBERPTR     mptr;
	TCVARPTR        vptr;
	COMMONPTR       cptr;

	trace("terminate_world()\n");

	if ( World != (WORLDPTR) 0) 
	{
		trace("liberate(World->Structures)\n");
		while ((sptr = World->Structures) != (TCSTRUCTPTR) 0) 
		{
			World->Structures = sptr->next;
			liberate_for_structure( sptr );
		}

		trace("liberate(Context->Current)\n");
		while ((sptr = World->CurrentStructure) != (TCSTRUCTPTR) 0) 
		{
			World->CurrentStructure = sptr->next;
			liberate_for_structure( sptr );
		}

		trace("liberate(World->Common)\n");
		while (( cptr = World->Common ) != (COMMONPTR) 0) 
		{
			World->Common = cptr->next;
			liberate_common_member( cptr );
		}

		trace("liberate(World->Macros)\n");
		while (( mptr = World->Macros ) != (TCMEMBERPTR) 0) 
		{
			World->Macros = mptr->next;
			liberate_structure_member( mptr );
		}

		while (( vptr = World->VariableHeap ) != (TCVARPTR) 0) 
		{
			World->VariableHeap = vptr->next;
			liberate( vptr );
		}

		liberate_definitions();
		liberate_class_trees();

		if ( World->Editor != (BPTR) 0 )
			liberate( World->Editor );

		if ( World->ErrorFile != (BPTR) 0 )
			liberate( World->ErrorFile );
	
		if ( World->StyleSheet != (BPTR) 0 )
			liberate( World->StyleSheet );
	
		terminate_world_list();

		if ( World->ListFile != (BPTR) 0 )
			liberate( World->ListFile );

		if ( World->TraceFile != (BPTR) 0 )
			liberate( World->TraceFile );

		if ( World->DefinedPragmas != (PRAGMAPTR) 0)
			release_defined_pragmas();

#ifdef  SWAP_CTRL
		liberate_buffer_controller();
#endif
		flush_debug_trace();
	
		liberate_for_options();

		liberate( World );
		World = (WORLDPTR) 0;
		return(0);
	}
	else    return(0);
}

/*	------------------	*/
/*	world_swap_garbage	*/
/*	------------------	*/
static  WORD    world_swap_garbage()
{
	return( tcode_garbage_collector() );
}

/*	------------------	*/
/*	world_swap_message	*/
/*	------------------	*/
static  WORD    world_swap_message()
{
	if ( OtrOption.Verbose )
		sysprintf("Swap Message Received\n");
	return( 0 );
}

/*	-----------------	*/
/*	set_world_virtual	*/
/*	-----------------	*/
WORD    set_world_virtual()
{
	World->Virtual = VRAI;
	return( 0 );
}

/*	-----------------	*/
/*	get_world_virtual	*/
/*	-----------------	*/
WORD    get_world_virtual()
{
	WORD    temp =  World->Virtual;
	World->Virtual = FAUX;
	return( temp );
}

/*	----------------	*/
/*	initialise_world	*/
/*	----------------	*/
WORD    initialise_world()
{
	WORD    status;

	if ((World = (WORLDPTR) allocate( sizeof ( struct otr_world ) )) == (WORLDPTR) 0)
		return( 27 );
	else    
	{
		World->DefinedPragmas  = (PRAGMAPTR) 0;
		World->VariableHeap     = (TCVARPTR) 0;
		World->ErrorFile        = (BPTR) 0;
		World->PragmaFile       = (BPTR) 0;
		World->ListFile         = (BPTR) 0;
		World->ListHandle       = (FILEPTR) 0;
		World->TraceFile        = (BPTR) 0;
		World->Editor           = (BPTR) 0;
		World->StyleSheet       = (BPTR) 0;
		World->FirstStructure   = (TCSTRUCTPTR) 0;                
		World->Structures       = (TCSTRUCTPTR) 0;
		World->CurrentStructure = (TCSTRUCTPTR) 0;
		World->Common           = (COMMONPTR) 0;
		World->LastCommon       = (COMMONPTR) 0;
		World->Macros           = (TCMEMBERPTR) 0;
		World->Scope            = 0;
		World->Virtual          = FAUX;
		World->SwapBuffers      = _SWAP_BUFFERS;
		World->SymbolicHost		= (HOSTPTR) 0;
		initialise_class_trees();
		initialise_definitions();
#ifdef  SWAP_CTRL
		/* ----------------------------------------------- */           
		/* Activate the Buffer Node Swap control Mechanism */
		/* ----------------------------------------------- */           
		if (initialise_buffer_control( "otr.swp", sizeof( struct tcode_value ), World->SwapBuffers, 10 ) == MOINS_UN )
			return( 27 );
		set_swap_garbage( world_swap_garbage );
		set_swap_message( world_swap_message );
#endif
		World->ErrorFile        = allocate_for_string(_WORLD_ERROR_FILE);
		World->TraceFile        = allocate_for_string(_WORLD_TRACE_FILE);
		World->Editor           = allocate_for_string(_WORLD_EDITOR);
		if (((status = add_definition(_HOST_ENVIRONMENT,0)) != 0)
		||  ((status = add_definition(_TOOL_IDENTITY,0)) != 0)
		||  ((status = add_definition(_TOOL_UPPER,0)) != 0)
		||  ((status = add_definition(_TOOL_VERSION,0)) != 0)) 
		{
			(void) terminate_world();
			return( status );
		}
		else	
		{
			World->PragmaFile = sysgetenv("STDPRAGMA");
			return( 0 );
		}
	}
}

/*	-----------	*/
/*	enter_world	*/
/*	-----------	*/
WORD    enter_world()
{
	if ( World == (WORLDPTR) 0 ) 
		return( 0 );
	else    return(++World->Scope); 
}

/*	-----------	*/
/*	leave_world	*/
/*	-----------	*/
WORD    leave_world()
{
	if ( World != (WORLDPTR) 0 ) 
		World->Scope--;
	return( 0 );
}

/*	-------------------	*/
/*	flush_world_members	*/
/*	-------------------	*/
WORD    flush_world_members()
{
	COMMONPTR       common;
	WORD            status=0;
	trace("flush_world_members()\n");
	if ((common = World->Common) != (COMMONPTR) 0) 
	{
		do      
		{
			if ((status = declare_world_member( common->member )) != 0)
				break;
		}
		while ((common = common->next) != (COMMONPTR) 0);
	}
	return( status );
}

/*	--------------------	*/
/*	flush_module_commons	*/
/*	--------------------	*/
WORD    flush_module_commons(sptr)
TCSTRUCTPTR	sptr;
{
	COMMONPTR       common;
	WORD            status=0;
	trace("flush_module_commons()\n");
	if ((common = World->Common) != (COMMONPTR) 0) 
	{
		do      
		{
#ifndef WIN32
			trace("declare_module_commons(");
			trace(common->member->name);
			trace(")\n");
#endif
			if ((status = declare_module_common( common->member, sptr )) != 0)
				break;
		}
		while ((common = common->next) != (COMMONPTR) 0);
	}
	return( status );
}

/*	-------------------------	*/
/*	 class_enhanced_indirect	*/
/*	-------------------------	*/
WORD    class_enhanced_indirect(class)
TCSTRUCTPTR     class;
{
	if (class != (TCSTRUCTPTR) 0 )
		return(( class->enhanced & _ENHANCED_INDIRECT ));
	else    return( 0 );
}

/*	-------------------------	*/
/*	 world_enhanced_indirect	*/
/*	-------------------------	*/
WORD    world_enhanced_indirect()
{
	TCSTRUCTPTR     class;
	if ((class = World->CurrentStructure) != (TCSTRUCTPTR) 0 )
		return(( class->enhanced & _ENHANCED_INDIRECT ));
	else    return( 0 );
}

/*	------------------------	*/
/*	member_enhanced_indirect	*/
/*	------------------------	*/
WORD    member_enhanced_indirect( member )
TCMEMBERPTR     member;
{
	TCSTRUCTPTR     class;
	if (( member != (TCMEMBERPTR) 0)
	&&  ((class = member->class) != (TCSTRUCTPTR) 0 ))
		return(( class->enhanced & _ENHANCED_INDIRECT ));
	else    return( 0 );
}

/*	------------	*/
/*	world_editor	*/
/*	------------	*/
BPTR    world_editor()
{
	if ( World->Editor != (BPTR) 0) 
		return( World->Editor );
	else    return((BPTR) _WORLD_EDITOR );
}

/*	-----------------	*/
/*	 world_errorfile	*/
/*	-----------------	*/
BPTR    world_errorfile( mode )
WORD    mode;   /* 1 : with extension,   0 : without extension */
{
	if ( World->ErrorFile != (BPTR) 0) 
		return( World->ErrorFile );
	else    return((BPTR) _WORLD_ERROR_FILE );
}

/*	----------------	*/
/*	 world_listfile 	*/
/*	----------------	*/
BPTR    world_listfile( mode )
WORD    mode;   /* 1 : with extension,   0 : without extension */
{
	if ( World->ListFile != (BPTR) 0) 
		return( World->ListFile );
	else    return((BPTR) _WORLD_LIST_FILE );
}

/*	-----------------	*/
/*	 world_tracefile	*/
/*	-----------------	*/
BPTR    world_tracefile( mode )
WORD    mode;   /* 1 : with extension,   0 : without extension */
{
	if ( World->TraceFile != (BPTR) 0) 
		return( World->TraceFile );
	else    return((BPTR) _WORLD_TRACE_FILE );
}

/*	----------------	*/
/*	set_world_editor	*/
/*	----------------	*/
WORD    set_world_editor( nptr )
BPTR    nptr;
{
	if ( World->Editor != (BPTR) 0 ) 
	{
		liberate( World->Editor );
		World->Editor = (BPTR) 0;
	}
	if ((World->Editor = allocate_for_string( nptr )) != (BPTR) 0)
		return( 0 );
	else    return( allocation_failure() );
}

/*	-------------------	*/
/*	set_world_errorfile	*/
/*	-------------------	*/
WORD    set_world_errorfile( nptr, aptr )
BPTR    nptr;
BPTR    aptr;
{
	if ( World->ErrorFile != (BPTR) 0 ) 
	{
		liberate( World->ErrorFile );
		World->ErrorFile = (BPTR) 0;
	}

	if (( aptr != (BPTR) 0 )
	&&  ( strlen(aptr) != 0))
		nptr = aptr;

	if ((World->ErrorFile = allocate( strlen(nptr)+32 )) != (BPTR) 0) 
	{
		if ( fn_parser( nptr, World->ErrorFile, 0x000F ) == 0) 
		{
			liberate( World->ErrorFile );
			World->ErrorFile = (BPTR) 0;
		}
		else    
		{
#ifdef  PROLOGUE
			strcat( World->ErrorFile, ".e" );
#else
			strcat( World->ErrorFile, ".err" );
#endif
		}
		return( 0 );
	}
	else    return( allocation_failure() );
}

/*	------------------	*/
/*	set_world_listfile	*/
/*	------------------	*/
WORD    set_world_listfile( nptr, aptr )
BPTR    nptr;
BPTR    aptr;
{
	if ( World->ListFile != (BPTR) 0 ) 
	{
		liberate( World->ListFile );
		World->ListFile = (BPTR) 0;
	}

	if (( aptr != (BPTR) 0 )
	&&  ( strlen(aptr) != 0))
		nptr = aptr;

	if ((World->ListFile = allocate( strlen(nptr)+32 )) != (BPTR) 0) 
	{
		if ( fn_parser( nptr, World->ListFile, 0x000F ) == 0) 
		{
			liberate( World->ListFile );
			World->ListFile = (BPTR) 0;
		}
		else    
		{
#ifdef  PROLOGUE
			strcat( World->ListFile, ".l" );
#else
			strcat( World->ListFile, ".lst" );
#endif
		}
		return( 0 );
	}
	else    return( allocation_failure() );
}

/*	-------------------	*/
/*	set_world_tracefile	*/
/*	-------------------	*/
WORD    set_world_tracefile( nptr )
BPTR    nptr;
{
	if ( World->TraceFile != (BPTR) 0 ) 
	{
		liberate( World->TraceFile );
		World->TraceFile = (BPTR) 0;
	}
	if ((World->TraceFile = allocate( strlen(nptr)+32 )) != (BPTR) 0) 
	{
		if ( fn_parser( nptr, World->TraceFile, 0x000F ) == 0) 
		{
			liberate( World->TraceFile );
			World->TraceFile = (BPTR) 0;
		}
		else    strcat( World->TraceFile, ".dbe" );
		return( 0 );
	}
	else    return( allocation_failure() );
}

	/* ---------- */
#endif  /* _TRWORLD_C */
	/* ---------- */

