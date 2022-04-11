//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_pprinter_h
#define	_html_pprinter_h

#include "printer.h"

#include "piface.h"
class	html_pprinter : public html_printer, 
			public printer_interface {

	char	*	linebuffer;
	void		user_intervention();

public:	
	virtual void	terminate();
	html_pprinter(char * filename);
	virtual void		putch(int c);
	virtual	int	outputbyte( int c );
	virtual int	start(char * uptr=0,html_text_descriptor * tptr=0);
	virtual void	commit();
	virtual	int	height();
	virtual	void	closure();
	virtual int	checkpage(int n);

	virtual void	linestart(int a, int b, int c );
	virtual void	flushline();
	virtual int	seekcolumn(int c);
	virtual int 	loch(int c);

	static	void	setdevice( char * pname );
	static	char *	device;
	static	int	paper_length;
	static	int	paper_width;
	static	int	initialise;
	static	int	top_margin;
	static	int	bottom_margin;
	static	int	page_options;
	static	int	page_start;
	static	int	configured;

	virtual	void		allow_abandon();
	virtual void		page_header(int option=0);
	virtual	void		page_footer();
	virtual	void		initialisation();
	void			escapeT( int n );
	void			page_information( int options );
	
	int			handle;
	char 			* printername;
	char 			* urlname;
	html_text_descriptor	* title;
	int			page_counter;
	int			line_counter;
	int			page_lines;
	int			page_limit;
	static	void		parameter( char * nptr, char * vptr );
private:
	int		lineindex;
	};

#endif	// _html_pprinter_h





