/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1994 Amenesik / Sologic s.a.			*/
/*		  -------------------------------------			*/
/*									*/
/*		File	:	AOLABEL.C				*/
/*		Version :	2.1b					*/
/*		Date	:	11/05/1994				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_LABEL_C
#define	_LABEL_C

#include "aomain.h"
#include "aolabel.h"


EXTERN	EXAWORD	SymbolStatus;

/*	Add new Reference Info to Adresse Storage Tree		*/
/*	----------------------------------------------		*/

EXAWORD	AddLabel( oldadr , newadr )
EXAWORD	oldadr;
EXAWORD	newadr;
{
	LABEL	lptr;

	if ( oldadr != newadr ) {
		if ((lptr = (LABEL) allocate(sizeof(struct etiquette))) != (LABEL) 0) {
			lptr->source = oldadr;
			lptr->target = newadr;
			lptr->suite  = AdrTree;
			AdrTree      = lptr;
			return(0);
			}
		else	{
			return(-1);
			}
		}
	return(0);
}

EXAWORD	relocate_newline( oldadr )
EXAWORD	oldadr;
{
	LABEL	lptr;
	if ((lptr = AdrTree) != (LABEL) 0) {
		do	{
			if ( lptr->source == oldadr )
				return( lptr->target );
			}
		while ((lptr = lptr->suite) != (LABEL) 0);
		}
	return( oldadr );
}

#ifndef	PRL
#ifndef	DOS
EXAWORD	MallInit( x )
EXAWORD	x;
{
	return(0);
}

void	MallFree()
{
	return;
}
void	PushMall()
{
	return;
}
void	PopMall()
{
	return;
}
#endif
#endif

/*	Initialisation of Labels Tree	*/
/*	-----------------------------	*/

EXAWORD	InitLabel(block_type,segm_id,proc_id)
EXAWORD	block_type;
EXAWORD	segm_id;
EXAWORD	proc_id;
{
	/* Initialise Base Pointers */
	/* ------------------------ */
	AdrTree = (LABEL) 0;
	FwdTree = (BACKPATCH) 0;

	/* Initialise Quick memory Allocator */
	/* --------------------------------- */
	if ( MallInit( 4096 ) != 0 ) 
		return(-1);

	/* Attempt to initialise Symbolic labels */
	/* ------------------------------------- */
	if ( SymbolStatus )
		collect_correspondance_labels( (block_type == 1 ? 0 : 1 ), (block_type == 1 ? segm_id : proc_id ));

	return(0); 

}

/*	Liberation of a Label Level	*/
/*	---------------------------	*/

void	LiberLabel( lptr )
LABEL	lptr;
{
	LABEL	rptr;

	while ( lptr != (LABEL) 0 ) {
		rptr = lptr->suite;
		lptr = liberate((BPTR) lptr );
		lptr = rptr;
		}
	return;
}

void	LiberFwd( lptr )
BACKPATCH	lptr;
{
	BACKPATCH	rptr;

	while ( lptr != (BACKPATCH) 0 ) {
		rptr = lptr->suite;
		lptr = liberate ((BPTR) lptr );
		lptr = rptr;
		}
	return;
}

/*	Liberation of Label Tree	*/
/*	------------------------	*/

void	FreeLabel(mode)
EXAWORD	mode;
{
	if (( mode ) 
	&&  ( SymbolStatus )) {
		status_message((BPTR) "Symbolic Information", (BPTR) "Rellocation" );
		rellocate_correspondance_labels();
		}

	LiberLabel( AdrTree ); 
	AdrTree = (LABEL) 0;
	LiberFwd( FwdTree );   
	FwdTree = (BACKPATCH) 0;
	MallFree();
}

void	AddForward( oldlabel , rptr )
EXAWORD	oldlabel;
BPTR	rptr;
{
	BACKPATCH	lptr;

	if ((lptr = (BACKPATCH) allocate(sizeof(struct forwardref))) != (BACKPATCH) 0) {
		lptr->source = oldlabel;
		lptr->target = rptr;
		lptr->suite  = FwdTree;
		FwdTree      = lptr;
		}
	return;
}

/* 
 *	This function is necessary to test if a zone which appears to be
 *	and embeded format string contains forward reference labels and 
 *	is therefore not an embeded format string.
 *
 */

EXAWORD	CheckLabel( firstadr, lastadr )
EXAWORD	firstadr;
EXAWORD	lastadr;
{
	LABEL	lptr;

	lptr = AdrTree;

	/* While Not End of Tree */
	/* --------------------- */
	while ( lptr != (LABEL) 0 ) {

		/* Check for Label is Between First and Last Adresses */
		/* -------------------------------------------------- */
		if (( lptr->source >= firstadr ) && ( lptr->source <= lastadr ))
			return( MOINS_UN );

		lptr = lptr->suite;

		}
	/* Adresses do not contain forward referenced Label */
	/* ------------------------------------------------ */
	return( 0 );
}

EXAWORD	LabelKnown( oldlabel )
EXAWORD	oldlabel;
{
	LABEL	lptr;

	lptr	 =	AdrTree;

	/* While Not End of Tree */
	/* --------------------- */
	while ( lptr != (LABEL) 0 ) {

		/* Labels are stacked Greatest Out */
		/* ------------------------------- */
		if ( oldlabel > lptr->source ) {
			return(MOINS_UN);
			}

		/* Check for Labels Match */
		/* ---------------------- */
		if ( lptr->source == oldlabel ) {

			/* Return the New Label Value */
			/* -------------------------- */
			return( lptr->target );

			}

		/* Next Label Info Pointer */
		/* ----------------------- */
		lptr = lptr->suite;

		}

	return(MOINS_UN);
}

EXAWORD	IsBackPatch( pptr )
BPTR	pptr;
{
	BACKPATCH	lptr;

	lptr = FwdTree;

	while ( lptr != (BACKPATCH) 0 ) {

		if ( pptr > lptr->target ) {
			return(MOINS_UN);
			}

		/* If this adresse is already to be patched */
		/* ---------------------------------------- */
		if ( lptr->target == pptr ) {
			return(0);
			}
		lptr = lptr->suite;
		}
	return(MOINS_UN);

}

/*	Conversion of old Label to New label	*/
/*	------------------------------------	*/

void	ConvertLabel( optr , nptr )
BPTR	optr;
BPTR	nptr;
{
	LABEL	lptr;
	EXAWORD	oldlabel;

	/* Collect Label to Convert */
	/* ------------------------ */
	oldlabel = tcGetw( optr );

	/* Establish Tree Base */
	/* ------------------- */
	lptr	 =	AdrTree;

	/* While Not End of Tree */
	/* --------------------- */
	while ( lptr != (LABEL) 0 ) {

		/* If Test label is Biggest */
		/* ------------------------ */	
		if ( oldlabel > lptr->source  ) {

			/* Add to BackPatch List */
			/* --------------------- */
			AddForward( oldlabel , nptr );
			return;
			}

		/* If Label Found Then Patch it */
		/* ---------------------------- */
		if ( lptr->source == oldlabel ) {

			/* Patch the New Label Value */
			/* ------------------------- */
			tcPutw( optr , (lptr->target) );
			return;
			}

		lptr = lptr->suite;
		}

	/* Add to BackPatch List */
	/* --------------------- */
	AddForward( oldlabel , nptr );
	return;

}

/*	Back Patch of the Foreward referenced Labels 	*/
/*	--------------------------------------------	*/

void	Resolver()
{
	BACKPATCH	pptr;
	LABEL		lptr;

	pptr	=	FwdTree;

	/* While Not End of List */
	/* --------------------- */
	while ( pptr != (BACKPATCH) 0 ) {

		lptr = AdrTree;

		while ( lptr != (LABEL) 0 ) {
			if ( lptr->source == pptr->source ) {
				tcPutw( pptr->target , lptr->target );
				break;
				}
			lptr = lptr->suite;
			}
		pptr = pptr->suite;
		}
	return;

}


#ifdef	OPTIMISE_CONSTANT_TABLE

/*	Recherche d'une Alias sur une constant		*/
/*	--------------------------------------		*/

EXAWORD	ConvertConst( cptr , si )
BPTR	cptr;
EXAWORD	si;
{
	ALIASSE aptr;
	EXAWORD	cid;


	/* Do nothing if not activated */
	/* --------------------------- */
	if (! (Options.Constants) ) { return(0); }

	cid = tcGetw( (cptr + si) );

	aptr = Aliasse;
	while ( aptr != (ALIASSE) 0 ) {
		if ( aptr->old_offs == cid ) {
			tcPutw( (cptr + si) , aptr->new_offs );
			return( 0 );
			}
		aptr = aptr->suite;
		}
	/* Reference not found */
	/* ------------------- */
	return( 1 );
}

/*	Liberation de la liste des alias convertis	*/
/*	------------------------------------------	*/
void	FreeAlias()
{
	ALIASSE aptr;

	/* Recover protected Allocations */
	/* ----------------------------- */
	PopMall();

	/* Liberate Constants Tree */
	/* ----------------------- */
	while ( Aliasse != (ALIASSE) 0 ) {
		aptr = Aliasse->suite;
		Aliasse = liberate((BPTR) Aliasse );
		Aliasse = aptr;
		}
	Aliasse = (ALIASSE) 0;

	/* Liberate Quick Allocater */
	/* ------------------------ */
	MallFree();
	return;
}

/*	Creation d'une reference d'alias sur les constants	*/
/*	--------------------------------------------------	*/

void	AliasCons( si , di )
EXAWORD	si;
EXAWORD	di;
{
	ALIASSE aptr;
	if ((aptr = (ALIASSE) allocate(sizeof(struct aliasse))) != (ALIASSE) 0) {
		aptr->old_offs = si;
		aptr->new_offs = di;
		aptr->suite = Aliasse;
		Aliasse = aptr;
		}
	return;
}

/*	Detection d'une alias constant		*/
/*	------------------------------		*/

void	KeepConstant( si )
EXAWORD	si;
{
	EXAWORD	sx;
	EXAWORD	dx;
	EXAWORD	di;
	EXAWORD	xl;

	di = 0;

	/* While not end of new constant table */
	/* ----------------------------------- */
	while ( di < NewGkl ) {
		
		/* Check for Same type and or Length */
		/* --------------------------------- */
		if ( *(tcGKT + si) == *(tcGKT + di) ) {

			sx = 0; dx = 0;

			/* Same Type Get Length */
			/* -------------------- */
			while ((xl = *(tcGKT + si + sx)) == 0 ) {
				sx++; dx++;
				}
			xl++;
	
			/* Compare Lengths and Contents */
			/* ---------------------------- */
			while ( xl > 0 ) {
				if (*(tcGKT+si+sx) != *(tcGKT+di+dx)) {
					break;
					}
				xl--; sx++; dx++;
				}

			/* Length Count expired so Lose this Constant */
			/* ------------------------------------------ */
			if ( xl == 0 ) {

				/* Create an Alias Reference */
				/* ------------------------- */
				AliasCons( si , di );
				return;
				}

			}

		/* Position to Next Constant */
		/* ------------------------- */
		if ( *(tcGKT + di) == 0 ) { di++; }
		di += ( *(tcGKT + di) + 1 );
		
		}

	/* Create an Alias Reference */
	/* ------------------------- */
	AliasCons( si , di );

	/* Arrival here means ADDITION of this constant required */
	/* ----------------------------------------------------- */
	while ((xl = *(tcGKT + si)) == 0 ) {
		*(tcGKT + di) = *(tcGKT + si);
		si++; di++;
		}

	/* Adjust for Length */
	/* ----------------- */
	xl++; 

	/* Transfer contents */
	/* ----------------- */
	while ( xl > 0 ) {
		*(tcGKT + di) = *(tcGKT + si);
		si++; di++; xl--;
		}

	NewGkl = di;
	return;

}

/*	Recherche des alias des constants	*/
/*	---------------------------------	*/

EXAWORD	CompactConst(MaxGkl)
EXAWORD	MaxGkl;
{
	EXAWORD	si;
	EXAWORD	lc;

	if ( ! (Options.Liste) ) {
		MallInit( 4096 );
		}
	else	{
		AffLine();
		AffMsg((BPTR) "Constant table ");
		AffLine();
		}

	/* Zero the current Used length */
	/* ---------------------------- */
	NewGkl = 0; si = 0;

	/* Reset Aliasse base pointer */
	/* -------------------------- */
	Aliasse = (ALIASSE) 0;

	/* While not end of Old table */
	/* -------------------------- */
	while ( si < MaxGkl ) {
		
		/* Calculate Constant Length */
		/* ------------------------- */
		if ((lc = ((EXAWORD) *(tcGKT + si))) == 0) {
			lc = ((EXAWORD) *(tcGKT + si +1))+1;
			} 
		lc++;

		if (!(Options.Liste)) {

			/* Attempt to Keep Constant */
			/* ------------------------ */
			KeepConstant( si );

			}
		else	{
			AffCons( si );
			AffLine();
			}

		/* Position to Next Constant */
		/* ------------------------- */
		si += lc;

		}

	/* RAZ to end of table */
	/* ------------------- */
	for (si=NewGkl; si < MaxGkl; si++ ) {
		*(tcGKT + si) = (BYTE) 0x00FF;
		}

	if (!(Options.Liste))
		PushMall();

	return(NewGkl);

}


#else

/*	------------------------------------		*/
/*	Constant Table Compression Functions		*/
/*	------------------------------------		*/

extern	BPTR newGKT;	/* Storage Zone for Useful Constants 		*/
BPTR	refGKT;		/* Storage Zone for Used Constant adresses	*/
EXAWORD	LenNewGkt;	/* Length of Used Portion of the new Table	*/
EXAWORD	LenOldGkt;	/* Current Length of Original table		*/

#ifndef	UNIX
extern	BPTR	MakeBlock(EXAWORD);
#else
extern	BPTR	MakeBlock();
#endif

EXAWORD	initialise_constant_compression( longueur )
EXAWORD	longueur;
{
	/* Initialise all Constant Optimisation Values */
	/* ------------------------------------------- */
	newGKT = (BPTR) 0; refGKT = (BPTR) 0; LenNewGkt = 0;

	LenOldGkt = longueur;

	/* Attempt to allocate for new constant table */
	/* ------------------------------------------ */
	if ((newGKT = MakeBlock( longueur )) != (BPTR) 0 ) {

		/* Attempt to allocate for Constant table Re-Director */
		/* -------------------------------------------------- */
		if (( refGKT = MakeBlock( longueur )) != (BPTR) 0 ) {

			/* Initialise Redirection Table */
			/* ---------------------------- */
			memset((BPTR) refGKT, MOINS_UN , longueur );
			memset((BPTR) newGKT, MOINS_UN , longueur );

			/* Generate Default Null Constant */
			/* ------------------------------ */
			*newGKT = 0;
			*(newGKT + 1) = 1;
			*(newGKT + 2) = 0x00CF;
			LenNewGkt = 3;

			/* Indicate SUCCESS */
			/* ---------------- */
			return( 1 );
			}

		/* Liberate allocated block */
		/* ------------------------ */
		LiberateBlock( newGKT );
		newGKT = (BPTR) 0;
		}

	/* Indicate Failure */
	/* ---------------- */
	return( MOINS_UN );

}

EXAWORD	ConvertConst( cptr , si )
BPTR	cptr;
EXAWORD	si;
{
	EXAWORD	lconst;
	EXAWORD	rconst;
	BPTR	sptr;
	BPTR	rptr;
	EXAWORD	slen;

	/* Do nothing if not activated */
	/* --------------------------- */
	if (! (Options.Constants) ) 
		return(0);

	/* Collect Constant Identity from Tcode Location */
	/* --------------------------------------------- */
	lconst = tcGetw( (cptr + si) );

	/* Collect Possible Redirection from Table */
	/* --------------------------------------- */
	rconst = tcGetw( (refGKT + lconst) );

	/* Check for already converted */
	/* --------------------------- */
	if ( rconst != MOINS_UN ) {

		/* Already Converted so Patch and Return */
		/* ------------------------------------- */
		tcPutw( (cptr + si) , rconst );

		/* Indicate Optimisation */
		/* --------------------- */
		return( 1 );

		}

	/* This Constant Must Now be redirected and Transfered */
	/* --------------------------------------------------- */
	tcPutw( (cptr + si) , LenNewGkt );
	tcPutw( (refGKT + lconst), LenNewGkt );


	/* Establish Source and Destination Pointers */
	/* ----------------------------------------- */
	sptr = (BPTR) (tcGKT + lconst);
	rptr = (BPTR) newGKT;

	/* Establish Transfer Length */
	/* ------------------------- */
	if ((slen = (EXAWORD) *sptr) == 0)
		slen = (EXAWORD) ( *(sptr + 1) + 1 );

	/* Plus 1 for The Length Byte */
	/* -------------------------- */
	slen++;

	/* Transfer from Old Table To New Table */
	/* ------------------------------------ */
	while ( slen != 0 ) {
		*( rptr + LenNewGkt ) = *(sptr++);
		slen--;
		LenNewGkt++;
		}

	/* Indicate Optimisation Performed */
	/* ------------------------------- */
	return( 1 );
}

EXAWORD	terminate_constant_compression(handle, secteur )
EXAWORD	handle;
EXAWORD	secteur;
{
	/* ReWrite the New Constant Table Whoops it might have expanded */
	/* ------------------------------------------------------------ */
	StoreBlock(secteur, (BPTR) newGKT );

	/* Liberate the Constant management Blocks */
	/* --------------------------------------- */
	LiberateBlock( refGKT );

	/* Check for Analysis active */
	/* ------------------------- */
	if ( Options.Analyse )
		tcGKT = newGKT;
#ifdef	VMS
	else	LiberateBlock( newGKT ); 
#endif
	
	/* Return new length to caller */
	/* --------------------------- */
	return( LenNewGkt );

}

EXAWORD	is_known_constant( sptr , slen )
BPTR	sptr;
EXAWORD	slen;
{
	BPTR	rptr;
	EXAWORD	ri;
	EXAWORD	i;
	EXAWORD	j;

	/* Initialise Search control */
	/* ------------------------- */
	rptr = tcGKT; ri = 0;

	/* Scan till end of new table */
	/* -------------------------- */
	while ( ri < LenOldGkt ) {


		/* Check for BCD of NULL length : Translator Hole */
		/* ---------------------------------------------- */
		if (( *(rptr +ri) == 0 ) && ( *(rptr + ri + 1) == 0 )) {

			/* So Scan to End of Block */
			/* ----------------------- */
			while ( ri % 256 )
				ri++;

			continue;
			}

		/* Check for String Constants of Same Length */
		/* ----------------------------------------- */
		if ( *(rptr + ri) == slen ) {

			/* Check for Identical Strings */
			/* --------------------------- */
			for ( i = 0, j = 1; i < slen; i++, j++ )

				/* If Not Identical then Quit Compare */
				/* ---------------------------------- */
				if ( *(sptr + i ) != *(rptr + ri + j) )
					break;

			/* If End of Strings Reached OK Found Match */
			/* ---------------------------------------- */
			if ( i == slen )
				return( ri );

			}

		/* Avoid Bcd Marqueur */
		/* ------------------ */
		if ( ! *(rptr + ri) )
			ri++;

		/* Step over to Next Constant */
		/* -------------------------- */
		ri += ( *(rptr + ri) + 1);

		}

	/* Indicate Failure */
	/* ---------------- */
	return( MOINS_UN );

}

EXAWORD	convert_to_constant( sptr , si , rptr , ri )
BPTR	sptr;
EXAWORD	si;
BPTR	rptr;
EXAWORD	ri;
{
	EXAWORD	x;
	EXAWORD	r;

	/* Ensure Constant Folding is Active */
	/* --------------------------------- */
	if ( ! (Options.Constants) )
		return( 0 );

	/* Calculate Tcode String Length */
	/* ----------------------------- */
	x = 0;
	while ( *(sptr + si + x)  ) x++;
	
	/* Test for Already Known */
	/* ---------------------- */
	if ((r = is_known_constant( (sptr + si) , x )) == MOINS_UN ) {
		return( 0 );
		}

	/* Back Patch Tcode to PRN CONST */
	/* ----------------------------- */
	tcPutw( (rptr + ri), r );


	/* Convert to New Table Adresse */
	/* ---------------------------- */
	ConvertConst( rptr , ri );
	

	/* Return Length to avoid */
	/* ---------------------- */

	return( (x+1) );
}

EXAWORD	duplicate_constant_tables( type, len )
EXAWORD	type;
EXAWORD	len;
{
	BPTR	xtab;
	BPTR	xref;

	/* Check for BCD type */
	/* ------------------ */
	if ( type == 0 )	len += 2;
	else			len++;


	if (( xtab = MakeBlock((LenOldGkt + len ))) != (BPTR) 0) {

		memcpy( xtab, tcGKT, LenOldGkt );
		memset( (xtab + LenOldGkt), MOINS_UN, len );
		LiberateBlock( tcGKT );
		tcGKT = xtab;
	
		if (( xtab = MakeBlock(( LenOldGkt + len))) != (BPTR) 0) {
			memcpy( xtab, refGKT, LenOldGkt );
			memset( (xtab + LenOldGkt), MOINS_UN, len );
			LiberateBlock( refGKT );
			refGKT = xtab;

			if (( xtab = MakeBlock(( LenOldGkt + len))) != (BPTR) 0) {
				memcpy( xtab, newGKT, LenOldGkt );
				memset( (xtab + LenOldGkt), MOINS_UN, len );
				LiberateBlock( newGKT );
				newGKT = xtab;
				return( len );

				}
			}
		}

	return( MOINS_UN );

}

EXAWORD	compress_bcd( bptr, blen )
BPTR	bptr;
EXAWORD	blen;
{
	BYTE	result[12];
	BPTR	rptr;
	BPTR	bcd;
	EXAWORD	len;
	EXAWORD	rlen;
	EXAWORD	phase;
	EXAWORD	digit;
	EXAWORD	x;
	
	(void) memcpy((BPTR) result, (BPTR) bptr, (EXAWORD) blen);

	bcd = (BPTR) result; len = blen;

	/* Check for Zero Squeeze Needed */
	/* ----------------------------- */
	if ( (((EXAWORD) *bcd) & 0x000F ) == 0x0000 ) {
		rptr = bcd; rlen = len;
		digit = (EXAWORD) *(bcd++); len--; phase = 1;
		while (( phase != 0 ) && (len > 0)) {
			switch ( phase ) {
				case 1 :	/* Read byte elimine zeros */
						/* ----------------------- */	
					len--;
					if ( (x = (EXAWORD) *(bcd++)) == 0) { continue; }
					if ( (x & 0x00F0) == 0 ) {
						*(rptr++) = (BYTE) ( digit | x ); rlen--;
						if ( len > 0) { 
							memcpy(rptr,bcd,len);
							rlen -= len; rptr += len;
							}
						phase = 0; continue;
						}
					*(rptr++) = (BYTE) ( digit | (( x & 0x00F0) >> 4));
					rlen--; digit = ((x & 0x000F) << 4);
					phase = 2; continue;
				case 2  :
					x = (EXAWORD) *(bcd++); len--;
					*(rptr++) = (BYTE) ( digit | (( x & 0x00F0) >> 4));
					rlen--; digit = (( x & 0x000F ) << 4);
					continue;
				}
			}
		if ((( phase == 2 ) && ( rlen > 0 )) || ( (phase == 1) && (len == 0) && (rlen > 0))) {	
			*(rptr++) = (BYTE) ( digit | 0x000F ); 
			rlen--;
			}
		while ( rlen > 0 ) { *(rptr++) = (BYTE) 0x00FF; rlen--; }
		}

	/* Remove unecessary Trailing FF bytes */
	/* ----------------------------------- */
	for ( len = 0; len < blen; len++ )
		if ((*(bptr++) = result[len]) == 0x00FF )
			break;
	return( len );

}

EXAWORD	compare_strings( tptr, tlen, sptr, slen )
BPTR	tptr;
EXAWORD	tlen;
BPTR	sptr;
EXAWORD	slen;
{
	if ( tlen != slen )
		return( 0 );

	for ( ; slen != 0; slen-- )
		if ( *(sptr) != *(tptr) )
			return( 0 );
		

	return( 1 );
}


EXAWORD	is_already_known( type, cptr, len )
EXAWORD	type;
BPTR	cptr;
EXAWORD	len;
{
	BPTR	rptr;
	EXAWORD	ri;
	EXAWORD	i;
	EXAWORD	j;

	/* Initialise Search control */
	/* ------------------------- */
	rptr = tcGKT; ri = 0;

	/* Scan till end of new table */
	/* -------------------------- */
	while ( ri < LenOldGkt ) {

		/* Check for BCD or String */
		/* ----------------------- */
		if ( type == 0 )  {

			if ( *(rptr + ri) == 0 ) {
				if ( compare_strings((rptr + ri + 2),*(rptr + ri + 1),cptr, len)) 
					return( ri );

				ri++;
				}
			}
		else	{
			if ( *(rptr + ri) == 0)
				ri++;
			else if ( compare_strings((rptr + ri + 1),*(rptr + ri), cptr, len))
					return( ri );
			}

		ri += (*(rptr + ri) + 1);

		}

	return( MOINS_UN );


}

EXAWORD	create_new_constant( type, len, cptr )
EXAWORD	type;
EXAWORD	len;
BPTR	cptr;
{
	BPTR	tptr;
	EXAWORD	result;
	EXAWORD	i;
	EXAWORD	indent;
	EXAWORD	longueur;

	if ( type == 0 )

		len = compress_bcd( cptr, len );


	/* Test if Constant already exists */
	/* ------------------------------- */
	if ((result = is_already_known(type, cptr, len )) != MOINS_UN)
		return( result );

	/* Attempt to extend the original constant table */
	/* --------------------------------------------- */
	if ((longueur = duplicate_constant_tables( type , len )) == MOINS_UN )
		return( MOINS_UN );

	result = LenOldGkt;
	indent = LenOldGkt;

	LenOldGkt += longueur;

	/* Differenciate Constant Types */
	/* ---------------------------- */
	if ( type == 0 ) {

		/* Generate Bcd Constant */
		/* --------------------- */
		*(tcGKT + (indent++)) = 0; indent++;

		/* Limit to Maximum BCD String Length */
		/* ---------------------------------- */
		if ( len > 12 ) 
			len = 12;	
	

		/* Transfer whilst checking for BCD Terminal Byte */
		/* ---------------------------------------------- */
		for ( i = 0; i < len;  ) {
			if ( *cptr == 0x00FF )
				break;
			i++;
			*(tcGKT + (indent++)) = *cptr;
			if (  (( *cptr & 0x00F0 ) == 0x00F0 ) || (( *cptr & 0x000F ) == 0x000F ) )
				break;
			cptr++; 
			}

		/* Establish Final Constant Length */
		/* ------------------------------- */
		*(tcGKT + (result + 1)) = i;

		}
	else	{
		/* Generate String Constant */
		/* ------------------------ */
		len &= 0x00FF; 
		*(tcGKT + (indent++)) = len;
		memcpy((tcGKT + indent),cptr,len);
		}
	return( result );

}

EXAWORD	ConstantUsefulSize( offset )
EXAWORD	offset;
{
	BPTR	cptr;
	EXAWORD	l;

	cptr = (BPTR) (tcGKT + offset);

	l = *cptr; cptr += l;

	while (( l ) && ( *(cptr++) == ' ' ))
		l--;

	return( l );
}

EXAWORD	ConstantSize( offset )
EXAWORD	offset;
{
	if ( *(tcGKT + offset) )
		return( *(tcGKT + offset) );
	else	return( *(tcGKT + offset + 1) );

}

EXAWORD	is_null_constant( offset )
EXAWORD	offset;
{
	BPTR	cptr;
	EXAWORD	clen;

	/* Calculate constant pointer */
	/* -------------------------- */
	cptr = (tcGKT + offset);

	/* Eliminate string constants */
	/* -------------------------- */
	if (( clen = *(cptr++) ) != 0 ) 
		return( MOINS_UN );

	/* Collect numeric string Length */
	/* ----------------------------- */
	clen = *(cptr++);

	while ( clen != 0 ) {

		if (( *cptr & 0x00F0 ) && (( *cptr & 0x00F0 ) < 0x00A0) )
			return( offset );

		if (( *cptr & 0x000F ) && (( *cptr & 0x000F ) < 0x000A) )
			return( offset );

		cptr++; clen--;
		}

	/* Indicate Effective NULL */
	/* ----------------------- */
	return( MOINS_UN );
}

#endif	/* OPTIMISE_CONSTANT_TABLE */
	/* ----------------------- */

#endif	/* _LABEL_C */
	/* -------- */


