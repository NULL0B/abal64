int	rgbtoycrcb( int v, char * buffer )
{
	int	r=0;
	int	g=0;
	int	b=0;
	char *  pptr;
	if (( v >= 0 ) && ( v <= 255)) {
		pptr = (buffer + (v*4));
		if ((r = (*(pptr + 3) & 0x00FF)) != 0)
			return(r);
		else 	{
			r = (*pptr & 0x00FF);
			g = (*(pptr+1) & 0x00FF);
			b = (*(pptr+2) & 0x00FF);
			return((*(pptr+3) = ((r/4)+(g/2)+(b/8))));
			}
		}
	else	return( 0 );
}


