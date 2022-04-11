struct SingRelais {
	int (*ptr_visual_national_language) (int v);
	void (*ptr_visual_thaw) (int x,int y,int w,int h);
	void (*ptr_visual_freeze) ();
	void  (*ptr_visual_filzone) (int x, int y, int w, int h, int pixel,int mode );
	void (*ptr_visual_trigger) (int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options );
	void (*ptr_visual_text) (int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options );
	void (*ptr_visual_window) (int atx, int aty, int nbx, int nby, int f, char * mptr,int mlen, int o );
	void (*ptr_visual_image) (int atx, int aty, int nbx, int nby, char * filename, int options );
	int (*ptr_visual_frame) ( int atx, int aty, int nbx, int nby, int style );
	int (*ptr_visual_viewport) (int atx, int aty, int nbx,int nby, int fid);
	void * (*ptr_visual_buffer) (int x,int y, int w, int h );
	int (*ptr_visual_buffer_get) (STDPSUPTR pptr, int atx, int aty );
	int (*ptr_visual_buffer_put) (STDPSUPTR pptr, int atx, int aty );
	int (*ptr_visual_buffer_mix) (STDPSUPTR pptr, int atx, int aty );
	int (*ptr_visual_buffer_show) (STDPSUPTR pptr, int ci, int ri, int atx, int aty, int nbx, int nby );
	void *  (*ptr_visual_drop) ( 	void * vptr);
	int (*ptr_visual_font) (char * nptr,int nlen );
	int (*ptr_visual_kbhit) ();
	int (*ptr_visual_getch) ();
	int (*ptr_visual_event) (int item);
	void (*ptr_visual_concave) (int atx,int aty, int nbx, int nby );
	void (*ptr_relief_frame) ( int atx, int aty, int nbx, int nby, int style );
	void (*ptr_vertical_concave) (int atx,int aty, int nbx, int nby );
	void (*ptr_visual_convex) (int atx,int aty, int nbx, int nby );
	void (*ptr_vertical_convex) (int atx,int aty, int nbx, int nby );
#ifndef WIN32
	void (*ptr_visual_circle) (int atx, int aty, int width, int height, int colour, int style );
#endif
	void (*ptr_visual_elipse) (int atx,int aty,int width,int height,int colour,int style);
	void (*ptr_configuration_drop) ();
	int (*ptr_configuration_save) ( char * fptr );
	int (*ptr_configuration_load) ( char * rootname );
	void (*ptr_visual_button) (int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state);
	int (*ptr_visual_progress) (unsigned int x,unsigned int y,unsigned int w,unsigned int h,int f,int fg,int bg,unsigned int l, unsigned int v, int o );
	int (*ptr_visual_table) ( int x, int y, int w, int h, int f, int fg, int bg, char * tptr, char * vptr, int options, char * fptr );
	void (*ptr_visual_hotkeys) ( char * buffer, int buflen );
	int (*ptr_visual_help) ( char * sptr );
	int (*ptr_visual_initialise) (int  mode );
	int (*ptr_set_edit_mask) (int v );
	int (*ptr_visual_liberate) ();
	int (*ptr_visual_image_info) (char * filename, int * width, int * height );
	int  (*ptr_visual_palette) ( char * filename, int length );
	int  (*ptr_visual_edit) (int x,int y, int w, int h, int f, char * sptr, int slen );
	void (*ptr_visual_check) (int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state);
	void (*ptr_visual_switch) (int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state);
	void (*ptr_visual_graph) (int atx, int aty, int nbx, int nby, int f,int fg,int bg,void * vptr, int nbv, int state);
	void (*ptr_visual_radio) (int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int storage, int value );
	void (*ptr_visual_tabpage) (int atx, int aty, int nbx, int nby, int f, char * mptr,int mlen, int msgx, int state );
	int (*ptr_visual_line) (int fx,int fy,int tx,int ty,int thick ,int pixel);
	int (*ptr_visual_colour) ( int cmd, char * buffer, int first, int last );
	int  (*ptr_visual_select) (int x,int y, int w, int h,int f, int fg, int bg,struct select_control * sptr,int state);
	int (*ptr_visual_scrollbar) (unsigned int atx,unsigned int aty,unsigned int nbx,unsigned int nby,int f,int fg,int bg,unsigned int item,unsigned int limit,unsigned int total,int style);
	void (*ptr_mouse_move_on) ();
	void (*ptr_mouse_move_off) ();
	char * (*ptr_GetWidgetStyle) (int w);
	int (*ptr_visual_styled_element) (int x,int y,int w,int h,char * cptr,char * sptr,int slen);
	int (*ptr_visual_trigger_code) ( char * bptr, int blen );
	void (*ptr_enter_modal) ();
	void (*ptr_leave_modal) ();
	char *(*ptr_allocate_string) (char *sptr);
#ifdef UNIX
	void *(*ptr_allocate) (int size,char *sptr);
	void *(*ptr_liberate) (void *ptr,char *sptr);
#else
	void *(*ptr_allocate) (unsigned int size);
	void *(*ptr_liberate) (void *ptr);
#endif
	struct select_control * (*ptr_parse_selection) (char * message, int * item );
	int (*ptr_is_valid_format) ( char * sptr );
	int (*ptr_general_parameters) ();
	int (*ptr_menu_refresh) ();
	int (*ptr_inspect_configuration) ();
	int (*ptr_screen_capture) ();
	int (*ptr_perform_animation) ();
	int (*ptr_camera_document_Properties) (int automatic);
	int (*ptr_treeview_parameters) ();
	int (*ptr_page_parameters) ();
	int (*ptr_text_editor_find) ();
	int (*ptr_text_editor_replace) ();
	int (*ptr_syntax_composer) ();
	int (*ptr_text_editor_search) ();
	int (*ptr_get_menubar_height) ();
	int (*ptr_use_font_editor) ();
	int (*ptr_toggle_treeview) ();
	int (*ptr_guifontsize) (int number);
	};


