
#ifndef _vwbutton_h
#define _vwbutton_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vwbutton.xml                                             */
/* Target         : vwbutton.h                                               */
/* Identification : 0.0-1195558265-4824.4823                                 */
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
	char * msg_Auto3028[8];
	char * hint_Auto3028[8];
	char * hint_Auto3029[8];
	char * msg_Auto3030[8];
	char * hint_Auto3030[8];
	char * msg_Auto3031[8];
	char * hint_Auto3031[8];
	char * msg_Auto3032[8];
	char * hint_Auto3032[8];
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
	char * msg_Auto3033[8];
	char * hint_Auto3033[8];
	char * msg_Auto3034[8];
	char * hint_Auto3034[8];
	char * msg_Auto3035[8];
	char * hint_Auto3035[8];
	char * msg_Auto3036[8];
	char * hint_Auto3036[8];
	char * msg_Auto3037[8];
	char * hint_Auto3037[8];
	char * msg_Auto3038[8];
	char * hint_Auto3038[8];
	char * msg_Auto3039[8];
	char * hint_Auto3039[8];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_Auto3040[8];
	char * hint_Auto3040[8];
	char * msg_Auto3041[8];
	char * hint_Auto3041[8];
	char * msg_Auto3042[8];
	char * hint_Auto3042[8];
	char * msg_Auto3043[8];
	char * hint_Auto3043[8];
	char * msg_Auto3044[8];
	char * hint_Auto3044[8];
	char * msg_Auto3045[8];
	char * hint_Auto3045[8];
	char * msg_PayLoadSelect[8];
	int	trigger_PayLoadSelect;
	char * hint_PayLoadSelect[8];
	int	s_PayLoadSelect;
	void *	p_PayLoadSelect;
	char * msg_Auto3046[8];
	char * hint_Auto3046[8];
	char * msg_Auto3047[8];
	char * hint_Auto3047[8];
	char * hint_Auto3048[8];
	char	signature[1];
	};
void	vwbutton_position_at(struct vwbutton_context * _Context,int x,int y);
void	vwbutton_SetVars(struct vwbutton_context * _Context);
void	vwbutton_GetVars(struct vwbutton_context * _Context);

#endif /* _vwbutton_h */
