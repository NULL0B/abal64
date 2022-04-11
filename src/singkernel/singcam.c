#ifndef	_singcam_c
#define	_singcam_c

#include <stdio.h>
#include <signal.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "genimage.h"
#include "sysimage.h"
#include "stdimage.h"
#include "singlang.h"
#include "singprod.h"
#include "singtree.h" 

#include "singpal.h"
#include "singbar.h"
#include "singmenu.h"
#include "singtool.h"
#include "singtext.h"
#include "singtype.h"
#include "singimg.h"
#include "singclas.h"
#include "singtree.h"
#include "singconf.h"

#include "singcam.h"

#include "singprot.h"

private	char *	PathPrefix[8] = { "en","fr","it","es","de","nl","pt","xx" };

public	struct	model_control ModelControl = { 0,0,0 };

public	struct	application_parameters Application = { 
		0,0,0,
		0,0,0,1,1,
		(char *) 0,
		(char *) 0,
		(char *) 0,
		(char *) 0,
		(char *) 0
				};

public	struct production_manager ProductionManager;

public	struct	document_parameters	Document = {
		(char *) 0,
		(char *) 0,
		(char *) 0,
		(char *) 0,
		(char *) 0,
		(char *) 0,
		0, 0, 0, 0, 0
		};

extern	struct	screen_control	Context;
extern	char 	LaPaterne[];
extern	char	namebuffer[];
extern	char	workbuffer[];
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

#ifdef	_PROTOTYPE_MENUS
#include "menu3d.c"
#endif

public	int	movement=1;
public 	struct	coordinate3d	Vektor 	     = { 50, 50, 50 };
public 	struct	coordinate3d	DefaultSizes = { 100,50,10  };
private	struct	coordinate3d	Cursor	     = { 0,0,0  };
private	struct	coordinate3d	Start	     = { 0,0,0  };
private	struct	coordinate3d	Finish	     = { 0,0,0  };
private	int			IsDown=0;
private	int			DownAtx=0;
private	int			DownAty=0;

public 	FILE *	open_xml_target( char * xmlname, char ** target,char * document, char * dtdname, char * cssname );
private	void	show_CameraItem(struct object3d * optr, int i );
public	void	swap_TreeView();
private	void	drop_CameraPayLoad( struct object3d * optr );
public 	void	load_CameraItem( struct object3d * optr, int a );
public	void	terminate_Camera(struct camera3d * cptr);
public	struct camera3d * CameraOnChangeFocus(struct camera3d * cptr,int reset);
public	int	camera_image_quality()
{
	return(Application.quality );
}

private	void	show_selection(struct camera3d * cptr, int mode)
{
	if (!( cptr ))
		return;
	if (!( cptr->current ))
		return;

	if ( Context.TreeView.style != 0 )
		show_CameraItem( cptr->current, mode );

	sprintf(namebuffer,"%s(%u,%u,%u)",
		cptr->current->name,
		cptr->current->topleft.x,
		cptr->current->topleft.y,
		cptr->current->topleft.z );
	status_message(namebuffer ,2);
	return;
}

private	void	hide_selection(struct camera3d * cptr,int mode)
{
	if ( cptr ) {
		if ( Context.TreeView.style != 0 )
			show_CameraItem( cptr->current, 0 );
		}
	return;
}

public	char	*	image_message( struct bitmap_control *  bptr )
{
	struct 	object3d * optr;
	if ((!( bptr ))
	||  (!( optr = bptr->host )))
		return("noname");
	else	return( optr->name );
}

public	int		compare_treeview_text ( struct source_control * sptr, char * nptr )
{
	struct 	object3d * optr;
	if (!( sptr ))
		return(0);
	else if (!( nptr ))
		return(0);
	else if (!( optr = sptr->host ))
		return(0);
	else	{
		if ( wildcomp( optr->name, nptr ) )
			return(0);
		else	return(1);
		}
}

public	int		compare_treeview_image( struct bitmap_control * sptr, char * nptr )
{
	struct 	object3d * optr;
	if (!( sptr ))
		return(0);
	else if (!( nptr ))
		return(0);
	else if (!( optr = sptr->host ))
		return(0);
	else	{
		if ( wildcomp( optr->name, nptr ) )
			return(0);
		else	return(1);
		}
}

public	char	*	text_message( struct source_control * sptr )
{
	struct 	object3d * optr;
	if ((!( sptr ))
	||  (!( optr = sptr->host )))
		return("noname");
	else	return( optr->name );
}

public	char	*	project_message( struct camera3d * cptr )
{
	if ((!( cptr ))
	||  (!( cptr->name )))
		return("noname");
	else	return(cptr->name);
}

public 	int	string_compare(char * aptr, char * bptr )
{
	if (!( aptr )) {
		if (!( bptr ))
			return(1);
		else	return(0);
		}
	else if (!( bptr ))
		return(0);
	while (( *aptr != 0 ) && ( *bptr != 0 ))
		if ( *(aptr++) != *(bptr++) )
			return(0);

	if ( *aptr != *bptr )
		return(0);
	else	return(1);
}

public 	int	upper_compare(char * aptr, char * bptr )
{
	int	a;
	int	b;
	if (!( aptr )) {
		if (!( bptr ))
			return(1);
		else	return(0);
		}
	else if (!( bptr ))
		return(0);
	while (( *aptr != 0 ) && ( *bptr != 0 )) {
		if (((a = *(aptr++)) >= 'a')
		&&  (a <= 'z')) { a -= ('a' - 'A'); }
		if (((b = *(bptr++)) >= 'a')
		&&  (b <= 'z')) { b -= ('a' - 'A'); }
		if ( a != b )
			return(0);
		}
	if ( *aptr != *bptr )
		return(0);
	else	return(1);
}

private	void	release_document_parameters()
{
	if ( Document.title ) 
		Document.title = liberate( Document.title );
	if ( Document.screenstyle ) 
		Document.screenstyle = liberate( Document.screenstyle );
	if ( Document.printstyle ) 
		Document.printstyle = liberate( Document.printstyle );
	if ( Document.logo ) 
		Document.logo = liberate( Document.logo );
	if ( Document.footer ) 
		Document.footer = liberate( Document.footer );
	if ( Document.pathroot ) 
		Document.pathroot = liberate( Document.pathroot );
	return;
}

private	void	autosize_Cube(struct object3d * optr )
{
	if (( optr->image != (struct standard_image *) 0)
	&&  ( optr->image->rows != 0 )
	&&  ( optr->image->columns != 0 )) {
		optr->bottomright.x = (optr->topleft.x + optr->image->columns);
		optr->bottomright.y = (optr->topleft.y + optr->image->rows);
		}
	return;
}

static	char 	cubeclass[64];

private	char *	resolve_cube_class(struct object3d * optr )
{
	if ( optr->nature == __3D_FORM )
		strcpy( cubeclass,"form");
#ifdef	_PROTOTYPE_MENUS
	else if ( optr->nature == __3D_MENU )
		strcpy( cubeclass,"menu");
#endif
#ifdef	_PROTOTYPE_CLASS
	else if ( optr->nature == __3D_CLASS )
		strcpy( cubeclass,"class");
#endif
	else if ( optr->nature == __3D_IMAGE )
		strcpy( cubeclass,"image");
	else if ( optr->nature == __3D_TEXT )
		strcpy( cubeclass,"text");
	else	strcpy( cubeclass," ");
	return( cubeclass );
}

private	char *	resolve_form_class(struct form_control * fptr )
{
	switch ( fptr->formflags & _FORM_TYPE_FLAGS ) {
		case	_FORM_TYPE_DIALOG	:
			strcpy( cubeclass,"dialog box");
			return( cubeclass );
		case	_FORM_TYPE_EVENT 	:
			strcpy( cubeclass,"event document");
			return( cubeclass );
		case	_FORM_TYPE_SCROLL	:
			strcpy( cubeclass,"scrolling printout");
			return( cubeclass );
		case	_FORM_TYPE_PAGE  	:
			strcpy( cubeclass,"draft document");
			return( cubeclass );
		default		:
			strcpy( cubeclass," ");
			return( cubeclass );
		}

}

public	char *	image_extension( int options )
{
	if (!( options & _CAMERA_IMAGE_TYPE )) {
		if (!( options & _INHIBIT_GIF ))
			return( GIF_EXTENSION );
		else	return( BMP_EXTENSION );
		}
	else	{
		switch ( (options & 0x0C0) >> 6 )  {
			case	0	: return( BMP_EXTENSION );
			case	1	: return( GIF_EXTENSION );
			case	2	: return( JPG_EXTENSION );
			case	3	: return( PNG_EXTENSION );
			default		: return( ".img" );
			}
		}
}

public	int   	image_nature( int options )
{
	if (!( options & _CAMERA_IMAGE_TYPE )) {
		if (!( options & _INHIBIT_GIF ))
			return( 1 );
		else	return( 0 );
		}
	else	return(((options & 0x0C0) >> 6));
}

private	struct standard_image * load_form_image( char * nptr, int options )
{
	struct	standard_image * iptr=(struct standard_image*) 0;
	char *	xptr;
	if (!( nptr = allocate_string( nptr ) )) { 
		allocate_failure();
		return( iptr );
		}

	xptr = image_extension( options );

	if (!( nptr = enforce_extension( nptr, xptr ) )) {
		allocate_failure();
		return( iptr );
		}
	iptr = local_image_loader( nptr );
	liberate( nptr );
	return( iptr );

}

private	struct bitmap_control * drop_Bitmap( struct bitmap_control * bptr)
{
	if ( bptr ) {
		remove_treenode( bptr->treenode );
		if ( bptr->treenode ) bptr->treenode = liberate_for_treeview( bptr->treenode );
		if ( bptr->payload  ) local_drop_image( bptr->payload );
		liberate( bptr );
		}
	return( (struct bitmap_control *) 0 );
}

public	struct bitmap_control * allocate_Bitmap()
{
	struct bitmap_control * iptr;
	if (!( iptr = allocate( sizeof( struct bitmap_control ) ) ))
		return(iptr);
	else	{
		iptr->savestamp = iptr->loadstamp = time((long*)0);
		iptr->payload 	= (struct standard_image *) 0;
		iptr->treenode 	= (void *) 0;
		iptr->host	= (void *) 0;
		if (!( iptr->treenode = allocate_for_treeview() )) 
			return( drop_Bitmap( iptr ) );
		else	{
			connect_treenode( iptr->treenode,TREE_IMAGE,iptr);
			return( iptr );
			}
		}
}

private	struct source_control * drop_Source( struct source_control * sptr)
{
	if ( sptr ) {
		remove_treenode( sptr->treenode );
		if ( sptr->treenode ) sptr->treenode = liberate_for_treeview( sptr->treenode );
		liberate( sptr );
		}
	return( (struct source_control *) 0 );
}

public	struct source_control * allocate_Source()
{
	struct source_control * sptr;
	if (!( sptr = allocate( sizeof( struct source_control ) ) ))
		return(sptr);
	else	{
		sptr->savestamp = sptr->loadstamp = time((long*)0);
		sptr->payload 	= (void *) 0;
		sptr->treenode 	= (void *) 0;
		sptr->host	= (void *) 0;
		if (!( sptr->treenode = allocate_for_treeview() )) 
			return( drop_Source( sptr ) );
		else	{
			connect_treenode( sptr->treenode,TREE_TEXT,sptr);
			return( sptr );
			}
		}
}

private	struct bitmap_control * load_Bitmap( char * nptr, int options )
{
	struct bitmap_control  * bptr;
	if (!( bptr = allocate_Bitmap()))
		return( bptr );
	else	{
		bptr->payload = local_image_loader( nptr );
		return( bptr );
		}
}

private	struct source_control * load_Source( char * nptr )
{
	struct source_control  * sptr;
	if (!( sptr = allocate_Source()))
		return( sptr );
	else	{
		sptr->payload = (void *) 0;
		return( sptr );
		}
}


private	int	edit_Cube(struct object3d * optr )
{
	int	status;
	char *	oldname;
	void *  pptr;
	struct	coordinate3d	Dimension;
	char *	kptr;
	int	autosize;
	int	inhibitgif;

	if (!( optr ))
		return(27);
	else if (!(optr->name))
		oldname = allocate_string("object");
	else	oldname = allocate_string(optr->name);

	kptr = resolve_cube_class( optr );

	Dimension.x = (optr->bottomright.x-optr->topleft.x);
	Dimension.y = (optr->bottomright.y-optr->topleft.y);
	Dimension.z = (optr->bottomright.z-optr->topleft.z);

	if ( optr->options & _CAMERA_AUTOSIZE )
		autosize   = 1;
	else	autosize   = 0;

	inhibitgif = image_nature( optr->options );

	if ((status  = accept_cube_properties(
		&optr->name,
		&optr->topleft.x,
		&optr->topleft.y,
		&optr->topleft.z,
		&Dimension.x,
		&Dimension.y,
		&Dimension.z,
		kptr,
		&autosize,
		&inhibitgif,

		/* Gestion des couleurs des faces */
		/* ------------------------------ */
		&optr->colours.back,
		&optr->colours.front,
		&optr->colours.left,
		&optr->colours.right,
		&optr->colours.upper,
		&optr->colours.lower,
		&optr->colours.light,
		&optr->colours.shadow

		)) != 27) {

		if ( autosize )
			optr->options |= _CAMERA_AUTOSIZE;
		else	optr->options &= ~_CAMERA_AUTOSIZE;

		optr->options &= 0xFF1F;
		optr->options |= _CAMERA_IMAGE_TYPE;
		optr->options |= ((inhibitgif << 6) & 0x00C0);
		optr->bottomright.x = (optr->topleft.x + Dimension.x);
		optr->bottomright.y = (optr->topleft.y + Dimension.y);
		optr->bottomright.z = (optr->topleft.z + Dimension.z);
		if (!( string_compare( oldname, optr->name ))) {
			drop_CameraPayLoad( optr );
			load_CameraItem( optr, 0 );
			}
		if ( optr->options & _CAMERA_AUTOSIZE )
			autosize_Cube( optr );
		}
	oldname = liberate( oldname );
	return(status);
}

private	int	edit_CameraItem(struct camera3d * cptr)
{
	struct	object3d * optr;
	if (!( cptr ))
		return(0);
	else if (!( optr = cptr->current))	
		return(0);
	else	return( edit_Cube( cptr->current ) );
}

private	void	show_CameraItem( struct object3d * optr, int state )
{
	struct	source_control 	* sptr;
	struct	bitmap_control 	* bptr;
	struct	form_control 	* fptr;
	struct	treeview  	* tptr;
	struct	menu_control 	* mptr;
	struct  standard_class 	* cptr;
	if (!( optr ))	return;
	switch ( optr->nature ) {

		case	__3D_IMAGE	:
			if (!( bptr = optr->payload))
				return;
			else if (!( tptr = bptr->treenode ))
				return;
			else	break;

		case	__3D_TEXT	:
			if (!( sptr = optr->payload))
				return;
			else if (!( tptr = sptr->treenode ))
				return;
			else	break;

		case	__3D_FORM	:
			if (!( fptr = optr->payload))
				return;
			else if (!( tptr = fptr->treenode ))
				return;
			else	break;

#ifdef	_PROTOTYPE_MENUS
		case	__3D_MENU	: 
			if (!( fptr = optr->payload))
				return;
			else if (!( tptr = fptr->treenode ))
				return;
			else	break;
#endif
#ifdef	_PROTOTYPE_CLASS
		case	__3D_CLASS	: 
			if (!( fptr = optr->payload))
				return;
			else if (!( tptr = fptr->treenode ))
				return;
			else	break;
#endif
		default			: output_string("item "); break;
		}

	focus_treenode( tptr, state );
	return;
}

public	void	disconnect_treeview( struct treeview * tptr )
{
	struct	bitmap_control 	* bptr;
	struct	form_control 	* fptr;
	struct	menu_control 	* mptr;
	struct  standard_class 	* cptr;
	struct 	form_item 	* iptr;
	struct	object3d	* optr;

	if (!( tptr->payload ))
		return;

	switch ( tptr->nature ) {

		case	TREE_PROJECT	:
			tptr->payload = (void *) 0;
			tptr->nature  = TREE_NULL;
			return;

		case	TREE_IMAGE	:
			if (!( bptr = tptr->payload))
				return;
			else	{
				bptr->treenode = (struct treeview*)0;
				return;
				}
		case	TREE_TEXT	:
			if (!( optr = tptr->payload))
				return;
			else	{
				optr->payload = (struct treeview*)0;
				return;
				}
		case	TREE_FORM	:
			if (!( fptr = tptr->payload))
				return;
			else	{
				fptr->treenode = (struct treeview*)0;
				return;
				}
#ifdef	_PROTOTYPE_MENUS
		case	TREE_MENU	: 
			if (!( mptr = tptr->payload))
				return;
			else	{
				mptr->treenode = (struct treeview*)0;
				return;
				}
#endif
#ifdef	_PROTOTYPE_CLASS
		case	TREE_CLASS	: 
			if (!( cptr = tptr->payload))
				return;
			else	{
				cptr->treenode = (struct treeview*)0;
				return;
				}
#endif
		case	TREE_WIDGET : 
			if (!( iptr = tptr->payload))
				return;
			else	{
				iptr->treenode = (struct treeview*)0;
				return;
				}

		default			: return;
		}

	
}

private	int	use_CameraItem( struct object3d * optr, int event )
{
	struct	treeview  * tptr;
	struct	form_control * fptr;
	struct	menu_control * mptr;
	struct  standard_class * cptr;

	switch ( optr->nature ) {
		case	__3D_FORM	:
			if (!( fptr = optr->payload))
				return(0);
			else if (!( tptr = fptr->treenode ))
				return(0);
			else	break;

#ifdef	_PROTOTYPE_MENUS
		case	__3D_MENU	: 
			if (!( fptr = optr->payload))
				return(0);
			else if (!( tptr = fptr->treenode ))
				return(0);
			else	break;
#endif
#ifdef	_PROTOTYPE_CLASS
		case	__3D_CLASS	: 
			if (!( fptr = optr->payload))
				return(0);
			else if (!( tptr = fptr->treenode ))
				return(0);
			else	break;
#endif
		default			: return(0);
		}

	
	if ( event == '+' ) {
		if (!( tptr->state & _TREE_OPEN )) {
			tptr->state |= _TREE_OPEN;
			return(1);
			}
		else	return(0);
		}	
	else if ( event == '-' ) {
		if ( tptr->state & _TREE_OPEN ) {
			tptr->state &= ~_TREE_OPEN;
			return(1);
			}
		else	return(0);
		}	
	else	return(0);
}

public 	void	show_CameraItems(struct camera3d * cptr)
{
	int	atrow=0;
	draw_tree_view(Context.Tree,0,&atrow);
	return;
}

public	void	draw_CameraItems(struct camera3d* cptr)
{
	if ( Context.DeskTop.style == _SCROLL_FRAME ) 
		activate_DeskTop( _OUTSET_FRAME );

	if ( freeze_camera(cptr) != 0 ) return;
	if ( erase_camera (cptr) != 0 ) return;
	if ( calc_camera  (cptr) != 0 ) return;
	if ( show_camera  (cptr) != 0 ) return;
	if ( thaw_camera  (cptr) != 0 ) return;
	sprintf(namebuffer,"%u,%u,%u",cptr->position.x,cptr->position.y,cptr->position.z);
	status_message(namebuffer,1);
	return;
}

public 	void	draw_Camera(struct camera3d * cptr)
{
	if (!( cptr )) return;
	draw_CameraItems(cptr);
	return;
}

private	void	check_Camera_background(struct camera3d * cptr)
{
	char	*	nptr;

	if ( cptr->background->image != (struct standard_image *) 0) {
		local_drop_image( cptr->background->image );
		cptr->background->image = (struct standard_image *) 0;
		}

	if ((nptr = cptr->background->iname) != (char *) 0) {
		cptr->background->image = local_image_loader( nptr );
		}

	prepare_background( cptr->background );
	return;
}

public	char *	project_configuration()
{
	if (!( Context.Camera ))
		return( configuration_rootname() );
	else	return( Context.Camera->configuration );
}

private	int	edit_Camera(struct camera3d * cptr)
{
	int	optautosize=0;
	int	optionf=0;
	int	optioni=0;
	int	align=0;
	int	i;

	if (!( cptr )) return(0);

	if ( cptr->options & _CAMERA_AUTOSIZE )
		optautosize = 1;
	else	optautosize = 0;

	if ( cptr->options & _CAMERA_FORMS  )
		optionf = 1;
	else	optionf = 0;

	if ( cptr->options & _CAMERA_IMAGES )
		optioni = 1;
	else	optioni = 0;

	i = cptr->background->style;

	if ((i & _REPEAT_X ) ||  (i & _REPEAT_Y ))
		align =_I_TILE;

	else if ( i & _MAKE_FIT )
		align =_I_MAKEFIT;

	else if ( i & _ALIGN_LEFT ) {
		if ( i & _ALIGN_RIGHT )
			align = _A_CENTER;
		else	align = _A_LEFT;
		}

	else if ( i & _ALIGN_RIGHT )
		align = _A_RIGHT;

	else	align = _A_NONE;

	if ( accept_camera_properties(
		&cptr->name,
		&cptr->position.x,
		&cptr->position.y,
		&cptr->position.z,
		&cptr->focus.x,
		&cptr->focus.y,
		&cptr->direction,
		&cptr->configuration,
		&Application.databasename,
		&cptr->step,
		&DefaultSizes.x,
		&DefaultSizes.y,
		&DefaultSizes.z,
		&Vektor.x,
		&Vektor.y,
		&Vektor.z,
		&Application.imagetype,
		&optautosize,
		&optionf,&optioni,
		&cptr->background->iname,
		&Application.palettename,
		&align,
		&cptr->background->colour,
		&Application.quality
		) != 27 ) {
		if ( optautosize )
			cptr->options |= _CAMERA_AUTOSIZE;
		else	cptr->options &= ~_CAMERA_AUTOSIZE;
		if ( optionf )
			cptr->options |= _CAMERA_FORMS;
		else	cptr->options &= ~_CAMERA_FORMS;
		if ( optioni )
			cptr->options |= _CAMERA_IMAGES;
		else	cptr->options &= ~_CAMERA_IMAGES;
		if ( Application.palettename )
			visual_palette(Application.palettename,strlen(Application.palettename));

		switch ( align ) {
			case	_A_LEFT	: 
				cptr->background->style = (_ALIGN_LEFT | _ALIGN_TOP);
				break;
			case	_A_RIGHT	: 
				cptr->background->style = (_ALIGN_RIGHT | _ALIGN_BOTTOM);
				break;
			case	_A_NONE	: 
			case	_A_CENTER	:
				cptr->background->style = 0;
				break;
			case	_I_TILE		:
				cptr->background->style = (_REPEAT_X | _REPEAT_Y);
				break;
			case	_I_MAKEFIT	:
			case	_I_BESTFIT	:
				cptr->background->style = _MAKE_FIT;
				break;
			default			:
				cptr->background->style = 0;
			}
		check_Camera_background(cptr);
		}

	return(1);
}

private	void	view_Camera(struct camera3d * cptr, int sens)
{
	int	holder;
	if (!( cptr )) return;

	holder = cptr->direction;

	switch ( sens ) {
		case	'u':
		case	'U': 	cptr->direction = yozo; break;
		case	'd':
		case	'D':	cptr->direction = ypzo; break;
		case	'f':
		case	'F':	cptr->direction = zoyo; break;
		case	'b':
		case	'B':	cptr->direction = zpyo; break;
		case	'l':
		case	'L':	cptr->direction = xoyo; break;
		case	'r':
		case	'R':	cptr->direction = xpyo; break;
		}
	if ( holder != cptr->direction ) {
		draw_DeskTop();
		}
	return;

}

public	void	calibrate_desktop(struct camera3d * cptr)
{
	connect_3dscroll( &cptr->position,inner_height(), 32000 );
	(void) calibrate3d( get_biosmode(), get_leftmargin(), get_topmargin(), get_rightmargin(), (char *) 0 );
	if ( cptr )
		prepare_background( cptr->background );
	return;
}

public	struct camera3d * initialise_Camera()
{
	struct camera3d * cptr;
	if (!(cptr = allocate_camera()))
		return(cptr);
	else if (!(cptr->treenode = allocate_for_treeview())) {
		terminate_Camera( cptr );
		return((struct camera3d*)0);
		}
	else	{
		cptr->treenode->state |= _TREE_OPEN;
		cptr->options = ( _CAMERA_AUTOSIZE | _CAMERA_FORMS | _CAMERA_IMAGES );
		connect_treenode(cptr->treenode,TREE_PROJECT,cptr);
		add_treenode( Context.Tree, cptr->treenode );
		cptr->host = Context.Tree;
		initialise_tree_manager();
		calibrate_desktop(cptr);
		return(cptr);
		}
}


private	void	new_camera_Form(struct object3d * optr)
{
	struct form_control * fptr;
	if (( fptr = allocate_Form( optr->name )) != (struct form_control *) 0) {
		fptr->host    = optr;
		optr->payload = fptr; 
		}	
	return;
}

private	struct standard_image * build_bitmap_image( struct object3d * optr )
{
	int	iwidth=0;
	int	iheight=0;
	if (!( optr ))
		return( (struct standard_image * ) 0);
	if (!( iwidth = (optr->bottomright.x - optr->topleft.x)))
		iwidth = 100;
	if (!( iheight = (optr->bottomright.y - optr->topleft.y)))
		iheight = 100;
	return( local_allocate_image( iwidth, iheight, Context.background,0 ) );
}

private	void	new_camera_Bitmap(struct object3d * optr)
{
	struct bitmap_control * bptr;
	if (( bptr = allocate_Bitmap()) != (struct bitmap_control *) 0) {
		bptr->host = optr;
		optr->payload = bptr; 
		}
	return;
}

private	void	new_camera_Source(struct object3d * optr)
{
	struct source_control * sptr;
	if (( sptr = allocate_Source()) != (struct source_control *) 0) {
		sptr->host = optr;
		optr->payload = sptr; 
		}
	return;
}

#ifdef	PROTOTYPE_CLASS
private	void	new_camera_Class(struct object3d * optr)
{
	struct standard_class * cptr;
	if ((cptr = allocate_Class( optr->name )) !=(struct standard_class *) 0) {
		cptr->host = optr;
		optr->payload = cptr; 
		}	
	return;
}
#endif

#ifdef	_PROTOTYPE_MENUS
private	void	new_camera_Menu(struct object3d * optr)
{
	struct menu_control * mptr;
	if ((mptr = allocate_Menu( optr->name )) != (struct menu_control *) 0) {
		mptr->host = optr;
		optr->payload = mptr; 
		}	
	return;
}
#endif

public 	int 	zoom_CameraItem(struct camera3d * cptr)
{
	int	status=0;
	char	*	nptr;
	char 	*	xptr;
	if (!( cptr ))
		return(0);
	else if (!( cptr->current ))
		return(0);
	else if (!( cptr->current->name ))
		return(0);
	else if (!( cptr->current->image ))
		return(0);
	else if (!( nptr = allocate_string( cptr->current->name )))
		return(0);
	xptr = image_extension( cptr->current->options );
	nptr = enforce_extension(nptr,xptr);

	if (!( nptr ))	return(0);

	status = edit_Image(nptr, &cptr->current->image );

	nptr = liberate( nptr );
	return( status );
}

public 	void	camera_ItemFile(char ** sptr)
{
	if (!( Context.Camera ))
		return;
	else if (!( Context.Camera->current ))
		return;
	else	{
		*sptr = Context.Camera->current->name;
		return;
		}
}

public 	int 	text_CameraItem(struct camera3d * kptr)
{
	struct  bitmap_control 	* bptr;
	struct	form_control 	* fptr;
	struct	menu_control 	* mptr;
	struct  standard_class 	* cptr;
	int	status=0;
	char	*	nptr;
	if (!( kptr ))
		return(0);
	else if (!( kptr->current ))
		return(0);
	else	{
		switch ( kptr->current->nature ) {
			case	__3D_FORM	:
				if (!( fptr = kptr->current->payload ))
					break;
				else	{
					status = use_editor( fptr->prodname,0 );
					break;
					}

			case	__3D_IMAGE	:
				break;

			case	__3D_TEXT	:
				status = use_editor( kptr->current->name,0 );
				break;

#ifdef	_PROTOTYPE_MENUS
			case	__3D_MENU	:
				if (!( mptr = kptr->current->payload ))
					break;
				else	{
					status = use_editor( mptr->prodname,0 );
					break;
					}
#endif
#ifdef	_PROTOTYPE_CLASS
			case	__3D_CLASS	:
				if (!( cptr = kptr->current->payload ))
					break;
				else	{
					status = use_editor( cptr->prodname,0 );
					break;
					}
#endif
			}
		}
	return( status );
}


private	int 	 form_CameraItem(struct camera3d * kptr,int mode)
{
	struct	object3d	* optr;
	struct  bitmap_control 	* bptr;
	struct	form_control 	* fptr;
	struct	menu_control 	* mptr;
	struct  standard_class 	* cptr;
	int	event=0;
	if (!( kptr ))
		return(0);
	else if (!( optr = kptr->current ))
		return(0);
	else 	{

		switch ( optr->nature ) {
			case	__3D_FORM	:
				if (!( optr->payload ))
					new_camera_Form(optr);

				event = FormEditorOnExec((struct form_control **)&optr->payload);

				if (( fptr = optr->payload ) != (struct form_control *) 0 )
					optr->image = fptr->image;

				if ( optr->options )
					autosize_Cube( optr );
				break;

			case	__3D_IMAGE	:
				if (!( bptr = optr->payload ))
					break;

				event = edit_Image( optr->name, &bptr->payload );

				if ( bptr->payload )
					optr->image = bptr->payload;
				else	optr->image = (struct standard_image * )0;
				if ( optr->options )
					autosize_Cube( optr );
				break;

			case	__3D_TEXT	:

				event = use_editor( optr->name,0 );

				break;

#ifdef	_PROTOTYPE_MENUS
			case	__3D_MENU	:
				if (!( optr->payload ))
					new_camera_Menu(optr);

				event = edit_Menu(&optr->payload,0);

				if (( mptr = optr->payload ) != (struct menu_control *) 0 )
					optr->image = mptr->image;

				if ( optr->options )
					autosize_Cube( optr );
				break;
#endif
#ifdef	_PROTOTYPE_CLASS
			case	__3D_CLASS	:
				if (!( optr->payload ))
					new_camera_Class(optr);

				event = edit_Class(&optr->payload,mode);

				if (( cptr = (struct standard_class *) optr->payload ) != (struct standard_class *) 0 )
					optr->image = cptr->image;

				if ( optr->options )
					autosize_Cube( optr );
				break;
#endif

			}
		return(event);
		}
}


private	int	drag_Camera(struct camera3d * cptr, int tox, int toy, int frx, int fry, int button)
{
	if (!( cptr ))
 		return(256);
	switch ( cptr->direction ) {
		case yozo	: /* UP */
			if ( button == _MIMO_LEFT ) {
				cptr->position.x += (frx-tox);
				cptr->position.z += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_RIGHT ) {
				cptr->position.y += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_WHEELUP ) {
				cptr->position.y += Vektor.y;
				return(257 );
				}
			else if ( button == _MIMO_WHEELDOWN ) {
				if ( cptr->position.y > Vektor.y )
					cptr->position.y -= Vektor.y;
				return(257 );
				}
			else	return(256);
		case ypzo	: /* DOWN */
			if ( button == _MIMO_LEFT ) {
				cptr->position.x += (frx-tox);
				cptr->position.z -= (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_RIGHT ) {
				if ( cptr->position.y > (fry-toy))
					cptr->position.y -= (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_WHEELUP ) {
				if ( cptr->position.y > Vektor.y )
					cptr->position.y -= Vektor.y;
				return(257 );
				}
			else if ( button == _MIMO_WHEELDOWN ) {
				cptr->position.y += Vektor.y;
				return(257 );
				}
			else	return(256);

		case zoyo	: /* FWD */
			if ( button == _MIMO_LEFT ) {
				cptr->position.x += (frx-tox);
				cptr->position.y += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_RIGHT ) {
				cptr->position.z += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_WHEELUP ) {
				cptr->position.z += Vektor.z;
				return(257 );
				}
			else if ( button == _MIMO_WHEELDOWN ) {
				if ( cptr->position.z > Vektor.z )
					cptr->position.z -= Vektor.z;
				return(257 );
				}
			else	return(256);

		case zpyo	: /* BACK */
			if ( button == _MIMO_LEFT ) {
				cptr->position.x -= (frx-tox);
				cptr->position.y += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_RIGHT ) {
				if ( cptr->position.z > (fry-toy))
					cptr->position.z -= (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_WHEELUP ) {
				if ( cptr->position.z > Vektor.z )
					cptr->position.z -= Vektor.z;
				return(257 );
				}
			else if ( button == _MIMO_WHEELDOWN ) {
				cptr->position.z += Vektor.z;
				return(257 );
				}
			else	return(256);
		case xoyo	: /* LEFT */
			if ( button == _MIMO_LEFT ) {
				cptr->position.z += (frx-tox);
				cptr->position.y += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_RIGHT ) {
				cptr->position.y += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_WHEELUP ) {
				cptr->position.y += Vektor.y;
				return(257 );
				}
			else if ( button == _MIMO_WHEELDOWN ) {
				if ( cptr->position.y > Vektor.y )
					cptr->position.y -= Vektor.y;
				return(257 );
				}
			else	return(256);



		case xpyo	: /*RIGHT */
			if ( button == _MIMO_LEFT ) {
				cptr->position.z -= (frx-tox);
				cptr->position.y += (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_RIGHT ) {
				cptr->position.y -= (fry-toy);
				return(257);
				}
			else if ( button == _MIMO_WHEELDOWN ) {
				cptr->position.y += Vektor.y;
				return(257 );
				}
			else if ( button == _MIMO_WHEELUP ) {
				if ( cptr->position.y > Vektor.y )
					cptr->position.y -= Vektor.y;
				return(257 );
				}
			else	return(256);
		}

}

public	int	get_camera_position_x()	{ if ( Context.Camera ) return( Context.Camera->position.x ); else return( 0 ); }
public	int	get_camera_position_y()	{ if ( Context.Camera ) return( Context.Camera->position.y ); else return( 0 ); }
public	int	get_camera_position_z()	{ if ( Context.Camera ) return( Context.Camera->position.z ); else return( 0 ); }


public	void	adjust_3d_step( int which, int mode, int * rptr )
{
	int	v;
	if (!( mode )) {
		switch ( which ) {
			case	1 :
				*rptr = Vektor.x;
				return;
			case	2 :
				*rptr = Vektor.y;
				return;
			case	3 :
				*rptr = Vektor.z;
				return;
			}
		}
	else if ( mode == 1 ) {
		switch ( which ) {
			case	1 :
				Vektor.x *= 2;
				*rptr = Vektor.x;
				return;
			case	2 :
				Vektor.y *= 2;
				*rptr = Vektor.y;
				return;
			case	3 :
				Vektor.z *= 2;
				*rptr = Vektor.z;
				return;
			}
		}
	else	{
		switch ( which ) {
			case	1 :
				Vektor.x /= 2;
				if (!( Vektor.x )) Vektor.x = 1;
				*rptr = Vektor.x;
				return;
			case	2 :
				Vektor.y /= 2;
				if (!( Vektor.y )) Vektor.y = 1;
				*rptr = Vektor.y;
				return;
			case	3 :
				Vektor.z /= 2;
				if (!( Vektor.z )) Vektor.z = 1;
				*rptr = Vektor.z;
				return;
			}

		}
	return;
}

public	int	move_3d_camera( int type, int * xptr, int * yptr, int * zptr )
{
	struct	camera3d * cptr;
	if (!( cptr = Context.Camera ))
		return(0);
	switch ( type ) {
		case	2 :
			cptr->position.x += Vektor.x;
			break;
		case	3 :
			cptr->position.y += Vektor.y;
			break;
		case	6 :
			cptr->position.z += Vektor.z;
			break;
		case	4 :
			if ( cptr->position.x > Vektor.x )
				cptr->position.x -= Vektor.x;
			break;
		case	1 :
			if ( cptr->position.y > Vektor.y )
				cptr->position.y -= Vektor.y;
			break;
		case	5 :
			if ( cptr->position.z > Vektor.z )
				cptr->position.z -= Vektor.z;
			break;
		}
	draw_Camera(cptr);
	if ( xptr )
		*xptr = cptr->position.x;
	if ( yptr )
		*yptr = cptr->position.y;
	if ( zptr )
		*zptr = cptr->position.z;
	return(1);
}

public	int	move_Camera(struct camera3d * cptr,int event )
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

public	int	select_ThisCamera( struct camera3d * cptr )
{
	if (!( cptr )) 
		return( 0 );
	else if (!( cptr->treenode ))
		return(0);
	else if (!( Context.Tree ))
		return(0);
	Context.Tree->current = cptr->treenode;
	return( 1 );
}

public	void	SelectCameraWidget( struct camera3d * cptr, struct object3d * optr )
{
	if (( cptr )
	&&  ( select_ThisCamera( cptr ) )) {
		hide_selection(cptr,0);
		cptr->current = optr;
		show_selection(cptr,_TREE_FOCUS);
		}
	return;
}

public	int	select_TreeHost( struct object3d * optr )
{
	if (!( optr ))
		return(0);
	else if (!( optr->host ))
		return(0);
	else 	{
		SelectCameraWidget( optr->host, optr );
		return(0);
		}
}


private	int	select_CameraItem( int item )
{
	int	mx,my;

	if ( visual_event(1) != _MIMO_DOWN )
		return(0);

	else	{
		mx = visual_event(7);
		my = visual_event(6);
		do	{
			show_camera_sprite( mx,my );
			while ( visual_getch() != 256 );
			mx = visual_event(7);
			my = visual_event(6);
			hide_sprite();
			}
		while ( visual_event(1) != _MIMO_UP );
		if (visual_event(2) == _MIMO_RIGHT)
			return( item);
		if (( mx > Context.DeskTop.x)
		&&  ( my > Context.DeskTop.y)
		&&  ( mx < Context.Palette.x)
		&&  ( my < Context.StatusBar.y )) 
			return( item );
		else	return(0);
		}

}

public	int	select_TreeImage( struct bitmap_control * bptr )
{
	if ( bptr ) {
		select_TreeHost( bptr->host );
		return( select_CameraItem( _VIEW_IMAGE ) );
		}
	return(0);
}

public	int	select_TreeText( struct source_control * sptr )
{
	if ( sptr ) {
		select_TreeHost( sptr->host );
		return( select_CameraItem( _VIEW_TEXT ) );
		}
	return(0);
}

public	int	select_TreeProject( struct camera3d * cptr )
{
	if (!( select_ThisCamera( cptr )))
		return(0);
	if ( visual_event(2) != _MIMO_LEFT ) {
		edit_Camera( cptr );
		return( 1 );
		}
	else	return( select_CameraItem( _EDIT_GRAPH ) );
}



private	void	 item_Camera(struct camera3d * cptr,int cursor)
{
	if (!( cptr )) 		return;
	if (!( cptr->current ))	return;

	switch ( cursor ) {

		case	_FIRST_ITEM		:
			SelectCameraWidget(cptr,cptr->first);
			break;

		case	5			:
		case	_NEXT_ITEM		:
			if (( cptr->current )
			&&  ( cptr->current->next )) {
				SelectCameraWidget(cptr,cptr->current->next);
				}
			break;

		case	_LAST_ITEM		:
			SelectCameraWidget(cptr,cptr->last);
			break;

		case	11			:
		case	_PREVIOUS_ITEM		:
			if (( cptr->current )
			&&  ( cptr->current->previous )) {
				SelectCameraWidget(cptr,cptr->current->previous);
				}
			break;
		}
	return;
}



private	void	drop_CameraItem(struct camera3d * cptr,struct object3d * optr)
{
	if (!( cptr )) 
		return;
	else if (!( optr ))
		return;
	else	{
		drop_CameraPayLoad( optr );
		del_cube(cptr, optr );
		}
}

private		void	add_CameraWild(struct camera3d * cptr, struct object3d * optr);
private		void	add_CameraItem(struct camera3d * cptr, int nature)
{
	struct object3d * optr;

	if (!( cptr ))
		return;

	else if (( optr = build_cube_at(
			cptr->position.x, cptr->position.y, cptr->position.z/2,
			DefaultSizes.x,DefaultSizes.y,DefaultSizes.z)) != (struct object3d *) 0) {
		optr->nature = nature;
		optr->options= (cptr->options  & _CAMERA_AUTOSIZE);
		add_cube(cptr,optr);
		if ( edit_Cube( optr ) == 27 )
			drop_CameraItem(cptr,optr);
		else	{
			cptr->current = optr;
			Context.OutOfDate |= 2;
			add_CameraWild(cptr,optr);
			}
		}
	return;
}

public		void	new_CameraItem(int nature, char * filename)
{
	struct camera3d * cptr;
	struct object3d * optr;

	if (!( cptr = Context.Camera ))
		return;

	else if (( optr = build_cube_at(
			cptr->position.x, cptr->position.y, cptr->position.z/2,
			DefaultSizes.x,DefaultSizes.y,DefaultSizes.z)) != (struct object3d *) 0) {
		optr->nature = nature;
		optr->options= (cptr->options  & _CAMERA_AUTOSIZE);
		optr->name = allocate_string( filename );
		add_cube(cptr,optr);
		load_CameraItem( optr, QUICK );
		}
	return;
}

private		void	add_CameraWild(struct camera3d * cptr, struct object3d * optr)
{
	char			*	nptr;
	char			*	sptr;
	struct	object3d 	*	xptr;
	int				started=0;
	int				items=0;
	int				atx=0;
	int				aty=0;
	struct	coordinate3d		Dimension;
	int				maxy=0;
	int				i;
	char	*			prefix = (char *) 0;

	if ((!( cptr ))
	||  (!( optr ))
	||  (!( nptr = optr->name ))) 
		return;

	for (	sptr=nptr; *sptr!=0; sptr++ )
		if (( *sptr == '*' )
		||  ( *sptr == '?' ))
			break;

	if (!( *sptr ))	return;
		
	/* The Cube Name String Contains a wild card so build a collection */
	/* --------------------------------------------------------------- */
	if ( fn_parser( nptr, namebuffer, 0x0007) != 0)
		prefix = allocate_string( namebuffer );
	else	prefix = (char *) 0;

	while ( filefinder( namebuffer, 255, nptr, strlen(nptr), started, 0 ) != 0 ) {
		for (i=0; i < 255; i++ )
			if ( namebuffer[i] == ' ' )
				break;
		namebuffer[i] = 0;
		started = 1;
		if (!( xptr = build_cube_at(
			(cptr->position.x+atx), (cptr->position.y+aty), cptr->position.z/2,
			DefaultSizes.x,DefaultSizes.y,DefaultSizes.z)))
			break;
		else if (!( xptr->name = relative_filename( namebuffer, prefix )))
			break;
		else	{
			xptr->host   = cptr;
			xptr->nature = optr->nature;
			xptr->options= optr->options;
			add_cube(cptr,xptr);
			drop_CameraPayLoad( xptr );
			load_CameraItem( xptr, ( _INHIBIT_REFRESH | _INHIBIT_PROPERTIES) );
			Dimension.x = (xptr->bottomright.x-xptr->topleft.x);
			Dimension.y = (xptr->bottomright.y-xptr->topleft.y);
			Dimension.z = (xptr->bottomright.z-xptr->topleft.z);
			if ( Dimension.y > maxy )
				maxy = Dimension.y;
			items++;
			if ( items > 5 ) {
				items = 0;
				atx   = 0;
				aty += (maxy+DefaultSizes.y);
				maxy = 0;
				}
			else	atx += (Dimension.x+DefaultSizes.x);
			}
		}
	drop_CameraItem(cptr,optr);
	return;
}


public	int	preserve_Camera(struct camera3d * cptr)
{
	if (!( Context.OutOfDate ))
		return(1);
	else	{
		while (1) {
			switch ( accept_exit( cptr->name ) ) {
				case	_FILE_SAVE :
					save_Camera(cptr,QUICK);
				case	13 :
					return(1);
				case	27 :
					draw_console();
					return(0);
				}
			}
		}
}

extern	int	og;
static	int	panicing=0;

public	int	panic(int s)
{
	if (!( panicing )) {
		if ( s == SIGKILL )
			s = SIGTERM;
		if (!( preserve_Camera( Context.Camera ) ))
			return(1);
		panicing=1;
		close_graphics(og);
		}
	exit(s);
}

public	void	drop_CameraItems(struct camera3d * cptr)
{
	while (( cptr->current ))
		drop_CameraItem(cptr,cptr->current);
	return;
}

public	void	terminate_Camera(struct camera3d * cptr)
{
	if (!( cptr ))
		return;

	if ( Context.TreeView.style ) { swap_TreeView(); }

	if ( cptr->treenode ) {
		disconnect_treeview( cptr->treenode );
		}

	drop_CameraItems( cptr );


	if ( Application.document )
		Application.document = liberate( Application.document );

	if ( Application.target )
		Application.target = liberate( Application.target );

	release_document_parameters();

	if ( cptr->treenode ) {
		remove_treenode( cptr->treenode );
		cptr->treenode = liberate_for_treeview(cptr->treenode );
		}

	cptr = drop_camera( cptr );

	return;
}


private	int	movecube(struct camera3d * cptr, int x, int y, int mode )
{
	struct object3d * optr;
	struct descriptor3d * rptr;
	int	xadjust=0;
	int	yadjust=0;
	if (!( optr = cptr->current))
		return(256);
	else 	rptr = & optr->descriptor;

	if (!( rptr->status ))
		return(256);
	if (!( rptr->status ))
		return(256);
	switch ( mode ) {
		case	0 :	/* Open    */

			Start.x = Finish.x = x;
			Start.y = Finish.y = y;
			Cursor.x = (rptr->values[3].x - rptr->values[0].x);
			Cursor.y = (rptr->values[3].y - rptr->values[0].y);

			visual_frame(
				rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x,Cursor.y,
				_CURSOR_FRAME );

			return(256);

		case	1 :	/* Move	   */
			visual_frame(rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x,Cursor.y,
				_CURSOR_FRAME );

			Finish.x = x;
			Finish.y = y;

			visual_frame(rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x,Cursor.y,
				_CURSOR_FRAME );

			return(256);

		case	2 :	/* Close   */
			visual_frame(rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x,Cursor.y,
				_CURSOR_FRAME );

			Finish.x = x;	Finish.y = y;

			xadjust = (Finish.x-Start.x);
			yadjust = (Finish.y-Start.y);

			adjust3d( optr, & cptr->position, xadjust, yadjust, 0, cptr->direction );

			return( 257 );
		}

	return(256);
}


private	int	pushcube(struct camera3d * cptr, int x, int y, int mode )
{
	struct object3d * optr;
	struct descriptor3d * rptr;
	int	xadjust=0;
	int	yadjust=0;
	if (!( optr = cptr->current))
		return(256);
	else 	rptr = & optr->descriptor;

	if (!( rptr->status ))
		return(256);

	switch ( mode ) {
		case	0 :	/* Open    */

			Start.x = Finish.x = x;
			Start.y = Finish.y = y;
			Cursor.x = (rptr->values[3].x - rptr->values[0].x);
			Cursor.y = (rptr->values[3].y - rptr->values[0].y);

			visual_frame(
				rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x,Cursor.y,
				_CURSOR_FRAME );

			return(256);

		case	1 :	/* Move	   */
			visual_frame(rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x+((Finish.x-Start.x)*2),
				Cursor.y+((Finish.y-Start.y)*2),
				_CURSOR_FRAME );

			Finish.x = x;
			Finish.y = y;

			visual_frame(rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x+((Finish.x-Start.x)*2),
				Cursor.y+((Finish.y-Start.y)*2),
				_CURSOR_FRAME );

			return(256);

		case	2 :	/* Close   */

			visual_frame(rptr->values[0].x+(Finish.x-Start.x),
				rptr->values[0].y+(Finish.y-Start.y),
				Cursor.x+((Finish.x-Start.x)*2),
				Cursor.y+((Finish.y-Start.y)*2),
				_CURSOR_FRAME );

			Finish.x = x;	Finish.y = y;

			xadjust = (Finish.x-Start.x);
			yadjust = (Finish.y-Start.y);

			adjust3d( optr, & cptr->position, xadjust, 0, yadjust, cptr->direction );

			return( 257 );
		}

	return(256);
}


public	int	is_CameraEvent(struct camera3d * cptr,int x, int y)
{
	struct object3d * optr;
	struct descriptor3d * rptr;
	int	t = visual_event(1);
	int 	b = visual_event(2);

	if (!( cptr ))
		return(-1);

	switch ( t ) {

		case	_MIMO_DOWN		:

			if (!( IsDown )) {

				IsDown = 0; DownAtx = x; DownAty = y;
				if (( b == _MIMO_WHEELUP )
				||  ( b == _MIMO_WHEELDOWN ))
					return(256);
 
				for (	optr=cptr->foot;
					optr != (struct object3d *) 0;
					optr = optr->before ) {
					rptr = & optr->descriptor;
					if (!( rptr->status ))
						continue;
					if (( x >= rptr->values[0].x )
					&&  ( y >= rptr->values[0].y )
					&&  ( x <= rptr->values[3].x )
					&&  ( y <= rptr->values[3].y )) {
						SelectCameraWidget( cptr,optr );
						IsDown=b;
						break;
						}			
					}

				if (!( IsDown ))
					return( 256 );
				else if ( b == _MIMO_LEFT ) 
					return(	movecube( cptr, x, y, 0 ) );
				else	return(	pushcube( cptr, x, y, 0 ) );

				}
		
		case	_MIMO_WHILE_DOWN	:
			if (!( IsDown ))
				return(-1);
			if (!( cptr->current ))
				return(-1);
			else if ( IsDown == _MIMO_LEFT ) 
				return(	movecube(cptr, x, y, 1 ) );
			else	return(	pushcube( cptr, x, y, 1 ) );

		case	_MIMO_UP		:

			if (!( IsDown )) 
				return(drag_Camera(cptr,x,y,DownAtx,DownAty,b));
			else 	{
				if ( IsDown != b ) {
					while (1) {
						while ( visual_getch() != 256);
						if (( visual_event(1) == _MIMO_UP )
						&&  ( visual_event(2) == IsDown   ))
							break;
						}
					IsDown = 0;
					return( _EDIT_FORM );
					}
				else 	IsDown = 0;
				if ( b == _MIMO_LEFT ) 
					return(	movecube( cptr, x, y, 2 ) );
				else	return(	pushcube ( cptr, x, y, 2 ) );
				}
		}
	return(-1);

}


public	void	save_form_image( char * nptr, struct standard_image * iptr, int options )
{
	int	r;
	char *	bptr;
	char *	xptr;
	if (!( nptr ))
		return;
	if (!( iptr ))
		return;
	else if (!( nptr = allocate_string( nptr )))
		return;

	if ( options != -1 ) {
		xptr = image_extension( options );
		nptr = enforce_extension(nptr,xptr);
		}
	else	options = 0;

	if (!( nptr ))	return;

	status_message( nptr,3 );
	x_event(35);
	if ( image_nature( options ) == 1 ) {
		if ( gif_create( nptr, iptr->columns, iptr->rows, 8, 0 )  != 0 ) {
			for (	r=0; r < iptr->rows; r++ ) {
				visual_kbhit();
				if (!( bptr = connect_pixel_row( iptr->storage, r ) ))
					break;
				else	gif_row( r, bptr, iptr->columns );
				}
			gif_close();
			}
		}
	else if ( bmp_create( nptr, iptr->columns, iptr->rows, 8 )  != 0 ) {
		for (	r=iptr->rows; r != 0; r-- ) {
			visual_kbhit();
			if (!( bptr = connect_pixel_row(iptr->storage,(r-1)) ))
				break;
			else	bmp_row((r-1),bptr, iptr->columns);
			}
		bmp_close();
		}
	x_event(34);
	liberate( nptr );
	return;
	
}

private	void	build_national_image( struct form_control * fptr, char * nomfic, char * pathroot, char * natroot )
{
	char * 	nptr;
	if (!( fptr ))			return;

	draw_Form( fptr,0 );
	form_Image( fptr );

	if (!( fptr->image ))		return;

	if (!( nptr = allocate_string( nomfic ) ))
		return;
	else if (!( nptr = enforce_extension(nptr,GIF_EXTENSION) ))
		return;

	if ( natroot )
		if (!( nptr = path_prefix( nptr, natroot )))
			return;
	if ( pathroot )
		if (!( nptr = path_prefix( nptr, pathroot )))
			return;
	save_form_image( nptr, fptr->image, -1 );
	liberate( nptr );
	return;
}

public	void	build_tab_image(  struct form_control * fptr, char * nomfic )
{
	build_national_image( fptr, nomfic, Document.pathroot, PathPrefix[fptr->natlang] );
	return;
}

private	int 	save_Camera(struct camera3d * kptr, int automatic)
{
	int	action;
	int	actions;
	FILE	*	h;
	struct object3d * optr;
	struct descriptor3d * rptr;
	struct form_control * fptr;
	struct menu_control * mptr;
	struct bitmap_control * bptr;
	struct standard_class * cptr;
	char		      * nptr;

	if (!( kptr ))
		return(0);

	if (!( kptr->name )) {
		if (!(kptr->name = allocate_string( "new" ) ))
			return(27);
		}

	if ( kptr->options & _CAMERA_FORMS )
		ModelControl.savemembers = 1;
	else	ModelControl.savemembers = 0;	

	if ( kptr->options & _CAMERA_IMAGES )
		ModelControl.saveimages  = 1;
	else	ModelControl.saveimages  = 0;

	if ((nptr = kptr->name) != (char *) 0)
		if ( *nptr == '?' )
			automatic &= ~_INHIBIT_PROPERTIES;

	if (!( system_xml ))
		kptr->name = verify_extension( kptr->name,PROJECT_EXTENSION);
	else	kptr->name = verify_extension( kptr->name,XML_EXTENSION);

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_modelsave(	
			&kptr->name,
			&ModelControl.saveimages,
			&ModelControl.savemembers,
			&ModelControl.saveall) 	== 27 )
			return(0);
		else	{
			if (!( system_xml ))
				kptr->name = verify_extension( kptr->name,PROJECT_EXTENSION);
			else	kptr->name = verify_extension( kptr->name,XML_EXTENSION);
			status_message(kptr->name,3);
			automatic |= _INHIBIT_REFRESH;
			automatic |= _INHIBIT_PROPERTIES;
			}
		}

	if ( detect_extension( kptr->name, XML_EXTENSION ) ) {
		xml_put_Camera( kptr, "threed.dtd", automatic );
		Context.OutOfDate = 0;
		return(0);
		}
	
	else if ((h = open_production_target(kptr->name,1)) != (FILE*) 0) {

		status_message(kptr->name,3);

		put_string(h,"3D");
		put_string(h,LaPaterne);

		put_word(h,0x000F);

		put_word(h,movement);
		put_word(h,Vektor.x);
		put_word(h,Vektor.y);
		put_word(h,Vektor.z);
		put_word(h,DefaultSizes.x);
		put_word(h,DefaultSizes.y);
		put_word(h,DefaultSizes.z);

		put_string(h,kptr->name);
		put_word(h,kptr->position.x);
		put_word(h,kptr->position.y);
		put_word(h,kptr->position.z);
		put_word(h,kptr->focus.x);
		put_word(h,kptr->focus.y);
		put_word(h,kptr->direction);
		put_word(h,kptr->timer);
		put_word(h,kptr->step);

		if (!( palette_is_active() ))
			kptr->options &= ~0x0010;
		else	kptr->options |=  0x0010;

		if (!( toolbar_is_active() ))
			kptr->options &= ~0x0020;
		else	kptr->options |=  0x0020;


		put_word(h,kptr->options);

		put_string(h,kptr->background->iname);
		put_word(h,(kptr->background->colour | (kptr->background->style << 8)));

		put_word(h,Application.isdocument);
		put_string(h, Application.document);

		for (	actions=0,optr=kptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next )
			actions++;

		for (	action=1,optr=kptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {

			status_progress(1,actions,action++);

			put_word(h,optr->nature);
			put_word(h,optr->options);
			put_string(h,optr->name);
			put_word(h,optr->topleft.x);
			put_word(h,optr->topleft.y);
			put_word(h,optr->topleft.z);
			put_word(h,optr->bottomright.x);
			put_word(h,optr->bottomright.y);
			put_word(h,optr->bottomright.z);

			put_word(h,optr->colours.front);
			put_word(h,optr->colours.back);
			put_word(h,optr->colours.left);
			put_word(h,optr->colours.right);
			put_word(h,optr->colours.upper);
			put_word(h,optr->colours.lower);
			put_word(h,optr->colours.shadow);
			put_word(h,optr->colours.light);

			switch ( optr->nature ) {
				case	__3D_TEXT	:
					break;

				case	__3D_IMAGE	:
					if ( optr->image ) {
						if (!( bptr = optr->payload ))
							break;
						else if ( bptr->loadstamp == bptr->savestamp )
							break;
						else	{
							save_form_image( optr->name, optr->image, 0 );
							bptr->loadstamp= bptr->savestamp;
							}
						}
					break;

				case	__3D_FORM	:
					if ((fptr = optr->payload) != (struct form_control *) 0) {
						if (( fptr->loadstamp < fptr->savestamp )
						||  ( ModelControl.saveall )) {
							if (ModelControl.saveimages )
								save_form_image( optr->name, optr->image, optr->options  );
							if ( ModelControl.savemembers )
								save_Form( fptr, automatic );
 
							fptr->loadstamp = fptr->savestamp = time((long*)0);
							}
						}
					break;
#ifdef	_PROTOTYPE_MENUS
				case	__3D_MENU	:
					if ((mptr = optr->payload) != (struct menu_control *) 0) {
						if (( mptr->loadstamp < mptr->savestamp ) 
						||  ( ModelControl.saveall )) {
							if ( ModelControl.saveimages )
								save_form_image( optr->name, optr->image, optr->options  );
							if ( ModelControl.savemembers )
								save_Menu( mptr, automatic );
						
							mptr->loadstamp = mptr->savestamp = time((long*)0);
							}
						}
					break;
#endif
#ifdef	_PROTOTYPE_CLASS
				case	__3D_CLASS	:
					if ((cptr = optr->payload) != (struct standard_class *) 0) {
						if (( cptr->loadstamp < cptr->savestamp ) 
						||  ( ModelControl.saveall )) {
							if ( ModelControl.saveimages )
								save_form_image( optr->name, optr->image, optr->options  );
							if ( ModelControl.savemembers )
								save_Class( cptr, automatic );
			
							cptr->loadstamp = cptr->savestamp = time((long*)0);
							}
						}
					break;
#endif
				}	
			}

		put_word(h,0);

		put_word(h,Application.productiontype);
		put_string(h, Application.target);
		put_word(h,Application.language);

		if ( Context.TreeView.style )
			put_word(h,1);
		else	put_word(h,0);

		put_word(h,Application.makefile);
		if ( Application.makename )
			put_string(h, Application.makename );
		else	put_byte(h,0);
		if ( kptr->configuration )
			put_string(h, kptr->configuration );
		else	put_byte(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);


		close_production_target( h, kptr->name );
		Context.OutOfDate = 0;
		}
	return(0);

}

private	void	drop_CameraPayLoad( struct object3d * optr )
{
	if (!( optr ))	return;

	switch ( optr->nature ) {

		case	__3D_TEXT	:
			if ( optr->payload )
				optr->payload = drop_Source(optr->payload );
			if ( optr->image )
			 	local_drop_image( optr->image );
			break;
		case	__3D_IMAGE	:
			if ( optr->payload )
				optr->payload = drop_Bitmap(optr->payload );
			break;
		case	__3D_FORM	:
			if ( optr->payload )
				optr->payload = liberate_Form(optr->payload );
			break;
#ifdef	_PROTOTYPE_MENUS
		case	__3D_MENU	:
			if ( optr->payload )
				optr->payload = liberate_Menu(optr->payload );
			break;
#endif
#ifdef	_PROTOTYPE_CLASS
		case	__3D_CLASS	:
			if ( optr->payload )
				optr->payload = liberate_Class(optr->payload );
			break;
#endif
		}

	optr->image 	= (struct standard_image *) 0;
	return;

}

private	struct standard_image * camera_text_image( char * nptr )
{
	struct 	standard_image * iptr=(struct standard_image *) 0;
	int			 textwidth;
	int			 textheight=0;
	fn_parser( nptr, workbuffer, 0x0018 );
	textwidth = textsizelen(Context.basefont,workbuffer,strlen(workbuffer));
	textwidth += (Context.fontwidth*4);
	textheight = (Context.fontheight*2);
	if (!( iptr = local_allocate_image(textwidth,textheight,standard_white,0)))
		return(iptr);
	background_pixel_capture( iptr->storage );
	relief(0,0,textwidth,textheight,standard_black,0,standard_black);
	visual_text(1,1,(textwidth-2),(textheight-2),
			Context.basefont, standard_black,0,
			workbuffer,strlen(workbuffer),(_A_CENTER|_A_BOLD));
	cancel_pixel_capture( iptr->storage );
	return( iptr );
}

public	void	load_CameraItem( struct object3d * optr, int automatic )
{
	struct source_control	* sptr;	
	struct bitmap_control	* bptr;	
	struct form_control     * fptr;
	struct menu_control     * mptr;
	struct standard_class 	* cptr;
	struct camera3d 	* kptr;
	struct treeview 	* tptr;
 		
	if (!( optr ))
		return;
	else if (!( kptr = optr->host ))
		return;
	switch ( optr->nature ) {
		case	__3D_TEXT  :

			if (!( automatic & _INHIBIT_STATUS ))
				status_message(optr->name,3);

			if (!( optr->payload = load_Source( optr->name) ))
				new_camera_Source(optr);

			if ((sptr = optr->payload) != (struct source_control*)0) {
				sptr->host    = optr;
				optr->image = camera_text_image( optr->name );
				connect_treenode( sptr->treenode,TREE_TEXT,sptr);
				add_treenode( kptr->treenode, sptr->treenode );
				}
			break;

		case	__3D_IMAGE :
			if (!( automatic & _INHIBIT_STATUS ))
				status_message(optr->name,3);

			if (!( optr->payload = load_Bitmap( optr->name, optr->options ) ))
				new_camera_Bitmap(optr);
			if ((bptr = optr->payload) != (struct bitmap_control*)0) {
				bptr->host    = optr;
				if (!( bptr->payload ))
					bptr->payload = build_bitmap_image( optr );
				optr->image = bptr->payload;
				connect_treenode( bptr->treenode,TREE_IMAGE,bptr);
				add_treenode( kptr->treenode, bptr->treenode );
				}
			break;

		case	__3D_FORM :
			if (!( optr->payload = load_Form(optr->payload,optr->name,1,automatic) ))
				new_camera_Form(optr);				
			if ((fptr = optr->payload) != (struct form_control *) 0) {
				fptr->host    = optr;
				optr->image = fptr->image = load_form_image( optr->name, optr->options );
				fptr->loadstamp = fptr->savestamp = time((long*)0);
				connect_treenode( fptr->treenode,TREE_FORM,fptr);
				add_treenode( kptr->treenode, fptr->treenode );
				}
			break;
#ifdef	_PROTOTYPE_MENUS
		case	__3D_MENU :
			if (!(optr->payload = load_Menu(optr->name,automatic)))
				new_camera_Menu(optr);
			if ((mptr = optr->payload) != (struct menu_control *) 0) {
				mptr->host    = optr;
				optr->image = mptr->image = load_form_image( optr->name, optr->options  );
				mptr->loadstamp = mptr->savestamp = time((long*)0);
				connect_treenode( mptr->treenode,TREE_MENU,mptr);
				add_treenode( kptr->treenode, mptr->treenode );
				}
			break;
#endif
#ifdef	_PROTOTYPE_CLASS
		case	__3D_CLASS :
			if (!( optr->payload = load_Class(optr->name,automatic) ))
				new_camera_Class(optr);
			if ((cptr = optr->payload) != (struct standard_class *) 0) {
				cptr->host    = optr;
				optr->image = cptr->image = load_form_image( optr->name, optr->options  );
				cptr->loadstamp = cptr->savestamp = time((long*)0);
				connect_treenode( cptr->treenode,TREE_CLASS,cptr);
				add_treenode( kptr->treenode, cptr->treenode );
				}
#endif
			break;
		}
	if ( optr->options )
		autosize_Cube( optr );
	return;
}

public	struct camera3d * load_Camera(char * nptr,int automatic)
{
	FILE			* h;
	struct object3d 	* optr;
	struct descriptor3d 	* rptr;
	char			* loadname;
	char			* sptr;
	char			* vptr;
	int			  o;
	int			  oo;
	struct	camera3d *	cptr;

	if (!( nptr )) nptr = "new";

	if (!(loadname = allocate_string( nptr ) ))
		return((struct camera3d *) 0);

	if (!( system_xml )) {
		if (!( loadname = verify_extension( loadname,PROJECT_EXTENSION) ))
			return((struct camera3d *) 0);
		}

	else if (!( loadname = verify_extension( loadname,XML_EXTENSION) ))
		return((struct camera3d *) 0);

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_modelfilename(&loadname) == 27 ) {
			loadname = liberate( loadname );
			return((struct camera3d *) 0);
			}
		else	status_message(loadname,3);
		automatic |= _INHIBIT_PROPERTIES;
		automatic |= _INHIBIT_REFRESH;
		}

	if (!( cptr = initialise_Camera() ))
		return(cptr);

	else if ( detect_extension( loadname, XML_EXTENSION ) )
		return( load_XmlCamera( cptr, loadname, 1, automatic ) );

	while (!(h = fopen(loadname,"rb"))) {
		if ( automatic & _INHIBIT_PROPERTIES )
			break;
		else if ( file_not_found( loadname ) == 27 )
			break;
		}

	if (!( h )) {

		/* First time loading : keep new file name */
		/* --------------------------------------- */
		if (!(cptr->name))
			cptr->name = allocate_string( loadname );
		}
	else	{

		if (!( automatic & _INHIBIT_STATUS )) 
			status_message(loadname,3);

		sptr = vptr = (char *) 0;

		if ((!( sptr = get_string(h)    ))
		||  (!( string_compare(sptr,"3D") ))
		||  (!( vptr = get_string(h)    ))) {
			if ( sptr ) sptr = liberate( sptr );
			if ( vptr ) vptr = liberate( vptr );
			incorrect_filetype(loadname);
			loadname = liberate( loadname );
			fclose(h);
			return(0);
			}

		if ( sptr ) sptr = liberate( sptr );
		if ( vptr ) vptr = liberate( vptr );
		o = get_word(h);

		movement = get_word(h);

		Vektor.x = get_word(h);
		Vektor.y = get_word(h);
		Vektor.z = get_word(h);

		if ( o & 1 ) {
			DefaultSizes.x = get_word(h);
			DefaultSizes.y = get_word(h);
			DefaultSizes.z = get_word(h);
			}
		else	{
			DefaultSizes.x = 100;
			DefaultSizes.x = 50;
			DefaultSizes.x = 10;
			}

		cptr->name= get_string(h);

		cptr->position.x= get_word(h);
		cptr->position.y= get_word(h);
		cptr->position.z= get_word(h);

		cptr->focus.x= get_word(h);
		cptr->focus.y= get_word(h);

		cptr->direction= get_word(h);
		cptr->timer= get_word(h);
		cptr->step= get_word(h);
		if ( o & 2 )
			cptr->options= get_word(h);
		else	cptr->options= 0;

		if ( o & 4 ) {
			cptr->background->iname = get_string(h);
			cptr->background->colour = get_word(h);
			cptr->background->style  = (cptr->background->colour >> 8);
			cptr->background->colour &= 0x00FF;
			check_Camera_background(cptr);
			}

		if ( o & 8 ) {
			if ( Application.document )
				Application.document = liberate( Application.document );
			Application.isdocument	= get_word(h);
			Application.document	= get_string(h);
			}

		while ((oo = get_word(h)) != 0 ) {

			if (!( optr = allocate_cube() ))
				break;
			else	add_cube(cptr,optr);

			if ((optr->nature = oo) == 1)
				optr->nature = __3D_FORM;

			if ( o & 2 )
				optr->options= get_word(h);
			else	optr->options= 0;

			optr->name= get_string(h);

			optr->topleft.x = get_word(h);
			optr->topleft.y = get_word(h);
			optr->topleft.z = get_word(h);
			optr->bottomright.x = get_word(h);
			optr->bottomright.y = get_word(h);
			optr->bottomright.z = get_word(h);

			optr->colours.front= get_word(h);
			optr->colours.back= get_word(h);
			optr->colours.left= get_word(h);
			optr->colours.right= get_word(h);
			optr->colours.upper= get_word(h);
			optr->colours.lower= get_word(h);
			optr->colours.shadow= get_word(h);
			optr->colours.light= get_word(h);
			load_CameraItem( optr, automatic );
			}

		if ( Application.target )
			Application.target = liberate( Application.target );

		Application.productiontype	= get_word(h);
		Application.target		= get_string(h);
		Application.language		= get_word(h);

		o = get_word(h);

		if (( o & 1 ) 
		&&  (!( Context.TreeView.style))) {
			if (!( automatic  & _INHIBIT_REFRESH ))
				swap_TreeView();
			}
		else if ((!( o & 1 ))
		     &&  ( Context.TreeView.style )) {
			if (!( automatic  & _INHIBIT_REFRESH ))
			swap_TreeView();
			}
		
		if ( cptr->options & 0x0010 ) {
			if (!( palette_is_active() ))
				toggle_palette_display();
			}
		else if ( palette_is_active() )
			toggle_palette_display();


		if ( cptr->options & 0x0020 ) {
			if (!( toolbar_is_active() ))
				toggle_toolbar_display();
			}
		else if ( toolbar_is_active() )
			toggle_toolbar_display();


		Application.makefile = get_word(h);
		Application.makename = get_string(h);

		if ((cptr->configuration  = get_string(h)) != (char *) 0)
			LoadConfiguration( cptr->configuration);
	
		o = get_word(h);

		Context.OutOfDate = 0;

		fclose( h );

		}

	loadname = liberate( loadname );
	return(cptr);

}

private	int	resolve_document_section( 
		struct object3d * optr,
		char * target, 
		char * message 		)
{
	int			i;
	char			* kptr;
	char			* iptr;
	struct  form_control 	* fptr;
	struct  menu_control 	* mptr;
	struct  standard_class 	* cptr;
	char 		  	* nptr;

	if ( optr->nature == __3D_FORM ) {
		if (!( kptr = resolve_form_class( (struct form_control *) optr->payload ) ))
			return(0);
		}

	else if (!( kptr = resolve_cube_class( optr ) ))
		return(0);

	else if (!( optr->name ))
		return(0);

	if ( Document.separate ) {
		if ( target != (char *) 0 ) {
			nptr = allocate_string( optr->name );
			nptr = enforce_extension( nptr, HTM_EXTENSION );
			strcpy( target, nptr );
			liberate( nptr );
			}
		}
	else if ( target != (char *) 0 )
		sprintf(target,"#%s",optr->name);

	switch ( optr->nature ) {
		case	__3D_TEXT	:
			return( 0 );

		case	__3D_IMAGE	:
			return( 0 );

		case	__3D_FORM	:

			if (!( fptr = (struct form_control *) optr->payload ))
				return(0);

			iptr = fptr->identifier;
			sprintf(message,"%s",iptr);
			for ( i=0; *(message+i) != 0; i++ )
				if ( *(message+i) == '_' )
					*(message+i) = ' ';
			return( strlen( message ) );
			break;

#ifdef	_PROTOTYPE_MENUS
		case	__3D_MENU	:
			if (!( mptr = (struct menu_control *) optr->payload ))
				return(0);

			iptr = mptr->identifier;
			break;
#endif
#ifdef	_PROTOTYPE_CLASS
		case	__3D_CLASS	:
			if (!( cptr = (struct standard_class *) optr->payload ))
				return(0);

			iptr = cptr->name;
			break;
#endif
		default			:
			return(0);

		}

	if ((!( kptr ))
	||  (!( iptr )))
		return(0);
	else	{
		sprintf(message,"%s : %s",kptr,iptr);
		return( strlen( message ) );
		}
}


private	void	table_of_contents( FILE * handle, struct camera3d * cptr )
{
	struct object3d * optr;
	char		  buffer[64];

	html_open_toc(handle);

	for (	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {

		if (!( resolve_document_section( optr, buffer, namebuffer ) ))
			continue;
		else	html_add_toc_item( handle, buffer, namebuffer );

		}

	html_close_toc(handle);
	return;
}


private	FILE *	html_production_target()
{
	FILE	* handle;

	if (!( handle = open_production_target( Application.document, 0 )))
		return(handle);

	else if (!(  start_html_document(
			handle,
			Document.title,
			Document.logo,
			Document.screenstyle,
			Document.printstyle
			) )) {
		close_production_target( handle, Application.document );
		return((FILE *) 0);
		}
	else	return( handle );
}

private	FILE *	html_camera_production_target(struct camera3d * cptr)
{
	FILE * handle;
	if (!( handle = html_production_target() ))
		return( handle );
	else if (!( Document.separate)) {
		table_of_contents(handle,cptr);
		return( handle );
		}
	else	{
		table_of_contents(handle,cptr);
		return( handle );
		}
}

private	int	align_camera(struct camera3d * cptr)
{
	int	items=0;
	struct	object3d * optr;
	int	primary=1;
	if (!( SingConf->expert_user ))
		return(0);
	if ( accept_camera_alignment(&primary) == 27 )
		return(0);

	for (	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		items++;
		}
	return(0);
}

private	int	makefile_Camera(struct camera3d * camptr,int automatic)
{
	int	nature;
	struct object3d * optr;
	struct form_control * fptr;
	FILE *	handle;

	if (!( Application.makename )) {
		fn_parser( Application.document, namebuffer, 0x000F );
		strcat( namebuffer, MF_EXTENSION );
		if (!( Application.makename = allocate_string( namebuffer ) ))
			return(27);
		}

	if (!( handle = open_production_target( Application.makename, 0 ) ))
		return(46);

	production_banner( handle,_GENERATE_MAKE, Application.document, Application.makename );

	
	for ( nature=0; nature < 3; nature++ ) {

		switch ( nature ) {
			case	0 : makefile_comment(handle,"Class files and Inclusions",0); 	break;
			case	1 : makefile_comment(handle,"Modules and Objects",0); 		break;
			case	2 : makefile_comment(handle,"Programs and Overlays",0); 	break;
			}

		for (	optr=camptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {
			if ( optr->nature != __3D_FORM )
				continue;
			else if (!( fptr = optr->payload ))
				continue;

			switch ( nature ) {
				case	0 : 
					if ((fptr->isprogram != 0) || ( fptr->isoverlay != 0))
						continue;
					else	break;
				case	1 : 
					if (fptr->isprogram != 0) 
						continue;
					else if (!( fptr->isoverlay ))
						continue;
					else 	break;
				case	2	:
					if (!( fptr->isprogram ))
						continue;
					else	break;
				}

			if ( fptr->isprogram ) {
				fn_parser( fptr->prodname, namebuffer,0x000F);
				strcat( namebuffer,AT_EXTENSION);
				fprintf(handle,"\n%s: %s",namebuffer,fptr->loadname);
				}
			else if ( fptr->isoverlay ) {
				fn_parser( fptr->prodname, namebuffer,0x000F);
				strcat( namebuffer, O_EXTENSION );
				fprintf(handle,"\n%s: %s",namebuffer,fptr->loadname);
				}
			else	fprintf(handle,"\n%s: %s",fptr->prodname,fptr->loadname);

			switch ( fptr->language ) {
				case	_GENERATE_BAL 	:
					fprintf(handle,"\n\tsing -ca $*\n");
					break;
				case	_GENERATE_ABAL 	:
					fprintf(handle,"\n\tsing -ca+ $*\n");
					break;
				case	_GENERATE_C 	:
					fprintf(handle,"\n\tsing -cc $*\n");
					break;
				case	_GENERATE_CPP 	:
					fprintf(handle,"\n\tsing -cc+ $*\n");
					break;
				}
	
			}

		fprintf(handle,"\n! make \n\n");
		}

	makefile_comment(handle,"End of file",0);
	close_production_target( handle, Application.makename );
	return(0);

}


private	int	document_Camera(struct camera3d * camptr,int automatic)
{
	FILE *	handle;
	char 		* xptr;
	char 		* docname=(char *) 0;
	char		* tptr;
	char		* kptr;
	struct object3d * optr;
	struct  form_control * fptr;
	struct  menu_control * mptr;
	struct  standard_class * cptr;
	char		* nptr=(char *) 0;
	char		* iname=(char *) 0;
	int	action=0;
	int	actions=0;

	if (!( camptr ))
		return(0);
	else if (!( Application.isdocument ))
		return(0);
	else if (!( not_blank( Application.document ) ))
		return(0);

	if (!( Document.title )) {
		if (!( tptr = configuration_item( "TITLE" ) ))
			tptr = _SING_TITLE;
		Document.title = allocate_string(tptr);
		}

	if (!( Document.logo )) {
		if (!( tptr = configuration_item( "LOGO" ) ))
			tptr = _SING_LOGO;
		Document.logo = allocate_string( tptr );
		}

	if (!( Document.screenstyle )) {
		if (!( tptr = configuration_item( "SCREEN" ) ))
			tptr = _SING_STYLE;
		Document.screenstyle = allocate_string( tptr );
		}

	if (!( Document.printstyle )) {
		if (!( tptr = configuration_item( "PRINT" ) ))
			tptr = _SING_STYLE;
		Document.printstyle = allocate_string( tptr );
		}

	if (!( Document.footer )) {
		if (!( tptr = configuration_item( "COPYRIGHT" ) ))
			tptr = _SING_COPYRIGHT;
		Document.footer = allocate_string( tptr );
		}

	if (!( automatic & _INHIBIT_PROPERTIES )) {

		if ( accept_document_parameters( 
				&Document.title, 
				&Document.pathroot, 
				&Document.screenstyle, &Document.printstyle, 
				&Document.logo,
				&Document.footer,
				&Document.separate, 
				&Document.forcelang,
				&Document.language,
				&Document.report ) == 27 ) 
			return(0);

		}

	if (!(handle = html_camera_production_target(camptr))) 
		return(0);

	else	{

		if ( Document.separate ) {
			close_html_document(handle, Document.footer );
			close_production_target( handle, Application.document );
			handle = (FILE *) 0;
			}

		for (	actions=0,optr=camptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next )
			actions++;

		for (	optr=camptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {

			status_progress(1,actions,action++);

			switch ( optr->nature ) {
				case	__3D_IMAGE	:
				case	__3D_TEXT 	:
					continue;
				}

			if ( Document.separate ) {

				if (!( docname = allocate_string( optr->name ) ))
					continue;
				else if (!( docname = enforce_extension(docname,HTM_EXTENSION)))
					continue;

				if ( Document.forcelang )
					docname = path_prefix(docname,PathPrefix[Document.language]);

				if ( Document.pathroot ) 
					docname = path_prefix(docname,Document.pathroot );

				if (!( automatic & _INHIBIT_STATUS )) 
					status_message(docname,3);
				if (!( handle = open_production_target( docname, 0 )))
					continue;
				/* printf("production : %s\r\n",docname); */
				if (!(  start_html_document(
						handle,
						Document.title,
						Document.logo,
						Document.screenstyle,
						Document.printstyle
						) )) {
					close_production_target( handle, docname );
					continue;
					}
				}
			if (!( resolve_document_section( optr, (char *) 0, workbuffer ) ))
				continue;

			if (!( nptr = allocate_string( optr->name )))
				break;
			xptr = image_extension( optr->options );
			nptr = enforce_extension(nptr,xptr);
	
			if (!( nptr ))	break;

	
			switch ( optr->nature ) {
				case	__3D_FORM	:
					if (( fptr = (struct form_control *) optr->payload) != (struct form_control *) 0) {
						prepare_Form(fptr);
						if ( fptr->pages )
							iname = (char *) 0;
						else	iname = nptr;
						}
					else	iname = nptr;
					html_open_section( handle, optr->name, workbuffer, iname );
					if (( fptr = (struct form_control *) optr->payload) != (struct form_control *) 0) {
						if ( Document.forcelang ) {
							Document.holdlang = fptr->natlang;
							if ( Document.language != fptr->natlang ) {
								if ( fptr->formflags & _FORM_INTERNATIONAL )
									change_national_language( fptr, Document.language );
								else	fptr->natlang = Document.language;
								}
							build_national_image( fptr, fptr->prodname, Document.pathroot, PathPrefix[Document.language] );
							}
						document_Form( handle, fptr, automatic, Document.report );
						if ( Document.forcelang ) {
							Document.holdlang = fptr->natlang;
							if ( Document.holdlang != fptr->natlang ) {
								if ( fptr->formflags & _FORM_INTERNATIONAL )
									change_national_language( fptr, Document.holdlang );
								else	fptr->natlang = Document.holdlang;
								}
							}
						}
					html_close_section( handle );
					break;
#ifdef	_PROTOTYPE_MENUS
				case	__3D_MENU	:
					html_open_section( handle, optr->name, workbuffer, nptr);
					document_Menu( handle, optr->payload, automatic, Document.report );
					html_close_section( handle );
					break;
#endif
#ifdef	_PROTOTYPE_CLASS
				case	__3D_CLASS	:
					html_open_section( handle, optr->name, workbuffer, nptr);
					document_Class( handle, optr->payload, automatic, Document.report );
					html_close_section( handle );
					break;
#endif

				}

			if ( Document.separate ) {
				close_html_document(handle, Document.footer );
				close_production_target( handle, docname );
				handle = (FILE *) 0;
				docname = liberate( docname );
				}

			}

		if (!( Document.separate )) {
			close_html_document(handle, Document.footer );
			close_production_target( handle, namebuffer );
			}
		return(1);
		}

}

private	struct production_manager * start_production( char * fname, int type, int pl )
{
	ProductionManager.filename = fname;
	ProductionManager.nature   = type;
	ProductionManager.prodlang = pl;
	if (!(ProductionManager.handle = open_production_target(
		ProductionManager.filename,0)))
		return( (struct production_manager *) 0 );
	else	{
		switch ( ProductionManager.nature ) {
			case	_APPLICATION_PROGRAM	:
			case	_APPLICATION_OVERLAY	:
				fprintf(ProductionManager.handle,
					"Program %c %c\r\n",0x0022,0x0022);
				break;

			case	_APPLICATION_MODULE 	:
				fprintf(ProductionManager.handle,
					"Module  %c %c\r\n",0x0022,0x0022);
				break;

			case	_APPLICATION_LIBRARY	:
				export_pragmas( ProductionManager.handle );
				fprintf(ProductionManager.handle,
					"Library %c %c\r\n",0x0022,0x0022);
				break;
			}
		return( & ProductionManager );
		}
}

private	void	production_item( 
		struct production_manager * pptr,
		struct object3d * optr, int automatic, int package )
{
	struct  form_control * fptr;
	struct  menu_control * mptr;
	struct  standard_class * cptr;

	switch ( optr->nature ) {
		case	__3D_TEXT	:
			break;

		case	__3D_IMAGE	:
			save_form_image( optr->name, optr->image, optr->options  );
			break;
		case	__3D_FORM	:
			if (!(fptr = optr->payload) != (struct form_control *) 0)
				break;
			switch ( package ) {
				case	0 : /* inclusion */
					if ( fptr->isoverlay )
						return;

				case	1 : /* module	 */
					if ( fptr->isprogram )
						return;
					else	break;

				case	2 :
					if (!( fptr->isprogram ))
						return;
					else	break;

				}
			if ( export_Form( optr->payload, automatic ) != 0 )
				if ( Context.AutoSave )
					save_Form( optr->payload, QUICK );

			export_Form((struct form_control *) 0,0);
			break;
#ifdef	_PROTOTYPE_MENUS
		case	__3D_MENU	:
			export_Menu( optr->payload, automatic );
			export_Menu((struct menu_control *) 0,0);
			break;
#endif
#ifdef	_PROTOTYPE_CLASS
		case	__3D_CLASS	:
			if ( pptr->nature != _APPLICATION_NONE ) {
				if ((cptr = (struct standard_class *) optr->payload)!=(struct standard_class *) 0) {
					abal_include(pptr->handle, cptr->prodname );
					}
				}
			export_Class( optr->payload, automatic );
			export_Class((struct standard_class *) 0,0);
			break;
#endif
		}
	return;
}

private	void	close_production( struct production_manager * mptr, int automatic )
{
	if (!( mptr ))
		return;
	else if (!( mptr->handle ))
		return;
	else	{
		switch ( mptr->nature ) {
			case	_APPLICATION_PROGRAM	:
			case	_APPLICATION_OVERLAY	:
				fprintf(mptr->handle,
					"End\r\n");
				break;

			case	_APPLICATION_MODULE 	:
				fprintf(mptr->handle,
					"End\r\n");
				break;

			case	_APPLICATION_LIBRARY	:
				fprintf(mptr->handle,
					"\tAll\r\n");
				fprintf(mptr->handle,
					"End\r\n");
				break;
			}

		close_production_target( mptr->handle, mptr->filename  );
		mptr->handle = (FILE*) 0;

		switch ( mptr->prodlang ) {
			case	_GENERATE_C	:
			case	_GENERATE_CPP	:
				break;
			case	_GENERATE_BAL	:
				translate_abal(0,mptr->filename,automatic);
				break;
			case	_GENERATE_ABAL	:
				translate_abal(1,mptr->filename,automatic);
				break;
			}
		}
		return;
}




private	void	export_Camera(struct camera3d * cptr, int automatic)
{
	struct production_manager * h=(struct production_manager *) 0;
	struct object3d * optr;
	int		  status=0;
	int		action=0;
	int		actions=0;
	int		prodlang=0;
	int		package=0;

	if (!( cptr ))
		return;


	if (!( automatic & _INHIBIT_PROPERTIES )) {

		if (( SingConf )
		&&  ( SingConf->expert_user ))
			prodlang = Application.language;

		else if ((prodlang = (Application.language-_GENERATE_BAL)) < 0 ) {
			if ( SingConf )
				SingConf->expert_user++;
			prodlang = Application.language;
			}		

		if ((status  = accept_production_properties(
				&cptr->name,
				&Application.target,
				&automatic,	
				&Application.build,
				&Application.visible,
				&Application.productiontype,
				&Application.isdocument,
				&prodlang,
				&Application.document,
				&Application.makefile,
				&Application.makename
				)) == 27)
			return;
		else	{
			if (( SingConf )
			&&  ( SingConf->expert_user ))
				Application.language = prodlang;
			else	Application.language = (prodlang+_GENERATE_BAL);
			}

		}

	if ( Application.build ) {

		switch ( Application.productiontype ) {
			case	_APPLICATION_NONE	:

				break;
			default				:
			case	_APPLICATION_PROGRAM	:
			case	_APPLICATION_OVERLAY	:
			case	_APPLICATION_MODULE 	:
			case	_APPLICATION_LIBRARY	:
				if (!(h = start_production(Application.target,Application.productiontype,Application.language)))
					return;
				else	status_message(Application.target,3);

			}

		if (!( Application.visible )) {
			automatic |= _INHIBIT_REFRESH;
			automatic &= ~_INHIBIT_STATUS;
			}
		else	{
			automatic &= ~_INHIBIT_REFRESH;
			automatic &= ~_INHIBIT_STATUS;
			}			

		for (	actions=0,optr=cptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next )
			actions++;

		for (	package=0;	
			package<3;
			package++ ) {
			for (	optr=cptr->first;
				optr != (struct object3d *) 0;
				optr = optr->next ) {
				status_progress(1,actions,action++);
				production_item( h, optr, automatic,package );
				}
			}

		switch ( Application.productiontype ) {
			case	_APPLICATION_NONE	:

				break;
			default				:
				close_production(h,automatic);
			}
		}


	if ( Application.makefile )
		(void) makefile_Camera( cptr, automatic );

	if ( Application.isdocument )
		(void) document_Camera( cptr,automatic );

	return;
}

private	void	calculate_Camera(struct camera3d * cptr)
{
	struct object3d * optr;
	int	item=0;

	if (!( cptr ))
		return;

	for (	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		optr->bottomright.x = (optr->topleft.x+DefaultSizes.x);
		optr->bottomright.y = (optr->topleft.y+DefaultSizes.y);
		optr->bottomright.z = (optr->topleft.z+DefaultSizes.z);
		}

	return;
}

private	void	pushpull_Camera(struct camera3d * cptr, int event)
{
	struct 	coordinate3d	position;
	struct object3d * optr;
	int	item=0;

	if (!( cptr ))
		return;
	else if (!( cptr->current))
		return;

	position.x = cptr->current->topleft.x;
	position.y = cptr->current->topleft.y;
	position.z = cptr->current->topleft.z;


	for (	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		switch ( movement ) {
			case	0 :
				if ( optr->topleft.x >= position.x ) {
					if ( event == CTRL_N ) {
						optr->topleft.x += Vektor.x;
						optr->bottomright.x += Vektor.x;
						}
					else if (( event == CTRL_Y )
					     &&  ( optr->topleft.x > Vektor.x )) {
						optr->topleft.x -= Vektor.x;
						optr->bottomright.x -= Vektor.x;
						}
					}
				continue;

			case	1 :
				if ( optr->topleft.y >= position.y ) {
					if ( event == CTRL_N ) {
						optr->topleft.y += Vektor.y;
						optr->bottomright.y += Vektor.y;
						}
					else if (( event == CTRL_Y )
					     &&  ( optr->topleft.y > Vektor.y )) {
						optr->topleft.y -= Vektor.y;
						optr->bottomright.y -= Vektor.y;
						}
					}
				continue;

			case	2 :
				if ( optr->topleft.z >= position.z ) {
					if ( event == CTRL_N ) {
						optr->topleft.z += Vektor.z;
						optr->bottomright.z += Vektor.z;
						}
					else if (( event == CTRL_Y )
					     &&  ( optr->topleft.z > Vektor.z )) {
						optr->topleft.z -= Vektor.z;
						optr->bottomright.z += Vektor.z;
						}
					}
				continue;
			}
		}
	return;
}

private	void	document_CameraItem(struct camera3d * kptr)
{
	struct object3d * optr;
	struct form_control * fptr;
	struct menu_control * mptr;
	struct  standard_class * cptr;
	if (!( kptr )) 
		return;
	else if (!( optr = kptr->current ))	
		return;
	else	{
		switch ( optr->nature ) {
			case	__3D_TEXT	:
				break;

			case	__3D_IMAGE	:
				break;

			case	__3D_FORM	:
				if (!(fptr = optr->payload ))
					break;
				else	{
					use_visual_text_editor( & fptr->document, _GENERATE_HTML );
					}
				break;

#ifdef	_PROTOTYPE_MENUS
			case	__3D_MENU	:
				if (!(mptr = optr->payload ))
					break;
				else	{
					use_visual_text_editor( & mptr->document, __GENERATE_HTML );
					}
				break;
#endif
#ifdef	_PROTOTYPE_CLASS
			case	__3D_CLASS	:
				if (!(cptr = optr->payload ))
					break;
				else	{
					use_visual_text_editor( & cptr->document, __GENERATE_HTML );
					}
				break;
#endif
			}
		}

}

public	int	await_camera_event(struct camera3d * cptr)
{
	int	c;
	show_selection(cptr,_TREE_FOCUS); 
	do	{
		c = visual_getch();
		}
	while ((c == 256)
	&&     ((c = handle_event()) == 256));
	hide_selection(cptr,0);
	return(c);
}

public	void	exec_Camera(struct camera3d * cptr)
{
	if (!( cptr )) return;
	if (!( cptr->current )) return;	
	if (!( cptr->current->name )) return;
		abal_runtime( cptr->current->name, 0);
	return;

}

public	void	resize_console()
{
	calibrate_desktop(Context.Camera);
	if ( Context.Form ) {
		calibrate_Form( Context.Form );
		}
	if ( Context.EditView == 1 ) {
		reconfigure_editor(); 
		}
	draw_console();
	return;
}

public	void	swap_TreeView()
{
	if ( Context.TreeView.style != 0 )
		reconfigure_console(0);
	else	reconfigure_console(1);
	resize_console();
	return;
}

public	void	show_DeskTop_TreeView()
{
	if (!( Context.TreeView.style ))
		reconfigure_console(1);
	return;
}

public	void	hide_DeskTop_TreeView()
{
	if ( Context.TreeView.style )
		reconfigure_console(0);
	return;
}

public	void	background_Camera(struct camera3d * cptr, int v )
{
	struct background2d * bptr;
	if (!( cptr ))
		return;
	else if (!(bptr = cptr->background))
		return;
	else	{
		bptr->colour = v;
		draw_DeskTop();
		}

}

public	int	CameraOnGetFocus(struct camera3d ** ccptr) 
{
	int	c;
	struct object3d * optr;
	struct	camera3d* cptr;

	if (!( cptr = *ccptr ))
		return(0);
	else	{
		Context.Camera = cptr;
		calibrate_desktop(cptr);
		add_3d_editor_menu();
		use_model_tools();
		draw_console();
		return(1);
		}
}

#include "singdict.c"


public	void	formhelpCamera(struct camera3d * cptr) 
{
	struct 	object3d 	* optr;
	struct	form_control 	* fptr;
	if (!( cptr ))
		return;
	else if (!( optr=cptr->current ))
		return;
	else if ( optr->nature != __3D_FORM )
		return;
	else if (!( fptr = optr->payload))
		return;
	else if (!( fptr->formflags & _INTERNATIONAL ))
		return;
	else	{
		edit_form_helptexts(fptr);
		return;
		}
}

public	void	translateCamera(struct camera3d * cptr) 
{
	struct 	object3d 	* optr;
	struct	form_control 	* fptr;
	struct	form_item 	* iptr;
	initialise_dictionary();
	for (	optr=cptr->first;
		optr != (struct object3d *) 0;
		optr = optr->next ) {
		if ( optr->nature != __3D_FORM )
			continue;
		else if (!( fptr = optr->payload))
			continue;
		else if (!( fptr->formflags & _INTERNATIONAL ))
			continue;
		for (	iptr=fptr->first;
			iptr != (struct form_item*) 0;
			iptr = iptr->next ) {
			set_national_payload(iptr,fptr->natlang);
			add_dictionary_term( iptr );
			get_national_payload(iptr,fptr->natlang);
			}
		}
	terminate_dictionary();
	return;
}

private	int	use_3d_editor(struct camera3d * cptr, int event)
{
	drop_3d_editor_menu();
	if ( event == _EDIT_FORM )
		event = form_CameraItem(cptr,event);
	else if ( event == _EDIT_FONT )
		event = font_edit(Context.Item.font);
	else if ( event == _EDIT_IMAGE )
		event = zoom_CameraItem(cptr);
	else if ( event == _EDIT_TEXT )
		event = text_CameraItem(cptr);
	add_3d_editor_menu();

	if ( event == _EDIT_GRAPH ) {
		draw_console();
		}
	return(event);
}

public	int	CameraOnUseEvent(struct camera3d ** ccptr, int event)
{
	struct camera3d * cptr;
	struct camera3d * xptr;

	if (!( cptr = *ccptr ))
		return(event);

	switch ( event ) {

		case	__3D_CALC	:
			calculate_Camera(cptr);
			draw_DeskTop();
			event=0; break;;
				

		case	'-'		:
		case	'+'		:
			if (!( use_CameraItem( cptr->current, event ) )) {
				event=0; break;;
				}
			else	{
				draw_TreeView();
				event=0; break;;
				}

		case	32		:
		case	CTRL_C		:
		case	CTRL_R		:
			if ( move_Camera(cptr,event) )
				draw_DeskTop();
			event=0; break;;
			case	CTRL_N		:

		case	CTRL_Y		:
			pushpull_Camera(cptr,event);
			draw_DeskTop();
			event=0; break;;

		case	_EDIT_DATABASE	:
			database_editor();
			event=0; break;

		case	11		:
		case	5		:

		case	_FIRST_ITEM	:
		case	_PREVIOUS_ITEM	:
		case	_NEXT_ITEM	:
		case	_LAST_ITEM	:
			item_Camera(cptr,event);
			event=0; break;;

		case	'f'		:
		case	'F'		:
		case	__3D_FORWARD	: 
			view_Camera(cptr,'F');
			event=0; break;;

		case	'b'		:
		case	'B'		:
		case	__3D_BACK	: 
			view_Camera(cptr,'B');
			event=0; break;;

		case	'l'		:
		case	'L'		:
		case	__3D_LEFT	: 
			view_Camera(cptr,'L');
			event=0; break;;

		case	'r'		:
		case	'R'		:
		case	__3D_RIGHT	: 
			view_Camera(cptr,'R');
			event=0; break;;

		case	'u'		:
		case	'U'		:
		case	__3D_UP		: 
			view_Camera(cptr,'U');
			event=0; break;;

		case	'd'		:
		case	'D'		:
		case	__3D_DOWN 	: 
			view_Camera(cptr,'D');
			event=0; break;;

		case	_EXEC_PROG	:
			exec_Camera(cptr);
			event=0; break;;
		case	__3D_ALIGN	:
			align_camera( cptr );
			event=0; break;

		case	CTRL_I		:
		case	_EDIT_PROPERTIES:
			edit_CameraItem(cptr);
			draw_console();
			event=0; break;;

		case	__3D_TRANSLATE	:
			translateCamera(cptr);
			draw_console();
			event=0; break;

		case	__3D_HELP	:
			formhelpCamera(cptr);
			draw_console();
			event=0; break;

		case	CTRL_Z		:
		case	__3D_CAMERA	:
			edit_Camera(cptr);
			draw_console();
			event=0; break;;

		case	0x007F		:
			drop_CameraItem(cptr,cptr->current);
			Context.OutOfDate |= 2;
			draw_console();
			event=0; break;;

#ifdef	_PROTOTYPE_MENUS
		case	__3D_MENU	:
#endif
		case	__3D_TEXT	:
		case	__3D_IMAGE	:
		case	__3D_FORM	:
#ifdef	_PROTOTYPE_CLASS
		case	__3D_CLASS	:
#endif
			add_CameraItem(cptr,event);

		case	257		:
			draw_console();
			event=0; break;;

#ifdef	_PROTOTYPE_ANALYSER
		case	2727		:
			use_analyser();
			event=0; break;
#endif
		case	_FILE_NEW	:
			event = preserve_Camera( cptr );
			if (!( event )) { break; }		
			drop_CameraItems( cptr );
			event=0; break;;

		case	_FILE_PRODUCE	:
			export_Camera(cptr,0);
			draw_console();
			event=0; break;;

		case	_FILE_COMPARE	:
			compare_Files((char *) 0, (char *) 0);
			draw_console();
			event=0; break;;

		case	_FILE_SAVE	:
			save_Camera(cptr,0);
			draw_console();
			event=0; break;;

		case	_FILE_QSAVE	:
			save_Camera(cptr,QUICK);
			draw_console();
			event=0; break;;

		case	_FILE_LOAD	:
			event = preserve_Camera( cptr );
			if (!( event )) { break; }		
			if (!(xptr = load_Camera(cptr->name,0)))
				draw_console();
			else	{
				cptr = CameraOnChangeFocus(xptr,0);
				}
			event=0; break;;

		case	_EVENT_FORMDOC		:
			document_CameraItem(cptr);
			event=0; break;;

		case	_EDIT_TREEVIEW  :
			swap_TreeView();
			event=0; break;;

		case	_LEAVE_SING	:
		case	_FILE_DROP	:
		case	_EDIT_GRAPH 	:
			break;;

		case	_VIEW_TEXT	:
			event = use_3d_editor(cptr,_EDIT_TEXT);
			break;

		case	_VIEW_IMAGE	:
			event = use_3d_editor(cptr,_EDIT_IMAGE);
			break;

		case	_USE_ITEM	:
			event = _EDIT_FORM;

		case	_EDIT_TEXT	:
		case	_EDIT_FORM	:
		case	_EDIT_FONT	:
		case	_EDIT_IMAGE	:

			event = use_3d_editor(cptr,event);
			break;

		default			:
			event=0; break;;
	
		}
	*ccptr = cptr;
	return( event );
}


public	int	CameraOnLoseFocus(struct camera3d ** ccptr)
{
	drop_3d_editor_menu();
	drop_tool_manager();
	if ( ccptr ) { *ccptr = Context.Camera; }
	Context.Camera = (struct camera3d *) 0;
	return(0);
}

public	struct camera3d * CameraOnChangeFocus(struct camera3d * cptr,int reset)
{
	struct	camera3d * xptr=(struct camera3d *) 0;
	CameraOnLoseFocus(&xptr);
	if ( reset ) {
		if ( xptr ) {	terminate_Camera(xptr);	} 
		}
	CameraOnGetFocus(&cptr);
	return( cptr );
}

public	int	CameraOnExec(struct camera3d ** ccptr)
{
	int	event;
	if (!( CameraOnGetFocus( ccptr ) ))
		return(0);
	else	{
		while (1) {
			event = await_camera_event(*ccptr);
			while (( event = CameraOnUseEvent(ccptr,event)) != 0) {
				if (( event == _EDIT_GRAPH) 
				||  ( event == _FILE_DROP )) {
					CameraOnLoseFocus(ccptr);
					return( event );
					}
				else if ( event != _LEAVE_SING)
					continue;
				else if (!(  preserve_Camera( *ccptr ) )) {
					break;
					}
				else	{
					CameraOnLoseFocus(ccptr);
					return(event);
					}
				}
			}
		}
}


public	int	CameraWorkOut( char * aptr )
{
	int	status=0;
	struct	camera3d * cptr;

	accept_introduction_create(&Context.Introduction);
	accept_introduction_show(Context.Introduction);
	sleep(1);
	if (!(cptr = load_Camera(aptr,_INHIBIT_REFRESH|_INHIBIT_PROPERTIES))) {
		if (!( cptr = initialise_Camera()))
			return(27);
		else	{
			cptr->options |= _CAMERA_AUTOSIZE;
			cptr->options |= _CAMERA_FORMS;
			cptr->options |= _CAMERA_IMAGES;
			}
		}
	accept_introduction_hide(Context.Introduction);
	accept_introduction_remove(Context.Introduction);
	while (1) {
		if (!( Context.Tree ))
			break;
		else if (!( Context.Tree->current ))
			break;
		else if (!(cptr = Context.Tree->current->payload ))
			break;
		else if ((status = CameraOnExec(&cptr)) == _LEAVE_SING)
			break;
		else if ( status != _FILE_DROP )
			continue;
		else if (!(status = preserve_Camera( cptr )))
			continue;
		else	{
			terminate_Camera(cptr);	
			if ( !( Context.Tree->current ))
				if (!( cptr = initialise_Camera()))
					return(27);
			}
		}
	return(status);
}

/*	--------------------------------------------------------------------------	*/
/*	Called from APLUS token analyser / convertor for  Visual Class Expressions	*/
/*	--------------------------------------------------------------------------	*/
public	struct form_control * locate_form_control( char * sptr )
{
	struct	camera3d * cptr;
	struct	object3d * optr;
	struct	form_control * fptr;
	if (( cptr = Context.Camera ) != (struct camera3d *) 0) {
		for ( 	optr=cptr->first;
			optr != (struct object3d *) 0;
			optr = optr->next ) {
			if ( optr->nature != __3D_FORM )
				continue;
			else if (!( fptr = optr->payload))
				continue;
			else if ( string_compare( fptr->identifier, sptr ) )
				return( fptr );
			}

		}
	return((struct form_control *) 0);
}


#endif	/* _singcam_c */
	/* ---------- */

