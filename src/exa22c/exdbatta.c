/*----------------------------------------------------------------------*/
/*									*/
/*		-----------------------------------  			*/
/*		D E B U G G E R   	A B A L + +  			*/
/*		-----------------------------------  			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBATTA.C  				*/
/*		Version :	2.1a					*/
/*		Date 	:	17/12/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXDBATTA_C
#define	_EXDBATTA_C

#include "exproto1.h"
/*	--------------------------------------		*/
/*	Extended Attachment Features for EXADB		*/
/*	--------------------------------------		*/
/*	Included by EXDBCLF.C				*/
/*	--------------------------------------		*/

VOID	draw_attachment( topcol, toplin, nbcol, attlog )
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbcol;
ATTLOGPTR	attlog;
{
	ATTENTPTR	attent;
	EXAWORD		nombre=0;
	BPTR		sptr;
	EXABYTE		buffer[128];	
	EXAWORD		l;
	if (( attlog != (ATTLOGPTR) 0 )
	&& ( attlog->filename != (BPTR) 0)) {
		attent = attlog->entry;
		while ( attent != (ATTENTPTR) 0 ) {
			attent = attent->next;
			nombre++;
			}
		exadb_strcpy((BPTR) buffer,(BPTR)  attlog->filename );
		l = exadb_strlen((BPTR) buffer );
		buffer[l++] = ' ';
		buffer[l++] = ':';
		exadb_itoa((BPTR) ( &buffer[l] ), nombre );
		if ( attlog->debug != (VPTR) 0 )
			exadb_strcat((BPTR) buffer, (BPTR) ",db" );
		left_string( topcol, toplin, nbcol, (BPTR) buffer );

		}
	else	left_string( topcol, toplin, nbcol, (BPTR) " " );
	return;
}

VOID	draw_attachments( topcol, toplin, nbcol, nblin, attlog )
EXAWORD		topcol;
EXAWORD		toplin;
EXAWORD		nbcol;
EXAWORD		nblin;
ATTLOGPTR	attlog;
{
	EXAWORD	n;

	for ( n = 0; n < nblin; n++ ) {
		draw_attachment( topcol, toplin+n, nbcol, attlog );
		if ( attlog != (ATTLOGPTR) 0 )
			attlog = attlog->next;
		} 
	return;
}

VOID	attachment_manager( cmdptr )
BPTR	cmdptr;
{
	ATTLOGPTR	attlog=AttachmentLog;
	ATTLOGPTR	tmpatt=AttachmentLog;
	EXAWORD		nombre=0;
	EXAWORD		nblines;
	EXAWORD		c;

	/* Count number of attachments */
	/* --------------------------- */
	while (tmpatt != (ATTLOGPTR) 0) {
		tmpatt = tmpatt->next;
		nombre++;
		}

	/* None so nothing to do */
	if ( nombre == 0 )
		return;

	tmpatt = attlog;
	mouse_title_box( 5, 6, 64, (nblines = ( nombre > 10 ? 10 : nombre )), (BPTR) "Attached Objects" );

	draw_attachments( 7, 7, 62, nblines, tmpatt );
	while ((c = mouse_or_keyboard()) != 27) {
		switch (c) {
			case 0x0005 :
			case 0x0003 :
				if ( tmpatt->next == (ATTLOGPTR) 0 )
					continue;
				tmpatt = tmpatt->next;
				break;

			case 0x000B :
			case 0x0012 :
				if ( tmpatt->prev == (ATTLOGPTR) 0 )
					continue;
				tmpatt = tmpatt->prev;
				break;
			}
		draw_attachments( 7, 7, 62, nblines, tmpatt );
		}

	pop_mouse();
	return;
}

VOID	force_symbolic_attachment( context )
OVLOBJPTR	context;
{
	ATTLOGPTR	attlog;
	if ( context != (OVLOBJPTR) 0 ) {
		if ((attlog = context->master) != (ATTLOGPTR) 0 )
			force_debug_context( attlog->debug );
		else	force_debug_context((BPTR) 0 );
		}
	return;
}

BPTR	ReadPtrVariable( xptr )
BPTR	xptr;
{
	BPTR	mptr;
	mptr = TcodeGetPointer( xptr );
	return( mptr );
}

#endif	/* _EXDBATTA_C */
	/* ----------- */
