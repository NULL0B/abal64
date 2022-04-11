#ifndef	_fl_struct_h
#define	_fl_struct_h

/*	-------------------------------------------------------------------------	*/
/*	Constants describing the byte fields of the FF begin communication buffer 	*/
/*	-------------------------------------------------------------------------	*/

#define FL_ver		0	/* version : 1 octet */
#define FL_release	1	/* numero de release : 1 octet */
#define FL_indice	2	/* indice de correction : 1 octet */
#define FL_compatible	3 	/* indice de compatibilite : 1 octet */
#define FL_dedicat	4	/* cle de cryptage pour dedicat */
#define FL_IdPart1	6	/* identifiant appelant */
#define FL_IdPart2	10	/* identifiant appelant (suite) */
#define FL_cnx		14	/* handle de connexion */
#define FL_fill		18 	/* reserve pour extensions : 90 octets */

#endif	/* _fl_struct_h */
	/* ------------ */


