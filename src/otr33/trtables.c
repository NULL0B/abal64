#define DEBUG
/* -------------------------------------------------------------------- */
/*                                                                      */
/*              Project ABAL : Macro pre-processer                      */
/*                                                                      */
/*               Copyright (c) 1990,1995 Amenesik / Sologic s.a.                  */
/*                                                                      */
/*                                                                      */
/*              File    :       TRTABLES.C                              */
/*              Version :       2.2a                                    */
/*              Date    :       16/02/1995                              */
/*                                                                      */
/* -------------------------------------------------------------------- */
/*      Modifications Log  (most recent first please!)                  */
/* -------------------------------------------------------------------- */
/* 12/01/1996   :       Correction to allow more then one user library  */
/*                      in a translation unit. Prior to this date only  */
/*                      the last user library encountered was added to  */
/*                      the tcode user library table. (cf TRLDF.C)      */
/* -------------------------------------------------------------------- */

#ifndef _TRTABLES_C
#define _TRTABLES_C

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "stdtypes.h"
#include "translat.h"
#include "trsyntax.h"
#include "trsymbol.h"
#include "troption.h"
#include "trmember.h"
#include "trcommon.h"
#include "trdebug.h"
#include "trstatic.h"
#include "trtables.h"
#include "trecho.h"
#include "trerrors.h"
#include "trparser.h"
#include "trproc.h"
#include "trinput.h"
#include "triof.h"
#include "troutput.h"
#include "trclass.h"
#include "trabal.h"
#include "trlabels.h"
#include "trapl.h"
#include "triter.h"
#include "trldf.h"

#ifndef UNIX
static	WORD	descriptor_table_usage( TCVARPTR );
static	WORD	establish_tcode_argument( TCVARPTR );
static	VOID	flush_used_variables( TCVARPTR, WORD );
static	VOID	flush_all_variables( TCVARPTR, WORD );
static	VOID	flush_used_varreloc( TCVARPTR );
static	VOID	flush_all_varreloc( TCVARPTR );
static	WORD	flush_stop(WORD);
#else
WORD            resolve_real_identity();
VOID            liberate_for_constant();
#endif

EXTERN  BYTE    TokenBuffer[];


/*      Pre-allocation storage Pointers         */
/*      -------------------------------         */
static  TCVARPTR        FreeVariable=(TCVARPTR) 0;
static  TCVARPTR        UsedVariable=(TCVARPTR) 0;
static  TCTYPPTR        FreeType=(TCTYPPTR) 0;
static  FIELDNODEPTR    FreeFields=(FIELDNODEPTR) 0;

WORD    not_legal_digit( sp, slen )
BPTR    sp;
WORD    slen;
{
	if ( slen > 0 )
		if ((( *sp >= '0' ) && ( *sp <= '9' ))
		||   ( *sp == '.' ))
			return(0);
	return(1);
}

WORD atobcd(sp,slen,bcd,len)
BPTR    sp;
WORD    slen;
BPTR    bcd;
WORD    len;
{
register WORD phase,x;
	 WORD   db;
	 WORD   mode;
	 WORD   fraction=0;
	 WORD total=0;

/* Ignore leading Spaces */
/* --------------------- */
while (( slen > 0 ) && ( *sp == ' ' )) { slen--; sp++; }

db = 0x00C0; phase = 0; mode = 0;
		
while (( len > 0 ) && ( slen > 0 )) {
	x = *(sp++); slen--;
	switch ( phase ) {

		case 0 : /* Collect and Set Digit * no exit on sign * */
			 /* ----------------------------------------- */
			switch ( x ) {
				case ' '        : slen = 0; continue;
				case '-'        : db = 0x00B0;
				case '+'        : continue;
				}

		case 2 : /* Establish Low order digit  */
			 /* -------------------------  */
			if (( x >= '0' ) && ( x <= '9' )) { x -= '0'; }
			else    {
				if (( x == '.' ) || ( x == ',')) { 
					if ( fraction ) {
						slen = 0;
						continue;
						}
					fraction = 1;
					mode = 1; 
					x = 0x000A; 
					}
				else    { slen = 0; continue; }
				}
			if ((( x != 0 ) || ( mode != 0 ) )
			||  ( not_legal_digit( sp, slen ) )) {
				*(bcd++) = (BYTE) ( db | x ); len--; total++;
				phase = 1; mode = 1;
				}
			continue;

		case 1 : /* Establish High order digit */
			 /* -------------------------- */
			if (( x >= '0' ) && ( x <= '9' )) { db = ((x - '0') << 4); }
			else    {
				if (( x == '.' ) || ( x == ',')) { 
					if ( fraction ) {
						slen = 0;
						continue;
						}
					fraction = 1;
					mode = 1; 
					db = 0x00A0; 
					}
				else    { slen = 0; continue; }
				}
			phase = 2; continue;

		}
	}
if ( len > 0 ) {
	switch ( phase ) {
		case 2 : *(bcd++) = (BYTE) (db | 0x000F); len--; total++; break;
		case 0 : *(bcd++) = (BYTE) 0x00C0; len--; total++;
		}
	while ( len > 0 ) { *(bcd++) = (BYTE) 0x00FF; len--; }
	}       
return(total);
}

HUGE    LongProduct( taille, outer, inner )
WORD    taille;
WORD    outer;
WORD    inner;
{
	HUGE    product=0L;
/*
	WORD    o;
	WORD    i;
*/
	product = (((HUGE) taille) * ((HUGE)inner));
	product *= ((HUGE) outer);
/*
	for ( o = 0; o < outer; o++ )
		for ( i = 0; i < inner; i++ )
			product += (HUGE) taille;
 */
	return( product );
}

LONG    ShortMul( lop, rop )
WORD    lop;
WORD    rop;
{
	WORD    top;
	LONG    r=0L;
/*      sysprintf("ShortMul(%d * %d)\n",lop,rop);  */
	if ( rop > lop ) {
		top = lop;
		lop = rop;
		rop = top;
		}
	while ( rop != 0 ) {
		r = r + ((LONG) lop);
		rop--;
		}
	return( r );
}

LONG    LongMul( lop, rop )
LONG    lop;
WORD    rop;
{
	LONG    r=0L;
	while ( rop != 0 ) {
		r += lop;
		rop--;
		}
	return( r );
}
 
LONG    FieldIndent( vptr, first, second )
TCTYPPTR        vptr;
WORD            first;
WORD            second;
{
	LONG    temp2=0L;
	LONG    result=0L;

/*      sysprintf("FieldIndent( %d, %d )\n",first,second);         */

	if ( vptr->type & _TYPE_FIRST) {
		if ( first > 1 ) {
			if ( first > vptr->first )
				return( -1L );
			result += ShortMul( vptr->size , ( first - 1 ) );
			}
		if ( vptr->type & _TYPE_SECOND ) {
			if ( second > 1 ) {
				if ( second > vptr->second )
					return( -1L );
				temp2   = ShortMul( vptr->size , vptr->first );
				result += LongMul( temp2, (second-1) );
				}
			}
		}
	return( result);
}

WORD    field_equals_m()
{
	if (( Context != (TCFDTPTR) 0 )
	&&  ( Context->ThisField != (FIELDPTR) 0)) {
		Context->ThisField->Field = 0;  
		Context->ThisField->SmallField = Context->ThisField->MaxSmallField;
		Context->ThisField->Host  = 0;
		if ( OtrOption.ListFlag & 1 )
			echo_field(0,(BPTR) 0);
		}
	return(0);
}

WORD    field_equals_file( handle )
WORD    handle;
{
	Context->ThisField->Field = handle;
	Context->ThisField->FileField = 0L;
	Context->ThisField->Host = 0;
	if ( OtrOption.ListFlag & 1 )
		echo_field(handle,(BPTR) 0);
	return(0);
}

WORD    field_equals_f()
{
	if (( Context != (TCFDTPTR) 0 )
	&&  ( Context->ThisField != (FIELDPTR) 0)) {
		Context->ThisField->Field = MOINS_UN;
		Context->ThisField->SmallField = Context->ThisField->MaxSmallField;
		Context->ThisField->Host  = 0;
		}
	return(0);
}

WORD    field_equals_g()
{
	Context->ThisField = (FIELDPTR) & Context->GlobalField;
	Context->scope = 0;
	return(0);
}

WORD    field_equals_v( vptr, indent )
TCVARPTR        vptr;
LONG            indent;
{
	WORD    handle;
	if ( vptr->type->type & 0x8000 ) {
		if ( vptr->type->type & 0x1000 ) {
			Context->ThisField->Host = vptr->identity;
			Context->ThisField->SmallField = indent;
			}
		else    {
			Context->ThisField->Host = vptr->host;
			Context->ThisField->SmallField = (WORD) (vptr->offset+indent);
			}
		}
	else if ( vptr->type->type & _TYPE_EXTENDED ) {
		Context->ThisField->BigField = (HUGE)(vptr->offset + indent);
		if ( OtrOption.ListFlag & 1 )
			echo_field(_TYPE_EXTENDED,vptr->name);
		}
	else if ((handle = vptr->type->type & _TYPE_VIRTUAL )) {
		Context->ThisField->FileField = (HUGE) (vptr->offset + indent);
		if ( OtrOption.ListFlag & 1 )
			echo_field((handle >> 8),vptr->name);
		}
	else    {
		Context->ThisField->SmallField = (WORD) (vptr->offset+indent);
		if ( OtrOption.ListFlag & 1 )
			echo_field(0,vptr->name);
		}
	return( 0 );
}


WORD    field_equals_l()
{
	trace("field_equals_l()\n");
	if ( Context->LDT != (TCVDTPTR) 0 ) {
		Context->ThisField = (FIELDPTR) & Context->LocalField;
		Context->scope = ISLOCAL;
		return(0);
		}
	else    return( syntax_error(665) );
}

VOID	drop_global_labels()
{
	TCLABELPTR	lptr;
	while ((lptr = Context->GLT) != (TCLABELPTR) 0) {
		Context->GLT = lptr->next;
		if ( lptr->name != (BPTR) 0 )
			liberate( lptr->name );
		liberate( lptr );
		}
	return;
}

WORD	check_data_label( BPTR nptr )
{
	TCLABELPTR	lptr;
	WORD		field=0;

	if (!( nptr ))
		return(0);
	else if (!( Context ))
		return(0);
	else if ( Context->CurrentSegment != (TCSEGPTR) 0 )
		return(0);
	else if ( Context->PRC != (TCPRCPTR) 0 )
		return(0);
	else if (!( is_equals() )) 
		return( syntax_error(152) );
	else	{

		if ( is_mnemonic("E") )
			field = 'E';
		else if (!( is_mnemonic("M") ))
			return( syntax_error(151) );
		else	field = 'M';

		if (!(lptr = allocate( sizeof( TCLABEL ) )))
			return( allocation_failure() );
		else	{
			lptr->prev = lptr->next = (TCLABELPTR) 0;
			if ( *nptr == '&' )
				nptr++;
			if (!( lptr->name = allocate( strlen(nptr)+1 ) )) {
				liberate( lptr );
				return( allocation_failure() );
				}
			else	strcpy( lptr->name, nptr );
			if ((lptr->field = field) == 'M')
				lptr->value = Context->ThisField->SmallField; 
			else	lptr->value = Context->ThisField->BigField; 
			if (( lptr->next = Context->GLT ) != (TCLABELPTR) 0)
				Context->GLT->prev = lptr;
			Context->GLT = lptr;
			Context->number_GLT++;
			return(1);
			}
		}
}

WORD	endloc_options( WORD v )
{
	TCPRCPTR        pptr;
	TCSEGPTR        sptr;

	if ((sptr = Context->CurrentSegment) != (TCSEGPTR) 0) {
		if ( v )
			sptr->options |= _STATIC_SEGM;
		else	sptr->options &= ~_STATIC_SEGM;
		return(0);
		}	
	else if ((pptr = Context->PRC) != (TCPRCPTR) 0) {
		if ( v )
			pptr->options |= _STATIC_PROC;
		else	pptr->options &= ~_STATIC_PROC;
		return(0);
		}
	else	return( syntax_error(665) );
}


WORD    copy_field( target, fptr )
FIELDPTR        target;
FIELDPTR        fptr;
{
	target->SmallField      =       fptr->SmallField;
	target->MaxSmallField   =       fptr->MaxSmallField;
	target->FileField       =       fptr->FileField;
	target->BigField        =       fptr->BigField;
	target->MaxBigField     =       fptr->MaxBigField;
	target->Field           =       fptr->Field;
	target->Host            =       fptr->Host;
	return(0);
}

WORD    common_field( target, fptr )
FIELDPTR        target;
FIELDPTR        fptr;
{
	target->SmallField      =       fptr->SmallField;
	target->FileField       =       fptr->FileField;
	target->BigField        =       fptr->BigField;
	target->Field           =       fptr->Field;
	target->Host            =       fptr->Host;
	return(0);
}

/*
 *      FIELD=(S)
 *      ---------
 *
 *      Store (Push) Current field
 *
 */

FIELDNODEPTR    allocate_for_field_node()
{
	FIELDNODEPTR    nptr;
	trace("allocate_for_field_node(");
	if ((nptr = (FIELDNODEPTR) allocate( sizeof( struct tcode_field_node ) )) != (FIELDNODEPTR) 0) {
		if ((nptr->contents = (FIELDPTR) allocate( sizeof( struct tcode_field ) )) != (FIELDPTR) 0)
			return( nptr );
		else    liberate( nptr );
		}
	return( (FIELDNODEPTR) 0);
}

WORD    field_equals_s()
{
	FIELDNODEPTR    nptr;
	if ((nptr = FreeFields) != (FIELDNODEPTR) 0)
		FreeFields = nptr->next;
	else if ((nptr = allocate_for_field_node()) == (FIELDNODEPTR) 0)
		return( allocation_failure() );

	copy_field( nptr->contents, Context->ThisField );
	nptr->next = Context->FieldHeap;
	Context->FieldHeap = nptr;
	return( 0 );
}

TCVDTPTR        allocate_for_vdt()
{
	TCVDTPTR        sptr;
	trace("allocate_for_vdt(");
	if ((sptr = (TCVDTPTR) allocate( sizeof( struct tcode_variable_table ))) != (TCVDTPTR) 0) {
		sptr->field     =(HUGE)0;
		sptr->maxfield  =(HUGE)0;
		sptr->nombre    =0;
		sptr->scope     =0;
		sptr->descriptor=0;
		sptr->Descriptor=0;
		sptr->variable  =(TCVARPTR) 0;
		sptr->first     =(TCVARPTR) 0;
		sptr->firstused =(TCVARPTR) 0;
		sptr->lastused  =(TCVARPTR) 0;
		}
	return( sptr );
}

WORD    liberate_external_field( fptr )
XTFIELDPTR      fptr;
{
	XTVARPTR        vptr;
	if ( fptr != (XTFIELDPTR) 0) {
		if ( fptr->name != (BPTR) 0)
			liberate( fptr->name );
		if ( fptr->field != (FIELDPTR) 0 )
			liberate( fptr->field );
		while ((vptr = fptr->member) != (XTVARPTR) 0) {
			fptr->member = vptr->next;
			liberate( vptr );
			}
		liberate( fptr );
		}
	return(0);
}

XTLOCALPTR      allocate_external_local()
{
	XTLOCALPTR      lptr;
	
	if ((lptr = (XTLOCALPTR) allocate( sizeof( struct tcode_local_extern ) )) != (XTLOCALPTR) 0) {
		lptr->number = ++Context->ExternalLocals;
		lptr->sector = 0;
		lptr->length = 0;
		lptr->next   = (XTLOCALPTR) 0;
		Context->CurrentXLT = lptr;
		}
	return( lptr );
}

WORD    add_external_local( xptr )
XTFIELDPTR      xptr;
{
	XTLOCALPTR      lptr;
	if ( Context->scope & ISLOCAL) {
		if (((lptr = Context->CurrentXLT) == (XTLOCALPTR) 0)
		&&  ((lptr = allocate_external_local()) == (XTLOCALPTR) 0))
			return( allocation_failure() );
		else    xptr->entry_XLT = lptr->number;
		xptr->nature |= 0x0010;
		}
	else    xptr->entry_XLT = 0;
	return(0);
}

WORD    add_external_field(module,zone,nptr,offset)
WORD    module;
WORD    zone;
BPTR    nptr;
LONG    offset;
{
	XTFIELDPTR      xptr;
	WORD            status;

	if ((xptr = (XTFIELDPTR) allocate( sizeof( struct tcode_extern_field ) )) != (XTFIELDPTR) 0) {
		if ((xptr->field = (FIELDPTR) allocate( sizeof( struct tcode_field ) )) != (FIELDPTR) 0) {
			copy_field( xptr->field, Context->ThisField );
			xptr->sector_XVT = 0;
			xptr->offset = offset;
			xptr->name   = nptr;
			xptr->nature = zone;
			xptr->module = module;
			xptr->member = (XTVARPTR) 0;
			xptr->members = 0;
			xptr->usedmembers = 0;
			if ((status = add_external_local( xptr )) == 0) {
				xptr->next = Context->CurrentXFT;
				Context->CurrentXFT = xptr;
				Context->ExternalFields++;
				return( 0 );
				}
			liberate( xptr->field );
			}
		liberate( xptr );
		}
	return( allocation_failure() );
}

WORD    field_equals_e()
{
	Context->ThisField->Field = 64; 
	Context->ThisField->BigField = Context->ThisField->MaxBigField;
	return( 0 );
}

/*
 *      FIELD=(R)
 *      ---------
 *
 *      Restore previously pushed field if any
 *
 */

WORD    field_equals_r()
{
	FIELDNODEPTR    nptr;
	if ((nptr = Context->FieldHeap) != (FIELDNODEPTR) 0) {
		copy_field( Context->ThisField, nptr->contents );
		Context->FieldHeap = nptr->next;
		nptr->next = FreeFields;
		FreeFields = nptr;
		}
	return( 0 );
}

WORD    release_fields()
{
	FIELDNODEPTR    nptr;
	WORD            nombre=0;
	while ((nptr = FreeFields) != (FIELDNODEPTR) 0) {
		FreeFields = nptr->next;
		liberate( nptr->contents );
		liberate( nptr );
		nombre++;
		}
	return( nombre );
}

WORD    tcode_program_identity()
{
	WORD	c;
	WORD    i=0;
	BPTR    nptr;
	nptr=(BPTR) TokenBuffer;
	if ( *nptr == '"' )
		nptr++;
	while (( *nptr ) && ( i < 15 )) {
		if ( *nptr == '"' )
			break;
		else    Context->identity[i++] = *(nptr++);
		}
	while ( i < 15 )
		Context->identity[i++] = ' ';           

	if ( OtrOption.UpperCase ) {
		for ( i=0; i < 15; i++ ) {
			c = Context->identity[i];
			if ((c >= 'a') &&  (c <= 'z'))
				Context->identity[i] = (( c - 'a') + 'A');
			}
		}
	return(0);
}

WORD    initialise_field( fptr )
FIELDPTR        fptr;
{
	if ( fptr != (FIELDPTR) 0) {
		fptr->SmallField=0;
		fptr->MaxSmallField=0;
		fptr->FileField=(HUGE)0;
		fptr->BigField=(HUGE)0;
		fptr->MaxBigField=(HUGE)0;
		fptr->Field=0;
		fptr->Host=0;
		}
	return(0);
}

WORD    set_global_scope()
{
	if ( Context != (TCFDTPTR) 0 ) {
		trace("set_global_scope()\n");
		(void) field_equals_g();
		}
	return(0);
}

WORD    set_local_scope()
{
	if ( Context != (TCFDTPTR) 0 ) {
		trace("set_local_scope()\n");
		(void) field_equals_l();
		initialise_field( Context->ThisField );
		}
	return(0);
}

WORD    build_token( tptr, source )
BPTR    tptr;
BPTR    source;
{
	WORD    i;
	BPTR    target=tptr;

	for ( i = 0; i < 32; i++ ) {
		if ( *source )
			*(target++) = *(source++);
		else    break;
		}

	*target = 0;
	*(tptr + OtrOption.TokenSize) = 0;
	return( i );
}

WORD    copy_token( vname, size )
BPTR    vname;
WORD    size;
{
	return( build_token( vname, TokenBuffer ) );
}

LONG    collect_field_indent(tptr)
TCTYPPTR        tptr;
{
	WORD    first=1;
	WORD    second=1;
	LONG    indent=0L;
	if ( is_left_brace() ) {
		trace("collect_field_indent()\n");
		first = integer_expression();
		if ( is_comma() )
			second = integer_expression();
		if (!(is_right_brace()))
			(void) unmatched_braces();
		indent = FieldIndent( tptr, first, second );    
		}
	return( indent );
}       

WORD    redefine_base_variable( vptr )
TCVARPTR        vptr;
{
	LONG            indent=0L;

	trace("redefine_base_variable("); trace(vptr->name); trace(")\n");
	indent = collect_field_indent( vptr->type );    
	return( field_equals_v( vptr, indent ) );
}

TCVARPTR	variable_symbol( BPTR vname )
{
	SYMBOLPTR       sptr;

	if ((sptr = is_symbol( vname )) == (SYMBOLPTR) 0)
		return((TCVARPTR) 0);
	else if ((sptr->type & SYMBOL_TYPE) != SYMBOL_VARB)
		return((TCVARPTR) 0);
	else	return((TCVARPTR) sptr->contents );
}

WORD    redefine_variable()
{
	BYTE            vname[65];
	TCVARPTR        vptr;
	LONG            indent=0L;

	trace("redefine_variable()\n");
	if ( copy_token( vname, 64 ) == 0 )
		return(syntax_error( 30 ));

	if ((!( vptr = variable_symbol( vname ) ))
	||  (!(vptr->type)))
		return( syntax_error(32) );
	return( redefine_base_variable( vptr ) );
}


WORD    dcl_filler( filler )
WORD    filler;
{
		switch ((Context->ThisField->Field)) {
			case 0  : 	
				Context->ThisField->SmallField += filler;
				if ((Context->ThisField->Host == 0)
				&&  ( Context->ThisField->SmallField > Context->ThisField->MaxSmallField ))
					Context->ThisField->MaxSmallField = Context->ThisField->SmallField;
				break;
			case 64 :
				Context->ThisField->BigField   += (HUGE) filler;
				if ( Context->ThisField->BigField > Context->ThisField->MaxBigField )
					Context->ThisField->MaxBigField = Context->ThisField->BigField;
				break;
			default :
				Context->ThisField->FileField  += (HUGE) filler;
				break;
			}

		return( 0 );
}

TCCONPTR        allocate_for_constant()
{
	TCCONPTR        sptr;
	trace("allocate_cor_constant(");
	if ((sptr = (TCCONPTR) allocate( sizeof( struct tcode_constant ))) != (TCCONPTR) 0) {
		sptr->identity=0;
		sptr->name=(BPTR) 0;
		sptr->type=(TCTYPPTR) 0;
		sptr->value=(BPTR) 0;
		sptr->length=0;
		sptr->relocation = (RELOCPTR) 0;
		sptr->hash = 0;
		sptr->redirect=(TCCONPTR) 0;
		sptr->next=(TCCONPTR) 0;
		}
	return( sptr );
}

WORD    add_to_variable_table( tptr, vptr, tusage )
TCVDTPTR        tptr;
TCVARPTR        vptr;
WORD            tusage;
{
	if ( tptr != (TCVDTPTR) 0 ) {
		trace("add_to_variable_table()\n");

		if (( tptr->nombre == 0 )
		&&  ( tptr->descriptor == 0)) {
			tptr->descriptor = (3*OtrOption.WordSize);
			tptr->first = vptr;
			}               

		vptr->vdt      = tptr;
		vptr->identity = (tptr->descriptor | (tptr->scope = Context->scope)); 

		if (!( OtrOption.Optimise & _OPTIMISE_TABLES))
			vptr->descriptor = vptr->identity;

		if ((vptr->next = tptr->variable) != (TCVARPTR) 0)
			tptr->variable->prev = vptr;
		tptr->variable = vptr;

		if ((!( OtrOption.Optimise & _OPTIMISE_TABLES ))
		&&  ( tusage ))
			tptr->nombre++;

		tptr->descriptor += tusage;
		vptr->usage       = tusage;
		}

	return(0);
}

TCBLKPTR        allocate_for_block()
{
	TCBLKPTR bptr;
	trace("allocate_for_block(");
	if ((bptr = (TCBLKPTR) allocate( sizeof( struct tcode_block ))) != (TCBLKPTR) 0) {
		bptr->code_sector=0;
		bptr->code_length=0;
		bptr->table_sector=0;
		bptr->table_length=0;
		bptr->const_sector=0;
		bptr->const_length=0;
		}
	return( bptr );
}

VOID    liberate_for_segment( sptr )
TCSEGPTR        sptr;
{

	if ( sptr != (TCSEGPTR) 0 ) {

		trace("liberate_for_segment()\n");

		if ( sptr->name != (BPTR) 0 )
			liberate( sptr->name );

		if ( sptr->details != (TCBLKPTR) 0 )
			liberate( sptr->details );

		liberate_cross_reference_list( sptr->crossref );

		liberate( sptr );
		}
	return;
}

TCSEGPTR        allocate_for_segment() 
{
	TCSEGPTR        sptr;
	trace("allocate_for_segment(");
	if ((sptr = (TCSEGPTR) allocate( sizeof( struct tcode_segment ))) != (TCSEGPTR) 0) {
		sptr->identity=0;
		sptr->name=(BPTR) 0;
		sptr->mode=MOINS_UN;
		sptr->offset = 0;
		sptr->options=0;
		sptr->crossref = (XREFPTR) 0;
		sptr->sector_XRF = 0;
		sptr->next=(TCSEGPTR) 0;
		sptr->symbolic.sector = 0;
		sptr->symbolic.length = 0;
		if ((sptr->details = (TCBLKPTR) allocate_for_block()) == (TCBLKPTR) 0) {
			liberate_for_segment( sptr );
			sptr = (TCSEGPTR) 0;
			}
		}
	return( sptr );
}


TCTYPPTR        allocate_for_type( t, l, f, s , c )
WORD    t;
WORD    l;
WORD    f;
WORD    s;
VPTR    c;
{
	TCTYPPTR        tptr;


	if ((tptr = FreeType) != (TCTYPPTR) 0)
		FreeType = (TCTYPPTR) ((VPTR) FreeType->class);
	else    {
		trace("allocate_for_type(");
		if ((tptr = (TCTYPPTR) allocate( sizeof(struct tcode_type))) == (TCTYPPTR) 0)
			return( tptr );
		}
	
	tptr->type = t;
	tptr->size = l;
	tptr->first = f;
	tptr->second = s;
	tptr->class  = c;
	return( tptr );
}

VOID    liberate_for_type( tptr )
TCTYPPTR        tptr;
{
	trace("liberate_for_type()\n");
	if ( tptr != (TCTYPPTR) 0) {
		switch ( tptr->type & 0x8F94 ) {
			case    0x8100 :
			case    0x8200 :
			case    0x8400 : 
				trace("liberate_extended_type()\n");
				liberate_for_type( tptr->class );
			}
		tptr->class = (void *) FreeType;
		FreeType    = tptr; 
		}
	return;
}

WORD    resolve_real_host( tptr, identity )
TCVDTPTR        tptr;
WORD            identity;
{
	TCVARPTR        vptr;
	trace("resolve_real_host()\n");
	if ((vptr = tptr->first) != (TCVARPTR) 0) {

		do      {
			if (( vptr->identity == identity )
			&&  ( vptr->type->size ))
				return( resolve_real_identity( vptr ) );

			}
		while ((vptr = vptr->prev) != (TCVARPTR) 0);
		}
	(void) internal_error(8899);
	return( identity );
}

WORD            resolve_real_identity( vptr )
TCVARPTR        vptr;
{
	TCVDTPTR        tptr;

	trace("resolve_real_identity()\n");


	/* Return to original VDT entry */
	/* ---------------------------- */
	while ( vptr->parent != (TCVARPTR) 0 )
		vptr = vptr->parent;

	if ( vptr->descriptor != 0 )
		return( vptr->descriptor );

/*      sysprintf("Entry %s id:%04.1X desc:%04.1X host:%04.1X \n",vptr->name,vptr->identity,vptr->descriptor,vptr->host);  */

	/* Ensure valid VDT */
	/* ---------------- */
	if ((tptr = vptr->vdt) == (TCVDTPTR) 0)
		return( vptr->identity );

	if (vptr->host != 0)
		vptr->host = resolve_real_host( tptr, vptr->host );

	/* Calculate Real Descriptor */
	/* ------------------------- */
	if (tptr->Descriptor == 0)
		vptr->descriptor = (3*OtrOption.WordSize);
	else    vptr->descriptor = tptr->Descriptor;

	/* Update Table Control Information */
	/* -------------------------------- */
	if ( vptr->type->size ) {
		tptr->Descriptor = (vptr->descriptor + vptr->usage);
		if ( tptr->Descriptor & ISLOCAL)
			return( internal_error( 4800 ) );
		tptr->nombre++;
		}

	/* Establish GLOBAL or LOCAL scope */
	/* ------------------------------- */
	vptr->descriptor |= tptr->scope;

	/* Add To Used Variable List of VDT */
	/* -------------------------------- */
	if (tptr->lastused == (TCVARPTR) 0)
		tptr->firstused = vptr;
	else    tptr->lastused->link = vptr;
	tptr->lastused = vptr;

	/* Return the Real Descriptor */
	/* -------------------------- */
/*      sysprintf("Exit  %s id:%04.1X desc:%04.1X host:%04.1X \n",vptr->name,vptr->identity,vptr->descriptor,vptr->host); */

	return( vptr->descriptor);

}

WORD            mark_variable( vptr )
TCVARPTR        vptr;
{
	if (( OtrOption.Optimise & _OPTIMISE_TABLES   )
	&&  ( vptr->descriptor == 0 ))  
		vptr->descriptor = resolve_real_identity( vptr );
	return(0);
}

TCVARPTR        allocate_for_variable()
{
	TCVARPTR        vptr;

	trace("allocate_for_variable(");

	if ((vptr = World->VariableHeap) != (TCVARPTR) 0)
		World->VariableHeap = vptr->next;

	else if ((vptr = (TCVARPTR) allocate( sizeof( struct tcode_variable ) )) == (TCVARPTR) 0) {
		(void) allocation_failure();
		return( vptr );
		}

	vptr->descriptor=0;
	vptr->module    =0;
	vptr->identity  =0;
	vptr->name      =(BPTR) 0;
	vptr->hash      = 0;
	vptr->offset    = 0L;
	vptr->host      = 0;
	vptr->master    = 0;
	vptr->nature    = 0;    /* Internal */
	vptr->access    = _TYPE_WRITABLE;
	vptr->usage     = 0;
	vptr->body      = _KW1_DCL;
	vptr->relocation = (RELOCPTR) 0;
	vptr->construction = (TCTEXTPTR) 0;
	vptr->vdt       =(TCVDTPTR) 0;
	vptr->type      =(TCTYPPTR) 0;
	vptr->next      =(TCVARPTR) 0;
	vptr->parent    =(TCVARPTR) 0;
	vptr->overloads =(TCVARPTR) 0;
	vptr->prev      =(TCVARPTR) 0;
	vptr->link      =(TCVARPTR) 0;
	vptr->class    = (VPTR) 0;
	vptr->firstdim = (VPTR) 0;
	vptr->secondim = (VPTR) 0;

	return( vptr );
}

VOID    release_variables()
{
	TCVARPTR        vptr;
	trace("release_variables()\n");
	while ((vptr = UsedVariable) != (TCVARPTR) 0) {
		UsedVariable = vptr->next;
		vptr->next = FreeVariable;
		FreeVariable = vptr;
		}
	return;
}

TCVARPTR        lock_used_variables()
{
	TCVARPTR        vptr=UsedVariable;
	UsedVariable = (TCVARPTR) 0;
	return( vptr );
}

VOID    unlock_used_variables( vptr )
TCVARPTR        vptr;
{
	release_variables();
	UsedVariable = vptr;
	return;
}

	

TCVARPTR        temp_variable( vptr )
TCVARPTR        vptr;
{
	TCVARPTR        sptr;
	if ( vptr == (TCVARPTR) 0 )
		return( vptr );
	else if ((sptr = FreeVariable) != (TCVARPTR) 0)
		FreeVariable = sptr->next;
	else if ((sptr = allocate_for_variable()) == (TCVARPTR) 0)
		return( sptr );
	sptr->hash              = vptr->hash;
	sptr->descriptor        = vptr->descriptor;
	sptr->identity          = vptr->identity;
	sptr->name              = vptr->name;
	sptr->offset            = vptr->offset;
	sptr->nature            = vptr->nature;
	sptr->access            = vptr->access;
	sptr->host              = vptr->host;
	sptr->type              = vptr->type;
	sptr->class             = vptr->class;
	sptr->parent            = vptr;
	sptr->next              = UsedVariable;
	sptr->module		= vptr->module;
	sptr->body		= vptr->body;
	UsedVariable            = sptr;
	sptr->prev              = (TCVARPTR) 0;
	sptr->firstdim          = (VPTR) 0;
	sptr->secondim          = (VPTR) 0;
	return( sptr );

}

VOID    initialise_variables()
{
	FreeVariable = (TCVARPTR) 0;
	UsedVariable = (TCVARPTR) 0;
	FreeType     = (TCTYPPTR) 0;
	return;
}


VOID    liberate_variables()
{
	TCVARPTR        vptr;
	TCTYPPTR        tptr;

	trace("liberate_variables()\n");
	release_variables();

	while ((vptr = FreeVariable) != (TCVARPTR) 0) {
		FreeVariable = vptr->next;
		liberate( vptr );
		}

	while ((tptr = FreeType) != (TCTYPPTR) 0) {
		FreeType = (TCTYPPTR) tptr->class;
		liberate( tptr );
		}

	return;
}

TCTYPPTR        copy_type( optr )
TCTYPPTR        optr;
{
	return( allocate_for_type(      optr->type,
					optr->size,
					optr->first,
					optr->second,
					optr->class      ) );
}

TCVARPTR        protect_variable( oldptr )
TCVARPTR        oldptr;
{
	TCVARPTR        newptr;
	if (( newptr = allocate_for_variable()) != (TCVARPTR) 0) {
		if ((newptr->type = copy_type( oldptr->type )) != (TCTYPPTR) 0) {
			newptr->hash       = oldptr->hash;
			newptr->descriptor = oldptr->descriptor;
			newptr->identity   = oldptr->identity;
			newptr->name       = oldptr->name;
			newptr->offset     = oldptr->offset;
			newptr->nature     = oldptr->nature;
			newptr->access     = oldptr->access;
			newptr->module     = oldptr->module;
			newptr->host       = oldptr->host;
			newptr->class      = oldptr->class;
			newptr->parent     = oldptr->parent;
			newptr->body       = oldptr->body;
			newptr->overloads  = oldptr->overloads;
			}
		}
	return( newptr );
}


TCVARPTR        copy_variable( oldptr )
TCVARPTR        oldptr;
{
	TCVARPTR        newptr;
	if ( oldptr == (TCVARPTR) 0 )
		return( oldptr );
	else if (( newptr = allocate_for_variable()) != (TCVARPTR) 0) {
		if ((newptr->type = copy_type( oldptr->type )) != (TCTYPPTR) 0) {
			newptr->hash       = oldptr->hash;
			newptr->descriptor = oldptr->descriptor;
			newptr->identity   = oldptr->identity;
			newptr->name       = oldptr->name;
			newptr->offset     = oldptr->offset;
			newptr->module     = oldptr->module;
			newptr->nature     = oldptr->nature;
			newptr->access     = oldptr->access;
			newptr->host       = oldptr->host;
			newptr->body       = oldptr->body;
			newptr->class      = oldptr->class;
			newptr->overloads  = oldptr->overloads;
			}
		}
	return( newptr );
}

WORD    trdtoi( sptr )
BPTR    sptr;
{
	WORD    result=0;
	WORD    sign=0;

	if ( *sptr == '-' ) {
		sptr++;
		sign=1;
		}

	while ( *sptr ) {
		if ((*sptr >= '0') && ( *sptr <= '9' ))
			result = ((result * 10) + (*(sptr++) - '0' ));
		else    break;
		}
	if ( sign )
		return( -result );
	else    return( result );
}

WORD    trhtoi( sptr )
BPTR    sptr;
{
	WORD    result=0;
	while ( *sptr ) {
		if ((*sptr >= '0') && ( *sptr <= '9' ))
			result = ((result << 4) | (*(sptr++) - '0' ));
		else if ((*sptr >= 'a') && ( *sptr <= 'f' ))
			result = ((result << 4) | ((*(sptr++) - 'a' ) +10));
		else if ((*sptr >= 'A') && ( *sptr <= 'F' ))
			result = ((result << 4) | ((*(sptr++) - 'F' ) +10));
		else    break;
		}
	return( result );
}

WORD    tratoi( sptr )
BPTR    sptr;
{
	WORD    result=0;
	if ( *sptr == '/' )
		return( trhtoi( (sptr + 1) ) );
	else    return( trdtoi( sptr ) );

}

WORD    store_to_constant( cptr, vptr )
TCCONPTR        cptr;
BPTR            vptr;
{
	WORD	vlen;
	WORD    l;
	WORD    xl;
	trace("store_to_constant()\n");
	if (( cptr->type->type & _TYPE_BASIC ) == _TYPE_STRING ) {
		if ( *vptr == '"' )
			vptr++;
		if (((l =  strlen( vptr )) != 0)
		&&  ( *(vptr + (l - 1)) == '"' )) {
			l--;
			*(vptr+l) = 0;
			}
		}
	else    l = (MAX_BCD_BYTES-1);
	if ((cptr->value = (BPTR) allocate((l+1))) != (BPTR) 0) {
		if (( cptr->type->type & _TYPE_BASIC ) == _TYPE_STRING )
			strcpy( cptr->value, vptr );
		else 	{
			vlen = strlen( vptr );
			if ( *vptr == '-' ) {
				if ( vlen > ((MAX_BCD_BYTES*2)))
					return( syntax_error( 14801 ) );
				}
			else if ( vlen > ((MAX_BCD_BYTES*2)-1))
				return( syntax_error( 14801 ) );

			if ((l = atobcd( vptr, vlen , cptr->value, MAX_BCD_BYTES )) > MAX_BCD_BYTES )
				return( syntax_error( 14801 ) );
			}
		}
	else    return( allocation_failure() );
	if ( OtrOption.LocalConstant & 2 )
		cptr->identity = Context->length_LCT;
	else    cptr->identity = Context->length_GCT;
	xl = cptr->length;
	if ((cptr->length = cptr->type->size = l) < xl )
		return( internal_error( 4801 ) );
	else    return(0);
}

WORD    add_data_item( vptr )
BPTR    vptr;
{
	WORD    v=0;
	WORD    l;
	WORD    t;
	BPTR    bptr;
	BYTE	buffer[32];

	if ( *vptr == '"' ) {
		t = 3;
		vptr++;
		if ((l =  strlen( vptr )) != 0)
			l--;
		*(vptr+l) = 0;
		}
	else if ( *vptr == '/' ) {
		v = convert_hex_token( vptr );
		sprintf(buffer,"%u",v);
		vptr = buffer;
		t = 2;
		l = 11;
		}
	else    {
		t = 2;
		l = 11;
		}
	if ((bptr = (BPTR) allocate((l+1))) != (BPTR) 0) {
		if (( t & 3 ) == 3 )
			strcpy( bptr, vptr );
		else    l = atobcd( vptr, strlen(vptr), bptr, 12 );
		generate_data_item( t, l, bptr );
		liberate( bptr );
		return( 0 );
		}
	else    return( allocation_failure() );

}

VOID    calculate_constant_hash( cptr )
TCCONPTR        cptr;
{
	BPTR    vptr;
	WORD    l;
	if ((( cptr->type->type & _TYPE_BASIC ) < _TYPE_NUMERIC)
	||  (( cptr->type->type & _TYPE_BASIC ) == _TYPE_INT32))
		cptr->hash = cptr->identity;
	else if ((vptr = cptr->value) != (BPTR) 0) {
		for ( l = cptr->length; l != 0; l-- )
			cptr->hash += *(vptr++);
		cptr->hash %= 0x7FFF;
		}
	return;
}

WORD    compare_constant_value(cptr, sptr)
TCCONPTR        cptr;
TCCONPTR        sptr;
{
	WORD    l;
	BPTR    vc;
	BPTR    vs;
	if ((( cptr->type->type & _TYPE_BASIC ) < _TYPE_NUMERIC)
	||  (( cptr->type->type & _TYPE_BASIC ) == _TYPE_INT32 ))
		return( VRAI );
	if (((vc = cptr->value) != (BPTR) 0)
	&&  ((vs = sptr->value) != (BPTR) 0)) {
		for ( l = cptr->length; l != 0; l-- )
			if ( *(vc++) != *(vs++) )
				break;
		if ( l == 0 )
			return( VRAI );
		}
	return( FAUX );
}

WORD    alias_constant( cptr )
TCCONPTR        cptr;
{
	TCCONPTR        sptr;
	

#ifndef	otr32
	/* don't optimise these */
	if ( cptr->redirect ) { return( VRAI );  }
#endif

	/* do not optimise out integer constants  */
	/* ------------------------------------- */
	switch(( cptr->type->type & _TYPE_BASIC )) {
		case	_TYPE_INT8	:
		case	_TYPE_INT16	:
		case	_TYPE_INT32	:
			/* keep it */
			return(VRAI);
		}

	if ( OtrOption.LocalConstant & 2 )
		sptr = Context->LCT;
	else	sptr = Context->GCT;

	/* all remaining constants should be strings */
	/* ----------------------------------------- */			
	if ( sptr != (TCCONPTR) 0) {
		do      {
			if (( cptr->hash   == sptr->hash   )
			&&  ( cptr->length == sptr->length )
			&&  (( cptr->type->type & _TYPE_BASIC) == (sptr->type->type & _TYPE_BASIC))
			&&  ( compare_constant_value( cptr, sptr ) )) {
				cptr->identity = sptr->identity;
				cptr->hash     = MOINS_UN;
				return(FAUX);
				}                               
			}
		while ((sptr = sptr->next) != (TCCONPTR) 0);
		}
	return(VRAI);
}

WORD    add_to_constant_list( cptr )
TCCONPTR        cptr;
{
	WORD    status=VRAI;

	calculate_constant_hash(cptr);

	if ( OtrOption.Aliasing )
		status = alias_constant( cptr );

	if ( OtrOption.LocalConstant & 2 ) {
		if ( Context->XLCT != (TCCONPTR) 0 )
			Context->XLCT->next = cptr;
		else    Context->LCT        = cptr;
		Context->XLCT = cptr;
		if ( status ) {
			/* identify local constants */
#ifndef	otr32
			if ( OtrOption.LocalConstant )
				cptr->type->type |= _TYPE_POINTER;
#endif
			if ( cptr->redirect ) 
				Context->length_LCT += (OtrOption.WordSize+2);
			else	{
				switch (( cptr->type->type & _TYPE_BASIC )) {
					case _TYPE_STRING : 
						Context->length_LCT += (cptr->length+1);
						break;
					case _TYPE_NUMERIC:
						Context->length_LCT += (cptr->length+2);
						break;
					}
				}
			}
		}
	else    {
		if ( Context->XCT != (TCCONPTR) 0 )
			Context->XCT->next = cptr;
		else    Context->GCT       = cptr;
		Context->XCT = cptr;
		if ( status ) {
			switch (( cptr->type->type & _TYPE_BASIC )) {
				case _TYPE_STRING : 
					Context->length_GCT += (cptr->length+1);
					break;
				case _TYPE_NUMERIC : 
					Context->length_GCT += (cptr->length+2);
					break;
				}
			}
		}
	return(0);
}


WORD    add_constant( vname, vtype, valptr )
BPTR    vname;
WORD    vtype;
BPTR    valptr;
{
	SYMBOLPTR       sptr;
	TCCONPTR        cptr;
	WORD            status;

	if ((sptr = is_symbol( vname )) != (SYMBOLPTR) 0)
		return( symbol_already_defined(vname) );
	else if ((sptr = add_symbol( vname ,(SYMBOL_CONST | (Context->scope & ISLOCAL ? SYMBOL_LOCAL : 0)) )) == (SYMBOLPTR) 0)
		return(allocation_failure());
	else if ((cptr = allocate_for_constant()) == (TCCONPTR) 0)
		return(allocation_failure());

	cptr->name = sptr->name;
	sptr->contents = (VPTR) cptr;

	if ((cptr->type = allocate_for_type( vtype, 1, 1, 1, (VPTR) 0 )) == (TCTYPPTR) 0)
		return(allocation_failure());

	switch (( vtype & _TYPE_BASIC )) {
		case _TYPE_INT32        :
			cptr->type->size = 4;
			cptr->identity = convert_numeric_token( valptr );
			break;
		case _TYPE_INT8         :
		case _TYPE_INT16        :
			cptr->type->size = ((vtype & _TYPE_BASIC) + 1);
			cptr->identity = convert_numeric_token( valptr );
			break;
		case _TYPE_NUMERIC :
		case _TYPE_STRING  :
			if ((status = store_to_constant( cptr, valptr )) != 0)
				return( status );
		}
	return( add_to_constant_list( cptr ) );

}

TCCONPTR        build_explicite_constant( vtype, valptr )
WORD            vtype;
BPTR            valptr;
{
	TCCONPTR        kptr=(TCCONPTR) 0;
	TCCONPTR        cptr=(TCCONPTR) 0;
	WORD            vlen=0;
	WORD            status;
	
	if ( vtype == _TYPE_POINTER ) {
		/* special case of request for local redirection to global */
		if (!( kptr = (TCCONPTR) valptr))
			return( kptr );
		if (!(cptr = allocate_for_constant()))
			return( cptr );
		if (!(cptr->type = allocate_for_type( kptr->type->type, kptr->type->size, 1, 1,(VPTR) 0 ))) {
			liberate_for_constant( cptr );
			return((TCCONPTR) 0);
			}
		cptr->redirect = kptr;
		if ( kptr->name )
			cptr->name = allocate_for_string( kptr->name );
		else	cptr->name = (BPTR) 0;
		switch (( cptr->type->type & _TYPE_BASIC )) {
			case _TYPE_INT32        : 
				cptr->type->size = 4;
				cptr->identity   = kptr->identity;
				break;
			case _TYPE_INT8         :
			case _TYPE_INT16        : 
				cptr->type->size = ((cptr->type->type & 3) + 1);
				cptr->identity 	 = kptr->identity;
				break;
			case _TYPE_NUMERIC      :
			case _TYPE_STRING       :
				if ((status = store_to_constant( cptr, kptr->value )) != 0)
					return( (TCCONPTR) 0 );
			}
		if ((status = add_to_constant_list( cptr )) != 0)
			return((TCCONPTR) 0);
		else	return( cptr );
		}
	else	{
		if (((vlen = strlen(valptr)) != 0 )     /* quote value quote */
		&&  ((cptr = allocate_for_constant()) != (TCCONPTR) 0)
		&&  ((cptr->type = allocate_for_type( vtype, vlen, 1, 1,(VPTR) 0 )) != (TCTYPPTR) 0)) {
			cptr->name = (BPTR) 0;
			switch (( vtype & _TYPE_BASIC )) {
				case _TYPE_INT32        : 
					cptr->type->size = 4;
					cptr->identity = tratoi( valptr ); 
					break;
				case _TYPE_INT8         :
				case _TYPE_INT16        : 
					cptr->type->size = ((vtype & 3) + 1);
					cptr->identity = tratoi( valptr ); 
					break;
				case _TYPE_NUMERIC      :
				case _TYPE_STRING       :
					if ((status = store_to_constant( cptr, valptr )) != 0)
						return( (TCCONPTR) 0 );
				}
			if ((status = add_to_constant_list( cptr )) != 0)
				return((TCCONPTR) 0);
			}
		return( cptr );
		}

}

#ifndef	otr32
WORD		is_integer_constant(  TCCONPTR cptr )
{
	switch ( cptr->type->type & _TYPE_BASIC ) {
		case	_TYPE_INT8	:
		case	_TYPE_INT16	:
		case	_TYPE_INT32	:
			return(1);
		default			:
			return(0);
		}
}

TCCONPTR	redirect_local_constant( TCCONPTR cptr )
{
	if ( cptr->type->type & _TYPE_POINTER )
		return( cptr );
	else if (!( OtrOption.LocalConstant & 2 ))
		return( cptr );
	else if (!( cptr->type ))
		return( cptr );
	else if ( is_integer_constant( cptr  ) )
		return( cptr );
	else if ( cptr->hash == MOINS_UN )
		return( cptr );
	else	return( build_explicite_constant( _TYPE_POINTER,(VPTR) cptr ) );
}
#endif

TCCONPTR        build_implicite_constant(vtype)
WORD            vtype;
{
	if ( get_token() )
		return( build_explicite_constant( vtype, TokenBuffer ) );
	else    return((TCCONPTR) 0);
}

WORD    add_external_variable( fptr, vptr )
XTFIELDPTR      fptr;
TCVARPTR        vptr;
{
	XTVARPTR        xptr;

	if ((xptr = (XTVARPTR) allocate( sizeof( struct tcode_external_variable ) )) != (XTVARPTR) 0) {
		xptr->variable = vptr;
		xptr->next = fptr->member;
		fptr->member = xptr;
		fptr->members++;
		return( 0 );
		}
	else    return( allocation_failure() );
}

static  WORD    descriptor_table_usage( vptr )
TCVARPTR        vptr;
{
	WORD    usage=0;

	if ( vptr->type->size ) {

		switch ((vptr->type->type & _TYPE_SPECIAL )) {
			case 0x8000 :
			case _TYPE_POINTER :
			case 0x0000 :
				usage = (2*OtrOption.WordSize); 
				break;
			case _TYPE_MEMBER :
			case _TYPE_MBPTR  :
			default     :
				usage = (3*OtrOption.WordSize); 
			} 

		if ((( vptr->type->type & _TYPE_BASIC) > _TYPE_INT16)
		&&  (( vptr->type->type & _TYPE_BASIC) != _TYPE_INT32))
			usage += OtrOption.WordSize;

		if ( vptr->type->type & _TYPE_FIRST ) {
			usage += OtrOption.WordSize;
			if ( vptr->type->type & _TYPE_SECOND )
				usage += OtrOption.WordSize;
			}
		return( usage );
		}

	/* Non-Structure Variables must have size */
	/* -------------------------------------- */
	else if (!( vptr->type->type & _TYPE_DEFINED ))
		return( MOINS_UN );

	/* Structure Variables may have no size */
	/* ------------------------------------ */
	else    return( 0 );

}

WORD    declare_variable( vptr )
TCVARPTR        vptr;
{
	WORD    usage;
	WORD    status;

	trace("declare_variable()\n");

	if ((usage = descriptor_table_usage( vptr )) == MOINS_UN) {
		strcpy( TokenBuffer, vptr->name );
		return( syntax_error( 666 ) );
		}
	/* Check if inside External Field */
	/* ------------------------------ */
	if ( Context->CurrentXFT != (XTFIELDPTR) 0) {
		vptr->nature = VRAI;    /* External */
		if (( Context->XDT == (TCVDTPTR) 0)
		&&  ((Context->XDT = allocate_for_vdt()) == (TCVDTPTR) 0))
			return( allocation_failure() );
		else if ((status = add_to_variable_table( Context->XDT, vptr, usage )) != 0)
			return( status );
		else if ((status = add_external_variable( Context->CurrentXFT, vptr )) != 0)
			return( status );
		}
	else    {
		if (( Context->scope & ISLOCAL)
		&&  ( Context->LDT != (TCVDTPTR) 0))
			status = add_to_variable_table( Context->LDT, vptr, usage );
		else    status = add_to_variable_table( Context->GDT, vptr, usage );
		}

/*      vptr->class = input_class();    */

	return( status );
}



TCVARPTR        next_master_object( vptr, master )
TCVARPTR        vptr;
WORD            master;
{

	while ( vptr  != (TCVARPTR) 0) {
		if ( vptr->identity == master )
			break;
		else    vptr = vptr->prev;
		}
	return( vptr );
}

TCVARPTR        locate_master_object( master )
WORD            master;
{
	TCVDTPTR        tptr;

	if (( Context->scope & ISLOCAL)
	&&  ( Context->LDT != (TCVDTPTR) 0))
		tptr = Context->LDT;
	else    tptr = Context->GDT;

	return( next_master_object( tptr->first, master ) );
}


VOID    update_field_information( vptr )
TCVARPTR        vptr;
{
	WORD    vtype;
	WORD    vone;
	WORD    vsize;
	WORD    vtwo;
	WORD    vmem;
	trace( "update_field_information()\n");

	if (((vtype = vptr->type->type) & _TYPE_POINTER) == _TYPE_POINTER)
		vmem = _KW1_PTR;
	else	vmem = _KW1_DCL;

	vsize = vptr->type->size;
	vone  = vptr->type->first;
	vtwo  = vptr->type->second;

	switch ((Context->ThisField->Field)) {
		case 0  : if ( vmem == _KW1_PTR )
				Context->ThisField->SmallField += 5;
			  else 	Context->ThisField->SmallField += (vsize * vone * vtwo );
			  if (( Context->ThisField->Host == 0 )
			  &&  ( Context->ThisField->SmallField > Context->ThisField->MaxSmallField ))
				Context->ThisField->MaxSmallField = Context->ThisField->SmallField;
			  trace("field=m\n");
			  break;
		case 64 : Context->ThisField->BigField   += (LongProduct( vsize, vone, vtwo )); 
			  if ( Context->ThisField->BigField > Context->ThisField->MaxBigField )
				Context->ThisField->MaxBigField = Context->ThisField->BigField;
			  trace("field=e\n");
			  break;
		default : Context->ThisField->FileField  += (LongProduct( vsize, vone, vtwo ));
			  trace("field=f\n");
			  break;
		}
	return;
}


/*
 *      D E C L A R E _ V A R I A B L E ()
 *      ----------------------------------
 *
 *      Performs the declaration of a variable without checking existance.
 *      
 *      Called from :
 *
 *              TRTABLES.add_variable   (having checked unicity)
 *      
 *              TRSTRUCT.declare_member (multiplicity allowed)
 *
 */

static WORD     establish_tcode_argument( vptr )
TCVARPTR        vptr;
{
	WORD    status;
	if (Context->Argument != (TCVARPTR) 0)
		return( syntax_error( 2021 ) );
	else if ((status = mark_variable( vptr )) != 0)
		return( status );
	vptr->type->type |= _TYPE_PARAMETER;
	Context->ArgumentVariable = vptr->descriptor;
	Context->Argument         = vptr;
	return( 0 );
}

WORD            variable_nature( vptr )
TCVARPTR        vptr;
{
	WORD            nature=_KW1_DCL;
	TCSTRUCTPTR     class;
	if ( vptr == (TCVARPTR) 0 )
		return( 0 );
	else if ( vptr->type->type & _TYPE_OVERLAY )
		return( _KW1_OVL );
	else if ( vptr->type->type & _TYPE_DEFINED ) {
		if (((class = (TCSTRUCTPTR)vptr->type->class) != (TCSTRUCTPTR) 0)
		&&  (!( class_enhanced_indirect( class ) ))
		&&   ( class->access & _MEMBER_OVERLAY ))
			return( _KW1_IND );
		else if ( vptr->master == 0 )
			return( _KW1_OBJ );
		nature = _KW1_OBJ;
		}

	if ((vptr->type->type & _TYPE_POINTER) == _TYPE_POINTER)
		return( _KW1_PTR );
	else if ( vptr->type->type & _TYPE_PARAMETER )
		return( _KW1_ARG );
	else    return( nature );
}

WORD    dcl_variable( vname, vtype, vsize, vone, vtwo, vmem, vnat, level, master )
BPTR    vname;
WORD    vtype;
WORD    vsize;
WORD    vone;
WORD    vtwo;
WORD    vmem;
WORD    vnat;
WORD    level;
WORD    master; /* Normally ZERO except when structure member */
{
	SYMBOLPTR       sptr;
	TCVARPTR        vptr;
	WORD            usage=0;
	WORD            status=0;
	
/*      sysprintf("%s %x %u %u %u\n",vname,vtype, vsize, vone, vtwo );     */

	if ((!(level))
	&&  ((sptr = add_symbol( vname , ((SYMBOL_VARB | (Context->scope & ISLOCAL ? SYMBOL_LOCAL : 0)) | ( vtype & (_TYPE_DEFINED | _TYPE_OVERLAY) ? SYMBOL_OBJECT : 0 ))  )) == (SYMBOLPTR) 0))
		return(allocation_failure());
	if ((vptr = allocate_for_variable()) == (TCVARPTR) 0)
		return(allocation_failure());

	if ( vmem == _KW1_PTR )
		vtype |= _TYPE_POINTER;
	else if ( vmem == _KW1_OVL )
		vtype |= _TYPE_POINTER;
	else if (( vmem == _KW1_OBJ )
	     &&  (!( level )))
		vtype |= _TYPE_POINTER; 
	else if (vmem == _KW1_CMN)
		vtype |= _TYPE_POINTER;
	else if (vmem == _KW1_IND)
		vtype |= _TYPE_POINTER;

	switch ((Context->ThisField->Field)) {
		case    0  : 
			vptr->offset = Context->ThisField->SmallField; 
			if ( Context->ThisField->Host != 0 ) {
				vptr->host   = Context->ThisField->Host;
				vtype |= _TYPE_MEMBER;
				}
			break;
		case    64 : 
			if ((vtype & _TYPE_POINTER) == _TYPE_POINTER)
				return( syntax_error( 890 ) );
			vptr->offset = Context->ThisField->BigField;    
			vtype |= _TYPE_EXTENDED;
			break;  
		default    : 
			if ((vtype & _TYPE_POINTER) == _TYPE_POINTER)
				return( syntax_error( 891 ) );
			vptr->offset = Context->ThisField->FileField;   
			vtype |= (Context->ThisField->Field << 8);
			break;
		}

	if ( Context->CurrentXFT != (XTFIELDPTR) 0 ) {
		vptr->offset = -1L;
		vptr->module = Context->CurrentXFT->module;
		}
	else	vptr->module = 0;

	if ((vptr->type = allocate_for_type( vtype, vsize, vone, vtwo,(VPTR) 0 )) == (TCTYPPTR) 0)
		return( allocation_failure() );
 
	if (!( level )) {
		sptr->contents = (VPTR) vptr;
		vptr->name     =  sptr->name;
		vptr->hash     = sptr->hash;
		}
	else    {
		vptr->name     = vname;
		vptr->hash = keyword_hash( vname );
		}

	vptr->master = master;

	if ((status = declare_variable( vptr )) != 0 )
		return( status );

	/* ARG VARIABLES are of PUBLIC SCOPE */
	/* --------------------------------- */
	if (( vmem == _KW1_ARG )
	&&  ((status = establish_tcode_argument( vptr )) != 0))
		return( status );

	/* CHECK FOR EXPLICITE PUBLIC SCOPE */
	/* -------------------------------- */
	else if ((!( OtrOption.Optimise & _OPTIMISE_TABLES ))
	     &&  ((status = mark_variable( vptr )) != 0 ))
		return( status );

	if ( Context->CurrentXFT == (XTFIELDPTR) 0 )
		update_field_information( vptr );

	if ( OtrOption.ListFlag & 1 )
		echo_declaration( vptr );       


	/* Store Nature */
	/* ------------ */
	vptr->body   = vnat;		/* DCL PROC SEGM USER CODE */
	return(status);
}

TCVARPTR        dcl_object_alias( type, n )
TCTYPPTR        type;
WORD            n;
{
	WORD            status;
	TCVARPTR        vptr;
	TCSTRUCTPTR     class;
	BYTE            vname[32];
	BPTR            nptr;
	if ( OtrOption.ListFlag & 1 ) {
		sprintf(vname,"R%u",n);
		if ((nptr = allocate_for_string( vname )) == (BPTR) 0)
			return((TCVARPTR) 0);
		}
	else    nptr = (BPTR) "methalias";
	if ((class = (TCSTRUCTPTR)type->class) != (TCSTRUCTPTR) 0)
		type->size = object_occupation( class );

	if ((status = dcl_variable(     nptr,
					type->type, 
					type->size, 
					type->first,
					type->second,
					_KW1_PTR,
					0,1,0)) != 0)
		return((TCVARPTR) 0);

	else if ( Context->scope & ISLOCAL)
		vptr = Context->LDT->variable;
	else    vptr = Context->GDT->variable;

	vptr->type->class = (VPTR) class;
	return( vptr );
}

WORD    add_variable( vname, vtype, vsize, vone, vtwo, vmem, vnat, master )
BPTR    vname;
WORD    vtype;
WORD    vsize;
WORD    vone;
WORD    vtwo;
WORD    vmem;
WORD    vnat;
WORD    master;
{
	XTFIELDPTR      xptr;
	SYMBOLPTR       sptr;
	TCVARPTR        vptr;
	WORD            status;

	/* Test if Symbol already defined : Error 81 */
	/* ----------------------------------------- */
	if ((sptr = is_symbol( vname )) != (SYMBOLPTR) 0) {
		if ((sptr->type & SYMBOL_LOCAL) == (Context->scope & ISLOCAL ? SYMBOL_LOCAL : 0 )) {
			vptr = (TCVARPTR) sptr->contents;
			
			/* Is an external field definition underway */
			/* ---------------------------------------- */
			if ((xptr = Context->CurrentXFT) != (XTFIELDPTR) 0) {
				if ( vptr->module == Context->CurrentXFT->module )
					return( symbol_already_defined(vname) );

				}
			else	{
				if (( vmem == _KW1_ARG ) &&  (vptr != (TCVARPTR) 0)) {
					if ((status = establish_tcode_argument( vptr )) != 0)
						return( status );
					else    return(0);
					}
				if ( verify_symbol_owner( sptr ) != 0 )
					return( symbol_already_defined(vname) );
				}
			}
		}

	return( dcl_variable( vname, vtype, vsize, vone, vtwo, vmem, vnat, 0, master ) );
}

static VOID     flush_used_variables( vptr,mode )
TCVARPTR        vptr;
WORD            mode;
{
	while ( vptr != (TCVARPTR) 0) {
		generate_descriptor( vptr, mode );
		vptr = vptr->link;
		}
	return;
}

static VOID     flush_all_variables( vptr, mode )
TCVARPTR        vptr;
WORD            mode;
{
	while ( vptr != (TCVARPTR) 0) {
		generate_descriptor( vptr, mode );
		vptr = vptr->prev;
		}
	return;
}

VOID    liberate_vdt( tptr )
TCVDTPTR        tptr;
{
	TCVARPTR        vptr;
	trace("liberate_vdt()\n");
	while ((vptr = tptr->first) != (TCVARPTR) 0) {
		tptr->first = vptr->prev;
		liberate_for_variable( vptr );
		}
	liberate( tptr );
	return;

}

VOID    flush_vdt_members( tptr, mode )
TCVDTPTR        tptr;
WORD            mode;
{

	if ( tptr != (TCVDTPTR) 0) {

		trace("flush_vdt_members()\n");

		/* First generate all variables */
		/* ---------------------------- */
		if ( OtrOption.Optimise & _OPTIMISE_TABLES )
			flush_used_variables( tptr->firstused, mode );
		else    flush_all_variables( tptr->first, mode );

		/* Then Liberate All variables */
		/* --------------------------- */
		if ( mode )
			liberate_vdt( tptr );

		}
	return;
}

WORD    flush_local_data()
{
	WORD    data_table_sector;

	trace("flush_local_data()\n");

	data_table_sector = current_target_sector();

	/* Ensure LOCAL  Field is Selected */
	/* ------------------------------- */
	(void) field_equals_l();

	if ( generate_data_table( Context->LDT, Context->ThisField, 1 ) != 0) {
		if ( Context->ThisField->SmallField > Context->biggest_LDS )
			Context->biggest_LDS = Context->ThisField->SmallField;
		if ( Context->LDT->descriptor > Context->biggest_LDT )
			Context->biggest_LDT = Context->LDT->descriptor;
		flush_vdt_members( Context->LDT, 1 );
		flush_sector();
		flush_debug_sector();
		}
	else    liberate_vdt( Context->LDT );

	Context->length_LVT = output_byte_count();

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	Context->LDT = (TCVDTPTR) 0;
	return( data_table_sector );
}

static VOID     flush_used_varreloc( vptr )
TCVARPTR        vptr;
{
	while ( vptr != (TCVARPTR) 0) {
		if ( vptr->relocation != (RELOCPTR) 0) {
			tcode_integer( vptr->descriptor );
			generate_code_rellocation( vptr->relocation );
			}
		vptr = vptr->link;
		}
	return;
}

static VOID     flush_all_varreloc( vptr )
TCVARPTR        vptr;
{
	while ( vptr != (TCVARPTR) 0) {
		if ( vptr->relocation != (RELOCPTR) 0) {
			tcode_integer( vptr->descriptor );
			generate_code_rellocation( vptr->relocation );
			}
		vptr = vptr->prev;
		}
	return;
}


WORD    flush_variable_rellocation()
{
	WORD            data_table_sector;
	TCVDTPTR        tptr;

	trace("flush_variable_rellocation()\n");

	use_debug_file();
	data_table_sector = current_target_sector();
	reset_byte_count();     

	if ((tptr = Context->GDT) != (TCVDTPTR) 0) {

		if ( OtrOption.Optimise & _OPTIMISE_TABLES )
			flush_used_varreloc( tptr->firstused);
		else    flush_all_varreloc( tptr->first);

		if ( output_byte_count() != 0 ) {
			tcputword( -1 );
			flush_sector();
			}
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	use_tcode_file();
	return( data_table_sector );

}

WORD    flush_global_labels()
{
	WORD    	data_table_sector;
	TCLABELPTR	lptr;

	trace("flush_global_data()\n");

	if (!( Context->number_GLT ))
		return( 0 );

	use_debug_file();
	data_table_sector = current_target_sector();
	reset_byte_count();     

	tcputword( Context->number_GLT );

	for (	lptr=Context->GLT;
		lptr != (TCLABELPTR) 0;
		lptr = lptr->next )
		generate_data_label( lptr );

	if ( output_byte_count() != 0 ) {
		tcputword( -1 );
		flush_sector();
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	use_tcode_file();

	drop_global_labels();

	return( data_table_sector );
}

WORD    flush_global_data()
{
	WORD    data_table_sector;

	trace("flush_global_data()\n");

	Context->sector_TRV = flush_variable_rellocation();

	data_table_sector = current_target_sector();

	/* Ensure GLOBAL Field is Selected */
	/* ------------------------------- */
	field_equals_g();

	if ( generate_data_table( Context->GDT, Context->ThisField, 1 ) != 0) {
		if ( Context->ThisField->MaxBigField != 0L ) {
#ifdef  DOS
			Context->paras_ETD = ((((WORD) Context->ThisField->MaxBigField) >> 4) + 1);
#else
			Context->ThisField->MaxBigField >>= 4;
			Context->ThisField->MaxBigField += 1;
			Context->paras_ETD = (WORD) Context->ThisField->MaxBigField;
#endif

#ifdef  DOS
			Context->megas_ETD = 0;
#else
			Context->ThisField->MaxBigField >>= 16;
			Context->megas_ETD = (WORD) Context->ThisField->MaxBigField;
#endif
			}
		flush_vdt_members( Context->GDT, 1 );
		flush_sector();
		flush_debug_sector();
		}
	else    liberate_vdt( Context->GDT );

	Context->length_GVT = output_byte_count();

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	Context->GDT = (TCVDTPTR) 0;
	return( data_table_sector );
}

WORD    flush_constant_rellocation()
{
	WORD            data_table_sector;
	TCCONPTR        cptr;

	trace("flush_constant_rellocation()\n");
	use_debug_file();
	data_table_sector = current_target_sector();
	reset_byte_count();     
	if ((cptr = Context->GCT) != (TCCONPTR) 0) {
		do      {
			if ( cptr->relocation != (RELOCPTR) 0 ) {
				tcode_integer( cptr->identity );
				generate_code_rellocation( cptr->relocation );
				}
			}
		while ((cptr = cptr->next) != (TCCONPTR) 0);
		if ( output_byte_count() != 0 ) {
			tcputword( -1 );
			flush_sector();
			}
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	use_tcode_file();
	return( data_table_sector );

}

WORD    flush_library_rellocation()
{
	WORD            data_table_sector;
	TCDLBPTR        lptr;

	trace("flush_library_rellocation()\n");
	use_debug_file();
	data_table_sector = current_target_sector();
	reset_byte_count();     

	if ((lptr = Context->DLT) != (TCDLBPTR) 0) {

		do      {
			if ( lptr->relocation != (RELOCPTR) 0 ) {
				generate_library_rellocation(lptr->identity, lptr->relocation );
				}
			}
		while ((lptr = lptr->next) != (TCDLBPTR) 0);

		if ( output_byte_count() != 0 ) {
			tcputword( -1 );
			flush_sector();
			}
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	use_tcode_file();
	return( data_table_sector );

}

VOID            liberate_for_constant( cptr )
TCCONPTR        cptr;
{
	if ( cptr != (TCCONPTR) 0) {
		if ( cptr->type != (TCTYPPTR) 0)
			liberate_for_type( cptr->type );
		if ( cptr->value != (BPTR) 0)
			liberate( cptr->value );
		liberate_rellocation_list( cptr->relocation );
		liberate( cptr );
		}
	return;
}

WORD    flush_global_const()
{
	WORD            data_table_sector;
	TCCONPTR        cptr;

	trace("flush_global_const()\n");
	Context->sector_TRC = flush_constant_rellocation();

	data_table_sector = current_target_sector();
	if (Context->GCT != (TCCONPTR) 0) {
#ifdef	WITH_ATOC
		if (!( OtrOption.Generate ))
			atoc_constants( Context->GCT, "GC" );
#endif
		while ((cptr = Context->GCT) != (TCCONPTR) 0) {
			Context->GCT = cptr->next;
			if ( cptr->hash != MOINS_UN )
				generate_constant( cptr );
			liberate_for_constant( cptr );
			}
		flush_sector();
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	Context->GCT = (TCCONPTR) 0;
	Context->XCT = (TCCONPTR) 0;
	return( data_table_sector );

}

WORD    flush_local_const()
{
	WORD            data_table_sector;
	TCCONPTR        cptr;

	data_table_sector = current_target_sector();

	if (Context->LCT != (TCCONPTR) 0) {
#ifdef	WITH_ATOC
		if (!( OtrOption.Generate ))
			atoc_constants( Context->LCT, "LC" );
#endif
		while ((cptr = Context->LCT) != (TCCONPTR) 0) {
			Context->LCT = cptr->next;
			if ( cptr->hash != MOINS_UN )
				generate_constant( cptr );
			liberate_for_constant( cptr );
			}
		flush_sector();
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		data_table_sector = 0;

	Context->LCT = (TCCONPTR) 0;
	Context->XLCT = (TCCONPTR) 0;
	return( data_table_sector );

}

TCMODPTR        locate_module( nptr )
BPTR            nptr;
{
	TCMODPTR        mptr;
	if ((mptr = Context->XMT) != (TCMODPTR) 0) {
		do      {
			if ( compare_tokens( nptr, mptr->name ) )
				break;
			}
		while ((mptr = mptr->next) != (TCMODPTR) 0);
		}
	return( mptr );
}

WORD    resolve_module_number( nptr, mode )
BPTR    nptr;
WORD    mode;
{
	SYMBOLPTR       sptr;
	TCMODPTR        mptr;
	if ((mptr = locate_module( nptr )) != (TCMODPTR) 0)
		return( mptr->number );
	else if ((mptr = (TCMODPTR) allocate( sizeof( struct tcode_module ) )) == (TCMODPTR) 0)
		return( allocation_failure() );
	else if ((mptr->name = (BPTR) allocate_for_token( nptr )) != (BPTR) 0) {
		if ((mptr->next = Context->XMT) == (TCMODPTR) 0)
			mptr->number = 1;
		else    mptr->number = (mptr->next->number + 1);
#ifdef ABAL33A
		mptr->mode = mode;
#endif		
		Context->XMT = mptr;
		if ((sptr = add_symbol( mptr->name, SYMBOL_MODULE )) == (SYMBOLPTR) 0)
			return( allocation_failure() );
		else	{
			sptr->contents = mptr;
			return( mptr->number );
			}
		}
	else    {
		liberate( mptr );
		return( allocation_failure() );
		}
}

TCPRCPTR        add_procedure( pptr, mode, symbol )
TCPRCPTR        pptr;
WORD            mode;
WORD            symbol;
{
	TCPRCPTR        lptr;
	SYMBOLPTR       sptr;
	WORD            status;

	if ( symbol ) {
		if ((sptr = is_symbol( pptr->name )) != (SYMBOLPTR) 0) {
			if ( sptr->type != SYMBOL_PROC ) { 
				if (!( OtrOption.DuplicateSymbols )) {
					(void) symbol_already_defined(pptr->name);
					liberate_for_procedure(pptr);
					return((TCPRCPTR) 0);
					}
				else if ((sptr = add_symbol( pptr->name , SYMBOL_PROC  )) == (SYMBOLPTR) 0) {
					(void) allocation_failure();
					liberate_for_procedure(pptr);
					return((TCPRCPTR) 0);
					}
				}
			else if ( pptr->module ) {
				if ((sptr = add_symbol( pptr->name , SYMBOL_PROC  )) == (SYMBOLPTR) 0) {
					(void) allocation_failure();
					liberate_for_procedure(pptr);
					return((TCPRCPTR) 0);
					}

				}
			}
		else if ((sptr = add_symbol( pptr->name , SYMBOL_PROC  )) == (SYMBOLPTR) 0) {
			(void) allocation_failure();
			liberate_for_procedure(pptr);
			return((TCPRCPTR) 0);
			}
		}

	if ((lptr = Context->PDT) != (TCPRCPTR) 0) {
		do      {
			if ((pptr->hash == lptr->hash)
			&&  ( compare_tokens( pptr->name, lptr->name ) )) {
				if ((status = ensure_correct_parameter_names(lptr->parameter,pptr->parameter,symbol)) != 0) {
					if (( status != 4001 ) 
					&&  ( status != 4000 )) {
						syntax_error( status );
					return((TCPRCPTR) 0);
						}
					else if (!( symbol ))
						continue;
					else	{
						syntax_error( status );
						return((TCPRCPTR) 0);
						}
					}
				liberate_for_procedure( pptr );
				if (( mode )&&  ( lptr->status )) {
					(void) symbol_already_defined(pptr->name);
					return( (TCPRCPTR) 0 );
					}
				else    return( lptr );
				}
			}
		while ((lptr = lptr->next) != (TCPRCPTR) 0);
		}

	if ( symbol ) {
		sptr->contents = (VPTR) pptr;
		sptr->module   = pptr->module;
		}

	if ( pptr->module ) {
		/* ----------------- */
		/* ETERNAL PROCEDURE */
		/* ----------------- */
		pptr->identity = MOINS_UN;
		if (!( pptr->extcall )) {
			pptr->next = Context->XPT;
			Context->XPT = pptr;
			Context->ExternalProcedures++;
			}
		}
	else    {
		/* ----------------------------- */
		/* FORWARD or INTERNAL PROCEDURE */
		/* ----------------------------- */

		pptr->identity = Context->ProcedureId;
		Context->ProcedureId += (8*OtrOption.WordSize);
		if (Context->ProcedureId < pptr->identity ) {
			(void) internal_error( 4802 );
			return((TCPRCPTR) 0);
			}

		Context->ProcedureCount++;
		if ( Context->XPDT == (TCPRCPTR) 0 )
			Context->PDT = pptr;
		else    Context->XPDT->next = pptr;
		Context->XPDT = pptr;
		}

	return( pptr );
}

WORD    establish_field_offset( vptr )
TCVARPTR        vptr;
{
	trace("establish_field_offset()\n");
	switch ((Context->ThisField->Field)) {
		case    0  : 
			vptr->offset = Context->ThisField->SmallField; 
			if ( Context->ThisField->Host != 0 ) {
				vptr->host   = Context->ThisField->Host;
				vptr->type->type |= 0xA000;
				}
			break;
		case    64 : 
			vptr->offset = Context->ThisField->BigField;    
			vptr->type->type |= 0x4000;
			break;  
		default    : 
			vptr->offset = Context->ThisField->FileField;   
			vptr->type->type |= (Context->ThisField->Field << 8);
			break;
		}
	return(0);
}

WORD    declare_procedure_parameters( vptr )
TCVARPTR        vptr;
{
	WORD            status;
	SYMBOLPTR       sptr;
	TCVARPTR        wptr;           
	TCVARPTR        pptr;           
	TCSTRUCTPTR     class;

	pptr = vptr;
	trace("declare_procedure_parameters()\n");
	while ( vptr != (TCVARPTR) 0 ) {
		if ((status = establish_field_offset(vptr)) != 0)
			return( status );

		if (( vptr->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY))
		&&  ( vptr->type->size == 0 )) {
			if ( vptr->type->type & _TYPE_OVERLAY )
				vptr->type->size = 10;
			else if ((class = (TCSTRUCTPTR) vptr->type->class) == (TCSTRUCTPTR) 0)
				return( syntax_error( 667 ) );
			else if ((vptr->type->size = parameter_occupation(class)) == 0)
				if (class->first == (TCMEMBERPTR) 0)
					return( syntax_error( 668 ) );
			}


		if ((status = declare_variable((wptr = copy_variable( vptr )) )) != 0)
			return( status );

		vptr->parent = wptr;

		if ( OtrOption.ListFlag & 1 )
			echo_declaration( wptr );       

		if ((sptr = add_symbol( wptr->name, 
	((SYMBOL_VARB | (Context->scope & ISLOCAL ? SYMBOL_LOCAL : 0))
	|( wptr->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY) ? SYMBOL_OBJECT : 0 ) )
			)) != (SYMBOLPTR) 0) {
			sptr->contents = (VPTR) wptr;
			update_field_information( wptr );
			}
		else    return( allocation_failure() );

		if ((status = mark_variable( wptr )) != 0)
			return( status );

		/* Collect Master Identity if Structure Type */
		/* ----------------------------------------- */
		if ( pptr->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY))
			vptr->identity = wptr->identity;

		vptr = vptr->next;
		}

	while ( pptr != (TCVARPTR) 0 ) {

		/* Detect and Generate Structured Parameters */
		/* ----------------------------------------- */
		if (( pptr->type->type & (_TYPE_DEFINED | _TYPE_OVERLAY))
		&&  ((status = generate_struct_parameter( pptr->parent )) != 0 ))
			return( status );
		else    pptr = pptr->next;

		}

	return( 0 );
}

WORD    reset_data_control()
{
	Context->DataCount  = 0;
	Context->DataOffset = MOINS_UN;
	return(0);
}

VOID    flush_data_control()
{
	if ( Context->DataCount ) {
		tcode_integer( 0 );
		tcode_integer( Context->DataCount );
		}
	tcode_label( Context->DataOffset );     /* READ=0 information */
	return;
}

WORD    start_procedure( pptr, mode )
TCPRCPTR        pptr;
WORD            mode;   /* VRAI : Explicite, FAUX : Implicite */
{
	WORD    status;
	trace("start_procedure()\n");

	/* EXTERNAL PROCEDURES cannot be defined ! */
	/* --------------------------------------- */
	if (( pptr->module ) || ( pptr->identity == MOINS_UN))
		return( syntax_error(669) );

	else if ((Context->LDT = allocate_for_vdt()) == (TCVDTPTR) 0)
		return( allocation_failure() );
	else if ((pptr->details = (TCBLKPTR) allocate_for_block()) == (TCBLKPTR) 0)
		return( allocation_failure() );
	reset_byte_count();
	if ( pptr->details != (TCBLKPTR) 0)
		pptr->details->code_sector = current_target_sector();
	pptr->status = VRAI;
	Context->PRC = pptr;
	if (( OtrOption.ListFlag & 1 )
	||  ( OtrOption.SourceTrace & 2 ))
		echo_procedure( pptr );
	if ( OtrOption.Verbose & 1 )
		procedure_verbose( pptr );
	start_code_block();
	start_correspondances((TCDBGPTR) & pptr->symbolic );
	reset_data_control();
	set_local_scope();
	if ((status = declare_procedure_parameters( pptr->parameter )) != 0 )
		return(status);
	if ( OtrOption.LocalConstant & 1 )
		OtrOption.LocalConstant <<= 1;
	if ((pptr->mode = mode)
	&&  ((status = local_instance_manager()) != 0))
		return( status );
	else    return((Context->CodeClosed=0));
}

TCSEGPTR        locate_internal_segment( nptr )
BPTR            nptr;
{
	TCSEGPTR        sptr;
	BPTR            token;
	trace("locate_internal_segment()\n");
	if ((sptr = Context->SDT) != (TCSEGPTR) 0) {
		if ((token = allocate_for_token( nptr )) != (BPTR) 0) {
			do      {
				if (( sptr->name != (BPTR) 0)
				&&  ( compare_tokens( token, sptr->name )))
					break;
				}
			while ((sptr = sptr->next) != (TCSEGPTR) 0);
			liberate(token);
			}
		}
	return( sptr );
}

XTSEGPTR        locate_external_segment( nptr )
BPTR            nptr;
{
	XTSEGPTR        sptr;
	BPTR            token;
	if ((sptr = Context->XTS) != (XTSEGPTR) 0) {
		if ((token = allocate_for_token( nptr )) != (BPTR) 0) {
			do      {
				if (( sptr->name != (BPTR) 0 )
				&&  ( compare_tokens( token, sptr->name ) ))
					break;
				}
			while ((sptr = sptr->next) != (XTSEGPTR) 0);
			liberate( token );
			}
		}
	return( sptr );
}

VOID    convert_external_segment( xptr, identity )
XTSEGPTR        xptr;
WORD            identity;
{
/*      sysprintf("convert_external_segment(%s from %d to %d)\n",xptr->name,xptr->number,identity); */
	xptr->number    = identity;
	return;
}

TCSEGPTR        build_segment( identity, nptr, check )
WORD    identity;
BPTR    nptr;
WORD    check;
{
	TCSEGPTR        sptr=(TCSEGPTR) 0;
	TCSEGPTR        lptr=(TCSEGPTR) 0;
	XTSEGPTR        xptr=(XTSEGPTR) 0;
	trace("build_segment()\n");

	if (( nptr != (BPTR) 0 )
	&&  (check)
	&&  ((sptr = locate_internal_segment( nptr )) != (TCSEGPTR) 0))
		return( sptr );
	else if ((sptr = allocate_for_segment()) == (TCSEGPTR) 0) {
		(void) allocation_failure();
		return( sptr );
		}

	if ( nptr == (BPTR) 0 ) {

		/* Numbered segments are handled here */
		/* ---------------------------------- */
		if ( identity == MOINS_UN ) {

			/* Incorrect Segment Number */
			/* ------------------------ */
			(void) syntax_error(670);
			liberate_for_segment( sptr );
			return( (TCSEGPTR) 0 );
			}

		else if ((sptr->name = (BPTR) allocate( 64 )) == (BPTR) 0) {
			(void) allocation_failure();
			liberate_for_segment( sptr );
			return( (TCSEGPTR) 0 );
			}
		else    sprintf(sptr->name,"%u",(sptr->identity = identity));

		}
	else    {

		/* Named Segments are handled here */
		/* ------------------------------- */ 
		if ( identity != MOINS_UN ) {

			/* Segment Number must be invalid */
			/* ------------------------------ */
			(void) syntax_error(671);
			liberate_for_segment( sptr );
			return( (TCSEGPTR) 0 );
			}

		else if ((sptr->name = allocate_for_token( nptr )) == (BPTR) 0) {
			(void) allocation_failure();
			liberate_for_segment( sptr );
			return( (TCSEGPTR) 0 );
			}

		else    {
			/* Detect if in Module */
			/* ------------------- */
			if (( context_is_module ))
				sptr->identity = identity;
			else    sptr->identity = Context->SegmentNumber++;
			}
		}

	/* Add to end of Segment Table */
	/* --------------------------- */
	sptr->offset   = (Context->SegmentCount * (12*OtrOption.WordSize));
	Context->SegmentCount++;
#ifndef	otr32
	if ( Context->SegmentCount >= 2048 ) {
		(void) internal_error( 4803 );
		return((TCSEGPTR) 0);
		}
#endif
	if ((lptr = Context->SDT) == (TCSEGPTR) 0)
		Context->SDT = sptr;
	else    {
		while (lptr->next != (TCSEGPTR) 0)
			lptr = lptr->next;
		lptr->next = sptr;
		}
	
	if (( nptr != (BPTR) 0 )
	&&  (check)
	&&  ((xptr = locate_external_segment( nptr )) != (XTSEGPTR) 0))
		convert_external_segment( xptr, sptr->identity );

	return( sptr );

}

WORD    start_segment( sptr, options, mode )
TCSEGPTR        sptr;
WORD            options;
WORD            mode;
{
	WORD    status=0;
	trace("start_segment()\n");

	reset_byte_count();

	if (( sptr->identity == 0  )
	&&  ( Context->SegmentZero ))
		return( syntax_error( 181 ) );

	sptr->options  = options;

	if ((Context->LDT = allocate_for_vdt()) == (TCVDTPTR) 0)
		return( allocation_failure() );
	else if ( sptr->details != (TCBLKPTR) 0)
		sptr->details->code_sector = current_target_sector();

	Context->CurrentSegment = sptr;

	start_code_block();
	start_correspondances((TCDBGPTR) &  sptr->symbolic );
	reset_data_control();

	if (( OtrOption.ListFlag & 1 )
	||  ( OtrOption.SourceTrace & 2 )) {
		echo_segment( sptr );
		}

	if ( OtrOption.Verbose & 1 ) {
		verbose_report_header(0);
		sysprintf("SEGMENT %u",sptr->identity);
		if ( options )
			sysprintf(", R");
		sysprintf("\n");
		}

	if ( OtrOption.LocalConstant & 1 )
		OtrOption.LocalConstant <<= 1;

	if ( sptr->identity == 0 ) 
		Context->SegmentZero = VRAI;
	else if (((sptr->mode = mode ))
	     &&  ((status = local_instance_manager()) != 0))
			return( status );
	return((Context->CodeClosed=0));
}

WORD    add_segment( identity, options, nptr, mode )
WORD    identity;
WORD    options;
BPTR    nptr;
WORD    mode;
{
	TCSEGPTR        sptr;

	trace("add_segment()\n");

	reset_byte_count();

	if ((sptr = build_segment( identity, nptr, 1 )) == (TCSEGPTR) 0)
		return( syntax_error(672) );
	else    return( start_segment( sptr, options, mode ) );

}

WORD    implicite_segment_zero()
{
	WORD    status;
	if (Context->SegmentZero)
		return( syntax_error(181) );
	else if ((status = add_segment( 0, 0, (BPTR) 0, VRAI )) != 0 )
		return( status );
	else    return( enter_segmental_translation() );
}

RELOCPTR        allocate_for_rellocation()
{
	RELOCPTR        rptr;
	trace("allocate_for_rellocation(");
	if ((rptr = (RELOCPTR) allocate( sizeof( struct tcode_rellocation ) )) != (RELOCPTR) 0) {
		rptr->sector = 0;
		rptr->length = 0;
		rptr->next   = (RELOCPTR) 0;
		}
	return( rptr );
}

WORD    add_constant_rellocation( cptr, sector, offset )
TCCONPTR        cptr;
WORD            sector;
WORD            offset;
{
	RELOCPTR        rptr;
	trace("add_constant_rellocation()\n");
	if ((rptr = allocate_for_rellocation()) == (RELOCPTR) 0)
		return( allocation_failure() );
	else    {
		rptr->sector = sector;
		rptr->length = offset;
		rptr->next = cptr->relocation;
		cptr->relocation = rptr;
		return( 0 );
		}
}

WORD    add_variable_rellocation( vptr, sector, offset )
TCVARPTR        vptr;
WORD            sector;
WORD            offset;
{
	RELOCPTR        rptr;
	trace("add_variable_rellocation()\n");
	if ((rptr = allocate_for_rellocation()) == (RELOCPTR) 0)
		return( allocation_failure() );
	else    {
		while ( vptr->parent != (TCVARPTR) 0)
			vptr = vptr->parent;
		rptr->sector = sector;
		rptr->length = offset;
		rptr->next = vptr->relocation;
		vptr->relocation = rptr;
		return( 0 );
		}
}

WORD    add_library_rellocation( lptr, sector, offset )
TCDLBPTR        lptr;
WORD            sector;
WORD            offset;
{
	RELOCPTR        rptr;
	trace("add_library_rellocation()\n");
	if ((rptr = allocate_for_rellocation()) == (RELOCPTR) 0)
		return( allocation_failure() );
	else    {
		rptr->sector = sector;
		rptr->length = offset;
		rptr->next = lptr->relocation;
		lptr->relocation = rptr;
		return( 0 );
		}
}

XREFPTR build_cross_reference( type, value, sector, offset )
WORD    type;
WORD    value;
WORD    sector;
WORD    offset;
{
	XREFPTR cptr;

	trace("allocate_for_cross_reference(");
	if ((cptr = (XREFPTR) allocate( sizeof( struct tcode_cross_reference ) )) != (XREFPTR) 0) {
		cptr->type     = type;
		cptr->identity = value;
		cptr->sector = sector;
		cptr->offset = offset;
		cptr->next = (XREFPTR) 0;
		}
	return( cptr );

}

WORD    add_procedure_crossref( type, value, sector,offset )
WORD    type;
WORD    value;
WORD    sector;
WORD    offset;
{
	XREFPTR cptr;
	trace("add_procedure_crossref("); trace( Context->PRC->name ); trace(")\n");
	if ((cptr = build_cross_reference( type, value, sector, offset )) == (XREFPTR) 0)
		return( allocation_failure() );
	cptr->next = Context->PRC->crossref;
	Context->PRC->crossref = cptr;
	return(0);
}

WORD    add_segment_crossref( type, value, sector, offset )
WORD    type;
WORD    value;
WORD    sector;
WORD    offset;
{
	XREFPTR cptr;
	trace("add_segment_crossref()\n");
	if ((cptr = build_cross_reference( type, value, sector,offset )) == (XREFPTR) 0)
		return( allocation_failure() );
	cptr->next = Context->CurrentSegment->crossref;
	Context->CurrentSegment->crossref = cptr;
	return(0);
}


WORD    rellocate_external_segment( sptr )
XTSEGPTR        sptr;
{
	RELOCPTR        rptr;

	if ( sptr->number == MOINS_UN ) {
		trace("rellocate_external_segment()\n");
		if ((rptr = allocate_for_rellocation()) == (RELOCPTR) 0)
			return( allocation_failure() );

		rptr->next = sptr->relocation;
		sptr->relocation = rptr;

		Context->RelocateSegment = sptr;
		}

	/* Information to rellocated */
	/* ------------------------- */
	return( sptr->number );

}

WORD    rellocate_external_procedure( pptr )
TCPRCPTR        pptr;
{
	RELOCPTR        rptr;
	trace("rellocate_external_procedure()\n");

	if (( pptr != (TCPRCPTR) 0)
	&&  ( pptr->identity == MOINS_UN )) {
		trace("rellocate_external_procedure()\n");
		if ((rptr = allocate_for_rellocation()) == (RELOCPTR) 0)
			return( allocation_failure() );

		rptr->next = pptr->relocation;
		pptr->relocation = rptr;

		Context->RelocateProc = pptr;
		}

	/* Information to rellocated */
	/* ------------------------- */
	return( pptr->identity );

}

WORD    resolve_external_segment( nptr )
BPTR    nptr;
{
	XTSEGPTR        sptr;

	if ((sptr = locate_external_segment( nptr )) == (XTSEGPTR) 0)
		return( 0 );
	else    return( rellocate_external_segment( sptr ) );
}

WORD    resolve_internal_segment( nptr )
BPTR    nptr;
{
	TCSEGPTR        sptr;

	if ((sptr = locate_internal_segment( nptr )) == (TCSEGPTR) 0)
		return( MOINS_UN );
	else    return( sptr->identity );
}

XTSEGPTR        build_external_segment( sptr, segid, mptr, modid, explicite )
BPTR    sptr;           /* Pointer to segment name (not allocated)      */
			/* This may not be a BPTR 0                     */
WORD    segid;          /* AS Segment Number | MOINS_UN                 */
BPTR    mptr;           /* Pointer to module  name (not allocated)      */
			/* This may be a BPTR 0 to indicate IN ANY      */
WORD    modid;          /* IN ANY := MOINS_UN                           */
WORD    explicite;      /* Indicates Explicite Creation or Implicite    */
{
	XTSEGPTR        xptr;

	if ((xptr = (XTSEGPTR) allocate( sizeof( struct external_segment ) )) != (XTSEGPTR) 0) {
		if ((xptr->name = allocate_for_token( sptr )) != (BPTR) 0) {
			xptr->number        = segid;
			xptr->module_name   = (BPTR) 0;
			xptr->module_number = modid;
			xptr->explicite     = explicite;
			xptr->identity      = MOINS_UN;
			if (( mptr == (BPTR) 0)
			||  ((xptr->module_name = allocate_for_token( mptr )) != (BPTR) 0)) {
				xptr->relocation = (RELOCPTR) 0;
				xptr->next = Context->XTS;
				Context->XTS = xptr;
				Context->ExternalSegments++;
				if ( OtrOption.ListFlag & 1 )
					echo_extern_segment( sptr );
				if ( OtrOption.Verbose & 1 ) {
					verbose_report_header(1);
					sysprintf("EXTERN SEGMENT %s \n",sptr);
					}
				return( xptr );
				}
			liberate( xptr->name );
			}
		liberate( xptr );
		}
	return((XTSEGPTR) 0);
}

/*
 *      A D D _ E X T E R N A L _ S E G M E N T ()
 *      ------------------------------------------
 *
 *      Called from :   TRPROC.translate_external_segment()
 *                      to explicitly define an external segment for the
 *                      ABAL definition syntax.
 *
 *                      TRCOBOL.translate_call()
 *                      to implicitly define an external segment for the
 *                      implicite COBOL program/segment mechanism.
 */

WORD    add_external_segment( sptr, segid, mptr, modid, explicite )
BPTR    sptr;           /* Pointer to segment name (not allocated)      */
			/* This may not be a BPTR 0                     */
WORD    segid;          /* AS Segment Number | MOINS_UN                 */
BPTR    mptr;           /* Pointer to module  name (not allocated)      */
			/* This may be a BPTR 0 to indicate IN ANY      */
WORD    modid;          /* IN ANY := MOINS_UN                           */
WORD    explicite;      /* Indicates Explicite Creation or Implicite    */
{
	XTSEGPTR        xptr;
	if ( sptr == (BPTR) 0 )
		return( syntax_error(673) );

	if ((xptr = locate_external_segment( sptr )) != (XTSEGPTR) 0) {
		if ( xptr->explicite == explicite )
			return( 0 );
		else    return( syntax_error(674) );
		}

	trace("allocate_external_segment(");

	if ((xptr = build_external_segment( sptr, segid, mptr, modid, explicite )) == (XTSEGPTR) 0)
		return( allocation_failure() );
	else    return( 0 );

}

/*
 *      Called from LDGO.SEG to find segment number of a
 *      named segment.
 *
 */

WORD    explicite_named_segment(token)
BPTR    token;
{
	TCSEGPTR        sptr;
	trace("explicite_named_segment()\n");
	if ((sptr = build_segment( MOINS_UN, token, 1)) != (TCSEGPTR) 0)
		return( sptr->identity );
	else    return( MOINS_UN );     

}

VOID    update_external_locals( sector, length )
WORD    sector;
WORD    length;
{
	if ( Context->CurrentXLT != (XTLOCALPTR) 0 ) {
		Context->CurrentXLT->sector = sector;
		Context->CurrentXLT->length = length;
		Context->CurrentXLT->next   = Context->XLT;
		Context->XLT = Context->CurrentXLT;
		Context->CurrentXLT = (XTLOCALPTR) 0;
		}
	return;
}

WORD    translate_stop()
{
	if ( Context->StopLabel == MOINS_UN )
		Context->StopLabel = new_implicite_label();
	(void) implicite_goto( Context->StopLabel );
	return( 0 );
}

static  WORD    flush_stop(destruction)
WORD    destruction;
{
	if ( Context->StopLabel != MOINS_UN ) {
		dcl_implicite_label( Context->StopLabel );
		if ( destruction != MOINS_UN ) {
			if ( destruction )
				implicite_gosub( destruction );
			else    (void) generate_gosub_destruction();
			}
		generate_stop();
		Context->StopLabel = MOINS_UN;
		}
	return( 0 );
}

WORD    segmental_closure( mode )
WORD    mode;
{
	WORD    label;
	WORD    xlabel;
	WORD    status;

	if (!( Context->CodeClosed )) {

		Context->CodeClosed = VRAI;

		xlabel = new_implicite_label();

		/* Detect and access destructor methods */
		/* ------------------------------------ */
		label = detect_destruction();

		implicite_goto( xlabel );

		/* Activate Destructor methods if any exist */
		/* ---------------------------------------- */
		if ( label != MOINS_UN )
			perform_destruction( label );
		else    status = flush_exception_catcher( xlabel );

		(void) dcl_implicite_label( xlabel );

		/* Generate Stop if Required */
		/* ------------------------- */
		if ( mode )
			generate_retseg();
		else    generate_stop();

		/* Generate Pending Routine Methods */
		/* -------------------------------- */
		status = flush_routine_methods();

		/* Generate STOP if required */
		/* ------------------------- */
		flush_stop( label );

		}

	return(0);
}

WORD    terminate_segment( identity, nptr, mode )
WORD    identity;
BPTR    nptr;
WORD    mode;
{
	WORD            status=0;

	trace("terminate_segment()\n");

	if ( Context->CurrentSegment != (TCSEGPTR) 0) {

		if ( Context->DataCount == 0 )
			segmental_closure( mode );

		/* Flush CodeBlock to Disk */
		/* ----------------------- */ 
		Context->CurrentSegment->details->code_length  = terminate_code_block();

		/* Flush Code Symbolic Information */
		/* ------------------------------- */
		terminate_correspondances( (TCDBGPTR) & Context->CurrentSegment->symbolic );

		/* Flush Local Variables */
		/* --------------------- */
		Context->CurrentSegment->details->table_sector = flush_local_data();
		Context->CurrentSegment->details->table_length = Context->length_LVT;

		update_external_locals(Context->CurrentSegment->details->table_sector,Context->CurrentSegment->details->table_length);

		/* Flush Local Constants */
		/* --------------------- */
		if ( OtrOption.LocalConstant ) {
			Context->CurrentSegment->details->const_sector = flush_local_const();
			Context->CurrentSegment->details->const_length = Context->length_LCT;
			Context->length_LCT = 0;
			}

		if ( OtrOption.Verbose & 1 )
			echo_details( Context->CurrentSegment->details );

		/* Verify Terminating Segment Identity */
		/* ----------------------------------- */
		if ( nptr == (BPTR) 0) {
			if ((Context->CurrentSegment == (TCSEGPTR) 0)
			||  (identity != Context->CurrentSegment->identity)) {
				sprintf(TokenBuffer," %u <> %u ",identity,Context->CurrentSegment->identity);
				status = syntax_error( 5558 );
				}
			}
		else    {
			if ((nptr = allocate_for_token( nptr )) == (BPTR) 0)
				status = allocation_failure();
			else    {
				if ((Context->CurrentSegment == (TCSEGPTR) 0)
				||  (Context->CurrentSegment->name == (BPTR) 0)
				||  (!( compare_tokens(Context->CurrentSegment->name, nptr) )))
					status = syntax_error( 5559 );
				liberate( nptr );
				}
			}
		/* Cancel Current Segment Status */
		/* ----------------------------- */
		if ( OtrOption.LocalConstant & 2 )
			OtrOption.LocalConstant >>= 1;
		if ( OtrOption.ListFlag & 1 )
			echo_eseg( Context->CurrentSegment );
		if ( Context->CurrentSegment->mode == VRAI )
			drop_local_instance(); 
		Context->CurrentSegment = (TCSEGPTR) 0;
		}
	return( status );
}

WORD            procedure_closure(pptr)
TCPRCPTR        pptr;
{
	WORD    label;
	WORD    xlabel=MOINS_UN;
	WORD    status;

	if (!( Context->CodeClosed )) {

		Context->CodeClosed = VRAI;

		xlabel = new_implicite_label();

		label = detect_destruction();

		implicite_goto( xlabel );

		signal_new_line(1);

		/* Activate Destructor methods if any exist */
		/* ---------------------------------------- */
		if ( label != MOINS_UN )
			status = perform_destruction( label );
		else    status = flush_exception_catcher( xlabel );

		(void) dcl_implicite_label( xlabel );

		/* Generate EXIT if required */
		/* ------------------------- */
		status = procedure_exit( pptr );

		/* Generate Pending Routine Methods */
		/* -------------------------------- */
		status += flush_routine_methods();

		/* Generate STOP if required */
		/* ------------------------- */
		flush_stop( label );

		}

	return(0);
}

WORD    start_data_control()
{
	TCPRCPTR        pptr;
	if ( Context->DataCount == 0 ) {
		if ((pptr = Context->PRC) != (TCPRCPTR) 0 ) 
			procedure_closure( pptr );
		else    segmental_closure( 0 );
		Context->DataOffset = current_tcode_offset();
		}
	return(0);
}

WORD    terminate_procedure( )
{
	WORD            status=0;
	TCPRCPTR        pptr;
	
	if ((pptr = Context->PRC) == (TCPRCPTR) 0)
		return( 0 );

	trace("terminate_procedure()\n");

	if ( Context->DataCount == 0 )
		procedure_closure( pptr );

	/* Flush Procedure Code to Disk */
	/* ---------------------------- */
	Context->PRC->details->code_length  = terminate_code_block();

	/* Flush Code Symbolic information */
	/* ------------------------------- */
	terminate_correspondances( (TCDBGPTR) & Context->PRC->symbolic );

	/* Flush LOCAL variables to DISK */
	/* ----------------------------- */
	Context->PRC->details->table_sector = flush_local_data();
	Context->PRC->details->table_length = Context->length_LVT;

	update_external_locals(Context->PRC->details->table_sector,Context->PRC->details->table_length);

	/* Flush Local Constants */
	/* --------------------- */
	if ( OtrOption.LocalConstant ) {
		Context->PRC->details->const_sector = flush_local_const();
		Context->PRC->details->const_length = Context->length_LCT;
		Context->length_LCT = 0;
		}

	if ( OtrOption.Verbose  & 1 )
		echo_details( Context->PRC->details );

	/* Cancel Current Procedure */
	/* ------------------------ */
	if ( OtrOption.LocalConstant & 2 )
		OtrOption.LocalConstant >>= 1;

	if ( OtrOption.ListFlag & 1 )
		echo_endproc();

	if ( Context->PRC->mode )
		drop_local_instance();

	Context->PRC = (TCPRCPTR) 0;
	return( status );
}

WORD    flush_libraries()
{
	WORD            data_table_sector;
	TCDLBPTR        pptr;
	
	trace("flush_libraries()\n");
	if ( Context->count_DLT != 0 ) {

		trace("flush_global_library()\n");
		Context->sector_TRL = flush_library_rellocation();

		data_table_sector = current_target_sector();

		reset_byte_count();     

		tcode_integer( Context->count_DLT );

		if ((pptr = Context->DLT) != (TCDLBPTR) 0) {
			do      {
/*                              sysprintf("Gen User Library : %u \n",pptr->identity); */
				generate_function_entry( pptr );
				}
			while ((pptr = pptr->next) != (TCDLBPTR) 0);
			Context->length_DLT = terminate_procedure_table();
			}

		/* Check for something written : otherwise cancel sector */
		/* ----------------------------------------------------- */
		if ( data_table_sector == current_target_sector() )
			return( 0 );
		else    return( data_table_sector );
		}
	else    return( 0 );
}

WORD    flush_procedures()
{
	WORD            data_table_sector;
	WORD            nombre=0;
	TCPRCPTR        pptr;

	trace("flush_procedures()\n");
	data_table_sector = current_target_sector();
	reset_byte_count();     

	if ((pptr = Context->PDT) != (TCPRCPTR) 0) {

		/* Flush Procedure Cross References */
		/* -------------------------------- */
		do      {
			if (pptr->crossref != (XREFPTR) 0) {
				if ( OtrOption.TargetTrace )
					sysprintf("Proc %s : Cross Reference Table \n",pptr->name);
				pptr->sector_XRF = generate_cross_references( pptr->crossref );
				}
			}
		while ((pptr = pptr->next) != (TCPRCPTR) 0);
		pptr = Context->PDT;
		if ( OtrOption.Symbolic )
			start_symbolic_procedures();
		do      {
			Context->PDT = pptr->next;
			generate_procedure_entry( pptr );
			nombre++;
			liberate_for_procedure( pptr );
			}
		while ((pptr = Context->PDT) != (TCPRCPTR) 0);
		Context->length_PDT = terminate_procedure_table();
		if ( OtrOption.Symbolic )
			flush_debug_sector();
		if ( OtrOption.Verbose & 1 ) {
			verbose_report_footer();
			sysprintf("Number of Procedures : %u\n",nombre);
			if ( OtrOption.Verbose & 32 )
				sysprintf("<p>");
			}
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		return( 0 );
	else    return( data_table_sector );
}

VOID    liberate_external_segment( sptr )
XTSEGPTR        sptr;
{
	if ( sptr != (XTSEGPTR) 0) {
		if ( sptr->name != (BPTR) 0 )
			liberate( sptr->name );
		if ( sptr->module_name != (BPTR) 0 )
			liberate( sptr->module_name );
		liberate_rellocation_list( sptr->relocation );  
		liberate( sptr );
		}
	return;
}

WORD    flush_external_variables()
{
	WORD            data_table_sector;

	trace("flush_external_variables()\n");
	if (Context->XDT == (TCVDTPTR) 0)
		return( 0 );

	else    {
		use_debug_file();
		data_table_sector = current_target_sector();
		reset_byte_count();     
		if ( generate_data_table( Context->XDT, (FIELDPTR) 0, 0 ) != 0) {
			flush_vdt_members( Context->XDT, 0 );
			Context->length_XDT = output_byte_count();
			flush_sector();
			}
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() ) {
		use_tcode_file();
		return( 0 );
		}
	else    {
		use_tcode_file();
		return( data_table_sector );
		}

}


WORD	count_used_field_members(XTFIELDPTR fptr )
{
	XTVARPTR        xptr;
	TCVARPTR	vptr;
	WORD		total=0;
	if ( fptr  != (XTFIELDPTR) 0 ) {
		for (	xptr=fptr->member;
			xptr != (XTVARPTR) 0;
			xptr = xptr->next ) {
			if (!( vptr = xptr->variable))
				continue;
			else if (!( vptr->relocation ))
				continue;
			else	total++;
			}
		}
	return( total );
}


WORD    flush_external_field_members(fptr)
XTFIELDPTR      fptr;
{
	TCVARPTR	vptr;
	WORD            data_table_sector;
	XTVARPTR        xptr;
	trace("flush_external_members()\n");
	if (( fptr != (XTFIELDPTR) 0)
	&&  ( fptr->members != 0 )
	&&  ((xptr = fptr->member) != (XTVARPTR) 0)) {
		use_debug_file();
		data_table_sector = current_target_sector();
		reset_byte_count();     
		tcode_integer( fptr->usedmembers );
		do      {
			if (((vptr = xptr->variable) != (TCVARPTR) 0)
			&&  (vptr->relocation != (RELOCPTR) 0))
				generate_external_member( xptr );
			}
		while ((xptr = xptr->next) != (XTVARPTR) 0);
		tcode_integer( MOINS_UN );
		flush_sector();
		fptr->sector_XVT = data_table_sector;
		use_tcode_file();
		}
	return(0);
}

WORD    flush_external_fields()
{
	WORD		used_fields=0;
	WORD            data_table_sector;
	WORD            status;
	XTFIELDPTR      fptr;
	trace("flush_external_fields()\n");
	if (((fptr = Context->XFT) == (XTFIELDPTR) 0)
	|| ( Context->ExternalFields == 0 ))
		return( 0 );
	else    {
		do      {
			if ((fptr->usedmembers = count_used_field_members( fptr )) != 0) {
				if ((status = flush_external_field_members( fptr )) != 0)
					return( status );
				else	used_fields++;
				}
			}
		while (( fptr = fptr->next) != (XTFIELDPTR) 0 );
		fptr = Context->XFT;
		use_debug_file();
		data_table_sector = current_target_sector();
		reset_byte_count();     
		if ( used_fields != 0 )
			tcode_integer( used_fields );
		do      {
			Context->XFT = fptr->next;
			if ( fptr->usedmembers != 0 ) {
				generate_external_field( fptr );        
				}
			liberate_external_field( fptr );
			}
		while ((fptr = Context->XFT) != (XTFIELDPTR) 0);
		if ( used_fields != 0 ) {
			Context->length_XFT = terminate_external_fields();
			}
		else	Context->length_XFT = 0;
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() ) {
		use_tcode_file();
		return( 0 );
		}
	else    {
		use_tcode_file();
		return( data_table_sector );
		}

}

WORD    flush_external_locals()
{
	WORD            data_table_sector;
	XTLOCALPTR      fptr;

	trace("flush_external_locals()\n");
	if (((fptr = Context->XLT) == (XTLOCALPTR) 0)
	|| ( Context->ExternalLocals == 0 ))
		return( 0 );
	else    {
		use_debug_file();
		data_table_sector = current_target_sector();
		reset_byte_count();     
		tcode_integer( Context->ExternalLocals );
		do      {
			Context->XLT = fptr->next;
			generate_external_local( fptr );        
			liberate( fptr );
			}
		while ((fptr = Context->XLT) != (XTLOCALPTR) 0);
		(void) terminate_external_fields();
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() ) {
		use_tcode_file();
		return( 0 );
		}
	else    {
		use_tcode_file();
		return( data_table_sector );
		}

}

WORD    flush_external_procedures()
{
	WORD            data_table_sector;
	TCPRCPTR        pptr;
	trace("flush_external_procedures()\n");
	if (((pptr = Context->XPT) == (TCPRCPTR) 0)
	|| ( Context->ExternalProcedures == 0 ))
		return( 0 );
	else    {
		for ( 	Context->ExternalProcedures=0,
			pptr=Context->XPT;
			pptr != (TCPRCPTR) 0;
			pptr = pptr->next ) {
			if (!( pptr->relocation ))
				continue;
			else 	Context->ExternalProcedures++;
			}
		use_debug_file();
		data_table_sector = current_target_sector();
		reset_byte_count();     
		tcode_integer( Context->ExternalProcedures );
		while ((pptr = Context->XPT) != (TCPRCPTR) 0) {
			Context->XPT = pptr->next;
			if ( pptr->relocation ) {
				generate_external_procedure( pptr );    
				}
			liberate_for_procedure( pptr );
			}
		while ((pptr = Context->XPT) != (TCPRCPTR) 0);
		Context->length_XPT = terminate_external_procedures();
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() ) {
		use_tcode_file();
		return( 0 );
		}
	else    {
		use_tcode_file();
		return( data_table_sector );
		}
	
}       

WORD    flush_external_segments()
{
	WORD            data_table_sector;
	XTSEGPTR        sptr;
	trace("flush_external_segments()\n");
	if (((sptr = Context->XTS) == (XTSEGPTR) 0)
	|| ( Context->ExternalSegments == 0 ))
		return( 0 );
	else    {
		use_debug_file();
		data_table_sector = current_target_sector();
		reset_byte_count();     
		tcode_integer( Context->ExternalSegments );
		do      {
			Context->XTS = sptr->next;
			generate_external_segment_entry( sptr );
			liberate_external_segment( sptr );
			}
		while ((sptr = Context->XTS) != (XTSEGPTR) 0);
		Context->length_XTS = terminate_external_segments();
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() ) {
		use_tcode_file();
		return( 0 );
		}
	else    {
		use_tcode_file();
		return( data_table_sector );
		}
}       

WORD    flush_segments()
{
	WORD            data_table_sector;
	WORD            nombre=0;
	TCSEGPTR        sptr;

	trace("flush_segments()\n");
	data_table_sector = current_target_sector();
	reset_byte_count();     
	if ((sptr = Context->SDT) != (TCSEGPTR) 0) {
		/* Flush Segment Cross References */
		/* ------------------------------ */
		do      {
			if (sptr->crossref != (XREFPTR) 0)
				sptr->sector_XRF = generate_cross_references( sptr->crossref );
			}
		while ((sptr = sptr->next) != (TCSEGPTR) 0);
		sptr = Context->SDT;
		if ( OtrOption.Symbolic )
			start_symbolic_segments();
		do      {
			Context->SDT = sptr->next;
			generate_segment_entry( sptr );
			nombre++;
			liberate_for_segment( sptr );
			}
		while ((sptr = Context->SDT) != (TCSEGPTR) 0);
		Context->length_SDT = terminate_segment_table();

		if ( OtrOption.Symbolic )
			flush_debug_sector();
		if ( OtrOption.Verbose & 1 ) {
			verbose_report_footer();
			sysprintf("Number of Segments   : %u\n",nombre);
			if ( OtrOption.Verbose & 32 )
				sysprintf("<p>");
			}
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		return( 0 );
	else    return( data_table_sector );
}

#ifdef ABAL33A
WORD    flush_library_modules()
{
	TCMODPTR        mptr;
	WORD            data_table_sector, i;

	trace("flush_library_modules()\n");
	if (Context->XMT != (TCMODPTR) 0 ) {
		data_table_sector = current_target_sector();
		reset_byte_count();     
		mptr = Context->XMT;
		while (mptr != (TCMODPTR) 0) {
			if (mptr->mode != 0)
				tcode_integer( mptr->number );
			mptr = mptr->next;
			}
		Context->length_LMT = terminate_library_modules();
		}

	/* Check for something written : otherwise cancel sector */
	/* ----------------------------------------------------- */
	if ( data_table_sector == current_target_sector() )
		return( 0 );
	else    return( data_table_sector );
}
#endif

WORD    flush_modules()
{
	TCMODPTR        mptr;
	WORD            target=0;
	trace("flush_modules()\n");
	if (Context->XMT != (TCMODPTR) 0 ) {
		target = next_debug_sector();
		while ((mptr = Context->XMT) != (TCMODPTR) 0) {
			Context->XMT = mptr->next;
			symbolic_module_entry( mptr->name, mptr->number );
			liberate( mptr->name );
			liberate( mptr );
			}
		flush_debug_sector();
		}
	return( target );
}

/*
 *      S T A R T _ T C O D E
 *      ---------------------
 *      This function will create the target tcode file and initialise
 *      the output module for tcode generation.
 *
 *      Called from :
 *                      TRABAL.start_program()
 *                      TRABAL.start_module()
 *                      TRABAL.start_program_object()
 *                      TRABAL.start_module_object()
 *                      TRCOBOL..start_program_or_module()
 *
 */

BPTR    context_filename()
{
	return( Context->TcodeFileName );
}

WORD    start_tcode()
{
	WORD    i;
	WORD    status;

	trace("start_tcode()\n");

	OtrOption.LabelGroup = 1;

	if ( Context->Started )
		return( syntax_error(675) );

	if ((status = initialise_output( Context->TcodeFileName )) != 0)
		return( status );

	if ( OtrOption.ListFlag & 1 ) {
		if ( context_is_module )
			echo_module();
		else    echo_program();
		}
	if ( OtrOption.Verbose & 1 ) {
		start_verbose_report(Context->TcodeFileName);
		if ( context_is_module )
			sysprintf("MODULE  ");
		else    sysprintf("PROGRAM ");
		sysprintf("\"");
		for (i=0; i < 15; i++)
			sysprintf("%c",Context->identity[i]);
		sysprintf("\"");
		if ( OtrOption.Verbose & 32 ) 
			sysprintf("</h2></table><p>");
		sysprintf("\n");
		}

	if ((Context->GDT = allocate_for_vdt()) == (TCVDTPTR) 0)
		return(leave_world());

	Context->Started = 1;
	enter_world();
	return(0);
}

WORD    tcode_garbage_collector()
{
	WORD    nombre=0;

	if ((nombre = liberate_for_input()) != 0)
		return( nombre );
	else if ((nombre = release_method_parameters()) != 0)
		return( nombre );
	else if ((nombre = release_fields()) != 0)
		return( nombre );
	else if ((nombre = release_labels()) != 0)
		return( nombre );
	else    return( 0 );
}

WORD    terminate_tcode()
{
	WORD    status=0;
	trace("terminate_tcode()\n");

	if (!( Context->Started ))
		return( 0 );

	else if ( Context->Started == 1 ) { /* TCODE Generation */
		if (((status = flush_overlay_methods()) == 0)
		&&  ((status = flush_function_methods(FAUX)) == 0)) {
			Context->sector_GCT = flush_global_const();
			Context->sector_GVT = flush_global_data();
			Context->sector_GLT = flush_global_labels();
			Context->sector_SDT = flush_segments();
			Context->sector_PDT = flush_procedures();
			Context->sector_DLT = flush_libraries();
			Context->sector_XTS = flush_external_segments();
			Context->sector_XPT = flush_external_procedures();
			Context->sector_XDT = flush_external_variables();
			Context->sector_XLT = flush_external_locals();
			Context->sector_XFT = flush_external_fields();
			if ( Context->XDT ) {
				liberate_vdt( Context->XDT );
				Context->XDT = (TCVDTPTR) 0;
				}
#ifdef ABAL33A
			/* Before flush_modules() ! */
			Context->sector_LMT   = flush_library_modules();
#endif
			Context->sector_XMT   = flush_modules();
			Context->Symbolic.sector_FileNames = flush_filenames();
#ifdef	WITH_NURAL
			Context->sector_NCT = flush_nural_classes();
#endif
			generate_tcode_header( Context->identity, Context->options);
			generate_debug_header( Context->identity, Context->options);
			}
		}

	else if ( Context->Started == 2 ) { /* APL Generation */
		Context->sector_GCT = flush_library_index_table();
		generate_tcode_header( Context->identity, Context->options);
		generate_debug_header( Context->identity, Context->options);
		OtrOption.Symbolic &= 0xFFFE; /* Do Not keep Debug File for APL */
		}
	if ( OtrOption.ListFlag & 1 )
		echo_end();
	if ( OtrOption.Verbose & 1 ) {
		if (!(OtrOption.Verbose & 32 ))
			sysprintf("END");
		else	close_verbose_report();
		sysprintf("\n");
		}
	Context->Started = 0;
	leave_world();
	return(status);
}

VOID	set_operation_pointer(void * fp)
{
	Context->operation = fp;
	return;
}

VOID    pop_operation_pointer()
{
	if ( Context->xoperindex > 0 )
		Context->operation      = Context->xoperation[--Context->xoperindex];
	else    Context->operation      = translator_startup;
	return;
}

WORD    push_operation_pointer()
{
	if ( Context->xoperindex < _MAX_NESTED_OPERATIONS ) {
		Context->xoperation[Context->xoperindex++] = Context->operation;
		return( 0 );
		}
	else    return(internal_error( 666 ));
}

WORD    previous_operation_pointer()
{
	if ( Context->xoperindex > 0 )
		return( (*Context->xoperation[(Context->xoperindex - 1)])() );
	else    return( translator_startup() );
}

WORD    flush_operation_pointers()
{
	trace("flush_operation_pointers()\n");
	while ( Context->xoperindex > 0 )
		pop_operation_pointer();
	return(0);
}

WORD    initialise_tcode_context(tcodefilename, identity )
BPTR    tcodefilename;
BPTR    identity;
{
	WORD    i;
	WORD    status;

	trace("initialise_tcode_context()\n");

	trace("allocate_tcode_context(");
	if ((Context = (TCFDTPTR) allocate( sizeof( struct tcode_control_table ))) == (TCFDTPTR) 0)
		return( MOINS_UN );
	else if ((status = initialise_auto_context()) != 0) {
		liberate( Context );
		Context = (TCFDTPTR) 0;
		return( MOINS_UN );
		}

	if ( tcodefilename ) {		
		strcpy(Context->TcodeFileName,tcodefilename);
		set_world_errorfile( Context->TcodeFileName, OtrOption.ErrorFile );
		set_world_listfile( Context->TcodeFileName, OtrOption.ListFile );
		set_world_tracefile( Context->TcodeFileName );
		}

	Context->LanguageCode   = 0x0000;
	if ( OtrOption.Symbolic & 2 )
		Context->DebugNature    = VRAI;         /* File Lines  */
	else    Context->DebugNature    = FAUX;         /* File Offset */
	Context->Semaphores     = MOINS_UN;
	Context->name           = (BPTR) 0;
	Context->options        = 0;
	Context->StopLabel      = MOINS_UN;
	Context->CodeClosed     = 1;
	Context->SegmentZero    = 0;


#ifdef ABAL33A
	if ( identity ) {
		for (i=0; i < 15; i++ )
			Context->identity[i] = identity[i];
	}
	else {
		for (i=0; i < 15; i++ )
			Context->identity[i] = ' ';
	}
#else
	for (i=0; i < 15; i++ )
		Context->identity[i] = ' ';
#endif

	Context->DclStruct        = (TCMEMBERPTR) 0;

	Context->Visibility       = _MEMBER_PUBLIC;
	Context->FieldHeap        = (FIELDNODEPTR) 0;

	Context->GLT		= (TCLABELPTR) 0;
	Context->XMT            = (TCMODPTR) 0;
	Context->GCT            = (TCCONPTR) 0;
	Context->XCT            = (TCCONPTR) 0;
	Context->LCT            = (TCCONPTR) 0;
	Context->XLCT           = (TCCONPTR) 0;
	Context->GDT            = (TCVDTPTR) 0;
	Context->XDT            = (TCVDTPTR) 0;
	Context->SDT            = (TCSEGPTR) 0;
	Context->PDT            = (TCPRCPTR) 0;
	Context->XPDT           = (TCPRCPTR) 0;
	Context->PRC            = (TCPRCPTR) 0;
	Context->LDT            = (TCVDTPTR) 0;
	Context->DLT            = (TCDLBPTR) 0;
	Context->XDLT           = (TCDLBPTR) 0;
	Context->XTS            = (XTSEGPTR) 0;
	Context->CurrentSegment = (TCSEGPTR) 0;
	Context->RelocateSegment= (XTSEGPTR) 0;
	Context->RelocateProc   = (TCPRCPTR) 0;
	Context->XPT            = (TCPRCPTR) 0;
	Context->XFT            = (XTFIELDPTR) 0;
	Context->XLT            = (XTLOCALPTR) 0;

	Context->CurrentXLT     = (XTLOCALPTR) 0;
	Context->CurrentXFT     = (XTFIELDPTR) 0;
	Context->ProcedureId    = 0;
	Context->Correspondance = FAUX;

	initialise_field((FIELDPTR) & Context->GlobalField );
	initialise_field((FIELDPTR) & Context->LocalField  );

	Context->DiezeMem       = _DIEZEMEM;
	Context->DiezeFiles     = _DIEZEFILES;
	Context->DiezeStack     = _DIEZESTACK;
	Context->DiezeHeap      = _DIEZEHEAP;

	Context->TargetVariable = (TCVARPTR) 0;
	Context->UseTarget	=0;
	Context->ArgumentVariable = 0;
	Context->Argument       = (TCVARPTR) 0;

	Context->sector_GLT	= 0;
	Context->number_GLT	= 0;
	Context->sector_GVT     = 0;
	Context->length_GVT     = 0;
	Context->length_LVT     = 0;
	Context->sector_GCT     = 0;
	Context->length_GCT     = 0;
	Context->length_LCT     = 0;
	Context->sector_SDT     = 0;
	Context->length_SDT     = 0;
	Context->sector_PDT     = 0;
	Context->length_PDT     = 0;    
	Context->sector_DLT     = 0;
	Context->length_DLT     = 0;
	Context->sector_MAP     = 0;
	Context->sector_LST     = 0;
	Context->count_DLT      = 0;
	Context->megas_ETD      = 0;
	Context->paras_ETD      = 0;
	Context->biggest_LDT    = 0;
	Context->biggest_LDS    = 0;    

	Context->sector_XTS     = 0;    /* External Segments Table      */
	Context->length_XTS     = 0;    /* External Segments Table Len  */
	Context->sector_XPT     = 0;    /* External Proc     Table      */
	Context->length_XPT     = 0;    /* External Proc     Table Len  */

	Context->sector_XDT     = 0;    /* External Variables Table     */
	Context->length_XDT     = 0;    /* External Variables Table Len */

	Context->sector_XMT     = 0;    /* External Modules Table       */
	Context->sector_XFT     = 0;    /* External Fields Table        */
	Context->length_XFT     = 0;    /* External Fields Table        */

	Context->sector_XPT     = 0;    /* External Procedures Table    */
	Context->length_XPT     = 0;    /* External Procedures Table    */

	Context->sector_XLT     = 0;    /* External Local Information   */
	Context->sector_TRV     = 0;    /* Global Variable Rellocation  */
	Context->sector_TRC     = 0;    /* Global Constant Rellocation  */
	Context->sector_TRL     = 0;    /* Global Library  Rellocation  */
	Context->sector_NCT     = 0;    /* Sector of Nural Class Table  */
	Context->length_NCT     = 0;    /* Length of Nural Class Table  */
#ifdef ABAL33A
	Context->sector_LMT     = 0;    /* Sector of Library Module Table (ABAL33A) */
	Context->length_LMT     = 0;    /* Length of Library Module Table (ABAL33A) */
#endif
	initialise_symbolic_term();

	Context->xoperindex     = 0;
	pop_operation_pointer();
	Context->ConvertType    = 2;

	Context->ExternalLocals         = 0;
	Context->ExternalProcedures     = 0;
	Context->ExternalFields         = 0;
	Context->ExternalSegments       = 0;

	Context->ProcedureCount         = 0;
	Context->SegmentCount           = 0;
	Context->SegmentNumber          = _FIRST_NAMED_SEGMENT;

	Context->Symbolic.sector_SegmentNames   = 0;
	Context->Symbolic.sector_FileNames      = 0;
	Context->Symbolic.sector_ListNames      = 0;
	Context->Symbolic.sector_ProcedureNames = 0;
	Context->Symbolic.sector_ConstantNames  = 0;

	set_global_scope();

	Context->Started        = 0;
	Context->LoadAdresse    = FAUX;
	Context->Depth          = 0;

	initialise_symbols();
	initialise_expressions();
	initialise_iterations();
	initialise_operands();
	initialise_iof();
	return(0);
}

WORD    liberate_tcode_context()
{
	if ( Context != (TCFDTPTR) 0) {

		while ( Context->FieldHeap != (FIELDNODEPTR) 0)
			field_equals_r();

		terminate_auto_context();
		liberate( Context );
		}
	return( 0 );
}

WORD	terminate_tcode_production()
{
	terminate_input();
	terminate_output();
	terminate_iof();
	return(0);
}

WORD    terminate_tcode_context()
{
	terminate_tcode_production();

	liberate_operands();
	liberate_dynamic_libraries();
	liberate_tcode_context();
	liberate_symbols();
	liberate_expressions();
	liberate_iterations();

	release_method_parameters();

	return(0);
}

/*
 *      I N I T I A L I S E _ S O U R C E _ T R A N S L A T I O N 
 *      ---------------------------------------------------------
 *
 *      Called from TRMAIN.main to initialise for source file translation
 *
 */

#ifndef	WIN32
VOID    panic_message( mptr, fptr, status )
BPTR    mptr;
BPTR    fptr;
WORD    status;
{
	sysprintf("%s ( %u ) : %s \n",mptr,status,fptr);
	return;
}
#endif

WORD    initialise_source_translation( filename )
BPTR    filename;
{
	WORD    status=0;
	BPTR    target;

	trace("initialise_source_translation()\n");

	Context = (TCFDTPTR) 0;

	if ((status = initialise_input( filename )) != 0) {
#ifdef	WIN32
		open_source_error( filename, status );
#else
		panic_message( "Cannot open source", filename, status );
#endif
		return( status );
		}

	else if ((status = initialise_tcode_context((target = (OtrOption.TargetName != (BPTR) 0 ? OtrOption.TargetName : filename )), (BPTR) 0 /* #BG240506*/)) == MOINS_UN) {
		(VOID) terminate_translation(1);
		return(2);
		}
	else    return( 0 );
}

/*
 *      I N I T I A L I S E _ R E M O T E _ T R A N S L A T I O N 
 *      ---------------------------------------------------------
 *
 *      Called from TRMAIN.main to initialise for remote line translation
 *
 */

WORD    initialise_remote_translation( filename )
BPTR    filename;
{
	WORD    status=0;
	BPTR    target;

	trace("initialise_remote_translation()\n");

	Context = (TCFDTPTR) 0;

	if ((status = initialise_tcode_context((target = (OtrOption.TargetName != (BPTR) 0 ? OtrOption.TargetName : filename )), (BPTR) 0 /* #BG240506*/)) == MOINS_UN) {
		(VOID) terminate_translation(1);
		return(2);
		}
	else    return( 0 );
}

VOID    implicite_return()
{
	generate_return();
	return;
}


WORD    generate_named_ldgoseg( token )
BPTR    token;
{
	XTSEGPTR        xptr;
	TCSEGPTR        sptr;

	if (( xptr = locate_external_segment( token )) != (XTSEGPTR) 0)
		return( ldgo_extern_segment( xptr  ) );
	else if ((sptr = build_segment( MOINS_UN, token, 1)) != (TCSEGPTR) 0)
		return( ldgo_intern_segment( sptr ) );
	else    return( allocation_failure() );
}

WORD            event_call_procedure( pptr,mode )
TCPRCPTR        pptr;
WORD            mode;   /* 0 : NORMAL, 1 EXTENDED */
{
	if (( pptr->parameter != (TCVARPTR) 0 )
	&&  ( pptr->parameter->type->size ))
		return( syntax_error( 1194 ) );
	else if ( pptr->result != (TCTYPPTR) 0)
		return( syntax_error( 1195 ) );
	else    return( generate_event_call( pptr, (TCVARPTR) 0, mode ) );
}


WORD            event_call_variable( vptr,mode )
TCVARPTR        vptr;
WORD            mode;
{
	if ((( vptr->type->type & _TYPE_BASIC ) != _TYPE_STRING)
	||  ( vptr->type->size != 5 ))
		return( syntax_error( 1196 ) );
	else if ( vptr->type->type & (_TYPE_FIRST | _TYPE_SECOND))
		return( syntax_error( 1197 ) );
	else    return( generate_event_call( (TCPRCPTR) 0, vptr, mode ) );
}

#endif  /* _TRTABLES_C */
	/* ----------- */

