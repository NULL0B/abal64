//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_text_descriptor_h
#define	_html_text_descriptor_h


class html_text_block	{

public:
	html_text_block * previous;
	html_text_block * next;
	int		  iread;
	int		  iwrite;
	char		  buffer[64];
	int		  identity;
	html_text_block();
	~html_text_block();
	int	putbyte(int c);
	int	getbyte();
	void	oninit();
private:
	};

class html_data_descriptor {

public:	
	html_text_block * first;
	html_text_block * last;
	html_text_block * current;

	static	html_text_block * textheap;

	html_data_descriptor();
	int			puttextbyte( int c );
	int			getdatabyte();
	int			firstdatabyte();
	html_text_block * 	new_html_text_block();
	void			delete_html_text_block(html_text_block * bptr);
	void			release();
	void			oninit();
	int			bytecount;
	int			ungotc;
	void			ungetch(int cc);

	static	int	garbage_collector();

	};

class html_text_descriptor : public html_data_descriptor {

public:	
	html_text_descriptor();

	char *	gettoken(int started);

	int	transget();

	int	firsttextbyte();
	int	gettextbyte();

	static	void	setwordsize( int nb );

private:
	static	int	wordbuffersize;
	static	char * 	wordbuffer;

	static	char	IsoText[96];
	};

#endif 	// _html_text_descriptor_h


