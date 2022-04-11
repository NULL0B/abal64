#ifndef	_abalterm_h
#define	_abalterm_h

#ifdef	_SINGABAL_C
/*	--------------------------------------------------	*/
/*	These are instanced only in the above defined file	*/
/*	--------------------------------------------------	*/
public	char	*	__abal_term[] = {
	(char *) /* create		*/ "Create",
	(char *) /* oncreate		*/ "OnCreate",
	(char *) /* show		*/ "Show",
	(char *) /* onshow		*/ "Onshow",
	(char *) /* get_focus		*/ "Getfocus",
	(char *) /* focus		*/ "Focus",
	(char *) /* onfocus		*/ "Onfocus",
	(char *) /* lose_focus		*/ "Losefocus",
	(char *) /* event		*/ "Event",
	(char *) /* onevent		*/ "Onevent",
	(char *) /* hide		*/ "Hide",
	(char *) /* remove		*/ "Remove",
	(char *) /* action		*/ "Action",
	(char *) /* flush		*/ "Flush",
	(char *) /* iterate		*/ "Iterate",
	(char *) /* finalise		*/ "Finalise",
	(char *) /* exec 		*/ "Exec",
	(char *) /* onexec 		*/ "Onexec",
	(char *) /* attach		*/ "Attach",
	(char *) /* detach		*/ "Detach",
	(char *) /* visual_def		*/ "visual.def",
	(char *) /* printer_def		*/ "printer.def",
	(char *) /* mimo_as		*/ "mimo.as",
	(char *) /* visual_initialise	*/ "VisualInitialise",
	(char *) /* visual_liberate	*/ "VisualLiberate",
	(char *) /* visual_palette	*/ "VisualPalette",
	(char *) /* visual_font		*/ "VisualFont",
	(char *) /* visual_fill		*/ "VisualFill",
	(char *) /* visual_text		*/ "VisualText",
	(char *) /* visual_edit		*/ "VisualEdit",
	(char *) /* visual_zone		*/ "VisualZone",
	(char *) /* visual_tabpage	*/ "VisualTabPage",
	(char *) /* visual_progress	*/ "VisualProgress",
	(char *) /* visual_table  	*/ "VisualTable",
	(char *) /* visual_scroll  	*/ "VisualScroll",
	(char *) /* visual_select  	*/ "VisualSelect",
	(char *) /* visual_switch  	*/ "VisualSwitch",
	(char *) /* visual_graph  	*/ "VisualGraph",
	(char *) /* visual_freeze  	*/ "VisualFreeze",
	(char *) /* visual_thaw  	*/ "VisualThaw",
	(char *) /* visual_line  	*/ "VisualLine",
	(char *) /* visual_window  	*/ "VisualWindow",
	(char *) /* visual_image  	*/ "VisualImage",
	(char *) /* visual_button  	*/ "VisualButton",
	(char *) /* visual_check  	*/ "VisualCheck",
	(char *) /* visual_radio  	*/ "VisualRadio",
	(char *) /* visual_event   	*/ "VisualEvent",
	(char *) /* visual_key  	*/ "VisualKey",
	(char *) /* visual_colour	*/ "VisualColour",
	(char *) /* visual_buffer	*/ "VisualBuffer",
	(char *) /* visual_page		*/ "VisualPage",
	(char *) /* visual_get		*/ "VisualGet",
	(char *) /* visual_getrow	*/ "VisualGetRow",
	(char *) /* visual_putrow	*/ "VisualPutRow",
	(char *) /* visual_put		*/ "VisualPut",
	(char *) /* visual_drop		*/ "VisualDrop",
	(char *) /* visual_transform	*/ "VisualTransform",
	(char *) /* visual_viewport 	*/ "VisualViewPort",
	(char *) /* mouse_column	*/ "MouseColumn",
	(char *) /* mouse_button	*/ "MouseButton",
	(char *) /* mouse_type		*/ "MouseType",
	(char *) /* mouse_row		*/ "MouseRow",
	(char *) /* visual_keycode	*/ "KeyCode=VisualKey(1)",
	(char *) /* focus_item		*/ "FocusItem",
	(char *) /* Resize		*/ "Resize",
	(char *) /* string_zero		*/ "0",

	/* Terms used by the ABAL PAGE module */
	/* ---------------------------------- */

	(char *) /* keyword_raster	*/ "Raster",
	(char *) /* keyword_printer	*/ "Printer",
	(char *) /* keyword_method	*/ "Method",
	(char *) /* keyword_row   	*/ "Row",
	(char *) /* keyword_handle	*/ "Handle",
	(char *) /* keyword_paper	*/ "Paper",
	(char *) /* keyword_margin	*/ "Margin",
	(char *) /* keyword_width	*/ "Width",
	(char *) /* keyword_height	*/ "Height",
	(char *) /* keyword_top		*/ "Top",
	(char *) /* keyword_bottom	*/ "Bottom",
	(char *) /* keyword_buffer	*/ "Buffer",
	(char *) /* keyword_dpi		*/ "Dpi",
	(char *) /* keyword_control	*/ "Control",
	(char *) /* keyword_options	*/ "Options",
	(char *) /* visual_control	*/ "VisualControl",
	(char *) /* visual_control	*/ "ptr o$=10",

	/* SQ access keywords */
	/* ------------------ */
	(char *) "Read",
	(char *) "Write",
	(char *) "BackSpace",
	(char *) "VisualActivate",
	(char *) /* keyword_units	*/ "Units",
	(char *) "Sector"

	};


#else
/*	--------------------------------------------------	*/
/*	Otherwise extern visibillity to the language terms	*/
/*	--------------------------------------------------	*/
extern	char *	__abal_term[];

#endif

#define	__abal_method_create		__abal_term[0x0000]	/*Create*/
#define	__abal_method_oncreate		__abal_term[0x0001]	/*OnCreate*/
#define	__abal_method_show		__abal_term[0x0002]	/*Show*/
#define	__abal_method_onshow		__abal_term[0x0003]	/*OnShow*/
#define	__abal_method_get_focus		__abal_term[0x0004]	/*GetFocus*/
#define	__abal_method_focus		__abal_term[0x0005]	/*Focus*/
#define	__abal_method_onfocus		__abal_term[0x0006]	/*OnFocus*/
#define	__abal_method_lose_focus	__abal_term[0x0007]	/*LoseFocus*/
#define	__abal_method_event		__abal_term[0x0008]	/*Event*/
#define	__abal_method_onevent		__abal_term[0x0009]	/*OnEvent*/
#define	__abal_method_hide		__abal_term[0x000A]	/*Hide*/
#define	__abal_method_remove		__abal_term[0x000B]	/*Remove*/
#define	__abal_method_action		__abal_term[0x000C]	/*Action*/
#define	__abal_method_flush		__abal_term[0x000D]	/*Flush*/
#define	__abal_method_iterate		__abal_term[0x000E]	/*Iterate*/
#define	__abal_method_finalise		__abal_term[0x000F]	/*Finalise*/
#define	__abal_method_exec 		__abal_term[0x0010]	/*Exec*/
#define	__abal_method_onexec 		__abal_term[0x0011]	/*OnExec*/
#define	__abal_method_attach		__abal_term[0x0012]	/*Attach*/
#define	__abal_method_detach		__abal_term[0x0013]	/*Detach*/
#define	__abal_visual_def		__abal_term[0x0014]	/*visual.def*/
#define	__abal_printer_def		__abal_term[0x0015]	/*printer.def*/
#define	__abal_mimo_as			__abal_term[0x0016]	/*mimo.as*/
#define	__abal_visual_initialise	__abal_term[0x0017]	/*VisualInitialise*/
#define	__abal_visual_liberate		__abal_term[0x0018]	/*VisualLiberate*/
#define	__abal_visual_palette		__abal_term[0x0019]	/*VisualPalette*/
#define	__abal_visual_font		__abal_term[0x001A]	/*VisualFont*/
#define	__abal_visual_fill		__abal_term[0x001B]	/*VisualFill*/
#define	__abal_visual_text		__abal_term[0x001C]	/*VisualText*/
#define	__abal_visual_edit		__abal_term[0x001D]	/*VisualEdit*/
#define	__abal_visual_zone		__abal_term[0x001E]	/*VisualZone*/
#define	__abal_visual_tabpage		__abal_term[0x001F]	/*VisualTabPage*/
#define	__abal_visual_progress		__abal_term[0x0020]	/*VisualProgress*/
#define	__abal_visual_table  		__abal_term[0x0021]	/*VisualTable*/
#define	__abal_visual_scroll  		__abal_term[0x0022]	/*VisualScroll*/
#define	__abal_visual_select  		__abal_term[0x0023]	/*VisualSelect*/
#define	__abal_visual_switch  		__abal_term[0x0024]	/*VisualSwitch*/
#define	__abal_visual_graph  		__abal_term[0x0025]	/*VisualGraph*/
#define	__abal_visual_freeze  		__abal_term[0x0026]	/*VisualFreeze*/
#define	__abal_visual_thaw  		__abal_term[0x0027]	/*VisualThaw*/
#define	__abal_visual_line  		__abal_term[0x0028]	/*VisualLine*/
#define	__abal_visual_window  		__abal_term[0x0029]	/*VisualWindow*/
#define	__abal_visual_image  		__abal_term[0x002A]	/*VisualImage*/
#define	__abal_visual_button  		__abal_term[0x002B]	/*VisualButton*/
#define	__abal_visual_check  		__abal_term[0x002C]	/*VisualCheck*/
#define	__abal_visual_radio  		__abal_term[0x002D]	/*VisualRadio*/
#define	__abal_visual_event   		__abal_term[0x002E]	/*VisualEvent*/
#define	__abal_visual_key  		__abal_term[0x002F]	/*VisualKey*/
#define	__abal_visual_colour		__abal_term[0x0030]	/*VisualColour*/
#define	__abal_visual_buffer		__abal_term[0x0031]	/*VisualBuffer*/
#define	__abal_visual_page		__abal_term[0x0032]	/*VisualPage*/
#define	__abal_visual_get		__abal_term[0x0033]	/*VisualGet*/
#define	__abal_visual_getrow		__abal_term[0x0034]	/*VisualGetRow*/
#define	__abal_visual_putrow		__abal_term[0x0035]	/*VisualPutRow*/
#define	__abal_visual_put		__abal_term[0x0036]	/*VisualPut*/
#define	__abal_visual_drop		__abal_term[0x0037]	/*VisualDrop*/
#define	__abal_visual_transform		__abal_term[0x0038]	/*VisualTransform*/
#define	__abal_visual_viewport 		__abal_term[0x0039]	/*VisualViewPort*/
#define	__abal_mouse_column		__abal_term[0x003A]	/*MouseColumn*/
#define	__abal_mouse_button		__abal_term[0x003B]	/*MouseButton*/
#define	__abal_mouse_type		__abal_term[0x003C]	/*MouseType*/
#define	__abal_mouse_row		__abal_term[0x003D]	/*MouseRow*/
#define	__abal_visual_keycode		__abal_term[0x003E]	/*KeyCode=VisualKey(1)*/
#define	__abal_focus_item		__abal_term[0x003F]	/*FocusItem*/
#define	__abal_method_Resize		__abal_term[0x0040]	/*Resize*/
#define	__abal_string_zero		__abal_term[0x0041]	/*0*/

#define	__abal_keyword_raster		__abal_term[0x0042]	/*Raster*/
#define	__abal_keyword_printer		__abal_term[0x0043]	/*Printer*/
#define	__abal_keyword_method		__abal_term[0x0044]	/*Method*/
#define	__abal_keyword_row   		__abal_term[0x0045]	/*Row*/
#define	__abal_keyword_handle		__abal_term[0x0046]	/*Handle*/
#define	__abal_keyword_paper		__abal_term[0x0047]	/*Paper*/
#define	__abal_keyword_margin		__abal_term[0x0048]	/*Margin*/
#define	__abal_keyword_width		__abal_term[0x0049]	/*Width*/
#define	__abal_keyword_height		__abal_term[0x004A]	/*Height*/
#define	__abal_keyword_top		__abal_term[0x004B]	/*Top*/
#define	__abal_keyword_bottom		__abal_term[0x004C]	/*Bottom*/
#define	__abal_keyword_buffer		__abal_term[0x004D]	/*Buffer*/
#define	__abal_keyword_dpi		__abal_term[0x004E]	/*Dpi*/
#define	__abal_keyword_control		__abal_term[0x004F]	/*Control*/
#define	__abal_keyword_options		__abal_term[0x0050]	/*Options*/
#define	__abal_visual_control 		__abal_term[0x0051]	/*VisualControl*/
#define	__abal_overlay_object		__abal_term[0x0052]	/*VisualObject */

#define	__abal_keyword_read  		__abal_term[0x0053]	/*Read */
#define	__abal_keyword_write  		__abal_term[0x0054]	/*Write*/
#define	__abal_keyword_backspace	__abal_term[0x0055]	/*Backspace*/
#define	__abal_visual_activate   	__abal_term[0x0056]	/*VisualActivate*/
#define	__abal_visual_units      	__abal_term[0x0057]	/*Units*/
#define	__abal_visual_sector	      	__abal_term[0x0058]	/*Sector*/


#endif	/* _abalterm_h */
	/* ----------- */

