unsigned short  fidperm=0;
unsigned char * fidbuff=(unsigned char*) 0;

struct	file_finder_item	{
	int		year;
	int		month;
	int		day;
	int		hour;
	int		minute;
	int		second;
	unsigned long	filesize;
	char	*	name;
	int		options;
	int		number;
	struct file_finder_item * previous;
	struct file_finder_item * next;
	};

struct	file_finder_ctrl	{
	struct file_finder_item * first;
	struct file_finder_item * last;
	struct file_finder_item * current;
	int			options;
	char	*		selection;
	int			slen;
	int			items;
	char			buffer[256];
	} * ffControl=(	struct file_finder_ctrl *) 0;

struct	file_finder_item * ffHeap=(struct file_finder_item *) 0;

static	char * extension[] = {
	".as",".at",".xml",".htm",".css",".jpg",".gif",".png",".bmp",".ico",".fmf",".c",".h",".3d",".sng",".ani",(char *) 0
	};

private	void	drop_file_list(	struct file_finder_ctrl * cptr )
{
	struct	file_finder_item * iptr;

	if (!( cptr )) 
		return;

	while ((iptr = cptr->first) != (struct file_finder_item *) 0) {
		cptr->first = iptr->next;
		if ( iptr->name )
			iptr->name = liberate( iptr->name );
		iptr->next = ffHeap;
		ffHeap = iptr;
		}

	if ( cptr->selection )
		cptr->selection = liberate( cptr->selection );

	cptr->first = cptr->last = cptr->current = (struct file_finder_item *) 0;
	cptr->items = 0;
	return;
}

private	int	comparelower( char * aptr, char * bptr )
{
	while (( *aptr != 0 ) && ( *bptr != 0 )) {
		if ( *aptr < *bptr )
			return(1);
		else if ( *(aptr++) > *(bptr++) )
			return(0);
		}
	if ( *aptr < *bptr )
		return(1);
	else	return(0);
}

private	struct	file_finder_item * allocate_find_heap()
{
	struct	file_finder_item * iptr;
	if ((iptr = ffHeap) != (struct file_finder_item*) 0)
		ffHeap = iptr->next;
	else if (!( iptr = allocate( sizeof ( struct	file_finder_item ) ) ))
		return(iptr);

	iptr->next = iptr->previous = (struct file_finder_item *) 0;
	iptr->name = (char *) 0; 
	iptr->filesize = 0L;
	iptr->year = iptr->month=
	iptr->day  = iptr->hour =
	iptr->minute = iptr->second = 
	iptr->number = iptr->options = 0;
	return(iptr);
}

private	void	add_sorted_entry( 
	struct file_finder_ctrl * cptr,
	struct	file_finder_item * iptr)
{
	struct	file_finder_item * tptr;
	for (	tptr=cptr->first; 
		tptr != (struct file_finder_item *) 0; 
		tptr = tptr->next ) {
		if (comparelower(iptr->name,tptr->name)) {

			/* add before */ 
			/* ---------- */ 
			if (!( iptr->previous = tptr->previous ))
				cptr->first = iptr;
			else	iptr->previous->next = iptr;
			iptr->next = tptr;
			tptr->previous = iptr;
			break;
			}
		}
	if (!( tptr )) {
		/* add after */
		/* --------- */
		if (!( iptr->previous = cptr->last )) {
			cptr->first = cptr->current = iptr;
			}
		else 	cptr->last->next = iptr;
		cptr->last = iptr;
		}
	return;
}

private	char *	allocate_directory_name( char * sptr )
{
	char * rptr;
	if (!( rptr = allocate( strlen( sptr ) + 16 ) ))
		return( rptr );
	else 	{
		sprintf(rptr,"/%s",sptr);
		return( rptr );
		}
}

private	void	collect_file_infos(struct file_finder_item * iptr, char * vptr )
{
	iptr->year     = ((*((unsigned char *) vptr) << 8) | *((unsigned char *) (vptr+1)));
	iptr->month    = *((unsigned char *) (vptr+2));
	iptr->day      = *((unsigned char *) (vptr+3));
	iptr->hour     = *((unsigned char *) (vptr+4));
	iptr->minute   = *((unsigned char *) (vptr+5));
	iptr->second   = *((unsigned char *) (vptr+6));
	iptr->filesize = ((*((unsigned char *) (vptr+7 )) << 24) 
			 |(*((unsigned char *) (vptr+8 )) << 16) 
			 |(*((unsigned char *) (vptr+9 )) <<  8) 
			 | *((unsigned char *) (vptr+10))      );
	return;
}


private	int	build_file_list(char * sptr, int slen, int mode )
{
	int	i;
	int	items=0;
	int	started=0;
	struct file_finder_ctrl * cptr;
	struct	file_finder_item * iptr;
	struct	file_finder_item * tptr;
	char *	vptr;

	if (!(cptr = ffControl )) {
		if (!( ffControl = allocate( sizeof( struct file_finder_ctrl ) ) ))
			return(0);
		else	cptr = ffControl;
		cptr->first = cptr->last = cptr->current = (struct file_finder_item *) 0;
		cptr->selection = (char *) 0;
		cptr->slen  = 0;
		cptr->options = 0;
		}
	else if ( cptr->selection != (char *) 0)
		drop_file_list( cptr );



	if (!( cptr->selection = allocate((cptr->slen = slen)+8 ) ))
		return(0);


	for (	i=0; i < slen; i++ )
		cptr->selection[i] = *(sptr+i);

#ifdef	UNIX
	/* Convert *.* to * for UNIX */
	/* ------------------------- */
	if (( cptr->selection[0] == '*' )
	&&  ( cptr->selection[1] == '.' )
	&&  ( cptr->selection[2] == '*' )) {
		cptr->selection[1] = 
		cptr->selection[2] = ' ';
		}
#endif

	cptr->selection[i] = 0; items = 0;

	if ((started = (mode & 0x0010)) != 0) {

		/* Add list of directories */
		/* ----------------------- */
		while ( dir_seek( cptr->buffer, 255, cptr->selection, cptr->slen,(started | 0x0020) ) != -1 ) {
			started |= 1;
			if (!( iptr = allocate_find_heap() ))
				break;

			collect_file_infos( iptr, cptr->buffer );

			if (!( iptr->name = allocate_directory_name( (cptr->buffer+11) ) )) {
				iptr = liberate( iptr );
				break;
				}
			else	add_sorted_entry(cptr, iptr);
			}
		}

	/* Add list of matching files */
	/* -------------------------- */
	started = 0;

	while ( dir_seek( cptr->buffer, 255, cptr->selection, cptr->slen,( started | 0x0020) ) != -1 ) {
		started = 1;

		if (!( iptr = allocate_find_heap() ))
			break;

		collect_file_infos( iptr, cptr->buffer );

		if (!( iptr->name = allocate_string( (cptr->buffer+11) ) )) {
			iptr = liberate( iptr );
			break;
			}
		else	add_sorted_entry(cptr,iptr);
		}


	/* Count all added items */
	/* --------------------- */
	for (	items=0,
		iptr = cptr->first;
		iptr != (struct file_finder_item*)0;
		iptr = iptr->next )
		iptr->number = cptr->items++;

	if ( cptr )
		cptr->current = cptr->first;
	return(items);
}


int	fnisdirectory(char * nptr, int nlen )
{

	if ( *nptr == '/' )
		return(1);
	else	return(0);
}

void	fnchangedirectory(char * rptr, int rlen, char * sptr, int slen )
{
	int	pl;
	int	rl;
	int	i;

	
	/*detect and avoid non directories */
	/* ------------------------------- */
	if (!( fnisdirectory( sptr, slen ) ))
		return;

	/* detect and avoid current directory */
	/* ---------------------------------- */
	else if (( *sptr == '/' ) && ( *(sptr+1) == '.' ) && ( *(sptr+2) == ' '))
		return;

	/* detect and honour parent directory */
	/* ---------------------------------- */
	else if (( *sptr == '/' ) && ( *(sptr+1) == '.' ) && ( *(sptr+2) == '.') && ( *(sptr+3) == ' ')) {
		/* Calculate position of directory - 1 */
		for (	i=0,pl=0,rl=0; i < rlen; i++ ) {
			if ( *(rptr+i) == '/' ) {
				pl = rl;
				rl = i;
				}
			}	
		if (!( pl ))
			i = 0;
		else if ( *(rptr+pl) == '/' )
			i = (pl+1);
		else	i=0;
		pl = 0;
		}

	/* Add directory component to current path */
	/* --------------------------------------- */
	else if ( *rptr != ' ' ) {
		for (	i=0,pl=0; i < rlen; i++ ) 
			if ( *(rptr+i) != ' ' )
				pl = i;
		for (i=1; i < slen; i++ ) {
			if ( *(sptr+i) == ' ' )
				break;
			else if ( (i+pl) < rlen )
				*(rptr+i+pl) = *(sptr+i);
			else	break;
			}
		}
	else	{
		for (i=0,pl=0; i < slen; i++ ) {
			if ( *(sptr+(i+1)) == ' ' )
				break;
			else if ( i < rlen )
				*(rptr+i) = *(sptr+(i+1));
			else	break;
			}

		}

	if ( i > 0 ) {
		/* Ensure terminated */
		/* ----------------- */
		if ( i < rlen ) {
			*(rptr+i) = '/';
			i++;
			}
		}

	/* Erase to end of string */
	/* ---------------------- */
	for ( ; i+pl < rlen; i++ )
		*(rptr+i+pl)  = ' ';
			
	return;

}


int	fileinformer( char * rptr, int rlen, char * sptr, int slen, int m, int item )
{
	int	i;
	int	items;
	struct file_finder_ctrl * cptr;
	struct	file_finder_item * iptr;
	char	muffer[64];

	if (!( m ))
		build_file_list( sptr, slen, 0x0010 );

	if (!( cptr = ffControl ))
		return(0);

	if ( item ) {
		for ( 	iptr=cptr->first;
			iptr != (struct	file_finder_item *)0;
			iptr = iptr->next )
			if ( iptr->number == item )
				break;
		cptr->current = iptr;	
		}

	if (!( iptr = cptr->current ))
		return(0);
	else if (!( sptr = iptr->name ))
		return(0);
	else	{
		cptr->current = iptr->next;

		for (i=0; i < rlen; i++ )
			*(rptr+i) = ' ';

		for (i=0; i < rlen; i++ ) {
			if ( *(sptr+i) == ' ' )
				break;
			else *(rptr+i) = *(sptr+i);
			}
		rptr += ((rlen/4)+1);
		sprintf(muffer,"    %012.1lu",iptr->filesize);
		for (i=0; muffer[i] != 0; i++ )
			*(rptr+i) = muffer[i];
		rptr += ((rlen/4)+1);
		sprintf(muffer,"    %02.1u:%02.1u:%02.1u",iptr->hour,iptr->minute,iptr->second);
		for (i=0; muffer[i] != 0; i++ )
			*(rptr+i) = muffer[i];
		rptr += ((rlen/4)+1);
		sprintf(muffer,"    %02.1u/%02.1u/%04.1u",iptr->day,iptr->month,iptr->year);
		for (i=0; muffer[i] != 0; i++ )
			*(rptr+i) = muffer[i];
		return(cptr->items);
		}
}

int	filefinder( char * rptr, int rlen, char * sptr, int slen, int m, int item )
{
	int	i;
	int	items;
	struct file_finder_ctrl * cptr;
	struct	file_finder_item * iptr;

	if (!( m ))
		build_file_list( sptr, slen, 0x0010 );

	if (!( cptr = ffControl ))
		return(0);

	if ( item ) {
		for ( 	iptr=cptr->first;
			iptr != (struct	file_finder_item *)0;
			iptr = iptr->next )
			if ( iptr->number == item )
				break;
		cptr->current = iptr;	
		}

	if (!( iptr = cptr->current ))
		return(0);
	else if (!( sptr = iptr->name ))
		return(0);
	else	{
		cptr->current = iptr->next;

		for (i=0; i < rlen; i++ )
			if (!( *(rptr+i) = *(sptr+i) ))
				break;	
		return(cptr->items);
		}
}

int	lenuze(char * sptr, int slen )
{
	int	i,l;
	for (i=0,l=0; i < slen; i++ ) {
		if (!( *(sptr+i) ))
			break;
		else if ( *(sptr+i) != ' ' )
			l = (i+1);
		}
	return(l);
}

public	void	liberate_file_finder()
{
	struct file_finder_ctrl * cptr;
	struct	file_finder_item * iptr;
	if (!(cptr = ffControl )) {
		drop_file_list( cptr );
		ffControl = liberate( ffControl );
		}
	while ((iptr = ffHeap) != (struct file_finder_item *) 0) {
		ffHeap = iptr->next;
		iptr = liberate( iptr );
		}
	return;
}

public	int	detect_file_extension( char * rptr, int rlen, int result )
{
	int	ilen;
	char	tmpbuffer[64];
	int	i;
	for ( ilen=0; ilen < rlen; ilen++ ) {
		if ( *(rptr+ilen) != ' ' )
			continue;
		else	{
			*(rptr+ilen) = 0;
			break;
			}
		}

	if (!( fn_parser( rptr, tmpbuffer, 16 ) ))
		result = 1;
	else	{
		for ( i=0; extension[i] != (char *) 0; i++ ) {
			if (!( strcmp( extension[i] , tmpbuffer ) )) {
				result = (i+1);
				break;
				}
			}
		}				
	*(rptr+ilen) = ' ';
	return( result );
}

