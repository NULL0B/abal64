#ifndef	_wfmod_c
#define	_wfmod_c

public	int	wfmod( int wid, int bufmax, int lgsais, char * buffer, int iflag, char * exitkey )
{
	int	event;
	struct	asfun_window * 	wptr;
	char			smessage[128];
	if ((wid == 0) || ( wid > _MAX_WINDOWS ))
		return(1);
	else if (!( wptr = Control.windows[(wid-1)] ))
		return(40);
	else	{
		clear_implicite_window();
		wptr->visible = 1;
		show_window( wptr );
		wptr->atlin=1;wptr->atcol=1;
		implicite_window((wid-1));
		while (1) {
			switch ( Control.language ) {
				case	0 :
					sprintf(smessage,"Modification de texte ligne %u, colonne %u : %s",wptr->atcol,wptr->atlin,(iflag ? "INS" : "\0"));
					break;
				case	1 :
				default	  :
					sprintf(smessage,"Modification of text line %u, column %u : %s",wptr->atcol,wptr->atlin,(iflag ? "INS" : "\0"));
					break;
				}
			sl_message(1,strlen(smessage),smessage);
			enable_cursor();
			window_pos(wptr);
			event = x_getch();
			inhibit_cursor();
			switch ( event ) {
				case	0x000F	:	/* toggle insert */
					iflag = ((iflag+1) & 1);
					continue;
				case	 6	:
					if ( wptr->atcol < wptr->w )
						wptr->atcol+=1;
					else 	{
						wptr->atcol=1;
						if ( wptr->atlin < wptr->h )
							wptr->atlin += 1;
						else	wptr->atlin  = 1;
						}
					continue;

				case	 8	:
					if ( wptr->atcol > 1 )
						wptr->atcol-=1;
					else 	{
						wptr->atcol=wptr->w;
						if ( wptr->atlin > 1 )
							wptr->atlin -= 1;
						else	wptr->atlin  = wptr->h;
						}
					continue;
				case	5 :
					if ( wptr->atlin < wptr->h )
						wptr->atlin += 1;
					else	wptr->atlin  = 1;
					continue;
				case	11 :
					if ( wptr->atlin > 1 )
						wptr->atlin -= 1;
					else	wptr->atlin  = wptr->h;
					continue;

				case	27	:
				case	13	:
				case	 9	:
					clear_implicite_window();
					wptr->visible = 0;
					show_windows();
					if ( exitkey )
						*exitkey = event;
					use_implicite_window();
					return(0);
				default		:
					if ( event >= ' ' ) {
						v_putch( event );
						if ( wptr->atcol < wptr->w )
							wptr->atcol+=1;
						else 	{
							wptr->atcol=1;
							if ( wptr->atlin < wptr->h )
								wptr->atlin += 1;
							else	wptr->atlin  = 1;
							}
						}
					continue;
				}
			}
		}
}


/* 45:%wfmod(%,%,%?,$?,#,.?) */
private EXAWORD Dll_wfmod( VOID FAR PTR FAR pptr[] )
{
	if (!( fen_ini	))	{	return(3); 	}
	else	{
		return(wfmod( 	LdfParaWord(0),	/* window handle */
				LdfParaWord(1),	/* buffer limit	 */
				LdfParaWord(2),	/* input length	 */
				LdfParaPtr(3),	/* buffer storage*/
				LdfParaByte(4),	/* insert flag	 */
				(LdfValidPara(5) ? LdfParaPtr(5) : (char *) 0) 
				)	
			);
		}
}

#endif	/* _wfmod_c */
	/* -------- */









