#ifndef	_inxsql_h
#define	_inxsql_h

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

/*	--------------------	*/
/*	INXS FILE INCLUSIONS 	*/
/*	--------------------	*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <memory.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

#define	USE_RECORD_BINDING

/*	-------------	*/
/*	INXS DATABASE 	*/
/*	-------------	*/

#define	_INXSQL_UNKNOWN_ENGINE		0

#ifdef	_INXSQL_MYSQL
#include "inxsql_mysql.h"
#endif

#ifdef	_INXSQL_PGSQL
#include "inxsql_postgresql.h"
#endif

#ifdef	_INXSQL_ORACLE
#include "inxsql_oracle.h"
#endif

#ifdef	_INXSQL_SQLITE
#include "inxsql_sqlite.h"
#endif

#ifdef	_INXSQL_SQLSERVER
#include "inxsql_sqlserver.h"
#endif

#ifdef	_INXSQL_MYSQL
#ifdef	_INXSQL_PGSQL
#define	inxsql_fetch_field(x,r,f) (x->engine==_INXSQL_MYSQL_ENGINE?r[f]:(x->engine==_INXSQL_PGSQL_ENGINE?PQgetvalue(x->result,(x->row-1),f):""))
#else
#define	inxsql_fetch_field(x,r,f) (x->engine==_INXSQL_MYSQL_ENGINE?r[f]:"")
#endif
#else
#ifdef	_INXSQL_PGSQL
#define	inxsql_fetch_field(x,r,f) (x->engine==_INXSQL_PGSQL_ENGINE?PQgetvalue(x->result,(x->row-1),f):"")
#else
#define	inxsql_fetch_field(x,r,f) ""
#endif
#endif

#define	_INXS_VERSION	'X'
#define	_INXS_MAGIC  	'S'

/*	----------------	*/
/*	Connection Flags	*/
/*	----------------	*/
#define	_INXS_INIT	1
#define	_INXS_SELECT	2

/*	------------	*/
/*	XS KEY Types	*/
/*	------------	*/
#define _XS_KEY_A      0       // String (Binary)
#define _XS_KEY_N      1       // numeric byte or word : Length
#define _XS_KEY_L      2       // LONG 32bit INT
#define _XS_KEY_S      3       // String Ascii
#define _XS_KEY_F      4       // Float / Numeric
#define _XS_KEY_D      5       // Date Y%,M#,D#
#define _XS_KEY_T      6       // Time H#,M#,S#
#define _XS_KEY_H      7       // HUGE 64bit INT

/*	---------------		*/
/*	INXS DATA TYPES		*/
/*	---------------		*/

#define	_INXS_BIN   			0	/* BINARY ZERO padded			*/
#define	_INXS_INT8  			1	/* TINY INT		ABAL #		*/
#define	_INXS_INT16  			2	/* SHORT INT		ABAL %		*/
#define	_INXS_FLOAT			3	/* FLOAT		ABAL ?		*/
#define	_INXS_STRING			4	/* CHAR(N) or BLOB(N)	ABAL $		*/
#define	_INXS_INT32  			5	/* INT			ABAL :		*/
#define	_INXS_INT64  			6	/* LONG LONG INT	ABAL @		*/
#define	_INXS_BCD    			7	/* BCD NUMERIC  	ABAL =		*/
#define	_INXS_VARBIN   			8	/* Variable Length Binary Data 		*/
#define	_INXS_DATE			9	/* SQL Date Type			*/
#define	_INXS_TIME			10	/* SQL Time Type			*/

#define	_INXS_ASC			0
#define	_INXS_DESC			1

/*	----------------	*/
/*	DATA TYPE LIMITS	*/
/*	----------------	*/
#define	_INXS_MIN_STRING	' '	
#define	_INXS_MAX_STRING	'Z'	
#define	_INXS_MIN_BINARY	0x0000
#define	_INXS_MAX_BINARY	0x00FF

#define	_INXS_LINK_MIN		0
#define	_INXS_LINK_MAX		1
#define	_INXS_LINK_VALUE	2

/*	-----------------	*/
/*	INXS LIMIT VALUES 	*/
/*	-----------------	*/

#define	_STD_QUERY_LENGTH		2048	/* The standard Query Buffer Size	*/
#define	_STD_KEY_LENGTH			16	/* The standard KEY name Limit      	*/
#define	_PRIMARY_KEY_MAX		1028	/* The maximum Primary Key Size		*/
#define	_ORDER_BY	" ORDER BY "		/* The SQL Order By Clause		*/
#define	_LIMIT_ONE	" LIMIT 1 "		/* The SQL LIMIT clause			*/
#define	_OFFSET   	" OFFSET "		/* The SQL OFFSET Clause		*/
#define	_FOR_UPDATE_NOWAIT " FOR UPDATE NOWAIT"	/* The SQL RECORD LOCK Clause		*/
#define	_ASC " ASC "				/* Ascending Sort Order			*/
#define	_DESC " DESC "				/* Ascending Sort Order			*/
#define	_INXS_PREFIX		"INXS"		/* the SOI buffer name prefix		*/
#define	_INXS_RECORD		"DATA"		/* the SOI buffer name prefix		*/
#define	_INXS_DEFAULT_PRIMARY	"_OID"		/* the name of the standard primary key	*/	
#define	_MIN_VALUE			0x0000	/* For TOP Of Collection Positioning	*/
#define	_MAX_VALUE			0x00FF	/* For END Of Collection Positioning	*/
#define	_INXS_KEY_MAX			256	/* Maximum INXS KEY/COLUMN Name Size	*/
#define	_ABAL_KEY_MAX_STD		16 	/* Maximum ABAL KEY/COLUMN Name Size	*/
#define	_ABAL_KEY_MAX_EXT		50 	/* Maximum ABAL KEY/COLUMN Name Size	*/
#define	_ABAL_JOIN_NAME_SIZE		15	/* size of the name of ABAL join name	*/
#define	_ABAL_STATS_SIZE		23	/* size of the ABAL STAT buffer      	*/
#define	_ABAL_INFO_SIZE			5	/* two words and a byte			*/
#define	_PENDING_CREATE	-1			/* Signals an Index for creation	*/
#define	_PENDING_DELETE	-2			/* Signals an Index for deletion	*/
#define	_INXS_POSIT_VIEW "posit"		/* the suffix used for POSIT views	*/
#define	_INXS_DIFFERENT_TYPE	1		/* field type compare different type	*/
#define	_INXS_DIFFERENT_SIZE	2		/* field type compare different size    */
#define	_INXS_DIFFERENT_EXTRA	3		/* field type compare different extra   */
#define	_INXS_UNLOCKED		0		/* the file has no locks		*/
#define	_INXS_RECORD_LOCK	1		/* the file has a record lock		*/
#define	_INXS_FILE_LOCK		2		/* the file has an exclusive lock	*/
#define	_INXS_LOCK_TIME		5		/* Time to wait to acsquire a lock 	*/
#define	_INXS_LOCK_NAME_SIZE	1024		/* room to work though SQL is 64 limit	*/

#define	_INXS_BKEY		0		/* a binary key				*/
#define	_INXS_LKEY		1		/* left aligned space padded after 	*/
#define	_INXS_RKEY		2		/* right aligned space padded before 	*/
#define	_INXS_NOKEY		3		/* just to keep the old LKEY code	*/

/*	---------------------	*/
/*	INXS RECORD SELECTION 	*/
/*	---------------------	*/
#define	_INXS_LIKE	" LIKE "
#define	_INXS_EQ	" = "
#define	_INXS_NE	" != "
#define	_INXS_LT	" < "
#define	_INXS_LE	" <= "
#define	_INXS_GT	" > "
#define	_INXS_GE	" >= "

#define	_INXS_JOIN_EQ	0x0D
#define	_INXS_JOIN_NE	0x19
#define	_INXS_JOIN_GT	0x05
#define	_INXS_JOIN_GE	0x11
#define	_INXS_JOIN_LT	0x09
#define	_INXS_JOIN_LE	0x15
#define	_INXS_JOIN_BTF	0x1E
#define	_INXS_JOIN_BTL	0x1F

#define	_POSIT_EQ	0x0D
#define	_POSIT_NE	0x19
#define	_POSIT_GT	0x05
#define	_POSIT_GE	0x11
#define	_POSIT_LT	0x09
#define	_POSIT_LE	0x15

#define	_POSIT_BTF    	0x1E
#define	_POSIT_BTL    	0x1F


#define	_INXS_INNER_JOIN	0
#define	_INXS_RIGHT_JOIN	1
#define	_INXS_LEFT_JOIN		2
#define	_INXS_OUTER_JOIN	3


/*	----------------	*/
/*	INXS ERROR CODES	*/
/*	----------------	*/
						/* ---------------------------- */
#define	_SUCCESS			 0	/* No Error Occured 		*/
#define	_ERROR_MEMORY			27	/* A memory allocation failed	*/
#define	_ERROR_SYNTAX			30	/* A value transfer syntax 	*/
#define	_ERROR_MISSING_JOIN		30	/* A JOIN was expected in POSIT	*/
#define	_ERROR_STATEMENT		30	/* A PREPARE STATEMENT failed	*/
#define	_ERROR_FILE_NOT_FOUND		40	/* File not found 		*/
#define	_ERROR_JOIN_NOT_FOUND		40	/* File not found 		*/
#define	_ERROR_FILE_EXISTS		41	/* The file exits already	*/
#define	_ERROR_FILE_LOCKED		44	/* The file is locked by other	*/
#define	_ERROR_RECORD_STRUCTURE		45	/* Bad data or record structure */
#define	_ERROR_DISK_FULL  		46	/* Disk full or create failure	*/
#define	_ERROR_SECURITY   		47	/* TLS Security Parameters 	*/
#define	_ERROR_END_OF_FILE		48	/* End Of File Condition	*/
#define	_ERROR_CONNECTION 		50	/* The connection is incorrect	*/
#define	_ERROR_UNSUPPORTED		56	/* unknown function combination	*/
#define	_ERROR_RECORD_EXISTS		81	/* the record index exists 	*/
#define	_ERROR_LOCK_FAILURE		74	/* the record cannot be locked	*/
#define	_ERROR_RECORD_NOT_FOUND		78	/* the record does not exist	*/
#define	_ERROR_BUFFER_TOO_SMALL		63	/* record size mismatch		*/
#define	_ERROR_TOP_OF_FILE		64	/* Top Of File Condition	*/
#define	_ERROR_END_OF_SELECTION		96	/* End of POSIT UP or DOWN	*/
#define	_ERROR_NOT_ENOUGH_DATA		69	/* Data too small for buffer	*/
						/* ---------------------------- */
#define	_ERROR_KEY_INCORECT		87	/* Incorrect Key expression	*/
#define	_ERROR_KEY_NOT_FOUND		88	/* KEY Not Found          	*/
#define	_ERROR_LINK_NOT_FOUND		89	/* LINK Not Found         	*/
#define	_ERROR_END_OF_VIEW		96	/* End Of View Condition	*/
						/* ---------------------------- */
#define	_ERROR_NOT_ALLOWED		126	/* Not llowed in this context	*/
						/* ---------------------------- */
#define	_ERROR_MYSQL_INIT		150	/* the database init failed 	*/
#define	_ERROR_MYSQL_OPTION		151	/* the database option failed	*/
#define	_ERROR_MYSQL_CONNECT		152	/* the database connect failed	*/
#define	_ERROR_MYSQL_SELECT 		153	/* the database select failed	*/
#define	_ERROR_MYSQL_PING 		154	/* the database ping failed	*/
#define	_ERROR_MYSQL_QUERY 		155	/* the database query failed 	*/
#define	_ERROR_MYSQL_CHARSET		156	/* the database charset failed 	*/
#define	_ERROR_MYSQL_NAMES 		157	/* the database names failed 	*/
#define	_ERROR_MYSQL_MODE  		158	/* the database set mode failed */
#define	_ERROR_RECORD_BCD  		159	/* incorrect BCD Value Ins/Mod	*/
#define	_ERROR_RECORD_DATE 		160	/* incorrect DATE Value Ins/Mod	*/
						/* ---------------------------- */

/*	------------------	*/
/*	INXS CONFIG VALUES	*/
/*	------------------	*/

						/* ----------------------------	*/
#define	_LOCAL_HOST "localhost"			/* database host for connection	*/
#define	_LOCAL_PORT 3306			/* database port for connection	*/
#define	_LOCAL_USER "inxsql"			/* database user for connection */
#define	_LOCAL_PASS "inxsql"			/* database user password	*/
#define	_LOCAL_BASE "inxsql"			/* database name for connection	*/
						/* ----------------------------	*/

/*	-----------------	*/
/*	INXS MEMORY ALLOC	*/
/*	-----------------	*/

void * abalallocate( int nb, char * mptr );
void * aballiberate( void * vptr,char * mptr );
char * allocate_string( char * sptr );

#define	allocate( x ) abalallocate( x, "inxsql" )
#define	liberate( x ) aballiberate( x, "inxsql" )

/*	----------------------	*/
/*	INXS TYPE CASE COMPARE	*/
/*	----------------------	*/
#define inxsql_base_name_compare	strcmp
#define inxsql_joint_name_compare 	strcmp
#define inxsql_table_name_compare 	strcmp
#define inxsql_index_name_compare 	strcmp
#define inxsql_view_name_compare 	strcmp
#define inxsql_field_name_compare	strcasecmp

/*	--------------------	*/
/*	INXS TYPE DEFINITONS	*/
/*	--------------------	*/

struct	xs_convertor
{
	unsigned char *	buffer;
	unsigned int	length;
};

struct	xs_file;
struct	xs_base;

/*	-----------------	*/
/*	x s _ r e c o r d	*/
/*	-----------------	*/
struct	xs_record
{
	struct	xs_record * previous;
	struct	xs_record * next;
	struct	xs_file	  * file;
	char 		  * buffer;
	int		    length;
};

/*	-----------------	*/
/*	 x s _ f i e l d 	*/
/*	-----------------	*/
struct	xs_field
{
	struct xs_field * previous;
	struct xs_field * next;
	struct xs_file  * file;
	char 		* name;
	int		size;
	int		type;
	int		offset;
	int		extra;
};

/*	-----------------	*/
/*	x s _ c l a u s e 	*/
/*	-----------------	*/
struct	xs_clause
{
	struct	xs_clause *  previous;
	struct  xs_clause *  next;
	struct	xs_joint * join;
	struct  xs_field * left;
	struct  xs_field * right;
	int	operator;
};

/*	
 *	----------------------------
 *	Jointure JSON file structure 
 *	----------------------------
	{
		"joint":{
			"name":"name",
			"type":"type",
			"state":"state",
			"clauses":[
				{
					"left":{"file":"file","column":"column"},
					"right":{"file":"file","column":"column"},
					"operator":"opcode"
				}]
			}
	}
*/

/*	---------------		*/
/*	x s _ j o i n t 	*/
/*	---------------		*/
struct	xs_joint
{
	struct	xs_joint * previous;
	struct	xs_joint * next;
	struct	xs_clause * first;
	struct	xs_clause * last;
	struct	xs_base	 * base;
	int		   type;
	char		 * name;
	int		   state;
};

/*	---------------		*/
/*	 x s _ l i n k		*/
/*	---------------		*/
struct	xs_link
{
	struct	xs_link *  previous;
	struct  xs_link *  next;
	struct  xs_field * field;
	int		   type;	/* 0: MIN, 1: MAX, 2: value */
	unsigned char    * value;
};

/*	---------------		*/
/*	x s _ i n d e x 	*/
/*	---------------		*/
struct	xs_index
{
	struct	xs_index * previous;
	struct	xs_index * next;
	struct	xs_link	 * first;
	struct	xs_link  * last;
	struct	xs_file	 * file;
	struct	xs_field * primary;
	char *		   lastkey;
	int		   number;
	char		 * name;
	int		   state;
	int		   reverse;
	long long 	   current;
	long long 	   tof;
	long long 	   eof;
};

/*	-------------	*/
/*	x s _ v i e w 	*/
/*	-------------	*/
struct	xs_view
{
	struct	xs_view * previous;
	struct	xs_view * next;
	struct	xs_base * base;
	char 		* name;
	char 		* query;
	char		  id[64];
	int		  qlen;
};

/*	-------------------------	*/
/*	x s _ c o n n e c t i o n	*/
/*	-------------------------	*/
struct  xs_connection 
{
	struct	xs_file * first;
	struct	xs_file * last;
	struct	xs_base * firstbase;
	struct	xs_base * lastbase;
	struct	xs_base * thisbase;
	struct	xs_base * home;

	void *	handle;		/* database connection handle 	*/
	void *	result;		/* database query result set	*/

#ifdef	_INXSQL_PGSQL
	/* ------------------------------------- */
	/* these are required for row management */
	/* ------------------------------------- */
	int	version;	/* database version		*/
	int	row;		/* database result row count	*/
	unsigned long * sizes;	/* sizes of data in row		*/
#endif

	char  * host;
	char  * user;
	char  * pass;
	char  * base;

	char  *	certificate;
	char  *	privatekey;
	char  *	authority;
	int	tls;
    	int	port;
    	int 	process;
    	int 	time;
    	int	state;
	int	fields;
	int	maxkey;
	int	transaction;
	int	signals;
	int	engine;
};

/*	-------------	*/
/*	x s _ b a s e 	*/
/*	-------------	*/
struct	xs_base
{
	/* base linkage */
	struct xs_base 		* previous;
	struct xs_base 		* next;

	/* host connection */
	struct xs_connection 	* connection;
	struct xs_connection 	* owner;

	/* file management */
	struct xs_file 		* first;
	struct xs_file 		* last;
	struct xs_file 		* current;

	/* join management */
	struct xs_joint 	* firstjoint;
	struct xs_joint 	* lastjoint;
	struct xs_joint 	* currentjoint;
	struct xs_joint 	* join;

	/* view management */
	struct xs_view	 	* firstview;
	struct xs_view		* lastview;
	struct xs_view		* view;

	/* database characteristics */
	int			maxkey;
	int			requests;
	int			blength;
	int			qlength;
	int			flength;
	int			lock;
	char *			name;
};

/*	-------------	*/
/*	x s _ f i l e 	*/
/*	-------------	*/
struct	xs_file
{
	/* file linkage */
	struct xs_file 		* previous;
	struct xs_file 		* next;

	/* host and connection */
	struct xs_connection 	* connection;
	struct xs_base 		* base;

	/* field management */
	struct xs_field 	* first;
	struct xs_field 	* last;
	struct xs_field 	* current;

	/* index management */
	struct xs_index 	* firstindex;
	struct xs_index 	* lastindex;
	struct xs_index 	* currentindex;
	struct xs_index 	* selection;
	struct xs_index 	* orderby;

	/* view management */
	struct xs_view	 	* firstview;
	struct xs_view		* lastview;
	struct xs_view		* view;

	/* query management */
	unsigned char 		* record;

#ifdef	_INXSQL_MYSQL
	/* ---------------------------------------------------- */
	/* these are required for prepared statement management */
	/* ---------------------------------------------------- */
	MYSQL_STMT 		* insert;
	MYSQL_BIND		* inserting;
	MYSQL_STMT 		* update;
	MYSQL_BIND		* updating;
#endif

	/* file characteristics */
	char 			* name;
	int			lock;
	int			state;
	int			type;
	int			maxkey;
	int			datalength;
	int			usage;
	int			qlength;	// max length for query buffer
	int			flength;	// field record length
	int			blength;	// binding mlax record length

	/* primary key management */
	struct xs_field		primary;
	int			align;	/* BKEY, LKEY, RKEY */
	char			lastkey[_PRIMARY_KEY_MAX];

	/* for inter request storage of collect */
	int			storageoffset;
	int			storagelength;
	char			* storage;

};

/*	---------------		*/
/*	INXS VISIBILITY		*/
/*	---------------		*/

#ifndef	public
#define	public
#endif

#ifndef	private
#define	private static
#endif

#ifndef	interface
#define	interface public
#endif

/*	---------------------	*/
/*	INXS PROTO DFINITIONS	*/
/*	---------------------	*/

public	int    inxsql_database_engine(int engine);

public  char * inxsql_allocate_string( char * sptr );
public  char * inxsql_table_name( struct xs_file * fptr );
public  char * inxsql_field_name( char * sptr );
public  char * inxsql_process_filename( char * filename );
public  int    inxsql_close_connection( struct xs_connection * xptr );

public  struct xs_file * inxsql_locate_base_file( struct xs_base * bptr, char * filename, int copy );
public  struct xs_field * inxsql_locate_base_field( struct xs_base * bptr, char * nptr);
public  struct xs_file * inxsql_locate_file( struct xs_connection * xptr, char * filename, int copy );
public  struct xs_file * inxsql_create_file( struct xs_connection * xptr, char * filename, struct xs_base * bptr );
public  struct xs_file * inxsql_liberate_file( struct xs_file * fptr );
public  struct xs_file * inxsql_allocate_file( char * filename );

public  int inxsql_connect_database( struct xs_connection * xptr, int first );
public  int inxsql_release_database( struct xs_connection * xptr );
public  int inxsql_create_database( struct xs_base * bptr );

public  struct xs_base * inxsql_liberate_database( struct xs_base * bptr );
public  struct xs_base * inxsql_allocate_database( struct xs_connection * xptr, char * nptr );

public  struct xs_base * inxsql_remove_base( struct xs_base * bptr);
public  struct xs_base * inxsql_close_base( struct xs_base * bptr);
public  struct xs_base * inxsql_open_base( struct xs_connection * xptr, char * name);
public  int inxsql_list_basefile( struct xs_base * bptr, char * dptr, int dlen, int mode );

public  int inxsql_create_table( struct xs_file * fptr, int keytype );
public  int inxsql_open_table( struct xs_file * fptr );
public  int inxsql_drop_table( struct xs_file * fptr );
public  int inxsql_rename_table( struct xs_file * xptr, char * filename );
public  int inxsql_transfer_tables(struct xs_base * bptr, char * oldbase, char * newbase );

public  int inxsql_insert_record( struct xs_file * fptr, char * iptr, char * dptr, int dlen );
public  int inxsql_update_record( struct xs_file * fptr, char * iptr, char * dptr, int dlen );
public  int inxsql_retrieve_record( struct xs_file * fptr, char * iptr, char * dptr, int dlen, int lock, int * vrl );
public  int inxsql_delete_record( struct xs_file * fptr, char * iptr );
		
public  int inxsql_first_record( struct xs_file * fptr, char * dptr, int dlen, int lock, int * vrl );
public  int inxsql_next_record( struct xs_file * fptr, char * dptr, int dlen, int lock, int * vrl );
public  int inxsql_previous_record( struct xs_file * fptr, char * dptr, int dlen, int lock, int * vrl );
public  int inxsql_last_record( struct xs_file * fptr, char * dptr, int dlen, int lock, int * vrl );
public  int inxsql_next_base_record( struct xs_base * bptr, char * dptr, int dlen, int lock );
public  int inxsql_previous_base_record( struct xs_base * bptr, char * dptr, int dlen, int lock );

public  int inxsql_count_file_records( struct xs_file * fptr, char * qptr, int qlen, int uni, int seq, int * response );
public  int inxsql_collect_file_records( struct xs_file * fptr, char * qptr, int qlen, int last, int uni, int seq, int * response );
public	int	inxsql_select_file_records(
		struct xs_file * fptr, 
		char * dptr, int dlen, char * kptr, int klen, 
		int * outlen, int * response);
public  int inxsql_position_file_records( struct xs_file * fptr, char * qptr, int qlen, int last, int uni, int seq, int * response );

public  int inxsql_count_base_records( struct xs_base * fptr, char * qptr, int qlen, int uni, int seq, int * response );
public  int inxsql_position_base_records( struct xs_base * fptr, char * qptr, int qlen, int last, int uni, int seq, int * response );
public  int inxsql_use_database( struct xs_connection * xptr, struct xs_base * bptr );
public  int inxsql_drop_this_database( struct xs_base * bptr );
public  int inxsql_drop_database( struct xs_connection * xptr, char * nptr );

public  int inxsql_file_info( struct xs_file * fptr, char * dptr, int dlen );
public  int inxsql_base_info( struct xs_base * rbtr, char * dptr, int dlen );
public	int inxsql_file_description(struct xs_file * fptr, char * dptr, int dlen );

public  int inxsql_file_lock( struct xs_file * fptr, int lock);
public  int inxsql_base_lock( struct xs_base * rbtr, int lock);

public  int inxsql_file_lock_record( struct xs_file * fptr);
public  int inxsql_file_unlock_record( struct xs_file * fptr);
public  int inxsql_base_lock_record( struct xs_base * bptr);
public  int inxsql_base_unlock_record( struct xs_base * bptr);

public  int inxsql_append_field( struct xs_file * fptr, char * nptr, int length, int type, int extra);
public  int inxsql_rename_field( struct xs_file * fptr, char * oldname, char * newname );
public  int inxsql_list_columns(struct xs_file * fptr, char * dptr, int dlen, int mode );
public  int inxsql_compare_columns( struct xs_field * lptr, struct xs_field * rptr );
public  struct xs_field * inxsql_locate_column( struct xs_file * fptr, char * nptr );

public  int inxsql_field_size(struct xs_field * cptr);
public  int inxsql_field_bsize(struct xs_field * cptr);
public  int inxsql_field_qsize(struct xs_field * cptr);

public  char * inxsql_new_field_value( struct xs_field * cptr, int direction );
public  char * inxsql_reset_field_value( struct xs_field * cptr, char * vptr, int vlen, int direction );
public  int inxsql_set_field_value( struct xs_field * cptr, char * query, int offset, unsigned char * dptr, int dlen, int align, int wild );
public  int inxsql_get_field_value( struct xs_field * cptr, char * sptr, int slen, unsigned char * dptr, int dlen );
public  int inxsql_primary_field_value(struct xs_field * cptr, char * buffer, int offset, unsigned char * data, int length, int align);
public  int inxsql_append_query( char * query, int offset, char * sptr );

public  struct xs_field * inxsql_add_field( struct xs_file * fptr, char * nptr, int length, int type, int extra );
public	struct xs_field * inxsql_liberate_field( struct xs_field * cptr );
public  struct xs_field * inxsql_locate_field(struct xs_file * fptr, char * nptr );
public	struct xs_field * inxsql_expression_field( struct xs_file * fptr, char * nptr );
public	struct xs_field * inxsql_copy_field( struct xs_file * fptr, struct xs_field * cptr );

public	int	inxsql_field_count(struct xs_file * fptr);
public 	int	inxsql_append_field_names( char * query, struct xs_field * cptr, int items);
public 	int	inxsql_append_distinct_field_names( char * query, struct xs_field * cptr, int items, struct xs_index * iptr);

#ifdef	_INXSQL_MYSQL
/* ------------------------------------------------ */
/* required for MYSQL prepared statement management */
/* ------------------------------------------------ */
public  MYSQL_BIND * 	inxsql_bind_fields( struct xs_file * fptr, MYSQL_BIND * bptr, char * dptr );
public	int		inxsql_bind_field( struct xs_field * cptr, MYSQL_BIND * bptr, char * dptr );
#endif

public	struct xs_link * inxsql_allocate_link();
public	struct xs_link * inxsql_liberate_link(struct xs_link * lptr);
public	struct xs_link * inxsql_append_link(struct xs_index * iptr, struct xs_field * cptr );
public	struct xs_link * inxsql_locate_link(struct xs_index * iptr, struct xs_field * cptr );
public	struct xs_link * inxsql_unique_link(struct xs_index * iptr, struct xs_field * cptr );
public	struct xs_index * inxsql_resolve_index(struct xs_file * fptr, struct xs_index * iptr);
public	struct xs_index * inxsql_resolve_use_index(struct xs_file * fptr, struct xs_index * iptr);
public	struct	xs_index *	inxsql_copy_index( struct xs_file * fptr, struct xs_index * iptr );

public	struct xs_index * inxsql_allocate_index();
public	struct xs_index * inxsql_liberate_index(struct xs_index * iptr);
public	struct xs_index * inxsql_locate_named_index(struct xs_file * fptr, char * nptr);
public	struct xs_index * inxsql_parse_index_list(struct xs_file * fptr, char * dptr, int dlen, int * error );
public  int inxsql_descriptor_field_name( char * rptr, int rlen, char * sptr, int slen );
public  int inxsql_set_link_value( struct xs_link * lptr, char * query, int offset, int vlen, int reverse);
public  int inxsql_max_field_value( struct  xs_field * cptr, char * query, int offset );
public  int inxsql_min_field_value( struct  xs_field * cptr, char * query, int offset );

public	int inxsql_create_index(struct xs_file * fptr, char * dptr, int dlen, int flag);
public	int inxsql_drop_index(struct xs_file * fptr, char * dptr, int dlen, int flag);
public	int inxsql_update_indexes(struct xs_file * fptr);
public  int inxsql_list_indexes(struct xs_file * fptr, char * dptr, int dlen, int mode );
public	int inxsql_file_qlength(struct xs_file * fptr);

public  int inxsql_list_joins(struct xs_base * bptr, char * dptr, int dlen, int mode );
public	int inxsql_declare_join(struct xs_base * bptr, char * dptr, int dlen);
public	int inxsql_create_join(struct xs_base * bptr, char * dptr, int dlen,int type);
public	int inxsql_delete_join(struct xs_base * bptr, char * name);
public	int inxsql_rename_join(struct xs_base * bptr, char * dptr, int dlen);
public  int inxsql_join_clause( struct xs_base * bptr, char * query, char * dptr, int dlen );
public	int inxsql_base_qlength(struct xs_base * bptr);

public	int 		 inxsql_is_view_name( char * nptr );
public  struct xs_view * inxsql_liberate_view( struct xs_view * vptr );
public  struct xs_view * inxsql_allocate_view( char * nptr );
public	struct xs_view * inxsql_locate_view( struct xs_file * fptr, char * name );
public	struct xs_view * inxsql_resolve_view( struct xs_file * fptr, char * name );
public	struct xs_view * inxsql_locate_base_view( struct xs_base * fptr, char * name );
public	struct xs_view * inxsql_resolve_base_view( struct xs_base * fptr, char * name );
public  int inxsql_drop_file_view(struct xs_file * fptr );
public  int inxsql_drop_base_view(struct xs_base * bptr );
public  int inxsql_rename_database( struct xs_base * bptr, char * nptr );

public	unsigned long *	inxsql_fetch_lengths(struct xs_connection * xptr);
public	int	inxsql_num_fields(struct xs_connection * xptr);
public	int	inxsql_num_rows(struct xs_connection * xptr);
public	void *	inxsql_fetch_row(struct xs_connection * xptr);

public	void *	inxsql_store_result(struct xs_connection * xptr);
public	void inxsql_free_result(struct xs_connection * xptr);
public  int inxsql_query( struct xs_connection * xptr, char * query, int length);
public  int inxsql_standard_query(struct xs_connection * xptr, char * query, int length, int failure );
public  int inxsql_liberate_storage(struct xs_file * fptr);
public  int inxsql_allocate_storage(struct xs_file * fptr, int length);

public  int     inxsql_buffer_too_small(void * vptr);
public  int     inxsql_connection_failure(void * vptr);

public  struct 	xs_connection * inxsql_security_credentials( struct  xs_connection * zptr, int mode );
public  int     inxsql_commit_transaction( struct xs_connection * xptr );
public  int     inxsql_start_transaction( struct xs_connection * xptr );
public	void	inxsql_signal_protection();
public	int	inxsql_engine();

	/* --------- */
#endif	/* _inxsql_h */
	/* --------- */

