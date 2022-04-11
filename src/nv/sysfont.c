void * font_drop( void * iptr )
{
	(void) DropFont( iptr );
	return((void *) 0);
}

void * font_loader(char * iname )
{
	void * iptr=(void *) 0;
	(void) LoadFontM( iname, 0, & iptr );
	return(iptr);
}


