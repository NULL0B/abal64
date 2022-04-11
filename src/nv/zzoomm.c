	if ((scolinc = (((unsigned int)columncount * 10) / (unsigned int)columns)) == 0)
		scolinc = 1;

	if ((srowinc = (((unsigned int)rowcount * 10) / (unsigned int)rows)) == 0)
		srowinc = 1;

	if (((trptr = iptr->first))
	&&  ((srptr = first))
	&&  ((tptr  = trptr->pixels))
	&&  ((sptr  = srptr->pixels)))

	for ( 	srow=0,trow=0; 
		trow < rows; 
		trow++		) {

		scol = 0;

		if ( sptr )
			pixel = *(sptr + scol);
		else	pixel = 0;


		for ( 	scoltot=0,tcol=0; 
			tcol < columns; 	
			tcol++ 			) {

			// Store Pixel to Target
			// ---------------------
			*( tptr + tcol ) = pixel;

			/* Advance Target Column Control */
			/* ----------------------------- */
			scoltot += scolinc;
			if ( scoltot > 10 ) {
				while ( scoltot > 10 ) {
					if ( scol < columncount )
						scol++;
					scoltot-= 10;
					}
				if (( scol < columncount )
				&&  ( sptr != (char *) 0 ))
					pixel = *(sptr + scol );
				else	pixel = 0;
				}
			}

		/* Advance Source Row Control */
		/* -------------------------- */
		srowtot += srowinc;
		if ( srowtot > 10 ) {
			while ( srowtot > 10 ) {
				if ( srow < rowcount ) {
					srow++;
					if ( srptr ) {
						if ((srptr = srptr->next))
							sptr = srptr->pixels;
						}
					}
				srowtot-= 10;
				}
			}
		/* Advance Target Row Control */
		/* -------------------------- */
		if (!(trptr = trptr->next))
			break;
		else if (!(tptr = trptr->pixels))
			break;
		}
