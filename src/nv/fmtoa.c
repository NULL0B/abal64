/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	FMTOA					*/
/*		Version :	1.4a					*/
/*		Date 	:	12/12/1990				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	FMTOA_C		/* If not already included		*/
#define	FMTOA_C		/* Avoid multiple inclusions		*/

/*	Format code string control	*/
/*	--------------------------	*/

#define	FMT_SEP	0x0000		/* , Separateur des elements	*/
#define	FMT_DEB	0x00FE		/*    Debut de nouveau format	*/ 
#define	FMT_FIN	0x00FF		/*    Fin de format		*/

/*	Character type control masks	*/
/*	----------------------------	*/

#define	FMT_D	0x0001		/* Dn Alpha n non-oblig		*/
#define FMT_A	0x0081		/* An Alpha n Oblig		*/
#define	FMT_N	0x0002		/* Nn Numeric n non-oblig	*/
#define	FMT_Z	0x0082		/* Zn Numeric n Oblig		*/
#define	FMT_C	0x0003		/* Cn Alphanum n non-oblig	*/
#define	FMT_B	0x0083		/* Bn Alphanum n Oblig		*/
#define	FMT_W	0x000F		/* Wn Any character n non-oblig	*/
#define	FMT_U	0x008F		/* Un Any character n Oblig	*/

#define	FMT_O	0x0092		/* Format N if none else Z	*/ 

#define	FMT_V	0x0008		/* V  Virgule interne		*/
#define	FMT_P	0x0088		/* .  Virgule a saisir affich	*/

/*	Format Action codes		*/
/*	-------------------		*/

#define	FMT_PR	0x0020		/* "Libelle" a afficher		*/
#define	FMT_LF	0x0021		/* /n	n Linefeeds		*/
#define	FMT_TAB	0x0022		/* Tn	n Tabulations		*/
#define	FMT_ESP	0x0023		/* Xn	n Spaces		*/
#define	FMT_ATB	0x0024		/* \n   Attribute Video n	*/

/*	Format Environment codes	*/
/*	------------------------	*/

#define	FMT_ZER	0x0040		/* *	Padd Zeros		*/
#define	FMT_JL	0x0041		/* L 	Justifie Left		*/
#define	FMT_JR	0x0042		/* R	Justifie Right		*/
#define	FMT_JJ	0x0043		/* J	Justifie Centree	*/
#define	FMT_SGN	0x0042		/* + FL  Speciale Value for ASK */
#define	FMT_POS	0x0044		/* +	Both signs		*/
#define	FMT_NEG	0x0045		/* -	Only negative signs	*/
#define	FMT_PNG	0x0046		/* 	Only postive signs	*/
#define	FMT_MIL	0x0047		/* S  Separateur milliers	*/
#define	FMT_MCH	0x0048		/* S(c) Separateur milliers 	*/
#define	FMT_ZCH	0x0049		/* *(c) Padd Zeros character	*/
#define	FMT_STR	0x0050		/* E Format Libre		*/
#define	FMT_CUT	0x0051		/* F No fill to end of zone	*/
#define	FMT_DOL 0x0052		/* $	Print len$(string)	*/
#define	FMT_DCH	0x0053		/* $(c) Print until character or*/
				/*	End of string !		*/ 
#define	FMT_DYN	0x0054		/* ?	Use next variable as to */
				/*      fullfill the next FMT   */
				/*	filter requirements	*/
#define FMT_INH	0x0055		/* If Zero then Padd like *	*/
#define	FMT_MNB	0x0056		/* Separation count format	*/
#define	FMT_H	0x0057		/* Hexadecimal Format for # / %	*/

#define	BYTE unsigned char 
#define	WORD unsigned short
#define	PTR  *
#define BPTR BYTE PTR

#define	output_byte( rptr, b ) *(rptr++) = b

void	output_word( BPTR result, WORD x )
{
	WORD	n;
	WORD	f;

	if ( x == 0 ) { 
		output_byte(result,'0'); 
		}
	else	{
		for (f = 0, n = 10000; n > 0; n /= 10 ) {
			if ((( x / n ) > 0 ) || ( f != 0)) {
				output_byte(result,(( x / n) | 0x0030));
				f = 1;
				}
			x %= n;
			}
		}
	return;
}

WORD	fmtoa(BPTR  result, BPTR  source)
{
	WORD	xtrl,x,y,n;
	BPTR 	nptr;
	BPTR 	hptr;
	BYTE	valu[4];
	WORD	fmtlng;
	WORD	fmtret;

fmtlng	= (WORD) *(source++); fmtret = fmtlng;

if ( *source != (BYTE) 0x00FE ) { 
	return(fmtret); 
	}

source++; output_byte(result,'('); xtrl = 0;

do 	{ 
	y = (WORD) *(source++); 
	switch ( y ) {
		case	FMT_D	: x = 'D' ; break;
		case	FMT_A	: x = 'A' ; break;
		case	FMT_N	: x = 'N' ; break;
		case	FMT_Z	: x = 'Z' ; break;
		case	FMT_O	: x = 'O' ; break;
		case	FMT_C	: x = 'C' ; break;
		case	FMT_B	: x = 'B' ; break;
		case	FMT_W	: x = 'W' ; break;
		case	FMT_U	: x = 'U' ; break;
		case	FMT_V   : output_byte(result,'V'); source++;  continue;
		case	FMT_P	: output_byte(result,'.'); continue;
		case	FMT_DOL : output_byte(result,'$'); continue;
		case	FMT_PR	: output_byte(result,'"'); 
				  x = *(source++);
				  while (x > 0) { output_byte(result,*(source++)); x--;}
				  output_byte(result,'"'); continue;
		case	FMT_LF  : x = '/' ; break;
		case	FMT_ATB	: x = '\\' ; break;
		case	FMT_TAB	: x = 'T' ; break;
		case	FMT_ESP	: x = 'X' ; break;
		case	FMT_SEP	: output_byte(result,',');  continue;
		case	FMT_STR	: output_byte(result,'E');  continue;
		case	FMT_CUT	: output_byte(result,'F');  continue;
		case	FMT_ZER	: output_byte(result,'*');  continue;
		case	FMT_JL	: output_byte(result,'L');  continue;
		case	FMT_JR	: output_byte(result,'R');  continue;
		case	FMT_NEG	: x = '-'; break;
		case	FMT_PNG	: x = '+'; break;
		case 	FMT_H   : output_byte(result,'H');  continue;
		case 	FMT_INH : output_byte(result,'I');  continue;
		case	FMT_MIL : output_byte(result,'S');  continue;
		case	FMT_DYN : output_byte(result,'?');  continue;
		case	FMT_MCH	: output_byte(result,'S');
				  output_byte(result,'(');
				  output_byte(result,*(source++)); 
				  output_byte(result,')');
				  continue;
		case	FMT_DCH	: output_byte(result,'$');
				  output_byte(result,'(');
				  output_byte(result,*(source++)); 
				  output_byte(result,')');
				  continue;
		case	FMT_ZCH	: output_byte(result,'*');
				  output_byte(result,'(');
				  output_byte(result,*(source++)); 
				  output_byte(result,')');
				  continue;
		case	FMT_FIN	:
		default		: output_byte(result,')'); xtrl = 1; continue;
		}
	output_byte(result, x ); 

	x = (WORD) *(source++);
	
	if (( x != 1 ) || ( y & 0x0020 )) {
		output_word(result, x );
		}
	}
while ( xtrl == 0 );
return(fmtret);

}


#endif	/* FMTOA_C */

