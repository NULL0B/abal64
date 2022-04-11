/*
 *	CICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	---------------------------------------------
 *
 *	Copyright (c) 1990 Amenesik / Sologic s.a.
 *
 *	cico.h - definitions fonctions CICO
 *
 *	$Header: /home/Produits/Abal3/cico/cico.h,v 1.2 2007/01/11 09:39:55 jamie Exp $
 *
 */


#include "_type_std.h"

#define cicoclose(cch) ( cch > 2 ? close( cch ) : printf("\r\n** CICO:CLOSE STDIN/OUT/ERR : %u\r\n",cch))

#if M_I86 || __TURBOC__ 

WORD x_getch(VOID);
WORD x_kbhit(VOID);
WORD prfo(WORD, BYTE FAR *, WORD);
WORD lcfo(WORD, BYTE FAR *, WORD);
VOID x_putch(WORD);
VOID x_cprintf(BYTE FAR *);
VOID pos(WORD, WORD);
VOID atb(WORD);
VOID backgr(WORD);
VOID foregr(WORD);
VOID x_clear(VOID);
VOID x_bell(VOID);
WORD x_col(VOID);
WORD x_lin(VOID);
VOID x_bstart(VOID);
VOID x_bflush(VOID);
WORD mima(WORD, WORD);
WORD conf(WORD);
WORD x_npos(VOID);
WORD im_open(BYTE FAR *, WORD);
VOID im_close(VOID);
VOID initerm(VOID);
VOID finterm(WORD);

#else

WORD x_getch();
WORD x_kbhit();
WORD x_putch(WORD);
WORD prfo(WORD,BYTE *,WORD);
WORD lcfo(WORD,BYTE *,WORD);
WORD x_cprintf(BYTE *);
VOID pos(WORD,WORD);
VOID atb(WORD);
VOID backgr(WORD);
VOID foregr(WORD);
VOID x_clear();
VOID x_bell();
WORD x_col();
WORD x_lin();
WORD x_bstart();
WORD x_bflush();
WORD mima(WORD,WORD);
WORD conf(WORD);
WORD x_npos();
WORD im_open();
VOID im_close();
VOID initerm();
VOID finterm();

#endif /* M_I86 || __TURBOC__ */


/* fin de fichier */
