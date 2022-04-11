#ifndef	_singapp_c
#define	_singapp_c

#include "threed.h"
#include "singexpo.h"

struct	application_node	{
	struct form_control 	* form;
	struct	object3d 	* cube;
	int			  users;
	int			  state;
	struct application_link * first;
	struct application_link * last;
	struct application_node	* previous;
	struct application_node	* next;
	};

struct	application_link	{
	struct application_node	* link;
	int			  nature;
	struct application_link	* previous;
	struct application_link	* next;
	};

struct	application_control	{
	struct application_node *	FirstNode;
	struct application_node *	LastNode;
	struct camera3d		*	Camera;
	struct coordinate3d	*	Coordinate;
	} ApplicationControl = {
		(struct application_node *) 0,
		(struct application_node *) 0,
		(struct camera3d *) 0,
		(struct coordinate3d *) 0
		};

private	struct	application_node * allocate_application_node( 
	struct form_control * fptr,
	struct	object3d    * optr )
{
	struct	application_node * nptr=(struct application_node *) 0;

	if (!( fptr ))
		return( nptr );
	else if (!( nptr = allocate( sizeof( struct application_node ) ) ))
		return( nptr );
	else	{
		nptr->form = fptr;
		nptr->cube = optr;
		nptr->users=1;
		nptr->state=0;
		nptr->previous = nptr->next = (struct application_node *) 0;
		nptr->first    = nptr->last = (struct application_link *) 0;
		return( nptr );
		}
}

private	struct	application_node * add_application_node( 
	struct form_control * fptr,
	struct	object3d    * optr )
{
	struct	application_node* nptr=(struct	application_node*) 0;
	if (!( nptr = allocate_application_node(fptr,optr) ))
		return( nptr );
	else 	{
		if (!( nptr->previous = ApplicationControl.LastNode ))
			ApplicationControl.FirstNode = nptr;
		else	nptr->previous->next = nptr;
		ApplicationControl.LastNode = nptr;
		return( nptr );
		}
}

private	struct	application_node * locate_application_node(  struct form_control * fptr )
{
	struct	application_node* nptr=(struct	application_node*) 0;
	if (!( fptr )) return( nptr );
	else if (!( fptr->loadname )) return( nptr );
	for (	nptr=ApplicationControl.FirstNode;
		nptr != (struct	application_node* )0;
		nptr = nptr->next ) {
		if (!( nptr->form ))
			continue;
		else if (!( nptr->form->loadname ))
			continue;
		else if (!( strcmp( fptr->loadname, nptr->form->loadname ) )) {
			nptr->users++;
			break;
			}
		}
	return( nptr );
}


public	int	analyse_application_node( struct application_node * nptr )
{
	struct	form_item * iptr;
	struct	form_control * fptr;
	struct	application_link * lptr;
	if (!( nptr ))
		return(0);
	else if (!( nptr->form ))
		return(0);
	else if (!( nptr->form->loadname ))
		return(0);
	for (	iptr = nptr->form->first;
		iptr != (struct form_item *) 0;
		iptr = iptr->next ) {

		if ((!( iptr->Contents.w  ))
		||  (!( iptr->Contents.h  )))
			continue;

		switch ((iptr->Contents.style &_FRAME_TYPE)) {

			case	_DATA_FRAME	:
				if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				&&  ( iptr->Contents.datatype != _WIDGET_CLASS   )
				&&  ( iptr->Contents.datatype != _WIDGET_MODULE  )
				&&  ( iptr->Contents.datatype != _WIDGET_POINTER ))
					continue;
				if (!( fptr = locate_form_control( abal_payload(iptr) )))
					continue;
				else if (!( lptr = allocate( sizeof( struct application_link ) ) ))
					continue;
				else	{
					lptr->next   = lptr->previous = (struct application_link *) 0;
					lptr->nature = iptr->Contents.datatype;
					if (!( lptr->previous = nptr->last ))
						nptr->first = lptr;
					else	nptr->last->next = lptr;
					nptr->last = lptr;
					lptr->link = add_application_node( fptr, (struct object3d *) 0 );
					continue;
					}
				break;

			case	_TAB_FRAME	:
			case	_BUTTON_FRAME	:
				if (( iptr->Contents.datatype != _WIDGET_OVERLAY )
				&&  ( iptr->Contents.datatype != _WIDGET_CHAIN   )
				&&  ( iptr->Contents.datatype != _WIDGET_MODULE  )
				&&  ( iptr->Contents.datatype != _WIDGET_LOADGO  ))
					continue;
				if (!( fptr = locate_form_control( iptr->Contents.format )))
					continue;
				else if (!( lptr = allocate( sizeof( struct application_link ) ) ))
					continue;
				else	{
					lptr->next   = lptr->previous = (struct application_link *) 0;
					lptr->nature = iptr->Contents.datatype;
					if (!( lptr->previous = nptr->last ))
						nptr->first = lptr;
					else	nptr->last->next = lptr;
					nptr->last = lptr;
					lptr->link = add_application_node( fptr, (struct object3d *) 0 );
					continue;
					}

			}

		}
	return(0);
}

public	int	drop_application_node( struct	application_node * nptr )
{
	struct	application_link * lptr;

	if ( nptr ) {
		while ((lptr=nptr->first) != (struct application_link* )0) {
			nptr->first = lptr->next;
			liberate( lptr );
			}
		liberate( nptr );
		}
	return(0);
}

public	int	drop_application_nodes()
{
	struct	application_node* nptr=(struct	application_node*) 0;

	while ((nptr=ApplicationControl.FirstNode) != (struct application_node* )0) {
		ApplicationControl.FirstNode = nptr->next;
		drop_application_node( nptr );
		}

	ApplicationControl.FirstNode = 
	ApplicationControl.LastNode  = (struct application_node *) 0;
	ApplicationControl.Camera    = (struct camera3d *) 0;

	return(0);
}

public	int	organise_application_links( struct application_link* lptr)
{
	struct	object3d * optr;
	struct	coordinate3d Dimension;
	struct	coordinate3d Position;
	int	cubewidth;
	Position.x = ApplicationControl.Coordinate->x;
	Position.y = ApplicationControl.Coordinate->y;
	Position.z = ApplicationControl.Coordinate->z;
	for (	;
		lptr != (struct	application_link* )0;
		lptr = lptr->next ) {
		if (!( lptr->link ))
			continue;
		else if (!( lptr->link->form ))
			continue;
		else if (!( lptr->link->form->loadname ))
			continue;
		else if (!( optr = lptr->link->cube ))
			continue;
		/* printf("\t link = %s \r\n",lptr->link->form->loadname); */
		cubewidth = Dimension.x = (optr->bottomright.x - optr->topleft.x);
		Dimension.y = (optr->bottomright.y - optr->topleft.y);
		Dimension.z = (optr->bottomright.z - optr->topleft.z);
		optr->bottomright.x = Position.x+Dimension.x;
		optr->bottomright.y = Position.y+Dimension.y;
		optr->bottomright.z = Position.z+Dimension.z;
		optr->topleft.x = Position.x;
		optr->topleft.y = Position.y;
		optr->topleft.z = Position.z;
		Position.x += (cubewidth+50);
		lptr->link->state++;
		}
	return( Position.x );
}

public	int	organise_application_nodes()
{
	int	cubeheight;
	int	cubewidth;
	int	leftmargin;
	struct	object3d * optr;
	struct coordinate3d Dimension;
	struct	application_link* lptr=(struct	application_link*) 0;
	struct	application_node* nptr=(struct	application_node*) 0;
	if (!( ApplicationControl.Camera ))
		return;
	for (	nptr=ApplicationControl.FirstNode;
		nptr != (struct	application_node* )0;
		nptr = nptr->next ) {
		if ( nptr->state )
			continue;
		if (!(optr = nptr->cube ))
			continue;
		else if (!( nptr->form ))
			continue;
		leftmargin = ApplicationControl.Coordinate->x;
		Dimension.x = (optr->bottomright.x - optr->topleft.x);
		cubeheight = Dimension.y = (optr->bottomright.y - optr->topleft.y);
		Dimension.z = (optr->bottomright.z - optr->topleft.z);
		optr->bottomright.x = ApplicationControl.Coordinate->x+Dimension.x;
		optr->bottomright.y = ApplicationControl.Coordinate->y+Dimension.y;
		optr->bottomright.z = ApplicationControl.Coordinate->z+Dimension.z;
		optr->topleft.x = ApplicationControl.Coordinate->x;
		optr->topleft.y = ApplicationControl.Coordinate->y;
		optr->topleft.z = ApplicationControl.Coordinate->z;
		/* printf("organise_application_node : form = %s \r\n",nptr->form->loadname); */
		if ( nptr->first ) {
			ApplicationControl.Coordinate->y += (cubeheight+50);
			cubewidth = organise_application_links( nptr->first );
			optr->topleft.x += ((cubewidth - leftmargin)/2); 
			optr->bottomright.x += ((cubewidth - leftmargin)/2); 
			}
		ApplicationControl.Coordinate->y += (cubeheight+50);
		ApplicationControl.Coordinate->x = leftmargin;
		nptr->state++;
		}

	draw_Camera( ApplicationControl.Camera );
	drop_application_nodes();

	return(0);
}

public	int	analyse_application_structure( struct camera3d * cptr, struct coordinate3d * xyzptr )
{
	struct	application_node* nptr;
	struct	object3d 	* optr;
	struct	form_control 	* fptr;

	if (!( cptr ))
		return(0);

	drop_application_nodes();

	ApplicationControl.Camera = cptr;
	ApplicationControl.Coordinate = xyzptr;

	for (	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		
		if ( optr->nature != __3D_FORM )
			continue;

		else if (!(fptr = optr->payload) != (struct form_control *) 0)
			continue;

		else if ((nptr = locate_application_node( fptr )) != (struct application_node *) 0) {
			nptr->cube = optr;
			continue;
			}
		else if (!( nptr = add_application_node( fptr, optr ) ))
			continue;
		else	{
			analyse_application_node( nptr );
			continue;
			}

		}
			
	organise_application_nodes();

	return(1);
}

#endif	/* _singapp_c */
	/* ---------- */

