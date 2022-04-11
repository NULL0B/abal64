#ifndef	_phpclass_c
#define	_phpclass_c

#include "abalclass.h"

private	int	abal_php_class_instance( FILE * h, char * tptr, int keyword )
{
	int	ispointer=0;
	struct	php_variable * vptr;
	char *	cname;
	if (!( cname = allocate_string( tptr ) ))
		return(0);
	else if (!( tptr = abal_get_token(0) )) {
		liberate( cname );
		return(0);
		}
	else if ( upper_compare( tptr, "POINTER" ) ) {
		ispointer=1;
		if (!( tptr = abal_get_token(0) )) {
			liberate( cname );
			return(0);
			}
		}

	if (!( vptr = allocate_php_variable( tptr ) )) {
		liberate( cname );
		return(0);
		}
	else	{
		vptr->classname = cname;
		if (!( vptr->pointer = ispointer ))
			fprintf(h,"$%s = new %s",vptr->name,vptr->classname);
		else	fprintf(h,"$%s = NULL",vptr->name);
		return(1);
		}
}

private	int	abal_php_clf6( FILE * h, char * tptr )
{
	struct	php_variable * vptr;
	char	keyword[64];
	strcpy( keyword, tptr );

	if (!( tptr = abal_get_token(0) ))
		return(0);
	else if (!( vptr = locate_php_variable( tptr ) ))
		return(0);
	else if (!( vptr->classname ))
		return(1);
	else if (!( vptr->pointer ))
		return(1);
	else	{
		if ( upper_compare( keyword, "CREATE" ) )
			fprintf(h,"$this->%s = new %s",vptr->name,vptr->classname);
		else if ( upper_compare( keyword, "REMOVE" ) )
			fprintf(h,"$this->%s = NULL",vptr->name);
		else if ( upper_compare( keyword, "FORGET" ) )
			fprintf(h,"$this->%s = NULL",vptr->name);
		else if ( upper_compare( keyword, "ATTACH" ) )
			fprintf(h,"$this->%s = new %s",vptr->name,vptr->classname);
		else if ( upper_compare( keyword, "DETACH" ) )
			fprintf(h,"$this->%s = NULL",vptr->name);
		return(1);
		}

}

private	int	is_abal_class( char * tptr )
{
	int	i;
	for ( i=0; abal_class_name[i] != (char *) 0; i++ )
		if (!( strcmp( abal_class_name[i] , tptr ) ))
			return((i+1));
	return(0);
}

	/* ----------- */
#endif	/* _phpclass_c */
	/* ----------- */

