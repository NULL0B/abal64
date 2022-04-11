#ifndef	_circle_c
#define	_circle_c

#include "pixel.h"
#ifndef WIN32
extern filzone(int,int,int,int,int);
extern xorzone(int,int,int,int,int);
#endif

void	drawcircle(int atx, int aty, int width, int height, int colour, int style )
{
	int	hw;	/* halfwidth 	*/
	int	hh;	/* halfheight	*/
	int	x;
	int	y;
	int	yy;
	int	rr;
	int	n;
	int	nx=0;
	int	nb=0;
	int	radius;
	int	cpt = (XGC.scale) ? XGC.scale : 1;
	int	xLeft;
	int	yTop;

	xLeft = atx;
	yTop  = aty;
	
	hw = (width/2);
	hh = (height/2);
	atx += hw;
	aty += hh;

	if ( width > height )
		radius = hh+1;
	else	radius = hw+1;

while(cpt)
	{
	nx=0;
	nb=0;
	rr = (radius*radius);

	for ( 	y=(radius-1); y > 0; y-- ) {

		yy = (y*y);
		x  = (radius-y);
		while (1) {
			if ((n=((x*x) + yy)) < rr) {
				x++;
				continue;
				}
			else if ( n > rr )
				x--;
			break;
			}

		switch ( style & 0x1F ) {
			case	12	:
				if ((nb = (hw - (x-nx))) <= 0)
					nb=1;
				filzone(atx-hw,aty-y,nb,1,colour);
				nx=x;
				break;

			case	4	:	/* Top Left */
				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				filzone(atx-x,	aty-y,nb,1,colour);
				nx=x;
				break;

			case	8	:
				filzone(atx-x,	aty-y,x,1,colour);
				nx=x;
				break;
				
			case	13	:
				if ((nb = (hw - (x-nx))) <= 0)
					nb=1;
				filzone(atx,aty-y,nb,1,colour);
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

			case	9	:
				filzone(atx,aty-y,x,1,colour);
				nx=x;
				break;

			case	14	:
				if ((nb = (hw - (x-nx))) <= 0)
					nb=1;
				filzone(atx-hw,aty+y,nb,1,colour);
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

			case	10	:
				filzone(atx-x,	aty+(y-1),x,1,colour);
				nx=x;
				break;

			case	15	:
				if ((nb = (hw - (x-nx))) <= 0)
					nb=1;
				filzone(atx,aty,nb,1,colour);
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

			case	11	:
				filzone(atx,	aty+(y-1),x,1,colour);
				nx=x;
				break;

			case	24	:	/* shaded outline   */
				if ((nb = (x-nx)) <= 0) {
					nb=1;
					nx--;
					}
				shadzone(atx-x,	aty-y,nb,1,colour);
				shadzone(atx+nx,aty-y,nb,1,colour);
				shadzone(atx-x,	aty+(y-1),nb,1,colour);
				shadzone(atx+nx,aty+(y-1),nb,1,colour);
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

			case	17	:	/* inverse filled   */
				if ((hw - x) > 0) {
					filzone(atx-hw,	aty-y,(hw-x),1,colour);
					filzone(atx+x, aty-y,(hw-x),1,colour);
					filzone(atx-hw,	aty+(y-1),(hw-x),1,colour);
					filzone(atx+x, aty+(y-1),(hw-x),1,colour);
					}
				nx=x;
				break;
			case	25	:	/* inverse shaded   */
				if ((hw - x) > 0) {
					shadzone(atx-hw,aty-y,(hw-x),1,colour);
					shadzone(atx+x, aty-y,(hw-x),1,colour);
					shadzone(atx-hw,aty+(y-1),(hw-x),1,colour);
					shadzone(atx+x, aty+(y-1),(hw-x),1,colour);
					}
				nx=x;
				break;
			case	23	:	/* shaded filled    */
				shadzone(atx-x,aty-y,x*2,1,colour);
				shadzone(atx-x,aty+(y-1),x*2,1,colour);
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
	radius--;
	cpt--;
		}
	return;

}

#endif	/* _circle_c */
	/* --------- */


