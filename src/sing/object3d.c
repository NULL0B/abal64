PUBLIC 	struct standard_process * drop_process(
	struct	standard_process * pptr)
{
	if ( pptr->image != (struct standard_image *) 0 ) {
		/* disconnect this to avoid explosion */
		pptr->image->storage = liberate_process_storage( pptr->image->storage );
		pptr->image->rows = pptr->image->columns = 0;
		pptr->mode = -1;
		pptr->serial=0;
		pptr->identity=(int *) 0;
		pptr->gsd = pptr->access=(char *) 0;
		pptr->image = drop_image( pptr->image );
		}
	pptr = liberate( pptr );
	return( (struct standard_process *) 0 );
}

PUBLIC 	struct	object3d * drop_cube( struct object3d * optr )
{	
	if ( optr ) {
		if ( optr->name )
			optr->name = drop_string( optr->name );
		if ( optr->iname )
			optr->iname = drop_string( optr->iname );
		if ( optr->image )
			optr->image = drop_image( optr->image );
		if ( optr->process )
			optr->process = drop_process( optr->process );
		liberate( optr );
		}
	return((struct object3d *) 0);
}

PUBLIC 	struct	object3d * allocate_cube()
{
	struct	object3d * optr=(struct object3d *) 0;

	if ((optr = (struct object3d *) allocate( sizeof( struct object3d ) )) == (struct object3d *) 0)
		return( optr );

	optr->iname  = optr->name = (char *) 0;
	optr->texture= (struct texture *) 0;
	optr->process= (struct standard_process *) 0;
	optr->image= (struct standard_image *) 0;
	optr->next = optr->previous = optr->after = (struct object3d *) 0;

	optr->nature = 0;
	optr->options =0;
	optr->special = 0;
	optr->host              = (void  *) 0;
	optr->payload           = (void  *) 0;
	optr->colours.front	= facecolour.front;
	optr->colours.back	= facecolour.back;
	optr->colours.left	= facecolour.left;
	optr->colours.right	= facecolour.right;
	optr->colours.upper	= facecolour.upper;
	optr->colours.lower	= facecolour.lower;
	optr->colours.shadow	= facecolour.shadow;
	optr->colours.light	= facecolour.light;

	optr->topleft.x = optr->topleft.y = optr->topleft.z = 100;	
	optr->bottomright.x = optr->bottomright.y = optr->bottomright.z = 10;	

	return(optr);
}

PUBLIC 	struct	object3d * build_cube_at(
	int atx, int aty,int atz,
	int dx, int dy, int dz )
{
	struct	object3d * optr=(struct object3d *) 0;
	if (!( optr = allocate_cube() ))
		return( optr );
	else	{
		optr->topleft.x = atx;
		optr->topleft.y = aty;
		optr->topleft.z = atz;
		optr->bottomright.x = optr->topleft.x + dx;
		optr->bottomright.y = optr->topleft.y + dy;
		optr->bottomright.z = optr->topleft.z + dz;
		return(optr);
		}
}

PUBLIC 	struct	object3d * build_cube(int dx, int dy, int dz )
{
	struct	object3d * optr=(struct object3d *) 0;
	if (!( optr = allocate_cube() ))
		return( optr );
	else	{
		optr->bottomright.x = optr->topleft.x + dx;
		optr->bottomright.y = optr->topleft.y + dy;
		optr->bottomright.z = optr->topleft.y + dz;
		return(optr);
		}
}

