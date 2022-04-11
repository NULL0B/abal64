/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
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

/*
 *	C o m p a r e _ T o k e n s ( aptr , bptr )
 *	-------------------------------------------
 *	Returns VRAI if the tokens are identical else FAUX
 *
 */ 

	BYTE	KeyWord[65];
	WORD	KeyWordHash;

static	LONG	CompareTokens=0L;

VOID	ct_statistics()
{
	sysprintf("compare_tokens() calls : %lu \n",CompareTokens );
	return;
}

WORD	compare_tokens( aptr , bptr )
BPTR	aptr;
BPTR	bptr;
{
	CompareTokens++;

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0)) {
		sysprintf("aptr(%s) or bptr(%s) == NULL\n",aptr,bptr);
		return( FAUX );
		}
	while ((*aptr) && (*bptr)) 
		if ( *(aptr++) != *(bptr++) ) 
			return(FAUX);

	if ( *aptr == *bptr ) return(VRAI);
	else		      return(FAUX);

}

WORD	uppercase_compare( aptr , bptr )
BPTR	aptr;
BPTR	bptr;
{
	WORD	a;
	WORD	b;
	CompareTokens++;

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0)) {
		sysprintf("aptr(%s) or bptr(%s) == NULL\n",aptr,bptr);
		return( FAUX );
		}
	while (1) {
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
	||  (n == 0)) {
		sysprintf("aptr(%s) or bptr(%s) or n(%d) == NULL\n",aptr,bptr,n);
		return( FAUX );
		}
	while (i < n) {
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

VOID	uppercase_keyword()
{
	WORD	i;
	WORD	c;
	for ( KeyWordHash = 0, i= 0; i < 64; i++) {
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

WORD	keyword_hash( sptr )
BPTR	sptr;
{
	WORD	h=0;
	while ( *sptr )
		h += *(sptr++);
	return( h );
}

static	WORD	NgfKeyHash[ _NGF_KEYWORD_MAX ];
static	WORD	NgfKeyInit=0;

BPTR	get_ngf_keyword( n )
WORD	n;
{
	return((BPTR) ngf_keywords[n] );
}

WORD	is_ngf_keyword()
{
	WORD	i;

	if (!( NgfKeyInit )) {
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
static	LONG	ClassKeyCall=0L;
static	LONG	ClassKeyFail=0L;

VOID	ick_statistics()
{
	sysprintf("is_class_keyword() calls : %lu \n",ClassKeyCall);
	sysprintf("is_class_keyword() fails : %lu \n",ClassKeyFail);
	return;
}

static	WORD	ClassKeyHash[ _CLASS_KEYWORD_MAX ];
static	WORD	ClassKeyInit=0;

BPTR	get_class_keyword( n )
WORD	n;
{
	if ( n < _CLASS_KEYWORD_MAX )
		return( class_keywords[ n ] );
	else	return( "<keyword>" );
}

WORD	is_class_keyword()
{
	WORD	i;

	ClassKeyCall++;

	if (!( ClassKeyInit )) {
		for ( i = 0; i < _CLASS_KEYWORD_MAX; i++ )
			ClassKeyHash[i] = keyword_hash(class_keywords[ i ]);
		ClassKeyInit=1;
		}

	uppercase_keyword();
	for ( i = 0; i < _CLASS_KEYWORD_MAX; i++ )
		if (( KeyWordHash == ClassKeyHash[i] )
		&&  ( compare_tokens( KeyWord , class_keywords[ i ] ) ))
			return(i);

	ClassKeyFail++;
	return(MOINS_UN);
}


WORD	is_iof_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _IOF_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , iof_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

static	WORD	Level1KeyHash[ _LEVEL1_KEYWORD_MAX ];
static	WORD	Level1KeyInit=0;

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

WORD	is_level2_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _LEVEL2_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , level2_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	is_dcl_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _DCL_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , dcl_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

static	WORD	ControlKeyHash[ _CONTROL_KEYWORD_MAX ];
static	WORD	ControlKeyInit=0;

WORD	is_control_keyword()
{
	WORD	i;
	if (!( ControlKeyInit )) {
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

WORD	is_logical_keyword()
{
	WORD	i;

	uppercase_keyword();
	for ( i = 0; i < _LOGICAL_KEYWORD_MAX; i++ )
		if ( compare_tokens( KeyWord , logical_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD	comparison_operator(mode)
WORD	mode;
{
	WORD	result;
	result = collect_normal_operator();
	if ( mode )
		return( reverse_compare(result) );
	else	return(result );
}

VOID		cancel_keyword( kptr )
BPTR XPTR	kptr;
{
	*kptr = (BPTR) "\n";
	return;
}

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


#endif	/* _TRSYNTAX_C */
	/* ----------- */



