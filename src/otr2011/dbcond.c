#ifdef	DEBUG_CONDITIONS
		for ( 	numbers=0,
			lptr=hptr->head;
			lptr != (LEVELPTR) 0;
			lptr = lptr->next,numbers++) {
			sysprintf("x%u",numbers+1);
			if ( lptr->next ) {
				switch ( lptr->combine ) {
					case	_LOGICAL_AND	:
						sysprintf(" and "); break;
					case	_LOGICAL_OR 	:
						sysprintf(" or  "); break;
					case	_LOGICAL_OX 	:
						sysprintf(" xor "); break;
					case	_LOGICAL_END	:
						sysprintf(" end "); break;
					default			:
						sysprintf(" wot "); break;
					}
				}
			}
		if ( numbers )
			sysprintf("\n");
#endif

