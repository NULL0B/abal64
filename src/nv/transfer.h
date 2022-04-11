//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_transfer_h
#define _html_transfer_h


class	html_transfer	{
	unsigned long	current;
	unsigned long	bytecount;
	unsigned long	contentlength;
	unsigned long	start;
	char *	msgbuffer;
	char *  reportat;

public:
	html_transfer();
	void	report(unsigned int nombre);
	void	open(char * nptr,unsigned long clength=0L);
	void	connect(char * nptr);
	void	close();
	void	failure(char * mptr);
	static	int	status;

	};

#endif	// _html_transfer_h




