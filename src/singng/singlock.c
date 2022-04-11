#ifndef	_singlock_c
#define	_singlock_c

/*	-------------------------------		*/
/*	this file is included by sing.c		*/
/*	-------------------------------		*/

/*	-------------------------------------------------------------	*/
/*	This table defines the widget gridlock/fontlock state switchs	*/
/*	-------------------------------------------------------------	*/
/*									*/
/*	This is used by the apply_gridlock function for the width and	*/
/*	height recalculations. 						*/
/*									*/
/*	when bit 1 is zero, standard grid locking will be applied	*/
/*	when bit 1 is true, widget font size grid locking occurs.	*/
/*									*/
/*	Higher order bits may provide widget standard size increase 	*/
/*	for eventual frame information.					*/
/*									*/
/*	This information is now stored and retrieved to and from 	*/
/*	project xml resource files.					*/
/*									*/
/*	-------------------------------------------------------------	*/

#define	_WIDGET_FONT_LOCK	1
#define	_WIDGET_FRAME_LOCK	~1


private	int	widget_fontlock[32] = {

	/* _FILL_FRAME		0  */	0,
	/* _OUTSET_FRAME	1  */	0,
	/* _INSET_FRAME		2  */	0,
	/* _RIDGE_FRAME		3  */	0,
	/* _GROOVE_FRAME	4  */	0,
	/* _EDIT_FRAME		5  */	1,
	/* _TEXT_FRAME		6  */	1,
	/* _IMAGE_FRAME		7  */	0,
	/* _LINE_FRAME		8  */	0,
	/* _BUTTON_FRAME	9  */	1,
	/* _WINDOW_FRAME	10 */	0,
	/* _TAB_FRAME		11 */	0,
	/* _CHECK_FRAME		12 */	1,
	/* _RADIO_FRAME		13 */	1,
	/* _SELECT_FRAME	14 */	1,
	/* _FORM_FRAME		15 */	5,
	/* _SCROLL_FRAME	16 */	0,
	/* _PROGRESS_FRAME	17 */	0,
	/* _SWITCH_FRAME	18 */	1,
	/* _GRAPH_FRAME		19 */	1,
	/* _DATA_FRAME		20 */	0,

	/* and the rest */
	/* ------------ */
	0,0,0,0,0,0,0,0,0,0,0

	};

public	int	get_widget_gridlock( int wstyle ) 
{
	if ( wstyle > 20 )
		return(0);
	else	return(widget_fontlock[wstyle]);
}

public	void	set_widget_gridlock( int wstyle, int wvalue ) 
{
	if ( wstyle <= 20 )
		widget_fontlock[wstyle] = wvalue;
	return;
}

private	int	lock_font_width( int v, int adjust, int fid )
{
	int	x;
	int	fw;
	if (!( fid ))
		return( v );
	fw  = (guifontsize(fid) & 0x00FF);
	if ((x = (v % fw)) > 0) {
		if ( v > (fw/2))
			v = (((v / fw)+adjust)*fw);
		else	v -= x;
		}
	else if (!( v ))
		v = ( fw * adjust);

	return(v);
}

private	int	lock_font_height( int v, int adjust, int fid )
{
	int	x;
	int	fh;

	if (!( fid ))
		return( v );

	fh  = ((guifontsize(fid) >> 8) & 0x00FF);

	if ((x = (v % fh)) > 0) {
		if ( v > (fh/2))
			v = (((v / fh)+adjust)*fh);
		else	v -= x;
		}
	else if (!( v ))
		v = (fh * adjust);
	return(v);
}

public 	void	apply_gridlock( struct window_control * wptr, int mode )
	/* Mode : 1	:	apply to position coordinates	*/
	/* Mode : 2	:	apply to dimension coordinates	*/
	/* Mode : 4	:	force round up			*/
{
	int	wstyle;
	int	dflag;
	if ( mode & 4 )	
		dflag=0;
	else	dflag=1;

	if ( Context.gridlockw ) {

		if ( mode & 1 ) {
			wptr->x = use_grid_lock( wptr->x,0,Context.gridlockw );
			wptr->y = use_grid_lock( wptr->y,0,Context.gridlockh  );
			}

		if ( mode & 2 ) {
			if ((wstyle = (wptr->style & _FRAME_TYPE)) == _BUTTON_FRAME) {
				switch ( ( wptr->align & 3 )) {
					case	0 :
					case	1 :	break;
					case	2 :	wstyle = _TEXT_FRAME;
					case	3 :	wstyle = _IMAGE_FRAME;
					}
				}
			if (( widget_fontlock[wstyle] & _WIDGET_FONT_LOCK) != 0) {
				wptr->w = (lock_font_width( wptr->w,dflag, wptr->font )
					  +(widget_fontlock[wstyle] & _WIDGET_FRAME_LOCK));
				wptr->h = (lock_font_height( wptr->h,dflag,wptr->font )
					  +(widget_fontlock[wstyle] & _WIDGET_FRAME_LOCK));
				}
			else	{
				wptr->w = use_grid_lock( wptr->w,dflag,Context.gridwidth );
				wptr->h = use_grid_lock( wptr->h,dflag,Context.gridheight);
				}
			}
		}
	return;
}


	/* ----------- */
#endif	/* _singlock_c */
	/* ----------- */

