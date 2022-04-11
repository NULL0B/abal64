#define	WATCH struct watchform SPTR
struct	watchform {
	BPTR		watchname;	/* Variable name		*/
	BPTR		watchvalue;	/* Original Value		*/
	BPTR		watchlength;	/* Length of watch zone		*/
	BPTR		watchtype;	/* Type of variable		*/
	WATCHPTR	watchnext;	/* Pointer to Next		*/
	};

WATCHPTR	WatchBase;

