private	void * Where=(void*)0;
private	struct	timeval Now = { 0,0 };
private	struct	timeval Then = { 0,0 };
private	struct	timeval ReplayDelay = { 0,0 };
private	struct	timeval ReplayTime = { 0,0 };
private	struct	timeval RecordTime = { 0,0 };

private	FILE *	RecordHandle=(FILE *) 0;

private	FILE * ReplayHandle=(FILE *) 0;
private	int	ReplayItem=0;
private	int	ReplayPending=0;
private	int	ReplayEvent=0;
private	int	ReplayKey=0;
private	int	ReplayButton=0;
private	int	ReplaygColumn=0;
private	int	ReplaygRow=0;
private	int	ReplaytColumn=0;
private	int	ReplaytRow=0;

private	int	VisualUnGotEvent=0;

#define	MICROSECONDS 1000000

private	int	replay_xgr_getch();
private	int	capture_xgr_getch(int result);
private	int	standard_xgr_kbhit();
private	int	replay_xgr_kbhit();
public	int 	xgr_kbhit();

private	void	addtimeofday( struct timeval * a, struct timeval * b)
{
	a->tv_sec += b->tv_sec;
	a->tv_usec += b->tv_usec;
	while ( a->tv_usec >= MICROSECONDS ) {
		a->tv_sec++;
		a->tv_usec -= MICROSECONDS;
		}
	return;
}

private	void	subtimeofday( struct timeval * a, struct timeval * b)
{
	if ( b->tv_usec > a->tv_usec ) {
		a->tv_usec += MICROSECONDS;
		a->tv_sec--;
		}
	a->tv_usec -= b->tv_usec;
	a->tv_sec -= b->tv_sec;
	return;
}

private	int	cmptimeofday( struct timeval * a, struct timeval * b)
{
	if ( a->tv_sec > b->tv_sec )
		return( 1 );
	else if ( a->tv_sec < b->tv_sec )
		return( -1 );
	else if ( a->tv_usec > b->tv_usec )
		return(1);
	else if ( a->tv_usec < b->tv_usec )
		return(-1);
	else	return( 0 );
}

private	void	reset_replay_record()
{
	ReplayHandle = RecordHandle = (FILE*)0;
	return;
}

public	int	cancel_xgr_replay_record()
{
	if ( ReplayHandle != (FILE *) 0) {
		fclose( ReplayHandle );
		ReplayHandle = (FILE *) 0;
		}
	else if ( RecordHandle != (FILE *) 0) {
		fclose( RecordHandle ) ;
		RecordHandle = (FILE *) 0;
		}
	return((ReplayEvent=0));
}

public	int 	activate_xgr_record(char * nptr)
{
	cancel_xgr_replay_record();
	if ((!( nptr )) || (!( *nptr )))
		return(46);
	else if (!( RecordHandle = fopen( nptr,"w" ) ))
		return(46);
	else	{
		gettimeofday(&Now,Where);
		Then.tv_sec = Now.tv_sec;
		Then.tv_usec = Now.tv_usec;
		return(0);
		}
}

private	int	replay_xgr_integer( int * iptr )
{
	int	c;
	*iptr = 0;
	while (1) {
		switch ((c = fgetc(ReplayHandle))) {
			case	0	:
			case	-1	:
			case	0x001A	:
				return(cancel_xgr_replay_record());
			case	0x000C	:
			case	0x001C	:
			case	' '	:
			case	'\t'	:
			case	'\r'	:
			case	'\n'	:
				continue;
			}
		break;
		}
	while ((c >= '0') && ( c <= '9')) {
		*iptr = (( *iptr * 10 ) + ( c - '0' ));
		if ((c = fgetc(ReplayHandle)) <= 0)
			return(cancel_xgr_replay_record());

		}
	return(1);
}

private	int	replay_xgr_mouse_event(int code)
{
	mimo_set_event( ReplayEvent, ReplayButton,ReplaygColumn,ReplaygRow );
	return( code );
}

private	int	replay_xgr_event()
{
	int	c;
	if (!( ReplayHandle ))
		return( cancel_xgr_replay_record() );
	else if (!(replay_xgr_integer(&ReplayDelay.tv_sec)))
		return( cancel_xgr_replay_record() );
	else if (!(replay_xgr_integer(&ReplayDelay.tv_usec)))
		return( cancel_xgr_replay_record() );
	else	{
		gettimeofday(&ReplayTime,Where);
		addtimeofday(&ReplayTime,&ReplayDelay);
		if ((c = fgetc(ReplayHandle)) == 'k') {
			if (!( replay_xgr_integer(&ReplayKey) ))
				return( cancel_xgr_replay_record() );
			else	{
				//printf("***(%u) %u.%u key %u \r\n",++ReplayItem,ReplayDelay.tv_sec,ReplayDelay.tv_usec,ReplayKey);
				return((ReplayEvent=2));
				}
			}
		else if ( c != 'e' )
			return( cancel_xgr_replay_record() );
		else if (!( replay_xgr_integer(&ReplayEvent) ))
			return( cancel_xgr_replay_record() );
		else if (!( replay_xgr_integer(&ReplayButton) ))
			return( cancel_xgr_replay_record() );
		else if (!( replay_xgr_integer(&ReplaygColumn) ))
			return( cancel_xgr_replay_record() );
		else if (!( replay_xgr_integer(&ReplaygRow) ))
			return( cancel_xgr_replay_record() );
		else	{
			//printf("***(%u) %u.%u event %u %u %u %u \r\n",++ReplayItem,ReplayDelay.tv_sec,ReplayDelay.tv_usec,ReplayEvent,ReplayButton,ReplaygColumn,ReplaygRow);
			return( (ReplayKey=replay_xgr_mouse_event(256)) );
			}
		}
}

public	int 	activate_xgr_replay(char * nptr)
{
	cancel_xgr_replay_record();
	if ((!( nptr )) || (!( *nptr )))
		return(40);
	else if (!(ReplayHandle = fopen(nptr,"r")))
		return(40);
	else	{
		gettimeofday( &Now, Where );
		Then.tv_sec = Now.tv_sec;
		Then.tv_usec = Now.tv_usec;
		ReplayPending = replay_xgr_event();
		return(0);
		}
}

/*	----------------------------------	*/
/*	      x g r _ g e t c h (   )		*/
/*	----------------------------------	*/
/*	Character Input 	:	CI	*/
/*	----------------------------------	*/
private	int	standard_xgr_getch()
{
	int	result;
	/* display the cursor if required */
	/* ------------------------------ */
	if ( Gigo.cursing & 1)	xgr_cursor(1);

	/* go and wait for an event */
	/* ------------------------ */
	result = wait_event();

	/* hide the cursor if required */
	/* --------------------------- */
	if ( Gigo.cursing & 1)	xgr_cursor(1);

	/* detect capturing of logical events */
	/* ---------------------------------- */
	if (!( Gigo.replaying & 4 ))
		return(result);
	else	return( capture_xgr_getch( result ) );
}

public	int 	xgr_getch()
{
	int	x=0;
	/* Test for replaying a CICO text stream */
	/* ------------------------------------- */
	if ( Gigo.replaying & 1 )
		return( local_x_getch() );

	/* Test for replaying a GIGO  X11 stream */
	/* ------------------------------------- */
	else if ( Gigo.replaying & 2 ) {

		while ( test_event() ) {
			wait_event();
			perform_low_level_flush();
			}
		perform_low_level_flush();
		return( replay_xgr_getch() );
		}
	/* Normal non bufferised stuff */
	/* --------------------------- */
	else	return( standard_xgr_getch() );
}

private	int	replay_xgr_getch()
{
	if ((!( ReplayPending ))
	&&  (!( ReplayPending = replay_xgr_event() ))) {
		Gigo.replaying &= ~2;
		return( standard_xgr_getch() );
		}
	else	{
		while (1) {
			gettimeofday(&Now,Where);
			if ( cmptimeofday( &Now, &ReplayTime ) >= 0 )
				break;
			else if ( test_event() )
				wait_event();
			}
		if ( test_event() )
			wait_event();
		ReplayPending=0;
		//printf("replay getch : %u\r\n",ReplayKey);
		if ( ReplayKey == 256 ) {
			mimo_set_event( ReplayEvent, ReplayButton,ReplaygColumn,ReplaygRow );
			}
		return( ReplayKey );
		}
}

private	int	capture_xgr_getch(int result)
{
	if ( RecordHandle ) {
		gettimeofday(&Now,Where);
		RecordTime.tv_sec = Now.tv_sec;
		RecordTime.tv_usec = Now.tv_usec;
		subtimeofday(&RecordTime,&Then);
		Then.tv_sec = Now.tv_sec;
		Then.tv_usec = Now.tv_usec;
		if ( result != 256 )
			fprintf(RecordHandle,"%lu %lu k %u\n",RecordTime.tv_sec,RecordTime.tv_usec,result);
		else	{
			fprintf(RecordHandle,"%lu %lu e %u %u %u %u\n",RecordTime.tv_sec,RecordTime.tv_usec,
				get_mimo_type(),get_mimo_par(),
				get_mimo_column(),get_mimo_row());
			}
		}
	return( result );
}


/*	----------------------------------	*/
/*	      x g r _ k b h i t (   )		*/
/*	----------------------------------	*/
/*	Test For Character Waiting : TPCI	*/
/*	----------------------------------	*/

private	int	standard_xgr_kbhit()
{
	int	result;

	if (( Gigo.cursing & 3)==3)
		xgr_cursor(1);
	result = test_event();
	if (( Gigo.cursing & 3)==3)
		xgr_cursor(1);
	return( result );
}

private	int	replay_xgr_kbhit()
{
	if (!( ReplayHandle ))
		return( standard_xgr_kbhit() );
	if (!( ReplayPending )) {
		if  (!( ReplayPending = replay_xgr_event() )) {
			cancel_xgr_replay_record();
			return( standard_xgr_kbhit() );
			}
		}

	if ( test_event() )
		wait_event();
	perform_low_level_flush();

	gettimeofday(&Now,Where);
	if (cmptimeofday( &Now,&ReplayTime) >= 0) {
		return(1);
		}
	else	{
		return(0);
		}
}

public	int 	xgr_kbhit()
{
	if ( Gigo.replaying & 1 )
		return( local_x_kbhit() );
	else if ( Gigo.replaying & 2 ) {
		//printf("flushing test event\r\n");
		(void) test_event();
		return( replay_xgr_kbhit() );
		}
	else	return( standard_xgr_kbhit() );
}


