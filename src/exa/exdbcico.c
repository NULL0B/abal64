/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXDBCICO.C
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 

#define EXDBCICOC

#include "ex.h"                         /* General definitions          */
#include "exdbgrsy.h"                   /* Graphique symbols            */
#include "exdbkeys.h"                   /* Key Definitions              */
#include "excico.h"                     /* CICO Prototypes              */
#include "exmimo.h"                     /* Mouse interface description  */
#include "exdbword.h"                   /* Version 666 Word definitions */
#include "exproto1.h"
#include <errno.h>

#ifndef	NOGIGO
#define x_getch() mimo_getch()
#endif

#define DBCO_TRUE       0x0001          /* Indicate CO Active           */
#define DBCO_FAUX       0xFFFE          /* Indicate CO inactive         */
#define DBCO_ESC        0x0002          /* Indicate Escape mode         */
#define DBCO_PASS       0x0004          /* Indicate transparant mode    */
#define DBCO_ARG        0x0008          /* Indicate Arg Mode            */
#define DBCO_NORM       0xFFF1          /* Reset mode normal            */

#define ZONEMAX         32              /* Number of Sub Zones          */

#ifdef  TEST40COL
#define INITSLIN        12
#define INITSCOL        40
#else
#define INITSLIN        conf(1)
#define INITSCOL        conf(2)
#endif

#ifdef WIN32
static int     errno;
#else
EXTERN  int     errno;
#endif
EXTERN  EXAWORD    ExWindow;
EXTERN  EXAWORD    DbWindow;

#ifdef	ABALX11
extern	int	exa_is_X11;
#endif

/*      Global Variables        */
/*      ----------------        */
#define PUSHPOP
#ifdef  PUSHPOP
struct  pushpop {
	BPTR              scrptr;       /* Pushed Screen Data           */
	BPTR              atbptr;       /* Pushed Screen Attributs      */
	BPTR              pntptr;       /* Pushed Screen Colours        */
	struct pushpop  PTR fwdptr;    /* Pointer to Next structure    */
	};
struct  pushpop PTR PopBase;           /* Base of Push / Pop Stack     */
#endif

EXAWORD    exadb_ungotc;
struct  Fenetre {
	BPTR    W_Sbuf;                 /* Screen Buffer Pointer        */
	BPTR    W_Abuf;                 /* Attribut Buffer Pointer      */
	BPTR    W_Cbuf;                 /* Colours Buffer Pointer       */
	EXAWORD    W_Sdex;                 /* Current offset               */
	EXAWORD    W_Satb;                 /* Current Attribute            */
	EXAWORD    W_Sfor;                 /* Current Forground Colour     */
	EXAWORD    W_Sbak;                 /* Current BackGround Colour    */
	EXAWORD    W_Sarg;                 /* ???                          */
	EXAWORD    W_Sesc;                 /* ???                          */
	EXAWORD    W_Edex;                 /* ???                          */
	EXABYTE    W_Earg[32];             /* Escape Args Pending          */
	EXAWORD    W_Sflg;                 /* Status Flags                 */
	EXAWORD    W_Para[5];              /* Window Parameters            */
#ifdef  ABAL21
	EXABYTE    W_mouse[32];            /* Should be long enough 14 * 2 */
#endif
	EXABYTE	   W_fkey[((50*33)+(8*2))]; /* 8 monocharatcer, 50 multicharacter */
	EXAWORD	   W_fkeys;
	};

struct Fenetre PTR Window;             /* window Manager               */

struct  ZoneKeep {
	BPTR    Z_buf;                  /* Buffer Pointer               */
	EXAWORD    Z_own;                  /* Owner ID                     */
	EXAWORD    Z_lno;                  /* Line Number                  */
	EXAWORD    Z_cno;                  /* Column Number                */
	EXAWORD    Z_nbl;                  /* Number of Lines              */
	EXAWORD    Z_nbc;                  /* Number of Columns            */
	EXAWORD    Z_pos;                  /* ???                          */
	EXAWORD    Z_atb;                  /* Current Last Atb             */
	EXAWORD    Z_for;                  /* Current Last ForeGround      */
	EXAWORD    Z_bak;                  /* Current Last BackGround      */
	EXAWORD    W_Para[5];              /* Window Parameters            */
	};

EXAWORD    WinDex;                         /* Window Index                 */
EXAWORD    DbinitOk;                       /* Flag indicates DB init OK    */

EXAWORD    Couleurs[24][2];        /* Matrice des Couleurs des Fenetres    */
				/* 1 ==> Couleur de fond                */
				/* 0 ==> Couleur caracteres             */

EXTERN  EXAWORD    WindCord[16][2];
BPTR    ScreenBuf;                      /* Screen character buffer      */
BPTR    AtbBuf;                         /* Screen Attribute buffer      */
BPTR    ColorBuf;                       /* Screen Colour Buffer         */
EXAWORD    HoldFore,HoldBack;              /* ColourAtb Holding Variables  */
EXAWORD    COLORATB;                       /* Last Color ATB Required      */
EXAWORD    PhysLin;                        /* Physical Line Counter        */
EXAWORD    ScreenLin;                      /* Number of Lines              */
EXAWORD    ScreenCol;                      /* Width in columns             */
EXAWORD    ScreenDex;                      /* Current Offset               */
EXAWORD    ScreenLen;                      /* Maximum Size                 */
EXAWORD    ScreenAtb;                      /* Current attribute            */
EXAWORD    ScreenFore;                     /* ForeGround Colour            */
EXAWORD    ScreenBack;                     /* BackGround Colour            */

EXAWORD    ScreenFlg;                      /* Current Status               */
EXAWORD    ScreenArg;                      /* Escape Arg Counter           */

EXAWORD    WindFlag;                       /* Window Status Flag           */
EXAWORD    WindCol;                        /* Number of Columns            */
EXAWORD    WindLin;                        /* Number of Lines              */
EXAWORD    WindLno;                        /* Top Line Number              */
EXAWORD    WindCno;                        /* Top Column number            */


EXAWORD    EscMode;                        /* Last Escape Type (for Esc t) */
EXABYTE    ArgZone[32];                    /* Arg Storage Zone             */
EXAWORD    ArgDex;                         /* Arg Index                    */

#include "abalcico.h"
EXTERN  EXAWORD    syskey[];
EXTERN  EXABYTE    askbuf[256];

/*      Sub-Zone Management             */
/*      -------------------             */

BPTR    ZoneStack[ZONEMAX];
EXAWORD    ZoneDex;


/*      Prototypes      */
/*      ----------      */
#ifndef UNIX
VOID    ColourAtb(EXAWORD);
VOID    db_xputch(EXAWORD);
VOID    db_xcprintf(BPTR);
VOID    db_Refresh(VOID);
VOID    db_xpos(EXAWORD,EXAWORD);
VOID    db_xatb(EXAWORD);
EXAWORD    db_xgetch(VOID);
EXAWORD    AsFun_Active(VOID);
EXAWORD	prologue_foreground(VOID);
EXAWORD	prologue_background(VOID);
VOID    LoadWindow( EXAWORD );
VOID    SwapWindow(VOID);
#else
VOID    ColourAtb();
VOID    db_xputch();
VOID    db_xcprintf();
VOID    db_Refresh();
VOID    db_xpos();
VOID    db_xatb();
EXAWORD    db_xgetch();
EXAWORD    AsFun_Active();
EXAWORD	prologue_foreground();
EXAWORD	prologue_background();
VOID    LoadWindow();
VOID    SwapWindow();
#endif


#ifdef  WIN32
void    ExadbCreeFenetre(void);
void    ExadbSupprimeFenetre(void);
void    ExadbSelecteFenetre(void);
#endif

VOID    db_foregr( colour )
EXAWORD    colour;
{
	if ( ScreenFlg & DBCO_TRUE ) { foregr( colour ); }
	ScreenFore = colour;
	return;
}

VOID    db_backgr( colour )
EXAWORD    colour;
{
	if ( ScreenFlg & DBCO_TRUE ) { backgr( colour ); }
	ScreenBack = (colour << 4);
	return;
}

VOID    Painter(forg,bacg)
EXAWORD    forg,bacg;
{
	db_foregr(forg);
	db_backgr(bacg);
	return;
}


EXAWORD    wotatb()
{
	return(ScreenAtb);
}

EXAWORD    wotfore()
{
	return(ScreenFore);
}

EXAWORD    wotback()
{
	return((ScreenBack >> 4));
}

VOID    WindowOff()
{
	WindFlag &= 0xFFFE;
	return;
}

VOID    WindowOn()
{
	WindFlag |= 1;
	return;
}
#ifndef UNIX
#ifndef VMS
#ifndef DOS
VOID    x_clear()
{
	if ( prndest == 1 )     { x_putch(syskey[IO_CLS]);      }
	else                    { x_putch(0x000C);              }
	return;
}
#endif
#endif
#endif

EXAWORD    db_xlin( )
{
#ifdef  ABAL14
	if ( AsFun_Active() != MOINS_UN ) 
		return(x_lin());
#endif  
	return(((ScreenDex / ScreenCol) + 1) );
}

EXAWORD    db_xcol( )
{
#ifdef  ABAL14
	if ( AsFun_Active() != MOINS_UN ) 
		return(x_col());
#endif
	return(((ScreenDex % ScreenCol) + 1) );
}

VOID    DebFrame( cc )
EXAWORD    cc;
{
	EXAWORD    x;
	db_xputch(GRSYM_DA); 
	for (x = 0; x < cc; x++) 
		db_xputch(GRSYM_C4);
	db_xputch(GRSYM_BF);
	return;
}

VOID    FinFrame( cc )
EXAWORD    cc;
{
	EXAWORD    x;
	db_xputch(GRSYM_C0); 
	for (x = 0; x < cc; x++) 
		db_xputch(GRSYM_C4);
	db_xputch(GRSYM_D9);
	return;
}

VOID    AddFrame( lno ,cno ,nbc , nbl )
EXAWORD    lno;
EXAWORD    cno;
EXAWORD    nbc;
EXAWORD    nbl;
{
	EXAWORD    x;
	while ( nbl > 0 ) {
		db_xpos(lno++,cno); db_xputch(GRSYM_B3);
		for ( x = 0; x < nbc; x++ ) 
			db_xputch(' ');
		db_xputch(GRSYM_B3);  nbl--;
		}
	db_xpos(lno,cno);
	FinFrame(nbc); return;
}

VOID    DrawFrame(lno,cno,nbl,nbc)
EXAWORD    lno;
EXAWORD    cno;
EXAWORD    nbl;
EXAWORD    nbc;
{
	EXAWORD    x;
#ifdef  BUF_CICO
	x_bstart();
#endif
	db_xatb(25); db_xpos(lno,cno); DebFrame( nbc );
	while ( nbl > 0 ) {
		db_xpos(++lno,cno); db_xputch(GRSYM_B3);
		for (x = 0; x < nbc ; x++) 
			db_xputch(' ');
		db_xputch(GRSYM_B3);
		nbl--;
		}
	db_xpos(++lno,cno); FinFrame( nbc );            
#ifdef  BUF_CICO
	x_bflush();
#endif
	db_xatb(26); return;    
}

EXAWORD    PushZone( lno , cno , nbl , nbc , PZflag , ZoneFore , ZoneBack )
EXAWORD    lno;
EXAWORD    cno;
EXAWORD    nbl;
EXAWORD    nbc;
EXAWORD    PZflag;
EXAWORD    ZoneFore;
EXAWORD    ZoneBack;
{
	EXAWORD    Zx,Rx,Yx;
	struct ZoneKeep PTR lzptr;
	BPTR    lzbuf;
	EXAWORD    Zlen;

	if ( ZoneDex >= ZONEMAX )        { return(   105     ); }
	if (( cno + nbc ) > ScreenCol )  { return(EXER_SYNTAX); }
	if (( lno + nbl ) > ScreenLin )  { return(EXER_SYNTAX); }
	if ((Zlen = (nbc * nbl)) == 0 )  { return(EXER_SYNTAX); }

	if ((lzptr = (struct ZoneKeep PTR) allocate((USINT)  sizeof(struct ZoneKeep) )) == (struct ZoneKeep PTR) 0 ) {
		return(ABAL_MEMORY);
		}
	if (( PZflag & 4 ) == 0 ) {
		if ( (lzbuf = (BPTR) allocate((USINT) ( Zlen * 3 ) )) == (BPTR) 0) {
			liberate( lzptr );
			return(ABAL_MEMORY);
			}
		}
	else    lzbuf = (BPTR) 0;

	(*(lzptr)).W_Para[0] = WindFlag; 
	(*(lzptr)).W_Para[1] = WindLin; (*(lzptr)).W_Para[2] = WindCol;
	(*(lzptr)).W_Para[3] = WindLno; (*(lzptr)).W_Para[4] = WindCno;

	WindFlag = 0;
	WindLin = nbl; WindCol = nbc;
	WindLno = lno; WindCno = cno;

	(*(lzptr)).Z_buf = lzbuf;       (*(lzptr)).Z_own = WinDex;
	(*(lzptr)).Z_lno = lno;         (*(lzptr)).Z_cno = cno;
	(*(lzptr)).Z_nbl = nbl;         (*(lzptr)).Z_nbc = nbc;
	(*(lzptr)).Z_pos = ScreenDex;   (*(lzptr)).Z_atb  = ScreenAtb;
	(*(lzptr)).Z_for  = ScreenFore; (*(lzptr)).Z_bak  = ScreenBack;

	Rx = 0; Zx = ( ((lno - 1) * ScreenCol) + (cno - 1)); Yx = nbl;
	
	if (( PZflag & 4 ) == 0) {
		while ( nbl > 0 ) {
			memcpy( (lzbuf + Rx) , (ScreenBuf + Zx) , (USINT) nbc );
			memcpy( (lzbuf + Zlen + Rx) , (AtbBuf + Zx) , (USINT) nbc);
			memcpy( (lzbuf + (Zlen * 2) + Rx) , (ColorBuf + Zx) , (USINT) nbc);
			Rx += nbc;
			Zx += ScreenCol;
			nbl--;
			}
		}

	ZoneStack [ ZoneDex++ ] = (BPTR) lzptr;

	/* Check Options */
	/* ------------- */

	/* Check for Colour infos */
	/* ---------------------- */
	if ( PZflag & 0x0010 ) {
		Painter(ZoneFore,ZoneBack);
		ColourAtb(2);   /* Force High Light             */
		ColourAtb(0);   /* Then Normal for palette init */
		}

	/* Check Option Auto Frame */
	/* ----------------------- */
	if ((PZflag & 4) == 0) 
		if ( PZflag & 1 ) 
			DrawFrame(lno,cno,(Yx - 2),(nbc - 2)); 

	/* Check Option Auto HOME  */
	/* ----------------------  */
	if ( PZflag & 2 ) { db_xpos( (lno+1) , (cno+2) );               }
	WindFlag = ((PZflag & 8) | 1);
	return(0);

}
#ifdef  DEBUG_PUSH_ZONE
EXAWORD    WhatPushZone( lno , cno , nbl , nbc , PZflag , ZoneFore , ZoneBack )
EXAWORD    lno;
EXAWORD    cno;
EXAWORD    nbl;
EXAWORD    nbc;
EXAWORD    PZflag;
EXAWORD    ZoneFore;
EXAWORD    ZoneBack;
{
	EXAWORD    result;
	db_xcprintf( (BPTR) " PushZone( ");
	intvisi( lno ); db_xputch(',');
	intvisi( cno ); db_xputch(',');
	intvisi( nbl ); db_xputch(',');
	intvisi( nbc ); db_xputch(',');
	intvisi( PZflag ); db_xputch(',');
	intvisi( ZoneFore ); db_xputch(',');
	intvisi( ZoneBack ); 
	db_xcprintf( (BPTR) " ) == ");
	result = PushZone(lno,cno,nbl,nbc,PZflag,ZoneFore,ZoneBack);
	intvisi( result );      
	x_getch();
	return( result );
}

#endif

EXAWORD    PopZone()
{
	EXAWORD    lno,cno,nbc,nbl;
	EXAWORD    Zx,Rx,Xx,Yx;
	struct ZoneKeep PTR lzptr;
	BPTR    lzbuf;
	EXAWORD    Zlen;
	EXAWORD    Zatb;
	EXAWORD    Zpaint;

	if ( ZoneDex == 0 ) { return( 105 ); }

	lzptr = (struct ZoneKeep PTR) ZoneStack [ --ZoneDex ];

	lzbuf = (*(lzptr)).Z_buf;       
	lno   = (*(lzptr)).Z_lno;       cno = (*(lzptr)).Z_cno;
	nbl   = (*(lzptr)).Z_nbl;       nbc = (*(lzptr)).Z_nbc;

	ScreenDex = (*(lzptr)).Z_pos;

	Rx = 0; Zx = ( ((lno - 1) * ScreenCol) + (cno - 1));
	Zlen = ( nbc * nbl );
	WindFlag = 0;
	db_xatb(25);
	while ( nbl > 0 ) {
		memcpy( (ScreenBuf + Zx ), (lzbuf + Rx) , (USINT) nbc );
		memcpy( (AtbBuf + Zx) ,(lzbuf + Zlen + Rx) ,  (USINT) nbc);
		memcpy( (ColorBuf + Zx) ,(lzbuf + (Zlen * 2) + Rx) ,  (USINT) nbc);

		if ( ScreenFlg & DBCO_TRUE ) {
#ifdef BUF_CICO
			x_bstart();
#endif
			Xx = nbc; Yx = Zx;
			pos(lno++,cno); 
			atb( (Zatb = *(AtbBuf + Yx)) );
			foregr(( (Zpaint = *(ColorBuf + Yx)) & 0x000F));
			backgr( (Zpaint >> 4 ));
			while ( Xx > 0 ) {
				if ( *(AtbBuf + Yx) != Zatb ) {
					atb( (Zatb = *(AtbBuf + Yx)) ); 
					}
				if ( *(ColorBuf + Yx) != Zpaint ) { 
					foregr(( (Zpaint = *(ColorBuf + Yx)) & 0x000F));
					backgr( (Zpaint >> 4 ));
					}
				x_putch(*(ScreenBuf + Yx));
				Yx++; Xx--;
				}
#ifdef BUF_CICO
			x_bflush();
#endif
			}
		Rx += nbc; Zx += ScreenCol; nbl--;
		}
	db_xatb(26);
	db_xpos(((ScreenDex / ScreenCol) + 1),((ScreenDex % ScreenCol) + 1));
	WindFlag = (*(lzptr)).W_Para[0]; WindLin  = (*(lzptr)).W_Para[1];
	WindCol  = (*(lzptr)).W_Para[2]; WindLno  = (*(lzptr)).W_Para[3];
	WindCno  = (*(lzptr)).W_Para[4]; 
	db_xatb((*(lzptr)).Z_atb);
	db_foregr( (*(lzptr)).Z_for );
	db_backgr( ((*(lzptr)).Z_bak >> 4));
	liberate( lzbuf ); liberate( lzptr );
	return(0);

}

EXAWORD    LibZone()
{
	struct ZoneKeep PTR lzptr;

	if ( ZoneDex == 0 ) { return( 105 ); }

	lzptr = (struct ZoneKeep PTR) ZoneStack [ --ZoneDex ];
	ScreenDex = (*(lzptr)).Z_pos;
	db_xpos(((ScreenDex / ScreenCol) + 1),((ScreenDex % ScreenCol) + 1));
	WindFlag = (*(lzptr)).W_Para[0]; WindLin  = (*(lzptr)).W_Para[1];
	WindCol  = (*(lzptr)).W_Para[2]; WindLno  = (*(lzptr)).W_Para[3];
	WindCno  = (*(lzptr)).W_Para[4]; 
	db_xatb((*(lzptr)).Z_atb);
	db_foregr( (*(lzptr)).Z_for );
	db_backgr( ((*(lzptr)).Z_bak >> 4));
	if ( (*(lzptr)).Z_buf != (BPTR) 0)
		liberate( (*(lzptr)).Z_buf );
	liberate( lzptr );
	return(0);

}

/*
 *      Z A D D L Y N E S ( nbl )
 *      -------------------------
 *
 *      Extends the Last Pushed Window By NBL lynes
 *
 */

EXAWORD    ZaddLynes(n)
EXAWORD    n;
{
	EXAWORD    lno,cno,nbc,nbl;
	EXAWORD    Zx,Xx,Yx,Zl;
	struct ZoneKeep PTR lzptr;
	BPTR    lzbuf;
	BPTR    lwbuf;
	EXAWORD    Zlen,Wlen;

	if ( ZoneDex == 0 ) { return( 105 ); }
	lzptr = (struct ZoneKeep PTR) ZoneStack [ (ZoneDex-1) ];
	lzbuf = (*(lzptr)).Z_buf;       
	lno   = (*(lzptr)).Z_lno;       cno = (*(lzptr)).Z_cno;
	nbl   = (*(lzptr)).Z_nbl;       nbc = (*(lzptr)).Z_nbc;
	Zlen = (nbl * nbc);

	/* Check For Exceeding Screen Limits */
	/* --------------------------------- */
	if ( ( lno + nbl + n ) > ScreenLin) { return(103); }

	Wlen = ((nbl + n) * nbc);

	/* Allocate New Zone Storage Buffer */
	/* -------------------------------- */
	if ((lwbuf = (BPTR) allocate((USINT) (Wlen * 3))) == (BPTR) 0) {
		return(ABAL_MEMORY);
		}
	/* Duplicate current Zone Contents */
	/* ------------------------------- */
	(VOID) memcpy((BPTR) lwbuf ,(BPTR) lzbuf , (USINT) Zlen );
	(VOID) memcpy((BPTR) (lwbuf+Wlen) ,(BPTR) (lzbuf+Zlen) , (USINT) Zlen );
	(VOID) memcpy((BPTR) (lwbuf+(Wlen * 2)) ,(BPTR) (lzbuf+(Zlen*2)) , (USINT) Zlen );

	/* Liberate Old Pointer */
	/* -------------------- */
	liberate((BPTR) lzbuf);

	Zl = (lno + nbl - 1); Zx = 0; Xx = n;

	/* Transfer Xx lines from Screen To Zone Storage */
	/* --------------------------------------------- */
	Yx = ((ScreenCol * Zl) + (cno-1));
	while ( Xx > 0 ) {
		(VOID) memcpy((BPTR) (lwbuf + Zlen + Zx) , (ScreenBuf + Yx) , (USINT) nbc);
		(VOID) memcpy((BPTR) (lwbuf + (Wlen+Zlen) + Zx) , (AtbBuf + Yx) , (USINT) nbc);
		(VOID) memcpy((BPTR) (lwbuf + ((Wlen*2) +Zlen) + Zx) , (ColorBuf +Yx), (USINT) nbc);
		Zx += nbc;
		Xx--; Yx += ScreenCol; 
		}
	/* Update Stack Infos */
	/* ------------------ */
	(*(lzptr)).Z_buf = lwbuf;
	(*(lzptr)).Z_nbl += n;

	/* Auto Update Frame */
	/* ----------------- */
	WindFlag = 0;
	WindLin  += n; 
	AddFrame((lno+nbl-1),cno,(nbc-2),n);
	WindFlag = 1;
	return(0);
}

EXAWORD	debug_save_function_keys(char * kbuf)
{
	int	n;
	char *	bptr;
	for (n=1; n < 8; n++ ) {
		bptr = (kbuf + ((n-1)*2));
		*(bptr++) = 1; 
		lcfo(n,bptr,1);
		}
		
	for (n=1; n < 40; n++ ) {
		bptr = ((kbuf + 16) + ((n-1)*33));
		*(bptr++) = 32; 
		lcfo(((n-1)+0x080),bptr,32);
		}
	return(1);
}

VOID	debug_load_function_keys(char * kbuf)
{
	int	n;
	char *	bptr;
	for (n=1; n < 8; n++ ) {
		bptr = (kbuf + ((n-1)*2));
		if ( *bptr != 0 )
			prfo(n,(bptr+1),1);
		}
	for (n=1; n < 40; n++ ) {
		bptr = ((kbuf + 16) + ((n-1)*33));
		*(bptr++) = 32; 
		prfo(((n-1)+0x080),bptr,32);
		}
	return;
}

VOID PushWindow( n )
EXAWORD    n;
{
	EXAWORD	holderr=err_val;
	(*(Window+n)).W_fkeys  = debug_save_function_keys( (*(Window + n)).W_fkey );
	(*(Window + n)).W_Sbuf = ScreenBuf;
	(*(Window + n)).W_Abuf = AtbBuf;
	(*(Window + n)).W_Cbuf = ColorBuf;
	(*(Window + n)).W_Sdex = ScreenDex;
	(*(Window + n)).W_Satb = ScreenAtb;
#ifdef  ABAL21  
	save_mimo_context( (BPTR) (*(Window + n)).W_mouse );    
#endif
	(*(Window + n)).W_Sfor = ScreenFore;
	(*(Window + n)).W_Sbak = ScreenBack;
	
	(*(Window + n)).W_Sarg = ScreenArg;
	(*(Window + n)).W_Sesc = EscMode;
	(*(Window + n)).W_Edex = ArgDex;
	memcpy( (*(Window + n)).W_Earg ,(BPTR) ArgZone , (USINT) 32);
	(*(Window + n)).W_Sflg = ScreenFlg;
	(*(Window + n)).W_Para[0] = WindFlag;
	(*(Window + n)).W_Para[1] = WindLin;
	(*(Window + n)).W_Para[2] = WindCol;
	(*(Window + n)).W_Para[3] = WindLno;
	(*(Window + n)).W_Para[4] = WindCno;
	err_val = holderr;
	return;

}

VOID PopWindow( n )
EXAWORD    n;
{
	EXAWORD	holderr=err_val;
	if ( (*(Window+n)).W_fkeys != 0 ) {
		debug_load_function_keys( (*(Window + n)).W_fkey );
		}
	ScreenBuf       = (*(Window + n)).W_Sbuf;
	AtbBuf          = (*(Window + n)).W_Abuf;
	ColorBuf        = (*(Window + n)).W_Cbuf;
	ScreenDex       = (*(Window + n)).W_Sdex;
	ScreenAtb       = (*(Window + n)).W_Satb;

	ScreenFore      = (*(Window + n)).W_Sfor;
	ScreenBack      = (*(Window + n)).W_Sbak;

	ScreenArg       = (*(Window + n)).W_Sarg;
	EscMode         = (*(Window + n)).W_Sesc;
	ArgDex          = (*(Window + n)).W_Edex;
	memcpy( (BPTR) ArgZone , (*(Window + n)).W_Earg , (USINT) 32);
	ScreenFlg       = (*(Window + n)).W_Sflg;
	(*(Window + n)).W_Sflg = ScreenFlg;
	WindFlag = (*(Window + n)).W_Para[0];
	WindLin  = (*(Window + n)).W_Para[1];
	WindCol  = (*(Window + n)).W_Para[2];
	WindLno  = (*(Window + n)).W_Para[3];
	WindCno  = (*(Window + n)).W_Para[4];
#ifdef  ABAL21  
	restore_mimo_context( (BPTR) (*(Window + n)).W_mouse ); 
#endif
	err_val = holderr;
	return; 

}

VOID    InitFail( x )
EXAWORD    x;
{
	if ( x == 1 ) {
		PopWindow(0);
		liberate(ScreenBuf); ScreenBuf = (BPTR) 0;
		liberate(AtbBuf);    AtbBuf    = (BPTR) 0;
		liberate(ColorBuf);  ColorBuf  = (BPTR) 0;
		}
	liberate(Window);
	Window    = (struct Fenetre PTR) 0; 
}

/*
 *      D B _ I N I T E R M ( )
 *      -----------------------
 *      Initialise Debuger Console controller
 */

EXAWORD    db_initerm()
{
	EXAWORD    x,y;

	DbinitOk = 0;
	exadb_ungotc = 0;

#ifdef UNIX
	if (!( exa_is_X11 )) {
#endif

#ifdef  DOS
		initermexa(0);
#else
		initerm();
#endif
#ifdef  ABAL21
#ifndef CICOMIMO
		init_mimo();
#endif
		init_fkey_storage();
#endif  
#ifdef  WIN1632
		ExadbCreeFenetre();
#endif

#ifdef UNIX
		}
#endif

	Window = (struct Fenetre PTR) allocate( (USINT) (sizeof( struct Fenetre )  * 2) );
	if ( Window == (struct Fenetre PTR) 0 ) { return(ABAL_MEMORY); }
	PhysLin   = (INITSLIN);
	ScreenLin = (PhysLin & 0xFFFE);
	ScreenLen = (PhysLin * (ScreenCol = INITSCOL ));
	if (ScreenLen == 0 ) {  return(1);  }
	WindCol = ScreenCol; WindLin = PhysLin;
	for ( x =0; x < 2; x++ ) {
		(*(Window+x)).W_fkeys  = 0; 
		if ( (ScreenBuf = (BPTR) allocate((USINT)  (ScreenLen + conf(13)) )) == (BPTR) 0 ) {
			InitFail(x);
			return(ABAL_MEMORY);
			}
		if ( (AtbBuf = (BPTR) allocate((USINT)  (ScreenLen + conf(13)) )) == (BPTR) 0 ) {
			liberate( ScreenBuf );
			InitFail(x);
			return(ABAL_MEMORY);
			}
		if ( (ColorBuf = (BPTR) allocate((USINT)  (ScreenLen + conf(13)) )) == (BPTR) 0 ) {
			liberate( AtbBuf );
			liberate( ScreenBuf );
			InitFail(x);
			return(ABAL_MEMORY);
			}
		memset( ScreenBuf ,(USINT)  ' ' , (USINT) ScreenLen );
		memset( AtbBuf    ,(USINT)  0   , (USINT) ScreenLen );
		memset( ColorBuf  ,(USINT) COULEUR , (USINT) ScreenLen ); 
		ScreenDex = 0; ScreenAtb = 0; ScreenFlg = 0; 
		ScreenFore = WASHFORE;    ScreenBack = WASHBACK;

		/* Initialise Colours Matrix */
		/* ------------------------- */
		if (((y = ABAL_Index) > '1')
		||  ((y = ABAL_Version) > '1')) {

			/* Version 1.2a */
			/* ------------ */
			/* Error Window */
			/* ------------ */
			Couleurs[12][0] = Rouge;
			Couleurs[12][1] = GrisClair;

			/* Zoom Ctrl Z Window */
			/* ------------------ */
			Couleurs[3][0] = Bleu;
			Couleurs[3][1] = GrisClair;

			/* Help Screens */
			/* ------------ */
			Couleurs[10][0] = Jaune;
			Couleurs[10][1] = Vert; 

			/* Commande / Exit Windows */
			/* ----------------------- */
			Couleurs[5][0] = Blanc;
			Couleurs[5][1] = Marron;        
			Couleurs[13][0] = Blanc;
			Couleurs[13][1] = Marron;       

			/* Liste Windows */
			/* ------------- */
			Couleurs[2][0] = Blanc;
			Couleurs[2][1] = Cyan;
			Couleurs[6][0] = Blanc;
			Couleurs[6][1] = Cyan;
			Couleurs[8][0] = Blanc;
			Couleurs[8][1] = Cyan;

			/* Variable Display / Modifs */
			/* ------------------------- */
			Couleurs[7][0] = Vert;
			Couleurs[7][1] = GrisClair;

			/* Dump Hex */
			/* -------- */
			Couleurs[9][0] = Jaune;
			Couleurs[9][1] = Bleu;

			/* Observation Window */
			/* ------------------ */
			Couleurs[4][0] = Jaune;
			Couleurs[4][1] = Marron;

			/* List Window  */
			/* ------------ */
			Couleurs[14][0] = GrisClair;
			Couleurs[14][1] = Bleu;
			Couleurs[15][0] = CyanClair;
			Couleurs[15][1] = Bleu;

			/* Other Windows */
			/* ------------- */
			Couleurs[11][0] = Blanc;
			Couleurs[11][1] = Noir;
			Couleurs[1][0] = Blanc;
			Couleurs[1][1] = Noir;
			Couleurs[0][0] = Blanc;
			Couleurs[0][1] = Noir;

			}
		else    {
			/* Version 1.1 d */
			/* ------------- */
			for ( y = 0; y <= 16; y++ ) {
				Couleurs[y][0] = Vert;
				Couleurs[y][1] = Noir;
				}
			}
		/* Establish Default Window Coordinates */
		/* ------------------------------------ */
		for ( y = 0; y < 16; y++ ) {
			WindCord[y][0] = 1;
			WindCord[y][1] = 1;
			}
		WindCord[5][0] = 5;
		WindCord[5][1] = 5;
		WindCord[12][0] = 5;
		WindCord[12][1] = 5;
		WindCord[13][0] = 5;
		WindCord[13][1] = 5;

		/* Attempt to Load from EXADB.CFG */
		/* ------------------------------ */
		(VOID) ParaCharge();
		WindFlag = 9;
		PushWindow(x);
		}

	/* Set Window to Debug Screen */
	/* -------------------------- */
	WinDex = 0; PopWindow( 0 );
	ScreenFlg = DBCO_TRUE;
	db_Refresh();
#ifdef  PUSHPOP
	PopBase = (struct pushpop PTR) 0;
#endif
	DbinitOk = 1;
	return(0);

}


/*
 *      D B _ F I N T E R M ( )
 *      -----------------------
 *      Liberate Debug Console Controller
 */

VOID    db_finterm(mode)
EXAWORD    mode;
{
	EXAWORD    x;

#ifdef  PUSHPOP
	struct pushpop PTR tptr;
#endif

	if ( DbinitOk == 1 ) {
		for ( x = 0; x < 2; x++ ) {
			liberate( (*(Window + x)).W_Sbuf );
			liberate( (*(Window + x)).W_Abuf );
			liberate( (*(Window + x)).W_Cbuf );
			 (*(Window + x)).W_Sbuf = 
			 (*(Window + x)).W_Abuf = 
			 (*(Window + x)).W_Cbuf = 0;

			}
#ifdef  PUSHPOP
		while ( PopBase != (struct pushpop PTR) 0) {
			liberate( PopBase->pntptr );
			liberate( PopBase->atbptr );
			liberate( PopBase->scrptr );
			tptr = PopBase;
			PopBase = PopBase->fwdptr;
			liberate( tptr );
			}
#endif
		liberate( Window );
		Window = 0;
		DbinitOk = 0;
		}
	atb(0);

#ifdef  WIN1632
	ExadbSupprimeFenetre();
#endif

#ifdef  ABAL21
	liber_fkey_storage();
#ifndef CICOMIMO
	fin_mimo();
#endif
#endif
	finterm(mode);
	return;
}


/*
 *      D B _ X P O S ( lno , cno )
 *      ---------------------------
 */

VOID    db_xpos( lno , cno )
EXAWORD    lno;
EXAWORD    cno;
{
	/* Do not limit printers */
	/* --------------------- */
	if ( prndest != 1 ) {
		pos( lno , cno );
		return;
		}

	/* Ensure screen limits respected */
	/* ------------------------------ */
	if ( lno > ScreenLin ) lno = ScreenLin;
	if ( cno > ScreenCol ) cno = ScreenCol;
	if ( lno < 1 ) lno = 1;
	if ( cno < 1 ) cno = 1;

	/* Perform screen positioning */
	/* -------------------------- */
	if ( ScreenFlg & DBCO_TRUE ) { pos( lno , cno ); }
	ScreenDex = (( (lno - 1) * ScreenCol ) + (cno - 1));

	return;
}

/*      
 *      Allows Curser positioning with respect to Window Coords
 *      -------------------------------------------------------
 */

VOID    wdw_xpos( lno , cno )
EXAWORD    lno,cno;
{
	db_xpos( (lno + WindLno), ( cno + WindCno ) );
	return;
}

VOID    KlearLine()
{
	EXAWORD    x;
	if ( ScreenFlg & DBCO_TRUE ) { atb(21); }
	x = (ScreenCol - db_xcol());
	if ( db_xlin() < ScreenLin ) { x++; } 
	if ( x > 0 ) {
		memset((ScreenBuf + ScreenDex),(USINT) ' ',(USINT) x);
		memset((AtbBuf    + ScreenDex),(USINT)  0 ,(USINT) x);
		memset((ColorBuf  + ScreenDex),(USINT)  ScreenFore ,(USINT) x);
		}
	return;
}

VOID    KlearPage()
{
	EXAWORD    x;
	if ( ScreenFlg & DBCO_TRUE ) { atb(22); }
	x = (ScreenLen - ScreenDex);
	if ( x > 0 ) {
		memset((ScreenBuf + ScreenDex),(USINT) ' ',(USINT) x);
		memset((AtbBuf    + ScreenDex),(USINT)  0 ,(USINT) x);
		memset((ColorBuf    + ScreenDex),(USINT) ScreenFore ,(USINT) x);
		}
	return;
}

VOID    db_xclear()
{
	if (( prndest != 1) || ( ScreenFlg & DBCO_TRUE )) { x_clear(); }
	if ( prndest == 1 ) {
		memset( ScreenBuf , (USINT) ' '     , (USINT) ScreenLen );
		memset( AtbBuf    , (USINT) 0       , (USINT) ScreenLen );
		memset( ColorBuf  , (USINT) COULEUR , (USINT) ScreenLen );
		COLORATB = 0;
#ifdef  PROLOGUE
		HoldFore = prologue_foreground();
		HoldBack = prologue_background();
#else
		HoldFore = 7; HoldBack = 0;
#endif
		ScreenDex = 0; ScreenAtb = 0;
		}
	return;
}

VOID    db_xhome()
{
	if ( ScreenFlg & DBCO_TRUE ) { pos(1,1); }
	ScreenDex = 0;
	return;
}

VOID    InserLine()
{
	EXAWORD    debline;
	EXAWORD    debut;
	EXAWORD    x;
	
	if ((debline = db_xlin()) < ScreenLin ) {
		for (x = ScreenLin; x > debline; x-- ) {
			debut = ((x-1) * ScreenCol);
			if ( debut > 0 ) {
				memcpy((BPTR) (ScreenBuf + debut), (BPTR) (ScreenBuf + debut - ScreenCol), (USINT) ScreenCol );
				memcpy((BPTR) (AtbBuf    + debut), (BPTR) (AtbBuf    + debut - ScreenCol), (USINT) ScreenCol );
				memcpy((BPTR) (ColorBuf  + debut), (BPTR) (ColorBuf  + debut - ScreenCol), (USINT) ScreenCol );
				}
			}
		}
	debut = ((debline-1) * ScreenCol);
	memset((ScreenBuf + debut),(USINT) ' ',(USINT) ScreenCol);
	memset((AtbBuf    + debut),(USINT)  0 ,(USINT) ScreenCol);
	memset((ColorBuf  + debut),(USINT)  ScreenFore ,(USINT) ScreenCol);
	return;
}

VOID    SupreLine()
{
	EXAWORD    debut,length;

	/* Calculate Start Offset of Line */
	/* ------------------------------ */
	debut  = ((db_xlin() - 1) * ScreenCol);

	/* Calculate Transfer Length */
	/* ------------------------- */
	length = ((ScreenLin - db_xlin()) * ScreenCol); 

	if ( length > 0 ) {
		memcpy((BPTR) (ScreenBuf + debut), (BPTR) (ScreenBuf + debut + ScreenCol) , (USINT) length );
		memcpy((BPTR) (AtbBuf    + debut), (BPTR) (AtbBuf    + debut + ScreenCol) , (USINT) length );
		memcpy((BPTR) (ColorBuf  + debut), (BPTR) (ColorBuf  + debut + ScreenCol) , (USINT) length );
		}
	debut = ((ScreenLin - 1) * ScreenCol);
	memset((ScreenBuf + debut),(USINT) ' ',(USINT) ScreenCol);
	memset((AtbBuf    + debut),(USINT)  0 ,(USINT) ScreenCol);
	memset((ColorBuf  + debut),(USINT)  ScreenFore ,(USINT) ScreenCol);
	return;
}

VOID    Scrollup()
{
	EXAWORD    l;

	l = (ScreenLen - ScreenCol);

	memcpy(ScreenBuf , (ScreenBuf + ScreenCol) ,(USINT) l );
	memcpy(AtbBuf    , (AtbBuf    + ScreenCol) ,(USINT) l );
	memcpy(ColorBuf  , (ColorBuf  + ScreenCol) ,(USINT) l );

	memset((ScreenBuf + l)  , ' ',(USINT) ScreenCol );
	memset((AtbBuf + l)     , 0  ,(USINT) ScreenCol );
	memset((ColorBuf + l)   , 7  ,(USINT) ScreenCol );

	return;

}


/*
 *      E s c A r g s ( Mode )
 *      ----------------------
 */

VOID EscArgs( nbarg )
EXAWORD    nbarg;
{
	if ( nbarg > 0 ) { ScreenArg = nbarg; ScreenFlg |= DBCO_ARG; ArgDex = 0; }
	else             { 
		ScreenFlg &= DBCO_NORM; 
		switch ( EscMode ) {
			case 'f' : db_xpos(( ArgZone[0] - 0x001F ) , ( ArgZone[1] - 0x001F )); return;
			case 'T' : ScreenArg = Tcodeword( ((BPTR) ArgZone) );
				   ScreenFlg |= DBCO_PASS; return;
			case 'r' : db_foregr( ArgZone[0] ); return; 
			case 'n' :
			case 's' : db_backgr( ArgZone[0] ); return;
			}
		}
	return;
}

/*
 *      D B _ X A T B ( natb )
 *      ----------------------
 *      Debug Attribut control
 */

VOID    db_xatb( natb )
EXAWORD    natb;
{
#ifdef UNIX
	if ( exa_is_X11 == 2 )   { atb(natb); return; }
#endif
	if ( prndest != 1 ) { atb(natb); }
	else    {
		switch ( natb ) {
			case 21 : KlearLine(); return;
			case 22 : KlearPage(); return;
			case 23 : InserLine();  
				  if ( ScreenFlg & DBCO_TRUE ) { atb( natb ); }
				  return;
			case 24 : SupreLine(); 
				  if ( ScreenFlg & DBCO_TRUE ) { atb( natb ); }
				  return;
			default : if ( ScreenFlg & DBCO_TRUE ) { atb( natb ); }
				  if ( natb < 20 ) { ScreenAtb = natb; }
			}
		}
	return;
}


VOID    ColourAtb( natb )
EXAWORD    natb;
{
	if ( conf(14) == 0 )    { db_xatb(natb); }
	else    {
		if ( natb != 0 ) {
			if ( COLORATB != 2 ) {
				HoldFore = wotfore();
				HoldBack = wotback();
				Painter( Noir , GrisClair );
				}
			}
		else    {
			if ( COLORATB != 0 ) {
				Painter( HoldFore , HoldBack );
				}
			}
		}
		COLORATB = natb;
	return;
}

#ifdef  PUSHPOP
/* 
 *      Gestion du ESC >        Push Screen
 *      ----------------        -----------
 *
 */

VOID    PushScreen()
{
	struct pushpop  PTR tptr;

	/* Allocate an new list entry structure */
	/* ------------------------------------ */
	tptr = (struct pushpop PTR ) allocate( sizeof( struct pushpop ) );
	if ( tptr == ( struct pushpop PTR ) 0 ) {
		return;
		}

	/* Allocate the Storage pointers SCREEN , ATB and COLOUR */
	/* ----------------------------------------------------- */
	if ( (tptr->scrptr = (BPTR) allocate( (USINT) ScreenLen )) == (BPTR) 0 ) {
		liberate( tptr );
		return;
		}
	if ( (tptr->atbptr = (BPTR) allocate( (USINT) ScreenLen )) == (BPTR) 0 ) {
		liberate( tptr->scrptr );
		liberate( tptr );
		return;
		}
	if ( (tptr->pntptr = (BPTR) allocate( (USINT) ScreenLen )) == (BPTR) 0 ) {
		liberate( tptr->atbptr );
		liberate( tptr->scrptr );
		liberate( tptr );
		return;
		}

	/* Copy Current Screen infos to Storage */
	/* ------------------------------------ */
	(VOID) memcpy( tptr->scrptr , ScreenBuf , (USINT) ScreenLen );
	(VOID) memcpy( tptr->atbptr , AtbBuf    , (USINT) ScreenLen );
	(VOID) memcpy( tptr->pntptr , ColorBuf , (USINT) ScreenLen );

	/* Ensure Forward Linkage */
	/* ---------------------- */
	tptr->fwdptr = PopBase; PopBase = tptr;
	return;
}

#ifdef	NOGIGO
static	void	use_pixel_primary(int v) { return; }
static	void	use_pixel_alternative(int v) { return; }
#endif

/*      Establish Program Window as active for writing          */
/*      ----------------------------------------------          */
VOID    ProgramWindow()
{
	LoadWindow((EXAWORD) 1);
	if ( ExWindow == 0 ) { 
#ifdef UNIX
		if ( exa_is_X11 == 2 ) 
			use_pixel_primary(1);
		else	SwapWindow(); 
#else 
		SwapWindow(); 
#endif
		ExWindow = 1; 
		DbWindow = 0;
		}

	return;
}

/*      Establish Debug window as active for writing            */
/*      --------------------------------------------            */
VOID    MoniteurWindow()
{
	LoadWindow((EXAWORD) 0); 
	if ( DbWindow == 0 ) { 
#ifdef UNIX
		if ( exa_is_X11 == 2 ) 
			use_pixel_alternative(1);
		else	SwapWindow();
#else 
		SwapWindow(); 
#endif
		ExWindow = 0;
		DbWindow = 1;
		}
	return;
}

/*
 *      Gestion de ESC '<'      :       Pop Screen
 *      ------------------------------------------      
 *
 */

VOID    PopScreen()
{
	struct pushpop PTR tptr;
	if ( PopBase != (struct pushpop PTR) 0 ) {
		memcpy( ScreenBuf , PopBase->scrptr , (USINT) ScreenLen );
		memcpy( AtbBuf    , PopBase->atbptr , (USINT) ScreenLen );
		memcpy( ColorBuf  , PopBase->pntptr , (USINT) ScreenLen );
		liberate(PopBase->pntptr);
		liberate(PopBase->atbptr);
		liberate(PopBase->scrptr);
		tptr = PopBase;         
		PopBase = tptr->fwdptr;
		liberate( tptr );
		}
	return;
}

#endif
	
/*
 *      D B _ X P U T C H ( c )
 *      -----------------------
 *      Debug character output
 */

VOID    db_xputch( c )
EXAWORD    c;
{
	EXAWORD    outctrue;

#ifdef UNIX	
	if ( exa_is_X11 == 2 )	{ x_putch( c ); return; }
#endif

	if ( prndest != 1 ) 	{ x_putch( c ); return; }

	outctrue = 1;

	if ( ScreenFlg & DBCO_ESC ) {
		if ( ScreenFlg & DBCO_ARG ) {
			ArgZone[ArgDex++] = (EXABYTE) c;
			if ( ArgDex >= ScreenArg ) { EscArgs(0); return; }
			return;
			}
		else    {
			switch ( (EscMode = c) ) {
#ifdef  PUSHPOP
				case '>' : /* Push Screen */
					   /* ----------- */
					ScreenFlg &= DBCO_NORM;
					ProgramWindow();
					x_putch( 0x001B );
					x_putch( '>'); 
					PushScreen();
					return;

				case '<' : /* Pop  Screen */
					   /* ----------- */
					ScreenFlg &= DBCO_NORM;
					ProgramWindow();
					x_putch( 0x001B );
					x_putch( '<'); 
					PopScreen();
					return;
#endif

				case 'a' : ScreenFlg &= DBCO_NORM; db_xatb(0); return;
				case 'b' :
				case 'p' : ScreenFlg &= DBCO_NORM; db_xatb(2); return; 
				case 'c' : ScreenFlg &= DBCO_NORM; db_xatb(3); return; 
				case 'd' : ScreenFlg &= DBCO_NORM; db_xatb(4); return; 
				case 'e' : ScreenFlg &= DBCO_NORM; db_xatb(5); return; 
				case 'h' : ScreenFlg &= DBCO_NORM; db_xatb(6); return; 
				case 'i' : ScreenFlg &= DBCO_NORM; db_xatb(7); return; 
				case 'j' : ScreenFlg &= DBCO_NORM; db_xatb(8); return; 
#ifndef PUSHPOP
				case '<' :
#endif
				case 'x' : ScreenFlg &= DBCO_NORM; db_xatb(10); return; 
#ifndef PUSHPOP
				case '>' :
#endif
				case 't' :
				case 'z' :
				case 'y' : ScreenFlg &= DBCO_NORM; db_xatb(11); return; 

				case 'f' : 
				case 'T' : EscArgs(2); return;
				case 'r' :
				case 'n' :
				case 's' : EscArgs(1); return;
				case 'J' : KlearPage(); ScreenFlg &= DBCO_NORM; return;
				case 'K' : KlearLine(); ScreenFlg &= DBCO_NORM; return;
				case 'L' : InserLine(); ScreenFlg &= DBCO_NORM; return;
				case 'M' : SupreLine(); ScreenFlg &= DBCO_NORM; return;
				default  : ScreenFlg &= DBCO_NORM; return;
				}
			}
		}
	else    {

		if (( ScreenFlg & DBCO_PASS ) == 0 ) { 
			switch ( c ) {
				case 0x0008 : ScreenDex--; outctrue = 0; break;
				case 0x0006 : ScreenDex++; outctrue = 0; break;
				case 0x000B : ScreenDex -= ScreenCol; outctrue = 0; break;
				case 0x001B : ScreenFlg  |= DBCO_ESC; return;
				case 0x000D : ScreenDex = ((ScreenDex / ScreenCol) * ScreenCol); outctrue = 0; break;
				case 0x0005 :
				case 0x000A : ScreenDex = (((ScreenDex / ScreenCol) * ScreenCol) + ScreenCol);
					      if ( ScreenDex >= ScreenLen ) {
							Scrollup(); ScreenDex -= ScreenCol;
							}
					      outctrue = 0; break;
				case 0x000C : db_xclear(); return;
				case 0x001C : db_xhome();  return;
				}
			}

		if ( outctrue != 0 ) {
			/* Standard Character OutPut */
			/* ------------------------- */
			*(ScreenBuf + ScreenDex) = (EXABYTE) c;
			*(AtbBuf    + ScreenDex) = (EXABYTE) ScreenAtb;
			*(ColorBuf  + ScreenDex) = (EXABYTE) (ScreenBack | ScreenFore);
			ScreenDex++;
			}

		if ( ScreenFlg & DBCO_TRUE) { x_putch( c ); }

		if ( ScreenFlg & DBCO_PASS ) { 
			ScreenArg--;
			if ( ScreenArg == 0 ) { ScreenFlg &= DBCO_NORM; }
			}
		if ( WindFlag & 1 ) {
			if (( ScreenDex % ScreenCol ) >= ((WindCno + WindCol) - 2)) {
				if ( (c = db_xlin()) > ((WindLno + WindLin) - 2)) {
					if ((WindFlag & 8) == 0)
						ScreenDex = ((WindLno * ScreenCol) + (WindCno + 1));
					}
				else    {
					if ((WindFlag & 8) == 0)
						ScreenDex = ((c  * ScreenCol) + (WindCno + 1));
					}
				db_xpos(((ScreenDex / ScreenCol) + 1),((ScreenDex % ScreenCol) + 1));
				}
			}
		else    {
			if ( ScreenDex >= ScreenLen ) {
				Scrollup(); ScreenDex -= ScreenCol;
				}
			}
		}
	return;

}

/*
 *      D B _ X C P R I N T F ( cptr )
 *      ------------------------------
 *      Debug string output
 */

VOID    db_xcprintf( cptr )
BPTR    cptr;
{
	while ( *cptr != (EXABYTE) 0 ) { db_xputch( ((EXAWORD)  *(cptr++)) ); }
	return;
}

VOID    db_Cls()
{
	x_clear();
}

/*      Refreshs the Current Screen View from buffered informations
 *      -----------------------------------------------------------
 */

VOID    db_Refresh()
{
	EXAWORD    latb,ldex;
	EXAWORD    lpaint;
#ifdef UNIX
	if ( exa_is_X11 == 2 )	{ return; }
#endif

	/* Cancell all refresh requests when ASFUN is active */
	/* ------------------------------------------------- */
	if ( AsFun_Active() != MOINS_UN ) { return; }

#ifdef  BUF_CICO
	x_bstart();
#endif
	prndest = 1;
	atb(25); pos(1,1); atb(0);
	atb( (latb = (EXAWORD) *AtbBuf)); 
	foregr( ( (lpaint = ((EXAWORD) *ColorBuf)) & 0x000F) );            
	backgr( ( lpaint >> 4 ) );
	ldex = 0;
	while ( ldex < (ScreenLen - 1) ) {
		if ( (EXAWORD) *(AtbBuf + ldex) != latb ) {
			atb( (latb = (EXAWORD) *(AtbBuf + ldex))); 
			}
		if ( (EXAWORD) *(ColorBuf + ldex) != lpaint ) {
			foregr( ( (lpaint = ((EXAWORD) *(ColorBuf + ldex))) & 0x000F) );
			backgr( ( lpaint >> 4 ) );
			}
		x_putch( *(ScreenBuf + ldex) );
		ldex++;
		}
	pos( ((ScreenDex / ScreenCol) + 1) , ((ScreenDex % ScreenCol) + 1));
	atb( ScreenAtb );
	foregr( ScreenFore );
	backgr( (ScreenBack >> 4 ) );

#ifdef  BUF_CICO
	x_bflush();
#endif
	atb(26); return;
}

EXAWORD    idb_Ladr( lno )
EXAWORD    lno;
{
	EXAWORD    x,y,width;
	errno = 0;

#ifdef UNIX
	if ( exa_is_X11 == 2 )	{ return(0); }
#endif

	if ( lno > ScreenLin )  { errno = 4; return(MOINS_UN);  }
	if ( lno > 0 )          { lno--;                        }
	x = ((lno * ScreenCol) + WindCord[14][1]);
	width = (ScreenCol - WindCord[14][1]);
	for ( y = 0; y <= width; y++,x++ ) {
		if ( *(ScreenBuf + x) == '(' ) {
			return(hextoi( (ScreenBuf + x + 1) , 4));
			}
		}
	errno = 4; return(MOINS_UN);
}

VOID    idb_Lpaint(lno , forg, backg )
EXAWORD    lno,forg,backg;
{
	EXAWORD    x,l;

#ifdef UNIX
	if ( exa_is_X11 == 2 )	{ return; }
#endif

	if ( lno > ScreenLin )  { return;       }
	if ( lno > 0 )          { lno--;        }
	x = ((lno * ScreenCol) + WindCord[14][1]);
	l = ((ScreenCol - 1) - WindCord[14][1]);
	memset( (ColorBuf + x) ,(USINT)  (forg | (backg << 4)), (USINT) l );
	return;

}
VOID    idb_Latb( lno , natb )
EXAWORD    lno;
EXAWORD    natb;
{
	EXAWORD    x,l;

#ifdef UNIX
	if ( exa_is_X11 == 2 )	{ return; }
#endif

	if ( lno > ScreenLin )  { return;       }
	if ( lno > 0 )          { lno--;        }
	x = ((lno * ScreenCol) + WindCord[14][1]);
	l = ((ScreenCol - 1) - WindCord[14][1]);
	memset( (AtbBuf + x) ,(USINT)  natb , (USINT) l );
	return;
	
}

VOID    idb_Lrefresh( nb )
EXAWORD    nb;
{
	EXAWORD x,y,latb,lpaint;
	EXAWORD    lno,cno;

#ifdef UNIX
	if ( exa_is_X11 == 2 )	{ return; }
#endif

	/* Save Current Infos */
	/* ------------------ */
	lno = db_xlin(); cno = db_xcol();

#ifdef  BUF_CICO
	x_bstart();
#endif
	atb(25); db_xpos(nb--,1);
	x = (nb * ScreenCol); y = ScreenCol;    
	atb( (latb = (EXAWORD) *(AtbBuf + x))); 
	foregr( ( (lpaint = (EXAWORD) *(ColorBuf + x)) & 0x000F) );                
	backgr( ( lpaint >> 4 ) );
	if ( nb == 24 ) { y--; }
	while ( y > 0 ) { 
		if ( (EXAWORD) *(AtbBuf + x) != latb ) {
			atb( (latb = (EXAWORD) *(AtbBuf + x))); 
			}
		if ( (EXAWORD) *(ColorBuf + x) != lpaint ) {
			foregr( ( (lpaint = (EXAWORD) *(ColorBuf + x)) & 0x000F) );                
			backgr( ( lpaint >> 4 ) );
			}
		x_putch( *(ScreenBuf + x) );
		x++; y--;
		}

	/* Restore Callers Entry Condition */
	/* ------------------------------- */
	pos(lno,cno);                   /* Reposition Curser    */
	atb( ScreenAtb );               /* Current Attribut     */
	foregr( ScreenFore );           /* ForeGround Colour    */
	backgr( (ScreenBack >> 4 ) );   /* BackGround Colour    */
	atb(26);                        /* Curser Back On ??    */

#ifdef  BUF_CICO
	x_bflush();                     /* Flush Buffers Now    */
#endif
	return;                         /* Return to Caller     */
}

VOID    LoadWindow( w )
EXAWORD    w;
{

#ifdef UNIX
	if ( exa_is_X11 == 2 )	{ return; }
#endif

	if ( w != WinDex ) {
		PushWindow(WinDex);
		PopWindow((WinDex = w));
		}
	return;
}

/*
 *      Force Program Output to Screen for ASFUN
 *      ----------------------------------------
 *
 */

EXAWORD    HoldForce;

VOID    ForceProgram()
{
	HoldForce = ScreenFlg;

#ifdef  ABAL14
#ifdef  ABALPS
	/* Ensure program Window always Active */
	/* ----------------------------------- */
	if ( AsFun_Active() != MOINS_UN ) {
		ScreenFlg |= DBCO_TRUE;
		}
#endif
#endif
	return;
}

VOID    UnForceProgram()
{
	ScreenFlg = HoldForce;
	return;
}


/*
 *      S W A P _ W I N D O W ( window , mode )
 *      ---------------------------------------
 *      Changes Currently active Window and displays it's contents.
 *      The variable WINDEX indicates the currently active window :
 *
 *              DEBUG WINDOW    0
 *              PROGRAM WINDOW  1
 *
 *      Version 1.4 also performs debug ASFUN window hide/show from
 *      this same function.
 *
 *      The screen status flag SCREENFLG indicates whether a window
 *      is currently active on output via the bit value DBCO_TRUE.
 *      When true it indicates that the currently loaded screen context
 *      is also the currently visible screen context.
 *      
 *      Problems due to ASFUN
 *      ---------------------
 *      The program output must always be active when the ASFUN mode
 *      is active. The program shadow screen will never be refreshed
 *      either.
 *
 */

VOID    SwapWindow()
{
	EXAWORD    x;


#ifdef UNIX
	if ( exa_is_X11 == 2 )	{ return; }
#endif

	/* Establish Other Window ID */
	/* ------------------------- */
	if ( WinDex == 0 ) { x = 1; }
	else               { x = 0; }

#ifdef  ABAL14
#ifdef  ABALPS
	/* Perform Window Swaping */
	/* ---------------------- */
	(VOID) AsFun_SwapState();
#endif
#endif
	
	/* Test Current Window for OUTPUT ACTIVE */
	/* ------------------------------------- */
	if (( ScreenFlg & DBCO_TRUE ) == 0 ) {

		/* Not Active for OUTPUT so Refresh it */
		/* ----------------------------------- */
		ScreenFlg |= DBCO_TRUE;    db_Refresh();

		/* Dissactivate other Window */
		/* ------------------------- */
		(*(Window + x)).W_Sflg &= DBCO_FAUX;
		return;

		}

	/* -------------------------------- */
	/* Current Window is already Active */
	/* -------------------------------- */

	/* Dissactivate and Save Current Window */
	/* ------------------------------------ */
	ScreenFlg &= DBCO_FAUX; PushWindow(WinDex);

	/* Load Other Window and Activate it */
	/* --------------------------------- */
	PopWindow(x);           ScreenFlg |= DBCO_TRUE;

	/* Refresh other Window then Save it */
	/* --------------------------------- */
	db_Refresh();           PushWindow(x);

	/* Recover Current Window */
	/* ---------------------- */
	PopWindow(WinDex);

	return;
	
}

VOID    DbSight()
{
	if ( ExWindow == 1 ) {
		DbWindow = 1; ExWindow = 0;

#ifdef UNIX
		if ( exa_is_X11 == 2 ) 
			use_pixel_alternative(1);
		else	SwapWindow();
#else
		SwapWindow();
#endif
		}
	return;
}


VOID    SwapView()
{

#ifdef UNIX
	if ( exa_is_X11 == 2 ) {
		if ( ExWindow )
			use_pixel_primary(1);
		else	use_pixel_alternative(1);
		}
	else if ( AsFun_Active() != MOINS_UN ) 
		AsFun_SwapView();
	else    SwapWindow();
#else
	if ( AsFun_Active() != MOINS_UN )
		AsFun_SwapView();
	else    SwapWindow();
#endif
	return;
}

/*
 *      Debugger Character Input Function
 *      ---------------------------------
 *      Allows Ctrl W to Swap Window even in an ASK !!!!
 *
 */
void    toggle_visible_screen()
{
	if ( ExWindow == 0 ) { ExWindow = 1; DbWindow = 0; }
	else                 { ExWindow = 0; DbWindow = 1; }


#ifdef UNIX
	if ( exa_is_X11 == 2 ) {
		if ( ExWindow )
			use_pixel_primary(1);
		else	use_pixel_alternative(1);
		}
	else	SwapView();
#else
	SwapView();
#endif
	return;
}

void    db_ungetch( c )
EXAWORD    c;
{
	exadb_ungotc = c;
	return;
}

EXAWORD    db_ungotch()
{
	EXAWORD    c;
	c = exadb_ungotc;
	exadb_ungotc = 0;
	return(c);
}

EXAWORD    db_xgetch()
{
	EXAWORD    c;
	while ( 1 ) {

		if ((c = db_ungotch()) != 0)
			exadb_ungotc = 0;

#ifdef	NOGIGO
#ifdef	x_getch
#undef	x_getch
#endif
#endif

		else    c = x_getch();

		if ( c != DB_WDWSWAP )
			return( c );
		else    toggle_visible_screen();

		}
}

void    activate_askbuf_output()
{
	prndest = 0;
	prnptr  = (BPTR) askbuf;
	prnleng = 256;
	prndex  = 0;
	prnfid = 0;
	return;
}

void    cancel_askbuf_output()
{
	prndest = 1;
	if ( prndex < prnleng )
		*(prnptr + prndex) = 0;
	prnptr  = (BPTR) 0;
	prnleng = 0;
	prndex  = 0;
	prnfid = 0;
	return;
}

EXAWORD    db_opb()
{
	return( opb() );
}


