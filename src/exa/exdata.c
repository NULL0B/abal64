/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDATA - C				*/
/*		Date 	:	26.08.1988				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	Gestion des DATA d'un segment ou procedure			*/
/*----------------------------------------------------------------------*/
/*	Include file for EXCALC - C					*/
/*----------------------------------------------------------------------*/

/* 
 *	Chargement d'un variable avec une donnee statique (READ=0:VARPTR)
 *	-----------------------------------------------------------------
 *	Remarque : WORKPTR1 has already been initialised
 *	READ=0: VARPTR	Version B.A.L. Compatible a peu pret
 *	------------------------------ ---------------------
 */

EXAWORD getdata()
{
	EXAWORD	xlen,xtyp;
	EXAWORD	flg;
	EXABYTE	c;

	if ( datadex > datamax )
		{ err_val = ABAL_FINDATA; return(SOFTERROR); }
	if ( *datawork == IO_NUL ) 
		{ datawork++; xtyp = VARB_BCD; }
	else
		{ xtyp = VARB_STR; }

	xlen = (EXAWORD) *(datawork++);
	if (( xtyp == VARB_STR ) && (worktyp1 != VARB_STR))
		{ err_val = ABAL_BCDFORM; return(SOFTERROR); }
	c = IO_ESP;
	switch ( worktyp1 ) {
		case VARB_FOUR	:
		case VARB_INT8  : *(workptr1) = (EXABYTE) bcdtoi(datawork,xlen); 
			 	  datawork += xlen; break;
		case VARB_INT16 : balputw((EXAWORD) bcdtoi(datawork,xlen),workptr1);
			 	  datawork += xlen; break;
		case VARB_INT32 : balputl((EXAWORD) bcdtol(datawork,xlen),workptr1);
			 	  datawork += xlen; break;
		case VARB_INT64 : balput64((EXAWORD) bcdtoh(datawork,xlen),workptr1);
			 	  datawork += xlen; break;
		case VARB_BCD   : 
			flg = 0; err_val = ABAL_NUM2BIG; 
			while ((worklen1 > 0) && (xlen > 0)) {
				if ( flg == 0 ) {
					switch ( *datawork & 0x00F0 ) {
						case 0x00A0 :
						case 0x00F0 : flg = 1;
						}
					switch ( *datawork & 0x000F ) {
						case 0x000A :
						case 0x000F : flg = 1;
						}
					}
				*(workptr1++) = *(datawork++);
				worklen1--; xlen--;
				}
			while ( worklen1 > 0 ) { *(workptr1++) = (EXABYTE) 0x00FF; worklen1--; }
			if ( xlen == 0 ) 	{ datadex++; return(1);   }
			else			{ 
				if (( *datawork & 0x00F0 ) > 0x0090 ) { flg = 1; }
				datadex++;
			 	while ( xlen > 0 ) { datawork++; xlen--; } 
				return(flg);
				}	

		case VARB_STR   : while (( xlen > 0 ) && (worklen1 > 0)) {
				 	*(workptr1++) = *(datawork++);
					xlen--; worklen1--;
					}
			 	while ( worklen1 > 0 ) { *(workptr1++) = c; worklen1--; }
			 	while ( xlen > 0 ) { datawork++; xlen--; } 
		}
	datadex++;
	return(1);
}

EXAWORD	regdata( reg )
EXAWORD	reg;
{


	if ( datadex > datamax )   { err_val = ABAL_FINDATA; return(SOFTERROR); }
	if ( *datawork == IO_NUL ) { 
		freg [reg] = bcdtoi( ( datawork + 1 ) , ((EXAWORD) *(++datawork)));
		datadex++; datawork += (((EXAWORD) *datawork) + 1);
		return(1);
		}
	return( SOFTERROR );
}

/* 
 *	Repositionement de la pointeur de DATA	(RESTORE x)
 *	---------------------------------------------------
 *	Remarque : DATADEX has already been initialised
 */


EXAWORD	setdata(x)
EXAWORD	x;		/*	Data Position to be sought	*/
{
	EXAWORD	l,y;

	if ( x <= datamax ) {	
		datawork = (TcodeSegment + datapnt); y = 1;
		if ( x == 0 ) { x = 1; }
		while ( y < x ) {
			if ( *datawork == IO_NUL ) { datawork++; }
			l = (EXAWORD) *(datawork++);
			datawork += l; y++; }
		return(1); 
		}	
	else 	{  
		if (( datapnt == 0 ) || ( datapnt == MOINS_UN )) {
			err_val = 0; return(1);	  
			}
		else 	{	
			err_val = ABAL_TCODCODE; return(SOFTERROR); 
			}
		}
}

