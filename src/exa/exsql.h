/*==========================================================================*/
/* SQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQL                                          SQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQL              ABAL SQL NATIF              SQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQL                                          SQLSQLSQLSQLSQL */
/* SQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQLSQL */
/*==========================================================================*/

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 * 01/02/12 : (#BG) Creation.
 */

/* --------------------------------------------------------------------------
 *	Definitions
 * --------------------------------------------------------------------------
 */

#define MAX_SQL_BUF				512
//#define HASQLCONN				EX_FILE_HANDLE
//#define HASQLSTMT				EX_FILE_HANDLE

#define GETSERVICEINFO_1		"SERVICE_NAME"
#define GETSERVICEINFO_2		"SERVICE_VERSION"
#define GETSERVICEINFO_3		"DB_VERSION"
#define GETSERVICEINFO_4		"DB_HOSTNAME"
#define GETSERVICEINFO_5		"DB_PROTOCOL_VER"
#define GETSERVICEINFO_6		"DB_NAME"

#define GETSERVICEINFO_1_ID	0x01
#define GETSERVICEINFO_2_ID	0x02
#define GETSERVICEINFO_3_ID	0x04
#define GETSERVICEINFO_4_ID	0x08
#define GETSERVICEINFO_5_ID	0x10
#define GETSERVICEINFO_6_ID	0x11

#define ISOLATION_LEVEL_1		"SERIALIZABLE"
#define ISOLATION_LEVEL_2		"REPEATABLE_READ"
#define ISOLATION_LEVEL_3		"READ_COMMITTED"
#define ISOLATION_LEVEL_4		"READ_UNCOMMITTED"

#define ISOLATION_LEVEL_1_ID	0x01
#define ISOLATION_LEVEL_2_ID	0x02
#define ISOLATION_LEVEL_3_ID	0x03
#define ISOLATION_LEVEL_4_ID	0x04

#define FETCH_FIRST				"FIRST"
#define FETCH_LAST				"LAST"
#define FETCH_NEXT				"NEXT"
#define FETCH_PRIOR				"PRIOR"

#define FETCH_FIRST_ID			0x01
#define FETCH_LAST_ID			0x02
#define FETCH_NEXT_ID			0x03
#define FETCH_PRIOR_ID			0x04

// Types Abal pour le service SQLpgres
#define ABAL_TY_TINYINT			0x02	// VARB_FOUR, VARB_INT8 (#)
#define ABAL_TY_SMALLINT		0x03	// VARB_INT16 (%)
#define ABAL_TY_INTEGER			0x05	// VARB_INT32 (%% ou :)
#define ABAL_TY_LARGEINT		0x06	// VARB_INT64 (:: ou &)
#define ABAL_TY_DECIMAL			0x07	// VARB_BCD
#define ABAL_TY_FIXCHAR			0x08	// VARB_STR ($)
#define ABAL_TY_DATE			0x09	// VARB_STR ($(10))

#define ABAL_MAX_LG_TINYINT	1
#define ABAL_MAX_LG_SMALLINT	2
#define ABAL_MAX_LG_INTEGER	4
#define ABAL_MAX_LG_LARGEINT	8
#define ABAL_MAX_LG_DATE		10

#define MAX_STR_LG_TINYINT		5
#define MAX_STR_LG_SMALLINT	7
#define MAX_STR_LG_INTEGER		12
#define MAX_STR_LG_DECIMAL		25
#define MAX_STR_LG_DATE			10

#define FORMAT_RES_TEXT			0x00
#define FORMAT_RES_BIN			0x01

#define PARAM_IN					0x00
#define PARAM_OUT					0x01


/* --------------------------------------------------------------------------
 *	Codes erreur commun avec la librairie sqlpgres
 * --------------------------------------------------------------------------
 */
#include "ascoderror.h"


/* --------------------------------------------------------------------------
 *	Prototypes
 * --------------------------------------------------------------------------
 */

int sql_connect(void);
int sql_begin(void);
int sql_commit(void);
int sql_rollback(void);
int sql_prepare(void);
int sql_exec(void);
int sql_getrowcol(void);
int sql_getcolname(void);
int sql_getcolname(void);
int sql_fetch(void);
int sql_getfield(void);
int sql_drop(void);
int sql_bindparam(void);
int sql_bindcol(void);
int sql_getsqlerror(void);
int sql_getserviceinfo(void);

static int GetStrParam(BPTR, int, BPTR*);
static int GetHandleStatement(EX_FILE_HANDLE* pHdleStmt);
static int GetParamInfo(BPTR*, int*, int*, int*, int*, int);
static int AddSqlStatement(EX_FILE_HANDLE);
static int LiberateSqlStatement(EX_FILE_HANDLE);
static int LiberateAllSqlStatement(void);

