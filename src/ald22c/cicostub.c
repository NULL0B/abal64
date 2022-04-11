
/*
	Projet  : ABAL          Copyright Amenesik / Sologic software. (c) 1997
	Module  : CICO
	Fichier : cicostub.c
	Version : xx
	Date    : 23/03/93
	Systeme : DOS / PRL / UNIX / VMS / Windows

	Stub for CICO

	Replace all CICO function by function that does nothing!


	Modifications list :
	12 Dec 1997			JPH	File creation
	9 Jully 1998		JPH	Modified to use ctDiag
*/

#include "aldtype.h"


/* Uncomment next line to use ODS */
//#define USE_ODS
#ifdef USE_ODS
#include "cttype.h"
	#define NOT_IMPLEMENTED(NAME) \
		ODSsz("!!!CICO stub - function not implemented %s",#NAME); 
#else
	#define NOT_IMPLEMENTED(NAME)
#endif

#undef PRIMITIVE
#define PRIMITIVE
#include "pubwcico.h"

#if 0
PRIMITIVE WORD err_val;			/* variable d'erreur */
PRIMITIVE WORD prndest;			/* support implicite */
PRIMITIVE WORD prnfid;			/* handle du support */
PRIMITIVE BYTE FAR * prnptr;	/* pointeur zone de reception */
PRIMITIVE WORD prnleng;			/* longueur zone de reception */
#endif


#include "display.h"



/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			DESCRIPTION DES PRIMITIVES			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

PRIMITIVE WORD x_kbhit(void)
{NOT_IMPLEMENTED(x_kbhit);return (WORD) -1;}

PRIMITIVE WORD x_getch(void)
{NOT_IMPLEMENTED(x_getch);return (WORD) -1;}

PRIMITIVE void x_KbdMode(WORD a)
{NOT_IMPLEMENTED(x_KbdMode);}

PRIMITIVE WORD prfo(WORD a, BYTE FAR * b, WORD c)
{NOT_IMPLEMENTED(prfo);return 0;}

PRIMITIVE WORD lcfo(WORD a, BYTE FAR * b, WORD c)
{NOT_IMPLEMENTED(lcfo);return 0;}

PRIMITIVE void x_putch (WORD Char)
	{
	#ifdef __WALD__
	waDisplayAppendChar((ctChar) Char);
	#else
	NOT_IMPLEMENTED(x_putch);
	#endif
	}

PRIMITIVE void x_cprintf (BYTE FAR * Str)
	{
	#ifdef __WALD__
	waDisplayAppendString(Str);
	#else
	NOT_IMPLEMENTED(x_cprintf);
	#endif
	}

PRIMITIVE void x_bstart(void)
{NOT_IMPLEMENTED(x_bstart);}

PRIMITIVE void x_bflush(void)
	{
	#ifdef __WALD__
	waDisplayFlush();
	#else
	NOT_IMPLEMENTED(x_bflush);
	#endif
	}

PRIMITIVE void pos(WORD a, WORD b)
{NOT_IMPLEMENTED(pos);}

PRIMITIVE void atb(WORD a)
{NOT_IMPLEMENTED(atb);}

PRIMITIVE void backgr(WORD a)
{NOT_IMPLEMENTED(backgr);}

PRIMITIVE void foregr(WORD a)
{NOT_IMPLEMENTED(foregr);}

PRIMITIVE void x_clear(void)
{NOT_IMPLEMENTED(x_clear);}

PRIMITIVE void x_bell(void)
{NOT_IMPLEMENTED(x_bell);}

PRIMITIVE WORD x_lin(void)
{NOT_IMPLEMENTED(x_lin);return 0;}

PRIMITIVE WORD x_col(void)
{NOT_IMPLEMENTED(x_col);return 0;}


PRIMITIVE WORD mima(WORD a, WORD b)
{NOT_IMPLEMENTED(mima);return 0;}

PRIMITIVE WORD conf(WORD a)
{NOT_IMPLEMENTED(conf);return 0;}

PRIMITIVE WORD x_npos(void)
{NOT_IMPLEMENTED(x_npos);return 0;}


PRIMITIVE WORD im_open(BYTE FAR * a, WORD b)
{NOT_IMPLEMENTED(im_open);return 0;}

PRIMITIVE void im_close(void)
{NOT_IMPLEMENTED(im_close);}


PRIMITIVE void initerm(void)
{NOT_IMPLEMENTED(initerm);}

PRIMITIVE void finterm(WORD a)
{NOT_IMPLEMENTED(finterm);}


