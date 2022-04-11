#ifndef	_winit_c
#define	_winit_c

/* -------------------- */
/* 0: %winit(#,#,#,#,#) */
/* -------------------- */
private	int	load_style(char * sptr)
{
	if (!( sptr ))
		return(0);
	else if ( load_visual_style( sptr, strlen( sptr ) ) != 0 )
		return(0);
	else	return(1);
}

public	int	winit(int a, int b, int c, int d, int e )
{
	char *	eptr;
	char *	fnptr;
	int	i;
	if (!( Control.status )) {
		initialise_style();
		eptr = get_system_fontpath();
		eptr = get_system_imagepath();
		eptr = get_system_stylepath();
		if (!( load_style( getenv("ASFUN_STYLE")) ))
			if (!( load_style("asfun.css") ))
				load_style( "/home/abal3/style/asfun.css");
		get_cons();
		if ((eptr = getenv("GRASFUN_DEBUG")) != (char *) 0)	
			bedug = *eptr - '0';
		else	bedug = 0;
		for ( i=0; i < _MAX_WINDOWS; i++ ) {
			Control.windows[i] = (struct asfun_window *) 0;
			}
		for ( i=0; i < _MAX_MENUS; i++ ) {
			Control.menus[i] = (struct asfun_menu *) 0;
			}
		for ( i=0; i < _MAX_LISTS; i++ ) {
			Control.lists[i] = (struct asfun_list *) 0;
			}
		for ( i=0; i < _MAX_WINDOWS; i++ ) {
			Control.dboxs[i] = (struct asfun_dbox *) 0;
			}
		memset(Control.Escape,0,33);
		memset(Control.statusmessage,' ',_MAX_STATUS_MSG);
		Control.mode = initialisepixel(3+512+256);
		load_palette( "/home/abal3/images/foret.rgb");
		fnptr = "/home/abal3/fonts/bmap1024.fmf";
		Control.basefont = visual_font(fnptr,strlen(fnptr));
		use_base_font(Control.basefont);
		Control.w = x_conf(69);
		Control.h = x_conf(68);
		cicowindow(0,0,Control.w,Control.h);
		Control.nbc = x_conf(2);
		Control.nbl = x_conf(1);
		Control.gfh = x_event(204);
		Control.gfw = x_event(205);
		Control.active = Control.implicite = 0;
		Control.status=1;
		Control.options = a;
		Control.filler  = b;
		Control.atb	= c;
		Control.fg	= d;
		Control.bg	= e;
		Control.statusline=x_conf(1);
		if (!( x_event(0) ));
		fen_ini = 1;
		show_windows();
		}
	return(0);
}

private EXAWORD Dll_winit( VOID FAR PTR FAR pptr[] )
{
	int	a=LdfParaWord(0);
	int	b=LdfParaWord(1);
	int	c=LdfParaWord(2);
	int	d=LdfParaWord(3);
	int	e=LdfParaWord(4);
	Control.statusbar=0;
	return( winit(a,b,c,d,e) );

}

#endif	/* _winit_c */
	/* -------- */

