#ifndef	_rfberror_h
#define	_rfberror_h

void	error_message( char *);

#define	read_error() error_message("read")
#define	write_error() error_message("write")
#define	select_error() error_message("select")
#define	connect_error() error_message("connect")
#define	name_error() error_message("name")
#define	bind_error() error_message("bind")
#define	fctrl_error() error_message("fctrl")
#define	listen_error() error_message("listen")
#define	accept_error() error_message("accept")
#define	socket_error() error_message("socket")
#define	option_error() error_message("setsockopt")

#endif	/* _rfberror_h */





