#ifndef	_window_h
#define	_window_h

#define	_MAX_TITLE	128
#define	_MAX_CADRE	8

struct	asfun_window {
	int		x;
	int		y;
	int		w;
	int		h;
	int		grx;
	int		gry;
	int		grw;
	int		grh;
	int		border;
	int		font;
	int		fg;
	int		bg;
	int		atb;
	int		frfg;
	int		frbg;
	int		fratb;
	int		atcol;
	int		atlin;
	int		frozen;
	int		lentit;
	int		control;
	int		atbtit;
	int		fgtit;
	int		bgtit;
	char 		titre[_MAX_TITLE+1];
	char 		frame[_MAX_CADRE+1];
	int		implicite;
	int		visible;
	int		scroll;
	int		cursor;
	int		shadow;
	int		menu;
	int		list;
	int		dbox;
	STDPSUPTR	storage;
	int		style;
	};	

private	int	implicite_window(int h);
public	void	clear_implicite_window();
public	void	use_implicite_window();
int	allocate_window(struct asfun_window * wptr);
struct	asfun_window * 	remove_window(struct asfun_window * wptr);
struct	asfun_window *	create_window();
void	show_window( struct asfun_window * wptr );
private	void	show_windows();



#endif  /* _window_h */
	/* --------- */


