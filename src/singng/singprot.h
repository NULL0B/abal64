/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 2004
 *	Fichier : singprot.h
 *	Date    : 27/10/2004
 *	Systeme : Windows
 *
 */

#ifndef _SINGPROT_H_
#define _SINGPROT_H_

/*************************************************************************************************/
#if defined(WIN32) || defined(__cplusplus)	/* GWB le 12/09/2007 */
#define	SING_PROTOTYPES
#endif

#ifdef	SING_PROTOTYPES

#ifdef WIN32
#define	public
#define	private	static
#define	WORD	unsigned short
#define	BYTE	unsigned char
#define	LONG	unsigned long
#define	BOOL	int
#define	BPTR	BYTE *
/* ------------------------------- */
/* typedef unsigned char *  BPTR;  */
/* GWB le 15/06/2007 avant #define */
/* ------------------------------- */
#define	WPTR	WORD *
#ifndef	FAR
#define	FAR
#endif
#endif

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
	/* GWB le 12/09/2007, mˆme sous UseIt on a besoin de ces fichiers en C++ */
#include "strucpsu.h"
#include "vobject.h"
#include "vobjapi.h"
#include "pixelgui.h"

#ifdef	WIN32
#ifdef __cplusplus	/* GWB le 05/06/2007 */
extern "C" {
#endif
#include "pubmanagercico.h"
#ifdef __cplusplus	/* GWB le 05/06/2007 */
}
#endif
#include "process.h"
#else

#ifndef	public
#define	public
#endif

#ifndef	private
#define	private	static
#endif

#ifndef	 WORD
#define  WORD	unsigned short
#endif

#ifndef	 BYTE
#define  BYTE  unsigned char
#endif

#ifndef	 LONG
#define  LONG  unsigned long
#endif

#ifndef	 BOOL
#define  BOOL  int
#endif

#ifndef	 BPTR
#define	BPTR BYTE *
#endif


#ifndef	 WPTR
#define	WPTR WORD *
#endif


#ifndef FAR
#define  FAR
#endif

#endif

#ifndef	SIGKILL
#define SIGKILL 0
#endif

/*
*************************************************************************************************
* Fonctions de stdpsu
************************************************************************************************
*/
#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif
	STDPSUPTR	allocate_graphic_storage( WORD, WORD, WORD, WORD );
	STDPSUPTR	allocate_textual_storage( WORD, WORD, WORD, WORD );
	STDPSUPTR	allocate_shadow_storage( STDPSUPTR );
	STDPSUPTR	liberate_pixel_storage( STDPSUPTR );
	STDPSUPTR	liberate_process_storage( STDPSUPTR );
	STDPSUPTR	allocate_process_storage( WORD,WORD, void* );
	BPTR 		resolve_pixel_storage( STDPSUPTR );
	void		background_pixel_capture( STDPSUPTR );
	void		foreground_pixel_capture( STDPSUPTR );
	void		cancel_pixel_capture( STDPSUPTR	 );
	void		commit_pixel_storage( STDPSUPTR, WORD, WORD );
	void		reset_pixel_row( STDPSUPTR, WORD, WORD, WORD, WORD );
	WORD		collect_pixel_row( STDPSUPTR, WORD, WORD, WORD, BPTR);
	BPTR		connect_pixel_row( STDPSUPTR, WORD );
	void		capture_pixel_storage( STDPSUPTR psptr );
	void		refresh_pixel_storage( STDPSUPTR psptr );
	void		move_pixel_capture( STDPSUPTR	psptr, WORD atcol, WORD atrow );

	int		testware(void);
	int		userware(int, int, void *);
	int		hardware(void);

	void *		check_psu( void * );

/*
*************************************************************************************************
* Fonctions publiques provenant d'autres modules
************************************************************************************************
*/

/* Module sing */
void usleep( unsigned long microsecond );
void sleep( unsigned long second );

int windows_create_process(char* cmdline, int IsWaiting );
char *confgetenv( const char *varname );
void windows_show_window();

/* editeur */
int editorOnLoseFocus();
int editorOnGetFocus();
int editorOnUseString(char* buf);
int editorInitEcran();
int editor_window_connection(char* buf);
int editorOnQuit();
int editorOnHide();
int editorOnUpdate(char* buf);
int editorOnUseEvent(int event);
int editorOnShow();
int editorOnCreate( int argc, char** argv);
int editorOnRemove( int x);
int editorOnHigh( int p1, int p2);
int editorGetToken( char* p1, int p2);
int editorOnColour( int p1, int normal, int string, int keyword, int comment, int punctuation);
int editorOnSeek( int p1, int offset);
int editorCommandWindow();
int editorGetPosition( char** nptr, int* nbl, int* topline, int* endline);
int editorOnSearch( char * cptr, int respect, int direct );
int editorOnReplace( char* sptr, char* rptr, int respect, int direct, int replaceall );

/*
*************************************************************************************************
* Fonctions publiques
************************************************************************************************
*/

/* --- abal*.c -------------------------------------------------- */

/* abaldata.c */

public 	char *	abal_data_reset(FILE * h, struct form_item * iptr );
#if defined(WIN32) || defined(__cplusplus)	/* GWB le 12/09/2007 */
public	int	abal_data_construction(FILE * h, struct form_item * iptr, int margin );
public	int	abal_data_destruction(FILE * h, struct form_item * iptr, int margin );
public	int	abal_data_member_expression( FILE * h, struct form_item * iptr, char * token );
public	int	check_data_format( char * nptr, struct data_control * dptr, char * fptr );
public	int	check_data_widget( struct form_item * iptr );
public	void	draw_class_image(int topx, int topy,struct form_item* iptr,int editing);
public	void	generate_aplus_mcfile_class( FILE * h, struct form_item * iptr );
public	void	generate_aplus_sifile_class( FILE * h, struct form_item * iptr );
public	void	generate_aplus_table_class( FILE * h, struct form_item * iptr );
public	int	generate_data_mask( struct file_control * optr, char * nptr, int nlen,char * tptr, int tlen, int language,int pageitems );
public	int	generate_data_page( struct file_control * optr, char * nptr, int nlen, char * tptr, int tlen,int language,int pageitems );
public	int	is_file_Widget( struct form_item * iptr );
#endif
	/* GWB le 23/08/2007 */
public	void	insert_database_item( struct data_control * dptr, int item );
public	void	delete_database_item( struct data_control * dptr, int item );

/* abaldbug.c */
public	int	abal_debuger(char * aptr, int automatic);
public	int	abal_runtime(char * aptr, int automatic);
public	int	activate_background_job( char * command );

/* abaledit.c */
public	void	close_window_editor();
public	void	delete_system_file( char * nptr, int nlen );
public	void	drop_window_editor();
public	void	EditorTextReplace(char * sptr, int slen, char * rptr, int rlen, int respect, int direct, int  replaceall );
public	void	EditorTextFinder( char * cptr, int clen, int respect, int direct );
public	int	focus_window_editor();
public	void	get_widget_filename( char * rptr, int rlen, int v, char * pptr, int plen );
public	void	html_operation( char * tptr );
public	void	initialise_abal_production();
public	int	open_window_editor( int atx, int aty, int nbx, int nby, char * nomfic );
public	void	reconfigure_editor();
public	void	release_abal_production();
public	void	show_window_editor();
public	void	standard_text_editor(char * nptr, int nlen );
public	int	text_editor_find();
public	int	text_editor_replace();
public	int	text_editor_search();
public	void	trace_editor( char * filename );
public	void	use_abal_editor();
public	int	use_editor( char * fnptr, int language);
public	void	use_file_selector( char * fnptr, int pft);
public	int	use_visual_text_editor( char ** nptr, int language );
public	int	use_window_editor();

/* abalform.c */
public	void	abal_visual_dependance( FILE * h, struct form_control * fptr );
public	int	abal_visual_element(FILE * h, struct form_item * iptr, char * sptr, char * mptr, int i);
public	void	abal_widget_function_thaw( FILE * h, struct form_item * wptr, int margin );
public  void	export_abal_form( FILE * h );
public	void	generate_abal_trigger( FILE * h, struct form_item * iptr, int margin );
public	void	abal_form_popup_put(FILE * h, struct form_item * wptr );

/* aballine.c */
public	int	abal_macro_conversion( FILE * h, char * sptr, char * hptr );
public	char *	abal_payload( struct form_item * iptr );
public	char *	abal_payload_length_parameter(FILE * h, struct form_item * iptr );
public	int	remove_brackets();	/* GWB le 21/05/2007 */

/* aballink.c */
public	char *		abal_modules(char * rptr, char * sptr);
public	void	link_abal(char * rootname, char * modules, int automatic, int mode);
public	void	use_abal_linker(char * nptr,int automatic);

/* abalmake.c */
public	int	use_abal_makefile(char * aptr, int automatic);
public	void	configure_makefile();

/* abalpage.c */
public  void	export_abal_page( FILE * h );
private	void	reset_visual_page(FILE * h, int i );

/* abalsynt.c */
public	void	abal_pragma_enter( FILE * h,char * mptr, char * nptr );
public	void	abal_pragma_leave( FILE * h,char * mptr, char * nptr );
public	void	abal_comment( FILE * handle, char * vptr , int indentation );
public	void	abal_banner(FILE * h, char * token );
public	void	abal_label( FILE * handle, char * lptr );
public	void	abal_keyword( FILE * handle, int indentation, char * kptr );
public  void	abal_if( FILE * h, int indentation, char * expression );
public	void	abal_else( FILE * handle, int indentation );
public	void	abal_endif( FILE * handle, int indentation );
public	void	abal_gosub( FILE * handle, char * label , int indentation );
public	void	abal_endloc( FILE * handle, int indentation );
public	void	abal_do( FILE * handle, int indentation );
public	void	abal_break( FILE * handle, int indentation );
public	void	abal_continue( FILE * handle, int indentation );
public	void	abal_retry( FILE * handle, int indentation );
public	void	abal_loop( FILE * handle, int indentation );
public	void	abal_include( FILE * handle, char * sptr );
public	void	abal_user( FILE * handle, char * sptr );
public	void	abal_program( FILE * handle, char * sptr );
public	void	abal_module( FILE * handle, char * sptr );
public	void	abal_end( FILE * handle, int indentation );
public	void	abal_variable( FILE * h,int	datatype,int	length,int	first, int second, char *comment );
public	void	abal_ptr( FILE * h,char * 	prefix, char* postfix,int	datatype,int	length,int	first, int second );
public	void	abal_dcl( FILE * h,char * 	prefix, char* postfix,int	datatype,int	length,int	first, int second ,char *comment);
public	void	abal_const( FILE * h,char *prefix, char* postfix,int	datatype,char * value );
public	void	abal_arg( FILE * h,char * 	prefix, char* postfix,int	datatype,int	length,int	first, int second );
public	void	abal_integer_constant( FILE * h,char * 	prefix, char* postfix,int	value );
public	void	abal_string_constant( FILE * h,char * 	prefix, char* postfix,char * 	value );
public	void	abal_field(FILE * h, char * prefix, char * vname );
public	void	abal_vfield(FILE * h, int id);
public	void	abal_filler(FILE * h, int length );
public  void	abal_procedure( FILE * h, char * prefix, char * nptr, int members, struct form_control * fptr);
public  void	abal_endproc( FILE * h);
public  void	abal_segment( FILE * h, char * vptr);
public	void	abal_retseg( FILE * handle, int indentation );
public  void	abal_endseg( FILE * h, char * vptr);
public	void	abal_stop( FILE * handle, int indentation );
public	void	abal_error( FILE * handle, char * vptr , int indentation );
public	void	abal_raise( FILE * handle, int v , int indentation );
public	void	abal_return( FILE * handle, char * vptr , int indentation );
public	void	abal_returni( FILE * handle, int v , int indentation );
public  void	abal_while( FILE * h, int indentation, char * expression );
public	void	abal_wend( FILE * handle, int indentation );
public	void	abal_repeat( FILE * handle, int indentation );
public  void	abal_select( FILE * h, char * expression, int indentation );
public	void	abal_case( FILE * handle, int value, int indentation );
public	void	abal_cases( FILE * handle, char * values,int indentation );
public	void	abal_default( FILE * handle, int indentation );
public	void	abal_endsel( FILE * handle, int indentation );

/* abaltrad.c */
#ifdef ABALCPP	/* GWB le 05/09/2007 */
public	int	translate_abal(int translator,char * filename, int automatic,void *this_param);
#else
public	int	translate_abal(int translator,char * filename, int automatic);
#endif
public	void	use_abal_translator(char * sptr, int automatic);

/* --- sing*.c -------------------------------------------------- */

/* sing.c */
public 	void	apply_gridlock( struct window_control * wptr, int mode );
public 	void	calculate_cursor( struct window_control * wptr );
int				check_class_buffer();
public	int	close_graphics(int og);
public	void	connect_3dscroll(struct coordinate3d * cptr, int l, int m);
public	void	cursor_frame( int atx, int aty, int nbx, int nby, int style );
public 	void	draw_console();
public	void	enter_modal();
public	void	fntransfer( char * rptr, int rlen, char * pptr, int plen , char * sptr, int slen );
public	void	fnaddfile( char * rptr, int rlen, char * pptr, int plen , char * sptr, int slen );
public 	int	handle_event();
public 	void	hide_form_cursor(int o);
public 	int	inner_height();
public	int	inner_left();
public 	int	inner_width(int mode);
public	void	leave_modal();
public	int	open_graphics();
void				output_int( int v );
void				output_string(char * sptr);
public	void	perform_toggle(int keycode);
public 	void	show_form_cursor(int o);
public	int	is_expert_user();
/* GWB le 20/04/2007 */
public	void	reset_c_form_input();	
public	void	set_c_form_input( struct form_control * fptr );	
public	void	set_c_form_error( struct form_control * fptr );
public	int	use_all_widget();
#ifdef CPP_PRODUCT
void visual_set_size(int w,int h);
void visual_show_window();
#endif

/* singabal.c */
public	void	abal_button_widget(FILE * h, struct form_item * iptr, int margin, int etat );
public  void	abal_call( FILE * h, char * cname, char * fname, int members, int level, struct form_control * fptr );
public	void	abal_case_focus(FILE * handle, struct form_item * iptr, int margin );
public	void	abal_dependance( FILE * h, char * sptr, int mode );
public	void	abal_dialog_show(FILE * handle, struct form_item * iptr, int mode );
public	void	abal_error_trap( FILE * h, int i, int level );
public	void	abal_error_abort( FILE * h, int i, int level );
public	void	abal_error_return( FILE * h, char * vptr, int level );
public	void	abal_extern_methods(FILE * h, struct form_control * fptr );
public	void	abal_fill_widget(FILE * handle, struct form_item * iptr, int margin );
public	void	abal_forms_members(FILE * h, struct form_control * fptr);
public	void	abal_forms_method_extern(FILE * h, struct form_control * fptr);
public	void	abal_forms_method_forward(FILE * h, struct form_control * fptr,int mode);
public	void	abal_forms_methods(FILE * h, struct form_control * fptr);
public	void	abal_forward_methods(FILE * h, struct form_control * fptr );
public	void	abal_frame_widget(FILE * handle, struct form_item * iptr, int margin );
public	void	abal_image_widget(FILE * handle, struct form_item * iptr, int margin );
public	int	abal_import_parameter( FILE * h , struct form_item * iptr, int i );
public	void	abal_initialise_national_language(FILE * h, struct form_control * fptr);
public	void	abal_invoke_widget_create( FILE * h, struct form_item * iptr, int mode, int margin );
public	void	abal_invoke_widget_event( FILE * h, struct form_item * iptr, int mode, int margin );
public	void	abal_invoke_widget_get_focus( FILE * h, struct form_item * iptr, int mode, int margin );
public	void	abal_invoke_widget_lose_focus( FILE * h, struct form_item * iptr,int mode, int margin );
public	void	abal_invoke_widget_remove( FILE * h, struct form_item * iptr, int mode, int margin );
public	void	abal_line_widget(FILE * handle, struct form_item * iptr, int margin );
public	void	abal_oncreate_methods( FILE * h );
public	void	abal_onevent_methods( FILE * h, struct form_control * fptr );
public	int	abal_onfocus_widget(FILE * h, struct form_item * iptr, int margin );
public	void	abal_onget_methods( FILE * h, char * nptr );
public	void	abal_onhide_methods( FILE * h, char * nptr );
public	void	abal_onlose_methods( FILE * h, char * nptr, int mode );
public	void	abal_onremove_methods( FILE * h );
public	void	abal_onshow_methods( FILE * h );
public	int	abal_onshow_widget(FILE * h, struct form_item * iptr, int margin );
public	void	abal_select_show(FILE * handle, struct form_item * iptr, int mode );
public  void	abal_signature( FILE * h, char * cname, char * fname, int members, struct form_control * fptr );
public	void	abal_text_widget(FILE * handle, struct form_item * iptr, int margin );
public	void	abal_transfer_parameters( FILE * h , int direction );
public	void	abal_widget_constants(FILE * h, struct form_control * fptr);
public	void	abal_widget_function( FILE * handle, char * mptr, int i );
public	void	abal_widget_viewport(FILE * h, struct form_item * iptr );
public	void	abal_window_widget(FILE * handle, struct form_item * iptr, int margin );
public	void	alias_redefined_widget( FILE * h, struct form_item * iptr, char * item, int tabstop );
public	void	attach_widget_overlay( FILE * h, struct form_item * iptr );
public	int	calculate_form_fields( struct form_item * iptr,int fieldwidth[], int maxfield, int linelength );
public 	void	constant_lendol_parameter(FILE * handle, struct form_item * iptr );
public	void	detach_widget_overlay( FILE * h, struct form_item * iptr );
public	void	generate_abal_event(FILE * handle, struct form_item * iptr );
public	void	generate_abal_flush(FILE * handle,int i);
public	void	generate_abal_focus(FILE * handle, struct form_item * iptr );
public	void	generate_abal_hide(FILE * handle, struct form_item * iptr, int paging );
public	void	generate_abal_popdown( FILE * h, struct form_item * wptr, int margin );
public	void	generate_abal_popup( FILE * h, struct form_item * wptr, int margin );
public	void	generate_abal_fonts(FILE * h);
public	void	generate_abal_show(FILE * handle, struct form_item * iptr, int paging  );
public  int	generate_abal_structure( FILE * h, struct form_control * fptr );
public	int	is_named_conditional( struct form_item * iptr );
public	int	is_named_select( struct form_item * iptr );
public	void	logical_abal_font( FILE * h, int fid );
public	int	max_payload_size( struct form_item * iptr );
public	int	pixel_payload_size( struct form_item * iptr );
public	void	abal_button_press( FILE * h, struct form_item * iptr );
public	void	abal_tab_focus(FILE * handle, struct form_item * iptr, int mode );
public	void	abal_default_focus(FILE * handle, struct form_item * iptr, int mode );
public	void	abal_edit_focus(FILE * h, struct form_item * iptr, int mode );
public	void	abal_form_focus(FILE * h, struct form_item * iptr, int mode );
public	void	invoke_widget_overlay_method( FILE * h, struct form_item * iptr,int method );
public	void	abal_visual_editshow(FILE * handle, struct form_item * iptr, int margin );
public	void	abal_widget_action( FILE * h, struct form_item * iptr );
	/* GWB le 16/05/2007 */
public	char *	language_prefix(int nl);
public	void	analyse_variable_expression(char * cptr,int clen,int * tptr,int * lptr,int * fptr, int * sptr);

/* singbar.c */
public 	void	show_item_info( struct form_item * iptr );
public 	void	show_mouse_position(int x,int y);
public	void	status_message_length(int position, char * message, int length );
public 	void	status_progress(int position,int limit, int value);

/* singc.c */
public	void	c_dependance( FILE * h, char * sptr );
public	int	c_onfocus_widget(FILE * h, struct form_item * iptr, int margin );
public	int	c_onshow_widget(FILE * h, struct form_item * iptr, int margin );
public	void	c_widget_viewport(FILE * h, struct form_item * iptr );
public  void	export_c_page( FILE * h );
public  void	logical_c_font( FILE * h,struct form_item * iptr );
public	void	initialise_c_production();
public	int	is_blank( char * sptr );
public	int	method_is_valid( char * eptr );
public	int	not_blank( char * sptr );
public	void	release_c_production();
public	int	c_define_messages(FILE * h,struct form_control * fptr);	/* GWB le 12/04/2007 */
public	void	generate_c_help(FILE * handle, struct form_item * iptr, int margin );	/* GWB le 16/05/2007 */
public	void	close_c_page(FILE * h,int pn,int i);	/* GWB le 19/05/2007 */
public	char *	c_hint( struct form_item * iptr );	/* GWB le 21/05/2007 */
	/* GWB le 21/05/2007 */
public	void	c_payload_parameter(FILE * h, struct form_item * iptr);
public  void	c_member_parameters( FILE * h, int iscall );
public	void	c_payload_filename_parameter(FILE * h, struct form_item * iptr);
public	int	c_visual_element(FILE * h, struct form_item * iptr, char * sptr, int i );

/* singcam.c */
public	void	adjust_3d_step( int which, int mode, int * rptr );
public	void	background_Camera(struct camera3d * cptr, int v );
public	void	build_tab_image(  struct form_control * fptr, char * nomfic );
public 	void	camera_ItemFile(char ** sptr);
public	int	camera_image_quality();
public	int	CameraWorkOut( char * aptr );
public	int	compare_treeview_image( struct bitmap_control * sptr, char * nptr );
public	int	compare_treeview_text ( struct source_control * sptr, char * nptr );
public	void	disconnect_treeview( struct treeview * tptr );
public 	void	draw_Camera(struct camera3d * cptr);
public	int	get_camera_position_x();
public	int	get_camera_position_y();
public	int	get_camera_position_z();
public	void	hide_DeskTop_TreeView();
public	int	is_CameraEvent(struct camera3d * cptr,int x, int y);
public	void	load_CameraItem( struct object3d * optr, int automatic );
public	int	move_3d_camera( int type, int * xptr, int * yptr, int * zptr );
public	void	new_CameraItem(	struct camera3d * cptr,int nature, char * filename);
public	char *	project_configuration();
public	void	resize_console();
public	void	save_form_image( char * nptr, struct standard_image * iptr, int options, int mode );
public	int	select_TreeHost( struct object3d * optr );
public	int	select_TreeImage( struct bitmap_control * bptr );
public	int	select_TreeProject( struct camera3d * cptr );
public	int	select_TreeText( struct source_control * sptr );
public	void	show_DeskTop_TreeView();
public 	int	string_compare(char * aptr, char * bptr );
public	void	swap_TreeView();
public 	int	upper_compare(char * aptr, char * bptr );
public	struct form_control * locate_form_control( char * sptr );
public	struct form_control * resolve_form_control( char * sptr );
public	void	CameraAbout();
public	void	camera_national_language();
public void 	export_labels(struct camera3d *cptr);
public void 	import_labels(struct camera3d *cptr);
public void 	sort_forms(struct camera3d *cptr);
public 	int	camera_document_Properties(int automatic);
public void 	sort_project_by_name(struct camera3d *cptr);
public void 	sort_project_by_type(struct camera3d *cptr);
/* GWB le 21/06/2007 */
public	int	toggle_national_language(int mode);
public	int locate_file_instance( char * sptr, int slen );
public	int	get_file_reference( int item, char * sptr, int slen );
public	int	use_file_reference( int item, char * sptr, int slen );
public	int	file_reference_count();
public	void	use_document_navigator( char * nptr, int nlen );

/* singcfrm.c */
public	void	c_event_switch_item( FILE * h, struct form_item * iptr, int mode, int margin );
public  void	export_c_form( FILE * h );
public	void	generate_c_popdown( FILE * h, struct form_item * wptr, int margin );
public  void	generate_c_freeze( FILE * h, int margin );
public	void	generate_c_popup( FILE * h, struct form_item * wptr, int margin );
public  void	generate_c_thaw( FILE * h, struct form_item * wptr, int margin );
public	void	generate_c_trigger( FILE * h, struct form_item * iptr, int margin );
public	void	set_zero_window_column( char * sptr, int v );
public	void	set_zero_window_line( char * sptr, int v );
/* GWB le 15/05/2007 */
public	void	c_form_onhelp( FILE * h,char *classe );
public	void	c_widget_onhelp( FILE * h,struct form_control * fptr, struct form_item * iptr, char *classe );
public	void	c_case_hotkey( FILE * h, int keycode, int margin );
public	void	c_check_widget_event(FILE * h,struct form_item * iptr,int margin);

/* singcpp.c GWB le 15/06/2007 */
public	int	cpp_macro_conversion( FILE * h, char * sptr, char * hptr );
public	void	export_cpp_form( FILE * h, char * headname );
public void compile_cpp(char *cname);
public void link_cpp(char *cname);
public void compile_dll_cpp(char *cname);
public void link_dll_cpp(char *cname);

/* singclin.c */
public	int	c_macro_conversion( FILE * h, char * sptr, char * hptr );
public int	c_get_punctuation();
public	char *	c_get_token(int uppercase);
public	char *	c_macro_columns( FILE * h, struct form_item * iptr );	/* GWB le 16/04/2007 */
public	char *	c_macro_position( FILE * h, struct form_item * iptr, char * tptr );	/* GWB le 16/04/2007 */
public	char * c_dimension();	/* GWB le 16/04/2007 */
public	char *	c_widget_overlay_method( FILE * h, struct form_item * iptr, char * tptr );	/* GWB le 16/04/2007 */
/* singcsyn.c */
public 	void	c_include( FILE * handle, char * sptr );
public	void	c_return( FILE * handle, char * vptr , int indentation );
public	void	c_else( FILE * handle , int indentation );	/* GWB le 16/05/2007 */
	/* GWB le 21/05/2007 */
public	void	c_endif( FILE * handle , int indentation );
public	void	c_case( FILE * handle, int value, int indentation );
public	void	c_break( FILE * handle, int indentation );
public	void	c_continue( FILE * handle, int indentation );
public	void	c_endif( FILE * handle , int indentation );
public	void	c_default( FILE * handle, int indentation );

/* singdesk.c */
public	int	desktop_Hscroll(int * offset, int limit );
public	int	desktop_Vscroll(int * offset, int limit );
public	void	draw_desktop_scroll();
public 	void	drop_DeskTop();
public 	int 	export_DeskTop( char * nptr,int mode );
public	int	is_ConsoleEvent(int x, int y );
public	void	use_background_colour( int v );
public	void	use_foreground_colour( int v );

/* singfail.c */
public	int	creation_failure( char * filename );
public	int	incorrect_filetype( char * filename );
public	int	no_free_triggers( char * nptr, char * lptr );

/* singclin.c */
public int	c_syntax_error( char * vptr, int n );

/* singcob.c */
public  void	export_cobol_form( FILE * h );
public  void	export_cobol_page( FILE * h );

/* singconf.c */
public	void	check_configuration();
char *			configuration_rootname();
public	int	load_from_slapd(char * eptr,int verbose);
public	void	LoadConfiguration( char * rootname );
public	int	production_language();
public	int	raz_from_slapd(char * sptr);
public	int	save_to_slapd(char * eptr,int verbose);

/* singdesk.c */
public 	void	activate_DeskTop(int mode);
public	int	console_Message( int atx, int aty, int state, char * message, int mlen, int indent );
public 	void	draw_DeskTop();
public 	int	is_DeskTopEvent(int x, int y );
public 	void	image_DeskTop( char * nptr, int automatic );
public 	int	load_DeskTop( char * nptr,int reset, int automatic );
public 	void	reset_scroll( struct scroll_control * sptr );
public 	void	select_current(int x, int y);
public	int	treeview_Message( int atx, int aty,char * message, int mlen, int iconid , int state, int indent );

/* singexpo.c */
public	int	add_interface_item(int items, struct form_item * iptr, int deftype);
public 	void	buffer_value(FILE * handle, char * sptr );
public	void	calculate_edit_lines( struct window_control * iptr, int * nbc, int * nbl );
public	void	calculate_form_lines( struct window_control * iptr, int * nbc, int * nbl );
public	void	calculate_edit_size( struct window_control * iptr );
public	void	calculate_window_alignment( struct form_item * iptr );
public	void	close_file_exclusion( FILE * h, char * token );
public 	void	colour_parameter(FILE * handle, struct form_item * iptr );
public 	void	constant_parameter(FILE * handle, struct form_item * iptr );
public 	void	constant_value(FILE * handle, struct form_item * iptr );
public 	int	export_Form( struct form_control * fptr, int automatic );
public 	void	filename_parameter(FILE * handle, char * sptr );
public 	void	font_parameter(FILE * handle, struct form_item * iptr );
public 	void	format_string_value(FILE * handle, char * sptr );
public 	void	format_value(FILE * handle, char * sptr );
public	void	get_window_alignment( int * x, int *y );
public 	void	indent( FILE * handle, int indentation );
public	void	initialise_production();
public 	void	length_parameter(FILE * handle, int l );
public 	void	linefeed( FILE * handle );
public	void	open_file_exclusion( FILE * h, char * token );
public	void	production_banner( FILE * h,int language, char * modelname, char * target );
public 	void	quoted_filename(FILE * handle, char * sptr );
public	void	quoted_string(FILE * handle, char * sptr );
public	void	release_production();
public	void	standard_dependance( FILE * h, char * sptr,  char * mptr );
public	void	string_length( FILE * h, char * sptr);
public 	void	string_value(FILE * handle, char * sptr );
public 	void	string_parameter(FILE * handle, char * sptr );
public 	void	variable_length(FILE * handle, char * sptr );
public 	void	variable_value(FILE * handle, char * sptr );
public	int	widget_foreground( struct form_item * iptr );
public	int	widget_background( struct form_item * iptr );
public	void	widget_bottom( FILE * h, struct form_item * iptr, int ax, int ay );
public	void	widget_position( FILE * h, struct form_item * iptr, int ax, int ay );
public	void	widget_dimensions( FILE * h, struct form_item * iptr, int ax, int ay );
public	void	widget_font_dimensions( FILE * h, struct form_item * iptr, int ax, int ay );
public	char * 	widget_x_position( struct form_item * iptr, int mode );
public	char *	widget_y_position( struct form_item * iptr, int mode );
public	char * 	widget_w_dimension( struct form_item * iptr, int mode );
public	char * 	widget_h_dimension( struct form_item * iptr, int mode );
public 	void	zoned_colour_parameter(FILE * handle, struct form_item * iptr,	char *	expression );
public 	void	close_exclusion(FILE * h, char * token );	/* GWB le 31/05/2007 */
/* GWB le 26/06/2007 */
public	char *	headername( char * sptr, char * xptr );

/* singfail.c */
public	int	allocate_failure();
public	int	editor_failure( char * mptr, char * eptr );
public	int	file_not_found( char * filename );
	/* GWB le 10/10/2007 */
public int	report_accept_error(char * lptr,char * mptr);

/* singfind.c */
public	int	detect_file_extension( char * rptr, int rlen, int result );
int	filefinder( char * rptr, int rlen, char * sptr, int slen, int m, int item );
int	fileinformer( char * rptr, int col1,int col2, int col3, int col4, char * sptr, int slen, int m, int item );
void	fnchangedirectory(char * rptr, int rlen, char * sptr, int slen );
int	fnisdirectory(char * nptr, int nlen );

/* singfont.c */
public	void	drop_FontTable();
int	font_edit(int fid);
public 	void	font_load(int number, char * nptr, int mode );
public	int	is_FontEvent(struct font_context * wptr, int x,int y);
public 	void	load_FontTable();
public	void	refresh_FontContext();
public 	void	save_Character(struct font_context * wptr , int c );

/* singform.c */
public 	void	add_Widget(struct form_control * fptr,struct form_item * iptr, int atend);
void				calculate_form_triggers( struct form_control * fptr );
public	void	change_national_language(struct form_control * fptr, int newlang );
public	void	check_Form( struct form_control * fptr );
public	void	check_forms_methods(struct form_control * fptr );
public 	void	check_Widget(struct form_item * iptr );
public	int	compare_treeview_form ( struct form_control * fptr, char * nptr );
public	int	document_Form(FILE * handle,struct form_control * fptr,int automatic, int report);
public	void	draw_Form(struct form_control * fptr, int refresh);
public	void	drop_form_clipboard();
public 	int 	edit_Widget(struct form_item * iptr, struct form_control * fptr);
public	int	get_context_gridlock();
public	int	get_context_gridsize();
public	void	get_widget_reference(int item, char * bptr, int blen );
public	void	form_Dimensions( struct window_control * wptr,struct form_control   * fptr);
public	int	form_parameters(struct form_control * fptr );
public	int	FormSyntaxComposer(struct form_control * fptr );
public	void	FormWidgetCompose(int c, int w, int m, char * bptr, int blen, int x);
public	void	get_national_payload(struct form_item * iptr, int i );
public	void	inspect_widget_reference(int item);
public	int	is_FormEvent(struct form_control * fptr, int x, int y);
public	int	make_widget_symbol( int widget_type );
public 	struct form_control * new_Form(struct form_control* fptr, char * nptr );
public	void	prepare_Form(struct form_control * fptr);
public	void	release_widget_types();
public	void	reload_payloads(struct form_control * fptr );
public	void	remove_Form(struct form_control *  fptr);
public 	void	respectcase(char * rptr, char * sptr);
public 	int	save_Form( struct form_control * fptr,int automatic, char * checkname );
public	void	search_widget_reference(int item,char * bptr, int blen);
public	char*	selection_item( int item, char * sptr );
public 	void	set_national_payload(struct form_item * iptr, int i );
public 	void	show_Form(struct form_control * fptr, int refresh);
public	void	store_payloads(struct form_control * fptr );
public	int	use_grid_lock( int v, int adjust, int gridlock );
public	int	widget_reference_count();
public	void	renumerate_form( struct form_control * fptr );
public	char * 	forms_template_selection(struct form_control * fptr, int nature);
public	int	FormZoomCheck();
public	char *	visual_table_testdata( struct form_item * iptr );
public	void	init_whResize(struct form_item * iptr);
	/* GWB le 04/06/2007 */
public int	visual_online_help(char *mptr[],int h);
public	int	change_widget_class(int * wcptr);
public	int	change_widget_view(int v);
public	void	edit_national_messages();
public	void	edit_national_helptext();
public char	*	FormsMethodNames();
public	void	get_helptext_line( int l, char * nptr, int nlen, char * tptr, int tlen );
public	int	get_helpline_count();

/* singgrid.c */
public	void	draw_grid( int atx, int aty, int nbx, int nby, int zf, int type );

/* singhtml.c */
public	void	close_html_definition_list( FILE * h);
public	void	html_anchor_name( FILE * h, char * target );
public	void	html_anchor_trigger( FILE * h, char * target );
public	void	html_area( FILE * handle, char * target, int x, int y, int w, int h, char * alt );
public	void	html_close_map( FILE * h);
public 	void	html_closure( FILE * h, char * nptr );
public	void	html_definition(FILE * h, char * n, char * d );
public	void	html_form_frameset( FILE * handle, int mode );
public	void	html_heading( FILE * h, int size, char * tptr );
public	void	html_image( FILE * handle, char * nptr, char * mptr );
public	void	html_integer(FILE * handle, int value );
public	char * html_numbered_image( FILE * handle, char * nptr, int number , char * mptr, int itype );
public	void	html_open_map( FILE * h, char * target );
public	void	html_paragraph( FILE * handle, char * message );
public 	void	html_tag( FILE * h, char * nptr );
public 	void	html_text( FILE * h, unsigned char * tptr );
public 	void	html_trigger( FILE * h, unsigned char * tptr );
public	void	open_html_definition_list( FILE * h);
public	int	use_html_navigator(char * aptr, int automatic);
public	void	use_navigator( char * filename , int namelength );
public	void	html_forms_national_flag( FILE* handle, struct form_control * fptr, int mode );

/* singimg.c */
public	int	screen_capture();

/* singmain.c */
public	void	activate_text_cursor();
public	void	inhibit_text_cursor();

/* singmemb.c */
public	void	drop_forms_method(int id);
public	void	edit_forms_method(int id);
public	int	forms_method_editor( struct form_control *fptr, char * method, int nbline );
public	void	get_forms_method_information(int item,char * rptr,int rlen, char * nptr, int nlen, char * pptr, int plen, char * tptr, int tlen );
public	void	put_forms_member(int number, char * nptr, int nlen, int type, int size,int first,int second,char *comment,int lcomment);
public	void	insert_forms_member_item(int number);
public	void	delete_forms_member_item(int number);
public	void	store_to_Method( char ** rptr, char * sptr, int slen );
public	int 	compare_member(struct forms_data_member *first,struct forms_data_member *second,int typtri);
public 	void 	sort_data_member(int typtri);
/* GWB le 31/05/2007 */
public	int	forms_method_count();
int	valid_copied_method();
void	paste_forms_method(int id);
void	copy_forms_method(int id);
public	int	forms_member_count();
public	struct	forms_data_member * get_forms_member(int number);

/* singmenu.c */
public	void	activate_MenuBar(int mode);
public	void	add_editor_menu();
public	void	add_trace_menu();
public	void	add_zoom_editor_menu();
public	void	compare_Files(char * lptr, char * rptr );
public	void	configure_gridlock(int v);
public 	void	draw_MenuBar();
public	void	drop_editor_menu();
public	void	drop_form_editor_menu();
public	void	drop_trace_menu();
public	void	drop_zoom_editor_menu();
public	void	editor_basket_icon(int value);
public	void	editor_insert_icon(int value);
public	void	editor_line_counter(int value);
public	void	editor_wipe_icons();
public	int	general_parameters();
public	int	inspect_configuration();
public 	int	is_MenuBarEvent(int x, int y );
public	int	menu_refresh();
public	void	mouse_move_off();
public	void	mouse_move_on();
public	int	new_menu_system();
public	int	page_parameters();
public 	int	page_resolution();
public	int	perform_animation();
public	void	resolve_tool_parameters( int * automatic, char * * sptr, int * nature );
public 	void	swap_MenuBar();
public	int	syntax_composer();
int				toggle_treeview();
int				toggle_palette();
public	int	treeview_parameters();
public	int	use_font_editor();
/* GWB le 21/06/2007 */
public	void	use_menu_editor();
public	int	get_menubar_height();

/* singpal.c */
public 	void	activate_Palette(int mode)	;
public	int	get_background();
public	int	get_foreground();
public	char *	GetPaletteSwitch();
public	void	hide_DeskTop_Palette();
public	int	is_PaletteEvent(int x, int y );
public	int	palette_is_active();
public	void	show_DeskTop_Palette();
public 	void swap_Palette();
public	int	toggle_palette_display();

/* singpars.c */
public	int	initialise_line_parser( char * eptr, char * hptr );
public	int	is_data_member( char * tptr, int uppercase );
public	int	is_valid_method( char * eptr );
public	int	is_visual_member( char * tptr, int uppercase );
public	int	is_visual_method( int m );
public	int	is_white_space(int c );
public	int	line_parser_error( int e );
public	int	not_white_space();
public	int	parser_getch();
public	int	parser_ungetch();
public	int	pop_line_parser();
public	int	push_line_parser();

/* singplus.c */
public	void	aplus_end( FILE * h );
public	void	aplus_visual_apl( FILE * h );
public	void	visual_object_event_retry( FILE * h,char * prefix, int margin );

/* singprod.c */
public	void	close_production_target( FILE * h, char * nptr );

/* singpv.c */
public	char *	sing_version();

/* singtext.c */
public	int 	edit_text(int topx,int topy,struct window_control* dptr);

/* singtool.c */
public	void	allocate_tool_managers();
public	void	drop_tool_manager();
public	void	hide_DeskTop_ToolBar();
public	void	hide_sprite();
public	int	is_ToolBarEvent(int x, int y );
public	void	liberate_tool_managers();
public	void	show_data_icon( int x, int y );
public	void	show_DeskTop_ToolBar();
public	void	show_form_sprite(int atx, int aty );
public	void	show_widget_sprite(int atx, int aty );
public	void	SingDrawIcon( int atx, int aty, char * buffer, int style );
public	int	toggle_toolbar_display();
public	int	toolbar_is_active();
public	void	use_form_tools();
public	void	use_html_tools();
public	int	use_icon_tool(int y,int v);
public	void	use_image_tools();
/* GWB le 21/06/2007 */
public	char *	GetToolBarSwitch();

/* singtree.c */
public	void	activate_TreeView(int state);
public	int	add_treenode( struct treeview * tptr, struct treeview * lptr );
public	int	allocate_tree_managers();
public	int	append_treenode(struct treeview * tptr,struct treeview * nptr,struct treeview * lptr );
public	int	configure_treeview();
public	void	connect_treenode( struct treeview * tptr, int n, void * p);
public	int	draw_tree_view(struct treeview * tptr, int atcol, int * atrow );
public	void	draw_TreeView();
public	void	focus_treenode( struct treeview * tptr, int state );
public	int	is_TreeViewEvent(int x,int y);
public	int	liberate_tree_managers();
public	struct treeview * newlocate_TreeViewWidget(int x, int y, struct treeview * lptr );
public	int	reconfigure_treeview();
public	void	remove_treenode( struct treeview * tptr );
public	int	select_TreeForm( struct form_control * fptr );
public	int	select_TreeWidget( struct form_item * iptr );
public	void	treeview_configuration();
public	int	treeview_is_active();
public	int	treeview_options();
public	int	treeview_padding();

/* singtrig.c */
public 	int 	calculate_payload_triggers( struct form_control * fptr );
public	void	check_Widget_trigger( struct  window_control * dptr );
public	int	compare_hotkeys( int a, int b );
public	int	detect_hotkey_trigger( char * nptr );
public	int	widget_can_trigger( struct window_control * dptr );

/* singzoom.c */
public	int	is_ZoomEvent(struct zoom_control * zptr, int x, int y );
public	void	refresh_ZoomWindow();
	/* GWB le 03/09/2007 */
public 	int	sing_light_transformation( int v, int w );
public	int	sing_blue_transformation( int v, int w );
public	int	sing_green_transformation( int v, int w );
public	int	sing_red_transformation( int v,int w );

/* --- *menu.c -------------------------------------------------- */

/* editmenu.c */
public	int	text_editor_menu();
public	int	text_editor_menu_event(struct text_editor_menu_context * _Context);

/* eventmenu.c */
public	int	standard_event_menu();

/* filemenu.c */
public	int	standard_file_menu();

/* formmenu.c */
public	int	forms_editor_menu();

/* imagemenu.c */
public	int	image_editor_menu();

/* mainmenu.c */
void		drop_menu_extension(void * _Context,int number);
public	int	standard_main_menu_create(void **cptr);
public	int	standard_main_menu_event(void * _Context);
public	int	standard_main_menu_remove(void * _Context);
public	int	standard_main_menu_show(void * _Context);
void		standard_menu_extension(void * _Context,int number, struct visual_language_message * mptr);

/* optionmenu.c */
public	int	standard_option_menu();

/* projmenu.c */
public	int	project_editor_menu();

/* tracmenu.c */
public	int	trace_editor_menu();

/* viewmenu.c */
public	int	standard_view_menu();
public	int	standard_view_menu_event(struct standard_view_menu_context * _Context);

/* widgmenu.c */
public	int	forms_widget_menu();

/* --- v*.c ------------------------------------------------------- */

/* vaed.c */
public	int	accept_editor(
	char * pFileName,
	char * pEditorName,
	char * pRazColour,
	char * pQuoteColour,
	char * pKeyWordColour,
	char * pCommentColour,
	char * pFrameInhibit,
	char * pTextFont);

/* vamake.c */
public	int	accept_amake(
	char * pToolName,
	char * pFileName,
	char * pOutput,
	char * pDefine,
	char * pForceBuild,
	char * pShowDates,
	char * pTouch_Only);

/* vaprod.c */
public	int	accept_abal_production(
	char * pFileName,
	char * pFilePath,
	char * pIdentity,
	char * pPackaging,
	char * pIsAutoTrad,
	char * pIsTrueColour,
	char * pExactDimensions,
	char * pDimensions,
	char * pDependance,
	char * pLinkage,
	char * pUseDiezeMem,
	char * pUseDiezeStack,
	char * pUseDiezeFiles,
	char * pUseDiezeHeap,
	char * pDiezeMem,
	char * pDiezeStack,
	char * pDiezeFiles,
	char * pDiezeHeap,
	char * pUsePragmaFile,
	char * pPragmaFileName,
	char * pRespectCase,
	char * pOptimiseTables,
	char * pUseTokenSize,
	char * pUseLabelSize,
	char * pTokenSize,
	char * pLabelSize);

/* vcamera.c */
#include "vcamera.h"

/* vcobprod.c */
public	int	accept_cobol_production(char * pAuto1773,char * pAuto1774);

/* vcolours.c */
public	int	accept_visual_colour(int * pfgcolour,	int * pbgcolour);

/* vcompare.c */
public	int	visual_file_compare_losefocus(struct visual_file_compare_context * _Context);

/* vcompose.c */
public	int	accept_form_syntax(
	char * pResult,
	char * pClassList,
	char * pWidgetList,
	char * pMethodList,
	char * pConcatenate);

/* vcprod.c */
public	int	accept_c_production(char * pFileName,char * pIdentifier,char * pIsProgram,char * pIsOverlay,char * pIsTrueColour,char * pInclusions,char * pDimensions);

/* vcppprod.c GWB le 17/12/2007 */
#ifdef ABALCPP
public int accept_cpp_production(char * pFileName,char * pIdentifier,char * pIsProgram,char * pIsOverlay,char * pIsTrueColour,char * pInclusions,char * pDimensions,char * pOptionCompile,char * pOptionLinkage);
#endif

/* vcompare.c */
public	int	visual_file_compare(char * pFileOne,char * pFileTwo);

/* vcube.c */
public	int	accept_cube_properties(
	char * pIdentity,
	char * pPosition,
	char * ptly,
	char * ptlz,
	char * pDimensions,
	char * pbry,
	char * pbrz,
	char * pClass,
	char * pAuto1560,
	char * pAuto1561,
	char * pImageFormat,
	char * pBack,
	char * pFront,
	char * pLeft,
	char * pRight,
	char * pUpper,
	char * pLower,
	char * pLight,
	char * pDark);

/* vcursor.c */
public	int	visual_3d_cursor_create(struct visual_3d_cursor_context **cptr);
public	int	visual_3d_cursor_event(struct visual_3d_cursor_context * _Context);
public	int	visual_3d_cursor_remove(struct visual_3d_cursor_context * _Context);
public	int	visual_3d_cursor_show(struct visual_3d_cursor_context * _Context);

/* vdebug.c */
public	int	accept_debug_parameters(
	char * pFileName,
	char * pCommandLine,
	char * pIsDebug,
	char * pDebugger,
	char * pDebugRoot,
	char * pRuntime);

/* vedcmd.c */
public	int	accept_editor_command(char * pEditorCommand);

/* verror.c */
public	int	accept_error(char * pErrorMsg,char * pFileName);

/* vfile.c */
struct file_control  * allocate_file_control(struct database_editor_context * _Context);
struct file_control  * AddFileClass(struct database_editor_context * _Context,int type, char * cname, char * oname, char * fname, char * format);
char	 * AddFileObject(struct database_editor_context * _Context,int type, char * iname, char * fname, char * format, char * hname);
public	int	database_editor();
public	int	database_editor_losefocus(struct database_editor_context * _Context);
void	initilise_file_manager(struct database_editor_context * _Context);
void	liberate_file_control(struct database_editor_context * _Context,struct file_control * fptr);
void	liberate_file_manager();
#ifdef __cplusplus		/* GWB le 15/06/2007 */
void	use_data_selector(void * _Context,char * rptr,int rlen, char * iptr,int ilen, char * nptr, int nlen);
#else
void	use_data_selector(struct database_editor_context * _Context,char * rptr,int rlen, char * iptr,int ilen, char * nptr, int nlen);
#endif

/* vfload.c */
public	int	accept_fontload(char * pFileName,char * pIsAnsi);
public	int	accept_form_load(char * pFileName);

/* vform.c */
public	int	accept_form_control(
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pConstants,
#ifdef	ABAL32A
	char * pStyling,
#endif
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pDynamic,
	char * pCommandLine,
	char * pArgVLen,
	char * pArgVNb,
	char * pResize,
	char * pResizeX,
	char * pResizeY,
	char * pGenHelp,
	char * pActHelp,
	char * pAskAtribut,
	char * pAskFore,
	char * pAskBack,
	char * pFileName,
	char * pIdentity,
	char * pStyleSheet,
	char * pPaletteName,
	char * pClearScreen,
	char * pSendLeft,
	char * pSendMiddle,
	char * pSendRight,
	char * pSendWheel,
	char * pMouseWidgets,
	char * pInhibitPurge,
	char * pMoving,
	char * pSendDown,
	char * pSendUp,
	char * pSendWhileDown,
	char * pSendMove,
	char * pMouseKey,
	char * pWidgetTriggers,
	char * pEscape,
	char * pEnter,
	char * pPageUp,
	char * pPageDown,
	char * pUpArrow,
	char * pDownArrow,
	char * pTabulation,
	char * pDefaultBreak);

/* vfsave.c */
public	int	accept_fontsave(char *  pFileName);
public	int	accept_form_save(char * pFileName);

/* vfselect.c */
public	int	file_selector(char * pResult,char * pFileType,char * pPath,char * pFileSelection);

/* vhelper.c */
public	int	accept_help_messages_losefocus(struct accept_help_messages_context * _Context);

/* viload.c */
public	int	accept_imageload(char * pFileName);

/* vimages.c */
public	void	image(	int atx, int aty, int tw, int th, struct standard_image * iptr, int options );
public	int	accept_image_dimensions(char * pWidth,char * pHeight,char * pMakeFit);

/* vipath.c */
public	int	check_image_paths();

/* visave.c */
public	int	accept_imagesave(char * pFileName,char * pPathSelection,char * pImageFormat,char * pIsTransparent);

/* vlink.c */
public	int	accept_linker_parameters(
	char * pLinker,
	char * pTargetFile,
	char * pTargetName,
	char * pReport,
	char * pReportName,
	char * pDebug,
	char * pInputTrace,
	char * pOutputTrace,
	char * pVerbose,
	char * pModules,
	char * pIncludePath);

/* vlocate.c */
public	int	widget_reference_locator(char * pTarget);

/* vmethod.c */
public	int	accept_forms_method(
	char * pIsPublic,
	char * pIsPointer,
	char * pMethodType,
	char * pMethodClass,
	char * pMethodNature,
	char * pMethodName,
	char * pSignature,
	char * pMethodText);
public	int	accept_forms_method_losefocus(struct accept_forms_method_context * _Context);

/* vpage.c */
public	int	accept_visual_page(
	char * pDeviceLo,
	char * pDriverLo,
	char * pPagination,
	char * pPaperType,
	char * pPrintDensity,
	char * pPageLayout,
	char * pPageFeed,
	char * pPageAlign,
	char * pPreview,
	char * pLeftMargin,
	char * pLeftMarginUnits,
	char * pTopMargin,
	char * pTopMarginUnits);

/* vparam.c */
public	int	accept_general_options(
	char * pProductionLanguage,
	char * pImageFormat,
	char * pTextFont,
	char * pAlignment,
	char * pIsBold,
	char * pIsUnderline,
	char * pIsShadow,
	char * pSnapOn,
	char * pLockOn,
	char * pTestData,
	char * pAuto3001,
	char * pDropTool,
	char * pGridWidth,
	char * pGridHeight,
	char * pThickNess,
	char * pResizeBy);

/* vrecrep.c */
public	int	accept_animation_parameters(char * pFileName,char * pMode);

/* vrefer.c */
public	int	accept_configuration(
	char * pFILENAME,
	char * pABALHOST,
	char * pIDENTITY,
	char * pREPLAY,
	char * pRECORD,
	char * pATR,
	char * pATR_DEFINE,
	char * pATR_INCLUDE,
	char * pATR_OPTIONS,
	char * pALD,
	char * pALD_INCLUDE,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_INCLUDE,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
/* GWB le 14/11/2007 */
	char * pCPP,
	char * pCPP_DEFINE,
	char * pCPP_INCLUDE,
	char * pCPP_OPTIONS,
	char * pLPP,
	char * pLPP_INCLUDE,
	char * pLPP_OPTIONS,
	char * pLPP_LIBRARY,
	char * pDLLCPP,
	char * pDLLCPP_DEFINE,
	char * pDLLCPP_INCLUDE,
	char * pDLLCPP_OPTIONS,
	char * pDLLLPP,
	char * pDLLLPP_INCLUDE,
	char * pDLLLPP_OPTIONS,
	char * pDLLLPP_LIBRARY,
/* fin GWB le 14/11/2007 */
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pSTYLEPATH,
	char * pCOMPONENTPATH,
	char * pFONTPATH,
	char * pFONT1,
	char * pFONT2,
	char * pFONT3,
	char * pFONT4,
	char * pFONT5,
	char * pFONT6,
	char * pFONT7,
	char * pFONT8,
	char * pFONT9,
	char * pFONT10,
	char * pHTML_TITLE,
	char * pHTML_LOGO,
	char * pHTML_COPYRIGHT,
	char * pSCREEN_CSS,
	char * pPRINT_CSS,
	char * pNAVIGATOR,
	char * pDOCPATH,
	char * pPRINTER,
	char * pPAPERTYPE,
	char * pLAYOUT,
	char * pPAGEFEED,
	char * pRESOLUTION,
	char * pAED,
	char * pAED_FONT,
	char * pAED_STATE,
	char * pAED_SYNTAX,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_COMMENT,
	char * pAED_KEYWORD,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST);

/* vreplace.c */
public	int	accept_replace(char * pCriteria,char * pReplace,char * pIgnoreCase,char * pReverseSearch,char * pReplaceAll);

/* vsearch.c */
public	int	accept_search(char * pCriteria,char * pIgnoreCase,char * pReverseSearch);

/* vseek.c */
public	int	accept_treeviewitem(char * pAuto1801);

/* vstatus.c */
void	status_bar_message(struct visual_status_bar_context * _Context,int item, char * mptr);
public	int	visual_status_bar_create( void** /* FCH_SING struct visual_status_bar_context ** */ cptr);
public	int	visual_status_bar_show(struct visual_status_bar_context * _Context);

/* vstdfont.c */
public	int	standard_font_editor(char * pCharacterDec,char * pFontName);
public	int	standard_font_editor_show(struct standard_font_editor_context * _Context);

/* vsysfont.c */
public	int	system_font_selector(char * presultname);

/* vtable.c */
public	int	is_valid_format( char * fptr );
public	int	vfields( char * tptr, int fieldwidth[], int maxfields, int linelength );
public	int	vformat( char * fptr, int fieldwidth[], int maxfields, int linelength );
public	int	visual_format_length( char * fptr );

/* vtrad.c */
public	int	accept_traduction(
	char * pFileName,
	char * pTranslator,
	char * pDebug,
	char * pTrace,
	char * pVerbose,
	char * pListFile,
	char * pOptimise,
	char * pCompact,
	char * pInclusion);
/* vtradacc.cpp GWB le 05/09/2007 */
int accept_traductionpp(
		char * pFileName,
		char * pTranslator,
		char * pDebug,
		char * pTrace,
		char * pVerbose,
		char * pListFile,
		char * pOptimise,
		char * pCompact,
		char * pInclusion,
		void *this_param);

/* vtree.c */
public	int	accept_treeview_parameters(
	char * pTextFont,
	char * pLineSpacing,
	char * pZoneType,
	char * pSourceName,
	char * pTargetName,
	char * pPackaging,
	char * pIdentity);

/*vtrinout.c */
public	void	filetransferin( char ** nptr, char ** pptr );
public	void	filetransferdrop( char * nptr );
public	void	filetransferout( char ** nptr, char ** pptr );
public	void	transfer_signature( char * iptr, char * optr );
public	void	visual_signature( char * iptr, char * optr );
public void	visual_transferin( void*  tptr, int tlen, void*  pptr ); 
public void	visual_transferout( void*  tptr, int tlen, void* pptr );
public	char * file_to_string( char * nptr );

/* vwebgen.c */
public	int	accept_html_production(
	char * pHtmlFileName,
	char * pTitle,
	char * pStyleFileName,
	char * pMetrics,
	char * pPoints,
	char * pWebAgent,
	char * pTranslation,
	char * pRestrict,
	char * pContextual,
	char * pActiveImage,
	char * piQuality,
	char * piCookie);

/* vwidget.c */
public	int	accept_widget_properties(
	char * pPermission,
	char * pIsExtern,
	char * pCreateOptions,
	char * pCreate,
	char * pShowOptions,
	char * pShow,
	char * pFocusOptions,
	char * pGetFocus,
	char * pMimoMove,
	char * pMimoDown,
	char * pMimoUp,
	char * pMimoHold,
	char * pMimoLeft,
	char * pMimoRight,
	char * pMimoWheel,
	char * pMimoMiddle,
	char * pEventOptions,
	char * pEvent,
	char * pLoseOptions,
	char * pLoseFocus,
	char * pHideOptions,
	char * pHide,
	char * pRemoveOptions,
	char * pRemove);

public	int	accept_widget_properties_losefocus(struct accept_widget_properties_context * _Context);

/* --- XML ---------------------------------------------------------- */

/* xmlp.c */
char *	allocate_string( char * sptr );

/* xmlform.c */
public 	FILE *	open_xml_target( char * xmlname, char ** target, char * document, char * dtdname, char * cssname );
public 	void	xml_put_coordinate(FILE * h, char * name, int x, int y, int margin);
public 	void	xml_put_Form( char* nptr, struct form_control * fptr, char * dtdname );
public 	void	xml_put_xyz(FILE * h, char * name, int x, int y, int z, int margin);

/* xmlparse.c */
void	set_xml_echo(int v);
struct	xml_parser * xml_close( struct xml_parser * h );
void	xml_get_xyz(struct xml_application * xptr, int * a, int * b, int * c );
void	xml_put_string(FILE * h, char * name, char * value, int margin);
void	xml_put_word(FILE * h, char * name, int value, int margin);

/* --- autres ------------------------------------------------------- */

/* camera3d.c */
void	add_cube(struct camera3d * cptr,struct object3d * optr);

/* console.c */
public	int 	get_biosmode();
public	int 	get_bioswidth();
public	int 	get_biosheight();
public	void	set_biosmode( int vesamode );

/* fnparser.c */
WORD	fn_parser( BPTR , BPTR , WORD );

/* fontfunc.c */
public	int	font_copy_cell(int c, int number);
public	int	font_paste_cell(int c, int number);
public	int	font_recalculate( int number, int fixed );
public	int	font_export_image( int number );
public	int	font_semi_graphics( int number );
public	int	guifontfunction(int number, int c, int operation, int parameter );

/* genimage.c */
public 	void	image_close(int format);
public	void	image_configuration(int ismap, int psize, char * pptr );
public 	int	image_create(char * nptr, unsigned int w, unsigned int h, int d, int format, int t );
public	int	image_row(int r, char * bptr,int rl, int format );
public 	int	image_write( char * nptr, struct standard_image * iptr, int mode, int transparence );

/* mouse.c */
void	initialise_mouse();
void	terminate_mouse();
void	without_mouse_move();

/* object3d.c */
struct	object3d * allocate_cube();

/* plusform */
public	void	aplus_visual_resolution( FILE * h );
public	void	export_aplus_form( FILE * h );
public	void	generate_aplus_file_class( FILE * h, struct form_control * fptr );

/* plusline.c */
public	int	aplus_method_line( FILE * h, char * eptr, int l, char * hptr, int * feeder );

/* pluspage.c */
public	void	export_aplus_page( FILE * h );

/* threed.c */
int 	calibrate3d( int mode, int lmargin, int tmargin, int rmargin,char * palette );
void	freeze3d(struct background2d * bptr);
void	old_apply_background(struct background2d * bptr);
int	prepare_background( struct background2d * bptr );
int	set3dfocus( int x, int y );
void	thaw3d();

/* wildcomp.c */
WORD	wildcomp( unsigned char* tptr , unsigned char* wptr );

/*
*************************************************************************************************
* Fonctions privées
************************************************************************************************
*/

#ifdef _vstdfont_c
private int on_CharacterData_show(struct standard_font_editor_context * _Context);
private int on_CharacterDec_losefocus(struct standard_font_editor_context * _Context);
private int on_FontName_losefocus(struct standard_font_editor_context * _Context);
private int on_NextCharacter_event(struct standard_font_editor_context * _Context);
private int on_PreviousCharacter_event(struct standard_font_editor_context * _Context);
#endif

#ifdef _vfselect_c
private int on_FileNames_event(struct file_selector_context * _Context);
private int on_FileInfos_event(struct file_selector_context * _Context);
private int on_FileNames_event(struct file_selector_context * _Context);
private int on_Path_losefocus(struct file_selector_context * _Context);
private int on_Slider_event(struct file_selector_context * _Context);
#endif

#ifdef _singa_c
/* abalform.c */
private	void	abal_detect_trigger_events( FILE * h, int margin );
public int is_xy_modif(struct form_item * iptr);
public int is_w_modif(struct form_item * iptr);	
public int is_h_modif(struct form_item * iptr);
public int w_base_resize(struct form_item * iptr);
public int h_base_resize(struct form_item * iptr);
public	void	abal_forward_positionat( FILE * h, struct form_control * fptr );
public	void	generate_position_control(FILE * h,struct form_item * iptr);

/* abalpage.c */
private	void	reset_visual_page(FILE * h, int i );
#endif

public	char *	c_payload( struct form_item * iptr );
public	void	c_payload_value(FILE * h, struct form_item * iptr);
public	void	c_switch_widget(FILE * handle, struct form_item * iptr, int margin,int etat );
#ifdef _SING_C
private	void	generate_c_data_instance( FILE * h, struct form_item * iptr );
private	void	generate_trigger_code( FILE * h, struct form_item * iptr, int margin );
private	int	inline_c_method( FILE * h,char * mptr, char* nptr, char * eptr, int type, int margin );
private	void	c_check_widget(FILE * handle, struct form_item * iptr, int margin,int etat );
private	void	c_button_widget(FILE * handle, struct form_item * iptr, int margin,int etat );
#endif
public void	c_hint_value(FILE * h, struct form_item * iptr);

/* velement.c GWB le 08/06/2007 */
public int	visual_styled_element(int x,int y,int w,int h,char * cptr,char * sptr,int slen);

#ifdef _SINGEXPO_C
/* singhtml.c */
private	void	add_row_before( struct sort_row * lptr, struct sort_item * sptr );
private	void	html_anchor( FILE * handle, char * target, char * message );
private	void	html_widget_size(struct form_item * wptr, struct window_control * Window, int alt );
private	void	html_text_widget( FILE * handle,struct form_item * iptr, int mode );
private	void	html_unquoted_string( FILE * handle, char * sptr );
private	void	html_submit_field( FILE * h, struct form_item * iptr, char * extra, char * method);

/* singagen.c */
private	void	web_agent_set_lang( h );
private	void	web_agent_onfocus( FILE * h, struct form_control * fptr );
#endif

#ifdef _singform_c
private	int	change_FormMember( struct form_control * fptr, int event );
private	void	remove_widget(	struct form_control * fptr,struct form_item * iptr );
#endif

#ifdef _singplus_c
private	char *	aplus_payload( struct form_item * iptr );
private	void	aplus_comment(FILE * h, struct form_item * iptr, int i);
private	int	aplus_method_body( FILE * h,char * eptr, int l, char * hptr);
private	char *	prepare_abal_inclusion( char * sptr ); /* abaltrad.c */
#endif

/* xmlthree.c GWB le 23/08/2007 */
public	int	import_database( char * nptr, int nlen );
public	int	export_database( char * nptr, int nlen );
public	void	Xml_form_data_collection( char * bnptr, int blen, char * fnptr, int flen );

//#ifdef _singtool_c
/* FCH_SING private */	void	show_model_tools();
//#endif

/* wsingkernel.c : GWB le 03/07/2007 */
int calculate_differences( char* p1, int p2, char* p3, int p4, int p5);
int	iso_conversion_value( int v );
void	dropsysfontlist();
int	getsysfontlist( void ** vptr, char * wildcards, int wildlen );
void windows_resize(int w,int h);

/* singfmf.c GWB le 22/08/2007 */
char *	GetFontFileList();

/* singlock.c GWB le 29/08/2007 */
public	int	get_widget_gridlock( int wstyle );
public	void	set_widget_gridlock( int wstyle, int wvalue );

/* vgridlock.c GWB le 03/09/2007 */
public int accept_widget_gridlock();

/* visual.c GWB le 19/09/2007 */
#ifdef UNIX
public	int	x_conf(int i);
#endif

/* loadlib.cpp GWB le 09/10/2007 */
int run_library(char *library);
#ifdef __cplusplus
#include "vclass.h"
#ifdef UNIX
typedef void * HINSTANCE;
#endif
class_visual_container *load_library(char *library,HINSTANCE *hndl);
void detach_library(HINSTANCE hndl,class_visual_container *l);
#endif

#ifdef __cplusplus	/* GWB le 05/06/2007 */
}
#endif

#include "choixrepfic.h"
/*
*************************************************************************************************
* PRAGMA COMPILATION
************************************************************************************************
*/

#pragma warning( disable : 4101 )  // unreferenced local variable
#pragma warning( disable : 4102 )  // unreferenced label

#endif	/* WIN32 */

#endif	/* _SINGPROTO_H */

