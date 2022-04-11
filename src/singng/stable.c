#include "vform.h"

static	char * stylenames[_MAX_FORM_FIELDS];

static	char * table_token( char * sptr, char * tptr, int tlen, char * dptr )
{
	int	i;

	/* remove white space */
	/* ------------------ */
	while ( *sptr == ' ' ) 	{ sptr++; 		}
	if (!( *sptr )) 	{ return((char *) 0 );	}

	/* copy default */
	/* ------------ */
	strcpy(tptr,dptr);

	/* return default if empty */
	/* ----------------------- */
	if (*sptr == ',' )	{ return((sptr+1));	}
		
	/* collect style token */
	/* ------------------- */
	for ( i=0; i < tlen; i++ ) {
		if (( *sptr >= 'a' ) && ( *sptr >= 'z' ))
			*(tptr + i) = *(sptr++);
		else if (( *sptr >= 'A' ) && ( *sptr >= 'Z' ))
			*(tptr + i) = *(sptr++);
		else if (( *sptr >= '0' ) && ( *sptr >= '9' ))
			*(tptr + i) = *(sptr++);
		else if (( *sptr >= '-' ) || ( *sptr >= '.' ))
			*(tptr + i) = *(sptr++);
		else	break;
		}

	/* terminate the token */
	/* ------------------- */
	*(tptr+i) = 0;

	/* remove trailing space */
	/* --------------------- */
	while ( *sptr == ' ' ) 	{ sptr++; 		}

	/* detect terminal symbol */
	/* ---------------------- */
	if (*sptr == ',' )
		return( (sptr+1) );
	else if ( *sptr == ']' )
		return( sptr );
	else 	return( (char *) 0 ); 

}


public	void	release_table_style( int styleinfo )
{
	int	i;
	/* release eventual style names */
	/* ---------------------------- */
	for (i=0; i < styleinfo; i++ ) {
		if ( stylenames[i] ) {
			liberate( stylenames[i] );
			stylenames[i] = (char *) 0;
			}
		}
	return;
}

int	styled_table_columns( char * fptr, char * dptr )
{
	int	i;
	int	n=0;
	char	stylename[256];

	/* scan forward past format to style class infos */
	/* --------------------------------------------- */
	while ( *fptr ) {
		if ( *fptr == '[' )
			break;
		else	fptr++;
		}

	/* no style information available */
	/* ------------------------------ */
	if ( *(fptr++) != '[' ) return(0);


	/* indicate style info present */
	/* --------------------------- */
	while ( 1 ) {

		/* Avoid table overflow */
		/* -------------------- */
		if ( n >= _MAX_FORM_FIELDS ) {	break;	}

		/* detect end of style information */
		/* ------------------------------- */
		if ( *fptr == ']' ) { break; }

		/* collect a style token */
		/* --------------------- */
		if (!( fptr = table_token( fptr, stylename, 255, dptr )))
			break;
		else if (!( stylenames[n] = allocate_string( stylename )))
			break;
		else	{
			n++;
			}
		}
	return(n);
}

char *	styled_table_column(int n)
{
	if ( n < _MAX_FORM_FIELDS )
		return( stylenames[n] );
	else	return( (char *) 0 );
}


int	styled_table( int x, int y, int w, int h, int f, int fg, int bg,
		char * tptr, char * vptr, int options, char * fptr )
{
	/* these four are for the hide / show */
	/* ---------------------------------- */
	int	ty,tw;
	int	xs;

	int	zw=w;
	int	zh=h;
	int	zx=x;
	int	zy=y;
	int	fh=0;
	int	fw=0;

	/* Field width calculations */
	/* ------------------------ */
	int	extra=0;
	int	overspill=0;
	int	underspill=0;
	int	field;
	int	fields;
	int	fieldwidth[_MAX_FORM_FIELDS];

	/* text display and bars */
	/* --------------------- */
	int	dath;
	int	tlen;
	int	padd;
	int	lmargin=0;
	char *	wptr;

	int	r;
	int	a=0;
	int	ha=-1;
	int	zbg=0;
	int	adjust=0;
	int	relw=0;
	int	nbr;
	int	xh=0;
	int	hh=0;
	int	i;
	int	styleinfo=0;
	char *	tdptr=(char *) 0;
	int	status;

	/* Handle CICO atributs */
	/* -------------------- */
	if ( options & _A_BOLD  ) a |= _PIXELCO_BOLD;
	if ( options & _A_LINE  ) a |= _PIXELCO_ULINE;

	/* Calculate font sizes */
	/* -------------------- */
	if (!( f ))
		return(0);		
	else	{
		fw = guifontsize(f);
		if (!(fh = (( fw >> 8) & 0x00FF)))
			return(0);		
		fw &= 0x00FF;
		if (!( fw ))
			return(0);		
		}

	/* Ensure legal zone */
	/* ----------------- */
	if (( w < fw )
	||  ( h < fh ))
		return(0);

	/* Check overall table width calculation */
	/* ------------------------------------- */
	if (!( options & 0x2000 )) {
		if ((xs = ((w - 4) % fw)) != 0)
			w -= xs;
		}
	else if ((xs = (w % fw)) != 0)
		w -= xs;
	
	zw = w;

	/* Remove Leading space form Titles */
	/* -------------------------------- */

	if ( tptr ) {

		hh = resolve_style_height( "tablerow" );

		while ( *tptr ) {
			if ( *tptr != ' ' )
				break;
			else	tptr++;
			}
		if ( *tptr )
			if (!( hh ))
				hh = fh;
		}

	/* Detect eventual table cell style information */
	/* -------------------------------------------- */
	if ( fptr )
		styleinfo = styled_table_columns( fptr, "tabledata" );
	else	styleinfo = 0;

	ha = cicoatribut( a );

	/* disactivate output */
	/* ------------------ */
	hide();

	if (!( options  & 0x2000 ))
		xh = 0;
	else	{
		xh = 1;
		if( hh ) 
			h = (((h / fh) * fh) + (xh*2));
		else	h = (((h / fh) * fh)+xh);
		}
	visual_element( x,y,w,h, "tabletray", " ",0);
	status = visual_element( x,y,w,h, "tableframe", " ",0);
	/* relief(x++,y++,w,h,standard_lolight,zbg,standard_hilight); */

	/* Test for compact table */
	/* ---------------------- */
	if (!( options  & 0x2000 )) {
		x += 1;     y += 1;
		w -= 2; h -= 2;
		}

	/* Generate black inside liner */
	/* --------------------------- */
	status = visual_element( x,y,w,h, "tableinner", " ",0);
	/* relief(x++,y++,w,h,standard_black,transparent,standard_black); */

	/* Test for compact table */
	/* ---------------------- */
	if (!( options & 0x2000 )) {
		x += 1;     y += 1;
		w -= 2; h -= 2;
		}

	/* Establish Titles background fill */
	/* -------------------------------- */
	/* filzone( x,y,w,fh, standard_title); */

	/* Calculate Title widths , hence widths */
	/* ------------------------------------- */
	if (( options & 0x4000 )
	&&  ( is_valid_format( fptr ) ))
		fields = vformat(fptr,fieldwidth,_MAX_FORM_FIELDS,(w/fw));
	else if (( tptr ) && ( *tptr ))
		fields = vfields(tptr,fieldwidth,_MAX_FORM_FIELDS,(w/fw));
	else	fields = 0;

	/* check for and perform row-wise zoning */
	/* ------------------------------------- */
	switch ( options & 0x0007 ) {
		case	1 :
		case	3 :
			if ( hh ) {
				y += (xh*2);
				for ( r=(fh*2); (r+fh) < h; r += (fh*2) ) {
					visual_element( x,y+r,w,fh, "tablerow", " ",0);
					}
				for (lmargin=0,field=0; field < fields; field++ ) {
					if ((field+1) == fields)
						tw = (w - lmargin);
					else 	tw = (fieldwidth[field] * fw);
					if (!( field & 1 ))
						visual_element(lmargin+x,y+hh-xh,tw/*-1*/,(h-(fh+xh)),"tablecolumn"," ",0);
					lmargin += (tw-xh);			
					}
				if ( hh ) { y -= (xh*2); }
				}
			else	{
				for ( r=0; (r+fh) < h; r += (fh*2) ) {
					visual_element( x,y+r,w, fh, "tablerow", " ",0);
					}
				for (lmargin=0,field=0; field < fields; field++ ) {
					if ((field+1) == fields)
						tw = (w - lmargin);
					else 	tw = (fieldwidth[field] * fw);
					if (!( field & 1 ))
						visual_element(lmargin+x,y,tw/*-1*/,h,"tablecolumn"," ",0);
					lmargin += (tw-xh);			
					}
				}

			break;
		}


	/* If a title has been provided */
	/* ---------------------------- */
	if (( hh ) && ( fields != 0)) {

		/* Print texts and vertical lines */
		/* ---------------------------- */
		for (lmargin=0,field=0; field < fields; field++ ) {
			for ( 	tlen=0,wptr=tptr; *wptr != 0; wptr++) {
				if ( *wptr == '|' )
					break;
				else	tlen++;
				}
			if ( tlen < fieldwidth[field] )
				padd = ((fieldwidth[field]-tlen)/2);
			else	padd = 0;

			if ((field+1) == fields)
				tw = (w - lmargin);
			else 	tw = (fieldwidth[field] * fw);
			tdptr = "tableheader";
			visual_element(lmargin+x,y,tw,(fh+(xh*2)),tdptr,tptr,tlen);
			if ( *(wptr++) != '|' )
				break;
			else	{
				tptr = wptr;
				lmargin += (tw-xh);			
				}
			}

		y += (xh*2);
		}


	if ( fields  != 0 ) {

		/* check for text and space remaining */
		/* ---------------------------------- */
		if (( options & 0x8000 )) {
			/* previous one shot display method */
			/* -------------------------------- */
			if (( vptr ) && (( h-fh ) > fh)) {
				visual_text(x,y+hh,w,h-hh,f,fg,0,vptr,strlen(vptr), _A_NONE);
				}
			}
		else 	{

			/* New Line by Line and Cell by Cell display */
			/* ----------------------------------------- */
			if(!( ty=hh ))
				ty = xh;

			for (extra=0,field=0;field < fields; field++)
				extra += fieldwidth[field];

			if ( extra > (w / fw ))
				overspill = (extra - (w/fw));
			else if ( extra < (w / fw))
				underspill = ((w/fw)-extra);

			/* check for and perform column-wise zoning */
			/* ---------------------------------------- */
			switch ( options & 0x0007 ) {

				case	4 :
				case	5 :
					for (lmargin=0,field=0; field < fields; field++ ) {
						if ((field+1) == fields)
							tw = (w - lmargin);
						else 	tw = (fieldwidth[field] * fw);
						if (!( field & 1 ))
							visual_element(lmargin+x,y+hh,tw/*-1*/,(h-(hh+(xh*2))),"tablecell"," ",0);
						lmargin += (tw-xh);			
						}
					break;

				case	6 :
				case	7 :
					for ( nbr=0,r=hh; (r+fh) < h; r+= fh, nbr++ ) {
						for (lmargin=0,field=0; field < fields; field++ ) {
							if ((field+1) == fields)
								tw = (w - lmargin);
							else	tw = (fieldwidth[field] * fw);
							if (!( (field+nbr) & 1 ))
								visual_element(lmargin+x,y+r,tw/*-1*/,fh,"tablecell"," ",0);
							lmargin += (tw-xh);			
							}
						}
					break;
				}

			/* Display Texts */
			/* ------------- */
			if ( vptr != (char *) 0) {
				while ( (ty+fh) <= (h+xh) ) {
					for (lmargin=0,field=0; field < fields; field++ ) {
						if ((field+1) == fields)
							tw = (w - lmargin);
						else 	tw = (fieldwidth[field] * fw);
						if (!( styleinfo ))
							tdptr = "tabledata";
						else if ( field < styleinfo )
							tdptr = stylenames[field];
						else	tdptr = "tabledata";
						visual_element(lmargin+x,ty+y-xh,tw,(fh+xh),tdptr,vptr,fieldwidth[field]);
						vptr += fieldwidth[field];
						lmargin += (tw-xh);
						}
					ty += fh;
					vptr += underspill;
					vptr -= overspill;
					}
				}
			}
		}
	show( zx,zy,zw,zh);
	a = cicoatribut( ha );
	release_table_style(styleinfo);
	return(0);		
}

