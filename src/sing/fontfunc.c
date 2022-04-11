#ifndef	_font_functions_c
#define	_font_functions_c


public	struct	standard_font * guifontstructure( int number );

private	struct standard_cell * copiedcell=(struct standard_cell *) 0;



/*	-------------------------------------------------	*/	
/*		f o n t _ p a s t e _ c e l l ()		*/
/*	-------------------------------------------------	*/	
/*	duplicates a the indicated character cell of the 	*/
/*	indicated font for eventual use by the character	*/
/*	pasting function below.					*/
/*	-------------------------------------------------	*/	

public	int	font_copy_cell(int c, int number)
{
	struct standard_font * fptr;
	struct	standard_cell * cptr;

	if (!( fptr = guifontstructure(number) ))
		return(118);
	if (!( cptr = fptr->cell[(c & 0x00FF)] ))
		return( 118 );
	if (copiedcell != (struct standard_cell *) 0) {
		liberate( copiedcell );
		copiedcell = (struct standard_cell *) 0;
		}
	if (!( copiedcell = allocate_font_cell( cptr->width, cptr->height ) ))
		return( 27 );
	else	{
		copy_font_cell( copiedcell, cptr );
		return( 0 );
		}
}


/*	-------------------------------------------------	*/	
/*		f o n t _ p a s t e _ c e l l ()		*/
/*	-------------------------------------------------	*/	
/*	duplicates a copied character into the indicated	*/
/*	character cell of the indicated font.			*/
/*	-------------------------------------------------	*/	

public	int	font_paste_cell(int c, int number)
{
	struct standard_font * fptr;
	struct	standard_cell * cptr;
	if (!( fptr = guifontstructure(number) ))
		return(118);
	if (!( copiedcell ))
		return( 118 );
	if (!( cptr = allocate_font_cell( copiedcell->width, copiedcell->height ) ))
		return( 27 );
	else	{
		copy_font_cell( cptr, copiedcell );
		if ( fptr->cell[(c & 0x00FF)] != (struct standard_cell *) 0) {
			liberate( fptr->cell[(c & 0x00FF)] );
			fptr->cell[(c & 0x00FF)] = (struct standard_cell *) 0;
			}
		fptr->cell[(c & 0x00FF)] = cptr;
		return( 0 );
		}

}

private	void	insert_font_line( struct standard_cell * cptr, int y )
{
	int	r;
	char *	mptr=cptr->matrix;
	for ( r=(cptr->height-1); r > y; r-- )
		memcpy(	(mptr + (r * cptr->width)),
			(mptr + ((r-1) * cptr->width)),
			cptr->width);
	
	memset(	(mptr + (y * cptr->width)),0,cptr->width);
	return;
}

private	void	delete_font_line( struct standard_cell * cptr, int y )
{
	int	r;
	char *	mptr=cptr->matrix;
	for ( r=y; r < (cptr->height-1); r++ )
		memcpy(	(mptr + (r * cptr->width)),
			(mptr + ((r+1) * cptr->width)),
			cptr->width);
	
	memset(	(mptr + ((cptr->height-1) * cptr->width)),0,cptr->width);
	return;
}


private	void	delete_font_column( struct standard_cell * cptr, int x )
{
	int	c;
	int	r;
	char *	mptr=cptr->matrix;
	for ( r=0; r < cptr->height; r++ ) {
		for (c=x; c < (cptr->width-1); c++ )
			*(mptr + (r * cptr->width) + c) = 
			*(mptr + (r * cptr->width) + (c+1));
		*(mptr + (r * cptr->width) + c) = 0;
		}
	return;
}

private	void	insert_font_column( struct standard_cell * cptr, int x )
{
	int	c;
	int	r;
	char *	mptr=cptr->matrix;
	for ( r=0; r < cptr->height; r++ ) {
		for (	c=(cptr->width-1);
			c > x;
			c-- )
			*(mptr + (r * cptr->width) + c) = 
			*(mptr + (r * cptr->width) + (c-1));
		*(mptr + (r * cptr->width) + c) = 0;
		}
	return;
}


/*	--------------------------------	*/
/*	g u i f o n t f u n c t i o n ()	*/
/*	--------------------------------	*/

public	int	guifontfunction(int number, int c, int operation, int parameter )
{
	struct	standard_font * fptr;
	struct	standard_cell * cptr;
	struct	standard_cell * kptr;

	if (!( fptr = guifontstructure(number) ))
		return(118);
	else	{
		switch ( operation ) {
			case	1 :	/* decrement character width */
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if (!( kptr = allocate_font_cell( cptr->width-1, cptr->height )))
					return(0);
				
				else	{
					copy_font_cell(kptr,cptr);
					liberate(cptr);
					fptr->cell[(c&0x00FF)] = kptr;
					return(0);
					}
			case	2 :	/* increment character width */
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if (!( kptr = allocate_font_cell( cptr->width+1, cptr->height )))
					return(0);
				else	{
					copy_font_cell(kptr,cptr);
					liberate(cptr);
					fptr->cell[(c&0x00FF)] = kptr;
					return(0);
					}
			case	3 :	/* decrement character height*/
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if (!( kptr = allocate_font_cell( cptr->width, cptr->height-1 )))
					return(0);
				else	{
					copy_font_cell(kptr,cptr);
					liberate(cptr);
					fptr->cell[(c&0x00FF)] = kptr;
					return(0);
					}
			case	4 :	/* increment character height*/
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if (!( kptr = allocate_font_cell( cptr->width, cptr->height+1 )))
					return(0);
				else	{
					copy_font_cell(kptr,cptr);
					liberate(cptr);
					fptr->cell[(c&0x00FF)] = kptr;
					return(0);
					}

			case	5 :	/* decrement font width */
				if ( fptr->width > 1 )
					fptr->width--;
				return( 0 );

			case	6 :	/* increment font width */
				fptr->width++;
				return( 0 );

			case	7 :	/* decrement font height*/
				if ( fptr->height > 1 )
					fptr->height--;
				return(0);

			case	8 :	/* increment font height*/
				fptr->height++;
				return(0);

			case	9 :	/* horizontal reflection*/
			case	10:	/* vertical   reflection*/
				return(0);

			case	20:	/* delete line   */
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if ( parameter > cptr->height )
					return(0);
				else if ( parameter < 1 )
					return(0);
				else	{
					delete_font_line(cptr,parameter-1);
					return(0);
					}

			case	21:	/* insert line   */
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if ( parameter > cptr->height )
					return(0);
				else if ( parameter < 1 )
					return(0);
				else	{
					insert_font_line(cptr,parameter-1);
					return(0);
					}
			case	22:	/* delete column */
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if ( parameter > cptr->width )
					return(0);
				else if ( parameter < 1 )
					return(0);
				else	{
					delete_font_column(cptr,parameter-1);
					return(0);
					}
			case	23:	/* insert column */
				if (!( cptr = fptr->cell[(c & 0x00FF)] ))
					return(0);
				else if ( parameter > cptr->width )
					return(0);
				else if ( parameter < 1 )
					return(0);
				else	{
					insert_font_column(cptr,parameter-1);
					return(0);
					}

			default	  :
				return(56);

			}
		}
}	


/*		--------------------------------------			*/
/*		f o n t _ s e m i _ g r a p h i c s ()			*/
/*		--------------------------------------			*/
/*									*/
/*		Regeneration of the semi graphics data			*/
/*		of the indicated font.					*/
/*									*/
/*		Returns:51	incorrect font number			*/
/*			118	font not loaded				*/
/*			27	allocation failure			*/
/*									*/
/*		--------------------------------------			*/

public	int	font_semi_graphics( int number )
{
	int	i;
	int	fw;
	int	fh;
	int	latx;
	int	ratx;
	int	taty;
	int	baty;
	int	rnbx;
	int	lnbx;
	int	bnby;
	int	tnby;
	struct standard_font * fptr;
	struct	standard_cell * cptr;
	struct	standard_cell * kptr;

	if (!( fptr = guifontstructure(number) ))
		return(118);

	/* Collect font dimensions and Calculate Semi Graphic Infos */
	/* -------------------------------------------------------- */
	fw  = fptr->width; 			fh = fptr->height;

	latx = (fw/2);	if (!(fw & 1))  { latx--; }	ratx = (latx+2);
	taty = (fh/2);	if (!(fh & 1))  { taty--; } 	baty = (taty+2);

	rnbx = (fw - ratx);		bnby = (fh - baty);
	lnbx = (fw - latx);		tnby = (fh - taty);

	/* from vertical to less than ALPHA */
	/* -------------------------------- */
	for (i=179; i < 224; i++ ) { 

		/* Load or Allocate the Character Cell */
		/* ----------------------------------- */
		while (!( cptr = fptr->cell[i] ))
			if (!( fptr->cell[i] = allocate_font_cell( fw, fh ) ))
				return(27);

		/* Check Cell Dimensions or Re-allocate */
		/* ------------------------------------ */
		if (( cptr->width  < fw )
		||  ( cptr->height < fh )) { 
			if (!( kptr = allocate_font_cell( fw, fh ) ))
				return(27);
			liberate( cptr );
			fptr->cell[i] = kptr;
			cptr = kptr;
			}

		/* Wipe the character cell */
		/* ----------------------- */
		switch ( i ) {
			case	219	: /* full square */
				fill_font_cell(cptr,0,0,fw,fh,1);
				break;

			case	223	: /* top half */
				fill_font_cell(cptr,0,0,fw,baty,1);
				break;

			case	220	: /* bottom half */
				fill_font_cell(cptr,0,baty,fw,bnby,1);
				break;

			case	221	: /* left half */
				fill_font_cell(cptr,0,0,ratx,fh,1);
				break;
			case	222	: /* right half */
				fill_font_cell(cptr,ratx,0,rnbx,fh,1);
				break;
			default		:
				fill_font_cell(cptr,0,0,fw,fh,0);
			}

		/* FULL  VERTICAL   */
		/* ---------------- */
		/* Codes requiring first full vertical bar */
		switch ( i ) {
			case	179 :
			case	180 :
			case	181 :
			case	182 :
			case	185 :
			case	186 :
			case	195 :
			case	197 :
			case	198 :
			case	199 :
			case	204 :
			case	206 :
			case	215 :
			case	216 :
				/* full height first vbar */
				fill_font_cell(cptr, latx,0,1,fh,1);
				break;
			}

		/* Codes requiring second full vertical bar */
		switch ( i ) {
			case	182 :
			case	185 :
			case	186 :
			case	199 :
			case	206 :
			case	215 :
				/* full height second vbar */
				fill_font_cell(cptr, ratx,0,1,fh,1);
				break;

			}

		/* LEFT  HORIZONTAL */
		/* ---------------- */
		/* Codes requiring first  short left horizontal bar */
		switch ( i ) {
			case	180	:
			case	181	:
			case	182	:
			case	184	:
			case	185	:
			case	187	:
			case	190	:
			case	191	:
			case	203	:
			case	206	:
			case	215	:
			case	217	:
				fill_font_cell(cptr, 0,baty,latx+1,1,1);
				break;
			}

		/* Codes requiring first  long left horizontal bar */
		switch ( i ) {
			case	183	:
			case	188	:
			case	189	:
			case	208	:
			case	210	:
				fill_font_cell(cptr, 0,baty,ratx+1,1,1);
			}

		/* Codes requiring second  short left horizontal bar */
		switch ( i ) {
			case 181	:
			case 184	:
			case 185	:
			case 188	:
			case 190	:		
			case 202	:
			case 206	:
				fill_font_cell(cptr, 0,taty,latx+1,1,1);
				break;
			}
		/* Codes requiring second long  left horizontal bar */
		switch ( i ) {
			case	187	:
				fill_font_cell(cptr, 0,taty,ratx+1,1,1);
				break;
			}

		/* RIGHT HORIZONTAL */
		/* ---------------- */
		/* Codes requiring first  short right horizontal bar */
		switch ( i ) {
			case	201	:
			case	203	:
			case	204	:
			case	206	:
				fill_font_cell(cptr,ratx,baty,rnbx,1,1);
			}

		/* Codes requiring first  long  right horizontal bar */
		switch ( i ) {
			case	192	:
			case	195	:
			case	198	:
			case	218	:
			case	200	:
			case	211	:
			case	212	:
			case	213	:
			case	214	:
				fill_font_cell(cptr,latx,baty,lnbx,1,1);
			}

		/* Codes requiring second short right horizontal bar */
		switch ( i ) {
			case	200	:
			case	202	:
			case	204	:
			case	206	:
				fill_font_cell(cptr,ratx,taty,rnbx,1,1);
			}
		/* Codes requiring second long  right horizontal bar */
		switch ( i ) {
			case	198	:
			case	201	:
			case	212	:
			case	213	:
				fill_font_cell(cptr,latx,taty,lnbx,1,1);
			}

		/* FULL  HORIZONTAL */
		/* ---------------- */
		/* Codes requiring first  full horizontal bar */
		switch ( i ) {
			case	193	:
			case	194	:
			case	196	:
			case	197	:
			case	202	:
			case	205	:
			case	207	:
			case	209	:
			case	215	:
			case	216	:
				/* full height first hbar */
				fill_font_cell(cptr, 0,baty,fw,1,1);
				break;
			}

		/* Codes requiring second full horizontal bar */
		switch ( i ) {
			case	203	:
			case	205	:
			case	207	:
			case	209	:
			case	216	:
				/* full height second hbar */
				fill_font_cell(cptr, 0,taty,fw,1,1);
				break;
			}

		/* UPPER VERTICAL */
		/* Codes requiring first long upper vertical */
		switch (i) {
			case	189	:
			case	190	:
			case	192	:
			case	193	:
			case	200	:
			case	208	:
			case	211	:
			case	212	:
			case	217	:
				fill_font_cell(cptr, latx, 0, 1, baty+1, 1 );
			}

		/* Codes requiring first short upper vertical */
		switch (i) {
			case	188	:
			case	202	:
			case	206	:
			case	207	:
				fill_font_cell(cptr, latx, 0, 1, taty+1, 1 );
			}

		/* Codes requiring second long upper vertical */
		switch (i) {
			case	188	:
			case	189	:
			case	208	:
			case	211	:
				fill_font_cell(cptr, ratx, 0, 1, baty+1, 1 );
			}

		/* Codes requiring second short upper vertical */
		switch (i) {
			case	200	:
			case	202	:
			case	204 	:
			case	206	:
				fill_font_cell(cptr, ratx, 0, 1, taty+1, 1 );
			}

		/* Codes requiring first  long  lower vertical */
		switch (i) {
			case	184 	:
			case	201	:
			case	213 :
				fill_font_cell(cptr,latx,taty,1,tnby,1);
			}
		/* Codes requiring first  short lower vertical */
		switch (i) {
			case	183 :
			case	187 :
			case	191 :
			case	194 :
			case	203 :
			case	206 :
			case	209 :
			case	210 :
			case	214 :
			case	218	:
				fill_font_cell(cptr,latx,baty,1,bnby,1);
			}
		/* Codes requiring second long  lower vertical */
		switch (i) {
			case	187 :
				fill_font_cell(cptr,ratx,taty,1,tnby,1);
			}
		/* Codes requiring second short lower vertical */
		switch (i) {
			case	201 :
			case	203 :
			case	183 :
			case	204 :
			case	206 :
			case	210 :
			case	214 :
				fill_font_cell(cptr,ratx,baty,1,bnby,1);
			}

		}
	/* Success */
	/* ------- */
	return(0);
}

/*		----------------------------------		*/
/*		f o n t _ r e c a l c u l a t e ()		*/
/*		----------------------------------		*/

public	int	font_recalculate( int number, int fixed )
{
	int	i;
	struct standard_font * fptr;
	struct	standard_cell * cptr;

	if (!( fptr = guifontstructure(number) ))
		return(118);
	else	{
		for (i=32; i < 179; i++ ) {
			if (!( cptr = fptr->cell[i] ))
				continue;
			else	fptr->cell[i] = recalculate_font_cell(cptr,fixed);
			}
		for (i=224; i < 256; i++ ) { 
			if (!( cptr = fptr->cell[i] ))
				continue;
			else	fptr->cell[i] = recalculate_font_cell(cptr,fixed);
			}
		return(0);
		}
}

/*		-----------------------------------		*/
/*		f o n t _ i m p o r t _ i m a g e()		*/
/*		-----------------------------------		*/

public	int	font_import_image( int number )
{
	struct standard_font * fptr;
	struct	standard_cell * cptr;

	if (!( fptr = guifontstructure(number) ))
		return(118);
	else	return(0);
}


/*		-----------------------------------		*/
/*		f o n t _ e x p o r t _ i m a g e()		*/
/*		-----------------------------------		*/

public	int	font_export_image( int number )
{
	struct	standard_font * fptr;
	struct	standard_cell * cptr;
	struct	standard_image * iptr;
	struct	standard_image * xptr;
	int	ascii=0;
	int	r;
	int	c;
	int	vr,vc;
	char *	bptr;
	char *	tempname;


	/* Ensure correct and loaded font identifier */
	/* ----------------------------------------- */
	if (!( fptr = guifontstructure(number) ))
		return(118);

	else if (!( tempname = allocate_string( "export.gif" ) ))
		return(27);

	SetPathSelection( system_imagepath );

	if ( accept_imagesave(
			&tempname, 
			&Context.imagepathitem,
			&Context.imageformat, 
			&Context.transparent ) == 27 ) {
		tempname = liberate( tempname );
		return(0);
		}
	else if (!( tempname = UsePathSelection( tempname, Context.imagepathitem ) ))
		return(27);

	else if (!(iptr = local_allocate_image((fptr->width*16),(fptr->height*16),Context.background,0) )) {
		tempname = liberate( tempname );
		return(27);
		}

	else	status_message(tempname,3);

	for (ascii=0,vr=0; vr < 16; vr++ ) {

		for (vc=0; vc < 16; vc++,ascii++ ) {

			if (!( cptr = fptr->cell[ascii] ))
				continue;

			for (r=0; r < cptr->height; r++ ) {
				if (!( bptr = connect_pixel_row( iptr->storage, (vr*fptr->height)+r ) ))
					break;		
				for (c=0; c < cptr->width; c++ ) {
					if ( cptr->matrix[((r*cptr->width)+c)] != 0 )
						*(bptr + (vc*fptr->width)+c) = Context.foreground;
					else	*(bptr + (vc*fptr->width)+c) = Context.background;
					}
				}
			}
		}

	if ( iptr ) {
		image_save( tempname, iptr,QUICK );
		iptr = local_drop_image( iptr );
		}
	if ( tempname )
		tempname = liberate( tempname );
	return(0);
}


#endif	/* _font_functions_c */
	/* ----------------- */

