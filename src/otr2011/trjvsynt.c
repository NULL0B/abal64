/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRJVSYNT.C				*/
/*		Version :	2.1c					*/
/*		Date	:	14/06/1996				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRSYNTAX_C
#define	_TRSYNTAX_C

#include "stdtypes.h"
#include "trjvsynt.h"
#include "trclass.h"
#include "trparser.h"
#include "trmalloc.h"

/*
 *	C o m p a r e _ T o k e n s ( aptr , bptr )
 *	-------------------------------------------
 *	Returns VRAI if the tokens are identical else FAUX
 *
 */ 

	BYTE	KeyWord[65];
	WORD	KeyWordHash;

WORD	compare_tokens( aptr , bptr )
BPTR	aptr;
BPTR	bptr;
{

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0))
		return( FAUX );

/*	sysprintf("TRJVSYNT..CompareTokens(%s,%s)\n",aptr,bptr);	*/

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

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0))
		return( FAUX );

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

	if ((aptr == (BPTR) 0)
	||  (bptr == (BPTR) 0)
	||  (n == 0)) {
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
	for ( i = 0; i < _LEVEL1_KEYWORD_MAX; i++ )
		if (( TokenHash == Level1KeyHash[i] )
		&&  ( compare_tokens( TokenBuffer, level1_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}

static	WORD	Level2KeyHash[ _LEVEL2_KEYWORD_MAX ];
static	WORD	Level2KeyInit=0;

WORD	is_level2_keyword()
{
	WORD	i;

	if (!( Level2KeyInit )) {
		for ( i = 0; i < _LEVEL2_KEYWORD_MAX; i++ )
			Level2KeyHash[i] = keyword_hash(level2_keywords[ i ]);
		Level2KeyInit=1;
		}
	for ( i = 0; i < _LEVEL2_KEYWORD_MAX; i++ )
		if (( TokenHash == Level2KeyHash[i] )
		&&  ( compare_tokens( TokenBuffer, level2_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}

static	WORD	Level3KeyHash[ _LEVEL3_KEYWORD_MAX ];
static	WORD	Level3KeyInit=0;

WORD	is_level3_keyword()
{
	WORD	i;

	if (!( Level3KeyInit )) {
		for ( i = 0; i < _LEVEL3_KEYWORD_MAX; i++ )
			Level3KeyHash[i] = keyword_hash(level3_keywords[ i ]);
		Level3KeyInit=1;
		}
	for ( i = 0; i < _LEVEL3_KEYWORD_MAX; i++ )
		if (( TokenHash == Level3KeyHash[i] )
		&&  ( compare_tokens( TokenBuffer, level3_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}

static	WORD	Level4KeyHash[ _LEVEL4_KEYWORD_MAX ];
static	WORD	Level4KeyInit=0;

WORD	is_level4_keyword()
{
	WORD	i;

	if (!( Level4KeyInit )) {
		for ( i = 0; i < _LEVEL4_KEYWORD_MAX; i++ )
			Level4KeyHash[i] = keyword_hash(level4_keywords[ i ]);
		Level4KeyInit=1;
		}
	for ( i = 0; i < _LEVEL4_KEYWORD_MAX; i++ )
		if (( TokenHash == Level4KeyHash[i] )
		&&  ( compare_tokens( TokenBuffer, level4_keywords[ i ] ) ))
			return(i);

	return(MOINS_UN);
}


VOID cancel_keyword(kptr)
BPTR  XPTR kptr;
{ return; }
VOID set_keyword_status(state)
WORD state;
{ return; }
BPTR get_class_keyword(n)
WORD n;
{ return((BPTR) 0); }
BPTR get_ngf_keyword(n)
WORD n;
{ return((BPTR) 0); }
WORD is_ngf_keyword(VOID) { return(MOINS_UN); }
#ifdef	WITH_NURAL
WORD is_nural_keyword(VOID) { return(MOINS_UN); }
#endif
WORD is_class_keyword(VOID) { return(MOINS_UN); }

WORD	is_iof_keyword()
{
	WORD	i;

	for ( i = 0; i < _IOF_KEYWORD_MAX; i++ )
		if ( compare_tokens( TokenBuffer, iof_keywords[ i ] ) )
			return(i);

	return(MOINS_UN);
}

WORD is_dcl_keyword(VOID) { return(MOINS_UN); }
WORD is_control_keyword(VOID) { return(MOINS_UN); }
WORD is_logical_keyword(VOID) { return(MOINS_UN); }
WORD comparison_operator(WORD mode) { return(MOINS_UN); }

#endif	/* _TRSYNTAX_C */
	/* ----------- */

