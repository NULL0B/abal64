//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_allocator_h
#define _html_layout_allocator_h

class	html_layout_allocator : html_layout_allocation {

public:
	html_layout_font * new_html_layout_font( int s, html_colour * c, html_colour * b );
	html_layout_body * new_html_layout_body( html_body_descriptor * dptr );
	html_layout_link * new_html_layout_link( html_anchor_descriptor * lptr, int start, html_layout_font * fptr=0);
	html_layout_byte * new_html_layout_byte( int pvalue );
	html_layout_bytes * new_html_layout_bytes( int pvalue, int pcount );
	html_layout_zone * new_html_layout_zone( int pvalue, int pcount, int ls, int ms, int rs, int o, int nb=-1,html_logical_image * iptr=0, html_layout_item * cptr=0);
	html_layout_text * new_html_layout_text( html_layout_font * fptr=0 );
	html_layout_line * new_html_layout_line();
	html_layout_image * new_html_layout_image(
			html_image_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			int pwidth,
			html_layout_font * fptr,html_layout_item * cptr=0 );

	html_layout_bmp * new_html_layout_bmp(
			html_image_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			int pwidth,
			html_layout_font * fptr,
			border_descriptor * bptr,html_layout_item *  cptr=0);

	html_layout_button * new_html_layout_button(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );
	html_layout_check * new_html_layout_check(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );
	html_layout_edit * new_html_layout_edit(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );
	html_layout_select * new_html_layout_select(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );
	html_layout_textarea * new_html_layout_textarea(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );
	html_layout_table * new_html_layout_table(
		html_table_descriptor	* dptr, 
		int plm, int prm, int bfw, int bfh, int xha );

	html_layout_allocator::html_layout_allocator();

	};
		
#endif	// _html_layout_allocator_h


