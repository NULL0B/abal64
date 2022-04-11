/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXPOWER.C 				*/
/*		Date 	:	10/10/1994				*/
/*		Version :	2.1c 					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXPOWER_C
#define	_EXPOWER_C

BPTR	wsptr;
EXAWORD	wslen;
EXAWORD	wsphz;

EXAWORD	Digit()
{
	if ( wslen > 0 ) {
		if ( wsphz & 1 ) { 
			wsphz = 0; wslen--; 
			return( (((EXAWORD) *(wsptr++)) & 0x000F )); 
			}
   		else	{ 
			wsphz = 1; 
			return( (((EXAWORD) *wsptr ) >> 4 )); 
			}
   		}
	else	return( 0x000F );
}

EXAWORD	bcd2std( bcds, lens, bcdr, lenr )
BPTR	bcds;
EXAWORD	lens;
BPTR	bcdr;
EXAWORD	lenr;
{
	EXAWORD	regx,regy;
	EXAWORD	flg,phase;

	wsphz = 0; wsptr = bcds; wslen = lens;

	/* Flg Controls the Mode of operation */
	/* ---------------------------------- */
	flg = 0; phase = 0;
	while (( lens > 0 ) && ( lenr > 0 )) {
		regx = Digit();
		switch ( regx ) {
			case 0x000F :	lens = 0; continue;
			case 0x000E :
			case 0x000D :	err_val = ABAL_BCDFORM; 
					return(SOFTERROR);
			case 0x000C :
			case 0x000B :   break;
			case 0x000A :	continue;
			case 0x0000 :	if ( flg == 0 ) 
						continue;
			default     :   if ( flg == 0 ) { 
						flg = 1; phase = 0;
						*(bcdr++) = (EXABYTE) (regy | regx); lenr--; phase = 0;
						regx = 0x000A;
						}
			}
		if ( phase == 0 ) { 
			regy = regx << 4; 
			phase = 1; 
			}
		else	{ 
			*(bcdr++) = (EXABYTE) (regy | regx); 
			lenr--; 
			phase = 0;
			}
		}
	if (( lenr > 0 ) && ( phase == 1 )) { 
		*(bcdr++) = (EXABYTE) (regy | 0x000F); 
		lenr--; 
		}
	while ( lenr > 0 ) { 
		*(bcdr++) = (EXABYTE) 0x00FF; 
		lenr--; 
		} 
	return(1);
}

BINAIRE	bcdpower( bcds , lens )
BPTR	bcds;
EXAWORD	lens;
{
	BINAIRE	pwr,flg;
	err_val = 0;
	if (( *bcds == 0x00CF ) || ( *bcds == 0x00BF ))
		return( 0 );
	wsphz = 0; wsptr = bcds; wslen = lens; pwr = -1; flg = 0;
	while ( lens > 0 ) {
		switch ( Digit() ) {
			case 0x000F :	if ( flg != 1 ) 
						pwr = 0;
					return( pwr );
			case 0x000E :
			case 0x000D :	err_val = ABAL_BCDFORM; 
					return(-1);
			case 0x000C :
			case 0x000B :   continue;
			case 0x000A :	if ( flg == 1 )
						return( pwr );
					flg = 2; 
					continue;
			case 0x0000 :	if ( flg == 0 ) 
						continue; 
					if ( flg == 2 ) { 
						pwr--; 
						continue; 
						}
			default     :   if ( flg != 2 ) { 
						flg = 1; 
						pwr++; 
						continue; 
						}
					return( pwr );
			}
		}
	return(pwr);
}

EXAWORD	std2bcd( bcds, lens, bcdr, lenr , pow)
BPTR	bcds;
EXAWORD	lens;
BPTR	bcdr;
EXAWORD	lenr;
BINAIRE	pow;
{
	register EXAWORD	regx,regy;
		 EXAWORD	flg,phase;

	pow += bcdpower( bcds , lens );
	if ( err_val != 0 ) 
		return(SOFTERROR);
	wsphz = 0; wsptr = bcds; wslen = lens;

	if ( pow < 0 ) {	/* Negative power results */
		pow++;
		*(bcdr++) = (EXABYTE) (( Digit() << 4 ) | 0x000A ); lenr--;
		phase = 0; regy = 0;
		while (( pow < 0 ) && (lenr > 0)) {
			if ( phase == 0 ) 
				phase = 1; 
			else	{ 
				*(bcdr++) = (EXABYTE) 0; 
				phase = 0; lenr--; 
				}
			pow++; 
			}
		flg = 0;
		}
	else	{ pow += 2; flg = 0; phase = 0; }

	while (( lens > 0 ) && ( lenr > 0 )) {
		regx = Digit();
		switch ( regx ) {
			case 0x000F :	lens = 0; continue;
			case 0x000E :
			case 0x000D :	err_val = ABAL_BCDFORM; 
					return(SOFTERROR);
			case 0x000C :
			case 0x000B :   break;
			case 0x000A :	continue;
			case 0x0000 :	if ( flg == 0 ) 
						continue;
			default     :   flg = 1;
					if ( pow > 0 ) {
						pow--;
						if ( pow == 0 ) {
							if ( phase == 0 ) {
								*(bcdr++) = (EXABYTE) ( 0x00A0 | regx ); lenr--;
								continue;
								}
							else	{
								*(bcdr++) = (EXABYTE) (regy | 0x000A); lenr--; regy = (regx << 4);
								continue;
								}
							}
						}
			}
		if ( phase == 0 ) { 
			regy = regx << 4; 
			phase = 1; 
			}
		else	{ 
			*(bcdr++) = (EXABYTE) (regy | regx); 
			lenr--; 
			phase = 0;
			}
		}

	while (( pow > 0 ) && ( lenr > 0 )) {
		pow--;
		if ( phase == 0 ) { 
			if ( pow == 0 ) 
				regy = 0x00A0;
			else	regy = 0;
			phase = 1; 
			}
		else	{ 
			if ( pow == 0 ) 
				regy |= 0x000A;
			else	regy &= 0x00F0; 
			*(bcdr++) = (EXABYTE) regy; 
			lenr--; phase = 0;
			}
		}

	if (( phase == 1 ) && ( lenr > 0 )) { 
		*(bcdr++) = (EXABYTE) ( regy | 0x000F);  lenr--; 
		}
	while ( lenr > 0 ) {
		*(bcdr++) = (EXABYTE) 0x00FF;  lenr--; 
		}
	return(1);
}

#endif	/* _EXPOWER_C */
	/* ---------- */
