#ifndef	_TRCOMMON_H
#define _TRCOMMON_H

#ifndef	UNIX
WORD	translate_common( VOID );
TCMEMBERPTR	locate_common_member( TCSTRUCTPTR, TCMEMBERPTR );
VOID	liberate_common_member( COMMONPTR );
TCMEMBERPTR	store_world_member( TCSTRUCTPTR, TCMEMBERPTR );
TCMEMBERPTR	add_common_member( TCSTRUCTPTR, TCMEMBERPTR );
WORD	add_world_member( TCSTRUCTPTR, TCMEMBERPTR );
WORD		declare_common_object( TCSTRUCTPTR, TCSTRUCTPTR, TCMEMBERPTR, TCTEXTPTR, WORD );
TCMEMBERPTR	build_common_object( BPTR, TCSTRUCTPTR, WORD, TCTEXTPTR, WORD );
TCMEMBERPTR	build_common_terminal( BPTR, WORD, WORD, WORD, WORD, WORD );
TCMEMBERPTR	locate_common_object( BPTR, TCSTRUCTPTR, TCSTRUCTPTR );
TCMEMBERPTR	locate_common_terminal( BPTR );
WORD	declare_world_member( TCMEMBERPTR );
WORD	declare_module_common( TCMEMBERPTR, TCSTRUCTPTR );

#else
TCMEMBERPTR	build_common_object();
TCMEMBERPTR	locate_common_object();
TCMEMBERPTR	build_common_terminal();
TCMEMBERPTR	locate_common_terminal();
TCMEMBERPTR	locate_common_member();
TCMEMBERPTR	add_common_member();
#endif

#endif 	/* _TRCOMMON_H */
	/* ----------- */

