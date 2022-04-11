//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_stats_h
#define _html_stats_h

#define	_STAT_SERVICE	"stats:"

class	html_statistics	{
	
	static	int	onexit;

	static	void	reset();
	static	void	write();

public:
	static	long	malloc_count;
	static	long	free_count;
	static	long	image_count;
	static	long	node_count;
	static	long	garbage_count;
	static	long	failure_count;
	static	long	document_count;

	static	void	request( char * cptr );
	static	void	terminate();

	};

#endif	// _html_stats_h


