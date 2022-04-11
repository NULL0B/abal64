//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_http_function_h
#define	_html_http_function_h

#define	_HTTP_ABAL_FAILURE -1

int	TranscodeByte(int );
int	HttpInitialise(char *,int);
int	HttpLiberate();
int	HttpOpenServer(int,int);
int	HttpOpenClient(char *,int,int);
int	HttpClose(int,int);
int	HttpAccept(int,int);
int	HttpCommand(int,char *);
int	HttpProxyCommand(int,char *,char *);
int	HttpGet(int,char *,int);
int	HttpPut(int,char *,int);
int	HttpGetLine(int,char *,int);
int	HttpGetString(int,char *,int);
int	HttpPutLine(int,char *,int);
int	HttpGetAddress(int,char *,int);
int	HttpSetHost(int, char *);
int	HttpSetType( char *);
int	HttpPost( int, char * );
int	HttpKeepAlive( int, int );
int	HttpOpenConnection(char *,int,int,int,long);
long	HttpIpAddress(int);
void	HttpContentLength(int,char *);
void	HttpSetAuthorize( char * );
void	HttpProxyAuthorize( char * );
void	HttpCryptage(int, char *, int , int );
int	HttpSelect(int,int);
#endif	// _html_http_function_h


