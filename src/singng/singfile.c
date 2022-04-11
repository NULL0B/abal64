#ifndef	_singfile_c
#define	_singfile_c

#include <stdio.h>
#include "sing.h"
#include "singclas.h"
#include "singlang.h"
#include "singprod.h"
#include "singtype.h"
#include "singtool.h"
#include "singfile.h"
#include "vframe.h"

extern	struct	screen_control	Context;
extern	char 	LaPaterne[];
extern	char	namebuffer[];

char	*	file_message( struct file_control * fptr )
{
	if ( fptr ) {
		if ( fptr->identifier )
			return( fptr->identifier );
		else if ( fptr->loadname )
			return( fptr->loadname );
		else if ( fptr->prodname )
			return( fptr->prodname );
		else if ( fptr->filename )
			return( fptr->filename );
		}
	return("[file]");
}

int	is_valid_filename( char * nptr )
{
	if (!( nptr ))
		return(0);
	else if (!( *nptr ))
		return(0);
	while ( *nptr == ' ' )
		nptr++;
	if (!( *nptr ))
		return(0);
	else	return(1);
}

private	void	check_file_Widget( struct form_item * wptr, int isint, int bytes )
{
	int	f;
	int	fh;
	int	fw;

	/* Ensure non-integral values are edit fields */
	/* ------------------------------------------ */
	if ((!( isint )) 
	&&  (( wptr->Contents.style & _FRAME_TYPE ) != _EDIT_FRAME)) {
		wptr->Contents.style  = _EDIT_FRAME;
		}
	
	/* For Edit field type */
	/* ------------------- */
	if (wptr->Contents.style == _EDIT_FRAME ) {

		/* Ensure fixed font */
		/* ----------------- */
		if ( wptr->Contents.font != 1 )
			wptr->Contents.font = 1;

		/* Collect font characteristics */
		/* ---------------------------- */
		if (!( f = wptr->Contents.font ))
			return;
		else	{
			fw = guifontsize(f);
			fh = (fw >> 8);
			fw &= 0x00FF;
			}

		/* Ensure box height suffisiant */
		/* ---------------------------- */
		if ( wptr->Contents.h < (fh+2) )
			wptr->Contents.h = (fh+2);

		/* Ensure box width suffisiant */
		/* --------------------------- */
		if ( wptr->Contents.w < ((fw*bytes)+2))
			wptr->Contents.w = ((fw*bytes)+2);

		}
	return;

}


private	struct form_control * validate_Form(struct form_control * fptr, struct standard_class * cptr, char * sptr )
{
	struct	standard_list * lptr;
	struct	standard_node * nptr;
	struct standard_member * mptr;
	struct data_member * dptr;
	struct form_item * wptr;

	if (!( cptr ))		return( fptr );
	else if (!( fptr )) {
		if (!( sptr ))	
			return( fptr );
		else if (!( fptr = load_Form(fptr, sptr, 0, 1 ) )) {
			if (!( fptr = allocate_Form( sptr ) ))
				return(fptr);
			}
		}
	if (!(lptr = cptr->members ))
		return(fptr);

	for (	nptr = lptr->first;
		nptr != (struct standard_node *) 0;
		nptr = nptr->next ) {
		if (!( mptr = nptr->contents ))
			continue;
		else	{
			switch ( mptr->nature ) {
				case	_MEMBER_DATA	 :
					if (!( wptr = validate_Widget( fptr, mptr->name )))
						continue;
					switch ( mptr->type.type & _BASIC_TYPE ) {
						case	_TYPE_BYTE	:
							check_file_Widget(wptr,1,5);
							continue;
						case	_TYPE_WORD	:
							check_file_Widget(wptr,1,7);
							continue;
						case	_TYPE_LONG	:
							check_file_Widget(wptr,1,15);
							continue;
						case	_TYPE_FLOAT	:
							check_file_Widget(wptr,0,24);
							continue;
						case	_TYPE_BCD 	:
							check_file_Widget(wptr,0,24);
							continue;
						case	_TYPE_STRING	:
						case	_TYPE_CLASS	:
							dptr = (struct data_member *) mptr;
							check_file_Widget(wptr,0,dptr->size);
							continue;
						}
					continue;

				case	_MEMBER_CONSTANT :
				case	_MEMBER_METHOD	:
				default			:
					continue;
				}

			}
		}

	return( fptr );
}

private	void	validate_ClassNames(struct file_control * fptr)
{
	if (!( fptr )) return;

	if ( is_valid_filename( fptr->recordclass ) ) {
		if ( fptr->record != ( struct standard_class * ) 0 ) {
			if (!( string_compare( 	fptr->recordclass,
						fptr->record->loadname) )) {
				fptr->record = liberate_Class( fptr->record );
				}
			}
		if (!( fptr->record )) {
			if (((fptr->record = load_Class( fptr->recordclass, 1 )))
			&&  ( fptr->isvariable & 2))
				fptr->dataform = validate_Form( fptr->dataform, fptr->record, fptr->recordclass );
			}
		}
	else if ( fptr->record != ( struct standard_class * ) 0 )
		fptr->record = liberate_Class( fptr->record );


	if ( is_valid_filename( fptr->indexclass ) ) {
		if ( fptr->index != ( struct standard_class * ) 0 ) {
			if (!( string_compare( 	fptr->indexclass,
						fptr->index->loadname ) )) {
				fptr->index = liberate_Class( fptr->index );
				}
			}
		if (!( fptr->index )) {
			if (((fptr->index = load_Class( fptr->indexclass, 1 )))
			&&  ( fptr->isvariable & 4))
				fptr->indexform = validate_Form( fptr->indexform, fptr->index, fptr->indexclass );
			}
		}
	else if ( fptr->index != ( struct standard_class * ) 0 )
		fptr->index = liberate_Class( fptr->index );


	return;
}

public	struct file_control * 	liberate_File(struct file_control *  fptr)
{
	if ( fptr ) {

		if ( fptr->prodname )
			fptr->prodname = liberate( fptr->prodname );
		if ( fptr->loadname )
			fptr->loadname = liberate( fptr->loadname );
		if ( fptr->filename )
			fptr->filename = liberate( fptr->filename );
		if ( fptr->identifier )
			fptr->identifier = liberate( fptr->identifier );
		if ( fptr->secondary )
			fptr->secondary = liberate( fptr->secondary );

		if ( fptr->document )
			fptr->document = liberate( fptr->document );

		if ( fptr->recordclass )
			fptr->recordclass = liberate( fptr->recordclass );

		if ( fptr->record )
			fptr->record = liberate_Class( fptr->record );

		if ( fptr->dataform )
			fptr->dataform = liberate_Form( fptr->dataform );

		if ( fptr->indexclass )
			fptr->indexclass = liberate( fptr->indexclass );

		if ( fptr->index )
			fptr->index = liberate_Class( fptr->index );

		if ( fptr->indexform )
			fptr->indexform = liberate_Form( fptr->indexform );

		if ( fptr->dependance )
			fptr->dependance = liberate( fptr->dependance );

		if ( fptr->construction )
			fptr->construction = liberate( fptr->construction );


		fptr = liberate( fptr );	
		}
	return((struct file_control *) 0);
}

public	struct file_control * 	allocate_File(char * nptr) 
{
	struct	file_control * fptr;
	if (!(fptr = (struct file_control *) allocate( sizeof( struct file_control ) )))
		return( fptr );
	else if (!( fptr->treenode = allocate_for_treeview())) {
		liberate( fptr );
		return((struct file_control *) 0);
		}
	else	{
		fptr->host       = (void *) 0;
		fptr->recordclass=
		fptr->indexclass=
		fptr->dependance=
		fptr->construction=
		fptr->loadname = 
		fptr->prodname = 
		fptr->filename = 
		fptr->identifier   = 
		fptr->secondary=(char *) 0;
		fptr->handle   = 64;
		fptr->language    = production_language();
		fptr->program  = 1;
		fptr->overlay  	= 0;
		fptr->filetype  = 2;
		fptr->recordsize= 256;
		fptr->isvariable= 0;
		fptr->indexalign= 0;
		fptr->indexsize = 16;
		fptr->loadstamp =
		fptr->savestamp = 0L;
		fptr->record    =
		fptr->index     = (struct standard_class*) 0;
		fptr->dataform  =
		fptr->indexform = (struct form_control*) 0;
		if ( nptr ) {
			if (!(fptr->identifier = allocate_string(nptr)))
				return( liberate_File(fptr) );
			if (!(fptr->loadname= allocate_string(nptr)))
				return( liberate_File(fptr) );
			else if (!(fptr->prodname= allocate_string(nptr)))
				return( liberate_File(fptr) );
			}
		}
	return(fptr);
}


private	int	file_properties(struct file_control * fptr)
{
	int	status;
	int	isvarlen;
	int	isdataform;
	int	isindexform;

	if (!( fptr ))	return( 27 );

	isvarlen 	= (fptr->isvariable & 1 ? 1 : 0 );
	isdataform	= (fptr->isvariable & 2 ? 1 : 0 );
	isindexform	= (fptr->isvariable & 4 ? 1 : 0 );

	if ((status = accept_file_properties(
			&fptr->identifier,	/* S */
			&fptr->handle,		/* W */
			&fptr->filename,	/* S */
			&fptr->filetype,	/* W */
			&fptr->prodname,	/* S */
			&fptr->dependance,	/* S */
			&fptr->recordclass,	/* S */
			&fptr->recordsize,	/* W */
			&isvarlen,        	/* W */
			&isdataform,		/* W */
			&fptr->indexalign,	/* W */
			&fptr->indexclass,	/* S */
			&fptr->indexsize,	/* W */
			&isindexform		/* W */
			/* fptr->secondary  */
			)) != 27) {
		if ( isvarlen )
			fptr->isvariable |= 1;
		else	fptr->isvariable &= ~1;
		if ( isdataform )
			fptr->isvariable |= 2;
		else	fptr->isvariable &= ~2;
		if ( isindexform )
			fptr->isvariable |= 4;
		else	fptr->isvariable &= ~4;
		validate_ClassNames( fptr );
		}
	return( status );
}


public	void	draw_File(struct file_control * fptr )
{
	return;
}

public	int	is_FileEvent(struct file_control * fptr, int x, int y)
{
	return( -1 );
}

public	int	edit_File(struct file_control ** ffptr, int mode)
{
	struct file_control *  fptr;

	int	event;

	if (!( ffptr ))
		return(0);
	else	fptr = *ffptr;

	if ((!( fptr ))
	&&  (!( fptr = allocate_File("newfile") )))
		return(0);

	else	{
		Context.File = fptr;	
		draw_console();
		}


	while (1) {

		while (((event = mimo_getch())   == 256)
		&&     ((event = handle_event()) == 256));

		switch ( event ) {

			case	_EDIT_CLASS	:
				if ( is_valid_filename( fptr->recordclass ) )
					(void) edit_Class( &fptr->record, 0 );
				draw_console();
				continue;

			case	_EDIT_TEXT	:
				if ( fptr->prodname  )
					use_editor( fptr->prodname, fptr->language );
				draw_console();
				continue;

			case	_EDIT_PROPERTIES	:
			case	CTRL_I			:

				(void) file_properties(fptr);
				draw_console();
				continue;


			case	_FILE_PRODUCE	:
				export_File(fptr,0);
				draw_console();
				continue;

			case	_FILE_COMPARE	:
				compare_Files(fptr->prodname,(char *) 0);
				draw_console();
				continue;

			case	_FILE_SAVE		:
				save_File(fptr,0);
				draw_console();
				continue;
			case	_FILE_QSAVE		:
				save_File(fptr,QUICK);
				draw_console();
				continue;

			case	_FILE_LOAD		:
				draw_console();
				continue;

			case	_VIEW_TEXT		:
			case	_VIEW_IMAGE		:
			case	_EDIT_GRAPH		:
			case	_LEAVE_SING		:
				break;

			default				:
				continue;


			}

		break;
		}

	Context.File = (struct file_control *) 0;
	*ffptr = fptr;
	return( event );
}

public	struct file_control * 	load_File(char * nptr,int automatic)
{
	struct file_control * 	fptr=(struct file_control*) 0;

	FILE		*	h;
	char		*	loadname;
	char		*	sptr;
	char		*	vptr;
	int			o;

	if (!( loadname = allocate_string( nptr ) ))
		return((struct file_control *) 0);
	else if (!( loadname = verify_extension( loadname, DATABASE_EXTENSION ) ))
		return((struct file_control *) 0);
	else if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_form_load(&loadname) == 27 ) {
			draw_console();
			loadname = liberate( loadname );
			return((struct file_control *) 0);
			}
		status_message(loadname,3);
		}

	while (!(h = fopen(loadname,"rb"))) {
		if ( automatic & _INHIBIT_PROPERTIES )
			break;
		else if ( file_not_found( loadname ) == 27 )
			break;
		}

	if ( h != (FILE *) 0) {

		if (!( fptr = allocate_File(loadname))) {
			fclose(h);
			loadname = liberate( loadname );
			return(fptr);
			}
		else	fptr->loadname = loadname;

		if (!( automatic & _INHIBIT_STATUS ))
			status_message(fptr->loadname,3);

		if ((!(sptr = get_string(h)))
		||  (!( string_compare(sptr,"FILE" )))
		||  (!(vptr = get_string(h)))) {
			incorrect_filetype(loadname);
			fclose(h);
			return(fptr);
			}
		else	{
			macro_get_word(h,o);

			macro_get_string(h,fptr->identifier);
			macro_get_word(h,fptr->language);
			macro_get_word(h,fptr->program);
			macro_get_word(h,fptr->overlay);
			macro_get_string(h,fptr->prodname);

			macro_get_string(h,fptr->filename);
			macro_get_word(h,fptr->handle);
			macro_get_word(h,fptr->filetype);
			macro_get_word(h,fptr->recordsize);
			macro_get_word(h,fptr->indexsize);
			macro_get_word(h,o);
			macro_get_string(h,fptr->secondary);
			macro_get_word( h, fptr->doctool );
			macro_get_string(h, fptr->document );
			macro_get_string(h, fptr->recordclass );
			macro_get_string(h, fptr->indexclass );
			macro_get_string(h, fptr->dependance );
			macro_get_word( h, fptr->indexalign );
			macro_get_word( h, fptr->isvariable );

			fptr->index  = (struct standard_class *) 0;
			fptr->record = (struct standard_class *) 0;
			validate_ClassNames( fptr );

			fclose(h);
			}
		if (!( automatic & _INHIBIT_REFRESH ))
			draw_console();

		}
	else if (!( automatic & _INHIBIT_REFRESH )) {
		draw_console();
		loadname = liberate( loadname );
		}
	return(fptr);
}


public	void	save_File(struct file_control * fptr, int automatic )
{
	FILE	*	h;
	if (!( fptr ))
		return;

	if (!( fptr->loadname )) {
		if (!(fptr->loadname = allocate_string( "new.sgf" ) ))
			return;
		}

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( file_properties(fptr) == 27 ) 
			return;
		else if ( accept_form_save(&fptr->loadname) == 27 )
			return;
		else	status_message(fptr->loadname,3);
		}

	if ((h = open_production_target(fptr->loadname,1)) != (FILE *) 0) {

		status_message(fptr->loadname,3);

		put_string(h,"FILE");
		put_string(h,LaPaterne);

		put_word(h,1);

		put_string(h,fptr->identifier);

		put_word(h,fptr->language);
		put_word(h,fptr->program);
		put_word(h,fptr->overlay);
		put_string(h,fptr->prodname);

		put_string(h,fptr->filename);
		put_word(h,fptr->handle);
		put_word(h,fptr->filetype);
		put_word(h,fptr->recordsize);
		put_word(h,fptr->indexsize);
		put_word(h,_TEXT_TOOL);
		put_string(h,fptr->secondary);

		put_word( h, fptr->doctool );
		put_string(h, fptr->document );

		put_string(h, fptr->recordclass );
		put_string(h, fptr->indexclass );
		put_string(h, fptr->dependance );
		put_word( h, fptr->indexalign );
		put_word( h, fptr->isvariable );

		put_word(h,0);		put_word(h,0);
		put_word(h,0);		put_word(h,0);
		put_word(h,0x1A1A);	put_word(h,0x1A1A);
		put_word(h,0x1A1A);	put_word(h,0x1A1A);
		put_word(h,0x1A1A);	put_word(h,0x1A1A);
		put_word(h,0x1A1A);	put_word(h,0x1A1A);

		close_production_target(h,fptr->loadname);

		if (( is_valid_filename( fptr->recordclass ) )
		&&  ( fptr->record != (struct standard_class *) 0 ))
			save_Class( fptr->record, automatic );
		if (( is_valid_filename( fptr->indexclass ) )
		&&  ( fptr->index != (struct standard_class *) 0 ))
			save_Class( fptr->index, automatic );

		if ( fptr->dataform )
			save_Form( fptr->dataform, automatic,(char *) 0 );
		if ( fptr->indexform )
			save_Form( fptr->indexform, automatic,(char *) 0 );

		if (!( automatic & _INHIBIT_REFRESH ))
			draw_console();
		}

	else if (!( automatic & _INHIBIT_REFRESH ))
		draw_console();

	return;
}

public	void	export_File(struct file_control * fptr,int automatic)
{
	if (!( fptr ))
		return;

	else if ( file_properties(fptr) == 27 )
		return;

	switch ( fptr->language ) {
		case	_GENERATE_C 	:
			generate_File_c(fptr,automatic);
			break;
		case	_GENERATE_CPP 	:
			generate_File_cpp(fptr,automatic);
			break;
		case	_GENERATE_BAL	:
			generate_File_bal(fptr,automatic);
			break;
		case	_GENERATE_ABAL	:
			generate_File_abal(fptr,automatic);
			break;
		case	_GENERATE_HTML 	:
		case	_GENERATE_JAVA	:
			break;
		}
	return;
}




public	int	document_File( 
			FILE * handle,
			struct file_control * fptr,
			int automatic , int report
			)
{
	if ( fptr->document )
		html_paragraph( handle, fptr->document );

	return(0);
}

public	int	select_TreeFile( struct file_control * fptr )
{
	select_TreeHost( fptr->host );
	return(0);
}

#endif  /* _singfile_c */
	/* ----------- */


