
EXAWORD	is_legal_format( sptr , slen )
BPTR	sptr;
EXAWORD	slen;
{
	EXAWORD	c;
	EXAWORD	status;
	status = 0;

	while ( slen ) {

		c = *(sptr++); slen--; 

		switch ( c ) {

		case	FMT_SEP	: /* 0x0000		   , Separateur des elements	*/
				continue;

		case	FMT_DEB	: /* 0x00FE		      Debut de nouveau format	*/ 
			status++;
			if ( status > 1 )
				return( FAUX );
			continue;

		case	FMT_FIN	: /* 0x00FF		      Fin de format		*/

			if ( slen ) return( FAUX );
			else	    return( VRAI );

		case	FMT_K	: /* 0x0080		   Dn Alpha n non-oblig		*/
		case	FMT_D	: /* 0x0001		   Dn Alpha n non-oblig		*/
		case 	FMT_A	: /* 0x0081		   An Alpha n Oblig		*/
		case	FMT_N	: /* 0x0002		   Nn Numeric n non-oblig	*/
		case	FMT_Z	: /* 0x0082		   Zn Numeric n Oblig		*/
		case	FMT_C	: /* 0x0003		   Cn Alphanum n non-oblig	*/
		case	FMT_B	: /* 0x0083		   Bn Alphanum n Oblig		*/
		case	FMT_W	: /* 0x000F		   Wn Any character n non-oblig	*/
		case	FMT_U	: /* 0x008F		   Un Any character n Oblig	*/
		case	FMT_O	: /* 0x0092		   Format N if none else Z	*/ 
		case	FMT_LF	: /* 0x0021		   /n	n Linefeeds		*/
		case	FMT_TAB	: /* 0x0022		   Tn	n Tabulations		*/
		case	FMT_ESP	: /* 0x0023		   Xn	n Spaces		*/
		case	FMT_ATB	: /* 0x0024		   \n   Attribute Video n	*/
		case	FMT_POS	: /* 0x0044		   +	Both signs		*/
		case	FMT_NEG	: /* 0x0045		   -	Only negative signs	*/
		case	FMT_PNG	: /* 0x0046		   	Only postive signs	*/
		case	FMT_MCH	: /* 0x0048		   S(c) Separateur milliers 	*/
		case	FMT_ZCH	: /* 0x0049		   *(c) Padd Zeros character	*/
		case	FMT_DCH	: /* 0x0053		   $(c) Print until character or*/
		case	FMT_V	: /* 0x0008		   V  Virgule interne		*/
		case	FMT_P	: /* 0x0088		   .  Virgule a saisir affich	*/
			sptr++; slen--;
			continue;


		case	FMT_PR	: /* 0x0020		   "Libelle" a afficher		*/
			while ( *sptr ) {
				sptr++; slen--;
				}
			sptr++; slen--;
			continue;

		case	FMT_ZER	: /* 0x0040		   *	Padd Zeros		*/
		case	FMT_JL	: /* 0x0041		   L 	Justifie Left		*/
		case	FMT_JR	: /* 0x0042		   R	Justifie Right		*/
		case	FMT_JJ	: /* 0x0043		   J	Justifie Centree	*/
		case	FMT_SGN	: /* 0x0042		   + FL  Speciale Value for ASK */
		case	FMT_MIL	: /* 0x0047		   S  Separateur milliers	*/
		case	FMT_STR	: /* 0x0050		   E Format Libre		*/
		case	FMT_CUT	: /* 0x0051		   F No fill to end of zone	*/
		case	FMT_DOL : /* 0x0052		   $	Print len$(string)	*/
		case	FMT_DYN	: /* 0x0054		   ?	Use next variable as to */
		case 	FMT_INH	: /* 0x0055		   If Zero then Padd like *	*/
		case	FMT_MNB	: /* 0x0056		   Separation count format	*/
		case	FMT_H	: /* 0x0057		   Hexadecimal Format for # / %	*/
			continue;
		default		:
			return( FAUX );
		}
	}
	return( FAUX );
}



