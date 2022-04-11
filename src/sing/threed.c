#ifndef	_three_d_c
#define _three_d_c

#include <stdio.h>
#include "singprot.h"

#define PRIVATE

#include "threed.h"
#include "texture.h"
#include "vimage.h"
#include "align.h"
#include "valign.h"
#include "gui.c"

FILE *	TraceTarget=(FILE *) 0;

void	*	check_psu( void *);

extern	char *	drop_string( char * );

extern	int	verbose;

/*	Delta Value Computational Macros	*/
/*	--------------------------------	*/

#ifdef	_TRACE_COMPUTATION

	/* ------------------- */
	/*    Slow Function    */
	/* ------------------- */

int	compute( int ov, int cv, int op, int cp, int dv, int dp )
{
	if ( TraceTarget ) {
		fprintf(TraceTarget,"\nCompute(%u,%u,%u,%u,%u,%u)\n\t",ov,cv,op,cp,dv,dp);
		fprintf(TraceTarget,
		"((((long)(%d ? (%d-%d) : (%d-%d))) * ( %d ? %d : %d ))/(%d ? %d : %d))",
			dv,cv,ov,ov,cv,dp,cp,op,dp,op,cp
			);
		}
	return(((((long)(dv ? ((cv-ov)+1)) : ((ov-cv)+1))) * ( dp ? cp : op ))/(dp ? op : cp)));
}

	/* ------------------- */
#else	/* ! TRACE_COMPUTATION */
	/* ------------------- */
	/*  High Speed Macro   */
	/* ------------------- */

#define	compute( ov, cv, op, cp, dv, dp ) ((((long) (dv ? ((cv-ov)+1) : ((ov-cv)+1))) * ( dp ? cp : op ))/(dp ? op : cp))

#endif

#define	dxdz(v,d) compute(input[v].x,camera.x,input[v].z,camera.z,control[d].x,control[d].z) 
#define	dydz(v,d) compute(input[v].y,camera.y,input[v].z,camera.z,control[d].y,control[d].z) 

#define	dydx(v,d) compute(input[v].y,camera.y,input[v].x,camera.x,control[d].y,control[d].x) 
#define	dzdx(v,d) compute(input[v].z,camera.z,input[v].x,camera.x,control[d].z,control[d].x) 

#define	dxdy(v,d) compute(input[v].x,camera.x,input[v].y,camera.y,control[d].x,control[d].y) 
#define	dzdy(v,d) compute(input[v].z,camera.z,input[v].y,camera.y,control[d].z,control[d].y) 

#define	_BACK_COLOUR		viewcolour.back
#define	_FRONT_COLOUR		viewcolour.front
#define	_LEFT_COLOUR		viewcolour.left
#define	_RIGHT_COLOUR		viewcolour.right
#define	_UPPER_COLOUR		viewcolour.upper
#define	_LOWER_COLOUR		viewcolour.lower
#define	_LIGHT_COLOUR		viewcolour.light
#define	_SHADOW_COLOUR		viewcolour.dark

PRIVATE	struct coordinate3d control[all_directions] = {

	/* These values are ok */

	0,0,0,	1,0,1,	0,0,1,	1,0,0,
	1,0,0,	0,1,0,	1,1,0,	0,1,1,
	0,1,0,	1,1,1,	0,0,1,	0,1,0,

	/* These constants need calculating */

	0,0,0,	1,0,1,	0,0,1,	1,0,0,
	1,0,0,	0,1,0,	1,1,0,	0,1,1,
	0,1,0,	1,1,1,	0,0,1,	0,1,0

	};

PRIVATE	struct coordinate3d	camera = { 
	P3D_ZERO, P3D_ZERO, P3D_ZERO 
	};

PRIVATE	struct coordinate3d	lower  = { 
	P3D_ZERO, P3D_ZERO, P3D_ZERO 
	};

PRIVATE	struct coordinate3d	upper  = { 
	P3D_ZERO, P3D_ZERO, P3D_ZERO 
	};

PRIVATE	struct coordinate3d	input[all_vortices] = {
	P3D_ZERO,P3D_ZERO,	P3D_ZERO,P3D_ZERO,	
	P3D_ZERO,P3D_ZERO,	P3D_ZERO,P3D_ZERO,
	P3D_ZERO,P3D_ZERO,	P3D_ZERO,P3D_ZERO,	
	P3D_ZERO,P3D_ZERO,	P3D_ZERO,P3D_ZERO
	};

PRIVATE	struct coordinate2d minimum = { 
	P3D_MAX, P3D_MAX 
	};

PRIVATE	struct coordinate2d maximum = { 
	P3D_MIN, P3D_MIN
	};

PRIVATE	struct coordinate2d	output[all_vortices] = {
	P3D_ZERO, P3D_ZERO, P3D_ZERO, P3D_ZERO, 
	P3D_ZERO, P3D_ZERO, P3D_ZERO, P3D_ZERO, 
	P3D_ZERO, P3D_ZERO, P3D_ZERO, P3D_ZERO, 
	P3D_ZERO, P3D_ZERO, P3D_ZERO, P3D_ZERO
	};

PRIVATE	struct coordinate2d	margins 	= { P3D_ZERO,P3D_ZERO };
PRIVATE	struct coordinate2d	dimensions	= { P3D_ZERO,P3D_ZERO };
PRIVATE	struct coordinate2d	focus		= { P3D_ZERO,P3D_ZERO };
PRIVATE	struct coordinate2d	edge 		= { P3D_ZERO,P3D_ZERO };

PUBLIC	struct	background2d leftwall= { 
	(char *) 0,
	(struct standard_image *) 0,
	0,
	0,0,0,0,0,0
	};		

PUBLIC	struct	background2d ceiling= { 
	(char *) 0,
	(struct standard_image *) 0,
	0,
	0,0,0,0,0,0
	};		

PUBLIC	struct	background2d floor= { 
	(char *) 0,
	(struct standard_image *) 0,
	0,
	0,0,0,0,0,0
	};		

PUBLIC	struct	background2d rightwall= { 
	(char *) 0,
	(struct standard_image *) 0,
	0,
	0,0,0,0,0,0
	};		

PUBLIC	struct	background2d background= { 
	(char *) 0,
	(struct standard_image *) 0,
	0,
	0,0,0,0,0,0
	};		

PUBLIC	struct	background2d foreground= { 
	(char *) 0,
	(struct standard_image *) 0,
	0,
	0,0,0,0,0,0
	};		
				
/*	PUBLIC	VARIABLES or STRUCTURES		*/
/*	-------------------------------		*/

PUBLIC	struct coordinate3d	correction = {
	P3D_ZERO, P3D_ZERO, P3D_ZERO
	};

PUBLIC	struct	colour3d	facecolour = {
	/* front =  */ 20,	/* back	   = */ 16,
	/* left  =  */ 21,	/* right   = */ 19,
	/* upper =  */ 22,	/* lower   = */ 18,
	/* light =  */ 23,	/* shadow  = */ 17
	};

PUBLIC	struct	colour3d	viewcolour = {
	/* front =  */ 20,	/* back	   = */ 16,
	/* left  =  */ 21,	/* right   = */ 19,
	/* upper =  */ 22,	/* lower   = */ 18,
	/* light =  */ 23,	/* shadow  = */ 17
	};


PUBLIC	struct	paint3d	upperfill = {
	0,0,20
	};

PUBLIC	struct	paint3d	lowerfill = {
	0,0,20
	};

PUBLIC	struct	paint3d	leftfill = {
	0,0,20
	};

PUBLIC	struct	paint3d	rightfill = {
	0,0,20
	};


#include "face3d.c"


PRIVATE	VOID	show_ivalues( target )
	FILE *	target;
{
	fprintf(target,"\n 3 dimensional Input Coordinates : \n");
	fprintf(target,"[%5d,%5d,%5d]---------------------[%5d,%5d,%5d]\n",
		input[0].x,input[0].y,input[0].z,
		input[1].x,input[1].y,input[1].z );
	fprintf(target,"        |          %c                             |        |%c\n",0x005C,0x005C);
	fprintf(target,"        |           [%5d,%5d,%5d]--------- | ---------[%5d,%5d,%5d]\n",
		input[4].x,input[4].y,input[4].z,
		input[5].x,input[5].y,input[5].z);
	fprintf(target,"        |                    |                   |                   |\n");
	fprintf(target,"[%5d,%5d,%5d]---------------------[%5d,%5d,%5d]          |\n",
		input[2].x,input[2].y,input[2].z,
		input[3].x,input[3].y,input[3].z);
	fprintf(target,"                   %c         |                             %c         |\n",0x005C,0x005C);
	fprintf(target,"                    [%5d,%5d,%5d]---------------------[%5d,%5d,%5d]\n",
		input[6].x,input[6].y,input[6].z,
		input[7].x,input[7].y,input[7].z);
	return;
}

PRIVATE	VOID	show_ovalues(target )
	FILE *	target;
{
	fprintf(target,"\n 2 dimensional Output Coordinates : \n");
	fprintf(target,"[  %5d , %5d  ]---------------------[  %5d , %5d  ]\n",
		output[0].x,output[0].y,
		output[1].x,output[1].y);
	fprintf(target,"         |         %c                             |         %c\n",0x005C,0x005C);
	fprintf(target,"         |          [  %5d , %5d  ]--------- | ---------[  %5d , %5d  ]\n",
		output[4].x,output[4].y,
		output[5].x,output[5].y);
	fprintf(target,"         |                   |                   |                   |\n");
	fprintf(target,"[  %5d , %5d  ]---------------------[  %5d , %5d  ]          |\n",
		output[2].x,output[2].y,
		output[3].x,output[3].y);
	fprintf(target,"                   %c         |                             %c         |\n",0x005C,0x005C);
	fprintf(target,"                    [  %5d , %5d  ]---------------------[  %5d , %5d  ]\n",
		output[6].x,output[6].y,
		output[7].x,output[7].y);
	return;
}

PRIVATE	VOID	prepare_values( int direction ) 
{

	/* Set X values */
	switch ( direction ) {
		case	zpyp	:
		case	zoyo	:
		case	ypzo	:
		case	yozp	:
			input[0].x = input[2].x = input[4].x = input[6].x = lower.x;
			input[1].x = input[3].x = input[5].x = input[7].x = upper.x;
			break;

		case	yozo	:
		case	ypzp	:
		case	zpyo	:
		case	zoyp	:
			input[0].x = input[2].x = input[4].x = input[6].x = upper.x;
			input[1].x = input[3].x = input[5].x = input[7].x = lower.x;
			break;
	
		case	xoyo	:
		case	xoyp	:
			input[0].x = input[1].x = input[2].x = input[3].x = upper.x;
			input[4].x = input[5].x = input[6].x = input[7].x = lower.x;
			break;

		case	xpyo	:
		case	xpyp	:
			input[0].x = input[1].x = input[2].x = input[3].x = lower.x;
			input[4].x = input[5].x = input[6].x = input[7].x = upper.x;
			break;
		}

	/* Set Y values */
	switch ( direction ) {
		case	xoyo	:
		case	xpyo	:
		case	zpyo	:
		case	zoyo	:
			input[0].y = input[1].y = input[4].y = input[5].y = lower.y;
			input[2].y = input[3].y = input[6].y = input[7].y = upper.y;
			break;

		case	xpyp	:
		case	xoyp	:
		case	zpyp	:
		case	zoyp	:
			input[0].y = input[1].y = input[4].y = input[5].y = upper.y;
			input[2].y = input[3].y = input[6].y = input[7].y = lower.y;
			break;
	
		case	yozo	:
		case	yozp	:
			input[0].y = input[1].y = input[2].y = input[3].y = upper.y;
			input[4].y = input[5].y = input[6].y = input[7].y = lower.y;
			break;

		case	ypzo	:
		case	ypzp	:
			input[0].y = input[1].y = input[2].y = input[3].y = lower.y;
			input[4].y = input[5].y = input[6].y = input[7].y = upper.y;
			break;

		}

	/* Set Z values */
	switch ( direction ) {
		case	zoyp	:
		case	zoyo	:
			input[0].z = input[1].z = input[2].z = input[3].z = upper.z;
			input[4].z = input[5].z = input[6].z = input[7].z = lower.z;
			break;
		case	zpyp	:
		case	zpyo	:
			input[0].z = input[1].z = input[2].z = input[3].z = lower.z;
			input[4].z = input[5].z = input[6].z = input[7].z = upper.z;
			break;
		case	xoyo	:
		case	xpyp	:
			input[0].z = input[2].z = input[4].z = input[6].z = upper.z;
			input[1].z = input[3].z = input[5].z = input[7].z = lower.z;
			break;
		case	xpyo	:	
		case	xoyp	:
			input[0].z = input[2].z = input[4].z = input[6].z = lower.z;
			input[1].z = input[3].z = input[5].z = input[7].z = upper.z;
			break;
		case	yozo	:
		case	ypzo	:
			input[0].z = input[1].z = input[4].z = input[5].z = lower.z;
			input[2].z = input[3].z = input[6].z = input[7].z = upper.z;
			break;
		case	yozp	:
		case	ypzp	:
			input[0].z = input[1].z = input[4].z = input[5].z = upper.z;
			input[2].z = input[3].z = input[6].z = input[7].z = lower.z;
			break;
		}

	if ( TraceTarget )
		show_ivalues( TraceTarget );
	return;
}

PRIVATE	VOID	calculate_delta_z( int direction )
{
	int	vortex;
	prepare_values(direction);
	for ( vortex=0; vortex < all_vortices; vortex++ ) {
		output[vortex].x = dxdz( vortex, direction );
		output[vortex].y = dydz( vortex, direction );
		}
	return;
}

PRIVATE	VOID	calculate_delta_x( int direction )
{
	int	vortex;
	prepare_values(direction);
	for ( vortex=0; vortex < all_vortices; vortex++ ) {
		output[vortex].x = dydx( vortex, direction );
		output[vortex].y = dzdx( vortex, direction );
		}
	return;
}

PRIVATE	VOID	calculate_delta_y( int direction )
{
	int	vortex;
	prepare_values(direction);
	for ( vortex=0; vortex < all_vortices; vortex++ ) {
		output[vortex].x = dxdy( vortex, direction );
		output[vortex].y = dzdy( vortex, direction );
		}
	return;
}

PRIVATE	VOID	new_apply_background(struct background2d * bptr)
{
	int	i;
	int	align=0;

	if (!( bptr ))
		return;

	i = bptr->style;

	if ((i & _REPEAT_X ) ||  (i & _REPEAT_Y )) {
		align =_I_TILE;
		}

	else if ( i & _MAKE_FIT ) {
		align =_I_MAKEFIT;
		}
	else if ( i & _BEST_FIT ) {
		align =_I_BESTFIT;
		}
	else if ( i & _ALIGN_LEFT ) {
		if ( i & _ALIGN_RIGHT ) {
			align = _A_CENTER;
			}
		else	align = _A_LEFT;
		}

	else if ( i & _ALIGN_RIGHT ) {
		align = _A_RIGHT;
		}
	else	align = _A_NONE;

	filzone(margins.x,margins.y,edge.x-margins.x,edge.y-margins.y,bptr->colour);
	if ( bptr->iname )
		visual_image( margins.x,margins.y,edge.x-margins.x,edge.y-margins.y,bptr->iname,align|_I_QUALITY);
	return;
}

PRIVATE	VOID	old_apply_background(struct background2d * bptr)
{
	int	maxrows;
	int	maxcols;
	int	gratcol;
	int	gratrow;
	int	grnbcol;
	int	grnbrow;
	int	r;
	char *	sptr;

	if (!( bptr ))
		return;

	if ( verbose )
		printf("apply_background(uf=%u lf=%u rf=%u,rp=%u bf=%u,bp=%u s=%x, c=%u)\n",
			bptr->upperfill,bptr->leftfill,
			bptr->rightfill,bptr->fillcolumn,
			bptr->lowerfill,bptr->fillrow,
			bptr->style,bptr->colour );


	if (( bptr->style & _BEST_FIT ) 
	||  ( bptr->style & _MAKE_FIT )) {
		if ( bptr->image ) {
			if ( bptr->image->palette )
				vgapalette(bptr->image->palette,0,256);
			draw_hface(
				margins.x,	margins.y,
				edge.x,		margins.y,
				margins.x,	edge.y,
				edge.x,		edge.y,
				bptr->colour,
				bptr->image );
			if ( bptr->image->palette )
				put_palette();
			return;
			}
		}

	if ( bptr->upperfill ) 
		filzone(margins.x,margins.y,(edge.x-margins.x),bptr->upperfill,bptr->colour);

	if ( bptr->image ) {
		if ( bptr->image->palette )
			vgapalette(bptr->image->palette,0,256);
		for (	r=bptr->imagerow,
			gratrow=(margins.y+bptr->upperfill); 
			gratrow < edge.y; 
			gratrow++ 	) {

			if ( bptr->leftfill ) 
				filzone(margins.x,gratrow,bptr->leftfill,1,bptr->colour);

			if (!(sptr = connect_pixel_row( 
					bptr->image->storage, r )))
				break;

			for (	grnbcol=0,
				gratcol=(margins.x+bptr->leftfill);
				gratcol < edge.x;
				gratcol+= grnbcol ) {

				if ((gratcol + (grnbcol = bptr->image->columns)) > edge.x )
					grnbcol = (edge.x - gratcol);

				putzone( gratcol, gratrow, grnbcol, 1, (sptr+bptr->imagecolumn));

				if (!( bptr->style & _REPEAT_X ))
					break;
	
				}

			if ( bptr->rightfill ) 
				filzone(bptr->fillcolumn,gratrow,bptr->rightfill,1,bptr->colour);

			r++;

			if ( r < bptr->image->rows )
				continue;
			else if (!( bptr->style & _REPEAT_Y ))
				break;
			else	r = 0;

			}
		if ( bptr->image->palette )
			put_palette();
		}

	if ( bptr->lowerfill ) 
		filzone(margins.x,bptr->fillrow,(edge.x-margins.x),bptr->lowerfill,bptr->colour);

	return;


}

PRIVATE	VOID	apply_background(struct background2d * bptr)
{
	if ( camera_image_quality() )
		new_apply_background( bptr );
	else	old_apply_background( bptr );
	return;
}

PUBLIC	VOID	freeze3d(struct background2d * bptr)
{
	hide();
	if ( bptr )
		apply_background(bptr);
	return;
}

PUBLIC	VOID	thaw3d()
{
	while (show(margins.x,margins.y,dimensions.x,dimensions.y)!=0);
	return;
}


PUBLIC	VOID	report3d(FILE * target,	struct object3d 	*optr )
{
	struct descriptor3d * rptr = & optr->descriptor;

	fprintf(target,"Focus  [ %u , %u ]\n",focus.x,focus.y);
	fprintf(target,"Window [ %u , %u ]\n",dimensions.x,dimensions.y);
	fprintf(target,"Margin [ %u , %u ]\n",margins.x,margins.y);

	fprintf(target,"Zone   [ %u , %u ] [ %u , %u ] ",
		rptr->column,rptr->row,
		rptr->width,rptr->height );

	if ( rptr->status & _LEFT_IS_VISIBLE )
		fprintf(target,",Left");
	else if ( rptr->status & _RIGHT_IS_VISIBLE )
		fprintf(target,",Right");

	if ( rptr->status & _UPPER_IS_VISIBLE )
		fprintf(target,",Upper");

	else if ( rptr->status & _LOWER_IS_VISIBLE )
		fprintf(target,",Lower");

	fprintf(target,",Front\n");

	fprintf(target," 2 dimensional Output Coordinates : \n");
	fprintf(target,"[  %5d , %5d  ]---------------------[  %5d , %5d  ]\n",
		rptr->values[0].x,rptr->values[0].y,
		rptr->values[1].x,rptr->values[1].y);
	fprintf(target,"         |         %c                             |         %c\n",0x005C,0x005C);
	fprintf(target,"         |          [  %5d , %5d  ]--------- | ---------[  %5d , %5d  ]\n",
		rptr->values[4].x,rptr->values[4].y,
		rptr->values[5].x,rptr->values[5].y);
	fprintf(target,"         |                   |                   |                   |\n");
	fprintf(target,"[  %5d , %5d  ]---------------------[  %5d , %5d  ]          |\n",
		rptr->values[2].x,rptr->values[2].y,
		rptr->values[3].x,rptr->values[3].y);
	fprintf(target,"                   %c         |                             %c         |\n",0x005C,0x005C);
	fprintf(target,"                    [  %5d , %5d  ]---------------------[  %5d , %5d  ]\n",
		rptr->values[6].x,rptr->values[6].y,
		rptr->values[7].x,rptr->values[7].y);
	return;
}


PUBLIC	int	calculate3d(	
		struct object3d 	*optr, 
		struct coordinate3d 	*cptr,
		int			direction )
{
	int		vortex;
	precision	value;
	struct descriptor3d *	rptr = & optr->descriptor;
	struct coordinate3d *	aptr = & optr->topleft;
	struct coordinate3d *	bptr = & optr->bottomright;

	/* ------------------------------ */
	/* Clear Result control variables */
	/* ------------------------------ */
	rptr->status=rptr->width=rptr->height=rptr->column=rptr->row=0;
	minimum.x = minimum.y = P3D_MAX; maximum.x = maximum.y = P3D_MIN;
		
	/* ----------------------------------------------- */
	/* Set upper and lower of the Coordinates in place */
	/* ----------------------------------------------- */
	if ( aptr->x < bptr->x ) { lower.x = aptr->x; upper.x = bptr->x; }
	else			 { lower.x = bptr->x; upper.x = aptr->x; }
	if ( aptr->y < bptr->y ) { lower.y = aptr->y; upper.y = bptr->y; }
	else			 { lower.y = bptr->y; upper.y = aptr->y; }
	if ( aptr->z < bptr->z ) { lower.z = aptr->z; upper.z = bptr->z; }
	else			 { lower.z = bptr->z; upper.z = aptr->z; }

	/* ------------------- */
	/* Set Camera Location */
	/* ------------------- */
	camera.x = cptr->x;	camera.y = cptr->y;	camera.z = cptr->z;

	/* -------------------------------------------------------- */
	/* Calculate Delta values if the object is visible from the */
	/* camera location 					    */
	/* -------------------------------------------------------- */
	switch ( direction ) {
		case	zpyo		:
		case	zpyp		:
		case	zpxo		:
		case	zpxp		:
			if ( camera.z < upper.z ) {
				calculate_delta_z( direction );
				break;
				}
			else	return(0);

		case	zoyo		:
		case	zoyp		:
		case	zoxo		:
		case	zoxp		:
			if ( camera.z > lower.z ) {
				calculate_delta_z( direction );
				break;
				}
			else	return(0);

		case	ypzo		:
		case	ypzp		:
		case	ypxo		:
		case	ypxp		:
			if ( camera.y < upper.y ) {
				calculate_delta_y( direction );
				break;
				}
			else	return(0);
		case	yozo		:
		case	yozp		:
		case	yoxo		:
		case	yoxp		:
			if ( camera.y > lower.y ) {
				calculate_delta_y( direction );
				break;
				}
			else	return(0);
		case	xpzo		:
		case	xpzp		:
		case	xpyo		:
		case	xpyp		:
			if ( camera.x < upper.x ) {
				calculate_delta_x( direction );
				break;
				}
			else	return(0);
		case	xozo		:
		case	xozp		:
		case	xoyo		:
		case	xoyp		:
			if ( camera.x > lower.x ) {
				calculate_delta_x( direction );
				break;
				}
			else	return(0);
		default			:
			return( 0 );
		}
	
	if ( TraceTarget )
		show_ovalues( TraceTarget );

	/* ----------------------------------------- */
	/* Calculation of maximum and minimum values */
	/* ----------------------------------------- */
	for ( vortex=0; vortex < all_vortices; vortex++ ) {
		if ((value = output[vortex].x) > maximum.x )
			maximum.x = value;
		else if (value < minimum.x)
			minimum.x = value;
		rptr->values[vortex].x = (value + focus.x);
		if ((value = output[vortex].y) > maximum.y )
			maximum.y = value;
		else if (value < minimum.y)
			minimum.y = value;
		rptr->values[vortex].y = (value + focus.y);
		}
	
	/* --------------------------------------------- */
	/* Calculation of result dimensions and position */
	/* --------------------------------------------- */
	rptr->column = 0;
	rptr->row    = 0;
	rptr->width  = ((maximum.x - minimum.x)+1);
	rptr->height = ((maximum.y - minimum.y)+1);

	/* Front is always visible and Back is Never visible */
	/* ------------------------------------------------- */

	if ( rptr->values[4].x < rptr->values[0].x ) {
		rptr->status |= _LEFT_IS_VISIBLE;
		rptr->column = rptr->values[4].x;
		}
	else 	{
		rptr->column = rptr->values[0].x;
		if ( rptr->values[5].x > rptr->values[1].x )
			rptr->status |= _RIGHT_IS_VISIBLE;
		}

	if ( rptr->values[4].y < rptr->values[0].y ) {
		rptr->status |= _UPPER_IS_VISIBLE;
		rptr->row = rptr->values[4].y;
		}
	else 	{
		rptr->row = rptr->values[0].y;
		if ( rptr->values[6].y > rptr->values[2].y )
			rptr->status |= _LOWER_IS_VISIBLE;
		}
	
	rptr->status |= _FRONT_IS_VISIBLE;

	return( rptr->status );

}

PUBLIC	void	adjust3d(	
		struct object3d 	*optr, 
		struct coordinate3d 	*cptr,
		int			xadjust,
		int			yadjust,
		int			zadjust,
		int			direction )
{
	struct descriptor3d *	rptr = & optr->descriptor;
	struct coordinate3d *	aptr = & optr->topleft;
	struct coordinate3d *	bptr = & optr->bottomright;
	int			xfactor;
	int			yfactor;
	int			zfactor;

	/* Ensure Object Calculations Performed */
	/* ------------------------------------ */
	calculate3d( optr, cptr, direction );

	if ( xadjust ) {
		xfactor = 	( 	
			(bptr->x - aptr->x) 
				/ 
			(rptr->values[1].x - rptr->values[0].x)
			);
		}
	else	xfactor = 1;

	if   (( yadjust )
	&&    ((rptr->values[3].y - rptr->values[1].y ) != 0)) {
		yfactor = 	( 	
			(bptr->y - aptr->y) 
				/ 
			(rptr->values[3].y - rptr->values[1].y)
			);
		}
	else	yfactor = 1;

	zfactor = 1;

	switch ( direction ) {

		case	zoyo:	/*	forward		*/
				/*    X += x , Y += Y	*/

			aptr->x += (xadjust * xfactor);
			bptr->x += (xadjust * xfactor);
			aptr->y += (yadjust * yfactor);
			bptr->y += (yadjust * yfactor);
			aptr->z -= (zadjust * zfactor);
			bptr->z -= (zadjust * zfactor);
			break;

		case	zpyo:	/*	backward	*/
				/*    X -= x , Y += Y	*/

			aptr->x -= (xadjust * xfactor);
			bptr->x -= (xadjust * xfactor);
			aptr->y += (yadjust * yfactor);
			bptr->y += (yadjust * yfactor);
			aptr->z += (zadjust * zfactor);
			bptr->z += (zadjust * zfactor);
			break;

		case	yozo:	/*	up		*/
				/*    X += x , Z -= Y	*/

			aptr->x += (xadjust * xfactor);
			bptr->x += (xadjust * xfactor);
			aptr->z -= (yadjust * yfactor);
			bptr->z -= (yadjust * yfactor);
			aptr->y += (zadjust * zfactor);
			bptr->y += (zadjust * zfactor);
			break;

		case	ypzo:	/*	down		*/
				/*    X += x , Z += Y	*/

			aptr->x += (xadjust * xfactor);
			bptr->x += (xadjust * xfactor);
			aptr->z += (yadjust * yfactor);
			bptr->z += (yadjust * yfactor);
			aptr->y -= (zadjust * zfactor);
			bptr->y -= (zadjust * zfactor);
			break;

		case	xoyo:	/*	left		*/
				/*    Z -= x , Y += Y	*/

			aptr->z -= (xadjust * xfactor);
			bptr->z -= (xadjust * xfactor);
			aptr->y += (yadjust * yfactor);
			bptr->y += (yadjust * yfactor);
			aptr->x -= (zadjust * zfactor);
			bptr->x -= (zadjust * zfactor);
			break;

		case	xpyo:	/*	right		*/
				/*    Z += x , Y += Y	*/
	
			aptr->z += (xadjust * xfactor);
			bptr->z += (xadjust * xfactor);
			aptr->y += (yadjust * yfactor);
			bptr->y += (yadjust * yfactor);
			aptr->x += (zadjust * zfactor);
			bptr->x += (zadjust * zfactor);
			break;
		}

	calculate3d( optr, cptr, direction );

	return;	
}

PUBLIC	VOID	erase3d(	struct object3d 	*optr )
{
	int	atc;
	int	atr;
	int	nbc;
	int	nbr;
	struct descriptor3d * rptr = & optr->descriptor;

	return;

	if ( rptr->status ) {

		if ((atc = rptr->column) < margins.x)
			atc = margins.x;
		else if ( atc > edge.x )
			return;
		if ((atr = rptr->row   ) < margins.y)
			atr = margins.y;
		else if ( atr > edge.y )
			return;
		if (((nbc = rptr->width) + atc) >= edge.x)
			nbc = (edge.x - atc);
		if (((nbr = rptr->height) + atr) >= edge.y)
			nbr = (edge.y - atr);
			
		if (( nbc > 0 ) && ( nbr  > 0 ))
			filzone( atc, atr, nbc ,nbr, optr->colours.back );
	
		}

	return;
}		

static	void	lock_gsd( char * lptr )
{
	return;
}
	
static	void	unlock_gsd( char * lptr )
{
	return;
}
	
PUBLIC	struct standard_image * uncheck_process( 
		struct standard_process * pptr,
		struct	standard_image * iptr	 )
{
	if ( pptr->gsd )
		unlock_gsd( pptr->gsd );

	iptr->storage = liberate_process_storage( iptr->storage );
	iptr->rows = iptr->columns = 0;
	pptr->mode = -1;
	pptr->gsd  = pptr->access   = (char *) 0;
	pptr->identity = (int *)0;
	pptr->serial   = 0;
	return( (struct standard_image * ) 0 );
}

PUBLIC	struct standard_image * build_process( 
		struct standard_process * pptr,
		struct	standard_image * iptr	 )
{
	void *	vptr=(void *) 0;

	/* Connect to Graphics Descriptor of the Required Post */
	/* --------------------------------------------------- */
	if ((pptr->mode = share_psu( pptr->id, & vptr, &pptr->access, &pptr->gsd )) != -1) {

		if ( pptr->gsd )
			lock_gsd( pptr->gsd );

		if (( pptr->access != (char *) 0 )
		&&  ( *(pptr->access+19) != 0 )) {
			pptr->identity = (int *) ((char *)pptr->access +16);
			pptr->serial   = *pptr->identity;
			}
		else	{
			pptr->identity = (int *)0;
			pptr->serial   = 0;
			}
		switch (pptr->mode) {
			case	0 :
				iptr->columns 	= 320;
				iptr->rows 	= 200;
				break;
			case	1 :
				iptr->columns 	= 640;
				iptr->rows 	= 400;
				break;
			case	2 :
				iptr->columns 	= 640;
				iptr->rows 	= 480;
				break;
			case	3 :
				iptr->columns 	= 800;
				iptr->rows 	= 600;
				break;
			case	4 :
				iptr->columns 	= 1024;
				iptr->rows 	= 768;
				break;
			case	5 :
				iptr->columns 	= 1280;
				iptr->rows 	= 1024;
				break;
			default	:
				iptr->columns = iptr->rows = 0;
			}

		if (( iptr->rows    )
		&&  ( iptr->columns ))
			if ((iptr->storage = 
				allocate_process_storage(
					iptr->columns,
					iptr->rows,
					vptr )))
				return( iptr );

		if ( pptr->gsd )
			unlock_gsd( pptr->gsd );
		}
	return( (struct standard_image * ) 0 );
}

PUBLIC	struct standard_image * check_process( struct standard_process * pptr )
{
	char	gbuffer[32];
	int	status;
	void *	vptr=(void *) 0;
	struct	standard_image * iptr;

	if (!( iptr = pptr->image ))
		return(iptr);

	if (!( iptr->rows ))

		return( build_process( pptr, iptr ) );

	if ( pptr->gsd )
		lock_gsd( pptr->gsd );

	if (( iptr->storage ) 
	&&  ( pptr->access  )) {

		if (!( *(pptr->access+19) )) {
			/* Access has been lost */
			if ( verbose )
				printf("failure *(pptr->access+1)=%u\n",*(pptr->access+1));
			return( uncheck_process( pptr, iptr ) );
			}
		else if (!( pptr->identity )) {
			/* Access has been lost */
			if ( verbose )
				printf("failure pptr->identity NULL\n");
			return( uncheck_process( pptr, iptr ) );
			}
		else if ( *pptr->identity != pptr->serial ) {
			if ( verbose )
				printf("failure serial change %u != %u \n",*pptr->identity,pptr->serial);
			(void) uncheck_process( pptr, iptr );
			return( build_process( pptr, iptr ) );
			}
		else if (!( vptr = check_psu( iptr->storage->root ) )) {
			if ( verbose )
				printf("failure invalid psu\n");
			return( uncheck_process( pptr, iptr ) );
			}
		else if (( iptr->rows    != 0 )
		     &&  ( iptr->columns != 0 ))
			return(iptr);
		}

	if ( pptr->gsd )
		unlock_gsd( pptr->gsd );
	return( (struct standard_image * ) 0 );
}


PUBLIC	VOID	display3d(	struct object3d 	*optr )
{
	int	i;
	struct	descriptor3d   * rptr = & optr->descriptor;
	struct	standard_image * iptr = (struct standard_image *) 0;
	if ( rptr->status ) {
		if ( optr->process )
			iptr = check_process( optr->process );
		if ( rptr->status & _UPPER_IS_VISIBLE ) {
			if ( verbose )
				printf(" Upper: ");
		/* draw_hface( */
			draw_face(
				rptr->values[4].x, rptr->values[4].y,
				rptr->values[5].x, rptr->values[5].y,
				rptr->values[0].x, rptr->values[0].y,
				rptr->values[1].x, rptr->values[1].y,
				( iptr ? _UPPER_COLOUR : optr->colours.upper ),
				( iptr ? iptr : optr->image )
				);
			}
		else if ( rptr->status & _LOWER_IS_VISIBLE ) {
			if ( verbose )
				printf(" Lower: ");
		/* draw_hface( */
			draw_face(
				rptr->values[2].x, rptr->values[2].y,
				rptr->values[3].x, rptr->values[3].y,
				rptr->values[6].x, rptr->values[6].y,
				rptr->values[7].x, rptr->values[7].y,
				( iptr ? _LOWER_COLOUR : optr->colours.lower ),
				( iptr ? iptr : optr->image )
				);
			}
		if ( rptr->status & _LEFT_IS_VISIBLE ) {
			if ( verbose )
				printf(" Left : ");
		/* draw_vface( */
			draw_face(
				rptr->values[4].x, rptr->values[4].y,
				rptr->values[0].x, rptr->values[0].y,
				rptr->values[6].x, rptr->values[6].y,
				rptr->values[2].x, rptr->values[2].y,
				( iptr ? _LEFT_COLOUR : optr->colours.left ),
				( iptr ? iptr : optr->image )
				);
			}
		else if ( rptr->status & _RIGHT_IS_VISIBLE ) {
			if ( verbose )
				printf(" Right: ");
		/* draw_vface( */
			draw_face(
				rptr->values[1].x, rptr->values[1].y,
				rptr->values[5].x, rptr->values[5].y,
				rptr->values[3].x, rptr->values[3].y,
				rptr->values[7].x, rptr->values[7].y,
				( iptr ? _RIGHT_COLOUR : optr->colours.right ),
				( iptr ? iptr : optr->image )
				);
			}

		if ( rptr->status & _FRONT_IS_VISIBLE ) {
			if ( verbose )
				printf(" Front: ");
			/* draw_hface( */
			draw_face(
				rptr->values[0].x, rptr->values[0].y,
				rptr->values[1].x, rptr->values[1].y,
				rptr->values[2].x, rptr->values[2].y,
				rptr->values[3].x, rptr->values[3].y,
				( iptr ? _FRONT_COLOUR : optr->colours.front ),
				( iptr ? iptr : optr->image )
				);
			}
		if (( optr->process )
		&&  ( optr->process->gsd ))
			unlock_gsd( optr->process->gsd );
		}

	return;
}

PUBLIC	int	set3dfocus( int x, int y )
{
	int	w = (dimensions.x + (margins.x * 2));
	int	h = (dimensions.y + (margins.y * 2));
	focus.x = w/2;
	focus.y = h/2;
	if ((focus.x + x) > edge.x)
		focus.x = edge.x;
	else if ((focus.x + x) < margins.x)
		focus.x = margins.x;
	else	focus.x += x;
	if ((focus.y + y) > edge.y)
		focus.y = edge.y;
	else if ((focus.y + y) < margins.y)
		focus.y = margins.y;
	else	focus.y += y;
	return;
}

PRIVATE	void	reset_fill_control(struct background2d * bptr )
{
	bptr->imagecolumn  = bptr->imagerow   = 0;
	bptr->leftfill	   = bptr->upperfill  = 0;
	bptr->lowerfill	   = bptr->fillrow    = 0;
	bptr->rightfill	   = bptr->fillcolumn = 0;
	return;
}


PUBLIC	int	prepare_background( struct background2d * bptr )
{

	int	gh,gw,n;

	reset_fill_control(bptr);

	/* Detect Image File Name and Succesful Image Loading */
	/* -------------------------------------------------- */
	if (!( bptr->iname)) {
		bptr->style = 0;
		bptr->image = (struct standard_image *) 0;
		bptr->upperfill=(edge.y-margins.y);
		return(0);
		}
	else if (!( bptr->image )) 
		bptr->image = image_loader( bptr->iname );


	if ( bptr->image != (struct standard_image *) 0) {

		/* Set and Use Alignment Options */
		/* ----------------------------- */
		if ((!( bptr->style & _MAKE_FIT ))
		&&  (!( bptr->style & _BEST_FIT ))) {

			if (!( bptr->style & _REPEAT_Y )) {

				/* No Y direction repetition */
				/* ------------------------- */
				gh = (edge.y - margins.y);
				if ( gh > bptr->image->rows ) {
					n = (gh - bptr->image->rows);
					if ( bptr->style & _ALIGN_TOP )
						bptr->upperfill = 0;
					else if ( bptr->style & _ALIGN_BOTTOM )
						bptr->upperfill = n;
					else	bptr->upperfill = (n/2);
					if ((bptr->lowerfill = (n-bptr->upperfill)) > 0)
						bptr->fillrow = (margins.y+bptr->upperfill+bptr->image->rows);
					}
				else	{
					n = (bptr->image->rows - gh);
					if ( bptr->style & _ALIGN_TOP )
						bptr->imagerow = 0;
					else if ( bptr->style & _ALIGN_BOTTOM )
						bptr->imagerow = n;
					else	bptr->imagerow = (n/2);
					}
				}
			else	{ bptr->upperfill = bptr->lowerfill=0; }
				if (!( bptr->style & _REPEAT_X )) {

				/* No X direction repetition */
				/* ------------------------- */
				gw = (edge.x - margins.x);
				if ( gw > bptr->image->columns ) {
					n = (gw - bptr->image->columns);
					if ( bptr->style & _ALIGN_LEFT )
						bptr->leftfill = 0;
					else if ( bptr->style & _ALIGN_RIGHT )
						bptr->leftfill = n;
					else	bptr->leftfill = (n/2);
					if ((bptr->rightfill = (n-bptr->leftfill)) > 0)
						bptr->fillcolumn = (margins.x+bptr->leftfill+bptr->image->columns);
					}
				else	{
					n = (bptr->image->columns - gw);
					if ( bptr->style & _ALIGN_LEFT )
						bptr->imagecolumn = 0;
					else if ( bptr->style & _ALIGN_RIGHT )
						bptr->imagecolumn = n;
					else	bptr->imagecolumn = (n/2);
					}	
				}
			else	{ bptr->rightfill = bptr->leftfill=0; }
			} /* ! makefit */
		}
	else	{
		bptr->image = (struct standard_image *) 0;
		bptr->upperfill=(edge.y-margins.y);
		}
	return(0);
}

PUBLIC	int 	calibrate3d( int mode, int lmargin, int tmargin, int rmargin,char * palette )
{
	switch ( mode ) {
		case	0 :
			dimensions.x = 320;	dimensions.y = 200;
			break;
		case	1 :
			dimensions.x = 640;	dimensions.y = 400;
			break;
		case	2 :
			dimensions.x = 640;	dimensions.y = 480;
			break;
		case	-1:
		case	3 :
			dimensions.x = 800;	dimensions.y = 600;
			break;
		case	4 :
			dimensions.x = 1024;	dimensions.y = 768;
			break;
		case	5 :
			dimensions.x = 1280;	dimensions.y = 1024;
			break;
		case	7	:
			dimensions.x = get_bioswidth();
			dimensions.y = get_biosheight();
			break;
		default	:
			return(0);
		}

	focus.x = dimensions.x / 2;
	focus.y = dimensions.y / 2;
	margins.x    = lmargin;	margins.y    = tmargin;
	if (!( rmargin ))
		dimensions.x -= (margins.x * 2);
	else	dimensions.x  = (rmargin - lmargin);
	dimensions.y -= (margins.y * 2);
	edge.x = (dimensions.x + margins.x);
	edge.y = (dimensions.y + margins.y);

	ceiling.upperfill 	= 
	background.upperfill 	= foreground.upperfill 	= 
	leftwall.upperfill 	= rightwall.upperfill 	= 
	floor.upperfill 	= (edge.y-margins.y);

	return(1);
}

PUBLIC	int 	initialise3d( int mode, int lmargin, int tmargin, char * palette )
{

	if (!( calibrate3d(mode, lmargin, tmargin,0, palette ) ))
		return(0);

	if ( verbose ) {
		printf("initialise3d( mode=%u, top=%u, left=%u)\n",mode,tmargin,lmargin);
		printf("focus3d(x=%u,y=%u)\n",focus.x,focus.y);
		printf("edge3d(x=%u,y=%u)\n",edge.x,edge.y);
		printf("dimensions3d(x=%u,y=%u)\n",dimensions.x,dimensions.y);
		printf("margins3d(x=%u,y=%u)\n",margins.x,margins.y);
		if ( palette )
			printf("palette3d(%s)\n",palette);
		}

	if ( mode != -1 ) {

		initialise_for_gui(mode|256);
		initialise_mouse();

		/* Detect and Load Explicite Palette */
		/* --------------------------------- */
		if ( palette )	load_palette( palette );

		(void) freeze3d((struct background2d *) 0);
		if (( margins.x > 0 )
		&&  ( margins.y > 0 )
		&&  ( dimensions.x > 0 )
		&&  ( dimensions.y > 0 )) {
			filzone( margins.x, margins.y,dimensions.x,dimensions.y,facecolour.back);
			filzone( margins.x-1, margins.y-1,dimensions.x+2,1,facecolour.shadow);
			filzone( margins.x-1, margins.y-1,1,dimensions.y+2,facecolour.shadow);
			filzone( margins.x+dimensions.x, margins.y-1,1,dimensions.y+2,facecolour.light);
			filzone( margins.x-1,margins.y+dimensions.y,dimensions.x+2,1,facecolour.light);
			}
		(void) thaw3d();

		}

	return(1);
}

PRIVATE	VOID	release_background( struct background2d * bptr )
{
	if ( bptr->iname )
		bptr->iname = drop_string( bptr->iname );
	if ( bptr->image )
		bptr->image = drop_image( bptr->image );
	return;
}

PUBLIC	VOID	liberate3d()
{
	terminate_mouse();
	release_background(&background);
	release_background(&foreground);
	release_background(&leftwall);
	release_background(&rightwall);
	release_background(&ceiling);
	release_background(&floor);
	liberate_for_gui();
	return;
}

PUBLIC	VOID	set_trace_target( fptr )
	FILE *	fptr;
{
	TraceTarget = fptr;
	return;
}

PUBLIC	int	coverage2d( optr, tptr, aptr )
	struct	descriptor3d * optr;
	struct	descriptor3d * tptr;
	struct	area2d *       aptr;
{
	int	tmaxc=(tptr->column+tptr->width);
	int	omaxc=(optr->column+optr->width);
	int	tmaxr=(tptr->row+tptr->height);
	int	omaxr=(optr->row+optr->height);

	if ((optr->column >=  tptr->column)
	&&  (optr->column <   tmaxc       ))
		aptr->start.x = optr->column;
	else if ((tptr->column >=  optr->column )
 	     &&  (tptr->column <   omaxc	))
		aptr->start.x = tptr->column;
	else	return(0);


	if ((optr->row >=  tptr->row)
	&&  (optr->row <   tmaxr    ))
		aptr->start.y = optr->row;
	else if ((tptr->row >=  optr->row)
 	     &&  (tptr->row <   omaxr    ))
		aptr->start.y = tptr->row;
	else	return(0);

	if ( omaxc < tmaxc )
		aptr->finish.x = omaxc;
	else	aptr->finish.x = tmaxc;

	if ( omaxr < tmaxr )
		aptr->finish.x = omaxr;
	else	aptr->finish.x = tmaxr;

	return(1);

}


#endif	/* _three_d_c */
	/* ---------- */

