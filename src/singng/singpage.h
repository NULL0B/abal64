#ifndef	_singpage_h
#define	_singpage_h

struct	page_manager	{
	char *	TopMargin;
	int	BottomMargin;
	char *	LeftMargin;
	int	RightMargin;
	int	ZoneWidth;
	int	ZoneHeight;
	int	Layout;	
	int	PaperType;
	int	PrintResolution;
	char *	PageHead;
	char *	PageFoot;
	char *	DeviceName;
	char *	DriverName;
	int	TitleOpt;	
	int	FeedOpt;
	int	NumbOpt;
	int	Preview;
	int	Alignment;
	};


#endif	/* _singpage_h */
	/* ----------- */
