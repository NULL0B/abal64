//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_xcico_h
#define _xcico_h

extern "C" {
	void	cico_open(void);
	void	cico_close(void);
	void	cico_foreground( int );
	void	cico_background( int );
	void	cico_putch( int );
	void	cico_puts( char * sptr );
	int 	cico_getch(void);
	int 	cico_kbhit(void);
	int	cico_event( int );
	int 	cico_max_lines(void);
	int 	cico_use_colour(void);
	void	cico_clear(void);
	void	cico_curser(int, int);
	int 	cicogetcolumn(void);
	int 	cicogetline(void);
	};

#endif	// _xcico_h



