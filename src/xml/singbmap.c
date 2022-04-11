;** ------------------------------------------------------------------------- 
;** Warning : this file has been generated and should not be modified by hand 
;** ------------------------------------------------------------------------- 
;** Sing Version   : 2.1a.0.33  
;** Production     : ABAL  
;** Project        : singbmap.xml  
;** Target         : singbmap.c  
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
Const en_Auto959$=" "
Const fr_Auto959$=" "
Const it_Auto959$=" "
Const es_Auto959$=" "
Const de_Auto959$=" "
Const nl_Auto959$=" "
Const pt_Auto959$=" "
Const xx_Auto959$=" "
Const en_Auto960$=" "
Const fr_Auto960$=" "
Const it_Auto960$=" "
Const es_Auto960$=" "
Const de_Auto960$=" "
Const nl_Auto960$=" "
Const pt_Auto960$=" "
Const xx_Auto960$=" "
Const en_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const fr_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const it_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const es_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const de_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const nl_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const pt_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const xx_ImageData$="/home/Dev/abal32/sing/zoomer.gif"
Const en_Auto961$=" "
Const fr_Auto961$=" "
Const it_Auto961$=" "
Const es_Auto961$=" "
Const de_Auto961$=" "
Const nl_Auto961$=" "
Const pt_Auto961$=" "
Const xx_Auto961$=" "
Const en_Auto962$=" "
Const fr_Auto962$=" "
Const it_Auto962$=" "
Const es_Auto962$=" "
Const de_Auto962$=" "
Const nl_Auto962$=" "
Const pt_Auto962$=" "
Const xx_Auto962$=" "
Const en_ToolBarControl$="upicon.gif"
Const fr_ToolBarControl$="upicon.gif"
Const it_ToolBarControl$="upicon.gif"
Const es_ToolBarControl$="upicon.gif"
Const de_ToolBarControl$="upicon.gif"
Const nl_ToolBarControl$="upicon.gif"
Const pt_ToolBarControl$="upicon.gif"
Const xx_ToolBarControl$="upicon.gif"
Const en_Auto963$=" "
Const fr_Auto963$=" "
Const it_Auto963$=" "
Const es_Auto963$=" "
Const de_Auto963$=" "
Const nl_Auto963$=" "
Const pt_Auto963$=" "
Const xx_Auto963$=" "
Const en_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const fr_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const it_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const es_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const de_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const nl_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const pt_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const xx_ImageTools$="/home/Dev/abal32/sing/itoolbar.gif"
Const en_Auto964$=" "
Const fr_Auto964$=" "
Const it_Auto964$=" "
Const es_Auto964$=" "
Const de_Auto964$=" "
Const nl_Auto964$=" "
Const pt_Auto964$=" "
Const xx_Auto964$=" "
Const en_PaletteControl$="upicon.gif"
Const fr_PaletteControl$="upicon.gif"
Const it_PaletteControl$="upicon.gif"
Const es_PaletteControl$="upicon.gif"
Const de_PaletteControl$="upicon.gif"
Const nl_PaletteControl$="upicon.gif"
Const pt_PaletteControl$="upicon.gif"
Const xx_PaletteControl$="upicon.gif"
Const en_Palette$="/home/Dev/abal32/sing/palette.gif"
Const fr_Palette$="/home/Dev/abal32/sing/palette.gif"
Const it_Palette$="/home/Dev/abal32/sing/palette.gif"
Const es_Palette$="/home/Dev/abal32/sing/palette.gif"
Const de_Palette$="/home/Dev/abal32/sing/palette.gif"
Const nl_Palette$="/home/Dev/abal32/sing/palette.gif"
Const pt_Palette$="/home/Dev/abal32/sing/palette.gif"
Const xx_Palette$="/home/Dev/abal32/sing/palette.gif"
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
Const it_New$="&Novo"
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
Const es_SaveAs$="Sal&var"
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
Const en_Images$="&Image"
Const fr_Images$="&Image"
Const it_Images$="&Image"
Const es_Images$="&Image"
Const de_Images$="&Image"
Const nl_Images$="&Image"
Const pt_Images$="&Image"
Const xx_Images$="&Image"
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
Const fr_Visual$="&Visuelle"
Const it_Visual$="screener"
Const es_Visual$="screener"
Const de_Visual$="screener"
Const nl_Visual$="screener"
Const pt_Visual$="screener"
Const xx_Visual$="screener"
Const en_TreeView$="Tr&eeView"
Const fr_TreeView$="Ar&borescence"
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
Const en_ScreenCapture$="&ScreenCapture"
Const fr_ScreenCapture$="&Capture Ecran"
Const it_ScreenCapture$="&ScreenCapture"
Const es_ScreenCapture$="&ScreenCapture"
Const de_ScreenCapture$="&ScreenCapture"
Const nl_ScreenCapture$="&ScreenCapture"
Const pt_ScreenCapture$="&ScreenCapture"
Const xx_ScreenCapture$="&ScreenCapture"
Const en_Animate$="&Animate"
Const fr_Animate$="&Animer"
Const it_Animate$="&Animate"
Const es_Animate$="&Animate"
Const de_Animate$="&Animate"
Const nl_Animate$="&Animate"
Const pt_Animate$="&Animate"
Const xx_Animate$="&Animate"
Const en_Image$="&Image"
Const fr_Image$="&Image"
Const it_Image$="&Image"
Const es_Image$="&Image"
Const de_Image$="&Image"
Const nl_Image$="&Image"
Const pt_Image$="&Image"
Const xx_Image$="&Image"
Const en_Auto968$=" "
Const fr_Auto968$=" "
Const it_Auto968$=" "
Const es_Auto968$=" "
Const de_Auto968$=" "
Const nl_Auto968$=" "
Const pt_Auto968$=" "
Const xx_Auto968$=" "
Const en_Copy$="&Copy"
Const fr_Copy$="&Copier"
Const it_Copy$="&Copy"
Const es_Copy$="&Copy"
Const de_Copy$="&Copy"
Const nl_Copy$="&Copy"
Const pt_Copy$="&Copy"
Const xx_Copy$="&Copy"
Const en_Paste$="&Paste"
Const fr_Paste$="Co&ller"
Const it_Paste$="&Paste"
Const es_Paste$="&Paste"
Const de_Paste$="&Paste"
Const nl_Paste$="&Paste"
Const pt_Paste$="&Paste"
Const xx_Paste$="&Paste"
Const en_Cut$="C&ut"
Const fr_Cut$="C&ouper"
Const it_Cut$="C&ut"
Const es_Cut$="C&ut"
Const de_Cut$="C&ut"
Const nl_Cut$="C&ut"
Const pt_Cut$="C&ut"
Const xx_Cut$="C&ut"
Const en_Rotate90$="&Rotate 90"
Const fr_Rotate90$="&Rotation 90"
Const it_Rotate90$="&Rotate 90"
Const es_Rotate90$="&Rotate 90"
Const de_Rotate90$="&Rotate 90"
Const nl_Rotate90$="&Rotate 90"
Const pt_Rotate90$="&Rotate 90"
Const xx_Rotate90$="&Rotate 90"
Const en_Rotate180$="R&otate 180"
Const fr_Rotate180$="Rotation 1&80"
Const it_Rotate180$="R&otate 180"
Const es_Rotate180$="R&otate 180"
Const de_Rotate180$="R&otate 180"
Const nl_Rotate180$="R&otate 180"
Const pt_Rotate180$="R&otate 180"
Const xx_Rotate180$="R&otate 180"
Const en_Rotate270$="Ro&tate 270"
Const fr_Rotate270$="Rotation 2&70"
Const it_Rotate270$="Ro&tate 270"
Const es_Rotate270$="Ro&tate 270"
Const de_Rotate270$="Ro&tate 270"
Const nl_Rotate270$="Ro&tate 270"
Const pt_Rotate270$="Ro&tate 270"
Const xx_Rotate270$="Ro&tate 270"
Const en_ChangeColour$="&Change Colour"
Const fr_ChangeColour$="&Changer Couleur"
Const it_ChangeColour$="&Change Colour"
Const es_ChangeColour$="&Change Colour"
Const de_ChangeColour$="&Change Colour"
Const nl_ChangeColour$="&Change Colour"
Const pt_ChangeColour$="&Change Colour"
Const xx_ChangeColour$="&Change Colour"
Const en_GreyScale$="&Grey Scale"
Const fr_GreyScale$="&D‚grad‚ de Gris"
Const it_GreyScale$="&Grey Scale"
Const es_GreyScale$="&Grey Scale"
Const de_GreyScale$="&Grey Scale"
Const nl_GreyScale$="&Grey Scale"
Const pt_GreyScale$="&Grey Scale"
Const xx_GreyScale$="&Grey Scale"
Const en_VerticalMirror$="&Vertical Mirror"
Const fr_VerticalMirror$="Sym‚trie &Verticale"
Const it_VerticalMirror$="&Vertical Mirror"
Const es_VerticalMirror$="&Vertical Mirror"
Const de_VerticalMirror$="&Vertical Mirror"
Const nl_VerticalMirror$="&Vertical Mirror"
Const pt_VerticalMirror$="&Vertical Mirror"
Const xx_VerticalMirror$="&Vertical Mirror"
Const en_HorizontalMirror$="&Horizontal Mirror"
Const fr_HorizontalMirror$="Sym‚trie &Horizontale"
Const it_HorizontalMirror$="&Horizontal Mirror"
Const es_HorizontalMirror$="&Horizontal Mirror"
Const de_HorizontalMirror$="&Horizontal Mirror"
Const nl_HorizontalMirror$="&Horizontal Mirror"
Const pt_HorizontalMirror$="&Horizontal Mirror"
Const xx_HorizontalMirror$="&Horizontal Mirror"
Const en_Dimensions$="&Dimensions"
Const fr_Dimensions$="D&imensions"
Const it_Dimensions$="&Dimensions"
Const es_Dimensions$="&Dimensions"
Const de_Dimensions$="&Dimensions"
Const nl_Dimensions$="&Dimensions"
Const pt_Dimensions$="&Dimensions"
Const xx_Dimensions$="&Dimensions"
Const en_Executer$="plusicon.gif"
Const fr_Executer$="plusicon.gif"
Const it_Executer$="plusicon.gif"
Const es_Executer$="plusicon.gif"
Const de_Executer$="plusicon.gif"
Const nl_Executer$="plusicon.gif"
Const pt_Executer$="plusicon.gif"
Const xx_Executer$="plusicon.gif"
Const en_Editor$="aedicon.gif"
Const fr_Editor$="aedicon.gif"
Const it_Editor$="aedicon.gif"
Const es_Editor$="aedicon.gif"
Const de_Editor$="aedicon.gif"
Const nl_Editor$="aedicon.gif"
Const pt_Editor$="aedicon.gif"
Const xx_Editor$="aedicon.gif"
Const en_Traducteur$="otricon.gif"
Const fr_Traducteur$="otricon.gif"
Const it_Traducteur$="otricon.gif"
Const es_Traducteur$="otricon.gif"
Const de_Traducteur$="otricon.gif"
Const nl_Traducteur$="otricon.gif"
Const pt_Traducteur$="otricon.gif"
Const xx_Traducteur$="otricon.gif"
Const en_Linker$="oldicon.gif"
Const fr_Linker$="oldicon.gif"
Const it_Linker$="oldicon.gif"
Const es_Linker$="oldicon.gif"
Const de_Linker$="oldicon.gif"
Const nl_Linker$="oldicon.gif"
Const pt_Linker$="oldicon.gif"
Const xx_Linker$="oldicon.gif"
Const en_Executeur$="vdbicon.gif"
Const fr_Executeur$="vdbicon.gif"
Const it_Executeur$="vdbicon.gif"
Const es_Executeur$="vdbicon.gif"
Const de_Executeur$="vdbicon.gif"
Const nl_Executeur$="vdbicon.gif"
Const pt_Executeur$="vdbicon.gif"
Const xx_Executeur$="vdbicon.gif"
Const en_Editeur$="aedicon.gif"
Const fr_Editeur$="aedicon.gif"
Const it_Editeur$="aedicon.gif"
Const es_Editeur$="aedicon.gif"
Const de_Editeur$="aedicon.gif"
Const nl_Editeur$="aedicon.gif"
Const pt_Editeur$="aedicon.gif"
Const xx_Editeur$="aedicon.gif"
Const en_Translate$="otricon.gif"
Const fr_Translate$="otricon.gif"
Const it_Translate$="otricon.gif"
Const es_Translate$="otricon.gif"
Const de_Translate$="otricon.gif"
Const nl_Translate$="otricon.gif"
Const pt_Translate$="otricon.gif"
Const xx_Translate$="otricon.gif"
Const en_Linkeur$="oldicon.gif"
Const fr_Linkeur$="oldicon.gif"
Const it_Linkeur$="oldicon.gif"
Const es_Linkeur$="oldicon.gif"
Const de_Linkeur$="oldicon.gif"
Const nl_Linkeur$="oldicon.gif"
Const pt_Linkeur$="oldicon.gif"
Const xx_Linkeur$="oldicon.gif"
Const en_Auto969$=" "
Const fr_Auto969$=" "
Const it_Auto969$=" "
Const es_Auto969$=" "
Const de_Auto969$=" "
Const nl_Auto969$=" "
Const pt_Auto969$=" "
Const xx_Auto969$=" "
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
Const __ToolBarControl%=1
Const __PaletteControl%=2
Const __File%=3
Const __New%=4
Const __Save%=5
Const __SaveAs%=6
Const __Open%=7
Const __Production%=8
Const __Drop%=9
Const __Quit%=10
Const __View%=11
Const __Run%=12
Const __Text%=13
Const __Images%=14
Const __Font%=15
Const __Properties%=16
Const __Visual%=17
Const __TreeView%=18
Const __Application%=19
Const __Event%=20
Const __Options%=21
Const __Parameters%=22
Const __Refresh%=23
Const __Configure%=24
Const __ScreenCapture%=25
Const __Animate%=26
Const __Image%=27
Const __Copy%=28
Const __Paste%=29
Const __Cut%=30
Const __Rotate90%=31
Const __Rotate180%=32
Const __Rotate270%=33
Const __ChangeColour%=34
Const __GreyScale%=35
Const __VerticalMirror%=36
Const __HorizontalMirror%=37
Const __Dimensions%=38
Const __StatusMessage1%=39
Const __StatusMessage2%=40
Const __StatusMessage3%=41
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
Dcl	msg_ImageData$=32(8)
Dcl	msg_ToolBarControl$=10(8)
Dcl	t_ToolBarControl%
Dcl	a_ToolBarControl%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_ImageTools$=34(8)
Dcl	msg_PaletteControl$=10(8)
Dcl	t_PaletteControl%
Dcl	a_PaletteControl%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Palette$=33(8)
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
Dcl	msg_Images$=6(8)
Dcl	t_Images%
Dcl	a_Images%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Font$=6(8)
Dcl	t_Font%
Dcl	a_Font%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Properties$=11(8)
Dcl	t_Properties%
Dcl	a_Properties%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Visual$=9(8)
Dcl	t_Visual%
Dcl	a_Visual%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_TreeView$=13(8)
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
Dcl	msg_ScreenCapture$=14(8)
Dcl	t_ScreenCapture%
Dcl	a_ScreenCapture%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Animate$=8(8)
Dcl	t_Animate%
Dcl	a_Animate%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Image$=6(8)
Dcl	t_Image%
Dcl	a_Image%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Copy$=7(8)
Dcl	t_Copy%
Dcl	a_Copy%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Paste$=7(8)
Dcl	t_Paste%
Dcl	a_Paste%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Cut$=7(8)
Dcl	t_Cut%
Dcl	a_Cut%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Rotate90$=12(8)
Dcl	t_Rotate90%
Dcl	a_Rotate90%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Rotate180$=13(8)
Dcl	t_Rotate180%
Dcl	a_Rotate180%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Rotate270$=13(8)
Dcl	t_Rotate270%
Dcl	a_Rotate270%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_ChangeColour$=16(8)
Dcl	t_ChangeColour%
Dcl	a_ChangeColour%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_GreyScale$=16(8)
Dcl	t_GreyScale%
Dcl	a_GreyScale%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_VerticalMirror$=19(8)
Dcl	t_VerticalMirror%
Dcl	a_VerticalMirror%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_HorizontalMirror$=21(8)
Dcl	t_HorizontalMirror%
Dcl	a_HorizontalMirror%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Dimensions$=11(8)
Dcl	t_Dimensions%
Dcl	a_Dimensions%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	msg_Executer$=12(8)
Dcl	msg_Editor$=11(8)
Dcl	msg_Traducteur$=11(8)
Dcl	msg_Linker$=11(8)
Dcl	msg_Executeur$=11(8)
Dcl	msg_Editeur$=11(8)
Dcl	msg_Translate$=11(8)
Dcl	msg_Linkeur$=11(8)
Dcl	a_StatusMessage1%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	b_StatusMessage1$=31		;** Buffer : user field 
Dcl	a_StatusMessage2%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	b_StatusMessage2$=29		;** Buffer : user field 
Dcl	a_StatusMessage3%		;** access : 0 pour normal, 1 pour invisible, 2 pour gris 
Dcl	b_StatusMessage3$=30		;** Buffer : user field 
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
Forward Proc StatusMessage1Onshow()
Forward Proc StatusMessage2Onshow()
Forward Proc StatusMessage3Onshow()
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
	Case __Images 
		Exit(a_Images)
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
	Case __Image 
		Exit(a_Image)
	Case __Copy 
		Exit(a_Copy)
	Case __Paste 
		Exit(a_Paste)
	Case __Cut 
		Exit(a_Cut)
	Case __Rotate90 
		Exit(a_Rotate90)
	Case __Rotate180 
		Exit(a_Rotate180)
	Case __Rotate270 
		Exit(a_Rotate270)
	Case __ChangeColour 
		Exit(a_ChangeColour)
	Case __GreyScale 
		Exit(a_GreyScale)
	Case __VerticalMirror 
		Exit(a_VerticalMirror)
	Case __HorizontalMirror 
		Exit(a_HorizontalMirror)
	Case __Dimensions 
		Exit(a_Dimensions)
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
	FocusItems=41
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
	Status = VisualControl(_VISUAL_TITLE,"Image_Editor",12)
	Status = VisualControl(_VISUAL_ICON,"exa",3)
	msg_ImageData(1)=en_ImageData
	msg_ImageData(2)=fr_ImageData
	msg_ImageData(3)=it_ImageData
	msg_ImageData(4)=es_ImageData
	msg_ImageData(5)=de_ImageData
	msg_ImageData(6)=nl_ImageData
	msg_ImageData(7)=pt_ImageData
	msg_ImageData(8)=xx_ImageData
	msg_ToolBarControl(1)=en_ToolBarControl
	msg_ToolBarControl(2)=fr_ToolBarControl
	msg_ToolBarControl(3)=it_ToolBarControl
	msg_ToolBarControl(4)=es_ToolBarControl
	msg_ToolBarControl(5)=de_ToolBarControl
	msg_ToolBarControl(6)=nl_ToolBarControl
	msg_ToolBarControl(7)=pt_ToolBarControl
	msg_ToolBarControl(8)=xx_ToolBarControl
	a_ToolBarControl=0 ;** initialise access : normal
	msg_ImageTools(1)=en_ImageTools
	msg_ImageTools(2)=fr_ImageTools
	msg_ImageTools(3)=it_ImageTools
	msg_ImageTools(4)=es_ImageTools
	msg_ImageTools(5)=de_ImageTools
	msg_ImageTools(6)=nl_ImageTools
	msg_ImageTools(7)=pt_ImageTools
	msg_ImageTools(8)=xx_ImageTools
	msg_PaletteControl(1)=en_PaletteControl
	msg_PaletteControl(2)=fr_PaletteControl
	msg_PaletteControl(3)=it_PaletteControl
	msg_PaletteControl(4)=es_PaletteControl
	msg_PaletteControl(5)=de_PaletteControl
	a_PaletteControl=0 ;** initialise access : normal
	msg_Palette(1)=en_Palette
	msg_Palette(2)=fr_Palette
	msg_Palette(3)=it_Palette
	msg_Palette(4)=es_Palette
	msg_Palette(5)=de_Palette
	msg_Palette(6)=nl_Palette
	msg_Palette(7)=pt_Palette
	msg_Palette(8)=xx_Palette
	msg_File(1)=en_File
	msg_File(2)=fr_File
	msg_File(3)=it_File
	msg_File(4)=es_File
	msg_File(5)=de_File
	msg_File(6)=nl_File
	msg_File(7)=pt_File
	msg_File(8)=xx_File
	a_File=0 ;** initialise access : normal
	msg_New(1)=en_New
	msg_New(2)=fr_New
	msg_New(3)=it_New
	msg_New(4)=es_New
	msg_New(5)=de_New
	msg_New(6)=nl_New
	msg_New(7)=pt_New
	msg_New(8)=xx_New
	a_New=0 ;** initialise access : normal
	msg_Save(1)=en_Save
	msg_Save(2)=fr_Save
	msg_Save(3)=it_Save
	msg_Save(4)=es_Save
	msg_Save(5)=de_Save
	msg_Save(6)=nl_Save
	msg_Save(7)=pt_Save
	msg_Save(8)=xx_Save
	a_Save=0 ;** initialise access : normal
	msg_SaveAs(1)=en_SaveAs
	msg_SaveAs(2)=fr_SaveAs
	msg_SaveAs(3)=it_SaveAs
	msg_SaveAs(4)=es_SaveAs
	msg_SaveAs(5)=de_SaveAs
	msg_SaveAs(6)=nl_SaveAs
	msg_SaveAs(7)=pt_SaveAs
	msg_SaveAs(8)=xx_SaveAs
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
	msg_Production(3)=it_Production
	msg_Production(4)=es_Production
	msg_Production(5)=de_Production
	msg_Production(6)=nl_Production
	msg_Production(7)=pt_Production
	msg_Production(8)=xx_Production
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
	msg_Quit(3)=it_Quit
	msg_Quit(4)=es_Quit
	msg_Quit(5)=de_Quit
	msg_Quit(6)=nl_Quit
	msg_Quit(7)=pt_Quit
	msg_Quit(8)=xx_Quit
	a_Quit=0 ;** initialise access : normal
	msg_View(1)=en_View
	msg_View(2)=fr_View
	msg_View(3)=it_View
	msg_View(4)=es_View
	msg_View(5)=de_View
	msg_View(6)=nl_View
	msg_View(7)=pt_View
	msg_View(8)=xx_View
	a_View=0 ;** initialise access : normal
	msg_Run(1)=en_Run
	msg_Run(2)=fr_Run
	msg_Run(3)=it_Run
	msg_Run(4)=es_Run
	msg_Run(5)=de_Run
	msg_Run(6)=nl_Run
	msg_Run(7)=pt_Run
	msg_Run(8)=xx_Run
	a_Run=0 ;** initialise access : normal
	msg_Text(1)=en_Text
	msg_Text(2)=fr_Text
	msg_Text(3)=it_Text
	msg_Text(4)=es_Text
	msg_Text(5)=de_Text
	msg_Text(6)=nl_Text
	msg_Text(7)=pt_Text
	msg_Text(8)=xx_Text
	a_Text=0 ;** initialise access : normal
	msg_Images(1)=en_Images
	msg_Images(2)=fr_Images
	msg_Images(3)=it_Images
	msg_Images(4)=es_Images
	msg_Images(5)=de_Images
	msg_Images(6)=nl_Images
	msg_Images(7)=pt_Images
	msg_Images(8)=xx_Images
	a_Images=0 ;** initialise access : normal
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
	msg_Properties(3)=it_Properties
	msg_Properties(4)=es_Properties
	msg_Properties(5)=de_Properties
	msg_Properties(6)=nl_Properties
	msg_Properties(7)=pt_Properties
	msg_Properties(8)=xx_Properties
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
	msg_TreeView(3)=it_TreeView
	msg_TreeView(4)=es_TreeView
	msg_TreeView(5)=de_TreeView
	msg_TreeView(6)=nl_TreeView
	msg_TreeView(7)=pt_TreeView
	msg_TreeView(8)=xx_TreeView
	a_TreeView=0 ;** initialise access : normal
	msg_Application(1)=en_Application
	msg_Application(2)=fr_Application
	msg_Application(3)=it_Application
	msg_Application(4)=es_Application
	msg_Application(5)=de_Application
	msg_Application(6)=nl_Application
	msg_Application(7)=pt_Application
	msg_Application(8)=xx_Application
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
	msg_Options(3)=it_Options
	msg_Options(4)=es_Options
	msg_Options(5)=de_Options
	msg_Options(6)=nl_Options
	msg_Options(7)=pt_Options
	msg_Options(8)=xx_Options
	a_Options=0 ;** initialise access : normal
	msg_Parameters(1)=en_Parameters
	msg_Parameters(2)=fr_Parameters
	msg_Parameters(3)=it_Parameters
	msg_Parameters(4)=es_Parameters
	msg_Parameters(5)=de_Parameters
	msg_Parameters(6)=nl_Parameters
	msg_Parameters(7)=pt_Parameters
	msg_Parameters(8)=xx_Parameters
	a_Parameters=0 ;** initialise access : normal
	msg_Refresh(1)=en_Refresh
	msg_Refresh(2)=fr_Refresh
	msg_Refresh(3)=it_Refresh
	msg_Refresh(4)=es_Refresh
	msg_Refresh(5)=de_Refresh
	msg_Refresh(6)=nl_Refresh
	msg_Refresh(7)=pt_Refresh
	msg_Refresh(8)=xx_Refresh
	a_Refresh=0 ;** initialise access : normal
	msg_Configure(1)=en_Configure
	msg_Configure(2)=fr_Configure
	msg_Configure(3)=it_Configure
	msg_Configure(4)=es_Configure
	msg_Configure(5)=de_Configure
	msg_Configure(6)=nl_Configure
	msg_Configure(7)=pt_Configure
	msg_Configure(8)=xx_Configure
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
	msg_Animate(3)=it_Animate
	msg_Animate(4)=es_Animate
	msg_Animate(5)=de_Animate
	msg_Animate(6)=nl_Animate
	msg_Animate(7)=pt_Animate
	msg_Animate(8)=xx_Animate
	a_Animate=0 ;** initialise access : normal
	msg_Image(1)=en_Image
	msg_Image(2)=fr_Image
	a_Image=0 ;** initialise access : normal
	msg_Copy(1)=en_Copy
	msg_Copy(2)=fr_Copy
	msg_Copy(3)=it_Copy
	msg_Copy(4)=es_Copy
	msg_Copy(5)=de_Copy
	msg_Copy(6)=nl_Copy
	msg_Copy(7)=pt_Copy
	msg_Copy(8)=xx_Copy
	a_Copy=0 ;** initialise access : normal
	msg_Paste(1)=en_Paste
	msg_Paste(2)=fr_Paste
	msg_Paste(3)=it_Paste
	msg_Paste(4)=es_Paste
	msg_Paste(5)=de_Paste
	msg_Paste(6)=nl_Paste
	msg_Paste(7)=pt_Paste
	msg_Paste(8)=xx_Paste
	a_Paste=0 ;** initialise access : normal
	msg_Cut(1)=en_Cut
	msg_Cut(2)=fr_Cut
	msg_Cut(3)=it_Cut
	msg_Cut(4)=es_Cut
	msg_Cut(5)=de_Cut
	msg_Cut(6)=nl_Cut
	msg_Cut(7)=pt_Cut
	msg_Cut(8)=xx_Cut
	a_Cut=0 ;** initialise access : normal
	msg_Rotate90(1)=en_Rotate90
	msg_Rotate90(2)=fr_Rotate90
	msg_Rotate90(3)=it_Rotate90
	msg_Rotate90(4)=es_Rotate90
	msg_Rotate90(5)=de_Rotate90
	msg_Rotate90(6)=nl_Rotate90
	msg_Rotate90(7)=pt_Rotate90
	msg_Rotate90(8)=xx_Rotate90
	a_Rotate90=0 ;** initialise access : normal
	msg_Rotate180(1)=en_Rotate180
	msg_Rotate180(2)=fr_Rotate180
	msg_Rotate180(3)=it_Rotate180
	msg_Rotate180(4)=es_Rotate180
	msg_Rotate180(5)=de_Rotate180
	msg_Rotate180(6)=nl_Rotate180
	msg_Rotate180(7)=pt_Rotate180
	msg_Rotate180(8)=xx_Rotate180
	a_Rotate180=0 ;** initialise access : normal
	msg_Rotate270(1)=en_Rotate270
	msg_Rotate270(2)=fr_Rotate270
	msg_Rotate270(3)=it_Rotate270
	msg_Rotate270(4)=es_Rotate270
	msg_Rotate270(5)=de_Rotate270
	msg_Rotate270(6)=nl_Rotate270
	msg_Rotate270(7)=pt_Rotate270
	msg_Rotate270(8)=xx_Rotate270
	a_Rotate270=0 ;** initialise access : normal
	msg_ChangeColour(1)=en_ChangeColour
	msg_ChangeColour(2)=fr_ChangeColour
	msg_ChangeColour(3)=it_ChangeColour
	msg_ChangeColour(4)=es_ChangeColour
	msg_ChangeColour(5)=de_ChangeColour
	msg_ChangeColour(6)=nl_ChangeColour
	msg_ChangeColour(7)=pt_ChangeColour
	msg_ChangeColour(8)=xx_ChangeColour
	a_ChangeColour=0 ;** initialise access : normal
	msg_GreyScale(1)=en_GreyScale
	msg_GreyScale(2)=fr_GreyScale
	msg_GreyScale(3)=it_GreyScale
	msg_GreyScale(4)=es_GreyScale
	msg_GreyScale(5)=de_GreyScale
	msg_GreyScale(6)=nl_GreyScale
	msg_GreyScale(7)=pt_GreyScale
	msg_GreyScale(8)=xx_GreyScale
	a_GreyScale=0 ;** initialise access : normal
	msg_VerticalMirror(1)=en_VerticalMirror
	msg_VerticalMirror(2)=fr_VerticalMirror
	msg_VerticalMirror(3)=it_VerticalMirror
	msg_VerticalMirror(4)=es_VerticalMirror
	msg_VerticalMirror(5)=de_VerticalMirror
	msg_VerticalMirror(6)=nl_VerticalMirror
	msg_VerticalMirror(7)=pt_VerticalMirror
	msg_VerticalMirror(8)=xx_VerticalMirror
	a_VerticalMirror=0 ;** initialise access : normal
	msg_HorizontalMirror(1)=en_HorizontalMirror
	msg_HorizontalMirror(2)=fr_HorizontalMirror
	msg_HorizontalMirror(3)=it_HorizontalMirror
	msg_HorizontalMirror(4)=es_HorizontalMirror
	msg_HorizontalMirror(5)=de_HorizontalMirror
	msg_HorizontalMirror(6)=nl_HorizontalMirror
	msg_HorizontalMirror(7)=pt_HorizontalMirror
	msg_HorizontalMirror(8)=xx_HorizontalMirror
	a_HorizontalMirror=0 ;** initialise access : normal
	msg_Dimensions(1)=en_Dimensions
	msg_Dimensions(2)=fr_Dimensions
	msg_Dimensions(3)=it_Dimensions
	msg_Dimensions(4)=es_Dimensions
	msg_Dimensions(5)=de_Dimensions
	msg_Dimensions(6)=nl_Dimensions
	msg_Dimensions(7)=pt_Dimensions
	msg_Dimensions(8)=xx_Dimensions
	a_Dimensions=0 ;** initialise access : normal
	msg_Executer(1)=en_Executer
	msg_Executer(2)=fr_Executer
	msg_Executer(3)=it_Executer
	msg_Executer(4)=es_Executer
	msg_Executer(5)=de_Executer
	msg_Executer(6)=nl_Executer
	msg_Executer(7)=pt_Executer
	msg_Executer(8)=xx_Executer
	msg_Editor(1)=en_Editor
	msg_Editor(2)=fr_Editor
	msg_Editor(3)=it_Editor
	msg_Editor(4)=es_Editor
	msg_Editor(5)=de_Editor
	msg_Editor(6)=nl_Editor
	msg_Editor(7)=pt_Editor
	msg_Editor(8)=xx_Editor
	msg_Traducteur(1)=en_Traducteur
	msg_Traducteur(2)=fr_Traducteur
	msg_Traducteur(3)=it_Traducteur
	msg_Traducteur(4)=es_Traducteur
	msg_Traducteur(5)=de_Traducteur
	msg_Traducteur(6)=nl_Traducteur
	msg_Traducteur(7)=pt_Traducteur
	msg_Traducteur(8)=xx_Traducteur
	msg_Linker(1)=en_Linker
	msg_Linker(2)=fr_Linker
	msg_Linker(3)=it_Linker
	msg_Linker(4)=es_Linker
	msg_Linker(5)=de_Linker
	msg_Linker(6)=nl_Linker
	msg_Linker(7)=pt_Linker
	msg_Linker(8)=xx_Linker
	msg_Executeur(1)=en_Executeur
	msg_Executeur(2)=fr_Executeur
	msg_Executeur(3)=it_Executeur
	msg_Executeur(4)=es_Executeur
	msg_Executeur(5)=de_Executeur
	msg_Executeur(6)=nl_Executeur
	msg_Executeur(7)=pt_Executeur
	msg_Executeur(8)=xx_Executeur
	msg_Editeur(1)=en_Editeur
	msg_Translate(1)=en_Translate
	msg_Linkeur(1)=en_Linkeur
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
Proc StatusMessage1Onshow()
	On Local Error Goto &elabel1,Status
	Status=VisualZone(70,600,248+2,16+2,5 + (a_StatusMessage1 * 128))	; si access vaut 2 alors gris
	Status=VisualText(70+1,600+1,248,16,FontHandle(1),27,0,b_StatusMessage1,31,0)
	Exit
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc StatusMessage2Onshow()
	On Local Error Goto &elabel1,Status
	Status=VisualZone(330,600,232+2,16+2,5 + (a_StatusMessage2 * 128))	; si access vaut 2 alors gris
	Status=VisualText(330+1,600+1,232,16,FontHandle(1),27,0,b_StatusMessage2,29,0)
	Exit
&elabel1
	On Local Error Abort
	Error Status
EndProc
Proc StatusMessage3Onshow()
	On Local Error Goto &elabel1,Status
	Status=VisualZone(570,600,240+2,16+2,5 + (a_StatusMessage3 * 128))	; si access vaut 2 alors gris
	Status=VisualText(570+1,600+1,240,16,FontHandle(1),27,0,b_StatusMessage3,30,0)
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
	Status=VisualFill(1,1,880,30,27,10)
	Status=VisualImage(62,31,759,559,"/home/Dev/abal32/sing/zoomer.gif",32,2)
	Status=VisualFill(820,30,60,600,27,11)
	if ( VisualStyle(22,5,19,19,"insetframe",10," ",0) <> 0)
		Status=VisualZone(22,5,19,19,2)
	Endif
	if (a_ToolBarControl = 2)	;** affichage gris‚ si 2
		Status=VisualButton(19,2,25,25,FontHandle(1),18,0,msg_ToolBarControl(NationalLanguage),Len(msg_ToolBarControl(NationalLanguage)),/0430)
	endif
	if (a_ToolBarControl = 0)	;** affichage normal si 0
		Status=VisualButton(19,2,25,25,FontHandle(1),27,0,msg_ToolBarControl(NationalLanguage),Len(msg_ToolBarControl(NationalLanguage)),/0030)
	endif
	Status=VisualFill(0,30,60,600,27,11)
	Status=VisualImage(4,40,55,285,"/home/Dev/abal32/sing/itoolbar.gif",34,2)
	if ( VisualStyle(843,7,18,17,"insetframe",10," ",0) <> 0)
		Status=VisualZone(843,7,18,17,2)
	Endif
	if (a_PaletteControl = 2)	;** affichage gris‚ si 2
		Status=VisualButton(840,4,24,25,FontHandle(2),18,0,msg_PaletteControl(NationalLanguage),Len(msg_PaletteControl(NationalLanguage)),/0430)
	endif
	if (a_PaletteControl = 0)	;** affichage normal si 0
		Status=VisualButton(840,4,24,25,FontHandle(2),16,0,msg_PaletteControl(NationalLanguage),Len(msg_PaletteControl(NationalLanguage)),/0030)
	endif
	Status=VisualImage(827,38,46,582,"/home/Dev/abal32/sing/palette.gif",33,2)
	t_File=VisualControl(_VISUAL_TRIGGER,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)))
	if (a_File = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,5,80,20,FontHandle(2),18,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0420)
	endif
	if (a_File = 0)	;** affichage normal si 0
		Status=VisualButton(70,5,80,20,FontHandle(2),16,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0020)
	endif
	Status=VisualFill(61,30,100,160,16,11)
	t_New=VisualControl(_VISUAL_TRIGGER,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)))
	if (a_New = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,40,80,20,FontHandle(2),18,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0420)
	endif
	if (a_New = 0)	;** affichage normal si 0
		Status=VisualButton(70,40,80,20,FontHandle(2),16,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0020)
	endif
	t_Save=VisualControl(_VISUAL_TRIGGER,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)))
	if (a_Save = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,60,80,20,FontHandle(2),18,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0420)
	endif
	if (a_Save = 0)	;** affichage normal si 0
		Status=VisualButton(70,60,80,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0020)
	endif
	t_SaveAs=VisualControl(_VISUAL_TRIGGER,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)))
	if (a_SaveAs = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,80,80,20,FontHandle(2),18,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0420)
	endif
	if (a_SaveAs = 0)	;** affichage normal si 0
		Status=VisualButton(70,80,80,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0020)
	endif
	t_Open=VisualControl(_VISUAL_TRIGGER,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)))
	if (a_Open = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,100,80,20,FontHandle(2),18,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0420)
	endif
	if (a_Open = 0)	;** affichage normal si 0
		Status=VisualButton(70,100,80,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0020)
	endif
	t_Production=VisualControl(_VISUAL_TRIGGER,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)))
	if (a_Production = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,120,80,20,FontHandle(2),18,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0420)
	endif
	if (a_Production = 0)	;** affichage normal si 0
		Status=VisualButton(70,120,80,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0020)
	endif
	t_Drop=VisualControl(_VISUAL_TRIGGER,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)))
	if (a_Drop = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,140,80,20,FontHandle(2),18,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0420)
	endif
	if (a_Drop = 0)	;** affichage normal si 0
		Status=VisualButton(70,140,80,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0020)
	endif
	t_Quit=VisualControl(_VISUAL_TRIGGER,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)))
	if (a_Quit = 2)	;** affichage gris‚ si 2
		Status=VisualButton(70,160,80,20,FontHandle(2),18,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0420)
	endif
	if (a_Quit = 0)	;** affichage normal si 0
		Status=VisualButton(70,160,80,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0020)
	endif
	t_View=VisualControl(_VISUAL_TRIGGER,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)))
	if (a_View = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,5,80,20,FontHandle(2),18,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0420)
	endif
	if (a_View = 0)	;** affichage normal si 0
		Status=VisualButton(170,5,80,20,FontHandle(2),16,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0020)
	endif
	Status=VisualFill(160,30,100,180,16,11)
	t_Run=VisualControl(_VISUAL_TRIGGER,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)))
	if (a_Run = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,40,80,20,FontHandle(2),18,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0420)
	endif
	if (a_Run = 0)	;** affichage normal si 0
		Status=VisualButton(170,40,80,20,FontHandle(2),16,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0020)
	endif
	t_Text=VisualControl(_VISUAL_TRIGGER,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)))
	if (a_Text = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,60,80,20,FontHandle(2),18,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0420)
	endif
	if (a_Text = 0)	;** affichage normal si 0
		Status=VisualButton(170,60,80,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0020)
	endif
	t_Images=VisualControl(_VISUAL_TRIGGER,msg_Images(NationalLanguage),Len(msg_Images(NationalLanguage)))
	if (a_Images = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,80,80,20,FontHandle(2),18,0,msg_Images(NationalLanguage),Len(msg_Images(NationalLanguage)),/0420)
	endif
	if (a_Images = 0)	;** affichage normal si 0
		Status=VisualButton(170,80,80,20,FontHandle(2),16,0,msg_Images(NationalLanguage),Len(msg_Images(NationalLanguage)),/0020)
	endif
	t_Font=VisualControl(_VISUAL_TRIGGER,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)))
	if (a_Font = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,100,80,20,FontHandle(2),18,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0420)
	endif
	if (a_Font = 0)	;** affichage normal si 0
		Status=VisualButton(170,100,80,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0020)
	endif
	t_Properties=VisualControl(_VISUAL_TRIGGER,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)))
	if (a_Properties = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,120,80,20,FontHandle(2),18,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0420)
	endif
	if (a_Properties = 0)	;** affichage normal si 0
		Status=VisualButton(170,120,80,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0020)
	endif
	t_Visual=VisualControl(_VISUAL_TRIGGER,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)))
	if (a_Visual = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,140,80,20,FontHandle(2),18,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0420)
	endif
	if (a_Visual = 0)	;** affichage normal si 0
		Status=VisualButton(170,140,80,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0020)
	endif
	t_TreeView=VisualControl(_VISUAL_TRIGGER,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)))
	if (a_TreeView = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,160,80,20,FontHandle(2),18,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0420)
	endif
	if (a_TreeView = 0)	;** affichage normal si 0
		Status=VisualButton(170,160,80,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0020)
	endif
	t_Application=VisualControl(_VISUAL_TRIGGER,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)))
	if (a_Application = 2)	;** affichage gris‚ si 2
		Status=VisualButton(170,180,80,20,FontHandle(2),18,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0420)
	endif
	if (a_Application = 0)	;** affichage normal si 0
		Status=VisualButton(170,180,80,20,FontHandle(2),16,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0020)
	endif
	t_Event=VisualControl(_VISUAL_TRIGGER,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)))
	if (a_Event = 2)	;** affichage gris‚ si 2
		Status=VisualButton(280,5,80,20,FontHandle(2),18,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0420)
	endif
	if (a_Event = 0)	;** affichage normal si 0
		Status=VisualButton(280,5,80,20,FontHandle(2),16,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0020)
	endif
	t_Options=VisualControl(_VISUAL_TRIGGER,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)))
	if (a_Options = 2)	;** affichage gris‚ si 2
		Status=VisualButton(390,5,80,20,FontHandle(2),18,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0420)
	endif
	if (a_Options = 0)	;** affichage normal si 0
		Status=VisualButton(390,5,80,20,FontHandle(2),16,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0020)
	endif
	Status=VisualFill(370,30,120,120,16,11)
	t_Parameters=VisualControl(_VISUAL_TRIGGER,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)))
	if (a_Parameters = 2)	;** affichage gris‚ si 2
		Status=VisualButton(380,40,100,20,FontHandle(2),18,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0420)
	endif
	if (a_Parameters = 0)	;** affichage normal si 0
		Status=VisualButton(380,40,100,20,FontHandle(2),16,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0020)
	endif
	t_Refresh=VisualControl(_VISUAL_TRIGGER,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)))
	if (a_Refresh = 2)	;** affichage gris‚ si 2
		Status=VisualButton(380,60,100,20,FontHandle(2),18,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0420)
	endif
	if (a_Refresh = 0)	;** affichage normal si 0
		Status=VisualButton(380,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0020)
	endif
	t_Configure=VisualControl(_VISUAL_TRIGGER,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)))
	if (a_Configure = 2)	;** affichage gris‚ si 2
		Status=VisualButton(380,80,100,20,FontHandle(2),18,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0420)
	endif
	if (a_Configure = 0)	;** affichage normal si 0
		Status=VisualButton(380,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0020)
	endif
	t_ScreenCapture=VisualControl(_VISUAL_TRIGGER,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)))
	if (a_ScreenCapture = 2)	;** affichage gris‚ si 2
		Status=VisualButton(380,100,102,19,FontHandle(2),18,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0420)
	endif
	if (a_ScreenCapture = 0)	;** affichage normal si 0
		Status=VisualButton(380,100,102,19,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0020)
	endif
	t_Animate=VisualControl(_VISUAL_TRIGGER,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)))
	if (a_Animate = 2)	;** affichage gris‚ si 2
		Status=VisualButton(380,120,100,20,FontHandle(2),18,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0420)
	endif
	if (a_Animate = 0)	;** affichage normal si 0
		Status=VisualButton(380,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0020)
	endif
	t_Image=VisualControl(_VISUAL_TRIGGER,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)))
	if (a_Image = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,5,70,20,FontHandle(2),18,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0420)
	endif
	if (a_Image = 0)	;** affichage normal si 0
		Status=VisualButton(500,5,70,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0020)
	endif
	Status=VisualFill(490,30,150,240,16,11)
	t_Copy=VisualControl(_VISUAL_TRIGGER,msg_Copy(NationalLanguage),Len(msg_Copy(NationalLanguage)))
	if (a_Copy = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,40,130,20,FontHandle(2),18,0,msg_Copy(NationalLanguage),Len(msg_Copy(NationalLanguage)),/0420)
	endif
	if (a_Copy = 0)	;** affichage normal si 0
		Status=VisualButton(500,40,130,20,FontHandle(2),16,0,msg_Copy(NationalLanguage),Len(msg_Copy(NationalLanguage)),/0020)
	endif
	t_Paste=VisualControl(_VISUAL_TRIGGER,msg_Paste(NationalLanguage),Len(msg_Paste(NationalLanguage)))
	if (a_Paste = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,60,130,20,FontHandle(2),18,0,msg_Paste(NationalLanguage),Len(msg_Paste(NationalLanguage)),/0420)
	endif
	if (a_Paste = 0)	;** affichage normal si 0
		Status=VisualButton(500,60,130,20,FontHandle(2),16,0,msg_Paste(NationalLanguage),Len(msg_Paste(NationalLanguage)),/0020)
	endif
	t_Cut=VisualControl(_VISUAL_TRIGGER,msg_Cut(NationalLanguage),Len(msg_Cut(NationalLanguage)))
	if (a_Cut = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,80,130,20,FontHandle(2),18,0,msg_Cut(NationalLanguage),Len(msg_Cut(NationalLanguage)),/0420)
	endif
	if (a_Cut = 0)	;** affichage normal si 0
		Status=VisualButton(500,80,130,20,FontHandle(2),16,0,msg_Cut(NationalLanguage),Len(msg_Cut(NationalLanguage)),/0020)
	endif
	t_Rotate90=VisualControl(_VISUAL_TRIGGER,msg_Rotate90(NationalLanguage),Len(msg_Rotate90(NationalLanguage)))
	if (a_Rotate90 = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,100,130,20,FontHandle(2),18,0,msg_Rotate90(NationalLanguage),Len(msg_Rotate90(NationalLanguage)),/0420)
	endif
	if (a_Rotate90 = 0)	;** affichage normal si 0
		Status=VisualButton(500,100,130,20,FontHandle(2),16,0,msg_Rotate90(NationalLanguage),Len(msg_Rotate90(NationalLanguage)),/0020)
	endif
	t_Rotate180=VisualControl(_VISUAL_TRIGGER,msg_Rotate180(NationalLanguage),Len(msg_Rotate180(NationalLanguage)))
	if (a_Rotate180 = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,120,130,20,FontHandle(2),18,0,msg_Rotate180(NationalLanguage),Len(msg_Rotate180(NationalLanguage)),/0420)
	endif
	if (a_Rotate180 = 0)	;** affichage normal si 0
		Status=VisualButton(500,120,130,20,FontHandle(2),16,0,msg_Rotate180(NationalLanguage),Len(msg_Rotate180(NationalLanguage)),/0020)
	endif
	t_Rotate270=VisualControl(_VISUAL_TRIGGER,msg_Rotate270(NationalLanguage),Len(msg_Rotate270(NationalLanguage)))
	if (a_Rotate270 = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,140,130,20,FontHandle(2),18,0,msg_Rotate270(NationalLanguage),Len(msg_Rotate270(NationalLanguage)),/0420)
	endif
	if (a_Rotate270 = 0)	;** affichage normal si 0
		Status=VisualButton(500,140,130,20,FontHandle(2),16,0,msg_Rotate270(NationalLanguage),Len(msg_Rotate270(NationalLanguage)),/0020)
	endif
	t_ChangeColour=VisualControl(_VISUAL_TRIGGER,msg_ChangeColour(NationalLanguage),Len(msg_ChangeColour(NationalLanguage)))
	if (a_ChangeColour = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,160,130,20,FontHandle(2),18,0,msg_ChangeColour(NationalLanguage),Len(msg_ChangeColour(NationalLanguage)),/0420)
	endif
	if (a_ChangeColour = 0)	;** affichage normal si 0
		Status=VisualButton(500,160,130,20,FontHandle(2),16,0,msg_ChangeColour(NationalLanguage),Len(msg_ChangeColour(NationalLanguage)),/0020)
	endif
	t_GreyScale=VisualControl(_VISUAL_TRIGGER,msg_GreyScale(NationalLanguage),Len(msg_GreyScale(NationalLanguage)))
	if (a_GreyScale = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,180,130,20,FontHandle(2),18,0,msg_GreyScale(NationalLanguage),Len(msg_GreyScale(NationalLanguage)),/0420)
	endif
	if (a_GreyScale = 0)	;** affichage normal si 0
		Status=VisualButton(500,180,130,20,FontHandle(2),16,0,msg_GreyScale(NationalLanguage),Len(msg_GreyScale(NationalLanguage)),/0020)
	endif
	t_VerticalMirror=VisualControl(_VISUAL_TRIGGER,msg_VerticalMirror(NationalLanguage),Len(msg_VerticalMirror(NationalLanguage)))
	if (a_VerticalMirror = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,200,130,20,FontHandle(2),18,0,msg_VerticalMirror(NationalLanguage),Len(msg_VerticalMirror(NationalLanguage)),/0420)
	endif
	if (a_VerticalMirror = 0)	;** affichage normal si 0
		Status=VisualButton(500,200,130,20,FontHandle(2),16,0,msg_VerticalMirror(NationalLanguage),Len(msg_VerticalMirror(NationalLanguage)),/0020)
	endif
	t_HorizontalMirror=VisualControl(_VISUAL_TRIGGER,msg_HorizontalMirror(NationalLanguage),Len(msg_HorizontalMirror(NationalLanguage)))
	if (a_HorizontalMirror = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,220,130,20,FontHandle(2),18,0,msg_HorizontalMirror(NationalLanguage),Len(msg_HorizontalMirror(NationalLanguage)),/0420)
	endif
	if (a_HorizontalMirror = 0)	;** affichage normal si 0
		Status=VisualButton(500,220,130,20,FontHandle(2),16,0,msg_HorizontalMirror(NationalLanguage),Len(msg_HorizontalMirror(NationalLanguage)),/0020)
	endif
	t_Dimensions=VisualControl(_VISUAL_TRIGGER,msg_Dimensions(NationalLanguage),Len(msg_Dimensions(NationalLanguage)))
	if (a_Dimensions = 2)	;** affichage gris‚ si 2
		Status=VisualButton(500,240,130,20,FontHandle(2),18,0,msg_Dimensions(NationalLanguage),Len(msg_Dimensions(NationalLanguage)),/0420)
	endif
	if (a_Dimensions = 0)	;** affichage normal si 0
		Status=VisualButton(500,240,130,20,FontHandle(2),16,0,msg_Dimensions(NationalLanguage),Len(msg_Dimensions(NationalLanguage)),/0020)
	endif
	Status=VisualImage(695,7,18,15,"plusicon.gif",12,2)
	Status=VisualImage(713,7,18,15,"aedicon.gif",11,2)
	Status=VisualImage(732,7,18,15,"otricon.gif",11,2)
	Status=VisualImage(751,7,18,15,"oldicon.gif",11,2)
	Status=VisualImage(677,7,18,15,"vdbicon.gif",11,2)
	Status=VisualImage(713,7,18,15,"aedicon.gif",11,2)
	Status=VisualImage(732,7,18,15,"otricon.gif",11,2)
	Status=VisualImage(751,7,18,15,"oldicon.gif",11,2)
	if ( VisualStyle(60,590,760,40,"outsetframe",11," ",0) <> 0)
		Status=VisualZone(60,590,760,40,1)
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
Proc OnEvent() : % 
	On Local Error Goto &elabel1,Status
	if ((MouseType and _MIMO_ALT) <> 0)
		MouseButton = (MouseButton and /00FF)
		if (( MouseButton >= /0061) and (MouseButton <= /007A))
			MouseButton -= /0020
		endif
		if (t_ToolBarControl = MouseButton ) :: Exit(1) 
		Endif
		if (t_PaletteControl = MouseButton ) :: Exit(2) 
		Endif
		if (t_File = MouseButton ) :: Exit(3) 
		Endif
		if (t_New = MouseButton ) :: Exit(4) 
		Endif
		if (t_Save = MouseButton ) :: Exit(5) 
		Endif
		if (t_SaveAs = MouseButton ) :: Exit(6) 
		Endif
		if (t_Open = MouseButton ) :: Exit(7) 
		Endif
		if (t_Production = MouseButton ) :: Exit(8) 
		Endif
		if (t_Drop = MouseButton ) :: Exit(9) 
		Endif
		if (t_Quit = MouseButton ) :: Exit(10) 
		Endif
		if (t_View = MouseButton ) :: Exit(11) 
		Endif
		if (t_Run = MouseButton ) :: Exit(12) 
		Endif
		if (t_Text = MouseButton ) :: Exit(13) 
		Endif
		if (t_Images = MouseButton ) :: Exit(14) 
		Endif
		if (t_Font = MouseButton ) :: Exit(15) 
		Endif
		if (t_Properties = MouseButton ) :: Exit(16) 
		Endif
		if (t_Visual = MouseButton ) :: Exit(17) 
		Endif
		if (t_TreeView = MouseButton ) :: Exit(18) 
		Endif
		if (t_Application = MouseButton ) :: Exit(19) 
		Endif
		if (t_Event = MouseButton ) :: Exit(20) 
		Endif
		if (t_Options = MouseButton ) :: Exit(21) 
		Endif
		if (t_Parameters = MouseButton ) :: Exit(22) 
		Endif
		if (t_Refresh = MouseButton ) :: Exit(23) 
		Endif
		if (t_Configure = MouseButton ) :: Exit(24) 
		Endif
		if (t_ScreenCapture = MouseButton ) :: Exit(25) 
		Endif
		if (t_Animate = MouseButton ) :: Exit(26) 
		Endif
		if (t_Image = MouseButton ) :: Exit(27) 
		Endif
		if (t_Copy = MouseButton ) :: Exit(28) 
		Endif
		if (t_Paste = MouseButton ) :: Exit(29) 
		Endif
		if (t_Cut = MouseButton ) :: Exit(30) 
		Endif
		if (t_Rotate90 = MouseButton ) :: Exit(31) 
		Endif
		if (t_Rotate180 = MouseButton ) :: Exit(32) 
		Endif
		if (t_Rotate270 = MouseButton ) :: Exit(33) 
		Endif
		if (t_ChangeColour = MouseButton ) :: Exit(34) 
		Endif
		if (t_GreyScale = MouseButton ) :: Exit(35) 
		Endif
		if (t_VerticalMirror = MouseButton ) :: Exit(36) 
		Endif
		if (t_HorizontalMirror = MouseButton ) :: Exit(37) 
		Endif
		if (t_Dimensions = MouseButton ) :: Exit(38) 
		Endif
		Exit(-1)
	endif
	if ((MouseType and /031) = 0)
		Exit(0)
	Endif
	if ((MouseColumn >= 570 ) 		and (MouseRow >= 600 ) 		and (MouseColumn <= 810 ) 		and (MouseRow <= 616 ))
		;** StatusMessage3 
		if (a_StatusMessage3=0)
			Exit(__StatusMessage3)
		Endif
	Endif
	if ((MouseColumn >= 330 ) 		and (MouseRow >= 600 ) 		and (MouseColumn <= 562 ) 		and (MouseRow <= 616 ))
		;** StatusMessage2 
		if (a_StatusMessage2=0)
			Exit(__StatusMessage2)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 600 ) 		and (MouseColumn <= 318 ) 		and (MouseRow <= 616 ))
		;** StatusMessage1 
		if (a_StatusMessage1=0)
			Exit(__StatusMessage1)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 240 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 260 ))
		;** Dimensions 
		if (a_Dimensions=0)
			Exit(__Dimensions)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 220 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 240 ))
		;** HorizontalMirror 
		if (a_HorizontalMirror=0)
			Exit(__HorizontalMirror)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 200 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 220 ))
		;** VerticalMirror 
		if (a_VerticalMirror=0)
			Exit(__VerticalMirror)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 180 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 200 ))
		;** GreyScale 
		if (a_GreyScale=0)
			Exit(__GreyScale)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 160 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 180 ))
		;** ChangeColour 
		if (a_ChangeColour=0)
			Exit(__ChangeColour)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 140 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 160 ))
		;** Rotate270 
		if (a_Rotate270=0)
			Exit(__Rotate270)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 140 ))
		;** Rotate180 
		if (a_Rotate180=0)
			Exit(__Rotate180)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 120 ))
		;** Rotate90 
		if (a_Rotate90=0)
			Exit(__Rotate90)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 100 ))
		;** Cut 
		if (a_Cut=0)
			Exit(__Cut)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 80 ))
		;** Paste 
		if (a_Paste=0)
			Exit(__Paste)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 630 ) 		and (MouseRow <= 60 ))
		;** Copy 
		if (a_Copy=0)
			Exit(__Copy)
		Endif
	Endif
	if ((MouseColumn >= 500 ) 		and (MouseRow >= 5 ) 		and (MouseColumn <= 570 ) 		and (MouseRow <= 25 ))
		;** Image 
		if (a_Image=0)
			Exit(__Image)
		Endif
	Endif
	if ((MouseColumn >= 380 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 480 ) 		and (MouseRow <= 140 ))
		;** Animate 
		if (a_Animate=0)
			Exit(__Animate)
		Endif
	Endif
	if ((MouseColumn >= 380 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 482 ) 		and (MouseRow <= 119 ))
		;** ScreenCapture 
		if (a_ScreenCapture=0)
			Exit(__ScreenCapture)
		Endif
	Endif
	if ((MouseColumn >= 380 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 480 ) 		and (MouseRow <= 100 ))
		;** Configure 
		if (a_Configure=0)
			Exit(__Configure)
		Endif
	Endif
	if ((MouseColumn >= 380 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 480 ) 		and (MouseRow <= 80 ))
		;** Refresh 
		if (a_Refresh=0)
			Exit(__Refresh)
		Endif
	Endif
	if ((MouseColumn >= 380 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 480 ) 		and (MouseRow <= 60 ))
		;** Parameters 
		if (a_Parameters=0)
			Exit(__Parameters)
		Endif
	Endif
	if ((MouseColumn >= 390 ) 		and (MouseRow >= 5 ) 		and (MouseColumn <= 470 ) 		and (MouseRow <= 25 ))
		;** Options 
		if (a_Options=0)
			Exit(__Options)
		Endif
	Endif
	if ((MouseColumn >= 280 ) 		and (MouseRow >= 5 ) 		and (MouseColumn <= 360 ) 		and (MouseRow <= 25 ))
		;** Event 
		if (a_Event=0)
			Exit(__Event)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 180 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 200 ))
		;** Application 
		if (a_Application=0)
			Exit(__Application)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 160 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 180 ))
		;** TreeView 
		if (a_TreeView=0)
			Exit(__TreeView)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 140 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 160 ))
		;** Visual 
		if (a_Visual=0)
			Exit(__Visual)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 140 ))
		;** Properties 
		if (a_Properties=0)
			Exit(__Properties)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 120 ))
		;** Font 
		if (a_Font=0)
			Exit(__Font)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 100 ))
		;** Images 
		if (a_Images=0)
			Exit(__Images)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 80 ))
		;** Text 
		if (a_Text=0)
			Exit(__Text)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 60 ))
		;** Run 
		if (a_Run=0)
			Exit(__Run)
		Endif
	Endif
	if ((MouseColumn >= 170 ) 		and (MouseRow >= 5 ) 		and (MouseColumn <= 250 ) 		and (MouseRow <= 25 ))
		;** View 
		if (a_View=0)
			Exit(__View)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 160 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 180 ))
		;** Quit 
		if (a_Quit=0)
			Exit(__Quit)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 140 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 160 ))
		;** Drop 
		if (a_Drop=0)
			Exit(__Drop)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 120 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 140 ))
		;** Production 
		if (a_Production=0)
			Exit(__Production)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 100 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 120 ))
		;** Open 
		if (a_Open=0)
			Exit(__Open)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 80 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 100 ))
		;** SaveAs 
		if (a_SaveAs=0)
			Exit(__SaveAs)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 60 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 80 ))
		;** Save 
		if (a_Save=0)
			Exit(__Save)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 40 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 60 ))
		;** New 
		if (a_New=0)
			Exit(__New)
		Endif
	Endif
	if ((MouseColumn >= 70 ) 		and (MouseRow >= 5 ) 		and (MouseColumn <= 150 ) 		and (MouseRow <= 25 ))
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
	FocusItems=41
	While (VisualKey(0) <> 0) 
		KeyCode=VisualKey(1) 
	Wend
	Do
&Continue
		Event(0)=(Event(5) and /FEFF)
		LastFocus=FocusItem
		Select(FocusItem)
		Case __Save
			;** Save 
			Status=VisualButton(70,60,80,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(70,60,80,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0020)
		Case __SaveAs
			;** SaveAs 
			Status=VisualButton(70,80,80,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(70,80,80,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0020)
		Case __Open
			;** Open 
			Status=VisualButton(70,100,80,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(70,100,80,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0020)
		Case __Production
			;** Production 
			Status=VisualButton(70,120,80,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(70,120,80,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0020)
		Case __Drop
			;** Drop 
			Status=VisualButton(70,140,80,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(70,140,80,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0020)
		Case __Quit
			;** Quit 
			Status=VisualButton(70,160,80,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(70,160,80,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0020)
		Case __Text
			;** Text 
			Status=VisualButton(170,60,80,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(170,60,80,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0020)
		Case __Images
			;** Images 
			Status=VisualButton(170,80,80,20,FontHandle(2),16,0,msg_Images(NationalLanguage),Len(msg_Images(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(170,80,80,20,FontHandle(2),16,0,msg_Images(NationalLanguage),Len(msg_Images(NationalLanguage)),/0020)
		Case __Font
			;** Font 
			Status=VisualButton(170,100,80,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(170,100,80,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0020)
		Case __Properties
			;** Properties 
			Status=VisualButton(170,120,80,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(170,120,80,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0020)
		Case __Visual
			;** Visual 
			Status=VisualButton(170,140,80,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(170,140,80,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0020)
		Case __TreeView
			;** TreeView 
			Status=VisualButton(170,160,80,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(170,160,80,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0020)
		Case __Refresh
			;** Refresh 
			Status=VisualButton(380,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(380,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0020)
		Case __Configure
			;** Configure 
			Status=VisualButton(380,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(380,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0020)
		Case __ScreenCapture
			;** ScreenCapture 
			Status=VisualButton(380,100,102,19,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(380,100,102,19,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0020)
		Case __Animate
			;** Animate 
			Status=VisualButton(380,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(380,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0020)
		Case __Image
			;** Image 
			Status=VisualButton(500,5,70,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,5,70,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0020)
		Case __Paste
			;** Paste 
			Status=VisualButton(500,60,130,20,FontHandle(2),16,0,msg_Paste(NationalLanguage),Len(msg_Paste(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,60,130,20,FontHandle(2),16,0,msg_Paste(NationalLanguage),Len(msg_Paste(NationalLanguage)),/0020)
		Case __Cut
			;** Cut 
			Status=VisualButton(500,80,130,20,FontHandle(2),16,0,msg_Cut(NationalLanguage),Len(msg_Cut(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,80,130,20,FontHandle(2),16,0,msg_Cut(NationalLanguage),Len(msg_Cut(NationalLanguage)),/0020)
		Case __Rotate90
			;** Rotate90 
			Status=VisualButton(500,100,130,20,FontHandle(2),16,0,msg_Rotate90(NationalLanguage),Len(msg_Rotate90(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,100,130,20,FontHandle(2),16,0,msg_Rotate90(NationalLanguage),Len(msg_Rotate90(NationalLanguage)),/0020)
		Case __Rotate180
			;** Rotate180 
			Status=VisualButton(500,120,130,20,FontHandle(2),16,0,msg_Rotate180(NationalLanguage),Len(msg_Rotate180(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,120,130,20,FontHandle(2),16,0,msg_Rotate180(NationalLanguage),Len(msg_Rotate180(NationalLanguage)),/0020)
		Case __Rotate270
			;** Rotate270 
			Status=VisualButton(500,140,130,20,FontHandle(2),16,0,msg_Rotate270(NationalLanguage),Len(msg_Rotate270(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,140,130,20,FontHandle(2),16,0,msg_Rotate270(NationalLanguage),Len(msg_Rotate270(NationalLanguage)),/0020)
		Case __ChangeColour
			;** ChangeColour 
			Status=VisualButton(500,160,130,20,FontHandle(2),16,0,msg_ChangeColour(NationalLanguage),Len(msg_ChangeColour(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,160,130,20,FontHandle(2),16,0,msg_ChangeColour(NationalLanguage),Len(msg_ChangeColour(NationalLanguage)),/0020)
		Case __GreyScale
			;** GreyScale 
			Status=VisualButton(500,180,130,20,FontHandle(2),16,0,msg_GreyScale(NationalLanguage),Len(msg_GreyScale(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,180,130,20,FontHandle(2),16,0,msg_GreyScale(NationalLanguage),Len(msg_GreyScale(NationalLanguage)),/0020)
		Case __VerticalMirror
			;** VerticalMirror 
			Status=VisualButton(500,200,130,20,FontHandle(2),16,0,msg_VerticalMirror(NationalLanguage),Len(msg_VerticalMirror(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,200,130,20,FontHandle(2),16,0,msg_VerticalMirror(NationalLanguage),Len(msg_VerticalMirror(NationalLanguage)),/0020)
		Case __HorizontalMirror
			;** HorizontalMirror 
			Status=VisualButton(500,220,130,20,FontHandle(2),16,0,msg_HorizontalMirror(NationalLanguage),Len(msg_HorizontalMirror(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,220,130,20,FontHandle(2),16,0,msg_HorizontalMirror(NationalLanguage),Len(msg_HorizontalMirror(NationalLanguage)),/0020)
		Case __Dimensions
			;** Dimensions 
			Status=VisualButton(500,240,130,20,FontHandle(2),16,0,msg_Dimensions(NationalLanguage),Len(msg_Dimensions(NationalLanguage)),/0022)
			KeyCode=VisualKey(1)
			Status=VisualButton(500,240,130,20,FontHandle(2),16,0,msg_Dimensions(NationalLanguage),Len(msg_Dimensions(NationalLanguage)),/0020)
		Case __StatusMessage1
			;** StatusMessage1 
			KeyCode=VisualEdit(70+1,600+1,248,16,FontHandle(1),b_StatusMessage1,31,3)
			if (a_StatusMessage1 <> 1)	;** affichage si diff‚rent de 1
				StatusMessage1Onshow()
			endif
		Case __StatusMessage2
			;** StatusMessage2 
			KeyCode=VisualEdit(330+1,600+1,232,16,FontHandle(1),b_StatusMessage2,29,3)
			if (a_StatusMessage2 <> 1)	;** affichage si diff‚rent de 1
				StatusMessage2Onshow()
			endif
		Case __StatusMessage3
			;** StatusMessage3 
			KeyCode=VisualEdit(570+1,600+1,240,16,FontHandle(1),b_StatusMessage3,30,3)
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
			FocusItem=41
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
					Status=VisualButton(70,5,80,20,FontHandle(2),16,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,5,80,20,FontHandle(2),16,0,msg_File(NationalLanguage),Len(msg_File(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __New
				;** New 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(70,40,80,20,FontHandle(2),16,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,40,80,20,FontHandle(2),16,0,msg_New(NationalLanguage),Len(msg_New(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Save
				;** Save 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(70,60,80,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,60,80,20,FontHandle(2),16,0,msg_Save(NationalLanguage),Len(msg_Save(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __SaveAs
				;** SaveAs 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(70,80,80,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,80,80,20,FontHandle(2),16,0,msg_SaveAs(NationalLanguage),Len(msg_SaveAs(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Open
				;** Open 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(70,100,80,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,100,80,20,FontHandle(2),16,0,msg_Open(NationalLanguage),Len(msg_Open(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Production
				;** Production 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(70,120,80,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,120,80,20,FontHandle(2),16,0,msg_Production(NationalLanguage),Len(msg_Production(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Drop
				;** Drop 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(70,140,80,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,140,80,20,FontHandle(2),16,0,msg_Drop(NationalLanguage),Len(msg_Drop(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Quit
				;** Quit 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(70,160,80,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(70,160,80,20,FontHandle(2),16,0,msg_Quit(NationalLanguage),Len(msg_Quit(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __View
				;** View 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,5,80,20,FontHandle(2),16,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,5,80,20,FontHandle(2),16,0,msg_View(NationalLanguage),Len(msg_View(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Run
				;** Run 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,40,80,20,FontHandle(2),16,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,40,80,20,FontHandle(2),16,0,msg_Run(NationalLanguage),Len(msg_Run(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Text
				;** Text 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,60,80,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,60,80,20,FontHandle(2),16,0,msg_Text(NationalLanguage),Len(msg_Text(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Images
				;** Images 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,80,80,20,FontHandle(2),16,0,msg_Images(NationalLanguage),Len(msg_Images(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,80,80,20,FontHandle(2),16,0,msg_Images(NationalLanguage),Len(msg_Images(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Font
				;** Font 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,100,80,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,100,80,20,FontHandle(2),16,0,msg_Font(NationalLanguage),Len(msg_Font(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Properties
				;** Properties 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,120,80,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,120,80,20,FontHandle(2),16,0,msg_Properties(NationalLanguage),Len(msg_Properties(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Visual
				;** Visual 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,140,80,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,140,80,20,FontHandle(2),16,0,msg_Visual(NationalLanguage),Len(msg_Visual(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __TreeView
				;** TreeView 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,160,80,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,160,80,20,FontHandle(2),16,0,msg_TreeView(NationalLanguage),Len(msg_TreeView(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Application
				;** Application 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(170,180,80,20,FontHandle(2),16,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(170,180,80,20,FontHandle(2),16,0,msg_Application(NationalLanguage),Len(msg_Application(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Event
				;** Event 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(280,5,80,20,FontHandle(2),16,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(280,5,80,20,FontHandle(2),16,0,msg_Event(NationalLanguage),Len(msg_Event(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Options
				;** Options 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(390,5,80,20,FontHandle(2),16,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(390,5,80,20,FontHandle(2),16,0,msg_Options(NationalLanguage),Len(msg_Options(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Parameters
				;** Parameters 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(380,40,100,20,FontHandle(2),16,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(380,40,100,20,FontHandle(2),16,0,msg_Parameters(NationalLanguage),Len(msg_Parameters(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Refresh
				;** Refresh 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(380,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(380,60,100,20,FontHandle(2),16,0,msg_Refresh(NationalLanguage),Len(msg_Refresh(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Configure
				;** Configure 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(380,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(380,80,100,20,FontHandle(2),16,0,msg_Configure(NationalLanguage),Len(msg_Configure(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __ScreenCapture
				;** ScreenCapture 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(380,100,102,19,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(380,100,102,19,FontHandle(2),16,0,msg_ScreenCapture(NationalLanguage),Len(msg_ScreenCapture(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Animate
				;** Animate 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(380,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(380,120,100,20,FontHandle(2),16,0,msg_Animate(NationalLanguage),Len(msg_Animate(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Image
				;** Image 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,5,70,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,5,70,20,FontHandle(2),16,0,msg_Image(NationalLanguage),Len(msg_Image(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Copy
				;** Copy 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,40,130,20,FontHandle(2),16,0,msg_Copy(NationalLanguage),Len(msg_Copy(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,40,130,20,FontHandle(2),16,0,msg_Copy(NationalLanguage),Len(msg_Copy(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Paste
				;** Paste 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,60,130,20,FontHandle(2),16,0,msg_Paste(NationalLanguage),Len(msg_Paste(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,60,130,20,FontHandle(2),16,0,msg_Paste(NationalLanguage),Len(msg_Paste(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Cut
				;** Cut 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,80,130,20,FontHandle(2),16,0,msg_Cut(NationalLanguage),Len(msg_Cut(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,80,130,20,FontHandle(2),16,0,msg_Cut(NationalLanguage),Len(msg_Cut(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Rotate90
				;** Rotate90 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,100,130,20,FontHandle(2),16,0,msg_Rotate90(NationalLanguage),Len(msg_Rotate90(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,100,130,20,FontHandle(2),16,0,msg_Rotate90(NationalLanguage),Len(msg_Rotate90(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Rotate180
				;** Rotate180 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,120,130,20,FontHandle(2),16,0,msg_Rotate180(NationalLanguage),Len(msg_Rotate180(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,120,130,20,FontHandle(2),16,0,msg_Rotate180(NationalLanguage),Len(msg_Rotate180(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Rotate270
				;** Rotate270 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,140,130,20,FontHandle(2),16,0,msg_Rotate270(NationalLanguage),Len(msg_Rotate270(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,140,130,20,FontHandle(2),16,0,msg_Rotate270(NationalLanguage),Len(msg_Rotate270(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __ChangeColour
				;** ChangeColour 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,160,130,20,FontHandle(2),16,0,msg_ChangeColour(NationalLanguage),Len(msg_ChangeColour(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,160,130,20,FontHandle(2),16,0,msg_ChangeColour(NationalLanguage),Len(msg_ChangeColour(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __GreyScale
				;** GreyScale 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,180,130,20,FontHandle(2),16,0,msg_GreyScale(NationalLanguage),Len(msg_GreyScale(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,180,130,20,FontHandle(2),16,0,msg_GreyScale(NationalLanguage),Len(msg_GreyScale(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __VerticalMirror
				;** VerticalMirror 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,200,130,20,FontHandle(2),16,0,msg_VerticalMirror(NationalLanguage),Len(msg_VerticalMirror(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,200,130,20,FontHandle(2),16,0,msg_VerticalMirror(NationalLanguage),Len(msg_VerticalMirror(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __HorizontalMirror
				;** HorizontalMirror 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,220,130,20,FontHandle(2),16,0,msg_HorizontalMirror(NationalLanguage),Len(msg_HorizontalMirror(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,220,130,20,FontHandle(2),16,0,msg_HorizontalMirror(NationalLanguage),Len(msg_HorizontalMirror(NationalLanguage)),/0020)
				Endif
				Goto &Continue
			Case __Dimensions
				;** Dimensions 
				if (( MouseType and _MIMO_DOWN) <> 0)
					Status=VisualButton(500,240,130,20,FontHandle(2),16,0,msg_Dimensions(NationalLanguage),Len(msg_Dimensions(NationalLanguage)),/0024)
				Endif
				if (( MouseType and _MIMO_UP) <> 0)
					Status=VisualButton(500,240,130,20,FontHandle(2),16,0,msg_Dimensions(NationalLanguage),Len(msg_Dimensions(NationalLanguage)),/0020)
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
			Break
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
		Case	11
			repeat
				If(FocusItem > 1)
					FocusItem = FocusItem-1
				Else
					FocusItem = FocusItems
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
