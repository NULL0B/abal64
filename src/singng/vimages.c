#include "zjpeg.h"
#include "vimage.h"
#include "valign.h"

#ifdef	FUCKING_IMAGES
#include "vmakefit.c"
private	void	llimage(	int atx, int aty, int tw, int th,
			struct standard_image * iptr, int options )
{
	int			r;
	int			p;
	int			sw;
	int			sh;
	int			nc,np;
	int			nl,nr;
	char	*		rptr;

	if ((!( tw  ))
	||  (!( th  ))) {
		return;
		}

	if ((!( iptr ))
	||  (!( iptr->storage ))) {
		 for (	p=1,r=0; r < th; r++,p++ ) filzone(atx,aty+r,tw,1,p);
		}
	else	{
		if ( iptr->palette ) {
			vgapalette(iptr->palette,0,256);
			}
		/* calculate alignments and repetitions */
		/* ------------------------------------ */
		if (( options & 7 ) == _I_TILE ) {
			sh=(th>iptr->rows?iptr->rows:th);
			sw=(tw>iptr->columns?iptr->columns:tw);
			}
		else if (( options & 7 ) == _I_MAKEFIT ) {
			imakefit(atx,  aty,  tw,  th,iptr,( _I_MAKEFIT | (options & _I_SPRITE )) );
			if ( iptr->palette )
#ifdef WIN32
				put_palette_byexa();
#else
				put_palette();
#endif
			return;
			}
		else if (( options & 7 ) == _I_BESTFIT ) {
			ibestfit(atx,  aty,  tw,  th,iptr,( _I_BESTFIT  | (options & _I_SPRITE )));
			if ( iptr->palette )
#ifdef WIN32
				put_palette_byexa();
#else
				put_palette();
#endif
			return;
			}
		else	{
			/* horizontaltical alignment */
			/* ------------------------- */
			switch ( options & 3 ) {
				case	_A_NONE    : 
				case	_A_LEFT    : 
					sw=(tw>iptr->columns?iptr->columns:tw);
					break;
	
				case	_A_RIGHT   : 
					if ((sw = iptr->columns ) < tw) 
						atx += 	(tw-sw);
					else	sw = tw;
					break;					
	
				case	_A_CENTER  :
					if ((sw = iptr->columns ) < tw) 
						atx += 	((tw-sw)/2);
					else	sw = tw;
					break;
				}

			/* vertical alignment */
			/* ------------------ */
			if ( options & _A_TOP )
				sh=(th>iptr->rows?iptr->rows:th);

			else if ( options & _A_BOTTOM ) {
				if ((sh = iptr->rows ) < th) 
					aty += 	(th - sh);
				else	sh = th;
				}
			else 	{
				if ((sh = iptr->rows ) < th) 
					aty += 	((th - sh)/2);
				else	sh = th;
				}
			tw = sw; th = sh;
			}
		nl = 0;
		while ( nl < th ) {
			nr = ( sh < (th - nl) ? sh : (th - nl));
			for (	r=0; r < nr; r++ ) {
				if (!(rptr = connect_pixel_row(iptr->storage,r)))
					break;
				else	{
					nc=0;
					if (!( iptr->format )) {
						while ( nc < tw ) {
							if (!( np = (sw < (tw - nc) ? sw : (tw - nc) ) ))
								break;
							else if ( options & _I_SPRITE )
								mixzone8(atx+nc,aty+nl+r,np,1,rptr);
							else	putzone8(atx+nc,aty+nl+r,np,1,rptr);
							nc += np;
							}
						}
					else	{
						while ( nc < tw ) {
							if (!( np = (sw < (tw - nc) ? sw : (tw - nc) ) ))
								break;
							else if ( options & _I_SPRITE )
								mixzone(atx+nc,aty+nl+r,np,1,rptr);
							else	putzone(atx+nc,aty+nl+r,np,1,rptr);
							nc += np;
							}

						}
					}
				}
			nl += r;
			}
		}
	if ( iptr )
		if ( iptr->palette )
#ifdef WIN32
			put_palette_byexa();
#else
			put_palette();
#endif
	return;
}

public	void	image(	int atx, int aty, int tw, int th,
			struct standard_image * iptr, int options )
{
	hide();
	llimage(atx,aty,tw,th,iptr,options);
	show(atx,aty,tw,th);
	return;
}
#endif

public	struct standard_image *  load_visual_image( char * filename )
{
	struct standard_image * iptr = (struct standard_image *) 0;
	char	*	sfic;
	char	*	sptr;
	int	i;
	char *	visual_language_flag();

	if (!( strcmp( filename, "flag" ) ))
		filename = visual_language_flag();

#ifdef WIN32
	/* ordre de recherche sous Windows */

	if (!( system_imagepath ))
		system_imagepath = configuration_item("IMAGEPATH");

	// Fichier de config clé==nom de fichier
	if ((!iptr) && ((sfic = configuration_item( filename )) != (char *) 0)) 
		{
		strcpy(fontbuffer,sfic);
		iptr = resolve_image( fontbuffer, strlen( fontbuffer ) );
		}

	// Fichier de config clé==IMAGEPATH
	if ((!iptr) && (system_imagepath) && check_image_paths())
		{
		for ( i=0; i < system_imagepaths; i++ ) 
			{
			sprintf(fontbuffer,"%s%s",imagepath[i],filename);
			if (!(iptr = resolve_image( fontbuffer, strlen( fontbuffer ) ) ))
				continue;
			else	break;
			}
		}

	// recherche selon l'exécuteur
	if ((!iptr) && find_image_byexa( filename, fontbuffer ))
		{
		iptr = resolve_image( fontbuffer, strlen( fontbuffer ) );
		}

		
#else


	if (!( system_imagepath ))
		system_imagepath = configuration_item("IMAGEPATH");
	if ((sfic = configuration_item( filename )) != (char *) 0) {
		strcpy(fontbuffer,sfic);
		if (!(iptr = resolve_image( fontbuffer, strlen( fontbuffer ) ) ))
			return 0;
		}
	else if ( fn_parser( filename, fontbuffer, 0x0007 ) != 0) {
		strcpy(fontbuffer,filename);
		if (!(iptr = resolve_image( fontbuffer, strlen( fontbuffer ) ) ))
			return 0;
		}
	else if (!( sptr = system_imagepath )) {
		strcpy(fontbuffer,filename);
		if (!(iptr = resolve_image( fontbuffer, strlen( fontbuffer ) ) ))
			return 0;
		}
	else if (!( check_image_paths() )) {
		strcpy(fontbuffer,filename);
		if (!(iptr = resolve_image( fontbuffer, strlen( fontbuffer ) ) ))
			return 0;
		}
	else	{
		for ( i=0; i < system_imagepaths; i++ ) {
			sprintf(fontbuffer,"%s%s",imagepath[i],filename);
			if (!(iptr = resolve_image( fontbuffer, strlen( fontbuffer ) ) ))
				continue;
			else	break;
			}
		}

#endif

	return( iptr );
}

private	void	visual_image_loader(	int atx, int aty, int nbx, int nby, char * filename, int options )
{
	struct standard_image * iptr;
	int	l;
	if (( filename != (char *) 0)
	&&  ((l = strlen(filename)) != 0)) {
		iptr = load_visual_image( filename );
		if ( iptr ) {
			if (!( iptr->name ))
				iptr->name = allocate_string( filename );
			/* printf("draw image : %s \r\n",iptr->name); */
			drawimage(atx,aty, nbx, nby, iptr, options );
			}
		}
	return;

}

public	void	visual_image( int atx, int aty, int nbx, int nby, char * filename, int options )
{
	if ( options & _I_QUALITY )
		set_image_quality(1);
	else if (!( get_pixel_format() ))
                set_image_quality(1|(options&_I_SPRITE));
	else	set_image_quality(0);

	visual_image_loader( atx,aty,nbx,nby,filename,options);

	set_image_quality(0);
}


public	int	visual_image_info(char * filename, int * width, int * height )
{
	struct standard_image * iptr;
	if ((iptr = load_visual_image( filename )) != (struct standard_image *) 0) {
		*width = iptr->columns;
		*height= iptr->rows;
		return(0);
		}
	else	return( 40 );
}







