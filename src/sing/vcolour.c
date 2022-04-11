#ifndef	_vcolour_c
#define	_vcolour_c

extern	BPTR thispalette;

int	visual_colour( int cmd, BPTR buffer, int first, int last )
{
	int	i;
	BPTR	pptr=thispalette;
	switch ( cmd ) {

		case	0	:	/* Get Colours 	*/
			if (( first <= 0     )
			||  ( first >  256   )
			||  ( last  <= 0     )
			||  ( last  >  256   )
			||  ( last  <  first ))
				return(55); 
			first--, last--;
			pptr += (first*4);
			for ( ; first <= last; first++ ) {
				for ( i=0; i < 4; i++ )
					*(buffer +i) = *(pptr+i);
				buffer += i;
				pptr += i;
				}
			return(0);
				
		case	1	:	/* Set Colours 	*/
			if (( first <= 0     )
			||  ( first >  256   )
			||  ( last  <= 0     )
			||  ( last  >  256   )
			||  ( last  <  first ))
				return(55);

			first--, last--;
			pptr += (first*4);
			for ( ; first <= last; first++ ) {
				for ( i=0; i < 4; i++ )
					*(pptr+i) = *(buffer +i);
				buffer += i;
				pptr += i;
				}
			return(0);

		case	2	:	/* get red	*/
			if (( first <= 0     )
			||  ( first >  256   ))
				return(0); 
			first--, last--;
			pptr += (first*4);
			return( (*pptr & 0x00FF));
		case	3	:	/* get green	*/
			if (( first <= 0     )
			||  ( first >  256   ))
				return(0); 
			first--, last--;
			pptr += (first*4);
			return( (*(pptr+1) & 0x00FF));

		case	4	:	/* get blue	*/
			if (( first <= 0     )
			||  ( first >  256   ))
				return(0); 
			first--, last--;
			pptr += (first*4);
			return( (*(pptr+2) & 0x00FF));
			
		case	5	:	/* put red	*/
		case	6	:	/* put green	*/
		case	7	:	/* put blue	*/

		default		:	/* unknown	*/
			return(56);
		}

}

#endif	/* _vcolour_c */


