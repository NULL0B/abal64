

EXBPTR	GetCwd( resptr , reslen )
EXBPTR	rsptr;
int	reslen;
{
	char	PathBuf1[64];
	char	PathBuf2[64];
	UBINAIR	Mode;

	/* Test for Nul Pointer and Allocate if needed */
	/* ------------------------------------------- */
	if ( resptr == (EXBPTR) 0 ) {
		if ((resptr = (EXBPTR) malloc( (USINT) 64)) == (EXBPTR) 0 ) {
			errno = 8;
			return((EXBPTR) 0);
			}
		}
	
	/* Initialise WorkZones */
	/* -------------------- */
	Mode = 1; strcpy(PathBuf1,"."); PathBuf2[0] = (EXABYTE) 0;






}

