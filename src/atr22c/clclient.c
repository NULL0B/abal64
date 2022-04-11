/*
	Desc : clClient.c  		Check License - Client stubb
	Proj : Visual Abal
	Copyright (c) 1996 Amenesik / Sologic  

	Check licenses services.

		Control access to software components.

		Services offered by client "stub".
		-	Included by final client application


	Modifications list :
	20/February/1998	JPH File creation.

*/

#include <windows.h>
#include "clClient.h"

#include "clClient.cg"




clError clFreeResource 
		(
		IN		clHandle			RequestHandle
		)
	{
	return clServerFreeResource (RequestHandle);
	}


clError clReNewResource 
		(
		IN		clRequestPtr		Request,
		IN		clHandle				RequestHandle,
		OUT	ctByteStr			PasswordBuffer,
		INOUT	ct2BytesPtr			PasswordLength		
		)
	{
	return clServerReNewResource 
		(
		Request, 
		RequestHandle, 
		PasswordBuffer, 
		PasswordLength
		);
	}


clError clGetBSAInformation 
		(
		IN		clHandle					RequestHandle,
		OUT	clBSAInformationPtr	BSAInformation
		)
	{
	clError Result = CL_BAD_PARAMETER_ERROR;
	
	if (BSAInformation)
		{
		BSAInformation->SizeOf = sizeof(clBSAInformation);
		
		Result = clServerGetBSAInformation
			(
			RequestHandle, 
			BSAInformation
			);
		}
	return Result;
	}


clError clNewResource 
		(
		IN		clRequestPtr	Request,
		OUT	clHandlePtr		RequestHandle,
		OUT	ctByteStr		PasswordBuffer,
		INOUT	ct2BytesPtr		PasswordLength		
		)
	{
	return clServerNewResource 
		(
		Request, 
		RequestHandle, 
		PasswordBuffer, 
		PasswordLength
		);
	}
