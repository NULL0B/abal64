
#ifndef _vwdata_h
#define _vwdata_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vwdata.xml                                               */
/* Target         : vwdata.h                                                 */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */


private struct vwdata_context {
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
	char * msg_Auto3603[8];
	char * hint_Auto3603[8];
	char * hint_Auto3604[8];
	char * msg_Auto3605[8];
	char * hint_Auto3605[8];
	char * msg_Auto3606[8];
	char * hint_Auto3606[8];
	char * msg_Auto3607[8];
	char * hint_Auto3607[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * msg_WidgetClass[8];
	char * hint_WidgetClass[8];
	int	value_WidgetClass;
	char * hint_Format[8];
	char	buffer_Format[256];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
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
	char * hint_PayLoad[8];
	char	buffer_PayLoad[256];
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
	char * msg_Type[8];
	char * hint_Type[8];
	int	value_Type;
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
	char * msg_Auto3613[8];
	char * hint_Auto3613[8];
	char * msg_Auto3614[8];
	char * hint_Auto3614[8];
	char * msg_Auto3615[8];
	char * hint_Auto3615[8];
	char * msg_PayLoadSelect[8];
	int	trigger_PayLoadSelect;
	char * hint_PayLoadSelect[8];
	int	s_PayLoadSelect;
	void *	p_PayLoadSelect;
	char * msg_Auto3616[8];
	char * hint_Auto3616[8];
	char * hint_Auto3617[8];
	char	signature[1];
	};
void	vwdata_position_at(struct vwdata_context * _Context,int x,int y);
void	vwdata_SetVars(struct vwdata_context * _Context);
void	vwdata_GetVars(struct vwdata_context * _Context);

#endif /* _vwdata_h */
