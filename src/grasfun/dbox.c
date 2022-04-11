#ifndef	_asfun_dbox_c
#define	_asfun_dbox_c

public	int	next_free_dbox()
{
	int	bid;
	for (bid=0; bid < _MAX_DBOXS; bid++)
		if (!( Control.dboxs[bid] ))
			break;
	return(bid);
}


struct	asfun_element *	remove_element(struct asfun_element * eptr )
{
	if ( eptr )
		liberate( eptr );
	return((struct asfun_element *) 0);
}	

struct	asfun_dbox * 	remove_dbox(struct asfun_dbox * bptr)
{
	int	i;
	if (bptr) {

		if ( bptr->window ) {
 			Control.windows[(bptr->window-1)] = remove_window( Control.windows[(bptr->window-1)] );
			}

		for (i=0; i < _MAX_ELEMENTS; i++ ) {
			if (!( bptr->option[i] ))
				break;
			else 	bptr->option[i] = remove_element( bptr->option[i] );
			}
		liberate(bptr);
		}
	return( (struct	asfun_dbox *) 0);
}

struct	asfun_element *	create_element(struct asfun_dbox * bptr)
{
	int	i;
	struct asfun_element * eptr;
	if (!( bptr ))
		return;
	else if (( i = bptr->options) >= _MAX_ELEMENTS )
		return((struct asfun_element *) 0);
	else if (!( eptr = allocate( sizeof( struct asfun_element ) ) ))
		return(eptr);
	else	{
		bptr->options++;
		eptr->atc 	= eptr->atl 	= 0;
		eptr->nbl	= eptr->nbc	= 0;
		eptr->type	= eptr->style	= 0;
		eptr->trigger	= 0;
		eptr->boolean	= 0;
		eptr->active	= 0;
		eptr->current	= (int *) 0;
		eptr->isfocus	= 0;
		eptr->offset	= 0;
		eptr->position	= 0;
		eptr->insert	= 0;
		eptr->etat	= 0;
		eptr->items	= 0;
		memset(eptr->value,' ',_MAX_VALUE);
		memset(eptr->comment,' ',_MAX_COMMENT);
		return((bptr->option[i] = eptr));
		}
}

struct	asfun_dbox *	create_dbox()
{
	int	i;
	struct	asfun_dbox * bptr;

	if (!( bptr = allocate( sizeof( struct asfun_dbox ) ) ))
		return(bptr);
	else	{
		bptr->window = 0;
		bptr->style = 0;
		bptr->number = 0;
		bptr->lentit = 0;
		bptr->type = 0;	
		bptr->escape = 0;
		bptr->options = 0;
		bptr->lenopt = 0;
		bptr->lencom = 0;
		for (i=0; i < _MAX_ELEMENTS; i++ )
			bptr->option[i] = (struct asfun_element*) 0;
		memset(bptr->titre,32,_MAX_TITLE);
		return(bptr);
		}
}

private	void	styled_dbox_element(
	int	topx,int topy,
	struct asfun_element * eptr,
	char *	sptr,
	char *	mptr,
	int	mlen )
{
	int	grx,gry,grw,grh;
	if ( sptr ) {
		grx = (eptr->atc-1)*Control.gfw;
		gry = (eptr->atl-1)*Control.gfh;
		grw = (eptr->nbc*Control.gfw);
		grh = (eptr->nbl*Control.gfh);
		visual_element(topx+grx,topy+gry,grw,grh,sptr,mptr,mlen);		
		return;
		}
}

private	void	styled_dbox_element_len(
	int	topx,int topy,
	struct asfun_element * eptr,
	int	nbc,
	char *	sptr,
	char *	mptr,
	int	mlen )
{
	int	grx,gry,grw,grh;
	if ( sptr ) {
		grx = (eptr->atc-1)*Control.gfw;
		gry = (eptr->atl-1)*Control.gfh;
		grw = (nbc*Control.gfw);
		grh = (eptr->nbl*Control.gfh);
		visual_element(topx+grx,topy+gry,grw,grh,sptr,mptr,mlen);		
		return;
		}
}

public	void	show_element(int topx, int topy, struct asfun_element * eptr )
{
	char *	sptr=(char *) 0;
	int	fid;
	int	indx=0;
	if (!( eptr ))
		return;
	else	{
		switch ( eptr->type ) {

			case	DBOX_MESSAGE	:
				styled_dbox_element(topx,topy,eptr,"asfun/dbox_message",eptr->value,eptr->nbc);
				break;

			case	DBOX_BOUTON 	:
				styled_dbox_element(topx,topy,eptr,"asfun/dbox_button",eptr->value,eptr->nbc);
				break;

			case	DBOX_R_BOUTON	:
				styled_dbox_element(topx,topy,eptr,"asfun/dbox_radio"," ",0);
				if ( eptr->boolean == *eptr->current )
					styled_dbox_element(topx,topy,eptr,"asfun/dbox_radio_true"," ",0);
				styled_dbox_element(topx,topy,eptr,"asfun/dbox_radio_label",eptr->value,eptr->nbc);
				break;

			case	DBOX_C_BOUTON	:
				switch ( eptr->style ) {
					case	1 :
						styled_dbox_element(topx,topy,eptr,"asfun/dbox_check"," ",0);
						if ( eptr->boolean ) 
							styled_dbox_element(topx,topy,eptr,"asfun/dbox_check_true"," ",0);
						break;
					case	2 :
						styled_dbox_element(topx,topy,eptr,"asfun/dbox_switch_label",eptr->value,eptr->nbc);
						if ( eptr->boolean ) 
							styled_dbox_element(topx,topy,eptr,"asfun/dbox_switch_true","Yes",3);
						else	styled_dbox_element(topx,topy,eptr,"asfun/dbox_switch","No",2);
						break;
					}
				break;

			case	DBOX_SAISIE   	:
				if ( eptr->isfocus ) {
					if (!( eptr->insert ))
						styled_dbox_element(topx,topy,eptr,(sptr ="asfun/dbox_edit_focus"),(eptr->value+eptr->offset),(eptr->nbc+1));
					else	styled_dbox_element(topx,topy,eptr,(sptr="asfun_dbox/edit_insert"),(eptr->value+eptr->offset),(eptr->nbc+1));
					if (!(fid = resolve_style_font(sptr)))
						break;
					else	{
						indx = textsizelen(fid,eptr->value+eptr->offset,eptr->position - eptr->offset);
						styled_dbox_element_len(topx+indx,topy,eptr,1,"asfun/dbox_edit_cursor",(eptr->value+eptr->position),1);
						}
					}
				else	styled_dbox_element(topx,topy,eptr,"asfun/dbox_edit",(eptr->value+eptr->offset),(eptr->nbc+1));
				break;

			case	DBOX_AIDE  	:
				styled_dbox_element(topx,topy,eptr,"asfun/dbox_help",eptr->value,eptr->nbc);
				break;

			case	DBOX_LISTE   	:
				styled_dbox_element(topx,topy,eptr,"asfun/dbox_list"," ",0);
				break;

			case	DBOX_FUNFREE	:
				styled_dbox_element(topx,topy,eptr,"asfun/dbox_window"," ",0);
				break;
			}
		return;
		}
}


public	void	show_dbox( struct asfun_dbox * bptr )
{
	int	i;
	struct	asfun_window * wptr;
	if (!( bptr ))
		return;
	else if (!( bptr->window ))
		return;
	else if (!( wptr = Control.windows[(bptr->window-1)] ))
		return;
	else	{
		hide();
		wvis(bptr->window);
		if ( bptr->options ) {
			for (i=0; i < bptr->options; i++) {
				show_element( wptr->grx, wptr->gry, bptr->option[i] );
				}
			}
		show(wptr->grx,wptr->gry,wptr->grw,wptr->grh);
		return;
		}
	return;
}

private	void	dbox_value(struct asfun_element * eptr, char * mptr, int mlen )
{
	int	si;
	int	ri=0;
	int	flag=0;
	if (!( eptr ))
		return;
	else if (!( mptr ))
		return;
	else if (!( mlen ))	
		return;
	for ( si=0; si < mlen; si++ ) {
		if ( ri < _MAX_VALUE ) {
			if ( *(mptr+si) == '~' ) {
				if (!( flag ))
					eptr->value[ri++] = '&';
				flag = ((flag+1) & 1);
				}
			else	{
				if (( flag ) && (!( eptr->trigger )))
					eptr->trigger = *(mptr+si);
				eptr->value[ri++] = *(mptr+si);
				}
			}
		}
	eptr->value[ri] = 0;
	return;
}

private	int bd_creat(
	char *	hptr,
	int	atl,	int	atc,	int	nbl,	int	nbc,
	int	style,	char *	tptr,	int	tlen,	int	bsize
	)
{
	int	bid;
	int	wid;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((bid = next_free_dbox()) >= _MAX_DBOXS)
		return(4);
	else if ((wid = next_free_window()) >= _MAX_WINDOWS)
		return(4);
	else if (!( bptr  = create_dbox() ))
		return(27);
	else if (!( wptr = create_window())) {
		remove_dbox(bptr);
		return(27);
		}
	else	{
		wptr->style 	= style; /* (style & 7); */
		wptr->y 	= atl;
		wptr->x 	= atc;
		wptr->h 	= nbl;
		wptr->w		= nbc;
		wptr->control   = style;
		use_window_control( wptr );

		wptr->fg 	= 0;	wptr->bg 	= 7;
		wptr->dbox	= (bid+1);

		if (( tptr != (char *) 0 ) && ( tlen > 0 ))
			memcpy(wptr->titre,tptr,(wptr->lentit = (tlen <= 32 ? tlen : 32)));

		if (!( allocate_window(wptr) )) {
			remove_window( wptr );
			remove_dbox(bptr);
			return(27);			
			}
		else	{
			Control.windows[wid] = wptr;
			Control.dboxs[bid] = bptr;
			bptr->window = (wid+1);
			PutInt16( hptr, (bid+1) );
			return(0);
			}
		}
}

private int bd_message( int h, int atl, int atc, char * mptr, int mlen )
{
	int	wid;
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else if (!( eptr = create_element( bptr )))
		return(11);
	else	{
		eptr->atc = atc;
		eptr->atl = atl;
		eptr->nbc = mlen;
		eptr->nbl = 1;
		eptr->type = DBOX_MESSAGE;
		eptr->style = 0;
		dbox_value(eptr,mptr,mlen);
		return(0);
		}
}

private int bd_button( int h, int atl, int atc, char * mptr, int mlen, int type )
{
	int	wid;
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else if (!( eptr = create_element( bptr )))
		return(11);
	else	{
		eptr->atc = atc;
		eptr->atl = atl;
		eptr->nbc = mlen;
		eptr->nbl = 1;
		eptr->type = DBOX_BOUTON;
		eptr->style = 0;
		dbox_value(eptr,mptr,mlen);
		return(0);
		}
}

private int bd_radio( int h, int atl, int atc, int nbl, int nbc, char * mptr, int mlen  )
{
	int	i;
	int	n;
	struct asfun_element * fptr=(struct asfun_element *) 0;
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else	{
		for ( n=0; n < nbl; n++ ) {
			if (!( eptr = create_element( bptr )))
				return(11);
			else	{
				eptr->boolean = (n+1);
				if (!( fptr )) {
					fptr = eptr;
					fptr->active = 1;
					fptr->items = nbl;
					}
				eptr->current = &fptr->active;
				eptr->atc = atc;
				eptr->atl = atl++;
				eptr->nbc = nbc+3;
				eptr->nbl = 1;
				eptr->type = DBOX_R_BOUTON;
				eptr->style = 0;
				dbox_value(eptr,mptr,nbc);
				mptr += nbc;				
				}
			}
		return(0);
		}
}

private int bd_check( int h, int atl, int atc, int style, int nbl, int nbc, char * mptr, int mlen  )
{
	int	i;
	int	n;
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else	{
		for ( n=0; n < nbl; n++ ) {
			if (!( eptr = create_element( bptr )))
				return(11);
			else	{
				eptr->atc = atc;
				eptr->atl = atl++;
				eptr->nbc = 2+nbc+style;
				eptr->nbl = 1;
				eptr->type = DBOX_C_BOUTON;
				eptr->style = style;
				dbox_value(eptr,mptr,nbc);
				mptr += nbc;				
				}
			}
		return(0);
		}

}

private int bd_edit(int h, int atl, int atc, int nbvis, int nbc )
{
	int	wid;
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else if (!( eptr = create_element( bptr )))
		return(11);
	else	{
		eptr->atc = atc;
		eptr->atl = atl;
		eptr->nbc = nbvis;
		eptr->nbl = 1;
		eptr->type = DBOX_SAISIE;
		eptr->style = nbc;
		return(0);
		}
}

private int bd_list(int h, int atl, int atc, int lid )
{
	int	wid;
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else if (!( eptr = create_element( bptr )))
		return(11);
	else	{
		eptr->atc = atc;
		eptr->atl = atl;
		eptr->nbc = 11;	/* will come from list later : TODO */
		eptr->nbl = 1;
		eptr->type = DBOX_LISTE;
		eptr->style = lid;
		return(0);
		}
}

private int bd_help( int h, int atl, int atc, char * mptr, int mlen )
{
	int	wid;
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else if (!( eptr = create_element( bptr )))
		return(11);
	else	{
		eptr->atc = atc;
		eptr->atl = atl;
		eptr->nbc = mlen;
		eptr->nbl = 1;
		eptr->type = DBOX_AIDE;
		eptr->style = 0;
		dbox_value(eptr,mptr,mlen);
		return(0);
		}
}

private int bd_funky( int h, int atl, int atc, int wid )
{
	struct asfun_element * eptr;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else if (!( eptr = create_element( bptr )))
		return(11);
	else	{
		eptr->atc = atc;
		eptr->atl = atl;
		eptr->nbc = 1;
		eptr->nbl = 1;
		eptr->type = DBOX_FUNFREE;
		eptr->style = wid;
		return(0);
		}
}

private	int bd_putdata( int h, char * dptr )
{
	int	bitfield;
	int	bitmask;
	int	wid;
	int	i;
	int	n;
	struct	asfun_dbox * bptr;
	struct	asfun_element * eptr;
	struct	asfun_element * fptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else	{
		i=0; 
		while ( i < bptr->options ) {
			if (!( eptr = bptr->option[i++] ))
				continue;
			switch ( eptr->type ) {
				case DBOX_MESSAGE	:
					continue;
				case DBOX_BOUTON	:
					eptr->etat = *(dptr++);
					continue;
				case DBOX_R_BOUTON	:
					eptr->etat = *(dptr++);
					bitfield = GetInt16(dptr); 
					dptr += WORDSIZE;
					fptr = eptr;
					n = 0;
					while (1) {
						if (bitfield & (1 << n))
							*eptr->current = eptr->boolean;
						if ( ++n >= fptr->items )
							break;
						else if (!( eptr = bptr->option[i++] ))
							break;
						}
					continue;

				case DBOX_C_BOUTON	:
					eptr->etat = *(dptr++);
					bitfield = GetInt16(dptr); 
					dptr += WORDSIZE;
					fptr = eptr;
					n = 0;
					while (1) {
						if (bitfield & (1 << n))
							eptr->boolean=1;
						if ( ++n >= fptr->items )
							break;
						else if (!( eptr = bptr->option[i++] ))
							break;
						}
					continue;

				case DBOX_SAISIE	:
					eptr->etat = *(dptr++);
					dptr += WORDSIZE;
					for (n=0; n < eptr->style; n++ )
						eptr->value[n] = *(dptr++);
					continue;

				case DBOX_LISTE		:
					eptr->etat = *(dptr++);
					eptr->offset = GetInt16( dptr );
					dptr += WORDSIZE;
					eptr->position = GetInt16( dptr );
					dptr += WORDSIZE;
					/* step over value zone */
					dptr += eptr->nbc;
					continue;
				case DBOX_AIDE		:
					eptr->etat = 1;
					continue;
				case DBOX_FUNFREE     	:
					eptr->etat = *(dptr++);
					continue;

				}
			}
		return(0);
		}
}

private	void	dbox_onfocus( struct asfun_dbox * bptr, int e )
{
	struct	asfun_window * wptr;
	struct	asfun_element * eptr;
	if (e >= bptr->options )
		return;
	else if(!( eptr = bptr->option[e] ))
		return;
	else if ( eptr->type != DBOX_SAISIE )
		return;
	else if (!( bptr->window ))
		return;
	else if (!( wptr = Control.windows[(bptr->window-1)] ))
		return;
	else	{
		eptr->isfocus=1;
		show_element(wptr->grx,wptr->gry,eptr );
		}
}

private	void	dbox_losefocus( struct asfun_dbox * bptr, int e )
{
	struct	asfun_window * wptr;
	struct	asfun_element * eptr;
	if (e >= bptr->options )
		return;
	else if(!( eptr = bptr->option[e] ))
		return;
	else if ( eptr->type != DBOX_SAISIE )
		return;
	else if (!( bptr->window ))
		return;
	else if (!( wptr = Control.windows[(bptr->window-1)] ))
		return;
	else	{
		eptr->isfocus=0;
		show_element(wptr->grx,wptr->gry,eptr );
		}
}

private	int	dbox_onevent( struct asfun_dbox * bptr, int e, int event )
{
	int	i;
	struct	asfun_element * eptr;
	if (e >= bptr->options )
		return(e);
	else if(!( eptr = bptr->option[e] ))
		return(e);
	else if ( eptr->type != DBOX_SAISIE )
		return(e);
	if ( event != 9 )
		if (!( eptr->etat )) 
			return(e);
	switch ( event ) {
		case	1	:
			for (i=0; i < eptr->style; i++ )
				eptr->value[i] = ' ';
			eptr->offset = eptr->position = 0;
			break;

		case	9	:
			if ( e < bptr->options )
				e++;
			else	e = 0;
			break;

		case	6	:
			if ((eptr->position+1) < eptr->style )
				eptr->position += 1;
			while (( eptr->position - eptr->offset ) > (eptr->nbc+1) )
				eptr->offset++;
			break;

		case	8	:
			if (eptr->position > 0)
				eptr->position -= 1;
			else if ( eptr->offset > 0 )
				eptr->offset -= 1;
			break;
		case	15	:
			eptr->insert += 1;
			eptr->insert &= 1;
			break;
		case	127	:
			for (i=eptr->position; i < eptr->style; i++ ) {
				eptr->value[i]=eptr->value[i+1];
				}
			eptr->value[i]=0;
			break;
	
		default		:
			if (( event >= ' ' ) && ( eptr->position < eptr->style )) {
				if (!( eptr->insert ))
					eptr->value[eptr->position++] = event;
				else	{
					for ( i=eptr->style; i > eptr->position; i-- ) 
						eptr->value[i] = eptr->value[i-1];
					eptr->value[eptr->position++] = event;
					}
				while (( eptr->position - eptr->offset ) > (eptr->nbc+1) )
					eptr->offset++;
				}
		}
	return(e);
}

private	int ll_bd_use( int h, int e, char * r)
{
	int	event;
	int	i;
	int	mt;
	int	mb;
	int	mc;
	int	ml;
	int	wid;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	struct	asfun_element * eptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else	{
		show_dbox( bptr );
		while (1) {
			dbox_onfocus(bptr,e);
			event = x_getch();
			dbox_losefocus(bptr,e);
			switch ( event ) {
				case	27	:
					PutInt16( r, 2 );
					winv(bptr->window);
					return( 0 );
				case	13	:
					PutInt16( r, 1 );
					winv(bptr->window);
					return( 0 );
				case	256	:
					if ((mt = x_event(1)) != 32)
						continue;
					else if ((mb = x_event(2)) != 1)
						continue;
					ml = x_event(3); mc = x_event(4);
					if (( mc < wptr->x )
					||  ( ml < wptr->y )
					||  ( ml >=(wptr->y+wptr->h))
					||  ( mc >=(wptr->x+wptr->w)))
						continue;

					mc -= (wptr->x-1);
					ml -= (wptr->y-1);

					for (i=0; i < bptr->options; i++ ) {
						if (!( eptr = bptr->option[i] ))
							continue;
						if ( mc < eptr->atc )
							continue;
						else if ( ml < eptr->atl )
							continue;
						else if ( ml >= (eptr->atl+eptr->nbl))
							continue;
						else if ( mc >= (eptr->atc+eptr->nbc))
							continue;
						else	{
							e = i;
							if (!( eptr->etat )) 
								continue;
							switch ( eptr->type ) {
								case	DBOX_R_BOUTON	:
									*eptr->current = eptr->boolean;
									show_dbox( bptr );
									break;
								case	DBOX_C_BOUTON	:
									eptr->boolean += 1;
									eptr->boolean &= 1;
									show_dbox( bptr );
									break;
								case	DBOX_BOUTON	:
									PutInt16( r, eptr->style );
									if ( eptr->style )
										winv(bptr->window);
									return( 0 );
								}
							}
						}
					continue;
				default	:
					e = dbox_onevent(bptr,e,event);
					continue;
				}
			}
		}
}

private	int bd_use( int h, int e, char * r)
{
	int	status;
	clear_implicite_window();
	status = ll_bd_use( h, e ,r );
	use_implicite_window();
	return( status );
}

private	int bd_getdata( int h, char * dptr )
{
	int	i;
	int	n;
	int	bitfield;
	int	wid;
	struct	asfun_dbox * bptr;
	struct	asfun_element * eptr;
	struct	asfun_element * fptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else	{
		i=0; 
		while ( i < bptr->options ) {
			if (!( eptr = bptr->option[i++] ))
				continue;
			switch ( eptr->type ) {
				case DBOX_MESSAGE	:
					continue;
				case DBOX_BOUTON	:
					*(dptr++) = eptr->etat;
					continue;
				case DBOX_R_BOUTON	:
					*(dptr++) = eptr->etat;
					fptr = eptr;
					n = 0;
					bitfield=0;
					while (1) {
						if ( *eptr->current == eptr->boolean ) 
							bitfield = (1 << n);
						if ( ++n >= fptr->items )
							break;
						else if (!( eptr = bptr->option[i++] ))
							break;
						}
					PutInt16(dptr,bitfield);
					dptr += WORDSIZE;
					continue;

				case DBOX_C_BOUTON	:
					*(dptr++) = eptr->etat;
					bitfield = 0;
					fptr = eptr;
					n = 0;
					while (1) {
						if ( eptr->boolean )
							bitfield |= (1 << n);
						if ( ++n >= fptr->items )
							break;
						else if (!( eptr = bptr->option[i++] ))
							break;
						}
					PutInt16(dptr,bitfield);
					dptr += WORDSIZE;
					continue;

				case DBOX_SAISIE	:
					*(dptr++) = eptr->etat;
					PutInt16(dptr,eptr->position);
					dptr += WORDSIZE;
					for (n=0; n < eptr->style; n++ )
						*(dptr++) = eptr->value[n];
					continue;

				case DBOX_LISTE		:
					*(dptr++) = eptr->etat;
					PutInt16( dptr, eptr->offset );
					dptr += WORDSIZE;
					PutInt16( dptr, eptr->position);
					dptr += WORDSIZE;
					/* step over value zone */
					for (n=0; n < eptr->nbc; n++ )
						*(dptr++) = eptr->value[n];
					continue;
				case DBOX_AIDE		:
					continue;
				case DBOX_FUNFREE     	:
					*(dptr++) = eptr->etat;
					continue;

				}
			}
		return(0);
		}
}

private	int bd_inv( int h )
{
	int	wid;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else if (!( wid = bptr->window ))
		return(2);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(2);
	else	{
		winv(bptr->window);
		return(0);
		}
}

private	int bd_sup( int h )
{
	int	wid;
	struct	asfun_dbox * bptr;
	struct	asfun_window * wptr;
	if ((!( h  )) || ( h > _MAX_DBOXS ))
		return(3);
	else if (!( bptr = Control.dboxs[(h-1)] ))
		return(2);
	else	{
		Control.dboxs[(h-1)] = remove_dbox( bptr );
		return(0);
		}
}

#endif	/* _asfun_dbox_c */
	/* ------------- */


