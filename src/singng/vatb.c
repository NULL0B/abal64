#ifndef	_vatb_c
#define	_vatb_c

/*			-------------------------------------				*/
/*			V I S U A L    A T B    M A N A G E R				*/
/*			-------------------------------------				*/
/*											*/
/*	The visual atribut manager watchs the CO flow from EXA print output		*/
/*	to detect special atributs introduced for the simplification of use		*/
/*	of the visual library functions in print and ask expressions			*/
/*											*/
/*											*/

#define	_REDIRECTED_CICO

#include "zalloc.h"
#include "valign.h"

#define	VISUAL_ATRIBUTS		 52
#define	VISUAL_ATRIBUT_BUFFER	512

struct	visual_escape_control {
	int	filter;

	int	state;
	int	param;
	int	length;

	int	atribut;
	int	buflen;

	int	atcol;
	int	atlin;

	int	zone;
	int	align;
	int	font;
	int	fg;
	int	bg;

	int	lmi;
	int	tmi;
	int	gfh;
	int	gfw;
	
	int	vpw;
	int	vph;

	char	buffer[VISUAL_ATRIBUT_BUFFER+1];

	int	escapeGsize; /* FCH Séquence EscG */
	int	escapeGcpt;  /* FCH Séquence EscG */

	} VisEsc = {
		0,
		0,0,0,  
		0,0, 
		0,0,
		0,0,0, 
		16,0,
		0,0,
		0,0,
		0,0
		};

int vga_approximation(int  r, int  g, int  b );

private	void	reset_visual_atribut();
private	void	reset_atribut_control();

#ifdef	_REDIRECTED_CICO
private	void	esc_f(int l, int c);
#else
private	void	esc_f(int l, int c) { return; }
#endif



#include "vstylist.c"	/* included here to be able to see the above collection zone */

/*	------------------------------------------------------------	*/
/*	d e f i n e _ v i s u a l _ a t r i b u t ( buffer, length )	*/
/*	------------------------------------------------------------	*/
/*									*/
/*	this function allows the definition of individual visual atbs	*/
/*	and will specify the behaviour required in terms of framing	*/
/*	fonting, colour, alignment and bold/shadow/underline etc	*/
/*									*/
/*	------------------------------------------------------------	*/
/*									*/
/*	The data buffer comprises the following fields , in order :	*/
/*									*/
/*	a	atribut id 	: lower case alpha character a .. z 	*/
/*									*/
/*	Z	zone type	: upper case hex digit 0 .. F		*/
/*				  representing the 16 zone types   	*/
/*									*/
/*				  0 : block (inhibited : plain text )	*/
/*				  1 : inset				*/
/*				  2 : outset				*/
/*				  3 : ridge				*/
/*				  4 : groove				*/
/*				  5 : editbox				*/
/*				  6 : pushbutton			*/
/*				  7 : pushedbutton			*/
/*				  8 : checkbox				*/
/*				  9 : checkedbox			*/
/*				  10: radiobutton			*/
/*				  11: radioedbutton			*/
/*				  12: off switch			*/
/*				  13 :on  switch			*/
/*									*/
/*	F	font number	: decimal digit between 1 and 9 	*/
/*				  representing the 9 text fonts		*/
/*									*/
/*	T	text colour	: upper case zex digit 0 ... Z		*/
/*				  representing the 16 paint colours	*/
/*									*/
/*	W	wash colour	: upper case zex digit 0 ... Z		*/
/*				  representing the 16 paint colours	*/
/*									*/
/*	A	alignment  	: L=left, R=right, C=center, J=justify	*/
/*									*/
/*	X	text atributs	: B=bold,S=shadow,U=underline		*/
/*									*/
/*	Example :							*/
/*									*/
/*		nZFTWAX							*/
/*		b0240LBUS						*/
/*									*/
/*			atribut 'b'					*/
/*			zone 0 (none or plain text)			*/
/*			font number 2 (proportional)			*/
/*			left aligned					*/
/*			bold underlined shadowed			*/
/*			characters blue on black/transparent		*/
/*									*/
/*	------------------------------------------------------------	*/


private	int	VisualAtribut[5][VISUAL_ATRIBUTS] = {

	/* --------------------------------- */
	/* zone	: font : text : wash : align */
	/* --------------------------------- */
/* a */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* b */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* c */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* d */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* e */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* f */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* g */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* h */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* i */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* j */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* k */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* l */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* m */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* n */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* o */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* p */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* q */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* r */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* s */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* t */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* u */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* v */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* w */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* x */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* y */	  0x0000,0x0000,0x0000,0x0000,0x0000 ,
/* z */	  0x0000,0x0000,0x0000,0x0000,0x0000
	};

private	EXAWORD	define_visual_atribut( BPTR buffer, WORD buflen )
{
	int	a=0;
	int	z=0;
	int	f=0;
	int	t=0;
	int	w=0;
	int	x=0;
	int	i=1;
	while ( *(buffer+i) == ' ' )
		i++;
	
	if (( *(buffer+i) == '{' ) ||  ( *(buffer+i) == '(' ))
		return( parse_visual_style( buffer, buflen ) );

	/* Validate atribut identifier */
	/* --------------------------- */
	if ((a = *(buffer++)) < 'a' ) {
		if ( a < 'A' )
			return(102); 
		else if ( a > 'Z' ) 
			return(103);
		else	{
			a -= 'A';
			a += 26;
			}
		}
	else if ( a > 'z' ) 
		return(103);
	else	a -= 'a';

	/* Zone type */
	/* --------- */
	if (( *buffer >= '0' ) && ( *buffer <= '9'))
		z = (*(buffer++) - '0');
	else if (( *buffer >= 'A' ) && ( *buffer <= 'F'))
		z = ((*(buffer++) - 'A')+10);
	else if (( *buffer >= 'a' ) && ( *buffer <= 'f'))
		z = ((*(buffer++) - 'a')+10);

	/* Font number */
	/* ----------- */
	if (( *buffer >= '0' ) && ( *buffer <= '9'))
		f = (*(buffer++) - '0');
	else	return(30);

	/* Text Colour */
	/* ----------- */
	if (( *buffer >= '0' ) && ( *buffer <= '9'))
		t = (*(buffer++) - '0');
	else if (( *buffer >= 'A' ) && ( *buffer <= 'Z'))
		t = ((*(buffer++) - 'A')+10);
	else if (( *buffer >= 'a' ) && ( *buffer <= 'z'))
		t = ((*(buffer++) - 'a')+10);
	else	return(30);

	/* Wash Colour */
	/* ----------- */
	if (( *buffer >= '0' ) && ( *buffer <= '9'))
		w = (*(buffer++) - '0');
	else if (( *buffer >= 'A' ) && ( *buffer <= 'Z'))
		w = ((*(buffer++) - 'A')+10);
	else if (( *buffer >= 'a' ) && ( *buffer <= 'z'))
		w = ((*(buffer++) - 'a')+10);
	else	return(30);

	/* Alignment and text atributs */
	/* --------------------------- */
	if (( *buffer == 'L' ) ||  ( *buffer == 'l' )) {
		buffer++; x = _A_LEFT;
		}

	else if (( *buffer == 'R' ) ||  ( *buffer == 'r' )) {
		buffer++; x = _A_RIGHT;
		}

	else if (( *buffer == 'C' ) ||  ( *buffer == 'c' )) {
		buffer++; x = _A_CENTER;
		}

	else if (( *buffer == 'J' ) ||  ( *buffer == 'j' )) {
		buffer++; x = _A_JUSTIFY;
		}
	else	return(30);

	if (( *buffer == 'B' ) ||  ( *buffer == 'b' )) {
		buffer++; x |= _A_BOLD;
		}

	if (( *buffer == 'U' ) ||  ( *buffer == 'u' )) {
		buffer++; x |= _A_LINE;
		}

	if (( *buffer == 'S' ) ||  ( *buffer == 's' )) {
		buffer++; x |= _A_SHADOW;
		}

	/* save value to the matrix */
	/* ------------------------ */
	VisualAtribut[0][a] = z;	VisualAtribut[1][a] = f;
	VisualAtribut[2][a] = t;	VisualAtribut[3][a] = w;
	VisualAtribut[4][a] = x;
#ifdef	_DEBUG_VATB
	printf("defining visual atribut(a=%u : z=%u, f=%u, t=%u, w=%u, x=%x)\r\n",
		a,
		VisualAtribut[0][a],VisualAtribut[1][a],
		VisualAtribut[2][a],VisualAtribut[3][a],
		VisualAtribut[4][a] );
#endif
	return(0);

}

private	void	reset_atribut_control()
{
	VisEsc.atcol	= VisEsc.atlin	=
	VisEsc.buflen	= VisEsc.atribut= 0;
	return;
}

private	void	reset_visual_atribut()
{
	int	gfw=10;
	int	gfh=24;
	int	lmi=0;
	int	tmi=0;

	if ( VisEsc.buflen ) {

		/* collect the viewport offset information */
		/* --------------------------------------- */
		lmi = VisEsc.lmi = x_event( 203); 
		tmi = VisEsc.tmi = x_event( 200);
		gfh = VisEsc.gfh = x_event( 204); 
		gfw = VisEsc.gfw = x_event( 205);
		VisEsc.vph = x_event( 208);
		VisEsc.vpw = x_event( 209);

		/* terminate the string */
		/* -------------------- */
		VisEsc.buffer[VisEsc.buflen] = 0;
	
		/* Collect the cursor position if this has not been received */
		/* --------------------------------------------------------- */
		if (!( VisEsc.atcol )) VisEsc.atcol = x_col(1);
		if (!( VisEsc.atlin )) VisEsc.atlin = x_lin(1);

		/* Display the zone frame type */
		/* --------------------------- */
		VisEsc.atribut = 0;

		/* Attempt to apply style */
		/* ---------------------- */
		if (!( reset_visual_style() )) {

		switch ( VisEsc.zone ) {
			case	0 :
				if ( VisEsc.font != 0) {

#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualText(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
							lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)*gfh),
						   	(VisEsc.buflen*gfw)  , gfh, 
							VisEsc.font, VisEsc.fg,VisEsc.bg,
							0x0022,VisEsc.buffer,0x0022,
							VisEsc.buflen,VisEsc.align );
						}
#endif	
					VisualText(
							lmi+((VisEsc.atcol-1)*gfw) , 
							tmi+((VisEsc.atlin-1)*gfh),
							(VisEsc.buflen*gfw)  , gfh, 
							VisEsc.font, VisEsc.fg,VisEsc.bg,
							VisEsc.buffer,VisEsc.buflen,VisEsc.align );
					}
				break;

			case	1 : 
			case	2 :
			case	3 :
			case	4 :
				/* standard relief frames */
				/* ---------------------- */
#ifdef	_VISUAL_ECHO
				if ( VisualEcho & 1 ) {
					printf("VisualZone(%u,%u,%u,%u, %u )\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.zone);
					}
#endif	
				VisualFrame(lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   (VisEsc.buflen*gfw)  , gfh, VisEsc.zone );
				
				if ( VisEsc.font ) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualText(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw)+2 , (tmi+((VisEsc.atlin-1)* gfh)+4),
						   (VisEsc.buflen*gfw)-6  , (gfh-8), 
							1, VisEsc.fg,VisEsc.bg,
							0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,VisEsc.align );
						}
#endif	
					VisualText(
						lmi+((VisEsc.atcol-1)*gfw)+2 , (tmi+((VisEsc.atlin-1)* gfh)+4),
						   (VisEsc.buflen*gfw)-6  , (gfh-8), 
							VisEsc.font, VisEsc.fg,VisEsc.bg,
							VisEsc.buffer,VisEsc.buflen,VisEsc.align );
					}
				break;

			case	5 : 

				if ( VisEsc.align & _A_SHADOW ) {

#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualFill(%u,%u,%u,%u, %u,%u)\r\n",
							lmi+((VisEsc.atcol-1)*gfw)+4 , 
							(tmi+((VisEsc.atlin-1)* gfh)+3)+4,
							(VisEsc.buflen*gfw)  , (gfh-6), 0x0012, 12);
						}
#endif	
					visual_filzone(
						lmi+((VisEsc.atcol-1)*gfw) , 
						(tmi+((VisEsc.atlin-1)* gfh)+3),
						(VisEsc.buflen*gfw)  , (gfh-6),  0x0012, 12);

					}
				
#ifdef	_VISUAL_ECHO
				if ( VisualEcho & 1 ) {
					printf("VisualZone(%u,%u,%u,%u, %u )\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , 
						(tmi+((VisEsc.atlin-1)* gfh)+3),
						(VisEsc.buflen*gfw)  , (gfh-6), VisEsc.zone );
					}
#endif	
				VisualFrame(
					lmi+((VisEsc.atcol-1)*gfw) , 
					(tmi+((VisEsc.atlin-1)* gfh)+3),
					(VisEsc.buflen*gfw)  , (gfh-6), VisEsc.zone );
				
				if (!( VisEsc.font ))
					break;

#ifdef	_VISUAL_ECHO
				if ( VisualEcho & 1 ) {
					printf("VisualText(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
					lmi+((VisEsc.atcol-1)*gfw) , (tmi+((VisEsc.atlin-1)* gfh)+4),
					   (VisEsc.buflen*gfw)  , (gfh-8), 
						1, VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,(VisEsc.align & ~_A_SHADOW) );
					}
#endif	
				VisualText(
					lmi+((VisEsc.atcol-1)*gfw)+1 , (tmi+((VisEsc.atlin-1)* gfh)+4),
					   (VisEsc.buflen*gfw)-2  , (gfh-8), 
						1, VisEsc.fg,VisEsc.bg,
						VisEsc.buffer,VisEsc.buflen,(VisEsc.align&~_A_SHADOW));

				break;

			case	6 :	/* button */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualButton(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,((VisEsc.align & 0x0F00)));
						}
#endif	
					VisualButton(
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen,((VisEsc.align & 0x0F00)));
					}				
				break;

			case	7 :	/* pressed button */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualButton(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,((VisEsc.align & 0x0F00)| 4));
						}
#endif	
					VisualButton(	lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen,(VisEsc.align & 0x0F00)|4);
					}				
				break;


			case	8 :	/* check */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualCheck(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,((VisEsc.align & 0x0F00)));
						}
#endif	
					VisualCheck(	lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen, 0);
					}				
				break;

			case	9 :	/* checked */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualCheck(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,((VisEsc.align & 0x0F00)| 1));
						}
#endif	
					VisualCheck(	lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen, 1);
				
					}
				break;

			case	10:	/* radio */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualRadio(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u,%u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,1,0);
						}
#endif	
					VisualRadio(	lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen,1,0);
					}				
				break;

			case	11:	/* radioed */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualRadio(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u,%u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,1,1);
						}
#endif	
					}
					VisualRadio(	lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen,1, 1);
				
			case	12:	/* switch */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualSwitch(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,0);
						}
#endif	
					VisualSwitch(	lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen,0);
				
					}
				break;

			case	13:	/* switched */

				if ( VisEsc.font != 0) {
#ifdef	_VISUAL_ECHO
					if ( VisualEcho & 1 ) {
						printf("VisualSwitch(%u,%u,%u,%u, %u, %u,%u, %c%s%c,%u, %u)\r\n",
						lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,
						0x0022,VisEsc.buffer,0x0022,VisEsc.buflen,1);
						}
#endif	
					VisualSwitch(	lmi+((VisEsc.atcol-1)*gfw) , tmi+((VisEsc.atlin-1)* gfh),
					   	(VisEsc.buflen*gfw)  , gfh, 
						VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.buffer,VisEsc.buflen,1);
				
					}
				break;


			}
			}

		/* step text cursor over the captured buffer length */
		/* ------------------------------------------------ */
		esc_f((VisEsc.atcol+VisEsc.buflen+0x001F),(VisEsc.atlin+0x001F));
		}

	reset_atribut_control();
	return;
}

private	void	use_visual_atribut(int c)
{
	c &= 0x00FF;
	if ( VisEsc.atribut != 0 )
		reset_visual_atribut();

	if ( c < 'a' ) {
		if ( c < 'A' )
			return;
		else if ( c > 'Z' )
			return;
		else	{
			c -= 'A';
			c += 26;
			}
		}
	else if ( c == 'z' ) {
		VisEsc.filter = 1;
		return;
		}
	else	c -= 'a';
	VisEsc.filter = 0;
	VisEsc.atribut=c;
	if (!( VisEsc.zone = use_visual_style( c ) )) {
		VisEsc.zone = VisualAtribut[0][c]; VisEsc.font = VisualAtribut[1][c];
		VisEsc.fg   = VisualAtribut[2][c]; VisEsc.bg   = VisualAtribut[3][c];
		VisEsc.align= VisualAtribut[4][c]; 
#ifdef	_DEBUG_VATB
		if ( c != 0 ) {
			printf("visual atribut(a=%u : z=%u, f=%u, t=%u, w=%u, x=%x)\r\n",
				VisEsc.atribut,VisEsc.zone,VisEsc.font,VisEsc.fg,VisEsc.bg,VisEsc.align);
			}
#endif
		}
	return;
}

/*	----------------------------------------------		*/
/*	VV _ PUTCH ( c )					*/
/*	----------------
/*	this catchs the visual co for visual formating 		*/
/*	----------------------------------------------		*/
private	void	vv_putch(int c)
{
	/* check for /visual/null (sic!) */
	/* ----------------------------- */
	if ((!( VisEsc.zone )) &&  (!( VisEsc.font ))) 
		return;

	if ((( c & 0x00FF) >= ' '  ) 
	&&  ( VisEsc.buflen < 511 )) 
		VisEsc.buffer[VisEsc.buflen++] = (c & 0x0FF);
	return;
}


#ifdef	_REDIRECTED_CICO

#define	vx_putch( c ) if ( VisEsc.atribut != 0 ) vv_putch(c); else x_putch(c)


private	void	esc_f(int l, int c)
{
	VisEsc.state = 0;
	if (!( VisEsc.atribut )) {
		x_putch(27); x_putch('f');
		x_putch(l);  x_putch(c);
		}
	else	{
		VisEsc.atcol = (c-0x001F);
		VisEsc.atlin = (l-0x001F);
		}
	return;
}

private	void	esc_Z(int l, int c)
{
	VisEsc.state = 0;
	if (!( VisEsc.atribut )) {
		x_putch(27); x_putch('Z');
		x_putch(l);  x_putch(c);
		}
	return;
}

private	void	esc_s(int v)
{
	VisEsc.state = 0;
	if (!( VisEsc.atribut )) {
		x_putch(27); x_putch('s'); x_putch(v);
		}
	return;
}

private	void	esc_r(int v)
{
	VisEsc.state = 0;
	if (!( VisEsc.atribut )) {
		x_putch(27); x_putch('r'); x_putch(v);
		}
	return;
}

private	void	esc_n(int v)
{
	VisEsc.state = 0;
	if (!( VisEsc.atribut )) {
		x_putch(27); x_putch('n'); x_putch(v);
		}
	return;
}

private	void	esc_q(int v)
{
	VisEsc.state = 0;
	if (!( VisEsc.atribut )) {
		x_putch(27); x_putch('q'); x_putch(v);
		}
	return;
}

private	void	x_pos(int c, int l )
{
	x_putch(27); x_putch('f'); x_putch( c+ 0x001F); x_putch( l + 0x001F);
	return;
}

private	void	x_paint(int f, int b)
{
	esc_s(( b > 10 ? ((b-10) + 'A') : (b+'0') ));
	esc_r(( f > 10 ? ((f-10) + 'A') : (f+'0') ));
	return;
}

#ifdef WIN32
public	void	v_putch(int c)
#else
private	void	v_putch(int c)
#endif
{
	switch ( VisEsc.state ) {

		case	0 :	/* awaiting escape */

			if ( c != 27 )
				break;
			else	
				{
				VisEsc.state=1;
				return;
				}

		case	1 :	/* awaiting first  */

			switch (( VisEsc.param = (c&0x00FF))) {
				case	'G'	: /* FCH Séquence EscG */
					x_putch(27);
					x_putch(c);
					VisEsc.escapeGsize = 0;
					VisEsc.escapeGcpt  = 4;
					VisEsc.state = 10;
					return;
					
				case	'T'	:
				case	'f'	:
				case	'q'	:
				case	'n'	:
				case	's'	:
				case	'r'	:
				case	'Z'	:
				case	'('	:
					VisEsc.state=2;
					return;
				default		:
					VisEsc.state = 0;
					x_putch(27);
					x_putch(c);
					return;
				}

		case	2 :	/* awaiting second */

			switch ( VisEsc.param ) {
				case	'T'	:
				case	'f'	:
				case	'Z'	:
					VisEsc.length=(c & 0x00FF);
					VisEsc.state=3;
					return;

				case	'('	:
					VisEsc.state = 0;
					use_visual_atribut(c);
					return;

				case	's'	: esc_s(c); return;
				case	'r'	: esc_r(c); return;
				case	'n'	: esc_n(c); return;
				case	'q'	: esc_q(c); return;
				default		:
					VisEsc.state = 0;
					x_putch(27);
					x_putch(VisEsc.param);
					x_putch(c);
					return;
				}

		case	3 :	/* awaiting third  */

			switch ( VisEsc.param ) {

				case	'T'	:
					x_putch(27);
					x_putch(VisEsc.param);
					x_putch((VisEsc.length & 0x00FF));
					x_putch(c);
					VisEsc.length |= ((c & 0x00FF) << 8);
					VisEsc.state=4;
					return;

				case	'Z'	: 
					esc_Z( VisEsc.length, c ); 
					return;

				case	'f'	: 
					esc_f( VisEsc.length, c ); 
					return;
				}

		case	4 :	/* transparence	   */

			if ( VisEsc.length )
				VisEsc.length--;
			else	VisEsc.state = 0;

			/* transparent packets are never collected */
			/* --------------------------------------- */
			x_putch((c & 0x00FF));
			return;

		case 10 : /* FCH Séquence EscG */
			x_putch(c);
			VisEsc.escapeGsize *= 256;
			VisEsc.escapeGsize += c;
			VisEsc.escapeGcpt--;
			if (!VisEsc.escapeGcpt)
				VisEsc.state = 11;
			return;

		case 11 : /* FCH Séquence EscG */
			x_putch(c);
			VisEsc.escapeGsize--;
			if (!VisEsc.escapeGsize)
				VisEsc.state = 0;
			return;
		}

	if ( VisEsc.atribut ) 
		vv_putch((c&0x00FF));
	else if (( VisEsc.filter ) && ( c == ' '))
		x_putch(6);
	else	x_putch((c&0x00FF));
	return;
}


#endif	/* _REDIRECTED_CICO */
	/* ---------------- */

#endif	/* _vatb_c */
	/* ------- */

