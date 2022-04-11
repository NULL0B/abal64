#define	DEBUG
#ifndef	_TRGENC_C
#define	_TRGENC_C

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


#define	_C_ARG_LIMIT	8
#define	_tc_NEWLINE 0x777

WORD		LocalDataTableCount=0;
BPTR		DataTableName=(BPTR) 0;
WORD		DataTableType=0;
WORD		RtlHotkeys=0;
HOTPTR		RtlHotHead=(HOTPTR) 0;
WORD		RtlFormatCount=0;
WORD		RtlRegisters=0;
WORD		RtlSegmentCount=0;
WORD		RtlGdsInit=0;
WORD		RtlDataItems=0;
WORD		RtlDataUsed=0;
WORD		RtlResumeUsed=0;
WORD		NewLineFlag = _tc_NEWLINE;
WORD		NewLineStatus = _tc_NEWLINE;
WORD		RtlNewLine=0;
WORD		RtlOfCounter=0;
WORD		RtlOfControl=0;
WORD		RtlCodeSection=0;
WORD		UseRtlAbalWord=0;
static WORD	RtlParameters=0;
static WORD	RtlHuge=0;
static BPTR	RtlHugePrefix=(BPTR) 0;
BYTE		RtlGdtName[24];

BPTR	allocate_for_string( BPTR );
EXTERN	BYTE	TokenBuffer[];

#ifndef	UNIX
static	VOID	generate_output_prefix( WORD );
#else
static	VOID	generate_output_prefix();
#endif

#include "trtnode.c"

TNODEPTR	RtlSelectHeap=(TNODEPTR) 0;

#define ENCODE 	1
#define	DECODE	0
BPTR	abal_crypt( pkey , sptr , slen ,mode)
WORD16	pkey;
BPTR	sptr;
WORD16	slen;
WORD16	mode;
{
	BPTR	rptr;
	BYTE	exkm[16][16];
	short int kdex,kdey;
	WORD	rotor;
	WORD	cmpt;
	WORD	x,y;
	WORD	phase;
	rptr = sptr; cmpt = 0;
	for (x = 0; x < 16 ; x++) {
		for ( y =0; y < 16; y++ ) {
			exkm[x][y] = (BYTE) cmpt; cmpt++;
			}
		}
	rotor = 1; phase = pkey & 0x0007;
	while ( slen > 0 ) {
		if ( mode == ENCODE ) { 
			kdex = ((WORD) *sptr) / 16;
			kdey = ((WORD) *sptr) % 16;
			switch ( phase ) {
				case 1 : kdey++;
				case 0 : kdex--; break;
				case 2 : kdey++; break;
				case 3 : kdey++; 
				case 4 : kdex++; break;
				case 5 : kdex++;
				case 6 : kdey--; break;
				case 7 : kdex--; kdey--;
				}
			}
		else	{
			for ( x = 0; x < 16; x++ ) {
				for ( y = 0; y < 16; y++ ) {
					if ( exkm[x][y] == *sptr ) {
						kdex = x; x = 16;
						kdey = y; y = 16;
						}
					}
				}
			switch ( phase ) {
				case 1 : kdey--;
				case 0 : kdex++; break;
				case 2 : kdey--; break;
				case 3 : kdey--; 
				case 4 : kdex--; break;
				case 5 : kdex--;
				case 6 : kdey++; break;
				case 7 : kdex++; kdey++;
				}
			}
		if ( kdex > 15 ) { kdex = 0; }
		if ( kdey > 15 ) { kdey = 0; }
		if ( kdex < 0 ) { kdex = 15; }
		if ( kdey < 0 ) { kdey = 15; }
		if ((pkey & rotor ) != 0 ) {
			phase++;
			if ( phase > 7 ) { phase = 0; }
			}
		rotor <<= 1;
		if ( rotor == 0 ) { rotor = 1; }
		*(sptr++) = exkm [ kdex ][ kdey ]; slen--;
		}
 	return(rptr);
}

WORD	tcode_labels() { return(FAUX); }
VOID	tcode_string( sptr )
BPTR	sptr;
{
	return;
}


VOID	set_rtl_huge( eptr )
BPTR	eptr;
{
	RtlHuge = 1;
	RtlHugePrefix = eptr;
	return;
}			

BPTR	host_code_name()
{
	if ( Context->PRC != (TCPRCPTR) 0)
		return( Context->PRC->name );
	else if ( Context->CurrentSegment != (TCSEGPTR) 0)
		return( Context->CurrentSegment->name );
	else	return((BPTR) 0 );
}

BPTR	HostCodeName()
{
	BPTR	tptr=(BPTR) 0;
	BPTR	nptr;
	if (((nptr = host_code_name()) != (BPTR) 0)
	&&  ((tptr = allocate_for_tnode(strlen(nptr)+5)) != (BPTR) 0))
		sprintf(tptr,"HCN$%s",nptr);
	return( tptr );
}
	
static	VOID	generate_hash_ifdef( optr, symbol )
CFILEPTR	optr;
BPTR		symbol;
{
	fprintf(optr->handle,"\n#ifdef %s\n",symbol);
	return;
}

static	VOID	generate_hash_ifndef( optr, symbol )
CFILEPTR	optr;
BPTR		symbol;
{
	fprintf(optr->handle,"\n#ifndef %s\n",symbol);
	return;
}

static	VOID	generate_hash_define( optr, symbol, value )
CFILEPTR	optr;
BPTR		symbol;
BPTR		value;
{
	fprintf(optr->handle,"\n#define %s %s\n",symbol,value);
	return;
}

static	VOID	generate_hash_else( optr )
CFILEPTR	optr;
{
	fprintf(optr->handle,"\n#else\n");
	return;
}

static	VOID	generate_hash_endif( optr )
CFILEPTR	optr;
{
	fprintf(optr->handle,"\n#endif\n");
	return;
}

static	VOID	generate_hash_include( optr, filename )
CFILEPTR	optr;
BPTR		filename;
{
	if ( *filename == '<' )
		fprintf(optr->handle,"#include %s\n",filename);
	else	fprintf(optr->handle,"#include %c%s%c\n",0x0022,filename,0x0022);
	return;
}

static	WORD	generate_file_exclusion( optr, extension )
CFILEPTR	optr;
BPTR		extension;
{
	BYTE	nom[32];
	extension++;
	fn_parser( optr->name, nom, 0x0008 );
	fprintf(optr->handle,"#ifndef _%s_%s \n",nom,extension);
	fprintf(optr->handle,"#define _%s_%s \n\n",nom,extension);
	return( 0 );
}

static	WORD	CreateOutputFile( optr, filename, extension, mode )
CFILEPTR	optr;
BPTR		filename;
BPTR		extension;
WORD		mode;
{
	BPTR	buffer;
	WORD	status;
	if ((buffer = allocate( 256 )) == (BPTR) 0)
		status = allocation_failure();
	else	{
		fn_parser( filename, buffer, 0x000F );
		strcat( buffer,extension);
		if (( optr->name = allocate_for_string( buffer )) != (BPTR) 0) {
			if ((optr->handle = fopen( optr->name, "w")) != (FILEPTR) 0) {
				if ( mode ) {
					if ( mode == 1 )
#ifdef	UNIX
						fprintf(MakeFile->handle,"%s.o: %s.c\n",filename,filename);
#else
						fprintf(MakeFile->handle,"%s.o: %s.c\n",filename,filename);
#endif
					status = generate_file_exclusion( optr, extension );
					}
				else	status = 0;
				}
			else	status = 44;
			}
		else	status = allocation_failure();
		liberate( buffer );
		}
	return ( status );
}

static	VOID	CloseOutputFile( optr,mode )
CFILEPTR	optr;
WORD		mode;
{
	if ( optr->name != (BPTR) 0 ) {
		if ( optr->handle != (FILEPTR) 0) {
			if ( mode )
				generate_hash_endif( optr );
			fclose( optr->handle );
			optr->handle = (FILEPTR) 0;
			}
		liberate( optr->name );
		optr->name = (BPTR) 0;
		}
	return;
}

VOID	flush_indentation( optr )
CFILEPTR	optr;
{
	WORD	i;
	for ( i = 0; i < optr->indentation; i++ )
		fprintf(optr->handle,"\t");
	return;
}

VOID		generate_indentation( optr )
CFILEPTR	optr;
{
	WORD	i;
	flush_indentation( optr );
	if (( RtlCodeSection )
	&&  ( RtlNewLine )) {
		fprintf(Output->handle,"%s$RtlNewLine;\n",HostCodeName());
		flush_indentation( optr );
		RtlNewLine = FAUX;
		}
	return;
}

VOID	generate_open_accolade(optr)
CFILEPTR	optr;
{
	fprintf( optr->handle,"{\n");
	optr->indentation++;
	return;
}

VOID	open_accolade(optr)
CFILEPTR	optr;
{
	generate_indentation( optr );
	generate_open_accolade(optr);
	return;
}

static	VOID	generate_close_accolade(optr)
CFILEPTR	optr;
{
	fprintf( optr->handle,"}\n");
	if ( optr->indentation > 0 )
		optr->indentation--;
	return;
}

VOID		close_accolade(optr)
CFILEPTR	optr;
{
	generate_indentation( optr );
	generate_close_accolade( optr );
	return;
}

static	VOID	generate_rtl_context()
{
	generate_indentation( Output );
	fprintf(Output->handle,"WORD _rtl_status=0;\n");
	generate_indentation( Output );
	fprintf(Output->handle,"struct _rtl_error_manager RtlError;\n");
	generate_indentation( Output );
	fprintf(Output->handle,"struct _rtl_gosub_manager RtlGosub;\n");
	LocalDataTableCount++;
	if ( Context->PRC != (TCPRCPTR) 0) {
		generate_indentation( Output );
		fprintf(Output->handle,"%s_DataManager;\n",HostCodeName());
		}
	RtlDataItems=0;
	RtlDataUsed=0;
	RtlResumeUsed=0;
	return;
}

static	VOID	open_data_items()
{
	if ( RtlDataItems == 0 ) {
		RtlDataItems++;
		fprintf(Footer->handle,"static BPTR %s_RTL$DT[ %s_RTL_DATA_ITEMS ] = {\n",HostCodeName(),HostCodeName());
		}
	return;
}

BPTR	RtlDataManagerName()
{
	BPTR	tptr=(BPTR) 0;
	BPTR	nptr;
	if (((nptr = HostCodeName()) != (BPTR) 0)
	&&  ((tptr = allocate_for_tnode( strlen(nptr)+10 )) != (BPTR) 0))
		sprintf(tptr,"& %s_RTL$DM",HostCodeName());
	RtlDataUsed++;
	return( tptr );
}

	
static	VOID	close_data_items()
{
	BPTR	nptr;
	if (( nptr = HostCodeName()) == (BPTR) 0 )
		return;
	
	if ( RtlDataItems ) {
		fprintf(Footer->handle,"\n\t};\n");
		fprintf(Header->handle,"#define %s_RTL_DATA_ITEMS %u\n",nptr,RtlDataItems);
		fprintf(Footer->handle,"#define %s_DataManager struct _artl_data_control %s_RTL$DM\n",nptr,nptr);
		fprintf(Footer->handle,"#define %s_DataManagerInit rtl_data_init( & %s_RTL$DM, %s_RTL_DATA_ITEMS, %s_RTL$DT )\n",nptr,nptr,nptr,nptr);
		}
	else	{
		if ( RtlDataUsed )
			(void) expected_keyword("DATA");
		fprintf(Footer->handle,"#define %s_DataManager BYTE %s_RTL$DM\n",nptr,nptr);
		fprintf(Footer->handle,"#define %s_DataManagerInit\n",nptr);
		}
	RtlDataUsed  = 0;
	RtlDataItems = 0;
	return;
}

VOID	rtl_function_interface( fptr )
TCDLFPTR	fptr;
{
	TCVARPTR	vptr;
	WORD		nombre=0;

	fprintf(Footer->handle,"WORD %s(",fptr->name);

	if ((vptr = fptr->parameter) != (TCVARPTR) 0) {
		while ( 1 ) {
			switch ((vptr->type->type & 0x000F)) {
				case	0	:
				case	1	:
					fprintf(Footer->handle,"arg$val%u",nombre++);
					break;
				case	8	:
				case	9	:
					fprintf(Footer->handle,"arg$ptr%u",nombre++);
					break;
				default		:
					fprintf(Footer->handle,"arg$ptr%u,arg$len%u",nombre, nombre);
					nombre++;
					break;
					fprintf(Footer->handle,"BPTR,WORD");
					break;
				}
			if ((vptr = vptr->prev) != (TCVARPTR) 0)
				fprintf(Footer->handle,", ");
			else	break;	
			}
		}
	fprintf(Footer->handle,")\n"); 
	nombre = 0;
	if ((vptr = fptr->parameter) != (TCVARPTR) 0) {
		while ( 1 ) {
			switch ((vptr->type->type & 0x000F)) {
				case	0	:
				case	1	:
					fprintf(Footer->handle,"WORD\targ$val%u;\n",nombre++);
					break;
				case	8	:
				case	9	:
					fprintf(Footer->handle,"BPTR\targ$ptr%u;\n",nombre++);
					break;
				default		:
					fprintf(Footer->handle,"BPTR\targ$ptr%u;\nWORD\targ$len%u;\n",nombre, nombre);
					nombre++;
					break;
				}
			if ((vptr = vptr->prev) == (TCVARPTR) 0)
				break;	
			}
		}
	open_accolade( Footer );
	nombre = 0;
	if ((vptr = fptr->parameter) != (TCVARPTR) 0) {
		while ( 1 ) {
			switch ((vptr->type->type & 0x000F)) {
				case	0	:
					generate_indentation( Footer );
					fprintf(Footer->handle,"rtl_dll_int8(arg$val%u,%u);\n",nombre,nombre);
					nombre++;
					break;
				case	8	:
					generate_indentation( Footer );
					fprintf(Footer->handle,"rtl_dll_ptr8(arg$ptr%u,%u);\n",nombre,nombre);
					nombre++;
					break;
				case	1	:
					generate_indentation( Footer );
					fprintf(Footer->handle,"rtl_dll_int16(arg$val%u,%u);\n",nombre,nombre);
					nombre++;
					break;
				case	9	:
					generate_indentation( Footer );
					fprintf(Footer->handle,"rtl_dll_ptr16(arg$ptr%u,%u);\n",nombre,nombre);
					nombre++;
					break;
				case	3	:
				case	0x000B	:
					generate_indentation( Footer );
					fprintf(Footer->handle,"rtl_dll_string(arg$ptr%u,arg$len%u,%u);\n",nombre, nombre, nombre);
					nombre++;
					break;
				case	2	:
				case	0x000A	:
					generate_indentation( Footer );
					fprintf(Footer->handle,"rtl_dll_bcd(arg$ptr%u,arg$len%u,%u);\n",nombre, nombre, nombre);
					nombre++;
					break;
				}
			if ((vptr = vptr->prev) == (TCVARPTR) 0)
				break;	
			}
		}
	
	generate_indentation( Footer );
	fprintf(Footer->handle,"return( rtl_dll_call(%u,%u,%u,%c%s%c) );\n",fptr->library->identity,fptr->identity,nombre,0x0022,fptr->library->name,0x0022);
	Footer->indentation = 0;
	close_accolade( Footer );
}


VOID	rtl_function_prototype( fptr )
TCDLFPTR	fptr;
{
	TCVARPTR	vptr;
	WORD		mode=1;
	BPTR		wptr;

	if ((wptr = fptr->library->name) != (BPTR) 0) {
		if ( *wptr == '!' )
			mode = 1;
		else	mode = 0;
		}

	if ( mode )
		fprintf(Header->handle,"EXTERN WORD %s(",fptr->name );
	else	fprintf(Header->handle,"WORD %s(",fptr->name);
	if ((vptr = fptr->parameter) != (TCVARPTR) 0) {
		while ( 1 ) {
			switch ((vptr->type->type & 0x000F)) {
				case	0	:
				case	1	:
					fprintf(Header->handle,"WORD");
					break;
				case	8	:
				case	9	:
					fprintf(Header->handle,"BPTR");
					break;
				default		:
					fprintf(Header->handle,"BPTR,WORD");
					break;
				}
			if ((vptr = vptr->prev) != (TCVARPTR) 0)
				fprintf(Header->handle,", ");
			else	break;	
			}
		}
	fprintf(Header->handle,");\n");
	if (!( mode ))
		rtl_function_interface( fptr );
	return;

}

static	WORD	procedure_parameter_count( vptr )
TCVARPTR	vptr;
{
	WORD	nombre=0;
	while ( vptr != (TCVARPTR) 0 ) {
		nombre++;
		vptr = vptr->next;
		}
	return( nombre );
}


static	VOID	rtl_procedure_prototype( pptr, mode )
TCPRCPTR	pptr;
WORD		mode;	/* 1 ==> Extern , 0 ==> Internal */
{
	TCVARPTR	vptr;
	WORD		nombre=0;
	if ( mode )
		fprintf(Footer->handle,"EXTERN WORD %s(",pptr->name );
	else	fprintf(Footer->handle,"WORD %s(",pptr->name);
	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		if ((nombre = procedure_parameter_count( vptr )) < _C_ARG_LIMIT) {
			while ( 1 ) {
				vptr->identity |= ISLOCAL;
				fprintf(Footer->handle,"BPTR,WORD");
				if ((vptr = vptr->next) != (TCVARPTR) 0)
					fprintf(Footer->handle,", ");
				else	break;	
				}
			}
		}
	fprintf(Footer->handle,");\n");
	fprintf(Footer->handle,"#define stub%u %s\n",pptr->identity,pptr->name);
	return;
}

VOID	generate_external_procedure( TCPRCPTR pptr) 
{ 
	rtl_procedure_prototype( pptr, 1 );	
	return;
}

static	VOID	rtl_procedure_definition( pptr )
TCPRCPTR	pptr;
{
	TCVARPTR	vptr;
	WORD		nombre=0;
	fprintf(Output->handle,"WORD %s(",pptr->name);
	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		if ((nombre = procedure_parameter_count( vptr )) < _C_ARG_LIMIT) {
			while ( 1 ) {
				fprintf(Output->handle,"p$%s,l$%s",vptr->name,vptr->name);
				if ((vptr = vptr->next) != (TCVARPTR) 0)
					fprintf(Output->handle,", ");
				else	break;	
				}
			}
		}
	fprintf(Output->handle,")\n");
	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		if ( nombre < _C_ARG_LIMIT ) {
			do	{
				fprintf(Output->handle,"BPTR p$%s;\n",vptr->name);
				fprintf(Output->handle,"WORD l$%s;\n",vptr->name);
				}
			while (( vptr = vptr->next) != (TCVARPTR) 0);
			}
		}
	return;
}

static	VOID	output_indentation()
{
	generate_indentation( Output );
	return;
}

static	BPTR	remove_indirection( vptr, type )
BPTR	vptr;
WORD	type;
{
	BPTR	tptr="(BPTR) 0";
	WORD	l;
	if ( type == 0 ) {	/* Type # */
		if (( *vptr == '*' )
		&&  ( *(vptr+1) == '(')) {
			if ((tptr = allocate_for_tnode((l = strlen(vptr))+1)) != (BPTR) 0) {
				strcpy( tptr, vptr );
				*( tptr + l - 1 ) = 0;
				tptr += 2;
				}
			}
		}
	else	{		/* Type % */
		if (( *vptr == '(' )
		&&  ( *(vptr+1) == 'g')
		&&  ( *(vptr+2) == 'e')
		&&  ( *(vptr+3) == 't')
		&&  ( *(vptr+4) == 'a')) {
			if ((tptr = allocate_for_tnode((l = strlen(vptr))+1)) != (BPTR) 0) {
				strcpy( tptr, vptr );
				*( tptr + l - 2 ) = 0;
				tptr += 2;
				while ( *(tptr++) != '(' );
				}
			}
		}
	return( tptr );
}

static WORD	rtl_transmit_structure( pptr, tptr )
TCPRCPTR	pptr;
TNODEPTR	tptr;
{

	return( not_yet_available() );
}

static WORD	rtl_retransmit_structure( pptr, tptr )
TCPRCPTR	pptr;
TNODEPTR	tptr;
{

	return( not_yet_available() );
}

static WORD	rtl_receive_structure( pptr, tptr )
TCPRCPTR	pptr;
TNODEPTR	tptr;
{
	TCVARPTR	vptr;
	WORD		nombre=0;
	return( not_yet_available() );
#ifdef	MULTI_ARGS
	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		do	{
			if (( vptr->type->type & _TYPE_POINTER) == _TYPE_POINTER ) {
				output_indentation();
				output_indentation();
				fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { putpointer(%s,p$%s); }\n",vptr->name,generate_pointer_adresse(vptr),vptr->name);
				output_indentation();
				fprintf(Output->handle,	"else { clf_forget(%s,0,0,0); }\n",generate_pointer_adresse(vptr));
				}
			else switch ((vptr->type->type & 3)) {
				case	0 :
					output_indentation();
					fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { *(%s) = *(p$%s); }\n",vptr->name,generate_variable_name(vptr),vptr->name);
					output_indentation();
					fprintf(Output->handle,	"else { *(%s) = l$%s; }\n",generate_variable_name(vptr),vptr->name);
					break;
				case	1 :
					output_indentation();
					fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { putabalword(%s,getabalword(p$%s)); }\n",vptr->name,generate_variable_name(vptr),vptr->name);
					output_indentation();
					fprintf(Output->handle,	"else { putabalword(%s,l$%s); }\n",generate_variable_name(vptr),vptr->name);
					break;
				case	2 :
					output_indentation();
					fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { bcd_copy( p$%s,(l$%s & 0x7FFF),%s); }\n",vptr->name,vptr->name,vptr->name,variable_svalue(vptr));
					break;
				case	3 :
					output_indentation();
					fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { string_copy( p$%s,(l$%s & 0x7FFF),%s); }\n",vptr->name,vptr->name,vptr->name,variable_svalue(vptr));
					break;
				}
			}
		while (( vptr = vptr->next) != (TCVARPTR) 0);
		}
	return(0);
#endif
}

static WORD	rtl_procedure_transmission( pptr, tptr )
TCPRCPTR	pptr;
TNODEPTR	tptr;
{
	WORD		c;
	BPTR		wptr;
	TCVARPTR	vptr;
	TNODEPTR	xptr;
	WORD		nombre=0;

	if ((nombre = procedure_parameter_count( pptr->parameter )) >= _C_ARG_LIMIT)
		return( rtl_transmit_structure( pptr, tptr ) );

	output_indentation();
	fprintf(Output->handle,"if ((_rtl_status = %s(",pptr->name);
	if ( tptr != (TNODEPTR) 0 ) {
		vptr = pptr->parameter;
		while (1) {
			wptr = tptr->value;
			if ((c = *wptr) == '?')
				wptr++;
			switch((vptr->type->type & 3)) {
				case	0	:
					if ((( vptr->type->type & _TYPE_POINTER) == _TYPE_POINTER )
					||   ( c == '?' ))
					 	fprintf(Output->handle,"%s,%s",remove_indirection(wptr,0),wptr);
					else 	fprintf(Output->handle,"(BPTR) 0,%s",wptr);
					break;
				case	1	:
					if ((( vptr->type->type & _TYPE_POINTER) == _TYPE_POINTER )
					||   ( c == '?' ))
					 	fprintf(Output->handle,"%s,%s",remove_indirection(wptr,1),wptr);
					else 	fprintf(Output->handle,"(BPTR) 0,%s",wptr);
					break;
				case	2	:
				case	3	:
					if ( c == '?' )
						fprintf(Output->handle,"%s | 0x8000",wptr);
					else	fprintf(Output->handle,"%s",wptr);
					break;
				}
			xptr = tptr->next;
			release_tnode( tptr );
			vptr = vptr->next;
			if ((tptr = xptr) == (TNODEPTR) 0)
				break;
			else	fprintf(Output->handle,", ");
			}
		}
	fprintf(Output->handle,")) != 0)");
	generate_open_accolade(Output);
	output_indentation();
	fprintf(Output->handle,"%s;\n",_RTL_RAISE_ERROR);
	close_accolade(Output);
	return(0);
}

static	WORD	rtl_procedure_reception( pptr )
TCPRCPTR	pptr;
{
	TCVARPTR	vptr;
	WORD		nombre=0;

	if ((nombre = procedure_parameter_count( pptr->parameter )) >= _C_ARG_LIMIT)
		return( rtl_receive_structure( pptr ) );

	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		do	{
			if (( vptr->type->type & _TYPE_POINTER) == _TYPE_POINTER ) {
output_indentation();
output_indentation();
fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { putpointer(%s,p$%s); }\n",vptr->name,generate_pointer_adresse(vptr),vptr->name);
output_indentation();
fprintf(Output->handle,	"else { clf_forget(%s,0,0,0); }\n",generate_pointer_adresse(vptr));

				}
			else
			switch ((vptr->type->type & 3)) {
				case	0 :
output_indentation();
fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { *(%s) = *(p$%s); }\n",vptr->name,generate_variable_name(vptr),vptr->name);
output_indentation();
fprintf(Output->handle,	"else { *(%s) = l$%s; }\n",generate_variable_name(vptr),vptr->name);
break;
				case	1 :
output_indentation();
fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { putabalword(%s,getabalword(p$%s)); }\n",vptr->name,generate_variable_name(vptr),vptr->name);
output_indentation();
fprintf(Output->handle,	"else { putabalword(%s,l$%s); }\n",generate_variable_name(vptr),vptr->name);
break;
				case	2 :
output_indentation();
fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { bcd_copy( p$%s,(l$%s & 0x7FFF),%s); }\n",vptr->name,vptr->name,vptr->name,variable_svalue(vptr));
break;
				case	3 :
output_indentation();
fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { string_copy( p$%s,(l$%s & 0x7FFF),%s); }\n",vptr->name,vptr->name,vptr->name,variable_svalue(vptr));
break;
				}
			}
		while (( vptr = vptr->next) != (TCVARPTR) 0);
		}
	return(0);
}

static	WORD	rtl_procedure_retransmission( pptr )
TCPRCPTR	pptr;
{
	TCVARPTR	vptr;
	WORD		dodo=0;
	WORD		nombre=0;

	if ((nombre = procedure_parameter_count( pptr->parameter )) >= _C_ARG_LIMIT)
		return( rtl_retransmit_structure( pptr ) );

	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		do	{
			if (( vptr->type->type & _TYPE_POINTER) == _TYPE_POINTER )
				dodo++;
			else
			switch ((vptr->type->type & 3)) {
				case	0 :
output_indentation();
fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { *(p$%s) = *(%s); }\n",vptr->name,vptr->name,generate_variable_name(vptr));
break;
				case	1 :
output_indentation();
fprintf(Output->handle,	"if ( p$%s != (BPTR) 0 ) { putabalword(p$%s,getabalword(%s)); }\n",vptr->name,vptr->name,generate_variable_name(vptr));
break;
				case	2 :
output_indentation();
fprintf(Output->handle,	"if (( p$%s != (BPTR) 0 ) && (l$%s & 0x8000)) { bcd_copy(%s, p$%s,(l$%s & 0x7FFF)); }\n",vptr->name,vptr->name,variable_svalue(vptr),vptr->name,vptr->name);
break;
				case	3 :
output_indentation();
fprintf(Output->handle,	"if (( p$%s != (BPTR) 0 ) && (l$%s & 0x8000)) { string_copy( %s,p$%s,(l$%s & 0x7FFF)); }\n",vptr->name,vptr->name,variable_svalue(vptr),vptr->name,vptr->name);
break;
				}
			}
		while (( vptr = vptr->next) != (TCVARPTR) 0);
		}
	return(0);
}

static	WORD	direct_rtl_procedure( pptr )
TCPRCPTR	pptr;
{
	TNODEPTR	tptr=(TNODEPTR) 0;
	TNODEPTR	xptr=(TNODEPTR) 0;
	TNODEPTR	rptr=(TNODEPTR) 0;
	BPTR		bptr=(BPTR) 0;
	BPTR		qptr=(BPTR) 0;
	TCVARPTR	vptr=(TCVARPTR) 0;

	if (!( is_left_brace() ))
		return( syntax_error() );

	if ((vptr = pptr->parameter) != (TCVARPTR) 0) {
		while (1) {
			switch ((vptr->type->type & 3)) {
				case	0 : 
				case	1 : bptr = IntegerExpression(); break;
				case	2 : bptr = BcdExpression(); break;
				case	3 : bptr = StringExpression(); break;
				}

			if (bptr == (BPTR) 0)
				return(syntax_error( 1050 ) );
			if ( is_question() )  {
				if (( qptr = allocate_for_tnode(strlen(bptr)+3)) == (BPTR) 0)
					return( allocation_failure() );
				sprintf(qptr,"?%s",bptr);
				bptr = qptr;
				}
			if ((xptr = allocate_tnode(strlen(bptr)+1)) == (TNODEPTR) 0)
				return( allocation_failure() );
			strcpy( xptr->value, bptr );
			if (rptr == (TNODEPTR) 0)
				tptr = xptr;
			else	rptr->next = xptr;
			rptr = xptr;

			if ((vptr = vptr->next) == (TCVARPTR) 0)
				break;
			else if (!( is_comma() ))
				return(syntax_error( 1050 ) );

			}
		}
	if (!( is_right_brace() ))
		return( unmatched_braces() );	
	else	return( rtl_procedure_transmission( pptr, tptr ) );
}

TCPRCPTR	allocate_for_procedure();
TCVARPTR	allocate_for_variable();
TCTYPPTR	allocate_for_type(WORD,WORD,WORD,WORD,VPTR);

static	WORD	indirect_rtl_procedure( pvptr )
BPTR	pvptr;
{
	WORD		status=0;
	TCPRCPTR	pptr=(TCPRCPTR) 0;
	TNODEPTR	tptr=(TNODEPTR) 0;
	TNODEPTR	xptr=(TNODEPTR) 0;
	TNODEPTR	rptr=(TNODEPTR) 0;
	BPTR		bptr=(BPTR) 0;
	BPTR		qptr=(BPTR) 0;
	TCVARPTR	vptr=(TCVARPTR) 0;
	TCVARPTR	lptr=(TCVARPTR) 0;
	WORD		type;

	if (!( is_left_brace() ))
		return( syntax_error() );

	if ((pptr = allocate_for_procedure()) == (TCPRCPTR) 0)
		return( allocation_failure() );

	pptr->name = pvptr;

	do	{

		if (((bptr = EvaluateExpression()) == (BPTR) 0)
		||  ( *bptr != '#' )) {
			status =  syntax_error();
			break;
			}
		else	{
			bptr++;
			type = ( *(bptr++) -'0' );
			}

		if (((vptr = allocate_for_variable()) == (TCVARPTR) 0)
		||  ((vptr->type = allocate_for_type( type, 1, 1, 1,(VPTR) 0 )) == (TCTYPPTR) 0)) {
			status = allocation_failure();
			break;
			}

		if ( lptr == (TCVARPTR) 0)
			pptr->parameter = vptr;
		else	lptr->next       = vptr;

		lptr = vptr;

		if ( is_question() )  {
			if (( qptr = allocate_for_tnode(strlen(bptr)+3)) == (BPTR) 0) {
				status = allocation_failure();
				break;
				}
			sprintf(qptr,"?%s",bptr);
			bptr = qptr;
			}
		if ((xptr = allocate_tnode(strlen(bptr)+1)) == (TNODEPTR) 0) {
			status = allocation_failure();
			break;
			}
		strcpy( xptr->value, bptr );
		if (rptr == (TNODEPTR) 0)
			tptr = xptr;
		else	rptr->next = xptr;
		rptr = xptr;
		}
	while 	( is_comma() );

	if ( status == 0 ) {
		if ( is_right_brace() )
			status = rtl_procedure_transmission( pptr, tptr );
		else 	status = unmatched_braces();	
		}

	/* Liberate Pseudo Procedure Now */
	/* ----------------------------- */
	if ( pptr != (TCPRCPTR) 0) {
		pptr->name = (BPTR) 0;
		liberate_for_procedure( pptr );
		}
	return( status );
}

VOID	initialise_error_control()
{
	generate_indentation( Output );
	fprintf(Output->handle,"RtlError.counter=0;\n");
}
VOID	generate_module_name( target )
CFILEPTR	target;
{
	WORD	i;
	for ( i = 0; i < 15; i++ ) {
		if ( Context->identity[i] == ' ' )
			break;
		else 	fprintf(target->handle,"%c",Context->identity[i]);
		}
	return;
}		

VOID	generate_module_controller( target )
CFILEPTR	target;
{
	generate_module_name( target );
	fprintf(target->handle,"_initialised");
	return;
}		

VOID	verify_module_controller()
{
	if ( context_is_module ) {
		generate_indentation( Output );
		fprintf(Output->handle,"if ((!( ");
		generate_module_controller( Output );
		fprintf(Output->handle," ))\n");
		generate_indentation( Output );
		fprintf(Output->handle,"&&  ((_rtl_status = ");
		generate_module_name( Output );
		fprintf(Output->handle,"_initialisation()) != 0)) { %s; }\n",_RTL_RAISE_ERROR);
		}
	return;
}

CFILEPTR	allocate_for_output()
{
	CFILEPTR	fptr;

	if ((fptr = (CFILEPTR) allocate( sizeof ( struct output_control ) )) != (CFILEPTR) 0) {
		fptr->name   = (BPTR) 0;
		fptr->handle = (FILEPTR) 0;
		fptr->indentation = 0;
		fptr->next = (CFILEPTR) 0;
		}
	return( fptr );
}

static	BYTE	PFName[32];

static	BPTR	pushfilename()
{
	sprintf(PFName,"%s%u",RtlHugePrefix,RtlHuge++);
	return( PFName );
}

static	WORD	push_rtl_output()
{
	CFILEPTR	fptr;
	WORD		status;
	if ((fptr = allocate_for_output()) == (CFILEPTR) 0)
		return( allocation_failure() );
	else if ((status = CreateOutputFile( fptr, pushfilename(), ".c",1 )) == 0) {
		fptr->next = Output;
		Output = fptr;
		generate_output_prefix(1);
		return( 0 );
		}
	else	return( allocation_failure() );
}

static	WORD	pop_rtl_output()
{
	CFILEPTR	fptr;
	if ((fptr = Output) != (CFILEPTR) 0) {
		Output = Output->next;
		CloseOutputFile( fptr, 1 );
		liberate( fptr );
		return( 0 );
		}
	else	return( internal_error( 616 ) );
}

static	WORD	start_procedure_function()
{
	TCPRCPTR	pptr;
	WORD		status;
	if ((pptr = Context->PRC) != (TCPRCPTR) 0) {
		if (( RtlHuge )
		&&  ((status = push_rtl_output()) != 0))
			return( status );
		Output->indentation = 0;
		Header->indentation = 0;
		rtl_procedure_prototype( pptr, 0 );
		rtl_procedure_definition( pptr );
		open_accolade(Output);
		generate_rtl_context();
		generate_indentation( Output );
		fprintf(Output->handle,"LDS_%s;\n",pptr->name);
		initialise_error_control();
		generate_indentation( Output );
		fprintf(Output->handle,"%s_DataManagerInit;\n",HostCodeName());
		verify_module_controller();
		rtl_procedure_reception( pptr );
		if ( OtrOption.Symbolic & 1 ) {
			generate_indentation( Output );
			fprintf(Output->handle,"iof_pause_string(%s);\n",rtlstring_constant( pptr->name ));
			}
		RtlCodeSection = VRAI;
		}
	return( 0 );
}

VOID	initialise_segment_pointer( name, number )
BPTR	name;
WORD	number;
{
	if ( number > RtlSegmentCount )
		RtlSegmentCount = number;
	generate_indentation( Output );
	fprintf(Output->handle,"_rtl_segment[%u] = segment_%s;\n",number,name);

}

VOID	generate_external_segment_entry( sptr )
XTSEGPTR	sptr;
{
	if ( sptr != (XTSEGPTR) 0 ) {
		fprintf(Footer->handle,"EXTERN WORD segment_%s();\n",sptr->name);
		if ( sptr->number != MOINS_UN )
			initialise_segment_pointer( sptr->name, sptr->number );
		}
	return;
}

static	WORD	start_segment_function()
{
	TCSEGPTR	sptr;
	WORD		status;
	if ((sptr = Context->CurrentSegment) != (TCSEGPTR) 0) {
		if (( RtlHuge )
		&&  ((status = push_rtl_output()) != 0))
			return( status );
		Output->indentation = 0;
		Header->indentation = 0;
		if ( sptr->name != (BPTR) 0 ) {
			fprintf(Footer->handle,"WORD segment_%s();\n",sptr->name);
			fprintf(Output->handle,"WORD segment_%s()\n",sptr->name);
			}
		else	{
			fprintf(Footer->handle,"WORD segment_%d();\n",sptr->identity);
			fprintf(Output->handle,"WORD segment_%d()\n",sptr->identity);
			}
		if (( sptr->identity > RtlSegmentCount )
		&&  ( sptr->identity != MOINS_UN ))
			RtlSegmentCount = sptr->identity;
		open_accolade(Output);
		generate_rtl_context();
		generate_indentation( Output );
		if ( sptr->name != (BPTR) 0 )
			fprintf(Output->handle,"LDS_segment_%s;\n",sptr->name);
		else	fprintf(Output->handle,"LDS_segment_%d;\n",sptr->identity);
		initialise_error_control();
		verify_module_controller();
		RtlCodeSection = VRAI;
		}	
	return( 0 );
}

/*	-----------------------------		*/
/*	PUBLIC	: INTERFACE FUNCTIONS		*/
/*	-----------------------------		*/

WORD	activate_rtl_procedure( pptr, rptr )
TCPRCPTR	pptr;
BPTR		rptr;
{
	if ( pptr == (TCPRCPTR) 0 )
		return( indirect_rtl_procedure( rptr ) );
	else	return( direct_rtl_procedure( pptr ) );
}

RESULTPTR	generate_register_load( rptr, sptr, mode )
RESULTPTR	rptr;
RESULTPTR 	sptr;
WORD		mode;
{
	return(rptr);
}

/*	-------------------------	*/
/*	terminate_procedure_table	*/
/*	-------------------------	*/
WORD	terminate_procedure_table() 
{ 
	return(0); 
}

/*	-------------------	*/
/*	generate_event_type	*/
/*	-------------------	*/
WORD	generate_event_type( WORD a) 
{ 
	return(0); 
}

/*	-----------------------	*/
/*	terminate_segment_table	*/
/*	-----------------------	*/
WORD	terminate_segment_table() 
{ 
	return(0); 
}

/*	-----------------	*/
/*	generate_on_timer	*/
/*	-----------------	*/
WORD	generate_on_timer( RESULTPTR r, WORD v) 
{ 
	return(0); 
}

/*	------------------	*/
/*	generate_increment	*/
/*	------------------	*/
RESULTPTR	generate_increment( RESULTPTR rptr )
{
	return(rptr);
}

/*	------------------	*/
/*	generate_decrement	*/
/*	------------------	*/
RESULTPTR	generate_decrement( RESULTPTR rptr )
{
	return(rptr);
}

VOID	open_gds_init()
{
	if ( context_is_module ) 
	{
		fprintf(Header->handle,"WORD ");
		generate_module_name(Header);
		fprintf(Header->handle,"_initialisation();\n");
		fprintf(Output->handle,"WORD ");
		generate_module_name(Output);
		fprintf(Output->handle,"_initialisation()\n");
		open_accolade( Output );
		generate_indentation( Output );
		generate_module_controller( Output );
		fprintf(Output->handle," = 1;\n");
	}
	else	
	{
		fprintf(Output->handle,"WORD gds_initialisation(argc,argv)\n");
		fprintf(Output->handle,"int    argc;\n");
		fprintf(Output->handle,"char * argv[];\n");
		open_accolade( Output );
		generate_indentation( Output );
		fprintf(Output->handle,"WORD i;\n");
		generate_indentation( Output );
		fprintf(Output->handle,"WORD _rtl_status=0;\n");
		generate_indentation( Output );
		fprintf(Output->handle,"struct _rtl_error_manager RtlError;\n");
		initialise_error_control();
		fprintf(Output->handle,"#ifdef _ABAL_WORD\n");
			generate_indentation( Output );
			fprintf(Output->handle,"RtlAbalWord();\n");
		fprintf(Output->handle,"#else\n");
			generate_indentation( Output );
			fprintf(Output->handle,"RtlIntelWord();\n");
		fprintf(Output->handle,"#endif\n");
		generate_indentation( Output );
		fprintf(Output->handle,"for (i=0;i< _SEGMENT_COUNT; i++)");
		open_accolade( Output );
		generate_indentation( Output );
		fprintf(Output->handle,"_rtl_segment[i] = rtl$error100;\n");
		close_accolade(Output);
	}
	RtlGdsInit = 1;
	return;
}

VOID	close_gds_init()
{
	if (( context_is_noclr )
	&&  (!( context_is_module ))) {
		generate_indentation(Output);
		fprintf(Output->handle,"iof_start();\n");
		generate_indentation(Output);
		fprintf(Output->handle,"iof_clear();\n");
		generate_indentation(Output);
		fprintf(Output->handle,"iof_flush();\n");
		}
	generate_indentation(Output);
	fprintf(Output->handle,"return(0);\n");
	if ( Output->indentation )
		Output->indentation--;
	close_accolade( Output );
	fprintf(Header->handle,"#define _SEGMENT_COUNT %u\n",(RtlSegmentCount+1));
	fprintf(Footer->handle,"_ABAL_SCOPE WORD (*_rtl_segment[_SEGMENT_COUNT])(); \n",RtlSegmentCount);
	RtlGdsInit=0;
	return;
}

/*	-------------	*/
/*	generate_byte	*/
/*	-------------	*/
WORD	generate_byte(WORD v) 
{ 
	return(0); 
}

/*	---------	*/
/*	tcputbyte	*/
/*	---------	*/
VOID	tcputbyte(WORD b) 
{ 
	return; 
}

/*	----------------------	*/
/*	generate_segment_entry	*/
/*	----------------------	*/
VOID	generate_segment_entry(TCSEGPTR sptr) 
{ 
	if (!( RtlGdsInit ))
		open_gds_init();

	if ( sptr->identity <=  RtlSegmentCount ) 
	{
		fprintf(Footer->handle,"HCN$%s_DataManager;\n",sptr->name);
		generate_indentation( Output );
		fprintf(Output->handle,"HCN$%s_DataManagerInit;\n",sptr->name);
		initialise_segment_pointer( sptr->name, sptr->identity );
	}
	return; 
}

/*	-------------------	*/
/*	generate_arithmetic	*/
/*	-------------------	*/
RESULTPTR	generate_arithmetic( operator, aterm, bterm, rterm)
WORD		operator;
RESULTPTR	aterm;
RESULTPTR	bterm;
RESULTPTR	rterm;
{
	return(rterm);
}

/*	-----------------------	*/
/*	generate_external_field	*/
/*	-----------------------	*/
VOID	generate_external_field(XTFIELDPTR f) 
{ 
	return;
}

/*	-------------------	*/
/*	symbolic_file_entry	*/
/*	-------------------	*/
VOID	symbolic_file_entry(BPTR f, WORD v) 
{ 
	return;
}

/*	-----------------	*/
/*	generate_proc_end	*/
/*	-----------------	*/
WORD	generate_proc_end() 
{ 
	return(0); 
}

/*	--------------------	*/
/*	generate_event_false	*/
/*	--------------------	*/
WORD	generate_event_false() 
{ 
	return(0); 
}

/*	------------------	*/
/*	generate_data_item	*/
/*	------------------	*/
VOID	generate_data_item( t, l, vptr )
WORD	t;
WORD	l;
BPTR	vptr;
{
	WORD	i;
	WORD	c;


	if ( RtlDataItems == 0 ) {
		open_data_items();
		}
	else	{
		RtlDataItems++;
		fprintf(Footer->handle,",\n");
		}
	fprintf(Footer->handle,"\t(BPTR) ");

	fprintf(Footer->handle,"%c",0x0022);

	if ( t == 3 ) {
		while ( *vptr )
			fprintf(Footer->handle,"%c",*(vptr++));
		}
	else	{
		/* BCD Constant */
		/* ------------ */
		if (( *vptr & 0x00F0 ) == 0x00B0)
			fprintf(Footer->handle,"-");

		while (1) {
			l--;
			switch (((c = (*(vptr++) & 0x000F)) )) {
				case 0x000A :
					fprintf(Footer->handle,".");
					break;
				case 0x000F :
					l = 0;
					break;
				default	    :
					fprintf(Footer->handle,"%c",(c+'0'));
				}
			if ( l == 0 )
				break;

			switch (((c = (*vptr & 0x00F0)) )) {
				case 0x00A0 :
					fprintf(Footer->handle,".");
					break;
				case 0x00F0 :
					l = 0;
					break;
				default	    :
					fprintf(Footer->handle,"%c",((c>>4)+'0'));
				}
			if ( l == 0 )
				break;
			}
		}
	fprintf(Footer->handle,"%c",0x0022);
	return;
}

/*	------------------	*/
/*	generate_read_data	*/
/*	------------------	*/
WORD	generate_read_data(RESULTPTR rptr) 
{
	BPTR		tptr;
	TCVARPTR 	vptr=(TCVARPTR) 0;
	if ( vptr == (TCVARPTR) 0)
		return( syntax_error() );
	switch ((vptr->type->type & 3)) // TODO
	{
		case	0 :
		case	1 : if ((tptr = generate_variable_name( vptr )) == (BPTR) 0)
				return( syntax_error() );
			    else break;
		case	2 :
		case	3 : if ((tptr = variable_svalue( vptr )) == (BPTR) 0)
				return( syntax_error() );
			    else break;
		default	  : return( syntax_error() );
	}
	generate_indentation( Output );
	fprintf(Output->handle,"if ((_rtl_status = rtl_data_");
	switch ((vptr->type->type & 3)) // TODO
	{
		case 0 : fprintf(Output->handle,"int8");
			 break;
		case 1 : fprintf(Output->handle,"int16");
			 break;
		case 2 : fprintf(Output->handle,"bcd");
			 break;
		case 3 : fprintf(Output->handle,"string");
			 break;
	}
	fprintf(Output->handle,"(& %s_RTL$DM, %s)) != 0) { %s; }\n",HostCodeName(),tptr,_RTL_RAISE_ERROR);
	RtlDataUsed++;
	return( 0 );
}

/*	------------------	*/
/*	flush_debug_sector	*/
/*	------------------	*/
VOID	flush_debug_sector() 
{ 
	return; 
}

/*	----------------	*/
/*	reset_byte_count	*/
/*	----------------	*/
VOID	reset_byte_count() 
{ 
	return; 
}

/*	---------------------	*/
/*	generate_debug_header	*/
/*	---------------------	*/
VOID	generate_debug_header( BPTR b, WORD l ) 
{ 
	return; 
}

/*	-------------------------	*/
/*	generate_cross_references	*/
/*	-------------------------	*/
WORD	generate_cross_references(XREFPTR x) 
{ 
	return(0); 
}

/*	-------------------	*/
/*	generate_conversion	*/
/*	-------------------	*/
RESULTPTR 	generate_conversion( RESULTPTR rptr, WORD type )
{
	return(rptr);
}

/*	-----------------	*/
/*	generate_segm_end	*/
/*	-----------------	*/
WORD	generate_segm_end() 
{ 
	return(0); 
}

/*	------------	*/
/*	generate_clf	*/
/*	------------	*/
WORD	generate_clf( WORD a, WORD b) 
{ 
	return(0); 
}

/*	-------------------	*/
/*	generate_dimensions	*/
/*	-------------------	*/
WORD	generate_dimensions(WORD i, TCVARPTR v) 
{ 
	return(0); 
}

/*	--------------------	*/
/*	generate_event_start	*/
/*	--------------------	*/
WORD	generate_event_start() 
{ 
	return(0); 
}

/*	-----------------------	*/
/*	generate_gosub_register	*/
/*	-----------------------	*/
WORD	generate_gosub_register(RESULTPTR r) 
{ 
	return(0); 
}

/*	------------	*/
/*	generate_clp	*/
/*	------------	*/
WORD	generate_clp()
{ 
	return(0); 
}

/*	--------------------	*/
/*	current_tcode_offset	*/
/*	--------------------	*/
WORD	current_tcode_offset() 
{ 
	return(0); 
}

/*	----------------	*/
/*	generate_compare	*/
/*	----------------	*/
WORD	generate_compare(WORD op, RESULTPTR l, RESULTPTR r, WORD a, WORD b) 
{ 
	return(0); 
}

/*	---------------------	*/
/*	generate_clp_identity	*/
/*	---------------------	*/
VOID	generate_clp_identity(RESULTPTR r) 
{ 
	return; 
}

/*	--------------	*/
/*	use_debug_file	*/
/*	--------------	*/
VOID	use_debug_file() 
{ 
	return; 
}

/*	-------------------------	*/
/*	terminate_correspondances	*/
/*	-------------------------	*/
VOID	terminate_correspondances(TCDBGPTR v) 
{ 
	return; 
}

/*	---------------------	*/
/*	generate_extern_event	*/
/*	---------------------	*/
WORD	generate_extern_event( WORD a, WORD b) 
{ 
	return(0); 
}

/*	-----------------	*/
/*	output_byte_count	*/
/*	-----------------	*/
WORD	output_byte_count() 
{ 
	return(0); 
}

/*	---------------------	*/
/*	current_target_sector	*/
/*	---------------------	*/
WORD	current_target_sector() 
{ 
	return(0); 
}

/*	--------------	*/
/*	release_labels	*/
/*	--------------	*/
WORD	release_labels() 
{ 
	return(0); 
}

/*	--------------	*/
/*	generate_label	*/
/*	--------------	*/
WORD	generate_label( WORD l) 
{ 
	return(0); 
}

/*	-------------	*/
/*	generate_push	*/
/*	-------------	*/
WORD	generate_push( WORD r) 
{ 
	return(0); 
}

/*	---------------------	*/
/*	generate_nurone_entry	*/
/*	---------------------	*/
WORD	generate_nurone_entry( nptr )
BPTR	nptr;
{
	return(0);
}

/*	-----------------------	*/
/*	generate_network_header	*/
/*	-----------------------	*/
WORD	generate_network_header( nptr )
BPTR	nptr; 
{
	return(0);
}

/*	---------------------	*/
/*	generate_tcode_header	*/
/*	---------------------	*/
VOID	generate_tcode_header(BPTR nptr, WORD v) 
{ 
	return; 
}

/*	---------------------	*/
/*	symbolic_module_entry	*/
/*	---------------------	*/
VOID	symbolic_module_entry(BPTR n, WORD v) 
{ 
	return; 
}

/*	--------------	*/
/*	use_tcode_file	*/
/*	--------------	*/
VOID	use_tcode_file() 
{ 
	return; 
}

/*	------------	*/
/*	generate_ldf	*/
/*	------------	*/
WORD	generate_ldf(TCDLBPTR l) 
{ 
	return(0); 
}

/*	---------------	*/
/*	generate_header	*/
/*	---------------	*/
VOID	generate_header( BPTR a, WORD b, WORD c) 
{ 
	return; 
}

/*	------------	*/
/*	flush_sector	*/
/*	------------	*/
VOID	flush_sector() 
{ 
	return; 
}

/*	------------	*/
/*	generate_ngf	*/
/*	------------	*/
WORD	generate_ngf( WORD v ) 
{ 
	return(0); 
}

/*	-------------------	*/
/*	use_explicite_label	*/
/*	-------------------	*/
WORD	use_explicite_label( BPTR nptr, WORD indent )
{
	if ( RtlOfControl != 0 ) 
	{
		generate_indentation(Output);
		fprintf(Output->handle,"\tcase %u : ",RtlOfCounter++);
		if ( *nptr == '&' ) nptr++;
		if ( RtlOfControl == 2 )
			fprintf(Output->handle,"rtl_gosub(%s); break; \n",nptr);
		else	fprintf(Output->handle,"goto %s;\n",nptr);
	}			
	return( VRAI );
}

/*	---------------	*/
/*	backpatch_label	*/
/*	---------------	*/
WORD	backpatch_label(WORD a,WORD b) 
{
	if ( RtlOfControl != 0 ) {
		generate_indentation(Output);
		fprintf(Output->handle,"\t}\n");
		RtlOfControl = 0;
		RtlOfCounter = 0;
		}
	return(0); 
}

/*	---------------	*/
/*	backpatch_value	*/
/*	---------------	*/
WORD	backpatch_value(WORD a,WORD b) 
{
	if ( RtlOfControl != 0 ) {
		RtlOfControl = 0;
		RtlOfCounter = 0;
		}
	return(0); 
}

/*	-----------	*/
/*	tcode_label	*/
/*	-----------	*/
WORD	tcode_label( WORD a) 
{ 
	return(0); 
}

/*	--------------------	*/
/*	of_requires_register	*/
/*	--------------------	*/
WORD	of_requires_register() 
{ 
	return(0); 
}

/*	-----------	*/
/*	generate_of	*/
/*	-----------	*/
WORD	generate_of(RESULTPTR rptr, WORD mode)
{
	RtlOfControl = (mode+1);
	RtlOfCounter = 1;
	generate_indentation(Output);
	fprintf(Output->handle,"switch ( %s ) {\n",variable_rvalue( rptr->contents ));
	return(1);
}

/*	------------------------	*/
/*	generate_newline_control	*/
/*	------------------------	*/
VOID	generate_newline_control()
{
	generate_indentation(Output);
	fprintf(Output->handle,"release_registers();\n");
	return;
}

/*	---------------	*/
/*	signal_new_line	*/
/*	---------------	*/
VOID	signal_new_line(WORD mode)
{
	if ( World->CurrentStructure == (TCSTRUCTPTR) 0 ) 
	{
		trace("signal_new_line()\n");
		release_expressions(mode);
		if ( mode )
			release_used_tnodes();
		if ( RtlRegisters ) 
		{
			generate_newline_control();
			RtlRegisters=0;
		}
		RtlNewLine = VRAI;
		if ( NewLineFlag == _tc_NEWLINE ) 
		{
			NewLineStatus = NewLineFlag;
			allow_construction();
		}
	}
	return;
}

/*	-------------	*/
/*	force_newline	*/
/*	-------------	*/
VOID	force_newline()
{
	if ( NewLineFlag == _tc_NEWLINE )
		NewLineStatus = NewLineFlag;
	RtlNewLine = VRAI;
	return;
}

/*	----------------------	*/
/*	inhibit_source_newline	*/
/*	----------------------	*/
VOID	inhibit_source_newline()
{
	NewLineStatus = NewLineFlag;
	NewLineFlag = 0;
	return;
}

/*	--------------------	*/
/*	allow_source_newline	*/
/*	--------------------	*/
VOID	allow_source_newline()
{
	NewLineStatus = NewLineFlag = _tc_NEWLINE;
	return;
}

/*	-------------------------	*/
/*	start_symbolic_procedures	*/
/*	-------------------------	*/
VOID	start_symbolic_procedures() 
{ 
	return; 
}

/*	---------------------	*/
/*	start_correspondances	*/
/*	---------------------	*/
VOID	start_correspondances(TCDBGPTR v) 
{ 
	return; 
}

/*	-----------------	*/
/*	next_debug_sector	*/
/*	-----------------	*/
WORD	next_debug_sector() 
{ 
	return(0); 
}

/*	---------------------	*/
/*	current_sector_offset	*/
/*	---------------------	*/
WORD	current_sector_offset() 
{ 
	return( 0 ); 
}

/*	--------------	*/
/*	generate_event	*/
/*	--------------	*/
WORD	generate_event() 
{ 
	return(0); 
}

/*	-----------------------------	*/
/*	terminate_external_procedures	*/
/*	-----------------------------	*/
WORD	terminate_external_procedures() 
{ 
	return(0); 
}

/*	-----------------------	*/
/*	generate_function_entry	*/
/*	-----------------------	*/
VOID	generate_function_entry(TCDLBPTR v) 
{ 
	return; 
}

/*	-------------------------	*/
/*	terminate_external_fields	*/
/*	-------------------------	*/
WORD	terminate_external_fields() 
{ 
	return(0); 
}

/*	------------------	*/
/*	generate_iteration	*/
/*	------------------	*/
WORD	generate_iteration() 
{ 
	return(0); 
}

/*	------------	*/
/*	generate_pop	*/
/*	------------	*/
WORD	generate_pop(WORD r) 
{ 
	return(0); 
}

/*	------------------------	*/
/*	generate_procedure_entry	*/
/*	------------------------	*/
VOID	generate_procedure_entry(TCPRCPTR pptr) 
{ 
	return; 
}

/*	------------------------	*/
/*	generate_external_member	*/
/*	------------------------	*/
WORD	generate_external_member(XTVARPTR v) 
{ 
	return(0); 
}

/*	-----------------------	*/
/*	generate_external_local	*/
/*	-----------------------	*/
VOID	generate_external_local(XTLOCALPTR x) 
{ 
	return; 
}

/*	-------------	*/
/*	tcode_integer	*/
/*	-------------	*/
WORD	tcode_integer(WORD v) 
{ 
	return(0); 
}

/*	-----------------------	*/
/*	start_symbolic_segments	*/
/*	-----------------------	*/
VOID	start_symbolic_segments() 
{ 
	return; 
}

/*	-------------	*/
/*	tcode_operand	*/
/*	-------------	*/
VOID	tcode_operand(RESULTPTR rptr) 
{ 
	return; 
}

/*	---------------	*/
/*	negate_register	*/
/*	---------------	*/
WORD	negate_register(RESULTPTR rptr) 
{ 
	return(0); 
}

/*	---------------------------	*/
/*	terminate_external_segments	*/
/*	---------------------------	*/
WORD	terminate_external_segments() 
{ 
	return(0); 
}

/*	------------------	*/
/*	generate_event_off	*/
/*	------------------	*/
WORD	generate_event_off() 
{ 
	return(0); 
}

/*	----------------------	*/
/*	generate_goto_register	*/
/*	----------------------	*/
WORD	generate_goto_register(RESULTPTR rptr) 
{ 
	return(0); 
}

/*	----------------------	*/
/*	generate_copy_register	*/
/*	----------------------	*/
WORD	generate_copy_register(WORD a, WORD b) 
{ 
	return(0); 
}

/*	----------------	*/
/*	terminate_output	*/
/*	----------------	*/
VOID	terminate_output()
{
	if (!( RtlGdsInit ))
		open_gds_init();

	if ( RtlGdsInit )
		close_gds_init();

	CloseOutputFile( Footer, 3 );
	CloseOutputFile( Header, 2 );
	CloseOutputFile( Output, 1 );
	CloseOutputFile(MakeFile,0 );

	liberate( Footer );
	liberate( Header );
	liberate( Output );
	liberate( MakeFile );
	liberate_tnodes();

	return;
}

/*	------------------	*/
/*	establish_gdt_name	*/
/*	------------------	*/
VOID	establish_gdt_name()
{
	WORD	i;
	if ( context_is_module ) 
	{
		for ( i = 0; i < 15; i++ ) 
		{
			if ( Context->identity[i] == ' ' )
				break;
			else 	RtlGdtName[i] = Context->identity[i];
		}
		RtlGdtName[i++] = '$';
		RtlGdtName[i] = 0;
		strcat((BPTR) RtlGdtName, "GDS");
	}
	else	strcpy((BPTR) RtlGdtName, "GDS");
	return;
}

/*	----------------------	*/
/*	global_data_table_name	*/
/*	----------------------	*/
BPTR	global_data_table_name()
{
	return( (BPTR) RtlGdtName );
}

/*	----------------------	*/
/*	generate_output_prefix	*/
/*	----------------------	*/
static VOID	generate_output_prefix( WORD mode )
{
	generate_hash_include( Output, "<rtlabal.h>" );
	generate_hash_include( Output, "<rtlavm.h>" );
	if ( mode )
		fprintf(Output->handle,"\n#define _ABAL_SCOPE EXTERN\n\n");
	else	fprintf(Output->handle,"\n#define _ABAL_SCOPE \n\n");

	generate_hash_include( Output, Header->name );
	fprintf(Output->handle,"\n%s_members;\n",global_data_table_name());
	fprintf(Header->handle,"EXTERN WORD _rtl_hotkey;\n");
	if ( context_is_module ) 
	{
		fprintf(Header->handle,"_ABAL_SCOPE WORD ");
		generate_module_controller( Header );
		fprintf(Header->handle,"=0;\n");
	}
	generate_hash_include( Output, Footer->name );
	return;
}

/*	---------------------	*/
/*	initialise_apl_output	*/
/*	---------------------	*/
WORD	initialise_apl_output( BPTR filename )
{
	return( 56 );
}

/*	-----------------	*/
/*	initialise_output	*/
/*	-----------------	*/
WORD	initialise_output(BPTR filename)
{
	BPTR	buffer;
	WORD	status;

	if ((MakeFile = allocate_for_output()) == (CFILEPTR) 0)
		return( allocation_failure() );
	if ((Output = allocate_for_output()) == (CFILEPTR) 0)
		return( allocation_failure() );
	if ((Header = allocate_for_output()) == (CFILEPTR) 0)
		return( allocation_failure() );
	if ((Footer = allocate_for_output()) == (CFILEPTR) 0)
		return( allocation_failure() );
	initialise_tnodes();

	if (((status = CreateOutputFile(MakeFile,filename,".mf",0 )) == 0)
	&&  ((status = CreateOutputFile( Output, filename, ".c",1 )) == 0)
	&&  ((status = CreateOutputFile( Header, filename, ".h",2 )) == 0)
	&&  ((status = CreateOutputFile( Footer, filename, ".f",3 )) == 0)) 
	{
		establish_gdt_name();
		if (!(OtrOption.Optimise)) 
		{
			UseRtlAbalWord = 1;
			fprintf(Output->handle,"#define _ABAL_WORD \n");
		}
		else	UseRtlAbalWord = 0;
		OtrOption.Optimise = FAUX;
		generate_output_prefix(0);
		return( 0 );
	}
	else	
	{
		(void) terminate_output();
		return( status );
	}
}

/*	----------------	*/
/*	start_code_block	*/
/*	----------------	*/
VOID	start_code_block() 
{
	fprintf(Output->handle,"\n");
	if ( Context->PRC != (TCPRCPTR) 0 )
		start_procedure_function();
	else	start_segment_function();
}

/*	-------------	*/
/*	generate_exit	*/
/*	-------------	*/
WORD	generate_exit(RESULTPTR rptr) 
{ 
	generate_indentation( Output );
	fprintf( Output->handle, "goto PROCEXIT;\n");
	return(0); 
}

/*	---------------	*/
/*	generate_retseg	*/
/*	---------------	*/
WORD	generate_retseg()
{ 
	generate_indentation( Output );
	fprintf( Output->handle, "return(0);\n");
	return(0); 
}

/*	-------------	*/
/*	generate_stop	*/
/*	-------------	*/
WORD	generate_stop() 
{
	generate_indentation( Output );
	fprintf( Output->handle, "exit(0);\n");
	return(0); 
}

/*	--------------------	*/
/*	terminate_code_block	*/
/*	--------------------	*/
WORD	terminate_code_block() 
{ 
	if ( Context->PRC != (TCPRCPTR) 0) 
	{
		fprintf(Output->handle,"\nPROCEXIT:\n");
		rtl_procedure_retransmission(Context->PRC);
		generate_indentation( Output );
		fprintf( Output->handle, "return(0);\n");
	}
	Output->indentation = 0;
	close_accolade( Output );
	close_data_items();
	if ( RtlResumeUsed )
		fprintf(Header->handle,"#define %s$RtlNewLine rtl_newline\n",HostCodeName());
	else	fprintf(Header->handle,"#define %s$RtlNewLine \n",HostCodeName());
	RtlCodeSection = FAUX;
	if ( RtlHuge )
		return( pop_rtl_output() );
	else	return(0); 
}

TCVARPTR	ResolveHostMember(vptr)
TCVARPTR	vptr;
{
	WORD	host;
	host = vptr->host;
	if (( vptr->vdt != (TCVDTPTR) 0)
	&&  ((vptr = vptr->vdt->first) != (TCVARPTR) 0)) {
		do	{
			if ( vptr->identity == host )
				return( vptr );
			}
		while ((vptr = vptr->prev) != (TCVARPTR) 0);
		}
	return((TCVARPTR) 0);	
}

VOID	ResolveMemoryOffset( vptr )
TCVARPTR	vptr;
{
	if ( vptr == (TCVARPTR) 0 )
		fprintf(Header->handle,"<null>");
	else 
	switch (( vptr->type->type & 0xB000 )) {
		case	0	:	/* Base DCL   */
			fprintf(Header->handle,"(& %s%d[%u])",DataTableName,DataTableType,(WORD)vptr->offset);
			break;
		case	_TYPE_POINTER	:	/* Base PTR   */
			fprintf(Header->handle,"(getpointer((& %s%d[%u])))",DataTableName,DataTableType,(WORD)vptr->offset);
			break;
		case	0xA000	:	/* DCL in PTR */
			fprintf(Header->handle,"(");
			ResolveMemoryOffset( ResolveHostMember( vptr ) );
			if ( vptr->offset != 0 )
				fprintf(Header->handle,"+%u)",(WORD)vptr->offset);
			else	fprintf(Header->handle,")");
			break;
		case	0xB000	:	/* PTR in PTR */
			fprintf(Header->handle,"(getpointer(");
			ResolveMemoryOffset( ResolveHostMember( vptr ) );
			if ( vptr->offset != 0 )
				fprintf(Header->handle,"+%u))",(WORD)vptr->offset);
			else	fprintf(Header->handle,"))");
			break;
		}
	return;
}
VOID	ResolvePointerOffset( vptr )
TCVARPTR	vptr;
{
	if ( vptr == (TCVARPTR) 0 )
		fprintf(Header->handle,"<null>");
	else 
	switch (( vptr->type->type & 0xB000 )) {
		case	_TYPE_POINTER	:	/* Base PTR   */
			fprintf(Header->handle,"(& %s%d[%u])",DataTableName,DataTableType,(WORD)vptr->offset);
			break;
		case	0xB000	:	/* PTR in PTR */
			fprintf(Header->handle,"(");
			ResolveMemoryOffset( ResolveHostMember( vptr ) );
			if ( vptr->offset != 0 )
				fprintf(Header->handle,"+%u)",(WORD)vptr->offset);
			else	fprintf(Header->handle,")");
			break;
		}
	return;
}

WORD	generate_constant(cptr)
TCCONPTR	cptr; 
{
	BPTR	vptr;
	WORD	l=0;
	WORD	hb;
	WORD	lb;
	if (( cptr != (TCCONPTR) 0 )
	&&  ( cptr->type != (TCTYPPTR) 0)) {

		switch ((cptr->type->type & _TYPE_BASIC)) {
			case	0 :
			case	1 :
			case	5 :
				fprintf(Header->handle,"#define %s %u\n",cptr->name,cptr->identity);
				break;

			case	2 :
				if (((vptr = cptr->value) != (BPTR) 0)
				&&  ((l    = cptr->length) != 0 )) {
					fprintf(Header->handle,"static BYTE %s[%u] = {\n",cptr->name,l);
					while ( l ) {
						l--;
						if ((hb = (*vptr >> 4)) > 9)
							hb = ((hb - 10) + 'A');
						else	hb += '0';
						if ((lb = (*(vptr++) & 0x000F)) > 9)
							lb = ((lb - 10) + 'A');
						else	lb += '0';
						if ( l ) 
							fprintf(Header->handle,"\t0x00%c%c,\n",hb,lb);
						else	fprintf(Header->handle,"\t0x00%c%c \n",hb,lb);
						}
					fprintf(Header->handle,"\t};\n");
					}
				break;

			case	3 :
				if (((vptr = cptr->value) != (BPTR) 0)
				&&  ((l    = cptr->length) != 0 )) {
					fprintf(Header->handle,"#define %s %c",cptr->name,0x0022);
					while ( l ) {
						fprintf(Header->handle,"%c",*(vptr++));
						l--;
						}
					fprintf(Header->handle,"%c\n",0x0022);
					}
				break;
			}

		}

	return(0);
}

/* ------------------------- 	*/
/* ARGVAR = ARGVAR ! "," 	*/
/* ARGVAR = ARGVAR ! argv[i] 	*/
/* ------------------------- 	*/

VOID	generate_initialise_arg( vptr )
TCVARPTR	vptr;
{
	BPTR	rptr;
	trace("generate_initialise_arg()\n");
	if ((rptr = StringOperation('!',variable_svalue(vptr),rtlstring_constant(","))) != (BPTR) 0) {
		generate_indentation( Output );
		fprintf(Output->handle,"string_copy(%s,%s);\n",rptr,variable_svalue(vptr));
		if ((rptr = StringOperation('!',variable_svalue(vptr),"argv[i],str_len(argv[i])")) != (BPTR) 0) {
			generate_indentation( Output );
			fprintf(Output->handle,"string_copy(%s,%s);\n",rptr,variable_svalue(vptr));
			}
		signal_new_line(MOINS_UN);
		}
	return;
}

WORD	generate_else()
{
	close_accolade( Output );
	generate_indentation( Output );
	fprintf(Output->handle,"else\t");
	generate_open_accolade( Output );
	return( 0 );
}

WORD	generate_else_if(xptr)
BPTR	xptr;
{
	close_accolade( Output );
	generate_indentation( Output );
	fprintf(Output->handle,"else if (%s)\t",xptr);
	generate_open_accolade( Output );
	return( 0 );
}

VOID	generate_initialise_dcl( vptr )
TCVARPTR	vptr;
{
	trace("generate_initialise_dcl()\n");

	if ( is_virtual_variable( vptr ) )
		return;
	switch (( vptr->type->type & 0xF000 )) {
		case _TYPE_POINTER : 	if (!( RtlGdsInit ))
					open_gds_init();
				generate_indentation( Output );
				fprintf(Output->handle,"(void) clf_forget(%s,%u,%u,%u);\n",generate_pointer_adresse(vptr),vptr->type->size,vptr->type->first,vptr->type->second);
				return;
		case	0   :	break;
		default	    :	return;
		}

	if (!( RtlGdsInit ))
		open_gds_init();

	if ( vptr->type->type & 8 ) {
		generate_indentation( Output );
		fprintf(Output->handle,"if ( argc < 2 ) ");
		open_accolade( Output );
		}

	switch ((vptr->type->type & 3)) {
		case 0 :
			generate_indentation( Output );
			fprintf(Output->handle,"*(%s) = 0;\n",generate_variable_name(vptr));
			break;
		case 1 :
			generate_indentation( Output );
			fprintf(Output->handle,"putabalword(%s,0);\n",generate_variable_name(vptr));
			break;
		case 2 :
			generate_indentation( Output );
			fprintf(Output->handle,"bcd_copy(%s,%s);\n",rtlbcd_constant("0") ,variable_svalue(vptr));
			break;
		case 3 :
			generate_indentation( Output );
			fprintf(Output->handle,"string_copy(%c%s%c,1,%s);\n",0x0022," ",0x0022 ,variable_svalue(vptr));
			break;
		}
	if ( vptr->type->type & 8 ) {
		/* ------------------------- 	*/
		/* ARGVAR = argv[1] 		*/
		/* for i = 2 < argc 		*/
		/* ------------------------- 	*/
		generate_else();
		generate_indentation( Output );
		fprintf(Output->handle,"string_copy(argv[1],str_len(argv[1]),%s);\n",variable_svalue(vptr));
		generate_indentation( Output );
		fprintf(Output->handle,"for ( i=2; i < argc; i++ )");
		open_accolade( Output );
		generate_initialise_arg( vptr );
		close_accolade( Output );
		close_accolade( Output );
		}
	return;

}

WORD	generate_descriptor( vptr, mode )
TCVARPTR	vptr;
WORD		mode;
{
	trace("generate_descriptor()\n");
	/* #define [GDS | LDS] <i> _ <name> [ GDS | LDS ] <i> [offset] */
	fprintf(Header->handle,"#define %s%d_%s ",DataTableName,DataTableType,vptr->name);
	ResolveMemoryOffset(vptr);
	fprintf(Header->handle,"\n");
	if (( vptr->type->type & _TYPE_POINTER ) == _TYPE_POINTER) {
		fprintf(Header->handle,"#define %s%d$%s ",DataTableName,DataTableType,vptr->name);
		ResolvePointerOffset(vptr);
		fprintf(Header->handle,"\n");
		}
	if ( DataTableType ==  0 )
		generate_initialise_dcl( vptr );
	return(0);
}

WORD	generate_data_table( tptr, fptr, mode )
TCVDTPTR	tptr;
FIELDPTR	fptr;
WORD		mode;
{
	BPTR	prefix;
	WORD	nombre;
	if ( mode != 0 ) {
		trace("generate_data_table()\n");
		if ( Context->PRC != (TCPRCPTR) 0 ) {
			DataTableName = (BPTR) "LDS";
			DataTableType = LocalDataTableCount;
			fprintf(Header->handle,"#define %s_%s ",DataTableName,Context->PRC->name);
			}
		else if ( Context->CurrentSegment != (TCSEGPTR) 0 ) {
			DataTableName = (BPTR) "LDS";
			DataTableType = LocalDataTableCount;
			if ( Context->CurrentSegment->name != (BPTR) 0 )
				fprintf(Header->handle,"#define %s_segment_%s ",DataTableName,Context->CurrentSegment->name);
			else	fprintf(Header->handle,"#define %s_segment_%d ",DataTableName,Context->CurrentSegment->identity);
			}
		else	{
			DataTableName = global_data_table_name();
			DataTableType = 0;
			fprintf(Header->handle,"#define %s_members ",DataTableName);
			if (( tptr->nombre != 0 )
			&&  ( fptr != (FIELDPTR) 0 ))
				fprintf(Header->handle," _ABAL_SCOPE ");
			}

		if (( tptr->nombre != 0 )
		&&  ( fptr != (FIELDPTR) 0 ))
			fprintf(Header->handle,"BYTE %s%u[%u]",DataTableName,DataTableType,fptr->MaxSmallField );

		fprintf(Header->handle,"\n");
		}

	return( tptr->nombre );
}

WORD	generate_comment(mode)
WORD	mode;
{
	WORD	c;
	WORD	status;
	status = is_active_region();
	if ( mode )
		c = get_byte();
	if (( Output != (CFILEPTR) 0 )
	&&  ( status ))
		fprintf(Output->handle,"/* ");
	while (1) {

		switch ((c = get_byte())) {
			case	0	 :
			case	'\n'	 :
			case	MOINS_UN :
				if (( Output != (CFILEPTR) 0 )
				&&  ( status ))
					fprintf(Output->handle," */\n");
				return( 0 );
			case	'\r'	:
				continue;
			default		:
				if (( Output != (CFILEPTR) 0 )
				&&  ( status ))
					fprintf(Output->handle,"%c",c);
	
			}
		}

}

WORD	generate_iof( )
{
	HOTPTR	hptr;
	generate_indentation( Output );
	fprintf(Output->handle,"iof_start();\n");
	RtlHotkeys=0;
	while ((hptr = RtlHotHead) != (HOTPTR) 0) {
		RtlHotHead = RtlHotHead->next;
		hptr->label = (BPTR) 0;
		release_hotkey( hptr );
		}
	return( 0 );
}

WORD	generate_fio( )
{
	generate_indentation( Output );
	fprintf(Output->handle,"iof_flush();\n");
	RtlHotkeys= 0;
	return( 0 );
}

WORD	generate_iof_hotkey( hptr )
HOTPTR	hptr;
{
	HOTPTR	nptr;
	if ((nptr = copy_hotkey( hptr )) == (HOTPTR) 0)
		return( allocation_failure() );
	nptr->next = RtlHotHead;
	RtlHotHead = nptr;
	RtlHotkeys++;
	trace("generate_iof_hotkey()\n");
	return( generate_rtliof_hotkey( nptr ) );
}

WORD	generate_iof_format(opcode, fptr )
WORD	opcode;
BPTR	fptr;
{
	WORD	l;
	WORD	n=0;
	RtlFormatCount++;
	generate_indentation( Output );
	fprintf(Output->handle,"iof_format_string( RTL$FMT%u, %u );\n",RtlFormatCount,(l = *(fptr++)));
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
	return( 0 );
}

WORD	generate_clf_format( fptr )
BPTR	fptr;
{
	WORD	l;
	WORD	n=0;
	RtlFormatCount++;
	fprintf(Output->handle,"RTL$FMT%u, %u ",RtlFormatCount,(l = *(fptr++)));
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
	return( 0 );
}

VOID	csrc_integer( buffer, value )
BPTR	buffer;
WORD	value;
{
	sprintf(buffer,"%u",value);
	return;
}

VOID	csrc_register_integer( buffer, value )
BPTR	buffer;
WORD	value;
{
	sprintf(buffer,"AbalRegister[%u].value",value);
	return;
}

VOID	csrc_constant_integer( buffer, cptr )
BPTR		buffer;
TCCONPTR	cptr;
{
	strcpy(buffer,"0");
	return;
}

VOID	csrc_variable_integer( buffer, vptr )
BPTR		buffer;
TCVARPTR	vptr;
{
	sprintf(buffer,"(getabalword( %s ))",generate_variable_name(vptr));
	return;
}


VOID	generate_code_rellocation(RELOCPTR r)
{
	return;
}

/*	------------------------	*/
/*	generate_rtl_affectation	*/
/*	------------------------	*/
WORD	generate_rtl_affectation( rptr, mode,echomode)
BPTR		rptr;
WORD		mode;
WORD		echomode;
{
	if ( mode )
		generate_indentation( Output );
	fprintf(Output->handle,"%s",rptr);
	if ( mode )
		fprintf(Output->handle,";\n");
	return(0); 
}

WORD	add_explicite_label( lptr )
BPTR	lptr;
{
	if ( is_active_region() ) 
	{
		if ( *lptr == '&' )
			lptr++;
		fprintf(Output->handle,"%s:\n",lptr);
	}
	return( VRAI );
}


WORD	generate_return() 
{ 
	generate_indentation( Output );
	fprintf(Output->handle,"rtl_return();\n");
	return(0); 
}

/*	-------------	*/
/*	generate_goto	*/
/*	-------------	*/
WORD	generate_goto( label )
WORD	label;
{
	generate_indentation( Output );
	fprintf(Output->handle,"goto $%u;\n",label);
	return( 0 );
}

/*	-------------------------	*/
/*	generate_goto_instruction	*/
/*	-------------------------	*/
WORD	generate_goto_instruction(lptr) 
BPTR	lptr;
{ 
	if ( *lptr == '&' )
		lptr++;
	generate_indentation( Output );
	fprintf(Output->handle,"goto %s;\n",lptr);
	return(0); 
}

/*	---------------	*/
/*	generate_resume	*/
/*	---------------	*/
WORD	generate_resume(WORD mode, BPTR label)
{
	if ( mode ) 
		return( generate_goto_instruction( label ) );
	else	
	{
		generate_indentation( Output );
		fprintf(Output->handle,"rtl_resume;\n");
		RtlResumeUsed++;
	}
	return(0); 
}

/*	--------------	*/
/*	generate_gosub 	*/
/*	--------------	*/
WORD	generate_gosub( BPTR lptr) 
{ 
	if ( *lptr == '&' )
		lptr++;
	generate_indentation( Output );
	fprintf(Output->handle,"rtl_gosub(%s);\n",lptr);
	return(0); 
}

/*	--------------------	*/
/*	generate_gosub_label	*/
/*	--------------------	*/
WORD	generate_gosub_label( BPTR tptr ) 
{
	return( generate_gosub( tptr ) ); 
}

/*	-----------	*/
/*	generate_do	*/
/*	-----------	*/
WORD	generate_do()
{
	generate_indentation( Output );
	fprintf(Output->handle,"while (1)\t");
	generate_open_accolade(Output);
	return(0); 
}

/*	-------------	*/
/*	generate_loop	*/
/*	-------------	*/
WORD	generate_loop()
{
	close_accolade( Output );
	return( 0 );
}

/*	---------------	*/
/*	generate_repeat	*/
/*	---------------	*/
WORD	generate_repeat()
{
	generate_indentation( Output );
	fprintf(Output->handle,"do\t");
	generate_open_accolade(Output);
	return(0); 
}

/*	-----------	*/
/*	generate_if	*/
/*	-----------	*/
WORD	generate_if( BPTR xptr)
{
	generate_indentation( Output );
	fprintf(Output->handle,"if (%s)\t",xptr);
	generate_open_accolade( Output );
	return( 0 );
}

/*	--------------	*/
/*	generate_endif	*/
/*	--------------	*/
WORD	generate_endif()
{
	close_accolade( Output );
	return( 0 );
}

/*	--------------	*/
/*	generate_break	*/
/*	--------------	*/
WORD	generate_break()
{
	generate_indentation( Output );
	fprintf(Output->handle,"break;\n");
	return(0);
}

/*	-----------	*/
/*	generate_op	*/
/*	-----------	*/
WORD	generate_op( BPTR label, TCVARPTR vptr)
{
	generate_if( "x_kbhit()" );

	if ( vptr != (TCVARPTR) 0 ) 
	{
		switch ( vptr->type->type ) 
		{
		case	0 :
			generate_indentation( Output );
			fprintf(Output->handle,"*((BPTR) %s) = x_getch();\n",generate_variable_name(vptr));
			break;
		case	1 :
			generate_indentation( Output );
			fprintf(Output->handle,"_rtl_status = x_getch();\n");
			generate_indentation( Output );
			fprintf(Output->handle,"putabalword(%s,_rtl_status);\n",generate_variable_name(vptr));
			break;
		default	:
			return( not_yet_available() );
		}
	}

	if ( label != (BPTR) 0 )  
	{
		if ( strlen(label) != 0 )
			generate_goto_instruction( label );
		else	generate_break();
	}
	if ( vptr != (TCVARPTR) 0) 
	{
		generate_else();
		switch ( vptr->type->type ) 
		{
		case	0 :
			generate_indentation( Output );
			fprintf(Output->handle,"*((BPTR) %s) = 0;\n",generate_variable_name(vptr));
			break;
		case	1 :
			generate_indentation( Output );
			fprintf(Output->handle,"putabalword(%s,0);\n",generate_variable_name(vptr));
			break;
		default	:
			return( not_yet_available() );
		}
	}
	generate_endif();
	return( 0 );
}

/*	--------------	*/
/*	generate_while	*/
/*	--------------	*/
WORD	generate_while(BPTR xptr)
{
	generate_indentation( Output );
	fprintf(Output->handle,"while (%s)\t",xptr);
	generate_open_accolade( Output );
	return( 0 );
}

/*	-------------	*/
/*	generate_wend	*/
/*	-------------	*/
WORD	generate_wend()
{
	close_accolade( Output );
	return( 0 );
}

/*	--------------	*/
/*	generate_until	*/
/*	--------------	*/
WORD	generate_until(BPTR xptr)
{
	close_accolade( Output );
	generate_indentation( Output );
	fprintf(Output->handle,"while (%s);\n",xptr);
	return( 0 );
}

/*	---------------	*/
/*	generate_select	*/
/*	---------------	*/
WORD	generate_select( BPTR xptr )
{
	TNODEPTR	tptr;
	if ((tptr = allocate_tnode( strlen(xptr) + 1)) == (TNODEPTR) 0)
		return( allocation_failure() );
	strcpy( tptr->value, xptr );
	tptr->state = 0;
	tptr->next = RtlSelectHeap;
	RtlSelectHeap = tptr;
	return( 0 );
}

/*	----------------	*/
/*	generate_or_case	*/
/*	----------------	*/
WORD	generate_or_case(BPTR xptr,WORD mode)
{
	TNODEPTR	tptr;
	BPTR		lptr;
	if ((tptr = RtlSelectHeap) == (TNODEPTR) 0 )
		return( syntax_error() );
	generate_indentation( Output );
	fprintf(Output->handle,"|| (");

	/* ---------------- */
	/* Generate Compare */
	/* ---------------- */
	lptr = tptr->value;

	while ( *lptr == '#' )
		lptr += 2;

	while ( *xptr == '#' )
		xptr += 2;

	fprintf(Output->handle,"%s == %s )\t",lptr,xptr);
	if ( mode ) 
	{
		fprintf(Output->handle,")");
		generate_open_accolade( Output );
	}
	else	fprintf(Output->handle,"\n");
	return( 0 );

}

/*	-------------	*/
/*	generate_case	*/
/*	-------------	*/
WORD	generate_case(BPTR xptr,WORD mode)
{
	TNODEPTR	tptr;
	BPTR		lptr;

	if ((tptr = RtlSelectHeap) == (TNODEPTR) 0 )
		return( syntax_error() );
	if (tptr->state) 
	{
		(void) generate_endif();
		generate_indentation( Output );
		fprintf(Output->handle,"else if (");
	}
	else	
	{
		generate_indentation( Output );
		fprintf(Output->handle,"if (");
	}

	if (!(mode))
		fprintf(Output->handle,"(");
	tptr->state++;

	/* ---------------- */
	/* Generate Compare */
	/* ---------------- */
	lptr = tptr->value;

	while ( *lptr == '#' )
		lptr += 2;

	while ( *xptr == '#' )
		xptr += 2;

	fprintf(Output->handle,"%s == %s )\t",lptr,xptr);
	if ( mode )
		generate_open_accolade( Output );
	else	fprintf(Output->handle,"\n");
	return( 0 );
}

/*	----------------	*/
/*	generate_default	*/
/*	----------------	*/
WORD	generate_default()
{
	TNODEPTR	tptr;
	if ((tptr = RtlSelectHeap) == (TNODEPTR) 0 )
		return( syntax_error() );
	if (tptr->state) 
	{
		(void) generate_endif();
		generate_indentation( Output );
		fprintf(Output->handle,"else\t");
		generate_open_accolade( Output );
		tptr->state++;
	}
	return( 0 );

}

/*	-----------------	*/	
/*	 generate_endsel	*/
/*	-----------------	*/	
WORD	generate_endsel()
{
	TNODEPTR	tptr;
	if ((tptr = RtlSelectHeap) == (TNODEPTR) 0 )
		return( syntax_error() );
	if (tptr->state)
		(void) generate_endif();
	RtlSelectHeap = RtlSelectHeap->next;
	release_tnode( tptr );
	return( 0 );
}

/*	--------------------	*/
/*	generate_error_abort	*/
/*	--------------------	*/
WORD	generate_error_abort()
{ 
	generate_indentation( Output );
	fprintf(Output->handle,"rtl_abort();\n");
	return(0); 
}

/*	------------------	*/
/*	implicite_on_error	*/
/*	------------------	*/
WORD	implicite_on_error( TCVARPTR vptr, WORD type, WORD label )
{
	generate_indentation( Output );
	fprintf(Output->handle,"rtl_on_error(%s,$%u);\n",generate_variable_name(vptr),label);
	return(0);	
}

/*	------------------	*/
/*	explicite_on_error	*/
/*	------------------	*/
WORD	explicite_on_error( TCVARPTR vptr, WORD type, BPTR label )
{
	generate_indentation( Output );
	if ( *label == '&' ) label++;
	fprintf(Output->handle,"rtl_on_error(%s,%s);\n",generate_variable_name(vptr),label);
	return(0);	
}

/*	------------------	*/
/*	generate_rtl_error	*/
/*	------------------	*/
WORD	generate_rtl_error(BPTR vptr) 
{
	BPTR	tptr=(BPTR) 0;
	generate_indentation( Output );
	fprintf(Output->handle,"rtl_raise(%s);\n",vptr);
	return(0); 
}

/*	----------------------	*/
/*	integer_from_resultptr	*/
/*	----------------------	*/
BPTR	integer_from_resultptr( RESULTPTR rptr )
{
	BPTR	tptr;
	switch ( rptr->nature ) {
		case _RESULT_INT   :
			if ((tptr = allocate_for_tnode( 8 )) != (BPTR) 0)
				sprintf(tptr,"%d",rptr->value);
			break;
		case _RESULT_ALIAS :
		case _RESULT_VPTR  :
		case _RESULT_VARB  :
			tptr = variable_rvalue( rptr->contents );
			break;
		}
	if ( tptr == (BPTR) 0 )
		return( "666" );
	else	return( tptr );
}

/*	--------------	*/
/*	generate_error	*/
/*	--------------	*/
WORD	generate_error(RESULTPTR vptr) 
{
	return( generate_rtl_error( integer_from_resultptr( vptr ) ) );
}

/*	----------------	*/
/*	generate_ldgoseg	*/
/*	----------------	*/
WORD	generate_ldgoseg(BPTR rptr,WORD type,WORD offset) 
{ 
	generate_indentation( Output );
	fprintf(Output->handle,"if ((_rtl_status = (*_rtl_segment[%s])()) != 0)",rptr);
	open_accolade(Output);
	generate_indentation( Output );
	fprintf(Output->handle,"%s;\n",_RTL_RAISE_ERROR);
	close_accolade(Output);
	return(0); 
}

/*	---------------------	*/
/*	generate_ldgoseg_name	*/
/*	---------------------	*/
WORD	generate_ldgoseg_name(BPTR nptr) 
{ 
	generate_indentation( Output );
	fprintf(Output->handle,"if ((_rtl_status = segment_%s()) != 0)\n",nptr);
	Output->indentation++;
	generate_indentation( Output );
	fprintf(Output->handle,"%s;\n",_RTL_RAISE_ERROR);
	Output->indentation--;
	return(0); 
}

/*	-------------	*/
/*	generate_next	*/
/*	-------------	*/
WORD	generate_next()
{
	close_accolade( Output );
	return( 0 );
}

/*	------------	*/
/*	generate_for	*/
/*	------------	*/
WORD	generate_for( TCVARPTR vptr, BPTR iptr, BPTR cptr, BPTR sptr )
{
	WORD	status;
	trace("generate_for()\n");
	generate_indentation( Output );
	fprintf(Output->handle,"for (\t");
	switch ((vptr->type->type & _TYPE_BASIC)) 
	{
	case _TYPE_INT8 : 
		if ((status = generate_int8_affectation( vptr, iptr, 0)) != 0)
			return( status );
		else	break;
		
	case _TYPE_INT16 : 
		if ((status = generate_int16_affectation( vptr, iptr, 0)) != 0)
			return( status );
		else	break;

	case _TYPE_INT32 : 
		if ((status = generate_int32_affectation( vptr, iptr, 0)) != 0)
			return( status );
		else	break;

	case _TYPE_INT64 : 
		if ((status = generate_int64_affectation( vptr, iptr, 0)) != 0)
			return( status );
		else	break;

	case _TYPE_NUMERIC : 
		if ((status = generate_bcd_affectation( vptr, iptr, 0)) != 0)
			return( status );
		else	break;

	case _TYPE_STRING : 
		if ((status = generate_string_affectation( vptr, iptr, 0)) != 0)
			return( status );
		else	break;
	}
	fprintf(Output->handle,";\n");
	trace("generate_to()\n");
	Output->indentation++;
	generate_indentation( Output );
	fprintf(Output->handle,"%s;\n",EvaluateComparison(_CMP_LE,"\0",variable_rvalue( vptr ),cptr,_LOGICAL_END,0));
	trace("generate_step()\n");
	generate_indentation( Output );
	Output->indentation--;

	if ( sptr == (BPTR) 0 )
		sptr = "1";

	switch ((vptr->type->type & _TYPE_BASIC))
	{
	case _TYPE_INT8  : 
		if ((status = generate_int8_affectation( vptr,VariableArithmetic('+',vptr, sptr), 0)) != 0)
			return( status );
		else	break;
		
	case _TYPE_INT16 : 
		if ((status = generate_int16_affectation( vptr,VariableArithmetic('+',vptr, sptr), 0)) != 0)
			return( status );
		else	break;

	case _TYPE_INT32 : 
		if ((status = generate_int32_affectation( vptr,VariableArithmetic('+',vptr, sptr), 0)) != 0)
			return( status );
		else	break;

	case _TYPE_INT64 : 
		if ((status = generate_int64_affectation( vptr,VariableArithmetic('+',vptr, sptr), 0)) != 0)
			return( status );
		else	break;

	case _TYPE_NUMERIC : 
		if ((status = generate_bcd_affectation( vptr,VariableArithmetic('+',vptr, sptr), 0)) != 0)
			return( status );
		else	break;

	case _TYPE_STRING : 
		if ((status = generate_string_affectation( vptr,VariableArithmetic('+',vptr, sptr), 0)) != 0)
			return( status );
		else	break;

	}
		
	fprintf(Output->handle,") ");
	generate_open_accolade( Output );
	return( 0 );
}

/*	--------------	*/
/*	generate_pause	*/
/*	--------------	*/
WORD	generate_pause(RESULTPTR rptr)
{ 
	generate_indentation( Output );
	return(generate_rtl_pause(rptr)); 
}

/*	------------------	*/
/*	activate_procedure	*/
/*	------------------	*/
WORD	activate_procedure(TCPRCPTR pptr, RESULTPTR rptr, TCPRCPTR sigptr )
{
	return( activate_rtl_procedure( pptr, rptr, pptr ) );
}

/*	-------------	*/
/*	IntegerResult	*/
/*	-------------	*/
BPTR	IntegerResult( WORD v  )
{
	BPTR	tptr;
	if ((tptr = allocate_for_tnode(16)) != (BPTR) 0)
		sprintf(tptr,"%u",v);
	return( tptr );
}

/*
 *	C O L L E C T _ D I M E N S I O N S ()
 *	--------------------------------------
 *
 *	This function is called from :
 *
 *		TRSYMBOL.is_variable()
 *
 *	in order to collect any dimensioning and structural 
 *	extensions for all variable operands.
 *
 *	NB: See also "variable_operand()" above for CLF6 targets.
 *
 */

TCVARPTR	collect_dimensions( TCVARPTR vptr )
{	
	BPTR	rptr;

	while (1) {

		/* Detect Dimensioned Variable */
		/* --------------------------- */
		if (( vptr->type->type & 0x0040 )
		&&  ( is_left_brace() )) {

			/* Evaluate First Dimension Expression */
			/* ----------------------------------- */
			if ((rptr = IntegerExpression()) == (BPTR) 0) {
				(void) syntax_error();
				return( vptr );
				}
			vptr->firstdim = (VPTR) rptr;

			/* Detect Secondary Dimensions */
			/* --------------------------- */
			if (( vptr->type->type & 0x0020 )
			&&  ( is_comma() )) {

				/* Evaluate Secondary Dimension Expression */
				/* --------------------------------------- */
				if ((rptr = IntegerExpression()) == (BPTR) 0) {
					(void) syntax_error();
					return( vptr );
					}
				vptr->secondim = (VPTR) rptr;
				}

			if (!( is_right_brace() ))
				(void) unmatched_braces();
			}

		/* Detect and Resolve Structural Elements */
		/* -------------------------------------- */
		if (( vptr->type->type & 0x0010 )
		&&  ( is_period() )
		&&  ((vptr = resolve_structure_member( vptr )) != (TCVARPTR) 0))
			continue;
		else	return( vptr );
		}
}

TCVARPTR	VariableOperand()
{
	TCVARPTR	vptr;

	/* Locate Potential and Expected Variable Identifier */
	/* ------------------------------------------------- */
	if ((vptr = get_variable(1)) != (TCVARPTR) 0) {

		/* Detect and Resolve Structure Member Componants */
		/* ---------------------------------------------- */
		while (( vptr->type->type & 0x0010 )
		   &&  ( is_period()               ))
			if ((vptr = resolve_structure_member( vptr )) == (TCVARPTR) 0)
				break;

		/* Return Variable Result */
		/* ---------------------- */
		return( vptr );
		}

	else	return( (TCVARPTR) 0 );
}


VOID	commented_source_line( lptr )
BPTR	lptr;
{
	WORD	nombre=0;
	WORD	c;
	trace("commented_source_line()\n");
	if (( lptr != (BPTR) 0 )
	&& ( strlen( lptr ) != 0 )
	&& ( Output != (CFILEPTR) 0 )
	&& ( Output->handle != (FILEPTR) 0)) {
		generate_indentation( Output );
		fprintf(Output->handle,"/* ");
		while (1) {
			switch ((c = *(lptr++))) {
				case	'\r' :
				case	'\n' :
				case	0    :
				case	MOINS_UN :
					break;
				case	'\t' :
					c = ' ';
				default	     :
					fprintf(Output->handle,"%c",c);
					nombre++;
					continue;
				}
			break;
			}
		fprintf(Output->handle," */\n");
		generate_indentation( Output );
		fprintf(Output->handle,"/* ");
		for ( ;nombre != 0; nombre-- ) 
			fprintf(Output->handle,"-");
		fprintf(Output->handle," */\n");
		}
	trace("fof()\n");
	return;
}

WORD	RtlExitValue( xptr, type )
BPTR	xptr;
WORD	type;
{
	BPTR	rptr;
	switch ( type ) {
		case	0 :
		case	1 :
			generate_indentation( Output );
			fprintf(Output->handle,"AVMV(53)  = %s;",xptr);
			generate_indentation( Output );
			fprintf(Output->handle,"AVMT(53) = 1; \n");
			break;
		case	2 :
			if ((rptr = NewBcdRegister()) == (BPTR) 0)
				return( allocation_failure() );
			generate_indentation( Output );
			fprintf(Output->handle,"bcd_copy(%s,%s);\n",xptr,rptr);
			generate_indentation( Output );
			fprintf(Output->handle,"AVMP(53) = AVMP(%u);\n",RtlRegisters);
			generate_indentation( Output );
			fprintf(Output->handle,"AVML(53) = AVML(%u); \n",RtlRegisters);
			generate_indentation( Output );
			fprintf(Output->handle,"AVMT(53) = 2; \n");
			break;
		case 3 :
			if ((rptr = NewStringRegister(0)) == (BPTR) 0)
				return( allocation_failure() );
			generate_indentation( Output );
			fprintf(Output->handle,"AVML(%u) = clf_length(%s); \n",RtlRegisters,xptr);
			RtlAdjustAllocator();
			generate_indentation( Output );
			fprintf(Output->handle,"string_copy(%s,%s);\n",xptr,rptr);
			generate_indentation( Output );
			fprintf(Output->handle,"AVMP(53) = AVMP(%u);\n",RtlRegisters);
			generate_indentation( Output );
			fprintf(Output->handle,"AVML(53) = AVML(%u); \n",RtlRegisters);
			generate_indentation( Output );
			fprintf(Output->handle,"AVMT(53) = 3; \n");
			break;
		}
	
	return( 0 );
}

PRCPTR	start_prc(TCPRCPTR l, TCTYPPTR r)
{
	return((VPTR) 0);
}


VOID	liberate_clp( PRCPTR vptr )
{
	return;
}

WORD	flush_clp( PRCPTR vptr )
{
	return( syntax_error(24056) );
}

WORD	store_clp( PRCPTR vptr, BPTR rptr, WORD mode )
{
	return( syntax_error( 25056 ) );
}

WORD	implicite_label( n )
WORD	n;
{
	return( 0 );
}

WORD		generate_rtl_funcptr( vptr, id )
TCVARPTR	vptr;
WORD		id;
{
	generate_indentation( Output );
	fprintf(Output->handle,"clf_funcptr(%s,stub%u);\n",generate_pointer_adresse(vptr),id);
	return(0);

}

WORD		generate_rtl_segmptr( vptr, id )
TCVARPTR	vptr;
WORD		id;
{
	generate_indentation( Output );
	fprintf(Output->handle,"clf_segmptr(%s,stub%u);\n",generate_pointer_adresse(vptr),id);
	return(0);

}

WORD		generate_rtl_alias( tptr, sptr )
TCVARPTR	tptr;
TCVARPTR	sptr;
{
	generate_indentation( Output );
	fprintf(Output->handle,"clf_aliasptr(%s,%s);\n",
				generate_pointer_adresse(tptr),	
				generate_pointer_adresse(sptr));
	return(0);

}

WORD		generate_rtl_create( tptr )
TCVARPTR	tptr;
{
	generate_indentation( Output );
	fprintf(Output->handle,"clf_create(%s,%u,%u,%u);\n",
				generate_pointer_adresse(tptr),	
				tptr->type->size,
				tptr->type->first,
				tptr->type->second);

	return(0);

}

WORD		generate_rtl_remove( tptr )
TCVARPTR	tptr;
{
	generate_indentation( Output );
	fprintf(Output->handle,"clf_remove(%s,%u,%u,%u);\n",
				generate_pointer_adresse(tptr),	
				tptr->type->size,
				tptr->type->first,
				tptr->type->second);

	return(0);

}

WORD		generate_rtl_forget( tptr )
TCVARPTR	tptr;
{
	generate_indentation( Output );
	fprintf(Output->handle,"clf_forget(%s,%u,%u,%u);\n",
				generate_pointer_adresse(tptr),	
				tptr->type->size,
				tptr->type->first,
				tptr->type->second);

	return(0);

}

#endif	/* _TRGENC_C */
	/* --------- */

