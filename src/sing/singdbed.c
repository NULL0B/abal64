#ifndef	_singdbed_c
#define	_singdbed_c

#include "singdbed.h"

public	void	recalculate_file_sizes( struct file_control * fptr );

struct	visual_database_editor VDE = {

	(struct	visual_database_model  *) 0,	/* first   		*/
	(struct	visual_database_model  *) 0,	/* last	   		*/
	(struct	visual_database_model  *) 0,	/* current 		*/
	(struct	visual_database_model  *) 0,	/* solo	   		*/
	(char *) 0,				/* name	   		*/
	1,					/* hyper space view	*/
	4,					/* fractioning		*/
	1,					/* bubble control 	*/
	0,0,					/* x and y margins 	*/
	0,0,0,0,				/* x y w h 	   	*/
	50,					/* xpadding	   	*/
	50,					/* xpadding	   	*/
	10,					/* trace padding   	*/
	0,					/* debug trace route	*/
	50,					/* recursive tracedepth */
	0,					/* relation tracer 	*/
	3,					/* trace line width	*/
	1,					/* trace line color	*/
	0					/* not inhibited 	*/
	};

struct visual_database_relation * databaseRelationRemove( struct visual_database_relation * rptr );
void	databaseMemberShow(struct visual_database_member * mptr );
struct visual_database_model * databaseModelRemove(struct visual_database_model * mptr );
struct visual_database_member * databaseModelCreate();
void	databaseCalculateHyperView();
void	databaseEditorRefresh();
void	limit_right_space(char * wptr, int wlen );
void	databaseEditorLock();

/*	--------------------------------------------------	*/
/*		d a t a b a s e O u t O f D a t e ()		*/
/*	--------------------------------------------------	*/
private	void	databaseOutOfDate()
{
	context_is_outofdate(Context.Camera,1);
	return;
}

/*	----------------------------------------	*/
/*	 d a t a b a s e Z o n e R e s e t   ()		*/
/*	----------------------------------------	*/
void	databaseZoneReset( struct style_zone * zptr )
{
	if ( zptr ) {
		zptr->x = zptr->y = zptr->w = zptr->h = 0;
		}
	return;
}

/*	----------------------------------------	*/
/*	 d a t a b a s e Z o n e E v e n t   ()		*/
/*	----------------------------------------	*/
int	databaseZoneEvent( struct style_zone * zptr, int mx, int my )
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

/*	----------------------------------------	*/
/*	 d a t a b a s e T r a c e L i n e   ()		*/
/*	----------------------------------------	*/
void	databaseTraceLine( int sx, int sy, int tx, int ty )
{
	if ( sx == tx ) {
		if ( sy > ty ) {
			if ( visual_element( sx, ty, 1, (sy-ty), _STYLE_DATABASE_TRACE_NORTH, " ", 0) )
				visual_line(	sx,	sy,	tx,	ty, VDE.tracewidth, VDE.tracecolour );
			}
		else if ( visual_element( sx, sy, 1, (ty-sy), _STYLE_DATABASE_TRACE_SOUTH, " ", 0) )
			visual_line(	sx,	sy,	tx,	ty, VDE.tracewidth, VDE.tracecolour );
		}
	else	{
		if ( sx > tx ) {
			if ( visual_element( tx, sy, (sx-tx),1, _STYLE_DATABASE_TRACE_WEST, " ", 0) )
				visual_line(	sx,	sy,	tx,	ty, VDE.tracewidth, VDE.tracecolour );
			}
		else if ( visual_element( sx, sy, (tx-sx),1, _STYLE_DATABASE_TRACE_EAST, " ", 0) )
			visual_line(	sx,	sy,	tx,	ty, VDE.tracewidth, VDE.tracecolour );
		}
	return;
}

/*	----------------------------------------	*/
/*	 d a t a b a s e T r a c e P o i n t ()		*/
/*	----------------------------------------	*/
void	databaseTracePoint( int sx, int sy )
{
	if ( visual_element( sx, sy, 1, 1, _STYLE_DATABASE_TRACE_POINT, " ", 0) )
		visual_line(	sx,	sy,	sx, sy, VDE.tracewidth, VDE.tracecolour );
	return;
}

/*	------------------------------------------------	*/
/*	  d a t a b a s e T e x t W i d t h ( m, s, f ) 	*/
/*	------------------------------------------------	*/
int	databaseTextWidth( char * message, char * style, int fid )
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
/*	d a t a b a s e T e x t H e i g h t ( m, s, f ) 	*/
/*	------------------------------------------------	*/
int	databaseTextHeight( char * message, char * style, int fid )
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

struct	visual_database_model * databaseModelResolve( char * nptr )
{
	struct	visual_database_model  * mptr;
	int	n;
	char	classname[256];
	for ( n=0; *(nptr+n) != 0; n++ )
		if ((classname[n] = *(nptr+n)) == ' ' )
			break;
	classname[n] = 0;
	for (	mptr=VDE.first;
		mptr != (struct	visual_database_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->name ))
			continue;
		else if (!( strcmp( classname , mptr->name ) ))
			break;
		}
	return( mptr );
}

void	databaseHelpShow( char * mptr, char * sptr )
{
	VDE.bubble.x = visual_event(7);
	VDE.bubble.y = visual_event(6);
	if ( VDE.bubblehelp ) {
		VDE.bubble.w = 220; VDE.bubble.h = 120;
		}
	else if (!( sptr )) 
		return;
	else	{
		VDE.bubble.w = 20; VDE.bubble.h = 20;
		}
	if (!( VDE.bubblezone = visual_buffer(VDE.bubble.x,VDE.bubble.y,VDE.bubble.w,VDE.bubble.h) ))
		return;
	else	{
		visual_buffer_get(VDE.bubblezone, VDE.bubble.x, VDE.bubble.y );
		if ( sptr ) {
			visual_element(VDE.bubble.x,VDE.bubble.y, 
				10,15, sptr, " ", 0);
			}
		if ( VDE.bubblehelp ) {
			visual_element(VDE.bubble.x+20,VDE.bubble.y+20, 
				200, 100, _STYLE_DATABASE_BUBBLE_FRAME, mptr, strlen( mptr ));
			}
		return;
		}
}

void	databaseHelpHide()
{
	if ( VDE.bubblezone ) {
		visual_buffer_put(VDE.bubblezone, VDE.bubble.x, VDE.bubble.y );
		visual_drop( VDE.bubblezone );
		VDE.bubblezone = (void *) 0;
		}
	return;
}


/*	--------------------------------------------------------	*/
/*									*/
/*	    D A T B A S E   R E L A T I O N   M E T H O D S		*/
/*									*/
/*	--------------------------------------------------------	*/

/*	-------------------------------------------------	*/
/*	  d a t a b a s e R e l a t i o n D e f i n e ()  	*/
/*	-------------------------------------------------	*/
struct	visual_database_member * databaseRelationDefine()
{
	int	event;
	/* Allow user to click on something else */
	/* ------------------------------------- */
	mouse_move_on();
	while (1) {
		databaseHelpShow("select the target member of the relation, or press escape to cancel the operation",
				_STYLE_DATABASE_RELATION_TARGET);
		event = visual_getch();
		databaseHelpHide();
		if ( event == 27 )
			return( (struct	visual_database_member *) 0 );
		else if ( event != 256 )
			continue;
		else if ( visual_event(1) == _MIMO_UP )
			break;
		}
	mouse_move_off();
	if ( databaseEditorEvent( visual_event(7), visual_event(6)) != 256 )
		return((struct visual_database_member*) 0);
	else if (!( VDE.current ))
		return((struct visual_database_member*) 0);
	else	return( VDE.current->current );
}

/*	-------------------------------------------------	*/
/*	       d a t a b a s e L i n k M o v e ()              	*/
/*	-------------------------------------------------	*/
int	databaseLinkMove(struct visual_database_relation * rptr )
{
	struct	visual_database_model  * pptr;
	struct	visual_database_member * wptr;

	if (!( wptr = databaseRelationDefine()))
		return(0);
	else if (!( rptr->relation ))
		return(0);
	else if (!( pptr = wptr->parent ))
		return(0);
	else	{
		if ( rptr->relation->target )
			liberate( rptr->relation->target );
		if (( rptr->relation->target = allocate((strlen(wptr->name)+strlen(pptr->name)+3))) != (char *) 0) { 
			sprintf(rptr->relation->target,"%s.%s",pptr->name,wptr->name);			
			rptr->target = wptr;
			databaseEditorShow();
			}
		databaseOutOfDate();
		return(1);
		}
}
		
/*	-------------------------------------------------	*/
/*	       d a t a b a s e L i n k C h a n g e ()          	*/
/*	-------------------------------------------------	*/
int	databaseLinkChange(struct visual_database_relation * rptr )
{
	struct	visual_database_model  * pptr;
	struct	visual_database_member * wptr;

	if (!( wptr = databaseRelationDefine(1)))
		return(0);
	else if (!( rptr->relation ))
		return(0);
	else if (!( pptr = wptr->parent ))
		return(0);
	else	{
		if ( rptr->relation->source )
			liberate( rptr->relation->source );
		if (( rptr->relation->source = allocate((strlen(wptr->name)+strlen(pptr->name)+3))) != (char *) 0) { 
			sprintf(rptr->relation->source,"%s.%s",pptr->name,wptr->name);			
			if (!( rptr->previous ))
				rptr->source->first = rptr->next;
			else	rptr->previous->next = rptr->next;
			if (!( rptr->next ))
				rptr->source->last = rptr->previous;
			else	rptr->next->previous = rptr->previous;
			if (!( rptr->previous = wptr->last))
				wptr->first = rptr;
			else	wptr->last->next = wptr;
			wptr->last = rptr;
			rptr->next = (struct visual_database_relation *) 0;
			rptr->source = wptr;
			databaseEditorShow();
			}
		databaseOutOfDate();
		return(1);
		}
}
		
/*	-------------------------------------------------	*/
/*	       d a t a b a s e L i n k D e l e t e()           	*/
/*	-------------------------------------------------	*/
/*	-------------------------------------------------	*/
/*	       d a t a b a s e L i n k D e l e t e()           	*/
/*	-------------------------------------------------	*/
int	databaseLinkDelete(struct visual_database_relation * rptr)
{
	struct visual_database_model 	* smptr;
	struct visual_database_member 	* sptr;
	struct visual_database_model 	* tmptr;
	struct visual_database_member 	* tptr;
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
		databaseRelationRemove( rptr );		
		databaseEditorShow();
		databaseOutOfDate();
		return(1);
		}

}

/*	-------------------------------------------------	*/
/*	       d a t a b a s e L i n k I n f o ()              	*/
/*	-------------------------------------------------	*/
int	databaseLinkInfo(struct visual_database_relation * rptr)
{
	struct visual_database_model 	* smptr;
	struct visual_database_member 	* sptr;
	struct visual_database_model 	* tmptr;
	struct visual_database_member 	* tptr;
	int				  lnature;
	int				  rnature;
	if (!( sptr = rptr->source ))
		return(0);
	else if (!( tptr = rptr->target ))
		return(0);
	else if (!( smptr = sptr->parent ))
		return(0);
	else if (!( tmptr = tptr->parent ))
		return(0);
	else 	{
		lnature = (rptr->nature & 0x000F);
		rnature = ((rptr->nature & 0x00F0) >> 4);
		if ( accept_database_relation(&rptr->name,&rptr->jointure,&lnature,&rnature,&smptr->name,&sptr->name,&rptr->inhibit,&tmptr->name,&tptr->name) != 27 ) {
			rptr->nature = ((lnature & 0x000F) | (( rnature & 0x000F) << 4));
			if ( rptr->relation ) {
				if ( rptr->relation->name )
					liberate( rptr->relation->name );
				rptr->relation->name = allocate_string( rptr->name );
				if ( rptr->relation->jointure )
					liberate( rptr->relation->jointure );
				rptr->relation->jointure = allocate_string( rptr->jointure );
				rptr->relation->nature = rptr->nature;
				rptr->relation->inhibit= rptr->inhibit;
				}
			databaseEditorRemove();
			databaseEditorCreate();
			databaseEditorShow();
			return(1);
			}
		}
	return(0);
}

/*	-------------------------------------------------	*/
/*	       d a t a b a s e L i n k M e n u ()              	*/
/*	-------------------------------------------------	*/
int	databaseLinkMenu(struct visual_database_relation * rptr)
{
	switch ( database_link_menu() ) {
		case	_LINK_INFO	:
			return(databaseLinkInfo( rptr ));
		case	_LINK_DELETE	:
			return(databaseLinkDelete( rptr ));
		case	_LINK_MOVE	:
			return(databaseLinkMove(rptr));
		}
	return(0);
}
		
/*	--------------------------------------------------------	*/
/*	  d a t a b a s e R e l a t i o n E v e n t  ( rptr )		*/
/*	--------------------------------------------------------	*/
int	databaseRelationEvent( struct visual_database_member * mptr, int mx, int my )
{
	struct visual_database_relation * rptr;
	struct visual_database_member 	* sptr;
	struct visual_database_member 	* tptr;
	struct visual_database_model 	* smptr;
	struct visual_database_model 	* tmptr;

	for (	rptr = mptr->first;
		rptr != (struct visual_database_relation *) 0;
		rptr = rptr->next ) {
		if (!( sptr = rptr->source ))
			continue;
		else if (!( tptr = rptr->target ))
			continue;
		else if (!( smptr = sptr->parent ))
			continue;
		else if (!( tmptr = tptr->parent ))
			continue;

		/* Merise Type Relation Box Event */
		/* ------------------------------ */
		if ( databaseZoneEvent(&rptr->label, mx, my ) ) {
			if (( visual_event(1) == _MIMO_UP) 
			&&  ( visual_event(2) == _MIMO_RIGHT))
				return( databaseLinkMenu( rptr ) );
			else	return( 0 );
			}
		
		/* Relation Source Padd */
		/* -------------------- */
		else if ( databaseZoneEvent(&rptr->left, mx, my ) ) {
			if (( visual_event(1) == _MIMO_UP) 
			&&  ( visual_event(2) == _MIMO_RIGHT))
				return( databaseLinkMenu( rptr ) );
			else if (( visual_event(1) == _MIMO_DOWN)
			     &&  ( visual_event(2) == _MIMO_LEFT))
				return( databaseLinkChange( rptr ) );
			}

		/* Relation Target Padd */
		/* -------------------- */
		else if ( databaseZoneEvent(&rptr->right, mx, my ) ) {
			if (( visual_event(1) == _MIMO_UP) 
			&&  ( visual_event(2) == _MIMO_RIGHT))
				return( databaseLinkMenu( rptr ) );
			else if (( visual_event(1) == _MIMO_DOWN)
			     &&  ( visual_event(2) == _MIMO_LEFT))
				return( databaseLinkMove( rptr ) );
			}
		}
	return(0);
}

/*	---------------------------------------------------------	*/
/*	d a t a b a s e M o d e l R e l a t i o n E v e n t(rptr)	*/
/*	---------------------------------------------------------	*/
int	databaseModelRelationEvent( struct visual_database_model * mptr, int mx, int my )
{
	struct	visual_database_member * bptr;
	if ((( visual_event(1) == _MIMO_UP  ) &&  ( visual_event(2) == _MIMO_RIGHT))
	||  (( visual_event(1) == _MIMO_DOWN) &&  ( visual_event(2) == _MIMO_LEFT ))) {
		for ( 	bptr = mptr->first;
			bptr != (struct visual_database_member *) 0;
			bptr = bptr->next ) {
			if (!( databaseRelationEvent( bptr, mx, my ) ))
				continue;
			else	return(256);
			}
		}
	return(0);
}
/*	--------------------------------------------------------	*/
/*	  d a t a b a s e R e l a t i o n R e m o v e ( rptr )		*/
/*	--------------------------------------------------------	*/
struct visual_database_relation * databaseRelationRemove( struct visual_database_relation * rptr )
{
	if ( rptr->name )
		liberate( rptr->name );
	if ( rptr->jointure )
		liberate( rptr->jointure );
	liberate( rptr );
	databaseOutOfDate();
	return((struct visual_database_relation *) 0);
}

/*	--------------------------------------------------------	*/
/*	  d a t a b a s e R e l a t i o n C r e a t e ( )     		*/
/*	--------------------------------------------------------	*/
struct visual_database_relation * databaseRelationCreate()
{
	struct visual_database_relation * rptr;

	if (!( rptr = allocate( sizeof( struct visual_database_relation ) ) ))
		return( rptr );

	else	{
		rptr->name = (char *) 0;
		rptr->jointure = (char *) 0;
		rptr->next = rptr->previous = (struct visual_database_relation *) 0;
		rptr->source = rptr->target = (struct visual_database_member *) 0;
		rptr->relation = (struct link_control *) 0;
		rptr->nature = 0;
		rptr->inhibit = 0;
		databaseZoneReset(&rptr->label);
		databaseZoneReset(&rptr->left);
		databaseZoneReset(&rptr->right);
		databaseOutOfDate();
		return( rptr );
		}
}

struct visual_database_relation * databaseRelationCopy( struct visual_database_relation * sptr )
{
	struct visual_database_relation * rptr;
	if (( rptr = databaseRelationCreate()) != (struct visual_database_relation *) 0) {
		if (( sptr->name ) &&  (!( rptr->name = allocate_string( sptr->name ))))
			return( databaseRelationRemove(rptr) );
		if (( sptr->jointure ) &&  (!( rptr->jointure = allocate_string( sptr->jointure ))))
			return( databaseRelationRemove(rptr) );
		rptr->inhibit = sptr->inhibit;
		rptr->nature = sptr->nature;
		rptr->target = sptr->target;
		}
	return( rptr );
}
	

#include "singroot.c"

/*	------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r S h o w ( mptr ) 	*/
/*	------------------------------------------------	*/
void	databaseRelationShow(struct visual_database_relation * rptr )
{
	int	btw,bth;
	int	bx,by,bw,bh;
	int	sx,sy;
	int	sph;
	int	spy;
	int	tx,ty;
	int	tph;
	int	tpy;
	int	mx,my;
	int	reverse=0;
	char	cardzone[64];
	struct visual_database_member * sptr;
	struct visual_database_member * tptr;
	struct visual_database_model  * smptr;
	struct visual_database_model  * tmptr;

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

	databaseZoneReset(&rptr->label);
	databaseZoneReset(&rptr->left);
	databaseZoneReset(&rptr->right);

	if ( rptr->inhibit )
		strcpy(cardzone," # ");
	else if ( VDE.schema != _SCHEMA_UML ) {
		switch ( rptr->nature & 0x000F) {
			case	0 : strcpy(cardzone,"0,1"); break;
			case	1 : strcpy(cardzone,"1,1"); break;
			case	2 : strcpy(cardzone,"0,n"); break;
			case	3 : strcpy(cardzone,"1,n"); break;
			default	  : strcpy(cardzone,"?,?"); break;
			}
		}
	else	{
		switch ( rptr->nature & 0x00FF) {
			case	0x0000 : strcpy(cardzone,"0,0"); break;
			case	0x0001 : strcpy(cardzone,"1,0"); break;
			case	0x0002 : strcpy(cardzone,"*,0"); break;
			case	0x0003 : strcpy(cardzone,"*,1"); break;
			case	0x0010 : strcpy(cardzone,"1,1"); break;
			case	0x0020 : strcpy(cardzone,"1,*"); break;
			case	0x0030 : strcpy(cardzone,"1,*"); break;
			case	0x0011 : strcpy(cardzone,"1,1"); break;
			case	0x0021 : strcpy(cardzone,"1,*"); break;
			case	0x0031 : strcpy(cardzone,"1,*"); break;
			case	0x0012 : strcpy(cardzone,"*,1"); break;
			case	0x0022 : strcpy(cardzone,"*,*"); break;
			case	0x0032 : strcpy(cardzone,"*,*"); break;
			case	0x0013 : strcpy(cardzone,"*,1"); break;
			case	0x0023 : strcpy(cardzone,"*,*"); break;
			case	0x0033 : strcpy(cardzone,"*,*"); break;
			default	  : strcpy(cardzone,"?,?"); break;
			}
		}
	rptr->right.w = rptr->left.w = (databaseTextWidth ( cardzone, _STYLE_DATABASE_RELATION_SOURCE, 1) + 2);
	rptr->right.h = rptr->left.h = (databaseTextHeight( cardzone, _STYLE_DATABASE_RELATION_SOURCE, 1) + 2);

	/* Calculate Source Padd Position */
	/* ------------------------------ */
	if ( sptr->x > tptr->x ) {			/* TX+TW  <---------- SW */
		reverse = 1;
		rptr->left.x  = (sptr->x-rptr->left.w);		
		sx = rptr->left.x;
		rptr->right.x = (tptr->x+tptr->w); 	
		tx = (rptr->right.x + rptr->right.w);
		}
	else	{					/* SX+SW -----------> TX */
		reverse = 0;
		rptr->left.x  = (sptr->x + sptr->w);
		sx = (rptr->left.x + rptr->left.w);
		rptr->right.x = (tptr->x-rptr->right.w);
		tx = rptr->right.x;
		}

	
	if (!( smptr->state )) {
		if ( sptr->h > rptr->left.h)
			spy = sptr->y+((sptr->h-rptr->left.h)/2);
		else	spy = sptr->y;
		}
	else	{
		if ( smptr->h > rptr->left.h)
			spy = smptr->y+((smptr->h-rptr->left.h)/2);
		else	spy = smptr->y;
		}

	rptr->left.y = spy;
	sy = (rptr->left.y + (rptr->left.h/2));
	sph = rptr->left.h;

	if ( visual_element(rptr->left.x,rptr->left.y,rptr->left.w,rptr->left.h,
		( sx < tx ? _STYLE_DATABASE_RELATION_SOURCE_LEFT : _STYLE_DATABASE_RELATION_SOURCE_RIGHT ),
		cardzone,strlen(cardzone)) != 0) 
		visual_frame(rptr->left.x,rptr->left.y,rptr->left.w,rptr->left.h,_EDIT_FRAME);

	/* target is inhibited */
	/* ------------------- */
	if ( tmptr->inhibit ) 
		return;
	else if (!( tmptr->state )) {
		if ( tptr->h > rptr->right.h )
			tpy = tptr->y+((tptr->h-rptr->right.h)/2);
		else	tpy = tptr->y;
		}
	else	{
		if ( tmptr->h > rptr->right.h )
			tpy = tmptr->y+((tmptr->h-rptr->right.h)/2);
		else	tpy = tmptr->y;
		}
	
	tph = rptr->right.h;
	rptr->right.y = tpy;
	ty = (rptr->right.y + (rptr->right.h/2));

	if ( rptr->inhibit )
		strcpy(cardzone," # "); 
	else if ( VDE.schema != _SCHEMA_UML ) {
		switch ((( rptr->nature & 0x00F0) >> 4)) {
			case	0 : strcpy(cardzone,"0,1"); break;
			case	1 : strcpy(cardzone,"1,1"); break;
			case	2 : strcpy(cardzone,"0,n"); break;
			case	3 : strcpy(cardzone,"1,n"); break;
			default	  : strcpy(cardzone,"?,?"); break;
			}
		}

	if ( visual_element(rptr->right.x,rptr->right.y,rptr->right.w,rptr->right.h,
		( sx > tx ? _STYLE_DATABASE_RELATION_TARGET_LEFT : _STYLE_DATABASE_RELATION_TARGET_RIGHT ),
		cardzone,strlen(cardzone)))
		visual_frame(rptr->right.x,rptr->right.y,rptr->right.w,rptr->right.h,_EDIT_FRAME);

	if (!( VDE.bender )) {
		/* trace it as the crow flies */
		/* -------------------------- */
		visual_line(	sx,	sy,	tx,	ty, VDE.tracewidth, VDE.tracecolour );
		}
	else if ( VDE.bender == 2 ) {
		if ( VDE.debug_trace_route ) {
			printf("Relation : %s(%u,%u) -> %s(%u,%u)\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		databaseTraceRoute( sx,sy,tx,ty, 0, reverse);
		if ( VDE.debug_trace_route ) {
			printf("\tEndRelation\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		}
	else if ( sy == ty ) {
		databaseTraceLine(sx,sy,tx,ty);
		}
	else if ( sx == tx ) {
		databaseTraceLine(sx,sy,tx,ty);
		}
	else if ( sx > tx ) {
		mx = (tx + ((sx - tx) / 2));
		databaseTraceLine(sx,sy,mx,sy);
		databaseTraceLine(mx,sy,mx,ty);
		if ( sy < ty )
			databaseTracePoint(mx,ty);
		databaseTraceLine(mx,ty,tx,ty);
		}
	else 	{
		mx = (sx + ((tx - sx) / 2));
		databaseTraceLine(sx,sy,mx,sy);
		if ( sy > ty )
			databaseTracePoint(mx,sy);
		databaseTraceLine(mx,sy,mx,ty);
		databaseTraceLine(mx,ty,tx,ty);
		}
	if ( VDE.schema == _SCHEMA_MERISE ) {

		if ((bw =  (databaseTextWidth( rptr->name, _STYLE_DATABASE_RELATION_FRAME, 0) + 2))
		>   (btw = (databaseTextWidth( rptr->name, _STYLE_DATABASE_RELATION_LABEL, 0) + 2)))
			btw = bw;

		if ((bh =  (databaseTextHeight( rptr->name, _STYLE_DATABASE_RELATION_FRAME, 0) + 2))
		>  (bth = (databaseTextHeight( rptr->name, _STYLE_DATABASE_RELATION_LABEL, 0) + 2)))
			bth = bh;

		bw = ( rptr->right.x > rptr->left.x ? ((rptr->right.x-rptr->left.x)) : ((rptr->left.x-rptr->right.x)));
		bh = ( rptr->right.y > rptr->left.y ? ((rptr->right.y-rptr->left.y)) : ((rptr->left.y-rptr->right.y)));
		bx = ( rptr->right.x > rptr->left.x ? ( rptr->left.x + ((bw/2) - (btw/2))) : ( rptr->right.x + ((bw/2) - (btw/2)) ));
		by = ( rptr->right.y > rptr->left.y ? ( rptr->left.y + ((bh/2) - (bth/2))) : ( rptr->right.y + ((bh/2) - (bth/2)) ));
		rptr->label.x = bx + (rptr->left.w/2); 
		rptr->label.y = by;
		rptr->label.w = btw; rptr->label.h = bth;
		visual_element(rptr->label.x,rptr->label.y,rptr->label.w,rptr->label.h,_STYLE_DATABASE_RELATION_FRAME," ",0);
		visual_element(rptr->label.x,rptr->label.y,rptr->label.w,rptr->label.h,_STYLE_DATABASE_RELATION_LABEL,rptr->name,strlen(rptr->name));
		}

	return;
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e F i l e R e l a t i o n( mptr ) 	*/
/*	------------------------------------------------	*/
void	databaseFileRelation(struct visual_database_member * sptr, struct visual_database_model * tptr )
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

	struct visual_database_model  * smptr;
	struct	form_item * iptr;
	struct	forms_method * pptr;
	if (!( sptr ))
		return;
	else if (!( smptr = sptr->parent ))
		return;

	databaseZoneReset(&sptr->left);
	databaseZoneReset(&sptr->right);

	if (!( tptr )) {
		if (!( smptr->state )) {
			sptr->right.w = sptr->left.w = (databaseTextWidth ( "N,N", _STYLE_DATABASE_RELATION_EXTERN, 1) + 2);
			sptr->right.h = sptr->left.h = (databaseTextHeight( "N,N", _STYLE_DATABASE_RELATION_EXTERN, 1) + 2);
			sptr->left.x = (sptr->x+sptr->w);
			sptr->left.y = (sptr->y+((sptr->h-sptr->left.h)/2));
			visual_element(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,_STYLE_DATABASE_RELATION_EXTERN," ",0); 
			}
		return;
		}

	sptr->right.w = sptr->left.w = (databaseTextWidth ( "N,N", _STYLE_DATABASE_RELATION_SOURCE, 1) + 2);
	sptr->right.h = sptr->left.h = (databaseTextHeight( "N,N", _STYLE_DATABASE_RELATION_SOURCE, 1) + 2);

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

	if ( visual_element(sptr->left.x,sptr->left.y,sptr->left.w,sptr->left.h,_STYLE_DATABASE_SOURCE_FILE," ",0)) 
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

	if ( visual_element(sptr->right.x,sptr->right.y,sptr->right.w,sptr->right.h,_STYLE_DATABASE_TARGET_FILE," ",0) )
		visual_frame(sptr->right.x,sptr->right.y,sptr->right.w,sptr->right.h,_EDIT_FRAME);


	if (!( VDE.bender )) {
		/* trace it as the crow flies */
		/* -------------------------- */
		visual_line(	sx,	sy,	tx,	ty, VDE.tracewidth, VDE.tracecolour );
		}
	else if ( VDE.bender == 2 ) {
		if ( VDE.debug_trace_route ) {
			printf("Relation : %s(%u,%u) -> %s(%u,%u)\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		databaseTraceRoute( sx,sy,tx,ty,0,reverse );
		if ( VDE.debug_trace_route ) {
			printf("\tEndRelation\r\n",sptr->name,sx,sy,tptr->name,tx,ty);
			}
		}
	else if ( sy == ty ) {
		databaseTraceLine(sx,sy,tx,ty);
		}
	else if ( sx == tx ) {
		databaseTraceLine(sx,sy,tx,ty);
		}
	else if ( sx > tx ) {
		mx = (tx + ((sx - tx) / 2));
		databaseTraceLine(sx,sy,mx,sy);
		databaseTraceLine(mx,sy,mx,ty);
		if ( sy < ty )
			databaseTracePoint(mx,ty);
		databaseTraceLine(mx,ty,tx,ty);
		}
	else 	{
		mx = (sx + ((tx - sx) / 2));
		databaseTraceLine(sx,sy,mx,sy);
		if ( sy > ty )
			databaseTracePoint(mx,sy);
		databaseTraceLine(mx,sy,mx,ty);
		databaseTraceLine(mx,ty,tx,ty);
		}
	return;
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r S h o w ( rptr ) 	*/
/*	------------------------------------------------	*/
void	databaseRelationSave(struct visual_database_relation * rptr )
{
	int	sx;
	int	sy;
	int	tx;
	int	ty;
	char * snptr;
	char * tnptr;

	struct visual_database_member * sptr;
	struct visual_database_member * tptr;
	struct visual_database_model  * smptr;
	struct visual_database_model  * tmptr;

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
		rptr->relation = create_database_link( rptr->name, rptr->jointure , snptr, tnptr, rptr->nature,rptr->inhibit);
		liberate( tnptr );
		liberate( snptr );
		databaseOutOfDate();
		return;
		}
}

/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E   M E M B E R   M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	--------------------------------------------------------------	*/
/*	d a t a b a s e M e m b e r D r o p R e l a t i o n s ( mptr )	*/
/*	--------------------------------------------------------------	*/
void	databaseMemberDropRelations(struct visual_database_member * mptr )
{
	struct visual_database_relation * rptr;
	while ((rptr = mptr->first) != ( struct visual_database_relation *) 0) {
		mptr->first = rptr->next;
		databaseRelationRemove( rptr );
		}
	mptr->first = mptr->last = (struct visual_database_releation *) 0;
}

/*	------------------------------------------------	*/
/*	d a t a b a s e M e m b e r R e m o v e ( mptr )	*/
/*	------------------------------------------------	*/
struct visual_database_member * databaseMemberRemove(struct visual_database_member * mptr )
{
	databaseMemberDropRelations( mptr );
	if ( mptr->name ) { liberate( mptr->name ); }
	liberate( mptr );
	return((struct visual_database_member *) 0);
}

/*	------------------------------------------------	*/
/*	d a t a b a s e M e m b e r R e s o l v e( xptr )	*/
/*	------------------------------------------------	*/
struct	database_application_member * databaseMemberResolve(char * xptr)
{
	struct visual_database_model  * aptr;
	struct visual_database_member * bptr;
	char 	work[512];
	char *	nptr;
	char * 	mptr;
	strcpy( work, xptr );
	for ( nptr = mptr = work; *mptr != 0; mptr++ )
		if ( *mptr == '.' )
			break;
	if ( *mptr == '.' )
		*(mptr++) = 0;

	for (	aptr=VDE.first;
		aptr != (struct visual_database_model *) 0;
		aptr = aptr->next ) {
		if (!( aptr->name ))
			continue;
		else if ( strcmp( aptr->name, nptr ) )
			continue;
		for (	bptr=aptr->first;
			bptr != (struct visual_database_member *) 0;
			bptr = bptr->next ) {
			if (!( bptr->name ))
				continue;
			else if (!( strcmp( bptr->name, mptr ) ))
				return( bptr );
			}
		}
	return((struct visual_database_member *) 0);
}

/*	------------------------------------------------	*/
/*	d a t a b a s e M e m b e r C r e a t e (      )	*/
/*	------------------------------------------------	*/
struct visual_database_member * databaseMemberCreate()
{
	struct visual_database_member * mptr;
	if ((mptr = allocate( sizeof( struct visual_database_member ) )) != (struct visual_database_member *) 0) {
		mptr->previous = mptr->next = (struct visual_database_member *) 0;
		mptr->x = mptr->y = mptr->w = mptr->h = 0;
		mptr->name = (char *) 0;
		mptr->nature=0;
		mptr->number=0;
		mptr->focus=0;
		mptr->parent=(struct visual_database_model *) 0;
		mptr->first = mptr->last = (struct visual_database_releation *) 0;
		}
	return( mptr );
}



/*	-------------------------------------------------	*/
/*	 d a t a b a s e M e m b e r E v e n t ( m,x,y ) 	*/
/*	-------------------------------------------------	*/
int	databaseMemberEvent(struct visual_database_member * mptr, int x, int y )
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
			return( databaseMemberMenu( mptr ) );
		else	return(1);
		}
}

/*	--------------------------------------------------	*/
/*	 d a t a b a s e M e m b e r S y n t a x ( m, b ) 	*/
/*	--------------------------------------------------	*/
int	databaseMemberSyntax( struct visual_database_member * mptr, char * rptr )
{
	struct	data_control * dptr;
	*rptr = 0;
	if (!( mptr ))
		return(0);
	else if (!( mptr->parent ))
		return(0);
	else if (!( dptr = mptr->parent->data ))
		return(0);
	else	{
		string_print_dcl(rptr,"\0",
			dptr->name[mptr->number], dptr->type[mptr->number],
			dptr->width[mptr->number],
			dptr->first[mptr->number], dptr->second[mptr->number],
			dptr->special[mptr->number],dptr->decimal[mptr->number] );
		return( strlen( rptr ) );
		}
}

/*	--------------------------------------------------	*/
/*	d a t a b a s e M e m b e r A n a l y s e ( m, b ) 	*/
/*	--------------------------------------------------	*/
int	databaseMemberAnalyse( struct visual_database_member * mptr, char * rptr, int rlen )
{
	int	i,l;
	struct	data_control * dptr;
	if (!( mptr ))
		return(0);
	else if (!( mptr->parent ))
		return(0);
	else if (!( dptr = mptr->parent->data ))
		return(0);
	else	{
		for (i=0,l=0; i < rlen; i++ )
			if ( *(rptr+i) != ' ' )
				l = (i+1);
		*(rptr+l) = 0;				
		analyse_variable_expression(
			rptr, strlen(rptr),
			&dptr->type[mptr->number],&dptr->width[mptr->number],
			&dptr->first[mptr->number],&dptr->second[mptr->number],
			&dptr->decimal[mptr->number],1
			);
		if ( dptr->name[mptr->number] ) {
			liberate( dptr->name[mptr->number]);
			}
		limit_right_space( rptr , strlen( rptr ) );
		dptr->name[mptr->number] = allocate_string( rptr );
		if ( mptr->name ) {
			liberate( mptr->name );
			}
		mptr->name = allocate_string( rptr );
		databaseOutOfDate();
		return(0);
		}
}

/*	-----------------------------------------------------------	*/
/*	  d a t a b a s e M e m b e r T e x t W i d t h ( m, s, f ) 	*/
/*	-----------------------------------------------------------	*/
int 	databaseMemberTextWidth(struct visual_database_member * mptr, char * style, int fid )
{
	char	workbuffer[512];
	if (!( mptr ))
		return(0);
	else if (!( databaseMemberSyntax( mptr, workbuffer ) ))
		return( 0 );
	else	return( databaseTextWidth( workbuffer, style, fid ) );
}

/*	---------------------------------------------------	*/
/*	d a t a b a s e M e m b e r L o s e F o c u s(mptr) 	*/
/*	---------------------------------------------------	*/
void	databaseMemberLoseFocus(struct visual_database_member * mptr )
{
	if ( mptr ) {
		if ( mptr->focus ) {
			databaseMemberShow(mptr);
			mptr->focus=0;
			}
		}
	return;
}

/*	-------------------------------------------------	*/
/*	d a t a b a s e M e m b e r G e t F o c u s(mptr) 	*/
/*	-------------------------------------------------	*/
void	databaseMemberGetFocus(struct visual_database_member * mptr )
{
	struct	visual_database_model * pptr;
	struct	data_control * dptr;
	char	workbuffer[512];
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if (!( dptr = pptr->data ))
		return;
	else	{
		databaseMemberLoseFocus( pptr->current );
		if (!( mptr->focus )) {
			string_print_dcl(workbuffer,"\0",
				dptr->name[mptr->number], dptr->type[mptr->number],
				dptr->width[mptr->number],
				dptr->first[mptr->number], dptr->second[mptr->number],
				dptr->special[mptr->number],dptr->decimal[mptr->number] );
			(void) visual_element( 
				mptr->x,mptr->y,mptr->w,mptr->h,
				( mptr->nature ? _STYLE_DATABASE_INDEX_FOCUS : _STYLE_DATABASE_MEMBER_FOCUS ),
				workbuffer, strlen( workbuffer )
				);
			if (!( dptr->special[mptr->number] & 1 )) {
				(void) visual_element( 
					mptr->x,mptr->y,mptr->w,mptr->h,
					( mptr->nature ? _STYLE_DATABASE_INDEX_LINK : _STYLE_DATABASE_MEMBER_LINK ),
					workbuffer, strlen( workbuffer )
					);
				}
			if ( dptr->special[mptr->number] & 2 ) {
				(void) visual_element( 
					mptr->x,mptr->y,mptr->w,mptr->h,
					( mptr->nature ? _STYLE_DATABASE_INDEX_LIST : _STYLE_DATABASE_MEMBER_LIST ),
					workbuffer, strlen( workbuffer )
					);
				}

			mptr->focus=1;
			}
		return;
		}
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r S h o w ( mptr ) 	*/
/*	------------------------------------------------	*/
void	databaseMemberShow(struct visual_database_member * mptr )
{
	struct	visual_database_model * pptr;
	struct	data_control * dptr;
	char	workbuffer[512];
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if (!( dptr = pptr->data ))
		return;
	if ( VDE.schema == _SCHEMA_UML ) {
		string_print_dcl(workbuffer,"\0",
			dptr->name[mptr->number], dptr->type[mptr->number],
			dptr->width[mptr->number],
			dptr->first[mptr->number], dptr->second[mptr->number],
			dptr->special[mptr->number],dptr->decimal[mptr->number] );
		}
	else	strcpy( workbuffer,mptr->name);

	if ( visual_element( 	
		mptr->x,mptr->y,mptr->w,mptr->h,
		( mptr->nature ? _STYLE_DATABASE_INDEX : _STYLE_DATABASE_MEMBER ),
		( workbuffer ? workbuffer : " " ), 
			( workbuffer ? strlen( workbuffer ) : 0 ) )) {

			/* Reset Zone otherwise */
			/* -------------------- */
			filzone	(
				mptr->x,mptr->y,
				mptr->w,mptr->h,
				_DEFAULT_GUI_WHITE);

		}
	else	{
		if (!(dptr->special[mptr->number] & 1 )) {
			(void) visual_element( 
				mptr->x,mptr->y,mptr->w,mptr->h,
				( mptr->nature ? _STYLE_DATABASE_INDEX_LINK : _STYLE_DATABASE_MEMBER_LINK ),
				workbuffer, strlen( workbuffer )
				);
			}
		if ( dptr->special[mptr->number] & 2 ) {
			(void) visual_element( 
				mptr->x,mptr->y,mptr->w,mptr->h,
				( mptr->nature ? _STYLE_DATABASE_INDEX_LIST : _STYLE_DATABASE_MEMBER_LIST ),
				workbuffer, strlen( workbuffer )
				);
			}	
		}
	return;
}

/*	---------------------------------------------------------------		*/
/*	 d a t a b a s e M e m b e r S h o w R e l a t i o n s ( mptr )   	*/
/*	---------------------------------------------------------------		*/
/*	Shows the explicite jointure type relations declared for the		*/
/*	members of the file class to other members of other file classes	*/
/*	---------------------------------------------------------------		*/
void	databaseMemberShowRelations(struct visual_database_member * mptr )
{
	struct	visual_database_relation  * rptr;
	for (	rptr = mptr->first;
		rptr != (struct visual_database_relation *) 0;
		rptr = rptr->next ) {
		databaseRelationShow( rptr );
		}
	return;
}

/*	---------------------------------------------------------------		*/
/*	 d a t a b a s e M e m b e r S h o w R e l a t i o n  ( mptr )   	*/
/*	---------------------------------------------------------------		*/
/*	Shows the implicite database file relation  declared for the		*/
/*	member  of the file class to other file model class.            	*/
/*	---------------------------------------------------------------		*/
void	databaseMemberShowRelation(struct visual_database_member * mptr )
{
	struct	visual_database_model * tptr;
	if (!( mptr ))	
		return;
	else if (!( mptr->name ))
		return;
	if (!( tptr = databaseModelResolve( mptr->name ) ))
		return;
	else	{
		databaseFileRelation(mptr, tptr );
		return;
		}
}

/*	-------------------------------------------------	*/
/*	 d a t a b a s e M e m b e r N a t u r e ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseMemberNature(struct visual_database_member * mptr)
{
	struct	visual_database_model * pptr;
	struct	data_control * dptr;
	char	workbuffer[512];
	char *	rptr=workbuffer;

	/* validate member, parent and file control */
	/* ---------------------------------------- */
	if (!( mptr ))				return(0);
	else if (!( pptr = mptr->parent ))	return(0);
	else if (!( dptr = pptr->data ))	return(0);
	else if ( dptr->type[mptr->number] == _ABAL_FIELD )
		return;
	else if ( dptr->type[mptr->number] == _ABAL_FILLER )
		return;
	else	FileManager->current = pptr->file;

	databaseOutOfDate();

	memset(workbuffer,' ',256);
	if (!( mptr ))
		return(0);
	else if (!( databaseMemberSyntax( mptr, workbuffer ) ))
		return(0);


	if ( mptr->nature ) {
		/* transform index to data */
		mptr->nature = 0;
		if ( mptr->number == (dptr->indexfields-1)) {
			if ( dptr->indexfields )
				dptr->indexfields--;
			dptr->datafields++;
			if ( pptr->file->nature != _VMEMORY_FRAME )
				check_file_datalength((void*) 0);
			databaseEditorRemove();
			databaseEditorCreate();
			databaseEditorShow();
			return(0);
			}
		else	{			
			delete_database_item( dptr, mptr->number );
			insert_database_item( dptr, mptr->number = (dptr->indexfields+dptr->datafields) );	
			}
		}
	else	{
		/* transform data to index */
		mptr->nature = 1;
		if ( mptr->number == dptr->indexfields) {
			dptr->indexfields++;
			if ( dptr->datafields )
				dptr->datafields--;
			if ( pptr->file->nature != _VMEMORY_FRAME )
				check_file_indexlength((void*) 0);
			databaseEditorRemove();
			databaseEditorCreate();
			databaseEditorShow();
			return(0);
			}
		else	{
			delete_database_item( dptr, mptr->number );
			insert_database_item( dptr, (mptr->number = dptr->indexfields) );
			}
		}
	analyse_variable_expression(
		rptr, strlen(rptr),
		&dptr->type[mptr->number],&dptr->width[mptr->number],
		&dptr->first[mptr->number],&dptr->second[mptr->number],
		&dptr->decimal[mptr->number],1
		);
	if ( dptr->name[mptr->number] ) {
		liberate( dptr->name[mptr->number]);
		}
	dptr->name[mptr->number] = allocate_string( rptr );
	if ( mptr->nature ) {
		if ( pptr->file->nature != _VMEMORY_FRAME )
			check_file_indexlength((void*) 0);
		}
	else	{
		if ( pptr->file->nature != _VMEMORY_FRAME )
			check_file_datalength((void*) 0);
		}
	databaseEditorRemove();
	databaseEditorCreate();
	databaseEditorShow();
	return;
}
	
/*	-------------------------------------------------	*/
/*	 d a t a b a s e M e m b e r D e f i n e ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseMemberDefine(struct visual_database_member * mptr)
{
	char	workbuffer[512];
	memset(workbuffer,' ',256);
	if (!( mptr ))
		return(0);
	else if (!( databaseMemberSyntax( mptr, workbuffer ) ))
		return(0);
	else	{
		visual_frame(	VDE.x+(mptr->x-VDE.xmargin),
				VDE.y+(mptr->y-VDE.ymargin),
			     	mptr->w, mptr->h,
				_EDIT_FRAME);

		if ( visual_edit( 
			VDE.x+(mptr->x-VDE.xmargin)+1,
			VDE.y+(mptr->y-VDE.ymargin)+1,
			mptr->w-2, mptr->h,
			Context.basefont,
			workbuffer, 255 ) != 27) {
			limit_right_space( workbuffer, 255);
			databaseOutOfDate();
			databaseMemberAnalyse(mptr, workbuffer,255);
			}
		return(1);
		}
}

/*	-----------------------------------------------		*/
/*	   d a t a b a s e M e m b e r N e w ( model )  	*/
/*	-----------------------------------------------		*/
void	databaseMemberNew(char * modname, int mid )
{
	struct	visual_database_model * pptr;
	struct	visual_database_member* mptr;
	if (!( modname ))
		return;
	for (	pptr=VDE.first;
		pptr != (struct visual_database_model *) 0;
		pptr = pptr->next ) {
		if (!( pptr->name ))
			continue;
		else if (!( strcmp( modname , pptr->name )))
			break;
		}
	if (!( pptr ))
		return;
	for (	mptr=pptr->first;
		mptr != (struct	visual_database_member*) 0;
		mptr = mptr->next) {
		if ( mptr->number == mid )
			break;
		}
	if ( mptr )
		databaseMemberDefine( mptr );
	return;
}

/*	-------------------------------------------------	*/
/*	  d a t a b a s e M e m b e r D e l e t e( model )  	*/
/*	-------------------------------------------------	*/
void	databaseMemberDelete(struct visual_database_member * mptr)
{
	struct	visual_database_model * pptr;
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if ( pptr->lock )
		return;
	else if (!( pptr->data ))
		return;
	else	{
		FileManager->current = pptr->file;
		delete_database_item( pptr->data, mptr->number );
		if ( pptr->file->nature != _VMEMORY_FRAME )
			check_file_datalength((void*) 0);
		databaseEditorRemove();
		databaseEditorCreate();
		databaseEditorShow();
		databaseOutOfDate();
		return;
		}
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r C o p y ( model )  	*/
/*	-------------------------------------------------	*/
struct visual_database_member * databaseMemberCopy(struct visual_database_member * sptr)
{
	struct visual_database_member * mptr;
	struct visual_database_relation * wptr;
	struct visual_database_relation * rptr;
	if ((mptr = databaseMemberCreate()) != (struct visual_database_member *) 0) {
		if (( sptr->name ) && (!( mptr->name = allocate_string( sptr->name ) )))
			return( databaseMemberRemove( mptr ) );
		else	{
			mptr->x = sptr->x;
			mptr->y = sptr->y;
			mptr->w = sptr->w;
			mptr->h = sptr->h;
			mptr->nature = sptr->nature;
			mptr->number = sptr->number;
			}
#ifdef	COPY_RELATIONS
		for (	wptr=sptr->first;
			wptr != (struct visual_database_relation *) 0;
			wptr = wptr->next ) {
			if (!( rptr = databaseRelationCopy( wptr )))
				return( databaseMemberRemove( mptr ) );
			if (!( rptr->previous = mptr->last ))
				mptr->first = rptr;
			else	rptr->previous->next = rptr;
			mptr->last = rptr;		
			rptr->source = mptr;
			}
#endif
		}
	return( mptr );
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r P a s t e ( model )  	*/
/*	-------------------------------------------------	*/
void	databaseMemberPaste(	struct visual_database_member * mptr, 
				struct visual_database_model * pptr )
{
	return;
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r L i n k   ( model )  	*/
/*	-------------------------------------------------	*/
void	databaseMemberLink(	struct visual_database_member * mptr	)
{
	struct	visual_database_model * pptr;
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if (!( pptr->data ))
		return;
	else if ( pptr->data->type[mptr->number] == _ABAL_FIELD )
		return;
	else if ( pptr->data->type[mptr->number] == _ABAL_FILLER )
		return;
	else if ( pptr->data->special[mptr->number] & 1 )
		pptr->data->special[mptr->number] &= ~1;
	else 	pptr->data->special[mptr->number] |= 1;

	return;
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r L i s t   ( model )  	*/
/*	-------------------------------------------------	*/
void	databaseMemberList(	struct visual_database_member * mptr	)
{
	struct	visual_database_model * pptr;
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if (!( pptr->data ))
		return;
	else if ( pptr->data->type[mptr->number] == _ABAL_FIELD )
		return;
	else if ( pptr->data->type[mptr->number] == _ABAL_FILLER )
		return;
	else if ( pptr->data->special[mptr->number] & 2 )
		pptr->data->special[mptr->number] &= ~2;
	else 	pptr->data->special[mptr->number] |= 2;

	return;
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r A f t e r ( model )  	*/
/*	-------------------------------------------------	*/
void	databaseMemberAfter(	struct visual_database_member * mptr, 
				struct visual_database_model * pptr )
{
	int	mid;
	char *	modname;
	if (!( pptr ))
		return;
	else if (!( pptr->data ))
		return;
	else if (!(modname = allocate_string( pptr->name )))
		return;
	else	{
		FileManager->current = pptr->file;
		insert_database_item( pptr->data,mid = ( mptr ? (mptr->number+1) : 0) );
		if ( pptr->file->nature != _VMEMORY_FRAME )
			check_file_datalength((void*) 0);
		databaseEditorRemove();
		databaseEditorCreate();
		databaseEditorShow();
		databaseMemberNew( modname, mid );
		databaseEditorShow();
		}
	return;
}

/*	-------------------------------------------------	*/
/*	  d a t a b a s e M e m b e r B e f o r e( model )  	*/
/*	-------------------------------------------------	*/
void	databaseMemberBefore(struct visual_database_member * mptr)
{
	int	mid;
	char *	modname;
	struct	visual_database_model * pptr;
	if (!( mptr ))
		return;
	else if (!( pptr = mptr->parent ))
		return;
	else if (!( pptr->data ))
		return;
	else if (!(modname = allocate_string( pptr->name )))
		return;
	else	{
		FileManager->current = pptr->file;
		insert_database_item( pptr->data, mid = mptr->number);
		if ( pptr->file->nature != _VMEMORY_FRAME )
			check_file_datalength((void*) 0);
		databaseEditorRemove();
		databaseEditorCreate();
		databaseEditorShow();
		databaseMemberNew( modname, mid );
		databaseEditorShow();
		return;
		}
}

/*	-------------------------------------------------	*/
/*	  d a t a b a s e M e m b e r R e l a t i o n (m)  	*/
/*	-------------------------------------------------	*/
void	databaseMemberRelation(struct visual_database_member * sptr)
{
	struct visual_database_model * smptr;
	struct visual_database_model * tmptr;

	struct visual_database_member * tptr;
	struct visual_database_relation * rptr;

	if (!( smptr = sptr->parent ))
		return;
	else if (!( smptr->data ))
		return;
	else if ( smptr->data->type[sptr->number] == _ABAL_FIELD )
		return;
	else if ( smptr->data->type[sptr->number] == _ABAL_FILLER )
		return;
	else if (!( tptr = databaseRelationDefine() ))
		return;
	else if (!( tmptr = tptr->parent ))
		return;
	else if (!( strcmp( smptr->name, tmptr->name ) )) {
		/* do not create self relations */
		/* ---------------------------- */
		databaseEditorAlert(1);
		return;
		}
	else if (!( rptr = databaseRelationCreate() ))
		return;
	else	{
		if (!(rptr->previous = sptr->last))
			sptr->first = rptr;
		else	rptr->previous->next = rptr;
		sptr->last = rptr;
		rptr->source = sptr;
		rptr->target = tptr;
		rptr->name = allocate_string("relation");
		rptr->jointure = allocate_string("jointure");
		databaseRelationSave( rptr );
		databaseEditorShow();
		databaseLinkInfo(rptr);
		return;
		}
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M e m b e r M e n u ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseMemberMenu(struct visual_database_member * mptr)
{
	switch ( database_member_menu() ) {
		case	_MEMBER_DEFINE	:
			databaseMemberDefine(mptr);
			return(0x007F);
		case	_MEMBER_NATURE	:
			databaseMemberNature(mptr);
			return(0x007F);
		case	_MEMBER_DELETE	:
			databaseMemberDelete(mptr);
			return(0x007F);
		case	_MEMBER_COPY	:
			if ( VDE.copied_member ) {
				VDE.copied_member = databaseMemberRemove( VDE.copied_member );
				}
			VDE.copied_member = databaseMemberCopy(mptr);
			return(1);
		case	_MEMBER_AFTER	:
			databaseMemberAfter(mptr,mptr->parent);
			return(0x007F);
		case	_MEMBER_BEFORE	:
			databaseMemberBefore(mptr);
			return(0x007F);
		case	_MEMBER_RELATION :
			databaseMemberRelation(mptr);
			return(0x007F);
		case	_MEMBER_LINK :
			databaseMemberLink(mptr);
			return(0x007F);
		case	_MEMBER_LIST :
			databaseMemberList(mptr);
			return(0x007F);
		}
}

/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E    M O D E L    M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	-------------------------------------------------	*/
/*	 d a t a b a s e M o d e l I n h i b i t( mptr )	*/
/*	-------------------------------------------------	*/
int	databaseModelInhibit(struct visual_database_model * mptr)
{
	char	work[512];
	struct	form_control * fptr;
	struct	form_item * iptr;
	if (!( VDE.inhibit ))
		return(0);
	else if (!( mptr ))
		return(0);
	else if (!( mptr->name ))
		return(0);
	else if (!( fptr = Context.Form ))
		return(0);

	/* Attempt to localise a file widget instancing this class */
	/* ------------------------------------------------------- */
	mptr->inhibit = VDE.inhibit;
	sprintf(work,"(%s)",mptr->name);
	for (	iptr = fptr->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {
		if (!( is_file_Widget( iptr ) ))
			continue;
		else if (!( iptr->Contents.format ))
			continue;
		else if (!(strcmp(iptr->Contents.format,work ) )) {
			mptr->inhibit = 0;
			break;
			}
		else if ( is_basefile_of_Widget( iptr, mptr->name ) ) {
			mptr->inhibit = 0;
			break;
			}
		}
	return( mptr->inhibit );
}

/*	-------------------------------------------------	*/
/*	 d a t a b a s e M o d e l L a y o u t ( mptr )		*/
/*	-------------------------------------------------	*/
void	databaseModelLayout(struct visual_database_model * mptr)
{
	struct	visual_database_member  * xptr;
	int	my;
	int	mh;
	my = mptr->y + databaseTextHeight(mptr->name,_STYLE_DATABASE_HEADER,0);
	mh = databaseTextHeight(mptr->name,_STYLE_DATABASE_MEMBER,0);
	for (	xptr=mptr->first;
		xptr != (struct visual_database_member *) 0;
		xptr = xptr->next ) {
		xptr->x = mptr->x;
		xptr->w = mptr->w;
		xptr->y = my;
		my += mh;
		xptr->h = mh;
		}
	/* Update VDE Buffer Control */
	/* ------------------------- */
	if (( mptr->x + mptr->w ) > VDE.buffer.width)
		VDE.buffer.width = (( mptr->x + mptr->w )+VDE.xpadding);
	if (( mptr->y + mptr->h ) > VDE.buffer.height)
		VDE.buffer.height = (( mptr->y + mptr->h )+VDE.ypadding);
	return;
}

/*	-------------------------------------------------	*/
/*	  d a t a b a s e M o d e l S t a t e ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelState(struct visual_database_model * mptr)
{
	int	whoops;
	mptr->state = ((mptr->state+1) & 1);
	whoops = mptr->h; mptr->h = mptr->safty; mptr->safty = whoops;
	databaseEditorShow();
	return(1);
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M o d e l L o c k ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelLock(struct visual_database_model * mptr)
{
	mptr->lock = ((mptr->lock+1) & 1);
	return(0);
}

/*	-------------------------------------------------	*/
/*	 d a t a b a s e M o d e l R e n a m e ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelRename(struct visual_database_model * mptr)
{
	char	workbuffer[512];
	if (!( mptr ))
		return;
	memset(workbuffer,' ',256);
	strcpy( workbuffer, mptr->name );
	visual_frame(	VDE.x+(mptr->x-VDE.xmargin),
			VDE.y+(mptr->y-VDE.ymargin),
		     	mptr->w, ( mptr->state ? mptr->h : mptr->safty ),
			_EDIT_FRAME);
	if ( visual_edit( 
		VDE.x+(mptr->x-VDE.xmargin)+1,
		VDE.y+(mptr->y-VDE.ymargin)+1,
		mptr->w-2, ( mptr->state ? mptr->h : mptr->safty ),
		Context.basefont,
		workbuffer, 255 ) != 27) {
		limit_right_space( workbuffer, 255);
		if ( mptr->name )
			liberate( mptr->name );
		mptr->name = allocate_string( workbuffer );
		if ( mptr->file ) {
			if ( mptr->file->classname )
				liberate( mptr->file->classname );
			mptr->file->classname = allocate_string( workbuffer );
			}
		}
	return(1);
}

/*	-------------------------------------------------	*/
/*	 d a t a b a s e M o d e l D e l e t e ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelDelete(struct visual_database_model * mptr)
{
	struct file_control * fptr;
	struct data_control * dptr;
	if (!( mptr->lock )) {
		fptr = mptr->file;
		dptr = mptr->data;
		if (!( file_control_users( fptr ) )) {
			databaseEditorRemove();
			drop_file_control((void *) 0, fptr);
			renumerate_file_control((void *) 0);
			databaseEditorCreate();
			databaseEditorShow();
			databaseOutOfDate();
			}
		else	database_delete_failure( fptr->classname );
		}
	return(0);
}
/*	-------------------------------------------------	*/
/*	 d a t a b a s e M o d e l R e s i z e ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelResize(struct visual_database_model * mptr)
{
	struct file_control * fptr;
	struct data_control * dptr;
	if ( mptr->lock )
		return(0);
	else if (!( fptr = mptr->file ))
		return(0);
	else if (!( dptr = mptr->data ))
		return(0);
	else	{
		databaseOutOfDate();
		recalculate_file_sizes( fptr );
		return(0);
		}
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M o d e l C o p y ( model )  	*/
/*	-------------------------------------------------	*/
struct visual_database_model *  databaseModelCopy(struct visual_database_model * sptr)
{
	struct visual_database_model * wptr;
	struct visual_database_member * mptr;
	struct visual_database_member * tptr;
	if (( wptr = databaseModelCreate()) != (struct visual_database_model *) 0) {
		if (( sptr->name ) && (!( wptr->name = allocate_string( sptr->name ) )))
			return( databaseModelRemove( wptr ) );
		wptr->file = sptr->file; wptr->data = sptr->data;
		wptr->inhibit = sptr->inhibit;
		wptr->lock= sptr->lock;
		wptr->state= sptr->state;
		wptr->safty= sptr->safty;
		wptr->x = sptr->x; wptr->y = sptr->y; wptr->w = sptr->w; wptr->h = sptr->h;
		for (	mptr = sptr->first;
			mptr != (struct visual_database_model *) 0;
			mptr = mptr->next ) {
			if (!( tptr = databaseMemberCopy( mptr ) ))
				return( databaseModelRemove( wptr ) );
			if (!( tptr->previous = wptr->last ))
				wptr->first = tptr;
			else	tptr->previous->next = tptr;
			wptr->last = tptr;
			tptr->parent = wptr;
			}
		databaseOutOfDate();
		}
	return( wptr );		
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M o d e l I n f o ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelInfo(struct visual_database_model * mptr)
{
	int	indextype=0;
	int	datatype=0;
	int	modext=0;
	int	marker=0;
	int	opener;
	int	locker;
	struct	file_control * fptr;
	struct	data_control * dptr;

	if (!( fptr = mptr->file ))
		return(0);
	else if (!( dptr = mptr->data ))
		return( 0 );

	if ( dptr->option & _A_LEFT )
		indextype=1;
	else if ( dptr->option & _A_RIGHT )
		indextype=2;
	else	indextype=0;

	if ( dptr->option & _A_BOLD )
		datatype = 1;
	else	datatype = 0;

	if ( dptr->option & _A_LINE )
		modext = 1;
	else	modext = 0;

	if ( dptr->option & _A_SHADOW )
		marker = 1;
	else	marker = 0;

	opener = mptr->state;
	locker = mptr->lock;

	if ( accept_model_properties(
		&fptr->classname,
		&fptr->identity,
		&fptr->filename,
		&fptr->nature,
		&indextype,
		&datatype,
		&modext,
		&marker,
		&dptr->indexlength,
		&dptr->indexfields,
		&dptr->datalength,
		&dptr->datafields,
		&opener,&locker
		) != 27 ) {

		if ( marker & 1 )
			dptr->option |= _A_SHADOW;
		else	dptr->option &= ~_A_SHADOW;

		if ( modext & 1 )
			dptr->option |= _A_LINE;
		else	dptr->option &= ~_A_LINE;

		if ( datatype & 1 )
			dptr->option |= _A_BOLD;
		else	dptr->option &= ~_A_BOLD;

		dptr->option &= ~ _A_LEFT|_A_RIGHT;
		if ( indextype == 1 )
			dptr->option |= _A_LEFT;
		else if ( indextype ==2 )
			dptr->option |= _A_RIGHT;
	
		if ( locker != mptr->lock  ) 
			(void) databaseModelLock( mptr );

		if ( opener != mptr->state )
			(void) databaseModelState( mptr );
		}
	return(0);
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M o d e l S o l o ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelSolo(struct visual_database_model * mptr)
{
	if (!( VDE.solo ))
		VDE.solo = mptr;
	else if (!( strcmp( VDE.solo->name , mptr->name ) ))
		VDE.solo = (struct visual_database_model *) 0;
	else	VDE.solo = mptr;
	if ( VDE.solo )
		status_message("model specific database links",2);
	else	status_message("all project database links",2);
	databaseEditorShow();
	return(0);
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M o d e l M e n u ( model )  	*/
/*	-------------------------------------------------	*/
int	databaseModelMenu(struct visual_database_model * mptr)
{
	switch ( database_model_menu() ) {
		case	_MODEL_INFO	:
			databaseModelInfo(mptr);
			return(1);
		case	_MODEL_STATE	:
			databaseModelState(mptr);
			return(1);
		case	_MODEL_DELETE	:
			databaseModelDelete(mptr);
			return(0x007F);
		case	_MODEL_RENAME	:
			databaseModelRename(mptr);
			return(1);
		case	_MODEL_SIZES	:
			databaseModelResize(mptr);
			return(1);
		case	_MODEL_COPY	:
			if ( VDE.copied_model ) {
				VDE.copied_model = databaseMemberRemove( VDE.copied_model );
				}
			VDE.copied_model = databaseModelCopy(mptr);
			return(1);
		case	_MODEL_LOCK	:
			databaseModelLock(mptr);
			return(1);
		case	_MODEL_SOLO	:
			databaseModelSolo(mptr);
			return(1);
		case	_MEMBER_AFTER	:
			databaseMemberAfter(mptr->last,mptr);
			return(257);
		case	_MEMBER_PASTE	:
			if (!( database_copied_member() ))
				return(1);
			else	{
				databaseMemberPaste(mptr->last, mptr );
				return(257);
				}
		}
}

/*	-------------------------------------------------	*/
/*	 d a t a b a s e M o d e l E v e n t ( m, x, y ) 	*/
/*	-------------------------------------------------	*/
int	databaseModelEvent(struct visual_database_model * mptr, int x, int y )
{
	int	status;
	int	event;
	int	mx;
	int	my;
	int	mb=0;
	struct	visual_database_member * xptr;
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
			xptr != (struct visual_database_member *) 0;
			xptr = xptr->next ) {
			if (!( status = databaseMemberEvent( xptr, x, y ) ))
				continue;
			else if ( status != 0x007F ){
				if (!( xptr->focus )) {
					mptr->oldfocus = mptr->current;
					mptr->current  = xptr;
					}
				return(1);
				}
			else	{
				VDE.outofdate=1;
				return( 0x007F);
				}
			}
		if ( visual_event(1) != _MIMO_DOWN )
			return( 1 );
		mb = visual_event(2);
		while (1) {
			if (!( mptr->lock )) {
				databaseHelpShow("move the file model to the required position and then release the mouse button",
					(char *) 0);
				}
			while ((event = visual_getch()) != 256);
			if (!( mptr->lock )) {
				databaseHelpHide();
				if ( mb == _MIMO_LEFT ) {
					mx = ((visual_event(7) - VDE.x) + VDE.xmargin);
					my = ((visual_event(6) - VDE.y) + VDE.ymargin);
					mptr->x += (mx -x); x = mx;
					mptr->y += (my -y); y = my;
					databaseModelLayout(mptr);
					databaseEditorShow();
					}
				}
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		if ( mb == _MIMO_RIGHT ) {
			return( databaseModelMenu(mptr) );
			}
		return(1);
		}
}

/*	------------------------------------------------	*/
/*	d a t a b a s e M o d e l A d d M e m b e r(mptr) 	*/
/*	------------------------------------------------	*/
int	databaseModelAddMember(struct visual_database_model * mptr, char * nptr, int nature, int number)
{
	struct	visual_database_member * xptr;
	if (!( xptr = databaseMemberCreate()))
		return(27);
	else if (!( xptr->name = allocate_string(( nptr ? nptr : "NULL Member")))) {
		databaseModelRemove( xptr );
		return(27);
		}
	else	{
		if (!( xptr->previous = mptr->last ))
			mptr->current = mptr->first = xptr;
		else	xptr->previous->next = xptr;
		mptr->last = xptr;		
		xptr->number = number;
		xptr->nature = nature;
		xptr->parent = mptr;
		databaseOutOfDate();
		return(0);
		}
}

void	databaseModelLoadMembers(struct visual_database_model * mptr )
{
	int	i;
	if (!( mptr->data ))
		return;
	for (i=0; i < mptr->data->indexfields; i++ ) {
		databaseModelAddMember( mptr, mptr->data->name[i], 1, i );
		}
	for (i=0; i < mptr->data->datafields; i++ ) {
		databaseModelAddMember( mptr, mptr->data->name[i+mptr->data->indexfields], 0, i+mptr->data->indexfields );
		}
	return;
}

void	databaseModelDropMembers(struct visual_database_model * mptr )
{
	struct	visual_database_member  * xptr;
	while ((xptr = mptr->first) != (struct visual_database_member  *) 0) {
		mptr->first =  xptr->next;
		databaseMemberRemove( xptr );
		}
	mptr->first = mptr->last = mptr->current = xptr;
	return;
}

/*	------------------------------------------------	*/
/*	 d a t a b a s e M o d e l R e m o v e ( mptr ) 	*/
/*	------------------------------------------------	*/
struct visual_database_model * databaseModelRemove(struct visual_database_model * mptr )
{
	if (!( mptr ))	return;
	databaseModelDropMembers( mptr );
	if ( mptr->name ) {
		liberate( mptr->name );
		}
	if ( mptr->file ) {
		if ( mptr->state )
			mptr->file->state |= 1;
		else	mptr->file->state &= ~1;
		if ( mptr->lock )
			mptr->file->state |= 2;
		else	mptr->file->state &= ~2;
		mptr->file->x = mptr->x;
		mptr->file->y = mptr->y;
		}
	databaseOutOfDate();
	liberate( mptr );
	return;
}

/*	------------------------------------------------	*/
/*	 d a t a b a s e M o d e l C r e a t e (      ) 	*/
/*	------------------------------------------------	*/
struct visual_database_member * databaseModelCreate()
{
	struct visual_database_model * mptr;
	if ((mptr = allocate( sizeof( struct visual_database_model ) )) != (struct visual_database_model *) 0) {
		mptr->previous = mptr->next = (struct visual_database_model *) 0;
		mptr->oldfocus = mptr->first = mptr->current = mptr->last = (struct visual_database_member *) 0;
		mptr->x = mptr->y = mptr->w = mptr->h = 0;
		mptr->data = (struct data_control *) 0; 
		mptr->file = (struct file_control * ) 0;
		mptr->name = (char *) 0;
		mptr->inhibit = 0;
		mptr->lock= 0;
		mptr->state= 0;
		mptr->focus=0;
		mptr->safty= 0;
		}
	databaseOutOfDate();
	return( mptr );
}

/*	--------------------------------------------------	*/
/*	d a t a b a s e M o d e l I s V i s i b l e (mptr)   	*/
/*	--------------------------------------------------	*/
int	databaseModelIsVisible(struct visual_database_model * mptr )
{
	if (!( mptr ))	
		return(0);
	else if ( mptr->inhibit )	
		return(0);
	else	return(1);
	if (( mptr->x < VDE.xmargin ) ||  ( mptr->x > (VDE.xmargin+VDE.w)))
		return(0);
	else if (( (mptr->x+mptr->w) < VDE.xmargin ) ||  (( mptr->x+ mptr->w) > (VDE.xmargin+VDE.w)))
		return(0);
	else if (( mptr->y < VDE.ymargin ) ||  ( mptr->y > (VDE.ymargin+VDE.h)))
		return(0);
	else if (( (mptr->y+mptr->h) < VDE.ymargin ) ||  (( mptr->y+ mptr->h) > (VDE.ymargin+VDE.h)))
		return(0);
	else	return(1);
}

/*	--------------------------------------------------	*/
/*	d a t a b a s e M o d e l L o s e F o c u s (mptr)   	*/
/*	--------------------------------------------------	*/
void	databaseModelLoseFocus(struct visual_database_model * mptr, int mode )
{
	if (!( mptr ))
		return;
	else if ( mptr->inhibit )	
		return;
	else	{
		if ( mode ) 
			databaseEditorStart();

		(void) visual_element( mptr->x,mptr->y,
			mptr->w,mptr->h,_STYLE_DATABASE_HEADER, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));

		mptr->focus=0;
		if (!( mptr->state ))
			databaseMemberLoseFocus(mptr->current);

		if ( mode )
			databaseEditorFlush();
		}
	return;
}

/*	------------------------------------------------	*/
/*	d a t a b a s e M o d e l G e t F o c u s (mptr)   	*/
/*	------------------------------------------------	*/
void	databaseModelGetFocus(struct visual_database_model * mptr )
{
	if (!( mptr ))
		return;
	else if ( mptr->inhibit )
		return;
	else	{
		databaseEditorStart();
		if (!( mptr->focus )) {
			databaseModelLoseFocus(VDE.current, 0);
			(void) visual_element( mptr->x,mptr->y,
				mptr->w,mptr->h,_STYLE_DATABASE_FOCUS, ( mptr->name ? mptr->name : " "),( mptr->name ? strlen( mptr->name ) : 0));
			mptr->focus=1;
			}
		if (!( mptr->state )) {
			databaseMemberLoseFocus(mptr->oldfocus);
			databaseMemberGetFocus(mptr->current);
			}
		databaseEditorFlush();
		VDE.current = mptr;
		}
	return;
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e M o d e l S h o w ( mptr )   	*/
/*	------------------------------------------------	*/
void	databaseModelShow(struct visual_database_model * mptr )
{
	struct	visual_database_member  * xptr;

	/* Avoid display of inhibited Models */
	/* --------------------------------- */
	if (!( mptr ))		return;
	if ( mptr->inhibit )	return;
	
	visual_element( mptr->x,mptr->y,mptr->w,mptr->h,_STYLE_DATABASE_MODEL_TRAY, " " , 0 );
	visual_element( mptr->x,mptr->y,mptr->w,mptr->h,_STYLE_DATABASE_MODEL, " " , 0 );

	databaseModelLoseFocus( mptr, 0 );

	if (!( mptr->state )) {
		for (	xptr = mptr->first;
			xptr != (struct visual_database_member *) 0;
			xptr = xptr->next ) {
			databaseMemberShow( xptr );
			}
		}

	return;
}

/*	---------------------------------------------------------------		*/
/*	   d a t a b a s e M o d e l S h o w R e l a t i o n s ( mptr )   	*/
/*	---------------------------------------------------------------		*/
void	databaseModelShowRelations(struct visual_database_model * mptr )
{
	struct	visual_database_member  * xptr;
	struct	file_control * fptr;
	if (!(fptr = mptr->file))
		return;
	else if ( fptr->nature  != _DBFILE_FRAME ) {
		for (	xptr = mptr->first;
			xptr != (struct visual_database_member *) 0;
			xptr = xptr->next ) {
			databaseMemberShowRelations( xptr );
			}
		}
	else 	{
		for (	xptr = mptr->first;
			xptr != (struct visual_database_member *) 0;
			xptr = xptr->next ) {
			databaseMemberShowRelation( xptr );
			}
		}
	return;
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M o d e l F o c u s ( mptr )		*/
/*	-------------------------------------------------	*/
int	databaseModelFocus(struct visual_database_model * mptr)
{
	int	event;
	mouse_move_on();
	event = visual_getch();
	mouse_move_off();
	return( event );
}

/*	-------------------------------------------------	*/
/*	   d a t a b a s e M o d e l S i z e s ( mptr )		*/
/*	-------------------------------------------------	*/
int	databaseModelSizes(struct visual_database_model * mptr)
{
	struct	visual_database_member  * xptr;
	int	swaper;
	int	wicons=0;
	int	maxlen=0;
	int	maxhig=0;
	int	mbmhig=0;
	int	mbmlen=0;
	if (!( mptr ))
		return(0);
	else if (!( mptr->name ))
		maxlen = 0;
	else if (!( maxlen = databaseTextWidth( mptr->name, _STYLE_DATABASE_HEADER, 0 ) )) {
		mbmhig = maxhig = 0;
		}
	else	{
		if ((maxhig = databaseTextHeight(  mptr->name, _STYLE_DATABASE_MEMBER, 0 )) < 20)
			maxhig = 20;
		if ((mbmhig = databaseTextHeight(  mptr->name, _STYLE_DATABASE_MEMBER, 0 )) < 20)
			mbmhig = 20;
		}
	mptr->safty = (maxhig + 5); 
	mptr->state = 0;

	wicons = databaseTextWidth( "X", _STYLE_DATABASE_INDEX_LINK, 0 );
	       + databaseTextWidth( "X", _STYLE_DATABASE_INDEX_LIST, 0 );

	for (	xptr = mptr->first;
		xptr != (struct visual_database_member *) 0;
		xptr = xptr->next ) {
		if ((mbmlen = databaseMemberTextWidth( xptr, _STYLE_DATABASE_MEMBER, 0 )) > maxlen)
			maxlen = mbmlen;
		maxhig += mbmhig;
		}
	mptr->h = maxhig+5;
	mptr->w = (maxlen + 30 + wicons);
	if ( mptr->file ) {
		mptr->state = (mptr->file->state & 1);
		if ( mptr->state ) {
			swaper = mptr->safty; mptr->safty = mptr->h; mptr->h = swaper;
			}		
		}
	return(0);
}


/*	------------------------------------------------	*/
/*								*/
/*	  D A T B A S E   E D I T O R   M E T H O D S		*/
/*								*/
/*	------------------------------------------------	*/

/*	------------------------------------------------	*/
/*	    d a t a b a s e D r o p I m a g e  ( ) 	   	*/
/*	------------------------------------------------	*/
void	databaseDropImage()
{
	if ( VDE.image ) {
		VDE.image->storage = (STDPSUPTR) 0;
		VDE.image = local_drop_image( VDE.image );
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e B u i l d I m a g e  ( ) 	   	*/
/*	------------------------------------------------	*/
void	databaseBuildImage()
{
	if (!( VDE.image = local_allocate_image( 0, 0, 0, 0 )))
		return;
	else	{
		VDE.image->storage = VDE.buffer.value;
		VDE.image->rows    = VDE.buffer.height;
		VDE.image->columns = VDE.buffer.width;
		VDE.image->format = get_pixel_size();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r C h e c k ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorCheck()
{
	if ( VDE.buffer.width < VDE.w )
		VDE.buffer.width = VDE.w;
	if ( VDE.buffer.height < VDE.h )
		VDE.buffer.height = VDE.h;

	if (( VDE.buffer.width  != VDE.buffer.x )
	||  ( VDE.buffer.height != VDE.buffer.y )) {
		if ( VDE.buffer.value ) {
			databaseDropImage();
			VDE.buffer.value = liberate_pixel_storage( VDE.buffer.value );
			}
		if (!( VDE.buffer.value = allocate_graphic_storage( 
			0,0, (VDE.buffer.x = VDE.buffer.width), 
			     (VDE.buffer.y = VDE.buffer.height)) ))
			return(27);
		databaseBuildImage();
		}
	if (!( VDE.buffer.value ))
		return(118);
	else	return(0);
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r F o c u s ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorAddModel()
{
	struct	visual_database_model  * mptr;
	if (!( mptr = databaseModelCreate()))
		return(27);
	else if (!( mptr->name = allocate_string("NULL Model"))) {
		databaseModelRemove( mptr );
		return(27);
		}
	else	{
		if (!( mptr->previous = VDE.last ))
			VDE.current = VDE.first = mptr;
		else	mptr->previous->next = mptr;
		VDE.last = mptr;		
		databaseOutOfDate();
		return(0);
		}
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e E d i t o r R e m o v e ( )  	*/
/*	------------------------------------------------	*/
int	databaseEditorRemove()
{
	struct	visual_database_model  * mptr;
	while ((mptr = VDE.first) != (struct visual_database_model  *) 0) {
		VDE.first = mptr->next;
		databaseModelRemove( mptr );
		}
	databaseDropImage();
	VDE.solo = VDE.first = VDE.current = VDE.last = (struct visual_database_model *) 0;
	return(0);
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e E d i t o r L a y o u t ( )  	*/
/*	------------------------------------------------	*/
int	databaseEditorLayout()
{
	int	my=0;
	int	x=VDE.xpadding;
	int	y=VDE.ypadding+30;
	int	nb=0;
	int	rowheight=0;
	struct	visual_database_model  * mptr;

	if (!( y = databaseTextHeight(VDE.title,_STYLE_DATABASE_TITLE,0) ))
		y =  VDE.ypadding;
	else	y += VDE.ypadding;

	VDE.x = Context.DeskTop.x;
	VDE.y = Context.DeskTop.y;
	VDE.w = Context.DeskTop.w;
	VDE.h = Context.DeskTop.h;

	VDE.buffer.width = 0;
	VDE.buffer.height= 0;

	for (	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		databaseModelSizes(mptr);
		}
	for (	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		if (( mptr->x == -1 )
		||  ( mptr->y == -1 )) {
		
			mptr->x = x; 
			mptr->y = y;
			if ((x + mptr->w + VDE.xpadding) > VDE.w) {
				x = VDE.xpadding;
				y += ( rowheight + VDE.ypadding);
				rowheight=mptr->h;
				}
			else if ((mptr->x+mptr->w) > (VDE.x + VDE.w)) {
				x = VDE.xpadding;
				mptr->x = VDE.xpadding;
				y += ( rowheight + VDE.ypadding);
				mptr->y = y;
				rowheight=mptr->h;
				}
			else	{
				x += (mptr->w + VDE.xpadding);
				if ( mptr->h > rowheight ) {
				rowheight = mptr->h;
				}
				}
			}
		databaseModelLayout(mptr);

		}
	return(0);
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e E d i t o r D e f a u lt ( )  	*/
/*	------------------------------------------------	*/
void	databaseEditorDefault()
{
	char	*	eptr;
	VDE.hyperspace	 = 1;
	VDE.fraction	 = 4;
	VDE.bubblehelp	 = 1;

	VDE.bender	 = 2;
	VDE.tracewidth	 = 3;
	VDE.tracecolour	 = 1;

	VDE.xpadding 	 = 50;
	VDE.ypadding 	 = 50;
	VDE.tracepadding = 50;
	VDE.depth 	 = 50;
	
	if (( eptr = getenv( "SING_DEBUG_ROUTER" )) != (char *) 0)
		VDE.debug_trace_route = atoi( eptr );
	else	VDE.debug_trace_route = 0;
	return;
}

/*	---------------------------------------------	*/
/*	d a t a b a s e E d i t o r L i b e r a t e()  	*/
/*	---------------------------------------------	*/
int	databaseEditorLiberate()
{
	if ( VDE.copied_member ) {
		VDE.copied_member = databaseMemberRemove( VDE.copied_member );
		}
	if ( VDE.copied_model ) {
		VDE.copied_model = databaseModelRemove( VDE.copied_model );
		}
	if ( VDE.Reader.ifile ) liberate(VDE.Reader.ifile);
	if ( VDE.Reader.cname ) liberate(VDE.Reader.cname);
	if ( VDE.Reader.oname ) liberate(VDE.Reader.oname);
	if ( VDE.Reader.fname ) liberate(VDE.Reader.fname);
	if ( VDE.Reader.iname ) liberate(VDE.Reader.iname);
	if ( VDE.Reader.mname ) liberate(VDE.Reader.mname);
	if ( VDE.Reader.dname ) liberate(VDE.Reader.dname);
	return;
}

/*	--------------------------------------------	*/
/*	   d a t a b a s e E d i t o r S c h e m a()  	*/
/*	--------------------------------------------	*/
void	databaseEditorSchema( int mode )
{
	if ( VDE.schema != mode ) {

		switch ((VDE.schema=mode)) {

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
/*	   d a t a b a s e E d i t o r R e s e t ( )  	*/
/*	--------------------------------------------	*/
int	databaseEditorInitialise()
{

	if ( Context.Form )
		VDE.inhibit = 1;
	else	VDE.inhibit = 0;

	VDE.hypersave.w = VDE.hypersave.h = VDE.hypersave.y = VDE.hypersave.x = 0;
	VDE.sbh = VDE.sbw = 0;
	VDE.xmargin 	  = 0; 
	VDE.ymargin 	  = 0;
	VDE.copied_member = (struct visual_database_member *) 0;
	VDE.copied_model  = (struct visual_database_model  *) 0;
	VDE.schema	  = 0;
	VDE.lock	  = 1;
	databaseEditorSchema( _SCHEMA_MERISE );
	VDE.Reader.ifile = (char *) 0;
	VDE.Reader.cname = (char *) 0;
	VDE.Reader.oname = (char *) 0;
	VDE.Reader.fname = (char *) 0;
	VDE.Reader.iname = (char *) 0;
	VDE.Reader.mname = (char *) 0;
	VDE.Reader.dname = (char *) 0;
	VDE.Reader.convert = 0;
	return;
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e E d i t o r C r e a t e ( )  	*/
/*	------------------------------------------------	*/
int	databaseEditorCreate()
{
	int	i;
	int	status=0;
	struct	visual_database_relation * aptr;
	struct	visual_database_member * sptr;
	struct	visual_database_member * rptr;
	struct	visual_database_model  * mptr;
	struct data_control * dptr;
	struct file_control * tptr;
	struct link_control * lptr;
	char *	eptr;

	VDE.solo = VDE.first = VDE.current = VDE.last = (struct visual_database_model *) 0;
	VDE.x = VDE.y = VDE.w = VDE.h =0;
	VDE.buffer.width  = 0;
	VDE.buffer.height = 0;
	VDE.buffer.x 	  = 0;
	VDE.buffer.y 	  = 0;
	VDE.buffer.value  = (STDPSUPTR) 0;
	VDE.image	  = (struct standard_image *) 0;
	VDE.outofdate 	  = 0;

	if (( VDE.title = FileManager->name) != (char *) 0)
		status_message(VDE.title,2);

	/* For all file records in the DataBase Manager */
	/* -------------------------------------------- */
	for ( 	tptr  = FileManager->first;
		tptr != (struct file_control *) 0;
		tptr = tptr->next ) {

		/* Validate both classname and identity */
		/* ------------------------------------ */
		if ((!( tptr->classname ))
		&&  (!( tptr->identity  )))
			continue;

		if ((status = databaseEditorAddModel()) != 0)
			break;
		else if (!( mptr = VDE.last))
			break;
		else 	{
			if ( mptr->name ) liberate( mptr->name );
			if (!( mptr->name = allocate_string( tptr->classname )))
				break;
			mptr->file = tptr;
			mptr->data = tptr->payload;

			mptr->x = tptr->x;
			mptr->y = tptr->y;
			mptr->state = 0;
			mptr->lock  = ((tptr->state & 2) ? 1 : 0);

			if (!( dptr = tptr->payload ))
				continue;

			if ( databaseModelInhibit( mptr ) )
				continue;

			databaseModelLoadMembers( mptr );

			}
		}

	/* For all file records in the DataBase Manager */
	/* -------------------------------------------- */
	for ( 	lptr  = FileManager->firstlink;
		lptr != (struct link_control *) 0;
		lptr = lptr->next ) {

		/* Validate both classname and identity */
		/* ------------------------------------ */
		if ((!( lptr->source ))
		&&  (!( lptr->target )))
			continue;
		else if (!( sptr = databaseMemberResolve( lptr->source ) ))
			continue;
		else if (!( rptr = databaseMemberResolve( lptr->target ) ))
			continue;
		else if (!( aptr = databaseRelationCreate() ))
			continue;
		else	{
			aptr->source = sptr;
			aptr->target = rptr;
			aptr->nature = lptr->nature;
			aptr->inhibit= lptr->inhibit;
			aptr->relation = lptr;
			if ( lptr->name )
				aptr->name = allocate_string( lptr->name );
			else	aptr->name = allocate_string( "relation" );
			if ( lptr->jointure )
				aptr->jointure = allocate_string( lptr->jointure );
			else	aptr->jointure = allocate_string( "jointure" );
			if (!(aptr->previous = sptr->last))
				sptr->first = aptr;
			else	aptr->previous->next = aptr;
			sptr->last = aptr;
			}
		}
	databaseEditorLayout();
	return(0);
}

/*	--------------------------------------------------------	*/
/*	 d a t a b a s e C a l c u l a t e H y p e r V i e w()	    	*/
/*	--------------------------------------------------------	*/
void	databaseCalculateHyperCursor()
{
	VDE.hypercursor.w = ((VDE.hyperview.w * VDE.w) / VDE.buffer.width);
	VDE.hypercursor.h = ((VDE.hyperview.h * VDE.h) / VDE.buffer.height);
	VDE.hypercursor.x = VDE.hyperview.x+((VDE.hyperview.w * VDE.xmargin) / VDE.buffer.width);
	VDE.hypercursor.y = VDE.hyperview.y+((VDE.hyperview.h * VDE.ymargin) / VDE.buffer.height);
	return;
}

/*	------------------------------------------------	*/
/*	     d a t a b a s e H y p e r V i e w  ()	    	*/
/*	------------------------------------------------	*/
void	databaseHyperView()
{
	if (!( VDE.image ))
		return;
	else if (!( VDE.image->storage ))
		return;
	else	{
		visual_element(VDE.hyperzone.x,VDE.hyperzone.y,VDE.hyperzone.w,VDE.hyperzone.h,_STYLE_DATABASE_HYPERVIEW_TRAY," ",1);
		visual_element(VDE.hyperzone.x,VDE.hyperzone.y,VDE.hyperzone.w,VDE.hyperzone.h,_STYLE_DATABASE_HYPERVIEW_FRAME," ",1);
		drawimage     (VDE.hyperview.x,VDE.hyperview.y,VDE.hyperview.w,VDE.hyperview.h,VDE.image,_I_MAKEFIT);
		visual_element(VDE.hypercursor.x,VDE.hypercursor.y,VDE.hypercursor.w,VDE.hypercursor.h,_STYLE_DATABASE_HYPERVIEW_CROSS," ",1);
		visual_element(VDE.hypercursor.x,VDE.hypercursor.y,VDE.hypercursor.w,VDE.hypercursor.h,_STYLE_DATABASE_HYPERVIEW_ZOOM," ",1);
		}
}

/*	------------------------------------------------------------		*/
/*	 d a t a b a s e H y p e r V i e w C u r s o r E v e n t ()	    	*/
/*	-----------------------------------------------------------		*/
int	databaseHyperViewCursorEvent(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	if ( x < VDE.hypercursor.x )
		return(0);
	else if ( y <= VDE.hypercursor.y )
		return(0);
	else if ( x > (VDE.hypercursor.x+VDE.hypercursor.w) )
		return(0);
	else if ( y > (VDE.hypercursor.y+VDE.hypercursor.h) )
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
			VDE.hypercursor.x += (mx -x); x = mx;
			VDE.hypercursor.y += (my -y); y = my;
			if ( VDE.hypercursor.x < VDE.hyperview.x )
				VDE.hypercursor.x = VDE.hyperview.x;
			else if ( (VDE.hypercursor.x+VDE.hypercursor.w) > (VDE.hyperview.x+VDE.hyperview.w))
				VDE.hypercursor.x = ((VDE.hyperview.x+VDE.hyperview.w)-VDE.hypercursor.w);
			if ( VDE.hypercursor.y < VDE.hyperview.y )
				VDE.hypercursor.y = VDE.hyperview.y;
			else if ((VDE.hypercursor.y+VDE.hypercursor.h) > (VDE.hyperview.y+VDE.hyperview.h))
				VDE.hypercursor.y = ((VDE.hyperview.y+VDE.hyperview.h)-VDE.hypercursor.h);
			VDE.xmargin = ((VDE.buffer.width*(VDE.hypercursor.x-VDE.hyperview.x))/VDE.hyperview.w);
			VDE.ymargin = ((VDE.buffer.height*(VDE.hypercursor.y-VDE.hyperview.y))/VDE.hyperview.h);
			VDE.hyperspace = 0;
			visual_freeze();
			databaseEditorRefresh();
			databaseHyperView();
			visual_thaw(VDE.hyperzone.x,VDE.hyperzone.y,VDE.hyperzone.w,VDE.hyperzone.h);
			VDE.hyperspace = 1;
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		mouse_move_off();
		return(1);
		}
}

/*	-------------------------------------------------------		*/
/*	 d a t a b a s e H y p e r V i e w Z o n e E v e n t ()	    	*/
/*	-------------------------------------------------------		*/
int	databaseHyperViewZoneEvent(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	if ( x < VDE.hyperview.x )
		return(0);
	else if ( y <= VDE.hyperview.y )
		return(0);
	else if ( x > (VDE.hyperview.x+VDE.hyperview.w) )
		return(0);
	else if ( y > (VDE.hyperview.y+VDE.hyperview.h) )
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
			VDE.hyperzone.x += (mx -x); x = mx;
			if ( VDE.hyperzone.x < VDE.x )
				VDE.hyperzone.x = VDE.x;
			else if ((VDE.hyperzone.x+VDE.hyperzone.w) > (VDE.x+VDE.w))
				VDE.hyperzone.x = (VDE.x + (VDE.w-VDE.hyperzone.w));
			VDE.hyperzone.y += (my -y); y = my;
			if ( VDE.hyperzone.y < VDE.y )
				VDE.hyperzone.y = VDE.y;
			else if ((VDE.hyperzone.y+VDE.hyperzone.h) > (VDE.y+VDE.h))
				VDE.hyperzone.y = (VDE.y + (VDE.h-VDE.hyperzone.h));
			databaseCalculateHyperView();
			databaseEditorRefresh();
			if ( visual_event(1) == _MIMO_UP ) break;
			}
		mouse_move_off();
		return(1);
		}
}

/*	------------------------------------------------	*/
/*	 d a t a b a s e H y p e r V i e w E v e n t ()	    	*/
/*	------------------------------------------------	*/
int	databaseHyperViewEvent(int x, int y)
{
	if (!( VDE.hyperspace ))
		return(0);
	else if ( databaseHyperViewCursorEvent(x,y) )
		return(1);
	else if ( databaseHyperViewZoneEvent(x,y) )
		return(1);
	else	return(0);
}

/*	--------------------------------------------------------	*/
/*	 d a t a b a s e C a l c u l a t e H y p e r V i e w()	    	*/
/*	--------------------------------------------------------	*/
void	databaseCalculateHyperView()
{
	VDE.hyperview.x = VDE.hyperzone.x + 5;
	VDE.hyperview.y = VDE.hyperzone.y + 5;
	VDE.hyperview.w = VDE.hyperzone.w - 10;
	VDE.hyperview.h = VDE.hyperzone.h - 10;
	return;
}

/*	--------------------------------------------------------	*/
/*	 d a t a b a s e C a l c u l a t e H y p e r Z o n e()	    	*/
/*	--------------------------------------------------------	*/
void	databaseCalculateHyperZone()
{
	if (( VDE.hypersave.w == VDE.w ) 
	&&  ( VDE.hypersave.h == VDE.h )
	&&  ( VDE.hypersave.y == VDE.y )
	&&  ( VDE.hypersave.x == VDE.x )
	&&  ( VDE.buffer.height== VDE.sbh )
	&&  ( VDE.buffer.width == VDE.sbw ))
		return;

	VDE.hypersave.w = VDE.w; VDE.hypersave.h = VDE.h;
	VDE.hypersave.y = VDE.y; VDE.hypersave.x = VDE.x;
	VDE.sbh = VDE.buffer.height;
	VDE.sbw = VDE.buffer.width;

	if ( VDE.buffer.height > VDE.buffer.width ) {
		VDE.hyperzone.h = (VDE.h/VDE.fraction)+10;
		VDE.hyperzone.w = ((VDE.hyperzone.h * VDE.buffer.width)/VDE.buffer.height)+10;
		}
	else	{
		VDE.hyperzone.w = (VDE.w / VDE.fraction)+10;
		VDE.hyperzone.h = ((VDE.hyperzone.w * VDE.buffer.height)/VDE.buffer.width)+10;
		}
	VDE.hyperzone.x = VDE.x + (VDE.w - VDE.hyperzone.w);
	VDE.hyperzone.y = VDE.y;
	databaseCalculateHyperView();
	return;
}

/*	------------------------------------------------	*/
/*	  d a t a b a s e E d i t o r R e f r e s h ()    	*/
/*	------------------------------------------------	*/
void	databaseEditorRefresh()
{
	int	pixelsize=get_pixel_size();
	int	r;
	char *	bptr;

	if (( VDE.xmargin + VDE.w ) > VDE.buffer.width )
		VDE.xmargin = (VDE.buffer.width - VDE.w);
	else if ( VDE.xmargin < 0 ) 
		VDE.xmargin = 0;
	if (( VDE.ymargin + VDE.h ) > VDE.buffer.height)
		VDE.ymargin = (VDE.buffer.height - VDE.h);
	else if ( VDE.ymargin < 0 ) 
		VDE.ymargin = 0;

	visual_freeze();
	for ( r=0; r < VDE.h; r++ ) {
		if (!( bptr = connect_pixel_row( VDE.buffer.value, r+VDE.ymargin )))
			break;
		else	putzone(VDE.x,VDE.y+r,VDE.w,1,(bptr+(VDE.xmargin*pixelsize)));
		}

	if ( VDE.hyperspace ) {
		databaseCalculateHyperZone();
		databaseCalculateHyperCursor();
		databaseHyperView();
		}

	visual_thaw( VDE.x, VDE.y, VDE.w, VDE.h );
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r S t a r t ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorStart()
{
	VDE.x = 0;
	VDE.y = 0;

	/* Allocate Screen Buffer and Establish */
	/* ------------------------------------ */
	if (!( databaseEditorCheck() )) {
		background_pixel_capture( VDE.buffer.value );
		}
	return;
}

/*	------------------------------------------------	*/
/*	   d a t a b a s e E d i t o r F l u s h ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorFlush()
{
	/* Disactive Screen Buffer */
	/* ----------------------- */
	if ( VDE.buffer.value ) {
		cancel_pixel_capture( VDE.buffer.value );
		}

	VDE.x = Context.DeskTop.x;
	VDE.y = Context.DeskTop.y;

	/* Display the Screen Buffer */
	/* ------------------------- */
	databaseEditorRefresh();
	
	return;
}

/*	------------------------------------------------	*/
/*	     d a t a b a s e E d i t o r S h o w ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorShow()
{
	struct	visual_database_model  * mptr;

	VDE.w = Context.DeskTop.w;
	VDE.h = Context.DeskTop.h;

	databaseEditorStart();

	/* display with style if required and possible */
	/* ------------------------------------------- */
	if ( visual_element( VDE.x,VDE.y,VDE.buffer.width,VDE.buffer.height,_STYLE_DATABASE_FRAME, "  ",0) ) {

		/* Reset Zone otherwise */
		/* -------------------- */
		filzone	(
			VDE.x,VDE.y,
			VDE.buffer.width,VDE.buffer.height,
			_DEFAULT_GUI_NEUTRAL);
		}

	(void ) visual_element( VDE.x,VDE.y,VDE.buffer.width,VDE.buffer.height,_STYLE_DATABASE_TITLE, VDE.title, strlen( VDE.title ));

	/* Detect and Display Solo Relations */
	/* --------------------------------- */
	if ( VDE.solo ) {
		databaseModelShowRelations(VDE.solo);
		}
	else	{
		/* Display the various Database Relations */
		/* -------------------------------------- */
		for (	mptr = VDE.first;
			mptr != (struct visual_database_model *) 0;
			mptr = mptr->next ) {
			databaseModelShowRelations(mptr);
			}
		}

	/* Display the various Database File Models */
	/* ---------------------------------------- */
	for (	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		databaseModelShow(mptr);
		}

	databaseEditorFlush();

	return(0);
}

/*	------------------------------------------------	*/
/*	     d a t a b a s e E d i t o r H i d e ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorHide()
{
	return(0);
}


/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r M o v e ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorMove(int x, int y)
{
	int	mb;
	int	mx;
	int	my;
	int	event;
	while (1) {
		while ((event = visual_getch()) != 256);
		mx = visual_event(7);
		my = visual_event(6);
		VDE.xmargin += (x - mx); x = mx;
		VDE.ymargin += (y - my); y = my;
		databaseEditorRefresh();
		if ( visual_event(1) == _MIMO_UP ) break;
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r R e s e t() 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorReset()
{
	struct	visual_database_model  * mptr;
	for (	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		if (!( mptr->lock )) {
			mptr->x = mptr->y = -1;
			}
		}
	VDE.outofdate = 2;
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r R e s e t() 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorState()
{
	struct	visual_database_model  * mptr;
	for (	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next )
		databaseModelState( mptr );
	VDE.outofdate = 2;
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r I m p o r t()	  	*/
/*	------------------------------------------------	*/
void	databaseEditorImport()
{
	int	mode=0;
	if ( accept_xml_filename( &VDE.title, &mode ) != 27 ) {
		import_database( VDE.title, strlen( VDE.title ) );
		databaseEditorRemove();
		databaseEditorCreate();
		databaseEditorShow();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r E x p o r t ()	  	*/
/*	------------------------------------------------	*/
void	databaseEditorExport()
{
	int	mode=1;
	if ( accept_xml_filename( &VDE.title, &mode ) != 27 ) {
		export_database( VDE.title, strlen( VDE.title ) );
		}
	return;
}


/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r I n f o ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorInfo()
{
	int	s;
	s = VDE.schema;
	if ( accept_database_control(
		&VDE.hyperspace,
		&VDE.bubblehelp,
		&VDE.bender,
		&VDE.tracewidth,
		&VDE.tracecolour,
		&VDE.depth,
		&VDE.tracepadding,	
		&VDE.xpadding,
		&VDE.ypadding,
		&VDE.fraction,
		&s) != 27 ) {
		databaseEditorSchema(s);
		databaseEditorRemove();
		databaseEditorCreate();
		databaseEditorShow();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r H e l p ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorHelp()
{
	if (!( VDE.bubblehelp = ((VDE.bubblehelp + 1) & 1) ))
		status_message("help bubble messages : OFF",2);
	else	status_message("help bubble messages : ON",2);
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r T r a c e ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorTrace()
{
	VDE.bender += 1;
	if ( VDE.bender > 2 )
		VDE.bender = 0;
	switch ( VDE.bender ) {
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
	VDE.outofdate=1;
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r H y p e r ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorHyper()
{
	if (!( VDE.hyperspace = ((VDE.hyperspace + 1) & 1) )) 
		status_message("hyperspace navigator : OFF",2);
	else	status_message("hyperspace navigator : ON",2);
	VDE.outofdate=1;
	return;
}

void	limit_right_space(char * wptr, int wlen )
{
	int	i;
	int	l;
	for (l=0,i=0; i < wlen; i++) {
		if (!( *(wptr + i) )) {
			l = i;
			break;
			}
		else if ( *(wptr+i) != ' ' )
			l = (i+1);
		}
	*(wptr+l) = 0;
	return;
}


#include "parseabal.c"

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r F i l e ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorFile(int emx, int emy)
{
	struct	file_control * fptr;
	int	i,l;
	char	workbuffer[512];
	memset(workbuffer,' ',256);
	visual_frame(	VDE.x, VDE.y, VDE.w, 32, _EDIT_FRAME );
	visual_text (	VDE.x+5, VDE.y+2, 100, 30, Context.menufont, 16,0, "Classname:",10,3);
	if ( visual_edit( 
			VDE.x+120,VDE.y+2,300,30,
			Context.basefont,
			workbuffer, 255 ) == 27) {
		databaseEditorRefresh();
		}
	else	{
		limit_right_space( workbuffer, 255);
		if (( fptr = AddFileClass((void*)0,_MCFILE_FRAME ,workbuffer,"noname","filename"," ")) != (struct file_control *) 0) {
			fptr->x = emx;
			fptr->y = emy;
			}
		VDE.outofdate=2;
		}
	return;
}


void	databaseIncludeSingle(char * nomfic, int emx,int emy)
{
	struct	file_control * fptr;
	if (( fptr = AddFileClass((void*)0,_MCFILE_FRAME ,VDE.Reader.cname,VDE.Reader.oname,VDE.Reader.fname," ")) != (struct file_control *) 0) {
		fptr->x = emx;
		fptr->y = emy;
		parse_file_inclusion( 	nomfic,
					fptr, 
					VDE.Reader.convert,
					VDE.Reader.iname,
					VDE.Reader.mname,
					VDE.Reader.dname );
		status_message("abal source file parsed",2);
		VDE.outofdate=2;
		}
	return;
}

void	databaseIncludeWild(int emx,int emy)
{
	char	*	holdc=(char *) 0;
	char 	*	holdo=(char *) 0;
	char 	*	holdf=(char *) 0;
	char	*	iname=(char *) 0;
	char	*	iroot=(char *) 0;
	char	*	prefix;
	char	*	sptr;
	int		started=0;
	char		namebuffer[512];
	char 		tempc[256];
	char 		tempo[256];
	char 		tempf[512];
	int		i;
	for (	sptr=VDE.Reader.ifile;
		*sptr != 0;
		sptr++ )
		if ( (*sptr == '*') || (*sptr == '?'))
			break;
	if (!( *sptr )) {
		databaseIncludeSingle( VDE.Reader.ifile, emx, emy );
		return;
		}

	/* multiple file import */
	/* -------------------- */
	if ( fn_parser( VDE.Reader.ifile, namebuffer, 0x0007) != 0)
		prefix = allocate_string( namebuffer );
	else	prefix = (char *) 0;

	holdc = VDE.Reader.cname;
	holdo = VDE.Reader.oname;
	holdf = VDE.Reader.fname;
	VDE.Reader.cname = tempc;
	VDE.Reader.oname = tempo;
	VDE.Reader.fname = tempf;

	while ( filefinder( namebuffer, 255, VDE.Reader.ifile, strlen(VDE.Reader.ifile), started, 0 ) != 0 ) {
		for (i=0; i < 255; i++ )
			if ( namebuffer[i] == ' ' )
				break;
		namebuffer[i] = 0;
		started++;
		if (!( iname = relative_filename( namebuffer, prefix )))
			break;
		else if (!( iroot = allocate_string( iname ))) {
			liberate( iname );
			break;
			}
		for ( 	sptr=iroot;
			*sptr != 0;
			sptr++ ) {
			switch ( *sptr ) {
				case	'.'	:
#ifndef	WIN32
				case	'/'	:
#else
				case	':'	:
				case	'\\'	:
#endif
					*sptr = '_';
				}
			}
		sprintf(tempc,"class_%u_%s",started,iroot);
		sprintf(tempo,"object_%u_%s",started,iroot);
		sprintf(tempf,"file_%u_%s",started,iroot);
		liberate( iroot );
		databaseIncludeSingle( iname, emx, emy );
		emx += VDE.xmargin;
		emy += VDE.ymargin;
		if ( iname ) { liberate( iname ); }
		}
	if ( prefix ) { liberate( prefix ); }
	VDE.Reader.cname = holdc;
	VDE.Reader.oname = holdo;
	VDE.Reader.fname = holdf;
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r R e a d ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorRead(int emx, int emy)
{
	struct	file_control * fptr;
	if ( accept_inclusion_parameters(
			&VDE.Reader.ifile, 
			&VDE.Reader.cname, &VDE.Reader.oname, &VDE.Reader.fname, 
			&VDE.Reader.iname, &VDE.Reader.mname, &VDE.Reader.dname, 
			&VDE.Reader.convert
		) == 27) {
		databaseEditorRefresh();
		}
	else if (!( method_is_valid( VDE.Reader.ifile ) )) {
		status_message("you must specify the includefile name",2);
		databaseEditorRefresh();
		}
	else if (!( method_is_valid( VDE.Reader.cname ) )) {
		status_message("you must specify the file classname",2);
		databaseEditorRefresh();
		}
	else if (!( method_is_valid( VDE.Reader.oname ) )) {
		status_message("you must specify the instance name",2);
		databaseEditorRefresh();
		}
	else if (!( method_is_valid( VDE.Reader.fname ) )) {
		status_message("you must specify the filename",2);
		databaseEditorRefresh();
		}
	else	{
		limit_right_space( VDE.Reader.cname, 255);
		databaseIncludeWild(emx,emy);
		return;
		}
}

/*	------------------------------------------------	*/
/*	  d a t a b a s e E d i t o r I n h i b i t ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorInhibit()
{
	if (!( Context.Form ))
		VDE.inhibit = 0;
	else	{
		VDE.inhibit = ((VDE.inhibit + 1) & 1);
		VDE.outofdate=2;
		}
	if ( VDE.inhibit ) 
		status_message("displaying forms database",2);
	else	status_message("displaying project database",2);

	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r P a s t e (x,y)		*/
/*	------------------------------------------------	*/
void	databaseModelPaste(int emx,int emy)
{
	struct	visual_database_model * mptr;
	struct	visual_database_member * aptr;
	struct	visual_database_relation * rptr;
	struct	file_control * fptr;
	struct	file_control * duplicate_file_control(void *, struct	file_control *  );
	if (!( VDE.copied_model ))
		return;
	else if (!( mptr = databaseModelCopy( VDE.copied_model )))
		return;
	else	{
		if (!(mptr->previous = VDE.last))
			VDE.first = mptr;
		else	mptr->previous->next = mptr;
		VDE.last = mptr;
		mptr->x = emx;
		mptr->y = emy;
		if ((mptr->file = duplicate_file_control((void *) 0, VDE.copied_model->file )) != (struct file_control *) 0)
			mptr->data = mptr->file->payload;
		else	mptr->data = (struct data_control *) 0;
		if ( mptr->name ) {
			mptr->name = liberate( mptr->name );
			mptr->name = allocate_string( mptr->file->classname );
			}
		for (	aptr=mptr->first;
			aptr != (struct visual_database_member*) 0;
			aptr = aptr->next ) {
			for (	rptr=aptr->first;
				rptr != (struct visual_database_relation*) 0;
				rptr = aptr->next ) {
				databaseRelationSave( rptr );
				}
			}
		databaseModelLayout(mptr);
		databaseEditorShow();
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e S a v e I m a g e ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseSaveImage()
{
	char *	tempname;
	if (!( VDE.image ))
		return;
	else if (!( tempname = allocate_string("database.gif") ))
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
			image_save(tempname,VDE.image,QUICK);
			tempname = liberate( tempname );
			return;
			}
		}
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r M e n u ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorMenu()
{
	int	emx = ((visual_event(7) - VDE.x) + VDE.xmargin);
	int	emy = ((visual_event(6) - VDE.y) + VDE.ymargin);
	switch ( database_main_menu() ) {
		case	_BASE_RESET	: databaseEditorReset();	break;
		case	_BASE_IMPORT	: databaseEditorImport();	break;
		case	_BASE_EXPORT	: databaseEditorExport();	break;
		case	_BASE_INFO	: databaseEditorInfo();		break;
		case	_BASE_LOCK	: databaseEditorLock();		break;
		case	_BASE_READ	: databaseEditorRead(emx,emy);	break;
		case	_BASE_HELP	: databaseEditorHelp();		break;
		case	_BASE_ADD	: databaseEditorFile(emx,emy);	break;
		case	_BASE_TRACE	: databaseEditorTrace();	break;
		case	_BASE_HYPER	: databaseEditorHyper();	break;
		case	_BASE_INHIBIT	: databaseEditorInhibit();	break;
		case	_MODEL_PASTE	: databaseModelPaste(emx,emy);	break;
		case	_BASE_IMAGE	: databaseSaveImage();		break;
		case	_BASE_CLOSE	: databaseEditorState();	break;
		}
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r L o c k ( ) 	  	*/
/*	------------------------------------------------	*/
void	databaseEditorLock()
{
	struct	visual_database_model  * mptr;
	VDE.lock = ((VDE.lock + 1) & 1);
	for (	mptr=VDE.first;
		mptr != (struct	visual_database_model  * ) 0;
		mptr = mptr->next ) {
		mptr->lock = VDE.lock;
		}
	if (!( VDE.lock ))
		status_message("all entities have been Unlocked",2);
	else	status_message("all entities have been Locked",2);
	return;
}

/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r E v e n t ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorEvent(int x, int y)
{
	int	status;
	struct	visual_database_model  * mptr;
	if (( x < Context.DeskTop.x )
	||  ( y < Context.DeskTop.y )
	||  ( x > (Context.DeskTop.x+Context.DeskTop.w))
	||  ( y > (Context.DeskTop.y+Context.DeskTop.h)))
		return( -1 );
	else if ( databaseHyperViewEvent(x,y) )
		return(256);
	else	{
		switch ( visual_event(2) ) {
			case	_MIMO_WHEELUP	:
				VDE.ymargin -= 10;
				databaseEditorRefresh();
				return(256);
			case	_MIMO_WHEELDOWN	:
				VDE.ymargin += 10;
				databaseEditorRefresh();
				return(256);
			default			:

				for (	mptr = VDE.first;
					mptr != (struct visual_database_model *) 0;
					mptr = mptr->next ) {
					if (!(status = databaseModelEvent(mptr, (x-VDE.x)+VDE.xmargin, (y-VDE.y)+VDE.ymargin ) )) {
						if (!( status = databaseModelRelationEvent( mptr, (x-VDE.x)+VDE.xmargin, (y-VDE.y)+VDE.ymargin ) ))
							continue;
						else if ( status != 0x007F )
							return(256);
						else	return(256);
						}
					else if ( status == 257 )
						return( status );
					else if (( status != 0x007F )) {
						databaseModelGetFocus(mptr);
						return( 256 );
						}		
					else	{
						return( 256 );
						}
					}
			
				switch ( visual_event(2) ) {
					case	_MIMO_LEFT	:
						if ( visual_event(1) == _MIMO_DOWN )
							databaseEditorMove(x,y);
						break;
					case	_MIMO_RIGHT	:
						if ( visual_event(1) == _MIMO_UP ) {
							databaseEditorMenu();
							return(257);
							}
					}
				return( 256 );
			}
		}

}

int	databaseEditorAlert(int number)
{
	char *	message="\0";
	switch ( number ) {
		case	1 : message = "incorrect recursive relation"; break;
		case	2 : message = "unexpected error"; break;
		}
	return( database_editor_failure( message ) );	
}


/*	------------------------------------------------	*/
/*	    d a t a b a s e E d i t o r F o c u s ( )    	*/
/*	------------------------------------------------	*/
int	databaseEditorFocus()
{
	int	event;
	int	awctrue;
	while(1) {
		switch ( VDE.outofdate ) {
			case	2 :
				databaseEditorRemove();
				databaseEditorCreate();
			case	1 :
				databaseEditorShow();
				VDE.outofdate = 0;
			}
		while ((event = databaseModelFocus( VDE.current )) == 256) {
			if ((event = databaseEditorEvent( visual_event(7), visual_event(6) )) == 256 )
				continue;
			else if ( event == 257 )
				break;
			else if ((event = handle_event()) == 256)
				continue;
			else	break;
			}
		switch ( event ) {
			case	 2		: /* HOME / END */
				if ( VDE.current->next )
					VDE.current = VDE.last;
				else	VDE.current = VDE.first;
				continue;
	
			case	5		: /* NEXT 	MEMBER 	*/
				if (!( VDE.current ))
					continue;
				else if (!( VDE.current->current ))
					continue;
				else if (!( VDE.current->current->next ))
					continue;
				else 	{
					VDE.current->current = VDE.current->current->next;
					continue;
					}
				
			case	11		: /* PREVIOUS 	MEMBER 	*/
				if (!( VDE.current ))
					continue;
				else if (!( VDE.current->current ))
					continue;
				else if (!( VDE.current->current->previous ))
					continue;
				else 	{
					VDE.current->current = VDE.current->current->previous;
					continue;
					}
			case	0x0012		: /* PREVIOUS	PAGE  	*/
				if ( VDE.ymargin  > (VDE.h / 8 ))
					VDE.ymargin -= (VDE.h / 8);
				else	VDE.ymargin = 0;
				databaseEditorRefresh();
				continue;

			case	0x0003		: /* NEXT	PAGE	*/
				VDE.ymargin += (VDE.h / 8);
				databaseEditorRefresh();
				continue;

			case	0x0009		: /* Page Right */
				VDE.xmargin += (VDE.w / 4);
				databaseEditorRefresh();
				continue;

			case	0x0000		: /* Page Left */
				VDE.xmargin -= (VDE.w / 4);
				databaseEditorRefresh();
				continue;

			case	0x001C		: /* Home	*/
			case	0x000C		: /* Home	*/
				VDE.ymargin = 0;
				VDE.xmargin = 0;
				databaseEditorRefresh();
				continue;

			case	0x000A		: /* New Line */
				VDE.xmargin = 0;
				databaseEditorRefresh();
				continue;


			case	_FILE_SAVE	:
				if ( Context.Camera ) {
					databaseEditorRemove();
					save_Camera(Context.Camera,0);
					databaseEditorCreate();
					databaseEditorShow();
					}
				continue;

			case	_FILE_QSAVE	:
				if ( Context.Camera ) {
					databaseEditorRemove();
					save_Camera(Context.Camera,QUICK);
					databaseEditorCreate();
					databaseEditorShow();
					}
				continue;

			case	0x0016		:
				databaseSaveImage();
				continue;

			case	13		:
				databaseModelInfo(VDE.current);
				continue;

			case	27		:
				event = _LEAVE_SING;

			case _SING_HELP		:
			case _SING_FLOW		:
			case _EDIT_FLOWCHART	:
			case _EDIT_IMAGE	:	
			case _EDIT_TEXT 	:
			case _EDIT_FONT 	:
			case _EDIT_STYLE 	:
			case _EDIT_DATABASE	:
			case _EDIT_DEPEND 	:
			case _EDIT_FORM		:
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
/*		d a t a b a s e _ e d i t o r ()		*/
/*	-------------------------------------------------	*/
int	database_model_editor()
{
#ifdef	SING_MODEL_EDITOR
	int	event=0;
	char *	eptr;
	(void) set_context_dataview(1);
	databaseEditorInitialise();
	databaseEditorCreate();
	VDE.outofdate=1;
	event = databaseEditorFocus();
	databaseEditorHide();
	databaseEditorRemove();
	databaseEditorLiberate();
	(void) set_context_dataview(0);
	draw_console();
	return( event );
#else
	return(0);
#endif
}

int	database_copied_class()
{
	if ( VDE.copied_model )
		return(1);
	else	return(0);
}

int	database_copied_member()
{
	if ( VDE.copied_member )
		return(1);
	else	return(0);
}


#endif	/* _singdbed_c */
	/* ----------- */

