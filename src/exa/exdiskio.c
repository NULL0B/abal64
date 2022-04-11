/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXWORK.H  				*/
/*		Date 	:	27/09/1994				*/
/*		Version :	1.4e / 2.1c				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef _EXDISKIO_H
#define _EXDISKIO_C

#define	HARD_SECTOR_SIZE 512
#define	SOFT_SECTOR_SIZE 256

static	EXABYTE	DiskBuffer[HARD_SECTOR_SIZE];

EXAWORD	hardread( handle, sector )
EXAWORD	handle;
EXAWORD	sector;
{
	EXALONG	seekadr;
	seekadr = (((EXALONG) (sector / 2)) * ((EXALONG) HARD_SECTOR_SIZE));
	if ( lseek(handle,seekadr,SEEK_SET) == -1 ) {
		err_val = 53;
		return( SOFTERROR );
		}
	else	return( read( handle,(BPTR) DiskBuffer, HARD_SECTOR_SIZE) );
}

EXAWORD	hardwrite( handle, sector, longueur )
EXAWORD	handle;
EXAWORD	sector;
EXAWORD	longueur;
{

	EXALONG	seekadr;
	seekadr = (((EXALONG) (sector / 2)) * ((EXALONG) HARD_SECTOR_SIZE));
	if ( lseek(handle,seekadr,SEEK_SET) == -1 ) {
		err_val = 53;
		return( SOFTERROR );
		}
	else	return( write( handle,(BPTR) DiskBuffer, longueur ));

}

EXAWORD	diskread( handle, secteur, buffer, longueur )
EXAWORD	handle;
EXAWORD	secteur;
BPTR	buffer;
EXAWORD	longueur;
{
	EXAWORD	transfer=0;
	EXAWORD	hardsize=0;
	if ( secteur & 1 ) {

		if ((hardsize = hardread( handle, secteur )) != HARD_SECTOR_SIZE ) {
			if ( hardsize > 256 )
				err_val = errno = 48;
			else	{
				if ( hardsize < 256 )
					return( 53 );
				else 	return( 48 );
				}
			}

		if ((transfer = ( longueur >= SOFT_SECTOR_SIZE ? ( (hardsize-SOFT_SECTOR_SIZE) < SOFT_SECTOR_SIZE ? hardsize : SOFT_SECTOR_SIZE ) : longueur )) != 0) {
			memcpy( buffer,(BPTR) & DiskBuffer[SOFT_SECTOR_SIZE], transfer );
			buffer += transfer;
			if ( hardsize < HARD_SECTOR_SIZE )
				return( 48 );
			longueur -= transfer;
			}
		secteur++;
		}
	while ( longueur > 0 ) {
		if ((hardsize = hardread( handle, secteur )) != HARD_SECTOR_SIZE ) {
			if ( hardsize > 256 )
				err_val = errno = 48;
			else	{
				if ( hardsize < 256 )
					return( 53 );
				else 	return( 48 );
				}
			}
		if ((transfer = ( longueur >= HARD_SECTOR_SIZE ? ( (hardsize < HARD_SECTOR_SIZE) ? hardsize : HARD_SECTOR_SIZE ) : longueur )) != 0) {
			memcpy( buffer,(BPTR) DiskBuffer, transfer );
			buffer += transfer;
			if ( hardsize < HARD_SECTOR_SIZE )
				return( 48 );
			longueur -= transfer;
			}
		secteur += 2;
		}
	return( 0 );
}

EXAWORD	diskwrite( handle, secteur, buffer, longueur )
EXAWORD	handle;
EXALONG	secteur;
BPTR	buffer;
EXAWORD	longueur;
{
	EXAWORD	hardsize=0;
	EXAWORD	transfer=0;

	if ( secteur & 1 ) {

		if ((hardsize = hardread( handle, secteur )) < SOFT_SECTOR_SIZE )
			return( 53 );

		if ((transfer = ( longueur >= SOFT_SECTOR_SIZE ? ( (hardsize-SOFT_SECTOR_SIZE) < SOFT_SECTOR_SIZE ? hardsize : SOFT_SECTOR_SIZE ) : longueur )) != 0) {
			memcpy( (BPTR) & DiskBuffer[SOFT_SECTOR_SIZE],buffer, transfer );
			buffer += transfer;
			if ( hardsize < HARD_SECTOR_SIZE )
				return( 53 );
			longueur -= transfer;
			}
		
		if ((hardsize = hardwrite( handle, secteur,(transfer+SOFT_SECTOR_SIZE) )) != HARD_SECTOR_SIZE )
			return( 53 );
		secteur++;
		}
	while ( longueur > 0 ) {
		if ((transfer = ( longueur >= HARD_SECTOR_SIZE ? HARD_SECTOR_SIZE : longueur )) != 0) {
			memcpy( (BPTR) DiskBuffer,buffer, transfer );
			buffer += transfer;
			longueur -= transfer;
			}
		else	break;
		if ((hardsize = hardwrite( handle, secteur, transfer )) != transfer )
			return( 53 );
		secteur += 2;
		}
	return( 0 );


}




#endif	/* _EXDISKIO_C */
	/* ----------- */
