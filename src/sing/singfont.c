#include <stdio.h>
#include "sing.h"
#include "palet.h"
#include "stdpsu.h"
#include "guimouse.h"
#include "singrel.h"
#include "singpix.h"
#include "allocate.h"
#define	_SYSTEM_IMAGES
#include "sysimage.h"
#include "stdimage.h"
#include "singprod.h"
#include "singmenu.h"
#include "singprot.h"

extern	char *	system_fontpath;
extern	char *	system_imagepath;
extern	char	namebuffer[];
extern	struct	screen_control	Context;
static	char *	ThisFontName=(char *) 0;

char *	alias_font( int number );

#include "singconf.h"
#include "singgrid.c"

#define	_FONT0	"standard.fmf\0             "
#define	_FONT1	"standard.fmf\0             "
#define	_FONT2	"font2.fmf\0                "
#define	_FONT3	"font3.fmf\0                "
#define	_FONT4	"font4.fmf\0                "
#define	_FONT5	"font5.fmf\0                "
#define	_FONT6	"font6.fmf\0                "
#define	_FONT7	"font7.fmf\0                "
#define	_FONT8	"font8.fmf\0                "
#define	_FONT9	"font9.fmf\0                "
#define	_FONT10	"standard.fmf\0             "

#include "singfont.h"

private	char * english_message[]= {
	"Font Editor",
	"Character",
	"Width",
	"Height",
	"Font"
	};

private	unsigned char	CharacterMap[256] = {
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
	0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
	0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
	' ','!','"','#','$','%','&',27,'(',')','*','+',',','-','.','/',
	'0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
	'@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_',
	27,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
	'p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',127,
	'C','u','e','a','a','a','a','c','e','e','e','i','i','i','A','A',
	'E',145,146,'o','o','o','u','u','y','O','U',155,156,157,156,159,
	'a','i','o','u','n','N',166,167,168,169,170,171,172,173,174,175,
	176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
	192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
	208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
	224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
	240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
	};



private	char * french_message[]= {
	"Editeur de Fontes",
	"CaractŠre",
	"Largeur",
	"Hauteur",
	"Fonte"
	};

public 	char * _default_font_name[FONT_MAX] = {
	_FONT0, _FONT1,
	_FONT2, _FONT3,
	_FONT4, _FONT5,
	_FONT6, _FONT7,
	_FONT8,	_FONT9,_FONT10

	};

public 	char * font_name[FONT_MAX] = {
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0,
	(char *) 0
	};

private	int	paper_type=0;

public 	int	font_window( struct font_context * wptr );

private	int	font_language=0;

private	char *	font_message(int number)
{
	if (!( font_language ))
		return( english_message[number] );
	else	return( french_message[number] );
}

private	void	font_save(int number,  char * nptr, int automatic )
{
	FILE	*	h;
	int		flen;
	int		nlen=0;
	char *		fptr;
	char	* tempname;


	if (!( tempname = relative_filename( nptr, system_fontpath )))
		return;

	if ( automatic != _FILE_QSAVE ) {
		if ( accept_fontsave( & tempname ) == 27 ) {
			tempname = liberate( tempname );
			return;
			}			
		else	status_message(tempname,3);
		}

	if (((fptr = alias_font(number)) != (char *) 0) 
	&&  ((flen = font_file_size(number)) != 0 )) {
		if ((h = open_production_target(tempname,1)) != (FILE*) 0) {
			fwrite(fptr,flen,1,h);
			close_production_target(h,tempname);
			}
		}
	tempname = liberate( tempname );
	return;
}

public 	void	font_load(int number, char * nptr, int mode )
{
	int	v;
	char	* fnptr;
	char	* tempname;
	int	  ansiflag=1; /* iso 8859-1 conversion to FMF */

	if (!( nptr ))
		return;

	if (!( tempname = allocate_string( nptr ) ))
		return;

	if ( mode ) {
		if ( accept_fontload( & tempname, &ansiflag ) == 27 ) {
			tempname = liberate( tempname );
			return;
			}			
		else	status_message(tempname,3);
		}

	if (!(Context.FontTable[number].state = local_load_font(number,tempname) )) {
		if ((v = guifontsize(number)) != 0) {
			Context.FontTable[number].width =(v & 0x00FF);
			Context.FontTable[number].height=((v >> 8) & 0x00FF);
			if ((fnptr = font_name[number]) != (char *) 0)
				fnptr = liberate( fnptr );
			font_name[number] = tempname;
			}
		else	tempname = liberate( tempname );
		}
	else	tempname = liberate( tempname );
	return;
}

public 	void	load_FontTable()
{
	int	i;
	int	v;

	if ((v = guifontsize(1)) != 0) {
		Context.FontTable[0].width =(v & 0x00FF);
		Context.FontTable[0].height=((v >> 8) & 0x00FF);
		Context.FontTable[1].width =(v & 0x00FF);
		Context.FontTable[1].height=((v >> 8) & 0x00FF);
		}

	for (i=FONT_MIN; i < FONT_MAX; i++ ) {
		Context.FontTable[i].width=Context.FontTable[i].height=0;
		if ( SingConf ) {
			font_load(i,SingConf->fontname[i-1],0);
			}
		}
	return;
}

public	void	drop_FontTable()
{
	int	i;
	char * fnptr;
	for (i=FONT_MIN; i < FONT_MAX; i++ ) {
		Context.FontTable[i].width=Context.FontTable[i].height=0;
		local_drop_font(i);
		if ((fnptr = font_name[i]) != (char *) 0)
			fnptr = liberate( fnptr );
		}
}

private	char *	fontworkzone=(char *) 0;

public 	int	load_FonCell( int w, int h, int cw, int ch, int margin, char * rptr, char * sptr,int dlen, int avoid )
{
	int	n,r,x,y,v,nbr;

	memset(rptr,0,(nbr=(w*h)));
	rptr += (w*margin); h-= (2*margin); ch -= (2*margin);
	r=0; x=0; y=0; v=0; 
	for (y=0; y < nbr; y += w ) {
		for (r=0,n=0; n < w; n++ ) {
			if (!(r)) { 
				if ( x < dlen ) {
					r = 0x0080; 
					v = (*(sptr+x) & 0x00FF); 
					x++; 
					}
				else	{
					return( 0 );
					}
				}
			if ( v & r )
				*(rptr+y+n) = 1;		
			else	*(rptr+y+n) = 0;		
			r >>= 1;
			}
		}
	return(0);
}

public 	int	load_FmfCell( int w, int h, int cw, int ch, int margin, char * rptr, char * sptr, int avoid )
{
	int	rotor=0;
	int	value=0;
	int	n,nn;
	memset(rptr,0,(w*h));
	rptr += (w*margin); h-= (2*margin); ch -= (2*margin);
	for (nn=0; nn < ch; nn++ ) {
		for (n=0; n < cw; n++ ) {
			if ( avoid ) {
				avoid--;
				*rptr = 0;
				}
			else	{
				if (!( rotor )) {
					rotor = 0x80;
					value = *(sptr++);
					}
				if ( value & rotor )
					*rptr = 1;
				else	*rptr = 0;
				rotor >>= 1;
				}
			rptr++;
			}
		/* step over extra space for proportional fonts */
		for (; n < w; n++ ) rptr++;
		}
	return(0);
}

private	void	check_fontworkzone(struct font_context * wptr)
{
	if (!( fontworkzone ))
		fontworkzone = allocate( (wptr->w * wptr->h) );
	return;
}

public 	void	load_Character(struct font_context * wptr , int c, int operation )
{
	int	nature=0;
	int	dlen=0;
	void *	vptr;
	char *	fptr;
	char *	cptr;
	short *	sptr;
	int	offset;
	int	ch,cw;
	wptr->operation = 0;
	if (!( wptr->font ))
		return;
	else if (!(vptr = alias_font( wptr->font ) ))
		return;
	else 	check_fontworkzone(wptr);
	sptr =  (short *) vptr;
	offset = *(sptr +16+ (c & 0x00FF));
	fptr   = (char *) vptr;
	cptr   = (char *) vptr;

	/* Phucking Fillip Lugey */
	/* --------------------- */
	if ((nature = *(fptr + 16 + 2 + 2 + 2)) == 'P')
		nature = 0;

	fptr  += offset;

	if ( nature ) {
		/* This is the FMF */
		/* --------------- */
		if ((wptr->w_cell = *(fptr+2)) > wptr->w) {
			/* The maximum cell size is less than the largest character */
			/* Whoops : this needs correction of the buffer size	    */
			Context.FontTable[wptr->font].width = wptr->w_cell;
			font_window( wptr );
			load_Character(wptr , c, operation );
			}
		else 	{
			wptr->h_cell = (*(fptr+4) + *(fptr+5));
			dlen = ((*fptr & 0x00FF) + (( *(fptr+1) & 0x00FF ) << 8));
			load_FonCell( 	wptr->w, 	wptr->h,
					wptr->w_cell,	wptr->h_cell, 
					wptr->margin, 
					fontworkzone, (fptr +8),dlen, operation);
			}
		}
	else	{
		/* This is the FMF */
		/* --------------- */
		wptr->h_cell = *fptr;
		wptr->w_cell = *(fptr + 2);
		/* The maximum cell size is less than the largest character */
		/* Whoops : this needs correction of the buffer size	    */
		if (wptr->w_cell > wptr->w) {
			Context.FontTable[wptr->font].width = wptr->w_cell;
			font_window( wptr );
			load_Character(wptr , c, operation );
			}
		else	{
			load_FmfCell( 	wptr->w, 	wptr->h,
					wptr->w_cell,	wptr->h_cell, 
					wptr->margin, 
					fontworkzone, (fptr +8),operation);
			}
		}
	return;

}


public 	int	save_FontCell( int w, int h, int cw, int ch, int margin, char * sptr, char * rptr )
{
	int	rotor=0x80;
	int	value=0;
	int	n,nn;
	sptr += (w*margin); h-= (2*margin); ch -= (2*margin);
	for (nn=0; nn < h; nn++ ) {
		for (n=0; n < cw; n++ ) {
			if (!( rotor )) {
				rotor = 0x80;
				value = 0;
				}
			if ( *(sptr++) != 0 )
				value |= rotor;
			rotor >>= 1;
			if (!( rotor )) {
				*(rptr++) = (value & 0x00FF);
				rotor = 0x80;
				value = 0;
				}
			}
		for (; n < w; n++ )
			sptr++;
		}
	if ( rotor != 0x80 )
		*(rptr++) = (value & 0x00FF);
	return(0);
}

private void	invert_Character(struct font_context * wptr )
{
	int	l;
	int	c;

	for (	l=0; l < wptr->h; l++ ) {
		for (c=0; c < wptr->w; c++) {
			if ( *(fontworkzone+(l*wptr->w)+c) != 0 )
				*(fontworkzone+(l*wptr->w)+c) = 0;
			else	*(fontworkzone+(l*wptr->w)+c) = 1;
			}
		}		
	return;
}

public 	void	save_Character(struct font_context * wptr , int c )
{
	void *	vptr;
	char *	fptr;
	short *	sptr;
	int	i;
	int	offset;
	if (!( wptr->font ))
		return;
	else if (!(vptr = alias_font( wptr->font ) ))
		return;
	else 	check_fontworkzone(wptr);

	sptr =  (short *) vptr;
	offset = *(sptr +16 + (c & 0x00FF));
	fptr   = (char *) vptr;
	fptr  += offset;

	/* reset cell meta data */
	/* -------------------- */
	for (i=0; i < 8; i++ ) { *(fptr+i) = 0; }

	*fptr 	  = wptr->h_cell; 
	*(fptr+2) = wptr->w_cell;

	save_FontCell( 	wptr->w, 	wptr->h,
			wptr->w_cell,	wptr->h_cell, 
			wptr->margin, 
			fontworkzone, (fptr +8) );
	return;
}

public 	void	fontfill( 
			struct font_context * wptr , 
			int atx, int aty, int nbx, int nby, int state )
{
	int	x;
	int	y;
/*
	if ( state )
		printf("\tfontfill( %u,%u, %u,%u (fw=%u,fh=%u)\r\n",
			atx,aty,nbx,nby,wptr->w,wptr->h);

	if (((aty + nby) > wptr->h)
	||  ((atx + nbx) > wptr->w))
		printf("exceeding font zone\r\n");
 */
	for (	y=0; y < nby; y++ ) {
		if ( y < wptr->h ) {
			for (	x=0; x < nbx; x++ ) {
				if ( x < wptr->w )
					*(fontworkzone + ((aty+y)*wptr->w)+(atx+x)) = state;
				else	break;
				}
			}
		else	break;
		}
	return;
}

public	void	calculate_cell_proportions( struct font_context * wptr )
{
	int	c,r;
	int	maxc;
	for (maxc=0,r=0; r < wptr->h; r++ )
		for ( c=0; c < wptr->w; c++ )
			if ( *(fontworkzone+(r*wptr->w)+c) != 0)
				if (c > maxc) 
					maxc = c;

	if ((wptr->w_cell = (maxc+3)) > wptr->w)
		if ((wptr->w_cell =(maxc+2)) > wptr->w)
			if ((wptr->w_cell =(maxc+1)) > wptr->w)
				wptr->w_cell = wptr->w;

	return;
}

public	void	calculate_proportions( struct font_context * wptr )
{
	int	i;

	if (!( wptr ))
		return;
	else	check_fontworkzone(wptr);

	for (i=32; i < 179; i++ ) {
		load_Character(wptr,i,0);
		calculate_cell_proportions(wptr);
		save_Character(wptr,i);
		}

	for (i=224; i < 256; i++ ) { 
		load_Character(wptr,i,0);
		calculate_cell_proportions(wptr);
		save_Character(wptr,i);
		}
	return;
}

public	void	generate_semi_graphics( struct font_context * wptr )
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

	fw  = wptr->w; 			fh = wptr->h;

	latx = (fw/2);	if (!(fw & 1))  { latx--; }	ratx = (latx+2);
	taty = (fh/2);	if (!(fh & 1))  { taty--; } 	baty = (taty+2);

	rnbx = (fw - ratx);		bnby = (fh - baty);
	lnbx = (fw - latx);		tnby = (fh - taty);

	for (i=179; i < 224; i++ ) { /* from vertical to less than ALPHA */

		load_Character( wptr, i, 0 );
		wptr->w_cell = fw; wptr->h_cell = fh;

		/* Wipe the character cell */
		/* ----------------------- */
		switch ( i ) {
			case	219	: /* full square */
				fontfill(wptr,0,0,fw,fh,1);
				break;

			case	223	: /* top half */
				fontfill(wptr,0,0,fw,baty,1);
				break;

			case	220	: /* bottom half */
				fontfill(wptr,0,baty,fw,bnby,1);
				break;

			case	221	: /* left half */
				fontfill(wptr,0,0,ratx,fh,1);
				break;
			case	222	: /* right half */
				fontfill(wptr,ratx,0,rnbx,fh,1);
				break;
			default		:
				fontfill(wptr,0,0,fw,fh,0);
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
				fontfill(wptr, latx,0,1,fh,1);
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
				fontfill(wptr, ratx,0,1,fh,1);
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
				fontfill(wptr, 0,baty,latx+1,1,1);
				break;
			}

		/* Codes requiring first  long left horizontal bar */
		switch ( i ) {
			case	183	:
			case	188	:
			case	189	:
			case	208	:
			case	210	:
				fontfill(wptr, 0,baty,ratx+1,1,1);
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
				fontfill(wptr, 0,taty,latx+1,1,1);
				break;
			}
		/* Codes requiring second long  left horizontal bar */
		switch ( i ) {
			case	187	:
				fontfill(wptr, 0,taty,ratx+1,1,1);
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
				fontfill(wptr,ratx,baty,rnbx,1,1);
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
				fontfill(wptr,latx,baty,lnbx,1,1);
			}

		/* Codes requiring second short right horizontal bar */
		switch ( i ) {
			case	200	:
			case	202	:
			case	204	:
			case	206	:
				fontfill(wptr,ratx,taty,rnbx,1,1);
			}
		/* Codes requiring second long  right horizontal bar */
		switch ( i ) {
			case	198	:
			case	201	:
			case	212	:
			case	213	:
				fontfill(wptr,latx,taty,lnbx,1,1);
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
/*	case	203	:	*/
			case	205	:
			case	207	:
			case	209	:
			case	215	:
			case	216	:
				/* full height first hbar */
				fontfill(wptr, 0,baty,fw,1,1);
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
				fontfill(wptr, 0,taty,fw,1,1);
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
				fontfill(wptr, latx, 0, 1, baty+1, 1 );
			}

		/* Codes requiring first short upper vertical */
		switch (i) {
			case	188	:
			case	202	:
			case	206	:
			case	207	:
				fontfill(wptr, latx, 0, 1, taty+1, 1 );
			}

		/* Codes requiring second long upper vertical */
		switch (i) {
			case	188	:
			case	189	:
			case	208	:
			case	211	:
				fontfill(wptr, ratx, 0, 1, baty+1, 1 );
			}

		/* Codes requiring second short upper vertical */
		switch (i) {
			case	200	:
			case	202	:
			case	204 	:
			case	206	:
				fontfill(wptr, ratx, 0, 1, taty+1, 1 );
			}

		/* Codes requiring first  long  lower vertical */
		switch (i) {
			case	184 	:
			case	201	:
			case	213 :
				fontfill(wptr,latx,taty,1,tnby,1);
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
				fontfill(wptr,latx,baty,1,bnby,1);
			}
		/* Codes requiring second long  lower vertical */
		switch (i) {
			case	187 :
				fontfill(wptr,ratx,taty,1,tnby,1);
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
				fontfill(wptr,ratx,baty,1,bnby,1);
			}

		save_Character( wptr, i );
		}
	return;
}

private	void	font_pixel(struct font_context * wptr, int c, int l )
{
	if ( *(fontworkzone+(l*wptr->w)+c) != 0 )
		filzone((wptr->x+(c*8)+1),(wptr->y+(l*8)+1),7,7,Context.foreground);
	else	filzone((wptr->x+(c*8)+1),(wptr->y+(l*8)+1),7,7,Context.background);
	return;
}

public 	void	font_data( struct font_context * wptr, int mode )
{
	int	c,l;
	int	i;
	char	buffer[32];
	if (!( fontworkzone ))
		return;

	if ( mode )
		hide();	
	
	i = (Context.fontitem & 0x00FF);

	cicocolour( standard_black, standard_white );

	/* Hex Value */
	if ( i > 0x000F )
		sprintf(buffer,  "%x",i);
	else	sprintf(buffer," %x",i);

	PixelFontSat(	wptr->x+(wptr->bfw*17),
			wptr->twy+(wptr->bfh*2),
			1,buffer);

	/* Character */
	PixelFontCat(	wptr->x+(wptr->bfw*11),
			wptr->twy+(wptr->bfh*2),
			1,i);

	/* Decimal Value */
	if ( i > 99 )
		sprintf(buffer,  "%u",i);
	else if ( i > 9 )
		sprintf(buffer, " %u",i);
	else	sprintf(buffer,"  %u",i);

	PixelFontSat(	wptr->x+(wptr->bfw*13),
			wptr->twy+(wptr->bfh*2),
			1,buffer);

	/* Character Width */
	if ((i=wptr->w_cell) > 9 )
		sprintf(buffer,  "%u",i);
	else 	sprintf(buffer, " %u",i);

	PixelFontSat(	wptr->x+(wptr->bfw*17),
			wptr->twy+(wptr->bfh*3),
			1,buffer);

	/* Character Height */
	if ((i=wptr->h_cell) > 9 )
		sprintf(buffer,  "%u",i);
	else 	sprintf(buffer, " %u",i);

	PixelFontSat(	wptr->x+(wptr->bfw*17),
			wptr->twy+(wptr->bfh*4)+1,
			1,buffer);

	for (	l=0; l < wptr->h; l++ )
		for (c=0; c < wptr->w; c++)
			font_pixel(wptr,c,l);

	if ( mode ) {
		show  (	wptr->twx, wptr->twy,
			wptr->tww+1, wptr->twh+1);
		}
	return;
}

private	void	font_page( struct font_context * wptr, int mode )
{
	int	r,c;
	if ( mode )
		hide();

	if ( paper_type ) {
		filzone (wptr->x+wptr->ezz,wptr->y,
			(wptr->w*8)+(wptr->bfw/2),(wptr->h*8)+(wptr->bfh/2),
			standard_backwash);
		cicocolour(standard_lomid,transparent);
		}
	else	{
		visual_frame   (wptr->x+wptr->ezz,wptr->y,
			(wptr->w*8)+3,(wptr->h*8)+2,
			_EDIT_FRAME );
		cicocolour(standard_himid,transparent);
		}

	for (	r=0; r < 8; r++ )
		for (	c=0; c < 8; c++ )
			PixelFontCat(	
				(wptr->x+wptr->ezz+(wptr->w*c))+2,
				(wptr->y+(wptr->h*r))+2,
				wptr->font,((r*8)+c)+wptr->page);

	cicocolour(standard_black,transparent);

	for (	r=0; r < 8; r++ )
		for (	c=0; c < 8; c++ )
			PixelFontCat(
				(wptr->x+wptr->ezz+(wptr->w*c)),
				(wptr->y+(wptr->h*r)),
				wptr->font,((r*8)+c)+wptr->page);

	if ( mode )
		show(wptr->x+wptr->ezz,wptr->y,(wptr->w*8)+(wptr->bfw/2),(wptr->h*8)+(wptr->bfh/2));
	return;
}

private	void	show_font_cursor( struct font_context * wptr )
{
	int	x;
	int	y;
	int	eight=8;
	if ((eight=8) > wptr->h )
		eight = wptr->h;
	x = wptr->x_cursor;
	filzone((wptr->x+(x*8)+1),
		(wptr->y-eight),7,7,standard_lolight);
	if ((eight=8) > wptr->w )
		eight = wptr->w;
	y = wptr->y_cursor;
	filzone((wptr->x-eight),
		(wptr->y+(y*8)+1),7,7,standard_lolight);
	return;
}

private	void	move_font_cursor( struct font_context * wptr, int newx, int newy )
{
	int	x;
	int	y;
	int	eight=8;
	if (( eight = 8) > wptr->h )
		eight = wptr->h;
	x = wptr->x_cursor;
	y = wptr->y_cursor;
	if ( x != newx ) {
		filzone((wptr->x+(x*8)+1),
			(wptr->y-eight),7,7,standard_backwash);
		filzone((wptr->x+(newx*8)+1),
			(wptr->y-eight),7,7,standard_lolight);
		}

	if ((eight=8) > wptr->w )
		eight = wptr->w;
	if ( y != newy ) {
		filzone((wptr->x-eight),
			(wptr->y+(y*8)+1),7,7,standard_backwash);
		filzone((wptr->x-eight),
			(wptr->y+(newy*8)+1),7,7,standard_lolight);
		}
	wptr->x_cursor = newx;
	wptr->y_cursor = newy;
	return;
}

private	int	get_font_height( struct font_context * wptr )
{
	int	i;
	struct window_control	Window;
	char	buffer[16];
	int	result=0;
	Window.x = wptr->x+(wptr->bfw*17)+wptr->ezz;
	Window.y = wptr->twy+(wptr->bfh*4)+1;
	Window.h = wptr->bfh;
	Window.w = (wptr->bfw*2);
	Window.payload = buffer;
	Window.size=2;
	Window.font = 1;
	sprintf(buffer,"%u",wptr->h);	
	if ( edit_text(0,0,&Window) != 27 ) {
		for (i=0; buffer[i] != 0; i++) {
			if ((buffer[i] >= '0') && ( buffer[i] <= '9'))
				result = ((result*10) + (buffer[i] -'0'));
			else	break;
			}
		}
	return( result );
}

private	int	get_cell_width( struct font_context * wptr )
{
	int	i;
	struct window_control	Window;
	char	buffer[16];
	int	result=0;
	Window.x = wptr->x+(wptr->bfw*17);
	Window.y = wptr->twy+(wptr->bfh*3);
	Window.h = wptr->bfh;
	Window.w = (wptr->bfw*2);
	Window.payload = buffer;
	Window.size=2;
	Window.font = 1;
	sprintf(buffer,"%u",wptr->w_cell);	
	if ( edit_text(0,0,&Window) != 27 ) {
		for (i=0; buffer[i] != 0; i++) {
			if ((buffer[i] >= '0') && ( buffer[i] <= '9'))
				result = ((result*10) + (buffer[i] -'0'));
			else	break;
			}
		}
	return( result );
}
private	int	get_font_width( struct font_context * wptr )
{
	int	i;
	struct window_control	Window;
	char	buffer[16];
	int	result=0;
	Window.x = wptr->x+(wptr->bfw*17)+wptr->ezz;
	Window.y = wptr->twy+(wptr->bfh*3);
	Window.h = wptr->bfh;
	Window.w = (wptr->bfw*2);
	Window.payload = buffer;
	Window.size=2;
	Window.font = 1;
	sprintf(buffer,"%u",wptr->w);	
	if ( edit_text(0,0,&Window) != 27 ) {
		for (i=0; buffer[i] != 0; i++) {
			if ((buffer[i] >= '0') && ( buffer[i] <= '9'))
				result = ((result*10) + (buffer[i] -'0'));
			else	break;
			}
		}
	return( result );
}

private	int	get_font_name( struct font_context * wptr )
{
	visual_edit ( 	(wptr->twx + (( wptr->tww - ((wptr->bfw*16)+2))/2)+1),
			wptr->y+(wptr->h*11)+3,
			(wptr->bfw*16),wptr->bfh,1,wptr->fontname,15);
	return(0);
}


private	char *	font_constructor( int newfw, int newfh, int * sizeptr )
{
	int	offset;
	int	i;
	char *	fbuffer=(char *) 0;
	int	filesize;
	int	headsize;
	int	cellbits;
	int	cellsize;

	if ( fontworkzone )
		fontworkzone = liberate( fontworkzone );

	headsize = 32+512;
	cellbits = (newfh*newfw);
	cellsize = (cellbits/8);
	if ((cellbits %8) != 0)
		cellsize++;
	cellsize += 8;
	filesize = ((cellsize*256)+headsize);
	if (!( fbuffer = allocate( filesize )))
		return((char *) 0);
	memset(fbuffer,0,filesize);
	for (i=0; i < 16; i++ )
		*(fbuffer+i) = 0x020;
	*(fbuffer+16) = (filesize & 0x00FF);
	*(fbuffer+17) = ((filesize >> 8) & 0x00FF);
	*(fbuffer+18) = (newfh & 0x00FF);
	*(fbuffer+19) = ((newfh >> 8) & 0x00FF);
	*(fbuffer+20) = (newfw & 0x00FF);
	*(fbuffer+21) = ((newfw >> 8) & 0x00FF);
	for (	offset=headsize, i=0; i < 256; i++, offset+=cellsize ) {
		*(fbuffer + 32 + (i*2) + 0 ) = (offset & 0x00FF);
		*(fbuffer + 32 + (i*2) + 1 ) = ((offset >> 8) & 0x00FF);
		*(fbuffer + offset + 0     ) = (newfh & 0x00FF);
		*(fbuffer + offset + 1     ) = ((newfh >> 8) & 0x00FF);
		*(fbuffer + offset + 2     ) = (newfw & 0x00FF);
		*(fbuffer + offset + 3     ) = ((newfw >> 8) & 0x00FF);
		}
	*sizeptr = filesize;
	return( fbuffer );

}

private	void	install_font( int fid, char * fbuffer, int filesize )
{
	int	i;
	establish_font( fid, fbuffer, filesize );
	if ((i = guifontsize(fid)) != 0) {
		Context.FontTable[fid].width =(i & 0x00FF);
		Context.FontTable[fid].height=((i >> 8) & 0x00FF);
		}
	return;
}

private	void	duplicate_font( int fid, char * fbuffer, int filesize )
{
	char * newbuffer;
	if (!( newbuffer = allocate( filesize )))
		return;
	else 	{
		memcpy( newbuffer, fbuffer, filesize );
		install_font( fid, newbuffer, filesize );
		return;
		}
}

private	int	new_font( int fid, int newfw, int newfh )
{
	int	i;
	int	filesize=0;
	char *	fbuffer=(char *) 0;

	if (!(fbuffer = font_constructor( newfw, newfh, &filesize ) ))
		return(0);
	else	{
		install_font( fid, fbuffer, filesize );
		return(filesize);
		}
}

private	int 	build_font(struct font_context * wptr )
{
	int	newfw;
	int	newfh;
	while ( visual_kbhit() ) visual_getch();

	if ((!(newfw = get_font_width(wptr)))
	||  (!(newfh = get_font_height(wptr))))
		return(0);
	else	return( new_font( wptr->font, newfw, newfh ) );
}

public 	int	font_window( struct font_context * wptr )
{
	char *	mptr;
	int	mlen;
	int	f;
	int	i;
	int	status=0;
	int	fg=standard_black;
	int	bg=standard_backwash;

	char 	buffer[16];

	if ( fontworkzone )
		fontworkzone = liberate( fontworkzone );

	if (!( f = wptr->font ))
		f = Context.Item.font;

	if ((!( f ))
	||  (!( wptr->w   = Context.FontTable[f].width  ))
	||  (!( wptr->h   = Context.FontTable[f].height ))
	||  (!( wptr->bfw = Context.FontTable[1].width  ))
	||  (!( wptr->bfh = Context.FontTable[1].height )))
		return(0);

	else if (!( wptr->fontname = alias_font( f ) ))
		return(0);

	/* Width and height of the editor frame and page frame */
	/* --------------------------------------------------- */
	wptr->ezw = (wptr->w*8); wptr->ezh = (wptr->h*8);

	if ( wptr->ezw > (wptr->bfw*20))
		wptr->ezz = (wptr->ezw+(wptr->bfw*2));
	else	wptr->ezz = (wptr->bfw*22);

	if ( wptr->ezz < (wptr->h*9))
		wptr->ezz = (wptr->h*9);

	/* If Base Font is Wider than the Edited Font */
	/* ------------------------------------------ */
	if ((wptr->tww = ((20*2) * wptr->bfw)) < (wptr->ezw*2))
		wptr->tww = (wptr->ezw*2);

	if ( wptr->tww < (wptr->h*19))
		wptr->tww = (wptr->h*19);

	/* Add in standard margin values */
	/* ----------------------------- */
	wptr->tww += (wptr->bfw*6);

	/* Calculate the total window height */
	wptr->twh = (wptr->ezh + (wptr->bfh*8) + (wptr->h*3));

	/* Calculate the position of the Window and Edit Zones */
	/* --------------------------------------------------- */
	wptr->twx = (Context.DeskTop.x+((Context.DeskTop.w - wptr->tww)/2));
	wptr->twy = (Context.DeskTop.y+((Context.DeskTop.h - wptr->twh)/2));

	wptr->x   = (wptr->twx+(wptr->bfw*2));
	wptr->y   = (wptr->twy+(wptr->bfh*6));

	wptr->font = f;
	wptr->margin = 0;

	hide();

	if (!(mptr = font_message(0)))
		mlen = 0;
	else	mlen = strlen(mptr);

	visual_window(	wptr->twx, wptr->twy, wptr->tww, wptr->twh,1,mptr, mlen,3 /* "Font Editor" */ );

	cicocolour( standard_black, transparent );

	PixelFontSat( 	wptr->x, wptr->twy+(wptr->bfh*2)  , 1, font_message(1) /* "Character" */);
	visual_frame(	wptr->x+(wptr->bfw*11)-1,
			wptr->twy+(wptr->bfh*2)-1,
			(wptr->bfw+2),
			(wptr->bfh+2), _EDIT_FRAME);

	visual_frame(	wptr->x+(wptr->bfw*13)-1,
			wptr->twy+(wptr->bfh*2)-1,
			((wptr->bfw*3)+2),
			(wptr->bfh+2), _EDIT_FRAME);

	visual_frame(	wptr->x+(wptr->bfw*17)-1,
			wptr->twy+(wptr->bfh*2)-1,
			((wptr->bfw*2)+2),
			(wptr->bfh+2), _EDIT_FRAME);

	PixelFontSat( wptr->x, wptr->twy+(wptr->bfh*3)+1, 1, font_message(2) /* "Width" */);
	visual_frame(	wptr->x+(wptr->bfw*17)-1,
			wptr->twy+(wptr->bfh*3),
			((wptr->bfw*2)+2),
			(wptr->bfh+2), _EDIT_FRAME);

	PixelFontSat( wptr->x, wptr->twy+(wptr->bfh*4)+2, 1, font_message(3) /* "Height" */);
	visual_frame(	wptr->x+(wptr->bfw*17)-1,
			wptr->twy+(wptr->bfh*4)+1,
			((wptr->bfw*2)+2),
			(wptr->bfh+2), _EDIT_FRAME);


	PixelFontSat( 	wptr->x+wptr->ezz, 
			wptr->twy+(wptr->bfh*2)  , 1, font_message(4) /* "Font" */);

	PixelFontSat( 	wptr->x+wptr->ezz, 
			wptr->twy+(wptr->bfh*3)+1, 1, font_message(2) /* "Width" */);
	visual_frame(	(wptr->x+(wptr->bfw*17)+wptr->ezz)-1,
			wptr->twy+(wptr->bfh*3)-1,
			((wptr->bfw*2)+2),
			(wptr->bfh+2), _EDIT_FRAME);

	/* Font Width */
	if ((i=wptr->w) > 9 )
		sprintf(buffer,  "%u",i);
	else 	sprintf(buffer, " %u",i);

	PixelFontSat(	wptr->x+(wptr->bfw*17)+wptr->ezz,
			wptr->twy+(wptr->bfh*3),
			1,buffer);

	/* Font Height */
	PixelFontSat( 	wptr->x+wptr->ezz, 
			wptr->twy+(wptr->bfh*4)+2, 1, font_message(3) /* "Height"*/);
	visual_frame(	(wptr->x+(wptr->bfw*17)+wptr->ezz)-1,
			wptr->twy+(wptr->bfh*4),
			((wptr->bfw*2)+2),
			(wptr->bfh+2), _EDIT_FRAME);

	if ((i=wptr->h) > 9 )
		sprintf(buffer,  "%u",i);
	else 	sprintf(buffer, " %u",i);

	PixelFontSat(	wptr->x+(wptr->bfw*17)+wptr->ezz,
			wptr->twy+(wptr->bfh*4)+1,
			1,buffer);


	draw_grid( wptr->x, wptr->y, wptr->w, wptr->h, 8, _EDIT_FRAME );

	show_font_cursor(wptr);

	font_page(wptr,0);

	visual_button( wptr->x             ,wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,"<",1,0);
	visual_button( wptr->x+(wptr->h* 2),wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,"+",1,0);
	visual_button( wptr->x+(wptr->h* 4),wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,"-",1,0);
	visual_button( wptr->x+(wptr->h* 6),wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,">",1,0);

	visual_button( wptr->x+wptr->ezz             ,wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,"<",1,0);
	visual_button( wptr->x+wptr->ezz+(wptr->h* 2),wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,"|",1,0);
	visual_button( wptr->x+wptr->ezz+(wptr->h* 4),wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,"=",1,0);
	visual_button( wptr->x+wptr->ezz+(wptr->h* 6),wptr->y+((wptr->h*8)+(wptr->h/2))+2,(wptr->h*2),(wptr->h*2),f,fg,bg,">",1,0);

	visual_frame( 	wptr->twx + (( wptr->tww - ((wptr->bfw*16)+2))/2),
			wptr->y+(wptr->h*11)+2,
			(wptr->bfw*16)+2,wptr->bfh+2,_EDIT_FRAME);
	visual_text ( 	(wptr->twx + (( wptr->tww - ((wptr->bfw*16)+2))/2)+1),
			wptr->y+(wptr->h*11)+3,
			(wptr->bfw*16),wptr->bfh,1,standard_black,standard_white,wptr->fontname,15,_A_LEFT);

	if (( fontworkzone = allocate( wptr->w * wptr->h )) != (char *) 0) {
		memset( fontworkzone,0,wptr->w * wptr->h );
		load_Character(wptr,Context.fontitem,0);
		font_data(wptr,1);
		status = 1;
		}
	else	status = 0;

	show  (	wptr->twx, wptr->twy,
		wptr->tww+1, wptr->twh+1);

	return(status);

}

public	void	refresh_FontContext()
{
	if ( Context.FontContext )
		(void) font_window( Context.FontContext );
	return;
}

public	int	is_FontEvent(struct font_context * wptr, int x,int y)
{
	int	t;
	int	b;
	int	oldcar=0;
	int	opcode;

	if (( x < wptr->twx ) 
	||  ( y < wptr->twy ) 
	||  ( x > (wptr->twx + wptr->tww))
	||  ( y > (wptr->twy + wptr->twh)))
		return(-1);
	

	/* Test for Inside Font Character Editor Zone */
	/* ------------------------------------------ */
	if (( x > wptr->x )
	&&  ( x < (wptr->x+(wptr->w*8)))) {

		if (( y > wptr->y )
		&&  ( y < (wptr->y+(wptr->h*8)))) {

			x -= wptr->x;	x /= 8;
			y -= wptr->y;	y /= 8;

			switch ( visual_event(1) ) {
				case	_MIMO_UP	:
				case	_MIMO_DOWN	:
				case	_MIMO_WHILE_DOWN:
					move_font_cursor(wptr,x,y);
					wptr->y_cursor = y;
					wptr->x_cursor = x;
					if ( visual_event(2) != _MIMO_LEFT )
						*(fontworkzone+(y*wptr->w)+x)=0;
					else	*(fontworkzone+(y*wptr->w)+x)=1;
					font_pixel(wptr,x,y);
				}
			return(256);
			}
		}


	/* Test for Function Button */
	/* ------------------------ */
	if (( x > wptr->x )
	&&  ( x < (wptr->x+(wptr->h*8)))
	&&  ( y > (wptr->y+(wptr->h*8)))
	&&  ( y < (wptr->y+(wptr->h*10)))) {
		x -= wptr->x;	x /= (wptr->h*2);
		switch ( visual_event(1) ) {
			case	_MIMO_UP	:
			switch ( x ) {
				case	0 : /* Button 1 */
					return( __FONT_PREV_CHAR );
				case	1 : /* Button 2 */
					return( __FONT_INS_LINE );
				case	2 : /* Button 3 */
					return( __FONT_DEL_LINE );
				case	3 : /* Button 4 */
					return( __FONT_NEXT_CHAR );
				}
			return(256);
			}
		}

	/* Inside Font Character Table Zone */
	/* -------------------------------- */
	if (( x > (wptr->x+wptr->ezz))
	&&  ( x < (wptr->x+(wptr->w*8)+wptr->ezz))) {

		/* Is it a character in the table */
		/* ------------------------------ */
		if (( y > wptr->y )
		&&  ( y < (wptr->y+(wptr->h*8)))) {

			x -= wptr->x;	y -= wptr->y;
			x -= wptr->ezz;
			x /= wptr->w; y/= wptr->h;

			switch ( visual_event(1) ) {
				case	_MIMO_UP	:
					save_Character(wptr,Context.fontitem);
					Context.fontitem = ((y*8)+x)+wptr->page;
					load_Character(wptr,Context.fontitem,0);
					font_data(wptr,1);
					break;
					}
			return(256);
			}
		}

	/* Test for Function Button */
	/* ------------------------ */
	if (( x > (wptr->x+wptr->ezz))
	&&  ( x < (wptr->x+(wptr->h*8)+wptr->ezz))
	&&  ( y > (wptr->y+((wptr->h*8)+(wptr->h/2))+2 ))
	&&  ( y < (wptr->y+(wptr->h*10)))) {

		x -= wptr->x;	y -= wptr->y;
		x -= wptr->ezz;	x /= (wptr->h*2);

		switch ( visual_event(1) ) {
			case	_MIMO_UP	:
			switch ( x ) {
				case	0 : /* Button 1 */
					return( __FONT_PREV_PAGE );
				case	1 : /* Button 2 */
					return( __FONT_CUT_CHAR );
				case	2 : /* Button 3 */
					return( __FONT_PASTE_CHAR );
				case	3 : /* Button 4 */
					return( __FONT_NEXT_PAGE );
				}
			}
		return(256);
		}

	/* Font Height / Width Box */
	/* ----------------------- */
	if (( x >= (wptr->x+(wptr->bfw*17)+wptr->ezz))
	&&  ( x <  (wptr->x+(wptr->bfw*19)+wptr->ezz))) {
		if (( y >= (wptr->twy+(wptr->bfh*4)+1))
		&&  ( y <  (wptr->twy+(wptr->bfh*5)+1)))
			return( __FONT_GET_HEIGHT );
		else if (( y >= (wptr->twy+(wptr->bfh*3)))
		     &&  ( y <  (wptr->twy+(wptr->bfh*4))))
			return( __FONT_GET_WIDTH  );
		}

	/* Font Height Box */
	/* --------------- */
	if (( x >= (wptr->x+(wptr->bfw*17)))
	&&  ( x <  (wptr->x+(wptr->bfw*19)))
	&&  ( y >= (wptr->twy+(wptr->bfh*3)))
	&&  ( y <  (wptr->twy+(wptr->bfh*4))))
			return( __FONT_CELL_WIDTH  );

	/* Font Name Box */
	/* ------------- */
	if (( x >= (wptr->twx + (( wptr->tww - ((wptr->bfw*16)+2))/2)+1) )
	&&  ( x <  ((wptr->twx + (( wptr->tww - ((wptr->bfw*16)+2))/2)+1)+(wptr->bfw*16)) )
	&&  ( y >= (wptr->y+(wptr->h*11)+3))
	&&  ( y <  (wptr->y+(wptr->h*11)+3+wptr->bfh)))
		return( __FONT_GET_NAME );
	else	return(-1);
}

public	void	select_font(int f)
{
	switch ( f ) {
		case	_TEXT_FONT1		:
			Context.Item.font = 1;
			return;;
		case	_TEXT_FONT2:
			Context.Item.font = 2;
			return;;
		case	_TEXT_FONT3:
			Context.Item.font = 3;
			return;;
		case	_TEXT_FONT4:
			Context.Item.font = 4;
			return;;
		case	_TEXT_FONT5:
			Context.Item.font = 5;
			return;;
		case	_TEXT_FONT6:
			Context.Item.font = 6;
			return;;
		case	_TEXT_FONT7:
			Context.Item.font = 7;
			return;;
		case	_TEXT_FONT8:
			Context.Item.font = 8;
			return;;
		case	_TEXT_FONT9:
			Context.Item.font = 9;
		default		:
			return;;
		}
}

private	void	insert_font_row( struct font_context * wptr )
{
	int	r;
	int	y;
	y = wptr->y_cursor;
	for ( r=(wptr->h-1); r > y; r-- )
		memcpy(	(fontworkzone + (r * wptr->w)),
			(fontworkzone + ((r-1) * wptr->w)),
			wptr->w);
	
	memset(	(fontworkzone + (y * wptr->w)),0,wptr->w);
	font_data(wptr,1);
	return;
}

private	void	delete_character( struct font_context * wptr )
{
	int	c;
	int	r;
	for ( r=0; r < wptr->h_cell; r++ ) {
		for (c=wptr->x_cursor; c < (wptr->w_cell-1); c++ )
			*(fontworkzone + (r * wptr->w) + c) = 
			*(fontworkzone + (r * wptr->w) + (c+1));
		*(fontworkzone + ((r-1) * wptr->w) + c) = 0;
		}
	font_data(wptr,1);
	return;
}

private	void	insert_character( struct font_context * wptr )
{
	int	c;
	int	r;
	for ( r=0; r < wptr->h_cell; r++ ) {
		for (	c=(wptr->w_cell-1);
			c > wptr->x_cursor;
			c-- )
			*(fontworkzone + (r * wptr->w) + c) = 
			*(fontworkzone + (r * wptr->w) + (c-1));
		*(fontworkzone + ((r-1) * wptr->w) + c) = 0;
		}
	font_data(wptr,1);
	return;
}


private	void	clear_to_end( struct font_context * wptr, int mode )
{
	int	offset;
	int	length;
	offset = ((wptr->y_cursor*wptr->w)+wptr->x_cursor);
	length = ((wptr->w*wptr->h) - offset);
	memset( (fontworkzone+offset),mode,length);
	font_data(wptr,1);
	return;
}


private	void	delete_font_row( struct font_context * wptr )
{
	int	r;
	int	y;
	y = wptr->y_cursor;
	for ( r=y; r < (wptr->h-1); r++ )
		memcpy(	(fontworkzone + (r * wptr->w)),
			(fontworkzone + ((r+1) * wptr->w)),
			wptr->w);
	
	memset(	(fontworkzone + ((wptr->h-1) * wptr->w)),0,wptr->w);
	font_data(wptr,1);
	return;
}

void	show_crosshair(struct font_context * wptr )
{
	xorzone((wptr->x+(wptr->x_cursor*8)),
		(wptr->y+(wptr->y_cursor*8)),
		9,1,0x0099);
	xorzone((wptr->x+(wptr->x_cursor*8)),
		(wptr->y+(wptr->y_cursor*8))+8,
		9,1,0x0099);
	xorzone((wptr->x+(wptr->x_cursor*8)),
		(wptr->y+(wptr->y_cursor*8)),
		1,9,0x0099);
	xorzone((wptr->x+(wptr->x_cursor*8))+8,
		(wptr->y+(wptr->y_cursor*8)),
		1,9,0x0099);
	return;
}

void	hide_crosshair(struct font_context * wptr )
{
	filzone((wptr->x+(wptr->x_cursor*8)),
		(wptr->y+(wptr->y_cursor*8)),
		9,1,standard_black);
	filzone((wptr->x+(wptr->x_cursor*8)),
		(wptr->y+(wptr->y_cursor*8))+8,
		9,1,standard_black);
	filzone((wptr->x+(wptr->x_cursor*8)),
		(wptr->y+(wptr->y_cursor*8)),
		1,9,standard_black);
	filzone((wptr->x+(wptr->x_cursor*8))+8,
		(wptr->y+(wptr->y_cursor*8)),
		1,9,standard_black);
	return;
}

struct standard_clipboard * drop_clipboard(struct standard_clipboard * cptr )
{
	if ( cptr->storage )
		cptr->storage = liberate( cptr->storage );
	cptr = liberate( cptr );
	return(0);	
}

void	cut_font(struct font_context * wptr )
{
	struct standard_clipboard * cptr;
	if ( wptr->clipboard )
		wptr->clipboard = drop_clipboard( wptr->clipboard );
	if (!( cptr = allocate( sizeof( struct standard_clipboard ) ) ))
		return;
	else if (!(cptr->storage = allocate(
		((cptr->width = wptr->w)*(cptr->height = wptr->h))
		))) {
		cptr = liberate( cptr );
		return;
		}
	else	{
		memcpy(cptr->storage,fontworkzone,(cptr->width*cptr->height));
		cptr->w_cell=wptr->w_cell;
		cptr->h_cell=wptr->h_cell;
		wptr->clipboard=cptr;
		return;
		}
}

void	paste_font(struct font_context * wptr )
{
	int	l,c;

	struct standard_clipboard * cptr;
	if (!(cptr = wptr->clipboard ))
		return;
	else if (!( cptr->storage ))
		return;
	for (	l=0; l < cptr->height; l++ ) {
		if ( l < wptr->h ) {
			for (	c=0; c < cptr->width; c++ ) {
				if ( c < wptr->w ) {
					*(fontworkzone+(l*wptr->w)+c)=
					*(cptr->storage+(l*cptr->width)+c);
					}
				else	break;
				}
			}
		else	break;
		}
	if ( cptr->w_cell < cptr->width )
		wptr->w_cell = cptr->w_cell;
	font_data(wptr,1);
	return;
}

public	void	font_import(int fid)
{
	char	*	bptr;
	struct	standard_image * iptr;
	int	mode;
	int	bg;
	int	c;
	int	vr;
	int	vc;
	int	r;
	int	fw=0;
	int	fh=0;
	int	v;
	int	rv;
	int	gv;
	int	bv;
	int	rp;
	int	gp;
	int	bp;
	int	rmax;
	int	cmax;
	int	ascii;
	int	ffs;
	char	s[2];
	int	pixelsize=get_pixel_size();
	int	colourmaped=get_pixel_format();
	struct 	font_context	FontEditor;
	struct 	font_context * wptr=&FontEditor;
	wptr->font = (fid+1);	
	wptr->margin = 0;
	if ( accept_imageload( &ThisFontName ) == 27 ) {
		return;
		}

	else if (!(iptr = local_image_loader(ThisFontName) )) {
		file_not_found( ThisFontName );
		return;
		}

	fw = (iptr->columns / 16);
	fh = (iptr->rows / 16);

	if ((mode = accept_font_import( &fw, &fh )) == 27) {
		local_drop_image( iptr );
		return;
		}
	else if (!(ffs = new_font(wptr->font, fw,fh ) )) {
		local_drop_image( iptr );
		return;
		}
	else 	{
		wptr->w = fw;
		wptr->h = fh;
		check_fontworkzone(wptr);
		}
	switch ( mode ) {
		case	26 :	/* assisted  */
		case	13 :	/* automatic */

			rmax = 16; 
			cmax = 16; 

			for (ascii=0,vr=0; vr < rmax; vr++ ) {

				for (vc=0; vc < cmax; vc++ ) {

					load_Character(wptr,ascii,0);

					for (r=0; r < wptr->h; r++ ) {
						if (!( bptr = connect_pixel_row( iptr->storage, (vr*wptr->h)+r ) ))
							break;		
						else if (!( r )) {
							if ( colourmaped )
								bg = *bptr;
							else	get_logical_pixel(bptr,&rv,&gv,&bv);
							}

						for (c=0; c < wptr->w; c++ ) {
							if (!( colourmaped )) {
								get_logical_pixel((bptr +  (((vc*wptr->w)+c) * pixelsize)) ,&rp,&gp,&bp);
								if ((rv != rp) || ( gv != gp ) || ( bv != bp ))	
									*(fontworkzone+(r*wptr->w)+c) = 1;
								else	*(fontworkzone+(r*wptr->w)+c) = 0;
								}
							else if (*(bptr + (vc*wptr->w)+c) != bg )
								*(fontworkzone+(r*wptr->w)+c) = 1;
							else	*(fontworkzone+(r*wptr->w)+c) = 0;
							}
						}
					save_Character(wptr,ascii);
					ascii++;
					}
				if ( ascii > 255 )
					break;
				}

			duplicate_font(wptr->font, alias_font( wptr->font ), ffs );
	
		case	27 :	/* abandoned */
			break;
		}

	local_drop_image( iptr );
	return;

}

public	void	font_export(int fid)
{
	struct	standard_image * iptr;
	int	c;
	int	r;
	int	fw=0;
	int	fh=0;
	int	fontid=fid;
	int	isbold=0;
	int	vpadd=0;
	int	hpadd=0;
	int	align=3;
	int	fg=16;
	int	bg=31;
	int	v;
	int	a;
	char	s[2];

	if ( accept_font_export( &ThisFontName, &fontid, &isbold, &vpadd, &hpadd, &align, &fg, &bg ) == 27 )
		return;
	else	fontid++;
	if (!( fw = guifontsize( fontid ))) {
		return;
		}
	else	{
		fh = (fw >> 8);
		fw &= 0x00FF;
		}
	if (!(iptr = local_allocate_image(((fw+vpadd)*16),((fh+hpadd)*16),Context.background,0) )) {
		return;
		}
	background_pixel_capture( iptr->storage );
	for ( r=0; r < 16; r++ ) {
		for ( c=0; c < 16; c++ ) {
			v = (r*16)+c;
			a = (align | ( isbold ? _A_BOLD : 0 ));
			if ( v < 32 )
				s[0] = 32;
			else if (( v >= 32 ) && ( v < 0x00B0))
				s[0] = v;
			else if ( v >= 0x00E0)
				s[0] = v;
			else	{
				s[0] = v;
				a = align;
				}
			s[1] = 0;
			visual_text((c * (fw + hpadd)), (r*(fh+vpadd)), (fw+hpadd),(fh+hpadd),fontid,fg,bg,s,1,a);
			}
		}
	cancel_pixel_capture( iptr->storage );
	image_save( ThisFontName, iptr, 0 );
	if ( iptr ) {
		iptr = local_drop_image( iptr ); 
		}
	return;
}

public	void	export_font(struct font_context * wptr )
{
	struct	standard_image * iptr;
	struct	standard_image * xptr;
	int	ascii=0;
	int	r;
	int	c;
	int	vr,vc;
	char *	bptr;
	char *	tempname;

	if (!( tempname = allocate_string( "export.bmp" ) ))
		return;

	SetPathSelection( system_imagepath );

	if ( accept_imagesave(
			&tempname, 
			&Context.imagepathitem,
			&Context.imageformat, 
			&Context.transparent ) == 27 ) {
		tempname = liberate( tempname );
		return;
		}
	else if (!( tempname = UsePathSelection( tempname, Context.imagepathitem ) ))
		return;

	else if (!(iptr = local_allocate_image((wptr->w*16),(wptr->h*16),Context.background,0) )) {
		tempname = liberate( tempname );
		return;
		}

	else	status_message(tempname,3);

	for (ascii=0,vr=0; vr < 16; vr++ ) {

		for (vc=0; vc < 16; vc++,ascii++ ) {

			load_Character(wptr,ascii,0);

			for (r=0; r < wptr->h; r++ ) {
				if (!( bptr = connect_pixel_row( iptr->storage, (vr*wptr->h)+r ) ))
					break;		
				for (c=0; c < wptr->w; c++ ) {
					if ( *(fontworkzone+(r*wptr->w)+c) == 1 )
						*(bptr + (vc*wptr->w)+c) = Context.foreground;
					else	*(bptr + (vc*wptr->w)+c) = Context.background;
					}
				}
			}
		}

	if ( edit_Image(tempname, &iptr ) != 27 ) 
		image_save( tempname, iptr,0 );

	if ( iptr )
		iptr = local_drop_image( iptr );
	load_Character(wptr,Context.fontitem,0);
	tempname = liberate( tempname );
	return;
}






/*
 *	N O T _ W H I T E _ L I N E 
 *	---------------------------
 *	Step over pixel rows to first row containing none background 
 *	colour pixels.
 *
 *	returns -1 when end of image is reached.
 *
 */

private	int	not_white_line( struct standard_image * iptr,int r, int bg )
{
	char	* bptr;
	int	c;
	for ( ; r < iptr->rows; r++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		for ( c=0; c < iptr->columns; c++ )
			if ( *(bptr +c) != bg )
				return( r );
		}
	return(-1);
}	 

/*
 *	N E X T _ W H I T E _ L I N E 
 *	-----------------------------
 *	Step over pixel rows to first row containing only background 
 *	colour pixels.
 *
 *	returns -1 when end of image is reached.
 *
 */
private	int	next_white_line( struct standard_image * iptr,int r, int bg )
{
	char	* bptr;
	int	c;
	for ( ; r < iptr->rows; r++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, r ) ))
			break;
		for ( c=0; c < iptr->columns; c++ )
			if ( *(bptr +c) != bg )
				break;
		if ( c < iptr->columns )
			continue;
		else	return(r);
		}
	return(-1);
}	 

/*
 *	C E L L _ S T A R T 
 *	-------------------
 *	Returns the column position of an non background pixel
 *	starting from the column position indicated and resting 
 *	between the indicated rows.
 *
 *	otherwise returns -1
 */

private	int cell_start(	
		struct standard_image * iptr, 
		int blackrow, int maxrow,
		int fromcol, int bg )
{
	char	* bptr;
	int	c;
	int	r;
	int	result;

	for (	r=blackrow,result=iptr->columns;
		r<maxrow;
		r++ ) {
		if (!( bptr = connect_pixel_row( iptr->storage, r )))
			break;
		for (c=fromcol; c < iptr->columns; c++ )
			if ( *(bptr + c) != bg )
				break;
		if ( c < result )
			result = c;
		}
	if ( result < iptr->columns )
		return( result );
	else	return( -1 );
}

/*
 *	C E L L _ C L O S E
 *	-------------------
 *	Returns the column position of a column slice containing
 *	only background pixels between the indicated rows.
 *
 *	otherwise returns -1
 */

private	int cell_close(	
		struct standard_image * iptr, 
		int blackrow, int maxrow,
		int fromcol, int bg )
{
	char	* bptr;
	int	c;
	int	r;
	int	result;

	for (	c=fromcol, result=iptr->columns;
		c < iptr->columns;
		c++ ) {
		for (	r=blackrow;
			r<maxrow;
			r++ ) {
			if (!( bptr = connect_pixel_row( iptr->storage, r )))
				break;
			else if ( *(bptr + c) != bg )
				break;
			}
		if ( r < maxrow )
			continue;
		else	return( c );
		}
	return( -1 );
}

private	void extract_character( 
		struct font_context * wptr,
		struct standard_image * iptr, 
		int blackcolumn, 
		int blackline, 
		int maxcol, int maxrow,
		int item, int bg )
{
	int	fr,fc;
	int	c;
	int	r;
	char *	bptr;
	int	i=item;

	for ( item=0; item < 256; item++ ) {

		if ( CharacterMap[item] != i )
			continue;	
	
		load_Character(wptr,item,0);
		memset(fontworkzone,0,(wptr->h*wptr->w));
		for (	fr=0,r=blackline; r < maxrow; r++,fr++ ) {
			if ( fr > wptr->h ) 
				break;
			else if (!( bptr = connect_pixel_row( iptr->storage, r) ))
				break;
			for (	fc=0,c=blackcolumn; c < maxcol; c++,fc++ ) {
				if ( fc > wptr->w ) 
					break;
				else if ( *(bptr+c) == bg )
					*(fontworkzone + (fr*wptr->w) + fc) = 0;
				else	*(fontworkzone + (fr*wptr->w) + fc) = 1;
				}
			}
		save_Character(wptr,item);
		}

	return;
}


private	void	scan_font_image( struct font_context * wptr, struct standard_image * iptr )
{
	int	blackline=0;
	int	whiteline=0;
	int	blackcolumn=0;
	int	whitecolumn=0;
	int	maxrow=0;
	int	maxcol=0;
	int	item='A';
	if ((blackline = not_white_line( iptr, 0, Context.background )) != -1) {
		do	{
			if ((whiteline = next_white_line(iptr,blackline,Context.background)) == -1)
				maxrow = (iptr->rows+1);
			else	maxrow = whiteline;
			if ((blackcolumn = cell_start( iptr, blackline, maxrow,whitecolumn,Context.background)) != -1) {
				do	{
					if ((whitecolumn = cell_close( iptr, blackline, maxrow,blackcolumn,Context.background)) == -1)
						maxcol = (iptr->columns+1);
					else	maxcol = whitecolumn;
					/* ------------------------------------------------- */
					/* Got One ( blackcolumn,blackline .. maxcol,maxrow) */
					/* ------------------------------------------------- */
					if ( blackcolumn == whitecolumn )
						continue;
					else	zoom_selection(blackcolumn,blackline,maxcol,maxrow,1);
					switch ((item = edit_Image("\0",&iptr))) {
						case	13	:
						case	27	:
							break;
						default		:
							extract_character( wptr, iptr, blackcolumn, blackline, maxcol, maxrow, item, Context.background );
						}
					zoom_selection(blackcolumn,blackline,maxcol,maxrow,0);
					if ( item == 27 ) break;
					}
				while ((whitecolumn != -1) && ((blackcolumn = cell_start(iptr,blackline,maxrow,whitecolumn,Context.background)) != -1));
				if ( item == 27 )
					break;
				else if ( item == '9' )
					break;
				else	whitecolumn = 0;
				}
			else	break;
			}
		while ((whiteline != -1) && ((blackline = not_white_line( iptr, whiteline,Context.background )) != -1));
		}
	return;
}

void	copy_font(struct font_context * wptr, char * fbuffer, int filesize, int nfw, int nfh )
{
	int	c;
	void *	vptr;
	char *	fptr;
	short *	sptr;
	int	i;
	int	x,y;
	int	offset;
	char *	travail;
	if ((!( wptr ))
	||  (!( vptr = fbuffer ))
	||  (!( filesize))
	||  (!( nfw ))
	||  (!( nfh )))
		return;
	else if (!( travail = allocate( (nfw * nfh) )))
		return;
	else	memset( travail, 0, (nfw*nfh));

	sptr =  (short *) vptr;

	for (	c=0; c < 256; c++ ) {
		load_Character( wptr, c, 0 ); /* into fontworkzone */
		offset = *(sptr +16 + (c & 0x00FF));
		fptr   = (char *) vptr;
		fptr  += offset;
		for (i=0; i < 8; i++ )
			*(fptr+i) = 0;
		*fptr 	  = nfh;
		*(fptr+2) = nfw;

		for (	y=0; y < wptr->h; y++ ) {
			if (y >= nfh)
				break;
			for (	x=0; x < wptr->w; x++ ) {
				if (x >= nfw)
					break;
				*(travail + (y*nfw)+x) = *(fontworkzone + (y*wptr->w)+x);
				}
			}
		save_FontCell( 	nfw, 	nfh,
				nfw,	nfh,
				0,
				travail, (fptr +8) );
		}
	travail = liberate( travail );
	return;
}

void	font_characteristics(struct font_context * wptr, int operation )
{
	int	nfw=0;
	int	nfh=0;
	int	filesize=0;
	char *	fbuffer=(char *) 0;

	if (!( wptr ))	return;

	nfw = wptr->w; nfh = wptr->h;

	switch ( operation ) {

		case	__FONT_CELL_WIDTH :
			while (1) {
				if (!(nfw = get_cell_width(wptr)))
					break;
				else if ( nfw <= wptr->w ) {
					wptr->w_cell = nfw;
					break;
					}
				}
			break;

		case	__FONT_GET_NAME  :
			if (!(get_font_name( wptr )))
				break;

		case	__FONT_GET_WIDTH :
			if (!(nfw = get_font_width(wptr)))
				break;

		case	__FONT_GET_HEIGHT :
			if (!(nfh = get_font_height(wptr)))
				break;
			else if (!( fbuffer = font_constructor(nfw,nfh, &filesize) ))
				break;

			/* The old font characters must be expanded and */
			/* compressed to the new structure		*/
			else	{
				copy_font(wptr, fbuffer, filesize, nfw, nfh );
				install_font(wptr->font,fbuffer,filesize);
				font_window(wptr);
				load_Character(wptr,Context.fontitem,0);
				font_data(wptr,1);
				}		
		}
	return;
}

void	import_font(struct font_context * wptr )
{
	struct	standard_image * iptr;
	int	ascii=0;
	int	r;
	int	c;
	int	vr,vc;
	int	rmax,cmax;
	int	mode=0;
	int	autofw;
	int	autofh;
	unsigned char *	bptr;

	char *	tempname;

	if (!( fontworkzone ))
		return;

	else if (!( tempname = allocate_string( "export.bmp" ) ))
		return;

	else if ( accept_imageload( &tempname ) == 27 ) {
		tempname = liberate( tempname );
		return;
		}

	else	status_message(tempname,3);

	if (!(iptr = local_image_loader(tempname) )) {
		tempname = liberate( tempname );
		return;
		}
	else if (!( bptr =connect_pixel_row( iptr->storage, 0 ) )) { 
		tempname = liberate( tempname );
		local_drop_image( iptr );
		return;
		}
	else	Context.background = *bptr;

	if ((mode = edit_Image(tempname, &iptr )) == 27 ) {
		tempname = liberate( tempname );
		local_drop_image( iptr );
		return;
		}

	autofw = (iptr->columns / 16);
	autofh = (iptr->rows / 16);

	if ((mode = accept_font_import( &autofw, &autofh )) == 27) {
		tempname = liberate( tempname );
		local_drop_image( iptr );
		return;
		}
	else if (!( new_font(wptr->font, (wptr->w=autofw),(wptr->h=autofh) ) )) {
		tempname = liberate( tempname );
		local_drop_image( iptr );
		return;
		}
	else 	check_fontworkzone(wptr);

	switch ( mode ) {

		case	26 : /* Assisted Font Import */
			scan_font_image( wptr, iptr );
			break;

		case	13 : /* Automatic Font Import */

			rmax = 16; 
			cmax = 16; 

			for (ascii=0,vr=0; vr < rmax; vr++ ) {

				for (vc=0; vc < cmax; vc++ ) {

					load_Character(wptr,ascii,0);

					for (r=0; r < wptr->h; r++ ) {
						if (!( bptr = connect_pixel_row( iptr->storage, (vr*wptr->h)+r ) ))
							break;		
						for (c=0; c < wptr->w; c++ ) {
							if (*(bptr + (vc*wptr->w)+c) != Context.background)
								*(fontworkzone+(r*wptr->w)+c) = 1;
							else	*(fontworkzone+(r*wptr->w)+c) = 0;
							}
						}
					save_Character(wptr,ascii);
					ascii++;
					}
				if ( ascii > 255 )
					break;
				}
			}

	local_drop_image( iptr );
	load_Character(wptr,Context.fontitem,0);
	tempname = liberate( tempname );
	return;
}

private	void	extract_font_character(
		void * tptr, int tw, int th,
		void * vptr, int vw, int vh, int c)
{
	int	tcw;
	int	tch;
	int	vcw;
	int	vch;
	int	mcw;
	int	mch;
	char *	fptr;
	short *	sptr;
	int	offset;
	sptr =  (short *) vptr;
	offset = *(sptr +16+ (c & 0x00FF));
	fptr   = (char *) vptr;
	fptr  += offset;
	vch = *fptr;
	vcw = *(fptr + 2);
	load_FmfCell( 	tw, th, vcw, vch, 0, fontworkzone, (fptr +8),0 );
	sptr =  (short *) tptr;
	offset = *(sptr +16+ (c & 0x00FF));
	fptr   = (char *) tptr;
	fptr  += offset;
	tch = *fptr;
	tcw = *(fptr + 2);
	save_FontCell( 	tw, th, tcw, tch, 0, fontworkzone, (fptr +8) );
	return;
}


private	void	font_extraction(struct font_context * wptr )
{
	int		sw;
	int		sh;
	int		tw;
	int		th;
	char	*	sptr;
	char	*	tptr;
	int	srcfont;
	int	tgtfont;
	int	group1=1;
	int	digits=0;
	int	group2=1;
	int	uppercase=0;
	int	group3=1;
	int	lowercase=0;
	int	group4=1;
	int	accents=0;
	int	group5=1;
	int	isprop=1;
	int	i;
	char *	fbuffer=(char*)0;
	int	filesize=0;
	if (!( wptr ))
		return;
	srcfont = wptr->font;
	srcfont--;
	if ( accept_extraction( 
		&srcfont, 
		&group1, &digits,
		&group2, &uppercase,
		&group3, &lowercase,
		&group4, &accents,
		&group5, &isprop ) == 27 ) 
		return;
	srcfont++;
	if ( srcfont == wptr->font )
		return;
	else if (!( sw = guifontsize(srcfont)))
		return;
	else if (!( sh = (sw >> 8)))
		return;
	else if (!( tw = guifontsize(wptr->font)))
		return;
	else if (!( th = (tw >> 8)))
		return;
	else if (!( sw = (sw & 0x00FF)))
		return;
	else if (!( tw = (tw & 0x00FF)))
		return;
	else if ( tw < sw )
		return;
	else if ( th < sh )
		return;
	else if (!( sptr = alias_font( srcfont ) ))
		return;
	else if (!( fbuffer = font_constructor(tw,th, &filesize) ))
		return;
	else	{
		if ( isprop ) {
			copy_font(wptr, fbuffer, filesize, tw, th );
			install_font(wptr->font,fbuffer,filesize);
			}
		if (!( tptr = alias_font( wptr->font ) ))
			return;
		if ( group1 ) {
			for (	i=0x0021; i <= 0x002F; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( digits ) {
			for (	i=0x0030; i <= 0x0039; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( group2 ) {
			for (	i=0x003A; i <= 0x0040; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( uppercase ) {
			for (	i=0x0041; i <= 0x005A; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( group3 ) {
			for (	i=0x005B; i <= 0x0060; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( lowercase ) {
			for (	i=0x0061; i <= 0x007F; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( group4 ) {
			for (	i=0x007B; i <= 0x007F; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( accents ) {
			for (	i=0x0080; i <= 0x009A; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( group5 ) {
			for (	i=0x009B; i <= 0x009F; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( accents ) {
			for (	i=0x00A0; i <= 0x00AF; i++ )
				extract_font_character(tptr,tw,th,sptr,sw,sh,i);
			}
		if ( isprop )
			calculate_proportions( wptr );
		font_window( wptr );
		}
	return;
}

public	int	edit_Font(struct font_context * fptr )
{
	int	x,y;
	int	event;

	add_font_editor_menu();
	use_font_tools();
	Context.FontContext = fptr;
	draw_console();

	while (1) {

		do	{
			show_crosshair(fptr);
			event = visual_getch();
			hide_crosshair(fptr);
			}
		while (( event == 256)
		&&     ((event = handle_event()) == 256));

		switch (event) {
			case	13	:
				save_Character(fptr,Context.fontitem);
			case	_LEAVE_SING	:
			case	27	:
				break;
						
			case	__FONT_NEXT_CHAR	:
				save_Character(fptr,Context.fontitem);
				Context.fontitem++;
				Context.fontitem &= 0x00FF;
				load_Character(fptr,Context.fontitem,0);
				font_data( fptr,1 );
				continue;

			case	__FONT_PREV_CHAR	:
				save_Character(fptr,Context.fontitem);
				Context.fontitem--;
				Context.fontitem &= 0x00FF;
				load_Character(fptr,Context.fontitem,0);
				font_data( fptr,1 );
				continue;

			case	CTRL_H	:
				if (!(x = (fptr->x_cursor)))
					x = fptr->w;
				x--;
				y = (fptr->y_cursor );
				move_font_cursor(fptr,x,y);
				continue;

			case	CTRL_F	:
				if ((x = ((fptr->x_cursor)+1)) >= fptr->w)
					x=0;
				y = (fptr->y_cursor );
				move_font_cursor(fptr,x,y);
				continue;
			case	CTRL_K	:
				if (!(y = (fptr->y_cursor)))
					y = fptr->h;
				y--;
				x = (fptr->x_cursor);
				move_font_cursor(fptr,x,y);
				continue;
			case	CTRL_E	:
				if ((y = ((fptr->y_cursor)+1)) >= fptr->h)
					y=0;
				x = (fptr->x_cursor);
				move_font_cursor(fptr,x,y);
				continue;

			case	' '			:
				if (!(  *(fontworkzone+(fptr->y_cursor*fptr->w)+fptr->x_cursor) ))
					*(fontworkzone+(fptr->y_cursor*fptr->w)+fptr->x_cursor) = 1;
				else	*(fontworkzone+(fptr->y_cursor*fptr->w)+fptr->x_cursor) = 0;
				font_pixel(fptr,fptr->x_cursor,fptr->y_cursor);
				continue;

			case	__FONT_INS_LINE		:
				insert_font_row(fptr);
				continue;

			case	__FONT_DEL_LINE		:
				delete_font_row(fptr);
				continue;

			case	__FONT_DEL_CHAR		:
				delete_character(fptr);
				continue;

			case	__FONT_INS_CHAR		:
				insert_character(fptr);
				continue;

			case	__FONT_WIPE_END	:
				clear_to_end(fptr,1);
				continue;
			case	__FONT_CLEAR_END	:
				clear_to_end(fptr,0);
				continue;

			case	__FONT_PREV_PAGE	:
				fptr->page -= 32;
				if ( fptr->page < 32 )
					fptr->page= (256-32);
				font_page(fptr,1);
				continue;

			case	__FONT_NEXT_PAGE	:
				fptr->page += 32;
				if (( fptr->page + 64 ) > 256)
					fptr->page = 32;
				font_page(fptr,1);
				continue;


			case	__FONT_PASTE_CHAR		:
				paste_font(fptr);
				continue;

			case	__FONT_FIX_CHAR		:
				save_Character(fptr,Context.fontitem);
				calculate_proportions(fptr);
				load_Character(fptr,Context.fontitem,0);
				font_data(fptr,1);
				continue;

			case	__FONT_CUT_CHAR		:
				cut_font(fptr);
				continue;

			case	__FONT_INVERT		:
				invert_Character(fptr);
				font_data(fptr,1);
				continue;

			case	__FONT_PAPER_TYPE	:
				if ( paper_type )
					paper_type = 0;
				else	paper_type = 1;
				font_page(fptr,1);
				continue;
		
			case	_EDIT_FONT	:
				continue;

			case	_EXEC_PROG	:
			case	_VIEW_TEXT	:
			case	_VIEW_IMAGE	:
			case	_EDIT_GRAPH	:
			case	_EDIT_TEXT 	:
			case	_EDIT_IMAGE	:
			case	_EDIT_TREEVIEW	:
#ifdef	ABAL32A
			case	_EDIT_STYLE	:
			case	_EDIT_DEPEND	:
#endif
			case	_EDIT_FORM	:
				save_Character(fptr,Context.fontitem);
				break;

			case	__FONT_EXTRACT	:
				save_Character(fptr,Context.fontitem);
				font_extraction(fptr);
				load_Character(fptr,Context.fontitem,0);
				refresh_FontContext();
				continue;

			case	_FILE_NEW	:
				if ( fptr->font > 1 ) {
					if (!(build_font(fptr)))
						continue;
					else if (!( font_window( fptr ) ))
						break;
					else	{
						load_Character(fptr,Context.fontitem,0);
						continue;
						}
					}
				else	continue;

			case	_FILE_LOAD	:
				if (( fptr->font > 0 )
				&&  ( font_name[fptr->font] != (char *)0)) {
					font_load(fptr->font,font_name[fptr->font],1);
					if (!( font_window( fptr ) ))
						break;
					else	{
						load_Character(fptr,Context.fontitem,0);
						continue;
						}
					}
				continue;
			case	_FILE_PRODUCE	:
				export_font( fptr );
				refresh_FontContext();
				continue;
			case	_FILE_COMPARE	:
				compare_Files((char *) 0, (char *) 0);
				refresh_FontContext();
				continue;

			case	_FILE_IMPORT	:
				import_font( fptr );
				refresh_FontContext();
				continue;

			case	_FILE_QSAVE 	:
			case	_FILE_SAVE 	:
				save_Character(fptr,Context.fontitem);
				if ( font_name[fptr->font] != (char *)0) {
					font_save(fptr->font,font_name[fptr->font],event);
					if (!( font_window( fptr ) ))
						break;
					load_Character(fptr,Context.fontitem,0);

					}
				continue;

			case	__FONT_SEMI_GRAPH	:
				generate_semi_graphics( fptr );
				refresh_FontContext();
				continue;


			case	__FONT_GET_NAME		:
			case	__FONT_GET_WIDTH	:
			case	__FONT_GET_HEIGHT	:
			case	__FONT_CELL_WIDTH 	:
				font_characteristics(fptr,event);
				continue;

			default				:
				continue;

			}
		break;
		}
	if ( fptr->clipboard )
		drop_clipboard(fptr->clipboard);
	Context.FontContext = (struct font_context *) 0;
	drop_tool_manager();
	drop_font_editor_menu();
	return(event);
}




int	font_edit(int fid)
{
	struct 	font_context	FontEditor;

	FontEditor.x_cursor = FontEditor.y_cursor = 0;	/* line / column position */
	FontEditor.clipboard=(struct standard_clipboard *) 0;
	FontEditor.operation=0;
	FontEditor.page = 32;
	FontEditor.font = fid;
	if (!( font_window( &FontEditor )))
		return(0);
	else	return( edit_Font( &FontEditor ) );
}

#ifdef PROLOGUE
/* #include "sgigo.c" */
#endif


#include "stdfmf.h"
#include "fontfunc.c"


