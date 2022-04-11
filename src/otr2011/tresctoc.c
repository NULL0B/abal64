
#ifndef	_TRESCTOC_C
#define	_TRESCTOC_C


PRIVATE	VOID		esc_call_parameters(pptr)
	TCVARPTR	pptr;
{
	WORD	pcount=0;
	BPTR	vptr;
	rtl_leftbrace;
	while ((vptr = atoc_parameter()) != (BPTR) 0) {
		if ( pptr == (TCVARPTR) 0) {
			if ((vptr = avm_evaluate( vptr )) == (BPTR) 0)
				break;
			}
		else	{
			switch (pptr->type->type & _TYPE_SPECIAL ) {
				case	_TYPE_POINTER 	:
				case	_TYPE_MBPTR	:
					vptr = avm_address( vptr );
					break;
				default			:
					vptr = avm_contents( vptr );
				}
			if ( vptr == (BPTR) 0 )
				break;
			else	pptr = pptr->next;
			}
		if ( pcount++ )
			rtl_comma;
		rtl_puts( vptr );
		}
	rtl_rightbrace;
	return;
}

PRIVATE	BPTR		esc_reg_parameters(pptr)
	TCVARPTR	pptr;
{
	WORD	pcount=0;
	BPTR	vptr;
	BPTR	hptr="(";
	BPTR	tptr=(BPTR) 0;

	while ((vptr = atoc_parameter()) != (BPTR) 0) {
		if ( pptr == (TCVARPTR) 0) {
			if ((vptr = avm_evaluate( vptr )) == (BPTR) 0)
				break;
			}
		else	{
			switch (pptr->type->type & _TYPE_SPECIAL ) {
				case	_TYPE_POINTER 	:
				case	_TYPE_MBPTR	:
					vptr = avm_address( vptr );
					break;
				default			:
					vptr = avm_contents( vptr );
				}
			if ( vptr == (BPTR) 0 )
				break;
			else	pptr = pptr->next;
			}
		if ((tptr = allocate( strlen(hptr) + strlen( vptr ) + 8 )) != (BPTR) 0 ) {
			if ( pcount++ )
				sprintf(tptr,"%s,%s",hptr,vptr);
			else	sprintf(tptr,"(%s",vptr);
			hptr = tptr;
			}
		else	break;
		}
	if ( strlen(hptr) == 1 )
		return("()");
	else	{
		strcat( hptr, ")" );
		return( hptr );
		}		
}

PRIVATE	VOID	esc_call_indirect( iptr )
	BPTR	iptr;
{
	TCVARPTR	vptr;
	TCTYPPTR	tptr;
	VPTR		mptr;
	BPTR		xptr;
	BPTR		hptr;
	if ((vptr = avm_locate(avm_atoi((iptr+1)))) != (TCVARPTR) 0) {

		/* Ensure Variable has Type */
		/* ------------------------ */
		if ((tptr = vptr->type) == (TCTYPPTR) 0)
			return;

		/* Detect Class Method Pointers */
		/* ---------------------------- */
		if ((mptr = (VPTR) tptr->class) != (VPTR) 0) {

			/* Detect Class Method with known Result Type */
			/* ------------------------------------------ */
			if ((tptr = resolve_method_type(mptr)) != (TCTYPPTR) 0) {
				if (((hptr = esc_reg_parameters(resolve_method_parameters(mptr))) != (BPTR) 0)
				&&  ((iptr = avm_evaluate( iptr )) != (BPTR) 0)
				&&  ((xptr = allocate_for_tnode( strlen(iptr) + strlen( hptr ) + 16 )) != (BPTR) 0)) {
					sprintf(xptr,"#V%u:(*%s)%s",vptr->descriptor,iptr,hptr);
					use_register( 53, xptr );
					}
				return;

				}
			else	{
				/* Void Class Method Pointer */
				/* ------------------------- */
				rtl_flushline();
				rtl_leftbrace;
				rtl_putptr();
				rtl_puts( avm_evaluate( iptr ) );
				rtl_rightbrace;
				esc_call_parameters(
					resolve_method_parameters(mptr));
				rtl_semicolon;
				return;
				}
			}
		else	{
			/* ABAL PROC unknown return type */
			/* ----------------------------- */
			return;
			}
		}
	return;
}
	
PRIVATE	VOID	esc_call_direct( iptr )
	BPTR	iptr;
{
	TCPRCPTR	pptr;
	TCTYPPTR	tptr;
	BPTR		xptr;
	BPTR		hptr;
	
	if ((pptr = avm_locate_proc(avm_atoi((iptr+1)))) != (TCPRCPTR) 0) {
		/* Detect Procedure Function with known Result Type */
		/* ------------------------------------------------ */
		if ((tptr = pptr->result) != (TCTYPPTR) 0) {
			if (((hptr = esc_reg_parameters(pptr->parameter)) != (BPTR) 0)
			&&  ((xptr = allocate_for_tnode( strlen(pptr->name) + strlen( hptr ) + 16 )) != (BPTR) 0)) {
				sprintf(xptr,"#P%u:%s%s",pptr->identity,pptr->name,hptr);
				use_register( 53, xptr );
				}
			return;

			}
		else	{
			/* Call Direct Void Now */
			/* -------------------- */
			rtl_flushline();
			rtl_puts( pptr->name );
			esc_call_parameters(pptr->parameter);
			rtl_semicolon;
			}
		}
	return;
}
	
/*
 * This function ( ESC _ CALL ) is called in response to the instructions :
 *
 *	ESC CLP
 *
 *	LDE
 *
 */

PUBLIC 	WORD	esc_call( offset )
	WORD	offset;
{
	BPTR	tptr;
	parameter_start( offset );
	if ((tptr = atoc_parameter()) == (BPTR) 0) return( 0 );
	switch (*tptr) {
		case	'V' : esc_call_indirect( tptr ); break;
		case	'I' : esc_call_direct( tptr ); break;
		default	    : return(0);
		}
	return( parameter_flush( offset ) );
}


PRIVATE	WORD	esc_expression_table( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	BPTR	rptr=avm_register( GetTcodeByte(offset++) );
	WORD	nombre=GetTcodeWord(offset);
	WORD	item=1;
	offset += 2;
	rtl_switch( avm_evaluate( rptr ) );
	while ( nombre  > 0 ) {
		rtl_case( item++ );
		switch ( tcode ) {
			case	_esc_JMR : /* 0x0032	JUMP EXPRESSION	TABLE	*/
				rtl_goto( GetTcodeWord( offset ) );
				break;
			case	_esc_GSR : /* 0x0052	GOSUB EXPRESSION TABLE	*/
				rtl_gosub( GetTcodeWord( offset ) );
				rtl_puts(" break;");
				break;
			}
		offset += 2;
		nombre--;
		}
	rtl_endswitch();
	return( offset );
}

PRIVATE	WORD	esc_throw( tcode, offset )
	WORD	tcode;
	WORD	offset;
{
	BPTR	rptr;
	switch ( tcode ) {
		case	_esc_RTI : /* 0x0028	ERROR WORD		*/
			if ((rptr = avm_integer( GetTcodeWord(offset) )) == (BPTR) 0 )
				return( 0 );
			else	{
				offset += 2;
				break;
				}

		case	_esc_RTV : /* 0x002C	ERROR VARB		*/
			if ((rptr = avm_variable( GetTcodeWord(offset) )) == (BPTR) 0 )
				return( 0 );
			else	{
				offset += 2;
				break;
				}

		case	_esc_RTR : /* 0x002E	ERROR REG		*/
			if ((rptr = avm_register( GetTcodeByte(offset++) )) == (BPTR) 0 )
				return( 0 );
			else	break;
		default	:
			return( 0 );
		}
	rtl_throw( avm_evaluate( rptr ) );
	return( offset );
}

PUBLIC	WORD	esc_to_c( i )
	WORD	i;
{
	WORD	tcode;
	switch ((tcode = GetTcodeByte( i++ ))) {
		case	_esc_PSI : /* 0x0013	PAUSE    WORD		*/
		case	_esc_PSC : /* 0x0033	PAUSE CONSTANT		*/
		case	_esc_PSV : /* 0x0053	PAUSE VARIABLE		*/
		case	_esc_PSR : /* 0x0073	PAUSE EXPRESSION	*/
			i = atoc_statement( _AVM_PAUSE,  tcode, i );
			break;

		case	_esc_CLP : /* 0x0017	CALL	PROCEDURE	*/
			i = esc_call( i );
			break;

		case	_esc_RTS : /* 0x0026	RET.SEG			*/
		case	_esc_ETS : /* 0x0027	END.SEG			*/
			avm_method_return();
			break;

		case	_esc_RTI : /* 0x0028	ERROR WORD		*/
		case	_esc_RTV : /* 0x002C	ERROR VARB		*/
		case	_esc_RTR : /* 0x002E	ERROR REG		*/
			i = esc_throw( tcode, i );
			break;

		case	_esc_SGW : /* 0x0070	LDGO.SEG WORD		*/
		case	_esc_SGV : /* 0x0050	LDGO.SEG VARIABLE	*/
			i++;
 		case	_esc_SGI : /* 0x0010	LDGO.SEG BYTE		*/
		case	_esc_SGR : /* 0x0030	LDGO.SEG EXPRESSION	*/
			i++;
			break;

		case	_esc_JMR : /* 0x0032	JUMP EXPRESSION	TABLE	*/
		case	_esc_GSR : /* 0x0052	GOSUB EXPRESSION TABLE	*/
			i = esc_expression_table( tcode, i );
			break;

		case	_esc_RTP : /* 0x0046	EXIT			*/
		case	_esc_ETP : /* 0x0047	END.PROC		*/
			avm_method_return();
			break;

		case	_esc_RGT : /* 0x0042	EXIT			*/
		case	_esc_RGS : /* 0x0062	STOP			*/
			i += 3; break;

		case	_esc_STP : /* 0x0066	STOP			*/
			rtl_void_statement( _AVM_STOP );
			break;

		default		 : 
			/* All other codes cause Failure */
			/* ----------------------------- */
			return(0);
		}	
	return(i);
}

#endif	/* _TRESCTOC_C */
	/* ----------- */











