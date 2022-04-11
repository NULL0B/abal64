#ifndef	_inxsql_mysql_h
#define	_inxsql_mysql_h

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

#define	_INXSQL_MYSQL_ENGINE		1
#define	INXSQL_ROW MYSQL_ROW

#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

#ifndef _INXSQL_DEFAULT_ENGINE
#define	_INXSQL_DEFAULT_ENGINE _INXSQL_MYSQL_ENGINE
#endif

#define	_INXS_CHAR_SET	"utf8mb4"

#endif /* _inxsql_mysql_h */
