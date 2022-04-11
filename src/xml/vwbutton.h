
#ifndef _vwbutton_h
#define _vwbutton_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwbutton.xml                                             */
/* Target         : vwbutton.h                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */


private struct vwbutton_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	char * msg_WidgetProperties[8];
	char * hint_WidgetProperties[8];
	int	x_WidgetProperties;
	int	y_WidgetProperties;
	int	w_WidgetProperties;
	int	h_WidgetProperties;
	char * msg_Auto3601[8];
	char * hint_Auto3601[8];
	char * hint_Auto3602[8];
	char * msg_Auto3603[8];
	char * hint_Auto3603[8];
	char * msg_Auto3604[8];
	char * hint_Auto3604[8];
	char * msg_Auto3605[8];
	char * hint_Auto3605[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * msg_WidgetClass[8];
	char * hint_WidgetClass[8];
	int	value_WidgetClass;
	char * hint_Hint[8];
	char	buffer_Hint[256];
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_IsLock[8];
	int	trigger_IsLock;
	char * hint_IsLock[8];
	int	value_IsLock;
	char * msg_Type[8];
	char * hint_Type[8];
	int	value_Type;
	char * hint_Format[8];
	char	buffer_Format[256];
	char * msg_TargetSelect[8];
	int	trigger_TargetSelect;
	char * hint_TargetSelect[8];
	int	s_TargetSelect;
	void *	p_TargetSelect;
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_TextColour[8];
	char	buffer_TextColour[7];
	char * hint_Background[8];
	char	buffer_Background[7];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * hint_ShowStyle[8];
	char	buffer_ShowStyle[256];
	char * hint_FocusStyle[8];
	char	buffer_FocusStyle[256];
	char * hint_FocusPress[8];
	char	buffer_FocusPress[256];
	char * hint_PayLoad[8];
	char	buffer_PayLoad[256];
	char * msg_IswResize[8];
	int	trigger_IswResize;
	char * hint_IswResize[8];
	int	value_IswResize;
	char * msg_IshResize[8];
	int	trigger_IshResize;
	char * hint_IshResize[8];
	int	value_IshResize;
	char * msg_IsBold[8];
	int	trigger_IsBold;
	char * hint_IsBold[8];
	int	value_IsBold;
	char * msg_IsUnderline[8];
	int	trigger_IsUnderline;
	char * hint_IsUnderline[8];
	int	value_IsUnderline;
	char * msg_IsShadow[8];
	int	trigger_IsShadow;
	char * hint_IsShadow[8];
	int	value_IsShadow;
	char * msg_Auto3606[8];
	char * hint_Auto3606[8];
	char * msg_Auto3607[8];
	char * hint_Auto3607[8];
	char * msg_Auto3608[8];
	char * hint_Auto3608[8];
	char * msg_Auto3609[8];
	char * hint_Auto3609[8];
	char * msg_Auto3610[8];
	char * hint_Auto3610[8];
	char * msg_Auto3611[8];
	char * hint_Auto3611[8];
	char * msg_Auto3612[8];
	char * hint_Auto3612[8];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_Auto3613[8];
	char * hint_Auto3613[8];
	char * msg_Auto3614[8];
	char * hint_Auto3614[8];
	char * msg_Auto3615[8];
	char * hint_Auto3615[8];
	char * msg_Auto3616[8];
	char * hint_Auto3616[8];
	char * msg_Auto3617[8];
	char * hint_Auto3617[8];
	char * msg_Auto3618[8];
	char * hint_Auto3618[8];
	char * msg_PayLoadSelect[8];
	int	trigger_PayLoadSelect;
	char * hint_PayLoadSelect[8];
	int	s_PayLoadSelect;
	void *	p_PayLoadSelect;
	char * msg_Auto3619[8];
	char * hint_Auto3619[8];
	char * msg_Auto3620[8];
	char * hint_Auto3620[8];
	char * msg_Auto3621[8];
	char * hint_Auto3621[8];
	char * msg_IsInhibit[8];
	char * hint_IsInhibit[8];
	int	value_IsInhibit;
	char * hint_Auto3622[8];
	char	signature[1];
	};
void	vwbutton_position_at(struct vwbutton_context * _Context,int x,int y);
void	vwbutton_SetVars(struct vwbutton_context * _Context);
void	vwbutton_GetVars(struct vwbutton_context * _Context);

#endif /* _vwbutton_h */
