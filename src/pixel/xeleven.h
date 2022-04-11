#ifndef	_xeleven_h
#define	_xeleven_h

/*	This file provides X11 substitution stubs for compilation checking	*/

typedef	Widget struct {
	int	handle;
	};

typedef	Display	struct {
	int	handle;
	};

typedef	XtAppContext struct {
	int	handle;
	};

typedef	XImage	struct	{
	char	*	data;
	int		width;
	int		columns;
	};

#endif	/* _xeleven_h */

