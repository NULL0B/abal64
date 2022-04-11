//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_standard_script_h
#define _html_standard_script_h

class	standard_script_parser	{

	int			ungotch;
	int			bytes;
	html_text_descriptor * source;
	html_based_component * host;
public:
	standard_script_parser( html_text_descriptor * dptr, html_based_component * hptr );
	virtual	int	removewhite();
	virtual	int	iswhite( int c );
	virtual	int	ispunctuation( int c );
	virtual	int	getch();
	virtual	int	isbyte(int c);
	virtual	void	ungetch(int c);
	virtual	int	gettoken( char * buffer, int maxlen );
	virtual void	operation( html_ascii_stream * target );
	virtual	int	usepunctuation( int c );
	virtual	int	usetoken( char * token );
	virtual	void	linefeed();
	virtual char *  resolveterm( char * tptr );

	};

#endif	// _html_standard_script_h



