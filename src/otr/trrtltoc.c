#ifndef _TRRTLTOC_C
#define _TRRTLTOC_C

	
PRIVATE WORD    OutputStatus=VRAI;
PRIVATE WORD    Indentation=0;
PRIVATE WORD    Indentations[4];
PRIVATE WORD    RtlActive=0;
PRIVATE FILEPTR RtlBody=(FILEPTR) 0;
PRIVATE FILEPTR RtlHead=(FILEPTR) 0;
PRIVATE FILEPTR RtlFoot=(FILEPTR) 0;
PRIVATE FILEPTR RtlOutput=(FILEPTR) 0;
PRIVATE WORD    TcodeLabel=0;
PRIVATE WORD    RtlCaseCount=0;

EXTERN  BPTR    get_target_root();


PUBLIC  VOID    rtl_cancel_output()
{
	OutputStatus = 0;
	return;
}

PUBLIC  VOID    rtl_activate_output()
{
	OutputStatus = 1;
	return;
}


PUBLIC  FILEPTR rtl_get_target()
{
	return( RtlOutput );
}

PUBLIC  VOID    rtl_set_target( tptr )
	FILEPTR tptr;
{
	RtlOutput = tptr;
	return;
}

PUBLIC  VOID    rtl_putb(c)
	WORD    c;
{
	if (!( OutputStatus )) return;
	if ( RtlOutput != (FILEPTR) 0 )
		fprintf(RtlOutput,"%c",(int)(c & 0x00FF));
	if ( OtrOption.TargetTrace )
		sysprintf("%c",(int)(c & 0x00FF));
	return;
}

PUBLIC  VOID    rtl_puts(sptr)
	BPTR    sptr;
{
	if (!( OutputStatus )) return;
	if ( RtlOutput != (FILEPTR) 0 )
		fprintf(RtlOutput,"%s",sptr);
	if ( OtrOption.TargetTrace )
		sysprintf("%s",sptr);

	return;
}

PUBLIC  VOID    rtl_putptr()
{
	rtl_puts(_RTL_PTR);
	return;
}

PUBLIC  VOID    rtl_putu(v)
	WORD    v;
{
	if (!( OutputStatus )) return;
	if ( RtlOutput != (FILEPTR) 0 )
		fprintf(RtlOutput,"%llu",v);
	if ( OtrOption.TargetTrace )
		sysprintf("%llu",v);
	return;
}

PUBLIC  VOID    rtl_putd(v)
	WORD    v;
{
	if (!( OutputStatus )) return;
	if ( RtlOutput != (FILEPTR) 0 )
		fprintf(RtlOutput,"%lld",v);
	if ( OtrOption.TargetTrace )
		sysprintf("%lld",v);
	return;
}

PUBLIC  VOID    rtl_putx(v)
	WORD    v;
{
	BYTE    buffer[16];
	WORD    i;
	if (!( OutputStatus )) return;
	sprintf(buffer,"0x%4.1llX",v);
	for ( i = 0; i < strlen(buffer); i++ )
		if ( buffer[i] == ' ')
			buffer[i] = '0';
	if ( RtlOutput != (FILEPTR) 0 )
		fprintf(RtlOutput,"%s",buffer);
	if ( OtrOption.TargetTrace )
		sysprintf("%s",buffer);
	return;
}

PUBLIC  VOID    rtl_putxb(v)
	WORD    v;
{
	BYTE    buffer[16];
	WORD    i;
	if (!( OutputStatus )) return;
	sprintf(buffer,"0x%2.1llX",v);
	for ( i = 0; i < strlen(buffer); i++ )
		if ( buffer[i] == ' ')
			buffer[i] = '0';
	if ( RtlOutput != (FILEPTR) 0 )
		fprintf(RtlOutput,"%s",buffer);
	if ( OtrOption.TargetTrace )
		sysprintf("%s",buffer);
	return;
}

PUBLIC  VOID    rtl_linefeed()
{
	rtl_putb('\n');
	return;
}

PUBLIC  VOID    rtl_indentation()
{
	WORD    i;
	for (i=0; i < Indentation; i++)
		rtl_putb('\t');
	return;
}

PUBLIC  VOID    rtl_label( offset )
	WORD    offset;
{
	BYTE    label[32];
	WORD    i;
	sprintf(label,"$L%16.1llX",offset );
	for (i=0; label[i] != 0; i++ )
		if ( label[i] == ' ' )
			label[i] = '0';
	rtl_puts( label );
	return;
}

PUBLIC  VOID    rtl_flushline()
{
	rtl_linefeed();
	if ( TcodeLabel != MOINS_UN ) {
		rtl_label( TcodeLabel );
		rtl_colon;
		TcodeLabel = MOINS_UN;
		}
	rtl_indentation();
	return;
}

PUBLIC  VOID    rtl_start_comment()
{
	if ( get_pragma_output() > 0 )
		rtl_puts("// ");
	else    rtl_puts("/* ");
	return;
}

PUBLIC  VOID    rtl_close_comment()
{
	if (!(get_pragma_output()))
		rtl_puts(" */"); 
	rtl_linefeed();
	return;
}


PUBLIC  VOID    rtl_comment( mptr )
	BPTR    mptr;
{
	WORD    i;
	rtl_linefeed(); rtl_indentation();
	rtl_start_comment();
	for (i=0; i < strlen(mptr); i++)
		rtl_putb( '-');
	rtl_close_comment();
	rtl_indentation();
	rtl_start_comment();
	rtl_puts( mptr );
	rtl_close_comment();
	rtl_indentation();
	rtl_start_comment();
	for (i=0; i < strlen(mptr); i++)
		rtl_putb( '-');
	rtl_close_comment();
	return;
}

PUBLIC  VOID    rtl_call_function( nptr, pptr )
	BPTR    nptr;
	BPTR    pptr;
{
	rtl_puts( nptr );
	rtl_leftbrace;
	rtl_puts( pptr );
	rtl_rightbrace;
	return;
}

PUBLIC  VOID    rtl_void_function( nptr )
	BPTR    nptr;
{
	rtl_call_function(nptr, "\0");
	return;
}

PUBLIC  VOID    rtl_statement( nptr, pptr )
	BPTR    nptr;
	BPTR    pptr;
{
	rtl_flushline();
	rtl_call_function( nptr, pptr );
	rtl_semicolon;
	return;
}

PUBLIC  VOID    rtl_typed_statement( nptr,type, pptr )
	BPTR    nptr;
	BPTR    pptr;
{
	rtl_flushline();
	rtl_puts( nptr );
	switch ( type ) {
		case    _TYPE_INT8    :
			rtl_putb('_'); rtl_puts("byte"); break;
		case    _TYPE_INT16   :
			rtl_putb('_'); rtl_puts("word"); break;
		case    _TYPE_NUMERIC :
			rtl_putb('_'); rtl_puts("long"); break;
		case    _TYPE_STRING  :
			rtl_putb('_'); rtl_puts("string"); break;
		}
	rtl_leftbrace;
	rtl_puts( pptr );
	rtl_rightbrace;
	rtl_semicolon;
	return;
}

PUBLIC  VOID    rtl_void_statement( nptr )
	BPTR    nptr;
{
	rtl_statement(nptr, "\0");
	return;
}

PUBLIC  VOID    rtl_gosub( label )
	WORD    label;
{
	rtl_flushline();
	rtl_puts( _RTL_GOSUB );
	rtl_leftbrace;
	rtl_label( label );
	rtl_rightbrace;
	rtl_semicolon;
	return;
}

PUBLIC  VOID    rtl_goto( label )
	WORD    label;
{
	rtl_flushline();
	rtl_puts( _RTL_GOTO );
	rtl_space;
	rtl_label( label );
	rtl_semicolon;
	return;
}

PUBLIC  VOID    rtl_set_label( offset )
	WORD    offset;
{
	if ( TcodeLabel == MOINS_UN )
		TcodeLabel = offset;
	return;
}

PUBLIC  VOID    rtl_compare( lptr, optr, rptr, label )
	BPTR    lptr;
	BPTR    optr;
	BPTR    rptr;
	WORD    label;
{
	rtl_flushline();
	rtl_puts("if"); rtl_space; rtl_leftbrace; rtl_leftbrace;
	rtl_puts( lptr );
	rtl_rightbrace;
	rtl_puts( optr );
	rtl_leftbrace;
	rtl_puts( rptr );
	rtl_rightbrace;
	rtl_rightbrace;
	Indentation++;
	rtl_goto(label);
	Indentation--;
	return;
}

PUBLIC  VOID    rtl_affectation( lptr, rptr )
	BPTR    lptr;
	BPTR    rptr;
{
	rtl_flushline();
	rtl_puts( lptr );
	rtl_equals;
	rtl_puts( rptr );
	rtl_semicolon;
	return;
}

PUBLIC  VOID    rtl_enter(mode)
	WORD    mode;
{
	rtl_leftaccolade;
	if ( mode ) Indentation++;
	return;
}

PUBLIC  VOID    rtl_leave(mode)
	WORD    mode;
{
	rtl_rightaccolade;
	if ( mode ) if ( Indentation ) Indentation--;
	return;
}

PUBLIC  VOID    rtl_start_block()
{
	Indentation = 0;
	rtl_linefeed();
	rtl_enter(1);
	return;
}




PUBLIC  VOID    rtl_close_block()
{
	Indentation = 0;
	rtl_linefeed();
	rtl_leave(0);
	return;
}

PUBLIC  VOID    rtl_dimensions(n)
	WORD    n;
{
	rtl_putb('[');
	rtl_putu(n);
	rtl_putb(']');
	return;
}

PUBLIC  VOID    rtl_switch( xptr )
	BPTR    xptr;
{
	rtl_flushline();
	rtl_puts( _RTL_SWITCH );
	rtl_leftbrace;
	rtl_puts( xptr );
	rtl_rightbrace;
	rtl_space;
	rtl_enter(0);
	RtlCaseCount=0;
	return;
}

PUBLIC  VOID    rtl_case( v )
	WORD    v;
{
	if ( RtlCaseCount == 0 )
		Indentation++;
	else    Indentation--;
	rtl_flushline();
	rtl_puts( _RTL_CASE );
	rtl_space;
	rtl_putu( v );
	rtl_space;
	rtl_colon;
	RtlCaseCount++;
	Indentation++;
	return;
}

PUBLIC  VOID    rtl_endswitch( )
{
	if ( RtlCaseCount )
		Indentation--;
	else    Indentation++;
	rtl_flushline();
	rtl_leave(0);
	Indentation--;
	RtlCaseCount = 0;
	return;
}

PUBLIC  VOID    rtl_throw( xptr )
	BPTR    xptr;
{
	rtl_flushline();
	rtl_puts( _RTL_THROW );
	rtl_leftbrace;
	rtl_puts( xptr );
	rtl_rightbrace;
	rtl_semicolon;
	return;
}

PUBLIC  VOID    rtl_return( xptr )
	BPTR    xptr;
{
	rtl_flushline();
	rtl_puts( "return" );
	if ( xptr != (BPTR) 0) {
		rtl_leftbrace;
		rtl_puts( xptr );
		rtl_rightbrace;
		}
	rtl_semicolon;
	return;
}



PRIVATE VOID    rtl_symbol( nptr )
	BPTR    nptr;
{
	WORD    c;
	rtl_putb('_');
	while ( *nptr ) {
		switch ((c = *(nptr++))) {
			case    '.' :   c = '_';
			default     :   rtl_putb(c);
			}
		}
	return;
}

PRIVATE VOID    rtl_include( fptr, nptr )
	FILEPTR fptr;
	BPTR    nptr;
{
	if ( fptr != (FILEPTR) 0 )
		fprintf(fptr,"\n#include %c%s%c\n",0x0022,nptr,0x0022);
	return;
}

PRIVATE VOID    rtl_dependance( nptr, xptr )
	BPTR    nptr;
	BPTR    xptr;
{
	rtl_linefeed();
	rtl_puts("#include");
	rtl_space;
	rtl_putb(0x0022);
	rtl_puts(nptr );
	rtl_puts(xptr );
	rtl_putb(0x0022);
	rtl_linefeed();
	return;
}

PUBLIC  VOID    rtl_ifndef( nptr )
	BPTR    nptr;
{
	rtl_linefeed();
	rtl_puts("#ifndef ");
	rtl_symbol( nptr );
	return;
}

PUBLIC  VOID    rtl_else()
{
	rtl_linefeed();
	rtl_puts("#else");
	return;
}

PUBLIC  VOID    rtl_endif()
{
	rtl_linefeed();
	rtl_puts("#endif");
	return;
}

PUBLIC  VOID    rtl_define( nptr, vptr )
	BPTR    nptr;
	BPTR    vptr;
{
	rtl_linefeed();
	rtl_puts("#define ");
	rtl_symbol( nptr );
	rtl_space;
	rtl_puts( vptr );

	return;
}

PRIVATE FILEPTR rtl_close_file( fptr )
	FILEPTR fptr;
{
	if ( fptr != (FILEPTR) 0 ) {
		if ( OtrOption.TargetTrace )
			sysprintf("\nRtl File Closure\n");

		rtl_set_target( fptr );
		rtl_activate_output();
		rtl_endif();
		rtl_comment("End of File");
		rtl_linefeed();
		rtl_cancel_output();
		rtl_set_target( (FILEPTR) 0 );
		fclose( fptr );
		}
	return((FILEPTR) 0 );
}

PRIVATE FILEPTR rtl_start_file( nptr )
	BPTR    nptr;
{
	FILEPTR fptr=(FILEPTR) 0;
	if ((fptr = fopen(nptr,"w")) != (FILEPTR) 0) {
		if ( OtrOption.TargetTrace )
			sysprintf("\nRtl Start File %s\n",nptr);
		rtl_set_target( fptr );
		rtl_ifndef( nptr );
		rtl_define( nptr, "\0" );
		rtl_comment("Warning : This file has been generated by OTR/ATOC");
		}
	return( fptr );
}

PRIVATE VOID    rtl_dieze_constants()
{
	BYTE    buffer[32];
	if (!( context_is_module )) {
		sprintf(buffer,"%llu",Context->DiezeFiles);
		rtl_define("dieze_files",buffer);
		sprintf(buffer,"%llu",Context->DiezeStack);
		rtl_define("dieze_stack",buffer);
		sprintf(buffer,"%llu",Context->DiezeMem);
		rtl_define("dieze_memory",buffer);
		sprintf(buffer,"%u",64);
		rtl_define("dieze_errors",buffer);
		}
	return;
}

PRIVATE WORD    rtl_start_files()
{
	BPTR    rptr;
	BPTR    tptr;
	WORD	i=0;
	Indentations[0] = 0; 
	Indentations[1] = 0; 
	Indentations[2] = 0; 
	Indentations[3] = 0; 
	if ((rptr = get_target_root()) != (BPTR) 0) {
		if ((tptr = allocate_for_tnode( strlen(rptr) + 16 )) != (BPTR) 0) {
			switch ( get_pragma_output() ) {
				case	0 : sprintf(tptr,"%s.h",rptr); break;
				case	1 : sprintf(tptr,"%s.hpp",rptr); break;
				case	2 :
				case	3 : sprintf(tptr,"%s.hjv",rptr); break;
				default	  : sprintf(tptr,"%s.hds",rptr); break;
				}
			if ((RtlHead = rtl_start_file( tptr )) != (FILEPTR) 0) {
				switch ( get_pragma_output() ) {
					case	0 : sprintf(tptr,"%s.f",rptr); break;
					case	1 : sprintf(tptr,"%s.h",rptr); break;
					case	2 :
					case	3 : sprintf(tptr,"%s.hjs",rptr); break;
					default	  : sprintf(tptr,"%s.hfs",rptr); break;
					}
				if ((RtlFoot = rtl_start_file( tptr )) != (FILEPTR) 0) {
					switch ( get_pragma_output() ) {
						case	0 : sprintf(tptr,"%s.c",rptr); break;
						case	1 : sprintf(tptr,"%s.cpp",rptr); break;
						case	2 :
						case	3 : sprintf(tptr,"%s.jav",rptr); break;
						default	  : sprintf(tptr,"%s.bdy",rptr); break;
						}
					if ((RtlBody = rtl_start_file( tptr )) != (FILEPTR) 0) {
						switch ( get_pragma_output() ) {
							case	0 :
								rtl_dieze_constants();
								rtl_include( RtlBody, "otratoc.h" );
								sprintf(tptr,"%s.h",rptr);
								rtl_include( RtlBody, tptr  );
								sprintf(tptr,"%s.f",rptr);
								rtl_include( RtlBody, tptr  );
								break;
							case	1 :
								rtl_include( RtlBody, "otracpp.h" );
								sprintf(tptr,"%s.hpp",rptr);
								rtl_include( RtlBody, tptr  );
								sprintf(tptr,"%s.h",rptr);
								rtl_include( RtlBody, tptr  );
								break;
							}
						return( 1 );
						}
					else    RtlFoot = rtl_close_file( RtlFoot );
					}
				else    RtlHead = rtl_close_file( RtlHead );
				}
			}
		}
	return(0);
}

PUBLIC  WORD    rtl_use_header()
{
	if ( OtrOption.TargetTrace )
		sysprintf("\nRtl Use Head\n");
	Indentations[RtlActive] = Indentation;
	switch ( RtlActive ) {
		case    0       : if (!( rtl_start_files() )) return(0);
		case    2       :
		case    3       : rtl_set_target( RtlHead );
		}
	Indentation = Indentations[1];
	return((RtlActive = 1));
}

PUBLIC  WORD    rtl_use_footer()
{
	if ( OtrOption.TargetTrace )
		sysprintf("\nRtl Use Foot\n");
	Indentations[RtlActive] = Indentation;
	switch ( RtlActive ) {
		case    0       : if (!( rtl_start_files() )) return(0);
		case    1       :
		case    3       : rtl_set_target( RtlFoot );
		}
	Indentation = Indentations[2];
	return((RtlActive = 2));
}

PUBLIC  WORD    rtl_use_body()
{
	if ( OtrOption.TargetTrace )
		sysprintf("\nRtl Use Body\n");
	Indentations[RtlActive] = Indentation;
	switch ( RtlActive ) {
		case    0       : if (!( rtl_start_files() )) return(0);
		case    1       :
		case    2       : rtl_set_target( RtlBody );
		}
	Indentation = Indentations[3];
	return((RtlActive = 3));
}

PUBLIC  WORD    rtl_close_files()
{
	rtl_set_target( (FILEPTR) 0 );
	if ( RtlBody != (FILEPTR) 0 )
		RtlBody = rtl_close_file( RtlBody );
	if ( RtlFoot != (FILEPTR) 0 )
		RtlFoot = rtl_close_file( RtlFoot );
	if ( RtlHead != (FILEPTR) 0 )
		RtlHead = rtl_close_file( RtlHead );
	return(0);
}

PUBLIC  WORD    rtl_get_active() { return( RtlActive ); }

PUBLIC  WORD    rtl_set_active(v)
	WORD    v;
{
	switch ( v ) {
		case    1 : rtl_use_header(); break;
		case    2 : rtl_use_footer(); break;
		case    3 : rtl_use_body(); break;
		}
	return(v);
}


#endif  /* _TRRTLTOC_C */
	/* ----------- */



