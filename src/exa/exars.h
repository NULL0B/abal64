#ifndef	_EXARS_H
#define	_EXARS_H

#include "xmlparse.h"

struct	abal_remote_service
{
	char			    *	service;	/* the service prefix string	*/
	char 			    *	program;	/* the service library name	*/
	void			    * 	handle;		/* the service library handle	*/
	struct	abal_remote_service * 	previous;	/* previous in service list	*/
	struct	abal_remote_service * 	next;		/* next item in service list	*/

	/* -------------------------------------------------------- */
	/* constructor method pointer retreived during package load */
	/* -------------------------------------------------------- */
	int	(*initialise)(struct abal_remote_service * s);
	int	(*exitvalue)(  int v );
	int	(*exitstring)( int t, char * bptr, int blen);
	int	(*xmlparser)( char * filename, struct xml_relay * interfaceitem, void * application );

	/* -------------------------------------------------------- */
	/* method pointers to those provided within service package */
	/* -------------------------------------------------------- */
	void * 	(*open)( struct program_url * url );
	int	(*attach)( void *, struct program_url * url, char * xptr  );
	int	(*parameters)( void *, int argc, char * argv );
	int	(*call)( void *, int procid , char * pptr );
	int	(*result)( void * );
	int	(*detach)( void * );
	void *	(*close)( void * );

};

	/* -------- */
#endif	/* _EXARS_H */
	/* -------- */



