/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1990 Amenesik / Sologic s.a.
 *
 *	cico.h - definitions fonctions CICO
 *
 *	$Header: /home/Produits/Abal3/asfun/cico.h,v 1.1.1.1 2003/11/04 23:40:49 root Exp $
 *
 */


#include "_type.h"


#if M_I86 || __TURBOC__

EXAWORD x_getch(VOID);
EXAWORD x_kbhit(VOID);
EXAWORD prfo(EXAWORD, BYTE FAR *, EXAWORD);
EXAWORD lcfo(EXAWORD, BYTE FAR *, EXAWORD);
VOID x_putch(EXAWORD);
VOID x_cprintf(BYTE FAR *);
VOID pos(EXAWORD, EXAWORD);
VOID atb(EXAWORD);
VOID backgr(EXAWORD);
VOID foregr(EXAWORD);
VOID x_clear(VOID);
VOID x_bell(VOID);
EXAWORD x_col(VOID);
EXAWORD x_lin(VOID);
VOID x_bstart(VOID);
VOID x_bflush(VOID);
EXAWORD mima(EXAWORD, EXAWORD);
EXAWORD conf(EXAWORD);
EXAWORD x_npos(VOID);
EXAWORD im_open(BYTE FAR *, EXAWORD);
VOID im_close(VOID);
VOID initerm(VOID);
VOID finterm(EXAWORD);

#else

EXAWORD x_getch();
EXAWORD x_kbhit();
EXAWORD prfo();
EXAWORD lcfo();
VOID x_putch();
VOID x_cprintf();
VOID pos();
VOID atb();
VOID backgr();
VOID foregr();
VOID x_clear();
VOID x_bell();
EXAWORD x_col();
EXAWORD x_lin();
VOID x_bstart();
VOID x_bflush();
EXAWORD mima();
EXAWORD conf();
EXAWORD x_npos();
EXAWORD im_open();
VOID im_close();
VOID initerm();
VOID finterm();

#endif /* M_I86 || __TURBOC__ */


/* fin de fichier */
