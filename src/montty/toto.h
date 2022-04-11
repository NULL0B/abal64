#define	RIEN	0
#define	SOFTWARE	
#ifdef	CNEW_RTSCTS
#define	HARDWARE CNEW_RTSCTS
#else
define	HARDWARE (CTSFLOW | RTSFLOW)
#endif

