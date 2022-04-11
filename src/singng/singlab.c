#ifndef	_singlab_c
#define	_singlab_c

public void 	export_labels(struct camera3d *cptr)
{
	struct object3d * optr;
	struct  form_control * fptr;
	struct form_item * iptr;
	int		   nl;
	char 	* sptr;
	FILE *export;
	char *fname;
	int separator=0;
	char car_sep;	
	int nbmess=0;
	char message[80];

	fname=allocate(256); strcpy(fname,"expdata");
	if (accept_elabels_parameters(&fname,&separator) == 27)
		return;
	else if (!( fname ))
		return;
	switch (separator) {
		case 0	: car_sep='\t'; break;
		case 1	: car_sep='|';  break;
		case 2	: car_sep=',';	break;
		case 3	: car_sep=';';	break;
		}

	if ((export=fopen(fname,"w")) == NULL) 
		return;

	fprintf(export,"Module%cform%cwidget%cenglish%cfrench%citalien%cspanish%cgerman%cdutch%cportugese%cother",car_sep,car_sep,car_sep,car_sep,car_sep,car_sep,car_sep,car_sep,car_sep,car_sep,'/');
	linefeed(export);

	for (	optr=cptr->first;optr != (struct object3d *) 0;optr = optr->next ) {
		if ((optr->nature ==  __3D_FORM) 
		&& ((fptr = optr->payload) != (struct form_control *) 0)) {
			for (	iptr=fptr->first;
				iptr != (struct form_item *) 0;
				iptr = iptr->next) {
				switch ( (iptr->Contents.style & _FRAME_TYPE ) ) {
					case _OUTSET_FRAME:
					case _INSET_FRAME:
					case _RIDGE_FRAME:
					case _GROOVE_FRAME:
						if (iptr->Contents.align & 0x00FF) 
							goto ecr_fichier;
			
					case 	_BUTTON_FRAME	:
					case	_TAB_FRAME 	:
					case	_PROGRESS_FRAME	:
					case	_FORM_FRAME	:
					case	_SELECT_FRAME:
					case	_SWITCH_FRAME	:
					case	_CHECK_FRAME	:
					case	_RADIO_FRAME	:
					case	_TEXT_FRAME:
					case	_WINDOW_FRAME:
					case	_IMAGE_FRAME:
ecr_fichier:
						fprintf(export,"%s%c%s%c%s",optr->name,car_sep,fptr->loadname,car_sep,iptr->Contents.name);
						set_national_payload(iptr,fptr->natlang);
						for ( nl=0; nl < MAXNATLANG; nl++ ) {
							fprintf(export,"%c",car_sep);
							if ( sptr = iptr->Contents.messages[nl] ) {
								fprintf(export,"%s",sptr);
								}
							}
						get_national_payload(iptr, fptr->natlang);
						nbmess++;
						linefeed(export);
					}
				}
			}
		}

	fclose(export);
	switch (visual_national_language(-1)) { 
		case 1	:
			sprintf(message,"Le fichier est correctement ecrit (%d messages)",nbmess);
			break;

		default	:
			sprintf(message,"The file has been written correctly (%d messages)",nbmess);
			break;
		}
	accept_valid(message,fname);
}
#ifdef	UNIX
char *	xstrchr(char * sptr, int c)
{
	if (!( sptr ))
		return( sptr );
	while ( *sptr ) {
		if ( *sptr == c )
			break;
		else	sptr++;
		}
	if (!( *sptr ))
		return((char *) 0);
	else	return(sptr);
}
#endif	
char *lsuiv(char **plig,char car_sep)
{

	if (strchr(*plig,car_sep) != NULL) {
		*strchr(*plig,car_sep)=0;
		*plig += strlen(*plig)+1;
		}
	else	*plig+=strlen(*plig);
	return(*plig);	
}

public void 	import_labels(struct camera3d *cptr)
{
	struct object3d * optr;
	struct  form_control * fptr;
	struct form_item * iptr,*last_radio,*ptr_radio=NULL;
	int		   nl;
	char 	* sptr;
	FILE *import=NULL;
	char *fname;
	int separator=0;
	char car_sep;
	char ligne[2500];
	char *object,*form,*widget,*lang[MAXNATLANG],*plig;
	int nblib=0;
	char message[80];

	fname=allocate(256);
	strcpy(fname,"expdata");
	while (import==NULL) {
		if (accept_ilabels_parameters(&fname,&separator) == 27) 
			return;
		else if (!( fname ))
			return;
		else if ((import=fopen(fname,"r")) == NULL) {
			if ( report_accept_error( "Can't open file for reading", fname ) == 27 ) 
				return;
			}
		}

	switch (separator) {
		case 0	:	car_sep='\t'; 	break;
		case 1	:	car_sep='|';	break;
		case 2	:	car_sep=',';	break;
		case 3	:	car_sep=';';	break;
		}

	fgets(ligne,2499,import);
	while (fgets(ligne,2499,import)) {
		if (strlen(ligne) && (ligne[strlen(ligne)-1]=='\n')) 
			ligne[strlen(ligne)-1]=0;
		if (!strchr(ligne,car_sep)) 
			continue;
		object=ligne;
		plig=ligne;
		form=lsuiv(&plig,car_sep);
		widget=lsuiv(&plig,car_sep);
		for (nl=0;nl<MAXNATLANG;nl++) 
			lang[nl]=lsuiv(&plig,car_sep);
		/* rechercher l'objet */
		for (	optr=cptr->first; 
			(optr != (struct object3d *) 0) && (!string_compare( object, optr->name ));
			optr = optr->next );

		if ((optr != NULL) && ((fptr=optr->payload) != NULL)) {
			for (	iptr=fptr->first;
				(iptr != (struct form_item *) 0) && (!string_compare(widget,iptr->Contents.name));
				iptr = iptr->next);
			if ((iptr != NULL) 
			&& ((iptr->Contents.style & _FRAME_TYPE) == _RADIO_FRAME)) {
				if (ptr_radio != iptr)
					ptr_radio=iptr;
				else	{
					for (	iptr=last_radio->next;
						(iptr != (struct form_item *) 0) && (!string_compare(widget,iptr->Contents.name));
						iptr = iptr->next);
					}
				last_radio=iptr;
				}
			if (iptr != NULL) {	
				set_national_payload(iptr,fptr->natlang);
				for ( nl=0; nl < MAXNATLANG; nl++ ) {
					if ((!lang[nl][0]) && (iptr->Contents.messages[nl]==NULL)) 
						lang[nl]=NULL;
					if (!string_compare(lang[nl],iptr->Contents.messages[nl])) {
						liberate(iptr->Contents.messages[nl]);
						if (lang[nl])
							iptr->Contents.messages[nl]=allocate_string(lang[nl]);
						else	iptr->Contents.messages[nl]=NULL;
						nblib++;
						form_is_outofdate(fptr);
						}
					}
				get_national_payload(iptr, fptr->natlang);
				}
			}
		}

	fclose(import);
	switch (visual_national_language(-1)) {
		case 1	:
			sprintf(message,"Traitement termine (%d messages modifies)",nblib);
			break;

		default	:
			sprintf(message,"File correctly read (%d messages updated)",nblib);
			break;
		}
	accept_valid(message,fname);
}

#endif	/* _singlab_c */
	/* ---------- */


