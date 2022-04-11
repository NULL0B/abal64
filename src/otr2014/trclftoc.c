#ifndef	_TRCLFTOC_C
#define	_TRCLFTOC_C

#include "trclftoc.h"

PRIVATE	CLFTOCPTR	allocate_for_clftoc( type, group )
	WORD	type;
	WORD	group;
{
	CLFTOCPTR	xptr;
	if ((xptr = (CLFTOCPTR) allocate( sizeof( struct clftoc_context ))) != (CLFTOCPTR) 0) {
		xptr->type  = type;
		xptr->group = group;
		xptr->parameters = 0;
		xptr->last  = xptr->first = (TNODEPTR) 0;
		}
	return( xptr );
}

PRIVATE	VOID		collect_parameters( xptr )
	CLFTOCPTR	xptr;
{
	BPTR		vptr;
	TNODEPTR	tptr;
	while ((vptr = atoc_parameter()) != (BPTR) 0) {

		if ((tptr = allocate_tnode( strlen( vptr ) + 3 )) != (TNODEPTR) 0) {
			if (xptr->first == (TNODEPTR) 0)
				xptr->first = tptr;
			else	xptr->last->next = tptr;
			xptr->last = tptr;
			strcpy(tptr->value,vptr);
			xptr->parameters++;
			}

		else	break;

		}

	return;
}

PRIVATE	VOID		clfx_parameters( tptr, sptr )
	TNODEPTR	tptr;
	BPTR		sptr;
{
	WORD	pcount=0;
	rtl_leftbrace;
	while ( tptr != (TNODEPTR) 0) {
		if ( pcount++) rtl_comma;
		if ((*sptr)
		&&  (*(sptr++) == '&'))
			rtl_puts( avm_address( tptr->value ) );
		else	rtl_puts( avm_evaluate( tptr->value ) );
		tptr = tptr->next;
		}
	rtl_rightbrace;
	return;
}

PRIVATE	VOID		clfx_tor(gcode,tcode, avmreg, tptr, nptr, sptr )
	WORD		gcode;
	WORD		tcode;
	WORD		avmreg;	/* Number of Register to set		*/
	TNODEPTR	tptr;	/* List of parameters 			*/
	BPTR		nptr;	/* Name of Function to Call	   	*/
	BPTR		sptr;	/* Signature of function		*/
{
	BPTR		rptr;
	BPTR		hptr;
	BPTR		vptr;
	WORD		pcount=0;
	if ((hptr = allocate_for_tnode( strlen(nptr) + 16 )) != (BPTR) 0) {
		sprintf(hptr,"#F%u:%s",((tcode << 4) | gcode),nptr);
		while ( tptr != (TNODEPTR) 0 ) {
			if ((*sptr)
			&&  (*(sptr++) == '&')) {
				if ((rptr = avm_address( tptr->value )) == (BPTR) 0)
					break;
				}
			else if ((rptr = avm_evaluate( tptr->value )) == (BPTR) 0)
				break;
			if ((vptr = allocate_for_tnode( strlen(hptr) + strlen( rptr ) + 8 )) == (BPTR) 0)
				break;
			else if ( pcount++ )
				sprintf(vptr,"%s,%s",hptr,rptr);
			else	sprintf(vptr,"%s(%s",hptr,rptr);
			hptr = vptr;
			tptr = tptr->next;
			}
		if ( pcount != 0 )
			strcat( hptr,")");
		else	strcat( hptr,"()");
		use_register( avmreg, hptr );	
		}
	return;
}

PRIVATE	VOID		clf_comment( xptr )
	CLFTOCPTR	xptr;
{
	TNODEPTR	tptr;
	rtl_flushline();
	rtl_puts("/* ");
	rtl_puts("CLF"); rtl_dimensions( xptr->group ); rtl_dimensions( xptr->type ); 
	if ((tptr = xptr->first) != (TNODEPTR) 0) {
		rtl_leftbrace;
		do	{
			if ( tptr->value != (BPTR) 0)
				rtl_puts( tptr->value );
			if ( tptr->next != (TNODEPTR) 0 )
				rtl_comma;
			else 	rtl_rightbrace;
			}
		while ((tptr = tptr->next) != (TNODEPTR) 0);
		}
	rtl_puts(" */");
	return;
}


PRIVATE	VOID		clfx_toc( xptr, nptr, mode, status, sptr )
	CLFTOCPTR	xptr;	/* CLF Context			   	*/
	BPTR		nptr;	/* Name of Function to Call	   	*/
	WORD		mode;	/* Indicates VOID or Function Type 	*/
	WORD		status;	/* Value to throw on error		*/
	BPTR		sptr;	/* Signature of function		*/
{
	TNODEPTR	tptr;
	BPTR		vptr;
	BYTE		buffer[64];

	if ( OtrOption.Special )
		clf_comment( xptr );

	tptr = xptr->first;

	if ( nptr == (BPTR) 0 ) {
		nptr = buffer;
		sprintf(	buffer,
				"(*$clf[%u][%u])",
				xptr->group,
				xptr->type		);
		}

	switch ( mode ) {

		case	0 : 
			/* <crlf> VOID nptr(p1..pn); 	*/
			/* -------------------------------- */
			rtl_flushline();
			rtl_puts( nptr );
			clfx_parameters( tptr, sptr );
			rtl_semicolon;
			break;

		case	5 :
		case	1 : 
			/* p1     =    nptr(p2..pn); 		*/
			/*   or			     		*/
			/* Register[r] => nptr(parameters) 	*/
			/* -------------------------------- 	*/
			if ((vptr = tptr->value) == (BPTR) 0 )
				return;
			else if ( *vptr == 'R' )
				clfx_tor(xptr->group,xptr->type,avm_atoi((vptr+1)), tptr->next, nptr, sptr );
			else	{
				rtl_flushline();
				if ( mode & 4 ) {
					rtl_puts("copy_string");
					rtl_leftbrace;
					rtl_puts( avm_address( tptr->value ) );
					rtl_comma;
					rtl_puts( nptr );
					clfx_parameters( tptr->next, (sptr+1) );
					rtl_rightbrace;
					}
				else	{
					rtl_puts( avm_evaluate( tptr->value ) );
					rtl_equals; rtl_puts( nptr );
					clfx_parameters( tptr->next,(sptr+1) );
					}
				rtl_semicolon;
				}
			break;
			
		case	2 : /* if ( nptr(p1..pn) != 0 ) { 	*/
			    /*		throw(status); 		*/
			    /*		} 			*/
			    /* -------------------------------- */
			rtl_flushline();
			rtl_puts( "if" ); rtl_space; rtl_leftbrace;
			rtl_puts( nptr );
			clfx_parameters( tptr, sptr );
			rtl_puts( " != 0" );
			rtl_rightbrace;
			rtl_enter(1);
			rtl_flushline();
			rtl_throw( avm_evaluate( avm_integer( status )) );
			rtl_flushline();
			rtl_leave(1);
			break;

		case	3 : /* if ((p1 = nptr(p2..pn)) != 0)	*/
			    /*		throw(status); 		*/
			    /*		} 			*/
			    /* -------------------------------- */
			rtl_flushline();
			rtl_puts( "if" );
			rtl_space; rtl_leftbrace; rtl_leftbrace;
			rtl_puts( avm_evaluate( tptr->value ) );
			rtl_equals; rtl_puts( nptr );
			clfx_parameters( tptr->next, (sptr+1) );
			rtl_rightbrace;
			rtl_puts( " != 0" );
			rtl_rightbrace;
			rtl_enter(1);
			rtl_flushline();
			rtl_throw( avm_evaluate( avm_integer( status )) );
			rtl_flushline();
			rtl_leave(1);
			break;

		}
	return;
}



PRIVATE	VOID		clf0_toc( xptr )
	CLFTOCPTR	xptr;
{
	return;
}

PRIVATE	VOID		clf1_toc( xptr )
	CLFTOCPTR	xptr;
{
	return;
}

PRIVATE	VOID		clf2_toc( xptr )
	CLFTOCPTR	xptr;
{
	return;
}

PRIVATE	VOID		clf3_toc( xptr )
	CLFTOCPTR	xptr;
{
	return;
}

PRIVATE	VOID		clf4_toc( xptr )
	CLFTOCPTR	xptr;
{
	return;
}

PRIVATE	VOID		clf5_toc( xptr )
	CLFTOCPTR	xptr;
{
	BPTR	rptr;
	BPTR	vptr;
	if (( xptr->type == 0 )
	&&  ( xptr->first != (TNODEPTR) 0)
	&&  ((rptr = xptr->first->value ) != (BPTR) 0 )
	&&  ( xptr->last  != (TNODEPTR) 0)
	&&  ((vptr = xptr->last->value  ) != (BPTR) 0 )) {
		if ( *rptr == 'R' ) {
			while ( *vptr == 'R' )
				vptr = avm_resolve_register( vptr );
			if ( *vptr == 'V' )
				use_register( avm_atoi((rptr+1)), vptr );
			}
		else	rtl_affectation( avm_evaluate( rptr ), avm_address( vptr ) );
		}
	return;
}

PRIVATE	VOID		clf6_create( xptr )
	CLFTOCPTR	xptr;
{
	TCVARPTR	vptr=(TCVARPTR) 0;
	TCSTRUCTPTR	class=(TCSTRUCTPTR) 0;
	TNODEPTR	tptr;
	TNODEPTR	ttptr;
	BPTR		pptr=(BPTR) 0;
	BPTR		eptr=(BPTR) 0;

	if (((tptr = xptr->first) != (TNODEPTR) 0)
	&&  ((pptr = tptr->value) != (BPTR) 0    )) {

		if ((ttptr = tptr->next) == (TNODEPTR) 0) {

			/* Calculation of Implicite Allocation Storage Size */
			/* ------------------------------------------------ */
			if  ((eptr = avm_occupation( pptr )) != (BPTR) 0) {
				if ((ttptr = allocate_tnode( strlen( eptr ) + 4 )) != (TNODEPTR) 0) {
					strcpy( ttptr->value, eptr );
					tptr->next = ttptr;
					xptr->last = ttptr;
					}
				}
			}
		else	{
			/* Calculation of Explicite Allocation Storage Size */
			/* ------------------------------------------------ */
			while ( ttptr != (TNODEPTR) 0) {
				if ( eptr == (BPTR) 0)
					eptr = ttptr->value;
				else	eptr = avm_expression( eptr, "*", ttptr->value );
				ttptr = ttptr->next;
				}
			if ( eptr != (BPTR) 0 ) {
				if ((ttptr = allocate_tnode( strlen( eptr ) + 4 )) != (TNODEPTR) 0) {
					strcpy( ttptr->value, eptr );
					tptr->next = ttptr;
					xptr->last = ttptr;
					}
				}
			}
		if (((vptr = avm_locate( avm_atoi((pptr + 1)) )) != (TCVARPTR) 0)
		&&  ( vptr->type->type & _TYPE_DEFINED ))
			class = (TCSTRUCTPTR) vptr->type->class;

		}

	rtl_flushline();
	rtl_puts( "if" ); 
		rtl_space; rtl_leftbrace; rtl_leftbrace;
		rtl_puts( avm_evaluate( tptr->value ) );
		rtl_equals; rtl_puts(avm_cast(xptr->first->value,"\0"));
		rtl_puts( "allocate" ); clfx_parameters( tptr->next,"#" );
		rtl_rightbrace;
		rtl_puts("==");	rtl_puts(avm_cast(xptr->first->value,"I0"));
		rtl_rightbrace;
		rtl_enter(1);
			rtl_throw( avm_evaluate( "I27" ) );
			rtl_flushline();
			rtl_leave(1);

	if ( class != (TCSTRUCTPTR) 0 )
		(void) atoc_class_strings( vptr, class );
	return;
}

PRIVATE	VOID		clf6_toc( xptr )
	CLFTOCPTR	xptr;
{
	BPTR	lptr;
	BPTR	rptr;
	switch ( xptr->type ) {
		case	0x0000 : /* CREATE	*/
			clf6_create( xptr );
			break;

		case	0x0001 : /* REMOVE	*/
			clfx_toc( xptr, "liberate", 0, 0, "&" );  break;

		case	0x0002 : /* FORGET	*/
			rtl_affectation( avm_evaluate(xptr->first->value), avm_cast(xptr->first->value,"I0") );
			break;

		case	0x0003 : /* ALIAS */
			if (((lptr = xptr->first->value) != (BPTR) 0)
			&&  ((rptr = xptr->last->value) != (BPTR) 0)) {
				switch ( *lptr ) {
					case	'V' :
						rtl_affectation( avm_evaluate(lptr), avm_address(rptr) );
						break;
					case	'R' :
						use_register( avm_atoi((lptr+1)), avm_reference( rptr ) );
						break;
					}
				}
			break;

		case	0x0004 : /* ATTACH	*/
			clfx_toc( xptr, "attach", 3, 27, "&&" ); break;

		case	0x0005 : /* DETACH	*/
			clfx_toc( xptr, "detach", 0, 0, "&" );  break;

		case	0x0006 : /* ALTER	*/
			break;

		}
	return;
}



PRIVATE	VOID		clf7_toc( xptr )
	CLFTOCPTR	xptr;
{
	switch ( xptr->type ) {
		case 0x0000 :	/* WAIT		*/
			clfx_toc( xptr, "wait", 0, 0,"#" ); break;
		case 0x0001 :	/* MASK		*/
			clfx_toc( xptr, "setmask", 0, 0, "#" ); break;
		case 0x0002 :	/* RESTORE	*/
			clfx_toc( xptr, "restore", 0, 0, "#" ); break;
		case 0x0003 :	/* DATE		*/
			clfx_toc( xptr, "setdate", 0, 0, "#&" ); break;
		case 0x0004 :	/* KBF		*/
			clfx_toc( xptr, "setkbf", 0, 0, "#&" ); break;
		case 0x0005 :	/* ASKCOLOR	*/
			clfx_toc( xptr, "askcolor", 0, 0, "#" ); break;
		case 0x0006 :	/* ASKATB	*/
			clfx_toc( xptr, "askatb", 0, 0, "#" ); break;
		case 0x0007 :	/* HOTKEY	*/
			clfx_toc( xptr, "hotkey", 0, 0, "#" ); break;
		case 0x0008 :	/* LANG		*/
			clfx_toc( xptr, "lang", 0, 0, "#" ); break;
		case 0x0009 :	/* INITDATA	*/
		case 0x000A :	/* END_USER	*/
		case 0x000B :	/* END_PROC	*/
		case 0x000C :	/* END_SEGM	*/
			break;
		case 0x000D :	/* EVENT	*/
			clfx_toc( xptr, "setevent", 0, 0, "##" ); break;
		case 0x000E :	/* IPCSEND	*/
			break;
		}
	return;
}

PRIVATE	VOID		clf8_toc( xptr )
	CLFTOCPTR	xptr;
{
	switch ( xptr->type ) {
		case	0 : clfx_toc( xptr, "abs", 1, 0,"#" ); 		break;
		case    1 : clfx_toc( xptr, "includ", 0, 0,"&#&#" ); 	break;
		case    2 : clfx_toc( xptr, "tran", 0, 0,"&&&##" ); 	break;
		case    3 : clfx_toc( xptr, "insert", 0, 0,"&#&#" ); 	break;
		}
	return;
}

PRIVATE	VOID		clf9_toc( xptr )
	CLFTOCPTR	xptr;
{
	clfx_toc( xptr, (BPTR) 0, 1, 0, "##" );
	return;
}

PRIVATE	VOID		clfa_toc( xptr )
	CLFTOCPTR	xptr;
{
	switch ( xptr->type ) {
		case 0x0000 :	/* LARGE	*/
			clfx_toc( xptr, "large_string", 5, 0,"&&" ); break;
		case 0x0001 :	/* SMALL	*/
			clfx_toc( xptr, "small_string", 5, 0,"&&" ); break;
		case 0x0002 :	/* SHL		*/
			clfx_toc( xptr, "shl_string", 5, 0,"&&" ); break;
		case 0x0003 :	/* SHR		*/
			clfx_toc( xptr, "shr_string", 5, 0,"&&" ); break;
		case 0x0004 :	/* INV		*/
			clfx_toc( xptr, "inv_string", 5, 0,"&&" ); break;
		case 0x0005 :	/* FM		*/
			clfx_toc( xptr, "fm", 1, 0,"&&" ); break;
		case 0x0006 :	/* FM		*/
			clfx_toc( xptr, "fm", 1, 0,"&&" ); break;
		case 0x0007 :	/* FM		*/
			clfx_toc( xptr, "fm", 1, 0,"&&" ); break;
		case 0x0008 :	/* ENV		*/
			clfx_toc( xptr, "getenv", 1, 0,"&&" ); break;
		}
	return;
}

PRIVATE	VOID		clfb_toc( xptr )
	CLFTOCPTR	xptr;
{
	switch (xptr->type ) {
		case 0x0000 :	/* HASH		*/
			clfx_toc( xptr, "hash", 1, 0,"#&" ); break;
		case 0x0001 :	/* DEC		*/
			clfx_toc( xptr, "dec", 1, 0,"#&" ); break;
		case 0x0002 :	/* LEN		*/
			clfx_toc( xptr, "len_string", 1, 0,"#&" ); break;
		case 0x0003 :	/* LEN$		*/
			clfx_toc( xptr, "len$_string", 1, 0,"#&" ); break;
		case 0x0004 :	/* SGN		*/
			clfx_toc( xptr, "sgn", 1, 0,"##" ); break;
		case 0x0005 :	/* INDEX	*/
			clfx_toc( xptr, "index", 1, 0,"#&&" ); break;
		case 0x0006 :	/* INSTR	*/
			clfx_toc( xptr, "instr", 1, 0,"#&&#" ); break;
		case 0x0007 :	/* VPTR		*/
			clfx_toc( xptr, "vptr", 1, 0,"#&" ); break;
		case 0x0008 :	/* FMINT	*/
			clfx_toc( xptr, "fmint", 1, 0,"##" ); break;
		case 0x0009 :	/* FMFP		*/
			clfx_toc( xptr, "fmfp", 1, 0,"##" ); break;
		case 0x000A :	/* POWER	*/
			clfx_toc( xptr, "power", 1, 0,"##" ); break;
		}
	return;
}

PRIVATE	VOID		clfc_toc( xptr )
	CLFTOCPTR	xptr;
{
	WORD	mode=1;
	switch (xptr->type ) {
		case	0 :
			clfx_toc( xptr, "left_string", 5, 0, "&&#" ); break;
		case	1 :
			clfx_toc( xptr, "right_string", 5, 0, "&&#" ); break;
		case	2 :
			clfx_toc( xptr, "sub_string", 5, 0, "&&##" ); break;
		case	3 : /* MOVE */
			clfx_toc( xptr, "move", 0, 0, "&&##" ); break;
		case	4 : /* SWAP */
			clfx_toc( xptr, "swap", 0, 0, "&&##" ); break;
		case	5 :
			clfx_toc( xptr, "parse", 1, 0, "&&#" ); break;
		default	  :
			clfx_toc( xptr, (BPTR) 0, 1, 0, "&&##" ); break;
		}
	return;
}

PRIVATE	VOID		clfd_toc( xptr )
	CLFTOCPTR	xptr;
{
	TCPRCPTR	pptr;
	BPTR		vptr;

	switch ( xptr->type ) {
		case 0x0000 :	/* GENER	*/
				clfx_toc( xptr, "gener_string", 5, 0,"&#&" ); break;
		case 0x0001 :	/* SPACE	*/
				clfx_toc( xptr, "space_string", 5, 0,"&#" ); break;
		case 0x0002 :	/* DATE		*/
				clfx_toc( xptr, "date_string", 5, 0,"&#" ); break;
		case 0x0003 :	/* KBF		*/
				clfx_toc( xptr, "kbf_string", 5, 0,"&#" ); break;
		case 0x0004 :	/* CURDIR	*/
				clfx_toc( xptr, "curdir_string", 5, 0,"&" ); break;
		case 0x0005 :	/* CURVOL	*/
				clfx_toc( xptr, "curvol_string", 5, 0,"&" ); break;
		case 0x0006 :	/* HEX		*/
				clfx_toc( xptr, "hex_string", 5, 0,"&&" ); break;
		case 0x0007 :	/* CHR$		*/
				clfx_toc( xptr, "chr$_string", 5, 0,"&#" ); break;
		case 0x0008 :	/* REPSTR	*/
				clfx_toc( xptr, "repeat_string", 5, 0,"&&" ); break;
		case 0x0009 :	/* CRYPT	*/
				clfx_toc( xptr, "abal_crypt", 0, 0,"&##" ); break;
		case 0x000A :	/* SYSERROR	*/
				clfx_toc( xptr, "syserror", 1, 0,"#" ); break;
		case 0x000B :	/* PROC		*/
		case 0x000C :	/* USER		*/
		case 0x000D :	/* SEGMENT	*/
			if ((vptr = xptr->last->value) != (BPTR) 0) {
				while ( *vptr == 'R' )
					vptr = avm_resolve_register( vptr );

				switch ( *vptr ) {
					case	'I' :
						if ((pptr = avm_locate_proc( avm_atoi( (vptr + 1) ) )) != (TCPRCPTR) 0)
							rtl_affectation( avm_evaluate( xptr->first->value ), pptr->name );
						break;
					case	'V' :
						rtl_affectation( avm_evaluate( xptr->first->value ), avm_evaluate( vptr ) );
						break;
					}
				}
		}
	return;
}

PRIVATE	VOID		clfe_toc( xptr )
	CLFTOCPTR	xptr;
{
	switch ( xptr->type ) {
		case 0x0000 : clfx_toc( xptr, "fix", 1, 0, "##"); break;
		case 0x0001 : clfx_toc( xptr, "roun", 1, 0, "##"); break;
		case 0x0002 : clfx_toc( xptr, "fp", 1, 0, "##"); break;
		case 0x0003 : clfx_toc( xptr, "int", 1, 0, "##"); break;
		case 0x0004 : clfx_toc( xptr, "val", 1, 0, "##"); break;
		case 0x0005 : clfx_toc( xptr, "stdform", 1, 0, "##"); break;
		case 0x0006 : clfx_toc( xptr, "real", 1, 0, "##"); break;
		case 0x0007 : clfx_toc( xptr, "strn", 1, 0, "##"); break;
		case 0x0008 : clfx_toc( xptr, "long", 1, 0, "##"); break;
		}
	return;
}

PRIVATE	VOID		clff_toc( xptr )
	CLFTOCPTR	xptr;
{
	switch ( xptr->type ) {
		case 0x0000 : clfx_toc( xptr, "col", 1, 0, "##"); break;
		case 0x0001 : clfx_toc( xptr, "lin", 1, 0, "##"); break;
		case 0x0002 : clfx_toc( xptr, "process", 1, 0, "#"); break; 
		case 0x0003 : clfx_toc( xptr, "rnd", 1, 0, "#"); break;
		case 0x0004 : clfx_toc( xptr, "getmask", 1, 0, "#"); break; 
		case 0x0005 : clfx_toc( xptr, "conf", 1, 0, "##"); break;
		case 0x0006 : clfx_toc( xptr, "erradr", 1, 0, "#"); break;
		case 0x0007 : clfx_toc( xptr, "restore", 1, 0, "#"); break; 
		case 0x0008 : clfx_toc( xptr, "eventadr", 1, 0, "#"); break;
		case 0x0009 : clfx_toc( xptr, "gethotkey", 1, 0, "#"); break; 
		case 0x000A : clfx_toc( xptr, "getevent", 1, 0, "##"); break;
		}
	return;
}

PRIVATE	WORD	clf_to_c( i )
	WORD	i;
{
	WORD		tcode;
	WORD		gcode;
	CLFTOCPTR	xptr=(CLFTOCPTR) 0;

	gcode = tcode = GetTcodeByte(i++); tcode >>= 4;
	parameter_start( i );
	if ((xptr = allocate_for_clftoc( (tcode & 0x000F), (gcode & 0x000F) )) != (CLFTOCPTR) 0) {
		collect_parameters( xptr );
		switch ( xptr->group ) {
			case	0x0000 : clf0_toc( xptr ); break;
			case	0x0001 : clf1_toc( xptr ); break;
			case	0x0002 : clf2_toc( xptr ); break;
			case	0x0003 : clf3_toc( xptr ); break;
			case	0x0004 : clf4_toc( xptr ); break;
			case	0x0005 : clf5_toc( xptr ); break;
			case	0x0006 : clf6_toc( xptr ); break;
			case	0x0007 : clf7_toc( xptr ); break;
			case	0x0008 : clf8_toc( xptr ); break;
			case	0x0009 : clf9_toc( xptr ); break;
			case	0x000A : clfa_toc( xptr ); break;
			case	0x000B : clfb_toc( xptr ); break;
			case	0x000C : clfc_toc( xptr ); break;
			case	0x000D : clfd_toc( xptr ); break;
			case	0x000E : clfe_toc( xptr ); break;
			case	0x000F : clff_toc( xptr ); break;
			}
		}
	return( parameter_flush(i) );
}

#endif	/* _TRCLFTOC_C */
	/* ----------- */


