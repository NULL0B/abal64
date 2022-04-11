#ifndef	_three_d_h
#define	_three_d_h

/*	Definition of various types		*/
/*	---------------------------		*/

#undef 	TRACE_3D_CALCULATIONS

#ifdef	P3D8
#define	precision	char
#define	P3D_MAX       0x007F
#define	P3D_MIN       0x0080
#define	P3D_ZERO	0
#else
#ifdef	P3D16
#define	precision	short int
#define	P3D_MAX       0x7FFF
#define	P3D_MIN       0x8000
#define	P3D_ZERO	0
#else
#ifdef	P3D32
#define	precision	long int
#define	P3D_MAX       0x7FFFFFFFL
#define	P3D_MIN       0x80000000L
#define	P3D_ZERO	0L
#else
include this is a deliberate error due to incorrect precision value
#endif
#endif
#endif

#define	VOID		void

#ifndef	PRIVATE
#define	PRIVATE		static
#endif

#ifndef	PUBLIC
#define	PUBLIC
#endif

/*	Direction Constants (they are all here now) Including Rotations  */
/*	------------------------------------------- -------------------  */

#define	zoyo	 0
#define	zpyo	 1
#define	xoyo	 2
#define	xpyo	 3
#define	yozo	 4
#define	ypzo	 5
#define	zoyp	 6
#define	zpyp	 7
#define	xoyp	 8
#define	xpyp	 9
#define	yozp	10
#define	ypzp	11
#define	zoxo	12
#define	zpxo	13
#define	xozo	14
#define	xpzo	15
#define	yoxo	16
#define	ypxo	17
#define	zoxp	18
#define	zpxp	19
#define	xozp	20
#define	xpzp	21
#define	yoxp	22
#define	ypxp	23

#define	all_directions 24
#define	all_vortices	8

struct	colour3d	{
	int	front;
	int	back;
	int	left;
	int	right;
	int	upper;
	int	lower;
	int	light;
	int	shadow;
	};


struct	coordinate2d	{
	precision	x;
	precision	y;
	};

struct	area2d	{
	struct	coordinate2d start;
	struct	coordinate2d finish;
	};

struct	paint3d	{
	int		count;
	int		position;
	int		colour;
	};

struct	coordinate3d	{
	precision 	x;
	precision 	y;
	precision	z;
	};

struct	descriptor3d {
	int		status;
	int		column;
	int		row;
	int		width;
	int		height;
	struct coordinate2d	values[all_vortices];
	};

#include "process.h"

struct	object3d	{

	struct coordinate3d topleft;
	struct coordinate3d bottomright;
	struct descriptor3d descriptor;
	struct colour3d	    colours;

	struct	texture *   		texture;
	struct	standard_image *   	image;
	struct	standard_process *	process;

	void			 *	payload;
	void 			 *   	host;
	int				nature;
	int				options;

	char		*   name;	/* For identification 		  */
	char		*   iname;	/* For identification 		  */

	struct object3d	*   previous;	/* Previous object in camera list */
	struct object3d	*   next;	/* Next object in camera list	  */
	struct object3d	*   before;	/* Objects displayed before	  */
	struct object3d	*   after;	/* Objects to be displayed after  */
	int		atrow;

	int		special;

	};

struct	background2d	{
	char		      * iname;
	struct standard_image * image;
	int			style;
	int			upperfill;
	int			lowerfill;
	int			leftfill;
	int			rightfill;
	int			fillcolumn;
	int			fillrow;
	int			imagecolumn;
	int			imagerow;
	int			colour;
	};


#define	_RIGHT_IS_VISIBLE		0x0001
#define	_LOWER_IS_VISIBLE		0x0002
#define	_UPPER_IS_VISIBLE		0x0004
#define	_LEFT_IS_VISIBLE		0x0008
#define	_FRONT_IS_VISIBLE		0x0010
#define	_BACK_IS_VISIBLE		0x0020
#define	_SHADOW_IS_VISIBLE		0x0040
#define	_LIGHT_IS_VISIBLE		0x0080

/*	Public function Prototypes 	*/
/*	--------------------------	*/
PUBLIC	int	initialise3d( int , int, int, char * );
PUBLIC	int	calculate3d( struct object3d *, struct coordinate3d *, int);
PUBLIC	VOID	erase3d( struct object3d * );
PUBLIC	VOID	display3d( struct object3d * );
PUBLIC	int	coverage2d( struct descriptor3d *, struct descriptor3d *, struct area2d * );

#endif	/* _three_d_h */
	/* ---------- */


