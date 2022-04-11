//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_vga_h
#define _html_vga_h

class	html_logical_palette;

class	html_vga {

	static char			  VgaPalette[256][4];
	static char  			* thispalette;
	static html_logical_palette 	* palettecontrol;
public:
	static	int	respect_colours;
	static	int	vga_approximation( int  r, int  g, int  b );
	static	void	vga_colour( int i );
	static	int	redvalue( int v );
	static	int	greenvalue( int v );
	static	int	bluevalue( int v );
	static	int	average(int v);
	static	void	use_palette(int item);
	static	void	put_palette();
	static	void	get_palette();
	static	void	load_palette(char * filename);
	static	void	save_palette(char * filename);
	static  char *	connect_palette();
	static	void	adjust_palette(int factor, int mode);
	static	void	copy( char * bptr );
	static	void	submit( char * bptr );
	static	void	merge( char * bptr );
	static	void	u_sing( char * bptr );
	static	void	submit( html_logical_palette * pptr );
	static	void	u_sing( html_logical_palette * pptr );
	static  html_logical_palette * paletteclient();
};


#endif	// _html_vga_h



