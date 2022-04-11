/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2008 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBSYMB.C 				*/
/*		Date 	:	15/07/2008				*/
/*		Version :	3.2b                     		*/
/*									*/
/*----------------------------------------------------------------------*/
/*
 * Mises a jour :
 * ------------
 * 27/09/02 : (#BG) Modification de locate_correspondance().
 * 15/10/02 : (#BG) Modification de locate_correspondance().
 * 19/02/03 : (#BG) Modification de locate_correspondance().
 *	------------ 2.2b -------------------------------------------------
 */


#ifndef	_EXDBSYMB_C
#define	_EXDBSYMB_C

/*	----------------------------------------------------------	*/
/*	S Y M B O L S 	M A N A G E M E N T	F O R	 E X A D B	*/
/*	----------------------------------------------------------	*/
#ifdef	USEIT
#define	CHECK_PROTO_ARGS
#endif
#include "exos.h"
#include "stdtypes.h"	
#include "exdbstre.h"
#include "exdbsymb.h"
#include "exdbtrap.h"
#include "exdbmimo.h"
#include "allocate.h"
#include "exptr.h"
#include "exword.h"
#include "exdbword.h"
#include "exproto1.h"

#ifdef	OPTIMISEUR
#include "exdbstd.c"
#ifdef	VERSION666
#ifdef	TOGLOBAL
#undef TOGLOBAL
#endif
#ifdef	ISLOCAL
#undef ISLOCAL
#endif
#define	ISLOCAL 	TcodeIsLocal
#define	TOGLOBAL	TcodeToGlobal 
extern	EXAWORD	ISLOCAL;
extern	EXAWORD	TOGLOBAL;
#endif
SYMBOLPTR	CurrentSymbol=(SYMBOLPTR) 0;
#else
#ifndef UNIX
BPTR	exadb_strcpy( BPTR, BPTR );
BPTR	exadb_strcat( BPTR, BPTR );
EXAWORD	systeme( BPTR );
#else
BPTR	exadb_strcpy();
BPTR	exadb_strcat();
EXAWORD	systeme();
#endif
#endif

SYMBOLPTR locate_module_number( EXAWORD number );
EXAWORD	load_module_names();
static VOID	loading_message( BPTR mptr );

#ifdef  UNIX
#ifdef CHECK_PROTO_ARGS
EXAWORD	wildcomp( BPTR, BPTR );
#else
EXAWORD	wildcomp();
#endif
#else  /* NOT UNIX */
EXAWORD	wildcomp( tptr , wptr )
BPTR	tptr;
BPTR	wptr;
{
	EXAWORD	wlen,tlen;

	wlen = exadb_strlen(wptr); tlen = exadb_strlen(tptr);

	while (( tlen > 0 ) && (wlen > 0)) {

		switch ( *wptr ) {
			case '*' : if ( wildcomp( tptr , (wptr + 1)) == 0 ) {
					return(0);
					}
				   tptr++; tlen--;
				   continue; 
			default  : if ( *tptr != *wptr ) { return(1); }
			case '?' : wptr++; tptr++; wlen--; tlen--; continue;
			}
		}
	if (( tlen == 0 ) && ( wlen == 0 )) { return(0); }
	if ( tlen == 0 ) {
		while ( wlen > 0 ) {
			if (( *wptr != '*' ) && ( *wptr != '?' )) { return(1); }
			wlen--; wptr++;
			}
		return(0);
		}
	if (( wlen == 0 ) && ( *(wptr - 1) == '*')) { return(0); }
	return(1);

}
#endif
VOID	exadb_itoa( bptr, nombre )
BPTR	bptr;
EXAWORD	nombre;
{
	EXAWORD	n;
	EXABYTE	chiffres[24];
	EXAWORD	ws;
	if ( nombre == 0 ) 
	{
		*(bptr++) = '0';
		*(bptr++) = 0;
	}
	else	
	{
#ifdef	VERSION666
		if ( WORDSIZE > 2 )
		{
#ifdef	ABAL64
			if ( WORDSIZE > 4 )
				ws = 20;
			else
#endif
				ws = 10;
		}
		else
#endif
			ws = 5;
		for ( n = ws; n > 0; n-- ) 
		{
			chiffres[n] = ((nombre % 10) + 0x0030);
			nombre /= 10;
			if ( nombre == 0 )
				break;
		}
		for ( ; n < (ws+1); n++ )
			*(bptr++) = chiffres[n];
		*(bptr++) = 0;
	}		

	return;
}

/*	------------------	*/
/*	exadb_address_word	*/
/*	------------------	*/
BPTR	exadb_address_word( BPTR bptr, EXAWORD wv )
{
	if ((wv & 0xF000) > 0x9000)
		*(bptr++) = ((((wv & 0xF000) >> 12) - 10) + 'A');
	else	*(bptr++) = (((wv & 0xF000) >> 12) + '0');
	if ((wv & 0x0F00) > 0x0900)
		*(bptr++) = ((((wv & 0x0F00) >> 8) - 10) + 'A');
	else	*(bptr++) = (((wv & 0x0F00) >>  8) + '0');
	if ((wv & 0x00F0) > 0x0090)
		*(bptr++) = ((((wv & 0x00F0) >> 4) - 10) + 'A');
	else	*(bptr++) = (((wv & 0x00F0) >>  4) + '0');
	if ((wv & 0x000F) > 0x0009)
		*(bptr++) = (((wv & 0x000F) - 10) + 'A');
	else	*(bptr++) = ((wv & 0x000F) + '0');
	return(bptr);
}

/*	-------------	*/
/*	exadb_address	*/
/*	-------------	*/
EXAWORD	exadb_address( BPTR bptr, EXAWORD wv)
{
#ifdef	VERSION666
#ifdef	ABAL64
	if ( WORDSIZE > 4 )
	{
		bptr = exadb_address_word(bptr, ((wv >> 48) & 0x00FFFF));
		bptr = exadb_address_word(bptr, ((wv >> 32) & 0x00FFFF));
	}
#endif
	if ( WORDSIZE > 2 )
	{
		bptr = exadb_address_word(bptr, ((wv >> 16) & 0x00FFFF));
	}
#endif
	bptr = exadb_address_word(bptr, (wv & 0x00FFFF));
	*(bptr++) = 0;
	return( WORDSIZE * 2 );
}

VOID	exadb_itoh( bptr, wv )
BPTR	bptr;
EXAWORD	wv;
{
	if ((wv & 0xF000) > 0x9000)
		*(bptr++) = ((((wv & 0xF000) >> 12) - 10) + 'A');
	else	*(bptr++) = (((wv & 0xF000) >> 12) + '0');
	if ((wv & 0x0F00) > 0x0900)
		*(bptr++) = ((((wv & 0x0F00) >> 8) - 10) + 'A');
	else	*(bptr++) = (((wv & 0x0F00) >>  8) + '0');
	if ((wv & 0x00F0) > 0x0090)
		*(bptr++) = ((((wv & 0x00F0) >> 4) - 10) + 'A');
	else	*(bptr++) = (((wv & 0x00F0) >>  4) + '0');
	if ((wv & 0x000F) > 0x0009)
		*(bptr++) = (((wv & 0x000F) - 10) + 'A');
	else	*(bptr++) = ((wv & 0x000F) + '0');
	*(bptr++) = 0;
	return;
}

EXAWORD	unlock_header( fdex )
BPTR	fdex;
{
	EXAWORD	dcrypt;

	switch ( *fdex ) {
#ifdef	ABAL64
		case	'4'	:
#endif
#ifdef	VERSION666
		case	'3'	:
#endif
		case	'1'	:
		case	'2'	:
			dcrypt = TcodeWord16( (fdex + ((21 * WORDSIZE)+(2*BYTESIZE)) + TCPREFIX /* 62 */ ) );
			if (( dcrypt != 0 ) && ( dcrypt != 0xFFFF ))
				(VOID) abal_crypt(dcrypt,(BPTR) (fdex + TCPREFIX),((2*BYTESIZE)+(21*WORDSIZE)),0);
			return( GOODRESULT );			
		default		:
			return( SOFTERROR );
		}
}


/*
 * ----------------------------------------------------
 * reset_symbols_manager
 * ----------------------------------------------------
 */
VOID	reset_symbols_manager()
{
	if (!(DebugSymbols)) return;

	DebugSymbols->modules    = (SYMBOLPTR) 0;
	DebugSymbols->sources    = (SYMBOLPTR) 0;
	DebugSymbols->listes     = (SYMBOLPTR) 0;
	DebugSymbols->globals    = (SYMBOLPTR) 0;
	DebugSymbols->locals     = (SYMBOLPTR) 0;
	DebugSymbols->constants  = (SYMBOLPTR) 0;
	DebugSymbols->procedures = (SYMBOLPTR) 0;
	DebugSymbols->linksymbol = (SYMBOLPTR) 0;
	DebugSymbols->segments   = (SYMBOLPTR) 0;
	DebugSymbols->libraries  = (SYMBOLPTR) 0;
	DebugSymbols->linkage    = (CORRESPTR) 0;
	DebugSymbols->linktype   = EXDB_FFFF;
	DebugSymbols->linkowner  = EXDB_FFFF;	
	DebugSymbols->ldt_sector = 0;
	DebugSymbols->zoom_status= 0;
	DebugSymbols->display_mode = 1;
	DebugSymbols->programme[0] = 0;
	DebugSymbols->config_name[0] = 0;
	reset_message_zone();
#ifdef	VERSION666
	DebugSymbols->ProcNameSelection=(BPTR) 0;
	DebugSymbols->SegmNameSelection=(BPTR) 0;
	DebugSymbols->GlobNameSelection=(BPTR) 0;
	DebugSymbols->LocalNameSelection=(BPTR) 0;
	DebugSymbols->SourceSelection=(BPTR) 0;
	DebugSymbols->LibrarySelection=(BPTR) 0;
#endif
	DebugSymbols->globalcount     = 0;
	DebugSymbols->AtPath = (BPTR) 0;
#ifndef	OPTIMISEUR
	initialise_mouse_manager();
	initialise_streams();
#endif
}

/*
 * ----------------------------------------------------
 * TcGetWord
 * ----------------------------------------------------
 */
EXAWORD	TcGetWord( BPTR bptr )
{
#ifdef	VERSION666
	EXAWORD	result=0;
	if ( WORDSIZE > 2 ) 
	{
		result =  (*(bptr++) & 0X00FF);
		result |= ((*(bptr++) & 0X00FF) << 8);
		result |= ((*(bptr++) & 0X00FF) << 16);
		result |= ((*(bptr++) & 0X00FF) << 24);
#ifdef	ABAL64
		if ( WORDSIZE > 4 )
		{
			result |= ((*(bptr++) & 0X00FF) << 32);
			result |= ((*(bptr++) & 0X00FF) << 40);
			result |= ((*(bptr++) & 0X00FF) << 48);
			result |= ((*(bptr++) & 0X00FF) << 56);
		}
#endif
		return( result );
	}
#endif
	return( ( ( *(bptr+1) * 256) + *bptr ) );
}

/*
 * ----------------------------------------------------
 * initialise_symbolic_file
 * Lecture des headers de l'AT et du DBG
 *   E:	Nom de l'at
 * ----------------------------------------------------
 */
EXAWORD	initialise_symbolic_file( BPTR filename )
{
	EXABYTE		nomfic[256];
	BPTR		interface_message( EXAWORD );
	EXAWORD	secteur;

	if (!( DebugSymbols )) return( FAUX );

	memset((BPTR) DebugSymbols->DbHeader, 'D', TCODEBLOCK);
	memset((BPTR) DebugSymbols->DbHeaderExt, 0xFF, TCODEBLOCK);
	memset((BPTR) DebugSymbols->AtHeader, 'A', TCODEBLOCK);
	memset((BPTR) nomfic, 0, 245);

	fn_parser((BPTR) filename, (BPTR) nomfic, 0x0007 );
	if (!( DebugSymbols->AtPath = (BPTR) allocate( (exadb_strlen( nomfic )+1) ) ))
		return(FAUX);
	else	exadb_strcpy(DebugSymbols->AtPath,nomfic);
	memset((BPTR) nomfic, 0, 245);
	fn_parser((BPTR) filename, (BPTR) nomfic, 0x000F );
	exadb_strcat( (BPTR) nomfic,(BPTR) TCODE_EXTENSION );

	if ( stream_open(_TCODE_STREAM, (BPTR) nomfic,0 ) ) 
	{
		if ( stream_read(_TCODE_STREAM, 0, (BPTR) DebugSymbols->AtHeader, HEADERBLOCK) == HEADERBLOCK) 
		{
			if ( unlock_header( (BPTR) DebugSymbols->AtHeader ) != SOFTERROR ) 
			{
				memset((BPTR) nomfic, 0, 245);
				fn_parser((BPTR) filename, (BPTR) nomfic, 0x000F );
#ifdef WIN32
				/* Si AT produit par ABAL3, alors AtHeader[0x74] vaut 0 ou >0,
					Si AT produit par ABAL2, alors AtHeader[0x74] vaut FF.
				*/
				if ((trad_ver == '2') && (DebugSymbols->AtHeader[0x74] == 0xFF))
					exafb_strcat( (BPTR) nomfic,(BPTR) DEBUG_EXTENSION_WABAL2 );
				else
#endif
					exadb_strcat( (BPTR) nomfic,(BPTR) DEBUG_EXTENSION );

				if ( stream_open( _DEBUG_STREAM, (BPTR) nomfic,2  ) ) 
				{

					if ( stream_read(_DEBUG_STREAM, 0, (BPTR) DebugSymbols->DbHeader, HEADERBLOCK) == HEADERBLOCK) 
					{
						if ( unlock_header( (BPTR) DebugSymbols->DbHeader ) != SOFTERROR ) 
						{
							if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[(54 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) != 0) 
							&&  (secteur != EXDB_FFFF)) 
							{
								if (stream_read(_DEBUG_STREAM, secteur, (BPTR) DebugSymbols->DbHeaderExt, HEADERBLOCK) == HEADERBLOCK) 
								{
									loading_message((BPTR) "Symbolic Information");
									return( GOODRESULT );
								}
							}
							else	
							{
								loading_message((BPTR) "Symbolic Information");
								return( VRAI );
							}
						}
					}
					stream_close( _DEBUG_STREAM );
				}
			}
		}
		stream_close(_TCODE_STREAM);
	}
	return( SOFTERROR );
}

// Table of 32 shift index to ensure the best possible
// repartition of hash value in the range.
//
static int ShiftTable[] =
	{
	 0,  8, 16, 24,  4, 12, 20,  2,
	10, 18,  6, 14, 22,  1,  9, 17,
	23,  3, 11, 19,  5, 21,  7, 15,
	24, 13,  9,  3, 17, 21, 13, 23
	};

EXAWORD	calculate_symbol_hash (BPTR Key) 
{
	register EXAWORD 		Result	= 0;
	register BPTR		 	Str 		= Key;
	register int			Shift 	= 0;

	while (*Str) 
	{
		Result = (Result ^ ((*Str++) << ShiftTable[Shift]) );
		Shift = (Shift+1) & 31;
	}
	return Result;
}

/*
 * ----------------------------------------------------
 * allocate_for_symbol
 * Alloue et initialise avec nom, type et hash
 * ----------------------------------------------------
 */
SYMBOLPTR	allocate_for_symbol( BPTR token, EXAWORD type )
{
	SYMBOLPTR	lsymb;

	if ((lsymb = (SYMBOLPTR) allocate( sizeof(struct symbolic_name) )) != (SYMBOLPTR) 0) 
	{
		if ((lsymb->name = allocate( (exadb_strlen((BPTR) token ) + 1) )) != (BPTR) 0) 
		{
			exadb_strcpy((BPTR) lsymb->name,(BPTR) token);
			lsymb->next		= (SYMBOLPTR) 0;
			lsymb->previous		= (SYMBOLPTR) 0;
			lsymb->nextSameName	= (SYMBOLPTR) -1; 
			lsymb->previousSameName	= (SYMBOLPTR) -1; 
			lsymb->number		= 0;
			lsymb->nature 		= 0; /* Normal */
#ifdef	OPTIMISEUR
			lsymb->newnumber	= 0;
#endif
			lsymb->special	= (VPTR) 0;
			lsymb->signature= (BPTR) 0;
			lsymb->hash 	= calculate_symbol_hash( (BPTR) token );
			lsymb->type 	= type;
			lsymb->moduleowner 	= (SYMBOLPTR) 0; 
		}
		else	
		{
			liberate( lsymb );
			lsymb = (SYMBOLPTR) 0;
		}
	}
#ifdef	WIN16
	if ( lsymb == (SYMBOLPTR) 0) 
	{
extern	void _fastcall AlertBox(BPTR);

		AlertBox((BPTR) "Symbol management error : not enough memory" );
	}
#endif
	return( lsymb );
}

XCODEPTR	allocate_for_code_control( identity )
EXAWORD		identity;
{
	XCODEPTR	lcode;

	if ((lcode = (XCODEPTR) allocate( sizeof( struct code_control ) )) != (XCODEPTR) 0)
	{
		lcode->identity		= identity;
		lcode->code_sector	= 0;
		lcode->code_length	= 0;
		lcode->data_sector	= 0;
		lcode->data_length	= 0;
		lcode->const_sector	= 0;
		lcode->const_length	= 0;
		lcode->infos_sector	= 0;	
		lcode->infos_length	= 0;
		lcode->options		= 0;
	}
#ifdef	WIN16
	if ( lcode == (SYMBOLPTR) 0) 
	{
extern	void _fastcall AlertBox(BPTR);
		AlertBox((BPTR) "Code management error : not enough memory" );
	}
#endif
	return( lcode );
}

/*
 * ----------------------------------------------------
 * allocate_for_extended_control
 * ----------------------------------------------------
 */
XCODEPTR	collect_procedure_infos( identity )
EXAWORD	identity;
{
	XCODEPTR	lcode;
	EXAWORD	secteur;
	EXAWORD	l;

	if (DebugSymbols == 0)
		return (XCODEPTR)0;

	if ((lcode = allocate_for_code_control( identity )) != (XCODEPTR) 0) 
	{

		if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[(9 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) != 0)
		&&  (secteur != EXDB_FFFF)
		&&  (stream_seek( _TCODE_STREAM, (secteur + ((identity & 0xFFFFFF00) >> 8)), (identity & 0x00FF ) ) )) 
		{
			lcode->code_sector  = stream_getw( _TCODE_STREAM );
			lcode->code_length  = stream_getw( _TCODE_STREAM );
			lcode->data_sector  = stream_getw( _TCODE_STREAM );
			lcode->data_length  = stream_getw( _TCODE_STREAM );
			lcode->const_sector = stream_getw( _TCODE_STREAM );
			lcode->const_length = stream_getw( _TCODE_STREAM );
			l		    = stream_getw( _TCODE_STREAM );
			lcode->options	    = stream_getw( _TCODE_STREAM );
		}
	}
	return( lcode );
}

XCODEPTR	collect_segment_infos( identity )
EXAWORD	identity;
{
	XCODEPTR	lcode;
	EXAWORD	secteur;
	EXAWORD	l;

	if (DebugSymbols == 0)
		return (XCODEPTR)0;

	if ((lcode = allocate_for_code_control( identity )) != (XCODEPTR) 0) 
	{
		if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[(7 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) != 0)
		&&  (secteur != EXDB_FFFF)
		&&  (stream_seek( _TCODE_STREAM, (secteur + ((identity & 0xFFFFFF00) >> 8)), (identity & 0x00FF ) ) )) 
		{
			l = stream_getw( _TCODE_STREAM );
			lcode->code_sector  = stream_getw( _TCODE_STREAM );
			lcode->code_length  = stream_getw( _TCODE_STREAM );
			lcode->data_sector  = stream_getw( _TCODE_STREAM );
			lcode->data_length  = stream_getw( _TCODE_STREAM );
			lcode->options	    = stream_getw( _TCODE_STREAM );
			lcode->const_sector = stream_getw( _TCODE_STREAM );
			lcode->const_length = stream_getw( _TCODE_STREAM );
		}
	}
	return( lcode );

}

/*
 * ----------------------------------------------------
 * collect_extended_infos
 * ----------------------------------------------------
 */
XEXTPTR	collect_extended_infos( EXAWORD offset )
{
	XEXTPTR	lext;
	EXAWORD	secteur;
	EXAWORD	longueur;
	EXAWORD	version;
	EXAWORD	nombre;
	EXAWORD i;
	
	if (DebugSymbols == 0)
		return 0;

	if (DebugSymbols->modules == 0)
		return 0;

	lext = 0;

	if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeaderExt[offset] )) != 0)
	&&  (secteur != EXDB_FFFF)
	&&  ((longueur = TcGetWord((BPTR) & DebugSymbols->DbHeaderExt[offset + WORDSIZE] )) != 0)
	&&  (longueur != EXDB_FFFF)
	&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ) )) 
	{
	
		if ( (version = stream_getw( _DEBUG_STREAM )) == _EXTENDED_SECTOR_V1) 
		{
			longueur -= WORDSIZE;
			nombre = longueur / WORDSIZE;
			if ((lext = allocate( nombre * sizeof(struct extended_control))) != 0) 
			{
				for( i=0 ; i<nombre ; i++) 
				{
					lext[i].identity = stream_getw( _DEBUG_STREAM );
				}
			}
		}
	}
	return(lext);

}

/*
 * ----------------------------------------------------
 * generate_segment_name
 * Fabrique un nom de segment à partir de son ID
 * ----------------------------------------------------
 */
VOID	generate_segment_name( BPTR bptr, EXAWORD nombre )
{
	EXAWORD	l;
	exadb_strcpy((BPTR) bptr, (BPTR) "SEGMENT_" );
	l = strlen( bptr );
	exadb_itoa( (BPTR) (bptr + l), nombre );
	return;
}

#ifdef	OPTIMISEUR
EXAWORD	next_segment_info( mptr )
BPTR	mptr;
{
	EXAWORD		l=0;
	SYMBOLPTR	sptr;
	if ((sptr = CurrentSymbol) != (SYMBOLPTR) 0 ) 
	{
		exadb_strcpy((BPTR) mptr, (BPTR) sptr->name );
		l = exadb_strlen( mptr );
		mptr += l;
		*(mptr++) = ' '; l++;
		exadb_itoa((BPTR) mptr, sptr->number );
		l = exadb_strlen( mptr );
		CurrentSymbol = CurrentSymbol->next;
	}
	return( l );
}

EXAWORD	first_segment_info( mptr )
BPTR	mptr;
{
	CurrentSymbol = DebugSymbols->segments;
	return( next_segment_info( mptr ) );
}
#endif

/*
 * ----------------------------------------------------
 * load_segment_names
 * Lecture des infos dans le DBG
 * ----------------------------------------------------
 */
EXAWORD	load_segment_names()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	EXAWORD		c;
	XCODEPTR	lcode;
	EXAWORD		realsegm;
	EXAWORD		special=0;
	SYMBOLPTR	modulesymb = 0;
	EXAWORD		moduleid   = 0;
	XEXTPTR		lext=(XEXTPTR) 0;

	if (!( DebugSymbols )) return (SOFTERROR);

	lext = collect_extended_infos( 4 * WORDSIZE /* offset segments */ );

	if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[(33 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) != 0)
	&&  (secteur != EXDB_FFFF)
	&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))
	&&  (nombre = stream_getw( _DEBUG_STREAM ))
	&&  (nombre != EXDB_FFFF)) 
	{ 
	 

		loading_message((BPTR) "Segment Name Symbols");
		if ((special = TcGetWord((BPTR) & DebugSymbols->DbHeader[(53 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) == EXDB_FFFF )
			special = 0;

		for ( id = 0; id < nombre; id++ ) 
		{

			/* Collect segment name */
			/* -------------------- */
			l = stream_gets( _DEBUG_STREAM,(BPTR) buffer, 256 );

			/* Collect segment identity */
			/* ------------------------ */
			realsegm = stream_getw(_DEBUG_STREAM);

			if ( l == 0 )
				generate_segment_name( (BPTR) buffer, realsegm );

			if ((lsymb = allocate_for_sname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );

			lsymb->number = realsegm;
			lsymb->nature = special;

			/* Module Owner */
			/* ------------ */
			if (lext!=0) 
			{
				if (lext->identity != moduleid) 
				{
					moduleid   = lext->identity;
					modulesymb = locate_module_number( moduleid );
				}
				lext++;
			}
			lsymb->moduleowner = modulesymb;

			/* Add this segment to symbols list */
			/* -------------------------------- */
			if ((lsymb->next = DebugSymbols->segments) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->segments = lsymb;

			/* Collect SEGMENT table offset ID */
			/* ------------------------------- */
			realsegm = stream_getw( _DEBUG_STREAM );

			/* Attempt to allocate code controller */
			/* ----------------------------------- */
			if ((lcode = collect_segment_infos( realsegm )) == (XCODEPTR) 0)
				return( SOFTERROR );
			else	lsymb->special = (VPTR) lcode;
			
			/* Perhaps table des noms des Constants locals */
			/* ------------------------------------------- */
			l = stream_getw( _DEBUG_STREAM );

			/* Adresse table correspondance + longueur */
			/* --------------------------------------- */
			lcode->infos_sector = stream_getw( _DEBUG_STREAM );
			lcode->infos_length = stream_getw( _DEBUG_STREAM );

		}
	}
	return( GOODRESULT );

}

/*
 * ----------------------------------------------------
 * load_procedure_names
 * Lecture des infos dans le DBG
 * ----------------------------------------------------
 */
EXAWORD	load_procedure_names()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	EXAWORD		c;
	EXAWORD		i;
	EXAWORD		rt;
	EXAWORD		special=0;
	BPTR		sptr;
	XCODEPTR	lcode;
	SYMBOLPTR	modulesymb = 0;
	EXAWORD		moduleid   = 0;
	XEXTPTR		lext;

	if (!( DebugSymbols )) return (SOFTERROR);

	lext = collect_extended_infos( 6 * WORDSIZE /* offset procedures */ );

	if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[(11 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) != 0)
	&&  (secteur != EXDB_FFFF)
	&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))
	&&  (nombre = stream_getw( _DEBUG_STREAM ))
	&&  (nombre != EXDB_FFFF)) 
	{

		loading_message((BPTR) "Procedure Name Symbols");
		if ((special = TcGetWord((BPTR) & DebugSymbols->DbHeader[(53 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) == EXDB_FFFF )
			special = 0;

		for ( id = 0; id < nombre; id++ ) 
		{

			/* Collect procedure name */
			/* ---------------------- */
			if ((l = stream_gets( _DEBUG_STREAM, (BPTR) buffer, 256 )) == 0)
				return( SOFTERROR );

			if ((lsymb = allocate_for_pname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( SOFTERROR );

			/* Collect procedure identity */
			/* -------------------------- */
			lsymb->number = stream_getw(_DEBUG_STREAM);
			lsymb->nature = special;

			/* Module Owner */
			/* ------------ */
			if (lext!=0) 
			{
				if (lext->identity != moduleid) 
				{
					moduleid   = lext->identity;
					modulesymb = locate_module_number( moduleid );
				}
				lext++;
			}
			lsymb->moduleowner = modulesymb;

			/* Add this procedure to symbols list */
			/* ---------------------------------- */
			if ((lsymb->next = DebugSymbols->procedures) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->procedures = lsymb;

			/* Attempt to allocate code controller */
			/* ----------------------------------- */
			if ((lcode = collect_procedure_infos( lsymb->number )) == (XCODEPTR) 0)
				return( SOFTERROR );

			lsymb->special = (VPTR) lcode;
			
			/* Perhaps table des noms des Constants locals */
			/* ------------------------------------------- */
			l = stream_getw(_DEBUG_STREAM );

			/* Adresse table correspondance + longueur */
			/* --------------------------------------- */
			lcode->infos_sector = stream_getw( _DEBUG_STREAM );
			lcode->infos_length = stream_getw( _DEBUG_STREAM );

			/* Procedure Parameters count and Return type */
			/* ------------------------------------------ */
			l = stream_getw(_DEBUG_STREAM); 
			rt = ((l & 0x0000FF00) >> 8); l &= 0x00FF;

			/* Attempt to allocate for signature storage */
			/* ----------------------------------------- */
			if ((sptr = (BPTR) allocate( (l+3) )) == (BPTR) 0) 
				return( SOFTERROR );

			lsymb->signature = sptr;

			l |= ((rt & 0x0007) << 8);
			if ( rt & 0x0008 ) 
			{
				rt >>= 4;
				rt |= 0x0080;
			}
			else	rt = 0;
			l++;
			*(sptr++) = (EXABYTE) (l & 0x00FF);
			*(sptr++) = (EXABYTE) ((l & 0xFF00) >> 8);
			*(sptr++) = (EXABYTE) rt;
			l--;
			/* Function Return type then parameter types */
			for (; l != 0; l-- )
				*(sptr++) = stream_getb( _DEBUG_STREAM );
		}
	}
	return( GOODRESULT );
}

EXAWORD	wild_card_check( nptr )
BPTR	nptr;
{
	EXAWORD	nombre=0;
	for ( nombre = 0; *nptr; nptr++ )
		if ((*nptr == '*' ) || (*nptr == '?'))
			nombre++;
	return( nombre );
}

/*
 * ----------------------------------------------------
 * locate_symbol_ex
 * Recherche d'un symbole dans la liste. Prise en compte des homonymes
 * avec création d'un chainage entre eux si IsLinkSameName==1
 * 
 * 	E: lsymb = liste des symboles
 * 	   token = élément recherché
 * 	   IsLinkSameName = prise en compte d'éléments de même nom
 * 	R: pointeur sur le symbole trouvé
 * 	   (c'est le 1er de la liste si IsLinkSameName==1)
 * ----------------------------------------------------
 */
SYMBOLPTR	locate_symbol_ex( SYMBOLPTR lsymb, BPTR token, WORD IsLinkSameName )
{
	EXAWORD		h=0;
	EXAWORD		wildcards=0;
	EXAWORD		IsFound = 0;
	SYMBOLPTR	symbHeadSameName;
	SYMBOLPTR	symbPrev;

	if ((lsymb == (SYMBOLPTR) 0) || (token == (BPTR) 0)) 
		return 0;

	if ((wildcards = wild_card_check((BPTR) token )) == 0)
		h = calculate_symbol_hash((BPTR) token );

	while ( lsymb != (SYMBOLPTR) 0) 
	{
		if (wildcards) 
		{
			if ( wildcomp((BPTR) lsymb->name, (BPTR) token) != MOINS_UN )
				break;
		}
		else if (( lsymb->hash == h ) 
		     &&  ( wildcomp((BPTR) lsymb->name, (BPTR) token) != MOINS_UN))
			break;
		lsymb = lsymb->next;
	}

	if (!(lsymb))
		return 0;

	if (IsLinkSameName) 
	{
		if (lsymb->nextSameName != (SYMBOLPTR)-1)
			return(lsymb);
	}
	else	
	{
		return(lsymb);
	}

	// ------------------------------------------------------------
	// - Recherche d'autres occurences
	// ------------------------------------------------------------

	symbHeadSameName = lsymb;
	symbHeadSameName->previousSameName = 0;
	symbHeadSameName->nextSameName = 0;
	symbPrev = lsymb;

	while (( lsymb = lsymb->next) != (SYMBOLPTR) 0) 
	{
		if (wildcards) 	
		{
			if ( wildcomp((BPTR) lsymb->name, (BPTR) token) != MOINS_UN ) 
			{
				symbPrev->nextSameName = lsymb;
				lsymb->previousSameName = symbPrev;
				lsymb->nextSameName = 0;
				symbPrev = lsymb;
			}
		}
		else if ( lsymb->hash != h )
			continue;
		else if ( wildcomp((BPTR) lsymb->name, (BPTR) token) == MOINS_UN )
			continue;
		else
		{	
			symbPrev->nextSameName = lsymb;
			lsymb->previousSameName = symbPrev;
			lsymb->nextSameName = 0;
			symbPrev = lsymb;
		}
	}
	return(symbHeadSameName);
}

/*
 * ----------------------------------------------------
 * locate_symbol
 * ----------------------------------------------------
 */
SYMBOLPTR	locate_symbol( SYMBOLPTR lsymb, BPTR token )
{
	return locate_symbol_ex(lsymb,token,0);
}

/*
 * ----------------------------------------------------
 * replace_filename_symbol
 * ----------------------------------------------------
 */
VOID	replace_filename_symbol( BPTR	oldname,BPTR newname )
{
	SYMBOLPTR	lsymb;
	return;

	if (DebugSymbols == 0)
		return;

	if (((lsymb = DebugSymbols->sources) != (SYMBOLPTR) 0)
	&&  ((lsymb = locate_symbol( lsymb, oldname )) != (SYMBOLPTR) 0)) 
	{
		if ( lsymb->name != (BPTR) 0)
			liberate( lsymb->name );
		if ((lsymb->name = allocate( (exadb_strlen((BPTR) newname ) + 1) )) != (BPTR) 0)
			exadb_strcpy((BPTR) lsymb->name,(BPTR) newname);
	}
	return;
}

/*
 * ----------------------------------------------------
 * liberate_symbol_list
 * ----------------------------------------------------
 */
VOID	liberate_symbol_list( sptr )
SYMBOLPTR	sptr;
{
	SYMBOLPTR	lsymb;
	while ((lsymb = sptr) != (SYMBOLPTR) 0) 
	{
		sptr = lsymb->next;
		if ( lsymb->name != (BPTR) 0 )
			liberate( lsymb->name );
		if ( lsymb->special != (VPTR) 0 )
			liberate( lsymb->special );
		if ( lsymb->signature != (BPTR) 0 )
			liberate( lsymb->signature );
		liberate( lsymb );
	}
	return;
}

#ifdef	OPTIMISEUR
/*
 * ----------------------------------------------------
 * release_local_variables
 * ----------------------------------------------------
 */
VOID	release_local_variables()
{
	liberate_symbol_list( DebugSymbols->locals );
	DebugSymbols->locals = (SYMBOLPTR) 0;
	return;
}
#endif

VOID	release_correspondances( CORRESPTR linfos )
{
	CORRESPTR	tinfos;
	while ((tinfos = linfos) != (CORRESPTR) 0) 
	{
		linfos = linfos->next;
		liberate( tinfos );
	}
	return; 
}

/*
 * ----------------------------------------------------
 * liberate_symbols_manager
 * ----------------------------------------------------
 */
VOID	liberate_symbols_manager()
{
	if ( DebugSymbols != (DEBUGPTR) 0 ) 
	{
		liberate_symbol_list( DebugSymbols->modules    );
		liberate_symbol_list( DebugSymbols->sources    );
		liberate_symbol_list( DebugSymbols->listes     );
		liberate_symbol_list( DebugSymbols->globals    );
		liberate_symbol_list( DebugSymbols->locals     );
		liberate_symbol_list( DebugSymbols->constants  );
		liberate_symbol_list( DebugSymbols->procedures );
		liberate_symbol_list( DebugSymbols->segments   );
		liberate_symbol_list( DebugSymbols->libraries  );
#ifdef	VERSION666
		if ( DebugSymbols->ProcNameSelection ) 
		{
			liberate(DebugSymbols->ProcNameSelection);
			DebugSymbols->ProcNameSelection=(BPTR) 0;
		}
		if ( DebugSymbols->SegmNameSelection ) 
		{
			liberate(DebugSymbols->SegmNameSelection);
			DebugSymbols->SegmNameSelection=(BPTR) 0;
		}
		if ( DebugSymbols->GlobNameSelection ) 
		{
			liberate(DebugSymbols->GlobNameSelection);
			DebugSymbols->GlobNameSelection=(BPTR) 0;
		}
		if ( DebugSymbols->LocalNameSelection ) 
		{
			liberate(DebugSymbols->LocalNameSelection);
			DebugSymbols->LocalNameSelection=(BPTR) 0;
		}
		if ( DebugSymbols->SourceSelection ) 
		{
			liberate(DebugSymbols->SourceSelection);
			DebugSymbols->SourceSelection=(BPTR) 0;
		}
		if ( DebugSymbols->LibrarySelection ) 
		{
			liberate(DebugSymbols->LibrarySelection);
			DebugSymbols->LibrarySelection=(BPTR) 0;
		}
#endif
		release_correspondances( DebugSymbols->linkage  );

		terminate_streams();
		if ( DebugSymbols->AtPath ) 
		{
			liberate(  DebugSymbols->AtPath );
		}
		reset_symbols_manager();

		liberate( DebugSymbols );

		if (DebugSymbols == InitialDebugSymbols)
			InitialDebugSymbols = 0;	

		DebugSymbols = (DEBUGPTR) 0;
	}
	return;
}

/*
 * ----------------------------------------------------
 * activate_symbols_manager
 *		E:	Nom de l'at sans extension	
 * ----------------------------------------------------
 */
EXAWORD	activate_symbols_manager( BPTR filename )
{
	if (!( DebugSymbols )) return( SOFTERROR );

	if ( filename != (BPTR) 0) 
	{

		exadb_strcpy( (BPTR) DebugSymbols->programme, (BPTR) filename );
		reset_message_zone();

#ifdef	VERSION666
#ifdef	ABAL64
		if ( WORDSIZE > 4 )
		{
			EXDB_FFFF = -1;
		}
		else	
#endif
		if ( WORDSIZE > 2 )
		{
			EXDB_FFFF = 0xFFFFFFFFL;
		}
		else	EXDB_FFFF = 0x0000FFFFL;
#endif

		if  (( initialise_symbolic_file( filename ) ) 
		&&  ( load_module_names() )
		&&  ( load_filename_symbols() )
		&&  ( load_listname_symbols() )
#ifdef	OPTIMISEUR
		&&  ( load_global_variables() )
#endif
		&&  ( load_segment_names()  )
		&&  ( load_procedure_names() )
		&&  ( load_dynamic_libraries()))
			return( VRAI );
	}
#ifdef	OPTIMISEUR
	liberate_symbols_manager();
#endif
	return( SOFTERROR );

}

/*
 * ----------------------------------------------------
 * initialise_symbols_manager
 * ----------------------------------------------------
 */
VOID	initialise_symbols_manager()
{
	if ((DebugSymbols = (DEBUGPTR) allocate( sizeof( struct debug_context ) )) != (DEBUGPTR) 0)
		reset_symbols_manager();
	return;
}

/*	---------------------------------------------------------	*/
/*	S Y M B O L	R E S E A R C H		F U N C T I O N S	*/
/*	---------------------------------------------------------	*/
/*									*/
/*	BY NAME		or	BY NUMBER				*/
/*	---------------------------------------------------------	*/

/*
 * ----------------------------------------------------
 * locate_symbol_number
 * ----------------------------------------------------
 */
SYMBOLPTR	locate_symbol_number( SYMBOLPTR lsymb, EXAWORD number )
{

	for ( ; (lsymb != (SYMBOLPTR) 0); lsymb = lsymb->next)
	{
		if (lsymb->number == number)
			break;
	}
	return( lsymb );
}

/*
 * ----------------------------------------------------
 * locate_procedure_number_ex
 * ----------------------------------------------------
 */
SYMBOLPTR	locate_procedure_number_ex( EXAWORD number , DEBUGPTR mydebugctx )
{
	SYMBOLPTR	lsymb;

	if (( mydebugctx != 0 )
	&& ((lsymb = locate_symbol_number( mydebugctx->procedures , number )) != (SYMBOLPTR) 0))
		return( lsymb );
	else	return( (SYMBOLPTR) 0);
}

/*
 * ----------------------------------------------------
 * locate_procedure_number
 * ----------------------------------------------------
 */
SYMBOLPTR	locate_procedure_number( EXAWORD number )
{
	return locate_procedure_number_ex( number , DebugSymbols );
}

/*
 * ----------------------------------------------------
 * locate_procedure_name_ex
 * ----------------------------------------------------
 */
SYMBOLPTR	locate_procedure_name_ex( BPTR token , DEBUGPTR mydebugctx )
{
	SYMBOLPTR	lsymb;

	if (( mydebugctx != 0 )
	&& ((lsymb = locate_symbol_ex( mydebugctx->procedures , token, 1 )) != (SYMBOLPTR) 0))
		return( lsymb );
	else	return( (SYMBOLPTR) 0);
}

/*
 * ----------------------------------------------------
 * get_procedure_name_ex
 * ----------------------------------------------------
 */
BPTR	get_procedure_name_ex( EXAWORD number, DEBUGPTR mydebugptr )
{
/* Attention: get_procedure_name() prend en paramètre le numéro de procédure
   figurant dans la liste lsymb, ie celui du .dbg (ou .wdg) qui dépend de WORDSIZE
   (0, 10, 20, ... en ABAL2 et 0, 20, 40, ... en ABAL3!)
*/

	SYMBOLPTR	lsymb;

	if ((lsymb = locate_procedure_number_ex( number, mydebugptr )) != (SYMBOLPTR) 0)
		return( (BPTR) lsymb->name );
	else	return( (BPTR) "???" );
}

/*
 * ----------------------------------------------------
 * get_procedure_name
 * ----------------------------------------------------
 */
BPTR	get_procedure_name( EXAWORD number )
{
	return get_procedure_name_ex( number, DebugSymbols );
}

/*
 * ----------------------------------------------------
 * get_procedure_number
 * (FCH03062008 non utilisé)
 * ----------------------------------------------------
EXAWORD	get_procedure_number( BPTR nptr )
{
	SYMBOLPTR	lsymb;

	if ((lsymb = locate_procedure_name( nptr )) != (SYMBOLPTR) 0)
		return( lsymb->number );
	else	return( MOINS_UN );
}
*/

/*
 * ----------------------------------------------------
 * locate_segment_number_ex
 * ----------------------------------------------------
 */
SYMBOLPTR locate_segment_number_ex( EXAWORD number, DEBUGPTR mydebugctx )
{
	SYMBOLPTR	lsymb;

	if (( mydebugctx != 0 )
	&& ((lsymb = locate_symbol_number( mydebugctx->segments , number )) != (SYMBOLPTR) 0))
		return( lsymb );
	else	return( (SYMBOLPTR) 0);
}

/*
 * ----------------------------------------------------
 * locate_segment_number
 * ----------------------------------------------------
 */
SYMBOLPTR locate_segment_number( EXAWORD number )
{
	return locate_segment_number_ex( number, DebugSymbols );
}

/*
 * ----------------------------------------------------
 * locate_segment_name_ex
 * ----------------------------------------------------
 */
SYMBOLPTR locate_segment_name_ex( BPTR token, DEBUGPTR mydebugptr )
{
	SYMBOLPTR	lsymb;

	if (( mydebugptr != 0 )
	&& ((lsymb = locate_symbol_ex( mydebugptr->segments ,(BPTR) token, 1 )) != (SYMBOLPTR) 0))
		return( lsymb );
	else	return( (SYMBOLPTR) 0);
}

/*
 * ----------------------------------------------------
 * get_segment_name_ex
 * ----------------------------------------------------
 */
BPTR	get_segment_name_ex( EXAWORD number, DEBUGPTR mydebugctx )
{
	SYMBOLPTR	lsymb;

	if ((lsymb = locate_segment_number_ex( number, mydebugctx )) != (SYMBOLPTR) 0)
		return( (BPTR) lsymb->name );
	else	return( (BPTR) "???" );
}

/*
 * ----------------------------------------------------
 * get_segment_name
 * ----------------------------------------------------
 */
BPTR	get_segment_name( EXAWORD number )
{
	return get_segment_name_ex( number, DebugSymbols );
}

/*
 * ----------------------------------------------------
 * locate_module_number FCH14112007
 * ----------------------------------------------------
 */
SYMBOLPTR locate_module_number( EXAWORD number )
{
	SYMBOLPTR	lsymb;

	if (( DebugSymbols != 0 )
	&& ((lsymb = locate_symbol_number( DebugSymbols->modules , number )) != (SYMBOLPTR) 0))
		return( lsymb );
	else	return( (SYMBOLPTR) 0);
}

/*
 * ----------------------------------------------------
 * locate_module_name FCH14112007
 * ----------------------------------------------------
 */
SYMBOLPTR locate_module_name( BPTR token )
{
	SYMBOLPTR	lsymb;

	if (( DebugSymbols != 0 )
	&& ((lsymb = locate_symbol( DebugSymbols->modules ,(BPTR) token )) != (SYMBOLPTR) 0))
		return( lsymb );
	else	return( (SYMBOLPTR) 0);
}

/*
 * ----------------------------------------------------
 * get_ownerprocedure_name_ex
 * ----------------------------------------------------
 */
BPTR	get_ownerprocedure_name_ex( EXAWORD number, DEBUGPTR mydebugctx )
{
	SYMBOLPTR	lsymb;

	lsymb = locate_procedure_number_ex( number, mydebugctx );
	
	if ( lsymb && lsymb->moduleowner)
		return lsymb->moduleowner->name;
	else	return( (BPTR) "" );
}

/*
 * ----------------------------------------------------
 * get_ownerprocedure_name
 * ----------------------------------------------------
 */
BPTR	get_ownerprocedure_name( EXAWORD number )
{
	return get_ownerprocedure_name_ex( number, DebugSymbols );
}

/*
 * ----------------------------------------------------
 * get_ownersegment_name_ex
 * ----------------------------------------------------
 */
BPTR	get_ownersegment_name_ex( EXAWORD number, DEBUGPTR mydebugctx )
{
	SYMBOLPTR	lsymb;

	lsymb = locate_segment_number_ex( number, mydebugctx );
	
	if ( lsymb && lsymb->moduleowner)
		return lsymb->moduleowner->name;
	else	return( (BPTR) "" );
}

/*
 * ----------------------------------------------------
 * get_ownersegment_name
 * ----------------------------------------------------
 */
BPTR	get_ownersegment_name( EXAWORD number )
{
	return get_ownersegment_name_ex( number, DebugSymbols );
}

/*
 * ----------------------------------------------------
 * load_module_names
 * Lecture des infos dans le DBG 
 * (doit être appelé AVANT le chargement des procédures,
 * des segments et des variables globales)
 * ----------------------------------------------------
 */
EXAWORD	load_module_names()
{
	EXAWORD		secteur;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;

	if ( DebugSymbols == 0 )
		return (SOFTERROR);

	if (!(secteur = TcGetWord((BPTR) & DebugSymbols->DbHeaderExt[0])))
		return( GOODRESULT );
	else if (secteur == EXDB_FFFF)
		return( GOODRESULT );
	else if (!( stream_seek( _DEBUG_STREAM, secteur, 0 ) ))
		return( GOODRESULT );
	else
	{ 
		loading_message((BPTR) "Module Name Symbols");

		id = stream_getw( _DEBUG_STREAM );
		
		while (id != EXDB_FFFF) 
		{ 
		
			/* Collect module name */
			/* ------------------- */
			if ((l = stream_gets( _DEBUG_STREAM, (BPTR) buffer, 256 )) == 0)
				return( SOFTERROR );

			if ((lsymb = allocate_for_mname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( SOFTERROR );

			/* Collect module identity */
			/* ----------------------- */
			lsymb->number = id;
			
			/* Add this module to symbols list */
			/* ------------------------------- */
			if ((lsymb->next = DebugSymbols->modules) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->modules = lsymb;

			id = stream_getw( _DEBUG_STREAM );
		}
		return( GOODRESULT );
	}
}

/*	----------------------------------------------------------	*/
/*	After this the windows and unix version are very different	*/
/*	----------------------------------------------------------	*/

VOID	reset_message_zone()
{
	exadb_strcpy( (BPTR) DebugSymbols->MessageZone,(BPTR) DebugSymbols->programme );
	return;
}

VOID	configuration_file_name( rptr, rlen )
BPTR	rptr;
EXAWORD	rlen;
{
	if ( exadb_strlen((BPTR) DebugSymbols->config_name) == 0 ) 
	{
		fn_parser((BPTR) DebugSymbols->programme, 
			  (BPTR) DebugSymbols->config_name,
			  0x000F);
		exadb_strcat((BPTR) DebugSymbols->config_name,(BPTR) ".dbc" );
	}
	if ( exadb_strlen( (BPTR) DebugSymbols->config_name ) < rlen )
		exadb_strcpy((BPTR) rptr, (BPTR) DebugSymbols->config_name );
	else	memset( (BPTR) rptr, 0, rlen );
	return;
}


/*
 *	A C T I V A T E _ S Y M B O L S _ M A N A G E R
 *	-----------------------------------------------
 *
 */

static VOID	loading_message( BPTR	mptr )
{
/* #ifndef	OPTIMISEUR
	db_xcprintf((BPTR) mptr ); db_xcprintf((BPTR) "\r\n");
#endif
*/
	return;
}

CORRESPTR	allocate_for_linkage()
{
	CORRESPTR	llink;
	if (( llink = (CORRESPTR) allocate( sizeof( struct source_link ))) != (CORRESPTR) 0) 
	{
		llink->tcode_offset	= EXDB_FFFF;
		llink->file_number	= EXDB_FFFF;
		llink->nature		= 0; /* Normal */
		llink->level		= 0;
		llink->file_offset	= (EXALONG) -1L;
		llink->next		= (CORRESPTR) 0;
		llink->previous		= (CORRESPTR) 0;
	}
#ifdef	WIN16
	if ( llink == (SYMBOLPTR) 0) 
	{
extern	void _fastcall AlertBox(BPTR);
		AlertBox((BPTR) "Linkage management error : not enough memory" );
	}
#endif
	return( llink );
}

EXAWORD	load_global_variables()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	SYMBOLPTR	headsymb=(SYMBOLPTR)0;
	SYMBOLPTR	footsymb=(SYMBOLPTR)0;
	EXAWORD		id;
	if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[(3 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) != 0)
	&&  (secteur != EXDB_FFFF)) 
	{
		if (( stream_seek( _TCODE_STREAM, secteur, 0 ) )
		&&  ((nombre = stream_getw( _TCODE_STREAM )) != 0)
		&&  (nombre != EXDB_FFFF)
		&&  ((secteur = stream_getw( _TCODE_STREAM )) != 0)
		&&  (secteur != EXDB_FFFF)
		&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))) 
		{
			DebugSymbols->globalcount = nombre;
			loading_message((BPTR) "Global Variable Symbols");
			while ( 1 ) 
			{
				if ((l = stream_gets( _DEBUG_STREAM,(BPTR) buffer, 256)) == 0)
					break;
				id = stream_getw(_DEBUG_STREAM );
				if ((lsymb = allocate_for_vname( (BPTR) buffer )) == (SYMBOLPTR) 0)
					break;
				lsymb->number = id;
				lsymb->next = (SYMBOLPTR) 0;
				if ((lsymb->previous = footsymb) != (SYMBOLPTR) 0)
					footsymb->next = lsymb;
				else	headsymb = lsymb;
				footsymb = lsymb;
				nombre--;
			}
			DebugSymbols->globals = headsymb;
		}
	}
	return( VRAI );
}

VOID	check_global_variables()
{
	if (!( DebugSymbols->globals ))
		load_global_variables();
}

EXAWORD	load_filename_symbols()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	if (!(secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[(40 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])))
		return( VRAI );
	else if (secteur == EXDB_FFFF)
		return( VRAI );
	else if (!( stream_seek( _DEBUG_STREAM, secteur, 0 ) )) 
		return( VRAI );
	else
	{ 
		loading_message((BPTR) "Filename Symbols");
		while (((nombre = stream_getw( _DEBUG_STREAM )) != 0) && (nombre != EXDB_FFFF)) 
		{
			if ((l = stream_gets(_DEBUG_STREAM, (BPTR) buffer, 256 )) == 0)
				return( FAUX );
			normalise_debug_source( buffer, 256, DebugSymbols->AtPath );
			if ((lsymb = allocate_for_fname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );
			lsymb->number = nombre;
			if ((lsymb->next = DebugSymbols->sources) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->sources = lsymb;
		}
		return( VRAI );
	}
}


EXAWORD	load_listname_symbols()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	if (!(secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[(23 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])))
		return( VRAI );
	else if (secteur == EXDB_FFFF)
		return( VRAI );
	else if (!(stream_seek( _DEBUG_STREAM, secteur, 0 ))) 
		return( VRAI );
	else
	{ 
		loading_message((BPTR) "Listname Symbols");
		while ((l = stream_gets(_DEBUG_STREAM, (BPTR) buffer, 256 )) != 0) 
		{
			if ((lsymb = allocate_for_fname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );
			lsymb->number = nombre;
			if ((lsymb->next = DebugSymbols->listes) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->listes = lsymb;
		}
		return( VRAI );
	}
}

EXAWORD	load_dynamic_libraries()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	EXAWORD		c;
	EXAWORD		n;
	if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[(24 * WORDSIZE) + (2*BYTESIZE) + TCPREFIX])) != 0)
	&&  (secteur != EXDB_FFFF)
	&&  (stream_seek( _TCODE_STREAM, secteur, 0 ))) 
	{ 
		loading_message((BPTR) "Dynamic Library Symbols");
		nombre = stream_getw( _TCODE_STREAM );
		for ( id = 0; id < nombre; id++ ) 
		{
			if ((l = stream_gets( _TCODE_STREAM, (BPTR) buffer, 256 )) == 0)
				return( FAUX );
			if ((lsymb = allocate_for_lname((BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );
			lsymb->number = id;
			if ((lsymb->next = DebugSymbols->libraries) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->libraries = lsymb;
			l = stream_getw( _TCODE_STREAM );
			n = (18 - WORDSIZE);
			for ( l = 0; l < n; l ++ )
				c = stream_getb( _TCODE_STREAM );

		}
	}
	return( VRAI );
}

VOID	check_global_load()
{
	if (DebugSymbols->globals == (SYMBOLPTR) 0)
		load_global_variables();
	return;
}

VOID	initial_symbols_manager()
{
	InitialDebugSymbols = DebugSymbols;
	return;
}

VOID	symbolic_detachment( attdebug )
DEBUGPTR	attdebug;
{
	DEBUGPTR	MasterDebug=DebugSymbols;

	if ((DebugSymbols = attdebug) != (DEBUGPTR) 0 ) 
	{
#ifndef	OPTIMISEUR
		liberate_overlay_traps();
#endif
		liberate_symbols_manager();
	}
	DebugSymbols = MasterDebug;
	return;
}

VOID	force_debug_context( dbgptr )
DEBUGPTR	dbgptr;
{
	if ( dbgptr != (DEBUGPTR) 0 )
		DebugSymbols = dbgptr;
	else	DebugSymbols = InitialDebugSymbols;
	return;
}

DEBUGPTR	active_debug_context()
{
	return( DebugSymbols );
}


VPTR	symbolic_attachment( filename )
BPTR	filename;
{
	DEBUGPTR	MasterDebug=DebugSymbols;
	DEBUGPTR	AttachDebug=(DEBUGPTR) 0;
	VOID		liberate_symbols_manager();

	if ( filename != (BPTR) 0 ) 
	{

		DebugSymbols = (DEBUGPTR) 0;

		initialise_symbols_manager();

		if ((AttachDebug = DebugSymbols) != (DEBUGPTR) 0 ) 
		{

			exadb_strcpy( (BPTR) DebugSymbols->programme, (BPTR) filename );
			reset_message_zone();
			
			if ((!( initialise_symbolic_file((BPTR) filename ))) 
			||  (!( load_filename_symbols()))
			||  (!(  load_procedure_names()))) 
			{
				liberate_symbols_manager();
				AttachDebug = (DEBUGPTR) 0;
			}	
		}
	}
	DebugSymbols = MasterDebug;
	return((VPTR) AttachDebug );
}

SYMBOLPTR	locate_variable_name( token )
BPTR		token;
{
	SYMBOLPTR	lsymb;

	if (!( DebugSymbols ))
		return( (SYMBOLPTR) 0 );
	else if ((lsymb = locate_symbol( DebugSymbols->locals, (BPTR) token )) == (SYMBOLPTR) 0)
		lsymb = locate_symbol( DebugSymbols->globals, (BPTR) token );
	return( lsymb );
}


SYMBOLPTR	locate_variable_number( number )
EXAWORD		number;
{
	if (!( DebugSymbols ))
		return( (SYMBOLPTR) 0 );
	else	return( locate_symbol_number( (number & ISLOCAL ? DebugSymbols->locals : DebugSymbols->globals ), number ) );
}

SYMBOLPTR	locate_procedure_name( token )
BPTR		token;
{
	if (!( DebugSymbols ))
		return( (SYMBOLPTR) 0 );
	else 	return( locate_symbol( DebugSymbols->procedures , token ) );
}

EXAWORD	get_procedure_number( nptr )
BPTR	nptr;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = locate_procedure_name( nptr )) != (SYMBOLPTR) 0)
		return( lsymb->number );
	else	return( EXDB_FFFF );
}

EXAWORD	get_variable_number( nptr )
BPTR	nptr;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = locate_variable_name((BPTR) nptr )) != (SYMBOLPTR) 0)
		return( lsymb->number );
	else	return( 0 );
}

BPTR	get_variable_name( number )
EXAWORD	number;
{
	SYMBOLPTR	lsymb;
	if (( DebugSymbols != (DEBUGPTR) 0 )
	&&  ((lsymb = locate_variable_number( number )) != (SYMBOLPTR) 0))
		return( (BPTR) lsymb->name );
#ifndef	OPTIMISEUR
	else	return( (BPTR) "{V}" );
#else
	else	return( (BPTR) 0 );
#endif
}

SYMBOLPTR	connect_global_symbols()
{
	if ( DebugSymbols )
		return( DebugSymbols->globals );
	else	return( (SYMBOLPTR) 0 );
}

SYMBOLPTR	connect_local_symbols()
{
	if ( DebugSymbols )
		return( DebugSymbols->locals );
	else	return( (SYMBOLPTR) 0 );
}


SYMBOLPTR	connect_segment_symbols()
{
	if ( DebugSymbols )
		return( DebugSymbols->segments );
	else	return( (SYMBOLPTR) 0 );
}


EXAWORD	resolve_global_variable( nptr )
BPTR	nptr;
{
	SYMBOLPTR	lsymb;

	if ((lsymb = locate_symbol( DebugSymbols->globals,(BPTR) nptr )) != (SYMBOLPTR) 0)
		return( lsymb->number );
	else	return( 0 );
}

EXAWORD	resolve_local_variable( nptr )
BPTR	nptr;
{
	SYMBOLPTR	lsymb;

	if ((lsymb = locate_symbol( DebugSymbols->locals, (BPTR) nptr )) != (SYMBOLPTR) 0)
		return( lsymb->number );
	else	return( 0 );
}

SYMBOLPTR	locate_source_name( token )
BPTR		token;
{
	return( locate_symbol( DebugSymbols->sources , token ) );
}

SYMBOLPTR	locate_source_number( number )
EXAWORD		number;
{
	return( locate_symbol_number( DebugSymbols->sources , number ) );
}

SYMBOLPTR	locate_segment_name( token )
BPTR		token;
{
	return( locate_symbol( DebugSymbols->segments ,(BPTR) token ) );
}

SYMBOLPTR	locate_any_symbol( token )
BPTR		token;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = locate_variable_name((BPTR) token)) == (SYMBOLPTR) 0)
		if ((lsymb = locate_procedure_name((BPTR) token)) == (SYMBOLPTR) 0)
			if ((lsymb = locate_segment_name((BPTR) token)) == (SYMBOLPTR) 0)
				lsymb = locate_source_name((BPTR) token);
	return( lsymb );
}

BPTR	get_local_name( vid )
EXAWORD	vid;
{
	return( get_variable_name( (vid | ISLOCAL) ) );
}

BPTR	get_global_name( vid )
EXAWORD	vid;
{
	return( get_variable_name( (vid & TOGLOBAL) ) );
}

SYMBOLPTR	load_local_variables( lsymb )
SYMBOLPTR	lsymb;
{
	SYMBOLPTR	LocalList=(SYMBOLPTR) 0;
	SYMBOLPTR	xsymb=(SYMBOLPTR) 0;
	XCODEPTR	lcode=(XCODEPTR) 0;
	EXAWORD		nombre=0;
	EXAWORD		secteur=0;
	EXABYTE		buffer[256];
	EXAWORD		l;

	if ((lsymb != (SYMBOLPTR) 0)
	&&  ((lcode = (XCODEPTR) lsymb->special) != (XCODEPTR) 0)) 
	{
		/* Collect LDT and LNT for this code block */
		/* --------------------------------------- */
		if ((lcode->data_sector != 0)
		&&  (lcode->data_sector != EXDB_FFFF)
		&&  ( stream_seek( _TCODE_STREAM, (DebugSymbols->ldt_sector = lcode->data_sector), 0 ))
		&&  (( nombre = stream_getw( _TCODE_STREAM )))
		&&  (  nombre != EXDB_FFFF )
		&&  (( secteur = stream_getw( _TCODE_STREAM )))
		&&  (  secteur != EXDB_FFFF )
		&&  ( stream_seek( _DEBUG_STREAM, secteur, 0 ) ) ) 
		{
			LocalList = (SYMBOLPTR) 0;
			/* Collect LOCAL NAME SYMBOLS */
			/* -------------------------- */
			while ( nombre ) 
			{
				if ((l = stream_gets( _DEBUG_STREAM, (BPTR) buffer, 256 )) == 0 ) 
				{
					liberate_symbol_list( LocalList ); 
					return((SYMBOLPTR) 0);
				}
				if ((xsymb = allocate_for_vname( (BPTR) buffer )) == (SYMBOLPTR) 0) 
				{
					liberate_symbol_list( LocalList ); 
					return((SYMBOLPTR) 0);
				}
				xsymb->number = stream_getw( _DEBUG_STREAM );
				xsymb->number |= ISLOCAL;
				if ((xsymb->next = LocalList) != (SYMBOLPTR) 0)
					xsymb->next->previous = xsymb;
				LocalList = xsymb;
				nombre--;
			}
			return( LocalList );
		}
	}
	return( (SYMBOLPTR) 0);

}

VOID	collect_local_variables( segproc, identity )
EXAWORD	segproc;
EXAWORD	identity;
{
	SYMBOLPTR	lsymb;
	if ( segproc )
		lsymb = locate_procedure_number( identity );
	else	lsymb = locate_segment_number( identity );

	if ( lsymb != (SYMBOLPTR) 0 ) 
	{
		liberate_symbol_list( DebugSymbols->locals );
		DebugSymbols->locals = load_local_variables( lsymb );
	}
	return;
}


/*
 *	L I B E R A T E _ S Y M B O L S _ M A N A G E R
 *	-----------------------------------------------
 *
 */

EXTERN EXAWORD fsame;
CORRESPTR	collect_correspondances(lsymb)
SYMBOLPTR	lsymb;
{
	CORRESPTR	linfos=(CORRESPTR) 0;
	CORRESPTR	xinfos=(CORRESPTR) 0;
	CORRESPTR	ninfos=(CORRESPTR) 0;
	EXAWORD		nbfic;
#ifdef CHECK_PROTO_ARGS
	EXALONG		stream_getl( EXAWORD );
#else
	EXALONG		stream_getl();
#endif
	XCODEPTR	lcode;
	EXAWORD		sector;

	/* Set redraw flag */
	fsame = EXDB_FFFF;

	/* Establish Source Stream[1] as Debug File Correspondance table */
	/* for this procedure or Segment 				 */
	/* ------------------------------------------------------------- */
	if ( (lsymb != (SYMBOLPTR) 0)
	&&   ((lcode = (XCODEPTR) lsymb->special) != (XCODEPTR) 0)
	&&   ((sector = lcode->infos_sector) != 0)
	&&   ( sector != EXDB_FFFF )
	&&   ( stream_seek( _DEBUG_STREAM, sector, 0 ) )) 
	{
		/* Remove 4 zero words in header and ignore ????? */
		/* ---------------------------------------------- */
		nbfic = stream_getw(_DEBUG_STREAM);
		nbfic = stream_getw(_DEBUG_STREAM);
		nbfic = stream_getw(_DEBUG_STREAM);
		nbfic = stream_getw(_DEBUG_STREAM);

		while ((nbfic = stream_getw(_DEBUG_STREAM)) != EXDB_FFFF) 
		{
			if ((xinfos = allocate_for_linkage()) == (CORRESPTR) 0) 
			{
				release_correspondances( linfos );
				linfos = xinfos;
				break;
			}
			xinfos->file_number  = nbfic;
			if ((xinfos->nature = lsymb->nature) == 0 ) 
			{
				xinfos->file_offset  =  stream_getw(_DEBUG_STREAM);
				xinfos->file_offset |= (stream_getw(_DEBUG_STREAM) << 16);
			}
			else	
			{
				xinfos->file_offset  = (EXALONG) stream_getw(_DEBUG_STREAM);
				xinfos->level   = stream_getw(_DEBUG_STREAM);
			}
			xinfos->tcode_offset = stream_getw(_DEBUG_STREAM);
			if ( linfos == (CORRESPTR) 0)
				linfos = xinfos;
			else	
			{
				ninfos->next = xinfos;
				xinfos->previous = ninfos;
			}	
			ninfos = xinfos;
		}
	}
	return( linfos );
}

VOID	forget_correspondances()
{
	release_correspondances( DebugSymbols->linkage );
	DebugSymbols->linkage   = (CORRESPTR) 0;
	DebugSymbols->linktype  = EXDB_FFFF;
	DebugSymbols->linkowner = EXDB_FFFF;
	DebugSymbols->linksymbol=(SYMBOLPTR) 0;
	return;
}

CORRESPTR	locate_correspondance( lsymb, offset )
SYMBOLPTR	lsymb;
EXAWORD		offset;
{
	CORRESPTR	litems;
	
	/* Check for renewal of current correspondances required due to */
	/* a change in code block or non actually active		*/
	/* ------------------------------------------------------------ */
	if ((DebugSymbols->linktype  != lsymb->type)
	||  (DebugSymbols->linkowner != lsymb->number)) 
	{
		forget_correspondances();
		if ((DebugSymbols->linkage = collect_correspondances( lsymb )) != (CORRESPTR) 0) 
		{
			DebugSymbols->linktype  = lsymb->type;
			DebugSymbols->linkowner = lsymb->number;
		}
#ifndef	OPTIMISEUR
		else	
		{
			standard_error("error collecting correspondances");				
		}
#endif
	}

	/* Attempt to locate the nearest source correspondance for the 	*/
	/* current provided tcode program offset 			*/
	/* ------------------------------------------------------------ */
	if (( litems = DebugSymbols->linkage) != (CORRESPTR) 0) 
	{
		do	
		{
			if ( litems->tcode_offset == offset )
				break;
		}
		while (( litems = litems->next) != (CORRESPTR) 0);
	}

	/* Return selected correspondance item */
	/* ----------------------------------- */ 
	return( litems );
	
}


#ifdef	OPTIMISEUR

VOID	collect_correspondance_labels( mode, identity )
EXAWORD	mode;
EXAWORD	identity;
{
	SYMBOLPTR	lsymb;
	CORRESPTR	linfos;
	
	forget_correspondances();

	if ((lsymb = locate_symbol_number(( mode == 1 ? DebugSymbols->procedures : DebugSymbols->segments ), identity )) != (SYMBOLPTR) 0) 
	{
		if ((linfos =  collect_correspondances( lsymb )) != (CORRESPTR) 0 ) 
		{
			DebugSymbols->linkage = linfos;
			DebugSymbols->linktype  = lsymb->type;
			DebugSymbols->linkowner = lsymb->number;
			DebugSymbols->linksymbol= lsymb;
		}
	}
	return;
}


VOID	rewrite_variable_names( lsymb, sector )
SYMBOLPTR	lsymb;
EXAWORD		sector;
{
	if ((lsymb != (SYMBOLPTR) 0)
	&&  ( sector != 0 )
	&&  ( sector != EXDB_FFFF )
	&&  ( stream_seek_for_write( _DEBUG_STREAM, sector, 0 ) )) 
	{
		do	
		{
			stream_putzs(_DEBUG_STREAM, (BPTR) lsymb->name );
			stream_putw( _DEBUG_STREAM, lsymb->newnumber   );
		}
		while ((lsymb = lsymb->next) != (SYMBOLPTR) 0);
		stream_putb(_DEBUG_STREAM, 0);
		stream_padd(_DEBUG_STREAM, 0x00FF );
	}
	return;
}
	
VOID	rewrite_local_variables( secteur )
EXAWORD	secteur;
{
	if ( DebugSymbols != (DEBUGPTR) 0 ) {
		rewrite_variable_names( DebugSymbols->locals, secteur );
		release_local_variables();
		}
	return;
}	

VOID	rewrite_global_variables( secteur )
EXAWORD	secteur;
{
	if ( DebugSymbols != (DEBUGPTR) 0 )
		rewrite_variable_names( DebugSymbols->globals, secteur );
	return;
}


VOID	rewrite_correspondances()
{
	CORRESPTR	linfos;
	SYMBOLPTR	lsymb;
	XCODEPTR	lcode;
	EXAWORD		sector;
	if (( DebugSymbols != (DEBUGPTR) 0 )
	&&  (((linfos = DebugSymbols->linkage) != (CORRESPTR) 0)
	&&   ((lsymb = DebugSymbols->linksymbol)!= (SYMBOLPTR) 0)
	&&   ((lcode = (XCODEPTR) lsymb->special) != (XCODEPTR) 0)
	&&   ((sector = lcode->infos_sector) != 0)
	&&   ( sector != EXDB_FFFF )
	&&   ( stream_seek_for_write( _DEBUG_STREAM, sector, 0 ) ))) 
	{
		/* ADD    4 zero words in header and ignore ????? */
		/* ---------------------------------------------- */
		stream_putw(_DEBUG_STREAM,0);
		stream_putw(_DEBUG_STREAM,0);
		stream_putw(_DEBUG_STREAM,0);
		stream_putw(_DEBUG_STREAM,0);

		do	
		{
			stream_putw( _DEBUG_STREAM, linfos->file_number );
			stream_putl( _DEBUG_STREAM, linfos->file_offset );
			stream_putw( _DEBUG_STREAM, linfos->tcode_offset);
		}
		while ((linfos = linfos->next) != (CORRESPTR) 0);
		stream_padd(_DEBUG_STREAM, 0x00FF );

	}
	return;
}

VOID	rellocate_correspondance_labels()
{
	CORRESPTR	linfos;
	EXAWORD		nombre=0;	
	EXAWORD	result;
	if (( DebugSymbols != (DEBUGPTR) 0 )
	&&  ((linfos = DebugSymbols->linkage) != (CORRESPTR) 0)) 
	{
		/* Rellocate all know correspondancies */
		/* ----------------------------------- */
		do	
		{
			if ((result = relocate_newline( linfos->tcode_offset )) != linfos->tcode_offset) 
			{
				linfos->tcode_offset = result;
				nombre++;
			}
		}
		while ((linfos =linfos->next) != (CORRESPTR) 0);

		/* Re-write the correspondances to the DEBUG file */
		/* ---------------------------------------------- */
		if ( nombre )
			rewrite_correspondances();

		/* Release correspondance list */
		/* --------------------------- */
		forget_correspondances();
	}
	return;
}

VOID	relocate_symbolic_variable( oldid, newid )
EXAWORD	oldid;
EXAWORD	newid;
{
	SYMBOLPTR	lsymb;

	if (( DebugSymbols != (DEBUGPTR) 0 )
	&& ((lsymb = locate_symbol_number((oldid & ISLOCAL ? DebugSymbols->locals : DebugSymbols->globals), oldid )) != (SYMBOLPTR) 0))
		lsymb->newnumber = (newid | (oldid & ISLOCAL));
	return;
}

#else	/* ! OPTIMISER */

VOID	trap_all_procedures( mode, absel )
EXAWORD	mode;
EXAWORD	absel;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = DebugSymbols->procedures) != (SYMBOLPTR) 0) 
	{
		do	
		{
			posepiege(lsymb->number,0,mode,absel,(BPTR) 0);
		}
		while ((lsymb = lsymb->next) != (SYMBOLPTR) 0);
	}
	return;
}

VOID	trap_all_segments( mode, absel )
EXAWORD	mode;
EXAWORD	absel;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = DebugSymbols->segments) != (SYMBOLPTR) 0) 
	{
		do	
		{
			posepiege(lsymb->number,0,mode,absel,(BPTR) 0);
		}
		while ((lsymb = lsymb->next) != (SYMBOLPTR) 0);
	}
	return;
}


#endif

BPTR	program_owner()
{
	return((BPTR) DebugSymbols->programme );
}

#ifdef ABAL21
#ifndef	OPTIMISEUR
EXAWORD	resolve_trap_file_position( TRAPTR ltrap, EXAWORD block, EXAWORD offset, EXAWORD type )
{
	CORRESPTR	linfos;
	CORRESPTR	resolve_correspondance(EXAWORD,EXAWORD,EXAWORD);
	if (!( ltrap ))
		return(0);
	else	
	{
		ltrap->file_number = 0;
		ltrap->file_line   = 0;
		if (!( linfos = resolve_correspondance( type,(type ?  (block * (8*WORDSIZE)) : block ), offset ) ))
			return(0);
		else	
		{
			ltrap->file_number = linfos->file_number;
			ltrap->file_line   = linfos->file_offset;		
			return(1);
		}
	}
}


BPTR get_code_name_by_ptr(BPTR ptr,EXAWORD len)
{
BPTR code_name=(BPTR)0;
EXAWORD code_id;
DEBUGPTR save_DebugSymbols;
EXAWORD	get_procid_by_ptr(BPTR);

	if((*ptr==PROGRAM_POINTER||*ptr==SEGMENT_POINTER
	  ||*ptr==PROCEDURE_POINTER)&&(len==PTRSIZE))
	{
		switch(*ptr)
	   	{
		case PROGRAM_POINTER:	/* 0x85 */
			 save_DebugSymbols=DebugSymbols;
			 code_id= get_procid_by_ptr(ptr);
			 if(code_id != EXDB_FFFF)
				code_name= (BPTR)get_procedure_name(code_id);					       
			 DebugSymbols= save_DebugSymbols; 
			 break;

		case SEGMENT_POINTER:	/* 0x09 */
			 code_id= (EXAWORD)balgetw(ptr+3);
			 if(code_id <= 256)
			        code_name= (BPTR)get_segment_name(code_id);					       
			 break;	

		case PROCEDURE_POINTER:		/* 0x05 */
  		    	 code_id= (EXAWORD)balgetw(ptr+3);
			 if(code_id <=0xFFF0)
			        code_name= (BPTR)get_procedure_name(code_id);					      
	  	         break;
	   	}
	}
	return((BPTR) code_name);
}
#endif
#endif

#endif	/* _EXDBSYMB_C */
	/* ----------- */

