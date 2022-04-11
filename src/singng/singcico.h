#ifndef	_singcico_h
#define _singcico_h


#define	_GIGO_CURSOR_BLOCK	1
#define	_GIGO_CURSOR_VLINE	2
#define	_GIGO_CURSOR_HLINE	3
#define	_GIGO_CURSOR_OUTLINE	4

#define	_ESC_normal	0	/* awaiting  escape character */
#define	_ESC_active	1	/* awaiting escaped character */
#define	_ESC_parameter 	2	/* awaiting 1st parameter     */
#define	_ESC_special   	3	/* awaiting 2nd parameter     */
#define	_ESC_transfer  	4	/* performing transparent T   */

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

#define	SHADOWX	2
#define	SHADOWY	2
#define	SHADOWFG	19


struct	gigo_manager	{
	int	cursorstyle;		/* text cursor form BLOCK/LINE etc	*/
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

	int	tracing;		/* trace mechanism activation		*/
	int	cursing;		/* Text Cursor State			*/
	int	escapestate;		/* escape mechanism state		*/
	int	escapecharacter;	/* escaped character code		*/
	int	escapeparameter;	/* the first parameter			*/
	int	escapetransfer;		/* esc T transfer count			*/
	int	currentfont;		/* current base font id			*/
	int	fontwidth;		/* the base font overall width		*/
	int	fontheight;		/* and height for quick positioning	*/
	unsigned char painter[32];	/* Specialised paint colours		*/

	/* margin indentation values */ 
	int	topmargin;
	int	rightmargin;
	int	bottommargin;
	int	leftmargin;

	char *	rbuffer;

	};




#endif	/* _singcico_h */

