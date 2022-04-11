#ifndef	_TROBJECT_C
#define	_TROBJECT_C

#undef  _TRACE_ACP
#undef 	DEBUG_TRACE_ACTIVE

#ifndef	UNIX
#else
VOID		echo_transmit_common();
WORD		print_information();
RESULTPTR	clf_validptr();
RESULTPTR	evaluate_member_term();
RESULTPTR	is_parameter_term();
TCTEXTPTR	collect_construction_parameters();
TCMBMETHPTR	allocate_structure_method();
TCVARPTR	explicite_method_parameters();
TCVARPTR	resolve_method_pointer();
TCVARPTR	resolve_method_table();
TCVARPTR	is_local_variable();
TCVARPTR	resolve_object_container();
TCMBFUNCPTR	build_function_method();
TCMEMBERPTR	locate_common_object();
#endif

#ifdef WIN32
#include "trtrace.h"
#endif

/*	--------------	*/
/*	is_member_term	*/
/*	--------------	*/
static RESULTPTR	is_member_term(funcptr)
{
	TCVARPTR	object=(TCVARPTR) 0;

	if (( object = (TCVARPTR) input_object()) != (TCVARPTR) 0   )
		return( evaluate_member_term( object, funcptr ));
	else	return( (RESULTPTR) 0);
}

/*	----------------------	*/
/*	compare_parameter_list	*/
/*	----------------------	*/
WORD	compare_parameter_list( lvarb, rvarb )
TCVARPTR	lvarb;
TCVARPTR	rvarb;
{
	trace("compare_parameter_list()\n");
	while ( 1 ) 
	{
		if ( lvarb == (TCVARPTR) 0 ) 
		{
			if ( rvarb == (TCVARPTR) 0 )
				return( VRAI );
			else	return( FAUX );
		}
		else if ( rvarb == (TCVARPTR) 0 )
			return( FAUX );

		trace("parameter(");
		trace(lvarb->name);
		trace(")\n");
		if (!( compare_types( lvarb->type, rvarb->type ) ))
			return( FAUX );
		else	
		{
			lvarb = lvarb->next;
			rvarb = rvarb->next;
		}
	}
}

/*	-------------	*/
/*	object_exists	*/
/*	-------------	*/
WORD	object_exists()
{
	TCVARPTR	object;
	if ((object = is_object()) != (TCVARPTR) 0)
		return( VRAI );
	else	return( FAUX );
}

/*	--------------------	*/
/*	evaluate_object_term	*/
/*	--------------------	*/
static RESULTPTR	evaluate_object_term(object,funcptr)
TCVARPTR	object;
WORD	funcptr;
{
	if ((object->type->type & _TYPE_DEFINED)
	&&  ( is_period() )) 
	{
		if (!( get_token() )) 
		{
			(void) syntax_error(4);
			return( (RESULTPTR) 0);
		}
		else 	return( evaluate_member_term( object, funcptr ) );
	}
	else	return( variable_result( object ) );
}

/*	--------------	*/
/*	is_object_term	*/
/*	--------------	*/
static RESULTPTR	is_object_term(funcptr)
WORD	funcptr;
{
	TCVARPTR	object;
	if ((object = is_object()) != (TCVARPTR) 0)
		return( evaluate_object_term( object, funcptr ) );
	else	return( (RESULTPTR) 0 );
}

/*	-------------	*/
/*	is_local_term	*/
/*	-------------	*/
static	RESULTPTR	is_local_term( funcptr )
WORD			funcptr;
{
	TCVARPTR	vptr;
	if ((vptr = is_local_variable()) == (TCVARPTR) 0)
		return( (RESULTPTR) 0 );
	else	return(evaluate_object_term( vptr, funcptr ) );
}

/*	--------------------	*/
/*	object_symbolic_term	*/
/*	--------------------	*/
RESULTPTR	object_symbolic_term(funcptr)
WORD		funcptr;
{
	RESULTPTR	rptr;

	if ((rptr = is_parameter_term()) != (RESULTPTR) 0)
		return( rptr );
	else if ((rptr = is_local_term(funcptr)) != (RESULTPTR) 0)
		return( rptr );
	else if ((rptr = is_member_term(funcptr)) != (RESULTPTR) 0)
		return( rptr );
	else if ((rptr = is_object_term(funcptr)) != (RESULTPTR) 0)
		return( rptr );
	else	return( (RESULTPTR) 0 );
}

/*	-------------------	*/
/*	add_common_pointers	*/
/*	-------------------	*/
static	TCVARPTR	add_common_pointers( root, liste )
TCVARPTR		root;
TCVARPTR		liste;
{
	TCVARPTR	variable;
	TCVARPTR	previous;
	TCVARPTR	current;

#ifdef	_TRACE_ACP
	sysprintf("add_common_pointers()\n");
#endif
	while ((variable = liste) != (TCVARPTR) 0) 
	{

		liste = liste->next;
		previous = (TCVARPTR) 0;

#ifdef	_TRACE_ACP
		sysprintf("acp:search(%s,%u)\n",variable->name,variable->hash);
#endif
		if ((current = root) == (TCVARPTR) 0) 
		{
#ifdef	_TRACE_ACP
			sysprintf("acp:root(%s,%u)\n",variable->name,variable->hash);
#endif
			root = variable;
		}
		else	
		{
			do	
			{
				if (( variable->hash == current->hash )
				&&  ( compare_tokens( variable->name, current->name ))) 
				{
#ifdef	_TRACE_ACP
					sysprintf("acp:eliminate(%s,%u)\n",variable->name,variable->hash);
#endif
					liberate_for_variable( variable );
					previous = (TCVARPTR) 0;
					break;
				}
				else	previous = current;
			}
			while ((current = current->next) != (TCVARPTR) 0);

			if ( previous != (TCVARPTR) 0 ) 
			{
#ifdef	_TRACE_ACP
				sysprintf("acp:add(%s,%u)\n",variable->name,variable->hash);
#endif
				previous->next = variable;
				variable->next = (TCVARPTR) 0;
			}
		}
	}
#ifdef	_TRACE_ACP
	sysprintf("acp:done()\n");
#endif
	return( root );
}

/*	--------------------	*/
/*	copy_common_pointers	*/
/*	--------------------	*/
static	TCVARPTR	copy_common_pointers( root, liste )
TCVARPTR		root;
TCVARPTR		liste;
{
	TCVARPTR	variable;
	TCVARPTR	previous;
	TCVARPTR	current;

#ifdef	_TRACE_ACP
	sysprintf("copy_common_pointers()\n");
#endif
	while ((variable = liste) != (TCVARPTR) 0) 
	{

		liste = liste->next;
		previous = (TCVARPTR) 0;

#ifdef	_TRACE_ACP
		sysprintf("acp:search(%s,%u)\n",variable->name,variable->hash);
#endif
		if ((current = root) == (TCVARPTR) 0) 
		{
#ifdef	_TRACE_ACP
			sysprintf("acp:root(%s,%u)\n",variable->name,variable->hash);
#endif
			root = copy_variable( variable );
		}
		else	
		{
			do	
			{
				if (( variable->hash == current->hash )
				&&  ( compare_tokens( variable->name, current->name ))) 
				{
#ifdef	_TRACE_ACP
					sysprintf("acp:eliminate(%s,%u)\n",variable->name,variable->hash);
#endif
					previous = (TCVARPTR) 0;
					break;
				}
				else	previous = current;
			}
			while ((current = current->next) != (TCVARPTR) 0);

			if ( previous != (TCVARPTR) 0 ) 
			{
#ifdef	_TRACE_ACP
				sysprintf("acp:add(%s,%u)\n",variable->name,variable->hash);
#endif
				previous->next = copy_variable( variable );
			}
		}
	}
#ifdef	_TRACE_ACP
	sysprintf("acp:done()\n");
#endif
	return( root );
}

/*	-------------------------	*/
/*	 overlay_common_pointers	*/
/*	-------------------------	*/
static TCVARPTR	overlay_common_pointers( root, worldclass, member )
TCVARPTR	root;
TCSTRUCTPTR	worldclass;
TCMEMBERPTR	member;
{
	TCVARPTR	variable=(TCVARPTR) 0;
	TCMBDATAPTR	dptr;
	TCSTRUCTPTR	class;
	WORD		status;
	WORD		size;

#ifdef	_TRACE_ACP
	sysprintf("overlay_common_pointers(%s)\n",worldclass->name);
#endif
	switch ( worldclass->commonlock ) 
	{
	case	VRAI	 :
		root = copy_common_pointers( root, worldclass->commonroot );
	case	MOINS_UN :
		return( root );
	}

	worldclass->commonlock = MOINS_UN;

	while ( member != (TCMEMBERPTR) 0 ) 
	{

#ifdef	_TRACE_ACP
		sysprintf("\tocp:member(%s)\n",member->name);
#endif
		if  (( member->nature )
		&&   ( member->nature != _KW1_CONST )
		&&   ((dptr = (TCMBDATAPTR)member->special) != (TCMBDATAPTR) 0)
		&&   ( dptr->structname != (BPTR) 0)) 
		{
			if (((class = dptr->structure) == (TCSTRUCTPTR) 0)
			&&  ((class = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0)) 
			{
				status = internal_error( 1516 );
				break;
			}

			worldclass->commonroot = overlay_common_pointers(worldclass->commonroot, class, class->first );

			if (( member->access & _MEMBER_COMMON )
			&& (!(member->access & _MEMBER_LOCAL))) { 
			 
				if ((status = declare_common_object( member->class, class, member, dptr->construction, dptr->field )) != 0)
					break;
				if (( size = structure_occupation( class )) != 0) 
				{
					if (((variable = allocate_for_variable()) == (TCVARPTR) 0) 
					||  ((variable->name = allocate_for_string( member->name )) == (BPTR) 0)
					||  ((variable->type = allocate_for_type( 
						(_TYPE_POINTER | _TYPE_DEFINED | _TYPE_STRING | _TYPE_PARAMETER), size , 1, 1, class )) == (TCTYPPTR) 0)) 
					{
						status = allocation_failure();
						break;
					}
					else	
					{
						variable->class = (VPTR)member->class;
						variable->hash = member->hash;
						worldclass->commonroot = add_common_pointers( worldclass->commonroot, variable );
					}
				}
			}
		}
		member = member->next;
	}
#ifdef	_TRACE_ACP
	sysprintf("ocp:done()\n");
#endif
	root = copy_common_pointers( root, worldclass->commonroot );
	worldclass->commonlock = VRAI;
	return( root );
}

/*	------------------------	*/
/*	overlay_common_interface	*/
/*	------------------------	*/
TCTEXTPTR	overlay_common_interface( parameters )
TCVARPTR	parameters;
{
	WORD		status;
	TCTEXTPTR	tptr=(TCTEXTPTR) 0;
	WORD		nombre=0;

	if ((tptr = allocate_text_value()) == (TCTEXTPTR) 0) 
	{
		(void) allocation_failure();
		return( tptr );
	}		
	else	ClassOptions.MethodText = tptr->buffer;

	if ((status = put_method_byte('(')) != 0)
		tptr = liberate_text_value( tptr );
	else 	
	{
		while ( parameters != (TCVARPTR) 0) 
		{
			if ( nombre++ )
				if (((status = put_method_byte(';')) != 0)
				||  ((status = put_method_byte(0x0027)) != 0)
				||  ((status = put_method_byte('\n')) != 0))
					break;

			if ((status = put_method_string( parameters->name )) != 0)
				break;
			else	parameters = parameters->next;
		}

		if (!( status ))
			status = put_method_byte(')');
	
		ClassOptions.MethodText = (VALUEPTR) 0;

		if ( status ) 
			tptr = liberate_text_value( tptr );

#ifdef	DEBUG_PRE_CONSTR
		trace_value( tptr->buffer, "Builder" );
#endif
	}

	return( tptr );

}

/*	-------------------------	*/
/*	 build_overlay_interface	*/
/*	-------------------------	*/
TCMBMETHPTR	build_overlay_interface( class, number )
TCSTRUCTPTR	class;
WORD		number;
{
	TCMBMETHPTR	method;
	WORD		status;
	trace("build_overlay_interface("); trace( class->name ); trace(")\n");

	if ((method = allocate_structure_method()) != (TCMBMETHPTR) 0) 
	{
		if ((method->number  = number) == 1)
			method->special = _CLASS_CONSTRUCTOR;
		else	method->special = _CLASS_DESTRUCTOR;

		method->nature  = _CLASS_FUNCTION;
		method->options = (_METHOD_INDIRECT | _METHOD_STRICT);

		method->parameters = overlay_common_pointers( (TCVARPTR) 0, class, class->first );

		if ((status = build_pseudo_object(method,class)) != 0 ) 
		{
			(void) internal_error( 1515 );
			liberate_structure_method( method );
			method = (TCMBMETHPTR) 0;
		}
	}
	return( method );
}

/*	----------------------------------------------------------------	*/
/*	T R A N S M I T _ C O M M O N _ L I N K A G E ( object, number )	*/
/*	----------------------------------------------------------------	*/
/*	Program Overlay Objects expect to recieve COMMON object pointers	*/
/*	from the host WORLD. These are transmited via calls to the implicite	*/
/*	PRE-CONSTRUCTION and POST-DESTRUCTION indirect methods pointed to by	*/
/*	the function pointers : (IMT(1)) and (IMT(2)).				*/
/*	----------------------------------------------------------------	*/

WORD		transmit_common_linkage( world, object, number, mode )
TCVARPTR	world;
TCVARPTR	object;
WORD		number;
WORD		mode;
{
	TCMBMETHPTR	method;
	TCVARPTR	variable;
	TCTEXTPTR	valptr=(TCTEXTPTR) 0;
	WORD		status;

	if ((method = build_overlay_interface( object->type->class, number )) == (TCMBMETHPTR) 0)
		return( allocation_failure() );

	else if ((variable = explicite_method_parameters( method )) != (TCVARPTR) 0)
		valptr = overlay_common_interface( variable );

	if (number == 1) 
	{
		if ((status = add_construction_method( world, object, (TCMEMBERPTR) 0, method, valptr, mode )) != 0)
			return( status );
	}

	else if ( number == 2 ) 
	{
		if ((status = add_destruction_method( world,object, (TCMEMBERPTR) 0, method, valptr, mode )) != 0)
			return( status );
	}
		
	return( 0 );

}

/*	-------------------------	*/
/*	 announce_common_linkage	*/
/*	-------------------------	*/
static	VOID	announce_common_linkage( texte,nptr )
BPTR	texte;
BPTR	nptr;
{
	BYTE		message[128];

	sprintf(message,"%s (Common %s)",texte,nptr);
	pause_announcement( message );
	return;
}

/*	----------------------	*/
/*	receive_common_linkage	*/
/*	----------------------	*/
static	WORD	receive_common_linkage( object, class )
TCVARPTR	object;
TCSTRUCTPTR	class;
{
	RESULTPTR	lptr;
	RESULTPTR	rptr;
	WORD		label;
	WORD		elabel;
	TCVARPTR	target;
	TCMEMBERPTR	member;
	WORD		status;
	TCSTRUCTPTR	sptr;
	while (( object != (TCVARPTR) 0 )
	   &&  ( object->type->type & _TYPE_PARAMETER )) 
	{
		sptr = (TCSTRUCTPTR)object->class;
		if ((lptr = clf_validptr( object )) == (RESULTPTR) 0)
			return( syntax_error( 5119 ) );
		else if ((rptr = integer_result(0)) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((label = new_implicite_label()) == MOINS_UN)
			return( syntax_error( 5118 ) );
		else if ((status = evaluate_comparison(_CMP_EQ,lptr,rptr,_LOGICAL_USE,label)) != 0 )
			return( status );
		if ( is_pragma_announce( _CLASS_COMMON ) )
			announce_common_linkage( "Alias", sptr->name );
		if ((member = locate_common_object( object->name, object->type->class, object->class )) == (TCMEMBERPTR) 0)
			return( syntax_error( 5117 ) );
		else if ((target = member->common) == (TCVARPTR) 0)
			return( syntax_error( 5116 ) );
		else if ((lptr = variable_result( target )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((rptr = variable_result( object )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else if ((status = clf_alias( lptr, rptr )) != 0)
			return( status );
		else	
		{
			elabel = new_implicite_label();
			implicite_goto( elabel );
			dcl_implicite_label( label );
			if ( is_pragma_announce( _CLASS_COMMON ) ) 
			{
				announce_common_linkage( "Forget", sptr->name );
			}
			if ((status = clf_forget( lptr )) != 0)
				return( status );
			dcl_implicite_label( elabel );
		}
		signal_new_line(VRAI);
		object = object->prev;
	}
	return( 0 );
}


/*	---------------------------------------------------------	*/
/*	 D E C L A R E _ O V E R L A Y _ C O N S T R U C T I O N	*/
/*	---------------------------------------------------------	*/
/*	Overlay and Aplus Compatible Indirect objects require
 *	specialised pre-construction and post-destruction.
 *
 *	INDIRECT OBJECT :	CREATE/REMOVE <indirect_method_table>
 *				indicated by "resolve_method_table(object)"
 *
 *				CREATE/REMOVE <object_container>
 *				indicated by "resolve_method_table(object)->prev"
 *
 *	OVERLAY OBJECT  :	Common object linkage via calls to
 *				the implicite indirect method pointer
 *					(<resolve_method_table> (1)) 
 *				for pre-construction and to
 *					(<resolve_method_table> (2)) 
 *				for post-destruction.
 *
 *	---------------------------------------------------------	*/

WORD	declare_overlay_construction( world, object, mode, allocation )

				/* ---------------------------- */
TCVARPTR	world;		/* WORLD in which it happens	*/
				/* ---------------------------- */
TCVARPTR	object;		/* OBJECT requiring operation	*/
				/* ---------------------------- */
				/* Operation Mode		*/
				/* ---------------------------- */
WORD		mode;		/* CONSTRUCT:1, DESTRUCT: 2	*/
				/* EXPLICITE:4, IMPLICITE:0	*/
				/* ---------------------------- */
				/* Allocation instruction	*/
				/* ---------------------------- */
WORD		allocation;	/* Explicite CREATE:0, ATTACH:1	*/
				/* Implicite MOINS_UN		*/
				/* ---------------------------- */
{
	WORD		status;
	TCSTRUCTPTR	class;

	trace("declare_overlay_construction()\n");

	while ( object->parent != (TCVARPTR) 0)
		object = object->parent;

	if ((class = (TCSTRUCTPTR)object->type->class) == (TCSTRUCTPTR) 0)
		return( internal_error( 333 ) );

	/* ----------------------------------------------------------- */
	/* ATTACH/DETACH : require PRE-CONSTRUCTION / POST-DESTRUCTION */
	/* ----------------------------------------------------------- */
	if ( allocation == 1 ) 
	{

		/* PRE-CONSTRUCTION */
		/* ---------------- */
		if (( mode & 1 )
		&&  (( status = transmit_common_linkage( world, object, 1, mode )) != 0))
			return( status );

		/* POST-DESTRUCTION */
		/* ---------------- */
		if (( mode & 2 )
		&&  (( status = transmit_common_linkage( world, object, 2, mode )) != 0))
			return( status );

	}
	else	
	{
		if ( mode & 1 ) 
		{
			/* ---------------------------------- */
			/* CREATE IMT (indirect method table) */
			/* ---------------------------------- */
			if ((status = add_indirect_construction( resolve_method_table(object), object, (TCMEMBERPTR) 0, (TCMBMETHPTR) 0, mode )) != 0)
				return( status );

			/* ----------------------------- */
			/* CREATE OBC (object container) */
			/* ----------------------------- */
			if ((class->size) 
			&&  ((status = add_indirect_construction( resolve_object_container(object), object, (TCMEMBERPTR) 0, (TCMBMETHPTR) 0, mode )) != 0))
				return( status );
		}

		if ( mode & 2 ) 
		{
			/* ---------------------------------- */
			/* REMOVE IMT (indirect method table) */
			/* ---------------------------------- */
			if ((status = add_destruction_method(
				resolve_method_table( object), object, (TCMEMBERPTR) 0, (TCMBMETHPTR) 0, (TCTEXTPTR) 0, mode )) != 0)
				return( status );

			/* ----------------------------- */
			/* REMOVE OBC (object container) */
			/* ----------------------------- */
			if ((class->size)
			&&  ((status = add_destruction_method( 
				resolve_object_container( object ), object, (TCMEMBERPTR) 0, (TCMBMETHPTR) 0,(TCTEXTPTR) 0, mode )) != 0))
				return( status );
		}

	}

	return( 0 );
}

/*	------------------------	*/
/*	overlay_interface_method	*/
/*	------------------------	*/
WORD	overlay_interface_method( class, member, method )
TCSTRUCTPTR	class;
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	switch ( method->nature ) 
	{
	case	_CLASS_FUNCTION	:
		if (( method->options & _METHOD_INDIRECT )
		&&  ( build_function_method( class, member, method, 0 ) == (TCMBFUNCPTR) 0))
			return( allocation_failure() );
		else	return( 0 );
	}
	return( 0 );
}

/*	--------------------	*/
/*	base_class_componant	*/
/*	--------------------	*/
TCSTRUCTPTR	base_class_componant( member )
TCMEMBERPTR	member;
{
	TCMBDATAPTR	dptr;
	TCSTRUCTPTR	class;
	if (((dptr = (TCMBDATAPTR)member->special) != (TCMBDATAPTR) 0)
	&&  ( dptr->structname != (BPTR) 0)) 
	{
		if (( dptr->structure == (TCSTRUCTPTR) 0)
		&&  ((dptr->structure = known_structure( dptr->structname )) == (TCSTRUCTPTR) 0))
			(void) syntax_error( 4994 );
		else if (((class = dptr->structure) != (TCSTRUCTPTR) 0)
		     &&  ( member->hash == class->hash)
		     &&  ( compare_tokens( member->name, class->name ) ))
			return( class );
	}
	return( (TCSTRUCTPTR) 0 );
}

/*	------------------	*/
/*	create_eimt_vector	*/
/*	------------------	*/
static	WORD	create_eimt_vector( object, base, container, class, member, method )
TCVARPTR	object;		/* Current Overlay   Object 	*/
TCVARPTR	base;		/* Current Pseudo Base		*/
TCVARPTR	container;	/* Current Componant Object 	*/
TCSTRUCTPTR	class;		/* Class of object	    	*/
TCMEMBERPTR	member;		/* Current member node		*/
TCMBMETHPTR	method;		/* Method of this member	*/
{
	WORD		status=0;
	WORD		holder;
	TCVARPTR	procptr;
#ifdef	_TRACE_EIMT
	sysprintf("CreateEimtVector : %s %x(%x), %s %x(%x), %s %x(%x), %s.%s \n",
			object->name,
			object->identity,
			object->master,
			base->name,
			base->identity,
			base->master,
			container->name,
			container->identity,
			container->master,
			class->name,
			member->name);
#endif
	/* ------------------ */
	/* Create EIMT.vector */
	/* ------------------ */
	if ((procptr = resolve_member_componant( base, member )) == (TCVARPTR) 0)
		return( internal_error( 22001 ) );

	if (( method->options & _METHOD_STRICT )
	&&  ((procptr = resolve_method_pointer( procptr, method )) == (TCVARPTR) 0))
		return( internal_error( 22002 ) );

	if ((status = affect_function_pointer( procptr, object, member->class, member, method )) != 0)
		return( status );

	else if (( member->access & (_MEMBER_OVERLOAD | _MEMBER_VIRTUAL) )
	     &&  ((status = method_object_alias( procptr, container )) != 0))
		return( status );

	/* ----------------- */
	/* Create GDS Vector */
	/* ----------------- */
	holder = container->identity;

	if (( object->hash == container->hash )
	&&  ( compare_tokens( object->name, container->name ) ))
		container->identity = object->identity;

	if ((procptr = resolve_member_componant( container, member )) == (TCVARPTR) 0)
		return( internal_error( 22003 ) );

	else	container->identity = holder;

	if (( method->options & _METHOD_STRICT )
	&&  ((procptr = resolve_method_pointer( procptr, method )) == (TCVARPTR) 0))
		return( internal_error( 22004 ) );

	if ((status = affect_function_pointer( procptr, container, member->class, member, method )) != 0)
		return( status );
	else if (( member->access & (_MEMBER_OVERLOAD | _MEMBER_VIRTUAL) )
	     &&  ((status = method_object_alias( procptr, container )) != 0))
		return( status );

	return( 0 );
}

/*	------------	*/
/*	eimt_message	*/
/*	------------	*/
WORD	eimt_message( sptr )
BPTR	sptr;
{
	sysprintf( sptr );
	return( 1 );
}

/*	------------------------	*/
/*	resolve_member_container	*/
/*	------------------------	*/
TCVARPTR	resolve_member_container( master, object, member, level )
WORD	 	master;
TCVARPTR	object;
TCMEMBERPTR	member;
WORD		level;
{
	TCVARPTR	mptr;

	/* ------------------------------- */
	/* Locate Original Descriptor Node */
	/* ------------------------------- */
	while (object->parent != (TCVARPTR) 0)
		object = object->parent;

	if ( level )
		master = object->identity;

	mptr = object;

	/* ------------------------ */
	/* Locate Child Member Node */
	/* ------------------------ */
	while (( object = object->prev) != (TCVARPTR) 0 ) 
	{
		if (( object->master == master )
		&&  ( object->hash == member->hash )
		&&  ( compare_tokens( object->name, member->name )))
			return( temp_variable( object ) );
	}
	return((TCVARPTR) 0);
}

/*	-------------------	*/
/*	create_eimt_vectors	*/
/*	-------------------	*/
static	WORD	create_eimt_vectors( object, base, container, class, level )
TCVARPTR	object;		/* THIS Enhanced Overlay Object		*/
TCVARPTR	base;		/* Current Pseudo base			*/
TCVARPTR	container;	/* Current Container			*/
TCSTRUCTPTR	class;		/* Class of object			*/
WORD		level;
{
	WORD		status=0;
	TCMEMBERPTR	member;
	TCMBMETHPTR	method;
	TCSTRUCTPTR	sptr;
	TCVARPTR	componant;
	TCVARPTR	pseudobase;

	if ((object != (TCVARPTR) 0)
	&&  (class  != (TCSTRUCTPTR) 0)
	&&  ((member = class->first) != (TCMEMBERPTR) 0)) 
	{
		do	
		{
			if (!( member->access & _MEMBER_PUBLIC ))
				continue;
			if (!( member->nature )) 
			{
				if (((method = (TCMBMETHPTR) member->special) != (TCMBMETHPTR) 0)
				&&  ( method->nature == _CLASS_FUNCTION )
				&&  ( method->options & _METHOD_INDIRECT )
				&&  ( method->value != (TCTEXTPTR) 0)
				&&  ((status = create_eimt_vector( object, base, container, class, member, method )) != 0))
					return( status );
			}
			else if (( class->enhanced & _ENHANCED_INDIRECT )
			     &&  ( member->nature != _KW1_CONST )
			     &&  ((sptr = base_class_componant( member )) != (TCSTRUCTPTR) 0)
			     &&  ((pseudobase = resolve_member_componant( base, member )) != (TCVARPTR) 0)
			     &&  ((componant  = resolve_member_container( object->identity, container, member, level )) != (TCVARPTR) 0)
			     &&  ((status     = create_eimt_vectors( object, pseudobase, componant, sptr, (level+1) )) != 0))
				return( status );

		}
		while ((member = member->next) != (TCMEMBERPTR) 0);
		}
	return( status );
}

/*	---------------------	*/
/*	segment_pseudo_object	*/
/*	---------------------	*/
TCVARPTR	segment_pseudo_object( object, class, field )
TCVARPTR	object;
TCSTRUCTPTR	class;
WORD		field;
{
	RESULTPTR	rptr;
	RESULTPTR	tptr;
	WORD		status;

	if ((status = declare_instance( class, "THIS", (field == 0 ? _KW1_PTR : _KW1_DCL ), 0, 0, (VPTR) 0, field)) != 0)
		return((TCVARPTR) 0);
	else if ((object = Context->LDT->first) == (TCVARPTR) 0)
		return( object );
	else if ( object->type->size == 0 )
		return( object );

	if (!( field )) 
	{
		if ((tptr = variable_result(object)) == (RESULTPTR) 0)
			return((TCVARPTR) 0);
		else if ((rptr = next_free_register()) == (RESULTPTR) 0)
			return((TCVARPTR) 0);
		rptr->nature   = _RESULT_EXPR;
		rptr->contents = (VPTR) set_shadow_type( rptr->contents, (object->type->type & _TYPE_BASIC)  );
		generate_copy_register( rptr->value, _EXIT_REGISTER );
		if ((status = clf_alias(tptr, rptr)) != 0)
			return((TCVARPTR) 0);
	}
	return( object );
}

/*	------------------------	*/
/*	resolve_object_container	*/
/*	------------------------	*/
TCVARPTR	resolve_object_container( object )
TCVARPTR	object;
{
	TCVARPTR	container;

	if (( object != (TCVARPTR) 0)
	&&  ((container = object->prev) != (TCVARPTR) 0)) 
	{
		/* --------------------------------------- */
		/* Step over possible procedure parameters */
		/* --------------------------------------- */
		while (1) 
		{
			while (( container != (TCVARPTR) 0)
			   &&  ( container->type->type & _TYPE_PARAMETER ))
				container = container->prev;
			if ( container == (TCVARPTR) 0 )
				return( container );
			else if ((container->hash == object->hash)
			     &&  (compare_tokens( container->name, object->name)))
				break;
			else	container = container->prev;
		}

		/* --------------------- */
		/* Container is the EIMT */
		/* --------------------- */
		while (1) 
		{
			if ((container = container->prev) == (TCVARPTR) 0)
				break;
			else if ((container->hash == object->hash)
			     &&  (compare_tokens( container->name, object->name)))
				break;
		}
	}
	return( container );
}

/*	-----------------	*/
/*	 reallocate_eimt	*/
/*	-----------------	*/
static	WORD	reallocate_eimt( object, imtptr )
TCVARPTR	object;
TCVARPTR	imtptr;
{
	RESULTPTR	lptr;
	RESULTPTR	rptr;
	WORD		status;
	WORD		entry;
	if ((object = resolve_method_table( object )) == (TCVARPTR) 0)
		return( syntax_error( 5885 ) );
	else if ((rptr = variable_result( object )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((lptr = variable_result( imtptr )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else if ((status = clf_forget( lptr )) != 0)
		return( status );
	else if ((status = clf_alias( lptr, rptr )) != 0)
		return( status );
	else if ((status = clf_create( rptr )) != 0)
		return( status );

	for (entry = 1; entry <= 2; entry++ ) 
	{
		if ((lptr = integer_result( entry )) == (RESULTPTR) 0)
			return( allocation_failure() );
		else	
		{
			imtptr->firstdim = (VPTR)lptr;
			object->firstdim = (VPTR) lptr;
		}
		if ((status = variable_to_variable( imtptr, object )) != 0 )
			return( status );
	}
	imtptr->firstdim = (VPTR) 0;
	object->firstdim = (VPTR) 0;
	if ((lptr = variable_result( imtptr )) == (RESULTPTR) 0)
		return( allocation_failure() );
	else 	return( clf_remove( lptr ) );
}

/*	------------------	*/
/*	declare_imt_holder	*/
/*	------------------	*/
static	TCVARPTR	declare_imt_holder()
{
	WORD		status;

	/* ------------------------------------ */
	/* Declare Indirect Method Table Holder */
	/* ------------------------------------ */
	if ((status = dcl_variable( 
			"OIMT",				/* Variable name 	*/
			(_TYPE_FIRST | _TYPE_STRING),	/* Table Type	*/
			5,				/* EIMT size 		*/
			2,				/* 1st dimension	*/
			1,				/* 2nd dimension 	*/
			_KW1_PTR, 			/* DCL, PTR, OVL 	*/
			0,1, 0 )) != 0)
		return( (TCVARPTR) 0);
	else	return( Context->GDT->variable );
}

/*	------------------------	*/
/*	enhanced_preconstruction	*/
/*	------------------------	*/
static	WORD	enhanced_preconstruction( class )
TCSTRUCTPTR	class;
{
	WORD		status=0;
	TCMBFUNCPTR	function;
	TCVARPTR	object;
	TCVARPTR	holder;

	if ((function = FunctionHeap) != (TCMBFUNCPTR) 0) 
	{
		if ((holder = declare_imt_holder()) == (TCVARPTR) 0)
			return( syntax_error( 6008 ) );

		function->status = VRAI;
		class->access |= _MEMBER_OVERLAY;

		if (((status = start_procedure( function->procedure, FAUX )) == 0)
		&&  ((status = enter_procedure_translation()) == 0)) 
		{
			if (((object = Context->LDT->first) != (TCVARPTR) 0)
			&&  ((status = reallocate_eimt( object, holder )) == 0)
			&&  ((status = create_eimt_vectors( object, object, resolve_object_container( object ), class, 0 )) == 0))
				status = receive_common_linkage(object->prev,class );

			status += terminate_procedure();

			leave_segmental_translation();

		}
		class->access &= ~_MEMBER_OVERLAY;
	}
	return( status );
}

/*	------------------------	*/
/*	standard_preconstruction	*/
/*	------------------------	*/
static	WORD	standard_preconstruction( class )
TCSTRUCTPTR	class;
{
	WORD		status=0;
	TCMBFUNCPTR	function;

	if ((function = FunctionHeap) != (TCMBFUNCPTR) 0) 
	{

		function->status = VRAI;

		if (((status = start_procedure( function->procedure, FAUX )) == 0)
		&&  ((status = enter_procedure_translation()) == 0)) 
		{

			status = receive_common_linkage(Context->LDT->first->prev, class );
			status += terminate_procedure();

			leave_segmental_translation();

		}
	}
	return( status );
}

/*	------------------------	*/
/*	generate_preconstruction	*/
/*	------------------------	*/
static	WORD	generate_preconstruction( class )
TCSTRUCTPTR	class;
{
	if ( class->enhanced & _ENHANCED_INDIRECT )
		return( enhanced_preconstruction( class ) );
	else	return( standard_preconstruction( class ) );		
}

/*	------------------------	*/
/*	common_interface_methods	*/
/*	------------------------	*/
static	WORD	common_interface_methods( class )
TCSTRUCTPTR	class;
{
	TCMEMBERPTR	member;
	TCMBMETHPTR	method;
	WORD		number;
	WORD		status=0;

	for ( number= 1; number <= 2; number++ ) 
	{
		if ((method = build_overlay_interface( class, number )) == (TCMBMETHPTR) 0)
			return( allocation_failure() );

		if ((status = activate_method_target( method )) != 0 )
			return( status );

		push_operation_pointer();

		sprintf(TokenBuffer,"OCIM%u",number);

		if (((status = put_method_string("Exit")) != 0)
		||  ((status = put_method_byte('\n')) != 0)
		||  ((status = terminate_method_text()) != 0))
			return( status );

		if ((member = allocate_structure_member( TokenBuffer )) == (TCMEMBERPTR) 0)
			return( allocation_failure() );

		member->special = (VPTR)method;

		if ((status = overlay_interface_method( class, member, method )) != 0)
			return( status );
	}

	/* ---------------------------------------------------------- */
	/* Cancel OVERLAY status of class for ENHANCED mode operation */
	/* ---------------------------------------------------------- */
	if ( class->enhanced & _ENHANCED_INDIRECT )
		class->access &= ~_MEMBER_OVERLAY;

	return(status);
}

/*	-------------------------	*/
/*	overlay_interface_methods	*/
/*	-------------------------	*/
WORD	overlay_interface_methods( class )
TCSTRUCTPTR	class;
{
	TCMEMBERPTR	member;
	TCMBMETHPTR	method;
	WORD		status;
	TCSTRUCTPTR	sptr;

	if (( class != (TCSTRUCTPTR) 0 )
	&&  ((member = class->first) != (TCMEMBERPTR) 0)) 
	{
		do	
		{
			if (!( member->access & _MEMBER_PUBLIC ))
				continue;
			if (!( member->nature )) 
			{
				if (((method = (TCMBMETHPTR) member->special) != (TCMBMETHPTR) 0)
				&&  ( method->value != (TCTEXTPTR) 0)
				&&  ((status = overlay_interface_method( class, member, method )) != 0))
					return( status );
			}
			else if (( class->enhanced & _ENHANCED_INDIRECT )
			     &&  ( member->nature != _KW1_CONST )
			     &&  ((sptr = base_class_componant( member )) != (TCSTRUCTPTR) 0)
			     &&  ((status = overlay_interface_methods( sptr )) != 0))
				return( status );
		}
		while ((member = member->next) != (TCMEMBERPTR) 0);
	}
	return( 0 );
}

#include "trinform.c"

/*	-------------------------	*/
/*	 instance_overlay_object	*/
/*	-------------------------	*/
static	WORD	instance_overlay_object( class )
TCSTRUCTPTR	class;
{
	WORD		status;
	trace("instance_overlay_object()\n");
	if ((status = common_interface_methods( class )) != 0)
		return( status );
	else if ((status = overlay_interface_methods( class )) != 0)
		return( status );
	else if ((status = generate_preconstruction( class )) != 0)
		return( status );
	else if ((status = add_segment( 0, 0, (BPTR) 0,VRAI)) != 0 )
		return( status );
	else if ((status = enter_segmental_translation()) != 0)
		return( status );
	else if ((status = mark_variable( Context->GDT->first )) != 0)
		return( status );
	else if ((status = allow_construction()) != 0)
		return( status );
	else if ((status = overlay_identification( class )) != 0)
		return( status );
	else if ((status = terminate_segment( 0, (BPTR) 0,0)) != 0)
		return( status );
	leave_segmental_translation();
	return( 0 );
}

/*	-------------------------	*/
/*	 instance_program_object	*/
/*	-------------------------	*/
static	WORD	instance_program_object( class )
TCSTRUCTPTR	class;
{
	WORD	status;

	trace("instance_program_object()\n");
	if ((status = add_segment( 0, 0, (BPTR) 0,VRAI)) != 0 )
		return( status );
	else if ((status = enter_segmental_translation()) != 0)
		return( status );
	else if ((status = allow_construction()) != 0)
		return( status );
	else if ((status = terminate_segment( 0, (BPTR) 0,0)) != 0)
		return( status );
	leave_segmental_translation();
	return( 0 );
}

/*	-------------------	*/
/*	declare_overlay_gds	*/
/*	-------------------	*/
static	WORD	declare_overlay_gds( class )
TCSTRUCTPTR	class;
{
	WORD		status;
	WORD		occupation=0;
	TCVARPTR	variable=(TCVARPTR) 0;

	if ((occupation = structure_occupation( class )) != 0) 
	{
		/* ------------------------------------ */
		/* Declare Indirect Method Table Holder */
		/* ------------------------------------ */
		if ((status = dcl_variable(
				class->name,		/* Dcl  name 	 */
				_TYPE_STRING,		/* Table Type	 */
				occupation,		/* GDS  size 	 */
				1,			/* 1st dimension */
				1,			/* 2nd dimension */
				_KW1_DCL, 		/* DCL, PTR, OVL */
				0,1, 0 )) != 0)
			return( status );

		else	variable = Context->GDT->variable;

	}

	/* Save Current field for COMMON instancing after GDS object */
	/* --------------------------------------------------------- */
	if ((status = flush_world_members()) != 0)
		return( status );
	else 	
	{
		field_equals_m();
		field_equals_s();
		if ( occupation )
			return( redefine_base_variable( variable ) );
		else	return( 0 );
	}
}

/*	-----------------	*/
/*	 declare_ocx_gds	*/
/*	-----------------	*/
WORD	declare_ocx_gds( class )
TCSTRUCTPTR	class;
{
	return( syntax_error( 0xFFFE ) );
}

/*	-------------------	*/
/*	instance_ocx_object	*/
/*	-------------------	*/
WORD	instance_ocx_object( class )
TCSTRUCTPTR	class;
{
	return( syntax_error( 0xFFFE ) );
}

/*	----------------	*/
/*	instance_program	*/
/*	----------------	*/
WORD	instance_program( nptr )
BPTR	nptr;
{
	TCSTRUCTPTR	class;
	TCTEXTPTR	valptr=(TCTEXTPTR) 0;
	BYTE		vname[_MAX_OTR_TOKEN+1];
	WORD		status;
	WORD		master=0;
	WORD		nature=_KW1_OBJ;

#ifdef WIN32
	MI_TRACE_DCL_TFN("instance_program");
#else
	trace("instance_program()\n");
#endif

	if ((class = known_structure( nptr )) == (TCSTRUCTPTR) 0)
		return( syntax_error( 1002 ) );
	else if ((!( get_token() )) ||  (!( copy_token( vname, 32 ) )))
		return( syntax_error( 1003 ) );

	if ((class->access & _MEMBER_INDIRECT)
	&&  (!(class->enhanced & _ENHANCED_INDIRECT)))
		nature = _KW1_IND;

	if (( class->nature == _KW1_CLASS )
	&&  ( is_left_brace()            )
	&&  ((valptr = collect_construction_parameters()) == (TCTEXTPTR) 0))
		return( allocation_failure() );
	else if ((status = field_equals_m()) != 0)
		return( status );

	if ( context_is_overlay ) 
	{
		class->access &= ~_MEMBER_OVERLAY;
		if ((status = declare_overlay_gds( class )) != 0)
			return( status );
		if ( class->size ) 
		{
			/* Possible Bug Here : May be last common object */
			master = Context->GDT->descriptor;
			nature  = _KW1_DCL;
		}
		else	master = MOINS_UN;
	}
	else if ( context_is_ocx ) 
	{
		if ((status = declare_ocx_gds( class )) != 0 )
			return( status );
	}		
	else if ((status = flush_world_members()) != 0)
		return( status );

	if (( master != MOINS_UN )
	&&  ((status = declare_structure( class, vname, nature, 0, master, valptr, 0 )) != 0))
		return( status );

	valptr = liberate_text_value( valptr );

	if ( context_is_overlay ) 
	{
		field_equals_r();
		class->access |= _MEMBER_OVERLAY;
		return( instance_overlay_object( class ) );
	}
	else if ( context_is_ocx ) 
		return( instance_ocx_object( class ) );
	else	return( instance_program_object( class ) );
}

/*	-----------------	*/
/*	 instance_module	*/
/*	-----------------	*/
WORD	instance_module( nptr )
BPTR	nptr;
{
	TCSTRUCTPTR	sptr;
	TCTEXTPTR	valptr=(TCTEXTPTR) 0;
	BYTE		vname[_MAX_OTR_TOKEN+1];
	WORD		status;
	TCVARPTR	object;

	trace("instance_module()\n");

	if ((sptr = known_structure( nptr )) == (TCSTRUCTPTR) 0)
		return( syntax_error( 1002 ) );

	tcode_program_identity();

	sptr->access &= ~_MEMBER_EXTERN;

	if ((!( get_token() ))
	||  (!( copy_token( vname, 32 ) )))
		return( syntax_error( 1003 ) );

	if (( sptr->nature == _KW1_CLASS )
	&&  ( is_left_brace()            )
	&&  ((valptr = collect_construction_parameters()) == (TCTEXTPTR) 0))
		return( allocation_failure() );

	/* ------------------------------------------ */
	/* Cancel Constructor / Destructor Collection */
	/* ------------------------------------------ */
	ModuleObject = VRAI;

	/* -------------------------- */
	/* Instance the Module Object */
	/* -------------------------- */
	object = Context->GDT->variable;

	status = declare_structure( sptr, vname, _KW1_DCL, 0, 0, valptr, 0 );

	if ( object == (TCVARPTR) 0 )
		object = Context->GDT->first;

	/* -------------------------------------------- */
	/* Reactivate Constructor Destructor Collection */
	/* -------------------------------------------- */
	ModuleObject = FAUX;

	valptr = liberate_text_value( valptr );

	if ( status )	
		return( status );
	else	return( declare_module_methods( object, sptr ) );
}

/*	-----------------	*/
/*	object_occupation	*/
/*	-----------------	*/
WORD	object_occupation( class )
TCSTRUCTPTR	class;
{
	if ((!( class->enhanced & _ENHANCED_INDIRECT ))
	&&   ( class->access & _MEMBER_OVERLAY ))
		return( 10 );
	else	return( class->size );
}

/*	--------------------	*/
/*	parameter_occupation	*/
/*	--------------------	*/
WORD	parameter_occupation( class )
TCSTRUCTPTR	class;
{
	/*
	 * -------------------------------------------------------------------------
	 * Correction 12/08/1996 to ensure that procedures instanced for methods of 
	 * classes which have been stored in APL class libraries do not generate
	 * parameter instance variables of zero size when first referencing a class
	 * for which the size has not yet been determined (IJM) 
	 * -------------------------------------------------------------------------
	 */
	if ((!( class->enhanced & _ENHANCED_INDIRECT ))
	&&   ( class->access & _MEMBER_OVERLAY ))
		return( 10 );
	else if ( class->size )
		return( class->size );
	else	return( structure_occupation( class ) );
}

/*------------------------------	*/
/*	translate_object_message	*/
/*------------------------------	*/
WORD	translate_object_message()
{
	TCVARPTR	object;
	WORD		status;

	if (context_is_module)
		return( MOINS_UN );

	else if ((object = is_object()) != (TCVARPTR) 0) 
	{
		while( object->parent != (TCVARPTR) 0 )
			object = object->parent;
		if ((status = implicite_segment_zero()) != 0)
			return( status );
		else	
		{
			signal_new_line(0);
			return( translate_instruction( object ) );
		}
	}
	else	return( MOINS_UN );
}

/*	-------------------------	*/
/*	 allocate_for_genericity	*/
/*	-------------------------	*/
GENERICPTR	allocate_for_genericity( oldclass, newclass )
TCSTRUCTPTR	oldclass;
TCSTRUCTPTR	newclass;
{
	GENERICPTR	gptr;

	if ((gptr = (GENERICPTR) allocate( sizeof( struct tcode_generic ) )) != (GENERICPTR) 0) 
	{
		gptr->old  = oldclass;
		gptr->new  = newclass;
		gptr->next = (GENERICPTR) 0;
	}
	return( gptr );
}

/*	-------------------------	*/
/*	 liberate_for_genericity	*/
/*	-------------------------	*/
VOID	liberate_for_genericity( gptr )
GENERICPTR	gptr;
{
	GENERICPTR	xptr;
	while ((xptr = gptr) != (GENERICPTR) 0) 
	{
		gptr = gptr->next;
		liberate( xptr );
	}
	return;
}

/*	-----------------	*/
/*	 copy_genericity	*/
/*	-----------------	*/
GENERICPTR	copy_genericity( xptr )
GENERICPTR	xptr;
{
	GENERICPTR	root=(GENERICPTR) 0;
	GENERICPTR	last=(GENERICPTR) 0;
	GENERICPTR	gptr=(GENERICPTR) 0;

	while ( xptr != (GENERICPTR) 0 ) 
	{
		if ((gptr = allocate_for_genericity( xptr->old, xptr->new )) == (GENERICPTR) 0) 
		{
			(void) allocation_failure();
			break;
		}
		else if ( last != (GENERICPTR) 0 )
			last->next = gptr;
		else	root       = gptr;
		last = gptr;
		xptr = xptr->next;
	}
	return( root );
}

#ifdef	DEBUG_OBJ_OCCUPATION
/*	-----------------	*/
/*	object_occupation	*/
/*	-----------------	*/
WORD	object_occupation( class )
TCSTRUCTPTR	class;
{
	WORD	size;
	if ( OtrOption.Verbose & 8 )
		sysprintf("Object(%s) Occupation : ",class->name);
	size = ll_object_occupation( class );
	if ( OtrOption.Verbose & 8 )
		sysprintf("%u \n",size);
	return( size );
}
#endif

	/* ----------- */
#endif	/* _TROBJECT_C */
	/* ----------- */


