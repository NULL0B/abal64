#ifndef	_sframe_c
#define	_sframe_c

#include "vstyle.h"

public	int	is_styled_outset_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if (use_default_style( visual_outset_frame ) )
		return(visual_element( x,y,w,h, "outsetframe", " ",0));
	else	return(78);
}

public	int	is_styled_inset_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if (use_default_style( visual_inset_frame ) )
		return(visual_element( x,y,w,h, "insetframe", " ",0));
	else	return(78);
}

public	int	is_styled_ridge_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if (use_default_style( visual_ridge_frame ) )
		return(visual_element( x,y,w,h, "ridgeframe", " ",0));
	else	return(78);
}

public	int	is_styled_groove_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if (use_default_style( visual_groove_frame ) )
		return(visual_element( x,y,w,h, "grooveframe", " ",0));
	else	return(78);
}

public	int	styled_outset_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if ( is_styled_outset_frame(x,y,w,h,style) != 0 )
		return(visual_frame(x,y,w,h,style));
	else	return(0);
}

public	int	styled_inset_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if ( is_styled_inset_frame(x,y,w,h,style) != 0 )
		return(visual_frame(x,y,w,h,style));
	else	return(0);
}

public	int	styled_groove_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if ( is_styled_groove_frame(x,y,w,h,style) != 0 )
		return(visual_frame(x,y,w,h,style));
	else	return(0);

}

public	int	styled_ridge_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if ( is_styled_ridge_frame(x,y,w,h,style) != 0 )
		return(visual_frame(x,y,w,h,style));
	else	return(0);
}

public	int	styled_edit_frame(EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD style)
{
	if ( use_default_style( visual_edit_frame ) )
		return(visual_element( x,y,w,h, "editframe", " ",0));
	else	return(visual_frame(x,y,w,h,style));
}

#endif	/* _sframe_c */
	/* --------- */



