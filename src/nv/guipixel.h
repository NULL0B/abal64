
int	initialisepixel( int );
int	putblock( int, int, int, int, char * );
int	putpixel( int, int, int );
int	getpixel( int, int );
void	liberatepixel( void );
int	putzone(int,int,int,int,char *);
int	getzone(int,int,int,int,char *);
int	swapzone(int,int,int,int,char *);
int	mixzone(int,int,int,int,char *);
int	filzone(int,int,int,int,int);
int	addzone(int,int,int,int,char *);
int	subzone(int,int,int,int,char * );
int	putzoom(int,int,int,int,int,char *);
int	mixzoom(int,int,int,int,char *);
#ifndef	_PROTO_USERWARE
#define	_PROTO_USERWARE
int	userware( int, int, char * );
#endif
int	hardware( void );
int	testware( void );






