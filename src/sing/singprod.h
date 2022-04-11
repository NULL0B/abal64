#ifndef	_sing_production_h
#define	_sing_production_h

/*	----------------------------------	*/
/*	Open:Create Production Stream File 	*/
/*	----------------------------------	*/
/*	MODE : 	0	ASCII			*/
/*		1	BINARY			*/
/*	----------------------------------	*/
#define	QUICK	(_INHIBIT_PROPERTIES | _INHIBIT_REFRESH )

#define	_INHIBIT_PROPERTIES	1
#define	_INHIBIT_REFRESH	2
#define	_INHIBIT_NAME  		4
#define	_INHIBIT_STATUS		8

#ifndef	open_production_target
FILE *	open_production_target( char * nptr, int mode );
#endif

public	struct form_item * locate_radio_method( struct form_control * fptr, char * nptr, int method );
public	struct form_item * locate_radio_create( struct form_control * fptr, char * nptr );
public	struct form_item * locate_radio_show( struct form_control * fptr, char * nptr );
public	struct form_item * locate_radio_get_focus( struct form_control * fptr, char * nptr );
public	struct form_item * locate_radio_event( struct form_control * fptr, char * nptr );
public	struct form_item * locate_radio_lose_focus( struct form_control * fptr, char * nptr );
public	struct form_item * locate_radio_hide( struct form_control * fptr, char * nptr );
public	struct form_item * locate_radio_remove( struct form_control * fptr, char * nptr );

#endif

