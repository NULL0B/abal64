#ifndef	_abalmail_c
#define	_abalmail_c

#include "abalmail.h"
#include "encode64.h"
#include "encode64.c"

BDA	desrt;
void _cfltcvt() { return; }
void _cropzeros() { return; }

static	struct	mime_message * MimeHead=(struct  mime_message *) 0;
static	struct	mime_message * MimeFoot=(struct  mime_message *) 0;

static	struct	mime_message * retrieve_mime_message(char * nptr, int nlen);
static	struct	mime_message * liberate_mime_message(struct  mime_message * mptr);

static	int	trace=0;

/*      ---------------       */
/*      abal_to_unicode       */
/*      ---------------       */
static	unsigned int abal_to_unicode(unsigned char * bptr,unsigned int value)
{
        unsigned int i=0;
        if (!( value ))
                return( 0 );
        else if ( value < 0x0080 )
        {
                *bptr = value;
                return(1);
        }
        else if (( value = unicodes[(value - 0x0080)] ) < 0x0080)
        {
                *bptr = value;
                return(1);
        }
        else if (!( value & 0x2000 ))
        {
                /* two byte sequence */
                *(bptr++) = (0x00C0 | ((value >> 6) & 0x001F));
                *(bptr++) = (0x0080 | (value & 0x003F));
                return( 2 );
        }
        else if (!( value & 0x4000 ))
        {
                /* three byte sequence */
                *(bptr++) = (0x00E0 | ((value >> 12) & 0x000F));
                *(bptr++) = (0x0080 | ((value >> 6) & 0x003F));
                *(bptr++) = (0x0080 | (value & 0x003F));
                return( 3 );
        }
        else
        {
                /* four byte sequence */
                *(bptr++) = (0x00F0 | ((value >> 18) & 0x0007));
                *(bptr++) = (0x0080 | ((value >> 12) & 0x003F));
                *(bptr++) = (0x0080 | ((value >> 6) & 0x003F));
                *(bptr++) = (0x0080 | (value & 0x003F));
                return( 4 );
        }
}

/*	----------------	*/
/*	 dll_log_message	*/
/*	-----------------	*/
static	void	dll_log_message(char * message)
{
	FILE * h;
	if (!( h = fopen( "bdamail.log", "a" ) ))
		return;
	else
	{
		fprintf(h,"%u : %lu : %s\n",getpid(),time((unsigned long*) 0),message);
		fclose(h);
		return;
	}
}

/*	---------	*/
/*	dll_trace	*/
/*	---------	*/
static	void	dll_trace(char * message)
{
	if ( trace )
		dll_log_message( message );
	return;
}

/*	-----------	*/
/*	dll_failure	*/
/*	-----------	*/
static	int	dll_failure(char * message, int code )
{
	char 	buffer[1024];
	sprintf(buffer,"error: %u : %s ",code,message);
	dll_log_message(message);
	return(code);
}

/*	--------	*/
/*	banniere	*/
/*	--------	*/
static VOID FAR banniere()
{
	return;
}

/*	-------------------	*/
/*	  MAIL FUNCTIONS	*/
/*	-------------------	*/

/* ------------- */
/* mail_debug(#) */
/* ------------- */
static EXAWORD Dll_mail_debug(int a1)
{
	trace = a1 & 1;
	return(0);
}

/* mail_conf(%) */
static EXAWORD Dll_mail_conf(int a1)
{
	return(0);
}

/*	-------------------	*/
/*	  SMTP FUNCTIONS	*/
/*	-------------------	*/

/* -------------- */
/* % smtp_reset() */
/* -------------- */

static EXAWORD Dll_smtp_reset()
{
	dll_trace("enter Dll_smtp_reset");
	dll_trace("leave Dll_smtp_reset");
	return(0);
}

/* ------------------- */
/* % smtp_disconnect() */
/* ------------------- */

static EXAWORD Dll_smtp_disconnect()
{
	dll_trace("enter Dll_smtp_disconnect");
	dll_trace("leave Dll_smtp_disconnect");
	return(0);
}

/* -------------------------- */
/* % smtp_connect($, %, $, %) */
/* -------------------------- */

static EXAWORD Dll_smtp_connect(char * server,int servlen,char * sender,int sendlen)
{
	dll_trace("enter Dll_smtp_connect");
	dll_trace("leave Dll_smtp_connect");
	return(0);
}

/* -------------------------------------------- */
/* % smtp_send(#, $, %, $, %, $, %, $, %, $, %) */
/* -------------------------------------------- */
/* Err=smtp_send(Type,FicMime,LEN$(FicMime),Destinataire,LEN$(Destinataire),Cc,LEN$(Cc),Id_Notif,LEN$(Id_Notif),Type_Notif,LEN$(Type_Notif)) */

static EXAWORD Dll_smtp_send(int type,char * mimefile,int filelen,char * toptr,int tolen,char * cc,int cclen,char * nptr,int nlen,char * tnptr,int tnlen)
{
	struct	mime_message * mptr;
	char buffer[2048];
	char *	sptr;
	dll_trace("enter Dll_smtp_send");
	// retrieve the message 
	if (!( mptr = retrieve_mime_message( mimefile, filelen ) ))
		return( dll_failure( "Dll_smtp_send", 40 ) );
	else
	{
		// generate the send mail command
		sprintf(buffer,"sendmail -t < %s", mptr->name );
		dll_trace(buffer);
		// release this message
		if (!( mptr->previous ))
			MimeHead = mptr->next;
		else 	mptr->previous->next = mptr->next;
		if (!( mptr->next ))
			MimeFoot = mptr->previous;
		else	mptr->next->previous = mptr->previous;
		mptr = liberate_mime_message( mptr );
		dll_trace("leave Dll_smtp_send");
		// send the mail
		if ( system( buffer ) < 0 )
			return( dll_failure("Dll_smtp_send_system",errno) );
		else	return( 0 );
		return( 0 );
	}
}

/* --------------------------------------------------- */
/* % smtp_connect_with_auth($, %, $, %, $, %, $, %, %) */
/* --------------------------------------------------- */

static EXAWORD Dll_smtp_connect_with_auth(
	char * server,	int servlen,
	char * sender,	int sendlen,
	char * username,int userlen,
	char * password,int passlen,
	int authtype)
{
	dll_trace("enter Dll_smtp_connect_with_auth");
	dll_trace("leave Dll_smtp_connect_with_auth");
	return(0);
}

/*	-------------------	*/
/*	  DNS  FUNCTIONS	*/
/*	-------------------	*/

/* ---------------------- */
/* % dns_request($, %, $) */
/* ---------------------- */

static EXAWORD Dll_dns_request(char * a1,int a2,char * a3)
{
	dll_trace("enter Dll_dns_request");
	dll_trace("leave Dll_dns_request");
	return(0);
}

/*	-------------------	*/
/*	  MIME FUNCTIONS	*/
/*	-------------------	*/

/*	---------------------	*/
/*	liberate_mime_element	*/
/*	---------------------	*/
static	struct	mime_element * liberate_mime_element(struct  mime_element * eptr)
{
	if ( eptr )
	{

		if ( eptr->filename )
			eptr->filename = liberate( eptr->filename );

		if ( eptr->parameter)
			eptr->parameter= liberate( eptr->parameter);

		eptr = liberate( eptr );
	}

	return((struct mime_element *) 0);
}

/*	---------------------	*/
/*	liberate_mime_message	*/
/*	---------------------	*/
static	struct	mime_message * liberate_mime_message(struct  mime_message * mptr)
{
	struct	mime_element * eptr;

	if ( mptr )
	{
		if ( mptr->name )
			mptr->name = liberate( mptr->name );
		if ( mptr->from )
			mptr->from = liberate( mptr->from );
		if ( mptr->body )
			mptr->body = liberate( mptr->body );
		if ( mptr->subject)
			mptr->subject = liberate( mptr->subject );
		if ( mptr->to )
			mptr->to = liberate( mptr->to );
		if ( mptr->boundary )
			mptr->boundary = liberate( mptr->boundary );
		if ( mptr->parameter)
			mptr->parameter= liberate( mptr->parameter);

		while ((eptr = mptr->first) != (struct mime_element *) 0)
		{
			mptr->first = eptr->next;
			eptr = liberate_mime_element( eptr );
		}

		mptr = liberate( mptr );
	}
	return((struct mime_message *) 0);
}

/*	---------------------	*/
/*	retrieve_mime_message	*/
/*	---------------------	*/
static	struct	mime_message * retrieve_mime_message(char * nptr, int nlen)
{
	struct	mime_message * mptr;
	for (	mptr = MimeHead;
		mptr != (struct mime_message *) 0;
		mptr = mptr->next )
	{
		if (!( mptr->name ))
			continue;
		else if (!( strncmp( mptr->name, nptr, nlen ) ))
			break;
	}
	return(mptr);
}

/*	-----------	*/
/*	string_hash	*/
/*	-----------	*/
static	int	string_hash(char * sptr)
{
	int	length;
	int	c;
	if (!( sptr ))
		return(0);
	else	length = strlen(sptr);
	while ((c = *(sptr++)) != 0) 
	{
		length *= c;
		length += c;
	}
	return( length );
}

/*	-----------------	*/
/*	allocate_boundary	*/
/*	-----------------	*/
static	char *	allocate_boundary( struct  mime_message * mptr )
{
	char	boundary[1024];
	char *	sptr;	
	sprintf(boundary,"%8lx-%4x-%4x-%4x-%4x-%8x",
			time((unsigned long *) 0),	
			string_hash(mptr->name),
			string_hash(mptr->from),
			string_hash(mptr->to),
			string_hash(mptr->subject),
			string_hash(mptr->body));
	if (!( sptr = allocate( strlen( boundary ) + 1 ) ))
		return( sptr );
	else	return( strcpy( sptr, boundary ) );
}
	
/*	---------------------	*/
/*	allocate_mime_element	*/
/*	---------------------	*/
static	struct	mime_element * allocate_mime_element()
{
	struct	mime_element * eptr;
	if (!( eptr = (struct mime_element *) allocate( sizeof( struct mime_element ) ) ))
		return( eptr );
	else	return( eptr );
}

/*	---------------------	*/
/*	allocate_mime_message	*/
/*	---------------------	*/
static	struct	mime_message * allocate_mime_message()
{
	struct	mime_message * mptr;
	if (!( mptr = (struct mime_message *) allocate( sizeof( struct mime_message ) ) ))
		return( mptr );
	else	return( mptr );
}

/*	--------------------	*/
/*	allocate_mime_string	*/
/*	--------------------	*/
static	char *	allocate_mime_string( char * vptr, int length )
{
	char *	sptr;
	if (!( sptr = allocate( length + 1) ))
		return( sptr );
	else 	return( strncpy( sptr, vptr, length ) );
}

/*	------------------------	*/
/*	generate_base64_encoding	*/
/*	------------------------	*/
static	int	generate_base64_encoding( FILE * hh, struct mime_element * eptr )
{
	unsigned char * ibuffer;
	unsigned char * obuffer;
	struct stat 	statbuf;
	FILE * h;
	int	i;

	dll_trace("enter generate_base64_encoding");
       	if ( stat(eptr->filename, &statbuf) < 0 )
		return( dll_failure( "base65_encoding_stat", errno ) );
	else if (!( statbuf.st_size ))
	{
		return( dll_failure( "base65_encoding_empty", 40 ) );
	}
	else if (!( ibuffer = allocate( statbuf.st_size ) ))
		return( dll_failure( "base65_encoding_allocate", 27 ) );
	else if (!( obuffer = allocate( statbuf.st_size * 4 ) ))
	{
		ibuffer = liberate( ibuffer );
		return( dll_failure( "base65_encoding_allocate", 27 ) );
	}
	else if (!( h = fopen( eptr->filename, "r" ) ))
	{
		ibuffer = liberate( ibuffer );
		obuffer = liberate( obuffer );
		return( dll_failure( "base65_encoding_open", 40 ) );
	}
	else if ( fread( ibuffer, statbuf.st_size, 1, h) != 1)
	{
		fclose(h);
		ibuffer = liberate( ibuffer );
		obuffer = liberate( obuffer );
		return( dll_failure( "base65_encoding_read", errno ) );
	}
	else if (!( BdamailEncodeBase64( obuffer, ibuffer, statbuf.st_size ) ))
	{
		fclose(h);
		ibuffer = liberate( ibuffer );
		obuffer = liberate( obuffer );
		return( dll_failure( "base65_encoding_encode", 30) );
	}
	else
	{
		fclose(h);
		ibuffer = liberate( ibuffer );
		fprintf(hh,"Content-Transfer-encoding: base64\r\n");
		fprintf(hh,"\r\n");
		for (	i=0;
			obuffer[i] != 0;
			i++)
		{
			if (( i > 0 ) && (!( i % 64 )))
				fprintf(hh,"\r\n");
			fprintf(hh,"%c",obuffer[i]);
		}
		if ( i % 64 ) fprintf(hh,"\r\n");
		obuffer = liberate( obuffer );

		dll_trace("leave generate_base64_encoding");
		return(0);
	}
}

/*	------------------------	*/
/*	generate_mime_text_plain	*/
/*	------------------------	*/
static	int	generate_mime_text_plain(FILE * h)
{
#ifdef	_MIME_UTF8
	fprintf(h,"Content-Type: text/plain; charset=%s\r\n",_MIME_UTF8);
#else
	fprintf(h,"Content-Type: text/plain\r\n");
#endif
	return(0);
}

/*	------------------	*/
/*	generate_mime_body	*/
/*	------------------	*/
static	int	generate_mime_body(FILE * h, unsigned char * sptr)
{
#ifdef	_MIME_UTF8
	unsigned int c;
	unsigned char buffer[16];
	unsigned int length;
	FILE *	hh;
	if (!( hh = fopen( sptr, "r") ))
	{
		// place the string in the message
		while ((c = *(sptr++)) != 0)
		{
			if (!(length = abal_to_unicode(buffer, c) ))
				break;
			else if ( fwrite( buffer, length, 1, h ) != 1 )
				break;
		}
	}
	else
	{
		// place the file contents in the message
		while (((c = fgetc(hh)) != -1) && ( c != 0 ))
		{
			if (!(length = abal_to_unicode(buffer, c) ))
				break;
			else if ( fwrite( buffer, length, 1, h ) != 1 )
				break;
		}
		fclose(hh);
	}
#else
	fprintf(h,"%s",mptr->body);
#endif
	fprintf(h,"\r\n");
	return(0);
}

/*	------------------	*/
/*	generate_mime_file	*/
/*	------------------	*/
static	int	generate_mime_file( struct mime_message * mptr )
{
	FILE *	h;
	char *	output=(char *) 0;
	int	olen;
	char	filename[2048];
	char *	sptr;
	struct	mime_element * eptr;
	
	dll_trace("enter generate_mime_file");

	if (!( mptr->name ))
		return( dll_failure( "generate_mime_file" , 30 ) );
	else	dll_trace( mptr->name );

	if (!( h = fopen( mptr->name, "w") ))
		return( dll_failure( "generate_mime_file" , 46 ) );
	else
	{
		fprintf(h,"MIME-Version: %s\r\n","1.0");
		fprintf(h,"To: %s\r\n",mptr->to);
		fprintf(h,"From: %s\r\n",mptr->from);
		fprintf(h,"Subject: %s\r\n",mptr->subject);

		if (!( mptr->boundary ))
		{
			generate_mime_text_plain(h);
			fprintf(h,"\r\n");
			generate_mime_body(h,mptr->body);
		}
		else
		{
			// establish the multipart header
			fprintf(h,"Content-Type: multipart/mixed; boundary=\"%s\"\r\n",mptr->boundary);
			fprintf(h,"\r\n");

			// generate the pseudo message for old clients
			fprintf(h,"%s\r\n","This is a Multipart Message");
			fprintf(h,"--%s\r\n",mptr->boundary);

			// generate the message body part
			generate_mime_text_plain(h);
			fprintf(h,"Content-Disposition: inline\r\n");
			fprintf(h,"\r\n");
			generate_mime_body(h,mptr->body);

			// process the attachements
			for (	eptr = mptr->first;
				eptr != (struct mime_element *) 0;
				eptr = eptr->next )
			{
				// extract the filename of the object
				if (!( sptr = strrchr(eptr->filename,'/') ))
					sptr = eptr->filename;
				else	sptr++;
				// generate the boundary header
				fprintf(h,"--%s\r\n",mptr->boundary);
				fprintf(h,"Content-Disposition: attachment; filename=\"%s\"\r\n",sptr);
				fprintf(h,"Content-Type: application/octet-stream\r\n");

				// generate the base 64 content
				generate_base64_encoding(h,eptr);
			}
			// final boundary marker
			fprintf(h,"\r\n");
			fprintf(h,"--%s--\r\n",mptr->boundary);
		}

		fclose(h);
		dll_trace("leave generate_mime_file");
		return(0);
	}
}

/* -------------------------------------------------------------- */
/* % mime_code($, %, $, %, $, %, $, %, $, %, $, %, $, %, #, $, %) */
/* -------------------------------------------------------------- */

static EXAWORD Dll_mime_code(
	char * sender,	 int sendlen,
	char * receiver, int recvlen,
	char * cc,	 int cclen,
	char * subject,	 int subjlen,
	char * parameter,int paralen,
	char * content,	 int ctlen,
	char * body,	 int bodylen,
	int 		 filetype,
	char * result,	 int reslen)
{
	struct mime_message * mptr;
	// allocate the message with provided parameters
	dll_trace("enter Dll_mime_code");
	if (!( mptr = allocate_mime_message()))
		return( dll_failure( "mime_code", 27 ) );
	else if (!( mptr->name = allocate_mime_string( result, reslen ) ))
	{
		mptr = liberate_mime_message( mptr );
		return( dll_failure( "mime_code_name", 27 ) );
	}
	else if (!( mptr->from = allocate_mime_string( sender, sendlen ) ))
	{
		mptr = liberate_mime_message( mptr );
		return( dll_failure( "mime_code_from", 27 ) );
	}
	else if (!( mptr->to   = allocate_mime_string( receiver, recvlen ) ))
	{
		mptr = liberate_mime_message( mptr );
		return( dll_failure( "mime_code_to", 27 ) );
	}
	else if (!( mptr->cc   = allocate_mime_string( cc, cclen ) ))
	{
		mptr = liberate_mime_message( mptr );
		return( dll_failure( "mime_code_cc", 27 ) );
	}
	else if (!( mptr->subject = allocate_mime_string( subject, subjlen ) ))
	{
		mptr = liberate_mime_message( mptr );
		return( dll_failure( "mime_code_subject", 27 ) );
	}
	else if (!( mptr->body = allocate_mime_string( body, bodylen ) ))
	{
		mptr = liberate_mime_message( mptr );
		return( dll_failure( "mime_code_body", 27 ) );
	}
	else if (!( mptr->parameter = allocate_mime_string(parameter,paralen) ))
	{
		mptr = liberate_mime_message( mptr );
		return( dll_failure( "mime_code_parameter", 27 ) );
	}
	else
	{
		// store the message
		mptr->type = filetype;
		if (!(mptr->previous = MimeFoot))
			MimeHead = mptr;
		else	mptr->previous->next = mptr;
		MimeFoot = mptr;

		// generate the result
		dll_trace("leave Dll_mime_code");
		return( generate_mime_file( mptr ) );
	}
}

/* ------------------------------- */
/* % mime_add($, %, $, %, #, $, %) */
/* ------------------------------- */

static EXAWORD Dll_mime_add(char * result,int reslen,char * object,int objlen,int type, char * parameter,int paralen)
{
	struct	mime_message * mptr;
	struct	mime_element * eptr;
	
	dll_trace("enter Dll_mime_add");
	// retrieve the message
	if (!( mptr = retrieve_mime_message( result, reslen) ))
		return( dll_failure("Dll_mime_add",40));
	// allocate the attachement
	else if (!( eptr = allocate_mime_element()))
		return( dll_failure("Dll_mime_add:allocate",27));
	else if (!( eptr->filename = allocate_mime_string(object,objlen)))
	{
		eptr = liberate_mime_element(eptr);
		return( dll_failure("Dll_mime_add:allocate",27));
	}
	else if (!( eptr->parameter = allocate_mime_string(parameter,paralen) ))
	{
		eptr = liberate_mime_element(eptr);
		return( dll_failure("Dll_mime_add:allocate",27));
	}
	else
	{
		eptr->type = type;

		// check for and create boundary
		if ((!( mptr->boundary ))
		&&  (!( mptr->boundary = allocate_boundary( mptr ) )))
		{
			eptr = liberate_mime_element(eptr);
			return( dll_failure("Dll_mime_add:allocate",27));
		}
		// add this attachement	
		if (!( eptr->previous = mptr->last ))
			mptr->first = eptr;
		else	eptr->previous->next = eptr;
		mptr->last = eptr;
		dll_trace("leave Dll_mime_add");
		// generate the state of the file
		return( generate_mime_file( mptr ) );
	}
}

/* ------------------------- */
/* % mime_remove($, %, $, %) */
/* ------------------------- */

static EXAWORD Dll_mime_remove(char * a1,int a2,char * a3,int a4)
{
	dll_trace("enter Dll_mime_remove");
	dll_trace("leave Dll_mime_remove");
	return(0);
}

/* --------------------------------------------------------------------------- */
/* % mime_decode($, %, $, %, $, %?, $, %?, $, %?, $, %?, $, %?, $, %?, %?, %?) */
/* --------------------------------------------------------------------------- */

static EXAWORD Dll_mime_decode(char * a1,int a2,char * a3,int a4,char * a5,int * a6,char * a7,int * a8,char * a9,int * a10,char * a11,int * a12,char * a13,int * a14,char * a15,int * a16,int * a17,int * a18)
{
	dll_trace("enter Dll_mime_decode");
	dll_trace("leave Dll_mime_decode");
	return(0);
}

/* ------------------------------------------------------------- */
/* % mime_attachment_info($, %, %, %?, %?, %?, %?, $, %?, $, %?) */
/* ------------------------------------------------------------- */

static EXAWORD Dll_mime_attachment_info(char * a1,int a2,int a3,int * a4,int * a5,int * a6,int * a7,char * a8,int * a9,char * a10,int * a11)
{
	dll_trace("enter Dll_mime_attachment_info");
	dll_trace("leave Dll_mime_attachment_info");
	return(0);
}

/* --------------------------------- */
/* % mime_extract($, %, %, $, %, %?) */
/* --------------------------------- */

static EXAWORD Dll_mime_extract(char * a1,int a2,int a3,char * a4,int a5,int * a6)
{
	dll_trace("enter Dll_mime_extract");
	dll_trace("leave Dll_mime_extract");
	return(0);
}

/* ---------------------------------- */
/* % mime_field($, %, $, %, %, $, %?) */
/* ---------------------------------- */

static EXAWORD Dll_mime_field(char * a1,int a2,char * a3,int a4,int a5,char * a6,int * a7)
{
	dll_trace("enter Dll_mime_field");
	dll_trace("leave Dll_mime_field");
	return(0);
}

/*	-------------------	*/
/*	  POP3 FUNCTIONS	*/
/*	-------------------	*/

/* % pop3_connect($, %, $, %, $, %) */
static EXAWORD Dll_pop3_connect(char * a1,int a2,char * a3,int a4,char * a5,int a6)
{
	return(0);
}

/* % pop3_box_status(%, %?, %?) */
static EXAWORD Dll_pop3_box_status(int a1,int * a2,int * a3)
{
	return(0);
}

/* % pop3_get_msg_buf(%, $, %?, %) */
static EXAWORD Dll_pop3_get_msg_buf(int a1,char * a2,int * a3,int a4)
{
	return(0);
}

/* % pop3_get_msg(%, $, %, %) */
static EXAWORD Dll_pop3_get_msg(int a1,char * a2,int a3,int a4)
{
	return(0);
}

/* % pop3_top_msg(%, $, %, %) */
static EXAWORD Dll_pop3_top_msg(int a1,char * a2,int a3,int a4)
{
	return(0);
}

/* % pop3_delete_msg(%) */
static EXAWORD Dll_pop3_delete_msg(int a1)
{
	return(0);
}

/* % pop3_reset() */
static EXAWORD Dll_pop3_reset()
{
	return(0);
}

/* % pop3_disconnect() */
static EXAWORD Dll_pop3_disconnect()
{
	return(0);
}

/*	----------	*/
/*	InitRelais	*/
/*	----------	*/

VOID FAR PTR InitRelais()
{
	if (rt_init != (VOID FAR PTR) 0L)
	rt_init->ordinaire.signature = BDA_REDIRECT;
	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;
	desrt.fonction[0] = (EXAWORD (FAR PTR)()) Dll_mail_debug;
	desrt.fonction[1] = (EXAWORD (FAR PTR)()) Dll_smtp_connect;
	desrt.fonction[2] = (EXAWORD (FAR PTR)()) Dll_smtp_send;
	desrt.fonction[3] = (EXAWORD (FAR PTR)()) Dll_smtp_disconnect;
	desrt.fonction[4] = (EXAWORD (FAR PTR)()) Dll_smtp_reset;
	desrt.fonction[5] = (EXAWORD (FAR PTR)()) Dll_dns_request;
	desrt.fonction[6] = (EXAWORD (FAR PTR)()) Dll_mime_code;
	desrt.fonction[7] = (EXAWORD (FAR PTR)()) Dll_mime_add;
	desrt.fonction[8] = (EXAWORD (FAR PTR)()) Dll_mime_remove;
	desrt.fonction[9] = (EXAWORD (FAR PTR)()) Dll_pop3_connect;
	desrt.fonction[10] = (EXAWORD (FAR PTR)()) Dll_pop3_box_status;
	desrt.fonction[11] = (EXAWORD (FAR PTR)()) Dll_pop3_get_msg_buf;
	desrt.fonction[12] = (EXAWORD (FAR PTR)()) Dll_pop3_get_msg;
	desrt.fonction[13] = (EXAWORD (FAR PTR)()) Dll_pop3_top_msg;
	desrt.fonction[14] = (EXAWORD (FAR PTR)()) Dll_pop3_delete_msg;
	desrt.fonction[15] = (EXAWORD (FAR PTR)()) Dll_pop3_reset;
	desrt.fonction[16] = (EXAWORD (FAR PTR)()) Dll_pop3_disconnect;
	desrt.fonction[17] = (EXAWORD (FAR PTR)()) Dll_mime_decode;
	desrt.fonction[18] = (EXAWORD (FAR PTR)()) Dll_mime_attachment_info;
	desrt.fonction[19] = (EXAWORD (FAR PTR)()) Dll_mime_extract;
	desrt.fonction[20] = (EXAWORD (FAR PTR)()) Dll_mime_field;
	desrt.fonction[21] = (EXAWORD (FAR PTR)()) Dll_mail_conf;
	desrt.fonction[22] = (EXAWORD (FAR PTR)()) Dll_smtp_connect_with_auth;
	desrt.nombre = 23;
	return((VOID FAR PTR) &desrt);
}

#endif	/* _abalmail_c */

