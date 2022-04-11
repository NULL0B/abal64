#ifndef	_stdkbf_c
#define	_stdkbf_c

	/*	------------------------------------------	*/
	/*							*/
	/*		Function Key Management			*/
	/*		-----------------------			*/
	/*							*/
	/*	These functions provide a subsytem will an	*/
	/*	identical behaviour to that provided by the	*/
	/*	standard CICO subsystem under prologue other	*/
	/*	than the limit to the total number of keys 	*/
	/*	that may be activated, due to XKEY limits	*/
	/*							*/
	/*	------------------------------------------	*/

#define	MAX_SPECIAL_KEY		10
#define	MAX_FUNCTION_KEY 	50
#define MAX_KEY_VALUE		64

private	int	special_keys[MAX_SPECIAL_KEY] = {
	/* 1 : RIGHT ARROW */	0x0006,
	/* 2 : LEFT  ARROW */   0x0008,
	/* 3 : UP    ARROW */   0x000B,
	/* 4 : DOWN  ARROW */   0x0005,
	/* 5 : WHO KNOWS   */   0x0000,
	/* 6 : CLEAR       */   0x000C,
	/* 7 to 10 ??????? */   0,0,0,0 };

private	struct	function_key {
	int	length;
	char	value[MAX_KEY_VALUE+1];
	} function_keys[MAX_FUNCTION_KEY];

private	char	FunctionKeyValue[MAX_KEY_VALUE+1];
private	int	FunctionKeyIndex = 0;
private	int	FunctionKeyLength= 0;

public	int	xgr_ikeys()
{
	int	i;

	FunctionKeyIndex = FunctionKeyLength = 0;

	for (i=0; i < MAX_FUNCTION_KEY; i++ ) {
		function_keys[i].length=1;
		function_keys[i].value[0]=(i+128);
		function_keys[i].value[1]=0;
		}
	return(0);
}

public	int	xgr_nbfo()
{
	return( MAX_FUNCTION_KEY );
}


public	int 	xgr_lcfo(
		int numero,
		char *chaine,
		int longueur 	     )
{
	int	i,l;

	if ( gigo_is_replaying() )
		return( local_x_lcfo( numero, chaine, longueur ) );
#ifdef	GIGOXTRACE
	if ( GigoXtrace & 8 )  {
		printf("x_lcfo(%u,%u,%u)\r\n",numero,*chaine,longueur);	
		}
#endif
	/* Ensure not zero key number */
	/* -------------------------- */
	if (!( numero ))
		return( 58 );

	/* Check for Special Programmable keys/cursors etc */
	/* ----------------------------------------------- */
	if (( numero >= 1 )
	&&  ( numero <= MAX_SPECIAL_KEY )) {
		*chaine = special_keys[(numero-1)];
		if ( longueur > 1 )
			*(chaine+1) = 0;
		return(0);
		}

	/* Detect Function Key Numbered from 128 to 128 + MAX */
	/* -------------------------------------------------- */
	else if ( numero >= 128 ) {
		numero -= 128;
		if ( numero > MAX_FUNCTION_KEY )
			return(58);

		l = function_keys[numero].length;

		for (i=0; i < l; i++ ) {
			if ( i < longueur )
				*(chaine + i) = function_keys[numero].value[i];
			else	break;
			}

		if ( i < longueur )
			*(chaine + i) = 0;

		return(0);

		}
	else if ( numero == 172 ) { /* the DEL key */
		return(0);
		}
	else	{
		return(58);
		}
}

public	int 	xgr_prfo(
		int 	numero,
		char 	*chaine,
		int 	longueur   )
{
	int	i,l;

	if ( gigo_is_replaying() )
		return( local_x_prfo( numero, chaine, longueur ) );
#ifdef	GIGOXTRACE
	if ( GigoXtrace & 8 )  {
		printf("x_prfo(%u,%u,%u)\r\n",numero,*chaine,longueur);
		}
#endif

	/* Ensure not zero key number */
	/* -------------------------- */
	if (!( numero ))
		return( 58 );

	/* Check for Special Programmable keys/cursors etc */
	/* ----------------------------------------------- */
	if (( numero >= 1 )
	&&  ( numero <= MAX_SPECIAL_KEY )) {
		special_keys[(numero-1)] = ( *chaine & 0x00FF );
		return(0);
		}

	/* Detect Function Key Numbered from 128 to 128 + MAX */
	/* -------------------------------------------------- */
	else if ( numero >= 128 ) {
		numero -= 128;
		if ( numero > MAX_FUNCTION_KEY )
			return(58);
		l = longueur;
		for (i=0; i < l; i++ ) {
			if ( i < MAX_KEY_VALUE )
				function_keys[numero].value[i] = *(chaine+i);
			else	break;
			}
		function_keys[numero].value[i] = 0;
		function_keys[numero].length   = l;
		return(0);

		}

	else if ( numero == 172 ) { /* the DEL key */
		return(0);
		}
	else	{
		return(58);
		}
}

private	int	xgr_usfo(int value)
{
	if (( value >= 1 ) && ( value <= 10 )) {
		if (!(special_keys[(value-1)]))
			return( -1 );
		else	return(( special_keys[(value-1)] & 0x00FF ));
		}
	else if ((value >= 128) && ( value < (128+MAX_FUNCTION_KEY))) {
		value -= 128;
		if (!(function_keys[value].length ))
			return(-1);
		else 	{
			if (function_keys[value].length > 1 ) {
				strcpy(FunctionKeyValue,function_keys[value].value);
				FunctionKeyIndex=1;
				FunctionKeyLength = function_keys[value].length;
				}
			return((function_keys[value].value[0] & 0x00FF));
			}

		}
	else	return( -1 );
}

	/* --------- */
#endif	/* _stdkbf_c */
	/* --------- */

