#include "singconf.h"

extern	char * 	system_imagepath;
extern	char * 	imagepath[10];
extern	int	system_imagepaths;

public	int	screen_capture()
{
	char *	tempname=(char *) 0;
	int	r=0;
	char *	bptr;
	struct standard_image * iptr;

	if (!(iptr = local_allocate_image(Context.width,Context.height,Context.background,0) ))
		return(256);

	else	{
		for (	r=0; r < Context.height; r++ ) {
			if (!( bptr = connect_pixel_row(iptr->storage,r) ))
				break;
			else	getzone(0,r,Context.width,1,bptr);
			}
		image_save("capture.gif",iptr,0);
		local_drop_image( iptr );
		return( 256 );

		}

}

public	struct standard_image * widget_image_loader( char * nfic, int q )
{
#ifdef WIN32
	/* ordre de recherche sous Windows */

	int	i;
	char *	sptr;
	char *	sfic;
	struct	standard_image * iptr=(struct standard_image *) 0;

	if (!( nfic ))
		return(iptr);

	// Fichier de config clé==nom de fichier
	if ((!iptr) && ( *nfic == _UNQUOTED_STRING ))
		{
		if ((sfic = configuration_item( (nfic+1) )) != (char *) 0)
			nfic = sfic;
		strcpy(namebuffer,nfic);
		iptr = local_image_loader( namebuffer );
		}

	// Fichier de config clé==IMAGEPATH
	if ((!iptr) && (system_imagepath) && check_image_paths())
		{
		for ( i=0; i < system_imagepaths; i++ ) 
			{
			sprintf(namebuffer,"%s%s",imagepath[i],nfic);
			if ((iptr = local_image_loader( namebuffer )) != (struct standard_image *) 0)
				break;
			}
		if (!( iptr ))
			iptr = local_image_loader( nfic );
		}

	// recherche selon l'exécuteur
	if ((!iptr) && find_image_byexa( nfic, namebuffer ))
		{
		iptr = local_image_loader( namebuffer );
		}

	return( iptr );
#else
	int	i;
	char *	sptr;
	char *	sfic;
	struct	standard_image * iptr=(struct standard_image *) 0;
	if (!( nfic ))
		return(iptr);
	else if ( *nfic == _UNQUOTED_STRING ) {
		if ((sfic = configuration_item( (nfic+1) )) != (char *) 0)
			nfic = sfic;
		strcpy(namebuffer,nfic);
		return( local_image_loader( namebuffer ) );
		}
	else if ( fn_parser( nfic, namebuffer, 0x0007 ) != 0) {
		strcpy(namebuffer,nfic);
		return( local_image_loader( namebuffer ) );
		}
	else if (!( sptr = system_imagepath )) {
		strcpy(namebuffer,nfic);
		return( local_image_loader( namebuffer ) );
		}
	else if (!(check_image_paths())) {
		strcpy(namebuffer,nfic);
		return( local_image_loader( namebuffer ) );
		}
	else	{
		for ( i=0; i < system_imagepaths; i++ ) {
			sprintf(namebuffer,"%s%s",imagepath[i],nfic);
			if ((iptr = local_image_loader( namebuffer )) != (struct standard_image *) 0)
				break;
			}
		if (!( iptr ))
			iptr = local_image_loader( nfic );
		return( iptr );
		}

#endif
}

public	void	image_load(char * nptr, struct standard_image ** iiptr  )
{
	struct	standard_image * iptr;
	if (!( nptr = allocate_string( nptr )))
		return;
	if ( accept_imageload( &nptr ) != 27 )
		if ((iptr = widget_image_loader( nptr, 0 )) != (struct standard_image *) 0)
			*iiptr = iptr;
	liberate( nptr );
	return;
}


public 	void	build_image(struct form_item * iptr )
{
	char	*	tptr;

	if ((tptr = allocate((iptr->Contents.size=256))) != (char *) 0) {
		iptr->Contents.payload = tptr;
		strcpy(tptr,"image.new");
		if ( accept_imageload( & iptr->Contents.payload ) != 27 ) {
			if (!(iptr->Contents.extra = widget_image_loader(iptr->Contents.payload,iptr->Contents.align))) 
				iptr->Contents.extra = local_allocate_image(iptr->Contents.w,iptr->Contents.h,Context.background,0);

			}
		else 	iptr->Contents.extra = local_allocate_image(iptr->Contents.w,iptr->Contents.h,Context.background,0);

		}

	return;
}

public	void	reload_image(struct window_control* dptr);

public 	void	resize_image(
			struct form_item * iptr,
			int width, 
			int height 
			)
{
	int	r;
	char *	rptr;
	char *	sptr;
	int	nbc;
	struct standard_image * yptr;
	struct standard_image * xptr;
	iptr->Contents.w = width;
	iptr->Contents.h = height;
	reload_image( &iptr->Contents );
	return;
	if ((yptr = local_allocate_image(width,height,Context.background,0))!= (struct standard_image *) 0) {
		if ((xptr = iptr->Contents.extra) != (struct standard_image *)0) {
			nbc = (yptr->columns < xptr->columns ? yptr->columns : xptr->columns );
			for (r=0; r < yptr->rows; r++ ) {
				if ( r >= xptr->rows )
					break;
				else if (!( sptr = connect_pixel_row( xptr->storage, r ) ))
					break;
				else if (!( rptr = connect_pixel_row( yptr->storage, r ) ))
					break;
				else	memcpy( rptr, sptr, nbc );
						
				}
			xptr = local_drop_image(xptr);
			}
		iptr->Contents.extra = yptr;
		}
	return;
}


public	void	reload_image(struct window_control* dptr)
{
	struct standard_image * iptr;
	if ((iptr = widget_image_loader(dptr->payload,dptr->align)) != (struct standard_image *) 0) {
		if ( dptr->extra ) {
			dptr->extra = local_drop_image( dptr->extra );
			}
		dptr->extra = iptr;
		}
	return;
}

public	void	draw_image(int topx, int topy,struct form_item* iptr,int editing)
{
	drawimage( topx+iptr->Contents.x, topy+iptr->Contents.y, iptr->Contents.w, iptr->Contents.h, iptr->Contents.extra,
		( iptr->Contents.align | Context.hideimage ));
	return;
}

#include "singzoom.c"


