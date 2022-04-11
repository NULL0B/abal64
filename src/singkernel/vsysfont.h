#ifndef	_vsysfont_h
#define	_vsysfont_h

/*	----------------------------------------------------------------------		*/
/*	This file is an inclusion for the system font manager visual interfaceitem		*/
/*	----------------------------------------------------------------------		*/

static	struct	system_font_memory	{
	char  * foundry;
	int	family;
	int	weight;
	int	slant;
	int	setwidth;
	int	pixels;
	int	points;
	int	hresdpi;
	int	vresdpi;
	int	spacing;
	int	average;
	char *	charset;
	} SysFontMem = { 
		(char *) 0,
		0,0,0,0,0,0,0,0,0,0,
		(char *) 0
		};

#endif	/* _vsysfont_h */
	/* ----------- */

