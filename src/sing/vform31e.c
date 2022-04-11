
#ifndef _vform31e_c
#define _vform31e_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vform31e.xml                                             */
/* Target         : vform31e.c                                               */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "abaltype.h"
#include "singmemb.h"
#include "singprot.h"
#define en__Auto3559   ""
#define fr__Auto3559   ""
#define it__Auto3559   ""
#define es__Auto3559   ""
#define de__Auto3559   ""
#define nl__Auto3559   ""
#define pt__Auto3559   ""
#define xx__Auto3559   ""
#define en_Auto3560   "skin.gif"
#define fr_Auto3560   "skin.gif"
#define it_Auto3560   "skin.gif"
#define es_Auto3560   "skin.gif"
#define de_Auto3560   "skin.gif"
#define nl_Auto3560   "skin.gif"
#define pt_Auto3560   "skin.gif"
#define xx_Auto3560   "skin.gif"
#define fr__Auto3560   ""
#define en_FormControl   "&Form Properties"
#define fr_FormControl   "&Formulaire"
#define it_FormControl   "&Form Properties"
#define es_FormControl   "&Form Properties"
#define de_FormControl   "&Eigenschaften"
#define nl_FormControl   "&Form Properties"
#define pt_FormControl   "&Form Properties"
#define xx_FormControl   "&Form Properties"
#define en__FormControl   ""
#define fr__FormControl   ""
#define it__FormControl   ""
#define es__FormControl   ""
#define de__FormControl   ""
#define nl__FormControl   ""
#define pt__FormControl   ""
#define xx__FormControl   ""
#define en_Auto3561   "Code Production Options"
#define fr_Auto3561   "Options de production du code"
#define it_Auto3561   "Code Production Options"
#define es_Auto3561   "Code Production Options"
#define de_Auto3561   "Code Produktions Optionen"
#define nl_Auto3561   "Code Production Options"
#define pt_Auto3561   "Code Production Options"
#define xx_Auto3561   "Code Production Options"
#define en__Auto3561   ""
#define fr__Auto3561   ""
#define it__Auto3561   ""
#define es__Auto3561   ""
#define de__Auto3561   ""
#define nl__Auto3561   ""
#define pt__Auto3561   ""
#define xx__Auto3561   ""
#define en_Auto3563   "ARGV$="
#define fr_Auto3563   "ARGV$="
#define it_Auto3563   "ARGV$="
#define es_Auto3563   "ARGV$="
#define de_Auto3563   "ARGV$="
#define nl_Auto3563   "ARGV$="
#define pt_Auto3563   "ARGV$="
#define xx_Auto3563   "ARGV$="
#define en__Auto3563   ""
#define fr__Auto3563   ""
#define it__Auto3563   ""
#define es__Auto3563   ""
#define de__Auto3563   ""
#define nl__Auto3563   ""
#define pt__Auto3563   ""
#define xx__Auto3563   ""
#define en_Auto3564   "Width"
#define fr_Auto3564   "Largeur"
#define it_Auto3564   "Width"
#define es_Auto3564   "Width"
#define de_Auto3564   "Width"
#define nl_Auto3564   "Width"
#define pt_Auto3564   "Width"
#define xx_Auto3564   "Width"
#define en__Auto3564   ""
#define fr__Auto3564   ""
#define it__Auto3564   ""
#define es__Auto3564   ""
#define de__Auto3564   ""
#define nl__Auto3564   ""
#define pt__Auto3564   ""
#define xx__Auto3564   ""
#define en_Auto3565   "Height"
#define fr_Auto3565   "Hauteur"
#define it_Auto3565   "Height"
#define es_Auto3565   "Height"
#define de_Auto3565   "Height"
#define nl_Auto3565   "Height"
#define pt_Auto3565   "Height"
#define xx_Auto3565   "Height"
#define en__Auto3565   ""
#define fr__Auto3565   ""
#define it__Auto3565   ""
#define es__Auto3565   ""
#define de__Auto3565   ""
#define nl__Auto3565   ""
#define pt__Auto3565   ""
#define xx__Auto3565   ""
#define en_Auto3566   "("
#define fr_Auto3566   "("
#define it_Auto3566   "("
#define es_Auto3566   "("
#define de_Auto3566   "("
#define nl_Auto3566   "("
#define pt_Auto3566   "("
#define xx_Auto3566   "("
#define en_Auto3567   ")"
#define fr_Auto3567   ")"
#define it_Auto3567   ")"
#define es_Auto3567   ")"
#define de_Auto3567   ")"
#define nl_Auto3567   ")"
#define pt_Auto3567   ")"
#define xx_Auto3567   ")"
#define en_Auto3568   "ok.gif"
#define fr_Auto3568   "ok.gif"
#define it_Auto3568   "ok.gif"
#define es_Auto3568   "ok.gif"
#define de_Auto3568   "ok.gif"
#define nl_Auto3568   "ok.gif"
#define pt_Auto3568   "ok.gif"
#define xx_Auto3568   "ok.gif"
#define en__Auto3568   ""
#define fr__Auto3568   ""
#define it__Auto3568   ""
#define es__Auto3568   ""
#define de__Auto3568   ""
#define nl__Auto3568   ""
#define pt__Auto3568   ""
#define xx__Auto3568   ""
#define en_Auto3569   "cancel.gif"
#define fr_Auto3569   "cancel.gif"
#define it_Auto3569   "cancel.gif"
#define es_Auto3569   "cancel.gif"
#define de_Auto3569   "cancel.gif"
#define nl_Auto3569   "cancel.gif"
#define pt_Auto3569   "cancel.gif"
#define xx_Auto3569   "cancel.gif"
#define en__Auto3569   ""
#define fr__Auto3569   ""
#define it__Auto3569   ""
#define es__Auto3569   ""
#define de__Auto3569   ""
#define nl__Auto3569   ""
#define pt__Auto3569   ""
#define xx__Auto3569   ""
#define en_Auto3570   "Production Model"
#define fr_Auto3570   "ModŠle de production"
#define it_Auto3570   "Production Model"
#define es_Auto3570   "Production Model"
#define de_Auto3570   "Produktions Modell"
#define nl_Auto3570   "Production Model"
#define pt_Auto3570   "Production Model"
#define xx_Auto3570   "Production Model"
#define en__Auto3570   ""
#define fr__Auto3570   ""
#define it__Auto3570   ""
#define es__Auto3570   ""
#define de__Auto3570   ""
#define nl__Auto3570   ""
#define pt__Auto3570   ""
#define xx__Auto3570   ""
#define en_Auto3571   "Production Language"
#define fr_Auto3571   "Langage de production"
#define it_Auto3571   "Production Language"
#define es_Auto3571   "Production Language"
#define de_Auto3571   "Produktions Sprache"
#define nl_Auto3571   "Production Language"
#define pt_Auto3571   "Production Language"
#define xx_Auto3571   "Production Language"
#define en__Auto3571   ""
#define fr__Auto3571   ""
#define it__Auto3571   ""
#define es__Auto3571   ""
#define de__Auto3571   ""
#define nl__Auto3571   ""
#define pt__Auto3571   ""
#define xx__Auto3571   ""
#define en_Auto3572   "National Language"
#define fr_Auto3572   "Langue"
#define it_Auto3572   "National Language"
#define es_Auto3572   "National Language"
#define de_Auto3572   "Nationale Sprache"
#define nl_Auto3572   "National Language"
#define pt_Auto3572   "National Language"
#define xx_Auto3572   "National Language"
#define en__Auto3572   ""
#define fr__Auto3572   ""
#define it__Auto3572   ""
#define es__Auto3572   ""
#define de__Auto3572   ""
#define nl__Auto3572   ""
#define pt__Auto3572   ""
#define xx__Auto3572   ""
#define en__FormType   ""
#define fr__FormType   ""
#define it__FormType   ""
#define es__FormType   ""
#define de__FormType   ""
#define nl__FormType   ""
#define pt__FormType   ""
#define xx__FormType   ""
#define en__ProductionLanguage   ""
#define fr__ProductionLanguage   ""
#define it__ProductionLanguage   ""
#define es__ProductionLanguage   ""
#define de__ProductionLanguage   ""
#define nl__ProductionLanguage   ""
#define pt__ProductionLanguage   ""
#define xx__ProductionLanguage   ""
#define en__NationalLanguage   ""
#define en_International   "&Internationalisation"
#define fr_International   "&Internationalisation"
#define it_International   "&Internationalisation"
#define es_International   "&Internationalisation"
#define de_International   "&Internationalisation"
#define nl_International   "&Internationalisation"
#define pt_International   "&Internationalisation"
#define xx_International   "&Internationalisation"
#define en__International   ""
#define fr__International   ""
#define it__International   ""
#define es__International   ""
#define de__International   ""
#define nl__International   ""
#define pt__International   ""
#define xx__International   ""
#define en_Constants   "Inhibit &Constant Expressions"
#define fr_Constants   "Expressions &constantes inhib‚es"
#define it_Constants   "Inhibit &Constant Expressions"
#define es_Constants   "Inhibit &Constant Expressions"
#define de_Constants   "Blockieren Konstanten Ausdrucke"
#define nl_Constants   "Inhibit &Constant Expressions"
#define pt_Constants   "Inhibit &Constant Expressions"
#define xx_Constants   "Inhibit &Constant Expressions"
#define en__Constants   ""
#define fr__Constants   ""
#define it__Constants   ""
#define es__Constants   ""
#define de__Constants   ""
#define nl__Constants   ""
#define pt__Constants   ""
#define xx__Constants   ""
#define en_MultipleLanguage   "M&ultiple Lingual Messages"
#define fr_MultipleLanguage   "&Generation multilingue"
#define it_MultipleLanguage   "M&ultiple Lingual Messages"
#define es_MultipleLanguage   "M&ultiple Lingual Messages"
#define de_MultipleLanguage   "Mehrsprachige Meldungen"
#define nl_MultipleLanguage   "M&ultiple Lingual Messages"
#define pt_MultipleLanguage   "M&ultiple Lingual Messages"
#define xx_MultipleLanguage   "M&ultiple Lingual Messages"
#define en__MultipleLanguage   ""
#define fr__MultipleLanguage   ""
#define it__MultipleLanguage   ""
#define es__MultipleLanguage   ""
#define de__MultipleLanguage   ""
#define nl__MultipleLanguage   ""
#define pt__MultipleLanguage   ""
#define xx__MultipleLanguage   ""
#define en_Program   "&Stand alone Program Unit"
#define fr_Program   "&Programme autonome"
#define it_Program   "&Stand alone Program Unit"
#define es_Program   "&Stand alone Program Unit"
#define de_Program   "Standalone Programm Einheit"
#define nl_Program   "&Stand alone Program Unit"
#define pt_Program   "&Stand alone Program Unit"
#define xx_Program   "&Stand alone Program Unit"
#define en__Program   ""
#define fr__Program   ""
#define it__Program   ""
#define es__Program   ""
#define de__Program   ""
#define nl__Program   ""
#define pt__Program   ""
#define xx__Program   ""
#define en_Overlay   "Su&bordinate Overlay or Module"
#define fr_Overlay   "M&odule ou Programme Overlay"
#define it_Overlay   "Su&bordinate Overlay or Module"
#define es_Overlay   "Su&bordinate Overlay or Module"
#define de_Overlay   "Overlay oder Module"
#define nl_Overlay   "Su&bordinate Overlay or Module"
#define pt_Overlay   "Su&bordinate Overlay or Module"
#define xx_Overlay   "Su&bordinate Overlay or Module"
#define en__Overlay   ""
#define fr__Overlay   ""
#define it__Overlay   ""
#define es__Overlay   ""
#define de__Overlay   ""
#define nl__Overlay   ""
#define pt__Overlay   ""
#define xx__Overlay   ""
#define en_PopUp   "&Pop-Up style Component"
#define fr_PopUp   "Style Pop-&Up"
#define it_PopUp   "&Pop-Up style Component"
#define es_PopUp   "&Pop-Up style Component"
#define de_PopUp   "&Pop-Up Komponente"
#define nl_PopUp   "&Pop-Up style Component"
#define pt_PopUp   "&Pop-Up style Component"
#define xx_PopUp   "&Pop-Up style Component"
#define en__PopUp   ""
#define fr__PopUp   ""
#define it__PopUp   ""
#define es__PopUp   ""
#define de__PopUp   ""
#define nl__PopUp   ""
#define pt__PopUp   ""
#define xx__PopUp   ""
#define en_Dynamic   "&Dynamic Positioning"
#define fr_Dynamic   "&D‚pla‡able"
#define it_Dynamic   "&Dynamic Positioning"
#define es_Dynamic   "&Dynamic Positioning"
#define de_Dynamic   "&Dynamische Positionierung"
#define nl_Dynamic   "&Dynamic Positioning"
#define pt_Dynamic   "&Dynamic Positioning"
#define xx_Dynamic   "&Dynamic Positioning"
#define en__Dynamic   ""
#define fr__Dynamic   ""
#define it__Dynamic   ""
#define es__Dynamic   ""
#define de__Dynamic   ""
#define nl__Dynamic   ""
#define pt__Dynamic   ""
#define xx__Dynamic   ""
#define en_CommandLine   "C&ommand Line Parameter Reception"
#define fr_CommandLine   "Ge&stion de ligne de commande"
#define it_CommandLine   "C&ommand Line Parameter Reception"
#define es_CommandLine   "C&ommand Line Parameter Reception"
#define de_CommandLine   "Befehlszeilenempfangsparameter"
#define nl_CommandLine   "C&ommand Line Parameter Reception"
#define pt_CommandLine   "C&ommand Line Parameter Reception"
#define xx_CommandLine   "C&ommand Line Parameter Reception"
#define en__CommandLine   ""
#define fr__CommandLine   ""
#define it__CommandLine   ""
#define es__CommandLine   ""
#define de__CommandLine   ""
#define nl__CommandLine   ""
#define pt__CommandLine   ""
#define xx__CommandLine   ""
#define en_ArgVLen   ""
#define fr_ArgVLen   ""
#define it_ArgVLen   ""
#define es_ArgVLen   ""
#define de_ArgVLen   ""
#define nl_ArgVLen   ""
#define pt_ArgVLen   ""
#define xx_ArgVLen   ""
#define en_ArgVNb   ""
#define fr_ArgVNb   ""
#define it_ArgVNb   ""
#define es_ArgVNb   ""
#define de_ArgVNb   ""
#define nl_ArgVNb   ""
#define pt_ArgVNb   ""
#define xx_ArgVNb   ""
#define en_Resize   "Automatic Resize"
#define fr_Resize   "&Redimensionment automatique"
#define it_Resize   "Automatic Resize"
#define es_Resize   "Automatic Resize"
#define de_Resize   "Automatic Resize"
#define nl_Resize   "Automatic Resize"
#define pt_Resize   "Automatic Resize"
#define xx_Resize   "Automatic Resize"
#define en__Resize   ""
#define fr__Resize   ""
#define it__Resize   ""
#define es__Resize   ""
#define de__Resize   ""
#define nl__Resize   ""
#define pt__Resize   ""
#define xx__Resize   ""
#define en_ResizeX   ""
#define fr_ResizeX   ""
#define it_ResizeX   ""
#define es_ResizeX   ""
#define de_ResizeX   ""
#define nl_ResizeX   ""
#define pt_ResizeX   ""
#define xx_ResizeX   ""
#define en__ResizeX   ""
#define en_ResizeY   ""
#define fr_ResizeY   ""
#define it_ResizeY   ""
#define es_ResizeY   ""
#define de_ResizeY   ""
#define nl_ResizeY   ""
#define pt_ResizeY   ""
#define xx_ResizeY   ""
#define en__ResizeY   ""
#define en_GenHelp   "None|Plain|Html"
#define fr_GenHelp   "Aucun|Texte|Html"
#define it_GenHelp   "None|Plain|Html"
#define es_GenHelp   "None|Plain|Html"
#define de_GenHelp   "None|Plain|Html"
#define nl_GenHelp   "None|Plain|Html"
#define pt_GenHelp   "None|Plain|Html"
#define xx_GenHelp   "None|Plain|Html"
#define en__GenHelp   ""
#define fr__GenHelp   ""
#define it__GenHelp   ""
#define es__GenHelp   ""
#define de__GenHelp   ""
#define nl__GenHelp   ""
#define pt__GenHelp   ""
#define xx__GenHelp   ""
#define en_ActHelp   "Manual|Auto"
#define fr_ActHelp   "Manuel|Auto"
#define it_ActHelp   "Manual|Auto"
#define es_ActHelp   "Manual|Auto"
#define de_ActHelp   "Manual|Auto"
#define nl_ActHelp   "Manual|Auto"
#define pt_ActHelp   "Manual|Auto"
#define xx_ActHelp   "Manual|Auto"
#define en__ActHelp   ""
#define fr__ActHelp   ""
#define it__ActHelp   ""
#define es__ActHelp   ""
#define de__ActHelp   ""
#define nl__ActHelp   ""
#define pt__ActHelp   ""
#define xx__ActHelp   ""
#define en_Auto3573   "Online Help"
#define fr_Auto3573   "Aide en ligne"
#define it_Auto3573   "Online Help"
#define es_Auto3573   "Online Help"
#define de_Auto3573   "Online Help"
#define nl_Auto3573   "Online Help"
#define pt_Auto3573   "Online Help"
#define xx_Auto3573   "Online Help"
#define en__Auto3573   ""
#define fr__Auto3573   ""
#define it__Auto3573   ""
#define es__Auto3573   ""
#define de__Auto3573   ""
#define nl__Auto3573   ""
#define pt__Auto3573   ""
#define xx__Auto3573   ""
#define en_auto7   "Production Filename"
#define fr_auto7   "Nom du fichier source Abal++"
#define it_auto7   "Production Filename"
#define es_auto7   "Production Filename"
#define de_auto7   "Production Filename"
#define nl_auto7   "Production Filename"
#define pt_auto7   "Production Filename"
#define xx_auto7   "Production Filename"
#define en__auto7   ""
#define fr__auto7   ""
#define it__auto7   ""
#define es__auto7   ""
#define de__auto7   ""
#define nl__auto7   ""
#define pt__auto7   ""
#define xx__auto7   ""
#define en_auto52   "Component Identification"
#define fr_auto52   "Nom du formulaire"
#define it_auto52   "Component Identification"
#define es_auto52   "Component Identification"
#define de_auto52   "Component Identifikation"
#define nl_auto52   "Component Identification"
#define pt_auto52   "Component Identification"
#define xx_auto52   "Component Identification"
#define en__auto52   ""
#define fr__auto52   ""
#define it__auto52   ""
#define es__auto52   ""
#define de__auto52   ""
#define nl__auto52   ""
#define pt__auto52   ""
#define xx__auto52   ""
#define en_Auto3574   "Filename containing the Style Classes"
#define fr_Auto3574   "Nom de fichier de classes de styles"
#define it_Auto3574   "Filename containing the Style Classes"
#define es_Auto3574   "Filename containing the Style Classes"
#define de_Auto3574   "Filename containing the Style Classes"
#define nl_Auto3574   "Filename containing the Style Classes"
#define pt_Auto3574   "Filename containing the Style Classes"
#define xx_Auto3574   "Filename containing the Style Classes"
#define en__Auto3574   ""
#define fr__Auto3574   ""
#define it__Auto3574   ""
#define es__Auto3574   ""
#define de__Auto3574   ""
#define nl__Auto3574   ""
#define pt__Auto3574   ""
#define xx__Auto3574   ""
#define en_Auto3575   "Classname of Screen Background Style"
#define fr_Auto3575   "Nom de la classe de style pour le fond d'‚cran"
#define it_Auto3575   "Classname of Screen Background Style"
#define es_Auto3575   "Classname of Screen Background Style"
#define de_Auto3575   "Classname of Screen Background Style"
#define nl_Auto3575   "Classname of Screen Background Style"
#define pt_Auto3575   "Classname of Screen Background Style"
#define xx_Auto3575   "Classname of Screen Background Style"
#define en__Auto3575   ""
#define fr__Auto3575   ""
#define it__Auto3575   ""
#define es__Auto3575   ""
#define de__Auto3575   ""
#define nl__Auto3575   ""
#define pt__Auto3575   ""
#define xx__Auto3575   ""
#define en_FileName   ""
#define fr_FileName   ""
#define it_FileName   ""
#define es_FileName   ""
#define de_FileName   ""
#define nl_FileName   ""
#define pt_FileName   ""
#define xx_FileName   ""
#define en_ChooseFileName   "..."
#define fr_ChooseFileName   "..."
#define it_ChooseFileName   "..."
#define es_ChooseFileName   "..."
#define de_ChooseFileName   "..."
#define nl_ChooseFileName   "..."
#define pt_ChooseFileName   "..."
#define xx_ChooseFileName   "..."
#define en__ChooseFileName   ""
#define en_ChooseStyleName   "..."
#define fr_ChooseStyleName   "..."
#define it_ChooseStyleName   "..."
#define es_ChooseStyleName   "..."
#define de_ChooseStyleName   "..."
#define nl_ChooseStyleName   "..."
#define pt_ChooseStyleName   "..."
#define xx_ChooseStyleName   "..."
#define en__ChooseStyleName   ""
#define en_EditSource   "edit"
#define fr_EditSource   "edit"
#define it_EditSource   "edit"
#define es_EditSource   "edit"
#define de_EditSource   "edit"
#define nl_EditSource   "edit"
#define pt_EditSource   "edit"
#define xx_EditSource   "edit"
#define en__EditSource   ""
#define fr__EditSource   ""
#define it__EditSource   ""
#define es__EditSource   ""
#define de__EditSource   ""
#define nl__EditSource   ""
#define pt__EditSource   ""
#define xx__EditSource   ""
#define en_EditStyle   "edit"
#define fr_EditStyle   "edit"
#define it_EditStyle   "edit"
#define es_EditStyle   "edit"
#define de_EditStyle   "edit"
#define nl_EditStyle   "edit"
#define pt_EditStyle   "edit"
#define xx_EditStyle   "edit"
#define en__EditStyle   ""
#define fr__EditStyle   ""
#define it__EditStyle   ""
#define es__EditStyle   ""
#define de__EditStyle   ""
#define nl__EditStyle   ""
#define pt__EditStyle   ""
#define xx__EditStyle   ""
#define en_Identity   ""
#define fr_Identity   ""
#define it_Identity   ""
#define es_Identity   ""
#define de_Identity   ""
#define nl_Identity   ""
#define pt_Identity   ""
#define xx_Identity   ""
#define en__Identity   ""
#define en_StyleSheet   ""
#define fr_StyleSheet   ""
#define it_StyleSheet   ""
#define es_StyleSheet   ""
#define de_StyleSheet   ""
#define nl_StyleSheet   ""
#define pt_StyleSheet   ""
#define xx_StyleSheet   ""
#define en_Auto3576   "Palette Filename"
#define fr_Auto3576   "Nom de fichier Palette"
#define it_Auto3576   "Palette Filename"
#define es_Auto3576   "Palette Filename"
#define de_Auto3576   "Name Datei Farben"
#define nl_Auto3576   "Palette Filename"
#define pt_Auto3576   "Palette Filename"
#define xx_Auto3576   "Palette Filename"
#define en__Auto3576   ""
#define fr__Auto3576   ""
#define it__Auto3576   ""
#define es__Auto3576   ""
#define de__Auto3576   ""
#define nl__Auto3576   ""
#define pt__Auto3576   ""
#define xx__Auto3576   ""
#define en_ChoosePalette   "..."
#define fr_ChoosePalette   "..."
#define it_ChoosePalette   "..."
#define es_ChoosePalette   "..."
#define de_ChoosePalette   "..."
#define nl_ChoosePalette   "..."
#define pt_ChoosePalette   "..."
#define xx_ChoosePalette   "..."
#define en__ChoosePalette   ""
#define en_PaletteName   ""
#define fr_PaletteName   ""
#define it_PaletteName   ""
#define es_PaletteName   ""
#define de_PaletteName   ""
#define nl_PaletteName   ""
#define pt_PaletteName   ""
#define xx_PaletteName   ""
#define en__PaletteName   ""
#define en_ClearScreen   ""
#define fr_ClearScreen   ""
#define it_ClearScreen   ""
#define es_ClearScreen   ""
#define de_ClearScreen   ""
#define nl_ClearScreen   ""
#define pt_ClearScreen   ""
#define xx_ClearScreen   ""
#define en__ClearScreen   ""
#define en_MouseEvents   "E&vent Manager"
#define fr_MouseEvents   "Ev‚&nements"
#define it_MouseEvents   "E&vent Manager"
#define es_MouseEvents   "E&vent Manager"
#define de_MouseEvents   "Ereignis Manager"
#define nl_MouseEvents   "E&vent Manager"
#define pt_MouseEvents   "E&vent Manager"
#define xx_MouseEvents   "E&vent Manager"
#define en__MouseEvents   ""
#define fr__MouseEvents   ""
#define it__MouseEvents   ""
#define es__MouseEvents   ""
#define de__MouseEvents   ""
#define nl__MouseEvents   ""
#define pt__MouseEvents   ""
#define xx__MouseEvents   ""
#define en_Auto3577   "Mouse Buttons"
#define fr_Auto3577   "Boutons de la souris"
#define it_Auto3577   "Mouse Buttons"
#define es_Auto3577   "Mouse Buttons"
#define de_Auto3577   "Maus Buttons"
#define nl_Auto3577   "Mouse Buttons"
#define pt_Auto3577   "Mouse Buttons"
#define xx_Auto3577   "Mouse Buttons"
#define en__Auto3577   ""
#define fr__Auto3577   ""
#define it__Auto3577   ""
#define es__Auto3577   ""
#define de__Auto3577   ""
#define nl__Auto3577   ""
#define pt__Auto3577   ""
#define xx__Auto3577   ""
#define en_Auto3578   "Mouse Events"
#define fr_Auto3578   "Evenements souris"
#define it_Auto3578   "Mouse Events"
#define es_Auto3578   "Mouse Events"
#define de_Auto3578   "Maus Ereignisse"
#define nl_Auto3578   "Mouse Events"
#define pt_Auto3578   "Mouse Events"
#define xx_Auto3578   "Mouse Events"
#define en__Auto3578   ""
#define fr__Auto3578   ""
#define it__Auto3578   ""
#define es__Auto3578   ""
#define de__Auto3578   ""
#define nl__Auto3578   ""
#define pt__Auto3578   ""
#define xx__Auto3578   ""
#define en_Auto3579   "Keyboard Events"
#define fr_Auto3579   "Evenements clavier"
#define it_Auto3579   "Keyboard Events"
#define es_Auto3579   "Keyboard Events"
#define de_Auto3579   "Tastatur Ereignisse"
#define nl_Auto3579   "Keyboard Events"
#define pt_Auto3579   "Keyboard Events"
#define xx_Auto3579   "Keyboard Events"
#define en__Auto3579   ""
#define fr__Auto3579   ""
#define it__Auto3579   ""
#define es__Auto3579   ""
#define de__Auto3579   ""
#define nl__Auto3579   ""
#define pt__Auto3579   ""
#define xx__Auto3579   ""
#define en_SendLeft   "M&ouse Left Button"
#define fr_SendLeft   "&Bouton Gauche de la Souris"
#define it_SendLeft   "M&ouse Left Button"
#define es_SendLeft   "M&ouse Left Button"
#define de_SendLeft   "Linker Maus Button"
#define nl_SendLeft   "M&ouse Left Button"
#define pt_SendLeft   "M&ouse Left Button"
#define xx_SendLeft   "M&ouse Left Button"
#define en__SendLeft   ""
#define fr__SendLeft   ""
#define it__SendLeft   ""
#define es__SendLeft   ""
#define de__SendLeft   ""
#define nl__SendLeft   ""
#define pt__SendLeft   ""
#define xx__SendLeft   ""
#define en_SendMiddle   "M&iddle Button"
#define fr_SendMiddle   "B&outon de Mileu de la Souris"
#define it_SendMiddle   "M&iddle Button"
#define es_SendMiddle   "M&iddle Button"
#define de_SendMiddle   "Mittlerer Maus Button"
#define nl_SendMiddle   "M&iddle Button"
#define pt_SendMiddle   "M&iddle Button"
#define xx_SendMiddle   "M&iddle Button"
#define en__SendMiddle   ""
#define fr__SendMiddle   ""
#define it__SendMiddle   ""
#define es__SendMiddle   ""
#define de__SendMiddle   ""
#define nl__SendMiddle   ""
#define pt__SendMiddle   ""
#define xx__SendMiddle   ""
#define en_SendRight   "Mo&use Right Button"
#define fr_SendRight   "Bo&uton Droite de la Souris"
#define it_SendRight   "Mo&use Right Button"
#define es_SendRight   "Mo&use Right Button"
#define de_SendRight   "Rechter Maus Button"
#define nl_SendRight   "Mo&use Right Button"
#define pt_SendRight   "Mo&use Right Button"
#define xx_SendRight   "Mo&use Right Button"
#define en__SendRight   ""
#define fr__SendRight   ""
#define it__SendRight   ""
#define es__SendRight   ""
#define de__SendRight   ""
#define nl__SendRight   ""
#define pt__SendRight   ""
#define xx__SendRight   ""
#define en_SendWheel   "Mouse &Wheel"
#define fr_SendWheel   "Molette &Souris"
#define it_SendWheel   "Mouse &Wheel"
#define es_SendWheel   "Mouse &Wheel"
#define de_SendWheel   "Mouse &Wheel"
#define nl_SendWheel   "Mouse &Wheel"
#define pt_SendWheel   "Mouse &Wheel"
#define xx_SendWheel   "Mouse &Wheel"
#define en__SendWheel   ""
#define fr__SendWheel   ""
#define it__SendWheel   ""
#define es__SendWheel   ""
#define de__SendWheel   ""
#define nl__SendWheel   ""
#define pt__SendWheel   ""
#define xx__SendWheel   ""
#define en_ButtonFilter   "Widget Button &Filtering"
#define fr_ButtonFilter   "Bo&uton Droite de la Souris"
#define it_ButtonFilter   "Mo&use Right Button"
#define es_ButtonFilter   "Mo&use Right Button"
#define de_ButtonFilter   "Rechter Maus Button"
#define nl_ButtonFilter   "Mo&use Right Button"
#define pt_ButtonFilter   "Mo&use Right Button"
#define xx_ButtonFilter   "Mo&use Right Button"
#define en__ButtonFilter   ""
#define fr__ButtonFilter   ""
#define it__ButtonFilter   ""
#define es__ButtonFilter   ""
#define de__ButtonFilter   ""
#define nl__ButtonFilter   ""
#define pt__ButtonFilter   ""
#define xx__ButtonFilter   ""
#define en_SendDown   "Mou&se Button DOWN"
#define fr_SendDown   "Bou&ton appuy‚e"
#define it_SendDown   "Mou&se Button DOWN"
#define es_SendDown   "Mou&se Button DOWN"
#define de_SendDown   "Maus Button DOWN"
#define nl_SendDown   "Mou&se Button DOWN"
#define pt_SendDown   "Mou&se Button DOWN"
#define xx_SendDown   "Mou&se Button DOWN"
#define en__SendDown   ""
#define fr__SendDown   ""
#define it__SendDown   ""
#define es__SendDown   ""
#define de__SendDown   ""
#define nl__SendDown   ""
#define pt__SendDown   ""
#define xx__SendDown   ""
#define en_SendUp   "Mouse &Button UP"
#define fr_SendUp   "Bouton &relƒch‚"
#define it_SendUp   "Mouse &Button UP"
#define es_SendUp   "Mouse &Button UP"
#define de_SendUp   "Maus Button UP"
#define nl_SendUp   "Mouse &Button UP"
#define pt_SendUp   "Mouse &Button UP"
#define xx_SendUp   "Mouse &Button UP"
#define en__SendUp   ""
#define fr__SendUp   ""
#define it__SendUp   ""
#define es__SendUp   ""
#define de__SendUp   ""
#define nl__SendUp   ""
#define pt__SendUp   ""
#define xx__SendUp   ""
#define en_SendWhileDown   "Mouse Move &While Down"
#define fr_SendWhileDown   "De&placement bouton appuy‚"
#define it_SendWhileDown   "Mouse Move &While Down"
#define es_SendWhileDown   "Mouse Move &While Down"
#define de_SendWhileDown   "Maus Bewegung mit DOWN"
#define nl_SendWhileDown   "Mouse Move &While Down"
#define pt_SendWhileDown   "Mouse Move &While Down"
#define xx_SendWhileDown   "Mouse Move &While Down"
#define en__SendWhileDown   ""
#define fr__SendWhileDown   ""
#define it__SendWhileDown   ""
#define es__SendWhileDown   ""
#define de__SendWhileDown   ""
#define nl__SendWhileDown   ""
#define pt__SendWhileDown   ""
#define xx__SendWhileDown   ""
#define en_SendMove   "Mouse &Pointer Move"
#define fr_SendMove   "Dep&lacement souris libre"
#define it_SendMove   "Mouse &Pointer Move"
#define es_SendMove   "Mouse &Pointer Move"
#define de_SendMove   "Maus Begegung"
#define nl_SendMove   "Mouse &Pointer Move"
#define pt_SendMove   "Mouse &Pointer Move"
#define xx_SendMove   "Mouse &Pointer Move"
#define en__SendMove   ""
#define fr__SendMove   ""
#define it__SendMove   ""
#define es__SendMove   ""
#define de__SendMove   ""
#define nl__SendMove   ""
#define pt__SendMove   ""
#define xx__SendMove   ""
#define en_MouseKey   "Mouse Eve&nt Channel"
#define fr_MouseKey   "Gestion des ‚&v‚nements souris"
#define it_MouseKey   "Mouse Eve&nt Channel"
#define es_MouseKey   "Mouse Eve&nt Channel"
#define de_MouseKey   "Maus Ereignis Kanal"
#define nl_MouseKey   "Mouse Eve&nt Channel"
#define pt_MouseKey   "Mouse Eve&nt Channel"
#define xx_MouseKey   "Mouse Eve&nt Channel"
#define en__MouseKey   ""
#define fr__MouseKey   ""
#define it__MouseKey   ""
#define es__MouseKey   ""
#define de__MouseKey   ""
#define nl__MouseKey   ""
#define pt__MouseKey   ""
#define xx__MouseKey   ""
#define en_WidgetTriggers   "Wi&dget Triggers"
#define fr_WidgetTriggers   "Ge&stion Touches Racourcis"
#define it_WidgetTriggers   "Wi&dget Triggers"
#define es_WidgetTriggers   "Wi&dget Triggers"
#define de_WidgetTriggers   "Widget Ausl”ser"
#define nl_WidgetTriggers   "Wi&dget Triggers"
#define pt_WidgetTriggers   "Wi&dget Triggers"
#define xx_WidgetTriggers   "Wi&dget Triggers"
#define en__WidgetTriggers   ""
#define fr__WidgetTriggers   ""
#define it__WidgetTriggers   ""
#define es__WidgetTriggers   ""
#define de__WidgetTriggers   ""
#define nl__WidgetTriggers   ""
#define pt__WidgetTriggers   ""
#define xx__WidgetTriggers   ""
#define en_Escape   "Allow use of the Escape &Key to abandon the form."
#define fr_Escape   "Abandon du formulaire par la touche &Echap"
#define it_Escape   "Allow use of the Escape &Key to abandon the form."
#define es_Escape   "Allow use of the Escape &Key to abandon the form."
#define de_Escape   "Allow use of the Escape &Key to abandon the form."
#define nl_Escape   "Allow use of the Escape &Key to abandon the form."
#define pt_Escape   "Allow use of the Escape &Key to abandon the form."
#define xx_Escape   "Allow use of the Escape &Key to abandon the form."
#define en__Escape   ""
#define fr__Escape   ""
#define it__Escape   ""
#define es__Escape   ""
#define de__Escape   ""
#define nl__Escape   ""
#define pt__Escape   ""
#define xx__Escape   ""
#define en_Enter   "Allow use of the En&ter Key to validate and leave a form."
#define fr_Enter   "Validation et sortie du formulaire par la touche &Entr‚e"
#define it_Enter   "Allow use of the En&ter Key to validate and leave a form."
#define es_Enter   "Allow use of the En&ter Key to validate and leave a form."
#define de_Enter   "Enter Taste"
#define nl_Enter   "Allow use of the En&ter Key to validate and leave a form."
#define pt_Enter   "Allow use of the En&ter Key to validate and leave a form."
#define xx_Enter   "Allow use of the En&ter Key to validate and leave a form."
#define en__Enter   ""
#define fr__Enter   ""
#define it__Enter   ""
#define es__Enter   ""
#define de__Enter   ""
#define nl__Enter   ""
#define pt__Enter   ""
#define xx__Enter   ""
#define en_PageUp   "Allow use of the Pa&ge Up Key to move back to a previous tab page"
#define fr_PageUp   "Activation de l'onglet pr‚c‚dent par la touche Page-&Prev"
#define it_PageUp   "Allow use of the Pa&ge Up Key to move back to a previous tab page"
#define es_PageUp   "Allow use of the Pa&ge Up Key to move back to a previous tab page"
#define de_PageUp   "Pa&ge Up"
#define nl_PageUp   "Allow use of the Pa&ge Up Key to move back to a previous tab page"
#define pt_PageUp   "Allow use of the Pa&ge Up Key to move back to a previous tab page"
#define xx_PageUp   "Allow use of the Pa&ge Up Key to move back to a previous tab page"
#define en__PageUp   ""
#define fr__PageUp   ""
#define it__PageUp   ""
#define es__PageUp   ""
#define de__PageUp   ""
#define nl__PageUp   ""
#define pt__PageUp   ""
#define xx__PageUp   ""
#define en_PageDown   "Allow use of the Page Down key to move back to a previous tab page"
#define fr_PageDown   "Activation de l'onglet suivant par la touche Page-&Suiv"
#define it_PageDown   "Allow use of the Page Down key to move back to a previous tab page"
#define es_PageDown   "Allow use of the Page Down key to move back to a previous tab page"
#define de_PageDown   "Page Down"
#define nl_PageDown   "Allow use of the Page Down key to move back to a previous tab page"
#define pt_PageDown   "Allow use of the Page Down key to move back to a previous tab page"
#define xx_PageDown   "Allow use of the Page Down key to move back to a previous tab page"
#define en__PageDown   ""
#define fr__PageDown   ""
#define it__PageDown   ""
#define es__PageDown   ""
#define de__PageDown   ""
#define nl__PageDown   ""
#define pt__PageDown   ""
#define xx__PageDown   ""
#define en_UpArrow   "Allow use of the Up Arrow Key to move back to the previous form control item."
#define fr_UpArrow   "Passage du focus … l'‚l‚ment pr‚c‚dent par la touche Flˆche-&Haut"
#define it_UpArrow   "Allow use of the Up Arrow Key to move back to the previous form control item."
#define es_UpArrow   "Allow use of the Up Arrow Key to move back to the previous form control item."
#define de_UpArrow   "Pfeil Hoch"
#define nl_UpArrow   "Allow use of the Up Arrow Key to move back to the previous form control item."
#define pt_UpArrow   "Allow use of the Up Arrow Key to move back to the previous form control item."
#define xx_UpArrow   "Allow use of the Up Arrow Key to move back to the previous form control item."
#define en__UpArrow   ""
#define fr__UpArrow   ""
#define it__UpArrow   ""
#define es__UpArrow   ""
#define de__UpArrow   ""
#define nl__UpArrow   ""
#define pt__UpArrow   ""
#define xx__UpArrow   ""
#define en_DownArrow   "Allow use of the Down Arrow Key to move forward to the next form control item."
#define fr_DownArrow   "Passage du focus … l'‚l‚ment suivant par la touche Flˆche-&Bas"
#define it_DownArrow   "Allow use of the Down Arrow Key to move forward to the next form control item."
#define es_DownArrow   "Allow use of the Down Arrow Key to move forward to the next form control item."
#define de_DownArrow   "Pfeil Unten"
#define nl_DownArrow   "Allow use of the Down Arrow Key to move forward to the next form control item."
#define pt_DownArrow   "Allow use of the Down Arrow Key to move forward to the next form control item."
#define xx_DownArrow   "Allow use of the Down Arrow Key to move forward to the next form control item."
#define en__DownArrow   ""
#define fr__DownArrow   ""
#define it__DownArrow   ""
#define es__DownArrow   ""
#define de__DownArrow   ""
#define nl__DownArrow   ""
#define pt__DownArrow   ""
#define xx__DownArrow   ""
#define en_Tabulation   "Allow use of the Tabulation Key to move forward to the next form control item."
#define fr_Tabulation   "Passage du focus … l'‚l‚ment suivant par la touche &Tabulation"
#define it_Tabulation   "Allow use of the Tabulation Key to move forward to the next form control item."
#define es_Tabulation   "Allow use of the Tabulation Key to move forward to the next form control item."
#define de_Tabulation   "Tabulator"
#define nl_Tabulation   "Allow use of the Tabulation Key to move forward to the next form control item."
#define pt_Tabulation   "Allow use of the Tabulation Key to move forward to the next form control item."
#define xx_Tabulation   "Allow use of the Tabulation Key to move forward to the next form control item."
#define en__Tabulation   ""
#define fr__Tabulation   ""
#define it__Tabulation   ""
#define es__Tabulation   ""
#define de__Tabulation   ""
#define nl__Tabulation   ""
#define pt__Tabulation   ""
#define xx__Tabulation   ""
#define en_DefaultBreak   "All other Key events and Mouse Events outside of the Form Area are to be returned to the caller."
#define fr_DefaultBreak   "Trans&fert de tous les autres ‚v‚nements clavier et souris … l'appelant"
#define it_DefaultBreak   "All other Key events and Mouse Events outside of the Form Area are to be returned to the caller."
#define es_DefaultBreak   "All other Key events and Mouse Events outside of the Form Area are to be returned to the caller."
#define de_DefaultBreak   "Default Abbruch"
#define nl_DefaultBreak   "All other Key events and Mouse Events outside of the Form Area are to be returned to the caller."
#define pt_DefaultBreak   "All other Key events and Mouse Events outside of the Form Area are to be returned to the caller."
#define xx_DefaultBreak   "All other Key events and Mouse Events outside of the Form Area are to be returned to the caller."
#define en__DefaultBreak   ""
#define fr__DefaultBreak   ""
#define it__DefaultBreak   ""
#define es__DefaultBreak   ""
#define de__DefaultBreak   ""
#define nl__DefaultBreak   ""
#define pt__DefaultBreak   ""
#define xx__DefaultBreak   ""
#define en_FormMethods   "&Method Manager"
#define fr_FormMethods   "&M‚thodes"
#define it_FormMethods   "&Method Manager"
#define es_FormMethods   "&Method Manager"
#define de_FormMethods   "&Method Manager"
#define nl_FormMethods   "&Method Manager"
#define pt_FormMethods   "&Method Manager"
#define xx_FormMethods   "&Method Manager"
#define en__FormMethods   ""
#define fr__FormMethods   ""
#define it__FormMethods   ""
#define es__FormMethods   ""
#define de__FormMethods   ""
#define nl__FormMethods   ""
#define pt__FormMethods   ""
#define xx__FormMethods   ""
#define en_Methods   "Return|Name|Parameters"
#define fr_Methods   "Retour|Nom|ParamŠtres"
#define it_Methods   "Return|Name|Parameters"
#define es_Methods   "Return|Name|Parameters"
#define de_Methods   "Return|Name|Parameter"
#define nl_Methods   "Return|Name|Parameters"
#define pt_Methods   "Return|Name|Parameters"
#define xx_Methods   "Return|Name|Parameters"
#define en__Methods   ""
#define fr__Methods   ""
#define it__Methods   ""
#define es__Methods   ""
#define de__Methods   ""
#define nl__Methods   ""
#define pt__Methods   ""
#define xx__Methods   ""
#define en_Cursor   ""
#define fr_Cursor   ""
#define it_Cursor   ""
#define es_Cursor   ""
#define de_Cursor   ""
#define nl_Cursor   ""
#define pt_Cursor   ""
#define xx_Cursor   ""
#define fr__Cursor   ""
#define en_EditMethod   "&Edit Method"
#define fr_EditMethod   "&Editer m‚thode"
#define it_EditMethod   "&Edit Method"
#define es_EditMethod   "&Edit Method"
#define de_EditMethod   "Method Editor"
#define nl_EditMethod   "&Edit Method"
#define pt_EditMethod   "&Edit Method"
#define xx_EditMethod   "&Edit Method"
#define en__EditMethod   ""
#define fr__EditMethod   ""
#define it__EditMethod   ""
#define es__EditMethod   ""
#define de__EditMethod   ""
#define nl__EditMethod   ""
#define pt__EditMethod   ""
#define xx__EditMethod   ""
#define en_PasteMethod   "&Paste Method"
#define fr_PasteMethod   "C&oller methode"
#define it_PasteMethod   "&Paste Method"
#define es_PasteMethod   "&Paste Method"
#define de_PasteMethod   "&Paste Method"
#define nl_PasteMethod   "&Paste Method"
#define pt_PasteMethod   "&Paste Method"
#define xx_PasteMethod   "&Paste Method"
#define en__PasteMethod   ""
#define fr__PasteMethod   ""
#define it__PasteMethod   ""
#define es__PasteMethod   ""
#define de__PasteMethod   ""
#define nl__PasteMethod   ""
#define pt__PasteMethod   ""
#define xx__PasteMethod   ""
#define en_CopyMethod   "&Copy Method"
#define fr_CopyMethod   "&Copier m‚thode"
#define it_CopyMethod   "&Copy Method"
#define es_CopyMethod   "&Copy Method"
#define de_CopyMethod   "&Copy Method"
#define nl_CopyMethod   "&Copy Method"
#define pt_CopyMethod   "&Copy Method"
#define xx_CopyMethod   "&Copy Method"
#define en__CopyMethod   ""
#define fr__CopyMethod   ""
#define it__CopyMethod   ""
#define es__CopyMethod   ""
#define de__CopyMethod   ""
#define nl__CopyMethod   ""
#define pt__CopyMethod   ""
#define xx__CopyMethod   ""
#define en_DropMethod   "&Drop Method"
#define fr_DropMethod   "&Effacer m‚thode"
#define it_DropMethod   "&Drop Method"
#define es_DropMethod   "&Drop Method"
#define de_DropMethod   "&Drop Method"
#define nl_DropMethod   "&Drop Method"
#define pt_DropMethod   "&Drop Method"
#define xx_DropMethod   "&Drop Method"
#define en__DropMethod   ""
#define fr__DropMethod   ""
#define it__DropMethod   ""
#define es__DropMethod   ""
#define de__DropMethod   ""
#define nl__DropMethod   ""
#define pt__DropMethod   ""
#define xx__DropMethod   ""
#define en_ScrollBar   ""
#define fr_ScrollBar   ""
#define it_ScrollBar   ""
#define es_ScrollBar   ""
#define de_ScrollBar   ""
#define nl_ScrollBar   ""
#define pt_ScrollBar   ""
#define xx_ScrollBar   ""
#define en_FormMemberPage   "&Member Manager"
#define fr_FormMemberPage   "Mem&bres"
#define it_FormMemberPage   "&Member Manager"
#define es_FormMemberPage   "&Member Manager"
#define de_FormMemberPage   "&Member Manager"
#define nl_FormMemberPage   "&Member Manager"
#define pt_FormMemberPage   "&Member Manager"
#define xx_FormMemberPage   "&Member Manager"
#define en__FormMemberPage   ""
#define fr__FormMemberPage   ""
#define it__FormMemberPage   ""
#define es__FormMemberPage   ""
#define de__FormMemberPage   ""
#define nl__FormMemberPage   ""
#define pt__FormMemberPage   ""
#define xx__FormMemberPage   ""
#define en_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define fr_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define it_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define es_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define de_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define nl_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define pt_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define xx_TypeSelect   "int8#|int16|bcd|string|int32|field|filler"
#define en__TypeSelect   ""
#define fr__TypeSelect   ""
#define it__TypeSelect   ""
#define es__TypeSelect   ""
#define de__TypeSelect   ""
#define nl__TypeSelect   ""
#define pt__TypeSelect   ""
#define xx__TypeSelect   ""
#define en_PtrCheck   "Dcl|Ptr|Const"
#define fr_PtrCheck   "Dcl|Ptr|Const"
#define it_PtrCheck   "Dcl|Ptr|Const"
#define es_PtrCheck   "Dcl|Ptr|Const"
#define de_PtrCheck   "Dcl|Ptr|Const"
#define nl_PtrCheck   "Dcl|Ptr|Const"
#define pt_PtrCheck   "Dcl|Ptr|Const"
#define xx_PtrCheck   "Dcl|Ptr|Const"
#define en__PtrCheck   ""
#define fr__PtrCheck   ""
#define it__PtrCheck   ""
#define es__PtrCheck   ""
#define de__PtrCheck   ""
#define nl__PtrCheck   ""
#define pt__PtrCheck   ""
#define xx__PtrCheck   ""
#define en_FormMembers   "Name|Ptr|Type|Size|1st|2nd|Comment/Constant Value"
#define fr_FormMembers   "Nom|Dcl|Type|Taille|1ere|2eme|Commentaire / Valeur constante"
#define it_FormMembers   "Name|Ptr|Type|Size|1st|2nd|Comment/Constant Value"
#define es_FormMembers   "Name|Ptr|Type|Size|1st|2nd|Comment/Constant Value"
#define de_FormMembers   "Name|Ptr|Type|Size|1st|2nd|Comment/Constant Value"
#define nl_FormMembers   "Name|Ptr|Type|Size|1st|2nd|Comment/Constant Value"
#define pt_FormMembers   "Name|Ptr|Type|Size|1st|2nd|Comment/Constant Value"
#define xx_FormMembers   "Name|Ptr|Type|Size|1st|2nd|Comment/Constant Value"
#define en__FormMembers   ""
#define fr__FormMembers   ""
#define it__FormMembers   ""
#define es__FormMembers   ""
#define de__FormMembers   ""
#define nl__FormMembers   ""
#define pt__FormMembers   ""
#define xx__FormMembers   ""
#define en_Kursor   ""
#define fr_Kursor   ""
#define it_Kursor   ""
#define es_Kursor   ""
#define de_Kursor   ""
#define nl_Kursor   ""
#define pt_Kursor   ""
#define xx_Kursor   ""
#define fr__Kursor   ""
#define en_MemberBar   ""
#define fr_MemberBar   ""
#define it_MemberBar   ""
#define es_MemberBar   ""
#define de_MemberBar   ""
#define nl_MemberBar   ""
#define pt_MemberBar   ""
#define xx_MemberBar   ""

private struct accept_form_control_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[4+1];
	char * msg_Auto3559[8];
	char * hint_Auto3559[8];
	int	x_Auto3559;
	int	y_Auto3559;
	int	w_Auto3559;
	int	h_Auto3559;
	char * msg_Auto3560[8];
	char * hint_Auto3560[8];
	char * msg_FormControl[8];
	int	trigger_FormControl;
	char * hint_FormControl[8];
	int	s_FormControl;
	void *	p_FormControl;
	int	page_number;
	char * msg_Auto3561[8];
	char * hint_Auto3561[8];
	char * hint_Auto3562[8];
	char * msg_Auto3563[8];
	char * hint_Auto3563[8];
	char * msg_Auto3564[8];
	char * hint_Auto3564[8];
	char * msg_Auto3565[8];
	char * hint_Auto3565[8];
	char * msg_Auto3566[8];
	char * hint_Auto3566[8];
	char * msg_Auto3567[8];
	char * hint_Auto3567[8];
	char * msg_Auto3568[8];
	int	trigger_Auto3568;
	char * hint_Auto3568[8];
	char * msg_Auto3569[8];
	int	trigger_Auto3569;
	char * hint_Auto3569[8];
	char * msg_Auto3570[8];
	char * hint_Auto3570[8];
	char * msg_Auto3571[8];
	char * hint_Auto3571[8];
	char * msg_Auto3572[8];
	char * hint_Auto3572[8];
	char * msg_FormType[8];
	char * hint_FormType[8];
	int	s_FormType;
	void *	p_FormType;
	int	value_FormType;
	char * msg_ProductionLanguage[8];
	char * hint_ProductionLanguage[8];
	int	s_ProductionLanguage;
	void *	p_ProductionLanguage;
	int	value_ProductionLanguage;
	char * msg_NationalLanguage[8];
	char * hint_NationalLanguage[8];
	int	value_NationalLanguage;
	char * msg_International[8];
	int	trigger_International;
	char * hint_International[8];
	int	value_International;
	char * msg_Constants[8];
	int	trigger_Constants;
	char * hint_Constants[8];
	int	value_Constants;
	char * msg_MultipleLanguage[8];
	int	trigger_MultipleLanguage;
	char * hint_MultipleLanguage[8];
	int	value_MultipleLanguage;
	char * msg_Program[8];
	int	trigger_Program;
	char * hint_Program[8];
	int	s_Program;
	void *	p_Program;
	int	value_Program;
	char * msg_Overlay[8];
	int	trigger_Overlay;
	char * hint_Overlay[8];
	int	s_Overlay;
	void *	p_Overlay;
	int	value_Overlay;
	char * msg_PopUp[8];
	int	trigger_PopUp;
	char * hint_PopUp[8];
	int	value_PopUp;
	char * msg_Dynamic[8];
	int	trigger_Dynamic;
	char * hint_Dynamic[8];
	int	value_Dynamic;
	char * msg_CommandLine[8];
	int	trigger_CommandLine;
	char * hint_CommandLine[8];
	int	value_CommandLine;
	char * hint_ArgVLen[8];
	char	buffer_ArgVLen[13];
	char * hint_ArgVNb[8];
	char	buffer_ArgVNb[14];
	char * msg_Resize[8];
	int	trigger_Resize;
	char * hint_Resize[8];
	int	value_Resize;
	char * hint_ResizeX[8];
	char	buffer_ResizeX[10];
	char * hint_ResizeY[8];
	char	buffer_ResizeY[10];
	char * msg_GenHelp[8];
	char * hint_GenHelp[8];
	int	value_GenHelp;
	char * msg_ActHelp[8];
	char * hint_ActHelp[8];
	int	value_ActHelp;
	char * msg_Auto3573[8];
	char * hint_Auto3573[8];
	char * msg_auto7[8];
	char * hint_auto7[8];
	char * msg_auto52[8];
	char * hint_auto52[8];
	char * msg_Auto3574[8];
	char * hint_Auto3574[8];
	char * msg_Auto3575[8];
	char * hint_Auto3575[8];
	char * hint_FileName[8];
	char	buffer_FileName[256];
	char * msg_ChooseFileName[8];
	int	trigger_ChooseFileName;
	char * hint_ChooseFileName[8];
	char * msg_ChooseStyleName[8];
	int	trigger_ChooseStyleName;
	char * hint_ChooseStyleName[8];
	char * msg_EditSource[8];
	int	trigger_EditSource;
	char * hint_EditSource[8];
	char * msg_EditStyle[8];
	int	trigger_EditStyle;
	char * hint_EditStyle[8];
	char * hint_Identity[8];
	char	buffer_Identity[256];
	char * hint_StyleSheet[8];
	char	buffer_StyleSheet[256];
	char * msg_Auto3576[8];
	char * hint_Auto3576[8];
	char * msg_ChoosePalette[8];
	int	trigger_ChoosePalette;
	char * hint_ChoosePalette[8];
	char * hint_PaletteName[8];
	char	buffer_PaletteName[256];
	char * hint_ClearScreen[8];
	char	buffer_ClearScreen[256];
	char * msg_MouseEvents[8];
	int	trigger_MouseEvents;
	char * hint_MouseEvents[8];
	char * msg_Auto3577[8];
	char * hint_Auto3577[8];
	char * msg_Auto3578[8];
	char * hint_Auto3578[8];
	char * msg_Auto3579[8];
	char * hint_Auto3579[8];
	char * msg_SendLeft[8];
	int	trigger_SendLeft;
	char * hint_SendLeft[8];
	int	value_SendLeft;
	char * msg_SendMiddle[8];
	int	trigger_SendMiddle;
	char * hint_SendMiddle[8];
	int	value_SendMiddle;
	char * msg_SendRight[8];
	int	trigger_SendRight;
	char * hint_SendRight[8];
	int	value_SendRight;
	char * msg_SendWheel[8];
	int	trigger_SendWheel;
	char * hint_SendWheel[8];
	int	value_SendWheel;
	char * msg_ButtonFilter[8];
	int	trigger_ButtonFilter;
	char * hint_ButtonFilter[8];
	int	value_ButtonFilter;
	char * msg_SendDown[8];
	int	trigger_SendDown;
	char * hint_SendDown[8];
	int	value_SendDown;
	char * msg_SendUp[8];
	int	trigger_SendUp;
	char * hint_SendUp[8];
	int	value_SendUp;
	char * msg_SendWhileDown[8];
	int	trigger_SendWhileDown;
	char * hint_SendWhileDown[8];
	int	value_SendWhileDown;
	char * msg_SendMove[8];
	int	trigger_SendMove;
	char * hint_SendMove[8];
	int	value_SendMove;
	char * msg_MouseKey[8];
	int	trigger_MouseKey;
	char * hint_MouseKey[8];
	int	value_MouseKey;
	char * msg_WidgetTriggers[8];
	int	trigger_WidgetTriggers;
	char * hint_WidgetTriggers[8];
	int	value_WidgetTriggers;
	char * msg_Escape[8];
	int	trigger_Escape;
	char * hint_Escape[8];
	int	s_Escape;
	void *	p_Escape;
	int	value_Escape;
	char * msg_Enter[8];
	int	trigger_Enter;
	char * hint_Enter[8];
	int	s_Enter;
	void *	p_Enter;
	int	value_Enter;
	char * msg_PageUp[8];
	int	trigger_PageUp;
	char * hint_PageUp[8];
	int	s_PageUp;
	void *	p_PageUp;
	int	value_PageUp;
	char * msg_PageDown[8];
	int	trigger_PageDown;
	char * hint_PageDown[8];
	int	s_PageDown;
	void *	p_PageDown;
	int	value_PageDown;
	char * msg_UpArrow[8];
	int	trigger_UpArrow;
	char * hint_UpArrow[8];
	int	s_UpArrow;
	void *	p_UpArrow;
	int	value_UpArrow;
	char * msg_DownArrow[8];
	int	trigger_DownArrow;
	char * hint_DownArrow[8];
	int	s_DownArrow;
	void *	p_DownArrow;
	int	value_DownArrow;
	char * msg_Tabulation[8];
	int	trigger_Tabulation;
	char * hint_Tabulation[8];
	int	s_Tabulation;
	void *	p_Tabulation;
	int	value_Tabulation;
	char * msg_DefaultBreak[8];
	int	trigger_DefaultBreak;
	char * hint_DefaultBreak[8];
	int	s_DefaultBreak;
	void *	p_DefaultBreak;
	int	value_DefaultBreak;
	char * msg_FormMethods[8];
	int	trigger_FormMethods;
	char * hint_FormMethods[8];
	char * msg_Methods[8];
	char * hint_Methods[8];
	int	value_Methods;
	int	column_Methods;
	char	buffer_Methods[25][88];
	int	formsort_Methods;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_Methods;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_Methods;	/* numéro d'ordre des elements triés */
	char	*indsort_Methods;	/* pointeur table intermédiaire de tri */
	int	nelt_Methods;	/* nombre d'eléments aloués dans tabsort */
	char * row_Methods;
	char * hint_Cursor[8];
	int	x_Cursor;
	int	y_Cursor;
	int	w_Cursor;
	int	h_Cursor;
	int	fg_Cursor;
	int	bg_Cursor;
	int	fid_Cursor;
	char * msg_EditMethod[8];
	int	trigger_EditMethod;
	char * hint_EditMethod[8];
	char * msg_PasteMethod[8];
	int	trigger_PasteMethod;
	char * hint_PasteMethod[8];
	int	s_PasteMethod;
	void *	p_PasteMethod;
	char * msg_CopyMethod[8];
	int	trigger_CopyMethod;
	char * hint_CopyMethod[8];
	char * msg_DropMethod[8];
	int	trigger_DropMethod;
	char * hint_DropMethod[8];
	char * hint_ScrollBar[8];
	int	value_ScrollBar;
	int	limit_ScrollBar;
	int	max_ScrollBar;
	char * msg_FormMemberPage[8];
	int	trigger_FormMemberPage;
	char * hint_FormMemberPage[8];
	char * msg_TypeSelect[8];
	char * hint_TypeSelect[8];
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
	char * msg_PtrCheck[8];
	char * hint_PtrCheck[8];
	int	x_PtrCheck;
	int	y_PtrCheck;
	int	w_PtrCheck;
	int	h_PtrCheck;
	int	fg_PtrCheck;
	int	bg_PtrCheck;
	int	fid_PtrCheck;
	int	value_PtrCheck;
	char * msg_FormMembers[8];
	char * hint_FormMembers[8];
	int	value_FormMembers;
	int	column_FormMembers;
	char	buffer_FormMembers[27][88];
	int	formsort_FormMembers;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_FormMembers;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_FormMembers;	/* numéro d'ordre des elements triés */
	char	*indsort_FormMembers;	/* pointeur table intermédiaire de tri */
	int	nelt_FormMembers;	/* nombre d'eléments aloués dans tabsort */
	char * row_FormMembers;
	char * hint_Kursor[8];
	int	x_Kursor;
	int	y_Kursor;
	int	w_Kursor;
	int	h_Kursor;
	int	fg_Kursor;
	int	bg_Kursor;
	int	fid_Kursor;
	char * hint_MemberBar[8];
	int	value_MemberBar;
	int	limit_MemberBar;
	int	max_MemberBar;
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[43];
	};
static int	vfh[16];
private int on_Methods_show(struct accept_form_control_context * _Context);
private int on_PasteMethod_show(struct accept_form_control_context * _Context);
private int on_ScrollBar_show(struct accept_form_control_context * _Context);
private int on_FormMembers_show(struct accept_form_control_context * _Context);
private int on_MemberBar_show(struct accept_form_control_context * _Context);
private int on_FormMembers_getfocus(struct accept_form_control_context * _Context);
private int on_FormMembers_losefocus(struct accept_form_control_context * _Context);
private int on_Auto3568_event(struct accept_form_control_context * _Context);
private int on_Auto3569_event(struct accept_form_control_context * _Context);
private int on_ChooseFileName_event(struct accept_form_control_context * _Context);
private int on_ChooseStyleName_event(struct accept_form_control_context * _Context);
private int on_EditSource_event(struct accept_form_control_context * _Context);
private int on_EditStyle_event(struct accept_form_control_context * _Context);
private int on_ChoosePalette_event(struct accept_form_control_context * _Context);
private int on_Methods_event(struct accept_form_control_context * _Context);
private int on_EditMethod_event(struct accept_form_control_context * _Context);
private int on_PasteMethod_event(struct accept_form_control_context * _Context);
private int on_CopyMethod_event(struct accept_form_control_context * _Context);
private int on_DropMethod_event(struct accept_form_control_context * _Context);
private int on_ScrollBar_event(struct accept_form_control_context * _Context);
private int on_FormMembers_event(struct accept_form_control_context * _Context);
private int on_MemberBar_event(struct accept_form_control_context * _Context);
static void	putstring(struct accept_form_control_context * _Context,char * rptr, int rlen, char * sptr);
private int  sort_item_Methods(struct accept_form_control_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_Methods(struct accept_form_control_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_Methods(struct accept_form_control_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_Methods */
private int compare_Methods(struct accept_form_control_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_Methods */
private int  sort_item_FormMembers(struct accept_form_control_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_FormMembers(struct accept_form_control_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_FormMembers(struct accept_form_control_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_FormMembers */
private int compare_FormMembers(struct accept_form_control_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_FormMembers */

/*	--------------------	*/
/*	p u t s t r i n g ()	*/
/*	--------------------	*/
static void	putstring(struct accept_form_control_context * _Context,char * rptr, int rlen, char * sptr){
	int i;
	for(i=0;i<rlen;i++){
	if(!(*(sptr+i)))
	break;
	else*(rptr+i)=*(sptr+i);
	}
	for(;i<rlen;i++){*(rptr+i)=' ';}
	return;

}
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_Methods(struct accept_form_control_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_Methods[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_Methods(struct accept_form_control_context * _Context,int nelts)
{
if (_Context->nelt_Methods<nelts) {
	liberate(_Context->tabsort_Methods);
	if ((_Context->tabsort_Methods=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_Methods=0;_Context->nelt_Methods<nelts;_Context->nelt_Methods++)
		{ _Context->tabsort_Methods[_Context->nelt_Methods]=_Context->nelt_Methods+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_Methods=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_Methods=allocate(nelts*88)) != NULL)
	memset(_Context->libsort_Methods,' ',nelts*88);
}

/* ---------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_Methods */
/* ---------------------------------------------------------- */
private void sort_Methods(struct accept_form_control_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_Methods,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_Methods[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_Methods[j]) && (compare_Methods(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_Methods[i]=k+1;
	_Context->indsort_Methods[k]=1;
	};	/* for i */
liberate(_Context->libsort_Methods);
liberate(_Context->indsort_Methods);
}

/* -------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_Methods */
/* -------------------------------------------------------- */
private int compare_Methods(struct accept_form_control_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_Methods[88*a],&_Context->libsort_Methods[88*b],17);	/* comparaison zone 1 */
switch (_Context->formsort_Methods) {
	case 1:	/* Return ordre normal */
		return(i);

	case -1:	/* Return ordre inverse */
		return(-i);

	case 2:	/* Name ordre normal */
		j=memicmp(&_Context->libsort_Methods[88*a+17],&_Context->libsort_Methods[88*b+17],33);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Name ordre inverse */
		j=memicmp(&_Context->libsort_Methods[88*b+17],&_Context->libsort_Methods[88*a+17],33);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Parameters ordre normal */
		j=memicmp(&_Context->libsort_Methods[88*a+50],&_Context->libsort_Methods[88*b+50],38);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Parameters ordre inverse */
		j=memicmp(&_Context->libsort_Methods[88*b+50],&_Context->libsort_Methods[88*a+50],38);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_FormMembers(struct accept_form_control_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_FormMembers[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_FormMembers(struct accept_form_control_context * _Context,int nelts)
{
if (_Context->nelt_FormMembers<nelts) {
	liberate(_Context->tabsort_FormMembers);
	if ((_Context->tabsort_FormMembers=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_FormMembers=0;_Context->nelt_FormMembers<nelts;_Context->nelt_FormMembers++)
		{ _Context->tabsort_FormMembers[_Context->nelt_FormMembers]=_Context->nelt_FormMembers+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_FormMembers=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_FormMembers=allocate(nelts*88)) != NULL)
	memset(_Context->libsort_FormMembers,' ',nelts*88);
}

/* -------------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_FormMembers */
/* -------------------------------------------------------------- */
private void sort_FormMembers(struct accept_form_control_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_FormMembers,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_FormMembers[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_FormMembers[j]) && (compare_FormMembers(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_FormMembers[i]=k+1;
	_Context->indsort_FormMembers[k]=1;
	};	/* for i */
liberate(_Context->libsort_FormMembers);
liberate(_Context->indsort_FormMembers);
}

/* ------------------------------------------------------------ */
/* compare the elements a et b of _Context->libsort_FormMembers */
/* ------------------------------------------------------------ */
private int compare_FormMembers(struct accept_form_control_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_FormMembers[88*a],&_Context->libsort_FormMembers[88*b],24);	/* comparaison zone 1 */
switch (_Context->formsort_FormMembers) {
	case 1:	/* Name ordre normal */
		return(i);

	case -1:	/* Name ordre inverse */
		return(-i);

	case 2:	/* Ptr ordre normal */
		j=memicmp(&_Context->libsort_FormMembers[88*a+24],&_Context->libsort_FormMembers[88*b+24],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Ptr ordre inverse */
		j=memicmp(&_Context->libsort_FormMembers[88*b+24],&_Context->libsort_FormMembers[88*a+24],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Type ordre normal */
		j=memicmp(&_Context->libsort_FormMembers[88*a+30],&_Context->libsort_FormMembers[88*b+30],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Type ordre inverse */
		j=memicmp(&_Context->libsort_FormMembers[88*b+30],&_Context->libsort_FormMembers[88*a+30],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* Size ordre normal */
		j=memicmp(&_Context->libsort_FormMembers[88*a+39],&_Context->libsort_FormMembers[88*b+39],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* Size ordre inverse */
		j=memicmp(&_Context->libsort_FormMembers[88*b+39],&_Context->libsort_FormMembers[88*a+39],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 5:	/* 1st ordre normal */
		j=memicmp(&_Context->libsort_FormMembers[88*a+45],&_Context->libsort_FormMembers[88*b+45],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -5:	/* 1st ordre inverse */
		j=memicmp(&_Context->libsort_FormMembers[88*b+45],&_Context->libsort_FormMembers[88*a+45],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 6:	/* 2nd ordre normal */
		j=memicmp(&_Context->libsort_FormMembers[88*a+51],&_Context->libsort_FormMembers[88*b+51],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -6:	/* 2nd ordre inverse */
		j=memicmp(&_Context->libsort_FormMembers[88*b+51],&_Context->libsort_FormMembers[88*a+51],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 7:	/* Comment/Constant Value ordre normal */
		j=memicmp(&_Context->libsort_FormMembers[88*a+57],&_Context->libsort_FormMembers[88*b+57],31);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -7:	/* Comment/Constant Value ordre inverse */
		j=memicmp(&_Context->libsort_FormMembers[88*b+57],&_Context->libsort_FormMembers[88*a+57],31);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}


public	int	accept_form_control_create(
	struct accept_form_control_context ** cptr,
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pConstants,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pDynamic,
	char * pCommandLine,
	char * pArgVLen,
	char * pArgVNb,
	char * pResize,
	char * pResizeX,
	char * pResizeY,
	char * pGenHelp,
	char * pActHelp,
	char * pFileName,
	char * pIdentity,
	char * pStyleSheet,
	char * pPaletteName,
	char * pClearScreen,
	char * pSendLeft,
	char * pSendMiddle,
	char * pSendRight,
	char * pSendWheel,
	char * pButtonFilter,
	char * pSendDown,
	char * pSendUp,
	char * pSendWhileDown,
	char * pSendMove,
	char * pMouseKey,
	char * pWidgetTriggers,
	char * pEscape,
	char * pEnter,
	char * pPageUp,
	char * pPageDown,
	char * pUpArrow,
	char * pDownArrow,
	char * pTabulation,
	char * pDefaultBreak)
{

	int i;
	struct accept_form_control_context * _Context=(struct accept_form_control_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_form_control_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=64;
	_Context->page_number=1;
	_Context->formsort_Methods=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_Methods=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_Methods=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_Methods=0;_Context->nelt_Methods<512;_Context->nelt_Methods++)
			{ _Context->tabsort_Methods[_Context->nelt_Methods]=_Context->nelt_Methods+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_Methods=0; /* si problème d'allocation */
_Context->indsort_Methods=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_ScrollBar=0;
		_Context->limit_ScrollBar=0;
		_Context->value_ScrollBar=0;
		_Context->value_TypeSelect=0;
		_Context->value_PtrCheck=0;
	_Context->formsort_FormMembers=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_FormMembers=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_FormMembers=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_FormMembers=0;_Context->nelt_FormMembers<512;_Context->nelt_FormMembers++)
			{ _Context->tabsort_FormMembers[_Context->nelt_FormMembers]=_Context->nelt_FormMembers+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_FormMembers=0; /* si problème d'allocation */
_Context->indsort_FormMembers=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_MemberBar=0;
		_Context->limit_MemberBar=0;
		_Context->value_MemberBar=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWWWWWWWWWSSSSSWWWWWWWWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pFormType);
		if (!( pFormType )) _Context->value_FormType=0;
		else	_Context->value_FormType = *((int *)pFormType);
		visual_transferin((void *) 0, 0, pProductionLanguage);
		if (!( pProductionLanguage )) _Context->value_ProductionLanguage=0;
		else	_Context->value_ProductionLanguage = *((int *)pProductionLanguage);
		visual_transferin((void *) 0, 0, pNationalLanguage);
		if (!( pNationalLanguage )) _Context->value_NationalLanguage=0;
		else	_Context->value_NationalLanguage = *((int *)pNationalLanguage);
		visual_transferin((void *) 0, 0, pInternational);
		if (!( pInternational )) _Context->value_International=0;
		else	_Context->value_International = *((int *)pInternational);
		visual_transferin((void *) 0, 0, pConstants);
		if (!( pConstants )) _Context->value_Constants=0;
		else	_Context->value_Constants = *((int *)pConstants);
		visual_transferin((void *) 0, 0, pMultipleLanguage);
		if (!( pMultipleLanguage )) _Context->value_MultipleLanguage=0;
		else	_Context->value_MultipleLanguage = *((int *)pMultipleLanguage);
		visual_transferin((void *) 0, 0, pProgram);
		if (!( pProgram )) _Context->value_Program=0;
		else	_Context->value_Program = *((int *)pProgram);
		visual_transferin((void *) 0, 0, pOverlay);
		if (!( pOverlay )) _Context->value_Overlay=0;
		else	_Context->value_Overlay = *((int *)pOverlay);
		visual_transferin((void *) 0, 0, pPopUp);
		if (!( pPopUp )) _Context->value_PopUp=0;
		else	_Context->value_PopUp = *((int *)pPopUp);
		visual_transferin((void *) 0, 0, pDynamic);
		if (!( pDynamic )) _Context->value_Dynamic=0;
		else	_Context->value_Dynamic = *((int *)pDynamic);
		visual_transferin((void *) 0, 0, pCommandLine);
		if (!( pCommandLine )) _Context->value_CommandLine=0;
		else	_Context->value_CommandLine = *((int *)pCommandLine);
		visual_transferin(_Context->buffer_ArgVLen, 12, pArgVLen);
		visual_transferin(_Context->buffer_ArgVNb, 13, pArgVNb);
		visual_transferin((void *) 0, 0, pResize);
		if (!( pResize )) _Context->value_Resize=0;
		else	_Context->value_Resize = *((int *)pResize);
		visual_transferin(_Context->buffer_ResizeX, 9, pResizeX);
		visual_transferin(_Context->buffer_ResizeY, 9, pResizeY);
		visual_transferin((void *) 0, 0, pGenHelp);
		if (!( pGenHelp )) _Context->value_GenHelp=0;
		else	_Context->value_GenHelp = *((int *)pGenHelp);
		visual_transferin((void *) 0, 0, pActHelp);
		if (!( pActHelp )) _Context->value_ActHelp=0;
		else	_Context->value_ActHelp = *((int *)pActHelp);
		visual_transferin(_Context->buffer_FileName, 255, pFileName);
		visual_transferin(_Context->buffer_Identity, 255, pIdentity);
		visual_transferin(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferin(_Context->buffer_PaletteName, 255, pPaletteName);
		visual_transferin(_Context->buffer_ClearScreen, 255, pClearScreen);
		visual_transferin((void *) 0, 0, pSendLeft);
		if (!( pSendLeft )) _Context->value_SendLeft=0;
		else	_Context->value_SendLeft = *((int *)pSendLeft);
		visual_transferin((void *) 0, 0, pSendMiddle);
		if (!( pSendMiddle )) _Context->value_SendMiddle=0;
		else	_Context->value_SendMiddle = *((int *)pSendMiddle);
		visual_transferin((void *) 0, 0, pSendRight);
		if (!( pSendRight )) _Context->value_SendRight=0;
		else	_Context->value_SendRight = *((int *)pSendRight);
		visual_transferin((void *) 0, 0, pSendWheel);
		if (!( pSendWheel )) _Context->value_SendWheel=0;
		else	_Context->value_SendWheel = *((int *)pSendWheel);
		visual_transferin((void *) 0, 0, pButtonFilter);
		if (!( pButtonFilter )) _Context->value_ButtonFilter=0;
		else	_Context->value_ButtonFilter = *((int *)pButtonFilter);
		visual_transferin((void *) 0, 0, pSendDown);
		if (!( pSendDown )) _Context->value_SendDown=0;
		else	_Context->value_SendDown = *((int *)pSendDown);
		visual_transferin((void *) 0, 0, pSendUp);
		if (!( pSendUp )) _Context->value_SendUp=0;
		else	_Context->value_SendUp = *((int *)pSendUp);
		visual_transferin((void *) 0, 0, pSendWhileDown);
		if (!( pSendWhileDown )) _Context->value_SendWhileDown=0;
		else	_Context->value_SendWhileDown = *((int *)pSendWhileDown);
		visual_transferin((void *) 0, 0, pSendMove);
		if (!( pSendMove )) _Context->value_SendMove=0;
		else	_Context->value_SendMove = *((int *)pSendMove);
		visual_transferin((void *) 0, 0, pMouseKey);
		if (!( pMouseKey )) _Context->value_MouseKey=0;
		else	_Context->value_MouseKey = *((int *)pMouseKey);
		visual_transferin((void *) 0, 0, pWidgetTriggers);
		if (!( pWidgetTriggers )) _Context->value_WidgetTriggers=0;
		else	_Context->value_WidgetTriggers = *((int *)pWidgetTriggers);
		visual_transferin((void *) 0, 0, pEscape);
		if (!( pEscape )) _Context->value_Escape=0;
		else	_Context->value_Escape = *((int *)pEscape);
		visual_transferin((void *) 0, 0, pEnter);
		if (!( pEnter )) _Context->value_Enter=0;
		else	_Context->value_Enter = *((int *)pEnter);
		visual_transferin((void *) 0, 0, pPageUp);
		if (!( pPageUp )) _Context->value_PageUp=0;
		else	_Context->value_PageUp = *((int *)pPageUp);
		visual_transferin((void *) 0, 0, pPageDown);
		if (!( pPageDown )) _Context->value_PageDown=0;
		else	_Context->value_PageDown = *((int *)pPageDown);
		visual_transferin((void *) 0, 0, pUpArrow);
		if (!( pUpArrow )) _Context->value_UpArrow=0;
		else	_Context->value_UpArrow = *((int *)pUpArrow);
		visual_transferin((void *) 0, 0, pDownArrow);
		if (!( pDownArrow )) _Context->value_DownArrow=0;
		else	_Context->value_DownArrow = *((int *)pDownArrow);
		visual_transferin((void *) 0, 0, pTabulation);
		if (!( pTabulation )) _Context->value_Tabulation=0;
		else	_Context->value_Tabulation = *((int *)pTabulation);
		visual_transferin((void *) 0, 0, pDefaultBreak);
		if (!( pDefaultBreak )) _Context->value_DefaultBreak=0;
		else	_Context->value_DefaultBreak = *((int *)pDefaultBreak);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3559[i]=" ";
	_Context->hint_Auto3559[0]=en__Auto3559;
	_Context->hint_Auto3559[1]=fr__Auto3559;
	_Context->hint_Auto3559[2]=it__Auto3559;
	_Context->hint_Auto3559[3]=es__Auto3559;
	_Context->hint_Auto3559[4]=de__Auto3559;
	_Context->hint_Auto3559[5]=nl__Auto3559;
	_Context->hint_Auto3559[6]=pt__Auto3559;
	_Context->hint_Auto3559[7]=xx__Auto3559;
	_Context->x_Auto3559=5;
	_Context->y_Auto3559=0;
	_Context->w_Auto3559=790;
	_Context->h_Auto3559=600;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3560[i]=" ";
	_Context->msg_Auto3560[0]=en_Auto3560;
	_Context->msg_Auto3560[1]=fr_Auto3560;
	_Context->msg_Auto3560[2]=it_Auto3560;
	_Context->msg_Auto3560[3]=es_Auto3560;
	_Context->msg_Auto3560[4]=de_Auto3560;
	_Context->msg_Auto3560[5]=nl_Auto3560;
	_Context->msg_Auto3560[6]=pt_Auto3560;
	_Context->msg_Auto3560[7]=xx_Auto3560;
	_Context->hint_Auto3560[1]=fr__Auto3560;
	for (i=0; i < 8; i++)_Context->msg_FormControl[i]=" ";
	_Context->msg_FormControl[0]=en_FormControl;
	_Context->msg_FormControl[1]=fr_FormControl;
	_Context->msg_FormControl[2]=it_FormControl;
	_Context->msg_FormControl[3]=es_FormControl;
	_Context->msg_FormControl[4]=de_FormControl;
	_Context->msg_FormControl[5]=nl_FormControl;
	_Context->msg_FormControl[6]=pt_FormControl;
	_Context->msg_FormControl[7]=xx_FormControl;
	_Context->hint_FormControl[0]=en__FormControl;
	_Context->hint_FormControl[1]=fr__FormControl;
	_Context->hint_FormControl[2]=it__FormControl;
	_Context->hint_FormControl[3]=es__FormControl;
	_Context->hint_FormControl[4]=de__FormControl;
	_Context->hint_FormControl[5]=nl__FormControl;
	_Context->hint_FormControl[6]=pt__FormControl;
	_Context->hint_FormControl[7]=xx__FormControl;
	_Context->s_FormControl=0;
	_Context->p_FormControl=visual_buffer(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770+2,500+2);
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto3561[i]=" ";
	_Context->msg_Auto3561[0]=en_Auto3561;
	_Context->msg_Auto3561[1]=fr_Auto3561;
	_Context->msg_Auto3561[2]=it_Auto3561;
	_Context->msg_Auto3561[3]=es_Auto3561;
	_Context->msg_Auto3561[4]=de_Auto3561;
	_Context->msg_Auto3561[5]=nl_Auto3561;
	_Context->msg_Auto3561[6]=pt_Auto3561;
	_Context->msg_Auto3561[7]=xx_Auto3561;
	_Context->hint_Auto3561[0]=en__Auto3561;
	_Context->hint_Auto3561[1]=fr__Auto3561;
	_Context->hint_Auto3561[2]=it__Auto3561;
	_Context->hint_Auto3561[3]=es__Auto3561;
	_Context->hint_Auto3561[4]=de__Auto3561;
	_Context->hint_Auto3561[5]=nl__Auto3561;
	_Context->hint_Auto3561[6]=pt__Auto3561;
	_Context->hint_Auto3561[7]=xx__Auto3561;
	for (i=0; i < 8; i++)_Context->msg_Auto3563[i]=" ";
	_Context->msg_Auto3563[0]=en_Auto3563;
	_Context->msg_Auto3563[1]=fr_Auto3563;
	_Context->msg_Auto3563[2]=it_Auto3563;
	_Context->msg_Auto3563[3]=es_Auto3563;
	_Context->msg_Auto3563[4]=de_Auto3563;
	_Context->msg_Auto3563[5]=nl_Auto3563;
	_Context->msg_Auto3563[6]=pt_Auto3563;
	_Context->msg_Auto3563[7]=xx_Auto3563;
	_Context->hint_Auto3563[0]=en__Auto3563;
	_Context->hint_Auto3563[1]=fr__Auto3563;
	_Context->hint_Auto3563[2]=it__Auto3563;
	_Context->hint_Auto3563[3]=es__Auto3563;
	_Context->hint_Auto3563[4]=de__Auto3563;
	_Context->hint_Auto3563[5]=nl__Auto3563;
	_Context->hint_Auto3563[6]=pt__Auto3563;
	_Context->hint_Auto3563[7]=xx__Auto3563;
	for (i=0; i < 8; i++)_Context->msg_Auto3564[i]=" ";
	_Context->msg_Auto3564[0]=en_Auto3564;
	_Context->msg_Auto3564[1]=fr_Auto3564;
	_Context->msg_Auto3564[2]=it_Auto3564;
	_Context->msg_Auto3564[3]=es_Auto3564;
	_Context->msg_Auto3564[4]=de_Auto3564;
	_Context->msg_Auto3564[5]=nl_Auto3564;
	_Context->msg_Auto3564[6]=pt_Auto3564;
	_Context->msg_Auto3564[7]=xx_Auto3564;
	_Context->hint_Auto3564[0]=en__Auto3564;
	_Context->hint_Auto3564[1]=fr__Auto3564;
	_Context->hint_Auto3564[2]=it__Auto3564;
	_Context->hint_Auto3564[3]=es__Auto3564;
	_Context->hint_Auto3564[4]=de__Auto3564;
	_Context->hint_Auto3564[5]=nl__Auto3564;
	_Context->hint_Auto3564[6]=pt__Auto3564;
	_Context->hint_Auto3564[7]=xx__Auto3564;
	for (i=0; i < 8; i++)_Context->msg_Auto3565[i]=" ";
	_Context->msg_Auto3565[0]=en_Auto3565;
	_Context->msg_Auto3565[1]=fr_Auto3565;
	_Context->msg_Auto3565[2]=it_Auto3565;
	_Context->msg_Auto3565[3]=es_Auto3565;
	_Context->msg_Auto3565[4]=de_Auto3565;
	_Context->msg_Auto3565[5]=nl_Auto3565;
	_Context->msg_Auto3565[6]=pt_Auto3565;
	_Context->msg_Auto3565[7]=xx_Auto3565;
	_Context->hint_Auto3565[0]=en__Auto3565;
	_Context->hint_Auto3565[1]=fr__Auto3565;
	_Context->hint_Auto3565[2]=it__Auto3565;
	_Context->hint_Auto3565[3]=es__Auto3565;
	_Context->hint_Auto3565[4]=de__Auto3565;
	_Context->hint_Auto3565[5]=nl__Auto3565;
	_Context->hint_Auto3565[6]=pt__Auto3565;
	_Context->hint_Auto3565[7]=xx__Auto3565;
	for (i=0; i < 8; i++)_Context->msg_Auto3566[i]=" ";
	_Context->msg_Auto3566[0]=en_Auto3566;
	_Context->msg_Auto3566[1]=fr_Auto3566;
	_Context->msg_Auto3566[2]=it_Auto3566;
	_Context->msg_Auto3566[3]=es_Auto3566;
	_Context->msg_Auto3566[4]=de_Auto3566;
	_Context->msg_Auto3566[5]=nl_Auto3566;
	_Context->msg_Auto3566[6]=pt_Auto3566;
	_Context->msg_Auto3566[7]=xx_Auto3566;
	for (i=0; i < 8; i++)_Context->msg_Auto3567[i]=" ";
	_Context->msg_Auto3567[0]=en_Auto3567;
	_Context->msg_Auto3567[1]=fr_Auto3567;
	_Context->msg_Auto3567[2]=it_Auto3567;
	_Context->msg_Auto3567[3]=es_Auto3567;
	_Context->msg_Auto3567[4]=de_Auto3567;
	_Context->msg_Auto3567[5]=nl_Auto3567;
	_Context->msg_Auto3567[6]=pt_Auto3567;
	_Context->msg_Auto3567[7]=xx_Auto3567;
	for (i=0; i < 8; i++)_Context->msg_Auto3568[i]=" ";
	_Context->msg_Auto3568[0]=en_Auto3568;
	_Context->msg_Auto3568[1]=fr_Auto3568;
	_Context->msg_Auto3568[2]=it_Auto3568;
	_Context->msg_Auto3568[3]=es_Auto3568;
	_Context->msg_Auto3568[4]=de_Auto3568;
	_Context->msg_Auto3568[5]=nl_Auto3568;
	_Context->msg_Auto3568[6]=pt_Auto3568;
	_Context->msg_Auto3568[7]=xx_Auto3568;
	_Context->hint_Auto3568[0]=en__Auto3568;
	_Context->hint_Auto3568[1]=fr__Auto3568;
	_Context->hint_Auto3568[2]=it__Auto3568;
	_Context->hint_Auto3568[3]=es__Auto3568;
	_Context->hint_Auto3568[4]=de__Auto3568;
	_Context->hint_Auto3568[5]=nl__Auto3568;
	_Context->hint_Auto3568[6]=pt__Auto3568;
	_Context->hint_Auto3568[7]=xx__Auto3568;
	for (i=0; i < 8; i++)_Context->msg_Auto3569[i]=" ";
	_Context->msg_Auto3569[0]=en_Auto3569;
	_Context->msg_Auto3569[1]=fr_Auto3569;
	_Context->msg_Auto3569[2]=it_Auto3569;
	_Context->msg_Auto3569[3]=es_Auto3569;
	_Context->msg_Auto3569[4]=de_Auto3569;
	_Context->msg_Auto3569[5]=nl_Auto3569;
	_Context->msg_Auto3569[6]=pt_Auto3569;
	_Context->msg_Auto3569[7]=xx_Auto3569;
	_Context->hint_Auto3569[0]=en__Auto3569;
	_Context->hint_Auto3569[1]=fr__Auto3569;
	_Context->hint_Auto3569[2]=it__Auto3569;
	_Context->hint_Auto3569[3]=es__Auto3569;
	_Context->hint_Auto3569[4]=de__Auto3569;
	_Context->hint_Auto3569[5]=nl__Auto3569;
	_Context->hint_Auto3569[6]=pt__Auto3569;
	_Context->hint_Auto3569[7]=xx__Auto3569;
	for (i=0; i < 8; i++)_Context->msg_Auto3570[i]=" ";
	_Context->msg_Auto3570[0]=en_Auto3570;
	_Context->msg_Auto3570[1]=fr_Auto3570;
	_Context->msg_Auto3570[2]=it_Auto3570;
	_Context->msg_Auto3570[3]=es_Auto3570;
	_Context->msg_Auto3570[4]=de_Auto3570;
	_Context->msg_Auto3570[5]=nl_Auto3570;
	_Context->msg_Auto3570[6]=pt_Auto3570;
	_Context->msg_Auto3570[7]=xx_Auto3570;
	_Context->hint_Auto3570[0]=en__Auto3570;
	_Context->hint_Auto3570[1]=fr__Auto3570;
	_Context->hint_Auto3570[2]=it__Auto3570;
	_Context->hint_Auto3570[3]=es__Auto3570;
	_Context->hint_Auto3570[4]=de__Auto3570;
	_Context->hint_Auto3570[5]=nl__Auto3570;
	_Context->hint_Auto3570[6]=pt__Auto3570;
	_Context->hint_Auto3570[7]=xx__Auto3570;
	for (i=0; i < 8; i++)_Context->msg_Auto3571[i]=" ";
	_Context->msg_Auto3571[0]=en_Auto3571;
	_Context->msg_Auto3571[1]=fr_Auto3571;
	_Context->msg_Auto3571[2]=it_Auto3571;
	_Context->msg_Auto3571[3]=es_Auto3571;
	_Context->msg_Auto3571[4]=de_Auto3571;
	_Context->msg_Auto3571[5]=nl_Auto3571;
	_Context->msg_Auto3571[6]=pt_Auto3571;
	_Context->msg_Auto3571[7]=xx_Auto3571;
	_Context->hint_Auto3571[0]=en__Auto3571;
	_Context->hint_Auto3571[1]=fr__Auto3571;
	_Context->hint_Auto3571[2]=it__Auto3571;
	_Context->hint_Auto3571[3]=es__Auto3571;
	_Context->hint_Auto3571[4]=de__Auto3571;
	_Context->hint_Auto3571[5]=nl__Auto3571;
	_Context->hint_Auto3571[6]=pt__Auto3571;
	_Context->hint_Auto3571[7]=xx__Auto3571;
	for (i=0; i < 8; i++)_Context->msg_Auto3572[i]=" ";
	_Context->msg_Auto3572[0]=en_Auto3572;
	_Context->msg_Auto3572[1]=fr_Auto3572;
	_Context->msg_Auto3572[2]=it_Auto3572;
	_Context->msg_Auto3572[3]=es_Auto3572;
	_Context->msg_Auto3572[4]=de_Auto3572;
	_Context->msg_Auto3572[5]=nl_Auto3572;
	_Context->msg_Auto3572[6]=pt_Auto3572;
	_Context->msg_Auto3572[7]=xx_Auto3572;
	_Context->hint_Auto3572[0]=en__Auto3572;
	_Context->hint_Auto3572[1]=fr__Auto3572;
	_Context->hint_Auto3572[2]=it__Auto3572;
	_Context->hint_Auto3572[3]=es__Auto3572;
	_Context->hint_Auto3572[4]=de__Auto3572;
	_Context->hint_Auto3572[5]=nl__Auto3572;
	_Context->hint_Auto3572[6]=pt__Auto3572;
	_Context->hint_Auto3572[7]=xx__Auto3572;
	for (i=0; i < 8; i++)_Context->msg_FormType[i]=" ";
	_Context->hint_FormType[0]=en__FormType;
	_Context->hint_FormType[1]=fr__FormType;
	_Context->hint_FormType[2]=it__FormType;
	_Context->hint_FormType[3]=es__FormType;
	_Context->hint_FormType[4]=de__FormType;
	_Context->hint_FormType[5]=nl__FormType;
	_Context->hint_FormType[6]=pt__FormType;
	_Context->hint_FormType[7]=xx__FormType;
	_Context->s_FormType=0;
	_Context->p_FormType=visual_buffer(_Context->x_Auto3559+50,_Context->y_Auto3559+120,140+2,144+2);
	for (i=0; i < 8; i++)_Context->msg_ProductionLanguage[i]=" ";
	_Context->hint_ProductionLanguage[0]=en__ProductionLanguage;
	_Context->hint_ProductionLanguage[1]=fr__ProductionLanguage;
	_Context->hint_ProductionLanguage[2]=it__ProductionLanguage;
	_Context->hint_ProductionLanguage[3]=es__ProductionLanguage;
	_Context->hint_ProductionLanguage[4]=de__ProductionLanguage;
	_Context->hint_ProductionLanguage[5]=nl__ProductionLanguage;
	_Context->hint_ProductionLanguage[6]=pt__ProductionLanguage;
	_Context->hint_ProductionLanguage[7]=xx__ProductionLanguage;
	_Context->s_ProductionLanguage=0;
	_Context->p_ProductionLanguage=visual_buffer(_Context->x_Auto3559+200,_Context->y_Auto3559+120,140+2,144+2);
	for (i=0; i < 8; i++)_Context->msg_NationalLanguage[i]=" ";
	_Context->hint_NationalLanguage[0]=en__NationalLanguage;
	for (i=0; i < 8; i++)_Context->msg_International[i]=" ";
	_Context->msg_International[0]=en_International;
	_Context->msg_International[1]=fr_International;
	_Context->msg_International[2]=it_International;
	_Context->msg_International[3]=es_International;
	_Context->msg_International[4]=de_International;
	_Context->msg_International[5]=nl_International;
	_Context->msg_International[6]=pt_International;
	_Context->msg_International[7]=xx_International;
	_Context->hint_International[0]=en__International;
	_Context->hint_International[1]=fr__International;
	_Context->hint_International[2]=it__International;
	_Context->hint_International[3]=es__International;
	_Context->hint_International[4]=de__International;
	_Context->hint_International[5]=nl__International;
	_Context->hint_International[6]=pt__International;
	_Context->hint_International[7]=xx__International;
	for (i=0; i < 8; i++)_Context->msg_Constants[i]=" ";
	_Context->msg_Constants[0]=en_Constants;
	_Context->msg_Constants[1]=fr_Constants;
	_Context->msg_Constants[2]=it_Constants;
	_Context->msg_Constants[3]=es_Constants;
	_Context->msg_Constants[4]=de_Constants;
	_Context->msg_Constants[5]=nl_Constants;
	_Context->msg_Constants[6]=pt_Constants;
	_Context->msg_Constants[7]=xx_Constants;
	_Context->hint_Constants[0]=en__Constants;
	_Context->hint_Constants[1]=fr__Constants;
	_Context->hint_Constants[2]=it__Constants;
	_Context->hint_Constants[3]=es__Constants;
	_Context->hint_Constants[4]=de__Constants;
	_Context->hint_Constants[5]=nl__Constants;
	_Context->hint_Constants[6]=pt__Constants;
	_Context->hint_Constants[7]=xx__Constants;
	for (i=0; i < 8; i++)_Context->msg_MultipleLanguage[i]=" ";
	_Context->msg_MultipleLanguage[0]=en_MultipleLanguage;
	_Context->msg_MultipleLanguage[1]=fr_MultipleLanguage;
	_Context->msg_MultipleLanguage[2]=it_MultipleLanguage;
	_Context->msg_MultipleLanguage[3]=es_MultipleLanguage;
	_Context->msg_MultipleLanguage[4]=de_MultipleLanguage;
	_Context->msg_MultipleLanguage[5]=nl_MultipleLanguage;
	_Context->msg_MultipleLanguage[6]=pt_MultipleLanguage;
	_Context->msg_MultipleLanguage[7]=xx_MultipleLanguage;
	_Context->hint_MultipleLanguage[0]=en__MultipleLanguage;
	_Context->hint_MultipleLanguage[1]=fr__MultipleLanguage;
	_Context->hint_MultipleLanguage[2]=it__MultipleLanguage;
	_Context->hint_MultipleLanguage[3]=es__MultipleLanguage;
	_Context->hint_MultipleLanguage[4]=de__MultipleLanguage;
	_Context->hint_MultipleLanguage[5]=nl__MultipleLanguage;
	_Context->hint_MultipleLanguage[6]=pt__MultipleLanguage;
	_Context->hint_MultipleLanguage[7]=xx__MultipleLanguage;
	for (i=0; i < 8; i++)_Context->msg_Program[i]=" ";
	_Context->msg_Program[0]=en_Program;
	_Context->msg_Program[1]=fr_Program;
	_Context->msg_Program[2]=it_Program;
	_Context->msg_Program[3]=es_Program;
	_Context->msg_Program[4]=de_Program;
	_Context->msg_Program[5]=nl_Program;
	_Context->msg_Program[6]=pt_Program;
	_Context->msg_Program[7]=xx_Program;
	_Context->hint_Program[0]=en__Program;
	_Context->hint_Program[1]=fr__Program;
	_Context->hint_Program[2]=it__Program;
	_Context->hint_Program[3]=es__Program;
	_Context->hint_Program[4]=de__Program;
	_Context->hint_Program[5]=nl__Program;
	_Context->hint_Program[6]=pt__Program;
	_Context->hint_Program[7]=xx__Program;
	_Context->s_Program=0;
	_Context->p_Program=visual_buffer(_Context->x_Auto3559+50,_Context->y_Auto3559+160,322+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_Overlay[i]=" ";
	_Context->msg_Overlay[0]=en_Overlay;
	_Context->msg_Overlay[1]=fr_Overlay;
	_Context->msg_Overlay[2]=it_Overlay;
	_Context->msg_Overlay[3]=es_Overlay;
	_Context->msg_Overlay[4]=de_Overlay;
	_Context->msg_Overlay[5]=nl_Overlay;
	_Context->msg_Overlay[6]=pt_Overlay;
	_Context->msg_Overlay[7]=xx_Overlay;
	_Context->hint_Overlay[0]=en__Overlay;
	_Context->hint_Overlay[1]=fr__Overlay;
	_Context->hint_Overlay[2]=it__Overlay;
	_Context->hint_Overlay[3]=es__Overlay;
	_Context->hint_Overlay[4]=de__Overlay;
	_Context->hint_Overlay[5]=nl__Overlay;
	_Context->hint_Overlay[6]=pt__Overlay;
	_Context->hint_Overlay[7]=xx__Overlay;
	_Context->s_Overlay=0;
	_Context->p_Overlay=visual_buffer(_Context->x_Auto3559+400,_Context->y_Auto3559+160,280+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_PopUp[i]=" ";
	_Context->msg_PopUp[0]=en_PopUp;
	_Context->msg_PopUp[1]=fr_PopUp;
	_Context->msg_PopUp[2]=it_PopUp;
	_Context->msg_PopUp[3]=es_PopUp;
	_Context->msg_PopUp[4]=de_PopUp;
	_Context->msg_PopUp[5]=nl_PopUp;
	_Context->msg_PopUp[6]=pt_PopUp;
	_Context->msg_PopUp[7]=xx_PopUp;
	_Context->hint_PopUp[0]=en__PopUp;
	_Context->hint_PopUp[1]=fr__PopUp;
	_Context->hint_PopUp[2]=it__PopUp;
	_Context->hint_PopUp[3]=es__PopUp;
	_Context->hint_PopUp[4]=de__PopUp;
	_Context->hint_PopUp[5]=nl__PopUp;
	_Context->hint_PopUp[6]=pt__PopUp;
	_Context->hint_PopUp[7]=xx__PopUp;
	for (i=0; i < 8; i++)_Context->msg_Dynamic[i]=" ";
	_Context->msg_Dynamic[0]=en_Dynamic;
	_Context->msg_Dynamic[1]=fr_Dynamic;
	_Context->msg_Dynamic[2]=it_Dynamic;
	_Context->msg_Dynamic[3]=es_Dynamic;
	_Context->msg_Dynamic[4]=de_Dynamic;
	_Context->msg_Dynamic[5]=nl_Dynamic;
	_Context->msg_Dynamic[6]=pt_Dynamic;
	_Context->msg_Dynamic[7]=xx_Dynamic;
	_Context->hint_Dynamic[0]=en__Dynamic;
	_Context->hint_Dynamic[1]=fr__Dynamic;
	_Context->hint_Dynamic[2]=it__Dynamic;
	_Context->hint_Dynamic[3]=es__Dynamic;
	_Context->hint_Dynamic[4]=de__Dynamic;
	_Context->hint_Dynamic[5]=nl__Dynamic;
	_Context->hint_Dynamic[6]=pt__Dynamic;
	_Context->hint_Dynamic[7]=xx__Dynamic;
	for (i=0; i < 8; i++)_Context->msg_CommandLine[i]=" ";
	_Context->msg_CommandLine[0]=en_CommandLine;
	_Context->msg_CommandLine[1]=fr_CommandLine;
	_Context->msg_CommandLine[2]=it_CommandLine;
	_Context->msg_CommandLine[3]=es_CommandLine;
	_Context->msg_CommandLine[4]=de_CommandLine;
	_Context->msg_CommandLine[5]=nl_CommandLine;
	_Context->msg_CommandLine[6]=pt_CommandLine;
	_Context->msg_CommandLine[7]=xx_CommandLine;
	_Context->hint_CommandLine[0]=en__CommandLine;
	_Context->hint_CommandLine[1]=fr__CommandLine;
	_Context->hint_CommandLine[2]=it__CommandLine;
	_Context->hint_CommandLine[3]=es__CommandLine;
	_Context->hint_CommandLine[4]=de__CommandLine;
	_Context->hint_CommandLine[5]=nl__CommandLine;
	_Context->hint_CommandLine[6]=pt__CommandLine;
	_Context->hint_CommandLine[7]=xx__CommandLine;
	for (i=0; i < 8; i++)_Context->msg_Resize[i]=" ";
	_Context->msg_Resize[0]=en_Resize;
	_Context->msg_Resize[1]=fr_Resize;
	_Context->msg_Resize[2]=it_Resize;
	_Context->msg_Resize[3]=es_Resize;
	_Context->msg_Resize[4]=de_Resize;
	_Context->msg_Resize[5]=nl_Resize;
	_Context->msg_Resize[6]=pt_Resize;
	_Context->msg_Resize[7]=xx_Resize;
	_Context->hint_Resize[0]=en__Resize;
	_Context->hint_Resize[1]=fr__Resize;
	_Context->hint_Resize[2]=it__Resize;
	_Context->hint_Resize[3]=es__Resize;
	_Context->hint_Resize[4]=de__Resize;
	_Context->hint_Resize[5]=nl__Resize;
	_Context->hint_Resize[6]=pt__Resize;
	_Context->hint_Resize[7]=xx__Resize;
	_Context->hint_ResizeX[0]=en__ResizeX;
	_Context->hint_ResizeY[0]=en__ResizeY;
	for (i=0; i < 8; i++)_Context->msg_GenHelp[i]=" ";
	_Context->msg_GenHelp[0]=en_GenHelp;
	_Context->msg_GenHelp[1]=fr_GenHelp;
	_Context->msg_GenHelp[2]=it_GenHelp;
	_Context->msg_GenHelp[3]=es_GenHelp;
	_Context->msg_GenHelp[4]=de_GenHelp;
	_Context->msg_GenHelp[5]=nl_GenHelp;
	_Context->msg_GenHelp[6]=pt_GenHelp;
	_Context->msg_GenHelp[7]=xx_GenHelp;
	_Context->hint_GenHelp[0]=en__GenHelp;
	_Context->hint_GenHelp[1]=fr__GenHelp;
	_Context->hint_GenHelp[2]=it__GenHelp;
	_Context->hint_GenHelp[3]=es__GenHelp;
	_Context->hint_GenHelp[4]=de__GenHelp;
	_Context->hint_GenHelp[5]=nl__GenHelp;
	_Context->hint_GenHelp[6]=pt__GenHelp;
	_Context->hint_GenHelp[7]=xx__GenHelp;
	for (i=0; i < 8; i++)_Context->msg_ActHelp[i]=" ";
	_Context->msg_ActHelp[0]=en_ActHelp;
	_Context->msg_ActHelp[1]=fr_ActHelp;
	_Context->msg_ActHelp[2]=it_ActHelp;
	_Context->msg_ActHelp[3]=es_ActHelp;
	_Context->msg_ActHelp[4]=de_ActHelp;
	_Context->msg_ActHelp[5]=nl_ActHelp;
	_Context->msg_ActHelp[6]=pt_ActHelp;
	_Context->msg_ActHelp[7]=xx_ActHelp;
	_Context->hint_ActHelp[0]=en__ActHelp;
	_Context->hint_ActHelp[1]=fr__ActHelp;
	_Context->hint_ActHelp[2]=it__ActHelp;
	_Context->hint_ActHelp[3]=es__ActHelp;
	_Context->hint_ActHelp[4]=de__ActHelp;
	_Context->hint_ActHelp[5]=nl__ActHelp;
	_Context->hint_ActHelp[6]=pt__ActHelp;
	_Context->hint_ActHelp[7]=xx__ActHelp;
	for (i=0; i < 8; i++)_Context->msg_Auto3573[i]=" ";
	_Context->msg_Auto3573[0]=en_Auto3573;
	_Context->msg_Auto3573[1]=fr_Auto3573;
	_Context->msg_Auto3573[2]=it_Auto3573;
	_Context->msg_Auto3573[3]=es_Auto3573;
	_Context->msg_Auto3573[4]=de_Auto3573;
	_Context->msg_Auto3573[5]=nl_Auto3573;
	_Context->msg_Auto3573[6]=pt_Auto3573;
	_Context->msg_Auto3573[7]=xx_Auto3573;
	_Context->hint_Auto3573[0]=en__Auto3573;
	_Context->hint_Auto3573[1]=fr__Auto3573;
	_Context->hint_Auto3573[2]=it__Auto3573;
	_Context->hint_Auto3573[3]=es__Auto3573;
	_Context->hint_Auto3573[4]=de__Auto3573;
	_Context->hint_Auto3573[5]=nl__Auto3573;
	_Context->hint_Auto3573[6]=pt__Auto3573;
	_Context->hint_Auto3573[7]=xx__Auto3573;
	for (i=0; i < 8; i++)_Context->msg_auto7[i]=" ";
	_Context->msg_auto7[0]=en_auto7;
	_Context->msg_auto7[1]=fr_auto7;
	_Context->msg_auto7[2]=it_auto7;
	_Context->msg_auto7[3]=es_auto7;
	_Context->msg_auto7[4]=de_auto7;
	_Context->msg_auto7[5]=nl_auto7;
	_Context->msg_auto7[6]=pt_auto7;
	_Context->msg_auto7[7]=xx_auto7;
	_Context->hint_auto7[0]=en__auto7;
	_Context->hint_auto7[1]=fr__auto7;
	_Context->hint_auto7[2]=it__auto7;
	_Context->hint_auto7[3]=es__auto7;
	_Context->hint_auto7[4]=de__auto7;
	_Context->hint_auto7[5]=nl__auto7;
	_Context->hint_auto7[6]=pt__auto7;
	_Context->hint_auto7[7]=xx__auto7;
	for (i=0; i < 8; i++)_Context->msg_auto52[i]=" ";
	_Context->msg_auto52[0]=en_auto52;
	_Context->msg_auto52[1]=fr_auto52;
	_Context->msg_auto52[2]=it_auto52;
	_Context->msg_auto52[3]=es_auto52;
	_Context->msg_auto52[4]=de_auto52;
	_Context->msg_auto52[5]=nl_auto52;
	_Context->msg_auto52[6]=pt_auto52;
	_Context->msg_auto52[7]=xx_auto52;
	_Context->hint_auto52[0]=en__auto52;
	_Context->hint_auto52[1]=fr__auto52;
	_Context->hint_auto52[2]=it__auto52;
	_Context->hint_auto52[3]=es__auto52;
	_Context->hint_auto52[4]=de__auto52;
	_Context->hint_auto52[5]=nl__auto52;
	_Context->hint_auto52[6]=pt__auto52;
	_Context->hint_auto52[7]=xx__auto52;
	for (i=0; i < 8; i++)_Context->msg_Auto3574[i]=" ";
	_Context->msg_Auto3574[0]=en_Auto3574;
	_Context->msg_Auto3574[1]=fr_Auto3574;
	_Context->msg_Auto3574[2]=it_Auto3574;
	_Context->msg_Auto3574[3]=es_Auto3574;
	_Context->msg_Auto3574[4]=de_Auto3574;
	_Context->msg_Auto3574[5]=nl_Auto3574;
	_Context->msg_Auto3574[6]=pt_Auto3574;
	_Context->msg_Auto3574[7]=xx_Auto3574;
	_Context->hint_Auto3574[0]=en__Auto3574;
	_Context->hint_Auto3574[1]=fr__Auto3574;
	_Context->hint_Auto3574[2]=it__Auto3574;
	_Context->hint_Auto3574[3]=es__Auto3574;
	_Context->hint_Auto3574[4]=de__Auto3574;
	_Context->hint_Auto3574[5]=nl__Auto3574;
	_Context->hint_Auto3574[6]=pt__Auto3574;
	_Context->hint_Auto3574[7]=xx__Auto3574;
	for (i=0; i < 8; i++)_Context->msg_Auto3575[i]=" ";
	_Context->msg_Auto3575[0]=en_Auto3575;
	_Context->msg_Auto3575[1]=fr_Auto3575;
	_Context->msg_Auto3575[2]=it_Auto3575;
	_Context->msg_Auto3575[3]=es_Auto3575;
	_Context->msg_Auto3575[4]=de_Auto3575;
	_Context->msg_Auto3575[5]=nl_Auto3575;
	_Context->msg_Auto3575[6]=pt_Auto3575;
	_Context->msg_Auto3575[7]=xx_Auto3575;
	_Context->hint_Auto3575[0]=en__Auto3575;
	_Context->hint_Auto3575[1]=fr__Auto3575;
	_Context->hint_Auto3575[2]=it__Auto3575;
	_Context->hint_Auto3575[3]=es__Auto3575;
	_Context->hint_Auto3575[4]=de__Auto3575;
	_Context->hint_Auto3575[5]=nl__Auto3575;
	_Context->hint_Auto3575[6]=pt__Auto3575;
	_Context->hint_Auto3575[7]=xx__Auto3575;
	for (i=0; i < 8; i++)_Context->msg_ChooseFileName[i]=" ";
	_Context->msg_ChooseFileName[0]=en_ChooseFileName;
	_Context->msg_ChooseFileName[1]=fr_ChooseFileName;
	_Context->msg_ChooseFileName[2]=it_ChooseFileName;
	_Context->msg_ChooseFileName[3]=es_ChooseFileName;
	_Context->msg_ChooseFileName[4]=de_ChooseFileName;
	_Context->msg_ChooseFileName[5]=nl_ChooseFileName;
	_Context->msg_ChooseFileName[6]=pt_ChooseFileName;
	_Context->msg_ChooseFileName[7]=xx_ChooseFileName;
	_Context->hint_ChooseFileName[0]=en__ChooseFileName;
	for (i=0; i < 8; i++)_Context->msg_ChooseStyleName[i]=" ";
	_Context->msg_ChooseStyleName[0]=en_ChooseStyleName;
	_Context->msg_ChooseStyleName[1]=fr_ChooseStyleName;
	_Context->msg_ChooseStyleName[2]=it_ChooseStyleName;
	_Context->msg_ChooseStyleName[3]=es_ChooseStyleName;
	_Context->msg_ChooseStyleName[4]=de_ChooseStyleName;
	_Context->msg_ChooseStyleName[5]=nl_ChooseStyleName;
	_Context->msg_ChooseStyleName[6]=pt_ChooseStyleName;
	_Context->msg_ChooseStyleName[7]=xx_ChooseStyleName;
	_Context->hint_ChooseStyleName[0]=en__ChooseStyleName;
	for (i=0; i < 8; i++)_Context->msg_EditSource[i]=" ";
	_Context->msg_EditSource[0]=en_EditSource;
	_Context->msg_EditSource[1]=fr_EditSource;
	_Context->msg_EditSource[2]=it_EditSource;
	_Context->msg_EditSource[3]=es_EditSource;
	_Context->msg_EditSource[4]=de_EditSource;
	_Context->msg_EditSource[5]=nl_EditSource;
	_Context->msg_EditSource[6]=pt_EditSource;
	_Context->msg_EditSource[7]=xx_EditSource;
	_Context->hint_EditSource[0]=en__EditSource;
	_Context->hint_EditSource[1]=fr__EditSource;
	_Context->hint_EditSource[2]=it__EditSource;
	_Context->hint_EditSource[3]=es__EditSource;
	_Context->hint_EditSource[4]=de__EditSource;
	_Context->hint_EditSource[5]=nl__EditSource;
	_Context->hint_EditSource[6]=pt__EditSource;
	_Context->hint_EditSource[7]=xx__EditSource;
	for (i=0; i < 8; i++)_Context->msg_EditStyle[i]=" ";
	_Context->msg_EditStyle[0]=en_EditStyle;
	_Context->msg_EditStyle[1]=fr_EditStyle;
	_Context->msg_EditStyle[2]=it_EditStyle;
	_Context->msg_EditStyle[3]=es_EditStyle;
	_Context->msg_EditStyle[4]=de_EditStyle;
	_Context->msg_EditStyle[5]=nl_EditStyle;
	_Context->msg_EditStyle[6]=pt_EditStyle;
	_Context->msg_EditStyle[7]=xx_EditStyle;
	_Context->hint_EditStyle[0]=en__EditStyle;
	_Context->hint_EditStyle[1]=fr__EditStyle;
	_Context->hint_EditStyle[2]=it__EditStyle;
	_Context->hint_EditStyle[3]=es__EditStyle;
	_Context->hint_EditStyle[4]=de__EditStyle;
	_Context->hint_EditStyle[5]=nl__EditStyle;
	_Context->hint_EditStyle[6]=pt__EditStyle;
	_Context->hint_EditStyle[7]=xx__EditStyle;
	_Context->hint_Identity[0]=en__Identity;
	for (i=0; i < 8; i++)_Context->msg_Auto3576[i]=" ";
	_Context->msg_Auto3576[0]=en_Auto3576;
	_Context->msg_Auto3576[1]=fr_Auto3576;
	_Context->msg_Auto3576[2]=it_Auto3576;
	_Context->msg_Auto3576[3]=es_Auto3576;
	_Context->msg_Auto3576[4]=de_Auto3576;
	_Context->msg_Auto3576[5]=nl_Auto3576;
	_Context->msg_Auto3576[6]=pt_Auto3576;
	_Context->msg_Auto3576[7]=xx_Auto3576;
	_Context->hint_Auto3576[0]=en__Auto3576;
	_Context->hint_Auto3576[1]=fr__Auto3576;
	_Context->hint_Auto3576[2]=it__Auto3576;
	_Context->hint_Auto3576[3]=es__Auto3576;
	_Context->hint_Auto3576[4]=de__Auto3576;
	_Context->hint_Auto3576[5]=nl__Auto3576;
	_Context->hint_Auto3576[6]=pt__Auto3576;
	_Context->hint_Auto3576[7]=xx__Auto3576;
	for (i=0; i < 8; i++)_Context->msg_ChoosePalette[i]=" ";
	_Context->msg_ChoosePalette[0]=en_ChoosePalette;
	_Context->msg_ChoosePalette[1]=fr_ChoosePalette;
	_Context->msg_ChoosePalette[2]=it_ChoosePalette;
	_Context->msg_ChoosePalette[3]=es_ChoosePalette;
	_Context->msg_ChoosePalette[4]=de_ChoosePalette;
	_Context->msg_ChoosePalette[5]=nl_ChoosePalette;
	_Context->msg_ChoosePalette[6]=pt_ChoosePalette;
	_Context->msg_ChoosePalette[7]=xx_ChoosePalette;
	_Context->hint_ChoosePalette[0]=en__ChoosePalette;
	_Context->hint_PaletteName[0]=en__PaletteName;
	_Context->hint_ClearScreen[0]=en__ClearScreen;
	for (i=0; i < 8; i++)_Context->msg_MouseEvents[i]=" ";
	_Context->msg_MouseEvents[0]=en_MouseEvents;
	_Context->msg_MouseEvents[1]=fr_MouseEvents;
	_Context->msg_MouseEvents[2]=it_MouseEvents;
	_Context->msg_MouseEvents[3]=es_MouseEvents;
	_Context->msg_MouseEvents[4]=de_MouseEvents;
	_Context->msg_MouseEvents[5]=nl_MouseEvents;
	_Context->msg_MouseEvents[6]=pt_MouseEvents;
	_Context->msg_MouseEvents[7]=xx_MouseEvents;
	_Context->hint_MouseEvents[0]=en__MouseEvents;
	_Context->hint_MouseEvents[1]=fr__MouseEvents;
	_Context->hint_MouseEvents[2]=it__MouseEvents;
	_Context->hint_MouseEvents[3]=es__MouseEvents;
	_Context->hint_MouseEvents[4]=de__MouseEvents;
	_Context->hint_MouseEvents[5]=nl__MouseEvents;
	_Context->hint_MouseEvents[6]=pt__MouseEvents;
	_Context->hint_MouseEvents[7]=xx__MouseEvents;
	_Context->focus_pages[2]=35;
	for (i=0; i < 8; i++)_Context->msg_Auto3577[i]=" ";
	_Context->msg_Auto3577[0]=en_Auto3577;
	_Context->msg_Auto3577[1]=fr_Auto3577;
	_Context->msg_Auto3577[2]=it_Auto3577;
	_Context->msg_Auto3577[3]=es_Auto3577;
	_Context->msg_Auto3577[4]=de_Auto3577;
	_Context->msg_Auto3577[5]=nl_Auto3577;
	_Context->msg_Auto3577[6]=pt_Auto3577;
	_Context->msg_Auto3577[7]=xx_Auto3577;
	_Context->hint_Auto3577[0]=en__Auto3577;
	_Context->hint_Auto3577[1]=fr__Auto3577;
	_Context->hint_Auto3577[2]=it__Auto3577;
	_Context->hint_Auto3577[3]=es__Auto3577;
	_Context->hint_Auto3577[4]=de__Auto3577;
	_Context->hint_Auto3577[5]=nl__Auto3577;
	_Context->hint_Auto3577[6]=pt__Auto3577;
	_Context->hint_Auto3577[7]=xx__Auto3577;
	for (i=0; i < 8; i++)_Context->msg_Auto3578[i]=" ";
	_Context->msg_Auto3578[0]=en_Auto3578;
	_Context->msg_Auto3578[1]=fr_Auto3578;
	_Context->msg_Auto3578[2]=it_Auto3578;
	_Context->msg_Auto3578[3]=es_Auto3578;
	_Context->msg_Auto3578[4]=de_Auto3578;
	_Context->msg_Auto3578[5]=nl_Auto3578;
	_Context->msg_Auto3578[6]=pt_Auto3578;
	_Context->msg_Auto3578[7]=xx_Auto3578;
	_Context->hint_Auto3578[0]=en__Auto3578;
	_Context->hint_Auto3578[1]=fr__Auto3578;
	_Context->hint_Auto3578[2]=it__Auto3578;
	_Context->hint_Auto3578[3]=es__Auto3578;
	_Context->hint_Auto3578[4]=de__Auto3578;
	_Context->hint_Auto3578[5]=nl__Auto3578;
	_Context->hint_Auto3578[6]=pt__Auto3578;
	_Context->hint_Auto3578[7]=xx__Auto3578;
	for (i=0; i < 8; i++)_Context->msg_Auto3579[i]=" ";
	_Context->msg_Auto3579[0]=en_Auto3579;
	_Context->msg_Auto3579[1]=fr_Auto3579;
	_Context->msg_Auto3579[2]=it_Auto3579;
	_Context->msg_Auto3579[3]=es_Auto3579;
	_Context->msg_Auto3579[4]=de_Auto3579;
	_Context->msg_Auto3579[5]=nl_Auto3579;
	_Context->msg_Auto3579[6]=pt_Auto3579;
	_Context->msg_Auto3579[7]=xx_Auto3579;
	_Context->hint_Auto3579[0]=en__Auto3579;
	_Context->hint_Auto3579[1]=fr__Auto3579;
	_Context->hint_Auto3579[2]=it__Auto3579;
	_Context->hint_Auto3579[3]=es__Auto3579;
	_Context->hint_Auto3579[4]=de__Auto3579;
	_Context->hint_Auto3579[5]=nl__Auto3579;
	_Context->hint_Auto3579[6]=pt__Auto3579;
	_Context->hint_Auto3579[7]=xx__Auto3579;
	for (i=0; i < 8; i++)_Context->msg_SendLeft[i]=" ";
	_Context->msg_SendLeft[0]=en_SendLeft;
	_Context->msg_SendLeft[1]=fr_SendLeft;
	_Context->msg_SendLeft[2]=it_SendLeft;
	_Context->msg_SendLeft[3]=es_SendLeft;
	_Context->msg_SendLeft[4]=de_SendLeft;
	_Context->msg_SendLeft[5]=nl_SendLeft;
	_Context->msg_SendLeft[6]=pt_SendLeft;
	_Context->msg_SendLeft[7]=xx_SendLeft;
	_Context->hint_SendLeft[0]=en__SendLeft;
	_Context->hint_SendLeft[1]=fr__SendLeft;
	_Context->hint_SendLeft[2]=it__SendLeft;
	_Context->hint_SendLeft[3]=es__SendLeft;
	_Context->hint_SendLeft[4]=de__SendLeft;
	_Context->hint_SendLeft[5]=nl__SendLeft;
	_Context->hint_SendLeft[6]=pt__SendLeft;
	_Context->hint_SendLeft[7]=xx__SendLeft;
	for (i=0; i < 8; i++)_Context->msg_SendMiddle[i]=" ";
	_Context->msg_SendMiddle[0]=en_SendMiddle;
	_Context->msg_SendMiddle[1]=fr_SendMiddle;
	_Context->msg_SendMiddle[2]=it_SendMiddle;
	_Context->msg_SendMiddle[3]=es_SendMiddle;
	_Context->msg_SendMiddle[4]=de_SendMiddle;
	_Context->msg_SendMiddle[5]=nl_SendMiddle;
	_Context->msg_SendMiddle[6]=pt_SendMiddle;
	_Context->msg_SendMiddle[7]=xx_SendMiddle;
	_Context->hint_SendMiddle[0]=en__SendMiddle;
	_Context->hint_SendMiddle[1]=fr__SendMiddle;
	_Context->hint_SendMiddle[2]=it__SendMiddle;
	_Context->hint_SendMiddle[3]=es__SendMiddle;
	_Context->hint_SendMiddle[4]=de__SendMiddle;
	_Context->hint_SendMiddle[5]=nl__SendMiddle;
	_Context->hint_SendMiddle[6]=pt__SendMiddle;
	_Context->hint_SendMiddle[7]=xx__SendMiddle;
	for (i=0; i < 8; i++)_Context->msg_SendRight[i]=" ";
	_Context->msg_SendRight[0]=en_SendRight;
	_Context->msg_SendRight[1]=fr_SendRight;
	_Context->msg_SendRight[2]=it_SendRight;
	_Context->msg_SendRight[3]=es_SendRight;
	_Context->msg_SendRight[4]=de_SendRight;
	_Context->msg_SendRight[5]=nl_SendRight;
	_Context->msg_SendRight[6]=pt_SendRight;
	_Context->msg_SendRight[7]=xx_SendRight;
	_Context->hint_SendRight[0]=en__SendRight;
	_Context->hint_SendRight[1]=fr__SendRight;
	_Context->hint_SendRight[2]=it__SendRight;
	_Context->hint_SendRight[3]=es__SendRight;
	_Context->hint_SendRight[4]=de__SendRight;
	_Context->hint_SendRight[5]=nl__SendRight;
	_Context->hint_SendRight[6]=pt__SendRight;
	_Context->hint_SendRight[7]=xx__SendRight;
	for (i=0; i < 8; i++)_Context->msg_SendWheel[i]=" ";
	_Context->msg_SendWheel[0]=en_SendWheel;
	_Context->msg_SendWheel[1]=fr_SendWheel;
	_Context->msg_SendWheel[2]=it_SendWheel;
	_Context->msg_SendWheel[3]=es_SendWheel;
	_Context->msg_SendWheel[4]=de_SendWheel;
	_Context->msg_SendWheel[5]=nl_SendWheel;
	_Context->msg_SendWheel[6]=pt_SendWheel;
	_Context->msg_SendWheel[7]=xx_SendWheel;
	_Context->hint_SendWheel[0]=en__SendWheel;
	_Context->hint_SendWheel[1]=fr__SendWheel;
	_Context->hint_SendWheel[2]=it__SendWheel;
	_Context->hint_SendWheel[3]=es__SendWheel;
	_Context->hint_SendWheel[4]=de__SendWheel;
	_Context->hint_SendWheel[5]=nl__SendWheel;
	_Context->hint_SendWheel[6]=pt__SendWheel;
	_Context->hint_SendWheel[7]=xx__SendWheel;
	for (i=0; i < 8; i++)_Context->msg_ButtonFilter[i]=" ";
	_Context->msg_ButtonFilter[0]=en_ButtonFilter;
	_Context->msg_ButtonFilter[1]=fr_ButtonFilter;
	_Context->msg_ButtonFilter[2]=it_ButtonFilter;
	_Context->msg_ButtonFilter[3]=es_ButtonFilter;
	_Context->msg_ButtonFilter[4]=de_ButtonFilter;
	_Context->msg_ButtonFilter[5]=nl_ButtonFilter;
	_Context->msg_ButtonFilter[6]=pt_ButtonFilter;
	_Context->msg_ButtonFilter[7]=xx_ButtonFilter;
	_Context->hint_ButtonFilter[0]=en__ButtonFilter;
	_Context->hint_ButtonFilter[1]=fr__ButtonFilter;
	_Context->hint_ButtonFilter[2]=it__ButtonFilter;
	_Context->hint_ButtonFilter[3]=es__ButtonFilter;
	_Context->hint_ButtonFilter[4]=de__ButtonFilter;
	_Context->hint_ButtonFilter[5]=nl__ButtonFilter;
	_Context->hint_ButtonFilter[6]=pt__ButtonFilter;
	_Context->hint_ButtonFilter[7]=xx__ButtonFilter;
	for (i=0; i < 8; i++)_Context->msg_SendDown[i]=" ";
	_Context->msg_SendDown[0]=en_SendDown;
	_Context->msg_SendDown[1]=fr_SendDown;
	_Context->msg_SendDown[2]=it_SendDown;
	_Context->msg_SendDown[3]=es_SendDown;
	_Context->msg_SendDown[4]=de_SendDown;
	_Context->msg_SendDown[5]=nl_SendDown;
	_Context->msg_SendDown[6]=pt_SendDown;
	_Context->msg_SendDown[7]=xx_SendDown;
	_Context->hint_SendDown[0]=en__SendDown;
	_Context->hint_SendDown[1]=fr__SendDown;
	_Context->hint_SendDown[2]=it__SendDown;
	_Context->hint_SendDown[3]=es__SendDown;
	_Context->hint_SendDown[4]=de__SendDown;
	_Context->hint_SendDown[5]=nl__SendDown;
	_Context->hint_SendDown[6]=pt__SendDown;
	_Context->hint_SendDown[7]=xx__SendDown;
	for (i=0; i < 8; i++)_Context->msg_SendUp[i]=" ";
	_Context->msg_SendUp[0]=en_SendUp;
	_Context->msg_SendUp[1]=fr_SendUp;
	_Context->msg_SendUp[2]=it_SendUp;
	_Context->msg_SendUp[3]=es_SendUp;
	_Context->msg_SendUp[4]=de_SendUp;
	_Context->msg_SendUp[5]=nl_SendUp;
	_Context->msg_SendUp[6]=pt_SendUp;
	_Context->msg_SendUp[7]=xx_SendUp;
	_Context->hint_SendUp[0]=en__SendUp;
	_Context->hint_SendUp[1]=fr__SendUp;
	_Context->hint_SendUp[2]=it__SendUp;
	_Context->hint_SendUp[3]=es__SendUp;
	_Context->hint_SendUp[4]=de__SendUp;
	_Context->hint_SendUp[5]=nl__SendUp;
	_Context->hint_SendUp[6]=pt__SendUp;
	_Context->hint_SendUp[7]=xx__SendUp;
	for (i=0; i < 8; i++)_Context->msg_SendWhileDown[i]=" ";
	_Context->msg_SendWhileDown[0]=en_SendWhileDown;
	_Context->msg_SendWhileDown[1]=fr_SendWhileDown;
	_Context->msg_SendWhileDown[2]=it_SendWhileDown;
	_Context->msg_SendWhileDown[3]=es_SendWhileDown;
	_Context->msg_SendWhileDown[4]=de_SendWhileDown;
	_Context->msg_SendWhileDown[5]=nl_SendWhileDown;
	_Context->msg_SendWhileDown[6]=pt_SendWhileDown;
	_Context->msg_SendWhileDown[7]=xx_SendWhileDown;
	_Context->hint_SendWhileDown[0]=en__SendWhileDown;
	_Context->hint_SendWhileDown[1]=fr__SendWhileDown;
	_Context->hint_SendWhileDown[2]=it__SendWhileDown;
	_Context->hint_SendWhileDown[3]=es__SendWhileDown;
	_Context->hint_SendWhileDown[4]=de__SendWhileDown;
	_Context->hint_SendWhileDown[5]=nl__SendWhileDown;
	_Context->hint_SendWhileDown[6]=pt__SendWhileDown;
	_Context->hint_SendWhileDown[7]=xx__SendWhileDown;
	for (i=0; i < 8; i++)_Context->msg_SendMove[i]=" ";
	_Context->msg_SendMove[0]=en_SendMove;
	_Context->msg_SendMove[1]=fr_SendMove;
	_Context->msg_SendMove[2]=it_SendMove;
	_Context->msg_SendMove[3]=es_SendMove;
	_Context->msg_SendMove[4]=de_SendMove;
	_Context->msg_SendMove[5]=nl_SendMove;
	_Context->msg_SendMove[6]=pt_SendMove;
	_Context->msg_SendMove[7]=xx_SendMove;
	_Context->hint_SendMove[0]=en__SendMove;
	_Context->hint_SendMove[1]=fr__SendMove;
	_Context->hint_SendMove[2]=it__SendMove;
	_Context->hint_SendMove[3]=es__SendMove;
	_Context->hint_SendMove[4]=de__SendMove;
	_Context->hint_SendMove[5]=nl__SendMove;
	_Context->hint_SendMove[6]=pt__SendMove;
	_Context->hint_SendMove[7]=xx__SendMove;
	for (i=0; i < 8; i++)_Context->msg_MouseKey[i]=" ";
	_Context->msg_MouseKey[0]=en_MouseKey;
	_Context->msg_MouseKey[1]=fr_MouseKey;
	_Context->msg_MouseKey[2]=it_MouseKey;
	_Context->msg_MouseKey[3]=es_MouseKey;
	_Context->msg_MouseKey[4]=de_MouseKey;
	_Context->msg_MouseKey[5]=nl_MouseKey;
	_Context->msg_MouseKey[6]=pt_MouseKey;
	_Context->msg_MouseKey[7]=xx_MouseKey;
	_Context->hint_MouseKey[0]=en__MouseKey;
	_Context->hint_MouseKey[1]=fr__MouseKey;
	_Context->hint_MouseKey[2]=it__MouseKey;
	_Context->hint_MouseKey[3]=es__MouseKey;
	_Context->hint_MouseKey[4]=de__MouseKey;
	_Context->hint_MouseKey[5]=nl__MouseKey;
	_Context->hint_MouseKey[6]=pt__MouseKey;
	_Context->hint_MouseKey[7]=xx__MouseKey;
	for (i=0; i < 8; i++)_Context->msg_WidgetTriggers[i]=" ";
	_Context->msg_WidgetTriggers[0]=en_WidgetTriggers;
	_Context->msg_WidgetTriggers[1]=fr_WidgetTriggers;
	_Context->msg_WidgetTriggers[2]=it_WidgetTriggers;
	_Context->msg_WidgetTriggers[3]=es_WidgetTriggers;
	_Context->msg_WidgetTriggers[4]=de_WidgetTriggers;
	_Context->msg_WidgetTriggers[5]=nl_WidgetTriggers;
	_Context->msg_WidgetTriggers[6]=pt_WidgetTriggers;
	_Context->msg_WidgetTriggers[7]=xx_WidgetTriggers;
	_Context->hint_WidgetTriggers[0]=en__WidgetTriggers;
	_Context->hint_WidgetTriggers[1]=fr__WidgetTriggers;
	_Context->hint_WidgetTriggers[2]=it__WidgetTriggers;
	_Context->hint_WidgetTriggers[3]=es__WidgetTriggers;
	_Context->hint_WidgetTriggers[4]=de__WidgetTriggers;
	_Context->hint_WidgetTriggers[5]=nl__WidgetTriggers;
	_Context->hint_WidgetTriggers[6]=pt__WidgetTriggers;
	_Context->hint_WidgetTriggers[7]=xx__WidgetTriggers;
	for (i=0; i < 8; i++)_Context->msg_Escape[i]=" ";
	_Context->msg_Escape[0]=en_Escape;
	_Context->msg_Escape[1]=fr_Escape;
	_Context->msg_Escape[2]=it_Escape;
	_Context->msg_Escape[3]=es_Escape;
	_Context->msg_Escape[4]=de_Escape;
	_Context->msg_Escape[5]=nl_Escape;
	_Context->msg_Escape[6]=pt_Escape;
	_Context->msg_Escape[7]=xx_Escape;
	_Context->hint_Escape[0]=en__Escape;
	_Context->hint_Escape[1]=fr__Escape;
	_Context->hint_Escape[2]=it__Escape;
	_Context->hint_Escape[3]=es__Escape;
	_Context->hint_Escape[4]=de__Escape;
	_Context->hint_Escape[5]=nl__Escape;
	_Context->hint_Escape[6]=pt__Escape;
	_Context->hint_Escape[7]=xx__Escape;
	_Context->s_Escape=0;
	_Context->p_Escape=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+280,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_Enter[i]=" ";
	_Context->msg_Enter[0]=en_Enter;
	_Context->msg_Enter[1]=fr_Enter;
	_Context->msg_Enter[2]=it_Enter;
	_Context->msg_Enter[3]=es_Enter;
	_Context->msg_Enter[4]=de_Enter;
	_Context->msg_Enter[5]=nl_Enter;
	_Context->msg_Enter[6]=pt_Enter;
	_Context->msg_Enter[7]=xx_Enter;
	_Context->hint_Enter[0]=en__Enter;
	_Context->hint_Enter[1]=fr__Enter;
	_Context->hint_Enter[2]=it__Enter;
	_Context->hint_Enter[3]=es__Enter;
	_Context->hint_Enter[4]=de__Enter;
	_Context->hint_Enter[5]=nl__Enter;
	_Context->hint_Enter[6]=pt__Enter;
	_Context->hint_Enter[7]=xx__Enter;
	_Context->s_Enter=0;
	_Context->p_Enter=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+460,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_PageUp[i]=" ";
	_Context->msg_PageUp[0]=en_PageUp;
	_Context->msg_PageUp[1]=fr_PageUp;
	_Context->msg_PageUp[2]=it_PageUp;
	_Context->msg_PageUp[3]=es_PageUp;
	_Context->msg_PageUp[4]=de_PageUp;
	_Context->msg_PageUp[5]=nl_PageUp;
	_Context->msg_PageUp[6]=pt_PageUp;
	_Context->msg_PageUp[7]=xx_PageUp;
	_Context->hint_PageUp[0]=en__PageUp;
	_Context->hint_PageUp[1]=fr__PageUp;
	_Context->hint_PageUp[2]=it__PageUp;
	_Context->hint_PageUp[3]=es__PageUp;
	_Context->hint_PageUp[4]=de__PageUp;
	_Context->hint_PageUp[5]=nl__PageUp;
	_Context->hint_PageUp[6]=pt__PageUp;
	_Context->hint_PageUp[7]=xx__PageUp;
	_Context->s_PageUp=0;
	_Context->p_PageUp=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+310,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_PageDown[i]=" ";
	_Context->msg_PageDown[0]=en_PageDown;
	_Context->msg_PageDown[1]=fr_PageDown;
	_Context->msg_PageDown[2]=it_PageDown;
	_Context->msg_PageDown[3]=es_PageDown;
	_Context->msg_PageDown[4]=de_PageDown;
	_Context->msg_PageDown[5]=nl_PageDown;
	_Context->msg_PageDown[6]=pt_PageDown;
	_Context->msg_PageDown[7]=xx_PageDown;
	_Context->hint_PageDown[0]=en__PageDown;
	_Context->hint_PageDown[1]=fr__PageDown;
	_Context->hint_PageDown[2]=it__PageDown;
	_Context->hint_PageDown[3]=es__PageDown;
	_Context->hint_PageDown[4]=de__PageDown;
	_Context->hint_PageDown[5]=nl__PageDown;
	_Context->hint_PageDown[6]=pt__PageDown;
	_Context->hint_PageDown[7]=xx__PageDown;
	_Context->s_PageDown=0;
	_Context->p_PageDown=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+340,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_UpArrow[i]=" ";
	_Context->msg_UpArrow[0]=en_UpArrow;
	_Context->msg_UpArrow[1]=fr_UpArrow;
	_Context->msg_UpArrow[2]=it_UpArrow;
	_Context->msg_UpArrow[3]=es_UpArrow;
	_Context->msg_UpArrow[4]=de_UpArrow;
	_Context->msg_UpArrow[5]=nl_UpArrow;
	_Context->msg_UpArrow[6]=pt_UpArrow;
	_Context->msg_UpArrow[7]=xx_UpArrow;
	_Context->hint_UpArrow[0]=en__UpArrow;
	_Context->hint_UpArrow[1]=fr__UpArrow;
	_Context->hint_UpArrow[2]=it__UpArrow;
	_Context->hint_UpArrow[3]=es__UpArrow;
	_Context->hint_UpArrow[4]=de__UpArrow;
	_Context->hint_UpArrow[5]=nl__UpArrow;
	_Context->hint_UpArrow[6]=pt__UpArrow;
	_Context->hint_UpArrow[7]=xx__UpArrow;
	_Context->s_UpArrow=0;
	_Context->p_UpArrow=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+370,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_DownArrow[i]=" ";
	_Context->msg_DownArrow[0]=en_DownArrow;
	_Context->msg_DownArrow[1]=fr_DownArrow;
	_Context->msg_DownArrow[2]=it_DownArrow;
	_Context->msg_DownArrow[3]=es_DownArrow;
	_Context->msg_DownArrow[4]=de_DownArrow;
	_Context->msg_DownArrow[5]=nl_DownArrow;
	_Context->msg_DownArrow[6]=pt_DownArrow;
	_Context->msg_DownArrow[7]=xx_DownArrow;
	_Context->hint_DownArrow[0]=en__DownArrow;
	_Context->hint_DownArrow[1]=fr__DownArrow;
	_Context->hint_DownArrow[2]=it__DownArrow;
	_Context->hint_DownArrow[3]=es__DownArrow;
	_Context->hint_DownArrow[4]=de__DownArrow;
	_Context->hint_DownArrow[5]=nl__DownArrow;
	_Context->hint_DownArrow[6]=pt__DownArrow;
	_Context->hint_DownArrow[7]=xx__DownArrow;
	_Context->s_DownArrow=0;
	_Context->p_DownArrow=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+400,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_Tabulation[i]=" ";
	_Context->msg_Tabulation[0]=en_Tabulation;
	_Context->msg_Tabulation[1]=fr_Tabulation;
	_Context->msg_Tabulation[2]=it_Tabulation;
	_Context->msg_Tabulation[3]=es_Tabulation;
	_Context->msg_Tabulation[4]=de_Tabulation;
	_Context->msg_Tabulation[5]=nl_Tabulation;
	_Context->msg_Tabulation[6]=pt_Tabulation;
	_Context->msg_Tabulation[7]=xx_Tabulation;
	_Context->hint_Tabulation[0]=en__Tabulation;
	_Context->hint_Tabulation[1]=fr__Tabulation;
	_Context->hint_Tabulation[2]=it__Tabulation;
	_Context->hint_Tabulation[3]=es__Tabulation;
	_Context->hint_Tabulation[4]=de__Tabulation;
	_Context->hint_Tabulation[5]=nl__Tabulation;
	_Context->hint_Tabulation[6]=pt__Tabulation;
	_Context->hint_Tabulation[7]=xx__Tabulation;
	_Context->s_Tabulation=0;
	_Context->p_Tabulation=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+430,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_DefaultBreak[i]=" ";
	_Context->msg_DefaultBreak[0]=en_DefaultBreak;
	_Context->msg_DefaultBreak[1]=fr_DefaultBreak;
	_Context->msg_DefaultBreak[2]=it_DefaultBreak;
	_Context->msg_DefaultBreak[3]=es_DefaultBreak;
	_Context->msg_DefaultBreak[4]=de_DefaultBreak;
	_Context->msg_DefaultBreak[5]=nl_DefaultBreak;
	_Context->msg_DefaultBreak[6]=pt_DefaultBreak;
	_Context->msg_DefaultBreak[7]=xx_DefaultBreak;
	_Context->hint_DefaultBreak[0]=en__DefaultBreak;
	_Context->hint_DefaultBreak[1]=fr__DefaultBreak;
	_Context->hint_DefaultBreak[2]=it__DefaultBreak;
	_Context->hint_DefaultBreak[3]=es__DefaultBreak;
	_Context->hint_DefaultBreak[4]=de__DefaultBreak;
	_Context->hint_DefaultBreak[5]=nl__DefaultBreak;
	_Context->hint_DefaultBreak[6]=pt__DefaultBreak;
	_Context->hint_DefaultBreak[7]=xx__DefaultBreak;
	_Context->s_DefaultBreak=0;
	_Context->p_DefaultBreak=visual_buffer(_Context->x_Auto3559+40,_Context->y_Auto3559+490,700+2,16+2);
	for (i=0; i < 8; i++)_Context->msg_FormMethods[i]=" ";
	_Context->msg_FormMethods[0]=en_FormMethods;
	_Context->msg_FormMethods[1]=fr_FormMethods;
	_Context->msg_FormMethods[2]=it_FormMethods;
	_Context->msg_FormMethods[3]=es_FormMethods;
	_Context->msg_FormMethods[4]=de_FormMethods;
	_Context->msg_FormMethods[5]=nl_FormMethods;
	_Context->msg_FormMethods[6]=pt_FormMethods;
	_Context->msg_FormMethods[7]=xx_FormMethods;
	_Context->hint_FormMethods[0]=en__FormMethods;
	_Context->hint_FormMethods[1]=fr__FormMethods;
	_Context->hint_FormMethods[2]=it__FormMethods;
	_Context->hint_FormMethods[3]=es__FormMethods;
	_Context->hint_FormMethods[4]=de__FormMethods;
	_Context->hint_FormMethods[5]=nl__FormMethods;
	_Context->hint_FormMethods[6]=pt__FormMethods;
	_Context->hint_FormMethods[7]=xx__FormMethods;
	_Context->focus_pages[3]=55;
	for (i=0; i < 8; i++)_Context->msg_Methods[i]=" ";
	_Context->msg_Methods[0]=en_Methods;
	_Context->msg_Methods[1]=fr_Methods;
	_Context->msg_Methods[2]=it_Methods;
	_Context->msg_Methods[3]=es_Methods;
	_Context->msg_Methods[4]=de_Methods;
	_Context->msg_Methods[5]=nl_Methods;
	_Context->msg_Methods[6]=pt_Methods;
	_Context->msg_Methods[7]=xx_Methods;
	_Context->hint_Methods[0]=en__Methods;
	_Context->hint_Methods[1]=fr__Methods;
	_Context->hint_Methods[2]=it__Methods;
	_Context->hint_Methods[3]=es__Methods;
	_Context->hint_Methods[4]=de__Methods;
	_Context->hint_Methods[5]=nl__Methods;
	_Context->hint_Methods[6]=pt__Methods;
	_Context->hint_Methods[7]=xx__Methods;
	if ( 0 > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[0-1][0]; } ;
	if ( 1 > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[1-1][0]; } ;
	_Context->hint_Cursor[1]=fr__Cursor;
	_Context->x_Cursor=_Context->x_Auto3559+30;
	_Context->y_Cursor=_Context->y_Auto3559+70;
	_Context->w_Cursor=710;
	_Context->h_Cursor=20;
	_Context->fg_Cursor=20;
	_Context->bg_Cursor=20;
	_Context->fid_Cursor=1;
	for (i=0; i < 8; i++)_Context->msg_EditMethod[i]=" ";
	_Context->msg_EditMethod[0]=en_EditMethod;
	_Context->msg_EditMethod[1]=fr_EditMethod;
	_Context->msg_EditMethod[2]=it_EditMethod;
	_Context->msg_EditMethod[3]=es_EditMethod;
	_Context->msg_EditMethod[4]=de_EditMethod;
	_Context->msg_EditMethod[5]=nl_EditMethod;
	_Context->msg_EditMethod[6]=pt_EditMethod;
	_Context->msg_EditMethod[7]=xx_EditMethod;
	_Context->hint_EditMethod[0]=en__EditMethod;
	_Context->hint_EditMethod[1]=fr__EditMethod;
	_Context->hint_EditMethod[2]=it__EditMethod;
	_Context->hint_EditMethod[3]=es__EditMethod;
	_Context->hint_EditMethod[4]=de__EditMethod;
	_Context->hint_EditMethod[5]=nl__EditMethod;
	_Context->hint_EditMethod[6]=pt__EditMethod;
	_Context->hint_EditMethod[7]=xx__EditMethod;
	for (i=0; i < 8; i++)_Context->msg_PasteMethod[i]=" ";
	_Context->msg_PasteMethod[0]=en_PasteMethod;
	_Context->msg_PasteMethod[1]=fr_PasteMethod;
	_Context->msg_PasteMethod[2]=it_PasteMethod;
	_Context->msg_PasteMethod[3]=es_PasteMethod;
	_Context->msg_PasteMethod[4]=de_PasteMethod;
	_Context->msg_PasteMethod[5]=nl_PasteMethod;
	_Context->msg_PasteMethod[6]=pt_PasteMethod;
	_Context->msg_PasteMethod[7]=xx_PasteMethod;
	_Context->hint_PasteMethod[0]=en__PasteMethod;
	_Context->hint_PasteMethod[1]=fr__PasteMethod;
	_Context->hint_PasteMethod[2]=it__PasteMethod;
	_Context->hint_PasteMethod[3]=es__PasteMethod;
	_Context->hint_PasteMethod[4]=de__PasteMethod;
	_Context->hint_PasteMethod[5]=nl__PasteMethod;
	_Context->hint_PasteMethod[6]=pt__PasteMethod;
	_Context->hint_PasteMethod[7]=xx__PasteMethod;
	_Context->s_PasteMethod=0;
	_Context->p_PasteMethod=visual_buffer(_Context->x_Auto3559+380,_Context->y_Auto3559+490,126+2,32+2);
	for (i=0; i < 8; i++)_Context->msg_CopyMethod[i]=" ";
	_Context->msg_CopyMethod[0]=en_CopyMethod;
	_Context->msg_CopyMethod[1]=fr_CopyMethod;
	_Context->msg_CopyMethod[2]=it_CopyMethod;
	_Context->msg_CopyMethod[3]=es_CopyMethod;
	_Context->msg_CopyMethod[4]=de_CopyMethod;
	_Context->msg_CopyMethod[5]=nl_CopyMethod;
	_Context->msg_CopyMethod[6]=pt_CopyMethod;
	_Context->msg_CopyMethod[7]=xx_CopyMethod;
	_Context->hint_CopyMethod[0]=en__CopyMethod;
	_Context->hint_CopyMethod[1]=fr__CopyMethod;
	_Context->hint_CopyMethod[2]=it__CopyMethod;
	_Context->hint_CopyMethod[3]=es__CopyMethod;
	_Context->hint_CopyMethod[4]=de__CopyMethod;
	_Context->hint_CopyMethod[5]=nl__CopyMethod;
	_Context->hint_CopyMethod[6]=pt__CopyMethod;
	_Context->hint_CopyMethod[7]=xx__CopyMethod;
	for (i=0; i < 8; i++)_Context->msg_DropMethod[i]=" ";
	_Context->msg_DropMethod[0]=en_DropMethod;
	_Context->msg_DropMethod[1]=fr_DropMethod;
	_Context->msg_DropMethod[2]=it_DropMethod;
	_Context->msg_DropMethod[3]=es_DropMethod;
	_Context->msg_DropMethod[4]=de_DropMethod;
	_Context->msg_DropMethod[5]=nl_DropMethod;
	_Context->msg_DropMethod[6]=pt_DropMethod;
	_Context->msg_DropMethod[7]=xx_DropMethod;
	_Context->hint_DropMethod[0]=en__DropMethod;
	_Context->hint_DropMethod[1]=fr__DropMethod;
	_Context->hint_DropMethod[2]=it__DropMethod;
	_Context->hint_DropMethod[3]=es__DropMethod;
	_Context->hint_DropMethod[4]=de__DropMethod;
	_Context->hint_DropMethod[5]=nl__DropMethod;
	_Context->hint_DropMethod[6]=pt__DropMethod;
	_Context->hint_DropMethod[7]=xx__DropMethod;
	_Context->max_ScrollBar=1;
	_Context->value_ScrollBar=1;
	_Context->limit_ScrollBar=1;
	_Context->value_ScrollBar=0;
	_Context->limit_ScrollBar=24;
	for (i=0; i < 8; i++)_Context->msg_FormMemberPage[i]=" ";
	_Context->msg_FormMemberPage[0]=en_FormMemberPage;
	_Context->msg_FormMemberPage[1]=fr_FormMemberPage;
	_Context->msg_FormMemberPage[2]=it_FormMemberPage;
	_Context->msg_FormMemberPage[3]=es_FormMemberPage;
	_Context->msg_FormMemberPage[4]=de_FormMemberPage;
	_Context->msg_FormMemberPage[5]=nl_FormMemberPage;
	_Context->msg_FormMemberPage[6]=pt_FormMemberPage;
	_Context->msg_FormMemberPage[7]=xx_FormMemberPage;
	_Context->hint_FormMemberPage[0]=en__FormMemberPage;
	_Context->hint_FormMemberPage[1]=fr__FormMemberPage;
	_Context->hint_FormMemberPage[2]=it__FormMemberPage;
	_Context->hint_FormMemberPage[3]=es__FormMemberPage;
	_Context->hint_FormMemberPage[4]=de__FormMemberPage;
	_Context->hint_FormMemberPage[5]=nl__FormMemberPage;
	_Context->hint_FormMemberPage[6]=pt__FormMemberPage;
	_Context->hint_FormMemberPage[7]=xx__FormMemberPage;
	_Context->focus_pages[4]=62;
	for (i=0; i < 8; i++)_Context->msg_TypeSelect[i]=" ";
	_Context->msg_TypeSelect[0]=en_TypeSelect;
	_Context->msg_TypeSelect[1]=fr_TypeSelect;
	_Context->msg_TypeSelect[2]=it_TypeSelect;
	_Context->msg_TypeSelect[3]=es_TypeSelect;
	_Context->msg_TypeSelect[4]=de_TypeSelect;
	_Context->msg_TypeSelect[5]=nl_TypeSelect;
	_Context->msg_TypeSelect[6]=pt_TypeSelect;
	_Context->msg_TypeSelect[7]=xx_TypeSelect;
	_Context->hint_TypeSelect[0]=en__TypeSelect;
	_Context->hint_TypeSelect[1]=fr__TypeSelect;
	_Context->hint_TypeSelect[2]=it__TypeSelect;
	_Context->hint_TypeSelect[3]=es__TypeSelect;
	_Context->hint_TypeSelect[4]=de__TypeSelect;
	_Context->hint_TypeSelect[5]=nl__TypeSelect;
	_Context->hint_TypeSelect[6]=pt__TypeSelect;
	_Context->hint_TypeSelect[7]=xx__TypeSelect;
	_Context->x_TypeSelect=_Context->x_Auto3559+272;
	_Context->y_TypeSelect=_Context->y_Auto3559+50;
	_Context->w_TypeSelect=72;
	_Context->h_TypeSelect=128;
	_Context->fg_TypeSelect=128;
	_Context->bg_TypeSelect=128;
	_Context->fid_TypeSelect=1;
	_Context->s_TypeSelect=0;
	_Context->p_TypeSelect=visual_buffer(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect+2,_Context->h_TypeSelect+2);
	for (i=0; i < 8; i++)_Context->msg_PtrCheck[i]=" ";
	_Context->msg_PtrCheck[0]=en_PtrCheck;
	_Context->msg_PtrCheck[1]=fr_PtrCheck;
	_Context->msg_PtrCheck[2]=it_PtrCheck;
	_Context->msg_PtrCheck[3]=es_PtrCheck;
	_Context->msg_PtrCheck[4]=de_PtrCheck;
	_Context->msg_PtrCheck[5]=nl_PtrCheck;
	_Context->msg_PtrCheck[6]=pt_PtrCheck;
	_Context->msg_PtrCheck[7]=xx_PtrCheck;
	_Context->hint_PtrCheck[0]=en__PtrCheck;
	_Context->hint_PtrCheck[1]=fr__PtrCheck;
	_Context->hint_PtrCheck[2]=it__PtrCheck;
	_Context->hint_PtrCheck[3]=es__PtrCheck;
	_Context->hint_PtrCheck[4]=de__PtrCheck;
	_Context->hint_PtrCheck[5]=nl__PtrCheck;
	_Context->hint_PtrCheck[6]=pt__PtrCheck;
	_Context->hint_PtrCheck[7]=xx__PtrCheck;
	_Context->x_PtrCheck=_Context->x_Auto3559+223;
	_Context->y_PtrCheck=_Context->y_Auto3559+50;
	_Context->w_PtrCheck=48;
	_Context->h_PtrCheck=48;
	_Context->fg_PtrCheck=48;
	_Context->bg_PtrCheck=48;
	_Context->fid_PtrCheck=1;
	for (i=0; i < 8; i++)_Context->msg_FormMembers[i]=" ";
	_Context->msg_FormMembers[0]=en_FormMembers;
	_Context->msg_FormMembers[1]=fr_FormMembers;
	_Context->msg_FormMembers[2]=it_FormMembers;
	_Context->msg_FormMembers[3]=es_FormMembers;
	_Context->msg_FormMembers[4]=de_FormMembers;
	_Context->msg_FormMembers[5]=nl_FormMembers;
	_Context->msg_FormMembers[6]=pt_FormMembers;
	_Context->msg_FormMembers[7]=xx_FormMembers;
	_Context->hint_FormMembers[0]=en__FormMembers;
	_Context->hint_FormMembers[1]=fr__FormMembers;
	_Context->hint_FormMembers[2]=it__FormMembers;
	_Context->hint_FormMembers[3]=es__FormMembers;
	_Context->hint_FormMembers[4]=de__FormMembers;
	_Context->hint_FormMembers[5]=nl__FormMembers;
	_Context->hint_FormMembers[6]=pt__FormMembers;
	_Context->hint_FormMembers[7]=xx__FormMembers;
	if ( 0 > 0 ) { _Context->row_FormMembers=&_Context->buffer_FormMembers[0-1][0]; } ;
	_Context->hint_Kursor[1]=fr__Kursor;
	_Context->x_Kursor=_Context->x_Auto3559+30;
	_Context->y_Kursor=_Context->y_Auto3559+70;
	_Context->w_Kursor=710;
	_Context->h_Kursor=20;
	_Context->fg_Kursor=20;
	_Context->bg_Kursor=20;
	_Context->fid_Kursor=1;
	_Context->max_MemberBar=1;
	_Context->value_MemberBar=1;
	_Context->limit_MemberBar=1;
	_Context->value_MemberBar=0;
	_Context->limit_MemberBar=26;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3559,_Context->y_Auto3559,790+10,600+10);
	return(0);
}

public 	int	accept_form_control_hide(struct accept_form_control_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=0;
		}
	if ((_Context->p_PasteMethod != (void *) 0)
	&& (_Context->s_PasteMethod != 0)) {
		(void)visual_buffer_put(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
		_Context->s_PasteMethod=0;
		}
	if ((_Context->p_DefaultBreak != (void *) 0)
	&& (_Context->s_DefaultBreak != 0)) {
		(void)visual_buffer_put(_Context->p_DefaultBreak,_Context->x_Auto3559+40,_Context->y_Auto3559+490);
		_Context->s_DefaultBreak=0;
		}
	if ((_Context->p_Tabulation != (void *) 0)
	&& (_Context->s_Tabulation != 0)) {
		(void)visual_buffer_put(_Context->p_Tabulation,_Context->x_Auto3559+40,_Context->y_Auto3559+430);
		_Context->s_Tabulation=0;
		}
	if ((_Context->p_DownArrow != (void *) 0)
	&& (_Context->s_DownArrow != 0)) {
		(void)visual_buffer_put(_Context->p_DownArrow,_Context->x_Auto3559+40,_Context->y_Auto3559+400);
		_Context->s_DownArrow=0;
		}
	if ((_Context->p_UpArrow != (void *) 0)
	&& (_Context->s_UpArrow != 0)) {
		(void)visual_buffer_put(_Context->p_UpArrow,_Context->x_Auto3559+40,_Context->y_Auto3559+370);
		_Context->s_UpArrow=0;
		}
	if ((_Context->p_PageDown != (void *) 0)
	&& (_Context->s_PageDown != 0)) {
		(void)visual_buffer_put(_Context->p_PageDown,_Context->x_Auto3559+40,_Context->y_Auto3559+340);
		_Context->s_PageDown=0;
		}
	if ((_Context->p_PageUp != (void *) 0)
	&& (_Context->s_PageUp != 0)) {
		(void)visual_buffer_put(_Context->p_PageUp,_Context->x_Auto3559+40,_Context->y_Auto3559+310);
		_Context->s_PageUp=0;
		}
	if ((_Context->p_Enter != (void *) 0)
	&& (_Context->s_Enter != 0)) {
		(void)visual_buffer_put(_Context->p_Enter,_Context->x_Auto3559+40,_Context->y_Auto3559+460);
		_Context->s_Enter=0;
		}
	if ((_Context->p_Escape != (void *) 0)
	&& (_Context->s_Escape != 0)) {
		(void)visual_buffer_put(_Context->p_Escape,_Context->x_Auto3559+40,_Context->y_Auto3559+280);
		_Context->s_Escape=0;
		}
	if ((_Context->p_Overlay != (void *) 0)
	&& (_Context->s_Overlay != 0)) {
		(void)visual_buffer_put(_Context->p_Overlay,_Context->x_Auto3559+400,_Context->y_Auto3559+160);
		_Context->s_Overlay=0;
		}
	if ((_Context->p_Program != (void *) 0)
	&& (_Context->s_Program != 0)) {
		(void)visual_buffer_put(_Context->p_Program,_Context->x_Auto3559+50,_Context->y_Auto3559+160);
		_Context->s_Program=0;
		}
	if ((_Context->p_ProductionLanguage != (void *) 0)
	&& (_Context->s_ProductionLanguage != 0)) {
		(void)visual_buffer_put(_Context->p_ProductionLanguage,_Context->x_Auto3559+200,_Context->y_Auto3559+120);
		_Context->s_ProductionLanguage=0;
		}
	if ((_Context->p_FormType != (void *) 0)
	&& (_Context->s_FormType != 0)) {
		(void)visual_buffer_put(_Context->p_FormType,_Context->x_Auto3559+50,_Context->y_Auto3559+120);
		_Context->s_FormType=0;
		}
	if ((_Context->p_FormControl != (void *) 0)
	&& (_Context->s_FormControl != 0)) {
		(void)visual_buffer_put(_Context->p_FormControl,_Context->x_Auto3559+10,_Context->y_Auto3559+30);
		_Context->s_FormControl=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3559,_Context->y_Auto3559);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_form_control_remove(
	struct accept_form_control_context * _Context,
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pConstants,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pDynamic,
	char * pCommandLine,
	char * pArgVLen,
	char * pArgVNb,
	char * pResize,
	char * pResizeX,
	char * pResizeY,
	char * pGenHelp,
	char * pActHelp,
	char * pFileName,
	char * pIdentity,
	char * pStyleSheet,
	char * pPaletteName,
	char * pClearScreen,
	char * pSendLeft,
	char * pSendMiddle,
	char * pSendRight,
	char * pSendWheel,
	char * pButtonFilter,
	char * pSendDown,
	char * pSendUp,
	char * pSendWhileDown,
	char * pSendMove,
	char * pMouseKey,
	char * pWidgetTriggers,
	char * pEscape,
	char * pEnter,
	char * pPageUp,
	char * pPageDown,
	char * pUpArrow,
	char * pDownArrow,
	char * pTabulation,
	char * pDefaultBreak)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_TypeSelect != (void *) 0)
		_Context->p_TypeSelect = visual_drop(_Context->p_TypeSelect);
	if (_Context->p_PasteMethod != (void *) 0)
		_Context->p_PasteMethod = visual_drop(_Context->p_PasteMethod);
	if (_Context->p_DefaultBreak != (void *) 0)
		_Context->p_DefaultBreak = visual_drop(_Context->p_DefaultBreak);
	if (_Context->p_Tabulation != (void *) 0)
		_Context->p_Tabulation = visual_drop(_Context->p_Tabulation);
	if (_Context->p_DownArrow != (void *) 0)
		_Context->p_DownArrow = visual_drop(_Context->p_DownArrow);
	if (_Context->p_UpArrow != (void *) 0)
		_Context->p_UpArrow = visual_drop(_Context->p_UpArrow);
	if (_Context->p_PageDown != (void *) 0)
		_Context->p_PageDown = visual_drop(_Context->p_PageDown);
	if (_Context->p_PageUp != (void *) 0)
		_Context->p_PageUp = visual_drop(_Context->p_PageUp);
	if (_Context->p_Enter != (void *) 0)
		_Context->p_Enter = visual_drop(_Context->p_Enter);
	if (_Context->p_Escape != (void *) 0)
		_Context->p_Escape = visual_drop(_Context->p_Escape);
	if (_Context->p_Overlay != (void *) 0)
		_Context->p_Overlay = visual_drop(_Context->p_Overlay);
	if (_Context->p_Program != (void *) 0)
		_Context->p_Program = visual_drop(_Context->p_Program);
	if (_Context->p_ProductionLanguage != (void *) 0)
		_Context->p_ProductionLanguage = visual_drop(_Context->p_ProductionLanguage);
	if (_Context->p_FormType != (void *) 0)
		_Context->p_FormType = visual_drop(_Context->p_FormType);
	if (_Context->p_FormControl != (void *) 0)
		_Context->p_FormControl = visual_drop(_Context->p_FormControl);
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWWWWWWWWWWWWWWWSSSSSWWWWWWWWWWWWWWWWWWW");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pFormType);
		if ( pFormType != (char *) 0)
			*((int*)pFormType) = _Context->value_FormType;
		visual_transferout((void *) 0, 0, pProductionLanguage);
		if ( pProductionLanguage != (char *) 0)
			*((int*)pProductionLanguage) = _Context->value_ProductionLanguage;
		visual_transferout((void *) 0, 0, pNationalLanguage);
		if ( pNationalLanguage != (char *) 0)
			*((int*)pNationalLanguage) = _Context->value_NationalLanguage;
		visual_transferout((void *) 0, 0, pInternational);
		if ( pInternational != (char *) 0)
			*((int*)pInternational) = _Context->value_International;
		visual_transferout((void *) 0, 0, pConstants);
		if ( pConstants != (char *) 0)
			*((int*)pConstants) = _Context->value_Constants;
		visual_transferout((void *) 0, 0, pMultipleLanguage);
		if ( pMultipleLanguage != (char *) 0)
			*((int*)pMultipleLanguage) = _Context->value_MultipleLanguage;
		visual_transferout((void *) 0, 0, pProgram);
		if ( pProgram != (char *) 0)
			*((int*)pProgram) = _Context->value_Program;
		visual_transferout((void *) 0, 0, pOverlay);
		if ( pOverlay != (char *) 0)
			*((int*)pOverlay) = _Context->value_Overlay;
		visual_transferout((void *) 0, 0, pPopUp);
		if ( pPopUp != (char *) 0)
			*((int*)pPopUp) = _Context->value_PopUp;
		visual_transferout((void *) 0, 0, pDynamic);
		if ( pDynamic != (char *) 0)
			*((int*)pDynamic) = _Context->value_Dynamic;
		visual_transferout((void *) 0, 0, pCommandLine);
		if ( pCommandLine != (char *) 0)
			*((int*)pCommandLine) = _Context->value_CommandLine;
		visual_transferout(_Context->buffer_ArgVLen, 12, pArgVLen);
		visual_transferout(_Context->buffer_ArgVNb, 13, pArgVNb);
		visual_transferout((void *) 0, 0, pResize);
		if ( pResize != (char *) 0)
			*((int*)pResize) = _Context->value_Resize;
		visual_transferout(_Context->buffer_ResizeX, 9, pResizeX);
		visual_transferout(_Context->buffer_ResizeY, 9, pResizeY);
		visual_transferout((void *) 0, 0, pGenHelp);
		if ( pGenHelp != (char *) 0)
			*((int*)pGenHelp) = _Context->value_GenHelp;
		visual_transferout((void *) 0, 0, pActHelp);
		if ( pActHelp != (char *) 0)
			*((int*)pActHelp) = _Context->value_ActHelp;
		visual_transferout(_Context->buffer_FileName, 255, pFileName);
		visual_transferout(_Context->buffer_Identity, 255, pIdentity);
		visual_transferout(_Context->buffer_StyleSheet, 255, pStyleSheet);
		visual_transferout(_Context->buffer_PaletteName, 255, pPaletteName);
		visual_transferout(_Context->buffer_ClearScreen, 255, pClearScreen);
		visual_transferout((void *) 0, 0, pSendLeft);
		if ( pSendLeft != (char *) 0)
			*((int*)pSendLeft) = _Context->value_SendLeft;
		visual_transferout((void *) 0, 0, pSendMiddle);
		if ( pSendMiddle != (char *) 0)
			*((int*)pSendMiddle) = _Context->value_SendMiddle;
		visual_transferout((void *) 0, 0, pSendRight);
		if ( pSendRight != (char *) 0)
			*((int*)pSendRight) = _Context->value_SendRight;
		visual_transferout((void *) 0, 0, pSendWheel);
		if ( pSendWheel != (char *) 0)
			*((int*)pSendWheel) = _Context->value_SendWheel;
		visual_transferout((void *) 0, 0, pButtonFilter);
		if ( pButtonFilter != (char *) 0)
			*((int*)pButtonFilter) = _Context->value_ButtonFilter;
		visual_transferout((void *) 0, 0, pSendDown);
		if ( pSendDown != (char *) 0)
			*((int*)pSendDown) = _Context->value_SendDown;
		visual_transferout((void *) 0, 0, pSendUp);
		if ( pSendUp != (char *) 0)
			*((int*)pSendUp) = _Context->value_SendUp;
		visual_transferout((void *) 0, 0, pSendWhileDown);
		if ( pSendWhileDown != (char *) 0)
			*((int*)pSendWhileDown) = _Context->value_SendWhileDown;
		visual_transferout((void *) 0, 0, pSendMove);
		if ( pSendMove != (char *) 0)
			*((int*)pSendMove) = _Context->value_SendMove;
		visual_transferout((void *) 0, 0, pMouseKey);
		if ( pMouseKey != (char *) 0)
			*((int*)pMouseKey) = _Context->value_MouseKey;
		visual_transferout((void *) 0, 0, pWidgetTriggers);
		if ( pWidgetTriggers != (char *) 0)
			*((int*)pWidgetTriggers) = _Context->value_WidgetTriggers;
		visual_transferout((void *) 0, 0, pEscape);
		if ( pEscape != (char *) 0)
			*((int*)pEscape) = _Context->value_Escape;
		visual_transferout((void *) 0, 0, pEnter);
		if ( pEnter != (char *) 0)
			*((int*)pEnter) = _Context->value_Enter;
		visual_transferout((void *) 0, 0, pPageUp);
		if ( pPageUp != (char *) 0)
			*((int*)pPageUp) = _Context->value_PageUp;
		visual_transferout((void *) 0, 0, pPageDown);
		if ( pPageDown != (char *) 0)
			*((int*)pPageDown) = _Context->value_PageDown;
		visual_transferout((void *) 0, 0, pUpArrow);
		if ( pUpArrow != (char *) 0)
			*((int*)pUpArrow) = _Context->value_UpArrow;
		visual_transferout((void *) 0, 0, pDownArrow);
		if ( pDownArrow != (char *) 0)
			*((int*)pDownArrow) = _Context->value_DownArrow;
		visual_transferout((void *) 0, 0, pTabulation);
		if ( pTabulation != (char *) 0)
			*((int*)pTabulation) = _Context->value_Tabulation;
		visual_transferout((void *) 0, 0, pDefaultBreak);
		if ( pDefaultBreak != (char *) 0)
			*((int*)pDefaultBreak) = _Context->value_DefaultBreak;
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Methods_show(struct accept_form_control_context * _Context) {
	int l;
	int n;
	int m;
	n=forms_method_count();
	start_sort_Methods(_Context,n);
	for(l=1;l<=n;l++)
	{
	if ( l > 0 ) { _Context->row_Methods=&_Context->libsort_Methods[(l-1)*88]; } ;
	get_forms_method_information(
	l,
	(_Context->row_Methods+0),17,
	(_Context->row_Methods+17),33,
	(_Context->row_Methods+50),38,
	(char*)0,0);
	};
	sort_Methods(_Context,n);
	if(!(n=_Context->value_Methods))
	n=1;
	for(l=1;l<=24;l++){
	if ( l > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[l-1][0]; } ;
	m=l+_Context->value_ScrollBar;
	m=sort_item_Methods(_Context,m);
	get_forms_method_information(
	m,
	(_Context->row_Methods+0),17,
	(_Context->row_Methods+17),33,
	(_Context->row_Methods+50),38,
	(char*)0,0);
	}
		visual_table(_Context->x_Auto3559+30,_Context->y_Auto3559+70,710,410,vfh[1],0,0,_Context->msg_Methods[_Context->language],_Context->buffer_Methods,0x4401,"(W16,W32,$)");
;
	_Context->x_Cursor=_Context->x_Auto3559+30;
	_Context->y_Cursor=_Context->y_Auto3559+70+(n*16);
	_Context->w_Cursor=710;
	_Context->value_Methods=n;
		visual_filzone(_Context->x_Cursor,_Context->y_Cursor,_Context->w_Cursor,_Context->h_Cursor,7453,16);
;
		return(-1);
}
private int on_PasteMethod_show(struct accept_form_control_context * _Context) {
	if(!(valid_copied_method())){
		if ((_Context->p_PasteMethod != (void *) 0)
	&& (_Context->s_PasteMethod != 0)) {
		(void)visual_buffer_put(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
		_Context->s_PasteMethod=0;
		}
;
	}
	else{
		if ((_Context->p_PasteMethod != (void *) 0)
	&& (_Context->s_PasteMethod == 0)) {
		(void)visual_buffer_get(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
		_Context->s_PasteMethod=1;
		}
	if ((_Context->p_PasteMethod != (void *) 0)
	&& (_Context->s_PasteMethod == 0)) {
		(void)visual_buffer_get(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
		_Context->s_PasteMethod=1;
		}
	_Context->trigger_PasteMethod=visual_trigger_code(_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+380,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]),0);
;
	}
	return(-1);
}
private int on_ScrollBar_show(struct accept_form_control_context * _Context) {
	_Context->max_ScrollBar=forms_method_count()+(24/2);
		visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,3);
;
	return(-1);
}
private int on_FormMembers_show(struct accept_form_control_context * _Context) {
	struct forms_data_member*get_forms_member(int);
	struct forms_data_member*dptr;
	int l;
	int i;
	int n;
	int m;
	int holdline;
	m=_Context->formsort_FormMembers;
	sort_data_member(m);
	if(!(n=_Context->value_FormMembers))
	n=1;
	holdline=n;
	memset(_Context->buffer_FormMembers,' ',2288);
	for(l=1;l<=26;l++){
	if(!(dptr=get_forms_member(l+_Context->value_MemberBar)))
	continue;
	if ( l > 0 ) { _Context->row_FormMembers=&_Context->buffer_FormMembers[l-1][0]; } ;
	if(dptr->name!=(char*)0)
	putstring(_Context, (_Context->row_FormMembers+0),24,dptr->name);
	else putstring(_Context, (_Context->row_FormMembers+0),24," ");
	switch((dptr->type&0x18)>>3){/*GWB le 21/09/2006*/
	case 0:
	putstring(_Context, (_Context->row_FormMembers+24),6,"dcl");
	break;
	case 1:
	putstring(_Context, (_Context->row_FormMembers+24),6,"ptr");
	break;
	case 2:
	putstring(_Context, (_Context->row_FormMembers+24),6,"const");
	break;
	}
	switch(dptr->type&7){
	case _ABAL_FIELD:
	putstring(_Context, (_Context->row_FormMembers+30),9,"field");
	break;
	case _ABAL_FILLER:
	putstring(_Context, (_Context->row_FormMembers+30),9,"filler");
	sprintf((_Context->row_FormMembers+39),"%u",dptr->size);
	break;
		case _ABAL_BYTE:
	putstring(_Context, (_Context->row_FormMembers+30),9,"byte");
	sprintf((_Context->row_FormMembers+39),"%u",1);
	break;
	case _ABAL_WORD:
	putstring(_Context, (_Context->row_FormMembers+30),9,"word");
	sprintf((_Context->row_FormMembers+39),"%u",2);
	break;
	case _ABAL_LONG:
	putstring(_Context, (_Context->row_FormMembers+30),9,"long");
	sprintf((_Context->row_FormMembers+39),"%u",4);
	break;
	case _ABAL_BCD:
	putstring(_Context, (_Context->row_FormMembers+30),9,"bcd");
	sprintf((_Context->row_FormMembers+39),"%u",dptr->size);
	break;
	case _ABAL_STRING:
	putstring(_Context, (_Context->row_FormMembers+30),9,"string");
	sprintf((_Context->row_FormMembers+39),"%u",dptr->size);
	break;
	}
	sprintf((_Context->row_FormMembers+45),"%u",dptr->first);
	sprintf((_Context->row_FormMembers+51),"%u",dptr->second);
	if(method_is_valid(dptr->comment))
	putstring(_Context, (_Context->row_FormMembers+57),31,dptr->comment);
	else
	putstring(_Context, (_Context->row_FormMembers+57),31," ");
	}
		visual_table(_Context->x_Auto3559+30,_Context->y_Auto3559+70,710,450,vfh[1],0,0,_Context->msg_FormMembers[_Context->language],_Context->buffer_FormMembers,0x4401,"($,W5,W8,N4Z,N4Z,N4Z,w30)");
;
	_Context->x_Kursor=_Context->x_Auto3559+30;
	_Context->y_Kursor=_Context->y_Auto3559+70+(holdline*16);
	_Context->w_Kursor=710;
	_Context->h_Kursor=16;
	_Context->value_FormMembers=holdline;
		visual_filzone(_Context->x_Kursor,_Context->y_Kursor,_Context->w_Kursor,_Context->h_Kursor,7453,16);
;
	return(-1);
}
private int on_MemberBar_show(struct accept_form_control_context * _Context) {
	_Context->max_MemberBar=forms_member_count()+(26/2);
		visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,3);
;
	return(-1);
}

public	int	accept_form_control_show(struct accept_form_control_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3559,_Context->y_Auto3559);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto3559,_Context->y_Auto3559,790,600,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
	visual_image(_Context->x_Auto3559+3,_Context->y_Auto3559+22,784,574,_Context->msg_Auto3560[_Context->language],4);
	if (_Context->page_number == 1 ) {
	if ((_Context->p_FormControl != (void *) 0)
	&& (_Context->s_FormControl == 0)) {
		(void)visual_buffer_get(_Context->p_FormControl,_Context->x_Auto3559+10,_Context->y_Auto3559+30);
		_Context->s_FormControl=1;
		}
	_Context->trigger_FormControl=visual_trigger_code(_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]));
	visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_FormControl[_Context->language],strlen(_Context->msg_FormControl[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+20,_Context->y_Auto3559+70,750,16,vfh[2],16,0,_Context->msg_Auto3561[_Context->language],strlen(_Context->msg_Auto3561[_Context->language]),258);
	visual_frame(_Context->x_Auto3559+20,_Context->y_Auto3559+86,750,254,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+20,_Context->y_Auto3559+340,750,180,4);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+330,_Context->y_Auto3559+280,70,16,vfh[2],16,0,_Context->msg_Auto3563[_Context->language],strlen(_Context->msg_Auto3563[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+330,_Context->y_Auto3559+310,70,16,vfh[2],16,0,_Context->msg_Auto3564[_Context->language],strlen(_Context->msg_Auto3564[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+480,_Context->y_Auto3559+310,56,16,vfh[2],16,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+500,_Context->y_Auto3559+280,14,16,vfh[2],16,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+620,_Context->y_Auto3559+280,14,16,vfh[2],16,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),2);
		}
	_Context->trigger_Auto3568=visual_trigger_code(_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]));
	visual_button(_Context->x_Auto3559+10,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]),1040);
	_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1040);
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+50,_Context->y_Auto3559+100,140,16,vfh[2],16,0,_Context->msg_Auto3570[_Context->language],strlen(_Context->msg_Auto3570[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+200,_Context->y_Auto3559+100,140,16,vfh[2],16,0,_Context->msg_Auto3571[_Context->language],strlen(_Context->msg_Auto3571[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+350,_Context->y_Auto3559+100,140,16,vfh[2],16,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_FormType != (void *) 0)
	&& (_Context->s_FormType == 0)) {
		(void)visual_buffer_get(_Context->p_FormType,_Context->x_Auto3559+50,_Context->y_Auto3559+120);
		_Context->s_FormType=1;
		}
	visual_select(_Context->x_Auto3559+50,_Context->y_Auto3559+120,140,144,vfh[2],27,0,parse_selection(FormTypeList,&_Context->value_FormType),768);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_ProductionLanguage != (void *) 0)
	&& (_Context->s_ProductionLanguage == 0)) {
		(void)visual_buffer_get(_Context->p_ProductionLanguage,_Context->x_Auto3559+200,_Context->y_Auto3559+120);
		_Context->s_ProductionLanguage=1;
		}
	visual_select(_Context->x_Auto3559+200,_Context->y_Auto3559+120,140,144,vfh[2],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),768);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto3559+350,_Context->y_Auto3559+120,140,144,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_International=visual_trigger_code(_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+190,322,16,vfh[2],28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),_Context->value_International|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Constants=visual_trigger_code(_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+220,294,16,vfh[2],28,28,_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]),_Context->value_Constants|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_MultipleLanguage=visual_trigger_code(_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+190,280,16,vfh[2],28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),_Context->value_MultipleLanguage|0);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_Program != (void *) 0)
	&& (_Context->s_Program == 0)) {
		(void)visual_buffer_get(_Context->p_Program,_Context->x_Auto3559+50,_Context->y_Auto3559+160);
		_Context->s_Program=1;
		}
	_Context->trigger_Program=visual_trigger_code(_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+160,322,16,vfh[2],27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),_Context->value_Program|0);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_Overlay != (void *) 0)
	&& (_Context->s_Overlay == 0)) {
		(void)visual_buffer_get(_Context->p_Overlay,_Context->x_Auto3559+400,_Context->y_Auto3559+160);
		_Context->s_Overlay=1;
		}
	_Context->trigger_Overlay=visual_trigger_code(_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+160,280,16,vfh[2],27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),_Context->value_Overlay|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_PopUp=visual_trigger_code(_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+220,294,16,vfh[2],27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),_Context->value_PopUp|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Dynamic=visual_trigger_code(_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+250,280,16,vfh[2],27,0,_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]),_Context->value_Dynamic|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_CommandLine=visual_trigger_code(_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+280,266,16,vfh[2],28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),_Context->value_CommandLine|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+400,_Context->y_Auto3559+280,96+2,16+2,5);
	visual_text(_Context->x_Auto3559+400+1,_Context->y_Auto3559+280+1,96,16,vfh[1],0,0,_Context->buffer_ArgVLen,12,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+510,_Context->y_Auto3559+280,104+2,16+2,5);
	visual_text(_Context->x_Auto3559+510+1,_Context->y_Auto3559+280+1,104,16,vfh[1],0,0,_Context->buffer_ArgVNb,13,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Resize=visual_trigger_code(_Context->msg_Resize[_Context->language],strlen(_Context->msg_Resize[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+310,264,16,vfh[2],27,28,_Context->msg_Resize[_Context->language],strlen(_Context->msg_Resize[_Context->language]),_Context->value_Resize|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+400,_Context->y_Auto3559+310,72+2,16+2,5);
	visual_text(_Context->x_Auto3559+400+1,_Context->y_Auto3559+310+1,72,16,vfh[1],0,0,_Context->buffer_ResizeX,9,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+540,_Context->y_Auto3559+310,72+2,16+2,5);
	visual_text(_Context->x_Auto3559+540+1,_Context->y_Auto3559+310+1,72,16,vfh[1],0,0,_Context->buffer_ResizeY,9,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto3559+510,_Context->y_Auto3559+120,112,48,vfh[2],0,0,parse_selection(_Context->msg_GenHelp[_Context->language],&_Context->value_GenHelp),768);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto3559+630,_Context->y_Auto3559+120,112,48,vfh[2],0,0,parse_selection(_Context->msg_ActHelp[_Context->language],&_Context->value_ActHelp),768);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+510,_Context->y_Auto3559+100,238,16,vfh[2],16,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),259);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+40,_Context->y_Auto3559+350,686,16,vfh[2],16,0,_Context->msg_auto7[_Context->language],strlen(_Context->msg_auto7[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+40,_Context->y_Auto3559+400,336,16,vfh[2],16,0,_Context->msg_auto52[_Context->language],strlen(_Context->msg_auto52[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+40,_Context->y_Auto3559+450,336,16,vfh[2],16,0,_Context->msg_Auto3574[_Context->language],strlen(_Context->msg_Auto3574[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+380,_Context->y_Auto3559+450,336,16,vfh[2],16,0,_Context->msg_Auto3575[_Context->language],strlen(_Context->msg_Auto3575[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+40,_Context->y_Auto3559+370,672+2,16+2,5);
	visual_text(_Context->x_Auto3559+40+1,_Context->y_Auto3559+370+1,672,16,vfh[1],34,0,_Context->buffer_FileName,255,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChooseFileName=visual_trigger_code(_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+370,32,16,vfh[8],27,28,_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+470,32,16,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_EditSource=visual_trigger_code(_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+390,32,16,vfh[8],27,28,_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+490,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+40,_Context->y_Auto3559+420,336+2,16+2,5);
	visual_text(_Context->x_Auto3559+40+1,_Context->y_Auto3559+420+1,336,16,vfh[1],34,0,_Context->buffer_Identity,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+40,_Context->y_Auto3559+470,336+2,16+2,5);
	visual_text(_Context->x_Auto3559+40+1,_Context->y_Auto3559+470+1,336,16,vfh[1],0,0,_Context->buffer_StyleSheet,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3559+380,_Context->y_Auto3559+400,336,16,vfh[2],16,0,_Context->msg_Auto3576[_Context->language],strlen(_Context->msg_Auto3576[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoosePalette=visual_trigger_code(_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+420,36,16,vfh[8],27,28,_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+380,_Context->y_Auto3559+420,336+2,16+2,5);
	visual_text(_Context->x_Auto3559+380+1,_Context->y_Auto3559+420+1,336,16,vfh[1],0,0,_Context->buffer_PaletteName,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3559+380,_Context->y_Auto3559+470,336+2,16+2,5);
	visual_text(_Context->x_Auto3559+380+1,_Context->y_Auto3559+470+1,336,16,vfh[1],0,0,_Context->buffer_ClearScreen,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_MouseEvents=visual_trigger_code(_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]));
	visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]),134,2);
	} else {
		visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_MouseEvents[_Context->language],strlen(_Context->msg_MouseEvents[_Context->language]),134,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3559+20,_Context->y_Auto3559+70,740,16,vfh[2],16,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),258);
	visual_frame(_Context->x_Auto3559+20,_Context->y_Auto3559+86,740,64,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3559+20,_Context->y_Auto3559+160,740,16,vfh[2],16,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),258);
	visual_frame(_Context->x_Auto3559+20,_Context->y_Auto3559+176,740,64,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3559+20,_Context->y_Auto3559+250,740,16,vfh[2],16,0,_Context->msg_Auto3579[_Context->language],strlen(_Context->msg_Auto3579[_Context->language]),258);
	visual_frame(_Context->x_Auto3559+20,_Context->y_Auto3559+266,740,254,4);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendLeft=visual_trigger_code(_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+100,238,16,vfh[2],27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),_Context->value_SendLeft|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendMiddle=visual_trigger_code(_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+100,210,16,vfh[2],27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),_Context->value_SendMiddle|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendRight=visual_trigger_code(_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+120,224,16,vfh[2],27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),_Context->value_SendRight|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendWheel=visual_trigger_code(_Context->msg_SendWheel[_Context->language],strlen(_Context->msg_SendWheel[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+120,224,16,vfh[2],27,0,_Context->msg_SendWheel[_Context->language],strlen(_Context->msg_SendWheel[_Context->language]),_Context->value_SendWheel|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ButtonFilter=visual_trigger_code(_Context->msg_ButtonFilter[_Context->language],strlen(_Context->msg_ButtonFilter[_Context->language]));
	visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+100,224,16,vfh[2],27,0,_Context->msg_ButtonFilter[_Context->language],strlen(_Context->msg_ButtonFilter[_Context->language]),_Context->value_ButtonFilter|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendDown=visual_trigger_code(_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+190,224,16,vfh[2],27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),_Context->value_SendDown|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendUp=visual_trigger_code(_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+190,196,16,vfh[2],27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),_Context->value_SendUp|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendWhileDown=visual_trigger_code(_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+210,238,16,vfh[2],27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),_Context->value_SendWhileDown|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SendMove=visual_trigger_code(_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+210,196,16,vfh[2],16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),_Context->value_SendMove|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_MouseKey=visual_trigger_code(_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]));
	visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+190,196,16,vfh[2],16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),_Context->value_MouseKey|0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_WidgetTriggers=visual_trigger_code(_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]));
	visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+210,210,16,vfh[2],16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),_Context->value_WidgetTriggers|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_Escape != (void *) 0)
	&& (_Context->s_Escape == 0)) {
		(void)visual_buffer_get(_Context->p_Escape,_Context->x_Auto3559+40,_Context->y_Auto3559+280);
		_Context->s_Escape=1;
		}
	_Context->trigger_Escape=visual_trigger_code(_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+280,700,16,vfh[2],27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),_Context->value_Escape|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_Enter != (void *) 0)
	&& (_Context->s_Enter == 0)) {
		(void)visual_buffer_get(_Context->p_Enter,_Context->x_Auto3559+40,_Context->y_Auto3559+460);
		_Context->s_Enter=1;
		}
	_Context->trigger_Enter=visual_trigger_code(_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+460,700,16,vfh[2],27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),_Context->value_Enter|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_PageUp != (void *) 0)
	&& (_Context->s_PageUp == 0)) {
		(void)visual_buffer_get(_Context->p_PageUp,_Context->x_Auto3559+40,_Context->y_Auto3559+310);
		_Context->s_PageUp=1;
		}
	_Context->trigger_PageUp=visual_trigger_code(_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+310,700,16,vfh[2],27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),_Context->value_PageUp|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_PageDown != (void *) 0)
	&& (_Context->s_PageDown == 0)) {
		(void)visual_buffer_get(_Context->p_PageDown,_Context->x_Auto3559+40,_Context->y_Auto3559+340);
		_Context->s_PageDown=1;
		}
	_Context->trigger_PageDown=visual_trigger_code(_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+340,700,16,vfh[2],27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),_Context->value_PageDown|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_UpArrow != (void *) 0)
	&& (_Context->s_UpArrow == 0)) {
		(void)visual_buffer_get(_Context->p_UpArrow,_Context->x_Auto3559+40,_Context->y_Auto3559+370);
		_Context->s_UpArrow=1;
		}
	_Context->trigger_UpArrow=visual_trigger_code(_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+370,700,16,vfh[2],27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),_Context->value_UpArrow|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_DownArrow != (void *) 0)
	&& (_Context->s_DownArrow == 0)) {
		(void)visual_buffer_get(_Context->p_DownArrow,_Context->x_Auto3559+40,_Context->y_Auto3559+400);
		_Context->s_DownArrow=1;
		}
	_Context->trigger_DownArrow=visual_trigger_code(_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+400,700,16,vfh[2],27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),_Context->value_DownArrow|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_Tabulation != (void *) 0)
	&& (_Context->s_Tabulation == 0)) {
		(void)visual_buffer_get(_Context->p_Tabulation,_Context->x_Auto3559+40,_Context->y_Auto3559+430);
		_Context->s_Tabulation=1;
		}
	_Context->trigger_Tabulation=visual_trigger_code(_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+430,700,16,vfh[2],27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),_Context->value_Tabulation|0);
		}
	if (_Context->page_number == 2 ) {
	if ((_Context->p_DefaultBreak != (void *) 0)
	&& (_Context->s_DefaultBreak == 0)) {
		(void)visual_buffer_get(_Context->p_DefaultBreak,_Context->x_Auto3559+40,_Context->y_Auto3559+490);
		_Context->s_DefaultBreak=1;
		}
	_Context->trigger_DefaultBreak=visual_trigger_code(_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+490,700,16,vfh[2],27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),_Context->value_DefaultBreak|0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_FormMethods=visual_trigger_code(_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]));
	visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]),265,2);
	} else {
		visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_FormMethods[_Context->language],strlen(_Context->msg_FormMethods[_Context->language]),265,0);
		}
	if (_Context->page_number == 3 ) {
	(void) on_Methods_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_EditMethod=visual_trigger_code(_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+30,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	if ((_Context->p_PasteMethod != (void *) 0)
	&& (_Context->s_PasteMethod == 0)) {
		(void)visual_buffer_get(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
		_Context->s_PasteMethod=1;
		}
	(void) on_PasteMethod_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_CopyMethod=visual_trigger_code(_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+250,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DropMethod=visual_trigger_code(_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+610,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	(void) on_ScrollBar_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_FormMemberPage=visual_trigger_code(_Context->msg_FormMemberPage[_Context->language],strlen(_Context->msg_FormMemberPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_FormMemberPage[_Context->language],strlen(_Context->msg_FormMemberPage[_Context->language]),401,2);
	} else {
		visual_tabpage(_Context->x_Auto3559+10,_Context->y_Auto3559+30,770,500,vfh[2],_Context->msg_FormMemberPage[_Context->language],strlen(_Context->msg_FormMemberPage[_Context->language]),401,0);
		}
	if (_Context->page_number == 4 ) {
	(void) on_FormMembers_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	(void) on_MemberBar_show(_Context);
		}
	visual_thaw(_Context->x_Auto3559,_Context->y_Auto3559,790,600);

	return(0);
}

private int FormControl_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This tab page presents the visual forms model general production parameters. ";
			mptr[1]=" ";
			mptr[2]=" ";
			mptr[3]="These various parameters influence the source production mechanisms ";
			mptr[4]="of sing as described for each individual control.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3568_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the ACCEPT button any changes made to the various    parameters ";
			mptr[1]="will take effect.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3569_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing the CANCEL button any modifications performed will be ";
			mptr[1]="   discarded.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FormType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This select control defines the production nature or application scenario ";
			mptr[1]="of the visual forms model.  ";
			mptr[2]=" ";
			mptr[3]="In the current version of the visual design tool the choice is limited ";
			mptr[4]="to either dialog box or draft document. ";
			mptr[5]=" ";
			mptr[6]=" The suplementary types event driven and high quality document being ";
			mptr[7]="available in a future version of the product.   ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ProductionLanguage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This select control allows the definition of the production language ";
			mptr[1]="for the visual forms model.  ";
			mptr[2]=" ";
			mptr[3]="In the current version of the visual design tool the following production ";
			mptr[4]=" languages are possible  ";
			mptr[5]=" ";
			mptr[6]="  ";
			mptr[7]="  ";
			mptr[8]=" - Abal  ";
			mptr[9]=" - Abal++  ";
			mptr[10]=" - C  ";
			mptr[11]="  ";
			mptr[12]=" ";
			mptr[13]=" each with their own specificity and production orientations.   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NationalLanguage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This select control allows the national language that is used by the ";
			mptr[1]="visual forms  model to be defined in order to be able to coo-operate ";
			mptr[2]="fully with future  national language conversion tools.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int International_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The check control allows management of multinationalisation or internationalisation ";
			mptr[1]="of forms component payload  messages, titles, textes and images and ";
			mptr[2]="documentation. When this is checked multiple national language messages ";
			mptr[3]="strings  will be saved to the resource file, otherwise only the current ";
			mptr[4]="payload will be saved.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Constants_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The check control allows management of multinationalisation or internationalisation ";
			mptr[1]="of forms component payload  messages, titles, textes and images and ";
			mptr[2]="documentation. When this is checked multiple national language messages ";
			mptr[3]="strings  will be saved to the resource file, otherwise only the current ";
			mptr[4]="payload will be saved.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MultipleLanguage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active the multinational message management ";
			mptr[1]="will be generated to the target source allowing national language ";
			mptr[2]="to be changed dynamiclly during program execution.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Program_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active it indicates that the visual forms ";
			mptr[1]="model will  produce a standalone program type production packaging. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Overlay_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This check control when active works in conjuntion with the state ";
			mptr[1]="of the  preceeding stand alone program check control according to ";
			mptr[2]="the following table  ";
			mptr[3]=" ";
			mptr[4]="   ";
			mptr[5]=" Program Subordinate Description  ";
			mptr[6]=" clear clear Include file package  ";
			mptr[7]=" clear set module file package  ";
			mptr[8]=" set clear program file package  ";
			mptr[9]=" set set program overlay package   ";
			mptr[10]=" ";
			mptr[11]="   ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PopUp_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active the source production will generate ";
			mptr[1]="code for the popup or screen saver mechanisms appropriate to the  ";
			mptr[2]="production language.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Dynamic_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active the source production will generate ";
			mptr[1]="code for the popup or screen saver mechanisms appropriate to the  ";
			mptr[2]="production language.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ArgVLen_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the size of the command line parameter variable ";
			mptr[1]="to be defined. It will only by of importance to programs which require ";
			mptr[2]="reception of command line parameters.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ArgVNb_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the maximum number of command line parameters ";
			mptr[1]="to be defined for programs requiring reception of command line parameters. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The Production Filename field identifies the full path and filename ";
			mptr[1]="of the target  to which the production of source, either ABAL or ABAL++, ";
			mptr[2]="will be generated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		case 1 : 
			{
			char * mptr[3];
			mptr[0] = "Le champ de Nom de Fichier de production ABAL++ identifie le chemin ";
			mptr[1]="complet et le nom de fichier de la cible dans laquelle la production ";
			mptr[2]="de source sera g‚n‚r‚e.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ChooseFileName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button gives access to the File Selection Dialog box for ";
			mptr[1]="the model source production filename.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ChooseStyleName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button gives access to the File Selection Dialog box for ";
			mptr[1]="the style class filename.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditSource_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The production file may be opened in the standard editor by pressing ";
			mptr[1]="on this button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditStyle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The style file may be opened in the standard editor by pressing on ";
			mptr[1]="this button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Identity_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This usage of this edit field value depends on both the production ";
			mptr[1]="language and the production packaging.   ";
			mptr[2]=" ";
			mptr[3]="For ABAL++ production ir provides the class name.  ";
			mptr[4]=" ";
			mptr[5]="For the production of an ABAL module it provides the stub or root ";
			mptr[6]="name of the module interface and support procedures.  ";
			mptr[7]=" ";
			mptr[8]="For ABAL PROGRAM production packages it will be used un the generation ";
			mptr[9]="of the PROGRAM statement.  ";
			mptr[10]=" ";
			mptr[11]="In all cases it will be used as the title and identification of the ";
			mptr[12]="model in html document production.   ";
			return(visual_online_help(mptr,13));
			}
			break;
		case 1 : 
			{
			char * mptr[14];
			mptr[0] = "L'utilisation de la valeur de ce champ d‚pend et du langage de production ";
			mptr[1]="et du l'emballage (packaging) de production.  ";
			mptr[2]=" ";
			mptr[3]="Pour une production ABAL++ il fournit le nom de classe.  ";
			mptr[4]=" ";
			mptr[5]="Pour une production d'un module ABAL, il fournit le pied ou le nom ";
			mptr[6]="de la racine des proc‚dures d'interface et de support des modules. ";
			mptr[7]="  ";
			mptr[8]=" ";
			mptr[9]="Pour les empaquetages de production de PROGRAMMES ABAL, il sera utilis‚ ";
			mptr[10]="pour la g‚n‚ration de la d‚claration de PROGRAMME.  ";
			mptr[11]=" ";
			mptr[12]="Dans tous les cas, il sera utilis‚ comme le titre et l'identification ";
			mptr[13]="du modŠle dans la production de documents html.   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int StyleSheet_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This edit field allows the filename of a style sheet to be specified. ";
			mptr[1]="The style sheet may provide style classes which overload the default ";
			mptr[2]="visual classes or simply provide classes used by visual element type ";
			mptr[3]="widgets. In all cases the style class is described using CSS   ";
			mptr[4]=" ";
			mptr[5]=" For more information to this effect please refer to the  Visual Atributs ";
			mptr[6]="and Style  documentation.   ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ChoosePalette_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button gives access to the File Selection Dialog box for ";
			mptr[1]="selection of the rgb palette filename.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PaletteName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" This edit field allows the filename of an rgb palette file to be ";
			mptr[2]="specified. This palette name if specified will be used instead of ";
			mptr[3]="the centralised  palette name taken from the project parameters in ";
			mptr[4]="the VisualPalette instruction of the forms constrcution methode.  ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ClearScreen_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field allows the class name of a style class to be specified. ";
			mptr[1]="This class will be used to provide an application background for program ";
			mptr[2]="type packaging.  ";
			mptr[3]=" ";
			mptr[4]="The style class should  be defined in the file referenced by the preceeding ";
			mptr[5]="style filename edit field.   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MouseEvents_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This tab page presents the various keyboard and  mouse or pointing ";
			mptr[1]="device  event controls.  ";
			mptr[2]=" ";
			mptr[3]="These parameters influence the event reception and  analysis source ";
			mptr[4]="generated to the OnEvent and the OnFocus  methods of the visual form.  ";
			mptr[5]=" ";
			mptr[6]="   ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendLeft_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]="left button events is possible, otherwise left button events will ";
			mptr[2]="be ignored.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendMiddle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]="middle button events is possible, otherwise middle button events will ";
			mptr[2]="be ignored.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendRight_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]="right button events is possible, otherwise right button events will ";
			mptr[2]="be ignored.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendWheel_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]="wheel  up and down events are possible, otherwise wheel events will ";
			mptr[2]="be ignored.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ButtonFilter_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = " ";
			mptr[1]=" When this check control is active events filtering will occur  in ";
			mptr[2]="accordance with the forms button configuration and each individual ";
			mptr[3]=" widget mouse button configuration.  ";
			mptr[4]="   ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" Lorsque ce control est active il y aura filtrage d'evenement souris ";
			mptr[2]="en fonction du configuration des boutons au niveau formulaire et  ";
			mptr[3]="en accord avec la configuration des boutons souris de chaque widget. ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendDown_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]=" button press events is possible, otherwise button press events will ";
			mptr[2]="be ignored.  ";
			mptr[3]=" ";
			mptr[4]="This is necessary for visual instance class data widgets to be easily ";
			mptr[5]="selected.     ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendUp_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]=" button release events is possible, otherwise button release events ";
			mptr[2]="will be ignored.  ";
			mptr[3]=" ";
			mptr[4]="In most cases the activation of application code, provided by  widget ";
			mptr[5]="Event methods, will occur on button release events.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendWhileDown_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]="move while down events is possible, otherwise these mouse events will ";
			mptr[2]="be ignored.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SendMove_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this check control is active reception and analysis of mouse ";
			mptr[1]="move  events is possible, otherwise these mouse events will be ignored. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int WidgetTriggers_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this check control is active source will be produced to handle ";
			mptr[1]="Alt Key Events. It also enables the forms menu option for the calculation ";
			mptr[2]="and distibution of   active widget component hotkey triggers.  ";
			mptr[3]=" ";
			mptr[4]="Otherwise this source production will be inhibited.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Escape_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "When this check control is active source code will be generated allowing ";
			mptr[1]="the  escape key to be used to cancel modifications prior to exit from ";
			mptr[2]="the forms model.  ";
			mptr[3]=" ";
			mptr[4]="If the check is clear then escape key handling source will be inhibited. ";
			mptr[5]="  ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Enter_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "If this check control is active then source will be generated allowing ";
			mptr[1]=" the enter key event to confirm and transmit modified parameters prior ";
			mptr[2]="to exit from a dialog box.  ";
			mptr[3]=" ";
			mptr[4]="If this check control is not active then the enter key event will ";
			mptr[5]="cause the  forms focus to be passed sequentially to the next forms ";
			mptr[6]="widget.   ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PageUp_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this check control is active source will be produced to handle ";
			mptr[1]="focus passing on a tab page level in a reverse direction through the ";
			mptr[2]="list of widget tab page  components.  ";
			mptr[3]=" ";
			mptr[4]="Otherwise this source production will be inhibited.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PageDown_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this check control is active source will be produced to handle ";
			mptr[1]="focus passing on a tab page level in a forward direction through the ";
			mptr[2]="list of widget tab page  components.  ";
			mptr[3]=" ";
			mptr[4]="Otherwise this source production will be inhibited.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int UpArrow_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this check control is active source will be produced to handle ";
			mptr[1]="focus passing in a reverse direction through the list of active widget ";
			mptr[2]="components.  ";
			mptr[3]=" ";
			mptr[4]="Otherwise this source production will be inhibited.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DownArrow_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this check control is active source will be produced to handle ";
			mptr[1]="focus passing in a forward direction through the list of active widget ";
			mptr[2]="components in response to the down arrow key.  ";
			mptr[3]=" ";
			mptr[4]="Otherwise this source production will be inhibited.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Tabulation_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this check control is active source will be produced to handle ";
			mptr[1]="focus passing in a forward direction through the list of active widget ";
			mptr[2]="components in response to the tabulation key.  ";
			mptr[3]=" ";
			mptr[4]="Otherwise this source production will be inhibited.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DefaultBreak_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this check control is active source will be produced allowing ";
			mptr[1]="all unhandled  keyboard events to break out of the OnFocus event handling switch and to return the corrsponding keycode ";
			mptr[2]="event as a result.  ";
			mptr[3]=" ";
			mptr[4]="Otherwise this source production will be inhibited.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FormMethods_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This tab page presents the collection of methods defined for and specific ";
			mptr[1]=" to the particular visual form. The methods are visible at and accessible ";
			mptr[2]=" from all other widget packaging level methods.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Methods_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[11];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="This control displays the list of forms methods defined for this visual ";
			mptr[3]="form.  ";
			mptr[4]=" ";
			mptr[5]="Forms methods are methods or procedures declared at the form level ";
			mptr[6]="that may be activated from other widget methods.  ";
			mptr[7]=" ";
			mptr[8]="A particular forms method may be selected for inspection  by clicking ";
			mptr[9]="with the left button on the corresponding item in the list and then ";
			mptr[10]="pressing the  Edit Method button.    ";
			return(visual_online_help(mptr,11));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditMethod_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This button provides access to the Forms Method dialog box for inspection ";
			mptr[1]="of the selected forms method.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PasteMethod_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This button causes a previously copied forms method to be pasted into ";
			mptr[1]="the method collection of the current forms model.  ";
			mptr[2]=" ";
			mptr[3]=" This button will only be displayed when a forms method is available ";
			mptr[4]="for pasting after having been copied by the corresponding button of ";
			mptr[5]="this dialog box.     ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CopyMethod_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This button causes the currently selected forms method to be copied ";
			mptr[1]="for subsequent pasting into another forms model or slot.  ";
			mptr[2]=" ";
			mptr[3]="A method copied in this way will replace a previous ly copied method ";
			mptr[4]="as the current value.  ";
			mptr[5]=" ";
			mptr[6]="If the current slot is empty it will cause the current pastable  method ";
			mptr[7]="selection to be reset.    ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DropMethod_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This button allows the currently selected forms method to be deleted ";
			mptr[1]="from the current form.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FormMemberPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This tab page presents the collection of methods defined for and specific ";
			mptr[1]=" to the particular visual form. The methods are visible at and accessible ";
			mptr[2]=" from all other widget packaging level methods.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FormMembers_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[20];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="This table allows definition of the extra data members required by ";
			mptr[3]="the current  forms model or class.  ";
			mptr[4]=" ";
			mptr[5]="The various columns of valid member items may be modified as required. ";
			mptr[6]=" ";
			mptr[7]=" ";
			mptr[8]="Clicking in the Type field will make a selection control appear for ";
			mptr[9]="the  prompted selection of the member data type.  ";
			mptr[10]=" ";
			mptr[11]="Clicking in the Ptr field will make a selection control appear for ";
			mptr[12]="the  prompted selection of the ptr or dcl  nature of the member data ";
			mptr[13]="type.  ";
			mptr[14]=" ";
			mptr[15]="Data input in the name field will be analysed for standard abal variable ";
			mptr[16]="declaration syntax.  ";
			mptr[17]=" ";
			mptr[18]="Information provided in the comment field will be generated alongside ";
			mptr[19]="the variable declaration in the resulting source file.      ";
			return(visual_online_help(mptr,20));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3559action(struct accept_form_control_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_form_control_hide(_Context);

		_Context->x_Auto3559 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3559 < 0) { _Context->x_Auto3559=0; }
		_Context->y_Auto3559 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3559 < 0) { _Context->y_Auto3559=0; }
			accept_form_control_show(_Context);

		visual_thaw(_Context->x_Auto3559,_Context->y_Auto3559,790,600);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3568_event(struct accept_form_control_context * _Context) {
	return(13);
	return(-1);
}
private int on_Auto3569_event(struct accept_form_control_context * _Context) {
	return(27);
	return(-1);
}
private int on_ChooseFileName_event(struct accept_form_control_context * _Context) {
	use_file_selector(_Context->buffer_FileName,WIDGET_FILE_AS);
		accept_form_control_show(_Context);
;
	return(-1);
}
private int on_ChooseStyleName_event(struct accept_form_control_context * _Context) {
	use_file_selector(_Context->buffer_StyleSheet,WIDGET_FILE_CSS);
		accept_form_control_show(_Context);
;
	return(-1);
}
private int on_EditSource_event(struct accept_form_control_context * _Context) {
		accept_form_control_hide(_Context);
;
	standard_text_editor(_Context->buffer_FileName,255);
		accept_form_control_show(_Context);
;
	return(-1);
}
private int on_EditStyle_event(struct accept_form_control_context * _Context) {
		accept_form_control_hide(_Context);
;
	standard_text_editor(_Context->buffer_StyleSheet,255);
		accept_form_control_show(_Context);
;
	return(-1);
}
private int on_ChoosePalette_event(struct accept_form_control_context * _Context) {
	use_file_selector(_Context->buffer_PaletteName,WIDGET_FILE_RGB);
		accept_form_control_show(_Context);
;
	return(-1);
}
private int on_Methods_event(struct accept_form_control_context * _Context) {
	int l;
	l=_Context->value_Methods;
	on_Methods_show(_Context);
	if(l>0){
	if ( l > 0 ) { _Context->row_Methods=&_Context->buffer_Methods[l-1][0]; } ;
	if(visual_event(2)==_MIMO_RIGHT)
	on_EditMethod_event(_Context);
	}
		return(-1);
}
private int on_EditMethod_event(struct accept_form_control_context * _Context) {
	int i;
	int m;
	if(_Context->page_number==3){
	if(!(i=_Context->value_Methods))
	i=1;
		accept_form_control_hide(_Context);

	m=i+_Context->value_ScrollBar;
	m=sort_item_Methods(_Context,m);
	edit_forms_method(m);
		accept_form_control_show(_Context);

	}
	return(-1);
}
private int on_PasteMethod_event(struct accept_form_control_context * _Context) {
	int i;
	int m;
	if(valid_copied_method()){
	if(_Context->page_number==3){
	if(!(i=_Context->value_Methods))
	i=1;
		accept_form_control_hide(_Context);

	m=i+_Context->value_ScrollBar;
	m=sort_item_Methods(_Context,m);
	paste_forms_method(m);
		accept_form_control_show(_Context);

	}
	}
	return(-1);
}
private int on_CopyMethod_event(struct accept_form_control_context * _Context) {
	int i;
	int m;
	if(_Context->page_number==3){
	if(!(i=_Context->value_Methods))
	i=1;
		accept_form_control_hide(_Context);

	m=i+_Context->value_ScrollBar;
	m=sort_item_Methods(_Context,m);
	copy_forms_method(m);
		accept_form_control_show(_Context);

	}
	return(-1);
}
private int on_DropMethod_event(struct accept_form_control_context * _Context) {
	int i;
	int m;
	if(_Context->page_number==3){
	i=_Context->value_Methods;
	if(i>0){
		accept_form_control_hide(_Context);

	m=i+_Context->value_ScrollBar;
	m=sort_item_Methods(_Context,m);
	drop_forms_method(m);
		accept_form_control_show(_Context);

	}
	}
	return(-1);
}
private int on_ScrollBar_event(struct accept_form_control_context * _Context) {
	on_Methods_show(_Context);
	return(-1);
}

private int on_ScrollBar_action(struct accept_form_control_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3559+70+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_ScrollBar -= 1;
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
		(void) on_ScrollBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3559+70+410-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_ScrollBar += 1;
		if (!(_Context->max_ScrollBar))
			_Context->value_ScrollBar = 0;
		else if ((_Context->max_ScrollBar < _Context->limit_ScrollBar) 
		&& (_Context->value_ScrollBar >= _Context->max_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-1);
		else if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
		(void) on_ScrollBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_ScrollBar;
		_Context->value_ScrollBar = (((visual_event(6) - (_Context->y_Auto3559+70+20)) * _Context->max_ScrollBar) / (410 - (2 * 20)));
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
		else if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
		if (_Context->value_ScrollBar != aty) {
		(void) on_ScrollBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_ScrollBar -= (_Context->limit_ScrollBar/2);
			if (_Context->value_ScrollBar < 0) 
				_Context->value_ScrollBar = 0;
		(void) on_ScrollBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_ScrollBar += (_Context->limit_ScrollBar/2);
			if (!(_Context->max_ScrollBar))
				_Context->value_ScrollBar = 0;
			else if ((_Context->max_ScrollBar < _Context->limit_ScrollBar) 
			&& (_Context->value_ScrollBar >= _Context->max_ScrollBar)) 
				_Context->value_ScrollBar = (_Context->max_ScrollBar-1);
			else if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
				_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
		(void) on_ScrollBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,410,vfh[1],0,0,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,3);

	return(1);
}
private int on_FormMembers_event(struct accept_form_control_context * _Context) {
	on_FormMembers_show(_Context);
	return(-1);
}
private int on_MemberBar_event(struct accept_form_control_context * _Context) {
	on_FormMembers_show(_Context);
	return(-1);
}

private int on_MemberBar_action(struct accept_form_control_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3559+70+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_MemberBar -= 1;
		if (_Context->value_MemberBar < 0) 
			_Context->value_MemberBar = 0;
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3559+70+450-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_MemberBar += 1;
		if (!(_Context->max_MemberBar))
			_Context->value_MemberBar = 0;
		else if ((_Context->max_MemberBar < _Context->limit_MemberBar) 
		&& (_Context->value_MemberBar >= _Context->max_MemberBar)) 
			_Context->value_MemberBar = (_Context->max_MemberBar-1);
		else if (_Context->value_MemberBar > (_Context->max_MemberBar-_Context->limit_MemberBar)) 
			_Context->value_MemberBar = (_Context->max_MemberBar-_Context->limit_MemberBar);
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_MemberBar;
		_Context->value_MemberBar = (((visual_event(6) - (_Context->y_Auto3559+70+20)) * _Context->max_MemberBar) / (450 - (2 * 20)));
		if (_Context->value_MemberBar < 0) 
			_Context->value_MemberBar = 0;
		else if (_Context->value_MemberBar > (_Context->max_MemberBar-_Context->limit_MemberBar)) 
			_Context->value_MemberBar = (_Context->max_MemberBar-_Context->limit_MemberBar);
		if (_Context->value_MemberBar != aty) {
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_MemberBar -= (_Context->limit_MemberBar/2);
			if (_Context->value_MemberBar < 0) 
				_Context->value_MemberBar = 0;
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_MemberBar += (_Context->limit_MemberBar/2);
			if (!(_Context->max_MemberBar))
				_Context->value_MemberBar = 0;
			else if ((_Context->max_MemberBar < _Context->limit_MemberBar) 
			&& (_Context->value_MemberBar >= _Context->max_MemberBar)) 
				_Context->value_MemberBar = (_Context->max_MemberBar-1);
			else if (_Context->value_MemberBar > (_Context->max_MemberBar-_Context->limit_MemberBar)) 
				_Context->value_MemberBar = (_Context->max_MemberBar-_Context->limit_MemberBar);
		(void) on_MemberBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3559+740,_Context->y_Auto3559+70,20,450,vfh[1],0,0,_Context->value_MemberBar,_Context->limit_MemberBar,_Context->max_MemberBar,3);

	return(1);
}


public	int	accept_form_control_event(
struct accept_form_control_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_FormControl == mb ) return(2);
		if (_Context->trigger_Auto3568 == mb ) return(3);
		if (_Context->trigger_Auto3569 == mb ) return(4);
		if (_Context->trigger_International == mb ) return(8);
		if (_Context->trigger_Constants == mb ) return(9);
		if (_Context->trigger_MultipleLanguage == mb ) return(10);
		if (_Context->trigger_Program == mb ) return(11);
		if (_Context->trigger_Overlay == mb ) return(12);
		if (_Context->trigger_PopUp == mb ) return(13);
		if (_Context->trigger_Dynamic == mb ) return(14);
		if (_Context->trigger_CommandLine == mb ) return(15);
		if (_Context->trigger_Resize == mb ) return(18);
		if (_Context->trigger_ChooseFileName == mb ) return(26);
		if (_Context->trigger_ChooseStyleName == mb ) return(27);
		if (_Context->trigger_EditSource == mb ) return(28);
		if (_Context->trigger_EditStyle == mb ) return(29);
		if (_Context->trigger_ChoosePalette == mb ) return(32);
		if (_Context->trigger_MouseEvents == mb ) return(35);
		if (_Context->trigger_SendLeft == mb ) return(36);
		if (_Context->trigger_SendMiddle == mb ) return(37);
		if (_Context->trigger_SendRight == mb ) return(38);
		if (_Context->trigger_SendWheel == mb ) return(39);
		if (_Context->trigger_ButtonFilter == mb ) return(40);
		if (_Context->trigger_SendDown == mb ) return(41);
		if (_Context->trigger_SendUp == mb ) return(42);
		if (_Context->trigger_SendWhileDown == mb ) return(43);
		if (_Context->trigger_SendMove == mb ) return(44);
		if (_Context->trigger_MouseKey == mb ) return(45);
		if (_Context->trigger_WidgetTriggers == mb ) return(46);
		if (_Context->trigger_Escape == mb ) return(47);
		if (_Context->trigger_Enter == mb ) return(48);
		if (_Context->trigger_PageUp == mb ) return(49);
		if (_Context->trigger_PageDown == mb ) return(50);
		if (_Context->trigger_UpArrow == mb ) return(51);
		if (_Context->trigger_DownArrow == mb ) return(52);
		if (_Context->trigger_Tabulation == mb ) return(53);
		if (_Context->trigger_DefaultBreak == mb ) return(54);
		if (_Context->trigger_FormMethods == mb ) return(55);
		if (_Context->trigger_EditMethod == mb ) return(57);
		if (_Context->trigger_PasteMethod == mb ) return(58);
		if (_Context->trigger_CopyMethod == mb ) return(59);
		if (_Context->trigger_DropMethod == mb ) return(60);
		if (_Context->trigger_FormMemberPage == mb ) return(62);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3559+769) )  
	&&  (my >= (_Context->y_Auto3559+4) )  
	&&  (mx <= (_Context->x_Auto3559+786) )  
	&&  (my <= (_Context->y_Auto3559+20) )) {
		return(1);	/* Auto3559 */

		}
	if ((mx >= (_Context->x_Auto3559+753) )  
	&&  (my >= (_Context->y_Auto3559+4) )  
	&&  (mx <= (_Context->x_Auto3559+770) )  
	&&  (my <= (_Context->y_Auto3559+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vform31e.htm");
			};
		return(-1);	/* Auto3559 */

		}
	if ((mx >= (_Context->x_Auto3559+737) )  
	&&  (my >= (_Context->y_Auto3559+4) )  
	&&  (mx <= (_Context->x_Auto3559+754) )  
	&&  (my <= (_Context->y_Auto3559+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_form_control_show(_Context);
		return(-1);	/* Auto3559 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3559+4) )  
		&&  (my >= (_Context->y_Auto3559+4) )  
		&&  (mx <= (_Context->x_Auto3559+722) )  
		&&  (my <= (_Context->y_Auto3559+20) )) {
			return( Auto3559action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3559+10+0) ) 
		&&  ( my >= (_Context->y_Auto3559+30) ) 
		&&  ( mx <= (_Context->x_Auto3559+10+133) ) 
		&&  ( my <= (_Context->y_Auto3559+30+24))) {
			return(2); /* FormControl */
			}
		}
	if (( mx >= (_Context->x_Auto3559+10) ) 
	&&  ( my >= (_Context->y_Auto3559+540) ) 
	&&  ( mx <= (_Context->x_Auto3559+10+56) ) 
	&&  ( my <= (_Context->y_Auto3559+540+48))) {
		return(3); /* Auto3568 */
		}
	if (( mx >= (_Context->x_Auto3559+720) ) 
	&&  ( my >= (_Context->y_Auto3559+540) ) 
	&&  ( mx <= (_Context->x_Auto3559+720+56) ) 
	&&  ( my <= (_Context->y_Auto3559+540+48))) {
		return(4); /* Auto3569 */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+50+0) ) 
		&&  ( my >= (_Context->y_Auto3559+120) ) 
		&&  ( mx <= (_Context->x_Auto3559+50+140) ) 
		&&  ( my <= (_Context->y_Auto3559+120+16))) {
			return(5); /* FormType */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+200+0) ) 
		&&  ( my >= (_Context->y_Auto3559+120) ) 
		&&  ( mx <= (_Context->x_Auto3559+200+140) ) 
		&&  ( my <= (_Context->y_Auto3559+120+16))) {
			return(6); /* ProductionLanguage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+350+0) ) 
		&&  ( my >= (_Context->y_Auto3559+120) ) 
		&&  ( mx <= (_Context->x_Auto3559+350+140) ) 
		&&  ( my <= (_Context->y_Auto3559+120+16))) {
			return(7); /* NationalLanguage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+50) ) 
		&&  ( my >= (_Context->y_Auto3559+190) ) 
		&&  ( mx <= (_Context->x_Auto3559+50+322) ) 
		&&  ( my <= (_Context->y_Auto3559+190+16))) {
			return(8); /* International */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+50) ) 
		&&  ( my >= (_Context->y_Auto3559+220) ) 
		&&  ( mx <= (_Context->x_Auto3559+50+294) ) 
		&&  ( my <= (_Context->y_Auto3559+220+16))) {
			return(9); /* Constants */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+400) ) 
		&&  ( my >= (_Context->y_Auto3559+190) ) 
		&&  ( mx <= (_Context->x_Auto3559+400+280) ) 
		&&  ( my <= (_Context->y_Auto3559+190+16))) {
			return(10); /* MultipleLanguage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+50) ) 
		&&  ( my >= (_Context->y_Auto3559+160) ) 
		&&  ( mx <= (_Context->x_Auto3559+50+322) ) 
		&&  ( my <= (_Context->y_Auto3559+160+16))) {
			return(11); /* Program */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+400) ) 
		&&  ( my >= (_Context->y_Auto3559+160) ) 
		&&  ( mx <= (_Context->x_Auto3559+400+280) ) 
		&&  ( my <= (_Context->y_Auto3559+160+16))) {
			return(12); /* Overlay */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+400) ) 
		&&  ( my >= (_Context->y_Auto3559+220) ) 
		&&  ( mx <= (_Context->x_Auto3559+400+294) ) 
		&&  ( my <= (_Context->y_Auto3559+220+16))) {
			return(13); /* PopUp */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+400) ) 
		&&  ( my >= (_Context->y_Auto3559+250) ) 
		&&  ( mx <= (_Context->x_Auto3559+400+280) ) 
		&&  ( my <= (_Context->y_Auto3559+250+16))) {
			return(14); /* Dynamic */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+50) ) 
		&&  ( my >= (_Context->y_Auto3559+280) ) 
		&&  ( mx <= (_Context->x_Auto3559+50+266) ) 
		&&  ( my <= (_Context->y_Auto3559+280+16))) {
			return(15); /* CommandLine */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+400) ) 
		&&  ( my >= (_Context->y_Auto3559+280) ) 
		&&  ( mx <= (_Context->x_Auto3559+400+96) ) 
		&&  ( my <= (_Context->y_Auto3559+280+16))) {
			return(16); /* ArgVLen */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+510) ) 
		&&  ( my >= (_Context->y_Auto3559+280) ) 
		&&  ( mx <= (_Context->x_Auto3559+510+104) ) 
		&&  ( my <= (_Context->y_Auto3559+280+16))) {
			return(17); /* ArgVNb */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+50) ) 
		&&  ( my >= (_Context->y_Auto3559+310) ) 
		&&  ( mx <= (_Context->x_Auto3559+50+264) ) 
		&&  ( my <= (_Context->y_Auto3559+310+16))) {
			return(18); /* Resize */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+400) ) 
		&&  ( my >= (_Context->y_Auto3559+310) ) 
		&&  ( mx <= (_Context->x_Auto3559+400+72) ) 
		&&  ( my <= (_Context->y_Auto3559+310+16))) {
			return(19); /* ResizeX */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+540) ) 
		&&  ( my >= (_Context->y_Auto3559+310) ) 
		&&  ( mx <= (_Context->x_Auto3559+540+72) ) 
		&&  ( my <= (_Context->y_Auto3559+310+16))) {
			return(20); /* ResizeY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+510+0) ) 
		&&  ( my >= (_Context->y_Auto3559+120) ) 
		&&  ( mx <= (_Context->x_Auto3559+510+112) ) 
		&&  ( my <= (_Context->y_Auto3559+120+16))) {
			return(21); /* GenHelp */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+630+0) ) 
		&&  ( my >= (_Context->y_Auto3559+120) ) 
		&&  ( mx <= (_Context->x_Auto3559+630+112) ) 
		&&  ( my <= (_Context->y_Auto3559+120+16))) {
			return(22); /* ActHelp */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+370) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+672) ) 
		&&  ( my <= (_Context->y_Auto3559+370+16))) {
			return(25); /* FileName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+720) ) 
		&&  ( my >= (_Context->y_Auto3559+370) ) 
		&&  ( mx <= (_Context->x_Auto3559+720+32) ) 
		&&  ( my <= (_Context->y_Auto3559+370+16))) {
			return(26); /* ChooseFileName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+720) ) 
		&&  ( my >= (_Context->y_Auto3559+470) ) 
		&&  ( mx <= (_Context->x_Auto3559+720+32) ) 
		&&  ( my <= (_Context->y_Auto3559+470+16))) {
			return(27); /* ChooseStyleName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+720) ) 
		&&  ( my >= (_Context->y_Auto3559+390) ) 
		&&  ( mx <= (_Context->x_Auto3559+720+32) ) 
		&&  ( my <= (_Context->y_Auto3559+390+16))) {
			return(28); /* EditSource */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+720) ) 
		&&  ( my >= (_Context->y_Auto3559+490) ) 
		&&  ( mx <= (_Context->x_Auto3559+720+32) ) 
		&&  ( my <= (_Context->y_Auto3559+490+16))) {
			return(29); /* EditStyle */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+420) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+336) ) 
		&&  ( my <= (_Context->y_Auto3559+420+16))) {
			return(30); /* Identity */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+470) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+336) ) 
		&&  ( my <= (_Context->y_Auto3559+470+16))) {
			return(31); /* StyleSheet */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+720) ) 
		&&  ( my >= (_Context->y_Auto3559+420) ) 
		&&  ( mx <= (_Context->x_Auto3559+720+36) ) 
		&&  ( my <= (_Context->y_Auto3559+420+16))) {
			return(32); /* ChoosePalette */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+380) ) 
		&&  ( my >= (_Context->y_Auto3559+420) ) 
		&&  ( mx <= (_Context->x_Auto3559+380+336) ) 
		&&  ( my <= (_Context->y_Auto3559+420+16))) {
			return(33); /* PaletteName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3559+380) ) 
		&&  ( my >= (_Context->y_Auto3559+470) ) 
		&&  ( mx <= (_Context->x_Auto3559+380+336) ) 
		&&  ( my <= (_Context->y_Auto3559+470+16))) {
			return(34); /* ClearScreen */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3559+10+134) ) 
		&&  ( my >= (_Context->y_Auto3559+30) ) 
		&&  ( mx <= (_Context->x_Auto3559+10+264) ) 
		&&  ( my <= (_Context->y_Auto3559+30+24))) {
			return(35); /* MouseEvents */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+100) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+238) ) 
		&&  ( my <= (_Context->y_Auto3559+100+16))) {
			return(36); /* SendLeft */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+280) ) 
		&&  ( my >= (_Context->y_Auto3559+100) ) 
		&&  ( mx <= (_Context->x_Auto3559+280+210) ) 
		&&  ( my <= (_Context->y_Auto3559+100+16))) {
			return(37); /* SendMiddle */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+120) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+224) ) 
		&&  ( my <= (_Context->y_Auto3559+120+16))) {
			return(38); /* SendRight */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+280) ) 
		&&  ( my >= (_Context->y_Auto3559+120) ) 
		&&  ( mx <= (_Context->x_Auto3559+280+224) ) 
		&&  ( my <= (_Context->y_Auto3559+120+16))) {
			return(39); /* SendWheel */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+490) ) 
		&&  ( my >= (_Context->y_Auto3559+100) ) 
		&&  ( mx <= (_Context->x_Auto3559+490+224) ) 
		&&  ( my <= (_Context->y_Auto3559+100+16))) {
			return(40); /* ButtonFilter */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+190) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+224) ) 
		&&  ( my <= (_Context->y_Auto3559+190+16))) {
			return(41); /* SendDown */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+280) ) 
		&&  ( my >= (_Context->y_Auto3559+190) ) 
		&&  ( mx <= (_Context->x_Auto3559+280+196) ) 
		&&  ( my <= (_Context->y_Auto3559+190+16))) {
			return(42); /* SendUp */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+210) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+238) ) 
		&&  ( my <= (_Context->y_Auto3559+210+16))) {
			return(43); /* SendWhileDown */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+280) ) 
		&&  ( my >= (_Context->y_Auto3559+210) ) 
		&&  ( mx <= (_Context->x_Auto3559+280+196) ) 
		&&  ( my <= (_Context->y_Auto3559+210+16))) {
			return(44); /* SendMove */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+490) ) 
		&&  ( my >= (_Context->y_Auto3559+190) ) 
		&&  ( mx <= (_Context->x_Auto3559+490+196) ) 
		&&  ( my <= (_Context->y_Auto3559+190+16))) {
			return(45); /* MouseKey */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+490) ) 
		&&  ( my >= (_Context->y_Auto3559+210) ) 
		&&  ( mx <= (_Context->x_Auto3559+490+210) ) 
		&&  ( my <= (_Context->y_Auto3559+210+16))) {
			return(46); /* WidgetTriggers */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+280) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+280+16))) {
			return(47); /* Escape */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+460) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+460+16))) {
			return(48); /* Enter */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+310) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+310+16))) {
			return(49); /* PageUp */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+340) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+340+16))) {
			return(50); /* PageDown */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+370) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+370+16))) {
			return(51); /* UpArrow */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+400) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+400+16))) {
			return(52); /* DownArrow */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+430) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+430+16))) {
			return(53); /* Tabulation */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3559+40) ) 
		&&  ( my >= (_Context->y_Auto3559+490) ) 
		&&  ( mx <= (_Context->x_Auto3559+40+700) ) 
		&&  ( my <= (_Context->y_Auto3559+490+16))) {
			return(54); /* DefaultBreak */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto3559+10+265) ) 
		&&  ( my >= (_Context->y_Auto3559+30) ) 
		&&  ( mx <= (_Context->x_Auto3559+10+400) ) 
		&&  ( my <= (_Context->y_Auto3559+30+24))) {
			return(55); /* FormMethods */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3559+30) ) 
		&&  ( my >= (_Context->y_Auto3559+70) ) 
		&&  ( mx <= (_Context->x_Auto3559+30+710) ) 
		&&  ( my <= (_Context->y_Auto3559+70+410))) {
			if ((_Context->value_Methods = ((visual_event(6) - (_Context->y_Auto3559+70)) / 16)) < 1)
				_Context->value_Methods=0;
else if (_Context->value_Methods > 24 )
				_Context->value_Methods=24;
			if ( _Context->value_Methods > 0 ) { _Context->row_Methods = &_Context->buffer_Methods[(_Context->value_Methods-1)][0]; } 
			_Context->column_Methods = (visual_event(7) - (_Context->x_Auto3559+30));
			if ( _Context->column_Methods < 136 ) {
				_Context->column_Methods = 1;
				}
			else if ( _Context->column_Methods < 400 ) {
				_Context->column_Methods = 2;
				}
			else if ( _Context->column_Methods < 704 ) {
				_Context->column_Methods = 3;
				}
			if ((!(_Context->value_Methods)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_Methods==_Context->column_Methods) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_Methods=-_Context->column_Methods;	/* alors tri décroissant */
				else
					_Context->formsort_Methods=_Context->column_Methods; };	/* sinon tri croissant */
			return(56); /* Methods */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3559+30) ) 
		&&  ( my >= (_Context->y_Auto3559+490) ) 
		&&  ( mx <= (_Context->x_Auto3559+30+126) ) 
		&&  ( my <= (_Context->y_Auto3559+490+32))) {
			return(57); /* EditMethod */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3559+380) ) 
		&&  ( my >= (_Context->y_Auto3559+490) ) 
		&&  ( mx <= (_Context->x_Auto3559+380+126) ) 
		&&  ( my <= (_Context->y_Auto3559+490+32))) {
			return(58); /* PasteMethod */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3559+250) ) 
		&&  ( my >= (_Context->y_Auto3559+490) ) 
		&&  ( mx <= (_Context->x_Auto3559+250+126) ) 
		&&  ( my <= (_Context->y_Auto3559+490+32))) {
			return(59); /* CopyMethod */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3559+610) ) 
		&&  ( my >= (_Context->y_Auto3559+490) ) 
		&&  ( mx <= (_Context->x_Auto3559+610+126) ) 
		&&  ( my <= (_Context->y_Auto3559+490+32))) {
			return(60); /* DropMethod */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3559+740) ) 
		&&  ( my >= (_Context->y_Auto3559+70) ) 
		&&  ( mx <= (_Context->x_Auto3559+740+20) ) 
		&&  ( my <= (_Context->y_Auto3559+70+410))) {
			return(61); /* ScrollBar */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto3559+10+401) ) 
		&&  ( my >= (_Context->y_Auto3559+30) ) 
		&&  ( mx <= (_Context->x_Auto3559+10+540) ) 
		&&  ( my <= (_Context->y_Auto3559+30+24))) {
			return(62); /* FormMemberPage */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3559+30) ) 
		&&  ( my >= (_Context->y_Auto3559+70) ) 
		&&  ( mx <= (_Context->x_Auto3559+30+710) ) 
		&&  ( my <= (_Context->y_Auto3559+70+450))) {
			if ((_Context->value_FormMembers = ((visual_event(6) - (_Context->y_Auto3559+70)) / 16)) < 1)
				_Context->value_FormMembers=0;
else if (_Context->value_FormMembers > 26 )
				_Context->value_FormMembers=26;
			if ( _Context->value_FormMembers > 0 ) { _Context->row_FormMembers = &_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0]; } 
			_Context->column_FormMembers = (visual_event(7) - (_Context->x_Auto3559+30));
			if ( _Context->column_FormMembers < 192 ) {
				_Context->column_FormMembers = 1;
				}
			else if ( _Context->column_FormMembers < 240 ) {
				_Context->column_FormMembers = 2;
				}
			else if ( _Context->column_FormMembers < 312 ) {
				_Context->column_FormMembers = 3;
				}
			else if ( _Context->column_FormMembers < 360 ) {
				_Context->column_FormMembers = 4;
				}
			else if ( _Context->column_FormMembers < 408 ) {
				_Context->column_FormMembers = 5;
				}
			else if ( _Context->column_FormMembers < 456 ) {
				_Context->column_FormMembers = 6;
				}
			else if ( _Context->column_FormMembers < 704 ) {
				_Context->column_FormMembers = 7;
				}
			if ((!(_Context->value_FormMembers)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_FormMembers==_Context->column_FormMembers) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_FormMembers=-_Context->column_FormMembers;	/* alors tri décroissant */
				else
					_Context->formsort_FormMembers=_Context->column_FormMembers; };	/* sinon tri croissant */
			return(63); /* FormMembers */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3559+740) ) 
		&&  ( my >= (_Context->y_Auto3559+70) ) 
		&&  ( mx <= (_Context->x_Auto3559+740+20) ) 
		&&  ( my <= (_Context->y_Auto3559+70+450))) {
			return(64); /* MemberBar */
			}
		}

	return(-1);
}
private int on_FormMembers_losefocus(struct accept_form_control_context * _Context) {
	int v;
	char*cptr;
	int t=0,n=0,l=0,f=0,s=0,p=0;
	struct forms_data_member*get_forms_member(int);
	struct forms_data_member*dptr;
	l=_Context->value_FormMembers;
	if(l>0){
	if ( l > 0 ) { _Context->row_FormMembers=&_Context->buffer_FormMembers[l-1][0]; } ;
	if(!(dptr=get_forms_member(l+_Context->value_MemberBar)))
	t=0;
	else t=dptr->type;
	switch(_Context->column_FormMembers){
	case 2:
	case 3:
	break;
	case 1:
	n=atoi((_Context->row_FormMembers+39));
	f=atoi((_Context->row_FormMembers+45));
	s=atoi((_Context->row_FormMembers+51));
	analyse_variable_expression(
	(_Context->row_FormMembers+0),24,
	&t,&n,&f,&s);
	for(cptr=(_Context->row_FormMembers+0),v=0;v<24;v++){
	if(!(*(cptr+v))){
	while(v<24){
	*(cptr+v)=' ';
	v++;
	}
	break;
	}
	}
	put_forms_member(l+_Context->value_MemberBar,(_Context->row_FormMembers+0),24,t,n,f,s,(_Context->row_FormMembers+57),31);
	break;
		case 4:
	case 5:
	case 6:
	case 7:
	n=atoi((_Context->row_FormMembers+39));
	f=atoi((_Context->row_FormMembers+45));
	s=atoi((_Context->row_FormMembers+51));
	put_forms_member(l+_Context->value_MemberBar,(_Context->row_FormMembers+0),24,t,n,f,s,(_Context->row_FormMembers+57),31);
	}
	}
	on_FormMembers_show(_Context);
	return(-1);
}


public	int	accept_form_control_losefocus(struct accept_form_control_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		case 4 : 
			break;

		}
	return(0);

}
private int on_FormMembers_getfocus(struct accept_form_control_context * _Context) {
	int Status;
	int l;
	struct forms_data_member*get_forms_member(int);
	struct forms_data_member*dptr;
	if(_Context->column_FormMembers==3){
	l=_Context->value_FormMembers;
	if(!(dptr=get_forms_member(l+_Context->value_MemberBar))){
		if (!_Context->value_FormMembers) _Context->value_FormMembers=1;	/* pour etre sur qu'on edite pas le titre */
	_Context->row_FormMembers = &_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0];
	switch (_Context->column_FormMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+2),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),184,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],23);
	visual_text((_Context->x_Auto3559+30+2),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),184,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],23,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+194),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][24],5);
	visual_text((_Context->x_Auto3559+30+194),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][24],5,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+242),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][30],8);
	visual_text((_Context->x_Auto3559+30+242),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][30],8,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+314),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][39],5);
	visual_text((_Context->x_Auto3559+30+314),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][39],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+362),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][45],5);
	visual_text((_Context->x_Auto3559+30+362),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][45],5,0);
		break;
	case	0x6 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+410),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][51],5);
	visual_text((_Context->x_Auto3559+30+410),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][51],5,0);
		break;
	case	0x7 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+458),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),240,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][57],30);
	visual_text((_Context->x_Auto3559+30+458),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),240,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][57],30,0);
		break;
		}
;
	}
	else{
	_Context->x_TypeSelect=_Context->x_Auto3559+272;_Context->y_TypeSelect=_Context->y_Auto3559+50;_Context->w_TypeSelect=72;_Context->h_TypeSelect=128;;
	_Context->y_TypeSelect=_Context->y_Auto3559+70+(l*16);
	switch(dptr->type){
	case _ABAL_BYTE:_Context->value_TypeSelect=0;break;
	case _ABAL_WORD:_Context->value_TypeSelect=1;break;
	case _ABAL_BCD:_Context->value_TypeSelect=2;break;
	case _ABAL_STRING:_Context->value_TypeSelect=3;break;
	case _ABAL_LONG:_Context->value_TypeSelect=4;break;
	case _ABAL_FIELD:_Context->value_TypeSelect=5;break;
	case _ABAL_FILLER:_Context->value_TypeSelect=6;break;
	}
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
	switch(_Context->value_TypeSelect){
	case 0:dptr->type=_ABAL_BYTE;break;
	case 1:dptr->type=_ABAL_WORD;break;
	case 2:dptr->type=_ABAL_BCD;break;
	case 3:dptr->type=_ABAL_STRING;break;
	case 4:dptr->type=_ABAL_LONG;break;
	case 5:dptr->type=_ABAL_FIELD;break;
	case 6:dptr->type=_ABAL_FILLER;break;
	}
	}
	}
	else if(_Context->column_FormMembers==2){
	l=_Context->value_FormMembers;
	if(!(dptr=get_forms_member(l+_Context->value_MemberBar))){
		if (!_Context->value_FormMembers) _Context->value_FormMembers=1;	/* pour etre sur qu'on edite pas le titre */
	_Context->row_FormMembers = &_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0];
	switch (_Context->column_FormMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+2),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),184,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],23);
	visual_text((_Context->x_Auto3559+30+2),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),184,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],23,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+194),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][24],5);
	visual_text((_Context->x_Auto3559+30+194),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][24],5,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+242),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][30],8);
	visual_text((_Context->x_Auto3559+30+242),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][30],8,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+314),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][39],5);
	visual_text((_Context->x_Auto3559+30+314),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][39],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+362),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][45],5);
	visual_text((_Context->x_Auto3559+30+362),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][45],5,0);
		break;
	case	0x6 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+410),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][51],5);
	visual_text((_Context->x_Auto3559+30+410),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][51],5,0);
		break;
	case	0x7 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+458),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),240,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][57],30);
	visual_text((_Context->x_Auto3559+30+458),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),240,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][57],30,0);
		break;
		}
;
	}
	else{
	if(dptr->type&8)
	_Context->value_PtrCheck=1;
	else _Context->value_PtrCheck=0;
	_Context->y_PtrCheck=_Context->y_Auto3559+70+(l*16);
		visual_select(_Context->x_PtrCheck,_Context->y_PtrCheck,_Context->w_PtrCheck,_Context->h_PtrCheck,_Context->fid_PtrCheck,27,28,parse_selection(_Context->msg_PtrCheck[_Context->language],&_Context->value_PtrCheck),0);
;
		_Context->keycode = visual_select(_Context->x_PtrCheck,_Context->y_PtrCheck,_Context->w_PtrCheck,_Context->h_PtrCheck,_Context->fid_PtrCheck,27,28,parse_selection(_Context->msg_PtrCheck[_Context->language],&_Context->value_PtrCheck),2);
;
	;
	dptr->type&=0xFFE7;
	dptr->type|=(_Context->value_PtrCheck<<3);
	}
	}
	else{
		if (!_Context->value_FormMembers) _Context->value_FormMembers=1;	/* pour etre sur qu'on edite pas le titre */
	_Context->row_FormMembers = &_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0];
	switch (_Context->column_FormMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+2),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),184,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],23);
	visual_text((_Context->x_Auto3559+30+2),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),184,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][0],23,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+194),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][24],5);
	visual_text((_Context->x_Auto3559+30+194),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][24],5,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+242),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][30],8);
	visual_text((_Context->x_Auto3559+30+242),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][30],8,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+314),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][39],5);
	visual_text((_Context->x_Auto3559+30+314),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][39],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+362),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][45],5);
	visual_text((_Context->x_Auto3559+30+362),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][45],5,0);
		break;
	case	0x6 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+410),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][51],5);
	visual_text((_Context->x_Auto3559+30+410),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][51],5,0);
		break;
	case	0x7 :
		_Context->keycode=visual_edit((_Context->x_Auto3559+30+458),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),240,16,vfh[1],&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][57],30);
	visual_text((_Context->x_Auto3559+30+458),(_Context->y_Auto3559+70+(_Context->value_FormMembers*16)+2),240,16,vfh[1],0,(24-((_Context->value_FormMembers-1)&1)),&_Context->buffer_FormMembers[(_Context->value_FormMembers-1)][57],30,0);
		break;
		}
;
	}
		return(-1);
}


public	int	accept_form_control_focus(struct accept_form_control_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* FormControl */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Auto3568 */
				_Context->trigger_Auto3568=visual_trigger_code(_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]));
				visual_button(_Context->x_Auto3559+10,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3568=visual_trigger_code(_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]));
	visual_button(_Context->x_Auto3559+10,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]),1040);
				break;
			case	0x4 :
				/* Auto3569 */
				_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
				visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1040);
				break;
			case	0x5 :
				/* FormType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3559+50,_Context->y_Auto3559+120,140,144,vfh[2],27,0,parse_selection(FormTypeList,&_Context->value_FormType),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* ProductionLanguage */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3559+200,_Context->y_Auto3559+120,140,144,vfh[2],27,0,parse_selection(ProductionLanguageList,&_Context->value_ProductionLanguage),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* NationalLanguage */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3559+350,_Context->y_Auto3559+120,140,144,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* International */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+190,322,16,vfh[2],28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),(_Context->value_International |2));
					_Context->keycode = visual_getch();
					_Context->trigger_International=visual_trigger_code(_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+190,322,16,vfh[2],28,28,_Context->msg_International[_Context->language],strlen(_Context->msg_International[_Context->language]),_Context->value_International|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Constants */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+220,294,16,vfh[2],28,28,_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]),(_Context->value_Constants |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Constants=visual_trigger_code(_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+220,294,16,vfh[2],28,28,_Context->msg_Constants[_Context->language],strlen(_Context->msg_Constants[_Context->language]),_Context->value_Constants|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* MultipleLanguage */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+190,280,16,vfh[2],28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),(_Context->value_MultipleLanguage |2));
					_Context->keycode = visual_getch();
					_Context->trigger_MultipleLanguage=visual_trigger_code(_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+190,280,16,vfh[2],28,28,_Context->msg_MultipleLanguage[_Context->language],strlen(_Context->msg_MultipleLanguage[_Context->language]),_Context->value_MultipleLanguage|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Program */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+160,322,16,vfh[2],27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),(_Context->value_Program |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_Program != (void *) 0)
					&& (_Context->s_Program == 0)) {
						(void)visual_buffer_get(_Context->p_Program,_Context->x_Auto3559+50,_Context->y_Auto3559+160);
						_Context->s_Program=1;
						}
					_Context->trigger_Program=visual_trigger_code(_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+160,322,16,vfh[2],27,0,_Context->msg_Program[_Context->language],strlen(_Context->msg_Program[_Context->language]),_Context->value_Program|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* Overlay */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+160,280,16,vfh[2],27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),(_Context->value_Overlay |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_Overlay != (void *) 0)
					&& (_Context->s_Overlay == 0)) {
						(void)visual_buffer_get(_Context->p_Overlay,_Context->x_Auto3559+400,_Context->y_Auto3559+160);
						_Context->s_Overlay=1;
						}
					_Context->trigger_Overlay=visual_trigger_code(_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+160,280,16,vfh[2],27,0,_Context->msg_Overlay[_Context->language],strlen(_Context->msg_Overlay[_Context->language]),_Context->value_Overlay|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* PopUp */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+220,294,16,vfh[2],27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),(_Context->value_PopUp |2));
					_Context->keycode = visual_getch();
					_Context->trigger_PopUp=visual_trigger_code(_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+220,294,16,vfh[2],27,0,_Context->msg_PopUp[_Context->language],strlen(_Context->msg_PopUp[_Context->language]),_Context->value_PopUp|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* Dynamic */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+250,280,16,vfh[2],27,0,_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]),(_Context->value_Dynamic |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Dynamic=visual_trigger_code(_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]));
	visual_check(_Context->x_Auto3559+400,_Context->y_Auto3559+250,280,16,vfh[2],27,0,_Context->msg_Dynamic[_Context->language],strlen(_Context->msg_Dynamic[_Context->language]),_Context->value_Dynamic|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* CommandLine */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+280,266,16,vfh[2],28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),(_Context->value_CommandLine |2));
					_Context->keycode = visual_getch();
					_Context->trigger_CommandLine=visual_trigger_code(_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+280,266,16,vfh[2],28,28,_Context->msg_CommandLine[_Context->language],strlen(_Context->msg_CommandLine[_Context->language]),_Context->value_CommandLine|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* ArgVLen */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+400+1,_Context->y_Auto3559+280+1,96,16,vfh[1],_Context->buffer_ArgVLen,12);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* ArgVNb */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+510+1,_Context->y_Auto3559+280+1,104,16,vfh[1],_Context->buffer_ArgVNb,13);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* Resize */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+310,264,16,vfh[2],27,28,_Context->msg_Resize[_Context->language],strlen(_Context->msg_Resize[_Context->language]),(_Context->value_Resize |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Resize=visual_trigger_code(_Context->msg_Resize[_Context->language],strlen(_Context->msg_Resize[_Context->language]));
	visual_check(_Context->x_Auto3559+50,_Context->y_Auto3559+310,264,16,vfh[2],27,28,_Context->msg_Resize[_Context->language],strlen(_Context->msg_Resize[_Context->language]),_Context->value_Resize|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* ResizeX */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+400+1,_Context->y_Auto3559+310+1,72,16,vfh[1],_Context->buffer_ResizeX,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* ResizeY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+540+1,_Context->y_Auto3559+310+1,72,16,vfh[1],_Context->buffer_ResizeY,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* GenHelp */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3559+510,_Context->y_Auto3559+120,112,48,vfh[2],0,0,parse_selection(_Context->msg_GenHelp[_Context->language],&_Context->value_GenHelp),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* ActHelp */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3559+630,_Context->y_Auto3559+120,112,48,vfh[2],0,0,parse_selection(_Context->msg_ActHelp[_Context->language],&_Context->value_ActHelp),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* FileName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+40+1,_Context->y_Auto3559+370+1,672,16,vfh[1],_Context->buffer_FileName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* ChooseFileName */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChooseFileName=visual_trigger_code(_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]));
					visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+370,32,16,vfh[8],27,28,_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChooseFileName=visual_trigger_code(_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+370,32,16,vfh[8],27,28,_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* ChooseStyleName */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
					visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+470,32,16,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+470,32,16,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* EditSource */
				if (_Context->page_number == 1 ) {
					_Context->trigger_EditSource=visual_trigger_code(_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]));
					visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+390,32,16,vfh[8],27,28,_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]),770);
					_Context->keycode = visual_getch();
					_Context->trigger_EditSource=visual_trigger_code(_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+390,32,16,vfh[8],27,28,_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]),768);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* EditStyle */
				if (_Context->page_number == 1 ) {
					_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
					visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+490,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),770);
					_Context->keycode = visual_getch();
					_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+490,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* Identity */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+40+1,_Context->y_Auto3559+420+1,336,16,vfh[1],_Context->buffer_Identity,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* StyleSheet */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+40+1,_Context->y_Auto3559+470+1,336,16,vfh[1],_Context->buffer_StyleSheet,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* ChoosePalette */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChoosePalette=visual_trigger_code(_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]));
					visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+420,36,16,vfh[8],27,28,_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoosePalette=visual_trigger_code(_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+420,36,16,vfh[8],27,28,_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* PaletteName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+380+1,_Context->y_Auto3559+420+1,336,16,vfh[1],_Context->buffer_PaletteName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* ClearScreen */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3559+380+1,_Context->y_Auto3559+470+1,336,16,vfh[1],_Context->buffer_ClearScreen,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* MouseEvents */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x24 :
				/* SendLeft */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+100,238,16,vfh[2],27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),(_Context->value_SendLeft |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendLeft=visual_trigger_code(_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+100,238,16,vfh[2],27,0,_Context->msg_SendLeft[_Context->language],strlen(_Context->msg_SendLeft[_Context->language]),_Context->value_SendLeft|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* SendMiddle */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+100,210,16,vfh[2],27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),(_Context->value_SendMiddle |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendMiddle=visual_trigger_code(_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+100,210,16,vfh[2],27,0,_Context->msg_SendMiddle[_Context->language],strlen(_Context->msg_SendMiddle[_Context->language]),_Context->value_SendMiddle|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* SendRight */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+120,224,16,vfh[2],27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),(_Context->value_SendRight |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendRight=visual_trigger_code(_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+120,224,16,vfh[2],27,0,_Context->msg_SendRight[_Context->language],strlen(_Context->msg_SendRight[_Context->language]),_Context->value_SendRight|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* SendWheel */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+120,224,16,vfh[2],27,0,_Context->msg_SendWheel[_Context->language],strlen(_Context->msg_SendWheel[_Context->language]),(_Context->value_SendWheel |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendWheel=visual_trigger_code(_Context->msg_SendWheel[_Context->language],strlen(_Context->msg_SendWheel[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+120,224,16,vfh[2],27,0,_Context->msg_SendWheel[_Context->language],strlen(_Context->msg_SendWheel[_Context->language]),_Context->value_SendWheel|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* ButtonFilter */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+100,224,16,vfh[2],27,0,_Context->msg_ButtonFilter[_Context->language],strlen(_Context->msg_ButtonFilter[_Context->language]),(_Context->value_ButtonFilter |2));
					_Context->keycode = visual_getch();
					_Context->trigger_ButtonFilter=visual_trigger_code(_Context->msg_ButtonFilter[_Context->language],strlen(_Context->msg_ButtonFilter[_Context->language]));
	visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+100,224,16,vfh[2],27,0,_Context->msg_ButtonFilter[_Context->language],strlen(_Context->msg_ButtonFilter[_Context->language]),_Context->value_ButtonFilter|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* SendDown */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+190,224,16,vfh[2],27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),(_Context->value_SendDown |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendDown=visual_trigger_code(_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+190,224,16,vfh[2],27,0,_Context->msg_SendDown[_Context->language],strlen(_Context->msg_SendDown[_Context->language]),_Context->value_SendDown|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* SendUp */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+190,196,16,vfh[2],27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),(_Context->value_SendUp |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendUp=visual_trigger_code(_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+190,196,16,vfh[2],27,0,_Context->msg_SendUp[_Context->language],strlen(_Context->msg_SendUp[_Context->language]),_Context->value_SendUp|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* SendWhileDown */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+210,238,16,vfh[2],27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),(_Context->value_SendWhileDown |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendWhileDown=visual_trigger_code(_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+210,238,16,vfh[2],27,0,_Context->msg_SendWhileDown[_Context->language],strlen(_Context->msg_SendWhileDown[_Context->language]),_Context->value_SendWhileDown|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* SendMove */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+210,196,16,vfh[2],16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),(_Context->value_SendMove |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SendMove=visual_trigger_code(_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]));
	visual_check(_Context->x_Auto3559+280,_Context->y_Auto3559+210,196,16,vfh[2],16,0,_Context->msg_SendMove[_Context->language],strlen(_Context->msg_SendMove[_Context->language]),_Context->value_SendMove|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* MouseKey */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+190,196,16,vfh[2],16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),(_Context->value_MouseKey |2));
					_Context->keycode = visual_getch();
					_Context->trigger_MouseKey=visual_trigger_code(_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]));
	visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+190,196,16,vfh[2],16,0,_Context->msg_MouseKey[_Context->language],strlen(_Context->msg_MouseKey[_Context->language]),_Context->value_MouseKey|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* WidgetTriggers */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+210,210,16,vfh[2],16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),(_Context->value_WidgetTriggers |2));
					_Context->keycode = visual_getch();
					_Context->trigger_WidgetTriggers=visual_trigger_code(_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]));
	visual_check(_Context->x_Auto3559+490,_Context->y_Auto3559+210,210,16,vfh[2],16,0,_Context->msg_WidgetTriggers[_Context->language],strlen(_Context->msg_WidgetTriggers[_Context->language]),_Context->value_WidgetTriggers|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* Escape */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+280,700,16,vfh[2],27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),(_Context->value_Escape |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_Escape != (void *) 0)
					&& (_Context->s_Escape == 0)) {
						(void)visual_buffer_get(_Context->p_Escape,_Context->x_Auto3559+40,_Context->y_Auto3559+280);
						_Context->s_Escape=1;
						}
					_Context->trigger_Escape=visual_trigger_code(_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+280,700,16,vfh[2],27,0,_Context->msg_Escape[_Context->language],strlen(_Context->msg_Escape[_Context->language]),_Context->value_Escape|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* Enter */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+460,700,16,vfh[2],27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),(_Context->value_Enter |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_Enter != (void *) 0)
					&& (_Context->s_Enter == 0)) {
						(void)visual_buffer_get(_Context->p_Enter,_Context->x_Auto3559+40,_Context->y_Auto3559+460);
						_Context->s_Enter=1;
						}
					_Context->trigger_Enter=visual_trigger_code(_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+460,700,16,vfh[2],27,0,_Context->msg_Enter[_Context->language],strlen(_Context->msg_Enter[_Context->language]),_Context->value_Enter|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* PageUp */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+310,700,16,vfh[2],27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),(_Context->value_PageUp |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_PageUp != (void *) 0)
					&& (_Context->s_PageUp == 0)) {
						(void)visual_buffer_get(_Context->p_PageUp,_Context->x_Auto3559+40,_Context->y_Auto3559+310);
						_Context->s_PageUp=1;
						}
					_Context->trigger_PageUp=visual_trigger_code(_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+310,700,16,vfh[2],27,0,_Context->msg_PageUp[_Context->language],strlen(_Context->msg_PageUp[_Context->language]),_Context->value_PageUp|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* PageDown */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+340,700,16,vfh[2],27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),(_Context->value_PageDown |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_PageDown != (void *) 0)
					&& (_Context->s_PageDown == 0)) {
						(void)visual_buffer_get(_Context->p_PageDown,_Context->x_Auto3559+40,_Context->y_Auto3559+340);
						_Context->s_PageDown=1;
						}
					_Context->trigger_PageDown=visual_trigger_code(_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+340,700,16,vfh[2],27,0,_Context->msg_PageDown[_Context->language],strlen(_Context->msg_PageDown[_Context->language]),_Context->value_PageDown|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* UpArrow */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+370,700,16,vfh[2],27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),(_Context->value_UpArrow |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_UpArrow != (void *) 0)
					&& (_Context->s_UpArrow == 0)) {
						(void)visual_buffer_get(_Context->p_UpArrow,_Context->x_Auto3559+40,_Context->y_Auto3559+370);
						_Context->s_UpArrow=1;
						}
					_Context->trigger_UpArrow=visual_trigger_code(_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+370,700,16,vfh[2],27,0,_Context->msg_UpArrow[_Context->language],strlen(_Context->msg_UpArrow[_Context->language]),_Context->value_UpArrow|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* DownArrow */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+400,700,16,vfh[2],27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),(_Context->value_DownArrow |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_DownArrow != (void *) 0)
					&& (_Context->s_DownArrow == 0)) {
						(void)visual_buffer_get(_Context->p_DownArrow,_Context->x_Auto3559+40,_Context->y_Auto3559+400);
						_Context->s_DownArrow=1;
						}
					_Context->trigger_DownArrow=visual_trigger_code(_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+400,700,16,vfh[2],27,0,_Context->msg_DownArrow[_Context->language],strlen(_Context->msg_DownArrow[_Context->language]),_Context->value_DownArrow|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* Tabulation */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+430,700,16,vfh[2],27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),(_Context->value_Tabulation |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_Tabulation != (void *) 0)
					&& (_Context->s_Tabulation == 0)) {
						(void)visual_buffer_get(_Context->p_Tabulation,_Context->x_Auto3559+40,_Context->y_Auto3559+430);
						_Context->s_Tabulation=1;
						}
					_Context->trigger_Tabulation=visual_trigger_code(_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+430,700,16,vfh[2],27,0,_Context->msg_Tabulation[_Context->language],strlen(_Context->msg_Tabulation[_Context->language]),_Context->value_Tabulation|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* DefaultBreak */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+490,700,16,vfh[2],27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),(_Context->value_DefaultBreak |2));
					_Context->keycode = visual_getch();
					if ((_Context->p_DefaultBreak != (void *) 0)
					&& (_Context->s_DefaultBreak == 0)) {
						(void)visual_buffer_get(_Context->p_DefaultBreak,_Context->x_Auto3559+40,_Context->y_Auto3559+490);
						_Context->s_DefaultBreak=1;
						}
					_Context->trigger_DefaultBreak=visual_trigger_code(_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]));
	visual_check(_Context->x_Auto3559+40,_Context->y_Auto3559+490,700,16,vfh[2],27,0,_Context->msg_DefaultBreak[_Context->language],strlen(_Context->msg_DefaultBreak[_Context->language]),_Context->value_DefaultBreak|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x37 :
				/* FormMethods */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x39 :
				/* EditMethod */
				if (_Context->page_number == 3 ) {
					_Context->trigger_EditMethod=visual_trigger_code(_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]));
					visual_button(_Context->x_Auto3559+30,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_EditMethod=visual_trigger_code(_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+30,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3a :
				/* PasteMethod */
				if (_Context->page_number == 3 ) {
					if ((_Context->p_PasteMethod != (void *) 0)
					&& (_Context->s_PasteMethod == 0)) {
						(void)visual_buffer_get(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
						_Context->s_PasteMethod=1;
						}
					_Context->trigger_PasteMethod=visual_trigger_code(_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]));
					visual_button(_Context->x_Auto3559+380,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]),2);
					_Context->keycode = visual_getch();
					if ((_Context->p_PasteMethod != (void *) 0)
					&& (_Context->s_PasteMethod == 0)) {
						(void)visual_buffer_get(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
						_Context->s_PasteMethod=1;
						}
					_Context->trigger_PasteMethod=visual_trigger_code(_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+380,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3b :
				/* CopyMethod */
				if (_Context->page_number == 3 ) {
					_Context->trigger_CopyMethod=visual_trigger_code(_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]));
					visual_button(_Context->x_Auto3559+250,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_CopyMethod=visual_trigger_code(_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+250,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3c :
				/* DropMethod */
				if (_Context->page_number == 3 ) {
					_Context->trigger_DropMethod=visual_trigger_code(_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]));
					visual_button(_Context->x_Auto3559+610,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_DropMethod=visual_trigger_code(_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+610,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3d :
				/* ScrollBar */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3e :
				/* FormMemberPage */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3f :
				/* FormMembers */
				if (_Context->page_number == 4 ) {
					(void) on_FormMembers_getfocus(_Context);
					(void) on_FormMembers_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x40 :
				/* MemberBar */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			accept_form_control_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_form_control_show(_Context);
			continue;
		case	0x2 :
			accept_form_control_losefocus(_Context);
			_Context->page_number=4;
			_Context->focus_item=64;
			accept_form_control_show(_Context);
			continue;
		case	0x3 :
			accept_form_control_losefocus(_Context);
			if ( _Context->page_number < 4 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_form_control_show(_Context);
			continue;
		case	0x12 :
			accept_form_control_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_form_control_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_form_control_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (FormControl_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Auto3568_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Auto3569_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (FormType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (ProductionLanguage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (NationalLanguage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (International_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Constants_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (MultipleLanguage_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Program_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (Overlay_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (PopUp_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (Dynamic_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (ArgVLen_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (ArgVNb_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (FileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (ChooseFileName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (ChooseStyleName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (EditSource_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (EditStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1e :
						if (Identity_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1f :
						if (StyleSheet_help(_Context) != 0) { continue; }
						else { break; }
					case	0x20 :
						if (ChoosePalette_help(_Context) != 0) { continue; }
						else { break; }
					case	0x21 :
						if (PaletteName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x22 :
						if (ClearScreen_help(_Context) != 0) { continue; }
						else { break; }
					case	0x23 :
						if (MouseEvents_help(_Context) != 0) { continue; }
						else { break; }
					case	0x24 :
						if (SendLeft_help(_Context) != 0) { continue; }
						else { break; }
					case	0x25 :
						if (SendMiddle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x26 :
						if (SendRight_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (SendWheel_help(_Context) != 0) { continue; }
						else { break; }
					case	0x28 :
						if (ButtonFilter_help(_Context) != 0) { continue; }
						else { break; }
					case	0x29 :
						if (SendDown_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2a :
						if (SendUp_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2b :
						if (SendWhileDown_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2c :
						if (SendMove_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2e :
						if (WidgetTriggers_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2f :
						if (Escape_help(_Context) != 0) { continue; }
						else { break; }
					case	0x30 :
						if (Enter_help(_Context) != 0) { continue; }
						else { break; }
					case	0x31 :
						if (PageUp_help(_Context) != 0) { continue; }
						else { break; }
					case	0x32 :
						if (PageDown_help(_Context) != 0) { continue; }
						else { break; }
					case	0x33 :
						if (UpArrow_help(_Context) != 0) { continue; }
						else { break; }
					case	0x34 :
						if (DownArrow_help(_Context) != 0) { continue; }
						else { break; }
					case	0x35 :
						if (Tabulation_help(_Context) != 0) { continue; }
						else { break; }
					case	0x36 :
						if (DefaultBreak_help(_Context) != 0) { continue; }
						else { break; }
					case	0x37 :
						if (FormMethods_help(_Context) != 0) { continue; }
						else { break; }
					case	0x38 :
						if (Methods_help(_Context) != 0) { continue; }
						else { break; }
					case	0x39 :
						if (EditMethod_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3a :
						if (PasteMethod_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3b :
						if (CopyMethod_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3c :
						if (DropMethod_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3e :
						if (FormMemberPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3f :
						if (FormMembers_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3559 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* FormControl */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_form_control_losefocus(_Context);
						_Context->page_number = 1;
						accept_form_control_show(_Context);
						}
					continue;
				case	0x3 :
					/* Auto3568 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3568=visual_trigger_code(_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]));
						visual_button(_Context->x_Auto3559+10,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3568=visual_trigger_code(_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]));
	visual_button(_Context->x_Auto3559+10,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3568_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* Auto3569 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
						visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3569=visual_trigger_code(_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+540,56,48,vfh[2],34,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3569_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* FormType */
					continue;
				case	0x6 :
					/* ProductionLanguage */
					continue;
				case	0x7 :
					/* NationalLanguage */
					continue;
				case	0x8 :
					/* International */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_International += 1;
						_Context->value_International &= 1;
						}
					continue;
				case	0x9 :
					/* Constants */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Constants += 1;
						_Context->value_Constants &= 1;
						}
					continue;
				case	0xa :
					/* MultipleLanguage */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MultipleLanguage += 1;
						_Context->value_MultipleLanguage &= 1;
						}
					continue;
				case	0xb :
					/* Program */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Program += 1;
						_Context->value_Program &= 1;
						}
					continue;
				case	0xc :
					/* Overlay */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Overlay += 1;
						_Context->value_Overlay &= 1;
						}
					continue;
				case	0xd :
					/* PopUp */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_PopUp += 1;
						_Context->value_PopUp &= 1;
						}
					continue;
				case	0xe :
					/* Dynamic */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Dynamic += 1;
						_Context->value_Dynamic &= 1;
						}
					continue;
				case	0xf :
					/* CommandLine */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_CommandLine += 1;
						_Context->value_CommandLine &= 1;
						}
					continue;
				case	0x10 :
					/* ArgVLen */
					continue;
				case	0x11 :
					/* ArgVNb */
					continue;
				case	0x12 :
					/* Resize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Resize += 1;
						_Context->value_Resize &= 1;
						}
					continue;
				case	0x13 :
					/* ResizeX */
					continue;
				case	0x14 :
					/* ResizeY */
					continue;
				case	0x15 :
					/* GenHelp */
					continue;
				case	0x16 :
					/* ActHelp */
					continue;
				case	0x19 :
					/* FileName */
					continue;
				case	0x1a :
					/* ChooseFileName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChooseFileName=visual_trigger_code(_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]));
						visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+370,32,16,vfh[8],27,28,_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChooseFileName=visual_trigger_code(_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+370,32,16,vfh[8],27,28,_Context->msg_ChooseFileName[_Context->language],strlen(_Context->msg_ChooseFileName[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChooseFileName_event(_Context)) != -1) break;

						}
					continue;
				case	0x1b :
					/* ChooseStyleName */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
						visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+470,32,16,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChooseStyleName=visual_trigger_code(_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+470,32,16,vfh[8],27,28,_Context->msg_ChooseStyleName[_Context->language],strlen(_Context->msg_ChooseStyleName[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChooseStyleName_event(_Context)) != -1) break;

						}
					continue;
				case	0x1c :
					/* EditSource */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditSource=visual_trigger_code(_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]));
						visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+390,32,16,vfh[8],27,28,_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]),770);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditSource=visual_trigger_code(_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+390,32,16,vfh[8],27,28,_Context->msg_EditSource[_Context->language],strlen(_Context->msg_EditSource[_Context->language]),768);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditSource_event(_Context)) != -1) break;

						}
					continue;
				case	0x1d :
					/* EditStyle */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
						visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+490,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),770);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditStyle=visual_trigger_code(_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+490,32,16,vfh[8],27,28,_Context->msg_EditStyle[_Context->language],strlen(_Context->msg_EditStyle[_Context->language]),768);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditStyle_event(_Context)) != -1) break;

						}
					continue;
				case	0x1e :
					/* Identity */
					continue;
				case	0x1f :
					/* StyleSheet */
					continue;
				case	0x20 :
					/* ChoosePalette */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoosePalette=visual_trigger_code(_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]));
						visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+420,36,16,vfh[8],27,28,_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoosePalette=visual_trigger_code(_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]));
	visual_button(_Context->x_Auto3559+720,_Context->y_Auto3559+420,36,16,vfh[8],27,28,_Context->msg_ChoosePalette[_Context->language],strlen(_Context->msg_ChoosePalette[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoosePalette_event(_Context)) != -1) break;

						}
					continue;
				case	0x21 :
					/* PaletteName */
					continue;
				case	0x22 :
					/* ClearScreen */
					continue;
				case	0x23 :
					/* MouseEvents */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_form_control_losefocus(_Context);
						_Context->page_number = 2;
						accept_form_control_show(_Context);
						}
					continue;
				case	0x24 :
					/* SendLeft */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendLeft += 1;
						_Context->value_SendLeft &= 1;
						}
					continue;
				case	0x25 :
					/* SendMiddle */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendMiddle += 1;
						_Context->value_SendMiddle &= 1;
						}
					continue;
				case	0x26 :
					/* SendRight */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendRight += 1;
						_Context->value_SendRight &= 1;
						}
					continue;
				case	0x27 :
					/* SendWheel */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendWheel += 1;
						_Context->value_SendWheel &= 1;
						}
					continue;
				case	0x28 :
					/* ButtonFilter */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ButtonFilter += 1;
						_Context->value_ButtonFilter &= 1;
						}
					continue;
				case	0x29 :
					/* SendDown */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendDown += 1;
						_Context->value_SendDown &= 1;
						}
					continue;
				case	0x2a :
					/* SendUp */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendUp += 1;
						_Context->value_SendUp &= 1;
						}
					continue;
				case	0x2b :
					/* SendWhileDown */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendWhileDown += 1;
						_Context->value_SendWhileDown &= 1;
						}
					continue;
				case	0x2c :
					/* SendMove */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SendMove += 1;
						_Context->value_SendMove &= 1;
						}
					continue;
				case	0x2d :
					/* MouseKey */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MouseKey += 1;
						_Context->value_MouseKey &= 1;
						}
					continue;
				case	0x2e :
					/* WidgetTriggers */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_WidgetTriggers += 1;
						_Context->value_WidgetTriggers &= 1;
						}
					continue;
				case	0x2f :
					/* Escape */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Escape += 1;
						_Context->value_Escape &= 1;
						}
					continue;
				case	0x30 :
					/* Enter */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Enter += 1;
						_Context->value_Enter &= 1;
						}
					continue;
				case	0x31 :
					/* PageUp */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_PageUp += 1;
						_Context->value_PageUp &= 1;
						}
					continue;
				case	0x32 :
					/* PageDown */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_PageDown += 1;
						_Context->value_PageDown &= 1;
						}
					continue;
				case	0x33 :
					/* UpArrow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_UpArrow += 1;
						_Context->value_UpArrow &= 1;
						}
					continue;
				case	0x34 :
					/* DownArrow */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_DownArrow += 1;
						_Context->value_DownArrow &= 1;
						}
					continue;
				case	0x35 :
					/* Tabulation */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Tabulation += 1;
						_Context->value_Tabulation &= 1;
						}
					continue;
				case	0x36 :
					/* DefaultBreak */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_DefaultBreak += 1;
						_Context->value_DefaultBreak &= 1;
						}
					continue;
				case	0x37 :
					/* FormMethods */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_form_control_losefocus(_Context);
						_Context->page_number = 3;
						accept_form_control_show(_Context);
						}
					continue;
				case	0x38 :
					/* Methods */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Methods_event(_Context)) != -1) break;

						}
					continue;
				case	0x39 :
					/* EditMethod */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditMethod=visual_trigger_code(_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]));
						visual_button(_Context->x_Auto3559+30,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditMethod=visual_trigger_code(_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+30,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_EditMethod[_Context->language],strlen(_Context->msg_EditMethod[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditMethod_event(_Context)) != -1) break;

						}
					continue;
				case	0x3a :
					/* PasteMethod */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_PasteMethod != (void *) 0)
						&& (_Context->s_PasteMethod == 0)) {
							(void)visual_buffer_get(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
							_Context->s_PasteMethod=1;
							}
						_Context->trigger_PasteMethod=visual_trigger_code(_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]));
						visual_button(_Context->x_Auto3559+380,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_PasteMethod != (void *) 0)
						&& (_Context->s_PasteMethod == 0)) {
							(void)visual_buffer_get(_Context->p_PasteMethod,_Context->x_Auto3559+380,_Context->y_Auto3559+490);
							_Context->s_PasteMethod=1;
							}
						_Context->trigger_PasteMethod=visual_trigger_code(_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+380,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_PasteMethod[_Context->language],strlen(_Context->msg_PasteMethod[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_PasteMethod_event(_Context)) != -1) break;

						}
					continue;
				case	0x3b :
					/* CopyMethod */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_CopyMethod=visual_trigger_code(_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]));
						visual_button(_Context->x_Auto3559+250,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_CopyMethod=visual_trigger_code(_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+250,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_CopyMethod[_Context->language],strlen(_Context->msg_CopyMethod[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CopyMethod_event(_Context)) != -1) break;

						}
					continue;
				case	0x3c :
					/* DropMethod */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DropMethod=visual_trigger_code(_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]));
						visual_button(_Context->x_Auto3559+610,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DropMethod=visual_trigger_code(_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]));
	visual_button(_Context->x_Auto3559+610,_Context->y_Auto3559+490,126,32,vfh[2],28,28,_Context->msg_DropMethod[_Context->language],strlen(_Context->msg_DropMethod[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DropMethod_event(_Context)) != -1) break;

						}
					continue;
				case	0x3d :
					/* ScrollBar */
					(void) on_ScrollBar_action(_Context);
					continue;
				case	0x3e :
					/* FormMemberPage */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_form_control_losefocus(_Context);
						_Context->page_number = 4;
						accept_form_control_show(_Context);
						}
					continue;
				case	0x3f :
					/* FormMembers */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FormMembers_event(_Context)) != -1) break;

						}
					continue;
				case	0x40 :
					/* MemberBar */
					(void) on_MemberBar_action(_Context);
					continue;
				case	0xffffffff :
				default :
					_Context->focus_item=1;
				continue;
				}
				break;
		case	0x1b :
			break;
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
				_Context->focus_item=64;
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

public	int	accept_form_control(
	char * pFormType,
	char * pProductionLanguage,
	char * pNationalLanguage,
	char * pInternational,
	char * pConstants,
	char * pMultipleLanguage,
	char * pProgram,
	char * pOverlay,
	char * pPopUp,
	char * pDynamic,
	char * pCommandLine,
	char * pArgVLen,
	char * pArgVNb,
	char * pResize,
	char * pResizeX,
	char * pResizeY,
	char * pGenHelp,
	char * pActHelp,
	char * pFileName,
	char * pIdentity,
	char * pStyleSheet,
	char * pPaletteName,
	char * pClearScreen,
	char * pSendLeft,
	char * pSendMiddle,
	char * pSendRight,
	char * pSendWheel,
	char * pButtonFilter,
	char * pSendDown,
	char * pSendUp,
	char * pSendWhileDown,
	char * pSendMove,
	char * pMouseKey,
	char * pWidgetTriggers,
	char * pEscape,
	char * pEnter,
	char * pPageUp,
	char * pPageDown,
	char * pUpArrow,
	char * pDownArrow,
	char * pTabulation,
	char * pDefaultBreak)
{
	int	status=0;
	struct accept_form_control_context * _Context=(struct accept_form_control_context*) 0;
	status = accept_form_control_create(
	&_Context,
	 pFormType,
	 pProductionLanguage,
	 pNationalLanguage,
	 pInternational,
	 pConstants,
	 pMultipleLanguage,
	 pProgram,
	 pOverlay,
	 pPopUp,
	 pDynamic,
	 pCommandLine,
	 pArgVLen,
	 pArgVNb,
	 pResize,
	 pResizeX,
	 pResizeY,
	 pGenHelp,
	 pActHelp,
	 pFileName,
	 pIdentity,
	 pStyleSheet,
	 pPaletteName,
	 pClearScreen,
	 pSendLeft,
	 pSendMiddle,
	 pSendRight,
	 pSendWheel,
	 pButtonFilter,
	 pSendDown,
	 pSendUp,
	 pSendWhileDown,
	 pSendMove,
	 pMouseKey,
	 pWidgetTriggers,
	 pEscape,
	 pEnter,
	 pPageUp,
	 pPageDown,
	 pUpArrow,
	 pDownArrow,
	 pTabulation,
	 pDefaultBreak);
	if ( status != 0) return(status);
	status = accept_form_control_show(_Context);
		enter_modal();
	status = accept_form_control_focus(_Context);
		leave_modal();
	status = accept_form_control_hide(_Context);
	status = accept_form_control_remove(
	_Context,
	 pFormType,
	 pProductionLanguage,
	 pNationalLanguage,
	 pInternational,
	 pConstants,
	 pMultipleLanguage,
	 pProgram,
	 pOverlay,
	 pPopUp,
	 pDynamic,
	 pCommandLine,
	 pArgVLen,
	 pArgVNb,
	 pResize,
	 pResizeX,
	 pResizeY,
	 pGenHelp,
	 pActHelp,
	 pFileName,
	 pIdentity,
	 pStyleSheet,
	 pPaletteName,
	 pClearScreen,
	 pSendLeft,
	 pSendMiddle,
	 pSendRight,
	 pSendWheel,
	 pButtonFilter,
	 pSendDown,
	 pSendUp,
	 pSendWhileDown,
	 pSendMove,
	 pMouseKey,
	 pWidgetTriggers,
	 pEscape,
	 pEnter,
	 pPageUp,
	 pPageDown,
	 pUpArrow,
	 pDownArrow,
	 pTabulation,
	 pDefaultBreak);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vform31e_c */
