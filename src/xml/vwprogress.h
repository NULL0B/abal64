
#ifndef _vwprogress_h
#define _vwprogress_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwprogress.xml                                           */
/* Target         : vwprogress.h                                             */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */


private struct vwprogress_context {
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
	char * msg_Auto3613[8];
	char * hint_Auto3613[8];
	char * hint_Auto3614[8];
	char * msg_Auto3615[8];
	char * hint_Auto3615[8];
	int	value_Auto3615;
	char * msg_Auto3616[8];
	char * hint_Auto3616[8];
	char * msg_Auto3617[8];
	char * hint_Auto3617[8];
	char * msg_IsBold[8];
	int	trigger_IsBold;
	char * hint_IsBold[8];
	int	value_IsBold;
	char * msg_IsUnderline[8];
	int	trigger_IsUnderline;
	char * hint_IsUnderline[8];
	int	value_IsUnderline;
	char * msg_Auto3618[8];
	char * hint_Auto3618[8];
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
	char * msg_Auto3619[8];
	char * hint_Auto3619[8];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_Auto3620[8];
	char * hint_Auto3620[8];
	char * msg_Auto3621[8];
	char * hint_Auto3621[8];
	char * msg_Auto3622[8];
	char * hint_Auto3622[8];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * msg_Type[8];
	char * hint_Type[8];
	int	value_Type;
	char * hint_TextColour[8];
	char	buffer_TextColour[7];
	char * hint_Background[8];
	char	buffer_Background[7];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_Auto3623[8];
	char * hint_Auto3623[8];
	char * msg_Auto3624[8];
	char * hint_Auto3624[8];
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
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
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
	char * hint_Auto3632[8];
	char	signature[1];
	};
void	vwprogress_position_at(struct vwprogress_context * _Context,int x,int y);
void	vwprogress_SetVars(struct vwprogress_context * _Context);
void	vwprogress_GetVars(struct vwprogress_context * _Context);

#endif /* _vwprogress_h */
