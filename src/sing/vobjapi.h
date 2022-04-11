// ********************************************************************************
// * vobjapi.h
// ********************************************************************************

#ifndef  _VOBJAPI_H_
#define _VOBJAPI_H_

#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif

void visual_filzone(int x, int y, int w, int h, int pixel,int mode );
int	visual_progress(
	unsigned int x, 
	unsigned int y, 
	unsigned int w, 
	unsigned int h,
	int f,			
	int fg,int bg,	
	unsigned int l, 
	unsigned int v, 
	int o );

int 	activate_replay(char * nptr);
int 	activate_record(char * nptr);
int	visual_table( int x, int y, int w, int h, int f, int fg, int bg, char * tptr, char * vptr, int options, char * fptr );
void	visual_hotkeys( char * buffer, int buflen );
int	visual_help( char * sptr );
int	vrotate180( void* storage );
int	vrotate( unsigned short mode, void* rptr, void* mptr );
int	visual_initialise(int  mode );
int	visual_activate(int width, int height, int style );
int 	initialise_configuration(char * nptr);
int 	terminate_configuration();
int	set_configuration_name(char * rptr);
int	set_edit_mask(int v );

int visual_scrollbar(
	unsigned int atx, unsigned int aty, 
	unsigned int nbx, unsigned int nby, 
	int f, int fg, int bg, 
	unsigned int item, unsigned int limit, unsigned int total, 
	int style );

int	visual_liberate();
void	visual_freeze();
void	visual_thaw(int x,int y, int w, int h);
void	visual_circle(int atx, int aty, int width, int height, int colour, int style );
int	visual_frame( int atx, int aty, int nbx, int nby, int style );
void	visual_image(	int atx, int aty, int nbx, int nby, char * filename, int options );
int	visual_image_info(char * filename, int * width, int * height );
int	visual_font(char * nptr,int nlen );
int 	visual_palette( char * filename, int length );
void	visual_window( int atx, int aty, int nbx, int nby, int f, char * mptr,int mlen, int o );
int 	visual_edit(int x,int y, int w, int h, int f, char * sptr, int slen );
void	visual_text(int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options );
void	visual_button(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state);
void	visual_check(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state);
void	visual_switch(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int state);
void	visual_graph(int atx, int aty, int nbx, int nby, int f,int fg,int bg, void * vptr, int nbv, int state);
void	visual_radio(int atx, int aty, int nbx, int nby, int f,int fg,int bg, char * mptr, int mlen, int storage, int value );
void	visual_tabpage(int atx, int aty, int nbx, int nby, int f, char * mptr,int mlen, int msgx, int state );
int	visual_event(int item);
int	visual_getch();
int	visual_kbhit();
int	visual_line(int fx,int fy,int tx,int ty,int thick ,int pixel);
int	visual_viewport(int atx, int aty, int nbx,int nby, int fid);
int	visual_colour( int cmd, char * buffer, int first, int last );
#ifndef STDPSUPTR	/* GWB le 11/09/2007 */
#include "strucpsu.h"
#endif
int  visual_buffer_put(STDPSUPTR pptr, int atx, int aty );	/* GWB le 01/06/2007 */

int  visual_select(	
		int x,int y, int w, int h, 
		int f, int fg, int bg, 
		struct select_control * sptr,
		int state 
		);

int	VisualSelect(
		int x,int y,int w,int h,
		int fid, int fg, int bg, 
		char * message,int length, unsigned int * iptr,int state);

int	visual_play_sound(char * nptr );

int	visual_national_language(int v);
int	visual_trigger_code( char * bptr, int blen );
void	visual_trigger(int x,int y, int w, int h, int f, int fg, int bg,char * mptr, int mlen, int options );

#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#endif

