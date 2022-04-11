#ifndef __CLTYPE_H__
#define __CLTYPE_H__

/*
	Desc : clType.h			Check Licence - Type definition
	Proj : Visual Abal
	Copyright (c) 1994-97 Amenesik / Sologic  

	XXX

	Modifications list :
	23 fev 1998		JPH	File creation
*/


#define	CL_HANDLE	CT_EXPORT_FUNCTION(clHandle)
#define	CL_ERROR		CT_EXPORT_FUNCTION(clError)
#define	CL_VOID		CT_EXPORT_FUNCTION(void)
			
			
typedef	ct4Bytes		clHandle;
typedef	clHandle		CT_FAR * clHandlePtr;
typedef	ct2Bytes		clError;
			
			
#define	CL_NO_ERROR									(0)
#define	CL_INVALID_HANDLE_ERROR					(1)
#define	CL_LICENSE_HOLDER_NOT_FOUND_ERROR	(2)
#define	CL_INVALID_BSA_ERROR						(3)
#define	CL_AUTORIZATION_NOT_FOUND_ERROR		(4)
#define	CL_PASS_LAST_DATE_ERROR					(5)
#define	CL_PASS_FIRST_DATE_ERROR				(6)
#define	CL_REMOTE_ACCESS_ERROR					(7)
#define	CL_BEYOND_AVAILABLE_RESOURCE_ERROR	(8)
#define	CL_BAD_PARAMETER_ERROR					(9)
#define	CL_INTERNAL_ERROR							(10)
#define	CL_INVALID_HOLDER_ACTION_ERROR		(11)
#define	CL_INVALID_CRC_ERROR						(12)

// ---------------------------------------- Types
typedef long int clResource;

typedef char clDate [8+1];				// 19991124
typedef char clFileName [127+1];
typedef char clPath [255+1];
typedef clPath CT_FAR * clPathPtr;
typedef char clClientPW[500+1];

													/*ex: 123456789 123456789 123456789 */
typedef char clCompanyName[30+1];		/*ex: Amenesik / Sologic   */
typedef char clProductName[30+1];  		/*ex: June alpha */
typedef char clProductVersion[10+1]; 	/*ex: 1.001a */

typedef char clRequestId[30+1];			/*ex: IdraEdition, JunePainter */

typedef ct4Bytes clUserHandle;		/* identifies current value of UH1, UH2 or UH3 */

/* -------------------------------------------------- clLicenceHolderId */

typedef struct clLicenseHolderIdStruct clLicenseHolderId;
typedef clLicenseHolderId CT_FAR * clLicenseHolderIdPtr;
struct zzclLicenseHolderIdStruct 
	{
	ct4Bytes						SizeOf;
	clPath						HolderFile;		/* ex. MyTotoLicenseHolder.dll */
	};

/* -------------------------------------------------- clProductId */

typedef struct clProductIdStruct clProductId;
typedef clProductId CT_FAR * clProductIdPtr;
struct clProductIdStruct 
	{
	// Describes a product
	clCompanyName			Company;
	clProductName			Product;
	clProductVersion		ProductVersion;
	};


/* -------------------------------------------------- clResourceSet */

typedef struct clResourceSetStruct clResourceSet;
typedef clResourceSet CT_FAR * clResourceSetPtr;
struct clResourceSetStruct 
	{
	clResource				User;
	clResource				Process;
	clResource				Thread;
	clResource				UH1;
	clResource				UH2;
	clResource				UH3;
	};

/* -------------------------------------------------- clResourceSupply */

typedef struct clResourceSupplyStruct clResourceSupply;
typedef clResourceSupply CT_FAR * clResourceSupplyPtr;
struct clResourceSupplyStruct 
	{
	clResourceSet			ForEachMachine;
	clResourceSet			ForEachUser;
	clResourceSet			ForEachProcess;
	clResourceSet			ForEachThread;
	clResourceSet			ForEachUH1;
	clResourceSet			ForEachUH2;
	clResourceSet			AccumulatedMax;
	};



/* ================================================== Client ========== */

/* -------------------------------------------------- clUserHandleSet */

typedef struct clUserHandleSetStruct clUserHandleSet;
typedef clUserHandleSet CT_FAR * clUserHandleSetPtr;
struct clUserHandleSetStruct 
	{
	clUserHandle			UH1;
	clUserHandle			UH2;
	clUserHandle			UH3;	
	};


/* -------------------------------------------------- clRequest */

typedef struct clRequestStruct clRequest;
typedef clRequest CT_FAR * clRequestPtr;
struct clRequestStruct 
	{
	ct4Bytes					SizeOf;
	ct4Bytes					CRC;
	ctConstStr				HolderFile;			/* Who's holder. Ex. MyTotoLicenseHolder.dll */
	clRequestId				RequestId;			/* What I want */
	clUserHandleSet		UserHandleState;	/* UH1,UH2,UH3 */
	clResourceSet			RequiredResource;	/* How much I want */
	};


/* ================================================== Server ========== */



/* ================================================== LicHolder ========== */

/*
	Contains:
		-	BSA identification		Authentifiate the product's owner
		-	{ Autorisation }			Describe a particular autorisation (encrypted with BSA ID)
		
*/

/* -------------------------------------------------- clAutorization */

typedef struct clAutorizationStruct clAutorization;
typedef clAutorization CT_FAR * clAutorizationPtr;
struct clAutorizationStruct 
	{
	// Describe an autorisation
	ct4Bytes					SizeOf;
	ct4Bytes					CRC;
	clRequestId				RequestId;
	clProductId				ProductId;		
	clResourceSupply		AllowedResource;
	clDate					FirstValidDay;
	clDate					LastValidDay;
	long						MaxValidDay;
	clClientPW				ClientPW;
	};


/* -------------------------------------------------- clBSAInformation */

// See original values in 'aw_syst.h'
typedef ctChar clSerialNumber[(4*5)+3+1];			// xxxxx-xxxxx-xxxxx-xxxxx
typedef ctChar clBSAName[48+1];
typedef ctByte clProductCode[5];
typedef ctByte clProductCode[5];

typedef struct clBSAInformationStruct clBSAInformation;
typedef clBSAInformation CT_FAR * clBSAInformationPtr;
struct clBSAInformationStruct 
	{
	// Describe an user (info from BSA file)
	ct4Bytes					SizeOf;
	ct4Bytes					CRC;

	ct2Bytes					Version;

	clSerialNumber			SerialNumber;
	clBSAName				UserName;
	clBSAName				FirmName;
	clProductCode			ProductCode; // ??
	};


#endif
