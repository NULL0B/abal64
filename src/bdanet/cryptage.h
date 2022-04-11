#ifndef	_cryptage_h
#define	_cryptage_h

#define	_encryption 1
#define	_decryption 2

#define	CRYPTAGE	struct _cryptage
#define	CRYPTAGEPTR	CRYPTAGE PTR

CRYPTAGE  	{
	INT	mode;
	INT	rotor;
	INT	key;
	INT	rx;
	INT	ry;
	};

/*	Function prototypes of Cryptage public "member" methods		*/
/*	-------------------------------------------------------		*/
int 	reset_crypt( CRYPTAGEPTR );
int 	start_crypt(CRYPTAGEPTR,char *,int,int );
int 	cryptb(CRYPTAGEPTR,int);
void	crypts(CRYPTAGEPTR,char *);
void	abal_crypt(CRYPTAGEPTR,char *,int);

int 	reset_cryptage( CRYPTAGEPTR eptr );

#endif

