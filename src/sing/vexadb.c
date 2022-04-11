
#ifndef _vexadb_c
#define _vexadb_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vexadb.xml                                               */
/* Target         : vexadb.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Main   "Exadb : Version 3.1a.0.01"
#define fr_Main   "Exadb : Version 3.1a.0.01"
#define it_Main   "Exadb : Version 3.1a.0.01"
#define es_Main   "Exadb : Version 3.1a.0.01"
#define de_Main   "Exadb : Version 3.1a.0.01"
#define nl_Main   "Exadb : Version 3.1a.0.01"
#define pt_Main   "Exadb : Version 3.1a.0.01"
#define xx_Main   "Exadb : Version 3.1a.0.01"
#define en__Main   ""
#define en_ProgramSource   "&Source"
#define fr_ProgramSource   "&Source"
#define it_ProgramSource   "&Source"
#define es_ProgramSource   "&Source"
#define de_ProgramSource   "&Source"
#define nl_ProgramSource   "&Source"
#define pt_ProgramSource   "&Source"
#define xx_ProgramSource   "&Source"
#define en__ProgramSource   ""
#define fr__ProgramSource   ""
#define it__ProgramSource   ""
#define es__ProgramSource   ""
#define de__ProgramSource   ""
#define nl__ProgramSource   ""
#define pt__ProgramSource   ""
#define xx__ProgramSource   ""
#define en__Auto3552   ""
#define fr__Auto3552   ""
#define it__Auto3552   ""
#define es__Auto3552   ""
#define de__Auto3552   ""
#define nl__Auto3552   ""
#define pt__Auto3552   ""
#define xx__Auto3552   ""
#define en_Auto3553   ""
#define en__Auto3553   ""
#define en__Auto3554   ""
#define fr__Auto3554   ""
#define it__Auto3554   ""
#define es__Auto3554   ""
#define de__Auto3554   ""
#define nl__Auto3554   ""
#define pt__Auto3554   ""
#define xx__Auto3554   ""
#define en_Auto3555   ""
#define en__Auto3555   ""
#define en__BreakManager   ""
#define fr__BreakManager   ""
#define it__BreakManager   ""
#define es__BreakManager   ""
#define de__BreakManager   ""
#define nl__BreakManager   ""
#define pt__BreakManager   ""
#define xx__BreakManager   ""
#define en_BreakFrame   ""
#define fr_BreakFrame   ""
#define en__BreakFrame   ""
#define en__BreakPoint   ""
#define fr__BreakPoint   ""
#define it__BreakPoint   ""
#define es__BreakPoint   ""
#define de__BreakPoint   ""
#define nl__BreakPoint   ""
#define pt__BreakPoint   ""
#define xx__BreakPoint   ""
#define en__StepInto   "execute single instruction : step into"
#define fr__StepInto   "executer ligne pas a pas"
#define it__StepInto   "execute single instruction : step into"
#define es__StepInto   "execute single instruction : step into"
#define de__StepInto   "execute single instruction : step into"
#define nl__StepInto   "execute single instruction : step into"
#define pt__StepInto   "execute single instruction : step into"
#define xx__StepInto   "execute single instruction : step into"
#define en__Goto   "execute up to current source line position"
#define fr__Goto   "executer jusqu'a la ligne source courante"
#define it__Goto   "execute up to current source line position"
#define es__Goto   "execute up to current source line position"
#define de__Goto   "execute up to current source line position"
#define nl__Goto   "execute up to current source line position"
#define pt__Goto   "execute up to current source line position"
#define xx__Goto   "execute up to current source line position"
#define en__Run   "execute till breakpoint or stop"
#define fr__Run   "lancer l'execution"
#define it__Run   "execute till breakpoint or stop"
#define es__Run   "execute till breakpoint or stop"
#define de__Run   "execute till breakpoint or stop"
#define nl__Run   "execute till breakpoint or stop"
#define pt__Run   "execute till breakpoint or stop"
#define xx__Run   "execute till breakpoint or stop"
#define en__Restart   "Restart current debug session"
#define fr__Restart   "Relancer l'execution depuis le debut"
#define it__Restart   "Restart current debug session"
#define es__Restart   "Restart current debug session"
#define de__Restart   "Restart current debug session"
#define nl__Restart   "Restart current debug session"
#define pt__Restart   "Restart current debug session"
#define xx__Restart   "Restart current debug session"
#define en__Break   "set breakpoint ot editor cursor position"
#define fr__Break   "etablir point d'arret a la position curseur de l'editeur"
#define it__Break   "set breakpoint ot editor cursor position"
#define es__Break   "set breakpoint ot editor cursor position"
#define de__Break   "set breakpoint ot editor cursor position"
#define nl__Break   "set breakpoint ot editor cursor position"
#define pt__Break   "set breakpoint ot editor cursor position"
#define xx__Break   "set breakpoint ot editor cursor position"
#define en__ClearBreak   "clear breakpoints for each occurance of this source line"
#define fr__ClearBreak   "d‚sactiver chaque point d'arr‚t pour ce ligne source."
#define it__ClearBreak   "clear all breakpoints"
#define es__ClearBreak   "clear all breakpoints"
#define de__ClearBreak   "clear all breakpoints"
#define nl__ClearBreak   "clear all breakpoints"
#define pt__ClearBreak   "clear all breakpoints"
#define xx__ClearBreak   "clear all breakpoints"
#define en__View   "inspect variable value"
#define fr__View   "consulter valeur d'une variable"
#define it__View   "inspect variable value"
#define es__View   "inspect variable value"
#define de__View   "inspect variable value"
#define nl__View   "inspect variable value"
#define pt__View   "inspect variable value"
#define xx__View   "inspect variable value"
#define en__Help   "Display online help"
#define fr__Help   "Afficher ecran d'aide"
#define it__Help   "Display online help"
#define es__Help   "Display online help"
#define de__Help   "Display online help"
#define nl__Help   "Display online help"
#define pt__Help   "Display online help"
#define xx__Help   "Display online help"
#define en__Save   "Save debug configuration to file"
#define fr__Save   "Ecrire information de configuration"
#define it__Save   "Save debug configuration to file"
#define es__Save   "Save debug configuration to file"
#define de__Save   "Save debug configuration to file"
#define nl__Save   "Save debug configuration to file"
#define pt__Save   "Save debug configuration to file"
#define xx__Save   "Save debug configuration to file"
#define en__Exit   "exit from the debug utility"
#define fr__Exit   "Quiter le moniteur de mise au point"
#define it__Exit   "exit from the debug utility"
#define es__Exit   "exit from the debug utility"
#define de__Exit   "exit from the debug utility"
#define nl__Exit   "exit from the debug utility"
#define pt__Exit   "exit from the debug utility"
#define xx__Exit   "exit from the debug utility"
#define en_BreakKey   "Intr"
#define fr_BreakKey   "Intr"
#define it_BreakKey   "Intr"
#define es_BreakKey   "Intr"
#define de_BreakKey   "Intr"
#define nl_BreakKey   "Intr"
#define pt_BreakKey   "Intr"
#define xx_BreakKey   "Intr"
#define en__BreakKey   "toggle break key"
#define fr__BreakKey   "Activer / Desactiver le touche d'interuption d'execution"
#define it__BreakKey   ""
#define es__BreakKey   ""
#define de__BreakKey   ""
#define nl__BreakKey   ""
#define pt__BreakKey   ""
#define xx__BreakKey   ""
#define en_AsmList   "List"
#define fr_AsmList   "List"
#define it_AsmList   "List"
#define es_AsmList   "List"
#define de_AsmList   "List"
#define nl_AsmList   "List"
#define pt_AsmList   "List"
#define xx_AsmList   "List"
#define en__AsmList   "toggle tcode list display"
#define fr__AsmList   "Basculer entre affichage des sources et affichage code virtuel"
#define it__AsmList   "toggle tcode list display"
#define es__AsmList   "toggle tcode list display"
#define de__AsmList   "toggle tcode list display"
#define nl__AsmList   "toggle tcode list display"
#define pt__AsmList   "toggle tcode list display"
#define xx__AsmList   "toggle tcode list display"
#define en_SaveConfig   "Conf"
#define fr_SaveConfig   "Conf"
#define it_SaveConfig   "Conf"
#define es_SaveConfig   "Conf"
#define de_SaveConfig   "Conf"
#define nl_SaveConfig   "Conf"
#define pt_SaveConfig   "Conf"
#define xx_SaveConfig   "Conf"
#define en__SaveConfig   "toggle configuration save on exit"
#define fr__SaveConfig   "activer / desactiver sauvegarde du configuration en sortie"
#define it__SaveConfig   "toggle configuration save on exit"
#define es__SaveConfig   "toggle configuration save on exit"
#define de__SaveConfig   "toggle configuration save on exit"
#define nl__SaveConfig   "toggle configuration save on exit"
#define pt__SaveConfig   "toggle configuration save on exit"
#define xx__SaveConfig   "toggle configuration save on exit"
#define en_HexaView   "Hexa"
#define fr_HexaView   "Hexa"
#define it_HexaView   "Hexa"
#define es_HexaView   "Hexa"
#define de_HexaView   "Hexa"
#define nl_HexaView   "Hexa"
#define pt_HexaView   "Hexa"
#define xx_HexaView   "Hexa"
#define en__HexaView   "toggle variable value display type"
#define fr__HexaView   "Activer / Desactiver affichage hex de variables"
#define it__HexaView   "toggle variable display value"
#define es__HexaView   "toggle variable display value"
#define de__HexaView   "toggle variable display value"
#define nl__HexaView   "toggle variable display value"
#define pt__HexaView   "toggle variable display value"
#define xx__HexaView   "toggle variable display value"
#define en_Dbio   ""
#define en__Dbio   ""
#define en__BreakBar   ""
#define fr__BreakBar   ""
#define it__BreakBar   ""
#define es__BreakBar   ""
#define de__BreakBar   ""
#define nl__BreakBar   ""
#define pt__BreakBar   ""
#define xx__BreakBar   ""
#define en__DebugCursor   ""
#define fr__DebugCursor   ""
#define it__DebugCursor   ""
#define es__DebugCursor   ""
#define de__DebugCursor   ""
#define nl__DebugCursor   ""
#define pt__DebugCursor   ""
#define xx__DebugCursor   ""
#define en_ProgramOutput   "&Output"
#define fr_ProgramOutput   "&Output"
#define it_ProgramOutput   "&Output"
#define es_ProgramOutput   "&Output"
#define de_ProgramOutput   "&Output"
#define nl_ProgramOutput   "&Output"
#define pt_ProgramOutput   "&Output"
#define xx_ProgramOutput   "&Output"
#define en__ProgramOutput   ""
#define fr__ProgramOutput   ""
#define it__ProgramOutput   ""
#define es__ProgramOutput   ""
#define de__ProgramOutput   ""
#define nl__ProgramOutput   ""
#define pt__ProgramOutput   ""
#define xx__ProgramOutput   ""
#define en__Auto3556   ""
#define fr__Auto3556   ""
#define it__Auto3556   ""
#define es__Auto3556   ""
#define de__Auto3556   ""
#define nl__Auto3556   ""
#define pt__Auto3556   ""
#define xx__Auto3556   ""
#define en_Prio   ""
#define en__Prio   ""
#define en_VSB   ""
#define en__VSB   ""
#define en_DebugControl   "&Control"
#define fr_DebugControl   "&Control"
#define it_DebugControl   "&Control"
#define es_DebugControl   "&Control"
#define de_DebugControl   "&Control"
#define nl_DebugControl   "&Control"
#define pt_DebugControl   "&Control"
#define xx_DebugControl   "&Control"
#define en__DebugControl   ""
#define fr__DebugControl   ""
#define it__DebugControl   ""
#define es__DebugControl   ""
#define de__DebugControl   ""
#define nl__DebugControl   ""
#define pt__DebugControl   ""
#define xx__DebugControl   ""
#define en__Auto3557   ""
#define fr__Auto3557   ""
#define it__Auto3557   ""
#define es__Auto3557   ""
#define de__Auto3557   ""
#define nl__Auto3557   ""
#define pt__Auto3557   ""
#define xx__Auto3557   ""
#define en_ErrAdr   ""
#define en__ErrAdr   ""
#define en_AskMask   ""
#define en__AskMask   ""
#define en_MouseMask   ""
#define en__MouseMask   ""
#define en_ErrorAdr   ""
#define en__ErrorAdr   ""
#define en_ErrorVal   ""
#define en__ErrorVal   ""
#define en_Auto3559   "ABAL++ Debug : Command and Control"
#define fr_Auto3559   "ABAL++ Debug"
#define it_Auto3559   "ABAL++ Debug : Command and Control"
#define es_Auto3559   "ABAL++ Debug : Command and Control"
#define de_Auto3559   "ABAL++ Debug : Command and Control"
#define nl_Auto3559   "ABAL++ Debug : Command and Control"
#define pt_Auto3559   "ABAL++ Debug : Command and Control"
#define xx_Auto3559   "ABAL++ Debug : Command and Control"
#define en_Auto3560   "Procedures"
#define fr_Auto3560   "Proc‚dures"
#define it_Auto3560   "Procedures"
#define es_Auto3560   "Procedures"
#define de_Auto3560   "Procedures"
#define nl_Auto3560   "Procedures"
#define pt_Auto3560   "Procedures"
#define xx_Auto3560   "Procedures"
#define en_Auto3561   "Segments"
#define fr_Auto3561   "Segments"
#define it_Auto3561   "Segments"
#define es_Auto3561   "Segments"
#define de_Auto3561   "Segments"
#define nl_Auto3561   "Segments"
#define pt_Auto3561   "Segments"
#define xx_Auto3561   "Segments"
#define en_Auto3562   "Global Variables"
#define fr_Auto3562   "Variables Globales"
#define it_Auto3562   "Global Variables"
#define es_Auto3562   "Global Variables"
#define de_Auto3562   "Global Variables"
#define nl_Auto3562   "Global Variables"
#define pt_Auto3562   "Global Variables"
#define xx_Auto3562   "Global Variables"
#define en_Auto3563   "Local Variables"
#define fr_Auto3563   "Variables Locales"
#define it_Auto3563   "Local Variables"
#define es_Auto3563   "Local Variables"
#define de_Auto3563   "Local Variables"
#define nl_Auto3563   "Local Variables"
#define pt_Auto3563   "Local Variables"
#define xx_Auto3563   "Local Variables"
#define en_Auto3564   "Activate Break Points"
#define fr_Auto3564   "Points d'arrˆts actifs"
#define it_Auto3564   "Activate Break Points"
#define es_Auto3564   "Activate Break Points"
#define de_Auto3564   "Activate Break Points"
#define nl_Auto3564   "Activate Break Points"
#define pt_Auto3564   "Activate Break Points"
#define xx_Auto3564   "Activate Break Points"
#define en_Auto3565   "Dynamic Libraries"
#define fr_Auto3565   "BibliothŠques dynamiques"
#define it_Auto3565   "Dynamic Libraries"
#define es_Auto3565   "Dynamic Libraries"
#define de_Auto3565   "Dynamic Libraries"
#define nl_Auto3565   "Dynamic Libraries"
#define pt_Auto3565   "Dynamic Libraries"
#define xx_Auto3565   "Dynamic Libraries"
#define en_Auto3566   "Active Variable Watch Expressions"
#define fr_Auto3566   "Expressions de Surveillance de Variables"
#define it_Auto3566   "Active Variable Watch Expressions"
#define es_Auto3566   "Active Variable Watch Expressions"
#define de_Auto3566   "Active Variable Watch Expressions"
#define nl_Auto3566   "Active Variable Watch Expressions"
#define pt_Auto3566   "Active Variable Watch Expressions"
#define xx_Auto3566   "Active Variable Watch Expressions"
#define en_Auto3567   "Syntax and Variable Value Display"
#define fr_Auto3567   "Affichage de la syntaxe et de la valeur de la variable"
#define it_Auto3567   "Syntax and Variable Value Display"
#define es_Auto3567   "Syntax and Variable Value Display"
#define de_Auto3567   "Syntax and Variable Value Display"
#define nl_Auto3567   "Syntax and Variable Value Display"
#define pt_Auto3567   "Syntax and Variable Value Display"
#define xx_Auto3567   "Syntax and Variable Value Display"
#define en__Auto3567   ""
#define en_Auto3568   "Tcode Registers"
#define fr_Auto3568   "Registres"
#define it_Auto3568   "Tcode Registers"
#define es_Auto3568   "Tcode Registers"
#define de_Auto3568   "Tcode Registers"
#define nl_Auto3568   "Tcode Registers"
#define pt_Auto3568   "Tcode Registers"
#define xx_Auto3568   "Tcode Registers"
#define en_Auto3569   "Assigned Files"
#define fr_Auto3569   "Fichiers assign‚s"
#define it_Auto3569   "Assigned Files"
#define es_Auto3569   "Assigned Files"
#define de_Auto3569   "Assigned Files"
#define nl_Auto3569   "Assigned Files"
#define pt_Auto3569   "Assigned Files"
#define xx_Auto3569   "Assigned Files"
#define en_Auto3570   "Attached Programs"
#define fr_Auto3570   "Programs attach‚es"
#define it_Auto3570   "Attached Programs"
#define es_Auto3570   "Attached Programs"
#define de_Auto3570   "Attached Programs"
#define nl_Auto3570   "Attached Programs"
#define pt_Auto3570   "Attached Programs"
#define xx_Auto3570   "Attached Programs"
#define en_Auto3571   "Stack Inspection"
#define fr_Auto3571   "Inspection du Pile"
#define it_Auto3571   "Stack Inspection"
#define es_Auto3571   "Stack Inspection"
#define de_Auto3571   "Stack Inspection"
#define nl_Auto3571   "Stack Inspection"
#define pt_Auto3571   "Stack Inspection"
#define xx_Auto3571   "Stack Inspection"
#define en_Auto3572   "Source Files"
#define fr_Auto3572   "Fichiers sources"
#define it_Auto3572   "Source Files"
#define es_Auto3572   "Source Files"
#define de_Auto3572   "Source Files"
#define nl_Auto3572   "Source Files"
#define pt_Auto3572   "Source Files"
#define xx_Auto3572   "Source Files"
#define en_Auto3573   "Observation Variables"
#define fr_Auto3573   "Observation de Variables"
#define it_Auto3573   "Observation Variables"
#define es_Auto3573   "Observation Variables"
#define de_Auto3573   "Observation Variables"
#define nl_Auto3573   "Observation Variables"
#define pt_Auto3573   "Observation Variables"
#define xx_Auto3573   "Observation Variables"
#define en_Auto3574   "Add Segment Break"
#define fr_Auto3574   "Arret sur segment"
#define it_Auto3574   "Add Segment Break"
#define es_Auto3574   "Add Segment Break"
#define de_Auto3574   "Add Segment Break"
#define nl_Auto3574   "Add Segment Break"
#define pt_Auto3574   "Add Segment Break"
#define xx_Auto3574   "Add Segment Break"
#define en_Auto3575   "File Assign Watch"
#define fr_Auto3575   "Assign surveill‚"
#define it_Auto3575   "File Assign Watch"
#define es_Auto3575   "File Assign Watch"
#define de_Auto3575   "File Assign Watch"
#define nl_Auto3575   "File Assign Watch"
#define pt_Auto3575   "File Assign Watch"
#define xx_Auto3575   "File Assign Watch"
#define en__Auto3575   ""
#define fr__Auto3575   ""
#define it__Auto3575   ""
#define es__Auto3575   ""
#define de__Auto3575   ""
#define nl__Auto3575   ""
#define pt__Auto3575   ""
#define xx__Auto3575   ""
#define en_Auto3576   "Add Procedure Break"
#define fr_Auto3576   "Arrˆt sur proc‚dure"
#define it_Auto3576   "Add Procedure Break"
#define es_Auto3576   "Add Procedure Break"
#define de_Auto3576   "Add Procedure Break"
#define nl_Auto3576   "Add Procedure Break"
#define pt_Auto3576   "Add Procedure Break"
#define xx_Auto3576   "Add Procedure Break"
#define en_Auto3577   "Add Variable Watch"
#define fr_Auto3577   "Variable surveill‚e"
#define it_Auto3577   "Add Variable Watch"
#define es_Auto3577   "Add Variable Watch"
#define de_Auto3577   "Add Variable Watch"
#define nl_Auto3577   "Add Variable Watch"
#define pt_Auto3577   "Add Variable Watch"
#define xx_Auto3577   "Add Variable Watch"
#define en_Auto3578   "Global Variable"
#define fr_Auto3578   "Variable globale"
#define it_Auto3578   "Global Variable"
#define es_Auto3578   "Global Variable"
#define de_Auto3578   "Global Variable"
#define nl_Auto3578   "Global Variable"
#define pt_Auto3578   "Global Variable"
#define xx_Auto3578   "Global Variable"
#define en_Auto3579   "Local Variable"
#define fr_Auto3579   "Variable locale"
#define it_Auto3579   "Local Variable"
#define es_Auto3579   "Local Variable"
#define de_Auto3579   "Local Variable"
#define nl_Auto3579   "Local Variable"
#define pt_Auto3579   "Local Variable"
#define xx_Auto3579   "Local Variable"
#define it_ProcName   ""
#define es_ProcName   ""
#define de_ProcName   ""
#define nl_ProcName   ""
#define pt_ProcName   ""
#define xx_ProcName   ""
#define en_ProcEdit   ">"
#define fr_ProcEdit   ">"
#define it_ProcEdit   ">"
#define es_ProcEdit   ">"
#define de_ProcEdit   ">"
#define nl_ProcEdit   ">"
#define pt_ProcEdit   ">"
#define xx_ProcEdit   ">"
#define en__ProcEdit   ""
#define en_SegmentEdit   ">"
#define fr_SegmentEdit   ">"
#define it_SegmentEdit   ">"
#define es_SegmentEdit   ">"
#define de_SegmentEdit   ">"
#define nl_SegmentEdit   ">"
#define pt_SegmentEdit   ">"
#define xx_SegmentEdit   ">"
#define en_ProcInfo   "Names|Numbers|Offsets"
#define fr_ProcInfo   "a|b|c"
#define it_ProcInfo   "Names|Numbers|Offsets"
#define es_ProcInfo   "Names|Numbers|Offsets"
#define de_ProcInfo   "Names|Numbers|Offsets"
#define nl_ProcInfo   "Names|Numbers|Offsets"
#define pt_ProcInfo   "Names|Numbers|Offsets"
#define xx_ProcInfo   "Names|Numbers|Offsets"
#define en__AssignList   ""
#define en_DeleteObservation   "-"
#define fr_DeleteObservation   "-"
#define it_DeleteObservation   "-"
#define es_DeleteObservation   "-"
#define de_DeleteObservation   "-"
#define nl_DeleteObservation   "-"
#define pt_DeleteObservation   "-"
#define xx_DeleteObservation   "-"
#define en_RemoveBreak   "-"
#define en_ExportAssign   ">"
#define en__ExportAssign   ""
#define en_DeleteWatch   "-"
#define fr_DeleteWatch   "-"
#define it_DeleteWatch   "-"
#define es_DeleteWatch   "-"
#define de_DeleteWatch   "-"
#define nl_DeleteWatch   "-"
#define pt_DeleteWatch   "-"
#define xx_DeleteWatch   "-"
#define en_InspectSource   ">"
#define fr_InspectSource   ">"
#define it_InspectSource   ">"
#define es_InspectSource   ">"
#define de_InspectSource   ">"
#define nl_InspectSource   ">"
#define pt_InspectSource   ">"
#define xx_InspectSource   ">"
#define en_Auto3580   "Editor Syntaxical Colours"
#define fr_Auto3580   "Coloration syntaxique de l'‚diteur AED"
#define it_Auto3580   "Editor Syntaxical Colours"
#define es_Auto3580   "Editor Syntaxical Colours"
#define de_Auto3580   "Editor Syntaxical Colours"
#define nl_Auto3580   "Editor Syntaxical Colours"
#define pt_Auto3580   "Editor Syntaxical Colours"
#define xx_Auto3580   "Editor Syntaxical Colours"
#define en_auto6060   "AED.NORMAL"
#define fr_auto6060   "Texte normal"
#define it_auto6060   "AED.NORMAL"
#define es_auto6060   "AED.NORMAL"
#define de_auto6060   "AED.NORMAL"
#define nl_auto6060   "AED.NORMAL"
#define pt_auto6060   "AED.NORMAL"
#define xx_auto6060   "AED.NORMAL"
#define en_Auto3581   "ErrAdr="
#define fr_Auto3581   "ErrAdr="
#define it_Auto3581   "ErrAdr="
#define es_Auto3581   "ErrAdr="
#define de_Auto3581   "ErrAdr="
#define nl_Auto3581   "ErrAdr="
#define pt_Auto3581   "ErrAdr="
#define xx_Auto3581   "ErrAdr="
#define en__Auto3581   ""
#define fr__Auto3581   ""
#define it__Auto3581   ""
#define es__Auto3581   ""
#define de__Auto3581   ""
#define nl__Auto3581   ""
#define pt__Auto3581   ""
#define xx__Auto3581   ""
#define en_Auto3582   "AskMask="
#define fr_Auto3582   "AskMask="
#define it_Auto3582   "AskMask="
#define es_Auto3582   "AskMask="
#define de_Auto3582   "AskMask="
#define nl_Auto3582   "AskMask="
#define pt_Auto3582   "AskMask="
#define xx_Auto3582   "AskMask="
#define en__Auto3582   ""
#define fr__Auto3582   ""
#define it__Auto3582   ""
#define es__Auto3582   ""
#define de__Auto3582   ""
#define nl__Auto3582   ""
#define pt__Auto3582   ""
#define xx__Auto3582   ""
#define en_Auto3583   "MouseMask="
#define fr_Auto3583   "MouseMask="
#define it_Auto3583   "MouseMask="
#define es_Auto3583   "MouseMask="
#define de_Auto3583   "MouseMask="
#define nl_Auto3583   "MouseMask="
#define pt_Auto3583   "MouseMask="
#define xx_Auto3583   "MouseMask="
#define en__Auto3583   ""
#define fr__Auto3583   ""
#define it__Auto3583   ""
#define es__Auto3583   ""
#define de__Auto3583   ""
#define nl__Auto3583   ""
#define pt__Auto3583   ""
#define xx__Auto3583   ""
#define en_Auto3584   "Error Value="
#define fr_Auto3584   "MouseMask="
#define it_Auto3584   "MouseMask="
#define es_Auto3584   "MouseMask="
#define de_Auto3584   "MouseMask="
#define nl_Auto3584   "MouseMask="
#define pt_Auto3584   "MouseMask="
#define xx_Auto3584   "MouseMask="
#define en__Auto3584   ""
#define fr__Auto3584   ""
#define it__Auto3584   ""
#define es__Auto3584   ""
#define de__Auto3584   ""
#define nl__Auto3584   ""
#define pt__Auto3584   ""
#define xx__Auto3584   ""
#define en_Auto3585   "ErrorAdr="
#define fr_Auto3585   "MouseMask="
#define it_Auto3585   "MouseMask="
#define es_Auto3585   "MouseMask="
#define de_Auto3585   "MouseMask="
#define nl_Auto3585   "MouseMask="
#define pt_Auto3585   "MouseMask="
#define xx_Auto3585   "MouseMask="
#define en__Auto3585   ""
#define fr__Auto3585   ""
#define it__Auto3585   ""
#define es__Auto3585   ""
#define de__Auto3585   ""
#define nl__Auto3585   ""
#define pt__Auto3585   ""
#define xx__Auto3585   ""
#define en_auto6061   "AED.STRING"
#define fr_auto6061   "ChaŒnes"
#define it_auto6061   "AED.STRING"
#define es_auto6061   "AED.STRING"
#define de_auto6061   "AED.STRING"
#define nl_auto6061   "AED.STRING"
#define pt_auto6061   "AED.STRING"
#define xx_auto6061   "AED.STRING"
#define en__auto6061   ""
#define en_auto6062   "AED.KEYWORD"
#define fr_auto6062   "Mots cl‚s"
#define it_auto6062   "AED.KEYWORD"
#define es_auto6062   "AED.KEYWORD"
#define de_auto6062   "AED.KEYWORD"
#define nl_auto6062   "AED.KEYWORD"
#define pt_auto6062   "AED.KEYWORD"
#define xx_auto6062   "AED.KEYWORD"
#define en__auto6062   ""
#define en_auto6063   "AED.COMMENT"
#define fr_auto6063   "Commentaires"
#define it_auto6063   "AED.COMMENT"
#define es_auto6063   "AED.COMMENT"
#define de_auto6063   "AED.COMMENT"
#define nl_auto6063   "AED.COMMENT"
#define pt_auto6063   "AED.COMMENT"
#define xx_auto6063   "AED.COMMENT"
#define en__auto6063   ""
#define en_auto6064   "AED.PUNCTUATE"
#define fr_auto6064   "Ponctuation"
#define it_auto6064   "AED.PUNCTUATE"
#define es_auto6064   "AED.PUNCTUATE"
#define de_auto6064   "AED.PUNCTUATE"
#define nl_auto6064   "AED.PUNCTUATE"
#define pt_auto6064   "AED.PUNCTUATE"
#define xx_auto6064   "AED.PUNCTUATE"
#define en__auto6064   ""
#define en_Auto3586   "AED.FONT"
#define fr_Auto3586   "Ponctuation"
#define it_Auto3586   "AED.PUNCTUATE"
#define es_Auto3586   "AED.PUNCTUATE"
#define de_Auto3586   "AED.PUNCTUATE"
#define nl_Auto3586   "AED.PUNCTUATE"
#define pt_Auto3586   "AED.PUNCTUATE"
#define xx_Auto3586   "AED.PUNCTUATE"
#define en__Auto3586   ""
#define en__AED_KEYWORD   ""
#define en__AED_COMMENT   ""
#define en__AED_PUNCTUATE   ""
#define en__AED_FONT   ""
#define en_EditorColour   "&Editor Colour/Font"
#define fr_EditorColour   "Couleurs &Editeur"
#define it_EditorColour   "&Editor Colours"
#define es_EditorColour   "&Editor Colours"
#define de_EditorColour   "&Editor Colours"
#define nl_EditorColour   "&Editor Colours"
#define pt_EditorColour   "&Editor Colours"
#define xx_EditorColour   "&Editor Colours"
#define en__EditorColour   ""
#define fr__EditorColour   ""
#define it__EditorColour   ""
#define es__EditorColour   ""
#define de__EditorColour   ""
#define nl__EditorColour   ""
#define pt__EditorColour   ""
#define xx__EditorColour   ""
#define en_SetBreakAP   "Multiple"
#define fr_SetBreakAP   "Multiple"
#define it_SetBreakAP   "Multiple"
#define es_SetBreakAP   "Multiple"
#define de_SetBreakAP   "Multiple"
#define nl_SetBreakAP   "Multiple"
#define pt_SetBreakAP   "Multiple"
#define xx_SetBreakAP   "Multiple"
#define en_SetBreakBP   "One Shot"
#define fr_SetBreakBP   "Unique"
#define it_SetBreakBP   "One Shot"
#define es_SetBreakBP   "One Shot"
#define de_SetBreakBP   "One Shot"
#define nl_SetBreakBP   "One Shot"
#define pt_SetBreakBP   "One Shot"
#define xx_SetBreakBP   "One Shot"
#define en_SetBreakAS   "Multiple"
#define fr_SetBreakAS   "Multiple"
#define it_SetBreakAS   "Multiple"
#define es_SetBreakAS   "Multiple"
#define de_SetBreakAS   "Multiple"
#define nl_SetBreakAS   "Multiple"
#define pt_SetBreakAS   "Multiple"
#define xx_SetBreakAS   "Multiple"
#define en_SetFileWatch   "Add"
#define fr_SetFileWatch   "Ajout"
#define it_SetFileWatch   "Add"
#define es_SetFileWatch   "Add"
#define de_SetFileWatch   "Add"
#define nl_SetFileWatch   "Add"
#define pt_SetFileWatch   "Add"
#define xx_SetFileWatch   "Add"
#define en__SetFileWatch   ""
#define fr__SetFileWatch   ""
#define it__SetFileWatch   ""
#define es__SetFileWatch   ""
#define de__SetFileWatch   ""
#define nl__SetFileWatch   ""
#define pt__SetFileWatch   ""
#define xx__SetFileWatch   ""
#define en_AllFileWatch   "*"
#define fr_AllFileWatch   "*"
#define it_AllFileWatch   "*"
#define es_AllFileWatch   "*"
#define de_AllFileWatch   "*"
#define nl_AllFileWatch   "*"
#define pt_AllFileWatch   "*"
#define xx_AllFileWatch   "*"
#define en__AllFileWatch   ""
#define fr__AllFileWatch   ""
#define it__AllFileWatch   ""
#define es__AllFileWatch   ""
#define de__AllFileWatch   ""
#define nl__AllFileWatch   ""
#define pt__AllFileWatch   ""
#define xx__AllFileWatch   ""
#define en_RazFileWatch   "Delete"
#define fr_RazFileWatch   "Raz"
#define it_RazFileWatch   "Delete"
#define es_RazFileWatch   "Delete"
#define de_RazFileWatch   "Delete"
#define nl_RazFileWatch   "Delete"
#define pt_RazFileWatch   "Delete"
#define xx_RazFileWatch   "Delete"
#define en__RazFileWatch   ""
#define fr__RazFileWatch   ""
#define it__RazFileWatch   ""
#define es__RazFileWatch   ""
#define de__RazFileWatch   ""
#define nl__RazFileWatch   ""
#define pt__RazFileWatch   ""
#define xx__RazFileWatch   ""
#define en_SetBreakBS   "One Shot"
#define fr_SetBreakBS   "Unique"
#define it_SetBreakBS   "One Shot"
#define es_SetBreakBS   "One Shot"
#define de_SetBreakBS   "One Shot"
#define nl_SetBreakBS   "One Shot"
#define pt_SetBreakBS   "One Shot"
#define xx_SetBreakBS   "One Shot"
#define en_MultipleWatch   "Multiple"
#define fr_MultipleWatch   "Multiple"
#define it_MultipleWatch   "Multiple"
#define es_MultipleWatch   "Multiple"
#define de_MultipleWatch   "Multiple"
#define nl_MultipleWatch   "Multiple"
#define pt_MultipleWatch   "Multiple"
#define xx_MultipleWatch   "Multiple"
#define en_SingleWatch   "One Shot"
#define fr_SingleWatch   "Unique"
#define it_SingleWatch   "One Shot"
#define es_SingleWatch   "One Shot"
#define de_SingleWatch   "One Shot"
#define nl_SingleWatch   "One Shot"
#define pt_SingleWatch   "One Shot"
#define xx_SingleWatch   "One Shot"
#define en_ObserveGlobal   "Observe"
#define fr_ObserveGlobal   "Observer"
#define it_ObserveGlobal   "Observe"
#define es_ObserveGlobal   "Observe"
#define de_ObserveGlobal   "Observe"
#define nl_ObserveGlobal   "Observe"
#define pt_ObserveGlobal   "Observe"
#define xx_ObserveGlobal   "Observe"
#define en_InspectGlobal   "Inspect"
#define fr_InspectGlobal   "Inspecter"
#define it_InspectGlobal   "Inspect"
#define es_InspectGlobal   "Inspect"
#define de_InspectGlobal   "Inspect"
#define nl_InspectGlobal   "Inspect"
#define pt_InspectGlobal   "Inspect"
#define xx_InspectGlobal   "Inspect"
#define en_ObserveLocal   "Observe"
#define fr_ObserveLocal   "Observer"
#define it_ObserveLocal   "Observe"
#define es_ObserveLocal   "Observe"
#define de_ObserveLocal   "Observe"
#define nl_ObserveLocal   "Observe"
#define pt_ObserveLocal   "Observe"
#define xx_ObserveLocal   "Observe"
#define en_InspectLocal   "Inspect"
#define fr_InspectLocal   "Inspecter"
#define it_InspectLocal   "Inspect"
#define es_InspectLocal   "Inspect"
#define de_InspectLocal   "Inspect"
#define nl_InspectLocal   "Inspect"
#define pt_InspectLocal   "Inspect"
#define xx_InspectLocal   "Inspect"
#define en_VariableControl   "&Variables"
#define fr_VariableControl   "&Variables"
#define it_VariableControl   "&Variables"
#define es_VariableControl   "&Variables"
#define de_VariableControl   "&Variables"
#define nl_VariableControl   "&Variables"
#define pt_VariableControl   "&Variables"
#define xx_VariableControl   "&Variables"
#define en__VariableControl   ""
#define fr__VariableControl   ""
#define it__VariableControl   ""
#define es__VariableControl   ""
#define de__VariableControl   ""
#define nl__VariableControl   ""
#define pt__VariableControl   ""
#define xx__VariableControl   ""
#define en__Auto3587   ""
#define fr__Auto3587   ""
#define it__Auto3587   ""
#define es__Auto3587   ""
#define de__Auto3587   ""
#define nl__Auto3587   ""
#define pt__Auto3587   ""
#define xx__Auto3587   ""
#define en_vListe   "ID|Variable|Offset|Value"
#define fr_vListe   "ID|Variable|Offset|Valeur"
#define it_vListe   "ID|Variable|Offset|Value"
#define es_vListe   "ID|Variable|Offset|Value"
#define de_vListe   "ID|Variable|Offset|Value"
#define nl_vListe   "ID|Variable|Offset|Value"
#define pt_vListe   "ID|Variable|Offset|Value"
#define xx_vListe   "ID|Variable|Offset|Value"
#define en__vListe   ""
#define en_vBar   ""
#define en__vBar   ""
#define en_Auto3588   ""
#define fr_Auto3588   ""
#define en__Auto3588   ""
#define en_StatusBar   ""
#define fr_StatusBar   ""
#define en__StatusBar   ""
#include "vexadb.h"
static int	vfh[16];
private int on_StatusBar_create(struct visual_debug_context * _Context);
private int on_Dbio_show(struct visual_debug_context * _Context);
private int on_Prio_show(struct visual_debug_context * _Context);
private int on_ErrAdr_show(struct visual_debug_context * _Context);
private int on_AskMask_show(struct visual_debug_context * _Context);
private int on_MouseMask_show(struct visual_debug_context * _Context);
private int on_ErrorAdr_show(struct visual_debug_context * _Context);
private int on_ErrorVal_show(struct visual_debug_context * _Context);
private int on_vListe_show(struct visual_debug_context * _Context);
private int on_vBar_show(struct visual_debug_context * _Context);
private int on_ProgramSource_getfocus(struct visual_debug_context * _Context);
private int on_Dbio_getfocus(struct visual_debug_context * _Context);
private int on_ProgramSource_losefocus(struct visual_debug_context * _Context);
private int on_ProgramOutput_losefocus(struct visual_debug_context * _Context);
private int on_StatusBar_losefocus(struct visual_debug_context * _Context);
private int on_BreakManager_event(struct visual_debug_context * _Context);
private int on_StepInto_event(struct visual_debug_context * _Context);
private int on_Goto_event(struct visual_debug_context * _Context);
private int on_Run_event(struct visual_debug_context * _Context);
private int on_Restart_event(struct visual_debug_context * _Context);
private int on_Break_event(struct visual_debug_context * _Context);
private int on_ClearBreak_event(struct visual_debug_context * _Context);
private int on_View_event(struct visual_debug_context * _Context);
private int on_Help_event(struct visual_debug_context * _Context);
private int on_Save_event(struct visual_debug_context * _Context);
private int on_Exit_event(struct visual_debug_context * _Context);
private int on_BreakKey_event(struct visual_debug_context * _Context);
private int on_AsmList_event(struct visual_debug_context * _Context);
private int on_SaveConfig_event(struct visual_debug_context * _Context);
private int on_HexaView_event(struct visual_debug_context * _Context);
private int on_Dbio_event(struct visual_debug_context * _Context);
private int on_VSB_event(struct visual_debug_context * _Context);
private int on_HSB_event(struct visual_debug_context * _Context);
private int on_ProcEdit_event(struct visual_debug_context * _Context);
private int on_SegmentEdit_event(struct visual_debug_context * _Context);
private int on_RemoveBreak_event(struct visual_debug_context * _Context);
private int on_ExportAssign_event(struct visual_debug_context * _Context);
private int on_DeleteWatch_event(struct visual_debug_context * _Context);
private int on_InspectSource_event(struct visual_debug_context * _Context);
private int on_Syntax_event(struct visual_debug_context * _Context);
private int on_EditorColour_event(struct visual_debug_context * _Context);
private int on_SetBreakAP_event(struct visual_debug_context * _Context);
private int on_SetBreakBP_event(struct visual_debug_context * _Context);
private int on_SetBreakAS_event(struct visual_debug_context * _Context);
private int on_SetFileWatch_event(struct visual_debug_context * _Context);
private int on_AllFileWatch_event(struct visual_debug_context * _Context);
private int on_RazFileWatch_event(struct visual_debug_context * _Context);
private int on_SetBreakBS_event(struct visual_debug_context * _Context);
private int on_MultipleWatch_event(struct visual_debug_context * _Context);
private int on_SingleWatch_event(struct visual_debug_context * _Context);
private int on_InspectGlobal_event(struct visual_debug_context * _Context);
private int on_InspectLocal_event(struct visual_debug_context * _Context);
private int on_vListe_event(struct visual_debug_context * _Context);
private int on_vBar_event(struct visual_debug_context * _Context);
private int on_StatusBar_event(struct visual_debug_context * _Context);
static void	visual_debug_onhint(struct visual_debug_context * _Context,char * mptr);
private int  sort_item_vListe(struct visual_debug_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_vListe(struct visual_debug_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_vListe(struct visual_debug_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_vListe */
private int compare_vListe(struct visual_debug_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_vListe */

static int stdinput(struct visual_debug_context * _Context)
{
	int tempfocus=0;
	while(1) {
		switch ((_Context->keycode=visual_getch())) {
			case 256 :
				if ( visual_event(1) == _MIMO_MOVE ) {
					if ((tempfocus = visual_debug_event(_Context)) == -1) continue;
					if (tempfocus == _Context->focus_item ) continue;
					}
			default  :
				return(_Context->keycode);
			}
		}
	return(-1);
}


/*	----------------------------------------	*/
/*	v i s u a l _ d e b u g _ o n h i n t ()	*/
/*	----------------------------------------	*/
static void	visual_debug_onhint(struct visual_debug_context * _Context,char * mptr){
	if(mptr){
	strcpy(_Context->buffer_StatusBar,mptr);
	visual_frame(22,662,954+2,16+2,5);
visual_text(22+1,662+1,954,16,vfh[1],16,0,_Context->buffer_StatusBar,119,0);
;
	}

}
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_vListe(struct visual_debug_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_vListe[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_vListe(struct visual_debug_context * _Context,int nelts)
{
if (_Context->nelt_vListe<nelts) {
	liberate(_Context->tabsort_vListe);
	if ((_Context->tabsort_vListe=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_vListe=0;_Context->nelt_vListe<nelts;_Context->nelt_vListe++)
		{ _Context->tabsort_vListe[_Context->nelt_vListe]=_Context->nelt_vListe+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_vListe=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_vListe=allocate(nelts*114)) != NULL)
	memset(_Context->libsort_vListe,' ',nelts*114);
}

/* --------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_vListe */
/* --------------------------------------------------------- */
private void sort_vListe(struct visual_debug_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_vListe,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_vListe[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_vListe[j]) && (compare_vListe(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_vListe[i]=k+1;
	_Context->indsort_vListe[k]=1;
	};	/* for i */
liberate(_Context->libsort_vListe);
liberate(_Context->indsort_vListe);
}

/* ------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_vListe */
/* ------------------------------------------------------- */
private int compare_vListe(struct visual_debug_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_vListe[114*a],&_Context->libsort_vListe[114*b],9);	/* comparaison zone 1 */
switch (_Context->formsort_vListe) {
	case 1:	/* ID ordre normal */
		return(i);

	case -1:	/* ID ordre inverse */
		return(-i);

	case 2:	/* Variable ordre normal */
		j=memicmp(&_Context->libsort_vListe[114*a+9],&_Context->libsort_vListe[114*b+9],33);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Variable ordre inverse */
		j=memicmp(&_Context->libsort_vListe[114*b+9],&_Context->libsort_vListe[114*a+9],33);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Offset ordre normal */
		j=memicmp(&_Context->libsort_vListe[114*a+42],&_Context->libsort_vListe[114*b+42],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Offset ordre inverse */
		j=memicmp(&_Context->libsort_vListe[114*b+42],&_Context->libsort_vListe[114*a+42],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* Value ordre normal */
		j=memicmp(&_Context->libsort_vListe[114*a+51],&_Context->libsort_vListe[114*b+51],63);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* Value ordre inverse */
		j=memicmp(&_Context->libsort_vListe[114*b+51],&_Context->libsort_vListe[114*a+51],63);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

private int on_StatusBar_create(struct visual_debug_context * _Context) {
	WindowEditorInformation(_Context->buffer_StatusBar,119);
	return(-1);
}

public	int	visual_debug_attach()
{
	if ( visual_initialise(4|512) == -1 )
		return(56);

	else	{
		visual_palette("grisstd.rgb",11);
		cicopalette(0,0);
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
		initialise_mouse();
		}
	return(0);
}

public	int	visual_debug_attach_mode(int mode)
{
	if ( visual_initialise(4|mode) == -1 )
		return(56);

	else	{
		visual_palette("grisstd.rgb",11);
		cicopalette(0,0);
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
		initialise_mouse();
		}
	return(0);
}

public	int	visual_debug_detach()
{

	if ( visual_liberate() == -1 )
		return(56);

	return(0);
}

public	int	visual_debug_create(
	struct visual_debug_context ** cptr,
	char * pBreakKey,
	char * pAsmList,
	char * pSaveConfig,
	char * pHexaView,
	char * pDbio,
	char * pPrio,
	char * pProcName,
	char * pProcInfo,
	char * pSegmName,
	char * pGlobNames,
	char * pLocalNames,
	char * pAssignList,
	char * pRegisterList,
	char * pAttachList,
	char * pStackList,
	char * pLibraryList,
	char * pObserveList,
	char * pBreakList,
	char * pWatchList,
	char * pSourceList,
	char * pSyntax,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAED_FONT,
	char * pStatusBar)
{

	int i;
	struct visual_debug_context * _Context=(struct visual_debug_context*)0;
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
	if (!(_Context = allocate( sizeof( struct visual_debug_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=75;
	_Context->page_number=1;
		_Context->max_VSB=0;
		_Context->limit_VSB=0;
		_Context->value_VSB=0;
		_Context->max_HSB=0;
		_Context->limit_HSB=0;
		_Context->value_HSB=0;
		for (i=0; i < 11; i++)  *(_Context->buffer_ErrAdr+i)=' ';
		for (i=0; i < 11; i++)  *(_Context->buffer_AskMask+i)=' ';
		for (i=0; i < 11; i++)  *(_Context->buffer_MouseMask+i)=' ';
		for (i=0; i < 11; i++)  *(_Context->buffer_ErrorAdr+i)=' ';
		for (i=0; i < 8; i++)  *(_Context->buffer_ErrorVal+i)=' ';
	_Context->formsort_vListe=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_vListe=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_vListe=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_vListe=0;_Context->nelt_vListe<512;_Context->nelt_vListe++)
			{ _Context->tabsort_vListe[_Context->nelt_vListe]=_Context->nelt_vListe+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_vListe=0; /* si problème d'allocation */
_Context->indsort_vListe=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_vBar=0;
		_Context->limit_vBar=0;
		_Context->value_vBar=0;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWSSWWWWWWWWWWWWWWSWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin((void *) 0, 0, pBreakKey);
		if (!( pBreakKey )) _Context->value_BreakKey=0;
		else	_Context->value_BreakKey = *((int *)pBreakKey);
		visual_transferin((void *) 0, 0, pAsmList);
		if (!( pAsmList )) _Context->value_AsmList=0;
		else	_Context->value_AsmList = *((int *)pAsmList);
		visual_transferin((void *) 0, 0, pSaveConfig);
		if (!( pSaveConfig )) _Context->value_SaveConfig=0;
		else	_Context->value_SaveConfig = *((int *)pSaveConfig);
		visual_transferin((void *) 0, 0, pHexaView);
		if (!( pHexaView )) _Context->value_HexaView=0;
		else	_Context->value_HexaView = *((int *)pHexaView);
		visual_transferin(_Context->buffer_Dbio, 4032, pDbio);
		visual_transferin(_Context->buffer_Prio, 4025, pPrio);
		visual_transferin((void *) 0, 0, pProcName);
		if (!( pProcName )) _Context->value_ProcName=0;
		else	_Context->value_ProcName = *((int *)pProcName);
		visual_transferin((void *) 0, 0, pProcInfo);
		if (!( pProcInfo )) _Context->value_ProcInfo=0;
		else	_Context->value_ProcInfo = *((int *)pProcInfo);
		visual_transferin((void *) 0, 0, pSegmName);
		if (!( pSegmName )) _Context->value_SegmName=0;
		else	_Context->value_SegmName = *((int *)pSegmName);
		visual_transferin((void *) 0, 0, pGlobNames);
		if (!( pGlobNames )) _Context->value_GlobNames=0;
		else	_Context->value_GlobNames = *((int *)pGlobNames);
		visual_transferin((void *) 0, 0, pLocalNames);
		if (!( pLocalNames )) _Context->value_LocalNames=0;
		else	_Context->value_LocalNames = *((int *)pLocalNames);
		visual_transferin((void *) 0, 0, pAssignList);
		if (!( pAssignList )) _Context->value_AssignList=0;
		else	_Context->value_AssignList = *((int *)pAssignList);
		visual_transferin((void *) 0, 0, pRegisterList);
		if (!( pRegisterList )) _Context->value_RegisterList=0;
		else	_Context->value_RegisterList = *((int *)pRegisterList);
		visual_transferin((void *) 0, 0, pAttachList);
		if (!( pAttachList )) _Context->value_AttachList=0;
		else	_Context->value_AttachList = *((int *)pAttachList);
		visual_transferin((void *) 0, 0, pStackList);
		if (!( pStackList )) _Context->value_StackList=0;
		else	_Context->value_StackList = *((int *)pStackList);
		visual_transferin((void *) 0, 0, pLibraryList);
		if (!( pLibraryList )) _Context->value_LibraryList=0;
		else	_Context->value_LibraryList = *((int *)pLibraryList);
		visual_transferin((void *) 0, 0, pObserveList);
		if (!( pObserveList )) _Context->value_ObserveList=0;
		else	_Context->value_ObserveList = *((int *)pObserveList);
		visual_transferin((void *) 0, 0, pBreakList);
		if (!( pBreakList )) _Context->value_BreakList=0;
		else	_Context->value_BreakList = *((int *)pBreakList);
		visual_transferin((void *) 0, 0, pWatchList);
		if (!( pWatchList )) _Context->value_WatchList=0;
		else	_Context->value_WatchList = *((int *)pWatchList);
		visual_transferin((void *) 0, 0, pSourceList);
		if (!( pSourceList )) _Context->value_SourceList=0;
		else	_Context->value_SourceList = *((int *)pSourceList);
		visual_transferin(_Context->buffer_Syntax, 226, pSyntax);
		visual_transferin((void *) 0, 0, pAED_NORMAL);
		if (!( pAED_NORMAL )) _Context->value_AED_NORMAL=0;
		else	_Context->value_AED_NORMAL = *((int *)pAED_NORMAL);
		visual_transferin((void *) 0, 0, pAED_QUOTE);
		if (!( pAED_QUOTE )) _Context->value_AED_QUOTE=0;
		else	_Context->value_AED_QUOTE = *((int *)pAED_QUOTE);
		visual_transferin((void *) 0, 0, pAED_KEYWORD);
		if (!( pAED_KEYWORD )) _Context->value_AED_KEYWORD=0;
		else	_Context->value_AED_KEYWORD = *((int *)pAED_KEYWORD);
		visual_transferin((void *) 0, 0, pAED_COMMENT);
		if (!( pAED_COMMENT )) _Context->value_AED_COMMENT=0;
		else	_Context->value_AED_COMMENT = *((int *)pAED_COMMENT);
		visual_transferin((void *) 0, 0, pAED_PUNCTUATE);
		if (!( pAED_PUNCTUATE )) _Context->value_AED_PUNCTUATE=0;
		else	_Context->value_AED_PUNCTUATE = *((int *)pAED_PUNCTUATE);
		visual_transferin((void *) 0, 0, pAED_FONT);
		if (!( pAED_FONT )) _Context->value_AED_FONT=0;
		else	_Context->value_AED_FONT = *((int *)pAED_FONT);
		visual_transferin(_Context->buffer_StatusBar, 119, pStatusBar);
		}
	for (i=0; i < 8; i++)_Context->msg_Main[i]=" ";
	_Context->msg_Main[0]=en_Main;
	_Context->msg_Main[1]=fr_Main;
	_Context->msg_Main[2]=it_Main;
	_Context->msg_Main[3]=es_Main;
	_Context->msg_Main[4]=de_Main;
	_Context->msg_Main[5]=nl_Main;
	_Context->msg_Main[6]=pt_Main;
	_Context->msg_Main[7]=xx_Main;
	_Context->hint_Main[0]=en__Main;
	_Context->x_Main=0;
	_Context->y_Main=0;
	_Context->w_Main=1014;
	_Context->h_Main=696;
	_Context->window_col=0;
	_Context->window_row=0;
	/*set_mimo_mask(0xF33F);*/
	for (i=0; i < 8; i++)_Context->msg_ProgramSource[i]=" ";
	_Context->msg_ProgramSource[0]=en_ProgramSource;
	_Context->msg_ProgramSource[1]=fr_ProgramSource;
	_Context->msg_ProgramSource[2]=it_ProgramSource;
	_Context->msg_ProgramSource[3]=es_ProgramSource;
	_Context->msg_ProgramSource[4]=de_ProgramSource;
	_Context->msg_ProgramSource[5]=nl_ProgramSource;
	_Context->msg_ProgramSource[6]=pt_ProgramSource;
	_Context->msg_ProgramSource[7]=xx_ProgramSource;
	_Context->hint_ProgramSource[0]=en__ProgramSource;
	_Context->hint_ProgramSource[1]=fr__ProgramSource;
	_Context->hint_ProgramSource[2]=it__ProgramSource;
	_Context->hint_ProgramSource[3]=es__ProgramSource;
	_Context->hint_ProgramSource[4]=de__ProgramSource;
	_Context->hint_ProgramSource[5]=nl__ProgramSource;
	_Context->hint_ProgramSource[6]=pt__ProgramSource;
	_Context->hint_ProgramSource[7]=xx__ProgramSource;
	_Context->focus_pages[1]=2;
	WindowEditorOnCreate(64+1,68+1,900-2,576-2,vfh[1]);
	for (i=0; i < 8; i++)_Context->msg_Auto3552[i]=" ";
	_Context->hint_Auto3552[0]=en__Auto3552;
	_Context->hint_Auto3552[1]=fr__Auto3552;
	_Context->hint_Auto3552[2]=it__Auto3552;
	_Context->hint_Auto3552[3]=es__Auto3552;
	_Context->hint_Auto3552[4]=de__Auto3552;
	_Context->hint_Auto3552[5]=nl__Auto3552;
	_Context->hint_Auto3552[6]=pt__Auto3552;
	_Context->hint_Auto3552[7]=xx__Auto3552;
	_Context->hint_Auto3553[0]=en__Auto3553;
	for (i=0; i < 8; i++)_Context->msg_Auto3554[i]=" ";
	_Context->hint_Auto3554[0]=en__Auto3554;
	_Context->hint_Auto3554[1]=fr__Auto3554;
	_Context->hint_Auto3554[2]=it__Auto3554;
	_Context->hint_Auto3554[3]=es__Auto3554;
	_Context->hint_Auto3554[4]=de__Auto3554;
	_Context->hint_Auto3554[5]=nl__Auto3554;
	_Context->hint_Auto3554[6]=pt__Auto3554;
	_Context->hint_Auto3554[7]=xx__Auto3554;
	_Context->hint_Auto3555[0]=en__Auto3555;
	for (i=0; i < 8; i++)_Context->msg_BreakManager[i]=" ";
	_Context->hint_BreakManager[0]=en__BreakManager;
	_Context->hint_BreakManager[1]=fr__BreakManager;
	_Context->hint_BreakManager[2]=it__BreakManager;
	_Context->hint_BreakManager[3]=es__BreakManager;
	_Context->hint_BreakManager[4]=de__BreakManager;
	_Context->hint_BreakManager[5]=nl__BreakManager;
	_Context->hint_BreakManager[6]=pt__BreakManager;
	_Context->hint_BreakManager[7]=xx__BreakManager;
	_Context->hint_BreakFrame[0]=en__BreakFrame;
	for (i=0; i < 8; i++)_Context->msg_BreakPoint[i]=" ";
	_Context->hint_BreakPoint[0]=en__BreakPoint;
	_Context->hint_BreakPoint[1]=fr__BreakPoint;
	_Context->hint_BreakPoint[2]=it__BreakPoint;
	_Context->hint_BreakPoint[3]=es__BreakPoint;
	_Context->hint_BreakPoint[4]=de__BreakPoint;
	_Context->hint_BreakPoint[5]=nl__BreakPoint;
	_Context->hint_BreakPoint[6]=pt__BreakPoint;
	_Context->hint_BreakPoint[7]=xx__BreakPoint;
	_Context->x_BreakPoint=40;
	_Context->y_BreakPoint=70;
	_Context->w_BreakPoint=16;
	_Context->h_BreakPoint=16;
	_Context->fg_BreakPoint=16;
	_Context->bg_BreakPoint=16;
	_Context->fid_BreakPoint=1;
	for (i=0; i < 8; i++)_Context->msg_StepInto[i]=" ";
	_Context->hint_StepInto[0]=en__StepInto;
	_Context->hint_StepInto[1]=fr__StepInto;
	_Context->hint_StepInto[2]=it__StepInto;
	_Context->hint_StepInto[3]=es__StepInto;
	_Context->hint_StepInto[4]=de__StepInto;
	_Context->hint_StepInto[5]=nl__StepInto;
	_Context->hint_StepInto[6]=pt__StepInto;
	_Context->hint_StepInto[7]=xx__StepInto;
	for (i=0; i < 8; i++)_Context->msg_Goto[i]=" ";
	_Context->hint_Goto[0]=en__Goto;
	_Context->hint_Goto[1]=fr__Goto;
	_Context->hint_Goto[2]=it__Goto;
	_Context->hint_Goto[3]=es__Goto;
	_Context->hint_Goto[4]=de__Goto;
	_Context->hint_Goto[5]=nl__Goto;
	_Context->hint_Goto[6]=pt__Goto;
	_Context->hint_Goto[7]=xx__Goto;
	for (i=0; i < 8; i++)_Context->msg_Run[i]=" ";
	_Context->hint_Run[0]=en__Run;
	_Context->hint_Run[1]=fr__Run;
	_Context->hint_Run[2]=it__Run;
	_Context->hint_Run[3]=es__Run;
	_Context->hint_Run[4]=de__Run;
	_Context->hint_Run[5]=nl__Run;
	_Context->hint_Run[6]=pt__Run;
	_Context->hint_Run[7]=xx__Run;
	for (i=0; i < 8; i++)_Context->msg_Restart[i]=" ";
	_Context->hint_Restart[0]=en__Restart;
	_Context->hint_Restart[1]=fr__Restart;
	_Context->hint_Restart[2]=it__Restart;
	_Context->hint_Restart[3]=es__Restart;
	_Context->hint_Restart[4]=de__Restart;
	_Context->hint_Restart[5]=nl__Restart;
	_Context->hint_Restart[6]=pt__Restart;
	_Context->hint_Restart[7]=xx__Restart;
	for (i=0; i < 8; i++)_Context->msg_Break[i]=" ";
	_Context->hint_Break[0]=en__Break;
	_Context->hint_Break[1]=fr__Break;
	_Context->hint_Break[2]=it__Break;
	_Context->hint_Break[3]=es__Break;
	_Context->hint_Break[4]=de__Break;
	_Context->hint_Break[5]=nl__Break;
	_Context->hint_Break[6]=pt__Break;
	_Context->hint_Break[7]=xx__Break;
	for (i=0; i < 8; i++)_Context->msg_ClearBreak[i]=" ";
	_Context->hint_ClearBreak[0]=en__ClearBreak;
	_Context->hint_ClearBreak[1]=fr__ClearBreak;
	_Context->hint_ClearBreak[2]=it__ClearBreak;
	_Context->hint_ClearBreak[3]=es__ClearBreak;
	_Context->hint_ClearBreak[4]=de__ClearBreak;
	_Context->hint_ClearBreak[5]=nl__ClearBreak;
	_Context->hint_ClearBreak[6]=pt__ClearBreak;
	_Context->hint_ClearBreak[7]=xx__ClearBreak;
	for (i=0; i < 8; i++)_Context->msg_View[i]=" ";
	_Context->hint_View[0]=en__View;
	_Context->hint_View[1]=fr__View;
	_Context->hint_View[2]=it__View;
	_Context->hint_View[3]=es__View;
	_Context->hint_View[4]=de__View;
	_Context->hint_View[5]=nl__View;
	_Context->hint_View[6]=pt__View;
	_Context->hint_View[7]=xx__View;
	for (i=0; i < 8; i++)_Context->msg_Help[i]=" ";
	_Context->hint_Help[0]=en__Help;
	_Context->hint_Help[1]=fr__Help;
	_Context->hint_Help[2]=it__Help;
	_Context->hint_Help[3]=es__Help;
	_Context->hint_Help[4]=de__Help;
	_Context->hint_Help[5]=nl__Help;
	_Context->hint_Help[6]=pt__Help;
	_Context->hint_Help[7]=xx__Help;
	for (i=0; i < 8; i++)_Context->msg_Save[i]=" ";
	_Context->hint_Save[0]=en__Save;
	_Context->hint_Save[1]=fr__Save;
	_Context->hint_Save[2]=it__Save;
	_Context->hint_Save[3]=es__Save;
	_Context->hint_Save[4]=de__Save;
	_Context->hint_Save[5]=nl__Save;
	_Context->hint_Save[6]=pt__Save;
	_Context->hint_Save[7]=xx__Save;
	for (i=0; i < 8; i++)_Context->msg_Exit[i]=" ";
	_Context->hint_Exit[0]=en__Exit;
	_Context->hint_Exit[1]=fr__Exit;
	_Context->hint_Exit[2]=it__Exit;
	_Context->hint_Exit[3]=es__Exit;
	_Context->hint_Exit[4]=de__Exit;
	_Context->hint_Exit[5]=nl__Exit;
	_Context->hint_Exit[6]=pt__Exit;
	_Context->hint_Exit[7]=xx__Exit;
	for (i=0; i < 8; i++)_Context->msg_BreakKey[i]=" ";
	_Context->msg_BreakKey[0]=en_BreakKey;
	_Context->msg_BreakKey[1]=fr_BreakKey;
	_Context->msg_BreakKey[2]=it_BreakKey;
	_Context->msg_BreakKey[3]=es_BreakKey;
	_Context->msg_BreakKey[4]=de_BreakKey;
	_Context->msg_BreakKey[5]=nl_BreakKey;
	_Context->msg_BreakKey[6]=pt_BreakKey;
	_Context->msg_BreakKey[7]=xx_BreakKey;
	_Context->hint_BreakKey[0]=en__BreakKey;
	_Context->hint_BreakKey[1]=fr__BreakKey;
	_Context->hint_BreakKey[2]=it__BreakKey;
	_Context->hint_BreakKey[3]=es__BreakKey;
	_Context->hint_BreakKey[4]=de__BreakKey;
	_Context->hint_BreakKey[5]=nl__BreakKey;
	_Context->hint_BreakKey[6]=pt__BreakKey;
	_Context->hint_BreakKey[7]=xx__BreakKey;
	_Context->value_BreakKey=get_brayk_value();
	on_BreakKey_event(_Context);
	for (i=0; i < 8; i++)_Context->msg_AsmList[i]=" ";
	_Context->msg_AsmList[0]=en_AsmList;
	_Context->msg_AsmList[1]=fr_AsmList;
	_Context->msg_AsmList[2]=it_AsmList;
	_Context->msg_AsmList[3]=es_AsmList;
	_Context->msg_AsmList[4]=de_AsmList;
	_Context->msg_AsmList[5]=nl_AsmList;
	_Context->msg_AsmList[6]=pt_AsmList;
	_Context->msg_AsmList[7]=xx_AsmList;
	_Context->hint_AsmList[0]=en__AsmList;
	_Context->hint_AsmList[1]=fr__AsmList;
	_Context->hint_AsmList[2]=it__AsmList;
	_Context->hint_AsmList[3]=es__AsmList;
	_Context->hint_AsmList[4]=de__AsmList;
	_Context->hint_AsmList[5]=nl__AsmList;
	_Context->hint_AsmList[6]=pt__AsmList;
	_Context->hint_AsmList[7]=xx__AsmList;
	_Context->value_AsmList=1;
	strcpy(_Context->buffer_Syntax,"LA0");
	for (i=0; i < 8; i++)_Context->msg_SaveConfig[i]=" ";
	_Context->msg_SaveConfig[0]=en_SaveConfig;
	_Context->msg_SaveConfig[1]=fr_SaveConfig;
	_Context->msg_SaveConfig[2]=it_SaveConfig;
	_Context->msg_SaveConfig[3]=es_SaveConfig;
	_Context->msg_SaveConfig[4]=de_SaveConfig;
	_Context->msg_SaveConfig[5]=nl_SaveConfig;
	_Context->msg_SaveConfig[6]=pt_SaveConfig;
	_Context->msg_SaveConfig[7]=xx_SaveConfig;
	_Context->hint_SaveConfig[0]=en__SaveConfig;
	_Context->hint_SaveConfig[1]=fr__SaveConfig;
	_Context->hint_SaveConfig[2]=it__SaveConfig;
	_Context->hint_SaveConfig[3]=es__SaveConfig;
	_Context->hint_SaveConfig[4]=de__SaveConfig;
	_Context->hint_SaveConfig[5]=nl__SaveConfig;
	_Context->hint_SaveConfig[6]=pt__SaveConfig;
	_Context->hint_SaveConfig[7]=xx__SaveConfig;
	_Context->value_SaveConfig=GetQmanSave();
	for (i=0; i < 8; i++)_Context->msg_HexaView[i]=" ";
	_Context->msg_HexaView[0]=en_HexaView;
	_Context->msg_HexaView[1]=fr_HexaView;
	_Context->msg_HexaView[2]=it_HexaView;
	_Context->msg_HexaView[3]=es_HexaView;
	_Context->msg_HexaView[4]=de_HexaView;
	_Context->msg_HexaView[5]=nl_HexaView;
	_Context->msg_HexaView[6]=pt_HexaView;
	_Context->msg_HexaView[7]=xx_HexaView;
	_Context->hint_HexaView[0]=en__HexaView;
	_Context->hint_HexaView[1]=fr__HexaView;
	_Context->hint_HexaView[2]=it__HexaView;
	_Context->hint_HexaView[3]=es__HexaView;
	_Context->hint_HexaView[4]=de__HexaView;
	_Context->hint_HexaView[5]=nl__HexaView;
	_Context->hint_HexaView[6]=pt__HexaView;
	_Context->hint_HexaView[7]=xx__HexaView;
	_Context->hint_Dbio[0]=en__Dbio;
	for (i=0; i < 8; i++)_Context->msg_BreakBar[i]=" ";
	_Context->hint_BreakBar[0]=en__BreakBar;
	_Context->hint_BreakBar[1]=fr__BreakBar;
	_Context->hint_BreakBar[2]=it__BreakBar;
	_Context->hint_BreakBar[3]=es__BreakBar;
	_Context->hint_BreakBar[4]=de__BreakBar;
	_Context->hint_BreakBar[5]=nl__BreakBar;
	_Context->hint_BreakBar[6]=pt__BreakBar;
	_Context->hint_BreakBar[7]=xx__BreakBar;
	_Context->x_BreakBar=66;
	_Context->y_BreakBar=68;
	_Context->w_BreakBar=872;
	_Context->h_BreakBar=16;
	_Context->fg_BreakBar=16;
	_Context->bg_BreakBar=16;
	_Context->fid_BreakBar=1;
	for (i=0; i < 8; i++)_Context->msg_DebugCursor[i]=" ";
	_Context->hint_DebugCursor[0]=en__DebugCursor;
	_Context->hint_DebugCursor[1]=fr__DebugCursor;
	_Context->hint_DebugCursor[2]=it__DebugCursor;
	_Context->hint_DebugCursor[3]=es__DebugCursor;
	_Context->hint_DebugCursor[4]=de__DebugCursor;
	_Context->hint_DebugCursor[5]=nl__DebugCursor;
	_Context->hint_DebugCursor[6]=pt__DebugCursor;
	_Context->hint_DebugCursor[7]=xx__DebugCursor;
	_Context->x_DebugCursor=40;
	_Context->y_DebugCursor=70;
	_Context->w_DebugCursor=16;
	_Context->h_DebugCursor=16;
	_Context->fg_DebugCursor=16;
	_Context->bg_DebugCursor=16;
	_Context->fid_DebugCursor=1;
	for (i=0; i < 8; i++)_Context->msg_ProgramOutput[i]=" ";
	_Context->msg_ProgramOutput[0]=en_ProgramOutput;
	_Context->msg_ProgramOutput[1]=fr_ProgramOutput;
	_Context->msg_ProgramOutput[2]=it_ProgramOutput;
	_Context->msg_ProgramOutput[3]=es_ProgramOutput;
	_Context->msg_ProgramOutput[4]=de_ProgramOutput;
	_Context->msg_ProgramOutput[5]=nl_ProgramOutput;
	_Context->msg_ProgramOutput[6]=pt_ProgramOutput;
	_Context->msg_ProgramOutput[7]=xx_ProgramOutput;
	_Context->hint_ProgramOutput[0]=en__ProgramOutput;
	_Context->hint_ProgramOutput[1]=fr__ProgramOutput;
	_Context->hint_ProgramOutput[2]=it__ProgramOutput;
	_Context->hint_ProgramOutput[3]=es__ProgramOutput;
	_Context->hint_ProgramOutput[4]=de__ProgramOutput;
	_Context->hint_ProgramOutput[5]=nl__ProgramOutput;
	_Context->hint_ProgramOutput[6]=pt__ProgramOutput;
	_Context->hint_ProgramOutput[7]=xx__ProgramOutput;
	_Context->focus_pages[2]=20;
	ProgramWindowOnCreate(30,64,920,560);
	for (i=0; i < 8; i++)_Context->msg_Auto3556[i]=" ";
	_Context->hint_Auto3556[0]=en__Auto3556;
	_Context->hint_Auto3556[1]=fr__Auto3556;
	_Context->hint_Auto3556[2]=it__Auto3556;
	_Context->hint_Auto3556[3]=es__Auto3556;
	_Context->hint_Auto3556[4]=de__Auto3556;
	_Context->hint_Auto3556[5]=nl__Auto3556;
	_Context->hint_Auto3556[6]=pt__Auto3556;
	_Context->hint_Auto3556[7]=xx__Auto3556;
	_Context->hint_Prio[0]=en__Prio;
	_Context->hint_VSB[0]=en__VSB;
	_Context->max_VSB=1;
	_Context->value_VSB=1;
	_Context->limit_VSB=1;
	_Context->value_VSB=0;
	_Context->limit_VSB=560;
	_Context->max_VSB=hardrows();
	_Context->max_HSB=1;
	_Context->value_HSB=1;
	_Context->limit_HSB=1;
	_Context->value_HSB=0;
	_Context->limit_HSB=920;
	_Context->max_HSB=hardcolumns();
	for (i=0; i < 8; i++)_Context->msg_DebugControl[i]=" ";
	_Context->msg_DebugControl[0]=en_DebugControl;
	_Context->msg_DebugControl[1]=fr_DebugControl;
	_Context->msg_DebugControl[2]=it_DebugControl;
	_Context->msg_DebugControl[3]=es_DebugControl;
	_Context->msg_DebugControl[4]=de_DebugControl;
	_Context->msg_DebugControl[5]=nl_DebugControl;
	_Context->msg_DebugControl[6]=pt_DebugControl;
	_Context->msg_DebugControl[7]=xx_DebugControl;
	_Context->hint_DebugControl[0]=en__DebugControl;
	_Context->hint_DebugControl[1]=fr__DebugControl;
	_Context->hint_DebugControl[2]=it__DebugControl;
	_Context->hint_DebugControl[3]=es__DebugControl;
	_Context->hint_DebugControl[4]=de__DebugControl;
	_Context->hint_DebugControl[5]=nl__DebugControl;
	_Context->hint_DebugControl[6]=pt__DebugControl;
	_Context->hint_DebugControl[7]=xx__DebugControl;
	_Context->focus_pages[3]=23;
	for (i=0; i < 8; i++)_Context->msg_Auto3557[i]=" ";
	_Context->hint_Auto3557[0]=en__Auto3557;
	_Context->hint_Auto3557[1]=fr__Auto3557;
	_Context->hint_Auto3557[2]=it__Auto3557;
	_Context->hint_Auto3557[3]=es__Auto3557;
	_Context->hint_Auto3557[4]=de__Auto3557;
	_Context->hint_Auto3557[5]=nl__Auto3557;
	_Context->hint_Auto3557[6]=pt__Auto3557;
	_Context->hint_Auto3557[7]=xx__Auto3557;
	_Context->hint_ErrAdr[0]=en__ErrAdr;
	_Context->hint_AskMask[0]=en__AskMask;
	_Context->hint_MouseMask[0]=en__MouseMask;
	_Context->hint_ErrorAdr[0]=en__ErrorAdr;
	_Context->hint_ErrorVal[0]=en__ErrorVal;
	for (i=0; i < 8; i++)_Context->msg_Auto3559[i]=" ";
	_Context->msg_Auto3559[0]=en_Auto3559;
	_Context->msg_Auto3559[1]=fr_Auto3559;
	_Context->msg_Auto3559[2]=it_Auto3559;
	_Context->msg_Auto3559[3]=es_Auto3559;
	_Context->msg_Auto3559[4]=de_Auto3559;
	_Context->msg_Auto3559[5]=nl_Auto3559;
	_Context->msg_Auto3559[6]=pt_Auto3559;
	_Context->msg_Auto3559[7]=xx_Auto3559;
	for (i=0; i < 8; i++)_Context->msg_Auto3560[i]=" ";
	_Context->msg_Auto3560[0]=en_Auto3560;
	_Context->msg_Auto3560[1]=fr_Auto3560;
	_Context->msg_Auto3560[2]=it_Auto3560;
	_Context->msg_Auto3560[3]=es_Auto3560;
	_Context->msg_Auto3560[4]=de_Auto3560;
	_Context->msg_Auto3560[5]=nl_Auto3560;
	_Context->msg_Auto3560[6]=pt_Auto3560;
	_Context->msg_Auto3560[7]=xx_Auto3560;
	for (i=0; i < 8; i++)_Context->msg_Auto3561[i]=" ";
	_Context->msg_Auto3561[0]=en_Auto3561;
	_Context->msg_Auto3561[1]=fr_Auto3561;
	_Context->msg_Auto3561[2]=it_Auto3561;
	_Context->msg_Auto3561[3]=es_Auto3561;
	_Context->msg_Auto3561[4]=de_Auto3561;
	_Context->msg_Auto3561[5]=nl_Auto3561;
	_Context->msg_Auto3561[6]=pt_Auto3561;
	_Context->msg_Auto3561[7]=xx_Auto3561;
	for (i=0; i < 8; i++)_Context->msg_Auto3562[i]=" ";
	_Context->msg_Auto3562[0]=en_Auto3562;
	_Context->msg_Auto3562[1]=fr_Auto3562;
	_Context->msg_Auto3562[2]=it_Auto3562;
	_Context->msg_Auto3562[3]=es_Auto3562;
	_Context->msg_Auto3562[4]=de_Auto3562;
	_Context->msg_Auto3562[5]=nl_Auto3562;
	_Context->msg_Auto3562[6]=pt_Auto3562;
	_Context->msg_Auto3562[7]=xx_Auto3562;
	for (i=0; i < 8; i++)_Context->msg_Auto3563[i]=" ";
	_Context->msg_Auto3563[0]=en_Auto3563;
	_Context->msg_Auto3563[1]=fr_Auto3563;
	_Context->msg_Auto3563[2]=it_Auto3563;
	_Context->msg_Auto3563[3]=es_Auto3563;
	_Context->msg_Auto3563[4]=de_Auto3563;
	_Context->msg_Auto3563[5]=nl_Auto3563;
	_Context->msg_Auto3563[6]=pt_Auto3563;
	_Context->msg_Auto3563[7]=xx_Auto3563;
	for (i=0; i < 8; i++)_Context->msg_Auto3564[i]=" ";
	_Context->msg_Auto3564[0]=en_Auto3564;
	_Context->msg_Auto3564[1]=fr_Auto3564;
	_Context->msg_Auto3564[2]=it_Auto3564;
	_Context->msg_Auto3564[3]=es_Auto3564;
	_Context->msg_Auto3564[4]=de_Auto3564;
	_Context->msg_Auto3564[5]=nl_Auto3564;
	_Context->msg_Auto3564[6]=pt_Auto3564;
	_Context->msg_Auto3564[7]=xx_Auto3564;
	for (i=0; i < 8; i++)_Context->msg_Auto3565[i]=" ";
	_Context->msg_Auto3565[0]=en_Auto3565;
	_Context->msg_Auto3565[1]=fr_Auto3565;
	_Context->msg_Auto3565[2]=it_Auto3565;
	_Context->msg_Auto3565[3]=es_Auto3565;
	_Context->msg_Auto3565[4]=de_Auto3565;
	_Context->msg_Auto3565[5]=nl_Auto3565;
	_Context->msg_Auto3565[6]=pt_Auto3565;
	_Context->msg_Auto3565[7]=xx_Auto3565;
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
	_Context->hint_Auto3567[0]=en__Auto3567;
	for (i=0; i < 8; i++)_Context->msg_Auto3568[i]=" ";
	_Context->msg_Auto3568[0]=en_Auto3568;
	_Context->msg_Auto3568[1]=fr_Auto3568;
	_Context->msg_Auto3568[2]=it_Auto3568;
	_Context->msg_Auto3568[3]=es_Auto3568;
	_Context->msg_Auto3568[4]=de_Auto3568;
	_Context->msg_Auto3568[5]=nl_Auto3568;
	_Context->msg_Auto3568[6]=pt_Auto3568;
	_Context->msg_Auto3568[7]=xx_Auto3568;
	for (i=0; i < 8; i++)_Context->msg_Auto3569[i]=" ";
	_Context->msg_Auto3569[0]=en_Auto3569;
	_Context->msg_Auto3569[1]=fr_Auto3569;
	_Context->msg_Auto3569[2]=it_Auto3569;
	_Context->msg_Auto3569[3]=es_Auto3569;
	_Context->msg_Auto3569[4]=de_Auto3569;
	_Context->msg_Auto3569[5]=nl_Auto3569;
	_Context->msg_Auto3569[6]=pt_Auto3569;
	_Context->msg_Auto3569[7]=xx_Auto3569;
	for (i=0; i < 8; i++)_Context->msg_Auto3570[i]=" ";
	_Context->msg_Auto3570[0]=en_Auto3570;
	_Context->msg_Auto3570[1]=fr_Auto3570;
	_Context->msg_Auto3570[2]=it_Auto3570;
	_Context->msg_Auto3570[3]=es_Auto3570;
	_Context->msg_Auto3570[4]=de_Auto3570;
	_Context->msg_Auto3570[5]=nl_Auto3570;
	_Context->msg_Auto3570[6]=pt_Auto3570;
	_Context->msg_Auto3570[7]=xx_Auto3570;
	for (i=0; i < 8; i++)_Context->msg_Auto3571[i]=" ";
	_Context->msg_Auto3571[0]=en_Auto3571;
	_Context->msg_Auto3571[1]=fr_Auto3571;
	_Context->msg_Auto3571[2]=it_Auto3571;
	_Context->msg_Auto3571[3]=es_Auto3571;
	_Context->msg_Auto3571[4]=de_Auto3571;
	_Context->msg_Auto3571[5]=nl_Auto3571;
	_Context->msg_Auto3571[6]=pt_Auto3571;
	_Context->msg_Auto3571[7]=xx_Auto3571;
	for (i=0; i < 8; i++)_Context->msg_Auto3572[i]=" ";
	_Context->msg_Auto3572[0]=en_Auto3572;
	_Context->msg_Auto3572[1]=fr_Auto3572;
	_Context->msg_Auto3572[2]=it_Auto3572;
	_Context->msg_Auto3572[3]=es_Auto3572;
	_Context->msg_Auto3572[4]=de_Auto3572;
	_Context->msg_Auto3572[5]=nl_Auto3572;
	_Context->msg_Auto3572[6]=pt_Auto3572;
	_Context->msg_Auto3572[7]=xx_Auto3572;
	for (i=0; i < 8; i++)_Context->msg_Auto3573[i]=" ";
	_Context->msg_Auto3573[0]=en_Auto3573;
	_Context->msg_Auto3573[1]=fr_Auto3573;
	_Context->msg_Auto3573[2]=it_Auto3573;
	_Context->msg_Auto3573[3]=es_Auto3573;
	_Context->msg_Auto3573[4]=de_Auto3573;
	_Context->msg_Auto3573[5]=nl_Auto3573;
	_Context->msg_Auto3573[6]=pt_Auto3573;
	_Context->msg_Auto3573[7]=xx_Auto3573;
	for (i=0; i < 8; i++)_Context->msg_Auto3574[i]=" ";
	_Context->msg_Auto3574[0]=en_Auto3574;
	_Context->msg_Auto3574[1]=fr_Auto3574;
	_Context->msg_Auto3574[2]=it_Auto3574;
	_Context->msg_Auto3574[3]=es_Auto3574;
	_Context->msg_Auto3574[4]=de_Auto3574;
	_Context->msg_Auto3574[5]=nl_Auto3574;
	_Context->msg_Auto3574[6]=pt_Auto3574;
	_Context->msg_Auto3574[7]=xx_Auto3574;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3576[i]=" ";
	_Context->msg_Auto3576[0]=en_Auto3576;
	_Context->msg_Auto3576[1]=fr_Auto3576;
	_Context->msg_Auto3576[2]=it_Auto3576;
	_Context->msg_Auto3576[3]=es_Auto3576;
	_Context->msg_Auto3576[4]=de_Auto3576;
	_Context->msg_Auto3576[5]=nl_Auto3576;
	_Context->msg_Auto3576[6]=pt_Auto3576;
	_Context->msg_Auto3576[7]=xx_Auto3576;
	for (i=0; i < 8; i++)_Context->msg_Auto3577[i]=" ";
	_Context->msg_Auto3577[0]=en_Auto3577;
	_Context->msg_Auto3577[1]=fr_Auto3577;
	_Context->msg_Auto3577[2]=it_Auto3577;
	_Context->msg_Auto3577[3]=es_Auto3577;
	_Context->msg_Auto3577[4]=de_Auto3577;
	_Context->msg_Auto3577[5]=nl_Auto3577;
	_Context->msg_Auto3577[6]=pt_Auto3577;
	_Context->msg_Auto3577[7]=xx_Auto3577;
	for (i=0; i < 8; i++)_Context->msg_Auto3578[i]=" ";
	_Context->msg_Auto3578[0]=en_Auto3578;
	_Context->msg_Auto3578[1]=fr_Auto3578;
	_Context->msg_Auto3578[2]=it_Auto3578;
	_Context->msg_Auto3578[3]=es_Auto3578;
	_Context->msg_Auto3578[4]=de_Auto3578;
	_Context->msg_Auto3578[5]=nl_Auto3578;
	_Context->msg_Auto3578[6]=pt_Auto3578;
	_Context->msg_Auto3578[7]=xx_Auto3578;
	for (i=0; i < 8; i++)_Context->msg_Auto3579[i]=" ";
	_Context->msg_Auto3579[0]=en_Auto3579;
	_Context->msg_Auto3579[1]=fr_Auto3579;
	_Context->msg_Auto3579[2]=it_Auto3579;
	_Context->msg_Auto3579[3]=es_Auto3579;
	_Context->msg_Auto3579[4]=de_Auto3579;
	_Context->msg_Auto3579[5]=nl_Auto3579;
	_Context->msg_Auto3579[6]=pt_Auto3579;
	_Context->msg_Auto3579[7]=xx_Auto3579;
	for (i=0; i < 8; i++)_Context->msg_ProcName[i]=" ";
	_Context->msg_ProcName[2]=it_ProcName;
	_Context->msg_ProcName[3]=es_ProcName;
	_Context->msg_ProcName[4]=de_ProcName;
	_Context->msg_ProcName[5]=nl_ProcName;
	_Context->msg_ProcName[6]=pt_ProcName;
	_Context->msg_ProcName[7]=xx_ProcName;
	for (i=0; i < 8; i++)_Context->msg_ProcEdit[i]=" ";
	_Context->msg_ProcEdit[0]=en_ProcEdit;
	_Context->msg_ProcEdit[1]=fr_ProcEdit;
	_Context->msg_ProcEdit[2]=it_ProcEdit;
	_Context->msg_ProcEdit[3]=es_ProcEdit;
	_Context->msg_ProcEdit[4]=de_ProcEdit;
	_Context->msg_ProcEdit[5]=nl_ProcEdit;
	_Context->msg_ProcEdit[6]=pt_ProcEdit;
	_Context->msg_ProcEdit[7]=xx_ProcEdit;
	_Context->hint_ProcEdit[0]=en__ProcEdit;
	for (i=0; i < 8; i++)_Context->msg_SegmentEdit[i]=" ";
	_Context->msg_SegmentEdit[0]=en_SegmentEdit;
	_Context->msg_SegmentEdit[1]=fr_SegmentEdit;
	_Context->msg_SegmentEdit[2]=it_SegmentEdit;
	_Context->msg_SegmentEdit[3]=es_SegmentEdit;
	_Context->msg_SegmentEdit[4]=de_SegmentEdit;
	_Context->msg_SegmentEdit[5]=nl_SegmentEdit;
	_Context->msg_SegmentEdit[6]=pt_SegmentEdit;
	_Context->msg_SegmentEdit[7]=xx_SegmentEdit;
	for (i=0; i < 8; i++)_Context->msg_ProcInfo[i]=" ";
	_Context->msg_ProcInfo[0]=en_ProcInfo;
	_Context->msg_ProcInfo[1]=fr_ProcInfo;
	_Context->msg_ProcInfo[2]=it_ProcInfo;
	_Context->msg_ProcInfo[3]=es_ProcInfo;
	_Context->msg_ProcInfo[4]=de_ProcInfo;
	_Context->msg_ProcInfo[5]=nl_ProcInfo;
	_Context->msg_ProcInfo[6]=pt_ProcInfo;
	_Context->msg_ProcInfo[7]=xx_ProcInfo;
	for (i=0; i < 8; i++)_Context->msg_SegmName[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_GlobNames[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_LocalNames[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AssignList[i]=" ";
	_Context->hint_AssignList[0]=en__AssignList;
	for (i=0; i < 8; i++)_Context->msg_RegisterList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AttachList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_StackList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_LibraryList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_ObserveList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_DeleteObservation[i]=" ";
	_Context->msg_DeleteObservation[0]=en_DeleteObservation;
	_Context->msg_DeleteObservation[1]=fr_DeleteObservation;
	_Context->msg_DeleteObservation[2]=it_DeleteObservation;
	_Context->msg_DeleteObservation[3]=es_DeleteObservation;
	_Context->msg_DeleteObservation[4]=de_DeleteObservation;
	_Context->msg_DeleteObservation[5]=nl_DeleteObservation;
	_Context->msg_DeleteObservation[6]=pt_DeleteObservation;
	_Context->msg_DeleteObservation[7]=xx_DeleteObservation;
	for (i=0; i < 8; i++)_Context->msg_BreakList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_RemoveBreak[i]=" ";
	_Context->msg_RemoveBreak[0]=en_RemoveBreak;
	for (i=0; i < 8; i++)_Context->msg_ExportAssign[i]=" ";
	_Context->msg_ExportAssign[0]=en_ExportAssign;
	_Context->hint_ExportAssign[0]=en__ExportAssign;
	for (i=0; i < 8; i++)_Context->msg_WatchList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_DeleteWatch[i]=" ";
	_Context->msg_DeleteWatch[0]=en_DeleteWatch;
	_Context->msg_DeleteWatch[1]=fr_DeleteWatch;
	_Context->msg_DeleteWatch[2]=it_DeleteWatch;
	_Context->msg_DeleteWatch[3]=es_DeleteWatch;
	_Context->msg_DeleteWatch[4]=de_DeleteWatch;
	_Context->msg_DeleteWatch[5]=nl_DeleteWatch;
	_Context->msg_DeleteWatch[6]=pt_DeleteWatch;
	_Context->msg_DeleteWatch[7]=xx_DeleteWatch;
	for (i=0; i < 8; i++)_Context->msg_SourceList[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_InspectSource[i]=" ";
	_Context->msg_InspectSource[0]=en_InspectSource;
	_Context->msg_InspectSource[1]=fr_InspectSource;
	_Context->msg_InspectSource[2]=it_InspectSource;
	_Context->msg_InspectSource[3]=es_InspectSource;
	_Context->msg_InspectSource[4]=de_InspectSource;
	_Context->msg_InspectSource[5]=nl_InspectSource;
	_Context->msg_InspectSource[6]=pt_InspectSource;
	_Context->msg_InspectSource[7]=xx_InspectSource;
	for (i=0; i < 8; i++)_Context->msg_Auto3580[i]=" ";
	_Context->msg_Auto3580[0]=en_Auto3580;
	_Context->msg_Auto3580[1]=fr_Auto3580;
	_Context->msg_Auto3580[2]=it_Auto3580;
	_Context->msg_Auto3580[3]=es_Auto3580;
	_Context->msg_Auto3580[4]=de_Auto3580;
	_Context->msg_Auto3580[5]=nl_Auto3580;
	_Context->msg_Auto3580[6]=pt_Auto3580;
	_Context->msg_Auto3580[7]=xx_Auto3580;
	for (i=0; i < 8; i++)_Context->msg_auto6060[i]=" ";
	_Context->msg_auto6060[0]=en_auto6060;
	_Context->msg_auto6060[1]=fr_auto6060;
	_Context->msg_auto6060[2]=it_auto6060;
	_Context->msg_auto6060[3]=es_auto6060;
	_Context->msg_auto6060[4]=de_auto6060;
	_Context->msg_auto6060[5]=nl_auto6060;
	_Context->msg_auto6060[6]=pt_auto6060;
	_Context->msg_auto6060[7]=xx_auto6060;
	for (i=0; i < 8; i++)_Context->msg_Auto3581[i]=" ";
	_Context->msg_Auto3581[0]=en_Auto3581;
	_Context->msg_Auto3581[1]=fr_Auto3581;
	_Context->msg_Auto3581[2]=it_Auto3581;
	_Context->msg_Auto3581[3]=es_Auto3581;
	_Context->msg_Auto3581[4]=de_Auto3581;
	_Context->msg_Auto3581[5]=nl_Auto3581;
	_Context->msg_Auto3581[6]=pt_Auto3581;
	_Context->msg_Auto3581[7]=xx_Auto3581;
	_Context->hint_Auto3581[0]=en__Auto3581;
	_Context->hint_Auto3581[1]=fr__Auto3581;
	_Context->hint_Auto3581[2]=it__Auto3581;
	_Context->hint_Auto3581[3]=es__Auto3581;
	_Context->hint_Auto3581[4]=de__Auto3581;
	_Context->hint_Auto3581[5]=nl__Auto3581;
	_Context->hint_Auto3581[6]=pt__Auto3581;
	_Context->hint_Auto3581[7]=xx__Auto3581;
	for (i=0; i < 8; i++)_Context->msg_Auto3582[i]=" ";
	_Context->msg_Auto3582[0]=en_Auto3582;
	_Context->msg_Auto3582[1]=fr_Auto3582;
	_Context->msg_Auto3582[2]=it_Auto3582;
	_Context->msg_Auto3582[3]=es_Auto3582;
	_Context->msg_Auto3582[4]=de_Auto3582;
	_Context->msg_Auto3582[5]=nl_Auto3582;
	_Context->msg_Auto3582[6]=pt_Auto3582;
	_Context->msg_Auto3582[7]=xx_Auto3582;
	_Context->hint_Auto3582[0]=en__Auto3582;
	_Context->hint_Auto3582[1]=fr__Auto3582;
	_Context->hint_Auto3582[2]=it__Auto3582;
	_Context->hint_Auto3582[3]=es__Auto3582;
	_Context->hint_Auto3582[4]=de__Auto3582;
	_Context->hint_Auto3582[5]=nl__Auto3582;
	_Context->hint_Auto3582[6]=pt__Auto3582;
	_Context->hint_Auto3582[7]=xx__Auto3582;
	for (i=0; i < 8; i++)_Context->msg_Auto3583[i]=" ";
	_Context->msg_Auto3583[0]=en_Auto3583;
	_Context->msg_Auto3583[1]=fr_Auto3583;
	_Context->msg_Auto3583[2]=it_Auto3583;
	_Context->msg_Auto3583[3]=es_Auto3583;
	_Context->msg_Auto3583[4]=de_Auto3583;
	_Context->msg_Auto3583[5]=nl_Auto3583;
	_Context->msg_Auto3583[6]=pt_Auto3583;
	_Context->msg_Auto3583[7]=xx_Auto3583;
	_Context->hint_Auto3583[0]=en__Auto3583;
	_Context->hint_Auto3583[1]=fr__Auto3583;
	_Context->hint_Auto3583[2]=it__Auto3583;
	_Context->hint_Auto3583[3]=es__Auto3583;
	_Context->hint_Auto3583[4]=de__Auto3583;
	_Context->hint_Auto3583[5]=nl__Auto3583;
	_Context->hint_Auto3583[6]=pt__Auto3583;
	_Context->hint_Auto3583[7]=xx__Auto3583;
	for (i=0; i < 8; i++)_Context->msg_Auto3584[i]=" ";
	_Context->msg_Auto3584[0]=en_Auto3584;
	_Context->msg_Auto3584[1]=fr_Auto3584;
	_Context->msg_Auto3584[2]=it_Auto3584;
	_Context->msg_Auto3584[3]=es_Auto3584;
	_Context->msg_Auto3584[4]=de_Auto3584;
	_Context->msg_Auto3584[5]=nl_Auto3584;
	_Context->msg_Auto3584[6]=pt_Auto3584;
	_Context->msg_Auto3584[7]=xx_Auto3584;
	_Context->hint_Auto3584[0]=en__Auto3584;
	_Context->hint_Auto3584[1]=fr__Auto3584;
	_Context->hint_Auto3584[2]=it__Auto3584;
	_Context->hint_Auto3584[3]=es__Auto3584;
	_Context->hint_Auto3584[4]=de__Auto3584;
	_Context->hint_Auto3584[5]=nl__Auto3584;
	_Context->hint_Auto3584[6]=pt__Auto3584;
	_Context->hint_Auto3584[7]=xx__Auto3584;
	for (i=0; i < 8; i++)_Context->msg_Auto3585[i]=" ";
	_Context->msg_Auto3585[0]=en_Auto3585;
	_Context->msg_Auto3585[1]=fr_Auto3585;
	_Context->msg_Auto3585[2]=it_Auto3585;
	_Context->msg_Auto3585[3]=es_Auto3585;
	_Context->msg_Auto3585[4]=de_Auto3585;
	_Context->msg_Auto3585[5]=nl_Auto3585;
	_Context->msg_Auto3585[6]=pt_Auto3585;
	_Context->msg_Auto3585[7]=xx_Auto3585;
	_Context->hint_Auto3585[0]=en__Auto3585;
	_Context->hint_Auto3585[1]=fr__Auto3585;
	_Context->hint_Auto3585[2]=it__Auto3585;
	_Context->hint_Auto3585[3]=es__Auto3585;
	_Context->hint_Auto3585[4]=de__Auto3585;
	_Context->hint_Auto3585[5]=nl__Auto3585;
	_Context->hint_Auto3585[6]=pt__Auto3585;
	_Context->hint_Auto3585[7]=xx__Auto3585;
	for (i=0; i < 8; i++)_Context->msg_auto6061[i]=" ";
	_Context->msg_auto6061[0]=en_auto6061;
	_Context->msg_auto6061[1]=fr_auto6061;
	_Context->msg_auto6061[2]=it_auto6061;
	_Context->msg_auto6061[3]=es_auto6061;
	_Context->msg_auto6061[4]=de_auto6061;
	_Context->msg_auto6061[5]=nl_auto6061;
	_Context->msg_auto6061[6]=pt_auto6061;
	_Context->msg_auto6061[7]=xx_auto6061;
	_Context->hint_auto6061[0]=en__auto6061;
	for (i=0; i < 8; i++)_Context->msg_auto6062[i]=" ";
	_Context->msg_auto6062[0]=en_auto6062;
	_Context->msg_auto6062[1]=fr_auto6062;
	_Context->msg_auto6062[2]=it_auto6062;
	_Context->msg_auto6062[3]=es_auto6062;
	_Context->msg_auto6062[4]=de_auto6062;
	_Context->msg_auto6062[5]=nl_auto6062;
	_Context->msg_auto6062[6]=pt_auto6062;
	_Context->msg_auto6062[7]=xx_auto6062;
	_Context->hint_auto6062[0]=en__auto6062;
	for (i=0; i < 8; i++)_Context->msg_auto6063[i]=" ";
	_Context->msg_auto6063[0]=en_auto6063;
	_Context->msg_auto6063[1]=fr_auto6063;
	_Context->msg_auto6063[2]=it_auto6063;
	_Context->msg_auto6063[3]=es_auto6063;
	_Context->msg_auto6063[4]=de_auto6063;
	_Context->msg_auto6063[5]=nl_auto6063;
	_Context->msg_auto6063[6]=pt_auto6063;
	_Context->msg_auto6063[7]=xx_auto6063;
	_Context->hint_auto6063[0]=en__auto6063;
	for (i=0; i < 8; i++)_Context->msg_auto6064[i]=" ";
	_Context->msg_auto6064[0]=en_auto6064;
	_Context->msg_auto6064[1]=fr_auto6064;
	_Context->msg_auto6064[2]=it_auto6064;
	_Context->msg_auto6064[3]=es_auto6064;
	_Context->msg_auto6064[4]=de_auto6064;
	_Context->msg_auto6064[5]=nl_auto6064;
	_Context->msg_auto6064[6]=pt_auto6064;
	_Context->msg_auto6064[7]=xx_auto6064;
	_Context->hint_auto6064[0]=en__auto6064;
	for (i=0; i < 8; i++)_Context->msg_Auto3586[i]=" ";
	_Context->msg_Auto3586[0]=en_Auto3586;
	_Context->msg_Auto3586[1]=fr_Auto3586;
	_Context->msg_Auto3586[2]=it_Auto3586;
	_Context->msg_Auto3586[3]=es_Auto3586;
	_Context->msg_Auto3586[4]=de_Auto3586;
	_Context->msg_Auto3586[5]=nl_Auto3586;
	_Context->msg_Auto3586[6]=pt_Auto3586;
	_Context->msg_Auto3586[7]=xx_Auto3586;
	_Context->hint_Auto3586[0]=en__Auto3586;
	for (i=0; i < 8; i++)_Context->msg_AED_NORMAL[i]=" ";
	_Context->value_AED_NORMAL=0;
	for (i=0; i < 8; i++)_Context->msg_AED_QUOTE[i]=" ";
	_Context->value_AED_QUOTE=12;
	for (i=0; i < 8; i++)_Context->msg_AED_KEYWORD[i]=" ";
	_Context->hint_AED_KEYWORD[0]=en__AED_KEYWORD;
	_Context->value_AED_KEYWORD=9;
	for (i=0; i < 8; i++)_Context->msg_AED_COMMENT[i]=" ";
	_Context->hint_AED_COMMENT[0]=en__AED_COMMENT;
	_Context->value_AED_COMMENT=10;
	for (i=0; i < 8; i++)_Context->msg_AED_PUNCTUATE[i]=" ";
	_Context->hint_AED_PUNCTUATE[0]=en__AED_PUNCTUATE;
	_Context->value_AED_PUNCTUATE=0;
	for (i=0; i < 8; i++)_Context->msg_AED_FONT[i]=" ";
	_Context->hint_AED_FONT[0]=en__AED_FONT;
	for (i=0; i < 8; i++)_Context->msg_EditorColour[i]=" ";
	_Context->msg_EditorColour[0]=en_EditorColour;
	_Context->msg_EditorColour[1]=fr_EditorColour;
	_Context->msg_EditorColour[2]=it_EditorColour;
	_Context->msg_EditorColour[3]=es_EditorColour;
	_Context->msg_EditorColour[4]=de_EditorColour;
	_Context->msg_EditorColour[5]=nl_EditorColour;
	_Context->msg_EditorColour[6]=pt_EditorColour;
	_Context->msg_EditorColour[7]=xx_EditorColour;
	_Context->hint_EditorColour[0]=en__EditorColour;
	_Context->hint_EditorColour[1]=fr__EditorColour;
	_Context->hint_EditorColour[2]=it__EditorColour;
	_Context->hint_EditorColour[3]=es__EditorColour;
	_Context->hint_EditorColour[4]=de__EditorColour;
	_Context->hint_EditorColour[5]=nl__EditorColour;
	_Context->hint_EditorColour[6]=pt__EditorColour;
	_Context->hint_EditorColour[7]=xx__EditorColour;
	for (i=0; i < 8; i++)_Context->msg_SetBreakAP[i]=" ";
	_Context->msg_SetBreakAP[0]=en_SetBreakAP;
	_Context->msg_SetBreakAP[1]=fr_SetBreakAP;
	_Context->msg_SetBreakAP[2]=it_SetBreakAP;
	_Context->msg_SetBreakAP[3]=es_SetBreakAP;
	_Context->msg_SetBreakAP[4]=de_SetBreakAP;
	_Context->msg_SetBreakAP[5]=nl_SetBreakAP;
	_Context->msg_SetBreakAP[6]=pt_SetBreakAP;
	_Context->msg_SetBreakAP[7]=xx_SetBreakAP;
	for (i=0; i < 8; i++)_Context->msg_SetBreakBP[i]=" ";
	_Context->msg_SetBreakBP[0]=en_SetBreakBP;
	_Context->msg_SetBreakBP[1]=fr_SetBreakBP;
	_Context->msg_SetBreakBP[2]=it_SetBreakBP;
	_Context->msg_SetBreakBP[3]=es_SetBreakBP;
	_Context->msg_SetBreakBP[4]=de_SetBreakBP;
	_Context->msg_SetBreakBP[5]=nl_SetBreakBP;
	_Context->msg_SetBreakBP[6]=pt_SetBreakBP;
	_Context->msg_SetBreakBP[7]=xx_SetBreakBP;
	for (i=0; i < 8; i++)_Context->msg_SetBreakAS[i]=" ";
	_Context->msg_SetBreakAS[0]=en_SetBreakAS;
	_Context->msg_SetBreakAS[1]=fr_SetBreakAS;
	_Context->msg_SetBreakAS[2]=it_SetBreakAS;
	_Context->msg_SetBreakAS[3]=es_SetBreakAS;
	_Context->msg_SetBreakAS[4]=de_SetBreakAS;
	_Context->msg_SetBreakAS[5]=nl_SetBreakAS;
	_Context->msg_SetBreakAS[6]=pt_SetBreakAS;
	_Context->msg_SetBreakAS[7]=xx_SetBreakAS;
	for (i=0; i < 8; i++)_Context->msg_SetFileWatch[i]=" ";
	_Context->msg_SetFileWatch[0]=en_SetFileWatch;
	_Context->msg_SetFileWatch[1]=fr_SetFileWatch;
	_Context->msg_SetFileWatch[2]=it_SetFileWatch;
	_Context->msg_SetFileWatch[3]=es_SetFileWatch;
	_Context->msg_SetFileWatch[4]=de_SetFileWatch;
	_Context->msg_SetFileWatch[5]=nl_SetFileWatch;
	_Context->msg_SetFileWatch[6]=pt_SetFileWatch;
	_Context->msg_SetFileWatch[7]=xx_SetFileWatch;
	_Context->hint_SetFileWatch[0]=en__SetFileWatch;
	_Context->hint_SetFileWatch[1]=fr__SetFileWatch;
	_Context->hint_SetFileWatch[2]=it__SetFileWatch;
	_Context->hint_SetFileWatch[3]=es__SetFileWatch;
	_Context->hint_SetFileWatch[4]=de__SetFileWatch;
	_Context->hint_SetFileWatch[5]=nl__SetFileWatch;
	_Context->hint_SetFileWatch[6]=pt__SetFileWatch;
	_Context->hint_SetFileWatch[7]=xx__SetFileWatch;
	for (i=0; i < 8; i++)_Context->msg_AllFileWatch[i]=" ";
	_Context->msg_AllFileWatch[0]=en_AllFileWatch;
	_Context->msg_AllFileWatch[1]=fr_AllFileWatch;
	_Context->msg_AllFileWatch[2]=it_AllFileWatch;
	_Context->msg_AllFileWatch[3]=es_AllFileWatch;
	_Context->msg_AllFileWatch[4]=de_AllFileWatch;
	_Context->msg_AllFileWatch[5]=nl_AllFileWatch;
	_Context->msg_AllFileWatch[6]=pt_AllFileWatch;
	_Context->msg_AllFileWatch[7]=xx_AllFileWatch;
	_Context->hint_AllFileWatch[0]=en__AllFileWatch;
	_Context->hint_AllFileWatch[1]=fr__AllFileWatch;
	_Context->hint_AllFileWatch[2]=it__AllFileWatch;
	_Context->hint_AllFileWatch[3]=es__AllFileWatch;
	_Context->hint_AllFileWatch[4]=de__AllFileWatch;
	_Context->hint_AllFileWatch[5]=nl__AllFileWatch;
	_Context->hint_AllFileWatch[6]=pt__AllFileWatch;
	_Context->hint_AllFileWatch[7]=xx__AllFileWatch;
	for (i=0; i < 8; i++)_Context->msg_RazFileWatch[i]=" ";
	_Context->msg_RazFileWatch[0]=en_RazFileWatch;
	_Context->msg_RazFileWatch[1]=fr_RazFileWatch;
	_Context->msg_RazFileWatch[2]=it_RazFileWatch;
	_Context->msg_RazFileWatch[3]=es_RazFileWatch;
	_Context->msg_RazFileWatch[4]=de_RazFileWatch;
	_Context->msg_RazFileWatch[5]=nl_RazFileWatch;
	_Context->msg_RazFileWatch[6]=pt_RazFileWatch;
	_Context->msg_RazFileWatch[7]=xx_RazFileWatch;
	_Context->hint_RazFileWatch[0]=en__RazFileWatch;
	_Context->hint_RazFileWatch[1]=fr__RazFileWatch;
	_Context->hint_RazFileWatch[2]=it__RazFileWatch;
	_Context->hint_RazFileWatch[3]=es__RazFileWatch;
	_Context->hint_RazFileWatch[4]=de__RazFileWatch;
	_Context->hint_RazFileWatch[5]=nl__RazFileWatch;
	_Context->hint_RazFileWatch[6]=pt__RazFileWatch;
	_Context->hint_RazFileWatch[7]=xx__RazFileWatch;
	for (i=0; i < 8; i++)_Context->msg_SetBreakBS[i]=" ";
	_Context->msg_SetBreakBS[0]=en_SetBreakBS;
	_Context->msg_SetBreakBS[1]=fr_SetBreakBS;
	_Context->msg_SetBreakBS[2]=it_SetBreakBS;
	_Context->msg_SetBreakBS[3]=es_SetBreakBS;
	_Context->msg_SetBreakBS[4]=de_SetBreakBS;
	_Context->msg_SetBreakBS[5]=nl_SetBreakBS;
	_Context->msg_SetBreakBS[6]=pt_SetBreakBS;
	_Context->msg_SetBreakBS[7]=xx_SetBreakBS;
	for (i=0; i < 8; i++)_Context->msg_MultipleWatch[i]=" ";
	_Context->msg_MultipleWatch[0]=en_MultipleWatch;
	_Context->msg_MultipleWatch[1]=fr_MultipleWatch;
	_Context->msg_MultipleWatch[2]=it_MultipleWatch;
	_Context->msg_MultipleWatch[3]=es_MultipleWatch;
	_Context->msg_MultipleWatch[4]=de_MultipleWatch;
	_Context->msg_MultipleWatch[5]=nl_MultipleWatch;
	_Context->msg_MultipleWatch[6]=pt_MultipleWatch;
	_Context->msg_MultipleWatch[7]=xx_MultipleWatch;
	for (i=0; i < 8; i++)_Context->msg_SingleWatch[i]=" ";
	_Context->msg_SingleWatch[0]=en_SingleWatch;
	_Context->msg_SingleWatch[1]=fr_SingleWatch;
	_Context->msg_SingleWatch[2]=it_SingleWatch;
	_Context->msg_SingleWatch[3]=es_SingleWatch;
	_Context->msg_SingleWatch[4]=de_SingleWatch;
	_Context->msg_SingleWatch[5]=nl_SingleWatch;
	_Context->msg_SingleWatch[6]=pt_SingleWatch;
	_Context->msg_SingleWatch[7]=xx_SingleWatch;
	for (i=0; i < 8; i++)_Context->msg_ObserveGlobal[i]=" ";
	_Context->msg_ObserveGlobal[0]=en_ObserveGlobal;
	_Context->msg_ObserveGlobal[1]=fr_ObserveGlobal;
	_Context->msg_ObserveGlobal[2]=it_ObserveGlobal;
	_Context->msg_ObserveGlobal[3]=es_ObserveGlobal;
	_Context->msg_ObserveGlobal[4]=de_ObserveGlobal;
	_Context->msg_ObserveGlobal[5]=nl_ObserveGlobal;
	_Context->msg_ObserveGlobal[6]=pt_ObserveGlobal;
	_Context->msg_ObserveGlobal[7]=xx_ObserveGlobal;
	for (i=0; i < 8; i++)_Context->msg_InspectGlobal[i]=" ";
	_Context->msg_InspectGlobal[0]=en_InspectGlobal;
	_Context->msg_InspectGlobal[1]=fr_InspectGlobal;
	_Context->msg_InspectGlobal[2]=it_InspectGlobal;
	_Context->msg_InspectGlobal[3]=es_InspectGlobal;
	_Context->msg_InspectGlobal[4]=de_InspectGlobal;
	_Context->msg_InspectGlobal[5]=nl_InspectGlobal;
	_Context->msg_InspectGlobal[6]=pt_InspectGlobal;
	_Context->msg_InspectGlobal[7]=xx_InspectGlobal;
	for (i=0; i < 8; i++)_Context->msg_ObserveLocal[i]=" ";
	_Context->msg_ObserveLocal[0]=en_ObserveLocal;
	_Context->msg_ObserveLocal[1]=fr_ObserveLocal;
	_Context->msg_ObserveLocal[2]=it_ObserveLocal;
	_Context->msg_ObserveLocal[3]=es_ObserveLocal;
	_Context->msg_ObserveLocal[4]=de_ObserveLocal;
	_Context->msg_ObserveLocal[5]=nl_ObserveLocal;
	_Context->msg_ObserveLocal[6]=pt_ObserveLocal;
	_Context->msg_ObserveLocal[7]=xx_ObserveLocal;
	for (i=0; i < 8; i++)_Context->msg_InspectLocal[i]=" ";
	_Context->msg_InspectLocal[0]=en_InspectLocal;
	_Context->msg_InspectLocal[1]=fr_InspectLocal;
	_Context->msg_InspectLocal[2]=it_InspectLocal;
	_Context->msg_InspectLocal[3]=es_InspectLocal;
	_Context->msg_InspectLocal[4]=de_InspectLocal;
	_Context->msg_InspectLocal[5]=nl_InspectLocal;
	_Context->msg_InspectLocal[6]=pt_InspectLocal;
	_Context->msg_InspectLocal[7]=xx_InspectLocal;
	for (i=0; i < 8; i++)_Context->msg_VariableControl[i]=" ";
	_Context->msg_VariableControl[0]=en_VariableControl;
	_Context->msg_VariableControl[1]=fr_VariableControl;
	_Context->msg_VariableControl[2]=it_VariableControl;
	_Context->msg_VariableControl[3]=es_VariableControl;
	_Context->msg_VariableControl[4]=de_VariableControl;
	_Context->msg_VariableControl[5]=nl_VariableControl;
	_Context->msg_VariableControl[6]=pt_VariableControl;
	_Context->msg_VariableControl[7]=xx_VariableControl;
	_Context->hint_VariableControl[0]=en__VariableControl;
	_Context->hint_VariableControl[1]=fr__VariableControl;
	_Context->hint_VariableControl[2]=it__VariableControl;
	_Context->hint_VariableControl[3]=es__VariableControl;
	_Context->hint_VariableControl[4]=de__VariableControl;
	_Context->hint_VariableControl[5]=nl__VariableControl;
	_Context->hint_VariableControl[6]=pt__VariableControl;
	_Context->hint_VariableControl[7]=xx__VariableControl;
	_Context->focus_pages[4]=71;
	for (i=0; i < 8; i++)_Context->msg_Auto3587[i]=" ";
	_Context->hint_Auto3587[0]=en__Auto3587;
	_Context->hint_Auto3587[1]=fr__Auto3587;
	_Context->hint_Auto3587[2]=it__Auto3587;
	_Context->hint_Auto3587[3]=es__Auto3587;
	_Context->hint_Auto3587[4]=de__Auto3587;
	_Context->hint_Auto3587[5]=nl__Auto3587;
	_Context->hint_Auto3587[6]=pt__Auto3587;
	_Context->hint_Auto3587[7]=xx__Auto3587;
	for (i=0; i < 8; i++)_Context->msg_vListe[i]=" ";
	_Context->msg_vListe[0]=en_vListe;
	_Context->msg_vListe[1]=fr_vListe;
	_Context->msg_vListe[2]=it_vListe;
	_Context->msg_vListe[3]=es_vListe;
	_Context->msg_vListe[4]=de_vListe;
	_Context->msg_vListe[5]=nl_vListe;
	_Context->msg_vListe[6]=pt_vListe;
	_Context->msg_vListe[7]=xx_vListe;
	_Context->hint_vListe[0]=en__vListe;
	if ( 0 > 0 ) { _Context->row_vListe=&_Context->buffer_vListe[0-1][0]; } ;
	_Context->hint_vBar[0]=en__vBar;
	_Context->max_vBar=1;
	_Context->value_vBar=1;
	_Context->limit_vBar=1;
	_Context->value_vBar=0;
	_Context->limit_vBar=34;
	_Context->max_vBar=32000;
	_Context->hint_Auto3588[0]=en__Auto3588;
	_Context->hint_StatusBar[0]=en__StatusBar;
	(void) on_StatusBar_create(_Context);
	return(0);
}

public 	int	visual_debug_hide(struct visual_debug_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;

	return(result);
}

public	int	visual_debug_remove(
	struct visual_debug_context * _Context,
	char * pBreakKey,
	char * pAsmList,
	char * pSaveConfig,
	char * pHexaView,
	char * pDbio,
	char * pPrio,
	char * pProcName,
	char * pProcInfo,
	char * pSegmName,
	char * pGlobNames,
	char * pLocalNames,
	char * pAssignList,
	char * pRegisterList,
	char * pAttachList,
	char * pStackList,
	char * pLibraryList,
	char * pObserveList,
	char * pBreakList,
	char * pWatchList,
	char * pSourceList,
	char * pSyntax,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAED_FONT,
	char * pStatusBar)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	ProgramWindowOnRemove();
	WindowEditorOnRemove();
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"WWWWSSWWWWWWWWWWWWWWSWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout((void *) 0, 0, pBreakKey);
		if ( pBreakKey != (char *) 0)
			*((int*)pBreakKey) = _Context->value_BreakKey;
		visual_transferout((void *) 0, 0, pAsmList);
		if ( pAsmList != (char *) 0)
			*((int*)pAsmList) = _Context->value_AsmList;
		visual_transferout((void *) 0, 0, pSaveConfig);
		if ( pSaveConfig != (char *) 0)
			*((int*)pSaveConfig) = _Context->value_SaveConfig;
		visual_transferout((void *) 0, 0, pHexaView);
		if ( pHexaView != (char *) 0)
			*((int*)pHexaView) = _Context->value_HexaView;
		visual_transferout(_Context->buffer_Dbio, 4032, pDbio);
		visual_transferout(_Context->buffer_Prio, 4025, pPrio);
		visual_transferout((void *) 0, 0, pProcName);
		if ( pProcName != (char *) 0)
			*((int*)pProcName) = _Context->value_ProcName;
		visual_transferout((void *) 0, 0, pProcInfo);
		if ( pProcInfo != (char *) 0)
			*((int*)pProcInfo) = _Context->value_ProcInfo;
		visual_transferout((void *) 0, 0, pSegmName);
		if ( pSegmName != (char *) 0)
			*((int*)pSegmName) = _Context->value_SegmName;
		visual_transferout((void *) 0, 0, pGlobNames);
		if ( pGlobNames != (char *) 0)
			*((int*)pGlobNames) = _Context->value_GlobNames;
		visual_transferout((void *) 0, 0, pLocalNames);
		if ( pLocalNames != (char *) 0)
			*((int*)pLocalNames) = _Context->value_LocalNames;
		visual_transferout((void *) 0, 0, pAssignList);
		if ( pAssignList != (char *) 0)
			*((int*)pAssignList) = _Context->value_AssignList;
		visual_transferout((void *) 0, 0, pRegisterList);
		if ( pRegisterList != (char *) 0)
			*((int*)pRegisterList) = _Context->value_RegisterList;
		visual_transferout((void *) 0, 0, pAttachList);
		if ( pAttachList != (char *) 0)
			*((int*)pAttachList) = _Context->value_AttachList;
		visual_transferout((void *) 0, 0, pStackList);
		if ( pStackList != (char *) 0)
			*((int*)pStackList) = _Context->value_StackList;
		visual_transferout((void *) 0, 0, pLibraryList);
		if ( pLibraryList != (char *) 0)
			*((int*)pLibraryList) = _Context->value_LibraryList;
		visual_transferout((void *) 0, 0, pObserveList);
		if ( pObserveList != (char *) 0)
			*((int*)pObserveList) = _Context->value_ObserveList;
		visual_transferout((void *) 0, 0, pBreakList);
		if ( pBreakList != (char *) 0)
			*((int*)pBreakList) = _Context->value_BreakList;
		visual_transferout((void *) 0, 0, pWatchList);
		if ( pWatchList != (char *) 0)
			*((int*)pWatchList) = _Context->value_WatchList;
		visual_transferout((void *) 0, 0, pSourceList);
		if ( pSourceList != (char *) 0)
			*((int*)pSourceList) = _Context->value_SourceList;
		visual_transferout(_Context->buffer_Syntax, 226, pSyntax);
		visual_transferout((void *) 0, 0, pAED_NORMAL);
		if ( pAED_NORMAL != (char *) 0)
			*((int*)pAED_NORMAL) = _Context->value_AED_NORMAL;
		visual_transferout((void *) 0, 0, pAED_QUOTE);
		if ( pAED_QUOTE != (char *) 0)
			*((int*)pAED_QUOTE) = _Context->value_AED_QUOTE;
		visual_transferout((void *) 0, 0, pAED_KEYWORD);
		if ( pAED_KEYWORD != (char *) 0)
			*((int*)pAED_KEYWORD) = _Context->value_AED_KEYWORD;
		visual_transferout((void *) 0, 0, pAED_COMMENT);
		if ( pAED_COMMENT != (char *) 0)
			*((int*)pAED_COMMENT) = _Context->value_AED_COMMENT;
		visual_transferout((void *) 0, 0, pAED_PUNCTUATE);
		if ( pAED_PUNCTUATE != (char *) 0)
			*((int*)pAED_PUNCTUATE) = _Context->value_AED_PUNCTUATE;
		visual_transferout((void *) 0, 0, pAED_FONT);
		if ( pAED_FONT != (char *) 0)
			*((int*)pAED_FONT) = _Context->value_AED_FONT;
		visual_transferout(_Context->buffer_StatusBar, 119, pStatusBar);
		}
	_Context=liberate(_Context);

	return(result);
}
private int on_Dbio_show(struct visual_debug_context * _Context) {
	on_EditorColour_event(_Context);
	WindowEditorLoseFocus();
	visual_freeze();
	visual_frame(64,68,900+2,576+2,5);
visual_text(64+1,68+1,900,576,vfh[1],16,0,_Context->buffer_Dbio,4032,0);
;
	if(WindowEditorOnEvent()==-1){
	Disassembler(_Context->buffer_Dbio,4032,36,112);
	visual_frame(64,68,900+2,576+2,5);
visual_text(64+1,68+1,900,576,vfh[1],16,0,_Context->buffer_Dbio,4032,0);
;
	}
	visual_thaw(64,68,900,576);
	WindowEditorGetFocus();
	on_BreakManager_event(_Context);
	return(-1);
}
private int on_Prio_show(struct visual_debug_context * _Context) {
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
	return(-1);
}
private int on_ErrAdr_show(struct visual_debug_context * _Context) {
	int lerradr;
	lerradr=GetErrAdr();
	sprintf(_Context->buffer_ErrAdr," /%08.8X ",lerradr);
	visual_frame(130,540,88+2,16+2,5);
visual_text(130+1,540+1,88,16,vfh[1],16,31,_Context->buffer_ErrAdr,11,0);
;
	return(-1);
}
private int on_AskMask_show(struct visual_debug_context * _Context) {
	int laskmask;
	laskmask=GetAskMask();
	sprintf(_Context->buffer_AskMask," /%08.8X ",laskmask);
	visual_frame(306,540,88+2,16+2,5);
visual_text(306+1,540+1,88,16,vfh[1],16,31,_Context->buffer_AskMask,11,0);
;
	return(-1);
}
private int on_MouseMask_show(struct visual_debug_context * _Context) {
	int levnmask;
	levnmask=GetEventMask();
	sprintf(_Context->buffer_MouseMask," /%08.8X ",levnmask);
	visual_frame(486,540,88+2,16+2,5);
visual_text(486+1,540+1,88,16,vfh[1],16,31,_Context->buffer_MouseMask,11,0);
;
	return(-1);
}
private int on_ErrorAdr_show(struct visual_debug_context * _Context) {
	int levnmask;
	levnmask=GetErrAdr();
	sprintf(_Context->buffer_ErrorAdr," /%08.8X ",levnmask);
	visual_frame(838,540,88+2,16+2,5);
visual_text(838+1,540+1,88,16,vfh[1],16,31,_Context->buffer_ErrorAdr,11,0);
;
	return(-1);
}
private int on_ErrorVal_show(struct visual_debug_context * _Context) {
	extern int err_val;
	sprintf(_Context->buffer_ErrorVal," %u ",err_val);
	visual_frame(680,540,64+2,16+2,5);
visual_text(680+1,540+1,64,16,vfh[1],16,31,_Context->buffer_ErrorVal,8,0);
;
	return(-1);
}
private int on_vListe_show(struct visual_debug_context * _Context) {
	int l;
	void*DebugPositVariable(int);
	void*firstvariable;
	memset(_Context->buffer_vListe,' ',3876);
	if((firstvariable=DebugPositVariable(_Context->value_vBar))!=(void*)0){
	for(l=1;l<=34;l++){
	if ( l > 0 ) { _Context->row_vListe=&_Context->buffer_vListe[l-1][0]; } ;
	DebugVariableInfo(
	(l-1),firstvariable,
	(_Context->row_vListe+0),9,
	(_Context->row_vListe+9),33,
	(_Context->row_vListe+42),9,
	(_Context->row_vListe+51),63);
	}
	}
		visual_table(32,64,922,566,vfh[1],0,0,_Context->msg_vListe[_Context->language],_Context->buffer_vListe,0x4401,"(W8,W32,W8,$)");
;
	return(-1);
}
private int on_vBar_show(struct visual_debug_context * _Context) {
	_Context->max_vBar=DebugGlobalVariableCount();
		visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
;
	return(-1);
}

public	int	visual_debug_show(struct visual_debug_context * _Context)
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	visual_window(0,0,1014,696,vfh[2],_Context->msg_Main[_Context->language],strlen(_Context->msg_Main[_Context->language]),0x7);
	if (_Context->page_number == 1 ) {
	_Context->trigger_ProgramSource=visual_trigger_code(_Context->msg_ProgramSource[_Context->language],strlen(_Context->msg_ProgramSource[_Context->language]));
	visual_tabpage(20,30,960,630,vfh[2],_Context->msg_ProgramSource[_Context->language],strlen(_Context->msg_ProgramSource[_Context->language]),0,2);
	} else {
		visual_tabpage(20,30,960,630,vfh[2],_Context->msg_ProgramSource[_Context->language],strlen(_Context->msg_ProgramSource[_Context->language]),0,0);
		}
	visual_image(354,28,626,26,DebugImageName(0),4);
	visual_filzone(20,28,960,27,16,1);
	if (_Context->page_number == 1 ) {
	visual_image(22,56,956,602,DebugImageName(0),4);
		}
	if (_Context->page_number == 1 ) {
	visual_filzone(30,68,934,578,7952,1);
		}
	if (_Context->page_number == 1 ) {
	visual_image(30,68,34,578,DebugImageName(0),12);
		}
	if (_Context->page_number == 1 ) {
	visual_filzone(30,68,34,578,16,1);
		}
	if (_Context->page_number == 1 ) {
	visual_image(458,30,24,24,DebugImageName(1),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(482,30,24,24,DebugImageName(2),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(560,30,24,24,DebugImageName(3),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(434,30,24,24,DebugImageName(12),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(506,30,24,24,DebugImageName(5),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(530,30,24,24,DebugImageName(6),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(588,30,24,24,DebugImageName(7),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(618,30,24,24,DebugImageName(8),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(648,30,24,24,DebugImageName(9),1024);
		}
	if (_Context->page_number == 1 ) {
	visual_image(676,30,24,24,DebugImageName(4),1024);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_BreakKey=visual_trigger_code(_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]));
	visual_switch(822,32,48,21,vfh[1],91,15,_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]),_Context->value_BreakKey| 0x0130);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_AsmList=visual_trigger_code(_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]));
	visual_switch(872,32,48,21,vfh[1],91,15,_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]),_Context->value_AsmList| 0x0130);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SaveConfig=visual_trigger_code(_Context->msg_SaveConfig[_Context->language],strlen(_Context->msg_SaveConfig[_Context->language]));
	visual_switch(772,32,48,21,vfh[1],91,15,_Context->msg_SaveConfig[_Context->language],strlen(_Context->msg_SaveConfig[_Context->language]),_Context->value_SaveConfig| 0x0130);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_HexaView=visual_trigger_code(_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]));
	visual_switch(922,32,48,21,vfh[1],91,15,_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]),_Context->value_HexaView| 0x0130);
		}
	if (_Context->page_number == 1 ) {
	(void) on_Dbio_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ProgramOutput=visual_trigger_code(_Context->msg_ProgramOutput[_Context->language],strlen(_Context->msg_ProgramOutput[_Context->language]));
	visual_tabpage(20,30,960,630,vfh[2],_Context->msg_ProgramOutput[_Context->language],strlen(_Context->msg_ProgramOutput[_Context->language]),80,2);
	} else {
		visual_tabpage(20,30,960,630,vfh[2],_Context->msg_ProgramOutput[_Context->language],strlen(_Context->msg_ProgramOutput[_Context->language]),80,0);
		}
	if (_Context->page_number == 2 ) {
	visual_image(22,56,956,602,DebugImageName(0),516);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Prio_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DebugControl=visual_trigger_code(_Context->msg_DebugControl[_Context->language],strlen(_Context->msg_DebugControl[_Context->language]));
	visual_tabpage(20,30,960,630,vfh[2],_Context->msg_DebugControl[_Context->language],strlen(_Context->msg_DebugControl[_Context->language]),159,2);
	} else {
		visual_tabpage(20,30,960,630,vfh[2],_Context->msg_DebugControl[_Context->language],strlen(_Context->msg_DebugControl[_Context->language]),159,0);
		}
	if (_Context->page_number == 3 ) {
	visual_image(22,56,956,602,DebugImageName(0),516);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(30,70,940,580,4);
		}
	if (_Context->page_number == 3 ) {
	(void) on_ErrAdr_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	(void) on_AskMask_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	(void) on_MouseMask_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	(void) on_ErrorAdr_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	(void) on_ErrorVal_show(_Context);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,80,425,22,vfh[4],27,0,_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),770);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,110,240,20,vfh[3],27,0,_Context->msg_Auto3560[_Context->language],strlen(_Context->msg_Auto3560[_Context->language]),258);
		}
	if (_Context->page_number == 3 ) {
	visual_text(512,362,170,20,vfh[3],27,0,_Context->msg_Auto3561[_Context->language],strlen(_Context->msg_Auto3561[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(514,112,170,20,vfh[3],27,0,_Context->msg_Auto3562[_Context->language],strlen(_Context->msg_Auto3562[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(742,112,165,20,vfh[3],27,0,_Context->msg_Auto3563[_Context->language],strlen(_Context->msg_Auto3563[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,310,420,20,vfh[3],27,0,_Context->msg_Auto3564[_Context->language],strlen(_Context->msg_Auto3564[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,260,420,20,vfh[3],27,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(512,312,350,20,vfh[3],27,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(396,486,552,20,vfh[3],27,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),1281);
		}
	if (_Context->page_number == 3 ) {
	visual_text(512,162,350,20,vfh[3],27,0,_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,160,414,20,vfh[3],27,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,210,420,20,vfh[3],27,0,_Context->msg_Auto3570[_Context->language],strlen(_Context->msg_Auto3570[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(512,212,348,20,vfh[3],27,0,_Context->msg_Auto3571[_Context->language],strlen(_Context->msg_Auto3571[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,360,420,20,vfh[3],27,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(512,262,350,20,vfh[3],27,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(194,580,150,16,vfh[2],27,0,_Context->msg_Auto3574[_Context->language],strlen(_Context->msg_Auto3574[_Context->language]),259);
	visual_frame(194,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(346,580,142,16,vfh[2],27,0,_Context->msg_Auto3575[_Context->language],strlen(_Context->msg_Auto3575[_Context->language]),259);
	visual_frame(346,596,142,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,580,150,16,vfh[2],27,0,_Context->msg_Auto3576[_Context->language],strlen(_Context->msg_Auto3576[_Context->language]),259);
	visual_frame(40,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(490,580,150,16,vfh[2],27,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),259);
	visual_frame(490,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(644,580,150,16,vfh[2],27,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),259);
	visual_frame(644,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(798,580,150,16,vfh[2],27,0,_Context->msg_Auto3579[_Context->language],strlen(_Context->msg_Auto3579[_Context->language]),259);
	visual_frame(798,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,130,264,432,vfh[1],0,0,parse_selection(GetProcedureNames(_Context->value_ProcInfo),&_Context->value_ProcName),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ProcEdit=visual_trigger_code(_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]));
	visual_button(306,130,18,19,vfh[8],27,28,_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SegmentEdit=visual_trigger_code(_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]));
	visual_button(918,380,21,19,vfh[8],27,28,_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(330,130,128,80,vfh[1],27,28,parse_selection(_Context->msg_ProcInfo[_Context->language],&_Context->value_ProcInfo),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(510,380,407,191,vfh[1],0,0,parse_selection(GetSegmentNames(),&_Context->value_SegmName),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(512,130,227,441,vfh[1],0,0,parse_selection(GetGlobalNames(),&_Context->value_GlobNames),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(740,130,200,444,vfh[1],0,0,parse_selection(GetLocalNames(),&_Context->value_LocalNames),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,180,400,384,vfh[1],27,0,parse_selection(GetAssignList(),&_Context->value_AssignList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(512,180,429,404,vfh[1],27,0,parse_selection(GetRegisterList(_Context->value_HexaView),&_Context->value_RegisterList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,230,420,350,vfh[1],27,0,parse_selection(GetAttachList(),&_Context->value_AttachList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(512,230,429,351,vfh[1],27,0,parse_selection(GetStackList(),&_Context->value_StackList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,280,420,290,vfh[1],27,0,parse_selection(GetLibraryList(),&_Context->value_LibraryList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(510,280,407,299,vfh[1],27,0,parse_selection(GetObserveList(),&_Context->value_ObserveList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DeleteObservation=visual_trigger_code(_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]));
	visual_button(918,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_RemoveBreak=visual_trigger_code(_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]));
	visual_button(441,330,20,19,vfh[1],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ExportAssign=visual_trigger_code(_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]));
	visual_button(442,180,20,19,vfh[1],40,0,_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(510,330,407,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DeleteWatch=visual_trigger_code(_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]));
	visual_button(918,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,380,400,192,vfh[1],27,0,parse_selection(GetSourceList(),&_Context->value_SourceList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_InspectSource=visual_trigger_code(_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]));
	visual_button(441,380,20,19,vfh[1],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(44,504,904+2,32+2,5);
	visual_text(44+1,504+1,904,32,vfh[1],16,0,_Context->buffer_Syntax,226,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(50,410,675,24,vfh[4],27,0,_Context->msg_Auto3580[_Context->language],strlen(_Context->msg_Auto3580[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(50,440,112,16,vfh[2],27,0,_Context->msg_auto6060[_Context->language],strlen(_Context->msg_auto6060[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(46,540,84,16,vfh[2],27,0,_Context->msg_Auto3581[_Context->language],strlen(_Context->msg_Auto3581[_Context->language]),257);
		}
	if (_Context->page_number == 3 ) {
	visual_text(222,540,84,16,vfh[2],27,0,_Context->msg_Auto3582[_Context->language],strlen(_Context->msg_Auto3582[_Context->language]),257);
		}
	if (_Context->page_number == 3 ) {
	visual_text(400,540,84,16,vfh[2],27,0,_Context->msg_Auto3583[_Context->language],strlen(_Context->msg_Auto3583[_Context->language]),257);
		}
	if (_Context->page_number == 3 ) {
	visual_text(594,540,84,16,vfh[2],27,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),257);
		}
	if (_Context->page_number == 3 ) {
	visual_text(750,540,84,16,vfh[2],27,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),257);
		}
	if (_Context->page_number == 3 ) {
	visual_text(172,440,112,16,vfh[2],27,0,_Context->msg_auto6061[_Context->language],strlen(_Context->msg_auto6061[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(294,440,112,16,vfh[2],27,0,_Context->msg_auto6062[_Context->language],strlen(_Context->msg_auto6062[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(408,440,112,16,vfh[2],27,0,_Context->msg_auto6063[_Context->language],strlen(_Context->msg_auto6063[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(522,440,126,16,vfh[2],27,0,_Context->msg_auto6064[_Context->language],strlen(_Context->msg_auto6064[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(648,440,126,16,vfh[2],27,0,_Context->msg_Auto3586[_Context->language],strlen(_Context->msg_Auto3586[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_select(50,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(172,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(294,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(408,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(522,460,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(644,460,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_EditorColour=visual_trigger_code(_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]));
	visual_button(808,448,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SetBreakAP=visual_trigger_code(_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]));
	visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SetBreakBP=visual_trigger_code(_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]));
	visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SetBreakAS=visual_trigger_code(_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]));
	visual_button(198,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SetFileWatch=visual_trigger_code(_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]));
	visual_button(350,600,56,32,vfh[2],40,0,_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_AllFileWatch=visual_trigger_code(_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]));
	visual_button(409,600,16,32,vfh[8],40,0,_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_RazFileWatch=visual_trigger_code(_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]));
	visual_button(428,600,56,32,vfh[2],40,0,_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SetBreakBS=visual_trigger_code(_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]));
	visual_button(270,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_MultipleWatch=visual_trigger_code(_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]));
	visual_button(494,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SingleWatch=visual_trigger_code(_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]));
	visual_button(566,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ObserveGlobal=visual_trigger_code(_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]));
	visual_button(648,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_InspectGlobal=visual_trigger_code(_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]));
	visual_button(720,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ObserveLocal=visual_trigger_code(_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]));
	visual_button(802,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_InspectLocal=visual_trigger_code(_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]));
	visual_button(874,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_VariableControl=visual_trigger_code(_Context->msg_VariableControl[_Context->language],strlen(_Context->msg_VariableControl[_Context->language]));
	visual_tabpage(20,30,960,630,vfh[2],_Context->msg_VariableControl[_Context->language],strlen(_Context->msg_VariableControl[_Context->language]),240,2);
	} else {
		visual_tabpage(20,30,960,630,vfh[2],_Context->msg_VariableControl[_Context->language],strlen(_Context->msg_VariableControl[_Context->language]),240,0);
		}
	if (_Context->page_number == 4 ) {
	visual_image(22,56,956,602,DebugImageName(0),516);
		}
	if (_Context->page_number == 4 ) {
	(void) on_vListe_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	(void) on_vBar_show(_Context);
		}
	visual_filzone(20,660,960,22,23312,8);
	visual_frame(22,662,954+2,16+2,5);
	visual_text(22+1,662+1,954,16,vfh[1],16,0,_Context->buffer_StatusBar,119,0);
	visual_thaw(0,0,1014,696);

	return(0);
}
private int on_BreakManager_event(struct visual_debug_context * _Context) {
	int i;
	visual_freeze();
		visual_image(30,68,34,578,DebugImageName(0),12);

	if(!(is_idb_active())){
	for(i=0;i<36;i++){
	if(IsBreakPoint(i)){
	_Context->y_BreakPoint=((68)+(i*16));
		visual_image(_Context->x_BreakPoint,_Context->y_BreakPoint,_Context->w_BreakPoint,_Context->h_BreakPoint,DebugImageName(11),1029);

	_Context->y_BreakBar=((68)+(i*16));
	_Context->h_BreakBar=16;
		visual_image(_Context->x_BreakBar,_Context->y_BreakBar,_Context->w_BreakBar,_Context->h_BreakBar,DebugImageName(13),1028);

	}
	if(IsExecutionPoint(i)){
	_Context->y_DebugCursor=((68)+(i*16));
		visual_image(_Context->x_DebugCursor,_Context->y_DebugCursor,_Context->w_DebugCursor,_Context->h_DebugCursor,DebugImageName(14),1024);

	}
	}
	i=editorOnGetFocus();
	}
		visual_filzone(30,68,34,578,16,1);
;
	visual_thaw(30,68,34,578);
	return(-1);
}
private int on_StepInto_event(struct visual_debug_context * _Context) {
	if((_Context->keycode==256)&&(visual_event(1)!=_MIMO_UP)){
	visual_debug_onhint(_Context, _Context->hint_StepInto[_Context->language]);
	}
	else{
	if(_Context->page_number!=1){
		/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
;
		visual_debug_show(_Context);
;
	}
	ExecuteSingleStep();
	on_StatusBar_event(_Context);
	}
	return(-1);
}
private int on_Goto_event(struct visual_debug_context * _Context) {
	if(visual_event(1)!=_MIMO_UP){
	visual_debug_onhint(_Context, _Context->hint_Goto[_Context->language]);
	}
	else{
	if(_Context->page_number==1){
	if(GotoSourceLine()!=0){
	on_Run_event(_Context);
	}
	}
	}
	return(-1);
}
private int on_Run_event(struct visual_debug_context * _Context) {
	if(visual_event(1)!=_MIMO_UP){
	visual_debug_onhint(_Context, _Context->hint_Run[_Context->language]);
	}
	else{
	if(_Context->page_number!=1){
		/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
;
		visual_debug_show(_Context);
;
	}
	WindowEditorLoseFocus();
	ExecuteTillBreak();
		visual_debug_show(_Context);
;
	on_StatusBar_event(_Context);
	WindowEditorGetFocus();
	}
	return(-1);
}
private int on_Restart_event(struct visual_debug_context * _Context) {
	if(visual_event(1)!=_MIMO_UP){
	visual_debug_onhint(_Context, _Context->hint_Restart[_Context->language]);
	}
	else{
	if(visual_debug_confirm(_Context->hint_Restart[_Context->language])!=27){
	strcpy(_Context->buffer_Syntax,"G");
	on_Syntax_event(_Context);
		visual_debug_show(_Context);

	}
	}
	return(-1);
}
private int on_Break_event(struct visual_debug_context * _Context) {
	if(visual_event(1)!=_MIMO_UP){
	visual_debug_onhint(_Context, _Context->hint_Break[_Context->language]);
	}
	else{
	if(_Context->page_number==1){
	SetSourceBreakPoint(1);
	}
	}
	return(-1);
}
private int on_ClearBreak_event(struct visual_debug_context * _Context) {
	if(visual_event(1)!=_MIMO_UP){
	visual_debug_onhint(_Context, _Context->hint_ClearBreak[_Context->language]);
	}
	else{
	if(visual_debug_confirm(_Context->hint_ClearBreak[_Context->language])!=27){
	ClearSourceBreakPoint(1);
	on_Dbio_show(_Context);
	}
	}
	return(-1);
}
private int on_View_event(struct visual_debug_context * _Context) {
	int i;
	if((_Context->keycode==256)
	&&(visual_event(1)!=_MIMO_UP)){
	visual_debug_onhint(_Context, _Context->hint_View[_Context->language]);
	return(-1);
	}
	else if(_Context->page_number==1){
	if(!(_Context->value_HexaView)){
	DebugViewVariable(_Context->buffer_Syntax,226,_Context->value_HexaView);
	}
	else DebugViewMemory();
	}
	return(-1);
}
private int on_Help_event(struct visual_debug_context * _Context) {
	if(visual_event(1)!=_MIMO_UP){
	visual_debug_onhint(_Context, _Context->hint_Help[_Context->language]);
	}
	else{
	system("mozilla file:///home/abal3/doc/en/vexadb.htm");
	}
	return(-1);
}
private int on_Save_event(struct visual_debug_context * _Context) {
	if(visual_event(1)!=_MIMO_UP){
	visual_debug_onhint(_Context, _Context->hint_Save[_Context->language]);
	}
	else{
	if(visual_debug_confirm(_Context->hint_Save[_Context->language])!=27){
	SaveDebugConfiguration();
	}
	}
	return(-1);
}
private int on_Exit_event(struct visual_debug_context * _Context) {
	if((_Context->keycode==256)
	&&(visual_event(1)!=_MIMO_UP)){
	visual_debug_onhint(_Context, _Context->hint_Exit[_Context->language]);
	}
	else if(visual_debug_confirm(_Context->hint_Exit[_Context->language])!=27){
	return(27);
	}
	return(-1);
}
private int on_BreakKey_event(struct visual_debug_context * _Context) {
	if(_Context->value_BreakKey)
	strcpy(_Context->buffer_Syntax,"K/1B");
	else strcpy(_Context->buffer_Syntax,"K/00");
	on_Syntax_event(_Context);
	return(-1);
}
private int on_AsmList_event(struct visual_debug_context * _Context) {
	if(_Context->value_AsmList)
	strcpy(_Context->buffer_Syntax,"LA0");
	else strcpy(_Context->buffer_Syntax,"LA1");
	on_Syntax_event(_Context);
		/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
;
		visual_debug_show(_Context);
;
	return(-1);
}
private int on_SaveConfig_event(struct visual_debug_context * _Context) {
	if(_Context->value_SaveConfig)
	strcpy(_Context->buffer_Syntax,"QCS1");
	else strcpy(_Context->buffer_Syntax,"QCS0");
	on_Syntax_event(_Context);
		visual_debug_show(_Context);
;
	return(-1);
}
private int on_HexaView_event(struct visual_debug_context * _Context) {
		/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
;
	return(-1);
}
private int on_Dbio_event(struct visual_debug_context * _Context) {
		/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
;
	return(-1);
}
private int on_VSB_event(struct visual_debug_context * _Context) {
		visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);
;
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
		return(-1);
}

private int on_VSB_action(struct visual_debug_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (64+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VSB -= 1;
		if (_Context->value_VSB < 0) 
			_Context->value_VSB = 0;
		(void) on_VSB_event(_Context);
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
		return(-1);
		}
	if ( visual_event(6) > (64+560-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VSB += 1;
		if (!(_Context->max_VSB))
			_Context->value_VSB = 0;
		else if ((_Context->max_VSB < _Context->limit_VSB) 
		&& (_Context->value_VSB >= _Context->max_VSB)) 
			_Context->value_VSB = (_Context->max_VSB-1);
		else if (_Context->value_VSB > (_Context->max_VSB-_Context->limit_VSB)) 
			_Context->value_VSB = (_Context->max_VSB-_Context->limit_VSB);
		(void) on_VSB_event(_Context);
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
		return(-1);
		}
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_VSB;
		_Context->value_VSB = (((visual_event(6) - (64+20)) * _Context->max_VSB) / (560 - (2 * 20)));
		if (_Context->value_VSB < 0) 
			_Context->value_VSB = 0;
		else if (_Context->value_VSB > (_Context->max_VSB-_Context->limit_VSB)) 
			_Context->value_VSB = (_Context->max_VSB-_Context->limit_VSB);
		if (_Context->value_VSB != aty) {
		(void) on_VSB_event(_Context);
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_VSB -= (_Context->limit_VSB/2);
			if (_Context->value_VSB < 0) 
				_Context->value_VSB = 0;
		(void) on_VSB_event(_Context);
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_VSB += (_Context->limit_VSB/2);
			if (!(_Context->max_VSB))
				_Context->value_VSB = 0;
			else if ((_Context->max_VSB < _Context->limit_VSB) 
			&& (_Context->value_VSB >= _Context->max_VSB)) 
				_Context->value_VSB = (_Context->max_VSB-1);
			else if (_Context->value_VSB > (_Context->max_VSB-_Context->limit_VSB)) 
				_Context->value_VSB = (_Context->max_VSB-_Context->limit_VSB);
		(void) on_VSB_event(_Context);
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
			break;
		}
	visual_scrollbar(954,64,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);

	return(1);
}
private int on_HSB_event(struct visual_debug_context * _Context) {
		visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);
;
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
	return(-1);
}

private int on_HSB_action(struct visual_debug_context * _Context) {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (30+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HSB -= 1;
		if (_Context->value_HSB < 0) 
			_Context->value_HSB = 0;
		(void) on_HSB_event(_Context);
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
		return(-1);
		}
	if ( visual_event(7) > (30+922-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HSB += 1;
		if (!(_Context->max_HSB))
			_Context->value_HSB = 0;
		else if ((_Context->max_HSB < _Context->limit_HSB) 
		&& (_Context->value_HSB >= _Context->max_HSB)) 
			_Context->value_HSB = (_Context->max_HSB-1);
		else if (_Context->value_HSB > (_Context->max_HSB-_Context->limit_HSB)) 
			_Context->value_HSB = (_Context->max_HSB-_Context->limit_HSB);
		(void) on_HSB_event(_Context);
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
		return(-1);
		}
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		atx = _Context->value_HSB;
		_Context->value_HSB = (((visual_event(7) - (30+20)) * _Context->max_HSB) / (922 - (2 * 20)));
		if (_Context->value_HSB < 0) 
			_Context->value_HSB = 0;
		else if (_Context->value_HSB > (_Context->max_HSB-_Context->limit_HSB)) 
			_Context->value_HSB = (_Context->max_HSB-_Context->limit_HSB);
		if (_Context->value_HSB != atx) {
		(void) on_HSB_event(_Context);
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_HSB -= (_Context->limit_HSB/2);
			if (_Context->value_HSB < 0) 
				_Context->value_HSB = 0;
		(void) on_HSB_event(_Context);
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_HSB += (_Context->limit_HSB/2);
			if (!(_Context->max_HSB))
				_Context->value_HSB = 0;
			else if ((_Context->max_HSB < _Context->limit_HSB) 
			&& (_Context->value_HSB >= _Context->max_HSB)) 
				_Context->value_HSB = (_Context->max_HSB-1);
			else if (_Context->value_HSB > (_Context->max_HSB-_Context->limit_HSB)) 
				_Context->value_HSB = (_Context->max_HSB-_Context->limit_HSB);
		(void) on_HSB_event(_Context);
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
			break;
		}
	visual_scrollbar(30,628,922,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);

	return(1);
}
private int on_ProcEdit_event(struct visual_debug_context * _Context) {
	FreezeEditorShow();
		/* Dbio */
	/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
	visual_debug_show(_Context);
	_Context->focus_item=19;
;
	DebugProcedureEdit(_Context->value_ProcName);
	ThawEditorShow();
	return(-1);
}
private int on_SegmentEdit_event(struct visual_debug_context * _Context) {
		/* Dbio */
	/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
	visual_debug_show(_Context);
	_Context->focus_item=19;
;
	DebugSegmentEdit(_Context->value_SegmName);
	return(-1);
}
private int on_RemoveBreak_event(struct visual_debug_context * _Context) {
	DeleteBreakPoint(_Context->value_BreakList);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_ExportAssign_event(struct visual_debug_context * _Context) {
	ExportAssignTable(GetAssignList(),_Context->buffer_Syntax,226);
	return(-1);
}
private int on_DeleteWatch_event(struct visual_debug_context * _Context) {
	DeleteWatchPoint(_Context->value_WatchList);
		visual_select(510,330,407,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_InspectSource_event(struct visual_debug_context * _Context) {
		/* Dbio */
	/* ProgramSource */
	visual_debug_losefocus(_Context);
	_Context->page_number = 1;
	visual_debug_show(_Context);
	_Context->focus_item=2;
	visual_debug_show(_Context);
	_Context->focus_item=19;
;
	WindowEditorFileNumber(_Context->value_SourceList,0);
	return(-1);
}
private int on_Syntax_event(struct visual_debug_context * _Context) {
	WindowEditorOnExec(_Context->buffer_Syntax,226);
	return(-1);
}
private int on_EditorColour_event(struct visual_debug_context * _Context) {
	editorOnColour(1,_Context->value_AED_NORMAL,_Context->value_AED_QUOTE,_Context->value_AED_KEYWORD,_Context->value_AED_COMMENT,_Context->value_AED_PUNCTUATE);
	editorOnFont(_Context->value_AED_FONT);
	return(-1);
}
private int on_SetBreakAP_event(struct visual_debug_context * _Context) {
	ControlWindowSetBreak(1,1,_Context->value_ProcName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakBP_event(struct visual_debug_context * _Context) {
	ControlWindowSetBreak(1,0,_Context->value_ProcName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakAS_event(struct visual_debug_context * _Context) {
	ControlWindowSetBreak(0,1,_Context->value_SegmName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetFileWatch_event(struct visual_debug_context * _Context) {
	sprintf(_Context->buffer_Syntax,"F=%u",_Context->value_AssignList);
	on_Syntax_event(_Context);
		return(-1);
}
private int on_AllFileWatch_event(struct visual_debug_context * _Context) {
	strcpy(_Context->buffer_Syntax,"F=**");
	on_Syntax_event(_Context);
		return(-1);
}
private int on_RazFileWatch_event(struct visual_debug_context * _Context) {
	strcpy(_Context->buffer_Syntax,"F=0");
	on_Syntax_event(_Context);
	return(-1);
}
private int on_SetBreakBS_event(struct visual_debug_context * _Context) {
	ControlWindowSetBreak(0,0,_Context->value_SegmName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_MultipleWatch_event(struct visual_debug_context * _Context) {
	ControlWindowSetBreak(2,1,_Context->value_GlobNames,0);
		visual_select(510,330,407,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_SingleWatch_event(struct visual_debug_context * _Context) {
	ControlWindowSetBreak(2,0,_Context->value_GlobNames,0);
		visual_select(510,330,407,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_InspectGlobal_event(struct visual_debug_context * _Context) {
	if(DebugShowVariable(_Context->buffer_Syntax,226,_Context->value_GlobNames,0,_Context->value_HexaView)!=0){
	visual_frame(44,504,904+2,32+2,5);
visual_text(44+1,504+1,904,32,vfh[1],16,0,_Context->buffer_Syntax,226,0);
;
	}
	return(-1);
}
private int on_InspectLocal_event(struct visual_debug_context * _Context) {
	if(DebugShowVariable(_Context->buffer_Syntax,226,_Context->value_LocalNames,1,_Context->value_HexaView)!=0){
	visual_frame(44,504,904+2,32+2,5);
visual_text(44+1,504+1,904,32,vfh[1],16,0,_Context->buffer_Syntax,226,0);
;
	}
	return(-1);
}
private int on_vListe_event(struct visual_debug_context * _Context) {
	int l;
	int i;
	l=_Context->value_vListe;
	if(l!=0){
	if ( l > 0 ) { _Context->row_vListe=&_Context->buffer_vListe[l-1][0]; } ;
	DebugDumpZone((_Context->row_vListe+9),33,(_Context->row_vListe+42),9);
	}
	return(-1);
}
private int on_vBar_event(struct visual_debug_context * _Context) {
	on_vListe_show(_Context);
	return(-1);
}

private int on_vBar_action(struct visual_debug_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (64+20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar -= 1;
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		(void) on_vBar_event(_Context);
	visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	if ( visual_event(6) > (64+566-20) ) {
		do { while( stdinput(_Context) != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar += 1;
		if (!(_Context->max_vBar))
			_Context->value_vBar = 0;
		else if ((_Context->max_vBar < _Context->limit_vBar) 
		&& (_Context->value_vBar >= _Context->max_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-1);
		else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		(void) on_vBar_event(_Context);
	visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	do {
		while(stdinput(_Context) != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_vBar;
		_Context->value_vBar = (((visual_event(6) - (64+20)) * _Context->max_vBar) / (566 - (2 * 20)));
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		if (_Context->value_vBar != aty) {
		(void) on_vBar_event(_Context);
	visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_vBar -= (_Context->limit_vBar/2);
			if (_Context->value_vBar < 0) 
				_Context->value_vBar = 0;
		(void) on_vBar_event(_Context);
	visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_vBar += (_Context->limit_vBar/2);
			if (!(_Context->max_vBar))
				_Context->value_vBar = 0;
			else if ((_Context->max_vBar < _Context->limit_vBar) 
			&& (_Context->value_vBar >= _Context->max_vBar)) 
				_Context->value_vBar = (_Context->max_vBar-1);
			else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
				_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		(void) on_vBar_event(_Context);
	visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			break;
		}
	visual_scrollbar(954,64,20,566,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	return(1);
}
private int on_StatusBar_event(struct visual_debug_context * _Context) {
	on_StatusBar_create(_Context);
	visual_frame(22,662,954+2,16+2,5);
visual_text(22+1,662+1,954,16,vfh[1],16,0,_Context->buffer_StatusBar,119,0);
;
	on_Dbio_show(_Context);
	return(-1);
}


public	int	visual_debug_event(
struct visual_debug_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ProgramSource == mb ) return(2);
		if (_Context->trigger_BreakKey == mb ) return(15);
		if (_Context->trigger_AsmList == mb ) return(16);
		if (_Context->trigger_SaveConfig == mb ) return(17);
		if (_Context->trigger_HexaView == mb ) return(18);
		if (_Context->trigger_ProgramOutput == mb ) return(20);
		if (_Context->trigger_DebugControl == mb ) return(23);
		if (_Context->trigger_ProcEdit == mb ) return(30);
		if (_Context->trigger_SegmentEdit == mb ) return(31);
		if (_Context->trigger_DeleteObservation == mb ) return(42);
		if (_Context->trigger_RemoveBreak == mb ) return(44);
		if (_Context->trigger_ExportAssign == mb ) return(45);
		if (_Context->trigger_DeleteWatch == mb ) return(47);
		if (_Context->trigger_InspectSource == mb ) return(49);
		if (_Context->trigger_EditorColour == mb ) return(57);
		if (_Context->trigger_SetBreakAP == mb ) return(58);
		if (_Context->trigger_SetBreakBP == mb ) return(59);
		if (_Context->trigger_SetBreakAS == mb ) return(60);
		if (_Context->trigger_SetFileWatch == mb ) return(61);
		if (_Context->trigger_AllFileWatch == mb ) return(62);
		if (_Context->trigger_RazFileWatch == mb ) return(63);
		if (_Context->trigger_SetBreakBS == mb ) return(64);
		if (_Context->trigger_MultipleWatch == mb ) return(65);
		if (_Context->trigger_SingleWatch == mb ) return(66);
		if (_Context->trigger_ObserveGlobal == mb ) return(67);
		if (_Context->trigger_InspectGlobal == mb ) return(68);
		if (_Context->trigger_ObserveLocal == mb ) return(69);
		if (_Context->trigger_InspectLocal == mb ) return(70);
		if (_Context->trigger_VariableControl == mb ) return(71);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1131)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= 993 )  
	&&  (my >= 4 )  
	&&  (mx <= 1009 )  
	&&  (my <= 20 )) {
		return(1);	/* Main */

		}
	if ((mx >= 977 )  
	&&  (my >= 4 )  
	&&  (mx <= 993 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vexadb.htm");
			};
		return(-1);	/* Main */

		}
	if ((mx >= 961 )  
	&&  (my >= 4 )  
	&&  (mx <= 977 )  
	&&  (my <= 20 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		visual_debug_show(_Context);
		return(-1);	/* Main */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 20 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 99 ) 
		&&  (my <= 54 )) {
			return(2); /* ProgramSource */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 68 ) 
		&&  ( mx <= 64 ) 
		&&  ( my <= 646 )) {
			return(3); /* BreakManager */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 68 ) 
		&&  ( mx <= 64 ) 
		&&  ( my <= 646 )) {
			return(4); /* BreakFrame */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 458 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 482 ) 
		&&  ( my <= 54 )) {
			return(5); /* StepInto */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 482 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 506 ) 
		&&  ( my <= 54 )) {
			return(6); /* Goto */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 560 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 584 ) 
		&&  ( my <= 54 )) {
			return(7); /* Run */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 434 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 458 ) 
		&&  ( my <= 54 )) {
			return(8); /* Restart */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 506 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 530 ) 
		&&  ( my <= 54 )) {
			return(9); /* Break */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 530 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 554 ) 
		&&  ( my <= 54 )) {
			return(10); /* ClearBreak */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 588 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 612 ) 
		&&  ( my <= 54 )) {
			return(11); /* View */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 618 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 642 ) 
		&&  ( my <= 54 )) {
			return(12); /* Help */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 648 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 672 ) 
		&&  ( my <= 54 )) {
			return(13); /* Save */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 676 ) 
		&&  ( my >= 30 ) 
		&&  ( mx <= 700 ) 
		&&  ( my <= 54 )) {
			return(14); /* Exit */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 822 ) 
		&&  ( my >= 32 ) 
		&&  ( mx <= 870 ) 
		&&  ( my <= 53 )) {
			return(15); /* BreakKey */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 872 ) 
		&&  ( my >= 32 ) 
		&&  ( mx <= 920 ) 
		&&  ( my <= 53 )) {
			return(16); /* AsmList */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 772 ) 
		&&  ( my >= 32 ) 
		&&  ( mx <= 820 ) 
		&&  ( my <= 53 )) {
			return(17); /* SaveConfig */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 922 ) 
		&&  ( my >= 32 ) 
		&&  ( mx <= 970 ) 
		&&  ( my <= 53 )) {
			return(18); /* HexaView */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 64 ) 
		&&  ( my >= 68 ) 
		&&  ( mx <= 964 ) 
		&&  ( my <= 644 )) {
			return(19); /* Dbio */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 100 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 178 ) 
		&&  (my <= 54 )) {
			return(20); /* ProgramOutput */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 954 ) 
		&&  ( my >= 64 ) 
		&&  ( mx <= 974 ) 
		&&  ( my <= 624 )) {
			return(21); /* VSB */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 628 ) 
		&&  ( mx <= 952 ) 
		&&  ( my <= 648 )) {
			return(22); /* HSB */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 179 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 259 ) 
		&&  (my <= 54 )) {
			return(23); /* DebugControl */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 130 ) 
		&&  ( my >= 540 ) 
		&&  ( mx <= 218 ) 
		&&  ( my <= 556 )) {
			return(24); /* ErrAdr */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 306 ) 
		&&  ( my >= 540 ) 
		&&  ( mx <= 394 ) 
		&&  ( my <= 556 )) {
			return(25); /* AskMask */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 486 ) 
		&&  ( my >= 540 ) 
		&&  ( mx <= 574 ) 
		&&  ( my <= 556 )) {
			return(26); /* MouseMask */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 838 ) 
		&&  ( my >= 540 ) 
		&&  ( mx <= 926 ) 
		&&  ( my <= 556 )) {
			return(27); /* ErrorAdr */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 680 ) 
		&&  ( my >= 540 ) 
		&&  ( mx <= 744 ) 
		&&  ( my <= 556 )) {
			return(28); /* ErrorVal */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 304 ) 
		&&  (my <= 146 )) {
			return(29); /* ProcName */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 306 ) 
		&&  ( my >= 130 ) 
		&&  ( mx <= 324 ) 
		&&  ( my <= 149 )) {
			return(30); /* ProcEdit */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 918 ) 
		&&  ( my >= 380 ) 
		&&  ( mx <= 939 ) 
		&&  ( my <= 399 )) {
			return(31); /* SegmentEdit */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 330 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 458 ) 
		&&  (my <= 146 )) {
			return(32); /* ProcInfo */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 510 ) 
		&&  (my >= 380 ) 
		&&  (mx <= 917 ) 
		&&  (my <= 396 )) {
			return(33); /* SegmName */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 512 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 739 ) 
		&&  (my <= 146 )) {
			return(34); /* GlobNames */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 740 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 940 ) 
		&&  (my <= 146 )) {
			return(35); /* LocalNames */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 180 ) 
		&&  (mx <= 440 ) 
		&&  (my <= 196 )) {
			return(36); /* AssignList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 512 ) 
		&&  (my >= 180 ) 
		&&  (mx <= 941 ) 
		&&  (my <= 196 )) {
			return(37); /* RegisterList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 230 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 246 )) {
			return(38); /* AttachList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 512 ) 
		&&  (my >= 230 ) 
		&&  (mx <= 941 ) 
		&&  (my <= 246 )) {
			return(39); /* StackList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 296 )) {
			return(40); /* LibraryList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 510 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 917 ) 
		&&  (my <= 296 )) {
			return(41); /* ObserveList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 918 ) 
		&&  ( my >= 280 ) 
		&&  ( mx <= 938 ) 
		&&  ( my <= 299 )) {
			return(42); /* DeleteObservation */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 440 ) 
		&&  (my <= 346 )) {
			return(43); /* BreakList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 441 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 461 ) 
		&&  ( my <= 349 )) {
			return(44); /* RemoveBreak */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 442 ) 
		&&  ( my >= 180 ) 
		&&  ( mx <= 462 ) 
		&&  ( my <= 199 )) {
			return(45); /* ExportAssign */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 510 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 917 ) 
		&&  (my <= 346 )) {
			return(46); /* WatchList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 918 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 938 ) 
		&&  ( my <= 349 )) {
			return(47); /* DeleteWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 380 ) 
		&&  (mx <= 440 ) 
		&&  (my <= 396 )) {
			return(48); /* SourceList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 441 ) 
		&&  ( my >= 380 ) 
		&&  ( mx <= 461 ) 
		&&  ( my <= 399 )) {
			return(49); /* InspectSource */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 44 ) 
		&&  ( my >= 504 ) 
		&&  ( mx <= 948 ) 
		&&  ( my <= 536 )) {
			return(50); /* Syntax */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 50 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 170 ) 
		&&  (my <= 476 )) {
			return(51); /* AED_NORMAL */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 172 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 292 ) 
		&&  (my <= 476 )) {
			return(52); /* AED_QUOTE */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 294 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 406 ) 
		&&  (my <= 476 )) {
			return(53); /* AED_KEYWORD */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 408 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 520 ) 
		&&  (my <= 476 )) {
			return(54); /* AED_COMMENT */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 522 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 642 ) 
		&&  (my <= 476 )) {
			return(55); /* AED_PUNCTUATE */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 644 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 794 ) 
		&&  (my <= 476 )) {
			return(56); /* AED_FONT */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 808 ) 
		&&  ( my >= 448 ) 
		&&  ( mx <= 948 ) 
		&&  ( my <= 480 )) {
			return(57); /* EditorColour */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 44 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 114 ) 
		&&  ( my <= 632 )) {
			return(58); /* SetBreakAP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 116 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 186 ) 
		&&  ( my <= 632 )) {
			return(59); /* SetBreakBP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 198 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 268 ) 
		&&  ( my <= 632 )) {
			return(60); /* SetBreakAS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 350 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 406 ) 
		&&  ( my <= 632 )) {
			return(61); /* SetFileWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 409 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 425 ) 
		&&  ( my <= 632 )) {
			return(62); /* AllFileWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 428 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 484 ) 
		&&  ( my <= 632 )) {
			return(63); /* RazFileWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 270 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 340 ) 
		&&  ( my <= 632 )) {
			return(64); /* SetBreakBS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 494 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 564 ) 
		&&  ( my <= 632 )) {
			return(65); /* MultipleWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 566 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 636 ) 
		&&  ( my <= 632 )) {
			return(66); /* SingleWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 648 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 718 ) 
		&&  ( my <= 632 )) {
			return(67); /* ObserveGlobal */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 720 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 790 ) 
		&&  ( my <= 632 )) {
			return(68); /* InspectGlobal */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 802 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 872 ) 
		&&  ( my <= 632 )) {
			return(69); /* ObserveLocal */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 874 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 944 ) 
		&&  ( my <= 632 )) {
			return(70); /* InspectLocal */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 260 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 354 ) 
		&&  (my <= 54 )) {
			return(71); /* VariableControl */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 32 ) 
		&&  ( my >= 64 ) 
		&&  ( mx <= 954 ) 
		&&  ( my <= 630 )) {
			if ((_Context->value_vListe = ((visual_event(6) - (64)) / 16)) < 1)
				_Context->value_vListe=0;
else if (_Context->value_vListe > 34 )
				_Context->value_vListe=34;
			if ( _Context->value_vListe > 0 ) { _Context->row_vListe = &_Context->buffer_vListe[(_Context->value_vListe-1)][0]; } 
			_Context->column_vListe = (visual_event(7) - (32));
			if ( _Context->column_vListe < 72 ) {
				_Context->column_vListe = 1;
				}
			else if ( _Context->column_vListe < 336 ) {
				_Context->column_vListe = 2;
				}
			else if ( _Context->column_vListe < 408 ) {
				_Context->column_vListe = 3;
				}
			else if ( _Context->column_vListe < 912 ) {
				_Context->column_vListe = 4;
				}
			if ((!(_Context->value_vListe)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_vListe==_Context->column_vListe) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_vListe=-_Context->column_vListe;	/* alors tri décroissant */
				else
					_Context->formsort_vListe=_Context->column_vListe; };	/* sinon tri croissant */
			return(72); /* vListe */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 954 ) 
		&&  ( my >= 64 ) 
		&&  ( mx <= 974 ) 
		&&  ( my <= 630 )) {
			return(73); /* vBar */
			}
		}
	if (( mx >= 20 ) 
	&&  ( my >= 660 ) 
	&&  ( mx <= 980 ) 
	&&  ( my <= 682 )) {
		return(74); /* Auto3588 */
		}
	if (( mx >= 22 ) 
	&&  ( my >= 662 ) 
	&&  ( mx <= 976 ) 
	&&  ( my <= 678 )) {
		return(75); /* StatusBar */
		}

	return(-1);
}
private int on_ProgramSource_losefocus(struct visual_debug_context * _Context) {
	WindowEditorLoseFocus();
	return(-1);
}
private int on_ProgramOutput_losefocus(struct visual_debug_context * _Context) {
	ProgramWindowLoseFocus();
	return(-1);
}
private int on_StatusBar_losefocus(struct visual_debug_context * _Context) {
	int i;
	if(_Context->keycode==13){
	if((_Context->buffer_StatusBar[0]!='D')
	&&(_Context->buffer_StatusBar[0]!='d')){
	WindowEditorOnExec(_Context->buffer_StatusBar,119);
	}
	else{
	DebugVariableSyntax(_Context->buffer_Syntax,226,_Context->buffer_StatusBar,119,_Context->value_HexaView);
	for(i=0;i<119;i++){
	if(i<226)
	_Context->buffer_StatusBar[i]=_Context->buffer_Syntax[i];
	else break;
	}
	visual_frame(22,662,954+2,16+2,5);
visual_text(22+1,662+1,954,16,vfh[1],16,0,_Context->buffer_StatusBar,119,0);
;
	}
	_Context->keycode=0;
	}
	return(-1);
}


public	int	visual_debug_losefocus(struct visual_debug_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			(void) on_ProgramSource_losefocus(_Context);
			break;
		case 2 : 
			(void) on_ProgramOutput_losefocus(_Context);
			break;
		case 3 : 
			break;
		case 4 : 
			break;

		}
	return(0);

}
private int on_ProgramSource_getfocus(struct visual_debug_context * _Context) {
	return(5);
	return(-1);
}
private int on_Dbio_getfocus(struct visual_debug_context * _Context) {
	int event,mx,my;
	while(1){
	CheckBreakPoints(0);
	on_BreakManager_event(_Context);
	event=visual_getch();
	editorOnLoseFocus();
	if(((event>='A')&&(event<='Z'))
	||((event>='a')&&(event<='z'))){
	visual_unget_event(event);
		/* StatusBar */
	visual_debug_show(_Context);
	_Context->focus_item=75;
;
	return(0);
	}
	/*filter out modifiers*/
	/*--------------------*/
	switch(event){
	case 1:/*ctrl A:WORD LEFT*/
	case 2:/*ctrl B:TOGGLE LINE*/
	case 3:/*ctrl C:PAGE DOWN*/
	case 4:/*ctrl D:CHAR RIGHT*/
	case 5:/*ctrl E:LINE UP*/
	case 6:/*ctrl E:WORD RIGHT*/
	break;
	case 7:/*ctrl G:DEL RIGHT*/
	case 8:/*ctrl H:DEL LEFT*/
	continue;
	case 9:/*ctrl I:TAB FIELD*/
	break;
	case 10:/*ctrl J:LINEFEED*/
	case 11:/*ctrl K:Clear EOL*/
	continue;
	case 12:/*ctrl L:Center Page*/
	break;
	case 13:/*ctrl M:CR*/
	case 14:/*ctrl N:cut line*/
	case 15:/*ctrl O:Insert*/
	continue;
	case 0x010:/*ctrl P:TOGGLE PAGE*/
	break;
	case 0x011:/*ctrl Q:Clear SOL*/
	case 0x012:/*ctrl R:Page UP*/
	break;
	case 0x013:/*ctrl S:Clear SOL*/
	case 0x014:/*ctrl T:Trace*/
	case 0x015:/*ctrl U:Clear SOL*/
	case 0x016:/*ctrl V:Indenting*/
	case 0x017:/*ctrl W:Clipboard*/
	case 0x018:/*ctrl X:Line Up*/
	break;
	case 0x019:/*ctrl Y:Delete Line*/
	continue;
	case 0x01A:/*ctrl Z:Zoom*/
	on_View_event(_Context);
	continue;
	case 0x020:/*space:step*/
	_Context->keycode=event;
	on_StepInto_event(_Context);
	continue;
	}
	if((event==27)||(event&_MIMO_ALT)||(event==9))
	break;
	else if(event==256){
	if(((mx=visual_event(7))>64)
	&&((my=visual_event(6))>68)
	&&(mx<(64+900))
	&&(my<(68+576))){
	if(visual_event(2)==1)
	editorOnUseEvent(event);
	else if(visual_event(1)==_MIMO_DOWN)
	on_View_event(_Context);
	}
	else break;
	}
	else if(event<26){
	if(editorOnUseEvent(event))
	break;
	}
	}
	return(event);
	return(-1);
}


public	int	visual_debug_focus(struct visual_debug_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) stdinput(_Context);

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ProgramSource */
				if (_Context->page_number == 1 ) {
					_Context->keycode = on_ProgramSource_getfocus(_Context);
					(void) on_ProgramSource_losefocus(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x13 :
				/* Dbio */
				if (_Context->page_number == 1 ) {
					_Context->keycode = on_Dbio_getfocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* ProgramOutput */
				if (_Context->page_number == 2 ) {
					_Context->keycode=stdinput(_Context);
					(void) on_ProgramOutput_losefocus(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x15 :
				/* VSB */
				if (_Context->page_number == 2 ) {
					_Context->keycode=stdinput(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x16 :
				/* HSB */
				if (_Context->page_number == 2 ) {
					_Context->keycode=stdinput(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x17 :
				/* DebugControl */
				if (_Context->page_number == 3 ) {
					_Context->keycode=stdinput(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1d :
				/* ProcName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,130,264,432,vfh[1],0,0,parse_selection(GetProcedureNames(_Context->value_ProcInfo),&_Context->value_ProcName),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* ProcEdit */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ProcEdit=visual_trigger_code(_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]));
					visual_button(306,130,18,19,vfh[8],27,28,_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_ProcEdit=visual_trigger_code(_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]));
	visual_button(306,130,18,19,vfh[8],27,28,_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* SegmentEdit */
				if (_Context->page_number == 3 ) {
					_Context->trigger_SegmentEdit=visual_trigger_code(_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]));
					visual_button(918,380,21,19,vfh[8],27,28,_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_SegmentEdit=visual_trigger_code(_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]));
	visual_button(918,380,21,19,vfh[8],27,28,_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* ProcInfo */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(330,130,128,80,vfh[1],27,28,parse_selection(_Context->msg_ProcInfo[_Context->language],&_Context->value_ProcInfo),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* SegmName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(510,380,407,191,vfh[1],0,0,parse_selection(GetSegmentNames(),&_Context->value_SegmName),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* GlobNames */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(512,130,227,441,vfh[1],0,0,parse_selection(GetGlobalNames(),&_Context->value_GlobNames),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* LocalNames */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(740,130,200,444,vfh[1],0,0,parse_selection(GetLocalNames(),&_Context->value_LocalNames),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* AssignList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,180,400,384,vfh[1],27,0,parse_selection(GetAssignList(),&_Context->value_AssignList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* RegisterList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(512,180,429,404,vfh[1],27,0,parse_selection(GetRegisterList(_Context->value_HexaView),&_Context->value_RegisterList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* AttachList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,230,420,350,vfh[1],27,0,parse_selection(GetAttachList(),&_Context->value_AttachList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* StackList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(512,230,429,351,vfh[1],27,0,parse_selection(GetStackList(),&_Context->value_StackList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* LibraryList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,280,420,290,vfh[1],27,0,parse_selection(GetLibraryList(),&_Context->value_LibraryList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* ObserveList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(510,280,407,299,vfh[1],27,0,parse_selection(GetObserveList(),&_Context->value_ObserveList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* DeleteObservation */
				if (_Context->page_number == 3 ) {
					_Context->trigger_DeleteObservation=visual_trigger_code(_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]));
					visual_button(918,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_DeleteObservation=visual_trigger_code(_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]));
	visual_button(918,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* BreakList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* RemoveBreak */
				if (_Context->page_number == 3 ) {
					_Context->trigger_RemoveBreak=visual_trigger_code(_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]));
					visual_button(441,330,20,19,vfh[1],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_RemoveBreak=visual_trigger_code(_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]));
	visual_button(441,330,20,19,vfh[1],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* ExportAssign */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ExportAssign=visual_trigger_code(_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]));
					visual_button(442,180,20,19,vfh[1],40,0,_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_ExportAssign=visual_trigger_code(_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]));
	visual_button(442,180,20,19,vfh[1],40,0,_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* WatchList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(510,330,407,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* DeleteWatch */
				if (_Context->page_number == 3 ) {
					_Context->trigger_DeleteWatch=visual_trigger_code(_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]));
					visual_button(918,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_DeleteWatch=visual_trigger_code(_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]));
	visual_button(918,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* SourceList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,380,400,192,vfh[1],27,0,parse_selection(GetSourceList(),&_Context->value_SourceList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* InspectSource */
				if (_Context->page_number == 3 ) {
					_Context->trigger_InspectSource=visual_trigger_code(_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]));
					visual_button(441,380,20,19,vfh[1],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_InspectSource=visual_trigger_code(_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]));
	visual_button(441,380,20,19,vfh[1],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* Syntax */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(44+1,504+1,904,32,vfh[1],_Context->buffer_Syntax,226);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* AED_NORMAL */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(50,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* AED_QUOTE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(172,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* AED_KEYWORD */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(294,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* AED_COMMENT */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(408,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x37 :
				/* AED_PUNCTUATE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(522,460,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x38 :
				/* AED_FONT */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(644,460,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x39 :
				/* EditorColour */
				if (_Context->page_number == 3 ) {
					_Context->trigger_EditorColour=visual_trigger_code(_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]));
					visual_button(808,448,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_EditorColour=visual_trigger_code(_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]));
	visual_button(808,448,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3a :
				/* SetBreakAP */
				if (_Context->page_number == 3 ) {
					_Context->trigger_SetBreakAP=visual_trigger_code(_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]));
					visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_SetBreakAP=visual_trigger_code(_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]));
	visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3b :
				/* SetBreakBP */
				if (_Context->page_number == 3 ) {
					_Context->trigger_SetBreakBP=visual_trigger_code(_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]));
					visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_SetBreakBP=visual_trigger_code(_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]));
	visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3c :
				/* SetBreakAS */
				if (_Context->page_number == 3 ) {
					_Context->trigger_SetBreakAS=visual_trigger_code(_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]));
					visual_button(198,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_SetBreakAS=visual_trigger_code(_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]));
	visual_button(198,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3d :
				/* SetFileWatch */
				if (_Context->page_number == 3 ) {
					_Context->trigger_SetFileWatch=visual_trigger_code(_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]));
					visual_button(350,600,56,32,vfh[2],40,0,_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_SetFileWatch=visual_trigger_code(_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]));
	visual_button(350,600,56,32,vfh[2],40,0,_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3e :
				/* AllFileWatch */
				if (_Context->page_number == 3 ) {
					_Context->trigger_AllFileWatch=visual_trigger_code(_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]));
					visual_button(409,600,16,32,vfh[8],40,0,_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_AllFileWatch=visual_trigger_code(_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]));
	visual_button(409,600,16,32,vfh[8],40,0,_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3f :
				/* RazFileWatch */
				if (_Context->page_number == 3 ) {
					_Context->trigger_RazFileWatch=visual_trigger_code(_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]));
					visual_button(428,600,56,32,vfh[2],40,0,_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_RazFileWatch=visual_trigger_code(_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]));
	visual_button(428,600,56,32,vfh[2],40,0,_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x40 :
				/* SetBreakBS */
				if (_Context->page_number == 3 ) {
					_Context->trigger_SetBreakBS=visual_trigger_code(_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]));
					visual_button(270,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_SetBreakBS=visual_trigger_code(_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]));
	visual_button(270,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x41 :
				/* MultipleWatch */
				if (_Context->page_number == 3 ) {
					_Context->trigger_MultipleWatch=visual_trigger_code(_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]));
					visual_button(494,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_MultipleWatch=visual_trigger_code(_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]));
	visual_button(494,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x42 :
				/* SingleWatch */
				if (_Context->page_number == 3 ) {
					_Context->trigger_SingleWatch=visual_trigger_code(_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]));
					visual_button(566,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_SingleWatch=visual_trigger_code(_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]));
	visual_button(566,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x43 :
				/* ObserveGlobal */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ObserveGlobal=visual_trigger_code(_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]));
					visual_button(648,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_ObserveGlobal=visual_trigger_code(_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]));
	visual_button(648,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x44 :
				/* InspectGlobal */
				if (_Context->page_number == 3 ) {
					_Context->trigger_InspectGlobal=visual_trigger_code(_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]));
					visual_button(720,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_InspectGlobal=visual_trigger_code(_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]));
	visual_button(720,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x45 :
				/* ObserveLocal */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ObserveLocal=visual_trigger_code(_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]));
					visual_button(802,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_ObserveLocal=visual_trigger_code(_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]));
	visual_button(802,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x46 :
				/* InspectLocal */
				if (_Context->page_number == 3 ) {
					_Context->trigger_InspectLocal=visual_trigger_code(_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]));
					visual_button(874,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),2);
					_Context->keycode = stdinput(_Context);
					_Context->trigger_InspectLocal=visual_trigger_code(_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]));
	visual_button(874,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x47 :
				/* VariableControl */
				if (_Context->page_number == 4 ) {
					_Context->keycode=stdinput(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x49 :
				/* vBar */
				if (_Context->page_number == 4 ) {
					_Context->keycode=stdinput(_Context);
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x4b :
				/* StatusBar */
				_Context->keycode = visual_edit(22+1,662+1,954,16,vfh[1],_Context->buffer_StatusBar,119);
				(void) on_StatusBar_losefocus(_Context);
			break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			visual_debug_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			visual_debug_show(_Context);
			continue;
		case	0x2 :
			visual_debug_losefocus(_Context);
			_Context->page_number=4;
			_Context->focus_item=75;
			visual_debug_show(_Context);
			continue;
		case	0x3 :
			visual_debug_losefocus(_Context);
			if ( _Context->page_number < 4 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_debug_show(_Context);
			continue;
		case	0x12 :
			visual_debug_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_debug_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=visual_debug_event(_Context)) == -1)
				continue;
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Main */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* ProgramSource */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_debug_losefocus(_Context);
						_Context->page_number = 1;
						visual_debug_show(_Context);
						}
					continue;
				case	0x3 :
					/* BreakManager */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_BreakManager_event(_Context)) != -1) break;

						}
					continue;
				case	0x4 :
					/* BreakFrame */
					continue;
				case	0x5 :
					/* StepInto */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_StepInto_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* Goto */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Goto_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* Run */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Run_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* Restart */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Restart_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* Break */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Break_event(_Context)) != -1) break;

						}
					continue;
				case	0xa :
					/* ClearBreak */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_ClearBreak_event(_Context)) != -1) break;

						}
					continue;
				case	0xb :
					/* View */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_View_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* Help */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Help_event(_Context)) != -1) break;

						}
					continue;
				case	0xd :
					/* Save */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Save_event(_Context)) != -1) break;

						}
					continue;
				case	0xe :
					/* Exit */
					if ( visual_event(1) &  0x130 ) {
					if ((_Context->keycode = on_Exit_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* BreakKey */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_BreakKey += 1;
						_Context->value_BreakKey &= 1;
						_Context->trigger_BreakKey=visual_trigger_code(_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]));
	visual_switch(822,32,48,21,vfh[1],91,15,_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]),_Context->value_BreakKey| 0x0130);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_BreakKey_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* AsmList */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_AsmList += 1;
						_Context->value_AsmList &= 1;
						_Context->trigger_AsmList=visual_trigger_code(_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]));
	visual_switch(872,32,48,21,vfh[1],91,15,_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]),_Context->value_AsmList| 0x0130);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_AsmList_event(_Context)) != -1) break;

						}
					continue;
				case	0x11 :
					/* SaveConfig */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SaveConfig += 1;
						_Context->value_SaveConfig &= 1;
						_Context->trigger_SaveConfig=visual_trigger_code(_Context->msg_SaveConfig[_Context->language],strlen(_Context->msg_SaveConfig[_Context->language]));
	visual_switch(772,32,48,21,vfh[1],91,15,_Context->msg_SaveConfig[_Context->language],strlen(_Context->msg_SaveConfig[_Context->language]),_Context->value_SaveConfig| 0x0130);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SaveConfig_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* HexaView */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_HexaView += 1;
						_Context->value_HexaView &= 1;
						_Context->trigger_HexaView=visual_trigger_code(_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]));
	visual_switch(922,32,48,21,vfh[1],91,15,_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]),_Context->value_HexaView| 0x0130);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_HexaView_event(_Context)) != -1) break;

						}
					continue;
				case	0x13 :
					/* Dbio */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Dbio_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* ProgramOutput */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_debug_losefocus(_Context);
						_Context->page_number = 2;
						visual_debug_show(_Context);
						}
					continue;
				case	0x15 :
					/* VSB */
					(void) on_VSB_action(_Context);
					continue;
				case	0x16 :
					/* HSB */
					(void) on_HSB_action(_Context);
					continue;
				case	0x17 :
					/* DebugControl */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_debug_losefocus(_Context);
						_Context->page_number = 3;
						visual_debug_show(_Context);
						}
					continue;
				case	0x18 :
					/* ErrAdr */
					continue;
				case	0x19 :
					/* AskMask */
					continue;
				case	0x1a :
					/* MouseMask */
					continue;
				case	0x1b :
					/* ErrorAdr */
					continue;
				case	0x1c :
					/* ErrorVal */
					continue;
				case	0x1d :
					/* ProcName */
					continue;
				case	0x1e :
					/* ProcEdit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ProcEdit=visual_trigger_code(_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]));
						visual_button(306,130,18,19,vfh[8],27,28,_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ProcEdit=visual_trigger_code(_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]));
	visual_button(306,130,18,19,vfh[8],27,28,_Context->msg_ProcEdit[_Context->language],strlen(_Context->msg_ProcEdit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ProcEdit_event(_Context)) != -1) break;

						}
					continue;
				case	0x1f :
					/* SegmentEdit */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SegmentEdit=visual_trigger_code(_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]));
						visual_button(918,380,21,19,vfh[8],27,28,_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SegmentEdit=visual_trigger_code(_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]));
	visual_button(918,380,21,19,vfh[8],27,28,_Context->msg_SegmentEdit[_Context->language],strlen(_Context->msg_SegmentEdit[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SegmentEdit_event(_Context)) != -1) break;

						}
					continue;
				case	0x20 :
					/* ProcInfo */
					continue;
				case	0x21 :
					/* SegmName */
					continue;
				case	0x22 :
					/* GlobNames */
					continue;
				case	0x23 :
					/* LocalNames */
					continue;
				case	0x24 :
					/* AssignList */
					continue;
				case	0x25 :
					/* RegisterList */
					continue;
				case	0x26 :
					/* AttachList */
					continue;
				case	0x27 :
					/* StackList */
					continue;
				case	0x28 :
					/* LibraryList */
					continue;
				case	0x29 :
					/* ObserveList */
					continue;
				case	0x2a :
					/* DeleteObservation */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DeleteObservation=visual_trigger_code(_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]));
						visual_button(918,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DeleteObservation=visual_trigger_code(_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]));
	visual_button(918,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),0);
						}
					continue;
				case	0x2b :
					/* BreakList */
					continue;
				case	0x2c :
					/* RemoveBreak */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_RemoveBreak=visual_trigger_code(_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]));
						visual_button(441,330,20,19,vfh[1],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_RemoveBreak=visual_trigger_code(_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]));
	visual_button(441,330,20,19,vfh[1],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_RemoveBreak_event(_Context)) != -1) break;

						}
					continue;
				case	0x2d :
					/* ExportAssign */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ExportAssign=visual_trigger_code(_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]));
						visual_button(442,180,20,19,vfh[1],40,0,_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ExportAssign=visual_trigger_code(_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]));
	visual_button(442,180,20,19,vfh[1],40,0,_Context->msg_ExportAssign[_Context->language],strlen(_Context->msg_ExportAssign[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ExportAssign_event(_Context)) != -1) break;

						}
					continue;
				case	0x2e :
					/* WatchList */
					continue;
				case	0x2f :
					/* DeleteWatch */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DeleteWatch=visual_trigger_code(_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]));
						visual_button(918,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DeleteWatch=visual_trigger_code(_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]));
	visual_button(918,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DeleteWatch_event(_Context)) != -1) break;

						}
					continue;
				case	0x30 :
					/* SourceList */
					continue;
				case	0x31 :
					/* InspectSource */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_InspectSource=visual_trigger_code(_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]));
						visual_button(441,380,20,19,vfh[1],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_InspectSource=visual_trigger_code(_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]));
	visual_button(441,380,20,19,vfh[1],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_InspectSource_event(_Context)) != -1) break;

						}
					continue;
				case	0x32 :
					/* Syntax */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Syntax_event(_Context)) != -1) break;

						}
					continue;
				case	0x33 :
					/* AED_NORMAL */
					continue;
				case	0x34 :
					/* AED_QUOTE */
					continue;
				case	0x35 :
					/* AED_KEYWORD */
					continue;
				case	0x36 :
					/* AED_COMMENT */
					continue;
				case	0x37 :
					/* AED_PUNCTUATE */
					continue;
				case	0x38 :
					/* AED_FONT */
					continue;
				case	0x39 :
					/* EditorColour */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditorColour=visual_trigger_code(_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]));
						visual_button(808,448,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditorColour=visual_trigger_code(_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]));
	visual_button(808,448,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditorColour_event(_Context)) != -1) break;

						}
					continue;
				case	0x3a :
					/* SetBreakAP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SetBreakAP=visual_trigger_code(_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]));
						visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SetBreakAP=visual_trigger_code(_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]));
	visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SetBreakAP_event(_Context)) != -1) break;

						}
					continue;
				case	0x3b :
					/* SetBreakBP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SetBreakBP=visual_trigger_code(_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]));
						visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SetBreakBP=visual_trigger_code(_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]));
	visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SetBreakBP_event(_Context)) != -1) break;

						}
					continue;
				case	0x3c :
					/* SetBreakAS */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SetBreakAS=visual_trigger_code(_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]));
						visual_button(198,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SetBreakAS=visual_trigger_code(_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]));
	visual_button(198,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SetBreakAS_event(_Context)) != -1) break;

						}
					continue;
				case	0x3d :
					/* SetFileWatch */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SetFileWatch=visual_trigger_code(_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]));
						visual_button(350,600,56,32,vfh[2],40,0,_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SetFileWatch=visual_trigger_code(_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]));
	visual_button(350,600,56,32,vfh[2],40,0,_Context->msg_SetFileWatch[_Context->language],strlen(_Context->msg_SetFileWatch[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SetFileWatch_event(_Context)) != -1) break;

						}
					continue;
				case	0x3e :
					/* AllFileWatch */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_AllFileWatch=visual_trigger_code(_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]));
						visual_button(409,600,16,32,vfh[8],40,0,_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_AllFileWatch=visual_trigger_code(_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]));
	visual_button(409,600,16,32,vfh[8],40,0,_Context->msg_AllFileWatch[_Context->language],strlen(_Context->msg_AllFileWatch[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_AllFileWatch_event(_Context)) != -1) break;

						}
					continue;
				case	0x3f :
					/* RazFileWatch */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_RazFileWatch=visual_trigger_code(_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]));
						visual_button(428,600,56,32,vfh[2],40,0,_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_RazFileWatch=visual_trigger_code(_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]));
	visual_button(428,600,56,32,vfh[2],40,0,_Context->msg_RazFileWatch[_Context->language],strlen(_Context->msg_RazFileWatch[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_RazFileWatch_event(_Context)) != -1) break;

						}
					continue;
				case	0x40 :
					/* SetBreakBS */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SetBreakBS=visual_trigger_code(_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]));
						visual_button(270,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SetBreakBS=visual_trigger_code(_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]));
	visual_button(270,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SetBreakBS_event(_Context)) != -1) break;

						}
					continue;
				case	0x41 :
					/* MultipleWatch */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_MultipleWatch=visual_trigger_code(_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]));
						visual_button(494,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_MultipleWatch=visual_trigger_code(_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]));
	visual_button(494,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_MultipleWatch_event(_Context)) != -1) break;

						}
					continue;
				case	0x42 :
					/* SingleWatch */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SingleWatch=visual_trigger_code(_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]));
						visual_button(566,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SingleWatch=visual_trigger_code(_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]));
	visual_button(566,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SingleWatch_event(_Context)) != -1) break;

						}
					continue;
				case	0x43 :
					/* ObserveGlobal */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ObserveGlobal=visual_trigger_code(_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]));
						visual_button(648,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ObserveGlobal=visual_trigger_code(_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]));
	visual_button(648,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),0);
						}
					continue;
				case	0x44 :
					/* InspectGlobal */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_InspectGlobal=visual_trigger_code(_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]));
						visual_button(720,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_InspectGlobal=visual_trigger_code(_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]));
	visual_button(720,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_InspectGlobal_event(_Context)) != -1) break;

						}
					continue;
				case	0x45 :
					/* ObserveLocal */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ObserveLocal=visual_trigger_code(_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]));
						visual_button(802,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ObserveLocal=visual_trigger_code(_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]));
	visual_button(802,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),0);
						}
					continue;
				case	0x46 :
					/* InspectLocal */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_InspectLocal=visual_trigger_code(_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]));
						visual_button(874,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_InspectLocal=visual_trigger_code(_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]));
	visual_button(874,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_InspectLocal_event(_Context)) != -1) break;

						}
					continue;
				case	0x47 :
					/* VariableControl */
					if (visual_event(1) & _MIMO_DOWN) {
						visual_debug_losefocus(_Context);
						_Context->page_number = 4;
						visual_debug_show(_Context);
						}
					continue;
				case	0x48 :
					/* vListe */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_vListe_event(_Context)) != -1) break;

						}
					continue;
				case	0x49 :
					/* vBar */
					(void) on_vBar_action(_Context);
					continue;
				case	0x4a :
					/* Auto3588 */
					continue;
				case	0x4b :
					/* StatusBar */
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_StatusBar_event(_Context)) != -1) break;

						}
					continue;
				case	0xffffffff :
				default :
					_Context->focus_item=1;
				continue;
				}
				break;
		case	0x1b :
			if(on_Exit_event(_Context)!=27)
			continue;
						break;
		case	0xd :
			continue;
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
				_Context->focus_item=75;
			}
			continue;
		default :
			continue;

			}
		break;
		}


	while( visual_kbhit() ) (void) stdinput(_Context);
	return(0);

}

public	int	visual_debug(
	char * pBreakKey,
	char * pAsmList,
	char * pSaveConfig,
	char * pHexaView,
	char * pDbio,
	char * pPrio,
	char * pProcName,
	char * pProcInfo,
	char * pSegmName,
	char * pGlobNames,
	char * pLocalNames,
	char * pAssignList,
	char * pRegisterList,
	char * pAttachList,
	char * pStackList,
	char * pLibraryList,
	char * pObserveList,
	char * pBreakList,
	char * pWatchList,
	char * pSourceList,
	char * pSyntax,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAED_FONT,
	char * pStatusBar)
{
	int	status=0;
	struct visual_debug_context * _Context=(struct visual_debug_context*) 0;
	status = visual_debug_create(
	&_Context,
	 pBreakKey,
	 pAsmList,
	 pSaveConfig,
	 pHexaView,
	 pDbio,
	 pPrio,
	 pProcName,
	 pProcInfo,
	 pSegmName,
	 pGlobNames,
	 pLocalNames,
	 pAssignList,
	 pRegisterList,
	 pAttachList,
	 pStackList,
	 pLibraryList,
	 pObserveList,
	 pBreakList,
	 pWatchList,
	 pSourceList,
	 pSyntax,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pAED_FONT,
	 pStatusBar);
	if ( status != 0) return(status);
	status = visual_debug_show(_Context);
		enter_modal();
	status = visual_debug_focus(_Context);
		leave_modal();
	status = visual_debug_hide(_Context);
	status = visual_debug_remove(
	_Context,
	 pBreakKey,
	 pAsmList,
	 pSaveConfig,
	 pHexaView,
	 pDbio,
	 pPrio,
	 pProcName,
	 pProcInfo,
	 pSegmName,
	 pGlobNames,
	 pLocalNames,
	 pAssignList,
	 pRegisterList,
	 pAttachList,
	 pStackList,
	 pLibraryList,
	 pObserveList,
	 pBreakList,
	 pWatchList,
	 pSourceList,
	 pSyntax,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pAED_FONT,
	 pStatusBar);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vexadb_c */
