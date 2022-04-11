//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_parser_h 
#define  _html_parser_h 

#include "streams.h"
#include "syntax.h"
#include "document.h"

#include "cssi.h"

#include "pending.h"


class	html_parser  {

	static html_style_manager	* globalmanager;
	static html_style_manager	* styliemanager;
	static html_style_manager	* localmanager;

	static html_pending_image	* parse_pending( standard_url * sourceulr, html_image_node * nptr, int ready , int mode );
	static html_image_node   	* reuse_image(standard_url * sourceulr );
public:	
	static	html_image_node		* firstimage;
	static	html_image_node		* lastimage;

	static void			  parse_plaintext(html_ascii_stream * source, html_document * document);
	static html_document 		* parse_document(html_ascii_stream * source, standard_url * durl=0);
	static html_basic_component 	* build_component( int nature, html_based_component * host );
	static int           		  parse_frame(html_based_component * parent, html_frame_component * frame);
	static int 			  resolve_pending( html_pending_image * pptr );
	static html_logical_image	* parse_bmp(standard_url * sourceulr );
	static html_logical_image	* parse_gif(standard_url * sourceulr );
	static html_logical_image	* parse_jpeg(standard_url * sourceulr );
	static html_logical_image	* resolve_image( char * uptr );
	static html_logical_image 	* parse_image(html_based_component * parent, html_url_field * src, int ready=0 );
	static int 	 		  parse_input_stream(html_ascii_stream * source,html_based_component * document, int closure_mode );


	// Style management

	static cssi_selector 		* parse_cssi(standard_url * uptr);
	static cssi_selector 		* parse_stylie(standard_url * uptr, char * tptr, char * mptr );
	static cssi_selector 		* parse_cssi(html_text_descriptor * source);
	static cssi_selector		* global_stylie(char * sptr );
	static cssi_selector 		* parse_stylie(html_text_descriptor * source, char * tptr, char * mptr );
	static cssi_selector 		* parse_cssi(char * source);
	static cssi_selector 		* parse_stylie(char * source, char * tptr, char * mptr );
	static cssi_selector		* select_style( char * tagname, char * classname, char * itemname );
	static void			  release_style( cssi_selector * sptr );
	static void			pushstylemanager( html_style_manager * mptr );
	static int 			popstylemanager( int mode );

	// Mime Fields and Images

	static html_mime_field  	* parse_mime_field(html_ascii_stream * source);
	static int			  compare( char * aptr, char * bptr );
	static int			  garbage_collector();
	static int			  trash_images();
	static void			  release_images();
	static int           		  image_type( char * fptr );
#ifdef	_TRACE_IMAGE_LOADING
	static void			  show_logical_image( html_logical_image * iptr );
#endif
private:
	static	char *	MimeNameBuffer;
	static	char *	MimeValueBuffer;
	int		status;

	};



#endif // _html_parser_h 
