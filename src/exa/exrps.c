#ifndef _EXRPS_C	
#define	_EXRPS_C	
#define	_FORKING
//#undef _FORKING
/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,2010 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXRPS.C  				*/
/*		Version :	3.3b 					*/
/*		Date 	:	08/12/2010				*/
/*									*/
/*----------------------------------------------------------------------*/
/*		EXRPS	:	Abal Runtime Remote Program Server	*/
/*----------------------------------------------------------------------*/
/*	This module is the front end providing an internet service for 	*/
/*	the processing of remote program attachment requests and remote	*/
/*	procedure calls from distant remote program clients.		*/
/*	The service is built around the runtime library shared object	*/
/*	often refered to as the abal call through extension offering 	*/
/*	program loading and execution as a shared library instead of as	*/
/*	the more usual stand alone program known as exa.		*/
/*----------------------------------------------------------------------*/
/*	Two operational modes are available				*/
/*	--abalrpc							*/
/*	--soaprpc							*/
/*----------------------------------------------------------------------*/

#define __USE_LARGEFILE64
#define	__USE_FILE_OFFSET64

#include "exrps.h"
#include "exdll.h"
#include "exvtype.h"
#include "extcp.h"
#include "exhttp.h"
#include "soapapp.h"
#include "allocate.h"

extern	EXAWORD procmaxid;

char * rpc_parse_parameter( char * );
void  rpc_parse_hex_string(char * rptr, char ** sptr,int bytes );
int   rpc_parse_hex_value( char ** sptr,int bytes );
BPTR procedure_data_table(EXAWORD);

static	struct  remote_program_server RPS = {
	0,
	"exrpc",
	0,
	0,
	256,
	_DEFAULT_ABAL_RPS_PORT,
	AF_INET,
	2,
	"",
	"abalrpc",
	"localhost",
	"stderr"
	};

/*	----------------------------------------------------------	*/
/*			r p c _ l o g _ t o _ f i l e 			*/
/*	----------------------------------------------------------	*/
static	void	rpc_log_to_file(char * mptr,  char * pptr, int value )
{
	return;
}

/*	----------------------------------------------------------	*/
/*			r p c _ l o g _ t o _ s t d o u t 		*/
/*	----------------------------------------------------------	*/
static	void	rpc_log_to_stdout(char * mptr,  char * pptr, int value )
{
	char * aptr = (char *) 0;

	if ( RPS.useaddress )
	{
		aptr = (char *) &RPS.address.sin_addr;
		printf("%u.%u.%u.%u:%u: ",
			( *(aptr + 0) & 0x00FF),
			( *(aptr + 1) & 0x00FF),
			( *(aptr + 2) & 0x00FF),
			( *(aptr + 3) & 0x00FF),
			ntohs(RPS.address.sin_port));
	}
	printf("%s:%u:%s:%s:%u\r\n",RPS.argvzero,getpid(),(mptr ? mptr : "\0"),(pptr? pptr : "\0") , value );
	return;
}

/*	----------------------------------------------------------	*/
/*			r p c _ l o g _ t o _ s t d e r rr		*/
/*	----------------------------------------------------------	*/
static	void	rpc_log_to_stderr(char * mptr,  char * pptr, int value )
{
	char * aptr = (char *) 0;

	if ( RPS.useaddress )
	{
		aptr = (char *) &RPS.address.sin_addr;
		fprintf(stderr,"%u.%u.%u.%u:%u: ",
			( *(aptr + 0) & 0x00FF),
			( *(aptr + 1) & 0x00FF),
			( *(aptr + 2) & 0x00FF),
			( *(aptr + 3) & 0x00FF),
			ntohs(RPS.address.sin_port));
	}
	fprintf(stderr,"%s(%u):%s:%s:%u\r\n",RPS.argvzero,getpid(),(mptr ? mptr : "\0"),(pptr? pptr : "\0") , value );
	return;
}

/*	----------------------------------------------------------	*/
/*			r p c _ l o g _ m e s s a g e			*/
/*	----------------------------------------------------------	*/
/*	all log messages are output by this function. This may be	*/
/*	to :								*/
/*		"stdout"						*/
/*		"stderr"						*/
/*		"null"							*/
/*	or to a named logfile.						*/
/*	----------------------------------------------------------	*/
static	void	rpc_log_message(char * mptr,  char * pptr, int value )
{
	if (!( RPS.logname ))
		return;
	else if (!( strcmp(RPS.logname,"null") ))
		return;
	else if (!( strcmp( RPS.logname, "stdout" ) ))
		rpc_log_to_stdout( mptr, pptr, value );
	else if (!( strcmp( RPS.logname, "stderr" ) ))
		rpc_log_to_stderr( mptr, pptr, value );
	else	rpc_log_to_file( mptr, pptr, value );
	return;
}

/*	----------------------------------------------------------	*/
/*				f a i l u r e				*/
/*	----------------------------------------------------------	*/
static	int	failure(char * message, int evalue )
{
	rpc_log_message("error",message,evalue);
	return( evalue );
}

/*	----------------------------------------------------------	*/
/*			s i g n a l _ c a t c h e r			*/
/*	----------------------------------------------------------	*/
static	int	signal_caught=0;
void	signal_catcher(int s)
{
	if ( RPS.debug ) 
	{ 
		rpc_log_message("signal","catcher", s); 
	}
	signal_caught = s;
	return;
}

/*	----------------------------------------------------------	*/
/*			c h i l d _ c l e a n e r			*/
/*	----------------------------------------------------------	*/
#define	_MAX_CHILD_WORKER	2048
static	int	maxWorker=0;
static	int	freeWorker=0;
static	int	childWorker[_MAX_CHILD_WORKER][2];

/*	----------------------------------------------------------	*/
/*			l o g _ c h i l d _ w o r k e r			*/
/*	----------------------------------------------------------	*/
static	void	log_child_worker( char * mptr, int i )
{
	char	buffer[1024];
	if ( RPS.debug )
	{
		sprintf(buffer,"worker(p=%u,s=%u)",childWorker[i][0],childWorker[i][1]);
		rpc_log_message(mptr, buffer, i );
	}
	return;
}

/*	----------------------------------------------------------	*/
/*	      i n i t i a l i s e _ c h i l d _ w o r k e r s		*/
/*	----------------------------------------------------------	*/
void	initialise_child_workers()
{
	int	i;
	for ( i=0; i < _MAX_CHILD_WORKER; i++ )
	{
		childWorker[i][0] = -1;
		childWorker[i][1] = -1;
	}
	maxWorker = freeWorker = 0;
	return;
}

/*	----------------------------------------------------------	*/
/*			a d d _ c h i l d _ w o r k e r			*/
/*	----------------------------------------------------------	*/
void	add_child_worker( int pid, int socket )
{
	int	i;
	if ((i = freeWorker) < maxWorker )
	{
		freeWorker = childWorker[i][1];
		childWorker[i][0] = pid;
		childWorker[i][1] = socket;	

	}
	else
	{
		freeWorker = ++maxWorker;
		childWorker[i][0] = pid;
		childWorker[i][1] = socket;	
	}
	log_child_worker("add",i);
	return;	
}

static	void	catch_signals();

/*	----------------------------------------------------------	*/
/*			c h i l d _ c l e a n e r			*/
/*	----------------------------------------------------------	*/
void	child_cleaner(int s)
{
	int	ok=0;
	int	status=0;
	int	i;
	int	childpid;
	catch_signals();
	if ( RPS.debug ) { rpc_log_message("child","cleaner", s);  }
	while (1)
	{
		if ((childpid = waitpid(0, &status,WNOHANG )) > 0)
		{
			for ( ok=0,i=0; i < maxWorker; i++ )
			{
				if ( childWorker[i][0] == childpid )
				{
					log_child_worker("del",i);
					close_tcp( childWorker[i][1] );
					childWorker[i][0] = -1;
					childWorker[i][1] = freeWorker;
					freeWorker = i;
					ok=1;
					break;
				}
			}
			if (!( ok )) { rpc_log_message("missing","worker",childpid); }
		}
		else 	break;
	}
	catch_signals();
	return;
}

/*	----------------------------------------------------------	*/
/*			c a t c h _ s i g n a l s			*/
/*	----------------------------------------------------------	*/
static	void	catch_signals()
{
	signal( SIGINT,signal_catcher);
	signal( SIGTERM,signal_catcher);
	signal( SIGCHLD,child_cleaner);
}

/*	----------------------------------------------------------	*/
/*			   t r y _ u n l i n k				*/
/*	----------------------------------------------------------	*/
static	void	try_unlink( char * filename )
{
	if (!( RPS.debug ))
		unlink( filename );
}


/*	----------------------------------------------------------	*/
/*			a t t a c h _ p r o g r a m			*/
/*	----------------------------------------------------------	*/
static	struct abal_program_handle * attach_program( char * aptr )
{
	char	progname[4096];
	struct	abal_program_handle * aph;
	sprintf(progname,"%s%s",RPS.root,( *aptr == '/' ? (aptr+1) : aptr ));
	aptr = progname;
	if ( RPS.verbose )
		printf("attach_program(%s)\r\n",aptr);
	
	if (!( aph = LoadAbalProgram( aptr, 0 ))) 
	{
		if ( RPS.verbose )
			printf("attach_program_failure(%s)\r\n",aptr);

		return(aph);	
	}
	else
	{
		return(aph);
	}
}

/*	----------------------------------------------------------	*/
/*			d e t a c h _ p r o g r a m			*/
/*	----------------------------------------------------------	*/
static	struct abal_program_handle * detach_program( struct abal_program_handle * aph )
{
	if ( aph )
	{
		if ( RPS.verbose )
			printf("detach_program()\r\n");
		(aph->stop)(aph);
	}
	return((struct abal_program_handle *) 0);
}

/*	----------------------------------------------------------	*/
/*			s e n d _ r e s p o n s e			*/
/*	----------------------------------------------------------	*/
static	void	send_response( int h, char * message )
{
	char	buffer[2048];
	if ( RPS.verbose )
		printf("response: %s\r\n",message);
	sprintf(buffer,"%s\r\n",message);
	putline_tcp( h, buffer,strlen(buffer));
	return;
}

/*	----------------------------------------------------------	*/
/*		    a d d _ r e m o t e _ v a l u e			*/
/*	----------------------------------------------------------	*/
int	add_remote_value( char * rptr, char * type, EXAWORD value, EXAWORD bytes )
{
	EXAWORD	mask;
	int	shift;
	sprintf(rptr,"%s ",type);
	rptr += strlen( rptr );
	switch ( bytes )
	{
	case	1 : mask = 0x00FF; shift = 0;  break;
	case	2 : mask = 0x00FF00; shift = 8;  break;
	case	4 : mask = 0x00FF000000; shift = 24; break;
#ifdef	ABAL64
	case	8 : mask = 0x00FF00000000000000; shift = 56; break;
#endif
	default	  : return( 0 );
	}
	while ( bytes-- )
	{
		sprintf(rptr,"%02X",(unsigned char)(((value & mask) >> shift) & 0xFF));
		rptr += 2;
		mask >>= 8;
		shift -= 8;
	}
	*(rptr++) = 0;
	return( 1 );
}

/*	----------------------------------------------------------	*/
/*		    a d d _ r e m o t e _ s t r i n g			*/
/*	----------------------------------------------------------	*/
void	add_remote_string( char * wptr, char * type, char * value, int length )
{
	sprintf(wptr,"%s %u ",type,length);
	wptr += strlen( wptr );
	while ( length-- )
	{
		sprintf(wptr,"%02X",(*(value++) & 0x00FF));
		wptr += 2;
	}		
	*(wptr++) = 0;
	return;
}

/*	----------------------------------------------------------	*/
/*			    e x i t _ r e m o t e			*/
/*	----------------------------------------------------------	*/
static	int	exit_remote( int h, struct abal_program_handle * aph )
{
	char	buffer[4096];
	int	type;
	int	rlen;
	char *	rptr;
	char *	dptr;
	char *	tptr;
	dptr = (aph->result)(aph,&type,&rlen);
	sprintf((rptr = buffer),"EXIT ");
	rptr += strlen(rptr);
	switch( type )
	{
	case	VARB_INT8	:	add_remote_value(rptr,"B",rlen,1); break;
	case	VARB_INT16	:	add_remote_value(rptr,"W",rlen,2); break;
	case	VARB_INT32	:	add_remote_value(rptr,"L",rlen,4); break;
	case	VARB_INT64	:	add_remote_value(rptr,"H",rlen,8); break;
	case	VARB_BCD	:	add_remote_string(rptr,"N",dptr,rlen); break;
	case	VARB_STR	:	add_remote_string(rptr,"S",dptr,rlen); break;
	default			:	strcat( rptr, "V 0" ); break;
	}
	send_response( h, buffer );
	return(0);
}

/*	----------------------------------------------------------	*/
/*			e r r o r _ r e m o t e				*/
/*	----------------------------------------------------------	*/
static	int	error_remote( int h, struct abal_program_handle * aph, int status )
{
	char	buffer[4096];
	sprintf(buffer,"ERROR %u",status);
	send_response( h, buffer );
	return(0);
}

/*	----------------------------------------------------------	*/
/*			c a l l _ r e m o t e				*/
/*	----------------------------------------------------------	*/
static	int	call_remote( struct abal_program_handle * aph, char * sptr )
{
	int	e;
	int	v;
	if ( RPS.verbose )
		printf("call_remote(%s)\r\n",sptr);

	if ( aph )
	{
		if ( *sptr == '#' )
			v = atoi( (sptr+1) );
		else if ((v = (aph->resolve)(aph,sptr)) == -1 )
			return(114);
		e = (aph->procedure)(aph,v);
	}
	return(e);
}

/*	----------------------------------------------------------	*/
/*		    p a r a m e t e r s _ r e m o t e			*/
/*	----------------------------------------------------------	*/
static	int	parameters_remote( struct abal_program_handle * aph, char * sptr )
{
	char *	wptr;
	char	buffer[8192];
	int	paracount=0;
	int	e=0;
	int	v;
	if ( RPS.verbose )
		printf("parameters_remote(%s)\r\n",sptr);

	if ( aph )
	{
		sptr = rpc_parse_parameter((wptr = sptr));
		for (	paracount=atoi(wptr);
			paracount != 0;
			paracount-- )
		{
			sptr = rpc_parse_parameter((wptr = sptr));
			switch ( *(wptr++) )
			{
				case	'B'	:
					v = rpc_parse_hex_value( &sptr, 1 );
					(aph->parameter)(aph,VARB_INT8,v, buffer);
					continue;
				case	'W'	:
					v = rpc_parse_hex_value( &sptr, 2 );
					(aph->parameter)(aph,VARB_INT16,v, buffer);
					continue;
				case	'L'	:
					v = rpc_parse_hex_value( &sptr, 4 );
					(aph->parameter)(aph,VARB_INT32,v, buffer);
					continue;
				case	'H'	:
					v = rpc_parse_hex_value( &sptr, 8 );
					(aph->parameter)(aph,VARB_INT64,v, buffer);
					continue;
				case	'N'	:
					sptr = rpc_parse_parameter((wptr = sptr));
					v = atoi( wptr );
					rpc_parse_hex_string(buffer, &sptr, v );
					(aph->parameter)(aph,VARB_BCD,v, buffer);
					continue;
				case	'S'	:
					sptr = rpc_parse_parameter((wptr = sptr));
					v = atoi( wptr );
					rpc_parse_hex_string(buffer, &sptr, v );
					(aph->parameter)(aph,VARB_STR,v, buffer);
					continue;
				default		:
					break;
			}
			break;
		}
	}
	return(e);
}

/*	----------------------------------------------------------	*/
/*			  l d g o _ r e m o t e				*/
/*	----------------------------------------------------------	*/
static	int	ldgo_remote( struct abal_program_handle * aph, char * sptr )
{
	int	e;
	int	v;
	if ( RPS.verbose )
		printf("ldgo_remote(%s)\r\n",sptr);

	if ( aph )
	{
		e = (aph->segment)(aph,atoi(sptr));
	}
	return(e);
}

/*	----------------------------------------------------------	*/
/*			s t o p _ r e m o t e				*/
/*	----------------------------------------------------------	*/
static	void	stop_remote( char * sptr )
{
	if ( RPS.verbose )
		printf("stop_remote(%s)\r\n",sptr);
	return;
}

/*	----------------------------------------------------------	*/
/*		a b a l r p c _ p r o g r a m _ c l i e n t		*/
/*	----------------------------------------------------------	*/
static	void	abalrpc_program_client(int h, struct sockaddr_in address)
{
	int	status;
	struct	timeval TimeOut;
	fd_set	r;
	fd_set 	w;
	fd_set	x;
	struct	abal_program_handle * aph=(struct abal_program_handle *) 0;
	char	command[4097];
	char *	sptr;

	memcpy( &RPS.address, &address, sizeof( struct sockaddr_in ) );
	RPS.useaddress = 1;
	
	if ( RPS.verbose )
		printf("abalrpc program client connection: pid=%u\r\n",getpid());

	while (!(signal_caught)) 
	{
		catch_signals();
		FD_ZERO(&r);
		FD_ZERO(&w);
		FD_ZERO(&x);
		FD_SET(h,&r);
		TimeOut.tv_sec = (unsigned long) (RPS.seconds*10);
		TimeOut.tv_usec = (unsigned long) 0;
		if (!(status = select( h+1, &r, NULL, NULL ,&TimeOut )))
			continue;
		else if ( status < 0 )
		{
			if ( errno != EINTR )
				break;
			else	continue;
		}
		else if (!( getline_tcp( h, command, 4096 )  ))
			break;
		else
		{
			sptr = command;
			while (( *sptr != 0 ) && ( *sptr != ' ' ))
				sptr++;
			*(sptr++) = 0;
			if (!( strcmp( command, "ATTACH" ) ))
			{
				if ( aph )
					aph = detach_program( aph );

				if (!( aph = attach_program( sptr ) ))
					send_response(h,"ERROR");
				else
				{
					sprintf(command,"OK %llu",procmaxid);
					send_response(h,command);					
				}
			}
			else if (!( strcmp( command, "DETACH" ) ))
			{
				if ( aph )
					aph = detach_program( aph );
				send_response(h,"OK");
			}		
			else if (!( strcmp( command, "CALL" ) ))
			{
				if (!( status = call_remote( aph, sptr ) ))
					exit_remote( h, aph );
				else	error_remote( h, aph, status );
			}
			/* ------------------------------------- */
			/* ARG <count> { <type> [<size>] <hex> } */
			/* types : B,W,L,H,N,S			 */
			/* ------------------------------------- */
			else if (!( strcmp( command, "ARGS" ) ))
			{
				parameters_remote( aph, sptr );
				send_response(h,"OK");
			}
			else if (!( strcmp( command, "LDGO" ) ))
			{
				ldgo_remote( aph, sptr );
				send_response(h,"RETSEG");
			}
			else if (!( strcmp( command, "STOP" ) ))
			{
				stop_remote( sptr );
				send_response(h,"OK");
				break;
			}							
		}
	}

	if ( RPS.verbose )
		printf("abalrpc program client shutdown: pid=%u\r\n",getpid());
	h = close_tcp( h );
#ifdef	_FORKING
	if ( RPS.debug ) { rpc_log_message( "abalrpc","exit",getppid()); }
	memset( &RPS.address, 0, sizeof( struct sockaddr_in ) );
	RPS.useaddress = 0;
	exit(0);
#else
	return;
#endif
}

/*	----------------------------------------------------------	*/
/*			s o a p r p c _ r e s p o n s e			*/
/*	----------------------------------------------------------	*/
static	void	soaprpc_response(int h, int status, char * message,char * filename)
{
	if ( RPS.verbose )
		printf("soaprpc: response: %u: %s: %s \r\n",status,message,filename);
	http_response_line( h, status, message );
	http_header_field(h, "Server","SoapRpc/Abal4");
	if ( filename )
		http_content_length(h,filename);
	http_end_header( h );
	if ( filename )
		http_send_file( h, filename );
	return;
}

/*	----------------------------------------------------------	*/
/*		s o a p r p c _ g e t _ c o m m a n d			*/
/*	----------------------------------------------------------	*/
static	void	soaprpc_get_command(int h, struct http_request * rptr )
{
	char *	tempname;
	struct	abal_program_handle * aph;
	if ( RPS.verbose )
		printf("soaprpc program client GET command: pid=%u\r\n",getpid());

	rpc_log_message( "soaprpc:get",rptr->object,0);

	if (!( aph = attach_program( rptr->object ) ))
	{
		soaprpc_response(h,404,"Program Not Found",(char *) 0);
		return;
	}
	else if (!( tempname = http_tempname()))
	{
		aph = detach_program( aph );
		soaprpc_response(h,520,"Server Failure",(char *) 0);
		return;
	}
	else if (!( (*aph->interface)(aph,tempname,"wsdl",RPS.hostname) ))
	{
		aph = detach_program( aph );
		soaprpc_response(h,501,"Server Failure",(char *) 0);
		return;
	}
	else
	{	
		aph = detach_program( aph );
		soaprpc_response(h,200,"OK",tempname);
		try_unlink( tempname );
		liberate( tempname );
		return;
	}
}

/*	----------------------------------------------------------	*/
/*	    s o a p r p c _ r e s o l v e _ p r o c e d u r e		*/
/*	----------------------------------------------------------	*/
static	int	soaprpc_resolve_procedure(struct abal_program_handle * aph,char * methodname)
{
	if ( *methodname == 'p' )
		return(atoi((methodname+1))-1);
	else	return((*aph->resolve)(aph,methodname));
}

/*	----------------------------------------------------------	*/
/*		  s o a p r p c _ e x i t _ r e m o t e			*/
/*	----------------------------------------------------------	*/
static	int	soaprpc_exit_remote( struct abal_program_handle * aph, char * buffer )
{
	int	type;
	int	rlen;
	char *	dptr;
	char *	tptr;
	dptr = (aph->result)(aph,&type,&rlen);
	switch( type )
	{
	case	VARB_INT8	:	add_remote_value(buffer,"B",rlen,1); break;
	case	VARB_INT16	:	add_remote_value(buffer,"W",rlen,2); break;
	case	VARB_INT32	:	add_remote_value(buffer,"L",rlen,4); break;
	case	VARB_INT64	:	add_remote_value(buffer,"H",rlen,8); break;
	case	VARB_BCD	:	add_remote_string(buffer,"N",dptr,rlen); break;
	case	VARB_STR	:	add_remote_string(buffer,"S",dptr,rlen); break;
	default			:	strcat( buffer, "V 0" ); break;
	}
	return(0);
}

/*	----------------------------------------------------------	*/
/*		s o a p r p c _ e r r o r _ r e m o t e			*/
/*	----------------------------------------------------------	*/
static	int	soaprpc_error_remote( struct abal_program_handle * aph, int status, char * buffer )
{
	sprintf(buffer,"%u",status);
	return(0);
}

/*	----------------------------------------------------------	*/
/*	    s o a p r p c _ p a r a m e t e r s _ r e m o t e		*/
/*	----------------------------------------------------------	*/
static	int	soaprpc_parameters_remote( struct abal_program_handle * aph, struct xml_tag * method, int procid )
{
	char *	dptr;
	char *	vptr;
	char	buffer[8192];
	int	paracount=0;
	int	vcount=0;
	int	e=0;
	int	v;
	struct	xml_tag * values;
	
	if ( aph )
	{
		/* ------------------------------------------------ */
		/* initialise procedure parameter reception control */
		/* ------------------------------------------------ */
		if (!( dptr = procedure_data_table( procid ) ))
			return(131);
		else if (!(vcount = (*aph->parametertype)(aph,&dptr,0,0)))
			return(132);

		for (	paracount=1, values = method->first_tag;
			values != (struct xml_tag *) 0;
			values = values->next, paracount++ )
		{
			if ( *values->name != 'v' )
				continue;
			else if (!( vptr = values->value ))
				return( 118 );
			while (( *vptr == '\n' )
			   ||  ( *vptr == '\r' )
			   ||  ( *vptr == '\t' ))
				vptr++;

			switch ( (*aph->parametertype)(aph, &dptr, paracount, vcount  ) )
			{
			case	VARB_INT8	:
				v = atoi( vptr );
				(*aph->parameter)(aph,VARB_INT8,v, vptr);
				continue;
			case	VARB_INT16	:
				v = atoi( vptr );
				(*aph->parameter)(aph,VARB_INT16,v, vptr);
				continue;
			case	VARB_INT32	:
				v = atoi( vptr );
				(*aph->parameter)(aph,VARB_INT32,v, vptr);
				continue;
			case	VARB_INT64	:
				v = atoi( vptr );
				(*aph->parameter)(aph,VARB_INT64,v, vptr);
				continue;
			case	VARB_BCD	:
				v = strlen( vptr );
				rpc_parse_hex_string(buffer,&vptr,v/2);
				(*aph->parameter)(aph,VARB_BCD,v/2, buffer);
				continue;
			case	VARB_STR	:
				v = strlen( vptr );
				rpc_parse_hex_string(buffer,&vptr,v/2);
				(aph->parameter)(aph,VARB_STR,v/2,buffer);
				continue;
			default		:
				/* ------------------- */
				/* incorrect parameter */
				/* ------------------- */
				return( 131 );
			}
		}
	}
	return(e);
}

/*	----------------------------------------------------------	*/
/*		s o a p r p c _ p o s t _ c o m m a n d			*/
/*	----------------------------------------------------------	*/
static	void	soaprpc_post_command(int h, struct http_request * rptr ) 
{
	int	status;
	char	buffer[16000];
	int	procid=0;
	char *	tempname1;
	char *	tempname2;
	char *	methodname;
	struct 	xml_tag * method;
	struct	abal_program_handle * aph;
	struct	xml_tag * document;

	if ( RPS.verbose )
		printf("soaprpc program client POST command: pid=%u\r\n",getpid());

	rpc_log_message( "soaprpc:post",rptr->object,0);

	if (!( tempname1 = http_tempname()))
		soaprpc_response(h,530,"Server Failure",(char *) 0);
	else if (!( tempname2 = http_tempname()))
		soaprpc_response(h,501,"Server Failure",(char *) 0);
	else if (!( http_recv_file_request( h, rptr,tempname1 ) ))
	{
		liberate( tempname1 );
		liberate( tempname2 );
		soaprpc_response(h,401,"Incorrect Request",(char *) 0);
		return;
	}
	else if (!( aph = attach_program( rptr->object ) ))
	{
		try_unlink( tempname1 );
		liberate( tempname1 );
		liberate( tempname2 );
		soaprpc_response(h,404,"Not Found",(char *) 0);
		return;
	}
	else if (!( document = xml_parse_file( tempname1, aph->xmlparser ) ))
	{
		try_unlink( tempname1 );
		aph = detach_program( aph );
		liberate( tempname1 );
		liberate( tempname2 );
		soaprpc_response(h,402,"Incorrect Request",(char *) 0);
		return;
	}
	else if (!( method = locate_method_node( document ) ))
	{
		try_unlink( tempname1 );
		document = drop_xml_document( document );
		aph = detach_program( aph );
		liberate( tempname1 );
		liberate( tempname2 );
		soaprpc_response(h,403,"Incorrect Request",(char *) 0);
		return;
	}
	else if (!( methodname = extract_method_name( method ) ))
	{
		try_unlink( tempname1 );
		document = drop_xml_document( document );
		aph = detach_program( aph );
		liberate( tempname1 );
		liberate( tempname2 );
		soaprpc_response(h,403,"Incorrect Request",(char *) 0);
		return;
	}
	else
	{
		procid = soaprpc_resolve_procedure( aph, methodname );
		soaprpc_parameters_remote( aph, method, procid );
		document = drop_xml_document( document );
		if (!(status = (*aph->procedure)(aph,procid) ))
		{
			soaprpc_exit_remote(aph, buffer);
			generate_response_message( tempname2, methodname, rptr->host, rptr->object, buffer );
		}
		else
		{
			soaprpc_error_remote(aph,status,buffer);
			generate_fault_message( tempname2, "Fault", rptr->host, rptr->object, buffer );
		}
		aph = detach_program( aph );
		soaprpc_response(h,200,"OK",tempname2);
		try_unlink( tempname1 );
		liberate( tempname1 );
		try_unlink( tempname2 );
		liberate( tempname2 );
		return;
	}
}

/*	----------------------------------------------------------	*/
/*		s o a p r p c _ p r o g r a m _ c l i e n t		*/
/*	----------------------------------------------------------	*/
static	void	soaprpc_program_client(int h, struct sockaddr_in address )
{
	int	status;
	struct	timeval TimeOut;
	fd_set	r;
	fd_set 	w;
	fd_set	x;
	char *	sptr;
	struct	http_request * rptr;

	memcpy( &RPS.address, &address, sizeof( struct sockaddr_in ) );
	RPS.useaddress = 1;

	if ( RPS.verbose )
		printf("soaprpc program client connection: pid=%u\r\n",getpid());

	if ( RPS.debug ) { rpc_log_message( "soaprpc","connection",h); }

	while (!(signal_caught)) 
	{
		catch_signals();
		FD_ZERO(&r);
		FD_ZERO(&w);
		FD_ZERO(&x);
		FD_SET(h,&r);
		TimeOut.tv_sec = (unsigned long) (RPS.seconds*10);
		TimeOut.tv_usec = (unsigned long) 0;
		if (!(status = select( h+1, &r, NULL, NULL ,&TimeOut )))
			continue;
		else if ( status < 0 )
		{
			if ( errno != EINTR )
				break;
			else	continue;
		}
		else if (!( rptr = http_recv_request( h ) ))
			break;
		else 
		{
			if ( rptr->method )
			{
				if (!( strcmp( rptr->method, "GET" ) ))
				{
					soaprpc_get_command(h, rptr );
				}
				else if (!( strcmp( rptr->method, "POST" ) ))
				{
					soaprpc_post_command(h, rptr );
				}		
			}
			http_drop_request( rptr );
			continue;
		}
	}

	if ( RPS.verbose )
		printf("soaprpc program client shutdown: pid=%u\r\n",getpid());

	if ( RPS.debug ) { rpc_log_message( "soaprpc","shutdown",h); }

	h = close_tcp( h );
#ifdef	_FORKING
	if ( RPS.debug ) { rpc_log_message( "soaprpc","exit",getppid()); }
	memset( &RPS.address, 0, sizeof( struct sockaddr_in ) );
	RPS.useaddress = 0;
	exit(0);
#else
	return;
#endif
}

/*	----------------------------------------------------------	*/
/*			p r o g r a m _ s e r v e r			*/
/*	----------------------------------------------------------	*/
static	int	program_server( char * aptr, int domain, int port, int clients )
{
	int	status=0;
	int	h=0;
	int	hh;
	int	optval=60;
	char *	wptr;
	unsigned  char tempxfer[4];
	struct  hostent *hp=(struct hostent *) 0;
	struct sockaddr_in address;
	struct sockaddr_in server;
	int	worker;
	int	length=sizeof( struct sockaddr );

	struct	timeval TimeOut;
	fd_set	r;
	fd_set 	w;
	fd_set	x;


	if (!( port ))
		return( failure("invalid port or service",errno) );

	if ((h = listen_tcp( port, clients )) < 0 )
		return( failure("socket creation",errno) );

	rpc_log_message( "server","initialisation",h);

	while (!(signal_caught))
	{
		catch_signals();
		FD_ZERO(&r);
		FD_ZERO(&w);
		FD_ZERO(&x);
		FD_SET(h,&r);
		TimeOut.tv_sec = (unsigned long) RPS.seconds;
		TimeOut.tv_usec = (unsigned long) 0;
		if (!(status = select( h+1, &r, NULL, NULL ,&TimeOut )))
			continue;
		else if ( status < 0 )
		{
			if ( errno != EINTR )
			{
				rpc_log_message("select","break",errno);
				break;
			}
			else	continue;
		}
		while ((hh = accept( h, &address, &length )) < 0 )
		{
			if ( errno != EINTR )
			{
				rpc_log_message("accept","break",errno);
				break;
			}
			else	continue;
		}
		if (hh < 0)
			break;
#ifdef	_FORKING
		catch_signals();
		if ((worker = fork()) != 0)
		{
			add_child_worker(worker,hh);
			continue;
		}
#endif
		else
		{
			if (!( strcmp( RPS.method, "abalrpc" ) ))
				abalrpc_program_client(hh,address);
			else if (!( strcmp( RPS.method, "soaprpc" ) ))
				soaprpc_program_client(hh,address);

#ifdef	_FORKING
			exit(0);
#else
			catch_signals();
#endif
		}
	}

	/* -------------------- */
	/* close down of server */
	/* -------------------- */
	rpc_log_message( "server","shutdown",h);
	h = close_tcp( h );
	return(0);
}

/*	----------------------------------------------------------	*/
/*				o p t i o n				*/
/*	----------------------------------------------------------	*/
static	int	option( char * aptr )
{
	switch ( *(aptr++) )
	{
	case	'-'	:
		if (!( strcmp( aptr, "ip" ) ))
			RPS.domain = AF_INET;
		else if (!( strcmp( aptr, "ipv6" ) ))
			RPS.domain = AF_INET6;
		else if (!( strcmp( aptr, "soaprpc" ) ))
			RPS.port = service2port_tcp( (RPS.method = aptr) );
		else if (!( strcmp( aptr, "abalrpc" ) ))
			RPS.port = service2port_tcp( (RPS.method = aptr) );
		else if (!( strcmp( aptr, "verbose" ) ))
			RPS.verbose=1;
		else if (!( strcmp( aptr, "debug" ) ))
			RPS.debug=1;
		return(0);

	case	'h'	:
		RPS.hostname = aptr;
		return(0);
	case	'v'	:
		RPS.verbose=1;
		return(0);
	case	'd'	:
		RPS.debug=1;
		return(0);
	case	'p'	:
		RPS.port = atoi( aptr );
		return(0);
	case	'l'	:
		RPS.logname = aptr;
		return(0);
	case	'r'	:
		RPS.root = aptr;
		return(0);
	default		:
		return(31);
	}
}

/*	----------------------------------------------------------	*/
/*				o p e r a t i o n			*/
/*	----------------------------------------------------------	*/
static	int	operation(int argc, char * argv[])
{
	int	status;
	int	argi;
	char *	aptr;

	RPS.useaddress = 0;
	memset( &RPS.address, 0, sizeof( struct sockaddr_in ) );

	if (!( RPS.port = service2port_tcp(RPS.method) ))
		return( failure( "service abalrpc not configured", 0 ) );
	for (	argi=1; argi < argc; argi++ )
	{
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' )
		{
			if ((status = option( (aptr+1) )) != 0)
				return(status);
			else 	continue;
		}
		else if ((status = program_server( aptr, RPS.domain, RPS.port, RPS.clients )) != 0 )
			return(status);
		else 	continue;
	}
	return(0);
}			

/*	----------------------------------------------------------	*/
/*				b a n n e r				*/
/*	----------------------------------------------------------	*/
static int	banner()
{
	printf("\n   Abal Remote Program Server : Version %u.%u%c.%u.%u ",4,1,'a',0,1);
	printf("\n   Provisoire du 10/12/2010 ");
	printf("\n   Copyright (c) Amenesik / Sologic \n");
	printf("\n   Options : \n");
	printf("\n   --abalrps        : start as abal rpc server ");
	printf("\n   --soaprps        : start as soap rpc server ");
	printf("\n    -l<filename>    : log requests to file name ");
	printf("\n    -v              : activate messages ");
	printf("\n    -p<number>      : specify port number ");;
	printf("\n    -r<string>      : specify path root ");
	printf("\n    -h<string>      : specify host name ");
	printf("\n   <nameofserver>   \n\n");
	return(0);
}

/*	----------------------------------------------------------	*/
/*				m a i n					*/
/*	----------------------------------------------------------	*/
int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv) );
}
	/* -------- */
#endif	/* _EXRPS_C */
	/* -------- */

