#ifndef	_TRSTDC_C
#define	_TRSTDC_C

#include <stdio.h>		/* Standard IO handling routines	*/
#include <errno.h>		/* Error return definitions		*/
#include <fcntl.h>		
#include "stdtypes.h"
#include "translat.h"
#include "trparser.h"
#include "trsyntax.h"
#include "trerrors.h"
#include "trsymbol.h"
#include "troption.h"
#include "trtables.h"
#include "trexpres.h"
#include "trlabels.h"
#include "triter.h"
#include "trtree.h"
#include "trmethod.h"
#include "trmember.h"
#include "trcommon.h"
#include "trclass.h"
#include "trinput.h"
#include "trdebug.h"
#include "trstdc.h"
#include "trapl.h"

EXTERN	BYTE	TokenBuffer[];
EXTERN	WORD	TokenHash;

#ifndef	UNIX
TCDLBPTR	locate_dynamic_library( BPTR );
COMETHODPTR	allocate_special_method( BPTR,WORD);
TCMBDATAPTR	allocate_structure_data( VOID );
TCMBCONSTPTR	allocate_structure_const( BPTR, TCTYPPTR );
#else
TCDLBPTR	locate_dynamic_library();
COMETHODPTR	allocate_special_method();
TCMBDATAPTR	allocate_structure_data();
TCMBCONSTPTR	allocate_structure_const();
#endif

static 	FILEPTR		cHandle=(FILEPTR) 0;
static	WORD		StdcDone=0;
static	WORD		StdcUnGotch=0;
static	TCSTRUCTPTR	StdcClass=(TCSTRUCTPTR) 0;

static	WORD	await_stdc_termination()
{
	pop_operation_pointer();
	return(await_target_end());
}

static	WORD	stdc_class_header( class )
	TCSTRUCTPTR	class;
{
	StdcClass = class;
	fprintf(cHandle,"\n#ifndef __%s",class->name);
	fprintf(cHandle,"\n#define __%s",class->name);
	fprintf(cHandle,"\n\n/*\tABAL++ Class : %s */\n",class->name);
	return(0);
}

static	WORD	stdc_class_footer( class )
	TCSTRUCTPTR	class;
{
	fprintf(cHandle,"\n\n/*\tABAL++ EndClass : %s */\n",class->name);
	fprintf(cHandle,"\n#endif  /* __%s */",class->name);
	StdcClass = (TCSTRUCTPTR) 0;
	return(0);
}

static	void	stdc_structptr( nptr )
	BPTR	nptr;
{
	fprintf(cHandle,"struct %s *",nptr);
	return;
}

static	void	stdc_struct( nptr )
	BPTR	nptr;
{
	fprintf(cHandle,"struct %s",nptr);
	return;
}

static	void	stdc_structcast( nptr )
	BPTR	nptr;
{
	fprintf(cHandle,"(");
	stdc_structptr( nptr );
	fprintf(cHandle,")");
	return;
}

static	void	stdc_this( nptr )
	BPTR	nptr;
{
	fprintf(cHandle,"\n\t");
	stdc_structptr( nptr );
	fprintf(cHandle," iptr;");
	return;
}

static	WORD		stdc_type( tptr )
	TCTYPPTR	tptr;
{
	TCSTRUCTPTR	cptr;
	if ( tptr->type & _TYPE_DEFINED ) {
		if ((cptr = (TCSTRUCTPTR)tptr->class) != (TCSTRUCTPTR) 0)
			stdc_structptr( cptr->name );
		else	fprintf(cHandle,"void *");
		}
	else	{
		switch ( tptr->type & _TYPE_BASIC ) {
			case	_TYPE_STRING	:
			case	_TYPE_NUMERIC	:
				fprintf(cHandle,"unsigned char []");
				break;
			case	_TYPE_INT8  	:
				fprintf(cHandle,"char");
				break;
			case	_TYPE_INT16  	:
				fprintf(cHandle,"short int");
				break;
			case	_TYPE_INT32  	:
				fprintf(cHandle,"long  int");
				break;
			}
		}
	return(0);
}


static	WORD		stdc_class_type( nptr, tptr )
	BPTR		nptr;
	TCTYPPTR	tptr;
{
	switch ( tptr->type & _TYPE_BASIC ) {
		case	_TYPE_STRING	:
		case	_TYPE_NUMERIC	:
			fprintf(cHandle,"unsigned char %s[%u]",nptr,tptr->size);
			break;
		case	_TYPE_INT8  	:
			fprintf(cHandle,"char %s",nptr);
			break;
		case	_TYPE_INT16  	:
			fprintf(cHandle,"short int %s",nptr);
			break;
		case	_TYPE_INT32  	:
			fprintf(cHandle,"long  int %s",nptr);
			break;
		}

	if ( tptr->type & _TYPE_FIRST ) {
		fprintf(cHandle,"[%u]",tptr->first);
		if ( tptr->type & _TYPE_SECOND )
			fprintf(cHandle,"[%u]",tptr->second);
		}
	fprintf(cHandle,";");
	return(0);
}


static	WORD	stdc_class_member( prefix, mptr, dptr )
	BPTR		prefix;
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;
{
	fprintf(cHandle,"\n%s",prefix);

	if ( dptr->structname != (BPTR) 0 ) {
		switch ( mptr->nature ) {
			case _KW1_PTR   :
			case _KW1_OVL   :
				stdc_structptr( dptr->structname );
				fprintf(cHandle," %s;",mptr->name);
				return(0);
			default		:
				stdc_struct( dptr->structname );
				fprintf(cHandle," %s;",mptr->name);
				return(0);
			}
		}
	else	return( stdc_class_type( mptr->name, dptr->type ) );
	return(0);

}

static	WORD	stdc_class_method( prefix, class,mptr, fptr )
	BPTR		prefix;
	TCSTRUCTPTR	class;
	TCMEMBERPTR	mptr;
	TCMBMETHPTR	fptr;
{
	if ( fptr->options & _METHOD_VIRTUAL ) {
		if ( fptr->options & _METHOD_OVERLOAD )
			fprintf(cHandle,"/*");
		fprintf(cHandle,"\n%s",prefix);
		stdc_structptr( class->name );
		fprintf(cHandle,"\t__%s;",mptr->name);
		fprintf(cHandle,"\n%s",prefix);
		if ( fptr->type != (TCTYPPTR) 0)
			stdc_type( fptr->type );
		else	fprintf(cHandle,"void");
		fprintf(cHandle,"\t(*%s)",mptr->name);
		stdc_structcast( class->name );
		fprintf(cHandle,";");
		if ( fptr->options & _METHOD_OVERLOAD )
			fprintf(cHandle,"*/");

		}
	return(0);
}

static	WORD	stdc_method_init( mptr, class,fptr )
	TCMEMBERPTR	mptr;
	TCSTRUCTPTR	class;
	TCMBMETHPTR	fptr;
{
	if ( fptr->options & _METHOD_VIRTUAL ) {
		if ( fptr->options & _METHOD_OVERLOAD )
			fprintf(cHandle,"/*");
		fprintf(cHandle,"\n\tiptr->%s = %s_%s;",mptr->name,class->name,mptr->name);
		fprintf(cHandle,"\n\tiptr->__%s = iptr;",mptr->name);
		if ( fptr->options & _METHOD_OVERLOAD )
			fprintf(cHandle,"*/");
		}
	return(0);
}

static	WORD	stdc_member_init( mptr, dptr, nature )
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;
	WORD		nature;
{
	if ( dptr->structname != (BPTR) 0 ) {
		switch ( nature ) {
			case _KW1_PTR   :
			case _KW1_OVL   :
				fprintf(cHandle,"\n\t\tiptr->%s = ",mptr->name );
				stdc_structcast( dptr->structname );
				fprintf(cHandle," 0;");
				break;
			case _KW1_IND   :
			case _KW1_OBJ   :
			case _KW1_DCL	:
			case _KW1_ARG   :
				fprintf(cHandle,"\n\t\tinit_%s(& iptr->%s );",dptr->structname,mptr->name );
				break;
			}
		return(0);
		}
	else	{
		switch ( dptr->type->type & _TYPE_BASIC ) {
			case	_TYPE_STRING :
				fprintf(cHandle,"\n\t\tmemset(iptr->%s,' ',%u);",mptr->name,dptr->type->size);
				break;
			case	_TYPE_NUMERIC :
				fprintf(cHandle,"\n\t\tmemset(iptr->%s,0x00FF,%u);",mptr->name,dptr->type->size);
				fprintf(cHandle,"\n\t\tiptr->%s[0] = 0x00CF;",mptr->name );
				break;
			case	_TYPE_INT8	:
			case	_TYPE_INT16	:
			case	_TYPE_INT32	:
				fprintf(cHandle,"\n\t\tiptr->%s = 0;",mptr->name );
				break;
			}
		}
	
	return(0);

}

static	WORD	stdc_get_source_character()
{
	WORD	c;
	if (!(c = StdcUnGotch))
		c = get_source_character();
	else	StdcUnGotch = 0;
	return( c );
}

static	VOID	stdc_unget_character( c )
	WORD	c;
{
	StdcUnGotch = c;
	return;
}


static	WORD	stdc_get_token()
{
	WORD	i=0;
	WORD	c;
	TokenBuffer[i]=0;
	if ((c = stdc_get_source_character()) != MOINS_UN)
		if ((c == '_')
	     	||  ((c >= 'a') && (c <= 'z'))
	     	||  ((c >= 'A') && (c <= 'Z')))
		while (1) {
			TokenBuffer[i++] = c;
			if ((c = stdc_get_source_character()) == MOINS_UN)
				break;
			else if ((c == '_')
			     ||  ((c >= 'a') && (c <= 'z'))
			     ||  ((c >= '0') && (c <= '9'))
			     ||  ((c >= 'A') && (c <= 'Z')))
				continue;
			else	break;
			}

	stdc_unget_character( c );
	TokenBuffer[i] = 0;
	return(i);
}

static	WORD	stdc_not_white()
{
	WORD	c;

	while ((c = stdc_get_source_character()) == ' ');
	stdc_unget_character( c );
	return( stdc_get_token() );
}	

static	WORD	stdc_not_whitec()
{
	WORD	c;

	while ((c = stdc_get_source_character()) == ' ');
	return( c );
}

static	TCMEMBERPTR	stdc_co_member( nptr )
	BPTR		nptr;
{
	TCMEMBERPTR	member=(TCMEMBERPTR) 0;
	if ( StdcClass != (TCSTRUCTPTR) 0) {
		member = StdcClass->first;
		while ( member != (TCMEMBERPTR) 0) {
			if ( compare_tokens( nptr, member->name ) )
				break;
			else	member = member->next;
			}
		}
	return( member );
}		



static	WORD	prefix_co_member( nptr )
	BPTR	nptr;
{
	TCMEMBERPTR	member=(TCMEMBERPTR) 0;
	if ((member = stdc_co_member( nptr )) != (TCMEMBERPTR) 0 ) {
		fprintf(cHandle,"iptr->%s",nptr);
		return(1);
		}
	else	return(0);
}

static	BPTR	stdc_member_class( nptr )
	BPTR	nptr;
{
	TCMBDATAPTR	dptr;
	TCMEMBERPTR	member=(TCMEMBERPTR) 0;
	if ((member = stdc_co_member( nptr )) != (TCMEMBERPTR) 0 ) {
		switch ( member->nature ) {
			case _KW1_PTR   :
			case _KW1_OVL   :
			case _KW1_IND   :
			case _KW1_OBJ   :
			case _KW1_DCL	:
			case _KW1_ARG   :
			case _KW1_CMN   :
				if (( dptr = (TCMBDATAPTR) member->special ) != (TCMBDATAPTR) 0)
					return( dptr->structname );
			}
		}
	return( (BPTR) 0);

}




static	VOID	stdc_create() 
{
	BPTR	class;

	if ( stdc_not_white() ) {
		if ((class = stdc_member_class( TokenBuffer )) != (BPTR) 0 )
			fprintf(cHandle,"\n\tiptr->%s = create_%s();",TokenBuffer,class);
		}
	return;
}

static	VOID	stdc_remove() 
{
	BPTR	class;
	if ( stdc_not_white() ) {
		if ((class = stdc_member_class( TokenBuffer )) != (BPTR) 0 )
			fprintf(cHandle,"\n\tremove_%s( iptr->%s );",class,TokenBuffer);
		}

	return;
}

static	VOID	stdc_forget() 
{
	BPTR	class;
	if ( stdc_not_white() ) {
		if ((class = stdc_member_class( TokenBuffer )) != (BPTR) 0 )
			fprintf(cHandle,"\n\tinit_%s( iptr->%s );",class,TokenBuffer);
		}
	return;
}

static	VOID	stdc_print_member( mptr, dptr )
	TCMEMBERPTR	mptr;
	TCMBDATAPTR	dptr;
{
	if ( dptr->structname == (BPTR) 0 ) {
		switch ( dptr->type->type & _TYPE_BASIC ) {
			case	_TYPE_INT8  :
			case	_TYPE_INT16 :
			case	_TYPE_INT32 :
				fprintf(cHandle,"\n\tprinti( iptr->%s );",mptr->name);
				break;
			case	_TYPE_STRING :
				fprintf(cHandle,"\n\tprintstring( iptr->%s, %u );",mptr->name,dptr->type->size);
				break;
			case	_TYPE_NUMERIC :
				fprintf(cHandle,"\n\tprintbcd( iptr->%s, %u );",mptr->name,dptr->type->size);
				break;
			}
		}
	return;
}

static	VOID	stdc_print() 
{
	WORD	punctuate=':';
	TCMEMBERPTR	member;

	if (( stdc_not_whitec() == '=' )
	&&  ( stdc_not_whitec() == '1' ))
		while ( stdc_not_whitec() == punctuate ) {
			punctuate=',';
			if (!( stdc_not_white() ))
				break;
			else if ((member = stdc_co_member( TokenBuffer )) != (TCMEMBERPTR) 0)
				stdc_print_member( member, member->special );
			else	fprintf(cHandle,"\n\tprinti( %s );",TokenBuffer);
			}
	return;
}

static	WORD	stdc_put_text( text )
TCTEXTPTR	text;
{
	WORD	status=0;
	WORD	c;

	if (( text != (TCTEXTPTR) 0)
	&&  ((status = establish_value_input( text->buffer )) == 0)) {

		while (1) {
			if ( stdc_get_token() ) {
				if ( uppercase_compare( TokenBuffer,"CREATE" ) )
					stdc_create();

				else if ( uppercase_compare( TokenBuffer,"REMOVE" ) )
					stdc_remove();
			
				else if ( uppercase_compare( TokenBuffer,"FORGET" ) )
					stdc_forget();

				else if ( uppercase_compare( TokenBuffer,"PRINT" ) )
					stdc_print();

				else if ( uppercase_compare( TokenBuffer,"EXIT" ) )
					fprintf(cHandle,"return");

				else if (!( prefix_co_member( TokenBuffer ) ))
					fprintf(cHandle," %s ",TokenBuffer);
				}
			else if ((c = stdc_get_source_character()) != MOINS_UN) {
				if ( c == 0x000D )
					continue;
				else if ( c == ';' ) {
					fprintf(cHandle,",");
					continue;
					}
				else if ( c == 0x000A ) {
					fprintf(cHandle,";\n");
					continue;
					}
				else if ( c == ':' ) {
					if ((c = stdc_get_source_character()) != MOINS_UN) {
						if ( c == ':' ) {
							fprintf(cHandle,";\n");
							continue;
							}
						else	fprintf(cHandle,":");
						}
					else	{
						fprintf(cHandle,":");
						continue;
						}
					}
				fprintf(cHandle,"%c",c);
				}
			else	break;
			}

		/* Remove Current Context */
		/* ---------------------- */
		(void) pop_source_context(1);
		}
	return( status );
}


static	WORD	stdc_class_function( class, mptr, fptr )
	TCSTRUCTPTR	class;
	TCMEMBERPTR	mptr;
	TCMBMETHPTR	fptr;
{
	if ( mptr->access & _MEMBER_PUBLIC )
		fprintf(cHandle,"\npublic\t");
	else	fprintf(cHandle,"\nprivate\t");
	if ( fptr->type == (TCTYPPTR) 0)
		fprintf(cHandle,"void");
	else	stdc_type( fptr->type );
	fprintf(cHandle,"\t%s_%s(iptr",class->name,mptr->name);
	fprintf(cHandle,")");
	stdc_this( class->name );
	fprintf(cHandle,"\n{");
	stdc_put_text( fptr->value );
	fprintf(cHandle,"\n}");
	return(0);
}

static	WORD	stdc_class_common( class )
	TCSTRUCTPTR	class;
{
	TCMEMBERPTR	mptr;
	WORD		status;
	if ((mptr = class->first) != (TCMEMBERPTR) 0) {
		do	{
			if ( mptr->special != (VPTR) 0 ) {
				switch ( mptr->nature ) {
					case _KW1_CMN   :
						if ((status = stdc_class_member( "static", mptr->name, mptr->special )) != 0)
							return( status );
					}
				}
			}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}
	return( 0 );
}

static	WORD	stdc_class_structure( class )
	TCSTRUCTPTR	class;
{
	TCMEMBERPTR	mptr;
	WORD		status;
	fprintf(cHandle,"\n");
	stdc_struct( class->name );
	fprintf(cHandle," {");
	if ((mptr = class->first) != (TCMEMBERPTR) 0) {
		do	{
			if ( mptr->special != (VPTR) 0 ) {
				switch ( mptr->nature ) {
					case _KW1_IND   :
					case _KW1_OBJ   :
					case _KW1_OVL   :
					case _KW1_DCL	:
					case _KW1_PTR   :
					case _KW1_ARG   :
						if ((status = stdc_class_member( "\t",mptr, mptr->special )) != 0)
							return( status );
						else	continue;
					case _KW1_CONST :
						continue;
					default		:
						if ((status = stdc_class_method( "\t",class, mptr, mptr->special )) != 0)
							return( status );
						else	continue;

					}
				}

			}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}
	fprintf(cHandle,"\n\t};");
	return( 0 );
}

static	WORD	stdc_class_initialise( class )
	TCSTRUCTPTR	class;
{
	TCMEMBERPTR	mptr;

	if ((mptr = class->first) != (TCMEMBERPTR) 0) {
		do	{
			if ( mptr->special != (VPTR) 0 ) {
				switch ( mptr->nature ) {
					case _KW1_IND   :
					case _KW1_OBJ   :
					case _KW1_OVL   :
					case _KW1_DCL	:
					case _KW1_PTR   :
					case _KW1_ARG   :
						stdc_member_init(mptr,mptr->special,mptr->nature);
						continue;
					case _KW1_CONST :
						continue;
					default		:
						stdc_method_init(mptr,class,mptr->special);
						continue;
					}
				}

			}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}
	return( 0 );
}

static	WORD	stdc_class_initialiser( class )
	TCSTRUCTPTR	class;
{
	BPTR	nptr=class->name;
	fprintf(cHandle,"\n\npublic void init_%s(iptr)",nptr);
	stdc_this( nptr );
	fprintf(cHandle,"\n{");
	fprintf(cHandle,"\n\tif ( iptr != ");
	stdc_structcast( nptr );
	fprintf(cHandle,"0) {");
	stdc_class_initialise( class );
	fprintf(cHandle,"\n\t\t}\n\treturn;");
	fprintf(cHandle,"\n}");
	return(0);
}

static	WORD	stdc_class_special( class )
	TCSTRUCTPTR	class;
{
	BPTR	nptr=class->name;
	fprintf(cHandle,"\n\npublic void init_%s(",nptr);
	stdc_structptr(nptr );
	fprintf(cHandle," );");
	fprintf(cHandle,"\n\npublic ");
	stdc_structptr( nptr );
	fprintf(cHandle," create_%s()",nptr);
	fprintf(cHandle,"\n{\n\t");
	stdc_structptr( nptr );
	fprintf(cHandle," iptr=");
	stdc_structcast( nptr );
	fprintf(cHandle," 0;");
	fprintf(cHandle,"\n\tif ((iptr = ");
	stdc_structcast( nptr );
	fprintf(cHandle," allocate( sizeof( ");
	stdc_struct( nptr );
	fprintf(cHandle," ) )) != ");
	stdc_structcast( nptr );
 	fprintf(cHandle," 0)");
	fprintf(cHandle,"\n\t\tinit_%s( iptr );",nptr );
	fprintf(cHandle,"\n\treturn( iptr );");
	fprintf(cHandle,"\n}");
	fprintf(cHandle,"\n\npublic void remove_%s(iptr)",nptr);
	stdc_this( nptr );
	fprintf(cHandle,"\n{");
	fprintf(cHandle,"\n\tif ( iptr != ");
	stdc_structcast( nptr );
	fprintf(cHandle,"0)");
	fprintf(cHandle,"\n\t\t liberate( iptr );");
	fprintf(cHandle,"\n\treturn;");
	fprintf(cHandle,"\n}");
	return(0);
}

static	WORD	stdc_class_functions( class )
	TCSTRUCTPTR	class;
{
	TCMEMBERPTR	mptr;
	WORD		status;

	if ((status = stdc_class_special( class )) != 0)
		return( status );
	else if ((mptr = class->first) != (TCMEMBERPTR) 0) {
		do	{
			if ( mptr->special != (VPTR) 0 ) {
				switch ( mptr->nature ) {
					case _KW1_IND   :
					case _KW1_CMN   :
					case _KW1_OBJ   :
					case _KW1_OVL   :
					case _KW1_DCL	:
					case _KW1_PTR   :
					case _KW1_ARG   :
					case _KW1_CONST :
						continue;
					default		: 
						if ((status = stdc_class_function( class, mptr, mptr->special )) != 0)
							return( status );
					}
				}		
			}
		while ((mptr = mptr->next) != (TCMEMBERPTR) 0);
		}
	return( stdc_class_initialiser( class ) );
}

static	WORD	stdc_put_class( class )
	TCSTRUCTPTR	class;
{
	WORD		status;
	if ((status = stdc_class_header( class )) != 0)
		return( status );
	else if ((status = stdc_class_common( class )) != 0)
		return( status );
	else if ((status = stdc_class_structure( class )) != 0)
		return( status );
	else if ((status = stdc_class_functions( class )) != 0)
		return( status );
	else	return( stdc_class_footer( class ) );
}

static	WORD	generate_all_stdc()
{
	TCSTRUCTPTR	class;
	WORD		status;

	if ((class = World->Structures) != (TCSTRUCTPTR) 0) {
		do	{
			if (!( class->access & _MEMBER_LIBRARY ))
				if ((status = stdc_put_class( class )) != 0)
					break;
			}
		while ((class = class->next) != (TCSTRUCTPTR) 0);
		}
	StdcDone = 1;
	return( 0 );
}

static	WORD	generate_stdc( classname )
	BPTR	classname;
{
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;

	if ( uppercase_compare( classname, "ALL" ) )
		return( generate_all_stdc() );
	else if ( uppercase_compare(classname,"END") )
		return( 0 );
	else if ((class = known_structure( classname )) == (TCSTRUCTPTR) 0)
	 	return( syntax_error( 9402 ) );
	else 	return( stdc_put_class( class ) );
}

WORD	instance_stdc()
{
	WORD	status;
	if ( get_filename() ) {
		if ((cHandle = fopen( TokenBuffer,"w" )) != (FILEPTR) 0) {
			fprintf(cHandle,"/* Source Generated by OTR : Do Not Modify */\n");
			fprintf(cHandle,"#include %c%s%c\n",0x0022,"otrstd.h",0x0022);
			status = 0;
			do	{
				if ( get_token() ) {
					if ((status = generate_stdc( TokenBuffer )) != 0)
						break;
					else	continue;
					}
				else	break;
				}
			while ( is_comma() );
			fprintf(cHandle,"\n/* End of File */\n");
			fclose( cHandle );
			return( status );
			}
		else	return(syntax_error(229));
		}
	else	return(syntax_error(229));
}

#endif  /* _TRSTDC_C */
	/* --------- */
 

