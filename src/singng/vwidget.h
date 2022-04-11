#ifndef	_VWIDGET_H
#define	_VWIDGET_H

/*	------------------------------------------------------------	*/
/*	This file defines the symbolic data type codes used by the	*/
/*	forms generation transfer in/out mechanisms and the widget	*/
/*	type values as required by the COMBOBOX or SELECT mechanism.	*/
/*	------------------------------------------------------------	*/

#define	_HOTKEY_TRIGGER		'&'
#define	_LIST_FIELD		'|'

#define	_SYMBOLIC_VOID		' '
#define	_SYMBOLIC_BYTE		'B'
#define	_SYMBOLIC_WORD		'W'
#define	_SYMBOLIC_LONG		'L'
#define	_SYMBOLIC_FLOAT		'F'
#define	_SYMBOLIC_NUMERIC	'N'
#define	_SYMBOLIC_STRING	'S'
#define	_SYMBOLIC_KONSTANT	'K'
#define	_SYMBOLIC_POINTER 	'P'
#define	_SYMBOLIC_CLASS   	'C'
#define	_SYMBOLIC_OVERLAY	'O'
#define	_SYMBOLIC_TEXTFILE	'T'

#define	_WIDGET_PUBLIC		1
#define	_WIDGET_EXTERN		2

#define	_WIDGET_VOID		0	
#define	_WIDGET_BYTE		1	
#define	_WIDGET_WORD		2	
#define	_WIDGET_LONG		3	
#define	_WIDGET_FLOAT		4	
#define	_WIDGET_NUMERIC		5	
#define	_WIDGET_STRING		6	
#define	_WIDGET_KONSTANT	7	
#define	_WIDGET_POINTER		8	
#define	_WIDGET_CLASS  		9	
#define	_WIDGET_OVERLAY		10
#define	_WIDGET_TEXTFILE	11
#define	_WIDGET_MODULE		12
#define	_WIDGET_CHAIN		13
#define	_WIDGET_LOADGO		14
#define	_WIDGET_SYSTEM		15
#define	_WIDGET_HYPERLINK	16
#ifdef	ABAL32A
#define	_WIDGET_TASK     	17
#endif

#define	_FORM_BASIC 		0
#define	_FORM_EVENT   		1
#define	_FORM_SCROLL   		2
#define	_FORM_PRINT 		3

#define	_IMAGE_IS_BMP	 	0
#define	_IMAGE_IS_GIF		1
#define	_IMAGE_IS_JPG		2
#define	_IMAGE_IS_PNG		3

	/*	These constants are required by the Visual Form :		*/
	/*									*/
	/*		accept_widget_properties				*/
	/*									*/
	/*	For use in the relevant combo selection boxs			*/
	/*									*/

#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif

char	*	WidgetOptionList(int);
char	*	FormMethodList(int);
char	*	FormWidgetList(int);
char	*	WidgetPayload(int);
char	*	GetTextFontList();
char 	* 	GetWidgetStyle(int);
char	*	GetWindowVersion();
int		GetFontLabel(int,char *,int);
int		SetFontLabel(int,char *,int);

#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#ifdef	ABAL32A
#define	WidgetTypeList	 	"void|int8|int16|int32|float|numeric|string|constant|pointer|class|overlay|textfile|module|chain|loadgo|system|hyperlink|task"
#else
#define	WidgetTypeList	 	"void|int8|int16|int32|float|numeric|string|constant|pointer|class|overlay|textfile|module|chain|loadgo|system|hyperlink"
#endif

#define	WidgetAlignList	 	"none|right|left|center|justify"
#define	WidgetDataList		"variable|instance|visual|sifile|mcfile|vmemory|sqfile|dbfile"
#define	WidgetTabList		"standard|concave|convex"
#define	WidgetImageList	 	"none|right|left|center|tile|makefit|bestfit"
#define	WidgetScrollList	"none|right|left|both|slider|slider right|slider left|slider both"
#define	WidgetFillList		"block|frame|circle|disk|convex1|convex2|concave1|concave2|framed block|framed disk|framed convex|framed concave|shadow|roundedframe|roundedfill|relief|shaded|hole|shade convex 1|shade convex 2|shade concave 1|shade concave 2|shaded frame|shaded disk|shaded circle|shaded hole"
#define	WidgetButtonList	"framed text|framed image|text|image"
#define WidgetFormList		"white|zoned|coloured|colour zoned|columned|colour columned|chequered|colour chequered"

#define	WidgetClassList	 	"fill|outset|inset|ridge|groove|edit|text|image|line|button|window|tabpage|check|radio|select|table|scroll|progress|switch|graph|data"
#define	WidgetShowOptions 	"inline automatic|inline conditional|function automatic|function conditional"
#define	WidgetHideOptions 	"inline normal|inline popup|function normal|function popup"
#define	WidgetEventOptions 	"inline without event|inline with event|function without event|function with event"
#define	WidgetFocusOptions 	"inline without focus|inline with focus|function without focus|function with focus"
#define	WidgetSizesOptions 	"inline without sizes|inline with sizes|function without sizes|function with sizes"

#ifdef WIN32
#define	WidgetFileNames	"*.*|*.as|*.at|*.xml|*.htm|*.css|*.jpg|*.gif|*.png|*.bmp|*.ico|*.fmf|*.c|*.h|*.3d|*.sng|*.ani|*.rgb|*.cfg|*.exe|*.o|*.txt"
#define	en_WidgetFileNamesDescription	"All (*.*)|ABAL Source (*.as)|ABAL T-CODE (*.at)|Forms file (*.xml)|Help File (*.htm)|Style sheet file (*.css)|image file (*.jpg)|image file (*.gif)|image file (*.png)|image file (*.bmp)|icone file (*.ico)|fmf file (*.fmf)|c source code (*.c)|header c file source (*.h)|3d file (*.3d)|sng file (*.sng)|ani file (*.ani)|Palet file name (*.rgb)|sing config file (*.cfg)|Windows Program (*.exe)|Abal modules (*.o)|Text Files (*.txt)"
#define	fr_WidgetFileNamesDescription	"Tous (*.*)|Source ABAL (*.as)|T-CODE ABAL (*.at)|fichier formulaire (*.xml)|Fichier d'aide (*.htm)|feuille de style (*.css)|fichier image (*.jpg)|fichier image (*.gif)|fichier image (*.png)|fichier image (*.bmp)|fichier icone (*.ico)|fichier fmf (*.fmf)|source code c (*.c)|fichier entete C (*.h)|fichier 3d (*.3d)|fichier sng (*.sng)|fichier ani (*.ani)|fichier palettes (*.rgb)|configuration sing (*.cfg)|Programes windows (*.exe)|Modules ABAL (*.o)|Fichiers texte (*.txt)"
#else
#define	WidgetFileNames	"*|*.as|*.at|*.xml|*.htm|*.css|*.jpg|*.gif|*.png|*.bmp|*.ico|*.fmf|*.c|*.h|*.3d|*.sng|*.ani|*.rgb|*.cfg|*.exe|*.obj|*"
#endif

#define	WIDGET_FILE_ANY	0
#define	WIDGET_FILE_AS  1
#define	WIDGET_FILE_AT  2
#define	WIDGET_FILE_XML 3
#define	WIDGET_FILE_HTM 4
#define	WIDGET_FILE_CSS 5
#define	WIDGET_FILE_JPG 6
#define	WIDGET_FILE_GIF	7
#define	WIDGET_FILE_PNG 8
#define	WIDGET_FILE_BMP 9
#define	WIDGET_FILE_ICO 10
#define	WIDGET_FILE_FMF 11
#define	WIDGET_FILE_C   12
#define	WIDGET_FILE_H   13
#define	WIDGET_FILE_3D  14
#define	WIDGET_FILE_SNG 15
#define	WIDGET_FILE_ANI 16
#define WIDGET_FILE_RGB 17
#define WIDGET_FILE_CFG 18
#define WIDGET_FILE_EXE 19
#define WIDGET_FILE_OBJ 20
#define WIDGET_FILE_TXT 21
#define	WIDGET_FILE_LIMIT 22

#define	_WINDOW_EXIT_BUTTON	1
#define	_WINDOW_HELP_BUTTON	2
#define	_WINDOW_LANG_BUTTON	4
#define	_WINDOW_MINIMIZE	8
#define	_WINDOW_MAXIMIZE	16

#define	WidgetPaperTypes	"A4|A3|A2|A1|A0|A10|A9|A8|A7|A6|A5|B10|B9|B8|B7|B6|B5|B4|B3|B2|B1|B0"
#define	WidgetPrintResolution	"text|75 dpi|100 dpi|150 dpi|300 dpi|600 dpi|1200 dpi"

/* The widget class list will be added the |form item at the end very soon */

#define	FormTypeList "Dialog Box|Event Driven|HQ Document|Draft Document"

#define	ProductionLanguageList	production_languages()
#ifdef	ABAL34A
#define ProductionLanguages "Abal|Abal++|Html|C|C++|Cobol|Java"
#else
#define ProductionLanguages "Abal|Abal++|Html|C|C++"
#endif

#define	NationalLanguageList "English|Fran‡ais|Italiano|Espagnol|Deutsch|Nederlands|Portugues|Other"

#define ImageFormatList "BMP|GIF|JPEG|PNG"
#define TextFontList 	GetTextFontList()
#define	FontFileList	GetFontFileList()
#define	TEXTFONTLIST	"Edit Font|Proportional|Font 3|Font 4|Font 5|Font 6|Font 7|Small Font|Font 9|Font 10|Font11|Font12|Font13|Font14|Font15|Font16"

#define	WidgetMethodNature "method|constructor|destructor"
#define	CicoColourList	"black|red|green|brown|blue|purple|cyan|grey|dark|pink|lime|yellow|blue|purple|sky|white"

#define	VisualSkin system_skin

#ifdef __cplusplus	/* GWB le 05/06/207 */
extern "C" {
#endif
char * production_languages();
char * WidgetMessage(int,int);
char * GetPathSelection();

extern	char * VisualSkin;

#ifdef __cplusplus	/* GWB le 05/06/207 */
}
#endif

#ifdef	UNIX
/* ----------------------------------------  */
/* Gerard il n y a pas de stricmp sous LINUX */
/* Il faut penser de verifier quand tu fait  */
/* trop de WINDOWS on oublie !!!	     */
/* ----------------------------------------  */
#define	stricmp(a,b) strcmp(a,b)
#define	memicmp(a,b,c)	memcmp(a,b,c)
#define	Conv(a) atoi(a)
#endif

#endif	/* _VWIDGET_H */

