#include <stdio.h>
#include "exdll.h"
#include "exsing.h"

struct	sing_context	SingForm = { 0,0,0,0,0,0,0 };

static	int	connect_sing_form( struct abal_program_handle * aph, int option )
{
	if ((SingForm.oncreate = (aph->resolve)(aph,"ONCREATE")) == -1) {
		if (!( option & 2 )) printf("\r\nFailure Resolving Procedure : ONCREATE\r\n");
		if (!( option & 1 )) SingForm.oncreate = __ONCREATE;
		else	return(78);
		}
	if ((SingForm.onshow   = (aph->resolve)(aph,"ONSHOW")) == -1) {
		if (!( option & 2 )) printf("\r\nFailure Resolving Procedure : ONSHOW\r\n");
		if (!( option & 1 )) SingForm.onshow = __ONSHOW;
		else	return(78);
		}
	if ((SingForm.onfocus  = (aph->resolve)(aph,"ONFOCUS")) == -1) {
		if (!( option & 2 )) printf("\r\nFailure Resolving Procedure : ONFOCUS\r\n");
		if (!( option & 1 )) SingForm.onfocus = __ONFOCUS;
		else	return(78);
		}
	if ((SingForm.onevent  = (aph->resolve)(aph,"ONEVENT")) == -1) {
		if (!( option & 2 )) printf("\r\nFailure Resolving Procedure : ONEVENT\r\n");
		if (!( option & 1 )) SingForm.onevent = __ONEVENT;
		else	return(78);
		}
	if ((SingForm.onlose   = (aph->resolve)(aph,"ONLOSEFOCUS")) == -1) {
		if (!( option & 2 )) printf("\r\nFailure Resolving Procedure : ONLOSEFOCUS\r\n");
		if (!( option & 1 )) SingForm.onlose = __ONLOSEFOCUS;
		else	return(78);
		}
	if ((SingForm.onhide   = (aph->resolve)(aph,"ONHIDE")) == -1){
		if (!( option & 2 )) printf("\r\nFailure Resolving Procedure : ONHIDE\r\n");
		if (!( option & 1 )) SingForm.onhide = __ONHIDE;
		else	return(78);
		}
	if ((SingForm.onremove = (aph->resolve)(aph,"ONREMOVE")) == -1) {
		if (!( option & 2 )) printf("\r\nFailure Resolving Procedure : ONREMOVE\r\n");
		if (!( option & 1 )) SingForm.onremove = __ONREMOVE;
		else	return(78);
		}
	return(0);
}

int	main(int argc, char * argv[] )
{
	int	verbose=0;
	int	x;
	int	e,r;
	int	argi;
	char *	aptr;
	struct	abal_program_handle * aph;
	if ( argc == 1 ) {
		printf("\n   Exa Sing Program Tester : Version 1.0.1 ");
//		printf("\n   Provisoire du 15/02/2008 ");
		printf("\n   Copyright (c) 2019 A.P.I. \n\n");
		return(0);
		}
	for (	argi=1; argi < argc; argi++ )  {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'v'	:
					verbose=1;
					continue;
				default		:
					printf("\nSyntax Error : %s \n",aptr);
					continue;
				}
			}
		else	{
			if (!( aph = LoadAbalProgram( aptr, 0 ))) {
				if ( verbose ) printf("\tProgram %s : Failure\n",aptr); 
				}
			else	{

				if ( verbose ) printf("\r\nProgram : %s \r\n",aptr);

				if (!( connect_sing_form( aph, 0 ) )) {
					if ((e = (aph->procedure)(aph,SingForm.oncreate)) != -1 ) {
						(void) (aph->procedure)(aph,SingForm.onshow);
						(void) (aph->procedure)(aph,SingForm.onfocus);
						(void) (aph->procedure)(aph,SingForm.onhide);
						(void) (aph->procedure)(aph,SingForm.onremove);
						}
					}
				if ( verbose ) printf("\tError   : %u \r\n",e); 
				(aph->stop)(aph);
				}
			}
		}
	return(0);
}

