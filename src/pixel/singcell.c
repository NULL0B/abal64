private	void	fill_font_cell( 
			struct standard_cell * cptr,
			int atx, int aty, int nbx, int nby, int state )
{
	int	x;
	int	y;
	for (	y=0; y < nby; y++ ) {
		if ( y < cptr->height ) {
			for (	x=0; x < nbx; x++ ) {
				if ( x < cptr->width )
					cptr->matrix[((aty+y)*wptr->w)+(atx+x)] = state;
				else	break;
				}
			}
		else	break;
		}
	return;
}


public	int	font_semi_graphics( struct standard_font * fptr )
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
	struct	standard_cell * cptr;
	struct	standard_cell * kptr;

	fw  = fptr->width; 			fh = fptr->height;

	latx = (fw/2);	if (!(fw & 1))  { latx--; }	ratx = (latx+2);
	taty = (fh/2);	if (!(fh & 1))  { taty--; } 	baty = (taty+2);

	rnbx = (fw - ratx);		bnby = (fh - baty);
	lnbx = (fw - latx);		tnby = (fh - taty);

	for (i=179; i < 224; i++ ) { /* from vertical to less than ALPHA */

		while (!( cptr = fptr->cell[i] ))
			if (!( cptr = allocate_cell( fw, fh ) ))
				return(27);

		if (( cptr->width  < fw )
		||  ( cptr->height < fh )) { 
			if (!( kptr = allocate_cell( fw, fh ) ))
				return(27);
			liberate_cell( cptr );
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
			case	204 	:
			case	206 :
			case	210 :
			case	214 :
				fill_font_cell(cptr,ratx,baty,1,bnby,1);
			}

		}
	return(0);
}



