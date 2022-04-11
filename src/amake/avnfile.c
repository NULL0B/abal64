#ifndef	_avnfile_c
#define	_avnfile_c

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "allocate.h"
#include "avnfile.h"

#ifndef	O_READONLY
#define	O_READONLY	0
#endif

int	differencecount=0;
extern int	echo;
extern int	verbose;

struct	avnor_diff *	currdiff=(struct avnor_diff *) 0;
struct	avnor_diff *	rootdiff=(struct avnor_diff *) 0;
struct	avnor_diff *	lastdiff=(struct avnor_diff *) 0;
struct	avnor_diff *	diffheap=(struct avnor_diff *) 0;

struct	avnor_file 	*	close_file( struct avnor_file * fptr)
{
	if ( fptr ) {
		if ( fptr->name )
			liberate( fptr->name );
		if ( fptr->buffer )
			liberate( fptr->buffer );

		liberate( fptr );

		}
	return( (struct avnor_file *) 0);
}

struct	avnor_file 	*	open_file( char * nptr )
{
	int	h;
	struct	avnor_file	*	fptr=(struct avnor_file *) 0;
	struct	stat			buffer;
	if (  stat( nptr, &buffer ) < 0 )
		return( fptr );
	else if (!( buffer.st_size ))
		return( fptr );
	else if (!( fptr = allocate( sizeof( struct avnor_file ) ) ))
		return( fptr );

	else	{
		fptr->name 	= 
		fptr->buffer 	= (char *) 0;
		fptr->size	= buffer.st_size;
		fptr->start	=
		fptr->offset	=
		fptr->line	= 0;
		if (!( fptr->name = allocate( strlen( nptr ) + 1 ))) 
			return( close_file( fptr ) );
		else	strcpy(fptr->name,nptr);
		if (!( fptr->buffer = allocate( fptr->size ) ))
			return( close_file( fptr ) );
		else if (!( h = open( fptr->name, O_READONLY ) ))
			return( close_file( fptr ) );
		else	{
			lseek( h, 0L, SEEK_SET );
			read( h, fptr->buffer, fptr->size );
			close(h);
			return( fptr );
			}
		}
}

int	show_line( char * bptr, int o )
{
	int	i;
	int	c;
	for (i=0; *(bptr+i+o) != '\n'; i++ ) { 
		if ((c = *(bptr+i+o))=='\r')
			continue;
		else	printf("%c",c);
		}
	printf("\n");
	return(0);
}

int	display_line( struct avnor_file * lptr )
{
	int	i=0;
	int	c;

	printf("%s(%u):",lptr->name,lptr->line+1);

	while  ((lptr->start+i) < lptr->size) {
		if ((c = lptr->buffer[(lptr->start+i)]) == '\n' )
			break;
		else	{
			printf("%c",c);
			i++;
			}
		}
	printf("\n");
	return(0);
}

int	add_difference(	struct avnor_diff * dptr, int count ,int nature )
{
	if (( lastdiff != (struct avnor_diff * ) 0)
	&&  ( lastdiff->type == _AVNOR_MODIFIED   )
	&&  ( nature         == _AVNOR_MODIFIED   )
	&&  ( lastdiff->lline== (dptr->lline-lastdiff->lines)   )
	&&  ( lastdiff->rline== (dptr->rline-lastdiff->lines)   )) {
		dptr->next = diffheap;
		diffheap = dptr;
		lastdiff->lines++;
		return(1);
		}
	else	{
		if (!( dptr->previous = lastdiff ))
			rootdiff = dptr;
		else 	lastdiff->next = dptr;
		lastdiff = dptr;
		dptr->lines = count;
		dptr->type  = nature;
		return(1);
		}
}

struct avnor_diff * 	allocate_difference(	struct avnor_file * lptr, struct avnor_file * rptr )
{
	struct avnor_diff * dptr;

	if ( verbose ) {
		display_line( lptr );
		display_line( rptr );
		}
	if (( dptr = diffheap ) != (struct avnor_diff *) 0)
		diffheap = diffheap->next;
	else if (!( dptr = allocate( sizeof( struct avnor_diff ) ) ))
		return(dptr);
	dptr->previous = dptr->next;
	dptr->lline = lptr->line;
	dptr->rline = rptr->line;
	dptr->lines = dptr->type = 0;
	return( dptr );

}

int	compare_lines(	struct avnor_file * lptr, struct avnor_file * rptr )
{
	int 	i=0;
	int	c;
	while  (((lptr->start+i) < lptr->size)
	&&	((rptr->start+i) < rptr->size)) {
		if ((c = lptr->buffer[(lptr->start+i)]) != rptr->buffer[(rptr->start+i)])
			return(0);
		else 	{
			i++;
			if ( c == '\n' ) {
				return(i);
				}
			}
		}
	return(-1);
}

int	next_line( struct avnor_file * lptr)
{
	int	i=0;
	int	c;
	while  ((lptr->start+i) < lptr->size) {
		c = lptr->buffer[(lptr->start+i)];
		i++;
		if ( c == '\n' ) {
			lptr->line  += 1;
			lptr->start += i;
			return(1);
			}
		}
	return(0);
}

int	is_inserted_lines(	struct avnor_file * lptr, struct avnor_file * rptr )
{
	int	i=0;
	int	n=0;
	int	offset;
	int	line;
	offset = lptr->start;
	line   = lptr->line;
	while (1) {
		if (!( next_line( lptr ) )) {
			lptr->start = offset;
			lptr->line  = line;
			return(0);
			}
		else  	{
			n++;
			if (!(i =  compare_lines( lptr, rptr ) )) {
				continue;
				}
			else if ( i > 1 ) {
				/* not just a line feed */
				lptr->start += i;
				rptr->start += i;
				lptr->line += 1;
				rptr->line += 1;
				return(n);
				}
			else	continue;


			}
		}
}

int	difference( char * aptr, char * bptr, int isupdate )
{
	struct	avnor_diff * dptr;
	int	i=0;
	int	n=0;
	int	errors=0;
	
	struct avnor_file * lptr=(struct avnor_file*) 0;
	struct avnor_file * rptr=(struct avnor_file*) 0;

#ifdef	AVNOR_MULTIPLE
	if ( (i = is_directory( aptr )) != (n = is_directory( bptr ) ))
		return( 1 );
	else if ((i) && (n))
		return( compare_directories( aptr, bptr ) );
#endif
	if (( lptr = open_file( aptr )) != (struct avnor_file*) 0) {
		if (( rptr = open_file( bptr )) != (struct avnor_file*) 0) {
			while (1) {
				if (!( i = compare_lines( lptr, rptr ) )) {
					if ( isupdate )
						return( ++differencecount );
						
					if (!( dptr = allocate_difference( lptr, rptr ) ))
						break;
					else	differencecount++;

					/* ------------------------------------------------- 	*/
					/* Test for Inserted lines by seeking the current 	*/
					/* line of the left hand file in the right hand   	*/
					/* file from the next right hand line		  	*/
					/* ------------------------------------------------- 	*/
					if ((n = is_inserted_lines( lptr, rptr )) > 0) {

						if (!( add_difference( dptr, n, _AVNOR_INSERTED ) )) 
							break;
						else if ( verbose > 1)   {
							printf("%u inserted lines\n",n);
							}
						continue;
						}						

					/* ------------------------------------------------- 	*/
					/* Test for Deleted lines by seeking the current 	*/
					/* line of the right hand file in the left hand   	*/
					/* file from the next left hand line		  	*/
					/* ------------------------------------------------- 	*/
					if ((n = is_inserted_lines( rptr, lptr )) > 0 ) {
						if (!( add_difference( dptr, n, _AVNOR_DELETED ) )) 
							break;
						else if ( verbose > 1 ) {
							printf("%u deleted lines\n",n);
							}
						continue;
						}

					/* ------------------------------------------------- 	*/
					/* The lines are assumed modified and continue with  	*/
					/* the both next lines or quit if either end of file 	*/
					/* ------------------------------------------------- 	*/
					else	{
						if (!( add_difference( dptr, 1, _AVNOR_MODIFIED ) )) 
							break;
						else if ( verbose > 1 ) {
							printf("modified line\n",n);
							}
						if (!( next_line( lptr ) ))
							break;
						else if (!( next_line( rptr ) ))
							break;
						else	continue;
						}


					}
				else if ( i > 0 ) {
					/* lines match */
					/* ----------- */
					lptr->line  += 1;
					lptr->start += i;
					rptr->line  += 1;
					rptr->start += i;
					continue;
					}
				/* end of either of the files */
				/* -------------------------- */
				else	break;

				}

			rptr = close_file( rptr );
			}
		else	{
			if ( verbose ) {
				printf("\n** error: cannot open : %s **\n",bptr);
				}
			errors++;
			}
		lptr = close_file( lptr );
		}
	else	{
		if ( verbose ) {
			printf("\n** error: cannot open : %s **\n",aptr);
			}
		errors++;
		}
	return( differencecount + errors );
}

void	show_differences(char * aptr, char * bptr)
{
	struct	avnor_diff * dptr;
	for (	dptr=rootdiff;
		dptr != (struct	avnor_diff *) 0;
		dptr = dptr->next ) {
		printf("%s(%u) : %s(%u) %u line(s)",
			aptr,dptr->lline,
			bptr,dptr->rline,
			dptr->lines);
		switch ( dptr->type ) {
			case	_AVNOR_MODIFIED : printf(" modified\n"); break;
			case	_AVNOR_INSERTED : printf(" inserted\n"); break;
			case	_AVNOR_DELETED  : printf(" deleted \n"); break;
			}
		}
	return;
}

void	release_difference(struct avnor_diff * dptr)
{
	if ( dptr ) {
		liberate( dptr );
		}
	return;
}

void	release_differences()
{
	struct	avnor_diff * dptr;
	while ((dptr = rootdiff) != (struct avnor_diff *) 0) {
		rootdiff = dptr->next;
		release_difference( dptr );
		}
	currdiff=rootdiff=lastdiff=(struct avnor_diff *) 0;
	differencecount=0;
	return;
}


struct	avnor_diff *	current_difference()
{
	if (!( currdiff ))
		currdiff = rootdiff;
	return( currdiff );

}

struct avnor_diff * select_difference(int position)
{
	switch ( position ) {
		case	 0	:
			return( current_difference() );
		case	12	:	/* home : first */
			return(( currdiff = rootdiff ));

		case	11	:	/* previous	*/
			if (!( currdiff ))
				return((struct avnor_diff *) 0);
			else if (!( currdiff->previous ))
				return((struct avnor_diff *) 0);
			else 	return((currdiff = currdiff->previous));

		case	 5	:	/* next		*/
			if (!( currdiff ))
				return((struct avnor_diff *) 0);
			else if (!( currdiff->next ))
				return((struct avnor_diff *) 0);
			else 	return((currdiff = currdiff->next));

		case	 2	:	/* end : last	*/
			return (( currdiff = lastdiff ));
		}
	return;
}

int	calculate_differences( char * lptr, int llen, char * rptr, int rlen, int option )
{
	int	status;
	int	l;
	int	r;
	int	lc;
	int	rc;
	for ( l=0; l < llen; l++ )
		if ( *(lptr+l) == ' ' )
			break;
	lc = *(lptr+l); *(lptr+l) = 0;
	for ( r=0; l < rlen; r++ )
		if ( *(rptr+r) == ' ' )
			break;
	rc = *(rptr+r); *(rptr+r) = 0;
	status = difference( lptr, rptr, option );
	*(rptr+r) = rc;
	*(lptr+l) = lc;
	return( status );
}


	

#endif	/* _avnfile_c */




