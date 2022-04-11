/*
 *	AOTCLIST.C		Copyright (c) 1991, 1993 Amenesik / Sologic s.a. 
 *	----------		--------------------------------------
 *
 *	This file is an include file for :
 *		
 *		TCODE.C		:	for AO the post optimiser
 *		
 *		IDBCODE.C	:	for IDB the Tcode Debugger
 *
 *	It performs tcode assembler listing version 2.1a
 *
 *	Date	:	17/06/1993
 *
 */
 
#ifndef	_AOTCLIST_C
#define	_AOTCLIST_C

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
			sptr++; slen--;
			continue;


		case	FMT_PR	: /* 0x0020		   "Libelle" a afficher		*/
			while ( *sptr ) {
				sptr++; slen--;
				}
			sptr++; slen--;
			continue;

		case	FMT_P	: /* 0x0088		   .  Virgule a saisir affich	*/
		case	FMT_ZER	: /* 0x0040		   *	Padd Zeros		*/
		case	FMT_JL	: /* 0x0041		   L 	Justifie Left		*/
		case	FMT_JR	: /* 0x0042		   R	Justifie Right		*/
		case	FMT_JJ	: /* 0x0043		   J	Justifie Centree	*/
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



EXAWORD	IofOperation( BPTR cptr, EXAWORD si, EXAWORD selection)
{
	EXAWORD	opcount=0;
	EXAWORD	tabl=0;
	while (1) {

		/* Perform Mnemonic Selection */
		/* -------------------------- */
		switch ((((EXAWORD) *(cptr + si)) & 0x000F)) {

			case _io_ASK	:	/* ASK			*/
				if ( selection == 4 ) {
					oputs("=");
					si = ArgMnemonic( cptr , si );
					return(++opcount);
					}
				return( opcount );

			case _io_DEV	:	/* Device Selection	*/
				if (!( selection )) {
					oputs("=");
					si = ArgMnemonic( cptr , si );
					return(++opcount);
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}
				continue;
					
			case _io_TABL	:	/* Tabulation Line	*/
				tabl = si;
				si = ConsumeArgMnemonic( cptr , si );
				continue;
									
			case _io_TABC	:	/* Tabulation Colonne	*/
				if ( selection == 4 ) {
					if ( opcount++ ) oputs(",");
					oputs("TAB(");
					si = ArgMnemonic( cptr , si );
					if ( tabl ) {
						oputs(",");
						(void) ArgMnemonic( cptr , tabl );
						tabl=0;
						}
					oputs(")");
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}
				continue;

			case _io_ATBV	:	/* Screen Atributs	*/
				if ( selection == 4 ) {
					if ( opcount++ ) oputs(",");
					oputs("ATB(");
					si = ArgMnemonic( cptr , si );
					oputs(")");
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}
				continue;

			case _io_TABV	:	/* Tabulation Verticale	*/
				if ( selection == 4 ) {
					if ( opcount++ ) oputs(",");
					oputs("TABV(");
					si = ArgMnemonic( cptr , si );
					oputs(")");
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}
				continue;

			case _io_FORG	:	/* ForeGround Colour	*/
			case _io_BACK	:	/* BackGround Colour	*/
				if ( selection == 4 ) {
					if ( opcount++ ) oputs(",");
					/* Display Mnemonic then Arguament */
					/* ------------------------------- */
			 		IoMnemonic( (((EXAWORD) *(cptr + si)) & 0x000F) );
					si = ArgMnemonic( cptr , si );
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}
				continue;

			case _io_PRN	:	/* PRINT		*/

				if ( selection == 4 ) {
					if ( opcount++ ) oputs(",");
					si = ArgMnemonic( cptr , si );
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}
				continue;

			case _io_ESC	:	/* Escape Codes		*/
				return( opcount );

			case _io_FMT	:	/* Format Infos		*/

				if (( selection == 1 ) || ( selection == 4)) {


					if ( (*(cptr + si) & 0x00F0 ) == 0 ) {
						/* Display of Jump Label */
						/* --------------------- */
						if ( selection == 1 ) {
							oputs(",");
							AffEtt ( (tcGetw((cptr + si + 1)) ) );
							}
						si += (WORDSIZE+1);
						continue;
						}
					else	{
						if ( (( *(cptr + si) & 0x00F0 ) >> 5) <= 3 ) {
							if ( selection == 4 ) {
								if ( opcount++ ) { oputs(","); }
								si = ArgMnemonic( cptr , si );
								}
							else	si = ConsumeArgMnemonic( cptr, si );
							}	
						else	{
							if ( selection == 4 ) {
								if ( opcount++ ) { oputs(","); }
								si++;
								fmtoa( (cptr + si) );
								si += (*(cptr + si) + 1);	
								}
							else	si = ConsumeArgMnemonic( cptr, si );
							} 
						}

					}

				else	{
					if ( (*(cptr + si) & 0x00F0 ) == 0 ) {
						/* Display of Jump Label */
						/* --------------------- */
						si += (WORDSIZE+1);
						continue;
						}
					else	{
						if ( (( *(cptr + si) & 0x00F0 ) >> 5) <= 3 ) {
							si = ConsumeArgMnemonic( cptr , si );
							}
						else	{
							si++;
							si += (*(cptr + si) + 1);
							} 
						}
					}
				continue;

			case _io_SPX	:	/* CLEAR HOME BELL	*/

				if ( selection == 4 ) {
					opcount++;
					switch ((( *(cptr + si ) & 0x00F0 ) >> 5) ) {	
						case 0 : oputs( "CLEAR" ); break;
						case 1 : oputs( "HOME" ); break;
						case 2 : oputs( "BELL" ); break;

						}
					}
				si++;
				continue;

			/* Jump Label Keys */
			/* --------------- */
			case _io_HOT1	:	/* I=&ettiquette etc	*/

				if ( selection == 2 ) {
					oputs(",");
					opcount++;
					switch ((( *(cptr + si ) & 0x00F0 ) >> 4 )) {	
						case 0x0000 : oputs( "I"); break;
						case 0x0001 : oputs( "L"); break;
						case 0x0002 : oputs( "U"); break;
						case 0x0003 : oputs( "D"); break;
						case 0x0004 : oputs( "E"); break;
						case 0x0005 : oputs( "T"); break;
						case 0x0006 : oputs( "X"); break;
						}
					}
				si++;
				if ( selection == 2 ) {
					oputs("=(");
					/* Display of Jump Label */
					/* --------------------- */
					AffEtt ( (tcGetw((cptr + si)) ) );
					oputs(")");
					}
				si += WORDSIZE;
				continue;

			case _io_HOT2	:	/* I=(&ettiquette) etc	*/

				if ( selection == 2 ) {
					oputs(",");

					opcount++;
					switch ((( *(cptr + si ) & 0x00F0 ) >> 4)) {	
						case 0x0000 : oputs( "I"); break;
						case 0x0001 : oputs( "L"); break;
						case 0x0002 : oputs( "U"); break;
						case 0x0003 : oputs( "D"); break;
						case 0x0004 : oputs( "E"); break;
						case 0x0005 : oputs( "T"); break;
						case 0x0006 : oputs( "X"); break;
						}
					}
				si++;
				if ( selection == 2 ) {
					oputb( '=' );
					/* Display of Jump Label */
					/* --------------------- */
					AffEtt ( (tcGetw((cptr + si)) ) );
					}
				si += WORDSIZE;
				continue;

			case _io_KEY1	:	/* Hot Key Goto		*/
				if ( selection == 2 ) {
					oputs(",");
					si = ArgMnemonic( cptr , si );
					opcount++;
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}

				if ( selection == 2 ) {
					oputs( "=" );

					/* Display of Jump Label */
					/* --------------------- */
					AffEtt ( (tcGetw((cptr + si)) ) );
					}
				si += WORDSIZE;
				continue;

			case _io_KEY2	:	/* Hot Key Gosub	*/
				if ( selection == 2 ) {
					oputs(",");
					si = ArgMnemonic( cptr , si );
					opcount++;
					}
				else	{
					si = ConsumeArgMnemonic( cptr , si );
					}

				if ( selection == 2 ) {
					oputs( "=(" );
					/* Display of Jump Label */
					/* --------------------- */
					AffEtt ( (tcGetw((cptr + si)) ) );
					oputs( ")" );
					si += WORDSIZE;
					}
				continue;
			}

		}
	return(opcount);
}


EXAWORD	IofAnalysis( BPTR cptr, EXAWORD si, EXAWORD comment  )
{
	EXAWORD	AskMode=FAUX;
	EXAWORD	IsAsk=0;
	EXAWORD	osi=si;
	oline();
	Comment(comment);

	do	{

		/* Perform Mnemonic Selection */
		/* -------------------------- */
		switch ((((EXAWORD) *(cptr + si)) & 0x000F)) {

			case _io_ASK	:	/* ASK			*/
				IsAsk=VRAI;
				AskMode = VRAI;

			case _io_TABC	:	/* Tabulation Colonne	*/
			case _io_ATBV	:	/* Screen Atributs	*/
			case _io_TABV	:	/* Tabulation Verticale	*/
			case _io_DEV	:	/* Device Selection	*/
			case _io_FORG	:	/* ForeGround Colour	*/
			case _io_BACK	:	/* BackGround Colour	*/
			case _io_TABL	:	/* Tabulation Line	*/
			case _io_PRN	:	/* PRINT		*/

				si = ConsumeArgMnemonic( cptr , si );
				continue;

			case _io_ESC	:	/* Escape Codes		*/
				switch (( *(cptr + si ) & 0x00F0 ) ) {	
					case 0x0000 : 
						AskMode = VRAI; 
						si++;
						continue;
					}
				si++;
				continue;

			case _io_FMT	:	/* Format Infos		*/

				if ( (*(cptr + si) & 0x00F0 ) == 0 ) {
					/* Display of Jump Label */
					/* --------------------- */
					si += (WORDSIZE+1);
					continue;
					}
				else	{
					if ( (( *(cptr + si) & 0x00F0 ) >> 5) <= 3 ) {
						si = ConsumeArgMnemonic( cptr , si );
						}
					else	{
						si++;
						si += (*(cptr + si) + 1);
						} 
					}
				continue;

			case _io_SPX	:	/* CLEAR HOME BELL	*/

				si++;
				continue;

			/* Jump Label Keys */
			/* --------------- */
			case _io_HOT1	:	/* I=&ettiquette etc	*/

				si++;
				si += WORDSIZE;
				continue;

			case _io_HOT2	:	/* I=(&ettiquette) etc	*/


				si++;
				si += WORDSIZE;
				continue;

			case _io_KEY1	:	/* Hot Key Goto		*/
				si = ConsumeArgMnemonic( cptr , si );
				si += WORDSIZE;
				continue;

			case _io_KEY2	:	/* Hot Key Gosub	*/
				si = ConsumeArgMnemonic( cptr , si );
				si += WORDSIZE;
				continue;


			}
		}
	while (AskMode == FAUX);


	if ( IsAsk ) 
		oputs("ASK");
	else	oputs("PRINT");


	if (!( IofOperation( cptr, osi, 0 ) ))
		oputs("=1");

	if ( IsAsk )
		IofOperation( cptr, osi, 2 );
	else 	IofOperation( cptr, osi, 1 );

	oputs(":");

	IofOperation( cptr, osi, 4 );


	return( si );
	
}

BPTR	tcfreg[256];
BPTR	tcireg[256];
BPTR	tcareg[256];


VOID	RegisterReset()
{
	EXAWORD	r;
	for ( r=0; r < 256; r++ ) {
		tcfreg[r] = (BPTR) 0;
		tcireg[r] = (BPTR) 0;
		tcareg[r] = (BPTR) 0;
		}
	return;
}

BPTR	tcliberate( BPTR sptr )
{
	if ( sptr )
		free( sptr );
	return((BPTR) 0);
}

VOID	RegisterRelease()
{
	EXAWORD	r;
	for ( r=0; r < 256; r++ ) {
		if ( tcfreg[r] )
			tcfreg[r] = tcliberate( tcfreg[r] );
		if ( tcireg[r] )
			tcireg[r] = tcliberate( tcireg[r] );
		if ( tcareg[r] )
			tcareg[r] = tcliberate( tcareg[r] );
		}
	return;
}


EXAWORD	TcodeList( cptr , si , comment )
BPTR	cptr;
EXAWORD	si;
EXAWORD	comment;
{
	BPTR	sptr;
	EXAWORD	AskMode;
	EXAWORD	CodeUsed;
	EXAWORD	di;
	EXAWORD	v;
	EXAWORD	x;
	EXAWORD	xtc;

	sptr = cptr + si; CodeUsed = 0; di = si;

	/* Check for End of Tcode */
	/* ---------------------- */
	if (( *(cptr + si) == 0x00FF )
	&&  ( *(cptr + si + 1) == 0x00FF ))
		return( CodeUsed );

	/* Check for and perform Comment for Compiler */
	/* ------------------------------------------ */
	Comment(comment);


	/* Display the T-Code adresse */
	/* -------------------------- */
#ifdef	DEBUGGER
	oputb(' '); HexWord( si ); oputb(' ');
#else
	AffEtt( si ); 
#endif
	/* Check for T-Code Format Strings */
	/* ------------------------------- */
	if (((EXAWORD) *(cptr + si + 1)) == 0x00FE)
		if ( is_legal_format( (cptr + si + 1), *(cptr + si) ) == VRAI )
			return(( *(cptr + si) + 1) );

	/* Establish New Line Symbol */
	/* ------------------------- */
	oputb(' ');
	if ( *(cptr + si) & 0x0080 ) 	{ 
		if ( enhanced_list()) {
			RegisterRelease();
			}
		oputs("::"); 
		}
	else	{
		oputs("  ");
		}
	oputb(' ');

	/* Display the T-Code mnemonic */
	/* --------------------------- */
	switch ( (((EXAWORD) *(cptr + si)) & 0x007F) ) {
		case	_tc_CLF	:
		case	_tc_NGF	:
		case	_tc_ESC	:
			if ( enhanced_list())
				break;
		case	_tc_IOF	:
			if ( enhanced_list() == 2)
				break;
		default		:
				Mnemonic( (((EXAWORD) *(cptr + si)) & 0x007F) );
		}
		
	/* Perform T-Code syntax analysis */
	/* ------------------------------ */
	switch ((xtc = (((EXAWORD) *(cptr + si)) & 0x007F) )) {

		/* Standard ABAL library functions */
		/* ------------------------------- */
		case _tc_CLF :
			CodeUsed = LibMnemonics( cptr , si , _tc_CLF );
			break;

		case _tc_NGF :
			if ( enhanced_list() ) {
				CodeUsed = NgfAnalysis( cptr, si, comment );
				}
			else	{
				CodeUsed = NgfSyntax( cptr , si , comment );
				}
			break;

		case _tc_WHN :
			CodeUsed = EventSyntax( (cptr + si) );
			break;

		/* Extended Escape Code functions */
		/* ------------------------------ */
		case _tc_ESC :
			if ( enhanced_list() ) {
				if (!( CodeUsed = EscAnalysis( cptr, si, comment ) ))
					CodeUsed++;
				}
			else if (!(CodeUsed = EscSyntax( cptr , si )))
				CodeUsed++;
			break;

		/* USER FUNCTIONS (Dynamic libraries) */
		/* ---------------------------------- */
		case _tc_LDE :
		case _tc_LDF :	
			CodeUsed = LibMnemonics( cptr , si , xtc );
			break;

		/* PRINT and ASK functions */
		/* ----------------------- */
		case _tc_IOF :

			si++;	

			if ( enhanced_list() == 2 ) {
				si  = IofAnalysis( cptr, si, comment );
				}
			else	{
			/* Enter IO Tcode Cycle */
			/* -------------------- */
			AskMode = FAUX;

			do	{

				oline();
				Comment(comment);

				/* Perform Mnemonic Selection */
				/* -------------------------- */
				switch ((((EXAWORD) *(cptr + si)) & 0x000F)) {

					case _io_ASK	:	/* ASK			*/
						AskMode = VRAI;

					case _io_TABC	:	/* Tabulation Colonne	*/
					case _io_ATBV	:	/* Screen Atributs	*/
					case _io_TABV	:	/* Tabulation Verticale	*/
					case _io_DEV	:	/* Device Selection	*/
					case _io_FORG	:	/* ForeGround Colour	*/
					case _io_BACK	:	/* BackGround Colour	*/
					case _io_TABL	:	/* Tabulation Line	*/
					case _io_PRN	:	/* PRINT		*/

						/* Display Mnemonic then Arguament */
						/* ------------------------------- */
				 		IoMnemonic( (((EXAWORD) *(cptr + si)) & 0x000F) );
						si = ArgMnemonic( cptr , si );
						continue;

					case _io_ESC	:	/* Escape Codes		*/

						switch (( *(cptr + si ) & 0x00F0 ) ) {	
							case 0x0000 : 
								oputs( "      FIO"); 
								AskMode = VRAI; 
								si++;
								continue;
							}
						si++;
						continue;

					case _io_FMT	:	/* Format Infos		*/

				 		IoMnemonic( (((EXAWORD) *(cptr + si)) & 0x000F) );
						oputb(' ');
						if ( (*(cptr + si) & 0x00F0 ) == 0 ) {
							/* Display of Jump Label */
							/* --------------------- */
							AffEtt ( (tcGetw((cptr + si + 1)) ) );
							si += (WORDSIZE+1);
							continue;
							}
						else	{
							if ( (( *(cptr + si) & 0x00F0 ) >> 5) <= 3 ) {
								si = ArgMnemonic( cptr , si );
								}
							else	{
								si++;
								fmtoa( (cptr + si) );
								si += (*(cptr + si) + 1);
								} 
							}
						continue;

					case _io_SPX	:	/* CLEAR HOME BELL	*/

						switch ((( *(cptr + si ) & 0x00F0 ) >> 5) ) {	
							case 0 : oputs( "      CLEAR" ); break;
							case 1 : oputs( "      HOME" ); break;
							case 2 : oputs( "      BELL" ); break;
		
							}
						si++;
						continue;

					/* Jump Label Keys */
					/* --------------- */
					case _io_HOT1	:	/* I=&ettiquette etc	*/

						oputs( "      GSB " );

						switch ((( *(cptr + si ) & 0x00F0 ) >> 4 )) {	
							case 0x0000 : oputs( "I "); break;
							case 0x0001 : oputs( "L "); break;
							case 0x0002 : oputs( "U "); break;
							case 0x0003 : oputs( "D "); break;
							case 0x0004 : oputs( "E "); break;
							case 0x0005 : oputs( "T "); break;
							case 0x0006 : oputs( "X "); break;
							}

						si++;
						oputb( ',' );
						/* Display of Jump Label */
						/* --------------------- */
						AffEtt ( (tcGetw((cptr + si)) ) );
						si += WORDSIZE;
						continue;

					case _io_HOT2	:	/* I=(&ettiquette) etc	*/

						oputs( "      JMP " );

						switch ((( *(cptr + si ) & 0x00F0 ) >> 4)) {	
							case 0x0000 : oputs( "I "); break;
							case 0x0001 : oputs( "L "); break;
							case 0x0002 : oputs( "U "); break;
							case 0x0003 : oputs( "D "); break;
							case 0x0004 : oputs( "E "); break;
							case 0x0005 : oputs( "T "); break;
							case 0x0006 : oputs( "X "); break;
							}

						si++;
						oputb( ',' );
						/* Display of Jump Label */
						/* --------------------- */
						AffEtt ( (tcGetw((cptr + si)) ) );
						si += WORDSIZE;
						continue;

					case _io_KEY1	:	/* Hot Key Goto		*/
						oputs( "      JMP " );
						si = ArgMnemonic( cptr , si );
						oputb( ',' );
						/* Display of Jump Label */
						/* --------------------- */
						AffEtt ( (tcGetw((cptr + si)) ) );
						si += WORDSIZE;
						continue;

					case _io_KEY2	:	/* Hot Key Gosub	*/
						oputs( "      GSB " );
						si = ArgMnemonic( cptr , si );
						oputb( ',' );
						/* Display of Jump Label */
						/* --------------------- */
						AffEtt ( (tcGetw((cptr + si)) ) );
						si += WORDSIZE;
						continue;
					}
	
					/* Display of Jump Label */
					/* --------------------- */
					AffEtt ( (tcGetw((cptr + si + 1)) ) );
					si += WORDSIZE;
	
					}
				while (AskMode == FAUX);

				}
			CodeUsed = (si - di);
			break;

		case _tc_ADI :
		case _tc_SBI :
		case _tc_MLI :
		case _tc_DVI :
		case _tc_MDI :
		case _tc_ANI :
		case _tc_ORI :
		case _tc_XRI :	AffReg( *(sptr + 1) );		oputb(',');
				HexWord( (tcGetw((sptr + 2))) ); oputb(',');
				AffReg( *(sptr + 2+WORDSIZE) );
				CodeUsed = 3+WORDSIZE;
				break;
		case _tc_ADV :
		case _tc_SBV :
		case _tc_MLV :
		case _tc_DVV :
		case _tc_MDV :
		case _tc_ANV :
		case _tc_ORV :
		case _tc_XRV :	AffReg( *(sptr + 1) );		oputb(',');
				AffVarb( (tcGetw((sptr + 2))) ); oputb(',');
				AffReg( *(sptr + 2+WORDSIZE) );
				CodeUsed = 3+WORDSIZE;
				break;
		case _tc_ADC :
		case _tc_SBC :
		case _tc_MLC :
		case _tc_DVC :
		case _tc_MDC :
		case _tc_ANC :
		case _tc_ORC :
		case _tc_XRC :	AffReg( *(sptr + 1) );		oputb(',');
				AffCons( (tcGetw((sptr + 2))) ); oputb(',');
				AffReg( *(sptr + 2+WORDSIZE) );
				CodeUsed = 3+WORDSIZE;
				break;
		case _tc_ADR :
		case _tc_SBR :
		case _tc_MLR :
		case _tc_DVR :
		case _tc_MDR :
		case _tc_ANR :
		case _tc_ORR :
		case _tc_XOR :	AffReg( *(sptr + 1) );	 oputb(',');
				AffReg( *(sptr + 2) );   oputb(',');
				AffReg( *(sptr + 3) );
				CodeUsed = 4;
				break;
		case _tc_JEQI:
		case _tc_JNEI:
		case _tc_JGRI:
		case _tc_JLSI:
		case _tc_JGEI:
		case _tc_JLEI:	AffReg ( *(sptr + 1) ); 	 oputb(',');
				HexWord( (tcGetw((sptr + 2))) ); oputb(',');
				AffEtt ( (tcGetw((sptr + 2 + WORDSIZE)) ) );
				CodeUsed = 2+(2*WORDSIZE); break;
		case _tc_JEQV:
		case _tc_JNEV:
		case _tc_JGRV:
		case _tc_JLSV:
		case _tc_JGEV:
		case _tc_JLEV:
		case _tc_JINV:
		case _tc_JNIV:	AffReg ( *(sptr + 1) ); 	 oputb(',');
				AffVarb( (tcGetw((sptr + 2))) ); oputb(',');
				AffEtt ( (tcGetw((sptr + 2 + WORDSIZE)) ) );
				CodeUsed = 2+(2*WORDSIZE); break;
		case _tc_JEQC:
		case _tc_JNEC:
		case _tc_JGRC:
		case _tc_JLSC:
		case _tc_JGEC:
		case _tc_JLEC:
		case _tc_JINC:
		case _tc_JNIC:	AffReg ( *(sptr + 1) ); 	 oputb(',');
				AffCons( (tcGetw((sptr + 2))) ); oputb(',');
				AffEtt ( (tcGetw((sptr + 2 + WORDSIZE)) ) );
				CodeUsed = 2 + (2*WORDSIZE); break;
		case _tc_JEQR:
		case _tc_JNER:
		case _tc_JGRR:
		case _tc_JLSR:
		case _tc_JGER:
		case _tc_JLER:
		case _tc_JINR:
		case _tc_JNIR:	AffReg ( *(sptr + 1) ); oputb(',');
				AffReg ( *(sptr + 2) ); oputb(',');
				AffEtt ( (tcGetw((sptr + 3)) ) );
				CodeUsed = 3+WORDSIZE; break;

		case _tc_STI :	HexWord( (tcGetw((sptr + 1))) ); oputb(',');
				AffVarb( (tcGetw((sptr + 1+WORDSIZE))) );
				CodeUsed = 1+(2*WORDSIZE); break;

		case _tc_STC :	AffCons( (tcGetw((sptr + 1))) ); oputb(',');
				AffVarb( (tcGetw((sptr + 1+WORDSIZE))) );
				CodeUsed = 1+(2*WORDSIZE); break;

		case _tc_STV :	AffVarb( (tcGetw((sptr + 1))) ); oputb(',');
				AffVarb( (tcGetw((sptr + 1+WORDSIZE))) );
				CodeUsed = 1+(2*WORDSIZE); break;

		case _tc_GWS :
		case _tc_LWS :	HexWord( (tcGetw((sptr + 1))) ); 
				oputs(", offset ");
				HexWord((tcGetw((sptr + 1+WORDSIZE))));
				CodeUsed = 1+(2*WORDSIZE); break;
		case _tc_JMI :
		case _tc_GSB :
		case _tc_REQ :	AffEtt ( (tcGetw((sptr + 1))) );
				CodeUsed = 1+WORDSIZE; break;
		case _tc_OEP :
		case _tc_NEW :
		case _tc_RAZ :
		case _tc_NOP :
		case _tc_RES :
		case _tc_RET :
		case _tc_SGN :
		case _tc_ERA :	CodeUsed = 1; break;

		case _tc_OER :
				AffReg ( *(sptr + 1) ); 	oputb(',');
				AffEtt ( (tcGetw((sptr + 2))) );
				CodeUsed = 2+WORDSIZE; break;
		case _tc_OLE :
		case _tc_OEO :
		case _tc_OEV :
		case _tc_OPV :	v = (tcGetw((sptr + 1)));
				/* Watch out for OP &ETT */
				/* --------------------- */
				if ( v != 0 ) {
					AffVarb( v ); 
					oputb(',');
					}
				AffEtt ( (tcGetw((sptr + 1 + WORDSIZE))) );				
				CodeUsed = 1 + (2*WORDSIZE); break;
		case _tc_CNV :
		case _tc_LXI :
		case _tc_AXI :
		case _tc_LDI :	AffReg ( *(sptr + 1) ); 	oputb(',');
				HexWord( (tcGetw((sptr + 2))) );
				CodeUsed = 2+WORDSIZE; break;
		case _tc_LXC :
		case _tc_AXC :
		case _tc_LDC :	AffReg ( *(sptr + 1) ); 	oputb(',');
				AffCons( (tcGetw((sptr + 2))) );
				CodeUsed = 2+WORDSIZE; break;
		case _tc_LXR :
		case _tc_AXR :
		case _tc_LDR :	AffReg ( *(sptr + 1) ); 	oputb(',');
				AffReg ( *(sptr + 2) );
				CodeUsed = 3; break;
/*		case _tc_CER :	*/
		case _tc_GIL :
		case _tc_LIL :
		case _tc_GCL :
		case _tc_LCL :
		case _tc_GIS :
		case _tc_LIS :
		case _tc_GCS :
		case _tc_LCS :	AffReg ( *(sptr + 1) ); oputs(", offset ");
				HexWord((tcGetw((sptr + 2))));
				CodeUsed = 2+WORDSIZE; break;

		case _tc_STR :
		case _tc_LDV :
		case _tc_VPT :
		case _tc_LXV :
		case _tc_AXV : 	AffReg ( *(sptr + 1) ); oputb(',');
				AffVarb( (tcGetw((sptr + 2))));
				CodeUsed = 2+WORDSIZE; break;

		case _tc_DTR :
		case _tc_PSH :
		case _tc_POP :
		case _tc_NGR :
		case _tc_INC :
		case _tc_DEC :
		case _tc_INX :
		case _tc_DEX :
		case _tc_ANX :
		case _tc_DAX : 	AffReg ( *(sptr + 1) );
				CodeUsed = 2; break;
		case _tc_DTV :
		case _tc_NGV :	AffVarb( (tcGetw((sptr + 1))));
				CodeUsed = 1+WORDSIZE; break;

		case _tc_TIM :	if (( *( sptr + 1 ) & 0x000F) == 0 ) {
					oputs( " OFF " );
					CodeUsed = 2;
					}
				else	{

					/* Handle Label and Value */
					/* ---------------------- */
					switch (( *(sptr + 1) & 0x00F0 )) {
						case 0x0000 :	HexWord( (tcGetw((sptr + 2))) );
								CodeUsed = 2+WORDSIZE;
								break;
						case 0x0020 :	AffCons( (tcGetw((sptr + 2))) );
								CodeUsed = 2+WORDSIZE;
								break;
						case 0x0040 :	AffVarb( (tcGetw((sptr + 2))) );
								CodeUsed = 2+WORDSIZE;
								break;
						case 0x0060 :	AffReg ( *(sptr + 2) );
								CodeUsed = 3;
						}
					switch (( *(sptr + 1) & 0x000F)) {
						case	2 :	oputs( " GSB " ); break;
						case	1 :	oputs( " JMP " ); break;
						case	3 :	oputs( " CALL " ); break;
						}

					AffEtt ( (tcGetw((sptr + CodeUsed))) );
					CodeUsed += WORDSIZE;
					}
				break;
		}
	StreamLine();
	return( CodeUsed );
}

#endif	/* _AOTCLIST_C */
	/* ----------- */

