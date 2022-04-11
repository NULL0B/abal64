#ifndef	_font_writer_c
#define	_font_writer_c


/*	-------------------------------------------------------		*/
/*			F O N T _ W R I T E R				*/
/*	-------------------------------------------------------		*/
/*									*/
/*	This file provides the necessary functions required for		*/
/*	the creation and update of abal standard and portable		*/
/*	font files. These files store character information in		*/
/*	in compacted bitmap format cells referenced via the		*/
/*	character offset table. These structures are preceeded		*/
/*	by a standard file header.					*/
/*									*/
/*	The file structure may be described as follows 			*/
/*									*/
/*		char 	signature[16]					*/
/*		ishort	filesize;					*/
/*		ishort	fontheight;					*/
/*		ishort	fontwidth;					*/
/*		ishort	reserved[5];					*/
/*									*/
/*		ishort	characteroffset[256];				*/
/*									*/
/*		struct	cell	{					*/
/*			ishort	height;					*/
/*			ishort	width;					*/
/*			ishort	reserved[2];				*/
/*			char	data[(height*width/8)];			*/
/*			}						*/
/*									*/
/*	-------------------------------------------------------		*/

static	int	fontfileoffset=0;
static	int	fontoffsets[256];

/*	-----------------------------		*/
/*	f o n t o u t p u t b y t e()		*/
/*	-----------------------------		*/

static	int	fontoutputbyte(FILE * h, int v)
{
	fprintf(h,"%c",v);
	return(++fontfileoffset);
}

static	int	fontoutputstring(FILE * h, char * s)
{
	while ( *s )
		fontoutputbyte(h, *(s++) );
	fontoutputbyte(h,0);
	return 0;
}

/*	-----------------------------		*/
/*	f o n t o u t p u t w o r d()		*/
/*	-----------------------------		*/

static	int	fontoutputword(FILE * h, int v)
{
	fontoutputbyte(h,(v & 0x00FF));
	return( fontoutputbyte(h,((v>> 8) & 0x00FF)) );
}

/*	-----------------------------		*/
/*	f o n t o u t p u t c e l l()		*/
/*	-----------------------------		*/

static	int	fontoutputcell(FILE * h, struct standard_cell * cptr, int fw, int fh , int id)
{
	int	maxcol=0;
	int	maxrow=0;
	int	toprow=0;
	int	rotor=0x80;
	int	value=0;
	int	n,nn;
	int	i;
	char *	sptr;
	int	o=fontfileoffset;

	if (!( cptr )) {
		/* empty cell */
		for (i=0; i < 4; i++ )
			fontoutputword(h,0);
		n = ((fw*fh)/8)+1;
		for (i=0; i < n; i++ )
			fontoutputbyte(h,0);
		return(o);
		}

	sptr = cptr->matrix;

#ifdef	DEBUG_FONT_WRITER
	if ( verbose ) { printf("output_character : %u , 0x0%x : w=%u, h=%u \n",id,id,cptr->width,cptr->height); }
#endif
	fontoutputword(h,cptr->height);
	fontoutputword(h,cptr->width );
	fontoutputword(h,0);
	fontoutputword(h,0);

	for (nn=0; nn < cptr->height; nn++ ) {
		for (n=0; n < cptr->width; n++ ) {
			if (!( rotor )) {
				rotor = 0x80;
				value = 0;
				}
			if ( *(sptr++) != 0 ) {
#ifdef	DEBUG_FONT_WRITER
				if ( verbose ) { printf("*"); }
#endif
				value |= rotor;
				}
#ifdef	DEBUG_FONT_WRITER
			else if ( verbose ) { printf("."); }
#endif
			rotor >>= 1;
			if (!( rotor )) {
				fontoutputbyte( h, value );
				rotor = 0x80;
				value = 0;
				}
			}
#ifdef	DEBUG_FONT_WRITER
		if ( verbose ) { printf("\n"); }
#endif
		for (; n < cptr->width; n++ )
			sptr++;
		}
	if ( rotor != 0x80 )
		fontoutputbyte( h, value );
	return(o);
}

/*	--------------------------------	*/
/*	f o n t o u t p u t r a n g e ()	*/
/*	--------------------------------	*/

static	int	fontoutputrange( FILE * h,struct standard_font * fptr, int first, int last)
{
	struct standard_cell * cptr;
	int	i;
	for ( i=first; i <= last; i++ ) {
		if (( cptr = fptr->cell[i]) != (struct standard_cell *) 0) {
			if ( cptr->width > fptr->width )
				cptr->width = fptr->width;
			if ( cptr->height < fptr->height )
				cptr->height = fptr->height;
			}
		fontoffsets[i] = fontoutputcell(h,fptr->cell[i],fptr->width,fptr->height,i); 
		}
	return(0);
}

static	void	fontoutputhq( FILE * h, char * hqn )
{
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

	if (!( hqn )) return;

	anasysfontname( hqn, 	foundry,family, &weight, &slant,  &setwidth, 
				pixels,	points, &hresdpi,&vresdpi,&spacing,
				average,charset, wname, &wcharset,wnature );

	fontoutputstring( h, foundry );
	fontoutputstring( h, family  );

	fontoutputword  ( h, weight  );
	fontoutputword  ( h, slant   );
	fontoutputword  ( h, setwidth);

	fontoutputstring( h, pixels  );
	fontoutputstring( h, points  );

	fontoutputword  ( h, hresdpi );
	fontoutputword  ( h, vresdpi );
	fontoutputword  ( h, spacing );

	fontoutputstring( h, average );
	fontoutputstring( h, charset );

	/* ----------------------------- */
	/* extension specific to windows */
	/* ----------------------------- */
	fontoutputstring( h, wname   );
	fontoutputword  ( h, wcharset);
	fontoutputstring( h, wnature );

	return;
}


/*	-----------------------------------------------------------	*/
/*	w r i t e _ s t a n d a r d _ f o n t ( filename, fontptr )	*/
/*	-----------------------------------------------------------	*/
/*	Writes the font structure out to the indicated file with the	*/
/*	standard abal portable font character matrix format.		*/
/*	-----------------------------------------------------------	*/

public	int	write_standard_font( char * nptr, struct standard_font * fptr)
{
	int	i;
	int	hqoffset=0;
	int	fcoffset;
	FILE *	h;

	if (!(h = fopen(nptr,"wb"))) {

		/* Failure */
		/* ------- */
		return(46);

		}
	else	{

		/* Initialise file header fields */
		/* ----------------------------- */
		fontfileoffset = 0;	
		for ( i=0; i < 16; i++  ) fontoutputbyte (h,0);
		for ( i=0; i < 16; i++  ) fontoutputbyte (h,0);

		/* Initialise Character Offset Table */
		/* --------------------------------- */
		for ( i=0; i < 256; i++ ) fontoutputword (h,(fontoffsets[i] = (512+32)));
#ifdef	OPTIMISED_FONT_WRITER
		if ( optimise ) {
			/* Output Selected Optimised Ranges */
			/* -------------------------------- */
			optimise=0;
			fontoutputrange(h,fptr,0x0020,0x0020);
			fontoutputrange(h,fptr,0x0030,0x0039);
			fontoutputrange(h,fptr,0x0041,0x005A);
			fontoutputrange(h,fptr,0x0061,0x007A);
			fontoutputrange(h,fptr,0x0021,0x002F);
			fontoutputrange(h,fptr,0x005B,0x0060);
			fontoutputrange(h,fptr,0x007B,0x007F);
			fontoutputrange(h,fptr,0x0080,0x00DF);
			}
		else
#endif
			/* Output All Character Cells to the File */
			fontoutputrange(h,fptr,0,255);

		/* Generate Hiqh Quality Font Items */
		/* -------------------------------- */
		fcoffset = fontfileoffset;
		fontoutputword(h,8);
		for ( i=0; i < 8; i++ ) {
			if ( fptr->hqname[i] != 0 ) {
				fontoutputbyte(h,1);
				fontoutputhq(h, fptr->hqname[i] );
				}
			else	{
				fontoutputbyte(h,0);
				}
			}
		hqoffset = (fontfileoffset - fcoffset);

		/* Reposition to the Header Zone */
		/* ----------------------------- */
		fseek(h,16L,SEEK_SET);

		/* Update the header fields */
		/* ------------------------ */
		fontoutputword(h, fontfileoffset );
		fontoutputword(h, fptr->height   );
		fontoutputword(h, fptr->width    );
		fontoutputword(h, 0 );
		fontoutputword(h, hqoffset );

		/* Reposition to the Offset Table */
		/* ------------------------------- */
		fseek(h,32L,SEEK_SET);

		/* Write the Offset Table to The File */
		/* ---------------------------------- */
		for ( i=0; i < 256; i++ ) { fontoutputword (h,fontoffsets[i]); }
		fclose(h);

		/* Success */
		/* ------- */
		return(0);
		}
}

#endif	/* _font_writer_c */
	/* -------------- */


