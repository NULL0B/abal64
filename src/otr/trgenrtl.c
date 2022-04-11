#define	DEBUG
#ifndef	_TRGENRTL_C
#define	_TRGENRTL_C

#define	_C_RTL_GEN
#define _GEN_C_RTL

#include <stdio.h>
#include <errno.h>		/* Error return definitions		*/
#include <fcntl.h>
#include "stdtypes.h"
#include "translat.h"
#include "troption.h"
#include "trexpres.h"
#include "trproc.h"
#include "troutput.h"
#include "trsyntax.h"
#include "triof.h"
#include "trclf.h"
#include "trdebug.h"
#include "trgenc.h"
#include "trtnode.h"

EXTERN	WORD	LocalDataTableCount;
EXTERN	BPTR	DataTableName;
EXTERN	WORD	DataTableType;
EXTERN	WORD	RtlFormatCount;

BPTR	allocate_for_string( BPTR );
EXTERN	BYTE	TokenBuffer[];

EXTERN	WORD	RtlHotkeys;
EXTERN	HOTPTR	RtlHotHead;
EXTERN	WORD	RtlRegisters;
	WORD	RtlCatchError=0;
	WORD	RtlIofDoLoop=0;

WORD	set_target_encryption( valeur )
WORD	valeur;
{
	return(0);
}

WORD	get_target_encryption()
{
	return( MOINS_UN );
}

WORD	is_virtual_variable( vptr )
TCVARPTR	vptr;
{
	if ((   vptr->type->type & 0x8000 )
	||  (   vptr->type->type & 0x4000 )
	||  (!( vptr->type->type & 0x3F00 )))
		return( 0 );
	else	return(((vptr->type->type & 0x3F00) >> 8));
}

BPTR	generate_string_constant( cptr )
TCCONPTR	cptr;
{
	BPTR	tptr;
	BPTR	xptr;
	WORD	i;
	WORD	l;
	BPTR	vptr;
	if (((vptr = cptr->value) == (BPTR) 0 )
	||  ((l = cptr->length)   == 0        )
	||  ((tptr = allocate_for_tnode(l+4)) == (BPTR) 0))
		return((BPTR) 0);
	xptr = tptr;
	*(tptr++) = 0x0022;
	for ( i = 0; i < l; i++ )
		*(tptr++) = *(vptr++);
	*(tptr++) = 0x0022;
	*(tptr++) = 0;

	return( xptr );
}

BPTR	global_data_table_name();

BPTR	generate_variable_name( vptr )
TCVARPTR	vptr;
{
	BPTR	rptr;
	WORD	extra=0;
	BPTR	fptr=(BPTR) 0;
	BPTR	sptr=(BPTR) 0;
	BPTR	tptr;
	WORD	handle;

	trace("generate_variable_name()\n");
	if ((handle = is_virtual_variable( vptr )) != 0 ) {
		(void) syntax_error(3029);				
		return( (BPTR) 0 );
		}
	if ( vptr->identity & ISLOCAL )
		tptr = (BPTR) "LDS";
	else	tptr = global_data_table_name();
	extra = (strlen( tptr ) + 16);
	if ( tptr == (BPTR) 0 )
		return( tptr );
	if ((vptr->type->type & 0x0040) 
	&& ((fptr = (BPTR) vptr->firstdim) != (BPTR) 0)) {
		extra += (strlen( fptr ) + 10);
		if ((vptr->type->type & 0x0020) 
		&& ((sptr = (BPTR) vptr->secondim) != (BPTR) 0))
			extra += (strlen( sptr )+10);
		}
	if ((rptr = allocate_for_tnode( strlen(vptr->name) + extra )) == (BPTR) 0)
		return((BPTR) 0 );
	if ( vptr->identity & ISLOCAL )
		sprintf(rptr,"%s%u_%s",tptr,LocalDataTableCount,vptr->name);
	else	sprintf(rptr,"%s0_%s",tptr,vptr->name);
	if ( fptr != (BPTR) 0 ) {
		trace("generate_first_dimension()\n");
		if ( vptr->type->size > 1 )
			sprintf(rptr,"%s+((%s-1) * %u)",rptr,fptr,vptr->type->size); 
		else	sprintf(rptr,"%s+(%s-1)",rptr,fptr); 
		if ( sptr != (BPTR) 0 ) {
			trace("generate_second_dimension()\n");
			sprintf(rptr,"%s+((%s-1) * %u)",rptr,sptr,(vptr->type->size*vptr->type->first)); 
			}
		}
	return( rptr );
}

BPTR	generate_pointer_adresse( vptr )
TCVARPTR	vptr;
{
	BPTR	rptr;
	BPTR	tptr;
	WORD	extra=0;
	WORD	handle;
	trace("generate_pointer_adresse()\n");

	if ((handle = is_virtual_variable( vptr )) != 0 ) {
		(void) syntax_error(3030);				
		return( (BPTR) 0 );
		}
	if ( vptr->identity & ISLOCAL )
		tptr = (BPTR) "LDS";
	else	tptr = global_data_table_name();
	extra = (strlen( tptr ) + 16);
	if ( tptr == (BPTR) 0 )
		return( tptr );
	if ((rptr = allocate_for_tnode( strlen(vptr->name) + extra )) == (BPTR) 0)
		return((BPTR) 0 );
	if ( vptr->identity & ISLOCAL )
		sprintf(rptr,"%s%u$%s",tptr,LocalDataTableCount,vptr->name);
	else	sprintf(rptr,"%s0$%s",tptr,vptr->name);
	return( rptr );
}

BPTR	generate_pointer_vector( vptr )
TCVARPTR	vptr;
{
	BPTR	rptr;
	BPTR	tptr;
	WORD	extra=0;
	WORD	handle;

	trace("generate_variable_name()\n");

	if ((handle = is_virtual_variable( vptr )) != 0 ) {
		(void) syntax_error(3031);				
		return( (BPTR) 0 );
		}
	if ( vptr->identity & ISLOCAL )
		tptr = (BPTR) "LDS";
	else	tptr = global_data_table_name();
	extra = (strlen( tptr ) + 32);
	if ( tptr == (BPTR) 0 )
		return( tptr );
	if ((rptr = allocate_for_tnode( strlen(vptr->name) + extra )) == (BPTR) 0)
		return((BPTR) "(ERROR27)" );
	trace("generate_variable_prefix()\n");
	if ( vptr->identity & ISLOCAL )
		sprintf(rptr,"%s%u$%s,%u",tptr,LocalDataTableCount,vptr->name,vptr->type->size);
	else	sprintf(rptr,"%s0$%s,%u",tptr,vptr->name,vptr->type->size);
	trace(rptr);
	trace("fin_gvn()\n");
	return( rptr );
}

WORD		rewrite_virtual_variable( handle, vptr, zptr )
WORD		handle;
TCVARPTR	vptr;
BPTR		zptr;
{
	if ( zptr != (BPTR) 0 ) {
		generate_indentation( Output );
		fprintf(Output->handle,"if ((_rtl_status = rtl_write_vmem(%u,%lu,%s)) != 0) { %s; }\n",
			handle,(WORD)vptr->offset,zptr,_RTL_RAISE_ERROR);
		}
	return( 0 );
}

BPTR	virtual_svalue( vptr, handle )
TCVARPTR	vptr;
WORD	handle;
{
	BPTR	zptr;
	generate_indentation( Output );
	switch ((vptr->type->type & 3)) {
		case	0	:
		case	1	:
		case	3	:
		case	2	:
			if ((zptr = NewStringRegister(vptr->type->size)) == (BPTR) 0)
				(void) allocation_failure();
			break;
		}
	if ( zptr != (BPTR) 0 ) {
		generate_indentation( Output );
		fprintf(Output->handle,"if ((_rtl_status = rtl_read_vmem(%u,%lu,%s)) != 0) { %s; }\n",
			handle,(WORD)vptr->offset,zptr,_RTL_RAISE_ERROR);
		}
	return(zptr);
}

BPTR	virtual_rvalue( vptr, handle )
TCVARPTR	vptr;
WORD	handle;
{
	BPTR	zptr;
	generate_indentation( Output );
	switch ((vptr->type->type & 3)) {
		case	0	:
		case	1	:
		case	3	:
		case	2	:
			if ((zptr = NewStringRegister(vptr->type->size)) == (BPTR) 0)
				(void) allocation_failure();
			break;
		}
	if ( zptr != (BPTR) 0 ) {
		generate_indentation( Output );
		fprintf(Output->handle,"if ((_rtl_status = rtl_read_vmem(%u,%lu,%s)) != 0) { %s; }\n",
			handle,(WORD)vptr->offset,zptr,_RTL_RAISE_ERROR);
		}
	if ((zptr = allocate_for_tnode( 64 )) == (BPTR) 0)
		return( zptr );

	switch ((vptr->type->type & 3)) {
		case	0	:
				sprintf(zptr,"*(AVMP(%u))",RtlRegisters);
				break;
		case	1	:
				sprintf(zptr,"getabalword(AVMP(%u))",RtlRegisters);
				break;
		case	3	:
				sprintf(zptr,"clf_cnvatoi(AVMP(%u),AVML(%u))",RtlRegisters,RtlRegisters);
				break;
		case	2	:
				sprintf(zptr,"clf_cnvbtoi(AVMP(%u),AVML(%u))",RtlRegisters,RtlRegisters);
				break;
		}
	return(zptr);
}

BPTR		variable_rvalue( vptr )
TCVARPTR	vptr;
{
	BPTR	tptr;
	BPTR	wptr;
	WORD	handle;

	if ((handle = is_virtual_variable( vptr )) != 0 )
		return( virtual_rvalue( vptr, handle ) );
	switch ((vptr->type->type & 3)) {
		case	0	:
		
			if ((wptr = generate_variable_name( vptr )) == (BPTR) 0)
				return( wptr );
			if ((tptr = allocate_for_tnode(strlen(wptr)+8)) != (BPTR) 0)
				sprintf(tptr,"*( %s )",wptr);
			else	return( tptr );
			break;
		case	1	:
			if ((wptr = generate_variable_name( vptr )) == (BPTR) 0)
				return( wptr );
			if ((tptr = allocate_for_tnode(strlen(wptr)+18)) != (BPTR) 0)
				sprintf(tptr,"(getabalword( %s ))",wptr);
			else	return( tptr );
			break;
		case	2	:
			if ((wptr = generate_variable_name( vptr )) == (BPTR) 0)
				return( wptr );
			if ((tptr = allocate_for_tnode(strlen(wptr)+32)) != (BPTR) 0)
				sprintf(tptr,"clf_cnvbtoi(%s,%u)",generate_variable_name(vptr),vptr->type->size);
			else	return( tptr );
			break;
		case	3	:
			if ((wptr = generate_variable_name( vptr )) == (BPTR) 0)
				return( wptr );
			if ((tptr = allocate_for_tnode(strlen(wptr)+32)) != (BPTR) 0)
				sprintf(tptr,"clf_cnvatoi(%s,%u)",generate_variable_name(vptr),vptr->type->size);
			else	return( tptr );
			break;
		}
	return( tptr );
}

BPTR		variable_svalue( vptr )
TCVARPTR	vptr;
{
	BPTR	tptr;
	BPTR	wptr;
	WORD	handle;

	if ((handle = is_virtual_variable( vptr )) != 0 )
		return( virtual_svalue( vptr, handle ) );

	switch ((vptr->type->type & 3)) {
		case	0	:
		case	1	:
			tptr = generate_variable_name( vptr );
		case	3	:
		case	2	:
			if ((wptr = generate_variable_name( vptr )) == (BPTR) 0)
				return( wptr );
			if ((tptr = allocate_for_tnode(strlen(wptr)+4)) != (BPTR) 0)
				sprintf(tptr,"%s,%u",generate_variable_name(vptr),vptr->type->size);
			break;
		}
	return( tptr );
}

BPTR	NewBcdRegister()
{
	BPTR	xterm;

	generate_indentation( Output );
	fprintf(Output->handle,"if ((_rtl_status = create_bcd_register( %u,12)) != 0) { %s; }\n",++RtlRegisters,_RTL_RAISE_ERROR);

	if ((xterm = allocate_for_tnode( 48 )) != (BPTR) 0)
		sprintf(xterm,"AVMP(%u),AVML(%u)",RtlRegisters,RtlRegisters);
	return( xterm );
}

BPTR	NewStringRegister(size)
WORD	size;
{
	BPTR	xterm;

	generate_indentation( Output );
	fprintf(Output->handle,"if ((_rtl_status = create_string_register( %u,%u)) != 0) { %s; }\n",++RtlRegisters,size,_RTL_RAISE_ERROR);

	if ((xterm = allocate_for_tnode( 48 )) != (BPTR) 0)
		sprintf(xterm,"AVMP(%u) ,AVML(%u)",RtlRegisters,RtlRegisters);
	return( xterm );
}

static	BPTR	rtlconvtob( vptr )
TCVARPTR	vptr;
{
	BPTR	tptr=(BPTR) 0;
	BPTR	rptr;
	BPTR	wptr;
	
	if (( rptr = NewBcdRegister()) != (BPTR) 0) {
		switch ((vptr->type->type & 3)) {
			case	0	:
			case	1	:
				if ((wptr = variable_rvalue(vptr)) == (BPTR) 0)
					return( wptr );
				else if ((tptr = allocate_for_tnode(strlen(wptr)+strlen(rptr)+16)) == (BPTR) 0)
					return( tptr );
				sprintf(tptr,"clf_cnvitob(%s,%s)",rptr,wptr);
				generate_indentation( Output);
				fprintf( Output->handle, "%s;\n",tptr);
				break;
			case	3	:
				if ((wptr = variable_svalue(vptr)) == (BPTR) 0)
					return( wptr );
				else if ((tptr = allocate_for_tnode(strlen(wptr)+strlen(rptr)+16)) == (BPTR) 0)
					return( tptr );
				sprintf(tptr,"clf_cnvatob(%s,%s)",rptr,wptr);
				generate_indentation( Output);
				fprintf( Output->handle, "%s;\n",tptr);
				break;
			}
		tptr = rptr;
		}
	else	tptr = (BPTR) 0;
	return( tptr );
}

static	BPTR	rtlconvtos( vptr )
TCVARPTR	vptr;
{
	BPTR	tptr=(BPTR) 0;
	BPTR	rptr=(BPTR) 0;
	BPTR	wptr;
	switch ((vptr->type->type & 3)) {
		case	0	:
		case	1	:
			if (( rptr = NewStringRegister(6)) == (BPTR) 0)
				return( rptr );
			else if ((wptr = variable_rvalue(vptr)) == (BPTR) 0)
				return( wptr );
			else if ((tptr = allocate_for_tnode(strlen(rptr)+strlen(wptr)+16)) == (BPTR) 0)
				return( tptr );
			sprintf(tptr,"clf_cnvitoa(%s,%s)",rptr,wptr);
			generate_indentation( Output);
			fprintf( Output->handle, "%s;\n",tptr);
			break;

		case	2	:
			if (( rptr = NewStringRegister(25)) == (BPTR) 0)
				return( rptr );
			else if ((wptr = variable_svalue(vptr)) == (BPTR) 0)
				return( wptr );
			else if ((tptr = allocate_for_tnode(strlen(rptr)+strlen(wptr)+16)) == (BPTR) 0)
				return( tptr );
			sprintf(tptr,"clf_cnvbtoa(%s,%s)",rptr,wptr);
			generate_indentation( Output);
			fprintf( Output->handle, "%s;\n",tptr);
			break;
		}
	return( rptr );
}

static	BPTR	rtlconvtoi( vptr )
TCVARPTR	vptr;
{
	BPTR	tptr=(BPTR) 0;
	BPTR	wptr;
	switch ((vptr->type->type & 3)) {
		case	2	:
			if ((wptr = variable_svalue( vptr )) == (BPTR) 0)
				return( wptr );
			else if ((tptr = allocate_for_tnode(strlen(wptr)+16)) == (BPTR) 0)
				return( tptr );
			sprintf(tptr,"clf_cnvbtoi(%s)",wptr);
			break;
		case	3	:
			if ((wptr = variable_svalue( vptr )) == (BPTR) 0)
				return( wptr );
			else if ((tptr = allocate_for_tnode(strlen(wptr)+16)) == (BPTR) 0)
				return( tptr );
			sprintf(tptr,"clf_cnvatoi(%s)",wptr);
			break;
		}
	return( tptr );
}

BPTR		variable_cnv_svalue( vptr, type )
TCVARPTR	vptr;
WORD		type;
{
	trace("variable_cnv_svalue()\n");
	if (( vptr->type->type & 3) == type )
		return( variable_svalue(vptr) );
	else	{
		switch ( type ) {
			case	0	:
			case	1	:
				return( rtlconvtoi( vptr ) );
			case	2	:
				return( rtlconvtob( vptr ) );
			case	3	:
				return( rtlconvtos( vptr ) );
			}
		return((BPTR) 0);
		}
}

BPTR	RtlTypeConvertor( wptr, otype, type )
BPTR	wptr;
WORD	otype;
WORD	type;
{
	BPTR	tptr;
	BPTR	rptr;


	switch ( type ) {
		case	0	:
		case	1	:
			switch ( otype ) {
				case	0 :
				case	1 :
					return( wptr );
				case	2 :
					if ((tptr = allocate_for_tnode(strlen(wptr)+16)) == (BPTR) 0)
						return( tptr );
					sprintf(tptr,"clf_cnvbtoi(%s)",wptr);
					break;
				case	3 :
					if ((tptr = allocate_for_tnode(strlen(wptr)+16)) == (BPTR) 0)
						return( tptr );
					sprintf(tptr,"clf_cnvatoi(%s)",wptr);
					break;
				}
			return( tptr );
		case	MOINS_UN :
		case	2	 :
			switch ( otype ) {
				case	2 :
					rptr = wptr;
					break;
				case	0 :
				case	1 :
					if (( rptr = NewBcdRegister()) == (BPTR) 0)
						return( rptr );
					else if ((tptr = allocate_for_tnode(strlen(rptr)+strlen(wptr)+16)) == (BPTR) 0)
						return( tptr );
					sprintf(tptr,"clf_cnvitob(%s,%s)",rptr,wptr);
					generate_indentation( Output);
					fprintf( Output->handle, "%s;\n",tptr);
					break;
				case	3 :
					if (( rptr = NewBcdRegister()) == (BPTR) 0)
						return( rptr );
					else if ((tptr = allocate_for_tnode(strlen(rptr)+strlen(wptr)+16)) == (BPTR) 0)
						return( tptr );
					sprintf(tptr,"clf_cnvatob(%s,%s)",rptr,wptr);
					generate_indentation( Output);
					fprintf( Output->handle, "%s;\n",tptr);
					break;
				}
			return( rptr );
		case	3	:
			switch ( otype ) {
				case	3 :
					rptr = wptr;
					break;
				case	0 :
				case	1 :
					if (( rptr = NewStringRegister(6)) == (BPTR) 0)
						return( rptr );
					else if ((tptr = allocate_for_tnode(strlen(rptr)+strlen(wptr)+16)) == (BPTR) 0)
						return( tptr );
					sprintf(tptr,"clf_cnvitoa(%s,%s)",rptr,wptr);
					generate_indentation( Output);
					fprintf( Output->handle, "%s;\n",tptr);
					break;
				case	2 :
					if (( rptr = NewStringRegister(25)) == (BPTR) 0)
						return( rptr );
					else if ((tptr = allocate_for_tnode(strlen(rptr)+strlen(wptr)+16)) == (BPTR) 0)
						return( tptr );
					sprintf(tptr,"clf_cnvbtoa(%s,%s)",rptr,wptr);
					generate_indentation( Output);
					fprintf( Output->handle, "%s;\n",tptr);
					break;
				}
			return( rptr );
		}

}


BPTR	RtlConvertToType( wptr, type )
BPTR	wptr;
WORD	type;
{
	WORD	otype=2;

	trace("RtlConvertToType("); trace( wptr ); trace(")\n");

	if ( *wptr == '#' ) {
		wptr++;
		otype = ( *(wptr++) - '0' );
		}

	return( RtlTypeConvertor( wptr, otype, type ) );
}

VOID	generate_iof_doloop()
{
	WORD	status;
	if ((!( RtlIofDoLoop ))
	&&  ((status = generate_do()) == 0))
		RtlIofDoLoop = VRAI;
	return;
}
	

WORD	generate_rtliof_print( xptr )
BPTR	xptr;
{
	WORD	type=3;
	if ( *xptr == '#' ) {
		xptr++;
		type = ( *(xptr++) - '0' );
		}
	else	type = 3;

	switch (type) {
		case	0	:
			fprintf(Output->handle,"iof_print_int8(%s);\n",xptr); break;
		case	1	:
			fprintf(Output->handle,"iof_print_int16(%s);\n",xptr); break;
		case	2	:
			fprintf(Output->handle,"iof_print_bcd(%s);\n",xptr); break;
		case	3	:
			fprintf(Output->handle,"iof_print_string(%s);\n",xptr); break;

		}
	return(0);
}

WORD	generate_rtl_hotkeys(hptr)
HOTPTR	hptr;
{
	BPTR	tptr;
	WORD	status;
	BPTR	lptr;
	BPTR	xptr;
	WORD	type;
	WORD	nombre=0;

	if ((tptr = allocate_for_tnode(256)) == (BPTR) 0)
		return( allocation_failure() );

	while ( hptr != (HOTPTR) 0 ) {
		
		switch ( hptr->nature ) {
			case	_hot_I 	: sprintf(tptr,"27"); break;
			case	_hot_U 	: sprintf(tptr,"11"); break;
			case	_hot_D 	: sprintf(tptr," 5"); break;
			case	_hot_L 	: sprintf(tptr," 8"); break;

			case	MOINS_UN :
				if (( xptr = hptr->operand) == (BPTR) 0)
					return( not_yet_available() );				
				if ( *xptr == '#' ) {
					xptr++;
					type = ( *(xptr++) - '0' );
					}
				else	type = 1;
				switch ( type ) {
					case 0 :
					case 1 :
						sprintf(tptr,"%s",xptr); 
						break;
					case 2 :
					case 3 :
						sprintf(tptr,"is_iof_hotkey(_rtl_hotkey,%s)",xptr); 
						break;
					}
				break;
			}

		generate_case( tptr, 1 );
		if (( lptr = hptr->label ) != (BPTR) 0) {
			if ( *lptr == '&' ) {
				if ( hptr->gosub )
					generate_gosub( lptr );
				else	generate_goto_instruction( lptr );
				}
			else if ( RtlIofDoLoop )
				generate_break();

			}
		else	return( syntax_error(3032) );
		nombre++;
		hptr = hptr->next;
		}
	return(0);
}

WORD	generate_rtliof_ask( xptr )
BPTR    xptr;
{
	BPTR	tptr;
	WORD	type=3;
	if ( *xptr == '#' ) {
		xptr++;
		type = ( *(xptr++) - '0' );
		}
	else	type = 3;
	if ((tptr = allocate_for_tnode( strlen( xptr ) + 32 )) == (BPTR) 0)
		return( allocation_failure() );
	switch (type) {
		case	0	:
			sprintf(tptr,"iof_ask_int8(%s)",xptr); break;
		case	1	:
			sprintf(tptr,"iof_ask_int16(%s)",xptr); break;
		case	2	:
			sprintf(tptr,"iof_ask_bcd(%s)",xptr); break;
		case	3	:
			sprintf(tptr,"iof_ask_string(%s)",xptr); break;
		}

	fprintf(Output->handle,"_rtl_hotkey = %s;\n",tptr);
	if (RtlHotkeys) {
		generate_select("_rtl_hotkey");
		generate_rtl_hotkeys(RtlHotHead);
		generate_default();
		if ( RtlIofDoLoop )
			generate_break();
		generate_endsel();
		}
	if ( RtlIofDoLoop ) {
		RtlIofDoLoop = FAUX;
		return( generate_loop() );
		}
	else	return(0);
}

WORD	generate_rtliof_device( rptr )
BPTR	rptr;
{
	WORD	type=3;
	trace("rtliof_device("); trace( rptr ); trace(")\n");
	if ( *rptr == '#' ) {
		rptr++;
		type = ( *(rptr++) - '0' );
		}
	else	type = 3;
	if ( type < 2 )
		fprintf(Output->handle,"iof_device(%s);\n",rptr);
	else	fprintf(Output->handle,"iof_device_buffer(%s);\n",rptr);
	return(0);
}

WORD		generate_iof_instruction( opcode, rptr )
WORD		opcode;
BPTR 		rptr;
{
	BPTR	tptr=(BPTR) 0;
	generate_indentation( Output );
	switch ( opcode ) {
		case 	_iof_TABC	:
			fprintf(Output->handle,"iof_tabc(%s);\n",rptr); break;
		case 	_iof_ATB	:
			fprintf(Output->handle,"iof_atb(%s);\n",rptr); break;
		case 	_iof_PRN	:
			return(generate_rtliof_print( rptr ));
		case 	_iof_TABV	:
			fprintf(Output->handle,"iof_tabv(%s);\n",rptr); break;
		case 	_iof_FMT	:
			fprintf(Output->handle,"iof_format();\n"); break;
		case 	_iof_DEV	:
			return( generate_rtliof_device( rptr ) );
		case 	_iof_BACK	:
			fprintf(Output->handle,"iof_backgr(%s);\n",rptr); break;
		case 	_iof_CLEAR	:
			fprintf(Output->handle,"iof_clear();\n"); break;
		case 	_iof_HOME 	:
			fprintf(Output->handle,"iof_clear();\n"); break;
		case 	_iof_BELL 	:
			fprintf(Output->handle,"iof_bell();\n"); break;
		case 	_iof_FORE	:
			fprintf(Output->handle,"iof_foregr(%s);\n",rptr); break;
		case 	_iof_TABL	:
			fprintf(Output->handle,"iof_tabl(%s);\n",rptr); break;
		case 	_iof_ASK	:
			return(generate_rtliof_ask( rptr ));
		}
	return( 0 );
}

WORD	generate_rtliof_hotkey( hptr )
HOTPTR	hptr;
{
	BPTR	tptr;
	WORD	type;
	generate_indentation( Output );
	switch ( hptr->nature ) {
		case	_hot_I 	: fprintf(Output->handle,"iof_hotkey(27);\n"); break;
		case	_hot_U 	: fprintf(Output->handle,"iof_hotkey(11);\n"); break;
		case	_hot_D 	: fprintf(Output->handle,"iof_hotkey( 5);\n"); break;
		case	_hot_L 	: fprintf(Output->handle,"iof_hotkey( 8);\n"); break;
		default		:
			if ((tptr = hptr->operand) != (BPTR) 0) {
				if ( *tptr == '#' ) {
					tptr++;
					type = ( *(tptr++) - '0' );
					}
				else	type = 1;
				switch ( type ) {
					case 0 :
					case 1 : 
						fprintf(Output->handle,"iof_hotkey(%s);\n",tptr); 
						break;
					case 2 :
					case 3 :
						fprintf(Output->handle,"iof_hotkey_string(%s);\n",tptr); 
						break;
					}
				}
		}
	return( 0 );
}


BPTR	IntegerExpression();

BPTR	BracedIntegerExpression()
{
	BPTR	rptr;
	BPTR	xptr=(BPTR) 0;
	if (((rptr = IntegerExpression()) != (BPTR) 0)
	&&  ((xptr = allocate_for_tnode(strlen(rptr)+3)) != (BPTR) 0))
		sprintf(xptr,"(%s)",rptr);
	return( xptr );
}


TCVARPTR	is_variable(WORD);
TCCONPTR	is_constant();
TCPRCPTR	is_procedure();
TCDLFPTR	is_dll_function();


BPTR		EvaluateProcedure( TCPRCPTR, WORD );
BPTR		EvaluateDllFunction( TCDLFPTR, WORD );
BPTR		EvaluateIndirect(WORD);

BPTR	TypedIndirect()
{
	return( EvaluateIndirect( MOINS_UN ) );
}


BPTR	IntegerVariable()
{
	BPTR		tptr=(BPTR) 0;
	TCVARPTR	vptr;
	TCCONPTR	cptr;
	TCPRCPTR	pptr;
	TCDLFPTR	fptr;
	if ((vptr = is_variable(1)) != (TCVARPTR) 0)
		return( variable_rvalue( vptr ) );
	else if ((cptr = is_constant()) != (TCCONPTR) 0)
		return( cptr->name );
	else if ((pptr = is_procedure()) != (TCPRCPTR) 0)
		return( EvaluateProcedure( pptr, 1 ) );
	else if ((fptr = is_dll_function()) != (TCDLFPTR) 0)
		return( EvaluateDllFunction( fptr, 1 ) );
	else	return( tptr );
}

static	BPTR	prepare_string_constant( cptr )
TCCONPTR	cptr;
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode( strlen( cptr->name ) + 32 )) != (BPTR) 0)
		sprintf( tptr,"%s,%u",cptr->name,cptr->length);
	return( tptr );
}

BPTR	BcdVariable()
{
	BPTR		tptr=(BPTR) 0;
	TCVARPTR	vptr;
	TCCONPTR	cptr;
	TCPRCPTR	pptr;
	TCDLFPTR	fptr;
	if ((vptr = is_variable(1)) != (TCVARPTR) 0)
		return( variable_cnv_svalue( vptr,2 ) );
	else if ((cptr = is_constant()) != (TCCONPTR) 0)
		return( prepare_string_constant( cptr ) );
	else if ((pptr = is_procedure()) != (TCPRCPTR) 0)
		return( EvaluateProcedure( pptr, 2 ) );
	else if ((fptr = is_dll_function()) != (TCDLFPTR) 0)
		return( EvaluateDllFunction( fptr, 2 ) );
	else	return( tptr );
}

BPTR	StringVariable()
{
	BPTR		tptr=(BPTR) 0;
	TCVARPTR	vptr;
	TCCONPTR	cptr;
	TCPRCPTR	pptr;
	TCDLFPTR	fptr;
	trace("StringVariable()\n");
	if ((vptr = is_variable(1)) != (TCVARPTR) 0)
		return( variable_cnv_svalue( vptr, 3 ) );
	else if ((cptr = is_constant()) != (TCCONPTR) 0)
		return( prepare_string_constant( cptr ) );
	else if ((pptr = is_procedure()) != (TCPRCPTR) 0)
		return( EvaluateProcedure( pptr, 3 ) );
	else if ((fptr = is_dll_function()) != (TCDLFPTR) 0)
		return( EvaluateDllFunction( fptr, 3 ) );
	else	return( tptr );
}

BPTR	NegateInteger( wptr )
BPTR	wptr;
{
	BPTR	tptr;
	trace("NegateInteger()\n");
	if ((tptr = allocate_for_tnode( strlen(wptr) + 8 )) != (BPTR) 0)
		sprintf(tptr,"-(%s)",wptr);
	return( tptr );
}

BPTR	IntegerTerm()
{
	BPTR		tptr=(BPTR) 0;
	WORD		result;
	WORD		c;
	trace("IntegerTerm()\n");
	if ( is_minus() )
		tptr = NegateInteger( IntegerTerm() );
	else if ( is_left_brace() ) {
		tptr = BracedIntegerExpression(); 
		if (!( is_right_brace()));
		}
	else if ((c = is_numeric()) != 0 ) {
		if (!( get_token() ))
			return( tptr );
		if (( c == '/' ) || ( is_integer(TokenBuffer) )) {
			result = convert_numeric_token( TokenBuffer );
			if ((tptr = allocate_for_tnode(16)) != (BPTR) 0)
				sprintf(tptr,"%u",result);
			}
		else 	return((BPTR) 0);
		}
	else if ( is_mnemonic("CALL") )
		return( EvaluateIndirect(1) );
	else if (!( get_token() ))
		return((BPTR) 0);
	else if ((tptr = IntegerVariable()) != (BPTR) 0)
		return( tptr );
	else if ((tptr = evaluate_clf()) != (BPTR) 0)
		return( tptr );
	else 	return((BPTR) 0);
	return( tptr );
}

BPTR	IntegerOperation( operation, lterm, rterm )
WORD	operation;
BPTR	lterm;
BPTR	rterm;
{
	BPTR	xptr=(BPTR) 0;

	trace("IntegerOperation()\n");
	if ((lterm != (BPTR) 0)
	&&  (rterm != (BPTR) 0)
	&&  ((xptr = allocate_for_tnode(strlen(lterm)+strlen(rterm)+8)) != (BPTR) 0))
		sprintf(xptr,"(%s %c %s)",lterm,operation,rterm);
	return( xptr );
}


BPTR	BcdOperation( operation, lterm, rterm )
WORD	operation;
BPTR	lterm;
BPTR	rterm;
{
	BPTR	xptr=(BPTR) 0;
	BPTR	xterm;
	BPTR	optr;
	trace("BcdOperation()\n");
	if ((lterm != (BPTR) 0)
	&&  (rterm != (BPTR) 0)) {
		if ((xterm = NewBcdRegister()) == (BPTR) 0)
			return( xterm );
		if ((xptr = allocate_for_tnode(strlen(lterm)+strlen(rterm)+strlen(xterm)+32)) != (BPTR) 0) {
			switch ( operation ) {
				case	'+'	: optr = "add"; break;
				case	'-'	: optr = "sub"; break;
				case	'*'	: optr = "mul"; break;
				case	'/'	: optr = "div"; break;
				case	0x0025	:
				case	'!'	: optr = "mod"; break;
				default		: (void) syntax_error(3033);
						  return((BPTR) 0);
				}

			sprintf(xptr,"bcd_%s(%s,%s,%s)",optr,lterm,rterm,xterm);
			generate_indentation( Output );
			fprintf(Output->handle,"%s;\n",xptr);
			return( xterm );
			}
		}
	return( xptr );
}

BPTR	NegateBcd( wptr )
BPTR	wptr;
{
	BPTR	nptr;
	trace("NegateBcd()\n");
	if ( wptr == (BPTR) 0)
		return( wptr );
	if ((nptr = rtlbcd_constant( "-1" )) != (BPTR) 0)
		return( BcdOperation( '*', wptr, nptr ) );
	else	return( nptr );
}

VOID	RtlAdjustAllocator()
{
	generate_indentation(Output);
	fprintf(Output->handle,"if ((_rtl_error = adjust_allocator(AVML(%u))) != 0) { %s; }\n",RtlRegisters,_RTL_RAISE_ERROR);
}

BPTR	StringOperation( operation, lterm, rterm )
WORD	operation;
BPTR	lterm;
BPTR	rterm;
{
	BPTR	xptr=(BPTR) 0;
	BPTR	xterm;
	BPTR	optr;
	if ((lterm != (BPTR) 0)
	&&  (rterm != (BPTR) 0)) {
		if ((xterm = NewStringRegister(0)) == (BPTR) 0)
			return( xterm );
		if ((xptr = allocate_for_tnode(strlen(lterm)+strlen(rterm)+strlen(xterm)+32)) != (BPTR) 0) {
			switch ( operation ) {
				case	'+'	: optr = "add"; break;
				case	0x0025	:
				case	'!'	: optr = "cat"; break;
				default		: (void) syntax_error(3034);
						  return((BPTR) 0);
				}

			sprintf(xptr,"str_%s(%s,%s,%s)",optr,lterm,rterm,xterm);
			generate_indentation(Output);
			fprintf(Output->handle,"AVML(%u) = %s;\n",RtlRegisters,xptr);
			RtlAdjustAllocator();
			return( xterm );
			}
		}
	return( xptr );
}

BPTR	VariableArithmetic( operation, vptr, rterm )
WORD		operation;
TCVARPTR	vptr;
BPTR		rterm;
{
	switch ((vptr->type->type & 3)) {
		case	0 :
		case	1 :
			return( IntegerOperation( operation, variable_rvalue( vptr ), rterm ) );
		case	2 :
			return( BcdOperation( operation, variable_svalue( vptr ), rterm ) );
		case	3 :
			return( StringOperation( operation, variable_svalue( vptr ), rterm ) );
		default	  :
			return( "<error>" );
		}
}


BPTR		IntegerExpression()
{
	WORD	operation;
	BPTR	lptr;
	BPTR	rptr;

	trace("IntegerExpression()\n");

	if ((lptr = IntegerTerm()) == (BPTR) 0)
		return( lptr );

	while ( 1 ) {

		switch ((operation = is_operator())) {
			case    ':' :
			case    ',' :
			case	')' :
			case	0   :
				return( lptr );
			}

		if ((rptr = IntegerTerm()) == (BPTR) 0)
			return(rptr);

		else if ((lptr = IntegerOperation(operation,lptr,rptr)) == (BPTR) 0) {
			(void) allocation_failure();
			return(lptr);
			}

		}
	return( lptr );
}

BPTR	TypePrefixed( rptr, type )
BPTR	rptr;
WORD	type;
{
	BPTR	tptr=(BPTR) 0;
	if ((rptr != (BPTR) 0)
	&& ((tptr = allocate_for_tnode( strlen(rptr)+ 16 )) != (BPTR) 0))
		sprintf(tptr,"#%u%s",(type & 3),rptr);
	return( tptr );
}

BPTR	EvaluateExpression();

BPTR	TypedVariable()
{
	BPTR		tptr=(BPTR) 0;
	TCVARPTR	vptr;
	TCCONPTR	cptr;
	RESULTPTR	rptr;
	RESULTPTR	primary_term();
	if ((rptr = primary_term()) == (RESULTPTR) 0)
		return( (BPTR) 0 );
	else 	{
		switch ((rptr->nature & _RESULT_BASIC)) {
			case _RESULT_INT   : 	
				if ((tptr = allocate_for_tnode( 16 )) != (BPTR) 0)
					sprintf(tptr,"%d",rptr->value);
				break;
 			case _RESULT_EXPR  : 
				if ((tptr = allocate_for_tnode( 32 )) != (BPTR) 0)
					sprintf(tptr,"** Register **");
				break;
			case _RESULT_CONST : 	
				cptr = rptr->contents;
				switch (( cptr->type->type & _TYPE_BASIC)) {
					case 0 :
					case 1 :
					case 5 :
						return(TypePrefixed( cptr->name,(cptr->type->type & _TYPE_BASIC)) );
					case 2 :
					case 3 :
						return(TypePrefixed( prepare_string_constant( cptr ), (cptr->type->type & _TYPE_BASIC)) );
					}
				break;

			case _RESULT_VARB  : 	
				vptr = rptr->contents;
				switch (( vptr->type->type & 3 ) ) {
					case 0 :
					case 1 :
						return(TypePrefixed( variable_rvalue( vptr ), vptr->type->type) );
					case 2 :
					case 3 :
						return(TypePrefixed( variable_svalue( vptr ), vptr->type->type) );
					}
				break;
			}
		}
	return( tptr );

}

BPTR	TypedClf();

BPTR	TypedProcedure()
{
	TCPRCPTR	pptr;
	if ((pptr = is_procedure()) != (TCPRCPTR) 0) 
	 	return( EvaluateProcedure( pptr, MOINS_UN ) );
	else	return((BPTR) 0);
}

BPTR	AmbiguousTerm()
{
	BPTR		tptr=(BPTR) 0;
	WORD		result;
	WORD		c;
	WORD		l;
	WORD		t=2;
	trace("AmbiguousTerm()\n");
	if ( is_minus() ) {
		tptr = AmbiguousTerm();
		if ( *tptr == '#' ) {
			tptr++;
			t = ( *(tptr++) - '0' );
			}
		else	t = 2;
		if ( t == 2 )
			tptr = TypePrefixed( NegateBcd( tptr ), t );
		else	tptr = TypePrefixed( NegateInteger( tptr ), t );
		}
	else if ( is_left_brace() ) {
		tptr = EvaluateExpression(); 
		if (!( is_right_brace()));
		}
	else if ((c = is_numeric()) != 0 ) {
		if (!( get_token() ))
			return( tptr );
		if (( c == '/' ) || ( is_integer(TokenBuffer) )) {
			result = convert_numeric_token( TokenBuffer );
			if ((tptr = allocate_for_tnode(16)) != (BPTR) 0)
			sprintf(tptr,"#1%u",result);
			}
		else	return( TypePrefixed( rtlbcd_constant( TokenBuffer ),2) );
		}
	else if ( is_mnemonic("CALL") )
		return( TypedIndirect() );
	else if (!( get_token() ))
		(void) syntax_error(3035);
	else if ( TokenBuffer[0] == '"' ) {
		if ((tptr = allocate_for_tnode((l = strlen(TokenBuffer))+16)) != (BPTR) 0)
			sprintf(tptr,"#3%s,%u",TokenBuffer,(l - 2));
		}
	else if ((tptr = TypedProcedure()) != (BPTR) 0)
		return( tptr );
	else if ((tptr = TypedVariable()) != (BPTR) 0)
		return( tptr );
	else if ((tptr = TypedClf()) != (BPTR) 0)
		return( tptr );
	else 	return((BPTR) 0);
	return( tptr );
}

VOID	define_rtlbcd_constant( vptr )
BPTR	vptr;
{

	WORD	l;
	WORD	c;
	WORD	d;
	l = strlen((vptr + 7));
	if ( l & 1 ) {
		strcat( vptr, "F" );
		l++;
		}
	l /= 2;
	fprintf(Header->handle,"#ifndef __%s\n",vptr);
	fprintf(Header->handle,"#define __%s\n",vptr);
	fprintf(Header->handle,"static BYTE %s[%u] = {\n",vptr,l);
	sprintf(vptr,"%s,%u",vptr,l);
	vptr += 7;
	while ( l != 0 ) {
		c = *(vptr++); d = *(vptr++); l--;
		if ( l ) 
			fprintf(Header->handle,"\t0x00%c%c,\n",c,d);
		else	fprintf(Header->handle,"\t0x00%c%c \n",c,d);
		}
	fprintf(Header->handle,"\t};\n");
	fprintf(Header->handle,"#endif  /* __%s */\n",vptr);
	return;
}

BPTR	rtlstring_constant( sptr )
BPTR	sptr;
{
	BPTR	tptr;
	WORD	l;
	if ((tptr = allocate_for_tnode( (l = strlen(sptr)) + 16 )) != (BPTR) 0)
		sprintf(tptr, "%c%s%c,%u",0x0022,sptr,0x0022,l);
	return( tptr );
}

BPTR	rtlbcd_constant( sptr )
BPTR	sptr;
{
	BPTR	tptr;
	BPTR	xptr;
	WORD	c;
	if ((xptr = allocate_for_tnode( (strlen(sptr) * 2) + 16 )) != (BPTR) 0) {
		tptr = xptr;
		strcpy(xptr,(BPTR) "RtlBcd$");
		xptr+= 7;
		if ( *sptr != '-' )
			*(xptr++) = 'C';
		else	{
			*(xptr++) = 'B';
			sptr++;
			}
		while (( *sptr ) && ( *sptr == '0' ))
			sptr++;
		while ( *sptr ) {
			c = *(sptr++);
			if ( c == '.' )
				*(xptr++) = 'A';
			else	*(xptr++) = c;
			}
		*(xptr++) = 'F';
		*(xptr++) = 0;
		define_rtlbcd_constant( tptr );
		}
	else	tptr = (BPTR) "<allocation_failure>,0";
	return( tptr );
}

BPTR	BcdTerm()
{
	WORD	c;
	BPTR	tptr=(BPTR) 0;
	if ( is_minus() )
		tptr = NegateBcd(BcdTerm());
	else if ( is_left_brace() ) {
		tptr = BcdExpression(); 
		if (!( is_right_brace()));
		}
	else if ((c = is_numeric()) != 0 ) {
		if (!( get_token() ))
			return("<syntax_error>,0");
		else	return( rtlbcd_constant( TokenBuffer ) );
		}
	else if ( is_mnemonic("CALL") )
		return( EvaluateIndirect(2) );
	else if (!( get_token() ))
		(void) syntax_error(3036);
	else if ((tptr = BcdVariable()) != (BPTR) 0)
		return( tptr );
	else if ((tptr = evaluate_clf()) != (BPTR) 0)
		return( tptr );
	else	(void) not_yet_available();
	return( tptr );
}

BPTR	StringTerm()
{
	BPTR	tptr=(BPTR) 0;
	WORD	l;
	trace("StringTerm(Entry)\n");
	if ( is_left_brace() ) {
		tptr = StringExpression(); 
		if (!( is_right_brace()));
		return( tptr );
		}
	if ( is_mnemonic("CALL") )
		return( EvaluateIndirect(3) );
	else if (!( get_token() ))
		(void) syntax_error(3037);
	else if ( TokenBuffer[0] == '"' ) {
		if ((tptr = allocate_for_tnode((l = strlen(TokenBuffer))+16)) != (BPTR) 0)
			sprintf(tptr,"%s,%u",TokenBuffer,(l - 2));
		}
	else if ((tptr = StringVariable()) != (BPTR) 0)
		return( tptr );
	else if ((tptr = evaluate_clf()) != (BPTR) 0)
		return( tptr );
	else	{
		sysprintf("\nString Term Failure %s \n",TokenBuffer);
		(void) not_yet_available();
		}
	return( tptr );
}


BPTR		BcdExpression()
{
	WORD	operation;
	BPTR	lptr;
	BPTR	rptr;
	trace("BcdExpression()\n");

	if ((lptr = BcdTerm()) == (BPTR) 0)
		return( lptr );

	while ( 1 ) {

		switch ((operation = is_operator())) {
			case    ':' :
			case    ',' :
			case	')' :
			case	0   :
				return( lptr );
			}

		if ((rptr = BcdTerm()) == (BPTR) 0) {
			(void) syntax_error(3038);
			return(rptr);
			}

		else if ((lptr = BcdOperation(operation,lptr,rptr)) == (BPTR) 0) {
			(void) allocation_failure();
			return(lptr);
			}

		}
	return( lptr );
}

BPTR		StringExpression()
{
	WORD	operation;
	BPTR	lptr;
	BPTR	rptr;
	trace("StringExpression()\n");

	if ((lptr = StringTerm()) == (BPTR) 0)
		return( lptr );

	while ( 1 ) {

		switch ((operation = is_operator())) {
			case    ':' :
			case    ',' :
			case	')' :
			case	0   :
				return( lptr );
			}

		if ((rptr = StringTerm()) == (BPTR) 0) {
			(void) syntax_error(3039);
			return(rptr);
			}

		else if ((lptr = StringOperation(operation,lptr,rptr)) == (BPTR) 0) {
			(void) allocation_failure();
			return(lptr);
			}

		}
	return( lptr );
}

static WORD	affect_virtual_int8( handle, vptr, rptr, mode )
WORD		handle;
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	zptr;
	if ((zptr = NewStringRegister(vptr->type->size)) == (BPTR) 0)
		(void) allocation_failure();
	generate_indentation( Output );
	fprintf(Output->handle,"*( AVMP(%u) ) = %s;\n",RtlRegisters,rptr);
	return( rewrite_virtual_variable( handle, vptr, zptr ) );
}

static WORD	affect_virtual_int16( handle, vptr, rptr, mode )
WORD		handle;
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	zptr;
	if ((zptr = NewStringRegister(vptr->type->size)) == (BPTR) 0)
		(void) allocation_failure();
	generate_indentation( Output );
	fprintf(Output->handle,"putabalword( AVMP(%u), %s );\n",RtlRegisters,rptr);
	return( rewrite_virtual_variable( handle, vptr, zptr ) );
}

static WORD	affect_virtual_bcd( handle, vptr, rptr, mode )
WORD		handle;
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	zptr;
	if ((zptr = NewStringRegister(vptr->type->size)) == (BPTR) 0)
		(void) allocation_failure();
	generate_indentation( Output );
	fprintf(Output->handle,"bcd_copy( %s, AVMP(%u), AVML(%u) );\n",rptr,RtlRegisters,RtlRegisters);
	return( rewrite_virtual_variable( handle, vptr, zptr ) );
}

static WORD	affect_virtual_string( handle, vptr, rptr, mode )
WORD		handle;
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	zptr;
	if ((zptr = NewStringRegister(vptr->type->size)) == (BPTR) 0)
		(void) allocation_failure();
	generate_indentation( Output );
	fprintf(Output->handle,"string_copy( %s, AVMP(%u), AVML(%u) );\n",rptr,RtlRegisters,RtlRegisters);
	return( rewrite_virtual_variable( handle, vptr, zptr ) );
}

WORD	generate_int8_affectation( vptr, rptr, mode )
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	nptr;
	BPTR	tptr;
	WORD	handle;
	trace("generate_int8_affect()\n");
	if ((handle = is_virtual_variable( vptr )) != 0 )
		return( affect_virtual_int8( handle,vptr, rptr, mode ) );
	if (((nptr = generate_variable_name( vptr )) == (BPTR) 0)
	||  ((tptr = allocate_for_tnode(strlen(nptr)+strlen(rptr)+32)) == (BPTR) 0))
		return( allocation_failure() );
	sprintf(tptr,"*((BPTR) %s) = %s",nptr,rptr);
	return( generate_rtl_affectation( tptr, mode,VRAI ));
}

WORD	generate_int16_affectation( vptr, rptr, mode )
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	nptr;
	BPTR	tptr;
	WORD	handle;
	trace("generate_int16_affect()\n");
	if ((handle = is_virtual_variable( vptr )) != 0 )
		return( affect_virtual_int16( handle, vptr, rptr, mode ) );
	if ( rptr == (BPTR) 0 )
		return( not_yet_available() );
	if (((nptr = generate_variable_name( vptr )) == (BPTR) 0)
	||  ((tptr = allocate_for_tnode(strlen(nptr)+strlen(rptr)+32)) == (BPTR) 0))
		return( allocation_failure() );
	sprintf(tptr,"putabalword(%s,%s)",nptr,rptr);
	return( generate_rtl_affectation( tptr, mode,VRAI ));
}

WORD	generate_optimised_sti( vptr, value )
TCVARPTR	vptr;
WORD		value;
{
	BYTE	buffer[16];
	sprintf(buffer,"%d",value);
	return( generate_int16_affectation( vptr, buffer, VRAI ) );
}

WORD	generate_bcd_affectation( vptr, rptr, mode )
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	nptr;
	BPTR	tptr;
	WORD	handle;
	trace("generate_bcd_affect()\n");
	if ((handle = is_virtual_variable( vptr )) != 0 )
		return( affect_virtual_bcd( handle, vptr, rptr, mode ) );
	if (((nptr = generate_variable_name( vptr )) == (BPTR) 0)
	||  ((tptr = allocate_for_tnode(strlen(nptr)+strlen(rptr)+64)) == (BPTR) 0))
		return( allocation_failure() );
	sprintf(tptr,"bcd_copy(%s,%s,%u)",rptr,nptr,vptr->type->size);
	return( generate_rtl_affectation( tptr, mode,VRAI ));
}

WORD	generate_string_affectation( vptr, rptr, mode )
TCVARPTR	vptr;
BPTR		rptr;
WORD		mode;
{
	BPTR	nptr;
	BPTR	tptr;
	WORD	handle;
	trace("generate_string_affect()\n");
	if ((handle = is_virtual_variable( vptr )) != 0 )
		return( affect_virtual_string( handle, vptr, rptr, mode ) );
	if (((nptr = generate_variable_name( vptr )) == (BPTR) 0)
	||  ((tptr = allocate_for_tnode(strlen(nptr)+strlen(rptr)+64)) == (BPTR) 0))
		return( allocation_failure() );
	sprintf(tptr,"string_copy(%s,%s,%u)",rptr,nptr,vptr->type->size);
	return( generate_rtl_affectation( tptr, mode,VRAI ));
}
WORD	variable_to_variable( sptr, rptr )
TCVARPTR	sptr;
TCVARPTR	rptr;
{
	BPTR	iptr;
	WORD	status;
	trace("variable_to_variable()\n");
	if ((rptr->type->type & 3) > 1 ) {
		if ((iptr = variable_svalue( sptr )) == (BPTR) 0)
			return( allocation_failure() );
		}
	else if ((iptr = variable_rvalue( sptr )) == (BPTR) 0)
		return( allocation_failure() );

	switch ((rptr->type->type & 3)) {
		case 0 : if ((status = generate_int8_affectation( rptr, iptr, 1)) != 0)
				return( status );
			 else	break;
			
		case 1 : if ((status = generate_int16_affectation( rptr, iptr, 1)) != 0)
				return( status );
			 else	break;

		case 2 : if ((status = generate_bcd_affectation( rptr, iptr, 1)) != 0)
				return( status );
			 else	break;

		case 3 : if ((status = generate_string_affectation( rptr, iptr, 1)) != 0)
				return( status );
			 else	break;

		}
	return(0);
}


BPTR	ComparisonOperator( opcode )
WORD	opcode;
{
	switch ( opcode ) {
		case	_CMP_EQ : return( "==" );
		case	_CMP_NE	: return( "!=" );
		case	_CMP_GE	: return( ">=" );
		case	_CMP_LE	: return( "<=" );
		case	_CMP_GR	: return( ">" );
		case	_CMP_LS	: return( "<" );
		case	_CMP_IN	: return( "==" );
		case	_CMP_NI	: return( "!=" );
		default		: return( "\0" );
		}
}

BPTR	LogicalOperator( opcode )
WORD	opcode;
{
	switch ( opcode ) {
		case	_LOGICAL_AND	: return( "&&" );
		case	_LOGICAL_OR 	: return( "||" );
		case	_LOGICAL_OX 	: return( "^^" );
		default			: return( "\0" );
		}
}

BPTR	FunctionCompare( opcode, mode )
WORD	opcode;
WORD	mode;
{
	switch ( opcode ) {
		case	_CMP_EQ : return( "eq" );
		case	_CMP_NE : return( "ne" );
		case	_CMP_GR : return( "gr" );
		case	_CMP_LS : return( "ls" );
		case	_CMP_GE : return( "ge" );
		case	_CMP_LE : return( "le" );
		case	_CMP_IN : if ( mode == 3 )
					return( "in" );
				  else  return( "eq" );
		case	_CMP_NI : if ( mode == 3 )
					return( "ni" );
				  else  return( "ne" );
		default		: return( "<illegal>" );
		}
}

BPTR	BcdCompare( opcode, lptr, rptr )
WORD	opcode;
BPTR	lptr;
BPTR	rptr;
{
	BPTR	tptr=(BPTR) 0;
	if ((lptr != (BPTR) 0)
	&&  (rptr != (BPTR) 0)) {
		if ((tptr = allocate_for_tnode( strlen(lptr) + strlen(rptr) + 64 )) != (BPTR) 0 )
			sprintf(tptr,"bcd_%s(%s,%s)",FunctionCompare(opcode,2) , lptr, rptr);		
		}
	return( tptr );
}

BPTR	StringCompare( opcode, lptr, rptr )
WORD	opcode;
BPTR	lptr;
BPTR	rptr;
{
	BPTR	tptr=(BPTR) 0;
	if ((lptr != (BPTR) 0)
	&&  (rptr != (BPTR) 0)) {
		if ((tptr = allocate_for_tnode( strlen(lptr) + strlen(rptr) + 64 )) != (BPTR) 0 )
			sprintf(tptr,"str_%s(%s,%s)",FunctionCompare(opcode,3) , lptr, rptr);		
		}
	return( tptr );
}

BPTR	EvaluateComparison(opcode,xptr,lptr,rptr,logic,mode)
WORD	opcode;
BPTR	xptr;
BPTR	lptr;
BPTR	rptr;
WORD	logic;
WORD	mode;
{
	BPTR	wptr;
	BPTR	tptr=(BPTR) 0;
	WORD	xl;
	WORD	dtype=1;
	if (( xptr == (BPTR) 0)
	||  ( lptr == (BPTR) 0)
	||  ( rptr == (BPTR) 0))
		return((BPTR) 0);

	while ( *lptr == '#' ) {
		lptr++;
		dtype = ( *(lptr++) - '0' );
		}
	while ( *rptr == '#' )
		rptr += 2;

	switch ( dtype ) {
		case	0 :
			if (( tptr = allocate_for_tnode( strlen(xptr)+strlen(lptr)+strlen(rptr)+64 )) != (BPTR) 0)
				sprintf(tptr,"%s (((SBYTE) %s) %s ((SBYTE) %s)) %s",xptr,lptr,ComparisonOperator(opcode),rptr,LogicalOperator(logic));
			break;
		case	1 :
			if (( tptr = allocate_for_tnode( strlen(xptr)+strlen(lptr)+strlen(rptr)+64 )) != (BPTR) 0)
				sprintf(tptr,"%s (((SWORD) %s) %s ((SWORD) %s)) %s",xptr,lptr,ComparisonOperator(opcode),rptr,LogicalOperator(logic));
			break;
		case	2 :
			if (((wptr = BcdCompare( opcode, lptr, rptr )) != (BPTR) 0)
			&&  (( tptr = allocate_for_tnode( strlen(xptr)+strlen(wptr)+32 )) != (BPTR) 0))
				sprintf(tptr,"%s (%s != 0 ) %s",xptr,wptr,LogicalOperator(logic));
	
			break;
		case	3 :
			if (((wptr = StringCompare( opcode, lptr, rptr )) != (BPTR) 0)
			&&  (( tptr = allocate_for_tnode( strlen(xptr)+strlen(wptr)+32 )) != (BPTR) 0))
				sprintf(tptr,"%s (%s != 0 ) %s",xptr,wptr,LogicalOperator(logic));
			break;
	
		}
	return( tptr );
}

BPTR	EvaluateExpression()
{
	WORD	operation;
	BPTR	lptr;
	BPTR	rptr;
	WORD	type;
	trace("EvaluateExpression()\n");

	if ((lptr = AmbiguousTerm()) == (BPTR) 0)
		return( lptr );
	else	{
		trace("AmbiguousTerm is ( ");
		trace( lptr );
		trace( " )\n");
		if ( *lptr == '#' ) {
			lptr++;
			type = ( *(lptr++) - '0' );
			}
		else	type = 3;
		}

	while ( 1 ) {

		switch ((operation = is_operator())) {
			case    ':' :
			case    ',' :
			case	')' :
			case	0   :
				return(TypePrefixed( lptr, type ));
			}

		switch ( type ) {
			case 0 :
			case 1 :
				if ((rptr = IntegerTerm()) == (BPTR) 0)
					return(rptr);

				else if ((lptr = IntegerOperation(operation,lptr,rptr)) == (BPTR) 0) {
					(void) allocation_failure();
					return(lptr);
					}
				else	break;
			case 2 :
				if ((rptr = BcdTerm()) == (BPTR) 0)
					return(rptr);

				else if ((lptr = BcdOperation(operation,lptr,rptr)) == (BPTR) 0) {
					(void) allocation_failure();
					return(lptr);
					}
				else	break;
			case 3 :
				if ((rptr = StringTerm()) == (BPTR) 0)
					return(rptr);

				else if ((lptr = StringOperation(operation,lptr,rptr)) == (BPTR) 0) {
					(void) allocation_failure();
					return(lptr);
					}
				else	break;

			default	:
				return( (BPTR) 0 );
			}
		}
	return(TypePrefixed( lptr, type ));
}

WORD	generate_rtl_pause( xptr )
BPTR    xptr;
{
	WORD	type;
	trace("generate_rtl_pause()\n");
	if ( *xptr == '#' ) {
		xptr++;
		type = ( *(xptr++) - '0' );
		}
	else	type = 3;
	switch ( type ) {
		case 0 :
			fprintf(Output->handle,"iof_pause_int(%s);\n",xptr);
			break;
		case 1 :
			fprintf(Output->handle,"iof_pause_int(%s);\n",xptr);
			break;
		case 2 :
			fprintf(Output->handle,"iof_pause_bcd(%s);\n",xptr);
			break;
		case 3 :
			fprintf(Output->handle,"iof_pause_string(%s);\n",xptr);
			break;
		}
	return(0);

}

WORD	generate_ngf_operand( optr, mode )
BPTR	optr;
WORD	mode;
{
	if ( mode )
		fprintf(Output->handle,", %s",optr);
	else	fprintf(Output->handle,"%s",optr);
	return( 0 );
}

WORD	generate_clf_operand( optr, mode )
BPTR	optr;
WORD	mode;
{
	if ( mode )
		fprintf(Output->handle,", %s",optr);
	else	fprintf(Output->handle,"%s",optr);
	return( 0 );
}

WORD	generate_ngf_special( v, mode )
WORD	v;
WORD	mode;
{
	if ( mode )
		fprintf(Output->handle,", %u",v);
	else	fprintf(Output->handle,"%u",v);
	return( 0 );
}

WORD	open_rtlngf( sptr )
BPTR	sptr;
{
	generate_indentation( Output );
	fprintf(Output->handle,"_rtl_status = %s(",sptr);
	return(0);
}

WORD	close_rtlngf()
{
	fprintf(Output->handle,");\n");
	return( 0 );
}

WORD	open_void_rtlclf( sptr )
BPTR	sptr;
{
	trace("open_void_rtlclf()\n");
	generate_indentation( Output );
	if ( *sptr == '@' ) {
		sptr++;
		fprintf(Output->handle,"if ((_rtl_status = ");
		RtlCatchError=1;
		}	
	else	RtlCatchError = 0;
	fprintf(Output->handle,"%s(",sptr);
	return(0);
}

WORD	close_void_rtlclf()
{
	trace("close_void_rtlclf()\n");
	if ( RtlCatchError )
		fprintf(Output->handle,")) != 0) { %s; }\n",_RTL_RAISE_ERROR);
	else	fprintf(Output->handle,");\n");
	RtlCatchError = 0;
	return( 0 );
}

BPTR	open_rtlclf( sptr )
BPTR	sptr;
{
	BPTR	tptr;
	trace("open_rtlclf()\n");
	if ( *sptr == '@' ) {
		sptr++;
		RtlCatchError = 1;
		}
	else	RtlCatchError = 0;
	if ((tptr = allocate_for_tnode(strlen(sptr)+2)) !=(BPTR) 0)
		sprintf(tptr,"%s(",sptr);
	return(tptr);
}

BPTR	close_rtlclf(wptr)
BPTR	wptr;
{
	BPTR	tptr;
	trace("close_rtlclf()\n");
	if ((tptr = allocate_for_tnode(strlen(wptr)+2)) !=(BPTR) 0)
		sprintf(tptr,"%s)",wptr);
	return( tptr );
}

BPTR	add_rtlclf( wptr, sptr, mode )
BPTR	wptr;
BPTR	sptr;
WORD	mode;
{
	BPTR	tptr;
	trace("add_rtlclf(\n");
	trace( wptr ); trace( ",\n");
	trace( sptr ); trace( ",mode)\n" );
	if ((tptr = allocate_for_tnode(strlen(wptr)+strlen(sptr)+3)) !=(BPTR) 0) {
		if ( mode )
			sprintf(tptr,"%s,%s",wptr,sptr);
		else	sprintf(tptr,"%s%s",wptr,sptr);
		}
	trace("Done\n");
	return( tptr );
}

BPTR	add_rtlclf_format(wptr, fptr, mode )
BPTR	wptr;
BPTR	fptr;
WORD	mode;
{
	WORD	l;
	WORD	n=0;
	BPTR	tptr;
	if ((tptr = allocate_for_tnode( strlen(wptr) + 128 )) == (BPTR) 0)
		return( tptr );
	RtlFormatCount++;
	if ( mode )
		sprintf(tptr,"%s,RTL$FMT%u, %u ",wptr,RtlFormatCount,(l = *(fptr++)));
	else	sprintf(tptr,"%s RTL$FMT%u, %u ",wptr,RtlFormatCount,(l = *(fptr++)));
	fprintf(Header->handle,"static BYTE RTL$FMT%u[%u] = ",RtlFormatCount,l);
	open_accolade( Header );
	while ( 1 ) 	{
		generate_indentation( Header );
		fprintf(Header->handle,"0x%X",*(fptr++));
		l--;
		if ( l ) {
			n++;
			if ( n >= 7 ) {
				fprintf(Header->handle,",\n");
				n = 0;
				}
			else	fprintf(Header->handle,", ");
			}
		else	{
			fprintf(Header->handle,"\n");
			generate_indentation( Header );
			fprintf(Header->handle,"};\n");
			Header->indentation--;
			break;
			}
		}
	return( tptr );
}

VOID	output_rtlclf( wptr )
BPTR	wptr;
{
	trace("output_rtlclf()\n");
	generate_indentation( Output );
	if ( RtlRegisters != 0 ) {
		fprintf(Output->handle,"AVML(%u) = %s;\n",RtlRegisters,wptr);
		RtlAdjustAllocator();
		}
	else	{
		if ( RtlCatchError )
			fprintf(Output->handle,"if ((_rtl_status = %s) == 0) { rtl_raise((_rtl_status = 111)); }\n",wptr);
		else	fprintf(Output->handle,"(void) %s;\n",wptr);
		}
	RtlCatchError = 0;

	return;
}

WORD	affect_rtl_status( tptr )
BPTR	tptr;
{
	generate_indentation( Output );
	fprintf(Output->handle,"putabalword(%s,_rtl_status);\n",tptr);
	return(0);
}

WORD	test_rtl_status( lptr )
BPTR	lptr;
{
	if ( *lptr == '&' )
		lptr++;
	generate_indentation( Output );
	fprintf(Output->handle,"if (_rtl_status != 0) goto %s;\n",lptr);
	return(0);	
}

WORD	generate_rtl_raise()
{
	generate_indentation( Output );
	fprintf(Output->handle,"if (_rtl_status != 0) { %s; }\n",_RTL_RAISE_ERROR);
	return(0);	
}

BPTR	VariableExpression(lptr)
WPTR	lptr;
{
	TCVARPTR	vptr;
	if (!( get_token() ))
		return((BPTR) 0);
	else if ((vptr = is_variable(1)) == (TCVARPTR) 0)
		return( (BPTR) 0 );
	else	{
		*lptr = vptr->type->size;
		return( generate_variable_name( vptr ) );
		}
}

BPTR	AskExpression()
{
	TCVARPTR	vptr;
	BPTR		aptr;
	if (!( get_token() ))
		return((BPTR) 0);
	else if ((vptr = is_variable(1)) == (TCVARPTR) 0)
		return( (BPTR) 0 );
	else if ((aptr = variable_svalue( vptr )) != (BPTR) 0)
		return( TypePrefixed(aptr, vptr->type->type) );
	else	return( TypePrefixed(generate_variable_name( vptr ), vptr->type->type) );
}

BPTR	RtlCollectExitValue( ptype )
WORD	ptype;
{
	BPTR	tptr;
	switch (ptype)	{
		case	0 	:
		case	1 	:
			tptr = (BPTR) "AVMV(53)";
			break;
		case	2 	:
		case	3 	:
			tptr = (BPTR) "AVMP(53), AVML(53)";
			break;

		case	0x0008	:
		case	0x0009	:
		case	0x000A	:
		case	0x000B	:
			tptr = (BPTR) "getpointer((BPTR) AVMP(53)), AVML(53)";
			break;

		case	MOINS_UN :
			if ((tptr = NewStringRegister(0)) == (BPTR) 0)
				return( tptr );
			generate_indentation( Output );
			fprintf(Output->handle,"AVMP(%u) = AVMP(53);\n",RtlRegisters);
			generate_indentation( Output );
			fprintf(Output->handle,"AVML(%u) = AVML(53);\n",RtlRegisters);
			generate_indentation( Output );
			fprintf(Output->handle,"AVMT(%u) = AVMT(53);\n",RtlRegisters);
			generate_indentation( Output );
			fprintf(Output->handle,"AVMV(%u) = AVMV(53);\n",RtlRegisters);

		}
	return( tptr );
}

BPTR	EvaluateProcedure( pptr, type )
TCPRCPTR	pptr;
WORD		type;
{
	BPTR	tptr=(BPTR) 0;
	WORD	ptype;
	WORD	status;
	if ((status = activate_rtl_procedure( pptr, tptr )) != 0)
		return((BPTR) 0);

	ptype = (((pptr->options >> 8) - 1) & 0x000B);

	if ((tptr = RtlCollectExitValue( ptype )) == (BPTR) 0)
		return( (BPTR) 0 );

	if ( type == MOINS_UN ) 
		return( TypePrefixed( tptr, ptype ) );
	else if ( type != ptype )
		return( RtlTypeConvertor(tptr,ptype,type) );
	else	return( tptr );
}

BPTR	evaluate_dll_function( TCDLFPTR );

BPTR	EvaluateDllFunction( fptr, type )
TCDLFPTR	fptr;
WORD		type;
{
	BPTR	tptr=(BPTR) 0;
	WORD	ptype=1;
	WORD	status;
	if ((tptr = evaluate_dll_function( fptr )) == (BPTR) 0)
		return((BPTR) 0);

	ptype = fptr->type;

	if ( type == MOINS_UN ) 
		return( TypePrefixed( tptr, ptype ) );
	else if ( type != ptype )
		return( RtlTypeConvertor(tptr,ptype,type) );
	else	return( tptr );
}


BPTR	RtlProcedurePointer()
{
	BPTR		xptr;
	TCVARPTR	vptr;
	BPTR		iptr;

	if ((!( get_token() ))
	||  ((vptr = is_variable(1)) == (TCVARPTR) 0)
	||  ((xptr = generate_variable_name( vptr )) == (BPTR) 0)
	||  ((iptr = allocate_for_tnode( strlen( xptr ) + 32 )) == (BPTR) 0))
		return( (BPTR) 0 );
	else	{
		sprintf(iptr,"(getprocptr((%s)))",xptr);
		return( iptr );
		}
}


BPTR	EvaluateIndirect( type )
WORD	type;
{
	WORD		status;
	BPTR		tptr;
	BPTR		iptr;

	if (!( is_left_brace() ))
		return( (BPTR) 0 );
	if ((iptr = RtlProcedurePointer()) == (BPTR) 0)
		return( iptr );
	if (!( is_right_brace() ))
		return( (BPTR) 0  );

	if ((status = activate_rtl_procedure( (TCPRCPTR) 0, iptr )) != 0)
		return((BPTR) 0);

	if ((tptr = RtlCollectExitValue( MOINS_UN )) == (BPTR) 0)
		return( (BPTR) 0 );
	else	return( tptr );
}

BPTR	TypedExpression( type )
WORD	type;
{
	switch ( type ) {
		case	0 :
		case	1 : return( IntegerExpression() );
		case	2 : return( BcdExpression()	);
		case	3 : return( StringExpression()	);
		default	  : return( (BPTR) 0);
		}
}


WORD		generate_event_call( pptr, vptr, mode )
TCPRCPTR	pptr;
TCVARPTR	vptr;
WORD		mode;	/* 0 Normal, 1 OCX etc Extension */
{
#ifdef	_BEFORE_19031998
	WORD	status;
	if ( pptr != (TCPRCPTR) 0 ) {
		if ((status = generate_extern_event( 2,mode )) != 0)
			return( status );
		else	return( tcode_procedure( pptr ) );
		}
	else if ((status = generate_extern_event( 3, mode )) != 0)
		return( status );
	else	return( tcode_variable( vptr ) );
#else
	return( 26056 );
#endif
}

WORD	generate_call_segment( vptr )
TCVARPTR	vptr;
{
#ifdef	_BEFORE_19031998
	WORD	status;
	if ((status = generate_dimensions( 0, vptr )) !=0 )
		return( status );
	tcode_instruction( _tc_LDE );
	tcputbyte( 0x0040 );
	tcode_variable( vptr );
	return( 0 );
#else
	return( 27056 );
#endif
}

/* #include "trrtldum.c" */

#endif	/* _TRGENRTL_C */
	/* ----------- */

