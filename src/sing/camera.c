#ifndef	_camera_c
#define	_camera_c

#include "camera3d.c"

PRIVATE	int		wait_camera( cptr )
	struct camera3d * cptr;
{
	if ( cptr->timer )
		zwait(cptr->timer);
	else	zabqt();
	return(0);
}

PRIVATE	int		rotation( handle, direction )
	FILE *		handle;
	int		direction;
{
	char	*	sptr;

	if (!(sptr = keyword( handle )))
		return( -1 );
	else if ( compare( sptr, "none" ) ) 
		return( direction );
	else if ( compare( sptr, "left" ) ) 
		switch (direction) {
			case	zoyo	: direction = zoxp; break;
			case	zpyo	: direction = zpxp; break;
			case	xoyo	: direction = xozo; break;
			case	xpyo	: direction = xpzp; break;
			case	yozo	: direction = yoxo; break;
			case	ypzo	: direction = ypxp; break;
			}
	else if ( compare( sptr, "right" ) ) 
		switch (direction) {
			case	zoyo	: direction = zoxo; break;
			case	zpyo	: direction = zpxp; break;
			case	xoyo	: direction = xozp; break;
			case	xpyo	: direction = xpzo; break;
			case	yozo	: direction = yoxp; break;
			case	ypzo	: direction = ypxo; break;
			}
	else if ( compare( sptr, "over" ) ) 
		switch (direction) {
			case	zoyo	: direction = zoyp; break;
			case	zpyo	: direction = zpyp; break;
			case	xoyo	: direction = xoyp; break;
			case	xpyo	: direction = xpyp; break;
			case	yozo	: direction = yozp; break;
			case	ypzo	: direction = ypzp; break;
			}
	else	return( -1 );
	return( direction );
}

PRIVATE	int		direction( handle )
	FILE *		  handle;
{
	char	*	sptr;

	if (!(sptr = keyword( handle )))
		return( -1 );
	else if ( compare( sptr, "forward" ) ) 
		return( zoyo );
	else if ( compare( sptr, "backward" ) ) 
		return( zpyo );
	else if ( compare( sptr, "up" ) ) 
		return( yozo );
	else if ( compare( sptr, "down" ) ) 
		return( ypzo );
	else if ( compare( sptr, "left" ) ) 
		return( xoyo );
	else if ( compare( sptr, "right" ) ) 
		return( xpyo );
	else	return( -1 );
}

PRIVATE	struct camera3d * camera( handle )
	FILE *		  handle;
{
	struct	object3d * optr;
	struct camera3d  * cptr;
	char		 * sptr;
	int		   status;
	int		 punctuation='{';
	int		 c;

	/* Allocate and Initialise 3d Camera Control Node */
	/* ---------------------------------------------- */
	if (!( cptr = allocate_camera() ))
		return( cptr );

	while ((c = notwhite( handle )) == punctuation ) {

		punctuation = ',';

		if ((sptr = keyword( handle )) == (char *) 0 )
			return( drop_camera( cptr ) );
		else if ( compare( sptr, "name" ) ) {
			if ((cptr->name = string( handle )) == (char *) 0)
				return( drop_camera( cptr ) );
			else	continue;
			}
		else if ( compare( sptr, "position" ) ) {
			if ( coordinates( handle, & cptr->position ) )
				return( drop_camera( cptr ) );
			else	continue;
			}
		else if ( compare( sptr, "focus" ) ) {
			if ( vector( handle, & cptr->focus ) )
				return( drop_camera( cptr ) );
			else	continue;
			}
		else if ( compare( sptr, "timer" ) ) {
			cptr->timer = integer(handle);
			continue;
			}
		else if ( compare( sptr, "step" ) ) {
			cptr->step = integer(handle);
			continue;
			}
		else if ( compare( sptr, "direction" ) ) {
			if ((cptr->direction = direction( handle )) == -1)
				return( drop_camera( cptr ) );
			else if (!( set_background( cptr ) ))
				return( drop_camera( cptr ) );
			else	continue;
			}
		else if ( compare( sptr, "rotation" ) ) {
			if ((cptr->direction = rotation( handle, cptr->direction )) == -1)
				return( drop_camera( cptr ) );
			else	continue;
			}
		else if ( compare( sptr, "cube" ) ) {
			if (!(optr = cube( handle )))
				return( drop_camera( cptr ) );
			else	add_cube(cptr,optr);
			continue;
			}

		else	return( drop_camera( cptr ) );


		}

	if ( c != '}' )

		return( drop_camera( cptr ) );

	else	{
		cptr->position.x += correction.x;
		cptr->position.y += correction.y;
		cptr->position.z += correction.z;
		return( cptr );
		}
}

PRIVATE	int		  report_camera(target, cptr, trace )
	FILE		* target;
	struct camera3d * cptr;
	int		  trace;
{
	char	*	sptr;
	struct object3d * optr;

	if (!( cptr ))
		return( 56 );

	if ( trace )
		set_trace_target( target );

	fprintf(target,"\ncamera\t{");

	if ( cptr->name ) 
		fprintf(target, "\n\tname=%s,",cptr->name);

	report_coordinates( target, "\n\tposition", & cptr->position );

	report_vector( target, ",\n\tfocus", & cptr->focus );

	fprintf(target,",\n\ttimer=%u,step=%u",cptr->timer,cptr->step);
	
	switch ( cptr->direction ) {
		case	zoyo:
			sptr = "forward";	break; 
		case	zpyo:
			sptr = "backward";	break; 
		case	yozo:
			sptr = "up";	break; 
		case	ypzo:
			sptr = "down";	break; 
		case	xoyo:
			sptr = "left";	break; 
		case	xpyo:	
			sptr = "right";	break; 
		default	 :
			sptr = "where";	break;
		}

	fprintf(target,",\n\tdirection=%s,\n\trotation=none",sptr);

	if ( cptr->first )
		fprintf(target,",");

	for (	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		report_object(target, optr );
		if ( optr->next )
			fprintf(target,",");
		if ( trace ) {
			fprintf(target,"\ncomment\t{\n");
			calculate3d( optr, & cptr->position, cptr->direction );
			report3d( target, optr );
			fprintf(target,"\t}\n");
			}
		}

	fprintf(target,"}");		
	if ( trace )
		set_trace_target( (FILE *) 0 );
	return(0);
}

PRIVATE	void	motion( cptr, x, y, z )
	struct camera3d * cptr;
	int		x;
	int		y;
	int		z;
{
	int	c;
	do	{
		if (( cptr->position.x + x ) > 5)
			cptr->position.x += x;
		else	return(0);
		if (( cptr->position.y + y ) > 5)
			cptr->position.y += y;
		else	return(0);
		if (( cptr->position.z + z ) > 5)
			cptr->position.z += z;
		else	return(0);
		if ((c = freeze_camera(cptr)) != 0)
			return(c);
		else if ((c = erase_camera( cptr )) != 0)
			return(c);
		else if ((c = calc_camera( cptr )) != 0)
			return(c);
		else if ((c = show_camera( cptr )) != 0)
			return( c );
		else if ((c = thaw_camera(cptr)) != 0)
			return(c);
		else if ( mimo_kbhit() )
			return(0);
		else if ( x != 0 )
			x -= (x==1 ? x : x/2);
		else if ( y != 0 )
			y -= (y==1 ? y : y/2);
		else if ( z != 0 )
			z -= (z==1 ? z : z/2);
		}
	while (( x != 0 ) || ( y != 0 ) || ( z != 0 ));
	return(0);
}

PRIVATE	void	movement( cptr, x, y, z )
	struct camera3d * cptr;
	int		x;
	int		y;
	int		z;
{
	int	c;
	if (( cptr->position.x + x ) > 5)
		cptr->position.x += x;
	if (( cptr->position.y + y ) > 5)
		cptr->position.y += y;
	if (( cptr->position.z + z ) > 5)
		cptr->position.z += z;
	if ((c = freeze_camera(cptr)) != 0)
		return(c);
	else if ((c = erase_camera( cptr )) != 0)
		return(c);
	else if ((c = calc_camera( cptr )) != 0)
		return(c);
	else if ((c = show_camera( cptr )) != 0)
		return( c );
	else if ((c = thaw_camera(cptr)) != 0)
		return(c);
	else	return(0);
}

PRIVATE	int	change_direction( struct camera3d * cptr, int c )
{

	switch ( c ) {
		case	'u':
		case	'U': 	cptr->direction = yozo; 
				set_background(cptr);
				movement( cptr, 0, 0, 0); 	
				mousecurser( MouseYo );
				return(1);
		case	'd':
		case	'D':	cptr->direction = ypzo; 
				set_background(cptr);
				movement( cptr, 0, 0, 0); 	
				mousecurser( MouseYp );
				return(1);
		case	'f':
		case	'F':	cptr->direction = zoyo; 
				set_background(cptr);
				movement( cptr, 0, 0, 0); 	
				mousecurser( MouseZo );
				return(1);
		case	'b':
		case	'B':	cptr->direction = zpyo; 
				set_background(cptr);
				movement( cptr, 0,   0, 0); 
				mousecurser( MouseZp );
				return(1);
		case	'l':
		case	'L':	cptr->direction = xoyo; 
				set_background(cptr);
				movement( cptr, 0, 0,  0); 	
				mousecurser( MouseXo );
				return(1);
		case	'r':
		case	'R':	cptr->direction = xpyo; 
				set_background(cptr);
				movement( cptr, 0,0, 0); 	
				mousecurser( MouseXp ); 
				return(1);

		default	   :
			return(0);
		}
}

PRIVATE	void		action( cptr )
	struct camera3d * cptr;
{
	int	c;
	int	xm=0,ym=0,zm=0;
	while (1) {
		if (!( mimo_kbhit() )) {
			movement(cptr,xm,ym,zm);
			if ((c = wait_camera(cptr)) != 0)
				break;
			else	continue;
			}
		else	{
			switch ((c = mimo_getch())) {
				case	32 : 	movement( cptr,(xm=0),(ym= 0),(zm= 0)); 
						continue;
				case	 8 : 	movement( cptr,(xm= -cptr->step),(ym= 0),(zm= 0)); 
						continue;
				case	 6 : 	movement( cptr,(xm=cptr->step),(ym=0),(zm=0)); 
						continue;
				case	11 : 	movement( cptr,(xm=0),(ym=-cptr->step),(zm=0)); 
						continue;
				case	 5 : 	movement( cptr,(xm=0),(ym=cptr->step),(zm=0)); 
						continue;
				case	 9 : 	movement( cptr,(xm=0),(ym=0),(zm=-cptr->step)); 
						continue;
				case	 0 : 	movement( cptr,(xm=0),(ym=0),(zm=cptr->step)); 
						continue;
				case	 3 : 	movement( cptr,   0, (cptr->step *2), 0); 
						continue; 
				case	18 : 	movement( cptr,   0,-(cptr->step*2), 0); 
						continue; 
				case	27 :
				case	13 :	return;
				case  '+'  : 	cptr->step *= 2; continue;
				case  '-'  : 	cptr->step /= 2; 
						if (!(cptr->step))
							cptr->step++;
						continue;
				default	   :	
					(void) change_direction(cptr,c);
					continue;
				}
			}
		}
	return;
}

PRIVATE	int		  focus_camera( struct camera3d * cptr )
{
	struct object3d * optr;
	int		  c;
	int		is_down=0;
	int		down_col=0;
	int		down_row=0;
	int		at_col=0;
	int		at_row=0;
	int		button=0;
	if (!( cptr ))
		return(55);

	mousecurser( MouseXp );

	while (1)  {


		while ((c = mimo_getch()) == 256) {
			switch ( get_mimo_type() ) {
				case	_MIMO_DOWN 	:
					down_row = get_mimo_row();
					down_col = get_mimo_column();
					is_down  = 1;
					continue;

				case	_MIMO_UP	:
					if (!( is_down ))
						continue;
					else	{
						at_row = get_mimo_row();
						at_col = get_mimo_column();
						if ((button = get_mimo_par()) == _MIMO_LEFT) {
							movement( cptr,
								/* x */
								(down_col - at_col),
								/* y */
								(down_row - at_row),
								/* z */
								0
								);
							}
						else	{
							movement( cptr,
								/* x */
								(down_col - at_col),
								/* y */
								0,
								/* z */
								(down_row - at_row)
								);
							}
						is_down  = 0;
						}
				default			:
					continue;
				}
			break;
			}				

		switch ( c ) {
			case	256: 	continue;

			case	'v' :	if ( verbose )
						verbose = 0;
					else	verbose = 1;
					continue;

			case	'V' :	if ( verbose )
						verbose = 0;
					else	verbose = 2;
					continue;

			case	'A' :
			case	'a' :	action(cptr);
					continue;

			case	 8 : 	movement( cptr, -cptr->step,  0, 0); 
					continue;
			case	 6 : 	movement( cptr,  cptr->step,  0, 0); 
					continue;
			case	11 : 	movement( cptr,   0,-cptr->step, 0); 
					continue;
			case	 5 : 	movement( cptr,   0, cptr->step, 0); 
					continue;
			case	 9 : 	movement( cptr,   0, 0,-cptr->step); 
					continue;
			case	 0 : 	movement( cptr,   0, 0, cptr->step); 
					continue;
			case	 3 : 	movement( cptr,   0, (cptr->step *2), 0); 
					continue; 
			case	18 : 	movement( cptr,   0,-(cptr->step*2), 0); 
					continue; 
			case	13 :
			case	27 : 	return(0);

			case  '<'  :	cptr->focus.x -= cptr->step;
					movement( cptr, 0,   0, 0); 
					continue;
			case  '>'  :	cptr->focus.x += cptr->step;
					movement( cptr, 0,   0, 0); 
					continue;
			case  '*'  :	cptr->focus.y -= cptr->step;
					movement( cptr, 0,   0, 0); 
					continue;
			case  '/'  :	cptr->focus.y += cptr->step;
					movement( cptr, 0,   0, 0); 
					continue;

			case  '+'  : 	cptr->step *= 2; continue;
			case  '-'  : 	cptr->step /= 2; 
					if (!(cptr->step))
						cptr->step++;
					continue;
			default	   :
				(void) change_direction( cptr, c );

			 	continue;				
			}
		}
	return( 0 );
}

#endif	/* _camera_c */

