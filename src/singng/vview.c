public	int	visual_viewport(int atx, int aty, int nbx,int nby, int fid)
{
	use_base_font(fid);
	if (( nbx != 0 ) && ( nby != 0 ))
		cicowindow(atx,aty,nbx,nby);
	else	cicowindow(atx,aty,nbx,nby);
	return(0);
}

