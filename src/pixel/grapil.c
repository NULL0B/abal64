#ifndef GRAPIL_C
#define GRAPIL_C

/*	-----------------------------------------------------------	*/
/*									*/
/*	What	:	GRAPIL.C					*/
/*	When	:	18/09/2002					*/
/*	Who	:	IJMarshall					*/
/*	Why	:	Provides the Graphics Image Library		*/
/*			functions provided by the Twin 2.4		*/
/*			system graphics kernal in MF for USEIT		*/
/*									*/
/*	-----------------------------------------------------------	*/

#include <stdio.h>

#define ALSMID "grapil"
#include "allocate.h"
#include "sysimage.h"
#include "stdimage.h"
#include "stdfont.h"

int LoadImage(char * filename, int forceload, struct standard_image ** iptrptr )
{
	if (!(*iptrptr = local_image_loader( filename )))
		return(40);
	else	{
		return(0);
		}
}

struct standard_image * CloneImage(struct standard_image * iptr)
{
	if ( iptr ) {
		iptr->users++;
		}
	return( iptr );
}

int DropImage(struct standard_image * iptr)
{
	if ( iptr ) {
		if ( iptr->users  )
			iptr->users--;
		if (!( iptr->users )) {
			iptr = local_drop_image( iptr );
			}
		}
	return(0);
}

int LoadFontM(char * filename, unsigned char ForceLoad, char** result)
{
	FILE	* handle;
	int	fs;
	int	status=0;
	int	l;
	char *	bptr;
	char	fonthead[256];
	if (!(handle = fopen(sysfilename(filename),"rb")))
		return(40);
	else if ( fread(fonthead,256,1,handle) != 1) {
		fclose(handle);
		return(48);
		}
	else	{
		fs = getw((fonthead+_FMF_SIZE));
#ifdef	UNIX
		l = fs;
#else
		l = (fs / 256);
		if ( fs % 256 ) l++;
		l *= 256;
#endif
		if (!(bptr = allocate((l + 256) ))) {
			fclose(handle);
			return(27);
			}
		memcpy(bptr,fonthead,256);
		if ( fread((bptr+256),l-256,1,handle) != 1) {
			fclose(handle);
			bptr = liberate( bptr );
			return( 53 );
			}
		fclose(handle);
		*result = bptr;
		return( 0 );
		}

}

int DropFont(void * pFont)
{
	/* Font Release is Automatic in the Font Managent Layer */
	/* So we must do absolutly nothing 			*/
	return(0);
}

#endif









