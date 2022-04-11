#ifndef	_singother_c
#define	_singother_h

#include <stdio.h>

/*	--------------------------------------------------------------------------------------------	*/
/*					Compulsory Interface Function					*/
/*	--------------------------------------------------------------------------------------------	*/
/*	initialise_sing_other	:	called from sing startup to allow specialised initialisation 	*/
/*	liberate_sing_other	:	called from sing closure to allow specialised liberation     	*/
/*	export_other_form    	:	called from sing form production for specialised form models 	*/
/*	export_other_page    	:	called from sing page production for specialised page models 	*/
/*	--------------------------------------------------------------------------------------------	*/

/*	--------------------	*/
/*	InitialiseSing Other 	*/
/*	--------------------	*/
int	initialise_sing_other()
{
	return(0);
}

/*	-----------------	*/
/*	Export Other Form	*/
/*	-----------------	*/
int	export_other_form(FILE * handle, struct form_control * fptr)
{
	return(0);
}

/*	-----------------	*/
/*	Export Other Form	*/
/*	-----------------	*/
int	export_other_page(FILE * handle, struct form_control * fptr)
{
	return(0);
}


/*	-------------------	*/
/*	Liberate Sing Other 	*/
/*	-------------------	*/
int	liberate_sing_other()
{
	return(0);
}


#endif	/* _singother_c */
	/* ------------ */








