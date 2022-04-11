#ifndef	_SOAPRPC_C
#define	_SOAPRPC_C

#include "exnetwork.h"
#include "exurl.h"
#include "exars.h"
#include "exrpcl.h"
#include "abalrpc.h"

int	create_remote_service(struct abal_remote_service * sptr)
{
	if (!( sptr ))
		return(0);
	else
	{
		set_exit_connection( sptr->exitvalue, sptr->exitstring );
		set_xml_parser( sptr->xmlparser );
		sptr->open	=	open_program_client;
		sptr->attach	=	attach_program_client;
		sptr->parameters=	call_program_parameters;
		sptr->call	=	call_program_client;
		sptr->result	=	exit_program_client;
		sptr->detach	=	detach_program_client;
		sptr->close	=	close_program_client;
		return(1);
	}
}




	/* ---------- */
#endif	/* _SOAPRPC_C */
	/* ---------- */



