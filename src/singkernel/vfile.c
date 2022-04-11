
#ifndef _vfile_c
#define _vfile_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vfile.xml  */
/* Target         : vfile.c  */
/* Identification : 0.0-1100886368-19834.19833 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singfile.h"
#include "singprot.h"
#define en_Auto1502   "Sing : Version 1.0a : Application Data Base Manager"
#define fr_Auto1502   "Sing : Version 1.0a : Gestionaire de Base de Donn‚es Applicatif"
#define it_Auto1502   "Sing : Version 1.0a"
#define es_Auto1502   "Sing : Version 1.0a"
#define de_Auto1502   "Sing : Version 1.0a"
#define nl_Auto1502   "Sing : Version 1.0a"
#define pt_Auto1502   "Sing : Version 1.0a"
#define xx_Auto1502   "Sing : Version 1.0a"
#define en_ListPage   "List"
#define fr_ListPage   "Liste"
#define it_ListPage   "List"
#define es_ListPage   "List"
#define de_ListPage   "List"
#define nl_ListPage   "List"
#define pt_ListPage   "List"
#define xx_ListPage   "List"
#define en_FileList   "Class|Instance|Record|Index"
#define fr_FileList   "Class|Instance|Donn‚es|Indexe"
#define it_FileList   "Class|Instance|Record|Index"
#define es_FileList   "Class|Instance|Record|Index"
#define de_FileList   "Class|Instance|Record|Index"
#define nl_FileList   "Class|Instance|Record|Index"
#define pt_FileList   "Class|Instance|Record|Index"
#define xx_FileList   "Class|Instance|Record|Index"
#define en_Auto1524   "a"
#define en_ScrollBar   ""
#define en_FilePage   "File"
#define fr_FilePage   "Fichier"
#define it_FilePage   "File"
#define es_FilePage   "File"
#define de_FilePage   "File"
#define nl_FilePage   "File"
#define pt_FilePage   "File"
#define xx_FilePage   "File"
#define en_Auto1504   "Class"
#define fr_Auto1504   "Class"
#define it_Auto1504   "Class"
#define es_Auto1504   "Class"
#define de_Auto1504   "Class"
#define nl_Auto1504   "Class"
#define pt_Auto1504   "Class"
#define xx_Auto1504   "Class"
#define en_Auto1505   "Members"
#define fr_Auto1505   "Membres"
#define it_Auto1505   "Primary Index Members"
#define es_Auto1505   "Primary Index Members"
#define de_Auto1505   "Primary Index Members"
#define nl_Auto1505   "Primary Index Members"
#define pt_Auto1505   "Primary Index Members"
#define xx_Auto1505   "Primary Index Members"
#define en_Auto1506   "Size"
#define fr_Auto1506   "Taille"
#define it_Auto1506   "Size"
#define es_Auto1506   "Size"
#define de_Auto1506   "Size"
#define nl_Auto1506   "Size"
#define pt_Auto1506   "Size"
#define xx_Auto1506   "Size"
#define en_ClassName   ""
#define en_Instance   ""
#define en_Filename   ""
#define en_IndexType   "K=|LK=|RK="
#define fr_IndexType   "K=|LK=|RK="
#define it_IndexType   "K=|LK=|RK="
#define es_IndexType   "K=|LK=|RK="
#define de_IndexType   "K=|LK=|RK="
#define nl_IndexType   "K=|LK=|RK="
#define pt_IndexType   "K=|LK=|RK="
#define xx_IndexType   "K=|LK=|RK="
#define en_IndexSize   ""
#define en_Auto1525   "-"
#define en_NbIndex   ""
#define en_Auto1507   "+"
#define fr_Auto1507   "+"
#define it_Auto1507   "+"
#define es_Auto1507   "+"
#define de_Auto1507   "+"
#define nl_Auto1507   "+"
#define pt_Auto1507   "+"
#define xx_Auto1507   "+"
#define en_RecordType   "VD="
#define fr_RecordType   "VD="
#define it_RecordType   "VD="
#define es_RecordType   "VD="
#define de_RecordType   "VD="
#define nl_RecordType   "VD="
#define pt_RecordType   "VD="
#define xx_RecordType   "VD="
#define en_RecordSize   ""
#define en_Auto1509   "-"
#define en_NbData   ""
#define en_Auto1510   "+"
#define fr_Auto1510   "+"
#define it_Auto1510   "+"
#define es_Auto1510   "+"
#define de_Auto1510   "+"
#define nl_Auto1510   "+"
#define pt_Auto1510   "+"
#define xx_Auto1510   "+"
#define en_Accept   "Accept"
#define fr_Accept   "Valider"
#define it_Accept   "Accept"
#define es_Accept   "Accept"
#define de_Accept   "Accept"
#define nl_Accept   "Accept"
#define pt_Accept   "Accept"
#define xx_Accept   "Accept"
#define en_Auto1511   "Filetype"
#define fr_Auto1511   "MŠthode"
#define it_Auto1511   "Format"
#define es_Auto1511   "Format"
#define de_Auto1511   "Format"
#define nl_Auto1511   "Format"
#define pt_Auto1511   "Format"
#define xx_Auto1511   "Format"
#define en_Auto1512   "Align"
#define fr_Auto1512   "Cadr‚"
#define it_Auto1512   "Format"
#define es_Auto1512   "Format"
#define de_Auto1512   "Format"
#define nl_Auto1512   "Format"
#define pt_Auto1512   "Format"
#define xx_Auto1512   "Format"
#define en_Auto1513   "Primary Index"
#define fr_Auto1513   "Indexe Primaire"
#define it_Auto1513   "Primary Index Size"
#define es_Auto1513   "Primary Index Size"
#define de_Auto1513   "Primary Index Size"
#define nl_Auto1513   "Primary Index Size"
#define pt_Auto1513   "Primary Index Size"
#define xx_Auto1513   "Primary Index Size"
#define en_Auto1514   "Data Record"
#define fr_Auto1514   "Enregistrement"
#define it_Auto1514   "Data Record Size"
#define es_Auto1514   "Data Record Size"
#define de_Auto1514   "Data Record Size"
#define nl_Auto1514   "Data Record Size"
#define pt_Auto1514   "Data Record Size"
#define xx_Auto1514   "Data Record Size"
#define en_Auto1515   "Instance"
#define fr_Auto1515   "Instance"
#define it_Auto1515   "Instance"
#define es_Auto1515   "Instance"
#define de_Auto1515   "Instance"
#define nl_Auto1515   "Instance"
#define pt_Auto1515   "Instance"
#define xx_Auto1515   "Instance"
#define en_Auto1516   "Filename"
#define fr_Auto1516   "Fichier"
#define it_Auto1516   "File"
#define es_Auto1516   "File"
#define de_Auto1516   "Filename"
#define nl_Auto1516   "Filename"
#define pt_Auto1516   "Filename"
#define xx_Auto1516   "Filename"
#define en_IndexMembers   "Name|Type|Length|1st|2nd"
#define fr_IndexMembers   "Nom|Type|Longueur|1ere|2eme"
#define it_IndexMembers   "Name|Type|Length|1st|2nd"
#define es_IndexMembers   "Name|Type|Length|1st|2nd"
#define de_IndexMembers   "Name|Type|Length|1st|2nd"
#define nl_IndexMembers   "Name|Type|Length|1st|2nd"
#define pt_IndexMembers   "Name|Type|Length|1st|2nd"
#define xx_IndexMembers   "Name|Type|Length|1st|2nd"
#define en_IndexBar   ""
#define en_DataMembers   "Name|Type|Length|1st|2nd"
#define fr_DataMembers   "Nom|Type|Longueur|1ere|2eme"
#define it_DataMembers   "Name|Type|Length|1st|2nd"
#define es_DataMembers   "Name|Type|Length|1st|2nd"
#define de_DataMembers   "Name|Type|Length|1st|2nd"
#define nl_DataMembers   "Name|Type|Length|1st|2nd"
#define pt_DataMembers   "Name|Type|Length|1st|2nd"
#define xx_DataMembers   "Name|Type|Length|1st|2nd"
#define en_DataBar   ""
#define en_TypeSelect   "byte|word|bcd|string|long"
#define fr_TypeSelect   "byte|word|bcd|string|long"
#define it_TypeSelect   "byte|word|bcd|string|long"
#define es_TypeSelect   "byte|word|bcd|string|long"
#define de_TypeSelect   "byte|word|bcd|string|long"
#define nl_TypeSelect   "byte|word|bcd|string|long"
#define pt_TypeSelect   "byte|word|bcd|string|long"
#define xx_TypeSelect   "byte|word|bcd|string|long"
#define en_MaskPage   "Mask"
#define fr_MaskPage   "Masque"
#define it_MaskPage   "Mask"
#define es_MaskPage   "Mask"
#define de_MaskPage   "Mask"
#define nl_MaskPage   "Mask"
#define pt_MaskPage   "Mask"
#define xx_MaskPage   "Mask"
#define en_Auto1786   "Data Object Form Generation"
#define fr_Auto1786   "Generation de Masque pour Objet de Donn‚es"
#define it_Auto1786   "Data Object Form Generation"
#define es_Auto1786   "Data Object Form Generation"
#define de_Auto1786   "Data Object Form Generation"
#define nl_Auto1786   "Data Object Form Generation"
#define pt_Auto1786   "Data Object Form Generation"
#define xx_Auto1786   "Data Object Form Generation"
#define en_Auto1787   "Filename Stub"
#define fr_Auto1787   "Nom de Fichier"
#define it_Auto1787   "Identifier"
#define es_Auto1787   "Identifier"
#define de_Auto1787   "Identifier"
#define nl_Auto1787   "Identifier"
#define pt_Auto1787   "Identifier"
#define xx_Auto1787   "Identifier"
#define en_Auto1795   "Window Title"
#define fr_Auto1795   "Titre"
#define it_Auto1795   "Title"
#define es_Auto1795   "Title"
#define de_Auto1795   "Title"
#define nl_Auto1795   "Title"
#define pt_Auto1795   "Title"
#define xx_Auto1795   "Title"
#define en_Auto1792   "Nature"
#define fr_Auto1792   "Nature"
#define it_Auto1792   "Nature"
#define es_Auto1792   "Nature"
#define de_Auto1792   "Nature"
#define nl_Auto1792   "Nature"
#define pt_Auto1792   "Nature"
#define xx_Auto1792   "Nature"
#define en_Auto1791   "Production"
#define fr_Auto1791   "Production"
#define it_Auto1791   "Production"
#define es_Auto1791   "Production"
#define de_Auto1791   "Production"
#define nl_Auto1791   "Production"
#define pt_Auto1791   "Production"
#define xx_Auto1791   "Production"
#define en_Auto1869   "Page Items"
#define fr_Auto1869   "Production"
#define it_Auto1869   "Production"
#define es_Auto1869   "Production"
#define de_Auto1869   "Production"
#define nl_Auto1869   "Production"
#define pt_Auto1869   "Production"
#define xx_Auto1869   "Production"
#define en_Identifier   ""
#define en_Title   ""
#define en_Nature   "Forms|Document"
#define fr_Nature   "Forms|Document"
#define it_Nature   "Forms|Document"
#define es_Nature   "Forms|Document"
#define de_Nature   "Forms|Document"
#define nl_Nature   "Forms|Document"
#define pt_Nature   "Forms|Document"
#define xx_Nature   "Forms|Document"
#define en_Language   "Program|Overlay|Module|File"
#define fr_Language   "Forms|Document"
#define it_Language   "Forms|Document"
#define es_Language   "Forms|Document"
#define de_Language   "Forms|Document"
#define nl_Language   "Forms|Document"
#define pt_Language   "Forms|Document"
#define xx_Language   "Forms|Document"
#define en_PageItems   ""
#define en_Auto1794   "Accept"
#define fr_Auto1794   "Valider"
#define it_Auto1794   "Accept"
#define es_Auto1794   "Accept"
#define de_Auto1794   "Accept"
#define nl_Auto1794   "Accept"
#define pt_Auto1794   "Accept"
#define xx_Auto1794   "Accept"
#define en_Progress   ""
static int	vfh[10];

private struct database_editor_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[3+1];
	char * msg_Auto1502[8];
	int	x_Auto1502;
	int	y_Auto1502;
	int	w_Auto1502;
	int	h_Auto1502;
	char * msg_ListPage[8];
	int	trigger_ListPage;
	int	page_number;
	char * msg_FileList[8];
	int	value_FileList;
	int	column_FileList;
	char	buffer_FileList[29][88];
	char * row_FileList;
	char * msg_Auto1524[8];
	int	value_ScrollBar;
	int	limit_ScrollBar;
	int	max_ScrollBar;
	char * msg_FilePage[8];
	int	trigger_FilePage;
	char * msg_Auto1504[8];
	char * msg_Auto1505[8];
	char * msg_Auto1506[8];
	char	buffer_ClassName[42];
	char	buffer_Instance[42];
	char	buffer_Filename[42];
	char * msg_FileType[8];
	int	value_FileType;
	char * msg_IndexType[8];
	int	value_IndexType;
	char	buffer_IndexSize[9];
	char * msg_Auto1525[8];
	int	trigger_Auto1525;
	char	buffer_NbIndex[6];
	char * msg_Auto1507[8];
	int	trigger_Auto1507;
	char * msg_RecordType[8];
	int	trigger_RecordType;
	int	value_RecordType;
	char	buffer_RecordSize[9];
	char * msg_Auto1509[8];
	int	trigger_Auto1509;
	char	buffer_NbData[6];
	char * msg_Auto1510[8];
	int	trigger_Auto1510;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * msg_Auto1511[8];
	char * msg_Auto1512[8];
	char * msg_Auto1513[8];
	char * msg_Auto1514[8];
	char * msg_Auto1515[8];
	char * msg_Auto1516[8];
	char * msg_IndexMembers[8];
	int	value_IndexMembers;
	int	column_IndexMembers;
	char	buffer_IndexMembers[5][87];
	char * row_IndexMembers;
	int	value_IndexBar;
	int	limit_IndexBar;
	int	max_IndexBar;
	char * msg_DataMembers[8];
	int	value_DataMembers;
	int	column_DataMembers;
	char	buffer_DataMembers[17][87];
	char * row_DataMembers;
	int	value_DataBar;
	int	limit_DataBar;
	int	max_DataBar;
	char * msg_TypeSelect[8];
	int	x_TypeSelect;
	int	y_TypeSelect;
	int	w_TypeSelect;
	int	h_TypeSelect;
	int	fg_TypeSelect;
	int	bg_TypeSelect;
	int	fid_TypeSelect;
	int	s_TypeSelect;
	void *	p_TypeSelect;
	int	value_TypeSelect;
	char * msg_MaskPage[8];
	int	trigger_MaskPage;
	char * msg_Auto1786[8];
	char * msg_Auto1787[8];
	char * msg_Auto1795[8];
	char * msg_Auto1792[8];
	char * msg_Auto1791[8];
	char * msg_Auto1869[8];
	char	buffer_Identifier[87];
	char	buffer_Title[87];
	char * msg_Nature[8];
	int	value_Nature;
	char * msg_Language[8];
	int	value_Language;
	char	buffer_PageItems[8];
	char * msg_Auto1794[8];
	int	trigger_Auto1794;
	int	value_Progress;
	int	limit_Progress;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
struct file_control  * allocate_file_control(struct database_editor_context * _Context);
void	liberate_file_control(struct database_editor_context * _Context,struct file_control * fptr);
void	initilise_file_manager(struct database_editor_context * _Context);
void	liberate_file_manager(struct database_editor_context * _Context);
static struct file_control  * locate_file(struct database_editor_context * _Context,int number);
static void	putstring(struct database_editor_context * _Context,char * rptr, int rlen, char * sptr);
static char	 * copystring(struct database_editor_context * _Context,char * sptr, int slen);
void	 * AddFileMember(struct database_editor_context * _Context,char * iptr, char * nptr, char * format,                   char * hptr, char * cptr, int type);
static short	convert_integer(struct database_editor_context * _Context,char * sptr, int slen);
static void	reallocate(struct database_editor_context * _Context,char ** rptr, char * sptr, int slen);
void	 * AddFileClass(struct database_editor_context * _Context,int type, char * cname, char * oname,                      char * fname, char * format);
void	 * AddFileObject(struct database_editor_context * _Context,int type, char * iname, char * fname, char * format,       char * hname);
static void	adjust_members(struct database_editor_context * _Context,int operation);
void	use_data_selector(struct database_editor_context * _Context,char * rptr,int rlen,                                      char * iptr,int ilen,                                      char * nptr, int nlen);
static short	locate_class(struct database_editor_context * _Context,char * nptr, int nlen);
struct data_control  * resolve_class_data(struct database_editor_context * _Context,char * classname);
void	mask_progression(struct database_editor_context * _Context,int value, int max);

/*	--------------------------------------------	*/
/*	a l l o c a t e _ f i l e _ c o n t r o l ()	*/
/*	--------------------------------------------	*/
struct file_control  * allocate_file_control(struct database_editor_context * _Context){
	struct file_control*fptr;
	if(!(fptr=allocate(sizeof(struct file_control))))
	return(fptr);
	fptr->previous=(struct file_control*)0;
	fptr->next=(struct file_control*)0;
	fptr->identity=(char*)0;
	fptr->filename=(char*)0;
	fptr->classname=(char*)0;
	fptr->format=(char*)0;
	fptr->payload=(struct data_control*)0;
	fptr->nature=0;
	fptr->number=0;
	fptr->indextype=(char*)0;
	fptr->recordtype=(char*)0;
	return(fptr);

}

/*	--------------------------------------------	*/
/*	l i b e r a t e _ f i l e _ c o n t r o l ()	*/
/*	--------------------------------------------	*/
void	liberate_file_control(struct database_editor_context * _Context,struct file_control * fptr){
	if(fptr){
	if(fptr->identity)
	liberate(fptr->identity);
	if(fptr->filename)
	liberate(fptr->filename);
	if(fptr->format)
	liberate(fptr->format);
	if(fptr->payload)
	drop_data_control(fptr->payload);
	if(fptr->indextype)
	liberate(fptr->indextype);
	if(fptr->recordtype)
	liberate(fptr->recordtype);
	liberate(fptr);
	}
	return;

}

/*	----------------------------------------------	*/
/*	i n i t i l i s e _ f i l e _ m a n a g e r ()	*/
/*	----------------------------------------------	*/
void	initilise_file_manager(struct database_editor_context * _Context){
	FileManager.first=
	FileManager.current=
	FileManager.last=(struct file_control*)0;
	return;

}

/*	--------------------------------------------	*/
/*	l i b e r a t e _ f i l e _ m a n a g e r ()	*/
/*	--------------------------------------------	*/
void	liberate_file_manager(struct database_editor_context * _Context){
	struct file_control*fptr;
	while((fptr=FileManager.first)!=(struct file_control*)0){
	FileManager.first=fptr->next;
	liberate_file_control(_Context, fptr);
	}
	return;

}

/*	------------------------	*/
/*	l o c a t e _ f i l e ()	*/
/*	------------------------	*/
static struct file_control  * locate_file(struct database_editor_context * _Context,int number){
	struct file_control*fptr;
	struct file_control*xptr;
	for(fptr=FileManager.first;
	fptr!=(struct file_control*)0;
	fptr=fptr->next){
	if(fptr->number==number)
	break;
	else if(fptr->number>number){
	if(!(xptr=allocate_file_control(_Context)))
	return(xptr);
	else{
	xptr->number=number;
	if(!(xptr->previous=fptr->previous))
	FileManager.first=xptr;
	else fptr->previous->next=xptr;
	xptr->next=fptr;
	xptr->payload=analyse_data_control(" ");
	return(xptr);
	}
	}
	}
	if(!(fptr)){
	if(!(fptr=allocate_file_control(_Context)))
	return(fptr);
	else{
	fptr->number=number;
	if(!(fptr->previous=FileManager.last))
	FileManager.last=fptr;
	else fptr->previous->next=fptr;
	if(!(FileManager.first)){
	FileManager.first=fptr;
	FileManager.current=fptr;
	}
	FileManager.last=fptr;
	fptr->payload=analyse_data_control(" ");
	}
	}
	return(fptr);

}

/*	--------------------	*/
/*	p u t s t r i n g ()	*/
/*	--------------------	*/
static void	putstring(struct database_editor_context * _Context,char * rptr, int rlen, char * sptr){
	int i;
	for(i=0;i<rlen;i++){
	if(!(*(sptr+i)))
	break;
	else*(rptr+i)=*(sptr+i);
	}
	for(;i<rlen;i++){*(rptr+i)=' ';}
	return;

}

/*	----------------------	*/
/*	c o p y s t r i n g ()	*/
/*	----------------------	*/
static char	 * copystring(struct database_editor_context * _Context,char * sptr, int slen){
	int i;
	int l;
	char*rptr;
	for(i=0,l=0;i<slen;i++){
	if(!(*(sptr+i)))
	break;
	else if(*(sptr+i)!=' ')
	l=(i+1);
	}
	if(!(l))
	return((char*)0);
	else if(!(rptr=allocate((l+1))))
	return(rptr);
	else{
	for(i=0;i<l;i++)
	*(rptr+i)=*(sptr+i);
	*(rptr+i)=0;
	return(rptr);
	}

}

/*	----------------------------	*/
/*	A d d F i l e M e m b e r ()	*/
/*	----------------------------	*/
void	 * AddFileMember(struct database_editor_context * _Context,char * iptr, char * nptr, char * format,                   char * hptr, char * cptr, int type){
	return(0);

}

/*	--------------------------------	*/
/*	c o n v e r t _ i n t e g e r ()	*/
/*	--------------------------------	*/
static short	convert_integer(struct database_editor_context * _Context,char * sptr, int slen){
	int i,l;
	int c;
	for(l=0,i=0;i<slen;i++){
	if((c=*(sptr+i))==' '){
	if(!(l))
	continue;
	else break;
	}
	else if((c>='0')&&(c<='9'))
	l=((l*10)+(c-'0'));
	}
	return(l);

}

/*	----------------------	*/
/*	r e a l l o c a t e ()	*/
/*	----------------------	*/
static void	reallocate(struct database_editor_context * _Context,char ** rptr, char * sptr, int slen){
	int i;
	int l;
	char*vptr;
	if(*rptr){
	liberate(*rptr);
	*rptr=(char*)0;
	}
	for(i=0;i<slen;i++)
	if(*(sptr+i)!=' ')
	l=(i+1);
	if(l>0){
	if((vptr=allocate((l+1)))!=(char*)0){
	memcpy(vptr,sptr,l);
	*(vptr+l)=0;
	*rptr=vptr;
	}
	}

}

/*	--------------------------	*/
/*	A d d F i l e C l a s s ()	*/
/*	--------------------------	*/
void	 * AddFileClass(struct database_editor_context * _Context,int type, char * cname, char * oname,                      char * fname, char * format){
	int number;
	struct file_control*fptr;
	/*--------------------------------------------*/
	/*Called from the XML DATABASE Application*/
	/*Parser to Add a database file class*/
	/*search for a similar named class*/
	/*--------------------------------------------*/
	if(!(cname))
	return((struct file_control*)0);
	for(fptr=FileManager.first;
	fptr!=(struct file_control*)0;
	fptr=fptr->next){
	if(!(fptr->classname))
	continue;
	else if(strcmp(fptr->classname,cname)==0)
	return(fptr);
	else continue;
	}
	if(!(FileManager.last))
	number=1;
	else number=(FileManager.last->number+1);
	if(!(fptr=locate_file(_Context, number)))
	return(fptr);
	else if(!(fptr->classname=allocate_string(cname)))
	return(fptr);
	else{
	if(oname)
	fptr->identity=allocate_string(oname);
	if(fname)
	fptr->filename=allocate_string(fname);
	if(format)
	fptr->format=allocate_string(format);
	fptr->nature=type;
	fptr->payload=analyse_data_control(fptr->format);
	return(fptr);
	}

}

/*	----------------------------	*/
/*	A d d F i l e O b j e c t ()	*/
/*	----------------------------	*/
void	 * AddFileObject(struct database_editor_context * _Context,int type, char * iname, char * fname, char * format,       char * hname){
	int number;
	char*classname;
	struct file_control*fptr;
	char result[128];
		/*--------------------------------------------*/
	/*Called from*/
	/*c h e c k _ f i l e _ W i d g e t*/
	/*and c h e c k _ W i d g e t*/
	/*--------------------------------------------*/
	if(!(format))return(format);else if(*format=='(')return(format);
	if(!(classname=allocate(strlen(hname)+strlen(iname)+8)))
	return(format);
	else sprintf(classname,"%s_%s",hname,iname);
	sprintf(result,"(%s)",classname);
	/*search for a similar named object*/
	/*---------------------------------*/
	for(fptr=FileManager.first;
	fptr!=(struct file_control*)0;
	fptr=fptr->next){
	if(!(fptr->identity)){
	if(!(fptr->classname))
	continue;
	else if(strcmp(fptr->classname,classname)==0){
	if(!(check_data_format(iname,fptr->payload,format))){
	fptr->identity=allocate_string(iname);
	liberate(classname);
	liberate(format);
	return(allocate_string(result));
	}
	else continue;
	}
	else continue;
	}
	else if(strcmp(fptr->identity,iname)==0){
	if(!(check_data_format(fptr->identity,fptr->payload,format))){
	liberate(classname);
	liberate(format);
	sprintf(result,"(%s)",fptr->classname);
	return(allocate_string(result));
	}
	else continue;
	}
	}
	if(!(FileManager.last))
	number=1;
	else number=(FileManager.last->number+1);
	if(!(fptr=locate_file(_Context, number))){
	liberate(classname);
	return(format);
	}
	else if(!(fptr->identity=allocate_string(iname))){
	liberate(classname);
	return(format);
	}
	else{
	fptr->classname=classname;
	fptr->format=format;
	fptr->nature=type;
	fptr->payload=analyse_data_control(fptr->format);
	return(allocate_string(result));
	}

}

/*	------------------------------	*/
/*	a d j u s t _ m e m b e r s ()	*/
/*	------------------------------	*/
static void	adjust_members(struct database_editor_context * _Context,int operation){
	int i;
	struct data_control*dptr;
	char buffer[64];
	if(!(FileManager.current))
	return;
	else if(!(dptr=FileManager.current->payload))
	return;
	switch(operation){
	case 0:/*decrement index members*/
	if(dptr->indexfields>0){
	if(dptr->name[(dptr->indexfields-1)])
	liberate(dptr->name[(dptr->indexfields-1)]);
	if(dptr->datafields>0){
	for(i=0;i<dptr->datafields;i++){
	dptr->name[(dptr->indexfields-1)+i]=dptr->name[(dptr->indexfields+i)];
	dptr->type[(dptr->indexfields-1)+i]=dptr->type[(dptr->indexfields+i)];
	dptr->width[(dptr->indexfields-1)+i]=dptr->width[(dptr->indexfields+i)];
	dptr->first[(dptr->indexfields-1)+i]=dptr->first[(dptr->indexfields+i)];
	dptr->second[(dptr->indexfields-1)+i]=dptr->second[(dptr->indexfields+i)];
	}
	}
	dptr->indexfields--;
	}
	break;
	case 1:/*increment index members*/
	if(dptr->datafields>0){
	for(i=dptr->datafields;i>0;i--){
	dptr->name[(dptr->indexfields+i)]=dptr->name[(dptr->indexfields+i)-1];
	dptr->type[(dptr->indexfields+i)]=dptr->type[(dptr->indexfields+i)-1];
	dptr->width[(dptr->indexfields+i)]=dptr->width[(dptr->indexfields+i)-1];
	dptr->first[(dptr->indexfields+i)]=dptr->first[(dptr->indexfields+i)-1];
	dptr->second[(dptr->indexfields+i)]=dptr->second[(dptr->indexfields+i)-1];
	}
	}
	dptr->indexfields++;
	sprintf(buffer,"Index%u",dptr->indexfields);
	dptr->name[(dptr->indexfields-1)]=allocate_string(buffer);
	dptr->type[(dptr->indexfields-1)]=
	dptr->width[(dptr->indexfields-1)]=
	dptr->first[(dptr->indexfields-1)]=
	dptr->second[(dptr->indexfields-1)]=0;
	break;
	case 2:/*decrement record members*/
	if(dptr->datafields>0){
	if(dptr->name[(dptr->datafields+dptr->indexfields-1)])
	liberate(dptr->name[(dptr->datafields+dptr->indexfields-1)]);
	dptr->datafields--;
	}
	break;
	case 3:/*increment record members*/
	dptr->datafields++;
	sprintf(buffer,"member%u",dptr->datafields);
	dptr->name[(dptr->datafields+dptr->indexfields-1)]=allocate_string(buffer);
	dptr->type[(dptr->datafields+dptr->indexfields-1)]=
	dptr->width[(dptr->datafields+dptr->indexfields-1)]=
	dptr->first[(dptr->datafields+dptr->indexfields-1)]=
	dptr->second[(dptr->datafields+dptr->indexfields-1)]=0;
	break;
	}
	return;

}

/*	------------------------------------	*/
/*	u s e _ d a t a _ s e l e c t o r ()	*/
/*	------------------------------------	*/
void	use_data_selector(struct database_editor_context * _Context,char * rptr,int rlen,                                      char * iptr,int ilen,                                      char * nptr, int nlen){
	char buffer[256];
	if(*rptr=='(')
	locate_class(_Context, rptr,rlen);
	if(database_editor()!=27){
	if((FileManager.current)
	&&(FileManager.current->classname)){
	if(rlen){
	sprintf(buffer,"(%s)",FileManager.current->classname);
	putstring(_Context, rptr,rlen,buffer);
	}
	if(ilen){
	putstring(_Context, iptr,ilen,FileManager.current->identity);
	}
	if(nlen){
	putstring(_Context, nptr,nlen,FileManager.current->filename);
	}
	}
	}

}

/*	--------------------------	*/
/*	l o c a t e _ c l a s s ()	*/
/*	--------------------------	*/
static short	locate_class(struct database_editor_context * _Context,char * nptr, int nlen){
	int number;
	struct file_control*fptr;
	char cname[129];
	int i;
	if(*nptr=='('){
	nptr++;
	nlen--;
	}
	for(i=0;i<128;i++){
	if(i>=nlen)
	break;
	else if((cname[i]=*(nptr+i))<=' ')
	break;
	else if(cname[i]==')')
	break;
	}
	*(cname+i)=0;
	/*search for a similar named class*/
	/*---------------------------------*/
	for(fptr=FileManager.first;
	fptr!=(struct file_control*)0;
	fptr=fptr->next){
	if(!(fptr->classname))
	continue;
	else if(strcmp(fptr->classname,cname)==0){
	FileManager.current=fptr;
	return(1);
	}
	else continue;
	}
	return(0);

}

/*	--------------------------------------	*/
/*	r e s o l v e _ c l a s s _ d a t a ()	*/
/*	--------------------------------------	*/
struct data_control  * resolve_class_data(struct database_editor_context * _Context,char * classname){
	if(!(classname))
	return((struct data_control*)0);
	else if(!(locate_class(_Context, classname,strlen(classname))))
	return((struct data_control*)0);
	else if(!(FileManager.current))
	return((struct data_control*)0);
	else return(FileManager.current->payload);
	
}

/*	----------------------------------	*/
/*	m a s k _ p r o g r e s s i o n ()	*/
/*	----------------------------------	*/
void	mask_progression(struct database_editor_context * _Context,int value, int max){
	_Context->value_Progress=value;
	_Context->limit_Progress=max;
	visual_freeze();
		visual_progress(_Context->x_Auto1502+270,_Context->y_Auto1502+300,200,30,vfh[1],70,96,_Context->value_Progress,_Context->limit_Progress,0);
;
	visual_thaw(_Context->x_Auto1502+270,_Context->y_Auto1502+300,200,30);
	usleep(50);

}

public	int	database_editor_create(struct database_editor_context **cptr)
{

	int i;
	struct database_editor_context * _Context=(struct database_editor_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct database_editor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=33;
	_Context->page_number=1;
	for (i=0; i < 8; i++)_Context->msg_Auto1502[i]=" ";
	_Context->msg_Auto1502[0]=en_Auto1502;
	_Context->msg_Auto1502[1]=fr_Auto1502;
	_Context->msg_Auto1502[2]=it_Auto1502;
	_Context->msg_Auto1502[3]=es_Auto1502;
	_Context->msg_Auto1502[4]=de_Auto1502;
	_Context->msg_Auto1502[5]=nl_Auto1502;
	_Context->msg_Auto1502[6]=pt_Auto1502;
	_Context->msg_Auto1502[7]=xx_Auto1502;
	_Context->x_Auto1502=0;
	_Context->y_Auto1502=0;
	_Context->w_Auto1502=790;
	_Context->h_Auto1502=590;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_ListPage[i]=" ";
	_Context->msg_ListPage[0]=en_ListPage;
	_Context->msg_ListPage[1]=fr_ListPage;
	_Context->msg_ListPage[2]=it_ListPage;
	_Context->msg_ListPage[3]=es_ListPage;
	_Context->msg_ListPage[4]=de_ListPage;
	_Context->msg_ListPage[5]=nl_ListPage;
	_Context->msg_ListPage[6]=pt_ListPage;
	_Context->msg_ListPage[7]=xx_ListPage;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_FileList[i]=" ";
	_Context->msg_FileList[0]=en_FileList;
	_Context->msg_FileList[1]=fr_FileList;
	_Context->msg_FileList[2]=it_FileList;
	_Context->msg_FileList[3]=es_FileList;
	_Context->msg_FileList[4]=de_FileList;
	_Context->msg_FileList[5]=nl_FileList;
	_Context->msg_FileList[6]=pt_FileList;
	_Context->msg_FileList[7]=xx_FileList;
	if ( 0 > 0 ) { _Context->row_FileList=&_Context->buffer_FileList[0-1][0]; } ;
	for (i=0; i < 8; i++)_Context->msg_Auto1524[i]=" ";
	_Context->msg_Auto1524[0]=en_Auto1524;
	_Context->max_ScrollBar=1;
	_Context->value_ScrollBar=1;
	_Context->limit_ScrollBar=1;
	_Context->limit_ScrollBar=29;
	_Context->value_ScrollBar=0;
	_Context->max_ScrollBar=100;
	for (i=0; i < 8; i++)_Context->msg_FilePage[i]=" ";
	_Context->msg_FilePage[0]=en_FilePage;
	_Context->msg_FilePage[1]=fr_FilePage;
	_Context->msg_FilePage[2]=it_FilePage;
	_Context->msg_FilePage[3]=es_FilePage;
	_Context->msg_FilePage[4]=de_FilePage;
	_Context->msg_FilePage[5]=nl_FilePage;
	_Context->msg_FilePage[6]=pt_FilePage;
	_Context->msg_FilePage[7]=xx_FilePage;
	_Context->focus_pages[2]=5;
	for (i=0; i < 8; i++)_Context->msg_Auto1504[i]=" ";
	_Context->msg_Auto1504[0]=en_Auto1504;
	_Context->msg_Auto1504[1]=fr_Auto1504;
	_Context->msg_Auto1504[2]=it_Auto1504;
	_Context->msg_Auto1504[3]=es_Auto1504;
	_Context->msg_Auto1504[4]=de_Auto1504;
	_Context->msg_Auto1504[5]=nl_Auto1504;
	_Context->msg_Auto1504[6]=pt_Auto1504;
	_Context->msg_Auto1504[7]=xx_Auto1504;
	for (i=0; i < 8; i++)_Context->msg_Auto1505[i]=" ";
	_Context->msg_Auto1505[0]=en_Auto1505;
	_Context->msg_Auto1505[1]=fr_Auto1505;
	_Context->msg_Auto1505[2]=it_Auto1505;
	_Context->msg_Auto1505[3]=es_Auto1505;
	_Context->msg_Auto1505[4]=de_Auto1505;
	_Context->msg_Auto1505[5]=nl_Auto1505;
	_Context->msg_Auto1505[6]=pt_Auto1505;
	_Context->msg_Auto1505[7]=xx_Auto1505;
	for (i=0; i < 8; i++)_Context->msg_Auto1506[i]=" ";
	_Context->msg_Auto1506[0]=en_Auto1506;
	_Context->msg_Auto1506[1]=fr_Auto1506;
	_Context->msg_Auto1506[2]=it_Auto1506;
	_Context->msg_Auto1506[3]=es_Auto1506;
	_Context->msg_Auto1506[4]=de_Auto1506;
	_Context->msg_Auto1506[5]=nl_Auto1506;
	_Context->msg_Auto1506[6]=pt_Auto1506;
	_Context->msg_Auto1506[7]=xx_Auto1506;
	for (i=0; i < 8; i++)_Context->msg_FileType[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_IndexType[i]=" ";
	_Context->msg_IndexType[0]=en_IndexType;
	_Context->msg_IndexType[1]=fr_IndexType;
	_Context->msg_IndexType[2]=it_IndexType;
	_Context->msg_IndexType[3]=es_IndexType;
	_Context->msg_IndexType[4]=de_IndexType;
	_Context->msg_IndexType[5]=nl_IndexType;
	_Context->msg_IndexType[6]=pt_IndexType;
	_Context->msg_IndexType[7]=xx_IndexType;
	for (i=0; i < 8; i++)_Context->msg_Auto1525[i]=" ";
	_Context->msg_Auto1525[0]=en_Auto1525;
	for (i=0; i < 8; i++)_Context->msg_Auto1507[i]=" ";
	_Context->msg_Auto1507[0]=en_Auto1507;
	_Context->msg_Auto1507[1]=fr_Auto1507;
	_Context->msg_Auto1507[2]=it_Auto1507;
	_Context->msg_Auto1507[3]=es_Auto1507;
	_Context->msg_Auto1507[4]=de_Auto1507;
	_Context->msg_Auto1507[5]=nl_Auto1507;
	_Context->msg_Auto1507[6]=pt_Auto1507;
	_Context->msg_Auto1507[7]=xx_Auto1507;
	for (i=0; i < 8; i++)_Context->msg_RecordType[i]=" ";
	_Context->msg_RecordType[0]=en_RecordType;
	_Context->msg_RecordType[1]=fr_RecordType;
	_Context->msg_RecordType[2]=it_RecordType;
	_Context->msg_RecordType[3]=es_RecordType;
	_Context->msg_RecordType[4]=de_RecordType;
	_Context->msg_RecordType[5]=nl_RecordType;
	_Context->msg_RecordType[6]=pt_RecordType;
	_Context->msg_RecordType[7]=xx_RecordType;
	for (i=0; i < 8; i++)_Context->msg_Auto1509[i]=" ";
	_Context->msg_Auto1509[0]=en_Auto1509;
	for (i=0; i < 8; i++)_Context->msg_Auto1510[i]=" ";
	_Context->msg_Auto1510[0]=en_Auto1510;
	_Context->msg_Auto1510[1]=fr_Auto1510;
	_Context->msg_Auto1510[2]=it_Auto1510;
	_Context->msg_Auto1510[3]=es_Auto1510;
	_Context->msg_Auto1510[4]=de_Auto1510;
	_Context->msg_Auto1510[5]=nl_Auto1510;
	_Context->msg_Auto1510[6]=pt_Auto1510;
	_Context->msg_Auto1510[7]=xx_Auto1510;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_Auto1511[i]=" ";
	_Context->msg_Auto1511[0]=en_Auto1511;
	_Context->msg_Auto1511[1]=fr_Auto1511;
	_Context->msg_Auto1511[2]=it_Auto1511;
	_Context->msg_Auto1511[3]=es_Auto1511;
	_Context->msg_Auto1511[4]=de_Auto1511;
	_Context->msg_Auto1511[5]=nl_Auto1511;
	_Context->msg_Auto1511[6]=pt_Auto1511;
	_Context->msg_Auto1511[7]=xx_Auto1511;
	for (i=0; i < 8; i++)_Context->msg_Auto1512[i]=" ";
	_Context->msg_Auto1512[0]=en_Auto1512;
	_Context->msg_Auto1512[1]=fr_Auto1512;
	_Context->msg_Auto1512[2]=it_Auto1512;
	_Context->msg_Auto1512[3]=es_Auto1512;
	_Context->msg_Auto1512[4]=de_Auto1512;
	_Context->msg_Auto1512[5]=nl_Auto1512;
	_Context->msg_Auto1512[6]=pt_Auto1512;
	_Context->msg_Auto1512[7]=xx_Auto1512;
	for (i=0; i < 8; i++)_Context->msg_Auto1513[i]=" ";
	_Context->msg_Auto1513[0]=en_Auto1513;
	_Context->msg_Auto1513[1]=fr_Auto1513;
	_Context->msg_Auto1513[2]=it_Auto1513;
	_Context->msg_Auto1513[3]=es_Auto1513;
	_Context->msg_Auto1513[4]=de_Auto1513;
	_Context->msg_Auto1513[5]=nl_Auto1513;
	_Context->msg_Auto1513[6]=pt_Auto1513;
	_Context->msg_Auto1513[7]=xx_Auto1513;
	for (i=0; i < 8; i++)_Context->msg_Auto1514[i]=" ";
	_Context->msg_Auto1514[0]=en_Auto1514;
	_Context->msg_Auto1514[1]=fr_Auto1514;
	_Context->msg_Auto1514[2]=it_Auto1514;
	_Context->msg_Auto1514[3]=es_Auto1514;
	_Context->msg_Auto1514[4]=de_Auto1514;
	_Context->msg_Auto1514[5]=nl_Auto1514;
	_Context->msg_Auto1514[6]=pt_Auto1514;
	_Context->msg_Auto1514[7]=xx_Auto1514;
	for (i=0; i < 8; i++)_Context->msg_Auto1515[i]=" ";
	_Context->msg_Auto1515[0]=en_Auto1515;
	_Context->msg_Auto1515[1]=fr_Auto1515;
	_Context->msg_Auto1515[2]=it_Auto1515;
	_Context->msg_Auto1515[3]=es_Auto1515;
	_Context->msg_Auto1515[4]=de_Auto1515;
	_Context->msg_Auto1515[5]=nl_Auto1515;
	_Context->msg_Auto1515[6]=pt_Auto1515;
	_Context->msg_Auto1515[7]=xx_Auto1515;
	for (i=0; i < 8; i++)_Context->msg_Auto1516[i]=" ";
	_Context->msg_Auto1516[0]=en_Auto1516;
	_Context->msg_Auto1516[1]=fr_Auto1516;
	_Context->msg_Auto1516[2]=it_Auto1516;
	_Context->msg_Auto1516[3]=es_Auto1516;
	_Context->msg_Auto1516[4]=de_Auto1516;
	_Context->msg_Auto1516[5]=nl_Auto1516;
	_Context->msg_Auto1516[6]=pt_Auto1516;
	_Context->msg_Auto1516[7]=xx_Auto1516;
	for (i=0; i < 8; i++)_Context->msg_IndexMembers[i]=" ";
	_Context->msg_IndexMembers[0]=en_IndexMembers;
	_Context->msg_IndexMembers[1]=fr_IndexMembers;
	_Context->msg_IndexMembers[2]=it_IndexMembers;
	_Context->msg_IndexMembers[3]=es_IndexMembers;
	_Context->msg_IndexMembers[4]=de_IndexMembers;
	_Context->msg_IndexMembers[5]=nl_IndexMembers;
	_Context->msg_IndexMembers[6]=pt_IndexMembers;
	_Context->msg_IndexMembers[7]=xx_IndexMembers;
	if ( 0 > 0 ) { _Context->row_IndexMembers=&_Context->buffer_IndexMembers[0-1][0]; } ;
	_Context->max_IndexBar=1;
	_Context->value_IndexBar=1;
	_Context->limit_IndexBar=1;
	_Context->value_IndexBar=0;
	_Context->limit_IndexBar=5;
	_Context->max_IndexBar=100;
	for (i=0; i < 8; i++)_Context->msg_DataMembers[i]=" ";
	_Context->msg_DataMembers[0]=en_DataMembers;
	_Context->msg_DataMembers[1]=fr_DataMembers;
	_Context->msg_DataMembers[2]=it_DataMembers;
	_Context->msg_DataMembers[3]=es_DataMembers;
	_Context->msg_DataMembers[4]=de_DataMembers;
	_Context->msg_DataMembers[5]=nl_DataMembers;
	_Context->msg_DataMembers[6]=pt_DataMembers;
	_Context->msg_DataMembers[7]=xx_DataMembers;
	if ( 0 > 0 ) { _Context->row_DataMembers=&_Context->buffer_DataMembers[0-1][0]; } ;
	_Context->max_DataBar=1;
	_Context->value_DataBar=1;
	_Context->limit_DataBar=1;
	_Context->value_DataBar=0;
	_Context->limit_DataBar=17;
	_Context->max_DataBar=1000;
	for (i=0; i < 8; i++)_Context->msg_TypeSelect[i]=" ";
	_Context->msg_TypeSelect[0]=en_TypeSelect;
	_Context->msg_TypeSelect[1]=fr_TypeSelect;
	_Context->msg_TypeSelect[2]=it_TypeSelect;
	_Context->msg_TypeSelect[3]=es_TypeSelect;
	_Context->msg_TypeSelect[4]=de_TypeSelect;
	_Context->msg_TypeSelect[5]=nl_TypeSelect;
	_Context->msg_TypeSelect[6]=pt_TypeSelect;
	_Context->msg_TypeSelect[7]=xx_TypeSelect;
	_Context->x_TypeSelect=_Context->x_Auto1502+521;
	_Context->y_TypeSelect=_Context->y_Auto1502+150;
	_Context->w_TypeSelect=72;
	_Context->h_TypeSelect=80;
	_Context->fg_TypeSelect=80;
	_Context->bg_TypeSelect=80;
	_Context->fid_TypeSelect=1;
	_Context->s_TypeSelect=0;
	_Context->p_TypeSelect=visual_buffer(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect);
	for (i=0; i < 8; i++)_Context->msg_MaskPage[i]=" ";
	_Context->msg_MaskPage[0]=en_MaskPage;
	_Context->msg_MaskPage[1]=fr_MaskPage;
	_Context->msg_MaskPage[2]=it_MaskPage;
	_Context->msg_MaskPage[3]=es_MaskPage;
	_Context->msg_MaskPage[4]=de_MaskPage;
	_Context->msg_MaskPage[5]=nl_MaskPage;
	_Context->msg_MaskPage[6]=pt_MaskPage;
	_Context->msg_MaskPage[7]=xx_MaskPage;
	_Context->focus_pages[3]=26;
	for (i=0; i < 8; i++)_Context->msg_Auto1786[i]=" ";
	_Context->msg_Auto1786[0]=en_Auto1786;
	_Context->msg_Auto1786[1]=fr_Auto1786;
	_Context->msg_Auto1786[2]=it_Auto1786;
	_Context->msg_Auto1786[3]=es_Auto1786;
	_Context->msg_Auto1786[4]=de_Auto1786;
	_Context->msg_Auto1786[5]=nl_Auto1786;
	_Context->msg_Auto1786[6]=pt_Auto1786;
	_Context->msg_Auto1786[7]=xx_Auto1786;
	for (i=0; i < 8; i++)_Context->msg_Auto1787[i]=" ";
	_Context->msg_Auto1787[0]=en_Auto1787;
	_Context->msg_Auto1787[1]=fr_Auto1787;
	_Context->msg_Auto1787[2]=it_Auto1787;
	_Context->msg_Auto1787[3]=es_Auto1787;
	_Context->msg_Auto1787[4]=de_Auto1787;
	_Context->msg_Auto1787[5]=nl_Auto1787;
	_Context->msg_Auto1787[6]=pt_Auto1787;
	_Context->msg_Auto1787[7]=xx_Auto1787;
	for (i=0; i < 8; i++)_Context->msg_Auto1795[i]=" ";
	_Context->msg_Auto1795[0]=en_Auto1795;
	_Context->msg_Auto1795[1]=fr_Auto1795;
	_Context->msg_Auto1795[2]=it_Auto1795;
	_Context->msg_Auto1795[3]=es_Auto1795;
	_Context->msg_Auto1795[4]=de_Auto1795;
	_Context->msg_Auto1795[5]=nl_Auto1795;
	_Context->msg_Auto1795[6]=pt_Auto1795;
	_Context->msg_Auto1795[7]=xx_Auto1795;
	for (i=0; i < 8; i++)_Context->msg_Auto1792[i]=" ";
	_Context->msg_Auto1792[0]=en_Auto1792;
	_Context->msg_Auto1792[1]=fr_Auto1792;
	_Context->msg_Auto1792[2]=it_Auto1792;
	_Context->msg_Auto1792[3]=es_Auto1792;
	_Context->msg_Auto1792[4]=de_Auto1792;
	_Context->msg_Auto1792[5]=nl_Auto1792;
	_Context->msg_Auto1792[6]=pt_Auto1792;
	_Context->msg_Auto1792[7]=xx_Auto1792;
	for (i=0; i < 8; i++)_Context->msg_Auto1791[i]=" ";
	_Context->msg_Auto1791[0]=en_Auto1791;
	_Context->msg_Auto1791[1]=fr_Auto1791;
	_Context->msg_Auto1791[2]=it_Auto1791;
	_Context->msg_Auto1791[3]=es_Auto1791;
	_Context->msg_Auto1791[4]=de_Auto1791;
	_Context->msg_Auto1791[5]=nl_Auto1791;
	_Context->msg_Auto1791[6]=pt_Auto1791;
	_Context->msg_Auto1791[7]=xx_Auto1791;
	for (i=0; i < 8; i++)_Context->msg_Auto1869[i]=" ";
	_Context->msg_Auto1869[0]=en_Auto1869;
	_Context->msg_Auto1869[1]=fr_Auto1869;
	_Context->msg_Auto1869[2]=it_Auto1869;
	_Context->msg_Auto1869[3]=es_Auto1869;
	_Context->msg_Auto1869[4]=de_Auto1869;
	_Context->msg_Auto1869[5]=nl_Auto1869;
	_Context->msg_Auto1869[6]=pt_Auto1869;
	_Context->msg_Auto1869[7]=xx_Auto1869;
	for (i=0; i < 8; i++)_Context->msg_Nature[i]=" ";
	_Context->msg_Nature[0]=en_Nature;
	_Context->msg_Nature[1]=fr_Nature;
	_Context->msg_Nature[2]=it_Nature;
	_Context->msg_Nature[3]=es_Nature;
	_Context->msg_Nature[4]=de_Nature;
	_Context->msg_Nature[5]=nl_Nature;
	_Context->msg_Nature[6]=pt_Nature;
	_Context->msg_Nature[7]=xx_Nature;
	for (i=0; i < 8; i++)_Context->msg_Language[i]=" ";
	_Context->msg_Language[0]=en_Language;
	_Context->msg_Language[1]=fr_Language;
	_Context->msg_Language[2]=it_Language;
	_Context->msg_Language[3]=es_Language;
	_Context->msg_Language[4]=de_Language;
	_Context->msg_Language[5]=nl_Language;
	_Context->msg_Language[6]=pt_Language;
	_Context->msg_Language[7]=xx_Language;
	for (i=0; i < 8; i++)_Context->msg_Auto1794[i]=" ";
	_Context->msg_Auto1794[0]=en_Auto1794;
	_Context->msg_Auto1794[1]=fr_Auto1794;
	_Context->msg_Auto1794[2]=it_Auto1794;
	_Context->msg_Auto1794[3]=es_Auto1794;
	_Context->msg_Auto1794[4]=de_Auto1794;
	_Context->msg_Auto1794[5]=nl_Auto1794;
	_Context->msg_Auto1794[6]=pt_Auto1794;
	_Context->msg_Auto1794[7]=xx_Auto1794;
	_Context->value_Progress=1;
	_Context->limit_Progress=1;
	_Context->value_Progress=0;
	_Context->limit_Progress=0;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto1502,_Context->y_Auto1502,790+10,590+10);
	return(0);
}

public 	int	database_editor_hide(struct database_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto1502,_Context->y_Auto1502);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	database_editor_remove(struct database_editor_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_TypeSelect != (void *) 0)
		_Context->p_TypeSelect = visual_drop(_Context->p_TypeSelect);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_FileList_show(struct database_editor_context * _Context) {
	int l;
	int item;
	struct file_control*fptr;
	struct data_control*dptr;
	memset(_Context->buffer_FileList,' ',2552);
	for(l=1;
	l<29;
	l++){
	item=(_Context->value_ScrollBar+l);
	if(!(fptr=locate_file(_Context, item))){
	continue;
	}
	else{
	if ( l > 0 ) { _Context->row_FileList=&_Context->buffer_FileList[l-1][0]; } ;
	if(fptr->classname)
	putstring(_Context, (_Context->row_FileList+0),33,fptr->classname);
	if(fptr->identity)
	putstring(_Context, (_Context->row_FileList+33),33,fptr->identity);
	if((dptr=fptr->payload)!=(struct data_control*)0){
	if(dptr->datalength>0){
	sprintf((_Context->row_FileList+66),"D=%u(%u)",dptr->datalength,dptr->datafields);
	}
	if(dptr->indexlength>0){
	sprintf((_Context->row_FileList+77),"K=%u(%u)",dptr->indexlength,dptr->indexfields);
	}
	}
	}
	}
		visual_table(_Context->x_Auto1502+30,_Context->y_Auto1502+80,710+2,490+2,vfh[1],27,28,_Context->msg_FileList[_Context->language],_Context->buffer_FileList,0x4401,"($,W32,W10,W10)");
;
	return(-1);
}
private int on_ClassName_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->classname))
	putstring(_Context, _Context->buffer_ClassName,41,FileManager.current->classname);
	else putstring(_Context, _Context->buffer_ClassName,41," ");
	visual_frame(_Context->x_Auto1502+110,_Context->y_Auto1502+80,328+2,16+2,5);
visual_text(_Context->x_Auto1502+110+1,_Context->y_Auto1502+80+1,328,16,vfh[1],0,28,_Context->buffer_ClassName,41,0);
;
	return(-1);
}
private int on_Instance_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->identity))
	putstring(_Context, _Context->buffer_Instance,41,FileManager.current->identity);
	else putstring(_Context, _Context->buffer_Instance,41," ");
	visual_frame(_Context->x_Auto1502+110,_Context->y_Auto1502+100,328+2,16+2,5);
visual_text(_Context->x_Auto1502+110+1,_Context->y_Auto1502+100+1,328,16,vfh[1],0,28,_Context->buffer_Instance,41,0);
;
	return(-1);
}
private int on_Filename_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->filename))
	putstring(_Context, _Context->buffer_Filename,41,FileManager.current->filename);
	else putstring(_Context, _Context->buffer_Filename,41," ");
	visual_frame(_Context->x_Auto1502+110,_Context->y_Auto1502+120,328+2,16+2,5);
visual_text(_Context->x_Auto1502+110+1,_Context->y_Auto1502+120+1,328,16,vfh[1],0,28,_Context->buffer_Filename,41,0);
;
	return(-1);
}
private int on_FileType_show(struct database_editor_context * _Context) {
	if(FileManager.current)
	_Context->value_FileType=FileManager.current->nature;
	else _Context->value_FileType=2;
		visual_select(_Context->x_Auto1502+110,_Context->y_Auto1502+140,96,64,vfh[1],0,28,parse_selection(WidgetDataList,&_Context->value_FileType),0);

	return(-1);
}
private int on_IndexType_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)){
	if(FileManager.current->payload->option&_A_LEFT)
	_Context->value_IndexType=2;
	else if(FileManager.current->payload->option&_A_RIGHT)
	_Context->value_IndexType=3;
	else _Context->value_IndexType=1;
	}
		visual_select(_Context->x_Auto1502+270,_Context->y_Auto1502+140,80,70,vfh[1],0,0,parse_selection(_Context->msg_IndexType[_Context->language],&_Context->value_IndexType),0);
;
	return(-1);
}
private int on_IndexSize_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload))
	sprintf(_Context->buffer_IndexSize,"%u",FileManager.current->payload->indexlength);
	else strcpy(_Context->buffer_IndexSize," ");
	visual_frame(_Context->x_Auto1502+580,_Context->y_Auto1502+100,64+2,16+2,5);
visual_text(_Context->x_Auto1502+580+1,_Context->y_Auto1502+100+1,64,16,vfh[1],0,0,_Context->buffer_IndexSize,8,0);
;
	return(-1);
}
private int on_NbIndex_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload))
	sprintf(_Context->buffer_NbIndex,"%u",FileManager.current->payload->indexfields);
	else strcpy(_Context->buffer_NbIndex," ");
	visual_frame(_Context->x_Auto1502+680,_Context->y_Auto1502+100,40+2,16+2,5);
visual_text(_Context->x_Auto1502+680+1,_Context->y_Auto1502+100+1,40,16,vfh[1],0,0,_Context->buffer_NbIndex,5,0);

	return(-1);
}
private int on_RecordType_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)){
	if(FileManager.current->payload->option&_A_BOLD)
	_Context->value_RecordType=1;
	else _Context->value_RecordType=0;
	}
		_Context->trigger_RecordType=visual_trigger_code(_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]));
	visual_check(_Context->x_Auto1502+360,_Context->y_Auto1502+140,70,16,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),_Context->value_RecordType|0);
;
	return(-1);
}
private int on_RecordSize_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload))
	sprintf(_Context->buffer_RecordSize,"%u",FileManager.current->payload->datalength);
	else strcpy(_Context->buffer_RecordSize," ");
	visual_frame(_Context->x_Auto1502+580,_Context->y_Auto1502+120,64+2,16+2,5);
visual_text(_Context->x_Auto1502+580+1,_Context->y_Auto1502+120+1,64,16,vfh[1],0,0,_Context->buffer_RecordSize,8,0);
;
	return(-1);
}
private int on_NbData_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload))
	sprintf(_Context->buffer_NbData,"%u",FileManager.current->payload->datafields);
	else strcpy(_Context->buffer_NbData," ");
	visual_frame(_Context->x_Auto1502+680,_Context->y_Auto1502+120,40+2,16+2,5);
visual_text(_Context->x_Auto1502+680+1,_Context->y_Auto1502+120+1,40,16,vfh[1],0,0,_Context->buffer_NbData,5,0);

	return(-1);
}
private int on_IndexMembers_show(struct database_editor_context * _Context) {
	struct data_control*dptr;
	int i;
	int l;
	memset(_Context->buffer_IndexMembers,' ',435);
	if((!(FileManager.current))
	||(!(dptr=FileManager.current->payload)))
	return(0);
	else{
	if((_Context->max_IndexBar=dptr->indexfields)>0){
	for(l=1;l<=5;l++){
	if((i=((l-1)+_Context->value_IndexBar))>=dptr->indexfields)
	break;
	else{
	if ( l > 0 ) { _Context->row_IndexMembers=&_Context->buffer_IndexMembers[l-1][0]; } ;
	putstring(_Context, (_Context->row_IndexMembers+0),60,dptr->name[i]);
	switch(dptr->type[i]){
	case _ABAL_BYTE:
	putstring(_Context, (_Context->row_IndexMembers+60),9,"byte");
	sprintf((_Context->row_IndexMembers+69),"%u",1);
	break;
	case _ABAL_WORD:
	putstring(_Context, (_Context->row_IndexMembers+60),9,"word");
	sprintf((_Context->row_IndexMembers+69),"%u",2);
	break;
	case _ABAL_LONG:
	putstring(_Context, (_Context->row_IndexMembers+60),9,"long");
	sprintf((_Context->row_IndexMembers+69),"%u",4);
	break;
	case _ABAL_BCD:
	putstring(_Context, (_Context->row_IndexMembers+60),9,"bcd");
	sprintf((_Context->row_IndexMembers+69),"%u",dptr->width[i]);
	break;
	case _ABAL_STRING:
	putstring(_Context, (_Context->row_IndexMembers+60),9,"string");
	sprintf((_Context->row_IndexMembers+69),"%u",dptr->width[i]);
	break;
	}
	sprintf((_Context->row_IndexMembers+75),"%u",dptr->first[i]);
	sprintf((_Context->row_IndexMembers+81),"%u",dptr->second[i]);
	}
	}
		visual_table(_Context->x_Auto1502+40,_Context->y_Auto1502+180,700+2,100+2,vfh[1],0,0,_Context->msg_IndexMembers[_Context->language],_Context->buffer_IndexMembers,0x4401,"($,W8,N4Z,N4Z,N4Z)");
;
	}
	}
		return(-1);
}
private int on_IndexBar_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)
	&&((_Context->max_IndexBar=FileManager.current->payload->indexfields)!=0)){
		visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
;
	}
	return(-1);
}
private int on_DataMembers_show(struct database_editor_context * _Context) {
	struct data_control*dptr;
	int i;
	int l;
	memset(_Context->buffer_DataMembers,' ',1479);
	if((!(FileManager.current))
	||(!(dptr=FileManager.current->payload)))
	return(0);
	else{
	if((_Context->max_DataBar=dptr->datafields)>0){
	for(l=1;l<=17;l++){
	if((i=((l-1)+_Context->value_DataBar))>=dptr->datafields)
	break;
	else{
	if ( l > 0 ) { _Context->row_DataMembers=&_Context->buffer_DataMembers[l-1][0]; } ;
	putstring(_Context, (_Context->row_DataMembers+0),60,dptr->name[i+dptr->indexfields]);
	switch(dptr->type[i+dptr->indexfields]){
	case _ABAL_BYTE:
	putstring(_Context, (_Context->row_DataMembers+60),9,"byte");
	sprintf((_Context->row_DataMembers+69),"%u",1);
	break;
	case _ABAL_WORD:
	putstring(_Context, (_Context->row_DataMembers+60),9,"word");
	sprintf((_Context->row_DataMembers+69),"%u",2);
	break;
	case _ABAL_LONG:
	putstring(_Context, (_Context->row_DataMembers+60),9,"long");
	sprintf((_Context->row_DataMembers+69),"%u",4);
	break;
	case _ABAL_BCD:
	putstring(_Context, (_Context->row_DataMembers+60),9,"bcd");
	sprintf((_Context->row_DataMembers+69),"%u",dptr->width[i+dptr->indexfields]);
	break;
	case _ABAL_STRING:
	putstring(_Context, (_Context->row_DataMembers+60),9,"string");
	sprintf((_Context->row_DataMembers+69),"%u",dptr->width[i+dptr->indexfields]);
	break;
	}
	sprintf((_Context->row_DataMembers+75),"%u",dptr->first[i+dptr->indexfields]);
	sprintf((_Context->row_DataMembers+81),"%u",dptr->second[i+dptr->indexfields]);
	}
	}
		visual_table(_Context->x_Auto1502+40,_Context->y_Auto1502+280,700+2,290+2,vfh[1],0,0,_Context->msg_DataMembers[_Context->language],_Context->buffer_DataMembers,0x4401,"($,W8,N4Z,N4Z,N4Z)");
;
	}
	}
	return(-1);
}
private int on_DataBar_show(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)
	&&((_Context->max_DataBar=FileManager.current->payload->datafields)!=0)){
		visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
;
	}
	return(-1);
}

public	int	database_editor_show(struct database_editor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto1502,_Context->y_Auto1502);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto1502,_Context->y_Auto1502,790,590,vfh[2],_Context->msg_Auto1502[_Context->language],strlen(_Context->msg_Auto1502[_Context->language]),0x407);
	if (_Context->page_number == 1 ) {
	_Context->trigger_ListPage=visual_trigger_code(_Context->msg_ListPage[_Context->language],strlen(_Context->msg_ListPage[_Context->language]));
	visual_tabpage(_Context->x_Auto1502+20,_Context->y_Auto1502+40,750,540,vfh[2],_Context->msg_ListPage[_Context->language],strlen(_Context->msg_ListPage[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto1502+20,_Context->y_Auto1502+40,750,540,vfh[2],_Context->msg_ListPage[_Context->language],strlen(_Context->msg_ListPage[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	(void) on_FileList_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto1502+740,_Context->y_Auto1502+180,8,16,vfh[1],27,28,_Context->msg_Auto1524[_Context->language],strlen(_Context->msg_Auto1524[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_FilePage=visual_trigger_code(_Context->msg_FilePage[_Context->language],strlen(_Context->msg_FilePage[_Context->language]));
	visual_tabpage(_Context->x_Auto1502+20,_Context->y_Auto1502+40,750,540,vfh[2],_Context->msg_FilePage[_Context->language],strlen(_Context->msg_FilePage[_Context->language]),59,2);
	} else {
		visual_tabpage(_Context->x_Auto1502+20,_Context->y_Auto1502+40,750,540,vfh[2],_Context->msg_FilePage[_Context->language],strlen(_Context->msg_FilePage[_Context->language]),59,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto1502+40,_Context->y_Auto1502+70,410,100,4);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto1502+450,_Context->y_Auto1502+70,310,100,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+30,_Context->y_Auto1502+80,70,16,vfh[2],16,0,_Context->msg_Auto1504[_Context->language],strlen(_Context->msg_Auto1504[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+660,_Context->y_Auto1502+80,84,16,vfh[2],16,0,_Context->msg_Auto1505[_Context->language],strlen(_Context->msg_Auto1505[_Context->language]),1283);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+580,_Context->y_Auto1502+80,70,16,vfh[2],16,0,_Context->msg_Auto1506[_Context->language],strlen(_Context->msg_Auto1506[_Context->language]),1283);
		}
	if (_Context->page_number == 2 ) {
	(void) on_ClassName_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Instance_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Filename_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_FileType_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_IndexType_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_IndexSize_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1525=visual_trigger_code(_Context->msg_Auto1525[_Context->language],strlen(_Context->msg_Auto1525[_Context->language]));
	visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1525[_Context->language],strlen(_Context->msg_Auto1525[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_NbIndex_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1507=visual_trigger_code(_Context->msg_Auto1507[_Context->language],strlen(_Context->msg_Auto1507[_Context->language]));
	visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1507[_Context->language],strlen(_Context->msg_Auto1507[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_RecordType_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_RecordSize_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1509=visual_trigger_code(_Context->msg_Auto1509[_Context->language],strlen(_Context->msg_Auto1509[_Context->language]));
	visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1509[_Context->language],strlen(_Context->msg_Auto1509[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_NbData_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto1510=visual_trigger_code(_Context->msg_Auto1510[_Context->language],strlen(_Context->msg_Auto1510[_Context->language]));
	visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1510[_Context->language],strlen(_Context->msg_Auto1510[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto1502+580,_Context->y_Auto1502+140,168,24,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+30,_Context->y_Auto1502+140,70,16,vfh[2],16,0,_Context->msg_Auto1511[_Context->language],strlen(_Context->msg_Auto1511[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+210,_Context->y_Auto1502+140,56,16,vfh[2],16,0,_Context->msg_Auto1512[_Context->language],strlen(_Context->msg_Auto1512[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+460,_Context->y_Auto1502+100,112,16,vfh[2],16,0,_Context->msg_Auto1513[_Context->language],strlen(_Context->msg_Auto1513[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+460,_Context->y_Auto1502+120,112,16,vfh[2],16,0,_Context->msg_Auto1514[_Context->language],strlen(_Context->msg_Auto1514[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+30,_Context->y_Auto1502+100,70,16,vfh[2],16,0,_Context->msg_Auto1515[_Context->language],strlen(_Context->msg_Auto1515[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto1502+30,_Context->y_Auto1502+120,70,16,vfh[2],16,0,_Context->msg_Auto1516[_Context->language],strlen(_Context->msg_Auto1516[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	(void) on_IndexMembers_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_IndexBar_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_DataMembers_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_DataBar_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_MaskPage=visual_trigger_code(_Context->msg_MaskPage[_Context->language],strlen(_Context->msg_MaskPage[_Context->language]));
	visual_tabpage(_Context->x_Auto1502+20,_Context->y_Auto1502+40,750,540,vfh[2],_Context->msg_MaskPage[_Context->language],strlen(_Context->msg_MaskPage[_Context->language]),128,2);
	} else {
		visual_tabpage(_Context->x_Auto1502+20,_Context->y_Auto1502+40,750,540,vfh[2],_Context->msg_MaskPage[_Context->language],strlen(_Context->msg_MaskPage[_Context->language]),128,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto1502+30,_Context->y_Auto1502+80,730,480,4);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto1502+40,_Context->y_Auto1502+290,440,50,1);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto1502+40,_Context->y_Auto1502+90,710,40,vfh[3],16,0,_Context->msg_Auto1786[_Context->language],strlen(_Context->msg_Auto1786[_Context->language]),1283);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto1502+50,_Context->y_Auto1502+140,238,16,vfh[2],16,0,_Context->msg_Auto1787[_Context->language],strlen(_Context->msg_Auto1787[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto1502+50,_Context->y_Auto1502+190,238,16,vfh[2],16,0,_Context->msg_Auto1795[_Context->language],strlen(_Context->msg_Auto1795[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto1502+50,_Context->y_Auto1502+240,196,16,vfh[2],16,0,_Context->msg_Auto1792[_Context->language],strlen(_Context->msg_Auto1792[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto1502+270,_Context->y_Auto1502+240,196,16,vfh[2],16,0,_Context->msg_Auto1791[_Context->language],strlen(_Context->msg_Auto1791[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto1502+540,_Context->y_Auto1502+260,98,16,vfh[2],16,0,_Context->msg_Auto1869[_Context->language],strlen(_Context->msg_Auto1869[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto1502+50,_Context->y_Auto1502+160,688+2,16+2,5);
	visual_text(_Context->x_Auto1502+50+1,_Context->y_Auto1502+160+1,688,16,vfh[1],16,0,_Context->buffer_Identifier,86,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto1502+50,_Context->y_Auto1502+210,688+2,16+2,5);
	visual_text(_Context->x_Auto1502+50+1,_Context->y_Auto1502+210+1,688,16,vfh[1],16,0,_Context->buffer_Title,86,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(_Context->x_Auto1502+50,_Context->y_Auto1502+260,200,90,vfh[1],16,0,parse_selection(_Context->msg_Nature[_Context->language],&_Context->value_Nature),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(_Context->x_Auto1502+270,_Context->y_Auto1502+260,200,90,vfh[1],16,0,parse_selection(_Context->msg_Language[_Context->language],&_Context->value_Language),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto1502+640,_Context->y_Auto1502+260,56+2,16+2,5);
	visual_text(_Context->x_Auto1502+640+1,_Context->y_Auto1502+260+1,56,16,vfh[1],0,0,_Context->buffer_PageItems,7,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Auto1794=visual_trigger_code(_Context->msg_Auto1794[_Context->language],strlen(_Context->msg_Auto1794[_Context->language]));
	visual_button(_Context->x_Auto1502+50,_Context->y_Auto1502+300,200,32,vfh[2],16,0,_Context->msg_Auto1794[_Context->language],strlen(_Context->msg_Auto1794[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_progress(_Context->x_Auto1502+270,_Context->y_Auto1502+300,200,30,vfh[1],70,96,_Context->value_Progress,_Context->limit_Progress,0);
		}
	visual_thaw(_Context->x_Auto1502,_Context->y_Auto1502,790,590);
	visual_thaw(_Context->x_Auto1502,_Context->y_Auto1502,790,590);

	return(0);
}

private int Auto1502action(struct database_editor_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			database_editor_hide(_Context);

		_Context->x_Auto1502 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto1502 < 0) { _Context->x_Auto1502=0; }
		_Context->y_Auto1502 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto1502 < 0) { _Context->y_Auto1502=0; }
			database_editor_show(_Context);

		visual_thaw(_Context->x_Auto1502,_Context->y_Auto1502,790,590);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_FileList_event(struct database_editor_context * _Context) {
	int l;
	struct file_control*fptr;
	l=_Context->value_FileList;
	if(l>0){
	l+=_Context->value_ScrollBar;
	if((fptr=locate_file(_Context, l))!=(struct file_control*)0){
	FileManager.current=fptr;
	if(visual_event(2)==_MIMO_RIGHT){
	while((visual_getch()!=256)
	&&(visual_event(1)!=32));
		/* FilePage */
	database_editor_losefocus(_Context);
	_Context->page_number = 2;
	database_editor_show(_Context);
	_Context->focus_item=5;
;
	}
	}
	}
	return(-1);
}

private int on_ScrollBar_action(struct database_editor_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto1502+80+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_ScrollBar -= 1;
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
	status = database_editor_show(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto1502+80+490-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_ScrollBar += 1;
		if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
	status = database_editor_show(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_ScrollBar;
		_Context->value_ScrollBar = (((visual_event(6) - (_Context->y_Auto1502+80+20)) * _Context->max_ScrollBar) / (490 - (2 * 20)));
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
		else if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
		if (_Context->value_ScrollBar != aty) {
	status = database_editor_show(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_ScrollBar -= (_Context->limit_ScrollBar/2);
			if (_Context->value_ScrollBar < 0) 
				_Context->value_ScrollBar = 0;
	status = database_editor_show(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_ScrollBar += (_Context->limit_ScrollBar/2);
			if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
				_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
	status = database_editor_show(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+80,20,490,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);

	return(1);
}
private int on_Auto1525_event(struct database_editor_context * _Context) {
	adjust_members(_Context, 2);
		database_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1507_event(struct database_editor_context * _Context) {
	adjust_members(_Context, 1);
		database_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1509_event(struct database_editor_context * _Context) {
	adjust_members(_Context, 0);
		database_editor_show(_Context);
;
	return(-1);
}
private int on_Auto1510_event(struct database_editor_context * _Context) {
	adjust_members(_Context, 3);
		database_editor_show(_Context);
;
	return(-1);
}
private int on_Accept_event(struct database_editor_context * _Context) {
	return(13);
	return(-1);
}
private int on_IndexBar_event(struct database_editor_context * _Context) {
	on_IndexMembers_show(_Context);
	return(-1);
}

private int on_IndexBar_action(struct database_editor_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto1502+180+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_IndexBar -= 1;
		if (_Context->value_IndexBar < 0) 
			_Context->value_IndexBar = 0;
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto1502+180+100-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_IndexBar += 1;
		if (_Context->value_IndexBar > (_Context->max_IndexBar-_Context->limit_IndexBar)) 
			_Context->value_IndexBar = (_Context->max_IndexBar-_Context->limit_IndexBar);
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_IndexBar;
		_Context->value_IndexBar = (((visual_event(6) - (_Context->y_Auto1502+180+20)) * _Context->max_IndexBar) / (100 - (2 * 20)));
		if (_Context->value_IndexBar < 0) 
			_Context->value_IndexBar = 0;
		else if (_Context->value_IndexBar > (_Context->max_IndexBar-_Context->limit_IndexBar)) 
			_Context->value_IndexBar = (_Context->max_IndexBar-_Context->limit_IndexBar);
		if (_Context->value_IndexBar != aty) {
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_IndexBar -= (_Context->limit_IndexBar/2);
			if (_Context->value_IndexBar < 0) 
				_Context->value_IndexBar = 0;
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_IndexBar += (_Context->limit_IndexBar/2);
			if (_Context->value_IndexBar > (_Context->max_IndexBar-_Context->limit_IndexBar)) 
				_Context->value_IndexBar = (_Context->max_IndexBar-_Context->limit_IndexBar);
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+180,20,100,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);

	return(1);
}
private int on_DataBar_event(struct database_editor_context * _Context) {
	on_DataMembers_show(_Context);
	return(-1);
}

private int on_DataBar_action(struct database_editor_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto1502+280+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_DataBar -= 1;
		if (_Context->value_DataBar < 0) 
			_Context->value_DataBar = 0;
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto1502+280+290-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_DataBar += 1;
		if (_Context->value_DataBar > (_Context->max_DataBar-_Context->limit_DataBar)) 
			_Context->value_DataBar = (_Context->max_DataBar-_Context->limit_DataBar);
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_DataBar;
		_Context->value_DataBar = (((visual_event(6) - (_Context->y_Auto1502+280+20)) * _Context->max_DataBar) / (290 - (2 * 20)));
		if (_Context->value_DataBar < 0) 
			_Context->value_DataBar = 0;
		else if (_Context->value_DataBar > (_Context->max_DataBar-_Context->limit_DataBar)) 
			_Context->value_DataBar = (_Context->max_DataBar-_Context->limit_DataBar);
		if (_Context->value_DataBar != aty) {
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_DataBar -= (_Context->limit_DataBar/2);
			if (_Context->value_DataBar < 0) 
				_Context->value_DataBar = 0;
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_DataBar += (_Context->limit_DataBar/2);
			if (_Context->value_DataBar > (_Context->max_DataBar-_Context->limit_DataBar)) 
				_Context->value_DataBar = (_Context->max_DataBar-_Context->limit_DataBar);
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto1502+740,_Context->y_Auto1502+280,20,290,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);

	return(1);
}
private int on_Auto1794_event(struct database_editor_context * _Context) {
	int result;
	int pitems=0;
	int i;
	struct data_control*dptr;
	char*pptr;
	if((!(FileManager.current))
	||(!(dptr=FileManager.current->payload)))
	return(-1);
	for(pptr=_Context->buffer_PageItems,i=0;i<7;i++){
	if((*(pptr+i)>='0')&&(*(pptr+i)<='9'))
	pitems=((pitems*10)+(*(pptr+i)-'0'));
	else break;
	}
	if(_Context->value_Nature==0)
	result=generate_data_mask(FileManager.current,&_Context->buffer_Identifier,86,&_Context->buffer_Title,86,_Context->value_Language,pitems);
	else result=generate_data_page(FileManager.current,&_Context->buffer_Identifier,86,&_Context->buffer_Title,86,_Context->value_Language,pitems);
		database_editor_hide(_Context);
;
	draw_console();
	return(result);
	return(-1);
}


public	int	database_editor_event(
struct database_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ListPage == mb ) return(2);
		if (_Context->trigger_FilePage == mb ) return(5);
		if (_Context->trigger_Auto1525 == mb ) return(12);
		if (_Context->trigger_Auto1507 == mb ) return(14);
		if (_Context->trigger_RecordType == mb ) return(15);
		if (_Context->trigger_Auto1509 == mb ) return(17);
		if (_Context->trigger_Auto1510 == mb ) return(19);
		if (_Context->trigger_Accept == mb ) return(20);
		if (_Context->trigger_MaskPage == mb ) return(26);
		if (_Context->trigger_Auto1794 == mb ) return(32);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3033)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto1502+769) )  
	&&  (my >= (_Context->y_Auto1502+4) )  
	&&  (mx <= (_Context->x_Auto1502+786) )  
	&&  (my <= (_Context->y_Auto1502+20) )) {
		return(1);	/* Auto1502 */

		}
	if ((mx >= (_Context->x_Auto1502+753) )  
	&&  (my >= (_Context->y_Auto1502+4) )  
	&&  (mx <= (_Context->x_Auto1502+770) )  
	&&  (my <= (_Context->y_Auto1502+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfile.htm");
			};
		return(-1);	/* Auto1502 */

		}
	if ((mx >= (_Context->x_Auto1502+737) )  
	&&  (my >= (_Context->y_Auto1502+4) )  
	&&  (mx <= (_Context->x_Auto1502+754) )  
	&&  (my <= (_Context->y_Auto1502+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		database_editor_show(_Context);
		return(-1);	/* Auto1502 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto1502+4) )  
		&&  (my >= (_Context->y_Auto1502+4) )  
		&&  (mx <= (_Context->x_Auto1502+722) )  
		&&  (my <= (_Context->y_Auto1502+20) )) {
			return( Auto1502action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto1502+20+0) ) 
		&&  ( my >= (_Context->y_Auto1502+40) ) 
		&&  ( mx <= (_Context->x_Auto1502+20+58) ) 
		&&  ( my <= (_Context->y_Auto1502+40+24))) {
			return(2); /* ListPage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1502+30) ) 
		&&  ( my >= (_Context->y_Auto1502+80) ) 
		&&  ( mx <= (_Context->x_Auto1502+30+710) ) 
		&&  ( my <= (_Context->y_Auto1502+80+490))) {
			if ((_Context->value_FileList = ((visual_event(6) - (_Context->y_Auto1502+80)) / 16)) < 1)
				_Context->value_FileList=0;
else if (_Context->value_FileList > 29 )
				_Context->value_FileList=29;
			if ( _Context->value_FileList > 0 ) { _Context->row_FileList = &_Context->buffer_FileList[(_Context->value_FileList-1)][0]; } 
			_Context->column_FileList = (visual_event(7) - (_Context->x_Auto1502+30));
			if ( _Context->column_FileList < 265 ) {
				_Context->column_FileList = 1;
				}
			else if ( _Context->column_FileList < 530 ) {
				_Context->column_FileList = 2;
				}
			else if ( _Context->column_FileList < 619 ) {
				_Context->column_FileList = 3;
				}
			else if ( _Context->column_FileList < 708 ) {
				_Context->column_FileList = 4;
				}
			return(3); /* FileList */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto1502+740) ) 
		&&  ( my >= (_Context->y_Auto1502+80) ) 
		&&  ( mx <= (_Context->x_Auto1502+740+20) ) 
		&&  ( my <= (_Context->y_Auto1502+80+490))) {
			return(4); /* ScrollBar */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto1502+20+59) ) 
		&&  ( my >= (_Context->y_Auto1502+40) ) 
		&&  ( mx <= (_Context->x_Auto1502+20+127) ) 
		&&  ( my <= (_Context->y_Auto1502+40+24))) {
			return(5); /* FilePage */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+110) ) 
		&&  ( my >= (_Context->y_Auto1502+80) ) 
		&&  ( mx <= (_Context->x_Auto1502+110+328) ) 
		&&  ( my <= (_Context->y_Auto1502+80+16))) {
			return(6); /* ClassName */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+110) ) 
		&&  ( my >= (_Context->y_Auto1502+100) ) 
		&&  ( mx <= (_Context->x_Auto1502+110+328) ) 
		&&  ( my <= (_Context->y_Auto1502+100+16))) {
			return(7); /* Instance */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+110) ) 
		&&  ( my >= (_Context->y_Auto1502+120) ) 
		&&  ( mx <= (_Context->x_Auto1502+110+328) ) 
		&&  ( my <= (_Context->y_Auto1502+120+16))) {
			return(8); /* Filename */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+110+0) ) 
		&&  ( my >= (_Context->y_Auto1502+140) ) 
		&&  ( mx <= (_Context->x_Auto1502+110+96) ) 
		&&  ( my <= (_Context->y_Auto1502+140+16))) {
			return(9); /* FileType */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+270+0) ) 
		&&  ( my >= (_Context->y_Auto1502+140) ) 
		&&  ( mx <= (_Context->x_Auto1502+270+80) ) 
		&&  ( my <= (_Context->y_Auto1502+140+16))) {
			return(10); /* IndexType */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+580) ) 
		&&  ( my >= (_Context->y_Auto1502+100) ) 
		&&  ( mx <= (_Context->x_Auto1502+580+64) ) 
		&&  ( my <= (_Context->y_Auto1502+100+16))) {
			return(11); /* IndexSize */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+660) ) 
		&&  ( my >= (_Context->y_Auto1502+120) ) 
		&&  ( mx <= (_Context->x_Auto1502+660+16) ) 
		&&  ( my <= (_Context->y_Auto1502+120+18))) {
			return(12); /* Auto1525 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+680) ) 
		&&  ( my >= (_Context->y_Auto1502+100) ) 
		&&  ( mx <= (_Context->x_Auto1502+680+40) ) 
		&&  ( my <= (_Context->y_Auto1502+100+16))) {
			return(13); /* NbIndex */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+730) ) 
		&&  ( my >= (_Context->y_Auto1502+100) ) 
		&&  ( mx <= (_Context->x_Auto1502+730+16) ) 
		&&  ( my <= (_Context->y_Auto1502+100+18))) {
			return(14); /* Auto1507 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+360) ) 
		&&  ( my >= (_Context->y_Auto1502+140) ) 
		&&  ( mx <= (_Context->x_Auto1502+360+70) ) 
		&&  ( my <= (_Context->y_Auto1502+140+16))) {
			return(15); /* RecordType */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+580) ) 
		&&  ( my >= (_Context->y_Auto1502+120) ) 
		&&  ( mx <= (_Context->x_Auto1502+580+64) ) 
		&&  ( my <= (_Context->y_Auto1502+120+16))) {
			return(16); /* RecordSize */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+660) ) 
		&&  ( my >= (_Context->y_Auto1502+100) ) 
		&&  ( mx <= (_Context->x_Auto1502+660+16) ) 
		&&  ( my <= (_Context->y_Auto1502+100+18))) {
			return(17); /* Auto1509 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+680) ) 
		&&  ( my >= (_Context->y_Auto1502+120) ) 
		&&  ( mx <= (_Context->x_Auto1502+680+40) ) 
		&&  ( my <= (_Context->y_Auto1502+120+16))) {
			return(18); /* NbData */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+730) ) 
		&&  ( my >= (_Context->y_Auto1502+120) ) 
		&&  ( mx <= (_Context->x_Auto1502+730+16) ) 
		&&  ( my <= (_Context->y_Auto1502+120+18))) {
			return(19); /* Auto1510 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+580) ) 
		&&  ( my >= (_Context->y_Auto1502+140) ) 
		&&  ( mx <= (_Context->x_Auto1502+580+168) ) 
		&&  ( my <= (_Context->y_Auto1502+140+24))) {
			return(20); /* Accept */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+40) ) 
		&&  ( my >= (_Context->y_Auto1502+180) ) 
		&&  ( mx <= (_Context->x_Auto1502+40+700) ) 
		&&  ( my <= (_Context->y_Auto1502+180+100))) {
			if ((_Context->value_IndexMembers = ((visual_event(6) - (_Context->y_Auto1502+180)) / 16)) < 1)
				_Context->value_IndexMembers=0;
else if (_Context->value_IndexMembers > 5 )
				_Context->value_IndexMembers=5;
			if ( _Context->value_IndexMembers > 0 ) { _Context->row_IndexMembers = &_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0]; } 
			_Context->column_IndexMembers = (visual_event(7) - (_Context->x_Auto1502+40));
			if ( _Context->column_IndexMembers < 481 ) {
				_Context->column_IndexMembers = 1;
				}
			else if ( _Context->column_IndexMembers < 554 ) {
				_Context->column_IndexMembers = 2;
				}
			else if ( _Context->column_IndexMembers < 603 ) {
				_Context->column_IndexMembers = 3;
				}
			else if ( _Context->column_IndexMembers < 652 ) {
				_Context->column_IndexMembers = 4;
				}
			else if ( _Context->column_IndexMembers < 701 ) {
				_Context->column_IndexMembers = 5;
				}
			return(21); /* IndexMembers */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+740) ) 
		&&  ( my >= (_Context->y_Auto1502+180) ) 
		&&  ( mx <= (_Context->x_Auto1502+740+20) ) 
		&&  ( my <= (_Context->y_Auto1502+180+100))) {
			return(22); /* IndexBar */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+40) ) 
		&&  ( my >= (_Context->y_Auto1502+280) ) 
		&&  ( mx <= (_Context->x_Auto1502+40+700) ) 
		&&  ( my <= (_Context->y_Auto1502+280+290))) {
			if ((_Context->value_DataMembers = ((visual_event(6) - (_Context->y_Auto1502+280)) / 16)) < 1)
				_Context->value_DataMembers=0;
else if (_Context->value_DataMembers > 17 )
				_Context->value_DataMembers=17;
			if ( _Context->value_DataMembers > 0 ) { _Context->row_DataMembers = &_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0]; } 
			_Context->column_DataMembers = (visual_event(7) - (_Context->x_Auto1502+40));
			if ( _Context->column_DataMembers < 481 ) {
				_Context->column_DataMembers = 1;
				}
			else if ( _Context->column_DataMembers < 554 ) {
				_Context->column_DataMembers = 2;
				}
			else if ( _Context->column_DataMembers < 603 ) {
				_Context->column_DataMembers = 3;
				}
			else if ( _Context->column_DataMembers < 652 ) {
				_Context->column_DataMembers = 4;
				}
			else if ( _Context->column_DataMembers < 701 ) {
				_Context->column_DataMembers = 5;
				}
			return(23); /* DataMembers */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto1502+740) ) 
		&&  ( my >= (_Context->y_Auto1502+280) ) 
		&&  ( mx <= (_Context->x_Auto1502+740+20) ) 
		&&  ( my <= (_Context->y_Auto1502+280+290))) {
			return(24); /* DataBar */
			}
		}
	if (_Context->page_number == 2 ) {
		if ((mx >= _Context->x_TypeSelect ) 
		&&  (my >= _Context->y_TypeSelect ) 
		&&  (mx <  (_Context->x_TypeSelect+_Context->w_TypeSelect)) 
		&&  (my <  (_Context->y_TypeSelect+_Context->h_TypeSelect))) {
			return(25); /* TypeSelect */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto1502+20+128) ) 
		&&  ( my >= (_Context->y_Auto1502+40) ) 
		&&  ( mx <= (_Context->x_Auto1502+20+202) ) 
		&&  ( my <= (_Context->y_Auto1502+40+24))) {
			return(26); /* MaskPage */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1502+50) ) 
		&&  ( my >= (_Context->y_Auto1502+160) ) 
		&&  ( mx <= (_Context->x_Auto1502+50+688) ) 
		&&  ( my <= (_Context->y_Auto1502+160+16))) {
			return(27); /* Identifier */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1502+50) ) 
		&&  ( my >= (_Context->y_Auto1502+210) ) 
		&&  ( mx <= (_Context->x_Auto1502+50+688) ) 
		&&  ( my <= (_Context->y_Auto1502+210+16))) {
			return(28); /* Title */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1502+50+0) ) 
		&&  ( my >= (_Context->y_Auto1502+260) ) 
		&&  ( mx <= (_Context->x_Auto1502+50+200) ) 
		&&  ( my <= (_Context->y_Auto1502+260+16))) {
			return(29); /* Nature */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1502+270+0) ) 
		&&  ( my >= (_Context->y_Auto1502+260) ) 
		&&  ( mx <= (_Context->x_Auto1502+270+200) ) 
		&&  ( my <= (_Context->y_Auto1502+260+16))) {
			return(30); /* Language */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1502+640) ) 
		&&  ( my >= (_Context->y_Auto1502+260) ) 
		&&  ( mx <= (_Context->x_Auto1502+640+56) ) 
		&&  ( my <= (_Context->y_Auto1502+260+16))) {
			return(31); /* PageItems */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1502+50) ) 
		&&  ( my >= (_Context->y_Auto1502+300) ) 
		&&  ( mx <= (_Context->x_Auto1502+50+200) ) 
		&&  ( my <= (_Context->y_Auto1502+300+32))) {
			return(32); /* Auto1794 */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto1502+270) ) 
		&&  ( my >= (_Context->y_Auto1502+300) ) 
		&&  ( mx <= (_Context->x_Auto1502+270+200) ) 
		&&  ( my <= (_Context->y_Auto1502+300+30))) {
			return(33); /* Progress */
			}
		}

	return(-1);
}
private int on_FileList_losefocus(struct database_editor_context * _Context) {
	int l;
	struct file_control*fptr;
	l=_Context->value_FileList;
	if(l>0){
	l+=_Context->value_ScrollBar;
	if((fptr=locate_file(_Context, l))!=(struct file_control*)0){
	switch(_Context->column_FileList){
	case 1:
	if(fptr->classname)
	liberate(fptr->classname);
	fptr->classname=copystring(_Context, (_Context->row_FileList+0),33);
	break;
	case 2:
	if(fptr->identity)
	liberate(fptr->identity);
	fptr->identity=copystring(_Context, (_Context->row_FileList+33),33);
	break;
	}
	}
	}
	return(-1);
}
private int on_ClassName_losefocus(struct database_editor_context * _Context) {
	if(FileManager.current){
	reallocate(_Context,&FileManager.current->classname,_Context->buffer_ClassName,41);
	}
	return(-1);
}
private int on_Instance_losefocus(struct database_editor_context * _Context) {
	if(FileManager.current){
	reallocate(_Context,&FileManager.current->identity,_Context->buffer_Instance,41);
	}
	return(-1);
}
private int on_Filename_losefocus(struct database_editor_context * _Context) {
	if(FileManager.current){
	reallocate(_Context,&FileManager.current->filename,_Context->buffer_Filename,41);
	}
	return(-1);
}
private int on_FileType_losefocus(struct database_editor_context * _Context) {
	if(FileManager.current)
	FileManager.current->nature=_Context->value_FileType;
	return(-1);
}
private int on_IndexType_losefocus(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)){
	FileManager.current->payload->option&=~(_A_LEFT|_A_RIGHT);
	switch(_Context->value_IndexType){
	case 2:
	FileManager.current->payload->option|=_A_LEFT;
	break;
	case 3:
	FileManager.current->payload->option|=_A_RIGHT;
	break;
	}
	}
	return(-1);
}
private int on_IndexSize_losefocus(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)){
	FileManager.current->payload->indexlength=convert_integer(_Context, _Context->buffer_IndexSize,8);
	}
	return(-1);
}
private int on_RecordType_losefocus(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)){
	if(_Context->value_RecordType)
	FileManager.current->payload->option|=_A_BOLD;
	else FileManager.current->payload->option&=~_A_BOLD;
	}
	return(-1);
}
private int on_RecordSize_losefocus(struct database_editor_context * _Context) {
	if((FileManager.current)
	&&(FileManager.current->payload)){
	FileManager.current->payload->datalength=convert_integer(_Context, _Context->buffer_RecordSize,8);
	}
	return(-1);
}
private int on_IndexMembers_losefocus(struct database_editor_context * _Context) {
	struct data_control*dptr;
	int l;
	int i;
	l=_Context->value_IndexMembers;
	if(l>0){
	if((FileManager.current!=(struct file_control*)0)
	&&((dptr=FileManager.current->payload)!=(struct data_control*)0)){
	if ( l > 0 ) { _Context->row_IndexMembers=&_Context->buffer_IndexMembers[l-1][0]; } ;
	i=((l-1)+_Context->value_IndexBar);
	switch(_Context->column_IndexMembers){
	case 1:/*name*/
	reallocate(_Context,
	&dptr->name[i],
	(_Context->row_IndexMembers+0),
	60);
	break;
	case 2:/*type*/
	break;
	case 3:/*length*/
	dptr->width[i]=convert_integer(_Context, (_Context->row_IndexMembers+69),6);
	break;
	case 4:/*primary dimension*/
	dptr->first[i]=convert_integer(_Context, (_Context->row_IndexMembers+75),6);
	break;
	case 5:/*second dimension*/
	dptr->second[i]=convert_integer(_Context, (_Context->row_IndexMembers+81),6);
	break;
	}
	}
		database_editor_show(_Context);
;
	}
	return(-1);
}
private int on_DataMembers_losefocus(struct database_editor_context * _Context) {
	struct data_control*dptr;
	int l;
	int i;
	l=_Context->value_DataMembers;
	if(l>0){
	if((FileManager.current!=(struct file_control*)0)
	&&((dptr=FileManager.current->payload)!=(struct data_control*)0)){
	if ( l > 0 ) { _Context->row_DataMembers=&_Context->buffer_DataMembers[l-1][0]; } ;
	i=((l-1)+_Context->value_DataBar);
	switch(_Context->column_DataMembers){
	case 1:/*name*/
	reallocate(_Context,
	&dptr->name[i+dptr->indexfields],
	(_Context->row_DataMembers+0),
	60);
	break;
	case 2:/*type*/
	break;
	case 3:/*length*/
	dptr->width[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+69),6);
	break;
	case 4:/*primary dimension*/
	dptr->first[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+75),6);
	break;
	case 5:/*second dimension*/
	dptr->second[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+81),6);
	break;
	}
	}
		database_editor_show(_Context);
;
		}
		return(-1);
}


public	int	database_editor_losefocus(struct database_editor_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;

		}
	return(0);

}
private int on_IndexMembers_getfocus(struct database_editor_context * _Context) {
	int l;
	int i;
	struct data_control*dptr;
	if(_Context->column_IndexMembers==2){
	dptr=FileManager.current->payload;
	l=_Context->value_IndexMembers;
	if((i=((l-1)+_Context->value_IndexBar))<=dptr->indexfields){
	switch(dptr->type[i]){
	case _ABAL_BYTE:_Context->value_TypeSelect=0;break;
	case _ABAL_WORD:_Context->value_TypeSelect=1;break;
	case _ABAL_BCD:_Context->value_TypeSelect=2;break;
	case _ABAL_STRING:_Context->value_TypeSelect=3;break;
	case _ABAL_LONG:_Context->value_TypeSelect=4;break;
	}
	}
	else _Context->value_TypeSelect=0;
	_Context->y_TypeSelect=_Context->y_Auto1502+180+(l*16);
		if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect == 0)) {
		(void)visual_buffer_get(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=1;
		}
	if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect == 0)) {
		(void)visual_buffer_get(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=1;
		}
	visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),0);
;
		_Context->keycode = visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),2);
;
		if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=0;
		}
;
	if(i<=dptr->indexfields){
	switch(_Context->value_TypeSelect){
	case 0:dptr->type[i]=_ABAL_BYTE;break;
	case 1:dptr->type[i]=_ABAL_WORD;break;
	case 2:dptr->type[i]=_ABAL_BCD;break;
	case 3:dptr->type[i]=_ABAL_STRING;break;
	case 4:dptr->type[i]=_ABAL_LONG;break;
	}
		visual_table(_Context->x_Auto1502+40,_Context->y_Auto1502+180,700+2,100+2,vfh[1],0,0,_Context->msg_IndexMembers[_Context->language],_Context->buffer_IndexMembers,0x4401,"($,W8,N4Z,N4Z,N4Z)");
;
	}
	}
	else{
		_Context->row_IndexMembers = &_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0];
	switch (_Context->column_IndexMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+2),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),472,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0],59);
	visual_text((_Context->x_Auto1502+40+2),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),472,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0],59,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+482),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),64,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][60],8);
	visual_text((_Context->x_Auto1502+40+482),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][60],8,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+554),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][69],5);
	visual_text((_Context->x_Auto1502+40+554),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][69],5,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+602),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][75],5);
	visual_text((_Context->x_Auto1502+40+602),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][75],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+650),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][81],5);
	visual_text((_Context->x_Auto1502+40+650),(_Context->y_Auto1502+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][81],5,0);
		break;
		}
;
	}
	return(-1);
}
private int on_DataMembers_getfocus(struct database_editor_context * _Context) {
	int l;
	int i;
	struct data_control*dptr;
	if(_Context->column_DataMembers==2){
	dptr=FileManager.current->payload;
	l=_Context->value_DataMembers;
	if((i=((l-1)+_Context->value_DataBar))<=dptr->datafields){
	switch(dptr->type[i+dptr->indexfields]){
	case _ABAL_BYTE:_Context->value_TypeSelect=0;break;
	case _ABAL_WORD:_Context->value_TypeSelect=1;break;
	case _ABAL_BCD:_Context->value_TypeSelect=2;break;
	case _ABAL_STRING:_Context->value_TypeSelect=3;break;
	case _ABAL_LONG:_Context->value_TypeSelect=4;break;
	}
	}
	else _Context->value_TypeSelect=0;
	_Context->y_TypeSelect=_Context->y_Auto1502+280+(l*16);
		if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect == 0)) {
		(void)visual_buffer_get(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=1;
		}
	if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect == 0)) {
		(void)visual_buffer_get(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=1;
		}
	visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),0);
;
		_Context->keycode = visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),2);
;
		if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=0;
		}
;
	if(i<=dptr->datafields){
	switch(_Context->value_TypeSelect){
	case 0:dptr->type[i+dptr->indexfields]=_ABAL_BYTE;break;
	case 1:dptr->type[i+dptr->indexfields]=_ABAL_WORD;break;
	case 2:dptr->type[i+dptr->indexfields]=_ABAL_BCD;break;
	case 3:dptr->type[i+dptr->indexfields]=_ABAL_STRING;break;
	case 4:dptr->type[i+dptr->indexfields]=_ABAL_LONG;break;
	}
		visual_table(_Context->x_Auto1502+40,_Context->y_Auto1502+280,700+2,290+2,vfh[1],0,0,_Context->msg_DataMembers[_Context->language],_Context->buffer_DataMembers,0x4401,"($,W8,N4Z,N4Z,N4Z)");
;
	}
	}
	else{
		_Context->row_DataMembers = &_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0];
	switch (_Context->column_DataMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+2),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),472,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0],59);
	visual_text((_Context->x_Auto1502+40+2),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),472,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0],59,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+482),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),64,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][60],8);
	visual_text((_Context->x_Auto1502+40+482),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][60],8,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+554),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][69],5);
	visual_text((_Context->x_Auto1502+40+554),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][69],5,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+602),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][75],5);
	visual_text((_Context->x_Auto1502+40+602),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][75],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto1502+40+650),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][81],5);
	visual_text((_Context->x_Auto1502+40+650),(_Context->y_Auto1502+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][81],5,0);
		break;
		}
;
	}
	return(-1);
}


public	int	database_editor_focus(struct database_editor_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ListPage */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* FileList */
				if (_Context->page_number == 1 ) {
					_Context->row_FileList = &_Context->buffer_FileList[(_Context->value_FileList-1)][0];
					switch (_Context->column_FileList) {
					case	0x1 :
						_Context->keycode=visual_edit((_Context->x_Auto1502+30+2),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),256,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][0],32);
					visual_text((_Context->x_Auto1502+30+2),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),256,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][0],32,0);
						break;
					case	0x2 :
						_Context->keycode=visual_edit((_Context->x_Auto1502+30+266),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),256,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][33],32);
					visual_text((_Context->x_Auto1502+30+266),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),256,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][33],32,0);
						break;
					case	0x3 :
						_Context->keycode=visual_edit((_Context->x_Auto1502+30+530),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),80,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][66],10);
					visual_text((_Context->x_Auto1502+30+530),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),80,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][66],10,0);
						break;
					case	0x4 :
						_Context->keycode=visual_edit((_Context->x_Auto1502+30+618),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),80,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][77],10);
					visual_text((_Context->x_Auto1502+30+618),(_Context->y_Auto1502+80+(_Context->value_FileList*16)+2),80,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][77],10,0);
						break;
						}
					(void) on_FileList_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* FilePage */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x6 :
				/* ClassName */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+110+1,_Context->y_Auto1502+80+1,328,16,vfh[1],_Context->buffer_ClassName,41);
					(void) on_ClassName_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Instance */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+110+1,_Context->y_Auto1502+100+1,328,16,vfh[1],_Context->buffer_Instance,41);
					(void) on_Instance_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Filename */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+110+1,_Context->y_Auto1502+120+1,328,16,vfh[1],_Context->buffer_Filename,41);
					(void) on_Filename_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* FileType */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_Auto1502+110,_Context->y_Auto1502+140,96,64,vfh[1],0,28,parse_selection(WidgetDataList,&_Context->value_FileType),2);
					(void) on_FileType_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* IndexType */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_Auto1502+270,_Context->y_Auto1502+140,80,70,vfh[1],0,0,parse_selection(_Context->msg_IndexType[_Context->language],&_Context->value_IndexType),2);
					(void) on_IndexType_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* IndexSize */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+580+1,_Context->y_Auto1502+100+1,64,16,vfh[1],_Context->buffer_IndexSize,8);
					(void) on_IndexSize_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* Auto1525 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1525[_Context->language],strlen(_Context->msg_Auto1525[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1525[_Context->language],strlen(_Context->msg_Auto1525[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* Auto1507 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1507[_Context->language],strlen(_Context->msg_Auto1507[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1507[_Context->language],strlen(_Context->msg_Auto1507[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* RecordType */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto1502+360,_Context->y_Auto1502+140,70,16,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),(_Context->value_RecordType |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto1502+360,_Context->y_Auto1502+140,70,16,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),(_Context->value_RecordType |0));
					(void) on_RecordType_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* RecordSize */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+580+1,_Context->y_Auto1502+120+1,64,16,vfh[1],_Context->buffer_RecordSize,8);
					(void) on_RecordSize_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Auto1509 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1509[_Context->language],strlen(_Context->msg_Auto1509[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1509[_Context->language],strlen(_Context->msg_Auto1509[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* Auto1510 */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1510[_Context->language],strlen(_Context->msg_Auto1510[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1510[_Context->language],strlen(_Context->msg_Auto1510[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Accept */
				if (_Context->page_number == 2 ) {
					visual_button(_Context->x_Auto1502+580,_Context->y_Auto1502+140,168,24,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1502+580,_Context->y_Auto1502+140,168,24,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* IndexMembers */
				if (_Context->page_number == 2 ) {
					(void) on_IndexMembers_getfocus(_Context);
					(void) on_IndexMembers_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* DataMembers */
				if (_Context->page_number == 2 ) {
					(void) on_DataMembers_getfocus(_Context);
					(void) on_DataMembers_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* MaskPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1b :
				/* Identifier */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+50+1,_Context->y_Auto1502+160+1,688,16,vfh[1],_Context->buffer_Identifier,86);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* Title */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+50+1,_Context->y_Auto1502+210+1,688,16,vfh[1],_Context->buffer_Title,86);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* Nature */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_Auto1502+50,_Context->y_Auto1502+260,200,90,vfh[1],16,0,parse_selection(_Context->msg_Nature[_Context->language],&_Context->value_Nature),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* Language */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_Auto1502+270,_Context->y_Auto1502+260,200,90,vfh[1],16,0,parse_selection(_Context->msg_Language[_Context->language],&_Context->value_Language),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* PageItems */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto1502+640+1,_Context->y_Auto1502+260+1,56,16,vfh[1],_Context->buffer_PageItems,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* Auto1794 */
				if (_Context->page_number == 3 ) {
					visual_button(_Context->x_Auto1502+50,_Context->y_Auto1502+300,200,32,vfh[2],16,0,_Context->msg_Auto1794[_Context->language],strlen(_Context->msg_Auto1794[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(_Context->x_Auto1502+50,_Context->y_Auto1502+300,200,32,vfh[2],16,0,_Context->msg_Auto1794[_Context->language],strlen(_Context->msg_Auto1794[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
		switch (_Context->keycode) {
		case	0xc :
			database_editor_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			database_editor_show(_Context);
			continue;
		case	0x2 :
			database_editor_losefocus(_Context);
			_Context->page_number=3;
			_Context->focus_item=33;
			database_editor_show(_Context);
			continue;
		case	0x3 :
			database_editor_losefocus(_Context);
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			database_editor_show(_Context);
			continue;
		case	0x12 :
			database_editor_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			database_editor_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=database_editor_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto1502 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* ListPage */
						if (visual_event(1) & _MIMO_DOWN) {
							database_editor_losefocus(_Context);
							_Context->page_number = 1;
							database_editor_show(_Context);
							}
						continue;
					case	0x3 :
						/* FileList */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_FileList_event(_Context)) != -1) break;

							}
						continue;
					case	0x4 :
						/* ScrollBar */
						(void) on_ScrollBar_action(_Context);
						continue;
					case	0x5 :
						/* FilePage */
						if (visual_event(1) & _MIMO_DOWN) {
							database_editor_losefocus(_Context);
							_Context->page_number = 2;
							database_editor_show(_Context);
							}
						continue;
					case	0x6 :
						/* ClassName */
						continue;
					case	0x7 :
						/* Instance */
						continue;
					case	0x8 :
						/* Filename */
						continue;
					case	0x9 :
						/* FileType */
						continue;
					case	0xa :
						/* IndexType */
						continue;
					case	0xb :
						/* IndexSize */
						continue;
					case	0xc :
						/* Auto1525 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1525[_Context->language],strlen(_Context->msg_Auto1525[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1525[_Context->language],strlen(_Context->msg_Auto1525[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1525_event(_Context)) != -1) break;

							}
						continue;
					case	0xd :
						/* NbIndex */
						continue;
					case	0xe :
						/* Auto1507 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1507[_Context->language],strlen(_Context->msg_Auto1507[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1507[_Context->language],strlen(_Context->msg_Auto1507[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1507_event(_Context)) != -1) break;

							}
						continue;
					case	0xf :
						/* RecordType */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_RecordType += 1;
							_Context->value_RecordType &= 1;
							}
						continue;
					case	0x10 :
						/* RecordSize */
						continue;
					case	0x11 :
						/* Auto1509 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1509[_Context->language],strlen(_Context->msg_Auto1509[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1502+660,_Context->y_Auto1502+100,16,18,vfh[8],27,28,_Context->msg_Auto1509[_Context->language],strlen(_Context->msg_Auto1509[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1509_event(_Context)) != -1) break;

							}
						continue;
					case	0x12 :
						/* NbData */
						continue;
					case	0x13 :
						/* Auto1510 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1510[_Context->language],strlen(_Context->msg_Auto1510[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1502+730,_Context->y_Auto1502+120,16,18,vfh[8],27,28,_Context->msg_Auto1510[_Context->language],strlen(_Context->msg_Auto1510[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1510_event(_Context)) != -1) break;

							}
						continue;
					case	0x14 :
						/* Accept */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1502+580,_Context->y_Auto1502+140,168,24,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1502+580,_Context->y_Auto1502+140,168,24,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

							}
						continue;
					case	0x15 :
						/* IndexMembers */
						continue;
					case	0x16 :
						/* IndexBar */
						(void) on_IndexBar_action(_Context);
						continue;
					case	0x17 :
						/* DataMembers */
						continue;
					case	0x18 :
						/* DataBar */
						(void) on_DataBar_action(_Context);
						continue;
					case	0x19 :
						/* TypeSelect */
						continue;
					case	0x1a :
						/* MaskPage */
						if (visual_event(1) & _MIMO_DOWN) {
							database_editor_losefocus(_Context);
							_Context->page_number = 3;
							database_editor_show(_Context);
							}
						continue;
					case	0x1b :
						/* Identifier */
						continue;
					case	0x1c :
						/* Title */
						continue;
					case	0x1d :
						/* Nature */
						continue;
					case	0x1e :
						/* Language */
						continue;
					case	0x1f :
						/* PageItems */
						continue;
					case	0x20 :
						/* Auto1794 */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto1502+50,_Context->y_Auto1502+300,200,32,vfh[2],16,0,_Context->msg_Auto1794[_Context->language],strlen(_Context->msg_Auto1794[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto1502+50,_Context->y_Auto1502+300,200,32,vfh[2],16,0,_Context->msg_Auto1794[_Context->language],strlen(_Context->msg_Auto1794[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Auto1794_event(_Context)) != -1) break;

							}
						continue;
					case	0x21 :
						/* Progress */
						continue;
					case	0xffffffff :
					default :
						_Context->focus_item=1;
					continue;
					}
				break;
			case	0x1b :
			case	0xd :
				break;
			case	0x9 :
			case	0x5 :
			if ( _Context->focus_item < _Context->focus_items ) {
				_Context->focus_item++;			} else {
				_Context->focus_item=1;
			}
			continue;
			case	0xb :
			if ( _Context->focus_item > 1 ) {
				_Context->focus_item--;
			} else {
				_Context->focus_item=33;
			}
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) visual_getch();
	return(0);

}

public	int	database_editor()
{
	int	status=0;
	struct database_editor_context * _Context=(struct database_editor_context*) 0;
	status = database_editor_create(&_Context);
	if ( status != 0) return(status);
	status = database_editor_show(_Context);
		enter_modal();
	status = database_editor_focus(_Context);
		leave_modal();
	status = database_editor_hide(_Context);
	status = database_editor_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfile_c */
