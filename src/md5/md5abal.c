#ifndef	_lodriver_c
#define	_lodriver_c

#include "md5c.c"
#include "md5abal.h"

#ifndef	EXAWORD
#ifdef	VERSION666
#define	EXAWORD unsigned long
#else
#define	EXAWORD unsigned short
#endif
#endif
#ifdef	PROLOGUE
#include "cropzero.c"
#endif

static	BYTE	buffer[1024];
static	BYTE	filename[1024];
static	MD5_CTX	Md5Context;

static	EXAWORD	Md5Init()
{
	MD5Init(&Md5Context);
	return(0);
}


static	EXAWORD	Md5File(BYTE FAR PTR nptr, WORD nlen, WORD type )
{
	int	eofile=0;
	int	i;
	WORD	buflen;
	FILE * h;
	if ( nlen > 1023 )
		return( 30 );
	else	{
		for (i=0; i < nlen; i++ )
			if ((filename[i] = *(nptr+i)) <= ' ')
				break;
		filename[i] = 0;

		}
	if (!(h = fopen( filename,"rb")))
		return( 40 );

	switch ( type ) {
		case	1 :	/* Ascii 	*/
			while ((buflen = fread(buffer,1,1024,h)) > 0) {
				for (i=0,eofile=0; i < buflen; i++ ) {
					if ( *(buffer+i) == 0x001A ) {
						eofile=1;
						buflen = i;
						break;
						}
					}
				if (!( buflen ))
					break;
				else	MD5Update(&Md5Context,buffer,buflen);
				
				if ( eofile )
					break;
				}
			fclose(h);
			return(0);
		case	0 :	/* Binaire 	*/
			while ((buflen = fread(buffer,1,1024,h)) > 0)
				MD5Update(&Md5Context,buffer,buflen);
			fclose(h);
			return(0);
		}
}

static	EXAWORD	Md5String(BYTE FAR PTR nptr, WORD nlen )
{
	WORD	i;
	if ( nlen > 1024 )
		return(30);
	for (i=0; i < nlen; i++)
		buffer[i] = *(nptr+i);
	MD5Update(&Md5Context,buffer,nlen);
	return(0);
}

static	EXAWORD	Md5Result(BYTE FAR PTR nptr, WORD nlen )
{
	WORD	i;
	if ( nlen < 8 )
		return(63);
	else	{
		MD5Final(buffer,&Md5Context);
		for (i=0; i < 16; i++) {
			if ( i < nlen )
				*(nptr+i) = buffer[i];
			else	break;
			}
		return(0);

		}
}

/* DLL Pattern Management */
/* ---------------------- */

static	char 	LaPaterne[16] = { 
	'*','P','R','L','@','I','N','F','O','*',
	'#',3,
	__DRIVER_MAJOR,__DRIVER_MINOR,__DRIVER_INDEX,
	0 };

static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[8];
char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

/* ------------------ */
/* DLL initialisation */
/* ------------------ */
VOID FAR PTR InitRelais()
{ 
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;

	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) 0L;

	desrt.nombre = 7;

#ifdef vms

	desrt.nom[_DRIVER_DLL_MD5INIT]	 	= (BYTE FAR PTR) "_Md5Init";
	desrt.nom[_DRIVER_DLL_MD5FILE]  	= (BYTE FAR PTR) "_Md5File";
	desrt.nom[_DRIVER_DLL_MD5STRING]	= (BYTE FAR PTR) "_Md5String";
	desrt.nom[_DRIVER_DLL_MD5RESULT] 	= (BYTE FAR PTR) "_Md5Result";
	/* ----- */
#else 	/* ! vms */
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;

	desrt.fonction[_DRIVER_DLL_MD5INIT]	= (WORD (FAR PTR)()) Md5Init;
	desrt.fonction[_DRIVER_DLL_MD5FILE]  	= (WORD (FAR PTR)()) Md5File;
	desrt.fonction[_DRIVER_DLL_MD5STRING]  	= (WORD (FAR PTR)()) Md5String;
	desrt.fonction[_DRIVER_DLL_MD5RESULT]  	= (WORD (FAR PTR)()) Md5Result;

#endif /* vms */

	return((VOID FAR PTR) &desrt);

}

/* ---------------------- */
/* Library identification */
/* ---------------------- */
static VOID FAR banniere()
{ 
	printf("\n   MD5 Encryption Library : %s ",__DRIVER_NAME);
	printf("\n   Version %s ",getpatternversion());
	printf("\n   Provisoire du %s ",__DRIVER_DATE);
	printf("\n   Copyright (c) 2000,2006 Amenesik / Sologic \n");
	printf("\n\t %u  %% Md5Init()",_DRIVER_DLL_MD5INIT);
	printf("\n\t %u  %% Md5File(name$,length%)",_DRIVER_DLL_MD5FILE);
	printf("\n\t %u  %% Md5String(sptr$,slen%)",_DRIVER_DLL_MD5STRING);
	printf("\n\t %u  %% Md5Result(rptr$,rlen%)\n",_DRIVER_DLL_MD5RESULT);
	return;
}

#endif	/* _lodriver_c */



