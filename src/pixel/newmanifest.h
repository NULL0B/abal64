
#ifndef _newmanifest_h
#define _newmanifest_h
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : newmanifest.xml                                          */
/* Target         : newmanifest.h                                            */
/* Identification : 0.0-1354199912-30353.30352                               */
/* ------------------------------------------------------------------------- */


private struct accept_new_manifest_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	x_Auto39;
	int	y_Auto39;
	int	w_Auto39;
	int	h_Auto39;
	char	buffer_ManifestName[60];
	char	buffer_ManifestSchema[60];
	char	buffer_ProductionFilename[60];
	char	buffer_AccountName[60];
	char	buffer_SecurityName[60];
	int	value_SecurityLevel;
	int	value_SecurityPolicy;
	int	value_FixedPosition;
	int	value_FastDrag;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[10];
	};

#endif /* _newmanifest_h */
