/* ---------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBSYMB.C 				*/
/*		Date 	:	19/09/1996				*/
/*		Version :	2.1c                     		*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBSYMB_C
#define	_EXDBSYMB_C

/*	----------------------------------------------------------	*/
/*	S Y M B O L S 	M A N A G E M E N T	F O R	 E X A D B	*/
/*	----------------------------------------------------------	*/
#include "exos.h"
#include "stdtypes.h"	
#include "exdbstre.h"
#include "exdbsymb.h"
#include "exdbmimo.h"
#include "allocate.h"
#include "exptr.h"
#include "exword.h"
#include "exproto1.h"

#ifdef	OPTIMISEUR
#include "exdbstd.c"
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
			default  : if ( *tptr != *wptr ) { return(0xFFFF); }
			case '?' : wptr++; tptr++; wlen--; tlen--; continue;
			}
		}
	if (( tlen == 0 ) && ( wlen == 0 )) { return(0); }
	if ( tlen == 0 ) {
		while ( wlen > 0 ) {
			if (( *wptr != '*' ) && ( *wptr != '?' )) { return(0xFFFF); }
			wlen--; wptr++;
			}
		return(0);
		}
	if (( wlen == 0 ) && ( *(wptr - 1) == '*')) { return(0); }
	return(0xFFFF);

}
#endif
VOID	exadb_itoa( bptr, nombre )
BPTR	bptr;
EXAWORD	nombre;
{
	EXAWORD	n;
	EXABYTE	chiffres[6];
	if ( nombre == 0 ) {
		*(bptr++) = '0';
		*(bptr++) = 0;
		}
	else	{
		for ( n = 5; n > 0; n-- ) {
			chiffres[n] = ((nombre % 10) + 0x0030);
			nombre /= 10;
			if ( nombre == 0 )
				break;
			}
		for ( ; n < 6; n++ )
			*(bptr++) = chiffres[n];
		*(bptr++) = 0;
		}		

	return;
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

/*
 *	I N I T I A L I S E _ S Y M B O L S _ M A N A G E R
 *	---------------------------------------------------
 *
 */

VOID	reset_message_zone()
{
	exadb_strcpy( (BPTR) DebugSymbols->MessageZone,(BPTR) DebugSymbols->programme );
	return;
}

VOID	configuration_file_name( rptr, rlen )
BPTR	rptr;
EXAWORD	rlen;
{
	if ( exadb_strlen((BPTR) DebugSymbols->config_name) == 0 ) {
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

VOID	reset_symbols_manager()
{
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
	DebugSymbols->linktype   = MOINS_UN;
	DebugSymbols->linkowner  = MOINS_UN;	
	DebugSymbols->ldt_sector = 0;
	DebugSymbols->zoom_status= 0;
	DebugSymbols->display_mode = 1;
	DebugSymbols->programme[0] = 0;
	DebugSymbols->config_name[0] = 0;
	reset_message_zone();
#ifndef	OPTIMISEUR
	initialise_mouse_manager();
	initialise_streams();
#endif
}

VOID	initialise_symbols_manager()
{
	if ((DebugSymbols = (DEBUGPTR) allocate( sizeof( struct debug_context ) )) != (DEBUGPTR) 0)
		reset_symbols_manager();
	return;
}

EXAWORD	TcGetWord( bptr )
BPTR	bptr;
{
	return( ( ( *(bptr+1) * 256) + *bptr ) );
}


VOID	unlock_header( fdex )
BPTR	fdex;
{
	EXAWORD	dcrypt;

	dcrypt = TcGetWord( (fdex + 62 ) );

	if (( dcrypt != 0 ) && ( dcrypt != MOINS_UN ))
		(VOID) exa_crypt(dcrypt,(BPTR) (fdex + 18),44,0);
	return;
}

/*
 *	A C T I V A T E _ S Y M B O L S _ M A N A G E R
 *	-----------------------------------------------
 *
 */

static VOID	loading_message( mptr )
BPTR	mptr;
{
/* #ifndef	OPTIMISEUR
	db_xcprintf((BPTR) mptr ); db_xcprintf((BPTR) "\r\n");
#endif
*/
	return;
}

EXAWORD	initialise_symbolic_file( filename )
BPTR	filename;
{
	EXABYTE		nomfic[256];
	BPTR		interface_message( EXAWORD );

	if ( DebugSymbols == (DEBUGPTR) 0 )
		return( FAUX );
	memset((BPTR) DebugSymbols->DbHeader, 'D', 256 );
	memset((BPTR) DebugSymbols->AtHeader, 'A', 256 );
	memset((BPTR) nomfic, 0, 245);
	fn_parser((BPTR) filename, (BPTR) nomfic, 0x000F );
	exadb_strcat( (BPTR) nomfic,(BPTR) TCODE_EXTENSION );
	if ( stream_open(_TCODE_STREAM, (BPTR) nomfic ) ) {
		if ( stream_read(_TCODE_STREAM, 0, (BPTR) DebugSymbols->AtHeader, 256 ) == 256 ) {
			unlock_header( (BPTR) DebugSymbols->AtHeader );
			memset((BPTR) nomfic, 0, 245);
			fn_parser((BPTR) filename, (BPTR) nomfic, 0x000F );
			exadb_strcat( (BPTR) nomfic,(BPTR) DEBUG_EXTENSION );
			if ( stream_open( _DEBUG_STREAM, (BPTR) nomfic ) ) {
				if ( stream_read(_DEBUG_STREAM, 0, (BPTR) DebugSymbols->DbHeader, 256 ) == 256 ) {
					unlock_header( (BPTR) DebugSymbols->DbHeader );
					loading_message((BPTR) "Symbolic Information");
					return( VRAI );
					}
				stream_close( _DEBUG_STREAM );
				}
			}
		stream_close(_TCODE_STREAM);
		}
#ifndef	OPTIMISEUR
	pos( 22, 2 );
	x_cprintf((BPTR) " * * * ");
	x_cprintf( (BPTR) interface_message(55) );
	x_putch( ' ' );
	x_cprintf( (BPTR) filename );
	x_cprintf( (BPTR) " ( "); 
	x_cprintf( (BPTR) nomfic );
	x_cprintf( (BPTR) " ) * * * ");
#endif
	return( FAUX );
}

EXAWORD	calculate_symbol_hash( token )
BPTR	token;
{
	EXAWORD	h=0;
	for ( h = 0; *token; token++ )
		h += *token;
	h %= SYMBOL_HASH;
	return( h );
}

SYMBOLPTR	allocate_for_symbol( token, type )
BPTR	token;
EXAWORD	type;
{
	SYMBOLPTR	lsymb;
	EXAWORD		h;

	if ((lsymb = (SYMBOLPTR) allocate( sizeof(struct symbolic_name) )) != (SYMBOLPTR) 0) {
		if ((lsymb->name = allocate( (exadb_strlen((BPTR) token ) + 1) )) != (BPTR) 0) {
			exadb_strcpy((BPTR) lsymb->name,(BPTR) token);
			lsymb->next	= (SYMBOLPTR) 0;
			lsymb->previous	= (SYMBOLPTR) 0;
			lsymb->number	= 0;
			lsymb->nature   = 0; /* Normal */
#ifdef	OPTIMISEUR
			lsymb->newnumber= 0;
#endif
			lsymb->special	= (VPTR) 0;
			lsymb->signature= (BPTR) 0;
			lsymb->hash 	= calculate_symbol_hash( (BPTR) token );
			lsymb->type 	= type;
			}
		else	{
			liberate( lsymb );
			lsymb = (SYMBOLPTR) 0;
			}
		}
#ifdef	WIN16
	if ( lsymb == (SYMBOLPTR) 0) {
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

	if ((lcode = (XCODEPTR) allocate( sizeof( struct code_control ) )) != (XCODEPTR) 0) 	{
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
	if ( lcode == (SYMBOLPTR) 0) {
extern	void _fastcall AlertBox(BPTR);
		AlertBox((BPTR) "Code management error : not enough memory" );
		}
#endif
	return( lcode );
}

CORRESPTR	allocate_for_linkage()
{
	CORRESPTR	llink;
	if (( llink = (CORRESPTR) allocate( sizeof( struct source_link ))) != (CORRESPTR) 0) {
		llink->tcode_offset	= MOINS_UN;
		llink->file_number	= MOINS_UN;
		llink->nature		= 0; /* Normal */
		llink->level		= 0;
		llink->file_offset	= (EXALONG) -1L;
		llink->next		= (CORRESPTR) 0;
		llink->previous		= (CORRESPTR) 0;
		};
#ifdef	WIN16
	if ( llink == (SYMBOLPTR) 0) {
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
	EXAWORD		id;
	if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[0x001A])) != 0)
	&&  (secteur != MOINS_UN)) {
		if (( stream_seek( _TCODE_STREAM, secteur, 0 ) )
		&&  ((nombre = stream_getw( _TCODE_STREAM )) != 0)
		&&  (nombre != MOINS_UN)
		&&  ((secteur = stream_getw( _TCODE_STREAM )) != 0)
		&&  (secteur != MOINS_UN)
		&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))) {
			loading_message((BPTR) "Global Variable Symbols");
			while ( 1 ) {
				if ((l = stream_gets( _DEBUG_STREAM,(BPTR) buffer, 256)) == 0)
					break;
				id = stream_getw(_DEBUG_STREAM );
				if ((lsymb = allocate_for_vname( (BPTR) buffer )) == (SYMBOLPTR) 0)
					break;
				lsymb->number = id;
				if ((lsymb->next = DebugSymbols->globals) != (SYMBOLPTR) 0)
					lsymb->next->previous = lsymb;
				DebugSymbols->globals = lsymb;
				nombre--;
				}
			}
		}
	return( VRAI );
}

XCODEPTR	collect_procedure_infos( identity )
EXAWORD	identity;
{
	XCODEPTR	lcode;
	EXAWORD	secteur;
	EXAWORD	l;
	if ((lcode = allocate_for_code_control( identity )) != (XCODEPTR) 0) {
		if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[0x0026])) != 0)
		&&  (secteur != MOINS_UN)
		&&  (stream_seek( _TCODE_STREAM, (secteur + ((identity & 0xFF00) >> 8)), (identity & 0x00FF ) ) )) {
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
	if ((lcode = allocate_for_code_control( identity )) != (XCODEPTR) 0) {
		if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[0x0022])) != 0)
		&&  (secteur != MOINS_UN)
		&&  (stream_seek( _TCODE_STREAM, (secteur + ((identity & 0xFF00) >> 8)), (identity & 0x00FF ) ) )) {
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

VOID	generate_segment_name( bptr, nombre )
BPTR	bptr;
EXAWORD	nombre;
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
	if ((sptr = CurrentSymbol) != (SYMBOLPTR) 0 ) {
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

EXAWORD	load_segment_names()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	EXAWORD		c;
	XCODEPTR		lcode;
	EXAWORD		realsegm;
	EXAWORD		special=0;

	if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[0x0056])) != 0)
	&&  (secteur != MOINS_UN)
	&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))
	&&  (nombre = stream_getw( _DEBUG_STREAM ))
	&&  (nombre != MOINS_UN)) {  

		loading_message((BPTR) "Segment Name Symbols");
		if ((special = TcGetWord((BPTR) & DebugSymbols->DbHeader[0x007E])) == MOINS_UN)
			special = 0;

		for ( id = 0; id < nombre; id++ ) {

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
				return( FAUX );
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
	return( VRAI );

}

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

	if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[0x002A])) != 0)
	&&  (secteur != MOINS_UN)
	&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))
	&&  (nombre = stream_getw( _DEBUG_STREAM ))
	&&  (nombre != MOINS_UN)) {  

		loading_message((BPTR) "Procedure Name Symbols");
		if ((special = TcGetWord((BPTR) & DebugSymbols->DbHeader[0x007E])) == MOINS_UN)
			special = 0;

		for ( id = 0; id < nombre; id++ ) {

			/* Collect procedure name */
			/* ---------------------- */
			if ((l = stream_gets( _DEBUG_STREAM, (BPTR) buffer, 256 )) == 0)
				return( FAUX );

			if ((lsymb = allocate_for_pname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );

			/* Collect procedure identity */
			/* -------------------------- */
			lsymb->number = stream_getw(_DEBUG_STREAM);
			lsymb->nature = special;

			/* Add this procedure to symbols list */
			/* ---------------------------------- */
			if ((lsymb->next = DebugSymbols->procedures) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->procedures = lsymb;

			/* Attempt to allocate code controller */
			/* ----------------------------------- */
			if ((lcode = collect_procedure_infos( lsymb->number )) == (XCODEPTR) 0)
				return( FAUX );

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
			l = (stream_getb(_DEBUG_STREAM) );

			/* Attempt to allocate for signature storage */
			/* ----------------------------------------- */
			if ((sptr = (BPTR) allocate( (l+3) )) == (BPTR) 0) 
				return( FAUX );

			lsymb->signature = sptr;

			rt = (stream_getb(_DEBUG_STREAM) );
			
			l |= ((rt & 0x0007) << 8);
			if ( rt & 0x0008 ) {
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
	return( VRAI );
}

EXAWORD	load_filename_symbols()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[0x0064])) != 0)
	&&  (secteur != MOINS_UN)
	&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))) { 
		loading_message((BPTR) "Filename Symbols");
		while (((nombre = stream_getw( _DEBUG_STREAM )) != 0) && (nombre != MOINS_UN)) {
			if ((l = stream_gets(_DEBUG_STREAM, (BPTR) buffer, 256 )) == 0)
				return( FAUX );
			if ((lsymb = allocate_for_fname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );
			lsymb->number = nombre;
			if ((lsymb->next = DebugSymbols->sources) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->sources = lsymb;
			}
		}
	return( VRAI );
}


EXAWORD	load_listname_symbols()
{
	EXAWORD		secteur;
	EXAWORD		nombre;
	EXAWORD		l;
	EXABYTE		buffer[256];
	SYMBOLPTR	lsymb;
	EXAWORD		id;
	if (((secteur = TcGetWord((BPTR) & DebugSymbols->DbHeader[0x0042])) != 0)
	&&  (secteur != MOINS_UN)
	&&  (stream_seek( _DEBUG_STREAM, secteur, 0 ))) { 
		loading_message((BPTR) "Listname Symbols");
		while ((l = stream_gets(_DEBUG_STREAM, (BPTR) buffer, 256 )) != 0) {
			if ((lsymb = allocate_for_fname( (BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );
			lsymb->number = nombre;
			if ((lsymb->next = DebugSymbols->listes) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->listes = lsymb;
			}
		}
	return( VRAI );
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

	if (((secteur = TcGetWord((BPTR) & DebugSymbols->AtHeader[0x0044])) != 0)
	&&  (secteur != MOINS_UN)
	&&  (stream_seek( _TCODE_STREAM, secteur, 0 ))) { 
		loading_message((BPTR) "Dynamic Library Symbols");
		nombre = stream_getw( _TCODE_STREAM );
		for ( id = 0; id < nombre; id++ ) {
			if ((l = stream_gets( _TCODE_STREAM, (BPTR) buffer, 256 )) == 0)
				return( FAUX );
			if ((lsymb = allocate_for_lname((BPTR) buffer )) == (SYMBOLPTR) 0)
				return( FAUX );
			lsymb->number = id;
			if ((lsymb->next = DebugSymbols->libraries) != (SYMBOLPTR) 0)
				lsymb->next->previous = lsymb;
			DebugSymbols->libraries = lsymb;
			l = stream_getw( _TCODE_STREAM );
			for ( l = 0; l < 18; l ++ )
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

EXAWORD	activate_symbols_manager( filename )
BPTR	filename;
{
	if ( DebugSymbols == (DEBUGPTR) 0 )
		return( FAUX );

	if ( filename != (BPTR) 0) {

		exadb_strcpy( (BPTR) DebugSymbols->programme, (BPTR) filename );
		reset_message_zone();

		if  (( initialise_symbolic_file( filename ) ) 
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
	return( FAUX );

}

VOID	symbolic_detachment( attdebug )
DEBUGPTR	attdebug;
{
	DEBUGPTR	MasterDebug=DebugSymbols;

	if ((DebugSymbols = attdebug) != (DEBUGPTR) 0 ) {
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

	if ( filename != (BPTR) 0 ) {

		DebugSymbols = (DEBUGPTR) 0;

		initialise_symbols_manager();

		if ((AttachDebug = DebugSymbols) != (DEBUGPTR) 0 ) {

			exadb_strcpy( (BPTR) DebugSymbols->programme, (BPTR) filename );
			reset_message_zone();
			
			if ((!( initialise_symbolic_file((BPTR) filename ))) 
			||  (!( load_filename_symbols()))
			||  (!(  load_procedure_names()))) {
				liberate_symbols_manager();
				AttachDebug = (DEBUGPTR) 0;
				}	
			}
		}

	DebugSymbols = MasterDebug;
	return((VPTR) AttachDebug );
}

/*	---------------------------------------------------------	*/
/*	S Y M B O L	R E S E A R C H		F U N C T I O N S	*/
/*	---------------------------------------------------------	*/
/*									*/
/*	BY NAME		or	BY NUMBER				*/
/*	---------------------------------------------------------	*/

SYMBOLPTR	locate_symbol_number( lsymb, number )
SYMBOLPTR	lsymb;
EXAWORD		number;
{

	for ( ; (lsymb != (SYMBOLPTR) 0); lsymb = lsymb->next)
	{
		if (lsymb->number == number)
			break;
	}
	return( lsymb );
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

SYMBOLPTR	locate_symbol( lsymb, token )
SYMBOLPTR	lsymb;
BPTR		token;
{
	EXAWORD	h=0;
	EXAWORD	wildcards=0;
	if ((lsymb != (SYMBOLPTR) 0) && (token != (BPTR) 0)) {
		if ((wildcards = wild_card_check((BPTR) token )) == 0)
			h = calculate_symbol_hash((BPTR) token );
		do	{
			if (wildcards) {
				if ( wildcomp((BPTR) lsymb->name, (BPTR) token) != MOINS_UN )
					return( lsymb );
				}
			else	if ((lsymb->hash == h )
				&&  (wildcomp((BPTR) lsymb->name, (BPTR) token) != MOINS_UN ))
					return( lsymb );
			}
		while (( lsymb = lsymb->next) != (SYMBOLPTR) 0); 
		}
	return( (SYMBOLPTR) 0);
}

VOID	replace_filename_symbol( oldname, newname )
BPTR	oldname;
BPTR	newname;
{
	SYMBOLPTR	lsymb;
	return;
	if (((lsymb = DebugSymbols->sources) != (SYMBOLPTR) 0)
	&&  ((lsymb = locate_symbol( lsymb, oldname )) != (SYMBOLPTR) 0)) {
		if ( lsymb->name != (BPTR) 0)
			liberate( lsymb->name );
		if ((lsymb->name = allocate( (exadb_strlen((BPTR) newname ) + 1) )) != (BPTR) 0)
			exadb_strcpy((BPTR) lsymb->name,(BPTR) newname);
		}
	return;
}


SYMBOLPTR	locate_variable_name( token )
BPTR		token;
{
	SYMBOLPTR	lsymb;

	if ((lsymb = locate_symbol( DebugSymbols->locals, (BPTR) token )) == (SYMBOLPTR) 0)
		lsymb = locate_symbol( DebugSymbols->globals, (BPTR) token );
	return( lsymb );
}


SYMBOLPTR	locate_variable_number( number )
EXAWORD		number;
{
	return( locate_symbol_number( (number & ISLOCAL ? DebugSymbols->locals : DebugSymbols->globals ), number ) );
}

SYMBOLPTR	locate_procedure_number( number )
EXAWORD		number;
{
	return( locate_symbol_number( DebugSymbols->procedures , number ) );
}

SYMBOLPTR	locate_procedure_name( token )
BPTR		token;
{
	return( locate_symbol( DebugSymbols->procedures , token ) );
}

BPTR	get_procedure_name( number )
EXAWORD	number;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = locate_procedure_number( number )) != (SYMBOLPTR) 0)
		return( (BPTR) lsymb->name );
#ifndef	OPTIMISEUR
	else	return( (BPTR) "P" );
#else
	else	return( (BPTR) 0 );
#endif
}

EXAWORD	get_procedure_number( nptr )
BPTR	nptr;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = locate_procedure_name( nptr )) != (SYMBOLPTR) 0)
		return( lsymb->number );
	else	return( MOINS_UN );
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
	else	return( (BPTR) "V" );
#else
	else	return( (BPTR) 0 );
#endif
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

SYMBOLPTR	locate_segment_number( number )
EXAWORD		number;
{
	return( locate_symbol_number( DebugSymbols->segments , number ) );
}

SYMBOLPTR	locate_segment_name( token )
BPTR		token;
{
	return( locate_symbol( DebugSymbols->segments ,(BPTR) token ) );
}

BPTR	get_segment_name( number )
EXAWORD	number;
{
	SYMBOLPTR	lsymb;
	if ((lsymb = locate_segment_number( number )) != (SYMBOLPTR) 0)
		return( (BPTR) lsymb->name );
#ifndef	OPTIMISEUR
	else	return( (BPTR) "S" );
#else
	else	return( (BPTR) 0 );
#endif
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
	&&  ((lcode = (XCODEPTR) lsymb->special) != (XCODEPTR) 0)) {

		/* Collect LDT and LNT for this code block */
		/* --------------------------------------- */
		if ((lcode->data_sector != 0)
		&&  (lcode->data_sector != MOINS_UN)
		&&  ( stream_seek( _TCODE_STREAM, (DebugSymbols->ldt_sector = lcode->data_sector), 0 ))
		&&  (( nombre = stream_getw( _TCODE_STREAM )))
		&&  (  nombre != MOINS_UN )
		&&  (( secteur = stream_getw( _TCODE_STREAM )))
		&&  (  secteur != MOINS_UN )
		&&  ( stream_seek( _DEBUG_STREAM, secteur, 0 ) ) ) {


			LocalList = (SYMBOLPTR) 0;
			/* Collect LOCAL NAME SYMBOLS */
			/* -------------------------- */
			while ( nombre ) {
				if ((l = stream_gets( _DEBUG_STREAM, (BPTR) buffer, 256 )) == 0 ) {
					liberate_symbol_list( LocalList ); 
					return((SYMBOLPTR) 0);
					}
				if ((xsymb = allocate_for_vname( (BPTR) buffer )) == (SYMBOLPTR) 0) {
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

	if ( lsymb != (SYMBOLPTR) 0 ) {
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

VOID	liberate_symbol_list( sptr )
SYMBOLPTR	sptr;
{
	SYMBOLPTR	lsymb;
	while ((lsymb = sptr) != (SYMBOLPTR) 0) {
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
VOID	release_local_variables()
{
	liberate_symbol_list( DebugSymbols->locals );
	DebugSymbols->locals = (SYMBOLPTR) 0;
	return;
}
#endif

VOID	release_correspondances( linfos )
CORRESPTR	linfos;
{
	CORRESPTR	tinfos;
	while ((tinfos = linfos) != (CORRESPTR) 0) {
		linfos = linfos->next;
		liberate( tinfos );
		}
	return; 
}

VOID	liberate_symbols_manager()
{
	SYMBOLPTR	sptr;

	if ( DebugSymbols != (DEBUGPTR) 0 ) {

		liberate_symbol_list( DebugSymbols->sources    );
		liberate_symbol_list( DebugSymbols->listes     );
		liberate_symbol_list( DebugSymbols->globals    );
		liberate_symbol_list( DebugSymbols->locals     );
		liberate_symbol_list( DebugSymbols->constants  );
		liberate_symbol_list( DebugSymbols->procedures );
		liberate_symbol_list( DebugSymbols->segments   );
		liberate_symbol_list( DebugSymbols->libraries  );
		release_correspondances( DebugSymbols->linkage  );

		terminate_streams();

		reset_symbols_manager();

		liberate( DebugSymbols );
		DebugSymbols = (DEBUGPTR) 0;

		}

	return;
}

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
	fsame = 0xFFFF;

	/* Establish Source Stream[1] as Debug File Correspondance table */
	/* for this procedure or Segment 				 */
	/* ------------------------------------------------------------- */
	if ( (lsymb != (SYMBOLPTR) 0)
	&&   ((lcode = (XCODEPTR) lsymb->special) != (XCODEPTR) 0)
	&&   ((sector = lcode->infos_sector) != 0)
	&&   ( sector != MOINS_UN )
	&&   ( stream_seek( _DEBUG_STREAM, sector, 0 ) )) {

		/* Remove 4 zero words in header and ignore ????? */
		/* ---------------------------------------------- */
		nbfic = stream_getw(_DEBUG_STREAM);
		nbfic = stream_getw(_DEBUG_STREAM);
		nbfic = stream_getw(_DEBUG_STREAM);
		nbfic = stream_getw(_DEBUG_STREAM);

		while ((nbfic = stream_getw(_DEBUG_STREAM)) != MOINS_UN) {
			if ((xinfos = allocate_for_linkage()) == (CORRESPTR) 0) {
				release_correspondances( linfos );
				linfos = xinfos;
				break;
				}
			xinfos->file_number  = nbfic;
			if ((xinfos->nature = lsymb->nature) == 0 )
				xinfos->file_offset  = stream_getl(_DEBUG_STREAM);
			else	{
				xinfos->file_offset  = (EXALONG) stream_getw(_DEBUG_STREAM);
				xinfos->level   = stream_getw(_DEBUG_STREAM);
				}
			xinfos->tcode_offset = stream_getw(_DEBUG_STREAM);
			if ( linfos == (CORRESPTR) 0)
				linfos = xinfos;
			else	{
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
	DebugSymbols->linktype  = MOINS_UN;
	DebugSymbols->linkowner = MOINS_UN;
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
	||  (DebugSymbols->linkowner != lsymb->number)) {
		forget_correspondances();
		if ((DebugSymbols->linkage = collect_correspondances( lsymb )) != (CORRESPTR) 0) {
			DebugSymbols->linktype  = lsymb->type;
			DebugSymbols->linkowner = lsymb->number;
			}
		}

	/* Attempt to locate the nearest source correspondance for the 	*/
	/* current provided tcode program offset 			*/
	/* ------------------------------------------------------------ */
	if (( litems = DebugSymbols->linkage) != (CORRESPTR) 0) {
		do	{
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

	if ((lsymb = locate_symbol_number(( mode == 1 ? DebugSymbols->procedures : DebugSymbols->segments ), identity )) != (SYMBOLPTR) 0) {
		if ((linfos =  collect_correspondances( lsymb )) != (CORRESPTR) 0 ) {
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
	&&  ( sector != MOINS_UN )
	&&  ( stream_seek_for_write( _DEBUG_STREAM, sector, 0 ) )) {
		do	{
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
	&&   ( sector != MOINS_UN )
	&&   ( stream_seek_for_write( _DEBUG_STREAM, sector, 0 ) ))) {
		/* ADD    4 zero words in header and ignore ????? */
		/* ---------------------------------------------- */
		stream_putw(_DEBUG_STREAM,0);
		stream_putw(_DEBUG_STREAM,0);
		stream_putw(_DEBUG_STREAM,0);
		stream_putw(_DEBUG_STREAM,0);

		do	{
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
	&&  ((linfos = DebugSymbols->linkage) != (CORRESPTR) 0)) {

		/* Rellocate all know correspondancies */
		/* ----------------------------------- */
		do	{
			if ((result = relocate_newline( linfos->tcode_offset )) != linfos->tcode_offset) {
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
	if ((lsymb = DebugSymbols->procedures) != (SYMBOLPTR) 0) {
		do	{
			posepiege(lsymb->number,0,mode,absel);
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
	if ((lsymb = DebugSymbols->segments) != (SYMBOLPTR) 0) {
		do	{
			posepiege(lsymb->number,0,mode,absel);
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
BPTR get_code_name_by_ptr(BPTR ptr,EXAWORD len)
{
BPTR code_name=(BPTR)0;
EXAWORD code_id;
DEBUGPTR save_DebugSymbols;
EXAWORD	get_procid_by_ptr(BPTR);

	if((*ptr==PROGRAM_POINTER||*ptr==SEGMENT_POINTER
	  ||*ptr==PROCEDURE_POINTER)&&(len==ABALPTRSIZE))
	{
	switch(*ptr)
	   {
		case PROGRAM_POINTER:	/* 0x85 */
			 save_DebugSymbols=DebugSymbols;
			 code_id= get_procid_by_ptr(ptr);
			 if(code_id != MOINS_UN)
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

