#ifndef	_exphp_c
#define _exphp_c

#include "exphp.h"
#include "exdll.h"

/*	---------------------------------	*/
/*	the abal php function relay table	*/
/*	---------------------------------	*/
private	struct zend_function_entry abal_php_functions[] = 
{
	ZEND_NAMED_FE(abal_program,abal_program,NULL),
	ZEND_NAMED_FE(abal_call,abal_call,NULL),
	ZEND_NAMED_FE(abal_ldgo,abal_ldgo,NULL),
	ZEND_NAMED_FE(abal_stop,abal_stop,NULL),
	{ NULL, NULL, NULL }
};

/*	---------------------------------	*/
/*	 the abal php module relay table	*/
/*	---------------------------------	*/
public	struct zend_module_entry abal_php_module_entry = 
{
	STANDARD_MODULE_HEADER,
	"abal",
	abal_php_functions,
	PHP_MINIT(abal),
	PHP_MSHUTDOWN(abal),
	PHP_RINIT(abal),
	PHP_RSHUTDOWN(abal),
	PHP_MINFO(abal),
	_ABAL_PHP_VERSION,
	STANDARD_MODULE_PROPERTIES
};

/*	------------------------------------------------------------------	*/
/*	    p h p   m o d u l e   h o o k u p   p r o t o t y p e s		*/
/*	------------------------------------------------------------------	*/

PHP_MINIT_FUNCTION(abal)
{
	return( SUCCESS );
}

PHP_MSHUTDOWN_FUNCTION(abal)
{
	return( SUCCESS );
}

PHP_RINIT_FUNCTION(abal)
{
	return( SUCCESS );
}

PHP_RSHUTDOWN_FUNCTION(abal)
{
	return( SUCCESS );
}

PHP_MINFO_FUNCTION(abal)
{
	php_printf("Abal Extension\n");
	php_info_print_table_start();
	php_info_print_table_row(2,"Version",_ABAL_PHP_VERSION);
	php_info_print_table_row(2,"Release",_ABAL_PHP_RELEASE);
	php_info_print_table_row(2,"LOAD","Load Abal Program");
	php_info_print_table_row(2,"CALL","Call Abal Procedure");
	php_info_print_table_row(2,"LDGO","LdGo Abal Segment");
	php_info_print_table_row(2,"STOP","Stop Abal Program");
	php_info_print_table_end();
	return( SUCCESS );
}

/*	------------------------------------------------------------------	*/
/*			a b a l _ p r o g r a m	_ h a n d l e 			*/
/*	------------------------------------------------------------------	*/
private	struct	abal_program_handle * aph=(struct abal_program_handle *) 0;

/*	------------------------------------------------------------------	*/
/*			a b a l _ p r o g r a m _ s t o p 			*/
/*	------------------------------------------------------------------	*/
private	void	abal_program_stop()
{
	if ( aph )
	{
		(aph->stop)(aph);
		aph = (struct abal_program_handle *) 0;
	}
}

/*	------------------------------------------------------------------	*/
/*			a b a l _ p r o g r a m _ l o a d 			*/
/*	------------------------------------------------------------------	*/
private	int	abal_program_load( char * aptr )
{
	abal_program_stop();
	if (!( aph = LoadAbalProgram( aptr, 0 )))
		return( 40 );
	else	return( 0  );		
}

/*	------------------------------------------------------------------	*/
/*			a b a l _ p r o g r a m _ c a l l 			*/
/*	------------------------------------------------------------------	*/
private	int	abal_program_call( char * aptr )
{
	int	procnumber=0;
	if ((procnumber = (aph->resolve)(aph,aptr)) == -1)
		return( 30 );
	else	return( (aph->procedure)(aph,procnumber));
}

/*	------------------------------------------------------------------	*/
/*			a b a l _ p r o g r a m _ l d g o 			*/
/*	------------------------------------------------------------------	*/
private	int	abal_program_ldgo( int number )
{
	return( (aph->segment)(aph,number) );
}

/*	------------------------------------------------------------------	*/
/*			p h p _ a b a l _ p r o g r a m				*/
/*	------------------------------------------------------------------	*/
/*	the entry point from PHP for the loading of an ABAL program using	*/
/*	the standard ABAL Call Through library of EXA to build a program	*/
/*	instance using the tcode filename passed as the sing parameter to	*/
/*	this function. Notification of failure in anyway should be sent to	*/
/*	the caller using the standard PHP error throwing techniques since	*/
/*	all errors encountered here are rather fatal.				*/
/*	------------------------------------------------------------------	*/
PHP_FUNCTION(abal_program)
{
	char *	programname=(char *) 0;
	int	namelength=0;
	int	status=0;

	if ( zend_parse_parameters(
		ZEND_NUM_ARGS() TSRMLS_CC, 
		"s",&programname,&namelength) == FAILURE )
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "expected program name" ); 
		RETURN_FALSE();
	}
	else if ((status = abal_program_load( programname )) != 0)
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "error(%u) loading program(%s)",status, programname); 
		RETURN_FALSE();
	}
}

/*	------------------------------------------------------------------	*/
/*			    p h p _ a b a l _ c e l l				*/
/*	------------------------------------------------------------------	*/
/*	This entry point from php allows a named procedure to be called as	*/
/*	described by the accompanying parameter values. The function will	*/
/*	return a PHP object corresponding to the return value of the call.	*/
/*	------------------------------------------------------------------	*/
PHP_FUNCTION(abal_call)
{
	char *	procedurename;
	int	namelength=0;
	int	status=0;
	if ( zend_parse_parameters(
		ZEND_NUM_ARGS() TSRMLS_CC, 
		"s",&procedurename,&namelength) == FAILURE )
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "expected procedure name" ); 
		RETURN_FALSE();
	}
	else if (!( aph ))
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "program not loaded" ); 
		RETURN_FALSE();
	}
	else if ((status = abal_program_call( procedurename )) != 0 )
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "error(%u) calling procedure(%s)",status, procedurename); 
		RETURN_FALSE();
	}
}

/*	------------------------------------------------------------------	*/
/*			    p h p _ a b a l _ l d g o				*/
/*	------------------------------------------------------------------	*/
/*	This entry point from php allows a segment to be loaded and run as	*/
/*	described by the accompanying parameter value. The function will	*/
/*	not return a PHP object since segents do not return results.		*/
/*	------------------------------------------------------------------	*/
PHP_FUNCTION(abal_ldgo)
{
	int	segmentnumber;
	int	status=0;
	if ( zend_parse_parameters(
		ZEND_NUM_ARGS() TSRMLS_CC, 
		"l",&segmentnumber) == FAILURE )
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "expected segment number" ); 
		RETURN_FALSE();
	}
	else if (!( aph ))
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "program not loaded" ); 
		RETURN_FALSE();
	}
	else if ((status = abal_program_ldgo( segmentnumber )) != 0 )
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "error(%u) calling segment(%u)",status, segmentnumber);
		RETURN_FALSE();
	}
}

/*	------------------------------------------------------------------	*/
/*			    p h p _ a b a l _ s t o p 				*/
/*	------------------------------------------------------------------	*/
/*	This entry point from php allows a loaded ABAL program to be stoped	*/
/*	and all memory and files involved will be released and closed.  	*/
/*	All further ABAL CALL and ABAL LDGO operations will result in an	*/
/*	error condition being thrown.						*/
/*	------------------------------------------------------------------	*/
PHP_FUNCTION(abal_stop)
{
	if (!( aph ))
	{
		php_error_docref( NULL TSRMLS_CC,E_WARNING, "program not loaded" ); 
		RETURN_FALSE();
	}
	abal_program_stop();
}

	/* -------- */
#endif	/* _exphp_c */
	/* -------- */

