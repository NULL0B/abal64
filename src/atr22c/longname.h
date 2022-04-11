#ifndef __LONGNAME_H__
#define __LONGNAME_H__

/*
	Desc : LongName.h  		Long Name Services
	Proj : Visual Abal
	Copyright (c) 1996 Amenesik / Sologic  

	Long names services for Abal translator chain.


		Translate long names into short name using
		a dictionary (database).


	Modifications list :
	11/February/1998	JPH File creation.

*/

#ifndef __CT_CREATE_OO_DLL__
#define __CT_USE_OO_DLL__
#define __CT_TYPE_ONLY__
#endif

#include "ctType.h"

typedef ct4Bytes lnHandle;
typedef ct2Bytes lnError;

#define LN_NO_ERROR								(0)
#define LN_SHORT_NAME_NOT_FOUND_WARNING	(1)
#define LN_INVALID_HANDLE_ERROR				(2)
#define LN_DATABASE_IS_FULL_ERROR			(3)


#ifdef __cplusplus
extern "C" {
#endif

/*
	Opens a LongName Database.
	
	MaxShortNameLength is only used at creation (first use with Write).
*/
#ifndef SKIPOMPARSE
CT_EXPORT_FUNCTION(lnError) 
#endif
lnOpen 
		(
		IN		ctStr				NameBasePath,
		IN		ctBoolean		AllowWrite,
		IN		ct4Bytes			MaxShortNameLength,
		OUT	lnHandle *		Context
		);


#ifndef SKIPOMPARSE
CT_EXPORT_FUNCTION(lnError) 
#endif
lnClose 
		(
		IN		lnHandle			Context
		);



#ifndef SKIPOMPARSE
CT_EXPORT_FUNCTION(lnError) 
#endif
lnShortToLong
		(
		IN		lnHandle			Context,
		IN		ctConstStr		ShortName,
		OUT	ctStr				LongName,
		IN		ct4Bytes			LongNameLength
		);


#ifndef SKIPOMPARSE
CT_EXPORT_FUNCTION(lnError) 
#endif
lnLongToShort
		(
		IN		lnHandle			Context,
		IN		ctConstStr		LongName,
		OUT	ctStr				ShortName,
		IN		ct4Bytes			ShortNameLength
		);



#ifndef SKIPOMPARSE
CT_EXPORT_FUNCTION(lnError) 
#endif
lnIsLong
		(
		IN		lnHandle			Context,
		IN		ctConstStr		ShortName,
		OUT	ctBoolean *		IsResult
		);

#ifdef __cplusplus
	}
#endif

#endif