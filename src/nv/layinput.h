//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_layout_input_h
#define	_html_layout_input_h



class	html_layout_input : 	public html_layout_item {

public:
	html_input_descriptor * descriptor;
	int			line;
	int			lines;
	int			columns;
	html_layout_font *	textfont;
	char *			source;
	html_layout_vector *	control;

	html_layout_input( 
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );

	void		oninit(
		html_input_descriptor * dptr, 
		int atline,
		int oflines,
		int cwidth,
			html_layout_vector * kptr );

	virtual	void	release();
	virtual	void	commit( html_output * target );
	virtual	int	usage(int minwidth,int maxwidth);
	virtual	int	locate( char * cptr );
	virtual	int	firstbyte(int l);
	virtual	int 	adjust(int value, int mv, int lm, int rm);
	virtual	int	nextbyte();
	void		setfont( html_layout_font * fptr );
	};


class	html_layout_button : public html_layout_input {

public:
	html_layout_button(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );

	virtual	void	commit( html_output * target );
	virtual	int	firstbyte(int l);
	virtual	void	release();
	};

class	html_layout_check : public html_layout_input {

public:
	html_layout_check(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );

	virtual	int	firstbyte(int l);
	virtual	void	release();
	};

class	html_layout_edit : public html_layout_input {

public:
	html_layout_edit(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );

	virtual	int	firstbyte(int l);
	virtual	int	nextbyte();
	virtual	void	release();

	};

class	html_layout_textarea : public html_layout_edit {

public:
	html_layout_textarea(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );

	virtual	int	firstbyte(int l);
	virtual	int	nextbyte();
	virtual	void	release();
	};

class	html_layout_select : public html_layout_input {

public:
	html_layout_select(
			html_input_descriptor * dptr, 
			int atline,
			int oflines,
			int cwidth,
			html_layout_vector * kptr );

	virtual	void	commit( html_output * target );
	virtual	int	firstbyte(int l);
	virtual	int	nextbyte();
	virtual	void	release();
	};


#endif	// _html_layout_input_h





