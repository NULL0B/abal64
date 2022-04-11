private	char buffer[132];

char	*	widget_event_message( struct form_item * wptr );

private	char * bar_message[8] = {
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0
	};

static	int	newbar=0;


public	void	activate_StatusBar(int mode)
{
	if (!( newbar )) {
		visual_status_bar_create(&Context.StatusObject);
		newbar=1;
		}
		
	if ((Context.StatusBar.style = mode)!=0) {
		Context.StatusBar.x = ((Context.ToolBar.x+Context.ToolBar.w)+1);
		Context.StatusBar.h = ((Context.fontheight*2)-2);
		Context.StatusBar.y = ((Context.height - Context.StatusBar.h)-1);
		Context.StatusBar.w = inner_width(2);
		}
	else	{
		Context.StatusBar.x = Context.StatusBar.y = 
		Context.StatusBar.w = Context.StatusBar.h = 0;
		}
	return; 
}

public	void swap_StatusBar()
{
	if ( Context.StatusBar.style )
		activate_StatusBar(0);
	else	activate_StatusBar(_OUTSET_FRAME);
	activate_DeskTop(_OUTSET_FRAME);
	draw_console();
	return;
}

/*
 *	There are Three status bar positions numbered from
 *	1 to 3
 *
 */

public 	void	show_status_bar_message(int position)
{
	int	boxwidth;
	int	texwidth;
	int	wipewidth;
	int	boxposit;
	char *	mptr;

	if ( Context.StatusBar.style != 0 ) {

		if (!( mptr = bar_message[position] ))
			return;

		hide();
		cicocolour(_DEFAULT_GUI_BLACK,_DEFAULT_GUI_WHITE);
		boxwidth = (((Context.StatusBar.w-Context.fontwidth)/3) - Context.fontwidth);
		texwidth = ((boxwidth-(Context.fontwidth*2))/Context.fontwidth);
		boxposit = ((boxwidth+Context.fontwidth)*(position-1));
		wipewidth = boxwidth;

		if ( Context.usage ) {
			filzone(
			(Context.StatusBar.x+boxposit)+Context.fontwidth,
			(Context.StatusBar.y+(Context.fontheight/2)),
			(wipewidth-(Context.fontwidth*2)),Context.fontheight,
				_DEFAULT_GUI_WHITE);
			Context.usage = 0;
			}
		Context.usage = 
			PixelFontLat(
			(Context.StatusBar.x+boxposit+ Context.fontwidth),
			(Context.StatusBar.y+(Context.fontheight/2)),
			Context.basefont,
			mptr, texwidth );
		show(
			(Context.StatusBar.x+boxposit)+Context.fontwidth,
			(Context.StatusBar.y+(Context.fontheight/2)),
			(wipewidth-(Context.fontwidth*2)),Context.fontheight
			);
		}
	return;	
}

public 	void	status_message(char * mptr,int position)
{
	if ( newbar ) 
		status_bar_message(Context.StatusObject, position, mptr );

	else if ( Context.StatusBar.style != 0 ) {
		if ( bar_message[position] != (char *) 0 )
			liberate(bar_message[position]);
		if (!(bar_message[position] = allocate_string( mptr )))
			return;

		show_status_bar_message(position);
		}
	return;
}

public	void	status_message_length(int position, char * message, int length )
{
	char 	* sptr;
	int	i;
	if ( newbar ) 
		status_bar_message(Context.StatusObject, position, message );
	else if ( Context.StatusBar.style != 0 ) {
		if ( bar_message[position] != (char *) 0 )
			liberate(bar_message[position]);
		if (!(sptr = (bar_message[position] = allocate( length+1 ))))
			return;
		else	{
			for (i=0; i < length; i++ )
				*(sptr+i) = *(message+i);
			*(sptr+length) = 0;			
			}
		show_status_bar_message(position);
		}
	return;


}

public 	void	status_progress(int position,int limit, int value)
{
	int	boxwidth;
	int	texwidth;
	int	wipewidth;
	int	boxposit;
	if ( Context.StatusBar.style != 0 ) {

		boxwidth = (((Context.StatusBar.w-Context.fontwidth)/3) 
			 	- Context.fontwidth);
		boxposit = ((boxwidth+Context.fontwidth)*(position-1));

		visual_progress( 
			(Context.StatusBar.x+boxposit)+Context.fontwidth,
			(Context.StatusBar.y+(Context.fontheight/2)),
			(boxwidth-(Context.fontwidth*2)),Context.fontheight,
			Context.basefont,
			standard_title,0,limit,value,0);

		}
}

public 	void	show_mouse_position(int x,int y)
{
	if ( Context.gridlockw) {
		x = use_grid_lock(x,0,Context.gridlockw);
		y = use_grid_lock(y,0,Context.gridlockh);
		}
	sprintf(buffer,"%u,%u",x,y);
	status_message(buffer,1);
	return;
}

public 	void	show_zone_position(int x,int y,int w,int h)
{
	if ( Context.gridlockw ) {
		x = use_grid_lock(x,0,Context.gridlockw);
		y = use_grid_lock(y,0,Context.gridlockh);
		w = use_grid_lock(w,1,Context.gridlockw);
		h = use_grid_lock(h,1,Context.gridlockh);
		}
	sprintf(buffer,"%u,%u,%u,%u",x,y,w,h);
	status_message(buffer,1);
	return;
}

public 	void	show_item_info( struct form_item * iptr )
{
	char			*	mptr;
	struct	form_control	*	fptr;
	
	if (!( iptr ))
		return;
	else if ((fptr = iptr->parent) != (struct form_control *) 0) {
		if (fptr->loadname) {
			if ( fptr->identifier )
				sprintf(buffer,"%s(%s)",fptr->loadname,fptr->identifier);
			else	strcpy(buffer,fptr->loadname);
			}
		if (!( fptr->Buffer.value )) {
			if ( fptr->identifier )
				strcpy(buffer,fptr->identifier);
			else	strcpy(buffer,"noname");
			}
		else	{
			if ( fptr->identifier )
				sprintf(buffer,"%s %u x %u px ",fptr->identifier,fptr->Buffer.width,fptr->Buffer.height);
			else	sprintf(buffer,"noname(%u,%u)",fptr->Buffer.width,fptr->Buffer.height);
			}
		status_message(buffer,1);
		}

	sprintf(buffer,"%s %s (%u,%u,%u,%u)",
		get_widget_class( iptr->Contents.style ),
		iptr->Contents.name,
		iptr->Contents.x,
		iptr->Contents.y,
		iptr->Contents.w,
		iptr->Contents.h );

	status_message(buffer,2);

	if (!( mptr = widget_event_message( iptr ) ))
		return;

	else	status_message(mptr, 3);

	return;

}

public	void	draw_StatusBar()	
{ 
	int	position;
	int	boxposit;
	int	boxwidth;

	if ( Context.StatusBar.style ) {

		if ( newbar ) 
			visual_status_bar_show(Context.StatusObject);

		else	{
			visual_frame(	Context.StatusBar.x,Context.StatusBar.y,
				Context.StatusBar.w,Context.StatusBar.h,Context.StatusBar.style);

			boxwidth = (((Context.StatusBar.w-Context.fontwidth)/3) - Context.fontwidth);

			for (	position=1; position < 4; position++ )   {
	
				boxposit=((boxwidth+Context.fontwidth)*(position-1));

				visual_frame(	Context.StatusBar.x+2+boxposit,
					Context.StatusBar.y+2,
					boxwidth,Context.StatusBar.h-4,
					_EDIT_FRAME );


				show_status_bar_message(position);
				}

			}

		}
	Context.usage = 0;
	return;
}

public 	int	status_edit(char * mptr,int mlen)
{
	int	swap=0;
	int	status=0;
	struct	window_control Window;

	if (!( Context.StatusBar.style )) {
		swap = 1;
		swap_StatusBar();
		}

	visual_frame(	Context.StatusBar.x,Context.StatusBar.y,
		Context.StatusBar.w,Context.StatusBar.h,_EDIT_FRAME);

	Window.x = 2;
	Window.y = 2;
	Window.w = (Context.StatusBar.w-4);
	Window.h = (Context.StatusBar.h-4);
	Window.colour=(0x0F10);
	Window.font=1;
	Window.payload = mptr;
	Window.size    = mlen;

	status = edit_text( Context.StatusBar.x, Context.StatusBar.y, &Window );

	if ( swap )
		swap_StatusBar();
	else	draw_StatusBar();
		
	return( status );

}

#include "singfail.c"


