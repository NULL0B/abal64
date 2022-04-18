#ifndef	_jsonabal_c
#define	_jsonabal_c

#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <string.h>
#include        "bda.h"
#include        "allocate.h"

#define __JSONABAL_DATE         "18/04/2022"
#define _JSON_DLL_FUNCTION    7

#define	MAXJSON	64
#define MAXFILENAME 1024

#ifndef BDA_REDIRECT
#define BDA_REDIRECT 5
#endif

#define PRIVATE static
#define PUBLIC
#define EXTERN  extern

#ifndef WIN32
static  char    VersionStatus[16]=
{ 'V','E','R','S','I','O','N','_','S','T','A','T','U','S',':','2' };
static  char    LaPaterne[20] = { '*','P','R','L','@','I','N','F','O','*','#',6,'1','1','d','0','0','3',0 };

static  char *  LaPointeur=(char*)0;
static  char    LaVersion[10];

static  char *  Provisoire="\n   Provisoire du %s ";
#endif

BDA     desrt;                          /* library description */
EXTERN BDA_INIT FAR PTR rt_init;        /* library signing */
EXTERN BDA_ARG rt_arg;                  /* arguments description */

        VOID FAR PTR InitRelais(VOID);
PRIVATE VOID FAR banniere(VOID);
EXTERN  VOID rt_error(EXAWORD);

#define	BPTR unsigned char *
#ifndef EXAWORD
#ifdef  VERSION666
#ifdef	ABAL64
#define	EXAWORD unsigned long long 
#define	WORD EXAWORD
#else
#define EXAWORD unsigned long
#endif
#else
#define EXAWORD unsigned short
#endif
#endif

#define	_ABAL_JSON_NULL		0
#define	_ABAL_JSON_NAME		1
#define	_ABAL_JSON_VALUE	2
#define	_ABAL_JSON_OBJECT	3
#define	_ABAL_JSON_ARRAY	4
#define	_ABAL_JSON_CLOSE	5
#define	_ABAL_JSON_ERROR	6

#define	trallocate(a,b) abalallocate(a,b)
#define	trliberate(a,b) aballiberate(a,b)

static	char * allocate_string(char * sptr)
{
	char * rptr;
	if (!( rptr = abalallocate( strlen(sptr)+1,"string") ))
		return( rptr );
	else	return( strcpy( rptr, sptr ) );
}

#include "json.h"
#include "json.c"

struct	json_context
{
	struct	data_element * 	root;
	struct	data_element * 	current;
	struct	data_element * 	ss[8192];
	int			xx[8192];
	FILE *	handle;
	int	sp;		// level of nesting
	char *	filename;	// input or output filename
	int	item;		// 0 : NAME, 1 : VALUE
	char *	sep;		// 
	int	mode;		// 0 : READ, 1 : WRITE
};

static	int		      ready=0;
static	struct	json_context * Heap[MAXJSON];

/*	-----------	*/
/*	check_ready	*/
/*	-----------	*/
static	void	check_ready()
{
	if (!( ready ))
		while ( ready < 15 )
			Heap[ready++] = (struct json_context*) 0;
	return;
}
	
/*	-----------	*/
/*	DllJsonOpen	*/
/*	-----------	*/
static	WORD	DllJsonOpen(BPTR filename, WORD length)
{
	char	buffer[MAXFILENAME+1];
	struct	data_element * dptr;
	struct	json_context * jptr;
	int	h=0;
	check_ready();
	memset(buffer,0,MAXFILENAME+1);
	memcpy(buffer,filename,(length<MAXFILENAME?length:MAXFILENAME));
	if (!( dptr = json_parse_file( buffer ) ))
		return(0);
	else if (!( jptr = allocate( sizeof( struct json_context ) ) ))
	{
		dptr = drop_data_element( dptr );
		return(0);
	}
	else if (!( jptr->filename = allocate_string(buffer) ))
	{
		dptr = drop_data_element( dptr );
		jptr = aballiberate( jptr, "context" );
		return(0);
	}
	else 
	{
		jptr->sep = "";
		jptr->mode = 0;
		jptr->root = jptr->current = dptr;
		if (dptr->name)
			jptr->item = _ABAL_JSON_OBJECT;
		else	jptr->item = _ABAL_JSON_ARRAY;
		jptr->sp   = 0;
		while (( h < MAXJSON) && ( Heap[h] ))
			h++;
		if ( h < MAXJSON)
		{
			Heap[h++] = jptr;
			return(h);
		}
		else
		{
			dptr = drop_data_element( dptr );
			jptr->filename = aballiberate(jptr->filename,"filename");
			jptr = aballiberate( jptr,"context");
			return(0);
		}
	}
}


/*	-------------	*/
/*	DllJsonCreate	*/
/*	-------------	*/
static	WORD	DllJsonCreate(BPTR filename, WORD length)
{
	char	buffer[MAXFILENAME];
	struct	data_element * dptr;
	struct	json_context * jptr;
	int	h=0;
	check_ready();
	memset(buffer,0,MAXFILENAME+1);
	memcpy(buffer,filename,(length<MAXFILENAME?length:MAXFILENAME));
	if (!( jptr = allocate( sizeof( struct json_context ) ) ))
		return(0);
	else if (!( jptr->filename = allocate_string(buffer) ))
	{
		jptr = aballiberate( jptr, "context" );
		return(0);
	}
	else if (!( jptr->handle = fopen( jptr->filename, "w" ) ))
	{
		jptr->filename = aballiberate( jptr->filename,"filename" );
		jptr = aballiberate( jptr, "context" );
		return(0);
	}
	else
	{
		jptr->sep = "";
		jptr->mode = 1;
		jptr->item = 0;
		jptr->sp   = 0;
		while (( h < MAXJSON) && ( Heap[h] ))
			h++;
		if ( h < MAXJSON)
		{
			Heap[h++] = jptr;
			return(h);
		}
		else
		{
			dptr = drop_data_element( dptr );
			jptr->filename = aballiberate(jptr->filename,"filename");
			jptr = aballiberate( jptr,"context");
			return(_ABAL_JSON_NULL);
		}
	}
}

/*	------------	*/
/*	DllJsonClose	*/
/*	------------	*/
static	WORD	DllJsonClose(WORD handle)
{
	struct	json_context * jptr;
	if ((!( handle )) || ( handle > MAXJSON))
		return(_ABAL_JSON_NULL);
	else if (!( jptr = Heap[--handle] ))
		return(_ABAL_JSON_NULL);
	else
	{
		if (!( jptr->mode ))
			jptr->root = drop_data_element( jptr->root );
		else	fclose(jptr->handle);
		jptr->handle = (FILE*) 0;
		jptr->filename = aballiberate(jptr->filename,"filename");
		jptr = aballiberate( jptr,"context" );
		Heap[handle] = jptr;
		return(0);
	}	
}

/*	----------------	*/
/*	avro_read_record	*/
/*	----------------	*/
static	WORD	avro_read_record( FILE * h, struct data_element * sptr,  struct data_element * jptr )
{
	return( 0 );
}

/*	-----------	*/
/*	avro_reader	*/
/*	-----------	*/
static	WORD	avro_reader( FILE * h, struct data_element * sptr, struct data_element * jptr )
{
	struct	data_element * nptr;
	struct	data_element * tptr;
	struct	data_element * fptr;
	if (!( h ))
		return(0);
	else if (!( sptr ))
		return(0);
	else if (!( jptr ))
		return(0);
	else if (!( tptr = json_element( sptr->first, "type") ))
		return(30);
	else if (!( tptr->value ))
		return(31);
	else if (!( nptr = json_element( sptr->first, "name") ))
		return(32);
	else if (!( nptr->value ))
		return(33);
	else if (!( strcmp( tptr->value, "record" ) ))
		return( avro_read_record( h, json_element( sptr->first, "fields"), jptr ) );
	else	return(50);
}

/*	-----------	*/
/*	DllAvroRead	*/
/*	-----------	*/
static	WORD	DllAvroRead(WORD schema, WORD handle, BPTR avrofile, WORD avronamelen)
{
	struct	json_context * sptr;
	struct	json_context * jptr;
	FILE *	h;
	WORD	status;
	BYTE	nptr[MAXFILENAME+1];

	// check the avro schema handle
	if ((!( schema)) || ( schema> MAXJSON))
		return(_ABAL_JSON_NULL);
	else if (!( sptr = Heap[--schema] ))
		return(_ABAL_JSON_NULL);
	else if ( jptr->mode )
		return(_ABAL_JSON_ERROR );

	// check the json output file handle
	if ((!( handle )) || ( handle > MAXJSON))
		return(_ABAL_JSON_NULL);
	else if (!( jptr = Heap[--handle] ))
		return(_ABAL_JSON_NULL);
	else if (!( jptr->mode ))
		return(_ABAL_JSON_ERROR );

	// prepare the avro filename
	memset(nptr, 0, MAXFILENAME+1);
	memcpy(nptr, avrofile, (avronamelen<MAXFILENAME?avronamelen:MAXFILENAME));

	// open the avro file
	if (!( h = fopen( nptr, "r") ))
		return(_ABAL_JSON_ERROR );
	else
	{
		status = avro_reader(h, sptr->root, jptr->root);
		fclose(h);
		return(status);
	}
}

/*	-----------	*/
/*	DllJsonRead	*/
/*	-----------	*/
static	WORD	DllJsonRead(WORD handle, BPTR dptr, WORD dlen)
{
	struct	json_context * jptr;
	struct	data_element * eptr;
	WORD	elen;
	WORD	i;

	if ((!( handle )) || ( handle > MAXJSON))
		return(_ABAL_JSON_NULL);
	else if (!( jptr = Heap[--handle] ))
		return(_ABAL_JSON_NULL);
	else if ( jptr->mode )
		return(_ABAL_JSON_ERROR );
	else
	{
		// pick up the current or previous element
		while (!( eptr = jptr->current )) 
		{
			if (!( jptr->sp ))
			{
				DllJsonClose((handle+1));
				return(_ABAL_JSON_CLOSE);
			}
			else	
			{
				jptr->current = jptr->ss[--jptr->sp];
				jptr->item = 0;
				return(_ABAL_JSON_CLOSE);
			}
		}

		switch (( i = jptr->item ))
		{
		case	0	:	// name
			if (!( eptr->name ))
			{
				jptr->ss[jptr->sp++] = eptr->next;
				if (!(jptr->current = eptr->first))
					return( _ABAL_JSON_ERROR );
				else
				{
					jptr->item=0;
					if (!( jptr->current->name ))
						return(_ABAL_JSON_ARRAY);
					else	return(_ABAL_JSON_OBJECT);
				}
			}
			else if ((elen = strlen( eptr->name )) > dlen )
				return(_ABAL_JSON_NULL);
			else
			{
				memset(dptr,' ',dlen);
				memcpy(dptr,eptr->name,elen);
				jptr->item++;
				return(_ABAL_JSON_NAME);
			}
		case	1	:	// value
			if (!( eptr->value ))
			{
				jptr->ss[jptr->sp++] = eptr->next;
				if (!(jptr->current = eptr->first))
					return( _ABAL_JSON_ERROR );
				else
				{
					jptr->item=0;
					if (!( jptr->current->name ))
						return(_ABAL_JSON_ARRAY);
					else	return(_ABAL_JSON_OBJECT);
				}
			}
			else if ((elen = strlen( eptr->value )) > dlen )
				return(_ABAL_JSON_NULL);
			else
			{
				memset(dptr,' ',dlen);
				memcpy(dptr,eptr->value,elen);
				jptr->item=0;
				jptr->current = eptr->next;
				return(_ABAL_JSON_VALUE);
			}
		// first time read
		case	_ABAL_JSON_ARRAY	:
		case	_ABAL_JSON_OBJECT	:
			jptr->item = 0;
			return( i );
		}
	}
	return(_ABAL_JSON_NULL);
}

/*	-----------------	*/
/*	avro_write_record	*/
/*	-----------------	*/
static	WORD	avro_write_record( FILE * h, struct data_element * sptr,  struct data_element * jptr )
{
	return( 0 );
}

/*	-----------	*/
/*	avro_writer	*/
/*	-----------	*/
static	WORD	avro_writer( FILE * h, struct data_element * sptr, struct data_element * jptr )
{
	struct	data_element * nptr;
	struct	data_element * tptr;
	struct	data_element * fptr;
	if (!( h ))
		return(0);
	else if (!( sptr ))
		return(0);
	else if (!( jptr ))
		return(0);
	else if (!( tptr = json_element( sptr->first, "type") ))
		return(30);
	else if (!( tptr->value ))
		return(31);
	else if (!( nptr = json_element( sptr->first, "name") ))
		return(32);
	else if (!( nptr->value ))
		return(33);
	else if (!( strcmp( tptr->value, "record" ) ))
		return( avro_write_record( h, json_element( sptr->first, "fields"), jptr ) );
	else	return(50);
}

/*	------------	*/
/*	DllAvroWrite	*/
/*	------------	*/
static	WORD	DllAvroWrite(WORD schema, WORD handle, BPTR avrofile, WORD avronamelen)
{
	struct	json_context * sptr;
	struct	json_context * jptr;
	FILE *	h;
	WORD	status=0;
	BYTE	nptr[MAXFILENAME+1];

	// check the avro schema handle
	if ((!( schema)) || ( schema> MAXJSON))
		return(_ABAL_JSON_NULL);
	else if (!( sptr = Heap[--schema] ))
		return(_ABAL_JSON_NULL);
	else if ( jptr->mode )
		return(_ABAL_JSON_ERROR );

	// check the json output file handle
	if ((!( handle )) || ( handle > MAXJSON))
		return(_ABAL_JSON_NULL);
	else if (!( jptr = Heap[--handle] ))
		return(_ABAL_JSON_NULL);
	else if ( jptr->mode )
		return(_ABAL_JSON_ERROR );

	// prepare the avro filename
	memset(nptr, 0, MAXFILENAME+1);
	memcpy(nptr, avrofile, (avronamelen<MAXFILENAME?avronamelen:MAXFILENAME));

	// open the avro file
	if (!( h = fopen( nptr, "w") ))
		return(_ABAL_JSON_ERROR );
	else
	{
		status = avro_writer(h, sptr->root, jptr->root);
		fclose(h);
		return(status);
	}
}

/*	------------	*/
/*	DllJsonWrite	*/
/*	------------	*/
static	WORD	DllJsonWrite(WORD handle, WORD item, BPTR dptr, WORD dlen)
{
	struct	json_context * jptr;
	if ((!( handle )) || ( handle > MAXJSON))
		return(_ABAL_JSON_NULL);
	else if (!( jptr = Heap[--handle] ))
		return(_ABAL_JSON_NULL);
	else if (!( jptr->mode ))
		return(_ABAL_JSON_ERROR );
	else
	{
		switch ( item )
		{
		case	_ABAL_JSON_NAME	:
			fprintf(jptr->handle,"%s%c",jptr->sep,0x0022);
			while ( dlen-- > 0 ) fprintf(jptr->handle,"%c",*(dptr++));
			fprintf(jptr->handle,"%c",0x0022);
			jptr->item++;
			jptr->sep = "";
			break;

		case	_ABAL_JSON_VALUE	:
			if ( jptr->item ) fprintf(jptr->handle,"%s%c",jptr->sep,':');
			if ( dlen > 0 )
			{
				fprintf(jptr->handle,"%c",0x0022);
				while ( dlen-- > 0 ) fprintf(jptr->handle,"%c",*(dptr++));
				fprintf(jptr->handle,"%c",0x0022);
			}
			jptr->item=0;
			jptr->sep = ",";
			break;
		case	_ABAL_JSON_OBJECT	:
			if ( jptr->item ) 
				fprintf(jptr->handle,"%s%c%c",jptr->sep,':','{');
			else	fprintf(jptr->handle,"%s%c",jptr->sep,'{');
			jptr->sep = "";
			jptr->xx[jptr->sp++] = '}';
			jptr->item=0;
			break;
	
		case	_ABAL_JSON_ARRAY	:
			if ( jptr->item ) fprintf(jptr->handle,"%s%c%c",jptr->sep,':','[');
			else	fprintf(jptr->handle,"%s%c",jptr->sep,'[');
			jptr->sep = "";
			jptr->xx[jptr->sp++] = ']';
			jptr->item=0;
			break;
		case	_ABAL_JSON_CLOSE	:
			if ( jptr->sp > 0 )
			{
				fprintf(jptr->handle,"%c",jptr->xx[--jptr->sp]);
				jptr->sep = ",";
			}
			jptr->item=0;
			break;
		default				:
			return(_ABAL_JSON_ERROR );
		}		
		return(_ABAL_JSON_NULL);
	}
}

/* --------------------	*/
/*	json_terminate	*/
/* --------------------	*/
static  void    json_liberate()
{
	int	i;
	for ( i = 0; i < MAXJSON; i++ )
		if ( Heap[i] )
			DllJsonClose(i+1);
        return;
}

/* -------------------- */
/*	InitRelais	*/
/* -------------------- */
VOID FAR PTR InitRelais()
{
#if defined(UNIX)
        if (rt_init != (VOID FAR PTR) 0L)
                rt_init->ordinaire.signature = BDA_REDIRECT;
#elif defined(WIN32)
        if (rt_init != (VOID FAR PTR) 0L)
                rt_init->ordinaire.signature = BDA_CICO;
#else
        if (rt_init != (VOID FAR PTR) 0L)
                rt_init->ordinaire.signature = BDA_ORDINAIRE;
#endif

        desrt.banniere = (VOID (FAR PTR)()) banniere;
        desrt.fin = (VOID (FAR PTR)()) json_liberate;

        desrt.nombre = _JSON_DLL_FUNCTION;

        desrt.reserve = (VOID FAR PTR) 0L;

        desrt.fonction[0]  = (EXAWORD (FAR PTR)()) DllJsonOpen;
        desrt.fonction[1]  = (EXAWORD (FAR PTR)()) DllJsonCreate;
        desrt.fonction[2]  = (EXAWORD (FAR PTR)()) DllJsonRead;
        desrt.fonction[3]  = (EXAWORD (FAR PTR)()) DllJsonWrite;
        desrt.fonction[4]  = (EXAWORD (FAR PTR)()) DllJsonClose;
        desrt.fonction[5]  = (EXAWORD (FAR PTR)()) DllAvroRead;
        desrt.fonction[6]  = (EXAWORD (FAR PTR)()) DllAvroWrite;
	
        return((VOID FAR PTR) &desrt);

}

#ifndef WIN32
char *  getpatternversion()
{
        if (!( LaPointeur )) {
                LaVersion[0] = LaPaterne[12];
                LaVersion[1] = '.';
                LaVersion[2] = LaPaterne[13];
                LaVersion[3] = LaPaterne[14];
                if ( VersionStatus[15] != '0' ) {
                        LaVersion[4] = '.';
                        LaVersion[5] = LaPaterne[15];
                        LaVersion[6] = '.';
                        LaVersion[7] = LaPaterne[16];
                        LaVersion[8] = LaPaterne[17];
                        LaVersion[9] = 0;
                        }
                else if ( LaPaterne[15] > '0' ) {
                        LaVersion[4] = '.';
                        LaVersion[5] = LaPaterne[15];
                        LaVersion[6] = 0;
                        }
                else    LaVersion[4] = 0;
                LaPointeur = LaVersion;
                }
        return( LaPointeur );

}

void    abaljson_banner()
{
        printf("\n   JSON Parser : Version %s ",getpatternversion());
        if ( VersionStatus[15] == '2' )
                printf(Provisoire,__JSONABAL_DATE);
        printf("\n   Copyright (c) 2021 Amenesik / Sologic \n");
        return;
}
#endif


/* -------------------- */
/* 	banniere	*/
/* -------------------- */
static VOID FAR banniere()
{
#ifndef	WIN32
	abaljson_banner();
#endif
        return;
}

void    _cfltcvt()      {       return;         }
void    _cropzeros()    {       return;         }


#endif	/* _jsonabal_c */

