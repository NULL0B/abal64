//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_redirected_h
#define	_html_redirected_h

#include "output.h"
#include "buffer.h"

class	html_redirected : public html_output {
public:
	html_output * target;
	html_redirected( html_output * parent );
	virtual	int 		outputbyte(int c);
	virtual int		enter( int n );
	virtual int		leave( int n );
	virtual	int		width();
	virtual int		position();
	virtual void		reposition(int l);
	virtual int  		setanchor( html_anchor_descriptor * aptr );
	virtual void		ruler(html_rule_descriptor * dptr );
	virtual void		image(html_image_descriptor * dptr );
	virtual void		input(html_input_descriptor * dptr );
	virtual void		applet(html_applet_descriptor * dptr );
	virtual html_output * 	opentable(html_table_descriptor * dptr );
	virtual void 		closetable(html_output * optr );
	virtual int 	puts(char * cptr);
	virtual int 	putb(int c );

	virtual int	setfont( int i );

	virtual int	textcolour( int i );
	virtual int	washcolour( int i );
	virtual int	linkcolour( int i );
	virtual int	donecolour( int i );
	virtual int	workcolour( int i );

	virtual int	fontwidth  ();
	virtual int	fontheight ();
	virtual int	pixelwidth ();
	virtual int	pixelheight();


	};

class	html_cell_output	: 	public html_printer,
					public html_buffer_descriptor {

public:
	html_output 		* target;
	html_cell_descriptor	* cell;
	html_cell_output 	* previous;
	html_cell_output 	* next;
	int			gotlast;
	int			maxwidth;
	html_cell_output( html_output * tptr, html_cell_descriptor * cptr, int unitwidth );
	virtual	int 		outputbyte( int c );
	int			getfirst( int linenumber );
	int			getnext();
	int			foreground;
	virtual int	 	setanchor( html_anchor_descriptor * aptr );
	
	};

class	html_row_output : public html_redirected {
public:
	html_table_descriptor	* table;
	html_row_output 	* previous;
	html_row_output 	* next;
	html_cell_output 	* first;
	html_cell_output 	* current;
	html_cell_output 	* last;

	html_row_output( html_output * parent, html_table_descriptor * dptr );
	virtual html_output * 	opencell(html_cell_descriptor * dptr );
	virtual void 		closecell(html_output * optr);
	virtual int 		start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual void		commit();

	};


class	html_table_output : public html_redirected {
public:
	html_text_descriptor	* caption;
	html_table_descriptor	* table;
	html_row_output 	* first;
	html_row_output 	* current;
	html_row_output 	* last;
	int			redirection;
	html_table_output( html_output * parent, html_table_descriptor * dptr );
	virtual html_output * 	openrow(html_row_descriptor * dptr );
	virtual void 		closerow(html_output * optr);
	virtual int 		start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual void		commit();
	virtual int		outputbyte(int c);
	virtual int 		puts(char * cptr);
	virtual int 		putb(int c );
	};


#endif	// _html_redirected_h


