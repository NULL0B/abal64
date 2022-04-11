
#ifndef _vwselect_h
#define _vwselect_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwselect.xml                                             */
/* Target         : vwselect.h                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */


private struct vwselect_context {
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
	char * msg_Auto3616[8];
	char * hint_Auto3616[8];
	char * hint_Auto3617[8];
	char * msg_Auto3618[8];
	char * hint_Auto3618[8];
	char * msg_IsInhibit[8];
	char * hint_IsInhibit[8];
	int	value_IsInhibit;
	char * msg_Auto3619[8];
	char * hint_Auto3619[8];
	char * msg_Auto3620[8];
	char * hint_Auto3620[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * msg_WidgetClass[8];
	char * hint_WidgetClass[8];
	int	value_WidgetClass;
	char * hint_Hint[8];
	char	buffer_Hint[256];
	char * msg_IsSpecial[8];
	int	trigger_IsSpecial;
	char * hint_IsSpecial[8];
	int	value_IsSpecial;
	char * msg_IsLock[8];
	int	trigger_IsLock;
	char * hint_IsLock[8];
	int	value_IsLock;
	char * msg_IsInterface[8];
	int	trigger_IsInterface;
	char * hint_IsInterface[8];
	int	value_IsInterface;
	char * msg_IsBold[8];
	int	trigger_IsBold;
	char * hint_IsBold[8];
	int	value_IsBold;
	char * msg_Auto3621[8];
	char * hint_Auto3621[8];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * msg_Auto3622[8];
	char * hint_Auto3622[8];
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_Auto3623[8];
	char * hint_Auto3623[8];
	char * msg_Auto3624[8];
	char * hint_Auto3624[8];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * msg_Auto3625[8];
	char * hint_Auto3625[8];
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
	char * msg_Auto3626[8];
	char * hint_Auto3626[8];
	char * msg_Auto3627[8];
	char * hint_Auto3627[8];
	char * msg_Auto3628[8];
	char * hint_Auto3628[8];
	char * msg_Auto3629[8];
	char * hint_Auto3629[8];
	char * msg_Auto3630[8];
	char * hint_Auto3630[8];
	char * msg_Auto3631[8];
	char * hint_Auto3631[8];
	char * hint_Auto3632[8];
	char	signature[1];
	};
void	vwselect_position_at(struct vwselect_context * _Context,int x,int y);
void	vwselect_SetVars(struct vwselect_context * _Context);
void	vwselect_GetVars(struct vwselect_context * _Context);

#endif /* _vwselect_h */
