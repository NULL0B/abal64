#ifndef	_paper_c
#define	_paper_c


/*	---------------------------------------------------------	*/
/*		p a p e r _ d i m e n s i o n s 			*/
/*	---------------------------------------------------------	*/
/*									*/
/*	This table provides the various stndard paper size values	*/
/*	for the full A and B ranges for 75dpi				*/
/*	Values for other print resolutions may be calculated		*/
/*									*/
/*		150	* 	2					*/
/*		100	*	2	/	3			*/
/*		300	*	4					*/
/*		600	*	8					*/
/*		1200	*	16					*/
/*									*/
/*	---------------------------------------------------------	*/
static	char *	paper_name[] = {
	"A10","A9","A8","A7","A6","A5","A4","A3","A2","A1","A0",
	"B10","B9","B8","B7","B6","B5","B4","B3","B2","B1","B0"
	};

static	int	paper_dimensions[24] = {

/*	---------------------------------------------			*/
/*	A10	A9	A8	A7	A6	A5			*/
/*	---------------------------------------------			*/
	73,	105,	148,	210,	297,	420,

/*	---------------------------------------------			*/
/*	A4	A3	A2	A1	A0				*/
/*	---------------------------------------------			*/
	595,	842,	1191,	1684,	2384,	3370,	


/*	---------------------------------------------			*/
/*	B10	B9	B8	B7	B6	B5			*/
/*	---------------------------------------------			*/
	91,	127,	181,	258,	363,	516,

/*	---------------------------------------------			*/
/*	B4	B3	B2	B1	B0				*/
/*	---------------------------------------------			*/
	729,   1032,	1460,	2064,	2920,	4127	

	};


int	PaperType=0;
char *	PaperName="A4";
int	PaperWidth=0;
int	PaperHeight=0;
int	DotsPerInch=0;

char *	get_paper_name()	{	return( PaperName );	}

int	set_paper_dimensions(int dpi, int papertype )
{
	int	pagetype;
	switch ((pagetype = papertype)) {
		case	0	:	/* A4 	*/
		case	1	:	/* A3 	*/
		case	2	:	/* A2 	*/
		case	3	:	/* A1 	*/
		case	4	:	/* A0 	*/
			pagetype += 6;
			break;

		case	5	:	/* A10	*/
		case	6	:	/* A9	*/
		case	7	:	/* A8 	*/
		case	8	:	/* A7 	*/
		case	9	:	/* A6 	*/
		case	10	:	/* A5	*/
			pagetype -= 5;
			break;

		case	11	:	/* B10 	*/
		case	12	:	/* B9	*/
		case	13	:	/* B8 	*/
		case	14	:	/* B7 	*/
		case	15	:	/* B6 	*/
		case	16	:	/* B5 	*/
		case	17	:	/* B4 	*/
		case	18	:	/* B3 	*/
		case	19	:	/* B2 	*/
		case	20	:	/* B1 	*/
		case	21	:	/* B0	*/
			pagetype += 1;
			break;
		}

	PaperType = pagetype;
	PaperWidth  = paper_dimensions[pagetype];
	PaperHeight = paper_dimensions[pagetype+1];
	PaperName = paper_name[pagetype];

	switch ((DotsPerInch=dpi)) {
		case	  75 	: break;
		case	 100	: 
			PaperWidth *= 4; PaperWidth /= 3;
			PaperHeight *= 4; PaperHeight /= 3;
			break;
		case	 150	: dpi = 2;
			PaperWidth *= 2;PaperHeight *= 2; 
			break;
		case	 300	: dpi = 3;
			PaperWidth *= 4;PaperHeight *= 4; 
			break;
		case	 600	: dpi = 4;
			PaperWidth *= 8;PaperHeight *= 8; 
			break;
		case	1200	: dpi = 5;
			PaperWidth *= 16;PaperHeight *= 16; 
			break;
		default		:
			if ( dpi < 100 )	return(set_paper_dimensions(75,papertype));
			else if ( dpi < 150 )	return(set_paper_dimensions(100,papertype));
			else if ( dpi < 300 )	return(set_paper_dimensions(150,papertype));
			else if ( dpi < 600 )	return(set_paper_dimensions(300,papertype));
			else if ( dpi < 1200 )	return(set_paper_dimensions(600,papertype));
			else			return(set_paper_dimensions(1200,papertype));
		}
	return( 0 );
			
}


int	collect_paper_dimensions( int *  w, int * h, int dpi, int papertype )
{
	set_paper_dimensions( dpi, papertype );
	*w = PaperWidth;
	*h = PaperHeight;
/*	printf("collect_page_dimensions(%u,%u) : %u x %u \r\n",dpi,papertype,*w,*h);	*/
	return 0;
}


#endif	/* _paper_c */
	/* -------- */


