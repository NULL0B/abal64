//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_filter_h
#define _html_filter_h

class	html_ascii_stream;


class	ascii_stream_parser {

	html_ascii_stream 	*	asource;
	html_text_descriptor 	*	tsource;

	int				mode;
	int				ungotc;
	int				started;

protected:
	char			*	buffer;

public:	ascii_stream_parser(html_ascii_stream * source,int buffersize=1024);
	ascii_stream_parser(html_text_descriptor * source,int buffersize=1024);
	~ascii_stream_parser();
	int			getch();
	void			ungetch(int c);

	virtual	int		iswhitespace(int c);
	virtual	int		ispunctuation(int c);
	virtual	char *		gets();

	};

#endif	// _html_filter_h


