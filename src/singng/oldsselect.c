#define RETOUR_SUR_CLICK 1

extern int gwb_lastcar;	

private	int  display_styled_selection(
		int x,int y, int w, int h, 
		int f, int fh,int fg,int bg,
		struct select_control * sptr,
		int first,int visible,int align )
{
	int	i;
	char *	mptr;
	int	mlen;
	visual_element(x,y,w-fh,h+2,"selectframe"," ",0);
	for ( i=0; i < visible; i++ ) {
		if ( (i+first) < sptr->limit ) {
			if (!( mptr = sptr->messages[(i+first)]))
				mptr = " ";
			}
		else	mptr = " ";

		mlen = strlen(mptr);
		visual_element(	x+1, y+(fh*i)+1,(w-fh)-2,fh,
				"selectlabel",mptr,mlen);
		}
	return(0);
}

private	int styled_simple_select(	
		int x,int y, int w, int h, 
		int f, int fw, int fh, int fg, int bg, 
		struct select_control * sptr,
		int align ,char * arrow
		)
{
	char * mptr;

	/* Simple Show : Not Focus */
	/* ----------------------- */
	if ( w > fh ) 	
		visual_element( x,y,(w-fh),fh+3,"selectframe"," ",0);
	if ( w > fh )
		visual_element( x+(w-fh),y,fh,fh+3,"selectframe"," ",0);
	if ( w > fh )
		visual_element( x+(w-fh),y,fh,fh+3,arrow," ",0);

	/* avoid current value display if no selection */
	/* ------------------------------------------- */
	if (!( sptr )) 			return(-1);
	else if (!( sptr->storage ))	return(-1);
	else if (!( sptr->messages )) 	return(-1);

	if ( w > fh ) {
		if (( sptr->current < sptr->limit )
		&&  (( mptr = sptr->messages[sptr->current] ) != (char *) 0 )) {
			if ((( w - (fh+1)) - 2) > 0) {
				visual_element(	x+1, y+1,(w-(fh+1))-2,fh,
					"selectlabel",mptr,strlen(mptr));
				}
			}
		}
	return(-1);
}


private	int  styled_select(	
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
	
	align = ((state & 0x00FF) >> 8);

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

		 if ((sav_focus) && (sav_x==x) && (sav_y==y) && (sav_w==w) && (sav_h==h))
			 result = styled_simple_select(x,y,w,h, f,fw,fh,bg,fg, sptr,align,"selectdown");
		 else	result = styled_simple_select(x,y,w,h, f,fw,fh, fg,bg,sptr,align,"selectdown" );

		/* not focus item so return now */
		/* ---------------------------- */
		if ( sptr ) {		
			if ( sptr->storage )
				sptr->storage = liberate( sptr->storage );
			if ( sptr->messages )
				sptr->messages = liberate( sptr->messages );
			}

		return( result );
		}

	else	{
		result = styled_simple_select(x,y,w,h,f,fw,fh,fg,bg,sptr,align,"selectup" );
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
		closure=1;
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
			result = styled_simple_select(x,oy,w,oh,f,fw,fh,bg,fg,sptr,align,"selectdown" );
			sav_x=x; sav_y=oy; sav_w=w; sav_h=oh; sav_focus=1;
			}
		else	result = styled_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,"selectup" );

		if (!closure)
			redraw=1;
		else	{
			redraw=0;
			affiche_tout=0;
			};

		/* 2) Use Focus */		

		while (1) {

			if ( redraw ) {
				visual_freeze();
				display_styled_selection(x,y,w,h,f,fh,fg,bg,sptr,first,visible,align);
				visual_thaw(x,y,w,h);
				redraw=0;
				}

			StyleSelectBar((x+(w-fh)),y,fh/*+1*/,h+2,8,fg,bg,(current+first),visible,sptr->limit,3);

			if (!( mptr = sptr->messages[(current+first)]))
				mptr = " ";
			mlen = strlen(mptr);
			if (((w-fh)-2) > 0 ) {
				visual_element(	x+1, y+(fh*current)+1,(w-fh)-2,fh,
					"selectfocus",mptr,mlen);
				}
			event = visual_getch(); 
			visual_freeze();
			display_styled_selection(x,y,w,h,f,fh,fg,bg,sptr,first,visible,align);
			visual_thaw(x,y,w,h);
			redraw=0;

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
								closure=1;
							default		   :
								continue;
							}
						/*
							mr -= y; mr /= fh;
						if ((current = mr) >= visible)
							current = (mr-1);
						*/
						sptr->current = (current+first);
						if ((vptr = sptr->result) != (int *) 0)
							*vptr = sptr->current;
						if ( iptr )
							pop_zone( x,y,w+1,h+2,iptr);
						result = styled_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,"selectdown" );
						return( visual_getch() );
						}
					if ((mc >= x)
					&&  (mr >= y)
					&&  (mc <  ( x+w) )
					&&  (mr <  ( y+h) )) {
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
								if ((sptr->current = visual_driver((x+(w-fh)),y,fh,h+2,(current+first),visible,sptr->limit,0x083)) != (current+first)) {
									visual_freeze();
									if ((first = ((sptr->current - visible)+1)) < 0)
										first = 0;
									current = (sptr->current - first);
									StyleSelectBar((x+(w-fh)),y,fh/*+1*/,h+2,8,fg,bg,(current+first),visible,sptr->limit,3);
									display_styled_selection(x,y,w,h,f,fh,fg,bg,sptr,first,visible,align);
									if (!( mptr = sptr->messages[(current+first)]))
										mptr = " ";
									mlen = strlen(mptr);
									if (((w-fh)-2) > 0 ) {
										visual_element(	x+1, y+(fh*current)+1,(w-fh)-2,fh,
										"selectlabel",mptr,mlen);
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
			result = styled_simple_select(x,oy,w,oh,f,fw,fh,fg,bg,sptr,align,"selectdown");
			}

		if ( sptr->storage )
			sptr->storage = liberate( sptr->storage );
		if ( sptr->messages )
			sptr->messages= liberate( sptr->messages);
		return( event );
		}

}

public	WORD StyledSelect(
		WORD x,WORD y,WORD w,WORD h,
		WORD fid, WORD fg, WORD bg, 
		BPTR message,WORD length,unsigned int * iptr,WORD state)
{
	struct  select_control * Selection;
	struct	select_control * parse_selection(char*,int *);

	if (!( Selection = parse_selection( message,iptr ) ))
		return(27);

	return( styled_select( x,y,w,h, fid, fg,bg,Selection,state ) );
}


