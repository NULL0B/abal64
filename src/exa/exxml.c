#ifndef	_exxml_c
#define	_exxml_c

#include "exxml.h"
#include "xmlparse.c"

static	char *	xmltoken=(char *) 0;
static	char	xmltext[256];
static	int	xmlignore=1;

struct	xml_atb	*	allocate_xml_atb()
{
	struct xml_atb * aptr;
	if (!( aptr = allocate( sizeof( struct xml_atb ) )))
		return( aptr );
	else	{
		aptr->name=(char *) 0;
		aptr->value=(char *) 0;
		aptr->next=(struct xml_atb *) 0;
		aptr->previous=(struct xml_atb *) 0;
		return( aptr );
		}
}

struct	xml_tag	*	allocate_xml_tag()
{
	struct xml_tag * tptr;
	if (!( tptr = allocate( sizeof( struct xml_tag ) )))
		return( tptr );
	else	{
		tptr->name=(char *) 0;
		tptr->value=(char *) 0;
		tptr->next=(struct xml_tag *) 0;
		tptr->parent=(struct xml_tag *) 0;
		tptr->previous=(struct xml_tag *) 0;
		tptr->first_atb=(struct xml_atb *) 0;
		tptr->last_atb=(struct xml_atb *) 0;
		tptr->first_tag=(struct xml_tag *) 0;
		tptr->last_tag=(struct xml_tag *) 0;
		return( tptr );
		}
}

static	int	abal_xml_open_tag(struct xml_application * xptr,char * nptr)
{
	xmltoken = nptr;
	return(_ABAL_XML_OPENTAG);
}

static	int	abal_xml_atb_name(struct xml_application * xptr,char * nptr)
{
	xmltoken = nptr;
	return(_ABAL_XML_ATBNAME);
}

static	int	abal_xml_atb_value(struct xml_application * xptr,char * nptr)
{
	xmltoken = nptr;
	return(_ABAL_XML_ATBVALUE);
}

static	int	abal_xml_close_tag(struct xml_application * xptr)
{
	return(_ABAL_XML_CLOSETAG);
}

static	int	abal_xml_punctuation_handler(char * mptr, int a )
{
	xmltext[0]=a;
	xmltext[1] = 0;
	return(_ABAL_XML_TAGTEXT);
}

static	int	abal_xml_space_handler(struct xml_application * xptr, int a )
{
	if ( xmlignore )
		return( 0 );
	else	{
		xmltext[0]=a;
		xmltext[1] = 0;
		return(_ABAL_XML_TAGTEXT);
		}
}

static	int	abal_xml_token_handler(char * mptr, char * tptr )
{
	strcpy(xmltext,tptr);
	return(_ABAL_XML_TAGTEXT);
}

static	int	abal_xml_error_handler(char * mptr, int a, int b)
{
	return(48);
}

static struct	xml_relay abal_xml_relays = {
			abal_xml_open_tag,
			abal_xml_atb_name,
			abal_xml_atb_value,
			abal_xml_space_handler,		/* white space  */
			abal_xml_token_handler,		/* token 	*/
			abal_xml_punctuation_handler,	/* punctuation 	*/
			abal_xml_close_tag,
			abal_xml_error_handler
			};

/*	--------------------------------------------------------	*/
/*	A b a l X m l O p e n ( nomfic, perm, handle )			*/
/*	--------------------------------------------------------	*/
EXAWORD	AbalXmlOpen( nomfic, perm, handle )
BPTR		nomfic;
EXAWORD		perm;
VPTR PTR	handle;
{
	if (!( handle ))	
		return(118); 
	else if (!( *handle = xml_open( nomfic, (void *) 0 ) ))
		return( 40);
	else	{
		xml_use_relays( *handle, &abal_xml_relays );
		return( 0 );
		}
}

/*	--------------------------------------------------------	*/
/*	A b a l X m l C f i l e ( nomfic, perm, handle )		*/
/*	--------------------------------------------------------	*/
EXAWORD	AbalXmlCfile( nomfic, perm, handle )
BPTR		nomfic;
EXAWORD		perm;
VPTR PTR	handle;
{
	if (!( handle ))	
		return(118); 
	else if (!( *handle = xml_create( nomfic, (void *) 0 ) ))
		return( 46 );
	else	{
		return( 0 );
		}
}

/*	--------------------------------------------------------	*/
/*	A b a l X m l C l o s e ( handle )				*/
/*	--------------------------------------------------------	*/
EXAWORD	AbalXmlClose( handle )
VPTR	handle;
{
	if ( handle ) {
		xml_close( handle );
		}
	return( 0 );
}

/*	---------------------------------------------------------	*/
/*	A b a l X m l I n f o (  handle, opcode, buffer, length )	*/
/*	---------------------------------------------------------	*/
EXAWORD	AbalXmlInfo( handle, opcode, buffer, length )
VPTR	handle;
EXAWORD	opcode;
BPTR	buffer;
EXAWORD	length;
{
	BPTR	vptr;

	if (!( handle )) { return(118); }

	switch ( (opcode & 0x00FF ) ) {
		case	_XML_PUT_VERSION:
			return( xml_set_version( handle, buffer, length ) );

		case	_XML_VERSION	:
			memset(buffer,' ',length);
			if ((vptr = xml_get_version( handle )) != (BPTR) 0 ) {
				while (( *vptr ) && ( length )) {
					*(buffer++) = *(vptr++);
					length--;
					}
				}
			return( 0 );

		case	_XML_PUT_CHARSET:
			return( xml_set_encoding( handle, buffer, length ) );

		case	_XML_CHARSET	:
			memset(buffer,' ',length);
			if ((vptr = xml_get_encoding( handle )) != (BPTR) 0 ) {
				while (( *vptr ) && ( length )) {
					*(buffer++) = *(vptr++);
					length--;
					}
				}
			return( 0 );

		case	_XML_PUT_STYLE  :
			return( xml_set_style( handle, buffer, length ) );

		case	_XML_STYLE   	:
			memset(buffer,' ',length);
			if ((vptr = xml_get_stylesheet( handle )) != (BPTR) 0 ) {
				while (( *vptr ) && ( length )) {
					*(buffer++) = *(vptr++);
					length--;
					}
				}
			return( 0 );

		default			:
			return( 55 );

		}
}

/*	----------------------------------------------------------	*/
/*	A b a l X m l W r i t e ( handle, opcode, buffer, length )	*/
/*	----------------------------------------------------------	*/
EXAWORD	AbalXmlWrite( handle, opcode, buffer, length )
VPTR	handle;
EXAWORD	opcode;
BPTR	buffer;
EXAWORD	length;
{
	EXAWORD		status;
	EXAWORD		item;
	EXAWORD		buflen;
	if (!( handle )) 
		return(118);
	else if (!( xml_check_mode(handle,1) ))
		return(51); 
	else if ( length < 4 )
		return(124);
	else	{
		if ( opcode == _XML_WRITEALL )
			xmlignore=0;
		else	xmlignore=1;
		xml_write_header( handle );
		item 	= balgetw( buffer ); buffer += 2;
		buflen	= balgetw( buffer ); buffer += 2;
		switch ( item ) {
			case	(_ABAL_XML_OPENTAG  & 0x000F)	:
				return( xml_write_tag(handle,buffer,buflen) );
			case	(_ABAL_XML_ATBNAME  & 0x000F)	:
				return( xml_write_atbname(handle,buffer,buflen) );
			case	(_ABAL_XML_ATBVALUE & 0x000F)	:
				return( xml_write_atbvalue(handle,buffer,buflen) );
			case	(_ABAL_XML_CLOSETAG & 0x000F)	:
				return( xml_write_close(handle,buffer,buflen) );
			case	(_ABAL_XML_TAGTEXT  & 0x000F)	:
				if ((status = xml_write_text(handle,buffer,buflen)) != 0)
					return(status );
				else if (opcode == _XML_WRITEALL )
					return(0);
				else	return(xml_write_text(handle," ",1)); 
			default					:
				return( 56 );
			}
		}
}

/*	----------------------------------------------------------	*/
/*	A b a l X m l P a r s e ( handle, opcode, buffer, length )	*/
/*	----------------------------------------------------------	*/
EXAWORD	AbalXmlParse( handle, opcode, buffer, length )
VPTR	handle;
EXAWORD	opcode;
BPTR	buffer;
EXAWORD	length;
{
	int	retcode;
	int	i;
	BPTR	wptr;

	if (!( handle )) 
		return(118);

	else if (!( xml_check_mode(handle,0) ))
		return(51); 

	if ( opcode == _XML_READALL )
		xmlignore=0;
	else	xmlignore=1;

	switch ((retcode = xml_parse_tokens( handle ))) {

		case	_ABAL_XML_TAGTEXT	:
			retcode &= 0x000F;
			balputw(retcode,buffer);
			buffer += 2;
			wptr = buffer;
			buffer += 2;
			length-=4;
			for (i=0; i < length; i++ ) {
				if (!( *(xmltext+i) ))
					break;
				else	*(buffer+i) = *(xmltext+i);
				}
			balputw(i,wptr);
			if (!( *(xmltext+i)  ))
				retcode = 0;
			else	retcode = 63;
			for ( ; i < length; i++ )
				*(buffer+i) = ' ';
			return(retcode);

		case	_ABAL_XML_OPENTAG	:
		case	_ABAL_XML_ATBNAME	:
		case	_ABAL_XML_ATBVALUE	:
		case	_ABAL_XML_CLOSETAG	:
			retcode &= 0x000F;
			balputw(retcode,buffer);
			buffer += 2;
			wptr = buffer;
			buffer += 2;
			length-=4;
			for (i=0; i < length; i++ ) {
				if (!( *(xmltoken+i) ))
					break;
				else	*(buffer+i) = *(xmltoken+i);
				}
			balputw(i,wptr);
			if (!( *(xmltoken+i)  ))
				retcode = 0;
			else	retcode = 63;
			for ( ; i < length; i++ )
				*(buffer+i) = ' ';
			return(retcode);

		default				:
			return(48);
		}
}

/*	----------------------------------------------------------	*/
/*	A b a l X m l P a r s e ( handle, opcode, buffer, length )	*/
/*	----------------------------------------------------------	*/
static	void	show_tree(struct xml_tag * tptr,int indent)
{
	struct	xml_atb * aptr   =(struct xml_atb *) 0;
	struct	xml_tag * xptr   =(struct xml_tag *) 0;
	int	i;
	
	if (!( tptr )) return;

	printf("\r\n");

	for ( i =0; i < indent; i++ )
		printf("\t");
	
	if ( tptr->name ) {
		printf("<%s",tptr->name);
		for ( aptr=tptr->first_atb; aptr != (struct xml_atb *) 0; aptr = aptr->next ) {
			if ( aptr->name ) {
				printf(" %s",aptr->name);
				if ( aptr->value );
					printf("=%s",aptr->value);
				}
			}
		if (!( tptr->first_tag )) {
			printf("/>");
			return;
			}
		else	printf(">");
		}

	for ( xptr=tptr->first_tag; xptr != (struct xml_tag *) 0; xptr = xptr->next )
		show_tree(xptr,indent+1);
		
	printf("\r\n");
	for ( i =0; i < indent; i++ )
		printf("\t");
	if ( tptr->name ) {
		printf("</%s>",tptr->name);
		}
	return;	
}


#endif	/* _exxml_c */
	/* -------- */




