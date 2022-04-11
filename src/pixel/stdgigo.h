#ifndef	_stdgigo_h
#define _stdgigo_h

#define	_ABAL_DTI	/* Dominique Talfumier Informatique : Direction : Hebrew */

#include <stdio.h>
#include "pixel.h"
#include "stdcursor.h"

#ifndef PIXIBYTE
#define PIXIBYTE char
#endif

#define	_ESC_normal	0	/* awaiting  escape character */
#define	_ESC_active	1	/* awaiting escaped character */
#define	_ESC_parameter 	2	/* awaiting 1st parameter     */
#define	_ESC_special   	3	/* awaiting 2nd parameter     */
#define	_ESC_transfer  	4	/* performing transparent T   */

#ifdef	_ABAL_DTI
#define	_GIGO_R2L	1	/* direction : right to left  */
#define	_GIGO_B2T	2	/* direction : bottom to top  */
#define	_GIGO_L2RT2B	0			/* Mode zero : default */
#define	_GIGO_R2LT2B	_GIGO_R2L		/* Mode 1    : hebrew  */
#define	_GIGO_L2RB2T	_GIGO_B2T		/* Mode 2    : upwards */
#define	_GIGO_R2LB2T	(_GIGO_R2L | _GIGO_B2T)	/* Mode 3    : reverse */
#endif

#define	_GIGO_BLINK		0
#define	_GIGO_UNDERLINE		1
#define	_GIGO_HIGHLIGHT		2
#define	_GIGO_SHADOW		4
#define	_GIGO_ITALIC		8
#define	_GIGO_UPPER		16
#define	_GIGO_LOWER		32
#define	_GIGO_LOWLIGHT		64
#define	_GIGO_COMPRESSED 	128
#define	_GIGO_PREFERRED  	256
#define	_GIGO_CURSOR_COLOUR	0x00FE

#define	_GIGO_OVERLINE		512
#define	_GIGO_STRIKE		1024

/* ------------------------------------------------------------ */
/* These bit values control the various ATB(21) etc functions 	*/
/* and may be program consulted and controlled		      	*/
/* The working value is stored in Gigo.acontrol			*/
/* ------------------------------------------------------------ */
#define	_GIGO_CLEAR_EOP		1
#define	_GIGO_CLEAR_EOL		2
#define	_GIGO_INSERT_LINE	4
#define	_GIGO_DELETE_LINE	8
#define	_GIGO_INSERT_CHAR	16
#define	_GIGO_DELETE_CHAR	32
#define	_GIGO_HARD_COPY		64
/* ------------------------------------------------------------ */

#define	SHADOWX	Gigo.ShadowX	/* was just 2  */
#define	SHADOWY	Gigo.ShadowY 	/* was just 2  */
#define	SHADOWFG Gigo.ShadowFg	/* was just 19 */

#include "stdfmf.h"

struct	gigo_manager	{

	int	cursorstyle;		/* text cursor form BLOCK/LINE etc	*/
	int	cursorcolour;		/* text cursor form BLOCK/LINE etc	*/
	int	foreground;		/* foreground , character colour code	*/
	int	background;		/* background	colour code		*/
	int	washground;		/* background	colour code		*/
	int	fg;			/* foreground , character colour copy	*/
	int	bg;			/* background	colour copy		*/
	int	atribut;		/* atribut bit mask			*/
	int	scrolling;		/* scrolling or paging			*/
	int	column;			/* current curser column position	*/
	int	line;			/* current curser line position		*/
	int	columns;		/* total number of columns for basefont */
	int	lines;			/* number of lines for base font	*/

	int	width;			/* Pixel Graphic Width			*/
	int	height;			/* Pixel Graphic Height in Rows		*/

	int	letter_spacing;		/* allows letters to be spaced out	*/
	int	line_spacing;		/* allows lines to be spaced out	*/

	int	tracing;		/* trace mechanism activation		*/
	int	cursing;		/* Text Cursor State			*/
	int	escapestate;		/* escape mechanism state		*/
	int	escapecharacter;	/* escaped character code		*/
	int	escapeparameter;	/* the first parameter			*/
	int	escapetransfer;		/* esc T transfer count			*/
	int	currentfont;		/* current base font id			*/
	int	workingfont;		/* current base font id			*/
	int	xmargin;		/* current base font id			*/
	int	ymargin;		/* current base font id			*/
	int	xfontwidth;		/* current base font id			*/
	int	yfontheight;		/* current base font id			*/
	int	fontwidth;		/* the base font overall width		*/
	int	fontheight;		/* and height for quick positioning	*/
	unsigned char painter[32];	/* Specialised paint colours		*/

	/* margin indentation values */ 
	int	topmargin;
	int	rightmargin;
	int	bottommargin;
	int	leftmargin;
	int	C_FORE;
	int	C_BACK;
	int	acontrol;		/* atribut controller			 	*/
	char 		      *fontnames[MAX_FONTS];		/* The font names 	*/
	struct  standard_font * graphicfonts[MAX_FONTS];	/* The font bytes 	*/
	int	flushall;

	int	use_altmap;		/* Alt Key Conversion Table active	*/
	char	altmap[256];		/* Alt Key Conversion Table Data	*/

	int	thisevent;		/* current event type for mimo event detection	*/
	int	hqfontid;		/* alternative hq font for printing ?		*/
#ifdef	_ABAL_DTI
	int	direction;		/* left to right to left top to bottom to top	*/
					/* Default value : 0 : L2R,T2B			*/
					/*                 1 : R2L,T2B			*/
					/*                 2 : L2R,B2T			*/
					/*                 3 : R2L,B2T			*/
	unsigned char reflection[256];
#endif
	int	ShadowX;
	int	ShadowY;
	int	ShadowFg;
	int	replaying;
	};

#ifdef	_stdgigo_c
	struct	gigo_manager	Gigo;
#else
extern	struct	gigo_manager	Gigo;
#endif

#endif	/* _stdgigo_h */

