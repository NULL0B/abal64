#include <stdio.h>

#include "stdpsu.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
#include "threed.h"
#include "scene.h"
#include "texture.h"

#include "anabal.c"

int	graphics=0;
int	err_val=0;
int	movement=0;

/*	-------------------------------------------------	*/
/*	These all belong to the standard SING environment	*/
/*	-------------------------------------------------	*/
#ifdef	UNIX
#include "cico.c"
public  int	verbose=0;
public	char	workbuffer[1024];
#else
#include "console.c"
#include "fnparser.c"
#endif
#include "mouse.c"
#include "stdimage.c"
#include "sysimage.c"

private	struct	coordinate3d	Vektor 	     = { 50, 50, 50 };
extern	struct 	coordinate3d	correction;
extern	struct 	colour3d	facecolour;
extern	struct	background2d 	background;
extern	struct	background2d 	foreground;
extern	struct	background2d 	leftwall;
extern	struct	background2d 	rightwall;
extern	struct	background2d 	ceiling;
extern	struct	background2d 	floor;

#include "object3d.c"
#include "camera3d.c"

private	struct standard_image * camera_text_image( char * nptr, int fg, int bg )
{
	struct 	standard_image * iptr=(struct standard_image *) 0;
	int			 textwidth;
	int			 textheight=0;
	strcpy( workbuffer, nptr );
	textwidth = textsizelen(1,workbuffer,strlen(workbuffer));
	textwidth += (10*4);
	textheight = (16*2);
	if (!( iptr = local_allocate_image(textwidth,textheight,bg,0)))
		return(iptr);
	background_pixel_capture( iptr->storage );
	PixelPutSat(1,1,workbuffer);
	cancel_pixel_capture( iptr->storage );
	return( iptr );
}

private	int	move_Camera(struct camera3d * cptr,int event)
{
	if (!( cptr )) 		return(0);
	switch ( event ) {
			

		case	32	: /* Change movement */
			movement += 1;
			if ( movement > 2 )
				movement = 0;
			return(0);

		case	'+'	:
			switch ( movement ) {
				case	0 :
					Vektor.x *= 2;
					break;
				case	1 :
					Vektor.y *= 2;
					break;
				case	2 :
					Vektor.z *= 2;
					break;
				}
			return(0);

		case	'-'	:		
			switch ( movement ) {
				case	0 :
					Vektor.x /= 2;
					if (!( Vektor.x )) Vektor.x = 1;
					break;
				case	1 :
					Vektor.y /= 2;
					if (!( Vektor.y )) Vektor.y = 1;
					break;
				case	2 :
					Vektor.z /= 2;
					if (!( Vektor.z )) Vektor.z = 1;
					break;
				}
			return(0);

		case	 3	: /* Page Down */
			switch ( movement ) {
				case	0 :
					cptr->position.x += Vektor.x;
					break;

				case	1 :
					cptr->position.y += Vektor.y;
					break;

				case	2 :
					cptr->position.z += Vektor.z;
					break;
				}
			return(1);

		case	0x0012	: /* Page Up   */
			switch ( movement ) {
				case	0 :
					if ( cptr->position.x > Vektor.x )
						cptr->position.x -= Vektor.x;
					break;
				case	1 :
					if ( cptr->position.y > Vektor.y )
						cptr->position.y -= Vektor.y;
					break;
				case	2 :
					if ( cptr->position.z > Vektor.z )
						cptr->position.z -= Vektor.z;
					break;
				}
			return(1);

		}
	return(0);
}

public	void	inhibit_text_cursor()
{
	x_putch(27); x_putch('w');
	return;
}

public	void	activate_text_cursor()
{
	x_putch(27); x_putch('v');
	return;
}

public	int	open_graphics()
{
	set_desktop_name( "Abal 3 : Analyser " );
	set_desktop_icon( "AnAbal3" );
	if ( open_console() == 2 ) {

		initialise_mouse();
		without_mouse_move();
		cicopalette(0,0);
#ifdef	UNIX
		x_event(31);	/* activate alt key operation */
		/* hide the text cursor for now */
		inhibit_text_cursor();
#endif
		return(1);
		}
	else	return(0);
}

public	int	close_graphics(int og)
{
	if ( og ) {
#ifdef	UNIX
		x_event(32);	/* inhibit alt key operation */
		/* show the text cursor for now */
		activate_text_cursor();
#endif
		terminate_mouse();
		}
	close_console();
	return(1);
}

/*	-------------------------------------------------	*/
/*		End of Standard Sing Environment		*/
/*	-------------------------------------------------	*/

/*	struct code_item * resolve_code(struct item_list * lptr, char * codename, int codetype )	*/


int	add_file_objects(
	struct camera3d * cptr,		/* target camera to receive objects */
	int    vposition,
	int    hposition,
	struct item_list * lptr, 	/* list of items to be added	    */
	struct file_item * fptr,
	struct item_list * llptr 	/* list of items to be added	    */
	)
{
	return(0);
}

int	add_code_objects(
	struct camera3d * cptr,		/* target camera to receive objects */
	int    vposition,
	int    hposition,
	struct item_list * lptr, 	/* list of items to be added	    */
	struct code_item * kptr,
	struct item_list * llptr 	/* list of items to be added	    */
	)
{
	int	adjust=0;
	int	vadjust=0;
	struct call_item * xptr;
	struct inclusion_item * iptr;
	struct file_item * fptr;
	struct	item_node * nptr;
	struct code_item * yptr;
	struct object3d  * optr=(struct object3d*) 0;

	printf("add_code_objects for %s\r\n",kptr->name);

	if (( optr = build_cube_at(
		vposition, hposition, cptr->position.z/2,
		100,50,10)) != (struct object3d *) 0) {
		optr->nature = _code_item;
		optr->options= cptr->options;
		optr->payload= kptr;
		optr->image = camera_text_image( kptr->name, 14, 3 );
		add_cube(cptr,optr);
		}

	for ( 	nptr=llptr->first;
		nptr != (struct item_node *) 0;
		nptr = nptr->next ) {
		switch ( nptr->type ) {
			case	_include_item	:
				if (!( iptr = nptr->contents ))
					continue;
				else if ((!(fptr =  iptr->item))
				     &&  (!(fptr =  resolve_file(&files,nptr->name) )))
					continue;
				else	vadjust += add_file_objects(cptr,vposition+vadjust,hposition,lptr,fptr,&fptr->items);
				continue;
			case	_call_item 	:
				if (!( xptr = nptr->contents ))
					continue;
				else if (!( yptr = resolve_code( lptr, xptr->name, xptr->nature ) ))
					continue;
				else if (!(adjust = add_code_objects(cptr,vposition+vadjust,hposition+150,lptr,yptr,&yptr->items)))
					vadjust += 70;
				else	vadjust += adjust;
				continue;
			}
		}
	if (!( vadjust ))
		if ( optr )
			vadjust = 70;

	return(vadjust);
}

int	add_3d_objects(
	struct camera3d * cptr,		/* target camera to receive objects */
	int    hposition,
	struct item_list * lptr 	/* list of items to be added	    */
	)
{
	int	adjustment=0;
	struct	item_node * nptr;
	struct	code_item * kptr;
	struct	object3d  * optr;
	for ( 	nptr=lptr->first;
		nptr != (struct item_node *) 0;
		nptr = nptr->next ) {
		if ( nptr->type != _code_item )
			continue;
		if (!( kptr = nptr->contents ))
			continue;
		else if (( optr = build_cube_at(
				cptr->position.x+150, (hposition+adjustment), cptr->position.z/2,
				100,50,10)) != (struct object3d *) 0) {
			optr->nature = _code_item;
			optr->options= cptr->options;
			optr->payload= kptr;
			optr->image = camera_text_image( kptr->name, 14, 3 );
			add_cube(cptr,optr);
			adjustment += 70;
			}

		}
	return(adjustment);
}

int	add_program_objects(
	struct camera3d * cptr,		/* target camera to receive objects */
	int    hposition,
	struct item_list * lptr 	/* list of items to be added	    */
	)
{
	int	adjustment=0;
	struct	item_node * nptr;
	struct	code_item * kptr;
	struct	object3d  * optr;

	/* attempt to locate segment zero */
	/* ------------------------------ */
	if (!( kptr = resolve_code( lptr, "0", _code_segment ) ))
		return( add_3d_objects( cptr, hposition, lptr ) );
	else	return( add_code_objects( cptr,cptr->position.x+150, hposition, lptr, kptr, &kptr->items ) );
}

struct	camera3d *	build_3d_analysis(struct item_list * lptr)
{
	struct	camera3d 	* cptr;
	struct	object3d 	* optr;
	struct	file_item 	* fptr;
	struct	item_node 	* nptr;
	int			  hposition;
	int			  adjustment;

	if (!( cptr = allocate_camera()))
		return(cptr);

	hposition = cptr->position.y;
	for ( 	nptr=lptr->first;
		nptr != (struct item_node *) 0;
		nptr = nptr->next ) {
		if (!( fptr = nptr->contents ))
			continue;
		else if (fptr->type != 1)
			continue;
		else if (( optr = build_cube_at(
				cptr->position.x, hposition, cptr->position.z/2,
				100,50,10)) != (struct object3d *) 0) {
			optr->nature = _file_item;
			optr->options= cptr->options;
			optr->payload= fptr;
			optr->image = camera_text_image( fptr->name, 15, 2 );
			add_cube(cptr,optr);
			if (!( adjustment = add_program_objects(cptr,hposition,&fptr->items)))
				hposition += 70;
			else	hposition += adjustment;
			}
		else	break;
		}

	for ( 	nptr=lptr->first;
		nptr != (struct item_node *) 0;
		nptr = nptr->next ) {
		if (!( fptr = nptr->contents ))
			continue;
		else if (fptr->type != 2)
			continue;
		else if (( optr = build_cube_at(
				cptr->position.x, hposition, cptr->position.z/2,
				100,50,10)) != (struct object3d *) 0) {
			optr->nature = _file_item;
			optr->options= cptr->options;
			optr->payload= fptr;
			optr->image = camera_text_image( fptr->name, 15, 1 );
			add_cube(cptr,optr);
			if (!( adjustment = add_3d_objects(cptr,hposition,&fptr->items)))
				hposition += 70;
			else	hposition += adjustment;
			}
		else	break;
		}
	return(cptr);

}


private	void	show_3d_camera(struct camera3d * cptr )
{
	if ( freeze_camera(cptr) != 0 ) return;
	if ( erase_camera (cptr) != 0 ) return;
	if ( calc_camera  (cptr) != 0 ) return;
	if ( show_camera  (cptr) != 0 ) return;
	if ( thaw_camera  (cptr) != 0 ) return;
	else				return;
}

private	void	use_graphics(struct item_list * lptr)
{
	int	event;
	struct camera3d * cptr;
	if ( open_graphics() != 0 ) {
		filzone(0,0,hardcolumns(),hardrows(),55);
		cicocolour(16,0);
		cicoatribut(4);
		load_font(1,"/home/abal3/fonts/standard.fmf");
		PixelPutSat(5,5, "Abal 3 Source Analyser : Version 1.0a.0.01 ");
		PixelPutSat(5,21,"Provisoire du 10/09/2003 ");
		PixelPutSat(5,37,"Copyright (c) 2003 Amenesik / Sologic ");
		filzone(5,54,hardcolumns()-10,1,56);
		filzone(5,54,1,(hardrows()-64),56);
		filzone(5,(hardrows()-10),hardcolumns()-10,1,56);
		filzone((hardcolumns()-5),54,1,(hardrows()-64),56);
		if ((cptr = build_3d_analysis(lptr)) != (struct camera3d*) 0) {
			calibrate3d(get_biosmode(), 6,55,(hardcolumns()-6), (char *) 0 );
			prepare_background( cptr->background );
			cptr->position.z = 500;
			show_3d_camera(cptr);
			while ((event = x_getch()) != 27) {
				move_Camera( cptr, event );
				show_3d_camera(cptr);
				}
			}
		else	x_getch();

		close_graphics(1);
		}
	return;
}

int	how(char *nptr)
{
	while (*nptr) {
		switch ( *(nptr++) ) {
			case	'i'	:
			case	'I'	:
				options |= 1;
				continue;

			case	'c'	:
			case	'C'	:
				options |= 2;
				continue;

			case	'g'	:
			case	'G'	:
				graphics=1;
				continue;
			case	's'	:
			case	'S'	:
				set_global_extension(nptr);
				return(0);
			case	'V'	:
			case	'v'	:
				F.verbose = 1;
				continue;
			case	'E'	:
			case	'e'	:
				F.echo = 1;
				continue;
				
			default		:
				return(30);
			}
		}
	return(0);

}



int	analyse(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	status;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-' ) {
			if (!(status = analyseit(aptr)))
				continue;
			else	return( analysed(aptr,status) );
			}
		else if (!(status = how((aptr+1)) ))
			continue;
		else	return( analysed(aptr,status) );
		}
	return(0);
}
		
int	main(int argc, char * argv[] )
{
	int	status;
	int	items=0;
	if ( argc == 1 ) {
		printf("\n   Annie : Source Analyser : Version 1.1a.0.01 ");
		printf("\n   Provisoire du 10/09/2003 ");
		printf("\n   Copyright (c) 2003 Amenesik / Sologic \n");
		return(0);
		}
	else	{
		initialise_analyser();
		status=analyse(argc,argv);
		if (!( graphics )) {
			items = program_list(&files);
			items += module_list(&files);
			if (!( items ))
				print_list(&files,0);
			}
		else	use_graphics(&files);
		terminate_analyser();
		return( status );
		}
}



