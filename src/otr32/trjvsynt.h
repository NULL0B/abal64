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
#ifndef	_TRSYNTAX_H
#define	_TRSYNTAX_H


#define	_LEVEL1_KEYWORD_MAX	18
#define	_LEVEL2_KEYWORD_MAX	10
#define	_LEVEL3_KEYWORD_MAX	1
#define	_LEVEL4_KEYWORD_MAX	11

#ifdef	_TRSYNTAX_C

static BPTR level1_keywords [_LEVEL1_KEYWORD_MAX] = {
	(BPTR) "package",
	(BPTR) "import",
	(BPTR) "public",
	(BPTR) "private",
	(BPTR) "protected",
	(BPTR) "final",
	(BPTR) "static",
	(BPTR) "class",
	(BPTR) "extends",
	(BPTR) "native",
	(BPTR) "abstract",
	(BPTR) "implements",
	(BPTR) "interface",
	(BPTR) "synchronized",
	(BPTR) "program",
	(BPTR) "overlay",
	(BPTR) "module",
	(BPTR) "library"
	};

static BPTR level2_keywords [_LEVEL2_KEYWORD_MAX] = {
	(BPTR) "void",
	(BPTR) "short",
	(BPTR) "unsigned",
	(BPTR) "signed",
	(BPTR) "char",
	(BPTR) "int",
	(BPTR) "long",
	(BPTR) "double",
	(BPTR) "float",
	(BPTR) "boolean"
	};

static BPTR level3_keywords [_LEVEL3_KEYWORD_MAX] = {
	(BPTR) "throws"
	};

static BPTR level4_keywords [_LEVEL4_KEYWORD_MAX] = {
	(BPTR) "if",
	(BPTR) "else",
	(BPTR) "for",
	(BPTR) "while",
	(BPTR) "do",
	(BPTR) "switch",
	(BPTR) "case",
	(BPTR) "default",
	(BPTR) "break",
	(BPTR) "continue",
	(BPTR) "return"
	};

#define	_IOF_KEYWORD_MAX	2
	
static BPTR iof_keywords [_IOF_KEYWORD_MAX] = {
	(BPTR) "printf",
	(BPTR) "sprintf"
	};

#endif

#define	_KW1_PACKAGE	0
#define	_KW1_IMPORT 	1
#define	_KW1_PUBLIC	2
#define	_KW1_PRIVATE	3
#define	_KW1_PROTECTED	4
#define	_KW1_FINAL	5
#define	_KW1_STATIC	6
#define	_KW1_CLASS	7
#define	_KW1_EXTENDS	8
#define	_KW1_NATIVE 	9
#define	_KW1_ABSTRACT	10
#define	_KW1_IMPLEMENTS 11
#define	_KW1_INTERFACE  12
#define	_KW1_SYNCHRONIZED 13
#define	_KW1_PROGRAM	14
#define	_KW1_OVERLAY	15
#define	_KW1_MODULE	16
#define	_KW1_LIBRARY	17

#define	_KW2_VOID	0
#define	_KW2_SHORT	1
#define	_KW2_UNSIGNED	2
#define	_KW2_SIGNED	3
#define	_KW2_CHAR	4
#define	_KW2_INT	5
#define	_KW2_LONG	6
#define	_KW2_DOUBLE	7
#define	_KW2_FLOAT	8
#define	_KW2_BOOLEAN	9

#define	_KW3_THROWS	0

#define	_KW4_IF		0
#define	_KW4_ELSE	1
#define	_KW4_FOR	2
#define	_KW4_WHILE	3
#define	_KW4_DO		4
#define	_KW4_SWITCH	5
#define	_KW4_CASE	6
#define	_KW4_DEFAULT	7
#define	_KW4_BREAK	8
#define	_KW4_CONTINUE	9
#define	_KW4_RETURN	10

#endif	/* _TRSYNTAX_H */
	/* ----------- */



