#ifndef	_singfmed_c
#define	_singfmed_c

#include "singfmed.h"
#include "singpars.h"
extern	char * system_imagepath;

struct	visual_flowchart_editor VFE = {

	(struct	visual_flowchart_model  *) 0,	/* first   		*/
	(struct	visual_flowchart_model  *) 0,	/* last	   		*/
	(struct	visual_flowchart_model  *) 0,	/* current 		*/
	(struct	visual_flowchart_model  *) 0,	/* solo	   		*/
	(char *) 0,				/* name	   		*/
	1,					/* hyper space view	*/
	4,					/* fractioning		*/
	1,					/* bubble control 	*/
	0,0,					/* x and y margins 	*/
	0,0,0,0,				/* x y w h 	   	*/
	50,					/* padding	   	*/
	10,					/* trace padding   	*/
	0,					/* debug trace route	*/
	50,					/* recursive tracedepth */
	0,					/* relation tracer 	*/
	3,					/* trace line width	*/
	1,					/* trace line color	*/
	0					/* not inhibited 	*/
	};


struct visual_flowchart_relation * flowchartRelationRemove( struct visual_flowchart_relation * rptr );
struct visual_flowchart_model * flowchartModelRemove(struct visual_flowchart_model * mptr );
struct visual_flowchart_member * flowchartModelCreate();
void	flowchartModelPrompt( struct visual_flowchart_model  * xptr );
void	flowchartCalculateHyperView();
void	flowchartEditorRefresh();
void	flowchartEditorRebuild();
void	flowchartEditorCamera();

/*	----------------------------------------	*/
/*	 f l o w c h a r t T r a c e L i n e   ()		*/
/*	----------------------------------------	*/
void	flowchartTraceLine( int sx, int sy, int tx, int ty )
{
	if ( sx == tx ) {
		if ( sy > ty ) {
			if ( visual_element( sx, ty, 1, (sy-ty), _STYLE_FLOWCHART_TRACE_NORTH, " ", 0) )
				visual_line(	sx,	sy,	tx,	ty, VFE.tracewidth, VFE.tracecolour );
			}
		else if ( visual_element( sx, sy, 1, (ty-sy), _STYLE_FLOWCHART_TRACE_SOUTH, " ", 0) )
			visual_line(	sx,	sy,	tx,	ty, VFE.tracewidth, VFE.tracecolour );
		}
	else	{
		if ( sx > tx ) {
			if ( visual_element( tx, sy, (sx-tx),1, _STYLE_FLOWCHART_TRACE_WEST, " ", 0) )
				visual_line(	sx,	sy,	tx,	ty, VFE.tracewidth, VFE.tracecolour );
			}
		else if ( visual_element( sx, sy, (tx-sx),1, _STYLE_FLOWCHART_TRACE_EAST, " ", 0) )
			visual_line(	sx,	sy,	tx,	ty, VFE.tracewidth, VFE.tracecolour );
		}
	return;
}

/*	----------------------------------------	*/
/*	 f l o w c h a r t T r a c e P o i n t ()		*/
/*	----------------------------------------	*/
void	flowchartTracePoint( int sx, int sy )
{
	if ( visual_element( sx, sy, 1, 1, _STYLE_FLOWCHART_TRACE_POINT, " ", 0) )
		visual_line(	sx,	sy,	sx, sy, VFE.tracewidth, VFE.tracecolour );
	return;
}

/*	----------------------------------------	*/
/*		f l o w c h a r t H a s h ()		*/
/*	----------------------------------------	*/
int	flowchartHash( char * sptr )
{	
	int	h=0;
	if (!( sptr ))
		return(0);
	while ( *sptr ) h += *(sptr++); 
	return( (h % 2007) );
}
	
/*	------------------------------------------------	*/
/*	  f l o w c h a r t T e x t W i d t h ( m, s, f ) 	*/
/*	------------------------------------------------	*/
int	flowchartTextWidth( char * message, char * style, int fid )
{
	int	w=0;
	if (!( message ))
		return(0);
	else if (!( style )) {
		if (!( fid ))
			return(0);
		else	return( textsizelen( fid, message, strlen(message) ) );
		}
	else 	{
		if (( w = resolve_style_width( style )) != 0)
			return(w);
		else	return( resolve_style_textwidth( style, message, strlen(message) ) );
		}	
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t T e x t H e i g h t ( m, s, f ) 	*/
/*	------------------------------------------------	*/
int	flowchartTextHeight( char * message, char * style, int fid )
{
	int	h;
	if (!( message ))
		return(0);
	else if (!( style )) {
		if (!( fid ))
			return(0);
		else if (!( h = guifontsize( fid )))
			return(0);
		else	return(((h >> 8) & 0x00FF));
		}
	else 	{
		if (( h = resolve_style_height( style )) != 0)
			return(h);
		else 	return( resolve_style_fontheight( style ) );
		}	
}


/*	----------------------------------------	*/
/*	  f l o w c h a r t H e l p S h o w ()		*/
/*	----------------------------------------	*/
void	flowchartHelpShow( char * mptr, char * sptr )
{
	VFE.bubble.x = visual_event(7);
	VFE.bubble.y = visual_event(6);
	if ( VFE.bubblehelp ) {
		VFE.bubble.w = 220; VFE.bubble.h = 120;
		}
	else if (!( sptr )) 
		return;
	else	{
		VFE.bubble.w = 20; VFE.bubble.h = 20;
		}
	if (!( VFE.bubblezone = visual_buffer(VFE.bubble.x,VFE.bubble.y,VFE.bubble.w,VFE.bubble.h) ))
		return;
	else	{
		visual_buffer_get(VFE.bubblezone, VFE.bubble.x, VFE.bubble.y );
		if ( sptr ) {
			visual_element(VFE.bubble.x,VFE.bubble.y, 
				10,15, sptr, " ", 0);
			}
		if ( VFE.bubblehelp ) {
			visual_element(VFE.bubble.x+20,VFE.bubble.y+20, 
				200, 100, _STYLE_FLOWCHART_BUBBLE_FRAME, mptr, strlen( mptr ));
			}
		return;
		}
}

/*	----------------------------------------	*/
/*	  f l o w c h a r t H e l p H i d e ()		*/
/*	----------------------------------------	*/
void	flowchartHelpHide()
{
	if ( VFE.bubblezone ) {
		visual_buffer_put(VFE.bubblezone, VFE.bubble.x, VFE.bubble.y );
		visual_drop( VFE.bubblezone );
		VFE.bubblezone = (void *) 0;
		}
	return;
}


/*	--------------------------------------------------------	*/
/*									*/
/*	    D A T B A S E   R E L A T I O N   M E T H O D S		*/
/*									*/
/*	--------------------------------------------------------	*/

/*	-------------------------------------------------	*/
/*	  f l o w c h a r t R e l a t i o n D e f i n e ()  	*/
/*	-------------------------------------------------	*/
struct	visual_flowchart_member * flowchartRelationDefine()
{
	int	event;
	/* Allow user to click on something else */
	/* ------------------------------------- */
	mouse_move_on();
	while (1) {
		flowchartHelpShow("select the target member of the relation, or press escape to cancel the operation",
				_STYLE_FLOWCHART_RELATION_TARGET);
		event = visual_getch();
		flowchartHelpHide();
		if ( event == 27 )
			return( (struct	visual_flowchart_member *) 0 );
		else if ( event != 256 )
			continue;
		else if ( visual_event(1) == _MIMO_UP )
			break;
		}
	mouse_move_off();
	if ( flowchartEditorEvent( visual_event(7), visual_event(6)) != 256 )
		return((struct visual_flowchart_member*) 0);
	else if (!( VFE.current ))
		return((struct visual_flowchart_member*) 0);
	else	return( VFE.current->current );
}

/*	-------------------------------------------------	*/
/*	       f l o w c h a r t L i n k M o v e ()              	*/
/*	-------------------------------------------------	*/
int	flowchartLinkMove(struct visual_flowchart_relation * rptr )
{
	struct	visual_flowchart_model  * pptr;
	struct	visual_flowchart_member * wptr;

	if (!( wptr = flowchartRelationDefine()))
		return(0);
	else if (!( rptr->relation ))
		return(0);
	else if (!( pptr = wptr->parent ))
		return(0);
	else	{
		return(1);
		}
}
		
/*	-------------------------------------------------	*/
/*	       f l o w c h a r t L i n k C h a n g e ()          	*/
/*	-------------------------------------------------	*/
int	flowchartLinkChange(struct visual_flowchart_relation * rptr )
{
	struct	visual_flowchart_model  * pptr;
	struct	visual_flowchart_member * wptr;

	if (!( wptr = flowchartRelationDefine(1)))
		return(0);
	else if (!( rptr->relation ))
		return(0);
	else if (!( pptr = wptr->parent ))
		return(0);
	else	{
		return(1);
		}
}
		
/*	-------------------------------------------------	*/
/*	       f l o w c h a r t L i n k D e l e t e()           	*/
/*	-------------------------------------------------	*/
int	flowchartLinkDelete(struct visual_flowchart_relation * rptr)
{
	struct visual_flowchart_model 	* smptr;
	struct visual_flowchart_member 	* sptr;
	struct visual_flowchart_model 	* tmptr;
	struct visual_flowchart_member 	* tptr;
	struct link_control 		* lptr;
	if (!( sptr = rptr->source ))
		return(0);
	else if (!( smptr = sptr->parent ))
		return(0);
	else if ( smptr->lock )
		return(0);
	else if (!( tptr = rptr->target ))
		return(0);
	else if (!( tmptr = tptr->parent ))
		return(0);
	else if ( tmptr->lock )
		return(0);
	if (!(  lptr = rptr->relation ))
		return( 0 );
	else	{
		if (!( rptr->previous ))
			sptr->first = rptr->next;
		else	rptr->previous->next = rptr->next;

		if (!( rptr->next ))
			sptr->last = rptr->previous;
		else	rptr->next->previous = rptr->previous;

		if (!( lptr->previous ))
			FileManager->firstlink= lptr->next;
		else 	lptr->previous->next = lptr->next;

		if (!( lptr->next ))
			FileManager->lastlink= lptr->previous;
		else 	lptr->next->previous = lptr->previous;

		if ( lptr->source )
			liberate( lptr->source );
		if ( lptr->target )
			liberate( lptr->target);
		liberate( lptr );
		flowchartRelationRemove( rptr );		
		flowchartEditorShow();
		return;
		}

}

/*	-------------------------------------------------	*/
/*	       f l o w c h a r t L i n k I n f o ()              	*/
/*	-------------------------------------------------	*/
int	flowchartLinkInfo(struct visual_flowchart_relation * rptr)
{
	struct visual_flowchart_model 	* smptr;
	struct visual_flowchart_member 	* sptr;
	struct visual_flowchart_model 	* tmptr;
	struct visual_flowchart_member 	* tptr;
	if (!( sptr = rptr->source ))
		return(0);
	else if (!( tptr = rptr->target ))
		return(0);
	else if (!( smptr = sptr->parent ))
		return(0);
	else if (!( tmptr = tptr->parent ))
		return(0);
	return(0);
}

/*	----------------------------------------	*/
/*	f l o w c h a r t _ l i n k _ m e n u ()	*/
/*	----------------------------------------	*/
int	flowchart_link_menu()
{
	return(27);
}

/*	--------------------------------------------	*/
/*	f l o w c h a r t _ m e m b e r _ m e n u ()	*/
/*	--------------------------------------------	*/
int	flowchart_member_menu()
{
	return(27);
}

/*	-------------------------------------------------	*/
/*	       f l o w c h a r t L i n k M e n u ()              	*/
/*	-------------------------------------------------	*/
int	flowchartLinkMenu(struct visual_flowchart_relation * rptr)
{
	switch ( flowchart_link_menu() ) {
		case	_FORM_ACTION_INFO	:
			flowchartLinkInfo( rptr );
			break;
		case	_FORM_ACTION_DELETE	:
			flowchartLinkDelete( rptr );
			break;
		case	_FORM_ACTION_MOVE	:
			flowchartLinkMove(rptr);
			break;
		}
	return;
}
		
/*	--------------------------------------------------------	*/
/*	  f l o w c h a r t R e l a t i o n E v e n t  ( rptr )		*/
/*	--------------------------------------------------------	*/
int	flowchartRelationEvent( struct visual_flowchart_member * mptr, int mx, int my )
{
	int	sx;
	int	sy;
	int	sh;
	int	sw;
	int	tx;
	int	ty;
	int	th;
	int	tw;
	struct visual_flowchart_relation * rptr;
	struct visual_flowchart_member 	* sptr;
	struct visual_flowchart_member 	* tptr;
	struct visual_flowchart_model 	* smptr;
	struct visual_flowchart_model 	* tmptr;

	for (	rptr = mptr->first;
		rptr != (struct visual_flowchart_relation *) 0;
		rptr = rptr->next ) {
		if (!( sptr = rptr->source ))
			continue;
		else if (!( tptr = rptr->target ))
			continue;
		else if (!( smptr = sptr->parent ))
			continue;
		else if (!( tmptr = tptr->parent ))
			continue;
		else if ( sptr->x > tptr->x ) {
			sx = sptr->x;
			tx = tptr->x + tptr->w;
			}
		else	{
			sx = sptr->x + sptr->w;
			tx = tptr->x;
			}

		sx -= 5; sw = 10; 
		sy  = sptr->y+(sptr->h/4);
		sh  = (sptr->h/2);
		if (( mx >= sx )
		&&  ( my >= sy )
		&&  ( mx < (sx+sw))
		&&  ( my < (sy+sh))) {
			/* Source Anchor Event */
			if (( visual_event(1) == _MIMO_UP) 
			&&  ( visual_event(2) == _MIMO_RIGHT))
				return( flowchartLinkMenu( rptr ) );
			else if (( visual_event(1) == _MIMO_DOWN)
			     &&  ( visual_event(2) == _MIMO_LEFT))
				return( flowchartLinkChange( rptr ) );
			}
		tx -= 5; tw = 10;
		ty  = tptr->y+(tptr->h/4);
		th  = (tptr->h/2);
		if (( mx >= tx )
		&&  ( my >= ty )
		&&  ( mx < (tx+tw))
		&&  ( my < (ty+th))) {
			/* Target Anchor Event */
			if (( visual_event(1) == _MIMO_UP) 
			&&  ( visual_event(2) == _MIMO_RIGHT))
				return( flowchartLinkMenu( rptr ) );
			else if (( visual_event(1) == _MIMO_DOWN)
			     &&  ( visual_event(2) == _MIMO_LEFT))
				return( flowchartLinkMove( rptr ) );
			}
		}
	return(0);
}

/*	---------------------------------------------------------	*/
/*	f l o w c h a r t M o d e l R e l a t i o n E v e n t(rptr)	*/
/*	---------------------------------------------------------	*/
int	flowchartModelRelationEvent( struct visual_flowchart_model * mptr, int mx, int my )
{
	struct	visual_flowchart_member * bptr;
	if ((( visual_event(1) == _MIMO_UP  ) &&  ( visual_event(2) == _MIMO_RIGHT))
	||  (( visual_event(1) == _MIMO_DOWN) &&  ( visual_event(2) == _MIMO_LEFT ))) {
		for ( 	bptr = mptr->first;
			bptr != (struct visual_flowchart_member *) 0;
			bptr = bptr->next ) {
			if (!( flowchartRelationEvent( bptr, mx, my ) ))
				continue;
			else	return(256);
			}
		}
	return(0);
}
/*	--------------------------------------------------------	*/
/*	  f l o w c h a r t R e l a t i o n R e m o v e ( rptr )		*/
/*	--------------------------------------------------------	*/
struct visual_flowchart_relation * flowchartRelationRemove( struct visual_flowchart_relation * rptr )
{
	if ( rptr->name )
		liberate( rptr->name );
	liberate( rptr );
	return((struct visual_flowchart_relation *) 0);
}

/*	--------------------------------------------------------	*/
/*	  f l o w c h a r t R e l a t i o n C r e a t e ( )     		*/
/*	--------------------------------------------------------	*/
struct visual_flowchart_relation * flowchartRelationCreate()
{
	struct visual_flowchart_relation * rptr;

	if (!( rptr = allocate( sizeof( struct visual_flowchart_relation ) ) ))
		return( rptr );

	else	{
		rptr->name = (char *) 0;
		rptr->next = rptr->previous = (struct visual_flowchart_relation *) 0;
		rptr->source = rptr->target = (struct visual_flowchart_member *) 0;
		rptr->relation = (struct link_control *) 0;
		rptr->nature = 0;
		return( rptr );
		}
}

/*	-------------------------------------------	*/
/*	f l o w c h a r t R e l a t i o n C o p y()
/*	-------------------------------------------	*/
struct visual_flowchart_relation * flowchartRelationCopy( struct visual_flowchart_relation * sptr )
{
	struct visual_flowchart_relation * rptr;
	if (( rptr = flowchartRelationCreate()) != (struct visual_flowchart_relation *) 0) {
		if (( sptr->name ) &&  (!( rptr->name = allocate_string( sptr->name ))))
			return( flowchartRelationRemove(rptr) );
		rptr->nature = sptr->nature;
		rptr->target = sptr->target;
		}
	return( rptr );
}
	

#include "singflow.c"

/*	------------------------------------------------	*/
/*	f l o w c h a r t A c t i o n S o u r c e (a,xx) 	*/
/*	------------------------------------------------	*/
char	*	flowchartActionSource( int action, int reverse )
{
	switch ( action ) {
		case	_ACTION_OVERLAY	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_OVERLAY_SOURCE );
			else	return( _STYLE_FLOWCHART_REV_OVERLAY_SOURCE );
		case	_ACTION_MODULE	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_MODULE_SOURCE );
			else	return( _STYLE_FLOWCHART_REV_MODULE_SOURCE );
		case	_ACTION_CHAIN	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_CHAIN_SOURCE );
			else	return( _STYLE_FLOWCHART_REV_CHAIN_SOURCE );
		case	_ACTION_LOADGO	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_LOADGO_SOURCE );
			else	return( _STYLE_FLOWCHART_REV_LOADGO_SOURCE );
		case	_ACTION_CLASS	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_CLASS_SOURCE );
			else	return( _STYLE_FLOWCHART_REV_CLASS_SOURCE );
		case	_ACTION_NULL	:
		default			:
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_RELATION_SOURCE );
			else	return( _STYLE_FLOWCHART_REV_RELATION_SOURCE );
		}
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t A c t i o n T a r g e t (a,xx) 	*/
/*	------------------------------------------------	*/
char	*	flowchartActionTarget( int action, int reverse )
{
	switch ( action ) {
		case	_ACTION_OVERLAY	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_OVERLAY_TARGET );
			else	return( _STYLE_FLOWCHART_REV_OVERLAY_TARGET );
		case	_ACTION_MODULE	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_MODULE_TARGET );
			else	return( _STYLE_FLOWCHART_REV_MODULE_TARGET );
		case	_ACTION_CHAIN	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_CHAIN_TARGET );
			else	return( _STYLE_FLOWCHART_REV_CHAIN_TARGET );
		case	_ACTION_LOADGO	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_LOADGO_TARGET );
			else	return( _STYLE_FLOWCHART_REV_LOADGO_TARGET );
		case	_ACTION_CLASS	: 
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_CLASS_TARGET );
			else	return( _STYLE_FLOWCHART_REV_CLASS_TARGET );
		case	_ACTION_NULL	:
		default			:
			if ( !( reverse ) )
				return( _STYLE_FLOWCHART_RELATION_TARGET );
			else	return( _STYLE_FLOWCHART_REV_RELATION_TARGET );
		}
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t M e m b e r S h o w ( mptr ) 	*/
/*	------------------------------------------------	*/
void	flowchartRelationShow(struct visual_flowchart_member * sptr, struct visual_flowchart_model * tptr )
{
	char *	ssptr;
	char *	tsptr;
	int	sx;
	int	sy;
	int	sph;
	int	spy;
	int	tx;
	int	ty;
	int	tph;
	int	tpy;
	int	mx;
	int	my;
	int	bx;
	int	reverse=0;
	int	action=_ACTION_NULL;
	struct visual_flowchart_model  * smptr;
	struct	form_item * iptr;
	struct	forms_method * pptr;
	if (!( sptr ))
		return;
	else if (!( smptr = sptr->parent ))
		return;
	else if (!( iptr = sptr->widget ))
		if (!( pptr = sptr->method ))
			if (!( sptr->detail ))
				return;

	databaseZoneReset(&sptr->left);
	databaseZoneReset(&sptr->right);


	if (!( tptr )) {
		if (!( smptr->state & 1 )) {
			if (!( sptr->target )) {
				sptr->right.w = sptr->left.w = (databaseTextWidth ( "N,N", _STYLE_FLOWCHART_RELATION_UNKNOWN, 1) + 2);
				sptr->right.h = sptr->left.h = (databaseTextHeight( "N,N", _STYLE_FLOWCHART_RELATION_UNKNOWN, 1) + 2);
				sptr->left.x = (sptr->x+sptr->w);
				sptr->left.y = (sptr->y+((sptr->h-sptr->left.h)/2));
				visual_element(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,_STYLE_FLOWCHART_RELATION_UNKNOWN," ",0); 
				}
			else	{
				sptr->right.w = sptr->left.w = (databaseTextWidth ( "N,N", _STYLE_FLOWCHART_RELATION_EXTERN, 1) + 2);
				sptr->right.h = sptr->left.h = (databaseTextHeight( "N,N", _STYLE_FLOWCHART_RELATION_EXTERN, 1) + 2);
				sptr->left.x = (sptr->x+sptr->w);
				sptr->left.y = (sptr->y+((sptr->h-sptr->left.h)/2));
				visual_element(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,_STYLE_FLOWCHART_RELATION_EXTERN," ",0); 
				}
			}
		return;
		}

	sptr->right.w = sptr->left.w = (databaseTextWidth ( "N,N", _STYLE_FLOWCHART_RELATION_SOURCE, 1) + 2);
	sptr->right.h = sptr->left.h = (databaseTextHeight( "N,N", _STYLE_FLOWCHART_RELATION_SOURCE, 1) + 2);

	if ( smptr->x > tptr->x ) {			/* TX+TW  <---------- SX */
		reverse = 1;
		sptr->left.x  = (smptr->x-sptr->left.w);		
		sx = sptr->left.x;
		sptr->right.x = (tptr->x+tptr->w); 	
		tx = (sptr->right.x + sptr->right.w);
		}
	else	{					/* SX+SW -----------> TX */
		reverse = 0;
		sptr->left.x  = (smptr->x + smptr->w);
		sx = (sptr->left.x + sptr->left.w);
		sptr->right.x = (tptr->x-sptr->right.w);
		tx = sptr->right.x;
		}


	if (!( smptr->state & 1 )) {
		if ( sptr->h > sptr->left.h)
			spy = sptr->y+((sptr->h-sptr->left.h)/2);
		else	spy = sptr->y;
		}
	else	{
		if ( smptr->h > sptr->left.h)
			spy = smptr->y+((smptr->h-sptr->left.h)/2);
		else	spy = smptr->y;
		}

	sptr->left.y = spy;
	sy = (sptr->left.y + (sptr->left.h/2));
	sph = sptr->left.h;

	if ( iptr ) {

		switch ((iptr->Contents.style &_FRAME_TYPE)) {
	
			case	_DATA_FRAME	:
				switch ( iptr->Contents.datatype ) {
					case	_WIDGET_IFRAME	:
					case	_WIDGET_OVERLAY	: action = _ACTION_OVERLAY; break;
					case	_WIDGET_MODULE 	: action = _ACTION_MODULE; break;
					case	_WIDGET_CLASS  	: action = _ACTION_CLASS; break;
					case	_WIDGET_POINTER : action = _ACTION_CLASS; break;
					default			: action = _ACTION_NULL; break;
					}
				break;
			case	_BUTTON_FRAME	:
			case	_TAB_FRAME	:
				switch ( iptr->Contents.datatype ) {
					case _WIDGET_IFRAME	:
					case _WIDGET_OVERLAY 	: action = _ACTION_OVERLAY; break;
					case _WIDGET_MODULE  	: action = _ACTION_MODULE; break;
					case _WIDGET_HYPERLINK :
					case _WIDGET_CHAIN   	: action = _ACTION_CHAIN; break;
					case _WIDGET_LOADGO  	: action = _ACTION_LOADGO; break;
					default			: action = _ACTION_NULL; break;
					}
				break;
			default			: action = _ACTION_NULL; break;
			}
		}
	ssptr = flowchartActionSource( action, reverse );

	if ( visual_element(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,ssptr," ",0)) 
		visual_frame(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,_EDIT_FRAME);

	/* target is inhibited */
	/* ------------------- */
	if (!( tptr->state & 1 )) {
		if ( tptr->total > sptr->right.h )
			tpy = tptr->y+((tptr->total-sptr->right.h)/2);
		else	tpy = tptr->y;
		}
	else	{
		if ( tptr->h > sptr->right.h )
			tpy = tptr->y+((tptr->h-sptr->right.h)/2);
		else	tpy = tptr->y;
		}
	
	tph = sptr->right.h;
	sptr->right.y = tpy;
	ty = (sptr->right.y + (sptr->right.h/2));

	ssptr = flowchartActionTarget( action, reverse );

	if ( visual_element(sptr->right.x,sptr->right.y,sptr->right.w,sptr->right.h,ssptr," ",0) )
		visual_frame(sptr->right.x,sptr->right.y,sptr->right.w,sptr->right.h,_EDIT_FRAME);


	if (!( VFE.bender )) {
		/* trace it as the crow flies */
		/* -------------------------- */
		visual_line(	sx,	sy,	tx,	ty, VFE.tracewidth, VFE.tracecolour );
		}
	else if ( VFE.bender == 2 ) {
		if ( VFE.debug_trace_route ) {
			printf("Relation : %s(%u,%u) -> %s(%u,%u)\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		flowchartTraceRoute( sx,sy,tx,ty,0,reverse );
		if ( VFE.debug_trace_route ) {
			printf("\tEndRelation\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		}
	else if ( sy == ty ) {
		flowchartTraceLine(sx,sy,tx,ty);
		}
	else if ( sx == tx ) {
		flowchartTraceLine(sx,sy,tx,ty);
		}
	else if ( sx > tx ) {
		mx = (tx + ((sx - tx) / 2));
		flowchartTraceLine(sx,sy,mx,sy);
		flowchartTraceLine(mx,sy,mx,ty);
		if ( sy < ty )
			flowchartTracePoint(mx,ty);
		flowchartTraceLine(mx,ty,tx,ty);
		}
	else 	{
		mx = (sx + ((tx - sx) / 2));
		flowchartTraceLine(sx,sy,mx,sy);
		if ( sy > ty )
			flowchartTracePoint(mx,sy);
		flowchartTraceLine(mx,sy,mx,ty);
		flowchartTraceLine(mx,ty,tx,ty);
		}
	return;
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t M e m b e r S h o w ( rptr ) 	*/
/*	------------------------------------------------	*/
void	flowchartRelationSave(struct visual_flowchart_relation * rptr )
{
	int	sx;
	int	sy;
	int	tx;
	int	ty;
	char * snptr;
	char * tnptr;

	struct visual_flowchart_member * sptr;
	struct visual_flowchart_member * tptr;
	struct visual_flowchart_model  * smptr;
	struct visual_flowchart_model  * tmptr;

	if (!( rptr ))
		return;
	else if (!( sptr = rptr->source ))
		return;
	else if (!( smptr = sptr->parent ))
		return;
	else if (!( tptr = rptr->target ))
		return;
	else if (!( tmptr = tptr->parent ))
		return;
	else if (!( snptr = allocate( strlen(sptr->name) + strlen(smptr->name) + 3 ) ))
		return;
	else if (!( tnptr = allocate( strlen(tptr->name) + strlen(tmptr->name) + 3 ) )) {
		liberate( snptr );
		return;
		}
	else	{
		sprintf(snptr,"%s.%s",smptr->name,sptr->name);
		sprintf(tnptr,"%s.%s",tmptr->name,tptr->name);
		liberate( tnptr );
		liberate( snptr );
		return;
		}
}

/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E   M E M B E R   M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	--------------------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r D r o p R e l a t i o n s ( mptr )	*/
/*	--------------------------------------------------------------	*/
void	flowchartMemberDropRelations(struct visual_flowchart_member * mptr )
{
	struct visual_flowchart_relation * rptr;
	while ((rptr = mptr->first) != ( struct visual_flowchart_relation *) 0) {
		mptr->first = rptr->next;
		flowchartRelationRemove( rptr );
		}
	mptr->first = mptr->last = (struct visual_flowchart_releation *) 0;
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r R e m o v e ( mptr )	*/
/*	------------------------------------------------	*/
struct visual_flowchart_member * flowchartMemberRemove(struct visual_flowchart_member * mptr )
{
	flowchartMemberDropRelations( mptr );
	if ( mptr->name ) { liberate( mptr->name ); }
	liberate( mptr );
	return((struct visual_flowchart_member *) 0);
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r R e s o l v e( xptr )	*/
/*	------------------------------------------------	*/
struct	flowchart_application_member * flowchartMemberResolve(char * xptr)
{
	struct visual_flowchart_model  * aptr;
	struct visual_flowchart_member * bptr;
	char 	work[512];
	char *	nptr;
	char * 	mptr;
	int	h;
	strcpy( work, xptr );
	for ( nptr = mptr = work; *mptr != 0; mptr++ )
		if ( *mptr == '.' )
			break;
	if ( *mptr == '.' )
		*(mptr++) = 0;
	h = flowchartHash( mptr );
	for (	aptr=VFE.first;
		aptr != (struct visual_flowchart_model *) 0;
		aptr = aptr->next ) {
		if (!( aptr->name ))
			continue;
		else if ( strcmp( aptr->name, nptr ) )
			continue;
		for (	bptr=aptr->first;
			bptr != (struct visual_flowchart_member *) 0;
			bptr = bptr->next ) {
			if (!( bptr->name ))
				continue;
			else if ( bptr->hash == -1 )
				bptr->hash = flowchartHash( bptr->name );
			if ( bptr->hash != h )
				continue;
			else if (!( strcmp( bptr->name, mptr ) ))
				return( bptr );
			}
		}
	return((struct visual_flowchart_member *) 0);
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r C r e a t e (      )	*/
/*	------------------------------------------------	*/
struct visual_flowchart_member * flowchartMemberCreate()
{
	struct visual_flowchart_member * mptr;
	if ((mptr = allocate( sizeof( struct visual_flowchart_member ) )) != (struct visual_flowchart_member *) 0) {
		mptr->previous = mptr->next = (struct visual_flowchart_member *) 0;
		mptr->x = mptr->y = mptr->w = mptr->h = 0;
		mptr->name = (char *) 0;
		mptr->widget = (struct form_item *) 0; 
		mptr->target = (struct form_contol *) 0; 
		mptr->method = (struct forms_method *) 0; 
		mptr->detail = (struct visual_flowchart_model *) 0;
		mptr->number=0;
		databaseZoneReset(&mptr->left);
		databaseZoneReset(&mptr->right);
		mptr->focus=0;
		mptr->hash=-1;
		mptr->parent=(struct visual_flowchart_model *) 0;
		mptr->first = mptr->last = (struct visual_flowchart_releation *) 0;
		}
	return( mptr );
}



/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M e m b e r E v e n t ( m,x,y ) 	*/
/*	-------------------------------------------------	*/
int	flowchartMemberEvent(struct visual_flowchart_member * mptr, int x, int y )
{
	if (!( mptr ))
		return(0);
	else if ( x < mptr->x )
		return(0);
	else if (y < mptr->y)
		return(0);
	else if (x > (mptr->x+mptr->w))
		return(0);
	else if (y > (mptr->y+mptr->h))
		return(0);
	else	{
		if (( visual_event(1) == _MIMO_UP    )
		&&  ( visual_event(2) == _MIMO_RIGHT )) 
			return( flowchartMemberMenu( mptr ) );
		else	return(1);
		}
}

/*	--------------------------------------------------	*/
/*	 f l o w c h a r t M e m b e r S y n t a x ( m, b ) 	*/
/*	--------------------------------------------------	*/
int	flowchartMemberSyntax( struct visual_flowchart_member * mptr, char * rptr )
{
	struct	form_control * fptr;
	struct	form_item * wptr;
	*rptr = 0;
	if (!( mptr ))
		return(0);
	else if (!( mptr->parent ))
		return(0);
	else if (!( wptr = mptr->widget ))
		return(0);
	else	{
		strcpy( rptr, wptr->Contents.name );
		return( strlen( rptr ) );
		}
}

/*	--------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r A n a l y s e ( m, b ) 	*/
/*	--------------------------------------------------	*/
int	flowchartMemberAnalyse( struct visual_flowchart_member * mptr, char * rptr )
{
	struct	form_control * dptr;
	if (!( mptr ))
		return(0);
	else if (!( mptr->parent ))
		return(0);
	else if (!( dptr = mptr->parent->form ))
		return(0);
	else	{
		return(0);
		}
}

/*	-----------------------------------------------------------	*/
/*	  f l o w c h a r t M e m b e r T e x t W i d t h ( m, s, f ) 	*/
/*	-----------------------------------------------------------	*/
int 	flowchartMemberTextWidth(struct visual_flowchart_member * mptr, char * style, int fid )
{
	char	workbuffer[512];
	if (!( mptr ))
		return(0);
	else if (!( flowchartMemberSyntax( mptr, workbuffer ) ))
		return( 0 );
	else	return( flowchartTextWidth( workbuffer, style, fid ) );
}

/*	---------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r C o m p o n a n t ()	*/
/*	---------------------------------------------------	*/
char * flowchartMemberComponent(struct visual_flowchart_member * mptr, char * sptr, char * cptr )
{
	struct	form_item * wptr;
	if (!( mptr ))
		return( sptr );
	else if (!( wptr = mptr->widget ))
		return( sptr );
	else if ((wptr->Contents.style &_FRAME_TYPE) == _DATA_FRAME )
		return( cptr );
	else	return( sptr );
}

/*	---------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r L o s e F o c u s(mptr) 	*/
/*	---------------------------------------------------	*/
void	flowchartMemberLoseFocus(struct visual_flowchart_member * mptr )
{
	if ( mptr ) {
		if ( mptr->focus ) {
			(void) visual_element( 
				mptr->x,mptr->y,mptr->w,mptr->h,
				flowchartMemberComponent(mptr,_STYLE_FLOWCHART_MEMBER,_STYLE_FLOWCHART_CLASS_FRAME),
				( mptr->name ? mptr->name : " "),
				( mptr->name ? strlen( mptr->name ) : 0)
				);
			mptr->focus=0;
			}
		}
	return;
}

/*	-------------------------------------------------	*/
/*	f l o w c h a r t M e m b e r G e t F o c u s(mptr) 	*/
/*	-------------------------------------------------	*/
void	flowchartMemberGetFocus(struct visual_flowchart_member * mptr )
{
	struct	visual_flowchart_model * pptr;
	struct	form_control * dptr;
	char	workbuffer[512];
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if (!( dptr = pptr->form ))
		return;
	else	{
		flowchartMemberLoseFocus( pptr->current );
		if (!( mptr->focus )) {
			strcpy(workbuffer,mptr->name);
			(void) visual_element( 
				mptr->x,mptr->y,mptr->w,mptr->h,
				flowchartMemberComponent(mptr,_STYLE_FLOWCHART_MEMBER_FOCUS,_STYLE_FLOWCHART_CLASS_FOCUS),
				workbuffer, strlen( workbuffer )
				);
			mptr->focus=1;
			}
		return;
		}
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t M e m b e r S h o w ( mptr ) 	*/
/*	------------------------------------------------	*/
void	flowchartMemberShow(struct visual_flowchart_member * mptr )
{
	if ( visual_element( 	
		mptr->x,mptr->y,mptr->w,mptr->h,
		flowchartMemberComponent(mptr,_STYLE_FLOWCHART_MEMBER,_STYLE_FLOWCHART_CLASS_FRAME),
		( mptr->name ? mptr->name : " " ), 
		( mptr->name ? strlen( mptr->name ) : 0 ) ) ) {

		/* Reset Zone otherwise */
		/* -------------------- */
		filzone	(
			mptr->x,mptr->y,
			mptr->w,mptr->h,
			_DEFAULT_GUI_WHITE);

		}
	return;
}

/*	----------------------------------------------------	*/
/*	 f l o w c h a r t M e m b e r L o c a t e  ( nptr )   	*/
/*	----------------------------------------------------	*/
struct visual_flowchart_member * flowchartMemberLocate( struct visual_flowchart_model * mptr, char * nptr )
{
	struct	visual_flowchart_member * rptr=(struct	visual_flowchart_member *) 0;
	int	h;
	if (!(  nptr )) 
		return( rptr );
	else if (!( mptr ))
		return( rptr );
	else	{
		h = flowchartHash(nptr);
		for (	rptr=mptr->first;
			rptr != (struct visual_flowchart_member *) 0;
			rptr = rptr->next ) {
			if (!( rptr->name ))
				continue;
			if ( rptr->hash == -1 )
				rptr->hash = flowchartHash(rptr->name);
			if ( rptr->hash != h )
				continue;
			else if (!( strcmp( rptr->name, nptr ) ))
				break;
			}
		return( rptr );
		}
}


/*	----------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l L o c a t e  ( nptr )   	*/
/*	----------------------------------------------------	*/
struct visual_flowchart_model * flowchartModelLocate( char * nptr )
{
	struct	visual_flowchart_model * rptr=(struct	visual_flowchart_model *) 0;
	int	h;
	if ( nptr ) {
		h = flowchartHash(nptr);
		for (	rptr=VFE.first;
			rptr != (struct visual_flowchart_model *) 0;
			rptr = rptr->next ) {
			if (!( rptr->name ))
				continue;
			else if ( rptr->hash == -1 )
				rptr->hash = flowchartHash( rptr->name );
			if ( rptr->hash != h )
				continue;
			else if (!( strcmp( rptr->name, nptr ) ))
				break;
			}
		}
	return( rptr );
}

/*	----------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l R e s o l v e ( mptr )   	*/
/*	----------------------------------------------------	*/
struct visual_flowchart_model * flowchartModelResolve( struct visual_flowchart_member * mptr )
{
	struct	form_control * fptr;
	struct	form_control * ffptr;
	struct	visual_flowchart_model * rptr=(struct	visual_flowchart_model *) 0;
	if (!( mptr ))
		return(rptr);
	else if ((rptr = mptr->detail ) != (struct	visual_flowchart_model *) 0)
		return( rptr );
	else if (!( fptr = mptr->target ))
		return(rptr);
	else if (!( fptr->identifier ))
		return(rptr);
	else if ( fptr->hash == -1 )
		fptr->hash = flowchartHash( fptr->identifier );
	/* scan list of forms to find the parent model */
	for (	rptr=VFE.first;
		rptr != (struct visual_flowchart_model *) 0;
		rptr = rptr->next ) {
		if (!( ffptr = rptr->form ))
			continue;
		else if (!( ffptr->identifier ))
			continue;
		else if ( ffptr->hash == -1 )
			ffptr->hash = flowchartHash( ffptr->identifier );
		if ( fptr->hash != ffptr->hash )
			continue;
		else if (!( strcmp( fptr->identifier, ffptr->identifier )))
			break;
		}
	return((mptr->detail = rptr));
}


/*	---------------------------------------------------------------		*/
/*	 f l o w c h a r t M e m b e r S h o w R e l a t i o n s ( mptr )   	*/
/*	---------------------------------------------------------------		*/
void	flowchartMemberShowRelations(struct visual_flowchart_member * mptr )
{
	struct	visual_flowchart_model * pptr;
	struct	visual_flowchart_model * rptr;
	pptr = mptr->parent;
	rptr = flowchartModelResolve( mptr );
	/* parent model detected : show relation from member to model */
	/* if ( rptr  != (struct visual_flowchart_model *) 0) */
	if (!( VFE.solo ))
		flowchartRelationShow( mptr, rptr );
	else if (( pptr ) && ( VFE.solo->number == pptr->number ))
		flowchartRelationShow( mptr, rptr );
	else if (( rptr ) && ( VFE.solo->number == rptr->number ))
		flowchartRelationShow( mptr, rptr );
	return;
}

/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M e m b e r N a t u r e ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartMemberNature(struct visual_flowchart_member * mptr)
{
	struct	visual_flowchart_model * pptr;
	struct	form_control * dptr;
	char	workbuffer[512];
	char *	rptr=workbuffer;

	/* validate member, parent and file control */
	/* ---------------------------------------- */
	if (!( mptr ))				return(0);

	flowchartEditorRefresh();
	return;
}
	
/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M e m b e r D e f i n e ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartMemberDefine(struct visual_flowchart_member * mptr)
{
	char	workbuffer[512];
	memset(workbuffer,' ',256);
	if (!( mptr ))
		return(0);
	else if (!( flowchartMemberSyntax( mptr, workbuffer ) ))
		return(0);
	else	{
		visual_frame(	VFE.x+(mptr->x-VFE.xmargin),
				VFE.y+(mptr->y-VFE.ymargin),
			     	mptr->w, mptr->h,
				_EDIT_FRAME);

		if ( visual_edit( 
			VFE.x+(mptr->x-VFE.xmargin)+1,
			VFE.y+(mptr->y-VFE.ymargin)+1,
			mptr->w-2, mptr->h,
			Context.basefont,
			workbuffer, 255 ) != 27) {
			limit_right_space( workbuffer, 255);
			flowchartMemberAnalyse(mptr, workbuffer);
			}
		return(1);
		}
}

/*	-----------------------------------------------		*/
/*	   f l o w c h a r t M e m b e r N e w ( model )  	*/
/*	-----------------------------------------------		*/
void	flowchartMemberNew(char * modname, int mid )
{
	struct	visual_flowchart_model * pptr;
	struct	visual_flowchart_member* mptr;
	if (!( modname ))
		return;
	for (	pptr=VFE.first;
		pptr != (struct visual_flowchart_model *) 0;
		pptr = pptr->next ) {
		if (!( pptr->name ))
			continue;
		else if (!( strcmp( modname , pptr->name )))
			break;
		}
	if (!( pptr ))
		return;
	for (	mptr=pptr->first;
		mptr != (struct	visual_flowchart_member*) 0;
		mptr = mptr->next) {
		if ( mptr->number == mid )
			break;
		}
	if ( mptr )
		flowchartMemberDefine( mptr );
	return;
}

/*	-------------------------------------------------	*/
/*	  f l o w c h a r t M e m b e r D e l e t e( model )  	*/
/*	-------------------------------------------------	*/
void	flowchartMemberDelete(struct visual_flowchart_member * mptr)
{
	struct	visual_flowchart_model * pptr;
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if ( pptr->lock )
		return;
	else if (!( pptr->form ))
		return;
	else	{
		flowchartEditorRebuild();
		return;
		}
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M e m b e r C o p y ( model )  	*/
/*	-------------------------------------------------	*/
struct visual_flowchart_member * flowchartMemberCopy(struct visual_flowchart_member * sptr)
{
	struct visual_flowchart_member * mptr;
	struct visual_flowchart_relation * wptr;
	struct visual_flowchart_relation * rptr;
	if ((mptr = flowchartMemberCreate()) != (struct visual_flowchart_member *) 0) {
		if (( sptr->name ) && (!( mptr->name = allocate_string( sptr->name ) )))
			return( flowchartMemberRemove( mptr ) );
		else	{
			mptr->x = sptr->x;
			mptr->y = sptr->y;
			mptr->w = sptr->w;
			mptr->h = sptr->h;
			mptr->number = sptr->number;
			}
		}
	return( mptr );
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M e m b e r P a s t e ( model )  	*/
/*	-------------------------------------------------	*/
void	flowchartMemberPaste(	struct visual_flowchart_member * mptr, 
				struct visual_flowchart_model * pptr )
{
	return;
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M e m b e r A f t e r ( model )  	*/
/*	-------------------------------------------------	*/
void	flowchartMemberAfter(	struct visual_flowchart_member * mptr, 
				struct visual_flowchart_model * pptr )
{
	int	mid;
	char *	modname;
	if (!( pptr ))
		return;
	else if (!( pptr->form ))
		return;
	else if (!(modname = allocate_string( pptr->name )))
		return;
	else	{
		flowchartEditorRebuild();
		flowchartMemberNew( modname, mid );
		flowchartEditorShow();
		}
	return;
}

/*	-------------------------------------------------	*/
/*	  f l o w c h a r t M e m b e r B e f o r e( model )  	*/
/*	-------------------------------------------------	*/
void	flowchartMemberBefore(struct visual_flowchart_member * mptr)
{
	int	mid;
	char *	modname;
	struct	visual_flowchart_model * pptr;
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if (!( pptr->form ))
		return;
	else if (!(modname = allocate_string( pptr->name )))
		return;
	else	{
		flowchartEditorRebuild();
		flowchartMemberNew( modname, mid );
		flowchartEditorShow();
		return;
		}
}

/*	-------------------------------------------------	*/
/*	  f l o w c h a r t M e m b e r R e l a t i o n (m)  	*/
/*	-------------------------------------------------	*/
void	flowchartMemberRelation(struct visual_flowchart_member * sptr)
{
	struct visual_flowchart_model * smptr;
	struct visual_flowchart_model * tmptr;

	struct visual_flowchart_member * tptr;
	struct visual_flowchart_relation * rptr;

	if (!( tptr = flowchartRelationDefine() ))
		return;
	else if (!( smptr = sptr->parent ))
		return;
	else if (!( tmptr = tptr->parent ))
		return;
	else if (!( strcmp( smptr->name, tmptr->name ) )) {
		/* do not create self relations */
		/* ---------------------------- */
		flowchartEditorAlert(1);
		return;
		}
	else if (!( rptr = flowchartRelationCreate() ))
		return;
	else	{
		if (!(rptr->previous = sptr->last))
			sptr->first = rptr;
		else	rptr->previous->next = rptr;
		sptr->last = rptr;
		rptr->source = sptr;
		rptr->target = tptr;
		rptr->name = allocate_string("relation");
		flowchartRelationSave( rptr );
		flowchartEditorShow();
		flowchartLinkInfo(rptr);
		return;
		}
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M e m b e r M e n u ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartMemberMenu(struct visual_flowchart_member * mptr)
{
	struct	form_item * wptr;
	struct	form_control * fptr;
	if (!( mptr ))
		return(0);
	else if (!( wptr = mptr->widget ))
		return(0);
	else if (!( fptr = wptr->parent ))
		return(0);
	else	{
		edit_Widget( wptr, fptr );
		return(1);
		}
#ifdef	_FMED_MENU
	switch ( flowchart_member_menu() ) {
		case	_FORM_MEMBER_DEFINE	:
			flowchartMemberDefine(mptr);
			return(1);
		case	_FORM_MEMBER_NATURE	:
			flowchartMemberNature(mptr);
			return(1);
		case	_FORM_MEMBER_DELETE	:
			flowchartMemberDelete(mptr);
			return(0x007F);
		case	_FORM_MEMBER_COPY	:
			if ( VFE.copied_member ) {
				VFE.copied_member = flowchartMemberRemove( VFE.copied_member );
				}
			VFE.copied_member = flowchartMemberCopy(mptr);
			return(1);
		case	_FORM_MEMBER_AFTER	:
			flowchartMemberAfter(mptr,mptr->parent);
			return(0x007F);
		case	_FORM_MEMBER_BEFORE	:
			flowchartMemberBefore(mptr);
			return(0x007F);
		case	_FORM_MEMBER_RELATION :
			flowchartMemberRelation(mptr);
			return(1);
		}
#endif
}

/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E    M O D E L    M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l I n h i b i t( mptr )	*/
/*	-------------------------------------------------	*/
int	flowchartModelInhibit(struct visual_flowchart_model * mptr)
{
	char	work[512];
	struct	form_control * fptr;
	struct	form_item * iptr;
	struct	camera3d * cptr;
	struct 	object3d * optr;
	struct	camera3d * kptr;
	if (!( VFE.inhibit ))
		return(0);
	else if (!( mptr ))
		return(0);
	else if (!( mptr->name ))
		return(0);
	else if (!( fptr = Context.Form ))
		return(0);
	else if (!(cptr = Context.Camera ))
		return(0);
	else if (!( optr = fptr->host ))
		return(0);
	else if (!( kptr = optr->host ))
		return(0);
	else if (!( kptr->name ))
		return(0);
	else if (!( cptr->name ))
		return(0);
	else if (!( strcmp( cptr->name, kptr->name ) ))
		return((mptr->inhibit=0));
	else	return((mptr->inhibit=1));
}

/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l L a y o u t ( mptr )		*/
/*	-------------------------------------------------	*/
void	flowchartModelLayout(struct visual_flowchart_model * mptr)
{
	struct	visual_flowchart_member  * xptr;
	int	my;
	int	mh;
	my = mptr->y + flowchartTextHeight(mptr->name,_STYLE_FLOWCHART_HEADER,0);
	mh = flowchartTextHeight(mptr->name,_STYLE_FLOWCHART_MEMBER,0);
	for (	xptr=mptr->first;
		xptr != (struct visual_flowchart_member *) 0;
		xptr = xptr->next ) {
		xptr->x = mptr->x;
		xptr->w = mptr->w;
		xptr->y = my;
		my += mh;
		xptr->h = mh;
		}
	/* Update VFE Buffer Control */
	/* ------------------------- */
	if (( mptr->x + mptr->w ) > VFE.buffer.width)
		VFE.buffer.width = (( mptr->x + mptr->w )+VFE.xpadding);
	if (( mptr->y + mptr->h ) > VFE.buffer.height)
		VFE.buffer.height = (( mptr->y + mptr->h )+VFE.ypadding);
	return;
}

/*	-------------------------------------------------	*/
/*	f l o w c h a r t M o d e l H e i g h t ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelHeight(struct visual_flowchart_model * mptr)
{
	if (!( mptr ))
		return(0);
	else if ( mptr->state & 2 )
		return((mptr->h = mptr->isize));
	else if ( mptr->state & 1 )
		return((mptr->h = mptr->msize));
	else	return((mptr->h = mptr->total));
}

/*	-------------------------------------------------	*/
/*	  f l o w c h a r t M o d e l S t a t e ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelState(struct visual_flowchart_model * mptr)
{
	if (!( mptr ))
		return(0);
	if ( mptr->state  & 1 )
		mptr->state &= ~1;
	else	mptr->state |= 1;
	flowchartModelHeight(mptr);
	flowchartEditorShow();
	return(1);
}

/*	-------------------------------------------------	*/
/*	  f l o w c h a r t M o d e l S i g h t ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelSight(struct visual_flowchart_model * mptr)
{
	if (!( mptr ))
		return(0);
	if ( mptr->state  & 2 )
		mptr->state &= ~2;
	else	mptr->state |= 2;
	flowchartModelHeight(mptr);
	flowchartEditorShow();
	return(1);
}

/*	-------------------------------------------------	*/
/*	  f l o w c h a r t E d i t o t D e t a i l( )  	*/
/*	-------------------------------------------------	*/
int	flowchartEditorDetail()
{
	struct visual_flowchart_model * mptr;
	for (	mptr=VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ){
		if ( mptr->state & 1 )
			mptr->state &= ~1;
		else	mptr->state |= 1;
		flowchartModelHeight(mptr);
		}
	flowchartEditorShow();
	return(1);
}
/*	-------------------------------------------------	*/
/*	  f l o w c h a r t E d i t o t S i g h t  ( )  	*/
/*	-------------------------------------------------	*/
int	flowchartEditorSight()
{
	struct visual_flowchart_model * mptr;
	for (	mptr=VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ){
		if ( mptr->state & 2 )
			mptr->state &= ~2;
		else	mptr->state |= 2;
		flowchartModelHeight(mptr);
		}
	flowchartEditorShow();
	return(1);
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l L o c k ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelLock(struct visual_flowchart_model * mptr)
{
	mptr->lock = ((mptr->lock+1) & 1);
	return(0);
}

/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l R e n a m e ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelRename(struct visual_flowchart_model * mptr)
{
	char	workbuffer[512];
	if (!( mptr ))
		return;
	memset(workbuffer,' ',256);
	strcpy( workbuffer, mptr->name );
	visual_frame(	VFE.x+(mptr->x-VFE.xmargin),
			VFE.y+(mptr->y-VFE.ymargin),
		     	mptr->w, ( mptr->state & 1 ? mptr->h : mptr->total ),
			_EDIT_FRAME);
	if ( visual_edit( 
		VFE.x+(mptr->x-VFE.xmargin)+1,
		VFE.y+(mptr->y-VFE.ymargin)+1,
		mptr->w-2, ( mptr->state & 1 ? mptr->h : mptr->total ),
		Context.basefont,
		workbuffer, 255 ) != 27) {
		if ( mptr->name )
			liberate( mptr->name );
		mptr->name = allocate_string( workbuffer );
		}
	return(1);
}

/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l D e l e t e ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelDelete(struct visual_flowchart_model * mptr)
{
	struct file_control * fptr;
	struct form_control * dptr;
	if (!( mptr->lock )) {
		flowchartEditorRemove();
		drop_file_control((void *) 0, fptr);
		flowchartEditorCreate();
		flowchartEditorShow();
		}
	return(0);
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l C o p y ( model )  	*/
/*	-------------------------------------------------	*/
struct visual_flowchart_model *  flowchartModelCopy(struct visual_flowchart_model * sptr)
{
	struct visual_flowchart_model * wptr;
	struct visual_flowchart_member * mptr;
	struct visual_flowchart_member * tptr;
	if (( wptr = flowchartModelCreate()) != (struct visual_flowchart_model *) 0) {
		if (( sptr->name ) && (!( wptr->name = allocate_string( sptr->name ) )))
			return( flowchartModelRemove( wptr ) );
		wptr->form = sptr->form;
		wptr->inhibit = sptr->inhibit;
		wptr->lock= sptr->lock;
		wptr->state= sptr->state;
		wptr->isize= sptr->isize;
		wptr->msize= sptr->msize;
		wptr->total= sptr->total;
		wptr->x = sptr->x; wptr->y = sptr->y; wptr->w = sptr->w; wptr->h = sptr->h;
		for (	mptr = sptr->first;
			mptr != (struct visual_flowchart_model *) 0;
			mptr = mptr->next ) {
			if (!( tptr = flowchartMemberCopy( mptr ) ))
				return( flowchartModelRemove( wptr ) );
			if (!( tptr->previous = wptr->last ))
				wptr->first = tptr;
			else	tptr->previous->next = tptr;
			wptr->last = tptr;
			tptr->parent = wptr;
			}
		}
	return( wptr );		
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l I n f o ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelInfo(struct visual_flowchart_model * mptr)
{
	int	indextype=0;
	int	datatype=0;
	int	modext=0;
	int	marker=0;
	int	opener;
	int	locker;
	struct	file_control * fptr;
	struct	form_control * dptr;

	return(0);
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l S o l o ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelSolo(struct visual_flowchart_model * mptr)
{
	if (!( VFE.solo ))
		VFE.solo = mptr;
	else if (!( strcmp( VFE.solo->name , mptr->name ) ))
		VFE.solo = (struct visual_flowchart_model *) 0;
	else	VFE.solo = mptr;
	if ( VFE.solo )
		status_message("model specific flowchart links",2);
	else	status_message("all project flowchart links",2);
	flowchartEditorShow();
	return(0);
}

/*	------------------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l P a r a  m e t e r s( model )  	*/
/*	------------------------------------------------------------	*/
int	flowchartModelParameters(struct visual_flowchart_model * mptr)
{
	struct	form_control * fptr;
	if (!( mptr ))
		return(0);
	else if (!( fptr = mptr->form ))
		return(0);
	else	{
		flowchartModelPrompt(mptr);
		form_parameters( fptr );
		return(1);
		}
}

/*	----------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l E d i t o r ( model )  	*/
/*	----------------------------------------------------	*/
int	flowchartModelEditor(struct visual_flowchart_model * mptr)
{
	int	h;
	struct	form_control * ffptr;
	struct	form_control * fptr;
	if (!( mptr ))
		return(0);
	else if (!( fptr = mptr->form ))
		return(0);
	else	{
		flowchartModelPrompt(mptr);
		flowchartEditorRemove();
		h = set_context_dataview(0);
		ffptr = Context.Form;
		Context.Form = fptr;
		FormEditorOnExec((struct form_control **)&Context.Form);
		Context.Form = ffptr;
		h = set_context_dataview(h);
		flowchartEditorCreate();
		flowchartEditorShow();
		return(1);
		}
}

/*	-------------------------------------------------	*/
/*			t a b u l a t o r			*/
/*	-------------------------------------------------	*/
static	void	tabulator(int level )
{
	int	i;
	for ( i=0; i < level; i++ ) 
		printf("\t");
	return;
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r B e s t ( )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelBest(struct visual_flowchart_model * mptr, struct style_zone * zptr, int level )
{
	struct	visual_flowchart_member * wptr;
	struct	visual_flowchart_model * rptr;
	struct	style_zone position;
	int	ecart=0;
	int	adjust=0;
	if (!( mptr ))
		return(0);
	else if (!( zptr ))
		return(0);
	else if ( mptr->done > 1 ) 
		return(0);
	else	{
		mptr->done++;
		/* tabulator(level); printf("Model : %s \r\n",mptr->name); */
		for (	wptr=mptr->first;
			wptr != (struct visual_flowchart_member *) 0;
			wptr = wptr->next ) {
			if (!( rptr = flowchartModelResolve( wptr )))
				continue;
			else if ( rptr->done > 0 )
				continue;
			else if ( mptr->state & 1 ) {
				if ( mptr->users <= 1 )
					mptr->done++;
				continue;
				}
			rptr->done++;
			rptr->by = mptr->number;
			/* tabulator(level); printf("\t positions %s \r\n",rptr->name); */
			rptr->x = zptr->x+ecart; ecart += 10;
			rptr->y = zptr->y + zptr->h;
			zptr->h += rptr->h;
			zptr->h += VFE.ypadding;
			flowchartModelLayout( rptr );
			}
		position.x = (mptr->x + mptr->w + VFE.xpadding);
		position.y = mptr->y;
		position.h = 0; position.w = 0;
		for (	wptr=mptr->first;
			wptr != (struct visual_flowchart_member *) 0;
			wptr = wptr->next ) {
			if (!( rptr = flowchartModelResolve( wptr )))
				continue;
			else if ( rptr->by != mptr->number )
				continue;
			else if ( rptr->done > 1)
				continue;
			else	{
				position.x = (rptr->x + rptr->w + VFE.xpadding);
				if ( adjust ) { rptr->y += adjust; flowchartModelLayout( rptr ); }
				position.y = rptr->y;
				position.h = 0; position.w = 0;
				flowchartModelBest( rptr, &position,(level+1) );
				if ( position.h > rptr->h ) { 
					adjust +=(position.h - rptr->h); 
					}
				}
			}
		zptr->h += adjust;	
		flowchartModelLayout( mptr );
		return(0);
		}
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r B e s t (bptr) 	*/
/*	-------------------------------------------------	*/
int	flowchartEditorBest(struct visual_flowchart_model * bptr)
{
	struct visual_flowchart_model * mptr=(struct visual_flowchart *) 0;

	struct style_zone		position;

	/* Reset all best layout control variables */
	/* --------------------------------------- */
	for (	mptr=VFE.first;
		mptr != (struct visual_flowchart *) 0;
		mptr = mptr->next) {
		mptr->users=mptr->done=mptr->by=0;
		}

	/* initialise position */
	/* ------------------- */
	databaseZoneReset( &position );


	/* printf("\r\nStart of Flowchart Best Positioning\r\n"); */
	/* printf("***********************************\r\n"); */

	if ( bptr ) {
		bptr->x = VFE.xpadding;
		bptr->y = VFE.ypadding;
		bptr->by = bptr->number;

		position.x = (bptr->x + bptr->w + VFE.xpadding);
		position.y = bptr->y;
		position.h = 0; position.w = 0;

		/* calculate best and descendants */
		/* ------------------------------ */
		flowchartModelBest( bptr, &position,0 );

		if ( position.h  < (bptr->h + VFE.ypadding)) {
			position.h = bptr->h + VFE.ypadding;
			}

		}

	/* detect and handle unused models */
	/* ------------------------------- */
	for (	mptr=VFE.first;
		mptr != (struct visual_flowchart *) 0;
		mptr = mptr->next) {
		if ( mptr->done )
			continue;
		else	{
			position.y += position.h;
			mptr->y = position.y;
			mptr->x = VFE.xpadding;
			position.x = (mptr->x+mptr->w+VFE.xpadding);
			position.h = 0; position.w = 0;
			mptr->by = mptr->number;

			/* calculate best and descendants */
			/* ------------------------------ */
			flowchartModelBest( mptr, &position, 0 );
			
			if ( position.h  < (mptr->h + VFE.ypadding)) {
				position.h = mptr->h + VFE.ypadding;
				}
			}
		}
	flowchartEditorShow();
	return(0);
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r C h o o s e()  	*/
/*	-------------------------------------------------	*/
int	flowchartEditorChoose()
{
	struct visual_flowchart_model * mptr;
	struct visual_flowchart_model * bptr=(struct visual_flowchart *) 0;

	/* locate model with most outbound connections */
	/* ------------------------------------------- */
	for (	mptr=VFE.first;
		mptr != (struct visual_flowchart *) 0;
		mptr = mptr->next) {
		if (!( bptr ))
			bptr = mptr;
		else if ( mptr->members > bptr->members )
			bptr = mptr;
		mptr->done=mptr->by=0;
		}
	if (!( bptr ))
		return(0);
	else 	return( flowchartEditorBest( bptr ) );
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l M e n u ( model )  	*/
/*	-------------------------------------------------	*/
int	flowchartModelMenu(struct visual_flowchart_model * mptr)
{
	switch ( flowchart_model_menu() ) {
		case	_FORM_PARA 	:
			flowchartModelParameters(mptr);
			return(0x007F);
		case	_EDIT_FORM	:
			flowchartModelEditor(mptr);
			return(0x007F);
		case	_FLOW_DETAIL	:
			flowchartModelState(mptr);
			return(1);
		case	_FLOW_SIGHT 	:
			flowchartModelSight(mptr);
			return(1);
		case	_FLOW_SOLO	:
			flowchartModelSolo(mptr);
			return(1);
		case	_FLOW_BEST	: 
			flowchartEditorBest(mptr);	
			return(1);
		}
}

/*	--------------------------------------------------	*/
/*	 f l o w c h a r t E d i t W i d g e t ( model )  	*/
/*	--------------------------------------------------	*/
int	flowchartEditWidget(struct visual_flowchart_model * mptr)
{
	if ( mptr ) {
		edit_Widget( mptr->widget, mptr->widget->parent );
		}
	return(1);
}

/*	--------------------------------------------------	*/
/*	 f l o w c h a r t E d i t M e t h o d ( model )  	*/
/*	--------------------------------------------------	*/
int	flowchartEditMethod(struct visual_flowchart_model * mptr)
{
	if ( mptr ) {
		inspect_forms_method( mptr->method, 0);
		}
	return(1);
}

/*	--------------------------------------------------	*/
/*	 f l o w c h a r t W i d g e t M e n u ( model )  	*/
/*	--------------------------------------------------	*/
int	flowchartWidgetMenu(struct visual_flowchart_model * mptr)
{
	switch ( flowchart_widget_menu() ) {
		case	_FORM_PARA 	:
			flowchartEditWidget(mptr);
			return(0x007F);
		case	_FLOW_DETAIL	:
			flowchartModelState(mptr);
			return(1);
		case	_FLOW_SIGHT 	:
			flowchartModelSight(mptr);
			return(1);
		case	_FLOW_SOLO	:
			flowchartModelSolo(mptr);
			return(1);
		case	_FLOW_BEST	: 
			flowchartEditorBest(mptr);	
			return(1);
		}
}

/*	--------------------------------------------------	*/
/*	  f l o w c h a r t M e t h o d M e n u ( model )  	*/
/*	--------------------------------------------------	*/
int	flowchartMethodMenu(struct visual_flowchart_model * mptr)
{
	switch ( flowchart_method_menu() ) {
		case	_FORM_PARA 	:
			flowchartEditMethod(mptr);
			return(0x007F);
		case	_FLOW_DETAIL	:
			flowchartModelState(mptr);
			return(1);
		case	_FLOW_SIGHT 	:
			flowchartModelSight(mptr);
			return(1);
		case	_FLOW_SOLO	:
			flowchartModelSolo(mptr);
			return(1);
		case	_FLOW_BEST	: 
			flowchartEditorBest(mptr);	
			return(1);
		}
}

/*	-------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l E v e n t ( m, x, y ) 	*/
/*	-------------------------------------------------	*/
int	flowchartModelEvent(struct visual_flowchart_model * mptr, int x, int y )
{
	int	status;
	int	event;
	int	mx;
	int	my;
	int	mb=0;
	struct	visual_flowchart_member * xptr;
	if (!( mptr ))
		return(0);
	else if ( mptr->inhibit )	
		return(0);
	else if ( x < mptr->x )
		return(0);
	else if (y < mptr->y)
		return(0);
	else if (x > (mptr->x+mptr->w))
		return(0);
	else if (y > (mptr->y+mptr->h))
		return(0);
	else	{
		for (	xptr = mptr->first;
			xptr != (struct visual_flowchart_member *) 0;
			xptr = xptr->next ) {
			if (!( status = flowchartMemberEvent( xptr, x, y ) ))
				continue;
			else if ( status != 0x007F ){
				if (!( xptr->focus )) {
					mptr->oldfocus = mptr->current;
					mptr->current  = xptr;
					}
				return(1);
				}
			else	{
				return((VFE.outofdate=1));
				}
			}
		if ( visual_event(1) != _MIMO_DOWN )
			return( 1 );
		mb = visual_event(2);
		while (1) {
			if ( mb == _MIMO_LEFT ) {
				if (!( mptr->lock )) {
					flowchartHelpShow("move the file model to the required position and then release the mouse button",
						(char *) 0);
					}
				}
			xorzone((mptr->x-VFE.xmargin)+VFE.x,(mptr->y-VFE.ymargin)+VFE.y,mptr->w,mptr->h,2007);
			while ((event = visual_getch()) != 256);
			xorzone((mptr->x-VFE.xmargin)+VFE.x,(mptr->y-VFE.ymargin)+VFE.y,mptr->w,mptr->h,2007);
			if (!( mptr->lock )) {
				if ( mb == _MIMO_LEFT ) {
					flowchartHelpHide();
					mx = ((visual_event(7) - VFE.x) + VFE.xmargin);
					my = ((visual_event(6) - VFE.y) + VFE.ymargin);
					mptr->x += (mx -x); x = mx;
					mptr->y += (my -y); y = my;
					}
				}
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		if ( mb == _MIMO_RIGHT ) {
			flowchartModelPrompt(mptr);
			if ( mptr->widget )
				return( flowchartWidgetMenu(mptr) );
			else if ( mptr->method )
				return( flowchartMethodMenu(mptr) );
			else	return( flowchartModelMenu(mptr) );
			}
		else if ( mb == _MIMO_LEFT ) {
			flowchartModelLayout(mptr);
			flowchartEditorShow();
			flowchartModelPrompt(mptr);
			}
		return(1);
		}
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t M o d e l A d d M e m b e r(mptr) 	*/
/*	------------------------------------------------	*/
struct	visual_flowchart_member * flowchartModelAddMember(struct visual_flowchart_model * mptr, struct form_item * iptr , struct form_control * ffptr )
{
	char	*	nptr;
	struct	visual_flowchart_member * xptr=(struct	visual_flowchart_member *) 0;
	if (!( mptr ))
		return(xptr);
	else if (!( iptr ))
		return(xptr);
	else if (!( nptr = iptr->Contents.name ))
		return(xptr);
	else if (!( xptr = flowchartMemberCreate()))
		return(xptr);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "NULL Widget")))) {
		flowchartModelRemove( xptr );
		return(xptr);
		}
	else	{
		xptr->widget = iptr;
		xptr->target = ffptr;
		if (!( xptr->previous = mptr->last ))
			mptr->current = mptr->first = xptr;
		else	xptr->previous->next = xptr;
		mptr->last = xptr;		
		if (!( xptr->previous ))
			xptr->number=1;
		else	xptr->number = (xptr->previous->number+1);
		xptr->parent = mptr;
		mptr->members++;
		return(xptr);
		}
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t M o d e l A d d M e m b e r(mptr) 	*/
/*	------------------------------------------------	*/
struct	visual_flowchart_member * flowchartModelAddModel(
		struct visual_flowchart_model * mptr, 
		struct visual_flowchart_model * tptr )
{
	char	*	nptr;
	struct	visual_flowchart_member * xptr=(struct	visual_flowchart_member *) 0;
	if (!( mptr ))
		return(xptr);
	else if (!( tptr ))
		return(xptr);
	else if (!( nptr = tptr->name ))
		return(xptr);
	else if (!( xptr = flowchartMemberCreate()))
		return(xptr);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "NULL Widget")))) {
		flowchartModelRemove( xptr );
		return(xptr);
		}
	else	{
		if (!( xptr->previous = mptr->last ))
			mptr->current = mptr->first = xptr;
		else	xptr->previous->next = xptr;
		mptr->last = xptr;		
		if (!( xptr->previous ))
			xptr->number=1;
		else	xptr->number = (xptr->previous->number+1);
		xptr->parent = mptr;
		mptr->members++;
		xptr->detail = tptr;
		return(xptr);
		}
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t M o d e l A d d M e t h o d(mptr) 	*/
/*	------------------------------------------------	*/
struct	visual_flowchart_member * flowchartModelAddMethod(struct visual_flowchart_model * mptr, struct forms_method * wptr , struct form_control * ffptr )
{
	char	*	nptr;
	struct	visual_flowchart_member * xptr=(struct	visual_flowchart_member *) 0;
	if (!( mptr ))
		return(xptr);
	else if (!( wptr ))
		return(xptr);
	else if (!( nptr = wptr->name ))
		return(xptr);
	else if (!( xptr = flowchartMemberCreate()))
		return(xptr);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "NULL Widget")))) {
		flowchartModelRemove( xptr );
		return(xptr);
		}
	else	{
		xptr->method = wptr;
		xptr->target = ffptr;
		if (!( xptr->previous = mptr->last ))
			mptr->current = mptr->first = xptr;
		else	xptr->previous->next = xptr;
		mptr->last = xptr;		
		if (!( xptr->previous ))
			xptr->number=1;
		else	xptr->number = (xptr->previous->number+1);
		xptr->parent = mptr;
		mptr->members++;
		return(xptr);
		}
}

/*	-------------------------------------------------	*/
/*	    f l o w c h a r t W i d g e t T e s t ()		*/
/*	-------------------------------------------------	*/
int	flowchartWidgetTest(struct form_item * iptr,int control )
{
	if (!( iptr ))
		return(0);

	switch ((iptr->Contents.style &_FRAME_TYPE)) {

		case	_DATA_FRAME	:
			if (!( control & 1 ))
				return(0);
			/* component widget controls form */
			if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			&&  ( iptr->Contents.datatype != _WIDGET_IFRAME  )
			&&  ( iptr->Contents.datatype != _WIDGET_CLASS   )
			&&  ( iptr->Contents.datatype != _WIDGET_MODULE  )
			&&  ( iptr->Contents.datatype != _WIDGET_POINTER ))
				return(0);
			else	return(1);

		case	_TAB_FRAME	:
		case	_BUTTON_FRAME	:
			if (!( control & 2 ))
				return(0);
			/* trigger widget causes on event activation */
			if (( iptr->Contents.datatype != _WIDGET_OVERLAY  )
			&&  ( iptr->Contents.datatype != _WIDGET_IFRAME   )
			&&  ( iptr->Contents.datatype != _WIDGET_HYPERLINK)
			&&  ( iptr->Contents.datatype != _WIDGET_CHAIN    )
			&&  ( iptr->Contents.datatype != _WIDGET_MODULE   )
			&&  ( iptr->Contents.datatype != _WIDGET_LOADGO   ))
				return(0);
			else	return(2);
		}
	return(0);
}


/*	-------------------------------------------------	*/
/*	    f l o w c h a r t M o d e l W i d g e t ()		*/
/*	-------------------------------------------------	*/
int	flowchartModelWidget(struct visual_flowchart_model * mptr, struct form_item * iptr, int control )
{
	struct	form_control * ffptr;

	if (!( iptr ))
		return(0);

	switch ((iptr->Contents.style &_FRAME_TYPE)) {

		case	_DATA_FRAME	:
			if (!( control & 1 ))
				break;
			/* component widget controls form */
			if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
			&&  ( iptr->Contents.datatype != _WIDGET_IFRAME  )
			&&  ( iptr->Contents.datatype != _WIDGET_CLASS   )
			&&  ( iptr->Contents.datatype != _WIDGET_MODULE  )
			&&  ( iptr->Contents.datatype != _WIDGET_POINTER ))
				break;
			else if (!( ffptr = locate_form_control( abal_payload(iptr) ))) { 
				flowchartModelAddMember( mptr, iptr, ffptr );
				return(1);
				}
			else 	{
				flowchartModelAddMember( mptr, iptr, ffptr );
				return(1);
				}
		case	_TAB_FRAME	:
		case	_BUTTON_FRAME	:
			if (!( control & 2 ))
				break;
			/* trigger widget causes on event activation */
			if (( iptr->Contents.datatype != _WIDGET_OVERLAY  )
			&&  ( iptr->Contents.datatype != _WIDGET_IFRAME   )
			&&  ( iptr->Contents.datatype != _WIDGET_HYPERLINK)
			&&  ( iptr->Contents.datatype != _WIDGET_CHAIN    )
			&&  ( iptr->Contents.datatype != _WIDGET_MODULE   )
			&&  ( iptr->Contents.datatype != _WIDGET_LOADGO   ))
				break;
			else if (!( ffptr = locate_form_control( iptr->Contents.format ))) {
				flowchartModelAddMember( mptr, iptr, ffptr );
				return(1);
				}
			else 	{
				flowchartModelAddMember( mptr, iptr, ffptr );
				return(1);
				break;
				}
		}
	return(0);
}

/*	---------------------------------------------------	*/
/*	f l o w c h a r t M o d e l L o a d M e m b e r s()	*/
/*	---------------------------------------------------	*/
void	flowchartModelLoadMembers(struct visual_flowchart_model * mptr )
{
	struct	form_item * iptr;
	struct	form_control * fptr;
	if (!( mptr ))
		return;
	else if (!( fptr = mptr->form ))
		return;
	for (	iptr = fptr->first; 
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		flowchartModelWidget( mptr, iptr, 3 );
		}
	return;
}

/*	---------------------------------------------------	*/
/*	f l o w c h a r t M o d e l D r o p M e m b e r s()	*/
/*	---------------------------------------------------	*/
void	flowchartModelDropMembers(struct visual_flowchart_model * mptr )
{
	struct	visual_flowchart_member  * xptr;
	while ((xptr = mptr->first) != (struct visual_flowchart_member  *) 0) {
		mptr->first =  xptr->next;
		flowchartMemberRemove( xptr );
		}
	mptr->first = mptr->last = mptr->current = xptr;
	return;
}

/*	------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l R e m o v e ( mptr ) 	*/
/*	------------------------------------------------	*/
struct visual_flowchart_model * flowchartModelRemove(struct visual_flowchart_model * mptr )
{
	if (!( mptr ))	return;
	flowchartModelDropMembers( mptr );
	if ( mptr->name ) {
		liberate( mptr->name );
		}
	if (( mptr->form ) && (!( mptr->nosave ))) {
		mptr->form->x = mptr->x;
		mptr->form->y = (mptr->y-mptr->base);
		mptr->form->flow = ((mptr->state << 1) | mptr->lock);
		form_is_outofdate( mptr->form );
		}
	liberate( mptr );
	return;
}

/*	------------------------------------------------	*/
/*	 f l o w c h a r t M o d e l C r e a t e (      ) 	*/
/*	------------------------------------------------	*/
struct visual_flowchart_member * flowchartModelCreate()
{
	struct visual_flowchart_model * mptr;
	if ((mptr = allocate( sizeof( struct visual_flowchart_model ) )) != (struct visual_flowchart_model *) 0) {
		mptr->previous = mptr->next = (struct visual_flowchart_model *) 0;
		mptr->oldfocus = mptr->first = mptr->current = mptr->last = (struct visual_flowchart_member *) 0;
		mptr->x = mptr->y = mptr->w = mptr->h = 0;
		mptr->form = (struct form_control *) 0; 
		mptr->method = (struct forms_method *) 0; 
		mptr->widget = (struct form_item *) 0; 
		mptr->name = (char *) 0;
		databaseZoneReset(&mptr->icon);
		mptr->base = 0;
		mptr->hash = -1;
		mptr->users = mptr->members = 0;
		mptr->inhibit = 0;
		mptr->lock= 0;
		mptr->state= 0;
		mptr->focus=0;
		mptr->msize = 
		mptr->total =
		mptr->isize = 0;
		mptr->done=0;
		mptr->by=0;
		mptr->nosave=0;
		mptr->number=1;
		}
	return( mptr );
}

/*	--------------------------------------------------	*/
/*	f l o w c h a r t M o d e l I s V i s i b l e (mptr)   	*/
/*	--------------------------------------------------	*/
int	flowchartModelIsVisible(struct visual_flowchart_model * mptr )
{
	if (!( mptr ))	
		return(0);
	else if ( mptr->inhibit )	
		return(0);
	else	return(1);
	if (( mptr->x < VFE.xmargin ) ||  ( mptr->x > (VFE.xmargin+VFE.w)))
		return(0);
	else if (( (mptr->x+mptr->w) < VFE.xmargin ) ||  (( mptr->x+ mptr->w) > (VFE.xmargin+VFE.w)))
		return(0);
	else if (( mptr->y < VFE.ymargin ) ||  ( mptr->y > (VFE.ymargin+VFE.h)))
		return(0);
	else if (( (mptr->y+mptr->h) < VFE.ymargin ) ||  (( mptr->y+ mptr->h) > (VFE.ymargin+VFE.h)))
		return(0);
	else	return(1);
}

/*	--------------------------------------------------	*/
/*	  f l o w c h a r t M o d e l I m a g e ( mptr )       	*/
/*	--------------------------------------------------	*/
void	flowchartModelImage(struct visual_flowchart_model * mptr)
{
	struct	form_control * fptr;
	if (!( mptr ))
		return;
	else if (!( fptr = mptr->form ))
		return;
	else if (!( fptr->image ))
		return;
	else if (!( mptr->state & 2 )) {
		drawimage(	mptr->x+(VFE.iconpadd/2),mptr->y,
				mptr->icon.w, mptr->icon.h,
				fptr->image,_I_BESTFIT);
		return;
		}	
	else	{
		drawimage(	mptr->x,mptr->y,
				mptr->w, mptr->h,
				fptr->image,_I_BESTFIT);
		return;
		}	
}
/*	--------------------------------------------------	*/
/*	f l o w c h a r t M o d e l L o s e F o c u s (mptr)   	*/
/*	--------------------------------------------------	*/
void	flowchartModelLoseFocus(struct visual_flowchart_model * mptr, int mode )
{
	if (!( mptr ))
		return;
	else if ( mptr->inhibit )
		return;
	else	{
		if ( mode ) 
			flowchartEditorStart();

		if ( VFE.images ) {
			(void) visual_element( mptr->x+mptr->icon.w+VFE.iconpadd,mptr->y,
				mptr->w-(mptr->icon.w+VFE.iconpadd),mptr->h,_STYLE_FLOWCHART_HEADER, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));
			flowchartModelImage( mptr );
			}
		else	{
			(void) visual_element( mptr->x,mptr->y,
				mptr->w,mptr->h,_STYLE_FLOWCHART_HEADER, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));
			}
		mptr->focus=0;
		if (!( mptr->state  ))
			flowchartMemberLoseFocus(mptr->current);

		if ( mode )
			flowchartEditorFlush();
		}
	return;
}

/*	------------------------------------------------	*/
/*	f l o w c h a r t M o d e l G e t F o c u s (mptr)   	*/
/*	------------------------------------------------	*/
void	flowchartModelGetFocus(struct visual_flowchart_model * mptr )
{
	if (!( mptr ))
		return;
	else if ( mptr->inhibit )
		return;
	else	{
		flowchartEditorStart();
		if (!( mptr->focus )) {
			flowchartModelLoseFocus(VFE.current, 0);
			if ( VFE.images ) {
				(void) visual_element( mptr->x+mptr->icon.w+VFE.iconpadd,mptr->y,
					mptr->w-(mptr->icon.w+VFE.iconpadd),mptr->h,_STYLE_FLOWCHART_FOCUS, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));
				flowchartModelImage( mptr );
				}
			else	{
				(void) visual_element( mptr->x,mptr->y,
					mptr->w,mptr->h,_STYLE_FLOWCHART_FOCUS, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));
				}
			mptr->focus=1;
			}
		if (!( mptr->state )) {
			flowchartMemberLoseFocus(mptr->oldfocus);
			flowchartMemberGetFocus(mptr->current);
			}
		flowchartEditorFlush();
		VFE.current = mptr;
		}
	return;
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l S h o w ( mptr )   	*/
/*	------------------------------------------------	*/
void	flowchartModelShow(struct visual_flowchart_model * mptr )
{
	struct	visual_flowchart_member  * xptr;

	/* Avoid display of inhibited Models */
	/* --------------------------------- */
	if (!( mptr ))		return;
	if ( mptr->inhibit )	return;
	
	visual_element( mptr->x,mptr->y,mptr->w,mptr->h,_STYLE_FLOWCHART_MODEL_TRAY, " " , 0 );
	visual_element( mptr->x,mptr->y,mptr->w,mptr->h,_STYLE_FLOWCHART_MODEL, " " , 0 );

	flowchartModelLoseFocus( mptr, 0 );

	if (!( mptr->state )) {	
		for (	xptr = mptr->first;
			xptr != (struct visual_flowchart_member *) 0;
			xptr = xptr->next ) {
			flowchartMemberShow( xptr );
			}
		}
	return;
}

/*	---------------------------------------------------------------		*/
/*	   f l o w c h a r t M o d e l S h o w R e l a t i o n s ( mptr )   	*/
/*	---------------------------------------------------------------		*/
void	flowchartModelShowRelations(struct visual_flowchart_model * mptr )
{
	struct	visual_flowchart_member  * xptr;
	if (!( mptr ))	return;
	for (	xptr = mptr->first;
		xptr != (struct visual_flowchart_member *) 0;
		xptr = xptr->next ) {
		flowchartMemberShowRelations( xptr );
		}
	return;
}

/*	---------------------------------------------------	*/
/*	     f l o w c h a r t M o d e l P r o m p t()		*/
/*	---------------------------------------------------	*/
void	flowchartModelPrompt( struct visual_flowchart_model  * xptr )
{
	if (!( xptr ))
		return;
	else if (!( xptr->name ))
		return;
	else	{
		status_message( xptr->name ,2);
		}
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l F o c u s ( mptr )		*/
/*	-------------------------------------------------	*/
int	flowchartModelFocus(struct visual_flowchart_model * mptr)
{
	int	event;
	mouse_move_on();
	event = visual_getch();
	mouse_move_off();
	return( event );
}

/*	-------------------------------------------------	*/
/*	   f l o w c h a r t M o d e l S i z e s ( mptr )		*/
/*	-------------------------------------------------	*/
int	flowchartModelSizes(struct visual_flowchart_model * mptr)
{
	struct	form_control * fptr;
	struct	visual_flowchart_member  * xptr;
	int	swaper;
	int	maxlen=0;
	int	maxhig=0;
	int	mbmhig=0;
	int	mbmlen=0;
	if (!( mptr ))
		return(0);
	else if (!( mptr->name ))
		maxlen = 0;
	else if (!( maxlen = flowchartTextWidth( mptr->name, _STYLE_FLOWCHART_HEADER, 0 ) )) {
		mbmhig = maxhig = 0;
		}
	else	{
		if ((maxhig = flowchartTextHeight(  mptr->name, _STYLE_FLOWCHART_MEMBER, 0 )) < 20)
			maxhig = 20;
		if ((mbmhig = flowchartTextHeight(  mptr->name, _STYLE_FLOWCHART_MEMBER, 0 )) < 20)
			mbmhig = 20;
		}

	mptr->isize = mptr->msize = (maxhig + 5); 
	mptr->icon.h = mptr->icon.w = maxhig;

	for (	xptr = mptr->first;
		xptr != (struct visual_flowchart_member *) 0;
		xptr = xptr->next ) {
		if ((mbmlen = flowchartMemberTextWidth( xptr, _STYLE_FLOWCHART_MEMBER, 0 )) > maxlen)
			maxlen = mbmlen;
		maxhig += mbmhig;
		}

	mptr->h = maxhig+5;
	mptr->total = mptr->h;
	mptr->w = (maxlen + 30);
	mptr->w += (mptr->icon.w + VFE.iconpadd);

	if (( fptr = mptr->form ) != (struct form_control *) 0) { 
		if ( fptr->image != (struct standard_image *) 0) {
			mptr->isize = ((mptr->w * fptr->image->rows)/ fptr->image->columns);
			}
		}
	flowchartModelHeight(mptr);
	return(0);
}


/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E   E D I T O R   M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	------------------------------------------------	*/
/*	    f l o w c h a r t D r o p I m a g e  ( ) 	   	*/
/*	------------------------------------------------	*/
void	flowchartDropImage()
{
	if ( VFE.image ) {
		VFE.image->storage = (STDPSUPTR) 0;
		VFE.image = local_drop_image( VFE.image );
		}
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t B u i l d I m a g e  ( ) 	   	*/
/*	------------------------------------------------	*/
void	flowchartBuildImage()
{
	if (!( VFE.image = local_allocate_image( 0, 0, 0, 0 )))
		return;
	else	{
		VFE.image->storage = VFE.buffer.value;
		VFE.image->rows    = VFE.buffer.height;
		VFE.image->columns = VFE.buffer.width;
		VFE.image->format = get_pixel_size();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r C h e c k ( )    	*/
/*	------------------------------------------------	*/
int	flowchartEditorCheck()
{
	if ( VFE.buffer.width < VFE.w )
		VFE.buffer.width = VFE.w;
	if ( VFE.buffer.height < VFE.h )
		VFE.buffer.height = VFE.h;

	if (( VFE.buffer.width  != VFE.buffer.x )
	||  ( VFE.buffer.height != VFE.buffer.y )) {
		if ( VFE.buffer.value ) {
			flowchartDropImage();
			VFE.buffer.value = liberate_pixel_storage( VFE.buffer.value );
			}
		if (!( VFE.buffer.value = allocate_graphic_storage( 
			0,0, (VFE.buffer.x = VFE.buffer.width), 
			     (VFE.buffer.y = VFE.buffer.height)) ))
			return(27);
		flowchartBuildImage();
		}
	if (!( VFE.buffer.value ))
		return(118);
	else	return(0);
}

/*	--------------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r A d d M o d e l ( )    	*/
/*	--------------------------------------------------------	*/
struct	visual_flowchart_model  * flowchartEditorAddModel(char * nptr)
{
	struct	visual_flowchart_model  * mptr;
	if (!( mptr = flowchartModelCreate()))
		return((struct	visual_flowchart_model  *)0);
	else if (!( mptr->name = allocate_string(( nptr ? nptr : "NULL Model")))) {
		flowchartModelRemove( mptr );
		return((struct	visual_flowchart_model  *)0);
		}
	else	{
		if (!( mptr->previous = VFE.last ))
			VFE.current = VFE.first = mptr;
		else	mptr->previous->next = mptr;
		VFE.last = mptr;		
		if ( mptr->previous )
			mptr->number += mptr->previous->number;
		return(mptr);
		}
}

/*	--------------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r A d d M o d e l ( )    	*/
/*	--------------------------------------------------------	*/
struct	visual_flowchart_model  * flowchartEditorTestAddModel(char * nptr)
{
	struct	visual_flowchart_model  * mptr;
	if (!( mptr = flowchartModelLocate( nptr )))
		mptr = flowchartEditorAddModel( nptr );
	return( mptr );
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r R e m o v e ( )  	*/
/*	------------------------------------------------	*/
int	flowchartEditorRemove()
{
	struct	visual_flowchart_model  * mptr;
	while ((mptr = VFE.first) != (struct visual_flowchart_model  *) 0) {
		VFE.first = mptr->next;
		flowchartModelRemove( mptr );
		}
	flowchartDropImage();
	VFE.solo = VFE.first = VFE.current = VFE.last = (struct visual_flowchart_model *) 0;
	return(0);
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r L a y o u t ( )  	*/
/*	------------------------------------------------	*/
int	flowchartEditorLayout()
{
	int	my=0;
	int	x=VFE.xpadding;
	int	y=VFE.ypadding+30;
	int	nb=0;
	int	rowheight=0;
	struct	visual_flowchart_model  * mptr;

	if (!( y = flowchartTextHeight(VFE.title,_STYLE_FLOWCHART_TITLE,0) ))
		y =  VFE.ypadding;
	else	y += VFE.ypadding;

	VFE.x = Context.DeskTop.x;
	VFE.y = Context.DeskTop.y;
	VFE.w = Context.DeskTop.w;
	VFE.h = Context.DeskTop.h;

	VFE.buffer.width = 0;
	VFE.buffer.height= 0;

	for (	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		flowchartModelSizes(mptr);
		}
	for (	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {

		if (( mptr->x == -1 )
		||  ( mptr->y == -1 )) {
		
			mptr->x = x; 
			mptr->y = y;
			if ((x + mptr->w + VFE.xpadding) > VFE.w) {
				x = VFE.xpadding;
				y += ( rowheight + VFE.ypadding);
				rowheight=mptr->h;
				}
			else if ((mptr->x+mptr->w) > (VFE.x + VFE.w)) {
				x = VFE.xpadding;
				mptr->x = VFE.xpadding;
				y += ( rowheight + VFE.ypadding);
				mptr->y = y;
				rowheight=mptr->h;
				}
			else	{
				x += (mptr->w + VFE.xpadding);
				if ( mptr->h > rowheight ) {
				rowheight = mptr->h;
				}
				}
			}
		flowchartModelLayout(mptr);

		}
	return(0);
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r D e f a u lt ( )  	*/
/*	------------------------------------------------	*/
void	flowchartEditorDefault()
{
	char	*	eptr;
	VFE.hyperspace	 = 1;
	VFE.fraction	 = 4;
	VFE.bubblehelp	 = 1;

	VFE.bender	 = 2;
	VFE.tracewidth	 = 3;
	VFE.tracecolour	 = 1;

	VFE.xpadding 	 = 100;
	VFE.ypadding 	 = 50;
	VFE.tracepadding = 50;
	VFE.depth 	 = 50;
	VFE.stylename	 = (char*) 0;
	
	if (( eptr = getenv( "SING_DEBUG_ROUTER" )) != (char *) 0)
		VFE.debug_trace_route = atoi( eptr );
	else	VFE.debug_trace_route = 0;
	return;
}

/*	---------------------------------------------	*/
/*	f l o w c h a r t E d i t o r L i b e r a t e()  	*/
/*	---------------------------------------------	*/
int	flowchartEditorLiberate()
{
	if ( VFE.copied_member ) {
		VFE.copied_member = flowchartMemberRemove( VFE.copied_member );
		}
	if ( VFE.copied_model ) {
		VFE.copied_model = flowchartModelRemove( VFE.copied_model );
		}
	if ( VFE.stylename ) {
		VFE.stylename = liberate( VFE.stylename );
		}
	return;
}

/*	-----------------------------------------------		*/
/*	   f l o w c h a r t E d i t o r S c h e m a()  	*/
/*	-----------------------------------------------		*/
void	flowchartEditorSchema( int mode )
{
	if ( VFE.schema != mode ) {

		switch ((VFE.schema=mode)) {

			case	_SCHEMA_SING	:
				load_visual_style( _SCHEMA_SING_STYLE, strlen(_SCHEMA_SING_STYLE) );
				break;

			case	_SCHEMA_MERISE	:
				load_visual_style( _SCHEMA_MERISE_STYLE, strlen(_SCHEMA_MERISE_STYLE) );
				break;

			case	_SCHEMA_UML	:
				load_visual_style( _SCHEMA_UML_STYLE, strlen(_SCHEMA_UML_STYLE) );
				break;

			}

		}	
	return;
}

/*	--------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r R e s e t ( )  	*/
/*	--------------------------------------------	*/
int	flowchartEditorInitialise()
{

	if ( Context.Camera )
		VFE.inhibit = 1;
	else	VFE.inhibit = 0;

	VFE.hypersave.w = VFE.hypersave.h = VFE.hypersave.y = VFE.hypersave.x = 0;
	VFE.sbh = VFE.sbw = 0;
	VFE.xmargin 	  = 0; 
	VFE.ymargin 	  = 0;
	VFE.copied_member = (struct visual_flowchart_member *) 0;
	VFE.copied_model  = (struct visual_flowchart_model  *) 0;
	VFE.schema = 0;
	VFE.images = 1;
	VFE.iconpadd = 10;
	flowchartEditorSchema(_SCHEMA_MERISE);
	return;
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r P r o j e c t()  	*/
/*	------------------------------------------------	*/
void	flowchartEditorProject( struct camera3d * cptr, struct style_zone * zptr )
{
	struct	visual_flowchart_model  * mptr;
	struct form_control 		* fptr;
	struct object3d 		* optr;
	int				status;
	if (!( cptr ))
		return;
	for ( 	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		if ( optr->nature != __3D_FORM )
			continue;
		else if (!( fptr = optr->payload))
			continue;

		/* Validate both classname and identity */
		/* ------------------------------------ */
		if (!( fptr->identifier  ))
			continue;

		if (!(mptr = flowchartEditorAddModel(fptr->identifier)))
			break;
		else 	{
			mptr->form = fptr;
			mptr->x = fptr->x;
			mptr->base = zptr->y;
			mptr->y = fptr->y + zptr->y;
			mptr->state = 0;
			mptr->lock  = (fptr->flow & 1 ? 1 : 0);
			if ( fptr->flow & 2 )
				mptr->state |= 1;
			if ( fptr->flow & 4 )
				mptr->state |= 2;
			flowchartModelLoadMembers( mptr ); 
			if (( mptr->y+mptr->h ) > zptr->h )
				zptr->h = (mptr->y + mptr->h);
			}
		}
	return;
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r C r e a t e ( )  	*/
/*	------------------------------------------------	*/
int	flowchartEditorCreate()
{
	int	i;
	int	status=0;
	VFE.solo = VFE.first = VFE.current = VFE.last = (struct visual_flowchart_model *) 0;
	VFE.x = VFE.y = VFE.w = VFE.h =0;
	VFE.buffer.width  = 0;
	VFE.buffer.height = 0;
	VFE.buffer.x 	  = 0;
	VFE.buffer.y 	  = 0;
	VFE.buffer.value  = (STDPSUPTR) 0;
	VFE.image	  = (struct standard_image *) 0;
	VFE.outofdate 	  = 0;

	if ( Context.Form ) {
		flowchartEditorForm( Context.Form );
		flowchartEditorLayout();
		flowchartEditorBest( VFE.first );
		}
	else	{
		flowchartEditorCamera();
		flowchartEditorLayout();
		}
	return(0);
}


/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r C a m e r a ( )  	*/
/*	------------------------------------------------	*/
void	flowchartEditorCamera()
{
	struct camera3d * cptr;
	char *	eptr;
	struct	style_zone viewport;
	databaseZoneReset(&viewport);
	if (( VFE.title = Context.Camera->name ) != (char *) 0)
		status_message(VFE.title,2);

	if ( VFE.inhibit ) {
		flowchartEditorProject( Context.Camera, &viewport );
		}
	else	{
		/* For all forms in the Project Manager */
		/* ------------------------------------ */
		for (	cptr = first_camera();
			cptr != (struct camera3d *) 0;
			cptr = mynext_camera(cptr) ) {
			flowchartEditorProject( cptr, &viewport );
			if ( viewport.h > viewport.y )
				viewport.y = viewport.h;
			}
		}
	return;
}

/*	--------------------------------------------------------	*/
/*	 f l o w c h a r t C a l c u l a t e H y p e r V i e w()	*/
/*	--------------------------------------------------------	*/
void	flowchartCalculateHyperCursor()
{
	VFE.hypercursor.w = ((VFE.hyperview.w * VFE.w) / VFE.buffer.width);
	VFE.hypercursor.h = ((VFE.hyperview.h * VFE.h) / VFE.buffer.height);
	VFE.hypercursor.x = VFE.hyperview.x+((VFE.hyperview.w * VFE.xmargin) / VFE.buffer.width);
	VFE.hypercursor.y = VFE.hyperview.y+((VFE.hyperview.h * VFE.ymargin) / VFE.buffer.height);
	return;
}

/*	------------------------------------------------	*/
/*	     f l o w c h a r t H y p e r V i e w  ()	    	*/
/*	------------------------------------------------	*/
void	flowchartHyperView()
{
	if (!( VFE.image ))
		return;
	else if (!( VFE.image->storage ))
		return;
	else	{
		visual_element(VFE.hyperzone.x,VFE.hyperzone.y,VFE.hyperzone.w,VFE.hyperzone.h,_STYLE_FLOWCHART_HYPERVIEW_TRAY," ",1);
		visual_element(VFE.hyperzone.x,VFE.hyperzone.y,VFE.hyperzone.w,VFE.hyperzone.h,_STYLE_FLOWCHART_HYPERVIEW_FRAME," ",1);
		drawimage     (VFE.hyperview.x,VFE.hyperview.y,VFE.hyperview.w,VFE.hyperview.h,VFE.image,_I_MAKEFIT);
		visual_element(VFE.hypercursor.x,VFE.hypercursor.y,VFE.hypercursor.w,VFE.hypercursor.h,_STYLE_FLOWCHART_HYPERVIEW_CROSS," ",1);
		visual_element(VFE.hypercursor.x,VFE.hypercursor.y,VFE.hypercursor.w,VFE.hypercursor.h,_STYLE_FLOWCHART_HYPERVIEW_ZOOM," ",1);
		}
}

/*	------------------------------------------------------------		*/
/*	 f l o w c h a r t H y p e r V i e w C u r s o r E v e n t ()	    	*/
/*	-----------------------------------------------------------		*/
int	flowchartHyperViewCursorEvent(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	if ( x < VFE.hypercursor.x )
		return(0);
	else if ( y <= VFE.hypercursor.y )
		return(0);
	else if ( x > (VFE.hypercursor.x+VFE.hypercursor.w) )
		return(0);
	else if ( y > (VFE.hypercursor.y+VFE.hypercursor.h) )
		return(0);
	else if ( visual_event(1) != _MIMO_DOWN )
		return(0);
	else	{
		mb = visual_event(2);	
		mouse_move_on();
		while (1) {
			while ( visual_getch() != 256 );
			mx = visual_event(7);
			my = visual_event(6);
			VFE.hypercursor.x += (mx -x); x = mx;
			VFE.hypercursor.y += (my -y); y = my;
			if ( VFE.hypercursor.x < VFE.hyperview.x )
				VFE.hypercursor.x = VFE.hyperview.x;
			else if ( (VFE.hypercursor.x+VFE.hypercursor.w) > (VFE.hyperview.x+VFE.hyperview.w))
				VFE.hypercursor.x = ((VFE.hyperview.x+VFE.hyperview.w)-VFE.hypercursor.w);
			if ( VFE.hypercursor.y < VFE.hyperview.y )
				VFE.hypercursor.y = VFE.hyperview.y;
			else if ((VFE.hypercursor.y+VFE.hypercursor.h) > (VFE.hyperview.y+VFE.hyperview.h))
				VFE.hypercursor.y = ((VFE.hyperview.y+VFE.hyperview.h)-VFE.hypercursor.h);
			VFE.xmargin = ((VFE.buffer.width*(VFE.hypercursor.x-VFE.hyperview.x))/VFE.hyperview.w);
			VFE.ymargin = ((VFE.buffer.height*(VFE.hypercursor.y-VFE.hyperview.y))/VFE.hyperview.h);
			VFE.hyperspace = 0;
			visual_freeze();
			flowchartEditorRefresh();
			flowchartHyperView();
			visual_thaw(VFE.hyperzone.x,VFE.hyperzone.y,VFE.hyperzone.w,VFE.hyperzone.h);
			VFE.hyperspace = 1;
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		mouse_move_off();
		return(1);
		}
}

/*	-------------------------------------------------------		*/
/*	 f l o w c h a r t H y p e r V i e w Z o n e E v e n t ()	    	*/
/*	-------------------------------------------------------		*/
int	flowchartHyperViewZoneEvent(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	if ( x < VFE.hyperview.x )
		return(0);
	else if ( y <= VFE.hyperview.y )
		return(0);
	else if ( x > (VFE.hyperview.x+VFE.hyperview.w) )
		return(0);
	else if ( y > (VFE.hyperview.y+VFE.hyperview.h) )
		return(0);
	else if ( visual_event(1) != _MIMO_DOWN )
		return(0);
	else	{
		mb = visual_event(2);	
		mouse_move_on();
		while (1) {
			while ( visual_getch() != 256 );
			mx = visual_event(7);
			my = visual_event(6);
			VFE.hyperzone.x += (mx -x); x = mx;
			if ( VFE.hyperzone.x < VFE.x )
				VFE.hyperzone.x = VFE.x;
			else if ((VFE.hyperzone.x+VFE.hyperzone.w) > (VFE.x+VFE.w))
				VFE.hyperzone.x = (VFE.x + (VFE.w-VFE.hyperzone.w));
			VFE.hyperzone.y += (my -y); y = my;
			if ( VFE.hyperzone.y < VFE.y )
				VFE.hyperzone.y = VFE.y;
			else if ((VFE.hyperzone.y+VFE.hyperzone.h) > (VFE.y+VFE.h))
				VFE.hyperzone.y = (VFE.y + (VFE.h-VFE.hyperzone.h));
			flowchartCalculateHyperView();
		//	VFE.hyperspace = 0;
		//	visual_freeze();
			flowchartEditorRefresh();
		//	flowchartHyperView();
		//	visual_thaw(VFE.hyperzone.x,VFE.hyperzone.y,VFE.hyperzone.w,VFE.hyperzone.h);
		//	VFE.hyperspace = 1;
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		mouse_move_off();
		return(1);
		}
}

/*	------------------------------------------------	*/
/*	 f l o w c h a r t H y p e r V i e w E v e n t ()	    	*/
/*	------------------------------------------------	*/
int	flowchartHyperViewEvent(int x, int y)
{
	if (!( VFE.hyperspace ))
		return(0);
	else if ( flowchartHyperViewCursorEvent(x,y) )
		return(1);
	else if ( flowchartHyperViewZoneEvent(x,y) )
		return(1);
	else	return(0);
}

/*	--------------------------------------------------------	*/
/*	 f l o w c h a r t C a l c u l a t e H y p e r V i e w()	    	*/
/*	--------------------------------------------------------	*/
void	flowchartCalculateHyperView()
{
	VFE.hyperview.x = VFE.hyperzone.x + 5;
	VFE.hyperview.y = VFE.hyperzone.y + 5;
	VFE.hyperview.w = VFE.hyperzone.w - 10;
	VFE.hyperview.h = VFE.hyperzone.h - 10;
	return;
}

/*	--------------------------------------------------------	*/
/*	 f l o w c h a r t C a l c u l a t e H y p e r Z o n e()	    	*/
/*	--------------------------------------------------------	*/
void	flowchartCalculateHyperZone()
{
	if (( VFE.hypersave.w == VFE.w ) 
	&&  ( VFE.hypersave.h == VFE.h )
	&&  ( VFE.hypersave.y == VFE.y )
	&&  ( VFE.hypersave.x == VFE.x )
	&&  ( VFE.buffer.height== VFE.sbh )
	&&  ( VFE.buffer.width == VFE.sbw ))
		return;

	VFE.hypersave.w = VFE.w; VFE.hypersave.h = VFE.h;
	VFE.hypersave.y = VFE.y; VFE.hypersave.x = VFE.x;
	VFE.sbh = VFE.buffer.height;
	VFE.sbw = VFE.buffer.width;

	if ( VFE.buffer.height > VFE.buffer.width ) {
		VFE.hyperzone.h = (VFE.h/VFE.fraction)+10;
		VFE.hyperzone.w = ((VFE.hyperzone.h * VFE.buffer.width)/VFE.buffer.height)+10;
		}
	else	{
		VFE.hyperzone.w = (VFE.w / VFE.fraction)+10;
		VFE.hyperzone.h = ((VFE.hyperzone.w * VFE.buffer.height)/VFE.buffer.width)+10;
		}
	VFE.hyperzone.x = VFE.x + (VFE.w - VFE.hyperzone.w);
	VFE.hyperzone.y = VFE.y;
	flowchartCalculateHyperView();
	return;
}

/*	------------------------------------------------	*/
/*	  f l o w c h a r t E d i t o r R e f r e s h ()    	*/
/*	------------------------------------------------	*/
void	flowchartEditorRefresh()
{
	int	pixelsize=get_pixel_size();
	int	r;
	char *	bptr;

	if (( VFE.xmargin + VFE.w ) > VFE.buffer.width )
		VFE.xmargin = (VFE.buffer.width - VFE.w);
	else if ( VFE.xmargin < 0 ) 
		VFE.xmargin = 0;
	if (( VFE.ymargin + VFE.h ) > VFE.buffer.height)
		VFE.ymargin = (VFE.buffer.height - VFE.h);
	else if ( VFE.ymargin < 0 ) 
		VFE.ymargin = 0;

	visual_freeze();
	for ( r=0; r < VFE.h; r++ ) {
		if (!( bptr = connect_pixel_row( VFE.buffer.value, r+VFE.ymargin )))
			break;
		else	putzone(VFE.x,VFE.y+r,VFE.w,1,(bptr+(VFE.xmargin*pixelsize)));
		}

	if ( VFE.hyperspace ) {
		flowchartCalculateHyperZone();
		flowchartCalculateHyperCursor();
		flowchartHyperView();
		}

	visual_thaw( VFE.x, VFE.y, VFE.w, VFE.h );
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r S t a r t ( )    	*/
/*	------------------------------------------------	*/
int	flowchartEditorStart()
{
	VFE.x = 0;
	VFE.y = 0;

	/* Allocate Screen Buffer and Establish */
	/* ------------------------------------ */
	if (!( flowchartEditorCheck() )) {
		background_pixel_capture( VFE.buffer.value );
		}
	return;
}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r F l u s h ( )    	*/
/*	------------------------------------------------	*/
int	flowchartEditorFlush()
{
	/* Disactive Screen Buffer */
	/* ----------------------- */
	if ( VFE.buffer.value ) {
		cancel_pixel_capture( VFE.buffer.value );
		}

	VFE.x = Context.DeskTop.x;
	VFE.y = Context.DeskTop.y;

	/* Display the Screen Buffer */
	/* ------------------------- */
	flowchartEditorRefresh();
	
	return;
}

/*	------------------------------------------------	*/
/*	     f l o w c h a r t E d i t o r S h o w ( )    	*/
/*	------------------------------------------------	*/
int	flowchartEditorShow()
{
	struct	visual_flowchart_model  * mptr;

	VFE.w = Context.DeskTop.w;
	VFE.h = Context.DeskTop.h;

	flowchartEditorStart();

	/* display with style if required and possible */
	/* ------------------------------------------- */
	if ( visual_element( VFE.x,VFE.y,VFE.buffer.width,VFE.buffer.height,_STYLE_FLOWCHART_FRAME, "  ",0) ) {

		/* Reset Zone otherwise */
		/* -------------------- */
		filzone	(
			VFE.x,VFE.y,
			VFE.buffer.width,VFE.buffer.height,
			_DEFAULT_GUI_NEUTRAL);
		}

	(void ) visual_element( VFE.x,VFE.y,VFE.buffer.width,VFE.buffer.height,_STYLE_FLOWCHART_TITLE, VFE.title, strlen( VFE.title ));

	/* Detect and Display Solo Relations */
	/* --------------------------------- */
	/* Display the various Database Relations */
	/* -------------------------------------- */
	for (	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->state & 1 ))
			flowchartModelShowRelations(mptr);
		}

	/* Display the various Database File Models */
	/* ---------------------------------------- */
	for (	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		flowchartModelShow(mptr);
		}

	flowchartEditorFlush();

	return(0);
}

/*	------------------------------------------------	*/
/*	     f l o w c h a r t E d i t o r H i d e ( )    	*/
/*	------------------------------------------------	*/
int	flowchartEditorHide()
{
	return(0);
}


/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r M o v e ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorMove(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	int	event;
	while (1) {
		while ((event = visual_getch()) != 256);
		mx = visual_event(7);
		my = visual_event(6);
		VFE.xmargin += (x - mx); x = mx;
		VFE.ymargin += (y - my); y = my;
		flowchartEditorRefresh();
		if ( visual_event(1) == _MIMO_UP ) break;
		}
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r R e s e t() 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorReset()
{
	struct	visual_flowchart_model  * mptr;
	if (!( VFE.inhibit )) {
		status_message("cannot be performed on multiple projects",2);
		return;
		}
	for (	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->lock )) {
			mptr->x = mptr->y = -1;
			}
		}
	VFE.outofdate = 2;
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r I n f o ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorInfo()
{
	if ( accept_database_control(
		&VFE.hyperspace,
		&VFE.bubblehelp,
		&VFE.bender,
		&VFE.tracewidth,
		&VFE.tracecolour,
		&VFE.depth,
		&VFE.tracepadding,	
		&VFE.xpadding,
		&VFE.ypadding,
		&VFE.fraction,
		&VFE.schema ) != 27 ) {
		flowchartEditorRefresh();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r H e l p ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorHelp()
{
	if (!( VFE.bubblehelp = ((VFE.bubblehelp + 1) & 1) ))
		status_message("help bubble messages : OFF",2);
	else	status_message("help bubble messages : ON",2);
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r T r a c e ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorTrace()
{
	VFE.bender += 1;
	if ( VFE.bender > 2 )
		VFE.bender = 0;
	switch ( VFE.bender ) {
		case	0 :
			status_message("diagonal trace routing : ON",2);
			break;
		case	1 :
			status_message("simple   trace routing : ON",2);
			break;
		case	2 :
			status_message("complex  trace routing : ON",2);
			break;
		}
	VFE.outofdate=1;
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r H y p e r ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorHyper()
{
	if (!( VFE.hyperspace = ((VFE.hyperspace + 1) & 1) )) 
		status_message("hyperspace navigator : OFF",2);
	else	status_message("hyperspace navigator : ON",2);
	VFE.outofdate=1;
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r F i l e ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorFile()
{
	int	i,l;
	char	workbuffer[512];
	memset(workbuffer,' ',256);
	visual_frame(	VFE.x, VFE.y, VFE.w, 32, _EDIT_FRAME );
	visual_text (	VFE.x+5, VFE.y+2, 100, 30, Context.menufont, 16,0, "Classname:",10,3);
	if ( visual_edit( 
			VFE.x+120,VFE.y+2,300,30,
			Context.basefont,
			workbuffer, 255 ) == 27) {
		flowchartEditorRefresh();
		}
	else	{
		limit_right_space( workbuffer, 256);
		AddFileClass((void*)0,	_MCFILE_FRAME ,workbuffer,"noname","filename"," ");
		VFE.outofdate=2;
		}
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r S o l o ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorSolo()
{
	if (!( VFE.solo )) {
		if ( VFE.current )
			flowchartModelSolo( VFE.current );
		}
	else	{
		VFE.solo = (struct visual_flowchart_model *) 0;
		flowchartEditorShow();
		}
	return;
}

/*	------------------------------------------------	*/
/*	  f l o w c h a r t E d i t o r I n h i b i t ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorInhibit()
{
	if (!( Context.Camera ))
		VFE.inhibit = 0;
	else	{
		VFE.inhibit = ((VFE.inhibit + 1) & 1);
		}
	if ( VFE.inhibit ) 
		status_message("displaying project flowchart",2);
	else	status_message("displaying all flowcharts",2);
	flowchartEditorRebuild();

	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r P a s t e (x,y)		*/
/*	------------------------------------------------	*/
void	flowchartModelPaste(int emx,int emy)
{
	struct	visual_flowchart_model * mptr;
	struct	visual_flowchart_member * aptr;
	struct	visual_flowchart_relation * rptr;
	struct	file_control * fptr;
	struct	file_control * duplicate_file_control(void *, struct	file_control *  );
	if (!( VFE.copied_model ))
		return;
	else if (!( mptr = flowchartModelCopy( VFE.copied_model )))
		return;
	else	{
		if (!(mptr->previous = VFE.last))
			VFE.first = mptr;
		else	mptr->previous->next = mptr;
		VFE.last = mptr;
		mptr->x = emx;
		mptr->y = emy;
#ifdef	OOUCH
		if ((mptr->file = duplicate_file_control((void *) 0, VFE.copied_model->file )) != (struct file_control *) 0)
			mptr->form = mptr->file->payload;
		else	mptr->form = (struct form_control *) 0;
		if ( mptr->name ) {
			mptr->name = liberate( mptr->name );
			mptr->name = allocate_string( mptr->file->classname );
			}
		for (	aptr=mptr->first;
			aptr != (struct visual_flowchart_member*) 0;
			aptr = aptr->next ) {
			for (	rptr=aptr->first;
				rptr != (struct visual_flowchart_relation*) 0;
				rptr = aptr->next ) {
				flowchartRelationSave( rptr );
				}
			}
#endif
		flowchartModelLayout(mptr);
		flowchartEditorShow();
		}
	return;
}

/*	------------------------------------------------------- 	*/
/*	    f l o w c h a r t E d i t o r R e f r e s h ( ) 	  	*/
/*	------------------------------------------------------- 	*/
void	flowchartEditorRebuild()
{
	flowchartEditorRemove();
	flowchartEditorCreate();
	flowchartEditorShow();
	return;
}

/*	------------------------------------------------------- 	*/
/*	    f l o w c h a r t E d i t o r S t y l e ( ) 	  	*/
/*	------------------------------------------------------- 	*/
int	flowchartEditorStyle()
{
	struct	form_control * fptr;
	struct	visual_flowchart_model * mptr;
	int	mode=0;
	if ( accept_css_filename( &VFE.stylename, &mode ) == 27 )
		return( 257 );
	else	{
		for (	mptr=VFE.first;
			mptr != (struct visual_flowchart_model *) 0;
			mptr = mptr->next ) {
			if (!( fptr = mptr->form ))
				continue;
			if ( fptr->stylesheet )
				liberate( fptr->stylesheet );
			if (!( fptr->stylesheet = allocate_string( VFE.stylename ) ))
				break;
			else	{
				draw_Form( fptr,0 );
				form_Image( fptr,0 );
				}
			}
		flowchartEditorShow();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t S a v e I m a g e ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartSaveImage()
{
	char *	tempname;
	if (!( VFE.image ))
		return;
	else if (!( tempname = allocate_string("flowchart.gif") ))
		return;
	else	{
		SetPathSelection( system_imagepath );
		if ( accept_imagesave(
				&tempname, 
				&Context.imagepathitem,
				&Context.imageformat, 
				&Context.transparent ) == 27 ) {
			tempname = liberate( tempname );
			return;
			}
		else if (!( tempname = UsePathSelection( tempname, Context.imagepathitem ) ))
			return;
		else	{
			image_save(tempname,VFE.image,QUICK);
			tempname = liberate( tempname );
			return;
			}
		}
}
/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r M e n u ( ) 	  	*/
/*	------------------------------------------------	*/
void	flowchartEditorMenu()
{
	int	emx = ((visual_event(7) - VFE.x) + VFE.xmargin);
	int	emy = ((visual_event(6) - VFE.y) + VFE.ymargin);
	switch ( flowchart_main_menu() ) {
		case	_FLOW_STYLE	: flowchartEditorStyle();		break;
		case	_FLOW_RESET	: flowchartEditorReset();		break;
		case	_FLOW_INFO	: flowchartEditorInfo();		break;
		case	_FLOW_HELP	: flowchartEditorHelp();		break;
		case	_FLOW_ADD	: flowchartEditorFile();		break;
		case	_FLOW_TRACE	: flowchartEditorTrace();		break;
		case	_FLOW_HYPER	: flowchartEditorHyper();		break;
		case	_FLOW_INHIBIT	: flowchartEditorInhibit();		break;
		case	_FORM_MODEL_PASTE : flowchartModelPaste(emx,emy);	break;
		case	_FLOW_SOLO	: flowchartEditorSolo();		break;
		case	_FLOW_BEST	: flowchartEditorChoose();		break;
		case	_FLOW_SCREEN	: flowchartEditorRebuild();		break;
		case	_FLOW_IMAGE	: flowchartSaveImage();			break;
		case	_FLOW_DETAIL	: flowchartEditorDetail();		break;
		case	_FLOW_SIGHT 	: flowchartEditorSight();		break;
		}
	return;
}

/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r E v e n t ( )    	*/
/*	------------------------------------------------	*/
int	flowchartEditorEvent(int x, int y)
{
	int	status;
	struct	visual_flowchart_model  * mptr;
	if (( x < Context.DeskTop.x )
	||  ( y < Context.DeskTop.y )
	||  ( x > (Context.DeskTop.x+Context.DeskTop.w))
	||  ( y > (Context.DeskTop.y+Context.DeskTop.h)))
		return( -1 );
	else if ( flowchartHyperViewEvent(x,y) )
		return(256);
	else	{
		switch ( visual_event(2) ) {
			case	_MIMO_WHEELUP	:
				VFE.ymargin -= 10;
				flowchartEditorRefresh();
				return(256);
			case	_MIMO_WHEELDOWN	:
				VFE.ymargin += 10;
				flowchartEditorRefresh();
				return(256);
			default			:

				for (	mptr = VFE.first;
					mptr != (struct visual_flowchart_model *) 0;
					mptr = mptr->next ) {
					if (!(status = flowchartModelEvent(mptr, (x-VFE.x)+VFE.xmargin, (y-VFE.y)+VFE.ymargin ) )) {
						if (!( status = flowchartModelRelationEvent( mptr, (x-VFE.x)+VFE.xmargin, (y-VFE.y)+VFE.ymargin ) ))
							continue;
						else if ( status != 0x007F )
							return(256);
						else	return(256);
						}
					else if ( status == 257 )
						return( status );
					else if (( status != 0x007F )) {
						flowchartModelGetFocus(mptr);
						return( 256 );
						}		
					else	{
						return( 256 );
						}
					}
			
				switch ( visual_event(2) ) {
					case	_MIMO_LEFT	:
						if ( visual_event(1) == _MIMO_DOWN )
							flowchartEditorMove(x,y);
						break;
					case	_MIMO_RIGHT	:
						if ( visual_event(1) == _MIMO_UP ) {
							flowchartEditorMenu();
							return(257);
							}
					}
				return( 256 );
			}
		}

}

/*	------------------------------------------------	*/
/*	   f l o w c h a r t E d i t o r A l e r t ( )  	*/
/*	------------------------------------------------	*/
int	flowchartEditorAlert(int number)
{
	char *	message="\0";
	switch ( number ) {
		case	1 : message = "incorrect recursive relation"; break;
		case	2 : message = "unexpected error"; break;
		}
	return( flowchart_editor_failure( message ) );	
}

/*	------------------------------------------------	*/
/*	      f l o w c h a r t G e t T o k e n ()		*/
/*	------------------------------------------------	*/
private	char * flowchartGetToken(char * cptr, char * tptr, int tlen)
{
	int	i=0;
	*tptr = 0;
	while (i < tlen) {
		if (( *cptr >= 'A') && ( *cptr <= 'Z')) {
			*(tptr+i) = *(cptr++);
			i++;
			}
		else if (( *cptr >= 'a') && ( *cptr <= 'z')) {
			*(tptr+i) = *(cptr++);
			i++;
			}
		else if (( *cptr >= '0') && ( *cptr <= '9')) {
			*(tptr+i) = *(cptr++);
			i++;
			}
		else if ( *cptr == '_') {
			*(tptr+i) = *(cptr++);
			i++;
			}
		else	break;
		}
	*(tptr+i) = 0;
	return( cptr );
}

/*	------------------------------------------------	*/
/*	     f l o w c h a r t W h i t e S p a c e()		*/
/*	------------------------------------------------	*/
private	char * flowchartWhiteSpace(char * cptr)
{
	if (!( cptr )) return( cptr );
	while (1) {
		switch ( *cptr )	{
			case	' '	:
			case	'\t'	:
			case	'\r'	:
			case	'\n'	:
				break;
			case	0	:
				return((char *) 0);
			default		:
				return( cptr );
			}
		cptr++;
		}
}

/*	---------------------------------------------------	*/
/*	f l o w c h a r t W i d g e t I n v o c a t i o n()	*/ 
/*	---------------------------------------------------	*/
int	flowchartWidgetInvocation(struct visual_flowchart_model * mptr, struct form_item * iptr, char * token, int keyword )
{
	struct	visual_flowchart_member * xptr;
	struct	visual_flowchart_model * rptr;
	char	*	cptr;
	char	mname[512];
	if (!( mptr ))
		return(0);
	else if (!( iptr ))
		return(0);
	else if (!( token ))
		return(0);
	else	{
		sprintf(mname,"%s.%s",iptr->Contents.name,token);
		if (( xptr = flowchartMemberLocate( mptr, mname )) != (struct visual_flowchart_member *) 0)
			return(0);
		else if (!( xptr = flowchartModelAddMember( mptr, iptr, (struct form_control *) 0)))
			return( 0 );
		if ( xptr->name ) 
			liberate( xptr->name );
		if (!( xptr->name = allocate_string( mname ) ))
			return(0);
		if ((rptr = flowchartModelLocate( mname )) != (struct visual_flowchart_model *) 0) {
			xptr->detail = rptr;
			return(0);
			}
		else if (!( mptr = flowchartEditorAddModel(mname)))
			return(27);
		else	{
			mptr->users++;
			mptr->nosave=1;
			mptr->widget = iptr;
			xptr->detail = mptr;
			switch ( keyword ) {
				case	VISUAL_MEMBER_CREATE	:
					if ( method_is_valid((cptr = iptr->Contents.events->on_create)))
						flowchartMethodParse(mptr,iptr->parent,cptr);
					break;
				case	VISUAL_MEMBER_SHOW	:
					if ( method_is_valid((cptr = iptr->Contents.events->on_show)))
						flowchartMethodParse(mptr,iptr->parent,cptr);
					break;
				case	VISUAL_MEMBER_GETFOCUS	:
					if ( method_is_valid((cptr = iptr->Contents.events->on_get_focus)))
						flowchartMethodParse(mptr,iptr->parent,cptr);
					break;
				case	VISUAL_MEMBER_EVENT	:
					if ( method_is_valid((cptr = iptr->Contents.events->on_event)))
						flowchartMethodParse(mptr,iptr->parent,cptr);
					break;
				case	VISUAL_MEMBER_LOSEFOCUS	:
					if ( method_is_valid((cptr = iptr->Contents.events->on_lose_focus)))
						flowchartMethodParse(mptr,iptr->parent,cptr);
					break;
				case	VISUAL_MEMBER_HIDE	:
					if ( method_is_valid((cptr = iptr->Contents.events->on_hide)))
						flowchartMethodParse(mptr,iptr->parent,cptr);
					break;
				case	VISUAL_MEMBER_REMOVE	:
					if ( method_is_valid((cptr = iptr->Contents.events->on_remove)))
						flowchartMethodParse(mptr,iptr->parent,cptr);
					break;
				}
			return(0);
			}
		}
	return(0);
}
	
/*	---------------------------------------------------	*/
/*	   f l o w c h a r t W i d g e t L o c a t e ()		*/
/*	---------------------------------------------------	*/
struct	form_item * flowchartWidgetLocate(struct form_control * fptr, char * token, struct form_item * iptr )
{
	struct	form_item * wptr;
	int	h;
	if (!( token )) 
		return((struct form_item *) 0);
	else if (!( fptr ))
		return((struct form_item *) 0);
	else if ( iptr )
		if (!( strcmp( token, "this" ) ))
			return( iptr );
	h = flowchartHash(token);
	for ( 	wptr=fptr->first;
		wptr != (struct form_item *) 0;
		wptr = wptr->next ) {
		if (!( wptr->Contents.name ))
			continue;
		else if ( wptr->Contents.hash == -1 )
			wptr->Contents.hash = flowchartHash( wptr->Contents.name );
		if ( wptr->Contents.hash != h )
			continue;
		else if (!( strcmp( wptr->Contents.name, token ) ))
			break;
		}
	return( wptr) ;
}

/*	---------------------------------------------------	*/
/*	f l o w c h a r t M e t h o d I n v o c a t i o n()	*/ 
/*	---------------------------------------------------	*/
int	flowchartMethodInvocation(struct visual_flowchart_model * mptr, struct forms_method * wptr, struct form_control * fptr )
{
	char * cptr;
	struct	visual_flowchart_member * xptr;
	struct	visual_flowchart_model * rptr;
	char	mname[512];
	if (!( mptr ))
		return(0);
	else if (!( wptr ))
		return(0);
	else	{
		if (( xptr = flowchartMemberLocate( mptr, wptr->name )) != (struct visual_flowchart_member *) 0)
			return(0);
		else if (!( xptr = flowchartModelAddMethod( mptr, wptr, (struct form_control *) 0)))
			return( 0 );
		if (!( xptr->name = allocate_string( wptr->name ) ))
			return(0);
		if ((rptr = flowchartModelLocate( wptr->name )) != (struct visual_flowchart_model *) 0) {
			xptr->detail = rptr;
			return(0);
			}
		else if (!( mptr = flowchartEditorAddModel(wptr->name)))
			return(27);
		else	{
			mptr->users++;
			mptr->nosave=1;
			mptr->method = wptr;
			xptr->detail = mptr;
			if (!( method_is_valid((cptr = wptr->text)) ))	
				return(0);
			return( flowchartMethodParse( mptr, fptr, cptr ) );
			}
		}
	return(0);
}
	
/*	---------------------------------------------------	*/
/*	   f l o w c h a r t M e t h o d L o c a t e ()		*/
/*	---------------------------------------------------	*/
struct forms_method * flowchartMethodLocate(struct form_control * fptr, char * token )
{
	struct forms_method *	mptr;
	int	h;
	h = flowchartHash(token);
	for ( 	mptr = fptr->rootmethod;
		mptr != (struct forms_method *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if ( mptr->hash == -1 )
			mptr->hash = flowchartHash( mptr->name );
		if ( mptr->hash != h )
			continue;
		else if (!( strcmp( mptr->name, token ) ))
			break;
		}
	return( mptr ) ;
}

/*	---------------------------------------------------------	*/
/*	f l o w c h a r t I n t e r f a c e I n v o c a t i o n()	*/ 
/*	---------------------------------------------------------	*/
void	flowchartInterfaceInvocation(
		struct visual_flowchart_model  * mptr,
		struct form_control * fptr,
		char * token )
{
	int	keyword=0;
	struct 	visual_flowchart_model  * tptr;
	struct	visual_flowchart_member * xptr;
	if (!( mptr ))
		return(0);
	else if (!( token ))
		return(0);
	else if (!( fptr ))
		return(0);
	else if (( keyword = is_visual_member( token, 1 )) < MAX_VISUAL_PROPERTY)
		return(0);

	switch( keyword ) {
		case	VISUAL_MEMBER_ONEVENT 	:
		case	VISUAL_MEMBER_ONSHOW	:
		case	VISUAL_MEMBER_ONHIDE	:
		case	VISUAL_MEMBER_ONFOCUS 	:
		case	VISUAL_MEMBER_ONCREATE 	:
		case	VISUAL_MEMBER_ONREMOVE 	:
			break;
		default				:
			return(0);
		}

	if (!( tptr = flowchartModelLocate( token ) )) {
		if (!( tptr = flowchartEditorAddModel(token)))
			return(0);
		else	{
			tptr->form = fptr;
			tptr->nosave=1;
			}
		}

	if (( xptr = flowchartMemberLocate( mptr, tptr->name )) != (struct visual_flowchart_member *) 0)
		return(0);

	else if (!( xptr = flowchartModelAddModel( mptr, tptr ) ))
		return( 0 );
	else	{
		xptr->detail = tptr;
		mptr->nosave=1;
		return(0);
		}
}

/*	---------------------------------------------------	*/
/*	     f l o w c h a r t M e t h o d P a r s e()		*/
/*	---------------------------------------------------	*/
int	flowchartMethodParse(
	struct visual_flowchart_model * mptr,
	struct form_control * fptr,
	char * cptr )
{
	struct visual_flowchart_model * rptr;
	struct	forms_method * pptr;
	struct	form_item * wptr;
	char	token[512];
	int	keyword=0;
	int	c;
	while (( cptr != (char *) 0) && ( *cptr != 0)) {
		
		if (!( cptr = flowchartWhiteSpace(cptr)))
			break;
		else if (!( cptr = flowchartGetToken(cptr,token, 511) ))
			break;
		else if (!( token[0] ))
			cptr++;		
		else if (!( wptr = flowchartWidgetLocate(fptr,token,mptr->widget) )) {
			if (!( pptr = flowchartMethodLocate( fptr, token ) )) {
				flowchartInterfaceInvocation(mptr,fptr,token );
				}
			else	flowchartMethodInvocation(mptr,pptr,fptr);
			}
		else if ((c = *(cptr++)) != '.' )
			continue;
		else if (!( cptr = flowchartGetToken(cptr,token,511) ))
			break;
		else if (!( token[0] ))
			cptr++;	
		else if (( keyword = is_visual_member( token, 1 )) < MAX_VISUAL_PROPERTY)
			continue;
		else	flowchartWidgetInvocation(mptr,wptr,token,keyword);
		}
	return(0);
}

/*	---------------------------------------------------	*/
/*	     f l o w c h a r t W i d g e t M e t h o d 		*/
/*	---------------------------------------------------	*/
int	flowchartWidgetMethod(struct visual_flowchart_model * mptr, struct form_item * iptr, char * cptr )
{
	struct	form_control * fptr;
	struct	forms_method * pptr;
	struct	form_item * wptr;
	char	token[512];
	int	keyword=0;
	int	c;
	if (!( cptr ))
		return(0);
	else if (!( mptr ))
		return(0);
	else if (!( iptr ))
		return(0);
	else if (!( iptr->parent ))
		return(0);
	else	return( flowchartMethodParse(mptr,iptr->parent,cptr) );
}

/*	---------------------------------------------------	*/
/*	  f l o w c h a r t M o d e l F o r m M e m b e r	*/
/*	---------------------------------------------------	*/
int	flowchartModelFormMember(struct visual_flowchart_model * mptr, struct form_item * iptr, char * cptr, int control )
{
	char	mname[512];
	struct	visual_flowchart_model * rptr=(struct	visual_flowchart_model *) 0;
	struct	visual_flowchart_member * xptr;
	int	status;
	if (!( mptr ))
		return(0);
	else	mptr->nosave = 1;
	if (!( mptr->form = iptr->parent ))
		return(0);
	if (!( xptr = flowchartModelAddMember( mptr, iptr, (struct form_control *) 0)))
		return( 0 );
	else if (!( mptr->name ))
		return(0);
	else if (!( iptr->Contents.name))
		return(0);
	else	{
		/* build widget method name ( removing the 'On' ) */
		/* ---------------------------------------------- */
		sprintf(mname,"%s.%s",iptr->Contents.name,(mptr->name+2));
		if ((rptr = flowchartModelLocate( mname )) != (struct visual_flowchart_model *) 0) {
			xptr->detail = rptr;
			return(0);
			}
		else if (!( mptr = flowchartEditorAddModel(mname)))
			return(27);
		else	{
			mptr->users++;
			mptr->nosave=1;
			mptr->widget = iptr;
			xptr->detail = mptr;
			if (!( cptr ))
				return(0);
			else	{
				flowchartWidgetMethod(mptr,iptr,cptr);
				if ( flowchartWidgetTest( iptr, control ) )
					flowchartModelWidget(mptr, iptr, control );
				return(0);
				}
			}
		}
}

/*	-------------------------------------------	*/
/*	f l  o w c h a r t E d i t o r F o r m (f)	*/
/*	-------------------------------------------	*/
/*	Builds an internal method->method flowchart	*/
/*	for the indicatd forms model starting from	*/
/*	each forms interface method Create,Show etc	*/
/*	-------------------------------------------	*/
int	flowchartEditorForm( struct form_control * fptr )
{
	struct	visual_flowchart_model *	mptr;
	struct	visual_flowchart_member *	xptr;
	struct	form_item		*	iptr;
	char				*	cptr;
	int					status=0;

	if (!( fptr ))
		return(0);
	else if (( VFE.title = fptr->identifier ) != (char *) 0)
		status_message(VFE.title,2);

	/* ONCREATE */
	/* -------- */
	for (	mptr=(struct visual_flowchart_model *) 0, 
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid((cptr = iptr->Contents.events->on_create)) ))
			continue;
		if ((!( mptr )) && (!( mptr = flowchartEditorTestAddModel("OnCreate"))))
			return(27);
		else if ((status = flowchartModelFormMember(mptr, iptr, cptr, 0 )) != 0)
			return(status);
		}
	/* ONSHOW */
	/* ------ */
	for (	mptr=(struct visual_flowchart_model *) 0, 
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid((cptr = iptr->Contents.events->on_show)) ))
			continue;
		else if (iptr->Contents.events->xo_show & _EVENT_IS_COND )
			continue;
		if ((!( mptr )) && (!( mptr = flowchartEditorTestAddModel("OnShow"))))
			return(27);
		else if ((status = flowchartModelFormMember(mptr, iptr, cptr, 0 )) != 0)
			return(status);
		}
	/* ONFOCUS */
	/* ------- */
	for (	mptr=(struct visual_flowchart_model *) 0, 
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid((cptr =  iptr->Contents.events->on_get_focus)) ))
			continue;
		if ((!( mptr )) && (!( mptr = flowchartEditorTestAddModel("OnFocus"))))
			return(27);
		else if ((status = flowchartModelFormMember(mptr, iptr, cptr, 0 )) != 0)
			return(status);
		}
	/* ONEVENT */
	/* ------- */
	for (	mptr=(struct visual_flowchart_model *) 0, 
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid((cptr =  iptr->Contents.events->on_event)) ))
			continue;
		if ((!( mptr )) && (!( mptr = flowchartEditorTestAddModel("OnEvent"))))
			return(27);
		else if ((status = flowchartModelFormMember(mptr, iptr, cptr, 2 )) != 0)
			return(status);
		}
	/* ONLOSE */
	/* ------ */
	for (	mptr=(struct visual_flowchart_model *) 0, 
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid((cptr = iptr->Contents.events->on_lose_focus )) ))
			continue;
		else if (!( iptr->Contents.events->xo_lose_focus & _EVENT_IS_FOCUS ))
			continue;
		if ((!( mptr )) && (!( mptr = flowchartEditorTestAddModel("OnLoseFocus"))))
			return(27);
		else if ((status = flowchartModelFormMember(mptr, iptr, cptr, 0 )) != 0)
			return(status);
		}
	/* ONHIDE */
	/* ------ */
	for (	mptr=(struct visual_flowchart_model *) 0, 
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid((cptr =  iptr->Contents.events->on_hide )) ))
			continue;
		if ((!( mptr )) && (!( mptr = flowchartEditorTestAddModel("OnHide"))))
			return(27);
		else if ((status = flowchartModelFormMember(mptr, iptr, cptr, 0 )) != 0)
			return(status);
		}
	/* ONREMOVE */
	/* -------- */
	for (	mptr=(struct visual_flowchart_model *) 0, 
		iptr=fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if ((!( iptr->Contents.w  )) ||  (!( iptr->Contents.h  )))
			continue;
		else if (!( method_is_valid((cptr =  iptr->Contents.events->on_remove )) ))
			continue;
		if ((!( mptr )) && (!( mptr = flowchartEditorTestAddModel("OnRemove"))))
			return(27);
		else if ((status = flowchartModelFormMember(mptr, iptr, cptr, 0 )) != 0)
			return(status);
		}
	return(0);
}


/*	------------------------------------------------	*/
/*	    f l o w c h a r t E d i t o r F o c u s ( )    	*/
/*	------------------------------------------------	*/
int	flowchartEditorFocus()
{
	int	event;
	int	awctrue;
	while(1) {
		switch ( VFE.outofdate ) {
			case	2 :
				flowchartEditorRemove();
				flowchartEditorCreate();
			case	1 :
				flowchartEditorShow();
				VFE.outofdate = 0;
			}
		while ((event = flowchartModelFocus( VFE.current )) == 256) {
			if ((event = flowchartEditorEvent( visual_event(7), visual_event(6) )) == 256 )
				continue;
			else if ( event == 257 )
				break;
			else if ((event = handle_event()) == 256)
				continue;
			else	break;
			}
		switch ( event ) {
			case	 2		: /* HOME / END */
				if (!( VFE.current ))
					continue;
				else if ( VFE.current->next )
					VFE.current = VFE.last;
				else	VFE.current = VFE.first;
				continue;
	
			case	5		: /* NEXT 	FORM_MEMBER 	*/
				if (!( VFE.current ))
					continue;
				else if (!( VFE.current->current ))
					continue;
				else if (!( VFE.current->current->next ))
					continue;
				else 	{
					VFE.current->current = VFE.current->current->next;
					continue;
					}
				
			case	11		: /* PREVIOUS 	FORM_MEMBER 	*/
				if (!( VFE.current ))
					continue;
				else if (!( VFE.current->current ))
					continue;
				else if (!( VFE.current->current->previous ))
					continue;
				else 	{
					VFE.current->current = VFE.current->current->previous;
					continue;
					}
#ifdef	NONO
			case	 6		: /* NEXT 	MODEL 	*/
				if (!( VFE.current ))
					continue;
				else if ( VFE.current->next )
					VFE.current = VFE.current->next;
				continue;

			case	8		: /* PREVIOUS 	MODEL 	*/
				if (!( VFE.current ))
					continue;
				else if ( VFE.current->previous )
					VFE.current = VFE.current->previous;
				continue;
#endif
			case	0x0012		: /* PREVIOUS	PAGE  	*/
				if ( VFE.ymargin  > (VFE.h / 8 ))
					VFE.ymargin -= (VFE.h / 8);
				else	VFE.ymargin = 0;
				flowchartEditorRefresh();
				continue;

			case	0x0003		: /* NEXT	PAGE	*/
				VFE.ymargin += (VFE.h / 8);
				flowchartEditorRefresh();
				continue;

			case	0x0009		: /* Page Right */
				VFE.xmargin += (VFE.w / 4);
				flowchartEditorRefresh();
				continue;

			case	0x0000		: /* Page Left */
				VFE.xmargin -= (VFE.w / 4);
				flowchartEditorRefresh();
				continue;

			case	0x001C		: /* Home	*/
			case	0x000C		: /* Home	*/
				VFE.ymargin = 0;
				VFE.xmargin = 0;
				flowchartEditorRefresh();
				continue;

			case	0x000A		: /* New Line */
				VFE.xmargin = 0;
				flowchartEditorRefresh();
				continue;

			case	_FILE_SAVE	:
				if ( Context.Camera ) {
					flowchartEditorRemove();
					save_Camera(Context.Camera,0);
					flowchartEditorCreate();
					flowchartEditorShow();
					}
				continue;

			case	_FILE_QSAVE	:
				if ( Context.Camera ) {
					flowchartEditorRemove();
					save_Camera(Context.Camera,QUICK);
					flowchartEditorCreate();
					flowchartEditorShow();
					}
				continue;

			case	27		:
				event = _LEAVE_SING;

			case _SING_HELP		:
			case _SING_BASE		:
			case _EDIT_IMAGE	:	
			case _EDIT_TEXT 	:
			case _EDIT_FONT 	:
			case _EDIT_STYLE 	:
			case _EDIT_DEPEND 	:
			case _EDIT_FORM		:
			case _EDIT_DATAMODEL	:
			case _EDIT_DATABASE	:
			case _EDIT_TREEVIEW	:
			case _EDIT_GRAPH	:
			case _EXEC_PROG		:
			case _LEAVE_SING	:
				break;			
			case	257		:
			default	:
				continue;
			}
		break;
		}
	return( event );
}

/*	-------------------------------------------------	*/
/*		f l o w c h a r t _ e d i t o r ()		*/
/*	-------------------------------------------------	*/
int	flowchart_editor()
{
#ifdef	SING_MODEL_EDITOR
	int	event=0;
	char *	eptr;
	(void) set_context_dataview(2);
	flowchartEditorInitialise();
	flowchartEditorCreate();
	VFE.outofdate=1;
	event = flowchartEditorFocus();
	flowchartEditorHide();
	flowchartEditorRemove();
	flowchartEditorLiberate();
	(void) set_context_dataview(0);
	draw_console();
	return( event );
#else
	return(0);
#endif
}

/*	---------------------------------------------------	*/
/*	   f l o w c h a r t _ c o p i e d _ c l a s s 		*/
/*	---------------------------------------------------	*/
int	flowchart_copied_class()
{
	if ( VFE.copied_model )
		return(1);
	else	return(0);
}

/*	---------------------------------------------------	*/
/*	   f l o w c h a r t _ c o p i e d _ m e m b e r	*/
/*	---------------------------------------------------	*/
int	flowchart_copied_member()
{
	if ( VFE.copied_member )
		return(1);
	else	return(0);
}


#endif	/* _singfmed_c */
	/* ----------- */

