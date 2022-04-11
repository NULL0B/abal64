#ifdef DOS
#define	READPERM 0
#define CREATPERM 1
#define WRITEPERM 1
#endif

#ifdef PRL
#define	CTRLZ 0x001A
#define	READPERM 0
#define WRITEPERM 1
#define CREATPERM 1
#endif

#ifdef UNIX
#define	READPERM O_RDONLY
#define WRITEPERM O_RDWR
#define CREATPERM 0666
#endif

#ifdef VMS
#define	READPERM 0
#define WRITEPERM 1
#define CREATPERM 1
#endif

#define	NULL_OUTPUT	0x0000
#define	CONSOLE_OUTPUT	0x0001
#define	FILE_OUTPUT	0x0002

