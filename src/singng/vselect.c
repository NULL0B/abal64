#define RETOUR_SUR_CLICK 1
#include "vdrive.c"
#include "stdimage.h"
#define CI_MODULE_ID 0x8000
#if defined(WIN32)
#ifdef VISUAL_EXPORTS
#include "visualtrace.h"
#else
#include "extrace.h"
#endif
#else
#define TRACEON
#include "trace.h"
#define CI_TRA_F_DEBUG 0x0040
#endif

private	struct	select_control	SelectionContext;
extern int gwb_lastcar;	

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
	char * mptr, int* item )
{
	void *	vptr=(void *) 0;
	int	i;
	int	j,k;
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

	if (!(SelectionContext.itemreel=allocate(messages*sizeof(int))))
		{
		liberate(vptr);
		return((struct select_control *) 0);
		};

	SelectionContext.messages = vptr;
	SelectionContext.messages[(SelectionContext.limit=0)] = message;
	SelectionContext.itemreel[0]=0;

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
			else	{
				j=0;
				SelectionContext.limit++;
#ifdef TRI_SUR_PARSE
				while ((j<SelectionContext.limit) && (strcmp(SelectionContext.messages[j],message+i+1)<0))
					j++;
				k=SelectionContext.limit;
				while (k>j)
					{
					SelectionContext.itemreel[k]=SelectionContext.itemreel[k-1];
					SelectionContext.messages[k]=SelectionContext.messages[k-1];
					k--;
					};
#else
				j=SelectionContext.limit;
#endif
				SelectionContext.itemreel[j] = SelectionContext.limit;
				SelectionContext.messages[j] = (message+i+1);
				}
			}
		}
	SelectionContext.limit++;

	if ( item != (int *) 0 )
		value = *item;
	else	value = 0;

	if ( value >= SelectionContext.limit )
		value = (SelectionContext.limit-1);

	for (j=0;(j<SelectionContext.limit) && (SelectionContext.itemreel[j]!=value);j++);

	SelectionContext.current = j;
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
		if ( (i+first) < sptr->limit ) {
			if (!( mptr = sptr->messages[(i+first)]))
				mptr = " ";
		}
		else	mptr = " ";

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
		int align, int arrow
		)
{
	char * mptr;

	/* Simple Show : Not Focus */
	/* ----------------------- */
	visual_frame( x,y,(w-fh),fh+3,_EDIT_FRAME);
	visual_button((x+(w-fh)),y,fh,fh+3,8,fg,bg," ",1,0);
	if (arrow & 0x10)
		visual_arrow((x+(w-fh))+1,y+1,fh-2,fh+1,standard_grayed,arrow & 0xF);
	else	visual_arrow((x+(w-fh))+1,y+1,fh-2,fh+1,standard_black,arrow);

	/* avoid current value display if no selection */
	/* ------------------------------------------- */
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
	int	closure=0;
	int	oy;
	int	oh;
	int	result;
	struct	standard_image * iptr;
	int	align=_A_LEFT;
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
	int	mb;
	char *	qptr;
	char	quick[33];
	int	quicki=0;
	int	q=0;
	int	qi=0;
	char frame_ok=0,affiche_tout=1,first_redraw=1;
#if RETOUR_SUR_CLICK
	int new_current;
	static int sav_x,sav_y,sav_w,sav_h,sav_focus=0;
#endif
#ifndef TRI_SUR_PARSE
	char *swap_messages;
	int swap_itemreel,i,j,k;
#endif

	MI_TRACE_DCL_TFN("visual_select");

sav_focus=0;

	/* prepare font and colour characteristics */
	/* --------------------------------------- */
	quick[quicki] = 0;

	if 	(!( f ))			return(-1);
	else if (!(fw = guifontsize(f)))	return(-1);
	else	{
		fh =(fw >> 8);
	 	fw &= 0x00FF;
		}
	
	align = ((state & 0xFF00) >> 8);
	if (state & 0x10)
		fg = standard_grayed;
	else	fg = standard_title;
	bg = standard_white;

	MI_TRACE_BEGIN();

#ifndef TRI_SUR_PARSE
	if (( state & _VISUAL_PRESS ) && (sptr->limit>1))
		{
		for (i=0;i<sptr->limit-1;i++)
			{
			k=i;
			for (j=i+1;j<sptr->limit;j++)
				if (strcmp(sptr->messages[j],sptr->messages[k])<0) k=j;
			if (k!=i) {
				swap_messages=sptr->messages[i];
				swap_itemreel=sptr->itemreel[i];
				sptr->messages[i]=sptr->messages[k];
				sptr->itemreel[i]=sptr->itemreel[k];
				sptr->messages[k]=swap_messages;
				sptr->itemreel[k]=swap_itemreel;
				if (sptr->current==k)
					sptr->current=i;
				else if (sptr->current==i) 
					sptr->current=k;
				};
			};
		};
#endif
	/* Display the current value */
	/* ------------------------- */

	if ((!( state & _VISUAL_FOCUS )) ||  (!( sptr ))) {

		 MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Affichage simple"));

		 if ((sav_focus) && (sav_x==x) && (sav_y==y) && (sav_w==w) && (sav_h==h))
			 result = visual_simple_select(x,y,w,h,f,fw,fh,standard_text,standard_title,sptr,align,_ARROW_DOWN | (state & 0x10));
		 else	 result = visual_simple_select(x,y,w,h,f,fw,fh,fg,bg,sptr,align,_ARROW_DOWN | (state & 0x10));

		/* not focus item so return now */
		/* ---------------------------- */
		if ( sptr ) {		
			if ( sptr->storage )
				sptr->storage = liberate( sptr->storage );
			if ( sptr->messages )
				sptr->messages = liberate( sptr->messages );
			if (sptr->itemreel)
				sptr->itemreel=liberate(sptr->itemreel);
			}

		MI_TRACE_END();
		return( -1 );
		}

	else	{
		oy = y; oh = h;
		y += (fh+3); h -= (fh+3);

		/* Get Focus 	*/
		/* ********* 	*/
		/* 1) Save Zone */		

		if ((visible = (h/fh)) < 3) {
			visible = 3;
			h = (fh*visible);
			}
		else if ( visible > sptr->limit) {
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

		if (!( state & 8 ))
			closure=1;
		else	closure=0;

		if (gwb_lastcar==256)
			{
			mc = visual_event(7);
			mr = visual_event(6);

			if (( mr >= oy ) 
				&&  ( mr <  y)  
				&&  ( mc < (x+w))
				&&  ( mc > (x+(w-fh)) ))
					closure=0;
			};

		if (closure==1) {
			result = visual_simple_select(x,oy,w,oh,f,fw,fh,standard_text,standard_title,sptr,align,_ARROW_DOWN );
			sav_x=x; sav_y=oy; sav_w=w; sav_h=oh; sav_focus=1;
			}
		else	result = visual_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,_ARROW_UP );

		if (!closure)
			redraw=1;
		else	{
			redraw=0;
			affiche_tout=0;
			};
		/* 2) Use Focus */		

		while (1) {

			if ( redraw ) {
				if (first_redraw)
					{
					result = visual_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,_ARROW_UP );
					first_redraw=0;
					sav_focus=0;
					};
				if (!frame_ok)
					{
					visual_frame( x,y,w-fh,h+2,_EDIT_FRAME);
					frame_ok=1;
					};
				hide();
				display_selection(x,y,w,h,f,fh,fg,bg,sptr,first,visible,align);
				show(x,y,w,h);
				redraw=0;
				affiche_tout=1;
				}

			if (affiche_tout)
			{
			sav_focus=0;
			visual_scrollbar((x+(w-fh)),y,fh+1,h+2,8,fg,bg,(current+first),visible,sptr->limit,3);

			if (!( mptr = sptr->messages[(current+first)]))
				mptr = " ";
			mlen = strlen(mptr);
			if (((w-fh)-2) > 0 ) {
			visual_text( 	x+1, y+(fh*current)+1,(w-fh)-2,fh,
				f,standard_text,standard_title,
				mptr,mlen,align);
				}
			}

			MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"appel visual_getch()"));
			event = visual_getch();
			MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"visual_getch()=%d",event));

			if ((((w-fh)-2) > 0 ) && (affiche_tout)) {
			visual_text( 	x+1, y+(fh*current)+1,(w-fh)-2,fh,
				f,fg,bg,
				mptr,mlen,align);
				}
retry:
			switch ( event ) {

				case	0x005	:	/* Item Down */
					if (affiche_tout==0) {
						sptr->current = (current+first);
						if ((vptr = sptr->result) != (int *) 0)
							*vptr = sptr->itemreel[sptr->current];
						break;
						}
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
					if (affiche_tout==0) {
						sptr->current = (current+first);
						if ((vptr = sptr->result) != (int *) 0)
							*vptr = sptr->itemreel[sptr->current];
						break;
						}
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
					mb = visual_event(2);
					if (( mr >= oy ) 
					&&  ( mr <  y  )  
					&&  ( mc < (x+w))
					&&  ( mc > (x+(w-fh)) )) {
						/* ------------------------------------ */
						/* click on select state closure button */
						/* ------------------------------------ */
						switch ( visual_event(1) ) {
							case	_MIMO_UP :
								if (!( closure )) 
									continue;
								else	break;
							case	_MIMO_DOWN :
							if (!closure)
								closure=1;
							else	{
								redraw=1;
								closure=0;
								};
							default		   :
								continue;
							}
#if !RETOUR_SUR_CLICK
						sptr->current = (current+first);
#endif
						if ((vptr = sptr->result) != (int *) 0)
							*vptr = sptr->itemreel[sptr->current];
						if ( iptr )
							pop_zone( x,y,w+1,h+2,iptr);
						result = visual_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,_ARROW_DOWN );
						if ( sptr->storage )
							sptr->storage = liberate( sptr->storage );
						if ( sptr->messages )
							sptr->messages= liberate( sptr->messages);
						if (sptr->itemreel)
							sptr->itemreel=liberate(sptr->itemreel);
						gwb_lastcar=-1;
						MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"fermeture liste"));
						MI_TRACE_END();
						return(-1);
						}
					if ((mc >= x)
					&&  (mr >= y)
					&&  (mc <  ( x+w) )
					&&  (mr <  ( y+h) )
					&& (affiche_tout)) {
						if ( mb == _MIMO_WHEELUP ) {
							event = 11;
							goto retry;
							}
						else if ( mb == _MIMO_WHEELDOWN ) {
							event = 5;
							goto retry;
							}
						if ( mc > (x+(w-fh))) {
							do	{
#if RETOUR_SUR_CLICK
								if ((new_current = visual_driver((x+(w-fh)),y,fh,h+2,(current+first),visible,sptr->limit,0x083)) != (current+first)) {
#else
								if ((sptr->current = visual_driver((x+(w-fh)),y,fh,h+2,(current+first),visible,sptr->limit,0x083)) != (current+first)) {
#endif
									hide();
#if RETOUR_SUR_CLICK
									if ((first = ((new_current - visible)+1)) < 0)
										first = 0;
									current = (new_current - first);
#else
									if ((first = ((sptr->current - visible)+1)) < 0)
										first = 0;
									current = (sptr->current - first);
#endif
									visual_scrollbar((x+(w-fh)),y,fh+1,h+2,8,fg,bg,(current+first),visible,sptr->limit,3);
									display_selection(x,y,w,h,f,fh,fg,bg,sptr,first,visible,align);
									if (!( mptr = sptr->messages[(current+first)]))
										mptr = " ";
									mlen = strlen(mptr);
									if (((w-fh)-2) > 0 ) {
									visual_text( 	x+1, y+(fh*current)+1,(w-fh)-2,fh,
										f,standard_text,standard_title,
										mptr,mlen,align);
										}
									show(x,y,w,h);


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

#if RETOUR_SUR_CLICK
							sptr->current = (current+first);
							if ((vptr = sptr->result) != (int *) 0)
								*vptr = sptr->itemreel[sptr->current];
							if ( iptr )
								pop_zone( x,y,w+1,h+2,iptr);
							result = visual_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,_ARROW_DOWN );
							if ( sptr->storage )
								sptr->storage = liberate( sptr->storage );
							if ( sptr->messages )
								sptr->messages= liberate( sptr->messages);
							if (sptr->itemreel)
								sptr->itemreel=liberate(sptr->itemreel);
							MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"fermeture liste : choix utilisateur %d",sptr->current));
							MI_TRACE_END();
							return(0);
#endif
							continue;
							}
						}
					if (( mr >= oy ) 
					&&  ( mr <  y  )  
					&&  ( mc <= (x+w-fh))
					&&  ( mc > x) && (visual_event(1)==_MIMO_UP)) continue;

					MI_TRACE_END();							
					break;

				case	13	:
					if (affiche_tout==0) {
						redraw=1;
						continue;
						}
					sptr->current = (current+first);
					if ((vptr = sptr->result) != (int *) 0)
						*vptr = sptr->itemreel[sptr->current];
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
			result = visual_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,_ARROW_DOWN );
			}

		if ( sptr->storage )
			sptr->storage = liberate( sptr->storage );
		if ( sptr->messages )
			sptr->messages= liberate( sptr->messages);
		if (sptr->itemreel)
			sptr->itemreel=liberate(sptr->itemreel);

		MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"fermeture liste par touche entree : choix utilisateur %d",sptr->current));
		MI_TRACE_END();
		return( event );
		}

}


public	int	VisualSelect(
		int x,int y,int w,int h,
		int fid, int fg, int bg, 
		BPTR message,int length,unsigned int* iptr,int state)
{
	struct  select_control * Selection;

	if (!( Selection = parse_selection( message,iptr ) ))
		return(27);

	return( visual_select( x,y,w,h, fid, fg,bg,Selection,state ) );
}


