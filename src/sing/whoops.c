
struct visual_database_model * databaseEwBlock(int y, int sx, int tx)
{
	struct visual_database_model * bptr=(struct visual_database_model *) 0;
	struct visual_database_model * mptr;
	for ( 	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		if ( mptr->x >= sx )
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
	return( bptr );
}

struct visual_database_model * databaseWeBlock(int y, int sx, int tx)
{
	struct visual_database_model * bptr=(struct visual_database_model *) 0;
	struct visual_database_model * mptr;
	for ( 	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		if ( mptr->x >= tx )
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
	return( bptr );
}

struct visual_database_model * databaseNsBlock(int x, int sy, int ty)
{
	struct visual_database_model * bptr=(struct visual_database_model *) 0;
	struct visual_database_model * mptr;
	for ( 	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		if ( (mptr->y+mptr->h) <= sy )
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
	return( bptr );
}

struct visual_database_model * databaseSnBlock(int x, int sy, int ty)
{
	struct visual_database_model * bptr=(struct visual_database_model *) 0;
	struct visual_database_model * mptr;
	for ( 	mptr = VDE.first;
		mptr != (struct visual_database_model *) 0;
		mptr = mptr->next ) {
		if ( mptr->y >= sy )
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
	return( bptr );
}

/*	------------------------------		*/
/*	Traces route to WEST from EAST		*/
/*	------------------------------		*/
/*	   	WEST <--  EAST
/*	------------------------------		*/
void	E2WTraceRoute(int sx, int sy, int tx, int ty )
{
	struct visual_database_model * bptr;
	int	mx;
	mx = (tx + ((sx - tx) / 2));
	if ((bptr = databaseEwBlock(sy,sx,mx)) != (struct visual_database_model *) 0)
		mx = ((bptr->x+bptr->w) + ((sx - (bptr->x+bptr->w))/2));
	databaseTraceLine(sx,sy,mx,sy);
	databaseTraceLine(mx,sy,mx,ty);
	if ( sy < ty )
		databaseTracePoint(mx,ty);
	databaseTraceLine(mx,ty,tx,ty);
	return;
}

/*	------------------------------		*/
/*	Traces route from WEST to EAST		*/
/*	------------------------------		*/
/*	   	WEST ---> EAST
/*	------------------------------		*/
void	W2ETraceRoute(int sx, int sy, int tx, int ty )
{
	struct visual_database_model * bptr;
	int	mx;
	mx = (sx + ((tx - sx) / 2));
	if ((bptr = databaseWeBlock(sy,sx,mx)) != (struct visual_database_model *) 0)
		mx = (sx + ((bptr->x - sx)/2));
	databaseTraceLine(sx,sy,mx,sy);
	if ( sy > ty )
		databaseTracePoint(mx,sy);
	databaseTraceLine(mx,sy,mx,ty);
	databaseTraceLine(mx,ty,tx,ty);
	return;
}

void	controlTraceRound(int sx,int sy,int tx,int ty,int mx,struct visual_database_model * bptr)
{
	int	my;
	if ((sy-bptr->y) < ((bptr->y+bptr->h)-sy)) {
		/* around the top */
		my = (bptr->y >= 5 ? (bptr->y-5) : 0);
		databaseTraceLine(mx,sy,mx,my);
		controlTraceRoute(mx,my,tx,ty);					
		}
	else	{
		/*around the bottom */
		my = (bptr->y+bptr->h+5);
		databaseTraceLine(mx,sy,mx,my);
		controlTraceRoute(mx,my,tx,ty);					
		}
	return;
}

void	controlTraceRoute(int sx, int sy, int tx, int ty )
{
	struct visual_database_model * bptr;
	int	mx;
	int	my;
	if ( sy == ty ) {
		if ( sx > tx ) {
			if (!(bptr = databaseEwBlock(sy,sx,tx))) {
				/* direct : no obstacles */
				databaseTraceLine(sx,sy,tx,ty);
				}
			else	{
				/* obstacle */
				mx = ((bptr->x+bptr->w) + ((sx - (bptr->x+bptr->w))/2));
				databaseTraceLine(sx,sy,mx,sy);
				/* choose the shortest path around it */
				controlTraceRound(sx,sy,tx,ty,mx,bptr);
				}		
			}
		else	{
			if (!(bptr = databaseWeBlock(sy,sx,tx))) {
				/* direct : no obstacles */
				databaseTraceLine(sx,sy,tx,ty);
				}
			else	{
				/* obstacle */
				mx = (sx + ((bptr->x - sx)/2));
				databaseTraceLine(sx,sy,mx,sy);
				/* choose the shortest path around it */
				controlTraceRound(sx,sy,tx,ty,mx,bptr);
				}
			}
		}
	else	{
		if ( sx > tx )
			E2WTraceRoute(sx,sy,tx,ty);
		else	W2ETraceRoute(sx,sy,tx,ty);
		}
	return;
}


