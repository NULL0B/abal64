
/*	-----------------------------------------------------------------------		*/
/*	Example Stub deriviation of the standard SING/EXA XML parser mechanisms		*/
/*	-----------------------------------------------------------------------		*/

static	int	xml_open_tag(struct xml_application * xptr,char * sptr) 
{ 
	if ( xptr->echo ) printf("<%s>",sptr); 	
	return(0); 
}

static	int	xml_atb_name(struct xml_application * xptr,char * sptr)	
{ 
	if ( xptr->echo ) printf(" %s",sptr);	
	return(0); 
}

static	int	xml_atb_value(struct xml_application * xptr,char * sptr)
{ 
	if ( xptr->echo ) printf("=%s",sptr);
	return(0); 
}

static	int	xml_white_space(struct xml_application * xptr, int c )
{
	if ( xptr->echo ) printf("%c",c);	
	return(0);
}

static	int	xml_data_punctuation(struct xml_application * xptr, int c )
{
	if ( xptr->echo ) printf("%c",c);	
	return(0);
}

static	int	xml_data_token(struct xml_application * xptr, char * tptr)
{
	if ( xptr->echo ) printf("%s",tptr);	
	return(0);
}

static	int	xml_close_tag(struct xml_application * xptr)
{
	if ( xptr->echo ) printf("</end>");
  	return(0); 
}


