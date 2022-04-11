//	------------------------------------------------------------------
//	Project		Staff Screamer : Graphical Screener Library Z.XP
//	------------------------------------------------------------------

#ifndef	_standard_gif_h
#define _standard_gif_h

struct standard_image * parse_gif(struct standard_image *);
int			initialise_gif(char  *);
void			terminate_gif();
struct standard_image * gif_loader(char *);

#endif	// _standard_gif_h





