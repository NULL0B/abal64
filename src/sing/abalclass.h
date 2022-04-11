#ifndef	 _abal_class_h
#define	 _abal_class_h

/*	--------------------------------------------------------------------------------	*/
/*					a b a l _ c l a s s 					*/
/*	--------------------------------------------------------------------------------	*/
/*	This source file contains the list of classes delivered with the abal product		*/
/*	It has been built from a list generated using the linux command : 			*/
/*												*/
/*		grep "#class" /home/abal3/class/*.cls | grep -v "#endclass" > output		*/
/*												*/
/*	and then edited to make it a compatible C string table.					*/
/*												*/
/*	The table of classes is used by the Abal 2 Php conversion mechanisms in the Php		*/
/*	web agent generator to be able to detect class names quickly in order to handle		*/
/*	instance and invocation expressions. These classes will need to be implemented		*/
/*	in php to complete the process but may be performed at a later date since they		*/
/*	are external to the php generator engine.						*/
/*	--------------------------------------------------------------------------------	*/

static	char * abal_class_name[] = {
	/* dynamic libraries */
	/* ----------------- */
	(char *) "asfun_library_interface",
	(char *) "sound_card_interface",
	(char *) "editor_library_interface",
	(char *) "math_library_interface",
	(char *) "graphics_printer",
	(char *) "graphics_printer",
	(char *) "graphics_driver_interface",
	(char *) "graphics_printer_interface",
	(char *) "tty_library_interface",
	/* visual library and widgets */
	/* -------------------------- */
	(char *) "visual_argv",
	(char *) "visual_buffer",
	(char *) "visual_callback", 
	(char *) "visual_check",
	(char *) "visual_command_line",
	(char *) "visual_colour",
	(char *) "visual_palette",
	(char *) "visual_edit",
	(char *) "visual_event",
	(char *) "visual_fill",
	(char *) "visual_filename",
	(char *) "visual_font",
	(char *) "visual_font_handle",
	(char *) "visual_frame",
	(char *) "visual_graph",
	(char *) "visual_group",
	(char *) "visual_image",
	(char *) "visual_library_definitions",
	(char *) "visual_library_interface",
	(char *) "visual_labels",
	(char *) "visual_library_mode",
	(char *) "visual_library_server",
	(char *) "visual_library_client",
	(char *) "visual_library_resolution",
	(char *) "visual_message",
	(char *) "visual_overlay",
	(char *) "visual_page",
	(char *) "visual_printer",
	(char *) "visual_progress",
	(char *) "visual_button",
	(char *) "overlay_button",
	(char *) "chain_button",
	(char *) "loadgo_button",
	(char *) "visual_radio",
	(char *) "visual_pushpop",
	(char *) "visual_saver",
	(char *) "visual_scroll",
	(char *) "visual_select",
	(char *) "visual_switch",
	(char *) "visual_table",
	(char *) "visual_tabpage",
	(char *) "visual_text",
	(char *) "visual_trigger",
	(char *) "visual_coordinate",
	(char *) "visual_dimension",
	(char *) "visual_align",
	(char *) "visual_object",
	(char *) "visual_window",
	/* files */
	/* ----- */
	(char *) "file_error", 
	(char *) "fac_definitions",
	(char *) "facfile",
	(char *) "fac_interface",
	(char *) "stdin",
	(char *) "stdout",
	(char *) "file_handle",
	(char *) "mcfile",
	(char *) "sifile",
	(char *) "stdfile",
	(char *) "text_stdout",
	/* web, soap and xml */
	(char *) "xml_database",
	(char *) "xml_form",
	(char *) "xml_project",
	(char *) "soap_agent",
	(char *) "secure_soap_agent",
	(char *) "internet_library_interface",
	(char *) "wasp_cookie",
	(char *) "xml_dom_parser", 
	(char *) "xml_element",
	(char *) "firewall_types",
	(char *) "wasp_firewall_filename",
	(char *) "web_server_firewall",
	(char *) "http_client",
	(char *) "iso_8601_date",
	(char *) "iso_8601_time",
	(char *) "list",
	(char *) "node",
	(char *) "list",
	(char *) "mime_file_size",
	(char *) "mime_date_and_time",
	(char *) "mime_string", 
	(char *) "mime_field", 
	(char *) "mime_header",
	(char *) "mime_attachment",
	(char *) "mime_document",
	(char *) "output", 
	(char *) "device_output",
	(char *) "file_output",
	(char *) "socket_output",
	(char *) "overlay web_service_interface",
	(char *) "smtp_client",
	(char *) "smtp_sendfile",
	(char *) "soap",
	(char *) "soap_document",
	(char *) "soap_ns_document",
	(char *) "soap_rpc",
	(char *) "soap_ns_rpc",
	(char *) "soap_response",
	(char *) "soap_fault",
	(char *) "soap_client",
	(char *) "standard_date",
	(char *) "wsdl2_document",
	(char *) "wsdl_document",
	(char *) "xml_document",
	(char *) "xml_file", 
	(char *) "xml_parser",
	(char *) "xml_string", 
	(char *) "xml_atribut",
	(char *) 0
	};

#endif	/* _abal_class_h */
	/* ------------- */


