#ifndef	_vbuffer_c
#define	_vbuffer_c

public	void *	visual_buffer(int x,int y, int w, int h )
{
	void	* vptr;
	vptr = allocate_graphic_storage( 0,0, w, h );
//	printf("0x0%lx = visual_buffer(%u,%u,%u,%u)\r\n",vptr,x,y,w,h);
	return( vptr );
}

public	void * visual_drop( void * vptr)
{
//	printf("visual_drop(0x0%lx)\r\n",vptr);
	return( liberate_pixel_storage( vptr ) );
}

public	int	visual_buffer_get(STDPSUPTR pptr, int atx, int aty )
{
	int		r;
	int		width;
	int		height;
	BPTR		bptr;

//	printf("visual_buffer_get(0x0%lx,%u,%u)\r\n",pptr,atx,aty);
	if (!(width = pptr->descriptor[0] ))
		return(0);

	else if (!(height = pptr->descriptor[1] ))
		return(0);

	/* Transfer rows from output */
	/* ------------------------- */
	for (	r=0;
		r <  height;
		r++ ) {
		if (!( bptr = connect_pixel_row( pptr, r )))
			break;
		else	getzone(atx,aty+r,width,1,bptr);
		}		

	return(1);
}

public	int	visual_buffer_put(STDPSUPTR pptr, int atx, int aty )
{
	int		r;
	int		width;
	int		height;
	BPTR		bptr;

//	printf("visual_buffer_put(0x0%lx,%u,%u)\r\n",pptr,atx,aty);

	if (!(width = pptr->descriptor[0] ))
		return(0);

	else if (!(height = pptr->descriptor[1] ))
		return(0);

	hide();
	/* Transfer rows to output */
	/* ----------------------- */
	for (	r=0;
		r <  height;
		r++ ) {
		if (!( bptr = connect_pixel_row( pptr, r )))
			break;
		else	putzone(atx,aty+r,width,1,bptr);
		}		
	show(atx,aty,width,height);
	return(1);

}

public	int	visual_buffer_mix(STDPSUPTR pptr, int atx, int aty )
{
	int		r;
	int		width;
	int		height;
	BPTR		bptr;

	if (!(width = pptr->descriptor[0] ))
		return(0);

	else if (!(height = pptr->descriptor[1] ))
		return(0);

	hide();
	/* Transfer rows to output */
	/* ----------------------- */
	for (	r=0;
		r <  height;
		r++ ) {
		if (!( bptr = connect_pixel_row( pptr, r )))
			break;
		else	mixzone(atx,aty+r,width,1,bptr);
		}		
	show(atx,aty,width,height);
	return(1);

}

public	int	visual_buffer_show(STDPSUPTR pptr, int ci, int ri, int atx, int aty, int nbx, int nby )
{
	int		r;
	int		width;
	int		height;
	BPTR		bptr;

	if (!(width = pptr->descriptor[0] ))
		return(0);

	else if (!(height = pptr->descriptor[1] ))
		return(0);

	if ( width  > nbx ) width  = nbx;
	if ( height > nby ) height = nby;

	hide();

	/* Transfer rows to output */
	/* ----------------------- */
	for (	r=0;
		r <  height;
		r++ ) {
		if (!( bptr = connect_pixel_row( pptr, (r+ri) )))
			break;
		else	putzone(atx,aty+r,width,1,(bptr+ci));
		}		
	show(atx,aty,width,height);
	return(1);

}

#endif	/* _vbuffer_c */
	/* ---------- */

