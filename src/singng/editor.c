#ifndef	_editor_c
#define	_editor_c

private	int editor_hotkey[32] = {
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
	16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31
	};

#define	_editor_tabulation	editor_hotkey[ CTRL_TAB  ]
#define	_editor_backtabule	editor_hotkey[ CTRL_BTAB ]
#define	_editor_char_left 	editor_hotkey[ CTRL_LEFT ]
#define	_editor_char_right 	editor_hotkey[ CTRL_RIGHT]
#define	_editor_delete		editor_hotkey[ CTRL_DEL  ]
#define	_editor_insert		editor_hotkey[ CTRL_DEL  ]
#define	_editor_word_left 	editor_hotkey[ CTRL_H    ]
#define	_editor_word_right 	editor_hotkey[ CTRL_F    ]

#define _editor_line_top 	editor_hotkey[ CTRL_B ]
#define _editor_line_up  	editor_hotkey[ CTRL_E ]
#define _editor_line_down	editor_hotkey[ CTRL_K ]
#define _editor_line_end 	editor_hotkey[ CTRL_B ]
#define _editor_page_top 	editor_hotkey[ CTRL_L ]
#define _editor_page_up  	editor_hotkey[ CTRL_R ]
#define _editor_page_down	editor_hotkey[ CTRL_C ]
#define _editor_page_wipe	editor_hotkey[ CTRL_J ]
#define _editor_page_end 	editor_hotkey[ CTRL_A ]
#define _editor_line_del 	editor_hotkey[ CTRL_Y ]
#define _editor_line_ins 	editor_hotkey[ CTRL_N ]
#define _editor_line_cut 	editor_hotkey[ CTRL_M ]
#define _editor_line_wipe	editor_hotkey[ CTRL_K ]

private	int	editor_line_top (EVENT * eptr)
private	int	editor_line_up  (EVENT * eptr)
private	int	editor_line_down(EVENT * eptr)
private	int	editor_line_end (EVENT * eptr)
private	int	editor_page_top (EVENT * eptr)
private	int	editor_page_up  (EVENT * eptr)
private	int	editor_page_down(EVENT * eptr)
private	int	editor_page_end (EVENT * eptr)
private	int	editor_line_del (EVENT * eptr)
private	int	editor_line_ins (EVENT * eptr)
private	int	editor_line_cut (EVENT * eptr)

private	int	editor_hotkey_handler( int hotkey )
{
	if ( hotkey == _editor_line_top  ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_line_up   ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_line_down ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_line_end  ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_page_top  ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_page_up   ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_page_down ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_page_end  ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_line_del  ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_line_ins  ) 
		return( editor_line_top(eptr) );
	else if ( hotkey == _editor_line_cut  ) 
		return( editor_line_top(eptr) );
	else	return(0);
}

private	int	editor_event_handler( EVENT * eptr )
{
	switch ( eptr->event ) {
		case	_EVENT_KEY	:
			return( editor_hotkey_handler( eptr->parameter ) );
		default			:
			return(0);
		}
}

#endif	/* _editor_c */

