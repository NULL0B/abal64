/* ---------------------------------------------------------------------*/
/*                                                                      */
/*              E X E C U T E U R       A . B . A . L                   */
/*              -------------------------------------                   */
/*                                                                      */
/*              Copyright (c) 1987,1997 Amenesik / Sologic S.A.         */
/*                                                                      */
/*              Module  :       EXDBMUI.C                              	*/
/*              Date    :       20/10/2022                              */
/*              Version :       5.1a                                    */
/*                                                                      */
/*----------------------------------------------------------------------*/
#ifdef	ABALX11
extern	int	exa_is_X11;
#endif

#ifdef	VERSION666
#include "exdbwui.c"
#endif

/*	-------------------------	*/
/*	 display_correspondances	*/
/*	-------------------------	*/
EXAWORD	display_correspondances( CORRESPTR linfos, EXAWORD opmode)
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
	if (fsame != EXDB_FFFF) 
	{
		/* Is the expected line within the current page ? */
		for (c = 0 ; c < nblin ; c++) 
		{
			/* Is this the exact line ? */
			if (ZoomLine[c] == linfos)	break;
		}
		if (c < nblin)	
			fsame = c;
		else 
		{
  			exp = linfos->tcode_offset;
			for (prv = 0 , c = 0 ; c < nblin ; c++) 
			{
				/* Is the code before next line ? */
				if (ZoomLine[c] == (CORRESPTR)0)	continue;
				if ((exp > ZoomLine[prv]->tcode_offset) &&
				    (exp < ZoomLine[c]->tcode_offset)) 
				{
					c = prv;
					break;
				}
				prv = c;
			}
			if (c < nblin)	fsame = c;
			else		fsame = EXDB_FFFF;
		}
	}

	/* Reload pointers from backup or scratch */
	if (fsame == EXDB_FFFF)	{ kinfos = tinfos = linfos; }
	else			{ tinfos = linfos; lno = lnd = fsame; }

	/* Forever... */
	check_global_variables();

	correspondance_header(topcol,toplin,nbcol,nblin,opmode);
	actpos = 1;
	while ( 1 ) 
	{
		/* Display page if code has changed */
		if (fsame == EXDB_FFFF) 
		{
			draw_correspondance_page(topcol,toplin,nbcol,nblin,kinfos);
			
			/* Retrieve debugged line */
			for (c = 0 ; c < nblin ; c++) 
			{
				if (ZoomLine[c] == linfos)	break;
			}
			if (c >= nblin)	{ lnd = EXDB_FFFF; }
			else		{ lnd = c; }
			
			/* Set current line if changed */
			if (actpos) 
			{
				tinfos = kinfos;
				for (c = 0 ; c < nblin ; c++) 
				{
					if (ZoomLine[c] == tinfos)	break;
				}
				if (c >= nblin)	{ lno = 0; }
				else		{ lno = c; }
			}
		}
		fsame = actpos = 0;
		        
		/* Display current selection */
		if (lnd != EXDB_FFFF)
			show_correspondance(6,topcol,toplin+1,lnd,nbcol,nblin,kinfos);
		if (lno != lnd)		
			show_correspondance(5,topcol,toplin+1,lno,nbcol,nblin,kinfos);

		/* Get user action */
		c = mouse_or_keyboard();

		/* Reset current selection */
		if (lnd != EXDB_FFFF)
			show_correspondance(4,topcol,toplin+1,lnd,nbcol,nblin,kinfos);
		if (lno != lnd)		
			show_correspondance(4,topcol,toplin+1,lno,nbcol,nblin,kinfos);

		/* Depending on what the user intends to do... */
		switch (c) 
		{
			case '-'    :	 
				if (opmode == 0) 
				{
					pop_mouse();
					previous_correspondance();
					correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				}
				actpos = fsame = EXDB_FFFF;
				break;

			case '?'    :
				alter_hexa_switch();
				break;

			case CTRL_H :
				view_help_screen(0);
				pop_mouse();
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				fsame = EXDB_FFFF;
				break;
				
			case CTRL_D :
				if (DbMouse.position == 0)	break;
				if ((finfos = ZoomLine[(DbMouse.position-1)]) != (CORRESPTR) 0) 
				{
					tinfos = finfos;
					lno = DbMouse.position - 1;
				}
				else	break;
				if (current_mouse_click() != 2)	break;
	
			case CTRL_M	:
				pop_mouse();
				edit_correspondance_file(tinfos);
				fsame = EXDB_FFFF;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_F :
				finfos=kinfos;
				find_correspondance(kinfos);
				actpos = fsame = EXDB_FFFF;
				kinfos=finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_L :
				kinfos = tinfos = linfos;
				actpos = fsame = EXDB_FFFF;
				break;

			case CTRL_Q :
				if ((opmode == 0) &&  (tinfos != (CORRESPTR)0)) 
				{
 					set_break_point(0x0002,tinfos);
					pop_mouse();
					return(0x0018);
				}
				break;

			case CTRL_I :
				if (opmode == 0) 
				{
					if (linfos->nature) 
					{
						if ((zinfos = pseudo_step(linfos)) != (CORRESPTR)0) 
						{
		 					set_break_point(0x0002,zinfos->next);
							pop_mouse();
							return(0x0018);
						}
					}
					else if (linfos->next != (CORRESPTR)0) 
					{
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
				fsame = EXDB_FFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_C :
				for (c = 0 ; c < 8 ; c++) 
				{
					finfos = get_next_line(tinfos);
					if (finfos == (CORRESPTR)0)	break;
					else	tinfos = finfos;
				}
				for (c = 0 ; c < nblin ; c++) 
				{
					if (ZoomLine[c] == tinfos)	break;
				}
				if (c >= nblin)	{ kinfos = tinfos; fsame = EXDB_FFFF; }
				else		{ lno = c; }
				actpos = 1;
				break;
				
			case CTRL_R :
				for (c = 0 ; c < 8 ; c++) 
				{
					finfos = get_prev_line(tinfos);
					if (finfos == (CORRESPTR)0)	break;
					else	tinfos = finfos;
				}
				for (c = 0 ; c < nblin ; c++) 
				{
					if (ZoomLine[c] == tinfos)	break;
				}
				if (c >= nblin)	{ kinfos = tinfos; fsame = EXDB_FFFF; }
				else		{ lno = c; }
				actpos = 1;
				break;

			case CTRL_Z	:
				alter_zoom_switch();
				actpos = fsame = EXDB_FFFF;
				break;
			
			case CTRL_G :
				finfos = kinfos;
				pop_mouse();
				symbols_selector(CTRL_G);
				fsame = EXDB_FFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_P :
				finfos = kinfos;
				pop_mouse();
				symbols_selector(CTRL_P);
				fsame = EXDB_FFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_S :
				finfos = kinfos;
				pop_mouse();
				symbols_selector(CTRL_S);
				fsame = EXDB_FFFF; kinfos = finfos;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_V :
				if (opmode == 0) 
				{
					finfos = kinfos;
					pop_mouse();
					symbols_selector(CTRL_V);
					fsame = EXDB_FFFF; kinfos = finfos;
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
				fsame = EXDB_FFFF;
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				left_string(topcol,ScreenLin-2,nbcol,(BPTR)" ");
				Observe(0);
				break;

			case CTRL_N  :
				pop_mouse();
				actpos = fsame = EXDB_FFFF;
				if ((offer_list_menu(opmode) != 0)
				&&  ((finfos = check_correspondances()) != (CORRESPTR) 0)) 
				{
					kinfos = linfos = finfos;
				}
				actpos = fsame = EXDB_FFFF;
				left_string(topcol,ScreenLin-2,nbcol,(BPTR)" ");
				Observe(0);
				nblin = avoid_observations(ScreenLin - 8);
				correspondance_header(topcol,toplin,nbcol,nblin,opmode);
				break;

			case CTRL_E	:
				finfos = get_next_line(tinfos);
				if (finfos != (CORRESPTR)0) 
				{
					tinfos = finfos;
					actpos = 1;
					for (c = 0 ; c < nblin ; c++) 
					{
						if (ZoomLine[c] == tinfos)	break;
					}
					if (c >= nblin)	{ kinfos = tinfos; fsame = EXDB_FFFF; }
					else		{ lno = c; }
				}
				break;

			case CTRL_K	:
				finfos = get_prev_line(tinfos);
				if (finfos != (CORRESPTR)0) 
				{
					tinfos = finfos;
					actpos = 1;
					for (c = 0 ; c < nblin ; c++) 
					{
						if (ZoomLine[c] == tinfos)	break;
					}
					if (c >= nblin)	{ kinfos = tinfos; fsame = EXDB_FFFF; }
					else		{ lno = c; }
				}
				break;

			case CTRL_T	:
				if (trace_toggle) 
				{
					trace_to_here(trace_start,tinfos); 
					trace_toggle = 0;
				}
				else	
					{
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
				if ((c != 0x0020) && (c != CTRL_X)) 
				{
					actpos = fsame = EXDB_FFFF;
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
	
	switch (DebugSymbols->zoom_status) 
	{
		case 0 :
		case 1 :
			do 
			{
				if ((linfos = linfos->next) == (CORRESPTR)0)
					break;
			} 
			while ((linfos->file_offset == linfos->previous->file_offset)
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
	
	switch (DebugSymbols->zoom_status) 
	{
		case 0 :
		case 1 :
			do 
			{
				if ((linfos = linfos->previous) == (CORRESPTR)0)
					break;
			} 
			while ((linfos->file_offset == linfos->next->file_offset)
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
	symbolic_atribut(4);
	lno = 0;
	while (linfos != (CORRESPTR)0) 
	{
		lno = correspondance_item(topcol,toplin+1,nbcol,nblin,lno,linfos);
		if (lno >= nblin)	break;
		linfos = get_next_line(linfos);
	}

	/* Rest of screen is set to blank */
	for ( ; lno < nblin ; lno++)
		left_string(topcol,toplin+1+lno,nbcol,(BPTR)" ");
}

#define	abal_directive_colour	(9&7)
#define	abal_comment_colour	(10&7)
#define	abal_constant_colour	(11&7)
#define	abal_procedure_colour	13
#define	abal_variable_colour	15	
#define	abal_keyword_colour	11
#define	abal_punctuation_colour	0

/*	-----------------	*/	
/*	correspondance_bg	*/
/*	-----------------	*/	
EXAWORD	correspondance_bg( EXAWORD v )
{
	x_putch(0x001B);
	x_putch('s');
	x_putch(v);
	return(v);
}

/*	-----------------	*/	
/*	correspondance_fg	*/
/*	-----------------	*/	
EXAWORD	correspondance_fg( EXAWORD v )
{
	x_putch(0x001B);
	x_putch('r');
	x_putch(v);
	return(v);
}

static	BPTR abal_keywords[] = 
{
	"IF","ELSE","ENDIF","END","TIMER","OFF","ON","ERROR","ABORT",
	"WHILE","WEND","DO","LOOP","NAME","BACKSPACE","EXTEND","PAUSE","OP",
	"FOR","TO","NEXT","STEP","EXTERN","FORWARD","INITLOCAL","INITGLOBAL",
	"REPEAT","UNTIL","BREAK","OR","AND","OX","HEX","KBF",
	"SELECT","CASE","DEFAULT","ENDSEL",
	"GOTO","GOSUB","RETURN","RESUME","LIKE","CODE","SEGM","ARG",
	"CALL","EXIT","LDGO.SEG","RET.SEG","STOP",
	"PRINT","ASK","TAB","TABV","ATB","PAINT","FMT","FM",
	"EVENT","CONF","DCL","PTR","FIELD","FILLER","ENDLOC",
	"PROC","ENDPROC", "SEGMENT","ESEG",
	"MASK","ERRADR","EVENTADR","HOTKEY","CHR","SPACE","FIX","ROUN","FP","INT",
	"LEFT","RIGHT","SUBSTR","MOVE","SWAP","LEN","TRAN","CONST",
	"DATA","RESTORE","LOAD.GO","CHAIN","ATTACH","DETACH","CREATE","ALIAS","REMOVE","FORGET","VALIDPTR",
	"ASSIGN","FILE","RENAME","OPEN","CLOSE","READ","WRITE","CFILE","DFILE","ATB",
	"INSERT","MODIF","SEARCH","SEARCH.M","SEARCH.L","SEARCH.ML","UP","DOWN","UP.M","UP.L","UP.ML","DOWN.M","DOWN.L","DOWN.ML",
	"POSIT","POSIT.D","COUNT","COLLECT","KEY","LINK","JOIN","LKEY","LLINK","LJOIN","CKEY","CLINK","CJOIN","RECORD",
	(BPTR) 0
};

/*	------------------------	*/
/*	 correspondance_keyword 	*/
/*	------------------------	*/
EXAWORD	correspondance_keyword( BPTR token )
{
	BPTR	sptr;
	EXAWORD	i=0;
	while ((sptr = abal_keywords[i++]) != (BPTR) 0)
		if (!( strcasecmp(token, sptr) ))
			return(1);
	return( 0 );
}

/*	-------------------------	*/
/*	 correspondance_variable	*/
/*	-------------------------	*/
EXAWORD	correspondance_variable( BPTR token )
{
	SYMBOLPTR       lsymb;
	if (!( lsymb = locate_variable_name( token ) ))
		return( 0 );
	else	return( 1 );
}

/*	------------------------	*/
/*	correspondance_procedure	*/
/*	------------------------	*/
EXAWORD	correspondance_procedure( BPTR token )
{
	SYMBOLPTR       lsymb;
	if (!( lsymb = locate_procedure_name( token ) ))
		return( 0 );
	else	return( 1 );
}

/*	------------------------	*/
/*	  correspondance_token		*/
/*	------------------------	*/
EXAWORD	correspondance_token( BPTR token, EXAWORD fg )
{
	EXAWORD		i;
	if ( *token == '"' )
	{
		if ( fg != abal_constant_colour )
			fg = correspondance_fg( abal_constant_colour );
		x_cprintf(token);
		return( fg );
	}
	else if (( *token >= '0' ) && ( *token <= '9' ))
	{
		if ( fg != abal_constant_colour )
			fg = correspondance_fg( abal_constant_colour );
		x_cprintf(token);
		return( fg );
	}
	else if ( correspondance_keyword( token ) )
	{
		if ( fg != abal_keyword_colour )
			fg = correspondance_fg( abal_keyword_colour );
		x_cprintf(token);
		return( fg );
	}
	else
	{
		for ( i = 0; token[i] != 0; i++ )
			if (( token[i] >= 'a' ) && ( token[i] <= 'z' ))
				token[i] -= ('a' - 'A');
		if ( correspondance_variable( token ) )
		{
			if ( fg != abal_variable_colour )
				fg = correspondance_fg( abal_variable_colour );
		}
		else if ( correspondance_procedure( token ) )
		{
			if ( fg != abal_procedure_colour )
				fg = correspondance_fg( abal_procedure_colour );
		}
		x_cprintf(token);
		return( fg );
	}
}

/*	-------------------	*/	
/*	correspondance_show	*/
/*	-------------------	*/	
VOID	correspondance_show( BPTR buffer )
{
	BYTE	token[1024];
	EXAWORD	tokens=0;
	EXAWORD	bytes=0;
	EXAWORD	i=0;
	EXAWORD	c=0;
	EXAWORD	fg=-1;
	EXAWORD	bg=-1;
	fg = correspondance_fg(abal_punctuation_colour);
	while (( c = *(buffer++)) != 0)
	{
		switch (c)
		{
		case	'\r'	:
		case	'\n'	:
		case	'\t'	:
			c = ' ';
		case	' '	:
			if ( token[0] == '"' )
			{
				token[i++] = c;
				continue;
			}
			else if ( i > 0 )
			{
				token[i] = 0;
				fg = correspondance_token(token,fg);
				token[(i = 0)] = 0;
			}
			if ( fg != 0 )
				fg = correspondance_fg(abal_punctuation_colour);
			x_putch(c);
			continue;
		default		:
			if ( token[0] == '"' )
			{
				token[i++] = c;
				if ( c == '"' )
				{
					bytes++;
					token[i] = 0;
					fg = correspondance_token(token,fg);
					token[(i = 0)] = 0;
				}
			}
			else if (( c >= 'a' ) && ( c <= 'z'))	
				token[i++] = c;
			else if (( c >= 'A' ) && ( c <= 'Z'))	
				token[i++] = c;
			else if (( c >= '0' ) && ( c <= '9'))	
				token[i++] = c;
			else if (( c == '_' ) || ( c == '"' ) || ( c == '.' ))
				token[i++] = c;
			else
			{
				if ( i > 0 )
				{
					bytes++;
					token[i] = 0;
					fg = correspondance_token(token,fg);
					token[(i = 0)] = 0;
				}
				if ( c == ';' )
				{
					fg = correspondance_fg(abal_comment_colour);
					x_putch(c);
					while ((c = *(buffer++)) != 0)
						x_putch(c);
					return;		
				}
				else if (( c == '#' ) && (!( bytes )))
				{
					fg = correspondance_fg(abal_directive_colour);
					x_putch(c);
					while ((c = *(buffer++)) != 0)
						x_putch(c);
					return;		
				}
				else if ( fg != 0 )
					fg = correspondance_fg(abal_punctuation_colour);
				bytes++;
				x_putch(c);
			}
			continue;
		}
	}
	if ( i > 0 )
	{
		token[i] = 0;
		fg = correspondance_token(token,fg);
		token[(i = 0)] = 0;
	}
	return;
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
	EXAWORD		adrsize=0;
	EXALONG		finish = (EXALONG)-1L;
	CORRESPTR	finfos;
	EXABYTE		thisline[1024];
	EXABYTE		workline[1024];

	if ((linfos != (CORRESPTR)0)
	&&  ((fsymb = locate_source_number(linfos->file_number)) != (SYMBOLPTR)0)
	&&  (stream_position(_WORK_STREAM,(BPTR)fsymb->name,(EXALONG)linfos->file_offset,fsymb->number+1,linfos->nature))) 
	{

		/* Prepare display */
		ZoomLine[lno] = linfos;
		x_bstart();
		nbcol += topcol;
		pos((toplin+lno),(nbc = topcol));
		
		/* Display breakpoint information */
		switch ((c = is_break_point(linfos))) 
		{
			case 0 : thisline[nbc] = ' '; break;
			case 1 :
			case 2 : thisline[nbc] = c+'A'-1; break;
		}

		/* Display trace information */
		if ((c = is_trace_region(linfos)) != 0)
			thisline[nbc+1] = 'T';
		else	thisline[nbc+1] = ' ';

		/* Display Tcode address */
		adrsize = exadb_address((BPTR)&thisline[nbc+2],linfos->tcode_offset);

		/* If same line as previous one, display blank line */
		finfos = linfos->previous;
		if (finfos != (CORRESPTR)0) 
		{
			if ((linfos->file_offset == finfos->file_offset) &&
			    (linfos->file_number == finfos->file_number) &&
			    (lno != 0)) 
			{
				thisline[nbc+adrsize+2] = '-'; 
				thisline[nbc+adrsize+3] = '>';
				nbc += (adrsize+4);
				for ( ; nbc < nbcol ; nbc++)	thisline[nbc] = ' ';
				thisline[nbc] = 0;
				x_cprintf((BPTR)&thisline[topcol]);
				x_bflush();
				return(lno+1);
			}
		}

		/* Get offset of next line */
		finfos = get_next_line(linfos);
		if (finfos != (CORRESPTR) 0) 
		{
			if (finfos->file_number == linfos->file_number)
				finish = finfos->file_offset;
		}
		else	finish = 0;

		/* Display what ??? */
		thisline[nbc+adrsize+2] = ':'; 
		thisline[nbc+adrsize+3] = ' ';
		nbc += (adrsize+4);
		
		/* Display source line */
		while ( 1 ) 
		{
			if ((c = stream_getc(_WORK_STREAM)) == EXDB_FFFF)
				c = 0x001A;
			switch ( c )  
			{
			case '\r' : 
				continue;

			case '\n' : 
				if (status)
					for ( ; nbc < nbcol ; nbc++)
						thisline[nbc] = ' ';
				thisline[nbc] = 0;
				correspondance_show((BPTR)&thisline[topcol]);
				nbc = topcol;
				status = 1;
				lno++;
				if (check_finished(linfos,finish)) 
				{
					x_bflush();
					return(lno);
				}
				if (finfos == (CORRESPTR)0)
					symbolic_atribut(0);
					
				if (lno < nbl) 
				{
					pos(toplin+lno,nbc);
					for (c = 0 ; c < 8 ; c++)
						thisline[nbc++] = ' ';
					continue;
				}

			case 0x0000 :
			case 0x001A :
				if (nbc > topcol) 
				{
					thisline[nbc] = 0;
					correspondance_show((BPTR)&thisline[topcol]);
				}
				x_bflush();
				return(lno);

 			case '\t' :
				do 
				{
					if (nbc < nbcol) 
						thisline[nbc++] = ' ';
				} while ((nbc < nbcol) && ((nbc % tabulation) != 0));
				continue;
 
			case 0x000C :
			case 0x001C : 
				c = 0x0020;
					
			default :
				if (DebugSymbols->zoom_status == 1) 
				{
					if (nbc >= nbcol) 
					{
						/* Print collected chars */
						thisline[nbc] = 0;
						correspondance_show((BPTR)&thisline[topcol]);
						lno++;

						/* Check if line is entirely displayed */
						if ((check_finished(linfos,finish)) ||
						    (lno >= nbl)) 
						{
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
				else	
				{
					if ((status) && (nbc < nbcol)) 
					{
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
	for (l = 0 ; l < nl ; l++) 
	{
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

	if (fsame == EXDB_FFFF) 
	{
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

	if (fsame == EXDB_FFFF) 
	{
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
	switch (DebugSymbols->zoom_status) 
	{
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
	switch (DebugSymbols->display_mode) 
	{
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

	if (fsame == EXDB_FFFF) 
	{
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

	if (fsame == EXDB_FFFF) 
	{
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
	switch (DebugSymbols->zoom_status) 
	{
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
	switch (DebugSymbols->display_mode) 
	{
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
