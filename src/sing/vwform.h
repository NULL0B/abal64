
#ifndef _vwform_h
#define _vwform_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 4.1a.0.09                                                */
/* Production     : C                                                        */
/* Project        : vwform.xml                                               */
/* Target         : vwform.h                                                 */
/* Identification : 0.0-1417705916-9408.9198                                 */
/* ------------------------------------------------------------------------- */


private struct vwform_context {
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
	char * msg_Auto2543[8];
	char * hint_Auto2543[8];
	char * hint_Auto2544[8];
	char * msg_Auto2545[8];
	char * hint_Auto2545[8];
	char * msg_Auto2546[8];
	char * hint_Auto2546[8];
	char * msg_Auto2547[8];
	char * hint_Auto2547[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * msg_WidgetStorage[8];
	char * hint_WidgetStorage[8];
	int	value_WidgetStorage;
	char * hint_Hint[8];
	char	buffer_Hint[256];
	char * msg_IsLock[8];
	int	trigger_IsLock;
	char * hint_IsLock[8];
	int	value_IsLock;
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * hint_PayLoad[8];
	char	buffer_PayLoad[256];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * hint_TextColour[8];
	char	buffer_TextColour[7];
	char * hint_Background[8];
	char	buffer_Background[7];
	char * msg_IsBold[8];
	int	trigger_IsBold;
	char * hint_IsBold[8];
	int	value_IsBold;
	char * msg_Compact[8];
	int	trigger_Compact;
	char * hint_Compact[8];
	int	value_Compact;
	char * msg_LineFocus[8];
	int	trigger_LineFocus;
	char * hint_LineFocus[8];
	int	value_LineFocus;
	char * msg_IsUnderline[8];
	int	trigger_IsUnderline;
	char * hint_IsUnderline[8];
	int	value_IsUnderline;
	char * msg_IsShadow[8];
	int	trigger_IsShadow;
	char * hint_IsShadow[8];
	int	value_IsShadow;
	char * hint_Format[8];
	char	buffer_Format[256];
	char * msg_IswResize[8];
	int	trigger_IswResize;
	char * hint_IswResize[8];
	int	value_IswResize;
	char * msg_IshResize[8];
	int	trigger_IshResize;
	char * hint_IshResize[8];
	int	value_IshResize;
	char * msg_Auto2548[8];
	char * hint_Auto2548[8];
	char * msg_Auto2549[8];
	char * hint_Auto2549[8];
	char * msg_Auto2550[8];
	char * hint_Auto2550[8];
	char * msg_Auto2551[8];
	char * hint_Auto2551[8];
	char * msg_Auto2552[8];
	char * hint_Auto2552[8];
	char * msg_Auto2553[8];
	char * hint_Auto2553[8];
	char * msg_Auto2554[8];
	char * hint_Auto2554[8];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_Auto2555[8];
	char * hint_Auto2555[8];
	char * msg_Auto2556[8];
	char * hint_Auto2556[8];
	char * msg_Auto2557[8];
	char * hint_Auto2557[8];
	char * msg_WidgetClass[8];
	char * hint_WidgetClass[8];
	int	value_WidgetClass;
	char * msg_Auto2558[8];
	char * hint_Auto2558[8];
	char * msg_Auto2559[8];
	char * hint_Auto2559[8];
	char * msg_Auto2560[8];
	char * hint_Auto2560[8];
	char * msg_Auto2561[8];
	char * hint_Auto2561[8];
	char * msg_Auto2562[8];
	char * hint_Auto2562[8];
	char * hint_Auto2563[8];
	char	signature[1];
	};
void	vwform_position_at(struct vwform_context * _Context,int x, int y);
void	vwform_SetVars(struct vwform_context * _Context);
void	vwform_GetVars(struct vwform_context * _Context);

#endif /* _vwform_h */
