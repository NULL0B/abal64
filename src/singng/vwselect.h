
#ifndef _vwselect_h
#define _vwselect_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.33                                                */
/* Production     : C                                                        */
/* Project        : vwselect.xml                                             */
/* Target         : vwselect.h                                               */
/* Identification : 0.0-1189177890-7931.7930                                 */
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
	char * msg_Auto2898[8];
	char * hint_Auto2898[8];
	char * hint_Auto2899[8];
	char * msg_Auto2900[8];
	char * hint_Auto2900[8];
	char * msg_Auto2901[8];
	char * hint_Auto2901[8];
	char * msg_Auto2902[8];
	char * hint_Auto2902[8];
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
	char * msg_Auto2903[8];
	char * hint_Auto2903[8];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * msg_Auto2904[8];
	char * hint_Auto2904[8];
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_Auto2905[8];
	char * hint_Auto2905[8];
	char * msg_Auto2906[8];
	char * hint_Auto2906[8];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * msg_Auto2907[8];
	char * hint_Auto2907[8];
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
	char * msg_Auto2908[8];
	char * hint_Auto2908[8];
	char * msg_Auto2909[8];
	char * hint_Auto2909[8];
	char * msg_Auto2910[8];
	char * hint_Auto2910[8];
	char * msg_Auto2911[8];
	char * hint_Auto2911[8];
	char * msg_Auto2912[8];
	char * hint_Auto2912[8];
	char * msg_Auto2913[8];
	char * hint_Auto2913[8];
	char * hint_Auto2914[8];
	char	signature[1];
	};
void	vwselect_position_at(struct vwselect_context * _Context,int x,int y);
void	vwselect_SetVars(struct vwselect_context * _Context);
void	vwselect_GetVars(struct vwselect_context * _Context);

#endif /* _vwselect_h */
