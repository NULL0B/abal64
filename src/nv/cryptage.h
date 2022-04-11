#ifndef	_cryptage_h
#define	_cryptage_h

#define	_encryption 1
#define	_decryption 2

#ifndef	PTR
#define	PTR	*
#endif

#ifndef	INT
#define	INT	int
#endif
#ifndef	BPTR
#define	BPTR	unsigned char *
#endif

#define	CRYPTAGE	struct _cryptage
#define	CRYPTAGEPTR	CRYPTAGE PTR

CRYPTAGE  	{
	INT	mode;
	INT	rotor;
	INT	offset;
	BPTR	key;
	INT	length;
	INT	rx;
	INT	ry;
	};

/*	Function prototypes of Cryptage public "member" methods		*/
/*	-------------------------------------------------------		*/
int 	reset_crypt( CRYPTAGEPTR );
int 	start_crypt(CRYPTAGEPTR,char *,int,int );
int 	cryptb(CRYPTAGEPTR,int);
void	crypts(CRYPTAGEPTR,char *);
void	crypt(CRYPTAGEPTR,char *,int);


#endif

