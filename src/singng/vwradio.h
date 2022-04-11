
#ifndef _vwradio_h
#define _vwradio_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwradio.xml                                              */
/* Target         : vwradio.h                                                */
/* Identification : 0.0-1177511938-4355.4354                                 */
/* ------------------------------------------------------------------------- */


private struct vwradio_context {
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
	char * msg_Auto2785[8];
	char * hint_Auto2785[8];
	char * hint_Auto2786[8];
	char * msg_Auto2787[8];
	char * hint_Auto2787[8];
	char * msg_Auto2788[8];
	char * hint_Auto2788[8];
	char * msg_Auto2789[8];
	char * hint_Auto2789[8];
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
	char * msg_Auto2790[8];
	char * hint_Auto2790[8];
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
	char * msg_Auto2791[8];
	char * hint_Auto2791[8];
	char * msg_Auto2792[8];
	char * hint_Auto2792[8];
	char * msg_Auto2793[8];
	char * hint_Auto2793[8];
	char * hint_PayLoad[8];
	char	buffer_PayLoad[256];
	char * msg_Auto2794[8];
	char * hint_Auto2794[8];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_IswResize[8];
	int	trigger_IswResize;
	char * hint_IswResize[8];
	int	value_IswResize;
	char * msg_IshResize[8];
	int	trigger_IshResize;
	char * hint_IshResize[8];
	int	value_IshResize;
	char * msg_Auto2795[8];
	char * hint_Auto2795[8];
	char * msg_Auto2796[8];
	char * hint_Auto2796[8];
	char * msg_Auto2797[8];
	char * hint_Auto2797[8];
	char * msg_Auto2798[8];
	char * hint_Auto2798[8];
	char * msg_Auto2799[8];
	char * hint_Auto2799[8];
	char * hint_Auto2800[8];
	char	signature[1];
	};
void	vwradio_position_at(struct vwradio_context * _Context,int x,int y);
void	vwradio_SetVars(struct vwradio_context * _Context);
void	vwradio_GetVars(struct vwradio_context * _Context);

#endif /* _vwradio_h */
