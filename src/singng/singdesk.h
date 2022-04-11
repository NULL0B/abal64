#ifndef	_singdesk_h
#define _singdesk_h
public 	void	font_save(int number,  char * nptr );
public  void	image_save( char * nptr, struct standard_image * iptr, int mode );
public 	void	build_title(struct form_item * iptr, char * mptr );
public 	void	build_button(struct form_item * iptr );
public 	void	activate_DeskTop(int mode);
public 	void	draw_item(struct window_control* dptr);
public 	void	draw_DeskTop();
#endif	/* _singdesk_h */

