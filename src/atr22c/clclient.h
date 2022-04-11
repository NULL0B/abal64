#ifndef __CLCLIENT_H__
#define __CLCLIENT_H__

/*
	Desc : clClient.h  		Check License - Client header
	Proj : Visual Abal
	Copyright (c) 1996 Amenesik / Sologic  

	Check licenses services.

		Control access to software components.

		Services offered by client "stub".
		-	Included by final client application


	Modifications list :
	20/February/1998	JPH File creation.

*/

#ifndef __CT_CREATE_OO_DLL__
#ifndef __CT_USE_OO_DLL__
#define __CT_USE_OO_DLL__
#endif
#define __CT_TYPE_ONLY__
#endif

#ifndef __CHECKLIC_H__
#include "CheckLic.h"
#endif
		
#ifdef __cplusplus
extern "C" {
#endif

#include "clClient.hg"

clError clNewResource 
		(
		IN		clRequestPtr	Request,
		OUT	clHandlePtr		RequestHandle,
		OUT	ctByteStr		PasswordBuffer,
		INOUT	ct2BytesPtr		PasswordLength		
		);

clError clFreeResource 
		(
		IN		clHandle			RequestHandle
		);


clError clReNewResource 
		(
		IN		clRequestPtr		Request,
		IN		clHandle				RequestHandle,
		OUT	ctByteStr			PasswordBuffer,
		INOUT	ct2BytesPtr			PasswordLength		
		);

clError clGetBSAInformation 
		(
		IN		clHandle					RequestHandle,
		OUT	clBSAInformationPtr	BSAInformation
		);

#ifdef __cplusplus
	}
#endif

#endif