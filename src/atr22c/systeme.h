/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : SYSTEME.H
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions des appels systemes du traducteur]
 *
 */

#ifdef LINT_ARGS
#ifdef msdos
extern int getch (void);
extern int putch (int);
extern int kbhit (void);
#endif /* msdos */

#ifdef prologue
extern int getch (void);
extern int putch (int);
extern int kbhit (void);
extern int autorise(void);
extern int prl_date (char far *);

#endif /* prologue */

#ifdef unix
extern int Access(char *,int,int);
extern void PurgeLox(void);
extern void liberlox(char *);
#endif /* unix */

#else

#ifdef msdos
extern int getch ();
extern int putch ();
extern int kbhit ();
#endif /* msdos */

#ifdef prologue
extern int getch ();
extern int putch ();
extern int kbhit ();
extern int autorise();
extern int prl_date ();

#endif /* prologue */

#ifdef unix
extern int Access();
extern void PurgeLox();
extern void liberlox();
#endif /* unix */

#endif /* LINT_ARGS */

/*------------------------- Fin de fichier : systeme.h ------------------*/

