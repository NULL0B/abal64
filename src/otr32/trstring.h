#ifndef	_TRSTRING_H
#define	_TRSTRING_H

struct	_string {
	unsigned short	length;
	unsigned char *  value;
	};

struct _string * 	allocate_string( unsigned short );
void		 	liberate_string( struct _string * );
void		 	copy_string( struct _string *, struct _string * );
void		 	build_string( struct _string *, unsigned char * , unsigned short );
void		 	set_string( struct _string *, unsigned char * );
void			iof_prn_string( struct _string * );

unsigned short			len_string( struct _string * );
unsigned short			lendollar( struct _string * );

struct _string * 	left_string( struct _string *, unsigned short );
struct _string * 	right_string( struct _string *, unsigned short, unsigned short );
struct _string * 	sub_string( struct _string *, unsigned short, unsigned short );
struct _string * 	shl_string( struct _string * );
struct _string * 	shr_string( struct _string * );
struct _string * 	inv_string( struct _string * );
struct _string * 	large_string( struct _string * );
struct _string * 	small_string( struct _string * );

#endif	/* _TRSTRING_H */
	/* ----------- */



