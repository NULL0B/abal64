#ifndef	_exmasql_ch
#define	_exmasql_h

EX_FILE_HANDLE	sql_open( BPTR filename, EXAWORD options );
EXAWORD	sql_close( EX_FILE_HANDLE handle );
EXAWORD	sql_select(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );
EXAWORD	sql_prepare(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );
EXAWORD	sql_fetch(EX_FILE_HANDLE handle);
EXAWORD	sql_get_int8(EX_FILE_HANDLE handle,BPTR buffer);
EXAWORD	sql_get_int16(EX_FILE_HANDLE handle,BPTR buffer);
EXAWORD	sql_get_int32(EX_FILE_HANDLE handle,BPTR buffer);
EXAWORD	sql_get_bcd(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );
EXAWORD	sql_get_string(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );
EXAWORD	sql_exec(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );
EXAWORD	sql_key_type(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );
EXAWORD	sql_link_name(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );
EXAWORD	sql_file_user(EX_FILE_HANDLE handle,BPTR buffer,EXAWORD buflen );

#endif	/* _exmasql_h */
	/* ---------- */


