//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_message_animator_h
#define _html_message_animator_h

class	html_message_animator	{


	int		zw;
	int		sl;

	int		phase;
	int		timeout;
	int		middle;
	int		lefthalf;
	int		righthalf;
	int		balls;
	int		fixlen;
	
	int		prefix;
	int		postfix;

	int		options;

	char		mover[32];
	char		fixed[64];
	char		message[96];
	char		buffer[128];

	void		setmessage(char * mptr);
	void		setphase( int v );
	void		refresh();

public:	html_message_animator(char * pmessage, int pzw, int poptions=0 );
	int	waitevent(char *emessage);
	
	static	int	timefactor;

	};

#endif	// _html_message_animator_h


