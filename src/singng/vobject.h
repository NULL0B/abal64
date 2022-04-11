#ifndef	_vobject_h
#define	_vobject_h

#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif

int	visual_national_language(int v);
void	visual_thaw(int x,int y, int w, int h);
void	visual_freeze();
void 	visual_filzone(int x, int y, int w, int h, int pixel,int mode );
void	visual_trigger(int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options );
void	visual_text(int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options );
void	visual_window(int atx, int aty, int nbx, int nby, int f, char * mptr,int mlen, int o );
void	visual_image(int atx, int aty, int nbx, int nby, char * filename, int options );
int	visual_frame( int atx, int aty, int nbx, int nby, int style );
int	visual_viewport(int atx, int aty, int nbx,int nby, int fid);
void *	visual_buffer(int x,int y, int w, int h );
int	visual_buffer_get(STDPSUPTR pptr, int atx, int aty );
int	visual_buffer_put(STDPSUPTR pptr, int atx, int aty );
int	visual_buffer_mix(STDPSUPTR pptr, int atx, int aty );
int	visual_buffer_show(STDPSUPTR pptr, int ci, int ri, int atx, int aty, int nbx, int nby );
void * 	visual_drop( void * vptr);
int	visual_font(char * nptr,int nlen );
int	visual_kbhit();
int	visual_getch();
int	visual_event(int item);
void	visual_concave(int atx,int aty, int nbx, int nby );
void	relief_frame( int atx, int aty, int nbx, int nby, int style );
void	vertical_concave(int atx,int aty, int nbx, int nby );
void	visual_convex(int atx,int aty, int nbx, int nby );
void	vertical_convex(int atx,int aty, int nbx, int nby );
void	visual_circle(int atx, int aty, int width, int height, int colour, int style );
void	visual_elipse(int atx, int aty, int width, int height, int colour, int style );
void	configuration_drop( void );
int	configuration_save( char * fptr );
int	configuration_load( char * rootname );
void	visual_button(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state);

#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#define	old_select(	a,b,c,d,e,f,g,p,o)	visualselect(a,b,c,d,e,f,g,p,o)

#endif	/* _vobject_h */
	/* ---------- */

