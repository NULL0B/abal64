#ifndef	_json_c
#define	_json_c

//      ------------------------------------------
//      Electronic Document Exchange : JSON
//      ------------------------------------------
//
//      Copyright (c) 2021 Amenesik SARL
//
//      Iain James MArshall <ijm@amenesik.com>
//
//      ------------------------------------------

#include "json.h"

#include "dataelement.c"

private	int	echo=0;

/*	------------------------------------------------	*/
/*	  j s o n   p a r s e r   p r o t o t y p e s 		*/
/*	------------------------------------------------	*/
private	int 	json_ungetch( struct json_parser * jptr, int c );
private	int	json_getch( struct json_parser * jptr );
private	int 	json_white( int c );
private	int 	json_remove_white( struct json_parser * jptr );
private	int 	json_punctuation( int c );
private	int 	json_get_punctuation( struct json_parser * jptr );
private	char *	json_get_token( struct json_parser * jptr );
private	struct	data_element * json_get_matrix( struct json_parser * jptr, struct data_element * parent  );
private	struct	data_element * json_get_complex(struct json_parser * jptr, struct data_element * parent  );
private	struct	data_element * json_get_element( struct json_parser * jptr, struct data_element * parent  );


private	int 	json_failure( struct json_parser * jptr, int status, char * message , char * other )
{
	printf("\njson parser json_failure(%u,%s %s) at line %u column %u \n",
		status,message,other,jptr->line,jptr->column);
	return( status );
}

/*	------------------------------------------------	*/
/*		j s o n _ t er m in a t e			*/
/*	------------------------------------------------	*/
private	struct	json_parser * json_terminate(struct json_parser * jptr )
{
	if ( jptr )
	{
		if ( jptr->handle )
			fclose( jptr->handle );
		jptr->ungotc = 0;
		jptr->handle = (FILE *) 0;
		liberate( jptr);
	}
	return((struct json_parser *) 0);
}

/*	------------------------------------------------	*/
/*		j s o n _ i n i t i a l i s e			*/ 
/*	------------------------------------------------	*/
private	struct json_parser * json_initialise(char * filename)
{
	struct	json_parser * jptr;
	if (!( jptr = trallocate( sizeof( struct json_parser ),"json_parser" ) ))
		return( jptr );
	else
	{
		jptr->ungotc = 0;
		jptr->line=0;
		jptr->column=0;
		if (!( jptr->handle = fopen( filename, "r" ) ))
			return( json_terminate( jptr ) );
		else	return( jptr );
	}
}

/*	------------------------------------------------	*/
/*		j s o n _ u n g e t c h				*/
/*	------------------------------------------------	*/
private	int	json_ungetch(struct json_parser * jptr, int c)
{
	return((jptr->ungotc = c));
}

/*	------------------------------------------------	*/
/*		j s o n _ s e t _ e c h o 			*/
/*	------------------------------------------------	*/

public	int	json_set_echo( int v )
{
	int	e=echo;
	echo = v;
	return( e );
}

/*	------------------------------------------------	*/
/*		j s o n _ g e t c h				*/
/*	------------------------------------------------	*/
private	int	json_getch( struct json_parser * jptr )
{
	int	c;
	if ((c = jptr->ungotc) != 0)
		jptr->ungotc=0;
	else if ((c = fgetc(jptr->handle)) == -1)
		c = 0;
	else if ( echo )
		printf("%c",c);
	if ( c == '\n' )
	{
		jptr->line++; jptr->column=0;
	}
	else if (( c != 0 ) && ( c != '\r'))
		jptr->column++;	
	return( c );
}

/*	------------------------------------------------	*/
/*			j s o n _ w h i t e			*/
/*	------------------------------------------------	*/
private	int	json_white(int c)
{
	switch ( c  )
	{
	case	' '	:
	case	'\n'	:
	case	'\r'	:
	case	'\t'	:
	case	0	:
	case	-1	:
		return(1);
	default		:
		return(0);
	}
}

/*	------------------------------------------------	*/
/*		j s o n _ r e m o v e _ w h i t e		*/
/*	------------------------------------------------	*/
private	int	json_remove_white(struct json_parser * jptr)
{
	int	c;
	while (1)
	{
		switch ((c = json_getch(jptr)))
		{
		case	' '	:
		case	'\n'	:
		case	'\r'	:
		case	'\t'	:
			continue;
		case	0	:
		case	-1	:
			return(0);
		default		:
			return(json_ungetch(jptr,c));
		}	
	}
}

/*	------------------------------------------------	*/
/*	    	j s o n _ p u n c t u a t i o n			*/
/*	------------------------------------------------	*/
private	int	json_punctuation( int c )
{
	if ( ( c == '{' ) || ( c == '}' ) 
	||   ( c == '[' ) || ( c == ']' ) 
	||   ( c == ':' ) || ( c == ',' ) )
		return(c);
	else	return(0);
}

/*	------------------------------------------------	*/
/*	    j s o n _ g e t _ p u n c t u a t i o n		*/
/*	------------------------------------------------	*/
private	int	json_get_punctuation( struct json_parser * jptr )
{
	int	c;
	if (!( json_remove_white( jptr ) ))
		return( 0 );
	else if (!( c = json_getch( jptr )))
		return( -1 );
	else if ( json_punctuation( c ) )
		return( c );

	else
	{
		json_ungetch( jptr, c );
		return( 0 );
	}
}


/*	------------------------------------------------	*/
/*		j s o n _ g e t _ t o k e n 			*/
/*	------------------------------------------------	*/
private	char * json_get_token( struct json_parser * jptr )
{
	char		buffer[16001];
	int		i=0;
	int		c;
	int		quoting=0;

	if (!( json_remove_white(jptr) ))
		return((char *) 0);
	
	while (i < 16000)
	{
		if (!( c = json_getch(jptr)))
			break;
		else if ( quoting )
		{
			if ( c != quoting )
			{
				/* handle escape now : but keep */
				if ( c == 0x005C )
				{
					if (!( c = json_getch(jptr)))
						break;
					else if ( c == 'n' )
						c = '\n';
					else if ( c == 't' )
						c = '\t';
					else if ( c == 'r' )
						c = '\r';
				}
				buffer[i++] = c;
			}
			else	quoting = 0;
		}
		else if ( c == '"' )
			quoting = c;
		else if ( c == 0x0027 )
			quoting = c;
		else if ( json_white(c) )
			break;
		else if ( json_punctuation( c ) )
		{
			json_ungetch(jptr,c);
			break;
		}
		else
		{
			/* handle escape now */
			if ( c == 0x005C )
				if (!( c = json_getch(jptr)))
					break;
				
			buffer[i++] = c;
		}
	}
	buffer[i++] = 0;
	return( allocate_string(buffer) );
}

/*	------------------------------------------------	*/
/*		j s o n _ g e t _ v a l u e 
/*	------------------------------------------------	*/
private	struct	data_element * json_get_value( struct json_parser * jptr, struct data_element * dptr )
{
	int	c;
	if (( c = json_get_punctuation( jptr )) == -1)
	{
		json_failure(jptr,33,"expected","punctuation");
		return( drop_data_element( dptr ) );
	}
	else if (c == ']' )
	{
		json_ungetch( jptr, c );
		return( dptr );
	}
	else if (c == '[' )
	{
		if (!( dptr = json_get_matrix( jptr, dptr ) ))
		{
			json_failure(jptr,33,"expected","matrix");
			return( drop_data_element( dptr ) );
		}
		else	return( dptr );
	}
	else if (c == '{' )
	{
		if (!( dptr = json_get_complex( jptr, dptr ) ))
		{
			json_failure(jptr,33,"expected","complex");
			return( drop_data_element( dptr ) );
		}
		else	return( dptr );
	}
	else if (!( dptr->value = json_get_token( jptr )))
	{
		json_failure(jptr,33,"expected","value");
		return( drop_data_element( dptr ) );
	}
	else	return( dptr );

}

/*	------------------------------------------------	*/
/*		j s o n _ g e t _ e l e m e n t			*/
/*	------------------------------------------------	*/
private	struct	data_element * json_get_element( struct json_parser * jptr, struct data_element * parent  )
{
	struct	data_element * dptr=(struct data_element *) 0;
	int	c;
	if (!( dptr = add_data_element( parent )))
	{
		json_failure(jptr,33,"cannot allocate", "element");
		return( dptr );
	}
	else if (!( dptr->name = json_get_token( jptr )))
	{
		json_failure(jptr,33,"expected","naming token");
		return( drop_data_element( dptr ) );
	}
	else if (( c = json_get_punctuation( jptr )) == -1)
	{
		json_failure(jptr,33,"expected","punctuation");
		return( drop_data_element( dptr ) );
	}
	else if ( c == '}' )
	{
		json_ungetch( jptr, c );
		return( dptr );
	}
	else if ( c != ':' )
	{
		json_failure(jptr,33,"incorrect","punctuation");
		return( drop_data_element( dptr ) );
	}
	return( json_get_value( jptr, dptr ) );
}


/*	------------------------------------------------	*/
/*		j s o n _ g e t _ c o m p le x 			*/
/*	------------------------------------------------	*/
private	struct	data_element * json_get_complex( struct json_parser * jptr, struct data_element * parent )
{
	int	c;
	while (1)
	{
		if (!( json_get_element( jptr, parent ) ))
			return( drop_data_element( parent ));
		else if (!( c = json_get_punctuation(jptr)))
			return( drop_data_element( parent ));
		else if ( c == ',' )
			continue;
		else if ( c == '}' )
			return( parent );
		else	return( drop_data_element( parent ));
	}	
}


/*	------------------------------------------------	*/
/*		j s o n _ g e t _ m a t r i x  			*/
/*	------------------------------------------------	*/
private	struct	data_element * json_get_matrix( struct json_parser * jptr, struct data_element * parent )
{
	int	c;
	while (1)
	{
		if (!( parent ))
			return( parent );
		else if (!( add_data_element( parent ) ))
			return( drop_data_element( parent ) );
		else if (!( json_get_value( jptr, parent->last ) ))
			return( drop_data_element( parent ) );
		else if (!( c = json_get_punctuation(jptr)))
			return( drop_data_element( parent ));
		else if ( c == ',' )
			continue;
		else if ( c != ']' )
			return( drop_data_element( parent ));
		else	return( parent );
	}	
}

/*	------------------------------------------------	*/
/*		j s o n _ p a r s e _ f i l e 			*/
/*	------------------------------------------------	*/
public	struct	data_element *	json_parse_file( char * filename )
{
	int	c;
	struct json_parser * jptr=(struct json_parser *) 0;
	struct	data_element * dptr=(struct data_element *) 0;
	struct	data_element * eptr=(struct data_element *) 0;
	if (( dptr = allocate_data_element( dptr )) != (struct data_element *) 0)
	{
		if (!( jptr = json_initialise( filename )))
			dptr = liberate_data_element( dptr );
		else
		{
			if (!(dptr->name = allocate_string( filename)))
				dptr = liberate_data_element( dptr );
			else
			{
				switch ((c = json_get_punctuation(jptr)))
				{

				case	'['	:
					if (!( dptr = json_get_matrix( jptr, dptr ) ))
						json_failure(jptr,33,"incorrect array",filename);
					break;

				case	'{'	:
					if (!( dptr = json_get_complex( jptr, dptr) ))
						json_failure(jptr,33,"incorrect structure",filename);
					break;

				default		:
					dptr = liberate_data_element( dptr );
					json_failure(jptr,33,"incorrect file",filename);
				}
			}
			json_terminate( jptr );
			// remove the dummy parent
			if (( dptr ) && ((eptr = dptr->first) != (struct data_element *) 0))
			{
				eptr->parent = (struct data_element*) 0;
				dptr->first = dptr->last = (struct data_element*) 0;
				dptr = liberate_data_element( dptr );
				dptr = eptr;
			}
		}
	}
	return( dptr );
}

/*	------------------------------------------------	*/
/*	  j s o n _ s e r i a l i s e _ c o m p l e x  		*/
/*	------------------------------------------------	*/
private	int	json_serialise_complex( FILE * h, struct data_element * dptr )
{
	struct	data_element * eptr;
	if ( dptr->name )
		fprintf(h," %c%s%c:",0x0022,dptr->name,0x0022 );

	if ( dptr->value )
		fprintf(h,"%c%s%c",0x0022,dptr->value,0x0022 );
	else
	{

		if ( dptr->first )
		{
			if ( dptr->first->name )
				fprintf(h,"\n{");
			else	fprintf(h,"\n[");
		}
		else	fprintf(h,"\n[");

		for (	eptr=dptr->first;
			eptr != (struct data_element *) 0;
			eptr = eptr->next )
		{
			json_serialise_complex( h, eptr );
			if ( eptr->next )
				fprintf(h,",");
		}

		if ( dptr->first )
		{
			if ( dptr->first->name )
				fprintf(h,"}");
			else	fprintf(h,"]");
		}
		else	fprintf(h,"]");
	}
	return(0);
}

/*	------------------------------------------------	*/
/*		j s o n _ s e r i a l i s e  			*/
/*	------------------------------------------------	*/
public	int	json_serialise( struct data_element * dptr, char * filename )
{
	int	c;
	FILE * h;
	if (!( h = fopen( filename, "w" )))
		return(46);
	else
	{
		fprintf(h,"{");
		json_serialise_complex( h, dptr );
		fprintf(h,"}\n");
		fclose(h);
		return( 0 );
	}
}
	
/*	------------------------------------------------	*/
/*			j s o n _ s h o w  			*/
/*	------------------------------------------------	*/
public 	int	json_show( struct data_element * dptr )
{
	struct	data_element * eptr;
	if (!( dptr ))
		return(0);
	if ( dptr->name )
		printf(" %c%s%c:",0x0022,dptr->name,0x0022 );

	if ( dptr->value )
		printf("%c%s%c",0x0022,dptr->value,0x0022 );
	else
	{

		if ( dptr->first )
		{
			if ( dptr->first->name )
				printf("\n{");
			else	printf("\n[");
		}

		for (	eptr=dptr->first;
			eptr != (struct data_element *) 0;
			eptr = eptr->next )
		{
			json_show( eptr );
			if ( eptr->next )
				printf(",");
		}

		if ( dptr->first )
		{
			if ( dptr->first->name )
				printf("}");
			else	printf("]");
		}
	}
	return(0);
}

/*	------------------------------------------------	*/
/*		    j s o n _ a t r i b u t			*/
/*	------------------------------------------------	*/
/*	rudimentary json atribut value search. will need	*/
/*	to be extended to handle object.member.member 		*/
/*	type expressions and other stuff later.			*/
/*	------------------------------------------------	*/
public	char *			json_atribut( struct data_element * dptr, char * nptr )
{
	char *	vptr;
	struct	data_element * eptr;
	if (!( dptr ))
		return( (char *) 0 );
	else if (!( dptr->name ))
	{
		if (!( vptr = json_atribut( dptr->first, nptr ) ))
			return( json_atribut( dptr->next, nptr ) );
		else	return( vptr );
	}
	else if (!( strcmp( dptr->name, nptr ) ))
	{
		/* ---------------------------- */
		/* returns exact value or first */
		/* element of a matrix but not  */
		/* a complete structure 	*/
		/* ---------------------------- */
		if ( dptr->value )
			return( dptr->value );
		else if (!( dptr->first->name ))
			return( dptr->first->value );
		else	return((char *) 0);
	}
	else 
	{
		/* scan shallow before going deep */
		/* ------------------------------ */
		for (	eptr = dptr->next;
			eptr != (struct data_element *) 0;
			eptr = eptr->next )
			if ( eptr->name )
				if (!( strcmp( eptr->name, nptr ) ))
					return( json_atribut( eptr, nptr ) );

		for (	eptr = dptr->first;
			eptr != (struct data_element *) 0;
			eptr = eptr->next )
			if ((vptr = json_atribut( eptr, nptr )) != (char *) 0)
				return( vptr );
		return((char *) 0);
	}			

}

/*	------------------------------------------------	*/
/*		    j s o n _ e l e m e n t			*/
/*	------------------------------------------------	*/
/*	rudimentary complex json atribut value search. 		*/
/*	------------------------------------------------	*/
public	struct data_element * json_element( struct data_element * dptr, char * nptr )
{
	struct	data_element * eptr;
	struct	data_element * vptr;
	if (!( dptr ))
		return( (struct data_element *) 0 );
	else if (!( dptr->name ))
	{
		if (!( eptr = json_element( dptr->first, nptr ) ))
			return( json_element( dptr->next, nptr ) );
		else	return( eptr );
	}
	else if (!( strcmp( dptr->name, nptr ) ))
		return( dptr );
	else 
	{
		/* scan shallow before going deep */
		/* ------------------------------ */
		for (	eptr = dptr->next;
			eptr != (struct data_element *) 0;
			eptr = eptr->next )
		{
			if (!( eptr->name ))
				continue;
			else if (!( strcmp( eptr->name, nptr ) ))
				return( eptr );
		}

		for (	eptr = dptr->first;
			eptr != (struct data_element *) 0;
			eptr = eptr->next )
			if ((vptr = json_element( eptr, nptr )) != (struct data_element *) 0)
				return( vptr );
		return( (struct data_element *) 0 );
	}			
}

	/* ------- */
#endif	/* _json_c */
	/* ------- */

