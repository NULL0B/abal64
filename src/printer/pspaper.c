#ifndef	_pspaper_c
#define	_pspaper_c


/*
 *	Calculation of the total number of dots that may be 
 *	printed due to the requested paper size, A4 -> A1
 *	and the requested dots per inch resolution 75 -> 1200.
 */

int	PaperWidth=0;
int	PaperHeight=0;
int	DotsPerInch=0;

static	int	paper_dimensions[6][5] = {
	595,	842,	1191,	1684,	2384,	/*   75 dpi  	*/
	778,	1096,	1556,	2192,	3116,	/*  100 dpi	*/
	1191,	1684,	2384,	3368,	4768,	/*  150 dpi	*/
	2384,	3368,	4768,	6736,	9536,	/*  300 dpi	*/
	4768,	6736,	9536,	13672,	19062,	/*  600 dpi	*/
	9536,	13672,	19062,	27344,	38124	/* 1200 dpi	*/
	};

int	set_paper_dimensions(int dpi, int papertype )
{
	switch ((DotsPerInch=dpi)) {
		case	  75 	: dpi = 0; break;
		case	 100	: dpi = 1; break;
		case	 150	: dpi = 2; break;
		case	 300	: dpi = 3; break;
		case	 600	: dpi = 4; break;
		case	1200	: dpi = 5; break;
		default		:
			if ( dpi < 100 )	return(set_paper_dimensions(75,papertype));
			else if ( dpi < 150 )	return(set_paper_dimensions(100,papertype));
			else if ( dpi < 300 )	return(set_paper_dimensions(150,papertype));
			else if ( dpi < 600 )	return(set_paper_dimensions(300,papertype));
			else if ( dpi < 1200 )	return(set_paper_dimensions(600,papertype));
			else			return(set_paper_dimensions(1200,papertype));
		}
	PaperWidth  = paper_dimensions[dpi][papertype];
	PaperHeight = paper_dimensions[dpi][papertype+1];
}

#endif	/* _pspaper_c */
	/* -------- */


