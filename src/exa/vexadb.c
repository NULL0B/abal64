
#ifndef _vexadb_c
#define _vexadb_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.31  */
/* Production     : C  */
/* Project        : vexadb.xml  */
/* Target         : vexadb.c  */
/* Identification : 0.0-1088513023-4937.4936 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#define en_Main   "Exadb : Version 3.1a.0.01"
#define en_ProgramSource   "Program &Source"
#define fr_ProgramSource   "&Source Program"
#define it_ProgramSource   "Program &Source"
#define es_ProgramSource   "Program &Source"
#define de_ProgramSource   "Program &Source"
#define nl_ProgramSource   "Program &Source"
#define pt_ProgramSource   "Program &Source"
#define xx_ProgramSource   "Program &Source"
#define en_Auto4724   "brail.gif"
#define en_BreakManager   ""
#define fr_BreakManager   ""
#define en_DebugCursor   "debug.gif"
#define en_BreakPoint   "break.gif"
#define en_Exit   "exit.gif"
#define fr_Exit   "exit.gif"
#define it_Exit   "exit.gif"
#define es_Exit   "exit.gif"
#define de_Exit   "exit.gif"
#define nl_Exit   "exit.gif"
#define pt_Exit   "exit.gif"
#define xx_Exit   "exit.gif"
#define en_StepInto   "step.gif"
#define fr_StepInto   "step.gif"
#define it_StepInto   "step.gif"
#define es_StepInto   "step.gif"
#define de_StepInto   "step.gif"
#define nl_StepInto   "step.gif"
#define pt_StepInto   "step.gif"
#define xx_StepInto   "step.gif"
#define en_Goto   "goto.gif"
#define fr_Goto   "goto.gif"
#define it_Goto   "goto.gif"
#define es_Goto   "goto.gif"
#define de_Goto   "goto.gif"
#define nl_Goto   "goto.gif"
#define pt_Goto   "goto.gif"
#define xx_Goto   "goto.gif"
#define en_Break   "trap.gif"
#define fr_Break   "trap.gif"
#define it_Break   "trap.gif"
#define es_Break   "trap.gif"
#define de_Break   "trap.gif"
#define nl_Break   "trap.gif"
#define pt_Break   "trap.gif"
#define xx_Break   "trap.gif"
#define en_ClearBreak   "clear.gif"
#define fr_ClearBreak   "clear.gif"
#define it_ClearBreak   "clear.gif"
#define es_ClearBreak   "clear.gif"
#define de_ClearBreak   "clear.gif"
#define nl_ClearBreak   "clear.gif"
#define pt_ClearBreak   "clear.gif"
#define xx_ClearBreak   "clear.gif"
#define en_Run   "run.gif"
#define fr_Run   "run.gif"
#define it_Run   "run.gif"
#define es_Run   "run.gif"
#define de_Run   "run.gif"
#define nl_Run   "run.gif"
#define pt_Run   "run.gif"
#define xx_Run   "run.gif"
#define en_View   "view.gif"
#define fr_View   "view.gif"
#define it_View   "view.gif"
#define es_View   "view.gif"
#define de_View   "view.gif"
#define nl_View   "view.gif"
#define pt_View   "view.gif"
#define xx_View   "view.gif"
#define en_Dbio   ""
#define en_ProgramOutput   "Program &Output"
#define fr_ProgramOutput   "S&ortie Program"
#define it_ProgramOutput   "Program &Output"
#define es_ProgramOutput   "Program &Output"
#define de_ProgramOutput   "Program &Output"
#define nl_ProgramOutput   "Program &Output"
#define pt_ProgramOutput   "Program &Output"
#define xx_ProgramOutput   "Program &Output"
#define en_Auto4725   "brail.gif"
#define en_DebugControl   "&Debug Control"
#define fr_DebugControl   "Contr“le &Debug"
#define it_DebugControl   "&Debug Control"
#define es_DebugControl   "&Debug Control"
#define de_DebugControl   "&Debug Control"
#define nl_DebugControl   "&Debug Control"
#define pt_DebugControl   "&Debug Control"
#define xx_DebugControl   "&Debug Control"
#define en_Auto1955   "ABAL++ Debug : Command and Control"
#define fr_Auto1955   "ABAL++ Debug : Contr“le et Commandes"
#define it_Auto1955   "ABAL++ Debug : Command and Control"
#define es_Auto1955   "ABAL++ Debug : Command and Control"
#define de_Auto1955   "ABAL++ Debug : Command and Control"
#define nl_Auto1955   "ABAL++ Debug : Command and Control"
#define pt_Auto1955   "ABAL++ Debug : Command and Control"
#define xx_Auto1955   "ABAL++ Debug : Command and Control"
#define en_Auto6301   "Procedures"
#define fr_Auto6301   "Procedures"
#define it_Auto6301   "Procedures"
#define es_Auto6301   "Procedures"
#define de_Auto6301   "Procedures"
#define nl_Auto6301   "Procedures"
#define pt_Auto6301   "Procedures"
#define xx_Auto6301   "Procedures"
#define en_Auto6303   "Segments"
#define fr_Auto6303   "Segments"
#define it_Auto6303   "Segments"
#define es_Auto6303   "Segments"
#define de_Auto6303   "Segments"
#define nl_Auto6303   "Segments"
#define pt_Auto6303   "Segments"
#define xx_Auto6303   "Segments"
#define en_Auto6305   "Global Variables"
#define fr_Auto6305   "Variables Globales"
#define it_Auto6305   "Global Variables"
#define es_Auto6305   "Global Variables"
#define de_Auto6305   "Global Variables"
#define nl_Auto6305   "Global Variables"
#define pt_Auto6305   "Global Variables"
#define xx_Auto6305   "Global Variables"
#define en_Auto6307   "Local Variables"
#define fr_Auto6307   "Variables Locales"
#define it_Auto6307   "Local Variables"
#define es_Auto6307   "Local Variables"
#define de_Auto6307   "Local Variables"
#define nl_Auto6307   "Local Variables"
#define pt_Auto6307   "Local Variables"
#define xx_Auto6307   "Local Variables"
#define en_Auto6309   "Activate Break Points"
#define fr_Auto6309   "Points d'Arret Actifs"
#define it_Auto6309   "Activate Break Points"
#define es_Auto6309   "Activate Break Points"
#define de_Auto6309   "Activate Break Points"
#define nl_Auto6309   "Activate Break Points"
#define pt_Auto6309   "Activate Break Points"
#define xx_Auto6309   "Activate Break Points"
#define en_Auto6311   "Dynamic Libraries"
#define fr_Auto6311   "BibliothŠques Dynamiques"
#define it_Auto6311   "Dynamic Libraries"
#define es_Auto6311   "Dynamic Libraries"
#define de_Auto6311   "Dynamic Libraries"
#define nl_Auto6311   "Dynamic Libraries"
#define pt_Auto6311   "Dynamic Libraries"
#define xx_Auto6311   "Dynamic Libraries"
#define en_Auto6313   "Active Variable Watch Expressions"
#define fr_Auto6313   "Expressions de Surveillance de Variables"
#define it_Auto6313   "Active Variable Watch Expressions"
#define es_Auto6313   "Active Variable Watch Expressions"
#define de_Auto6313   "Active Variable Watch Expressions"
#define nl_Auto6313   "Active Variable Watch Expressions"
#define pt_Auto6313   "Active Variable Watch Expressions"
#define xx_Auto6313   "Active Variable Watch Expressions"
#define en_Auto6315   "Syntax and Variable Value Display"
#define fr_Auto6315   "Affichage de Syntax et Valeurs de Variables"
#define it_Auto6315   "Syntax and Variable Value Display"
#define es_Auto6315   "Syntax and Variable Value Display"
#define de_Auto6315   "Syntax and Variable Value Display"
#define nl_Auto6315   "Syntax and Variable Value Display"
#define pt_Auto6315   "Syntax and Variable Value Display"
#define xx_Auto6315   "Syntax and Variable Value Display"
#define en_Auto6317   "Tcode Registers"
#define fr_Auto6317   "Registres"
#define it_Auto6317   "Tcode Registers"
#define es_Auto6317   "Tcode Registers"
#define de_Auto6317   "Tcode Registers"
#define nl_Auto6317   "Tcode Registers"
#define pt_Auto6317   "Tcode Registers"
#define xx_Auto6317   "Tcode Registers"
#define en_Auto6319   "Assigned Files"
#define fr_Auto6319   "Fichiers Assign‚s"
#define it_Auto6319   "Assigned Files"
#define es_Auto6319   "Assigned Files"
#define de_Auto6319   "Assigned Files"
#define nl_Auto6319   "Assigned Files"
#define pt_Auto6319   "Assigned Files"
#define xx_Auto6319   "Assigned Files"
#define en_Auto6321   "Attached Programs"
#define fr_Auto6321   "Programs Attach‚es"
#define it_Auto6321   "Attached Programs"
#define es_Auto6321   "Attached Programs"
#define de_Auto6321   "Attached Programs"
#define nl_Auto6321   "Attached Programs"
#define pt_Auto6321   "Attached Programs"
#define xx_Auto6321   "Attached Programs"
#define en_Auto6323   "Stack Inspection"
#define fr_Auto6323   "Inspection du Pile"
#define it_Auto6323   "Stack Inspection"
#define es_Auto6323   "Stack Inspection"
#define de_Auto6323   "Stack Inspection"
#define nl_Auto6323   "Stack Inspection"
#define pt_Auto6323   "Stack Inspection"
#define xx_Auto6323   "Stack Inspection"
#define en_Auto6325   "Source Files"
#define fr_Auto6325   "Fichiers Sources"
#define it_Auto6325   "Source Files"
#define es_Auto6325   "Source Files"
#define de_Auto6325   "Source Files"
#define nl_Auto6325   "Source Files"
#define pt_Auto6325   "Source Files"
#define xx_Auto6325   "Source Files"
#define en_Auto6327   "Observation Variables"
#define fr_Auto6327   "Observation de Variables"
#define it_Auto6327   "Observation Variables"
#define es_Auto6327   "Observation Variables"
#define de_Auto6327   "Observation Variables"
#define nl_Auto6327   "Observation Variables"
#define pt_Auto6327   "Observation Variables"
#define xx_Auto6327   "Observation Variables"
#define en_Auto1618   "Add Segment Break"
#define fr_Auto1618   "Arret Segment"
#define it_Auto1618   "Add Segment Break"
#define es_Auto1618   "Add Segment Break"
#define de_Auto1618   "Add Segment Break"
#define nl_Auto1618   "Add Segment Break"
#define pt_Auto1618   "Add Segment Break"
#define xx_Auto1618   "Add Segment Break"
#define en_Auto1619   "Add Procedure Break"
#define fr_Auto1619   "Arret Procedure"
#define it_Auto1619   "Add Procedure Break"
#define es_Auto1619   "Add Procedure Break"
#define de_Auto1619   "Add Procedure Break"
#define nl_Auto1619   "Add Procedure Break"
#define pt_Auto1619   "Add Procedure Break"
#define xx_Auto1619   "Add Procedure Break"
#define en_Auto1620   "Add Variable Watch"
#define fr_Auto1620   "Surveil Variable"
#define it_Auto1620   "Add Variable Watch"
#define es_Auto1620   "Add Variable Watch"
#define de_Auto1620   "Add Variable Watch"
#define nl_Auto1620   "Add Variable Watch"
#define pt_Auto1620   "Add Variable Watch"
#define xx_Auto1620   "Add Variable Watch"
#define en_Auto1951   "Global Variable"
#define fr_Auto1951   "Variable Globale"
#define it_Auto1951   ""
#define es_Auto1951   ""
#define de_Auto1951   ""
#define nl_Auto1951   ""
#define pt_Auto1951   ""
#define xx_Auto1951   ""
#define en_Auto1964   "Local Variable"
#define fr_Auto1964   "Variable Locale"
#define it_Auto1964   "Local Variable"
#define es_Auto1964   "Local Variable"
#define de_Auto1964   "Local Variable"
#define nl_Auto1964   "Local Variable"
#define pt_Auto1964   "Local Variable"
#define xx_Auto1964   "Local Variable"
#define it_ProcName   ""
#define es_ProcName   ""
#define de_ProcName   ""
#define nl_ProcName   ""
#define pt_ProcName   ""
#define xx_ProcName   ""
#define it_GlobNames   ""
#define es_GlobNames   ""
#define de_GlobNames   ""
#define nl_GlobNames   ""
#define pt_GlobNames   ""
#define xx_GlobNames   ""
#define it_AssignList   ""
#define es_AssignList   ""
#define de_AssignList   ""
#define nl_AssignList   ""
#define pt_AssignList   ""
#define xx_AssignList   ""
#define it_RegisterList   ""
#define es_RegisterList   ""
#define de_RegisterList   ""
#define nl_RegisterList   ""
#define pt_RegisterList   ""
#define xx_RegisterList   ""
#define it_AttachList   ""
#define es_AttachList   ""
#define de_AttachList   ""
#define nl_AttachList   ""
#define pt_AttachList   ""
#define xx_AttachList   ""
#define it_StackList   ""
#define es_StackList   ""
#define de_StackList   ""
#define nl_StackList   ""
#define pt_StackList   ""
#define xx_StackList   ""
#define it_LibraryList   ""
#define es_LibraryList   ""
#define de_LibraryList   ""
#define nl_LibraryList   ""
#define pt_LibraryList   ""
#define xx_LibraryList   ""
#define it_ObserveList   ""
#define es_ObserveList   ""
#define de_ObserveList   ""
#define nl_ObserveList   ""
#define pt_ObserveList   ""
#define xx_ObserveList   ""
#define en_DeleteObservation   "-"
#define it_BreakList   ""
#define es_BreakList   ""
#define de_BreakList   ""
#define nl_BreakList   ""
#define pt_BreakList   ""
#define xx_BreakList   ""
#define en_RemoveBreak   "-"
#define it_WatchList   ""
#define es_WatchList   ""
#define de_WatchList   ""
#define nl_WatchList   ""
#define pt_WatchList   ""
#define xx_WatchList   ""
#define en_DeleteWatch   "-"
#define it_SourceList   ""
#define es_SourceList   ""
#define de_SourceList   ""
#define nl_SourceList   ""
#define pt_SourceList   ""
#define xx_SourceList   ""
#define en_InspectSource   ">"
#define en_Auto5722   "Editor Syntaxical Colours"
#define fr_Auto5722   "Couleurs Syntaxiques de l'Editeur"
#define it_Auto5722   "Editor Syntaxical Colours"
#define es_Auto5722   "Editor Syntaxical Colours"
#define de_Auto5722   "Editor Syntaxical Colours"
#define nl_Auto5722   "Editor Syntaxical Colours"
#define pt_Auto5722   "Editor Syntaxical Colours"
#define xx_Auto5722   "Editor Syntaxical Colours"
#define en_auto6060   "AED.NORMAL"
#define fr_auto6060   "AED.NORMAL"
#define it_auto6060   "AED.NORMAL"
#define es_auto6060   "AED.NORMAL"
#define de_auto6060   "AED.NORMAL"
#define nl_auto6060   "AED.NORMAL"
#define pt_auto6060   "AED.NORMAL"
#define xx_auto6060   "AED.NORMAL"
#define en_auto6061   "AED.STRING"
#define fr_auto6061   "AED.STRING"
#define it_auto6061   "AED.STRING"
#define es_auto6061   "AED.STRING"
#define de_auto6061   "AED.STRING"
#define nl_auto6061   "AED.STRING"
#define pt_auto6061   "AED.STRING"
#define xx_auto6061   "AED.STRING"
#define en_auto6062   "AED.KEYWORD"
#define fr_auto6062   "AED.KEYWORD"
#define it_auto6062   "AED.KEYWORD"
#define es_auto6062   "AED.KEYWORD"
#define de_auto6062   "AED.KEYWORD"
#define nl_auto6062   "AED.KEYWORD"
#define pt_auto6062   "AED.KEYWORD"
#define xx_auto6062   "AED.KEYWORD"
#define en_auto6063   "AED.COMMENT"
#define fr_auto6063   "AED.COMMENT"
#define it_auto6063   "AED.COMMENT"
#define es_auto6063   "AED.COMMENT"
#define de_auto6063   "AED.COMMENT"
#define nl_auto6063   "AED.COMMENT"
#define pt_auto6063   "AED.COMMENT"
#define xx_auto6063   "AED.COMMENT"
#define en_auto6064   "AED.PUNCTUATE"
#define fr_auto6064   "AED.PUNCTUATE"
#define it_auto6064   "AED.PUNCTUATE"
#define es_auto6064   "AED.PUNCTUATE"
#define de_auto6064   "AED.PUNCTUATE"
#define nl_auto6064   "AED.PUNCTUATE"
#define pt_auto6064   "AED.PUNCTUATE"
#define xx_auto6064   "AED.PUNCTUATE"
#define en_EditorColour   "&Editor Colours"
#define fr_EditorColour   "Couleurs &Editeur"
#define it_EditorColour   "&Editor Colours"
#define es_EditorColour   "&Editor Colours"
#define de_EditorColour   "&Editor Colours"
#define nl_EditorColour   "&Editor Colours"
#define pt_EditorColour   "&Editor Colours"
#define xx_EditorColour   "&Editor Colours"
#define en_SetBreakAP   "Multiple"
#define fr_SetBreakAP   "Multiple"
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
#define en_SingleWatch   "One Shot"
#define fr_SingleWatch   "Unique"
#define it_SingleWatch   "One Shot"
#define es_SingleWatch   "One Shot"
#define de_SingleWatch   "One Shot"
#define nl_SingleWatch   "One Shot"
#define pt_SingleWatch   "One Shot"
#define xx_SingleWatch   "One Shot"
#define en_ObserveGlobal   "Observe"
#define fr_ObserveGlobal   "Observe"
#define it_ObserveGlobal   "Observe"
#define es_ObserveGlobal   "Observe"
#define de_ObserveGlobal   "Observe"
#define nl_ObserveGlobal   "Observe"
#define pt_ObserveGlobal   "Observe"
#define xx_ObserveGlobal   "Observe"
#define en_InspectGlobal   "Inspect"
#define fr_InspectGlobal   "Inspect"
#define it_InspectGlobal   "Inspect"
#define es_InspectGlobal   "Inspect"
#define de_InspectGlobal   "Inspect"
#define nl_InspectGlobal   "Inspect"
#define pt_InspectGlobal   "Inspect"
#define xx_InspectGlobal   "Inspect"
#define en_ObserveLocal   "Observe"
#define fr_ObserveLocal   "Observe"
#define it_ObserveLocal   "Observe"
#define es_ObserveLocal   "Observe"
#define de_ObserveLocal   "Observe"
#define nl_ObserveLocal   "Observe"
#define pt_ObserveLocal   "Observe"
#define xx_ObserveLocal   "Observe"
#define en_InspectLocal   "Inspect"
#define fr_InspectLocal   "Inspect"
#define it_InspectLocal   "Inspect"
#define es_InspectLocal   "Inspect"
#define de_InspectLocal   "Inspect"
#define nl_InspectLocal   "Inspect"
#define pt_InspectLocal   "Inspect"
#define xx_InspectLocal   "Inspect"
#define en_BreakKey   "Intr"
#define fr_BreakKey   "Intr"
#define it_BreakKey   "Intr"
#define es_BreakKey   "Intr"
#define de_BreakKey   "Intr"
#define nl_BreakKey   "Intr"
#define pt_BreakKey   "Intr"
#define xx_BreakKey   "Intr"
#define en_AsmList   "List"
#define fr_AsmList   "List"
#define it_AsmList   "List"
#define es_AsmList   "List"
#define de_AsmList   "List"
#define nl_AsmList   "List"
#define pt_AsmList   "List"
#define xx_AsmList   "List"
#define en_HexaView   "Hexa"
#define fr_HexaView   "Hexa"
#define it_HexaView   "Hexa"
#define es_HexaView   "Hexa"
#define de_HexaView   "Hexa"
#define nl_HexaView   "Hexa"
#define pt_HexaView   "Hexa"
#define xx_HexaView   "Hexa"
#define en_StatusBar   ""
#define fr_StatusBar   ""
#define en_VariableControl   "&Variables"
#define fr_VariableControl   "&Variables"
#define it_VariableControl   "&Variables"
#define es_VariableControl   "&Variables"
#define de_VariableControl   "&Variables"
#define nl_VariableControl   "&Variables"
#define pt_VariableControl   "&Variables"
#define xx_VariableControl   "&Variables"
#define en_vListe   "ID|Variable|Offset|Value"
#define fr_vListe   "ID|Variable|Offset|Valeur"
#define it_vListe   "ID|Variable|Offset|Value"
#define es_vListe   "ID|Variable|Offset|Value"
#define de_vListe   "ID|Variable|Offset|Value"
#define nl_vListe   "ID|Variable|Offset|Value"
#define pt_vListe   "ID|Variable|Offset|Value"
#define xx_vListe   "ID|Variable|Offset|Value"
#define en_vBar   ""
static int	vfh[10];

private struct visual_debug_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[4+1];
	char * msg_Main[8];
	char * msg_ProgramSource[8];
	int	trigger_ProgramSource;
	int	page_number;
	char * msg_Auto4724[8];
	char	buffer_BreakManager[109];
	char * msg_DebugCursor[8];
	int	x_DebugCursor;
	int	y_DebugCursor;
	int	w_DebugCursor;
	int	h_DebugCursor;
	int	fg_DebugCursor;
	int	bg_DebugCursor;
	int	fid_DebugCursor;
	char * msg_BreakPoint[8];
	int	x_BreakPoint;
	int	y_BreakPoint;
	int	w_BreakPoint;
	int	h_BreakPoint;
	int	fg_BreakPoint;
	int	bg_BreakPoint;
	int	fid_BreakPoint;
	char * msg_Exit[8];
	int	trigger_Exit;
	char * msg_StepInto[8];
	int	trigger_StepInto;
	char * msg_Goto[8];
	int	trigger_Goto;
	char * msg_Break[8];
	int	trigger_Break;
	char * msg_ClearBreak[8];
	int	trigger_ClearBreak;
	char * msg_Run[8];
	int	trigger_Run;
	char * msg_View[8];
	int	trigger_View;
	char	buffer_Dbio[3781];
	char * msg_ProgramOutput[8];
	int	trigger_ProgramOutput;
	char * msg_Auto4725[8];
	char	buffer_Prio[3605];
	int	value_VSB;
	int	limit_VSB;
	int	max_VSB;
	int	value_HSB;
	int	limit_HSB;
	int	max_HSB;
	char * msg_DebugControl[8];
	int	trigger_DebugControl;
	char * msg_Auto1955[8];
	char * msg_Auto6301[8];
	char * msg_Auto6303[8];
	char * msg_Auto6305[8];
	char * msg_Auto6307[8];
	char * msg_Auto6309[8];
	char * msg_Auto6311[8];
	char * msg_Auto6313[8];
	char * msg_Auto6315[8];
	char * msg_Auto6317[8];
	char * msg_Auto6319[8];
	char * msg_Auto6321[8];
	char * msg_Auto6323[8];
	char * msg_Auto6325[8];
	char * msg_Auto6327[8];
	char * msg_Auto1618[8];
	char * msg_Auto1619[8];
	char * msg_Auto1620[8];
	char * msg_Auto1951[8];
	char * msg_Auto1964[8];
	char * msg_ProcName[8];
	int	value_ProcName;
	char * msg_SegmName[8];
	int	value_SegmName;
	char * msg_GlobNames[8];
	int	value_GlobNames;
	char * msg_LocalNames[8];
	int	value_LocalNames;
	char * msg_AssignList[8];
	int	value_AssignList;
	char * msg_RegisterList[8];
	int	value_RegisterList;
	char * msg_AttachList[8];
	int	value_AttachList;
	char * msg_StackList[8];
	int	value_StackList;
	char * msg_LibraryList[8];
	int	value_LibraryList;
	char * msg_ObserveList[8];
	int	value_ObserveList;
	char * msg_DeleteObservation[8];
	int	trigger_DeleteObservation;
	char * msg_BreakList[8];
	int	value_BreakList;
	char * msg_RemoveBreak[8];
	int	trigger_RemoveBreak;
	char * msg_WatchList[8];
	int	value_WatchList;
	char * msg_DeleteWatch[8];
	int	trigger_DeleteWatch;
	char * msg_SourceList[8];
	int	value_SourceList;
	char * msg_InspectSource[8];
	int	trigger_InspectSource;
	char	buffer_Syntax[425];
	char * msg_Auto5722[8];
	char * msg_auto6060[8];
	char * msg_auto6061[8];
	char * msg_auto6062[8];
	char * msg_auto6063[8];
	char * msg_auto6064[8];
	char * msg_AED_NORMAL[8];
	int	value_AED_NORMAL;
	char * msg_AED_QUOTE[8];
	int	value_AED_QUOTE;
	char * msg_AED_KEYWORD[8];
	int	value_AED_KEYWORD;
	char * msg_AED_COMMENT[8];
	int	value_AED_COMMENT;
	char * msg_AED_PUNCTUATE[8];
	int	value_AED_PUNCTUATE;
	char * msg_EditorColour[8];
	int	trigger_EditorColour;
	char * msg_SetBreakAP[8];
	int	trigger_SetBreakAP;
	char * msg_SetBreakBP[8];
	int	trigger_SetBreakBP;
	char * msg_SetBreakAS[8];
	int	trigger_SetBreakAS;
	char * msg_SetBreakBS[8];
	int	trigger_SetBreakBS;
	char * msg_MultipleWatch[8];
	int	trigger_MultipleWatch;
	char * msg_SingleWatch[8];
	int	trigger_SingleWatch;
	char * msg_ObserveGlobal[8];
	int	trigger_ObserveGlobal;
	char * msg_InspectGlobal[8];
	int	trigger_InspectGlobal;
	char * msg_ObserveLocal[8];
	int	trigger_ObserveLocal;
	char * msg_InspectLocal[8];
	int	trigger_InspectLocal;
	char * msg_BreakKey[8];
	int	trigger_BreakKey;
	int	value_BreakKey;
	char * msg_AsmList[8];
	int	trigger_AsmList;
	int	value_AsmList;
	char * msg_HexaView[8];
	int	trigger_HexaView;
	int	value_HexaView;
	char	buffer_StatusBar[91];
	char * msg_VariableControl[8];
	int	trigger_VariableControl;
	char * msg_vListe[8];
	int	value_vListe;
	int	column_vListe;
	char	buffer_vListe[34][107];
	char * row_vListe;
	int	value_vBar;
	int	limit_vBar;
	int	max_vBar;
	char	signature[26];
	} * _Context;
private int on_StatusBar_create() {
	WindowEditorInformation(_Context->buffer_StatusBar,90);
	return(-1);
}

public	int	visual_debug_attach()
{
	if ( visual_initialise(4|512) == -1 )
		return(56);

	else	{
		visual_palette("aqua.rgb",8);
		cicopalette(0,0);
		vfh[1] = visual_font("standard.fmf",12);
		vfh[2] = visual_font("arial2.fmf",10);
		vfh[3] = visual_font("arial3.fmf",10);
		vfh[4] = visual_font("arial4.fmf",10);
		vfh[5] = visual_font("arial5.fmf",10);
		vfh[6] = visual_font("ufjt6.fmf",9);
		vfh[7] = visual_font("font7.fmf",9);
		vfh[8] = visual_font("font8.fmf",9);
		vfh[9] = visual_font("font9.fmf",9);
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
	char * pBreakManager,
	char * pDbio,
	char * pPrio,
	char * pProcName,
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
	char * pBreakKey,
	char * pHexaView,
	char * pStatusBar)
{

	int i;
	if (!(_Context = allocate( sizeof( struct visual_debug_context ) ) ))
		return(27);
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=56;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSSWWWWWWWWWWWWWSWWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_BreakManager, 108, pBreakManager);
		visual_transferin(_Context->buffer_Dbio, 3780, pDbio);
		visual_transferin(_Context->buffer_Prio, 3604, pPrio);
		visual_transferin((void *) 0, 0, pProcName);
		if (!( pProcName )) _Context->value_ProcName=0;
		else	_Context->value_ProcName = *((int *)pProcName);
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
		visual_transferin(_Context->buffer_Syntax, 424, pSyntax);
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
		visual_transferin((void *) 0, 0, pBreakKey);
		if (!( pBreakKey )) _Context->value_BreakKey=0;
		else	_Context->value_BreakKey = *((int *)pBreakKey);
		visual_transferin((void *) 0, 0, pHexaView);
		if (!( pHexaView )) _Context->value_HexaView=0;
		else	_Context->value_HexaView = *((int *)pHexaView);
		visual_transferin(_Context->buffer_StatusBar, 90, pStatusBar);
		}
	for (i=0; i < 8; i++)_Context->msg_Main[i]=" ";
	_Context->msg_Main[0]=en_Main;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_ProgramSource[i]=" ";
	_Context->msg_ProgramSource[0]=en_ProgramSource;
	_Context->msg_ProgramSource[1]=fr_ProgramSource;
	_Context->msg_ProgramSource[2]=it_ProgramSource;
	_Context->msg_ProgramSource[3]=es_ProgramSource;
	_Context->msg_ProgramSource[4]=de_ProgramSource;
	_Context->msg_ProgramSource[5]=nl_ProgramSource;
	_Context->msg_ProgramSource[6]=pt_ProgramSource;
	_Context->msg_ProgramSource[7]=xx_ProgramSource;
	_Context->focus_pages[1]=2;
	WindowEditorOnCreate(61+1,70+1,840-2,576-2,vfh[1]);
	for (i=0; i < 8; i++)_Context->msg_Auto4724[i]=" ";
	_Context->msg_Auto4724[0]=en_Auto4724;
	for (i=0; i < 8; i++)_Context->msg_DebugCursor[i]=" ";
	_Context->msg_DebugCursor[0]=en_DebugCursor;
	_Context->x_DebugCursor=35;
	_Context->y_DebugCursor=70;
	_Context->w_DebugCursor=20;
	_Context->h_DebugCursor=20;
	_Context->fg_DebugCursor=20;
	_Context->bg_DebugCursor=20;
	_Context->fid_DebugCursor=1;
	for (i=0; i < 8; i++)_Context->msg_BreakPoint[i]=" ";
	_Context->msg_BreakPoint[0]=en_BreakPoint;
	_Context->x_BreakPoint=35;
	_Context->y_BreakPoint=90;
	_Context->w_BreakPoint=20;
	_Context->h_BreakPoint=20;
	_Context->fg_BreakPoint=20;
	_Context->bg_BreakPoint=20;
	_Context->fid_BreakPoint=1;
	for (i=0; i < 8; i++)_Context->msg_Exit[i]=" ";
	_Context->msg_Exit[0]=en_Exit;
	_Context->msg_Exit[1]=fr_Exit;
	_Context->msg_Exit[2]=it_Exit;
	_Context->msg_Exit[3]=es_Exit;
	_Context->msg_Exit[4]=de_Exit;
	_Context->msg_Exit[5]=nl_Exit;
	_Context->msg_Exit[6]=pt_Exit;
	_Context->msg_Exit[7]=xx_Exit;
	for (i=0; i < 8; i++)_Context->msg_StepInto[i]=" ";
	_Context->msg_StepInto[0]=en_StepInto;
	_Context->msg_StepInto[1]=fr_StepInto;
	_Context->msg_StepInto[2]=it_StepInto;
	_Context->msg_StepInto[3]=es_StepInto;
	_Context->msg_StepInto[4]=de_StepInto;
	_Context->msg_StepInto[5]=nl_StepInto;
	_Context->msg_StepInto[6]=pt_StepInto;
	_Context->msg_StepInto[7]=xx_StepInto;
	for (i=0; i < 8; i++)_Context->msg_Goto[i]=" ";
	_Context->msg_Goto[0]=en_Goto;
	_Context->msg_Goto[1]=fr_Goto;
	_Context->msg_Goto[2]=it_Goto;
	_Context->msg_Goto[3]=es_Goto;
	_Context->msg_Goto[4]=de_Goto;
	_Context->msg_Goto[5]=nl_Goto;
	_Context->msg_Goto[6]=pt_Goto;
	_Context->msg_Goto[7]=xx_Goto;
	for (i=0; i < 8; i++)_Context->msg_Break[i]=" ";
	_Context->msg_Break[0]=en_Break;
	_Context->msg_Break[1]=fr_Break;
	_Context->msg_Break[2]=it_Break;
	_Context->msg_Break[3]=es_Break;
	_Context->msg_Break[4]=de_Break;
	_Context->msg_Break[5]=nl_Break;
	_Context->msg_Break[6]=pt_Break;
	_Context->msg_Break[7]=xx_Break;
	for (i=0; i < 8; i++)_Context->msg_ClearBreak[i]=" ";
	_Context->msg_ClearBreak[0]=en_ClearBreak;
	_Context->msg_ClearBreak[1]=fr_ClearBreak;
	_Context->msg_ClearBreak[2]=it_ClearBreak;
	_Context->msg_ClearBreak[3]=es_ClearBreak;
	_Context->msg_ClearBreak[4]=de_ClearBreak;
	_Context->msg_ClearBreak[5]=nl_ClearBreak;
	_Context->msg_ClearBreak[6]=pt_ClearBreak;
	_Context->msg_ClearBreak[7]=xx_ClearBreak;
	for (i=0; i < 8; i++)_Context->msg_Run[i]=" ";
	_Context->msg_Run[0]=en_Run;
	_Context->msg_Run[1]=fr_Run;
	_Context->msg_Run[2]=it_Run;
	_Context->msg_Run[3]=es_Run;
	_Context->msg_Run[4]=de_Run;
	_Context->msg_Run[5]=nl_Run;
	_Context->msg_Run[6]=pt_Run;
	_Context->msg_Run[7]=xx_Run;
	for (i=0; i < 8; i++)_Context->msg_View[i]=" ";
	_Context->msg_View[0]=en_View;
	_Context->msg_View[1]=fr_View;
	_Context->msg_View[2]=it_View;
	_Context->msg_View[3]=es_View;
	_Context->msg_View[4]=de_View;
	_Context->msg_View[5]=nl_View;
	_Context->msg_View[6]=pt_View;
	_Context->msg_View[7]=xx_View;
	for (i=0; i < 8; i++)_Context->msg_ProgramOutput[i]=" ";
	_Context->msg_ProgramOutput[0]=en_ProgramOutput;
	_Context->msg_ProgramOutput[1]=fr_ProgramOutput;
	_Context->msg_ProgramOutput[2]=it_ProgramOutput;
	_Context->msg_ProgramOutput[3]=es_ProgramOutput;
	_Context->msg_ProgramOutput[4]=de_ProgramOutput;
	_Context->msg_ProgramOutput[5]=nl_ProgramOutput;
	_Context->msg_ProgramOutput[6]=pt_ProgramOutput;
	_Context->msg_ProgramOutput[7]=xx_ProgramOutput;
	_Context->focus_pages[2]=11;
	ProgramWindowOnCreate(30,70,850,556);
	for (i=0; i < 8; i++)_Context->msg_Auto4725[i]=" ";
	_Context->msg_Auto4725[0]=en_Auto4725;
	_Context->max_VSB=1;
	_Context->value_VSB=1;
	_Context->limit_VSB=1;
	_Context->value_VSB=0;
	_Context->limit_VSB=556;
	_Context->max_VSB=hardrows();
	_Context->max_HSB=1;
	_Context->value_HSB=1;
	_Context->limit_HSB=1;
	_Context->value_HSB=0;
	_Context->limit_HSB=850;
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
	_Context->focus_pages[3]=15;
	for (i=0; i < 8; i++)_Context->msg_Auto1955[i]=" ";
	_Context->msg_Auto1955[0]=en_Auto1955;
	_Context->msg_Auto1955[1]=fr_Auto1955;
	_Context->msg_Auto1955[2]=it_Auto1955;
	_Context->msg_Auto1955[3]=es_Auto1955;
	_Context->msg_Auto1955[4]=de_Auto1955;
	_Context->msg_Auto1955[5]=nl_Auto1955;
	_Context->msg_Auto1955[6]=pt_Auto1955;
	_Context->msg_Auto1955[7]=xx_Auto1955;
	for (i=0; i < 8; i++)_Context->msg_Auto6301[i]=" ";
	_Context->msg_Auto6301[0]=en_Auto6301;
	_Context->msg_Auto6301[1]=fr_Auto6301;
	_Context->msg_Auto6301[2]=it_Auto6301;
	_Context->msg_Auto6301[3]=es_Auto6301;
	_Context->msg_Auto6301[4]=de_Auto6301;
	_Context->msg_Auto6301[5]=nl_Auto6301;
	_Context->msg_Auto6301[6]=pt_Auto6301;
	_Context->msg_Auto6301[7]=xx_Auto6301;
	for (i=0; i < 8; i++)_Context->msg_Auto6303[i]=" ";
	_Context->msg_Auto6303[0]=en_Auto6303;
	_Context->msg_Auto6303[1]=fr_Auto6303;
	_Context->msg_Auto6303[2]=it_Auto6303;
	_Context->msg_Auto6303[3]=es_Auto6303;
	_Context->msg_Auto6303[4]=de_Auto6303;
	_Context->msg_Auto6303[5]=nl_Auto6303;
	_Context->msg_Auto6303[6]=pt_Auto6303;
	_Context->msg_Auto6303[7]=xx_Auto6303;
	for (i=0; i < 8; i++)_Context->msg_Auto6305[i]=" ";
	_Context->msg_Auto6305[0]=en_Auto6305;
	_Context->msg_Auto6305[1]=fr_Auto6305;
	_Context->msg_Auto6305[2]=it_Auto6305;
	_Context->msg_Auto6305[3]=es_Auto6305;
	_Context->msg_Auto6305[4]=de_Auto6305;
	_Context->msg_Auto6305[5]=nl_Auto6305;
	_Context->msg_Auto6305[6]=pt_Auto6305;
	_Context->msg_Auto6305[7]=xx_Auto6305;
	for (i=0; i < 8; i++)_Context->msg_Auto6307[i]=" ";
	_Context->msg_Auto6307[0]=en_Auto6307;
	_Context->msg_Auto6307[1]=fr_Auto6307;
	_Context->msg_Auto6307[2]=it_Auto6307;
	_Context->msg_Auto6307[3]=es_Auto6307;
	_Context->msg_Auto6307[4]=de_Auto6307;
	_Context->msg_Auto6307[5]=nl_Auto6307;
	_Context->msg_Auto6307[6]=pt_Auto6307;
	_Context->msg_Auto6307[7]=xx_Auto6307;
	for (i=0; i < 8; i++)_Context->msg_Auto6309[i]=" ";
	_Context->msg_Auto6309[0]=en_Auto6309;
	_Context->msg_Auto6309[1]=fr_Auto6309;
	_Context->msg_Auto6309[2]=it_Auto6309;
	_Context->msg_Auto6309[3]=es_Auto6309;
	_Context->msg_Auto6309[4]=de_Auto6309;
	_Context->msg_Auto6309[5]=nl_Auto6309;
	_Context->msg_Auto6309[6]=pt_Auto6309;
	_Context->msg_Auto6309[7]=xx_Auto6309;
	for (i=0; i < 8; i++)_Context->msg_Auto6311[i]=" ";
	_Context->msg_Auto6311[0]=en_Auto6311;
	_Context->msg_Auto6311[1]=fr_Auto6311;
	_Context->msg_Auto6311[2]=it_Auto6311;
	_Context->msg_Auto6311[3]=es_Auto6311;
	_Context->msg_Auto6311[4]=de_Auto6311;
	_Context->msg_Auto6311[5]=nl_Auto6311;
	_Context->msg_Auto6311[6]=pt_Auto6311;
	_Context->msg_Auto6311[7]=xx_Auto6311;
	for (i=0; i < 8; i++)_Context->msg_Auto6313[i]=" ";
	_Context->msg_Auto6313[0]=en_Auto6313;
	_Context->msg_Auto6313[1]=fr_Auto6313;
	_Context->msg_Auto6313[2]=it_Auto6313;
	_Context->msg_Auto6313[3]=es_Auto6313;
	_Context->msg_Auto6313[4]=de_Auto6313;
	_Context->msg_Auto6313[5]=nl_Auto6313;
	_Context->msg_Auto6313[6]=pt_Auto6313;
	_Context->msg_Auto6313[7]=xx_Auto6313;
	for (i=0; i < 8; i++)_Context->msg_Auto6315[i]=" ";
	_Context->msg_Auto6315[0]=en_Auto6315;
	_Context->msg_Auto6315[1]=fr_Auto6315;
	_Context->msg_Auto6315[2]=it_Auto6315;
	_Context->msg_Auto6315[3]=es_Auto6315;
	_Context->msg_Auto6315[4]=de_Auto6315;
	_Context->msg_Auto6315[5]=nl_Auto6315;
	_Context->msg_Auto6315[6]=pt_Auto6315;
	_Context->msg_Auto6315[7]=xx_Auto6315;
	for (i=0; i < 8; i++)_Context->msg_Auto6317[i]=" ";
	_Context->msg_Auto6317[0]=en_Auto6317;
	_Context->msg_Auto6317[1]=fr_Auto6317;
	_Context->msg_Auto6317[2]=it_Auto6317;
	_Context->msg_Auto6317[3]=es_Auto6317;
	_Context->msg_Auto6317[4]=de_Auto6317;
	_Context->msg_Auto6317[5]=nl_Auto6317;
	_Context->msg_Auto6317[6]=pt_Auto6317;
	_Context->msg_Auto6317[7]=xx_Auto6317;
	for (i=0; i < 8; i++)_Context->msg_Auto6319[i]=" ";
	_Context->msg_Auto6319[0]=en_Auto6319;
	_Context->msg_Auto6319[1]=fr_Auto6319;
	_Context->msg_Auto6319[2]=it_Auto6319;
	_Context->msg_Auto6319[3]=es_Auto6319;
	_Context->msg_Auto6319[4]=de_Auto6319;
	_Context->msg_Auto6319[5]=nl_Auto6319;
	_Context->msg_Auto6319[6]=pt_Auto6319;
	_Context->msg_Auto6319[7]=xx_Auto6319;
	for (i=0; i < 8; i++)_Context->msg_Auto6321[i]=" ";
	_Context->msg_Auto6321[0]=en_Auto6321;
	_Context->msg_Auto6321[1]=fr_Auto6321;
	_Context->msg_Auto6321[2]=it_Auto6321;
	_Context->msg_Auto6321[3]=es_Auto6321;
	_Context->msg_Auto6321[4]=de_Auto6321;
	_Context->msg_Auto6321[5]=nl_Auto6321;
	_Context->msg_Auto6321[6]=pt_Auto6321;
	_Context->msg_Auto6321[7]=xx_Auto6321;
	for (i=0; i < 8; i++)_Context->msg_Auto6323[i]=" ";
	_Context->msg_Auto6323[0]=en_Auto6323;
	_Context->msg_Auto6323[1]=fr_Auto6323;
	_Context->msg_Auto6323[2]=it_Auto6323;
	_Context->msg_Auto6323[3]=es_Auto6323;
	_Context->msg_Auto6323[4]=de_Auto6323;
	_Context->msg_Auto6323[5]=nl_Auto6323;
	_Context->msg_Auto6323[6]=pt_Auto6323;
	_Context->msg_Auto6323[7]=xx_Auto6323;
	for (i=0; i < 8; i++)_Context->msg_Auto6325[i]=" ";
	_Context->msg_Auto6325[0]=en_Auto6325;
	_Context->msg_Auto6325[1]=fr_Auto6325;
	_Context->msg_Auto6325[2]=it_Auto6325;
	_Context->msg_Auto6325[3]=es_Auto6325;
	_Context->msg_Auto6325[4]=de_Auto6325;
	_Context->msg_Auto6325[5]=nl_Auto6325;
	_Context->msg_Auto6325[6]=pt_Auto6325;
	_Context->msg_Auto6325[7]=xx_Auto6325;
	for (i=0; i < 8; i++)_Context->msg_Auto6327[i]=" ";
	_Context->msg_Auto6327[0]=en_Auto6327;
	_Context->msg_Auto6327[1]=fr_Auto6327;
	_Context->msg_Auto6327[2]=it_Auto6327;
	_Context->msg_Auto6327[3]=es_Auto6327;
	_Context->msg_Auto6327[4]=de_Auto6327;
	_Context->msg_Auto6327[5]=nl_Auto6327;
	_Context->msg_Auto6327[6]=pt_Auto6327;
	_Context->msg_Auto6327[7]=xx_Auto6327;
	for (i=0; i < 8; i++)_Context->msg_Auto1618[i]=" ";
	_Context->msg_Auto1618[0]=en_Auto1618;
	_Context->msg_Auto1618[1]=fr_Auto1618;
	_Context->msg_Auto1618[2]=it_Auto1618;
	_Context->msg_Auto1618[3]=es_Auto1618;
	_Context->msg_Auto1618[4]=de_Auto1618;
	_Context->msg_Auto1618[5]=nl_Auto1618;
	_Context->msg_Auto1618[6]=pt_Auto1618;
	_Context->msg_Auto1618[7]=xx_Auto1618;
	for (i=0; i < 8; i++)_Context->msg_Auto1619[i]=" ";
	_Context->msg_Auto1619[0]=en_Auto1619;
	_Context->msg_Auto1619[1]=fr_Auto1619;
	_Context->msg_Auto1619[2]=it_Auto1619;
	_Context->msg_Auto1619[3]=es_Auto1619;
	_Context->msg_Auto1619[4]=de_Auto1619;
	_Context->msg_Auto1619[5]=nl_Auto1619;
	_Context->msg_Auto1619[6]=pt_Auto1619;
	_Context->msg_Auto1619[7]=xx_Auto1619;
	for (i=0; i < 8; i++)_Context->msg_Auto1620[i]=" ";
	_Context->msg_Auto1620[0]=en_Auto1620;
	_Context->msg_Auto1620[1]=fr_Auto1620;
	_Context->msg_Auto1620[2]=it_Auto1620;
	_Context->msg_Auto1620[3]=es_Auto1620;
	_Context->msg_Auto1620[4]=de_Auto1620;
	_Context->msg_Auto1620[5]=nl_Auto1620;
	_Context->msg_Auto1620[6]=pt_Auto1620;
	_Context->msg_Auto1620[7]=xx_Auto1620;
	for (i=0; i < 8; i++)_Context->msg_Auto1951[i]=" ";
	_Context->msg_Auto1951[0]=en_Auto1951;
	_Context->msg_Auto1951[1]=fr_Auto1951;
	_Context->msg_Auto1951[2]=it_Auto1951;
	_Context->msg_Auto1951[3]=es_Auto1951;
	_Context->msg_Auto1951[4]=de_Auto1951;
	_Context->msg_Auto1951[5]=nl_Auto1951;
	_Context->msg_Auto1951[6]=pt_Auto1951;
	_Context->msg_Auto1951[7]=xx_Auto1951;
	for (i=0; i < 8; i++)_Context->msg_Auto1964[i]=" ";
	_Context->msg_Auto1964[0]=en_Auto1964;
	_Context->msg_Auto1964[1]=fr_Auto1964;
	_Context->msg_Auto1964[2]=it_Auto1964;
	_Context->msg_Auto1964[3]=es_Auto1964;
	_Context->msg_Auto1964[4]=de_Auto1964;
	_Context->msg_Auto1964[5]=nl_Auto1964;
	_Context->msg_Auto1964[6]=pt_Auto1964;
	_Context->msg_Auto1964[7]=xx_Auto1964;
	for (i=0; i < 8; i++)_Context->msg_ProcName[i]=" ";
	_Context->msg_ProcName[2]=it_ProcName;
	_Context->msg_ProcName[3]=es_ProcName;
	_Context->msg_ProcName[4]=de_ProcName;
	_Context->msg_ProcName[5]=nl_ProcName;
	_Context->msg_ProcName[6]=pt_ProcName;
	_Context->msg_ProcName[7]=xx_ProcName;
	for (i=0; i < 8; i++)_Context->msg_SegmName[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_GlobNames[i]=" ";
	_Context->msg_GlobNames[2]=it_GlobNames;
	_Context->msg_GlobNames[3]=es_GlobNames;
	_Context->msg_GlobNames[4]=de_GlobNames;
	_Context->msg_GlobNames[5]=nl_GlobNames;
	_Context->msg_GlobNames[6]=pt_GlobNames;
	_Context->msg_GlobNames[7]=xx_GlobNames;
	for (i=0; i < 8; i++)_Context->msg_LocalNames[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AssignList[i]=" ";
	_Context->msg_AssignList[2]=it_AssignList;
	_Context->msg_AssignList[3]=es_AssignList;
	_Context->msg_AssignList[4]=de_AssignList;
	_Context->msg_AssignList[5]=nl_AssignList;
	_Context->msg_AssignList[6]=pt_AssignList;
	_Context->msg_AssignList[7]=xx_AssignList;
	for (i=0; i < 8; i++)_Context->msg_RegisterList[i]=" ";
	_Context->msg_RegisterList[2]=it_RegisterList;
	_Context->msg_RegisterList[3]=es_RegisterList;
	_Context->msg_RegisterList[4]=de_RegisterList;
	_Context->msg_RegisterList[5]=nl_RegisterList;
	_Context->msg_RegisterList[6]=pt_RegisterList;
	_Context->msg_RegisterList[7]=xx_RegisterList;
	for (i=0; i < 8; i++)_Context->msg_AttachList[i]=" ";
	_Context->msg_AttachList[2]=it_AttachList;
	_Context->msg_AttachList[3]=es_AttachList;
	_Context->msg_AttachList[4]=de_AttachList;
	_Context->msg_AttachList[5]=nl_AttachList;
	_Context->msg_AttachList[6]=pt_AttachList;
	_Context->msg_AttachList[7]=xx_AttachList;
	for (i=0; i < 8; i++)_Context->msg_StackList[i]=" ";
	_Context->msg_StackList[2]=it_StackList;
	_Context->msg_StackList[3]=es_StackList;
	_Context->msg_StackList[4]=de_StackList;
	_Context->msg_StackList[5]=nl_StackList;
	_Context->msg_StackList[6]=pt_StackList;
	_Context->msg_StackList[7]=xx_StackList;
	for (i=0; i < 8; i++)_Context->msg_LibraryList[i]=" ";
	_Context->msg_LibraryList[2]=it_LibraryList;
	_Context->msg_LibraryList[3]=es_LibraryList;
	_Context->msg_LibraryList[4]=de_LibraryList;
	_Context->msg_LibraryList[5]=nl_LibraryList;
	_Context->msg_LibraryList[6]=pt_LibraryList;
	_Context->msg_LibraryList[7]=xx_LibraryList;
	for (i=0; i < 8; i++)_Context->msg_ObserveList[i]=" ";
	_Context->msg_ObserveList[2]=it_ObserveList;
	_Context->msg_ObserveList[3]=es_ObserveList;
	_Context->msg_ObserveList[4]=de_ObserveList;
	_Context->msg_ObserveList[5]=nl_ObserveList;
	_Context->msg_ObserveList[6]=pt_ObserveList;
	_Context->msg_ObserveList[7]=xx_ObserveList;
	for (i=0; i < 8; i++)_Context->msg_DeleteObservation[i]=" ";
	_Context->msg_DeleteObservation[0]=en_DeleteObservation;
	for (i=0; i < 8; i++)_Context->msg_BreakList[i]=" ";
	_Context->msg_BreakList[2]=it_BreakList;
	_Context->msg_BreakList[3]=es_BreakList;
	_Context->msg_BreakList[4]=de_BreakList;
	_Context->msg_BreakList[5]=nl_BreakList;
	_Context->msg_BreakList[6]=pt_BreakList;
	_Context->msg_BreakList[7]=xx_BreakList;
	for (i=0; i < 8; i++)_Context->msg_RemoveBreak[i]=" ";
	_Context->msg_RemoveBreak[0]=en_RemoveBreak;
	for (i=0; i < 8; i++)_Context->msg_WatchList[i]=" ";
	_Context->msg_WatchList[2]=it_WatchList;
	_Context->msg_WatchList[3]=es_WatchList;
	_Context->msg_WatchList[4]=de_WatchList;
	_Context->msg_WatchList[5]=nl_WatchList;
	_Context->msg_WatchList[6]=pt_WatchList;
	_Context->msg_WatchList[7]=xx_WatchList;
	for (i=0; i < 8; i++)_Context->msg_DeleteWatch[i]=" ";
	_Context->msg_DeleteWatch[0]=en_DeleteWatch;
	for (i=0; i < 8; i++)_Context->msg_SourceList[i]=" ";
	_Context->msg_SourceList[2]=it_SourceList;
	_Context->msg_SourceList[3]=es_SourceList;
	_Context->msg_SourceList[4]=de_SourceList;
	_Context->msg_SourceList[5]=nl_SourceList;
	_Context->msg_SourceList[6]=pt_SourceList;
	_Context->msg_SourceList[7]=xx_SourceList;
	for (i=0; i < 8; i++)_Context->msg_InspectSource[i]=" ";
	_Context->msg_InspectSource[0]=en_InspectSource;
	for (i=0; i < 8; i++)_Context->msg_Auto5722[i]=" ";
	_Context->msg_Auto5722[0]=en_Auto5722;
	_Context->msg_Auto5722[1]=fr_Auto5722;
	_Context->msg_Auto5722[2]=it_Auto5722;
	_Context->msg_Auto5722[3]=es_Auto5722;
	_Context->msg_Auto5722[4]=de_Auto5722;
	_Context->msg_Auto5722[5]=nl_Auto5722;
	_Context->msg_Auto5722[6]=pt_Auto5722;
	_Context->msg_Auto5722[7]=xx_Auto5722;
	for (i=0; i < 8; i++)_Context->msg_auto6060[i]=" ";
	_Context->msg_auto6060[0]=en_auto6060;
	_Context->msg_auto6060[1]=fr_auto6060;
	_Context->msg_auto6060[2]=it_auto6060;
	_Context->msg_auto6060[3]=es_auto6060;
	_Context->msg_auto6060[4]=de_auto6060;
	_Context->msg_auto6060[5]=nl_auto6060;
	_Context->msg_auto6060[6]=pt_auto6060;
	_Context->msg_auto6060[7]=xx_auto6060;
	for (i=0; i < 8; i++)_Context->msg_auto6061[i]=" ";
	_Context->msg_auto6061[0]=en_auto6061;
	_Context->msg_auto6061[1]=fr_auto6061;
	_Context->msg_auto6061[2]=it_auto6061;
	_Context->msg_auto6061[3]=es_auto6061;
	_Context->msg_auto6061[4]=de_auto6061;
	_Context->msg_auto6061[5]=nl_auto6061;
	_Context->msg_auto6061[6]=pt_auto6061;
	_Context->msg_auto6061[7]=xx_auto6061;
	for (i=0; i < 8; i++)_Context->msg_auto6062[i]=" ";
	_Context->msg_auto6062[0]=en_auto6062;
	_Context->msg_auto6062[1]=fr_auto6062;
	_Context->msg_auto6062[2]=it_auto6062;
	_Context->msg_auto6062[3]=es_auto6062;
	_Context->msg_auto6062[4]=de_auto6062;
	_Context->msg_auto6062[5]=nl_auto6062;
	_Context->msg_auto6062[6]=pt_auto6062;
	_Context->msg_auto6062[7]=xx_auto6062;
	for (i=0; i < 8; i++)_Context->msg_auto6063[i]=" ";
	_Context->msg_auto6063[0]=en_auto6063;
	_Context->msg_auto6063[1]=fr_auto6063;
	_Context->msg_auto6063[2]=it_auto6063;
	_Context->msg_auto6063[3]=es_auto6063;
	_Context->msg_auto6063[4]=de_auto6063;
	_Context->msg_auto6063[5]=nl_auto6063;
	_Context->msg_auto6063[6]=pt_auto6063;
	_Context->msg_auto6063[7]=xx_auto6063;
	for (i=0; i < 8; i++)_Context->msg_auto6064[i]=" ";
	_Context->msg_auto6064[0]=en_auto6064;
	_Context->msg_auto6064[1]=fr_auto6064;
	_Context->msg_auto6064[2]=it_auto6064;
	_Context->msg_auto6064[3]=es_auto6064;
	_Context->msg_auto6064[4]=de_auto6064;
	_Context->msg_auto6064[5]=nl_auto6064;
	_Context->msg_auto6064[6]=pt_auto6064;
	_Context->msg_auto6064[7]=xx_auto6064;
	for (i=0; i < 8; i++)_Context->msg_AED_NORMAL[i]=" ";
	_Context->value_AED_NORMAL=0;
	for (i=0; i < 8; i++)_Context->msg_AED_QUOTE[i]=" ";
	_Context->value_AED_QUOTE=12;
	for (i=0; i < 8; i++)_Context->msg_AED_KEYWORD[i]=" ";
	_Context->value_AED_KEYWORD=9;
	for (i=0; i < 8; i++)_Context->msg_AED_COMMENT[i]=" ";
	_Context->value_AED_COMMENT=10;
	for (i=0; i < 8; i++)_Context->msg_AED_PUNCTUATE[i]=" ";
	_Context->value_AED_PUNCTUATE=0;
	for (i=0; i < 8; i++)_Context->msg_EditorColour[i]=" ";
	_Context->msg_EditorColour[0]=en_EditorColour;
	_Context->msg_EditorColour[1]=fr_EditorColour;
	_Context->msg_EditorColour[2]=it_EditorColour;
	_Context->msg_EditorColour[3]=es_EditorColour;
	_Context->msg_EditorColour[4]=de_EditorColour;
	_Context->msg_EditorColour[5]=nl_EditorColour;
	_Context->msg_EditorColour[6]=pt_EditorColour;
	_Context->msg_EditorColour[7]=xx_EditorColour;
	for (i=0; i < 8; i++)_Context->msg_SetBreakAP[i]=" ";
	_Context->msg_SetBreakAP[0]=en_SetBreakAP;
	_Context->msg_SetBreakAP[1]=fr_SetBreakAP;
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
	for (i=0; i < 8; i++)_Context->msg_BreakKey[i]=" ";
	_Context->msg_BreakKey[0]=en_BreakKey;
	_Context->msg_BreakKey[1]=fr_BreakKey;
	_Context->msg_BreakKey[2]=it_BreakKey;
	_Context->msg_BreakKey[3]=es_BreakKey;
	_Context->msg_BreakKey[4]=de_BreakKey;
	_Context->msg_BreakKey[5]=nl_BreakKey;
	_Context->msg_BreakKey[6]=pt_BreakKey;
	_Context->msg_BreakKey[7]=xx_BreakKey;
	_Context->value_BreakKey=get_brayk_value();
	on_BreakKey_event();
	for (i=0; i < 8; i++)_Context->msg_AsmList[i]=" ";
	_Context->msg_AsmList[0]=en_AsmList;
	_Context->msg_AsmList[1]=fr_AsmList;
	_Context->msg_AsmList[2]=it_AsmList;
	_Context->msg_AsmList[3]=es_AsmList;
	_Context->msg_AsmList[4]=de_AsmList;
	_Context->msg_AsmList[5]=nl_AsmList;
	_Context->msg_AsmList[6]=pt_AsmList;
	_Context->msg_AsmList[7]=xx_AsmList;
	_Context->value_AsmList=1;
	strcpy(_Context->buffer_Syntax,"LA0");
	for (i=0; i < 8; i++)_Context->msg_HexaView[i]=" ";
	_Context->msg_HexaView[0]=en_HexaView;
	_Context->msg_HexaView[1]=fr_HexaView;
	_Context->msg_HexaView[2]=it_HexaView;
	_Context->msg_HexaView[3]=es_HexaView;
	_Context->msg_HexaView[4]=de_HexaView;
	_Context->msg_HexaView[5]=nl_HexaView;
	_Context->msg_HexaView[6]=pt_HexaView;
	_Context->msg_HexaView[7]=xx_HexaView;
	(void) on_StatusBar_create();
	for (i=0; i < 8; i++)_Context->msg_VariableControl[i]=" ";
	_Context->msg_VariableControl[0]=en_VariableControl;
	_Context->msg_VariableControl[1]=fr_VariableControl;
	_Context->msg_VariableControl[2]=it_VariableControl;
	_Context->msg_VariableControl[3]=es_VariableControl;
	_Context->msg_VariableControl[4]=de_VariableControl;
	_Context->msg_VariableControl[5]=nl_VariableControl;
	_Context->msg_VariableControl[6]=pt_VariableControl;
	_Context->msg_VariableControl[7]=xx_VariableControl;
	_Context->focus_pages[4]=54;
	for (i=0; i < 8; i++)_Context->msg_vListe[i]=" ";
	_Context->msg_vListe[0]=en_vListe;
	_Context->msg_vListe[1]=fr_vListe;
	_Context->msg_vListe[2]=it_vListe;
	_Context->msg_vListe[3]=es_vListe;
	_Context->msg_vListe[4]=de_vListe;
	_Context->msg_vListe[5]=nl_vListe;
	_Context->msg_vListe[6]=pt_vListe;
	_Context->msg_vListe[7]=xx_vListe;
	if ( 0 > 0 ) { _Context->row_vListe=&_Context->buffer_vListe[0-1][0]; } ;
	_Context->max_vBar=1;
	_Context->value_vBar=1;
	_Context->limit_vBar=1;
	_Context->value_vBar=0;
	_Context->limit_vBar=34;
	_Context->max_vBar=32000;
	return(0);
}

public 	int	visual_debug_hide()
{
	int	result=_Context->keycode;

	return(result);
}

public	int	visual_debug_remove(
	char * pBreakManager,
	char * pDbio,
	char * pPrio,
	char * pProcName,
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
	char * pBreakKey,
	char * pHexaView,
	char * pStatusBar)
{

	int	result=_Context->keycode;
	WindowEditorOnRemove();
	ProgramWindowOnRemove();
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"KSSWWWWWWWWWWWWWSWWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_BreakManager, 108, pBreakManager);
		visual_transferout(_Context->buffer_Dbio, 3780, pDbio);
		visual_transferout(_Context->buffer_Prio, 3604, pPrio);
		visual_transferout((void *) 0, 0, pProcName);
		if ( pProcName != (char *) 0)
			*((int*)pProcName) = _Context->value_ProcName;
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
		visual_transferout(_Context->buffer_Syntax, 424, pSyntax);
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
		visual_transferout((void *) 0, 0, pBreakKey);
		if ( pBreakKey != (char *) 0)
			*((int*)pBreakKey) = _Context->value_BreakKey;
		visual_transferout((void *) 0, 0, pHexaView);
		if ( pHexaView != (char *) 0)
			*((int*)pHexaView) = _Context->value_HexaView;
		visual_transferout(_Context->buffer_StatusBar, 90, pStatusBar);
		}
	_Context=liberate(_Context);

	return(result);
}
private int on_Dbio_show() {
	on_EditorColour_event();
	WindowEditorLoseFocus();
	if(WindowEditorOnEvent()==-1){
	Disassembler(_Context->buffer_Dbio,3780,36,105);
	visual_frame(61,70,840+2,576+2,5);
visual_text(61+1,70+1,840,576,vfh[1],16,0,_Context->buffer_Dbio,3780,0);
;
	}
	WindowEditorGetFocus();
	on_BreakManager_event();
	return(-1);
}
private int on_Prio_show() {
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
	return(-1);
}
private int on_vListe_show() {
	int l;
	void*DebugPositVariable(int);
	void*firstvariable;
	memset(_Context->buffer_vListe,' ',3638);
	if((firstvariable=DebugPositVariable(_Context->value_vBar))!=(void*)0){
	for(l=1;l<=34;l++){
	if ( l > 0 ) { _Context->row_vListe=&_Context->buffer_vListe[l-1][0]; } ;
	DebugVariableInfo(
	(l-1),firstvariable,
	(_Context->row_vListe+0),9,
	(_Context->row_vListe+9),33,
	(_Context->row_vListe+42),9,
	(_Context->row_vListe+51),56);
	}
	}
		visual_table(30,80,860+2,560+2,vfh[1],0,0,_Context->msg_vListe[_Context->language],_Context->buffer_vListe,0x4401,"(W8,W32,W8,$)");
;
	return(-1);
}
private int on_vBar_show() {
	_Context->max_vBar=DebugGlobalVariableCount();
		visual_scrollbar(892,80,20,560,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
;
	return(-1);
}

public	int	visual_debug_show()
{
	_Context->language = visual_national_language(-1);
	visual_freeze();
	visual_window(0,0,1000,700,vfh[2],_Context->msg_Main[_Context->language],strlen(_Context->msg_Main[_Context->language]),0x7);
	visual_filzone(926,56,64,604,28,11);
	if (_Context->page_number == 1 ) {
	_Context->trigger_ProgramSource=visual_trigger_code(_Context->msg_ProgramSource[_Context->language],strlen(_Context->msg_ProgramSource[_Context->language]));
	visual_tabpage(20,30,900,630,vfh[2],_Context->msg_ProgramSource[_Context->language],strlen(_Context->msg_ProgramSource[_Context->language]),0,34);
	} else {
		visual_tabpage(20,30,900,630,vfh[2],_Context->msg_ProgramSource[_Context->language],strlen(_Context->msg_ProgramSource[_Context->language]),0,32);
		}
	if (_Context->page_number == 1 ) {
	visual_image(20,56,892,597,_Context->msg_Auto4724[_Context->language],3);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(30,68,877,582,2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(33,70,24+2,576+2,5);
	visual_text(33+1,70+1,24,576,vfh[1],0,0,_Context->buffer_BreakManager,108,3);
		}
	_Context->trigger_Exit=visual_trigger_code(_Context->msg_Exit[_Context->language],strlen(_Context->msg_Exit[_Context->language]));
	visual_button(934,594,48,48,vfh[1],16,0,_Context->msg_Exit[_Context->language],strlen(_Context->msg_Exit[_Context->language]),16);
	_Context->trigger_StepInto=visual_trigger_code(_Context->msg_StepInto[_Context->language],strlen(_Context->msg_StepInto[_Context->language]));
	visual_button(934,80,48,48,vfh[1],16,0,_Context->msg_StepInto[_Context->language],strlen(_Context->msg_StepInto[_Context->language]),16);
	_Context->trigger_Goto=visual_trigger_code(_Context->msg_Goto[_Context->language],strlen(_Context->msg_Goto[_Context->language]));
	visual_button(934,130,48,48,vfh[1],27,0,_Context->msg_Goto[_Context->language],strlen(_Context->msg_Goto[_Context->language]),16);
	_Context->trigger_Break=visual_trigger_code(_Context->msg_Break[_Context->language],strlen(_Context->msg_Break[_Context->language]));
	visual_button(934,180,48,48,vfh[1],27,0,_Context->msg_Break[_Context->language],strlen(_Context->msg_Break[_Context->language]),16);
	_Context->trigger_ClearBreak=visual_trigger_code(_Context->msg_ClearBreak[_Context->language],strlen(_Context->msg_ClearBreak[_Context->language]));
	visual_button(934,330,48,48,vfh[1],28,28,_Context->msg_ClearBreak[_Context->language],strlen(_Context->msg_ClearBreak[_Context->language]),16);
	_Context->trigger_Run=visual_trigger_code(_Context->msg_Run[_Context->language],strlen(_Context->msg_Run[_Context->language]));
	visual_button(934,230,48,48,vfh[1],16,0,_Context->msg_Run[_Context->language],strlen(_Context->msg_Run[_Context->language]),16);
	_Context->trigger_View=visual_trigger_code(_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]));
	visual_button(934,280,48,48,vfh[1],28,28,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),16);
	if (_Context->page_number == 1 ) {
	(void) on_Dbio_show();
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ProgramOutput=visual_trigger_code(_Context->msg_ProgramOutput[_Context->language],strlen(_Context->msg_ProgramOutput[_Context->language]));
	visual_tabpage(20,30,900,630,vfh[2],_Context->msg_ProgramOutput[_Context->language],strlen(_Context->msg_ProgramOutput[_Context->language]),134,34);
	} else {
		visual_tabpage(20,30,900,630,vfh[2],_Context->msg_ProgramOutput[_Context->language],strlen(_Context->msg_ProgramOutput[_Context->language]),134,32);
		}
	if (_Context->page_number == 2 ) {
	visual_image(20,56,894,598,_Context->msg_Auto4725[_Context->language],3);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(28,68,857,584,2);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Prio_show();
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(888,68,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);
		}
	if (_Context->page_number == 2 ) {
	visual_scrollbar(30,630,855,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DebugControl=visual_trigger_code(_Context->msg_DebugControl[_Context->language],strlen(_Context->msg_DebugControl[_Context->language]));
	visual_tabpage(20,30,900,630,vfh[2],_Context->msg_DebugControl[_Context->language],strlen(_Context->msg_DebugControl[_Context->language]),267,34);
	} else {
		visual_tabpage(20,30,900,630,vfh[2],_Context->msg_DebugControl[_Context->language],strlen(_Context->msg_DebugControl[_Context->language]),267,32);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(30,70,880,580,4);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,80,670,22,vfh[4],27,0,_Context->msg_Auto1955[_Context->language],strlen(_Context->msg_Auto1955[_Context->language]),770);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,110,240,20,vfh[3],27,0,_Context->msg_Auto6301[_Context->language],strlen(_Context->msg_Auto6301[_Context->language]),258);
		}
	if (_Context->page_number == 3 ) {
	visual_text(290,110,170,20,vfh[3],27,0,_Context->msg_Auto6303[_Context->language],strlen(_Context->msg_Auto6303[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,110,170,20,vfh[3],27,0,_Context->msg_Auto6305[_Context->language],strlen(_Context->msg_Auto6305[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(700,110,165,20,vfh[3],27,0,_Context->msg_Auto6307[_Context->language],strlen(_Context->msg_Auto6307[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,310,420,20,vfh[3],27,0,_Context->msg_Auto6309[_Context->language],strlen(_Context->msg_Auto6309[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,260,420,20,vfh[3],27,0,_Context->msg_Auto6311[_Context->language],strlen(_Context->msg_Auto6311[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,310,350,20,vfh[3],27,0,_Context->msg_Auto6313[_Context->language],strlen(_Context->msg_Auto6313[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(410,486,483,20,vfh[3],27,0,_Context->msg_Auto6315[_Context->language],strlen(_Context->msg_Auto6315[_Context->language]),1281);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,160,350,20,vfh[3],27,0,_Context->msg_Auto6317[_Context->language],strlen(_Context->msg_Auto6317[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,160,420,20,vfh[3],27,0,_Context->msg_Auto6319[_Context->language],strlen(_Context->msg_Auto6319[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,210,420,20,vfh[3],27,0,_Context->msg_Auto6321[_Context->language],strlen(_Context->msg_Auto6321[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,210,348,20,vfh[3],27,0,_Context->msg_Auto6323[_Context->language],strlen(_Context->msg_Auto6323[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,360,420,20,vfh[3],27,0,_Context->msg_Auto6325[_Context->language],strlen(_Context->msg_Auto6325[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,260,350,20,vfh[3],27,0,_Context->msg_Auto6327[_Context->language],strlen(_Context->msg_Auto6327[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(216,580,150,16,vfh[2],27,0,_Context->msg_Auto1618[_Context->language],strlen(_Context->msg_Auto1618[_Context->language]),259);
	visual_frame(216,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(40,580,150,16,vfh[2],27,0,_Context->msg_Auto1619[_Context->language],strlen(_Context->msg_Auto1619[_Context->language]),259);
	visual_frame(40,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(392,580,150,16,vfh[2],27,0,_Context->msg_Auto1620[_Context->language],strlen(_Context->msg_Auto1620[_Context->language]),259);
	visual_frame(392,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(568,580,150,16,vfh[2],27,0,_Context->msg_Auto1951[_Context->language],strlen(_Context->msg_Auto1951[_Context->language]),259);
	visual_frame(568,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_text(744,580,150,16,vfh[2],27,0,_Context->msg_Auto1964[_Context->language],strlen(_Context->msg_Auto1964[_Context->language]),259);
	visual_frame(744,596,150,40,3);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,130,240,440,vfh[1],0,0,parse_selection(GetProcedureNames(),&_Context->value_ProcName),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(290,130,170,440,vfh[1],0,0,parse_selection(GetSegmentNames(),&_Context->value_SegmName),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,130,200,440,vfh[1],0,0,parse_selection(GetGlobalNames(),&_Context->value_GlobNames),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(700,130,200,444,vfh[1],0,0,parse_selection(GetLocalNames(),&_Context->value_LocalNames),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,180,420,390,vfh[1],27,0,parse_selection(GetAssignList(),&_Context->value_AssignList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,180,429,404,vfh[1],27,0,parse_selection(GetRegisterList(_Context->value_HexaView),&_Context->value_RegisterList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,230,420,350,vfh[1],27,0,parse_selection(GetAttachList(),&_Context->value_AttachList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,230,429,351,vfh[1],27,0,parse_selection(GetStackList(),&_Context->value_StackList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,280,420,290,vfh[1],27,0,parse_selection(GetLibraryList(),&_Context->value_LibraryList),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,280,403,298,vfh[1],27,0,parse_selection(GetObserveList(),&_Context->value_ObserveList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DeleteObservation=visual_trigger_code(_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]));
	visual_button(874,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_RemoveBreak=visual_trigger_code(_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]));
	visual_button(440,330,20,19,vfh[2],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,330,404,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DeleteWatch=visual_trigger_code(_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]));
	visual_button(876,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(40,380,400,190,vfh[1],27,0,parse_selection(GetSourceList(),&_Context->value_SourceList),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_InspectSource=visual_trigger_code(_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]));
	visual_button(440,380,20,19,vfh[2],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(44,504,848+2,64+2,5);
	visual_text(44+1,504+1,848,64,vfh[1],16,0,_Context->buffer_Syntax,424,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(50,410,675,24,vfh[4],27,0,_Context->msg_Auto5722[_Context->language],strlen(_Context->msg_Auto5722[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(50,440,112,16,vfh[2],27,0,_Context->msg_auto6060[_Context->language],strlen(_Context->msg_auto6060[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(200,440,112,16,vfh[2],27,0,_Context->msg_auto6061[_Context->language],strlen(_Context->msg_auto6061[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(340,440,112,16,vfh[2],27,0,_Context->msg_auto6062[_Context->language],strlen(_Context->msg_auto6062[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(470,440,112,16,vfh[2],27,0,_Context->msg_auto6063[_Context->language],strlen(_Context->msg_auto6063[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_text(610,440,126,16,vfh[2],27,0,_Context->msg_auto6064[_Context->language],strlen(_Context->msg_auto6064[_Context->language]),259);
		}
	if (_Context->page_number == 3 ) {
	visual_select(50,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(200,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(340,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(470,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),768);
		}
	if (_Context->page_number == 3 ) {
	visual_select(610,460,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),768);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_EditorColour=visual_trigger_code(_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]));
	visual_button(750,450,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),0);
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
	visual_button(220,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SetBreakBS=visual_trigger_code(_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]));
	visual_button(292,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_MultipleWatch=visual_trigger_code(_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]));
	visual_button(396,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_SingleWatch=visual_trigger_code(_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]));
	visual_button(468,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ObserveGlobal=visual_trigger_code(_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]));
	visual_button(572,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_InspectGlobal=visual_trigger_code(_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]));
	visual_button(644,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ObserveLocal=visual_trigger_code(_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]));
	visual_button(748,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_InspectLocal=visual_trigger_code(_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]));
	visual_button(820,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),0);
		}
	_Context->trigger_BreakKey=visual_trigger_code(_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]));
	visual_switch(940,410,40,16,vfh[1],12,15,_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]),_Context->value_BreakKey);
	_Context->trigger_AsmList=visual_trigger_code(_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]));
	visual_switch(940,430,40,16,vfh[1],12,15,_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]),_Context->value_AsmList);
	_Context->trigger_HexaView=visual_trigger_code(_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]));
	visual_switch(940,390,40,16,vfh[1],12,15,_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]),_Context->value_HexaView);
	visual_frame(20,664,900+2,24+2,5);
	visual_text(20+1,664+1,900,24,vfh[7],16,0,_Context->buffer_StatusBar,90,0);
	if (_Context->page_number == 4 ) {
	_Context->trigger_VariableControl=visual_trigger_code(_Context->msg_VariableControl[_Context->language],strlen(_Context->msg_VariableControl[_Context->language]));
	visual_tabpage(20,30,900,630,vfh[2],_Context->msg_VariableControl[_Context->language],strlen(_Context->msg_VariableControl[_Context->language]),395,34);
	} else {
		visual_tabpage(20,30,900,630,vfh[2],_Context->msg_VariableControl[_Context->language],strlen(_Context->msg_VariableControl[_Context->language]),395,32);
		}
	if (_Context->page_number == 4 ) {
	(void) on_vListe_show();
		}
	if (_Context->page_number == 4 ) {
	(void) on_vBar_show();
		}
	visual_thaw(0,0,1000,700);

	return(0);
}
private int on_BreakManager_event() {
	int i;
	visual_freeze();
	visual_frame(33,70,24+2,576+2,5);
visual_text(33+1,70+1,24,576,vfh[1],0,0,_Context->buffer_BreakManager,108,3);
;
	if(!(is_idb_active())){
	for(i=0;i<36;i++){
	if(IsBreakPoint(i)){
	_Context->y_BreakPoint=((70)+(i*16));
		visual_image(_Context->x_BreakPoint,_Context->y_BreakPoint,_Context->w_BreakPoint,_Context->h_BreakPoint,_Context->msg_BreakPoint[_Context->language],3);
;
	}
	}
	i=editorOnGetFocus();
	_Context->y_DebugCursor=((70)+(i*16));
	}
	else _Context->y_DebugCursor=70;
		visual_image(_Context->x_DebugCursor,_Context->y_DebugCursor,_Context->w_DebugCursor,_Context->h_DebugCursor,_Context->msg_DebugCursor[_Context->language],3);
;
	visual_thaw(33,70,24,576);
	return(-1);
}
private int on_Exit_event() {
	return(27);
	return(-1);
}
private int on_StepInto_event() {
	if(_Context->page_number!=1){
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	visual_debug_show();
	}
	ExecuteSingleStep();
	on_StatusBar_event();
	return(-1);
}
private int on_Goto_event() {
	if(_Context->page_number==1){
	if(GotoSourceLine()!=0){
	on_Run_event();
	}
	}
	return(-1);
}
private int on_Break_event() {
	if(_Context->page_number==1){
	SetSourceBreakPoint(1);
	}
	return(-1);
}
private int on_ClearBreak_event() {
	ClearSourceBreakPoint(1);
	return(-1);
}
private int on_Run_event() {
	if(_Context->page_number!=1){
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	visual_debug_show();
	}
	WindowEditorLoseFocus();
	ExecuteTillBreak();
	visual_debug_show();
	on_StatusBar_event();
	WindowEditorGetFocus();
	return(-1);
}
private int on_View_event() {
	int i;
	if(_Context->page_number==1){
	if(!(_Context->value_HexaView)){
	DebugViewVariable(_Context->buffer_Syntax,424,_Context->value_HexaView);
	for(i=0;i<90;i++){
	if(i<424)
	_Context->buffer_StatusBar[i]=_Context->buffer_Syntax[i];
	else break;
	}
	visual_frame(20,664,900+2,24+2,5);
visual_text(20+1,664+1,900,24,vfh[7],16,0,_Context->buffer_StatusBar,90,0);
;
	while(1){
	while(visual_getch()!=256);
	if(visual_event(1)==_MIMO_UP)
	break;
	}
	on_StatusBar_event();
	}
	else DebugViewMemory();
	}
	return(-1);
}
private int on_Dbio_event() {
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	return(-1);
}
private int on_VSB_event() {
		visual_scrollbar(888,68,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);
;
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
		return(-1);
}

private int on_VSB_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (68+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VSB -= 1;
		if (_Context->value_VSB < 0) 
			_Context->value_VSB = 0;
		(void) on_VSB_event();
	visual_scrollbar(888,68,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
		return(-1);
		}
	if ( visual_event(6) > (68+560-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_VSB += 1;
		if (_Context->value_VSB > (_Context->max_VSB-_Context->limit_VSB)) 
			_Context->value_VSB = (_Context->max_VSB-_Context->limit_VSB);
		(void) on_VSB_event();
	visual_scrollbar(888,68,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
		return(-1);
		}
	visual_scrollbar(888,68,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_VSB;
		_Context->value_VSB = (((visual_event(6) - (68+20)) * _Context->max_VSB) / (560 - (2 * 20)));
		if (_Context->value_VSB < 0) 
			_Context->value_VSB = 0;
		else if (_Context->value_VSB > (_Context->max_VSB-_Context->limit_VSB)) 
			_Context->value_VSB = (_Context->max_VSB-_Context->limit_VSB);
		if (_Context->value_VSB != aty) {
		(void) on_VSB_event();
	visual_scrollbar(888,68,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(888,68,20,560,vfh[1],0,0,_Context->value_VSB,_Context->limit_VSB,_Context->max_VSB,3);

	return(1);
}
private int on_HSB_event() {
		visual_scrollbar(30,630,855,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);
;
	ProgramWindowOnShow(_Context->value_HSB,_Context->value_VSB);
	return(-1);
}

private int on_HSB_action() {
	int status;
	int atx=visual_event(7);
	int tox=visual_event(7);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }

	if ( visual_event(7) < (30+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HSB -= 1;
		if (_Context->value_HSB < 0) 
			_Context->value_HSB = 0;
		(void) on_HSB_event();
	visual_scrollbar(30,630,855,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
		return(-1);
		}
	if ( visual_event(7) > (30+855-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_HSB += 1;
		if (_Context->value_HSB > (_Context->max_HSB-_Context->limit_HSB)) 
			_Context->value_HSB = (_Context->max_HSB-_Context->limit_HSB);
		(void) on_HSB_event();
	visual_scrollbar(30,630,855,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
		return(-1);
		}
	visual_scrollbar(30,630,855,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);

	do {
		while(visual_getch() != 256);
		atx = _Context->value_HSB;
		_Context->value_HSB = (((visual_event(7) - (30+20)) * _Context->max_HSB) / (855 - (2 * 20)));
		if (_Context->value_HSB < 0) 
			_Context->value_HSB = 0;
		else if (_Context->value_HSB > (_Context->max_HSB-_Context->limit_HSB)) 
			_Context->value_HSB = (_Context->max_HSB-_Context->limit_HSB);
		if (_Context->value_HSB != atx) {
		(void) on_HSB_event();
	visual_scrollbar(30,630,855,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(30,630,855,20,vfh[1],27,0,_Context->value_HSB,_Context->limit_HSB,_Context->max_HSB,3);

	return(1);
}
private int on_RemoveBreak_event() {
	DeleteBreakPoint(_Context->value_BreakList);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_DeleteWatch_event() {
	DeleteWatchPoint(_Context->value_WatchList);
		visual_select(470,330,404,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_InspectSource_event() {
		/* Dbio */
	/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
	visual_debug_show();
	_Context->focus_item=10;
;
	WindowEditorFileNumber(_Context->value_SourceList,0);
	return(-1);
}
private int on_Syntax_event() {
	WindowEditorOnExec(_Context->buffer_Syntax,424);
	return(-1);
}
private int on_EditorColour_event() {
	editorOnColour(1,_Context->value_AED_NORMAL,_Context->value_AED_QUOTE,_Context->value_AED_KEYWORD,_Context->value_AED_COMMENT,_Context->value_AED_PUNCTUATE);
	return(-1);
}
private int on_SetBreakAP_event() {
	ControlWindowSetBreak(1,1,_Context->value_ProcName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakBP_event() {
	ControlWindowSetBreak(1,0,_Context->value_ProcName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakAS_event() {
	ControlWindowSetBreak(0,1,_Context->value_SegmName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_SetBreakBS_event() {
	ControlWindowSetBreak(0,0,_Context->value_SegmName,0);
		visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),768);

	return(-1);
}
private int on_MultipleWatch_event() {
	ControlWindowSetBreak(2,1,_Context->value_GlobNames,0);
		visual_select(470,330,404,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_SingleWatch_event() {
	ControlWindowSetBreak(2,0,_Context->value_GlobNames,0);
		visual_select(470,330,404,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),768);

	return(-1);
}
private int on_InspectGlobal_event() {
	if(DebugShowVariable(_Context->buffer_Syntax,424,_Context->value_GlobNames,0,_Context->value_HexaView)!=0){
	visual_frame(44,504,848+2,64+2,5);
visual_text(44+1,504+1,848,64,vfh[1],16,0,_Context->buffer_Syntax,424,0);
;
	}
	return(-1);
}
private int on_InspectLocal_event() {
	if(DebugShowVariable(_Context->buffer_Syntax,424,_Context->value_LocalNames,1,_Context->value_HexaView)!=0){
	visual_frame(44,504,848+2,64+2,5);
visual_text(44+1,504+1,848,64,vfh[1],16,0,_Context->buffer_Syntax,424,0);
;
	}
	return(-1);
}
private int on_BreakKey_event() {
	if(_Context->value_BreakKey)
	strcpy(_Context->buffer_Syntax,"K/1B");
	else strcpy(_Context->buffer_Syntax,"K/00");
	on_Syntax_event();
	return(-1);
}
private int on_AsmList_event() {
	if(_Context->value_AsmList)
	strcpy(_Context->buffer_Syntax,"LA0");
	else strcpy(_Context->buffer_Syntax,"LA1");
	on_Syntax_event();
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	visual_debug_show();
	return(-1);
}
private int on_HexaView_event() {
		/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
	return(-1);
}
private int on_StatusBar_event() {
	on_StatusBar_create();
	visual_frame(20,664,900+2,24+2,5);
visual_text(20+1,664+1,900,24,vfh[7],16,0,_Context->buffer_StatusBar,90,0);
;
	on_Dbio_show();
	return(-1);
}
private int on_vListe_event() {
	int l;
	int i;
	l=_Context->value_vListe;
	if(l!=0){
	if ( l > 0 ) { _Context->row_vListe=&_Context->buffer_vListe[l-1][0]; } ;
	DebugDumpZone((_Context->row_vListe+9),33,(_Context->row_vListe+42),9);
	}
	return(-1);
}
private int on_vBar_event() {
	on_vListe_show();
	return(-1);
}

private int on_vBar_action() {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (80+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar -= 1;
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		(void) on_vBar_event();
	visual_scrollbar(892,80,20,560,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	if ( visual_event(6) > (80+560-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_vBar += 1;
		if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		(void) on_vBar_event();
	visual_scrollbar(892,80,20,560,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
		return(-1);
		}
	visual_scrollbar(892,80,20,560,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	do {
		while(visual_getch() != 256);
		aty = _Context->value_vBar;
		_Context->value_vBar = (((visual_event(6) - (80+20)) * _Context->max_vBar) / (560 - (2 * 20)));
		if (_Context->value_vBar < 0) 
			_Context->value_vBar = 0;
		else if (_Context->value_vBar > (_Context->max_vBar-_Context->limit_vBar)) 
			_Context->value_vBar = (_Context->max_vBar-_Context->limit_vBar);
		if (_Context->value_vBar != aty) {
		(void) on_vBar_event();
	visual_scrollbar(892,80,20,560,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);
			}

		}
	while (visual_event(1) != _MIMO_UP);	visual_scrollbar(892,80,20,560,vfh[1],0,0,_Context->value_vBar,_Context->limit_vBar,_Context->max_vBar,259);

	return(1);
}


public	int	visual_debug_event()
{
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ProgramSource == mb ) return(2);
		if (_Context->trigger_Exit == mb ) return(3);
		if (_Context->trigger_StepInto == mb ) return(4);
		if (_Context->trigger_Goto == mb ) return(5);
		if (_Context->trigger_Break == mb ) return(6);
		if (_Context->trigger_ClearBreak == mb ) return(7);
		if (_Context->trigger_Run == mb ) return(8);
		if (_Context->trigger_View == mb ) return(9);
		if (_Context->trigger_ProgramOutput == mb ) return(11);
		if (_Context->trigger_DebugControl == mb ) return(15);
		if (_Context->trigger_DeleteObservation == mb ) return(26);
		if (_Context->trigger_RemoveBreak == mb ) return(28);
		if (_Context->trigger_DeleteWatch == mb ) return(30);
		if (_Context->trigger_InspectSource == mb ) return(32);
		if (_Context->trigger_EditorColour == mb ) return(39);
		if (_Context->trigger_SetBreakAP == mb ) return(40);
		if (_Context->trigger_SetBreakBP == mb ) return(41);
		if (_Context->trigger_SetBreakAS == mb ) return(42);
		if (_Context->trigger_SetBreakBS == mb ) return(43);
		if (_Context->trigger_MultipleWatch == mb ) return(44);
		if (_Context->trigger_SingleWatch == mb ) return(45);
		if (_Context->trigger_ObserveGlobal == mb ) return(46);
		if (_Context->trigger_InspectGlobal == mb ) return(47);
		if (_Context->trigger_ObserveLocal == mb ) return(48);
		if (_Context->trigger_InspectLocal == mb ) return(49);
		if (_Context->trigger_BreakKey == mb ) return(50);
		if (_Context->trigger_AsmList == mb ) return(51);
		if (_Context->trigger_HexaView == mb ) return(52);
		if (_Context->trigger_VariableControl == mb ) return(54);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x1031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	if (mt & _MIMO_UP) {
	if ((mx >= 979 )  
	&&  (my >= 4 )  
	&&  (mx <= 995 )  
	&&  (my <= 20 )) {
		return(1);	/* Main */

		}
	if ((mx >= 963 )  
	&&  (my >= 4 )  
	&&  (mx <= 979 )  
	&&  (my <= 20 )) {
		if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vexadb.htm");
			};
		return(-1);	/* Main */

		}
	if ((mx >= 947 )  
	&&  (my >= 4 )  
	&&  (mx <= 963 )  
	&&  (my <= 20 )) {
		if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		visual_debug_show();
		return(-1);	/* Main */

		}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if ((mx >= 20 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 153 ) 
		&&  (my <= 54 )) {
			return(2); /* ProgramSource */
			}
		}
	if (( mx >= 934 ) 
	&&  ( my >= 594 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 642 )) {
		return(3); /* Exit */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 80 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 128 )) {
		return(4); /* StepInto */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 130 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 178 )) {
		return(5); /* Goto */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 180 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 228 )) {
		return(6); /* Break */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 330 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 378 )) {
		return(7); /* ClearBreak */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 230 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 278 )) {
		return(8); /* Run */
		}
	if (( mx >= 934 ) 
	&&  ( my >= 280 ) 
	&&  ( mx <= 982 ) 
	&&  ( my <= 328 )) {
		return(9); /* View */
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= 61 ) 
		&&  ( my >= 70 ) 
		&&  ( mx <= 901 ) 
		&&  ( my <= 646 )) {
			return(10); /* Dbio */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if ((mx >= 154 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 286 ) 
		&&  (my <= 54 )) {
			return(11); /* ProgramOutput */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 70 ) 
		&&  ( mx <= 880 ) 
		&&  ( my <= 626 )) {
			return(12); /* Prio */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 888 ) 
		&&  ( my >= 68 ) 
		&&  ( mx <= 908 ) 
		&&  ( my <= 628 )) {
			return(13); /* VSB */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 630 ) 
		&&  ( mx <= 885 ) 
		&&  ( my <= 650 )) {
			return(14); /* HSB */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if ((mx >= 287 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 414 ) 
		&&  (my <= 54 )) {
			return(15); /* DebugControl */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 280 ) 
		&&  (my <= 146 )) {
			return(16); /* ProcName */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 290 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 146 )) {
			return(17); /* SegmName */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 670 ) 
		&&  (my <= 146 )) {
			return(18); /* GlobNames */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 700 ) 
		&&  (my >= 130 ) 
		&&  (mx <= 900 ) 
		&&  (my <= 146 )) {
			return(19); /* LocalNames */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 180 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 196 )) {
			return(20); /* AssignList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 180 ) 
		&&  (mx <= 899 ) 
		&&  (my <= 196 )) {
			return(21); /* RegisterList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 230 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 246 )) {
			return(22); /* AttachList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 230 ) 
		&&  (mx <= 899 ) 
		&&  (my <= 246 )) {
			return(23); /* StackList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 460 ) 
		&&  (my <= 296 )) {
			return(24); /* LibraryList */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 280 ) 
		&&  (mx <= 873 ) 
		&&  (my <= 296 )) {
			return(25); /* ObserveList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 874 ) 
		&&  ( my >= 280 ) 
		&&  ( mx <= 894 ) 
		&&  ( my <= 299 )) {
			return(26); /* DeleteObservation */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 440 ) 
		&&  (my <= 346 )) {
			return(27); /* BreakList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 440 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 460 ) 
		&&  ( my <= 349 )) {
			return(28); /* RemoveBreak */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 330 ) 
		&&  (mx <= 874 ) 
		&&  (my <= 346 )) {
			return(29); /* WatchList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 876 ) 
		&&  ( my >= 330 ) 
		&&  ( mx <= 896 ) 
		&&  ( my <= 349 )) {
			return(30); /* DeleteWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 40 ) 
		&&  (my >= 380 ) 
		&&  (mx <= 440 ) 
		&&  (my <= 396 )) {
			return(31); /* SourceList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 440 ) 
		&&  ( my >= 380 ) 
		&&  ( mx <= 460 ) 
		&&  ( my <= 399 )) {
			return(32); /* InspectSource */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 44 ) 
		&&  ( my >= 504 ) 
		&&  ( mx <= 892 ) 
		&&  ( my <= 568 )) {
			return(33); /* Syntax */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 50 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 170 ) 
		&&  (my <= 476 )) {
			return(34); /* AED_NORMAL */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 200 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 320 ) 
		&&  (my <= 476 )) {
			return(35); /* AED_QUOTE */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 340 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 452 ) 
		&&  (my <= 476 )) {
			return(36); /* AED_KEYWORD */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 470 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 582 ) 
		&&  (my <= 476 )) {
			return(37); /* AED_COMMENT */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= 610 ) 
		&&  (my >= 460 ) 
		&&  (mx <= 730 ) 
		&&  (my <= 476 )) {
			return(38); /* AED_PUNCTUATE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 750 ) 
		&&  ( my >= 450 ) 
		&&  ( mx <= 890 ) 
		&&  ( my <= 482 )) {
			return(39); /* EditorColour */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 44 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 114 ) 
		&&  ( my <= 632 )) {
			return(40); /* SetBreakAP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 116 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 186 ) 
		&&  ( my <= 632 )) {
			return(41); /* SetBreakBP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 220 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 290 ) 
		&&  ( my <= 632 )) {
			return(42); /* SetBreakAS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 292 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 362 ) 
		&&  ( my <= 632 )) {
			return(43); /* SetBreakBS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 396 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 466 ) 
		&&  ( my <= 632 )) {
			return(44); /* MultipleWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 468 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 538 ) 
		&&  ( my <= 632 )) {
			return(45); /* SingleWatch */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 572 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 642 ) 
		&&  ( my <= 632 )) {
			return(46); /* ObserveGlobal */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 644 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 714 ) 
		&&  ( my <= 632 )) {
			return(47); /* InspectGlobal */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 748 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 818 ) 
		&&  ( my <= 632 )) {
			return(48); /* ObserveLocal */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= 820 ) 
		&&  ( my >= 600 ) 
		&&  ( mx <= 890 ) 
		&&  ( my <= 632 )) {
			return(49); /* InspectLocal */
			}
		}
	if (( mx >= 940 ) 
	&&  ( my >= 410 ) 
	&&  ( mx <= 980 ) 
	&&  ( my <= 426 )) {
		return(50); /* BreakKey */
		}
	if (( mx >= 940 ) 
	&&  ( my >= 430 ) 
	&&  ( mx <= 980 ) 
	&&  ( my <= 446 )) {
		return(51); /* AsmList */
		}
	if (( mx >= 940 ) 
	&&  ( my >= 390 ) 
	&&  ( mx <= 980 ) 
	&&  ( my <= 406 )) {
		return(52); /* HexaView */
		}
	if (( mx >= 20 ) 
	&&  ( my >= 664 ) 
	&&  ( mx <= 920 ) 
	&&  ( my <= 688 )) {
		return(53); /* StatusBar */
		}
	if (_Context->page_number == 4 ) {
	} else {
		if ((mx >= 415 ) 
		&&  (my >= 30 ) 
		&&  (mx <= 509 ) 
		&&  (my <= 54 )) {
			return(54); /* VariableControl */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 30 ) 
		&&  ( my >= 80 ) 
		&&  ( mx <= 890 ) 
		&&  ( my <= 640 )) {
			if ((_Context->value_vListe = ((visual_event(6) - 80) / 16)) < 1)
				_Context->value_vListe=0;
else if (_Context->value_vListe > 34 )
				_Context->value_vListe=34;
			if ( _Context->value_vListe > 0 ) { _Context->row_vListe = &_Context->buffer_vListe[(_Context->value_vListe-1)][0]; } 
			_Context->column_vListe = (visual_event(7) - 30);
			if ( _Context->column_vListe < 73 ) {
				_Context->column_vListe = 1;
				}
			else if ( _Context->column_vListe < 338 ) {
				_Context->column_vListe = 2;
				}
			else if ( _Context->column_vListe < 411 ) {
				_Context->column_vListe = 3;
				}
			else if ( _Context->column_vListe < 860 ) {
				_Context->column_vListe = 4;
				}
			return(55); /* vListe */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= 892 ) 
		&&  ( my >= 80 ) 
		&&  ( mx <= 912 ) 
		&&  ( my <= 640 )) {
			return(56); /* vBar */
			}
		}

	return(-1);
}
private int on_ProgramSource_losefocus() {
	WindowEditorLoseFocus();
	return(-1);
}
private int on_ProgramOutput_losefocus() {
	ProgramWindowLoseFocus();
	return(-1);
}
private int on_StatusBar_losefocus() {
	int i;
	if(_Context->keycode==13){
	if((_Context->buffer_StatusBar[0]!='D')
	&&(_Context->buffer_StatusBar[0]!='d')){
	WindowEditorOnExec(_Context->buffer_StatusBar,90);
	}
	else{
	DebugVariableSyntax(_Context->buffer_Syntax,424,_Context->buffer_StatusBar,90,_Context->value_HexaView);
	for(i=0;i<90;i++){
	if(i<424)
	_Context->buffer_StatusBar[i]=_Context->buffer_Syntax[i];
	else break;
	}
	visual_frame(20,664,900+2,24+2,5);
visual_text(20+1,664+1,900,24,vfh[7],16,0,_Context->buffer_StatusBar,90,0);
;
	}
	_Context->keycode=0;
	}
	return(-1);
}


public	int	visual_debug_losefocus()
{
	switch (_Context->page_number) {
		case 1 : 
			(void) on_ProgramSource_losefocus();
			break;
		case 2 : 
			(void) on_ProgramOutput_losefocus();
			break;
		case 3 : 
			break;
		case 4 : 
			break;

		}
	return(0);

}
private int on_ProgramSource_getfocus() {
	return(5);
	return(-1);
}
private int on_Dbio_getfocus() {
	int event,mx,my;
	while(1){
	CheckBreakPoints(0);
	on_BreakManager_event();
	event=visual_getch();
	editorOnLoseFocus();
	if(((event>='A')&&(event<='Z'))
	||((event>='a')&&(event<='z'))){
	visual_unget_event(event);
		/* StatusBar */
	visual_debug_show();
	_Context->focus_item=53;
;
	return(0);
	}
	if((event==27)||(event&_MIMO_ALT))
	break;
	else if(event==32)
	on_StepInto_event();
	else if(event==256){
	if(((mx=visual_event(7))>61)
	&&((my=visual_event(6))>70)
	&&(mx<(61+840))
	&&(my<(70+576))){
	if(visual_event(2)==1)
	editorOnUseEvent(event);
	else if(visual_event(1)==_MIMO_DOWN)
	on_View_event();
	}
	else break;
	}
	else if(event<26){
	if(!(editorOnUseEvent(event)))
	break;
	}
	}
	return(event);
	return(-1);
}


public	int	visual_debug_focus()
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* ProgramSource */
				if (_Context->page_number == 1 ) {
					if ((_Context->keycode = on_ProgramSource_getfocus()) != -1) break;
					(void) on_ProgramSource_losefocus();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* Dbio */
				if (_Context->page_number == 1 ) {
					if ((_Context->keycode = on_Dbio_getfocus()) != -1) break;
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* ProgramOutput */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
					(void) on_ProgramOutput_losefocus();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xc :
				/* Prio */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(30+1,70+1,850,556,vfh[1],_Context->buffer_Prio,3604);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* DebugControl */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x10 :
				/* ProcName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,130,240,440,vfh[1],0,0,parse_selection(GetProcedureNames(),&_Context->value_ProcName),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* SegmName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(290,130,170,440,vfh[1],0,0,parse_selection(GetSegmentNames(),&_Context->value_SegmName),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* GlobNames */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,130,200,440,vfh[1],0,0,parse_selection(GetGlobalNames(),&_Context->value_GlobNames),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* LocalNames */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(700,130,200,444,vfh[1],0,0,parse_selection(GetLocalNames(),&_Context->value_LocalNames),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* AssignList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,180,420,390,vfh[1],27,0,parse_selection(GetAssignList(),&_Context->value_AssignList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* RegisterList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,180,429,404,vfh[1],27,0,parse_selection(GetRegisterList(_Context->value_HexaView),&_Context->value_RegisterList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* AttachList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,230,420,350,vfh[1],27,0,parse_selection(GetAttachList(),&_Context->value_AttachList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* StackList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,230,429,351,vfh[1],27,0,parse_selection(GetStackList(),&_Context->value_StackList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* LibraryList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,280,420,290,vfh[1],27,0,parse_selection(GetLibraryList(),&_Context->value_LibraryList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ObserveList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,280,403,298,vfh[1],27,0,parse_selection(GetObserveList(),&_Context->value_ObserveList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* DeleteObservation */
				if (_Context->page_number == 3 ) {
					visual_button(874,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(874,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* BreakList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,330,400,250,vfh[1],0,0,parse_selection(GetBreakPointList(),&_Context->value_BreakList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* RemoveBreak */
				if (_Context->page_number == 3 ) {
					visual_button(440,330,20,19,vfh[2],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(440,330,20,19,vfh[2],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* WatchList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,330,404,241,vfh[1],0,0,parse_selection(GetWatchPointList(),&_Context->value_WatchList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* DeleteWatch */
				if (_Context->page_number == 3 ) {
					visual_button(876,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(876,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* SourceList */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(40,380,400,190,vfh[1],27,0,parse_selection(GetSourceList(),&_Context->value_SourceList),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* InspectSource */
				if (_Context->page_number == 3 ) {
					visual_button(440,380,20,19,vfh[2],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(440,380,20,19,vfh[2],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* Syntax */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(44+1,504+1,848,64,vfh[1],_Context->buffer_Syntax,424);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* AED_NORMAL */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(50,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* AED_QUOTE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(200,460,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* AED_KEYWORD */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(340,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* AED_COMMENT */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(470,460,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* AED_PUNCTUATE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(610,460,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* EditorColour */
				if (_Context->page_number == 3 ) {
					visual_button(750,450,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(750,450,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* SetBreakAP */
				if (_Context->page_number == 3 ) {
					visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* SetBreakBP */
				if (_Context->page_number == 3 ) {
					visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* SetBreakAS */
				if (_Context->page_number == 3 ) {
					visual_button(220,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(220,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* SetBreakBS */
				if (_Context->page_number == 3 ) {
					visual_button(292,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(292,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* MultipleWatch */
				if (_Context->page_number == 3 ) {
					visual_button(396,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(396,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* SingleWatch */
				if (_Context->page_number == 3 ) {
					visual_button(468,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(468,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* ObserveGlobal */
				if (_Context->page_number == 3 ) {
					visual_button(572,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(572,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* InspectGlobal */
				if (_Context->page_number == 3 ) {
					visual_button(644,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(644,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* ObserveLocal */
				if (_Context->page_number == 3 ) {
					visual_button(748,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(748,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* InspectLocal */
				if (_Context->page_number == 3 ) {
					visual_button(820,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),2);
					_Context->keycode = visual_getch();
					visual_button(820,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* BreakKey */
				visual_switch(940,410,40,16,vfh[1],12,15,_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]),(_Context->value_BreakKey |2));
				_Context->keycode = visual_getch();
				visual_switch(940,410,40,16,vfh[1],12,15,_Context->msg_BreakKey[_Context->language],strlen(_Context->msg_BreakKey[_Context->language]),(_Context->value_BreakKey |0));
					/* ProgramSource */
	visual_debug_losefocus();
	_Context->page_number = 1;
	visual_debug_show();
	_Context->focus_item=2;
;
				break;
			case	0x33 :
				/* AsmList */
				visual_switch(940,430,40,16,vfh[1],12,15,_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]),(_Context->value_AsmList |2));
				_Context->keycode = visual_getch();
				visual_switch(940,430,40,16,vfh[1],12,15,_Context->msg_AsmList[_Context->language],strlen(_Context->msg_AsmList[_Context->language]),(_Context->value_AsmList |0));
				break;
			case	0x34 :
				/* HexaView */
				visual_switch(940,390,40,16,vfh[1],12,15,_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]),(_Context->value_HexaView |2));
				_Context->keycode = visual_getch();
				visual_switch(940,390,40,16,vfh[1],12,15,_Context->msg_HexaView[_Context->language],strlen(_Context->msg_HexaView[_Context->language]),(_Context->value_HexaView |0));
				break;
			case	0x35 :
				/* StatusBar */
				_Context->keycode = visual_edit(20+1,664+1,900,24,vfh[7],_Context->buffer_StatusBar,90);
				(void) on_StatusBar_losefocus();
			break;
			case	0x36 :
				/* VariableControl */
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
			visual_debug_losefocus();
			_Context->page_number=1;
			_Context->focus_item=1;
			visual_debug_show();
			continue;
		case	0x2 :
			visual_debug_losefocus();
			_Context->page_number=4;
			_Context->focus_item=56;
			visual_debug_show();
			continue;
		case	0x3 :
			visual_debug_losefocus();
			if ( _Context->page_number < 4 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_debug_show();
			continue;
		case	0x12 :
			visual_debug_losefocus();
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			visual_debug_show();
			continue;
			case	0x100 :
				if ((retcode=visual_debug_event()) == -1)
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
							visual_debug_losefocus();
							_Context->page_number = 1;
							visual_debug_show();
							}
						continue;
					case	0x3 :
						/* Exit */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,594,48,48,vfh[1],16,0,_Context->msg_Exit[_Context->language],strlen(_Context->msg_Exit[_Context->language]),18);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,594,48,48,vfh[1],16,0,_Context->msg_Exit[_Context->language],strlen(_Context->msg_Exit[_Context->language]),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Exit_event()) != -1) break;

							}
						continue;
					case	0x4 :
						/* StepInto */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,80,48,48,vfh[1],16,0,_Context->msg_StepInto[_Context->language],strlen(_Context->msg_StepInto[_Context->language]),18);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,80,48,48,vfh[1],16,0,_Context->msg_StepInto[_Context->language],strlen(_Context->msg_StepInto[_Context->language]),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_StepInto_event()) != -1) break;

							}
						continue;
					case	0x5 :
						/* Goto */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,130,48,48,vfh[1],27,0,_Context->msg_Goto[_Context->language],strlen(_Context->msg_Goto[_Context->language]),18);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,130,48,48,vfh[1],27,0,_Context->msg_Goto[_Context->language],strlen(_Context->msg_Goto[_Context->language]),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Goto_event()) != -1) break;

							}
						continue;
					case	0x6 :
						/* Break */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,180,48,48,vfh[1],27,0,_Context->msg_Break[_Context->language],strlen(_Context->msg_Break[_Context->language]),18);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,180,48,48,vfh[1],27,0,_Context->msg_Break[_Context->language],strlen(_Context->msg_Break[_Context->language]),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Break_event()) != -1) break;

							}
						continue;
					case	0x7 :
						/* ClearBreak */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,330,48,48,vfh[1],28,28,_Context->msg_ClearBreak[_Context->language],strlen(_Context->msg_ClearBreak[_Context->language]),18);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,330,48,48,vfh[1],28,28,_Context->msg_ClearBreak[_Context->language],strlen(_Context->msg_ClearBreak[_Context->language]),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ClearBreak_event()) != -1) break;

							}
						continue;
					case	0x8 :
						/* Run */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,230,48,48,vfh[1],16,0,_Context->msg_Run[_Context->language],strlen(_Context->msg_Run[_Context->language]),18);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,230,48,48,vfh[1],16,0,_Context->msg_Run[_Context->language],strlen(_Context->msg_Run[_Context->language]),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Run_event()) != -1) break;

							}
						continue;
					case	0x9 :
						/* View */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(934,280,48,48,vfh[1],28,28,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),18);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(934,280,48,48,vfh[1],28,28,_Context->msg_View[_Context->language],strlen(_Context->msg_View[_Context->language]),16);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_View_event()) != -1) break;

							}
						continue;
					case	0xa :
						/* Dbio */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Dbio_event()) != -1) break;

							}
						continue;
					case	0xb :
						/* ProgramOutput */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_debug_losefocus();
							_Context->page_number = 2;
							visual_debug_show();
							}
						continue;
					case	0xc :
						/* Prio */
						continue;
					case	0xd :
						/* VSB */
						(void) on_VSB_action();
						continue;
					case	0xe :
						/* HSB */
						(void) on_HSB_action();
						continue;
					case	0xf :
						/* DebugControl */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_debug_losefocus();
							_Context->page_number = 3;
							visual_debug_show();
							}
						continue;
					case	0x10 :
						/* ProcName */
						continue;
					case	0x11 :
						/* SegmName */
						continue;
					case	0x12 :
						/* GlobNames */
						continue;
					case	0x13 :
						/* LocalNames */
						continue;
					case	0x14 :
						/* AssignList */
						continue;
					case	0x15 :
						/* RegisterList */
						continue;
					case	0x16 :
						/* AttachList */
						continue;
					case	0x17 :
						/* StackList */
						continue;
					case	0x18 :
						/* LibraryList */
						continue;
					case	0x19 :
						/* ObserveList */
						continue;
					case	0x1a :
						/* DeleteObservation */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(874,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(874,280,20,19,vfh[2],27,0,_Context->msg_DeleteObservation[_Context->language],strlen(_Context->msg_DeleteObservation[_Context->language]),0);
							}
						continue;
					case	0x1b :
						/* BreakList */
						continue;
					case	0x1c :
						/* RemoveBreak */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(440,330,20,19,vfh[2],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(440,330,20,19,vfh[2],40,0,_Context->msg_RemoveBreak[_Context->language],strlen(_Context->msg_RemoveBreak[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_RemoveBreak_event()) != -1) break;

							}
						continue;
					case	0x1d :
						/* WatchList */
						continue;
					case	0x1e :
						/* DeleteWatch */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(876,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(876,330,20,19,vfh[2],40,0,_Context->msg_DeleteWatch[_Context->language],strlen(_Context->msg_DeleteWatch[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DeleteWatch_event()) != -1) break;

							}
						continue;
					case	0x1f :
						/* SourceList */
						continue;
					case	0x20 :
						/* InspectSource */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(440,380,20,19,vfh[2],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(440,380,20,19,vfh[2],27,0,_Context->msg_InspectSource[_Context->language],strlen(_Context->msg_InspectSource[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InspectSource_event()) != -1) break;

							}
						continue;
					case	0x21 :
						/* Syntax */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_Syntax_event()) != -1) break;

							}
						continue;
					case	0x22 :
						/* AED_NORMAL */
						continue;
					case	0x23 :
						/* AED_QUOTE */
						continue;
					case	0x24 :
						/* AED_KEYWORD */
						continue;
					case	0x25 :
						/* AED_COMMENT */
						continue;
					case	0x26 :
						/* AED_PUNCTUATE */
						continue;
					case	0x27 :
						/* EditorColour */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(750,450,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(750,450,140,32,vfh[2],28,28,_Context->msg_EditorColour[_Context->language],strlen(_Context->msg_EditorColour[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_EditorColour_event()) != -1) break;

							}
						continue;
					case	0x28 :
						/* SetBreakAP */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(44,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAP[_Context->language],strlen(_Context->msg_SetBreakAP[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakAP_event()) != -1) break;

							}
						continue;
					case	0x29 :
						/* SetBreakBP */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(116,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBP[_Context->language],strlen(_Context->msg_SetBreakBP[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakBP_event()) != -1) break;

							}
						continue;
					case	0x2a :
						/* SetBreakAS */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(220,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(220,600,70,32,vfh[2],40,0,_Context->msg_SetBreakAS[_Context->language],strlen(_Context->msg_SetBreakAS[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakAS_event()) != -1) break;

							}
						continue;
					case	0x2b :
						/* SetBreakBS */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(292,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(292,600,70,32,vfh[2],40,0,_Context->msg_SetBreakBS[_Context->language],strlen(_Context->msg_SetBreakBS[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SetBreakBS_event()) != -1) break;

							}
						continue;
					case	0x2c :
						/* MultipleWatch */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(396,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(396,600,70,32,vfh[2],40,0,_Context->msg_MultipleWatch[_Context->language],strlen(_Context->msg_MultipleWatch[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_MultipleWatch_event()) != -1) break;

							}
						continue;
					case	0x2d :
						/* SingleWatch */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(468,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(468,600,70,32,vfh[2],40,0,_Context->msg_SingleWatch[_Context->language],strlen(_Context->msg_SingleWatch[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SingleWatch_event()) != -1) break;

							}
						continue;
					case	0x2e :
						/* ObserveGlobal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(572,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(572,600,70,32,vfh[2],27,0,_Context->msg_ObserveGlobal[_Context->language],strlen(_Context->msg_ObserveGlobal[_Context->language]),0);
							}
						continue;
					case	0x2f :
						/* InspectGlobal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(644,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(644,600,70,32,vfh[2],27,0,_Context->msg_InspectGlobal[_Context->language],strlen(_Context->msg_InspectGlobal[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InspectGlobal_event()) != -1) break;

							}
						continue;
					case	0x30 :
						/* ObserveLocal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(748,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(748,600,70,32,vfh[2],27,0,_Context->msg_ObserveLocal[_Context->language],strlen(_Context->msg_ObserveLocal[_Context->language]),0);
							}
						continue;
					case	0x31 :
						/* InspectLocal */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(820,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(820,600,70,32,vfh[2],27,0,_Context->msg_InspectLocal[_Context->language],strlen(_Context->msg_InspectLocal[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_InspectLocal_event()) != -1) break;

							}
						continue;
					case	0x32 :
						/* BreakKey */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_BreakKey += 1;
							_Context->value_BreakKey &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_BreakKey_event()) != -1) break;

							}
						continue;
					case	0x33 :
						/* AsmList */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AsmList += 1;
							_Context->value_AsmList &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_AsmList_event()) != -1) break;

							}
						continue;
					case	0x34 :
						/* HexaView */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_HexaView += 1;
							_Context->value_HexaView &= 1;
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_HexaView_event()) != -1) break;

							}
						continue;
					case	0x35 :
						/* StatusBar */
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_StatusBar_event()) != -1) break;

							}
						continue;
					case	0x36 :
						/* VariableControl */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_debug_losefocus();
							_Context->page_number = 4;
							visual_debug_show();
							}
						continue;
					case	0x37 :
						/* vListe */
						if ( visual_event(1) &  0x10 ) {
						if ((_Context->keycode = on_vListe_event()) != -1) break;

							}
						continue;
					case	0x38 :
						/* vBar */
						(void) on_vBar_action();
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
				_Context->focus_item=56;
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

public	int	visual_debug(
	char * pBreakManager,
	char * pDbio,
	char * pPrio,
	char * pProcName,
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
	char * pBreakKey,
	char * pHexaView,
	char * pStatusBar)
{
	int	status=0;
	status = visual_debug_create(
	 pBreakManager,
	 pDbio,
	 pPrio,
	 pProcName,
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
	 pBreakKey,
	 pHexaView,
	 pStatusBar);
	if ( status != 0) return(status);
	status = visual_debug_show();
		enter_modal();
	status = visual_debug_focus();
		leave_modal();
	status = visual_debug_hide();
	status = visual_debug_remove(
	 pBreakManager,
	 pDbio,
	 pPrio,
	 pProcName,
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
	 pBreakKey,
	 pHexaView,
	 pStatusBar);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vexadb_c */
