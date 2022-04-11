int	MallDex = 0;
int	MallLen[2000];
char *  MallPtr[2000];
extern	char * memcpy();
extern  char * memset();
extern	char askbuf[];
extern	char mathwork[];
extern	char joinwork[];

void	WallopMem( err )
int	err;
{

	switch ( err ) {
		case 0 : x_cprintf("Erreur : Malloc trops d'appels "); break;
		case 1 : x_cprintf("Erreur : Free   Pointer inconnue"); break;
		case 2 : x_cprintf("Erreur : Memory DestP adresse error "); break;
		case 3 : x_cprintf("Erreur : Memory Dest Overflow ! "); break;
		case 4 : x_cprintf("Erreur : Memory Source adresse error "); break;
		case 5 : x_cprintf("Erreur : Memory Source Overflow ! "); break;
		default: x_cprintf("Erreur : unknown "); break;
		}
	return;
}


char * Ijmmalloc( l )
int	l;
{
	char * lptr;
	if ( MallDex == 0 ) {	/* Must Initialise */
		MallPtr[0] = askbuf;
		MallLen[0] = 256;
		MallPtr[1] = mathwork;
		MallPtr[2] = joinwork;
		MallLen[1] = 192;
		MallLen[2] = 19;
		MallDex = 3;
		}
	if ( MallDex >= 2000 ) {
		WallopMem(0);
		return( (char *) 0 );
		}
	MallLen[MallDex] = l;
	lptr = (char *) allocate( l );
	if ( lptr != (char *) 0) { MallPtr[MallDex++] = lptr; }
	return (lptr);	

}

char * Ijmcalloc( l , m )
int	l,m;
{
	char * lptr;
	if ( MallDex >= 2000 ) {
		WallopMem(0);
		return( (char *) 0 );
		}
	MallLen[MallDex] = l;
	lptr = (char *) calloc( l ,m );
	if ( lptr != (char *) 0) { MallPtr[MallDex++] = lptr; }
	return (lptr);	

}

void	Ijmfree( ptr )
char * ptr;
{
	int x;

	for ( x=0; x < MallDex; x++ ) {
		if ( ptr == MallPtr[x] ) { break; }
		}
	if ( x < MallDex ) {	liberate(ptr);  }
	else   {
		WallopMem( 1 );	
		}
	if ( x < MallDex ) {
		MallDex--;
		for ( ; x < MallDex; x++ ) {
			MallPtr[x] = MallPtr[x+1];
			MallLen[x] = MallLen[x+1];
			}

		}
	return;
}

char	* Ijmmemset( dp , wot , xl )
char * dp;
int	wot;
int	xl;
{
	int x;
	for ( x = 0; x < MallDex; x++ ) {
		if ((dp >= MallPtr[x]) && (dp < (MallPtr[x] + MallLen[x]))) {
			if ( (dp + xl) > (MallPtr[x] + MallLen[x])) {
				WallopMem(3);
				}
			break;
			}
		}
	if ( x == MallDex ) { WallopMem(2); }
	return(memset(dp,wot,xl));
}

char	* Ijmmemcpy( dp , sp , xl )
char * dp;
char * sp;
int	xl;
{

	int x;
	for ( x = 0; x < MallDex; x++ ) {
		if ((dp >= MallPtr[x]) && (dp < (MallPtr[x] + MallLen[x]))) {
			if ( (dp + xl) > (MallPtr[x] + MallLen[x])) {
				WallopMem(3);
				}
			break;
			}
		}
	if ( x == MallDex ) { WallopMem(2); }
	for ( x = 0; x < MallDex; x++ ) {
		if ((sp >= MallPtr[x]) && (sp < (MallPtr[x] + MallLen[x]))) {
			if ( (sp + xl) > (MallPtr[x] + MallLen[x])) {
				WallopMem(4);
				}
			break;
			}
		}
	if ( x == MallDex ) { WallopMem(5); }

	return(memcpy(dp,sp,xl));
}

