/* 	----------------------------------	*/
/*	N o d e F o r m . c			*/
/* 	----------------------------------	*/
/*	Node JS and Angular JS Forms Model 	*/
/*	Generator tool for SING production	*/
/* 	----------------------------------	*/
/*	Copyright (c) 2016 IJM Amenesik		*/
/* 	----------------------------------	*/

#ifndef _nodeform_c
#define _nodeform_c

	
public  void    export_node_form( FILE * h, int webagent, char * soaphost, int restriction, int contextual, int autotrad, char * prodname )
{
        FILE                    *hh;
        int                     withstyle=0;
        char                    * eptr;
        char                    * nptr;
        char                    * pptr;
        char                    * fnptr;
        struct  form_control    * fptr;
        struct  forms_method    * mptr;
        struct  form_item       * iptr;
        struct  form_item       * wptr;
        FILE                    * hptr;
        int     i;
        int     isoverlay;


        if (!( fptr = Context.Form ))
                return;
        else if (!( fptr->identifier ))
                return;
        else if (!( nptr = allocate_string( fptr->identifier )))
                return;
        else if (!( pptr = enforce_extension( pptr, NODE_EXTENSION )))
                return;

	fprintf(h,"<html ng-app>\n");	
	fprintf(h,"<head><title>%s</title></head>\n",nptr);
	fprintf(h,"<body>\n");	
	fprintf(h,"<input ng-model=\"name\"> Hello {{ name }}\n");
	fprintf(h,"<script src=\"https://ajax.googleapis.com/ajax/libs/angularjs/1.2.25/angular.min.js\"></script>\n");
	fprintf(h,"</body>\n");	
	fprintf(h,"</html>\n");	

}


	/* ----------- */
#endif 	/* _nodeform_c */
	/* ----------- */
