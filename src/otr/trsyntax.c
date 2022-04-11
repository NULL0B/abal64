/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.	*/
/*									*/
/*									*/
/*		File	:	TRSYNTAX.C				*/
/*		Version :	2.1c					*/
/*		Date	:	28/09/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSYNTAX_C
#define	_TRSYNTAX_C

#include <stdio.h>

#include "stdtypes.h"
#include "translat.h"
#include "trsyntax.h"
#include "trclass.h"
#include "trparser.h"
#include "trmalloc.h"
#include "trabal.h"
#include "triof.h"
#include "trclf.h"
#include "trecho.h"

	BYTE	KeyWord[65];
	WORD	KeyWordHash;
static	LONG	CompareTokens=0L;
static	WORD	NgfKeyHash[ _NGF_KEYWORD_MAX ];
static	WORD	NgfKeyInit=0;
static	WORD	ClassKeyHash[ _CLASS_KEYWORD_MAX ];
static	WORD	ClassKeyInit=0;
static	WORD	Level1KeyHash[ _LEVEL1_KEYWORD_MAX ];
static	WORD	Level1KeyInit=0;
static	WORD	ControlKeyHash[ _CONTROL_KEYWORD_MAX ];
static	WORD	ControlKeyInit=0;

/*	--------------	*/
/*	compare_tokens	*/
/*	--------------	*/
WORD	compare_tokens( aptr , bptr )
BPTR	aptr;
BPTR	bptr;
{
	CompareTokens++;

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0)) 
		return( FAUX );

	while ((*aptr) && (*bptr)) 
		if ( *(aptr++) != *(bptr++) ) 
			return(FAUX);

	if ( *aptr == *bptr ) return(VRAI);
	else		      return(FAUX);
}

/*	-----------------	*/
/*	uppercase_compare	*/
/*	-----------------	*/
WORD	uppercase_compare( aptr , bptr )
BPTR	aptr;
BPTR	bptr;
{
	WORD	a;
	WORD	b;
	CompareTokens++;

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0)) 
		return( FAUX );

	while (1) 
	{
		a = *(aptr++);
		b = *(bptr++);
		if ((a == 0) || (b == 0))
			break;
		if (( a >= 'a' ) && ( a <= 'z' ))
			a -= ('a'-'A');
		if (( b >= 'a' ) && ( b <= 'z' ))
			b -= ('a'-'A');
		if ( a != b ) 
			return(FAUX);
	}

	if (  a    ==  b    ) return(VRAI);
	else		      return(FAUX);
}

/*	------------------	*/
/*	uppercase_ncompare	*/
/*	------------------	*/
WORD	uppercase_ncompare( aptr , bptr, n)
BPTR	aptr;
BPTR	bptr;
WORD	n;
{
	WORD	a;
	WORD	b;
	WORD	i = 0;
	CompareTokens++;

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0)
	||  (n == 0)) 
		return( FAUX );

	while (i < n) 
	{
		a = *(aptr++);
		b = *(bptr++);
		if ((a == 0) || (b == 0))
			break;
		if (( a >= 'a' ) && ( a <= 'z' ))
			a -= ('a'-'A');
		if (( b >= 'a' ) && ( b <= 'z' ))
			b -= ('a'-'A');
		if ( a != b ) 
			return(FAUX);
		i++;
	}

	if (  a    ==  b    ) return(VRAI);
	else		      return(FAUX);
}

/*	-----------------	*/
/*	uppercase_keyword	*/
/*	-----------------	*/
VOID	uppercase_keyword()
{
	WORD	i;
	WORD	c;
	for ( KeyWordHash = 0, i= 0; i < 64; i++) 
	{
 		if ((c = TokenBuffer[i]) == 0)
			break;
		else if ((c >= 'a') && ( c <= 'z' ))
			c -= ('a' - 'A');
		KeyWord[i] = c;
		KeyWordHash += c;
	}
	KeyWord[i] = 0;
	return;
}

/*	------------	*/
/*	keyword_hash	*/
/*	------------	*/
WORD	keyword_hash( sptr )
BPTR	sptr;
{
	WORD	h=0;
	while ( *sptr )
		h += *(sptr++);
	return( h );
}

/*	---------------	*/
/*	get_ngf_keyword	*/
/*	---------------	*/
BPTR	get_ngf_keyword( n )
WORD	n;
{
	return((BPTR) ngf_keywords[n] );
}

/*	--------------	*/
/*	is_ngf_keyword	*/
/*	--------------	*/
WORD	is_ngf_keyword()
{
	WORD	i;

	if (!( NgfKeyInit )) 
	{
		for ( i = 0; i < _NGF_KEYWORD_MAX; i++ )
			NgfKeyHash[i] = keyword_hash(ngf_keywords[ i ]);
		NgfKeyInit=1;
	}

	uppercase_keyword();
	for ( i = 0; i < _NGF_KEYWORD_MAX; i++ )
		if (( KeyWordHash == NgfKeyHash[i] )
		&&  ( compare_tokens( KeyWord , ngf_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}

#ifdef	WITH_NURAL
/*	----------------	*/
/*	is_nural_keyword	*/
/*	----------------	*/
WORD	is_nural_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _NURAL_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , nural_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}
#endif

/*	-----------------	*/
/*	get_class_keyword	*/
/*	-----------------	*/
BPTR	get_class_keyword( n )
WORD	n;
{
	if ( n < _CLASS_KEYWORD_MAX )
		return( class_keywords[ n ] );
	else	return( "<keyword>" );
}

/*	----------------	*/
/*	is_class_keyword	*/
/*	----------------	*/
WORD	is_class_keyword()
{
	WORD	i;

	if (!( ClassKeyInit )) 
	{
		for ( i = 0; i < _CLASS_KEYWORD_MAX; i++ )
			ClassKeyHash[i] = keyword_hash(class_keywords[ i ]);
		ClassKeyInit=1;
	}

	uppercase_keyword();
	for ( i = 0; i < _CLASS_KEYWORD_MAX; i++ )
		if (( KeyWordHash == ClassKeyHash[i] )
		&&  ( compare_tokens( KeyWord , class_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}

/*	--------------	*/
/*	is_iof_keyword	*/
/*	--------------	*/
WORD	is_iof_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _IOF_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , iof_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

/*	-----------------	*/
/*	is_level1_keyword	*/
/*	-----------------	*/
WORD	is_level1_keyword()
{
	WORD	i;

	if (!( Level1KeyInit )) {
		for ( i = 0; i < _LEVEL1_KEYWORD_MAX; i++ )
			Level1KeyHash[i] = keyword_hash(level1_keywords[ i ]);
		Level1KeyInit=1;
		}

	uppercase_keyword();

	for ( i = 0; i < _LEVEL1_KEYWORD_MAX; i++ )
		if (( KeyWordHash == Level1KeyHash[i] )
		&&  ( compare_tokens( KeyWord , level1_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}

/*	-----------------	*/
/*	is_level2_keyword	*/
/*	-----------------	*/
WORD	is_level2_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _LEVEL2_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , level2_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

/*	----------------	*/
/*	 is_dcl_keyword 	*/
/*	----------------	*/
WORD	is_dcl_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _DCL_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , dcl_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

/*	------------------	*/
/*	is_control_keyword	*/
/*	------------------	*/
WORD	is_control_keyword()
{
	WORD	i;
	if (!( ControlKeyInit )) 
	{
		for ( i = 0; i < _CONTROL_KEYWORD_MAX; i++ )
			ControlKeyHash[i] = keyword_hash(control_keywords[ i ]);
		ControlKeyInit=1;
	}

	uppercase_keyword();
	for ( i = 0; i < _CONTROL_KEYWORD_MAX; i++ )
		if (( KeyWordHash == ControlKeyHash[i] )
		&&  (  compare_tokens( KeyWord , control_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}

/*	------------------	*/
/*	is_logical_keyword	*/
/*	------------------	*/
WORD	is_logical_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _LOGICAL_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , logical_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

/*	-------------------	*/
/*	comparison_operator	*/
/*	-------------------	*/
WORD	comparison_operator(mode)
WORD	mode;
{
	WORD	result;
	result = collect_normal_operator();
	if ( mode )
		return( reverse_compare(result) );
	else	return(result );
}

/*	--------------	*/
/*	cancel_keyword	*/
/*	--------------	*/
VOID		cancel_keyword( kptr )
BPTR XPTR	kptr;
{
	*kptr = (BPTR) "\n";
	return;
}

/*	------------------	*/
/*	set_keyword_status	*/
/*	------------------	*/
VOID	set_keyword_status( state )
WORD	state;
{
	WORD	type;
	if ((type = is_control_keyword()) != MOINS_UN)
		cancel_keyword( & control_keywords[type] );
	else if ((type = is_logical_keyword()) != MOINS_UN)
		cancel_keyword( & logical_keywords[type] );
	else if ((type = is_dcl_keyword()) != MOINS_UN)
		cancel_keyword( & dcl_keywords[type] );
	else if ((type = is_level2_keyword()) != MOINS_UN)
		cancel_keyword( & level2_keywords[type] );
	else if ((type = is_level1_keyword()) != MOINS_UN)
		cancel_keyword( & level1_keywords[type] );
	else if ((type = is_iof_keyword()) != MOINS_UN)
		cancel_keyword( & iof_keywords[type] );
	else if ((type = is_ngf_keyword()) != MOINS_UN)
		cancel_keyword( & ngf_keywords[type] );
#ifdef	WITH_NURAL
	else if ((type = is_nural_keyword()) != MOINS_UN)
		cancel_keyword( & nural_keywords[type] );
#endif
	else if ((type = is_class_keyword()) != MOINS_UN)
		cancel_keyword( & class_keywords[type] );
	else if ( cancel_iof_instruction() != MOINS_UN )
		return;
	else if ( cancel_clf_instruction() != MOINS_UN)
		return;
	return;
}

	/* ----------- */
#endif	/* _TRSYNTAX_C */
	/* ----------- */



