#ifndef	_qinxs_c
#define	_qinxs_c

#include "inxsql.h"
#include "libinxsql.h"

private	int	mode=0;

private	void	set_mode(int v) { mode = v; return; }

private	char *	remove_white( char * sptr )
{
	while ( *sptr )
	{
		switch ( *sptr )
		{
		case	0	:
		case	'\n':
		case	'\r':
			return((char *) 0);
		case	' '	:
		case	'\t':
			sptr++;
			continue;
		default		:
			return( sptr );
		}
	}
	return( sptr );
}

private	char * consume_token( char * buffer , char * token)
{
	int	c;
	int	i=0;

	if (!( buffer = remove_white( buffer ) )) return( buffer );	

	while (1)
	{
		switch ((c = *buffer))
		{
		case	0	:
		case	'\r':
		case	'\n':	
			if (!( i ))
				return((char *) 0);
			else 
			{
				*(token + i) = 0;
				return( buffer );
			}
		case	'\t':
		case	' '	:
			*(token + i) = 0;
			return( buffer );
			break;
		default		:
			*(token + i) = c;
			i++;
			buffer++;
			continue;
		}
		break;
	}
	if (!( buffer = remove_white( buffer ) )) 
		return( buffer );	
	else	return( buffer );
}

private	char * qinx_drop_table( char * sptr )
{
	char 	token[2048];
	if (!( sptr = consume_token( sptr, token )))
		return( sptr );
	else	
	{
		IsamUnlink( token );
		return( sptr );
	}
}

private	char * qinx_wait( char * sptr )
{
	char 	token[2048];
	if (!( sptr = consume_token( sptr, token )))
		return( sptr );
	else	
	{
		sleep( atoi(token) );
		return( sptr );
	}
}

private	char * qinx_close_table( char * sptr )
{
	char 	token[2048];
	void * 	xh;
	if (!( sptr = consume_token( sptr, token )))
		return( sptr );
	else
	{
		return( sptr );
	}

}
private	char * qinx_open_table( char * sptr )
{
	char 	token[2048];
	void * 	xh;
	if (!( sptr = consume_token( sptr, token )))
		return( sptr );
	else
	{
		if (!( mode ))
			xh = IsamOpen( token );
		else	xh = McIsamOpen( token );
		return( sptr );
	}

}

private	char * qinx_rename_table( char * sptr )
{
	char 	oldname[2048];
	char 	newname[256];
	void * 	xh;
	if (!( sptr = consume_token( sptr, oldname)))
		return( sptr );
	else if (!( sptr = consume_token( sptr, newname )))
		return( sptr );
	else
	{
		if (!( mode ))
		{
			xh = IsamOpen( oldname );
			IsamRename( xh, newname );
			xh = IsamClose( xh );
		}
		else
		{
			xh = McIsamOpen( oldname );
			McIsamRename( xh, newname );
			xh = McIsamClose( xh );
		}
		return( sptr );
	}
}

private	char * qinx_create_table( char * sptr )
{
	char 	token[2048];
	char 	klen[256];
	char 	dlen[256];
	int	k=0;
	int	d=0;
	void * 	xh;
	if (!( sptr = consume_token( sptr, token )))
		return( sptr );
	else if (!( sptr = consume_token( sptr, klen)))
		return( sptr );
	else if (!( sptr = consume_token( sptr, dlen)))
		return( sptr );
	else	
	{
		k = atoi(klen);
		d = atoi(dlen);
		if (!( mode ))
			xh = IsamCreate( token, &k, &d, 0, 0, 0, 0, 0 );
		else	xh = McIsamCreate( token, &k, &d, 0, 0, 0, 0, 0 );
		return( sptr );
	}
}

private	int	execute( char * buffer )
{
	char	token[2048];
	printf("INXSQL: %s",buffer);
	while ( *buffer != 0 )
	{
		if (!( buffer = consume_token( buffer, token )))
			return(0);
		else if (!( strcasecmp( token, "VERBOSE" ) ))
			set_verbose(1);
		else if (!( strcasecmp( token, "MC" ) ))
			set_mode(1);
		else if (!( strcasecmp( token, "SI" ) ))
			set_mode(0);
		else if (!( strcasecmp( token, "CREATE" ) ))
			buffer = qinx_create_table( buffer );
		else if (!( strcasecmp( token, "OPEN" ) ))
			buffer = qinx_open_table( buffer );
		else if (!( strcasecmp( token, "WAIT" ) ))
			buffer = qinx_wait( buffer );
		else if (!( strcasecmp( token, "CLOSE" ) ))
			buffer = qinx_close_table( buffer );
		else if (!( strcasecmp( token, "DROP" ) ))
			buffer = qinx_drop_table( buffer );
		else if (!( strcasecmp( token, "RENAME" ) ))
			buffer = qinx_rename_table( buffer );
		else	return(0);
	}
	return(strlen( buffer));
}

private int operation(int argc, char * argv[])
{
	int		status=0;
	char	buffer[1024];
	char	work[8194];
	char * 	lptr;
	char *	filename;
	FILE *	h;
	printf("\n");

	if ((status = IsamBegin( buffer, 0 )) != 0)
	{
		printf("INXSQL: IsamBegin Failure: %u\n",status);
		return( status );
	}
	else	printf("INXSQL: IsamBegin: OK\n");

	if (( filename = argv[1]) != (char *) 0)
	{
		if ((h = fopen( filename, "r" )) != (FILE *) 0)
		{
			printf("INXSQL: Script: %s\n",filename);
			while (( lptr = fgets(work, 8192, h )) != (char *) 0)
				if ((status = execute( work )) != 0)
					break;
			fclose(h);
		}
		else	printf("INXSQL: Error Opening file : %s\n",filename);
	}
	
	if (( status = IsamEnd((void*) buffer)) != 0)
	{
		printf("INXSQL: IsamBegin Failure : %u\n",status);
		return( status );
	}
	else	printf("INXSQL: IsamEnd: OK\n");

	return(0);
}

private int	banner()
{
	printf("\n   INXSQL Test Tool : Version 1.0a");
	printf("\n   Beta Version : 02/05/2021 ");
	printf("\n   Copyright (c) 2014,2021 Amenesik SARL\n");
	return(0);
}

public int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation( argc, argv ) );
}

#endif	/* _qinxs_c */
