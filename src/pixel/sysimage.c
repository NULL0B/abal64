#ifdef	BADUNIX
#define	high_resolution 1
#else
int	high_resolution=0;
#endif
struct	standard_image * drop_image( struct	standard_image * iptr )
{
	if ( high_resolution )
		local_drop_image( iptr );
#ifndef	BADUNIX
	else	(void) DropImage( iptr );
#endif
	return((struct standard_image *) 0);
}

struct	standard_image * image_loader(char * iname )
{
	struct	standard_image * iptr=(struct standard_image *) 0;
	image_error = 0;
	if ( high_resolution )
		iptr = local_image_loader( iname );
#ifndef	BADUNIX
	else if ((image_error = LoadImage( iname, 0, & iptr ))!=0)
		iptr = (struct standard_image *) 0;
#endif
	return(iptr);
}


