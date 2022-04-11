#ifndef	_singpal_c
#define	_singpal_c

extern	char *	DownIcon;
extern	char *	UpIcon;
public	int	get_background()
{
	return( Context.background );
}

public	int	get_foreground()
{
	return( Context.foreground );
}

public 	void	activate_Palette(int mode)	
{
	if ((Context.Palette.style = mode)!=0) {
		Context.Palette.align = 0;
		Context.Palette.w = (((Context.fontwidth*3)*2)+Context.fontwidth);
		Context.Palette.x = (((Context.width - Context.Palette.w)-2)+2);
		Context.Palette.y = 1;
		Context.Palette.h = (Context.height-2);
		}
	else	{
		Context.Palette.align = 
		Context.Palette.x = Context.Palette.y = 
		Context.Palette.w = Context.Palette.h = 0;
		}
	return; 
}

public	int	palette_is_active()
{
	if (!( Context.Palette.align ))
		return(1);
	else	return(0);
}

public	char *	GetPaletteSwitch()
{
	if ( Context.Palette.align )
		return( "downicon.gif" );
	else	return( "upicon.gif" );
}


private	void	draw_Palette()	
{ 
	int	i;
	int	w;
	int	h;
	if ( Context.Palette.style ) {
		if ( Context.Palette.align ) {
			if (!( new_menu_system() )) {
				hide();
				visual_frame(	Context.Palette.x,Context.Palette.y,Context.Palette.align,Context.MenuBar.h+1,_HMENU_FRAME );
				if ( DownIcon ) {
					SingDrawIcon(	
						Context.Palette.x+((Context.Palette.align/2)-((Context.fontheight+2)/2)),
						Context.Palette.y+4,
						DownIcon,_INSET_FRAME);
					}
				else	{
					visual_arrow(
						Context.Palette.x+4,Context.Palette.y+4,
						Context.Palette.align-8,Context.MenuBar.h-8,
						standard_black,_ARROW_DOWN);
					}
				show (	Context.Palette.x,Context.Palette.y,Context.Palette.align,Context.MenuBar.h+1);
				}
			}
		else	{
			hide();
			if (!( new_menu_system() )) {
				visual_frame(	Context.Palette.x,Context.Palette.y,Context.Palette.w,Context.MenuBar.h+1,_HMENU_FRAME );
				if ( UpIcon ) {
					SingDrawIcon(	
						Context.Palette.x+((Context.Palette.w/2)-((Context.fontheight+2)/2)),
						Context.Palette.y+4,
						UpIcon,_INSET_FRAME);
					}
				else	{
					visual_arrow(
						Context.Palette.x+4,Context.Palette.y+4,
						Context.Palette.w-8,Context.MenuBar.h-8,
						standard_black,_ARROW_UP);
					}
				}
			visual_frame(	Context.Palette.x,Context.Palette.y+Context.MenuBar.h,
				Context.Palette.w,Context.Palette.h-Context.MenuBar.h,Context.Palette.style);
			w = ((Context.Palette.w-Context.fontwidth)/4);
			h = ((Context.Palette.h-(Context.fontheight*4))/64);
			for ( i=0; i < 256; i++ )
				filzone( ((((i%4)*w)+Context.Palette.x)+(Context.fontwidth/2)),
					 ((((i/4)*h)+Context.Palette.y)+(Context.fontheight*3)),
					 w, h,i);

			show (	Context.Palette.x,Context.Palette.y,
				Context.Palette.w,Context.Palette.h );
			}
		}
	return;
}

public 	void swap_Palette()
{
	if ( Context.Palette.style )
		activate_Palette(0);
	else	activate_Palette(_OUTSET_FRAME);
	activate_MenuBar( Context.MenuBar.style );
	activate_StatusBar( Context.StatusBar.style );
	activate_DeskTop(_OUTSET_FRAME);
	draw_console();
	return;
}

public	int	toggle_palette_display()
{
	if (!( Context.Palette.align )) {
		Context.Palette.align = Context.Palette.w;
		Context.Palette.w = 0;					
		}
	else	{
		Context.Palette.w = Context.Palette.align;
		Context.Palette.align = 0;
		}
	activate_StatusBar(0);
	activate_StatusBar(_OUTSET_FRAME );
	activate_DeskTop(0);
	activate_DeskTop(_OUTSET_FRAME );
	resize_console();
	return(0);
}

public	void	show_DeskTop_Palette()
{
	if (!( Context.Palette.style ))
		toggle_palette_display();
	return;
}

public	void	hide_DeskTop_Palette()
{
	if ( Context.Palette.style )
		toggle_palette_display();
	return;
}


public	int	is_PaletteEvent(int x, int y )
{
	int	t;
	int	b;
	int	w,h;

	if (( Context.Palette.style != 0 )
	&&  ( x > Context.Palette.x      )) {
		if ((!( Context.Palette.w ))
		&&  ( y > Context.MenuBar.h ))
			return(-1);
		switch ((t = visual_event(1))) {
			case	_MIMO_UP	:
			case	_MIMO_CLICK	:
				if ( y > (Context.fontheight*3)) {
					if (!( Context.Palette.align )) {
						w = ((Context.Palette.w-Context.fontwidth)/4);
						h = ((Context.Palette.h-(Context.fontheight*4))/64);
						y -= (Context.fontheight*3);
						y /= h;
						x -= Context.Palette.x;
						x -= (Context.fontwidth/2);
						x /= w;
						if ( visual_event(2) == _MIMO_LEFT )
							use_foreground_colour( (((y*4)+x)&0x00FF));
						else	use_background_colour( (((y*4)+x)&0x00FF));
						draw_ToolBar();
						}
					}
				else	{
					toggle_palette_display();
					}
			default			:
				return(256);
			}
		}
	else	return(-1);
}

#endif	/* _singpal_c */
	/* ---------- */


