
#ifndef _vwgraph_h
#define _vwgraph_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwgraph.xml                                              */
/* Target         : vwgraph.h                                                */
/* Identification : 0.0-1177511938-4355.4354                                 */
/* ------------------------------------------------------------------------- */


private struct vwgraph_context {
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
	char * msg_Auto2780[8];
	char * hint_Auto2780[8];
	char * hint_Auto2781[8];
	char * msg_Auto2782[8];
	char * hint_Auto2782[8];
	char * msg_Auto2783[8];
	char * hint_Auto2783[8];
	char * hint_Auto2784[8];
	char * msg_IswResize[8];
	int	trigger_IswResize;
	char * hint_IswResize[8];
	int	value_IswResize;
	char * msg_IshResize[8];
	int	trigger_IshResize;
	char * hint_IshResize[8];
	int	value_IshResize;
	char * hint_Auto2785[8];
	char * msg_Auto2786[8];
	char * hint_Auto2786[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * msg_WidgetClass[8];
	char * hint_WidgetClass[8];
	int	value_WidgetClass;
	char * msg_Type[8];
	char * hint_Type[8];
	int	value_Type;
	char * hint_Hint[8];
	char	buffer_Hint[256];
	char * msg_IsLock[8];
	int	trigger_IsLock;
	char * hint_IsLock[8];
	int	value_IsLock;
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * hint_TextColour[8];
	char	buffer_TextColour[7];
	char * hint_Background[8];
	char	buffer_Background[7];
	char * msg_Auto2787[8];
	char * hint_Auto2787[8];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_Auto2788[8];
	char * hint_Auto2788[8];
	char * msg_Auto2789[8];
	char * hint_Auto2789[8];
	char * msg_Auto2790[8];
	char * hint_Auto2790[8];
	char * msg_Auto2791[8];
	char * hint_Auto2791[8];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_Auto2792[8];
	char * hint_Auto2792[8];
	char * msg_Auto2793[8];
	char * hint_Auto2793[8];
	char * msg_Auto2794[8];
	char * hint_Auto2794[8];
	char * msg_Auto2795[8];
	char * hint_Auto2795[8];
	char * msg_Auto2796[8];
	char * hint_Auto2796[8];
	char * msg_Auto2797[8];
	char * hint_Auto2797[8];
	char * hint_Auto2798[8];
	char	signature[1];
	};
void	vwgraph_position_at(struct vwgraph_context * _Context,int x,int y);
void	vwgraph_SetVars(struct vwgraph_context * _Context);
void	vwgraph_GetVars(struct vwgraph_context * _Context);

#endif /* _vwgraph_h */
