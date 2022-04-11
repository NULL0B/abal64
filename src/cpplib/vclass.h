/* --------------------------------------- */
/* classes de bases pour la production C++ */
/* --------------------------------------- */
#ifndef _VCLASS_H
#define _VCLASS_H
#include "vform.h"

class class_visual_container;
class visual_object;
#if defined(WIN32)
#include <windows.h>
#endif
#include <stdio.h>
#include "singprot.h"
#include "sing.h"

#undef public

/* ------------------------------- */
/*                                 */
/* définitions pour classes object */
/*                                 */
/* ------------------------------- */
class class_visual_position
{
// Attributes
public:
	int x;
	int y;
	int movable;
	class_visual_position(int px=0,int py=0,int pmovable=1);
	~class_visual_position();

	virtual void AddToPosition(int nx,int ny);
	virtual void position_at(int nx,int ny);
	void SetMovable(int pmovable=1);
};

class class_visual_size
{
// construction
public:
	class_visual_size(int ph=0,int pw=0);
	~class_visual_size();
	int h;
	int w;
};

class class_visual_rect : public class_visual_position,public class_visual_size
{
public:
	int save;
	STDPSUPTR psave;

	class_visual_rect(int px=0,int py=0,int pmovable=1,int ph=0,int pw=0);
	~class_visual_rect();
	void SetPopUp(int ppopup=1,int adjust=2);
	void ObjPopUp();
	void ObjPopDown();
	void DropSaver();
};

class class_visual_style
{
public:
	char *StyleName;
	class class_visual_style *next;

	class_visual_style(char *pStyleName,class_visual_style *previous);
	~class_visual_style();
	int apply_style(int x,int y,int w,int h,char *lib);
};

class class_visual_colour
{
public:
	int fg;
	int bg;
	
	class_visual_colour(int pfg=1,int pbg=0);
	~class_visual_colour();

};

class class_visual_font
{
public:
	int font;
	char *fname;

	class_visual_font(char *pfname=NULL);
	~class_visual_font();
	int charger_fonte(char *pfname);
	int GetFont();
};

/* ---------------------------- */
/*                              */
/* définitions classes méthodes */
/*                              */
/* ---------------------------- */
extern "C" {
struct virtual_method_pointer {
	int (*VMP)(void *_THIS);
	void *_THIS;
};
};

#define METHOD_ATTACHE(o,m,f,po) { \
	char t[60]; \
	sprintf(t,"%lu",f); \
	void *tp=(void *)atol(t); \
	o->m.attache((int (*)(void *))tp,(void *)po); }

#define POINTER_ATTACHE(o,f,po) { \
	char t[60]; \
	sprintf(t,"%lu",f); \
	void *tp=(void *)atol(t); \
	o->attache((int (*)(void *))tp,(void *)po); }

class class_visual_method_interface {
	struct virtual_method_pointer method;
	int fonction_vide();

public:
	class_visual_method_interface();
	~class_visual_method_interface();
	void attache(int (*vmp)(void *_THIS),void *v);
	int Invoke();
};

class class_visual_widget_interface {
public:
	class_visual_method_interface MethodOnCreate;
	class_visual_method_interface MethodOnShow;
	class_visual_method_interface MethodOnEvent;
	class_visual_method_interface MethodOnFocus;
	class_visual_method_interface MethodOnHide;
	class_visual_method_interface MethodOnRemove;
	class_visual_method_interface MethodOnLoseFocus;
	class_visual_method_interface MethodOnHelp;
};

/* ---------------------------- */
/*                              */
/*       définition object      */
/*                              */
/* ---------------------------- */
class class_visual_object : public class_visual_rect,public class_visual_colour,public class_visual_widget_interface {
public:
	class_visual_object(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1);
	~class_visual_object();


	char *msg[8];
	char *hint[8];
	int focus;
	int trigger;
	char *payload;
	
	class_visual_font *fontclass;

	class_visual_style *StyleSheet;
	class_visual_style *StyleFocus;

	class_visual_object *previous;
	class_visual_object *next;
	class_visual_container *pere;

	virtual int OnCreate();
	virtual int OnShow();
	virtual int OnFocusShow();
	virtual int OnEvent();
	virtual int OnFocus();
	virtual int OnHide();
	virtual int OnRemove();
	virtual int OnLoseFocus();


	class_visual_style *FindLastStyle(class_visual_style *pStyle);
	void AddStyleSheet(char *lib);
	void AddStyleFocus(char *lib);
	int fonc_visual_element(char *lib=NULL,int with_focus=0);
	void SetPayload(char *ppayload);
};



/* --------------------------- */
/*                             */
/* définitions widgets de base */
/*                             */
/* --------------------------- */
class class_visual_fill : public class_visual_object {
public:
	int align;

	class_visual_fill(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,int palign=0);
	~class_visual_fill();
	int OnShow();
	int OnFocus();
};

class class_visual_frame : public class_visual_object {
public:
	class_visual_frame(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,int pstyle=0,char *ppayload=NULL,int palign=0);
	~class_visual_frame();
	int OnShow();
	int OnFocus();
	int style;
	int align;
};

class class_visual_edit : public class_visual_object {
public:
	char *buffer;
	int tbuff;
	int tlig;
	int nlig;
	int style;
	int datatype;
	int align;
	class_visual_edit(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,int pstyle=0,int pdatatype=1,int palign=0,int ptbuff=1,int ptlig=1,int pnlig=1);
	~class_visual_edit();
	int OnShow();
	int OnFocus();
};

class class_visual_text : public class_visual_object {
public:
	int align;
	class_visual_text(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *ppayload=NULL,int palign=0);
	~class_visual_text();
	int OnShow();
	int OnFocus();
};


class class_visual_image : public class_visual_object {
public:
	int align;
	class_visual_image(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *ppayload=NULL,int palign=0);
	~class_visual_image();
	int OnShow();
	int OnFocus();
};

class class_visual_line : public class_visual_object {
public:
	int size;
	class_visual_line(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,int psize=1);
	~class_visual_line();
	int OnShow();
	int OnFocus();
	void AddToPosition(int nx,int ny);
};

class class_visual_button : public class_visual_object {
public:
	int align;
	int etat;
	class_visual_button(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *ppayload=NULL,int palign=0,int petat=0);
	~class_visual_button();
	int OnShow();
	int OnFocusShow();
	int OnFocus();
};

class class_visual_window : public class_visual_object {
public:
	int align;
	int multilang;
	class_visual_window(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,int palign=0,int pmultilang=0);
	~class_visual_window();
	int OnShow();
	int OnFocus();
};

class class_visual_tabpage : public class_visual_object {
public:
	int align;
	int adjust;
	class_visual_tabpage(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,int palign=0,int padjust=0);
	~class_visual_tabpage();
	int OnShow();
	int OnFocusShow();
	int OnFocus();
};

class class_visual_check : public class_visual_object {
public:
	int align;
	int value;
	class_visual_check(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,int palign=0,int pvalue=0);
	~class_visual_check();
	int OnShow();
	int OnFocusShow();
	int OnFocus();
};

class class_visual_radio : public class_visual_object {
public:
	int align;
	int *value;
	int radio;
	class_visual_radio(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,int pradio=0,int *pvalue=NULL);
	~class_visual_radio();
	int OnShow();
	int OnFocus();
};

class class_visual_select : public class_visual_object {
public:
	int value;
	int align;
	int special;
	class_visual_select(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,int pvalue=0,int palign=0,int pspecial=0);
	~class_visual_select();
	int OnShow();
	int OnFocus();
};

class class_visual_form : public class_visual_object {
public:
	int value;
	char *buffer;
	int align;
	int datatype;
	int nlig;
	int tlig;
	int formsort;				/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char *libsort;				/* table intermédiaire contenant la liste des éléments a trier */
	int *tab_sort;				/* numéro d'ordre des elements triés */
	char *indsort;				/* pointeur table intermédiaire de tri */
	int nelt;					/* nombre d'eléments aloués dans tab_sort */
	char *row;
	int fields;					/* nombre de champs */
	int	fieldwidth[_MAX_FORM_FIELDS];	/* table des tailles de champs */
	int	fieldpos[_MAX_FORM_FIELDS];		/* table des adresses de champs */
	int ncol;					/* numro de colonne */
	char *format;

	int compare(int a,int b);	/* compare the elements a et b of libsort */
	char *column(int ncol);	/* select the adresse of column to fill */
	
	void sort(int nelts);		/* sort the intermediate table into tab_sort */
	int tabsort(int nelts);		/* returns resolved sort item */
	void linesort(int nelts);	/* select the linesort to fill */
	void line(int nelts);		/* select the line to fill */
	void startsort(int nelts);	/* allocate intermediate sort table */
	void init_column(int col);
	class_visual_form(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=0,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,char *pformat=NULL,int palign=0,int pdatatype=0,int pnlig=1,int ptlig=1,int pfields=0,int pfieldwidth[_MAX_FORM_FIELDS]=0);
	~class_visual_form();
	int OnShow();
	int OnFocus();
};

class class_visual_scroll : public class_visual_object {
public:
	int value;
	int limit;
	int max;
	int align;
	class_visual_scroll(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,int pvalue=0,int plimit=0,int pmax=0,int palign=0);
	~class_visual_scroll();
	void limitmin();
	void limitmax();
	void limits();
	void visual_widget(int focus);
	int OnShow();
	int OnFocusShow();
	int OnFocus();
};

class class_visual_progress : public class_visual_object {
public:
	int value;
	int limit;
	class_visual_progress(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,int pvalue=0,int plimit=0);
	~class_visual_progress();
	int OnShow();
	int OnFocus();
};

class class_visual_switch : public class_visual_object {
public:
	int align;
	int value;
	class_visual_switch(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,int palign=0,int pvalue=0);
	~class_visual_switch();
	int OnShow();
	int OnFocusShow();
	int OnFocus();
};

class class_visual_graph : public class_visual_object {
public:
	int value;
	class_visual_graph(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1,char *payload=NULL,int pvalue=0);
	~class_visual_graph();
	int OnShow();
	int OnFocus();
};

class class_visual_data : public class_visual_object {
public:
	class_visual_data(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1);
	~class_visual_data();
	int OnShow();
	int OnFocus();
};


/* --------------------------------- */
/*                                   */
/* définition container (formulaire) */
/*                                   */
/* --------------------------------- */

class class_visual_container : public class_visual_object {
public:
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	language;
	int	*focus_pages;
	int page_number;
	char *signature;
	class_visual_font *vfh[FONT_MAX];
	class_visual_object *premier_fils;
	class_visual_object *dernier_fils;

	class_visual_container(int px=0,int py=0,int ph=0,int pw=0,int pfg=1,int pbg=0,class_visual_font *pfontclass=NULL,class_visual_container *ppere=NULL,int pfocus=1,class_visual_object *pprevious=NULL,int pmovable=1);
	~class_visual_container();
	int detect_trigger_events();
	void AddToPosition(int nx,int ny);
	virtual void position_at(int nx,int ny);
	void allocate_signature(char *texte);
	void allocate_focus_pages(int taille);
	virtual int stdinput();
	virtual int OnExec();
	int OnFocusShow();
	int form_help(int pfocus);
	virtual void info_special(int n,void *r);
};




#define public

#endif


