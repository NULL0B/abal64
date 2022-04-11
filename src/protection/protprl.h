/*
	Desc : idraprot.h
	Proj : June - Integre
	Copyright (c) 2005 Amenesik / Sologic  

	Implementation de la protection

*/

#ifndef _IDRAPROT_H_
#define _IDRAPROT_H_

// Intégré Wabal
#define C_WABAL_CODE_PRODUIT		30
#define C_WABAL_NOM_PRODUIT		"Wabal3"
#define C_WABAL_VERSION_PRODUIT	"3.2"

// bdanet
#define C_BDANET_CODE_PRODUIT		31
#define C_BDANET_NOM_PRODUIT		"bdanet"
#define C_BDANET_VERSION_PRODUIT	"1.1"

#ifdef __cplusplus
extern "C" {
#endif
int ValideProt(int ProductCode, char* ProductVers, char* ProductName, BOOL bVerbose, int* pNbAccess);
int ValideNbAccessByLaunch(char* ProductName, int NbAccess);
void FreeNbAccess(void);

#ifdef __cplusplus
}
#endif

#endif