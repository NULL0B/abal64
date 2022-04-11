//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_manager_h
#define	_html_layout_manager_h

#include "output.h"		// Descriptors of all types

#include "laystore.h"		// Layout Storage Mechanisms
#include "layliber.h"		// Layout Liberation Mechanisms
#include "layout.h"		// Layout Interface Class
#include "layfont.h"		// Layout font classes
#include "layitem.h"		// Layout line item classes
#include "laybody.h"		// Layout line body classes
#include "laylink.h"		// Layout line link classes
#include "laytext.h"		// Layout line text classes
#include "layline.h"		// Layout line controller
#include "laybyte.h"		// Layout line byte classes
#include "laybytes.h"		// Layout line string classes
#include "layzone.h"		// Layout line zone classes
#include "layimage.h"		// Layout line image  classes
#include "layinput.h"		// Layout line input  classes
#include "laytable.h"		// Table  Layout controller
#include "layfset.h"		// Frameset Layout controller
#include "layalloc.h"		// Layout Allocation Mechanisms
#include "fonting.h"		// Font Image Mechanism

class	html_layout_manager : public 	html_layout, 
			      		html_layout_allocator {


	html_layout_item * standard_border( border_descriptor * border, int mode, int cwidth, html_layout_item * cptr=0);

	void	newline(int amode=0);
	void	clearline();
	void	closelines();
	void	setlimit(int value);
public:
	html_layout_vector	* windowing;

	html_layout_line	* top;
	html_layout_line	* first;
	html_layout_line	* last;
	html_layout_line	* current;
	html_layout_line	* imgcurrent;
	html_layout_line	* imglast;

	html_layout_link	* pendinganchor;
	html_layout_link	* workinganchor;
	html_layout_font	* font;
	html_layout_body 	* bodyptr;

	html_layout_table 	* tableptr;

	html_layout_frameset 	* framesetptr;

	html_anchor_descriptor 	* thisanchor;

	html_font_image		* fonting;

	html_output 	 	* physical;

	int			quote_counter;
	int			logical_line;
	int			logical_column;
	int			logical_width;
	int			left_margin;
	int			logical_alignment;
	int			column_limit;

	html_layout_manager();
	virtual	void	ondestroy	();
	virtual int 	start(html_output * target);
	virtual	void	commit( html_output * target );
	virtual	void	release();
	virtual	void	oninit();
	virtual	int	getevent( html_logical_event * eptr );
	virtual	int	use( int event );
	virtual	int	scroll( int position );
	virtual int	position();

		void	additem( html_layout_item * iptr );
		void	closeline(int lm=0,int rm=0);
		void	checkanchor(int lm, int lcc, int rm, int al=-1);

	virtual int	body	 	( html_body_descriptor 	* dptr );
	virtual int 	setanchor	( html_anchor_descriptor 	* dptr );
	virtual int 	setfont  	( html_font_descriptor 	* dptr );
	virtual	void 	addnewfont	( int fontsize, html_colour * fontfore, html_colour * fontback );
	virtual int	text	 	( html_text_descriptor 	* dptr );
	virtual int	item	 	( html_list_descriptor 	* dptr, html_text_descriptor 	* tptr, int iwidth );
	virtual int	list	 	( html_list_descriptor 	* dptr, int iwidth );
	virtual int	heading		( html_heading_descriptor * dptr, int mode );
	virtual void	ruler	 	(html_rule_descriptor  	* dptr );
	virtual void	image	 	(html_image_descriptor 	* dptr );

		int 	apply_font_image( html_image_descriptor 	* dptr,	html_horizontal_alignment * 	aptr  );

	virtual void	input	 	(html_input_descriptor 	* dptr );
	virtual void	applet 	 	(html_applet_descriptor * dptr );

	virtual	void	linefeed();


	virtual	void	quote( int mode );
	virtual void	enter( int n );
	virtual void	leave( int n );
	virtual int	align( int alignment );
	virtual int	locate( char * cptr );

	virtual void	table( html_table_descriptor * dptr );
	virtual void	row( html_row_descriptor * dptr );
	virtual void	cell( html_cell_descriptor * dptr );

	virtual void	frameset( html_frameset_descriptor * dptr );
	virtual void	frame( html_frame_descriptor * dptr );
	virtual int 	style( int mode,cssi_selector *  sptr=0 );

	virtual void	message  	(char * mptr);

	static int	basefontsize;
	static int	basefontwidth;
	static int	basefontheight;
	static int	basefontcolour;

private:
	int	oneshotalign;
	int	inhibit_line_wrap();
	void	layout_table_frame( html_layout_table * tptr, int option );
	};


#endif	// _html_layout_manager_h




