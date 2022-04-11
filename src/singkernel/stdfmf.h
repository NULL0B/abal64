#ifndef	_stdfmf_h
#define	_stdfmf_h

struct	standard_cell	{
	int	width;		/* image width  */
	int	height;		/* image height */
	char	matrix[1];	/* image data   */
	};

struct	standard_font	{
	int			width;		/* overall width	  */
	int			height;		/* overall height	  */
	int			margin;		/* cell margin value	  */
	int			flags;		/* font options		  */
	char	*		buffer;		/* original file buffer	  */
	int			buffersize;	/* size of original buffer*/ 
	struct	standard_cell *	cell[256];	/* one for each character */
	};

#endif	/* _stdfmf_h */
	/* --------- */









