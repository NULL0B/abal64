#ifndef	_GET_DOMAIN_H
#define	_GET_DOMAIN_H

/*	---------------------------------	*/
/*	CHAR FAR * GET_DOMAIN( INT MODE )	*/
/*	---------------------------------	*/
/*	Returns a constant char far pointer	*/
/*	to the current domain name of the 	*/
/*	machine on which the calling program	*/
/*	is running. 				*/
/*						*/
/*	The optional boolean parameter mode 	*/
/*	causes the file to be reloaded each	*/
/*	time the function is called when FALSE	*/
/*	or the result of a previous call to	*/
/*	be optimised and reused if TRUE.	*/
/*						*/
/*	If the file does not exist then a  	*/
/*	pointer to the root . domain will	*/
/*	be returned to the caller.		*/
/*	If the domain name in the file is 	*/
/*	empty or not present then a 		*/
/*	pointer to the root . domain will	*/
/*	also be returned to the caller.		*/
/*						*/
/*	Only the first 512 bytes of the file 	*/
/*	will be read and any preceeding and	*/
/*	trailing white space characters, 	*/
/*		0D, 0A, 09 20			*/
/*	will be silently removed. 		*/
/*						*/
/*	Any other character less than SPACE	*/
/*	will signify the end of the file.	*/
/*						*/
/*	---------------------------------	*/

char far * get_domain(int mode);

#endif	/* _GET_DOMAIN_H */




