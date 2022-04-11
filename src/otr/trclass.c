/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990, 1995 Amenesik / Sologic s.a.       */
/*                                                                      */
/*                                                                      */
/*              File    :       TRCLASS.C                               */
/*              Version :       2.1d                                    */
/*              Date    :       23/02/1995                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
#ifndef _TRCLASS_C
#define _TRCLASS_C

#undef 	DEBUG_TRACE_ACTIVE
#define DEBUG

#include <stdio.h>              /* Standard IO handling routines        */
#include <errno.h>              /* Error return definitions             */
#include <string.h>             /* string function definitions          */
#include "stdtypes.h"
#include "translat.h"
#include "trparser.h"
#include "trsyntax.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trtables.h"
#include "trexpres.h"
#include "trshadow.h"
#include "trlabels.h"
#include "triter.h"
#include "trinput.h"
#include "trclf.h"
#include "trclass.h"
#include "trmethod.h"
#include "trmember.h"
#include "trecho.h"
#include "trdebug.h"
#include "trmethod.h"	
#include "trproc.h"		
#include "trcommon.h"	
#include "trdirect.h"	
#include "triof.h"			
#include "troutput.h"	
#include "trabal.h"			
#include "trldf.h"			
#include "trmain.h"			

EXTERN  BYTE    TokenBuffer[];

WORD    ModuleObject=0;
WORD    ListMemberCounter=0;

#ifndef UNIX
static  VOID    reset_class_options( VOID );
static  WORD    translate_inherit( VOID );
static  WORD    translate_terminal_data( VOID );
static  WORD    translate_implicite_member( VOID );
static  WORD    translate_member( VOID );
static  WORD    ll_translate_base_class( VOID );
static  WORD    translate_base_class( VOID );
static  WORD    basic_return_type( WORD );
static  WORD    translate_method_pointer( VOID );
static  WORD    translate_data_pointer( VOID );
static  WORD    translate_pointer( VOID );
static  translate_keyword_class( VOID );
#else
WORD            compare_classes();
TCDLBPTR        locate_dynamic_library();
RESULTPTR       build_string_constant();
TCVARPTR        collect_typed_parameters();
WORD            translate_class_keyword();
#endif

/*	---------------------	*/
/*	reset_oneshot_options	*/
/*	---------------------	*/
VOID    reset_oneshot_options()
{
	trace("reset_oneshot_options()\n");
	ClassOptions.CallBack   = 0;
	ClassOptions.Resident   = 0;
	ClassOptions.Strict     = 0;
	ClassOptions.Static     = 0;
	ClassOptions.Protect    = 0;
	ClassOptions.Direct     = 0;
	ClassOptions.Virtual    = 0;
	ClassOptions.Overload   = 0;
	ClassOptions.Method     = 0;
	ClassOptions.Special    = 0;
	ClassOptions.Common     = 0;
	ClassOptions.Extern     = 0;
	ClassOptions.Type       = 0;
	ClassOptions.Size       = 0;
	ClassOptions.Declare    = 0;
	ClassOptions.Local      = 0;
	ClassOptions.Number     = MOINS_UN;
	Context->Visibility &= _MEMBER_ACCESS;
	translate_dynamic_keyword();
	ClassOptions.ReturnType = (TCTYPPTR) 0;
	return;
}

/*	-----------------	*/
/*	 set_class_local	*/
/*	-----------------	*/
WORD    set_class_local()
{
	if ( ClassOptions.Local )
		return( syntax_error( 5231 ) );
	else    
	{
		ClassOptions.Local = VRAI;
		return( 0 );
	}
}

/*	-----------------	*/
/*	set_method_target	*/
/*	-----------------	*/
VOID            set_method_target( vptr )
VALUEPTR        vptr;
{
	ClassOptions.MethodText = vptr;
	return;
}

/*	-------------------	*/
/*	reset_class_options	*/
/*	-------------------	*/
static  VOID    reset_class_options()
{
	trace("reset_class_options()\n");
	ClassOptions.Public  = _CLASS_PRIVATE;
	Context->Visibility  = _MEMBER_PRIVATE;
	set_method_target( (VALUEPTR) 0 );
	ClassOptions.WorkingMethod = (VPTR) 0;
	translate_private();
	reset_oneshot_options();
	return;
}

/*	------------------------------------------------------------	*/
/*			method_requires_parameters			*/
/*	------------------------------------------------------------	*/
/*      Called during method signature translation when explicite	*/
/*      method parameters have not been detected to ensure that the	*/
/*      method type does not require parameters.			*/
/*									*/
/*      Currently only OPERATOR methods oblige parameters.		*/
/*	------------------------------------------------------------	*/
WORD    method_requires_parameters()
{
	switch ( ClassOptions.Special ) 
	{
	case _CLASS_OPERATOR    :
		return( syntax_error( 1878 ) );
	default                 :
		return( 0 );
	}
}

/*	-----------------------------------------------------------	*/
/*			method_allows_parameters			*/
/*	-----------------------------------------------------------	*/
/*      Called during method signature translation when explicite	*/
/*      method parameters have been detected to ensure that the		*/
/*      method type allows parameters.					*/
/*									*/
/*      Warnings :							*/
/*              ROUTINE converted to INLINE     (W5)			*/
/*              OVERLAY converted to FUNCTION   (W6)			*/
/*									*/
/*      Errors   :							*/
/*              EXCEPTION, PRECONDITION, POSTCONDITION, INVARIANT	*/
/*              methods do not allow explicite parameters (A10001)	*/
/*	-----------------------------------------------------------	*/

WORD    method_allows_parameters()
{
	switch ( ClassOptions.Method ) 
	{
	case    _CLASS_ROUTINE :
		ClassOptions.Method = _CLASS_INLINE;
		issue_warning(5);
		break;

	case    _CLASS_OVERLAY :
		ClassOptions.Method = _CLASS_FUNCTION;
		issue_warning(6);
		break;
	}

	switch ( ClassOptions.Special ) 
	{
	case _CLASS_EXCEPTION           :
	case _CLASS_INVARIANT           :
	case _CLASS_PRECONDITION        :
	case _CLASS_POSTCONDITION       :
		return( syntax_error( 1877 ) );
	default                         :
		return( 0 );
	}
}

/*	-----------------	*/
/*	translate_inherit	*/
/*	-----------------	*/
static  WORD    translate_inherit()
{
	trace("translate_inherit()\n");
	if ( get_token() )
		return( inherit_struct( TokenBuffer ) );
	else    return( syntax_error(800) );
}

/*	--------------------	*/
/*	terminate_macro_text	*/
/*	--------------------	*/
WORD	terminate_macro_text()
{
	if ( ClassOptions.MethodText != (VALUEPTR) 0 ) 
	{
		pop_operation_pointer();
		ClassOptions.MethodText = (VALUEPTR) 0;
		ClassOptions.WorkingMethod = (VPTR) 0;
	}
	return(0);
}

/*	---------------------	*/
/*	terminate_method_text	*/
/*	---------------------	*/
WORD	terminate_method_text()
{
	trace("terminate_method_text()\n");
	reset_oneshot_options();
	terminate_macro_text();
	return(0);
}

#include "trobject.c"
#include "trmbuser.c"

/*	-------------------------	*/
/*	 translate_terminal_data	*/
/*	-------------------------	*/
static  WORD    translate_terminal_data()
{
	WORD    status=0;
	trace("translate_terminal_data()\n");
	if ( get_token() ) 
	{
		while ( 1 ) 
		{
			ListMemberCounter++;
			if ((status = translate_variable(_KW1_DCL,0)) != 0 )
				break;
			else if ( is_comma() ) 
			{
				if ( get_token() )
					continue;
				else    return( 0 );
			}
			else    
			{
				status = verify_end_of_line();
				break;
			}
		}
		ListMemberCounter = 0;
	}
	else if ( ListMemberCounter != 0 )
		status = syntax_error(801);

	pop_operation_pointer();
	reset_oneshot_options();
	return( status );
}

/*	--------------------------	*/
/*	translate_implicite_member	*/
/*	--------------------------	*/
static  WORD    translate_implicite_member()
{
	WORD    status;

	if ( is_colon() )
		status = translate_method();
	else if ( ClassOptions.Method )
		status = syntax_error(802);
	else if ( ClassOptions.ReturnType != (TCTYPPTR) 0 )
		status = translate_pointer_method();
	else if ( ClassOptions.Type )
		status = syntax_error(803);
	else    
	{
		if (!( ClassOptions.Declare ))
			ClassOptions.Declare = _KW1_DCL;
		if ((status = translate_variable(ClassOptions.Declare,0)) == 0 ) 
		{
			if ( is_comma() ) 
			{
				push_operation_pointer();
				set_operation_pointer(translate_terminal_data);
				ListMemberCounter = 0;
				return( translate_terminal_data() );
			}
			else    status = verify_end_of_line();
		}
	}
	reset_oneshot_options();
	return( status );
}

/*	----------------	*/
/*	translate_member	*/
/*	----------------	*/
static  WORD    translate_member()
{
	WORD    status;
	status = translate_implicite_member();
	return( status );
}

/*	------------------------	*/
/*	 ll_translate_base_class	*/
/*	------------------------	*/
static  WORD    ll_translate_base_class()
{
	WORD    status=0;
	WORD    nature=_KW1_DCL;

	trace("translate_base_class()\n");

	if ( get_token() ) 
	{
		while (1) 
		{
			switch ( is_class_keyword() ) 
			{
			case    _CLASS_OVERLAY  :
				nature = _KW1_OVL;
				if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    _CLASS_POINTER  :
				nature = _KW1_PTR;
				if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;
					
			case    _CLASS_STATIC   :
				if ((status = translate_static_keyword()) != 0)
					return( status );
				else if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    _CLASS_DYNAMIC  :
				if ((status = translate_dynamic_keyword()) != 0)
					return( status );
				else if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    _CLASS_PRIVATE  :
				if ((status = translate_private()) != 0)
					return( status );
				else if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    _CLASS_PUBLIC   :
				if ((status = translate_public()) != 0)
					return( status );
				else if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    _CLASS_VIRTUAL  :
				if ((status = translate_virtual()) != 0)
					return( status );
				else if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    _CLASS_COMMON   :
				if ((status = translate_common()) != 0)
					return( status );
				else if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    _CLASS_INHERIT  :

				if (!( get_token() ))
					return( syntax_error(804) );
				else    continue;

			case    MOINS_UN :
				ListMemberCounter++;
				if ((status = translate_base_instance(nature)) == MOINS_UN)
					return( syntax_error(810) );
				else if ( status != 0 )
					return( status );
				nature = _KW1_DCL;
				if ( is_comma() ) 
				{
					reset_oneshot_options();
					if ( get_token() )
						continue;
					else    return( 0 );
				}
				else    break;

			default                 :
				return( syntax_error(811) );
			}
			break;
		}
		ListMemberCounter = 0;
	}

	if (!( is_right_brace() ))
		return( 0 );

	pop_operation_pointer();

	return( status );
}

/*	--------------------	*/
/*	translate_base_class	*/
/*	--------------------	*/
static  WORD    translate_base_class()
{
	WORD    status;
	status = ll_translate_base_class();
	reset_oneshot_options();
	return( status );
}

/*	-----------------	*/
/*	basic_return_type	*/
/*	-----------------	*/
static  WORD    basic_return_type( t )
WORD    t;
{
	if ( ClassOptions.Method )
		return( syntax_error( 1070 ) );
	if ( ClassOptions.Type )
		return( syntax_error(813) );

	trace("basic_return_type()\n");

	switch ((ClassOptions.Type = t)) 
	{
	case    _TYPE_INT16 	: ClassOptions.Size =  2; break;
	case    _TYPE_INT32 	: ClassOptions.Size =  4; break;
	case    _TYPE_INT64 	: ClassOptions.Size =  8; break;
	case    _TYPE_NUMERIC 	: ClassOptions.Size = 12; break;
	case    _TYPE_STRING	: ClassOptions.Size = 15; break;
	}
	return( 0 );
}

/*	---------------------	*/
/*	remove_useless_length	*/
/*	---------------------	*/
WORD	remove_useless_length()
{
	if (!( is_equals() ))
		return(0);
	else	return( get_token() );
}

/*	------------------	*/
/*	analyse_basic_type	*/
/*	------------------	*/
WORD    analyse_basic_type()
{
	WORD    type;
	WORD    basic_type=0;

	switch ((type = is_class_keyword())) 
	{

	case    _CLASS_INTEGER  :
#ifdef	otr64
		basic_type = _TYPE_INT64;
#else
#ifdef	otr32
		basic_type = _TYPE_INT32;
#else
		basic_type = _TYPE_INT16;
#endif
#endif
		break;

	case    _CLASS_STRING   :
		basic_type = _TYPE_STRING;
		remove_useless_length();
		break;

	case    _CLASS_NUMERIC  :
		basic_type = _TYPE_NUMERIC;
		remove_useless_length();
		break;

	case    MOINS_UN        :
		return( MOINS_UN );

	default :
		return( 0 );

	}

	if ( is_mnemonic("POINTER") )
		basic_type |= _TYPE_POINTER;

	return( basic_type );
}

/*	------------------------	*/
/*	translate_method_pointer	*/
/*	------------------------	*/
static  WORD    translate_method_pointer()
{
	WORD    type=0x0003;
	trace("translate_method_pointer()\n");
	switch ( ClassOptions.Method ) 
	{
	case    _CLASS_OVERLAY  :
		type |= 0x8100;
		break;
	case    _CLASS_USER     :
		type |= 0x8200;
		break;
	case    _CLASS_FUNCTION :
		type |= 0x8400;
		break;
	default                 :
		ClassOptions.Declare = _KW1_PTR;
		return( 0 );
	}

	if ( is_mnemonic("POINTER") )
		type |= _TYPE_POINTER;
	if (( ClassOptions.ReturnType = allocate_for_type( type, OtrOption.PointerSize, 1, 1, ClassOptions.ReturnType )) == (TCTYPPTR) 0)
		return( allocation_failure() );
	ClassOptions.Method = 0;
	return( 0 );
}

/*	----------------------	*/
/*	translate_data_pointer	*/
/*	----------------------	*/
static  WORD    translate_data_pointer()
{
	trace("translate_data_pointer()\n");

	if (!( ClassOptions.Method ))
		ClassOptions.Type |= _TYPE_POINTER;
	if (( ClassOptions.ReturnType = allocate_for_type( ClassOptions.Type, ClassOptions.Size, 1, 1, ClassOptions.ReturnType )) == (TCTYPPTR) 0)
		return( allocation_failure() );
	ClassOptions.Type = 0;
	ClassOptions.Size = 0;
	if ( ClassOptions.Method )
		return( translate_method_pointer());
	else    return( 0 );
}

/*	-----------------	*/
/*	translate_pointer	*/
/*	-----------------	*/
static  WORD    translate_pointer()
{
	trace("translate_pointer()\n");
	if ( ClassOptions.Type )
		return( translate_data_pointer() );
	else if ( ClassOptions.Method )
		return( translate_method_pointer() );
	else if (!( ClassOptions.Declare )) 
	{
		ClassOptions.Declare = _KW1_PTR;
		return( 0 );
	}
	else    return( syntax_error(815) );
}

/*	-------------------	*/
/*	translate_class_dll	*/
/*	-------------------	*/
WORD    translate_class_dll()
{
	TCSTRUCTPTR     class;

	trace("translate_class_dll()\n");
	if ((class = World->CurrentStructure) == (TCSTRUCTPTR) 0)
		return( syntax_error(6200) );
	else if (class->dll != (TCDLBPTR) 0)
		return( syntax_error(6201) );
	else if (!( get_filename() ))
		return( syntax_error(6202) );
	else if ((class->dll = locate_dynamic_library(TokenBuffer)) == (TCDLBPTR) 0)
		return( syntax_error(6203) );
	else    return( 0 );
}

/*	----------------	*/
/*	translate_strict	*/
/*	----------------	*/
WORD    translate_strict()
{
	if (( ClassOptions.Strict ) 
	&&  ( ClassOptions.Strict == _CLASS_STRICT ))
		return( syntax_error(817) );
	else    
	{
		ClassOptions.Strict = _CLASS_STRICT;
		return(0);
	}
}

/*	-----------------	*/
/*	 translate_relax	*/
/*	-----------------	*/
WORD    translate_relax()
{
	if (( ClassOptions.Strict )
	&&  ( ClassOptions.Strict == _CLASS_RELAX ))
		return( syntax_error(817) );
	else    
	{
		ClassOptions.Strict = _CLASS_RELAX;
		return(0);
	}
}

/*	-------------------------	*/
/*	 translate_class_keyword	*/
/*	-------------------------	*/
WORD    translate_class_keyword()
{
	WORD    status;
	WORD    type;

	if ((type = is_class_keyword()) == _CLASS_CALLBACK) 
	{
		if ( ClassOptions.CallBack )
			return( syntax_error(826) );
		else    
		{
			ClassOptions.CallBack = type;
			type = _CLASS_VIRTUAL;
		}
	}

	switch ( type ) 
	{
	case    _CLASS_INHERIT          :
		status = translate_inherit();
		reset_oneshot_options();
		return( status );

	case    _CLASS_PUBLIC           :
		ClassOptions.Public = type;
		return(translate_public());

	case    _CLASS_PRIVATE          :
		ClassOptions.Public = type;
		return( translate_private() );
		break;

	case    _CLASS_PROTECT          :
		if ( ClassOptions.Protect )
			return( syntax_error(816) );
		else    
		{
			ClassOptions.Protect = type;
			return( translate_protect() );
		}

	case    _CLASS_GENERIC          :
		return( 0 );

	case    _CLASS_COMMON           :
		if ( ClassOptions.Common )
			return( syntax_error(818) );
		else    
		{
			ClassOptions.Common = type;
			return( translate_common() );
		}

	case    _CLASS_EXTERN           :
		if ( ClassOptions.Extern )
			return( syntax_error(819) );
		else    ClassOptions.Extern = type;
		return( 0 );

	case    _CLASS_RESIDENT         :
		if ( ClassOptions.Resident )
			return( syntax_error(826) );
		else    ClassOptions.Resident = type;
		return( 0 );

	case    _CLASS_METHOD           :
	case    _CLASS_ROUTINE          :
	case    _CLASS_INLINE           :
	case    _CLASS_OVERLAY          :
	case    _CLASS_FUNCTION         :
	case    _CLASS_USER             :
		return( translate_method_type( type ) );
	case    _CLASS_OPERATOR         :
		return( translate_operator() );

	case    _CLASS_EMETHOD          :
		return( 0 );
	case    _CLASS_LOCAL            :
	case    _CLASS_INHIBIT          :
		return( syntax_error(820) );
	case    _CLASS_POINTER          :
		return( translate_pointer() );

	case    _CLASS_FRIEND           :
		return( translate_friend() );

	case    _CLASS_LIBRARY          :
		return( translate_class_dll() );
	case    _CLASS_CLASS            :
	case    _CLASS_UNION            :
		return( syntax_error(821) );

	case    _CLASS_CONST            :
		if ( ClassOptions.Declare )
			return( syntax_error(822) );
		else    ClassOptions.Declare = _KW1_CONST;
		break;

	case    _CLASS_DCL              :
		if ( ClassOptions.Declare )
			return( syntax_error(822) );
		else    ClassOptions.Declare = _KW1_DCL;
		break;

	case    _CLASS_ARGUMENT         :
		if ( ClassOptions.Declare )
			return( syntax_error(822) );
		else if ((status = translate_static_keyword()) != 0)
			return( status );
		else    
		{
			ClassOptions.Static  = _CLASS_STATIC;
			ClassOptions.Declare = _KW1_ARG;
			ClassOptions.Common = _CLASS_COMMON;
			return( translate_common() );
		}

	case    _CLASS_STRICT           :
		if ((status = translate_strict()) != 0)
			return( status );
		else    break;

	case    _CLASS_RELAX            :
		if ((status = translate_relax()) != 0)
			return( status );
		else    break;

	case    _CLASS_STATIC   :
		if ( ClassOptions.Static )
			return( syntax_error(823) );
		else if ((status = translate_static_keyword()) != 0)
			return( status );
		else    ClassOptions.Static = type;
		break;

	case    _CLASS_DYNAMIC  :
		if ( ClassOptions.Static )
			return( syntax_error(823) );
		else if ((status = translate_dynamic_keyword()) != 0)
			return( status );
		else    ClassOptions.Static = type;
		break;

	case    _CLASS_OVERLOAD         :
		if ( ClassOptions.Overload )
			return( syntax_error(814) );
		else    
		{
			ClassOptions.Overload = type;
			(void) translate_overload();
			type = _CLASS_VIRTUAL;
		}
		
	case    _CLASS_VIRTUAL          :
		if ( ClassOptions.Virtual )
			return( syntax_error(814) );
		else    
		{
			if ( world_enhanced_indirect() ) 
			{
				ClassOptions.Virtual = type;
				(void) translate_virtual();
			}
			type = _CLASS_INDIRECT;
		}
			
	case    _CLASS_INDIRECT         :
	case    _CLASS_DIRECT           :
		if ( ClassOptions.Direct )
			return( syntax_error(824) );
		else    ClassOptions.Direct = type;
		break;

	case    _CLASS_CONSTRUCTOR      :
	case    _CLASS_DESTRUCTOR       :
	case    _CLASS_PRECONDITION     :
	case    _CLASS_EXCEPTION        :
	case    _CLASS_POSTCONDITION    :
	case    _CLASS_INVARIANT        :
		if ( ClassOptions.Special )
			return( syntax_error(825) );
		else    ClassOptions.Special = type;
		break;

	case    _CLASS_INTEGER          :
#ifdef	otr64
		return( basic_return_type( _TYPE_INT64 ) );
#else
#ifdef	otr64
		return( basic_return_type( _TYPE_INT32 ) );
#else
		return( basic_return_type( _TYPE_INT16 ) );
#endif
#endif
	case    _CLASS_NUMERIC          :
		remove_useless_length();
		return( basic_return_type( _TYPE_NUMERIC ) );
	
	case    _CLASS_STRING           :
		remove_useless_length();
		return( basic_return_type( _TYPE_STRING ) );

	default                         : 
		return( MOINS_UN );

	}
	return( 0 );
}

/*	------------------------	*/
/*	 base_class_translation		*/
/*	------------------------	*/
WORD    base_class_translation()
{
	push_operation_pointer();
	set_operation_pointer(translate_base_class);
	ListMemberCounter = 0;
	return( translate_base_class() );
}

/*	-------------------------	*/
/*	 translate_class_members	*/
/*	-------------------------	*/
WORD    translate_class_members()
{
	WORD    status;
	WORD	alors=MOINS_UN;
	trace("translate_class_members()\n");

	if ( is_left_brace() )
		return( base_class_translation() );

	else  if ((status = previous_operation_pointer()) != MOINS_UN) 
	{
		reset_oneshot_options();
		return( status );
	}

	else  if ((status = translate_class_keyword()) != MOINS_UN)
		return( status );
	else    return( translate_member() );
}

/*	------------------------	*/
/*	 translate_base_classes		*/
/*	------------------------	*/
WORD    translate_base_classes()
{
	trace("translate_base_classes()\n");
	if ( is_left_brace() )
		return( base_class_translation() );
	else    return( 0 );
}

/*	-------------------------	*/
/*	 translate_keyword_class	*/
/*	-------------------------	*/
static  translate_keyword_class()
{
	TCSTRUCTPTR     sptr;
	WORD            type;
	WORD            nature;
	if (( ClassOptions.Type )
	||  ( ClassOptions.ReturnType  != (TCTYPPTR) 0))
		return( syntax_error(827) );
	else if (!( get_token() ))
		return( syntax_error(828) );
	else if ((sptr = known_structure(TokenBuffer)) == (TCSTRUCTPTR) 0)
		return( syntax_error(829) );
	else if ( sptr->virtual )
		return( syntax_error(1030 ) );
	if ((sptr->access & _MEMBER_OVERLAY)
	&&  (!(sptr->enhanced & _ENHANCED_INDIRECT)))
		nature = _KW1_IND;
	else    nature = _KW1_OBJ; 
	if ((nature = translate_instance_option(nature)) == MOINS_UN)
		return( syntax_error(830) );
	else if (( nature == _KW1_DCL )
	     ||  ( nature == _KW1_OBJ ))
		type = 0x0013;
	else    type = 0x9013;

	if ((ClassOptions.ReturnType = allocate_for_type( type, sptr->size, 1,1, sptr )) == (TCTYPPTR) 0)
		return( allocation_failure() );
	else    return( 0 );            
}

/*	-------------------------	*/
/*	 class_definition_active	*/
/*	-------------------------	*/
WORD    class_definition_active()
{
	if ( World->CurrentStructure != (TCSTRUCTPTR) 0 )
		return( VRAI );
	else    return( FAUX );
}

/*	-----------------	*/
/*	 translate_class	*/
/*	-----------------	*/
WORD    translate_class( type, nature )
WORD    type;
WORD    nature; 	/* _MEMBER_EXTERN */
{
	WORD    status;
	trace("translate_class()\n");
	if ( World->CurrentStructure != (TCSTRUCTPTR) 0 ) 
	{
		/* ----------------------------------------------------	*/
		/* arrival here means we are inside a class definition	*/
                /* collecting its constituant member definitions and	*/
 		/* we encountered the CLASS keyword in a declarative	*/
		/* data type situation requiring an instance or method	*/
		/* return type definition.				*/
		/* ----------------------------------------------------	*/
		if (( status = translate_keyword_class()) != 0)
			return( status );
		else    
		{
			if (!( get_token() ))
				return( syntax_error( 833 ) );
			/* ------------------------------ */
			/* Signal Continue : Nothing Done */
			/* ------------------------------ */
			else    return( MOINS_UN );
		}
	}
	else    
	{
		/* ---------------------------------------------------- */
		/* Arrival here is for the initiation of the class	*/
		/* definition phase due to the directive #class 	*/
		/* ---------------------------------------------------- */
		if ((status = enter_global_translation()) != 0)
			return( status );
		push_operation_pointer();
		set_operation_pointer(translate_class_members);
		reset_class_options();
		(void) inhibit_bal_comments();
		if (( nature )
		&&  ((status = translate_extern_keyword()) != 0))
			return( status );
		else    return( translate_struct(type) );
	}
}

/*	-----------------	*/
/*	 translate_union	*/
/*	-----------------	*/
WORD    translate_union( type, nature )
WORD    type;           /* DCL , PTR */
WORD    nature;         /* UNION     */
{
	WORD    status;
	WORD    vtype;
	WORD    nombre=0;

	trace("translate_union()\n");

	if (!( class_definition_active() )) 
	{
		if ( type )
			/* ----------------------------------- */
			/* Structure/Union Instance Expression */
			/* ----------------------------------- */
			return( translate_structure( type, nature ) );

		else    
			/* ------------------------------------- */
			/* Structure/Union Definition Expression */
			/* ------------------------------------- */
			return( translate_struct( nature ) );
	}

	/* -------------------------------------------------------------- */
	/* Translation UNION keyword in APLUS compatible CLASS definition */
	/* -------------------------------------------------------------- */
	else if ((status = define_explicite_union()) != 0) 
		return( status );

	while ( remove_white_space() != 0 ) 
	{

		if (( is_mnemonic( "POINTER" ) )
		||  ( is_mnemonic( "PTR"     ) ))
			vtype = _KW1_PTR;
		else    vtype = _KW1_DCL;

		if (!( get_token() ))
			break;

		else if ((status = translate_variable(vtype,0)) != 0)
			break;
		else    nombre++;

		if (!(is_comma())) 
		{
			status = verify_end_of_line();
			break;
		}
		else if ((!( remove_white_space() ))
		     &&  (!( new_input_line()     ))) 
		{
				status = 148;
				break;
		}
	}
	if ( status )
		return( status );
	else if (!( nombre ))
		return( syntax_error( 149 ) );
	else    return( terminate_explicite_union() );
}

/*	------------------	*/
/*	translate_endclass	*/
/*	------------------	*/
WORD    translate_endclass( type )
WORD    type;
{
	WORD    status;
	TCSTRUCTPTR     sptr;
	trace("translate_endclass()\n");
	terminate_method_text();
	pop_operation_pointer();
	restore_bal_comments(1);
	sptr = World->CurrentStructure;
	if ((status = translate_endstruct(type)) != 0)
		return( status );

	if (( show_class_dependance() )
	&&  ( sptr != (TCSTRUCTPTR) 0 ))
		trace_class_dependance( sptr, 0,_MEMBER_PUBLIC );

	return(leave_global_translation());
}

/*	------------------------	*/
/*	 translate_extern_class 	*/
/*	------------------------	*/
WORD    translate_extern_class()
{
	return( translate_class( _KW1_CLASS, _MEMBER_EXTERN ) );
}

/*	-------------------------	*/
/*	 translate_forward_class	*/
/*	-------------------------	*/
WORD    translate_forward_class()
{
	WORD    status=0;
	switch ( is_class_keyword() ) 
	{
	case    _CLASS_CLASS    :
		if ((status = translate_class( _KW1_CLASS , 0 )) != 0)
			return( status );
		else    return( translate_endclass( _KW1_ENDCLASS ) ); 

	case    _CLASS_UNION    :
		if ((status = translate_class( _KW1_UNION , 0 )) != 0)
			return( status );
		else    return( translate_endclass( _KW1_ENDUNION));  

	default                 :
		return( syntax_error( 4030 ) );
	}
}

/*	-------------------	*/
/*	trace_error_context	*/
/*	-------------------	*/
static	BYTE    MessageBuffer[512];
BPTR    trace_error_context()
{
	TCVARPTR        object;
	TCSTRUCTPTR     class;
	TCMBMETHPTR     method;
	TCMEMBERPTR     member;

	if ((object = (TCVARPTR)input_object()) != (TCVARPTR) 0) 
	{
		strcpy( MessageBuffer, object->name );
		strcat(MessageBuffer,"(");
		if ((class = (TCSTRUCTPTR)object->type->class) != (TCSTRUCTPTR) 0)
			strcat( MessageBuffer, class->name );
		else    strcat(MessageBuffer, "NULL" );
		strcat(MessageBuffer,").");
		if ((( method = (TCMBMETHPTR)input_method()) != (TCMBMETHPTR) 0)
		&&  (( member = method->member ) != (TCMEMBERPTR) 0))
			strcat( MessageBuffer, member->name );
		else    strcat( MessageBuffer, "NULL" );
		return( MessageBuffer );
	}
	else    return( (BPTR) 0 );
}

/*	------------------	*/
/*	directive_endclass	*/
/*	------------------	*/
WORD directive_endclass() 
{       
	if (!( is_active_region() ))
		return(0);
	else    return( translate_endclass( _KW1_ENDCLASS ) ); 
}

/*	-----------------	*/
/*	 directive_class	*/
/*	-----------------	*/
WORD directive_class()
{ 
	if (!( is_active_region() ))
		return(0);
	else    return( translate_class( _KW1_CLASS, 0 ) );
}

/*	-------------------	*/
/*	directive_endstruct	*/
/*	-------------------	*/
WORD directive_endstruct()
{ 
	if (!( is_active_region() ))
		return(0);
	else    return( translate_endclass( _KW1_ENDSTRUCT)); 
}

/*	----------------	*/
/*	directive_struct	*/
/*	----------------	*/
WORD directive_struct()   
{ 
	if (!( is_active_region() ))
		return(0);
	else    return( translate_class( _KW1_STRUCT, 0 ) );          
}

/*	------------------	*/
/*	directive_endunion	*/
/*	------------------	*/
WORD directive_endunion() 
{ 
	if (!( is_active_region() ))
		return(0);
	else    return( translate_endclass( _KW1_ENDUNION));  
}

/*	-----------------	*/
/*	 directive_union	*/
/*	-----------------	*/
WORD directive_union()    
{ 
	if (!( is_active_region() ))
		return(0);
	else    return( translate_class( _KW1_UNION, 0 ) );           
}

/*	------------------	*/
/*	directive_endmacro	*/
/*	------------------	*/
WORD directive_endmacro() 
{ 
	if (!( is_active_region() ))
		return(0);
	else    return( translate_endmacro() ); 
}

/*	-----------------	*/
/*	 directive_macro	*/
/*	-----------------	*/
WORD directive_macro()    
{ 
	if (!( is_active_region() ))
		return(0);
	else    return( translate_macro() );    
}

/*	-----------------	*/
/*	 compare_methods	*/
/*	-----------------	*/
WORD            compare_methods( lptr, rptr )
TCMBMETHPTR     lptr;
TCMBMETHPTR     rptr;
{
	if ((lptr == (TCMBMETHPTR) 0)
	||  (rptr == (TCMBMETHPTR) 0))
		return( FAUX );
	else if (( lptr->nature  != rptr->nature  )
	     ||  ( lptr->options != rptr->options )
	     ||  ( lptr->special != rptr->special ))
		return( FAUX );
	if (lptr->type != (TCTYPPTR) 0) 
	{
		if ( rptr->type == (TCTYPPTR) 0)
			return( FAUX );
		else if (!( compare_types( lptr->type, rptr->type ) ))
			return( FAUX );
	}
	else if ( rptr->type != (TCTYPPTR) 0 )
		return( FAUX );

	return( compare_strict_methods( lptr, rptr ) );
}

/*	--------------------	*/
/*	compare_data_members	*/
/*	--------------------	*/
WORD            compare_data_members( lptr, rptr )
TCMBDATAPTR     lptr;
TCMBDATAPTR     rptr;
{
	if ( lptr->structname != (BPTR) 0 ) 
	{
		if ( rptr->structname == (BPTR) 0 )
			return( FAUX );
		else  if ( compare_tokens( lptr->structname, rptr->structname ) )
			return( VRAI );
		else    return( compare_classes( lptr->structure, rptr->structure ) );
	}
	else if ( rptr->structname != (BPTR) 0 )
		return( FAUX );
	else if ( lptr->field != rptr->field )
		return( FAUX );
	else    return( compare_types( lptr->type, rptr->type ) );
}

/*	-----------------	*/
/*	 compare_members	*/
/*	-----------------	*/
WORD            compare_members( lptr, rptr )
TCMEMBERPTR     lptr;
TCMEMBERPTR     rptr;
{
	WORD    nature;
	if (( lptr->hash != rptr->hash )
	||  (!( compare_tokens( lptr->name, rptr->name ) )))
		return( FAUX );
	else if ((nature = lptr->nature) != rptr->nature )
		return( FAUX );

	else if ((lptr->access & ~ (_MEMBER_PUBLIC | _MEMBER_PRIVATE | _MEMBER_PROTECT))
	     !=  (lptr->access & ~ (_MEMBER_PUBLIC | _MEMBER_PRIVATE | _MEMBER_PROTECT)))
		return( FAUX );

	switch ( nature ) 
	{
	case _KW1_IND   :
	case _KW1_CMN   :
	case _KW1_OBJ   :
	case _KW1_OVL   :
	case _KW1_DCL   :
	case _KW1_PTR   :
	case _KW1_ARG   :
		return( compare_data_members( lptr->special, rptr->special ) );
	case _KW1_CONST :
		return( VRAI );
	default         : 
		return( compare_methods( lptr->special, rptr->special ) );
	}
}

/*	-----------------	*/
/*	 compare_classes	*/
/*	-----------------	*/
WORD    compare_classes( lclass, rclass )
TCSTRUCTPTR     lclass;
TCSTRUCTPTR     rclass;
{
	TCMEMBERPTR     lptr;
	TCMEMBERPTR     rptr;

	if ((lclass == (TCSTRUCTPTR) 0)
	||  (rclass == (TCSTRUCTPTR) 0))
		return( FAUX );

	else if (( lclass->hash == rclass->hash )
	     &&  ( compare_tokens( lclass->name, rclass->name )))
		return( VRAI );

	else if (((lptr = lclass->first) == (TCMEMBERPTR) 0)
	     ||  ((rptr = rclass->first) == (TCMEMBERPTR) 0))
		return( FAUX );

	while ((rptr != (TCMEMBERPTR) 0)
	   &&  (lptr != (TCMEMBERPTR) 0)) 
	{
		if ((rptr->access & _MEMBER_INHERIT )) 
		{
			rptr = rptr->next;
			continue;
		}
		else if ((lptr->access & _MEMBER_INHERIT )) 
		{
			lptr = lptr->next;
			continue;
		}
		else if (!( compare_members(lptr, rptr) ))
			return( FAUX );
		else    
		{
			lptr = lptr->next;
			rptr = rptr->next;
		}
	}
	if ( rptr == (TCMEMBERPTR) 0 )
		return( VRAI );
	else    return( FAUX );
}

/*	--------------------	*/
/*	is_method_definition	*/
/*	--------------------	*/
WORD	is_method_definition()
{
	if ( ClassOptions.MethodText != (VALUEPTR) 0 )
		return( VRAI );
	else	return( FAUX );
}

/*	--------------------	*/
/*	inherit_dynamic_type	*/
/*	--------------------	*/
WORD	inherit_dynamic_type( tptr, oldclass, newclass )
TCTYPPTR	tptr;
TCSTRUCTPTR	oldclass;
TCSTRUCTPTR	newclass;
{
	TCSTRUCTPTR	class;
	if (( tptr != (TCTYPPTR) 0)
	&&  (tptr->type & _TYPE_DEFINED)		
	&&  ((class = (TCSTRUCTPTR)tptr->class) != (TCSTRUCTPTR) 0)
	&&  ( class->hash == oldclass->hash )
	&&  ( compare_tokens( class->name, oldclass->name ) ))
		tptr->class = (VPTR) newclass;
	return(0);
}

/*	------------------	*/
/*	analyse_method_end	*/
/*	------------------	*/
WORD	analyse_method_end()
{
	WORD	status=0;

	if ( is_period() ) 
	{
		if ( is_mnemonic("PROC") )
			return( put_method_string("END.PROC") );
		else if ( is_mnemonic("SEG") )
			return( put_method_string("END.SEG") );
		else if ( is_mnemonic("USER") )
			return( put_method_string("END.USER") );
		else	return( syntax_error( 195 ) );
	}
	else if ( is_mnemonic("EVENT") ) 
	{
		if (((status = put_method_string("END")) != 0)
		||  ((status = put_method_string("EVENT")) != 0))
			return( status );
		else	return( 0 );
	}
	else if (( is_mnemonic("EXTERN") )
	     &&  ( is_mnemonic("EVENT" ) )) 
	{
		if (((status = put_method_string("END")) != 0)
		||  ((status = put_method_string("EXTERN")) != 0)
		||  ((status = put_method_string("EVENT")) != 0))
			return( status );
		else	return( 0 );
	}
	else	return( MOINS_UN );
}

#include "trecho.c"

	/* ---------- */
#endif  /* _TRCLASS_C */
	/* ---------- */


