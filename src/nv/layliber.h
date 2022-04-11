//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_liberator_h
#define _html_layout_liberator_h


class	html_layout_liberator : html_layout_allocation {

public:
	static void delete_html_layout_font( html_layout_font * iptr );
	static void delete_html_layout_body( html_layout_body * iptr );
	static void delete_html_layout_link( html_layout_link * iptr );
	static void delete_html_layout_byte( html_layout_byte * iptr );
	static void delete_html_layout_bytes( html_layout_bytes * iptr );
	static void delete_html_layout_zone( html_layout_zone * iptr );
	static void delete_html_layout_text( html_layout_text * iptr );
	static void delete_html_layout_line( html_layout_line * iptr );
	static void delete_html_layout_image( html_layout_image * iptr );
	static void delete_html_layout_bmp( html_layout_bmp * iptr );
	static void delete_html_layout_button( html_layout_button * iptr );
	static void delete_html_layout_check( html_layout_check * iptr );
	static void delete_html_layout_edit( html_layout_edit * iptr );
	static void delete_html_layout_select( html_layout_select * iptr );
	static void delete_html_layout_textarea( html_layout_textarea * iptr );
	static void delete_html_layout_table( html_layout_table * iptr );
	static int  garbage_collector();

	html_layout_liberator();

	};
		

#endif	// _html_layout_liberator_h



