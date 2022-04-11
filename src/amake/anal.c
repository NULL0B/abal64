#include <stdio.h>

void *	malloc(int);
void 	free(void *);

#define	allocate malloc
#define liberate free

char	buffer[1024];

int	verbose=0;
int	liste=0;
int	ignore=0;

struct	node {
	int	type;
	struct	node * previous;
	struct	node * next;
	struct	fichier * contents;
	};

struct	fichier	{
	char *	name;
	int	type;
	int	hash;
	int	done;
	struct	fichier * previous;
	struct	fichier * next;
	struct	node * first;
	struct	node * last;
	};

struct	fichier	*	fileheap=(struct fichier *) 0;
struct	fichier	*	filefoot=(struct fichier *) 0;

int	calculate_hash( char * sptr )
{
	int	r=0;
	while ( *sptr ) r+= *(sptr++);
	return((r % 57));
}

int	compare( char * aptr, char * bptr )
{
	while (( *aptr != 0 ) && ( *bptr != 0 ))
		if ( *(aptr++) != *(bptr++) )
			break;
	if ( *(aptr++) != *(bptr++) )
		return(0);
	else	return(1);
}

struct	fichier * allocate_file( char * nptr )
{
	struct	fichier * fptr;
	if (!( fptr = allocate( sizeof( struct fichier ) )))
		return( fptr );
	else if (!( fptr->name = allocate( strlen( nptr ) + 1 ))) {
		liberate( fptr );
		return((struct fichier *) 0);
		}
	else	{
		strcpy(fptr->name,nptr);
		fptr->previous = fptr->next = (struct fichier *) 0; 
		fptr->first = fptr->last = (struct node *) 0;
		fptr->type  = fptr->done=0;
		fptr->hash  = calculate_hash( nptr );
		return( fptr );
		}

}

struct	fichier * locate_file( char * nptr )
{
	struct	fichier * fptr;
	int	h;
	h = calculate_hash(nptr);
	for (fptr=fileheap; fptr != (struct fichier*) 0; fptr = fptr->next ) {
		if ( h != fptr->hash )
			continue;
		else if (!( compare( nptr, fptr->name )))
			continue;
		else	return( fptr );
		}
	if (!( fptr = allocate_file( nptr ) ))
		return( fptr );
	else	{
		if (!( fptr->previous = filefoot))
			fileheap = fptr;
		else 	filefoot->next = fptr;
		filefoot = fptr;
		return( fptr );
		}
}

void	banner()
{
	return;
}

void	build_node(FILE * h, struct fichier * fptr , int type)
{
	struct	fichier * xptr;
	int	quoting=0;
	int	i=0;
	int	c;
	struct	node * nptr;
	while ((c = fgetc(h)) != -1) {
		if ( c == '"' ) {
			if (!( quoting )) 
				quoting = c;
			else	break;
			}
		else if ( quoting ) {
			if (( c >= 'A') && ( c <= 'Z' ))
				buffer[i++] = ( ignore ? ( c + ('a' - 'A')) : c );
			else	buffer[i++] = c;
			}
		else if (( c >= 'A') && ( c <= 'Z' ))
			buffer[i++] = ( ignore ? ( c + ('a' - 'A')) : c );
		else if (( c >= 'a') && ( c <= 'z' ))
			buffer[i++] = c;
		else if (( c >= '0') && ( c <= '9' ))
			buffer[i++] = c;
		else if ((c == '.') || ( c == '/') || ( c == '_' ) || ( c == '\\' ) || ( c == '-'))
			buffer[i++] = c;
		else if ((c == ' ') || ( c == '\t')) {
			if (!( i )) 
				continue;
			else	break;
			}
		else	break;
		}
	buffer[i] = 0;
	if (!( i ))
		return;
	if (!( xptr = locate_file( buffer )))
		return;
	else if ( xptr->type < type )
		xptr->type = type;
	if (!(nptr = allocate( sizeof( struct node ) )))
		return;
	else	{
		nptr->contents = xptr;
		nptr->previous = nptr->next = (struct node *) 0;
		if (!( nptr->previous = fptr->last ))
			fptr->first = nptr;
		else	fptr->last->next = nptr;
		fptr->last = nptr;
		nptr->type = type;
		return;
		}
}

void	add_node(FILE * h, struct fichier * fptr )
{
	int	c;
	int	i=0;
	struct	node * nptr;
	while ((c = fgetc(h)) != -1) {
		if (( c >= 'a' ) && ( c <= 'z' ))
			buffer[i++] = (c - ('a' - 'A'));
		else if (( c >= 'a' ) && ( c <= 'z' ))
			buffer[i++] = c;
		else	break;
		}
	buffer[i] = 0;
	if (!( i ))
		return;
	if ( compare( buffer,"INCLUDE" ))
		build_node(h,fptr,1);
	else if ( compare( buffer,"USE" ))
		build_node(h,fptr,2);
	return;
}

void	indent( int level )
{
	int	i;
	for ( i=0; i < level; i++ )
		printf("\t");
	return;
}

void	dependance( struct fichier * fptr,int level )
{
	struct	node * nptr;
	if ( verbose ) {
		indent(level);
		printf("dependance : %s { \n",fptr->name);
		}
	if (!( fptr->done )) {
		fptr->done = 1;
		for ( nptr= fptr->first; nptr != (struct node *) 0; nptr = nptr->next )
			if ( nptr->contents )
				dependance( nptr->contents,(level+1) );
		if ( fptr->type == 2 )
			printf("library %s\n",fptr->name);
		}
	if ( verbose ) {
		indent(level+1);
		printf(" } // %s \n",fptr->name);
		}
	return;
}

int	main( int argc, char * argv[] )
{
	int	c;
	int	argi;
	char *	aptr;
	FILE *	h;
	struct	fichier * fptr;
	struct	node * nptr;
	if ( argc == 1 ) {
		banner();
		return(0);
		}

	for (argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'v'	:
				case	'V'	:
					verbose=1;
					break;
				case	'l'	:
				case	'L'	:
					liste=1;
					break;
				case	'i'	:
				case	'I'	:
					ignore=1;
					break;
				}
			continue;
			}
		else	{
			if (!( fptr = locate_file( aptr ))) {
				printf("error allocating %s\n",aptr);
				break;
				}
			else if (!( h = fopen( aptr, "r" ) )) {
				printf("error opening %s\n",aptr);
				break;
				}
			else	{
				if ( verbose ) 
					printf("analysis : %s\n",aptr);
				while ((c = fgetc(h)) != -1) {
					if ( c != '#' )
						continue;
					else	add_node(h,fptr);
					}
				fclose(h);
				}
			}
		}

	for ( fptr=fileheap; fptr != (struct fichier *) 0; fptr = fptr->next )
		if (!( fptr->done ))
			dependance( fptr, 0 );


	if ( liste ) {
		for ( fptr=fileheap; fptr != (struct fichier *) 0; fptr = fptr->next ) {
			if ( fptr->name ) {
				if ( fptr->type == 2 )
					printf("library: %s\n",fptr->name);
				else	printf("source : %s\n",fptr->name);
				for ( nptr= fptr->first; nptr != (struct node *) 0; nptr = nptr->next ) {
					if ( nptr->contents ) {
						if ( nptr->type == 2 )
							printf("\n#use     %s\n",nptr->contents->name);
						else	printf("\n#include %s\n",nptr->contents->name);
						}
					}
				}
			}
		}
	while (( fptr=fileheap) != (struct fichier *) 0) {
		fileheap = fptr->next;
		if ( fptr->name ) {
			while (( nptr= fptr->first ) != (struct node *) 0) {
				fptr->first = nptr->next;
				liberate( nptr );
				}
			liberate( fptr->name );
			}
		liberate( fptr );
		}

	return(0);
}














