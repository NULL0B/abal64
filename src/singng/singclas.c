#ifndef	_singclas_c
#define	_singclas_c

#include <stdio.h>
#include "sing.h"
#include "singclas.h"
#include "singlang.h"
#include "singprod.h"
#include "singtype.h"
#include "singtool.h"
#include "singedit.h"
#include "sysimage.h"
#include "stdimage.h"
#include "vframe.h"
#include "guimouse.h"

extern	struct	screen_control	Context;
extern	char 	LaPaterne[];
extern	char	namebuffer[];
extern	char * classbuffer;

struct	standard_list * liberate_members( struct standard_list * lptr);
struct	standard_node * liberate_member( struct standard_node * nptr);


static	int	visible=0;


char	*	class_message( struct standard_class * cptr )
{
	if ( cptr ) {
		if ( cptr->name )
			return( cptr->name );
		else if ( cptr->loadname )
			return( cptr->loadname );
		else if ( cptr->prodname )
			return( cptr->prodname );
		}
	return("[class]");
}

struct	standard_list * liberate_members( struct standard_list * lptr) 
{
	struct	standard_node  * nptr;
	if ( lptr ) {
		while ((nptr = lptr->first) != (struct standard_node *) 0) {
			lptr->first = nptr->next;
			nptr = liberate_member( nptr );
			}	
		lptr = liberate( lptr );
		}
	return( lptr );
}

char *	join_strings( char * aptr, char * bptr )
{
	char	*	rptr;
	if (!( aptr )) {
		if ( bptr )
			return( allocate_string( bptr ) );
		else	return( bptr );
		}
	else if (!( bptr )) 
		return( allocate_string( aptr ) );
	else if (!( rptr = allocate( strlen(aptr) + strlen(bptr) + 16 ) ))
		return( rptr );
	else	{
		sprintf(rptr,"%s %s",aptr,bptr);
		return(rptr);
		}
}

char *	postfix_string( char * aptr, char * bptr )
{
	char	*	rptr;
	if (!( aptr )) {
		if ( bptr )
			return( allocate_string( bptr ) );
		else	return( bptr );
		}
	else if (!( bptr )) 
		return( allocate_string( aptr ) );
	else if (!( rptr = allocate( strlen(aptr) + strlen(bptr) + 16 ) ))
		return( rptr );
	else	{
		sprintf(rptr,"%s%s",aptr,bptr);
		return(rptr);
		}
}

char *	generate_type( struct standard_type * tptr )
{
	switch ( tptr->type & _BASIC_TYPE ) {
		case	_TYPE_VOID	:
			return( allocate_string("void"));
		case	_TYPE_BYTE	:
			return( allocate_string("byte"));
		case	_TYPE_WORD	:
			return( allocate_string("word"));
		case	_TYPE_LONG	:
			return( allocate_string("long"));
		case	_TYPE_FLOAT	:
			return( allocate_string("float"));
		case	_TYPE_BCD 	:
			return( allocate_string("bcd"));
		case	_TYPE_STRING	:
			return( allocate_string("string"));
		case	_TYPE_CLASS	:
			return( join_strings("class ",tptr->name));
		default			:
			return((char *) 0);
		}
}

void  	add_type( char * sptr, struct standard_type * tptr )
{
	switch ( tptr->type & _BASIC_TYPE ) {
		case	_TYPE_VOID	:
			strcat(sptr,"void "); break;
		case	_TYPE_BYTE	:
			strcat(sptr,"byte "); break;
		case	_TYPE_WORD	:
			strcat(sptr,"word "); break;
		case	_TYPE_LONG	:
			strcat(sptr,"long "); break;
		case	_TYPE_FLOAT	:
			strcat(sptr,"float "); break;
		case	_TYPE_BCD 	:
			strcat(sptr,"bcd "); break;
		case	_TYPE_STRING	:
			strcat(sptr,"string "); break;
		case	_TYPE_CLASS	:
			strcat(sptr,"class ");
			if ( tptr->name )
				strcat(sptr,tptr->name);
			else	strcat(sptr,"_void");
			strcat(sptr, " " );
			break;
		}
}

void	interpret_type( struct standard_type * tptr, char * sptr)
{
	char	* rptr;
	if (!( sptr ))
		return;
	else if ( compare( sptr, "void"  ) )
		tptr->type = _TYPE_VOID;
	else if ( compare( sptr, "byte"  ) )
		tptr->type = _TYPE_BYTE;
	else if ( compare( sptr, "word"  ) )
		tptr->type = _TYPE_WORD;
	else if ( compare( sptr, "long"  ) )
		tptr->type = _TYPE_LONG;
	else if ( compare( sptr, "float" ) )
		tptr->type = _TYPE_FLOAT;
	else if ( compare( sptr, "bcd"   ) )
		tptr->type = _TYPE_BCD;
	else if ( compare( sptr, "string") )
		tptr->type = _TYPE_STRING;
	else if ((rptr = compare( sptr, "class"  ) ) 
	     ||  (rptr = compare( sptr, "struct" ) )) {
		tptr->type = _TYPE_CLASS;
		if ( tptr->name )
			tptr->name = liberate( tptr->name );
		tptr->name = allocate_string( rptr );
		}
	return;
}


int	specify_constant( struct const_member * cptr )
{
	int	status;
	int	ctype=0;

	ctype = (cptr->type.type & _BASIC_TYPE);

	if ((status = accept_constant( 
			&cptr->name, 
			&ctype,
			&cptr->value,
			&cptr->protection
			 )) != 27 ) {
		cptr->type.type &= ~_BASIC_TYPE;
		cptr->type.type |= ctype;
		}

	return(status);;
}

void	add_method_options(char * sptr, int option)
{
	if ( option & _TYPE_CONSTRUCTOR )
		strcat( sptr, "constructor " );
	else if ( option & _TYPE_DESTRUCTOR )
		strcat( sptr, "destructor " );
	else 	strcat( sptr, "method " );

	return;
}

int	generate_options(int option)
{
	if ( option & _TYPE_CONSTRUCTOR )
		return( 1 );
	else if ( option & _TYPE_DESTRUCTOR )
		return( 2 );
	else	return( 0 );
}

int		interpret_options(int o)
{
	if (!( o ))
		return( _TYPE_METHOD );
	else if ( o == 1 )
		return( _TYPE_CONSTRUCTOR );
	else if ( o == 2 )
		return( _TYPE_DESTRUCTOR );
	else	return( _TYPE_METHOD );

}

int	specify_Class( struct standard_class * cptr )
{
	return( accept_class( 	&cptr->name, 
				&cptr->loadname, 
				&cptr->prodname,
				&cptr->headname,
				&cptr->dependance ) );
}

int	specify_data( struct data_member * dptr )
{
	int	status;
	char *	tptr;
	int	ptrstatus=0;
	int	comstatus=0;

	if (!( tptr = generate_type( &dptr->type ) ))
		return(27);
	if ( dptr->type.type & _TYPE_POINTER )
		ptrstatus = 1;
	else	ptrstatus = 0;
	if ( dptr->type.type & _TYPE_COMMON )
		comstatus = 1;
	else	comstatus = 0;
	if ((status = accept_data(
			 	&dptr->name, 
				&tptr,
				&dptr->size,
				&dptr->first,
				&dptr->second,
				&dptr->construction,
				&dptr->protection,
				&comstatus, 
				&ptrstatus
				)) != 27) {
		interpret_type( &dptr->type, tptr );
		if ( ptrstatus )
			dptr->type.type |= _TYPE_POINTER;
		else	dptr->type.type &= ~_TYPE_POINTER;
		if ( comstatus )
			dptr->type.type |= _TYPE_COMMON;
		else	dptr->type.type &= ~_TYPE_COMMON;
		}
	if ( tptr )
		tptr = liberate( tptr );		

	return(status);;
}

int	specify_method( struct method_member * mptr )
{
	int	status;
	char *	tptr;
	int	options;
	int	ptrstatus=0;
	int	vstatus=0;
	int	ostatus=0;

	if (!( tptr = generate_type( &mptr->type ) ))
		return(27);
	if ( mptr->type.type & _TYPE_POINTER )
		ptrstatus = 1;
	else	ptrstatus = 0;
	if ( mptr->options  & _TYPE_VIRTUAL )
		vstatus = 1;
	else	vstatus = 0;
	if ( mptr->options  & _TYPE_OVERLOAD)
		ostatus = 1;
	else	ostatus = 0;

	options = generate_options( mptr->options );

	if ((status = accept_method( &mptr->name, 
				&tptr,
				&options,
				&mptr->parameters,
				&mptr->base,
				&mptr->instructions,
				&mptr->protection,
				&ptrstatus,&vstatus,&ostatus
				 )) != 27) {
		interpret_type( &mptr->type, tptr );
		mptr->options = interpret_options( options );
		if ( ptrstatus )
			mptr->type.type |= _TYPE_POINTER;
		else	mptr->type.type &= ~_TYPE_POINTER;
		if ( vstatus )
			mptr->options |= _TYPE_VIRTUAL;
		else	mptr->options &= ~_TYPE_VIRTUAL;
		if ( ostatus )
			mptr->options |= _TYPE_OVERLOAD;
		else	mptr->options &= ~_TYPE_OVERLOAD;
		}

	if ( tptr )
		tptr = liberate( tptr );		

	return(status);;
}

void	liberate_constant(struct const_member * cptr)
{
	if (!( cptr ))
		return;
	if ( cptr->name )
		cptr->name = liberate( cptr->name );
	if ( cptr->value )
		cptr->value = liberate( cptr->value );
	if ( cptr->type.name )
		cptr->type.name = liberate( cptr->type.name );
	if ( cptr->document )
		cptr->document = liberate( cptr->document );
	return;
}

void	liberate_data(struct data_member * dptr)
{
	if (!( dptr ))
		return;
	if ( dptr->name )
		dptr->name = liberate( dptr->name );
	if ( dptr->construction )
		dptr->construction = liberate( dptr->construction );
	if ( dptr->type.name )
		dptr->type.name = liberate( dptr->type.name );
	if ( dptr->document )
		dptr->document = liberate( dptr->document );
	return;
}

void	 liberate_method(struct method_member * mptr)
{
	if (!( mptr ))
		return;
	if ( mptr->name )
		mptr->name = liberate( mptr->name );
	if ( mptr->instructions )
		mptr->instructions = liberate( mptr->instructions );
	if ( mptr->base )
		mptr->base = liberate( mptr->base );
	if ( mptr->members )
		mptr->members = liberate_members( mptr->members );
	if ( mptr->parameters )
		mptr->parameters = liberate( mptr->parameters );
	if ( mptr->type.name )
		mptr->type.name = liberate( mptr->type.name );
	if ( mptr->document )
		mptr->document = liberate( mptr->document );
	return;
}

struct	standard_node * liberate_member(struct standard_node * nptr )
{
	struct standard_member * cptr;
	if ( nptr ) {

		if ((cptr = nptr->contents) != (struct standard_member*) 0) {
			switch ( cptr->nature ) {
				case	_MEMBER_CONSTANT	:
					liberate_constant((struct const_member*) cptr );
					break;
				case	_MEMBER_DATA    	:
					liberate_data((struct data_member*)  cptr );
					break;
				case	_MEMBER_METHOD  	:
					liberate_method((struct method_member*)  cptr );
					break;
				default				:
					cptr = liberate((void *) cptr );
				}
			}

		nptr = liberate( nptr );

		}
	return( nptr );
}
	
struct	standard_node * initialise_constant(struct standard_node * nptr,int automatic)
{
	struct const_member * cptr;
	if (!( nptr ))
		return( nptr );
	else if (!( cptr = (struct const_member *) nptr->contents ))
		return( liberate_member( nptr ) );
	else	{
		cptr->paratool = _TEXT_TOOL;
		cptr->parent = (struct standard_class*) 0;
		cptr->nature = _MEMBER_CONSTANT;
		cptr->name   = (char *) 0;
		cptr->type.type = _TYPE_WORD;
		cptr->type.name = (char *) 0;
		cptr->protection = _MEMBER_PRIVATE;
		cptr->value  = (char *) 0;
		cptr->doctool  = _TEXT_TOOL;
		cptr->document = (char *) 0;
		if ( automatic & _INHIBIT_PROPERTIES )
			return( nptr );
		else if ( specify_constant( cptr ) == 27 )
			return( liberate_member( nptr ) );
		else	return( nptr );
		}
}

struct	standard_node * initialise_data(struct standard_node * nptr,int automatic)
{
	struct data_member * dptr;
	if (!( nptr ))
		return( nptr );
	else if (!( dptr = (struct data_member *) nptr->contents ))
		return( liberate_member( nptr ) );
	else	{
		dptr->paratool = _TEXT_TOOL;
		dptr->parent = (struct standard_class*) 0;
		dptr->nature = _MEMBER_DATA;
		dptr->name   = (char *) 0;
		dptr->type.type = _TYPE_WORD;
		dptr->protection = _MEMBER_PRIVATE;
		dptr->construction = (char *) 0;
		dptr->type.name = (char *) 0;
		dptr->size   = 2;
		dptr->first  = dptr->second = 1;
		dptr->doctool  = _TEXT_TOOL;
		dptr->document = (char *) 0;
		if ( automatic & _INHIBIT_PROPERTIES )
			return( nptr );
		else if ( specify_data( dptr ) == 27 )
			return( liberate_member( nptr ) );
		else	return( nptr );
		}
}

struct	standard_node * initialise_method(struct standard_node * nptr, int automatic)
{
	struct method_member * mptr;
	if (!( nptr ))
		return( nptr );
	else if (!( mptr = (struct method_member *) nptr->contents ))
		return( liberate_member( nptr ) );
	else	{
		mptr->basetool = _TEXT_TOOL;
		mptr->methtool = _TEXT_TOOL;
		mptr->paratool = _TEXT_TOOL;
		mptr->parent = (struct standard_class*) 0;
		mptr->nature = _MEMBER_METHOD;
		mptr->name   = (char *) 0;
		mptr->type.type = _TYPE_VOID;
		mptr->type.name = (char *) 0;
		mptr->protection = _MEMBER_PUBLIC;
		mptr->options = _TYPE_METHOD;
		mptr->members = (struct standard_list *) 0;
		mptr->base = mptr->parameters = mptr->instructions=(char *) 0;
		mptr->doctool  = _TEXT_TOOL;
		mptr->document = (char *) 0;
		if ( automatic & _INHIBIT_PROPERTIES )
			return( nptr );
		else if ( specify_method( mptr ) == 27 )
			return( liberate_member( nptr ) );
		else	return( nptr );
		}
}

struct	standard_node * allocate_member(int type,int automatic )
{
	struct	standard_node * nptr;
	if (!( nptr = allocate( sizeof( struct standard_node ) ) ))
		return(nptr);
	nptr->previous = nptr->next = (struct standard_node *) 0;
	nptr->contents = (struct standard_member *) 0;
	nptr->x = nptr->y = nptr->item = 0;
	switch ( type ) {
		case	_MEMBER_CONSTANT :
			if (!( nptr->contents = allocate( sizeof ( struct const_member ) ) ))
				return( liberate_member( nptr ) );
			else	return( initialise_constant( nptr,automatic ) );

		case	_MEMBER_DATA     :
			if (!( nptr->contents = allocate( sizeof ( struct data_member ) ) ))
				return( liberate_member( nptr ) );
			else	return( initialise_data( nptr,automatic ) );
		case	_MEMBER_METHOD   :
			if (!( nptr->contents = allocate( sizeof ( struct method_member ) ) ))
				return( liberate_member( nptr ) );
			else	return( initialise_method( nptr, automatic ) );
		default			 :
			return( liberate_member( nptr ) );
		}

}

int	del_class_member( struct standard_class * cptr )
{
	struct	standard_list * lptr;
	struct	standard_node * nptr;
	if (!( cptr ))
		return(0);
	if (!(lptr = cptr->members ))
		return(0);
	else if (!( nptr = lptr->current ))
		return(0);
	else	{
		if ( lptr->base == lptr->current ) {
			if (!( lptr->base->next ))
				lptr->base = lptr->base->previous;
			else	lptr->base = lptr->base->next;
			}
		if (!(  lptr->current = nptr->next )) {
			lptr->current = lptr->last = nptr->previous;
			}
		else	nptr->next->previous = nptr->previous;
		if (!( nptr->previous ))
			lptr->first = nptr->next;
		else	nptr->previous->next = nptr->next;
		
		nptr = liberate_member( nptr );
		return(257);
		}
}

int	add_class_member( struct standard_class * cptr, int type, int addatend )
{
	struct	standard_node * nptr;
	struct standard_list * lptr;
	if (!( cptr ))
		return(0);
	if (!(lptr = cptr->members ))
		return(0);
	else if (!( nptr = allocate_member( type, 1 )))
		return(0);
	else if ( addatend ) {	
		if (!( nptr->previous = lptr->last )) {
			lptr->current = lptr->first = lptr->base = nptr;
			}
		else	lptr->last->next = nptr;
		lptr->current = lptr->last = nptr;
		nptr->contents->parent = cptr;
		return(1);
		}
	else	{
		/* Attempt to Add after the current element */
		/* ---------------------------------------- */
		if (!( nptr->previous = lptr->current )) {
			/* Whoops : no current so add to the end    */
			/* with all necessary tests and adjustments */
			if (!( nptr->previous = lptr->last )) {
				lptr->current = lptr->first = lptr->base = nptr;
				}
			else	lptr->last->next = nptr;
			lptr->current = lptr->last = nptr;
			}
		else 	{
			if (!(nptr->next = lptr->current->next )) {
				/* we have been added at the end any way */
				lptr->last = nptr;
				}
			else	nptr->next->previous = nptr;
			lptr->current = nptr->previous->next = nptr;
			}			
		nptr->contents->parent = cptr;
		return(1);
		}
}
	

struct	standard_list * allocate_list()
{
	struct standard_list * lptr;
	if (!( lptr = allocate( sizeof( struct standard_list ) ) ))
		return(lptr);
	else	{
		lptr->base = lptr->first = lptr->current = lptr->last =  (struct standard_node *) 0;
		return( lptr );
		}
}

struct	standard_class * liberate_Class(struct standard_class * cptr)
{
	if ( cptr ) {
		if ( cptr->name )
			cptr->name = liberate( cptr->name );
		if ( cptr->loadname )
			cptr->loadname = liberate( cptr->loadname );
		if ( cptr->prodname )
			cptr->prodname = liberate( cptr->prodname );
		if ( cptr->headname )
			cptr->headname = liberate( cptr->headname );
		if ( cptr->dependance )
			cptr->dependance = liberate( cptr->dependance );
		if ( cptr->document )
			cptr->document = liberate( cptr->document );
		if ( cptr->members )
			cptr->members = liberate_members( cptr->members );
		cptr = liberate( cptr );
		}
	return( cptr );
	
}

struct	standard_class * allocate_Class(char * nptr)
{
	struct standard_class * cptr;

	if (!( cptr = allocate( sizeof( struct standard_class ) ) ))
		return(cptr);
	else if (!( cptr->treenode = allocate_for_treeview())) {
		liberate( cptr );
		return((struct standard_class *) 0);
		}
	else	{
		cptr->host     = (void *) 0;
		cptr->language = production_language();
		cptr->members  = (struct standard_list *) 0;
		cptr->tool     = _CLASS_TOOL;
		cptr->name     =
		cptr->headname = 
		cptr->dependance = 
		cptr->loadname = 
		cptr->prodname = (char *) 0;
		cptr->image    = (struct standard_image *) 0;
		cptr->nature   = 0;
		cptr->items    = 0;
		cptr->doctool  = _TEXT_TOOL;
		cptr->document = (char *) 0;
		if ( nptr ) {
			if (!(cptr->name= allocate_string(nptr)))
				return( liberate_Class(cptr) );
			if (!(cptr->loadname= allocate_string(nptr)))
				return( liberate_Class(cptr) );
			else if (!(cptr->prodname= allocate_string(nptr)))
				return( liberate_Class(cptr) );
			}
		if (!(cptr->members = allocate_list() ))
			return( liberate_Class(cptr) );
		else	return( cptr );
		}
}

private	void	load_Constant(FILE * h, struct const_member * cptr, int automatic,int o)
{
	GetWord		( h,cptr->protection	);
	GetString	( h,cptr->name   	);
	GetWord		( h,cptr->type.type 	);
	GetString	( h,cptr->type.name   	);
	GetWord		( h,cptr->paratool 	);
	if ( cptr->paratool != 0 ) {
		GetString	( h,cptr->value	);
		}
	if ( o & _DOCUMENTATION ) {
		GetWord(h,cptr->doctool);
		GetString(h,cptr->document);
		}
	else	{
		cptr->doctool = _TEXT_TOOL;
		cptr->document= (char *) 0;
		}
	return;
}

private	void	load_Data(FILE * h, struct data_member * cptr, int automatic, int o)
{
	GetWord		( h,cptr->protection	);
	GetString	( h,cptr->name   	);
	GetWord		( h,cptr->type.type 	);
	GetString	( h,cptr->type.name   	);
	GetWord		( h,cptr->size		);
	GetWord		( h,cptr->first		);
	GetWord		( h,cptr->second	);
	GetWord		( h,cptr->paratool 	);
	if ( cptr->paratool != 0 ) {
		GetString	( h,cptr->construction	);
		}
	if ( o & _DOCUMENTATION ) {
		GetWord(h,cptr->doctool);
		GetString(h,cptr->document);
		}
	else	{
		cptr->doctool = _TEXT_TOOL;
		cptr->document= (char *) 0;
		}
	return;
}

private	void	load_Method(FILE * h, struct method_member * cptr, int automatic, int o)
{
	GetWord		( h,cptr->protection	);
	GetString	( h,cptr->name   	);
	GetWord		( h,cptr->type.type 	);
	GetString	( h,cptr->type.name   	);
	GetWord		( h,cptr->options	);
	GetWord		( h,cptr->paratool	);
	if ( cptr->paratool != 0 ) {
		GetString	( h,cptr->parameters  	);
		}

	(void) get_word(h);	/* no locals */

	GetWord		( h,cptr->methtool 	);
	if ( cptr->methtool != 0 ) {
		GetString	( h,cptr->instructions );
		}
	if ( o & _DOCUMENTATION ) {
		GetWord(h,cptr->doctool);
		GetString(h,cptr->document);
		}
	else	{
		cptr->doctool = _TEXT_TOOL;
		cptr->document= (char *) 0;
		}
	if ( o & _BASEORDER ) {
		GetWord  (h,cptr->basetool);
		GetString(h,cptr->base );
		}
	return;

}


struct	standard_class *	load_Class(char * sptr, int automatic )
{
	int			o;
	int			n;
	FILE		*	h=(FILE *) 0;
	char		*	loadname=(char *) 0;
	struct	standard_class *cptr=(struct standard_class *) 0;
	struct	standard_node  *nptr=(struct standard_node *) 0;
	struct	standard_member	* mptr=(struct standard_member *) 0;
	char		*	vptr=(char *) 0;

	if (!( loadname = allocate_string( sptr ) ))
		return((struct standard_class *) 0);
	else if (!( loadname = verify_extension( loadname, CLASS_EXTENSION ) ))
		return((struct standard_class *) 0);
	else if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( accept_form_load(&loadname) == 27 ) {
			loadname = liberate( loadname );
			return((struct standard_class *) 0);
			}
		status_message(loadname,3);
		}

	while(!(h = fopen(loadname,"rb"))) {
		if ( automatic & _INHIBIT_PROPERTIES )
			break;
		else if ( file_not_found( loadname ) == 27 )
			break;
		}

	if ( h  != (FILE *) 0) {

		if (!( cptr = allocate_Class(loadname))) {
			fclose(h);
			loadname = liberate( loadname );
			return(cptr);
			}

		if (!( automatic & _INHIBIT_STATUS ))
			status_message(cptr->loadname,3);

		if ((!(vptr = get_string(h)))
		||  (!( string_compare(vptr,"CLASS") ))
		||  (!(vptr = get_string(h)))) {
			incorrect_filetype(loadname);
			fclose(h);
			loadname = liberate( loadname );
			return(cptr);
			}
		else	{
			o = get_word(h);

			GetString(h,cptr->name);
			GetString(h,cptr->prodname);
			GetString(h,cptr->loadname);
			GetWord(h,cptr->nature);
			GetWord(h,cptr->language);
			GetWord(h,cptr->tool);
			if ( o & _DOCUMENTATION ) {
				GetWord(h,cptr->doctool);
				GetString(h,cptr->document);
				}
			else	{
				cptr->doctool = _TEXT_TOOL;
				cptr->document= (char *) 0;
				}

			if ( o & _DEPENDANCE ) {
				GetString(h,cptr->headname);
				GetString(h,cptr->dependance);
				}
			else	{
				cptr->headname = cptr->dependance = (char *) 0;
				}

			while ((n = get_word(h)) != 0x001A) {
				if (!(add_class_member(cptr,n,1)))
					break;
				else if (!( mptr = cptr->members->current->contents ))
					break;
				else if ( mptr->nature == _MEMBER_CONSTANT )
					load_Constant(h,(struct const_member *) mptr,automatic,o);
				else if ( mptr->nature == _MEMBER_DATA     )
					load_Data(h,(struct data_member *) mptr,automatic,o);
				else if ( mptr->nature == _MEMBER_METHOD )
					load_Method(h,(struct method_member *) mptr,automatic,o);
				else	break;

				}
			fclose(h);
			}
		}

	loadname = liberate( loadname );
	return( cptr );

}

void	save_Constant(FILE * h, struct const_member * cptr, int automatic)
{
	put_word	( h,cptr->nature 	);
	put_word	( h,cptr->protection	);
	put_string	( h,cptr->name   	);
	put_word	( h,cptr->type.type 	);
	put_string	( h,cptr->type.name   	);
	put_word	( h,cptr->paratool	);
	put_string	( h,cptr->value		);
	put_word	( h,cptr->doctool	);
	put_string	( h,cptr->document	);
	return;
}

void	save_Data(FILE * h, struct data_member * cptr, int automatic)
{
	put_word	( h,cptr->nature 	);
	put_word	( h,cptr->protection	);
	put_string	( h,cptr->name   	);
	put_word	( h,cptr->type.type 	);
	put_string	( h,cptr->type.name   	);
	put_word	( h,cptr->size		);
	put_word	( h,cptr->first		);
	put_word	( h,cptr->second	);
	put_word	( h,cptr->paratool	);
	put_string	( h,cptr->construction	);
	put_word	( h,cptr->doctool	);
	put_string	( h,cptr->document	);
	return;
}

void	save_Method(FILE * h, struct method_member * cptr, int automatic)
{
	put_word	( h,cptr->nature 	);
	put_word	( h,cptr->protection	);
	put_string	( h,cptr->name   	);
	put_word	( h,cptr->type.type 	);
	put_string	( h,cptr->type.name   	);
	put_word	( h,cptr->options	);
	put_word	( h,cptr->paratool	);
	put_string	( h,cptr->parameters  	);
	put_word	( h,0 ); /* no locals */
	put_word	( h,cptr->methtool	);
	put_string	( h,cptr->instructions );
	put_word	( h,cptr->doctool	);
	put_string	( h,cptr->document	);
	put_word	( h,cptr->basetool	);
	put_string	( h,cptr->base		);
	return;
}

int	save_Class(struct standard_class * cptr, int automatic )
{
	FILE			* h;
	struct 	standard_list 	* lptr;
	struct	standard_member	* mptr;
	struct	standard_node 	* nptr;

	if (!( cptr ))
		return(0);

	if (!( cptr->loadname )) {
		if (!(cptr->loadname = allocate_string( "new.cms" ) ))
			return(27);
		}

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( specify_Class( cptr ) == 27 ) {
			draw_console();
			return(0);
			}
		else	status_message(cptr->loadname,3);
		}

	if ((h = open_production_target(cptr->loadname,1)) != (FILE *) 0) {

		status_message(cptr->loadname,3);
		put_string(h,"CLASS");
		put_string(h,LaPaterne);

		put_word(h,1 | _DEPENDANCE | _BASEORDER | _DOCUMENTATION);	/* version control */

		put_string(h,cptr->name);
		put_string(h,cptr->prodname);
		put_string(h,cptr->loadname);
		put_word(h,cptr->nature);
		put_word(h,cptr->language);
		put_word(h,cptr->tool);
		put_word(h,cptr->doctool);
		put_string(h,cptr->document);
		put_string(h,cptr->headname);
		put_string(h,cptr->dependance);

		if (( lptr = cptr->members ) != (struct standard_list*) 0) {
			for (	nptr=lptr->first;
				nptr != (struct standard_node*) 0;
				nptr = nptr->next ) {
				if (!( mptr = nptr->contents ))
					continue;
				else if ( mptr->nature == _MEMBER_CONSTANT )
					save_Constant(h,(struct const_member *) mptr,automatic);
				else if ( mptr->nature == _MEMBER_DATA     )
					save_Data(h,(struct data_member *) mptr,automatic);
				else if ( mptr->nature == _MEMBER_METHOD )
					save_Method(h,(struct method_member *) mptr,automatic);
				}
			}
		put_word(h,0x001A);
		put_word(h,0x001A);
		put_word(h,0x001A);
		put_word(h,0x001A);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);
		put_word(h,0);


		close_production_target( h, cptr->loadname );

		if (!( automatic & _INHIBIT_REFRESH ))
			draw_console();


		}



	return(0);
}

int	prepare_cpp_class(struct standard_class * cptr)
{
	char	* punctuation=" : ";
	struct	standard_list * lptr;
	struct	standard_node * nptr;
	struct	standard_member * mptr;
	struct	data_member * dptr;

	if (!( cptr ))
		return(0);

	output_string("class ");
	output_string(cptr->name);

	if ((lptr = cptr->members ) != (struct standard_list *) 0) {
		for ( 	nptr = lptr->first;
			nptr != (struct standard_node *) 0;
			nptr = nptr->next ) {
			if (!( mptr = nptr->contents ))
				continue;
			else if ( mptr->nature != _MEMBER_DATA )
				continue;
			else	{
				if (( is_blank( mptr->name ) )
				&&  ( mptr->type.type & _TYPE_CLASS )
				&&  ( not_blank( mptr->type.name )  )) {
					output_string( punctuation );
					if ((visible = mptr->protection) != 0 )
						output_string( "public  " );
					else	output_string( "private " );
					output_string( mptr->type.name );
					punctuation = " , ";
					}
				}
			}
		}

	output_string(" { ");
	return(strlen( classbuffer ));
}

int	prepare_class(struct standard_class * cptr,int mode)
{
	if (!( check_class_buffer() ))
		return(0);

	switch ( cptr->language ) {
		case	_GENERATE_C		:
			if (!( mode )) 
				sprintf(classbuffer,"struct %s {",cptr->name);
			break;
		case	_GENERATE_CPP		:
			if (!( mode ))
				return( prepare_cpp_class( cptr ) );
			else	break;

		case	_GENERATE_HTML		:
			sprintf(classbuffer,"<html><head><title>%s</title></head><body>" ,cptr->name);
			break;
		case	_GENERATE_BAL		:
			sprintf(classbuffer,"Program %c%s%c" ,0x0022,cptr->name,0x0022);
			break;
		case	_GENERATE_ABAL		:
			sprintf(classbuffer,"#class %s" ,cptr->name);
			break;
		case	_GENERATE_JAVA		:
			sprintf(classbuffer,"class %s" ,cptr->name);
			break;
		default				:
			return(0);

		}
	return(strlen( classbuffer ));
}

int	prepare_endclass(struct standard_class * cptr, int mode)
{
	if (!( check_class_buffer() ))
		return(0);

	switch ( cptr->language ) {
		case	_GENERATE_C		:
			if (!( mode ))
				sprintf(classbuffer,"}; /* %s */",cptr->name);
			break;
		case	_GENERATE_CPP		:
			if (!( mode ))
				sprintf(classbuffer,"}; // %s " ,cptr->name);
			break;
		case	_GENERATE_HTML		:
			sprintf(classbuffer,"</body></html>");
			break;
		case	_GENERATE_BAL		:
			sprintf(classbuffer,"End ; %s " ,cptr->name);
			break;
		case	_GENERATE_ABAL		:
			sprintf(classbuffer,"#endclass %s" ,cptr->name);
			break;
		case	_GENERATE_JAVA		:
			sprintf(classbuffer,"endclass %s" ,cptr->name);
			break;
		default				:
			return(0);

		}
	return(strlen( classbuffer ));
}

void	output_c_datatype( struct standard_type * tptr,int mode )
{
	switch ( tptr->type & _BASIC_TYPE ) {
		case	_TYPE_VOID	:
			output_string("void "); break;
		case	_TYPE_BYTE	:
			output_string("byte "); break;
		case	_TYPE_WORD	:
			output_string("word "); break;
		case	_TYPE_LONG	:
			output_string("long "); break;
		case	_TYPE_FLOAT	:
			output_string("float "); break;
		case	_TYPE_BCD 	:
			if ( mode )
				output_string("class ");
			else	output_string("struct ");
			output_string("bcd "); break;
		case	_TYPE_STRING	:
			if ( mode )
				output_string("class ");
			else	output_string("struct ");
			output_string("string "); break;
		case	_TYPE_CLASS	:
			if (!( mode ))
				output_string( "struct " );
/*			else	output_string("class ");	*/
			output_string( tptr->name);
			output_string( " ");
		}
	
	if ( tptr->type & _TYPE_POINTER )
		output_string("*");
	return;
}


void	output_c_dimension( int v )
{
	if ( v > 1 ) {
		output_string("[");
		output_int(v);
		output_string("]");
		}
	return;
}

int	prepare_C_Constant(struct const_member * nptr, int mode) 
{
	if (!( mode )) {

		output_string("#define ");
		output_string( nptr->name );
		if ( not_blank(nptr->value) ) {
			output_string(" ");
			output_string(nptr->value);
			}
		}

	return(strlen(classbuffer) );
}

int	prepare_C_Data(struct data_member * nptr, int mode)
{
	if ( mode ) {
		if (!( nptr->type.type & _TYPE_COMMON ))
			return(0);
		else	output_string("static ");
		}

	output_c_datatype( &nptr->type,0 );
	output_string( nptr->name );
	output_c_dimension(nptr->first);
	output_c_dimension(nptr->second);
	if ( mode ) {
		if (!( nptr->type.type & _TYPE_COMMON ))
			output_string("*/ ");
		else if ( not_blank( nptr->construction )) {
			output_string("=");
			output_string(nptr->construction);
			}
		}
	output_string(";");
	return(strlen(classbuffer) );
}

int 	prepare_C_Method(struct method_member * nptr,int mode)
{
	switch ( mode ) {

		case	0 : /* Signature of Prototype */

			if ((!( nptr->options & (_TYPE_VIRTUAL | _TYPE_OVERLOAD)))
			&&  (!( nptr->type.type &  _TYPE_POINTER )))
				output_string( "/* ");

			output_c_datatype( &nptr->type, 0 );
			output_string("(*");
			output_string( nptr->name );
			output_string(")(");
			output_string( nptr->parameters );
			output_string(");");

			if ((!( nptr->options & (_TYPE_VIRTUAL | _TYPE_OVERLOAD)))
			&&  (!( nptr->type.type &  _TYPE_POINTER )))
				output_string( "*/ ");
			break;

		case	1 : /* Method instance Signature */
			output_c_datatype( &nptr->type, 0 );
			output_string( nptr->parent->name );
			output_string( "_");
			output_string( nptr->name );
			output_string("(");
			output_string( nptr->parameters );
			output_string(") {");
		}

	return(strlen(classbuffer) );
}

int	prepare_Cpp_Constant(struct const_member * nptr, int mode) 
{
	if (!( mode )) {
		if ( visible != nptr->protection ) {
			if ((visible = nptr->protection) !=0 )
				output_string( "public: ");
			else	output_string( "private: ");
			}
		output_string( "const ");
		output_string( nptr->name );
		output_string("=");
		output_string(nptr->value);
		output_string(";");
		}
	return(strlen(classbuffer) );
}

void	output_linefeed()
{
#ifndef	UNIX
	output_string("\r\n");
#else
	output_string("\n");
#endif
	return;
}

int	instance_Cpp_Data(struct data_member * nptr)
{
	if (!( nptr->type.type & _TYPE_COMMON ))
		return(0);

	output_c_datatype( &nptr->type, 1);

	output_string(nptr->parent->name);
	output_string("::");

	output_string( nptr->name );
	output_c_dimension(nptr->first);
	output_c_dimension(nptr->second);

	if ( not_blank( nptr->construction ) ) {
		if ( nptr->type.type & _TYPE_CLASS ) {
			output_string("(");
			output_string(nptr->construction);
			output_string(")");
			}
		else if ( nptr->type.type & _TYPE_COMMON ) {
			output_string("=");
			output_string(nptr->construction);
			}
		}
	output_string(";");
	return(strlen(classbuffer) );

}

int	define_Cpp_Data(struct data_member * nptr)
{
	/* Comment out base class components */

	if ( visible != nptr->protection ) {
		if ((visible = nptr->protection) !=0 )
			output_string( "public:  ");
		else	output_string( "private: ");
		}

	if (( is_blank( nptr->name ) )
	&&  ( nptr->type.type & _TYPE_CLASS )
	&&  ( not_blank( nptr->type.name )  ))
		output_string("// ");


	if ( nptr->type.type & _TYPE_COMMON )
		output_string("static ");

	output_c_datatype( &nptr->type, 1);

	output_string( nptr->name );
	output_c_dimension(nptr->first);
	output_c_dimension(nptr->second);
	output_string(";");
	return(strlen(classbuffer) );
}

int	prepare_Cpp_Data(struct data_member * nptr, int mode)
{
	if ( mode )
		return( instance_Cpp_Data(nptr) );
	else	return( define_Cpp_Data(nptr) );
}
		
int 	prepare_Cpp_Method(struct method_member * nptr,int instance_mode)
{
	if (!( instance_mode )) { /* Prototype into Class */
		
		if ( visible != nptr->protection ) {
			if ((visible = nptr->protection) !=0 )
				output_string( "public: ");
			else	output_string( "private: ");
			}

		if (( nptr->options & _TYPE_OVERLOAD)
		||  ( nptr->options & _TYPE_VIRTUAL))
			output_string("virtual ");

		if ( nptr->options  & _TYPE_DESTRUCTOR ) {
			output_string("~");
			output_string( nptr->parent->name );
			}
		else if (nptr->options  & _TYPE_CONSTRUCTOR ) 
			output_string( nptr->parent->name );
		else	{
			output_c_datatype( &nptr->type, 1 );
			output_string( nptr->name );
			}

		output_string("(");
		if ( not_blank( nptr->parameters ) )
			output_string( nptr->parameters );
		else	output_string("void");
		output_string(");");
		}
	else	{
		/* Method instance */
		/* --------------- */
		if ((!( nptr->options  & _TYPE_DESTRUCTOR  )) 
		&&  (!( nptr->options  & _TYPE_CONSTRUCTOR ))) {
			output_c_datatype( &nptr->type, 1 );
			output_string(" ");
			}

		output_string(nptr->parent->name);
		output_string("::");

		if ( nptr->options  & _TYPE_DESTRUCTOR ) {
			output_string("~");
			output_string( nptr->parent->name );
			}

		else if (nptr->options  & _TYPE_CONSTRUCTOR ) 
			output_string( nptr->parent->name );

		else	output_string( nptr->name );

		output_string("(");
		output_string( nptr->parameters );
		output_string(")");
		if ( not_blank(nptr->base) ) {
			output_linefeed();
			output_string(" : ");
			output_string( nptr->base );
			}
		output_linefeed();
		output_string("{");
		}

	return(strlen(classbuffer) );
}

int	prepare_Html_Constant(struct const_member * nptr, int mode) 
{
	output_string( nptr->value );
	return(strlen(classbuffer) );
}

int	prepare_Html_Data(struct data_member * nptr, int mode)
{
	output_string( nptr->construction );
	return(strlen(classbuffer) );
}

int 	prepare_Html_Method(struct method_member * nptr,int mode)
{
	return(0);
}

void	output_bal_data_type( struct standard_type * tptr,int mode )
{
	switch ( tptr->type & _BASIC_TYPE ) {
		case	_TYPE_VOID	:
			break;
		case	_TYPE_BYTE	:
			output_string("#"); break;
		case	_TYPE_WORD	:
			output_string("%"); break;
		case	_TYPE_LONG	:
		case	_TYPE_FLOAT	:
		case	_TYPE_BCD 	:
			if ( mode )
				output_string("*");
			break;

		case	_TYPE_CLASS	:
		case	_TYPE_STRING	:
			output_string("$");
			break;

		}
	return;
}

void	output_bal_dimensions(struct data_member * nptr)
{
	if (( nptr->type.type & (_TYPE_LONG | _TYPE_FLOAT | _TYPE_BCD | _TYPE_STRING))) {
		output_string("=");
		output_int( nptr->size );
		}
	if ( nptr->first > 1 ) {
		output_string("(");
		output_int( nptr->first );
		if ( nptr->second > 1 ) {
			output_string(",");
			output_int( nptr->second );
			}
		output_string(")");
		}
	return;
}

int	prepare_Bal_Constant(struct const_member * nptr, int mode) 
{
	output_string( "Const ");
	output_string( nptr->name );
	output_bal_data_type( &nptr->type,0 );	
	output_string("=");
	output_string( nptr->value );
	return(strlen(classbuffer) );
}

int	prepare_Bal_Data(struct data_member * nptr, int mode)
{
	if (!( nptr->type.type & _TYPE_POINTER ))
		output_string( "Dcl ");
	else	output_string( "Ptr ");
	output_string( nptr->name );
	output_bal_data_type( &nptr->type,0 );	
	output_bal_dimensions( nptr );
	return(strlen(classbuffer) );
}

int 	prepare_Bal_Method(struct method_member * nptr,int mode)
{
	if (not_blank( nptr->parameters )) {
		output_string("Proc ");
		output_string( nptr->name );
		output_string("(");
		output_string( nptr->parameters );
		output_string(")");
		if ( nptr->type.type & _BASIC_TYPE) {
			output_string(" : ");
			output_bal_data_type( &nptr->type,1 );	
			}
		}
	else	{
		output_string("Segment ");
		output_string( nptr->name );
		}
	return(strlen(classbuffer) );
}

void	output_abal_data_type( struct standard_type * tptr,int mode )
{
	switch ( tptr->type & _BASIC_TYPE ) {
		case	_TYPE_VOID	:
			break;
		case	_TYPE_BYTE	:
		case	_TYPE_WORD	:
			output_string("Integer "); break;

		case	_TYPE_LONG	:
		case	_TYPE_FLOAT	:
		case	_TYPE_BCD 	:
			output_string("Numeric "); 
			break;

		case	_TYPE_STRING	:
			output_string("String ");
			break;

		case	_TYPE_CLASS	:
			output_string( "Class " );
			output_string( tptr->name);
			output_string( " ");
		}
	if ( tptr->type & _TYPE_POINTER )
		output_string( "Pointer " );

	return;
}

int	prepare_Abal_Constant(struct const_member * nptr, int mode) 
{
	if ( nptr->protection )
		output_string( "Public ");
	else	output_string( "Private ");
	output_string( "Const ");
	output_string( nptr->name );
	output_bal_data_type(&nptr->type,0);
	output_string("=");
	output_string(nptr->value);
	return(strlen(classbuffer) );
}

int	prepare_Abal_Data(struct data_member * nptr, int mode)
{
	char	*	mptr;
	/* detect base class component */
	if (( is_blank( nptr->name ) )
	&&  ( nptr->type.type & _TYPE_CLASS )) {
		output_string("(");
		if ( nptr->protection )
			output_string( "Public ");
		else	output_string( "Private ");
		if ( nptr->type.type & _TYPE_COMMON  )
			output_string("Common ");

		output_string( nptr->type.name );
		if ( not_blank(nptr->construction) ) {
			output_string("(");
			output_string(nptr->construction);
			output_string(")");
			}
		output_string(")");
		}
	else	{
		if ( nptr->protection )
			output_string( "Public ");
		else	output_string( "Private ");
		if ( nptr->type.type & _TYPE_COMMON  )
			output_string("Common ");
		if ( nptr->type.type & _TYPE_CLASS ) {
			/* output_string( "Class "); */
			output_string( nptr->type.name );
			if ( nptr->type.type & _TYPE_POINTER ) 
				output_string(" Pointer ");
			else	output_string( " " );
			output_string( nptr->name );
			if  ( not_blank(nptr->construction) ) {
				output_string("(");
				output_string(nptr->construction);
				output_string(")");
				}
			}
		else	{
			if ( nptr->type.type & _TYPE_POINTER ) 
				output_string("Pointer ");
			else	output_string("Dcl ");		
			output_string( nptr->name );
			output_bal_data_type(&nptr->type,0);
			output_bal_dimensions(nptr);
			}
		}
	return(strlen(classbuffer) );
}

int 	prepare_Abal_Method(struct method_member * nptr,int mode)
{
	if ( nptr->protection )
		output_string( "Public ");
	else	output_string( "Private ");
	if ( nptr->options  & _TYPE_OVERLOAD )
		output_string("Overload ");
	else if ( nptr->options & _TYPE_VIRTUAL)
		output_string("Virtual ");
	output_abal_data_type(&nptr->type,0);
	if ( nptr->options  & _TYPE_CONSTRUCTOR )
		output_string(  "Constructor " );
	else if ( nptr->options  & _TYPE_DESTRUCTOR )
		output_string( "Destructor " );
	else	output_string( "Method " );
	output_string( nptr->name );
	output_string(":");
	if ( not_blank(nptr->parameters ) ) {
		output_string("(");
		output_string( nptr->parameters );
		output_string(")");
		}
	return(strlen(classbuffer) );
}

int	prepare_Java_Constant(struct const_member * nptr, int mode) 
{
	return(strlen(classbuffer) );
}
int	prepare_Java_Data(struct data_member * nptr, int mode)
{
	return(strlen(classbuffer) );
}

int 	prepare_Java_Method(struct method_member * nptr,int mode)
{
	return(strlen(classbuffer) );
}




int	prepare_constant(struct const_member * mptr, int mode )
{
	switch ( mode ) {
		case	0 :	
		case	1 :
			switch ( mptr->parent->language ) {
				case	_GENERATE_C		:
					return(prepare_C_Constant( mptr,mode ) );
				case	_GENERATE_CPP		:	
					return( prepare_Cpp_Constant( mptr,mode ) );
				case	_GENERATE_HTML		:
					return( prepare_Html_Constant( mptr,mode ) );
				case	_GENERATE_BAL		:
					return( prepare_Bal_Constant( mptr,mode ) );
				case	_GENERATE_ABAL		:
					return( prepare_Abal_Constant( mptr,mode ) );
				case	_GENERATE_JAVA		:
					return( prepare_Java_Constant( mptr,mode ) );
				}
		 }
	return( 0 );
}

int	prepare_data(struct data_member * mptr, int mode )
{

	switch ( mode ) {
		case	0	:
		case	1	:

			switch ( mptr->parent->language ) {
				case	_GENERATE_C		:
					return(prepare_C_Data( mptr,mode ) );
				case	_GENERATE_CPP		:
					return( prepare_Cpp_Data( mptr,mode ) );
				case	_GENERATE_HTML		:
					return( prepare_Html_Data( mptr,mode ) );
				case	_GENERATE_BAL		:
					return( prepare_Bal_Data( mptr,mode ) );
				case	_GENERATE_ABAL		:
					return( prepare_Abal_Data( mptr,mode ) );
				case	_GENERATE_JAVA		:
					return( prepare_Java_Data( mptr,mode ) );
				}
		}
	return(0);

}

private	int	method_body(struct method_member * mptr )
{
	char	*	eptr;
	int		n;
	int		i;
	int		l;
	int		blen=0;
	
	if ( mptr->methtool == _TEXT_TOOL ) {
		if ( not_blank((eptr = mptr->instructions)) ) {
			blen = strlen(classbuffer);
			l = strlen( eptr );
			do	{
				if ((n = l) > EDITOR_COLUMNS)
					n = EDITOR_COLUMNS;
				if (!( *eptr ))
					break;
				if (!( *eptr ))
					break;
				*(classbuffer+blen)='\t';
				blen++;
				for (i=0; i < n; i++ ) {
					if (!( *eptr )) 
						break;
					else	{
						*(classbuffer+blen)=*(eptr++);
						blen++;
						}
					}
#ifndef	UNIX
				*(classbuffer+blen)='\r';
				blen++;
#endif
				*(classbuffer+blen)='\n';
				blen++;
				l -= n;
				}
			while ( l > 0 );
			*(classbuffer+blen)=0;
			}
		else 	strcpy( classbuffer, " ");
		}
	return( strlen( classbuffer ) );	
}

private	int	method_end(struct method_member * mptr )
{
	switch ( mptr->parent->language ) {
		case	_GENERATE_C		:
		case	_GENERATE_CPP		:
		case	_GENERATE_JAVA		:
			output_string(" } ");
			break;

		case	_GENERATE_BAL		:
			if (not_blank( mptr->parameters ))
				output_string("EndProc");
			else if ((( mptr->type.type & _BASIC_TYPE ) == _TYPE_VOID )
			     && (!( mptr->type.type & _TYPE_POINTER ))) {
				output_string("Eseg ");
				output_string(mptr->name);
				}
			else	output_string("EndProc");
			break;
		case	_GENERATE_ABAL		:
			output_string("End");
			break;
		case	_GENERATE_HTML		:
		default				:
			return(0);
		
		}
	
	return(strlen(classbuffer) );

}

int	prepare_method(struct method_member * mptr, int mode )
{
	switch ( mode ) {
		case	2	:	/* Method Text */
			return( method_body((struct method_member*) mptr));
		case	3	:	/* End Method */
			return( method_end((struct method_member*) mptr));

		case	0	:	/* Prototype */

		case	1	: 	/* Signature */

			switch ( mptr->parent->language ) {
				case	_GENERATE_C		:	
					return(prepare_C_Method( mptr, mode ));
				case	_GENERATE_CPP		:
					return( prepare_Cpp_Method( mptr, mode ));
				case	_GENERATE_HTML		:
					return( prepare_Html_Method( mptr, mode ));
				case	_GENERATE_BAL		:
					return( prepare_Bal_Method( mptr, mode ));
				case	_GENERATE_ABAL		:
					return( prepare_Abal_Method( mptr, mode ));
				case	_GENERATE_JAVA		:
					return( prepare_Java_Method( mptr, mode ));
				}
		}
	return(0);
}

int	prepare_member(struct standard_member * mptr, int mode )
{
	
	if (!( check_class_buffer() ))
		return(0);
	else if (!( mptr ))
		return( 0 );
	switch ( mptr->nature ) {
		case	_MEMBER_CONSTANT :
			return( prepare_constant((struct const_member *) mptr, mode ) );
		case	_MEMBER_DATA	 :
			return( prepare_data((struct data_member *) mptr, mode ) );
		case	_MEMBER_METHOD	:
			return( prepare_method((struct method_member*) mptr, mode ) );
		default			:
			return(0);
		}

}

int	show_Member(struct standard_node * nptr,int state)
{
	struct	standard_member * mptr;
	int			  slen=0;
	if (!( mptr = nptr->contents ))
		return(0);
	else if (!(slen = prepare_member( mptr,0 )))
		return(0);
	else	return( console_Message( nptr->x, nptr->y, state, classbuffer, slen, 1 ) );
}

int	specify_ClassMember(struct standard_class * cptr)
{
	struct standard_list * lptr;
	struct standard_node * nptr;
	struct	standard_member * mptr;
	if (!( cptr ))
		return(0);
	if (!( lptr = cptr->members))
		return(0);
	else if (!(nptr = lptr->current ))
		return(0);
	else if (!( mptr = nptr->contents ))
		return(0);
	else	{
		switch ( mptr->nature ) {
			case	_MEMBER_CONSTANT :
				return( specify_constant( (struct const_member *) mptr ) );
			case	_MEMBER_DATA :
				return( specify_data( (struct data_member *) mptr ) );
			case	_MEMBER_METHOD :
				return( specify_method( (struct method_member *) mptr ) );
			default			:
				return(0);
			}
		}
}
int	change_ClassMember(struct standard_class * cptr, int event )
{
	struct standard_list * lptr;
	struct standard_node * nptr;
	struct	standard_member * mptr;
	if (!( cptr ))
		return(0);
	if (!( lptr = cptr->members))
		return(0);
	else	{
		switch ( event ) {
			case	_FIRST_ITEM	:
				lptr->base = lptr->current = lptr->first;
				return(257);
			case	_LAST_ITEM	:
				lptr->base = lptr->current = lptr->last;
				return(257);
			case	5		:
			case	_NEXT_ITEM	:
				if (!( nptr = lptr->current ))
					return(0);
				else if (!( nptr->next ))
					return(0);
				else if ( nptr->item == cptr->items ) {
					lptr->current = nptr->next;
					return(0);
					}
				else	{
					lptr->base = lptr->base->next;
					lptr->current = lptr->current->next;
					return(257);
					}
			case	11		:
			case	_PREVIOUS_ITEM	:
				if (!( nptr = lptr->current ))
					return(0);
				else if (!( nptr->previous ))
					return(0);
				else if( nptr->item != 1 ) {
					lptr->current = nptr->previous;
					return(0);
					}
				else if (!( lptr->base->previous ))
					return(0);
				else	{
					lptr->base = lptr->base->next;
					lptr->current = lptr->current->next;
					return(257);
					}
			}
		return(0);
		}
}

void	document_ClassMember(struct standard_class * cptr)
{
	struct standard_list * lptr;
	struct standard_node * nptr;
	struct	standard_member * mptr;
	if (!( cptr ))
		return;
	else if (!( lptr = cptr->members))
		return;
	else if (!( nptr = lptr->current ))
		return;
	else if (!(mptr = nptr->contents ))
		return;
	else	{
		use_visual_text_editor( & mptr->document, _GENERATE_HTML );
		}
}

void	show_ClassMember(struct standard_class * cptr, int state)
{
	struct standard_list * lptr;
	struct standard_node * nptr;
	struct	standard_member * mptr;
	if (!( cptr ))
		return;
	else if (!( lptr = cptr->members))
		return;
	else if (!( nptr = lptr->current ))
		return;
	else if (!( nptr->contents ))
		return;
	else	{
		show_Member( nptr, state );
		return;
		}
}

private	void	flush_classbuffer(FILE * h)
{
	char	*	cptr;
	for (cptr=classbuffer; *cptr != 0; cptr++ )
		fprintf(h,"%c",*cptr);
#ifndef	UNIX
	fprintf(h,"\r\n");
#else
	fprintf(h,"\n");
#endif
	return;
}
public 	int	export_class_members( FILE * h, struct standard_class * cptr )
{
	struct	standard_member * mptr;
	struct standard_node * nptr;
	struct standard_list * lptr;

	if (!( cptr ))
		return(0);
	else if (!( lptr = cptr->members ))
		return(0);

	for (	nptr=lptr->base;
		nptr != (struct standard_node *) 0;
		nptr = nptr->next ) {
		if (!( mptr = nptr->contents ))
			continue;
		else if (!( prepare_member( mptr, 0) ))
			continue;
		else	flush_classbuffer( h );
		}
	return(0);
}

public 	int	first_pass_Class(FILE * h, struct standard_class * cptr, int automatic )
{
	struct	standard_member * mptr;

	if (!( cptr->members ))
		return(0);

	visible = -1;

	if ( prepare_class(cptr,0) != 0 ) 
		flush_classbuffer( h );

	visible = -1;

	export_class_members(h, cptr );

	if ( prepare_endclass(cptr,0) != 0 )
		flush_classbuffer( h );

	return(0);
}

public 	int	second_pass_Class(FILE * h, struct standard_class * cptr, int automatic )
{
	struct	standard_member * mptr;
	struct standard_list * lptr;
	struct standard_node * nptr;
	int	item;

	if (!( lptr = cptr->members ))
		return(0);

	if ( prepare_class(cptr,1) != 0 ) 
		flush_classbuffer( h );

	for (	nptr=lptr->base;
		nptr != (struct standard_node *) 0;
		nptr = nptr->next ) {
		if (!( mptr = nptr->contents ))
			continue;
		else	{
			for (	item=1; prepare_member( mptr, item) != 0; item++)
				flush_classbuffer( h );
			}
		}
	if ( prepare_endclass(cptr,1) != 0 )
		flush_classbuffer( h );

	return(0);
}

public 	int	export_Class( struct standard_class * cptr, int automatic )
{
	FILE	*	h;

	if (!( cptr ))
		return(0);

	if (!( cptr->prodname ))
		if (!(cptr->prodname = allocate_string( "new.cls" ) )) 
			return(27);

	if (!( automatic & _INHIBIT_PROPERTIES )) {
		if ( specify_Class( cptr ) == 27 ) {
			if (!( automatic & _INHIBIT_REFRESH ))
				draw_console();
			return(0);
			}
		}

	/* C and C++ require header file generation */
	/* ---------------------------------------- */
	switch ( cptr->language ) {
		case	_GENERATE_C	:
		case	_GENERATE_CPP	:
			if ( cptr->headname ) {
				if ((h = open_production_target(cptr->headname,0)) != (FILE*)0) {
					file_exclusion(h,cptr->headname);
					if (!( automatic & _INHIBIT_STATUS ))
						status_message(cptr->headname,3);
					if ( cptr->dependance )
						c_dependance(h,cptr->dependance );
					first_pass_Class( h, cptr, automatic );
					close_exclusion(h,cptr->headname);
					close_production_target( h, cptr->headname );
					}
				}
		}
		
	/* All production langauges produce output */
	/* --------------------------------------- */
	if ((h = open_production_target(cptr->prodname,0)) != (FILE*)0) {

		if (!( automatic & _INHIBIT_STATUS ))
			status_message(cptr->prodname,3);

		file_exclusion(h,cptr->prodname);
		switch ( cptr->language ) {

			case	_GENERATE_C	:
			case	_GENERATE_CPP	:

				if ( cptr->headname )
					c_include(h,cptr->headname);

				break;

			case	_GENERATE_BAL	:
			case	_GENERATE_ABAL	:

				if ( cptr->dependance )
					abal_dependance(h,cptr->dependance,3 );
				break;


			}
				
		second_pass_Class( h, cptr, automatic );
		close_exclusion(h,cptr->prodname);

		close_production_target( h, cptr->prodname );

		}

	if (!( automatic & _INHIBIT_REFRESH ))
		draw_console();

	return(0);
}

public	void			draw_Class(struct standard_class * cptr)
{
	int	atrow=0;
	int	atcol=0;
	int	fh,fw;
	int	i=1;
	int	slen=0;
	struct standard_list * lptr;
	struct standard_node * nptr;

	fh = guifontsize(1);	
	fw = (fh & 0x00FF);
	fh >>= 8;	
	fh &= 0x00FF;

	if (!( lptr = cptr->members ))
		return;

	if ((slen = prepare_class(cptr,0)) != 0 ) {
		atrow = console_Message( 0,0, 1, classbuffer, slen, 1 );
		}
	else	atrow = 0;

	for (	i=1,nptr=lptr->base;
		nptr != (struct standard_node *) 0;
		nptr = nptr->next, i++ ) {
		nptr->x = atcol; nptr->y = atrow;
		nptr->item = i;
		show_Member( nptr, 0 );
		atrow += fh;
		if ( atrow >= Context.DeskTop.h )
			break;
		}
	cptr->items = i;
	if (!( nptr )) {
		if ( atrow < Context.DeskTop.h ) {
			if ((slen = prepare_endclass(cptr,0)) != 0 )
				atrow += console_Message( 0,atrow, 1, classbuffer,slen,1 );
			}
		}
	return;

}

public	int	is_ClassEvent(struct standard_class * cptr, int x, int y)
{
	int	i;
	struct standard_list * lptr;
	struct standard_node * nptr;

	if (!( lptr = cptr->members ))
		return(256);

	else if (( i = is_ConsoleEvent( x, y )) != 0) {
		i--;
		for (	nptr=lptr->base;
			nptr != (struct standard_node *) 0;
			nptr = nptr->next ) {
			if ( nptr->item == i ) {
				show_ClassMember(cptr,0);
				lptr->current = nptr;
				show_ClassMember(cptr,2);
				break;
				}
			}
		}
	return(256);
}

private	void	class_Image(struct standard_class * cptr)
{
	struct	standard_image * grab_Image(struct window_control *, struct standard_image *);
	struct window_control Window;

	(void) class_header( &cptr->name );

	Window.x = Window.y = 0;
	Window.w = 440; Window.h = 180;

	cptr->image = grab_Image(&Window, cptr->image );
	cptr->savestamp = time((long *) 0);
	return;
}


public	int	edit_Class(struct standard_class **  ccptr, int mode )
{
	struct	standard_class * cptr;

	int	event=0;
	int	lastitem=__ADD_METHOD;
	struct	standard_class * kptr;

	if (!( ccptr ))
		return( 0 );
	else	cptr = *ccptr;	

	if ((!( cptr ))
	&&  (!( cptr = allocate_Class((char *) 0) )))
		return( 0 );

	else	{
		Context.Class = cptr;	
		activate_DeskTop(_SCROLL_FRAME );
		draw_console();
		}

	add_class_menu();

	while (1) {

		show_ClassMember(cptr,2);
		while (((event = visual_getch())   == 256)
		&&     ((event = handle_event()) == 256));
		show_ClassMember(cptr,0);

		if ( event == 1 ) /* Ctrl A(dd same again) */
			event = lastitem;

		switch ( event ) {

			case	_EDIT_TEXT	:
				if ( cptr->prodname  )
					event = use_editor( cptr->prodname, cptr->language );
				continue;

			case	_VIEW_TEXT	:
			case	_VIEW_IMAGE	:
			case	_EDIT_FORM	:
			case	_EDIT_GRAPH	:
				class_Image( cptr );
				break;

			case	0x007F		:
				if ( del_class_member( cptr ) )
					draw_console();
				continue;
	

			case	__ADD_CONSTANT	:
				lastitem = event;
				add_class_member( cptr, _MEMBER_CONSTANT,0 );
				draw_console();
				continue;
					
			case	__ADD_DATA	:
				lastitem = event;
				add_class_member( cptr, _MEMBER_DATA, 0 );
				draw_console();
				continue;

			case	__ADD_METHOD	:
				lastitem = event;
				add_class_member( cptr, _MEMBER_METHOD, 0 );
				draw_console();
				continue;

			case	__CLASS_PROPERTIES	:
				specify_Class((struct standard_class*)cptr);
				draw_console();
				continue;

			case		9	:
			case	_EDIT_PROPERTIES	:
				specify_ClassMember( cptr );
				draw_console();
				continue;

			
			case	_EVENT_ITEMDOC		:
				document_ClassMember(cptr);
				draw_console();
				continue;

			case	_EVENT_FORMDOC		:
				use_visual_text_editor( & cptr->document, _GENERATE_HTML );
				continue;


			case	_FILE_SAVE		:
				save_Class((struct standard_class*)cptr,0);
				draw_console();
				continue;
			case	_FILE_QSAVE		:
				save_Class((struct standard_class*)cptr,QUICK);
				draw_console();
				continue;

			case	_FILE_LOAD		:
				if ((kptr = load_Class(cptr->loadname,0)) != (struct standard_class *) 0) {
					cptr = liberate_Class( cptr );
					Context.Class = cptr = kptr;
					}

			case	_FILE_PRODUCE	:
				export_Class(cptr,0);
				continue;

			case	_FILE_COMPARE	:
				compare_Files((char *) 0, (char *) 0);
				continue;

			case	257	:
				draw_console();
				continue;

			case	_LEAVE_SING	:
				break;

			case	5		:
			case	11		:
			case	_FIRST_ITEM	:
			case	_PREVIOUS_ITEM	:
			case	_NEXT_ITEM	:
			case	_LAST_ITEM	:
				if ( change_ClassMember( cptr, event ) )
					draw_console();
				continue;

			default			:
				continue;
			}
		break;

		}

	drop_class_menu();

	Context.Class = (struct standard_class*) 0;
	activate_DeskTop(_OUTSET_FRAME );
	*ccptr = cptr;
	return(event);

}

public	int	document_Class( 
			FILE * handle,
			struct standard_class * cptr,
			int automatic , int report
			)
{
	struct standard_list   * lptr;
	struct standard_node   * nptr;
	struct standard_member * mptr;
	int			 slen;

	if ( cptr->document )
		html_paragraph( handle, cptr->document );

	if (!( lptr = cptr->members))
		return(1);

	html_heading(handle,3,"Components");
	html_tag(handle,"dl");

	for (	nptr=lptr->base;
		nptr != (struct standard_node *) 0;
		nptr = nptr->next ) {
		if (!( mptr = nptr->contents ))
			continue;
		else if (!(slen = prepare_member( mptr,0 )))
			continue;
		html_tag(handle,"dt");
		html_paragraph(handle, classbuffer );
		if ( mptr->document ) {
			html_tag(handle,"dd");
			html_paragraph(handle, mptr->document );
			}			
		}

	html_closure(handle,"dl");
	html_paragraph( handle, " " );
	return(1);
}

public	void	select_classname( char * nptr )
{
	return;
}

public	int	select_TreeClass( struct standard_class * cptr )
{
	select_TreeHost( cptr->host );
	return(0);
}


#endif	/* _singclas_c */


















































































































