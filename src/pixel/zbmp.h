//	------------------------------------------------------------------
//	Project		Staff Screamer : Graphical Screener Library Z.XP
//	------------------------------------------------------------------

#ifndef	_standard_bmp_h
#define _standard_bmp_h

struct standard_image * parse_bmp(struct standard_image *);
int			initialise_bmp(char  *);
void			terminate_bmp();
struct standard_image * bmp_loader(char *);

#endif	// _standard_bmp_h











