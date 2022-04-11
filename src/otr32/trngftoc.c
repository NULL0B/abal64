#ifndef	_TRNGFTOC_C
#define	_TRNGFTOC_C

PUBLIC 	WORD	ngf_to_c( i )
	WORD	i;
{
	WORD	tcode;

	switch ((tcode = GetTcodeByte( i++ ))) {

		/*	Codes des fonctions Standardes		*/
		/*	------------------------------		*/

		case 	_NGF_CFILE 		: /* 0x0000 */
		case 	_NGF_DFILE 		: /* 0x0001 */
		case 	_NGF_RENAME		: /* 0x0002 */
		case 	_NGF_OPEN		: /* 0x0003 */
		case 	_NGF_CLOSE		: /* 0x0004 */
		case 	_NGF_READ		: /* 0x0005 */
		case 	_NGF_WRITE		: /* 0x0006 */

		/*	Codes des fonctions I.S.A.M		*/
		/*	---------------------------		*/

		case 	_NGF_INSERT		: /* 0x0007 */
		case 	_NGF_MODIFY		: /* 0x0008 */
		case 	_NGF_DELETE		: /* 0x0009 */
		case 	_NGF_SEARCH		: /* 0x000A */
		case 	_NGF_DOWN		: /* 0x000B */
		case 	_NGF_UP  		: /* 0x000C */
		case 	_NGF_ATB		: /* 0x000D */
		case 	_NGF_BACKSPACE		: /* 0x000E */
		case 	_NGF_EXTEND		: /* 0x000F */
		case 	_NGF_ASSIGN		: /* 0x0010 */
		case 	_NGF_LOAD		: /* 0x0011 */
		case 	_NGF_XCRI		: /* 0x0012 */
		case 	_NGF_CHAIN		: /* 0x0013 */

		/*	Codes des fonctions Multicritere	*/
		/*	--------------------------------	*/

		case 	_NGF_KEY		: /* 0x0014 */
		case 	_NGF_CKEY		: /* 0x0015 */
		case 	_NGF_RKEY		: /* 0x0016 */
		case 	_NGF_FKEY		: /* 0x0017 */
		case 	_NGF_NKEY		: /* 0x0018 */
		case 	_NGF_LKEY		: /* 0x0019 */
		case 	_NGF_LINK		: /* 0x001A */
		case 	_NGF_CLINK		: /* 0x001B */
		case 	_NGF_LLINK		: /* 0x001C */
		case 	_NGF_POSIT		: /* 0x001D */
		case 	_NGF_COUNT		: /* 0x001E */
		case 	_NGF_STATS		: /* 0x001F */

		/*	Codes des fonctions Base de donnees	*/
		/*	-----------------------------------	*/

		case 	_NGF_RECORD		: /* 0x0020 */
		case 	_NGF_JOIN		: /* 0x0021 */
		case 	_NGF_CJOIN		: /* 0x0022 */
		case 	_NGF_DJOIN		: /* 0x0023 */
		case 	_NGF_RJOIN		: /* 0x0024 */
		case 	_NGF_LJOIN		: /* 0x0025 */
		case 	_NGF_LFILE		: /* 0x0026 */


		/*	Recherche catalogue Volume	*/
		/*	--------------------------	*/

		case 	_NGF_FIND		: /* 0x0027 */


		/*	Dump of current executer core	*/
		/*	-----------------------------	*/
		case 	_NGF_FILE		: /* 0x0028 */

		/* 	Return Assign Infos		*/
		/*	-------------------		*/
		case 	_NGF_NAME		: /* 0x0029 */

			break;

		default		 : 
			/* All other codes cause Failure */
			/* ----------------------------- */
			return(0);


		}
	return(i);
}

#endif	/* _TRNGFTOC_C */
	/* ----------- */




