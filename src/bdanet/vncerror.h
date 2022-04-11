#ifndef	_vncerror_h
#define	_vncerror_h
#include "rfberror.h"

#define	vnc_connect_error() error_message("connection to VNC server")
#define	vnc_server_error() error_message("incorrect VNC server")
#define	vnc_client_error() error_message("incorrect VNC viewer")
#define	vnc_name_error() error_message("resolving VNC server name")

#define	vnc_copy_error() error_message("unexpected copy encoding")
#define	vnc_rre_error() error_message("unexpected rre encoding")
#define	vnc_corre_error() error_message("unexpected corre encoding")
#define	vnc_hextile_error() error_message("unexpected hextile encoding")

#endif	/* _vncerror_h */






