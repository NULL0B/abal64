#ifndef	_cursor_h
#define _cursor_h
#ifdef	prologue
extern BOOL curs_is_on;		/* etat courant du curseur */
#define on_cursor()  { if (!(curs_is_on)) { atb(26); curs_is_on = TRUE; } }
#define off_cursor() { if (curs_is_on   ) { atb(25); curs_is_on = FALSE; } }
#else
#ifdef	USEIT
extern BOOL curs_is_on;		/* etat courant du curseur */
#define on_cursor()  { if (!(curs_is_on)) { atb(26); curs_is_on = TRUE; } }
#define off_cursor() { if (curs_is_on   ) { atb(25); curs_is_on = FALSE; } }
#else
#define	on_cursor()
#define off_cursor()
#endif
#endif
#endif /* _cursor_h */

