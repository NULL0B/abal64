//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_messages_h
#define _html_messages_h


#define	_GESMES_BANNER 	 1
#define	_GESMES_FAILURE  2
#define	_GESMES_HTTP200	 3
#define	_GESMES_HTTP201  4
#define	_GESMES_HTTP202  5
#define	_GESMES_HTTP203  6
#define	_GESMES_HTTP204	 7
#define	_GESMES_HTTP301	 8
#define	_GESMES_HTTP302	 8
#define	_GESMES_HTTP303 10
#define	_GESMES_HTTP304 11
#define	_GESMES_HTTP400 12
#define	_GESMES_HTTP401 13
#define	_GESMES_HTTP402 14
#define	_GESMES_HTTP403 15
#define	_GESMES_HTTP404 16
#define	_GESMES_HTTP500 17
#define	_GESMES_HTTP501 18
#define	_GESMES_HTTP502 19
#define	_GESMES_HTTP503 20

#define _GESMES_MENU_BACK	21
#define _GESMES_MENU_FWD	22
#define _GESMES_MENU_GOTO	23
#define _GESMES_MENU_RELOAD	24
#define _GESMES_MENU_PRINT	25
#define _GESMES_MENU_OPTIONS	26
#define _GESMES_MENU_HALT	27
#define _GESMES_MENU_NEW	28
#define _GESMES_MENU_SEARCH	29
#define _GESMES_MENU_HEAD	30
#define _GESMES_MENU_EXIT	31
#define _GESMES_MENU_VALID	32
#define _GESMES_MENU_RESET	33
#define _GESMES_MENU_INSERT	34
#define _GESMES_MENU_DELETE	35
#define _GESMES_MENU_QUIT	36

#define	_GESMES_LOADING		37
#define	_GESMES_RELOADING	38
#define	_GESMES_PRINTING	39
#define	_GESMES_HISTORY		40

#define	_GESMES_PRINTSCREEN	41
#define	_GESMES_ADDBOOKMARK	42

#define	_GESMES_SUBMIT		43
#define	_GESMES_RESET		44
#define	_GESMES_PAGE		45

#define	_GESMES_GARBAGE		46
#define	_GESMES_CONNECT		47
#define	_GESMES_FATAL		48
#define	_GESMES_ESCORRC		49
#define	_GESMES_ABANDON		50

#define	_GESMES_CONNECTED	51
#define	_GESMES_DIALING		52	
#define	_GESMES_CONNECTING	53
#define	_GESMES_DISCONNECTED	54

#define	_GESMES_PPP_DEAD		55
#define	_GESMES_PPP_NETWORK		56
#define	_GESMES_PPP_ESTABLISH		57
#define	_GESMES_PPP_AUTHENTICATE	58
#define	_GESMES_PPP_TERMINATE		59

#define	_GESMES_ABORT_RETRY_CONTINUE	60

#define	_GESMES_USAGE		61
#define	_GESMES_OPTIONV 	62
#define	_GESMES_OPTIONH 	63
#define	_GESMES_OPTIONE 	64
#define	_GESMES_OPTIONT 	65
#define	_GESMES_OPTIONC 	66
#define	_GESMES_FILENAME	67

#define	_GESMES_ERRALLOC	68
#define	_GESMES_ERRCFILE	69
#define	_GESMES_ERRWRITE	70
#define	_GESMES_DOYOUREALLY	71
#define	_GESMES_YES		72
#define	_GESMES_NO 		73
#define	_GESMES_MENU_ZOOM	74

extern	"C"	{
	void	initialise_messages();
	char *	gesmessage( int n );
	void	setgesmeslang( int l );
	int	getgesmeslang();
	};


#endif	// _html_messages_h




