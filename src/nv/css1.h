//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_cssi_parser_h
#define _html_cssi_parser_h

#include "string.h"
#include "streams.h"
#include "cssi.h"

class	html_cssi_parser	{

	static	char *	keywords[ _CSS1_MAX ];

	cssi_selector *	selectors;

	FILE			*	ihandle;
	char 			*	istring;
	html_ascii_stream 	* 	isource;
	html_text_descriptor 	*	imemory;

	int		istart;

	int 		echo;
	int		ungotchi;
	char		ungotch[16];
	char		tokenbuffer[1024];

	int	getch();
	void	ungetch(int c);
	char *	gettoken();
	char *	geturl();
	int	notwhite();
	int	is_keyword(char * token);
	int	translate_keyword();
	int	translate_flush(int bracing);
	int	translate_font_familly();	
	int	translate_font_variant();	
	int	translate_font_weight();	
	int	translate_font_size();	
	int	translate_font_style();	
	int	translate_rgb(int code);	
	int	translate_font();	
	int	translate_background_color();
	int	translate_background_image();
	int	translate_background_position();
	int	translate_background_repeat();
	int	translate_background_attachment();
	int	translate_background();
	int	translate_margin_width(int type);
	int	translate_margin();
	int	translate_padding_width(int type);
	int	translate_padding();
	int	translate_border_edge_width(int type);
	int	translate_border_edge_color(int type);
	int	translate_border_edge_style(int type);
	int	translate_border_items(int tw, int ts, int tc);
	int	translate_border_top();
	int	translate_border_right();
	int	translate_border_bottom();
	int	translate_border_left();
	int	translate_border_style();
	int	translate_border_width();
	int	translate_border_color();
	int	translate_border();
	int	translate_color();	
	int	translate_word();	
	int	translate_letter();	
	int	translate_text_decoration();	
	int	translate_text_align();	
	int	translate_text_indent();	
	int	translate_text_transform();	
	int	translate_text();	
	int	translate_vertical();	
	int	translate_line();	
	int	translate_width();	
	int	translate_height();	
	int	translate_float();	
	int	translate_clear();	
	int	translate_display();	
	int	translate_white();	
	int	translate_list_type();	
	int	translate_list_image();	
	int	translate_list_position();	
	int	translate_list();	
	int	translate_rule();
	int	translate_atrule();
	int	translate_selector();
	void	addproperty( int t, int v );
	void	addproperty( int t, int a, int b , int c );
	void	addproperty( int t, char * sptr );
	void	addurlproperty( int t, char * sptr );
	void	addlengthproperty( int t, char * sptr );
	void	addproperty( cssi_property * pptr );
	void	addtag( char * tptr );
	void	addtag( int o );
	void	reset(int v=0);

public: html_cssi_parser();
	~html_cssi_parser();

	cssi_selector *	parse_file  ( char * filename, int options=0 );
	cssi_selector *	parse_string( char * sptr, int options=0 );
	cssi_selector *	parse_memory( html_text_descriptor * source, int options=0 );
	cssi_selector *	parse_entity( html_ascii_stream * source, int options=0 );


	static char   * keyword( int v );

	};

#endif	// _html_cssi_parser_h




