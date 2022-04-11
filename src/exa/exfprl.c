#else
	workval1 = Indent;
	switch ( x ) {
		case 0 :	(void) clf_left();	break;
		case 1 :	(void) clf_right()	break;
		case 2 :	(void) clf_substr();	break;
		case 3 :	(void) clf_move();	break;
		case 4 :	(void) clf_swap();	break;
		}
#endif
