#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <setjmp.h>
#include "bda.h"
#include "allocate.h"
#include "stdpsu.h"

BDA	desrt;

void _cfltcvt() { return; }
void _cropzeros() { return; }


#include "bdacico.h"
#include "aasfun.h"
#include "asfun.h"
#include "window.h"
#include "menu.h"
#include "list.h"
#include "dbox.h"
#include "fundef.h"

static	int	bedug=0;
public	char	asfun_stylename[512];

WORD	MAXLIG,MAXCOL;
WORD	SBARCOL;	/* Status bar columns	*/
WORD	SBARLIG;	/* Status bar line	*/
WORD	COULEUR;	/* type ecran 		*/
BYTE	fen_ini=0;

#include "abalword.c"
#include "ldfparam.c"

public	EXAWORD	md_choice(struct asfun_option * optr, int nesting);
public	EXAWORD	md_inv(int mid);
private	VOID	v_putch(int c);

#include "acico.c"	/* character IO handling 	*/

void get_cons()
{
	MAXLIG = conf(1);
	MAXCOL = conf(2);
	if (!( SBARCOL= conf(13) ))
		SBARLIG=0;
	else	SBARLIG=1;
	COULEUR = conf(14);
	return;
}

private VOID FAR banniere()
{
	return;
}

#include "window.c"	/* window handling functions 	*/
#include "menu.c"	/* menu handling functions 	*/
#include "list.c"	/* list handling functions 	*/
#include "dbox.c"	/* dbox handling functions 	*/
#include "aservice.c"	/* stub service functions 	*/


private	int	load_palette( char * n )
{
	FILE * 	h;
	char 	buffer[256*4];
	if (( h = fopen( n, "b" )) != (FILE *) 0) {
		fread(buffer,256,4,h);
		fclose(h);
		vgapalette(buffer,0,255);
		return(0);
		}
	return( 40);	
}

/*	-------------------------------------------------	*/
/*		F O N C T I O N S  _  F E N E T R E S	 	*/
/*	-------------------------------------------------	*/
/*	DLL Interface and Operational Interface Functions 	*/
/*	-------------------------------------------------	*/
#include "winit.c"
#include "wcreat.c"
#include "wsup.c"
#include "wwrite.c"
#include "wselect.c"
#include "winv.c"
#include "wvis.c"
#include "wfgen.c"
#include "watb.c"
#include "wposcur.c"
#include "wimpl.c"
#include "wgel.c"
#include "wfend.c"
#include "wsetatb.c"
#include "swcreat.c"
#include "mduse.c"

/*	-------------------------------------------------	*/
/*		S E R V I C E S  _  F E N E T R E S	 	*/
/*	-------------------------------------------------	*/
/*	DLL Interface and Operational Interface Functions 	*/
/*	-------------------------------------------------	*/

/* 14: %sf_init($) */
private EXAWORD Dll_sf_init( VOID FAR PTR FAR pptr[] )
{
	/* use asfun version */
	/*------------------ */
	if ( fen_ini ) 	{
		return( 3 ); 
		}
	else	{
		Control.statusbar=1;
		return( winit(0,0,0,0,0) );	
		}

}
	

/* 15:%sl_activ() */
private EXAWORD Dll_sl_activ( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else if ( Control.statusbar ==1 )
		return(0);
	else	{
		Control.statusbar=1;
		show_windows();
		return(0);	
		}
}

public	int	sl_message( int type, int ml, char * mptr )
{
	int	i;
	memset(Control.statusmessage,' ',_MAX_STATUS_MSG);
	Control.statustype = type;
	for (i=0; i < ml; i++ )
		if ( i < _MAX_STATUS_MSG )
			Control.statusmessage[i] = *(mptr+i);
	show_statusbar();
	return(0);
}
	
/* 16:%sl_mess(#,#,$) */
private EXAWORD Dll_sl_mess( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{ 
		return( 
			sl_message(
				LdfParaByte(0),
				LdfParaByte(1),
				LdfParaPtr(2) 
				) 
			); 
		}
}

/* 17:%sl_inv() */
private EXAWORD Dll_sl_inv( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else if (!( Control.statusbar )) 
		return(0);
	else	{
		Control.statusbar=0;
		show_windows();
		return(0);	
		}
}

/* 18:%sl_desac() */
private EXAWORD Dll_sl_desac( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else if (!( Control.statusbar )) 
		return(0);
	else	{
		Control.statusbar=0;
		show_windows();
		return(0);	
		}
}

public	EXAWORD	md_sup(int mid)
{
	struct	asfun_menu *	mptr;
	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	if (!(mptr = Control.menus[(mid-1)]))
		return(0);
	else	{
		Control.menus[(mid-1)] = remove_menu( mptr );
		return(0);
		}
}

public	EXAWORD	md_creat(int mid, char * dptr, int control, char * hptr, int hlen )
{
	int	i;
	int	wid;
	struct	asfun_menu *	mptr;
	struct	asfun_window *	wptr;
	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	if ((wid = next_free_window()) >= _MAX_WINDOWS)
		return(4);
	else if ((mptr = Control.menus[(mid-1)]) != (struct asfun_menu *) 0)
		md_sup(mid);	
	if (!( mptr = create_menu()))
		return(27);
	else if (!( wptr = create_window())) {
		remove_menu(mptr);
		return(27);
		}
	else	{
		wptr->style = *dptr;		dptr++;
		wptr->y = GetInt16( dptr ); 	dptr += WORDSIZE;
		wptr->x = GetInt16( dptr ); 	dptr += WORDSIZE;
	
		if ( bedug )  {
			printf("menu_creat(%u, %u, %u,%u,",mid,wptr->style,wptr->x,wptr->y);
			}

		if (wptr->style)	{ 	wptr->border=4;		}
		wptr->fg 	= 0;	wptr->bg 	= 7;
		wptr->menu	= mid;

		memcpy(wptr->titre,dptr,32);	dptr += 32;
		for ( i=0; i < 32; i++ )
			if ( wptr->titre[i] != ' ' )
				wptr->lentit = (i+1);

		mptr->number	=	mid;
		mptr->type	=	*(dptr++);		/* H or V */
		mptr->escape	=	*(dptr++);		/* escape type 1 .... 5 */


		if ((mptr->options = *(dptr++)) > _MAX_OPTIONS) {
			remove_menu( mptr );
			remove_window( wptr );
			return(1);
			}
		mptr->lenopt	=	*(dptr++);
		mptr->width	=	*(dptr++);
		mptr->lencom	=	*(dptr++);

		if ( bedug )  {
			printf("%u,%u,%u,%u,%u)\r\n",mptr->type,mptr->escape,mptr->lenopt,mptr->width,mptr->lencom);
			}

		for (i=0; i < mptr->options; i++ ) {
			if (!( mptr->option[i] = create_option(wptr->style) )) {
				remove_menu( mptr );
				remove_window( wptr );
				return(27);
				}
			}

		switch ( mptr->type ) {
			case	1	:	/* horizontal */
				wptr->h = 1;
				wptr->w = (((mptr->width+1)*mptr->options)+2);
				break;
			case	2	:	/* vertical   */
				wptr->h = mptr->options;
				wptr->w = mptr->width;
				break;
			default		:
				remove_menu(mptr);
				remove_window(wptr);
				return(1);
			}

		wptr->fg = wptr->bg = 0;

		if (!( allocate_window(wptr) )) {
			remove_window( wptr );
			remove_menu(mptr);
			return(27);			
			}
		else	{
			mptr->window = (wid+1);
			Control.windows[wid] = wptr;
			Control.menus[(mid-1)] = mptr;
			return(0);
			}
		}
}

public	EXAWORD	md_vis(int mid, int optid, int afftype )
{
	int	i;
	struct	asfun_menu *	mptr;
	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	if (!(mptr = Control.menus[(mid-1)]))
		return(40);
	else 	{
		show_menu( mptr );
		return(0);
		}
}

public	EXAWORD	md_choice(struct asfun_option * optr, int nesting)
{
	int	i;
	if (!( optr ))
		return(0);
	switch ( optr->style & 7 ) {
		case	_HIDE_NOTHING	:
			return(0);
		case	_HIDE_CURRENT	:
			md_inv(Control.nested[nesting]);
			return(0);

		case	_HIDE_ALL	:
			Control.freeze=1;
			for ( i=0; i <= nesting; i++ )
				md_inv( Control.nested[i] );
			Control.freeze=0;
			show_windows();
			return(0);

		case	_HIDE_EXCEPT	:
			Control.freeze=1;
			for ( i=1; i <= nesting; i++ )
				md_inv( Control.nested[i] );
			Control.freeze=0;
			show_windows();
			return(0);

		default	  :	return(0);
		}
}	


public	EXAWORD	md_inv(int mid)
{
	int	i;
	struct	asfun_menu *	mptr;
	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	if (!(mptr = Control.menus[(mid-1)]))
		return(40);
	else 	{
		hide_menu( mptr );
		return(0);
		}
	return(0);
}

public	EXAWORD	mo_creat(int mid, int oid, char * dptr, char * vptr, char * cptr )
{
	int	t=0;
	int	n=0;
	int	i=0;
	struct	asfun_menu *	mptr;
	struct	asfun_option *	optr;
	struct	asfun_window *	wptr;

	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	else if (!(mptr = Control.menus[(mid-1)]))
		return(40);
	else if ((oid == 0) || ( oid > mptr->options))
		return(1);
	else if (!(optr = mptr->option[(oid-1)]))
		return(40);
	else	{
		optr->trigger = *(dptr++);
		optr->style  = (*(dptr++) & 7);		
		switch ( *(dptr++ ) ) {
			case	1	:	break;
			case	2	:
				optr->style |= _OPTION_SHADED;
				break;
			default		:
				return(1);
			}
		switch ((i = *(dptr++))) {
			case	1 : optr->style |= _OPTION_CHOOSE; break;
			case	2 : optr->style |= _OPTION_SET; break;
			case	3 : break;
			default	  :
				return(1);
			}
		switch ((i = *(dptr++))) {
			case	1 : break;
			case	2 : optr->style |= _OPTION_ACTIVE; break;
			default	  :
				return(1);
			}
		optr->menu   = *(dptr++);
		optr->option = *(dptr++);
		optr->slen = mptr->width;
		optr->vlen = mptr->lenopt;
		for (t=0,i=0,n=0; n < optr->vlen; n++ ) { 
			if ( *(vptr+n) == optr->trigger ) {
				if (!( t )) {
					t = 1;
					optr->value[i++] = '&';
					}
				}
			optr->value[i++] = *(vptr+n); 
			}
		optr->vlen += t;
		optr->clen = mptr->lencom;
		for (i=0; i < optr->clen; i++ ) { optr->comment[i] = *(cptr+i); }
		if (!( wptr = Control.windows[(mptr->window-1)] ))
			return(1);
		switch ( mptr->type ) {
			case	_HMENU	:
				optr->x = wptr->x + ((oid-1)*(mptr->width+1));
				optr->w = mptr->width;
				optr->y = wptr->y;
				optr->h = 1;
				break;
			case	_VMENU	:
				optr->x = wptr->x;
				optr->w = mptr->width;
				optr->y = (wptr->y + oid - 1);
				optr->h = 1;
				break;
			}
		optr->grx = (optr->x-1)*Control.gfw;
		optr->gry = (optr->y-1)*Control.gfh;
		optr->grw = (optr->w*Control.gfw);
		optr->grh = (optr->h*Control.gfh);
		optr->option &= ~_OPTION_BLANK;
		optr->option &= ~_OPTION_SEPARATE;
		return(0);
		}
}

public	EXAWORD	mo_latt(int mid, int oid, char * optaff, char * optsel, char * optetat, char * vptr)
{
	int	i=0;
	struct	asfun_menu *	mptr;
	struct	asfun_option *	optr;

	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	else if (!(mptr = Control.menus[(mid-1)]))
		return(40);
	else if ((oid == 0) || ( oid > mptr->options))
		return(1);
	else if (!(optr = mptr->option[(oid-1)]))
		return(40);
	else	{
		if ( optr->style & _OPTION_SHADED )
			*optaff=2;
		else	*optaff=0;

		if ( optr->style & _OPTION_CHOOSE )
			*optsel = 1;
		else if ( optr->style & _OPTION_SET)
			*optsel =2;
		else	*optsel =3;

		if ( optr->style & _OPTION_ACTIVE )
			*optetat = 2;
		else	*optetat = 1;

		if ( vptr ) {
			for (i=0; i < mptr->lenopt; i++) {
				if ( optr->value[i] == '&' )
					continue;
				else	*(vptr++) = optr->value[i];
				}
			}
		return(0);

		}
}

public	EXAWORD	mo_matt(int mid, int oid, int optaff, int optsel, int optetat )
{
	struct	asfun_menu *	mptr;
	struct	asfun_option *	optr;
	struct	asfun_window *	wptr;

	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	else if (!(mptr = Control.menus[(mid-1)]))
		return(40);
	else if ((oid == 0) || ( oid > mptr->options))
		return(1);
	else if (!(optr = mptr->option[(oid-1)]))
		return(40);
	else	{
		switch ( optaff ) {
			case	0 	:
				break;
			case	1	:
				optr->style &= ~_OPTION_SHADED;
				break;
			case	2	:
				optr->style |= _OPTION_SHADED;
				break;
			default		:
				return(1);
			}
		switch ( optsel ) {
			case	0 :
				break;
			case	1 : 
				optr->style |= _OPTION_CHOOSE;
				optr->style &= ~_OPTION_SET; 
				break;
			case	2 : 
				optr->style &= ~_OPTION_CHOOSE;
				optr->style |= _OPTION_SET; 
				break;
			case	3 : 
				optr->style &= ~_OPTION_SET; 
				optr->style &= ~_OPTION_CHOOSE;
				break;
			default	  :
				return(1);
			}
		switch ( optetat ) {
			case	0 :
				break;
			case	1 :
				optr->style &= ~_OPTION_ACTIVE; 
				break;
			case	2 : 
				optr->style |= _OPTION_ACTIVE; 
				break;
			default	  :
				return(1);
			}
		if (!( mptr->window ))
			return(0);
		else if (!( wptr = Control.windows[(mptr->window-1)] ))
			return(0);
		else if (!( wptr->visible ))
			return(0);
		else	{
			show_option( optr );
			return(0);
			}
		}
}

public	EXAWORD	mo_blank(int mid, int oid)
{
	struct	asfun_menu *	mptr;
	struct	asfun_option *	optr;

	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	else if (!(mptr = Control.menus[(mid-1)]))
		return(40);
	else if ((oid == 0) || ( oid > mptr->options))
		return(1);
	else if (!(optr = mptr->option[(oid-1)]))
		return(40);
	else	{
		optr->option |= _OPTION_BLANK;
		optr->option &= ~_OPTION_SEPARATE;
		return(0);
		}
}

public	EXAWORD	mo_sep(int mid, int oid )
{
	struct	asfun_menu *	mptr;
	struct	asfun_option *	optr;

	if ((mid == 0) || (mid > _MAX_MENUS))
		return(1);
	else if (!(mptr = Control.menus[(mid-1)]))
		return(40);
	else if ((oid == 0) || ( oid > mptr->options))
		return(1);
	else if (!(optr = mptr->option[(oid-1)]))
		return(40);
	else	{
		optr->option &= ~_OPTION_BLANK;
		optr->option |= _OPTION_SEPARATE;
		return(0);
		}
}

/* 19:%menu_creat(#,$,.) */
private EXAWORD Dll_menu_creat( VOID FAR PTR FAR pptr[] )
{
	int	mid;
	char *	dptr;
	int	control=0;
	char *	hptr=(char *) 0;
	int	hlen=0;
	mid = LdfParaByte(0);
	dptr = LdfParaPtr(1);
	if ( LdfValidPara(2) ) {
		control = LdfParaWord(2);
		if ( LdfValidPara(3) ) {
			hptr = LdfParaPtr(3);
			hlen = LdfParaLen(3);
			}
		}
	return (md_creat(mid,dptr,control,hptr, hlen));
}

/* 20:%menu_option(#,#,$,$,$) */
private EXAWORD Dll_menu_option( VOID FAR PTR FAR pptr[] )
{
	return (mo_creat(LdfParaByte(0), LdfParaByte(1),pptr[2] ,pptr[3],pptr[4] ) );
}

/* 21:%menu_sep(#,#) */
private EXAWORD Dll_menu_sep( VOID FAR PTR FAR pptr[] )
{
	return (mo_sep(	LdfParaByte(0),
			LdfParaByte(1)) );
}

/* 22:%menu_modif_opt(#,#,#,$,$,$) */
private EXAWORD Dll_menu_modif_opt( VOID FAR PTR FAR pptr[] )
{
	switch ( LdfParaByte(2) ) {
		case	0 :
			return (mo_blank( LdfParaByte(0), LdfParaByte(1) ) );
		case	1 :
			return (mo_sep( LdfParaByte(0), LdfParaByte(1) ) );
		case	2 : 
			return (mo_creat( 
				LdfParaByte(0), LdfParaByte(1),
				pptr[3] ,pptr[4] ,pptr[5] ) );
		return(1);
		}
}

/* 23:%menu_latt_opt(#,#,#?,#?,#?,.) */
private EXAWORD Dll_menu_latt_opt( VOID FAR PTR FAR pptr[] )
{
	return (mo_latt(LdfParaByte(0),
			LdfParaByte(1),
			pptr[2] ,
			pptr[3] ,
			pptr[4] , (LdfValidPara(5) ? pptr[5] : (char *) 0) ) );
}

/* 24:%menu_matt_opt(#,#,#,#,#) */
private EXAWORD Dll_menu_matt_opt( VOID FAR PTR FAR pptr[] )
{
	return (mo_matt(
			LdfParaByte(0),
			LdfParaByte(1),
			LdfParaByte(2),
			LdfParaByte(3),
			LdfParaByte(4)) );

}

/* 25:%menu_blank_opt(#,#) */
private EXAWORD Dll_menu_blank_opt( VOID FAR PTR FAR pptr[] )
{
 	return (mo_blank( LdfParaByte(0), LdfParaByte(1)) );
}

/* 26:%menu_vis(#,#,#) */
private EXAWORD Dll_menu_vis( VOID FAR PTR FAR pptr[] )
{
	return (md_vis(
			LdfParaByte(0),
			LdfParaByte(1),
			LdfParaByte(2)) );
}

/* 27:%menu(#,#,#?,#?,$?,.?) */
private EXAWORD Dll_menu( VOID FAR PTR FAR pptr[] )
{
	return (enter_md_use(
			LdfParaByte(0),
			LdfParaByte(1),
			LdfParaPtr(2) ,
			LdfParaPtr(3) ,
			LdfParaPtr(4) ,
			LdfParaPtr(5), 0 ) );
}

/* 28:%menu_inv(#) */
private EXAWORD Dll_menu_inv( VOID FAR PTR FAR pptr[] )
{
	return (md_inv(LdfParaByte(0)));
}

/* 29:%menu_sup(#) */
private EXAWORD Dll_menu_sup( VOID FAR PTR FAR pptr[] )
{
	return (md_sup(LdfParaByte(0)));
}

/* 30:%list_creat(#,$,.) */
private EXAWORD Dll_list_creat( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_creat( 
				LdfParaByte(0), 
				LdfParaPtr(1),
				LdfParaWord(2),
				LdfParaPtr(3), 0 ) );
		}
}

/* 31:%listmul_creat(#,$,.) */
private EXAWORD Dll_listmul_creat( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_creat( 
				LdfParaByte(0), 
				LdfParaPtr(1),
				LdfParaWord(2),
				LdfParaPtr(3), 1 ) );
		}
}

/* 32:%list_element(#,%?,#,#,$,$) */
private EXAWORD Dll_list_element( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_element( 
			LdfParaByte(0),
			LdfParaPtr(1),
			LdfParaByte(2),
			LdfParaByte(3),
			LdfParaPtr(4),
			LdfParaPtr(5) ) );
		
		}
}

/* 33:%list_read_elt(#,%,#?,#?,$?) */
private EXAWORD Dll_list_read_elt( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_read_element( 
			LdfParaByte(0),
			LdfParaWord(1),
			LdfParaPtr(2),
			LdfParaPtr(3),
			LdfParaPtr(4) ) );
		}
}

/* 34:%list_down(#,%?,#?,#?,$?) */
private EXAWORD Dll_list_down( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_down_element( 
			LdfParaByte(0),
			LdfParaPtr(1),
			LdfParaPtr(2),
			LdfParaPtr(3),
			LdfParaPtr(4) ) );
		}
}

/* 35:%list_up(#,%?,#?,#?,$?) */
private EXAWORD Dll_list_up( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_down_element( 
			LdfParaByte(0),
			LdfParaPtr(1),
			LdfParaPtr(2),
			LdfParaPtr(3),
			LdfParaPtr(4) ) );
		}
}

/* 36:%list_matt_elt(#,%,#,#,.) */
private EXAWORD Dll_list_matt_elt( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_mat_element( 
			LdfParaByte(0),
			LdfParaWord(1),
			LdfParaByte(2),
			LdfParaByte(3),
			LdfParaPtr(4),
			LdfParaPtr(5) ) );
		}
}

/* 37:%list_close(#) */
private EXAWORD Dll_list_close( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_close(  LdfParaByte(0) ) );
		}
}

/* 38:%list_vis(#,%,%,.) */
private EXAWORD Dll_list_vis( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_vis(  
				LdfParaByte(0),
				LdfParaWord(1),
				LdfParaWord(2),
				LdfParaWord(3) ) );
		}
}

/* 39:%list(#,%?,%?,#?,$?,.?) */
private EXAWORD Dll_list( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return(use_list(
			LdfParaByte(0),
			LdfParaPtr(1),	/* first visible */
			LdfParaPtr(2),	/* current	 */
			LdfParaPtr(3),	/* choice type	 */
			LdfParaPtr(4),	/* value	 */
			LdfParaPtr(5)	/* keycode	 */ ));
		}
}

/* 40:%list_inv(#) */
private EXAWORD Dll_list_inv( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_inv(  LdfParaByte(0) ) );
		}
}

/* 41:%list_sup(#) */
private EXAWORD Dll_list_sup( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_sup(  LdfParaByte(0) ) );
		}
}

/* 42:%bvalid_spc($,$,#?) */
private EXAWORD Dll_bvalid_spc( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else			{	return(0);	}
}

/* 43:%bvalid(#,#?) */
private EXAWORD Dll_bvalid( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else			{	return(0);	}
}

/* 44:%sf_end() */
private EXAWORD Dll_sf_end( VOID FAR PTR FAR pptr[] )
{
	if (!(fen_ini))	{	return(3); 		}
	else			{	return( wend() );	}
}

#include "wfmod.c"

/* 46:%help_activ(#,$) */
private EXAWORD Dll_help_activ( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else			{	return(0);	}
}

/* 47:%help($) */
private EXAWORD Dll_help( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else			{	return(0);	}
}

/* 48:%help_desac() */
private EXAWORD Dll_help_desac( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else			{	return(0);	}
}

/* 49:%help_def($) */
private EXAWORD Dll_help_def( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else			{	return(0);	}
}

/* 50:%wget_impl(%?) */
private EXAWORD Dll_wget_impl( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		PutInt16( pptr[0], Control.implicite);
		return(0);
		}
}

/* 51:%bd_creat(%?,%,%,%,%,%,.) */
private EXAWORD Dll_bd_creat( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return (bd_creat(
			pptr[0],
			LdfParaWord(1),
			LdfParaWord(2),
			LdfParaWord(3),
			LdfParaWord(4),
			LdfParaWord(5),
			LdfParaPtr(6),LdfParaLen(6),
			LdfParaWord(7) ) );
		}
}

/* 52:%bd_insert(%,%,%,%,.) */
private EXAWORD Dll_bd_insert( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		switch( LdfParaWord(3) & 0x00FF ) {
			case DBOX_MESSAGE	:
				return (bd_message(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2),
						pptr[4] ,LdfParaLen(4) ));
			case DBOX_BOUTON	:
				return (bd_button(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2),
						LdfParaPtr(4), LdfParaLen(4),
						LdfParaWord(5) ));
			case DBOX_R_BOUTON	:
				return (bd_radio(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2), 
						LdfParaWord(4),
						LdfParaWord(5),
						LdfParaPtr(6), LdfParaLen(6) ) );
			case DBOX_C_BOUTON	:
				return (bd_check(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2),
						LdfParaWord(4),
						LdfParaWord(5),
						LdfParaWord(6),
						LdfParaPtr(7), LdfParaLen(7) ) );
			case DBOX_SAISIE	:
				return (bd_edit(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2),
						LdfParaWord(4),
						LdfParaWord(5) ));
			case DBOX_LISTE		:
				return (bd_list(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2),
						LdfParaWord(4) ));
						
			case DBOX_AIDE		:
				return (bd_help(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2),
						pptr[4], LdfParaLen(4)) );
			case DBOX_FUNFREE     	:
				return (bd_funky(
						LdfParaWord(0),
						LdfParaWord(1),
						LdfParaWord(2),
						LdfParaWord(4) ));
			default			:
				/* BD ERROR TYPE */
				return(11);

			}
		}
}

/* 53:%bd_use(%,%,%?,.?) */
private EXAWORD Dll_bd_use( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return (bd_use(	LdfParaWord(0),LdfParaWord(1),pptr[2] ));
		}
}

/* 54:%bd_inv(%) */
private EXAWORD Dll_bd_inv( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return (bd_inv(	LdfParaWord(0) ) );
		}
}

/* 55:%bd_sup(%) */
private EXAWORD Dll_bd_sup( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return (bd_sup(	LdfParaWord(0) ) );
		}
}

/* 56:%bd_putdata(%,$) */
private EXAWORD Dll_bd_putdata( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return (bd_putdata(	LdfParaWord(0), LdfParaPtr(1) ) );
		}
}

/* 57:%bd_getdata(%,$?) */
private EXAWORD Dll_bd_getdata( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return (bd_getdata(	LdfParaWord(0), LdfParaPtr(1) ) );
		}
}

/* 58:%wexit(%) */
private EXAWORD Dll_wexit( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{	
		switch ((LdfParaWord(0))) {
			case	1	:
				v_putch(0x001C);
			}
		clear_implicite_window();
		enable_scroll();
		enable_cursor();
		return(0);	
		}
}

/* 59:%wrefresh() */
private EXAWORD Dll_wrefresh( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		inhibit_scroll();
		inhibit_cursor();
		show_windows();
		return(0);	
		}
}

/* 60:%menu_way(#?,$?) */
private EXAWORD Dll_menu_way( VOID FAR PTR FAR pptr[] )
{
	int	i;
	char *	wptr;
	char *	rptr;
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		wptr = LdfParaPtr(0);
		rptr = LdfParaPtr(1);
		for (i=0; i < 5; i++ ) {
			if (!( Control.nested[i] ))
				break;
			*(rptr++) = Control.nested[i];
			*(rptr++) = Control.choice[i];
			}
		*wptr = i;
		return(0);	
		}
}

/* 62:%wcadre(%,#,.) */
private EXAWORD Dll_wcadre( VOID FAR PTR FAR pptr[] )
{
	struct	asfun_window * wptr;
	int	h;
	int	i;
	int	type;
	int	tlen;
	char * 	tptr;
	if (!( fen_ini	))	{	return(3); 	}
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		wptr->control &= ~(CAD3|CAD2|CAD3);
		switch ((wptr->border = LdfParaWord(1)))  {
			case	1	:	wptr->control |= CAD1; 	break;
			case	2	:	wptr->control |= CAD2;	break;
			case	3	:	wptr->control |= CAD3;	break;
			case	0	:
				if ( wptr->style )
					wptr->border=1;
			}
		wptr->fratb = LdfParaWord(2);
		wptr->frfg = LdfParaWord(3);
		wptr->frbg = LdfParaWord(4);
		if ( bedug ) {
			printf("wcadre(%u,%u,%u,%u,%u)\r\n",h,wptr->border,wptr->fratb,wptr->frfg,wptr->frbg);
			}
		if ( LdfValidPara(5) ) {
			tptr = LdfParaPtr(5);
			tlen = LdfParaLen(5);
			memset(wptr->titre,' ',_MAX_CADRE);
			if ( tlen > _MAX_CADRE )
				tlen = _MAX_CADRE;
			for (i=0; i< tlen ; ++i) { wptr->frame[i] = *(tptr+i); }
			}
		show_window( wptr );
		return(0);
		}
}

/* 63:%wtitre(%,#,#,#,.) */
private EXAWORD Dll_wtitre( VOID FAR PTR FAR pptr[] )
{
	struct	asfun_window * wptr;
	int	h;
	int	i;
	int	tlen;
	char * 	tptr;
	if (!( fen_ini	))	{	return(3); 	}
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		wptr->atbtit = LdfParaWord(1);
		wptr->fgtit = LdfParaWord(2);
		wptr->bgtit = LdfParaWord(3);
		if ( LdfValidPara(4) ) {
			tptr = LdfParaPtr(4);
			tlen = LdfParaLen(4);
			memset(wptr->titre,' ',_MAX_TITLE);
			if ( tlen > _MAX_TITLE )
				tlen = _MAX_TITLE;
			for (i=0; i < tlen; i++ )
				wptr->titre[i] = *(tptr+i);
			show_window(wptr);
			}
		if ( bedug ) {
			printf("wtitle(%u,%u,%u,%u)\r\n",h,wptr->atbtit,wptr->fgtit,wptr->bgtit);
			}
		return(0);
		}
}

/* 64:%wmove(%,%,%) */
private EXAWORD Dll_wmove( VOID FAR PTR FAR pptr[] )
{
	struct	asfun_window * wptr;
	int	newcol;
	int	newlig;
	int	h;
	if (!( fen_ini	))	{	return(3); 	}
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		newlig = LdfParaWord(1);
		newcol = LdfParaWord(2);
		if ( bedug ) {
			printf("wmove(%u,%u,%u)\r\n",h,newlig,newcol);
			}
		if (((( newcol+wptr->w-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbc )
		||  ((( newlig+wptr->h-1 ) + ( wptr->border ? 2 : 0 )) > Control.nbl )) {
			return(1);
			}
		move_window( wptr, newcol, newlig );
		return(0);
		}
}

/* 65:%listel_del(#,%) */
private EXAWORD Dll_listel_del( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_del_element( LdfParaByte(0), LdfParaWord(1) ) );
		}
}

/* 66:%listel_ins(#,%?,#,#,$,$) */
private EXAWORD Dll_listel_ins( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return( list_ins_element( 
			LdfParaByte(0),
			LdfParaWord(1),
			LdfParaByte(2),
			LdfParaByte(3),
			LdfParaPtr(4),
			LdfParaPtr(5) ) );
		}
}

/* 67:%set_tch_esc(#,$) */
private EXAWORD Dll_set_tch_esc( VOID FAR PTR FAR pptr[] )
{
	int		i;
	char	*	bptr;
	int		blen;
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		blen = LdfParaWord(0);
		bptr = LdfParaPtr(1);
		if ( blen > 32 )
			return(1);
		else	{
			memset(Control.Escape,0,33);
			for (i=0; i < blen; i++ )
				Control.Escape[i] = *(bptr+i);
			return(0);	
			}
		}
}

/* 68:%winfo(%,$?) */
private EXAWORD Dll_winfo( VOID FAR PTR FAR pptr[] )
{
	int	i;
	int	h;
	char *	wb;
	struct	asfun_window * wptr;
	if (!( fen_ini	))	{	return(3); 	}
	h = LdfParaWord(0);
	if ((h <= 0) || ( h >= _MAX_WINDOWS))
		return(2);
	else if (!( wptr = Control.windows[(h-1)] ))
		return(2);
	else	{
		if ( bedug ) {
			printf("winfo(%u,l=%u,c=%u)\r\n",h,wptr->y,wptr->x);
			}
		wb = LdfParaPtr(1);

		PutInt16( wb , 0 );
		PutInt16( & wb[Bpos_lig],wptr->y );	
		PutInt16( & wb[Bpos_col],wptr->x );
		PutInt16( & wb[Bnb_lig], wptr->h );	
		PutInt16( & wb[Bnb_col], wptr->w  );

		wb[Batb_vid] = wptr->atb;
		wb[Batbcol_text] = wptr->fg;
		wb[Batbcol_fond] = wptr->bg;

		PutInt16( & wb[Bcontrol], wptr->control); 
		PutInt16( & wb[Bln_tit],  wptr->lentit);
	
		for (i=0; i< 32; ++i) { wb[Btitre+i] = wptr->titre[i]; }

		for (i=0; i< 8; ++i)  { wb[Bcad_usr+i] = wptr->frame[i]; }

		wb[Bcad_atb] = wptr->fratb;
		wb[Bcad_text]= wptr->frfg;
		wb[Bcad_fond]=wptr->frbg;
		return(0);
		}
}

/* 69:%get_style(#,$?) */
private EXAWORD Dll_get_style( VOID FAR PTR FAR pptr[] )
{
	return (0); /* get_style(LdfParaWord(0),pptr[1]));*/
}

/* 70:%set_style(#,$) */
private EXAWORD Dll_set_style( VOID FAR PTR FAR pptr[] )
{
	return (0); /* set_style(LdfParaWord(0),pptr[1])); */
}

/* 71:%wlangue(#) */
private EXAWORD Dll_wlangue( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		switch ((Control.language = LdfParaWord(0))) {
			case	0	:	/* Francais 	*/
			case	1	:	/* English 	*/
			case	2	:	/* Deutsch	*/
			case	3	:	/* Espagnol	*/
			case	4	:	/* Italiano	*/
			case	5	:	/* Neerlands	*/
			case	6	:	/* Potugeus	*/
			case	7	:	/* Autre	*/
			case	16	:	/* Encod‚	*/	
				return(0);	/*	OK	*/
			default		:
				return(1);	/* Incorrect	*/
			}
		}
}

/* 72:%asfvers($?) */
private EXAWORD Dll_asfvers( VOID FAR PTR FAR pptr[] )
{
	char	*	rptr;
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		rptr = pptr[0];
		*(rptr++) = '3';
		*(rptr++) = '2';
		*(rptr++) = 'a';
		*(rptr++) = ' ';
		return(0);	
		}
}

/* 88:%who_is_there(%,%,%?,%?) */
private EXAWORD Dll_who_is_there( VOID FAR PTR FAR pptr[] )
{
	int	atcol;
	int	atlin;
	int	h;
	char *	cp;
	char *	lp;
	struct	asfun_window * wptr;
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		atlin = LdfParaWord(0);
		atcol = LdfParaWord(1);
		for (h=0; h < _MAX_WINDOWS; h++) {
			if (!( wptr = Control.windows[h] ))
				continue;	
			else if (!( wptr->visible ))
				continue;
			else if (( atlin >= wptr->y )
			     &&  ( atlin < (wptr->y+wptr->h))
			     &&  ( atcol >= wptr->x )
			     &&  ( atcol < (wptr->x+wptr->w))) {
				lp = LdfParaPtr(2);
				PutInt16(lp,((atlin-wptr->y)+1));
				cp = LdfParaPtr(3);
				PutInt16(cp,((atcol-wptr->x)+1));
				return((h+1));
				}
			else if (!( wptr->border ))
				continue;
			else if (( atlin == (wptr->y-1))
			     &&  ( atcol >= (wptr->x-1))
			     &&  ( atcol < (wptr->x+wptr->w+1))) {
				lp = LdfParaPtr(2);
				PutInt16(lp,0);
				cp = LdfParaPtr(3);
				if ( atcol == (wptr->x-1) )
					PutInt16(cp,0);
				else	PutInt16(cp,((atcol-wptr->x)+1));
				return((h+1));
				}
			}
		lp = LdfParaPtr(2);
		PutInt16(lp,atlin);
		cp = LdfParaPtr(3);
		PutInt16(cp,atcol);
		return(0);
		}
}

#include "rle.c"

/* 89:%rlecomp($,$,%) */
private EXAWORD Dll_rlecomp( VOID FAR PTR FAR pptr[] )
{
	return( rlecomp( pptr[0], pptr[1], LdfParaWord(2) ) );
}

/* 90:%rledecomp($,$,%) */
private EXAWORD Dll_rledecomp( VOID FAR PTR FAR pptr[] )
{
	return( rledcomp( pptr[0], pptr[1], LdfParaWord(2) ) );
}


private	VOID	v_putch(int c)
{
	struct	asfun_window * wptr;
	int	w;
	int	hider=0;
	switch ( c ) {
		case	0x000C	:
			if ((w = Control.implicite ) != 0) {
				wfgen(w,1);
				break;
				}
		default		:
			x_putch((c&0x00FF));
		}
#ifdef	OHHHHHHHHHHHHHHH
	printf("v_putch(%x)\r\n",c);
	if (!(w = Control.implicite ))
		return;
	else if (!(wptr = Control.windows[(w-1)]))
		return;
	else if (!( wptr->visible ))
		return;
	else if ( wptr->frozen )
		return;
	else	{
		clear_implicite_window();
		hide();
		show_window(wptr);
		while ( show(wptr->grx,wptr->gry,wptr->grw,wptr->grh) )
			hider++;
		while ( hider-- )
			hide();
		use_implicite_window();
		}
#endif
	return;
}


VOID FAR PTR InitRelais()
{
	if (rt_init != (VOID FAR PTR) 0L)
	rt_init->ordinaire.signature = BDA_REDIRECT;
	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;
	desrt.fonction[0] = (EXAWORD (FAR PTR)()) Dll_winit;
	desrt.fonction[1] = (EXAWORD (FAR PTR)()) Dll_wcreat;
	desrt.fonction[2] = (EXAWORD (FAR PTR)()) Dll_wsup;
	desrt.fonction[3] = (EXAWORD (FAR PTR)()) Dll_wwrite;
	desrt.fonction[4] = (EXAWORD (FAR PTR)()) Dll_wselect;
	desrt.fonction[5] = (EXAWORD (FAR PTR)()) Dll_winv;
	desrt.fonction[6] = (EXAWORD (FAR PTR)()) Dll_wvis;
	desrt.fonction[7] = (EXAWORD (FAR PTR)()) Dll_wfgen;
	desrt.fonction[8] = (EXAWORD (FAR PTR)()) Dll_watb;
	desrt.fonction[9] = (EXAWORD (FAR PTR)()) Dll_wposcur;
	desrt.fonction[10] = (EXAWORD (FAR PTR)()) Dll_wimpl;
	desrt.fonction[11] = (EXAWORD (FAR PTR)()) Dll_wgel;
	desrt.fonction[12] = (EXAWORD (FAR PTR)()) Dll_wfend;
	desrt.fonction[13] = (EXAWORD (FAR PTR)()) Dll_wsetatb;
	desrt.fonction[14] = (EXAWORD (FAR PTR)()) Dll_sf_init;
	desrt.fonction[15] = (EXAWORD (FAR PTR)()) Dll_sl_activ;
	desrt.fonction[16] = (EXAWORD (FAR PTR)()) Dll_sl_mess;
	desrt.fonction[17] = (EXAWORD (FAR PTR)()) Dll_sl_inv;
	desrt.fonction[18] = (EXAWORD (FAR PTR)()) Dll_sl_desac;
	desrt.fonction[19] = (EXAWORD (FAR PTR)()) Dll_menu_creat;
	desrt.fonction[20] = (EXAWORD (FAR PTR)()) Dll_menu_option;
	desrt.fonction[21] = (EXAWORD (FAR PTR)()) Dll_menu_sep;
	desrt.fonction[22] = (EXAWORD (FAR PTR)()) Dll_menu_modif_opt;
	desrt.fonction[23] = (EXAWORD (FAR PTR)()) Dll_menu_latt_opt;
	desrt.fonction[24] = (EXAWORD (FAR PTR)()) Dll_menu_matt_opt;
	desrt.fonction[25] = (EXAWORD (FAR PTR)()) Dll_menu_blank_opt;
	desrt.fonction[26] = (EXAWORD (FAR PTR)()) Dll_menu_vis;
	desrt.fonction[27] = (EXAWORD (FAR PTR)()) Dll_menu;
	desrt.fonction[28] = (EXAWORD (FAR PTR)()) Dll_menu_inv;
	desrt.fonction[29] = (EXAWORD (FAR PTR)()) Dll_menu_sup;
	desrt.fonction[30] = (EXAWORD (FAR PTR)()) Dll_list_creat;
	desrt.fonction[31] = (EXAWORD (FAR PTR)()) Dll_listmul_creat;
	desrt.fonction[32] = (EXAWORD (FAR PTR)()) Dll_list_element;
	desrt.fonction[33] = (EXAWORD (FAR PTR)()) Dll_list_read_elt;
	desrt.fonction[34] = (EXAWORD (FAR PTR)()) Dll_list_down;
	desrt.fonction[35] = (EXAWORD (FAR PTR)()) Dll_list_up;
	desrt.fonction[36] = (EXAWORD (FAR PTR)()) Dll_list_matt_elt;
	desrt.fonction[37] = (EXAWORD (FAR PTR)()) Dll_list_close;
	desrt.fonction[38] = (EXAWORD (FAR PTR)()) Dll_list_vis;
	desrt.fonction[39] = (EXAWORD (FAR PTR)()) Dll_list;
	desrt.fonction[40] = (EXAWORD (FAR PTR)()) Dll_list_inv;
	desrt.fonction[41] = (EXAWORD (FAR PTR)()) Dll_list_sup;
	desrt.fonction[42] = (EXAWORD (FAR PTR)()) Dll_bvalid_spc;
	desrt.fonction[43] = (EXAWORD (FAR PTR)()) Dll_bvalid;
	desrt.fonction[44] = (EXAWORD (FAR PTR)()) Dll_sf_end;
	desrt.fonction[45] = (EXAWORD (FAR PTR)()) Dll_wfmod;
	desrt.fonction[46] = (EXAWORD (FAR PTR)()) Dll_help_activ;
	desrt.fonction[47] = (EXAWORD (FAR PTR)()) Dll_help;
	desrt.fonction[48] = (EXAWORD (FAR PTR)()) Dll_help_desac;
	desrt.fonction[49] = (EXAWORD (FAR PTR)()) Dll_help_def;
	desrt.fonction[50] = (EXAWORD (FAR PTR)()) Dll_wget_impl;
	desrt.fonction[51] = (EXAWORD (FAR PTR)()) Dll_bd_creat;
	desrt.fonction[52] = (EXAWORD (FAR PTR)()) Dll_bd_insert;
	desrt.fonction[53] = (EXAWORD (FAR PTR)()) Dll_bd_use;
	desrt.fonction[54] = (EXAWORD (FAR PTR)()) Dll_bd_inv;
	desrt.fonction[55] = (EXAWORD (FAR PTR)()) Dll_bd_sup;
	desrt.fonction[56] = (EXAWORD (FAR PTR)()) Dll_bd_putdata;
	desrt.fonction[57] = (EXAWORD (FAR PTR)()) Dll_bd_getdata;
	desrt.fonction[58] = (EXAWORD (FAR PTR)()) Dll_wexit;
	desrt.fonction[59] = (EXAWORD (FAR PTR)()) Dll_wrefresh;
	desrt.fonction[60] = (EXAWORD (FAR PTR)()) Dll_menu_way;
	desrt.fonction[61] = (EXAWORD (FAR PTR)()) Dll_swcreat;
	desrt.fonction[62] = (EXAWORD (FAR PTR)()) Dll_wcadre;
	desrt.fonction[63] = (EXAWORD (FAR PTR)()) Dll_wtitre;
	desrt.fonction[64] = (EXAWORD (FAR PTR)()) Dll_wmove;
	desrt.fonction[65] = (EXAWORD (FAR PTR)()) Dll_listel_del;
	desrt.fonction[66] = (EXAWORD (FAR PTR)()) Dll_listel_ins;
	desrt.fonction[67] = (EXAWORD (FAR PTR)()) Dll_set_tch_esc;
	desrt.fonction[68] = (EXAWORD (FAR PTR)()) Dll_winfo;
	desrt.fonction[69] = (EXAWORD (FAR PTR)()) Dll_get_style;
	desrt.fonction[70] = (EXAWORD (FAR PTR)()) Dll_set_style;
	desrt.fonction[71] = (EXAWORD (FAR PTR)()) Dll_wlangue;
	desrt.fonction[72] = (EXAWORD (FAR PTR)()) Dll_asfvers;
	desrt.fonction[88] = (EXAWORD (FAR PTR)()) Dll_who_is_there;
	desrt.fonction[89] = (EXAWORD (FAR PTR)()) Dll_rlecomp;
	desrt.fonction[90] = (EXAWORD (FAR PTR)()) Dll_rledecomp;
	desrt.nombre = 91;

	desrt.fonction[desrt.nombre+1]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+2]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+3]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+4]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+5]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+6]	= (EXAWORD (FAR PTR)()) v_putch;
	desrt.fonction[desrt.nombre+7]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+8]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+9]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+10]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+11]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+12]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+13]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+14]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[desrt.nombre+15]	= connect_access_controller;
	desrt.fonction[desrt.nombre+16]	= (EXAWORD (FAR PTR)()) 0;

	if (rt_init != (VOID FAR PTR) 0L) {
		rt_init->cico.numero = (16384 | 32);
		rt_init->cico.fonction[CICO_CI]     = desrt.fonction[desrt.nombre+1]; 
	 	rt_init->cico.fonction[CICO_TPCI]   = desrt.fonction[desrt.nombre+2];
	  	rt_init->cico.fonction[CICO_PRFO]   = desrt.fonction[desrt.nombre+3];  	
		rt_init->cico.fonction[CICO_LCFO]   = desrt.fonction[desrt.nombre+4];  	
		rt_init->cico.fonction[CICO_CONF]   = desrt.fonction[desrt.nombre+5]; 	
		rt_init->cico.fonction[CICO_CO]     = desrt.fonction[desrt.nombre+6]; 	
		rt_init->cico.fonction[CICO_MES]    = desrt.fonction[desrt.nombre+7]; 	
		rt_init->cico.fonction[CICO_LIGNE]  = desrt.fonction[desrt.nombre+8]; 	
		rt_init->cico.fonction[CICO_COLONNE]= desrt.fonction[desrt.nombre+9]; 	
		rt_init->cico.fonction[CICO_START]  = desrt.fonction[desrt.nombre+10]; 	
		rt_init->cico.fonction[CICO_FLUSH]  = desrt.fonction[desrt.nombre+11]; 	
		rt_init->cico.fonction[CICO_LO]     = desrt.fonction[desrt.nombre+12]; 	
		rt_init->cico.fonction[CICO_MIMA]   = desrt.fonction[desrt.nombre+13];   
		rt_init->cico.fonction[CICO_EVENT]  = desrt.fonction[desrt.nombre+14];
		rt_init->cico.fonction[CICO_INIT]   = desrt.fonction[desrt.nombre+15];
		rt_init->cico.fonction[CICO_GRAPH]  = desrt.fonction[desrt.nombre+16];
		}

	return((VOID FAR PTR) &desrt);
}


