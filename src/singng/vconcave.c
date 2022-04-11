public	void	visual_concave(int atx,int aty, int nbx, int nby )
{
	if ( nby >= 12 ) {
		filzone(atx,aty,nbx,nby,standard_backwash);
		filzone (atx,aty+0,nbx,1,standard_black);
		xfilzone(atx,aty+1,nbx,1,standard_loblack);
		filzone (atx,aty+2,nbx,1,standard_lolight);
		xfilzone(atx,aty+3,nbx,1,standard_miblack);
		filzone (atx,aty+4,nbx,1,standard_lomid);
		xfilzone(atx,aty+5,nbx,1,standard_hiblack);
		aty+=(nby-1);
		xfilzone(atx,aty-5,nbx,1,standard_lowhite);
		filzone (atx,aty-4,nbx,1,standard_himid);
		xfilzone(atx,aty-3,nbx,1,standard_miwhite);
		filzone (atx,aty-2,nbx,1,standard_hilight);
		xfilzone(atx,aty-1,nbx,1,standard_hiwhite);
		filzone (atx,aty-0,nbx,1,standard_white);
		}
	return;
}

public	void	vertical_concave(int atx,int aty, int nbx, int nby )
{
	if ( nbx >= 12 ) {
		filzone(atx,aty,nbx,nby,standard_backwash);
		filzone (atx+0,aty,1,nby,standard_black );
		xfilzone(atx+1,aty,1,nby,standard_loblack);
		filzone (atx+2,aty,1,nby,standard_lolight);	
		xfilzone(atx+3,aty,1,nby,standard_miblack);
		filzone (atx+4,aty,1,nby,standard_lomid );
		xfilzone(atx+5,aty,1,nby,standard_hiblack);
		atx+=(nbx-1);
		xfilzone(atx-5,aty,1,nby,standard_lowhite);
		filzone (atx-4,aty,1,nby,standard_himid);
		xfilzone(atx-3,aty,1,nby,standard_miwhite);
		filzone (atx-2,aty,1,nby,standard_hilight);
		xfilzone(atx-1,aty,1,nby,standard_hiwhite);
		filzone (atx-0,aty,1,nby,standard_white);
		}
	return;
}



