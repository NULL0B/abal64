#ifndef	_stdimage_h
#define	_stdimage_h
struct standard_image * local_drop_image( struct standard_image * iptr );
struct standard_image * local_allocate_image( int columns, int rows,int dath,int scaled );
struct standard_image * local_image_loader( char * filename );
struct standard_image * image_loader( char * filename );
struct standard_image * resolve_image(char * filename,int namelen );
struct standard_image * resolve_image_by_number( int number );
char 		      *	resolve_imagename_by_number( int number );
struct standard_image * drop_image( struct standard_image * iptr );
void	release_images();
int	image_heap_count();
int	imageheap_drop_item( char * nptr );
#endif

