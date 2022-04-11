#ifndef	_abalkeywords_c
#define	_abalkeywords_c

/*	-------------------------------		*/
/*	ABAL KEYWORD UNIQUE definitions 	*/
/*	-------------------------------		*/
/*	Necessary for space saving		*/
/*	-------------------------------		*/
/*	New items must be added at the END !	*/
/*	-------------------------------		*/

#ifdef	_SINGABAL_C

public	char *	__abal_keyword[] = {

	(char *)	/* abal_keyword_program	*/ "Program",
	(char *)	/* abal_keyword_module 	*/ "Module",
	(char *)	/* abal_keyword_forward	*/ "Forward",
	(char *)	/* abal_keyword_extern 	*/ "Extern",
	(char *)	/* abal_keyword_end	*/ "End",

	(char *)	/* abal_keyword_ptr	*/ "Ptr",
	(char *)	/* abal_keyword_dcl	*/ "Dcl",
	(char *)	/* abal_keyword_const	*/ "Const",
	(char *)	/* abal_keyword_field_m	*/ "Field=m",

	(char *)	/* abal_keyword_call   	*/ "Call",
	(char *)	/* abal_keyword_ldgo   	*/ "Ldgo",

	(char *)	/* abal_keyword_repeat	*/ "Repeat",
	(char *)	/* abal_keyword_until 	*/ "Until",
	(char *)	/* abal_keyword_while	*/ "While",
	(char *)	/* abal_keyword_wend   	*/ "Wend",
	(char *)	/* abal_keyword_select 	*/ "Select",
	(char *)	/* abal_keyword_case	*/ "Case",
	(char *)	/* abal_keyword_endsel	*/ "EndSel",
	(char *)	/* abal_keyword_gosub  	*/ "Gosub",
	(char *)	/* abal_keyword_return 	*/ "Return",
	(char *)	/* abal_keyword_error 	*/ "Error",

	(char *)	/* abal_keyword_attach 	*/ "Attach",
	(char *)	/* abal_keyword_detach 	*/ "Detach",
	(char *)	/* abal_keyword_validptr*/ "ValidPtr",
	(char *)	/* abal_keyword_alter	*/ "Alter",
	(char *)	/* abal_keyword_alias	*/ "Alias",
	(char *)	/* abal_keyword_create	*/ "Create",
	(char *)	/* abal_keyword_remove	*/ "Remove",
	(char *)	/* abal_keyword_forget	*/ "Forget",

	(char *)	/* abal_keyword_for  	*/ "For",
	(char *)	/* abal_keyword_to	*/ "To",
	(char *)	/* abal_keyword_next  	*/ "Next",
	(char *)	/* abal_keyword_if  	*/ "If",
	(char *)	/* abal_keyword_or	*/ "Or",
	(char *)	/* abal_keyword_and	*/ "And",
	(char *)	/* abal_keyword_else  	*/ "Else",
	(char *)	/* abal_keyword_endif  	*/ "Endif",
	(char *)	/* abal_keyword_do 	*/ "Do",
	(char *)	/* abal_keyword_loop 	*/ "Loop",
	(char *)	/* abal_keyword_endloc	*/ "EndLoc",

	(char *)	/* abal_keyword_status 	*/ "Status",
	(char *)	/* abal_keyword_break  	*/ "Break",
	(char *)	/* abal_keyword_default	*/ "Default",
	(char *)	/* abal_keyword_goto  	*/ "Goto",
	(char *)	/* abal_keyword_continue*/ "Continue",
	(char *)	/* abal_keyword_retry	*/ "Retry",
	(char *)	/* abal_keyword_keycode	*/ "KeyCode",

	(char *)	/* abal_keyword_segment	*/ "Segment",
	(char *)	/* abal_keyword_retseg	*/ "Ret.Seg",
	(char *)	/* abal_keyword_stop	*/ "Stop",
	(char *)	/* abal_keyword_eseg   	*/ "Eseg",

	(char *)	/* abal_keyword_proc	*/ "Proc",
	(char *)	/* abal_keyword_exit	*/ "Exit",
	(char *)	/* abal_keyword_endproc	*/ "EndProc",

	(char *)	/* abal_keyword_print 	*/ "Print",
	(char *)	/* abal_keyword_ask  	*/ "Ask",
	(char *)	/* abal_keyword_page  	*/ "Page",
	(char *)	/* abal_keyword_left	*/ "Left",
	(char *)	/* abal_keyword_right 	*/ "Right",
	(char *)	/* abal_keyword_substr	*/ "Substr",

	(char *)	/* abal_keyword_assign 	*/ "Assign",
	(char *)	/* abal_keyword_name   	*/ "Name",
	(char *)	/* abal_keyword_open   	*/ "Open",
	(char *)	/* abal_keyword_cfile  	*/ "Cfile",
	(char *)	/* abal_keyword_read   	*/ "Read",
	(char *)	/* abal_keyword_write  	*/ "Write",
	(char *)	/* abal_keyword_close  	*/ "Close",
	(char *)	/* abal_keyword_dfile  	*/ "Dfile",
	(char *)	/* abal_keyword_rename 	*/ "Rename",

	(char *)	/* abal_keyword_insert 	*/ "Insert",
	(char *)	/* abal_keyword_search 	*/ "Search",
	(char *)	/* abal_keyword_modif  	*/ "Modif",
	(char *)	/* abal_keyword_delete 	*/ "Delete",

	(char *)	/* abal_keyword_down   	*/ "Down",
	(char *)	/* abal_keyword_up     	*/ "Up",
	(char *)	/* abal_keyword_down_m 	*/ "Down.M",
	(char *)	/* abal_keyword_up_m   	*/ "Up.M",
	(char *)	/* abal_keyword_search_m*/ "Search.M",

	(char *)	/* abal_keyword_len 	*/ "Len",
	(char *)	/* abal_keyword_filler 	*/ "Filler",

	(char *)	/* abal_keyword_pragma 	*/ "#Pragma",
	(char *)	/* abal_keyword_enter  	*/ "Enter",
	(char *)	/* abal_keyword_leave  	*/ "Leave",
	(char *)	/* abal_keyword_key  	*/ "Key",
	(char *)	/* abal_keyword_ckey   	*/ "Ckey",
	(char *)	/* abal_keyword_link   	*/ "Link",
	(char *)	/* abal_keyword_llink  	*/ "Clink",
	(char *)	/* abal_keyword_posit  	*/ "Posit",
	(char *)	/* abal_keyword_count  	*/ "Count",

	(char *)	/* abal_keyword_driver 	*/ "Driver",
	(char *)	/* abal_keyword_down_l 	*/ "Down.L",
	(char *)	/* abal_keyword_up_l   	*/ "Up.L",
	(char *)	/* abal_keyword_search_l*/ "Search.L"

	};
#else	/* ! SINGABAL_C */
extern	char *	__abal_keyword[];
#endif	

/*	------------------------------------------------------------	*/
/*	Definitions of macros giving acces to keyword table elements	*/
/*	------------------------------------------------------------	*/

#define	__abal_keyword_program	__abal_keyword[0x0000]	 /*Program*/
#define	__abal_keyword_module 	__abal_keyword[0x0001]	 /*Module*/
#define	__abal_keyword_forward	__abal_keyword[0x0002]	 /*Forward*/
#define	__abal_keyword_extern 	__abal_keyword[0x0003]	 /*Extern*/
#define	__abal_keyword_end	__abal_keyword[0x0004]	 /*End*/
#define	__abal_keyword_ptr	__abal_keyword[0x0005]	 /*Ptr*/
#define	__abal_keyword_dcl	__abal_keyword[0x0006]	 /*Dcl*/
#define	__abal_keyword_const	__abal_keyword[0x0007]	 /*Const*/
#define	__abal_keyword_field_m	__abal_keyword[0x0008]	 /*Field=m*/
#define	__abal_keyword_call   	__abal_keyword[0x0009]	 /*Call*/
#define	__abal_keyword_ldgo   	__abal_keyword[0x000A]	 /*Ldgo*/
#define	__abal_keyword_repeat	__abal_keyword[0x000B]	 /*Repeat*/
#define	__abal_keyword_until 	__abal_keyword[0x000C]	 /*Until*/
#define	__abal_keyword_while	__abal_keyword[0x000D]	 /*While*/
#define	__abal_keyword_wend   	__abal_keyword[0x000E]	 /*Wend*/
#define	__abal_keyword_select 	__abal_keyword[0x000F]	 /*Select*/
#define	__abal_keyword_case	__abal_keyword[0x0010]	 /*Case*/
#define	__abal_keyword_endsel	__abal_keyword[0x0011]	 /*EndSel*/
#define	__abal_keyword_gosub  	__abal_keyword[0x0012]	 /*Gosub*/
#define	__abal_keyword_return 	__abal_keyword[0x0013]	 /*Return*/
#define	__abal_keyword_error 	__abal_keyword[0x0014]	 /*Error*/ 
#define	__abal_keyword_attach 	__abal_keyword[0x0015]	 /*Attach*/
#define	__abal_keyword_detach 	__abal_keyword[0x0016]	 /*Detach*/
#define	__abal_keyword_validptr __abal_keyword[0x0017]	 /*ValidPtr*/
#define	__abal_keyword_alter	__abal_keyword[0x0018]	 /*Alter*/
#define	__abal_keyword_alias	__abal_keyword[0x0019]	 /*Alias*/
#define	__abal_keyword_create	__abal_keyword[0x001A]	 /*Create*/
#define	__abal_keyword_remove	__abal_keyword[0x001B]	 /*Remove*/
#define	__abal_keyword_forget	__abal_keyword[0x001C]	 /*Forget*/
#define	__abal_keyword_for  	__abal_keyword[0x001D]	 /*For*/
#define	__abal_keyword_to	__abal_keyword[0x001E]	 /*To*/
#define	__abal_keyword_next  	__abal_keyword[0x001F]	 /*Next*/
#define	__abal_keyword_if  	__abal_keyword[0x0020]	 /*If*/
#define	__abal_keyword_or	__abal_keyword[0x0021]	 /*Or*/
#define	__abal_keyword_and	__abal_keyword[0x0022]	 /*And*/
#define	__abal_keyword_else  	__abal_keyword[0x0023]	 /*Else*/
#define	__abal_keyword_endif  	__abal_keyword[0x0024]	 /*Endif*/
#define	__abal_keyword_do 	__abal_keyword[0x0025]	 /*Do*/
#define	__abal_keyword_loop 	__abal_keyword[0x0026]	 /*Loop*/
#define	__abal_keyword_endloc	__abal_keyword[0x0027]	 /*EndLoc*/
#define	__abal_keyword_status 	__abal_keyword[0x0028]	 /*Status*/
#define	__abal_keyword_break  	__abal_keyword[0x0029]	 /*Break*/
#define	__abal_keyword_default	__abal_keyword[0x002A]	 /*Default*/
#define	__abal_keyword_goto  	__abal_keyword[0x002B]	 /*Goto*/
#define	__abal_keyword_continue __abal_keyword[0x002C]	 /*Continue*/
#define	__abal_keyword_retry	__abal_keyword[0x002D]	 /*Retry*/
#define	__abal_keyword_keycode	__abal_keyword[0x002E]	 /*KeyCode*/
#define	__abal_keyword_segment	__abal_keyword[0x002F]	 /*Segment*/
#define	__abal_keyword_retseg	__abal_keyword[0x0030]	 /*Ret.Seg*/
#define	__abal_keyword_stop	__abal_keyword[0x0031]	 /*Stop*/
#define	__abal_keyword_eseg   	__abal_keyword[0x0032]	 /*Eseg*/
#define	__abal_keyword_proc	__abal_keyword[0x0033]	 /*Proc*/
#define	__abal_keyword_exit	__abal_keyword[0x0034]	 /*Exit*/
#define	__abal_keyword_endproc	__abal_keyword[0x0035]	 /*EndProc*/
#define	__abal_keyword_print 	__abal_keyword[0x0036]	 /*Print*/
#define	__abal_keyword_ask  	__abal_keyword[0x0037]	 /*Ask*/
#define	__abal_keyword_page  	__abal_keyword[0x0038]	 /*Page*/
#define	__abal_keyword_left	__abal_keyword[0x0039]	 /*Left*/
#define	__abal_keyword_right 	__abal_keyword[0x003A]	 /*Right*/
#define	__abal_keyword_substr	__abal_keyword[0x003B]	 /*Substr*/
#define	__abal_keyword_assign 	__abal_keyword[0x003C]	 /*Assign*/
#define	__abal_keyword_name   	__abal_keyword[0x003D]	 /*Name*/
#define	__abal_keyword_open   	__abal_keyword[0x003E]	 /*Open*/
#define	__abal_keyword_cfile  	__abal_keyword[0x003F]	 /*Cfile*/
#define	__abal_keyword_read   	__abal_keyword[0x0040]	 /*Read*/
#define	__abal_keyword_write  	__abal_keyword[0x0041]	 /*Write*/
#define	__abal_keyword_close  	__abal_keyword[0x0042]	 /*Close*/
#define	__abal_keyword_dfile  	__abal_keyword[0x0043]	 /*Dfile*/
#define	__abal_keyword_rename 	__abal_keyword[0x0044]	 /*Rename*/
#define	__abal_keyword_insert 	__abal_keyword[0x0045]	 /*Insert*/
#define	__abal_keyword_search 	__abal_keyword[0x0046]	 /*Search*/
#define	__abal_keyword_modif  	__abal_keyword[0x0047]	 /*Modif*/
#define	__abal_keyword_delete 	__abal_keyword[0x0048]	 /*Delete*/
#define	__abal_keyword_down   	__abal_keyword[0x0049]	 /*Down*/
#define	__abal_keyword_up     	__abal_keyword[0x004A]	 /*Up*/
#define	__abal_keyword_down_m 	__abal_keyword[0x004B]	 /*Down.M*/
#define	__abal_keyword_up_m   	__abal_keyword[0x004C]	 /*Up.M*/
#define	__abal_keyword_search_m	__abal_keyword[0x004D]	 /*Search.M*/
#define	__abal_keyword_len    	__abal_keyword[0x004E]	 /*Len*/
#define	__abal_keyword_filler  	__abal_keyword[0x004F]	 /*Filler*/
#define	__abal_keyword_pragma  	__abal_keyword[0x0050]	 /*#Pragma*/
#define	__abal_keyword_enter   	__abal_keyword[0x0051]	 /*Enter*/
#define	__abal_keyword_leave   	__abal_keyword[0x0052]	 /*Leave*/
#define	__abal_keyword_key   	__abal_keyword[0x0053]	 /*Key*/
#define	__abal_keyword_ckey   	__abal_keyword[0x0054]	 /*Ckey*/
#define	__abal_keyword_link   	__abal_keyword[0x0055]	 /*Link*/
#define	__abal_keyword_clink   	__abal_keyword[0x0056]	 /*Llink*/
#define	__abal_keyword_posit   	__abal_keyword[0x0057]	 /*Posit*/
#define	__abal_keyword_count   	__abal_keyword[0x0058]	 /*Count*/
#define	__abal_keyword_driver  	__abal_keyword[0x0059]	 /*Driver*/
#define	__abal_keyword_down_l 	__abal_keyword[0x005A]	 /*Down.L*/
#define	__abal_keyword_up_l   	__abal_keyword[0x005B]	 /*Up.L*/
#define	__abal_keyword_search_l	__abal_keyword[0x005C]	 /*Search.L*/

#endif	/* _abalkeywords_c */



