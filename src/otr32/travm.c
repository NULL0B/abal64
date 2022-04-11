#ifndef	_TRAVM_C
#define _TRAVM_C

#include "travm.h"

PRIVATE	struct tcode_type AvmType;

PRIVATE TCTYPPTR AvmReturnType=(TCTYPPTR) 0;

/* ----------------------------- */
/* Forward Definition Prototypes */
/* ----------------------------- */
PUBLIC	TCTYPPTR	avm_resolve_type( BPTR );
PUBLIC	BPTR		avm_evaluate( BPTR );
PUBLIC	BPTR		avm_address( BPTR );
PUBLIC	BPTR		avm_contents( BPTR );


PUBLIC	VOID		avm_set_return( tptr )
	TCTYPPTR	tptr;
{
	AvmReturnType = tptr;
	return;
}

BYTE	RegBuffer[256];

PUBLIC	VOID	use_register( number, vptr )
	WORD	number;
	BPTR	vptr;
{
	if ( number < _ATOC_REGISTERS ) {
		if ( vptr != (BPTR) 0 )
			AtocRegister[ number ] = vptr;
		else	AtocRegister[ number ] = "Z";
		}
	if ( number > AtocRegisters )
		AtocRegisters = number;

	if ( OtrOption.Special ) {
		sprintf(RegBuffer,"R[%u] = %s",number,AtocRegister[number]);	
		rtl_comment( RegBuffer );
		}
	return;
}



PUBLIC	BPTR	avm_integer( v )
	WORD	v;
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode( 8 )) != (BPTR) 0)
		sprintf(tptr,"I%u",v);
	return( tptr );
}

PUBLIC	BPTR	avm_numeric( v )
	WORD	v;
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode( 8 )) != (BPTR) 0)
		sprintf(tptr,"%u",v);
	return( tptr );
}

PUBLIC	BPTR	avm_variable( v )
	WORD	v;
{
	BPTR		nptr=(BPTR) 0;
	if ((nptr = allocate_for_tnode( 16 )) != (BPTR) 0)
		sprintf(nptr,"V%u",v);
	return( nptr );
}

PUBLIC	BPTR	avm_hexvariable( v )
	WORD	v;
{
	BPTR		nptr=(BPTR) 0;
	if ((nptr = allocate_for_tnode( 16 )) != (BPTR) 0)
		sprintf(nptr,"H%X",v);
	return( nptr );
}

PUBLIC	TCPRCPTR	avm_locate_proc( pid )
	WORD		pid;
{
	TCPRCPTR	lptr;
	if ((lptr = Context->PDT) != (TCPRCPTR) 0) {
		do	{
			if ( lptr->identity == pid )
				break;
			}
		while ((lptr = lptr->next) != (TCPRCPTR) 0);
		}
	return( lptr );
}

PUBLIC	TCVARPTR	avm_locate( v )
	WORD		v;
{
	TCVDTPTR	tptr;
	TCVARPTR	vptr;
	WORD		identity=v;
	if ( v & ISLOCAL )
		tptr = Context->LDT;
	else	tptr = Context->GDT;

	if ((vptr = tptr->first) != (TCVARPTR) 0) {
		while ( vptr != (TCVARPTR) 0) {
			if  ( (vptr->descriptor & TOGLOBAL) == ( identity & TOGLOBAL ) )
				break;
			else	vptr = vptr->prev;
			}
		}
	return( vptr );
}

PUBLIC	BPTR	avm_constant( v )
	WORD	v;
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode( 8 )) != (BPTR) 0)
		sprintf(tptr,"C%u",v);
	return( tptr );
}

PUBLIC	BPTR	avm_register( v )
	WORD	v;
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode( 8 )) != (BPTR) 0)
		sprintf(tptr,"R%u",v);
	return( tptr );
}

PUBLIC	BPTR	avm_expression( lptr, optr, rptr )
	BPTR	lptr;
	BPTR	optr;
	BPTR	rptr;
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode( strlen(lptr) + strlen(optr) + strlen(rptr) + 16)) != (BPTR) 0)
		sprintf(tptr,"(%s %s %s)",lptr,optr,rptr);
	return( tptr );
}

PRIVATE	WORD	avm_atoi( sptr )
	BPTR	sptr;
{
	WORD	result=0;
	while (( *sptr )
	&&     ( *sptr >= '0') 
	&&     ( *sptr <= '9'))
		result = ((result * 10) + ( *(sptr++) -'0' ));
	return( result );
}

PUBLIC	TCTYPPTR	avm_variable_type( tptr )
	BPTR		tptr;
{
	TCVARPTR	vptr;
	if (( vptr = avm_locate( avm_atoi( (tptr + 1) ) )) != (TCVARPTR) 0)
		return( vptr->type );
	else	return((TCTYPPTR) 0);
}

PUBLIC	TCTYPPTR	avm_indirect_type( varid )
	WORD		varid;
{
	TCTYPPTR	tptr=(TCTYPPTR) 0;
	TCVARPTR	vptr;
	if ((vptr = avm_locate( varid )) != (TCVARPTR) 0)
		tptr = resolve_method_type( vptr->type->class );
	return( tptr );
}

PUBLIC	TCTYPPTR	avm_direct_type( procid )
	WORD		procid;
{
	TCTYPPTR	tptr=(TCTYPPTR) 0;
	TCPRCPTR	pptr;
	if ((pptr = (TCPRCPTR)avm_locate_proc( procid )) != (TCPRCPTR) 0)
		tptr = pptr->result;
	return( tptr );
}

PUBLIC	TCTYPPTR	avm_standard_type( t )
	WORD		t;
{
	AvmType.type = t;
	AvmType.class = (VPTR) 0;
	return( & AvmType );
}

PUBLIC	TCTYPPTR	avm_clf_type( clfcode )
	WORD		clfcode;
{
	TCTYPPTR	tptr=(TCTYPPTR) 0;
	switch ( (clfcode & 0x000F )) {

		case	0x0000 : 
		case	0x0001 : 
		case	0x0002 : 
		case	0x0003 : 
		case	0x0004 : 
		case	0x0006 : 
		case	0x0007 : return( (TCTYPPTR) 0);

		case	0x0005 : 
		case	0x000B : 
		case	0x000F : return( avm_standard_type( _TYPE_INT16 ) );

		case	0x0008 : if (clfcode & 0x00F0)
					return((TCTYPPTR) 0);
		case	0x0009 : 
		case	0x000E : return( avm_standard_type( _TYPE_NUMERIC ) );

		case	0x000A : 
			switch ( (clfcode & 0x00F0) >> 4 ) {
				case	0x0005 :
				case	0x0006 :
				case	0x0007 : return((TCTYPPTR) 0);
				default	       : return(avm_standard_type( _TYPE_STRING | _TYPE_POINTER ));
				}

		case	0x000C : 
			switch ( (clfcode & 0x00F0) >> 4 ) {
				case	0x0003 :
				case	0x0004 : return((TCTYPPTR) 0);
				default	       : return(avm_standard_type( _TYPE_STRING | _TYPE_POINTER ));
				}
		case	0x000D : 
			if (((clfcode & 0x00F0) >> 4 ) < 9 ) 
				return(avm_standard_type( _TYPE_STRING | _TYPE_POINTER ));
			else	return((TCTYPPTR) 0);

		}
	return( tptr );
}

PUBLIC	TCTYPPTR	avm_function_type( xptr )
	BPTR		xptr;
{
	TCTYPPTR	tptr=(TCTYPPTR) 0;
	if ( *(xptr++) == '#' ) {
		switch ( *(xptr++) ) {
			case	'I'     :	/* Integer Function sizeof etc */
				return( avm_standard_type( _TYPE_INT16 ) );
			case	'V'	:	/* Indirect Proc Function Call 	*/
				return( avm_indirect_type( avm_atoi(xptr) ) );
			case	'P'	:	/* Direct   Proc Function Call 	*/
				return( avm_direct_type( avm_atoi(xptr) ) );
			case	'F'	:	/* Common Library Function Call	*/
				return( avm_clf_type( avm_atoi( xptr ) ) );
			}
		}
	return( tptr );
}

PUBLIC	TCTYPPTR	avm_expression_type( tptr )
	BPTR		tptr;
{
	while ( *tptr == '(' )
		tptr++;
	return( avm_resolve_type( tptr ) );	
}

PUBLIC	BPTR	avm_occupation( tptr )
	BPTR	tptr;
{
	TCSTRUCTPTR	class;
	TCVARPTR	vptr;
	WORD		size=0;
	while ((*tptr) && (*tptr == ' ')) tptr++;
	switch ( *tptr ) {
		case	'V' :
			if (( vptr = avm_locate( avm_atoi((tptr+1)) )) != (TCVARPTR) 0) {
				if (( vptr->type->type & _TYPE_DEFINED )
				&&  ((class = (TCSTRUCTPTR)vptr->type->class) != (TCSTRUCTPTR) 0)
				&&  ((tptr = allocate_for_tnode( strlen( class->name ) + 34 )) != (BPTR) 0))
					sprintf(tptr,"#I:sizeof(struct _%s)",class->name);
				else	tptr = avm_integer( (vptr->type->size * vptr->type->first * vptr->type->second ));
				}
			break;

		}
	return( tptr );
}

PUBLIC	BPTR		avm_constant_entry( v, cptr, pptr )
	WORD		v;
	TCCONPTR	cptr;
	BPTR		pptr;
{
	BPTR		nptr=(BPTR) 0;
	while ( cptr != (TCCONPTR) 0) {

		if ( cptr->identity == v ) {
			if ( cptr->name != (BPTR) 0 ) {
				if (( nptr = allocate_for_tnode( strlen( cptr->name ) + 3 )) != (BPTR) 0)
					sprintf(nptr,"%s",cptr->name);
				break;
				}
			else 	{
				if (( nptr = allocate_for_tnode( 16 )) != (BPTR) 0)
					sprintf(nptr,"$%s%u",pptr,cptr->identity);
				break;
				}
			}
		else	cptr = cptr->next;
		}
	return( nptr );
}


PUBLIC	BPTR	avm_constanter( v )
	WORD	v;
{
	BPTR		nptr;

	if ((nptr = avm_constant_entry( v, Context->LCT,"LC" )) != (BPTR) 0)
		return( nptr );
	if ((nptr = avm_constant_entry( v, Context->GCT,"GC" )) != (BPTR) 0)
		return( nptr );
	else	return( avm_constant( v ) );
}

PRIVATE	BPTR	avm_evaluate_primary( regid, lptr )
	WORD	regid;
	BPTR	lptr;
{
	BPTR	rptr;
	BPTR	dptr;
	if ((( rptr = AtocPrimary[regid]) != (BPTR) 0)
	&&  (( rptr = avm_evaluate( rptr )) != (BPTR) 0)
	&&  (( dptr = allocate_for_tnode( strlen(lptr) + strlen(rptr) + 16 )) != (BPTR) 0)) {
		sprintf(dptr,"%s[(%s-1)]",lptr,rptr);
		return( dptr );
		}
	else	return( lptr );
}

PRIVATE	BPTR	avm_evaluate_secondary( regid, lptr )
	WORD	regid;
	BPTR	lptr;
{
	BPTR	rptr;
	BPTR	dptr;
	if ((( rptr = AtocSecondary[regid]) != (BPTR) 0)
	&&  (( rptr = avm_evaluate( rptr )) != (BPTR) 0)
	&&  (( dptr = allocate_for_tnode( strlen(lptr) + strlen(rptr) + 16 )) != (BPTR) 0)) {
		sprintf(dptr,"%s[(%s-1)]",lptr,rptr);
		return( dptr );
		}
	else	return( lptr );
}

PUBLIC	BPTR	avm_resolver( v, indexreg )
	WORD	v;
	WORD	indexreg;
{
	BPTR		nptr=(BPTR) 0;
	TCVDTPTR	tptr;
	TCVARPTR	vptr;
	BPTR		hptr=(BPTR) 0;
	WORD		identity=v;
	if ( v & ISLOCAL )
		tptr = Context->LDT;
	else	tptr = Context->GDT;

	if ((vptr = tptr->first) != (TCVARPTR) 0) {
		while ( vptr != (TCVARPTR) 0) {
			if  ( (vptr->descriptor & TOGLOBAL) == ( identity & TOGLOBAL ) ) {
				while ( vptr->parent != (TCVARPTR) 0 )
					vptr = vptr->parent;
				if ( nptr == (BPTR) 0 ) {
					while ( vptr->overloads != (TCVARPTR) 0) {
						vptr = vptr->overloads;
						while ( vptr->parent != (TCVARPTR) 0)
							vptr = vptr->parent;
						}
					if ((nptr = allocate_for_tnode( strlen(vptr->name)+4 )) == (BPTR) 0)
						break;
					else if  ((!( vptr->type->type & _TYPE_DEFINED ))
					     &&   (   vptr->type->class != (VPTR) 0))
						sprintf(nptr,"$%s",vptr->name);
					else	strcpy( nptr, vptr->name );
					if ( vptr->type->type & _TYPE_FIRST ) {
						nptr = avm_evaluate_primary(indexreg,nptr);
						if ( vptr->type->type & _TYPE_FIRST )
							nptr = avm_evaluate_secondary(indexreg,nptr);
						}
					}
				else	{
					if ((hptr = allocate_for_tnode( strlen(vptr->name)+strlen(nptr)+8 )) == (BPTR) 0)
						break;
					else	{
						switch ( vptr->type->type & _TYPE_SPECIAL ) {
							case _TYPE_POINTER :
							case _TYPE_MBPTR   :
								if (( compare_tokens( vptr->name, "THIS" ) )
								&&  ( get_pragma_output() > 0 ))
									sprintf(hptr,"%s",nptr);
								else	sprintf(hptr,"%s->%s",vptr->name,nptr);
								break;
							default		   :
								if (( compare_tokens( vptr->name, "THIS" ) )
								&&  ( get_pragma_output() > 0 ))
									sprintf(hptr,"%s",nptr);
								else	sprintf(hptr,"%s.%s",vptr->name,nptr);
								break;
							}
						nptr = hptr;
						}
					}
				if ((identity = vptr->master) != 0)
					vptr = tptr->first;
				else 	return( nptr );
				}
			else	vptr = vptr->prev;
			}
		}
	return( avm_hexvariable( v ) );
}


PUBLIC	BPTR	avm_calculator( tptr )
	BPTR	tptr;
{
	BPTR	lptr;
	BPTR	rptr;
	BPTR	optr;
	while ((*tptr) && (*tptr == ' ')) tptr++;
	lptr = tptr;
	while ((*tptr) && (*tptr != ' ')) tptr++;
	while ((*tptr) && (*tptr == ' ')) tptr++;
	optr = tptr;
	while ((*tptr) && (*tptr != ' ')) tptr++;
	while ((*tptr) && (*tptr == ' ')) tptr++;
	rptr = tptr;
	lptr = avm_evaluate( lptr );
	rptr = avm_evaluate( rptr );
	if ((tptr = allocate_for_tnode( strlen(lptr) + strlen(rptr) + 8 )) != (BPTR) 0)
		sprintf(tptr,"(%s %c %s)",lptr,*optr,rptr);
	return( tptr );
}

PUBLIC	BPTR	avm_resolve_register( tptr )
	BPTR	tptr;
{
	if ((tptr = AtocRegister[ avm_atoi((tptr+1)) ]) != (BPTR) 0)
		return( tptr );
	else	return("Z");
}

PUBLIC	BPTR	avm_evaluate( tptr )
	BPTR	tptr;
{
	WORD	index_register=0;
	while ( tptr != (BPTR) 0 ) {

		switch ( *tptr ) {
			case	'*' : 
				return( avm_address( (tptr+1) ) );
			case	'(' :
				return( avm_calculator( (tptr+1) ) );
			case	'C' :
				return( avm_constanter(avm_atoi((tptr+1))) );
			case	'V' :
				return( avm_resolver(avm_atoi((tptr+1)), index_register ) );
			case	'#' :
				while (( *tptr ) && ( *tptr != ':' )) tptr++;
				if ( *tptr == ':' ) tptr++;
				return( tptr );

			case	'I' : 
				return( avm_numeric( avm_atoi((tptr+1))) );
			case	'R' : 
				if (!( index_register ))
					index_register = avm_atoi((tptr + 1));
				tptr = avm_resolve_register( tptr );
				continue;
					
			default	    :
				return( tptr );
			}
		}
	return("Z");
}

PUBLIC	BPTR	avm_reference( tptr )
	BPTR	tptr;
{
	BPTR	rptr;
	if ((rptr = allocate_for_tnode( strlen(tptr) + 4 )) != (BPTR) 0)
		sprintf(rptr,"*%s",tptr);
	return( rptr );
}

PUBLIC	TCTYPPTR	avm_resolve_type( tptr )
	BPTR	tptr;
{
	while ( *tptr == 'R' )
		tptr = avm_resolve_register( tptr );
	switch ( *tptr ) {
		case	'Z' :
		case	'I' : return( avm_standard_type( _TYPE_INT16 ) );
		case	'C' : return( avm_standard_type( _TYPE_STRING ) );
		case	'V' : return( avm_variable_type( tptr ) );
		case	'#' : return( avm_function_type( tptr ) );
		case	'(' : return( avm_expression_type( tptr ) );
		default	    : return( (TCTYPPTR) 0 );
		}
}

PUBLIC	BPTR	avm_contents( xptr )
	BPTR	xptr;
{
	TCTYPPTR	tptr;
	BPTR		rptr;

	if ((tptr = avm_resolve_type( xptr )) == (TCTYPPTR) 0)
		return( "0" );
	else if ((xptr = avm_evaluate( xptr )) == (BPTR) 0)
		return( "0" );
	else	{
		switch ( tptr->type & _TYPE_SPECIAL ) {
			case	_TYPE_POINTER	:
			case	_TYPE_MBPTR	:
				if ((rptr = allocate_for_tnode( strlen( xptr ) + 5 )) == (BPTR) 0)
					return( xptr );
				else	{
					sprintf(rptr,"*%s",xptr);
					return( rptr );
					}
			default			:
				return( xptr );
			}
		}
}

PUBLIC	BPTR	avm_address( xptr )
	BPTR	xptr;
{
	TCTYPPTR	tptr=(TCTYPPTR) 0;
	BPTR		rptr=(BPTR) 0;
	BPTR		iptr;
	if ( *xptr == 'R' ) {
		iptr = xptr;
		while ( *iptr == 'R' )
			if ((iptr = avm_resolve_register( iptr )) == (BPTR) 0)
				return("0");
		if ( *iptr == 'I' )
			return( avm_evaluate( iptr ) );
		}

	else if ( *xptr == 'I' )
		return( avm_evaluate( xptr ) );

	if ((tptr = avm_resolve_type( xptr )) == (TCTYPPTR) 0)
		return( "0" );

	else if ((xptr = avm_evaluate( xptr )) == (BPTR) 0)
		return( "0" );
	else	{
		switch ( tptr->type & _TYPE_SPECIAL ) {
			case	_TYPE_POINTER	:
			case	_TYPE_MBPTR	:
				return( xptr );
			default			:
				if ((rptr = allocate_for_tnode( strlen( xptr ) + 5 )) == (BPTR) 0)
					return( xptr );
				else	{
					sprintf(rptr,"&%s",xptr);
					return( rptr );
					}
			}
		}
}

PUBLIC	BPTR	avm_constant_address( tptr )
	BPTR	tptr;
{
	BPTR	hptr;
	BPTR	rptr;
	if (((hptr = avm_evaluate( tptr )) != (BPTR) 0)
	&&  ((rptr = allocate_for_tnode( strlen( hptr ) + 8 )) != (BPTR) 0)) {
		sprintf( rptr, "&%s",hptr);
		return( rptr );
		}
	else	return( tptr );
}

PUBLIC	BPTR	avm_condition( tcode )
	WORD	tcode;
{
	switch ((tcode & 0x000F)) {
		case 0x0008 : return("==");
		case 0x0009 : return("!=");
		case 0x000A : return(">=");
		case 0x000B : return("<=");
		case 0x000C : return(">");
		case 0x000D : return("<");
		case 0x000E : return("==");
		case 0x000F : return("!=");
		default	    : return("??");
		}
}

PUBLIC	BPTR	avm_operator( tcode )
	WORD	tcode;
{
	switch ((tcode & 0x000F)) {
		case 0x0008 : return("+");
		case 0x0009 : return("-");
		case 0x000A : return("*");
		case 0x000B : return("/");
		case 0x000C : return("%");
		case 0x000D : return("&");
		case 0x000E : return("|");
		case 0x000F : return("^");
		default	    : return("@");
		}
}

PUBLIC 	WORD	avm_gosub( offset )
	WORD	offset;
{
	WORD	label=GetTcodeWord( offset );
	rtl_gosub( label );
	return( offset + 2 );
}

PUBLIC 	WORD	avm_goto( offset )
	WORD	offset;
{
	WORD	label=GetTcodeWord( offset );
	offset += 2;
	if ( label != offset )
		rtl_goto( label );
	return( offset );
}

PUBLIC	WORD	avm_optimised_load( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	BPTR	tptr=(BPTR) 0;
	WORD	target=GetTcodeByte(offset++);
	WORD	value=GetTcodeByte(offset);
	offset += 2;
	switch ( (tcode & 0x007F) ) {
		case	_tc_GIL :
			if ((tptr = allocate_for_tnode( 16 )) == (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"G%u",value);
				break;
				}
		case	_tc_GCL :
			if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"g%u",value);
				break;
				}
		case	_tc_LIL :
			if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"L%u",value);
				break;
				}
		case	_tc_LCL :
			if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"l%u",value);
				break;
				}
		default		:
			return( 0 );
		}
	use_register( target, tptr );
	return( offset );
}

PUBLIC	VOID	avm_string_store( tptr, sptr )
	BPTR	tptr;
	BPTR	sptr;
{	
	rtl_flushline();
	rtl_puts("copy_string"); 
	rtl_leftbrace;
		rtl_puts( avm_address( tptr ) );
		rtl_comma;
		rtl_puts( avm_address( sptr ) );
	rtl_rightbrace;
	rtl_semicolon;
	return;
}

PUBLIC	WORD	avm_optimised_store( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	TCVARPTR	vptr;
	WORD	value;
	BPTR	tptr=(BPTR) 0;
	BPTR	sptr=(BPTR) 0;

	switch ( (tcode & 0x007F) ) {
		case	_tc_GWS :
			if ((sptr = avm_integer( GetTcodeWord(offset) )) == (BPTR) 0)
				return(0);
			else	{
				offset += 2;
				if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
					return( 0 );
				else	{
					sprintf(tptr,"G%u",GetTcodeWord(offset));
					offset += 2;
					break;
					}
				}

		case	_tc_LWS :
			if ((sptr = avm_integer( GetTcodeWord(offset) )) == (BPTR) 0)
				return(0);
			else	{
				offset += 2;
				if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
					return( 0 );
				else	{
					sprintf(tptr,"L%u",GetTcodeWord(offset));
					offset += 2;
					break;
					}
				}

		case	_tc_GIS :
			if ((sptr = AtocRegister[ GetTcodeByte(offset++)]) == (BPTR) 0)
				return(0);
			else if ((tptr = allocate_for_tnode( 16 )) == (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"G%u",GetTcodeWord(offset));
				offset += 2;
				break;
				}
		case	_tc_GCS :
			if ((sptr = AtocRegister[ GetTcodeByte(offset++)]) == (BPTR) 0)
				return(0);
			else if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"g%u",GetTcodeWord(offset));
				offset += 2;
				break;
				}
		case	_tc_LIS :
			if ((sptr = AtocRegister[ GetTcodeByte(offset++)]) == (BPTR) 0)
				return(0);
			else if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"L%u",GetTcodeWord(offset));
				offset += 2;
				break;
				}

		case	_tc_LCS :
			if ((sptr = AtocRegister[ GetTcodeByte(offset++)]) == (BPTR) 0)
				return(0);
			else if ((tptr = allocate_for_tnode( 16 ))== (BPTR) 0) 
				return( 0 );
			else	{
				sprintf(tptr,"l%u",GetTcodeWord(offset));
				offset += 2;
				break;
				}
		default		:
			return( 0 );
		}


	if (((vptr = avm_locate( avm_atoi((tptr+1)) ))!= (TCVARPTR) 0)
	&&  (( vptr->type->type & (_TYPE_DEFINED | _TYPE_STRING)) == _TYPE_STRING ))
		avm_string_store( tptr, sptr );
	else	rtl_affectation( avm_evaluate(tptr), avm_evaluate( sptr ) );
	return( offset );

}

PUBLIC	WORD	avm_load_register( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	WORD	target=GetTcodeByte(offset++);
	BPTR	tptr;

	switch ((tcode & 0x0070) ) {

		case	0x0000 :

			if ((tptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				use_register(target,tptr);
				return( offset + 2 );
				}
			else	break;

		case	0x0020 :

			if ((tptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				use_register(target,tptr);
				return( offset + 2 );
				}
			else	break;

		case	0x0040 :

			if ((tptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				use_register(target,tptr);
				return( offset + 2 );
				}
			else	break;

		case	0x0060 :

			if ((tptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0) {
				while ( *tptr == 'R' )
					tptr = avm_resolve_register( tptr );
				use_register(target,tptr);
				return( offset );
				}
			else	break;
		}
	return( 0 );
}

PUBLIC	WORD	avm_load_primary( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	WORD	target=GetTcodeByte(offset++);
	BPTR	tptr;

	switch ((tcode & 0x0070) ) {

		case	0x0000 :

			if ((tptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				AtocPrimary[target] = tptr;
				return( offset + 2 );
				}
			else	break;

		case	0x0020 :

			if ((tptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				AtocPrimary[target] = tptr;
				return( offset + 2 );
				}
			else	break;

		case	0x0040 :

			if ((tptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				AtocPrimary[target] = tptr;
				return( offset + 2 );
				}
			else	break;

		case	0x0060 :

			if ((tptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0) {
				AtocPrimary[target] = tptr;
				return( offset );
				}
			else	break;
		}
	return( 0 );
}

PUBLIC	WORD	avm_store( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	TCVARPTR	vptr;
	BPTR	sptr;
	BPTR	tptr;

	switch ((tcode & 0x0060)) {
		case	0x0000 :
			if ((sptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);
		case	0x0020 :
			if ((sptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);

		case	0x0040 :
			if ((sptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);
		case	0x0060 :
			if ((sptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0)
				break;
			else	return(0);
		default		:
			return( 0 );
		}

	if ((tptr = avm_variable( GetTcodeWord(offset) )) == (BPTR) 0)
		return( 0 );
	else 	{
		if (((vptr = avm_locate( avm_atoi((tptr+1)) ))!= (TCVARPTR) 0)
		&&  (( vptr->type->type & (_TYPE_DEFINED | _TYPE_STRING)) == _TYPE_STRING ))
			avm_string_store( tptr, sptr );
		else	rtl_affectation( avm_evaluate(tptr), avm_evaluate( sptr ) );
		return( offset + 2 );
		}
}

PUBLIC	WORD	avm_load_secondary( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	WORD	target=GetTcodeByte(offset++);
	BPTR	tptr;

	switch ((tcode & 0x0070) ) {

		case	0x0000 :

			if ((tptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				AtocSecondary[target] = tptr;
				return( offset + 2 );
				}
			else	break;

		case	0x0020 :

			if ((tptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				AtocSecondary[target] = tptr;
				return( offset + 2 );
				}
			else	break;

		case	0x0040 :

			if ((tptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				AtocSecondary[target] = tptr;
				return( offset + 2 );
				}
			else	break;

		case	0x0060 :

			if ((tptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0) {
				AtocSecondary[target] = tptr;
				return( offset );
				}
			else	break;
		}
	return( 0 );
}

PUBLIC	WORD	avm_unary( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	WORD	avalue=GetTcodeByte(offset++);

	return( offset );
}

PUBLIC	WORD	avm_operation( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	BPTR	lptr=avm_register(GetTcodeByte(offset++));
	BPTR	rptr;
	WORD	rvalue;

	switch ((tcode & 0x0060)) {
		case	0x0000 :
			if ((rptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);
		case	0x0020 :
			if ((rptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);

		case	0x0040 :
			if ((rptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);
		case	0x0060 :
			if ((rptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0)
				break;
			else	return(0);
		default		:
			return( 0 );
		}

	use_register( GetTcodeByte(offset++), 
		avm_expression( lptr, avm_operator(tcode), rptr ) );

	return( offset );
}

PUBLIC	WORD	avm_compare( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	BPTR	lptr=avm_register( GetTcodeByte(offset++) );
	BPTR	rptr=(BPTR) 0;
	WORD	label;

	switch ((tcode & 0x0060)) {
		case	0x0000 :
			if ((rptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);
		case	0x0020 :
			if ((rptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);

		case	0x0040 :
			if ((rptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else	return(0);
		case	0x0060 :
			if ((rptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0)
				break;
			else	return(0);
		default		:
			return( 0 );
		}

	label=GetTcodeWord(offset); offset += 2;

	rtl_compare( 	avm_evaluate( lptr ),
			avm_condition( tcode  ),
			avm_evaluate( rptr ),
			label  );

	return( offset );
}

PUBLIC	WORD	avm_convert( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	return( offset+ 3 );
}

PUBLIC	WORD	avm_catcher( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	BPTR	vptr;
	if ((vptr = avm_variable( GetTcodeWord(offset) )) == (BPTR) 0)
		return( 0 );
	else	{
		offset += 2;
		rtl_flushline();
		rtl_puts("rtl_catch");
		rtl_leftbrace;
		rtl_puts(avm_evaluate(vptr));
		rtl_comma;
		rtl_label( GetTcodeWord( offset ) );
		rtl_rightbrace;
		rtl_semicolon;
		offset += 2;
		return( offset );
		}
}

PUBLIC	VOID	avm_method_return()
{
	BPTR	vptr=(BPTR) 0;
	if ( AvmReturnType != (TCTYPPTR) 0)
		if ((vptr = AtocRegister[53]) != (BPTR) 0)
			vptr = avm_evaluate( vptr );
	rtl_return( vptr );
	return;
}

PUBLIC	BPTR		avm_type( tptr )
	TCTYPPTR	tptr;
{
	BPTR		lptr="\0";
	BPTR		rptr="\0";
	TCSTRUCTPTR	class;
	if ( tptr->type & _TYPE_DEFINED ) {
		if (((class = (TCSTRUCTPTR) tptr->class) != (TCSTRUCTPTR) 0)
		&&  ((lptr = allocate_for_tnode( strlen( class->name ) + strlen( "struct" ) + strlen( _RTL_PTR ) + 16 )) != (BPTR) 0)) {
			switch ( tptr->type & _TYPE_SPECIAL ) {
				case _TYPE_POINTER :
				case _TYPE_MBPTR   :
					sprintf(lptr,"struct _%s %s",class->name,_RTL_PTR);
					break;
				default		   :
					sprintf(lptr,"struct _%s",class->name);
				}
			return( lptr );
			}
		}
	else	{
		switch ( tptr->type & _TYPE_BASIC ) {
			case	_TYPE_INT8	:
				return(_RTL_INT8);
			case	_TYPE_INT16	:
				return(_RTL_INT16);
			case	_TYPE_NUMERIC	:
				if ( tptr->size > 8 )
					return(_RTL_DOUBLE);
				else	return(_RTL_FLOAT);
			case	_TYPE_STRING	:
				return(_RTL_STRING );
			}
		}
	switch ( tptr->type & _TYPE_SPECIAL ) {
		case _TYPE_POINTER :
		case _TYPE_MBPTR   :
			return("void *");
		default		   :
			return("void");
		}
}



PUBLIC	BPTR	avm_cast( tptr , xptr )
	BPTR	tptr;
	BPTR	xptr;
{
	TCVARPTR	vptr;
	BPTR		hptr;
	BPTR		rptr;
	BPTR		cptr;
	switch ( *tptr ) {
		case	'V' :
			if (((vptr = avm_locate( avm_atoi( (tptr + 1) ) )) != (TCVARPTR) 0)
			&&  ((hptr = avm_type( vptr->type )) != (BPTR) 0)) {
				switch ( vptr->type->type & _TYPE_SPECIAL ) {
					case _TYPE_POINTER :
					case _TYPE_MBPTR   :
						if (!(*xptr))
							cptr = xptr;
						else if ((cptr = avm_address( xptr )) == (BPTR) 0)
							return( xptr );
						break;
					default		   :
						if (!( *xptr ))
							cptr = xptr;
						else if ((cptr = avm_contents( xptr )) == (BPTR) 0)
							return( xptr );
						break;
					}
				if ((rptr = allocate_for_tnode( strlen( hptr ) + strlen( cptr ) + 8 )) != (BPTR) 0) {
					sprintf(rptr,"(%s)%s",hptr,cptr);
					return( rptr );
					}
				}

		default	    :
			return( xptr );
		}
}

#endif	/* _TRAVM_C */
	/* -------- */




