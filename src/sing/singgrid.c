public	void	draw_grid( int atx, int aty, int nbx, int nby, int zf, int type )
{
	int	x;
	hide();

	if ( type != 0 )
		visual_frame(	atx, aty, nbx*zf, nby*zf, type );
	else	relief(atx,aty,nbx,nby,_DEFAULT_GUI_BLACK,0,_DEFAULT_GUI_BLACK);

	if ( zf > 1 ) {

		for (	x=zf; x < (nbx*zf); x += zf)
			filzone(atx+x,aty,1,nby*zf,_DEFAULT_GUI_BLACK);
		for (	x=zf; x < (nby*zf); x += zf)
			filzone(atx,aty+x,nbx*zf,1,_DEFAULT_GUI_BLACK);

		}

	show (	atx, aty, nbx*zf, nby*zf );
	return;
}


