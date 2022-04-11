
#ifndef _vwcheck_h
#define _vwcheck_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwcheck.xml                                              */
/* Target         : vwcheck.h                                                */
/* Identification : 0.0-1177511937-4355.4354                                 */
/* ------------------------------------------------------------------------- */


private struct vwcheck_context {
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
	char * msg_Auto2773[8];
	char * hint_Auto2773[8];
	char * hint_Auto2774[8];
	char * msg_Auto2775[8];
	char * hint_Auto2775[8];
	char * msg_Auto2776[8];
	char * hint_Auto2776[8];
	char * msg_Auto2777[8];
	char * hint_Auto2777[8];
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
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_PayLoad[8];
	char	buffer_PayLoad[256];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * hint_FocusStyle[8];
	char	buffer_FocusStyle[256];
	char * msg_IswResize[8];
	int	trigger_IswResize;
	char * hint_IswResize[8];
	int	value_IswResize;
	char * msg_IshResize[8];
	int	trigger_IshResize;
	char * hint_IshResize[8];
	int	value_IshResize;
	char * msg_Auto2778[8];
	char * hint_Auto2778[8];
	char * msg_Auto2779[8];
	char * hint_Auto2779[8];
	char * msg_Auto2780[8];
	char * hint_Auto2780[8];
	char * msg_Auto2781[8];
	char * hint_Auto2781[8];
	char * msg_Auto2782[8];
	char * hint_Auto2782[8];
	char * msg_Auto2783[8];
	char * hint_Auto2783[8];
	char * msg_Auto2784[8];
	char * hint_Auto2784[8];
	char * msg_Auto2785[8];
	char * hint_Auto2785[8];
	char * msg_Auto2786[8];
	char * hint_Auto2786[8];
	char * msg_Auto2787[8];
	char * hint_Auto2787[8];
	char * hint_Auto2788[8];
	char	signature[1];
	};
void	vwcheck_position_at(struct vwcheck_context * _Context,int x,int y);
void	vwcheck_SetVars(struct vwcheck_context * _Context);
void	vwcheck_GetVars(struct vwcheck_context * _Context);

#endif /* _vwcheck_h */
