
#ifndef	_lodriver_c
#define	_lodriver_c

#include "xgraph.h"
#include "allocate.h"
#include <string.h>

#ifdef UNIX
#define x_previous_graph (CicoAccessController.FunctionRelay[CICO_GRAPH])
#else
int x_previous_graph( int i, struct x_graph_descriptor * dptr );
#endif
void	resolve_colour( int v, int * r, int * g, int * b);
int	get_palette_pixel(int);
void	pixel_to_rgb(int, int, int, int);

static	struct	lodriver_context	{
	char *				DriverControlString;
	int				DriverControlLength;
	int				LeftUnits;
	int				TopUnits;
	struct text_item	*	TextHead;
	struct text_item	*	TextFoot;
	int				font;
	struct	prn_colour		foreground;
	struct	prn_colour		background;
	int				atribut;
	int				isolatin;
	char 				LeftMargin[16];
	char 				TopMargin[16];
	} LoGraph = 
	{
	(char *) 0, 0,
	0,0,
	(struct text_item *) 0,
	(struct text_item *) 0,
	0,
	0,0,
	0,
	0
	};


void	set_print_colour( struct prn_colour * cptr, int v )
{
	if (!((cptr->value = v) & 0x80000000)) {
		cptr->value = (get_palette_pixel((v & 0x00FF)) | 0x80000000);
		}
	pixel_to_rgb( (cptr->value & 0x7FFFFFFF), cptr->red, cptr->green, cptr->blue );
	return;
}

void	copy_print_colour( struct prn_colour * rptr, struct prn_colour * sptr )
{
	rptr->red   = sptr->red;
	rptr->green   = sptr->green;
	rptr->blue   = sptr->blue;
	rptr->value = sptr->value;
	return;
}

void	raz_print_colour( struct text_item*tptr)
{
	tptr->foreground.red 	=
	tptr->background.red 	=
	tptr->foreground.green	=
	tptr->background.green 	=
	tptr->foreground.blue 	=
	tptr->background.blue	= 0;
	return;
}

void	reset_driver_context()
{
	LoGraph.TextHead = (struct text_item*) 0;
	LoGraph.TextFoot = (struct text_item*) 0;
	LoGraph.font     =
	LoGraph.atribut  =
	LoGraph.isolatin = 0;
	LoGraph.LeftMargin[0] = 0;
	LoGraph.TopMargin[0] = 0;
	LoGraph.LeftUnits=0;
	LoGraph.TopUnits=0;
	LoGraph.foreground.red = 
	LoGraph.foreground.green = 
	LoGraph.foreground.blue = 
	LoGraph.foreground.value = 
	LoGraph.background.red = 
	LoGraph.background.green = 
	LoGraph.background.blue = 
	LoGraph.background.value = 0;
	return;
}


#define	_STYLE_DPI 	75  		/* pixels per   inch				*/
#define	_STYLE_MMPI	25.4		/* mm per inch				*/
#define	_STYLE_PTPI	72		/* points per inch				*/
#define	_STYLE_PTPP	12		/* points per pica				*/
#define	_STYLE_PCPI	6		/* picas  per inch	 			*/

int	inchtoi(char * sptr)
{
	float	q=0;
	int	pixels;
	sscanf(sptr,"%f",&q);
	return(	(pixels =  (q*_STYLE_DPI)));
}

int	mmtoi(char * sptr)
{
	float	q=0;
	int	pixels;
	sscanf(sptr,"%f",&q);
	return((pixels =  (((q*_STYLE_DPI)/_STYLE_MMPI))));
}

int	calculate_paper_left_margin(int dpi)
{
	switch ( LoGraph.LeftUnits ) {
		case	0 :
			return(atoi(LoGraph.LeftMargin));
		case	1 :
			return(((inchtoi(LoGraph.LeftMargin)*dpi)/75));
		case	2 :
			return(((mmtoi(LoGraph.LeftMargin)*dpi)/75));
		default	  :
			return(0);
		}
}

int	calculate_paper_top_margin(int dpi)
{
	switch ( LoGraph.TopUnits ) {
		case	0 :
			return(atoi(LoGraph.TopMargin));
		case	1 :
			return(((inchtoi(LoGraph.TopMargin)*dpi)/75));
		case	2 :
			return(((mmtoi(LoGraph.TopMargin)*dpi)/75));
		default	  :
			return(0);
		}
}


unsigned char Twin2Ansi[256] =	{
  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,
 16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,
 32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,
 48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,
 64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,
 80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,
 96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
199, 252, 233, 226, 228, 224, 229, 231, 234, 235, 232, 239, 238, 236, 196, 197,
201, 230, 198, 244, 246, 242, 251, 249, 255, 214, 220, 162, 163, 165, 158, 159,
225, 237, 243, 250, 241, 209, 170, 186, 191, 175, 172, 189, 188, 161, 171, 187,
128, 129, 130, 166, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142,
143, 144, 145, 146, 173, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157,
160, 168, 167, 169, 174, 179, 184, 185, 190, 192, 193, 194, 195, 208, 202, 203,
222, 223, 204, 182, 205, 254, 181, 206, 216, 245, 210, 240, 211, 248, 200, 215,
207, 177, 212, 213, 221, 253, 247, 217, 176, 183, 180, 218, 219, 178, 164, 227
};

unsigned char Twin2Twin[256] =	{
  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,
 16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,
 32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,
 48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,
 64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,
 80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95,
 96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127,
'C','u','e','a','a','a','a','c','e','e','e','i','i','i','A','A',
'E','a','A','o','o','o','u','u','y','o','o','E','L','Y','P','F',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
};

void	set_iso_latin(int v)
{
	LoGraph.isolatin = v;
	return;
}

#ifndef	_use_text_item
#define	_use_text_item
int	use_text_item( struct text_item * tptr )
{
	return(0);
}
#endif

static	void	add_list_item( struct text_item * tptr )
{
	if (!( use_text_item( tptr ))) {
		tptr->next = (struct text_item *) 0;
		if (!( LoGraph.TextFoot ))
			LoGraph.TextHead = tptr;
		else	LoGraph.TextFoot->next = tptr;
		LoGraph.TextFoot= tptr;
		}
	else	{
		if ( tptr->type == _PRINT_TEXT )
			if ( tptr->message )
				liberate( tptr->message );
		liberate( tptr );
		}
	return;
}

void	add_line_item( int x, int y, int w, int h, int thick, int pixel )
{
	struct	text_item * tptr;
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else	{
		raz_print_colour(tptr);
		tptr->atx = x; 	tptr->aty = y;
		tptr->w = w;	tptr->h = h;
		tptr->align =	thick;
		set_print_colour( &tptr->foreground, pixel );
		tptr->type = _PRINT_LINE;
		add_list_item( tptr );
		return;
		}
}

void	add_fill_item( int x, int y, int w, int h, int pixel )
{
	struct	text_item * tptr;
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else	{
		raz_print_colour(tptr);
		tptr->atx = x; 	tptr->aty = y;
		tptr->w = w;	tptr->h = h;
		set_print_colour( &tptr->foreground, pixel );
		tptr->type = _PRINT_FILL;
		add_list_item( tptr );
		return;
		}
}

void	add_xfill_item( int x, int y, int w, int h, int pixel )
{
	struct	text_item * tptr;
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else	{
		raz_print_colour(tptr);
		tptr->atx = x; 	tptr->aty = y;
		tptr->w = w;	tptr->h = h;
		set_print_colour( &tptr->foreground, pixel );
		tptr->type = _PRINT_XFILL;
		add_list_item( tptr );
		return;
		}
}

void	add_circle_item( int x, int y, int w, int h, int pixel, int type )
{
	struct	text_item * tptr;
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else	{
		raz_print_colour(tptr);
		raz_print_colour(tptr);
		tptr->atx = x; 	tptr->aty = y;
		tptr->w = w;	tptr->h = h;
		tptr->align =	type;
		set_print_colour( &tptr->foreground, pixel );
		tptr->type = _PRINT_CIRCLE;
		add_list_item( tptr );
		return;
		}
}

/*FCH24022006 begin */
void	add_roundfill_item( int x, int y, int w, int h, int pixel )
{
	struct	text_item * tptr;
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else	{
		raz_print_colour(tptr);
		tptr->atx = x; 	tptr->aty = y;
		tptr->w = w;	tptr->h = h;
		set_print_colour( &tptr->foreground, pixel );
		tptr->type = _PRINT_ROUNDFILL;
		add_list_item( tptr );
		return;
		}
}

void	add_roundframe_item( int x, int y, int w, int h, int pixel )
{
	struct	text_item * tptr;
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else	{
		raz_print_colour(tptr);
		tptr->atx = x; 	tptr->aty = y;
		tptr->w = w;	tptr->h = h;
		set_print_colour( &tptr->foreground, pixel );
		tptr->type = _PRINT_ROUNDFRAME;
		add_list_item( tptr );
		return;
		}
}
/*FCH24022006 end */

void	add_image_item( int x, int y, int w, int h, struct standard_image * iptr, int align )
{
	struct	text_item * tptr;
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else if (!( tptr->image = iptr )) {
		free( tptr );
		return;
		}
	raz_print_colour(tptr);
	tptr->atx = x; 	tptr->aty = y;
	tptr->w = w;	tptr->h = h;
	tptr->align =	align;
	tptr->type = _PRINT_IMAGE;
	add_list_item( tptr );
	return;
}

void	add_text_item( int x, int y, int fid, char * mptr, int mlen, int w, int h, int a )
{
	char *	wptr;
	struct	text_item * tptr;
	int	i;
	int	extra=0;

	/* detect and eliminate space strings */
	/* ---------------------------------- */
	for (i=0; i < mlen; i++ )
		if ( *(mptr+i) != ' ' )
			break;

	if ( i >= mlen ) return;

	/* detect required escape characters */
	/* --------------------------------- */
	for ( i=0; i < mlen; i++ ) { 
		switch ( *(mptr+i) ) {
			case	')'	:
			case	'('	:
			case	'\\'	:
				extra++;
			}
		}

	/* allocate for text storage */
	/* ------------------------- */
	if (!( tptr = allocate( sizeof( struct text_item ) ) ))
		return;
	else if (!( tptr->message = allocate( (mlen+1+(extra*2)) ))) {
		free( tptr );
		return;
		}
	else	{
		raz_print_colour(tptr);
		tptr->type= _PRINT_TEXT;
		tptr->atx = x; tptr->aty = y;
		tptr->w = w; tptr->h = h;
		for (wptr = tptr->message,i=0; i < mlen; i++ ) { 
			switch ( *(mptr+i) ) {
				case	')'	:
				case	'('	:
				case	'\\'	:
					*(wptr++) = '\\';
				}
			*(wptr++) = *(mptr+i);
			}
		*(wptr++) = 0;
		tptr->font  = fid;	tptr->bytes = mlen;
		copy_print_colour( &tptr->foreground, &LoGraph.foreground );
		copy_print_colour( &tptr->background, &LoGraph.background );
		tptr->atribut = LoGraph.atribut;
		tptr->align   = a;
		/* Perform Charactere conversions */
		/* ------------------------------ */
		mptr = tptr->message;
		if ( LoGraph.isolatin ) {
			for ( i=0; i < mlen; i++ ) { *(mptr+i) = Twin2Ansi[(*(mptr+i)&0x00FF)]; }
			}
		else	{
			for ( i=0; i < mlen; i++ ) { *(mptr+i) = Twin2Twin[(*(mptr+i)&0x00FF)]; }
			}

		add_list_item( tptr );
		return;
		}

}

struct	text_item * get_text_item()
{
	struct	text_item * tptr;
	if (!(tptr = LoGraph.TextHead)) {
		return((LoGraph.TextFoot=tptr));
		}
	else	{
		LoGraph.TextHead = tptr->next;
		return( tptr );
		}
}


void	set_colour_options( int options )
{
	switch (((options & _PIXEL_SIZE) >> _PIXEL_SHIFT)) {
		case	0 :	colourmapping = 1; pixelsize = 1; break;
		case	1 :	colourmapping = 0; pixelsize = 1; 
				redmask = _RED_MASK8;
				bluemask = _BLUE_MASK8;
				greenmask = _GREEN_MASK8;
				break;
		case	2 :	colourmapping = 0; pixelsize = 2;
				redmask = _RED_MASK16;
				bluemask = _BLUE_MASK16;
				greenmask = _GREEN_MASK16;
				break;
		case	3 :	
		case	4 :	colourmapping = 0; pixelsize = 4; 
				redmask = _RED_MASK32;
				bluemask = _BLUE_MASK32;
				greenmask = _GREEN_MASK32;
				break;
		default	  :	colourmapping = 1; pixelsize = 1; break;
		}
	return;
}

int	palettepixel( int offset )
{
	int	r=0;
	int	i;
	int	s;
	char *	bptr=PaletteBuffer;
	if ( colourmapping ) 
		return( offset );
	else	{
		for (s=0,i=0,r=0; i < 3; i++,s+=8 )
			r = (r | (( *(bptr + (offset * 4) + i) & 0x00FF) << s));
		return( r );
		}
}

int	logicalpixel( char * bptr, int offset )
{
	int	r=0;
	int	i;
	int	s;
	int	maxbytes;
	if ( colourmapping ) 
		return( (*(bptr+offset) & 0x00FF ) );
	else	{
		if ((maxbytes = pixelsize) > 3)
			maxbytes=3;
		for (s=0,i=0,r=0; i < maxbytes; i++,s+=8 )
			r = (r | (( *(bptr + (offset * pixelsize) + i) & 0x00FF) << s));
		return( r );
		}
}

void	resolve_colour( int v, int * r, int * g, int * b)
{
	char	*	pptr;

	*r = *g = *b = 0;

	if (( v >= 0 ) && ( v <= 255)) {
		pptr = (PaletteBuffer + (v*4));
		*r = (*pptr & 0x00FF);
		*g = (*(pptr+1) & 0x00FF);
		*b = (*(pptr+2) & 0x00FF);
		}
	return;
}

int	colour_map_luminence( int v )
{
	int	r=0;
	int	g=0;
	int	b=0;
	int	l;
	char *  pptr;
	if (( v >= 0 ) && ( v <= 255)) {
		pptr = (PaletteBuffer + (v*4));
		if ((r = (*(pptr + 3) & 0x00FF)) != 0)
			return(r);
		else 	{
			/* this is right ! */
			/* --------------- */
			r = (*pptr & 0x00FF);
			g = (*(pptr+1) & 0x00FF);
			b = (*(pptr+2) & 0x00FF);
			l = (((r*_RED_WEIGHT)+(g*_GREEN_WEIGHT)+(b*_BLUE_WEIGHT))/256);
			return( l );
			}
		}
	else	return( 0 );
}

int	truecolour_luminence( char * rptr, int offset )
{
	int	r=0;
	int	g=0;
	int	b=0;
	int	l;
	int	p;
	if (!( p = logicalpixel( rptr, offset ) ))
		return( p );
	else	{
		/* This is right */
		/* --------------- */
		switch ( pixelsize ) {
			case	1 :
				r = (((p >> _RED_SHIFT8) &  _RED_MASK8) << _RED_CORRECTION8);
				b = (((p >> _BLUE_SHIFT8) &  _BLUE_MASK8) << _BLUE_CORRECTION8);
				g = (((p >> _GREEN_SHIFT8) &  _GREEN_MASK8) << _GREEN_CORRECTION8);
				break;
			case	2 :
				r = (((p >> _RED_SHIFT16) & _RED_MASK16) << _RED_CORRECTION16);
				b = (((p >> _BLUE_SHIFT16) & _BLUE_MASK16) << _BLUE_CORRECTION16);
				g = (((p >> _GREEN_SHIFT16) & _GREEN_MASK16) << _GREEN_CORRECTION16);
				break;
			case	3 :
			case	4 :
				r = ((p >> _RED_SHIFT32) &  _RED_MASK32);
				b = ((p >> _BLUE_SHIFT32) &  _BLUE_MASK32);
				g = ((p >> _GREEN_SHIFT32) &  _GREEN_MASK32);
				break;
			default	  :
				return( p );
			}
		l = (((r*_RED_WEIGHT)+(g*_GREEN_WEIGHT)+(b*_BLUE_WEIGHT))/256);
		return( l );
		}
}

int	luminence( char * bptr, int offset )
{
	if ( colourmapping )
		return( colour_map_luminence( ( *(bptr+offset) & 0x00FF ) ) );
	else	return( truecolour_luminence( bptr, offset ) );
}
	
void	extract_colour( int p, int * r, int * g, int * b)
{
	/* This is right */
	/* --------------- */
	switch ( pixelsize ) {
		case	1 :
			*r = ((p >> _RED_SHIFT8) & _RED_MASK8);
			*b = ((p >> _BLUE_SHIFT8) & _BLUE_MASK8);
			*g = ((p >> _GREEN_SHIFT8) & _GREEN_MASK8);
			break;
		case	2 :
			*r = ((p >> _RED_SHIFT16) & _RED_MASK16);
			*b = ((p >> _BLUE_SHIFT16) & _BLUE_MASK16);
			*g = ((p >> _GREEN_SHIFT16) & _GREEN_MASK16);
			break;
		case	3 :
		case	4 :
			*r = ((p >> _RED_SHIFT32) & _RED_MASK32);
			*b = ((p >> _BLUE_SHIFT32) & _BLUE_MASK32);
			*g = ((p >> _GREEN_SHIFT32) & _GREEN_MASK32);
			break;
		default	  :
			*r = 0; *b = 0; *g= 0;
		}
	return;
}

/* DLL Pattern Management */
/* ---------------------- */

static	char 	LaPaterne[16] = { 
	'*','P','R','L','@','I','N','F','O','*',
	'#',3,
	__DRIVER_MAJOR,__DRIVER_MINOR,__DRIVER_INDEX,
	0 };

static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[8];
char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

#ifdef	UNIX

#ifndef	private
#define	private static
#endif

#ifndef	public
#define	public
#endif

/*	--------------------------------------		*/
/*	Elements of the CICO Access Controller		*/
/*	--------------------------------------		*/

private	struct	cico_access_controller	{

	WORD   FunctionCount;
	EXAWORD  (*FunctionRelay[CICO_NOMBRE])();

	} CicoAccessController;


/*	--------------------------------------		*/
/*	Access Controller Basic Initialisation		*/
/*	--------------------------------------		*/

private	void	initialise_access_controller()
{
	CicoAccessController.FunctionCount = CICO_NOMBRE;

	CicoAccessController.FunctionRelay[CICO_CI] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_TPCI]	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_PRFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LCFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CONF] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MES] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LIGNE] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_COLONNE]= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_START] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_FLUSH] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MIMA] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_EVENT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_INIT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_GRAPH] 	= (void *) 0;
  	return;
}

/*	-------------------------------------------------	*/
/* 	This function is provided to  perform redirection	*/
/*	--------------------------------------------------	*/

private	void *	redirect_access_controller( int	item,  void *	fptr )
{
	void	*	vptr=(void *) 0;
	if ((item >= 0) && ( item < CicoAccessController.FunctionCount )) {
		if ( fptr ) {
			vptr = CicoAccessController.FunctionRelay[item]; 	
			CicoAccessController.FunctionRelay[item] = fptr;
	 		}
 		}
	return( vptr );
}

private	EXAWORD connect_access_controller( BDA_INIT * iptr, void * eptr )
{
	int	i;
	void *	vptr;
	
	if (!( iptr ))
		return(0);

	for (i=0; i < CICO_NOMBRE; i++ ) {
		vptr = iptr->cico.fonction[i];
		if ( i != CICO_INIT )
			CicoAccessController.FunctionRelay[i] = vptr;
		}
	return(0);
}

int	x_graph( int xgcode, struct x_graph_descriptor * dptr )
{
	return( (CicoAccessController.FunctionRelay[CICO_GRAPH])(xgcode,dptr) );
}

int	x_event( int xgcode )
{
	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(xgcode) );
}

public	int	printer_x_graph( int xgcode, struct x_graph_descriptor * dptr )
{
	char	*	cptr;
	int		i;
	int		l;
	char	*	wptr;

	if (!( textfiltering & 1 ))
		return( x_previous_graph(xgcode,dptr) );

	switch ( xgcode ) {

		case	_XGR_HARDWARE	:
			textfiltering &= ~6;
			return( x_previous_graph(xgcode,dptr) );

		case	_XGR_SOFTWARE	:
			textfiltering |= 6;
			return( x_previous_graph(xgcode,dptr) );
					
		}

	if (!( textfiltering & 2 ))
		return( x_previous_graph(xgcode,dptr) );

	switch ( xgcode ) {
		case	_XGR_XFILZONE	:
			add_xfill_item( 
				dptr->zone.x,
				dptr->zone.y,
				dptr->zone.w,
				dptr->zone.h, 
				dptr->foreground);
			if (!( textfiltering  & 4 ))
				return(0);
			else	return( x_previous_graph(xgcode,dptr) );

		case	_XGR_FILZONE	:
			add_fill_item( 
				dptr->zone.x,
				dptr->zone.y,
				dptr->zone.w,
				dptr->zone.h, 
				dptr->foreground);
			if (!( textfiltering  & 4 ))
				return(0);
			else	return( x_previous_graph(xgcode,dptr) );

		case	_XGR_CIRCLE 	:
			if ( dptr->buffer )
				add_circle_item( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->foreground,
					dptr->length  );

			if (!( textfiltering  & 4 ))
				return(0);
			else	return( x_previous_graph(xgcode,dptr) );

		case	_XGR_ROUNDFILZONE 	:
			if ( dptr->buffer )
				add_roundfill_item( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->foreground);

			if (!( textfiltering  & 4 ))
				return(0);
			else	return( x_previous_graph(xgcode,dptr) );

		case	_XGR_ROUNDFRAME 	:
			if ( dptr->buffer )
				add_roundframe_item( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->foreground);

			if (!( textfiltering  & 4 ))
				return(0);
			else	return( x_previous_graph(xgcode,dptr) );


		case	_XGR_LINE 	:
			if ( dptr->buffer )
				add_line_item( 
					dptr->zone.x,
					dptr->zone.y,
					dptr->zone.w,
					dptr->zone.h, 
					dptr->length,
					dptr->foreground  );
			if (!( textfiltering  & 4 ))
				return(0);
			else	return( x_previous_graph(xgcode,dptr) );

		case	_XGR_IMAGE	:
			if ( dptr->buffer )
				add_image_item( dptr->zone.x, dptr->zone.y, dptr->zone.w, dptr->zone.h, dptr->buffer, dptr->length );
			if (!( textfiltering  & 4 ))
				return(0);
			else	return( x_previous_graph(xgcode,dptr) );

		case	_XGR_FONTSIZE	:
			return( x_previous_graph(xgcode,dptr) );

		case	_XGR_USEFONT  	:
			LoGraph.font = dptr->fontnumber;			
			return( x_previous_graph(xgcode,dptr) );
		
		case	_XGR_ATRIBUT	:
			LoGraph.atribut = dptr->zone.x;
			return( x_previous_graph(xgcode,dptr) );

		case	_XGR_COLOUR  	:
			set_print_colour( &LoGraph.foreground,dptr->foreground);
			set_print_colour( &LoGraph.background,dptr->background);
			return( x_previous_graph(xgcode,dptr) );

		case	_XGR_PUTC	:
			printf(" PixelPutC(%c)\r\n", dptr->value ); 
			return(0);

		case	_XGR_FONTC	:
			/* printf(" PixelFontC(%u,%c)\r\n", dptr->fontnumber,dptr->value );  */
			return(0);

		case	_XGR_PUTCAT	:
			/* printf(" PixelPutCat(%u,%u,%c)\r\n", dptr->zone.x, dptr->zone.y, dptr->value );  */
			return(0);

		case	_XGR_FONTCAT	:
			/* printf(" PixelFontCat(%u,%u,%u,%c)\r\n", dptr->zone.x, dptr->zone.y, dptr->fontnumber,dptr->value );  */
			return(0);

		case	_XGR_PUTS	:
			if ( dptr->buffer )
				add_text_item( -1,-1, LoGraph.font,dptr->buffer, strlen(dptr->buffer), 0,0, -1);
			return(0);

		case	_XGR_FONTS	:
			if ( dptr->buffer )
				add_text_item( -1,-1, dptr->fontnumber,dptr->buffer, strlen(dptr->buffer), 0,0, -1);
			return(0);

		case	_XGR_PUTSAT	:
			if ( dptr->buffer )
				add_text_item( dptr->zone.x, dptr->zone.y, LoGraph.font,dptr->buffer, strlen(dptr->buffer), 0,0, -1 );
			return(0);

		case	_XGR_PUTL	:
			if ( dptr->buffer )
				add_text_item( -1,-1, LoGraph.font,dptr->buffer, dptr->length, 0,0, -1);
			return(0);

		case	_XGR_FONTL	:
			if ( dptr->buffer )
				add_text_item( -1,-1, dptr->fontnumber,dptr->buffer, dptr->length, 0,0, -1);
			return(0);

		case	_XGR_PUTLAT	:
			if ( dptr->buffer )
				add_text_item( dptr->zone.x, dptr->zone.y, LoGraph.font,dptr->buffer, dptr->length, 0,0, -1 );
			return(0);

		case	_XGR_FONTSAT	:
			if ( dptr->buffer )
				add_text_item( dptr->zone.x, dptr->zone.y, dptr->fontnumber,dptr->buffer, strlen( dptr->buffer), 0,0, -1 );
			return(0);

		case	_XGR_ALIGN	:
			if ((cptr = dptr->buffer) != (char *) 0) {
				if (!( wptr =allocate( strlen( cptr ) + 1 )))
					return(0);
				else	{
					strcpy(wptr,cptr);
					cptr = wptr;
					}
				while ( *cptr == ' ' ) {
					cptr++;
					if ( dptr->length )
						dptr->length--;
					}
				for ( l=0,i=0; i < dptr->length; i++ ) {
					if ( *(cptr+i) != ' ' )
						l = (i+1);
					}
				*(cptr+l) = 0;
				dptr->length = l;
#ifdef	TRACE_XGR_ALIGN
			printf(" XGR ALIGN(%u,%u,%u,%u,%u,",
				dptr->zone.x, dptr->zone.y, 
				dptr->zone.w, dptr->zone.h, 
				dptr->fontnumber);
			for ( i=0; i < dptr->length; i++ )
				printf("%c",*(cptr+i));
				printf(",%u,%u)\r\n",dptr->length,dptr->value );
#endif
				add_text_item( dptr->zone.x, dptr->zone.y, dptr->fontnumber,cptr, dptr->length, dptr->zone.w, dptr->zone.h, dptr->value );
				liberate( wptr );
				}
			return(0);


		case	_XGR_FONTLAT	:
#ifdef	TRACE_XGR_FONTLAT
			printf(" XGR FONTLAT(%u,%u)\r\n",dptr->zone.x, dptr->zone.y);
#endif
			if ( dptr->buffer )
				add_text_item( dptr->zone.x, dptr->zone.y, dptr->fontnumber,dptr->buffer, dptr->length, 0,0, -1 );
			return(0);

		case	_XGR_TEXTSIZE	:
			return(0);

		default			:
			return( x_previous_graph(xgcode,dptr) );
		}
}

#endif

public	int	get_page_control( char ** s, int * l)
{
	if ((LoGraph.DriverControlString != (char *) 0)
	&&  (LoGraph.DriverControlLength != 0)) {
		*s = LoGraph.DriverControlString;
		*l = LoGraph.DriverControlLength;
		return( LoGraph.DriverControlLength );
		}
	else	{
		*s = (char *) 0;
		*l = 0;
		return( 0 );
		}
}
	

private	EXAWORD	DriverControl(char * s, int sl)
{
	printf(" Driver Control ( %u ) \n",sl);
	if ( LoGraph.DriverControlString ) {
		LoGraph.DriverControlString = liberate( LoGraph.DriverControlString );
		LoGraph.DriverControlLength = 0;
		}
	if ( sl ) {
		if (!( LoGraph.DriverControlString = allocate( sl+1 ) ))
			return( 27 );
		else	{
			memcpy(LoGraph.DriverControlString,s,sl);
			*(LoGraph.DriverControlString+sl) = 0;
			LoGraph.DriverControlLength = sl;
			}
		}
	return(0);
}

private	EXAWORD	DriverMargins(char * lv, int lt, char * tv, int tt )
{
	int	i;
	int	c;
	for (i=0; i < 15; i++ ) {
		if (!( c = *(lv++)))
			break;
		else if ( c == ' ' )
			break;
		else if (( c >= '0' ) && ( c <= '9' ))
			LoGraph.LeftMargin[i] = c;
		else if ( c != '.' )
			break;
		else	LoGraph.LeftMargin[i] = c;
		}
	LoGraph.LeftMargin[i] = 0;
	for (i=0; i < 15; i++ ) {
		if (!( c = *(tv++)))
			break;
		else if ( c == ' ' )
			break;
		else if (( c >= '0' ) && ( c <= '9' ))
			LoGraph.TopMargin[i] = c;
		else if ( c != '.' )
			break;
		else	LoGraph.TopMargin[i] = c;
		}
	LoGraph.TopMargin[i] = 0;
	LoGraph.LeftUnits  = lt;
	LoGraph.TopUnits   = tt;
#ifdef	_calculate_driver_margins
	return( calculate_driver_margins() );
#else
	return( 0 );
#endif
}

/* ------------------ */
/* DLL initialisation */
/* ------------------ */
VOID FAR PTR InitRelais()
{ 
#ifdef	UNIX
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_REDIRECT;
#else
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;
#endif
	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;

	desrt.nombre = _DRIVER_DLL_FUNCTION;	/* 8 */
#ifdef	UNIX
	initialise_access_controller();
#endif
#ifdef vms

	desrt.nom[_DRIVER_DLL_INITIALISE] 	= (BYTE FAR PTR) "_DriverInitialise";
	desrt.nom[_DRIVER_DLL_COLOUR]  		= (BYTE FAR PTR) "_DriverColours";
	desrt.nom[_DRIVER_DLL_CONNECT] 		= (BYTE FAR PTR) "_DriverConnect";
	desrt.nom[_DRIVER_DLL_START]   		= (BYTE FAR PTR) "_DriverStartRaster";
	desrt.nom[_DRIVER_DLL_PRINT]     	= (BYTE FAR PTR) "_DriverPrintRow";
	desrt.nom[_DRIVER_DLL_END]  		= (BYTE FAR PTR) "_DriverEndRaster";
	desrt.nom[_DRIVER_DLL_LIBERATE]   	= (BYTE FAR PTR) "_DriverLiberate";
	desrt.nom[_DRIVER_DLL_MARGINS]   	= (BYTE FAR PTR) "_DriverMargins";
	desrt.nom[_DRIVER_DLL_CONTROL]   	= (BYTE FAR PTR) "_DriverControl";

	/* ----- */
#else 	/* ! vms */
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;

	desrt.fonction[_DRIVER_DLL_INITIALISE]  = (EXAWORD (FAR PTR)()) DriverInitialise;
	desrt.fonction[_DRIVER_DLL_COLOUR]  	= (EXAWORD (FAR PTR)()) DriverColours;
	desrt.fonction[_DRIVER_DLL_CONNECT]  	= (EXAWORD (FAR PTR)()) DriverConnect;
	desrt.fonction[_DRIVER_DLL_START]  	= (EXAWORD (FAR PTR)()) DriverStartRaster;
	desrt.fonction[_DRIVER_DLL_PRINT]  	= (EXAWORD (FAR PTR)()) DriverPrintRow;
	desrt.fonction[_DRIVER_DLL_END]  	= (EXAWORD (FAR PTR)()) DriverEndRaster;
	desrt.fonction[_DRIVER_DLL_LIBERATE]  	= (EXAWORD (FAR PTR)()) DriverLiberate;
	desrt.fonction[_DRIVER_DLL_MARGINS]  	= (EXAWORD (FAR PTR)()) DriverMargins;
	desrt.fonction[_DRIVER_DLL_CONTROL]  	= (EXAWORD (FAR PTR)()) DriverControl;

#endif /* vms */


#ifdef	UNIX
	desrt.fonction[_DRIVER_DLL_FUNCTION+1]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+2]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+3]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+4]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+5]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+6]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+6]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+7]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+8]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+9]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+10]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+11]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+12]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+13]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+14]	= (EXAWORD (FAR PTR)()) 0;
	desrt.fonction[_DRIVER_DLL_FUNCTION+15]	= connect_access_controller;
	desrt.fonction[_DRIVER_DLL_FUNCTION+16]	= (EXAWORD (FAR PTR)()) printer_x_graph;
	if (rt_init != (VOID FAR PTR) 0L) {
		rt_init->cico.numero = 16384 | 32768;
		rt_init->cico.fonction[CICO_CI]     = desrt.fonction[_DRIVER_DLL_FUNCTION+1]; 
	 	rt_init->cico.fonction[CICO_TPCI]   = desrt.fonction[_DRIVER_DLL_FUNCTION+2];
	  	rt_init->cico.fonction[CICO_PRFO]   = desrt.fonction[_DRIVER_DLL_FUNCTION+3];  	
		rt_init->cico.fonction[CICO_LCFO]   = desrt.fonction[_DRIVER_DLL_FUNCTION+4];  	
		rt_init->cico.fonction[CICO_CONF]   = desrt.fonction[_DRIVER_DLL_FUNCTION+5]; 	
		rt_init->cico.fonction[CICO_CO]     = desrt.fonction[_DRIVER_DLL_FUNCTION+6]; 	
		rt_init->cico.fonction[CICO_MES]    = desrt.fonction[_DRIVER_DLL_FUNCTION+7]; 	
		rt_init->cico.fonction[CICO_LIGNE]  = desrt.fonction[_DRIVER_DLL_FUNCTION+8]; 	
		rt_init->cico.fonction[CICO_COLONNE]= desrt.fonction[_DRIVER_DLL_FUNCTION+9]; 	
		rt_init->cico.fonction[CICO_START]  = desrt.fonction[_DRIVER_DLL_FUNCTION+10]; 	
		rt_init->cico.fonction[CICO_FLUSH]  = desrt.fonction[_DRIVER_DLL_FUNCTION+11]; 	
		rt_init->cico.fonction[CICO_LO]     = desrt.fonction[_DRIVER_DLL_FUNCTION+12]; 	
		rt_init->cico.fonction[CICO_MIMA]   = desrt.fonction[_DRIVER_DLL_FUNCTION+13];   
		rt_init->cico.fonction[CICO_EVENT]  = desrt.fonction[_DRIVER_DLL_FUNCTION+14];
		rt_init->cico.fonction[CICO_INIT]   = desrt.fonction[_DRIVER_DLL_FUNCTION+15];
		rt_init->cico.fonction[CICO_GRAPH]  = desrt.fonction[_DRIVER_DLL_FUNCTION+16];
		}
#endif
	return((VOID FAR PTR) &desrt);

}

/* ---------------------- */
/* Library identification */
/* ---------------------- */
static VOID FAR banniere()
{ 
	printf("\n   Graphics Printer Driver : %s ",__DRIVER_NAME);
	printf("\n   Version %s ",getpatternversion());
	printf("\n   Provisoire du %s ",__DRIVER_DATE);
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	printf("\n\t %u  %% DriverInitialise(palette$?,dpi%%,width%%,height%%,options%%)",_DRIVER_DLL_INITIALISE);
	printf("\n\t %u  %% DriverColours()",_DRIVER_DLL_COLOUR);
	printf("\n\t %u  %% DriverConnect(bufferA$,bufferB$,result$)",_DRIVER_DLL_CONNECT);
	printf("\n\t %u  %% DriverStartRaster(result$?)",_DRIVER_DLL_START);
	printf("\n\t %u  %% DriverPrintRow(result$?,source$?)",_DRIVER_DLL_PRINT);
	printf("\n\t %u  %% DriverEndRaster(result$?)",_DRIVER_DLL_END);
	printf("\n\t %u  %% DriverLiberate(result$?)\n",_DRIVER_DLL_LIBERATE);
	printf("\n\t %u  %% DriverMargins(lv$,lt%%,tv$,tt%%)\n",_DRIVER_DLL_MARGINS);
	printf("\n\t %u  %% DriverControl(lv$,lt%%)\n",_DRIVER_DLL_CONTROL);
	return;
}

#endif	/* _lodriver_c */



