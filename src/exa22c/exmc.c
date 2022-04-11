/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXMC - C				*/
/*		Version :	2.1e                      		*/ 
/*		Date 	:	11/08/98				*/
/*									*/
/*----------------------------------------------------------------------*/

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	11/08/98 : rubrctrl() : parcours de toute la table des handles pour rechercher
 *            une rubrique.
 * 17/08/00 : (#SP)long names support 
 * 16/10/00 : (#SP)switching off prefixes in short names mode for Criteria 3.6 or higher
 * 19/10/00 : (#SP)fixing a bug with FKEY with new Criteria.
 * 28/11/00 : (#SP)fixing a bug with LINK with new Criteria with many rubs in the list (testeur).
 * 13/12/00 : (#SP)correction of the error code on posit/count (with autolkey) for compatibility.
 * 28/12/00 : (#SP)fixing bug with BCD column and autoLKEY functionality.
 * 02/02/01 : (#OK)fixing bug with POSIT (error 88).
 * 08/02/01 : (#SP)fixing bug with CLINK in modext.
 * 26/02/01 : (#BG)A partir de Criteria 3.6, l'option U est supportée dans la syntaxe du nouveau Posit.
 * 15/06/01 : (#BG)Correction erreur 98 sur Count.
 * 26/09/03 : (#SP)Fixing a problem with bug in posit (error #98)
 * 22/03/04 : (#BG)Suppression de la correction SP du 26/09/03 qui tronquait le buffer du posit au premier 0 binaire et provoquait alors une erreur 78.
 * 22/03/04 : (#BG)Aurisation des options (U) et (S) à partir de Criteria 3.6d (accord LC) pour éviter une erreur 94 à tord.
 */

#include "exngf.h"	/* For Debug purposes */
#include "exctype.h"	/* Character set definitions */

#ifdef INTEL
#include "exprag0.h"
#endif

#include "anaquest.h"


/*	Part 1		:	Rubrique / Key Management
 *	------			-------------------------
 *
 *	The buffer declared in the ASSIGN statement ( fichbase.asptr )
 *	is used to store all rubrique information.
 *	The structure of this zone ( for a single key ) is as follows.
 *
 *	Offset			Usage
 *	-------------		-------------------------------------------
 *	0  -> 15		Rubrique name string (SPACE filled) MAX 16
 *	16 -> 17		Indirect word indicating key data zone length
 *	18			Rubrique type : bit fields as below
 *				Bit 0	: Unused
 *				Bit 1	: Unused
 *				Bit 2	: 1 = Numeric, 0 = Alphanumeric
 *				Bit 3	: Unused
 *				Bit 4-7 : Decimal place count for BCD FIX
 *						
 *	19			Internal status byte : bit fields as below
 *				Bit 0->6: Rubrique number (for REDEF RUB)
 *				Bit 7   : Redefined rubrique flag
 *					  1 = Redefinition, 0 = Normale 
 *
 *	Notes :	If the length is ZERO then the rubrique is only a reference
 *		for further redefinitions and must not be created by CKEY !!
 *
 *	The WORD 'mcext' contained in the file table indicates
 *
 *		bits 0 - 7 : Current KEY count in buffer
 *		bits 8 - 14: Current KEY being redefined
 *		Bit 15	   : Indicates redefinition of Rubrique underway.
 */

/*
 *	R U B S H I F T ( base_rub )
 *	----------------------------
 *	Implants a RUBRIQUE STRING at base_rub
 *
 */

EXAWORD	rubshift( BPTR base_rub , BPTR sptr , EXAWORD slen , EXABYTE bLongNames )
{
	EXAWORD	y;

	/* Tranfer string to KEY storage zone */
	/* ---------------------------------- */

	y = (bLongNames ? MAX_RUB_NAME_LEN_EXT : MAX_RUB_NAME_LEN_STD); 
	slen = lenuze(sptr,slen);

	while (( y > 0 ) && ( slen > 0 )) {
		*(base_rub++) = *(sptr++); y--; slen--;
		}

	/* Test for KEY too EXALONG */
	/* --------------------- */
	if ( slen != 0 ) { return(ABAL_BCD2LONG); }

	/* Fill KEY zone with spaces */
	/* ------------------------- */
	while ( y > 0 ) { *(base_rub++) = ' '; y--; }
	return(0);
}

/*
 *	A D D R U B R ( w , x , y , z )
 *	-------------------------------
 *	LFH	:	Logical file handle
 *
 *	Z	:	Internal status Flag ( 0x8000 or 0x0000 ) | KEY No.
 *	Y	:	Offset into Rubrique storage zone
 *	X	:	Data type (0->3 ABAL D.T. types)
 *	W	:	Current KEY count value
 *
 */

EXAWORD	addrubr( w , x , y , z )
EXAWORD	w,x,y,z;
{
	register BPTR	base_rub;
	EXAWORD	 lerr;

	if ( y + (bUserLongNames ? RUB_DESC_LEN_EXT:RUB_DESC_LEN_STD) > fidblen)	{ return(ABAL_BUF2SMALL); }
	base_rub = fidbuff + y;
	y = bUserLongNames ? MAX_RUB_NAME_LEN_EXT : MAX_RUB_NAME_LEN_STD;
	z &= 0xFF00;

	lerr = rubshift(base_rub,workptr1,worklen1,bUserLongNames);
	if ( lerr != 0 ) { return(lerr); }
	base_rub += (bUserLongNames ? MAX_RUB_NAME_LEN_EXT:MAX_RUB_NAME_LEN_STD);

	/* Store rubrique length into KEY zone */
	/* ----------------------------------- */
	TcodePmot16(base_rub,workval2); base_rub += sizeof(short int); /* not WORDSIZE BLEM : IJM */

	/* Establish the Data type EXABYTE */
	/* ---------------------------- */
	if ( x == 3 ) { x = 0; }
	else 	      { x = 4; }
	x |= (( workval3 & 0x000F ) << 4); /* Mix in decimals */
	*(base_rub++) = (EXABYTE) x;

	/* Establish KEY control EXABYTE */
	/* -------------------------- */
	*(base_rub++) = (EXABYTE) (z >> 8);

	/* Adjust ASSIGN table Control WORDSIZE ('mcext') */
	/* ------------------------------------------ */
	w++; fidmc = ( w | z );

	return(0);
}

/*
 *	R U B R D C L ( )
 *	-----------------
 *	Performs the ABAL / BAL : KEY=nlog function
 *
 */

EXAWORD	rubrdcl()
{
	EXAWORD	w,x,y,z;

	if (( fidperm & NGF_MC ) != NGF_MC ) { return(ABAL_OPNOTPOSS); }

	if ( fidblen < (bUserLongNames ? RUB_DESC_LEN_EXT : RUB_DESC_LEN_STD) )		 { return(ABAL_BUF2SMALL); }

	for ( x = 1; x <= 3; x++ ) {
		if ( fargset(x) == 0 ) { return(err_val); }
		}
	x = workval3; /* Put Rubrique type to one side */
	workval3 = 0;
	if ( x == 2 ) { (VOID) fargset(3); }

	/* ------------------------------------ */
	/* WSET(1) --> Nom du rubrique 		*/
	/* WSET(2) --> Longeur du Rubrique	*/
	/* X       --> Type de Rubrique		*/
	/* WSET(3) --> Nombre de decimaux (BCD) */
	/* ------------------------------------ */

	z = fidmc; w = ( z & 0x00FF ); 
	y = ( w * (bUserLongNames ? RUB_DESC_LEN_EXT : RUB_DESC_LEN_STD) );

	return( addrubr(w,x,y,z) );
}

/*
 *	R U B R D E F ( )
 *	-----------------
 *	Performs the ABAL / BAL : CKEY=nlog function
 *
 */


#undef	VERBALISE_CKEY
#ifdef	VERBALISE_CKEY
void	showrubrname(BPTR rptr,BPTR mptr,EXAWORD nb)
{
	int	iii;
	printf("%u : %s (",nb,mptr);
	for (iii=0; iii < 16; iii++)
		printf("%c",*(rptr+iii));
	printf(")\r\n");		
	return;
}
#endif

EXAWORD	rubrdef_STD()
{
	BPTR	base_rubr,mc_ptr;
	EXAWORD	rubdex,rubmax,mode,mc_len,y,mc_sup,hold,rublen,func,lerr;

	/* Check file ASSIGN for >= MC */
	/* --------------------------- */
	switch ( ( fidperm & NGF_TYP ) ) {
		case	NGF_MC   : func = 0x20bb; break;
#ifdef	ABALBD
		case	NGF_MCBD : 
		case	NGF_BD   : func = 0x21bb; break;
#endif
		default		 : return(ABAL_OPNOTPOSS);
		}

	/* Check file ASSIGN for write permission WR */
	/* ----------------------------------------- */
	if (( fidperm & NGF_R_W ) == 0 ) { return(ABAL_WRITPROT) ; }

	/* Establish Rubrique Control Variables */
	/* ------------------------------------ */
	rubmax = fidmc & 0x00FF; 	/* Number of Rubriques declared */
	rubdex = 0; 			/* Current Rubrique Index count */
	mc_sup = 0;			/* Offset into Buffer		*/

	/* Establish Buffer pointer */
	/* ------------------------ */
	if ( rubmax > 0 ) {	base_rubr = fidbuff; mode = 0; }

	/* While Current Count is Less than Maximum number */
	/* ----------------------------------------------- */
	while ( rubdex < rubmax ) {

		/* Collect Rubrique Length Value */
		/* ----------------------------- */
		rublen = TcodeWord16( (base_rubr + RUB_LEN_OFFSET_STD));

		/* If Length is not zero then Define */
		/* --------------------------------- */
		if ( rublen != 0 ) {

			/* Collect rubrique type Code Octet */
			/* -------------------------------- */
			mode = (EXAWORD) *(base_rubr + RUB_CTRL_OFFSET_STD);
			
			/* Seperate Redefinitions from Defines */
			/* ----------------------------------- */
			if (( mode & 0x0080 ) != 0 ) { 
			
				/* Re-definition of a Rubrique */
				/* --------------------------- */
				mc_ptr = (BPTR) (TcodeByteStack + worktop);

				mc_len = (RUB_DESC_LEN_STD+MAX_RUB_NAME_LEN_STD+1);
	
				/* Transfer Rubrique name to be redefined into descriptor */
				/* ------------------------------------------------------ */
				memcpy((BPTR) mc_ptr,(BPTR) (fidbuff + ((mode & 0x007F) * RUB_DESC_LEN_STD)), (USINT) MAX_RUB_NAME_LEN_STD);

				/* Establish length of new rubrique */
				/* -------------------------------- */
				TcodePmot16( (mc_ptr + MAX_RUB_NAME_LEN_STD) , rublen );

				/* Collect and position Rubrique Type Octet */
				/* ---------------------------------------- */
				y = (EXAWORD) *(base_rubr + RUB_TYPE_OFFSET_STD);
				*( mc_ptr + RUB_TYPE_OFFSET_STD) = (EXABYTE) (y & 0x0004) ;

				/* Transfer new rubrique Name into Descriptor */
				/* ------------------------------------------ */
				(VOID) memcpy( (mc_ptr + RUB_DESC_LEN_STD-1) , base_rubr , (USINT) MAX_RUB_NAME_LEN_STD);
#ifdef	VERBALISE_CKEY
				showrubrname(base_rubr,"FKEY",rubdex);
#endif
				/* Position the indent into Redefined rubrique */
				/* ------------------------------------------- */
				TcodePmot16( (mc_ptr + RUB_DESC_LEN_STD+MAX_RUB_NAME_LEN_STD-1) , mc_sup );

				/* Adjust Indent for next redefinitions */
				/* ------------------------------------ */
				mc_sup += rublen; mode = 1;

				}
			else	{	 
				/* Initial declaration of a Rubrique */
				/* --------------------------------- */
#ifdef	VERBALISE_CKEY
				showrubrname(base_rubr,"KEY",rubdex);
#endif
				mc_ptr = base_rubr; 
				mc_len = RUB_DESC_LEN_STD-1; 
				mode =0; mc_sup = 0; 
		  		}
		
			/* Collect and save rubrique control Byte */
			/* -------------------------------------- */
			hold = (EXAWORD) *(mc_ptr + RUB_TYPE_OFFSET_STD);

			/* Correct the Type Byte for Low level MC */
			/* -------------------------------------- */
			*(mc_ptr + RUB_TYPE_OFFSET_STD) = (EXABYTE) ( hold & 0x0004 );

			/* Interface with MC descriptor handler */
			/* ------------------------------------ */
			if ((lerr = (EXAWORD) mc_key(fidreel,mode,mc_ptr,mc_len,func)) == MOINS_UN ) {
				*(mc_ptr + RUB_TYPE_OFFSET_STD) = (EXABYTE) hold;
				return(errno);
			} 
			
			/* Restore original Control Byte */
			/* ----------------------------- */
			*(mc_ptr + RUB_TYPE_OFFSET_STD) = (EXABYTE) hold;

			/* Reset Mode Flag */
			/* --------------- */
			mode = 0;
		}

		/* Next Rubrique */
		/* ------------- */
		rubdex++; base_rubr += RUB_DESC_LEN_STD;

		}	

	/* All went well No Error */
	/* ---------------------- */
	return(0);
}


EXAWORD	rubrdef_EXT()
{
	BPTR	base_rubr,mc_ptr;
	EXAWORD	rubdex,rubmax,mode,mc_len,y,mc_sup,hold,rublen,func,lerr;

	/* Check file ASSIGN for >= MC */
	/* --------------------------- */
	switch ( ( fidperm & NGF_TYP ) ) {
		case	NGF_MC   : func = 0x20bb; break;
#ifdef	ABALBD
		case	NGF_MCBD : 
		case	NGF_BD   : func = 0x21bb; break;
#endif
		default		 : return(ABAL_OPNOTPOSS);
		}

	/* Check file ASSIGN for write permission WR */
	/* ----------------------------------------- */
	if (( fidperm & NGF_R_W ) == 0 ) { return(ABAL_WRITPROT) ; }

	/* Establish Rubrique Control Variables */
	/* ------------------------------------ */
	rubmax = fidmc & 0x00FF; 	/* Number of Rubriques declared */
	rubdex = 0; 			/* Current Rubrique Index count */
	mc_sup = 0;			/* Offset into Buffer		*/

	/* Establish Buffer pointer */
	/* ------------------------ */
	if ( rubmax > 0 ) {	base_rubr = fidbuff; mode = 0; }

	/* While Current Count is Less than Maximum number */
	/* ----------------------------------------------- */
	while ( rubdex < rubmax ) {

		/* Collect Rubrique Length Value */
		/* ----------------------------- */
		rublen = TcodeWord16( (base_rubr + RUB_LEN_OFFSET_EXT) );

		/* If Length is not zero then Define */
		/* --------------------------------- */
		if ( rublen != 0 ) {

			/* Collect rubrique type Code Octet */
			/* -------------------------------- */
			mode = (EXAWORD) *(base_rubr + RUB_CTRL_OFFSET_EXT);
			
			/* Seperate Redefinitions from Defines */
			/* ----------------------------------- */
			if (( mode & 0x0080 ) != 0 ) { 
			
				/* Re-definition of a Rubrique */
				/* --------------------------- */
				mc_ptr = (BPTR) (TcodeByteStack + worktop);

				mc_len = (RUB_DESC_LEN_EXT+MAX_RUB_NAME_LEN_EXT+1);
	
				/* Transfer Rubrique name to be redefined into descriptor */
				/* ------------------------------------------------------ */
				memcpy((BPTR) mc_ptr,(BPTR) (fidbuff + ((mode & 0x007F) * RUB_DESC_LEN_EXT)), (USINT) MAX_RUB_NAME_LEN_EXT);

				/* Establish length of new rubrique */
				/* -------------------------------- */
				TcodePmot16( (mc_ptr + MAX_RUB_NAME_LEN_EXT) , rublen );

				/* Collect and position Rubrique Type Octet */
				/* ---------------------------------------- */
				y = (EXAWORD) *(base_rubr + RUB_TYPE_OFFSET_EXT);
				*( mc_ptr + RUB_TYPE_OFFSET_EXT) = (EXABYTE) (y & 0x0004) ;

				/* Transfer new rubrique Name into Descriptor */
				/* ------------------------------------------ */
				(VOID) memcpy( (mc_ptr + RUB_DESC_LEN_EXT-1) , base_rubr , (USINT) MAX_RUB_NAME_LEN_EXT);
		
				/* Position the indent into Redefined rubrique */
				/* ------------------------------------------- */
				TcodePmot16( (mc_ptr + RUB_DESC_LEN_EXT+MAX_RUB_NAME_LEN_EXT-1) , mc_sup );

				/* Adjust Indent for next redefinitions */
				/* ------------------------------------ */
				mc_sup += rublen; mode = 1;

				}
			else	{ 
				/* Initial declaration of a Rubrique */
				/* --------------------------------- */
				mc_ptr = base_rubr; 
				mc_len = RUB_DESC_LEN_EXT-1; 
				mode =0; mc_sup = 0; 
		  		}
		
			/* Collect and save rubrique control Byte */
			/* -------------------------------------- */
			hold = (EXAWORD) *(mc_ptr + RUB_TYPE_OFFSET_EXT);

			/* Correct the Type Byte for Low level MC */
			/* -------------------------------------- */
			*(mc_ptr + RUB_TYPE_OFFSET_EXT) = (EXABYTE) ( hold & 0x0004 );

			/* Interface with MC descriptor handler */
			/* ------------------------------------ */
			if ((lerr = (EXAWORD) mc_key(fidreel,mode,mc_ptr,mc_len,func)) == MOINS_UN ) {
				*(mc_ptr + RUB_TYPE_OFFSET_EXT) = (EXABYTE) hold;
				return(errno);
				} 
			
			/* Restore original Control Byte */
			/* ----------------------------- */
			*(mc_ptr + RUB_TYPE_OFFSET_EXT) = (EXABYTE) hold;

			/* Reset Mode Flag */
			/* --------------- */
			mode = 0;
			}

		/* Next Rubrique */
		/* ------------- */
		rubdex++; base_rubr += RUB_DESC_LEN_EXT;

		}	

	/* All went well No Error */
	/* ---------------------- */
	return(0);
}

EXAWORD	rubrdef_new()
{
BPTR	base_rubr,mc_ptr; 
EXAWORD	rubdex,rubmax,mode,mc_len,y,mc_sup,hold,rublen,func,lerr;

	/* Check file ASSIGN for >= MC */
	/* --------------------------- */
    
	switch ( ( fidperm & NGF_TYP ) ) {
		case	NGF_MC: 
			func = 0x20bb; 
			break;

#ifdef	ABALBD

		case	NGF_MCBD: 
		case	NGF_BD: 
			func = 0x21bb; 
			break;
#endif

		default:
			return(ABAL_OPNOTPOSS);
		}

	/* Check file ASSIGN for write permission WR */
	/* ----------------------------------------- */
	if (( fidperm & NGF_R_W ) == 0 ) { return(ABAL_WRITPROT) ; }

	/* Establish Rubrique Control Variables */
	/* ------------------------------------ */
	rubmax = fidmc & 0x00FF; 	/* Number of Rubriques declared */
	rubdex = 0; 			/* Current Rubrique Index count */
	mc_sup = 0;			/* Offset into Buffer		*/

	/* Establish Buffer pointer */
	/* ------------------------ */
	if ( rubmax > 0 ) {	base_rubr = fidbuff; mode = 0; }

	/* While Current Count is Less than Maximum number */
	/* ----------------------------------------------- */
	while ( rubdex < rubmax ) {

		/* Collect Rubrique Length Value */
		/* ----------------------------- */
		rublen = TcodeWord16( (base_rubr + RUBLENG) ); 

		/* If Length is not zero then Define */
		/* --------------------------------- */
		if ( rublen != 0 ) {

			/* Collect rubrique type Code Octet */
			/* -------------------------------- */
			mode = (EXAWORD) *(base_rubr + RUBSTAT); 
			
			/* Seperate Redefinitions from Defines */
			/* ----------------------------------- */
			if (( mode & 0x0080 ) != 0 ) { 
			
				/* Re-definition of a Rubrique */
				/* --------------------------- */
				mc_ptr = (BPTR) (TcodeByteStack + worktop);
				mc_len = 37;  
		
				/* Transfer Rubrique name to be redefined into descriptor */
				/* ------------------------------------------------------ */
				(VOID) memcpy((BPTR) mc_ptr,(BPTR) (fidbuff + ((mode & 0x007F) * 20)), (USINT) 16); 

				/* Establish length of new rubrique */
				/* -------------------------------- */
				TcodePmot16( (mc_ptr + 16) , rublen );  

				/* Collect and position Rubrique Type Octet */
				/* ---------------------------------------- */
				y = (EXAWORD) *(base_rubr + RUBTYPE);
				*( mc_ptr + 18 ) = (EXABYTE) (y & 0x0004) ;

				/* Transfer new rubrique Name into Descriptor */
				/* ------------------------------------------ */
				(VOID) memcpy( (mc_ptr + 19) , base_rubr , (USINT) 16);
		
				/* Position the indent into Redefined rubrique */
				/* ------------------------------------------- */
				TcodePmot16( (mc_ptr + 35) , mc_sup );

				/* Adjust Indent for next redefinitions */
				/* ------------------------------------ */
				mc_sup += rublen; mode = 1;

				}

			else	{ 
				/* Initial declaration of a Rubrique */
				/* --------------------------------- */
				mc_ptr = base_rubr; mc_len = 19; 
				mode =0; mc_sup = 0; 
				}
		
			/* Collect and save rubrique control Byte */
			/* -------------------------------------- */
			hold = (EXAWORD) *(mc_ptr + RUBTYPE);

			/* Correct the Type Byte for Low level MC */
			/* -------------------------------------- */
			*(mc_ptr + RUBTYPE) = (EXABYTE) ( hold & 0x0004 );

			/* Interface with MC descriptor handler */
			/* ------------------------------------ */
			if ((lerr = (EXAWORD) mc_key(fidreel,mode,mc_ptr,mc_len,func)) == MOINS_UN ) {
				*(mc_ptr + RUBTYPE) = (EXABYTE) hold;
				return(errno);
				} 
			
			/* Restore original Control Byte */
			/* ----------------------------- */
			*(mc_ptr + RUBTYPE) = (EXABYTE) hold;

			/* Reset Mode Flag */
			/* --------------- */
			mode = 0;
			}

		/* Next Rubrique */
		/* ------------- */
		rubdex++; base_rubr += 20;

		}	

	/* All went well No Error */
	/* ---------------------- */
	return(0);
}

/*
 *	R U B R D E F ( )
 *	-----------------
 *	Performs the ABAL / BAL : CKEY=nlog function
 *
 */

EXAWORD	rubrdef()
{
  if (bUserLongNames) return rubrdef_EXT();
  else return rubrdef_STD();
}

#ifdef OLD_VERSION

EXAWORD	rubrdef()
{
	BPTR	base_rubr,mc_ptr;
	EXAWORD	rubdex,rubmax,mode,mc_len,y,mc_sup,hold,rublen,func,lerr;

	/* Check file ASSIGN for >= MC */
	/* --------------------------- */
	switch ( ( fidperm & NGF_TYP ) ) {
		case	NGF_MC   : func = 0x20bb; break;
#ifdef	ABALBD
		case	NGF_MCBD : 
		case	NGF_BD   : func = 0x21bb; break;
#endif
		default		 : return(ABAL_OPNOTPOSS);
		}

	/* Check file ASSIGN for write permission WR */
	/* ----------------------------------------- */
	if (( fidperm & NGF_R_W ) == 0 ) { return(ABAL_WRITPROT) ; }

	/* Establish Rubrique Control Variables */
	/* ------------------------------------ */
	rubmax = fidmc & 0x00FF; 	/* Number of Rubriques declared */
	rubdex = 0; 			/* Current Rubrique Index count */
	mc_sup = 0;			/* Offset into Buffer		*/

	/* Establish Buffer pointer */
	/* ------------------------ */
	if ( rubmax > 0 ) {	base_rubr = fidbuff; mode = 0; }

	/* While Current Count is Less than Maximum number */
	/* ----------------------------------------------- */
	while ( rubdex < rubmax ) {

		/* Collect Rubrique Length Value */
		/* ----------------------------- */
		rublen = TcodeWord16( (base_rubr + RUBLENG) ); // Commented by #SP

		/* If Length is not zero then Define */
		/* --------------------------------- */
		if ( rublen != 0 ) {

			/* Collect rubrique type Code Octet */
			/* -------------------------------- */
			mode = (EXAWORD) *(base_rubr + RUBSTAT); // Commented by #SP
			
			/* Seperate Redefinitions from Defines */
			/* ----------------------------------- */
			if (( mode & 0x0080 ) != 0 ) { 
			
				/* Re-definition of a Rubrique */
				/* --------------------------- */
				mc_ptr = (BPTR) (TcodeByteStack + worktop);


				mc_len = 37;  
		
				/* Transfer Rubrique name to be redefined into descriptor */
				/* ------------------------------------------------------ */
				(VOID) memcpy((BPTR) mc_ptr,(BPTR) (fidbuff + ((mode & 0x007F) * 20)), (USINT) 16); 

				/* Establish length of new rubrique */
				/* -------------------------------- */
				TcodePmot16( (mc_ptr + 16) , rublen );  

				/* Collect and position Rubrique Type Octet */
				/* ---------------------------------------- */
				y = (EXAWORD) *(base_rubr + RUBTYPE);
				*( mc_ptr + 18 ) = (EXABYTE) (y & 0x0004) ;

				/* Transfer new rubrique Name into Descriptor */
				/* ------------------------------------------ */
				(VOID) memcpy( (mc_ptr + 19) , base_rubr , (USINT) 16);
		
				/* Position the indent into Redefined rubrique */
				/* ------------------------------------------- */
				TcodePmot16( (mc_ptr + 35) , mc_sup );


				/* Adjust Indent for next redefinitions */
				/* ------------------------------------ */
				mc_sup += rublen; mode = 1;

				}

			else	{ 
				/* Initial declaration of a Rubrique */
				/* --------------------------------- */
				mc_ptr = base_rubr; mc_len = 19; 
				mode =0; mc_sup = 0; 
				}
		
			/* Collect and save rubrique control Byte */
			/* -------------------------------------- */
			hold = (EXAWORD) *(mc_ptr + RUBTYPE);

			/* Correct the Type Byte for Low level MC */
			/* -------------------------------------- */
			*(mc_ptr + RUBTYPE) = (EXABYTE) ( hold & 0x0004 );

			/* Interface with MC descriptor handler */
			/* ------------------------------------ */
			if ((lerr = (EXAWORD) mc_key(fidreel,mode,mc_ptr,mc_len,func)) == MOINS_UN ) {
				*(mc_ptr + RUBTYPE) = (EXABYTE) hold;
				return(errno);
				} 
			
			/* Restore original Control Byte */
			/* ----------------------------- */
			*(mc_ptr + RUBTYPE) = (EXABYTE) hold;

			/* Reset Mode Flag */
			/* --------------- */
			mode = 0;
			}

		/* Next Rubrique */
		/* ------------- */
		rubdex++; base_rubr += 20;

		}	

	/* All went well No Error */
	/* ---------------------- */
	return(0);

}
#endif	/* OLDVERSION */

/*
 *	R u b r C o m p a r e ( a , al , b , bl )
 *	-----------------------------------------
 *	General purpose length controlled rubrique/key compare function
 *
 *	Returns : MOINS_UN : Compare fail
 *		  ZERO     : Compare OK
 *
 */

EXAWORD	RubrCompare( a , al , b , bl )
BPTR	a;
EXAWORD	al;
BPTR	b;
EXAWORD	bl;
{
	/* Repeat while neither length is ZERO */
	/* ----------------------------------- */
	while ((al > 0) && (bl > 0)) {

		/* If current characters differ : FAIL */
		/* ----------------------------------- */
		if ( *(a++) != *(b++) ) { return(MOINS_UN); }

		/* Decrement length controllers */
		/* ---------------------------- */
		al--; bl--;
		}

	/* Ensure Strings Contain only white space */
	/* --------------------------------------- */
	while (al > 0) {
		if ( *(a++) != ' ') { return(MOINS_UN); }
		al--;
		}

	while (bl > 0) {
		if ( *(b++) != ' ') { return(MOINS_UN); }
		bl--;
		}

	/* Strings are Equal */
	/* ----------------- */
	return( 0 );
}
 

/*
 *	R U B R S E E K ( base_rubr , x , workptr , worklen )
 *	-----------------------------------------------------
 *	Recherche d'un rubrique dans le tampon d'ASSIGN
 *	Retour 	: MOINS_UN	Rubrique non-trouvee
 *		  	Other values indicate rubrique ID number
 */

EXAWORD	rubrseek( base_rubr, x , workptr , worklen )

			/* ---------------------------- */
BPTR	base_rubr;	/* KEY storage zone base 	*/
EXAWORD	x;		/* Number of KEYS		*/
BPTR	workptr;	/* KEY name requested		*/
EXAWORD	worklen;	/* Length of KEY name requested	*/
			/* ---------------------------- */

{
	EXAWORD	z;

	z = 0;

	/* Scan KEY storage buffer for 'X' keys */
	/* ------------------------------------ */
	while ( z < x ) {

		/* Compare this key with requested key name */
		/* ---------------------------------------- */
		if ( RubrCompare(base_rubr,(bUserLongNames ? MAX_RUB_NAME_LEN_EXT:MAX_RUB_NAME_LEN_STD),workptr,worklen) == 0 ) {

			/* Return Table Index */
			/* ------------------ */
			return( z );

			}

		/* Next key entry */
		/* -------------- */
		base_rubr += (bUserLongNames ? RUB_DESC_LEN_EXT:RUB_DESC_LEN_STD); z++;
		}

	/* KEY Name not found in table */
	/* --------------------------- */
	return(MOINS_UN);

}

/*
 *	R U B R C T R L ( workptr , worklen )
 *	-------------------------------------
 *	Recherche d'un Rubrique Pour les questions posit et count
 *	WORKPTR points to the rubrique string to find (length WORKLEN)
 *
 */

EXAWORD	rubrctrl( workptr , worklen )
BPTR	workptr;
EXAWORD	worklen;
{
	EXAWORD	x,y;
	if ((fidperm & NGF_TYP ) != NGF_BD) { return(rubrseek(rubr_base,rubr_max,workptr,worklen)); }

	for ( x = 1; x < diezfic; x++) {
		if ( (EXAWORD) *(fidbase + x) != 0 ) {
			rubr_base = (*(AssignTable + x)).asptr;
			rubr_max = ( (*(AssignTable + x)).mcext & 0x00FF);
			if ((y=rubrseek(rubr_base,rubr_max,workptr,worklen)) != MOINS_UN) {
				 return(y); 
				}
			}
		}
	return(MOINS_UN);
}


/*
 *	R U B R F L D ()
 *	---------------------
 *	Performs the ABAL / BAL : FKEY=nlog function
 *
 */

EXAWORD	rubrfld()
{
	BPTR	base_rubr;
	EXAWORD	z,x;
	
	if (( fidperm & NGF_MC  ) != NGF_MC ) 					{ return(ABAL_OPNOTPOSS); }
	if ( fidblen < (bUserLongNames ? RUB_DESC_LEN_EXT:RUB_DESC_LEN_STD) )	{ return(ABAL_BUF2SMALL); }
	x = fargset(1);
	if ( x == 0 ) {	fidmc &= 0x00FF; return(0);}

	/* Find if Rubrique exists */
	base_rubr = fidbuff; x =  fidmc & 0x00FF;

	if ( (z = rubrseek(base_rubr,x,workptr1,worklen1)) != MOINS_UN) {
			z |= 0x0080; x |= ( z << 8 );
			fidmc = x; return(0);
			}

	/* Reset Length and decimal place count */
	/* ------------------------------------ */
	workval2 = 0; workval3 = 0;
	return( addrubr(x,0,(x*(bUserLongNames ? RUB_DESC_LEN_EXT:RUB_DESC_LEN_STD)), ((x << 8) | 0x8000) ) );
}

/*
 *	R U B R R A Z ()
 *	---------------------
 *	Performs the ABAL / BAL : RKEY=nlog function
 *
 *	Resets the Key buffer zone for the MC / MCDB file @ LFH 
 */

EXAWORD	rubrraz( )
{
	EXAWORD	x;

	if (( fidperm & NGF_TYP ) == NGF_BD ) {
		/* We must now liberate All FILE Key fields .... */
		/* --------------------------------------------- */
		for ( x = 1; x < diezfic ; x++ ) {
			if ( (*(AssignTable +x)).permf & 0x0100 ) { /* File OK */
				if ( ( (*(AssignTable +x)).permf & NGF_TYP) == NGF_MCBD) {
					if ( (*(AssignTable +x)).dblog == lfh) {
						(*(AssignTable +x)).mcext = 0;
						}
					}
				}
			}
		fidmc = 0;
		return(0);
		}	
	if (( fidperm & NGF_MC  ) != NGF_MC ) { return(ABAL_OPNOTPOSS); }
	fidmc = 0;
	return(0);
}

/*
 *	R U B R N O M ( )
 *	-----------------
 *	Performs the ABAL / BAL : NKEY=nlog function
 *
 *	Renames the KEY specified by by WSET(1) as that specified by WSET(2)
 *
 */

EXAWORD	rubrnom()
{
	EXAWORD	x,lerr,ecart,func;
	EXAWORD  rub_desc_ln,name_offs,name_len,ctrl_ofs;

	if (bUserLongNames){
		rub_desc_ln=RUB_DESC_LEN_EXT;
		name_offs=(RUB_DESC_LEN_EXT+MAX_RUB_NAME_LEN_EXT-1);
		name_len=MAX_RUB_NAME_LEN_EXT;
		ctrl_ofs=RUB_CTRL_OFFSET_EXT;
		}
	else	{
		rub_desc_ln=RUB_DESC_LEN_STD;
		name_offs=(RUB_DESC_LEN_STD+MAX_RUB_NAME_LEN_STD-1);
		name_len=MAX_RUB_NAME_LEN_STD;
		ctrl_ofs=RUB_CTRL_OFFSET_STD;
		}

	/* Ensure file ASSIGN is of correct type >= MC */
	/* ------------------------------------------- */
	switch ( ( fidperm & NGF_TYP ) ) {
		case	NGF_MC   : func = 0x20bb; break;
#ifdef	ABALBD
		case	NGF_MCBD : 
		case	NGF_BD   : func = 0x21bb; break;
#endif
		default		 : return(ABAL_OPNOTPOSS);
		}

	/* Check for WR permission */
	/* ----------------------- */
	if (( fidperm & NGF_R_W ) == 0      ) 	{ return(ABAL_WRITPROT) ; }

	/* Check Rubrique WorkZone Length */
	/* ------------------------------ */
	if ( fidblen < rub_desc_ln )		 	{ return(ABAL_BUF2SMALL); }

	/* Check for Temporary zone overflow */
	/* --------------------------------- */
	if (( worktop + name_offs ) >= dieztmp )	{ return(ABAL_MEMORY);	  }

	/* Calculate and protect Descriptor Pointer */
	/* ---------------------------------------- */
	workptr3 = (BPTR) (TcodeByteStack + worktop);
	worktop += name_offs; ecart = 0; lerr = 0;

	/* Ensure these 3 octets are Zero */
	/* ------------------------------ */
	for ( x = name_len; x < ctrl_ofs; x++) { *(workptr3 + x) = (EXABYTE) 0; }

	/* Collect the 2 arguaments : OldName , NewName */
	/* -------------------------------------------- */
	for ( x = 1; x <=2 ; x++ ) {
		if (  fargset(1) == 0 ) { return(err_val); }
		if ((lerr = rubshift((workptr3 + ecart),workptr1,worklen1,bUserLongNames)) != 0) {
			return(lerr);
			}
		ecart += ctrl_ofs;
		}	

	/* Perform the low-level MC operation */
	/* ---------------------------------- */
	if ((lerr = (EXAWORD) mc_key(fidreel,8,workptr3,name_offs,func)) == MOINS_UN ) { 

		/* Return Low-Level Error */
		/* ---------------------- */
		return(errno);
		}
	/* No Error So OK */
	/* -------------- */
	return(0);
}


/*
 *	R U B R L S T ( func )
 *	----------------------
 *	Performs Dictionary listing functions wrt to 'func'
 *	LKEY, LFILE, LLINK, LJOIN
 */

EXAWORD	rubrlst( func , mode)
EXAWORD	func,mode;
{
EXAWORD	lerr;

	/* Ensure file ASSIGN is of correct type >= MC */
	/* ------------------------------------------- */
	switch ( ( fidperm & NGF_TYP ) ) {
		case	NGF_MC   : break;
#ifdef	ABALBD
		case	NGF_MCBD : 
		case	NGF_BD   : func |= 0x0100; break;
#endif
		default		 : return(ABAL_OPNOTPOSS);
		}

	/* Collect Option Arguament (F) or ( ) */
	/* ----------------------------------- */
	if (fargset(2) == 0 ) { return(err_val); }

	/* Check for and establish Option (F)  */
	/* ----------------------------------  */
	if ( worktyp2 == 3 ) { 
		if (toupper(*workptr2) == 'F' ) mode |= 0x0020; 
  		}

	/* Establish Result buffer pointer     */
	/* -------------------------------     */
	if (fargset(0) == 0 ) { return(err_val); }

	/* Establish Result Length	       */
	/* -----------------------	       */
	if (fargset(3) != 0 ) { worklen1 = (EXAWORD) workval3; }

	/* Perform Low-Level MC Operation      */
	/* ------------------------------      */
	if ( (lerr = (EXAWORD) mc_key(fidreel,mode,workptr1,worklen1,func)) == MOINS_UN ) {

		/* Return Low-Level Error */
		/* ---------------------- */
		return(errno);
		}

	/* Else all went well OK */
	/* --------------------- */
	return(0);	
}

EXAWORD	prepare_jointure( sptr, slen, stype, rptr )
BPTR	sptr;
EXAWORD	slen;
EXAWORD	stype;
BPTR	rptr;
{
	BPTR	mptr;
	EXAWORD	newlen;

	/* Ensure Clean Descriptor */
	/* ----------------------- */
	(VOID) memset((BPTR) rptr,' ',(USINT) 17);
	*rptr = 0; *(rptr+1) = 0;

	if (( stype == 3 )
	&&  ( lenuze(sptr,slen) > 0 )) {
		memcpy((BPTR) ( mptr = (TcodeByteStack + worktop)) , (BPTR) sptr , (USINT) slen );
		*(mptr + slen) = 0;
		worktop += (slen+1);
		if ((newlen = check_implicite_join_file( mptr )) != 0) {
			slen = newlen;
			mptr = (BPTR) askbuf;
			}
		if ( anajoin((BPTR) mptr ,(BPTR) rptr, slen) == 0 ) {
			err_val = EXER_JOIN; 
			return(SOFTERROR); 
			}
		}
	return( GOODRESULT );
}

/*
 *	S E T J O I N ( func )
 *	----------------------
 *	Establishes the contents of the 'Tampon Jointure'
 *	For Data base access methods
 *
 */

EXAWORD	setjoin( func )
EXAWORD	func;
{
	/* Collect Arguament 'Jointure'	*/
	/* ---------------------------- */
	if ( fargset(1) == SOFTERROR ) 
		return(SOFTERROR);

	/* Control File Access Type MC,MCBD,BD */
	/* ----------------------------------- */
	switch ( ( fidperm & NGF_TYP ) ) {
		case	NGF_MC   : break;
#ifdef ABALBD
		case	NGF_MCBD : func |= 0x0100; break;
		case	NGF_BD   : 
			func |= 0x0100; 
			if ( prepare_jointure( workptr1, worklen1, worktyp1, (BPTR) joinwork ) == SOFTERROR )
				return( SOFTERROR );
			sicico |= ONSEM_JOIN; 
			break;
#endif
		default		 : 
			err_val = ABAL_OPNOTPOSS; 
			return(0);
		}
	return(func);
}

/*
 *	L I N K W O R K (func)
 *	-----------------------------
 *	Declaration des liens MC + MCBD
 *	Creation ou mise a jour des liens MC + MCBD
 *
 */

EXAWORD	linkwork_longnames( func , bmode)
EXAWORD	func,bmode;
{
	EXAWORD	rl,ri,tl,mode;
	EXABYTE	c;
	EXAWORD	jl;
	EXAWORD	calcmaxcrit=MAXCRIT;
	BPTR  rub_start;
	EXAWORD  maxUserTabName=bUserLongNames ? MAX_TABLE_NAME_LEN_EXT:MAX_TABLE_NAME_LEN_STD;
	EXAWORD  maxUserColName=bUserLongNames ? MAX_RUB_NAME_LEN_EXT:MAX_RUB_NAME_LEN_STD;

	/* Collect Dummy or Real Jointure Arguament */
	/* ---------------------------------------- */
	jl = 0;
	if (( func = setjoin(func)) == MOINS_UN ) { return(err_val); }
	if ( sicico & ONSEM_JOIN ) { jl = 15; sicico &= OFSEM_JOIN; }

	/* Collect Optional Arguament 'Liste des Rubriques' */
	/* ------------------------------------------------ */
	if ( fargset(1) == 0 ) { 
		workptr2 = (BPTR) 0; worklen2 = 0; 
		mode = 0; jl = 0; 
		}
	else	{
		/* Check for Parameter type Correct */
		/* -------------------------------- */
		if ( worktyp1 != 3 ) { return(20); }

		/* Check for an Empty Link String   */
		/* ------------------------------   */
		if ( lenuze(workptr1,worklen1) == 0 ) {
			workptr2 = (BPTR) 0; worklen2 = 0; 
			mode = 0; jl = 0; 
			}
		else	{
			mode = bmode;

			/* Calculate and allocate Descriptor Zone @ WORKPTR2 */
			/* ------------------------------------------------- */
			for (calcmaxcrit=MAXCRIT; calcmaxcrit >= OLDMAXCRIT; calcmaxcrit-- ) {
				tl = (calcmaxcrit * (MAX_RUB_NAME_LEN_EXT+MAX_TABLE_NAME_LEN_EXT+1)) + 1;
				if ((workptr2 = (BPTR) allocate((USINT) (tl+jl))) != (BPTR) 0)
					break;
				}
			if ( workptr2 == (BPTR) 0 )
				return(EXER_MEMFULL);
			ri=2;
			rub_start=(workptr2+1);
			*rub_start='?'; 
			rl=0;
			worklen1 = lenuze(workptr1,worklen1);
		  	*workptr2 = 0;  
	
			/* Analyse arguament 'Liste des Rubriques' and fill descriptor */
			/* ----------------------------------------------------------- */
			while (( worklen1 > 0 ) && ( ri < tl)) {
        			if (bUserLongNames) {
					if ( *workptr1 == '.' ) {
        					if (rl>maxUserTabName || *rub_start!='?'){
							liberate(workptr2);
							return(EXER_RUBTROP);
							}
        					for (;rl<MAX_TABLE_NAME_LEN_EXT && ri<tl;ri++,rl++) { 
							*(workptr2+ri)=' ';
          						}
						/* mark that we we have a table name as a prefix */
						/* but the name of the column is not filled yet. */
						/* --------------------------------------------- */
						*rub_start='!'; 
						worklen1--; workptr1++; 
						rl=0; continue;
						}
					}

				if ( *workptr1 == ',' ) {
          				for (;rl<MAX_RUB_NAME_LEN_EXT && ri<tl;ri++,rl++){
						*(workptr2 + ri) = ' ';
						} 
					*rub_start=*rub_start=='?' ? 0:1;
					worklen1--; workptr1++; 
					/* rubrique counter */
					/* ---------------- */
					(*workptr2)++; 
					rl = 0;
          				rub_start=(workptr2+ri); ri++;
          				*rub_start='?';
					continue;
					}

				if (rl>maxUserColName) {
					if ((*workptr1 == ' ') || (*workptr1 == ',')) { 
						break; 
						}
					else	{
						liberate(workptr2);
					  	return(EXER_RUBTROP);
          					}
        				}
				else	{
					*(workptr2 + ri) = *(workptr1++); 
					ri++; rl++;
					worklen1--; continue; 
					}
				}
      			if (!rl && *rub_start=='!'){
			  	liberate(workptr2);
			  	return(EXER_RUBTROP);
      				}


			if (rl<=maxUserColName && rl>0 && (*rub_start=='?' || *rub_start=='!')){
			(*workptr2)++; 
			*rub_start=*rub_start=='?' ? 0:1;
			}
		if (rl>0) {
			for (;rl<MAX_RUB_NAME_LEN_EXT && ri<tl;ri++,rl++){
				*(workptr2 + ri) = ' ';
			  	} 
      			}
		worklen2 = ri;
		}
	}
  /* Collect 2nd Optional arguament 'Options du Lien' */
  /* ------------------------------------------------ */
  if ( fargset(1) != 0 ) {
	  if ( worktyp1 == 3 ) {
		  c = toupper(*workptr1);
		  /* Test for 'Ensemble Minimum' */
		  /* --------------------------- */
		  if ( c == 'A' ) { mode |= 0x0004; }

		  /* Test for 'Lien a suprimer' */
		  /* -------------------------- */
		  if ( c == 'D' ) { mode |= 0x0008; }
		}
	}
  errno = 0;

  #ifdef ABALBD

  /* Perform 'Transfer du Jointure' For Database Access's */
  /* ---------------------------------------------------- */
  if ( jl > 0 ) { 
	  (VOID) memcpy((workptr2+worklen2),(BPTR) (joinwork+2),(USINT) jl); 
	}

  #endif

  /* Perform the Actual MC/MCBD/BD function : 'LINK' or 'CLINK' */
  /* ---------------------------------------------------------- */
  ri = (EXAWORD) mc_key(fidreel,mode,workptr2,worklen2+jl,func);

  /* Liberate pointer if needed */
  /* -------------------------- */	
  if ( workptr2 != (BPTR) 0 ) 
	  liberate(workptr2);

  /* Return Error Status */
  /* ------------------- */
  if ( ri == MOINS_UN ) 
	  return(errno);
  else	return(0);
}
// #SP: 17/08/2000 (end)____________________________________________________


EXAWORD	linkwork( func , bmode)
EXAWORD	func,bmode;
{
	EXAWORD	rl,ri,tl,mode;
	EXABYTE	c;
	EXAWORD	jl;
	EXAWORD	calcmaxcrit=MAXCRIT;

	/* bSystemLongNames ??? IJM */
	if (bSystemLongNames) return linkwork_longnames(func,bmode);

  /* Collect Dummy or Real Jointure Arguament */
  /* ---------------------------------------- */
  jl = 0;
  if (( func = setjoin(func)) == MOINS_UN ) { return(err_val); }
  if ( sicico & ONSEM_JOIN ) { jl = 15; sicico &= OFSEM_JOIN; }

  /* Collect Optional Arguament 'Liste des Rubriques' */
  /* ------------------------------------------------ */
  if ( fargset(1) == 0 ) { 
	  workptr2 = (BPTR) 0; worklen2 = 0; 
	  mode = 0; jl = 0; 
	}
  else 	{
	  /* Check for Parameter type Correct */
	  /* -------------------------------- */
	  if ( worktyp1 != 3 ) { return(20); }

	  /* Check for an Empty Link String   */
	  /* ------------------------------   */
	  if ( lenuze(workptr1,worklen1) == 0 ) {
		  workptr2 = (BPTR) 0; worklen2 = 0; 
		  mode = 0; jl = 0; 
		}
	else	{
		  mode = bmode;

		  /* Calculate and allocate Descriptor Zone @ WORKPTR2 */
		  /* ------------------------------------------------- */
		  for (calcmaxcrit=MAXCRIT; calcmaxcrit >= OLDMAXCRIT; calcmaxcrit-- ) {
        		tl = (calcmaxcrit * MAX_RUB_NAME_LEN_STD) + 1;

			if ((workptr2 = (BPTR) allocate((USINT) (tl+jl))) != (BPTR) 0)
				break;
			}
		  if ( workptr2 == (BPTR) 0 )
			return(EXER_MEMFULL);
		  ri = 1; rl = MAX_RUB_NAME_LEN_STD; 
		  worklen1 = lenuze(workptr1,worklen1);
		  *workptr2 = 0;
	
		  /* Analyse arguament 'Liste des Rubriques' and fill descriptor */
		  /* ----------------------------------------------------------- */
		  while (( worklen1 > 0 ) && ( ri < tl)) {
			  if ( *workptr1 == ',' ) {
				  while (( rl > 0 ) && ( ri < tl )) {
					  *(workptr2 + ri) = ' '; ri++; rl--;
					} 
				  worklen1--; workptr1++; (*workptr2)++; rl = MAX_RUB_NAME_LEN_STD; continue;
				}
			  if (rl > 0) {
			 	  *(workptr2 + ri) = *(workptr1++); 
				  ri++; rl--; worklen1--; continue; 
				}
			else 	{ 
				  if ((*workptr1 == ' ') || (*workptr1 == ',')) { 
					  break; 
					}
				else 	{ 
					  liberate(workptr2);
					  return(EXER_RUBTROP);
					}
				}
      }
		  if ( rl < MAX_RUB_NAME_LEN_STD ) {
			  while (( rl > 0 ) && ( ri < tl )) {
				  *(workptr2 + ri) = ' '; ri++; rl--;
			  } 
			  (*workptr2)++; 
		  }
		  worklen2 = ri;
		}
	}
  /* Collect 2nd Optional arguament 'Options du Lien' */
  /* ------------------------------------------------ */
  if ( fargset(1) != 0 ) {
	  if ( worktyp1 == 3 ) {
		  c = toupper(*workptr1);

		  /* Test for 'Ensemble Minimum' */
		  /* --------------------------- */
		  if ( c == 'A' ) { mode |= 0x0004; }

		  /* Test for 'Lien a suprimer' */
		  /* -------------------------- */
		  if ( c == 'D' ) { mode |= 0x0008; }
		}
	}
  errno = 0;

  #ifdef ABALBD

  /* Perform 'Transfer du Jointure' For Database Access's */
  /* ---------------------------------------------------- */
  if ( jl > 0 ) { 
	  (VOID) memcpy((workptr2+worklen2),(BPTR) (joinwork+2),(USINT) jl); 
	}

  #endif

  /* Perform the Actual MC/MCBD/BD function : 'LINK' or 'CLINK' */
  /* ---------------------------------------------------------- */
  ri = (EXAWORD) mc_key(fidreel,mode,workptr2,worklen2+jl,func);

  /* Liberate pointer if needed */
  /* -------------------------- */	
  if ( workptr2 != (BPTR) 0 ) 
	  liberate(workptr2);

  /* Return Error Status */
  /* ------------------- */
  if ( ri == MOINS_UN ) 
	  return(errno);
  else	return(0);
}


/*
 *	M C q T O K E N ( reqtok )
 *	--------------------------
 *	Token id codes :	0	Operator
 *				1	Rubrique
 *				2	Value
 *
 */

EXAWORD	Qtoken_length;

EXAWORD	mcQtoken(reqtok)
EXAWORD	reqtok;
{
	EXAWORD	rdex,etat;
	EXAWORD	quoter=0;
/* Initialise Token buffer index */
/* ----------------------------- */
rdex = 0; etat =0; Qtoken_length = 0;

/* While Source string length is Valid */
/* ----------------------------------- */
while ( worklen1 > 0 ) {
	/* Check for operator request */
	/* -------------------------- */
	if ( reqtok == 0 ) {
		worklen1--;
		/* Prepare Operator Binary Code */
		/* ---------------------------- */
		switch ( *(workptr1++) ) {
			case '>' : rdex = 0x0005; break;
			case '<' : rdex = 0x0009; break;
			case '=' : rdex = 0x000D; break;
			case '(' : rdex = 0x001E; break;
			default  :
			case ' ' : continue;
			}
		/* Check for and Mix in Secondary Character */
		/* ---------------------------------------- */
		if ( *workptr1 == '=' ) { rdex += 12; workptr1++; worklen1--; }
		if ( *workptr1 == '>' ) { rdex += 16; workptr1++; worklen1--; }

		/* Store the Binary Code to Result Zone */
		/* ------------------------------------ */
		askbuf[0] = (EXABYTE) rdex;

		/* Avaler White Spaces */
		/* ------------------- */
		while (( *workptr1 == ' ' ) && ( worklen1 > 0 )) {
			workptr1++; worklen1--; 
			}
		/* Return Result as anticipated */
		/* ---------------------------- */
		Qtoken_length = 1;
		return(reqtok);
		}
	else 	{
		/* Request for Value or Rubrique */
		/* ----------------------------- */

		/* Analyse character */
		/* ----------------- */
		switch ( *workptr1 ) {
			case ')' :
			case ',' : /* Check for Inside Quotes */
				   /* ----------------------- */
				   if ( etat == 2 ) { 
					askbuf[rdex++] = *(workptr1++); 
					worklen1--; 
					continue; 
					}
				   do { /* Avaler White Space */
				 	workptr1++; worklen1--; 
				  	}
				   while (( *workptr1 == ' ' ) && ( worklen1 > 0 ));
				   if ( rdex == 0 ) { continue; }
				   break;
			case '>' :
			case '<' :
			case '=' :
			case '(' : /* Check for Inside Quotes */
				   /* ----------------------- */
				   if ( etat == 2 ) { 
					askbuf[rdex++] = *(workptr1++); 
					worklen1--; 
					continue; 
					}
				   if ( rdex == 0 ) { return(MOINS_UN); }
				   break;
			case '"' :
			case '\'': if ( etat == 2 ) { 
					if ( *workptr1 == quoter ) {
						workptr1++; 
						worklen1--; 	
						break; 
						}
					else	{
						askbuf[rdex++] = *(workptr1++); 
						worklen1--; 
						continue; 
						}	
					}
			   	   else { 
					quoter = *(workptr1++);
					etat = 2; 
					worklen1--; 
					continue;   
					}
			default  : askbuf[rdex++] = *(workptr1++); 
				   worklen1--; 
				   continue;
			}
		}
	/* Avaler White Space Please */
	/* ------------------------- */
	while ((*workptr1 == ' ') && ( worklen1 > 0)) {
		workptr1++; worklen1--;
		}
	Qtoken_length = rdex;
	askbuf[rdex++] = (EXABYTE) 0;
	return(reqtok);
	}
if ( reqtok > 0 ) { 
	Qtoken_length = rdex;
	askbuf[rdex++] = (EXABYTE) 0; 
	return(reqtok); 
	}
else	return(MOINS_UN);
}

/*
 *	R U B S H I F T _ w i t h _ P R E F I X 
 *	---------------------------------------
 *	when use of long names is active this 
 *	function is used to transfer a rubrique 
 *	to the corresponding descriptor detecting
 *	eventual TABLE. prefixed expressions.
 *	Note : the table prefix is space filled 
 *	and the descriptor contains a byte prefix 
 * 	where
 *		0 : no table prefix present
 *		1 :    table prefix present
 *
 *
 *	BYTE [TABLE PREFIX] RUBRIQUE
 *
 */

EXAWORD	rubshift_with_prefix(desc,pColName,cbColName)
BPTR	desc;
BPTR 	pColName;
EXAWORD cbColName;
{
	EXAWORD	y,cb=MAX_RUB_NAME_LEN_EXT+1;
	BPTR	tableName=desc;
	BPTR	p=pColName;

	/* Test if useful length is greater than total legal rubrique length */
	/* ----------------------------------------------------------------- */
	if ((cbColName = lenuze(pColName,cbColName)) > (MAX_TABLE_NAME_LEN_EXT+MAX_RUB_NAME_LEN_EXT+1)) {
		return( 0 );
		}

	/* Initialise Control */
	/* ------------------ */
	*(desc++)=0; y=0;

	/* Transfer rubrique name whilst checking for TABLE. prefix */
	/* -------------------------------------------------------- */
	while (cbColName > 0) {
		if ((*p=='.') && (*tableName==0) && (bUserLongNames)) {

			/* indicate table prefix present */
			/* ----------------------------- */
			*tableName=1;

			/* space fill remainder of tabler prefix */
			/* ------------------------------------- */
			for (;y<MAX_TABLE_NAME_LEN_EXT;y++) *(desc++)=' ';

			/* Adjust control information */
			/* -------------------------- */
			y=0; cb+=MAX_TABLE_NAME_LEN_EXT; p++;
			}
		else	{
			/* transfer character */
			/* ------------------ */
			*(desc++) = *(p++);  y++;
			}
		cbColName--;
		}

	/* space fill remainder of descriptor */
	/* ---------------------------------- */
	for (;y<MAX_RUB_NAME_LEN_EXT;y++) *(desc++)=' ';

	return(cb);
}



EXAWORD	rubcmpi(BPTR  a ,EXAWORD  al ,BPTR  b ,EXAWORD  bl )
{
	/* Repeat while neither length is ZERO */
	/* ----------------------------------- */
	while ((al > 0) && (bl > 0)) {
		/* If current characters differ : FAIL */
		/* ----------------------------------- */
		if ( toupper(*a) != toupper(*b) ) { return(MOINS_UN); }
		a++;
		b++;
		/* Decrement length controllers */
		/* ---------------------------- */
		al--; bl--;
		}

	/* Ensure Strings Contain only white space */
	/* --------------------------------------- */
	while (al > 0) {
		if ( *(a++) != ' ') { return(MOINS_UN); }
		al--;
		}

	while (bl > 0) {
		if ( *(b++) != ' ') { return(MOINS_UN); }
		bl--;
		}

	/* Strings are Equal */
	/* ----------------- */
	return( 0 );
}



EXABYTE GetColumn(EX_FILE_HANDLE hFile,
               BPTR szTableName,
               EXAWORD cbTableName,
               BPTR szColumnName,
               EXAWORD cbColumnName,
               EXAWORD PTR pColumnSize,
               EXAWORD PTR pColumnType)
{

	if ((fidperm & NGF_TYP)!=NGF_BD){ 

		typedef EXAWORD (* lkey_proc_type)(EX_FILE_HANDLE, BPTR, EXAWORD, EXAWORD);

		EXABYTE  colDesc[RUB_DESC_LEN_EXT+5];
		EXAWORD  err=0;
		EXAWORD  cbColDesc               =   bUserLongNames ? (RUB_DESC_LEN_EXT+5) : (RUB_DESC_LEN_STD+5);
		EXAWORD  cbColName               =   bUserLongNames ? (MAX_RUB_NAME_LEN_EXT) : (MAX_RUB_NAME_LEN_STD);
		EXAWORD  wColumnLengthOffset     =   bUserLongNames ? (RUB_LEN_OFFSET_EXT) : (RUB_LEN_OFFSET_STD);
		EXAWORD  wColumnTypeOffset       =   bUserLongNames ? (RUB_TYPE_OFFSET_EXT) : (RUB_TYPE_OFFSET_STD);
		EXABYTE  listOperation           =   bUserLongNames ? LIST_RUB_FIRST_EXT : LIST_RUB_FIRST_STD;
		EXAWORD  z;
		lkey_proc_type  lkey_proc;
		BPTR    rubr_base_saved;
		EXAWORD    rubr_max_saved;
		rubr_base_saved = rubr_base; rubr_max_saved = rubr_max;
		rubr_base = fidbuff; rubr_max = fidmc;

		if ((z = rubrctrl((BPTR) szColumnName,cbColumnName)) != MOINS_UN) {
			z *= (cbColDesc-5);
			*pColumnSize=(EXAWORD)TcodeWord16( (rubr_base + z + wColumnLengthOffset) );
			*pColumnType=(EXABYTE)*((EXABYTE*)(rubr_base + z + wColumnTypeOffset));
			rubr_base = rubr_base_saved; rubr_max = rubr_max_saved;
			return( 1 );
			}

		rubr_base = rubr_base_saved; 
		rubr_max  = rubr_max_saved;

		if (!hFile) return( 0 );

		/* Detect a properly procedure */
		/* --------------------------- */
		if ((fidperm & NGF_TYP)==NGF_MC) 
			lkey_proc=&EeEmc_lkey;
		else 	lkey_proc=&EeEbd_lkey;
  
		/* Get the first column */
		/* -------------------- */
		err=lkey_proc(hFile,colDesc,cbColDesc,listOperation);

		/* switch to getthe NEXT item */
		/* -------------------------- */
		listOperation++; 

		/* list all columns tofind the needed one */
		/* -------------------------------------- */
		while (!(err)){
			if (!(RubrCompare(szColumnName,cbColumnName,colDesc,cbColName))) {
				/* column was found : collect the info */
				/* ----------------------------------- */
				if (pColumnSize){
					*pColumnSize=((EXAWORD)colDesc[wColumnLengthOffset]<<8)+(EXAWORD)(colDesc[wColumnLengthOffset+1]);
					}
				if (pColumnType) {
					*pColumnType=(EXAWORD)colDesc[wColumnTypeOffset];
					}
				return( 1 );
				}
			/* get next column */
			/* --------------- */
			err=lkey_proc(hFile,colDesc,cbColDesc,listOperation);
			}
		return( 0 );
		} 
	else 	{
		EXAWORD i;
		int  saved_lfh;
		int  pass;

		for (pass=0;pass<2;pass++){

			for (i=1; i<diezfic; i++) {
				if ((EXAWORD)*(fidbase+i) != 0) {
					if ((*(AssignTable + i)).unlog!=0 && (*(AssignTable + i)).unlog!=EX_UNUSED_HANDLE/* &&
						(EX_FILE_HANDLE)(*(AssignTable + i)).dblog==hFile*/) {

						EXAWORD fidperm_saved=fidperm;
						EXABYTE res;

						if (szTableName && cbTableName){
							EXABYTE  szFileName[MAX_TABLE_NAME_LEN_EXT+1]={0};
							EXAWORD  cbFileName=fn_parser((*(AssignTable + i)).direcp,szFileName,8); // extract the filename

							if (cbFileName && !rubcmpi(szFileName,cbFileName,szTableName,cbTableName)){
								fidperm=(*(AssignTable + i)).permf;

								saved_lfh=lfh;
								lfh=i;
								loadfich();

								res=GetColumn(pass ? (*(AssignTable + i)).unlog:0,
									 szTableName,cbTableName,szColumnName,cbColumnName,pColumnSize,pColumnType);

								lfh=saved_lfh;
								loadfich();

								fidperm=fidperm_saved;
								return( res );
								}
							continue;
							}

						fidperm=(*(AssignTable + i)).permf;
						saved_lfh=lfh;
						lfh=i;
						loadfich();
						res=GetColumn(( pass ? (*(AssignTable + i)).unlog : 0 ),
							 szTableName,cbTableName,szColumnName,cbColumnName,pColumnSize,pColumnType);
						lfh=saved_lfh;
						loadfich();
						fidperm=fidperm_saved;
						if (res) {
							return( res );
							}
						}
					}
				}
			}
		}
	return( 0 );
}



EXAWORD	questprep(qui)
EXAWORD	qui;		/* 2 indicates MC Liens, 4 => BD Jointures */
{
	EXAWORD	x=0,y=0,z=0,t=0,l=0,ll=0,kk;
	EXAWORD	ri;

	/* Establish Rubrique Control Values : Base pointer and Rubrique Count */
	/* ------------------------------------------------------------------- */
	rubr_base = fidbuff; rubr_max = fidmc;

	/* Analyse Question String checking rubriques for Validity */
	/* ------------------------------------------------------- */
	x = qui - 1; ri = 1;
	worklen1 = lenuse(workptr1,worklen1);

	/* Remove and leading white space */
	/* ------------------------------ */
	while (( worklen1 > 0 ) && ( *workptr1 == ' ' )) { workptr1++; worklen1--; }

	/* While question contains valid clauses */
	/* ------------------------------------- */
	while (( worklen1 > 0 ) && ( ri < worklen2 )) {

		/* Attempt to collect token of type X */
		/* ---------------------------------- */
		if ( mcQtoken(x) != x) { 

			/* Mis-matched Tokens */ 
			/* ------------------ */
			return(EXER_MCFUNC); 
			}

		/* Calculate Length of Token */
		/* ------------------------- */
		if ((y = Qtoken_length) == 0) {
			/* Ignore Empty token */ 
			continue; 
			}

		/* Select WRT token Type */
		/* --------------------- */
		switch ( x ) {

			case 4 :	/* Token Type = 2nd Rubrique */
					/* ------------------------- */
				(*workptr2)++;

			case 3 :	/* Token Type = 1st Rubrique */
					/* ------------------------- */

				/* bSystemLongNames ??? IJM */
				if (!bSystemLongNames){
					(VOID) rubshift( (workptr2 + ri),(BPTR) askbuf,y,bSystemLongNames);
					ri += MAX_RUB_NAME_LEN_STD; 
					}
				else	{
					ri+=rubshift_with_prefix( (workptr2 + ri),(BPTR) askbuf,y);
					}
				if ( x & 4 ) 	{ x = 3; }
				else 		{ x = 0; } 
				continue;

			case 1 :	/* Token Type = only Rubrique */
					/* -------------------------- */
				(*workptr2)++;
				/* bSystemLongNames ??? IJM */
				if (!bSystemLongNames){
					if (!GetColumn(fidreel,(BPTR)0,0,askbuf,y,&ll,&t)) 
						return(EXER_MCSIZE);
					else	(VOID) rubshift( (workptr2 + ri),(BPTR) askbuf,y,bSystemLongNames);
	
					ri += MAX_RUB_NAME_LEN_STD; 
					}
				else	{
					EXAWORD i,cbTable=0;
					BPTR tableName=(BPTR)0;
					BPTR colName=askbuf;
					if (bUserLongNames){
						for (i=0;i<y;i++){
							if (askbuf[i]=='.'){
								tableName=askbuf;
								colName=(BPTR)(askbuf+i+1);
								cbTable=(EXAWORD)(colName-tableName-1);
								break;
								}
							}
			  			}
					if (!GetColumn(fidreel,tableName,cbTable,colName,y-(cbTable ? (cbTable+1):0),&ll,&t)) 
						return(EXER_MCSIZE);
					ri+=rubshift_with_prefix( (workptr2 + ri),(BPTR) askbuf,y);
					}
				x=0;
				continue;

			case 0 : 	/* Token type = Operator */
					/* --------------------- */
				 kk = (EXAWORD) askbuf[0];
				 *(workptr2 + ri) = (EXABYTE) kk;
				 x = qui; ri++; continue;

			case 2 :	/* Token Type = Value */
					/* ------------------ */
				 *(workptr2 + ri) = (EXABYTE) ll; l = ll; ri++;
				 if ( (t & 0x0004) == 0 ) { /* String Ascii */
					workptr3 = (BPTR) &askbuf[0]; worklen3 = y;
					while ((l > 0) && (worklen3 > 0)) { 
						*(workptr2 + ri) = *(workptr3++); 
						ri++; l--; worklen3--; 
						}
					while ( l > 0 ) { 
						*(workptr2 + ri) = ' '; ri++; l--; 
						}
					}
				 else 	{ 
			 		switch ( ll ) {
					case 1 : z= atoi((BPTR) askbuf,y);
						 *(workptr2 + ri) = (char) z; ri++;
						 break;
					case 2 : z= atoi((BPTR) askbuf,y);
						 balputw( z , (workptr2 + ri) );
						 ri += sizeof( short int ); /* not WORDSIZE  BLEM : IJM */
						 break;
					default: if ((askbuf[0] < '0') || ( askbuf[0] > '9')) {
							if (( askbuf[0] != '-' ) && ( askbuf[0] != '+' ) && ( askbuf[0] != '.' ) && ( askbuf[0] != ',' ))
								return(99);
							}
						if ((workptr3 = (BPTR) allocate((USINT) l)) == (BPTR) 0)
							return( EXER_MEMFULL );
						 atobcd((BPTR) askbuf,workptr3,l,y);
						 (VOID) bcdfix(workptr3,workptr3,l,l,(( t & 0x00F0 ) >> 4),1);
						 memcpy((workptr2 + ri),workptr3,(USINT) l);
						 liberate(workptr3); ri += l; break;
						}
					}
				if ( kk == 0x001E ) 
					kk = 0;
				else 	x  = 1;
				continue;
			}
		}
	if ( ri < worklen2 )    {	worklen2 = ri; return(0); 	}
	else			{	return(ABAL_MEMORY);		} 
}


/*
 *	I N T E R O ( func , sfx )
 *	--------------------------
 *	Performs the BAL/ABAL MC functions POSIT and COUNT
 *
 *	POSIT [.D] = nlog , Question [,Options] :[ &Etiq , e ,] Compteur
 *	COUNT [.D] = nlog , Question [,Options] :[ &Etiq , e ,] Compteur
 *
 *	NGF,POSIT,[ARGDESCS],[ERREUR+VAR],NLOG,XDESC,QUEST,COMPTEUR,OPT
 *	    COUNT
 */

EXAWORD	intero( func , sfx )
EXAWORD	func,sfx;			   
{
	EXAWORD	ri,mode,jl;
	EXAWORD	TempLengh;
	EXALONG	resnombre;
	EXABYTE	c;
	EXAWORD	FlagIsNewPosit;

/* Get Direction Byte and create function code */
/* ------------------------------------------- */
func |= ( 0x0008 << ( ((EXAWORD) *(fdex++)) & 1 )); mode = 0; jl = 0;
if (( func = setjoin(func) ) == 0 ) { return(err_val); } 
if ( sicico & ONSEM_JOIN ) { jl = 15; sicico &= OFSEM_JOIN; }

/* Establish Interogation String Source/Result pointers */
/* ---------------------------------------------------- */
if ( fargset(1) == 0 ) 	        			{ return(err_val); 	}
if ( worktyp1 != 3   )					{ return(EXER_SYNTAX);	}

/* Establish Question Descriptor Pointer */
/* ------------------------------------- */
/* Check first for Descriptor Overflow   */
/* ------------------------------------- */
if ( worktop < dieztmp ) { worklen2 = (dieztmp - worktop); }
else			 { return(ABAL_MEMORY);		   }

workptr2 = (BPTR) (TcodeByteStack + worktop);

*workptr2 = (EXABYTE) 0;

/* Analysis of Question */
/* -------------------- */
rubr_base = fidbuff; rubr_max = fidmc;
ri=NewAnalyseSyntaxique(sfx);	/* sfx=0 => COUNT; sfx=1 => POSIT */
if(ri!=ABAL_SUCCESS){
	FlagIsNewPosit=0;
	if ((ri = questprep(2)) != 0) 
		return(ri); 
	}
else{
	FlagIsNewPosit=1;
	}

/* Protect the Question in the Descriptor */
/* -------------------------------------- */
if (( worktop + worklen2 + jl) >= dieztmp ) { 
	return(ABAL_MEMORY); 
	}
else	{
	worktop += (worklen2 + jl); 
	}

/* Collect Result storage arguament */
/* -------------------------------- */
if ( fargset(0) == 0 ) { return(err_val); }

/* Establish Interogation Option */
/* ----------------------------- */
if ( fargset(3) != 0 )  {
	if (( worklen3 > 0 ) && ( worktyp3 == 3)) {
		c = toupper(*workptr3);
		if ( c == 'S' ) { mode |= 0x0040; } /* Sequential 	 */
		if ( c == 'U' ) { mode |= 0x0020; } /* Unique no doubles */
		/* ----------------------------------------------- */
		/* Avec le Nouveau posit, option U et S interdites */
		/* ----------------------------------------------- */
		if ((FlagIsNewPosit) && (!( bSystemLongNames))) { if ((c == 'S') ||  (c == 'U')) { return (94); } }
		}
	}

#ifdef ABALBD

/* Perform 'Transfer du Jointure' For Database Access's */
/* ---------------------------------------------------- */
if ( jl > 0 ) { 
	(VOID) memcpy((workptr2+worklen2),(BPTR) &joinwork[2],(USINT) jl); 
	if(FlagIsNewPosit){
		/* On doit rajouter la taille du nom de jointure
		 * dans la taille du nouveau descripteur
		 * workptr2[22] = poids faible
		 * workptr2[21] = poids fort
		 */

		if (!(bSystemLongNames)){
			TempLengh=(EXAWORD)(256*workptr2[POSIT_DESC_SIZE_OFS_STD] + workptr2[POSIT_DESC_SIZE_OFS_STD+1]) + jl;
			workptr2[POSIT_DESC_SIZE_OFS_STD]=(EXABYTE)(TempLengh >> 8);
			workptr2[POSIT_DESC_SIZE_OFS_STD+1]=(EXABYTE)(TempLengh & 0x00FF);
			}
		else	{
			TempLengh=(EXAWORD)(256*workptr2[POSIT_DESC_SIZE_OFS_EXT] + workptr2[POSIT_DESC_SIZE_OFS_EXT+1]) + jl;
			workptr2[POSIT_DESC_SIZE_OFS_EXT]=(EXABYTE)(TempLengh >> 8);
			workptr2[POSIT_DESC_SIZE_OFS_EXT+1]=(EXABYTE)(TempLengh & 0x00FF);
			}

		}
	}

#endif

/* Perform function POSIT or COUNT */
/* ------------------------------- */
if ( (sfx & 1) == 0 )
	mode |= 0x0080;

if ((resnombre = (EXALONG) mc_key(fidreel,mode,workptr2,(worklen2+jl),func)) == -1) {
	return(errno); 
	}
else 	{
	switch ( worktyp1 ) {
		case VARB_FOUR :
		case VARB_INT8 : ri = (EXAWORD) resnombre;
			 *((CPTR) workptr1) = (char) ri; break;
		case VARB_INT16 : ri = (EXAWORD) resnombre;
			 balputw(ri,workptr1); break;
#ifdef	VERSION666
		case VARB_INT32 : balputl(resnombre,workptr1); break;	
#endif
		case VARB_BCD : (VOID) ltobcd(resnombre,workptr1,worklen1); break;
		case VARB_STR : ri = (EXAWORD) resnombre;
			 (VOID) itoa(ri,workptr1,worklen1); break;
		}
	return(0);
	}
}
#ifdef INTEL
#include "exprag1.h"
#endif

