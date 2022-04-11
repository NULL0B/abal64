
/* -------------------------------------------------------------------
 * DISPLAY_CORRESPONDANCES
 *
 *	Affiche une page de source et gere les actions utilisateur
 *
 *	E/ pointeur sur la description de la ligne en cours
 *	   mode operatoire (0 = execution)
 *	S/ caractere designant l'action externe a effectuer
 *
 * ------------------------------------------------------------------- */

EXAWORD display_correspondances(linfos,opmode)
CORRESPTR linfos;
EXAWORD opmode;
{
	EXAWORD		trace_toggle=0;
	EXAWORD		trace_start=0;
	EXAWORD		c;
	EXAWORD		lno;
	EXAWORD		lnd;
	EXAWORD		actpos;
	EXAWORD		prv;
	EXAWORD		exp;
	EXAWORD		topcol=1;
	EXAWORD		toplin=5;
	EXAWORD		nblin;
	EXAWORD		nbcol;
	CORRESPTR	zinfos;
	CORRESPTR	tinfos;
	CORRESPTR	finfos;

	/* Adjust line count to avoid observation display */
	nbcol = ScreenCol;
	nblin = avoid_observations(ScreenLin - 8);

	/* Is the page still valid ? */
	if (fsame != 0xFFFF) {
		/* Is the expected line within the current page ? */
		for (c = 0 ; c < nblin ; c++) {
			/* Is this the exact line ? */
			if (ZoomLine[c] == linfos)	break;
		}
		if (c < nblin)	fsame = c;
		else {
  			exp = linfos->tcode_offset;
			for (prv = 0 , c = 0 ; c < nblin ; c++) {
				/* Is the code before next line ? */
				if (ZoomLine[c] == (CORRESPTR)0)	continue;
				if ((exp > ZoomLine[prv]->tcode_offset) &&
				    (exp < ZoomLine[c]->tcode_offset)) {
					c = prv;
					break;
				}
				prv = c;
			}
			if (c < nblin)	fsame = c;
			else		fsame = 0xFFFF;
		}
	}

	/* Reload pointers from backup or scratch */
	if (fsame == 0xFFFF)	{ kinfos = tinfos = linfos; }
	else			{ tinfos = linfos; lno = lnd = fsame; }

	/* Forever... */
	correspondance_header(topcol,toplin,nbcol,nblin,opmode);
	actpos = 1;
	while ( 1 ) {
		/* Display page if code has changed */
		if (fsame == 0xFFFF) {
			draw_correspondance_page(topcol,toplin,nbcol,nblin,kinfos);
			
			/* Retrieve debugged line */
			for (c = 0 ; c < nblin ; c++) {
				if (ZoomLine[c] == linfos)	break;
			}
			if (c >= nblin)	{ lnd = 0xFFFF; }
			else		{ lnd = c; }
			
			/* Set current line if changed */
			if (actpos) {
				tinfos = kinfos;
				for (c = 0 ; c < nblin ; c++) {
					if (ZoomLine[c] == tinfos)	break;
				}
				if (c >= nblin)	{ lno = 0; }
				else		{ lno = c; }
			}
		}
		fsame = actpos = 0;
		        
		/* Display current selection */
		if (lnd != 0xFFFF)
			show_correspondance(2,topcol,toplin+1,lnd,nbcol,nblin,kinfos);
		if (lno != lnd)		
			show_correspondance(1,topcol,toplin+1,lno,nbcol,nblin,kinfos);

		/* Get user action */
		c = mouse_or_keyboard();

		/* Reset current selection */
		if (lnd != 0xFFFF)
			show_correspondance(0,topcol,toplin+1,lnd,nbcol,nblin,kinfos);
		if (lno != lnd)		
			show_correspondance(0,topcol,toplin+1,lno,nbcol,nblin,kinfos);

		/* Depending on what the user intends to do... */
		switch (c) {
			case '-'    :	 
				if (opmode == 0) {
					pop_mouse();
					previous_correspondance();
					correspondance_header(topcol,toplin,nbcol,nblin,opmode);
					}
				actpos = fsame = 0xFFFF;
				break;

			case '?'    :
				alter_hexa_switch();
				break;

			case CTRL_H :
				view_help_screen(0);
				pop_mouse();
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				fsame = 0xFFFF;
				break;
				
			case CTRL_D :
				if (DbMouse.position == 0)	break;
				if ((finfos = ZoomLine[(DbMouse.position-1)]) != (CORRESPTR) 0) {
					tinfos = finfos;
					lno = DbMouse.position - 1;
				}
				else	break;
				if (current_mouse_click() != 2)	break;
	
			case CTRL_M	:
				pop_mouse();
				edit_correspondance_file(tinfos);
				fsame = 0xFFFF;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_F :
				finfos=kinfos;
				find_correspondance(kinfos);
				actpos = fsame = 0xFFFF;
				kinfos=finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_L :
				kinfos = tinfos = linfos;
				actpos = fsame = 0xFFFF;
				break;

			case CTRL_Q :
				if ((opmode == 0) &&  (tinfos != (CORRESPTR)0)) {
 					set_break_point(0x0002,tinfos);
					pop_mouse();
					return(0x0018);
				}
				break;

			case CTRL_I :
				if (opmode == 0) {
					if (linfos->nature) {
						if ((zinfos = pseudo_step(linfos)) != (CORRESPTR)0) {
		 					set_break_point(0x0002,zinfos->next);
							pop_mouse();
							return(0x0018);
							}
						}
					else
					if (linfos->next != (CORRESPTR)0) {
	 					set_break_point(0x0002,linfos->next);
						pop_mouse();
						return(0x0018);
					}
				}
				break;

			case CTRL_J :
				finfos = kinfos;
				stream_close(_WORK_STREAM);
				pop_mouse();
				symbols_browser();
				fsame = 0xFFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_C :
				for (c = 0 ; c < 8 ; c++) {
					finfos = get_next_line(tinfos);
					if (finfos == (CORRESPTR)0)	break;
					else	tinfos = finfos;
				}
				for (c = 0 ; c < nblin ; c++) {
					if (ZoomLine[c] == tinfos)	break;
				}
				if (c >= nblin)	{ kinfos = tinfos; fsame = 0xFFFF; }
				else		{ lno = c; }
				actpos = 1;
				break;
				
			case CTRL_R :
				for (c = 0 ; c < 8 ; c++) {
					finfos = get_prev_line(tinfos);
					if (finfos == (CORRESPTR)0)	break;
					else	tinfos = finfos;
				}
				for (c = 0 ; c < nblin ; c++) {
					if (ZoomLine[c] == tinfos)	break;
				}
				if (c >= nblin)	{ kinfos = tinfos; fsame = 0xFFFF; }
				else		{ lno = c; }
				actpos = 1;
				break;

			case CTRL_Z	:
				alter_zoom_switch();
				actpos = fsame = 0xFFFF;
				break;
			
			case CTRL_G :
				finfos = kinfos;
				pop_mouse();
				symbols_selector(CTRL_G);
				fsame = 0xFFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_P :
				finfos = kinfos;
				pop_mouse();
				symbols_selector(CTRL_P);
				fsame = 0xFFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_S :
				finfos = kinfos;
				pop_mouse();
				symbols_selector(CTRL_S);
				fsame = 0xFFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_V :
				if (opmode == 0) {
					finfos = kinfos;
					pop_mouse();
					symbols_selector(CTRL_V);
					fsame = 0xFFFF; kinfos = finfos;
					correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				}
				break;
				
			case CTRL_Y :
				c  = 0; 
			case CTRL_A  :
			case CTRL_B  :
				set_break_point(c,tinfos);
				break;

			case CTRL_U	:
				pop_mouse();
				left_string(topcol,ScreenLin-2,nbcol,(BPTR)" ");
				Observe(1);
				nblin = avoid_observations(ScreenLin - 8);
				fsame = 0xFFFF;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				left_string(topcol,ScreenLin-2,nbcol,(BPTR)" ");
				Observe(0);
				break;

			case CTRL_N  :
				pop_mouse();
				actpos = fsame = 0xFFFF;
				if ((offer_list_menu(opmode) != 0)
				&&  ((finfos = check_correspondances()) != (CORRESPTR) 0)) {
					kinfos = linfos = finfos;
				}
				actpos = fsame = 0xFFFF;
				left_string(topcol,ScreenLin-2,nbcol,(BPTR)" ");
				Observe(0);
				nblin = avoid_observations(ScreenLin - 8);
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_E	:
				finfos = get_next_line(tinfos);
				if (finfos != (CORRESPTR)0) {
					tinfos = finfos;
					actpos = 1;
					for (c = 0 ; c < nblin ; c++) {
						if (ZoomLine[c] == tinfos)	break;
					}
					if (c >= nblin)	{ kinfos = tinfos; fsame = 0xFFFF; }
					else		{ lno = c; }
				}
				break;

			case CTRL_K	:
				finfos = get_prev_line(tinfos);
				if (finfos != (CORRESPTR)0) {
					tinfos = finfos;
					actpos = 1;
					for (c = 0 ; c < nblin ; c++) {
						if (ZoomLine[c] == tinfos)	break;
					}
					if (c >= nblin)	{ kinfos = tinfos; fsame = 0xFFFF; }
					else		{ lno = c; }
				}
				break;

			case CTRL_T	:
				if (trace_toggle) {
					trace_to_here(trace_start,tinfos); 
					trace_toggle = 0;
				}
				else	{
					Verbose((BPTR)interface_message(50));
					trace_start  = tinfos->tcode_offset;
					trace_toggle = 1;
				}
				break;

			case CTRL_O	:
				c = 0x0020;
			case CTRL_X	:
			case 0x0020	:
				
			default 	:
				if ((c != 0x0020) && (c != CTRL_X)) {
					actpos = fsame = 0xFFFF;
				}
				pop_mouse();
				return(c);
		}
	}
}


/* -------------------------------------------------------------------
 * GET_NEXT_LINE
 *
 *	Recupere un pointeur sur la description de la ligne suivante.
 *
 *	E/ pointeur sur la description de la ligne en cours
 *	S/ pointeur sur la description de la ligne suivante
 *
 * ------------------------------------------------------------------- */

CORRESPTR get_next_line(linfos)
CORRESPTR linfos;
{
	if (linfos == (CORRESPTR)0)	return((CORRESPTR)0);
	
	switch (DebugSymbols->zoom_status) {
		case 0 :
		case 1 :
			do {
				if ((linfos = linfos->next) == (CORRESPTR)0)
					break;
			} while ((linfos->file_offset == linfos->previous->file_offset)
			     &&  (linfos->file_number == linfos->previous->file_number));
			break;			   
		case 2 :	
			linfos = linfos->next;
			break;
	}
	
	return(linfos);
}


/* -------------------------------------------------------------------
 * GET_PREV_LINE
 *
 *	Recupere un pointeur sur la description de la ligne precedente.
 *
 *	E/ pointeur sur la description de la ligne en cours
 *	S/ pointeur sur la description de la ligne precedente
 *
 * ------------------------------------------------------------------- */

CORRESPTR get_prev_line(linfos)
CORRESPTR linfos;
{
	if (linfos == (CORRESPTR)0)	return((CORRESPTR)0);
	
	switch (DebugSymbols->zoom_status) {
		case 0 :
		case 1 :
			do {
				if ((linfos = linfos->previous) == (CORRESPTR)0)
					break;
			} while ((linfos->file_offset == linfos->next->file_offset)
			     &&  (linfos->file_number == linfos->next->file_number));
			break;			   
		case 2 :	
			linfos = linfos->previous;
			break;
	}
	
	return(linfos);
}


/* -------------------------------------------------------------------
 * DRAW_CORRESPONDANCE_PAGE
 *
 *	Affiche une page de source.
 *
 *	E/ coordonnees de la fenetre d'affichage
 *	   pointeur sur la description de la premiere ligne de la page
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID draw_correspondance_page(topcol,toplin,nbcol,nblin,linfos)
EXAWORD toplin;
EXAWORD topcol;
EXAWORD nbcol;
EXAWORD nblin;
CORRESPTR linfos;
{
	EXAWORD	lno;
	EXAWORD	c;

	/* Set line array to void */
	for (c = 0 ; c < 64 ; c++)
		ZoomLine[c] = (CORRESPTR)0;

	/* As long as window is not full and stream empty... */
	symbolic_atribut(0);
	lno = 0;
	while (linfos != (CORRESPTR)0) {
		lno = correspondance_item(topcol,toplin+1,nbcol,nblin,lno,linfos);
		if (lno >= nblin)	break;
		linfos = get_next_line(linfos);
	}

	/* Rest of screen is set to blank */
	for ( ; lno < nblin ; lno++)
		left_string(topcol,toplin+1+lno,nbcol,(BPTR)" ");
}


/* -------------------------------------------------------------------
 * CORRESPONDANCE_ITEM
 *
 *	Affiche une ligne logique de source.
 *
 *	E/ coordonnees de la fenetre d'affichage
 *	   numero de la ligne a afficher
 *	   pointeur sur la description de la ligne a afficher
 *	S/ numero de la prochaine ligne
 *
 * ------------------------------------------------------------------- */

EXAWORD correspondance_item(topcol,toplin,nbcol,nbl,lno,linfos)
EXAWORD topcol;
EXAWORD toplin;
EXAWORD nbcol;
EXAWORD nbl;
EXAWORD lno;
CORRESPTR linfos;
{
	SYMBOLPTR	fsymb=(SYMBOLPTR) 0;
	EXAWORD		c;
	EXAWORD		nbc;
	EXAWORD		tabulation=TabSize;
	EXAWORD		status = 1;
	EXAWORD		n;
	EXALONG		finish = (EXALONG)-1L;
	CORRESPTR	finfos;
	EXABYTE		thisline[240];

	if ((linfos != (CORRESPTR)0)
	&&  ((fsymb = locate_source_number(linfos->file_number)) != (SYMBOLPTR)0)
	&&  (stream_position(_WORK_STREAM,(BPTR)fsymb->name,(EXALONG)linfos->file_offset,fsymb->number+1,linfos->nature))) {

		/* Prepare display */
		ZoomLine[lno] = linfos;
		x_bstart();
		nbcol += topcol;
		pos((toplin+lno),(nbc = topcol));
		
		/* Display breakpoint information */
		switch ((c = is_break_point(linfos))) {
			case 0 : thisline[nbc] = ' '; break;
			case 1 :
			case 2 : thisline[nbc] = c+'A'-1; break;
		}

		/* Display trace information */
		if ((c = is_trace_region(linfos)) != 0)
			thisline[nbc+1] = 'T';
		else	thisline[nbc+1] = ' ';

		/* Display Tcode address */
		exadb_itoh((BPTR)&thisline[nbc+2],linfos->tcode_offset);

		/* If same line as previous one, display blank line */
		finfos = linfos->previous;
		if (finfos != (CORRESPTR)0) {
			if ((linfos->file_offset == finfos->file_offset) &&
			    (linfos->file_number == finfos->file_number) &&
			    (lno != 0)) {
				thisline[nbc+6] = '-'; 
				thisline[nbc+7] = '>';
				nbc += 8;
				for ( ; nbc < nbcol ; nbc++)	thisline[nbc] = ' ';
				thisline[nbc] = 0;
				x_cprintf((BPTR)&thisline[topcol]);
				x_bflush();
				return(lno+1);
			}
		}

		/* Get offset of next line */
		finfos = get_next_line(linfos);
		if (finfos != (CORRESPTR) 0) {
			if (finfos->file_number == linfos->file_number)
				finish = finfos->file_offset;
		}
		else	finish = 0;

		/* Display what ??? */
		thisline[nbc+6] = ':'; 
		thisline[nbc+7] = ' ';
		nbc += 8;
		
		/* Display source line */
		while ( 1 ) {
			switch ((c = stream_getc(_WORK_STREAM))) {
				case '\r' : 
					continue;

				case '\n' : 
					if (status)
						for ( ; nbc < nbcol ; nbc++)
							thisline[nbc] = ' ';
					thisline[nbc] = 0;
					x_cprintf((BPTR)&thisline[topcol]);
					nbc = topcol;
					status = 1;
					lno++;
					if (check_finished(linfos,finish)) {
						x_bflush();
						return(lno);
					}
					if (finfos == (CORRESPTR)0)
						symbolic_atribut(0);
						
					if (lno < nbl) {
						pos(toplin+lno,nbc);
						for (c = 0 ; c < 8 ; c++)
							thisline[nbc++] = ' ';
						continue;
					}

				case 0x0000 :
				case 0x001A :
				case 0xFFFF :
					if (nbc > topcol) {
						thisline[nbc] = 0;
						x_cprintf((BPTR)&thisline[topcol]);
					}
					x_bflush();
					return(lno);

 				case '\t' :
					do {
						if (nbc < nbcol) 
							thisline[nbc++] = ' ';
					} while ((nbc < nbcol) && ((nbc % tabulation) != 0));
					continue;
  
				case 0x000C :
				case 0x001C : 
					c = 0x0020;
					
				default :
				if (DebugSymbols->zoom_status == 1) {
					if (nbc >= nbcol) {
						/* Print collected chars */
						thisline[nbc] = 0;
						x_cprintf((BPTR)&thisline[topcol]);
						lno++;

						/* Check if line is entirely displayed */
						if ((check_finished(linfos,finish)) ||
						    (lno >= nbl)) {
							x_bflush();
							return(lno);
						}

						/* Prepare new line for display */
						pos(toplin+lno,(nbc = topcol));
						for (c = 0 ; c < 8 ; c++)
							thisline[nbc++] = ' ';
					}
					thisline[nbc++] = (EXABYTE)c;
				}
				else	{
					if ((status) && (nbc < nbcol)) {
						thisline[nbc++] = (EXABYTE)c;
					}
					else	status = 0;
				}
				continue;
			}
		}	
	}
	return(lno);
}


/* -------------------------------------------------------------------
 * SHOW_CORRESPONDANCE
 *
 *	Affiche une ligne logique de source.
 *
 *	E/ attribut de visualisation
 *	   coordonnees de la fenetre d'affichage
 *	   numero de la ligne physique a afficher
 *	   pointeur sur la description de la premiere ligne de la page
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

EXAWORD show_correspondance(mode,topcol,toplin,item,nbcol,nblin,linfos)
EXAWORD mode;
EXAWORD topcol;
EXAWORD toplin;
EXAWORD item;
EXAWORD nbcol;
EXAWORD nblin;
CORRESPTR linfos;
{ 
	/* Display the line with the appropriate attribute */
	symbolic_atribut(mode);	
	(VOID)correspondance_item(topcol,toplin,nbcol,nblin,item,ZoomLine[item]);
	symbolic_atribut(0);	

	return(0);
}


/* -------------------------------------------------------------------
 * DRAW_EMPTY_BOX
 *
 *	Affiche une boite vide.
 *
 *	E/ coordonnees de la fenetre d'affichage
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID draw_empty_box(tc,tl,nc,nl)
EXAWORD tc;
EXAWORD tl;
EXAWORD nc;
EXAWORD nl;
{ EXAWORD c,l;
  EXABYTE buf[256];
  
	/* Prepare buffer with blanks */
	for (c = 0 ; c < nc ; c++) 
		buf[c] = ' ';
	buf[c] = 0;

	/* Display empty box */
	x_bstart();
	symbolic_atribut(0);
	for (l = 0 ; l < nl ; l++) {
		pos(tl+l,tc);
		x_cprintf((BPTR)buf);
	}
	x_bflush();
}	


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			AFFICHAGE MODE TEXTE				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

#ifndef DBWIN_GR
/* -------------------------------------------------------------------
 * CORRESPONDANCE_HEADER
 *
 *	Affiche l'entete de la page de debug.
 *
 *	E/ coordonnees de la fenetre d'affichage
 *	   mode d'utilisation
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID correspondance_header(topcol,toplin,nbcol,nblin,opmode)
EXAWORD topcol;
EXAWORD toplin;
EXAWORD nbcol;
EXAWORD nblin;
EXAWORD opmode;
{
	EXAWORD	c;
	EXAWORD	nbc;
	EXAWORD	col60;

	col60 = ScreenCol-20;
	symbolic_atribut(0);

	if (fsame == 0xFFFF) {
		draw_box(1,1,(nbc = (ScreenCol-2)),3);
		pos(1,20);  x_putch(GRSYM_C2);

		if (trace_is_active())
			display_operation_mode(5);
		else	display_operation_mode(opmode);

		symbolic_atribut(2);
		centered_string(3,2,16,(BPTR)interface_message(29));

		symbolic_atribut(0);
		x_putch(' ');		x_putch(GRSYM_B3);
		pos(2,col60+1);		x_putch(GRSYM_B3);	x_putch(' ');

		symbolic_atribut(2);
		centered_string(col60+3,2,16,(BPTR)interface_message(30));

		symbolic_atribut(0);
		pos(3,1);	x_putch(GRSYM_C3);
		
		for (c = 0 ; c < nbc ; c++)	x_putch(GRSYM_C4);
		
		pos(3,20);		x_putch(GRSYM_C5);
		pos(3,col60+1);		x_putch(GRSYM_C5);
		pos(4,1);		x_putch(GRSYM_B3);	x_putch(' ');
		pos(4,19);		x_putch(' ');		x_putch(GRSYM_B3);	x_putch(' ');
		pos(1,col60+1);		x_putch(GRSYM_C2);
		pos(4,col60); 		x_putch(' ');		x_putch(GRSYM_B3);	x_putch(' ');
		pos(3,ScreenCol);	x_putch(GRSYM_B4);
		pos(4,ScreenCol-1);	x_putch(' ');		x_putch(GRSYM_B3);

		show_debug_switchs();
		show_debug_level();
	}
	
	display_message_zone();
	reset_message_zone();

	if (fsame == 0xFFFF) {
		pos(5,20);  	x_putch(GRSYM_C1);
		pos(5,col60+1);	x_putch(GRSYM_C1);
		code_block_identity(topcol,toplin);
	}
	
	establish_function_keys(opmode);
	set_mouse_control(topcol,toplin,nbcol,nblin);
#ifdef WIN1632
	atb(25);
#endif
}


/* -------------------------------------------------------------------
 * SHOW_ZOOM_SWITCH
 *
 *	Affiche l'etat de zoom du source.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_zoom_switch()
{ EXAWORD	col63;

	col63 = ScreenCol-17;
	WindowOff();
	symbolic_atribut(2);
	switch (DebugSymbols->zoom_status) {
		case 0 :
		case 1 : centered_string(col63,4,8,(BPTR) interface_message(7));
			 break;
		case 2 : centered_string(col63,4,8,(BPTR) interface_message(8));
			 break;
	}
	symbolic_atribut(0);
	x_putch(' ');
	WindowOn();
}


/* -------------------------------------------------------------------
 * SHOW_BREAK_SWITCH
 *
 *	Affiche l'etat du break.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_break_switch()
{
	WindowOff();
	symbolic_atribut(2);
	if (brayk != 0)	centered_string(3,4,9,(BPTR)interface_message(24));
	else		centered_string(3,4,9,(BPTR)interface_message(25));
	symbolic_atribut(0);
	x_putch(' ');
	WindowOn();
}


/* -------------------------------------------------------------------
 * SHOW_HEXA_SWITCH
 *
 *	Affiche le mode d'affichage des variables.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_hexa_switch()
{
	WindowOff();
	symbolic_atribut(2);
	switch (DebugSymbols->display_mode) {
		case 1 : centered_string(13,4,6,(BPTR)interface_message(26));
			 break;
		case 0 : centered_string(13,4,6,(BPTR)interface_message(27));
			 break;
	}
	symbolic_atribut(0);
	WindowOn();
}


/* -------------------------------------------------------------------
 * SHOW_SCREEN_SWITCH
 *
 *	Affiche le mode d'ecran courant.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_screen_switch()
{
	WindowOff();
	symbolic_atribut(2);
	centered_string(ScreenCol-8,4,7,(BPTR)interface_message(28)); 
	symbolic_atribut(0);
	WindowOn();
}

#else /* DBWIN_GR */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			AFFICHAGE MODE GRAPHIQUE			     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* -------------------------------------------------------------------
 * CORRESPONDANCE_HEADER
 *
 *	Affiche l'entete de la page de debug.
 *
 *	E/ coordonnees de la fenetre d'affichage
 *	   mode d'utilisation
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID correspondance_header(topcol,toplin,nbcol,nblin,opmode)
EXAWORD topcol;
EXAWORD toplin;
EXAWORD nbcol;
EXAWORD nblin;
EXAWORD opmode;
{
	EXAWORD	c;
	EXAWORD	nbc;
	EXAWORD	col60;

	col60 = ScreenCol-20;
	symbolic_atribut(0);

	if (fsame == 0xFFFF) {
		draw_empty_box(1,1,(nbc = (ScreenCol-2))+2,2+3);

		if (trace_is_active())
			display_operation_mode(5);
		else	display_operation_mode(opmode);

		symbolic_atribut(2);
		centered_string(3,2,16,(BPTR)interface_message(29));
		centered_string(col60+3,2,16,(BPTR)interface_message(30));
		symbolic_atribut(0);

		show_debug_switchs();
	}
	
	display_message_zone();
	reset_message_zone();

	if (fsame == 0xFFFF) {
		code_block_identity(topcol,toplin);
	}
	
	establish_function_keys(opmode);
	set_mouse_control(topcol,toplin,nbcol,nblin);
}


/* -------------------------------------------------------------------
 * SHOW_ZOOM_SWITCH
 *
 *	Affiche l'etat de zoom du source.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_zoom_switch()
{ EXAWORD	col63;

	col63 = ScreenCol-17;
	WindowOff();
	symbolic_atribut(2);
	switch (DebugSymbols->zoom_status) {
		case 0 :
		case 1 : centered_string(col63,4,8,(BPTR) interface_message(7));
			 break;
		case 2 : centered_string(col63,4,8,(BPTR) interface_message(8));
			 break;
	}
	symbolic_atribut(0);
	x_putch(' ');
	WindowOn();
}


/* -------------------------------------------------------------------
 * SHOW_BREAK_SWITCH
 *
 *	Affiche l'etat du break.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_break_switch()
{
	WindowOff();
	symbolic_atribut(2);
	if (brayk != 0)	centered_string(3,4,9,(BPTR)interface_message(24));
	else		centered_string(3,4,9,(BPTR)interface_message(25));
	symbolic_atribut(0);
	x_putch(' ');
	WindowOn();
}


/* -------------------------------------------------------------------
 * SHOW_HEXA_SWITCH
 *
 *	Affiche le mode d'affichage des variables.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_hexa_switch()
{
	WindowOff();
	symbolic_atribut(2);
	switch (DebugSymbols->display_mode) {
		case 1 : centered_string(13,4,6,(BPTR)interface_message(26));
			 break;
		case 0 : centered_string(13,4,6,(BPTR)interface_message(27));
			 break;
	}
	symbolic_atribut(0);
	WindowOn();
}


/* -------------------------------------------------------------------
 * SHOW_SCREEN_SWITCH
 *
 *	Affiche le mode d'ecran courant.
 *
 *	E/ rien
 *	S/ rien
 *
 * ------------------------------------------------------------------- */

VOID	show_screen_switch()
{
	WindowOff();
	symbolic_atribut(2);
	centered_string(ScreenCol-8,4,7,(BPTR)interface_message(28)); 
	symbolic_atribut(0);
	WindowOn();
}

#endif /* DBWIN_GR */
