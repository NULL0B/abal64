#ifndef	_singtool_c
#define _singtool_c

#include "singconf.h"

#define	_DATA_ICON 	"dataicon.gif\0            "
#define	_BOMB_ICON 	"bombicon.gif\0            "
#define	_ABAL_ICON 	"abalicon.gif\0            "
#define	_HTML_ICON 	"htmlicon.gif\0            "
#define	_C_ICON 	"cicon.gif\0               "
#define	_FORM_ICON 	"formtool.gif\0            "
#define	_FILE_ICON 	"fileicon.gif\0            "
#define	_MOVE_ICON 	"moveicon.gif\0            "
#define	_IMAGE_TOOL 	"imgtool.gif\0             "
#define	_IMAGE_ICON 	"imgicon.gif\0             "
#define	_TEXT_ICON 	"texticon.gif\0            "

#define	_PEN_ICON 	"penicon.gif\0            "
#define	_PIPE_ICON 	"pipicon.gif\0            "
#define	_POUR_ICON 	"pouricon.gif\0            "
#define	_TREE_ICON 	"treeicon.gif\0            "
#define	_TREE_TOOL 	"treetool.gif\0            "
#define	_PROJECT_ICON 	"projicon.gif\0            "
#define	_WIDGET_ICON 	"widgicon.gif\0            "
#define	_ROOT_ICON 	"rooticon.gif\0            "

#define	_LEFT_ICON 	"lefticon.gif\0            "
#define	_UP_ICON 	"upicon.gif\0            "
#define	_RIGHT_ICON 	"riteicon.gif\0            "
#define	_DOWN_ICON 	"downicon.gif\0            "
#define	_PLUS_ICON 	"plusicon.gif\0            "

#define	_EXADB_ICON	"vdbicon.gif\0             "
#define	_EXA_ICON	"exaicon.gif\0             "
#define	_OTR_ICON	"otricon.gif\0             "
#define	_OLD_ICON	"oldicon.gif\0             "
#define	_AED_ICON	"aedicon.gif\0             "

private	char *	TreeTool =(char *) 0;
private	char *	MoveTool =(char *) 0;
private	char *	FormTool =(char *) 0;
private	char *	DataIcon =(char *) 0;
private	char *	ImageTool=(char *) 0;
private	char *	ImageIcon=(char *) 0;
private	char *	TextIcon=(char *) 0;
private	char *	PenTool =(char *) 0;
private	char *	PipeTool =(char *) 0;
private	char *	PourTool =(char *) 0;
public 	char *	ProjectIcon =(char *) 0;
public 	char *	WidgetIcon =(char *) 0;
public 	char *	RootIcon =(char *) 0;
public 	char *	TreeIcon =(char *) 0;

public	char *	DownIcon=(char *) 0;
public	char *	UpIcon=(char *) 0;
public	char *	LeftIcon=(char *) 0;
public	char *	RightIcon=(char *) 0;
public	char *	PlusIcon=(char *) 0;

public	char *	ExadbIcon=(char *) 0;
public	char *	ExaIcon=(char *) 0;
public	char *	AedIcon=(char *) 0;
public	char *	OtrIcon=(char *) 0;
public	char *	OldIcon=(char *) 0;

private struct	tool_manager * ImageTools=(struct tool_manager*) 0;
private struct	tool_manager * HtmlTools=(struct tool_manager*) 0;
private struct	tool_manager * FontTools=(struct tool_manager*) 0;
private struct	tool_manager * FormTools=(struct tool_manager*) 0;
private struct	tool_manager * MenuTools=(struct tool_manager*) 0;
private struct	tool_manager * ModelTools=(struct tool_manager*) 0;
private struct	tool_manager * ClassTools=(struct tool_manager*) 0;
private	char 	IconWork[128];
private	int	icon_status=0;

private	struct	sprite_control	{
		int	height;		/* height and width of image 	*/
		int	width;
		int	x;		/* position when shown x and y 	*/
		int	y;
		int	w;		/* dimensions shown 		*/
		int	h;		/* and thus in buffer		*/
		char *	buffer;		/* copy of zone preshow 	*/
		} Sprite = { 0,0,0,0,0,0, (char *) 0 };

public	void	show_sprite( char * ibuffer, int atx, int aty )
{
	int	r;
	if (!( ibuffer ))
		return;
	if (!( Sprite.buffer )) {
		Sprite.height = (Context.fontheight*2);
		Sprite.width  = (Context.fontwidth*3);
		if (!( Sprite.buffer = allocate((Sprite.height*Sprite.width)+16) ))
			return;
		}
	Sprite.x = atx; Sprite.y = aty;
	if ((atx + Sprite.width) > hardcolumns())
		Sprite.w = (hardcolumns() - atx);
	else	Sprite.w = Sprite.width;
	if ((aty + Sprite.height) > hardrows())
		Sprite.h = (hardrows() - aty);
	else	Sprite.h = Sprite.height;
	if ((!( Sprite.h)) || (!( Sprite.w )))
		return;
	getzone( Sprite.x,Sprite.y,Sprite.w,Sprite.h, Sprite.buffer );
	for (r=0; r < Sprite.h; r++ ) {
		mixzone(Sprite.x,Sprite.y+r,Sprite.w,1,ibuffer);
		ibuffer += Sprite.width;
		}
	return;
}

public	void	show_form_sprite(int atx, int aty )
{
	show_sprite( FormTool,atx,aty );
}

public	void	show_tree_sprite(int atx, int aty )
{
	show_sprite( TreeTool,atx,aty );
}

public	void	show_widget_sprite(int atx, int aty )
{
	show_sprite( FormTool,atx,aty );
}


public	void	show_camera_sprite(int atx, int aty )
{
	show_sprite( FormTool,atx,aty );
}


public	void	hide_sprite()
{
	if ((!( Sprite.h)) || (!( Sprite.w )))
		return;
	if (!( Sprite.buffer ))
		return;
	putzone( Sprite.x,Sprite.y,Sprite.w,Sprite.h, Sprite.buffer );
	Sprite.w = Sprite.h = 0;
	return;
}

public char	*	compare(char * aptr, char * kptr )
{
	while (*aptr==' ') aptr++;
	while (*kptr==' ') kptr++;

	while (( *aptr != 0) && ( *kptr != 0 ))
		if ( *(aptr++) != *(kptr++))
			return((char *)0);

	while (*aptr==' ') aptr++;
	while (*kptr==' ') kptr++;

	if (!( *kptr ))
		return( aptr );
	else	return((char *) 0);
}

private	char *	load_icon( char * nptr, int bg )
{
	struct	standard_image * iptr;
	char		       * iconbuffer;
	char		       * rptr;
	int			 r;
	int	iconw,iconh;
	iconw = (Context.fontwidth*3);
	iconh = (Context.fontheight*2);

	if ((!( SingConf ))
 	||  (!( SingConf->iconpath )))
		strcpy(IconWork,nptr);
	else	sprintf(IconWork,"%s%s",SingConf->iconpath,nptr);

	nptr = IconWork;

	if (!( iptr = local_image_loader( nptr )))
		return( (char *) 0 );
	else if (!( iconbuffer = allocate( iconw * iconh ) ))
		return( iconbuffer );
	else	{
		for (	r = 0 ;
			r < iconh;
			r++   ) {
			/* prewipe it all */
			/* -------------- */
			memset((iconbuffer+(r*iconw)),bg, iconw );
			if (( r < iptr->rows )
			&&  ((rptr = connect_pixel_row( iptr->storage, r )) != (char *) 0)){
				memcpy((iconbuffer+(r*iconw)),rptr,(iptr->columns>iconw?iconw:iptr->columns));
				}
			}
		iptr = local_drop_image( iptr );
		return( iconbuffer );
		}
}

private	void	drop_icons()
{
	if( MoveTool  ) { MoveTool  = liberate( MoveTool  ); }
	if( FormTool  ) { FormTool  = liberate( FormTool  ); }
	if( TextIcon  ) { TextIcon  = liberate( TextIcon  ); }
	if( ImageIcon ) { ImageIcon = liberate( ImageIcon ); }
	if( ImageTool ) { ImageTool = liberate( ImageTool ); }
	if( PenTool   ) { PenTool   = liberate( PenTool   ); }
	if( PipeTool  ) { PipeTool  = liberate( PipeTool  ); }
	if( PourTool  ) { PourTool  = liberate( PourTool  ); }
	if( WidgetIcon  ) { WidgetIcon  = liberate( WidgetIcon  ); }
	if( ProjectIcon  ) { ProjectIcon  = liberate( ProjectIcon  ); }
	if( RootIcon  ) { RootIcon  = liberate( RootIcon  ); }
	if( TreeIcon  ) { TreeIcon  = liberate( TreeIcon  ); }
	if( TreeTool  ) { TreeTool  = liberate( TreeTool  ); }

	if ( DownIcon ) { DownIcon  = liberate( DownIcon  ); }
	if( UpIcon  ) { UpIcon  = liberate( UpIcon  ); }
	if( LeftIcon  ) { LeftIcon  = liberate( LeftIcon  ); }
	if( RightIcon  ) { RightIcon  = liberate( RightIcon  ); }
	if( PlusIcon  ) { PlusIcon  = liberate( PlusIcon  ); }

	if( ExadbIcon ) { ExadbIcon = liberate( ExadbIcon ); }
	if( ExaIcon ) { ExaIcon = liberate( ExaIcon ); }
	if( AedIcon ) { AedIcon = liberate( AedIcon ); }
	if( OtrIcon ) { OtrIcon = liberate( OtrIcon ); }
	if( OldIcon ) { OldIcon = liberate( OldIcon ); }

	icon_status = 0;
	return;
}

private	void	load_icons()
{
	int	bg = _DEFAULT_GUI_NEUTRAL;
#ifdef	UNIX
	set_transparence(1);
#endif
	if (!( icon_status & 2 )) {
		ImageTool= load_icon(_IMAGE_TOOL,bg);
		ImageIcon= load_icon(_IMAGE_ICON,bg);
		TextIcon = load_icon(_TEXT_ICON,bg);
		icon_status |= 2;
		}
	if (!( icon_status & 4 ))
		if ((MoveTool = load_icon(_MOVE_ICON, bg)) != (char*) 0)
			icon_status |= 4;
	if (!( icon_status & 8 ))
		if ((FormTool = load_icon(_FORM_ICON ,bg)) != (char*) 0)
			icon_status |= 8;
	if (!( icon_status & 16))
		if ((PenTool = load_icon(_PEN_ICON ,bg)) != (char*) 0)
			icon_status |= 16;
	if (!( icon_status & 32))
		if ((PipeTool = load_icon(_PIPE_ICON ,bg)) != (char*) 0)
			icon_status |= 32;
	if (!( icon_status & 64))
		if ((PourTool = load_icon(_POUR_ICON ,bg)) != (char*) 0)
			icon_status |= 64;
	if (!( icon_status &256))
		if ((ProjectIcon = load_icon(_PROJECT_ICON ,bg)) != (char*) 0)
			icon_status |=256;
	if (!( icon_status &0x00200))
		if ((WidgetIcon = load_icon(_WIDGET_ICON ,bg)) != (char*) 0)
			icon_status |=0x00200;

	if (!( icon_status &0x00400)) {
		if (((RootIcon = load_icon(_ROOT_ICON ,bg)) != (char*) 0)
		&&  ((TreeIcon = load_icon(_TREE_ICON ,bg)) != (char*) 0)
		&&  ((TreeTool = load_icon(_TREE_TOOL ,0 )) != (char*) 0)
		&&  ((DataIcon = load_icon(_DATA_ICON ,bg)) != (char*) 0))
			icon_status |=0x00400;
		}

	if (!( icon_status &0x1000)) {
		if (((DownIcon  = load_icon(_DOWN_ICON  ,0)) != (char*) 0)
		&&  ((UpIcon    = load_icon(_UP_ICON    ,0)) != (char*) 0)
		&&  ((LeftIcon  = load_icon(_LEFT_ICON  ,0)) != (char*) 0)
		&&  ((RightIcon = load_icon(_RIGHT_ICON ,0)) != (char*) 0)
		&&  ((PlusIcon  = load_icon(_PLUS_ICON  ,0)) != (char*) 0))
			icon_status |=0x1000;
		}
	if (!( ExadbIcon   )) ExadbIcon = load_icon( _EXADB_ICON, 0 );
	if (!( ExaIcon   )) ExaIcon = load_icon( _EXA_ICON, 0 );
	if (!( AedIcon   )) AedIcon = load_icon( _AED_ICON, 0 );
	if (!( OtrIcon   )) OtrIcon = load_icon( _OTR_ICON, 0 );
	if (!( OldIcon   )) OldIcon = load_icon( _OLD_ICON, 0 );

#ifdef	UNIX
	set_transparence(0);
#endif
	return;
}

public	char *	GetToolBarSwitch()
{
	if ( Context.ToolBar.align )
		return( "downicon.gif" );
	else	return( "upicon.gif" );
}

private	void	draw_button_tool(int position, char * message, int mode )
{
	int	b;
	int	x;
	int	y;
	if (( Context.Tool.h > 0 ) && ( Context.Tool.w > 0)  && (!( Context.ToolBar.align))) {
		hide();
		x = (Context.ToolBar.x+Context.Tool.x);
		y = (Context.ToolBar.y+
			(position *(Context.Tool.h+(Context.Tool.y/2)))
			+(Context.fontheight*3));
		if ( Context.ToolManager ) {
			Context.ToolManager->manager->toolmap[(position & _TOOL_MASK)] = 1;
			b = Context.ToolManager->manager->font;
			}
		else	b = Context.basefont;		
		visual_button(x,y,Context.Tool.w*2,Context.Tool.h,b,0,0,
			message,strlen(message),mode);
		show(x,y,Context.Tool.w*2,Context.Tool.h);
		}
	return;


}

public	void	SingDrawIcon( int atx, int aty, char * buffer, int style )
{
	visual_frame(atx,aty,Context.fontheight+2,Context.fontheight+2,style);
	mixzone8(atx+1,aty+1,Context.Tool.w,Context.fontheight,buffer);
	return;
}

public	void	show_data_icon( int x, int y )
{
	if (DataIcon)
		putzone8(x,y,Context.Tool.w,Context.Tool.h,DataIcon);
	else	filzone(x,y,Context.Tool.w,Context.Tool.h,8);
	return;
}

private	void	draw_icon_tool(int position, int type, char * tptr )
{
	int	y;
	int	x;
	if (( Context.Tool.h > 0 ) && ( Context.Tool.w > 0) && (!( Context.ToolBar.align))) {
		hide();
		if ( position == -1 ) {
			x = ((Context.ToolBar.w - Context.Tool.w)/2);	
			x += Context.ToolBar.x;
			y = (Context.ToolBar.h - ((Context.Tool.h*3)/2));
			y += Context.ToolBar.y;
			visual_frame(x-1,y-1,Context.Tool.w+2,Context.Tool.h+2,1);
			}
		else	{
			x = (Context.ToolBar.x+Context.Tool.x);
			x += ((position & 1) * Context.Tool.w);
			x += (position&1);
			y = (Context.ToolBar.y+
				((position/2) *(Context.Tool.h+(Context.Tool.y/2)))
				+(Context.fontheight*3));
			}
		filzone(x,y,Context.Tool.w+1,Context.Tool.h+1,_DEFAULT_GUI_NEUTRAL);
		if ( position != -1 ) {
			if ( Context.ToolManager )
				Context.ToolManager->manager->toolmap[(position & _TOOL_MASK)] = (type+1);
			}
		switch ( type ) {
			case	_OUTLINE_FRAME :
				relief(	x,y,
					Context.Tool.w,Context.Tool.h,Context.foreground,transparent,Context.foreground);
				break;
			case	_FILL_FRAME :
			if (( Context.Tool.h > 0 ) && ( Context.Tool.w > 0))
				filzone(x,y,
					Context.Tool.w,Context.Tool.h,Context.foreground);
				break;
			case	_TEXT_FRAME :
				visual_text(	x,y,Context.Tool.w,Context.Tool.h,
					Context.tinyfont,
					Context.foreground,
					Context.background,
					"abcdefghijklmnopqrstuvwxyz",26,_A_NONE );
				break;
			case	_MOVE_FRAME :
				if (MoveTool)
					mixzone8(x,y,Context.Tool.w,Context.Tool.h,MoveTool);
				else	filzone(x,y,Context.Tool.w,Context.Tool.h,3);
				break;
			case	_FORM_FRAME :
				if (FormTool)
					putzone8(x,y,Context.Tool.w,Context.Tool.h,FormTool);
				else	filzone(x,y,Context.Tool.w,Context.Tool.h,8);
				break;
			case	_DATA_FRAME :
				show_data_icon(x,y);
				break;
			case	_PEN_FRAME :
				if (PenTool)
					mixzone8(x,y,Context.Tool.w,Context.Tool.h,PenTool);
				else	filzone(x,y,Context.Tool.w,Context.Tool.h,8);
				break;
			case	_PIPE_FRAME :
				if (PipeTool)
					mixzone8(x,y,Context.Tool.w,Context.Tool.h,PipeTool);
				else	filzone(x,y,Context.Tool.w,Context.Tool.h,8);
				break;
			case	_POUR_FRAME :
				if (PourTool)
					mixzone8(x,y,Context.Tool.w,Context.Tool.h,PourTool);
				else	filzone(x,y,Context.Tool.w,Context.Tool.h,8);
				break;
			case	_LINE_FRAME :
				drawline(x,y,x+Context.Tool.w,y+(Context.Tool.h-1),1,Context.foreground,filzone);
				drawline(x,y+1,x+Context.Tool.w,y+Context.Tool.h,1,Context.background,filzone);
				break;
			case	_IMAGE_FRAME :
				if ( ImageTool )
					putzone(x,y,Context.Tool.w,Context.Tool.h,ImageTool);
				else	filzone(x,y,Context.Tool.w,Context.Tool.h,4);

				break;

			case	_SWITCH_FRAME :
				visual_switch(x+2,y+2,Context.Tool.w-4,Context.Tool.h-4,
					Context.basefont,Context.foreground,Context.background,"X",1,1);
				break;
			case	_GRAPH_FRAME :
				visual_graph(x+2,y+2,Context.Tool.w-4,Context.Tool.h-4,
					Context.basefont,Context.foreground,Context.background,"visualswitch",12,0);
				break;
			case	_CIRCLE_FRAME :
				visual_circle( x,y,Context.Tool.w,Context.Tool.w,Context.foreground,0);
				break;

			case	_DISC_FRAME :
				visual_circle( x,y,Context.Tool.w,Context.Tool.w,Context.foreground,1);
				break;

			case	_BUTTON_FRAME :
				visual_button(x,y,Context.Tool.w,Context.Tool.h,Context.tinyfont,0,0,tptr,(strlen(tptr)>2?2:strlen(tptr)),0);
				break;

			case	_TAB_FRAME :
				visual_tabpage(x,y,Context.Tool.w,Context.Tool.h,Context.tinyfont,"sing",4,0,2);
				break;

			case	_WINDOW_FRAME :
				visual_window(x,y,Context.Tool.w,Context.Tool.h,Context.tinyfont,"sing",4,3);
				break;

			default			:
				visual_frame(	x,y,Context.Tool.w,Context.Tool.h,type);
			}
		show(x,y,Context.Tool.w,Context.Tool.h);
		}
	return;
}

private	void	show_icon_tool()
{
	if (( Context.ToolBar.style ) 
	&&  ( Context.usingtool     )
	&&  ( Context.ToolManager   )
	&&  ( Context.ToolManager->manager->state & 1 )) 
		draw_icon_tool(-1,Context.style," ");
	return;
}

private	void	show_button_tool()
{
	int	i;
	char *	sptr;

	if (!( Context.ToolManager ))
		return;
	else 	{
		i = Context.ToolManager->manager->current;
		if (!( sptr = Context.ToolManager->manager->toolmsg[i] ))
			return;
		else	{
			draw_button_tool(i,sptr,2);
			return;
			}
		}
}

public	int	use_icon_tool(int y)
{
	if ( y <= _MOVE_FRAME ) {
								
		if (!( Context.ToolManager ))
			return(256);
		else if (!( y = Context.ToolManager->manager->toolmap[(y & _TOOL_MASK)] ))
			return( 256 );
		else	y--;

		if (y == _CUT_FRAME )
			Context.Image.state = 1;
		else	Context.Image.state = 0;

		Context.style = y;
		Context.usingtool = (Context.style+1);
		show_icon_tool();

		}
	return(256);
}

private	int	use_button_tool(int y)
{
	if ( y <= _MOVE_FRAME ) {
								
		if (( Context.ToolManager )
		&&  (!( Context.ToolManager->manager->toolmap[(y & _TOOL_MASK)] )))
			return( 256 );
		Context.style = y;
		Context.usingtool = (Context.style+1);
		show_button_tool();

		}
	return(256);
}

private	int	is_button_tool_event(int x, int y)
{
	int	t;
	int	b;
	switch ((t = visual_event(1))) {
		case	_MIMO_UP	:
		case	_MIMO_CLICK	:
			y -= Context.ToolBar.y;
			y -= (Context.fontheight*3);
			y /= ((Context.Tool.y/2) + Context.Tool.h);
			use_button_tool( y );
		default			:
			return(256);
		}
	return(-1);
}

private	int	is_tool_icon_event(int x, int y)
{
	int	t;
	int	b;
	switch ((t = visual_event(1))) {
		case	_MIMO_UP	:
		case	_MIMO_CLICK	:
			x -= Context.ToolBar.x;
			x -= (Context.fontwidth/2);
			x /= Context.Tool.w;
			y -= Context.ToolBar.y;
			y -= (Context.fontheight*3);
			y /= ((Context.Tool.y/2) + Context.Tool.h);
			y *= 2;
			y += x;
			use_icon_tool( y );
		default			:
			return(256);
		}
	return(-1);
}

public 	void	activate_ToolBar(int mode)	
{
	if ((Context.ToolBar.style = mode)!=0) {
		Context.Tool.x = (Context.fontwidth/2);
		Context.Tool.y = Context.fontheight;
		Context.Tool.w = (Context.fontwidth*3);
		Context.Tool.h = (Context.fontheight*2);
		Context.Tool.style=_GROOVE_FRAME;
		Context.ToolBar.align = 0;
		Context.ToolBar.x = 1;
		Context.ToolBar.y = 1;
		Context.ToolBar.w = (((Context.Tool.w*2)+Context.fontwidth));
		Context.ToolBar.h = (Context.height-2);
		}
	else	{
		Context.Tool.style=
		Context.ToolBar.align = 
		Context.ToolBar.x = Context.ToolBar.y = 
		Context.ToolBar.w = Context.ToolBar.h = 
		Context.Tool.x 	  = Context.Tool.y    = 
		Context.Tool.w    = Context.Tool.h    = 0;
		}
	return; 
}

private	void	show_button_tools()
{
	int	i;
	char *	sptr;
	if ( Context.ToolManager ) {
		for (i=0; i < _MAX_TOOLS; i++ ) {
			if (!(sptr = Context.ToolManager->manager->toolmsg[i] ))
				continue;
			else	draw_button_tool(i,sptr,0);
			}
		}
	return;
}

public	int	toolbar_is_active()
{
	if (!( Context.ToolBar.align ))
		return(1);
	else	return(0);
}

public	void	draw_ToolBar()	
{ 
	if ( Context.ToolBar.style ) {
		if ( Context.ToolBar.align ) {
			hide();
			visual_frame(	Context.ToolBar.x,Context.ToolBar.y,Context.ToolBar.align+1,Context.MenuBar.h+1,_HMENU_FRAME );
			if ( DownIcon ) {
				SingDrawIcon(	
					Context.ToolBar.x+((Context.ToolBar.align/2)-((Context.fontheight+2)/2)),
					Context.ToolBar.y+4,
					DownIcon,_INSET_FRAME);
				}
			else	{
				visual_arrow(
					Context.ToolBar.x+4,Context.ToolBar.y+4,
					Context.ToolBar.align-8,Context.MenuBar.h-8,
					standard_black,_ARROW_DOWN);
				}
			show(	Context.ToolBar.x,Context.ToolBar.y,
				Context.ToolBar.align,Context.MenuBar.h+1 );
			}
		else	{
			hide();

			visual_frame(	Context.ToolBar.x,Context.ToolBar.y,Context.ToolBar.w+1,Context.MenuBar.h+1,_HMENU_FRAME );
			if ( UpIcon ) {
				SingDrawIcon(	
					Context.ToolBar.x+((Context.ToolBar.w/2)-((Context.fontheight+2)/2)),
					Context.ToolBar.y+4,
					UpIcon,_INSET_FRAME);
				}
			else	{
				visual_arrow(
					Context.ToolBar.x+4,Context.ToolBar.y+4,
					Context.ToolBar.w-8,Context.MenuBar.h-8,
					standard_black,_ARROW_UP);
				}
			visual_frame(	Context.ToolBar.x,Context.ToolBar.y+Context.MenuBar.h,
				Context.ToolBar.w+1,Context.ToolBar.h-Context.MenuBar.h,Context.ToolBar.style);

			if (( Context.ToolManager )
			&&  ( Context.ToolManager->manager->state  & 2 ))
				(Context.ToolManager->manager->on_show)();


			show(	Context.ToolBar.x,Context.ToolBar.y,
				Context.ToolBar.w,Context.ToolBar.h );
			}
		}
	return;
}

public	void swap_ToolBar()
{
	if ( Context.ToolBar.style )
		activate_ToolBar(0);
	else	activate_ToolBar(_OUTSET_FRAME);
	activate_MenuBar( Context.MenuBar.style );
	activate_StatusBar( Context.StatusBar.style );
	activate_DeskTop(_OUTSET_FRAME);
	draw_console();
	return;
}

public	int	toggle_toolbar_display()
{
	int	style;
	if (!( Context.ToolBar.align )) {
		Context.ToolBar.align = Context.ToolBar.w;
		Context.ToolBar.w = 0;					
		}
	else	{
		Context.ToolBar.w = Context.ToolBar.align;
		Context.ToolBar.align = 0;
		}
	activate_StatusBar(_OUTSET_FRAME );
	if ((style = Context.TreeView.style) !=0) {
		Context.TreeView.style;
		reactivate_TreeView(style);
		}
	reactivate_DeskTop(_OUTSET_FRAME );
	resize_console();
	return(0);
}

public	void	show_DeskTop_ToolBar()
{
	if (!( Context.ToolBar.style ))
		toggle_toolbar_display();
	return;
}

public	void	hide_DeskTop_ToolBar()
{
	if ( Context.ToolBar.style )
		toggle_toolbar_display();
	return;
}

public	int	is_ToolBarEvent(int x, int y )
{
	int	style=0;

	/* Is it a click on a tool bar */
	/* --------------------------- */
	if ( Context.ToolBar.style != 0 ) {

		if (( x > Context.ToolBar.w    )
		&&  ( x > Context.ToolBar.align)) 
			return(-1);
		if ((!( Context.ToolBar.w ))
		&&  ( y > Context.MenuBar.h ))
			return(-1);

		/* Special Case for Model Scroll Bar */
		/* --------------------------------- */
		if (( y > (Context.fontheight*3)) 
		&&  (!( Context.ToolBar.align )) 
		&&  ( Context.ToolManager    )
		&&  ( Context.ToolManager->manager->state & 4 ))
			return( (Context.ToolManager->manager->on_event)(x,y) );

		switch ( visual_event(1)) {
			case	_MIMO_UP	:
			case	_MIMO_CLICK	:

				if ((!( Context.ToolManager 	   	    ))
				||  (!( Context.ToolManager->manager->state ))) 
					return(256);
				else if ( y > (Context.fontheight*3)) {
					if (!( Context.ToolBar.align )) {
						return( (Context.ToolManager->manager->on_event)(x,y) );
						}
					}
				else	{
					toggle_toolbar_display();
					}
			default	:
				return(256);
			}
		}
	else	return(-1);
}

struct	tool_manager *	allocate_tool_manager()
{
	int	i;
	struct tool_manager * tptr;

	if (!( tptr = (struct tool_manager *) allocate( sizeof( struct tool_manager ) ) ))
		return(tptr);

	for (i=0; i < _MAX_TOOLS; i++ ) {
		tptr->toolmap[i] = 0;
		tptr->toolmsg[i] = (char *) 0;
		}

	tptr->state  =
	tptr->current=0;
	tptr->on_show=0;
	tptr->on_event=0;
	if (!(tptr->font   = Context.basefont))
		tptr->font=1;
	return(tptr);
}


/*	TOOL NODES	*/
/*	----------	*/
public	void	drop_tool_manager()
{
	struct tool_node * tptr;
	if (!(tptr = Context.ToolManager))
		return;

	Context.ToolManager->manager->current = Context.style;

	Context.ToolManager = tptr->previous;
	tptr = liberate( tptr );
	draw_ToolBar();
	return;

}

private	void	use_tool_manager(struct tool_manager * mptr)
{
	struct tool_node * tptr;
	if (!( tptr = allocate( sizeof( struct tool_node ) ) ))
		return;
	tptr->manager  = mptr;
	tptr->previous = Context.ToolManager;
	Context.ToolManager = tptr;
	return;
}

/*	-----------	*/
/*	IMAGE TOOLS	*/
/*	-----------	*/
private	void	liberate_image_tools()
{
	if ( ImageTools )
		ImageTools = liberate( ImageTools );
	return;
}


private	void	show_image_colours(int fgposition,int bgposition)
{
	int	x;
	int	y;
	int	redfraction;
	int	greenfraction;
	int	bluefraction;
	int	redvalue;
	int	greenvalue;
	int	bluevalue;
	char	message[32];
	int	mlen;
	if (( Context.Tool.h > 0 ) && ( Context.Tool.w > 0) && (!( Context.ToolBar.align))) {
		redfraction=bluefraction=greenfraction=Context.Tool.w;
		x = (Context.ToolBar.x+Context.Tool.x);
		x += ((fgposition & 1) * Context.Tool.w);
		y = (Context.ToolBar.y+
			((fgposition/2) *(Context.Tool.h+(Context.Tool.y/2)))
			+(Context.fontheight*3));
		sprintf(message,"%u",Context.foreground);
		mlen = strlen( message );
		visual_frame(x-1,y-1,(Context.Tool.w*2)+2,((Context.Tool.h/3)*3)+2,_INSET_FRAME);
		filzone(x,y,Context.Tool.w,((Context.Tool.h/3)*3),Context.foreground);
		visual_text(x,y,Context.Tool.w,((Context.Tool.h/3)*3),Context.menufont,Context.background,0,message,mlen,3);

		get_rgb_values(Context.foreground,&redvalue,&greenvalue,&bluevalue);
		redfraction = ((redvalue*Context.Tool.w)/255);
		greenfraction = ((greenvalue*Context.Tool.w)/255);
		bluefraction = ((bluevalue*Context.Tool.w)/255);

		sprintf(message,"%02.2x",redvalue);
		mlen = strlen( message );
		filzone(x+Context.Tool.w,y,redfraction,Context.Tool.h/3,4);
		visual_text(x+Context.Tool.w,y,Context.Tool.w,Context.Tool.h/3,Context.tinyfont,15,0,message,mlen,3);

		sprintf(message,"%02.2x",greenvalue);
		mlen = strlen( message );
		filzone(x+Context.Tool.w,y+(Context.Tool.h/3),greenfraction,Context.Tool.h/3,2);
		visual_text(x+Context.Tool.w,y+(Context.Tool.h/3),Context.Tool.w,Context.Tool.h/3,Context.tinyfont,15,0,message,mlen,3);

		sprintf(message,"%02.2x",bluevalue);
		mlen = strlen( message );
		filzone(x+Context.Tool.w,y+((Context.Tool.h/3)*2),bluefraction,Context.Tool.h/3,1);
		visual_text(x+Context.Tool.w,y+((Context.Tool.h/3)*2),Context.Tool.w,Context.Tool.h/3,Context.tinyfont,15,0,message,mlen,3);


		x = (Context.ToolBar.x+Context.Tool.x);
		x += ((bgposition & 1) * Context.Tool.w);
		y = (Context.ToolBar.y+
			((bgposition/2) *(Context.Tool.h+(Context.Tool.y/2)))
			+(Context.fontheight*3));
		sprintf(message,"%u",Context.background);
		mlen = strlen( message );
		visual_frame(x-1,y-1,(Context.Tool.w*2)+2,((Context.Tool.h/3)*3)+2,_INSET_FRAME);
		filzone(x,y,Context.Tool.w,((Context.Tool.h/3)*3),Context.background);
		visual_text(x,y,Context.Tool.w,((Context.Tool.h/3)*3),Context.menufont,Context.foreground,0,message,mlen,3);

		get_rgb_values(Context.background,&redvalue,&greenvalue,&bluevalue);
		redfraction = ((redvalue*Context.Tool.w)/255);
		greenfraction = ((greenvalue*Context.Tool.w)/255);
		bluefraction = ((bluevalue*Context.Tool.w)/255);

		sprintf(message,"%02.2x",redvalue);
		mlen = strlen( message );
		filzone(x+Context.Tool.w,y,redfraction,Context.Tool.h/3,4);
		visual_text(x+Context.Tool.w,y,Context.Tool.w,Context.Tool.h/3,Context.tinyfont,15,0,message,mlen,3);

		sprintf(message,"%02.2x",greenvalue);
		mlen = strlen( message );
		filzone(x+Context.Tool.w,y+(Context.Tool.h/3),greenfraction,Context.Tool.h/3,2);
		visual_text(x+Context.Tool.w,y+(Context.Tool.h/3),Context.Tool.w,Context.Tool.h/3,Context.tinyfont,15,0,message,mlen,3);

		sprintf(message,"%02.2x",bluevalue);
		mlen = strlen( message );
		filzone(x+Context.Tool.w,y+((Context.Tool.h/3)*2),bluefraction,Context.Tool.h/3,1);
		visual_text(x+Context.Tool.w,y+((Context.Tool.h/3)*2),Context.Tool.w,Context.Tool.h/3,Context.tinyfont,15,0,message,mlen,3);

		}
}

private	void	show_image_tools()
{
	int	i;

	draw_icon_tool(0,_FILL_FRAME," ");		draw_icon_tool(1,_OUTLINE_FRAME," ");
	draw_icon_tool(2,_OUTSET_FRAME," ");		draw_icon_tool(3,_INSET_FRAME," ");
	draw_icon_tool(4,_RIDGE_FRAME," ");		draw_icon_tool(5,_GROOVE_FRAME," ");
	draw_icon_tool(6,_PEN_FRAME ," ");		draw_icon_tool(7,_PIPE_FRAME ," ");
	draw_icon_tool(8,_LINE_FRAME ," ");		draw_icon_tool(9,_POUR_FRAME ," ");
	draw_icon_tool(10, _CIRCLE_FRAME ," ");		draw_icon_tool(11, _DISC_FRAME ," ");
	draw_icon_tool(12,_CUT_FRAME," ");		draw_icon_tool(13,_MOVE_FRAME," ");
	show_image_colours(16,18);
	return;
}

private	int	is_image_tool_event(int x, int y)
{
	return( is_tool_icon_event( x, y ) );
}

private	void	allocate_image_tools()
{
	if (!( ImageTools = allocate_tool_manager() ))
		return;

	ImageTools->on_show  = show_image_tools;
	ImageTools->on_event = is_image_tool_event;
	ImageTools->state    = 3;
	return;
}

public	void	use_image_tools()
{
	if ( ImageTools ) {
		use_tool_manager( ImageTools );
		use_icon_tool( ImageTools->current );
		}
	return;
}

/*	----------	*/
/*	FONT TOOLS	*/
/*	----------	*/
private	void	liberate_font_tools()
{
	if ( FontTools )
		FontTools = liberate( FontTools );
	return;
}

private	void	show_font_tools()
{
	int	i;
	draw_icon_tool(0,_BUTTON_FRAME,"1");
	draw_icon_tool(1,_BUTTON_FRAME,"2");
	draw_icon_tool(2,_BUTTON_FRAME,"3");
	draw_icon_tool(3,_BUTTON_FRAME,"4");
	draw_icon_tool(4,_BUTTON_FRAME,"5");
	draw_icon_tool(5,_BUTTON_FRAME,"6");
	draw_icon_tool(6,_BUTTON_FRAME,"7");
	draw_icon_tool(7,_BUTTON_FRAME,"8");
	draw_icon_tool(8,_BUTTON_FRAME,"9");
	for (i=0; i < 9; i++ )
		FontTools->toolmap[i] = (i+1);
	return;
}

private	int	is_font_tool_event(int x, int y)
{
	if ( is_tool_icon_event( x, y )  != 256 )
		return(-1);
	else 	{
		if (( Context.FontContext )) {
			Context.FontContext->font = (Context.style+1);
			font_window(Context.FontContext);
			}
		return(256);
		}
}

private	void	allocate_font_tools()
{
	int	i;
	if (!( FontTools = allocate_tool_manager() ))
		return;
	for (i=0; i < 9; i++ )
		FontTools->toolmap[i] = (i+1);
	FontTools->state    = 2;
	FontTools->on_show  = show_font_tools;
	FontTools->on_event = is_font_tool_event;
	return;
}

public	void	use_font_tools()
{
	if ( FontTools )
		use_tool_manager( FontTools );
	return;
}

/*	FORM TOOLS	*/
/*	----------	*/
private	void	liberate_form_tools()
{
	if ( FormTools )
		FormTools = liberate( FormTools );
	return;
}

private	void	show_form_tools()
{
	int	i;
	for ( i=0; i <= _MOVE_FRAME; i++ ) 
		draw_icon_tool(i,i,"OK");
	show_icon_tool();
	return;
}

private	int	is_form_tool_event(int x, int y)
{
	return( is_tool_icon_event(x,y) );
}

private	void	allocate_form_tools()
{
	if (!( FormTools = allocate_tool_manager() ))
		return;

	FormTools->on_show  = show_form_tools;
	FormTools->on_event = is_form_tool_event;
	FormTools->state    = 3;
	return;
}

public	void	use_form_tools()
{
	if ( FormTools ) {
		use_tool_manager( FormTools );
		use_icon_tool( FormTools->current );
		}
	return;
}

/*	MENU TOOLS	*/
/*	----------	*/
private	void	liberate_menu_tools()
{
	if ( MenuTools )
		MenuTools = liberate( MenuTools );
	return;
}

private	void	show_menu_tools()
{
	show_button_tools();
	return;
}

private	int	is_menu_tool_event(int x, int y)
{
	return( is_button_tool_event(x,y) );
}

private	void	allocate_menu_tools()
{
	if (!( MenuTools = allocate_tool_manager() ))
		return;

	MenuTools->on_show  = show_menu_tools;
	MenuTools->on_event = is_menu_tool_event;
	MenuTools->toolmsg[0] = "Menu";
	MenuTools->toolmsg[1] = "Option";
	MenuTools->toolmsg[2] = "Separator";
	MenuTools->state = 3;
	MenuTools->font  = Context.tinyfont;
	return;
}

public	void	use_menu_tools()
{
	if ( MenuTools ) {
		use_tool_manager( MenuTools );
		use_button_tool( MenuTools->current );
		}
	return;
}

/*	----------	*/
/*	HTML TOOLS	*/
/*	----------	*/
private	void	liberate_html_tools()
{
	if ( HtmlTools )
		HtmlTools = liberate( HtmlTools );
	return;
}

private	void	show_html_tools()
{
	int	i;
	for (	i=0; i < 18; i++ ) {
		draw_icon_tool(i,_BUTTON_FRAME,HtmlTools->toolmsg[i]);
		HtmlTools->toolmap[i] = (i+1);
		}
	return;
}

private	int	is_html_tool_event(int x, int y)
{
	if ( is_tool_icon_event( x, y )  != 256 )
		return(-1);
	else 	{
		html_operation(HtmlTools->toolmsg[Context.style]);
		return(256);
		}
}

private	void	allocate_html_tools()
{
	if (!( HtmlTools = allocate_tool_manager() ))
		return;

	HtmlTools->on_show  = show_html_tools;
	HtmlTools->on_event = is_html_tool_event;
	HtmlTools->font     = Context.tinyfont;
	HtmlTools->toolmsg[0] = "B";
	HtmlTools->toolmsg[1] = "U";
	HtmlTools->toolmsg[2] = "I";
	HtmlTools->toolmsg[3] = "BR";
	HtmlTools->toolmsg[4] = "P";
	HtmlTools->toolmsg[5] = "HR";
	HtmlTools->toolmsg[6] = "TABLE";
	HtmlTools->toolmsg[7] = "TR";
	HtmlTools->toolmsg[8] = "TH";
	HtmlTools->toolmsg[9] = "TD";
	HtmlTools->toolmsg[10] = "OL";
	HtmlTools->toolmsg[11] = "UL";
	HtmlTools->toolmsg[12] = "DL";
	HtmlTools->toolmsg[13] = "DT";
	HtmlTools->toolmsg[14] = "DD";
	HtmlTools->toolmsg[15] = "LI";
	HtmlTools->toolmsg[16] = "IMG";
	HtmlTools->toolmsg[17] = "A";
	HtmlTools->state    = 2;
	return;
}

public	void	use_html_tools()
{
	if ( HtmlTools ) {
		use_tool_manager( HtmlTools );
		draw_ToolBar();
		}
	return;
}

/*	-----------	*/
/*	CLASS TOOLS	*/
/*	-----------	*/
private	void	liberate_class_tools()
{
	if ( ClassTools )
		ClassTools = liberate( ClassTools );
	return;
}

private	void	show_class_tools()
{
	show_button_tools();
	return;
}

private	int	is_class_tool_event(int x, int y)
{
	return( is_button_tool_event(x,y) );
}

private	void	allocate_class_tools()
{
	if (!( ClassTools = allocate_tool_manager() ))
		return;

	ClassTools->on_show  = show_class_tools;
	ClassTools->on_event = is_class_tool_event;
	ClassTools->toolmsg[0] = "Constant";
	ClassTools->toolmsg[1] = "Data";
	ClassTools->toolmsg[2] = "Method";
	ClassTools->state = 3;
	ClassTools->font  = Context.tinyfont;
	return;
}

public	void	use_class_tools()
{
	if ( ClassTools ) {
		use_tool_manager( ClassTools );
		use_button_tool( ClassTools->current );
		}
	return;
}

/*	-----------	*/
/*	MODEL TOOLS	*/
/*	-----------	*/

private	void	old_show_model_tools()
{
	if (( Context.Tool.h > 0 ) && ( Context.Tool.w > 0)  && (!( Context.ToolBar.align))) {
		hide();
		switch ( Context.Scroll3d.plane ) {
			case	0	:
				if (!( Context.Scroll3d.value ))
					break;
				if ( Context.Scroll3d.value->x < 150 )
					Context.Scroll3d.value->x = 150;
				visual_scrollbar(
					Context.ToolBar.x+Context.fontwidth,
					Context.DeskTop.y+Context.fontheight,
					Context.ToolBar.w-(2*Context.fontwidth),
					Context.DeskTop.h-(3*Context.fontheight),
					2,standard_white,standard_black,
					Context.Scroll3d.value->x,
					Context.Scroll3d.limit,Context.Scroll3d.max,Context.Scroll3d.focus | 3);
				break;
			case	1	:
				if (!( Context.Scroll3d.value ))
					break;
				if ( Context.Scroll3d.value->y < 150 )
					Context.Scroll3d.value->y = 150;
				visual_scrollbar(
					Context.ToolBar.x+Context.fontwidth,
					Context.DeskTop.y+Context.fontheight,
					Context.ToolBar.w-(2*Context.fontwidth),
					Context.DeskTop.h-(3*Context.fontheight),
					2,standard_white,standard_black,
					Context.Scroll3d.value->y,
					Context.Scroll3d.limit,Context.Scroll3d.max,Context.Scroll3d.focus | 3);
				break;
			case	2	:
				if (!( Context.Scroll3d.value ))
					break;
				if ( Context.Scroll3d.value->z < 150 )
					Context.Scroll3d.value->z = 150;
				visual_scrollbar(
					Context.ToolBar.x+Context.fontwidth,
					Context.DeskTop.y+Context.fontheight,
					Context.ToolBar.w-(2*Context.fontwidth),
					Context.DeskTop.h-(3*Context.fontheight),
					2,standard_white,standard_black,
					Context.Scroll3d.value->z,
					Context.Scroll3d.limit,Context.Scroll3d.max,Context.Scroll3d.focus | 3);
				break;

			}
		visual_select(	Context.ToolBar.x+Context.fontwidth,
			(Context.StatusBar.y-(Context.fontheight*2)),
			(5*Context.fontwidth),(3*Context.fontheight),
			1,standard_black,standard_white,
			parse_selection("X|Y|Z",&Context.Scroll3d.plane),0);
		show(Context.ToolBar.x,Context.ToolBar.y,Context.ToolBar.w,Context.ToolBar.h );
		}
	return;
}

private	void	on_3dscroll_event(int focus)
{
	Context.Scroll3d.focus = focus;
	show_model_tools();
	draw_DeskTop();
}

private int on_ModelTools_Zaction() 
{
	int factor;
	int aty=visual_event(6);
	int toy=visual_event(6);
	factor = (Context.Scroll3d.max/Context.Scroll3d.limit);
	if ( visual_event(6) < 
			((Context.DeskTop.y+Context.fontheight)+
			(Context.ToolBar.w-(2*Context.fontwidth)))) {
		do { while(visual_getch() != 256); } while ( visual_event(1) != _MIMO_UP );
		Context.Scroll3d.value->z -= factor;
		if (Context.Scroll3d.value->z < 0) 
			Context.Scroll3d.value->z = 0;
		(void) on_3dscroll_event(0);
		return(-1);
		}
	if ( visual_event(6) > 
			((Context.DeskTop.y+Context.fontheight)+
			(Context.DeskTop.h-(3*Context.fontheight))-
			(Context.ToolBar.w-(2*Context.fontwidth)))) {
		do { while(visual_getch() != 256); } while ( visual_event(1) != _MIMO_UP );
		Context.Scroll3d.value->z += factor;
		if (Context.Scroll3d.value->z > (Context.Scroll3d.max-Context.Scroll3d.limit)) 
			Context.Scroll3d.value->z = (Context.Scroll3d.max-Context.Scroll3d.limit);
		on_3dscroll_event(0);
		return(-1);
		}
	(void) on_3dscroll_event(0x0100);
	do 	{
		while(visual_getch() != 256);
		if ((toy = visual_event(6)) > aty) {
			Context.Scroll3d.value->z += ((toy-aty)*factor);
			if (Context.Scroll3d.value->z > (Context.Scroll3d.max-Context.Scroll3d.limit)) 
				Context.Scroll3d.value->z = (Context.Scroll3d.max-Context.Scroll3d.limit);

			}
		else if (Context.Scroll3d.value->z > ((aty-toy)*factor))
			Context.Scroll3d.value->z -= ((aty-toy)*factor);
		else	Context.Scroll3d.value->z = 0;
		(void) on_3dscroll_event(0x0100);
		if (visual_event(2) == _MIMO_LEFT) aty = toy;
		}
	while (visual_event(1) != _MIMO_UP);
	(void) on_3dscroll_event(0);
	return(1);
}

private int on_ModelTools_Yaction() 
{
	int factor;
	int aty=visual_event(6);
	int toy=visual_event(6);
	factor = (Context.Scroll3d.max/Context.Scroll3d.limit);
	if ( visual_event(6) < 
			((Context.DeskTop.y+Context.fontheight)+
			(Context.ToolBar.w-(2*Context.fontwidth)))) {
		do { while(visual_getch() != 256); } while ( visual_event(1) != _MIMO_UP );
		Context.Scroll3d.value->y -= factor;
		if (Context.Scroll3d.value->y < 0) 
			Context.Scroll3d.value->y = 0;
		(void) on_3dscroll_event(0);
		return(-1);
		}
	if ( visual_event(6) > 
			((Context.DeskTop.y+Context.fontheight)+
			(Context.DeskTop.h-(3*Context.fontheight))-
			(Context.ToolBar.w-(2*Context.fontwidth)))) {
		do { while(visual_getch() != 256); } while ( visual_event(1) != _MIMO_UP );
		Context.Scroll3d.value->y += factor;
		if (Context.Scroll3d.value->y > (Context.Scroll3d.max-Context.Scroll3d.limit)) 
			Context.Scroll3d.value->y = (Context.Scroll3d.max-Context.Scroll3d.limit);
		on_3dscroll_event(0);
		return(-1);
		}
	(void) on_3dscroll_event(0x0100);
	do 	{
		while(visual_getch() != 256);
		if ((toy = visual_event(6)) > aty) {
			Context.Scroll3d.value->y += ((toy-aty)*factor);
			if (Context.Scroll3d.value->y > (Context.Scroll3d.max-Context.Scroll3d.limit)) 
				Context.Scroll3d.value->y = (Context.Scroll3d.max-Context.Scroll3d.limit);

			}
		else if (Context.Scroll3d.value->y > ((aty-toy)*factor))
			Context.Scroll3d.value->y -= ((aty-toy)*factor);
		else	Context.Scroll3d.value->y = 0;
		(void) on_3dscroll_event(0x0100);
		if (visual_event(2) == _MIMO_LEFT) aty = toy;
		}
	while (visual_event(1) != _MIMO_UP);
	(void) on_3dscroll_event(0);
	return(1);
}

private int on_ModelTools_Xaction() 
{
	int factor;
	int aty=visual_event(6);
	int toy=visual_event(6);
	factor = (Context.Scroll3d.max/Context.Scroll3d.limit);
	if ( visual_event(6) < 
			((Context.DeskTop.y+Context.fontheight)+
			(Context.ToolBar.w-(2*Context.fontwidth)))) {
		do 	{ while(visual_getch() != 256); } while ( visual_event(1) != _MIMO_UP );
		Context.Scroll3d.value->x -= factor;
		if (Context.Scroll3d.value->x < 0) 
			Context.Scroll3d.value->x = 0;
		(void) on_3dscroll_event(0);
		return(-1);
		}
	if ( visual_event(6) > 
		((Context.DeskTop.y+Context.fontheight)+
		(Context.DeskTop.h-(3*Context.fontheight))-
		(Context.ToolBar.w-(2*Context.fontwidth)))) {
		do { while(visual_getch() != 256); } while ( visual_event(1) != _MIMO_UP );
		Context.Scroll3d.value->x += factor;
		if (Context.Scroll3d.value->x > (Context.Scroll3d.max-Context.Scroll3d.limit)) 
			Context.Scroll3d.value->x = (Context.Scroll3d.max-Context.Scroll3d.limit);
		on_3dscroll_event(0);
		return(-1);
		}
	(void) on_3dscroll_event(0x0100);
	do 	{
		while(visual_getch() != 256);
		if ((toy = visual_event(6)) > aty) {
			Context.Scroll3d.value->x += ((toy-aty)*factor);
			if (Context.Scroll3d.value->x > (Context.Scroll3d.max-Context.Scroll3d.limit)) 
				Context.Scroll3d.value->x = (Context.Scroll3d.max-Context.Scroll3d.limit);

			}
		else if (Context.Scroll3d.value->x > ((aty-toy)*factor))
			Context.Scroll3d.value->x -= ((aty-toy)*factor);
		else	Context.Scroll3d.value->x = 0;
		(void) on_3dscroll_event(0x0100);
		if (visual_event(2) == _MIMO_LEFT) aty = toy;
		}
	while (visual_event(1) != _MIMO_UP);
	(void) on_3dscroll_event(0);
	return(1);
}

private int on_ModelTools_action() 
{
	int	event;
	switch ( visual_event(1) ) {
		case	_MIMO_DOWN 		:
		case	_MIMO_WHILE_DOWN	:	
		case	_MIMO_IS_DOWN		:	
			break;
		default				:
			return(0);
		}
	switch ( Context.Scroll3d.plane ) {
		case	0	:	
			return( on_ModelTools_Xaction() );
		case	1	:	
			return( on_ModelTools_Yaction() );
		case	2	:	
			return( on_ModelTools_Zaction() );
		default		:
			return(0);
		}
}

private	int	old_is_model_tool_event(int x, int y)
{
	if ( visual_event(6) > 
		((Context.DeskTop.y+Context.fontheight)+
		(Context.DeskTop.h-(3*Context.fontheight)))) {
		visual_select(	Context.ToolBar.x+Context.fontwidth,
			(Context.StatusBar.y-(Context.fontheight*2)),
			(5*Context.fontwidth),(3*Context.fontheight),
			1,standard_black,standard_white,
			parse_selection("X|Y|Z",&Context.Scroll3d.plane),_VISUAL_FOCUS);

		return( 256 );
		}
	else if (!( on_ModelTools_action() ))
		return(-1);	
	else	return(256);
}

private	void	show_model_tools()
{
	visual_3d_cursor_show(Context.ThreedCursor);
	return;
}

private	void	liberate_model_tools()
{
	visual_3d_cursor_remove(Context.ThreedCursor);
	return;
}

private	int	is_model_tool_event()
{
	visual_3d_cursor_event(Context.ThreedCursor);
	return(256);
}

private	void	allocate_model_tools()
{
	if (!( ModelTools = allocate_tool_manager() ))
		return;

	ModelTools->on_show  = show_model_tools;
	ModelTools->on_event = is_model_tool_event;
	ModelTools->state = 6;
	ModelTools->font  = 2;
	visual_3d_cursor_create(&Context.ThreedCursor);
	return;
}

public	void	use_model_tools()
{
	if ( ModelTools ) {
		use_tool_manager( ModelTools );
		use_button_tool( ModelTools->current );
		}
	return;
}

/*	---------------		*/
/*	TOOL MANAGEMENT		*/
/*	---------------		*/
public	void	allocate_tool_managers()
{
	if (!( icon_status ))
		load_icons();

	allocate_image_tools();
	allocate_font_tools();
	allocate_form_tools();
	allocate_menu_tools();
	allocate_html_tools();
	allocate_class_tools();
	allocate_model_tools();
}

public	void	liberate_tool_managers()
{
	liberate_model_tools();
	liberate_class_tools();
	liberate_html_tools();
	liberate_menu_tools();
	liberate_form_tools();
	liberate_font_tools();
	liberate_image_tools();
	if ( icon_status )
		drop_icons();

}


#endif	/* _singtool_c */


