#ifndef	_camera3d_c
#define	_camera3d_c

/*	BASIC CAMERA 3D FUNCTIONS	*/
/*	-------------------------	*/

/*	D R O P _ C A M E R A ( camera )	*/
/*	--------------------------------	*/

PRIVATE	struct camera3d * drop_camera( struct camera3d * cptr )
{
	struct	object3d *	optr;
	if ( cptr ) {
		while ((optr = cptr->first) != (struct object3d *) 0) {
			cptr->first = optr->next;
			drop_cube( optr );
			}
		if ( cptr->name )
			cptr->name = drop_string( cptr->name );
		liberate( cptr );
		}
	return( (struct camera3d *) 0 );
}

/*	A L L O C A T E _ C A M E R A ()	*/
/*	--------------------------------	*/

PRIVATE	int	set_background( cptr )
	struct camera3d * cptr;
{
	switch ( cptr->direction ) {
		case	yozo	:
			cptr->background= &ceiling;
			break;
		case	ypzo	:
			cptr->background= &floor;
			break;
		case	zoyo	:
			cptr->background= &background;
			break;
		case	zpyo	:
			cptr->background= &foreground;
			break;
		case	xoyo	:
			cptr->background= &leftwall;
			break;
		case	xpyo	:
			cptr->background= &rightwall;
			break;
		default		:
			cptr->background= &background;
			break;
		}
	return(1);
}

PRIVATE	struct camera3d * allocate_camera()
{
	struct camera3d * cptr;

	/* Allocate and Initialise 3d Camera Control Node */
	/* ---------------------------------------------- */
	if ((cptr = (struct camera3d *) allocate( sizeof( struct camera3d ) )) == (struct camera3d *) 0)
		return((struct camera3d*) 0 );

	else	{
		cptr->name  = (char *) 0;
		cptr->configuration = (char *) 0;
		cptr->step  = DEFAULT_STEP;
		cptr->timer = DEFAULT_TIMER;
		cptr->first = cptr->last = cptr->current = 
		cptr->foot  = cptr->head = (struct object3d *) 0;
		cptr->direction = zoyo;
		cptr->treenode  = (struct treeview *) 0;
		cptr->host      = (struct treeview *) 0;
		(void) set_background(cptr);
		/* Towards Negative Z with Negative Y above */
		cptr->position.x = cptr->position.y = cptr->position.z = 200;
		cptr->focus.x = cptr->focus.y = 0;
		cptr->options= 0;
		return( cptr );
		}
}

/*	S H O W _ C A M E R A ( camera )	*/
/*	--------------------------------	*/

PRIVATE	int		  erase_camera( cptr )
	struct camera3d * cptr;
{
	struct object3d * optr;
	for (	optr=cptr->foot;
		optr != (struct object3d *) 0;
		optr = optr->before )
		erase3d( optr );
	return(0);
}

PRIVATE	int		  show_camera( struct camera3d * cptr )
{
	struct object3d * optr;

	if ( cptr ) {
		for (	optr=cptr->head;
			optr != (struct object3d *) 0;
			optr = optr->after ) {
			display3d( optr );
			}
		}
	return( 0 );
}

PRIVATE	int	ispriority( optr, tptr, cptr )
	struct object3d * optr;
	struct object3d * tptr;
	struct camera3d * cptr;
{
	int		  status=0;
	struct area2d     area={0,0,0,0};

	if ( coverage2d( &optr->descriptor, &tptr->descriptor, & area ) != 0 ) {

		switch (cptr->direction) {

			case	xoyp	 :
				if ( optr->bottomright.x < tptr->topleft.x )
					{	status=1; break;	}
				else if (( optr->topleft.z > cptr->position.z    )
				     &&  ( optr->topleft.z > tptr->bottomright.z ))
					{	status=1; break;	}
				else if (( optr->bottomright.z < cptr->position.z)
				     &&  ( optr->bottomright.z < tptr->topleft.z ))
					{	status=1; break;	}
				else if (( optr->bottomright.y > cptr->position.y    )
				     &&  ( optr->bottomright.y > tptr->topleft.y ))
					{	status=1; break;	}
				else if (( optr->topleft.y < cptr->position.y)
				     &&  ( optr->topleft.y < tptr->bottomright.y ))
					{	status=1; break;	}
				else	{	status=0; break;	}

			case	xoyo	 :
				if ( optr->bottomright.x < tptr->topleft.x )
					{	status=1; break;	}
				else if (( optr->bottomright.z > cptr->position.z    )
				     &&  ( optr->bottomright.z > tptr->topleft.z ))
					{	status=1; break;	}
				else if (( optr->topleft.z < cptr->position.z)
				     &&  ( optr->topleft.z < tptr->bottomright.z ))
					{	status=1; break;	}
				else if (( optr->topleft.y > cptr->position.y    )
				     &&  ( optr->topleft.y > tptr->bottomright.y ))
					{	status=1; break;	}
				else if (( optr->bottomright.y < cptr->position.y)
				     &&  ( optr->bottomright.y < tptr->topleft.y ))
					{	status=1; break;	}
				else	{	status=0; break;	}


			case	xozo	 :

			case	xozp	 :

				if ( optr->bottomright.x < tptr->topleft.x )
					{	status=1; break;	}
				else	{	status=0; break;	}

			case	xpzp	 :
			case	xpzo	 :
			case	xpyo	 :
			case	xpyp	 :

				if ( optr->topleft.x > tptr->bottomright.x )
					{	status=1; break;	}
				else	{	status=0; break;	}

			case	yoxp	 :
			case	yoxo	 :
			case	yozp	 :
			case	yozo	 :

				if ( optr->bottomright.y < tptr->topleft.y )
					{	status=1; break;	}
				else	{	status=0; break;	}

			case	ypzo	 :
			case	ypzp	 :
			case	ypxo	 :
			case	ypxp	 :

				if ( optr->topleft.y > tptr->bottomright.y )
					{	status=1; break;	}
				else	{	status=0; break;	}

			case	zoyo	 :
				if ( optr->bottomright.z < tptr->topleft.z )
					{	status=1; break;	}
				else if (( optr->topleft.x > cptr->position.x    )
				     &&  ( optr->topleft.x > tptr->bottomright.x ))
					{	status=2; break;	}
				else if (( optr->bottomright.x < cptr->position.x)
				     &&  ( optr->bottomright.x < tptr->topleft.x ))
					{	status=3; break;	}
				else if (( optr->topleft.y > cptr->position.y    )
				     &&  ( optr->topleft.y > tptr->bottomright.y ))
					{	status=4; break;	}
				else if (( optr->bottomright.y < cptr->position.y)
				     &&  ( optr->bottomright.y < tptr->topleft.y ))
					{	status=5; break;	}
				else	{	status=0; break;	}

			case	zoyp	 :
				if ( optr->bottomright.z < tptr->topleft.z )
					{	status=1; break;	}
				else if (( optr->bottomright.x > cptr->position.x    )
				     &&  ( optr->bottomright.x > tptr->topleft.x ))
					{	status=2; break;	}
				else if (( optr->topleft.x < cptr->position.x)
				     &&  ( optr->topleft.x < tptr->bottomright.x ))
					{	status=3; break;	}
				else if (( optr->bottomright.y > cptr->position.y    )
				     &&  ( optr->bottomright.y > tptr->topleft.y ))
					{	status=4; break;	}
				else if (( optr->topleft.y < cptr->position.y)
				     &&  ( optr->topleft.y < tptr->bottomright.y ))
					{	status=5; break;	}
				else	{	status=0; break;	}

			case	zoxo	 :
			case	zoxp	 :

				if ( optr->bottomright.z < tptr->topleft.z )
					{	status=1; break;	}
				else	{	status=0; break;	}

			case	zpyo	 :
			case	zpxp	 :
			case	zpxo	 :
			case	zpyp	 :

				if ( optr->topleft.z > tptr->bottomright.z )
					{	status=1; break;	}
				else	{	status=0; break;	}

			}

		}
	return(status);
}

PRIVATE	int		  calc_camera( cptr )
	struct camera3d * cptr;
{
	struct object3d * optr;
	struct object3d * tptr;

	if ( cptr ) {

		set3dfocus( cptr->focus.x, cptr->focus.y );
		for (	optr=cptr->first,
			cptr->head = cptr->foot = (struct object3d *) 0;
			optr != (struct object3d *) 0;
			optr = optr->next ) {
			optr->before = optr->after = (struct object3d *) 0;
			calculate3d( optr, & cptr->position, cptr->direction );
			if ((tptr = cptr->head) == (struct object3d *) 0) {
				cptr->foot = cptr->head = optr;
				}
			else 	{
				while ( tptr != (struct object3d *) 0 ) {
					if ( ispriority( optr, tptr, cptr ) ) {
						if ((optr->before = tptr->before) == (struct object3d *) 0)
							cptr->head = optr;
						else	optr->before->after = optr;
						tptr->before= optr;
						optr->after = tptr;
						break;
						}
					else if ((tptr = tptr->after) == (struct object3d *) 0) {
						if ((optr->before = cptr->foot) == (struct object3d *) 0)
							cptr->head = optr;
						else	cptr->foot->after = optr;
						cptr->foot = optr;
						}
					}
				}			
			}

		}

	return( 0 );
}

PRIVATE	int		freeze_camera( cptr )
	struct camera3d * cptr;
{
	freeze3d(cptr->background);
	return(0);
}

PRIVATE	int		thaw_camera( cptr )
	struct camera3d * cptr;
{
	thaw3d();
	return(0);
}


PUBLIC	void	add_cube(struct camera3d * cptr,struct object3d * optr)
{
	if ((!( cptr ))
	||  (!( optr )))
		return;

	else 	{
		if ((optr->previous = cptr->last))
			cptr->last->next = optr;
		else	{
			cptr->current = cptr->first = optr;
			}
		cptr->last = optr;
		optr->host = cptr;
		return;
		}
}

PUBLIC	void	del_cube(struct camera3d * cptr,struct object3d * optr)
{
	if ((!( cptr ))
	||  (!( optr )))
		return;

	else 	{
		/* if its the last one : new last one (maybe null) */
		if (!(cptr->current = optr->next )) {
			cptr->current = cptr->last = optr->previous;			
			}
		else	optr->next->previous = optr->previous;

		/* if its the first one : new first one (maybe null) */

		if (!( optr->previous ))
			cptr->first = optr->next;
		else	optr->previous->next = optr->next;

		drop_cube( optr );
		return;
		}
}


#endif	/* _camera3d_c */
	/* ----------- */

