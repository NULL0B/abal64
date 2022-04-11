
struct	xcolour	{
	int	pixel;
	int	red;
	int	green;
	int	blue;
	int	flags;
	};

#define	XColor struct xcolour
#define	DoRed	1
#define	DoGreen	2
#define	DoBlue	4

