#ifndef	_exdbwui_c
#define	_exdbwui_c
/* ---------------------------------------------------------------------*/
/*                                                                      */
/*              E X E C U T E U R       A . B . A . L                   */
/*              -------------------------------------                   */
/*                                                                      */
/*              Copyright (c) 1987,1997 Amenesik / Sologic S.A.         */
/*                                                                      */
/*              Module  :       EXDBWUI.C                               */
/*              Date    :       20/10/2021                              */
/*              Version :       5.1a                                    */
/*                                                                      */
/*----------------------------------------------------------------------*/
/*				E X D B W U I 				*/
/*----------------------------------------------------------------------*/
/*                                                                      */
/*		This source has been added and allows			*/
/*		EXADB to use AED for source following			*/
/*		in graphical windowed environments.			*/
/*                                                                      */
/*----------------------------------------------------------------------*/

#include <stdio.h>
typedef int PTR I32PTR; 
#include "exword.h"

EXAWORD	CheckBreakPoints(EXAWORD fileid);
CORRESPTR	resolve_correspondance(EXAWORD,EXAWORD,EXAWORD);
BPTR		get_procedure_name(EXAWORD);
BPTR		attachmentlist();
BPTR		breakpointlist();
BPTR		watchpointlist();
extern	BPTR	GlobalDataTable;
extern	BPTR	LocalDataTable;
extern	EXAWORD	err_val;
extern	EXAWORD	worktyp1;
extern	EXAWORD	workval1;
extern	EXAWORD	worklen1;
extern	BPTR   	workptr1;

struct	debug_editor	
{
	EXAWORD	inhibit;
	BPTR	host;		/* current filename 			*/
	EXAWORD	x;		/* top left corner of editor window	*/
	EXAWORD	y;		/* coordinates x and y			*/
	EXAWORD	w;		/* dimension of the window in pixels	*/
	EXAWORD	h;		/* w and h				*/
	EXAWORD	font;		/* font number to use in editor		*/
	EXAWORD	fontwidth;	/* width of font for scroll bar		*/
	EXAWORD	fontheight;	/* width of font for scroll bar		*/
	EXAWORD	state;		/* 0 idle, 1 ready, 2 active		*/
	EXAWORD	number;		/* number of active file		*/
	EXAWORD	fontchange;
	BYTE	buffer[64];	/* configuration work buffer		*/
	BPTR	argv[5];	/* command line parameters		*/
	BYTE	command[80];	/* command work buffer			*/
} aed = 
{ 
	0,
	(char *) "\0",	/* current filename 			*/
	0,0,0,0,	/* zero dimensions			*/
	0,		/* to be sure to be sure !		*/
	0,0,0,0,0 	/* all reset to zero			*/

};

struct	debug_window	
{
	EXAWORD	isexecute;
	EXAWORD	execfile;
	EXAWORD	execline;
	EXAWORD	dpi;
	EXAWORD	execution;
	EXAWORD	globals;
	EXAWORD	debugmask;
	EXAWORD	mousemask;
	EXAWORD	pvpx;
	EXAWORD	dvpx;
	EXAWORD	x;		/* top left corner of program window	*/
	EXAWORD	y;		/* coordinates x and y			*/
	EXAWORD	w;		/* dimension of the window in pixels	*/
	EXAWORD	h;		/* w and h				*/
	EXAWORD	state;		/* 0 idle, 1 ready, 2 active		*/
	EXAWORD	width;
	EXAWORD	height;
	EXAWORD	hidden;
	BPTR	buffer;
	BPTR	work;
	BYTE	token[128];	/* Token Buffer				*/
	EXAWORD	symbols[40];	/* 40 line symbols 			*/
	BYTE	pvp[80];	/* program viewport			*/
	BYTE	dvp[80];	/* debug   viewport			*/
	BYTE	dbpal[1024];	/* Debug   Palette			*/
	BYTE	pgpal[1024];	/* Program Palette			*/
	BYTE	dbrgb[16];	/* Debug Paint/Gui			*/
	BYTE	pgrgb[16];	/* Program Pain/Gui			*/

} program = 
{
	0,0,0,
	75,
	0,0,
	0,0,
	0,0,
	0,0,0,0,
	0,
	0,0,
	0,
	(BPTR) 0, (BPTR) 0
};

static	BYTE	programimo[64];

static	BPTR	FileNameSelection=(BPTR) 0;
static	BPTR	AttachNameSelection=(BPTR) 0;
static	BPTR	BreakSelection=(BPTR) 0;
static	BPTR	WatchSelection=(BPTR) 0;
static	BPTR	StackSelection=(BPTR) 0;
static	BPTR	ObserveSelection=(BPTR) 0;
static	BPTR	RegisterSelection=(BPTR) 0;

/*	-------------	*/
/*	visual_circle	*/
/*	-------------	*/
void	visual_circle(int x,int y, int w, int h, int p, int t )
{
#ifndef	NOGIGO
	drawcircle(x,y,w,h,p,t);
#endif
	return;
}

/*	-------------------	*/
/*	use_program_palette	*/
/*	-------------------	*/
void	use_program_palette()
{
#ifndef	NOGIGO
	BPTR * get_vga_palette();
	BPTR * pptr;
	if ((pptr = get_vga_palette()) != (BPTR) 0) 
	{
		memcpy(program.dbpal,pptr,1024);
		memcpy(pptr,program.pgpal,1024);
		put_palette();
	}		
	get_paint_translation( program.dbrgb, 16 );
	set_paint_translation( program.pgrgb, 16 );
#endif
	return;
}

int	control_fork()			{	return(fork());		}
void	system_failure(char * mptr)	{	return;			}
int	test_initialise_hardware()	{	return(1);		}

/*	-----------------	*/
/*	use_debug_palette	*/
/*	-----------------	*/
void	use_debug_palette()
{
#ifndef NOGIGO
	BPTR * get_vga_palette();
	BPTR * pptr;
	if ((pptr = get_vga_palette()) != (BPTR) 0)
	{
		memcpy(program.pgpal,pptr,1024);
		memcpy(pptr,program.dbpal,1024);
		put_palette();
	}		
	get_paint_translation( program.pgrgb, 16 );
	set_paint_translation( program.dbrgb, 16 );
#endif
	return;
}

/*	--------------------	*/
/*	get_program_viewport	*/
/*	--------------------	*/
void	get_program_viewport()
{
#ifndef NOGIGO
	program.pvpx = get_cico_viewport( &program.pvp );
#endif
	return;
}

/*	--------------------	*/
/*	set_program_viewport	*/
/*	--------------------	*/
void	set_program_viewport()
{
#ifndef NOGIGO
	if ( program.pvpx ) 
	{
		set_cico_viewport( &program.pvp );
		program.pvpx = 0;
	}
#endif
	return;
}

/*	------------------	*/
/*	set_debug_viewport	*/
/*	------------------	*/
void	set_debug_viewport()
{
#ifndef NOGIGO
	if ( program.dvpx ) 
	{
		set_cico_viewport( &program.dvp );
		program.dvpx = 0;
	}
#endif
	return;
}

/*	------------------	*/
/*	get_debug_viewport	*/
/*	------------------	*/
void	get_debug_viewport()
{
#ifndef NOGIGO
	program.dvpx = get_cico_viewport( &program.dvp );
#endif
	return;
}

/*	-------------------------	*/
/*	 WindowEditorOnConfigure	*/
/*	-------------------------	*/
EXAWORD	WindowEditorOnConfigure()
{
	use_base_font(aed.font);
	aed.fontwidth = (guifontsize(aed.font) & 0x00FF);
	cicowindow(aed.x,aed.y,aed.w-(aed.fontwidth*2),aed.h );
	sprintf(aed.buffer,"%u:%u:%u:%u:0:%u:0:%u",aed.x,aed.y,aed.w,aed.h,aed.font,(aed.fontwidth*3));
	aed.state = 1; aed.number= -1; aed.host="\0";
	editor_window_connection(aed.buffer);
	aed.argv[0]="exadb";
}

/*	--------------------	*/
/*	WindowEditorOnCreate	*/
/*	--------------------	*/
EXAWORD	WindowEditorOnCreate( EXAWORD x, EXAWORD y, EXAWORD w, EXAWORD h, EXAWORD fid )
{
	int	fw;
	aed.x = x; aed.y = y; aed.w = w; aed.h = h; 
	if ( aed.font == 0 ) 
	{
		aed.font = fid;
	}
	if ( aed.font == 0 ) 
	{
		aed.font = 1;
	}
	WindowEditorOnConfigure();
	return(0);
}

/*	---------------------	*/
/*	WindowEditorLoseFocus	*/
/*	---------------------	*/
VOID	WindowEditorLoseFocus()
{
	if ( aed.state == 3 ) 
	{
		editorFocusLine(0);
		aed.state = 2;
	}
	return;
}

/*	--------------------	*/
/*	WindowEditorGetFocus	*/
/*	--------------------	*/
VOID	WindowEditorGetFocus()
{
	if ( aed.state == 2 ) 
	{
		editorFocusLine(1);
		aed.state = 3;
	}
	return;
}

extern	EXAWORD	StopStatus;

/*	---------------------	*/
/*	WindowEditorResetFile	*/
/*	---------------------	*/
VOID	WindowEditorResetFile()
{
	aed.host  = aed.argv[1] = (char *) 0;
	aed.number= 0;
	return;
}	

/*	-----------------	*/
/*	 TryEditorOnShow	*/
/*	-----------------	*/
EXAWORD	TryEditorOnShow()
{
	if (!(aed.inhibit))
		editorOnShow();
	return(0);
}

/*	----------------	*/
/*	FreezeEditorShow	*/
/*	----------------	*/
VOID	FreezeEditorShow()
{
	aed.inhibit = 1;
	editorNoShow();
	return;
}

/*	----------------	*/
/*	 ThawEditorShow 	*/
/*	----------------	*/
VOID	ThawEditorShow()
{
	aed.inhibit = 0;
	editorDoShow();
	return;
}

/*	----------------	*/
/*	WindowEditorFile	*/
/*	----------------	*/
EXAWORD	WindowEditorFile( SYMBOLPTR fsymb, EXAWORD offset )
{
	if (!( fsymb )) { return(0); }

	if ( aed.fontchange ) 
	{
		WindowEditorOnConfigure();
	}

	if (( aed.state < 2 ) || ( aed.fontchange )) 
	{
		aed.host   = fsymb->name;
		aed.number = fsymb->number;
		aed.argv[1]= fsymb->name;
		editorOnCreate( 2, aed.argv );
		aed.fontchange=0;
		aed.state=2;
	}
	else 	
	{
		if ((!( aed.host ))
		||  (!( fsymb->name ))
		||  ( strcmp( aed.host, fsymb->name ) )) 
		{
			WindowEditorLoseFocus();
			editorOnQuit();
			editorOnRemove();
			aed.host   = fsymb->name;
			aed.number = fsymb->number;
			aed.argv[1]=fsymb->name;
			editorOnCreate( 2, aed.argv );
		}
	}
	aed.fontchange = 0;
	if (!( editorOnSeek(0,offset) )) 
	{
		TryEditorOnShow();
	}
	WindowEditorGetFocus();
	CheckBreakPoints(fsymb->number);
	return(0);
}

/*	------------------------	*/
/*	 WindowEditorFileNumber 	*/
/*	------------------------	*/
EXAWORD	WindowEditorFileNumber( EXAWORD fileid, EXAWORD offset )
{
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	EXAWORD		item=0;

	for (	item=0, 
		fsymb=DebugSymbols->sources;
		fsymb != (SYMBOLPTR) 0;
		fsymb = fsymb->next ) 
	{
		if ( item == fileid )
			break;
		else	item++;
	}
	if (!( fsymb ))
		return( 0 );
	else	return( WindowEditorFile( fsymb, offset) );
}

/*	----------------------		*/
/*	 DebugEditorFileNumber  	*/
/*	----------------------		*/
EXAWORD	DebugEditorFileNumber( EXAWORD fileid, EXAWORD offset )
{
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;

	for (	fsymb=DebugSymbols->sources;
		fsymb != (SYMBOLPTR) 0;
		fsymb = fsymb->next ) 
	{
		if ( fsymb->number == fileid )
			break;
	}
	if (!( fsymb ))
		return( 0 );
	else	return( WindowEditorFile( fsymb, offset) );
}

/*	------------------	*/
/*	WindowEditorOnShow	*/
/*	------------------	*/
EXAWORD	WindowEditorOnShow( EXAWORD type, EXAWORD block, EXAWORD offset )
{
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	CORRESPTR	linfos=(CORRESPTR) 0;
	
	if ( is_idb_active() )  
	{
		return(-1);
	}

	program.execfile=program.execline=program.isexecute=0;
	while (!(StopStatus)) 
	{
		if (!( linfos = resolve_correspondance( type, block, offset ) )) 
		{
			activate_assembler_list(3);
			break;
		}
		else if (!( fsymb = locate_source_number(linfos->file_number) )) 
		{
			activate_assembler_list(3);
			break;
		}
		else	
		{
			program.execfile=linfos->file_number;
			program.execline=linfos->file_offset;
			break;
		}
	}
	if ( StopStatus )
		return(0);
	else if ( is_idb_active() )
		return(0);
	else	return( WindowEditorFile( fsymb, linfos->file_offset ) );
}

/*	-------------------	*/
/*	WindowEditorOnEvent	*/
/*	-------------------	*/
EXAWORD	WindowEditorOnEvent()
{
	return( 
		WindowEditorOnShow( 
			current_tcode_block_type(),
			current_tcode_identity(),
			current_tcode_offset() ) );
}

/*	------------------------	*/
/*	 WindowEditorOnGetFocus 	*/
/*	------------------------	*/
EXAWORD	WindowEditorOnGetFocus()
{
	return(mimo_getch());
}

/*	------------------	*/
/*	WindowEditorOnExec	*/
/*	------------------	*/
EXAWORD	WindowEditorOnExec( BPTR bptr, EXAWORD blen )
{
	*(bptr+(blen-1)) = 0;
	command_interpreter(bptr, 0);
	return(0);
}

/*	--------------------	*/
/*	WindowEditorOnRemove	*/
/*	--------------------	*/
EXAWORD	WindowEditorOnRemove()
{
	if ( aed.state > 1 ) 
	{
		editorOnLoseFocus();
		editorOnHide();
		editorOnQuit();
		editorOnRemove();
		aed.state=1;
	}
	if ( aed.state > 0 ) 
	{
		aed.state=0;
	}
	return(0);
}

/*	----------------	*/
/*	symbolic_failure	*/
/*	----------------	*/
VOID	symbolic_failure( 
	BPTR buffer,
	EXAWORD	type,
	EXAWORD	block,
	EXAWORD	offset )
{
	if ( type )
		sprintf(buffer,"proc: %x:%x ",block,offset); 
	else	sprintf(buffer,"segm: %u:%x ",block,offset);
	return;
}

/*	-------------------------	*/
/*	 WindowEditorInformation	*/
/*	-------------------------	*/
VOID	WindowEditorInformation( BPTR buffer, EXAWORD buflen )
{
	EXAWORD	type=current_tcode_block_type();
	EXAWORD	block=current_tcode_identity();
	EXAWORD	offset=current_tcode_offset();
	char *	prefix;
	char *	tcodename;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	CORRESPTR	linfos=(CORRESPTR) 0;

	if (!( tcodename=trace_tcode_filename() ))
		tcodename = "noname";

	switch (type) 
	{
		case 0 :	/* Segmental  code block */
			lsymb = locate_segment_number(block);
			break;
						
		case 1 :	/* Procedural code block */
			lsymb = locate_procedure_number(block);
			break;
	}
	if (!( lsymb )) 
	{
		symbolic_failure( buffer, type, block, offset );
		return;
	}
	if (!( linfos = resolve_correspondance( type, block, offset ) )) 
	{
		symbolic_failure( buffer, type, block, offset );
		return;
	}
	else if (!( fsymb = locate_source_number(linfos->file_number) )) 
	{
		symbolic_failure( buffer, type, block, offset );
		return;
	}
	if ( type ) 
	{
		sprintf(buffer,"%s: proc: %s(%x):%x , %s(%u)",
			tcodename,
			lsymb->name,block,offset,
			fsymb->name,linfos->file_offset);
	}
	else	
	{
		sprintf(buffer,"%s: segm: %s(%u):%x , %s(%u)",
			tcodename,
			(lsymb->name ? lsymb->name : (BPTR) "noname"),
			block,offset,
			fsymb->name,linfos->file_offset);
	}
	return;
}

/*	----------------	*/
/*	DeleteBreakPoint	*/
/*	----------------	*/
VOID	DeleteBreakPoint( EXAWORD id )
{
	raztrap(id);
	return;
}

EXAWORD	ProcNameSelectionMode=-1;

/*	------------------	*/
/*	DebugProcedureEdit	*/
/*	------------------	*/
int	DebugProcedureEdit(int item)
{
	CORRESPTR	linfos=(CORRESPTR) 0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;
	for (	lsymb = DebugSymbols->procedures;
		lsymb != (SYMBOLPTR) 0;
		lsymb = lsymb->next ) 
	{
		if ( lsymb->number == ( item * (8*WORDSIZE) )) 
		{
			if (!( linfos = locate_correspondance( lsymb, 0 )))
				return(0);
			else	break;
		}
	}

	if (!( linfos ))
		return(0);
	if (!( DebugEditorFileNumber( linfos->file_number, linfos->file_offset ) ))
		return(0);
	else	return(1);
}

/*	----------------	*/
/*	DebugSegmentEdit	*/
/*	----------------	*/
int	DebugSegmentEdit(int item)
{
	CORRESPTR	linfos=(CORRESPTR) 0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;
	int		items=0;

	for (	items=0,
		lsymb = DebugSymbols->segments;
		lsymb != (SYMBOLPTR) 0;
		lsymb = lsymb->next )
	{
		if ( item == items ) 
		{
			if (!( linfos = locate_correspondance( lsymb, 0 )))
				return(0);
			else	break;
		}
	}

	if (!( linfos ))
		return(0);
	else if (!( DebugEditorFileNumber( linfos->file_number, linfos->file_offset ) ))
		return(0);
	else	return(1);

}

/*	-----------------	*/
/*	GetProcedureNames	*/
/*	-----------------	*/
BPTR	GetProcedureNames(int mode)
{
	BPTR	wptr;
	EXAWORD	nbuflen=0;
	EXAWORD	procedures=0;
	EXAWORD	block=0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;
	BYTE	xbuffer[32];

	if ( DebugSymbols->ProcNameSelection ) 
	{
		if (ProcNameSelectionMode != mode ) 
		{
			liberate( DebugSymbols->ProcNameSelection );
			DebugSymbols->ProcNameSelection = (BPTR) 0;
		}
	}

	if (!( DebugSymbols->ProcNameSelection )) 
	{
		while ((lsymb = locate_procedure_number(block)) != (SYMBOLPTR) 0) 
		{
			if ( lsymb->name ) 
			{
				nbuflen += (strlen(lsymb->name)+1);
				switch ( mode ) 
				{
					case	1 : sprintf(xbuffer,":%u",procedures);  nbuflen += strlen(xbuffer); break;
					case	2 : sprintf(xbuffer,"/%x",block);  	nbuflen += strlen(xbuffer); break;
				}
				procedures++;
			}
			block += 32;
		}
		if (!( nbuflen ))
			return("procedures|etc");
		else if (!(DebugSymbols->ProcNameSelection = allocate( nbuflen )))
			return("procedures|etc");
		block = 0;
		procedures=0;
		wptr = DebugSymbols->ProcNameSelection;
		ProcNameSelectionMode = mode;
		*wptr = 0;
		while ((lsymb = locate_procedure_number(block)) != (SYMBOLPTR) 0) 
		{
			if ( lsymb->name ) 
			{
				if ( block )
					strcat(wptr,"|");
				strcat(wptr,lsymb->name);
				switch ( mode ) 
				{
					case	1 : sprintf(xbuffer,":%u",procedures);  strcat(wptr,xbuffer); break;
					case	2 : sprintf(xbuffer,"/%x",block);  	strcat(wptr,xbuffer); break;
				}
				wptr += strlen(wptr);
				procedures++;
			}
			block += 32;
		}
	}
	if (!( DebugSymbols->ProcNameSelection )) 
		return("procedures|etc");
	else	return( DebugSymbols->ProcNameSelection );
}

/*	-----------------	*/
/*	 GetSegmentNames	*/
/*	-----------------	*/
BPTR	GetSegmentNames()
{
	BPTR	wptr;
	EXAWORD	nbuflen=0;
	EXAWORD	segments=0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;

	if (!( DebugSymbols->SegmNameSelection )) 
	{
		for (	segments=0,
			lsymb = DebugSymbols->segments;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				nbuflen += (strlen(lsymb->name)+1);
				segments++;
			}
		}
		if (!( nbuflen ))
			return("segments|etc");
		else if (!(DebugSymbols->SegmNameSelection = allocate( nbuflen )))
			return("segments|etc");
		wptr = DebugSymbols->SegmNameSelection;
		*wptr = 0;
		for (	segments=0,
			lsymb = DebugSymbols->segments;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				if ( segments ) 
				{
					strcat(wptr,"|");
				}
				strcat(wptr,lsymb->name);
				wptr += strlen(wptr);
				segments++;
			}
		}
	}
	if (!( DebugSymbols->SegmNameSelection )) 
		return("segments|etc");
	else	return( DebugSymbols->SegmNameSelection );
}

/*	--------------------	*/
/*	variable_symbol_size	*/
/*	--------------------	*/
EXAWORD	variable_symbol_size( SYMBOLPTR lsymb, BPTR tptr )
{
	BPTR	dptr;
	BPTR	nptr;
	EXAWORD	hid;
	EXAWORD	length=0;
	EXAWORD	dtype;

	length = (strlen(lsymb->name)+8); /* name + dcl/ptr +type */
	dptr = (tptr+lsymb->number);
	dtype = Tcodeword( dptr ); 
	dptr+= WORDSIZE;
	if (dtype & ISDYNAMIC) 
	{
		if  (dtype & ISMEMBER) 
		{
			hid = Tcodeword( dptr ); 
			dptr+= WORDSIZE;
			if ((nptr = get_variable_name( hid )) != (BPTR) 0)
				length += (strlen(nptr) + 3);
		}
		dptr+= WORDSIZE;
	}
	else if ( dtype & SPECIALE ) 
		dptr += (2 * WORDSIZE);
	if ( dtype & NDX1st ) 
	{
		length += 7;
		if ( dtype & NDX2nd )
			length += 7;
	}
	if (( dtype & 3 ) > 1)
		length += 7;
	return( length );
}

/*	--------------------	*/
/*	variable_symbol_type	*/
/*	--------------------	*/
VOID	variable_symbol_type(BPTR wptr, EXAWORD dtype, BPTR dptr )
{
	EXAWORD	ilen;
	EXAWORD	alen;
	EXAWORD	dlen;
	switch ( dtype & VARB_ISOL ) 
	{
		case	VARB_INT8	:
			strcat(wptr,"#"); break;
		case	VARB_INT16	:
			strcat(wptr,"%"); break;
		case	VARB_INT32	:
			strcat(wptr,":"); break;
		case	VARB_INT64	:
			strcat(wptr,"&"); break;
		case	VARB_STR	:
			strcat(wptr,"$");
		case	VARB_BCD	:
			wptr += strlen(wptr);
			dlen = Tcodeword(dptr); 
			dptr+=WORDSIZE;
			sprintf(wptr,"=%u",dlen);
			break;
	}
	if ( dtype & NDX1st ) 
	{
		wptr += strlen( wptr );
		ilen = Tcodeword(dptr); dptr+=WORDSIZE;
		if ( dtype & NDX2nd ) 
		{
			alen = Tcodeword(dptr); dptr+=WORDSIZE;
			sprintf(wptr,"(%u,%u)",ilen,alen);
		}
		else	sprintf(wptr,"(%u)",ilen,alen);
	}
	return;
}

/*	------------------------	*/
/*	 variable_symbol_string 	*/
/*	------------------------	*/
VOID	variable_symbol_string(BPTR wptr, SYMBOLPTR lsymb, BPTR tptr, EXAWORD newname )
{
	BPTR	dptr;
	BPTR	nptr;
	EXAWORD	dlen;
	EXAWORD	hid;
	EXAWORD	dtype;
	EXAWORD	ws;
	dptr = (tptr+lsymb->number);
	dtype = Tcodeword( dptr );
	dptr += WORDSIZE;
	ws = WORDSIZE;
	if (!(dtype & ISDYNAMIC)) 
	{
		if ( newname ) 
		{
			strcpy(wptr,"dcl ");
		}
		if ( dtype & SPECIALE ) 
			dptr += (2 * WORDSIZE);
		else	dptr += WORDSIZE;
	}
	else	
	{
		if ( newname ) 
		{
			if (dtype & ISPOINTER) strcpy(wptr,"ptr "); 	else	strcpy(wptr,"dcl ");
		}
		if ( dtype & ISMEMBER ) 
		{
			hid = Tcodeword( dptr ); 
			dptr+= WORDSIZE;
			if ((nptr = get_variable_name( hid )) != (BPTR) 0) 
			{
				strcat(wptr,nptr);
				strcat(wptr,".");
			}
		}
		dptr+= WORDSIZE;
	}
	strcat(wptr,lsymb->name);
	variable_symbol_type(wptr,dtype,dptr);
	return;
}

/*	------------------	*/
/*	DebugPositVariable	*/
/*	------------------	*/
VPTR	DebugPositVariable(EXAWORD vnumber)
{
	SYMBOLPTR	lsymb;
	EXAWORD		variables=0;
	check_global_load();
	for (	variables=0,
		lsymb = DebugSymbols->globals;
		lsymb != (SYMBOLPTR) 0;
		lsymb = lsymb->next, variables++ )
		if ( variables == vnumber )
			return( lsymb );
	return((VPTR) 0);
}

/*	-------------------	*/
/*	DebugTransferString	*/
/*	-------------------	*/
VOID	DebugTransferString(BPTR rptr, EXAWORD rlen, BPTR sptr )
{
	EXAWORD	i=0;
	if ( sptr ) 
	{
		for (i=0; i < rlen; i++ ) 
		{
			if (!( *sptr+i ))
				break;
			else 	*(rptr+i) = *(sptr+i);
		}
	}
	for (; i < rlen; i++ )
		*(rptr+i) = ' ';
	return;
}			

/*	--------------	*/
/*	GetGlobalNames	*/
/*	--------------	*/
BPTR	GetGlobalNames()
{
	BPTR		wptr;
	EXAWORD		variables=0;
	EXAWORD		nbuflen=0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;

	if (!( DebugSymbols->GlobNameSelection )) 
	{
		check_global_load();
		check_for_local_load();
		for (	variables=0,
			lsymb = DebugSymbols->globals;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				nbuflen += variable_symbol_size(lsymb,GlobalDataTable);
				variables++;
			}
		}
		if (!( nbuflen ))
			return("global|variables");
		if (!(DebugSymbols->GlobNameSelection = allocate( nbuflen )))
			return("global|variables");
		wptr = DebugSymbols->GlobNameSelection;
		*wptr=0;
		for (	variables=0,
			lsymb = DebugSymbols->globals;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				if ( variables )
					strcpy(wptr++,"|");
				variable_symbol_string(wptr,lsymb,GlobalDataTable,0);	
				wptr += strlen(wptr);
				variables++;
			}
		}
	}
	if (!( DebugSymbols->GlobNameSelection )) 
		return("global|variables");
	else	return( DebugSymbols->GlobNameSelection );
}

/*	-------------	*/
/*	GetLocalNames	*/
/*	-------------	*/
BPTR	GetLocalNames()
{
	BPTR		wptr;
	EXAWORD		variables=0;
	EXAWORD		nbuflen=0;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;

	if (!( valid_local_data() )) 
		return("local|variables");
	else	check_for_local_load();

	if (!( DebugSymbols->LocalNameSelection )) 
	{
		for (	variables=0,
			lsymb = DebugSymbols->locals;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				nbuflen += (strlen(lsymb->name)+1);
				variables++;
			}
		}
		if (!( nbuflen ))
			return("local|variables");
		if (!(DebugSymbols->LocalNameSelection = allocate( nbuflen )))
			return("local|variables");
		wptr = DebugSymbols->LocalNameSelection;
		*wptr=0;
		for (	variables=0,
			lsymb = DebugSymbols->locals;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				if ( variables )
					strcat(wptr,"|");
				strcat(wptr,lsymb->name);
				wptr += strlen(wptr);
				variables++;
			}
		}
	}
	if (!( DebugSymbols->LocalNameSelection )) 
		return("local|variables");
	else	return( DebugSymbols->LocalNameSelection );
}

extern	EXAWORD	worktyp1;
extern	EXAWORD	worklen1;
extern	EXAWORD	workval1;
extern	BPTR	workptr1;

/*	------------------	*/
/*	DebugPrintVariable	*/
/*	------------------	*/
EXAWORD	DebugPrintVariable(BPTR buffer, EXAWORD buflen,BPTR vname, EXAWORD vid,EXAWORD mode)
{
	int	i;
	int	c;
	BYTE	wbuffer[256];
	if ( thisvarb(vid,1,1,1) == SOFTERROR )
		return( 1 );
	else
	{
		sprintf(wbuffer,"%s:[%x]",vname,vid);
		if ( strlen(wbuffer) > buflen )
			return(1);
		else	
		{
			strcpy(buffer,wbuffer);
			buflen -= strlen(buffer);
			buffer += strlen(buffer);
		}
		switch ( worktyp1 ) 
		{
			case	0 :
			case	4 :
				sprintf(wbuffer,"#=");
				if (!( mode )) 
				{
					if ( strlen(wbuffer) > buflen )
						return(1);
					else	strcpy(buffer,wbuffer);
					buflen -= strlen( buffer );
					buffer += strlen( buffer );
					sprintf(buffer,"%u",(workval1 & 0x00FF));
					return(1);
				}
				else	break;
	
			case	1 :
				sprintf(wbuffer,"%c=",0x0025);
				if (!( mode )) 
				{
					if ( strlen(wbuffer) > buflen )
						return(1);
					else	strcpy(buffer,wbuffer);
					buflen -= strlen( buffer );
					buffer += strlen( buffer );
					sprintf(buffer,"%u",(workval1 & 0x0FFFF));
					return(1);
				}
				else	break;
			case	5 :
				sprintf(wbuffer,":=",workval1);
				if (!( mode )) 
				{
					if ( strlen(wbuffer) > buflen )
						return(1);
					else	strcpy(buffer,wbuffer);
					buflen -= strlen( buffer );
					buffer += strlen( buffer );
					sprintf(buffer,"%lu",workval1);
					return(1);
				}
				else	break;
			case	3 :
				sprintf(wbuffer,"$=");
				if (!( mode )) 
				{
					if ( strlen(wbuffer) > buflen )
						return(1);
					else	strcpy(buffer,wbuffer);
					buflen -= strlen( buffer );
					buffer += strlen( buffer );
					for ( i=0; i < worklen1; i++ ) 
					{
						if ( i < buflen )
							sprintf(buffer++,"%c",*(workptr1++));
						else	break;
					}
					return(1);
				}
				else	break;
			case	2 :
				sprintf(buffer,"=");
				if (!( mode )) 
				{
					if ( strlen(wbuffer) > buflen )
						return(1);
					else	strcpy(buffer,wbuffer);
					buflen -= strlen( buffer );
					buffer += strlen( buffer );
					bcdtoa(workptr1,worklen1,buffer, buflen);
					return(1);
				}
				else	break;
		}
		for (i=0; i < worklen1; i++ ) 
		{
			if ( buflen > 3 ) 
			{
				sprintf(buffer," %x",(*(workptr1++) & 0X00FF));
				buflen -= strlen(buffer);
				buffer += strlen(buffer);
			}
			else	break;
		}
	}
	return(1);
}

/*	-------------------	*/
/*	DebugVariableSyntax	*/
/*	-------------------	*/
EXAWORD	DebugVariableSyntax(BPTR buffer, EXAWORD buflen, BPTR syntax, EXAWORD slen, EXAWORD mode)
{
	EXAWORD	i;
	EXAWORD	vid;
	BYTE	vuffer[32];

	if (( *syntax == 'D' ) ||  ( *syntax == 'd' )) { syntax++; slen--; }
	if (( *syntax == 'H' ) ||  ( *syntax == 'h' )) { syntax++; slen--; if (!( mode )) mode = 1; }
	for (i=0; i < slen; i++ ) if ( *(syntax+i) != ' ' ) break;

	syntax += i; slen -= i;
	if ( *syntax == '/' ) 
	{
		vid = HexaTcodeId( syntax );
		if ((vid & ISLOCAL) != 0)
			sprintf(vuffer,"LV[%x]",vid);
		else	sprintf(vuffer,"GV[%x]",vid);

		return( DebugPrintVariable(buffer, buflen, vuffer, vid, mode ) );
	}
	else	return(0);

}

struct	debug_variable_collection	
{
	SYMBOLPTR	symbol;
	EXAWORD		count;
	EXAWORD		nature;
	EXAWORD		first;
	EXAWORD		second;
} DVC = { (SYMBOLPTR) 0, 0, 0, 1, 1 } ;

/*	------------------	*/
/*	DebugSetDimensions	*/
/*	------------------	*/
VOID	DebugSetDimensions(  BPTR fptr, EXAWORD flen, BPTR sptr, EXAWORD slen )
{
	int	i;
	int	v;
	for ( i=0, v=0; i < flen; i++ ) 
	{
		if (( *(fptr+i) >= '0' )
		&&  ( *(fptr+i) <= '9' ))
			v = ((v*10) + (*(fptr+i) - '0'));
		else	break;
	}

	if (!(DVC.first=v)) 	DVC.first=1;

	for ( i=0, v=0; i < slen; i++ ) 
	{
		if (( *(sptr+i) >= '0' )
		&& ( *(sptr+i) <= '9' ))
			v = ((v*10) + (*(sptr+i) - '0'));
		else	break;
	}
	if (!(DVC.second=v))	DVC.second=1;
	return;
}

/*	--------------------	*/
/*	DebugVariableColumns	*/
/*	--------------------	*/
VOID	DebugVariableColumns(
	SYMBOLPTR lsymb, 
	BPTR idptr, EXAWORD idlen, 
	BPTR nomptr, EXAWORD nomlen, 
	BPTR offptr, EXAWORD offlen,
	BPTR valptr, EXAWORD lenval )
{
	EXAWORD		i;
	BYTE		muffer[256];
	sprintf(muffer,"%8.8X",lsymb->number);
	DebugTransferString(idptr,idlen,muffer);
	variable_symbol_string(muffer,lsymb,GlobalDataTable,1);
	DebugTransferString(nomptr,nomlen,muffer);
	if ( thisvarb(lsymb->number,DVC.first,DVC.second,1) == SOFTERROR ) 
	{
		sprintf(muffer," ERROR %u ",err_val);
		DebugTransferString(valptr,lenval,muffer);
		workptr1 = (BPTR) 0;
	}
	else	
	{
		switch ( worktyp1 ) 
		{
		case	4		:
		case	0		:
		case	1		:
		case	5		:
			sprintf(muffer,"%ld",workval1);
			break;
		case	2		:
			bcdtoa(workptr1,worklen1,muffer,64);
			break;
		case	3		:
			memset(muffer,' ',256);
			for ( i=0; i < worklen1; i++ ) 
			{
				if ( i < 256 )
					muffer[i] = *(workptr1+i);
				else	break;
				}
			break;
		}
		DebugTransferString(valptr,lenval,muffer);	
	}
	sprintf(muffer,"%8.8X",workptr1);
	DebugTransferString(offptr,offlen,muffer);
	return;
}

/*	-----------------	*/
/*	DebugVariableInfo	*/
/*	-----------------	*/
VOID	DebugVariableInfo(
	EXAWORD vitem, SYMBOLPTR lsymb, 
	BPTR idptr, EXAWORD idlen, 
	BPTR nomptr, EXAWORD nomlen, 
	BPTR offptr, EXAWORD offlen,
	BPTR valptr, EXAWORD lenval )
{
	EXAWORD		variables=0;
	for (	variables=0;
		lsymb != (SYMBOLPTR) 0;
		lsymb = lsymb->next, variables++ )
		if ( variables == vitem )
			break;
	if (!( lsymb )) return;
	DebugVariableColumns(lsymb,idptr,idlen,nomptr,nomlen,offptr,offlen,valptr,lenval);
	return;
}

/*	----------------	*/
/*	DebugGetVariable	*/
/*	----------------	*/
EXAWORD	DebugGetVariable( 
	EXAWORD item,
	BPTR optr,	EXAWORD	olen,
	BPTR nomptr, 	EXAWORD nomlen, 
	BPTR memptr,	EXAWORD	memlen,
	BPTR valptr,	EXAWORD lenval )
{
	SYMBOLPTR	lsymb;
	BYTE		muffer[256];
	EXAWORD		nbfound=0;
	BPTR		vtable;
	BPTR		vmemory;
	BPTR		varnom=(BPTR) 0;
	EXAWORD		vid=0;
	EXAWORD		i;
	EXAWORD		l;
	EXAWORD		c;
	EXAWORD		pass=0;
	EXAWORD		iterate=1;

	if (!( lsymb = DVC.symbol ))
		return(0);
	else if (!( DVC.count ))
		return(0);

	while (1) 
	{
		if ( iterate == item ) 
		{
			vid = (lsymb->number | DVC.nature);
			DebugVariableColumns(lsymb, optr,olen, nomptr,nomlen,memptr,memlen,valptr,lenval);
			return( 1 );
		}
		else if (!(lsymb = locate_symbol( lsymb->next, program.token)))
			return( 0 );
		else	iterate++;
	}
}

/*	-----------------	*/
/*	DebugViewVariable	*/
/*	-----------------	*/
EXAWORD	DebugViewVariable(BPTR buffer, EXAWORD buflen, EXAWORD mode)
{
	EXAWORD		nbfound=0;
	SYMBOLPTR	vsymb;
	BPTR		vtable;
	BPTR		vmemory;
	BPTR		varnom=(BPTR) 0;
	EXAWORD		vid=0;
	EXAWORD		i;
	EXAWORD		l;
	EXAWORD		c;
	EXAWORD		pass=0;
	if (!( editorGetToken( program.token, 0 )))
		return(0);
	else	
	{
		check_global_load();
		check_for_local_load();
		while (1) 
		{
			if (( vsymb = locate_symbol( DebugSymbols->locals , program.token )) != (SYMBOLPTR) 0)
			{
				vid = (vsymb->number | ISLOCAL);
				break;
			}
			else if (!( vsymb = locate_symbol( DebugSymbols->globals , program.token )))
			{
				if (!( pass )) 
				{
					pass=1;
					for (i=0; program.token[i] != 0; i++ )
					{
						if (((c = program.token[i]) >= 'a')
						&&  ( c <= 'z' ))
							program.token[i] -= ('a' - 'A');
					}
				}
				else	return(vsymb);
			}
			else
			{
				vid = (vsymb->number & TOGLOBAL);
				break;
			}
		}
		if ((DVC.symbol = vsymb) != (SYMBOLPTR) 0) 
		{
			DVC.count++;
			DVC.nature = (vid & ISLOCAL);
			while ((vsymb = locate_symbol( vsymb->next, program.token)) != (SYMBOLPTR) 0)
				DVC.count++;

		}
		else
		{
			DVC.count=0;
			DVC.nature=0;
		}
#ifndef	NOGIGO
		varnom = allocate_string( program.token );
		accept_variable_inspection(&varnom,&DVC.first,&DVC.second,&DVC.count);
#endif
		if ( varnom ) liberate( varnom );
		return(1);
	}
}

/*	-------------------	*/
/*	DebugStandardErrors	*/
/*	-------------------	*/
EXAWORD	DebugStandardErrors( EXAWORD evalue )
{
	return( 1 );
}

/*	-----------------	*/
/*	DebugShowVariable	*/
/*	-----------------	*/
EXAWORD	DebugShowVariable(BPTR buffer, EXAWORD buflen, EXAWORD item, EXAWORD locals, EXAWORD mode )
{
	SYMBOLPTR	lsymb;
	int	items;

	if (!( locals )) 
	{
		for (	items=0,
			lsymb = DebugSymbols->globals;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( item == items )
				return( DebugPrintVariable(buffer,buflen,lsymb->name,(lsymb->number & TOGLOBAL),mode) );
			else	items++;
		}
		return(0);
	}
	else	
	{
		for (	items=0,
			lsymb = DebugSymbols->locals;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( item == items )
				return( DebugPrintVariable(buffer,buflen,lsymb->name,(lsymb->number | ISLOCAL),mode) );
			else	items++;
		}
		return(0);
	}
}
	
/*	-----------------	*/
/*	GetBreakPointList	*/
/*	-----------------	*/
BPTR	GetBreakPointList()
{
	if ( BreakSelection ) 
	{
		liberate( BreakSelection );
		BreakSelection = (BPTR) 0;
	}
	if (!( BreakSelection = breakpointlist()))
		return("breakpoint|list");
	else	return( BreakSelection );
}

/*	-----------------	*/
/*	GetWatchPointList	*/
/*	-----------------	*/
BPTR	GetWatchPointList()
{
	if ( WatchSelection ) 
	{
		liberate( WatchSelection );
		WatchSelection = (BPTR) 0;
	}
	if (!( WatchSelection = watchpointlist()))
		return("watchpoint|list");
	else	return( WatchSelection );
}

/*	-------------	*/
/*	GetAssignList	*/
/*	-------------	*/
BPTR	GetAssignList()
{
	int	i;
	int	l;
	int	w=0;
	BPTR	wptr;
	BPTR	build_file_table_entry();
	EXAWORD	load_file_table_entry(EXAWORD);
	BPTR	bptr;

	if ( FileNameSelection ) 
	{
		liberate( FileNameSelection );
		FileNameSelection = (BPTR) 0;
	}

	l = get_dieze_files();

	for (	w=0,i=0; i < l; i++ ) 
	{
		if ( load_file_table_entry(i) != 0)
			break;
		w += 7;
		if (( bptr = build_file_table_entry()) != (BPTR) 0)
			w += strlen( bptr );
	}
	if (!( w ))
		return("assign|table");
	else if (!( FileNameSelection = allocate( w + 16 )))
		return("assign|table");

	wptr=FileNameSelection;
	*wptr = 0;
	for (	i=0; i < l; i++ ) 
	{
		if (load_file_table_entry(i) != 0) 
			break;
		if ( i ) strcpy(wptr++,"|");
		if (!( bptr = build_file_table_entry()))
			sprintf(wptr,"%u ",i);
		else	sprintf(wptr,"%u %s",i,bptr);
		wptr += strlen( wptr );
	}
	return(FileNameSelection);
}

/*	-----------------	*/
/*	ExportAssignTable	*/
/*	-----------------	*/
VOID	ExportAssignTable( char * sptr, char * nptr, int nlen )
{
	FILE *	handle;
	BPTR	nomfic;
	EXAWORD	i;
	EXAWORD	c;
	EXAWORD	nbass;
	BPTR	wptr;
	if (!( nomfic = allocate( nlen+1 ) ))
		return;
	for (i=0; i < nlen; i++ ) 
	{
		if (*(nptr+i) == ' ' )
			break;
		else if (!( *(nptr+i ) ))
			break;
		else 	*(nomfic+i) = *(nptr+i);
	}
	*(nomfic+i) = 0;
	
	if ((handle = fopen(nomfic,"w")) != (FILE *) 0) 
	{
		fprintf(handle,"--------------------\n");
		fprintf(handle,"Assign Table Entries\n");
		fprintf(handle,"--------------------\n");
		nbass = 0;
		while ( *sptr ) 
		{
			wptr = sptr;
			while (( *wptr ) && ( *wptr != '|' )) wptr++;
			c = *wptr; * wptr = 0;
			fprintf(handle,"%u : %s\n",nbass++,sptr);
			*wptr = c; 
			if (!( c ))
				sptr = wptr;
			else	sptr = (wptr+1);
		}
		fprintf(handle,"-------------\n");
		fprintf(handle,"End of Table \n");
		fprintf(handle,"-------------\n");
		fclose(handle);
	}
	liberate( nomfic );
	return;
}

/*	-------------	*/
/*	GetAttachList	*/
/*	-------------	*/
BPTR	GetAttachList()
{
	if ( AttachNameSelection ) 
	{
		liberate( AttachNameSelection );
		AttachNameSelection = (BPTR) 0;
	}
	if (!( AttachNameSelection = attachmentlist()))
		return("attach|list");
	else	return(AttachNameSelection);
}

/*	------------	*/
/*	GetStackList	*/
/*	------------	*/
BPTR	GetStackList()
{
	BPTR	BuildStackList();
	return(BuildStackList());
}

/*	--------------	*/
/*	GetLibraryList	*/
/*	--------------	*/
BPTR	GetLibraryList()
{
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;
	EXAWORD		nbuflen=0;
	EXAWORD		files=0;
	BPTR		wptr;
	if (!( DebugSymbols->LibrarySelection )) 
	{
		for (	files=0,nbuflen=0,
			lsymb = DebugSymbols->libraries;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				nbuflen += (strlen(lsymb->name)+1);
				files++;
			}
		}
		if ((!( nbuflen ))
		||  (!(DebugSymbols->LibrarySelection = allocate( nbuflen+16 ))))
			return("library|list");

		wptr = DebugSymbols->LibrarySelection;
		*wptr=0;
		for (	files=0,
			lsymb = DebugSymbols->libraries;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				if ( files ) strcpy(wptr++,"|");
				strcpy(wptr,lsymb->name);
				wptr += strlen(wptr);
				files++;
			}
		}
	}
	if (!( DebugSymbols->LibrarySelection )) 
		return("library|list");
	else	return( DebugSymbols->LibrarySelection );
}

/*	--------------------	*/
/*	DebugWindowUSeSource	*/
/*	--------------------	*/
EXAWORD	DebugWindowUSeSource( EXAWORD id )
{

}

/*	-------------	*/
/*	GetSourceList	*/
/*	-------------	*/
BPTR	GetSourceList()
{
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;
	EXAWORD		nbuflen=0;
	EXAWORD		files=0;
	BPTR		wptr;
	if (!( DebugSymbols->SourceSelection )) 
	{
		for (	files=0,nbuflen=0,
			lsymb = DebugSymbols->sources;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				nbuflen += (strlen(lsymb->name)+1);
				files++;
			}
		}
		if ((!( nbuflen ))
		||  (!(DebugSymbols->SourceSelection = allocate( nbuflen+16 ))))
			return("source|list");

		wptr = DebugSymbols->SourceSelection;
		*wptr=0;
		for (	files=0,
			lsymb = DebugSymbols->sources;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			if ( lsymb->name ) 
			{
				if ( files ) strcpy(wptr++,"|");
				strcpy(wptr,lsymb->name);
				wptr += strlen(wptr);
				files++;
			}
		}
	}
	if (!( DebugSymbols->SourceSelection )) 
		return("source|list");
	else	return( DebugSymbols->SourceSelection );
}

/*	--------------	*/
/*	GetObserveList	*/
/*	--------------	*/
BPTR	GetObserveList()
{
	return("observe|list");
}

/*	-----------------	*/
/*	 GetRegisterList	*/
/*	-----------------	*/
BPTR	GetRegisterList(EXAWORD hexdec)
{
	int	r;
	BPTR	wptr;
	if ((!( RegisterSelection ))
	&&  (!( RegisterSelection = allocate((40 * 56 )))))
		return("registers|list");

	wptr = RegisterSelection;
	*wptr = 0;

	for (r=0; r <= 53; r++ ) 
	{
		if ( r ) strcpy(wptr++,"|");
		generate_register(r,wptr,hexdec);
		wptr += strlen(wptr);
	}
	return(RegisterSelection);
}

#ifdef NOGIGO
int	hardcolumns()	{	return(0);	}
int	hardrows()	{	return(0);	}
int	hide()		{	return(0);	}
int	show()		{	return(0);	}
#endif

/*	---------------------	*/
/*	ProgramWindowOnCreate	*/
/*	---------------------	*/
VOID	ProgramWindowOnCreate(int atx, int aty, int nbx, int nby)
{
#ifndef NOGIGO
	program.x = atx; program.y = aty; program.w = nbx; program.h = nby;
	program.width = program.height = 0;
	program.buffer= (void *) 0;
	if ((!(program.width = hardcolumns()))
	||  (!(program.height= hardrows()))
	||  (!(program.buffer= visual_buffer(0,0,program.width,program.height)))) 
	{
		program.buffer= (void *) 0;
		program.width = program.height =0;
	}
#endif
	return;
}

/*	----------------------	*/
/*	ProgramWindowLoseFocus	*/
/*	----------------------	*/
VOID	ProgramWindowLoseFocus()
{
	return;
}

/*	-------------------	*/
/*	ProgramWindowOnShow	*/
/*	-------------------	*/
VOID	ProgramWindowOnShow(int hsbv, int vsbv)
{
#ifndef NOGIGO
	int	pixelsize=get_pixel_size();
	if (!( program.buffer))
		return;
	else	visual_buffer_show( program.buffer,(hsbv * pixelsize),vsbv, program.x,program.y,program.w,program.h );
#endif
	return;
}

/*	---------------------	*/
/*	ProgramWindowOnRemove	*/
/*	---------------------	*/
VOID	ProgramWindowOnRemove()
{
#ifndef NOGIGO
	if ( program.buffer ) {
		visual_drop( program.buffer );
		program.buffer = (BPTR) 0;
		}
#endif
	return;
}

/*	-----------------	*/
/*	 set_program_dpi	*/
/*	-----------------	*/
static	VOID	set_program_dpi()
{
#ifndef NOGIGO
	set_event_parameter(59,program.dpi);
#endif
	return;
}

/*	-----------------	*/
/*	 get_program_dpi	*/
/*	-----------------	*/
static	VOID	get_program_dpi()
{
#ifndef NOGIGO
	program.dpi = get_event_parameter(59);
	set_event_parameter(59,75);
#endif
	return;
}

#ifndef	NOGIGO
/*	-------------------------	*/
/*	 restore_after_execution	*/
/*	-------------------------	*/
static	VOID	restore_after_execution()
{
	switch ( program.execution )
	{
	case	1	:	/* execute single step */

		program.mousemask = get_mimo_mask();
		set_mimo_mask( program.debugmask );


		if ((program.hidden = hidecount()) != 0)
			while ( show(0,0,0,0) != 0 );


		get_program_viewport();

		if ( program.buffer )
			cancel_pixel_capture( program.buffer );

		set_debug_viewport();

		break;

	case	2	:	/* execute till break */
		program.mousemask = get_mimo_mask();
		set_mimo_mask( program.debugmask );
	
		if ((program.hidden = hidecount()) != 0)
			while ( show(0,0,0,0) != 0 );

		if ( program.buffer )
			visual_buffer_get( program.buffer, 0,0 );

		get_program_viewport();
		set_debug_viewport();

	}
	program.execution = 0;
	return;
}
#endif

/*	-----------------	*/
/*	ExecuteSingleStep	*/
/*	-----------------	*/
VOID	ExecuteSingleStep()
{
	int	i;

#ifndef	NOGIGO
	get_debug_viewport();
	set_program_viewport();
	use_program_palette();

	if ( program.buffer )
	{
		background_pixel_capture( program.buffer );
		for (i=0; i < program.hidden; i++)
			hide();
	}

	program.debugmask= get_mimo_mask();

	if (!( program.mousemask ))
		program.mousemask = get_mimo_mask();
	else	set_mimo_mask( program.mousemask );
#endif

	program.execution = 1;
	set_program_dpi();
	execute_single_step(0);
	get_program_dpi();

#ifndef	NOGIGO
	use_debug_palette();
	restore_after_execution();
#endif
	return;
}

/*	----------------	*/
/*	ExecuteTillBreak	*/
/*	----------------	*/
VOID	ExecuteTillBreak()
{
	int	i;
#ifndef	NOGIGO
	get_debug_viewport();
	set_program_viewport();
	use_program_palette();

	if ( program.buffer ) 
	{
		visual_buffer_put( program.buffer, 0,0 );

		for (i=0; i < program.hidden; i++)
			hide();

	}

	program.debugmask= get_mimo_mask();

	if (!( program.mousemask ))
		program.mousemask = get_mimo_mask();
	else	set_mimo_mask( program.mousemask );

#endif
	program.execution = 2;
	set_program_dpi();
	execute_till_break(1);	
	get_program_dpi();
#ifndef	NOGIGO
	use_debug_palette();
	restore_after_execution();
#endif
	return;
}

/*	----------------	*/
/*	 DebugWatchShow 	*/
/*	----------------	*/
EXAWORD	DebugWatchShow( char * nptr, unsigned long before, unsigned long after  )
{
	char *		varnom=(char *) 0;
	char *		varadr=(char *) 0;
	BYTE		muffer[64];
	if (!( GraphicalDebug() )) return(0);
#ifndef	NOGIGO
	varnom = allocate_string( nptr );
	restore_after_execution();
	sprintf(muffer,"%08.8lx",after);
	varadr = allocate_string( muffer );
	accept_watch_inspection(&varadr,&varnom);
	if ( varnom ) liberate( varnom);
	if ( varadr ) liberate( varadr);
#endif
	return(1);
}

/*	-------------	*/
/*	DebugDumpZone	*/
/*	-------------	*/
VOID	DebugDumpZone( BPTR nptr, EXAWORD nlen, BPTR optr, EXAWORD olen )
{
	BYTE	muffer[256];
	BPTR	varnom;
	BPTR	varadr;
#ifndef	NOGIGO
	unsigned long adresse=0L;
	EXAWORD	i;
	for ( i=0; i < nlen; i++ )
		muffer[i] = *(nptr+i);
	muffer[i] = 0;
	varnom = allocate_string( muffer );
	for (i=0; i < olen; i++ )
		muffer[i] = *(optr+i);
	muffer[i] = 0;
	varadr = allocate_string( muffer );
	accept_watch_inspection(&varadr,&varnom);
	if ( varnom ) liberate( varnom);
	if ( varadr ) liberate( varadr);
#endif
	return;
}

/*	------------------------	*/
/*	DebugGlobalVariableCount	*/
/*	------------------------	*/
EXAWORD	DebugGlobalVariableCount()
{
	if (!( DebugSymbols ))
		return(0);
	else 	return(DebugSymbols->globalcount);
}

/*	-----------------	*/
/*	 DebugViewMemory	*/
/*	-----------------	*/
EXAWORD	DebugViewMemory()
{
	BYTE		muffer[64];
	EXAWORD		nbfound=0;
	SYMBOLPTR	vsymb;
	BPTR		vtable;
	BPTR		vmemory;
	EXAWORD		vid=0;
	EXAWORD		i;
	EXAWORD		l;
	EXAWORD		c;
	EXAWORD		pass=0;
	BPTR		varnom=(BPTR) 0;
	BPTR		varadr=(BPTR) 0;
	if (!( editorGetToken( program.token )))
		return(0);
	else if (!( DebugSymbols ))
		return(0);
	else
	{
		check_global_load();
		check_for_local_load();
		while (1)
		{
			if (( vsymb = locate_symbol( DebugSymbols->locals , program.token )) != (SYMBOLPTR) 0)
			{
				vid = (vsymb->number | ISLOCAL);
				break;
			}
			else if (!( vsymb = locate_symbol( DebugSymbols->globals , program.token )))
			{
				if (!( pass ))
				{
					pass=1;
					for (i=0; program.token[i] != 0; i++ )
					{
						if (((c = program.token[i]) >= 'a')
						&&  ( c <= 'z' ))
							program.token[i] -= ('a' - 'A');
					}
				}
				else	return(1);
			}
			else
			{
				vid = (vsymb->number & TOGLOBAL);
				break;
			}
		}
		if ( thisvarb(vsymb->number,1,1,1) == SOFTERROR )
			return(1);
#ifndef	NOGIGO
		varnom = allocate_string( vsymb->name);
		sprintf(muffer,"%08.8X",workptr1);
		varadr = allocate_string( muffer );
		accept_watch_inspection(&varadr,&varnom);
#endif
		if ( varnom ) liberate( varnom);
		if ( varadr ) liberate( varadr);
		return(1);
	}
}

/*	This is necessary to inhibit lowlevel informational searh errors that may be thrown up 	*/
/*	when looking for correspondance blocks.							*/

EXAWORD	StandardErrorStatus=0;

/*	-------------------------	*/
/*	 inhibit_standard_errors	*/
/*	-------------------------	*/
EXAWORD	inhibit_standard_errors()
{
	return( StandardErrorStatus );
}

/*	-------------------	*/
/*	SetSourceBreakPoint	*/
/*	-------------------	*/
EXAWORD	SetSourceBreakPoint(int mode)
{
	TRAPTR		ltrap;
	EXAWORD		nombre=0;
	unsigned long	topline;
	unsigned long	fileline;
	unsigned long	lastline;
	BPTR		filename;
	SYMBOLPTR	lsymb=(SYMBOLPTR) 0;
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	CORRESPTR	linfos=(CORRESPTR) 0;
	if (!( editorGetPosition(&filename,&fileline,&topline,&lastline) ))
		return(0);
	else if (!( fsymb = locate_symbol( DebugSymbols->sources, filename ) ))
		return(0);
	else if (!( DebugSymbols ))
		return(0);
	else	
	{
		StandardErrorStatus=1;
		for (	nombre=0,
			lsymb = DebugSymbols->procedures;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			for ( 	linfos = locate_correspondance( lsymb, 0 );
				linfos != (CORRESPTR) 0;
				linfos = linfos->next ) 
			{
				if ( linfos->file_number != fsymb->number )
					continue;
				else if ( linfos->file_offset != fileline )
					continue;
				else if ( mode == 0x007F )
					deposepiege((lsymb->number / (8*WORDSIZE)),linfos->tcode_offset,1,(BPTR) 0);
				else if ((ltrap = posepiege((lsymb->number / (8*WORDSIZE)),linfos->tcode_offset,1,mode,(BPTR) 0)) != (TRAPTR) 0) {
					ltrap->file_number = fsymb->number;
					ltrap->file_line   = linfos->file_offset;
					nombre++;
				}
			}
		}
		for (	lsymb = DebugSymbols->segments;
			lsymb != (SYMBOLPTR) 0;
			lsymb = lsymb->next ) 
		{
			for ( 	linfos = locate_correspondance( lsymb, 0 );
				linfos != (CORRESPTR) 0;
				linfos = linfos->next ) 
			{
				if ( linfos->file_number != fsymb->number )
					continue;
				else if ( linfos->file_offset != fileline )
					continue;
				else if ( mode == 0x007F )
					deposepiege(lsymb->number,linfos->tcode_offset,0,(BPTR) 0);
				else if ((ltrap = posepiege(lsymb->number,linfos->tcode_offset,0,mode,(BPTR) 0)) != (TRAPTR) 0) {
					ltrap->file_number = fsymb->number;
					ltrap->file_line   = linfos->file_offset;
					nombre++;
				}
			}
		}
		StandardErrorStatus=0;
		return(nombre);
	}
}

/*	---------------------	*/
/*	ClearSourceBreakPoint	*/
/*	---------------------	*/
EXAWORD	ClearSourceBreakPoint(int mode)
{
	SetSourceBreakPoint(0x007F);
}

/*	--------------	*/
/*	GotoSourceLine	*/
/*	--------------	*/
EXAWORD	GotoSourceLine()
{
	return(  SetSourceBreakPoint(0) );
}

/*	---------------------	*/
/*	ControlWindowSetBreak	*/
/*	---------------------	*/
VOID	ControlWindowSetBreak(
	EXAWORD	type,		/* 0: SEGM, 1: PROC, 2: VARB 	*/
	EXAWORD	mode,		/* 0: TEMP, 1: PERM		*/
	EXAWORD	item,		/* number in list		*/
	EXAWORD	offset		/* offset from item start	*/
	)
{
	TRAPTR		ltrap;
	CORRESPTR	linfos;
	SYMBOLPTR	lsymb;
	EXAWORD		items;
	switch ( type ) 
	{
		case	0 : /* segment 	 */
			for (	items=0,
				lsymb = DebugSymbols->segments;
				lsymb != (SYMBOLPTR) 0;
				lsymb = lsymb->next ) 
			{
				if ( item == items ) 
				{
					if (((ltrap = posepiege(lsymb->number,offset,type,mode,(BPTR) 0)) != (TRAPTR) 0)
					&&   ( lsymb != (SYMBOLPTR) 0 )
					&&  (( linfos = locate_correspondance( lsymb, offset )) != (CORRESPTR) 0)) 
					{
						ltrap->file_number = linfos->file_number;
						ltrap->file_line   = linfos->file_offset;
					}
					break;
				}
				else	items++;
			}
			break;

		case	1 : /* procedure */
			for (	lsymb = DebugSymbols->procedures;
				lsymb != (SYMBOLPTR) 0;
				lsymb = lsymb->next )
				if ( lsymb->number == ( item * (8*WORDSIZE) ))
					break;

			if (((ltrap = posepiege(item,offset,type,mode,(BPTR) 0)) != (TRAPTR) 0)
			&&   ( lsymb != (SYMBOLPTR) 0 )
			&&  (( linfos = locate_correspondance( lsymb, offset )) != (CORRESPTR) 0)) 
			{
				ltrap->file_number = linfos->file_number;
				ltrap->file_line   = linfos->file_offset;
			}
			break;

		case	2 : /* variable */
			for (	items=0,
				lsymb = connect_global_symbols();
				lsymb != (SYMBOLPTR) 0;
				lsymb = lsymb->next ) 
			{
				if ( item == items ) 
				{
					if ( thisvarb(lsymb->number,1,1,1) == SOFTERROR )
						return;
					WatchMake(lsymb->name,mode,1,1,lsymb->number);
					break;
				}
				else	items++;
			}
			break;

	}
	return;
}

/*	-----------------	*/
/*	 VisualDebugOpen	*/
/*	-----------------	*/
VOID	VisualDebugOpen( BPTR visifig )
{
	EXAWORD	mode=512;
	BPTR	eptr;
	if (( eptr = (BPTR) getenv("VEXADBRGB")) != (BPTR) 0) 
	{
		if ( *eptr != '0' )
			mode = 512;
		else	mode = 256;
	}
#ifndef	NOGIGO
	set_configuration_name(visifig);
	use_visual_mouse();
	visual_debug_attach_mode(mode);
#endif
	FileNameSelection=(BPTR) 0;
	AttachNameSelection=(BPTR) 0;
	ObserveSelection=(BPTR) 0;
	StackSelection=(BPTR) 0;
	BreakSelection=(BPTR) 0;
	WatchSelection=(BPTR) 0;
	RegisterSelection=(BPTR) 0;
	return;
}

/*	----------------	*/
/*	VisualDebugClose	*/
/*	----------------	*/
VOID	VisualDebugClose()
{
	if ( FileNameSelection ) 
	{
		liberate(FileNameSelection);
		FileNameSelection=(BPTR) 0;
	}
	if ( AttachNameSelection ) 
	{
		liberate(AttachNameSelection);
		AttachNameSelection=(BPTR) 0;
	}
	if ( ObserveSelection ) 
	{
		liberate(ObserveSelection);
		ObserveSelection=(BPTR) 0;
	}
	if ( StackSelection ) 
	{
		liberate(StackSelection);
		StackSelection=(BPTR) 0;
	}
	if ( BreakSelection ) 
	{
		liberate(BreakSelection);
		BreakSelection=(BPTR) 0;
	}
	if ( WatchSelection ) 
	{
		liberate(WatchSelection);
		WatchSelection=(BPTR) 0;
	}
	if ( RegisterSelection ) 
	{
		liberate(RegisterSelection);
		RegisterSelection=(BPTR) 0;
	}
	return;
}

/*	----------------	*/
/*	CheckBreakPoints	*/
/*	----------------	*/
EXAWORD	CheckBreakPoints(EXAWORD fileid)
{
	unsigned long	topline;
	unsigned long	fileline;
	unsigned long	lastline;
	BPTR		filename;
	EXAWORD		i;
	TRAPTR		ltrap;
	SYMBOLPTR	fsptr;

	if (!( editorGetPosition(&filename,&fileline,&topline,&lastline) ))
		return(0);

	if (!( fileid )) 
	{
		if (!( fsptr = locate_symbol( DebugSymbols->sources, filename ) ))
			return(0);
		else	fileid = fsptr->number;
	}

	for (i=0; i < 40; i++ ) program.symbols[i] = 0;

	for ( 	ltrap = TrapBase;
		ltrap != (TRAPTR) 0;
		ltrap = ltrap->next) 
	{
		if ( ltrap->file_number != fileid )
			continue;
		else if ( ltrap->file_line < topline )
			continue;
		else if ( ltrap->file_line > lastline )
			continue;
		else 	
		{
			program.symbols[(ltrap->file_line-topline)]=1;
			continue;
		}	
	}
	if (( program.execfile != 0	   )
	&&  ( program.execfile == fileid   )
	&&  ( program.execline >= topline  ) 
	&&  ( program.execline <= lastline ))
		program.isexecute=((program.execline-topline)+1);
	else	program.isexecute=0;
	return;

}

/*	----------------	*/
/*	IsExecutionPoint	*/
/*	----------------	*/
EXAWORD	IsExecutionPoint(EXAWORD id)
{
	if (!( program.isexecute ))
		return( 0 );
	else if ((program.isexecute-1) == id)
		return(1);
	else	return(0);
}

/*	------------	*/
/*	IsBreakPoint	*/
/*	------------	*/
EXAWORD	IsBreakPoint(EXAWORD id)
{
	return( program.symbols[id] );

}

/*	-----------------	*/
/*	 GetTextFontList	*/
/*	-----------------	*/
BPTR	DbTextFontList=(BPTR) 0;
BPTR	GetTextFontList()
{
#ifndef	NOGIGO
	BPTR	guifontlist();
	if (!( DbTextFontList ))
		DbTextFontList = guifontlist();
#endif
	if ( DbTextFontList )
		return( DbTextFontList );
	else	return( "standard.fmf" );
}

VOID	enter_modal()	{	return;		}
VOID	leave_modal()	{	return;		}

/*	-----------------	*/
/*	 editorOnCommand	*/
/*	-----------------	*/
EXAWORD	editorOnCommand(BPTR cptr,EXAWORD clen )
{
	return(27);
}

/*	-----------------	*/
/*	  editorOnError 	*/
/*	-----------------	*/
EXAWORD	editorOnError(int gravite, BPTR cptr,BPTR mptr)
{
	return(0);
}

/*	----------------	*/
/*	 editorOnStatus 	*/
/*	----------------	*/
EXAWORD	editorOnStatus( EXAWORD option, EXAWORD value )
{
	return(0);
}

/*	------------------	*/
/*	   editorOnFont 	*/
/*	------------------	*/
EXAWORD	editorOnFont(EXAWORD fontid)
{
	int	v=fontid+1;
	if ( v != aed.font ) 
	{
		aed.font = (fontid+1);	
		aed.fontchange=1;
	}
	return(0);
}

/*	-------------------	*/
/*	handle_style_errors	*/
/*	-------------------	*/
EXAWORD	handle_style_errors( EXAWORD count, BPTR filename)
{
	return(0);
}

#endif	/* _exdbwui_c */
	/* ---------- */
