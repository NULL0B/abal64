#define	_vtable_c

#include "vform.h"

public	int	is_valid_format( char * fptr )
{
	if (!( fptr ))
		return(0);
	else if (!( *fptr ))
		return(0);
	else if ( *fptr == '(' )
		return(1);
	else	return(0);
}

public	int	visual_format_length( char * fptr )
{
	int	fieldwidth=0;
	int	c;
	int	v;
	int	i;
	int	twidth;
	char *	wptr;

	if ( (!( fptr )) ||  ( *fptr != '(' ))	return(0);
	else	fptr++;

	twidth = 0;  wptr = fptr; 

	while ((c = *(wptr++)) != 0) {

		if ( c == ')' )
			break;

		else if ( c == ',' )
			continue;

		if (( c >= 'a') && ( c <= 'z' )) { c -= ('a' - 'A'); }

		switch ( c ) {
			case	'('	:
				continue;
			case	'/'	:
			case	'T'	:
			case	'$'	:
			case	'L'	:
			case	'R'	:
			case	'H'	:
				continue;
			case	'.'	:
				fieldwidth++;
				continue;
			case	'-'	:
			case	'+'	:
			case 	'O'	: 
			case	'Q'	:
			case	'D'	:
			case	'A'	:
			case	'N'	:
			case	'Z'	:
			case	'C'	:
			case	'B'	:
			case	'W'	:
			case	'U'	: 
				for ( v = 1; *wptr == c; wptr++ )
					v++;
				if (( *wptr >= '0' )
				&&  ( *wptr <= '9' )) {
					i = 0;
					while(( *wptr >= '0' )
					&&    ( *wptr <= '9' )) {
						i = ((i*10) + ( *(wptr++) - '0'));
						}
					v = ((v-1) + i);
					}
				fieldwidth += v;
				continue;
			}

		}
	return( fieldwidth );

}

public	int	vformat( char * fptr, int fieldwidth[], int maxfields, int linelength )
{
	int	c=0;
	int	v=0;
	int	i=0;
	int	fields=0;
	int	twidth=0;
	int	awidth=0;
	int	extra=0;
	int	f;
	int	zeros=0;
	char *	wptr;

	if ( (!( fptr )) ||  ( *fptr != '(' ))	return(0);
	else	fptr++;

	/* Calculate field count and sizes */
	/* ------------------------------- */
	for ( fields=0; fields < maxfields; fields++ )
		fieldwidth[fields] = 0;
											
	twidth = 0;  fields=0; wptr = fptr; fieldwidth[fields] = 0;

	while ((c = *(wptr++)) != 0) {

		if ( c == ')' ) {
			if (!( fieldwidth[fields]))
				zeros++;
			else 	fieldwidth[fields]++;
			twidth += fieldwidth[fields]; 
			fields++;
			fieldwidth[fields] = 0;
			break;
			}
		else if ( c == ',' ) {
			if (!( fieldwidth[fields]))
				zeros++;
			else 	fieldwidth[fields]++;
			twidth += fieldwidth[fields]; 
			fields++;
			fieldwidth[fields] = 0;
			continue;
			}
		if (( c >= 'a') && ( c <= 'z' )) { c -= ('a' - 'A'); }
		switch ( c ) {
			case	'('	:
				continue;
			case	'/'	:
			case	'T'	:
			case	'$'	:
			case	'L'	:
			case	'R'	:
			case	'H'	:
				continue;
			case	'.'	:
				fieldwidth[fields]++;
				continue;
			case	'-'	:
			case	'+'	:
			case 	'O'	: 
			case	'Q'	:
			case	'D'	:
			case	'A'	:
			case	'N'	:
			case	'Z'	:
			case	'C'	:
			case	'B'	:
			case	'W'	:
			case	'U'	: 
				for ( v = 1; *wptr == c; wptr++ )
					v++;
				if (( *wptr >= '0' )
				&&  ( *wptr <= '9' )) {
					i = 0;
					while(( *wptr >= '0' )
					&&    ( *wptr <= '9' )) {
						i = ((i*10) + ( *(wptr++) - '0'));
						}
					v = ((v-1) + i);
					}
				fieldwidth[fields] += v;
				continue;
			}

		}

	if (!( fields ))	return(0);

	if ( twidth < linelength ) {

		if ( zeros ) {
			awidth = ((linelength -twidth)/zeros);
			extra  = ((linelength -twidth)-(awidth * zeros));
			}
		else 	{
			awidth = ((linelength -twidth)/fields);
			extra  = ((linelength -twidth)-(awidth * fields));
			}

		for ( f=0; f < fields; f++ ) {
			if (!( 	zeros )) {
				fieldwidth[f] += awidth;
				if ( extra ) {
					fieldwidth[f]++;
					extra--;
					}
				break;
				}
			else if (!( fieldwidth[f] )) {
				fieldwidth[f] = awidth;
				if ( extra ) {
					fieldwidth[f]++;
					extra--;
					}
				break;
				}
			}
		}
	return( fields );
}

public	int	vfields( char * tptr, int fieldwidth[], int maxfields, int linelength )
{
	int	fields=0;
	int	twidth=0;
	int	awidth=0;
	int	f;
	char *	wptr;

	/* Calculate field count and sizes */
	/* ------------------------------- */
	for ( fields=0; fields < maxfields; fields++ )
		fieldwidth[fields] = 0;
											
	for (twidth=0,fields=0,wptr=tptr; *wptr != 0; wptr++ ) {
		if ( *wptr == '|' ) {
			twidth += fieldwidth[fields];
			fields++;
			}
		else	fieldwidth[fields]++;
		}

	twidth += fieldwidth[fields];

	if ( fieldwidth[fields] ) fields++;
		
	if (!( fields ))	return(0);

	/* Redistribute Surplus amongst fields */
	/* ----------------------------------- */
	if ( twidth < linelength ) {
		if (!(awidth = ((linelength - twidth)/fields))) {
			awidth = (linelength - twidth);
			for ( f=0; f < fields; f++ ) {
				if (!( 	awidth ))
					break;
				else	{
					fieldwidth[f]++;
					awidth--;
					}
				}
			}
		else	{
			twidth = ((linelength - twidth)-(awidth*fields));
			for ( f=0; f < fields; f++ ) {
				if (twidth ) {
					fieldwidth[f]++;
					twidth--;
					}
				fieldwidth[f] += awidth;
				}
			}
		}
	return( fields );
}


int	visual_table( int x, int y, int w, int h, int f, int fg, int bg,
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
	int	underspill=0;
	int	overspill=0;
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

	int	xh=0;
	int	r;
	int	a=0;
	int	ha=-1;
	int	zbg=0;
	int	adjust=0;
	int	relw=0;
	int	nbr;

	/* Handle CICO atributs */
	/* -------------------- */
	if ( options & _A_BOLD  ) a |= _PIXELCO_BOLD;
	if ( options & _A_LINE  ) a |= _PIXELCO_ULINE;

	/* if ( options & _A_SHADOW) a |= _PIXELCO_SHADOW; */

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

	ha = cicoatribut( a );

	/* disactivate output */
	/* ------------------ */
	hide();


	if (!( options  & 0x2000 ))
		xh = 0;
	else	{
		xh = 1;
		if( fh ) 
			h = (((h / fh) * fh) + (xh*2));
		else	h = (((h / fh) * fh)+xh);
		}

	/* Generate relief frame with background */
	/* ------------------------------------- */
	if ((options & 0x0007 ) < 4) 
		zbg = (options & 2 ? bg : standard_white);
	else	zbg = (options & 1 ? bg : standard_white);

	relief(x,y,w,h,standard_lolight,zbg,standard_hilight);
	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Generate black inside liner */
	/* --------------------------- */
	relief(x,y,w,h,standard_black,transparent,standard_black);

	if (!( options & 0x2000 )) {
		x += 1; y+= 1;
		w -= 2; h -= 2;
		}

	/* Establish Titles background fill */
	/* -------------------------------- */
	filzone( x,y,w,fh, standard_title);

	/* check for and perform row-wise zoning */
	/* ------------------------------------- */
	switch ( options & 0x0007 ) {
		case	1 :
		case	3 :
			zbg = (options & 2 ? bg-1 : standard_white-1);
			for ( r=(fh*2); (r+fh) < h; r+= (fh*2) )
				filzone(x,y+r,w,fh,zbg);
			break;
		}

	/* If a title has been provided */
	/* ---------------------------- */
	if ( tptr ) {

		/* Calculate title items */
		/* --------------------- */
		if ( options & _A_SHADOW) 
			cicocolour( standard_black,0 );
		else	cicocolour( standard_text, standard_title );

		/* Calculate Title widths , hence widths */
		/* ------------------------------------- */
		if (( options & 0x4000 )
		&&  ( is_valid_format( fptr ) ))
			fields = vformat(fptr,fieldwidth,_MAX_FORM_FIELDS,(w/fw));
		else 	fields = vfields(tptr,fieldwidth,_MAX_FORM_FIELDS,(w/fw));

		if ( fields != 0) {

			/* Print texts and vertical lines */
			/* ---------------------------- */
			dath = (standard_white | (standard_black << 8));
			for (lmargin=0,field=0; field < fields; field++ ) {
				for ( 	tlen=0,wptr=tptr; *wptr != 0; wptr++) {
					if ( *wptr == '|' )
						break;
					else	tlen++;
					}
				if ( tlen < fieldwidth[field] )
					padd = ((fieldwidth[field]-tlen)/2);
				else	padd = 0;

				if ( options & _A_SHADOW) {
					relw = (fieldwidth[field]*fw);
					if ( *wptr != '|' )
						if (( lmargin*fw) < w )
							relw = (w - (lmargin*fw));
					relief((lmargin*fw)+x,y-1,relw,fh+1,
						standard_hilight,standard_backwash,standard_lolight);
					adjust = fh;
					}					
				PixelFontLat(((lmargin+padd)*fw)+x,y,f,tptr,tlen);

				if ( *(wptr++) != '|' )
					break;
				else	{
					tptr = wptr;
					lmargin += fieldwidth[field];
					xfilzone((((lmargin*fw)+x)-1),y+adjust,1,h-adjust,dath);
					}
				}

			}


		/* check for text and space remaining */
		/* ---------------------------------- */
		if (( options & 0x8000 )) {
			/* previous one shot display method */
			/* -------------------------------- */
			if (( vptr ) && (( h-fh ) > fh)) {
				visual_text(x,y+fh,w,h-fh,f,fg,0,vptr,strlen(vptr), _A_NONE);
				}
			}
		else 	{

			/* New Line by Line and Cell by Cell display */
			/* ----------------------------------------- */
			ty=fh; 
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
					zbg = (options & 1 ? bg-1 : standard_white-1);
					for (lmargin=0,field=0; field < fields; field++ ) {
						if ((field+1) == fields)
							tw = (w - lmargin);
						else 	tw = (fieldwidth[field] * fw);
						if (!( field & 1 ))
							filzone(lmargin+x,y+fh,tw-1,(h-fh),zbg);
						lmargin += (tw-xh);			
						}
					break;

				case	6 :
				case	7 :
					zbg = (options & 1 ? bg-1 : standard_white-1);
					for ( nbr=0,r=fh; (r+fh) < h; r+= fh, nbr++ ) {
						for (lmargin=0,field=0; field < fields; field++ ) {
							if ((field+1) == fields)
								tw = (w - lmargin);
							else	tw = (fieldwidth[field] * fw);
							if (!( (field+nbr) & 1 ))
								filzone(lmargin+x,y+r,tw-1,fh,zbg);
							lmargin += (tw-xh);			
							}
						}
					break;
				}

			/* Display Texts */
			/* ------------- */
			if ( vptr != (char *) 0) {
				while ( (ty+fh) <= h ) {
					for (lmargin=0,field=0; field < fields; field++ ) {
						tw = (fieldwidth[field] * fw);
						visual_text(lmargin+x,ty+y,tw,fh,f,fg,0,vptr,fieldwidth[field], _A_NONE );
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
	return(0);		

}


#ifndef	_vtable_c
#define	_vtable_c

int	grvtable( int x, int y, int w, int h, int f, int fg, int bg,
		char * tptr, char * vptr, int options )
{
	int	fh;
	int	fw;
	int	items;
	char *	iptr;
	char *	dptr;
	int	zw=w;
	int	zh=h;
	int	zx=x;
	int	zy=y;
	int	cx;
	int	tw;
	int	dlen;
	int	c;
	int	extra=0;
	int	nb=0;

	/* Calculate font sizes */
	/* -------------------- */
	if (!( f )) fh = 0;
	else	{
		fw = guifontsize(f);
		fh = (( fw >> 8) & 0x00FF);
		fw &= 0x00FF;
		}

	if (( w < fw )
	||  ( h < fh ))
		return(0);

	hide();

	relief(x++,y++,w,h,standard_lolight,standard_white,standard_hilight);
	w -= 2; h -= 2;

	relief(x++,y++,w,h,standard_black,transparent,standard_black);
	w -= 2; h -= 2;

	filzone( x,y,w,fh, standard_title);

	if ( tptr ) {

		/* Calculate title items */
		/* --------------------- */
		cicocolour( standard_text, standard_title );

		for (	nb=0,tw=0,cx=x,dlen=0, dptr = tptr, iptr = tptr; 
			cx < (x+w);
			iptr++ ) {
			switch ( c = *iptr ) {
				case	0	:
				case	'|'	:
				*iptr = 0;

				while ((cx + (tw = textsizelen(f,dptr,dlen))) >= (x+w)) {
					if (!( dlen ))
						break;
					else	dlen--;
					}	
				if ( dlen )
					nb++;

				cx += (tw+1);

				if (!( *iptr = c ))
					break;
				else	{
					dptr = (iptr+1); dlen=0;
					continue;
					}
				default		:
					dlen++;
					continue;
				}
			break;
			}
		
		/* distribute the remainder */
		cx -= x;

		if (( cx < w  )
		&&  ( nb != 0 ))
			extra = ((w - cx) / nb);


		/* display title items */

		for (	tw=0,cx=x,dlen=0, dptr = tptr, iptr = tptr; 
			cx < (x+w);
			iptr++ ) {
			switch ( c = *iptr ) {
				case	0	:
				case	'|'	:
				*iptr = 0;

				while ((cx + (tw = textsizelen(f,dptr,dlen))) >= (x+w)) {
					if (!( dlen ))
						break;
					else	dlen--;
					}	

				if ( dlen )
					PixelFontLat(cx+(extra/2),y,f,dptr,dlen);

				if (!( *iptr = c ))
					break;
				else	{
					dptr = (iptr+1); dlen=0;
					cx += (tw+extra);
					xfilzone(cx++,y,1,h,(standard_white | (standard_black << 8)));
					continue;
					}
				default		:
					dlen++;
					continue;
				}
			break;
			}
		if (( vptr ) 
		&&  (( h-fh ) > fh)) {
			visual_text(x,y+fh,w,h-fh,f,fg,0,vptr,strlen(vptr),_A_NONE);
			}
		}
	show( zx,zy,zw,zh);
	return(0);		

}

#endif 	/* _vtable_c */


