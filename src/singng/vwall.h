
#ifndef _vwall_h
#define _vwall_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.26                                                */
/* Production     : C                                                        */
/* Project        : vwall.xml                                                */
/* Target         : vwall.h                                                  */
/* Identification : 0.0-1177511937-4355.4354                                 */
/* ------------------------------------------------------------------------- */


private struct vwall_context {
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
	char * msg_auto50093[8];
	char * hint_auto50093[8];
	char * msg_auto49[8];
	char * hint_auto49[8];
	char * hint_AtX[8];
	char	buffer_AtX[8];
	char * msg_auto53[8];
	char * hint_auto53[8];
	char * hint_AtY[8];
	char	buffer_AtY[8];
	char * msg_auto55[8];
	char * hint_auto55[8];
	char * hint_Width[8];
	char	buffer_Width[8];
	char * hint_Height[8];
	char	buffer_Height[8];
	char * msg_auto64[8];
	char * hint_auto64[8];
	char * msg_auto67[8];
	char * hint_auto67[8];
	char * msg_TextFont[8];
	char * hint_TextFont[8];
	int	value_TextFont;
	char * hint_TextColour[8];
	char	buffer_TextColour[13];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_auto70[8];
	char * hint_auto70[8];
	char * hint_Background[8];
	char	buffer_Background[13];
	char * msg_bgSelect[8];
	int	trigger_bgSelect;
	char * hint_bgSelect[8];
	char * msg_PayLoadSelect[8];
	int	trigger_PayLoadSelect;
	char * hint_PayLoadSelect[8];
	int	s_PayLoadSelect;
	void *	p_PayLoadSelect;
	char * msg_auto73[8];
	char * hint_auto73[8];
	char * msg_Auto2770[8];
	char * hint_Auto2770[8];
	char * msg_Auto2771[8];
	char * hint_Auto2771[8];
	char * msg_Auto2772[8];
	char * hint_Auto2772[8];
	char * hint_PayLoad[8];
	char	buffer_PayLoad[261];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * hint_Format[8];
	char	buffer_Format[261];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * hint_StyleFocus[8];
	char	buffer_StyleFocus[256];
	char * hint_Hint[8];
	char	buffer_Hint[256];
	char * msg_auto77[8];
	char * hint_auto77[8];
	char * msg_Auto2773[8];
	char * hint_Auto2773[8];
	char * hint_HotkeyValue[8];
	char	buffer_HotkeyValue[7];
	char * msg_auto80[8];
	char * hint_auto80[8];
	char * msg_Auto2774[8];
	char * hint_Auto2774[8];
	char * msg_auto269[8];
	char * hint_auto269[8];
	char * msg_WidgetClass[8];
	char * hint_WidgetClass[8];
	int	value_WidgetClass;
	char * msg_auto138[8];
	char * hint_auto138[8];
	char * msg_Align[8];
	char * hint_Align[8];
	int	value_Align;
	char * msg_Type[8];
	char * hint_Type[8];
	int	value_Type;
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
	char * msg_IsLock[8];
	int	trigger_IsLock;
	char * hint_IsLock[8];
	int	value_IsLock;
	char * msg_IsInterface[8];
	int	trigger_IsInterface;
	char * hint_IsInterface[8];
	int	value_IsInterface;
	char * msg_IsSpecial[8];
	int	trigger_IsSpecial;
	char * hint_IsSpecial[8];
	int	value_IsSpecial;
	char * msg_Auto2776[8];
	char * hint_Auto2776[8];
	char * msg_IswResize[8];
	int	trigger_IswResize;
	char * hint_IswResize[8];
	int	value_IswResize;
	char * msg_IshResize[8];
	int	trigger_IshResize;
	char * hint_IshResize[8];
	int	value_IshResize;
	char	signature[1];
	};
void	vwall_position_at(struct vwall_context * _Context,int x,int y);
void	vwall_SetVars(struct vwall_context * _Context);
void	vwall_GetVars(struct vwall_context * _Context);

#endif /* _vwall_h */
