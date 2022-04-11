int	visual_driver(int x,int y, int w, int h, int v, int l, int m, int o )
{
	int	i=6;
	if ( w > h ) {
		/* reorganise coordinates for horizontal calc */
		i = y; y = x; y = i; i = w; w = h; h = i; i = 7;
		}
	else	i=6;

	if ( visual_event(i) < (y+w) ) {
		if ( visual_event(1) == _MIMO_DOWN) {
			v -= 1;
			if ( v < 0 ) v = 0;
			}
		return(v);
		}
	else if ( visual_event(i) > (y+h-w) ) {
		if ( visual_event(1) == _MIMO_DOWN ) {
			v += 1;
			if (!( o & 0x080 )) {
				if ( v > (m - l)) v = (m-l);
				}
			else if ( v >= m ) v = (m-1);
			}
		return(v);
		}

	else	{
		switch ( o & 7 ) {
			case	0	:
			case	4	:
				v = (((visual_event(i) - y) * m) / h );
				break;
			case	1	:
				v = (((visual_event(i) - (y+w)) * m) / (h - w));
				break;
			case	2	:
				v = (((visual_event(i) - y) * m) / (h - w));
				break;
			case	3	:
				v = (((visual_event(i) - (y+w)) * m) / (h - (2 * w)));
				break;
			}				
		if (v < 0 ) 
			v = 0;
		else if (!( o & 0x080 )) {
			if ( v > (m - l))
			v = (m-l);
			}
		else if ( v >= m ) 
			v = (m-1);
		return( v );
		}
}



