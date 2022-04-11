/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1994 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBFIND.C  				*/
/*		Date 	:	17/10/1994				*/
/*		Version :	2.1c					*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBFIND_C
#define	_EXDBFIND_C

static	FINDPTR	add_selection( xfind, linfos, nature, parent )
FINDPTR		xfind;
CORRESPTR	linfos;
EXAWORD		nature;
EXAWORD		parent;
{
	FINDPTR	lfind;
	FINDPTR	wfind;

	if ((lfind = (FINDPTR) allocate( sizeof( struct exadb_finder ))) != (FINDPTR) 0) {
		lfind->next      = (FINDPTR) 0;
		lfind->previous  = (FINDPTR) 0;
		lfind->selection.type   = nature;
		lfind->selection.block  = parent;
		lfind->selection.offset = linfos->tcode_offset;
		if ((wfind = xfind) == (FINDPTR) 0 )
			return( lfind );
		else	{
			while ( wfind->next != (FINDPTR) 0)
				wfind = wfind->next;
			wfind->next = lfind;
			lfind->previous = wfind;
			}
		}
	return( xfind );
}

static	EXAWORD	find_selection_compare( token, finish)
BPTR		token;
EXALONG		finish;
{
	EXAWORD	indent=0;
	EXAWORD	c;
	while ( 1 ) {
		switch ((c = stream_getb(_WORK_STREAM))) {
			case CTRL_M   : continue;

			case CTRL_J   :
				if (( *(token+indent) == 0 )
				|| (( *(token+indent) == '*')
				&&  ( *(token+indent+1) == 0)))
					return( indent );
				else if ( stream_tell( _WORK_STREAM ) >= finish )
					return(0);
				else	{
					indent = 0;
					continue;
					}
			case 0	      :
			case MOINS_UN :
			case CTRL_Z   :
				if (( *(token+indent) == 0 )
				||  ( *(token+indent) == '*'))
					return( indent );
				else	return( 0 );

			case CTRL_I   :
				c = ' ';
			default	      :
				switch ( *(token +indent) ) {
					case   0 : 
						return( indent );
					case '*' : 
						if ( *(token + indent + 1) == 0 )
							return((indent+1));
						if ( *(token + indent + 1) == c )
							indent++;
						continue;
 
					case '?' :
						indent++;
						continue;
					default  :
						if ( *(token+indent) == c )
							indent++;
						else	indent = 0;
						continue;
					}
			}
		}
	return( 0 );
}

static	EXALONG	find_finish( linfos, handle )
CORRESPTR	linfos;
EXAWORD		handle;
{
	while ( linfos != (CORRESPTR) 0 ) {
		if ( linfos->file_number == handle )
			return( linfos->file_offset );
		else	linfos = linfos->next;
		}
	return( 0L );
}


static	FINDPTR	build_find_selection( linfos, xfind, token, nature, parent )
CORRESPTR	linfos;
FINDPTR		xfind;
BPTR		token;
EXAWORD		nature;
EXAWORD		parent;
{
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	EXALONG		finish;
	while ( linfos != (CORRESPTR) 0) {
		if  (((fsymb = locate_source_number( linfos->file_number )) != (SYMBOLPTR) 0)
		&&   ( stream_position( _WORK_STREAM, (BPTR) fsymb->name, (EXALONG) linfos->file_offset, (fsymb->number+1),linfos->nature ))) {
			if  ( find_selection_compare( token,(finish = find_finish( linfos->next, linfos->file_number ))) )
				xfind = add_selection( xfind, linfos, nature, parent );
			}
		linfos = linfos->next;
		}
	return( xfind );
}

static	FINDPTR	build_proc_selection( token, lfind )
BPTR	token;
FINDPTR	lfind;
{
	SYMBOLPTR	lsymb= (SYMBOLPTR) 0;
	CORRESPTR	linfos=(CORRESPTR) 0;
	if ((lsymb = DebugSymbols->procedures) != (SYMBOLPTR) 0) {
		do	{
			if ((linfos= locate_correspondance( lsymb, 0 )) != (CORRESPTR) 0)
				lfind = build_find_selection( linfos, lfind, token, 1, lsymb->number );
			}
		while ((lsymb = lsymb->next) != (SYMBOLPTR) 0);
		}
	return( lfind );
}

static	FINDPTR	build_segm_selection( token, lfind )
BPTR	token;
FINDPTR	lfind;
{
	SYMBOLPTR	lsymb= (SYMBOLPTR) 0;
	CORRESPTR	linfos=(CORRESPTR) 0;
	if ((lsymb = DebugSymbols->segments) != (SYMBOLPTR) 0) {
		do	{
			if ((linfos= locate_correspondance( lsymb, 0 )) != (CORRESPTR) 0)
				lfind = build_find_selection( linfos, lfind, token, 0, lsymb->number );
			}
		while ((lsymb = lsymb->next) != (SYMBOLPTR) 0);
		}
	return( lfind );
}

static	FINDPTR	build_global_selection( token, lfind )
BPTR	token;
FINDPTR	lfind;
{
	lfind = build_proc_selection( token, lfind );
	lfind = build_segm_selection( token, lfind );
	return( lfind );
}

static	FINDPTR	build_this_selection( token )
BPTR	token;
{
	FINDPTR		lfind= (FINDPTR)   0;
	SYMBOLPTR	lsymb= (SYMBOLPTR) 0;
	CORRESPTR	linfos=(CORRESPTR) 0;

	switch ((BlockType)) {
		case 0 :	/* Segmental  code block */
			lsymb = locate_segment_number(BlockIdentity);
			break;
						
		case 1 :	/* Procedural code block */
			lsymb = locate_procedure_number(BlockIdentity);
			break;
		}

	if ((lsymb != (SYMBOLPTR) 0)
	&&  ((linfos= locate_correspondance( lsymb, 0 )) != (CORRESPTR) 0))
		lfind = build_find_selection( linfos, lfind, token, BlockType, BlockIdentity );

	return( lfind );
}

static	VOID	display_selection( lfound )
FINDPTR	lfound;
{
	/* Source Correspondance Information */
	/* --------------------------------- */
	(void) tcode_correspondance( lfound->selection.type, lfound->selection.block, lfound->selection.offset, 4 );
	return;
}

static	VOID	display_find_selection(lfind,token)
FINDPTR	lfind;
BPTR	token;
{
	FINDPTR	tfind;
	tfind = lfind;
	while (1) {
		standard_message( token );
		switch ( display_menu( 5, 5, 4, 
				(BPTR) interface_message(67),
				(BPTR) interface_message(68),
				(BPTR) interface_message(69),
				(BPTR) interface_message(70),
				(BPTR) "\0",
				(BPTR) "\0",
				(BPTR) "\0",
				(BPTR) "\0",
				(BPTR) "\0") ) {
			case	MOINS_UN	:
				return;
			case	0		:
				tfind = lfind;
				display_selection( (tfind = lfind) );
				break;
			case	1		:
				if ( tfind->next != (FINDPTR) 0 )
					display_selection( (tfind = tfind->next) );
				break;
			case	2		:
				if ( tfind->previous != (FINDPTR) 0 )
					display_selection( (tfind = tfind->previous ) );
				break;
			case	3 		:
				while (tfind->next != (FINDPTR) 0)
					tfind = tfind->next;
				display_selection( tfind );
  
			}
		}
	return;
}

static	VOID	release_find_selection( lfind )
FINDPTR	lfind;
{
	FINDPTR	xfind=(FINDPTR) 0;
	while ((xfind = lfind) != (FINDPTR) 0) {
		lfind = lfind->next;
		liberate( xfind );
		}
	return;
}

VOID	find_correspondance( hinfos )
CORRESPTR	hinfos;
{
	EXAWORD		l;
	EXABYTE		buffer[33];
	EXAWORD		option=0;
	FINDPTR		lfind=(FINDPTR) 0;
	EXAWORD		HoldLinkType;
	EXAWORD		HoldLinkOwn;
	CORRESPTR	HoldLinkage;


	if ((l = standard_ask( (BPTR) buffer, 32, (BPTR) interface_message( 74 ), 0 )) != 0) {
		if ((option = display_menu(22, 9, 4,
				(BPTR) interface_message(72),
				(BPTR) interface_message(65),
				(BPTR) interface_message(64),
				(BPTR) interface_message(73),
				(BPTR) "\0",
				(BPTR) "\0",
				(BPTR) "\0",
				(BPTR) "\0",
				(BPTR) "\0" )) == MOINS_UN) 
			return;
		HoldLinkType = DebugSymbols->linktype;
		HoldLinkOwn  = DebugSymbols->linkowner;
		HoldLinkage  = DebugSymbols->linkage;
		DebugSymbols->linkage = (CORRESPTR) 0;
		DebugSymbols->linktype = MOINS_UN;
		DebugSymbols->linkowner = MOINS_UN;
		switch ((option)) { 
			case 	0 	 :
				lfind = build_this_selection( (BPTR) buffer);
				break;
			case 	1 	 :
				lfind = build_segm_selection( (BPTR) buffer,lfind);
				break;
			case 	2 	 :
				lfind = build_proc_selection( (BPTR) buffer,lfind);
				break;
			case 	3	 :
				/* Build Find Selection Control Context */
				/* ------------------------------------ */
				lfind = build_global_selection( (BPTR) buffer,lfind);
				break;
			}
		if ( lfind != (FINDPTR) 0 ) {
			display_find_selection(lfind,(BPTR) buffer);
			release_find_selection( lfind );
			forget_correspondances();
			}
		else	standard_error( interface_message( 75 ) );
		DebugSymbols->linktype  = HoldLinkType;
		DebugSymbols->linkowner = HoldLinkOwn;
		DebugSymbols->linkage   = HoldLinkage;
		}
	return;
 

}



#endif	/* _EXDBFIND_C */
	/* ----------- */

