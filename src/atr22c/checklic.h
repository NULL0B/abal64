#ifndef __CHECKLIC_H__
#define __CHECKLIC_H__

/*
	Desc : CheckLic.h  		Check License
	Proj : Visual Abal
	Copyright (c) 1996 Amenesik / Sologic  


	Modifications list :
	11/February/1998	JPH File creation.


*/

#ifndef __CT_CREATE_OO_DLL__
#ifndef __CT_USE_OO_DLL__
#define __CT_USE_OO_DLL__
#endif
#define __CT_TYPE_ONLY__
#endif

#include "ctType.h"

#ifndef __CLTYPE_H__
#include "clType.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

CL_ERROR clServerNewResource 
		(
		IN		clRequestPtr	Request,
		OUT	clHandlePtr		RequestHandle,
		OUT	ctByteStr		PasswordBuffer,
		INOUT	ct2BytesPtr		PasswordLength		
		);

CL_ERROR clServerFreeResource 
		(
		IN		clHandle			RequestHandle
		);


CL_ERROR clServerReNewResource 
		(
		IN		clRequestPtr		Request,
		IN		clHandle				RequestHandle,
		OUT	ctByteStr			PasswordBuffer,
		INOUT	ct2BytesPtr			PasswordLength		
		);


CL_ERROR clzzzz
		(
		);

CL_ERROR clServerGetBSAInformation
		(
		IN		clHandle					RequestHandle,
		OUT	clBSAInformationPtr	BSAInformation
		);

#ifdef __cplusplus
	}
#endif

#endif