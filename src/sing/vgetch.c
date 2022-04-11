#ifndef	_VGETCH_C
#define	_VGETCH_C

private	LONG	Now=0L;
private	LONG	Then=0L;

private	FILE *	RecordHandle=(FILE *) 0;
private	LONG	RecordTime=0L;

private	FILE * ReplayHandle=(FILE *) 0;

private	WORD	ReplayPending=0;
private	WORD	ReplayEvent=0;
private	WORD	ReplayKey=0;
private	WORD	ReplayButton=0;
private	WORD	ReplayColumn=0;
private	WORD	ReplayRow=0;
private	WORD	ReplayDelay=0;
private	LONG	ReplayTime=0L;

private	WORD	VisualUnGotEvent=0;
int gwb_lastcar=-1;

public 	void	reset_replay_record()
{
	ReplayHandle = RecordHandle = (FILE*)0;
	return;
}

public 	int	cancel_replay_record()
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

public 	int 	activate_record(char * nptr)
{
	cancel_replay_record();
	if ((!( nptr )) || (!( *nptr )))
		return(46);
	else if (!( RecordHandle = fopen( nptr,"w" ) ))
		return(46);
	else	{
		Now=Then = time((long*)0);			
		return(0);
		}
}

private	int	replay_integer( WPTR iptr )
{
	int	c;
	*iptr = 0;
	while (1) {
		switch ((c = fgetc(ReplayHandle))) {
			case	0	:
			case	-1	:
			case	0x001A	:
				return(cancel_replay_record());
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
			return(cancel_replay_record());

		}
	return(1);
}

private	int	replay_event()
{
	int	c;
	if (!( ReplayHandle ))
		return( cancel_replay_record() );
	else if (!(replay_integer(&ReplayDelay)))
		return( cancel_replay_record() );
	else	{
		ReplayTime = (time((LONG*)0) + (LONG)ReplayDelay);
		if ((c = fgetc(ReplayHandle)) == 'K') {
			if (!( replay_integer(&ReplayKey) ))
				return( cancel_replay_record() );
			else	return((ReplayEvent=2));
			}
		else if ( c != 'E' )
			return( cancel_replay_record() );
		else if (!( replay_integer(&ReplayEvent) ))
			return( cancel_replay_record() );
		else if (!( replay_integer(&ReplayButton) ))
			return( cancel_replay_record() );
		else if (!( replay_integer(&ReplayColumn) ))
			return( cancel_replay_record() );
		else if (!( replay_integer(&ReplayRow) ))
			return( cancel_replay_record() );
		else	return( (ReplayKey=256) );
		}
}

public 	int 	activate_replay(char * nptr)
{
	cancel_replay_record();
	if ((!( nptr )) || (!( *nptr )))
		return(40);
	else if (!(ReplayHandle = fopen(nptr,"r")))
		return(40);
	else	{
		Now=Then=time((long*)0);			
		ReplayPending = replay_event();
		return(0);
		}
}

public	int	visual_kbhit()
{
	if ( VisualUnGotEvent != 0 )
		return( 1 );
	else if (!( ReplayHandle ))
		return( mimo_kbhit() );
	if ((!( ReplayPending ))
	&&  (!( ReplayPending = replay_event() ))) {
		cancel_replay_record();
		return( mimo_kbhit() );
		}
	if ((Now = time((LONG*)0)) >= ReplayTime)
		return(1);
	else	return(0);
}

public	int	visual_getch()
{
	int	result;
	if ((result = VisualUnGotEvent) != 0 ) {
		VisualUnGotEvent = 0;
		gwb_lastcar=result;
		return( result );
		}
	else if (!( ReplayHandle )) {
		result = mimo_getch();
		if ( RecordHandle ) {
			RecordTime = ((Now = time((LONG*) 0)) - Then);
			Then = Now;
			if ( result != 256 )
				fprintf(RecordHandle,"%lu K %u\n",RecordTime,result);
			else	{
				fprintf(RecordHandle,"%lu E %u %u %u %u\n",RecordTime,
					get_mimo_type(),get_mimo_par(),
					get_mimo_column(),get_mimo_row());
				}
			}
		gwb_lastcar=result;
		return( result );	
		}
	else	{
		while (mimo_kbhit()!=0) {
			if ( mimo_getch() == 27 ) {
				while (1) {
					switch ( mimo_getch() ) {
						case	13	:
							cancel_replay_record();
						case	27	:
							break;
						default		:
							continue;
						}
					break;
					}
				break;
				}
			}

		if ((!( ReplayPending ))
		&&  (!( ReplayPending = replay_event() ))) {
			cancel_replay_record();
			result = mimo_getch();
			}
		while ((Now = time((LONG*)0)) < ReplayTime);
		ReplayPending = 0;
		gwb_lastcar=ReplayKey;
		return( ReplayKey );
		}
}

public	int	visual_event(int item)
{
	if (!( ReplayHandle )) {
		switch ( item ) {
			case	1	:  
				if ((item = get_mimo_type()) == _MIMO_DOWN)
					x_event(33);
				else if ( item == _MIMO_UP )
					x_event(34);
				return( item );

			case	2	: return( get_mimo_par() );
			case	3	: return( get_mimo_lin() );
			case	6	: return( get_mimo_row() );
			case	4	: return( get_mimo_col() );
			case	7	: return( get_mimo_column());
			default		: return( 0 );
			}
		}
	else	{
		switch ( item ) {
			case	1	: return( ReplayEvent );
			case	2	: return( ReplayButton);
			case	3	:
				case	6	: return( ReplayRow );
			case	4	:
			case	7	: return( ReplayColumn);
			default		: return( 0 );
			}
		}
}	

public	void	visual_unget_event( int event )
{
	VisualUnGotEvent = event;
	return;
}


#endif	/* _VGETCH_C */
	/* --------- */ 


