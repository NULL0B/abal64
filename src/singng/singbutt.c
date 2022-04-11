#include "vframe.h"
public 	void	build_button(struct form_item * iptr )
{
	int			l,i,v,f;
	char	*		tptr;

	f = iptr->Contents.font;

	if ( iptr->Contents.w < (Context.FontTable[f].width*3))
		iptr->Contents.w = (Context.FontTable[f].width*3);

	if ( iptr->Contents.h < (Context.FontTable[f].height * 2))
		iptr->Contents.h = (Context.FontTable[f].height*2);

	if (Context.FontTable[f].width)
		l = ((iptr->Contents.w/Context.FontTable[f].width)-1);
	else	l = ((iptr->Contents.w/16)-1);
		
	switch ((iptr->Contents.style&_FRAME_TYPE)) {
		case	_CHECK_FRAME	:
		case	_RADIO_FRAME	:
			if ( l > 3 )
				l -= 3;
		}

	if ((tptr = allocate((l+1))) != (char *) 0) {
		for (v='A',i=0; i < l; i++ ) {
			*(tptr+i) = v++;
			if ( v > 'Z') v = 'A';
			}
		*(tptr+l) = 0;
		iptr->Contents.payload = tptr;
		iptr->Contents.size    = l;
		}
	return;
}

public	void	draw_button(int topx,int topy,struct form_item* iptr,int editing)
{
	int	fw;
	int	fh;
	int	w;
	int	h;
	char *	bptr;
	int	fg;
	int	bg;
	int	dummy=0;
	if (!( iptr ))
		return;
	else	{
		fg = (iptr->Contents.colour&0x00FF);
		bg = (iptr->Contents.colour>>8);
		switch ( iptr->Contents.style & _FRAME_TYPE ) {
			case	_SCROLL_FRAME	:
				visual_scrollbar( 
					topx+iptr->Contents.x,topy+iptr->Contents.y,
					iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,
					10,40,100,iptr->Contents.align);
				break;

			case	_DATA_FRAME	:
				fw = guifontsize(iptr->Contents.font);
				fh = ((fw >> 8) & 0x00FF);
				fw &= 0x00FF;
				if (!( method_is_valid( iptr->Contents.payload ) ))
					w = 0;
				else 	w = textsizelen( iptr->Contents.font, iptr->Contents.payload,strlen(iptr->Contents.payload));
				show_data_icon(topx+iptr->Contents.x,topy+iptr->Contents.y);
				if ( w ) {
					visual_text(	topx+iptr->Contents.x, 
							topy+iptr->Contents.y + iptr->Contents.h,
							w+(fw*2),fh, iptr->Contents.font,fg,0, iptr->Contents.payload,strlen(iptr->Contents.payload),3);
					}
				break;
			case	_FORM_FRAME	:
				visual_table( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,
					check_payload(iptr->Contents.payload),
					visual_table_testdata(iptr),
					(iptr->Contents.align | (iptr->Contents.format ? 0x4000 : 0)), 
					iptr->Contents.format );
				break;									

			case	_PROGRESS_FRAME	:
				visual_progress( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,100,50,iptr->Contents.align);
				break;

			case	_SELECT_FRAME 	:
				visual_select( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,parse_selection(check_payload(iptr->Contents.payload),&dummy),
					((iptr->Contents.align&7)<< 8));
				break;									
			case	_BUTTON_FRAME 	:
				visual_button( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,
					((iptr->Contents.align&1?_VISUAL_IMAGE:0) |
					 (iptr->Contents.align&_A_BOLD?_A_BOLD:0) |
					 (iptr->Contents.align&_A_LINE?_A_LINE:0) |
					 (iptr->Contents.align&_A_SHADOW?_A_SHADOW:0) |
					 (iptr->Contents.align&2?_INHIBIT_FRAME:0)));
				break;
			case	_CHECK_FRAME 	:
				visual_check( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,0 );
				break;
			case	_SWITCH_FRAME 	:
				visual_switch( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,
						((iptr->Contents.align & 0x0F00)| ((iptr->Contents.align & 0x000F) << 4)) );
				break;
			case	_GRAPH_FRAME 	:
				visual_graph( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,0 );
				break;
			case	_RADIO_FRAME 	:
				visual_radio( topx+iptr->Contents.x,topy+iptr->Contents.y,iptr->Contents.w,iptr->Contents.h,
					iptr->Contents.font,fg,bg,check_payload(iptr->Contents.payload),iptr->Contents.size,0,0 );
				break;
			}
		return;
		}
}






