#ifndef  _RGRAPHAPI_H_
#define _RGRAPHAPI_H_

int	initialisepixel(int mode);
int	activatepixel(int width,int height, int style );
int	liberatepixel();

int	hide();
int	show(int x,int y,int w,int h);

int	filzone ( int x, int y, int w, int h, int colour );
int	xfilzone ( int x, int y, int w, int h, int colour );
int	xorzone ( int x, int y, int w, int h, int colour );
int	putzone ( int x, int y, int w, int h, char * buffer );
void	putzone8( int atx,  int aty,  int nbx,  int nby, char * sptr );
int	mixzone ( int x, int y, int w, int h, char * buffer );
int	mixzone8 ( int x, int y, int w, int h, char * buffer );
int	getzone ( int x, int y, int w, int h, char * buffer );
int	movezone ( int x, int y, int xx, int yy, int w, int h );

int 	SetCicoPixelColumn( int x );
int 	CicoFontMargin( int x );

int	init_mimo();
int	fin_mimo();
int	activate_mimo();
int	inhibit_mimo();
int	get_mimo_type();
int	get_mimo_par();
int	get_mimo_lin();
int	get_mimo_col();
int	flush_mimo();
int	get_mimo_row();
int	get_mimo_column();
int	get_mimo_mask();
int set_mimo_mask(int v);	

int	cicoatribut(int v);	

int	mimo_kbhit();
int	mimo_getch();
int	use_new_mimo();

char *	sysfilename(char * nptr);

int	vgapalette(char * bptr, int d, int n );
int	load_palette_byexa(char * bptr);

int	loadguifont(int id, char * bptr, int blen );
int	loadguifont_windows(int id, char * bptr);
int	load_font(int id, char * bptr);

int	use_base_font(int id);
int	guifontsize(int id);

int	cicocursor(int x, int y );
int	cicocolour(int f, int b );
int	cicopalette(int c, int v );

int	PixelPutC( int v );
int	PixelFontC(int fid,int v);
int	PixelPutCat( int x, int y, int v );
int	PixelFontCat(int x, int y, int fid,int v);
int	PixelPutS( char * sptr);
int	PixelFontS(int fid,char * sptr);
int	PixelPutSat( int x, int y, char * sptr);
int	PixelFontSat(int x, int y, int fid, char * sptr );
int	PixelPutL( char * sptr, int slen);
int	PixelFontL(int fid,char * sptr, int slen );
int	PixelPutLat( int x, int y, char * sptr, int slen);
int	PixelFontLat(int x, int y, int fid, char * sptr, int slen );

int	textsizelen(int fid,char * sptr, int slen );
int	textsize(int fid,char * sptr );

void *	liberate_pixel_storage( void * bptr );
void 	capture_pixel_storage( void * bptr );
void 	refresh_pixel_storage( void * bptr );
void	*	allocate_graphic_storage( int x, int y, int w, int h );
void	*	connect_pixel_row(void * xptr, int r);
void		collect_pixel_row(void * xptr,int atcol ,int atrow, int nbcol, char * rptr );
void 	background_pixel_capture( void * bptr );
void 	cancel_pixel_capture( void * bptr );

void	cicowindow( int x,int y,int w,int h );
void	windowtitle( char * sptr );
void	windowicon( char * sptr );

int	publish_selection(char * mptr, int mlen);

int	set_letter_spacing( int fontid );
int	set_line_spacing( int fontid );

#endif /* _RGRAPHAPI_H_ */
