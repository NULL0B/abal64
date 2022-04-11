class html_data_descriptor {

public:	
	html_text_block * first;
	html_text_block * last;
	html_text_block * current;

	html_data_descriptor();
	int	puttextbyte( int c );
	int	gettextbyte();
	int	firsttextbyte();

	void	release();
	int	bytecount;

	};

class html_text_descriptor : public html_data_descriptor {

public:	
	html_text_descriptor();
	char *	gettoken(int started);
	int	transget();
	static	char wordbuffer[1024];
private:
	static	char	IsoText[96];
	};


