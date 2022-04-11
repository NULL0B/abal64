#ifndef	_z_c
#define	_z_c

int	getch()
{
	int	c;
_asm	{
	mov  	ah,010h
	int	110
	xor	ah, ah
	mov	c,ax
	}
	return(c); 
}

void	pause()
{
	(void) getch();
	return;
}



WORD	dllzzinit(BYTE * b)
{
	trace("dllzzinit(%s)\n",b);
	pause(); return(0); 
}

WORD	dllzzinitmouse(BYTE * b)
{
	trace("dllzzinitmouse(%s)\n",b); pause(); return(0); 
}

WORD	dllzzshowmouse()
{
	trace("dllzzshowmouse()\n"); pause(); return(0); 
}

WORD	dllzzhidemouse()
{
	trace("dllzzhidemouse()\n"); pause(); return(0); 
}

WORD	dllzzreserve1()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}


WORD	dllzzstatusmouse(BYTE * b)
{
	trace("dllzzstatysmouse()\n"); pause(); return(0); 
}

WORD	dllzzreserve2()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}


WORD	dllzzreserve3()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzrlecpt(BYTE * b,BYTE * c,WORD d)
{
	trace("dllzrlecpt(%s,%s,%u)\n",b,c,d); pause(); return(0); 
}


WORD	dllzrledcpt(BYTE * b,BYTE * c,WORD d)
{
	trace("dllzrledcpt(%s,%s,%u)\n",b,c,d); pause(); return(0); 
}


WORD	dllzzreserve4()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzzreserve5()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzzreserve6()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzzreserve7()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzbprint(WORD a,BYTE * b,WORD c,WORD d)
{
	trace("dllzbprint()\n"); pause(); return(0); 
}


WORD	dllzbprintxy(WORD a,WORD b,WORD c,BYTE * d)
{
	trace("dllzbprintxy()\n"); pause(); return(0); 
}

WORD	dllzbhide()
{
	trace("dllzbhide()\n"); pause(); return(0); 
}

WORD	dllzbshow(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzbshow()\n"); pause(); return(0); 
}

WORD	dllzzwait1_10()
{
	trace("dllzzwait1_10()\n"); pause(); return(0); 
}

WORD	dllzwanal(BYTE * b,WORD a,WORD c,WORD d/*?*/,WORD e/*?*/,WORD f/*?*/,WORD g/*?*/,WORD h/*?*/)
{
	trace("dllzwanal()\n"); pause(); return(0); 
}

WORD	dllzzend()
{
	trace("dllzzend()\n"); pause(); return(0); 
}

WORD	dllzz_adrs(BYTE * b)
{
	trace("dllzz_adrs()\n"); pause(); return(0); 
}

WORD	dllzzpush(WORD a,WORD b,WORD c,WORD d,WORD e)
{
	trace("dllzzpush()\n"); pause(); return(0); 
}

WORD	dllzzpop()
{
	trace("dllzzpop()\n"); pause(); return(0); 
}

WORD	dllzzwmove(WORD a,WORD b)
{
	trace("dllzzwmove()\n"); pause(); return(0); 
}

WORD	dllzzshadow(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzzshadow()\n"); pause(); return(0); 
}	

WORD	dllzscroll(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzscroll()\n"); pause(); return(0); 
}

WORD	azac_init(WORD a)
{
	trace("azac_init()\n"); pause(); return(0); 
}

WORD	azac_open(WORD a,BYTE * b,WORD c)
{
	trace("azac_open()\n"); pause(); return(0); 
}

WORD	azac_nextline(WORD a,BYTE * b,WORD c/*?*/)
{
	trace("azac_nextline()\n"); pause(); return(0); 
}

WORD	azac_prevline(WORD a,BYTE * b,WORD c/*?*/)
{
	trace("azac_prevline()\n"); pause(); return(0); 
}

WORD	azac_firstline(WORD a,BYTE * b,WORD c/*?*/)
{
	trace("azac_firstline()\n"); pause(); return(0); 
}

WORD	azac_lastline(WORD a,BYTE * b,WORD c/*?*/)
{
	trace("azac_lastline()\n"); pause(); return(0); 
}

WORD	azac_close(WORD a)
{
	trace("azac_close()\n"); pause(); return(0); 
}

WORD	azac_create(WORD a,BYTE * b)
{
	trace("azac_create()\n"); pause(); return(0); 
}

WORD	azac_write(WORD a,BYTE * b,WORD c)
{
	trace("azac_write()\n"); pause(); return(0); 
}

WORD	dllzbprintvar(WORD a,WORD b,WORD c,BYTE * d)
{
	trace("dllzbprintvar()\n"); pause(); return(0); 
}

WORD	dllzbprintitem(WORD a,WORD b,WORD c,BYTE * d,BYTE * e,WORD f,WORD g)
{
	trace("dllzbprintitem()\n"); pause(); return(0); 
}

WORD	dllzprintran(WORD a,BYTE * b)
{
	trace("dllzprintran()\n"); pause(); return(0); 
}

WORD	dllztab_2_seq(WORD a,WORD b,BYTE * c,BYTE * d,BYTE * e,WORD f,WORD g,BYTE * h,BYTE * i,WORD j) 
{
	trace("dllztab_2_seq()\n"); pause(); return(0); 
}

WORD	dllzstring_cpt(BYTE * b,WORD c,BYTE * d)
{
	trace("dllzstring_cpt()\n"); pause(); return(0); 
}

WORD	dllzzfind(BYTE * b,BYTE * c,WORD d,WORD e)
{
	trace("dllzzfind()\n"); pause(); return(0); 
}

WORD	azac_read(WORD a,BYTE * b,WORD c)
{
	trace("azac_read()\n"); pause(); return(0); 
}

WORD	dllzindex(BYTE * b,BYTE c,WORD d,WORD e)
{
	trace("dllzindex()\n"); pause(); return(0); 
}

WORD	dllzoem2ansi(BYTE * b,WORD c)
{
	trace("dllzoem2ansi()\n"); pause(); return(0); 
}

WORD	dllzansi2oem(BYTE * b,WORD c)
{
	trace("dllzansi2oem()\n"); pause(); return(0); 
}

WORD	dllzzreserve15()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzzreserve16()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzzreserve17()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzzreserve18()
{
	trace("dllzzfunc()\n"); pause(); return(0); 
}

WORD	dllzwin_mesval(BYTE * b,WORD c)
{
	trace("dllzwin_mesval()\n"); pause(); return(0); 
}

WORD	dllzwin_messerr(BYTE * b,WORD c)
{
	trace("dllzwin_messerr()\n"); pause(); return(0); 
}

WORD	dllzwin_mesyesno(BYTE * b,WORD c,WORD d)
{
	trace("dllzwin_mesyesno()\n"); pause(); return(0); 
}

WORD	dllzwin_mesync(BYTE * b,WORD c)
{
	trace("dllzwin_mesync()\n"); pause(); return(0); 
}

WORD	dllzwin_button(WORD a,WORD b,WORD c,WORD d,WORD e,BYTE * f,WORD g,BYTE * h)
{
	trace("dllzwin_button()\n"); pause(); return(0); 
}

WORD	dllzwin_smallbutton(WORD a,WORD b,WORD c,WORD d,BYTE * e,WORD f,BYTE * g)
{
	trace("dllzwin_smallbutton()\n"); pause(); return(0); 
}

WORD	dllzwin_F1button(WORD a,WORD b,WORD c)
{
	trace("dllzwin_F1button()\n"); pause(); return(0); 
}

WORD	dllzwin_vlift(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzwin_vlist()\n"); pause(); return(0); 
}

WORD	dllzwin_lisf_lift(WORD a,WORD b,WORD c,WORD d,WORD e)
{
	trace("dllzwin_lisf_lift()\n"); pause(); return(0); 
}

WORD	dllzwin_frame(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f,WORD g,WORD h,BYTE * i)
{
	trace("dllzwin_frame()\n"); pause(); return(0); 
}

WORD	dllzwin_window(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f,WORD g,BYTE * h,WORD i)
{
	trace("dllzwin_window()\n"); pause(); return(0); 
}

WORD	dllzwin_font(WORD j)
{
	trace("dllzwin_font()\n"); pause(); return(0); 
}

WORD	dllzwin_check(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzwin_check()\n"); pause(); return(0); 
}

WORD	dllzwin_radio(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzwin_radio()\n"); pause(); return(0); 
}

WORD	dllzwin_statusxy(WORD a,WORD b)
{
	trace("dllzwin_statusxy()\n"); pause(); return(0); 
}

WORD	dllzwin_status_draw()
{
	trace("dllzwin_status_draw()\n"); pause(); return(0); 
}

WORD	dllzwin_status(BYTE * b,WORD c)
{
	trace("dllzwin_status()\n"); pause(); return(0); 
}

WORD	dllzwin_mousecursor(WORD a)
{
	trace("dllzwin_mousecursor()\n"); pause(); return(0); 
}

WORD	dllzwin_askcursor(WORD a)
{
	trace("dllzwin_askcursor()\n"); pause(); return(0); 
}

WORD	dllzwin_bbitmap(WORD a,BYTE * b,BYTE * c,WORD d)
{
	trace("dllzwin_bbitmap()\n"); pause(); return(0); 
}

WORD	dllzwin_bitmap(BYTE * b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzwin_bitmap()\n"); pause(); return(0); 
}

WORD	dllzwin_actual(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzwin_actual()\n"); pause(); return(0); 
}

WORD	dllzwdll_load(BYTE * b)
{
	trace("dllzwdll_load()\n"); pause(); return(0); 
}

WORD	dllzwdll_free()
{
	trace("dllzwdll_free()\n"); pause(); return(0); 
}

WORD	dllzwin_hlift(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzwin_hlift()\n"); pause(); return(0); 
}

WORD	dllzwin_alone(BYTE * b)
{
	trace("dllzwin_alone()\n"); pause(); return(0); 
}

WORD	dllzchdir(BYTE * b)
{
	trace("dllzchdir()\n"); pause(); return(0); 
}

WORD	dllzwbmp_load(WORD a,BYTE * b)
{
	trace("dllzwbmp_load()\n"); pause(); return(0); 
}

WORD	dllzwbmp_free(WORD a)
{
	trace("dllzwbmp_free()\n"); pause(); return(0); 
}

WORD	dllzwin_bbmp(WORD a,BYTE * b,WORD c,WORD d)
{
	trace("dllzwin_bbmp()\n"); pause(); return(0); 
}

WORD	dllzwin_bmp(WORD a,WORD b,WORD c,WORD d,WORD e)
{
	trace("dllzwin_bmp()\n"); pause(); return(0); 
}

WORD	dllzzwin_version()
{
	trace("dllzzwin_version()\n"); pause(); return(0); 
}

WORD	dllzzwin_clear(BYTE * b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzzwin_clear()\n"); pause(); return(0); 
}

WORD	dllzzprint_title(WORD a,WORD b,WORD c,BYTE * d)
{
	trace("dllzzprint_title()\n"); pause(); return(0); 
}

WORD	dllzzwinmove(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzzwinmove()\n"); pause(); return(0); 
}

WORD	dllzzwinmoveable(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzzwinmoveable()\n"); pause(); return(0); 
}

WORD	dllzwin_tabview(WORD a,WORD b,WORD c,WORD d,WORD e,BYTE * f,WORD g,BYTE * h)
{
	trace("dllzwin_tabview()\n"); pause(); return(0); 
}

WORD	dllzzgetmaxy(WORD a/*?*/,WORD b/*?*/)
{
	trace("dllzzgetmaxy()\n"); pause(); return(0); 
}

WORD	dllzzfont_choose(BYTE * b)
{
	trace("dllzzfont_choose()\n"); pause(); return(0); 
}

WORD	dllzzfont_create(WORD a,BYTE * b)
{
	trace("dllzzfont_create()\n"); pause(); return(0); 
}

WORD	dllzzfont_delete(WORD a)
{
	trace("dllzzfont_delete()\n"); pause(); return(0); 
}

WORD	dllzzwin_title(WORD a,WORD b,WORD c,BYTE * d,WORD e,WORD f,WORD g)
{
	trace("dllzzwin_title()\n"); pause(); return(0); 
}

WORD	dllzzprintl(WORD a,BYTE * b,WORD c)
{
	trace("dllzzprintl()\n"); pause(); return(0); 
}

WORD	dllzzw_getcolor(WORD a,WORD b)
{
	trace("dllzzw_getcolor(%u,%u)\n",a,b); pause(); return(0); 
}

WORD	dllzzw_color(WORD a,WORD b,WORD c)
{
	trace("dllzzw_color(%u,%u,%u)\n",a,b,c); pause(); return(0); 
}

WORD	dllzzw_brush(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzzw_brush(%u,%u,%u,%u)\n",a,b,c,d); pause(); return(0); 
}

WORD	dllzzw_pen(WORD a,WORD b,WORD c,WORD d,WORD e)
{
	trace("dllzzw_prn()\n"); pause(); return(0); 
}

WORD	dllzzw_point(WORD a,WORD b)
{
	trace("dllzzw_point(%u,%u)\n",a,b); pause(); return(0); 
}

WORD	dllzzw_line(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzzw_line(%u,%u,%u,%u)\n",a,b,c,d); pause(); return(0); 
}

WORD	dllzzw_rectangle(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzzw_rectangle(%u,%u,%u,%u)\n",a,b,c,d); pause(); return(0); 
}

WORD	dllzzw_roundrect(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f)
{
	trace("dllzzw_roundrect(%u,%u,%u,%u,%u,%u)\n",a,b,c,d,e,f); pause(); return(0); 
}

WORD	dllzzw_ellipse(WORD a,WORD b,WORD c,WORD d)
{
	trace("dllzzw_ellipse(%u,%u,%u,%u)\n",a,b,c,d); pause(); return(0); 
}

WORD	dllzzw_pie(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f,WORD g,WORD h)
{
	trace("dllzzw_pie(%u,%u,%u,%u,%u,%u,%u,%u)\n",a,b,c,d,e,f,g,h); pause(); return(0); 
}

WORD	dllzzw_trapez(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f,WORD g,WORD h)
{
	trace("dllzzw_trapez(%u,%u,%u,%u,%u,%u,%u,%u)\n",a,b,c,d,e,f,g,h); pause(); return(0); 
}

WORD	dllzzw_printxy(WORD a,WORD b,WORD c,BYTE * d)
{
	trace("dllzzw_printxy()\n"); pause(); return(0); 
}

WORD	dllzwin_xbmp(WORD a,WORD b,WORD c,WORD d,WORD e,WORD f,WORD g)
{
	trace("dllzzw_xbmp(%u,%u,%u,%u,%u,%u,%u)\n",a,b,c,d,e,f,g); pause(); return(0); 
}

WORD	dllzzwin_nbbits()
{
	trace("dllzzwin_nbbits()\n"); pause(); return(0); 
}


#endif	/* _z_c */


