;** ------------------------------------------------------------------------- 
;** Warning : this file has been generated and should not be modified by hand 
;** ------------------------------------------------------------------------- 
;** Sing Version   : 2.1a.0.33  
;** Production     : ABAL  
;** Project        : singedit.xml  
;** Target         : singedit.c  
;** Identification : 0.0-1187889906-9142.9141 
;** ------------------------------------------------------------------------- 
#pragma ignore_case on
#pragma optimise tables off
#pragma tokensize 64
#user "visual.def"
Program "On",NOCLR
#include "mimo.as"
#include "visidef.as"
;** Widget Message Constants 
Const en_Auto960$=" "
Const fr_Auto960$=" "
Const it_Auto960$=" "
Const es_Auto960$=" "
Const de_Auto960$=" "
Const nl_Auto960$=" "
Const pt_Auto960$=" "
Const xx_Auto960$=" "
Const en_Auto961$=" "
Const fr_Auto961$=" "
Const it_Auto961$=" "
Const es_Auto961$=" "
Const de_Auto961$=" "
Const nl_Auto961$=" "
Const pt_Auto961$=" "
Const xx_Auto961$=" "
Const en_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const fr_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const it_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const es_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const de_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const nl_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const pt_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const xx_EditorText$="/home/Dev/abal32/sing/editer.gif"
Const en_Auto962$=" "
Const fr_Auto962$=" "
Const it_Auto962$=" "
Const es_Auto962$=" "
Const de_Auto962$=" "
Const nl_Auto962$=" "
Const pt_Auto962$=" "
Const xx_Auto962$=" "
Const en_Auto963$=" "
Const fr_Auto963$=" "
Const it_Auto963$=" "
Const es_Auto963$=" "
Const de_Auto963$=" "
Const nl_Auto963$=" "
Const pt_Auto963$=" "
Const xx_Auto963$=" "
Const en_ToolBarControl$="downicon.gif"
Const fr_ToolBarControl$="downicon.gif"
Const it_ToolBarControl$="downicon.gif"
Const es_ToolBarControl$="downicon.gif"
Const de_ToolBarControl$="downicon.gif"
Const nl_ToolBarControl$="downicon.gif"
Const pt_ToolBarControl$="downicon.gif"
Const xx_ToolBarControl$="downicon.gif"
Const en_Auto964$=" "
Const fr_Auto964$=" "
Const it_Auto964$=" "
Const es_Auto964$=" "
Const de_Auto964$=" "
Const nl_Auto964$=" "
Const pt_Auto964$=" "
Const xx_Auto964$=" "
Const en_PaletteControl$="downicon.gif"
Const fr_PaletteControl$="downicon.gif"
Const it_PaletteControl$="downicon.gif"
Const es_PaletteControl$="downicon.gif"
Const de_PaletteControl$="downicon.gif"
Const nl_PaletteControl$="downicon.gif"
Const pt_PaletteControl$="downicon.gif"
Const xx_PaletteControl$="downicon.gif"
Const en_File$="&File"
Const fr_File$="&Fichier"
Const it_File$="&Fichero"
Const es_File$="&Fichero"
Const de_File$="&Datei"
Const nl_File$="&File"
Const pt_File$="&File"
Const xx_File$="&File"
Const en_Auto965$=" "
Const fr_Auto965$=" "
Const it_Auto965$=" "
Const es_Auto965$=" "
Const de_Auto965$=" "
Const nl_Auto965$=" "
Const pt_Auto965$=" "
Const xx_Auto965$=" "
Const en_New$="&New"
Const fr_New$="&Nouveau"
Const it_New$="&Nuevo"
Const es_New$="&Nuevo"
Const de_New$="&Neu"
Const nl_New$="&New"
Const pt_New$="&New"
Const xx_New$="&New"
Const en_Save$="&Save"
Const fr_Save$="&Enregistrer"
Const it_Save$="&Salver"
Const es_Save$="&Salvar"
Const de_Save$="&Schreiben"
Const nl_Save$="&Save"
Const pt_Save$="&Save"
Const xx_Save$="&Save"
Const en_SaveAs$="Sa&ve As"
Const fr_SaveAs$="En&registrer sous"
Const it_SaveAs$="Sal&ver"
Const es_SaveAs$="Sal&ver"
Const de_SaveAs$="Zuschreiben"
Const nl_SaveAs$="Sa&ve As"
Const pt_SaveAs$="Sa&ve As"
Const xx_SaveAs$="Sa&ve As"
Const en_Open$="&Open"
Const fr_Open$="&Ouvrir"
Const it_Open$="&Open"
Const es_Open$="&Abiert&o"
Const de_Open$="&Ofnen"
Const nl_Open$="&Open"
Const pt_Open$="&Open"
Const xx_Open$="&Open"
Const en_Production$="&Production"
Const fr_Production$="&Production"
Const it_Production$="&Production"
Const es_Production$="&Produccion"
Const de_Production$="&Produktion"
Const nl_Production$="&Production"
Const pt_Production$="&Production"
Const xx_Production$="&Production"
Const en_Drop$="&Drop"
Const fr_Drop$="&Fermer"
Const it_Drop$="DROP"
Const es_Drop$="&Cerrado"
Const de_Drop$="&Ziehen"
Const nl_Drop$="DROP"
Const pt_Drop$="DROP"
Const xx_Drop$="DROP"
Const en_Quit$="&Quit"
Const fr_Quit$="&Quitter"
Const it_Quit$="&Quit"
Const es_Quit$="&Abandonar"
Const de_Quit$="&Ausgang"
Const nl_Quit$="&Quit"
Const pt_Quit$="&Quit"
Const xx_Quit$="&Quit"
Const en_View$="&View"
Const fr_View$="&Visualiser"
Const it_View$="&View"
Const es_View$="&View"
Const de_View$="&View"
Const nl_View$="&View"
Const pt_View$="&View"
Const xx_View$="&View"
Const en_Auto966$=" "
Const fr_Auto966$=" "
Const it_Auto966$=" "
Const es_Auto966$=" "
Const de_Auto966$=" "
Const nl_Auto966$=" "
Const pt_Auto966$=" "
Const xx_Auto966$=" "
Const en_Run$="&Run"
Const fr_Run$="&Ex‚cution"
Const it_Run$="&Run"
Const es_Run$="&Run"
Const de_Run$="&Run"
Const nl_Run$="&Run"
Const pt_Run$="&Run"
Const xx_Run$="&Run"
Const en_Text$="Te&xt"
Const fr_Text$="Te&xte"
Const it_Text$="Te&xt"
Const es_Text$="Te&xt"
Const de_Text$="Te&xt"
Const nl_Text$="Te&xt"
Const pt_Text$="Te&xt"
Const xx_Text$="Te&xt"
Const en_Image$="&Image"
Const fr_Image$="&Image"
Const it_Image$="&Image"
Const es_Image$="&Image"
Const de_Image$="&Image"
Const nl_Image$="&Image"
Const pt_Image$="&Image"
Const xx_Image$="&Image"
Const en_Font$="Fo&nt"
Const fr_Font$="&Fonte"
Const it_Font$="&Font"
Const es_Font$="&Font"
Const de_Font$="&Font"
Const nl_Font$="&Font"
Const pt_Font$="&Font"
Const xx_Font$="&Font"
Const en_Properties$="&Properties"
Const fr_Properties$="&Propri‚t‚s"
Const it_Properties$="&Properties"
Const es_Properties$="&Properties"
Const de_Properties$="&Properties"
Const nl_Properties$="&Properties"
Const pt_Properties$="&Properties"
Const xx_Properties$="&Properties"
Const en_Visual$="&Visual"
Const fr_Visual$="&Visuel"
Const it_Visual$="screener"
Const es_Visual$="screener"
Const de_Visual$="screener"
Const nl_Visual$="screener"
Const pt_Visual$="screener"
Const xx_Visual$="screener"
Const en_TreeView$="Tr&eeView"
Const fr_TreeView$="Arborescence"
Const it_TreeView$="Tr&eeView"
Const es_TreeView$="Tr&eeView"
Const de_TreeView$="Tr&eeView"
Const nl_TreeView$="Tr&eeView"
Const pt_TreeView$="Tr&eeView"
Const xx_TreeView$="Tr&eeView"
Const en_Application$="&Application"
Const fr_Application$="&Application"
Const it_Application$="&Application"
Const es_Application$="&Application"
Const de_Application$="&Application"
Const nl_Application$="&Application"
Const pt_Application$="&Application"
Const xx_Application$="&Application"
Const en_Event$="&Event"
Const fr_Event$="&Ev‚nement"
Const it_Event$="&Event"
Const es_Event$="&Event"
Const de_Event$="&Event"
Const nl_Event$="&Event"
Const pt_Event$="&Event"
Const xx_Event$="&Event"
Const en_Options$="&Options"
Const fr_Options$="&Options"
Const it_Options$="&Options"
Const es_Options$="&Options"
Const de_Options$="&Options"
Const nl_Options$="&Options"
Const pt_Options$="&Options"
Const xx_Options$="&Options"
Const en_Auto967$=" "
Const fr_Auto967$=" "
Const it_Auto967$=" "
Const es_Auto967$=" "
Const de_Auto967$=" "
Const nl_Auto967$=" "
Const pt_Auto967$=" "
Const xx_Auto967$=" "
Const en_Parameters$="&Parameters"
Const fr_Parameters$="&ParamŠtres"
Const it_Parameters$="&Parameters"
Const es_Parameters$="&Parameters"
Const de_Parameters$="&Parameters"
Const nl_Parameters$="&Parameters"
Const pt_Parameters$="&Parameters"
Const xx_Parameters$="&Parameters"
Const en_Refresh$="&Refresh"
Const fr_Refresh$="&R‚afficher"
Const it_Refresh$="&Refresh"
Const es_Refresh$="&Refresh"
Const de_Refresh$="&Refresh"
Const nl_Refresh$="&Refresh"
Const pt_Refresh$="&Refresh"
Const xx_Refresh$="&Refresh"
Const en_Configure$="&Configure"
Const fr_Configure$="&Configurer"
Const it_Configure$="&Configure"
Const es_Configure$="&Configure"
Const de_Configure$="&Configure"
Const nl_Configure$="&Configure"
Const pt_Configure$="&Configure"
Const xx_Configure$="&Configure"
Const en_ScreenCapture$="&Screen Capture"
Const fr_ScreenCapture$="&Capture Ecran"
Const it_ScreenCapture$="&Screen Capture"
Const es_ScreenCapture$="&Screen Capture"
Const de_ScreenCapture$="&Screen Capture"
Const nl_ScreenCapture$="&Screen Capture"
Const pt_ScreenCapture$="&Screen Capture"
Const xx_ScreenCapture$="&Screen Capture"
Const en_Animate$="&Animate"
Const fr_Animate$="&Animer"
Const it_Animate$="&Animate"
Const es_Animate$="&Animate"
Const de_Animate$="&Animate"
Const nl_Animate$="&Animate"
Const pt_Animate$="&Animate"
Const xx_Animate$="&Animate"
Const en_Editor$="&Editor"
Const fr_Editor$="&Editeur"
Const it_Editor$="&Editor"
Const es_Editor$="&Editor"
Const de_Editor$="&Editor"
Const nl_Editor$="&Editor"
Const pt_Editor$="&Editor"
Const xx_Editor$="&Editor"
Const en_Auto968$=" "
Const fr_Auto968$=" "
Const it_Auto968$=" "
Const es_Auto968$=" "
Const de_Auto968$=" "
Const nl_Auto968$=" "
Const pt_Auto968$=" "
Const xx_Auto968$=" "
Const en_Find$="&Find"
Const fr_Find$="&Rechercher"
Const it_Find$="&Find"
Const es_Find$="&Find"
Const de_Find$="&Find"
Const nl_Find$="&Find"
Const pt_Find$="&Find"
Const xx_Find$="&Find"
Const en_Replace$="&Replace"
Const fr_Replace$="&Remplacer"
Const it_Replace$="&Replace"
Const es_Replace$="&Replace"
Const de_Replace$="&Replace"
Const nl_Replace$="&Replace"
Const pt_Replace$="&Replace"
Const xx_Replace$="&Replace"
Const en_Syntax$="S&yntax"
Const fr_Syntax$="S&yntaxe"
Const it_Syntax$="S&yntax"
Const es_Syntax$="S&yntax"
Const de_Syntax$="S&yntax"
Const nl_Syntax$="S&yntax"
Const pt_Syntax$="S&yntax"
Const xx_Syntax$="S&yntax"
Const en_Search$="&Search"
Const fr_Search$="&Search"
Const it_Search$="Locat&e"
Const es_Search$="Locat&e"
Const de_Search$="Locat&e"
Const nl_Search$="Locat&e"
Const pt_Search$="Locat&e"
Const xx_Search$="Locat&e"
Const en_Trace$="&Trace"
Const fr_Trace$="&Trace"
Const it_Trace$="&Trace"
Const es_Trace$="&Trace"
Const de_Trace$="&Trace"
Const nl_Trace$="&Trace"
Const pt_Trace$="&Trace"
Const xx_Trace$="&Trace"
Const en_Auto969$=" "
Const fr_Auto969$=" "
Const it_Auto969$=" "
Const es_Auto969$=" "
Const de_Auto969$=" "
Const nl_Auto969$=" "
Const pt_Auto969$=" "
Const xx_Auto969$=" "
Const en_InsertSwitch$="INS"
Const fr_InsertSwitch$="INS"
Const it_InsertSwitch$="INS"
Const es_InsertSwitch$="INS"
Const de_InsertSwitch$="INS"
Const nl_InsertSwitch$="INS"
Const pt_InsertSwitch$="INS"
Const xx_InsertSwitch$="INS"
Const en_SelectSwitch$="SEL"
Const fr_SelectSwitch$="SEL"
Const it_SelectSwitch$="SEL"
Const es_SelectSwitch$="SEL"
Const de_SelectSwitch$="SEL"
Const nl_SelectSwitch$="SEL"
Const pt_SelectSwitch$="SEL"
Const xx_SelectSwitch$="SEL"
Const en_LineNumber$=" "
Const fr_LineNumber$=" "
Const it_LineNumber$=" "
Const es_LineNumber$=" "
Const de_LineNumber$=" "
Const nl_LineNumber$=" "
Const pt_LineNumber$=" "
Const xx_LineNumber$=" "
Const en_Executeur$="vdbicon.gif"
Const fr_Executeur$="vdbicon.gif"
Const it_Executeur$="vdbicon.gif"
Const es_Executeur$="vdbicon.gif"
Const de_Executeur$="vdbicon.gif"
Const nl_Executeur$="vdbicon.gif"
Const pt_Executeur$="vdbicon.gif"
Const xx_Executeur$="vdbicon.gif"
Const en_First$="&First"
Const fr_First$="P&remier"
Const it_First$="&First"
Const es_First$="&First"
Const de_First$="&First"
Const nl_First$="&First"
Const pt_First$="&First"
Const xx_First$="&First"
Const en_Previous$="&Previous"
Const fr_Previous$="&Pr‚c‚dent"
Const it_Previous$="&Previous"
Const es_Previous$="&Previous"
Const de_Previous$="&Previous"
Const nl_Previous$="&Previous"
Const pt_Previous$="&Previous"
Const xx_Previous$="&Previous"
Const en_Widget$="&Widget"
Const fr_Widget$="&El‚ment graphique(Widget)"
Const it_Widget$="&Widget"
Const es_Widget$="&Widget"
Const de_Widget$="&Widget"
Const nl_Widget$="&Widget"
Const pt_Widget$="&Widget"
Const xx_Widget$="&Widget"
Const en_Method$="&Method"
Const fr_Method$="&M‚thode"
Const it_Method$="&Method"
Const es_Method$="&Method"
Const de_Method$="&Method"
Const nl_Method$="&Method"
Const pt_Method$="&Method"
Const xx_Method$="&Method"
Const en_Next$="&Next"
Const fr_Next$="&Suivant"
Const it_Next$="&Next"
Const es_Next$="&Next"
Const de_Next$="&Next"
Const nl_Next$="&Next"
Const pt_Next$="&Next"
Const xx_Next$="&Next"
Const en_Last$="&Last"
Const fr_Last$="&Dernier"
Const it_Last$="&Last"
Const es_Last$="&Last"
Const de_Last$="&Last"
Const nl_Last$="&Last"
Const pt_Last$="&Last"
Const xx_Last$="&Last"
Const en_Executer$="plusicon.gif"
Const fr_Executer$="plusicon.gif"
Const it_Executer$="plusicon.gif"
Const es_Executer$="plusicon.gif"
Const de_Executer$="plusicon.gif"
Const nl_Executer$="plusicon.gif"
Const pt_Executer$="plusicon.gif"
Const xx_Executer$="plusicon.gif"
Const en_EditConf$="aedicon.gif"
Const fr_EditConf$="aedicon.gif"
Const it_EditConf$="aedicon.gif"
Const es_EditConf$="aedicon.gif"
Const de_EditConf$="aedicon.gif"
Const nl_EditConf$="aedicon.gif"
Const pt_EditConf$="aedicon.gif"
Const xx_EditConf$="aedicon.gif"
Const en_Translate$="otricon.gif"
Const fr_Translate$="otricon.gif"
Const it_Translate$="otricon.gif"
Const es_Translate$="otricon.gif"
Const de_Translate$="otricon.gif"
Const nl_Translate$="otricon.gif"
Const pt_Translate$="otricon.gif"
Const xx_Translate$="otricon.gif"
Const en_Linker$="oldicon.gif"
Const fr_Linker$="oldicon.gif"
Const it_Linker$="oldicon.gif"
Const es_Linker$="oldicon.gif"
Const de_Linker$="oldicon.gif"
Const nl_Linker$="oldicon.gif"
Const pt_Linker$="oldicon.gif"
Const xx_Linker$="oldicon.gif"
Const en_Auto970$=" "
Const fr_Auto970$=" "
Const it_Auto970$=" "
Const es_Auto970$=" "
Const de_Auto970$=" "
Const nl_Auto970$=" "
Const pt_Auto970$=" "
Const xx_Auto970$=" "
Const en_StatusMessage1$=" "
Const fr_StatusMessage1$=" "
Const it_StatusMessage1$=" "
Const es_StatusMessage1$=" "
Const de_StatusMessage1$=" "
Const nl_StatusMessage1$=" "
Const pt_StatusMessage1$=" "
Const xx_StatusMessage1$=" "
Const en_StatusMessage2$=" "
Const fr_StatusMessage2$=" "
Const it_StatusMessage2$=" "
Const es_StatusMessage2$=" "
Const de_StatusMessage2$=" "
Const nl_StatusMessage2$=" "
Const pt_StatusMessage2$=" "
Const xx_StatusMessage2$=" "
Const en_StatusMessage3$=" "
Const fr_StatusMessage3$=" "
Const it_StatusMessage3$=" "
Const es_StatusMessage3$=" "
Const de_StatusMessage3$=" "
Const nl_StatusMessage3$=" "
Const pt_StatusMessage3$=" "
Const xx_StatusMessage3$=" "
;** Widget Focus Values 
Const __Auto962%=1
Const __ToolBarControl%=2
Const __PaletteControl%=3
Const __File%=4
Const __New%=5
Const __Save%=6
Const __SaveAs%=7
Const __Open%=8
Const __Production%=9
Const __Drop%=10
Const __Quit%=11
Const __View%=12
Const __Run%=13
Const __Text%=14
Const __Image%=15
Const __Font%=16
Const __Properties%=17
Const __Visual%=18
Const __TreeView%=19
Const __Application%=20
Const __Event%=21
Const __Options%=22
Const __Parameters%=23
Const __Refresh%=24
Const __Configure%=25
Const __ScreenCapture%=26
Const __Animate%=27
Const __Editor%=28
Const __Find%=29
Const __Replace%=30
Const __Syntax%=31
Const __Search%=32
Const __Trace%=33
Const __InsertSwitch%=34
Const __SelectSwitch%=35
Const __LineNumber%=36
Const __First%=37
Const __Previous%=38
Const __Widget%=39
Const __Method%=40
Const __Next%=41
Const __Last%=42
Const __StatusMessage1%=43
Const __StatusMessage2%=44
Const __StatusMessage3%=45
Dcl	KeyCode%
Dcl	FocusItem%
Dcl	LastFocus%
Dcl	FocusItems%
Dcl	__pi%
Dcl	__si%
Dcl	KeyBuffer$=32
Field=m,KeyBuffer
Dcl	KeyValue#(32)
Dcl	AskForeGround%
Dcl	AskBackGround%
Dcl	AskAtribut%
Dcl	FirstPage%
Dcl	NationalLanguage%
Dcl	FontHandle%(16)
Dcl	msg_EditorText$=32(8)
Dcl	v_Auto962%		;** Value : actual value of scrool bar 
Dcl	l_Auto962%		;** limit : page size 
Dcl	m_Auto962%		;** max : total size 
Dcl	msg_ToolBarControl$=12(8)
Dcl	t_ToolBarControl%
Dcl	a_ToolBarControl%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_PaletteControl$=12(8)
Dcl	t_PaletteControl%
Dcl	a_PaletteControl%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_File$=8(8)
Dcl	t_File%
Dcl	a_File%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_New$=8(8)
Dcl	t_New%
Dcl	a_New%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Save$=12(8)
Dcl	t_Save%
Dcl	a_Save%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_SaveAs$=17(8)
Dcl	t_SaveAs%
Dcl	a_SaveAs%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Open$=9(8)
Dcl	t_Open%
Dcl	a_Open%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Production$=11(8)
Dcl	t_Production%
Dcl	a_Production%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Drop$=8(8)
Dcl	t_Drop%
Dcl	a_Drop%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Quit$=10(8)
Dcl	t_Quit%
Dcl	a_Quit%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_View$=11(8)
Dcl	t_View%
Dcl	a_View%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Run$=10(8)
Dcl	t_Run%
Dcl	a_Run%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Text$=6(8)
Dcl	t_Text%
Dcl	a_Text%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Image$=6(8)
Dcl	t_Image%
Dcl	a_Image%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Font$=6(8)
Dcl	t_Font%
Dcl	a_Font%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Properties$=11(8)
Dcl	t_Properties%
Dcl	a_Properties%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Visual$=8(8)
Dcl	t_Visual%
Dcl	a_Visual%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_TreeView$=12(8)
Dcl	t_TreeView%
Dcl	a_TreeView%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Application$=12(8)
Dcl	t_Application%
Dcl	a_Application%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Event$=10(8)
Dcl	t_Event%
Dcl	a_Event%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Options$=8(8)
Dcl	t_Options%
Dcl	a_Options%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Parameters$=11(8)
Dcl	t_Parameters%
Dcl	a_Parameters%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Refresh$=11(8)
Dcl	t_Refresh%
Dcl	a_Refresh%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Configure$=11(8)
Dcl	t_Configure%
Dcl	a_Configure%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_ScreenCapture$=15(8)
Dcl	t_ScreenCapture%
Dcl	a_ScreenCapture%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Animate$=8(8)
Dcl	t_Animate%
Dcl	a_Animate%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Editor$=8(8)
Dcl	t_Editor%
Dcl	a_Editor%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Find$=11(8)
Dcl	t_Find%
Dcl	a_Find%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Replace$=10(8)
Dcl	t_Replace%
Dcl	a_Replace%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Syntax$=8(8)
Dcl	t_Syntax%
Dcl	a_Syntax%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Search$=7(8)
Dcl	t_Search%
Dcl	a_Search%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Trace$=6(8)
Dcl	t_Trace%
Dcl	a_Trace%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_InsertSwitch$=3(8)
Dcl	t_InsertSwitch%
Dcl	a_InsertSwitch%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	v_InsertSwitch%		;** Value : Number of user choice 
Dcl	msg_SelectSwitch$=3(8)
Dcl	t_SelectSwitch%
Dcl	a_SelectSwitch%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	v_SelectSwitch%		;** Value : Number of user choice 
Dcl	a_LineNumber%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	b_LineNumber$=3		;** Buffer : user field 
Dcl	msg_Executeur$=11(8)
Dcl	msg_First$=8(8)
Dcl	t_First%
Dcl	a_First%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Previous$=10(8)
Dcl	t_Previous%
Dcl	a_Previous%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Widget$=26(8)
Dcl	t_Widget%
Dcl	a_Widget%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Method$=8(8)
Dcl	t_Method%
Dcl	a_Method%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Next$=8(8)
Dcl	t_Next%
Dcl	a_Next%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Last$=8(8)
Dcl	t_Last%
Dcl	a_Last%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Executer$=12(8)
Dcl	msg_EditConf$=11(8)
Dcl	msg_Translate$=11(8)
Dcl	msg_Linker$=11(8)
Dcl	a_StatusMessage1%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	b_StatusMessage1$=38		;** Buffer : user field 
Dcl	a_StatusMessage2%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	b_StatusMessage2$=29		;** Buffer : user field 
Dcl	a_StatusMessage3%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	b_StatusMessage3$=37		;** Buffer : user field 
Dcl	Signature$=4
Dcl	Status%
Dcl	MouseEvent$=8
Field=m,MouseEvent
Dcl	MouseType%
Dcl	MouseButton%
Dcl	MouseColumn%
Dcl	MouseRow%
Field=m
Forward Proc OnCreate() : %
Forward Proc OnRemove() : %
Forward Proc OnHide() : %
Forward Proc OnShow() : %
Forward Proc OnEvent() : %
Forward Proc OnFocus() : %
Forward Proc OnLosefocus() : %
;** Public Widget Interface Methods 
;** Private Widget Interface Methods 
Forward Proc Auto962Event() : % 
Forward Proc LineNumberOnshow()
Forward Proc StatusMessage1Onshow()
Forward Proc StatusMessage2Onshow()
Forward Proc StatusMessage3Onshow()
Forward Proc Auto962Action() : % 
;** Private Forms Method Interface  
* ------------------------- *
* Test Widget Access Rights *
* ------------------------- *
Proc value_access(FocusItem%):%
	Select (FocusItem)
	Case __ToolBarControl 
		Exit(a_ToolBarControl)
	Case __PaletteControl 
		Exit(a_PaletteControl)
	Case __File 
		Exit(a_File)
	Case __New 
		Exit(a_New)
	Case __Save 
		Exit(a_Save)
	Case __SaveAs 
		Exit(a_SaveAs)
	Case __Open 
		Exit(a_Open)
	Case __Production 
		Exit(a_Production)
	Case __Drop 
		Exit(a_Drop)
	Case __Quit 
		Exit(a_Quit)
	Case __View 
		Exit(a_View)
	Case __Run 
		Exit(a_Run)
	Case __Text 
		Exit(a_Text)
	Case __Image 
		Exit(a_Image)
	Case __Font 
		Exit(a_Font)
	Case __Properties 
		Exit(a_Properties)
	Case __Visual 
		Exit(a_Visual)
	Case __TreeView 
		Exit(a_TreeView)
	Case __Application 
		Exit(a_Application)
	Case __Event 
		Exit(a_Event)
	Case __Options 
		Exit(a_Options)
	Case __Parameters 
		Exit(a_Parameters)
	Case __Refresh 
		Exit(a_Refresh)
	Case __Configure 
		Exit(a_Configure)
	Case __ScreenCapture 
		Exit(a_ScreenCapture)
	Case __Animate 
		Exit(a_Animate)
	Case __Editor 
		Exit(a_Editor)
	Case __Find 
		Exit(a_Find)
	Case __Replace 
		Exit(a_Replace)
	Case __Syntax 
		Exit(a_Syntax)
	Case __Search 
		Exit(a_Search)
	Case __Trace 
		Exit(a_Trace)
	Case __InsertSwitch 
		Exit(a_InsertSwitch)
	Case __SelectSwitch 
		Exit(a_SelectSwitch)
	Case __LineNumber 
		Exit(a_LineNumber)
	Case __First 
		Exit(a_First)
	Case __Previous 
		Exit(a_Previous)
	Case __Widget 
		Exit(a_Widget)
	Case __Method 
		Exit(a_Method)
	Case __Next 
		Exit(a_Next)
	Case __Last 
		Exit(a_Last)
	Case __StatusMessage1 
		Exit(a_StatusMessage1)
	Case __StatusMessage2 
		Exit(a_StatusMessage2)
	Case __StatusMessage3 
		Exit(a_StatusMessage3)
	EndSel
	Exit(0)
EndProc
Proc OnCreate() : % 
	On Local Error Goto &elabel1,Status
	Status = VisualControl(_VISUAL_GETKEYS,KeyBuffer,Len(KeyBuffer))
	NationalLanguage=1
	Status = VisualControl(_VISUAL_LANGUAGE," ",NationalLanguage)
	KeyCode=0
	FirstPage=1
	Event(57)=15
	AskForeGround=0
	AskBackGround=15
	AskAtribut=53
	FocusItem=1
	FocusItems=45
	Event(82)=1
	Status = VisualControl(_VISUAL_CONFIG,"doc",3)
	If(VisualInitialise(4+256) = -1 )
		Error 56
	Else
		If(VisualPalette("grisstd.rgb",11) <> 0 )
			Error 40
		Endif
	Endif
	FontHandle(1) = VisualFont("standard.fmf",12)
	FontHandle(2) = VisualFont("arial2.fmf",10)
	FontHandle(3) = VisualFont("arial3.fmf",10)
	FontHandle(4) = VisualFont("arial4.fmf",10)
	FontHandle(5) = VisualFont("arial5.fmf",10)
	FontHandle(6) = VisualFont("arial6.fmf",10)
	FontHandle(7) = VisualFont("font7.fmf",9)
	FontHandle(8) = VisualFont("font8.fmf",9)
	FontHandle(9) = VisualFont("font9.fmf",9)
	FontHandle(10) = VisualFont("standard.fmf",12)
	Status = VisualControl(_VISUAL_TITLE,"Text_Editor",11)
	Status = VisualControl(_VISUAL_ICON,"exa",3)
	msg_EditorText(1)=en_EditorText
	msg_EditorText(2)=fr_EditorText
	msg_EditorText(3)=it_EditorText
	msg_EditorText(4)=es_EditorText
	msg_EditorText(5)=de_EditorText
	msg_EditorText(6)=nl_EditorText
	msg_EditorText(7)=pt_EditorText
	msg_EditorText(8)=xx_EditorText
	v_Auto962 = 0
	m_Auto962 = 0
	l_Auto962 = 1
#Pragma Enter Auto962.Create
	v_Auto962=0
	{this.limit=[List].lines}	m_Auto962=l_Auto962
#Pragma Leave Auto962.Create
	msg_ToolBarControl(1)=en_ToolBarControl
	msg_ToolBarControl(2)=fr_ToolBarControl
	msg_ToolBarControl(3)=it_ToolBarControl
	msg_ToolBarControl(4)=es_ToolBarControl
	msg_ToolBarControl(5)=de_ToolBarControl
	msg_ToolBarControl(6)=nl_ToolBarControl
	msg_ToolBarControl(7)=pt_ToolBarControl
	msg_ToolBarControl(8)=xx_ToolBarControl
	a_ToolBarControl=0 ;** initialise access : normal
	msg_PaletteControl(1)=en_PaletteControl
	msg_PaletteControl(2)=fr_PaletteControl
	a_PaletteControl=0 ;** initialise access : normal
	msg_File(1)=en_File
	msg_File(2)=fr_File
	msg_File(3)=it_File
	msg_File(4)=es_File
	msg_File(5)=de_File
	a_File=0 ;** initialise access : normal
	msg_New(1)=en_New
	msg_New(2)=fr_New
	msg_New(3)=it_New
	msg_New(4)=es_New
	msg_New(5)=de_New
	a_New=0 ;** initialise access : normal
	msg_Save(1)=en_Save
	msg_Save(2)=fr_Save
	msg_Save(3)=it_Save
	msg_Save(4)=es_Save
	msg_Save(5)=de_Save
	a_Save=0 ;** initialise access : normal
	msg_SaveAs(1)=en_SaveAs
	msg_SaveAs(2)=fr_SaveAs
	msg_SaveAs(3)=it_SaveAs
	msg_SaveAs(4)=es_SaveAs
	msg_SaveAs(5)=de_SaveAs
	a_SaveAs=0 ;** initialise access : normal
	msg_Open(1)=en_Open
	msg_Open(2)=fr_Open
	msg_Open(3)=it_Open
	msg_Open(4)=es_Open
	msg_Open(5)=de_Open
	msg_Open(6)=nl_Open
	msg_Open(7)=pt_Open
	msg_Open(8)=xx_Open
	a_Open=0 ;** initialise access : normal
	msg_Production(1)=en_Production
	msg_Production(2)=fr_Production
	msg_Production(4)=es_Production
	msg_Production(5)=de_Production
	a_Production=0 ;** initialise access : normal
	msg_Drop(1)=en_Drop
	msg_Drop(2)=fr_Drop
	msg_Drop(3)=it_Drop
	msg_Drop(4)=es_Drop
	msg_Drop(5)=de_Drop
	msg_Drop(6)=nl_Drop
	msg_Drop(7)=pt_Drop
	msg_Drop(8)=xx_Drop
	a_Drop=0 ;** initialise access : normal
	msg_Quit(1)=en_Quit
	msg_Quit(2)=fr_Quit
	msg_Quit(4)=es_Quit
	msg_Quit(5)=de_Quit
	a_Quit=0 ;** initialise access : normal
	msg_View(1)=en_View
	msg_View(2)=fr_View
	a_View=0 ;** initialise access : normal
	msg_Run(1)=en_Run
	msg_Run(2)=fr_Run
	a_Run=0 ;** initialise access : normal
	msg_Text(1)=en_Text
	msg_Text(2)=fr_Text
	a_Text=0 ;** initialise access : normal
	msg_Image(1)=en_Image
	msg_Image(2)=fr_Image
	a_Image=0 ;** initialise access : normal
	msg_Font(1)=en_Font
	msg_Font(2)=fr_Font
	msg_Font(3)=it_Font
	msg_Font(4)=es_Font
	msg_Font(5)=de_Font
	msg_Font(6)=nl_Font
	msg_Font(7)=pt_Font
	msg_Font(8)=xx_Font
	a_Font=0 ;** initialise access : normal
	msg_Properties(1)=en_Properties
	msg_Properties(2)=fr_Properties
	a_Properties=0 ;** initialise access : normal
	msg_Visual(1)=en_Visual
	msg_Visual(2)=fr_Visual
	msg_Visual(3)=it_Visual
	msg_Visual(4)=es_Visual
	msg_Visual(5)=de_Visual
	msg_Visual(6)=nl_Visual
	msg_Visual(7)=pt_Visual
	msg_Visual(8)=xx_Visual
	a_Visual=0 ;** initialise access : normal
	msg_TreeView(1)=en_TreeView
	msg_TreeView(2)=fr_TreeView
	a_TreeView=0 ;** initialise access : normal
	msg_Application(1)=en_Application
	msg_Application(2)=fr_Application
	a_Application=0 ;** initialise access : normal
	msg_Event(1)=en_Event
	msg_Event(2)=fr_Event
	msg_Event(3)=it_Event
	msg_Event(4)=es_Event
	msg_Event(5)=de_Event
	msg_Event(6)=nl_Event
	msg_Event(7)=pt_Event
	msg_Event(8)=xx_Event
	a_Event=0 ;** initialise access : normal
	msg_Options(1)=en_Options
	msg_Options(2)=fr_Options
	a_Options=0 ;** initialise access : normal
	msg_Parameters(1)=en_Parameters
	msg_Parameters(2)=fr_Parameters
	a_Parameters=0 ;** initialise access : normal
	msg_Refresh(1)=en_Refresh
	msg_Refresh(2)=fr_Refresh
	a_Refresh=0 ;** initialise access : normal
	msg_Configure(1)=en_Configure
	msg_Configure(2)=fr_Configure
	a_Configure=0 ;** initialise access : normal
	msg_ScreenCapture(1)=en_ScreenCapture
	msg_ScreenCapture(2)=fr_ScreenCapture
	msg_ScreenCapture(3)=it_ScreenCapture
	msg_ScreenCapture(4)=es_ScreenCapture
	msg_ScreenCapture(5)=de_ScreenCapture
	msg_ScreenCapture(6)=nl_ScreenCapture
	msg_ScreenCapture(7)=pt_ScreenCapture
	msg_ScreenCapture(8)=xx_ScreenCapture
	a_ScreenCapture=0 ;** initialise access : normal
	msg_Animate(1)=en_Animate
	msg_Animate(2)=fr_Animate
	a_Animate=0 ;** initialise access : normal
	msg_Editor(1)=en_Editor
	msg_Editor(2)=fr_Editor
	msg_Editor(3)=it_Editor
	msg_Editor(4)=es_Editor
	msg_Editor(5)=de_Editor
	msg_Editor(6)=nl_Editor
	msg_Editor(7)=pt_Editor
	msg_Editor(8)=xx_Editor
	a_Editor=0 ;** initialise access : normal
	msg_Find(1)=en_Find
	msg_Find(2)=fr_Find
	msg_Find(3)=it_Find
	msg_Find(4)=es_Find
	msg_Find(5)=de_Find
	msg_Find(6)=nl_Find
	msg_Find(7)=pt_Find
	msg_Find(8)=xx_Find
	a_Find=0 ;** initialise access : normal
	msg_Replace(1)=en_Replace
	msg_Replace(2)=fr_Replace
	msg_Replace(3)=it_Replace
	msg_Replace(4)=es_Replace
	msg_Replace(5)=de_Replace
	msg_Replace(6)=nl_Replace
	msg_Replace(7)=pt_Replace
	msg_Replace(8)=xx_Replace
	a_Replace=0 ;** initialise access : normal
	msg_Syntax(1)=en_Syntax
	msg_Syntax(2)=fr_Syntax
	msg_Syntax(3)=it_Syntax
	msg_Syntax(4)=es_Syntax
	msg_Syntax(5)=de_Syntax
	msg_Syntax(6)=nl_Syntax
	msg_Syntax(7)=pt_Syntax
	msg_Syntax(8)=xx_Syntax
	a_Syntax=0 ;** initialise access : normal
	msg_Search(1)=en_Search
	msg_Search(2)=fr_Search
	msg_Search(3)=it_Search
	msg_Search(4)=es_Search
	msg_Search(5)=de_Search
	msg_Search(6)=nl_Search
	msg_Search(7)=pt_Search
	msg_Search(8)=xx_Search
	a_Search=0 ;** initialise access : normal
	msg_Trace(1)=en_Trace
	msg_Trace(2)=fr_Trace
	msg_Trace(3)=it_Trace
	msg_Trace(4)=es_Trace
	msg_Trace(5)=de_Trace
	msg_Trace(6)=nl_Trace
	msg_Trace(7)=pt_Trace
	msg_Trace(8)=xx_Trace
	a_Trace=0 ;** initialise access : normal
	msg_InsertSwitch(1)=en_InsertSwitch
	msg_InsertSwitch(2)=fr_InsertSwitch
	msg_InsertSwitch(3)=it_InsertSwitch
	msg_InsertSwitch(4)=es_InsertSwitch
	msg_InsertSwitch(5)=de_InsertSwitch
	msg_InsertSwitch(6)=nl_InsertSwitch
	msg_InsertSwitch(7)=pt_InsertSwitch
	msg_InsertSwitch(8)=xx_InsertSwitch
	a_InsertSwitch=0 ;** initialise access : normal
	v_InsertSwitch = 0
	msg_SelectSwitch(1)=en_SelectSwitch
	msg_SelectSwitch(2)=fr_SelectSwitch
	msg_SelectSwitch(3)=it_SelectSwitch
	msg_SelectSwitch(4)=es_SelectSwitch
	msg_SelectSwitch(5)=de_SelectSwitch
	msg_SelectSwitch(6)=nl_SelectSwitch
	msg_SelectSwitch(7)=pt_SelectSwitch
	msg_SelectSwitch(8)=xx_SelectSwitch
	a_SelectSwitch=0 ;** initialise access : normal
	v_SelectSwitch = 0
	a_LineNumber=0 ;** initialise access : normal
	b_LineNumber=" "
	msg_Executeur(1)=en_Executeur
	msg_First(1)=en_First
	msg_First(2)=fr_First
	msg_First(3)=it_First
	msg_First(4)=es_First
	msg_First(5)=de_First
	msg_First(6)=nl_First
	msg_First(7)=pt_First
	msg_First(8)=xx_First
	a_First=0 ;** initialise access : normal
	msg_Previous(1)=en_Previous
	msg_Previous(2)=fr_Previous
	msg_Previous(3)=it_Previous
	msg_Previous(4)=es_Previous
	msg_Previous(5)=de_Previous
	msg_Previous(6)=nl_Previous
	msg_Previous(7)=pt_Previous
	msg_Previous(8)=xx_Previous
	a_Previous=0 ;** initialise access : normal
	msg_Widget(1)=en_Widget
	msg_Widget(2)=fr_Widget
	msg_Widget(3)=it_Widget
	msg_Widget(4)=es_Widget
	msg_Widget(5)=de_Widget
	msg_Widget(6)=nl_Widget
	msg_Widget(7)=pt_Widget
	msg_Widget(8)=xx_Widget
	a_Widget=0 ;** initialise access : normal
	msg_Method(1)=en_Method
	msg_Method(2)=fr_Method
	msg_Method(3)=it_Method
	msg_Method(4)=es_Method
	msg_Method(5)=de_Method
	msg_Method(6)=nl_Method
	msg_Method(7)=pt_Method
	msg_Method(8)=xx_Method
	a_Method=0 ;** initialise access : normal
	msg_Next(1)=en_Next
	msg_Next(2)=fr_Next
	msg_Next(3)=it_Next
	msg_Next(4)=es_Next
	msg_Next(5)=de_Next
	msg_Next(6)=nl_Next
	msg_Next(7)=pt_Next
	msg_Next(8)=xx_Next
	a_Next=0 ;** initialise access : normal
	msg_Last(1)=en_Last
	msg_Last(2)=fr_Last
	msg_Last(3)=it_Last
	msg_Last(4)=es_Last
	msg_Last(5)=de_Last
	msg_Last(6)=nl_Last
	msg_Last(7)=pt_Last
	msg_Last(8)=xx_Last
	a_Last=0 ;** initialise access : normal
	msg_Executer(1)=en_Executer
	msg_EditConf(1)=en_EditConf
	msg_EditConf(2)=fr_EditConf
	msg_Translate(1)=en_Translate
	msg_Translate(2)=fr_Translate
	msg_Linker(1)=en_Linker
	msg_Linker(2)=fr_Linker
	a_StatusMessage1=0 ;** initialise access : normal
	b_StatusMessage1=" "
	a_StatusMessage2=0 ;** initialise access : normal
	b_StatusMessage2=" "
	a_StatusMessage3=0 ;** initialise access : normal
	b_StatusMessage3=" "
	Exit(0)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc OnHide() : % 
	On Local Error Goto &elabel1,Status
	Exit(0)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc OnRemove() : % 
	On Local Error Goto &elabel1,Status
	If(VisualLiberate()= -1)
		Error 56
	Endif
	Exit(0)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc Auto962Onshow()
	Status=VisualScroll(860,32,20,557,FontHandle(2),0,0,v_Auto962,l_Auto962,m_Auto962,3)
	Exit
EndProc
Proc LineNumberOnshow()
	On Local Error Goto &elabel1,Status
	Status=VisualZone(692,6,31+2,16+2,5 + (a_LineNumber * 128))	; si access vaut 2 alors gris
	Status=VisualEdit(692+1,6+1,31,16,FontHandle(1),b_LineNumber,3,/0800)
	Exit
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc StatusMessage1Onshow()
	On Local Error Goto &elabel1,Status
	Status=VisualZone(11,599,308+2,16+2,5 + (a_StatusMessage1 * 128))	; si access vaut 2 alors gris
	Status=VisualText(11+1,599+1,308,16,FontHandle(1),27,0,b_StatusMessage1,38,0)
	Exit
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc StatusMessage2Onshow()
	On Local Error Goto &elabel1,Status
	Status=VisualZone(326,599,232+2,16+2,5 + (a_StatusMessage2 * 128))	; si access vaut 2 alors gris
	Status=VisualText(326+1,599+1,232,16,FontHandle(1),27,0,b_StatusMessage2,29,0)
	Exit
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc StatusMessage3Onshow()
	On Local Error Goto &elabel1,Status
	Status=VisualZone(564,599,300+2,20+2,5 + (a_StatusMessage3 * 128))	; si access vaut 2 alors gris
	Status=VisualText(564+1,599+1,300,20,FontHandle(1),27,0,b_StatusMessage3,37,0)
	Exit
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc OnShow() : % 
	On Local Error Goto &elabel1,Status
	NationalLanguage = VisualControl(_VISUAL_LANGUAGE," ",-1)
	if ( NationalLanguage = 0 ) :: NationalLanguage = 1 
	Endif
	Status=VisualFreeze()
	if ( VisualStyle(0,0,880,630,"outsetframe",11," ",0) <> 0)
		Status=VisualZone(0,0,880,630,1)
	Endif
	Status=VisualFill(0,0,880,30,27,10)
	Status=VisualImage(2,31,866,557,"/home/Dev/abal32/sing/editer.gif",32,2)
	Auto962Onshow()
	if ( VisualStyle(22,5,19,19,"insetframe",10," ",0) <> 0)
		Status=VisualZone(22,5,19,19,2)
	Endif
	if (a_ToolBarControl = 2)	;** affichage gris‚ si 2
		Status=VisualButton(19,2,25,25,FontHandle(1),18,0,msg_ToolBarControl(NationalLanguage),Len(msg_ToolBarControl(NationalLanguage)),/0430)
	endif
	if (a_ToolBarControl = 0)	;** affichage normal si 0
		Status=VisualButton(19,2,25,25,FontHandle(1),27,0,msg_ToolBarControl(NationalLanguage),Len(msg_ToolBarControl(NationalLanguage)),/0030)
	endif
	if ( VisualStyle(843,7,18,17,"insetframe",10," ",0) <> 0)
		Status=VisualZone(843,7,18,17,2)
	Endif
	if (a_PaletteControl = 2)	;** affichage gris‚ si 2
		Status=VisualButton(840,4,24,25,FontHandle(2),18,0,msg_PaletteControl(NationalLanguage),Len(msg_PaletteControl(NationalLanguage)),/0430)
	endif
	if (a_PaletteControl = 0)	;** affichage normal si 0
		Status=VisualButton(840,4,24,25,FontHandle(2),16,0,msg_PaletteControl(NationalLanguage),Len(msg_PaletteControl(NationalLanguage)),/0030)
	endif
	t_File=VisualControl(_VISUAL_TRIGGER,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)))
	if (a_File = 2)	;** affichage gris‚ si 2
		Status=VisualButton(60,4,90,20,FontHandle(2),18,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0420)
	endif
	if (a_File = 0)	;** affichage normal si 0
		Status=VisualButton(60,4,90,20,FontHandle(2),16,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0020)
	endif
	Status=VisualFill(40,30,110,160,16,11)
	t_New=VisualControl(_VISUAL_TRIGGER,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)))
	if (a_New = 2)	;** affichage gris‚ si 2
		Status=VisualButton(50,40,90,20,FontHandle(2),18,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0420)
	endif
	if (a_New = 0)	;** affichage normal si 0
		Status=VisualButton(50,40,90,20,FontHandle(2),16,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0020)
	endif
	t_Save=VisualControl(_VISUAL_TRIGGER,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)))
	if (a_Save = 2)	;** affichage gris‚ si 2
		Status=VisualButton(50,60,90,20,FontHandle(2),18,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0420)
	endif
	if (a_Save = 0)	;** affichage normal si 0
		Status=VisualButton(50,60,90,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0020)
	endif
	t_SaveAs=VisualControl(_VISUAL_TRIGGER,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)))
	if (a_SaveAs = 2)	;** affichage gris‚ si 2
		Status=VisualButton(50,80,90,20,FontHandle(2),18,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0420)
	endif
	if (a_SaveAs = 0)	;** affichage normal si 0
		Status=VisualButton(50,80,90,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0020)
	endif
	t_Open=VisualControl(_VISUAL_TRIGGER,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)))
	if (a_Open = 2)	;** affichage gris‚ si 2
		Status=VisualButton(50,100,90,20,FontHandle(2),18,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0420)
	endif
	if (a_Open = 0)	;** affichage normal si 0
		Status=VisualButton(50,100,90,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0020)
	endif
	t_Production=VisualControl(_VISUAL_TRIGGER,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)))
	if (a_Production = 2)	;** affichage gris‚ si 2
		Status=VisualButton(50,120,90,20,FontHandle(2),18,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0420)
	endif
	if (a_Production = 0)	;** affichage normal si 0
		Status=VisualButton(50,120,90,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0020)
	endif
	t_Drop=VisualControl(_VISUAL_TRIGGER,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)))
	if (a_Drop = 2)	;** affichage gris‚ si 2
		Status=VisualButton(50,140,90,20,FontHandle(2),18,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0420)
	endif
	if (a_Drop = 0)	;** affichage normal si 0
		Status=VisualButton(50,140,90,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0020)
	endif
	t_Quit=VisualControl(_VISUAL_TRIGGER,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)))
	if (a_Quit = 2)	;** affichage gris‚ si 2
		Status=VisualButton(50,160,90,20,FontHandle(2),18,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0420)
	endif
	if (a_Quit = 0)	;** affichage normal si 0
		Status=VisualButton(50,160,90,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0020)
	endif
	t_View=VisualControl(_VISUAL_TRIGGER,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)))
	if (a_View = 2)	;** affichage gris‚ si 2
		Status=VisualButton(150,4,90,20,FontHandle(2),18,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0420)
	endif
	if (a_View = 0)	;** affichage normal si 0
		Status=VisualButton(150,4,90,20,FontHandle(2),16,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0020)
	endif
	Status=VisualFill(150,30,110,180,16,11)
	t_Run=VisualControl(_VISUAL_TRIGGER,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)))
	if (a_Run = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,40,90,20,FontHandle(2),18,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0420)
	endif
	if (a_Run = 0)	;** affichage normal si 0
		Status=VisualButton(160,40,90,20,FontHandle(2),16,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0020)
	endif
	t_Text=VisualControl(_VISUAL_TRIGGER,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)))
	if (a_Text = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,60,90,20,FontHandle(2),18,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0420)
	endif
	if (a_Text = 0)	;** affichage normal si 0
		Status=VisualButton(160,60,90,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0020)
	endif
	t_Image=VisualControl(_VISUAL_TRIGGER,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)))
	if (a_Image = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,80,90,20,FontHandle(2),18,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0420)
	endif
	if (a_Image = 0)	;** affichage normal si 0
		Status=VisualButton(160,80,90,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0020)
	endif
	t_Font=VisualControl(_VISUAL_TRIGGER,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)))
	if (a_Font = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,100,90,20,FontHandle(2),18,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0420)
	endif
	if (a_Font = 0)	;** affichage normal si 0
		Status=VisualButton(160,100,90,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0020)
	endif
	t_Properties=VisualControl(_VISUAL_TRIGGER,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)))
	if (a_Properties = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,120,90,20,FontHandle(2),18,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0420)
	endif
	if (a_Properties = 0)	;** affichage normal si 0
		Status=VisualButton(160,120,90,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0020)
	endif
	t_Visual=VisualControl(_VISUAL_TRIGGER,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)))
	if (a_Visual = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,140,90,20,FontHandle(2),18,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0420)
	endif
	if (a_Visual = 0)	;** affichage normal si 0
		Status=VisualButton(160,140,90,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0020)
	endif
	t_TreeView=VisualControl(_VISUAL_TRIGGER,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)))
	if (a_TreeView = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,160,88,20,FontHandle(2),18,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0420)
	endif
	if (a_TreeView = 0)	;** affichage normal si 0
		Status=VisualButton(160,160,88,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0020)
	endif
	t_Application=VisualControl(_VISUAL_TRIGGER,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)))
	if (a_Application = 2)	;** affichage gris‚ si 2
		Status=VisualButton(160,180,88,20,FontHandle(2),18,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0420)
	endif
	if (a_Application = 0)	;** affichage normal si 0
		Status=VisualButton(160,180,88,20,FontHandle(2),16,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0020)
	endif
	t_Event=VisualControl(_VISUAL_TRIGGER,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)))
	if (a_Event = 2)	;** affichage gris‚ si 2
		Status=VisualButton(240,4,90,20,FontHandle(2),18,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0420)
	endif
	if (a_Event = 0)	;** affichage normal si 0
		Status=VisualButton(240,4,90,20,FontHandle(2),16,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0020)
	endif
	t_Options=VisualControl(_VISUAL_TRIGGER,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)))
	if (a_Options = 2)	;** affichage gris‚ si 2
		Status=VisualButton(330,4,90,20,FontHandle(2),18,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0420)
	endif
	if (a_Options = 0)	;** affichage normal si 0
		Status=VisualButton(330,4,90,20,FontHandle(2),16,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0020)
	endif
	Status=VisualFill(300,30,120,120,16,11)
	t_Parameters=VisualControl(_VISUAL_TRIGGER,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)))
	if (a_Parameters = 2)	;** affichage gris‚ si 2
		Status=VisualButton(310,40,100,20,FontHandle(2),18,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0420)
	endif
	if (a_Parameters = 0)	;** affichage normal si 0
		Status=VisualButton(310,40,100,20,FontHandle(2),16,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0020)
	endif
	t_Refresh=VisualControl(_VISUAL_TRIGGER,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)))
	if (a_Refresh = 2)	;** affichage gris‚ si 2
		Status=VisualButton(310,60,100,20,FontHandle(2),18,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0420)
	endif
	if (a_Refresh = 0)	;** affichage normal si 0
		Status=VisualButton(310,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0020)
	endif
	t_Configure=VisualControl(_VISUAL_TRIGGER,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)))
	if (a_Configure = 2)	;** affichage gris‚ si 2
		Status=VisualButton(310,80,100,20,FontHandle(2),18,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0420)
	endif
	if (a_Configure = 0)	;** affichage normal si 0
		Status=VisualButton(310,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0020)
	endif
	t_ScreenCapture=VisualControl(_VISUAL_TRIGGER,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)))
	if (a_ScreenCapture = 2)	;** affichage gris‚ si 2
		Status=VisualButton(310,100,100,20,FontHandle(2),18,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0420)
	endif
	if (a_ScreenCapture = 0)	;** affichage normal si 0
		Status=VisualButton(310,100,100,20,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0020)
	endif
	t_Animate=VisualControl(_VISUAL_TRIGGER,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)))
	if (a_Animate = 2)	;** affichage gris‚ si 2
		Status=VisualButton(310,120,100,20,FontHandle(2),18,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0420)
	endif
	if (a_Animate = 0)	;** affichage normal si 0
		Status=VisualButton(310,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0020)
	endif
	t_Editor=VisualControl(_VISUAL_TRIGGER,msg_Editor(NationalLanguage),Len(msg_Editor(NationalLanguage)))
	if (a_Editor = 2)	;** affichage gris‚ si 2
		Status=VisualButton(420,4,90,20,FontHandle(2),18,0,msg_Editor(NationalLanguage),Len(msg_Editor(NationalLanguage)),/0420)
	endif
	if (a_Editor = 0)	;** affichage normal si 0
		Status=VisualButton(420,4,90,20,FontHandle(2),16,0,msg_Editor(NationalLanguage),Len(msg_Editor(NationalLanguage)),/0020)
	endif
	Status=VisualFill(420,30,110,90,16,11)
	t_Find=VisualControl(_VISUAL_TRIGGER,msg_Find(NationalLanguage),Len(msg_Find(NationalLanguage)))
	if (a_Find = 2)	;** affichage gris‚ si 2
		Status=VisualButton(430,40,90,20,FontHandle(2),18,0,msg_Find(NationalLanguage),Len(msg_Find(NationalLanguage)),/0420)
	endif
	if (a_Find = 0)	;** affichage normal si 0
		Status=VisualButton(430,40,90,20,FontHandle(2),16,0,msg_Find(NationalLanguage),Len(msg_Find(NationalLanguage)),/0020)
	endif
	t_Replace=VisualControl(_VISUAL_TRIGGER,msg_Replace(NationalLanguage),Len(msg_Replace(NationalLanguage)))
	if (a_Replace = 2)	;** affichage gris‚ si 2
		Status=VisualButton(430,56,90,20,FontHandle(2),18,0,msg_Replace(NationalLanguage),Len(msg_Replace(NationalLanguage)),/0420)
	endif
	if (a_Replace = 0)	;** affichage normal si 0
		Status=VisualButton(430,56,90,20,FontHandle(2),16,0,msg_Replace(NationalLanguage),Len(msg_Replace(NationalLanguage)),/0020)
	endif
	t_Syntax=VisualControl(_VISUAL_TRIGGER,msg_Syntax(NationalLanguage),Len(msg_Syntax(NationalLanguage)))
	if (a_Syntax = 2)	;** affichage gris‚ si 2
		Status=VisualButton(430,72,90,20,FontHandle(2),18,0,msg_Syntax(NationalLanguage),Len(msg_Syntax(NationalLanguage)),/0420)
	endif
	if (a_Syntax = 0)	;** affichage normal si 0
		Status=VisualButton(430,72,90,20,FontHandle(2),16,0,msg_Syntax(NationalLanguage),Len(msg_Syntax(NationalLanguage)),/0020)
	endif
	t_Search=VisualControl(_VISUAL_TRIGGER,msg_Search(NationalLanguage),Len(msg_Search(NationalLanguage)))
	if (a_Search = 2)	;** affichage gris‚ si 2
		Status=VisualButton(430,88,90,20,FontHandle(2),18,0,msg_Search(NationalLanguage),Len(msg_Search(NationalLanguage)),/0420)
	endif
	if (a_Search = 0)	;** affichage normal si 0
		Status=VisualButton(430,88,90,20,FontHandle(2),16,0,msg_Search(NationalLanguage),Len(msg_Search(NationalLanguage)),/0020)
	endif
	t_Trace=VisualControl(_VISUAL_TRIGGER,msg_Trace(NationalLanguage),Len(msg_Trace(NationalLanguage)))
	if (a_Trace = 2)	;** affichage gris‚ si 2
		Status=VisualButton(510,4,80,20,FontHandle(2),18,21,msg_Trace(NationalLanguage),Len(msg_Trace(NationalLanguage)),/0420)
	endif
	if (a_Trace = 0)	;** affichage normal si 0
		Status=VisualButton(510,4,80,20,FontHandle(2),28,21,msg_Trace(NationalLanguage),Len(msg_Trace(NationalLanguage)),/0020)
	endif
	Status=VisualFill(530,30,120,140,28,11)
	t_InsertSwitch=VisualControl(_VISUAL_TRIGGER,msg_InsertSwitch(NationalLanguage),Len(msg_InsertSwitch(NationalLanguage)))
	if (a_InsertSwitch = 2)	;** affichage gris‚ si 2
		Status=VisualSwitch(620,6,32,16,FontHandle(1),18,18,msg_InsertSwitch(NationalLanguage),Len(msg_InsertSwitch(NationalLanguage)),((v_InsertSwitch+0) or /0000))
	endif
	if (a_InsertSwitch = 0)	;** affichage normal si 0
		Status=VisualSwitch(620,6,32,16,FontHandle(1),28,29,msg_InsertSwitch(NationalLanguage),Len(msg_InsertSwitch(NationalLanguage)),((v_InsertSwitch+0) or /0000))
	endif
	t_SelectSwitch=VisualControl(_VISUAL_TRIGGER,msg_SelectSwitch(NationalLanguage),Len(msg_SelectSwitch(NationalLanguage)))
	if (a_SelectSwitch = 2)	;** affichage gris‚ si 2
		Status=VisualSwitch(656,6,32,16,FontHandle(1),18,18,msg_SelectSwitch(NationalLanguage),Len(msg_SelectSwitch(NationalLanguage)),((v_SelectSwitch+0) or /0000))
	endif
	if (a_SelectSwitch = 0)	;** affichage normal si 0
		Status=VisualSwitch(656,6,32,16,FontHandle(1),28,29,msg_SelectSwitch(NationalLanguage),Len(msg_SelectSwitch(NationalLanguage)),((v_SelectSwitch+0) or /0000))
	endif
	if (a_LineNumber <> 1)	;** affichage si diff‚rent de 1
		LineNumberOnshow()
	endif
	Status=VisualImage(729,7,18,15,"vdbicon.gif",11,2)
	t_First=VisualControl(_VISUAL_TRIGGER,msg_First(NationalLanguage),Len(msg_First(NationalLanguage)))
	if (a_First = 2)	;** affichage gris‚ si 2
		Status=VisualButton(540,40,100,20,FontHandle(2),18,21,msg_First(NationalLanguage),Len(msg_First(NationalLanguage)),/0420)
	endif
	if (a_First = 0)	;** affichage normal si 0
		Status=VisualButton(540,40,100,20,FontHandle(2),28,21,msg_First(NationalLanguage),Len(msg_First(NationalLanguage)),/0020)
	endif
	t_Previous=VisualControl(_VISUAL_TRIGGER,msg_Previous(NationalLanguage),Len(msg_Previous(NationalLanguage)))
	if (a_Previous = 2)	;** affichage gris‚ si 2
		Status=VisualButton(540,60,100,20,FontHandle(2),18,21,msg_Previous(NationalLanguage),Len(msg_Previous(NationalLanguage)),/0420)
	endif
	if (a_Previous = 0)	;** affichage normal si 0
		Status=VisualButton(540,60,100,20,FontHandle(2),28,21,msg_Previous(NationalLanguage),Len(msg_Previous(NationalLanguage)),/0020)
	endif
	t_Widget=VisualControl(_VISUAL_TRIGGER,msg_Widget(NationalLanguage),Len(msg_Widget(NationalLanguage)))
	if (a_Widget = 2)	;** affichage gris‚ si 2
		Status=VisualButton(540,80,100,20,FontHandle(2),18,21,msg_Widget(NationalLanguage),Len(msg_Widget(NationalLanguage)),/0420)
	endif
	if (a_Widget = 0)	;** affichage normal si 0
		Status=VisualButton(540,80,100,20,FontHandle(2),28,21,msg_Widget(NationalLanguage),Len(msg_Widget(NationalLanguage)),/0020)
	endif
	t_Method=VisualControl(_VISUAL_TRIGGER,msg_Method(NationalLanguage),Len(msg_Method(NationalLanguage)))
	if (a_Method = 2)	;** affichage gris‚ si 2
		Status=VisualButton(540,100,100,20,FontHandle(2),18,21,msg_Method(NationalLanguage),Len(msg_Method(NationalLanguage)),/0420)
	endif
	if (a_Method = 0)	;** affichage normal si 0
		Status=VisualButton(540,100,100,20,FontHandle(2),28,21,msg_Method(NationalLanguage),Len(msg_Method(NationalLanguage)),/0020)
	endif
	t_Next=VisualControl(_VISUAL_TRIGGER,msg_Next(NationalLanguage),Len(msg_Next(NationalLanguage)))
	if (a_Next = 2)	;** affichage gris‚ si 2
		Status=VisualButton(540,120,100,20,FontHandle(2),18,21,msg_Next(NationalLanguage),Len(msg_Next(NationalLanguage)),/0420)
	endif
	if (a_Next = 0)	;** affichage normal si 0
		Status=VisualButton(540,120,100,20,FontHandle(2),28,21,msg_Next(NationalLanguage),Len(msg_Next(NationalLanguage)),/0020)
	endif
	t_Last=VisualControl(_VISUAL_TRIGGER,msg_Last(NationalLanguage),Len(msg_Last(NationalLanguage)))
	if (a_Last = 2)	;** affichage gris‚ si 2
		Status=VisualButton(540,140,100,20,FontHandle(2),18,21,msg_Last(NationalLanguage),Len(msg_Last(NationalLanguage)),/0420)
	endif
	if (a_Last = 0)	;** affichage normal si 0
		Status=VisualButton(540,140,100,20,FontHandle(2),28,21,msg_Last(NationalLanguage),Len(msg_Last(NationalLanguage)),/0020)
	endif
	Status=VisualImage(748,7,18,15,"plusicon.gif",12,2)
	Status=VisualImage(768,7,18,15,"aedicon.gif",11,2)
	Status=VisualImage(788,7,18,15,"otricon.gif",11,2)
	Status=VisualImage(808,7,18,15,"oldicon.gif",11,2)
	if ( VisualStyle(1,589,874,40,"outsetframe",11," ",0) <> 0)
		Status=VisualZone(1,589,874,40,1)
	Endif
	if (a_StatusMessage1 <> 1)	;** affichage si diff‚rent de 1
		StatusMessage1Onshow()
	endif
	if (a_StatusMessage2 <> 1)	;** affichage si diff‚rent de 1
		StatusMessage2Onshow()
	endif
	if (a_StatusMessage3 <> 1)	;** affichage si diff‚rent de 1
		StatusMessage3Onshow()
	endif
	Status=VisualThaw(0,0,630,138364052)
	Exit(0)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc Auto962Event() : % 
	On Local Error Goto &elabel1,Status
#Pragma Enter Auto962.Event
	{ [List].Show()}#Pragma Leave Auto962.Event
	Exit(-1)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc Auto962Action() : % 
	Dcl	toy%
	Dcl	aty%
	EndLoc
	if ( MouseRow < (32+20) )
		Gosub &awaitup
		v_Auto962 -= 1
		Gosub &limits
		Gosub &payload
		Status=VisualScroll(860,32,20,557,FontHandle(2),0,0,v_Auto962,l_Auto962,m_Auto962,3)
		Exit(-1)
	Endif
	if ( MouseRow > (32+557-20) )
		Gosub &awaitup
		v_Auto962 += 1
		Gosub &limits
		Gosub &payload
		Status=VisualScroll(860,32,20,557,FontHandle(2),0,0,v_Auto962,l_Auto962,m_Auto962,3)
		Exit(-1)
	Endif
	aty = MouseRow
	Status=VisualScroll(860,32,20,557,FontHandle(2),0,0,v_Auto962,l_Auto962,m_Auto962,259)
	Repeat
		Gosub &getevent
		Select (MouseButton)
		Case _MIMO_LEFT,_MIMO_RIGHT
			aty = v_Auto962
			v_Auto962 = (((MouseRow - ((32)+20)) * m_Auto962) / (557 - (2 * 20)))
			Gosub &limits
			if ( v_Auto962 <> aty)
				Gosub &payload
				Status=VisualScroll(860,32,20,557,FontHandle(2),0,0,v_Auto962,l_Auto962,m_Auto962,259)
			Endif
		EndSel
	Until (MouseType = _MIMO_UP)
	Select (MouseButton)
	Case _MIMO_UPWHEEL
		v_Auto962 -= (l_Auto962/2)
		Gosub &limits
		Gosub &payload
	Case _MIMO_DOWNWHEEL
		v_Auto962 += (l_Auto962/2)
		Gosub &limits
		Gosub &payload
	Default 
		Gosub &payload
	EndSel
	Status=VisualScroll(860,32,20,557,FontHandle(2),0,0,v_Auto962,l_Auto962,m_Auto962,3)
	Exit(-1)
&awaitup
	Repeat
		Gosub &getevent
	Until (MouseType = _MIMO_UP)
	Return
&getevent
	While(VisualKey(1) <> 256) 
	Wend
	Status = VisualEvent(MouseEvent)
	Return
&limits
	if (v_Auto962 < 0)
		v_Auto962 = 0
	Else
		if (v_Auto962 > (m_Auto962-l_Auto962))
			v_Auto962 = (m_Auto962-l_Auto962)
		Endif
	Endif
	Return
&payload
	Auto962Event()
	Return
EndProc
Proc OnEvent() : % 
	On Local Error Goto &elabel1,Status
	if ((MouseType and _MIMO_ALT) <> 0)
		MouseButton = (MouseButton and /00FF)
		if (( MouseButton >= /0061) and (MouseButton <= /007A))
			MouseButton -= /0020
		endif
		if (t_ToolBarControl = MouseButton ) :: Exit(2) 
		Endif
		if (t_PaletteControl = MouseButton ) :: Exit(3) 
		Endif
		if (t_File = MouseButton ) :: Exit(4) 
		Endif
		if (t_New = MouseButton ) :: Exit(5) 
		Endif
		if (t_Save = MouseButton ) :: Exit(6) 
		Endif
		if (t_SaveAs = MouseButton ) :: Exit(7) 
		Endif
		if (t_Open = MouseButton ) :: Exit(8) 
		Endif
		if (t_Production = MouseButton ) :: Exit(9) 
		Endif
		if (t_Drop = MouseButton ) :: Exit(10) 
		Endif
		if (t_Quit = MouseButton ) :: Exit(11) 
		Endif
		if (t_View = MouseButton ) :: Exit(12) 
		Endif
		if (t_Run = MouseButton ) :: Exit(13) 
		Endif
		if (t_Text = MouseButton ) :: Exit(14) 
		Endif
		if (t_Image = MouseButton ) :: Exit(15) 
		Endif
		if (t_Font = MouseButton ) :: Exit(16) 
		Endif
		if (t_Properties = MouseButton ) :: Exit(17) 
		Endif
		if (t_Visual = MouseButton ) :: Exit(18) 
		Endif
		if (t_TreeView = MouseButton ) :: Exit(19) 
		Endif
		if (t_Application = MouseButton ) :: Exit(20) 
		Endif
		if (t_Event = MouseButton ) :: Exit(21) 
		Endif
		if (t_Options = MouseButton ) :: Exit(22) 
		Endif
		if (t_Parameters = MouseButton ) :: Exit(23) 
		Endif
		if (t_Refresh = MouseButton ) :: Exit(24) 
		Endif
		if (t_Configure = MouseButton ) :: Exit(25) 
		Endif
		if (t_ScreenCapture = MouseButton ) :: Exit(26) 
		Endif
		if (t_Animate = MouseButton ) :: Exit(27) 
		Endif
		if (t_Editor = MouseButton ) :: Exit(28) 
		Endif
		if (t_Find = MouseButton ) :: Exit(29) 
		Endif
		if (t_Replace = MouseButton ) :: Exit(30) 
		Endif
		if (t_Syntax = MouseButton ) :: Exit(31) 
		Endif
		if (t_Search = MouseButton ) :: Exit(32) 
		Endif
		if (t_Trace = MouseButton ) :: Exit(33) 
		Endif
		if (t_InsertSwitch = MouseButton ) :: Exit(34) 
		Endif
		if (t_SelectSwitch = MouseButton ) :: Exit(35) 
		Endif
		if (t_First = MouseButton ) :: Exit(37) 
		Endif
		if (t_Previous = MouseButton ) :: Exit(38) 
		Endif
		if (t_Widget = MouseButton ) :: Exit(39) 
		Endif
		if (t_Method = MouseButton ) :: Exit(40) 
		Endif
		if (t_Next = MouseButton ) :: Exit(41) 
		Endif
		if (t_Last = MouseButton ) :: Exit(42) 
		Endif
		Exit(-1)
	endif
	if ((MouseType and /030) = 0)
		Exit(0)
	Endif
	if ((MouseColumn >= 564 ) 		and (MouseRow >= 599 ) 		and (MouseColumn <= 864 ) 		and (MouseRow <= 619 ))
		;** StatusMessage3 
		if (a_StatusMessage3=0)
			Exit(__StatusMessage3)
		Endif
	Endif
	if ((MouseColumn >= 326 ) 		and (MouseRow >= 599 ) 		and (MouseColumn <= 558 ) 		and (MouseRow <= 615 ))
		;** StatusMessage2 
		if (a_StatusMessage2=0)
			Exit(__StatusMessage2)
		Endif
	Endif
	if ((MouseColumn >= 11 ) 		and (MouseRow >= 599 ) 		and (MouseColumn <= 319 ) 		and (MouseRow <= 615 ))
		;** StatusMessage1 
		if (a_StatusMessage1=0)
			Exit(__StatusMessage1)
		Endif
	Endif
	if ((MouseColumn >= 540 ) 		and (MouseRow >= 140 ) 		and (MouseColumn <= 640 ) 		and (MouseRow <= 160 ))
		;** Last 
		if (a_Last=0)
			Exit(__Last)
		Endif
	Endif
	if ((MouseColumn >= 540 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 640 ) 		and (MouseRow <= 140 ))
		;** Next 
		if (a_Next=0)
			Exit(__Next)
		Endif
	Endif
	if ((MouseColumn >= 540 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 640 ) 		and (MouseRow <= 120 ))
		;** Method 
		if (a_Method=0)
			Exit(__Method)
		Endif
	Endif
	if ((MouseColumn >= 540 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 640 ) 		and (MouseRow <= 100 ))
		;** Widget 
		if (a_Widget=0)
			Exit(__Widget)
		Endif
	Endif
	if ((MouseColumn >= 540 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 640 ) 		and (MouseRow <= 80 ))
		;** Previous 
		if (a_Previous=0)
			Exit(__Previous)
		Endif
	Endif
	if ((MouseColumn >= 540 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 640 ) 		and (MouseRow <= 60 ))
		;** First 
		if (a_First=0)
			Exit(__First)
		Endif
	Endif
	if ((MouseColumn >= 692 ) 		and (MouseRow >= 6 ) 		and (MouseColumn <= 723 ) 		and (MouseRow <= 22 ))
		;** LineNumber 
		if (a_LineNumber=0)
			Exit(__LineNumber)
		Endif
	Endif
	if ((MouseColumn >= 656 ) 		and (MouseRow >= 6 ) 		and (MouseColumn <= 688 ) 		and (MouseRow <= 22 ))
		;** SelectSwitch 
		if (a_SelectSwitch=0)
			Exit(__SelectSwitch)
		Endif
	Endif
	if ((MouseColumn >= 620 ) 		and (MouseRow >= 6 ) 		and (MouseColumn <= 652 ) 		and (MouseRow <= 22 ))
		;** InsertSwitch 
		if (a_InsertSwitch=0)
			Exit(__InsertSwitch)
		Endif
	Endif
	if ((MouseColumn >= 510 ) 		and (MouseRow >= 4 ) 		and (MouseColumn <= 590 ) 		and (MouseRow <= 24 ))
		;** Trace 
		if (a_Trace=0)
			Exit(__Trace)
		Endif
	Endif
	if ((MouseColumn >= 430 ) 		and (MouseRow >= 88 ) 		and (MouseColumn <= 520 ) 		and (MouseRow <= 108 ))
		;** Search 
		if (a_Search=0)
			Exit(__Search)
		Endif
	Endif
	if ((MouseColumn >= 430 ) 		and (MouseRow >= 72 ) 		and (MouseColumn <= 520 ) 		and (MouseRow <= 92 ))
		;** Syntax 
		if (a_Syntax=0)
			Exit(__Syntax)
		Endif
	Endif
	if ((MouseColumn >= 430 ) 		and (MouseRow >= 56 ) 		and (MouseColumn <= 520 ) 		and (MouseRow <= 76 ))
		;** Replace 
		if (a_Replace=0)
			Exit(__Replace)
		Endif
	Endif
	if ((MouseColumn >= 430 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 520 ) 		and (MouseRow <= 60 ))
		;** Find 
		if (a_Find=0)
			Exit(__Find)
		Endif
	Endif
	if ((MouseColumn >= 420 ) 		and (MouseRow >= 4 ) 		and (MouseColumn <= 510 ) 		and (MouseRow <= 24 ))
		;** Editor 
		if (a_Editor=0)
			Exit(__Editor)
		Endif
	Endif
	if ((MouseColumn >= 310 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 410 ) 		and (MouseRow <= 140 ))
		;** Animate 
		if (a_Animate=0)
			Exit(__Animate)
		Endif
	Endif
	if ((MouseColumn >= 310 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 410 ) 		and (MouseRow <= 120 ))
		;** ScreenCapture 
		if (a_ScreenCapture=0)
			Exit(__ScreenCapture)
		Endif
	Endif
	if ((MouseColumn >= 310 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 410 ) 		and (MouseRow <= 100 ))
		;** Configure 
		if (a_Configure=0)
			Exit(__Configure)
		Endif
	Endif
	if ((MouseColumn >= 310 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 410 ) 		and (MouseRow <= 80 ))
		;** Refresh 
		if (a_Refresh=0)
			Exit(__Refresh)
		Endif
	Endif
	if ((MouseColumn >= 310 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 410 ) 		and (MouseRow <= 60 ))
		;** Parameters 
		if (a_Parameters=0)
			Exit(__Parameters)
		Endif
	Endif
	if ((MouseColumn >= 330 ) 		and (MouseRow >= 4 ) 		and (MouseColumn <= 420 ) 		and (MouseRow <= 24 ))
		;** Options 
		if (a_Options=0)
			Exit(__Options)
		Endif
	Endif
	if ((MouseColumn >= 240 ) 		and (MouseRow >= 4 ) 		and (MouseColumn <= 330 ) 		and (MouseRow <= 24 ))
		;** Event 
		if (a_Event=0)
			Exit(__Event)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 180 ) 		and (MouseColumn <= 248 ) 		and (MouseRow <= 200 ))
		;** Application 
		if (a_Application=0)
			Exit(__Application)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 160 ) 		and (MouseColumn <= 248 ) 		and (MouseRow <= 180 ))
		;** TreeView 
		if (a_TreeView=0)
			Exit(__TreeView)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 140 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 160 ))
		;** Visual 
		if (a_Visual=0)
			Exit(__Visual)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 140 ))
		;** Properties 
		if (a_Properties=0)
			Exit(__Properties)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 120 ))
		;** Font 
		if (a_Font=0)
			Exit(__Font)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 100 ))
		;** Image 
		if (a_Image=0)
			Exit(__Image)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 80 ))
		;** Text 
		if (a_Text=0)
			Exit(__Text)
		Endif
	Endif
	if ((MouseColumn >= 160 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 60 ))
		;** Run 
		if (a_Run=0)
			Exit(__Run)
		Endif
	Endif
	if ((MouseColumn >= 150 ) 		and (MouseRow >= 4 ) 		and (MouseColumn <= 240 ) 		and (MouseRow <= 24 ))
		;** View 
		if (a_View=0)
			Exit(__View)
		Endif
	Endif
	if ((MouseColumn >= 50 ) 		and (MouseRow >= 160 ) 		and (MouseColumn <= 140 ) 		and (MouseRow <= 180 ))
		;** Quit 
		if (a_Quit=0)
			Exit(__Quit)
		Endif
	Endif
	if ((MouseColumn >= 50 ) 		and (MouseRow >= 140 ) 		and (MouseColumn <= 140 ) 		and (MouseRow <= 160 ))
		;** Drop 
		if (a_Drop=0)
			Exit(__Drop)
		Endif
	Endif
	if ((MouseColumn >= 50 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 140 ) 		and (MouseRow <= 140 ))
		;** Production 
		if (a_Production=0)
			Exit(__Production)
		Endif
	Endif
	if ((MouseColumn >= 50 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 140 ) 		and (MouseRow <= 120 ))
		;** Open 
		if (a_Open=0)
			Exit(__Open)
		Endif
	Endif
	if ((MouseColumn >= 50 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 140 ) 		and (MouseRow <= 100 ))
		;** SaveAs 
		if (a_SaveAs=0)
			Exit(__SaveAs)
		Endif
	Endif
	if ((MouseColumn >= 50 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 140 ) 		and (MouseRow <= 80 ))
		;** Save 
		if (a_Save=0)
			Exit(__Save)
		Endif
	Endif
	if ((MouseColumn >= 50 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 140 ) 		and (MouseRow <= 60 ))
		;** New 
		if (a_New=0)
			Exit(__New)
		Endif
	Endif
	if ((MouseColumn >= 60 ) 		and (MouseRow >= 4 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 24 ))
		;** File 
		if (a_File=0)
			Exit(__File)
		Endif
	Endif
	if ((MouseColumn >= 840 ) 		and (MouseRow >= 4 ) 		and (MouseColumn <= 864 ) 		and (MouseRow <= 29 ))
		;** PaletteControl 
		if (a_PaletteControl=0)
			Exit(__PaletteControl)
		Endif
	Endif
	if ((MouseColumn >= 19 ) 		and (MouseRow >= 2 ) 		and (MouseColumn <= 44 ) 		and (MouseRow <= 27 ))
		;** ToolBarControl 
		if (a_ToolBarControl=0)
			Exit(__ToolBarControl)
		Endif
	Endif
	if ((MouseColumn >= 860 ) 		and (MouseRow >= 32 ) 		and (MouseColumn <= 880 ) 		and (MouseRow <= 589 ))
		;** Auto962 
		Exit(__Auto962)
	Endif
	Exit(-1)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc OnLosefocus() : % 
	On Local Error Goto &elabel1,Status
	Exit(0)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc OnFocus() : % 
	Dcl	v_access#		;** Pour tester le changement de focus 
	On Local Error Goto &elabel1,Status
	FocusItems=45
	While (VisualKey(0) <> 0) 
		KeyCode=VisualKey(1) 
	Wend
	Do
&Continue
		Event(0)=(Event(5) and /FEFF)
		LastFocus=FocusItem
		Select(FocusItem)
		Case __Auto962
			;** Auto962 
			KeyCode=VisualKey(1)
		Case __Save
			;** Save 
			Status=VisualButton(50,60,90,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(50,60,90,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0020)
		Case __SaveAs
			;** SaveAs 
			Status=VisualButton(50,80,90,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(50,80,90,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0020)
		Case __Open
			;** Open 
			Status=VisualButton(50,100,90,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(50,100,90,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0020)
		Case __Production
			;** Production 
			Status=VisualButton(50,120,90,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(50,120,90,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0020)
		Case __Drop
			;** Drop 
			Status=VisualButton(50,140,90,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(50,140,90,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0020)
		Case __Quit
			;** Quit 
			Status=VisualButton(50,160,90,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(50,160,90,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0020)
		Case __Text
			;** Text 
			Status=VisualButton(160,60,90,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(160,60,90,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0020)
		Case __Image
			;** Image 
			Status=VisualButton(160,80,90,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(160,80,90,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0020)
		Case __Font
			;** Font 
			Status=VisualButton(160,100,90,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(160,100,90,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0020)
		Case __Properties
			;** Properties 
			Status=VisualButton(160,120,90,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(160,120,90,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0020)
		Case __Visual
			;** Visual 
			Status=VisualButton(160,140,90,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(160,140,90,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0020)
		Case __TreeView
			;** TreeView 
			Status=VisualButton(160,160,88,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(160,160,88,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0020)
		Case __Refresh
			;** Refresh 
			Status=VisualButton(310,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(310,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0020)
		Case __Configure
			;** Configure 
			Status=VisualButton(310,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(310,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0020)
		Case __ScreenCapture
			;** ScreenCapture 
			Status=VisualButton(310,100,100,20,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(310,100,100,20,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0020)
		Case __Animate
			;** Animate 
			Status=VisualButton(310,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(310,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0020)
		Case __Editor
			;** Editor 
			Status=VisualButton(420,4,90,20,FontHandle(2),16,0,msg_Editor(NationalLanguage),Len(msg_Editor(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(420,4,90,20,FontHandle(2),16,0,msg_Editor(NationalLanguage),Len(msg_Editor(NationalLanguage)),/0020)
		Case __Replace
			;** Replace 
			Status=VisualButton(430,56,90,20,FontHandle(2),16,0,msg_Replace(NationalLanguage),Len(msg_Replace(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(430,56,90,20,FontHandle(2),16,0,msg_Replace(NationalLanguage),Len(msg_Replace(NationalLanguage)),/0020)
		Case __Syntax
			;** Syntax 
			Status=VisualButton(430,72,90,20,FontHandle(2),16,0,msg_Syntax(NationalLanguage),Len(msg_Syntax(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(430,72,90,20,FontHandle(2),16,0,msg_Syntax(NationalLanguage),Len(msg_Syntax(NationalLanguage)),/0020)
		Case __Search
			;** Search 
			Status=VisualButton(430,88,90,20,FontHandle(2),16,0,msg_Search(NationalLanguage),Len(msg_Search(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(430,88,90,20,FontHandle(2),16,0,msg_Search(NationalLanguage),Len(msg_Search(NationalLanguage)),/0020)
		Case __Trace
			;** Trace 
			Status=VisualButton(510,4,80,20,FontHandle(2),28,21,msg_Trace(NationalLanguage),Len(msg_Trace(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(510,4,80,20,FontHandle(2),28,21,msg_Trace(NationalLanguage),Len(msg_Trace(NationalLanguage)),/0020)
		Case __InsertSwitch
			;** InsertSwitch 
			Status=VisualSwitch(620,6,32,16,FontHandle(1),28,29,msg_InsertSwitch(NationalLanguage),Len(msg_InsertSwitch(NationalLanguage)),((v_InsertSwitch or 2) or /0000))
			KeyCode=VisualKey(1)
			Status=VisualSwitch(620,6,32,16,FontHandle(1),28,29,msg_InsertSwitch(NationalLanguage),Len(msg_InsertSwitch(NationalLanguage)),(v_InsertSwitch or /0000))
		Case __SelectSwitch
			;** SelectSwitch 
			Status=VisualSwitch(656,6,32,16,FontHandle(1),28,29,msg_SelectSwitch(NationalLanguage),Len(msg_SelectSwitch(NationalLanguage)),((v_SelectSwitch or 2) or /0000))
			KeyCode=VisualKey(1)
			Status=VisualSwitch(656,6,32,16,FontHandle(1),28,29,msg_SelectSwitch(NationalLanguage),Len(msg_SelectSwitch(NationalLanguage)),(v_SelectSwitch or /0000))
		Case __LineNumber
			;** LineNumber 
			KeyCode=VisualEdit(692+1,6+1,31,16,FontHandle(1),b_LineNumber,3,0)
			if (a_LineNumber <> 1)	;** affichage si diff‚rent de 1
				LineNumberOnshow()
			endif
		Case __First
			;** First 
			Status=VisualButton(540,40,100,20,FontHandle(2),28,21,msg_First(NationalLanguage),Len(msg_First(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(540,40,100,20,FontHandle(2),28,21,msg_First(NationalLanguage),Len(msg_First(NationalLanguage)),/0020)
		Case __Previous
			;** Previous 
			Status=VisualButton(540,60,100,20,FontHandle(2),28,21,msg_Previous(NationalLanguage),Len(msg_Previous(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(540,60,100,20,FontHandle(2),28,21,msg_Previous(NationalLanguage),Len(msg_Previous(NationalLanguage)),/0020)
		Case __Widget
			;** Widget 
			Status=VisualButton(540,80,100,20,FontHandle(2),28,21,msg_Widget(NationalLanguage),Len(msg_Widget(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(540,80,100,20,FontHandle(2),28,21,msg_Widget(NationalLanguage),Len(msg_Widget(NationalLanguage)),/0020)
		Case __Method
			;** Method 
			Status=VisualButton(540,100,100,20,FontHandle(2),28,21,msg_Method(NationalLanguage),Len(msg_Method(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(540,100,100,20,FontHandle(2),28,21,msg_Method(NationalLanguage),Len(msg_Method(NationalLanguage)),/0020)
		Case __Next
			;** Next 
			Status=VisualButton(540,120,100,20,FontHandle(2),28,21,msg_Next(NationalLanguage),Len(msg_Next(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(540,120,100,20,FontHandle(2),28,21,msg_Next(NationalLanguage),Len(msg_Next(NationalLanguage)),/0020)
		Case __Last
			;** Last 
			Status=VisualButton(540,140,100,20,FontHandle(2),28,21,msg_Last(NationalLanguage),Len(msg_Last(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(540,140,100,20,FontHandle(2),28,21,msg_Last(NationalLanguage),Len(msg_Last(NationalLanguage)),/0020)
		Case __StatusMessage1
			;** StatusMessage1 
			KeyCode=VisualEdit(11+1,599+1,308,16,FontHandle(1),b_StatusMessage1,38,3)
			if (a_StatusMessage1 <> 1)	;** affichage si diff‚rent de 1
				StatusMessage1Onshow()
			endif
		Case __StatusMessage2
			;** StatusMessage2 
			KeyCode=VisualEdit(326+1,599+1,232,16,FontHandle(1),b_StatusMessage2,29,3)
			if (a_StatusMessage2 <> 1)	;** affichage si diff‚rent de 1
				StatusMessage2Onshow()
			endif
		Case __StatusMessage3
			;** StatusMessage3 
			KeyCode=VisualEdit(564+1,599+1,300,20,FontHandle(1),b_StatusMessage3,37,3)
			if (a_StatusMessage3 <> 1)	;** affichage si diff‚rent de 1
				StatusMessage3Onshow()
			endif
		Default
			KeyCode=5
		EndSel
&Retry
		Select(KeyCode)
		Case	0
			Goto &Continue
		Case	12
			FocusItem=1
			Status = OnShow()
			Goto &Continue
		Case	2
			FocusItem=45
			Status = OnShow()
			Goto &Continue
		Case	256
			Status=VisualEvent(MouseEvent)
			Status=OnEvent()
			if (Status = 0)
				Goto &Continue
			Else
				FocusItem=Status
			Endif
			Select(FocusItem)
			Case __Auto962
				;** Auto962 
				Status = Auto962Action()
				Goto &Continue
			Case __ToolBarControl
				;** ToolBarControl 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(19,2,25,25,FontHandle(1),27,0,msg_ToolBarControl(NationalLanguage),Len(msg_ToolBarControl(NationalLanguage)),/0034)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(19,2,25,25,FontHandle(1),27,0,msg_ToolBarControl(NationalLanguage),Len(msg_ToolBarControl(NationalLanguage)),/0030)
				Endif
				Goto &Continue
			Case __PaletteControl
				;** PaletteControl 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(840,4,24,25,FontHandle(2),16,0,msg_PaletteControl(NationalLanguage),Len(msg_PaletteControl(NationalLanguage)),/0034)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(840,4,24,25,FontHandle(2),16,0,msg_PaletteControl(NationalLanguage),Len(msg_PaletteControl(NationalLanguage)),/0030)
				Endif
				Goto &Continue
			Case __File
				;** File 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(60,4,90,20,FontHandle(2),16,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(60,4,90,20,FontHandle(2),16,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __New
				;** New 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(50,40,90,20,FontHandle(2),16,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(50,40,90,20,FontHandle(2),16,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Save
				;** Save 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(50,60,90,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(50,60,90,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __SaveAs
				;** SaveAs 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(50,80,90,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(50,80,90,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Open
				;** Open 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(50,100,90,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(50,100,90,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Production
				;** Production 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(50,120,90,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(50,120,90,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Drop
				;** Drop 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(50,140,90,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(50,140,90,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Quit
				;** Quit 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(50,160,90,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(50,160,90,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __View
				;** View 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(150,4,90,20,FontHandle(2),16,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(150,4,90,20,FontHandle(2),16,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Run
				;** Run 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,40,90,20,FontHandle(2),16,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,40,90,20,FontHandle(2),16,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Text
				;** Text 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,60,90,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,60,90,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Image
				;** Image 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,80,90,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,80,90,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Font
				;** Font 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,100,90,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,100,90,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Properties
				;** Properties 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,120,90,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,120,90,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Visual
				;** Visual 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,140,90,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,140,90,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __TreeView
				;** TreeView 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,160,88,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,160,88,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Application
				;** Application 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(160,180,88,20,FontHandle(2),16,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(160,180,88,20,FontHandle(2),16,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Event
				;** Event 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(240,4,90,20,FontHandle(2),16,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(240,4,90,20,FontHandle(2),16,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Options
				;** Options 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(330,4,90,20,FontHandle(2),16,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(330,4,90,20,FontHandle(2),16,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Parameters
				;** Parameters 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(310,40,100,20,FontHandle(2),16,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(310,40,100,20,FontHandle(2),16,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Refresh
				;** Refresh 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(310,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(310,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Configure
				;** Configure 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(310,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(310,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __ScreenCapture
				;** ScreenCapture 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(310,100,100,20,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(310,100,100,20,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Animate
				;** Animate 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(310,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(310,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Editor
				;** Editor 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(420,4,90,20,FontHandle(2),16,0,msg_Editor(NationalLanguage),Len(msg_Editor(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(420,4,90,20,FontHandle(2),16,0,msg_Editor(NationalLanguage),Len(msg_Editor(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Find
				;** Find 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(430,40,90,20,FontHandle(2),16,0,msg_Find(NationalLanguage),Len(msg_Find(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(430,40,90,20,FontHandle(2),16,0,msg_Find(NationalLanguage),Len(msg_Find(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Replace
				;** Replace 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(430,56,90,20,FontHandle(2),16,0,msg_Replace(NationalLanguage),Len(msg_Replace(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(430,56,90,20,FontHandle(2),16,0,msg_Replace(NationalLanguage),Len(msg_Replace(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Syntax
				;** Syntax 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(430,72,90,20,FontHandle(2),16,0,msg_Syntax(NationalLanguage),Len(msg_Syntax(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(430,72,90,20,FontHandle(2),16,0,msg_Syntax(NationalLanguage),Len(msg_Syntax(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Search
				;** Search 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(430,88,90,20,FontHandle(2),16,0,msg_Search(NationalLanguage),Len(msg_Search(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(430,88,90,20,FontHandle(2),16,0,msg_Search(NationalLanguage),Len(msg_Search(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Trace
				;** Trace 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(510,4,80,20,FontHandle(2),28,21,msg_Trace(NationalLanguage),Len(msg_Trace(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(510,4,80,20,FontHandle(2),28,21,msg_Trace(NationalLanguage),Len(msg_Trace(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __InsertSwitch
				;** InsertSwitch 
				if ((MouseType and _MIMO_UP) <> 0)
					v_InsertSwitch = v_InsertSwitch + 1
					v_InsertSwitch = v_InsertSwitch and 1
				Endif
				Goto &Continue
			Case __SelectSwitch
				;** SelectSwitch 
				if ((MouseType and _MIMO_UP) <> 0)
					v_SelectSwitch = v_SelectSwitch + 1
					v_SelectSwitch = v_SelectSwitch and 1
				Endif
				Goto &Continue
			Case __LineNumber
				;** LineNumber 
				Goto &Continue
			Case __First
				;** First 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(540,40,100,20,FontHandle(2),28,21,msg_First(NationalLanguage),Len(msg_First(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(540,40,100,20,FontHandle(2),28,21,msg_First(NationalLanguage),Len(msg_First(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Previous
				;** Previous 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(540,60,100,20,FontHandle(2),28,21,msg_Previous(NationalLanguage),Len(msg_Previous(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(540,60,100,20,FontHandle(2),28,21,msg_Previous(NationalLanguage),Len(msg_Previous(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Widget
				;** Widget 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(540,80,100,20,FontHandle(2),28,21,msg_Widget(NationalLanguage),Len(msg_Widget(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(540,80,100,20,FontHandle(2),28,21,msg_Widget(NationalLanguage),Len(msg_Widget(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Method
				;** Method 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(540,100,100,20,FontHandle(2),28,21,msg_Method(NationalLanguage),Len(msg_Method(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(540,100,100,20,FontHandle(2),28,21,msg_Method(NationalLanguage),Len(msg_Method(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Next
				;** Next 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(540,120,100,20,FontHandle(2),28,21,msg_Next(NationalLanguage),Len(msg_Next(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(540,120,100,20,FontHandle(2),28,21,msg_Next(NationalLanguage),Len(msg_Next(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Last
				;** Last 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(540,140,100,20,FontHandle(2),28,21,msg_Last(NationalLanguage),Len(msg_Last(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(540,140,100,20,FontHandle(2),28,21,msg_Last(NationalLanguage),Len(msg_Last(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __StatusMessage1
				;** StatusMessage1 
				Goto &Continue
			Case __StatusMessage2
				;** StatusMessage2 
				Goto &Continue
			Case __StatusMessage3
				;** StatusMessage3 
				Goto &Continue
			Default
				FocusItem=1
				Goto &Continue
			EndSel
			Break
		Case	27
			Break
		Case	13
			repeat
				If(FocusItem < FocusItems)
					FocusItem = FocusItem+1
				Else
					FocusItem = 1
				Endif
				v_access = value_access(FocusItem)
			until (v_access = 0)
			Goto &Continue
		Case	9,5
			repeat
				If(FocusItem < FocusItems)
					FocusItem = FocusItem+1
				Else
					FocusItem = 1
				Endif
				v_access = value_access(FocusItem)
			until (v_access = 0)
			Goto &Continue
		Default
			Goto &Continue
		EndSel
		Break
	Loop
	Exit(KeyCode)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc OnAttach(gmode%) : %
	On Local Error Goto &elabel1,Status
	If(VisualInitialise(gmode+256) = -1 )
		Error 56
	Else
		If(VisualPalette("grisstd.rgb",11) <> 0 )
			Error 40
		Endif
	Endif
	FontHandle(1) = VisualFont("standard.fmf",12)
	FontHandle(2) = VisualFont("arial2.fmf",10)
	FontHandle(3) = VisualFont("arial3.fmf",10)
	FontHandle(4) = VisualFont("arial4.fmf",10)
	FontHandle(5) = VisualFont("arial5.fmf",10)
	FontHandle(6) = VisualFont("arial6.fmf",10)
	FontHandle(7) = VisualFont("font7.fmf",9)
	FontHandle(8) = VisualFont("font8.fmf",9)
	FontHandle(9) = VisualFont("font9.fmf",9)
	FontHandle(10) = VisualFont("standard.fmf",12)
	Exit(0)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc OnDetach() : %
	On Local Error Goto &elabel1,Status
	If(VisualLiberate()= -1)
		Error 56
	Endif
	Exit(0)
&elabel1
	On Local Error Abort
	Error Status
EndProc
Segment 0
	On Local Error Goto &elabel1,Status
	Status=OnCreate()
	if (Status=0)
		Status=OnShow()
		Status=OnFocus()
		Status=OnHide()
		Status=OnRemove()
	Endif
	Stop
&elabel1
	On Local Error Abort
	Stop
Eseg 0
End
;** End of File 
