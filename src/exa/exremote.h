/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXREMOTE.H
 *		Version :	4.0a
 *		Date 	:	01/12/2010
 */
#ifndef	_EXREMOTE_H
#define	_EXREMOTE_H

#include "exurl.h"

#define	_REMOTE_PREFIX	"abalrpc:"
#define	EXREMOTE	struct remote_context
#define	EXREMOTEPTR	EXREMOTE PTR 

#include "exars.h"

struct	remote_context	
{
	struct	abal_remote_service	*	service;
	struct	program_url			url;
	void				*	handle;
};


	/* ----------- */
#endif	/* _EXREMOTE_H */
	/* ----------- */

