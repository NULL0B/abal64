private	char * 	Flags[8] = { "en.gif", "fr.gif", "it.gif","es.gif","de.gif","nl.gif","pt.gif", "xx.gif" };

private	int	LanguageCode= 0;
private	int	SmallFontHandle=0;

public	int	visual_smallfont()
{
	if (!( SmallFontHandle )) {
		SmallFontHandle = visual_font("font8.fmf",strlen("font8.fmf"));
		}
	return( SmallFontHandle );
}

public	char *	visual_language_flag()
{
	return( Flags[LanguageCode] );
}

public	int	visual_national_language(int v)
{
	int	holder=LanguageCode;
	if (( v >= 0 )
	&&  ( v < 8  )) {
		LanguageCode = v;
		}
	return(holder);
}


static	int	freeze80=0;

public	void	freeze_control(int state)
{
	freeze80 = state;
	return;
}

public	void	visual_freeze()
{
	if ( freeze80 ) { x_event(80); }
	hide();
	return;
}

public	void	visual_thaw(int x,int y, int w, int h)
{
	show(x,y,w,h);
	if ( freeze80) { x_event(81); }
	return;
}

public	void	style_visual_freeze()
{
	visual_freeze();
	return;
}

public	void	style_visual_thaw(int x,int y, int w, int h)
{
	visual_thaw(x,y,w,h);
	return;
}

public	void	visual_window( int atx, int aty, int nbx, int nby, int f, char * mptr,int mlen, int o )
{
	int	fw;
	int	fh;
	int	sf;
	int	m;
	int	n;
	int	colourmaped = get_pixel_format();
	sf = visual_smallfont();
	if (!( f )) {
		if ((fh = (nby-8)) > 24)
			fh = 24;
		else if ( fh <= 0 )
			fh = 1;
		}
	else	{
		fh = guifontsize(f);
		fw = (fh & 0x00FF);
		fh >>= 8;
		fh &= 0x00FF;
		}
	if ((nbx > 0) && (nby > 0)) {
		if ( o & _A_SHADOW ) {
			if (!( colourmaped ))
				shadzone(atx+10,aty+10,nbx,nby,standard_black );
			else 	xfilzone(atx+10,aty+10,nbx,nby,standard_black );
			}
		relief(atx,aty,nbx,nby,standard_black,standard_backwash,standard_black);
		if ((nbx > 2) && (nby > 2)) {
			relief(atx+1,aty+1,nbx-2,nby-2,standard_himid,transparent,standard_lomid);
			if ((nbx > 4) && (nby > 4)) {
				relief(atx+2,aty+2,nbx-4,nby-4,standard_hilight,transparent,standard_lolight); 
				if ((nbx > 9) && ( fh > 0 ) && ((nby-8) > fh)) {
					relief(atx+3,aty+3,nbx-7,fh+2,standard_lolight,transparent,standard_hilight); 
					filzone(atx+4,aty+4,nbx-9,fh,standard_title);
					if (( f != 0 )
					&&  ( mptr != (char *) 0 )) {
						cicocolour(standard_text,0);
						PixelFontSat(atx+6,aty+5,f,mptr);
						}
					if ( o & _WINDOW_EXIT_BUTTON ) {
						visual_button(	(atx+nbx)-(fh+5),
							aty+4,fh,fh,sf,0,0,
							"X", 1, 0 );
						}
					if ( o & _WINDOW_HELP_BUTTON ) {
						visual_button((atx+nbx)-((fh*2)+6),
							aty+4,fh,fh,sf,0,0,
							"?", 1, 0 );
						}
					m=3; n = 10;
					if ( o & _WINDOW_LANG_BUTTON ) {
						visual_button((atx+nbx)-((fh*m)+(n+1)),
							aty+4,fh+4,fh,sf,0,0,
							"*", 1, 0 );
						visual_image(((atx+nbx)-((fh*(m++))+n)),(aty+3),fh+2,fh,
							Flags[LanguageCode],0);
						}
					if ( o & _WINDOW_MINIMIZE ) {
						visual_button((atx+nbx)-((fh*m)+(n+1)),
							aty+4,fh+4,fh,sf,0,0,
							"-", 1, 0 );
						visual_image(((atx+nbx)-((fh*(m++))+n)),(aty+3),fh+2,fh,
							"mini.gif",0);
						}
					if ( o & _WINDOW_MAXIMIZE) {
						visual_button((atx+nbx)-((fh*m)+(n+1)),
							aty+4,fh+4,fh,sf,0,0,
							"+", 1, 0 );
						visual_image(((atx+nbx)-((fh*(m++))+n)),(aty+3),fh+2,fh,
							"maxi.gif",0);
						}
					}
				}
			}
		}
	return;
}




