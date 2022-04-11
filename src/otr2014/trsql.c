/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Abal Translator    			*/
/*									*/
/*		 Copyright (c) 1990, 2012 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRSQL.C  				*/
/*		Version :	4.1a					*/
/*		Date	:	02/01/2012				*/
/*									*/
/* --------------------------------------------------------------------	*/

#ifndef	_tr_sql_c
#define _trsql_c

/*	----------------------------------------------------------	*/
/*	IJM : 02/01/2012						*/
/*	----------------						*/
/*	Functions introduced to handle ABAL / CRITERIA SQL for the	*/
/*	POSTGRE SQL and MYSQL Version where the service prefix of	*/
/*	the assign will select the appropriate SQL service engine.	*/
/*	----------------------------------------------------------	*/

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ c o n n e c t		*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_connect( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status );
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ b e g i n			*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_begin( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status );
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ c o m m i t			*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_commit( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status );
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ r o l l b a c k		*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_rollback( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status );
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ p r e p a r e		*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_prepare( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = question_result())	== 0 ))
		return( flush_ngf() );
	else	return( status );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ e x e c			*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_exec( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 ))
	{
		if (!( is_comma() ))
			return( syntax_error(4001) );
		else if ( is_left_brace() ) 
		{
			/* the braced prepared request handle : may have parameters */
			/* -------------------------------------------------------- */
			if ((status = store_parameter( integer_result(1) ) ))
				return( status );
			else if ((status = store_parameter( evaluate_expression(0) ) ))
				return( status );
			else if (!( is_right_brace() ))
				return( syntax_error(4002) );
			else if  ((status = ngf_error_trap())	!= 0 )
				return( status );
			else if  ((status = result_format())	!= 0 )
				return( status );
			else
			{
				while ( is_comma() )
					if ((status = store_parameter( evaluate_expression(0) ) ))
						return( status );
				return( flush_ngf() );
			}
		}
		else
		{
			/* the query operand : needs request handle */
			/* ---------------------------------------- */
			if ((status = store_parameter( integer_result(0) ) ))
				return( status );
			else if ((status = store_parameter( evaluate_expression(0) ) ))
				return( status );
			else if ((status = ngf_error_trap())	!= 0 )
				return( status );
			else if ((status = question_result())	!= 0 )
				return( status );
			else if  ((status = result_format())	!= 0 )
				return( status );
			else	return( flush_ngf() );
		}
	}
	else	return( status );

}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ g e t r o w c o l		*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_getrowcol( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = question_result())	== 0 )
	&&  ((status = question_result())	== 0 ))
		return( flush_ngf() );
	else	return( status );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ g e t c o l n a m e		*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_getcolname( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 ))
		return( flush_ngf() );
	else	return( status );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ f e t c h 			*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_fetch( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
	{
		while ( is_comma() )
			if ((status = store_parameter( evaluate_expression(0) ) ))
				return( status );

		return( flush_ngf() );
	}
	else	return( status );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ g e t f i e l d		*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_getfield( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 ))
		return( flush_ngf() );
	else	return( status );
	return(0);
}

/*	----------------------------------------------------------	*/
/*		t r a n s l a t e _ s q l _ d r o p 			*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_drop( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 ))
		return( flush_ngf() );
	else	return( status );
	return(0);
}

/*	----------------------------------------------------------	*/
/*	    t r a n s l a t e _ s q l _ g e t s q l e r r o r		*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_getsqlerror( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 ))
		return( flush_ngf() );
	else	return( status );
	return(0);
}

/*	----------------------------------------------------------	*/
/*	 t r a n s l a t e _ s q l _ g e t s e r v i c e i n f o	*/
/*	----------------------------------------------------------	*/
WORD	translate_sql_getserviceinfo( WORD operation ) 		
{
	WORD	status;
	if (((status = start_ngf( operation )) 	== 0 )
	&&  ((status = ngf_handle())           	== 0 )
	&&  ((status = ngf_operand())		== 0 )
	&&  ((status = ngf_error_trap())	== 0 )
	&&  ((status = ngf_buffer())		== 0 ))
		return( flush_ngf() );
	else	return( status );
	return(0);
}

#endif	/* _trsql_c */
	/* -------- */

