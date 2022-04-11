#ifndef	_stdfont_h
#define	_stdfont_h

#define	_FMF_SIZE	16
#define	_FMF_HEIGHT	18
#define	_FMF_WIDTH	20
#define	_FMF_FLAGS	22
#define	_FMF_HQINFO 	24

#define	getw(a) ((*(a) & 0x00FF) | ((*((a)+1) & 0x00FF) << 8))

/* --------------------------------------------------------- */
/* Prototype of new system Font name string builder function */
/* --------------------------------------------------------- */
char *	sysfontname( 
	char * 	foundry,
	char *	family,
	int	weight,
	int	slant,	
	int	setwidth,
	char *	pixels,
	char *	points,
	int	hresdpi,
	int	vresdpi,
	int	spacing,
	char *	average,
	char *	charset,
	char *	wname,
	int	wcharset,
	char *	wnature );

void	anasysfontname( 
	char *	hqn,
	char * 	foundry,
	char *	family,
	int*	weight,
	int*	slant,	
	int*	setwidth,
	char *	pixels,
	char *	points,
	int*	hresdpi,
	int*	vresdpi,
	int*	spacing,
	char *	average,
	char *	charset,
	char *	wname,
	int  *  wcharset,
	char *	wnature );

#endif	/* _stdfont_h */

