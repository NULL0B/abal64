#ifndef	_exphp_h
#define _exphp_h

/*	------------------------------------------------------------------	*/
/*		p h p    e x t e n s i o n    i n c l u s i o n s		*/
/*	------------------------------------------------------------------	*/
#include <stdio.h>
#include <php.h>
#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zendextensions.h>

#define	_ABAL_PHP_VERSION	"4.0a.0.01"
#define	_ABAL_PHP_RELEASE	"15/08/2011"

#ifndef	private
#define	private	static
#endif

#ifndef	public	
#define	public	
#endif

/*	------------------------------------------------------------------	*/
/*	    p h p   m o d u l e   h o o k u p   p r o t o t y p e s		*/
/*	------------------------------------------------------------------	*/

PHP_MINIT_FUNCTION(abal);
PHP_MSHUTDOWN_FUNCTION(abal);
PHP_RINIT_FUNCTION(abal);
PHP_RSHUTDOWN_FUNCTION(abal);
PHP_MINFO_FUNCTION(abal);

/*	------------------------------------------------------------------	*/
/*	    a b a l   p h p   e x t e n s i o n   p r o t o t y p e s		*/
/*	------------------------------------------------------------------	*/
PHP_FUNCTION(abal_program);
PHP_FUNCTION(abal_call);
PHP_FUNCTION(abal_ldgo);
PHP_FUNCTION(abal_stop);

	/* -------- */
#endif	/* _exphp_h */
	/* -------- */

