#include "guimouse.h"
#include "stdcursor.h"

/*	----------------------------------------------------------------------		*/
/*	Modification : 	14/9/2006 IJM 							*/
/*			for new subtext selection mechansisms using the mouse 		*/
/*			for inset/delete/copy/paste type operations.			*/
/*	----------------------------------------------------------------------		*/
							
#define	EDIT_SECRET	512
#define	EDIT_REFRESH	1024
#define	EDIT_NOFOCUS	2048

#ifdef	WIN32
#define	xgr_lcfo(a,b,c) lcfo(a,b,c)
#define	xgr_prfo(a,b,c) prfo(a,b,c)
#endif

private	char	edithotkey[256];
private	int	edithotkeys=0;
private	int	editmask=0;
private	int	editcolumn=-1;
private	int	defaultinsert=1;
private	int	editinsert=0;
private	int	editline=-1;
private	int	editcursor=0;

private	int	EditColour[4] = {
	0x001F, 	/* standard white 	:	background colour 	*/
	0x0010,		/* standard black	:	character  colour	*/
	0x001D,		/* standard focus	:	normal focus 		*/
	0x001B		/* standard focus - 2	:	insert focus		*/
	};

private	int	EditCursorTempo=-1;

private	char * xwbuffer=(char *) 0;

private	int	EditKeys[33] = {
	0,	/* Null	  */
	0x0001,	/* Ctrl A */
	0x0002,	/* Ctrl B */
	0x0003,	/* Ctrl C */
	0x0004,	/* Ctrl D */
	0x0005,	/* Ctrl E */
	0x0006,	/* Ctrl F */
	0x0007,	/* Ctrl G */
	0x0008,	/* Ctrl H */
	0x0009,	/* Ctrl I */
	0x000A,	/* Ctrl J */
	0x000B,	/* Ctrl K */
	0x000C,	/* Ctrl L */
	0x000D,	/* Ctrl M */
	0x000E,	/* Ctrl N */
	0x000F,	/* Ctrl O */
	0x0010,	/* Ctrl P */
	0x0011,	/* Ctrl Q */
	0x0012,	/* Ctrl R */
	0x0013,	/* Ctrl S */
	0x0014,	/* Ctrl T */
	0x0015,	/* Ctrl U */
	0x0016,	/* Ctrl V */
	0x0017,	/* Ctrl W */
	0x0018,	/* Ctrl X */
	0x0019,	/* Ctrl Y */
	0x001A,	/* Ctrl Z */
	0x001B,	/* Escape */
	0x001C,	/* Home   */
	0x001D,	/*        */
	0x001E,	/*        */
	0x0004,	/*        */
	0x007F,	/* Delete */
	};

#define	EditKeyDeleteAll	EditKeys[0x0001]
#define	EditKeyHomeEnd		EditKeys[0x0002]
#define	EditKeyPageDown		EditKeys[0x0003]
#define	EditKeyLeft		EditKeys[0x0004]
#define	EditKeyDown		EditKeys[0x0005]
#define	EditKeyRight		EditKeys[0x0006]
#define	EditKeyBell		EditKeys[0x0007]
#define	EditKeyBackSpace	EditKeys[0x0008]
#define	EditKeyTab		EditKeys[0x0009]
#define	EditKeyLineFeed		EditKeys[0x000A]
#define	EditKeyUp		EditKeys[0x000B]
#define	EditKeyHome		EditKeys[0x000C]
#define	EditKeyEnter		EditKeys[0x000D]
#define	EditKeyCutLine		EditKeys[0x000E]
#define	EditKeyInsert		EditKeys[0x000F]
#define	EditKeyPrint		EditKeys[0x0010]
#define	EditKeyHelp		EditKeys[0x0011]
#define	EditKeyPageUp		EditKeys[0x0012]
#define	EditKeyCtrlS		EditKeys[0x0013]
#define	EditKeyCtrlT		EditKeys[0x0014]
#define	EditKeyCtrlU		EditKeys[0x0015]
#define	EditKeyCtrlV		EditKeys[0x0016]
#define	EditKeyCopy		EditKeys[0x0017]
#define	EditKeyPaste		EditKeys[0x0018]
#define	EditKeyDeleteLine	EditKeys[0x0019]
#define	EditKeyClearEnd		EditKeys[0x001A]
#define	EditKeyEscape		EditKeys[0x001B]
#define	EditKeyClear		EditKeys[0x001C]
#define	EditKeyExtra1		EditKeys[0x001D]
#define	EditKeyExtra2		EditKeys[0x001E]
#define	EditKeyExtra3		EditKeys[0x001F]
#define	EditKeyDelete		EditKeys[0x0020]

public	int	get_visual_editline()	{	return( editline  );	}
public	int	get_visual_editcol()	{	return( editcolumn);	}

public 	void	vedit_ctrl_w( char * sptr, int offset, int slen, int fcharset )
{
	int	i;
	int	l=0;
	char	*	tptr;
	if ( offset >= slen )
		return;
	if (xwbuffer != (char *) 0)
		xwbuffer = liberate( xwbuffer );

	if ((xwbuffer = allocate((slen - offset)+ 16)) != (char *) 0) {
		for (l=0,tptr=xwbuffer, i=offset; i < slen; i++ ) {
			if ((*(tptr++) = *(sptr+i)) != ' ')
				l = ((i-offset)+1);
			}
		*tptr = 0;
		if ( l != 0 ) {
#ifdef	UNIX
			publish_selection( xwbuffer, l );
#else
			ClipboardSet_byexa( xwbuffer, l, fcharset );
#endif
			}
		}
	return;	

}

public	int	visual_edit_keys( int operation, char * buffer, int length ) 
{
	int	i;
	switch ( operation ) {

		case	0	:	/* Get Edit Keys */

			if ( length > 32 ) length = 32 ;

			for ( i=0; i < length; i++ )
				*(buffer+i) = (EditKeys[(i+1)] & 0x00FF);
			break;

		case	1	:	/* Set Edit Keys */

			if ( length > 32 ) length = 32 ;

			for ( i=0; i < length; i++ )
				EditKeys[(i+1)] = (*(buffer+i) & 0x00FF);

			break;

		case	2	:	/* Get Edit Colours */
			if ( length > 4 ) length = 4;
			for ( i=0; i < length; i++ )
				*(buffer+i) = (EditColour[i] & 0x00FF);
			break;

		case	3	:	/* Set Edit Colours */
			if ( length > 4 ) length = 4;
			for ( i=0; i < length; i++ )
				EditColour[i] = (*(buffer+i) & 0x00FF);
			break;

		}
	return(0);
}

private	void	insert_edit_character( char * sptr, int slen, int i, int doffset, int c )
{
	int	nb;
	for ( nb=(slen-1); nb > (i+doffset); nb-- )
		*(sptr+nb) = *(sptr+(nb-1));
	*(sptr+i+doffset) = c;
	return;
}

public 	int	vedit_ctrl_x( char * tptr, int offset, int tlen, int fcharset, int inserting )
{
#ifdef	UNIX
	char * sptr;
	if (!( sptr = xwbuffer ))
		return(0);

	if (!( inserting )) {
		for (	; offset < tlen; offset++ ) {
			if (!( *sptr )) 
				break;
			else	*(tptr+offset) = *(sptr++);
			}
		}
	else	{
		for (	; offset < tlen; offset++ ) {
			if (!( *sptr )) 
				break;
			else	insert_edit_character(tptr, tlen, 0, offset, *(sptr++) );
			}
		}
#else
	/* GWB le 20/11/2007 tlen-offset, avant tlen et bien sur on cassait tout */
	ClipboardGet_byexa( &tptr[offset], tlen-offset, fcharset); /*FCH22042005*/
#endif
	return(1);
}

public	void	visual_hotkeys( char * buffer, int buflen )
{
	int	i;
	for ( i=0; i < buflen; i++ )
		edithotkey[i] = *(buffer++);
	edithotkeys=buflen;
	return;
}

private	int	is_edit_hotkey(int c)
{
	int	i;
	for (i=0; i < edithotkeys; i++ )
		if (( edithotkey[i] & 0x00FF)  == (c & 0x00FF))
			return(1);
	return(0);
}

public	int	set_edit_mask(int v )
{
	int	lv=editmask;
	editmask = v;
	editcursor = ((v & 0x00F0) >> 4);
	return( lv );
}


private	void	edit_cursor_on(int x, int y,int f, char * sptr, int i, int doffset, int nc,int nl, int inserting, int dlen)
{
	int	xadjust;
	int	cc;
	int	nbc;
	int	nbl;
	int	fw = guifontsize(f);
	int	fh =(fw >> 8); 	
	if ( editcursor ) return;
	fw &= 0x00FF;
	/* cicocolour(standard_white,standard_focus-(inserting*2)); */
	cicocolour(EditColour[0],EditColour[2+inserting]);
	xadjust = textsizelen(f,sptr+doffset,i);
	if ( nl > 1 ) {
		nbc = (i % nc);
		nbl = (i / nc);
		if (!( editmask & EDIT_SECRET ))
			PixelFontCat((x+(fw*nbc)),(y+(fh*nbl)),f,((cc = *(sptr+i+doffset)) ? cc : ' '));
		else 	PixelFontCat((x+(fw*nbc)),(y+(fh*nbl)),f,'*');
		}
	else 	{
		nbc = (i % dlen);
		nbl = 0; /* (i / dlen); */
		if (!( editmask & EDIT_SECRET ))
			PixelFontCat((x+xadjust),(y+(fh*nbl)),f,((cc = *(sptr+i+doffset)) ? cc : ' '));
		else 	PixelFontCat((x+xadjust),(y+(fh*nbl)),f,'*');
		}
}

private	void	edit_cursor_off(int x, int y,int f, char * sptr, int i, int doffset, int nc,int nl, int fg, int bg, int dlen )
{
	int	xadjust;
	int	cc;
	int	nbc;
	int	nbl;
	int	fw = guifontsize(f);
	int	fh =(fw >> 8); 	
	if ( editcursor ) return;
	fw &= 0x00FF;
	cicocolour(fg,bg);
	xadjust = textsizelen(f,sptr+doffset,i);
	if ( nl > 1 ) {
		nbc = (i % nc);
		nbl = (i / nc);
		if (!( editmask & EDIT_SECRET ))
			PixelFontCat((x+(fw*nbc)),(y+(fh*nbl)),f,((cc = *(sptr+i+doffset)) ? cc : ' '));
		else	PixelFontCat((x+(fw*nbc)),(y+(fh*nbl)),f,'*');
		}
	else	{
		nbc = (i % dlen);
		nbl = 0; /* (i / dlen); */
		if (!( editmask & EDIT_SECRET ))
			PixelFontCat((x+xadjust),(y+(fh*nbl)),f,((cc = *(sptr+i+doffset)) ? cc : ' '));
		else 	PixelFontCat((x+xadjust),(y+(fh*nbl)),f,'*');
		}
	return;
}

private	void	edit_cursor_zone_on(int x, int y,int f, char * sptr, int i, int n, int doffset, int nc, int nl, int inserting, int dlen )
{
	int	holdcurse=editcursor;
	editcursor = 0;
	do	{
		edit_cursor_on(x,y,f,sptr,i++,doffset,nc,nl,inserting,dlen);
		}
	while (i <= n );
	editcursor = holdcurse;
}

private	void	edit_cursor_zone_off(int x, int y,int f, char * sptr, int i, int n, int doffset, int nc, int nl, int fg, int bg, int dlen)
{
	int	holdcurse=editcursor;
	editcursor = 0;
	do	{
		edit_cursor_off(x,y,f,sptr,i++,doffset,nc,nl,fg,bg,dlen);
		}
	while (i <= n );
	editcursor = holdcurse;
}

public 	void	vedit_ctrl_del( char * sptr, int offset, int slen, int fcharset )
{
	int	nb;
	for ( nb=offset; nb < (slen-1); nb++ )
		*(sptr+nb) = *(sptr+(nb+1));
	*(sptr+nb) = ' ';
	*(sptr+(nb+1)) = 0;
	return;
}

private	void	edit_cursor_zone_cut( char * sptr, int i, int n, int doffset, int slen, int fcharset )
{
	do	{
		vedit_ctrl_del( sptr, n+doffset, slen, fcharset);
		n--;
		}
	while ( n >= i );
}

private	void	edit_getch_cursor(int x, int y, int fw, int fh )
{
	hide();
	switch ( editcursor ) {
		case	_GIGO_CURSOR_VLINE 	:
			xorzone(x,y+1,1,fh-2,169);
			break;
		case	_GIGO_CURSOR_BLOCK	:
			xorzone(x,y,fw,fh,169);
			break;
		case	_GIGO_CURSOR_HLINE 	:
			xorzone(x,(y+(fh-2)),fw,1,169);
			break;
		case	_GIGO_CURSOR_OUTLINE	:
			xorzone(x,y,fw,1,169);
			xorzone(x+(fw-1),y+1,1,fh-2,169);
			xorzone(x,y+1,1,fh-2,169);
			xorzone(x,(y+(fh-1)),fw,1,169);
			break;
		default:
			/*FCH ajout du default*/
			xorzone(x,y+1,1,fh-2,169);
			break;
		}
	show(x,y,fw,fh);
	return;
}

private	int	visual_edit_getch(int x,int y, int fw, int fh, int i,int xadjust)
{
	char *	eptr;
	int	flipflop=0;
	if (!( editcursor ))
		return( visual_getch() );
	else	{
		/* x += (i *fw); */
		x += xadjust;
		while (!( visual_kbhit() )) {
			edit_getch_cursor(x,y,fw,fh);
			if ( EditCursorTempo == -1 ) {
				if (!(eptr = getenv("VCURSORTEMPO")))
					EditCursorTempo = 200000;
				else	EditCursorTempo = atoi(eptr);
				}
#ifdef	UNIX
			usleep(EditCursorTempo);
#elif defined(WIN32)
			Sleep(EditCursorTempo*10);
#endif
			flipflop = ((flipflop + 1) & 1);
			}
		if ( flipflop )	{
			edit_getch_cursor(x,y,fw,fh);
			}
		return( visual_getch() );
		}
}

private	int	visual_edit_text( int x, int y, int w, int h, int f, int fg, int bg, char * sptr, int slen , int o )
{
	int	prop=0;
	int	nc,nl;
	int	fw,fh;
	int	dlen;	
	int	tl;
	fw = guifontsize(f);	
	fh =(fw >> 8); 	fw &= 0x00FF;
	nc  = (w/fw); nl  = (h/fh);

	if (( nl == 1 ) &&  ( textsizelen(f,"i",1) != textsizelen(f,"W",1))) {
		dlen=nc; 
		while (dlen < slen) {
			prop = 1;
			if ((tl = textsizelen(f,sptr,dlen)) <= w )
				dlen++;
			else 	{
				dlen--;
				break;
				}
			}
		visual_text(x,y,w,h,f,fg,bg,sptr,dlen,_A_LEFT|_A_SPACE);
		}
	else 	{
		if ( slen > (nc*nl) )
			dlen = (nc*nl);
		else	dlen = slen;
		visual_text(x,y,w,h,f,fg,bg,sptr,dlen,0);
		}
	return(dlen);
}

private	int	visual_mouse_position( int mx, int my, int f, char * sptr, int dlen )
{
	int	start=0;
	int	finish=0;
	int	n=0;
	for (n=0; n < dlen; n++ ) {
		finish = textsizelen(f,sptr,(n+1));
		if (( mx >= start ) && ( mx <= finish ))
			break;
		else	start = finish;
		}
	return(n);
}

public	int 	visual_edit(int x,int y, int w, int h, int f, char * sptr, int slen )
{
	int	ungotc=0;
	int	xadjust=0;
	int	z=0;
	int	nb;
	int	yl;
	int	i=0;
	int	j=0;
	int	n=0;
	int	c=0;
	int	cc=0;
	int	nc,nl;
	int	fw,fh;
	int	nbc,nbl;
	int	mx,my,mt;
	int	inserting=1;
/*	int	fg=standard_black;	*/
/*	int	bg=standard_white;	*/
	int	fg=EditColour[1];
	int	bg=EditColour[0];
	int	scrolling=0;
	int	dlen=0;
	int	doffset=0;
	char	leftarrow[2];
	char	savearrow[2];
	int	fcharset;
	int	hend=0;
	int	gotdown=0;
	int	adjv=0;
	int	xlen;
	int	tsl=0;

	if (!( sptr ))		return(-1);
	else if (!( f ))	return(-1);

	xgr_lcfo(2,&savearrow,1);
	leftarrow[0] = 4;
	xgr_prfo(2,&leftarrow,1);

	fw = guifontsize(f);	fh =(fw >> 8); 	fw &= 0x00FF;
#ifdef	WIN32
	fcharset = guifontcharset(f);
#else
	fcharset=0;
#endif
	if ( h < fh ) { h = fh; }

	nbc = nbl = i = 0; 

	nc  = (w/fw); nl  = (h/fh);

	/* step forward by half the difference */
	/* ----------------------------------- */
	if ((nl*fh) < h) { 
		adjv = ((h - (nl*fh))/2); 
		y += adjv;
		h = (nl*fh);
		}

	if ( editmask & EDIT_REFRESH ) {
		if ((nbl = editline) == -1)
			nbl=0;
		if ((nbc = editcolumn) == -1)
			nbc=0;
		if ((i = ((nbl * nc) + nbc)) >= slen)
			nbl = nbc = i = 0;
		inserting=editinsert;
		}

	hend=n=i;

	if ( slen > (nc*nl) ) {
		scrolling=1;
		dlen = (nc*nl);
		doffset=0;
		}
	else	{
		scrolling=0;
		dlen = slen;
		doffset=0;
		}

	if (!( editmask & EDIT_SECRET ))
		dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);

	c = 13;

	if ( editmask & EDIT_NOFOCUS ) {
		return( -1 );
		}

	while ( i < slen ) {
		xadjust = textsizelen(f,sptr+doffset,i);
		edit_cursor_on(x,y,f,sptr,i,doffset,nc,nl,inserting,dlen);
		while ((c = visual_edit_getch(x,y,fw,fh,i,xadjust)) == 256) {
			mx = visual_event(7);
			my = visual_event(6);
			if (( mx >= x )
			&&  ( my >= y )
			&&  ( mx < (x+w))
			&&  ( my < (y+h))
			&&  ( visual_event(2) != _MIMO_RIGHT)) {
				switch ((mt = visual_event(1))) {
					case	_MIMO_DOWN	:
						gotdown=1;
						edit_cursor_off(x,y,f,sptr,i,doffset,nc,nl,fg,bg,dlen);
						mx -= x;
						my -= y;
						if ( nl > 1 )
							n = (((my/fh)*nc)+(mx/fw));
						else	n = visual_mouse_position(mx,my,f,sptr+doffset,dlen);
						i = 0;
						for (z=0; i < slen; i++ )
							if (*(sptr+i+doffset)  != ' ' )
								z = (i+1);
						if ( n > z )
							n = z;
						hend = i = n;
						edit_cursor_on(x,y,f,sptr,i,doffset,nc,nl,inserting,dlen);
						xadjust = textsizelen(f,sptr+doffset,i);
						continue;
					default			:
						edit_cursor_zone_off(x,y,f,sptr,i,hend,doffset,nc,nl,fg,bg,dlen);
						mx -= x;
						my -= y;
						if ( nl > 1 )
							n = (((my/fh)*nc)+(mx/fw));
						else	n = visual_mouse_position(mx,my,f,sptr+doffset,dlen);
						j = 0;
						for (z=0; j < slen; j++ )
							if (*(sptr+j+doffset)  != ' ' )
								z = (j+1);
						if ( n > z )
							n = z;
						if (!( gotdown ))
							i = n;
						if ( mt == _MIMO_UP )
							gotdown=0;
						if ( n < hend ) {
							i = n;
							edit_cursor_zone_on(x,y,f,sptr,i,hend,doffset,nc,nl,inserting,dlen);
							}
						else if ((hend = n) > i )
							edit_cursor_zone_on(x,y,f,sptr,i,hend,doffset,nc,nl,inserting,dlen);
						else	edit_cursor_on(x,y,f,sptr,i,doffset,nc,nl,inserting,dlen);
						xadjust = textsizelen(f,sptr+doffset,i);
						continue;
					}
				}
			else	{
				edit_cursor_off(x,y,f,sptr,i,doffset,nc,nl,fg,bg,dlen);
				xgr_prfo(2,&savearrow,1);
				return(c);
				}
			}
		edit_cursor_off(x,y,f,sptr,i,doffset,nc,nl,fg,bg,dlen);
		if ( c & _MIMO_ALT ) {
			 /* Alt key extension */
			break;			
			}

		if ( is_edit_hotkey(c) ) { break; }

		if ( c == EditKeyRight ) {	/* Default : 6 : Ctrl F */
			if ( (i+1) < dlen ) 
				i++;
			else if (( i+doffset ) < slen ) {
				doffset++;
				while (1) {
					tsl = textsizelen(f,sptr+doffset,i);
					if ( tsl < w ) { break; }
					doffset++; 
					if ( i ) i--;
					}
				if (!( editmask & EDIT_SECRET )) {
					while ((dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0)) <= i) {
						doffset++;
						if ( i ) i--;
						}
					}
				}
			hend=i;
			continue;
			}
		else if ( c == EditKeyLeft ) { /* Default 8 : Ctrl H */
			if ( i > 0 ) 
				i--;
			else if ( doffset > 0 ) {
				doffset--;
				if (!( editmask & EDIT_SECRET ))
					dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
				}
			hend=i;
			continue;
			}
		else if ( c == EditKeyPageDown ) { /* Default /0C : Ctrl C */
			if ( hend > i ) {
				vedit_ctrl_w(sptr,i+doffset,hend+doffset+1,fcharset);
				continue;
				}
			else	break;
			}
		else if ( c == EditKeyCopy ) { /* Default /17 : Ctrl W */
			vedit_ctrl_w(sptr,i+doffset,slen,fcharset);
			hend=i;
			continue;
			}
		else if  ( c == EditKeyCtrlV )  { /* Default /16 : Ctrl V */
			if ( hend > i ) {
				edit_cursor_zone_cut( sptr, i, hend, doffset, slen, fcharset );
				}
			hend = i;
			if ( vedit_ctrl_x(sptr,i+doffset,slen,fcharset,inserting) != 0 )
				if (!( editmask & EDIT_SECRET ))
					dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
			if (!( editmask & EDIT_REFRESH ))
				continue;
			else	break;
			}
		else if  ( c == EditKeyPaste )  { /* Default /18 : Ctrl X */
			hend=i;
			if ( vedit_ctrl_x(sptr,i+doffset,slen,fcharset,inserting) != 0 )
				if (!( editmask & EDIT_SECRET ))
					dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
			if (!( editmask & EDIT_REFRESH ))
				continue;
			else	break;
			}

		else if ( c == EditKeyDeleteLine ) { /* Default /19 : Ctrl Y */
			hend=i;
			if ( nl > 1 ) {
				if (( yl = ((i/nc)+1)) < nl ) {
					i = ((yl-1) * nc);
					for ( nb=0; nb < nc; nb++ )
						*(sptr+nb+i) = *(sptr+(nb+i+nc));
					}
				memset( (sptr + ((yl-1)*nc)),' ',nc);
				if (!( editmask & EDIT_SECRET ))
					dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
				if (!( editmask & EDIT_REFRESH ))
					continue;
				else	break;
				}
			else 	break;	/* was c = EditKeyDeleteAll; */
			}
		if ( c == EditKeyDeleteAll ) { /* Default : /01 : Ctrl A */
			i = 0; doffset=0;
			c = EditKeyClearEnd;
			hend=i;
			}
		if ( c == EditKeyClearEnd ) { /* Default : /1A : Ctrl Z */
			hend=i;
			memset(sptr+i+doffset,' ',slen-i);
			if (!( editmask & EDIT_SECRET ))
				dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
			if (!( editmask & EDIT_REFRESH ))
				continue;
			else	break;
			}
		if ( c == 256 ) {
#ifdef	_BEFORE_12092006
			mx -= x;
			my -= y;
			n = (((my/fh)*nc)+(mx/fw));
			i = 0;
			for (z=0; i < slen; i++ )
				if (*(sptr+i+doffset)  != ' ' )
					z = (i+1);
			if ( n > z )
				n = z;
			i = n;
#endif
			continue;
			}
		if ( c == EditKeyHomeEnd ) { /* Default 2 : Ctrl B */
			if ( i+doffset ) {
				i = doffset = 0;
				}
			else	{
				for (z=0,i=0; i < slen; i++ ) {
					if (!( *(sptr+i) ))
						break;
					else if (*(sptr+i)  != ' ' )
						z = (i+1);
					}
				i = z ;
				if ( i > (nc*nl)) {
					doffset = (i-(nc*nl));
					i = ((nc*nl)-1);
					}
				}
			if ( scrolling )
				if (!( editmask & EDIT_SECRET ))
					dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
			hend=i;
			continue;
			}
		else if ( c == EditKeyUp ) { /* Default /0B : Ctrl K */
			if ( nbl > 0 ) {
				nbl--;
				i = (nbl*nc)+nbc;
				hend=i;
				continue;
				}
			else	break;
			}
		else if ( c == EditKeyDown ) { /* Default /05 : Ctrl E */
			if ((nbl+1) < nl) {
				nbl++;
				i = (nbl*nc)+nbc;
				hend=i;
				continue;
				}
			else	break;
			}
		else if ( c == EditKeyEnter) { /* Default /0D : Enter */
			nbl++; 
			nbc = 0;
			i = (nbl*nc);
			hend=i;
			if ( nbl < nl )
				continue;
			else	{
				nbl--;
				break;
				}
			}
		else if ( c == EditKeyInsert ) { /* Default : /0F : Ctrl O */				
			inserting = ((inserting+1)&1);
			continue;
			}
		else if ( c == EditKeyDelete ) { /* Default : /7F DELETE */
			if ( hend > i ) {
				edit_cursor_zone_cut( sptr, i, hend, doffset, slen, fcharset );
				}
			else	{
				vedit_ctrl_del(sptr,i+doffset,slen,fcharset);
				}
			hend=i;
			if (!( editmask & EDIT_SECRET ))
				dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
			if (!( editmask & EDIT_REFRESH ))
				continue;
			else	break;
			}
		else if ( c == EditKeyBackSpace  ) {
			if ( i > 0 ) {
				i--;
				hend=i;
				}
			else if ( doffset > 0 ) {
				doffset--;
				hend=i;
				}
			else	{
				hend=i;
				continue;
				}
			for ( nb=(i+doffset); nb < (slen-1); nb++ )
				*(sptr+nb) = *(sptr+(nb+1));
			*(sptr+nb) = ' ';
			*(sptr+(nb+1)) = 0;
			if (!( editmask & EDIT_SECRET ))
				dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
			if (!( editmask & EDIT_REFRESH ))
				continue;
			else	break;
			}
		else  if ( c < ' ' )
			break;
		else 	{
			if (!( inserting )) {
				if ( hend > i ) {
					edit_cursor_zone_cut( sptr, (i+1), hend, doffset, slen, fcharset );
					}
				*(sptr+i+doffset) = c;
				cicocolour(fg,bg);
				if (!( editmask & EDIT_SECRET ))
					dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
				}
			else	{
				if ( hend > i ) {
					edit_cursor_zone_cut( sptr, i, hend, doffset, slen, fcharset );
					}

				insert_edit_character( sptr, slen, i, doffset, c);

				if (!( editmask & EDIT_SECRET ))
					dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0);
				}
			if ( (i+1) < dlen ) 
				i++;
			else if (( i+doffset ) < slen ) {
				doffset++;
				while (1) {
					tsl = textsizelen(f,sptr+doffset,i);
					if ( tsl < w ) { break; }
					doffset++; 
					if ( i ) i--;
					}
				if (!( editmask & EDIT_SECRET )) {
					while ((dlen = visual_edit_text(x,y,w,h,f,fg,bg,(sptr+doffset),slen,0)) <= i) {
						doffset++; 
						if ( i ) i--;
						}
					}
				}
			hend=i;
			if (!( editmask & EDIT_REFRESH ))
				continue;
			else	break;
			}
		}
	xgr_prfo(2,&savearrow,1);
	if (( editmask & EDIT_REFRESH ) && ( c != 27 )) {
		nbc = (i % nc);
		nbl = (i / nc);
		editline=nbl;
		editcolumn=nbc;
		editinsert=inserting;
		}
	else	{
		editinsert=defaultinsert;
		editline=editcolumn=-1;
		}
	return(c);
}



