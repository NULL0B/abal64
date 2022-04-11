#ifndef	_abalsynt_c
#define	_abalsynt_c

/*	------------------------------------------------------		*/
/*	ABAL Specific Language construction generation methods 		*/
/*	------------------------------------------------------		*/

public	void	abal_pragma_enter( FILE * h,char * mptr, char * nptr )
{
	fprintf(h,"%s %s ",__abal_keyword_pragma,__abal_keyword_enter);
	if ( mptr )
		fprintf(h,"%s",mptr);
	if ( nptr )
		fprintf(h,".%s",nptr);
	linefeed(h);
	return;
}

public	void	abal_pragma_leave( FILE * h,char * mptr, char * nptr )
{
	fprintf(h,"%s %s ",__abal_keyword_pragma,__abal_keyword_leave);
	if ( mptr )
		fprintf(h,"%s",mptr);
	if ( nptr )
		fprintf(h,".%s",nptr);
	linefeed(h);
	return;
}

public	void	abal_comment( FILE * handle, char * vptr , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,";** %s ",vptr);
	linefeed(handle);
	return;
}

public	void	abal_banner(FILE * h, char * token )
{
	int	tokenlen;
	int	i;

	if (!( token ))					return;
	else if (!( tokenlen =strlen( token ) ))	return;
	else	tokenlen *= 2;

	fprintf(h,"\r\n;**\t"); for (i=0; i < tokenlen; i++ ) fprintf(h,"-");
	fprintf(h,"\r\n;**\t"); while ( *token ) fprintf(h,"%c ",*(token++));
	fprintf(h,"\r\n;**\t"); for (i=0; i < tokenlen; i++ ) fprintf(h,"-");
	return;
}

public	void	abal_label( FILE * handle, char * lptr )
{
	fprintf(handle,"&%s",lptr);
	linefeed(handle);
	return;
}

public	void	abal_keyword( FILE * handle, int indentation, char * kptr )
{
	indent(handle,indentation);
	fprintf(handle,"%s",kptr);
	linefeed(handle);
	return;
}



/*	-----------------	*/
/*	IF / ELSE / ENDIF	*/
/*	-----------------	*/

public  void	abal_if( FILE * h, int indentation, char * expression )
{
	indent(h,indentation);
	fprintf(h,"%s(%s)",__abal_keyword_if,expression);
	linefeed(h);
	return;
}

public	void	abal_else( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_else);	}

public	void	abal_endif( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_endif);	}

public	void	abal_gosub( FILE * handle, char * label , int indentation )
{	
	indent(handle,indentation);
	fprintf(handle,"%s %s",__abal_keyword_gosub,label);
	linefeed(handle);
	return;
}

public	void	abal_endloc( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_endloc);	}

/*	----------------------------	*/
/*	DO / BREAK / CONTINUE / LOOP	*/
/*	----------------------------	*/
public	void	abal_do( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_do);	}

public	void	abal_break( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_break);	}

public	void	abal_continue( FILE * handle, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"%s &%s",__abal_keyword_goto,__abal_keyword_continue);
	linefeed(handle);
	return;
}

public	void	abal_retry( FILE * handle, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"%s &%s",__abal_keyword_goto,__abal_keyword_retry);
	linefeed(handle);
	return;
}

public	void	abal_loop( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_loop);	}

/*	--------------		*/
/*	INCLUDE / USER		*/
/*	--------------		*/

public	void	abal_include( FILE * handle, char * sptr )
{
	fprintf(handle,"%s ",keyword_include);
	if (( *sptr != '<' )
	&&  ( *sptr != '"' ))
		quoted_string(handle,sptr);
	else	fprintf(handle,"%s",sptr);
	linefeed(handle);
	return;
}
public	void	abal_user( FILE * handle, char * sptr )
{
	fprintf(handle,"%s ",keyword_user);
	if (( *sptr != '<' )
	&&  ( *sptr != '"' ))
		quoted_string(handle,sptr);
	else	fprintf(handle,"%s",sptr);
	linefeed(handle);
	return;
}

/*	----------------------	*/
/*	PROGRAM / MODULE / END	*/
/*	----------------------	*/

public	void	abal_program( FILE * handle, char * sptr )
{
	fprintf(handle,"%s ",__abal_keyword_program);
	if ( *sptr != '"' )
		quoted_string(handle,sptr);
	else	fprintf(handle,"%s",sptr);
	fprintf(handle,",NOCLR");
	linefeed(handle);
	return;
}

public	void	abal_module( FILE * handle, char * sptr )
{
	fprintf(handle,"%s ",__abal_keyword_module);
	if ( *sptr != '"' )
		quoted_string(handle,sptr);
	else	fprintf(handle,"%s",sptr);
	linefeed(handle);
	return;
}

public	void	abal_end( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_end);	}

/*	-----------	*/
/*	DCL / FIELD	*/
/*	-----------	*/

public	void	abal_variable( FILE * h,
	int	datatype,
	int	length,
	int	first, int second )
{
	switch ( datatype ) {
		case	_ABAL_BYTE 	:
			fprintf(h,"#"); break;
		case	_ABAL_WORD 	:
			fprintf(h,"%c",0x0025); break;
		case	_ABAL_BCD  	:
			fprintf(h,"=%u",length); break;
		case	_ABAL_STRING 	:
			fprintf(h,"$=%u",length); break;
		case	_ABAL_PROC	:
			break;
		}
	if ( first ) {
		fprintf(h,"(%u",first);
		if ( second )
			fprintf(h,",%u",second);
		fprintf(h,")");
		}
	linefeed(h);
	return;
}

public	void	abal_ptr( FILE * h,
	char * 	prefix, char* postfix,
	int	datatype,
	int	length,
	int	first, int second )
{
	if ( datatype != _ABAL_PROC )
		fprintf(h,"%s\t%s%s",__abal_keyword_ptr,prefix,postfix);
	else	fprintf(h,"%s %s %s%s",__abal_keyword_ptr,__abal_keyword_proc,prefix,postfix);
	abal_variable( h, datatype, length, first, second );
	return;
}

public	void	abal_dcl( FILE * h,
	char * 	prefix, char* postfix,
	int	datatype,
	int	length,
	int	first, int second )
{
	if ( datatype != _ABAL_PROC )
		fprintf(h,"%s\t%s%s",__abal_keyword_dcl,prefix,postfix);
	else	fprintf(h,"%s %s %s%s",__abal_keyword_dcl,__abal_keyword_proc,prefix,postfix);
	abal_variable( h, datatype, length, first, second );
	return;
}

public	void	abal_arg( FILE * h,
	char * 	prefix, char* postfix,
	int	datatype,
	int	length,
	int	first, int second )
{
	abal_dcl(h,prefix,postfix,datatype,length,first,second);
	fprintf(h,"Arg\t%s%s",prefix,postfix);
	linefeed(h);
	return;
}

public	void	abal_integer_constant( FILE * h,
	char * 	prefix, char* postfix,
	int	value )
{
	fprintf(h,"%s %s%s%c=%u",
		__abal_keyword_const,
		prefix,postfix,0x0025,value);
	linefeed(h);
	return;
}

public	void	abal_string_constant( FILE * h,
	char * 	prefix, char* postfix,
	char * 	value )
{
	fprintf(h,"%s %s%s$=",__abal_keyword_const,prefix,postfix);
	string_value(h,value);
	linefeed(h);
	return;
}

public	void	abal_field(FILE * h, char * prefix, char * vname )
{
	fprintf(h,__abal_keyword_field_m);
	if ( prefix ) {
		fprintf(h,",%s",prefix);
		if ( vname )
			fprintf(h,"%s",vname);
		}
	linefeed(h);
	return;
}

public	void	abal_vfield(FILE * h, int id)
{
	fprintf(h,"Field=%u",id);
	linefeed(h);
	return;
}

public	void	abal_filler(FILE * h, int length )
{
	if ( length ) {
		fprintf(h,"%s %s",__abal_keyword_dcl,__abal_keyword_filler);
		fprintf(h,"=%u",length);
		linefeed(h);
		}
	return;
}

/*	--------------------	*/
/*	PROC / EXIT/ ENDPROC	*/
/*	--------------------	*/

public  void	abal_procedure( FILE * h, char * prefix, char * nptr, int members, struct form_control * fptr)
{
	int	i;
	int	j=0;
	fprintf(h,"%s %s%s(",__abal_keyword_proc,prefix,nptr);

	if (( Abal_Config.generate_program )
	&&  ( Abal_Config.generate_overlay )) {
		fprintf(h,"%s",__abal_overlay_object);
		j=1;
		}

	if ( members != 0 ) {
		if (!( fptr )) { 		
			for (i=0; i < members; i++ ) {
				if (!( i+j ))
					fprintf(h,"%s pp%u$",__abal_keyword_ptr,i);
				else	fprintf(h,",%s pp%u$",__abal_keyword_ptr,i);
				}
			}
		else	construction_parameters( h, fptr, 0 );
		}

	fprintf(h,") : %c ",0x0025);
	linefeed(h);
	return;
}

public  void	abal_endproc( FILE * h)
{
	fprintf(h,__abal_keyword_endproc);
	linefeed(h);
	return;
}

/*	------------------------	*/
/*	SEGMENT / RET.SEG / ESEG 	*/
/*	------------------------	*/
public  void	abal_segment( FILE * h, char * vptr)
{
	fprintf(h,"%s %s",__abal_keyword_segment,vptr);
	linefeed(h);
	return;
}

public	void	abal_retseg( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_retseg);	}

public  void	abal_endseg( FILE * h, char * vptr)
{
	fprintf(h,"%s %s",__abal_keyword_eseg,vptr);
	linefeed(h);
	return;
}

/*	-------------	*/
/*	STOP / RETURN	*/
/*	-------------	*/

public	void	abal_stop( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_stop);	}

public	void	abal_error( FILE * handle, char * vptr , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"%s %s",__abal_keyword_error,vptr);
	linefeed(handle);
	return;
}

public	void	abal_raise( FILE * handle, int v , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"%s %d",__abal_keyword_error,v);
	linefeed(handle);
	return;
}

public	void	abal_return( FILE * handle, char * vptr , int indentation )
{
	indent(handle,indentation);
	if (!( vptr ))
		fprintf(handle,__abal_keyword_exit,vptr);
	else	fprintf(handle,"%s(%s)",__abal_keyword_exit,vptr);
	linefeed(handle);
	return;
}

public	void	abal_returni( FILE * handle, int v , int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"%s(%d)",__abal_keyword_exit,v);
	linefeed(handle);
	return;
}

/*	------------	*/
/*	WHILE / WEND	*/
/*	------------	*/

public  void	abal_while( FILE * h, int indentation, char * expression )
{
	indent(h,indentation);
	fprintf(h,"%s(%s)",__abal_keyword_while,expression);
	linefeed(h);
	return;
}

public	void	abal_wend( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_wend);	}

public	void	abal_repeat( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_repeat);	}


/*	-------------------------------		*/
/*	SELECT / CASE /DEFAULT / ENDSEL		*/
/*	-------------------------------		*/

public  void	abal_select( FILE * h, char * expression, int indentation )
{
	indent(h,indentation);
	fprintf(h,"%s(%s)",__abal_keyword_select,expression);
	linefeed(h);
	return;
}

public	void	abal_case( FILE * handle, int value, int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"%s\t%d",__abal_keyword_case,value);
	linefeed(handle);
	return;
}

public	void	abal_cases( FILE * handle, char * values,int indentation )
{
	indent(handle,indentation);
	fprintf(handle,"%s\t%s",__abal_keyword_case,values);
	linefeed(handle);
	return;
}

public	void	abal_default( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_default);	}


public	void	abal_endsel( FILE * handle, int indentation )
{	abal_keyword(handle,indentation,__abal_keyword_endsel);	}

#endif /* _abalsynt_c */

