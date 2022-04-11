#ifndef	_inxsql_sqlite_h
#define	_inxsql_sqlite_h

/*      ------------------------------------------------        */
/*                                                              */
/*      INXSQL : Database Client Library for ABAL and D3        */
/*                                                              */
/*      ------------------------------------------------        */
/*                                                              */
/*           Copyright (c) 2014-2021 Amenesik SARL              */
/*                                                              */
/*          Iain James Marshall  <ijm@amenesik.com>             */
/*                                                              */
/*      ------------------------------------------------        */

#include <sqlite.h>

#define	_INXSQL_SQLITE_ENGINE		4

#ifndef	INXSQL_ROW
#define	INXSQL_ROW void *
#endif

#ifndef _INXSQL_DEFAULT_ENGINE
#define	_INXSQL_DEFAULT_ENGINE _INXSQL_SQLITE_ENGINE
#endif

#ifndef	SSL_MODE_DISABLED
#define SSL_MODE_DISABLED 0
#endif

#ifndef	SSL_MODE_REQUIRED
#define SSL_MODE_REQUIRED 1
#endif

#define	_INXS_CHAR_SET	"UTF8"

#endif /* _inxsql_sqlite_h */
