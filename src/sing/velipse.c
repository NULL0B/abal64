public	void	visual_elipse(int atx, int aty, int width, int height, int colour, int style )
{
	int	x;
	int	y;
	int	yy;
	int	rr;
	int	n;
	int	nx=0;
	int	nb=0;
	int	cumul;
	int	xadjust;
	int	adjust;
	int	yradius;

	yradius = (height/2);
	
	atx += (width/2);
	aty += (height/2);

	xadjust = (((width - height) * 10)/height);


	for ( 	adjust=0,cumul=0,y=(yradius-1); y > 0; y-- ) {
		x  = (yradius-y);

		if ( xadjust < 0 ) {
			cumul += xadjust;
			while ( cumul <= -10 ) {
				cumul += 10;
				adjust--;
				}
			}
		else if ( xadjust > 0 ) {
			cumul += xadjust;
			while ( cumul > 10 ) {
				cumul -= 10;
				adjust++;
				}
			}

		yy = (y*y);
		rr = ((yradius+adjust)*(yradius+adjust));

		while (1) {
			if ((n=((x*x) + yy)) < rr) {
				x++;
				continue;
				}
			else if ( n > rr )
				x--;
			break;
			}


		switch ( style & 7 ) {

			case	4	:	/* Top Left */
				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				filzone(atx-x,	aty-y,nb,1,colour);
				nx=x;
				break;
			case	5	: 	/* Top Right */
				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				filzone(atx+nx,	aty-y,nb,1,colour);
				nx=x;
				break;

			case	6	:	/* Bottom Left	*/
				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				filzone(atx-x,	aty+(y-1),nb,1,colour);
				nx=x;
				break;

			case	7	:	/* Bottom Right	*/
				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				filzone(atx+nx,	aty+(y-1),nb,1,colour);
				nx=x;
				break;


			case	0	:	/* standard outline */
				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				filzone(atx-x,	aty-y,nb,1,colour);
				filzone(atx+nx,	aty-y,nb,1,colour);
				filzone(atx-x,	aty+(y-1),nb,1,colour);
				filzone(atx+nx,	aty+(y-1),nb,1,colour);
				nx=x;
				break;

			case	1	:	/* standard filled  */
				filzone(atx-x,aty-y,x*2,1,colour);
				filzone(atx-x,aty+(y-1),x*2,1,colour);
				break;

			case	2	:	/* cursor  outline */

				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				filzone(atx-x,	aty-y,nb,1,colour);
				filzone(atx+nx,	aty-y,nb,1,colour);
				filzone(atx-x,	aty+(y-1),nb,1,colour);
				filzone(atx+nx,	aty+(y-1),nb,1,colour);
				nx=x;
				break;
			case	3	:	/* filled  curser  */
				xorzone(atx-x,aty-y,x*2,1,colour);
				xorzone(atx-x,aty+(y-1),x*2,1,colour);
				break;
			}

		}
	return;

}




