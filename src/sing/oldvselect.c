#include "vdrive.c"
#include "stdimage.h"

private	struct	select_control	SelectionContext;

public	struct standard_image  * push_zone(int x, int y, int w, int h )
{
	struct standard_image * iptr;
	char	*	bptr;
	int	r;
	if (!( iptr = local_allocate_image( w,h,0,1 ) ))
		return( iptr );
	for ( 	r=0; r < h; r++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		else	getzone( x,y+r,w,1,bptr);
		}
	return( iptr );
}

public	void	pop_zone(int x, int y, int w, int h, struct standard_image * iptr )
{
	char	*	bptr;
	int	r;
	if (!( iptr ))
		return;
	for ( 	r=0; r < h; r++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		else	putzone( x,y+r,w,1,bptr);
		}
	(void) local_drop_image( iptr);
	return;
}


public	struct	select_control * parse_selection(
	char * mptr, int * item )
{
	void *	vptr=(void *) 0;
	int	i;
	int	messages=0;
	char	*message;
	int	value;
	int	separator=0;
	if (!( mptr ))
		message = allocate_string("empty");
	else	message = allocate_string( mptr );
	SelectionContext.messages = vptr;
	SelectionContext.storage = message;
	SelectionContext.result  = item;
	for ( messages=1, i=0; *(message+i) != 0; i++ ) {
		if (!( separator )) {
			switch ( *(message+i) ) {
				case	'|'	:
				case	','	:
					separator = *(message+i);
				}
			}
		if ( *(message+i) == separator )
			messages++;
		}

	if (!( messages ))
		return((struct	select_control * ) 0 );
	else if (!( vptr = allocate( ((messages+2) * sizeof( BPTR ))) ))
		return((struct	select_control * ) 0 );

	SelectionContext.messages = vptr;
	SelectionContext.messages[(SelectionContext.limit=0)] = message;

	for ( separator=0, i=0; *(message+i) != 0; i++ ) {
		if (!( separator )) {
			switch ( *(message+i) ) {
				case	'|'	:
				case	','	:
					separator = *(message+i);
				}
			}
		if ( *(message+i) == separator ) {
			*(message+i) = 0;
			if (!( *(message+i+1) ))
				break;
			else	SelectionContext.messages[++SelectionContext.limit] = (message+i+1);
			}
		}
	SelectionContext.limit++;

	if ( item != (int *) 0 )
		value = *item;
	else	value = 0;

	if ( value >= SelectionContext.limit )
		value = (SelectionContext.limit-1);

	SelectionContext.current = value;
	return( &SelectionContext );
}

private	int  display_selection(
		int x,int y, int w, int h, 
		int f, int fh,int fg,int bg,
		struct select_control * sptr,
		int first,int visible,int align )
{
	int	i;
	char *	mptr;
	int	mlen;
	for ( i=0; i < visible; i++ ) {
		if (!( mptr = sptr->messages[(i+first)]))
			mptr = " ";
		mlen = strlen(mptr);
		filzone(x+1, y+(fh*i)+1,(w-fh)-2,fh-1,standard_white);
		visual_text( 	x+1, y+(fh*i)+1,(w-fh)-2,fh,
			f,fg,bg,mptr,mlen,align);
		}
	return(0);
}

private	int  visual_simple_select(	
		int x,int y, int w, int h, 
		int f, int fw, int fh, int fg, int bg, 
		struct select_control * sptr,
		int align 
		)
{
	char * mptr;

	/* Simple Show : Not Focus */
	/* ----------------------- */
	visual_frame( x,y,(w-fh),fh+3,_EDIT_FRAME);
	visual_button((x+(w-fh)),y,fh,fh+3,8,fg,bg," ",1,0);
	visual_arrow((x+(w-fh))+1,y+1,fh-2,fh+1,standard_black,_ARROW_DOWN);

	if (!( sptr )) 			return(-1);
	else if (!( sptr->storage ))	return(-1);
	else if (!( sptr->messages )) 	return(-1);

	if (( sptr->current < sptr->limit )
	&&  (( mptr = sptr->messages[sptr->current] ) != (char *) 0 )) {
		if ((( w - (fh+1)) - 2) > 0)
			visual_text( x+1,y+1,(w-(fh+1))-2,fh,f,fg,bg,mptr,strlen(mptr),align);
		}
	return(-1);
}


public	int  visual_select(	
		int x,int y, int w, int h, 
		int f, int fg, int bg, 
		struct select_control * sptr,
		int state 
		)
{
	int	result;
	struct	standard_image * iptr;
	int	align=0;
	int	fw;
	int	fh;
	int	current;
	int	redraw;
	int	first;
	int	visible;
	int	event;
	int	mlen;
	char	*mptr;
	int	*vptr;
	int	mr;
	int	mc;
	char *	qptr;
	char	quick[33];
	int	quicki=0;
	int	q=0;
	int	qi=0;

	quick[quicki] = 0;

	if 	(!( f ))			return(-1);
	else if (!(fw = guifontsize(f)))	return(-1);
	else	{
		fh =(fw >> 8);
	 	fw &= 0x00FF;
		}
	
fuckit:
	while (1) {

	align = ((state & 0x00FF) >> 8);
	fg = standard_title;
	bg = standard_white;

	if ((!( state & _VISUAL_FOCUS )) ||  (!( sptr ))) {

		result = visual_simple_select(x,y,w,h,f,fw,fh,fg,bg,sptr,align );

		if ( sptr ) {		
			if ( sptr->storage )
				sptr->storage = liberate( sptr->storage );
			if ( sptr->messages )
				sptr->messages = liberate( sptr->messages );
			}

		return( result );
		}

	else	{
		/* Get Focus 	*/
		/* ********* 	*/
		/* 1) Save Zone */		

		if ((visible = (h/fh)) > sptr->limit) {
			visible = sptr->limit;
			h = (sptr->limit * fh);
			}

		if ((current = sptr->current) < visible)
			first = 0;
		else	{
			if ((first = ((sptr->current - visible)+1)) < 0)
				first = 0;
			current = (sptr->current - first);
			}		

		iptr = push_zone( x,y,w+1,h+2 );
		visual_frame( x,y,w-fh,h+2,_EDIT_FRAME);
		redraw=1;

		/* 2) Use Focus */		

		while (1) {

			if ( redraw ) {
				visual_freeze();
				display_selection(x,y,w,h,f,fh,fg,bg,sptr,first,visible,align);
				visual_thaw(x,y,w,h);
				redraw=0;
				}

			visual_scrollbar((x+(w-fh)),y,fh,h+2,8,fg,bg,(current+first),visible,sptr->limit,3);

			if (!( mptr = sptr->messages[(current+first)]))
				mptr = " ";
			mlen = strlen(mptr);
			if (((w-fh)-2) > 0 ) {
				visual_text( 	x+1, y+(fh*current)+1,(w-fh)-2,fh,
					f,standard_text,standard_title,
					mptr,mlen,align);
				}
			event = visual_getch() /*mimo_getch()*/;
			if (((w-fh)-2) > 0 ) {
				visual_text( 	x+1, y+(fh*current)+1,(w-fh)-2,fh,
					f,fg,bg,
					mptr,mlen,align);
				}
retry:
			switch ( event ) {

				case	0x005	:	/* Item Down */
					if ((current+first+1) >= sptr->limit)
						continue;
					else if (( current + 1) >= visible ) {
						first++;
						redraw=1;
						}
					else if ((current+first+1) < sptr->limit)
						current++;
					continue;

				case	0x00B	:	/* Item Up */
					if ( current > 0 )
						current--;
					else if ( first > 0) {
						first--;
						redraw=1;
						}
					continue;

				case	27	:
					break;


				case	256	:	/* MiMo	*/
					mc = visual_event(7);
					mr = visual_event(6);
					if ((mc >= x)
					&&  (mr >= y)
					&&  (mc <  ( x+w) )
					&&  (mr <  ( y+h) )) {
						if ( mc > (x+(w-fh))) {
							do	{
								if ((sptr->current = visual_driver((x+(w-fh)),y,fh,h+2,(current+first),visible,sptr->limit,0x083)) != (current+first)) {
									visual_freeze();
									if ((first = ((sptr->current - visible)+1)) < 0)
										first = 0;
									current = (sptr->current - first);
									visual_scrollbar((x+(w-fh)),y,fh,h+2,8,fg,bg,(current+first),visible,sptr->limit,3);
									display_selection(x,y,w,h,f,fh,fg,bg,sptr,first,visible,align);
									if (!( mptr = sptr->messages[(current+first)]))
										mptr = " ";
									mlen = strlen(mptr);
									if (((w-fh)-2) > 0 ) {
										visual_text( 	x+1, y+(fh*current)+1,(w-fh)-2,fh,
											f,standard_text,standard_title,
											mptr,mlen,align);
										}
									visual_thaw(x,y,w,h);
									}
								while ( visual_getch() != 256 );
								}
							while ( visual_event(1) != _MIMO_UP );
							continue;
							}
						if ( visual_event(1) != _MIMO_UP )
							continue;
						else if (( mr < (y+fh))
						     &&  ( mc > (x+(w-fh)))) {
							/* top button */
							event = 0x000B;
							goto retry; 
							}
						else if (( mr > (y+(h-fh)))
						     &&  ( mc > (x+(w-fh)))) {
							/* bottom button */
							event = 0x0005;
							goto retry; 
							}
						else	{
							/* It is inside the Select Zone */
							mr -= y; mr /= fh;
							if ((current = mr) >= visible)
								current = (mr-1);
							continue;
							}
						}
				case	13	:
					sptr->current = (current+first);
					if ((vptr = sptr->result) != (int *) 0)
						*vptr = sptr->current;
					break;
				default		:
					if ( event < 8 )
						break;
					else if ( event == 8 ) {
						if (!( quicki ))
							continue;
						else	quicki--;
						}
					else if ( event < 32 )
						break;
					else if ( quicki < 32 )
						quick[quicki++] = event;
					quick[quicki] = 0;
					for ( q=0; q < sptr->limit; q++ ) {
						if (!( qptr = sptr->messages[q]))
							continue;
						for ( qi=0; qi < quicki; qi++ ) {
							if ( quick[qi] != *(qptr+ qi) )
								break;
							}
						if ( quick[qi] != 0 )
							continue;
						else	{
							sptr->current = q;
							if ((current = sptr->current) < visible)
								first = 0;
							else	{
								if ((first = ((sptr->current - visible)+1)) < 0)
									first = 0;
								current = (sptr->current - first);
								}	
							redraw=1;	
							break;
							}
						} 			
					continue;
				}
			break;

			}
		/* 3) Rest Zone */
		if ( iptr )
			pop_zone( x,y,w+1,h+2,iptr);
		if ( event != 27 ) {
			if (( sptr->current < sptr->limit )
			&&  (( mptr = sptr->messages[sptr->current] ) != (char *) 0 )) {
				filzone(x+1, y+1,(w-(fh+1))-2,fh,standard_white);
				if (((w-(fh+1))-2) > 0 ) {
					visual_text   (x+1, y+1,(w-(fh+1))-2,fh,f,fg,bg,mptr,strlen(mptr),0);
					}
				}
			}

		if ( sptr->storage )
			sptr->storage = liberate( sptr->storage );
		if ( sptr->messages )
			sptr->messages= liberate( sptr->messages);
		return( event );
		}
	}

}


public	WORD VisualSelect(
		WORD x,WORD y,WORD w,WORD h,
		WORD fid, WORD fg, WORD bg, 
		BPTR message,WORD length,unsigned int * iptr,WORD state)
{
	struct  select_control * Selection;

	if (!( Selection = parse_selection( message,iptr ) ))
		return(27);

	return( visual_select( x,y,w,h, fid, fg,bg,Selection,state ) );
}



