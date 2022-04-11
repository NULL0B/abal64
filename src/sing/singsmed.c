#ifndef	_singsmed_c
#define	_singsmed_c

#include "singsmed.h"
#include "singpars.h"
#include "guimouse.h"
extern	char * system_imagepath;

struct	visual_dependance_editor VSE = {

	(struct	visual_dependance_model  *) 0,	/* first   		*/
	(struct	visual_dependance_model  *) 0,	/* last	   		*/
	(struct	visual_dependance_model  *) 0,	/* current 		*/
	(struct	visual_dependance_model  *) 0,	/* solo	   		*/
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


struct visual_dependance_relation * dependanceRelationRemove( struct visual_dependance_relation * rptr );
struct visual_dependance_model * dependanceModelRemove(struct visual_dependance_model * mptr );
struct visual_dependance_model * dependanceModelCreate();
struct	visual_dependance_member * dependanceModelAddDependance(struct visual_dependance_model * mptr, char * nptr );
struct	visual_dependance_member * dependanceModelAddDependant(struct visual_dependance_model * mptr, char * nptr );
void	dependanceModelPrompt( struct visual_dependance_model  * xptr );
void	dependanceCalculateHyperView();
void	dependanceEditorRefresh();
void	dependanceEditorRebuild();
struct	visual_dependance_model * dependanceRelationDefine(int stmode);
struct visual_dependance_model * dependanceEditorChooseBest();
private	void	dependanceStyleGenerate(FILE * h, struct visual_dependance_model * mptr);

/*	----------------------------------------	*/
/*	 d e p e n d a n c e T r a c e L i n e   ()		*/
/*	----------------------------------------	*/
void	dependanceTraceLine( int sx, int sy, int tx, int ty )
{
	if ( sx == tx ) {
		if ( sy > ty ) {
			if ( visual_element( sx, ty, 1, (sy-ty), _STYLE_TRACE_NORTH, " ", 0) )
				visual_line(	sx,	sy,	tx,	ty, VSE.tracewidth, VSE.tracecolour );
			}
		else if ( visual_element( sx, sy, 1, (ty-sy), _STYLE_TRACE_SOUTH, " ", 0) )
			visual_line(	sx,	sy,	tx,	ty, VSE.tracewidth, VSE.tracecolour );
		}
	else	{
		if ( sx > tx ) {
			if ( visual_element( tx, sy, (sx-tx),1, _STYLE_TRACE_WEST, " ", 0) )
				visual_line(	sx,	sy,	tx,	ty, VSE.tracewidth, VSE.tracecolour );
			}
		else if ( visual_element( sx, sy, (tx-sx),1, _STYLE_TRACE_EAST, " ", 0) )
			visual_line(	sx,	sy,	tx,	ty, VSE.tracewidth, VSE.tracecolour );
		}
	return;
}

/*	--------------------------------------------		*/
/*	 d e p e n d a n c e T r a c e P o i n t ()		*/
/*	--------------------------------------------		*/
void	dependanceTracePoint( int sx, int sy )
{
	if ( visual_element( sx, sy, 1, 1, _STYLE_TRACE_POINT, " ", 0) )
		visual_line(	sx,	sy,	sx, sy, VSE.tracewidth, VSE.tracecolour );
	return;
}

/*	----------------------------------------	*/
/*	 d e p e n d a n c e H a s h ( sptr )		*/
/*	----------------------------------------	*/
int	dependanceHash( char * sptr )
{	
	int	h=0;
	if (!( sptr ))
		return(0);
	while ( *sptr ) h += *(sptr++); 
	return( (h % 2007) );
}
	
/*	------------------------------------------------	*/
/*	  d e p e n d a n c e T e x t W i d t h ( m, s, f ) 	*/
/*	------------------------------------------------	*/
int	dependanceTextWidth( char * message, char * style, int fid )
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
/*	d e p e n d a n c e T e x t H e i g h t ( m, s, f ) 	*/
/*	------------------------------------------------	*/
int	dependanceTextHeight( char * message, char * style, int fid )
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


/*	------------------------------------------	*/
/*	 d e p e n d a n c e H e l p S h o w (m,s) 	*/
/*	------------------------------------------	*/
void	dependanceHelpShow( char * mptr, char * sptr )
{
	VSE.bubble.x = visual_event(7);
	VSE.bubble.y = visual_event(6);
	if ( VSE.bubblehelp ) {
		VSE.bubble.w = 220; VSE.bubble.h = 120;
		}
	else if (!( sptr )) 
		return;
	else	{
		VSE.bubble.w = 20; VSE.bubble.h = 20;
		}
	if (!( VSE.bubblezone = visual_buffer(VSE.bubble.x,VSE.bubble.y,VSE.bubble.w,VSE.bubble.h) ))
		return;
	else	{
		visual_buffer_get(VSE.bubblezone, VSE.bubble.x, VSE.bubble.y );
		if ( sptr ) {
			visual_element(VSE.bubble.x,VSE.bubble.y, 
				10,15, sptr, " ", 0);
			}
		if ( VSE.bubblehelp ) {
			visual_element(VSE.bubble.x+20,VSE.bubble.y+20, 
				200, 100, _STYLE_BUBBLE_FRAME, mptr, strlen( mptr ));
			}
		return;
		}
}

/*	------------------------------------------	*/
/*	 d e p e n d a n c e H e l p H i d e (m,s) 	*/
/*	------------------------------------------	*/
void	dependanceHelpHide()
{
	if ( VSE.bubblezone ) {
		visual_buffer_put(VSE.bubblezone, VSE.bubble.x, VSE.bubble.y );
		visual_drop( VSE.bubblezone );
		VSE.bubblezone = (void *) 0;
		}
	return;
}


/*	--------------------------------------------------------	*/
/*									*/
/*	D E P E N D A N C E   R E L A T I O N   M E T H O D S		*/
/*									*/
/*	--------------------------------------------------------	*/
/*	--------------------------------------------	*/
/*	 d e p e n d a n c e Z o n e E v e n t   ()	*/
/*	--------------------------------------------	*/
int	dependanceZoneEvent( struct style_zone * zptr, int mx, int my )
{
	if (!( zptr ))
		return(0);
	else if (!( zptr->w ))
		return(0);
	else if (!( zptr->h ))
		return(0);
	else if ( mx < zptr->x )
		return(0);	
	else if ( my < zptr->y )
		return(0);	
	else if ( mx >= (zptr->x+zptr->w) )
		return(0);	
	else if ( my >= (zptr->y+zptr->h) )
		return(0);	
	else	return(1);
}

/*	-------------------------------------------------	*/
/*	       d e p e n d a n c e L i n k M o v e ()          	*/
/*	-------------------------------------------------	*/
int	dependanceLinkMove(struct visual_dependance_member * rptr )
{
	struct	visual_dependance_model  * pptr;
	struct	visual_dependance_model  * mptr;
	if (!( rptr ))
		return(0);
	else if (!(mptr = rptr->detail ))
		return(0);
	else if (!( pptr = dependanceRelationDefine(1)))
		return(0);
	else 	return(dependanceBaseChange( mptr, pptr ));
}
		
/*	--------------------------------------------------------	*/
/*	       d e p e n d a n c e L i n k C h a n g e ()          	*/
/*	--------------------------------------------------------	*/
int	dependanceLinkChange(struct visual_dependance_member * rptr )
{
	struct	visual_dependance_model  * pptr;
	struct	visual_dependance_model  * mptr;
	if (!( rptr ))
		return(0);
	else if (!(mptr = rptr->detail ))
		return(0);
	else if (!( pptr = dependanceRelationDefine(0)))
		return(0);
	else 	return(dependanceBaseChange( pptr, mptr ));
}
		
/*	--------------------------------------------------------	*/
/*	  d e p e n d a n c e R e l a t i o n E v e n t  ( rptr )	*/
/*	---------------------------------------------------------	*/
int	dependanceRelationEvent( struct visual_dependance_member * mptr, int mx, int my )
{
	struct visual_dependance_member * sptr;
	struct visual_dependance_member * tptr;
	struct visual_dependance_model 	* smptr;
	struct visual_dependance_model 	* tmptr;

	/* Relation Source Padd */
	/* -------------------- */
	if ( dependanceZoneEvent(&mptr->left, mx, my ) ) {
#ifdef	OOOOOO
		if (( visual_event(1) == _MIMO_UP) 
		&&  ( visual_event(2) == _MIMO_RIGHT))
			return( dependanceLinkMenu( rptr ) );
#endif
		if (( visual_event(1) == _MIMO_DOWN)
		     &&  ( visual_event(2) == _MIMO_LEFT))
			return( dependanceLinkChange( mptr ) );
		}

	/* Relation Target Padd */
	/* -------------------- */
	else if ( dependanceZoneEvent(&mptr->right, mx, my ) ) {
#ifdef	OOOOOO
		if (( visual_event(1) == _MIMO_UP) 
		&&  ( visual_event(2) == _MIMO_RIGHT))
			return( dependanceLinkMenu( mptr ) );
#endif
		if (( visual_event(1) == _MIMO_DOWN)
		     &&  ( visual_event(2) == _MIMO_LEFT))
			return( dependanceLinkMove( mptr ) );
		}
	return(0);
}

/*	---------------------------------------------------------	*/
/*	d e p e n d a n c e M o d e l R e l a t i o n E v e n t(rptr)	*/
/*	---------------------------------------------------------	*/
int	dependanceModelRelationEvent( struct visual_dependance_model * mptr, int mx, int my )
{
	struct	visual_dependance_member * bptr;
	if ((( visual_event(1) == _MIMO_UP  ) &&  ( visual_event(2) == _MIMO_RIGHT))
	||  (( visual_event(1) == _MIMO_DOWN) &&  ( visual_event(2) == _MIMO_LEFT ))) {
		for ( 	bptr = mptr->first;
			bptr != (struct visual_dependance_member *) 0;
			bptr = bptr->next ) {
			if (!( dependanceRelationEvent( bptr, mx, my ) ))
				continue;
			else	return(256);
			}
		}
	return(0);
}

/*	-------------------------------------------------	*/
/*	  d e p e n d a n c e R e l a t i o n D e f i n e ()  	*/
/*	-------------------------------------------------	*/
struct	visual_dependance_model * dependanceRelationDefine(int stmode)
{
	int	event;
	/* Allow user to click on something else */
	/* ------------------------------------- */
	mouse_move_on();
	while (1) {
		switch ( VSE.mode ) {
			case	0	:
				if (!( stmode ))
					dependanceHelpShow("select the style model to be the base class of the current class,  or press escape to cancel the operation",_STYLE_RELATION_SOURCE);
				else	dependanceHelpShow("select the style model to use this class as its base class, or press escape to cancel the operation",_STYLE_RELATION_TARGET);
				break;

			case	1	:
				if (!( stmode ))
					dependanceHelpShow("select the style model to use this class as its base class, or press escape to cancel the operation",_STYLE_RELATION_SOURCE);
				else	dependanceHelpShow("select the style model to be the base class of the current class,  or press escape to cancel the operation",_STYLE_RELATION_TARGET);
				break;
			}
		event = visual_getch();
		dependanceHelpHide();
		if ( event == 27 )
			return( (struct	visual_dependance_member *) 0 );
		else if ( event != 256 )
			continue;
		else if ( visual_event(1) == _MIMO_UP )
			break;
		}
	mouse_move_off();
	if ( dependanceEditorEvent( visual_event(7), visual_event(6)) != 256 )
		return((struct visual_dependance_member*) 0);
	else if (!( VSE.current ))
		return((struct visual_dependance_member*) 0);
	else	return( VSE.current );
}

#include "singdeep.c"

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e M e m b e r S h o w ( mptr ) 	*/
/*	------------------------------------------------	*/
void	dependanceRelationShow(struct visual_dependance_member * sptr, struct visual_dependance_model * tptr )
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
	int	action=0;
	struct visual_dependance_model  * smptr;

	if (!( sptr ))
		return;
	else if (!( smptr = sptr->parent ))
		return;

	databaseZoneReset(&sptr->left);
	databaseZoneReset(&sptr->right);


	sptr->right.w = sptr->left.w = (databaseTextWidth ( "N,N", _STYLE_RELATION_SOURCE, 1) + 2);
	sptr->right.h = sptr->left.h = (databaseTextHeight( "N,N", _STYLE_RELATION_SOURCE, 1) + 2);

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

	if (!( smptr->state )) {
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

	if ( reverse )
		ssptr = ( VSE.mode ? _STYLE_REV_RELATION_SOURCE : _STYLE_RELATION_SOURCE );
	else	ssptr = ( VSE.mode ? _STYLE_RELATION_SOURCE : _STYLE_REV_RELATION_SOURCE );

	if ( visual_element(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,ssptr," ",0)) 
		visual_frame(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,_EDIT_FRAME);

	/* target is inhibited */
	/* ------------------- */
	if (!( tptr->state )) {
		if ( tptr->safty > sptr->right.h )
			tpy = tptr->y+((tptr->safty-sptr->right.h)/2);
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

	if ( reverse )
		ssptr = ( VSE.mode ? _STYLE_REV_RELATION_TARGET : _STYLE_RELATION_TARGET );
	else	ssptr = ( VSE.mode ? _STYLE_RELATION_TARGET : _STYLE_REV_RELATION_TARGET );

	if ( visual_element(sptr->right.x,sptr->right.y,sptr->right.w,sptr->right.h,ssptr," ",0) )
		visual_frame(sptr->right.x,sptr->right.y,sptr->right.w,sptr->right.h,_EDIT_FRAME);


	if (!( VSE.bender )) {
		/* trace it as the crow flies */
		/* -------------------------- */
		visual_line(	sx,	sy,	tx,	ty, VSE.tracewidth, VSE.tracecolour );
		}
	else if ( VSE.bender == 2 ) {
		if ( VSE.debug_trace_route ) {
			printf("Relation : %s(%u,%u) -> %s(%u,%u)\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		dependanceTraceRoute( sx,sy,tx,ty,0,reverse );
		if ( VSE.debug_trace_route ) {
			printf("\tEndRelation\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		}
	else if ( sy == ty ) {
		dependanceTraceLine(sx,sy,tx,ty);
		}
	else if ( sx == tx ) {
		dependanceTraceLine(sx,sy,tx,ty);
		}
	else if ( sx > tx ) {
		mx = (tx + ((sx - tx) / 2));
		dependanceTraceLine(sx,sy,mx,sy);
		dependanceTraceLine(mx,sy,mx,ty);
		if ( sy < ty )
			dependanceTracePoint(mx,ty);
		dependanceTraceLine(mx,ty,tx,ty);
		}
	else 	{
		mx = (sx + ((tx - sx) / 2));
		dependanceTraceLine(sx,sy,mx,sy);
		if ( sy > ty )
			dependanceTracePoint(mx,sy);
		dependanceTraceLine(mx,sy,mx,ty);
		dependanceTraceLine(mx,ty,tx,ty);
		}
	return;
}

/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E   M E M B E R   M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	------------------------------------------------	*/
/*	d e p e n d a n c e M e m b e r R e m o v e ( mptr )	*/
/*	------------------------------------------------	*/
struct visual_dependance_member * dependanceMemberRemove(struct visual_dependance_member * mptr )
{
	if ( mptr->name ) { liberate( mptr->name ); }
	liberate( mptr );
	return((struct visual_dependance_member *) 0);
}

/*	------------------------------------------------	*/
/*	d e p e n d a n c e M e m b e r C r e a t e (      )	*/
/*	------------------------------------------------	*/
struct visual_dependance_member * dependanceMemberCreate()
{
	struct visual_dependance_member * mptr;
	if ((mptr = allocate( sizeof( struct visual_dependance_member ) )) != (struct visual_dependance_member *) 0) {
		mptr->previous = mptr->next = (struct visual_dependance_member *) 0;
		mptr->x = mptr->y = mptr->w = mptr->h = 0;
		mptr->name   = (char *) 0;
		mptr->parent = (struct visual_dependance_model *) 0;
		mptr->detail = (struct visual_dependance_model *) 0;
		mptr->number=0;
		databaseZoneReset(&mptr->left);
		databaseZoneReset(&mptr->right);
		mptr->focus=0;
		mptr->hash=-1;
		}
	return( mptr );
}

/*	-------------------------------------------------	*/
/*	 d e p e n d a n c e M e m b e r E v e n t ( m,x,y ) 	*/
/*	-------------------------------------------------	*/
int	dependanceMemberEvent(struct visual_dependance_member * mptr, int x, int y )
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
			return( dependanceMemberMenu( mptr ) );
		else	return(1);
		}
}

/*	--------------------------------------------------	*/
/*	 d e p e n d a n c e M e m b e r S y n t a x ( m, b ) 	*/
/*	--------------------------------------------------	*/
int	dependanceMemberSyntax( struct visual_dependance_member * mptr, char * rptr )
{
	*rptr = 0;
	if (!( mptr ))
		return(0);
	else if (!( mptr->parent ))
		return(0);
	else 	return(0);
}

/*	--------------------------------------------------	*/
/*	d e p e n d a n c e M e m b e r A n a l y s e ( m, b ) 	*/
/*	--------------------------------------------------	*/
int	dependanceMemberAnalyse( struct visual_dependance_member * mptr, char * rptr )
{
	if (!( mptr ))
		return(0);
	else if (!( mptr->parent ))
		return(0);
	else	{
		return(0);
		}
}

/*	-----------------------------------------------------------	*/
/*	  d e p e n d a n c e M e m b e r T e x t W i d t h ( m, s, f ) 	*/
/*	-----------------------------------------------------------	*/
int 	dependanceMemberTextWidth(struct visual_dependance_member * mptr, char * style, int fid )
{
	char	workbuffer[512];
	if (!( mptr ))
		return(0);
	else if (!( dependanceMemberSyntax( mptr, workbuffer ) ))
		return( 0 );
	else	return( dependanceTextWidth( workbuffer, style, fid ) );
}

/*	--------------------------------------------------------	*/
/*	d e p e n d a n c e M e m b e r L o s e F o c u s (mptr) 	*/
/*	--------------------------------------------------------	*/

void	dependanceMemberLoseFocus(struct visual_dependance_member * mptr )
{
	if ( mptr ) {
		if ( mptr->focus ) {
			(void) visual_element( 
				mptr->x,mptr->y,mptr->w,mptr->h,
				_STYLE_MEMBER,
				( mptr->name ? mptr->name : " "),
				( mptr->name ? strlen( mptr->name ) : 0)
				);
			mptr->focus=0;
			}
		}
	return;
}

/*	-------------------------------------------------	*/
/*	d e p e n d a n c e M e m b e r G e t F o c u s(mptr) 	*/
/*	-------------------------------------------------	*/
void	dependanceMemberGetFocus(struct visual_dependance_member * mptr )
{
	struct	visual_dependance_model * pptr;
	char	workbuffer[512];
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else	{
		dependanceMemberLoseFocus( pptr->current );
		if (!( mptr->focus )) {
			strcpy(workbuffer,mptr->name);
			(void) visual_element( 
				mptr->x,mptr->y,mptr->w,mptr->h,
				_STYLE_MEMBER_FOCUS,
				workbuffer, strlen( workbuffer )
				);
			mptr->focus=1;
			}
		return;
		}
}

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e M e m b e r S h o w ( mptr ) 	*/
/*	------------------------------------------------	*/
void	dependanceMemberShow(struct visual_dependance_member * mptr )
{
	if ( visual_element( 	
		mptr->x,mptr->y,mptr->w,mptr->h,
		_STYLE_MEMBER,
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
/*	 d e p e n d a n c e M o d e l L o c a t e  ( nptr )   	*/
/*	----------------------------------------------------	*/
struct visual_dependance_model * dependanceModelLocate( char * nptr )
{
	struct	visual_dependance_model * rptr=(struct	visual_dependance_model *) 0;
	int	h;
	if ( nptr ) {
		h = dependanceHash(nptr);
		for (	rptr=VSE.first;
			rptr != (struct visual_dependance_model *) 0;
			rptr = rptr->next ) {
			if (!( rptr->name ))
				continue;
			else if ( rptr->hash == -1 )
				rptr->hash = dependanceHash( rptr->name );
			if ( rptr->hash != h )
				continue;
			else if (!( strcmp( rptr->name, nptr ) ))
				break;
			}
		}
	return( rptr );
}

/*	-----------------------------------------------------		*/
/*	 d e p e n d a n c e M o d e l R e s o l v e ( mptr )   	*/
/*	-----------------------------------------------------		*/
struct visual_dependance_model * dependanceModelResolve( struct visual_dependance_member * wptr )
{
	char *	nptr;
	int	h;
	struct	visual_dependance_model * mptr=(struct	visual_dependance_model *) 0;
	if (!( wptr ))
		return( mptr );
	else if (!( nptr = wptr->name ))
		return(mptr);
	h = dependanceHash( nptr );
	for ( 	mptr = VSE.first;
		mptr != (struct	visual_dependance_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if ( mptr->hash == -1 )
			mptr->hash = dependanceHash( mptr->name );
		if ( mptr->hash != h )
			continue;
		else if (!( strcmp( nptr, mptr->name )))
			break;
		}
	return( mptr );
}


/*	---------------------------------------------------------------		*/
/*	 d e p e n d a n c e M e m b e r S h o w R e l a t i o n s ( mptr )   	*/
/*	---------------------------------------------------------------		*/
void	dependanceMemberShowRelations(struct visual_dependance_member * mptr )
{
	struct	visual_dependance_model * pptr;
	struct	visual_dependance_model * rptr;
	pptr = mptr->parent;
	if (!( rptr = dependanceModelLocate( mptr->name )))
		return;
	/* parent model detected : show relation from member to model */
	/* if ( rptr  != (struct visual_dependance_model *) 0) */
	if (!( VSE.solo ))
		dependanceRelationShow( mptr, rptr );
	else if (( pptr ) && ( VSE.solo->number == pptr->number ))
		dependanceRelationShow( mptr, rptr );
	else if (( rptr ) && ( VSE.solo->number == rptr->number ))
		dependanceRelationShow( mptr, rptr );
	return;
}

/*	-------------------------------------------------	*/
/*	 d e p e n d a n c e M e m b e r N a t u r e ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceMemberNature(struct visual_dependance_member * mptr)
{
	struct	visual_dependance_model * pptr;
	struct	form_control * dptr;
	char	workbuffer[512];
	char *	rptr=workbuffer;

	/* validate member, parent and file control */
	/* ---------------------------------------- */
	if (!( mptr ))				return(0);

	dependanceEditorRefresh();
	return;
}
	
/*	-------------------------------------------------	*/
/*	 d e p e n d a n c e M e m b e r D e f i n e ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceMemberDefine(struct visual_dependance_member * mptr)
{
	char	workbuffer[512];
	memset(workbuffer,' ',256);
	if (!( mptr ))
		return(0);
	else if (!( dependanceMemberSyntax( mptr, workbuffer ) ))
		return(0);
	else	{
		visual_frame(	VSE.x+(mptr->x-VSE.xmargin),
				VSE.y+(mptr->y-VSE.ymargin),
			     	mptr->w, mptr->h,
				_EDIT_FRAME);

		if ( visual_edit( 
			VSE.x+(mptr->x-VSE.xmargin)+1,
			VSE.y+(mptr->y-VSE.ymargin)+1,
			mptr->w-2, mptr->h,
			Context.basefont,
			workbuffer, 255 ) != 27) {
			limit_right_space( workbuffer, 255);
			dependanceMemberAnalyse(mptr, workbuffer);
			}
		return(1);
		}
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e M e m b e r M e n u ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceMemberMenu(struct visual_dependance_member * mptr)
{
	struct	form_item * wptr;
	struct	form_control * fptr;
	if (!( mptr ))
		return(0);
	else	{
		return(1);
		}
}

/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E    M O D E L    M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	-------------------------------------------------	*/
/*	 d e p e n d a n c e M o d e l I n h i b i t( mptr )	*/
/*	-------------------------------------------------	*/
int	dependanceModelInhibit(struct visual_dependance_model * mptr)
{
	char	work[512];
	struct	form_control * fptr;
	struct	form_item * iptr;
	struct	camera3d * cptr;
	struct 	object3d * optr;
	struct	camera3d * kptr;
	if (!( VSE.inhibit ))
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
/*	 d e p e n d a n c e M o d e l L a y o u t ( mptr )		*/
/*	-------------------------------------------------	*/
void	dependanceModelLayout(struct visual_dependance_model * mptr)
{
	struct	visual_dependance_member  * xptr;
	int	my;
	int	mh;
	my = mptr->y + dependanceTextHeight(mptr->name,_STYLE_HEADER,0);
	mh = dependanceTextHeight(mptr->name,_STYLE_MEMBER,0);
	for (	xptr=mptr->first;
		xptr != (struct visual_dependance_member *) 0;
		xptr = xptr->next ) {
		xptr->x = mptr->x;
		xptr->w = mptr->w;
		xptr->y = my;
		my += mh;
		xptr->h = mh;
		}
	/* Update VSE Buffer Control */
	/* ------------------------- */
	if (( mptr->x + mptr->w ) > VSE.buffer.width)
		VSE.buffer.width = (( mptr->x + mptr->w )+VSE.xpadding);
	if (( mptr->y + mptr->h ) > VSE.buffer.height)
		VSE.buffer.height = (( mptr->y + mptr->h )+VSE.ypadding);
	return;
}

/*	-------------------------------------------------	*/
/*	  d e p e n d a n c e M o d e l S t a t e ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelState(struct visual_dependance_model * mptr)
{
	int	whoops;
	mptr->state = ((mptr->state+1) & 1);
	whoops = mptr->h; mptr->h = mptr->safty; mptr->safty = whoops;
	dependanceEditorShow();
	return(1);
}

/*	-----------------------------------------------------	*/
/*	  d e p e n d a n c e M o d e l D e t a i l ( model )  	*/
/*	-----------------------------------------------------	*/
int	dependanceEditorDetail()
{
	int	whoops;
	struct visual_dependance_model * mptr;
	for (	mptr=VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ){
		mptr->state = ((mptr->state+1) & 1);
		whoops = mptr->h; mptr->h = mptr->safty; mptr->safty = whoops;
		}
	dependanceEditorShow();
	return(1);
}

/*	-----------------------------------------------------	*/
/*	  d e p e n d a n c e E d i t o r D o m a i n ( )  	*/
/*	-----------------------------------------------------	*/
int	dependanceEditorDomain()
{
	if ( accept_css_domain( &VSE.filter, &VSE.selection ) != 27 ) {
		dependanceEditorRemove();
		dependanceEditorCreate();
		dependanceEditorChoose();
		dependanceEditorShow();
		}
	return(1);
}

/*	---------------------------------------------	*/
/*	  d e p e n d a n c e E d i t o r M o d e ( )  	*/
/*	---------------------------------------------	*/
int	dependanceEditorMode()
{
	if ( VSE.mode )
		VSE.mode = 0;
	else	VSE.mode = 1;
	dependanceEditorLayout();
	dependanceEditorChoose();
	dependanceEditorShow();
	return(1);
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l L o c k ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelLock(struct visual_dependance_model * mptr)
{
	mptr->lock = ((mptr->lock+1) & 1);
	return(0);
}

/*	-------------------------------------------------	*/
/*	 d e p e n d a n c e M o d e l R e n a m e ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelRename(struct visual_dependance_model * mptr)
{
	char	workbuffer[512];
	if (!( mptr ))
		return;
	memset(workbuffer,' ',256);
	strcpy( workbuffer, mptr->name );
	visual_frame(	VSE.x+(mptr->x-VSE.xmargin),
			VSE.y+(mptr->y-VSE.ymargin),
		     	mptr->w, ( mptr->state ? mptr->h : mptr->safty ),
			_EDIT_FRAME);
	if ( visual_edit( 
		VSE.x+(mptr->x-VSE.xmargin)+1,
		VSE.y+(mptr->y-VSE.ymargin)+1,
		mptr->w-2, ( mptr->state ? mptr->h : mptr->safty ),
		Context.basefont,
		workbuffer, 255 ) != 27) {
		if ( mptr->name )
			liberate( mptr->name );
		mptr->name = allocate_string( workbuffer );
		}
	return(1);
}

/*	-------------------------------------------------	*/
/*	 d e p e n d a n c e M o d e l D e l e t e ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelDelete(struct visual_dependance_model * mptr)
{
	struct file_control * fptr;
	struct form_control * dptr;
	if ( mptr->lock )
		return(257);
	else	{
		if (!( mptr->previous ))
			VSE.first = mptr->next;
		else	mptr->previous->next = mptr->next;
		if (!( mptr->next ))
			VSE.last = mptr->previous;
		else	mptr->next->previous = mptr->previous;
		if (( VSE.best ) && ( VSE.best->number == mptr->number ))
			VSE.best = (struct visual_dependance_model *) 0;
		if (( VSE.solo ) && ( VSE.solo->number == mptr->number ))
			VSE.solo = (struct visual_dependance_model *) 0;
		if (( VSE.current ) && ( VSE.current->number == mptr->number ))
			VSE.current = (struct visual_dependance_model *) 0;
		dependanceModelRemove(mptr);
		dependanceEditorShow();
		return(257);
		}
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l I n f o ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelInfo(struct visual_dependance_model * mptr)
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
/*	   d e p e n d a n c e M o d e l S o l o ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelSolo(struct visual_dependance_model * mptr)
{
	if (!( VSE.solo ))
		VSE.solo = mptr;
	else if (!( strcmp( VSE.solo->name , mptr->name ) ))
		VSE.solo = (struct visual_dependance_model *) 0;
	else	VSE.solo = mptr;
	if ( VSE.solo )
		status_message("model specific dependance links",2);
	else	status_message("all project dependance links",2);
	dependanceEditorShow();
	return(0);
}

/*	------------------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l P a r a  m e t e r s( model )  	*/
/*	------------------------------------------------------------	*/
int	dependanceModelParameters(struct visual_dependance_model * mptr)
{
	if (!( mptr ))
		return(0);
	else	{
		return(1);
		}
}

/*	----------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l E d i t o r ( model )  	*/
/*	----------------------------------------------------	*/
int	dependanceModelEditor(struct visual_dependance_model * mptr)
{
	int	h;
	struct	form_control * ffptr;
	struct	form_control * fptr;
	if (!( mptr ))
		return(0);
	else	{
		dependanceModelPrompt(mptr);
		dependanceEditorRemove();
		dependanceEditorCreate();
		dependanceEditorShow();
		return(1);
		}
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r B e s t ( )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelBest(struct visual_dependance_model * mptr, struct style_zone * zptr, int level )
{
	struct	visual_dependance_member * wptr;
	struct	visual_dependance_model * rptr;
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
		for (	wptr=mptr->firstdependant;
			wptr != (struct visual_dependance_member *) 0;
			wptr = wptr->next ) {
			if (!( rptr = dependanceModelResolve( wptr )))
				continue;
			else if ( rptr->done > 0 )
				continue;
			else	{
				rptr->done++;
				rptr->by = mptr->number;
				/* tabulator(level); printf("\t positions %s \r\n",rptr->name); */
				rptr->x = zptr->x+ecart; ecart += 10;
				rptr->y = zptr->y + zptr->h;
				zptr->h += rptr->h;
				zptr->h += VSE.ypadding;
				dependanceModelLayout( rptr );
				}		
			}
		position.x = (mptr->x + mptr->w + VSE.xpadding);
		position.y = mptr->y;
		position.h = 0; position.w = 0;
		for (	wptr=mptr->first;
			wptr != (struct visual_dependance_member *) 0;
			wptr = wptr->next ) {
			if (!( rptr = dependanceModelResolve( wptr )))
				continue;
			else if ( rptr->by != mptr->number )
				continue;
			else if ( rptr->done > 1)
				continue;
			else	{
				position.x = (rptr->x + rptr->w + VSE.xpadding);
				if ( adjust ) { rptr->y += adjust; dependanceModelLayout( rptr ); }
				position.y = rptr->y;
				position.h = 0; position.w = 0;
				dependanceModelBest( rptr, &position,(level+1) );
				if ( position.h > rptr->h ) { 
					adjust +=(position.h - rptr->h); 
					}
				}
			}
		zptr->h += adjust;	
		dependanceModelLayout( mptr );
		return(0);
		}
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r B e s t (bptr) 	*/
/*	-------------------------------------------------	*/
int	dependanceEditorBest( struct visual_dependance_model * bptr)
{
	struct style_zone position;
	struct visual_dependance_model * mptr=(struct visual_dependance *) 0;

	/* initialise position */
	/* ------------------- */
	databaseZoneReset( &position );

	if ( bptr ) {
		bptr->x = VSE.xpadding;
		bptr->y = VSE.ypadding;
		bptr->by = bptr->number;

		position.x = (bptr->x + bptr->w + VSE.xpadding);
		position.y = bptr->y;
		position.h = 0; position.w = 0;

		/* calculate best and descendants */
		/* ------------------------------ */
		dependanceModelBest( bptr, &position,0 );

		if ( position.h  < (bptr->h + VSE.ypadding)) {
			position.h = bptr->h + VSE.ypadding;
			}

		}

	/* detect and handle unused models */
	/* ------------------------------- */
	while (( mptr = dependanceEditorChooseBest()) != (struct visual_dependance *) 0 ) {
		if ( mptr->done )
			continue;
		else	{
			position.y += position.h;
			mptr->y = position.y;
			mptr->x = VSE.xpadding;
			position.x = (mptr->x+mptr->w+VSE.xpadding);
			position.h = 0; position.w = 0;
			mptr->by = mptr->number;

			/* calculate best and descendants */
			/* ------------------------------ */
			dependanceModelBest( mptr, &position, 0 );
			
			if ( position.h  < (mptr->h + VSE.ypadding)) {
				position.h = mptr->h + VSE.ypadding;
				}
			}
		}
	dependanceEditorShow();
	return(0);
}

/*	-----------------------------------------------------		*/
/*	 d e p e n d a n c e M a t c h S e l e c t i o n( c )		*/
/*	-----------------------------------------------------		*/
int	dependanceMatchSelection(char * classname)
{
	int	encore;
	int	inverse=0;
	char *	rptr=(char *) 0;
	char *	sptr=(char *) 0;
	char *	selection=(char *) 0;
	if (!( method_is_valid( VSE.selection ) ))
		return(1);
	else if (!( classname ))
		return(0);
	else if (!( selection = allocate_string( VSE.selection ) )) 
		return(0);
	else	{
		rptr = selection;
		while(1) {
			while ( *selection==' ') selection++;
			if (!( *selection ))	 break;
			for ( 	sptr = selection; *sptr; sptr++ ) if ( *sptr == '|' ) break;
			if ( *sptr == '|' ) {
				encore=1;
				*(sptr++) = 0;
				}
			else	encore = 0;
			if ( *selection == '!' ) {
				selection++;
				inverse = 1;
				}
			else	inverse = 0;
			/* test classname against criteria */

			while ( *selection==' ') selection++;
			if (!( *selection )) break;

			if (!( wildcomp( classname, selection ) )) {
				/* match found */
				liberate(rptr);
				return(( inverse ? 0 : 1));
				}
			else if (!( encore ))
				break;
			else	selection = sptr;
			}
		liberate(rptr);
		return(( inverse ? 1 : 0));
		}
}

/*	---------------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r C h o o s e B e s t ()  	*/
/*	---------------------------------------------------------	*/
struct visual_dependance_model * dependanceEditorChooseBest()
{
	struct element_style * eptr;
	struct element_style * beptr;
	struct visual_dependance_model * mptr;
	struct visual_dependance_model * bptr=(struct visual_dependance *) 0;

	/* locate model with most outbound connections */
	/* ------------------------------------------- */
	while ((mptr = VSE.best) != (struct visual_dependance *) 0) {
		if (!( mptr->done ))
			break;
		else	VSE.best = mptr->next;
		}

	for (	mptr=VSE.best;
		mptr != (struct visual_dependance *) 0;
		mptr = mptr->next) {
		if ( mptr->done ) 
			continue;
		else if ( mptr->by ) 
			continue;
		else if (!( bptr ))
			bptr = mptr;
		else if ( mptr->dependants > bptr->dependants )
			bptr = mptr;
		}
	if (!( bptr ))
		return( bptr );
	else	{
		while ( bptr->basename ) {
			if (!( mptr = dependanceModelLocate( bptr->basename ) ))
				break;
			else if (!( mptr->done ))
				bptr = mptr;
			else	break;
			}
		if ( VSE.debug_trace_route ) {
			printf( "%s : %u(%u) \r\n",bptr->name, bptr->done, bptr->members);
			}
		return( bptr );
		}
}

/*	---------------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r M o d e l M o d e()     	*/
/*	---------------------------------------------------------	*/
void	dependanceEditorModelMode( struct visual_dependance_model * mptr )
{
	switch ( VSE.mode ) {
		case	0 :
			mptr->first = mptr->firstdependance;
			mptr->last  = mptr->lastdependance;
			mptr->members = mptr->dependance;
			break;
		case	1 :
			mptr->first = mptr->firstdependant;
			mptr->last  = mptr->lastdependant;
			mptr->members = mptr->dependants;
			break;
		}
	return;
}

/*	---------------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r P r e p a r e ( )       	*/
/*	---------------------------------------------------------	*/
void	dependanceEditorPrepare()
{
	struct	visual_dependance_model  * mptr;
	for (	mptr=VSE.best=VSE.first;
		mptr != (struct visual_dependance *) 0;
		mptr = mptr->next) {
		mptr->done=mptr->by=0;
		mptr->oldfocus = mptr->current = (struct visual_dependance_member*) 0;
		dependanceEditorModelMode( mptr );
		}
	return;
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r C h o o s e()  	*/
/*	-------------------------------------------------	*/
int	dependanceEditorChoose()
{
	struct visual_dependance_model * mptr;
	struct visual_dependance_model * bptr=(struct visual_dependance *) 0;

	dependanceEditorPrepare();

	if (( bptr = dependanceEditorChooseBest()))
		(void) dependanceEditorBest( bptr );

	return(0);
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e Z o o m R e m o v e () 	 	*/
/*	-------------------------------------------------	*/
int	dependanceZoomRemove()
{
	if ( VSE.stylezoom ) {
		close_window_editor();
		liberate( VSE.stylezoom );
		VSE.stylezoom = (char *) 0;
		VSE.h += VSE.zoomzone.h;
		databaseZoneReset(&VSE.zoomzone);
		filetransferdrop(VSE.zoomname);
		VSE.zoomname =(char *) 0;
		}
	return(0);
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e S t y l e Z o o m ( style )  	*/
/*	-------------------------------------------------	*/
int	dependanceStyleZoom(char * sptr)
{
	dependanceZoomRemove();

	if (!( VSE.stylezoom=sptr))
		return(0);
	else	{
		filetransferin(&VSE.zoomname,&VSE.stylezoom);
		VSE.zoomzone.h = (VSE.h/3);
		VSE.h -= VSE.zoomzone.h;
		VSE.zoomzone.x = VSE.x;
		VSE.zoomzone.w = VSE.w;
		VSE.zoomzone.y = (VSE.y+VSE.h);
		visual_element( VSE.zoomzone.x, VSE.zoomzone.y,
				VSE.zoomzone.w-1, VSE.zoomzone.h, 
				_STYLE_EDITOR_FRAME, " ", 0);
		open_window_editor(
			VSE.zoomzone.x+2,VSE.zoomzone.y+2,
			VSE.zoomzone.w-6,VSE.zoomzone.h-4,
			VSE.zoomname);
		show_window_editor();
		inhibit_text_cursor();
		return(0);
		}
}

/*	--------------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r I m p o r t ( model )  	*/
/*	--------------------------------------------------------	*/
int	dependanceEditorImport()
{
	int	status;
	int	h;
	int	mode=0;
	if ( accept_css_filename( &VSE.exportname, &mode ) == 27 )
		return( 257 );
	else	{
		if ( VSE.selection ) {
			VSE.selection = liberate( VSE.selection );
			}
		if (!(VSE.selection = allocate_string( VSE.exportname )))
			return(257);
		else	VSE.filter = 1;
		load_visual_style( VSE.selection, strlen(VSE.selection) );
		h = set_context_dataview(0);
		status = inspect_style_trace();
		h = set_context_dataview(h);
		if (!( status )) {
			dependanceEditorRemove();
			dependanceEditorCreate();
			dependanceEditorChoose();
			dependanceEditorShow();
			}
		return(257);
		}
}

/*	--------------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l E x p o r t ( model )  	*/
/*	--------------------------------------------------------	*/
int	dependanceModelExport(struct visual_dependance_model * mptr)
{
	int	mode=1;
	FILE	*	h;
	char *	sheetvalue;
	struct element_style * eptr;
	struct element_style * bptr;
	struct visual_dependance_model * wptr;
	if (!( mptr ))
		return(257);
	else if (!( eptr = mptr->style ))
		return(257);
	else if (!( eptr->basename )) {
		bptr = (struct element_style *) 0;
		}
	else if (!( wptr = dependanceModelLocate( eptr->basename ) ))
		return(257);
	else 	bptr = wptr->style;

	if ( accept_css_filename( &VSE.exportname, &mode ) == 27 )
		return( 257 );
	else if (!(sheetvalue = generate_style_file(eptr, bptr, 0 )))
		return(257);
	else if (!( h = fopen( VSE.exportname, "w" ))) {
		liberate( sheetvalue );
		return(257);
		}
	else	{
		fprintf(h,"%s",sheetvalue);
		fclose(h);
		liberate( sheetvalue );
		return( 257 );
		}
	
}

private	void	dependanceAliasGenerate(FILE * h, char * sptr, int sequence )
{
	struct visual_dependance_model * pptr;
	char *	lptr;
	char *	llptr;
	char *	aptr;
	if (!( lptr = allocate_string( sptr )))
		return;
	else	{
		llptr = lptr;
		while ( *lptr ) {
			while ( *lptr == ' ' ) lptr++;
			if (!( *lptr )) break;
			aptr = lptr;
			while (( *lptr != ' ' ) && ( *lptr != '|' ) && ( *lptr != 0 ))
				lptr++;
			if ( *lptr )
				*(lptr++) = 0;
			if (!( pptr = dependanceModelLocate( aptr ) ))
				continue;
			else if ( pptr->sequence < sequence )
				dependanceStyleGenerate(h, pptr );
			}
		liberate( llptr );
		return;
		}
}

private	void	dependanceStyleGenerate(FILE * h, struct visual_dependance_model * mptr)
{
	char	tempbuffer[512];
	char *	sheetvalue;
	struct element_style * eptr;
	struct element_style * bptr;
	struct visual_dependance_model * wptr=(struct visual_dependance_model *) 0;
	if (!( mptr ))
		return;
	else	mptr->sequence++;

	if (!( eptr = mptr->style ))
		return;
	else if (!( eptr->basename ))
		bptr = (struct element_style *) 0;
	else if (!( wptr = dependanceModelLocate( eptr->basename ) ))
		return;
	else 	{
		if ( wptr->sequence < mptr->sequence )
			dependanceStyleGenerate( h, wptr );
		bptr = wptr->style;
		}
	if ( eptr->alias ) {
		dependanceAliasGenerate(h, eptr->alias, mptr->sequence );
		}

	if (!(sheetvalue = generate_style_file(eptr, bptr,0 )))
		return;

	else	{
		c_expanded_line	  (h,mptr->name,0);
		c_expanded_comment(h,mptr->name,0);
		c_expanded_line	  (h,mptr->name,0);
		fprintf(h,"%s\r\n",sheetvalue);
		liberate( sheetvalue );
		}
	return;
}

/*	--------------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r E x p o r t ( model )  	*/
/*	--------------------------------------------------------	*/
int	dependanceEditorExport()
{
	struct visual_dependance_model * mptr;
	int	mode=1;
	FILE	*	h;
	
	if ( accept_css_filename( &VSE.exportname, &mode ) == 27 )
		return( 257 );

	else if (!( h = fopen( VSE.exportname, "w" ))) {
		return(257);
		}

	c_expanded_line	  (h,VSE.exportname,0);
	c_expanded_comment(h,VSE.exportname,0);
	c_expanded_line	  (h,VSE.exportname,0);

	for (	mptr=VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {
		dependanceStyleGenerate( h, mptr );
		}

	c_expanded_line	  (h,"end of file",0);
	c_expanded_comment(h,"end of file",0);
	c_expanded_line	  (h,"end of file",0);

	fclose(h);
	return( 257 );
	
}


/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e S t y l e I n s p e c (s,n)  	*/
/*	-------------------------------------------------	*/
int	dependanceStyleInspect(char ** sheet, char ** name )
{
	int	status=0;
	use_css_tools();
	status = accept_style_inspection( sheet, name );
	drop_tool_manager();
	return( status );
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l E d i t ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelEdit(struct visual_dependance_model * mptr)
{
	char *	sheetvalue;
	struct element_style * eptr;
	struct element_style * bptr;
	struct visual_dependance_model * wptr;
	if (!( mptr ))
		return(257);
	else if (!( eptr = mptr->style )) {
		if (!( sheetvalue = allocate( strlen(mptr->name) + 16) ))
			return(257);
		else	sprintf(sheetvalue,"%s\t{\r\n\t}\r\n",mptr->name);
		bptr = (struct element_style *) 0;
		}
	else 	{
		if (!( eptr->basename )) {
			bptr = (struct element_style *) 0;
			}
		else if (!( wptr = dependanceModelLocate( eptr->basename ) ))
			return(257);
		else 	bptr = wptr->style;
		if (!(sheetvalue = generate_style_file(eptr, bptr, 1 )))
			return(257);
		}
	if ( sheetvalue ) {
		switch ( dependanceStyleInspect( &sheetvalue, &mptr->name ) ) {
			case	27	: 
				liberate( sheetvalue );
				break;
			case	13	: 
				define_visual_style( sheetvalue, strlen( sheetvalue ) );
				if (!( mptr->style ))
					mptr->style = resolve_style_class( mptr->name );
				liberate( sheetvalue );
			}
		}
	return(257);
}


/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l W o r k ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelWork(struct visual_dependance_model * mptr)
{
	char *	sheetvalue;
	struct element_style * eptr;
	struct element_style * bptr;
	struct visual_dependance_model * wptr;
	if (!( mptr ))
		return(257);
	else if (!( mptr->name ))
		return( 257 );
	else if (!( eptr = mptr->style )) {
		if (!( sheetvalue = allocate( strlen(mptr->name) + 16) ))
			return(257);
		else	sprintf(sheetvalue,"%s\t{\r\n\t}\r\n",mptr->name);
		}
	else if (!(sheetvalue = generate_style_file(eptr, (struct element_style *) 0,1)))
		return( 257 );
	if ( sheetvalue != (char *) 0) {
		switch ( dependanceStyleInspect( &sheetvalue, &mptr->name ) ) {
			case	27	: 
				liberate( sheetvalue );
				break;
			case	13	: 
				define_visual_style( sheetvalue, strlen( sheetvalue ) );
				if (!( mptr->style ))
					mptr->style = resolve_style_class( mptr->name );
				liberate( sheetvalue );
			}
		return(257);
		}
}

void	dependantBaseDrop( struct visual_dependance_model * mptr, struct visual_dependance_model * dptr )
{
	struct visual_dependance_member * rptr;
	if ( mptr ) {
		for (	rptr=mptr->firstdependant;
			rptr != (struct visual_dependance_member *) 0;
			rptr = rptr->next ) {
			if (!( rptr->name ))
				continue;
			else if (!( strcmp( rptr->name, dptr->name ) ))
				break;
			else	continue;
			}
		if ( rptr ) {
			if (!( rptr->previous ))
				mptr->firstdependant = rptr->next;
			else	rptr->previous->next = rptr->next;
			if (!( rptr->next ))
				mptr->lastdependant = rptr->previous;
			else	rptr->next->previous = rptr->previous;
			dependanceMemberRemove( rptr );
			}
		}
	return;
}

void	dependanceBaseDrop( struct visual_dependance_model * mptr )
{
	struct visual_dependance_member * rptr;
	if ( mptr ) {
		for (	rptr=mptr->firstdependance;
			rptr != (struct visual_dependance_member *) 0;
			rptr = rptr->next ) {
			if (!( rptr->name ))
				continue;
			else if (!( strcmp( rptr->name, mptr->basename ) ))
				break;
			else	continue;
			}
		if ( rptr ) {
			if (!( rptr->previous ))
				mptr->firstdependance = rptr->next;
			else	rptr->previous->next = rptr->next;
			if (!( rptr->next ))
				mptr->lastdependance = rptr->previous;
			else	rptr->next->previous = rptr->previous;
			dependantBaseDrop( rptr->detail, mptr );
			dependanceMemberRemove( rptr );
			}
		if ( mptr->basename ) {
			mptr->basename = liberate( mptr->basename ); 
			}
		}
	return;
}

/*	----------------------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l A d d R e l a t i o n( model )  	*/
/*	----------------------------------------------------------------	*/
int	dependanceBaseChange(
		struct visual_dependance_model * mptr,
		struct visual_dependance_model * bptr 
		)
{
	struct visual_dependance_model * pptr;
	struct	element_style * eptr;
	char	*	sheetvalue;

	if (!( mptr ))				return(257);
	else if (!( bptr ))			return(257);
	else if (!( eptr = mptr->style ))	return(257);

	if (eptr->basename) { eptr->basename = liberate( eptr->basename ); }

	if (!( eptr->basename = allocate_string( bptr->name )))
		return(257);
	else if (!(sheetvalue = generate_style_file(eptr, bptr->style, 1)))
		return(257);

	define_visual_style( sheetvalue, strlen( sheetvalue ) );

	liberate( sheetvalue );

	if ( mptr->basename ) {
		dependanceBaseDrop( mptr );
		}

	if (!( mptr->basename = allocate_string( bptr->name )))
		return(257);
	else if (!( dependanceModelAddDependance( mptr, mptr->basename ) ))
		return( 257 );
	else if (!( pptr = dependanceModelLocate( mptr->basename ) ))
		return( 257 );
	else if (!( dependanceModelAddDependant( pptr, mptr->name ) ))
		return( 257 );
	else	return(0);
}

/*	----------------------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l A d d R e l a t i o n( model )  	*/
/*	----------------------------------------------------------------	*/
int	dependanceModelAddRelation(struct visual_dependance_model * mptr)
{
	int	status;
	struct	visual_dependance_model * pptr;
	if (!( mptr ))
		return(257);
	else if (!( pptr = dependanceRelationDefine(1)))
		return(257);

	/* ------------------------------------------------------------- */
	/* The source model : mptr is related to the target model : pptr */
	/* The nature of the relation depends on the current model mode	 */
	/* 		Dependance(0) or Dependants(1)			 */
	/* ------------------------------------------------------------- */
	switch	( VSE.mode )	{

		case 0		:
			/* ----------------------------------------------- */
			/* Dependance : 				   */
			/* the target pptr will be the base class of mptr  */
			/* ----------------------------------------------- */
			if ((status = dependanceBaseChange( mptr, pptr )) != 0)
				return(status);
			else	return(257);


		case 	1	:
			/* ---------------------------------------------- */
			/* Dependants : 				  */
			/* the target pptr will be a base client of mptr  */
			/* ---------------------------------------------- */
			if ((status = dependanceBaseChange( pptr, mptr )) != 0)
				return(status);
			else	return(257);		

		}

}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l M e n u ( model )  	*/
/*	-------------------------------------------------	*/
int	dependanceModelMenu(struct visual_dependance_model * mptr)
{
	switch ( dependance_model_menu() ) {
		case	_FLOW_ADD	:
			return( dependanceModelAddRelation( mptr ) );
		case	_FLOW_DELETE	:
			return( dependanceModelDelete( mptr ) );
		case	_FLOW_EXPORT	:
			dependanceModelExport( mptr );
			return(257);
		case	_FLOW_INFO	:
			dependanceModelEdit( mptr );
			dependanceEditorRefresh();
			return(257);
		case	_FLOW_WORK	:
			dependanceModelWork( mptr );
			dependanceEditorRefresh();
			return(257);
		case	_FLOW_DETAIL	:
			dependanceModelState(mptr);
			return(1);
		case	_FLOW_SOLO	:
			dependanceModelSolo(mptr);
			return(1);
		case	_FLOW_BEST	: 
			dependanceEditorPrepare();
			dependanceEditorBest(mptr);	
			return(1);
		}
}

/*	--------------------------------------------------	*/
/*	 d e p e n d a n c e E d i t W i d g e t ( model )  	*/
/*	--------------------------------------------------	*/
int	dependanceEditWidget(struct visual_dependance_model * mptr)
{
	return(1);
}

/*	--------------------------------------------------	*/
/*	 d e p e n d a n c e E d i t M e t h o d ( model )  	*/
/*	--------------------------------------------------	*/
int	dependanceEditMethod(struct visual_dependance_model * mptr)
{
	return(1);
}

/*	-------------------------------------------------	*/
/*	 d e p e n d a n c e M o d e l E v e n t ( m, x, y ) 	*/
/*	-------------------------------------------------	*/
int	dependanceModelEvent(struct visual_dependance_model * mptr, int x, int y )
{
	int	status;
	int	event;
	int	mx;
	int	my;
	int	mb=0;
	struct	visual_dependance_member * xptr;
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
			xptr != (struct visual_dependance_member *) 0;
			xptr = xptr->next ) {
			if (!( status = dependanceMemberEvent( xptr, x, y ) ))
				continue;
			else if ( status != 0x007F ){
				if (!( xptr->focus )) {
					mptr->oldfocus = mptr->current;
					mptr->current  = xptr;
					}
				return(1);
				}
			else	{
				return((VSE.outofdate=1));
				}
			}
		if ( visual_event(1) != _MIMO_DOWN )
			return( 1 );
		mb = visual_event(2);
		while (1) {
			if ( mb == _MIMO_LEFT ) {
				if (!( mptr->lock )) {
					dependanceHelpShow("move the file model to the required position and then release the mouse button",
						(char *) 0);
					}
				}
			xorzone((mptr->x-VSE.xmargin)+VSE.x,(mptr->y-VSE.ymargin)+VSE.y,mptr->w,mptr->h,2007);
			while ((event = visual_getch()) != 256);
			xorzone((mptr->x-VSE.xmargin)+VSE.x,(mptr->y-VSE.ymargin)+VSE.y,mptr->w,mptr->h,2007);
			if (!( mptr->lock )) {
				if ( mb == _MIMO_LEFT ) {
					dependanceHelpHide();
					mx = ((visual_event(7) - VSE.x) + VSE.xmargin);
					my = ((visual_event(6) - VSE.y) + VSE.ymargin);
					mptr->x += (mx -x); x = mx;
					mptr->y += (my -y); y = my;
					}
				}
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		if ( mb == _MIMO_RIGHT ) {
			dependanceModelPrompt(mptr);
			return( dependanceModelMenu(mptr) );
			}
		else if ( mb == _MIMO_LEFT ) {
			dependanceModelLayout(mptr);
			dependanceEditorShow();
			dependanceModelPrompt(mptr);
			}
		return(1);
		}
}

/*	--------------------------------------------------------------		*/
/*	d e p e n d a n c e M o d e l A d d D e p e n d a n c e (mptr) 		*/
/*	--------------------------------------------------------------		*/
struct	visual_dependance_member * dependanceModelAddDependance(struct visual_dependance_model * mptr, char * nptr )
{
	struct	visual_dependance_member * xptr=(struct	visual_dependance_member *) 0;
	if (!( mptr ))
		return(xptr);
	else if (!( xptr = dependanceMemberCreate()))
		return(xptr);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "null dependance")))) {
		dependanceModelRemove( xptr );
		return(xptr);
		}
	else	{
		if (!( xptr->previous = mptr->lastdependance ))
			mptr->current = mptr->firstdependance = xptr;
		else	xptr->previous->next = xptr;
		mptr->lastdependance = xptr;		
		if (!( xptr->previous ))
			xptr->number=1;
		else	xptr->number = (xptr->previous->number+1);
		xptr->parent = mptr;
		mptr->dependance++;
		return(xptr);
		}
}

/*	--------------------------------------------------------------		*/
/*	d e p e n d a n c e M o d e l A d d D e p e n d a n t (mptr) 		*/
/*	--------------------------------------------------------------		*/
struct	visual_dependance_member * dependanceModelAddDependant(struct visual_dependance_model * mptr, char * nptr )
{
	struct	visual_dependance_member * xptr=(struct	visual_dependance_member *) 0;
	if (!( mptr ))
		return(xptr);
	else if (!( xptr = dependanceMemberCreate()))
		return(xptr);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "null dependant")))) {
		dependanceModelRemove( xptr );
		return(xptr);
		}
	else	{
		if (!( xptr->previous = mptr->lastdependant ))
			mptr->current = mptr->firstdependant = xptr;
		else	xptr->previous->next = xptr;
		mptr->lastdependant = xptr;		
		if (!( xptr->previous ))
			xptr->number=1;
		else	xptr->number = (xptr->previous->number+1);
		xptr->parent = mptr;
		mptr->dependants++;
		return(xptr);
		}
}

/*	------------------------------------------------	*/
/*	d e p e n d a n c e M o d e l A d d M e m b e r(mptr) 	*/
/*	------------------------------------------------	*/
struct	visual_dependance_member * dependanceModelAddModel(
		struct visual_dependance_model * mptr, 
		struct visual_dependance_model * tptr )
{
	char	*	nptr;
	struct	visual_dependance_member * xptr=(struct	visual_dependance_member *) 0;
	if (!( mptr ))
		return(xptr);
	else if (!( tptr ))
		return(xptr);
	else if (!( nptr = tptr->name ))
		return(xptr);
	else if (!( xptr = dependanceMemberCreate()))
		return(xptr);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "NULL Widget")))) {
		dependanceModelRemove( xptr );
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
/*	d e p e n d a n c e M o d e l A d d M e t h o d(mptr) 	*/
/*	------------------------------------------------	*/
struct	visual_dependance_member * dependanceModelAddMethod(struct visual_dependance_model * mptr, struct forms_method * wptr , struct form_control * ffptr )
{
	char	*	nptr;
	struct	visual_dependance_member * xptr=(struct	visual_dependance_member *) 0;
	if (!( mptr ))
		return(xptr);
	else if (!( wptr ))
		return(xptr);
	else if (!( nptr = wptr->name ))
		return(xptr);
	else if (!( xptr = dependanceMemberCreate()))
		return(xptr);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "NULL Widget")))) {
		dependanceModelRemove( xptr );
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
		return(xptr);
		}
}

/*	------------------------------------------------	*/
/*	 d e p e n d a n c e M o d e l R e m o v e ( mptr ) 	*/
/*	------------------------------------------------	*/
struct visual_dependance_model * dependanceModelRemove(struct visual_dependance_model * mptr )
{
	struct	visual_dependance_member * rptr;
	if ( mptr ) {
		if ( mptr->name )
			liberate( mptr->name );
		if ( mptr->basename )
			liberate( mptr->basename );
		while ((rptr=mptr->firstdependance) != (struct visual_dependance_member *) 0) {
			mptr->firstdependance = rptr->next;
			dependanceMemberRemove( rptr );
			}
		while ((rptr=mptr->firstdependant) != (struct visual_dependance_member *) 0) {
			mptr->firstdependant = rptr->next;
			dependanceMemberRemove( rptr );
			}
		liberate( mptr );
		}
	return( (struct visual_dependance_model *) 0);
}

/*	------------------------------------------------	*/
/*	 d e p e n d a n c e M o d e l C r e a t e (      ) 	*/
/*	------------------------------------------------	*/
struct visual_dependance_model * dependanceModelCreate()
{
	struct visual_dependance_model * mptr;
	if ((mptr = allocate( sizeof( struct visual_dependance_model ) )) != (struct visual_dependance_model *) 0) {
		mptr->previous = mptr->next = (struct visual_dependance_model *) 0;
		mptr->oldfocus = mptr->current = 
		mptr->firstdependance = mptr->lastdependance =
		mptr->firstdependant = mptr->lastdependant = (struct visual_dependance_member *) 0;
		mptr->x = mptr->y = -1;
		mptr->w = mptr->h = 0;
		mptr->name = (char *) 0;
		mptr->basename = (char *) 0;
		databaseZoneReset(&mptr->icon);
		mptr->sequence=0;
		mptr->hash = -1;
		mptr->dependance = mptr->dependants = mptr->users = mptr->members = 0;
		mptr->inhibit = 0;
		mptr->lock= 0;
		mptr->state= VSE.detail;
		mptr->focus=0;
		mptr->safty= 0;
		mptr->done=0;
		mptr->by=0;
		mptr->nosave=0;
		mptr->number=1;
		}
	return( mptr );
}

/*	--------------------------------------------------	*/
/*	d e p e n d a n c e M o d e l I s V i s i b l e (mptr)   	*/
/*	--------------------------------------------------	*/
int	dependanceModelIsVisible(struct visual_dependance_model * mptr )
{
	if (!( mptr ))	
		return(0);
	else if ( mptr->inhibit )	
		return(0);
	else	return(1);
	if (( mptr->x < VSE.xmargin ) ||  ( mptr->x > (VSE.xmargin+VSE.w)))
		return(0);
	else if (( (mptr->x+mptr->w) < VSE.xmargin ) ||  (( mptr->x+ mptr->w) > (VSE.xmargin+VSE.w)))
		return(0);
	else if (( mptr->y < VSE.ymargin ) ||  ( mptr->y > (VSE.ymargin+VSE.h)))
		return(0);
	else if (( (mptr->y+mptr->h) < VSE.ymargin ) ||  (( mptr->y+ mptr->h) > (VSE.ymargin+VSE.h)))
		return(0);
	else	return(1);
}

/*	--------------------------------------------------	*/
/*	d e p e n d a n c e M o d e l L o s e F o c u s (mptr)   	*/
/*	--------------------------------------------------	*/
void	dependanceModelLoseFocus(struct visual_dependance_model * mptr, int mode )
{
	char 	work[256];
	if (!( mptr ))
		return;
	else if ( mptr->inhibit )
		return;
	else	{
		if ( mode ) 
			dependanceEditorStart();

		if ( mptr->name ) {
			sprintf(work,"%s",mptr->name);
			}
		else	strcpy(work," ");

		if ( VSE.images ) {
			(void) visual_element( mptr->x+mptr->icon.w+VSE.iconpadd,mptr->y,
				mptr->w-(mptr->icon.w+VSE.iconpadd),mptr->h,_STYLE_HEADER, 
				work, strlen(work)
				);
			}
		else	{
			(void) visual_element( mptr->x,mptr->y,
				mptr->w,mptr->h,_STYLE_HEADER, 
				work,strlen(work)
				);
			}
		mptr->focus=0;
		if (!( mptr->state ))
			dependanceMemberLoseFocus(mptr->current);

		if ( mode )
			dependanceEditorFlush();
		}
	return;
}

/*	------------------------------------------------	*/
/*	d e p e n d a n c e M o d e l G e t F o c u s (mptr)   	*/
/*	------------------------------------------------	*/
void	dependanceModelGetFocus(struct visual_dependance_model * mptr )
{
	if (!( mptr ))
		return;
	else if ( mptr->inhibit )
		return;
	else	{
		dependanceEditorStart();
		if (!( mptr->focus )) {
			dependanceModelLoseFocus(VSE.current, 0);
			if ( VSE.images ) {
				(void) visual_element( mptr->x+mptr->icon.w+VSE.iconpadd,mptr->y,
					mptr->w-(mptr->icon.w+VSE.iconpadd),mptr->h,_STYLE_FOCUS, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));
				}
			else	{
				(void) visual_element( mptr->x,mptr->y,
					mptr->w,mptr->h,_STYLE_FOCUS, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));
				}
			mptr->focus=1;
			}
		if (!( mptr->state )) {
			dependanceMemberLoseFocus(mptr->oldfocus);
			dependanceMemberGetFocus(mptr->current);
			}
		dependanceEditorFlush();
		VSE.current = mptr;
		}
	return;
}

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l S h o w ( mptr )   	*/
/*	------------------------------------------------	*/
void	dependanceModelShow(struct visual_dependance_model * mptr )
{
	struct	visual_dependance_member  * xptr;

	/* Avoid display of inhibited Models */
	/* --------------------------------- */
	if (!( mptr ))		return;
	if ( mptr->inhibit )	return;
	
	visual_element( mptr->x,mptr->y,mptr->w,mptr->h,_STYLE_MODEL_TRAY, " " , 0 );
	visual_element( mptr->x,mptr->y,mptr->w,mptr->h,_STYLE_MODEL, " " , 0 );

	dependanceModelLoseFocus( mptr, 0 );

	if (!( mptr->state )) {
		for (	xptr = mptr->first;
			xptr != (struct visual_dependance_member *) 0;
			xptr = xptr->next ) {
			dependanceMemberShow( xptr );
			}
		}

	return;
}

/*	---------------------------------------------------------------		*/
/*	   d e p e n d a n c e M o d e l S h o w R e l a t i o n s ( mptr )   	*/
/*	---------------------------------------------------------------		*/
void	dependanceModelShowRelations(struct visual_dependance_model * mptr )
{
	struct	visual_dependance_member  * xptr;
	if (!( mptr ))	return;
	for (	xptr = mptr->first;
		xptr != (struct visual_dependance_member *) 0;
		xptr = xptr->next ) {
		dependanceMemberShowRelations( xptr );
		}
	return;
}

void	dependanceModelPrompt( struct visual_dependance_model  * xptr )
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
/*	   d e p e n d a n c e M o d e l F o c u s ( mptr )		*/
/*	-------------------------------------------------	*/
int	dependanceModelFocus(struct visual_dependance_model * mptr)
{
	int	event;
	mouse_move_on();
	event = visual_getch();
	mouse_move_off();
	return( event );
}

/*	-------------------------------------------------	*/
/*	   d e p e n d a n c e M o d e l S i z e s ( mptr )		*/
/*	-------------------------------------------------	*/
int	dependanceModelSizes(struct visual_dependance_model * mptr)
{
	struct	form_control * fptr;
	struct	visual_dependance_member  * xptr;
	int	swaper;
	int	maxlen=0;
	int	maxhig=0;
	int	mbmhig=0;
	int	mbmlen=0;
	if (!( mptr ))
		return(0);
	else if (!( mptr->name ))
		maxlen = 0;
	else if (!( maxlen = dependanceTextWidth( mptr->name, _STYLE_HEADER, 0 ) )) {
		mbmhig = maxhig = 0;
		}
	else	{
		if ((maxhig = dependanceTextHeight(  mptr->name, _STYLE_MEMBER, 0 )) < 20)
			maxhig = 20;
		if ((mbmhig = dependanceTextHeight(  mptr->name, _STYLE_MEMBER, 0 )) < 20)
			mbmhig = 20;
		}

	mptr->safty = (maxhig + 5); 

	mptr->icon.h = mptr->icon.w = 0; /* was this for forms image : maxhig; */

	for (	xptr = mptr->first;
		xptr != (struct visual_dependance_member *) 0;
		xptr = xptr->next ) {
		if ((mbmlen = dependanceMemberTextWidth( xptr, _STYLE_MEMBER, 0 )) > maxlen)
			maxlen = mbmlen;
		maxhig += mbmhig;
		}
	mptr->h = maxhig+5;
	mptr->w = (maxlen + 30);
	
	mptr->w += (mptr->icon.w + VSE.iconpadd);

	if ( mptr->state )  {
		swaper = mptr->safty;
		mptr->safty = mptr->h;
		mptr->h = swaper;
		}

	return(0);
}


/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E   E D I T O R   M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e D r o p I m a g e  ( ) 	   	*/
/*	------------------------------------------------	*/
void	dependanceDropImage()
{
	if ( VSE.image ) {
		VSE.image->storage = (STDPSUPTR) 0;
		VSE.image = local_drop_image( VSE.image );
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e B u i l d I m a g e  ( ) 	   	*/
/*	------------------------------------------------	*/
void	dependanceBuildImage()
{
	if (!( VSE.image = local_allocate_image( 0, 0, 0, 0 )))
		return;
	else	{
		VSE.image->storage = VSE.buffer.value;
		VSE.image->rows    = VSE.buffer.height;
		VSE.image->columns = VSE.buffer.width;
		VSE.image->format = get_pixel_size();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r C h e c k ( )    	*/
/*	------------------------------------------------	*/
int	dependanceEditorCheck()
{
	if ( VSE.buffer.width < VSE.w )
		VSE.buffer.width = VSE.w;
	if ( VSE.buffer.height < VSE.h )
		VSE.buffer.height = VSE.h;

	if (( VSE.buffer.width  != VSE.buffer.x )
	||  ( VSE.buffer.height != VSE.buffer.y )) {
		if ( VSE.buffer.value ) {
			dependanceDropImage();
			VSE.buffer.value = liberate_pixel_storage( VSE.buffer.value );
			}
		if (!( VSE.buffer.value = allocate_graphic_storage( 
			0,0, (VSE.buffer.x = VSE.buffer.width), 
			     (VSE.buffer.y = VSE.buffer.height)) ))
			return(27);
		dependanceBuildImage();
		}
	if (!( VSE.buffer.value ))
		return(118);
	else	return(0);
}

/*	--------------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r A d d M o d e l ( )    	*/
/*	--------------------------------------------------------	*/
struct	visual_dependance_model  * dependanceEditorAddModel(char * nptr)
{
	struct	visual_dependance_model  * mptr;
	if (!( mptr = dependanceModelCreate()))
		return((struct	visual_dependance_model  *)0);
	else if (!( mptr->name = allocate_string(( nptr ? nptr : "NULL Model")))) {
		dependanceModelRemove( mptr );
		return((struct	visual_dependance_model  *)0);
		}
	else	{
		if (!( mptr->previous = VSE.last ))
			VSE.current = VSE.first = mptr;
		else	mptr->previous->next = mptr;
		VSE.last = mptr;		
		if ( mptr->previous )
			mptr->number += mptr->previous->number;
		return(mptr);
		}
}

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r R e m o v e ( )  	*/
/*	------------------------------------------------	*/
int	dependanceEditorRemove()
{
	struct	visual_dependance_model  * mptr;
	while ((mptr = VSE.first) != (struct visual_dependance_model  *) 0) {
		VSE.first = mptr->next;
		dependanceModelRemove( mptr );
		}
	dependanceDropImage();
	VSE.solo = VSE.first = VSE.current = VSE.last = (struct visual_dependance_model *) 0;
	return(0);
}

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r L a y o u t ( )  	*/
/*	------------------------------------------------	*/
int	dependanceEditorLayout()
{
	int	my=0;
	int	x=VSE.xpadding;
	int	y=VSE.ypadding+30;
	int	nb=0;
	int	rowheight=0;
	struct	visual_dependance_model  * mptr;

	if (!( y = dependanceTextHeight(VSE.title,_STYLE_TITLE,0) ))
		y =  VSE.ypadding;
	else	y += VSE.ypadding;

	VSE.x = Context.DeskTop.x;
	VSE.y = Context.DeskTop.y;
	VSE.w = Context.DeskTop.w;
	VSE.h = (Context.DeskTop.h - VSE.zoomzone.h);

	VSE.buffer.width = 0;
	VSE.buffer.height= 0;

	for (	mptr = VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {
		dependanceEditorModelMode( mptr );
		dependanceModelSizes(mptr);
		}
	for (	mptr = VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {

		if (( mptr->x == -1 )
		||  ( mptr->y == -1 )) {
		
			mptr->x = x; 
			mptr->y = y;
			if ((x + mptr->w + VSE.xpadding) > VSE.w) {
				x = VSE.xpadding;
				y += ( rowheight + VSE.ypadding);
				rowheight=mptr->h;
				}
			else if ((mptr->x+mptr->w) > (VSE.x + VSE.w)) {
				x = VSE.xpadding;
				mptr->x = VSE.xpadding;
				y += ( rowheight + VSE.ypadding);
				mptr->y = y;
				rowheight=mptr->h;
				}
			else	{
				x += (mptr->w + VSE.xpadding);
				if ( mptr->h > rowheight ) {
				rowheight = mptr->h;
				}
				}
			}
		dependanceModelLayout(mptr);

		}
	return(0);
}

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r D e f a u lt ( )  	*/
/*	------------------------------------------------	*/
void	dependanceEditorDefault()
{
	char	*	eptr;

	VSE.mode	 = 1;
	VSE.hyperspace	 = 1;
	VSE.fraction	 = 4;
	VSE.bubblehelp	 = 1;
	VSE.detail	 = 0;

	VSE.bender	 = 2;
	VSE.tracewidth	 = 3;
	VSE.tracecolour	 = 1;

	VSE.xpadding 	 = 100;
	VSE.ypadding 	 = 50;
	VSE.tracepadding = 50;
	VSE.depth 	 = 50;

	VSE.filter = 0; /* filter by domain */
	VSE.selection  = (char *) 0;
	VSE.stylesheet = (char *) 0;
	VSE.stylezoom  = (char *) 0;
	VSE.exportname = (char *) 0;
	
	if (( eptr = getenv( "SING_DEBUG_ROUTER" )) != (char *) 0)
		VSE.debug_trace_route = atoi( eptr );
	else	VSE.debug_trace_route = 0;
	return;
}

/*	-------------------------------------------------	*/
/*	d e p e n d a n c e E d i t o r L i b e r a t e()  	*/
/*	-------------------------------------------------	*/
int	dependanceEditorLiberate()
{
	if ( VSE.copied_member ) {
		VSE.copied_member = dependanceMemberRemove( VSE.copied_member );
		}
	if ( VSE.copied_model ) {
		VSE.copied_model = dependanceModelRemove( VSE.copied_model );
		}
	if ( VSE.exportname ) {
		liberate( VSE.exportname );
		VSE.exportname = (char *) 0;
		}
	dependanceZoomRemove();
	return;
}

/*	-----------------------------------------------		*/
/*	   d e p e n d a n c e E d i t o r S c h e m a()  	*/
/*	-----------------------------------------------		*/
void	dependanceEditorSchema( int mode )
{
	if ( VSE.schema != mode ) {

		switch ((VSE.schema=mode)) {

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

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r R e s e t ( )  	*/
/*	------------------------------------------------	*/
int	dependanceEditorInitialise()
{

	if ( Context.Camera )
		VSE.inhibit = 1;
	else	VSE.inhibit = 0;

	VSE.hypersave.w = VSE.hypersave.h = VSE.hypersave.y = VSE.hypersave.x = 0;
	VSE.sbh = VSE.sbw = 0;
	VSE.xmargin 	  = 0; 
	VSE.ymargin 	  = 0;
	VSE.copied_member = (struct visual_dependance_member *) 0;
	VSE.copied_model  = (struct visual_dependance_model  *) 0;
	VSE.schema = 0;
	VSE.images = 1;
	VSE.useroot=1;
	VSE.iconpadd = 10;
	dependanceEditorSchema(_SCHEMA_MERISE);
	VSE.x = VSE.y = VSE.w = VSE.h =0;
	databaseZoneReset(VSE.zoomzone);
	return;
}

/*	--------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r P r o j e c t()  	*/
/*	--------------------------------------------------	*/
void	dependanceEditorProject( struct camera3d * cptr, struct style_zone * zptr )
{
	struct	visual_dependance_model  * mptr;
	struct object3d 		* optr;
	int				status;
	if (!( cptr ))
		return;
	for ( 	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		if ( optr->nature != __3D_FORM )
			continue;
		}
	return;
}

/*	--------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r M o d e l ()     	*/
/*	--------------------------------------------------	*/
void	dependanceEditorModel()
{
	char	* aptr;
	char	* lptr;
	char	* llptr;
	struct	element_style * eptr;
	struct	style_zone viewport;
	struct	visual_dependance_member * rptr;
	struct	visual_dependance_model * mptr;
	struct	visual_dependance_model * pptr;
	databaseZoneReset(&viewport);
	if (( VSE.title = Context.Camera->name ) != (char *) 0)
		status_message(VSE.title,2);

	for ( 	eptr=first_style_class(); 
		eptr != (struct element_style *) 0; 
		eptr = eptr->next ) {
		if (!( eptr->name ))
			continue;
		else if (!( dependanceMatchSelection((VSE.filter ? eptr->filename : eptr->name))))
			continue;
		else if (!( mptr = dependanceEditorAddModel( eptr->name ) ))
			continue;
		else 	{
			mptr->style = eptr;
			if (!( eptr->basename ))
				continue;
			else if (!( mptr->basename = allocate_string( eptr->basename ) ))
				continue;
			}
		}
	/* add base class information members */
	for (	mptr=VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->basename ))
			continue;
		else if (!( rptr = dependanceModelAddDependance( mptr, mptr->basename ) ))
			continue;
		else	{
			if (!( pptr = dependanceModelLocate( mptr->basename ) ))
				continue;
			else if (!( rptr = dependanceModelAddDependant( pptr, mptr->name ) ))
				continue;
			}
		}
	/* add alias member information */
	for (	mptr=VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->style ))
			continue;
		else if (!( mptr->style->alias ))
			continue;
		else if (!( lptr = allocate_string( mptr->style->alias )))
			continue;
		else	{
			llptr = lptr;
			while ( *lptr ) {
				while ( *lptr == ' ' ) lptr++;
				if (!( *lptr )) break;
				aptr = lptr;
				while (( *lptr != ' ' ) && ( *lptr != '|' ) && ( *lptr != 0 ))
					lptr++;
				if ( *lptr )
					*(lptr++) = 0;
				if (!( rptr = dependanceModelAddDependance( mptr, aptr ) ))
					continue;
				else	{
					if (!( pptr = dependanceModelLocate( aptr ) ))
						continue;
					else if (!( rptr = dependanceModelAddDependant( pptr, mptr->name ) ))
						continue;
					}
				}
			liberate( llptr );
			}
		}
	for (	mptr=VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next )
		dependanceEditorModelMode( mptr );

	return;
}

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r C r e a t e ( )  	*/
/*	------------------------------------------------	*/
int	dependanceEditorCreate()
{
	int	i;
	int	status=0;
	VSE.solo = VSE.best = VSE.first = VSE.current = VSE.last = (struct visual_dependance_model *) 0;
	VSE.buffer.width  = 0;
	VSE.buffer.height = 0;
	VSE.buffer.x 	  = 0;
	VSE.buffer.y 	  = 0;
	VSE.buffer.value  = (STDPSUPTR) 0;
	VSE.image	  = (struct standard_image *) 0;
	VSE.outofdate 	  = 0;

	dependanceEditorModel();
	dependanceEditorLayout();
	return(0);
}


/*	--------------------------------------------------------	*/
/*	 d e p e n d a n c e C a l c u l a t e H y p e r V i e w()	*/
/*	--------------------------------------------------------	*/
void	dependanceCalculateHyperCursor()
{
	VSE.hypercursor.w = ((VSE.hyperview.w * VSE.w) / VSE.buffer.width);
	VSE.hypercursor.h = ((VSE.hyperview.h * VSE.h) / VSE.buffer.height);
	VSE.hypercursor.x = VSE.hyperview.x+((VSE.hyperview.w * VSE.xmargin) / VSE.buffer.width);
	VSE.hypercursor.y = VSE.hyperview.y+((VSE.hyperview.h * VSE.ymargin) / VSE.buffer.height);
	return;
}

/*	------------------------------------------------	*/
/*	     d e p e n d a n c e H y p e r V i e w  ()	    	*/
/*	------------------------------------------------	*/
void	dependanceHyperView()
{
	if (!( VSE.image ))
		return;
	else if (!( VSE.image->storage ))
		return;
	else	{
		visual_element(VSE.hyperzone.x,VSE.hyperzone.y,VSE.hyperzone.w,VSE.hyperzone.h,_STYLE_HYPERVIEW_TRAY," ",1);
		visual_element(VSE.hyperzone.x,VSE.hyperzone.y,VSE.hyperzone.w,VSE.hyperzone.h,_STYLE_HYPERVIEW_FRAME," ",1);
		drawimage     (VSE.hyperview.x,VSE.hyperview.y,VSE.hyperview.w,VSE.hyperview.h,VSE.image,_I_MAKEFIT);
		visual_element(VSE.hypercursor.x,VSE.hypercursor.y,VSE.hypercursor.w,VSE.hypercursor.h,_STYLE_HYPERVIEW_CROSS," ",1);
		visual_element(VSE.hypercursor.x,VSE.hypercursor.y,VSE.hypercursor.w,VSE.hypercursor.h,_STYLE_HYPERVIEW_ZOOM," ",1);
		}
}

/*	------------------------------------------------------------		*/
/*	 d e p e n d a n c e H y p e r V i e w C u r s o r E v e n t ()	    	*/
/*	-----------------------------------------------------------		*/
int	dependanceHyperViewCursorEvent(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	if ( x < VSE.hypercursor.x )
		return(0);
	else if ( y <= VSE.hypercursor.y )
		return(0);
	else if ( x > (VSE.hypercursor.x+VSE.hypercursor.w) )
		return(0);
	else if ( y > (VSE.hypercursor.y+VSE.hypercursor.h) )
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
			VSE.hypercursor.x += (mx -x); x = mx;
			VSE.hypercursor.y += (my -y); y = my;
			if ( VSE.hypercursor.x < VSE.hyperview.x )
				VSE.hypercursor.x = VSE.hyperview.x;
			else if ( (VSE.hypercursor.x+VSE.hypercursor.w) > (VSE.hyperview.x+VSE.hyperview.w))
				VSE.hypercursor.x = ((VSE.hyperview.x+VSE.hyperview.w)-VSE.hypercursor.w);
			if ( VSE.hypercursor.y < VSE.hyperview.y )
				VSE.hypercursor.y = VSE.hyperview.y;
			else if ((VSE.hypercursor.y+VSE.hypercursor.h) > (VSE.hyperview.y+VSE.hyperview.h))
				VSE.hypercursor.y = ((VSE.hyperview.y+VSE.hyperview.h)-VSE.hypercursor.h);
			VSE.xmargin = ((VSE.buffer.width*(VSE.hypercursor.x-VSE.hyperview.x))/VSE.hyperview.w);
			VSE.ymargin = ((VSE.buffer.height*(VSE.hypercursor.y-VSE.hyperview.y))/VSE.hyperview.h);
			VSE.hyperspace = 0;
			visual_freeze();
			dependanceEditorRefresh();
			dependanceHyperView();
			visual_thaw(VSE.hyperzone.x,VSE.hyperzone.y,VSE.hyperzone.w,VSE.hyperzone.h);
			VSE.hyperspace = 1;
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		mouse_move_off();
		return(1);
		}
}

/*	-----------------------------------------------------------	*/
/*	 d e p e n d a n c e H y p e r V i e w Z o n e E v e n t ()	*/
/*	-----------------------------------------------------------	*/
int	dependanceHyperViewZoneEvent(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	if ( x < VSE.hyperview.x )
		return(0);
	else if ( y <= VSE.hyperview.y )
		return(0);
	else if ( x > (VSE.hyperview.x+VSE.hyperview.w) )
		return(0);
	else if ( y > (VSE.hyperview.y+VSE.hyperview.h) )
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
			VSE.hyperzone.x += (mx -x); x = mx;
			if ( VSE.hyperzone.x < VSE.x )
				VSE.hyperzone.x = VSE.x;
			else if ((VSE.hyperzone.x+VSE.hyperzone.w) > (VSE.x+VSE.w))
				VSE.hyperzone.x = (VSE.x + (VSE.w-VSE.hyperzone.w));
			VSE.hyperzone.y += (my -y); y = my;
			if ( VSE.hyperzone.y < VSE.y )
				VSE.hyperzone.y = VSE.y;
			else if ((VSE.hyperzone.y+VSE.hyperzone.h) > (VSE.y+VSE.h))
				VSE.hyperzone.y = (VSE.y + (VSE.h-VSE.hyperzone.h));
			dependanceCalculateHyperView();
			dependanceEditorRefresh();
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		mouse_move_off();
		return(1);
		}
}

/*	------------------------------------------------	*/
/*	 d e p e n d a n c e H y p e r V i e w E v e n t ()	    	*/
/*	------------------------------------------------	*/
int	dependanceHyperViewEvent(int x, int y)
{
	if (!( VSE.hyperspace ))
		return(0);
	else if ( dependanceHyperViewCursorEvent(x,y) )
		return(1);
	else if ( dependanceHyperViewZoneEvent(x,y) )
		return(1);
	else	return(0);
}

/*	--------------------------------------------------------	*/
/*	 d e p e n d a n c e C a l c u l a t e H y p e r V i e w()	    	*/
/*	--------------------------------------------------------	*/
void	dependanceCalculateHyperView()
{
	VSE.hyperview.x = VSE.hyperzone.x + 5;
	VSE.hyperview.y = VSE.hyperzone.y + 5;
	VSE.hyperview.w = VSE.hyperzone.w - 10;
	VSE.hyperview.h = VSE.hyperzone.h - 10;
	return;
}

/*	--------------------------------------------------------	*/
/*	 d e p e n d a n c e C a l c u l a t e H y p e r Z o n e()	    	*/
/*	--------------------------------------------------------	*/
void	dependanceCalculateHyperZone()
{
	if (( VSE.hypersave.w == VSE.w ) 
	&&  ( VSE.hypersave.h == VSE.h )
	&&  ( VSE.hypersave.y == VSE.y )
	&&  ( VSE.hypersave.x == VSE.x )
	&&  ( VSE.buffer.height== VSE.sbh )
	&&  ( VSE.buffer.width == VSE.sbw ))
		return;

	VSE.hypersave.w = VSE.w; VSE.hypersave.h = VSE.h;
	VSE.hypersave.y = VSE.y; VSE.hypersave.x = VSE.x;
	VSE.sbh = VSE.buffer.height;
	VSE.sbw = VSE.buffer.width;

	if ( VSE.buffer.height > VSE.buffer.width ) {
		VSE.hyperzone.h = (VSE.h/VSE.fraction)+10;
		VSE.hyperzone.w = ((VSE.hyperzone.h * VSE.buffer.width)/VSE.buffer.height)+10;
		}
	else	{
		VSE.hyperzone.w = (VSE.w / VSE.fraction)+10;
		VSE.hyperzone.h = ((VSE.hyperzone.w * VSE.buffer.height)/VSE.buffer.width)+10;
		}
	VSE.hyperzone.x = VSE.x + (VSE.w - VSE.hyperzone.w);
	VSE.hyperzone.y = VSE.y;
	dependanceCalculateHyperView();
	return;
}

/*	------------------------------------------------	*/
/*	  d e p e n d a n c e E d i t o r R e f r e s h ()    	*/
/*	------------------------------------------------	*/
void	dependanceEditorRefresh()
{
	int	pixelsize=get_pixel_size();
	int	r;
	char *	bptr;

	if (( VSE.xmargin + VSE.w ) > VSE.buffer.width )
		VSE.xmargin = (VSE.buffer.width - VSE.w);
	else if ( VSE.xmargin < 0 ) 
		VSE.xmargin = 0;
	if (( VSE.ymargin + VSE.h ) > VSE.buffer.height)
		VSE.ymargin = (VSE.buffer.height - VSE.h);
	else if ( VSE.ymargin < 0 ) 
		VSE.ymargin = 0;

	visual_freeze();
	for ( r=0; r < VSE.h; r++ ) {
		if (!( bptr = connect_pixel_row( VSE.buffer.value, r+VSE.ymargin )))
			break;
		else	putzone(VSE.x,VSE.y+r,VSE.w,1,(bptr+(VSE.xmargin*pixelsize)));
		}

	if ( VSE.hyperspace ) {
		dependanceCalculateHyperZone();
		dependanceCalculateHyperCursor();
		dependanceHyperView();
		}

	visual_thaw( VSE.x, VSE.y, VSE.w, VSE.h );
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r S t a r t ( )    	*/
/*	------------------------------------------------	*/
int	dependanceEditorStart()
{
	VSE.x = 0;
	VSE.y = 0;

	/* Allocate Screen Buffer and Establish */
	/* ------------------------------------ */
	if (!( dependanceEditorCheck() )) {
		background_pixel_capture( VSE.buffer.value );
		}
	return;
}

/*	------------------------------------------------	*/
/*	   d e p e n d a n c e E d i t o r F l u s h ( )    	*/
/*	------------------------------------------------	*/
int	dependanceEditorFlush()
{
	/* Disactive Screen Buffer */
	/* ----------------------- */
	if ( VSE.buffer.value ) {
		cancel_pixel_capture( VSE.buffer.value );
		}

	VSE.x = Context.DeskTop.x;
	VSE.y = Context.DeskTop.y;

	/* Display the Screen Buffer */
	/* ------------------------- */
	dependanceEditorRefresh();
	
	return;
}

/*	------------------------------------------------	*/
/*	     d e p e n d a n c e E d i t o r S h o w ( )    	*/
/*	------------------------------------------------	*/
int	dependanceEditorShow()
{
	struct	visual_dependance_model  * mptr;

	VSE.outofdate = 0;

	dependanceZoomRemove();

	VSE.w = Context.DeskTop.w;
	VSE.h = Context.DeskTop.h;

	dependanceEditorStart();

	/* display with style if required and possible */
	/* ------------------------------------------- */
	if ( visual_element( VSE.x,VSE.y,VSE.buffer.width,VSE.buffer.height,_STYLE_FRAME, "  ",0) ) {

		/* Reset Zone otherwise */
		/* -------------------- */
		filzone	(
			VSE.x,VSE.y,
			VSE.buffer.width,VSE.buffer.height,
			_DEFAULT_GUI_NEUTRAL);
		}

	(void ) visual_element( VSE.x,VSE.y,VSE.buffer.width,VSE.buffer.height,_STYLE_TITLE, VSE.title, strlen( VSE.title ));

	/* Display the various Database Relations */
	/* -------------------------------------- */
	for (	mptr = VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {
		dependanceModelShowRelations(mptr);
		}

	/* Display the various Database File Models */
	/* ---------------------------------------- */
	for (	mptr = VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {
		dependanceModelShow(mptr);
		}

	dependanceEditorFlush();

	return(0);
}

/*	------------------------------------------------	*/
/*	     d e p e n d a n c e E d i t o r H i d e ( )    	*/
/*	------------------------------------------------	*/
int	dependanceEditorHide()
{
	return(0);
}


/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r M o v e ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorMove(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	int	event;
	while (1) {
		while ((event = visual_getch()) != 256);
		mx = visual_event(7);
		my = visual_event(6);
		VSE.xmargin += (x - mx); x = mx;
		VSE.ymargin += (y - my); y = my;
		dependanceEditorRefresh();
		if ( visual_event(1) == _MIMO_UP ) break;
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r R e s e t() 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorReset()
{
	struct	visual_dependance_model  * mptr;
	if (!( VSE.inhibit )) {
		status_message("cannot be performed on multiple projects",2);
		return;
		}
	for (	mptr = VSE.first;
		mptr != (struct visual_dependance_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->lock )) {
			mptr->x = mptr->y = -1;
			}
		}
	VSE.outofdate = 2;
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r I n f o ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorInfo()
{
	if ( accept_database_control(
		&VSE.hyperspace,
		&VSE.bubblehelp,
		&VSE.bender,
		&VSE.tracewidth,
		&VSE.tracecolour,
		&VSE.depth,
		&VSE.tracepadding,	
		&VSE.xpadding,
		&VSE.ypadding,
		&VSE.fraction,
		&VSE.schema ) != 27 ) {
		dependanceEditorRefresh();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r H e l p ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorHelp()
{
	if (!( VSE.bubblehelp = ((VSE.bubblehelp + 1) & 1) ))
		status_message("help bubble messages : OFF",2);
	else	status_message("help bubble messages : ON",2);
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r T r a c e ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorTrace()
{
	VSE.bender += 1;
	if ( VSE.bender > 2 )
		VSE.bender = 0;
	switch ( VSE.bender ) {
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
	VSE.outofdate=1;
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r H y p e r ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorHyper()
{
	if (!( VSE.hyperspace = ((VSE.hyperspace + 1) & 1) )) 
		status_message("hyperspace navigator : OFF",2);
	else	status_message("hyperspace navigator : ON",2);
	VSE.outofdate=1;
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r S o l o ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorSolo()
{
	if (!( VSE.solo )) {
		if ( VSE.current )
			dependanceModelSolo( VSE.current );
		}
	else	{
		VSE.solo = (struct visual_dependance_model *) 0;
		dependanceEditorShow();
		}
	return;
}

/*	------------------------------------------------	*/
/*	  d e p e n d a n c e E d i t o r I n h i b i t ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceEditorInhibit()
{
	if (!( Context.Camera ))
		VSE.inhibit = 0;
	else	{
		VSE.inhibit = ((VSE.inhibit + 1) & 1);
		}
	if ( VSE.inhibit ) 
		status_message("displaying project dependance",2);
	else	status_message("displaying all dependances",2);
	dependanceEditorRebuild();

	return;
}

/*	------------------------------------------------------- 	*/
/*	    d e p e n d a n c e E d i t o r R e f r e s h ( ) 	  	*/
/*	------------------------------------------------------- 	*/
void	dependanceEditorRebuild()
{
	dependanceEditorRemove();
	dependanceEditorCreate();
	dependanceEditorShow();
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e S a v e I m a g e ( ) 	  	*/
/*	------------------------------------------------	*/
void	dependanceSaveImage()
{
	char *	tempname;
	if (!( VSE.image ))
		return;
	else if (!( tempname = allocate_string("dependance.gif") ))
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
			image_save(tempname,VSE.image,QUICK);
			tempname = liberate( tempname );
			return;
			}
		}
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r N e w ( )   	*/
/*	------------------------------------------------	*/
void	dependanceEditorNew(int x, int y)
{
	struct	element_style * eptr;
	struct	visual_dependance_model  * mptr;
	char	workbuffer[512];
	memset(workbuffer,' ',256);
	visual_frame(	VSE.x, VSE.y, VSE.w, 32, _EDIT_FRAME );
	visual_text (	VSE.x+5, VSE.y+2, 100, 30, Context.menufont, 16,0, "Classname:",10,3);
	if ( visual_edit( 
			VSE.x+120,VSE.y+2,300,30,
			Context.basefont,
			workbuffer, 255 ) == 27) {
		dependanceEditorRefresh();
		}
	else	{
		limit_right_space( workbuffer, 255);
		if (!( eptr = resolve_style_class( workbuffer )))
			if (!( eptr = overload_style( workbuffer ) ))
				return;
 		if (!( mptr = dependanceEditorAddModel( workbuffer ))) {
			dependanceEditorRefresh();
			return;
			}
		else	{
			mptr->x = x;
			mptr->y = y;
			mptr->style = eptr;
			dependanceModelSizes(mptr);
			dependanceEditorShow();
			}
		}
	return;
}
/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r M e n u ( )   	*/
/*	------------------------------------------------	*/
void	dependanceEditorMenu()
{
	int	emx = ((visual_event(7) - VSE.x) + VSE.xmargin);
	int	emy = ((visual_event(6) - VSE.y) + VSE.ymargin);
	switch ( dependance_main_menu() ) {
		case	_FLOW_RESET	: dependanceEditorReset();		break;
		case	_FLOW_INFO	: dependanceEditorInfo();		break;
		case	_FLOW_HELP	: dependanceEditorHelp();		break;
		case	_FLOW_TRACE	: dependanceEditorTrace();		break;
		case	_FLOW_HYPER	: dependanceEditorHyper();		break;
		case	_FLOW_INHIBIT	: dependanceEditorInhibit();		break;
		case	_FLOW_SOLO	: dependanceEditorSolo();		break;
		case	_FLOW_BEST	: dependanceEditorChoose();		break;
		case	_FLOW_SCREEN	: dependanceEditorRebuild();		break;
		case	_FLOW_IMAGE	: dependanceSaveImage();		break;
		case	_FLOW_EXPORT	: dependanceEditorExport();		break;
		case	_FLOW_IMPORT	: dependanceEditorImport();		break;
		case	_FLOW_DETAIL	: dependanceEditorDetail();		break;
		case	_FLOW_DOMAIN	: dependanceEditorDomain();		break;
		case	_FLOW_MODE	: dependanceEditorMode();		break;
		case	_FLOW_NEW	: dependanceEditorNew(emx,emy);		break;
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r E v e n t ( )    	*/
/*	------------------------------------------------	*/
int	dependanceZoomEvent(int x, int y)
{
	int	event;
	if (( x < VSE.zoomzone.x )
	||  ( y < VSE.zoomzone.y )
	||  ( x > (VSE.zoomzone.x+VSE.zoomzone.w))
	||  ( y > (VSE.zoomzone.y+VSE.zoomzone.h)))
		return( -1 );
	else if ( visual_event(1)  != _MIMO_DOWN )
		return(-1);
	else	{
		event = focus_window_editor();
		inhibit_text_cursor();
		return( event );
		}
}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r E v e n t ( )    	*/
/*	------------------------------------------------	*/
int	dependanceEditorEvent(int x, int y)
{
	int	status;
	struct	visual_dependance_model  * mptr;
	if (( x < Context.DeskTop.x )
	||  ( y < Context.DeskTop.y )
	||  ( x > (Context.DeskTop.x+Context.DeskTop.w))
	||  ( y > (Context.DeskTop.y+Context.DeskTop.h)))
		return( -1 );
	else if ( dependanceHyperViewEvent(x,y) )
		return(256);
	else	{
		switch ( visual_event(2) ) {
			case	_MIMO_WHEELUP	:
				VSE.ymargin -= 10;
				dependanceEditorRefresh();
				return(256);
			case	_MIMO_WHEELDOWN	:
				VSE.ymargin += 10;
				dependanceEditorRefresh();
				return(256);
			default			:

				for (	mptr = VSE.first;
					mptr != (struct visual_dependance_model *) 0;
					mptr = mptr->next ) {
					if (!(status = dependanceModelEvent(mptr, (x-VSE.x)+VSE.xmargin, (y-VSE.y)+VSE.ymargin ) )) {
						if (!( status = dependanceModelRelationEvent( mptr, (x-VSE.x)+VSE.xmargin, (y-VSE.y)+VSE.ymargin ) ))
							continue;
						}
					if ( status == 257 )
						return( status );
					else if (( status != 0x007F )) {
						dependanceModelGetFocus(mptr);
						return( 256 );
						}		
					else	{
						return( 256 );
						}
					}
			
				switch ( visual_event(2) ) {
					case	_MIMO_LEFT	:
						if ( visual_event(1) == _MIMO_DOWN )
							dependanceEditorMove(x,y);
						break;
					case	_MIMO_RIGHT	:
						if ( visual_event(1) == _MIMO_UP ) {
							dependanceEditorMenu();
							return(257);
							}
					}
				return( 256 );
			}
		}

}

/*	------------------------------------------------	*/
/*	    d e p e n d a n c e E d i t o r F o c u s ( )    	*/
/*	------------------------------------------------	*/
int	dependanceEditorFocus()
{
	int	event;
	int	awctrue;
	while(1) {
		switch ( VSE.outofdate ) {
			case	2 :
				dependanceEditorRemove();
				dependanceEditorCreate();
			case	1 :
				dependanceEditorShow();
				VSE.outofdate = 0;
			}
		while ((event = dependanceModelFocus( VSE.current )) == 256) {
			if ((event = dependanceZoomEvent( visual_event(7), visual_event(6) )) != -1)
				continue;
			else if ((event = dependanceEditorEvent( visual_event(7), visual_event(6) )) == 256 )
				continue;
			else if ( event == 257 )
				break;
			else if ((event = handle_event()) == 256)
				continue;
			else	break;
			}
		switch ( event ) {
			case	 2		: /* HOME / END */
				if (!( VSE.current ))
					continue;
				else if ( VSE.current->next )
					VSE.current = VSE.last;
				else	VSE.current = VSE.first;
				continue;
	
			case	5		: /* NEXT 	FORM_MEMBER 	*/
				if (!( VSE.current ))
					continue;
				else if (!( VSE.current->current ))
					continue;
				else if (!( VSE.current->current->next ))
					continue;
				else 	{
					VSE.current->current = VSE.current->current->next;
					continue;
					}
				
			case	11		: /* PREVIOUS 	FORM_MEMBER 	*/
				if (!( VSE.current ))
					continue;
				else if (!( VSE.current->current ))
					continue;
				else if (!( VSE.current->current->previous ))
					continue;
				else 	{
					VSE.current->current = VSE.current->current->previous;
					continue;
					}

			case	 6		: /* NEXT 	MODEL 	*/
				if (!( VSE.current ))
					continue;
				else if ( VSE.current->next )
					VSE.current = VSE.current->next;
				continue;

			case	8		: /* PREVIOUS 	MODEL 	*/
				if (!( VSE.current ))
					continue;
				else if ( VSE.current->previous )
					VSE.current = VSE.current->previous;
				continue;

			case	0x0012		: /* PREVIOUS	PAGE  	*/
				if ( VSE.ymargin  > (VSE.h / 8 ))
					VSE.ymargin -= (VSE.h / 8);
				else	VSE.ymargin = 0;
				dependanceEditorRefresh();
				continue;

			case	0x0003		: /* NEXT	PAGE	*/
				VSE.ymargin += (VSE.h / 8);
				dependanceEditorRefresh();
				continue;

			case	0x0009		: /* Page Right */
				VSE.xmargin += (VSE.w / 4);
				dependanceEditorRefresh();
				continue;

			case	0x0000		: /* Page Left */
				VSE.xmargin -= (VSE.w / 4);
				dependanceEditorRefresh();
				continue;

			case	0x001C		: /* Home	*/
			case	0x000C		: /* Home	*/
				VSE.ymargin = 0;
				VSE.xmargin = 0;
				dependanceEditorRefresh();
				continue;

			case	0x000A		: /* New Line */
				VSE.xmargin = 0;
				dependanceEditorRefresh();
				continue;

			case	_FILE_SAVE	:
				if ( Context.Camera ) {
					dependanceEditorRemove();
					save_Camera(Context.Camera,0);
					dependanceEditorCreate();
					dependanceEditorShow();
					}
				continue;

			case	_FILE_QSAVE	:
				if ( Context.Camera ) {
					dependanceEditorRemove();
					save_Camera(Context.Camera,QUICK);
					dependanceEditorCreate();
					dependanceEditorShow();
					}
				continue;

			case _EDIT_IMAGE	:	
			case _EDIT_TEXT 	:
			case _EDIT_FONT 	:
			case _EDIT_STYLE 	:
			case _EDIT_FORM		:
			case _EDIT_FLOWCHART	:
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
/*		d e p e n d a n c e _ e d i t o r ()		*/
/*	-------------------------------------------------	*/
int	style_model_editor()
{
#ifdef	SING_MODEL_EDITOR
	int	event=0;
	char *	eptr;
	(void) set_context_dataview(3);
	calculate_style_derivations();
	dependanceEditorInitialise();
	dependanceEditorCreate();
	VSE.outofdate=1;
	dependanceEditorChoose();
	event = dependanceEditorFocus();
	dependanceEditorHide();
	dependanceEditorRemove();
	dependanceEditorLiberate();
	(void) set_context_dataview(0);
	draw_console();
	return( event );
#else
	return(0);
#endif
}

int	dependance_copied_class()
{
	if ( VSE.copied_model )
		return(1);
	else	return(0);
}

int	dependance_copied_member()
{
	if ( VSE.copied_member )
		return(1);
	else	return(0);
}


#endif	/* _singsmed_c */
	/* ----------- */


