#ifndef	_singflow_c
#define	_singflow_c

void	flowchartTraceRoute(int sx, int sy, int tx, int ty, int level, int reverse );

struct visual_flowchart_model * flowchartEwBlock(int y, int sx, int tx, int nb)
{
	struct visual_flowchart_model * bptr=(struct visual_flowchart_model *) 0;
	struct visual_flowchart_model * mptr;
	for ( 	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		if ( mptr->inhibit )
			continue;
		else if ( mptr->x >= sx )
			continue;
		else if ( (mptr->x+mptr->w) <= tx )
			continue;
		else if ( mptr->y >= y )
			continue;
		else if ( (mptr->y+mptr->h) <= y )
			continue;
		else if (!( bptr ))
			bptr = mptr;
		else if ( (mptr->x+mptr->w) > (bptr->x+bptr->w) )
			bptr = mptr;
		}
	if (( bptr ) && ( VFE.debug_trace_route )) {
		printf("EwBlocked(%u)(y=%u,sx=%u,tx=%u) by %s(%u,%u,%u,%u)\r\n",
			nb,y,sx,tx,
			bptr->name,bptr->x,bptr->y,bptr->x+bptr->w,bptr->y+bptr->h);
		}
	return( bptr );
}

struct visual_flowchart_model * flowchartWeBlock(int y, int sx, int tx,int nb)
{
	struct visual_flowchart_model * bptr=(struct visual_flowchart_model *) 0;
	struct visual_flowchart_model * mptr;
	for ( 	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		if ( mptr->inhibit )
			continue;
		else if ( mptr->x >= tx )
			continue;
		else if ( (mptr->x+mptr->w) <= sx )
			continue;
		else if ( mptr->y >= y )
			continue;
		else if ( (mptr->y+mptr->h) <= y )
			continue;
		else if (!( bptr ))
			bptr = mptr;
		else if ( mptr->x < bptr->x )
			bptr = mptr;
		}
	if (( bptr ) && ( VFE.debug_trace_route )) {
		printf("WeBlocked(%u)(y=%u,sx=%u,tx=%u) by %s(%u,%u,%u,%u)\r\n",
		nb,y,sx,tx,
			bptr->name,bptr->x,bptr->y,bptr->x+bptr->w,bptr->y+bptr->h);
		}
	return( bptr );
}

struct visual_flowchart_model * flowchartNsBlock(int x, int sy, int ty,int nb)
{
	struct visual_flowchart_model * bptr=(struct visual_flowchart_model *) 0;
	struct visual_flowchart_model * mptr;
	for ( 	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		if ( mptr->inhibit )
			continue;
		else if ( (mptr->y+mptr->h) <= sy )
			continue;
		else if ( mptr->y >= ty )
			continue;
		else if ( mptr->x >= x )
			continue;
		else if ( (mptr->x+mptr->w) <= x )
			continue;
		else if (!( bptr ))
			bptr = mptr;
		else if ( mptr->y < bptr->y )
			bptr = mptr;
		}
	if (( bptr ) && ( VFE.debug_trace_route )) {
		printf("NsBlocked(%u)(x=%u,sy=%u,ty=%u) by %s(%u,%u,%u,%u)\r\n",
			nb,x,sy,ty,
			bptr->name,bptr->x,bptr->y,bptr->x+bptr->w,bptr->y+bptr->h);
		}
	return( bptr );
}

struct visual_flowchart_model * flowchartSnBlock(int x, int sy, int ty,int nb)
{
	struct visual_flowchart_model * bptr=(struct visual_flowchart_model *) 0;
	struct visual_flowchart_model * mptr;
	for ( 	mptr = VFE.first;
		mptr != (struct visual_flowchart_model *) 0;
		mptr = mptr->next ) {
		if ( mptr->inhibit )
			continue;
		else if ( mptr->y >= sy )
			continue;
		else if ( (mptr->y+mptr->h) <= ty )
			continue;
		else if ( mptr->x >= x )
			continue;
		else if ( (mptr->x+mptr->w) <= x )
			continue;
		else if (!( bptr ))
			bptr = mptr;
		else if ( (mptr->y+mptr->h) > (bptr->y+mptr->h) )
			bptr = mptr;
		}
	if (( bptr ) && ( VFE.debug_trace_route )) {
		printf("SnBlocked(%u)(x=%u,sy=%u,ty=%u) by %s(%u,%u,%u,%u)\r\n",
			nb,x,sy,ty,
			bptr->name,bptr->x,bptr->y,bptr->x+bptr->w,bptr->y+bptr->h);
		}
	return( bptr );
}

void	datadebugTraceLine(int sx, int sy, int tx, int ty, int nb )
{
	if ( VFE.debug_trace_route ) {
		printf("\tTraceLine(%u)(sx=%u,sy=%u) -> (tx=%u,ty=%u) \r\n",nb,sx,sy,tx,ty);
		}
	flowchartTraceLine(sx,sy,tx,ty);
	return;
}

void	datadebugTracePoint(int sx, int sy, int nb )
{
	if ( VFE.debug_trace_route ) {
		printf("\tTracePoint(%u)(sx=%u,sy=%u)\r\n",nb,sx,sy);
		}
	flowchartTracePoint(sx,sy);
	return;
}

void	flowchartTraceRound(int sx,int sy,int tx,int ty,int mx,struct visual_flowchart_model * bptr,int level,int reverse,int nb)
{
	struct visual_flowchart_model * wptr;
	int	my;
	if ( VFE.debug_trace_route ) {
		printf("  flowchartTraceRound(%u)(sx=%u,sy=%u, tx=%u,ty=%u, mx=%u)\r\n",nb,sx,sy,tx,ty,mx);
		}
	if ((sy-bptr->y) < ((bptr->y+bptr->h)-sy)) {
		/* around the top */
		my = (bptr->y >= VFE.tracepadding ? (bptr->y-VFE.tracepadding) : 0);
		/* check for and avoid eventual obstacle */
		if ((wptr = flowchartSnBlock( mx, sy, my,1)) != (struct visual_flowchart_model *) 0)
			my = ((wptr->y+wptr->h) + 10);
		datadebugTraceLine(mx,sy,mx,my,1);
		if ( sy < my )
			datadebugTracePoint(mx,my,1);
		flowchartTraceRoute(mx,my,tx,ty,level+1,reverse);					
		}
	else	{
		/*around the bottom */
		my = (bptr->y+bptr->h+VFE.tracepadding);
		/* check for and avoid eventual obstacle */
		if ((wptr = flowchartNsBlock( mx, sy, my,1)) != (struct visual_flowchart_model *) 0)
			my = (wptr->y - 10);
		datadebugTraceLine(mx,sy,mx,my,2);
		if ( sy < my )
			datadebugTracePoint(mx,my,1);
		flowchartTraceRoute(mx,my,tx,ty,level+1,reverse);					
		}
	return;
}

int	__f__T__r=0;
void	flowchartTraceRoute(int sx, int sy, int tx, int ty, int level, int reverse )
{
	struct visual_flowchart_model * bptr;
	int	xx;
	int	mx;
	int	my;
	int	bottom;
	if ( VFE.debug_trace_route ) {
		printf("  flowchartTraceRoute(sx=%u,sy=%u, tx=%u,ty=%u, l=%u,r=%u)\r\n",sx,sy,tx,ty,level,reverse);
		}
	if ( __f__T__r > VFE.depth )
		return;
	else	__f__T__r++;
	if ( sy == ty ) {
		/* its a possible horizontal direct hit */
		if ( sx > tx ) {
			if (!(bptr = flowchartEwBlock(sy,sx,tx,1))) {
				/* direct : no obstacles : go for it */
				datadebugTraceLine(sx,sy,tx,ty,3);
				}
			else	{
				/* obstacle */
				mx = ((bptr->x+bptr->w) + ((sx - (bptr->x+bptr->w))/2));
				datadebugTraceLine(sx,sy,mx,sy,4);
				/* choose the shortest path around it */
				flowchartTraceRound(sx,sy,tx,ty,mx,bptr,level,reverse,1);
				}		
			}
		else	{
			if (!(bptr = flowchartWeBlock(sy,sx,tx,1))) {
				/* direct : no obstacles : go for it */
				datadebugTraceLine(sx,sy,tx,ty,5);
				}
			else	{
				/* obstacle */
				mx = (sx + ((bptr->x - sx)/2));
				datadebugTraceLine(sx,sy,mx,sy,6);
				/* choose the shortest path around it */
				flowchartTraceRound(sx,sy,tx,ty,mx,bptr,level,reverse,2);
				}
			}
		}
	else if ( sx == tx ) {
		/* its a possible vertical, direct, hit */
		/* check for eventual vertical obstacle */
		if ( sy < ty )
			bptr = flowchartNsBlock(sx,sy,ty,2);
		else	bptr = flowchartSnBlock(sx,sy,ty,2);
		if (!( bptr )) {
			/* its going straight home */
			datadebugTraceLine(sx,sy,tx,ty,7);
			}
		else	{
			/* we're gonna cut at the obstacle */
			if ( sy < ty )
				my = (bptr->y > VFE.tracepadding ? (bptr->y - VFE.tracepadding) : 0 );
			else	my = (bptr->y + bptr->h + VFE.tracepadding);
			datadebugTraceLine(sx,sy,sx,my,8);
			/* choose the shortest way round */
			if ((sx - bptr->x) < ((bptr->x+bptr->w)-sx)) {
				/* east end is nearer */
				mx = (bptr->x > VFE.tracepadding ? (bptr->x - VFE.tracepadding) : 0 );
				}
			else	{
				/* west end is nearer */
				mx = ((bptr->x+bptr->w)-sx);
				}
			datadebugTraceLine(sx,my,mx,my,9);
			flowchartTraceRoute(mx,my,tx,ty,level+1,reverse);
			}
		}
	else	{
		/* its sure its bender */
		if ( sx > tx ) { 
			/* is this the first and are we forward */
			if ((!( level )) && (!( reverse ))) {
				if ((sx - tx) > 10) 	
					mx = sx + 10; 
				else	mx = sx + ((sx -tx) / 2);
				datadebugTraceLine(sx,sy,mx,sy,10);

				/* check if we're going over or under */
				xx = (tx + ((mx - tx) / 2));
				if ((bptr = flowchartEwBlock(sy,mx,xx,2)) != (struct visual_flowchart_model *) 0 ) {
					if ((sy - bptr->y) > ((bptr->y+bptr->h)-sy))
						bottom =  (bptr->y+bptr->h+VFE.tracepadding);
					else	bottom = 0;						
					}
				else	bottom = 0;
				if (!( bottom )) {
					if ( ty > sy ) {
						if ((ty - sy ) > 20)
							my = (sy + 20);
						else	my = (sy + ((ty-sy)/2));
						}
					else if ((sy-ty) > 20 )
						my = (sy-20);
					else 	my = (sy - ((sy-ty)/2));


					if ( sy > ty )
						datadebugTracePoint(mx,sy,0);
					datadebugTraceLine(mx,sy,mx,my,11);
					if ( sy < my )
						datadebugTracePoint(mx,my,1);
					sx = mx; sy = my;
					}
				else	{
					my = bottom;
					datadebugTraceLine(mx,sy,mx,my,24);
					if ( sy < my )
						datadebugTracePoint(mx,my,8);
					sx = mx; sy = my;
					}
				}
			/* West <-- East */
			mx = (tx + ((sx - tx) / 2));
			/* check for horizontal obstacle */
			if (!(bptr = flowchartEwBlock(sy,sx,mx,2))) {
				/* check for eventual vertical obstacle */
				if ( sy < ty )
					bptr = flowchartNsBlock(mx,sy,ty,3);
				else	bptr = flowchartSnBlock(mx,sy,ty,3);
				if ( bptr ) {
					/* obstacle : beyond the west end */
					mx = ( bptr->x > VFE.tracepadding ? (bptr->x - VFE.tracepadding) : 0);
					}
				datadebugTraceLine(sx,sy,mx,sy,12);
				if ( reverse ) {
					datadebugTraceLine(mx,sy,mx,ty,13);
					if ( sy < ty )
						datadebugTracePoint(mx,ty,2);
					flowchartTraceRoute(mx,ty,tx,ty,level+1,reverse);
					}
				else	{
					if ( sy > ty ) {
						if ((sy - ty) > 20)
							my = ty+20;
						else	my = (ty + ((sy-ty)/2));
						}
					else	my = ( ty > 20 ? ty-20 : (ty / 2));
					datadebugTraceLine(mx,sy,mx,my,13);
					datadebugTraceLine(mx,my,tx,my,15);
					if ( sy > ty )
						datadebugTracePoint(tx,my,3);
					flowchartTraceRoute(tx,my,tx,ty,level+1,reverse);
					}
				}
			else	{			
				/* obstacle */
				mx = ((bptr->x+bptr->w) + ((sx - (bptr->x+bptr->w))/2));
				datadebugTraceLine(sx,sy,mx,sy,16);
				/* choose the shortest path around it */
				flowchartTraceRound(sx,sy,tx,ty,mx,bptr,level,reverse,3);
				}
			}
		else	{
			/* is this the first and are we forward */
			if ((!( level )) && ( reverse )) {
				if ( sx > 10 )
					mx = sx-10; 
				else	mx = (sx / 2);
				datadebugTraceLine(sx,sy,mx,sy,17);

				/* check if we're going over or under */
				xx = (mx + ((tx - mx) / 2));
				if ((bptr = flowchartWeBlock(sy,mx,xx,2)) != (struct visual_flowchart_model *) 0 ) {
					if ((sy - bptr->y) > ((bptr->y+bptr->h)-sy))
						bottom =  (bptr->y+bptr->h+VFE.tracepadding);
					else	bottom = 0;						
					}
				else	bottom = 0;
				if (!( bottom )) {
					if ( ty > sy ) {
						if ((ty - sy) > 20)
							my = sy+20;
						else	my = ((ty-sy)/2);
						}
					else if ( sy > 20 )
						my = sy-20;
					else	my = (sy/2);
					datadebugTraceLine(mx,sy,mx,my,18);
					sx = mx; sy = my;
					}
				else	{
					my = bottom;
					datadebugTraceLine(mx,sy,mx,my,24);
					sx = mx; sy = my;
					}
				}
			/* West --> East */
			mx = (sx + ((tx - sx) / 2));
			/* check for horizontal obstacle */
			if (!(bptr = flowchartWeBlock(sy,sx,mx,2))) {
				/* check for eventual vertical obstacle */
				if ( sy < ty )
					bptr = flowchartNsBlock(mx,sy,ty,4);
				else	bptr = flowchartSnBlock(mx,sy,ty,4);
				if ( bptr ) {
					/* obstacle : beyond the east end */
					mx = ( bptr->x + bptr->w + VFE.tracepadding );
					}
				datadebugTraceLine(sx,sy,mx,sy,19);
				if ( sy > ty )
					datadebugTracePoint(mx,sy,4);
				
				if ( mx < tx ) {
					if (!( reverse ))
						my = ty;
					else if ( sy > ty ) {
						if ((sy-ty) > 20)	
							my = ty + 20;
						else	my = ty + ((sy-ty)/2);
						}
					else if ((ty-sy) > 20)
						my = ty - 20;
					else	my = ty;
					datadebugTraceLine(mx,sy,mx,my,20);
					sx = mx; 
					if ( mx < tx ) {
						if ((tx - mx) > 20 )
							 mx += 20;
						else	mx += ((tx - mx) / 2);
						}
					else if ((mx - tx) > 20 )
						mx -= 20;
					else	mx -= ((mx -tx) / 2);
					sy = my;
					datadebugTraceLine(sx,sy,mx,sy,21);
					if ( sy < ty )
						datadebugTracePoint(mx,sy,5);
					flowchartTraceRoute(mx,sy,tx,ty,level+1,reverse);

					}
				else	{ 
					datadebugTraceLine(mx,sy,mx,ty,22);
					if ( sy < ty )
						datadebugTracePoint(mx,ty,6);
					flowchartTraceRoute(mx,ty,tx,ty,level+1,reverse);
					}
				}
			else	{
				/* obstacle */
				mx = (sx + ((bptr->x - sx)/2));
				datadebugTraceLine(sx,sy,mx,sy,23);
				/* choose the shortest path around it */
				if ( sy > ty )
					datadebugTracePoint(mx,sy,7);
				flowchartTraceRound(sx,sy,tx,ty,mx,bptr,level,reverse,4);
				}
			}
		}
	__f__T__r--;
	return;
}


#endif	/* _singflow_c */
	/* ----------- */

