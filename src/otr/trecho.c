#ifndef _TRECHO_C
#define	_TRECHO_C

#ifndef	private
#define	private	static
#endif

#include "troutput.h"

	BPTR	CodeLine=(BPTR) 0;
private	WORD	EchoIndent=0;
private	LONG	EchoOffset=0L;
private	LONG	EchoLineOffset=0L;
private	LONG	EchoLastOffset=0L;
private	WORD	EchoCodeBlock=FAUX;
private	WORD	EchoMode=1;
private	WORD	EchoActive=1;
private	WORD	EchoPrefix=0;
private	BYTE	EchoBuffer[512];
private	WORD	EchoIndex=0;
private	WORD	EchoLines=1;
private	WORD	EchoNumber=0;
private	WORD	EchoColumns=0;

#ifndef	UNIX
#else
VOID	echo_operand();
VOID	echo_shadow_operand();
#endif

#ifdef WIN32

#include "wotrmess.h"

extern int OptIdra;

/*	---------	*/
/*	sysprintf	*/
/*	---------	*/
private	char Message[1024];
private	int	offset;
int 	sysprintf(const char * format, ...)
{
	char *		pstring;
	int			Ret;

	if (*format == '\0')
		return offset;

	pstring = Message + offset;

	Ret = vsprintf(pstring, format, (char*)(&format+1));
	offset += strlen(pstring);

	/* ---------------------------------------- */
	/* Send the message only when 0A is reached */
	/* ---------------------------------------- */
	if (*(Message + offset - 1) == '\n') 
	{
		if (OptIdra)
			ctOutputMessageDiagnostic2(Message, NULL);
		else	x_cprintf(Message);

		*Message = '\0';
		offset = 0;
	}

	return Ret;
}
#endif

/*	-----------------	*/
/*	 set_echo_prefix	*/
/*	-----------------	*/
VOID	set_echo_prefix()
{
	EchoPrefix = VRAI;
	return;
}

/*	-----------------	*/
/*	clear_echo_prefix	*/
/*	-----------------	*/
VOID	clear_echo_prefix()
{
	EchoPrefix = FAUX;
	return;
}

/*	--------------------	*/
/*	set_echo_list_number	*/
/*	--------------------	*/
WORD	set_echo_list_number( fptr )
BPTR	fptr;
{
	if ((EchoNumber = symbolic_file_number( fptr )) != MOINS_UN)
		return( VRAI );
	else	return( FAUX );
}

/*	--------------	*/
/*	list_file_line	*/
/*	--------------	*/
WORD	list_file_line()
{
	if ( EchoPrefix )
		return( (EchoLines) );
	else	return( (EchoLines-1) );
}

/*	----------------	*/
/*	list_file_indent	*/
/*	----------------	*/
WORD	list_file_indent()
{
	if ( EchoPrefix )
		return( ((WORD) EchoLastOffset) );
	else	return( ((WORD) EchoLineOffset) );
}

/*	-----------------	*/
/*	list_file_segment	*/
/*	-----------------	*/
WORD	list_file_segment()
{
	if ( EchoPrefix )
		return( ((WORD) (EchoLastOffset >> 16)) );
	else	return( ((WORD) (EchoLineOffset >> 16)) );
}

/*	----------------	*/
/*	list_file_offset	*/
/*	----------------	*/
LONG	list_file_offset()
{
	if ( EchoPrefix )
		return( EchoLastOffset );
	else	return( EchoLineOffset );
}

/*	----------------	*/
/*	list_file_number	*/
/*	----------------	*/
WORD	list_file_number()
{
	return( EchoNumber );
}

/*	-----------------	*/
/*	 list_file_level	*/
/*	-----------------	*/
WORD	list_file_level()
{
	return( 0 );
}

/*	------------	*/
/*	suspend_echo	*/
/*	------------	*/
VOID	suspend_echo()
{
	EchoActive = FAUX;
	return;
}

/*	------------	*/
/*	restart_echo	*/
/*	------------	*/
VOID	restart_echo()
{
	EchoActive = VRAI;
	return;
}

/*	---------	*/
/*	echo_byte	*/
/*	---------	*/
VOID	echo_byte( n )
WORD	n;
{
	if (!( EchoActive ))
		return;
	else if ( EchoMode ) 
	{
		if ( EchoColumns == 0 ) 
		{
			if (!(OtrOption.Symbolic & 1))
				fprintf(World->ListHandle,"%9.1llu ",EchoLines);  
			if ( EchoCodeBlock )
				fprintf(World->ListHandle,"%8.1llX ",current_tcode_offset());
		}
		fprintf( World->ListHandle,"%c",(int)(n&0x00FF));

		EchoOffset++;
		if ( n == '\n' ) 
		{
			clear_echo_prefix();
			EchoLines++;
			EchoColumns=0;
#ifndef	UNIX
			EchoOffset++;
#endif
			EchoLineOffset = EchoLastOffset;
			EchoLastOffset = EchoOffset;
		}
		else	EchoColumns++;
	}
	else if ( EchoIndex < 512 ) 
	{
		if ((EchoBuffer[EchoIndex++] = n) == 0)
			EchoMode++;
	}
	return;
}

/*	----------	*/
/*	echo_gener	*/
/*	----------	*/
VOID	echo_gener( n, v )
WORD	n;
WORD	v;
{
	for ( ; n > 0; n-- )
		echo_byte( v );
	return;
}

/*	-----------	*/
/*	echo_string	*/
/*	-----------	*/
VOID	echo_string(nptr)
BPTR	nptr;
{
	if (!( verify_world_list() ))
		return;
	while ( *nptr )
		echo_byte( *(nptr++) );
	return;
}

/*	---------	*/
/*	echo_line	*/
/*	---------	*/
VOID	echo_line()
{
	if (!( verify_world_list() ))
		return;
	if ( EchoMode )
		echo_string("\n");
	else	echo_byte( 0 );
	return;
}

/*	----------	*/
/*	echo_space	*/
/*	----------	*/
VOID	echo_space()
{
	echo_byte(' ');
	return;
}

/*	------------	*/
/*	echo_keyword	*/
/*	------------	*/
VOID	echo_keyword( iptr )
BPTR	iptr;
{
	echo_string(iptr);
	echo_space();
	return;
}	

/*	------------	*/
/*	echo_integer	*/
/*	------------	*/
private	VOID	echo_integer( n )
WORD	n;
{
	BYTE	buffer[64];
	sprintf(buffer,"%llu",n);
	echo_string(buffer);
	return;
}

/*	--------	*/
/*	echo_hex	*/
/*	--------	*/
private	VOID	echo_hex( n )
WORD	n;
{
	BYTE	buffer[64];
	WORD	i;
	sprintf(buffer,"0x%16.1llX",n);
	for (i=0; i < strlen(buffer); i++ )
		if ( buffer[i] == ' ' )
			buffer[i] = 0;
	echo_string(buffer);
	return;
}

/*	----------------	*/
/*	echo_indentation	*/
/*	----------------	*/
private	VOID	echo_indentation()
{
	WORD	i=0;

	while ( i < EchoIndent ) 
	{
		echo_byte('\t');
		i++;
	}
	return;
}

/*	----------	*/
/*	echo_start	*/
/*	----------	*/
WORD	echo_start(mode)
WORD	mode;
{
	if (!( verify_world_list() ))
		return(0);
	else 	
	{
		if ( mode )
			echo_indentation();
		else 	EchoIndex = EchoMode = 0;
		return(1);
	}
}

/*	-------------------------	*/
/*	 echo_line_concatenation	*/
/*	-------------------------	*/
VOID	echo_line_concatenation()
{
	echo_byte(' ');
	echo_byte(0x027);
	echo_line();
	echo_indentation();
	return;
}

/*	----------	*/
/*	echo_comma	*/
/*	----------	*/
VOID	echo_comma()
{
	echo_byte(',');
	if ( EchoColumns > 200 )
		echo_line_concatenation();
	return;
}

/*	----------	*/
/*	echo_colon	*/
/*	----------	*/
VOID	echo_colon()
{
	echo_byte(':');
	return;
}

/*	-----------	*/
/*	echo_equals	*/
/*	-----------	*/
VOID	echo_equals()
{
	echo_byte('=');
	return;
}

/*	-----------------	*/
/*	 echo_left_brace	*/
/*	-----------------	*/
VOID	echo_left_brace()
{
	echo_byte('(');
	return;
}

/*	----------------	*/
/*	echo_right_brace	*/
/*	----------------	*/
VOID	echo_right_brace()
{
	echo_byte(')');
	return;
}

/*	---------	*/
/*	echo_type	*/
/*	---------	*/
VOID		echo_type( type, mode )
TCTYPPTR	type;
WORD		mode;
{
	if (!( verify_world_list() ))
		return;
	if ( type != (TCTYPPTR) 0) 
	{
		if (( type->type & _TYPE_POINTER ) == _TYPE_POINTER )
			echo_keyword("Ptr");
		switch(( type->type & _TYPE_BASIC )) 
		{
		case	_TYPE_INT8	: 
			echo_byte('#');
			break;
		case	_TYPE_INT16	: 
			echo_byte('%');
			break;
		case	_TYPE_INT32	: 
			echo_byte(':');
			break;
		case	_TYPE_INT64	: 
			echo_byte('&');
			break;
		case	_TYPE_STRING	: 
			echo_byte('$');
		case	_TYPE_NUMERIC	: 
			if ( mode ) 
			{
				echo_equals();
				echo_integer( type->size );
			}
		}
		if (( mode )
		&&  ( type->type & _TYPE_FIRST )) 
		{
			echo_left_brace();
			echo_integer(type->first);
			if ( type->type & _TYPE_SECOND ) 
			{
				echo_comma();
				echo_integer( type->second );
			}
			echo_right_brace();
		}
	}
	return;
}

/*	-----------------	*/
/*	echo_class_nature	*/
/*	-----------------	*/
VOID	echo_class_nature( class )
TCSTRUCTPTR	class;
{
	if (!( verify_world_list() ))
		return;
	switch ( class->nature ) 
	{
	case	_KW1_CLASS	: echo_keyword("Class"); break;
	case	_KW1_STRUCT	: echo_keyword("Struct"); break;
	case	_KW1_UNION	: echo_keyword("Union"); break;
	}
	return;
}

/*	------------------	*/
/*	echo_class_options	*/
/*	------------------	*/
VOID	echo_class_options( class )
TCSTRUCTPTR	class;
{
	if (!( verify_world_list() ))
		return;
	if ( class->access & _MEMBER_EXTERN )
		echo_keyword("Extern");
	if ( class->access & _MEMBER_OVERLAY )
		echo_keyword("Overlay");
	if ( class->access & _MEMBER_GENERIC )
		echo_keyword("Generic");
	if ( class->virtual )
		echo_keyword("Virtual");
	return;
}

/*	-----------------	*/
/*	 echo_class_name	*/
/*	-----------------	*/
VOID	echo_class_name( class )
TCSTRUCTPTR	class;
{
	if (!( verify_world_list() ))
		return;
	echo_keyword( class->name );
	return;
}

/*	----------------	*/
/*	echo_basic_class	*/
/*	----------------	*/
VOID	echo_basic_class( class )
TCSTRUCTPTR	class;
{
	if (!( verify_world_list() ))
		return;
	if ( class != (TCSTRUCTPTR) 0 ) 
	{
		echo_class_nature( class );
		echo_class_name( class );
	}
	return;
}

/*	----------	*/
/*	echo_class	*/
/*	----------	*/
VOID	echo_class( class )
TCSTRUCTPTR	class;
{
	if (!( verify_world_list() ))
		return;
	if ( class != (TCSTRUCTPTR) 0 ) 
	{
		echo_class_nature( class );
		echo_class_options( class );
		echo_class_name( class );
	}
	return;
}

/*	----------------	*/
/*	echo_method_type	*/
/*	----------------	*/
VOID		echo_method_type( type )
TCTYPPTR	type;
{
	if (!( verify_world_list() ))
		return;

	if ( type != (TCTYPPTR) 0) 
	{
		if ( type->type & _TYPE_DEFINED )
			echo_basic_class( type->class );
		else	
		{
			switch(( type->type & _TYPE_BASIC )) 
			{
			case	_TYPE_INT8	: 
			case	_TYPE_INT16	: 
			case	_TYPE_INT32	: 
			case	_TYPE_INT64	: 
				echo_keyword("Integer"); break;
			case	_TYPE_STRING	: 
				echo_keyword("String"); break;
			case	_TYPE_NUMERIC	: 
				echo_keyword("Numeric"); break;
			}
		}
		if (( type->type & _TYPE_POINTER ) == _TYPE_POINTER )
			echo_keyword("Pointer");
	}
	return;
}

/*	--------------	*/
/*	echo_soft_line	*/
/*	--------------	*/
private	VOID	echo_soft_line()
{
	echo_space();
	echo_byte(0x0027);
	echo_line();
	EchoIndent++;
	echo_indentation();
	EchoIndent--;
	return;
}

/*	-----------------	*/
/*	 echo_parameters	*/
/*	-----------------	*/
VOID	echo_parameters( variable )
TCVARPTR	variable;
{
	WORD		nombre=0;
	TCSTRUCTPTR	class;
	if (!( verify_world_list() ))
		return;
	if (variable != (TCVARPTR) 0 ) 
	{
		do	
		{
			if ( nombre++ ) 
			{
				echo_comma();
				echo_soft_line();
			}
			else	echo_left_brace();

			if ( variable->type->type & _TYPE_DEFINED ) 
			{
				if ((class = (TCSTRUCTPTR)variable->type->class) != (TCSTRUCTPTR) 0)
					echo_basic_class( class );
			}
			echo_string( variable->name );
			if (!( variable->type->type & _TYPE_DEFINED ))
				echo_type( variable->type, 1 );
		}
		while ((variable = variable->next) != (TCVARPTR) 0);
		if ( nombre );
			echo_right_brace();
	}
	return;
}

/*	-----------	*/
/*	echo_method	*/
/*	-----------	*/
VOID		echo_method( member,method )
TCMEMBERPTR	member;
TCMBMETHPTR	method;
{
	if (( method == (TCMBMETHPTR) 0)
	||  ( member == (TCMEMBERPTR) 0))
		return;
	if (!( verify_world_list() ))
		return;
	if ( method->options & _METHOD_STRICT )
		echo_keyword("Strict");
	else	echo_keyword("Relax");
	if ( method->options & _METHOD_RESIDENT )
		echo_keyword("Resident");

	if ( method->type != (TCTYPPTR) 0 )
		echo_method_type( method->type );
	if ( method->options & _METHOD_INDIRECT ) 
	{
		if ( method->options & _METHOD_OVERLOAD )
			echo_keyword("Overload");
		else if ( method->options & _METHOD_VIRTUAL )
			echo_keyword("Virtual");
		else	echo_keyword("Indirect");
	}
	else	echo_keyword("Direct");
	echo_keyword(get_class_keyword(method->nature));
	if ( method->special )
		echo_keyword(get_class_keyword(method->special));
	else	echo_keyword(get_class_keyword(_CLASS_METHOD));
	if ( method->options & _METHOD_MACRO )
		echo_keyword("Macro");
	echo_string(member->name);
	echo_colon();
	echo_parameters( method->parameters );
	return;
}

/*	-------------	*/
/*	echo_constant	*/
/*	-------------	*/
VOID		echo_constant( member, cptr )
TCMEMBERPTR	member;
TCMBCONSTPTR	cptr;
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("CONST");
	echo_string(member->name);

	if ( cptr != (TCMBCONSTPTR) 0) 
	{
		echo_type( cptr->type, 0 );
		echo_equals();
		echo_string( cptr->value );
	}
	return;
}

/*	-----------	*/
/*	echo_member	*/
/*	-----------	*/
VOID		echo_member( member )
TCMEMBERPTR	member;
{
	TCMBDATAPTR	dptr;

	if (!( verify_world_list() ))
		return;
	if ( member != (TCMEMBERPTR) 0 ) 
	{
		if ( member->access & _MEMBER_PRIVATE )
			echo_keyword("Private");
		if ( member->access & _MEMBER_PUBLIC  )
			echo_keyword("Public");
		if ( member->access & _MEMBER_PROTECT )
			echo_keyword("Protect ");
		if ( member->access & _MEMBER_COMMON )
			echo_keyword("Common ");
		if ( member->access & _MEMBER_DYNAMIC )
			echo_keyword("Dynamic ");
		else	echo_keyword("Static  ");

		if (!( member->nature )) 
			echo_method( member, member->special );
		else if ( member->nature == _KW1_CONST )
			echo_constant( member, member->special );
		else	
		{
			if ( member->access & _MEMBER_OVERLOAD)
				echo_keyword("Overload ");
			else if ( member->access & _MEMBER_VIRTUAL )
				echo_keyword("Virtual ");
			switch ( member->nature ) 
			{
			case	_KW1_DCL	: echo_keyword("Dcl "); break;
			case	_KW1_PTR	: echo_keyword("Ptr "); break;
			case	_KW1_OVL	: echo_keyword("Ovl "); break;
			case	_KW1_ARG	: echo_keyword("Arg "); break;
			case	_KW1_CMN	: echo_keyword("Cmn "); break;
			case	_KW1_IND	: echo_keyword("Ind "); break;
			case	_KW1_OBJ	: echo_keyword("Obj "); break;
			default			: echo_keyword("?????");
			}
			if ((dptr = (TCMBDATAPTR)member->special) != (TCMBDATAPTR) 0) 
			{
				if ( dptr->structname != (BPTR) 0 ) 
				{
					echo_keyword(dptr->structname );
					echo_string( member->name );
				}
				else	
				{
					echo_string( member->name );
					echo_type( dptr->type, 1 );
				}
			}
		}
		echo_line();
	}
	return;
}

/*	--------------------	*/
/*	echo_target_identity	*/
/*	--------------------	*/
private	VOID	echo_target_identity()
{
	WORD	i;
	echo_byte('"');
	for (i=0; i < 15; i++)
		echo_byte(Context->identity[i]);
	echo_byte('"');
	return;
}

/*	------------	*/
/*	echo_program	*/
/*	------------	*/
VOID	echo_program()
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("PROGRAM");
	echo_target_identity();
	echo_line();
	return;
}

/*	------------	*/
/*	echo_library	*/
/*	------------	*/
VOID	echo_library()
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("LIBRARY");
	echo_line();
	return;
}

/*	-----------	*/
/*	echo_module	*/
/*	-----------	*/
VOID	echo_module()
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("MODULE");
	echo_target_identity();
	echo_line();
	return;
}

/*	------------	*/
/*	echo_segment	*/
/*	------------	*/
VOID	echo_segment( sptr )
TCSEGPTR	sptr;
{
	if (!( verify_world_list() ))
		return;
	EchoIndent = 0;
	echo_keyword("SEGMENT"); 
	echo_integer(sptr->identity);
	echo_line();
	EchoCodeBlock = 1;
	EchoIndent = 1;
	return;
}

/*	---------	*/
/*	echo_eseg	*/
/*	---------	*/
VOID	echo_eseg( sptr )
TCSEGPTR	sptr;
{
	if (!( verify_world_list() ))
		return;
	EchoIndent = 0;
	EchoCodeBlock = 0;
	echo_keyword("ESEG");
	echo_integer(sptr->identity);
	echo_line();
	return;
}

/*	-------------------	*/
/*	echo_extern_segment	*/
/*	-------------------	*/
VOID	echo_extern_segment( nptr )
BPTR	nptr;
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("EXTERN");
	echo_keyword("SEGMENT");
	echo_string(nptr);
	echo_line();
}

/*	------------	*/
/*	echo_endproc	*/
/*	------------	*/
VOID	echo_endproc()
{
	if (!( verify_world_list() ))
		return;
	EchoCodeBlock = 0;
	EchoIndent = 0;
	echo_keyword("ENDPROC");
	echo_line();
	return;
}

/*	-----------	*/
/*	echo_return	*/
/*	-----------	*/
VOID	echo_return()
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("RETURN");
	echo_line();
	return;
}

/*	--------------	*/
/*	echo_procedure	*/
/*	--------------	*/
VOID	echo_procedure( pptr )
TCPRCPTR	pptr;
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("PROC");
	echo_string(pptr->name);
	echo_parameters( pptr->parameter );
	if ( pptr->options & _DIFFERED_PROC ) 
	{
		echo_comma();
		echo_keyword("D");
	}
	echo_line();
	EchoCodeBlock = 2;
	EchoIndent = 1;
	return;
}

/*	------------------	*/
/*	get_procedure_name	*/
/*	------------------	*/
TCPRCPTR	get_procedure_name( n )
WORD		n;
{
	TCPRCPTR	pptr;

	if ((pptr = Context->PDT) != (TCPRCPTR) 0) 
	{
		do	
		{
			if ( pptr->identity == n )
				break;
		}
		while ((pptr = pptr->next) != (TCPRCPTR) 0);
	}
	return( pptr );
}

/*	-------------------	*/
/*	echo_procedure_name	*/
/*	-------------------	*/
VOID	echo_procedure_name( xptr )
RESULTPTR	xptr;
{
	TCPRCPTR	pptr;
	switch ( xptr->nature ) 
	{
	case	_RESULT_INT	:
		if ((pptr = get_procedure_name( xptr->value )) != (TCPRCPTR) 0) 
		{
			echo_string( pptr->name );
			break;
		}
	default			:
		echo_operand( xptr );
	}
	return;
}

/*	--------------	*/
/*	report_details	*/
/*	--------------	*/
VOID	report_details( dptr )
TCBLKPTR	dptr;
{
#ifdef	PROLOGUE
	sysprintf("<td>%u<td>%u<td>%u\n",dptr->code_length,dptr->table_length,dptr->const_length);
#else
	sysprintf("<td>%llu<td>%llu<td>%llu\n",dptr->code_length,dptr->table_length,dptr->const_length);
#endif
	return;
}

/*	------------	*/
/*	echo_details	*/
/*	------------	*/
VOID	echo_details( dptr )
TCBLKPTR	dptr;
{
	if (!( verify_world_list() )) 
	{
		if ( OtrOption.Verbose & 32 ) 
			report_details( dptr );
		else	
		{
#ifdef	PROLOGUE
			if ( dptr->code_length )
				sysprintf("\tCode  Size             : %llu\n",dptr->code_length);
			if ( dptr->table_length )
				sysprintf("\tLocal Data Table Size  : %llu\n",dptr->table_length);
			if ( dptr->const_length )
				sysprintf("\tLocal Constants  Size  : %llu\n",dptr->const_length);
#else
			if ( dptr->code_length )
				sysprintf("\tCode  Size             : %llu\n",dptr->code_length);
			if ( dptr->table_length )
				sysprintf("\tLocal Data Table Size  : %llu\n",dptr->table_length);
			if ( dptr->const_length )
				sysprintf("\tLocal Constants  Size  : %llu\n",dptr->const_length);
#endif
		}
	}
	else	
	{
		BYTE	buffer[128];
#ifdef	PROLOGUE
		if ( dptr->code_length ) 
		{
			sprintf(buffer,"\tCode  Size             : %llu\n",dptr->code_length);
			echo_string(buffer);
			echo_line();
		}
		if ( dptr->table_length ) 
		{
			sprintf(buffer,"\tLocal Data Table Size  : %llu\n",dptr->table_length);
			echo_string(buffer);
			echo_line();
		}
		if ( dptr->const_length ) 
		{
			sprintf(buffer,"\tLocal Constants  Size  : %llu\n",dptr->const_length);
			echo_string(buffer);
			echo_line();
		}
#else
		if ( dptr->code_length ) 
		{
			sprintf(buffer,"\tCode  Size             : %llu\n",dptr->code_length);
			echo_string(buffer);
			echo_line();
		}
		if ( dptr->table_length ) 
		{
			sprintf(buffer,"\tLocal Data Table Size  : %llu\n",dptr->table_length);
			echo_string(buffer);
			echo_line();
		}
		if ( dptr->const_length ) 
		{
			sprintf(buffer,"\tLocal Constants  Size  : %llu\n",dptr->const_length);
			echo_string(buffer);
			echo_line();
		}
#endif
	}
	return;
}

/*	--------	*/
/*	echo_end	*/
/*	--------	*/
VOID	echo_end()
{
	if (!( verify_world_list() ))
		return;
	echo_keyword("END");
	echo_line();
	EchoIndent = 0;
	return;
}

/*	-----------------	*/
/*	echo_dll_function	*/
/*	-----------------	*/
VOID	echo_dll_function( fptr )
TCDLFPTR	fptr;
{
	TCVARPTR	vptr;
	if (!( verify_world_list() ))
		return;
	echo_keyword("DLL");
	switch ( fptr->type ) 
	{
	case _TYPE_INT8  	: echo_byte('#'); break;
	case _TYPE_INT16 	: echo_byte('%'); break;
	case _TYPE_INT32 	: echo_byte(':'); break;
	case _TYPE_INT64 	: echo_byte('&'); break;
	case _TYPE_STRING	: echo_byte('$'); break;
	case _TYPE_NUMERIC   	: echo_byte('*'); break;
	case 7 		 	: echo_byte('.'); break;
	default		 	: echo_space();
	}
	echo_string(fptr->name);
	echo_left_brace();
	if ((vptr = fptr->parameter) != (TCVARPTR) 0) 
		{
		do	
		{
			switch (( vptr->type->type & 0x0007 )) 
			{
			case _TYPE_INT8  	: echo_byte('#'); break;
			case _TYPE_INT16 	: echo_byte('%'); break;
			case _TYPE_INT32 	: echo_byte(':'); break;
			case _TYPE_INT64 	: echo_byte('&'); break;
			case _TYPE_STRING	: echo_byte('$'); break;
			case _TYPE_NUMERIC   	: echo_byte('*'); break;
			case 7 		 	: echo_byte('.'); break;
			}
			if (( vptr->type->type & 0x0008 ))
				echo_byte('?');
			if ( vptr->next != (TCVARPTR) 0 )
				echo_comma();
		}
		while ((vptr = vptr->next) != (TCVARPTR) 0);
	}	
	echo_right_brace();
	echo_line();
	return;
}

/*	--------------------------	*/
/*	resolve_variable_decriptor	*/
/*	--------------------------	*/
private	TCVARPTR	resolve_variable_decriptor(vdt, identity )
TCVDTPTR	vdt;
WORD		identity;
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	if ( vdt != (TCVDTPTR) 0) 
	{
		if ((vptr = vdt->first) != (TCVARPTR) 0) 
		{
			do	
			{
				if (( vptr->identity & TOGLOBAL) == ( identity & TOGLOBAL ))
					break;
			}
			while ((vptr = vptr->prev) != (TCVARPTR) 0);
		}
	}
	return( vptr );
}

/*	------------------	*/
/*	echo_variable_name	*/
/*	------------------	*/
private	VOID	echo_variable_name( vptr, level )
TCVARPTR	vptr;
WORD		level;
{
	TCVARPTR	host;

	if ( vptr != (TCVARPTR) 0 ) 
	{
		if ( OtrOption.ListFlag & 4 ) 
		{
			while ( vptr->parent != (TCVARPTR) 0 )
				vptr = vptr->parent;
			if ( vptr->master ) 
			{
				if (( host = resolve_variable_decriptor(vptr->vdt, vptr->master )) != (TCVARPTR) 0)
					echo_variable_name( host, (level+1) );
			}
			else if ( vptr->host ) 
			{
				if (( host = resolve_variable_decriptor(vptr->vdt, vptr->host )) != (TCVARPTR) 0)
					echo_variable_name( host, (level+1) );
			}
		}
		if ( vptr->name != (BPTR) 0 )
			echo_string(vptr->name);
		else	echo_string("<name>");
	}
	else	echo_string("<variable>");

	if ( level )
		echo_byte('.');
	return;
}

/*	----------------	*/
/*	echo_declaration	*/
/*	----------------	*/
VOID	echo_declaration( vptr )
TCVARPTR	vptr;
{

	if (!( verify_world_list() ))
		return;
	if ( vptr->type->size == 0 )
		return;
	echo_indentation();
	
	if ( OtrOption.Special ) 
	{
		echo_string("[V=");
		echo_hex( vptr->descriptor );
		echo_string(",M=");
		echo_hex( vptr->master );
		echo_string(",H=");
		echo_hex( vptr->host );
		echo_string(",T=");
		echo_hex( vptr->type->type );
		echo_string("] ");
	}

	if ( vptr->type->type & _TYPE_PARAMETER )
		echo_keyword("ARG");
	if (( vptr->type->type & _TYPE_POINTER) == _TYPE_POINTER)
		echo_keyword("PTR");
	else	echo_keyword("DCL");

	echo_variable_name( vptr, 0 );

	switch ((vptr->type->type & _TYPE_BASIC)) 
	{
	case _TYPE_INT8		: echo_byte('#'); break;
	case _TYPE_INT16	: echo_byte('%'); break;
	case _TYPE_INT32	: echo_byte(':'); break;
	case _TYPE_INT64	: echo_byte('&'); break;
	case _TYPE_STRING	: echo_byte('$'); 
	case _TYPE_NUMERIC	: echo_equals();
				  echo_integer(vptr->type->size); 
				  break;
	}

	if ( vptr->type->type & _TYPE_FIRST ) 
	{
		echo_left_brace();
		echo_integer(vptr->type->first);
		if ( vptr->type->type & _TYPE_SECOND ) 
		{
			echo_comma();
			echo_integer(vptr->type->second);
		}
		echo_right_brace();
	}
	echo_line();
	return;
}

/*	----------	*/
/*	echo_field	*/
/*	----------	*/
VOID	echo_field( handle, nptr )
WORD	handle;
BPTR	nptr;
{
	if (!( verify_world_list() ))
		return;
	echo_indentation();
	if ( handle == 0 )
		echo_keyword("FIELD=M");
	else if ( handle == _TYPE_EXTENDED )
		echo_keyword("FIELD=E");
	else 	
	{
		echo_string("FIELD=");
		echo_integer(handle);
		echo_byte(' ');
	}
	if ( nptr != (BPTR) 0 ) 
	{
		echo_comma();
		echo_string(nptr);
	}
	echo_line();
	return;
}

/*	--------------	*/
/*	echo_code_line	*/
/*	--------------	*/
VOID	echo_code_line( lptr )
BPTR	lptr;
{
	CodeLine = lptr;
	return;
}

/*	------------	*/
/*	echo_newline	*/
/*	------------	*/
VOID	echo_newline()
{
	return;
}

/*	----------	*/	
/*	echo_label	*/
/*	----------	*/	
VOID	echo_label( nptr )
BPTR	nptr;
{
	if (!( verify_world_list() ))
		return;
	echo_keyword(nptr);
	echo_line();
	return;
}

/*	----------	*/	
/*	echo_gosub	*/
/*	----------	*/	
VOID	echo_gosub( n )
WORD	n;
{
	if (!( verify_world_list() ))
		return;
	else	echo_indentation();
	echo_keyword("GOSUB");
	echo_byte('$');
	echo_integer(n);
	echo_line();
	return;
}

/*	----------------	*/	
/*	echo_gosub_label	*/
/*	----------------	*/	
VOID	echo_gosub_label( nptr )
BPTR	nptr;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("GOSUB");
		echo_string(nptr);
		echo_line();
	}
	return;
}

/*	-----------------	*/	
/*	 echo_goto_label	*/
/*	-----------------	*/	
VOID	echo_goto_label( nptr )
BPTR	nptr;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("GOTO");
		echo_string(nptr);
		echo_line();
	}
	return;
}

/*	-------------------	*/
/*	echo_implicite_goto	*/
/*	-------------------	*/
VOID	echo_implicite_goto( label )
WORD	label;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("GOTO");
		echo_byte('$');
		echo_integer( label);
		echo_line();
	}
	return;
}

/*	----------------	*/
/*	echo_instruction	*/
/*	----------------	*/
VOID	echo_instruction( iptr )
BPTR	iptr;
{
	if (!( verify_world_list() ))
		return;
	else	
	{
		echo_indentation();
		echo_keyword( iptr );
		echo_line();
	}
	return;
}

/*	--------------------	*/
/*	echo_leave_iteration	*/
/*	--------------------	*/
VOID	echo_leave_iteration( type )
WORD	type;
{
	if (!( verify_world_list() ))
		return;

	if (( type != _ITERATION_REPEAT ) 
	&&  ( type != _ITERATION_FOR    )) 
	{
		if ( EchoIndent > 0 )
			EchoIndent--;
		echo_indentation();
	}

	switch ( type ) 
	{
	case	_ITERATION_IF		:
		echo_keyword("ENDIF"); 
		echo_line();
		break;
	case	_ITERATION_SELECT	:
		echo_keyword("ENDSEL"); 
		echo_line();
		break;
	case	_ITERATION_DO		:
		echo_keyword("LOOP"); 
		echo_line();
		break;
	case	_ITERATION_WHILE	:
		echo_keyword("WEND"); 
		echo_line();
		break;
	case	_ITERATION_REPEAT	:
		break;
	case	_ITERATION_FOR		:
		break;
	case	_ITERATION_EVENT	:
		echo_keyword("END EVENT"); 
		echo_line();
		break;
	}
	return;
}

/*	--------------------	*/
/*	echo_enter_iteration	*/
/*	--------------------	*/
VOID	echo_enter_iteration( type )
WORD	type;
{
	if ( type == _ITERATION_FOR )
		return;
	else if (!( verify_world_list() ))
		return;
	else	echo_indentation();
	switch ( type ) 
	{
	case	_ITERATION_IF		:
		echo_keyword("IF");
		set_echo_prefix();
		break;
	case	_ITERATION_DO		:
		echo_keyword("DO"); 
		echo_line();
		break;
	case	_ITERATION_WHILE	:
		echo_keyword("WHILE"); 
		set_echo_prefix();
		break;
	case	_ITERATION_SELECT	:
		echo_keyword("SELECT"); 
		set_echo_prefix();
		break;
	case	_ITERATION_REPEAT	:
		echo_keyword("REPEAT"); 
		echo_line();
		break;
	case	_ITERATION_EVENT	:
		echo_keyword("ON EVENT");
		set_echo_prefix();
		break;
	}
	EchoIndent++;
	return;
}

/*	------------------	*/
/*	echo_gosub_routine	*/
/*	------------------	*/
VOID	echo_gosub_routine( optr, mptr )
BPTR	optr;
BPTR	mptr;
{
	if (!( verify_world_list() ))
		return;
	else	echo_indentation();
	echo_keyword("GOSUB");
	echo_string(optr); echo_byte('.'); echo_string(mptr);
	echo_line();
	return;
}

/*	------------	*/
/*	echo_routine	*/
/*	------------	*/
VOID	echo_routine( optr, mptr )
BPTR	optr;
BPTR	mptr;
{
	if (!( verify_world_list() ))
		return;
	echo_byte('&');
	echo_string(optr); 
	echo_byte('.'); 
	echo_string(mptr);
	echo_line();
	return;
}

/*	------------------	*/
/*	echo_call_function	*/
/*	------------------	*/
VOID	echo_call_function( optr, mptr )
BPTR	optr;
BPTR	mptr;
{
	if (!( verify_world_list() ))
		return;
	else	echo_indentation();
	echo_keyword("CALL");
	echo_string(optr); 
	echo_byte('.'); 
	echo_string(mptr);
	echo_line();
	return;
}

/*	-----------------	*/
/*	echo_load_overlay	*/
/*	-----------------	*/
VOID	echo_load_overlay( optr, mptr )
BPTR	optr;
BPTR	mptr;
{
	if (!( verify_world_list() ))
		return;
	else	echo_indentation();
	echo_keyword("LDGO.SEG");
	echo_string(optr); 
	echo_byte('.'); 
	echo_string(mptr);
	echo_line();
	return;
}

/*	--------------------	*/
/*	echo_integer_operand	*/
/*	--------------------	*/
VOID	echo_integer_operand( r )
WORD	r;
{
	if ( verify_world_list() )
		echo_integer(r);
	return;
}

/*	-----------------	*/
/*	 echo_dimensions	*/
/*	-----------------	*/
VOID	echo_dimensions( type, fptr, sptr )
WORD		type;
RESULTPTR	fptr;
RESULTPTR	sptr;
{
	if ( type & _TYPE_FIRST ) 
	{
		if ( fptr != (RESULTPTR) 0) 
		{
			echo_left_brace();
			echo_operand( fptr );
			if (( type & _TYPE_SECOND )
			&&  ( sptr != (RESULTPTR) 0)) {
				
				echo_comma();
				echo_operand( sptr );
			}
			echo_right_brace();
		}
	}
	return;
}

/*	---------------------	*/
/*	echo_variable_operand	*/
/*	---------------------	*/
VOID	echo_variable_operand( vptr )
TCVARPTR	vptr;
{
	if ( verify_world_list() ) 
	{
		echo_variable_name( vptr, 0 );
		echo_dimensions( vptr->type->type, vptr->firstdim, vptr->secondim );
	}
	return;
}

/*	-----------------	*/
/*	 echo_bcd_nibble	*/
/*	-----------------	*/
private	WORD	echo_bcd_nibble( c )
WORD	c;
{
	switch ( c ) 
	{
	case	0x000C :
		echo_byte('+');
		break;
	case	0x000B :
		echo_byte('-');
		break;
	case	0x000A :
		echo_byte('.');
		break;
	default	       :
		if ( c > 9 )
			return( 0 );
		else	echo_byte((c + '0'));
	}
	return(1);
}

/*	-------------	*/	
/*	echo_bcd_byte	*/
/*	-------------	*/	
private	WORD	echo_bcd_byte( c )
WORD	c;
{
	if (!(echo_bcd_nibble( ((c >> 4) & 0x000F) ) ))
		return(0);
	else if (!(echo_bcd_nibble( (c & 0x000F) ) ))
		return(0);
	else	return(1);
}

/*	-----------------	*/
/*	 echo_bcd_string	*/
/*	-----------------	*/
VOID	echo_bcd_string( bptr, blen )
BPTR	bptr;
WORD	blen;
{
	while ( blen-- ) 
		if (!( echo_bcd_byte( *(bptr++) ) ))
			break;
	return;
}

/*	---------------------	*/
/*	echo_constant_operand	*/
/*	---------------------	*/
VOID	echo_constant_operand( cptr )
TCCONPTR	cptr;
{
	if (!( verify_world_list() ))
		return;
	else if ( cptr->name != (BPTR) 0)
		echo_string(cptr->name);
	else 	
	{
		switch ((cptr->type->type & _TYPE_BASIC)) 
		{
		case _TYPE_INT8	:
		case _TYPE_INT16:
		case _TYPE_INT32:
		case _TYPE_INT64:
			echo_integer(cptr->identity);
		case _TYPE_STRING :
			if ( cptr->value != (BPTR) 0 ) 
			{
				echo_byte('"');
				echo_string(cptr->value);
				echo_byte('"');
			}
			break;
		default		:
			if ( cptr->value != (BPTR) 0 )
				echo_bcd_string(cptr->value, cptr->type->size);
		}
	}
	return;
}

/*	---------	*/
/*	echo_void	*/
/*	---------	*/
VOID	echo_void()
{
	echo_string("<void>");
	return;
}

/*	---------	*/
/*	echo_null	*/
/*	---------	*/
VOID	echo_null()
{
	echo_string("<null>");
	return;
}

/*	-------------------	*/
/*	echo_braced_operand	*/
/*	-------------------	*/
VOID	echo_braced_operand( rptr )
RESULTPTR 	rptr;
{
	echo_left_brace();
	if ( rptr != (RESULTPTR) 0)
		echo_operand( rptr );
	else	echo_void();
	echo_right_brace();
	return;
}

/*	------------------	*/
/*	echo_braced_shadow	*/
/*	------------------	*/
VOID	echo_braced_shadow( rptr, value )
SHADOWNODE	rptr;
WORD		value;
{
	echo_left_brace();
	if ( rptr != (SHADOWNODE) 0)
		echo_shadow_operand( rptr, value );
	else	echo_void();
	echo_right_brace();
	return;
}

/*	--------------------	*/
/*	echo_complex_operand	*/
/*	--------------------	*/
VOID	echo_complex_operand( type, tptr, value )
WORD	type;
VPTR	tptr;
WORD	value;
{
	switch ( type ) 
	{
	case 	_REGISTER_INT	:
		echo_integer_operand( value );
		break;
	case	_REGISTER_CONST	:
		echo_constant_operand( tptr );
		break;
	case	_REGISTER_VARB	:
		echo_variable_operand( tptr ); 
		break;
	case	_REGISTER_EXPR  :
		echo_braced_operand( tptr );
	}
	return;
}

/*	--------------------	*/
/*	echo_register_number	*/
/*	--------------------	*/
VOID	echo_register_number( n, nature )
WORD	n;
WORD	nature;
{
	echo_byte('R');
	echo_integer(n);
	echo_left_brace();
	echo_hex( nature );
	echo_right_brace();
	return;
}

/*	---------------------	*/
/*	echo_special_register	*/
/*	---------------------	*/
VOID		echo_special_register( sptr, value)
SHADOWNODE	sptr;
WORD		value;
{
	if (sptr->nature == _SHADOW_CONVS8 ) 
	{
		echo_string("CONV#");
		echo_braced_shadow( sptr->lptr, value );
	}
	else if ( sptr->nature == _SHADOW_CONVS16 ) 
	{
		echo_string("CONV"); echo_byte('%');
		echo_braced_shadow( sptr->lptr, value );
	}
	else if ( sptr->nature == _SHADOW_CONVSL ) 
	{
		echo_string("CONV");
		echo_braced_shadow( sptr->lptr, value );
	}
	else if ( sptr->nature == _SHADOW_CONVSS ) 
	{
		echo_string("CONV$");
		echo_braced_shadow( sptr->lptr, value );
	}
	else if ( sptr->nature == _SHADOW_CONVR8 ) 
	{
		echo_string("CONV#");
		echo_braced_operand( sptr->lptr );
	}
	else if ( sptr->nature == _SHADOW_CONVR16 ) 
	{
		echo_string("CONV"); echo_byte('%');
		echo_braced_operand( sptr->lptr );
	}
	else if ( sptr->nature == _SHADOW_CONVRL ) 
	{
		echo_string("CONV");
		echo_braced_operand( sptr->lptr );
	}
	else if ( sptr->nature == _SHADOW_CONVRS ) 
	{
		echo_string("CONV$");
		echo_braced_operand( sptr->lptr );
	}
	else if ( sptr->nature == (_SHADOW_RESULT | _REGISTER_VARB)) 
	{
		echo_variable_operand( sptr->lptr );
	}
	else if ( sptr->nature == (_SHADOW_RESULT | _REGISTER_CONST)) 
	{
		echo_constant_operand( sptr->lptr );
	}
	else if ( sptr->nature == _SHADOW_RESULT ) 
	{
		echo_operand( sptr->lptr );
	}
	else if ( sptr->nature == _SHADOW_INCS ) 
	{
		echo_left_brace();
		echo_braced_shadow( sptr->lptr, value );
		echo_byte('+');
		echo_byte('1');
		echo_right_brace();
	}
	else if (( sptr->nature & _SHADOW_MASK) == _SHADOW_INCR ) 
	{
		echo_left_brace();
		echo_complex_operand( (sptr->nature & 0x000F), sptr->lptr, value );
		echo_byte('+');
		echo_byte('1');
		echo_right_brace();
	}
	else if ( sptr->nature == _SHADOW_DECS ) 
	{
		echo_left_brace();
		echo_braced_shadow( sptr->lptr, value );
		echo_byte('-');
		echo_byte('1');
		echo_right_brace();
	}
	else if (( sptr->nature & _SHADOW_MASK) == _SHADOW_DECR ) 
	{
		echo_left_brace();
		echo_complex_operand( (sptr->nature & 0x000F), sptr->lptr, value );
		echo_byte('-');
		echo_byte('1');
		echo_right_brace();
	}
	else if ( sptr->nature == _SHADOW_NEGS ) 
	{
		echo_left_brace();
		echo_byte('-');
		echo_braced_shadow( sptr->lptr, value );
		echo_right_brace();
	}
	else if (( sptr->nature & _SHADOW_MASK) == _SHADOW_NEGR ) 
	{
		echo_left_brace();
		echo_byte('-');
		echo_complex_operand( (sptr->nature & 0x000F), sptr->lptr, value );
		echo_right_brace();
	}
	else if ( sptr->nature == _SHADOW_TEXT ) 
	{
		if ( sptr->lptr != (VPTR) 0 )
			echo_string(sptr->lptr);
		else	echo_null();
	}
	else	echo_void();
	return;
}

/*	-------------------	*/
/*	echo_shadow_operand	*/
/*	-------------------	*/
VOID		echo_shadow_operand( sptr, value )
SHADOWNODE	sptr;
WORD		value;
{
	if (( sptr != (SHADOWNODE) 0)
	&&  ( sptr->nature != MOINS_UN )) 
	{
		if ( sptr->nature < 0x00FF ) 
		{
			echo_left_brace();
			echo_operand( sptr->lptr );
			echo_byte(sptr->nature);
			echo_operand( sptr->rptr );
			echo_right_brace();
		}
		else	echo_special_register( sptr, value );
	}
	return;
}

/*	---------------------	*/
/*	echo_register_operand	*/
/*	---------------------	*/
VOID		echo_register_operand( sptr )
SHADOWPTR	sptr;
{
	if ( verify_world_list() ) 
	{
		if ( sptr->operand != (SHADOWNODE) 0)
			echo_shadow_operand( sptr->operand, sptr->value );
		else	
		{
			switch ( sptr->nature ) 
			{
			case 	_REGISTER_INT	:
				echo_integer_operand( sptr->value );
				break;
			case	_REGISTER_CONST	:
				echo_constant_operand( sptr->contents );
				break;
			case	_REGISTER_ALIAS	:
				echo_keyword("ALIAS");
				echo_left_brace();
				echo_variable_operand( sptr->contents ); 
				echo_right_brace();
				break;
			case	_REGISTER_VARB	:
				echo_variable_operand( sptr->contents ); 
				break;
			case    _RESULT_ALEXPR  :
				echo_keyword("ALIAS");
				echo_left_brace();
				echo_register_number( sptr->number, sptr->nature  );
				echo_right_brace();
				break;
			case	_REGISTER_EXPR	:
			default			:
				echo_register_number( sptr->number, sptr->nature  );
			}
		}
	}
	return;
}

/*	--------------------	*/
/*	echo_constant_symbol	*/
/*	--------------------	*/
VOID	echo_constant_symbol( cptr )
TCCONPTR	cptr;
{
	if ((cptr->type->type & _TYPE_BASIC) == _TYPE_STRING) 
		if ( cptr->value != (BPTR) 0 )
			echo_string(cptr->value);
	return;
}

/*	------------	*/
/*	echo_operand	*/
/*	------------	*/
VOID	echo_operand( xptr )
RESULTPTR	xptr;
{
	switch ( xptr->nature ) 
	{
	case _RESULT_ALEXPR  :
	case _RESULT_EXPR : echo_register_operand( xptr->contents ); break;
	case _RESULT_ALIAS :
	case _RESULT_VPTR :
	case _RESULT_VARB : echo_variable_operand( xptr->contents ); break;
	case _RESULT_CONST: echo_constant_operand( xptr->contents ); break;
	case _RESULT_INT  : echo_integer_operand( xptr->value ); break;
	}
	return;
}

/*	----------	*/
/*	echo_pause	*/
/*	----------	*/
VOID	echo_pause( rptr )
RESULTPTR	rptr;
{
	if (!( verify_world_list() ))
		return;
	else	echo_indentation();
	echo_keyword( "PAUSE" );
	echo_operand( rptr );
	echo_line();
	return;
}

/*	----------------	*/
/*	echo_affectation	*/
/*	----------------	*/
VOID	echo_affectation( vptr, rptr, withecho )
TCVARPTR	vptr;
RESULTPTR	rptr;
WORD		withecho;
{
	if ( withecho ) 
	{
		if ( verify_world_list() ) 
		{
			echo_indentation();
			echo_variable_operand( vptr );
			echo_equals();
			echo_operand( rptr );
			echo_line();
		}
	}
	return;
}

/*	--------	*/
/*	echo_sti	*/
/*	--------	*/
VOID	echo_sti( vptr, value )
TCVARPTR	vptr;
WORD      	value;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_variable_operand( vptr );
		echo_equals();
		echo_integer( value );
		echo_line();
	}
	return;
}

/*	---------	*/
/*	echo_case	*/
/*	---------	*/
VOID	echo_case( mode, rptr )
WORD		mode;
RESULTPTR	rptr;
{
	if (!( verify_world_list() ))
		return;
	if ( mode ) 
		echo_comma();
	else	
	{
		if ( EchoIndent > 0 )
			EchoIndent--;
		echo_indentation();
		echo_keyword("CASE");
	}
	echo_operand( rptr );
	return;
}

/*	-------------	*/
/*	echo_case_end	*/
/*	-------------	*/
VOID	echo_case_end()
{
	if ( verify_world_list() ) 
	{
		echo_line();
		EchoIndent++;		
	}	
	return;
}

/*	-----------	*/
/*	echo_select	*/
/*	-----------	*/
VOID	echo_select( rptr )
RESULTPTR	rptr;
{
	if (!( verify_world_list() ))
		return;
	else	
	{
		echo_operand( rptr );
		echo_line();
	}
	return;
}

/*	-----------------	*/
/*	 echo_for_prefix	*/
/*	-----------------	*/
VOID		echo_for_prefix()
{
	if (!( verify_world_list() ))
		return;
	else	
	{
		echo_indentation();
		echo_keyword("FOR");
		set_echo_prefix();
	}
	return;
}

/*	--------	*/
/*	echo_for	*/
/*	--------	*/
VOID		echo_for(vptr, rptr, operator)
TCVARPTR	vptr;
RESULTPTR	rptr;
WORD		operator;
{
	if (!( verify_world_list() ))
		return;
	else	
	{
		echo_variable_operand( vptr );
		if ( operator )
			echo_byte( operator );
		echo_equals();
		echo_operand( rptr );
		echo_space();
	}
	return;
}

/*	---------	*/
/*	 echo_to	*/
/*	---------	*/
VOID		echo_to(rptr)
RESULTPTR	rptr;
{
	if (!( verify_world_list() ))
		return;
	else	
	{
		echo_keyword("TO");
		echo_operand( rptr );
		echo_space();
	}
	return;
}

/*	---------	*/
/*	echo_step	*/
/*	---------	*/
VOID		echo_step(rptr)
RESULTPTR	rptr;
{
	if (!( verify_world_list() ))
		return;
	else	
	{
		echo_keyword("STEP");
		if ( rptr != (RESULTPTR) 0 )
			echo_operand( rptr );
		else	echo_integer(1);
		echo_line();
		EchoIndent++;
		suspend_echo();
	}
	return;
}

/*	------------	*/
/*	echo_compare	*/
/*	------------	*/
VOID		echo_compare( operation, lptr, rptr )
WORD		operation;
RESULTPTR	lptr;
RESULTPTR	rptr;
{
	if (!( verify_world_list() ))
		return;
	else	
	{
		echo_left_brace();
		echo_operand( lptr );
		switch ( operation ) 
		{
		case _CMP_EQ : echo_keyword(" = " ); break;
		case _CMP_NE : echo_keyword(" <> " ); break;
		case _CMP_GR : echo_keyword(" > " ); break;
		case _CMP_LS : echo_keyword(" < " ); break;
		case _CMP_GE : echo_keyword(" >= " ); break;
		case _CMP_LE : echo_keyword(" <= " ); break;
		case _CMP_IN : echo_keyword(" = " ); break;
		case _CMP_NI : echo_keyword(" != "); break;
		}
		echo_operand( rptr );
		echo_right_brace();
	}
	return;

}

/*	----------	*/
/*	echo_logic	*/
/*	----------	*/
VOID		echo_logic( operation )
WORD		operation;
{
	if (!( verify_world_list() ))
		return;
	switch ( operation ) 
	{
	case	_LOGICAL_AND	:
		echo_keyword(" AND "); break;
	case	_LOGICAL_OR 	:
		echo_keyword(" OR "); break;
	case	_LOGICAL_OX 	:
		echo_keyword(" OX "); break;
	}
	return;
}

/*	----------------	*/
/*	echo_compare_end	*/
/*	----------------	*/
VOID	echo_compare_end()
{
	if (!( verify_world_list() ))
		return;
	else	echo_line();
	return;
}

/*	----------	*/
/*	echo_until	*/
/*	----------	*/
VOID	echo_until()
{
	if ( verify_world_list() ) 
	{
		if ( EchoIndent > 0 )
			EchoIndent--;
		echo_indentation();
		echo_keyword("UNTIL");
		set_echo_prefix();
	}
	return;
}

/*	---------	*/
/*	echo_else	*/
/*	---------	*/
VOID	echo_else()
{
	if ( verify_world_list() ) 
	{
		if ( EchoIndent > 0 )
			EchoIndent--;
		echo_indentation();
		echo_keyword("ELSE");
		echo_line();
		EchoIndent++;
		set_echo_prefix();
	}
	return;
}

/*	---------	*/
/*	echo_exit	*/
/*	---------	*/
VOID		echo_exit(rptr)
RESULTPTR	rptr;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("EXIT");
		if ( rptr != (RESULTPTR) 0) 
		{
			echo_left_brace();
			echo_operand( rptr );
			echo_right_brace();
		}
		echo_line();
	}
	return;
}

/*	----------	*/
/*	echo_error	*/
/*	----------	*/
VOID		echo_error(rptr)
RESULTPTR	rptr;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("ERROR");
		if ( rptr != (RESULTPTR) 0) 
		{
			echo_left_brace();
			echo_operand( rptr );
			echo_right_brace();
		}
		echo_line();
	}
	return;
}

/*	---------	*/
/*	echo_next	*/
/*	---------	*/
VOID		echo_next(vptr)
TCVARPTR 	vptr;
{
	if ( verify_world_list() ) 
	{
		if ( EchoIndent > 0 )
			EchoIndent--;
		echo_indentation();
		echo_keyword("NEXT"); 
		echo_variable_operand( vptr ); 
		echo_line();
	}
	return;
}

/*	-------------	*/
/*	echo_on_timer	*/
/*	-------------	*/
VOID	echo_on_timer( rptr, type, label )
RESULTPTR	rptr;
WORD		type;
BPTR		label;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("ON"); 
		echo_keyword("TIMER");
		echo_operand( rptr );
		echo_space();
		if ( type == 1 )
			echo_keyword("GOTO");
		else	echo_keyword("GOSUB");
		echo_string( label );
		echo_line();
	}
	return;
}

/*	--------------	*/
/*	echo_timer_off	*/
/*	--------------	*/
VOID	echo_timer_off()
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("TIMER");
		echo_keyword("OFF"); 
		echo_line();
	}
	return;
}

/*	-------------	*/
/*	start_echo_of	*/
/*	-------------	*/
VOID	start_echo_of( rptr, type )
RESULTPTR	rptr;
WORD		type;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("OF"); 
		echo_operand( rptr );
		echo_space();
		if ( type == 0 )
			echo_keyword("GOTO ");
		else	echo_keyword("GOSUB ");
	}
	return;
}

/*	-------------	*/
/*	echo_of_label	*/
/*	-------------	*/
VOID	echo_of_label( nombre, nptr )
WORD	nombre;
BPTR	nptr;
{
	if ( verify_world_list() ) 
	{
		if ( nombre ) {
			echo_comma();
			echo_soft_line();
			}
		echo_string( nptr );
	}
	return;
}

/*	-----------	*/
/*	echo_resume	*/
/*	-----------	*/
VOID	echo_resume( mode, label )
WORD	mode;
BPTR	label;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_keyword("RESUME");
		if ( mode )
			echo_string( label );
		echo_line();
	}
	return;
}

/*	------------	*/
/*	echo_comment	*/
/*	------------	*/
VOID	echo_comment( cptr )
BPTR	cptr;
{
	if (( OtrOption.ListFlag & 1 )
	&&  ( verify_world_list() )) 
	{
		echo_indentation();
		echo_keyword(";** ");
		echo_string( cptr );
		echo_line();
		echo_indentation();
		echo_keyword(";** ");
		echo_gener(strlen( cptr ), '-' );
		echo_line();
	}
	else	sysprintf("%s\n",cptr);
	return;
}

/*	-------------	*/
/*	get_echo_text	*/
/*	-------------	*/
BPTR	get_echo_text()
{
	return((BPTR) allocate_for_string( EchoBuffer ) );
}

/*	-------------------	*/
/*	echo_correspondance	*/
/*	-------------------	*/
VOID	echo_correspondance( l, o )
WORD	l;
WORD	o;
{
	return;
}	

/*	------------------	*/
/*	echo_error_message	*/
/*	------------------	*/
VOID	echo_error_message( a, b, c )
BPTR	a;
BPTR	b;
BPTR	c;
{
	if ( verify_world_list() ) 
	{
		echo_string("* * ");
		echo_string( a );
		echo_space();
		echo_string(b);
		echo_space();
		echo_string(c);
		echo_string(" * *");
		echo_line();
	}
	return;
}

/*	--------------------	*/
/*	echo_warning_message	*/
/*	--------------------	*/
VOID	echo_warning_message( a, b,l, c )
BPTR	a;
BPTR	b;
WORD	l;
BPTR	c;
{
	if ( verify_world_list() ) 
	{
		echo_string("* * ");
		echo_string( a );
		echo_space();
		echo_string(b);
		echo_space();
		echo_integer( l );
		echo_space();
		echo_string(c);
		echo_string(" * *");
		echo_line();
	}
	return;
}

/*	--------------------	*/	
/*	echo_transmit_common	*/
/*	--------------------	*/	
VOID		echo_transmit_common( vptr )
TCVARPTR	vptr;
{
	if ( verify_world_list() ) 
	{
		echo_indentation();
		echo_string("TransmitCommon");
		echo_parameters( vptr );
		echo_line();
	}
	return;
}

	/* --------- */
#endif	/* _TRECHO_C */
	/* --------- */

