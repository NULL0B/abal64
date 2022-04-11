#ifndef	_vstylist_c
#define	_vstylist_c

public	char *	selection_item( int item, char * sptr )
{
	char *	rptr;
	char *	dptr;
	int	i=0;
	int	c=0;
	if (!( dptr =sptr )) return( sptr );
	while (1) {
		while ( *sptr == ' ' ) { sptr++; }
		while ( *sptr != 0 ) {
			if ( *sptr == '|' )
				break;
			else	sptr++;
			}
		if (!( *sptr ))	break;
		if ( i < item) {
			i++;
			sptr++;
			dptr = sptr;
			}
		else	break;
		}
	if ( i != item )
		return((char *) 0);
	else	{
		while ( *dptr == ' ' ) { dptr++; }
		if (!( *dptr )) return((char *) 0);
		c = *sptr;
		*sptr = 0;
		rptr = allocate_string( dptr );
		*sptr = c;
		return( rptr );
		}
}

public int	visual_styled_element(
		int x,int y, int w, int h, char * cptr, 
		char * sptr, int slen );
#include "vstyle.c"
public int	visual_styled_element(
		int x,int y, int w, int h, char * cptr, 
		char * sptr, int slen )
{
	int	items=0;
	int	item=0;
	char *  vptr;
	if (!( cptr )) 
		return(118);
	else if (!( *cptr ))
		return(118);
	else if (!( cptr = allocate_string(cptr )))
		return(27);

	/* printf("visual_styled_element(%s)\r\n",cptr); */

	while ((vptr = selection_item(item++,cptr )) != (char *) 0) {
		items++;
		if ( visual_element(x,y,w,h,vptr,sptr,slen) != 0 ) {
			liberate( cptr );
			liberate( vptr );
			return(78);
			}
		liberate( vptr );
		}
	liberate( cptr );
	if (!( items ))
		return(118);
	else	return(0);
}

#endif	/* _vstylist_c */
	/* ----------- */

