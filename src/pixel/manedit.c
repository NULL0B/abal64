#ifndef	_manedit_c
#define	_manedit_c

#include <stdio.h>
#include "stdpsu.h"
#include "cico.c"
#include "guimouse.h"

#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"

#include "manedit.h"

#define	public
#define	private static
#define	_MAX_BUFFER_SIZE	8192

private	int	nodecount=0;
private	int	screenheight=0;
private	int	statusheight=0;
private	int	toolsheight=0;
private	int	menuheight=0;
private	int	screenwidth=0;
private	int	statuswidth=0;
private	int	toolswidth=0;
private	int	menuwidth=0;
private	int	lineheight=0;
private	int	deskx=0;
private	int	desky=0;
private	int	deskadjx=0;
private	int	deskadjy=0;
private	int	deskw=0;
private	int	deskh=0;
private	int	title=0;
private	int	label=0;
private	int	fore=16;
private	int	back=15;
private	int	nodew=16;
private	int	nodeh=16;
private	int	zoom=2;
private	int	downx=0;
private	int	downy=0;
private	int	fixed=0;
private	int	speed=1;
private	int	view=0;
private	char *	system_editor=(char *) 0;

struct	icons
{
	char	* background;
	int	  bgstyle;

	char 	* simple;
	int	  simplestyle;

	char 	* complex;
	int	  complexstyle;

	char	* action;
	int	  actionstyle;

	char 	* user;
	int	  userstyle;

}	Icons = {
	"./background.jpg",3,
	"./simple.jpg",5,
	"./complex.jpg",5,
	"./action.jpg",5,
	"./user.jpg",5
	};

private	int	shade=22;
private	int	light=23;
private	int	cursor=29;
private	int	relation1=12;
private	int	relation2=14;

/*	-------------------------------------------------------------	*/
/*				a l l o c a t e				*/
/*	-------------------------------------------------------------	*/
void *	allocate( int n )
{
	char * rptr;
	if (!( rptr = malloc( n ) ))
		return( rptr );
	else
	{
		memset( rptr, 0, n );
		return( rptr );
	}
}

/*	-------------------------------------------------------------	*/
/*				l i b e r a t e				*/
/*	-------------------------------------------------------------	*/
void *	liberate( void * vptr )
{
	if ( vptr )
		free( vptr );
	return((void *) 0);
}

/*	-------------------------------------------------------------	*/
/*			e n t e r _ m o d a l				*/
/*	-------------------------------------------------------------	*/
public	int	enter_modal() 
{ 
	return(0); 
}

/*	-------------------------------------------------------------	*/
/*			l e a v e _ m o d a l				*/
/*	-------------------------------------------------------------	*/
public	int	leave_modal() 
{ 
	return(0); 
}

/*	-------------------------------------------------------------	*/
/*			c o n t r o l _ f o r k				*/
/*	-------------------------------------------------------------	*/
public	int	control_fork()
{
	return( fork() );
}

/*	-------------------------------------------------------------	*/
/*			s y s t e m _ f a i l u r e			*/
/*	-------------------------------------------------------------	*/
public	int	system_failure(char * mptr)
{
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			a l l o c a t e _ s t r i n g			*/
/*	-------------------------------------------------------------	*/
private	char *	allocate_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return( sptr );
	else if (!( rptr = (char *) allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else 	return( strcpy( rptr, sptr ) );
}

/*	-------------------------------------------------------------	*/
/*			o p e n _ g r a p h i c s			*/
/*	-------------------------------------------------------------	*/
private	int	open_graphics(int screenmode)
{
	if ( initialisepixel( (screenmode+512) ) == -1 )
		return(56);
	else
	{
		initialise_mouse();
		set_mimo_mask((
			_MIMO_WHILE_DOWN |
			_MIMO_DOWN 	 |
			_MIMO_UP 	 |
			_MIMO_CLICK	 |
			_MIMO_SEND_RIGHT |
			_MIMO_SEND_LEFT   	   ));

		load_palette("standard.rgb");
		put_palette();
		label = standard_load_font("/home/abal3/fonts/tahoma13.fmf");
		title = standard_load_font("/home/abal3/fonts/tahoma15.fmf");
		screenheight = 600;
		screenwidth  = 800;
		statusheight = 24;
		statuswidth  = 800;
		menuheight = 24;
		menuwidth  = 800;
		toolsheight = 600-(menuheight+statusheight);
		toolswidth  = 24;
		deskx = toolswidth;
		desky = menuheight;
		deskw = menuwidth - toolswidth ;
		deskh = toolsheight;
		return(0);
	}
}

/*	-------------------------------------------------------------	*/
/*			c l o s e _ g r a p h i c s			*/
/*	-------------------------------------------------------------	*/
private	void	close_graphics()
{
	terminate_mouse();
	liberatepixel();
	return;
}

/*	-------------------------------------------------------------	*/
/*			s h o w _ d e s k				*/
/*	-------------------------------------------------------------	*/
private	int	show_desk()
{
	filzone(deskx,desky,deskw,deskh,back);
	visual_image(deskx,desky,deskw,deskh,Icons.background,Icons.bgstyle);
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e t _ m a n i f e s t _ i n f o 		*/
/*	-------------------------------------------------------------	*/
private	int	get_manifest_info(char * buffer, struct manifest * mptr)
{
	sprintf(buffer,"<manifest name='%s' xmlns='%s'/>",
		( mptr->name ? mptr->name : "[no name]"),
		( mptr->ns   ? mptr->ns   : "[no ns]" ));
	return( strlen( buffer ) );
}

/*	-------------------------------------------------------------	*/
/*			s h o w _ m a n i f e s t _ i n f o 		*/
/*	-------------------------------------------------------------	*/
private	int	show_manifest_info(struct manifest * mptr)
{
	char	buffer[_MAX_BUFFER_SIZE];
	filzone(0,0,screenwidth,menuheight,shade);
	relief_box(0,0,screenwidth,menuheight,1);
	if ( mptr )
	{
		get_manifest_info( buffer, mptr );
		cicocolour(fore,0);
		PixelFontSat( toolswidth+4,(menuheight/4),title,buffer);
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*				s h o w _ t o o l s			*/
/*	-------------------------------------------------------------	*/
private	int	show_tools()
{
	filzone(0,menuheight,toolswidth,toolsheight,shade);
	relief_box(0,menuheight,toolswidth,toolsheight,1);
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			g e t _ n o d e _ i n f o  			*/
/*	-------------------------------------------------------------	*/
private	int	get_node_info(char * buffer, struct node * nptr)
{
	sprintf(buffer,"<node name='%s' access='%s' scope='%s' type='%s'/>",
		nptr->name, 
		( nptr->access ? "public" : "private"),
		( nptr->scope  ? "common" : "normal" ),
		( nptr->type   ? nptr->typename : "simple" ));
	return(strlen(buffer));
}

/*	-------------------------------------------------------------	*/
/*			s h o w _ n o d e _ i n f o  			*/
/*	-------------------------------------------------------------	*/
private	int	show_node_info(struct node * nptr)
{
	char buffer[_MAX_BUFFER_SIZE];
	filzone(0,screenheight-statusheight,screenwidth,statusheight,shade);
	relief_box(0,screenheight-statusheight,screenwidth,statusheight,1);
	if ( nptr )
	{
		get_node_info( buffer, nptr );	
		cicocolour(fore,0);
		PixelFontSat( toolswidth+4,screenheight-(statusheight/2)-(statusheight/4),title,buffer);
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			i s _ v i s i b l e				*/
/*	-------------------------------------------------------------	*/
private	int	is_visible(int x, int y )
{
	if ( x < deskadjx )
		return( 0 );
	else if ( y < deskadjy )
		return( 0 );
	else if ( x > ( deskadjx+deskw))
		return( 0 );
	else if ( y > ( deskadjy+deskh ))
		return( 0 );
	else 	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			g e t _ n o d e _ n a m e  			*/
/*	-------------------------------------------------------------	*/
private	int	get_node_name(char * buffer, struct node *nptr)
{
	if (!( nptr->name ))
		sprintf(buffer,"node%u",nptr->number);
	else	strcpy(buffer,nptr->name);
	return( strlen(buffer) );
}

/*	-------------------------------------------------------------	*/
/*			s h o w _ n o d e _ n a m e  			*/
/*	-------------------------------------------------------------	*/
private	int	show_node_name(int x, int y, int font, struct node *nptr, int mode)
{
	char	buffer[1024];
	get_node_name( buffer, nptr );
	if (!( mode ))
		cicocolour(fore,back);
	else	cicocolour(back,fore);
	PixelFontSat( x,y, font, buffer);	
}

/*	-------------------------------------------------------------	*/
/*				n o d e _ i c o n			*/
/*	-------------------------------------------------------------	*/
private	int	node_icon( int x, int y, int w, int h, int type, char * icon )
{
	visual_image(x,y,w,h,icon,Icons.simplestyle);
	return(0);
}

/*	-------------------------------------------------------------	*/
/*				s h o w _ n o d e 			*/
/*	-------------------------------------------------------------	*/
private	int	show_node(struct node *nptr)
{
	int	x;
	int	y;
	int	w;
	int	h;
	if (!( nptr ))
		return(0);
	else 	
	{
		x = (nptr->x * zoom);
		y = (nptr->y * zoom);
		w = (nodew * zoom);
		h = (nodeh * zoom);
		if (( is_visible( x,y ) )
		&&  ( is_visible( x+w,y+h ) ))
		{
			x += deskx;
			y += desky;
			x -= deskadjx;
			y -= deskadjy;
			relief_box(x,y,w,h,1);
			filzone(x+2,y+2,w-4,h-4,nptr->number%256);
			node_icon( x,y,w,h,nptr->type, nptr->icon);
			show_node_name( x+w+4, y+(h/2),label,nptr, 0 );
			nptr->visible=1;
		}
		else	nptr->visible=0;
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*		    s h ow _ n o d e _ l i s t _ i t e m 		*/
/*	-------------------------------------------------------------	*/
private	int	show_node_list_item( struct node * nptr, int dath )
{
	char	buffer[_MAX_BUFFER_SIZE];
	if ( nptr )
	{
		get_node_info(buffer,nptr);
		filzone(toolswidth,menuheight+nptr->ly,screenwidth-toolswidth,lineheight,dath);
		cicocolour(fore,0);
		PixelFontSat( toolswidth+4,menuheight+4+nptr->ly,title,buffer);
	}
	return(lineheight);
}

/*	-------------------------------------------------------------	*/
/*			g e t f o c u s _ n o d e 			*/
/*	-------------------------------------------------------------	*/
private	int	getfocus_node(struct node *nptr)
{
	int	x;
	int	y;
	int	w;
	int	h;
	if (!( nptr ))
		return(0);
	else if ( view == 1 )
		show_node_list_item( nptr, cursor );
	else 	
	{
		x = (nptr->x * zoom);
		y = (nptr->y * zoom);
		w = (nodew * zoom);
		h = (nodeh * zoom);
		if (( is_visible( x,y ) )
		&&  ( is_visible( x+w,y+h ) ))
		{
			x += deskx;
			y += desky;
			x -= deskadjx;
			y -= deskadjy;
			relief_box(x,y,w,h,2);
			filzone(x+2,y+2,w-4,h-4,nptr->number%256);
			node_icon( x,y,w,h,nptr->type,nptr->icon);
			show_node_name( x+w+4, y+(h/2),label,nptr, 1 );
			nptr->visible=1;
		}
		else	nptr->visible=0;
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			l o s e f o c u s _ n o d e 			*/
/*	-------------------------------------------------------------	*/
private	int	losefocus_node(struct node *nptr)
{
	if ( view == 1 )
		show_node_list_item( nptr, nptr->dath );
	else	show_node( nptr );
	return(0);
}

/*	-------------------------------------------------------------	*/
/*	     		t r a c e _ l i n k				*/
/*	-------------------------------------------------------------	*/
private	void	trace_link( struct node * source, struct node * target, int type )
{
	int	w;
	int	h;
	int	sx;
	int	sy;
	int	tx;
	int	ty;

	w = (nodew * zoom);
	h = (nodeh * zoom);

	sx = (source->x * zoom);
	sy = (source->y * zoom);
	tx = (target->x * zoom);
	ty = (target->y * zoom);

	tx += (w / 2);
	ty += (h / 2);
	sx += (w / 2);
	sy += (h / 2);

	if (!( is_visible( sx, sy ) ))
		return;
	else if (!( is_visible( tx, ty ) ))
		return;
	else
	{
		sx += deskx;
		sy += desky;
		sx -= deskadjx;
		sy -= deskadjy;
	
		tx += deskx;
		ty += desky;
		tx -= deskadjx;
		ty -= deskadjy;

		drawline( sx, sy, tx, ty, zoom, ( type ? relation1 : relation2 ) );
		show_node( source );
		show_node( target );
		return;
	}
}

/*	-------------------------------------------------------------	*/
/*	     s h o w _ m a n i f e s t _ d e p e n d a n c e		*/
/*	-------------------------------------------------------------	*/
private	int	show_manifest_dependance(struct manifest *mptr)
{
	struct	dependance * dptr;
	struct	node * nptr;
	hide();
	show_desk();
	show_manifest_info(mptr);
	if ((nptr = mptr->current) != (struct node *) 0)
	{
		show_node_info( nptr );
		for (	dptr=nptr->links.first;
			dptr != (struct dependance *) 0;
			dptr = dptr->next )
		{
			if (!( dptr->other ))
				continue;
			else  	trace_link( nptr, dptr->other, dptr->type );
		}
	}
	show(deskx,desky,deskw,deskh);
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			s h o w _ m a n i f e s t _ l i s t 		*/
/*	-------------------------------------------------------------	*/
private	int	show_manifest_list(struct manifest *mptr)
{
	int	item=0;
	int	aty;
	struct	node * nptr;
	int	dath;
	hide();
	show_desk();
	show_manifest_info(mptr);

	if (!( mptr->top ))
		mptr->top = mptr->first;

	lineheight = 20;
	for (	aty=0,nptr=mptr->top;
		nptr != (struct node *) 0;
		nptr = nptr->next )
	{
		if ( item++ & 1 )
			dath = shade;
		else	dath = light;
		nptr->dath = dath;
		nptr->ly = aty;
		show_node_list_item( nptr, dath );
		aty += lineheight;
	 }
		
	show_node_info(mptr->current);
	show(deskx,desky,deskw,deskh);
	return(0);
}
	
/*	-------------------------------------------------------------	*/
/*			s h o w _ m a n i f e s t _ p l a n 		*/
/*	-------------------------------------------------------------	*/
private	int	show_manifest_plan(struct manifest *mptr)
{
	struct	node * nptr;
	hide();
	show_desk();
	show_manifest_info(mptr);
	for (	nptr=mptr->first;
		nptr != (struct node *) 0;
		nptr = nptr->next )
		show_node( nptr );
	show_node_info(mptr->current);
	show(deskx,desky,deskw,deskh);
	return(0);
}

/*	-------------------------------------------------------------	*/
/*				s h o w _ m a n i f e s t		*/
/*	-------------------------------------------------------------	*/
private	int	show_manifest(struct manifest *mptr)
{
	switch ( view )
	{
	case	0	:
		show_manifest_plan( mptr );
		break;
	case	1	:
		show_manifest_list( mptr );
		break;
	case	2	:
		show_manifest_dependance( mptr );
		break;
	}
}

/*	-------------------------------------------------------------	*/
/*			g e t f o c u s _ m a n i f e s t		*/
/*	-------------------------------------------------------------	*/
private	int	getfocus_manifest(struct manifest *mptr)
{
	if (!( mptr ))
		return( 0 );
	else if (!( mptr->current ))
		return( 0 );
	else
	{
		getfocus_node( mptr->current );
		return(0);
	}
}

/*	-------------------------------------------------------------	*/
/*			l o s e f o c u s _ m a n i f e s t		*/
/*	-------------------------------------------------------------	*/
private	int	losefocus_manifest(struct manifest *mptr)
{
	if (!( mptr ))
		return( 0 );
	else if (!( mptr->current ))
		return( 0 );
	else
	{
		losefocus_node( mptr->current );
		return(0);
	}
}

/*	-------------------------------------------------------------	*/
/*				c h e c k _ i c o n 			*/
/*	-------------------------------------------------------------	*/
private	void	check_icon( struct node * nptr )
{
	if (!( nptr->type )) 
	{
		liberate( nptr->icon );
		nptr->icon = allocate_string( Icons.simple );
	}
	else
	{
		if ( strcmp( nptr->icon, Icons.complex ) )
		{
			if (!( strcmp( nptr->icon, Icons.simple ) ))
			{
				liberate( nptr->icon );
				nptr->icon = allocate_string( Icons.complex );
			}
		}
	}
	return;
}

/*	-------------------------------------------------------------	*/
/*				d r o p _ n o d e			*/
/*	-------------------------------------------------------------	*/
private	struct node * drop_node(struct node * nptr)
{
	if ( nptr )
	{
		if ( nptr->name ) 	liberate( nptr->name );
		if ( nptr->icon ) 	liberate( nptr->icon );
		if ( nptr->typename ) 	liberate( nptr->typename );
		if ( nptr->category ) 	liberate( nptr->category );
		liberate( nptr );
	}
	return((struct node *) 0);
}

/*	-------------------------------------------------------------	*/
/*				n e w _ n o d e				*/
/*	-------------------------------------------------------------	*/
private	struct node * new_node(int mode)
{
	struct	node * nptr;
	if (!( nptr = allocate( sizeof( struct node ) )))
		return(0);
	else	memset( nptr, 0, sizeof( struct node ) );
	if (!( nptr->icon = allocate_string( Icons.simple ) ))
		return( drop_node( nptr ) );
	else
	{
		nptr->number = ++nodecount;
		if (!( nptr->category = allocate_string( "manifest" ) ))
			return( drop_node(nptr) );
		else if (!( mode ))
			return( nptr );
		else if ( accept_new_node( &nptr->name, &nptr->access, &nptr->scope, &nptr->type, &nptr->typename, &nptr->category, &nptr->icon ) == 27 )
			return( drop_node(nptr) );
		else
		{
			check_icon( nptr );
			return( nptr );
		}
	}
}

/*	-------------------------------------------------------------	*/
/*		r e s o l v e _ m a n i f e s t _ n o d e 		*/
/*	-------------------------------------------------------------	*/
private	struct	node *	resolve_manifest_node( struct manifest * mptr, char * name )
{
	struct	node *	nptr;
	for ( nptr=mptr->first; nptr != (struct node *) 0; nptr = nptr->next )
	{
		if (!( nptr->name ))
			continue;
		else if (!( strcmp( nptr->name, name ) ))
			break;
	}
	return( nptr );
}

/*	-------------------------------------------------------------	*/
/*			a n a l y s e _ m a n i f e s t			*/
/*	-------------------------------------------------------------	*/
private	void	analyse_manifest(struct manifest *mptr)
{
	struct	dependance * dptr;
	struct	dependance * ddptr;
	struct	relation* rptr;
	struct	node 	* nptr;
	struct	node 	* nnptr;
	struct	action 	* aptr;
	char		* vptr;
	char		* wptr;
	char 		* nodename;
	char 		* nodeword;

	while ((rptr=mptr->graph.first) != (struct relation *) 0)
	{
		mptr->graph.first = rptr->next;

		if ((dptr = rptr->source) != (struct dependance *) 0)
		{
			nptr = dptr->owner;
			if (!( dptr->previous ))
				nptr->links.first = dptr->next;
			else	dptr->previous->next = dptr->next;
			if (!( dptr->next ))
				nptr->links.last = dptr->previous;
			else	dptr->next->previous = dptr->previous;

			if ( dptr->expression )
				liberate( dptr->expression );
			liberate( dptr );
		}

		if ((dptr = rptr->target) != (struct dependance *) 0)
		{
			nptr = dptr->owner;
			if (!( dptr->previous ))
				nptr->links.first = dptr->next;
			else	dptr->previous->next = dptr->next;
			if (!( dptr->next ))
				nptr->links.last = dptr->previous;
			else	dptr->next->previous = dptr->previous;

			if ( dptr->expression )
				liberate( dptr->expression );
			liberate( dptr );
		}

		liberate( rptr );
	}

	mptr->graph.first = mptr->graph.last = (struct relation *) 0;		

	/* ------------------------------------- */
	/* analyse construction dependance graph */
	/* ------------------------------------- */
	for ( 	aptr=mptr->configuration.first;
		aptr != (struct action *) 0;
		aptr = aptr->next )
	{
		/* ------------------- */
		/* for each expression */
		/* ------------------- */
		if (!( aptr->expression ))
			continue;
		else if (!( vptr = allocate_string( aptr->expression ) ))
			continue;
		else	wptr = vptr;

		/* ------------------------- */
		/* step over optional prefix */
		/* ------------------------- */
		if (!(strncmp( vptr, "cordscript:", strlen( "cordscript:" ) ) ))
		{
			vptr += strlen( "cordscript:" );
		}
		while ( *vptr == ' ' ) vptr++;

		/* ------------------------------------ */
		/* extract eventual dependant node name */
		/* ------------------------------------ */
		nodename = vptr;
		
		while (( *vptr ) && ( *vptr != '.' )) vptr++;

		if ( *vptr != '.' )
		{
			liberate( wptr );
			continue;
		}
		else	*(vptr++) = 0;

		/* ------------------------- */
		/* locate corresponding node */
		/* ------------------------- */
		if (!( nptr = resolve_manifest_node( mptr, nodename ) ))
		{
			liberate( wptr );
			continue;
		}

		/* ------------------------------------- */
		/* extract eventual configuration method */
		/* ------------------------------------- */
		nodeword = vptr;
		
		while (( *vptr ) && ( *vptr != '(' )) vptr++;

		if ( *vptr == '(' )	*(vptr++) = 0;

		if ( strcmp( nodeword, "configure" ) != 0 )
		{
			liberate( wptr );
			continue;
		}

		/* ------------------------------------- */
		/* extract eventual dependance node name */
		/* ------------------------------------- */
		while ( *vptr == ' ' ) vptr++;

		nodename = vptr;

		while (( *vptr ) && ( *vptr != '.' )) vptr++;

		if ( *vptr == '.' )	*(vptr++) = 0;

		/* ------------------------- */
		/* locate corresponding node */
		/* ------------------------- */
		if (!( nnptr = resolve_manifest_node( mptr, nodename ) ))
		{
			liberate( wptr );
			continue;
		}

		/* ------------------------------- */
		/* we have a dependance of n on nn */
		/* ------------------------------- */
		else if (!( rptr = allocate( sizeof( struct relation  ) ) ))
		{
			liberate( wptr );
			continue;
		}
		else if (!( dptr = allocate( sizeof( struct dependance ) ) ))
		{
			liberate( wptr );
			liberate( rptr );
			continue;
		}
		else if (!( ddptr = allocate( sizeof( struct dependance ) ) ))
		{
			liberate( wptr );
			liberate( rptr );
			liberate( dptr );
			continue;
		}
		else
		{
			memset( dptr, 0, sizeof( struct dependance ));
			dptr->other = nnptr;
			dptr->owner = nptr;
			dptr->expression = allocate_string( wptr );
			if (!( dptr->previous = nptr->links.last ))
				nptr->links.first = dptr;
			else	dptr->previous->next = dptr;
			nptr->links.last = dptr;
			dptr->type = 0;
			dptr->parent = rptr;

			memset( ddptr, 0, sizeof( struct dependance ));
			ddptr->expression = wptr;
			ddptr->other = nptr;
			ddptr->owner = nnptr;
			ddptr->parent = rptr;
			if (!( ddptr->previous = nnptr->links.last ))
				nnptr->links.first = ddptr;
			else	ddptr->previous->next = ddptr;
			nnptr->links.last = ddptr;
			ddptr->type = 1;

			memset( rptr, 0, sizeof( struct relation ));
			rptr->source = dptr;
			rptr->target = ddptr;
			if (!( rptr->previous = mptr->graph.last ))
				mptr->graph.first = rptr;
			else	rptr->previous->next = rptr;
			mptr->graph.last = rptr;
		}
	}
	return;

}

/*	-------------------------------------------------------------	*/
/*			a d d_ n o d e _ a f t e r			*/
/*	-------------------------------------------------------------	*/
private	struct	node * add_node_after(struct manifest *mptr,int mode)
{
	struct	node * nptr;
	if (!( nptr = new_node(mode)))
		return((struct node *) 0 );
	else if ( mptr->current )
	{
		nptr->x = mptr->current->x;
		nptr->y = mptr->current->y + nodeh;
		nptr->previous = mptr->current;
		if (( nptr->next = mptr->current->next ) != (struct node *) 0)
			nptr->next->previous = nptr;
		mptr->current->next = nptr;
		mptr->current = nptr;			
		if ( fixed ) recalculate_after( nptr );
	}
	else if ( mptr->last )
	{
		nptr->x = mptr->last->x;
		nptr->y = mptr->last->y + nodeh;
		nptr->previous = mptr->last;
		mptr->last->next = nptr;
		mptr->last = nptr;			
	}
	else
	{
		nptr->x = nptr->y = 10;
		mptr->first = mptr->last = nptr;
	}
	analyse_manifest( mptr );
	return(nptr);
}

/*	-------------------------------------------------------------	*/
/*				d e l e t e _ n o d e			*/
/*	-------------------------------------------------------------	*/
private	int	delete_node(struct manifest *mptr)
{
	struct	node * nptr;
	if (!( nptr = mptr->current ))
		return(0);

	if (!( nptr->previous ))
		mptr->first = nptr->next;
	else	nptr->previous->next = nptr->next;

	if (!( nptr->next ))
	{
		mptr->last = nptr->previous;
		mptr->current = nptr->previous;
	}
	else
	{
		mptr->current = nptr->next;
		nptr->next->previous = nptr->previous;
	}

	drop_node( nptr );
	analyse_manifest( mptr );
	return( 1 );
}

/*	-------------------------------------------------------------	*/
/*			r e c a l c u l a t e _ a f t e r		*/
/*	-------------------------------------------------------------	*/
private	void	recalculate_after( struct node * nptr )
{	
	struct	node * vptr;
	while ((vptr = nptr->next) != (struct node *) 0)
	{
		vptr->y = nptr->y + nodeh;
		nptr = vptr;
	}
	return;
}

/*	-------------------------------------------------------------	*/
/*			a d d _ n o d e _ b e f o r e 			*/
/*	-------------------------------------------------------------	*/
private	struct node *	add_node_before(struct manifest *mptr,int mode)
{
	struct	node * nptr;
	if (!( nptr = new_node(mode)))
		return((struct node *) 0 );
	else if ( mptr->current )
	{
		nptr->x = mptr->current->x;
		nptr->y = mptr->current->y + nodeh;
		nptr->next = mptr->current;
		if (( nptr->previous = mptr->current->previous ) != (struct node *) 0)
			nptr->previous->next = nptr;
		mptr->current->previous = nptr;
		mptr->current = nptr;			
		if ( fixed ) recalculate_after( nptr );
	}
	else if ( mptr->first )
	{
		nptr->x = mptr->first->x;
		nptr->y = mptr->first->y + nodeh;
		nptr->next = mptr->first;
		mptr->first->previous = nptr;
		mptr->first = nptr;			
	}
	else
	{
		nptr->x = nptr->y = 10;
		mptr->first = mptr->last = nptr;
	}
	analyse_manifest( mptr );
	return(nptr);
}

/*	-------------------------------------------------------------	*/
/*			a d d _ a c t i o n _ a f t e r			*/
/*	-------------------------------------------------------------	*/
private	struct	action * add_action_after( struct actions * reason )
{
	struct	action * aptr;
	if (!( aptr = allocate( sizeof( struct action ) ) ))
		return( aptr );
	else
	{
		memset( aptr, 0, sizeof( struct action ) );
		if (!( aptr->previous = reason->last ))
			reason->first = aptr;
		else
			aptr->previous->next = aptr;
		reason->last = aptr;
		return( aptr );
	}
}

#include "maneditsave.c"

/*	-------------------------------------------------------------	*/
/*			i s _ z o n r _ e v e n t			*/
/*	-------------------------------------------------------------	*/
private	int	is_zone_event(int x, int y, int zx, int zy, int zw, int zh )
{
	if (( x < zx ) || ( y < zy ))
		return(0);
	else if (( x > (zx+zw) ) || ( y > (zy+zh) ))
		return(0);
	else
	{
		return(1);
	}
}
	
/*	-------------------------------------------------------------	*/
/*			i s _ n o d e _ e v e n t			*/
/*	-------------------------------------------------------------	*/
private	struct	node * is_node_event(int x, int y, struct manifest * mptr)
{
	int	nx;
	int	ny;
	int	nw;
	int	nh;
	struct	node * nptr;
	for (	nptr=mptr->first;
		nptr != (struct node *) 0;
		nptr = nptr->next )
	{
		if (!( nptr->visible ))
			continue;
		else
		{
			nx = (nptr->x * zoom);
			ny = (nptr->y * zoom);
			nw = (nodew * zoom);
			nh = (nodeh * zoom);
			nx += deskx;
			ny += desky;
			nx -= deskadjx;
			ny -= deskadjy;
			if (!( is_zone_event( x,y, nx, ny, nw, nh ) ))
				continue;
			else	return( nptr );
		}
	}
	return((struct node *) 0);
}

/*	-------------------------------------------------------------	*/
/*				m o v e _ n o d e 			*/
/*	-------------------------------------------------------------	*/
private	int	move_node(int x, int y, struct node * nptr,struct manifest * mptr)
{
	int	c;
	int	t;
	int	tx;
	int	ty;
	while (1)
	{
		if ((c = visual_getch()) == 27)
			break;
		else if ( c != 256 )
			continue;
		else
		{
			if (!( fixed ))
			{
				if ( speed )
				{
					tx = visual_event(7);
					ty = visual_event(6);
					nptr->x += ( tx - x );
					nptr->y += ( ty - y );
					x = tx; y = ty;
					if ( nptr->x < 0 ) nptr->x = 0;
					if ( nptr->y < 0 ) nptr->y = 0;
				}
				else
				{
					tx = visual_event(7);
					ty = visual_event(6);
					nptr->x += (( tx - x ) / zoom);
					nptr->y += (( ty - y ) / zoom);
					x = tx; y = ty;
					if ( nptr->x < 0 ) nptr->x = 0;
					if ( nptr->y < 0 ) nptr->y = 0;
				}
			}
			if ((t = visual_event(1)) != _MIMO_UP)
				show_manifest(mptr);
			else	break;
		}
	}
	mptr->current = nptr;
	show_manifest(mptr);
	return(0);
}

/*	-------------------------------------------------------------	*/
/*				m o v e _ p a g e 			*/
/*	-------------------------------------------------------------	*/
private	int	move_page(int x, int y,struct manifest * mptr)
{
	int	c;
	int	t;
	int	tx;
	int	ty;
	while (1)
	{
		if ((c = visual_getch()) == 27)
			break;
		else if ( c != 256 )
			continue;
		else
		{
			if (!( fixed ))
			{
				if ( speed )
				{
					tx = visual_event(7);
					ty = visual_event(6);
					deskadjx += ( x - tx );
					deskadjy += ( y - ty );
					y = ty; x = tx;
					if ( deskadjy < 0 ) deskadjy = 0;
					if ( deskadjx < 0 ) deskadjx = 0;
				}
				else
				{
					tx = visual_event(7);
					ty = visual_event(6);
					deskadjy += (( y - ty ) / zoom);
					deskadjx += (( x - tx ) / zoom);
					y = ty; x = tx;
					if ( deskadjx < 0 ) deskadjx = 0;
					if ( deskadjy < 0 ) deskadjy = 0;
				}
			}
			if ((t = visual_event(1)) != _MIMO_UP)
				show_manifest(mptr);
			else	break;
		}
	}
	show_manifest(mptr);
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			m a n i f e s t _ l e f t			*/
/*	-------------------------------------------------------------	*/
private	int	manifest_left( struct manifest *mptr)
{
	int	c;
	int	t;
	int	x;
	int	y;
	int	tx;
	int	ty;
	struct node * nptr;
	x = visual_event(7);
	y = visual_event(6);

	if ((t = visual_event(1)) == _MIMO_DOWN)
	{
		if (!( nptr = is_node_event( x,y, mptr ) ))
			return( move_page(x,y, mptr) );
		else	return( move_node( x,y, nptr,mptr ) );
	}
}

/*	-------------------------------------------------------------	*/
/*			m a n i f e s t _ r i g h t			*/
/*	-------------------------------------------------------------	*/
private	int	manifest_right( struct manifest *mptr)
{
	int	t;
	int	x;
	int	y;
	struct node * nptr;
	x = visual_event(7);
	y = visual_event(6);
	if ((t = visual_event(1)) != _MIMO_UP)
		return(0);
	if (!( nptr = is_node_event( x,y, mptr ) ))
		return( use_manifest_menu() );
	else
	{
		mptr->current = nptr;
		return( use_node_menu() );
	}
}

/*	-------------------------------------------------------------	*/
/*			m a n i f e s t _ e v e n t			*/
/*	-------------------------------------------------------------	*/
private	int	manifest_event(struct manifest *mptr)
{
	int	b;
	if ((b = visual_event(2)) == _MIMO_LEFT )
		return( manifest_left( mptr) );
	else if ( b == _MIMO_RIGHT )
		return( manifest_right( mptr) );
	else	return(0);

}

/*	-------------------------------------------------------------	*/
/*			e d i t _ m a n i f e s t			*/
/*	-------------------------------------------------------------	*/
private	int	edit_manifest(struct manifest *mptr)
{
	char	buffer[1024];
	if ( system_editor )
	{
		sprintf(buffer,"%s %s\n",system_editor,mptr->filename);
		system( buffer );
	}
	return(0);
}

/*	-------------------------------------------------------------	*/
/*			m a n i f e s t _ o p e r a t i o n		*/
/*	-------------------------------------------------------------	*/
private	int	manifest_operation(struct manifest *mptr)
{
	int	c;
	struct	node * nptr=(struct node *) 0;
	mptr->current = mptr->top = mptr->first;
	show_tools();
	show_manifest(mptr);
	while (1)
	{
		getfocus_manifest(mptr);
		c = visual_getch();
		losefocus_manifest(mptr);
		if ( c == 27 ) 
			break;
		else if ( c == 256 )
			if (!(c = manifest_event(mptr))) 
				continue;

		switch( c )
		{
		case	1	:
			if ( add_node_after(mptr,1) )
				show_manifest(mptr);
			break;
		case	2	:
			if ( add_node_before(mptr,1) )
				show_manifest(mptr);
			break;
		case	3	:
			deskadjy += (deskh / 2);
			show_manifest(mptr);
			break;
		case	4	:
			edit_manifest(mptr);
			break;
		case	0x0012	:
			if ( deskadjy > (deskh / 2) )
				deskadjy -= (deskh / 2);
			else	deskadjy = 0;
			show_manifest(mptr);
			break;
		case	16	:
			generate_manifest( mptr, mptr->filename );
			break;
		case	127	:
			if ( delete_node(mptr) )
				show_manifest(mptr);
			break;
		case	5	:
			if (( mptr->current )
			&& ( mptr->current->next ))
			{
				mptr->current = mptr->current->next;
				show_manifest(mptr);
			}
			break;
		case	13	:
			accept_new_manifest(&mptr->name,&mptr->ns,&mptr->filename,&mptr->owner.name,&mptr->access.name,&mptr->access.level,&mptr->access.policy, &fixed, &speed );
			show_manifest(mptr);
			continue;

		case	11	:
			if (( mptr->current )
			&& ( mptr->current->previous ))
			{
				mptr->current = mptr->current->previous;
				show_manifest(mptr);
			}
			break;
		case	9	:
			if (!( nptr = mptr->current ))
				continue;
			else if ( accept_new_node( &nptr->name, &nptr->access, &nptr->scope, &nptr->type, &nptr->typename, &nptr->category,&nptr->icon ) == 27 )
				continue;
			else	
			{
				check_icon( nptr );
				show_manifest(mptr);
				break;
			}

		case	'!'	:
			view += 1;
			view %= 3;
			show_manifest(mptr);
			continue;
		case	'/'	:
		case	'-'	:
			if ( zoom > 1 ) 
			{
				zoom--;
				show_manifest(mptr);
			}
			break;
		case	'*'	:
		case	'+'	:
			if ( zoom < 100 ) 
			{
				zoom++;
				show_manifest(mptr);
			}
			break;

		default		:
			continue;
		}
	}
	return( 0 );
}

/*	-------------------------------------------------------------	*/
/*		a l l o c a t e _ u n q u o t e d _ s t r i n g		*/
/*	-------------------------------------------------------------	*/
private	char *	allocate_unquoted_string( char * sptr )
{
	if (!( sptr ))
		return( sptr );
	if ( *sptr == '"' )
	{
		*sptr++;
		if ( *(sptr+(strlen(sptr)-1)) == '"' )
			*(sptr+(strlen(sptr)-1)) = 0;
		return( allocate_string(sptr) );
	}
}

#include "maneditload.c"

/*	-------------------------------------------------------------	*/
/*				x m l _ n a m e				*/
/*	-------------------------------------------------------------	*/
private	char *	xml_name( char * buffer, char * stub )
{
	sprintf(buffer,"%s.xml",stub);
	return( buffer );
}

/*	-------------------------------------------------------------	*/
/*				m a n e d i t 				*/
/*	-------------------------------------------------------------	*/
public	int	manedit(int argc, char * argv[])
{
	char 	buffer[1024];
	struct	manifest M;
	int	status;
	memset( &M, 0, sizeof( struct manifest ));
	if (!( system_editor = allocate_string( "aed" ) ))
		return( 27 );
	else if (!( M.name = allocate_string( argv[1] ) ))
		return( 27 );
	else if (!( M.owner.name = allocate_string( argv[1] ) ))
		return( 27 );
	else if (!( M.access.name = allocate_string( argv[1] ) ))
		return( 27 );
	else if (!( M.ns = allocate_string( "http://www.compatibleone.fr/schemes/manifest.xsd" )))
		return( 27 );
	else if (!( M.filename = allocate_string( ( argc < 3  ? xml_name( buffer, argv[1] ) : xml_name( buffer, argv[2] ) ) ) ))
		return( 27 );
	else
	{
		load_manifest( &M );
		analyse_manifest( &M );
		sprintf(buffer,"Accords Platform Manifest Editor : %s\n",M.name);
		set_desktop_name( buffer );
		set_desktop_icon( "manedit" );
		if ((status = open_graphics(3)) != 0)
			return(status);
		else
		{
			accept_new_manifest_attach();
			accept_new_node_attach();
			manifest_operation(&M);
			accept_new_node_detach();
			accept_new_manifest_detach();
			close_graphics();
			return(0);
		}
	}
}

/*	-------------------------------------------------------------	*/
/*				b a n n e r				*/
/*	-------------------------------------------------------------	*/
public	int	banner(int arc, char * argv[])
{
	printf("\n   Manifest Editor Version 1.0a.0.01");
	printf("\n   Beta Version  22/01/2013 ");
	printf("\n   Copyright (c) 2013 Iain James Marshall\n\n");
	return(0);
}

/*	-------------------------------------------------------------	*/
/*				m a i n 				*/
/*	-------------------------------------------------------------	*/
public	int	main(int argc, char * argv[])
{
	if ( argc == 1 )
		return( banner(argc, argv) );
	else	return( manedit(argc,argv) );
}

#endif	/* _manedit_c */









