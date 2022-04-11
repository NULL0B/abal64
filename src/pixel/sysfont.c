#ifndef	_sysfont_c
#define	_sysfont_c

#include "ansi.h"

static	int	iso_conversion=1;

static	struct	system_font_manager	{
	char **	fontnames;
	char *  selection;
	int	fontcount;
	} SysFontMan = { (char **) 0, (char *) 0, 0 };


public	void	dropsysfontlist()
{
	if ( SysFontMan.selection ) {
		liberate( SysFontMan.selection );
		SysFontMan.selection = (char *) 0;
		}
	if ( SysFontMan.fontnames ) {
		XFreeFontNames( SysFontMan.fontnames );
		SysFontMan.fontnames = (char **) 0;
		}
	SysFontMan.fontcount=0;
	return;
}

public	int	getsysfontlist( void ** vptr, char * wildcards, int wildlen )
{
	int	i;
	int	l;
	if (!( SysFontMan.selection )) {
		if (!( SysFontMan.selection = allocate( (wildlen+1) )))
			return(0);
		for (l=0,i=0; i < wildlen; i++ ) {
			switch (( *(SysFontMan.selection + i) = *(wildcards+i) )) {
				case	0 	:
					break;
				case	' '	:
					continue;
				default		:
					l = (i+1);
					continue;
				}
			break;
			}
		*(SysFontMan.selection + l) = 0;
		SysFontMan.fontnames = XListFonts(XGC.displayptr,SysFontMan.selection,20000,&SysFontMan.fontcount);
		}
	*vptr = SysFontMan.fontnames;
	return( SysFontMan.fontcount );
}


/*	------------------------------		*/
/*	i s _ w h i t e _ p i x e l ()		*/
/*	------------------------------		*/
/*	Returns TRUE if the indicated 		*/
/*	image pixel is white, otherwise		*/
/*	returns FALSE				*/
/*	------------------------------		*/

static	int	is_white_pixel( char * bptr, int c, int bytes )
{
	int	i;
	bptr += (c*bytes);
	if ( bytes == 4 )
		bytes--;
	for (i=0; i < bytes; i++)
		if ( (*(bptr+i) & 0x00FF) != 0x00FF)
			return(0);
	return(1);
}


/*	--------------------------------------		*/
/*	e x t r a c t _ i m a g e _ d a t a ()		*/
/*	--------------------------------------		*/
/*	Analyses the image data containing the		*/
/*	printed character and returns a standard	*/
/*	font cell containing the bitmap matrix		*/
/*	--------------------------------------		*/

static	struct	standard_cell * extract_image_data( 
			int character, 
			XImage * iptr,
			int width,
			int bytes
			)
{
	struct	standard_cell * cptr=(struct standard_cell *) 0;
	int	l,c,w,h;
	char *	bptr;
	char *	dptr;
	if (!( iptr ))
		return(cptr);
	else if (!( bptr = iptr->data ))
		return(cptr);
	else if (!( w = iptr->bytes_per_line ))
		return(cptr);
	else if (!( h = iptr->height ))
		return(cptr);
	else if (!( cptr = allocate_font_cell(width,h) ))
		return( cptr );

#ifdef	DEBUG_X11_FONTCH
	if ( verbose ) { printf("character : %c (w=%u,h=%u) \r\n",character,width,h); }
#endif
	dptr = &cptr->matrix[0];

	for ( l=0; l < h; l++ ) {
#ifdef	DEBUG_X11_FONTCH
		if ( verbose ) { printf("\t"); }
#endif
		for ( c = 0; c < width; c++ ) {
			if ( is_white_pixel( bptr, c, bytes ) )
				*(dptr+c) = 0;
			else	*(dptr+c) = 1;
#ifdef	DEBUG_X11_FONTCH
			if ( *(dptr+c) )
				printf("*");
			else	printf(" ");
#endif
			}
		dptr += width;
		bptr += iptr->bytes_per_line;
#ifdef	DEBUG_X11_FONTCH
		if ( verbose ) { printf("\r\n"); }
#endif
		}
#ifdef	DEBUG_X11_FONTCH
	if ( verbose ) { printf("\r\n"); }
#endif
	return(cptr);
}
			

/*	-----------------------------------------------		*/
/*		l o a d _ s y s t e m _ f o n t ()		*/
/*	-----------------------------------------------		*/
/*	Attempt to load a system specific font and if 		*/
/*	succesful returns a pointer to a standard font		*/
/*	structure containing the various character cells	*/
/*	-----------------------------------------------		*/


struct	standard_font * load_system_font( char * fontname )
{
	int	proportional=0;
	struct 	standard_cell * cellptr;
	struct	standard_font * fmfptr;
	char 	s[16];
	int	c;
	int	cc;
	int	i;
	int	clb;
	int	viewsize=0;
	int	width=0;
	int	height=0;
	int	cellwidth;
	int	cellheight;
	char *	symbolic=(char *) 0;
	char *	Symbolic=(char *) 0;
	XFontStruct * fptr;
	XCharStruct * cptr;
	Pixmap	      p;
	XImage * iptr=(XImage *) 0;

	if (!( fontname )) 
		return( (struct standard_font *) 0);	
	else if (!(Symbolic = allocate( strlen( fontname ) + 1 )))
		return( (struct standard_font *) 0);	
	else	strcpy((symbolic=Symbolic),fontname);

	/* Remove Packaging and other Bits */
	/* ------------------------------- */
	if ( *symbolic == '{' ) symbolic++;
	i = 0;
	while ( *(symbolic+i) != 0 ) {
		if ( *(symbolic+i) == '{' )
			break;
		else	i++;
		}
	*(symbolic+i) = 0;


	if (!( fptr = XLoadQueryFont(XGC.displayptr,symbolic) )) {
		liberate( Symbolic );
		return((struct standard_font *) 0);
		}

	cellwidth = fptr->max_bounds.rbearing;

	if ( fptr->min_bounds.lbearing < 0 )
		cellwidth -= fptr->min_bounds.lbearing;
	cellheight = (fptr->max_bounds.ascent+fptr->max_bounds.descent);

#ifdef	DEBUG_X11_FONT
	if ( verbose ) { printf("font : %s (w=%u, h=%u) \r\n",symbolic,cellwidth,cellheight); }
#endif

	if (!(p = XCreatePixmap( 
			XGC.displayptr,XGC.desktopwindow,
			cellwidth,cellheight,
			XGC.visdepth))) {
		XFreeFont(XGC.displayptr,fptr);
		return((struct standard_font *) 0);
		}

	else  if (!( fptr->per_char )) {
		XFreePixmap(XGC.displayptr, p);
		XFreeFont(XGC.displayptr,fptr);
		liberate( Symbolic );
		return((struct standard_font *) 0);
		}
	else if (!( fmfptr = allocate( sizeof( struct standard_font ) ) )) {
		XFreePixmap(XGC.displayptr, p);
		XFreeFont(XGC.displayptr,fptr);
		liberate( Symbolic );
		return( fptr );
		}
	else	{
		fmfptr->margin=0;
		fmfptr->flags=0;		
		fmfptr->buffer=(char *) 0;
		fmfptr->buffersize=0;

		for ( i=0; i < 256; i++ )
			fmfptr->cell[i] = (struct standard_cell *) 0;

		for ( i=0; i < 8; i++ ) {
			fmfptr->hqname[i] = (char *) 0;
			fmfptr->hqfont[i] = (struct standard_font *) 0;
			}

		fmfptr->width  = cellwidth;
		fmfptr->height = cellheight;
		XSetForeground(XGC.displayptr,XGC.gc,BlackPixel(XGC.displayptr,XGC.screen));
		XSetBackground(XGC.displayptr,XGC.gc,WhitePixel(XGC.displayptr,XGC.screen));
		XSetFont(XGC.displayptr,XGC.gc,fptr->fid);
#ifdef	DEBUG_X11_FONT
		if ( verbose ) {
			printf("Pixmap : %u origin at 0,%u : w=%u, h=%u\r\n",p,
				fptr->ascent,
				fptr->max_bounds.rbearing-fptr->min_bounds.lbearing,
				fptr->max_bounds.ascent+fptr->max_bounds.descent);
			printf("\tmax : w=%d, h=%d ( lb=%d, rb=%d, a=%d,d=%d )\r\n",
				fptr->max_bounds.width,
				fptr->max_bounds.ascent+fptr->max_bounds.descent,
				fptr->max_bounds.lbearing,
				fptr->max_bounds.rbearing,
				fptr->max_bounds.ascent,fptr->max_bounds.descent);
			printf("\tmin : w=%d, h=%d ( lb=%d, rb=%d, a=%d,d=%d )\r\n",
				fptr->min_bounds.width,
				fptr->min_bounds.ascent+fptr->min_bounds.descent,
				fptr->min_bounds.lbearing,
				fptr->min_bounds.rbearing,
				fptr->min_bounds.ascent,fptr->min_bounds.descent);
			}
#endif
		for (proportional=0,cptr=fptr->per_char,c=fptr->min_char_or_byte2;
			c<fptr->max_char_or_byte2;
			c++,cptr++ ) {
			if ( c > 255 )
				break;
			else if (!( cptr->width ))
				continue;
			else if ( cptr->width != cellwidth )
				proportional = 1;

			}

		for ( 	cptr=fptr->per_char,c=fptr->min_char_or_byte2;
			c<fptr->max_char_or_byte2;
			c++,cptr++ ) {
			if ( c > 255 )
				break;
			else if (!( cptr->width ))
				continue;
			else if ( c >= 32 ) {
				s[0] = c; s[1] = 0;
				XSetForeground(XGC.displayptr,XGC.gc,WhitePixel(XGC.displayptr,XGC.screen));
				XFillRectangle(XGC.displayptr,p,XGC.gc,0,0,cellwidth,cellheight);
				XSetForeground(XGC.displayptr,XGC.gc,BlackPixel(XGC.displayptr,XGC.screen));
				if ( cptr->lbearing < 0 )
					clb = 0 - cptr->lbearing;
				else	clb = 0;
				XDrawImageString(XGC.displayptr,p,XGC.gc,clb,fptr->ascent,s,1); 
#ifdef	DEBUG_X11_FONT
				if ( verbose ) {
					printf("\tchar : %u : w=%d, h=%d ( lb=%d, rb=%d, a=%d,d=%d )\r\n",
						c,
						cptr->width,
						cptr->ascent+cptr->descent,
						cptr->lbearing,
						cptr->rbearing,
						cptr->ascent,cptr->descent);
					}
#endif
				if (!( cellwidth ))
					break;
				else if ((iptr = XGetImage( XGC.displayptr,p,0,0,cellwidth,cellheight,AllPlanes,ZPixmap)) != (XImage*) 0) {
					c &= 0x00FF;
					if ( c == 32 )
						cellptr = allocate_font_cell( cptr->width, cellheight );
					else	{
						if (!( cellptr = extract_image_data( c, iptr,cellwidth, (iptr->bytes_per_line/cellwidth)))) {
							XDestroyImage( iptr );
							continue;
							}
						if ( proportional ) {
							if (!( cellptr = recalculate_font_cell( cellptr, 0 ) )) {
								XDestroyImage( iptr );
								continue;
								}
							}
						}
					if ( c < 128 )
						fmfptr->cell[c] = cellptr;
					else	{
						switch ( iso_conversion ) {
							case	0 : /* transparent font loading */
								fmfptr->cell[c] = cellptr; 
								break;
							case	1 : /* iso 8859-1 conversion */
								if ((cc = ansi_iso_character_set[c]) >= 128)
									fmfptr->cell[cc] = cellptr;
								else	liberate( cellptr );
								break;
		
							case	2 : /* iso 8859-2 conversion */
								if ((cc = iso_8859_2_character_set[c]) >= 128)
									fmfptr->cell[cc] = cellptr;
								else	liberate( cellptr );
								break;
		
							default	:
								liberate( cellptr );
							}
						}
					XDestroyImage( iptr );
					}
				else	break;
				}
			}
		XFreePixmap(XGC.displayptr, p);
		XFreeFont(XGC.displayptr,fptr);
		liberate( Symbolic );
		return( fmfptr );
		}
}


int	iso_conversion_value( int v )
{
	int	holder=iso_conversion;
	iso_conversion = v;
	return( holder );
}


void	sysfontswap( struct standard_font * fptr )
{
	struct 	standard_cell * sptr;
	struct 	standard_cell * tptr;
	int	c;
	int	cc;
	if (!( fptr ))
		return;
	for (	c=128; c < 256; c++ ) {
		if ((cc = ansi_iso_character_set[c]) < 128)
			continue;
		else if (!( sptr = fptr->cell[cc] ))
			continue;
		else if (!( tptr = fptr->cell[c] ))
			continue;
		else	{
			fptr->cell[c] = sptr;
			fptr->cell[cc] = tptr;
			}
		}
	return;
}

/*	---------------------------------------------------	*/
/*			s y s f o n t n a m e 			*/
/*	---------------------------------------------------	*/
/*	Builds a system font name for HQ alternative print	*/
/*	font loading mechanisms. 
/*	---------------------------------------------------	*/

char *	sysfontname( 
	char * 	foundry,
	char *  family,
	int	weight,
	int	slant,	
	int	setwidth,
	char *	pixels,
	char *	points,
	int	hresdpi,
	int	vresdpi,
	int	spacing,
	char *	average,
	char *	charset,
	char *	wname,
	int 	wcharset,
	char *	wnature )
{
	char	token[65];
	char *	rptr=(char *) 0;
	char *	wptr=(char *) 0;

	if (!( wptr = allocate( 2048 ))) return( wptr );

	strcpy((rptr = wptr),"{-"); rptr += strlen(rptr);

	if (( foundry ) && *(foundry)) 
		strcat( rptr, foundry ); 
	else	strcat(rptr,"*");

	strcat(rptr,"-");
	rptr += strlen(rptr);

	if (( family  ) && *(family )) 
		strcat( rptr, family );
	else	strcat( rptr,"*");

	strcat(rptr,"-");
	rptr += strlen(rptr);

#ifdef integer_family
	switch ( family ) {
		case	 0 : strcat(rptr,"*"); break;
		case	 1 : strcat(rptr,"charter"); break;
		case	 2 : strcat(rptr,"courier"); break;
		case	 3 : strcat(rptr,"helvetica"); break;
		case	 4 : strcat(rptr,"gothic"); break;
		case	 5 : strcat(rptr,"new century schoolbook"); break;
		case	 6 : strcat(rptr,"times"); break;
		case	 7 : strcat(rptr,"symbol"); break;
		case	 8 : strcat(rptr,"utopia"); break;
		case	 9 : strcat(rptr,"luxi moni"); break;
		case	10 : strcat(rptr,"luxi serif"); break;
		case	11 : strcat(rptr,"lucida"); break;
		case	12 : strcat(rptr,"lucidabright"); break;
		case	13 : strcat(rptr,"lucidatypewriter"); break;
		case	14 : strcat(rptr,"newspaper"); break;
		case	15 : strcat(rptr,"terminal"); break;
		case	16 : strcat(rptr,"fixed"); break;
		case	17 : strcat(rptr,"arial"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);
#endif
	switch ( weight ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"medium"); break;
		case	2 : strcat(rptr,"bold"); break;
		case	3 : strcat(rptr,"black"); break;
		case	4 : strcat(rptr,"regular"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( slant ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"r"); break;
		case	2 : strcat(rptr,"i"); break;
		case	3 : strcat(rptr,"o"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( setwidth ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"normal"); break;
		case	2 : strcat(rptr,"condensed"); break;
		case	3 : strcat(rptr,"narrow"); break;
		case	4 : strcat(rptr,"double width"); break;
		}
	strcat(rptr,"--");rptr += strlen(rptr);

	if ( pixels )  
		strcat( rptr, pixels ); 
	else	strcat(rptr,"*");

	strcat(rptr,"-");rptr += strlen(rptr);

	if ( points )  
		strcat( rptr, points ); 
	else	strcat(rptr,"*");

	strcat(rptr,"-");rptr += strlen(rptr);

	if (!( hresdpi ))
		strcpy(token,"*");
	else	sprintf(token,"%u",hresdpi);
	strcat( rptr, token );
	strcat(rptr,"-");rptr += strlen(rptr);

	if (!( vresdpi ))
		strcpy(token,"*");
	else	sprintf(token,"%u",vresdpi);
	strcat( rptr, token );
	strcat(rptr,"-");rptr += strlen(rptr);

	switch ( spacing ) {
		case	0 : strcat(rptr,"*"); break;
		case	1 : strcat(rptr,"m"); break;
		case	2 : strcat(rptr,"p"); break;
		case	3 : strcat(rptr,"c"); break;
		}
	strcat(rptr,"-");rptr += strlen(rptr);

	if ( average )  
		strcat( rptr, average ); 
	else	strcat(rptr,"*");

	strcat(rptr,"-");rptr += strlen(rptr);

	if ( charset )  
		strcat( rptr, charset ); 
	else	strcat(rptr,"*");

	strcat( rptr,"{");
	if ( wname )
		strcat( rptr,wname);
	else	strcat(rptr,"*");

	sprintf(token,"-%u",wcharset);
	strcat(rptr,token);
	if ( wnature )
		strcat( rptr,wnature);
	else	strcat(rptr,"*");
	strcat( rptr,"}");

	if (( rptr = allocate( strlen( wptr) + 1 )) != (char *) 0)
		strcpy( rptr, wptr );

	liberate( wptr );
	return( rptr );

}

static	char *	getsystoken( char * sptr, char * rptr, int n, int terminator )
{
	int	i;
	int	c;
	for (	i=0; i < n; i++ ) {
		if (!( *sptr ))
			break;
		else if ((c = *(sptr++)) == terminator )
			break;
		else	*(rptr++) = c;
		}
	*(rptr++) = 0;
	return( sptr );
}

void	anasysfontname( 
		char *	nptr,
		char * 	foundry,
		char *	family,
		int*	weight,
		int*	slant,	
		int*	setwidth,
		char *	pixels,
		char *	points,
		int*	hresdpi,
		int*	vresdpi,
		int*	spacing,
		char *	average,
		char *	charset,
		char *	wname,
		int*	wcharset,
		char *	wnature
		)
{
	char	token[65];
	int	v;
	int	c;
	int	i;
	strcpy(foundry,"*");
	strcpy(family ,"*");
	*weight = 0;
	*slant  = 0;
	*setwidth = 0;
	strcpy(pixels ,"*");
	strcpy(points ,"*");
	*hresdpi=0;
	*vresdpi=0;
	*spacing=0;
	strcpy(average,"*");
	strcpy(charset,"*");

	strcpy(wname,"*");
	*wcharset=0;
	strcpy(wnature ,"*");

	if ( *(nptr++) != '{' )
		return;
	else if ( *(nptr++) != '-' )
		return;

	nptr = getsystoken(nptr,foundry,64,'-');
	nptr = getsystoken(nptr,family,64,'-');

	nptr = getsystoken(nptr,token,64,'-');
	if (!( strcmp( token,"medium") ))
		*weight=1;
	else if (!( strcmp(token,"bold") ))
		*weight=2;
	else if (!( strcmp(token,"black") ))
		*weight=3;
	else if (!( strcmp(token,"regular") ))
		*weight=4;

	nptr = getsystoken(nptr,token,64,'-');
	switch ( token[0] ) {
		case	'r' : *slant = 1; break;
		case 	'i' : *slant = 2; break;
		case 	'o' : *slant = 3; break;
		}

	nptr = getsystoken(nptr,token,64,'-');
	if (!( strcmp( token,"normal") ))
		*setwidth=1;
	else if (!( strcmp(token,"condensed") ))
		*setwidth=2;
	else if (!( strcmp(token,"narrow") ))
		*setwidth=3;
	else if (!( strcmp(token,"double width") ))
		*setwidth=4;

	if ( *(nptr++) != '-' )
		return;

	nptr = getsystoken(nptr,pixels ,64,'-');
	nptr = getsystoken(nptr,points ,64,'-');

	nptr = getsystoken(nptr,token,64,'-');
	for (v=0,i=0; i < 64; i++ ) {
		if (( token[i] >= '0' ) && ( token[i] <= '9'))
			v = ((v*10) + (token[i] - '0'));
		else	break;
		}
	switch ( v ) {
		case	75	:	*hresdpi = 1; break;
		case	100	:	*hresdpi = 2; break;
		case	120	:	*hresdpi = 3; break;
		case	150	:	*hresdpi = 4; break;
		case	200	:	*hresdpi = 5; break;
		case	240	:	*hresdpi = 6; break;
		case	300	:	*hresdpi = 7; break;
		}
	*hresdpi=v;
	nptr = getsystoken(nptr,token,64,'-');
	for (v=0,i=0; i < 64; i++ ) {
		if (( token[i] >= '0' ) && ( token[i] <= '9'))
			v = ((v*10) + (token[i] - '0'));
		else	break;
		}
	*vresdpi = v;

	nptr = getsystoken(nptr,token,64,'-');
	switch ( token[0] ) {
		case	'm' : *spacing = 1; break;
		case 	'p' : *spacing = 2; break;
		case 	'c' : *spacing = 3; break;
		}

	nptr = getsystoken(nptr,average,64,'-');
	nptr = getsystoken(nptr,charset,64,'{');

	nptr = getsystoken(nptr,wname,64,'-');
	nptr = getsystoken(nptr,token,64,'-');
	for (v=0,i=0; i < 64; i++ ) {
		if (( token[i] >= '0' ) && ( token[i] <= '9'))
			v = ((v*10) + (token[i] - '0'));
		else	break;
		}
	*wcharset = v;
	nptr = getsystoken(nptr,wnature,64,'}');
	return;
}

public	struct standard_font * load_dynamic_system_font( char * hqn, int height )
{
	struct standard_font * fptr;
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
	char	wname[65];
	int	wcharset;
	char	wnature[65];
	char *	nptr;

	if (!( hqn )) { return( (struct standard_font *) 0); }

	anasysfontname( hqn, 	foundry,family, &weight, &slant,  &setwidth, 
				pixels,	points, &hresdpi,&vresdpi,&spacing,
				average,charset, wname, &wcharset,wnature );

	/* Reset these size control fields */
	/* ------------------------------- */
	if ( strcmp( pixels,"0" ) == 0 ) {
		sprintf(pixels,"%u",height);
		sprintf(points,"%u",height*10);
		strcpy(average,"*");
		vresdpi = hresdpi = 0;
		}

	if (!( nptr = sysfontname( 	foundry,family, weight, slant,  setwidth, 
				pixels,	points, hresdpi,vresdpi,spacing,
				average,charset, wname, wcharset, wnature ) )) { 
		return( (struct standard_font *) 0); 
		}
	else	{
#ifdef	DEBUG_X11_FONTCH
		printf("dynamic system font : %s ",nptr);
#endif
		fptr = load_system_font( nptr );
#ifdef	DEBUG_X11_FONTCH
		if (!( fptr ))
			printf(" : fail \r\n");
		else	printf(" : ok \r\n");
#endif
		liberate( nptr );
		return( fptr );
		}
}

#endif	/* _sysfont_c */
	/* ---------- */

