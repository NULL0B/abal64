#ifndef _TRATOC_C
#define _TRATOC_C

#include <stdio.h>              /* Standard IO handling routines        */
#include <errno.h>              /* Error return definitions             */
#include <fcntl.h>
#include "stdtypes.h"
#include "translat.h"
#include "troption.h"
#include "trtcode.h"
#include "trevent.h"
#include "trexpres.h"
#include "trproc.h"
#include "triof.h"
#include "troutput.h"
#include "trsyntax.h"
#include "trclf.h"
#include "trmember.h"
#include "trnurone.h"
#include "trdebug.h"
#include "trtnode.c"
#include "trrtltoc.h"
#include "tratoc.h"

PRIVATE WORD    AtocClassMembers=0;
PRIVATE WORD    AtocBaseMembers=0;


PRIVATE WORD    LdsCounter=0;

PRIVATE WORD    GetTcodeByte( a )
	WORD    a;
{
	return(  get_sector_byte( a ) );
}

PRIVATE WORD    GetTcodeWord( a )
	WORD    a;
{
	WORD    v;
	v = GetTcodeByte(a+1);
	v <<= 8;
	v += GetTcodeByte(a);
	return( v );
}

#include "trrtltoc.c"
#include "travm.c"

PRIVATE WORD    atocDindex=0;
PRIVATE WORD    atocVindex=0;
PRIVATE WORD    atocState=0;

PUBLIC  VOID    parameter_start( i )
	WORD    i;
{
	atocVindex = atocDindex = i;
	while (GetTcodeByte(atocVindex++) & 0x0001);
	atocState = 1;
}

PUBLIC  WORD    parameter_flush( i )
	WORD    i;
{
	WORD    tcode;
	parameter_start(i);
	do      {
		tcode = GetTcodeByte(atocDindex++);
		switch ( tcode & 0x0060 ) {
			case    0x0000 :
			case    0x0020 :
			case    0x0040 : atocVindex += 2; break;
			case    0x0060 : atocVindex++;
			}
		if (!( tcode & 0x0010 ))
			break;
		switch ( tcode & 0x0006 ) {
			case    0 :
			case    2 :
			case    4 : atocVindex += 2; break;
			case    6 : atocVindex++;
			}
		}
	while ( tcode & 0x0001 );
	atocState = 0;
	return( atocVindex );
}

PUBLIC  BPTR    atoc_parameter()
{
	BPTR    tptr=(BPTR) 0;
	WORD    tcode;
	if ( atocState ) {
		tcode = GetTcodeByte(atocDindex);
		if ( atocState == 1 ) {
			switch ( tcode & 0x0060 ) {
				case    0x0000 : tptr = avm_integer( GetTcodeWord(atocVindex) ); atocVindex += 2; break;
				case    0x0020 : tptr = avm_constant( GetTcodeWord(atocVindex) ); atocVindex += 2; break;
				case    0x0040 : tptr = avm_variable( GetTcodeWord(atocVindex) ); atocVindex += 2; break;
				case    0x0060 : tptr = avm_register( GetTcodeByte(atocVindex++) ); break;
				}
			if ( tcode & 0x0010 )
				atocState = 2;
			else    atocState = 0;
			}
		else    {
			switch ( tcode & 0x0006 ) {
				case    0x0000 : tptr = avm_integer( GetTcodeWord(atocVindex) ); atocVindex += 2; break;
				case    0x0002 : tptr = avm_constant( GetTcodeWord(atocVindex) ); atocVindex += 2; break;
				case    0x0004 : tptr = avm_variable( GetTcodeWord(atocVindex) ); atocVindex += 2; break;
				case    0x0006 : tptr = avm_register( GetTcodeByte(atocVindex++) ); break;
				}
			if ( tcode & 0x0001 ) {
				atocState = 1;
				atocDindex++;
				}
			else    atocState = 0;
			}
		}
	return( tptr );
}

PRIVATE WORD    atoc_statement( fptr, tcode, offset )
	BPTR    fptr;
	WORD    tcode;
	WORD    offset;
{
	BPTR    sptr;
	switch ((tcode & 0x0060)) {
		case    0x0000 :
			if ((sptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else    return(0);
		case    0x0020 :
			if ((sptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else    return(0);

		case    0x0040 :
			if ((sptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else    return(0);
		case    0x0060 :
			if ((sptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0)
				break;
			else    return(0);
		default         :
			return( 0 );
		}
	rtl_statement( fptr, avm_evaluate( sptr ));
	return( offset );
}

PRIVATE VOID    atoc_access( rights )
	WORD    rights;
{
	if ( get_pragma_output() > 1 ) {
		if ( rights & _MEMBER_PUBLIC )
			rtl_puts("public ");
		else if ( rights & _MEMBER_PRIVATE )
			rtl_puts("private ");
		}
	if ( rights & _MEMBER_COMMON )
		rtl_puts("static ");
	return;
}
PRIVATE WORD    atoc_typed_statement( fptr, tcode, offset )
	BPTR    fptr;
	WORD    tcode;
	WORD    offset;
{
	TCTYPPTR        tptr;
	BPTR    sptr;
	WORD    type=MOINS_UN;
	switch ((tcode & 0x0060)) {
		case    0x0000 :
			if ((sptr = avm_integer( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				type = _TYPE_INT16;
				break;
				}
			else    return(0);
		case    0x0020 :
			if ((sptr = avm_constant( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				type = _TYPE_STRING;
				break;
				}
			else    return(0);

		case    0x0040 :
			if ((sptr = avm_variable( GetTcodeWord(offset) )) != (BPTR) 0) {
				offset += 2;
				break;
				}
			else    return(0);
		case    0x0060 :
			if ((sptr = avm_register( GetTcodeByte(offset++) )) != (BPTR) 0)
				break;
			else    return(0);
		default         :
			return( 0 );
		}

	if (( sptr != (BPTR) 0) 
	&&  ((tptr = avm_resolve_type( sptr )) != (TCTYPPTR) 0)) {
		if ((type = tptr->type & _TYPE_BASIC) == _TYPE_STRING )
			rtl_typed_statement( fptr, type, avm_address( sptr ));
		else    rtl_typed_statement( fptr, type, avm_evaluate( sptr ));
		}

	return( offset );
}


PUBLIC  WORD    atoc_newline(offset)
	WORD    offset;
{
	WORD    i;

	if ( offset != MOINS_UN ) {
		switch ( get_pragma_output() ) {
			case	0 :	rtl_void_statement( _AVM_NEWLINE );
			}
		}

	if ( AtocRegisters > 0 ) {


		while ( AtocRegisters > 0 ) {
			AtocRegister[AtocRegisters]  = (BPTR) 0;
			AtocPrimary[AtocRegisters]   = (BPTR) 0;
			AtocSecondary[AtocRegisters] = (BPTR) 0;
			AtocRegisters--;
			}

		/* Clear the ZERO / Default Index Register */
		/* --------------------------------------- */
		AtocRegister [0] = (BPTR) 0;
		AtocPrimary  [0] = (BPTR) 0;
		AtocSecondary[0] = (BPTR) 0;

		release_used_tnodes();
		AtocRegisters = 0;

		}

	return(offset);
}

PUBLIC  BPTR    atoc_integer( tcode , offset )
	WORD    tcode;
	WORD    offset;
{
	return((BPTR) 0);
}

PUBLIC  TCVARPTR        atoc_class_strings( TCVARPTR, TCSTRUCTPTR );

#include "tresctoc.c"
#include "trngftoc.c"
#include "trclftoc.c"
#include "trldftoc.c"
#include "trioftoc.c"

PRIVATE VOID            atoc_parameters( TCVARPTR, WORD, WORD );
PRIVATE TCVARPTR        atoc_variable( TCVARPTR, WORD );

PRIVATE VOID    atoc_classtype( nptr )
	BPTR    nptr;
{
	switch ( get_pragma_output() ) {
		case    0       :       /* 'C'          */
			rtl_puts("struct _");   rtl_puts( nptr );       
			break;
		case    1       :       /* C++          */
		case    2       :       /* 'Java'       */
		case    3       :       /* 'Java++'     */
			rtl_puts( nptr );
			break;
		}
	return;
}

PRIVATE VOID    atoc_type( tptr, nptr )
	TCTYPPTR        tptr;
	BPTR            nptr;
{
	TCSTRUCTPTR     cptr;
	if ( tptr->type & _TYPE_DEFINED ) {
		if ((cptr = (TCSTRUCTPTR)tptr->class) != (TCSTRUCTPTR) 0)
			atoc_classtype( cptr->name );
		else    rtl_puts("struct/class type unknown");
		switch ( tptr->type & _TYPE_SPECIAL ) {
			case    _TYPE_POINTER :
			case    _TYPE_MBPTR   :
				rtl_putptr();
			}
		rtl_space;
		rtl_puts( nptr );
		}
	else    {
		switch ( tptr->type & _TYPE_BASIC ) {
			case    _TYPE_INT8      :
				rtl_int8; break;
		
			case    _TYPE_INT16     :
				rtl_int16; break;
			case    _TYPE_NUMERIC   :
				if ( tptr->size > 8 )
					rtl_double;
				else    rtl_float;
				break;
			case    _TYPE_STRING    :
				rtl_string; break;
			}

		switch ( tptr->type & _TYPE_SPECIAL ) {
			case    _TYPE_POINTER :
			case    _TYPE_MBPTR   :
				rtl_putptr();
			}

		rtl_space;
		rtl_puts( nptr );

		switch ( tptr->type & _TYPE_BASIC ) {
			case    _TYPE_NUMERIC   :
			case    _TYPE_STRING    :
				rtl_space; 
				/* rtl_dimensions( tptr->size); */
			}
		if ( tptr->type & _TYPE_FIRST ) {
			rtl_dimensions( tptr->first);
			if ( tptr->type & _TYPE_SECOND ) {
				rtl_dimensions( tptr->second);
				}
			}

		}
	return;

}

PRIVATE VOID    atoc_init( tptr )
	TCTYPPTR        tptr;
{

	if ( tptr->type & _TYPE_DEFINED ) {

		switch ( tptr->type & _TYPE_SPECIAL ) {
			case    _TYPE_POINTER :
			case    _TYPE_MBPTR   :
				rtl_equals;
				rtl_leftbrace;
				atoc_type( tptr, "\0");
				rtl_rightbrace;
				rtl_putb('0');
			}

		}
	else    {
		if (( tptr->type & _TYPE_BASIC ) == _TYPE_STRING)
			switch ( tptr->type & _TYPE_SPECIAL ) {
				case    _TYPE_POINTER :
				case    _TYPE_MBPTR   :
					break;
				default         :
					return;
				}
		rtl_equals;
		rtl_leftbrace;
		atoc_type( tptr, "\0");
		rtl_rightbrace;
		rtl_putb('0');
		}
	return;
}

PRIVATE	VOID	atoc_method_parameters( fptr, mode )
	VPTR            fptr;
	WORD            mode;   /* 0 : AtocClassMethod, 1 : AtocVirtualPtr */
{
	TCVARPTR        pptr;
	WORD            pcount=0;
	BPTR		nptr;
	if ((pptr = resolve_method_parameters( fptr )) != (TCVARPTR) 0) {

		/* Avoid Object Pointer for Class Type Languages 	*/
		if ( get_pragma_output() > 0 ) /* C++, Java, Java++ 	*/
			pptr = pptr->next;
			
		if ( pptr != (TCVARPTR) 0) {
			rtl_leftbrace;
			do      {
				if ( pcount++ ) rtl_comma;
				if ( mode & 8 )
					nptr = pptr->name;
				else	nptr = "\0";
				atoc_type( pptr->type, nptr );
				}
			while ((pptr = pptr->next) != (TCVARPTR) 0);
			rtl_rightbrace;
			return;
			}
		}

	switch ( get_pragma_output() ) {
		case	0 :
		case	2 :
		case	3 : rtl_puts("( void )"); break;
		case	1 : rtl_leftbrace; rtl_rightbrace; break;
		}
	return;

}

PRIVATE	WORD	atoc_method_return( fptr )
	VPTR            fptr;
{
	TCTYPPTR        xptr;
	
	if ((xptr = resolve_method_type( fptr )) != (TCTYPPTR) 0) {
		atoc_type( xptr, "\0");
		return(1);
		}
	else    {
		rtl_puts("void ");
		return( 0 );
		}
}


PRIVATE VOID    atoc_methptr( fptr, nptr, mode )
	VPTR            fptr;
	BPTR            nptr;
	WORD            mode;   /* 0 : AtocClassMethod, 1 : AtocVirtualPtr */
{

	(VOID) atoc_method_return( fptr );

	/* if Output Language is Greater than 'C' ie C++,Java,Java++ */
	/* --------------------------------------------------------- */
	if ( get_pragma_output() > 0 ) { 
		rtl_space;
		rtl_puts( nptr );
		}
	else    {
		rtl_leftbrace;
		rtl_putptr();
		rtl_space;
		if ( mode & 1 )
			rtl_putb('$');
		rtl_puts( nptr );
		rtl_rightbrace;
		}
	atoc_method_parameters( fptr, mode );
	return;
}
		
PRIVATE VOID    atoc_member( tptr, nptr )
	TCTYPPTR        tptr;
	BPTR            nptr;
{
	TCSTRUCTPTR     cptr;
	if ( tptr->type & _TYPE_DEFINED ) {
		if ((cptr = (TCSTRUCTPTR)tptr->class) != (TCSTRUCTPTR) 0)
			atoc_classtype( cptr->name );
		else    rtl_puts("struct/class type unknown");
		switch ( tptr->type & _TYPE_SPECIAL ) {
			case    _TYPE_POINTER :
			case    _TYPE_MBPTR   :
				rtl_putptr();
			}
		rtl_space;
		rtl_puts( nptr );
		}
	else    {
		switch ( tptr->type & _TYPE_BASIC ) {
			case    _TYPE_INT8      :
				rtl_int8; break;
		
			case    _TYPE_INT16     :
				rtl_int16; break;
			case    _TYPE_NUMERIC   :
				if ( tptr->size > 8 )
					rtl_double;
				else    rtl_float;
				break;
			case    _TYPE_STRING    :
				if (( tptr->size == 5 )
				&&  ( tptr->class != (VPTR) 0)) {
					atoc_methptr( tptr->class, nptr,1 );
					return;
					}
				rtl_string; break;
			}

		switch ( tptr->type & _TYPE_SPECIAL ) {
			case    _TYPE_POINTER :
			case    _TYPE_MBPTR   :
				rtl_putptr();
			}

		rtl_space;
		rtl_puts( nptr );

		switch ( tptr->type & _TYPE_BASIC ) {
			case    _TYPE_NUMERIC   :
			case    _TYPE_STRING    :
				rtl_space; 
				/* rtl_dimensions( tptr->size); */
			}
		if ( tptr->type & _TYPE_FIRST ) {
			rtl_dimensions( tptr->first);
			if ( tptr->type & _TYPE_SECOND ) {
				rtl_dimensions( tptr->second);
				}
			}

		}
	return;

}

PRIVATE WORD    is_member_of_host(hptr, mptr )
	TCVARPTR        hptr;
	TCVARPTR        mptr;
{
	switch ( hptr->type->type & _TYPE_SPECIAL ) {
		case _TYPE_POINTER :
		case _TYPE_MBPTR   :
			if ( mptr->host == hptr->descriptor )
				return(1);
			else    return(0);
		default            :
			if ( mptr->master == hptr->descriptor )
				return(1);
			else    return(0);
		}
}

PUBLIC  TCVARPTR        avoid_members( pptr, vptr )
	TCVARPTR        pptr;
	TCVARPTR        vptr;
{
	while ( vptr != (TCVARPTR) 0 ) {
		if (!( is_member_of_host( pptr, vptr ) ))
			break;
		else if ( vptr->type->type & _TYPE_DEFINED )
			vptr = avoid_members( vptr, vptr->prev );
		else    vptr = vptr->prev;
		}
	return( vptr );
}

PRIVATE VOID            atoc_put_member( mptr )
	TCVARPTR        mptr;
{
	rtl_linefeed();
	rtl_indentation();
	if ( OtrOption.Special ) {
		rtl_puts("/* "); rtl_puts("V="); rtl_putx( mptr->descriptor );
		rtl_puts(", "); rtl_puts("M="); rtl_putx( mptr->master );
		rtl_puts(", "); rtl_puts("H="); rtl_putx( mptr->host );
		rtl_puts(", "); rtl_puts("T="); rtl_putx( mptr->type->type );
		rtl_puts(" */ ");
		}
	atoc_member( mptr->type, mptr->name );
	rtl_semicolon;
	return;
}

PRIVATE TCVARPTR        not_parameter( hptr, vptr )
	TCVARPTR        hptr;
	TCVARPTR        vptr;
{
	while ((vptr != (TCVARPTR) 0)
	&&     (vptr->type->type & _TYPE_PARAMETER))
		vptr = vptr->prev;
	while ((vptr != (TCVARPTR) 0)
	&&     (!( is_member_of_host( hptr, vptr ) )))
		vptr = vptr->prev;

	return( vptr );
}

PUBLIC	VOID	atoc_dependance( sptr )
	BPTR	sptr;
{
	WORD            output_status;

	output_status = rtl_get_active();
	rtl_use_header();
	switch ( get_pragma_output() ) {
		case	1 : 	rtl_dependance( sptr, ".hpp" );
		case	0 : 	rtl_dependance( sptr, ".h" );
				break;
		case	2 :
		case	3 :	rtl_linefeed();
				rtl_puts("import ");
				rtl_puts( sptr );
				rtl_linefeed();
				break;
		}
	rtl_set_active( output_status );
	return;
}

PRIVATE WORD            atoc_generate_class( vptr, cptr, nptr,level)
	TCVARPTR        vptr;
	TCSTRUCTPTR     cptr;
	BPTR            nptr;
	WORD            level;
{
	WORD            output_status;
	TCVARPTR        mptr=not_parameter(vptr,vptr->prev);
	if (!(is_member_library(cptr))) {
		output_status = rtl_get_active();
		rtl_use_header();
		rtl_linefeed();
		rtl_indentation();
		atoc_classtype( cptr->name );
		rtl_space;
		rtl_enter(1);
		set_member_library( cptr );
		while ( mptr != (TCVARPTR) 0) {
			if (!( is_member_of_host( vptr, mptr ) ))
				break;
			if ( mptr->overloads != (TCVARPTR) 0) {
				mptr = mptr->prev;
				}
			else    {
				if ( mptr->type->type & _TYPE_DEFINED ) {
					if (!( atoc_generate_class( mptr, mptr->type->class, mptr->name, Indentation ) ))
						atoc_put_member( mptr );
					mptr = avoid_members( mptr, mptr->prev );
					}
				else    {
					atoc_put_member( mptr );
					mptr = mptr->prev;
					}
				}
			}
		rtl_linefeed();
		rtl_indentation();
		rtl_leave(1);
		rtl_puts( nptr );
		rtl_semicolon;
		rtl_set_active( output_status );
		return( VRAI );
		}
	else    return( FAUX );
}


PRIVATE WORD            atoc_segment( sptr )
	TCSEGPTR        sptr;
{
	rtl_linefeed();
	avm_set_return( (TCTYPPTR) 0 );
	rtl_puts("public void segment_");
	if ( sptr->name != (BPTR) 0 )
		rtl_puts( sptr->name );
	else    rtl_putu(sptr->identity);
	return( 0 );
}

PRIVATE WORD            atoc_procedure( pptr, mode)
	TCPRCPTR        pptr;
	WORD		mode;
{
	TCSTRUCTPTR	class;
	TCMEMBERPTR	member;

	switch ( get_pragma_output() ) {
		case	1	:
 			if (((class  = (TCSTRUCTPTR)pptr->class)  != (TCSTRUCTPTR) 0)
			&&  ((member = (TCMEMBERPTR)pptr->member) != (TCMEMBERPTR) 0)) {
				if (!( mode )) {
					avm_set_return( pptr->result );
					if (pptr->result != (TCTYPPTR) 0)
						atoc_type( pptr->result,"\0" );
					else    rtl_puts("void");
					rtl_space;
					rtl_puts( class->name );
					rtl_colon; rtl_colon;
					rtl_puts( member->name );
					}
				break;
				}

		case	0	:
			rtl_puts("public ");
			avm_set_return( pptr->result );
			if (pptr->result != (TCTYPPTR) 0)
				atoc_type( pptr->result,"\0" );
			else    rtl_puts("void ");
			rtl_puts( pptr->name ); 
			break;
		}
	return( 0 );
}

PRIVATE WORD    atoc_signature(mode)
	WORD    mode;
{
	WORD            status;
	TCVDTPTR        tptr;
	TCSEGPTR        sptr;
	TCPRCPTR        pptr;
	TCMEMBERPTR	member;

	rtl_linefeed();
	if ((sptr = Context->CurrentSegment) != (TCSEGPTR) 0) {
		if ((status = atoc_segment( sptr )) != 0)
			return( status );
		if ((tptr = Context->LDT) != (TCVDTPTR) 0)
			atoc_parameters( tptr->first, mode,  0 );
		else    atoc_parameters( (TCVARPTR) 0, mode, 0 );
		}
	else if ((pptr = Context->PRC) != (TCPRCPTR) 0) {
		if ((status = atoc_procedure( pptr,mode )) != 0)
			return( status );
		if ((tptr = Context->LDT) != (TCVDTPTR) 0) {
			if ((member = (TCMEMBERPTR)pptr->member) != (TCMEMBERPTR) 0) {
				if (!( mode ))
					atoc_parameters( tptr->first, mode, (get_pragma_output() > 0 ? 1 : 0));
				}
			else 	atoc_parameters( tptr->first, mode, 0);
			}
		else    atoc_parameters( (TCVARPTR) 0, mode, 0);
		}


	return( 0);
}

PRIVATE WORD    atoc_method()
{
	WORD            status;
	TCVDTPTR        tptr;
	TCVARPTR        vptr;


	if ((status = atoc_signature(0)) != 0)
		return( status );

	rtl_start_block();

	if ((tptr = Context->LDT) != (TCVDTPTR) 0) {
		vptr = tptr->first;
		while ( vptr != (TCVARPTR) 0)
			vptr = atoc_variable( vptr, 0 );
		}
	return( 0 );
}

PUBLIC  WORD    tcode_to_c(maxbytes)
	WORD    maxbytes;
{
	WORD    i=0;
	WORD    tcode;
	WORD    status;

	if ( Context->DataOffset != MOINS_UN )
		maxbytes = Context->DataOffset;
	else    maxbytes -= 2;

	rtl_set_label( MOINS_UN );

	rtl_use_footer();

	if ((status = atoc_signature(1)) != 0)
		return( status );

	rtl_use_body();

	if ((status = atoc_method()) != 0 )
		return( status );

	while ( i < maxbytes ) {

		rtl_set_label( i );

		if ((tcode = GetTcodeByte( i++ )) & 0x0080 ) {
			if (( tcode == 0x00FF )
			||  ((status = atoc_newline(i)) == 0))
				break;
			}

		switch ((tcode & 0x007F)) {

			case _tc_ESC    :       /* 0x0000 */

				if ((i = esc_to_c(i)) != 0)
					continue;
				else    break;

			case _tc_NOP    :       /* 0x0056 */
				continue;

			case _tc_RAZ    :       /* 0x0005 */
			case _tc_NEW    :       /* 0x0016 */
				if ((status = atoc_newline(i)) != 0)
					continue;
				else    break;

			case _tc_JMI    :       /* 0x0012 */
				if ((i = avm_goto( i )) != 0)
					continue;
				else    break;

			case _tc_RET    :       /* 0x0006 */
				rtl_void_statement( _RTL_RETURN );
				continue;

			case _tc_GSB    :       /* 0x0007 */
				if ((i = avm_gosub( i )) != 0)
					continue;
				else    break;
				
			case _tc_NGF    :       /* 0x0035 */
				if ((i = ngf_to_c(i)) != 0)
					continue;
				else    break;

			case _tc_LDF    :       /* 0x0065 */
				if ((i = ldf_to_c(i)) != 0)
					continue;
				else    break;

			case _tc_CLF    :       /* 0x0015 */
				if ((i = clf_to_c(i)) != 0)
					continue;
				else    break;

			case _tc_IOF    :       /* 0x0055 */

				if ((i = iof_to_c(i)) != 0)
					continue;
				else    break;

			case _tc_VPT    :       /* 0x0047 */
			case _tc_LDI    :       /* 0x0001 */
			case _tc_LDC    :       /* 0x0021 */    
			case _tc_LDV    :       /* 0x0041 */
			case _tc_LDR    :       /* 0x0061 */
				if ((i = avm_load_register( tcode,i)) != 0)
					continue;
				else    break;

			case _tc_STI    :       /* 0x0014 */
			case _tc_STC    :       /* 0x0034 */
			case _tc_STV    :       /* 0x0054 */
			case _tc_STR    :       /* 0x0074 */
				if ((i = avm_store(tcode,i)) != 0)
					continue;
				else    break;

			case _tc_LXI    :       /* 0x0003 */
			case _tc_LXC    :       /* 0x0023 */
			case _tc_LXV    :       /* 0x0043 */
			case _tc_LXR    :       /* 0x0063 */
				if ((i = avm_load_primary(tcode, i)) != 0)
					continue;
				else    break;

			case _tc_AXI    :       /* 0x0004 */
			case _tc_AXC    :       /* 0x0024 */
			case _tc_AXV    :       /* 0x0044 */
			case _tc_AXR    :       /* 0x0064 */
				if ((i = avm_load_secondary(tcode,i)) != 0)
					continue;
				else    break;

			case _tc_CNV    :       /* 0x0037 */
				if ((i = avm_convert( i )) != 0)
					continue;
				else    break;

			/* Unary Operation on Register */
			/* --------------------------- */
			case _tc_NGR    :       /* 0x0062 */
			case _tc_NGV    :       /* 0x0072 */

			case _tc_INC    :       /* 0x0011 */
			case _tc_DEC    :       /* 0x0031 */

			case _tc_INX    :       /* 0x0051 */
			case _tc_DEX    :       /* 0x0071 */

			case _tc_ANX    :       /* 0x0002 */
			case _tc_DAX    :       /* 0x0022 */
				if ((i = avm_unary(tcode,i)) != 0)
					continue;
				else    break;


			/* Calculate Register with Register to Register */
			/* -------------------------------------------- */
			case _tc_ADI    :       /* 0x0008 */
			case _tc_SBI    :       /* 0x0009 */
			case _tc_MLI    :       /* 0x000A */
			case _tc_DVI    :       /* 0x000B */
			case _tc_MDI    :       /* 0x000C */
			case _tc_ANI    :       /* 0x000D */
			case _tc_ORI    :       /* 0x000E */
			case _tc_XRI    :       /* 0x000F */
			case _tc_ADC    :       /* 0x0028 */
			case _tc_SBC    :       /* 0x0029 */
			case _tc_MLC    :       /* 0x002A */
			case _tc_DVC    :       /* 0x002B */
			case _tc_MDC    :       /* 0x002C */
			case _tc_ANC    :       /* 0x002D */
			case _tc_ORC    :       /* 0x002E */
			case _tc_XRC    :       /* 0x002F */
			case _tc_ADV    :       /* 0x0048 */
			case _tc_SBV    :       /* 0x0049 */
			case _tc_MLV    :       /* 0x004A */
			case _tc_DVV    :       /* 0x004B */
			case _tc_MDV    :       /* 0x004C */
			case _tc_ANV    :       /* 0x004D */
			case _tc_ORV    :       /* 0x004E */
			case _tc_XRV    :       /* 0x004F */
			case _tc_ADR    :       /* 0x0068 */
			case _tc_SBR    :       /* 0x0069 */
			case _tc_MLR    :       /* 0x006A */
			case _tc_DVR    :       /* 0x006B */
			case _tc_MDR    :       /* 0x006C */
			case _tc_ANR    :       /* 0x006D */
			case _tc_ORR    :       /* 0x006E */
			case _tc_XRR    :       /* 0x006F */
				if ((i = avm_operation(tcode, i)) != 0)
					continue;
				else    break;
				
			/* Compare Register with Register : If TRUE : LABEL */
			/* ------------------------------------------------ */
			case _tc_JEQI   :       /* 0x0018 */
			case _tc_JNEI   :       /* 0x0019 */
			case _tc_JGEI   :       /* 0x001A */
			case _tc_JLEI   :       /* 0x001B */
			case _tc_JGRI   :       /* 0x001C */
			case _tc_JLSI   :       /* 0x001D */
			case _tc_JEQC   :       /* 0x0038 */
			case _tc_JNEC   :       /* 0x0039 */
			case _tc_JGEC   :       /* 0x003A */
			case _tc_JLEC   :       /* 0x003B */
			case _tc_JGRC   :       /* 0x003C */
			case _tc_JLSC   :       /* 0x003D */
			case _tc_JINC   :       /* 0x003E */
			case _tc_JNIC   :       /* 0x003F */
			case _tc_JEQV   :       /* 0x0058 */
			case _tc_JNEV   :       /* 0x0059 */
			case _tc_JGEV   :       /* 0x005A */
			case _tc_JLEV   :       /* 0x005B */
			case _tc_JGRV   :       /* 0x005C */
			case _tc_JLSV   :       /* 0x005D */
			case _tc_JINV   :       /* 0x005E */
			case _tc_JNIV   :       /* 0x005F */
			case _tc_JEQR   :       /* 0x0078 */
			case _tc_JNER   :       /* 0x0079 */
			case _tc_JGER   :       /* 0x007A */
			case _tc_JLER   :       /* 0x007B */
			case _tc_JGRR   :       /* 0x007C */
			case _tc_JLSR   :       /* 0x007D */
			case _tc_JINR   :       /* 0x007E */
			case _tc_JNIR   :       /* 0x007F */
				if ((i = avm_compare(tcode, i)) != 0)
					continue;
				else    break;

			/* Exception and Error Catching Functions */
			/* -------------------------------------- */
			case _tc_OEO    :       /* 0x0010 */
			case _tc_OLE    :       /* 0x0057 */
			case _tc_OEV    :       /* 0x0040 */
				if ((i = avm_catcher( tcode, i )) != 0)
					continue;
				else    break;

			case _tc_ERA    :       /* 0x0042 */
				rtl_void_statement( "rtl_abort" );
				continue;

			case _tc_OEP    :       /* 0x0030 */
				continue;

			/* Resume After Error */
			/* ------------------ */
			case _tc_RES    :       /* 0x0060 */
			case _tc_REQ    :       /* 0x0067 */
				continue;

			case _tc_DTV    :       /* 0x0027 */
				continue;

			case _tc_PSH    :       /* 0x0025 */
			case _tc_POP    :       /* 0x0045 */
				i++;
				continue;

			case _tc_SGN    :       /* 0x0050 */
				continue;

			case _tc_LDE    :       /* 0x0070 */
				if ((i = esc_call( i )) != 0)
					continue;
				else    break;

			/* Event Instructions TIMER, KEYBOARD, HARD/SOFT */
			/* --------------------------------------------- */
			case _tc_TIM    :       /* 0x0020 */
			case _tc_TPC    :       /* 0x0036 */
			case _tc_WHN    :       /* 0x0076 */

				continue;

			/* Optimised Variable Access */
			/* ------------------------- */
			case _tc_GIL    :       /* 0x0053 */
			case _tc_GCL    :       /* 0x0026 */
			case _tc_LIL    :       /* 0x0073 */
			case _tc_LCL    :       /* 0x0017 */
				if ((i = avm_optimised_load( tcode, i )) != 0)
					continue;
				else    break;

			case _tc_GIS    :       /* 0x0013 */
			case _tc_GCS    :       /* 0x0046 */
			case _tc_LCS    :       /* 0x0066 */
			case _tc_LIS    :       /* 0x0033 */
			case _tc_GWS    :       /* 0x0075 */
			case _tc_LWS    :       /* 0x0077 */
				if ((i = avm_optimised_store( tcode, i )) != 0)
					continue;
				else    break;
			}
		break;
		}
	(void) atoc_newline(MOINS_UN);
	rtl_close_block();
	rtl_linefeed();
	return(0);
}

PUBLIC  TCVARPTR        atoc_declaration( vptr, mode )
	TCVARPTR        vptr;
	WORD            mode;   /* 1 : Initialise, 0 : No Init */
{
	if ( vptr->type->type & _TYPE_DEFINED ) {
		atoc_generate_class( vptr, vptr->type->class,"\0", 0 );
		atoc_type( vptr->type,vptr->name );
		if ( mode )
			atoc_init( vptr->type );
		return( avoid_members(vptr,vptr->prev) );
		}
	else    {
		atoc_type( vptr->type,vptr->name );
		if ( mode )
			atoc_init( vptr->type );
		return( vptr->prev );
		}
}

PUBLIC  VOID            atoc_build_string( vptr, sptr )
	TCVARPTR        vptr;
	BPTR            sptr;
{
	if ( vptr->type->type & _TYPE_FIRST ) {
		rtl_flushline();
		rtl_puts("for (__xdim=0; __xdim < ");
		rtl_putu(vptr->type->first);
		rtl_puts("; __xdim++ )");
		rtl_enter(1);
		if ( vptr->type->type & _TYPE_SECOND ) {
			rtl_flushline();
			rtl_puts("for (__ydim=0; __ydim < ");
			rtl_putu(vptr->type->first);
			rtl_puts("; __ydim++ )");
			rtl_enter(1);
			}

		}

	rtl_flushline();
	rtl_puts("build_string");
	rtl_leftbrace;
	rtl_puts( avm_address( avm_variable( vptr->descriptor ) ) );

	if ( vptr->type->type & _TYPE_FIRST ) {
		rtl_puts("[__xdim]");
		if ( vptr->type->type & _TYPE_SECOND )
			rtl_puts("[__ydim]");
		}

	rtl_comma; rtl_putb( 0x0022 ); rtl_puts( sptr ); rtl_putb( 0x0022 );
	rtl_comma; rtl_putu( vptr->type->size );
	rtl_rightbrace; rtl_semicolon;

	if ( vptr->type->type & _TYPE_FIRST ) {
		if ( vptr->type->type & _TYPE_SECOND )
			rtl_leave(1);
		rtl_leave(1);
		}
	return;
}

PUBLIC  TCVARPTR        atoc_class_strings( hptr, class )
	TCVARPTR        hptr;
	TCSTRUCTPTR     class;
{
	TCVARPTR        vptr;
	if ((vptr = hptr->prev) != (TCVARPTR) 0) {
		do      {
			if (!( is_member_of_host( hptr, vptr ) ))
				break;
			else if (vptr->type->type & _TYPE_DEFINED ) {
				switch ( vptr->type->type & _TYPE_SPECIAL ) {
					case    _TYPE_POINTER :
					case    _TYPE_MBPTR   :
						vptr = avoid_members( vptr, vptr->prev );
						break;
					default               :
						vptr = (TCVARPTR)atoc_class_strings( vptr, (TCSTRUCTPTR)vptr->type->class );
						break;
					}

				}
			else    {
				if (( vptr->type->type & _TYPE_BASIC ) == _TYPE_STRING) {
					switch ( vptr->type->type & _TYPE_SPECIAL ) {
						case    _TYPE_POINTER :
						case    _TYPE_MBPTR   :
							break;
						default               :
							if ( vptr->type->class == (VPTR) 0)
								atoc_build_string( vptr, " " );
							break;
						}
					}
				vptr = vptr->prev;
				}
			}
		while ( vptr != (TCVARPTR) 0 );
		}
	return( vptr );
}



PRIVATE WORD            master_is_parameter( vptr )
	TCVARPTR        vptr;
{
	TCVARPTR        mptr;
	/* Return to original VDT entry */
	/* ---------------------------- */
	while ( vptr->parent != (TCVARPTR) 0 )
		vptr = vptr->parent;

	/* No Master so not parameter */
	/* -------------------------- */
	if ( vptr->master == 0 )
		return( vptr->master );

	if ((mptr = vptr->next) != (TCVARPTR) 0) {
		do      {
			if ( mptr->descriptor == vptr->master ) {
				if ( mptr->master == 0 )
					break;
				else    vptr = mptr;
				}
			}
		while ((mptr = mptr->next) != (TCVARPTR) 0);
		}
	if ( mptr != (TCVARPTR) 0)
		return( mptr->type->type & _TYPE_PARAMETER );
	else    return( 0 );

}

PUBLIC  VOID    atoc_build( vptr, mode, sptr )
	TCVARPTR        vptr;   /* Variable to Build    */
	WORD            mode;   /* 1 : GDS, 0 : LDS     */
	BPTR            sptr;   /* Initial Value        */
{
	WORD    hold_output;
	WORD    hold_indent;    
	if (( vptr->type->type & (_TYPE_DEFINED | _TYPE_STRING)) == _TYPE_STRING ) {
		switch ( vptr->type->type & _TYPE_SPECIAL ) {
			case    0:
				if ( mode ) {
					if (!( context_is_module )) {
						hold_output = rtl_get_active();
						rtl_use_body();
						Indentation = 1;
						atoc_build_string( vptr, sptr );
						rtl_set_active( hold_output );
						}
					}

			}
		}
	return; 

}

PUBLIC  TCVARPTR        atoc_variable( vptr, mode )
	TCVARPTR        vptr;
	WORD            mode;   /* 1 : GDS, 0 : LDS */
{
	if ( vptr->type->type & _TYPE_PARAMETER )
		return( vptr->prev );
	else if ( master_is_parameter( vptr ) )
		return( vptr->prev );
	else    {
		rtl_linefeed();
		rtl_indentation();
		atoc_build(vptr, mode, " ");
		vptr = atoc_declaration( vptr, 1 );
		rtl_semicolon;
		return( vptr );
		}
}

PRIVATE VOID            atoc_parameters( vptr, mode, avoid )
	TCVARPTR        vptr;
	WORD            mode;
	WORD		avoid;
{
	WORD    nombre=0;
	rtl_leftbrace;
	while ( vptr != (TCVARPTR) 0 ) {
		if (!( vptr->type->type & _TYPE_PARAMETER ))
			break;
		else    {
			if ( avoid ) {
				avoid--;
				vptr = vptr->prev;
				}
			else	{
				if ( nombre++ ) rtl_comma;
				vptr = atoc_declaration( vptr,0 );
				}
			}
		}
	rtl_rightbrace;
	if ( mode ) rtl_semicolon; 
	return;
}


PUBLIC  VOID            atoc_variables( tptr,scope,memsize )
	TCVDTPTR        tptr;
	WORD            scope;
	WORD            memsize;
{
	TCVARPTR        vptr;

	if ((vptr = tptr->first) != (TCVARPTR) 0) {
		if (!( scope & ISLOCAL )) {

			if (!( context_is_module )) {
				rtl_use_body();
				rtl_linefeed(); 
				rtl_puts("public void gds_initialisation()"); 
				rtl_start_block();
				}

			rtl_use_footer(); rtl_comment( "Global Variables" );

			while ( vptr != (TCVARPTR) 0)
				vptr = atoc_variable( vptr,1 );

			rtl_linefeed();
			
			if (!( context_is_module )) {
				rtl_use_body();
				rtl_flushline(); rtl_puts( "return;"); rtl_close_block();
				rtl_linefeed();

				rtl_linefeed(); rtl_puts("public int main(argc,argv)"); 
				rtl_linefeed(); rtl_puts("int argc;");
				rtl_linefeed(); rtl_puts("char * argv[];");
				rtl_start_block();
				rtl_flushline(); rtl_puts( "int _arge=0;");
				rtl_flushline(); rtl_puts( "rtl_catch(_arge,argl);");
				rtl_flushline(); rtl_puts( "gds_initialisation();");
				rtl_flushline(); rtl_puts( "segment_0();");
				rtl_flushline(); rtl_puts( "rtl_abort();"); 
				rtl_flushline(); rtl_puts( "return(0);"); 
				rtl_linefeed();  rtl_puts( "argl:\t" );
				rtl_puts("sysprintf("); 
				rtl_quote;
				rtl_backslash;
				rtl_puts("n* * Runtime Exception ");
				rtl_percent;
				rtl_puts("u * * "); rtl_backslash; rtl_puts("n");
				rtl_quote;
				rtl_comma;
				rtl_puts("_arge);");
				rtl_flushline(); rtl_puts( "return(0);"); 
				rtl_close_block();
				}

			rtl_close_files();
			}
		}

	return;
}


PUBLIC  VOID    atoc_constant( cptr, pptr )
	TCCONPTR        cptr;
	BPTR            pptr;
{
	WORD    bcount=0;
	WORD    i=0;
	rtl_linefeed();

	switch ( (cptr->type->type & _TYPE_BASIC) ) {
		case    _TYPE_NUMERIC   :
		case    _TYPE_STRING    :
			atoc_classtype( "string");
			if ( cptr->name != (BPTR) 0 )
				rtl_puts( cptr->name );
			else    {
				rtl_putb('$');
				rtl_puts( pptr );
				rtl_putu( cptr->identity );
				}
			rtl_equals; rtl_enter(0);
			rtl_space;
			rtl_putu( cptr->type->size );
			rtl_comma;
			rtl_puts(" (unsigned char *) ");
			rtl_putb(0x0022);
			while ( i < cptr->type->size ) {
				rtl_putb(*(cptr->value + i));
				i++;
				}
			rtl_putb(0x0022);
			rtl_space;
			rtl_leave(0);
			rtl_semicolon;
			break;
		}
	return;
}

PUBLIC  VOID    atoc_constants( cptr, pptr )
	TCCONPTR        cptr;
	BPTR            pptr;
{

	rtl_use_header();

	if ( *pptr == 'G' )
		rtl_comment( "Global Constants" );
	else    rtl_comment( "Local Constants"  );

	Indentation=0;
	while ( cptr != (TCCONPTR) 0) {
		atoc_constant( cptr, pptr );
		cptr = cptr->next;
		}

	return;


}

PRIVATE VOID            atoc_class_header( class )
	TCSTRUCTPTR     class;
{
	Indentation = 0;
	rtl_comment( class->name );
	rtl_linefeed();

	if ( get_pragma_output() > 1 )        
		atoc_access( _MEMBER_PUBLIC );

	if ( get_pragma_output() > 0 ) {
		rtl_puts("class ");
		rtl_puts( class->name );
		}

	else	atoc_classtype( class->name );

	rtl_space;      
	
	if ( get_pragma_output() > 0 ) {        
		AtocClassMembers=0; AtocBaseMembers=0;
		}
	else    {
		AtocClassMembers=1; AtocBaseMembers=0;
		rtl_enter(1);
		}
	return;
}

PRIVATE VOID    atoc_struct( sptr, nptr, mode )
	BPTR    sptr;
	BPTR    nptr;
	WORD    mode;   /* 1 : Pointer , 0 Not Pointer  */
{
	atoc_classtype( sptr );
	if ( mode )             rtl_putptr();
	rtl_space;              rtl_puts( nptr );
	return;
}


PRIVATE WORD            atoc_class_member(class, member, dptr )
	TCSTRUCTPTR     class;
	TCMEMBERPTR     member;
	TCMBDATAPTR     dptr;
{
	if ( dptr->structname != (BPTR) 0 ) {
		rtl_linefeed(); rtl_indentation();
		atoc_access( member->access );
		atoc_struct( dptr->structname, member->name, 0 );
		rtl_semicolon;
		}               
	else if ( dptr->type != (TCTYPPTR) 0) {
		rtl_linefeed(); rtl_indentation();
		atoc_access( member->access );
		atoc_type( dptr->type, member->name );
		rtl_semicolon;
		}
	return(0);
}

PRIVATE WORD            atoc_c_method(class, member, dptr )
	TCSTRUCTPTR     class;
	TCMEMBERPTR     member;
	VPTR            dptr;
{
	if ( member->access & _MEMBER_INDIRECT ) {
		rtl_linefeed(); rtl_indentation();
		atoc_access( member->access );
		atoc_methptr( dptr, member->name, 0 );
		rtl_semicolon;
		}
	else if ((   member->access & _MEMBER_VIRTUAL )
	     &&  (!( member->access & _MEMBER_OVERLOAD ))) {
		rtl_linefeed(); rtl_indentation();
		atoc_access( member->access );
		atoc_methptr( dptr, member->name, 1 );
		rtl_semicolon;
		rtl_linefeed(); rtl_indentation();
		atoc_access( member->access );
		atoc_struct( class->name, member->name, 1 );
		rtl_semicolon;
		}
	return(0);
}

PRIVATE WORD            atoc_cpp_method(class, member, method )
	TCSTRUCTPTR     class;
	TCMEMBERPTR     member;
	VPTR            method;
{
	WORD		status;
	TCPRCPTR	procedure;
	WORD		output_status;
	WORD		return_type;
	TCPRCPTR	add_function_method( BPTR,TCVARPTR,TCTYPPTR,WORD,WORD, WORD, WORD);

	rtl_linefeed(); rtl_indentation();
	atoc_access( member->access );

	if (( member->access & _MEMBER_INDIRECT)
	||  ( member->access & _MEMBER_VIRTUAL )
	||  ( member->access & _MEMBER_OVERLOAD) )
		rtl_puts( " virtual ");

	atoc_methptr( method, member->name, 8 );
	rtl_semicolon;

	output_status = rtl_get_active();
	rtl_use_body();
	rtl_linefeed();
#ifdef	_DUMMY_CPP
	return_type = atoc_method_return( method ); 
		rtl_puts( class->name ); rtl_colon; rtl_colon; rtl_puts( member->name );
		atoc_method_parameters( method, 8 );
		rtl_linefeed();
	rtl_enter(1);
		rtl_linefeed(); 
		rtl_indentation(); rtl_puts("return");
		if ( return_type ) {
			rtl_leftbrace; rtl_leftbrace;
			return_type = atoc_method_return( method );
			rtl_rightbrace; rtl_putd(0); rtl_rightbrace;
			}
		rtl_semicolon; 
		rtl_linefeed();
		rtl_leave(1);
	rtl_linefeed();

#else	/* ! DUMMY_CPP */

	if ((procedure = add_function_method(member->name,resolve_method_parameters( method ), resolve_method_type( method ) ,0, 0, 0, FAUX )) != (TCPRCPTR) 0) {
		procedure->class  = (VPTR)class;
		procedure->member = (VPTR)member;
		status = flush_function_method( class, member, method, procedure );
		rtl_linefeed();
		}
#endif

	rtl_set_active( output_status );
	return(0);
}

PRIVATE WORD            atoc_java_method(class, member, dptr )
	TCSTRUCTPTR     class;
	TCMEMBERPTR     member;
	VPTR            dptr;
{
	rtl_linefeed(); rtl_indentation();
	atoc_access( member->access );
	atoc_methptr( dptr, member->name, 8 );
	rtl_space;
	rtl_enter(1);
	rtl_flushline(); 
	rtl_leave(1);
	return(0);
}

PRIVATE WORD            atoc_class_method(class, member, dptr )
	TCSTRUCTPTR     class;
	TCMEMBERPTR     member;
	VPTR            dptr;
{
	if ( dptr != (VPTR) 0 ) {
		switch ( get_pragma_output() ) {
			case	0	: return( atoc_c_method( class, member, dptr ) );
			case	1	: return( atoc_cpp_method( class, member, dptr ) );
			case	2	: 
			case	3	: return( atoc_java_method( class, member, dptr ) );
			}
		}
	return( 0 );
}

PRIVATE VOID            atoc_class_footer( class )
	TCSTRUCTPTR     class;
{
	switch ( get_pragma_output() ) {
		case	1 :
			if (!( AtocClassMembers )) {
				rtl_semicolon;
				rtl_linefeed();
				break;
				}
		case	2 :
		case	3 :
		case	0 :
			rtl_linefeed(); 
			rtl_leave(1);   rtl_semicolon;
			rtl_linefeed();
		}
	return;
}

PRIVATE TCMBDATAPTR	is_atoc_base_member( member )
	TCMEMBERPTR     member;
{
	TCMBDATAPTR     dptr;
	if ( member->special != (VPTR) 0 ) {
		switch ( member->nature ) {
			case _KW1_IND   :
			case _KW1_OBJ   :
			case _KW1_OVL   :
			case _KW1_DCL   :
			case _KW1_PTR   :
			case _KW1_ARG   :
				if (((dptr = (TCMBDATAPTR) member->special) != (TCMBDATAPTR) 0)                        
				&&  (dptr->structname != (BPTR) 0)
				&&  (compare_tokens(dptr->structname,member->name)))
					return(dptr);
			}
		}
	return((TCMBDATAPTR) 0 );
}

PRIVATE WORD		atoc_base_member( member )
	TCMEMBERPTR     member;
{
	TCMBDATAPTR     dptr;
	if ((dptr = is_atoc_base_member( member )) != (TCMBDATAPTR) 0 ) {
		if ( AtocBaseMembers++ ) {
			if ( get_pragma_output() == 2 )
				rtl_puts(" implements ");
			else    { rtl_comma; rtl_space; }
			}
		else    {    
			if ( get_pragma_output() > 1 )                                               
				rtl_puts(" extends ");
			else    { rtl_colon; rtl_space; }
			}

		atoc_access( member->access );
		rtl_puts( dptr->structname );
		return(1);
		}

	rtl_linefeed();    
	rtl_enter( 1 );
	AtocClassMembers=1;
	return(0);
}



PUBLIC  WORD            atoc_put_class( class )
	TCSTRUCTPTR     class;
{
	TCMBDATAPTR	dptr;
	TCMEMBERPTR     member;
	WORD            status;
	WORD		publics=0;
	if (( class != (TCSTRUCTPTR) 0)
	&&  (!( is_member_library(class) ))) {
		rtl_use_header();
		atoc_class_header( class );
		if ( get_pragma_output() > 0 ) {
			rtl_semicolon;
			rtl_use_footer();
			atoc_class_header( class );
			}
		if ((member = class->first) != (TCMEMBERPTR) 0) {
			do      {
				if ((!( AtocClassMembers ))
				&&  ( atoc_base_member( member ) )) 
					continue;
				if (( member->access & _MEMBER_PUBLIC )
				&&  ( member->special != (VPTR) 0 )) {
					if ((!( publics++ ))
					&&  ( get_pragma_output() == 1 )) {
						rtl_linefeed();
						rtl_puts("public");
						rtl_colon;
						rtl_linefeed();
						}
					switch ( member->nature ) {
						case _KW1_IND   :
						case _KW1_OBJ   :
						case _KW1_OVL   :
						case _KW1_DCL   :
						case _KW1_PTR   :
						case _KW1_ARG   :
							if ((status = atoc_class_member( class, member, member->special )) != 0)
								return( status );
							else    continue;
						case _KW1_CONST :
							continue;
						default         :
							if ((status = atoc_class_method( class, member, member->special )) != 0)
								return( status );
							else    continue;

						}
					}
				}
			while ((member = member->next) != (TCMEMBERPTR) 0);
			}
		if ((member = class->first) != (TCMEMBERPTR) 0) {
			publics=0;
			do      {
				if (((dptr = is_atoc_base_member( member )) == (TCMBDATAPTR) 0 )
				&&  (!(member->access & _MEMBER_PUBLIC ))
				&&  ( member->special != (VPTR) 0 )) {
					if ((!( publics++ ))
					&&  ( get_pragma_output() == 1 )) {
						rtl_linefeed();
						rtl_puts("private");
						rtl_colon;
						rtl_linefeed();
						}
					switch ( member->nature ) {
						case _KW1_IND   :
						case _KW1_OBJ   :
						case _KW1_OVL   :
						case _KW1_DCL   :
						case _KW1_PTR   :
						case _KW1_ARG   :
							if ((status = atoc_class_member( class, member, member->special )) != 0)
								return( status );
							else    continue;
						case _KW1_CONST :
							continue;
						default         :
							if ((status = atoc_class_method( class, member, member->special )) != 0)
								return( status );
							else    continue;

						}
					}
				}
			while ((member = member->next) != (TCMEMBERPTR) 0);
			}
		atoc_class_footer( class );
		}
	return( 0 );
}

PUBLIC  VOID    atoc_create_library()
{
	rtl_use_header();
	return;
}

PUBLIC  VOID    atoc_close_library()
{
	rtl_close_files();
	return;
}



#endif  /* _TRATOC_C */
	/* --------- */



