#ifndef	_singtag_c
#define	_singtag_c

struct	template_link_item	{
	struct	template_link_item * previous;
	struct	template_link_item * next;
	int		number;
	char	*	target;
	char	*	href;
	char	*	alt;
	char 	*	class;
	char 	*	value;
	};

struct	template_link_manager	{
	struct	template_link_item *	head;
	struct	template_link_item *	foot;
	char			   *	selection;
	char				work[2048];
	} HrefMan = {
	(struct template_link_item *) 0,
	(struct template_link_item *) 0,
	(char *) 0
	};

private	void	template_atb( char * rptr, char * nptr, char * vptr)
{
	sprintf(rptr," %s=%c%s%c",nptr,0x0022,vptr,0x0022);
	return;
}

public	void	tag_selection_result( char * rptr, int rlen, int v )
{
	int	i;
	struct	template_link_item *	lptr;
	memset(rptr,' ',rlen);
	for (	lptr=HrefMan.head;
		lptr != (struct	template_link_item *) 0;
		lptr = lptr->next )
		if ( lptr->number == v )
			break;
	if (!( lptr ))
		return;
	else	{
		strcpy(HrefMan.work,"<a");
		if ( lptr->target ) {
			template_atb(HrefMan.work + strlen(HrefMan.work),"target",lptr->target );
			}
		if ( lptr->class ) {
			template_atb(HrefMan.work + strlen(HrefMan.work),"class",lptr->class );
			}
		if ( lptr->alt ) {
			template_atb(HrefMan.work + strlen(HrefMan.work),"alt",lptr->alt );
			}
		if ( lptr->href ) {
			template_atb(HrefMan.work + strlen(HrefMan.work),"href",lptr->href );
			}
		strcat(HrefMan.work,">");
		if ( lptr->value )
			strcat(HrefMan.work,lptr->value);
		else	strcat(HrefMan.work,"&nbsp;");
		strcat(HrefMan.work,"</a>");
		for (i=0; i < rlen; i++ ) {
			*(rptr+i) = HrefMan.work[i];
			}
		return;
		}

}

public	void	get_template_tag( int v, char * hptr, int hlen, char * vptr, int vlen )
{
	int	i;
	struct	template_link_item *	lptr;
	memset(hptr,' ',hlen);
	memset(vptr,' ',vlen);
	for (	lptr=HrefMan.head;
		lptr != (struct	template_link_item *) 0;
		lptr = lptr->next )
		if ( lptr->number == v )
			break;
	if ( lptr ) {
		if ( lptr->href ) {
			memcpy( hptr, lptr->href,( hlen < strlen(lptr->href) ? hlen : strlen( lptr->href )));
			}
		if ( lptr->value ) {
			memcpy( vptr, lptr->value,( vlen < strlen(lptr->value) ? vlen : strlen( lptr->value )));
			}
		}
	return;
}

public	char * get_tag_selection_value( int v )
{
	int	i;
	struct	template_link_item *	lptr;
	for (	lptr=HrefMan.head;
		lptr != (struct	template_link_item *) 0;
		lptr = lptr->next )
		if ( lptr->number == v )
			return( lptr->value );
	return((char *) 0);
}

public	char *	tag_selection_list( int tagtype )
{
	struct	template_link_item *	lptr;
	char	*	rptr=(char *) 0;
	char 	*	wptr=(char *) 0;
	if (!( HrefMan.selection )) {
		for (	lptr=HrefMan.head;
			lptr != (struct	template_link_item *) 0;
			lptr = lptr->next ) {
			if ( rptr ) {
				if (!( wptr = allocate( strlen(rptr) + strlen( lptr->value ) + 4) ))
					break;
				else	{
					sprintf(wptr,"%s|%s",rptr,lptr->value);
					liberate( rptr );
					rptr = wptr;
					}
				}
			else if (!( rptr = allocate_string( lptr->value )))
				break;
			}
		if (!( HrefMan.selection = rptr ))
			return( "empty" );
		}
	return( HrefMan.selection );
}

#endif	/* _singtag_c */
	/* ---------- */


