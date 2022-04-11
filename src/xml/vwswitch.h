
#ifndef _vwswitch_h
#define _vwswitch_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwswitch.xml                                             */
/* Target         : vwswitch.h                                               */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */


private struct vwswitch_context {
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
	char * msg_Auto3617[8];
	char * hint_Auto3617[8];
	char * hint_Auto3618[8];
	char * msg_Auto3619[8];
	char * hint_Auto3619[8];
	char * msg_IsInhibit[8];
	char * hint_IsInhibit[8];
	int	value_IsInhibit;
	char * msg_Auto3620[8];
	char * hint_Auto3620[8];
	char * msg_Auto3621[8];
	char * hint_Auto3621[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * msg_WidgetClass[8];
	char * hint_WidgetClass[8];
	int	value_WidgetClass;
	char * hint_Hint[8];
	char	buffer_Hint[256];
	char * msg_IsLock[8];
	int	trigger_IsLock;
	char * hint_IsLock[8];
	int	value_IsLock;
	char * msg_IsInterface[8];
	int	trigger_IsInterface;
	char * hint_IsInterface[8];
	int	value_IsInterface;
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_TextColour[8];
	char	buffer_TextColour[7];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * hint_Background[8];
	char	buffer_Background[7];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_Auto3622[8];
	char * hint_Auto3622[8];
	char * hint_PayLoad[8];
	char	buffer_PayLoad[256];
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
	char * msg_IswResize[8];
	int	trigger_IswResize;
	char * hint_IswResize[8];
	int	value_IswResize;
	char * msg_IshResize[8];
	int	trigger_IshResize;
	char * hint_IshResize[8];
	int	value_IshResize;
	char * msg_Auto3623[8];
	char * hint_Auto3623[8];
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_Auto3624[8];
	char * hint_Auto3624[8];
	char * msg_Auto3625[8];
	char * hint_Auto3625[8];
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
	char * msg_Auto3632[8];
	char * hint_Auto3632[8];
	char * msg_Auto3633[8];
	char * hint_Auto3633[8];
	char * msg_Auto3634[8];
	char * hint_Auto3634[8];
	char * hint_Auto3635[8];
	char	signature[1];
	};
void	vwswitch_position_at(struct vwswitch_context * _Context,int x,int y);
void	vwswitch_SetVars(struct vwswitch_context * _Context);
void	vwswitch_GetVars(struct vwswitch_context * _Context);

#endif /* _vwswitch_h */
