#ifndef	_asfun_list_c
#define	_asfun_list_c

#undef	DEBUG_LIST

private	void	list_onfocus(struct asfun_list * lptr,struct asfun_window * wptr);
private	void	list_losefocus(struct asfun_list * lptr, struct asfun_window * wptr);

struct	asfun_item * 	remove_item(struct asfun_item * iptr)
{
	if ( iptr )
		liberate( iptr );
	return((struct asfun_item *) 0);
}

struct	asfun_list * 	remove_list(struct asfun_list * lptr)
{
	int	i;
	if (lptr) {
		if ( lptr->window )
			wsup(lptr->window);
		for ( i=0; i < lptr->options; i++ )
			lptr->option[i] = remove_item( lptr->option[i] );
		liberate(lptr);
		}
	return( (struct	asfun_list *) 0);
}

struct	asfun_item *	create_item()
{
	int	i;
	struct	asfun_item * iptr;

	if (!( iptr = allocate( sizeof( struct asfun_item ) ) ))
		return(iptr);
	else	{
		iptr->c = iptr->l = 0;
		iptr->ataff=0;
		iptr->etat =0;
		iptr->comlen=0;
		iptr->atlen=0;
		memset(iptr->value,' ',_MAX_VALUE);
		memset(iptr->comment,' ',_MAX_COMMENT);
		return( iptr );
		}
}

struct	asfun_list *	create_list()
{
	int	i;
	struct	asfun_list * lptr;

	if (!( lptr = allocate( sizeof( struct asfun_list ) ) ))
		return(lptr);
	else	{
		lptr->isopen	= 1;
		lptr->colinc	=
		lptr->rowinc	=
		lptr->indent	= 
		lptr->active	= 
		lptr->multiple  = 
		lptr->options	=
		lptr->mode	= 
		lptr->amode	= 
		lptr->dmode	= 
		lptr->align	= 
		lptr->lines	=
		lptr->columns	= 
		lptr->maxel	= 
		lptr->disel	= 
		lptr->lenel	= 
		lptr->comel	= 
		lptr->window 	=	 
		lptr->number 	= 0;
		for (i=0; i < _MAX_OPTIONS; i++ )
			lptr->option[i] = (struct asfun_option *) 0;
		return(lptr);
		}
}


public	void	show_styled_item( int topx, int topy, int grw, int grh, struct asfun_item * iptr, char * sptr)
{
	int	adjust=(Control.gfw+(Control.gfw/2));
	switch ( iptr->ataff ) {
		case	1 :
			visual_element(topx,topy,grw-adjust,grh,sptr,iptr->value,iptr->atlen);	
			break;
		default	  :
			visual_element(topx,topy,grw-adjust,grh,"asfun/list_inhibit",iptr->value,iptr->atlen);	
			break;
		}
	switch ( iptr->etat ) {
		case	1	:
			visual_element(topx-adjust,topy,adjust,grh,"asfun/list_active"," ",0);
			break;
		case	2	:
			visual_element(topx-adjust,topy,adjust,grh,"asfun/list_normal"," ",0);
			break;
		}
	return;
}

public	void	show_item( int topx, int topy, int grw, int grh, struct asfun_item * iptr)
{
	show_styled_item( topx,topy, grw, grh, iptr, "asfun/list_item" );
	return;
}

public	void	focus_item( int topx, int topy, int grw, int grh, struct asfun_item * iptr)
{
	show_styled_item( topx,topy, grw, grh, iptr, "asfun/list_focus" );
	sl_message( 1 /* comment */, iptr->comlen, iptr->comment);
	return;
}


public	void	show_items(int topx, int topy, struct asfun_list * lptr )
{
	int	c;
	int	l;
	int	nc;
	int	nl;
	int	n;
	int	grx,gry,grw,grh;
	struct 	asfun_item * iptr;
	if (!( lptr ))
		return;
	else	n = lptr->indent;

	for (l=0; l < lptr->lines; l++ ) {
		nl = (n+(l*lptr->rowinc));
		for ( c=0; c < lptr->columns; c++ ) {
			nc = (nl + (c * lptr->colinc));		
			if ( nc >= lptr->maxel )
				continue;
			else if (!( iptr = lptr->option[nc]))
				continue;
			else	{
				grw = (iptr->atlen * Control.gfw);
				grh = Control.gfh;
				iptr->c = c; iptr->l = l;
				show_item( topx+(c*grw)+Control.gfw, topy+(l*grh), grw, grh, iptr );
				}
			}
		}
	return;
}

public	void	show_list( struct asfun_list * lptr )
{
	int	grx,gry,grw,grh;
	int	topx,topy;
	struct	asfun_window * wptr;
	char *	sptr;
	char *	mptr;
	int	mlen;
	if (!( lptr ))
		return;
	else if (!( lptr->window ))
		return;
	else if (!( wptr = Control.windows[(lptr->window-1)] ))
		return;
	else	{
		hide();
		wvis(lptr->window);
		topx = wptr->grx;
		topy = wptr->gry;
		if ( lptr->options ) {
			show_items(topx,topy,lptr);
			}
		if (( lptr->multiple ) && (!( lptr->control & _NODIALOGBOX ))) { 
			/* show multiple validation message */
			grx = (Control.gfw);
			gry = ((wptr->h-3)*Control.gfh);
			grw = ((wptr->w-2)*Control.gfw);
			grh = Control.gfh;
			mptr = "Your Choice"; mlen = strlen(mptr);
			sptr = "asfun/list_message";
			visual_element(topx+grx,topy+gry,grw,grh,sptr,mptr,mlen);		
			/* show multiple validation buttons */
			grx = (Control.gfw);
			gry = ((wptr->h-1)*Control.gfh);
			grw = (((wptr->w-2)/3)*Control.gfw);
			grh = Control.gfh;
			sptr = "asfun/list_button";
			mptr = "Yes"; mlen = strlen(mptr);
			visual_element(topx+grx,topy+gry,grw,grh,sptr,mptr,mlen);		
			mptr = "No"; mlen = strlen(mptr);
			visual_element(topx+grx+grw,topy+gry,grw,grh,sptr,mptr,mlen);		
			mptr = "Abandon"; mlen = strlen(mptr);
			visual_element(topx+grx+(grw*2),topy+gry,grw,grh,sptr,mptr,mlen);		
			}
		if ( lptr->control & _VSCROLLBAR ) {
			/* vertical scrollbar */
			sptr = "asfun/vscroll_frame";
			visual_element(wptr->grx,wptr->gry,wptr->grw-Control.gfw,wptr->grh,sptr,mptr,mlen);		
			sptr = "asfun/vscroll_up";
			visual_element(wptr->grx,wptr->gry,wptr->grw-Control.gfw,wptr->grh,sptr,mptr,mlen);		
			sptr = "asfun/vscroll_down";
			visual_element(wptr->grx,wptr->gry,wptr->grw-Control.gfw,wptr->grh,sptr,mptr,mlen);		
			sptr = "asfun/vscroll_bar";
			visual_element(wptr->grx,wptr->gry,wptr->grw-Control.gfw,wptr->grh,sptr,mptr,mlen);		
			}
		if ( lptr->control & _HSCROLLBAR ) {
			/* horizontal scrollbar */
			sptr = "asfun/hscroll_frame";
			visual_element(wptr->grx,wptr->gry,wptr->grw,wptr->grh-(Control.gfh/2),sptr,mptr,mlen);		
			sptr = "asfun/hscroll_left";
			visual_element(wptr->grx,wptr->gry,wptr->grw,wptr->grh-(Control.gfh/2),sptr,mptr,mlen);		
			sptr = "asfun/hscroll_right";
			visual_element(wptr->grx,wptr->gry,wptr->grw,wptr->grh-(Control.gfh/2),sptr,mptr,mlen);		
			sptr = "asfun/hscroll_bar";
			visual_element(wptr->grx,wptr->gry,wptr->grw,wptr->grh-(Control.gfh/2),sptr,mptr,mlen);		
			}

		show(wptr->grx,wptr->gry,wptr->grw,wptr->grh);
		return;
		}
	return;
}

#ifdef	DEBUG_LIST
#define	wwwtrace(a,b) printf("asfungraphic::%s(%u)\r\n",a,b)
#else
#define	wwwtrace(a,b)
#endif

private	int	list_creat( int lid, char * dptr, int o, char * hptr, int multiple )
{
	int	v;
	struct	asfun_list 	* lptr;
	struct	asfun_window	* wptr;
	int			  wid;
	wwwtrace("list_creat",lid);
	if (( lid <= 0 ) || ( lid > _MAX_LISTS )) 
		return(1);
	else if (( lptr = Control.lists[(lid-1)] ) != (struct asfun_list *) 0)
		return(1);
	else if ((wid = next_free_window()) >= _MAX_WINDOWS)
		return(4);
	else if (!( lptr  = create_list() ))
		return(27);
	else if (!( wptr = create_window())) {
		remove_list(lptr);
		return(27);
		}
	else	{
		v = *(dptr++);
		wptr->style 	= v; /* (v & 7); */
		wptr->y 	= GetInt16( dptr ); dptr += WORDSIZE;
		wptr->x 	= GetInt16( dptr ); dptr += WORDSIZE;
		wptr->h 	= GetInt16( dptr ); dptr += WORDSIZE;
		lptr->lines	= wptr->h;
		lptr->control 	= o;
		if ( multiple ) {
			if (!( lptr->control & _NODIALOGBOX ))
				wptr->h += 4; 
			}
		if ( lptr->control & _VSCROLLBAR )
			wptr->w += 1;
		if ( lptr->control & _HSCROLLBAR )
			wptr->h += 1;

		memcpy(wptr->titre,dptr,(wptr->lentit = 32));
		if ( wptr->titre[0] == ' ' ) wptr->lentit=0;
		dptr += 32;
		lptr->multiple	= multiple;
		lptr->amode 	= *(dptr++);
		lptr->dmode 	= *(dptr++);
		lptr->mode = (lptr->dmode | (lptr->amode << 4));
		lptr->columns	= *(dptr++);
		dptr++; /* para bidon */
		lptr->align 	= *(dptr++);
		lptr->maxel	= GetInt16(dptr); dptr += WORDSIZE;
		lptr->lenel	= *(dptr++);
		lptr->disel	= *(dptr++);
		lptr->comel	= *(dptr++);
		wptr->w		= (lptr->columns * (lptr->disel+1) + 1);
		wptr->control   = v;
		wptr->control |= CAD1;
		use_window_control( wptr );
		wptr->fg 	= 0;	
		wptr->bg 	= 7;
		wptr->list	= lid;

		if (!( allocate_window(wptr) )) {
			remove_window( wptr );
			remove_list(lptr);
			return(27);			
			}
		else	{
			Control.windows[wid] = wptr;
			Control.lists[(lid-1)] = lptr;
			lptr->number = lid;
			lptr->window = (wid+1);
			lptr->colinc = lptr->rowinc = 0;
			return(0);
			}
		}

	return(0);
}

private	void	list_analyse( struct asfun_list * lptr )
{
	switch (lptr->mode) {
		case	LIST_AHDH	:
			lptr->colinc = 1;
			lptr->rowinc = (lptr->maxel / lptr->lines);
			break;
		case	LIST_AHDV	:
			lptr->colinc = 1;
			lptr->rowinc = lptr->columns;
			break;
		case	LIST_AVDH	:
			lptr->rowinc = 1;
			lptr->rowinc = lptr->lines;
			break;
		case	LIST_AVDV	:
			lptr->colinc = (lptr->maxel / lptr->columns);
			lptr->rowinc = 1;
			break;
		}
	return;
}

private	int	list_element(int l, char * e, int a, int o, char * vptr, char * cptr )
{
	int	i;
	int	iid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	struct	asfun_window * wptr;
	wwwtrace("list_element",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else if (!( vptr ))
		return(1);
	else if ( lptr->options >= lptr->maxel )
		return(78);
	else if (!( iptr = create_item() ))
		return( 27 );
	else	{
		iid = ++lptr->options;
		iptr->ataff = a;
		iptr->etat  = o;
		for (i=0; i < lptr->lenel; i++ )
			iptr->value[i] = *(vptr+i);
		iptr->value[i] = 0;
		iptr->atlen = lptr->disel;
		if (( cptr ) && ( lptr->comel )) {
			for (i=0; i < lptr->comel; i++ )
				iptr->comment[i] = *(cptr+i);
			iptr->comment[i] = 0;
			iptr->comlen =lptr->comel;
			}
		lptr->option[(iid-1)] = iptr;
		list_analyse(lptr);
		PutInt16(e,iid);
		return(0);
		}
}

private	int	list_del_element(int l, int e )
{
	int	i;
	int	wid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	wwwtrace("list_del_element",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else if ( e > lptr->options ) 
		return(78);
	else if (!( iptr = lptr->option[(e-1)] ))
		return(78);
	else	{
		remove_item( iptr );
		for (	i=(e-1); i < lptr->options; i++ )
			lptr->option[i] = lptr->option[i+1];
		lptr->options--;
		list_analyse(lptr);
		return(0);
		} 
}

private	int	list_ins_element(int l, int e, int a, int o, char * vptr, char * cptr )
{
	int	i;
	int	iid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	struct	asfun_window * wptr;
	wwwtrace("list_ins_element",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else if (!( vptr ))
		return(1);
	else if ( lptr->options >= lptr->maxel )
		return(78);

	if (!( iptr = create_item() ))
		return( 27 );
	else	{
		for (	i=lptr->options;
			i > e;
			i-- )
			lptr->option[i] = lptr->option[i-1];
		iptr->ataff = a;
		iptr->etat  = o;
		for (i=0; i < lptr->lenel; i++ )
			iptr->value[i] = *(vptr+i);
		iptr->value[i] = 0;
		iptr->atlen = lptr->disel;
		if (( cptr ) && ( lptr->comel )) {
			for (i=0; i < lptr->comel; i++ )
				iptr->comment[i] = *(cptr+i);
			iptr->comment[i] = 0;
			iptr->comlen =lptr->comel;
			}
		lptr->options++;
		lptr->option[(e-1)] = iptr;
		list_analyse(lptr);
		return(0);
		}
}

private	int	list_mat_element(int l, int e, int a, int o, char * vptr, char * cptr )
{
	int	i;
	int	iid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	struct	asfun_window * wptr;
	wwwtrace("list_mat_element",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else if (!( vptr ))
		return(1);
	else if ( lptr->options >= lptr->maxel )
		return(78);
	else if (!( iptr = lptr->option[(e-1)] ))
		return( 78 );
	else	{
		iptr->ataff = a;
		iptr->etat  = o;
		for (i=0; i < lptr->lenel; i++ )
			iptr->value[i] = *(vptr+i);
		iptr->value[i] = 0;
		iptr->atlen = lptr->disel;
		if (( cptr ) && ( lptr->comel )) {
			for (i=0; i < lptr->comel; i++ )
				iptr->comment[i] = *(cptr+i);
			iptr->comment[i] = 0;
			iptr->comlen =lptr->comel;
			}
		list_analyse(lptr);
		return(0);
		}
}

private	int	list_close(int l )
{
	int	wid;
	struct	asfun_list * lptr;
	wwwtrace("list_close",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else	{
		lptr->isopen	= 0;
		return(0);
		}
}

private	int	list_vis(int l, int e, int i, int a )
{
	int	wid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	struct	asfun_window * wptr;
	wwwtrace("list_vis",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else if (!( wid = lptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else	{
		lptr->indent = i;
		lptr->active = a;
		show_list( lptr );
		switch ( a ) {
			case	0 :	break;
			case	1 :	
				list_onfocus( lptr, wptr );
				break;
				
			case	2 :
				if (!( iptr = lptr->option[ a ] ))
					break;
				iptr->etat = 2;
				list_losefocus( lptr, wptr );
				break;

			}
		return(0);
		}
}


private	int	list_hide(struct asfun_list * lptr)
{
	int	wid;
	struct	asfun_window * wptr;
	if (!( wid = lptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else	{
		winv(lptr->window);
		return(0);
		}
}

private	int	list_inv(int l)
{
	struct	asfun_list * lptr;
	wwwtrace("list_inv",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else	return( list_hide( lptr ) );
}

private	int	list_sup(int l)
{
	int	wid;
	struct	asfun_list * lptr;
	struct	asfun_window * wptr;
	wwwtrace("list_sup",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else if (!( wid = lptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else	{
		Control.lists[(l-1)]= remove_list(lptr);
		return(0);
		}
}

private	int	list_line_up(struct asfun_list * lptr)
{
	struct	asfun_item * iptr;
	if (!( iptr = lptr->option[lptr->active] ))
		return(0);
	switch ( lptr->dmode ) {
		case	1 :	/* H */
			if ( iptr->l > 0 )
				lptr->active -= lptr->rowinc;
			break;

		case	2 :	/* V */
			if ( iptr->l > 0 )
				lptr->active -= lptr->rowinc;
			else if ( lptr->indent >= lptr->rowinc ) {
				lptr->indent -= lptr->rowinc;
				lptr->active -= lptr->rowinc;
				show_list(lptr);
				}
			break;
		}

	return(0);
}

private	int	list_adjust(struct asfun_list * lptr, int adjust)
{
	int n;
	n  = (lptr->indent + ((lptr->columns-1)*lptr->colinc) + ((lptr->lines-1)  *lptr->rowinc));
	if (( n + adjust ) >= lptr->maxel)
		return(0);
	else	return(1);
}

private	int	list_line_down(struct asfun_list * lptr)
{
	struct	asfun_item * iptr;
	if (!( iptr = lptr->option[lptr->active] ))
		return(0);
	switch ( lptr->dmode ) {
		case	1 :	/* H */
			if (( iptr->l + 1) < lptr->lines )
				lptr->active += lptr->rowinc;
			break;

		case	2 :	/* V */
			if (( iptr->l + 1) < lptr->lines )
				lptr->active += lptr->rowinc;
			else if (!( list_adjust( lptr, lptr->rowinc )))
				break;
			else if (( lptr->active + lptr->rowinc ) < lptr->options ) {
				lptr->active += lptr->rowinc;
				lptr->indent += lptr->rowinc;
				show_list( lptr );
				}
		}
	return(0);
}

private	int	list_page_up(struct asfun_list * lptr)
{
	if ( lptr->active >= lptr->rowinc )
		lptr->active -= lptr->rowinc;
	else	lptr->active = 0;
	if ( lptr->indent >= lptr->rowinc )
		lptr->indent -= lptr->rowinc;
	else	lptr->indent = 0;
	return(0);
}

private	int	list_page_down(struct asfun_list * lptr)
{
	lptr->indent += lptr->rowinc;
	lptr->active += lptr->rowinc;
	return(0);
}

private	int	list_cell_left(struct asfun_list * lptr)
{
	struct	asfun_item * iptr;
	if (!( iptr = lptr->option[lptr->active] ))
		return(0);
	switch ( lptr->dmode ) {
		case	1 :	/* H */
			if ( iptr->c > 0 )
				lptr->active -= lptr->colinc;
			else if ( lptr->indent >= lptr->colinc ) {
				lptr->active -= lptr->colinc;
				lptr->indent -= lptr->colinc;
				show_list( lptr );
				}
			break;
			
		case	2 :	/* V */
			if ( iptr->c > 0 )
				lptr->active -= lptr->colinc;
			break;
		}
	return(0);
}

private	int	list_cell_right(struct asfun_list * lptr)
{
	int	c;
	struct	asfun_item * iptr;
	if (!( iptr = lptr->option[lptr->active] ))
		return(0);
	switch ( lptr->dmode ) {
		case	1 :	/* H */
			if ((iptr->c + 1) < lptr->columns)
				lptr->active += lptr->colinc;
			else if (!( list_adjust( lptr, lptr->colinc )))
				break;
			else if (( lptr->active + lptr->colinc ) < lptr->options ) {
				lptr->active += lptr->colinc;
				lptr->indent += lptr->colinc;
				show_list( lptr );
				}
			break;
			
		case	2 :	/* V */
			if (( iptr->c + 1 ) < lptr->columns)
				lptr->active += lptr->colinc;
			break;
		}
	return(0);
}

private	void	list_onfocus(struct asfun_list * lptr,struct asfun_window * wptr)
{
	int	grw;
	int	grh;
	int	c;
	int	l;
	int	n;
	struct	asfun_item * iptr;
	if (!( iptr = lptr->option[lptr->active]))
		return;
	else	{
		grw = (iptr->atlen * Control.gfw);
		grh = Control.gfh;
		focus_item( wptr->grx+(iptr->c*grw)+Control.gfw, wptr->gry+(iptr->l*grh), grw, grh, iptr );
		return;
		}
}

private	void	list_losefocus(struct asfun_list * lptr, struct asfun_window * wptr)
{
	int	grw;
	int	grh;
	int	c;
	int	l;
	int	n;
	struct	asfun_item * iptr;
	if (!( iptr = lptr->option[lptr->active]))
		return;
	else	{
		grw = (iptr->atlen * Control.gfw);
		grh = Control.gfh;
		show_item( wptr->grx+(iptr->c*grw)+Control.gfw, wptr->gry+(iptr->l*grh), grw, grh, iptr );
		}
}

private	int	ll_use_list(int l, char * first, char * current, char * choix, char * value, char * key)
{
	int	event;
	int	wid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	struct	asfun_window * wptr;
	wwwtrace("use_list",l);
	if ((!( l  )) || ( l > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(l-1)] ))
		return(2);
	else if (!( wid = lptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else	{
		lptr->indent = (GetInt16(first)-1);
		lptr->active = (GetInt16(current)-1);
		show_list( lptr );
		while (1) {
			list_onfocus(lptr,wptr);
			event = x_getch();
			list_losefocus(lptr,wptr);
			switch ( event ) {
				case	27	: *choix = 2; break;
				case	 9	: *choix = 4; break;
				case	13	: *choix = 1; break;
				case	12	: 
					lptr->indent = lptr->active = 0;
					continue;
				case	32	:
					if (!( iptr = lptr->option[lptr->active] ))
						continue;
					else	{
						iptr->etat &= 1;
						iptr->etat += 1;
						continue;
						}
				case	 5	:
					list_line_down(lptr);
					continue;

				case	11	:
					list_line_up(lptr);
					continue;
				case	 6	:
					list_cell_right(lptr);
					continue;
				case	 8	:
					list_cell_left(lptr);
					continue;
				case	 3	:
					list_page_down(lptr);
					continue;
				case	18	:
					list_page_up(lptr);
					continue;
				default		:
					continue;
				}
			break;
			}
		if (!( lptr->control & _NOCLEAR ))
			list_hide(lptr);
		PutInt16(first,(lptr->indent+1));
		PutInt16(current,(lptr->active+1));
		if ( event != 13 )
			return(0);
		else if (!( value ))
			return(0);
		else if (!( iptr = lptr->option[lptr->active]))
			return(0);
		else	{
			memcpy( value, iptr->value, lptr->lenel );
			return(0);
			}
		}
}

private	int	use_list(int l, char * first, char * current, char * choix, char * value, char * key)
{
	int	status;
	clear_implicite_window();
	status = ll_use_list(l,first,current,choix,value,key);
	use_implicite_window();
	return( status );
}

static	int	list_read_element( int lid, int iid, char * aptr, char * eptr, char * vptr)
{
	int	wid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	wwwtrace("read_element",lid);
	if ((!( lid  )) || ( lid > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(lid-1)] ))
		return(40);
	else if (( iid < 1 ) || ( iid > lptr->options ))
		return( 78 );
	else if (!(iptr = lptr->option[(iid-1)]))
		return(78);
	else	{
		lptr->indent =
		lptr->active = (iid-1);
		*aptr = iptr->ataff;
		*eptr = iptr->etat;
		memcpy(vptr,iptr->value,lptr->lenel);
		return(0);
		}
}

static	int	list_down_element( int lid, char * item, char * aptr, char * eptr, char * vptr)
{
	int	iid;
	int	wid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	wwwtrace("down_element",lid);
	if ((!( lid  )) || ( lid > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(lid-1)] ))
		return(40);
	else if ((iid = ++lptr->active) >= lptr->options) 
		return(48);
	else if (!(iptr = lptr->option[iid]))
		return(78);
	else	{
		lptr->indent =
		lptr->active = iid;
		*aptr = iptr->ataff;
		*eptr = iptr->etat;
		memcpy(vptr,iptr->value,lptr->lenel);
		PutInt16(item,(iid+1));
		return(0);
		}
}

static	int	list_up_element( int lid, char * item, char * aptr, char * eptr, char * vptr)
{
	int	iid;
	int	wid;
	struct	asfun_list * lptr;
	struct	asfun_item * iptr;
	wwwtrace("up_element",lid);
	if ((!( lid  )) || ( lid > _MAX_LISTS ))
		return(3);
	else if (!( lptr = Control.lists[(lid-1)] ))
		return(40);
	else if (!( lptr->active ))
		return(64);
	else if ((iid = --lptr->active) < 0)
		return(64);
	else if (!(iptr = lptr->option[iid]))
		return(78);
	else	{
		lptr->indent =
		lptr->active = iid;
		*aptr = iptr->ataff;
		*eptr = iptr->etat;
		memcpy(vptr,iptr->value,lptr->lenel);
		PutInt16(item,(iid+1));
		return(0);
		}
}

#endif	/* _asfun_list_c */
	/* ------------- */




