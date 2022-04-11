#ifndef	_view3d_c
#define	_view3d_c

private	int	camera_use_view( struct camera3d * cptr, struct view3d   * vptr )
{
	cptr->focus.x 	= vptr->focus.x;
	cptr->focus.y 	= vptr->focus.y;
	cptr->position.x= vptr->position.x;
	cptr->position.y= vptr->position.y;
	cptr->position.z= vptr->position.z;
	cptr->direction = vptr->direction;
	draw_Camera( cptr );
	return(0);
}

public	int	camera_top_view(struct camera3d * cptr)
{
	struct view3d   * vptr;
	if (!( cptr ))
		return(118);
	else if (!(vptr = cptr->topview ))
		return(118);
	else	{
		cptr->curview = vptr;
		return(camera_use_view(cptr, vptr));
		}
}

public	int	camera_next_view(struct camera3d * cptr)
{
	struct view3d   * vptr;
	if (!( cptr ))
		return(118);
	else if (!( cptr->curview ))
		return(118);
	else if (!(vptr = cptr->curview->next ))
		return(118);
	else	{
		cptr->curview = vptr;
		return(camera_use_view(cptr, vptr));
		}
}

public	int	camera_drop_view(struct camera3d * cptr)
{
	struct view3d   * vptr;
	if (!( cptr ))
		return(118);
	else if (!(vptr = cptr->curview ))
		return(118);
	else	{
		if (!( vptr->next )) {
			cptr->curview = vptr->previous;
			if (!( cptr->endview = vptr->previous ))
				cptr->topview = cptr->curview = cptr->endview;
			else	cptr->endview->next = (struct view3d*) 0;
			}
		else	{
			vptr->next->previous = vptr->previous;
			cptr->curview = vptr->next;
			}
		if (!( vptr->previous )) {
			if (!( cptr->topview = vptr->next ))
				cptr->endview = cptr->curview = cptr->topview;
			else	cptr->topview->previous = (struct view3d*) 0;
			}
		else	vptr->previous->next = vptr->next;
		liberate( vptr );
		return(0);
		}
}
			
public	int	camera_prev_view(struct camera3d * cptr)
{
	struct view3d   * vptr;
	if (!(cptr ))
		return(118);
	else if (!( cptr->curview ))
		return(118);
	else if (!(vptr = cptr->curview->previous ))
		return(118);
	else	{
		cptr->curview = vptr;
		return(camera_use_view(cptr, vptr));
		}
}

public	int	camera_end_view(struct camera3d * cptr)
{
	struct view3d   * vptr;
	if (!(cptr ))
		return(118);
	else if (!(vptr = cptr->endview ))
		return(118);
	else	{
		cptr->curview = vptr;
		return(camera_use_view(cptr, vptr));
		}
}

public	int	camera_new_view(struct camera3d * cptr)
{
	struct view3d   * vptr;
	if (!(cptr ))
		return(118);
	else if (!( vptr = allocate( sizeof( struct view3d ) ) ))
		return(27);
	else	{
		vptr->focus.x 	= cptr->focus.x;
		vptr->focus.y 	= cptr->focus.y;
		vptr->position.x= cptr->position.x;
		vptr->position.y= cptr->position.y;
		vptr->position.z= cptr->position.z;
		vptr->direction = cptr->direction;
		vptr->previous = vptr->next = (struct view3d*) 0;
		if (!( vptr->previous = cptr->endview))
			cptr->topview = vptr;
		else	cptr->endview->next = vptr;
		cptr->endview = vptr;
		cptr->curview = vptr;
		return(0);
		}
}

public	int	camera_add_view()
{
	return( camera_new_view( Context.Camera ) );
}

public	int	camera_del_view()
{
	return(camera_drop_view( Context.Camera ) ); 
}

public	int	camera_xy_focus(int v)
{
	struct camera3d * cptr;
	if (!(cptr = Context.Camera ))
		return(118);
	else	{
		cptr->focus.x = v;
		cptr->focus.y = v;
		draw_Camera( cptr );
		return(0);
		}
}

public	int	camera_x_focus(int v)
{
	struct camera3d * cptr;
	if (!(cptr = Context.Camera ))
		return(118);
	else	{
		cptr->focus.x += v;
		draw_Camera( cptr );
		return(0);
		}
}
public	int	camera_y_focus(int v)
{
	struct camera3d * cptr;
	if (!(cptr = Context.Camera ))
		return(118);
	else	{
		cptr->focus.y += v;
		draw_Camera( cptr );
		return(0);
		}
}

#endif	/* _view3d_c */
	/* --------- */


