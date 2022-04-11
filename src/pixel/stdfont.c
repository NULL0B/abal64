#ifndef	_stdfont_c
#define	_stdfont_c


#include "stdfont.h"
#include "sysfile.h"
#include "fontrite.c"

extern	int	GigoXtrace;

private	int	fontgets( char * r, char * s, int n )
{
	int	i;
	for (i=0; i < n; i++ ) {
		if (!( *(r+i) = *(s+i) ))
			break;
		}
	return( i+1 );
}

/*	--------------------------------------		*/
/*	a l l o c a t e _ f o n t _ c e l l ()		*/
/*	--------------------------------------		*/

public 	struct standard_cell * allocate_font_cell( int width, int height )
{
	struct standard_cell * cptr=(struct standard_cell *) 0;
	if (( width > 0 ) && ( height > 0 )) {
		if (( cptr = allocate( sizeof(struct standard_cell) + ( width*height ) - 1 )) != (struct standard_cell *) 0) {
			cptr->width 	= width;
			cptr->height	= height;
			memset( &cptr->matrix,0,(width*height));
			}
		}
	return( cptr );
}

/*	-------------------------------		*/
/*	c o p y  _ f o n t _ c e l l ()		*/
/*	-------------------------------		*/

public 	void	copy_font_cell( struct standard_cell * rptr, struct standard_cell * sptr )
{
	int	r;
	int	c;
	for (r=0; r < rptr->height; r++ ) {
		if ( r < sptr->height ) {
			for (c=0; c < rptr->width;  c++ ) {
				if ( c < sptr->width ) 
					rptr->matrix[(r*rptr->width)+c]=sptr->matrix[(r*sptr->width)+c];
				else	break;
				}
			}
		else	break;
		}			
	return;
}

/*		--------------------------------------------		*/
/*		r e c a l c u l a t e _ f o n t _ c e l l ()		*/
/*		--------------------------------------------		*/

public 	struct standard_cell * recalculate_font_cell( struct standard_cell * cptr, int fixed )
{
	int	c,r;
	int	maxc;
	int	width,height;
	struct standard_cell * kptr;

	if ((width = fixed) != 0) {

		/* fixed font */
		/* ---------- */
		height = ((width >> 8) & 0x00FF);
		width  &= 0x00FF;
		if (( cptr->width  == width )
		&&  ( cptr->height == height ))
			return( cptr );
		else if (!( kptr = allocate_font_cell( width, height ) ))
			return( cptr );
		else	{
			copy_font_cell( kptr, cptr );
			liberate( cptr );
			return( kptr );
			}

		}
	else	{	
		/* scan calculate proportional */
		/* --------------------------- */
		for (maxc=0,r=0; r < cptr->height; r++ )
			for ( c=0; c < cptr->width; c++ )
				if ( cptr->matrix[((r*cptr->width)+c)] != 0)
					if (c > maxc) 
						maxc = (c+1);
		if ( cptr->width == (maxc+1) )
			return( cptr );
		else if (!( kptr = allocate_font_cell( maxc+1, cptr->height ) ))
			return( cptr );
		else	{
			copy_font_cell( kptr, cptr );
			liberate( cptr );
			return( kptr );
			}
		}
}

/*	------------------------------		*/
/*	f i l l _ f o n t _ c e l l ()		*/
/*	------------------------------		*/

public 	void	fill_font_cell( 
			struct standard_cell * cptr,
			int atx, int aty, int nbx, int nby, int state )
{
	int	x;
	int	y;
	for (	y=0; y < nby; y++ ) {
		if ( y < cptr->height ) {
			for (	x=0; x < nbx; x++ ) {
				if ( x < cptr->width )
					cptr->matrix[((aty+y)*cptr->width)+(atx+x)] = state;
				else	break;
				}
			}
		else	break;
		}
	return;
}

/*	---------------------------	*/
/*	b u i l d _ f m f _ c e l l 	*/
/*	---------------------------	*/

private	void	build_fmf_cell( int w, int h, int m, char * rptr, char * sptr )
{
	int	rotor=0;
	int	value=0;
	int	n,nn;
	rptr += (w * m); 
	h    -= (2 * m);
	for (nn=0; nn < h; nn++ ) {
		for ( n=0; n < w; n++ ) {
			if (!( rotor )) {
				rotor = 0x80;
				value = *(sptr++);
				}
			if ( value & rotor )
				*rptr = 1;
			rotor >>= 1;
			rptr++;
			}
		}
	return;
}

/*	-----------------	*/
/*	d r o p _ f o n t	*/
/*	-----------------	*/

private	struct	standard_font * drop_font( struct standard_font * fptr )
{
	int	i;
	if ( fptr ) {
		for ( i=0; i < 256; i++ )
			if ( fptr->cell[i] )
				fptr->cell[i] = liberate( fptr->cell[i] );

		for ( i=0; i < 8; i++ ) {
			if ( fptr->hqname[i] )
				fptr->hqname[i] = liberate ( fptr->hqname[i] );
			if ( fptr->hqfont[i] )
				fptr->hqfont[i] = drop_font ( fptr->hqfont[i] );
			}
		if ( fptr->buffer != (char *) 0 )
			fptr->buffer = liberate( fptr->buffer );
		fptr = liberate( fptr );
		}
	return( fptr );
}

/*	-------------------------	*/
/*	l o a d _ f o n _ c e l l 	*/
/*	-------------------------	*/

private	struct	standard_font * load_fon_cell(
	struct	standard_font * fptr,
	int			i,
	char 		      * fbuffer,
	int			o)
{

	struct	standard_cell * cptr;
	int	l,w,h,dlen,nbc,nbr;
	char 	header[8];
	int	v,x,n,r,y;
	int	colcount,colwidth;
	int	rowcount;
	int	bitcount;
	int	extra=0;

	if (( dlen = (getw( (fbuffer+o) )) ) != 0) {

		if ( i == 65 )
			i = 65;

		/* step over data size */
		/* ------------------- */
		fbuffer += (o+2);

		/* read the cell header information */
		/* -------------------------------- */
		for (x=0; x < 6; x++)
			header[x] = *(fbuffer++);

		/* Collect indicated required column count */
		/* --------------------------------------- */
		if (!(colcount = header[0] ))
			colcount = 1;

		/* Collect and calculate indicated required row count */
		/* -------------------------------------------------- */
		if (!( rowcount = (header[2] + header[3]) ))
			rowcount = fptr->height;

		/* calculate bits per row count */
		/* ---------------------------- */
		bitcount = ((dlen/rowcount)*8);

		/* Calculate character cell column width */
		/* ------------------------------------- */
		if ( colcount > fptr->width )
			colcount = fptr->width;

		if ( bitcount > colcount )
			extra = (bitcount-colcount)/8;
		else	extra = 0;

		if ( colcount < fptr->width )
			colwidth = (colcount+1);
		else	colwidth = colcount;

		l = (sizeof( struct standard_cell )+(colwidth*rowcount)-1);

		/* Allocate and Initialise Character Cell Storage */
		/* ---------------------------------------------- */
		if (!( cptr = allocate_font_cell(colwidth,rowcount)))
			return( drop_font( fptr ) );
		else	fptr->cell[i]=cptr;


		if ( colcount < bitcount )
			bitcount = colcount;

		r=0; x=0; y=0; v=0; 
		nbr = (cptr->width * cptr->height);
		if ( i >= 255 ) return( fptr );
		for (y=0; y < nbr; y += cptr->width ) {
			for (r=0,n=0; n < bitcount; n++ ) {
				if (!(r)) { 
					if ( x < dlen ) {
						r = 0x0080; 
						v = (*(fbuffer+x) & 0x00FF); 
						x++; 
						}
					else	{
						return( fptr );
						}
					}
				if ( v & r )
					cptr->matrix[y+n] = 1;		
				else	cptr->matrix[y+n] = 0;		
				r >>= 1;
				}
			x += extra;
			}
		return( fptr );
		}
	else	{
		/* Empty Cell */
		/* ---------- */
		h = fptr->height;
		w = fptr->width;
		if (!( cptr = allocate_font_cell( w, h ) ))
			return( drop_font( fptr ) );
		else	{
			fptr->cell[i]=cptr;
			return(fptr);
			}
		}
}
			
/*	-------------------------	*/
/*	l o a d _ f m f _ c e l l 	*/
/*	-------------------------	*/

private	struct	standard_font * load_fmf_cell(
	struct	standard_font * fptr,
	int			i,
	char 		      * fbuffer,
	int			o)
{
	struct	standard_cell * cptr;
	int	w,h,l;
	if (!( h = (getw( (fbuffer+o) ) + fptr->margin) ))
		h = fptr->height;
	if ( h > o ) 	return( fptr );
	if (!( w = (getw( (fbuffer+o+2))+ fptr->margin) ))
		w = fptr->width;
	if ( w > o ) 	return( fptr );
	if (!( cptr = allocate_font_cell(w,h)))
		return( drop_font( fptr ) );
	else	{
		fptr->cell[i]=cptr;
		build_fmf_cell(w,h,fptr->margin,cptr->matrix,(fbuffer+o+8));
		return( fptr );
		}
}


/*	-------------------------	*/
/*	b u i l d _ h q _ n a m e 	*/
/*	-------------------------	*/
private	char *	build_hq_name( char * fbuffer, int * offset )
{
	int	x;
	int	o;
	char 	foundry[65];
	char 	family[65];
	int	weight=0;
	int	slant=0;
	int	setwidth=0;
	char 	pixels[65];
	char 	points[65];
	int	hresdpi=0;
	int	vresdpi=0;
	int	spacing=0;
	char 	average[65];
	char 	charset[65];
	char 	wname[65];
	int	wcharset;
	char 	wnature[65];

	o = *offset;

	if ((x = fontgets( foundry, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	if ((x = fontgets( family, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	weight   = getw( (fbuffer + o) ); o+= 2;
	slant    = getw( (fbuffer + o) ); o+= 2;
	setwidth = getw( (fbuffer + o) ); o+= 2;

	if ((x = fontgets( pixels, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	if ((x = fontgets( points, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	hresdpi  = getw( (fbuffer + o) ); o+= 2;
	vresdpi  = getw( (fbuffer + o) ); o+= 2;
	spacing  = getw( (fbuffer + o) ); o+= 2;

	if ((x = fontgets( average, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	if ((x = fontgets( charset, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	if ((x = fontgets( wname, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	wcharset = getw( (fbuffer + o) ); o+= 2;

	if ((x = fontgets( wnature, (fbuffer+ o), 64 )) > 65)
		return((char *) 0);
	else	o += x;

	*offset = o;

	return( sysfontname( 	foundry, family, weight,  slant, setwidth, pixels,  
				points,  hresdpi, vresdpi,spacing, average, charset, 
				wname, wcharset, wnature ) );
}

/*	-------------------	*/
/*	b u i l d _ f o n t  	*/
/*	-------------------	*/

private	struct	standard_font * build_font( char * fbuffer )
{
	struct	standard_font * fptr;
	struct	standard_cell * cptr;
	int	i,o,w,h,l;
	int	maxo;
	int	hqinfo=0;
	int	n;

	if (!(fptr = (struct standard_font *) allocate((l = sizeof( struct standard_font )) ) ))
		return( fptr );
	else	memset(fptr,0,l);

	maxo	       =getw((fbuffer + _FMF_SIZE));

	if ((fptr->flags = getw((fbuffer + _FMF_FLAGS))) == 'HP') {
		/* ---------------------------------------------------- */
		/* 		FONT FILE HEALTH WARNING		*/
		/* ---------------------------------------------------- */
		/* The fucking twassock Phillip Legay was here seeking 	*/
		/* immortality he stamped this zone  with his initials  */
		/* 							*/
		/*			PHL				*/
		/* 							*/
		/* 		   "what a cunt !" 			*/
		/* 							*/
		/*	   (copyright 1983 barry coombs esq.)		*/
		/* 							*/
		/* ---------------------------------------------------- */
		memset((fbuffer + _FMF_FLAGS),0,4);
		fptr->flags = 0;
		}
	if ( fptr->flags ) {
		fptr->height  = getw((fbuffer + _FMF_WIDTH));
		fptr->width   = getw((fbuffer + _FMF_HEIGHT));
		}
	else	{
		fptr->width   = getw((fbuffer + _FMF_WIDTH));
		fptr->height  = getw((fbuffer + _FMF_HEIGHT));
		}

	/* ----------------------------------------------------------------------- */
	/* Extension to FMF format to manage HQ System Font Extension for Printing */
	/* ----------------------------------------------------------------------- */
	if (((hqinfo = getw((fbuffer + _FMF_HQINFO))) != 0x2020) && (hqinfo != 0xFFFF) && ( hqinfo > 0 )) {
		if ( GigoXtrace & 1024 ) {
			printf("fmfHeader(w=%u,h=%u,f=%u,q=%u,o=%u)\r\n",
				fptr->width,fptr->height,fptr->flags,hqinfo,maxo);
			}
		maxo -= hqinfo;
		}

	fptr->margin = 0;
	fptr->buffer = fbuffer;
	fptr->buffersize =getw((fbuffer + _FMF_SIZE)); 

	/* ------------------------------------------------- */
	/* Standard FMF format Character Cell Matrix Loading */
	/* ------------------------------------------------- */
	for (i=0; i < 256; i++ ) {
		o = getw( (fbuffer+32+(i*2)) );
		if ( o > maxo ) {
			fptr->cell[i] = (void*)0;
			continue;
			}
		if ( fptr->flags != 0 ) {
			if (!( fptr = load_fon_cell( fptr,i,fbuffer,o) ))
				break;
			else	continue;
			}
		else if (!( fptr = load_fmf_cell( fptr,i,fbuffer,o) ))
			break;
		}

	/* ------------------------------------------------------------------------ */
	/* Extension to Font Builder Mechanisms to Integrate High Quality Font Info */
	/* ------------------------------------------------------------------------ */
	if ( hqinfo ) {

		o =  maxo;
		if ((n = getw((fbuffer+o))) > 8 )
			n = 8;
		o += 2;

		for (i=0; i < n; i++) {
			if (!( *(fbuffer+o) )) {
				fptr->hqname[i]=(char *) 0;
				o++;
				continue;
				}
			else	{
				o++;
				if (!( fptr->hqname[i]=build_hq_name(fbuffer,&o) ))
					break;
				if ( GigoXtrace & 1024 ) {
					printf("HqFontName[%u] = %s\r\n",i,fptr->hqname[i]);
					}
				}
			}
		}

	return( fptr );
}

/*		----------------------------------		*/
/*		g u i f o n t s t r u c t u r e ()		*/
/*		----------------------------------		*/

public	struct	standard_font * guifontstructure( int number )
{

	/* Ensure correct and loaded font identifier */
	/* ----------------------------------------- */
	if ( number >= MAX_FONTS )
		return((struct standard_font *) 0);
	else 	return( Gigo.graphicfonts[number] );
}


/*		--------------------------------		*/
/*		s e t _ h q _ f o n t n a m e ()		*/
/*		--------------------------------		*/

public	int	set_hq_fontname( int number, int item, char * hqfontname )
{
	struct	standard_font * fptr;
	char 		      * nptr;
	if ( item >= 8 ) 
		return(103); 
	else if ( item < 0 ) 
		return(102);
	if (!( fptr = guifontstructure( number )))
		return(118);
	else	{
		if ( fptr->hqname[item] ) { 
			fptr->hqname[item]  = liberate  ( fptr->hqname[item] ); 
			}
		if ( fptr->hqfont[item] ) {
			fptr->hqfont[item]  = drop_font ( fptr->hqfont[item] );
			}
		fptr->hqname[item] = hqfontname;
		return(0);
		}	
}

/*		--------------------------------		*/
/*		g e t _ h q _ f o n t n a m e ()		*/
/*		--------------------------------		*/

public	char * get_hq_fontname( int number, int item )
{
	char *	rptr;
	struct	standard_font * fptr;
	char 		      * nptr;
	if ( item >= 8 ) 
		return((char *) 0);
	else if ( item < 0 )
		return((char *) 0);
	if (!( fptr = guifontstructure( number )))
		return((char *) 0);
	else if (!( rptr = fptr->hqname[item] ))
		return(rptr);
	else	{
		if (( rptr = allocate( strlen(fptr->hqname[item])+1 )) != (char *) 0)
			strcpy(rptr,fptr->hqname[item]);
		return(rptr);
		}
}

/*	-------------------	*/
/*	a l i a s _ f o n t  	*/
/*	-------------------	*/

public	char *	alias_font(int number )
{
	struct	standard_font * fptr;
	if (!( fptr = guifontstructure(number) ))
		return( (char *) 0 );
	else	return( fptr->buffer );
}


/*	---------------------------	*/
/*	f o n t _ f i l e _ s i z e	*/
/*	---------------------------	*/

public	int	font_file_size(int number )
{
	struct	standard_font * fptr;
	if (!( fptr = guifontstructure(number) ))
		return( 0 );
	else	return( fptr->buffersize );
}

/*	---------------------		*/
/*	l o a d g u i f o n t		*/
/*	---------------------		*/


public	int	loadguifont( int number, char * buffer, int buflen )
{
	struct	standard_font * fptr;
	if ( number >= MAX_FONTS )
		return( 51 );
	if ( GigoXtrace & 1024 ) {
		printf("loadguifont(%u)\r\n",number);
		}
	fptr = build_font( buffer );
	if (!( fptr ))
		return(27);
	if ( Gigo.graphicfonts[number] ) {
		Gigo.graphicfonts[number] = drop_font(
			Gigo.graphicfonts[number] );
		}
	Gigo.graphicfonts[number] = fptr;

	return(0);
}

#ifdef	WIN32
#include "winsysfont.c"
#else
#include "sysfont.c"
#endif

/*	---------------------		*/
/*	l o a d   x   f o n t		*/
/*	---------------------		*/

public	int	loadsysfont( int number, char * nomfic )
{
	struct	standard_font * fptr;
	if ( number >= MAX_FONTS )
		return( 51 );
	else if (!( fptr = load_system_font( nomfic ) ))
		return(27);
	if ( Gigo.graphicfonts[number] )
		Gigo.graphicfonts[number] = drop_font(Gigo.graphicfonts[number] );
	Gigo.graphicfonts[number] = fptr;

	return(0);
}

/*	---------------------------		*/
/*	e s t a b l i s h _ f o n t		*/
/*	---------------------------		*/

public	int	establish_font( int number, char * bptr, int fs )
{
	return( loadguifont(number,bptr,fs ) );
}


/*	---------------------		*/
/*	g u i f o n t s i z e		*/
/*	---------------------		*/

public	int	guifontsize(int number)
{
	int	result=0;
	struct	standard_font * fptr;
	if (!( fptr = guifontstructure(number) ))
		return(result);
	else	return((fptr->width | ((fptr->height + Gigo.line_spacing) << 8)));;
}


/*	---------------------		*/
/*	l o a d   _   f o n t		*/
/*	---------------------		*/
public	char *	guifontlist()
{
	char *	tptr;
	char *	result=(char *) 0;
	int	number;
	char *	sptr;
	char *	rptr;
	for (number=1; number < MAX_FONTS ; number++ ) {
		if (!( sptr = Gigo.fontnames[number] ))
			continue;
		else if (!( tptr = allocate( strlen( sptr ) + 1 ) ))
			break;
		else	{
			fn_parser(sptr,tptr,0x0018);
			sptr = tptr;
			}
		if (!( result )) {
			if (!( rptr = allocate( strlen( sptr ) + 1 ) )) {
				liberate( tptr );
				break;
				}
			else	strcpy(rptr, sptr );
			result = rptr;
			liberate( tptr );
			continue;
			}
		else if (!( rptr = allocate( strlen( result ) + strlen( sptr ) + 10 ) )) {
			liberate( tptr );
			break;
			}
		else 	{
			sprintf(rptr,"%s|%s",result,sptr);
			liberate( result );
			result = rptr;
			liberate( tptr );
			continue;
			}
		}
	if ( GigoXtrace & 1024 ) {
		printf("guifontlist(%s)\r\n",result);
		}
	return( result );
}

public	int	load_font( int number, char * filename )
{
	FILE	* handle;
	int	fs;
	int	status=0;
	int	l;
	char *	bptr;
	char	fonthead[256];
	if ( GigoXtrace & 1024 ) {
		printf("load_font(%u,%s)\r\n",number,filename);
		}
	if ( *filename == '{' ) {
		if ((status = loadsysfont( number, (filename+1) )) != 0)
			return( status );
		if ( Gigo.fontnames[number] )
			liberate( Gigo.fontnames[number] );
		if ((Gigo.fontnames[number] = allocate( strlen(filename)+1 )) != (char *) 0)
			strcpy(Gigo.fontnames[number],filename);
		return(0);
		}
	else if (!(handle = fopen((filename = sysfilename(filename)),"rb")))
		return(40);
	else if ( fread(fonthead,256,1,handle) != 1) {
		fclose(handle);
		return(48);
		}
	else	{
		fs = getw((fonthead+_FMF_SIZE));
#ifndef	UNIX
		l = (fs / 256);
		if ( fs % 256 ) l++;
		l *= 256;
#else
		l = fs;
#endif
		if (!(bptr = allocate( l ))) {
			fclose(handle);
			return(27);
			}
		memcpy(bptr,fonthead,256);
		if ( fread((bptr+256),l-256,1,handle) != 1) {
			fclose(handle);
			bptr = liberate( bptr );
			return( 53 );
			}
		fclose(handle);
		if (!( status = establish_font( number,bptr,fs) )) {
			if ( Gigo.fontnames[number] )
				liberate( Gigo.fontnames[number] );
			if ((Gigo.fontnames[number] = allocate( strlen(filename)+1 )) != (char *) 0)
				strcpy(Gigo.fontnames[number],filename);
			}
		return( status );
		}

}


/*	-------------------------	*/
/*	u s e _ b a s e _ f o n t 	*/
/*	-------------------------	*/

public	int	use_base_font(int number)
{
	struct	standard_font * fptr;
	if (!( fptr = guifontstructure(number) ))
		return(118);
	else	{
		Gigo.workingfont =
		Gigo.currentfont = number;
		if ((Gigo.fontwidth  =  fptr->width) != 0)
			Gigo.columns =  (Gigo.width/Gigo.fontwidth);
		if ((Gigo.fontheight =  fptr->height) != 0)
			Gigo.lines   =  (Gigo.height/Gigo.fontheight);
		Gigo.xfontwidth = Gigo.fontwidth;
		Gigo.yfontheight= Gigo.fontheight;
		return( 0 );
		}		
}


/*	------------------------------------	*/
/*	f o n t c h a r a c t e r s i z e () 	*/
/*	------------------------------------	*/

public	int	fontcharactersize(int c, int number )
{
	struct	standard_cell * cptr;
	struct	standard_font * fptr;
	if (!( fptr = guifontstructure(number) ))
		return(0);
	else if (!( cptr = fptr->cell[(c & 0x00FF)] ))
		return(0);
	else	return((cptr->width & 0x00FF) | ((cptr->height & 0x00FF) << 8));
}

/*	------------------------------------	*/
/*	f o n t c h a r a c t e r d a t a () 	*/
/*	------------------------------------	*/

public	char *	fontcharacterdata(int c, int number )
{
	struct	standard_cell * cptr;
	struct	standard_font * fptr;
	if (!( fptr = guifontstructure(number) ))
		return((char *) 0);
	else if (!( cptr = fptr->cell[(c & 0x00FF)] ))
		return((char *) 0);
	else	return(& cptr->matrix);
}


/*	------------------------	*/
/*	g u i f o n t n a m e ()	*/
/*	------------------------	*/

public	char *	guifontname( int number )
{
	if ( number >= MAX_FONTS )
		return((char *)0);
	else if (!( Gigo.graphicfonts[number] ))
		return((char *) 0);
	else	return(  Gigo.fontnames[number] );
}

/*	------------------------	*/
/*	g u i f o n t i n f o ()	*/
/*	------------------------	*/

public	char *	guifontinfo( int number )
{
	struct	standard_font * fptr;
	if ( number >= MAX_FONTS )
		return((char *)0);
	else if (!(fptr = Gigo.graphicfonts[number] ))
		return((char *) 0);
	else	return(  fptr->hqname[0] );
}

/*	------------------------	*/
/*	g u i f o n t s a v e ()	*/
/*	------------------------	*/

public	int	guifontsave( int number, char * filename )
{
	struct	standard_font * fptr;
	if (!( fptr = guifontstructure(number) ))
		return(118);
	else	return(  write_standard_font( filename, fptr ) );
}


/*		----------------------------------------------------		*/
/*		s t a n d a r d _ f o n t _ l o a d ( fontfilename )		*/
/*		----------------------------------------------------		*/
/*		Loads a font into a low level font slot if one is		*/
/*		available and returns the font handle.				*/
/*		otherwise returns -1 to indicate all slots full.		*/	
/*		----------------------------------------------------		*/

public	int	standard_load_font( char * fontfilename )
{
	int	number;
	int	status;
	for ( number=1; number < MAX_FONTS; number++ )  {
		if (!( Gigo.graphicfonts[number] )) {
			if ((status = load_font( number, fontfilename )) != 0)
				break;
			else	return( number );
			}
		else if (!( Gigo.fontnames[number] ))
			continue;
		else if (!( strcmp(Gigo.fontnames[number],fontfilename) ))
			return( number ); 
		}
	return(0);
}

/*		----------------------------------------------		*/
/*		s t a n d a r d _ d r o p _ l o a d ( fontid )		*/
/*		----------------------------------------------		*/
public	int	standard_drop_font( int fontid )
{
	return(0);
}

/*		----------------------------------------------		*/
/*		s t a n d a r d _ f o n t _ s w a p ( fontid )		*/
/*		----------------------------------------------		*/
public	int	standard_font_swap( int fontid )
{
	if (!( Gigo.graphicfonts[fontid] ))
		return(0);
	else	{
		sysfontswap( Gigo.graphicfonts[fontid] );
		return(1);
		}
	return(0);
}
/*		----------------------------------------------		*/
/*		s t a n d a r d _ c e l l _ s w a p ( fontid )		*/
/*		----------------------------------------------		*/
public	int	standard_cell_swap( int fontid, int s, int t )
{
	struct	standard_font * fptr;
	struct	standard_cell * sptr;
	struct	standard_cell * tptr;
	if (!(fptr = Gigo.graphicfonts[fontid] ))
		return(0);
	else if (!( sptr = fptr->cell[(s & 0x00FF)] ))
		return(0);
	else if (!( tptr = fptr->cell[(t & 0x00FF)] ))
		return(0);
	else	{
		fptr->cell[s] = tptr;
		fptr->cell[t] = sptr;
		return(1);
		}
}




#endif	/* _stdfont_c */
	/* ---------- */


