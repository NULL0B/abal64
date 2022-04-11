#ifndef	__PROJECT_H__
#define	__PROJECT_H__

/*
	Desc : Project.h
	Proj : ald
	Copyright (c) 1993-98 Amenesik / Sologic  

	
	Modifications list :
	17/July/1998  JPH  Restructuration for WAMAKE32
*/

/*
	Local type : includes "local" project header file

	BEWARE - THIS file is NOT shared between projects!!!

*/


#ifndef PRIMITIVE
#define PRIMITIVE
#endif

#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif
#ifndef INOUT
#define INOUT
#endif


#ifndef Xmemcpy
#define Xmemcpy(To, From, Length)	memcpy(To, From, Length)
#endif

#endif	/* __PROJECT_H__ */
