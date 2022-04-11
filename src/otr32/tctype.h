#ifndef	_tctype_h
#define	_tctype_h

#define	TCMODPTR struct tcode_module XPTR
#define	TCVARPTR struct tcode_variable XPTR
#define	XTVARPTR struct tcode_external_variable XPTR
#define	TCCONPTR struct tcode_constant XPTR
#define	TCDLFPTR struct tcode_library_function XPTR
#define	TCDLBPTR struct tcode_library XPTR
#define	TCODEPTR struct tcode_value XPTR
#define	TCBLKPTR struct tcode_block XPTR
#define	TCSEGPTR struct tcode_segment XPTR
#define	XTSEGPTR struct external_segment XPTR
#define XTLOCALPTR struct tcode_local_extern XPTR
#define	TCPRCPTR struct tcode_procedure XPTR
#define	TCVDTPTR struct tcode_variable_table XPTR
#define	TCFDTPTR struct tcode_control_table XPTR
#define	FIELDPTR struct tcode_field XPTR
#define	XTFIELDPTR struct tcode_extern_field XPTR
#define	FIELDNODEPTR struct tcode_field_node XPTR
#define	FILEPTR	 FILE XPTR
#define	TCDBGPTR struct tcode_correspondance XPTR
#define	RELOCPTR struct tcode_rellocation XPTR
#define	XREFPTR	struct tcode_cross_reference XPTR

#endif	/* _tctype_h */

