/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRJAVA.C				*/
/*		Version :	2.1c					*/
/*		Date	:	14/06/1996				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRJAVA_H
#define	_TRJAVA_H

#define _TRANSLATOR_LANGUAGE_DEFAULT	"JTRDEF"

#define	_JTR_SYNTAX_ERROR   		13000
#define	_JTR_EXPECTED_SEMICOLON		13001
#define	_JTR_EXPECTED_TOKEN 		13002
#define	_JTR_CLASS_QUALIFIER		13003
#define	_JTR_EXPECTED_TYPE  		13004
#define	_JTR_EXPECTED_COMMA 		13005
#define	_JTR_EXPECTED_LEFTBRACE		13006
#define	_JTR_EXPECTED_RIGHTBRACE	13007
#define	_JTR_EXPECTED_COLON		13008

#define	JAVAPTR	struct java_class_member XPTR

struct	java_class_member	{
	BPTR	name;
	WORD	type;
	WORD	size;
	WORD	first;
	WORD	second;
	WORD	nature;
	};


#endif	/* _TRJAVA_H */
	/* --------- */

