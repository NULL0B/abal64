
#include "singedit.h"
static	struct	sing_text_editor Editor;
static	int			editor_ready=0;

private	int	initialise_editor()
{
	if (!( editor_ready )) {

		if  (!( Editor.Buffer = allocate( MAX_EDITOR_BUFFER + 16 ) ))
			return(27);

		Editor.Window.font =
		Editor.Zone.font   = Context.basefont;
		Editor.Zone.h    = (EDITOR_ROWS * Context.fontheight);
		Editor.Zone.w    = (EDITOR_COLUMNS * Context.fontwidth);
		Editor.Window.w = (Editor.Zone.w + (Context.fontwidth*4));
		Editor.Window.h = (Editor.Zone.h + (Context.fontheight*8));
		Editor.Window.x = ((Context.DeskTop.w - Editor.Window.w)/2);
		Editor.Window.y = ((Context.DeskTop.h - Editor.Window.h)/2);
		Editor.Zone.x = (Editor.Window.x+(Context.fontwidth*2));
		Editor.Zone.y = (Editor.Window.y+(Context.fontheight*3));
		Editor.Window.colour =
		Editor.Zone.colour   = (standard_black | (standard_white << 8));

		editor_ready = 1;

		}
	return(0);
}
		
public	char *	standard_editor( char * tptr, char * mptr )
{
	int	mx,my;
	int	i;
	int	l;
	int	mlen;

	if (!( mptr ))
		mlen = 0;
	else	mlen = strlen( mptr );

	if (initialise_editor()) return((char *) 0);

	memset( Editor.Buffer, ' ', MAX_EDITOR_BUFFER );
	*Editor.Buffer = 0;

	if ( tptr ) {
		strcpy( Editor.Buffer, tptr );
		*(Editor.Buffer+strlen(tptr)) = ' ';
		}

	*(Editor.Buffer+MAX_EDITOR_BUFFER) = 0;

	/* ON SHOW */

	window(	Context.DeskTop.x + Editor.Window.x,
		Context.DeskTop.y + Editor.Window.y,
		Editor.Window.w,Editor.Window.h,Editor.Window.font,mptr,mlen,3);

	frame(	(Context.DeskTop.x+Editor.Zone.x)-1,
		(Context.DeskTop.y+Editor.Zone.y)-1,
		(Editor.Zone.w+2),(Editor.Zone.h+2),_EDIT_FRAME);

	button(	(Context.DeskTop.x+Editor.Zone.x)-1,
		((Context.DeskTop.y+Editor.Zone.y)+(Editor.Zone.h+Context.fontheight)),
		(Context.fontwidth * 16),
		(Context.fontheight * 2),
		Editor.Window.font,
		standard_black,standard_lomid,
		"     OK     ",12,0);

	button(	(Context.DeskTop.x+Editor.Zone.x)+(Context.fontwidth * 20),
		((Context.DeskTop.y+Editor.Zone.y)+(Editor.Zone.h+Context.fontheight)),
		(Context.fontwidth * 16),
		(Context.fontheight * 2),
		Editor.Window.font,
		standard_black,standard_lomid,
		"   Cancel   ",12,0);

	Editor.Zone.payload = Editor.Buffer;
	Editor.Zone.size    = MAX_EDITOR_BUFFER;

	/* ON GET FOCUS */
	while (1) {
		switch ( edit_text ( Context.DeskTop.x, Context.DeskTop.y, & Editor.Zone ) ) {
			case	27	:
				return((char *) 0);
			case	256	:
				/* ON EVENT */
				mx = visual_event(7);
				my = visual_event(6);
				if ((my >= ((Context.DeskTop.y+Editor.Zone.y)+(Editor.Zone.h+Context.fontheight)))
				&&  (my < (((Context.DeskTop.y+Editor.Zone.y)+(Editor.Zone.h+Context.fontheight))+(Context.fontheight * 2)))) {
					if (( mx >= ((Context.DeskTop.x+Editor.Zone.x)-1))
					&&  ( mx <  (((Context.DeskTop.x+Editor.Zone.x)-1)+(Context.fontwidth*16)))) {
						if ( visual_event(1) == _MIMO_UP )
							break;
						}
					if (( mx >= (((Context.DeskTop.x+Editor.Zone.x)-1)+(Context.fontwidth*20)))
					&&  ( mx <  (((Context.DeskTop.x+Editor.Zone.x)-1)+(Context.fontwidth*36)))) {
						if ( visual_event(1) == _MIMO_UP )
							return((char *) 0);
						}
					}
				continue;
			default		:
				break;
			}
		break;
		}

	/* ON REMOVE */
	for (l=0,i=0; i < MAX_EDITOR_BUFFER; i++ )
		if ( *(Editor.Buffer + i) != ' ')
			l = (i+1);
	if ( tptr )
		tptr = liberate( tptr );
	
	if ( l > 0 ) {
		tptr = allocate( (l+16) );
		memset( tptr, 0, l+1);
		memcpy( tptr, Editor.Buffer, l );
		}
	else	tptr = "\0";

	return( tptr );

}


