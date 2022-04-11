/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : CICO.H
 *      Version : 2.1f
 *      Date    : 10/08/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions des appels CICO du traducteur]
 *
 */

#ifdef WIN16
#define NOTFASTCALL _cdecl
#else
#define NOTFASTCALL
#endif

#ifdef DLL

#define pos(a,b)
#define x_putch(a)
#define x_cprintf(a)
#define x_kbhit() 0
#define x_getch() 0
#define atb(a)
#define x_bell()
#define x_clear()
#define initerm(a)
#define finterm(a)
#define conf(a) 0
#define backgr(a)
#define foregr(a)

#else /* DLL */

#ifdef LINT_ARGS

extern void NOTFASTCALL pos(BINAIRE,BINAIRE);
extern void NOTFASTCALL x_putch(BINAIRE);
extern void NOTFASTCALL x_cprintf(char *);
extern BINAIRE NOTFASTCALL x_kbhit(void);
extern BINAIRE NOTFASTCALL x_getch(void);
extern void NOTFASTCALL atb(BINAIRE);
extern void NOTFASTCALL x_bell(void);
extern void NOTFASTCALL x_clear(void);
extern void initerm(void);
extern void finterm(void);
extern BINAIRE NOTFASTCALL conf(BINAIRE);
extern void NOTFASTCALL backgr(BINAIRE);
extern void NOTFASTCALL foregr(BINAIRE);

#ifdef unix
extern void modterm(BINAIRE);
#endif /* unix */

#else

extern void pos();
extern void x_putch();
extern void x_cprintf();
extern BINAIRE x_kbhit();
extern BINAIRE x_getch();
extern void atb();
extern void x_bell();
extern void x_clear();
extern void initerm();
extern void finterm();
extern BINAIRE conf();
extern void backgr();
extern void foregr();

#ifdef unix
extern void modterm();
#endif /* unix */

#endif /* LINT_ARGS */
#endif /* DLL */

/*------------------------- Fin de fichier : cico.h ------------------*/

