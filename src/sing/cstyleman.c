
#ifndef _cstyleman_c
#define _cstyleman_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : cstyleman.xml                                            */
/* Target         : cstyleman.c                                              */
/* Identification : 0.0-1334659660-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "vstyle.h"
#include "cstyleman.h"
#define en__Auto3628   ""
#define fr__Auto3628   ""
#define it__Auto3628   ""
#define es__Auto3628   ""
#define de__Auto3628   ""
#define nl__Auto3628   ""
#define pt__Auto3628   ""
#define xx__Auto3628   ""
#define en_Auto3629   "cancel.gif"
#define fr_Auto3629   "cancel.gif"
#define it_Auto3629   "cancel.gif"
#define es_Auto3629   "cancel.gif"
#define de_Auto3629   "cancel.gif"
#define nl_Auto3629   "cancel.gif"
#define pt_Auto3629   "cancel.gif"
#define xx_Auto3629   "cancel.gif"
#define en__Auto3629   "Exit from the style editor"
#define fr__Auto3629   "Quiter l'‚diteur de styles"
#define it__Auto3629   "Exit from the style editor"
#define es__Auto3629   "Exit from the style editor"
#define de__Auto3629   "Exit from the style editor"
#define nl__Auto3629   "Exit from the style editor"
#define pt__Auto3629   "Exit from the style editor"
#define xx__Auto3629   "Exit from the style editor"
#define en_Trash   "trash.gif"
#define fr_Trash   "trash.gif"
#define it_Trash   "trash.gif"
#define es_Trash   "trash.gif"
#define de_Trash   "trash.gif"
#define nl_Trash   "trash.gif"
#define pt_Trash   "trash.gif"
#define xx_Trash   "trash.gif"
#define en__Trash   "Delete a style class or file"
#define fr__Trash   "Suprimer un fichier ou classe de style"
#define it__Trash   "Delete a style class or file"
#define es__Trash   "Delete a style class or file"
#define de__Trash   "Delete a style class or file"
#define nl__Trash   "Delete a style class or file"
#define pt__Trash   "Delete a style class or file"
#define xx__Trash   "Delete a style class or file"
#define en_Trace   "warning.png"
#define fr_Trace   "warning.png"
#define it_Trace   "warning.png"
#define es_Trace   "warning.png"
#define de_Trace   "warning.png"
#define nl_Trace   "warning.png"
#define pt_Trace   "warning.png"
#define xx_Trace   "warning.png"
#define en__Trace   "Style Error Trace"
#define fr__Trace   "Trace d'erreurs de Style"
#define it__Trace   "Style Error Trace"
#define es__Trace   "Style Error Trace"
#define de__Trace   "Style Error Trace"
#define nl__Trace   "Style Error Trace"
#define pt__Trace   "Style Error Trace"
#define xx__Trace   "Style Error Trace"
#define en_Classes   "stylec"
#define fr_Classes   "stylec"
#define it_Classes   "stylec"
#define es_Classes   "stylec"
#define de_Classes   "stylec"
#define nl_Classes   "stylec"
#define pt_Classes   "stylec"
#define xx_Classes   "stylec"
#define en__Classes   ""
#define en_Files   "stylef"
#define fr_Files   "stylef"
#define it_Files   "stylef"
#define es_Files   "stylef"
#define de_Files   "stylef"
#define nl_Files   "stylef"
#define pt_Files   "stylef"
#define xx_Files   "stylef"
#define en__Files   ""
#define en_FileWork   "stylef"
#define en__FileWork   ""
#define en_ImportFile   "stylef"
#define en__ImportFile   ""
#define en_Members   "stylem"
#define fr_Members   "stylem"
#define it_Members   "stylem"
#define es_Members   "stylem"
#define de_Members   "stylem"
#define nl_Members   "stylem"
#define pt_Members   "stylem"
#define xx_Members   "stylem"
#define en__Members   ""
#define en_ImportMember   "stylem"
#define en__ImportMember   ""
#define en_Worker   "stylec"
#define en__Worker   ""
#define en_CLPage   " Classes"
#define fr_CLPage   " Classes"
#define it_CLPage   " Classes"
#define es_CLPage   " Classes"
#define de_CLPage   " Classes"
#define nl_CLPage   " Classes"
#define pt_CLPage   " Classes"
#define xx_CLPage   " Classes"
#define en__CLPage   ""
#define en_ClassList   "classname|baseclass"
#define fr_ClassList   "nom de classe|classe de base"
#define it_ClassList   "classname|baseclass"
#define es_ClassList   "classname|baseclass"
#define de_ClassList   "classname|baseclass"
#define nl_ClassList   "classname|baseclass"
#define pt_ClassList   "classname|baseclass"
#define xx_ClassList   "classname|baseclass"
#define en__ClassList   ""
#define fr__ClassList   ""
#define it__ClassList   ""
#define es__ClassList   ""
#define de__ClassList   ""
#define nl__ClassList   ""
#define pt__ClassList   ""
#define xx__ClassList   ""
#define en_CLCursor   ""
#define fr_CLCursor   ""
#define it_CLCursor   ""
#define es_CLCursor   ""
#define de_CLCursor   ""
#define nl_CLCursor   ""
#define pt_CLCursor   ""
#define xx_CLCursor   ""
#define en__CLCursor   ""
#define en_Action   ""
#define en__Action   ""
#define en_FileList   "filename"
#define fr_FileList   "fichier"
#define it_FileList   "filename"
#define es_FileList   "filename"
#define de_FileList   "filename"
#define nl_FileList   "filename"
#define pt_FileList   "filename"
#define xx_FileList   "filename"
#define en__FileList   ""
#define fr__FileList   ""
#define it__FileList   ""
#define es__FileList   ""
#define de__FileList   ""
#define nl__FileList   ""
#define pt__FileList   ""
#define xx__FileList   ""
#define en_FLCursor   ""
#define en__FLCursor   ""
#define en_CFList   "name"
#define fr_CFList   "nom"
#define it_CFList   "name"
#define es_CFList   "name"
#define de_CFList   "name"
#define nl_CFList   "name"
#define pt_CFList   "name"
#define xx_CFList   "name"
#define en__CFList   ""
#define fr__CFList   ""
#define it__CFList   ""
#define es__CFList   ""
#define de__CFList   ""
#define nl__CFList   ""
#define pt__CFList   ""
#define xx__CFList   ""
#define en_MLCursor   ""
#define en__MLCursor   ""
#define en_CLBar   ""
#define en__CLBar   ""
#define en_MLBar   ""
#define en__MLBar   ""
#define en_FLBar   ""
#define en__FLBar   ""
#define en_StylePage   " Style"
#define fr_StylePage   " Style"
#define it_StylePage   " Style"
#define es_StylePage   " Style"
#define de_StylePage   " Style"
#define nl_StylePage   " Style"
#define pt_StylePage   " Style"
#define xx_StylePage   " Style"
#define en__StylePage   ""
#define en_ExportNameError   "The filename for the export operation is incorrect"
#define fr_ExportNameError   "Le nom de fichier pour l'operation d'export est incorrect"
#define it_ExportNameError   "The filename for the export operation is incorrect"
#define es_ExportNameError   "The filename for the export operation is incorrect"
#define de_ExportNameError   "The filename for the export operation is incorrect"
#define nl_ExportNameError   "The filename for the export operation is incorrect"
#define pt_ExportNameError   "The filename for the export operation is incorrect"
#define xx_ExportNameError   "The filename for the export operation is incorrect"
#define en__ExportNameError   ""
#define fr__ExportNameError   ""
#define it__ExportNameError   ""
#define es__ExportNameError   ""
#define de__ExportNameError   ""
#define nl__ExportNameError   ""
#define pt__ExportNameError   ""
#define xx__ExportNameError   ""
#define en_StatusBar   ""
#define en__StatusBar   ""
#define en_Auto3631   "current classname"
#define fr_Auto3631   "nom de classe courante"
#define it_Auto3631   "classname"
#define es_Auto3631   "classname"
#define de_Auto3631   "classname"
#define nl_Auto3631   "classname"
#define pt_Auto3631   "classname"
#define xx_Auto3631   "classname"
#define en__Auto3631   ""
#define fr__Auto3631   ""
#define it__Auto3631   ""
#define es__Auto3631   ""
#define de__Auto3631   ""
#define nl__Auto3631   ""
#define pt__Auto3631   ""
#define xx__Auto3631   ""
#define en_Auto3632   "Style Manager"
#define fr_Auto3632   "Gestionaire de Style"
#define it_Auto3632   "Style Manager"
#define es_Auto3632   "Style Manager"
#define de_Auto3632   "Style Manager"
#define nl_Auto3632   "Style Manager"
#define pt_Auto3632   "Style Manager"
#define xx_Auto3632   "Style Manager"
#define en__Auto3632   ""
#define fr__Auto3632   ""
#define it__Auto3632   ""
#define es__Auto3632   ""
#define de__Auto3632   ""
#define nl__Auto3632   ""
#define pt__Auto3632   ""
#define xx__Auto3632   ""
#define en_Auto3633   "save current class to filename"
#define fr_Auto3633   "sauver la classe courante sur le fichier"
#define it_Auto3633   "save individual class to filename"
#define es_Auto3633   "save individual class to filename"
#define de_Auto3633   "save individual class to filename"
#define nl_Auto3633   "save individual class to filename"
#define pt_Auto3633   "save individual class to filename"
#define xx_Auto3633   "save individual class to filename"
#define en__Auto3633   ""
#define fr__Auto3633   ""
#define it__Auto3633   ""
#define es__Auto3633   ""
#define de__Auto3633   ""
#define nl__Auto3633   ""
#define pt__Auto3633   ""
#define xx__Auto3633   ""
#define en_Auto3634   "export collection of style classes to filename"
#define fr_Auto3634   "exporter la collection de classes sur le fichier"
#define it_Auto3634   "export collection of style classes to filename"
#define es_Auto3634   "export collection of style classes to filename"
#define de_Auto3634   "export collection of style classes to filename"
#define nl_Auto3634   "export collection of style classes to filename"
#define pt_Auto3634   "export collection of style classes to filename"
#define xx_Auto3634   "export collection of style classes to filename"
#define en__Auto3634   ""
#define fr__Auto3634   ""
#define it__Auto3634   ""
#define es__Auto3634   ""
#define de__Auto3634   ""
#define nl__Auto3634   ""
#define pt__Auto3634   ""
#define xx__Auto3634   ""
#define en_Auto3635   "import all style classes from filename"
#define fr_Auto3635   "importer tout les classes de style du fichier"
#define it_Auto3635   "import all style classes from filename"
#define es_Auto3635   "import all style classes from filename"
#define de_Auto3635   "import all style classes from filename"
#define nl_Auto3635   "import all style classes from filename"
#define pt_Auto3635   "import all style classes from filename"
#define xx_Auto3635   "import all style classes from filename"
#define en__Auto3635   "import all style classes from filename"
#define fr__Auto3635   ""
#define it__Auto3635   ""
#define es__Auto3635   ""
#define de__Auto3635   ""
#define nl__Auto3635   ""
#define pt__Auto3635   ""
#define xx__Auto3635   ""
#define en_Auto3636   "derives"
#define fr_Auto3636   "derivation de"
#define it_Auto3636   "derives"
#define es_Auto3636   "derives"
#define de_Auto3636   "derives"
#define nl_Auto3636   "derives"
#define pt_Auto3636   "derives"
#define xx_Auto3636   "derives"
#define en__Auto3636   ""
#define fr__Auto3636   ""
#define it__Auto3636   ""
#define es__Auto3636   ""
#define de__Auto3636   ""
#define nl__Auto3636   ""
#define pt__Auto3636   ""
#define xx__Auto3636   ""
#define en_Auto3637   "description"
#define fr_Auto3637   "descriptif"
#define it_Auto3637   "description"
#define es_Auto3637   "description"
#define de_Auto3637   "description"
#define nl_Auto3637   "description"
#define pt_Auto3637   "description"
#define xx_Auto3637   "description"
#define en__Auto3637   ""
#define fr__Auto3637   ""
#define it__Auto3637   ""
#define es__Auto3637   ""
#define de__Auto3637   ""
#define nl__Auto3637   ""
#define pt__Auto3637   ""
#define xx__Auto3637   ""
#define en_ClassName   ""
#define en__ClassName   "Specify the name of the style class"
#define en_LoadOperation   "load.png"
#define fr_LoadOperation   "load.png"
#define it_LoadOperation   "load.png"
#define es_LoadOperation   "load.png"
#define de_LoadOperation   "load.png"
#define nl_LoadOperation   "load.png"
#define pt_LoadOperation   "load.png"
#define xx_LoadOperation   "load.png"
#define en__LoadOperation   "Load from style manager structure"
#define fr__LoadOperation   "Chargment depuis des champs de d‚finition de style"
#define it__LoadOperation   "Load from style manager structure"
#define es__LoadOperation   "Load from style manager structure"
#define de__LoadOperation   "Load from style manager structure"
#define nl__LoadOperation   "Load from style manager structure"
#define pt__LoadOperation   "Load from style manager structure"
#define xx__LoadOperation   "Load from style manager structure"
#define en_Reset   "trash.gif"
#define fr_Reset   "trash.gif"
#define it_Reset   "trash.gif"
#define es_Reset   "trash.gif"
#define de_Reset   "trash.gif"
#define nl_Reset   "trash.gif"
#define pt_Reset   "trash.gif"
#define xx_Reset   "trash.gif"
#define en__Reset   "Reset all fields"
#define fr__Reset   "RAZ des champs de d‚finition de style"
#define it__Reset   "Reset all fields"
#define es__Reset   "Reset all fields"
#define de__Reset   "Reset all fields"
#define nl__Reset   "Reset all fields"
#define pt__Reset   "Reset all fields"
#define xx__Reset   "Reset all fields"
#define en_BaseClass   ""
#define en__BaseClass   "specify the classname of a base class"
#define en_Description   ""
#define en__Description   "Specify a short textual description of the style class"
#define en_ClassFile   ""
#define en__ClassFile   "Specify the name of the file to which the class save operation applies"
#define en_SaveOperation   "floppy.png"
#define fr_SaveOperation   "floppy.png"
#define it_SaveOperation   "floppy.png"
#define es_SaveOperation   "floppy.png"
#define de_SaveOperation   "floppy.png"
#define nl_SaveOperation   "floppy.png"
#define pt_SaveOperation   "floppy.png"
#define xx_SaveOperation   "floppy.png"
#define en__SaveOperation   "Save to file name"
#define fr__SaveOperation   "Sauver sur fichier"
#define it__SaveOperation   "Save to file name"
#define es__SaveOperation   "Save to file name"
#define de__SaveOperation   "Save to file name"
#define nl__SaveOperation   "Save to file name"
#define pt__SaveOperation   "Save to file name"
#define xx__SaveOperation   "Save to file name"
#define en_ViewFile   "screen.gif"
#define fr_ViewFile   "screen.gif"
#define it_ViewFile   "screen.gif"
#define es_ViewFile   "screen.gif"
#define de_ViewFile   "screen.gif"
#define nl_ViewFile   "screen.gif"
#define pt_ViewFile   "screen.gif"
#define xx_ViewFile   "screen.gif"
#define en__ViewFile   ""
#define fr__ViewFile   ""
#define it__ViewFile   ""
#define es__ViewFile   ""
#define de__ViewFile   ""
#define nl__ViewFile   ""
#define pt__ViewFile   ""
#define xx__ViewFile   ""
#define en_ExportName   ""
#define en__ExportName   "Name of the file for the export operation"
#define en_ExportOperation   "floppy.png"
#define fr_ExportOperation   "floppy.png"
#define it_ExportOperation   "floppy.png"
#define es_ExportOperation   "floppy.png"
#define de_ExportOperation   "floppy.png"
#define nl_ExportOperation   "floppy.png"
#define pt_ExportOperation   "floppy.png"
#define xx_ExportOperation   "floppy.png"
#define en__ExportOperation   "Export collection of classes to a style class file"
#define fr__ExportOperation   "Exporter la collection de classes vers un fichier"
#define it__ExportOperation   "Export collection of classes to a style class file"
#define es__ExportOperation   "Export collection of classes to a style class file"
#define de__ExportOperation   "Export collection of classes to a style class file"
#define nl__ExportOperation   "Export collection of classes to a style class file"
#define pt__ExportOperation   "Export collection of classes to a style class file"
#define xx__ExportOperation   "Export collection of classes to a style class file"
#define en_ViewExport   "screen.gif"
#define fr_ViewExport   "screen.gif"
#define it_ViewExport   "screen.gif"
#define es_ViewExport   "screen.gif"
#define de_ViewExport   "screen.gif"
#define nl_ViewExport   "screen.gif"
#define pt_ViewExport   "screen.gif"
#define xx_ViewExport   "screen.gif"
#define en__ViewExport   ""
#define fr__ViewExport   ""
#define it__ViewExport   ""
#define es__ViewExport   ""
#define de__ViewExport   ""
#define nl__ViewExport   ""
#define pt__ViewExport   ""
#define xx__ViewExport   ""
#define en_ImportName   ""
#define en__ImportName   "Name of file for the import operation"
#define en_ImportOperation   "load.png"
#define fr_ImportOperation   "load.png"
#define it_ImportOperation   "load.png"
#define es_ImportOperation   "load.png"
#define de_ImportOperation   "load.png"
#define nl_ImportOperation   "load.png"
#define pt_ImportOperation   "load.png"
#define xx_ImportOperation   "load.png"
#define en__ImportOperation   "Import file containig style classes"
#define fr__ImportOperation   "Import d'un fichier de classes de style"
#define it__ImportOperation   "Import file containing style classes"
#define es__ImportOperation   "Import file containing style classes"
#define de__ImportOperation   "Import file containing style classes"
#define nl__ImportOperation   "Import file containing style classes"
#define pt__ImportOperation   "Import file containing style classes"
#define xx__ImportOperation   "Import file containing style classes"
#define en_ViewImport   "screen.gif"
#define fr_ViewImport   "screen.gif"
#define it_ViewImport   "screen.gif"
#define es_ViewImport   "screen.gif"
#define de_ViewImport   "screen.gif"
#define nl_ViewImport   "screen.gif"
#define pt_ViewImport   "screen.gif"
#define xx_ViewImport   "screen.gif"
#define en__ViewImport   ""
#define fr__ViewImport   ""
#define it__ViewImport   ""
#define es__ViewImport   ""
#define de__ViewImport   ""
#define nl__ViewImport   ""
#define pt__ViewImport   ""
#define xx__ViewImport   ""
#define en_TestPage   " Test"
#define fr_TestPage   " Test"
#define it_TestPage   " Test"
#define es_TestPage   " Test"
#define de_TestPage   " Test"
#define nl_TestPage   " Test"
#define pt_TestPage   " Test"
#define xx_TestPage   " Test"
#define en__TestPage   ""
#define en__Thing   ""
#define en_Cell   " Cell"
#define fr_Cell   " Cell"
#define it_Cell   " Cell"
#define es_Cell   " Cell"
#define de_Cell   " Cell"
#define nl_Cell   " Cell"
#define pt_Cell   " Cell"
#define xx_Cell   " Cell"
#define en__Cell   ""
#define en_Auto3638   "Cell"
#define fr_Auto3638   "Cell"
#define it_Auto3638   "Cell"
#define es_Auto3638   "Cell"
#define de_Auto3638   "Cell"
#define nl_Auto3638   "Cell"
#define pt_Auto3638   "Cell"
#define xx_Auto3638   "Cell"
#define en__Auto3638   ""
#define en_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define fr_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define it_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define es_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define de_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define nl_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define pt_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define xx_Auto3639   "The term CELL applies to the complete style model collection comprising MARGIN, BORDER, PADDING, BACKGROUND and CONTENTS."
#define en__Auto3639   ""
#define en_Auto3640   ""
#define en__Auto3640   ""
#define en_Auto3641   ""
#define en__Auto3641   ""
#define en_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define fr_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define it_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define es_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define de_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define nl_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define pt_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define xx_Auto3642   "The CELL parameters may  be used to redimension and or reposition the client style cell description."
#define en__Auto3642   ""
#define en_Auto3643   "content"
#define fr_Auto3643   "content"
#define it_Auto3643   "content"
#define es_Auto3643   "content"
#define de_Auto3643   "content"
#define nl_Auto3643   "content"
#define pt_Auto3643   "content"
#define xx_Auto3643   "content"
#define en__Auto3643   ""
#define en_Auto3644   "position"
#define fr_Auto3644   "position"
#define it_Auto3644   "position"
#define es_Auto3644   "position"
#define de_Auto3644   "position"
#define nl_Auto3644   "position"
#define pt_Auto3644   "position"
#define xx_Auto3644   "position"
#define en__Auto3644   ""
#define en_Auto3645   "width"
#define fr_Auto3645   "width"
#define it_Auto3645   "width"
#define es_Auto3645   "width"
#define de_Auto3645   "width"
#define nl_Auto3645   "width"
#define pt_Auto3645   "width"
#define xx_Auto3645   "width"
#define en__Auto3645   ""
#define en_Auto3646   "left"
#define fr_Auto3646   "left"
#define it_Auto3646   "left"
#define es_Auto3646   "left"
#define de_Auto3646   "left"
#define nl_Auto3646   "left"
#define pt_Auto3646   "left"
#define xx_Auto3646   "left"
#define en__Auto3646   ""
#define en_Auto3647   "top"
#define fr_Auto3647   "top"
#define it_Auto3647   "top"
#define es_Auto3647   "top"
#define de_Auto3647   "top"
#define nl_Auto3647   "top"
#define pt_Auto3647   "top"
#define xx_Auto3647   "top"
#define en__Auto3647   ""
#define en_Auto3648   "bottom"
#define fr_Auto3648   "bottom"
#define it_Auto3648   "bottom"
#define es_Auto3648   "bottom"
#define de_Auto3648   "bottom"
#define nl_Auto3648   "bottom"
#define pt_Auto3648   "bottom"
#define xx_Auto3648   "bottom"
#define en__Auto3648   ""
#define en_Auto3649   "right"
#define fr_Auto3649   "right"
#define it_Auto3649   "right"
#define es_Auto3649   "right"
#define de_Auto3649   "right"
#define nl_Auto3649   "right"
#define pt_Auto3649   "right"
#define xx_Auto3649   "right"
#define en__Auto3649   ""
#define en_Auto3650   "height"
#define fr_Auto3650   "height"
#define it_Auto3650   "height"
#define es_Auto3650   "height"
#define de_Auto3650   "height"
#define nl_Auto3650   "height"
#define pt_Auto3650   "height"
#define xx_Auto3650   "height"
#define en__Auto3650   ""
#define en__ct   "specify the style cell content type"
#define en__posv   "specify the style cell position"
#define en_cwv   ""
#define en__cwv   "specify the style cell width value"
#define en__cwt   "select the style cell width metric"
#define fr__cwt   ""
#define it__cwt   ""
#define es__cwt   ""
#define de__cwt   ""
#define nl__cwt   ""
#define pt__cwt   ""
#define xx__cwt   ""
#define en_chv   ""
#define en__chv   "specify the style cell height value"
#define en__cht   "select the style cell height metric"
#define fr__cht   "select the style cell height metric"
#define it__cht   "select the style cell height metric"
#define es__cht   "select the style cell height metric"
#define de__cht   "select the style cell height metric"
#define nl__cht   "select the style cell height metric"
#define pt__cht   "select the style cell height metric"
#define xx__cht   "select the style cell height metric"
#define en_cplv   ""
#define en__cplv   "specify the left indent value"
#define en__cplt   "select the left indent metric"
#define fr__cplt   "select the left indent metric"
#define it__cplt   "select the left indent metric"
#define es__cplt   "select the left indent metric"
#define de__cplt   "select the left indent metric"
#define nl__cplt   "select the left indent metric"
#define pt__cplt   "select the left indent metric"
#define xx__cplt   "select the left indent metric"
#define en_cptv   ""
#define en__cptv   "specify the top indent value"
#define en_cprv   ""
#define en__cprv   "specify the right indent value"
#define en_cpbv   ""
#define en__cpbv   "specify the bottom indent value"
#define en__cptt   "select the top indent metric"
#define fr__cptt   "select the top indent metric"
#define it__cptt   "select the top indent metric"
#define es__cptt   "select the top indent metric"
#define de__cptt   "select the top indent metric"
#define nl__cptt   "select the top indent metric"
#define pt__cptt   "select the top indent metric"
#define xx__cptt   "select the top indent metric"
#define en__cprt   "select the right indent metric"
#define fr__cprt   "select the right indent metric"
#define it__cprt   "select the right indent metric"
#define es__cprt   "select the right indent metric"
#define de__cprt   "select the right indent metric"
#define nl__cprt   "select the right indent metric"
#define pt__cprt   "select the right indent metric"
#define xx__cprt   "select the right indent metric"
#define en__cpbt   "select the bottom indent metric"
#define fr__cpbt   "select the bottom indent metric"
#define it__cpbt   "select the bottom indent metric"
#define es__cpbt   "select the bottom indent metric"
#define de__cpbt   "select the bottom indent metric"
#define nl__cpbt   "select the bottom indent metric"
#define pt__cpbt   "select the bottom indent metric"
#define xx__cpbt   "select the bottom indent metric"
#define en_MarginPage   " Margin"
#define fr_MarginPage   " Margin"
#define it_MarginPage   " Margin"
#define es_MarginPage   " Margin"
#define de_MarginPage   " Margin"
#define nl_MarginPage   " Margin"
#define pt_MarginPage   " Margin"
#define xx_MarginPage   " Margin"
#define en__MarginPage   ""
#define fr__MarginPage   ""
#define it__MarginPage   ""
#define es__MarginPage   ""
#define de__MarginPage   ""
#define nl__MarginPage   ""
#define pt__MarginPage   ""
#define xx__MarginPage   ""
#define en_Auto3651   "Margin"
#define fr_Auto3651   "Margin"
#define it_Auto3651   "Margin"
#define es_Auto3651   "Margin"
#define de_Auto3651   "Margin"
#define nl_Auto3651   "Margin"
#define pt_Auto3651   "Margin"
#define xx_Auto3651   "Margin"
#define en__Auto3651   ""
#define en_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define fr_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define it_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define es_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define de_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define nl_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define pt_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define xx_Auto3652   "The term MARGIN refers to the space between the various cell edges and the eventual cell BORDER"
#define en__Auto3652   ""
#define en_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define fr_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define it_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define es_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define de_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define nl_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define pt_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define xx_Auto3653   "All MARGIN values may be set at once using the central control, or by using the individual side MARGIN controls."
#define en__Auto3653   ""
#define en_Auto3654   ""
#define en__Auto3654   ""
#define en_Auto3655   ""
#define en__Auto3655   ""
#define en_Auto3656   "left"
#define fr_Auto3656   "left"
#define it_Auto3656   "left"
#define es_Auto3656   "left"
#define de_Auto3656   "left"
#define nl_Auto3656   "left"
#define pt_Auto3656   "left"
#define xx_Auto3656   "left"
#define en__Auto3656   ""
#define fr__Auto3656   ""
#define it__Auto3656   ""
#define es__Auto3656   ""
#define de__Auto3656   ""
#define nl__Auto3656   ""
#define pt__Auto3656   ""
#define xx__Auto3656   ""
#define en_Auto3657   "margin"
#define fr_Auto3657   "margin"
#define it_Auto3657   "margin"
#define es_Auto3657   "margin"
#define de_Auto3657   "margin"
#define nl_Auto3657   "margin"
#define pt_Auto3657   "margin"
#define xx_Auto3657   "margin"
#define en__Auto3657   ""
#define fr__Auto3657   ""
#define it__Auto3657   ""
#define es__Auto3657   ""
#define de__Auto3657   ""
#define nl__Auto3657   ""
#define pt__Auto3657   ""
#define xx__Auto3657   ""
#define en_Auto3658   "top"
#define fr_Auto3658   "top"
#define it_Auto3658   "top"
#define es_Auto3658   "top"
#define de_Auto3658   "top"
#define nl_Auto3658   "top"
#define pt_Auto3658   "top"
#define xx_Auto3658   "top"
#define en__Auto3658   ""
#define fr__Auto3658   ""
#define it__Auto3658   ""
#define es__Auto3658   ""
#define de__Auto3658   ""
#define nl__Auto3658   ""
#define pt__Auto3658   ""
#define xx__Auto3658   ""
#define en_Auto3659   "right"
#define fr_Auto3659   "right"
#define it_Auto3659   "right"
#define es_Auto3659   "right"
#define de_Auto3659   "right"
#define nl_Auto3659   "right"
#define pt_Auto3659   "right"
#define xx_Auto3659   "right"
#define en__Auto3659   ""
#define fr__Auto3659   ""
#define it__Auto3659   ""
#define es__Auto3659   ""
#define de__Auto3659   ""
#define nl__Auto3659   ""
#define pt__Auto3659   ""
#define xx__Auto3659   ""
#define en_Auto3660   "bottom"
#define fr_Auto3660   "bottom"
#define it_Auto3660   "bottom"
#define es_Auto3660   "bottom"
#define de_Auto3660   "bottom"
#define nl_Auto3660   "bottom"
#define pt_Auto3660   "bottom"
#define xx_Auto3660   "bottom"
#define en__Auto3660   ""
#define fr__Auto3660   ""
#define it__Auto3660   ""
#define es__Auto3660   ""
#define de__Auto3660   ""
#define nl__Auto3660   ""
#define pt__Auto3660   ""
#define xx__Auto3660   ""
#define en_mlv   ""
#define en__mlv   "specify the left margin value"
#define en__mlt   "select the left margin metric"
#define fr__mlt   "select the left margin metric"
#define it__mlt   "select the left margin metric"
#define es__mlt   "select the left margin metric"
#define de__mlt   "select the left margin metric"
#define nl__mlt   "select the left margin metric"
#define pt__mlt   "select the left margin metric"
#define xx__mlt   "select the left margin metric"
#define en_mgv   ""
#define en__mgv   "specify the all margins value"
#define en__mgt   "select the all margins metric"
#define fr__mgt   "select the all margins metric"
#define it__mgt   "select the all margins metric"
#define es__mgt   "select the all margins metric"
#define de__mgt   "select the all margins metric"
#define nl__mgt   "select the all margins metric"
#define pt__mgt   "select the all margins metric"
#define xx__mgt   "select the all margins metric"
#define en_mtv   ""
#define en__mtv   "specify the top margin value"
#define en__mtt   "select the top margin metric"
#define fr__mtt   "select the top margin metric"
#define it__mtt   "select the top margin metric"
#define es__mtt   "select the top margin metric"
#define de__mtt   "select the top margin metric"
#define nl__mtt   "select the top margin metric"
#define pt__mtt   "select the top margin metric"
#define xx__mtt   "select the top margin metric"
#define en_mrv   ""
#define en__mrv   "specify the right margin value"
#define en__mrt   "select the right margin metric"
#define fr__mrt   "select the right margin metric"
#define it__mrt   "select the right margin metric"
#define es__mrt   "select the right margin metric"
#define de__mrt   "select the right margin metric"
#define nl__mrt   "select the right margin metric"
#define pt__mrt   "select the right margin metric"
#define xx__mrt   "select the right margin metric"
#define en_mbv   ""
#define en__mbv   "specify the bottom margin value"
#define en__mbt   "select the bottom margin metric"
#define fr__mbt   "select the bottom margin metric"
#define it__mbt   "select the bottom margin metric"
#define es__mbt   "select the bottom margin metric"
#define de__mbt   "select the bottom margin metric"
#define nl__mbt   "select the bottom margin metric"
#define pt__mbt   "select the bottom margin metric"
#define xx__mbt   "select the bottom margin metric"
#define en_BorderPage   " Border"
#define fr_BorderPage   " Border"
#define it_BorderPage   " Border"
#define es_BorderPage   " Border"
#define de_BorderPage   " Border"
#define nl_BorderPage   " Border"
#define pt_BorderPage   " Border"
#define xx_BorderPage   " Border"
#define en__BorderPage   ""
#define fr__BorderPage   ""
#define it__BorderPage   ""
#define es__BorderPage   ""
#define de__BorderPage   ""
#define nl__BorderPage   ""
#define pt__BorderPage   ""
#define xx__BorderPage   ""
#define en_Auto3661   "Margin"
#define fr_Auto3661   "Margin"
#define it_Auto3661   "Margin"
#define es_Auto3661   "Margin"
#define de_Auto3661   "Margin"
#define nl_Auto3661   "Margin"
#define pt_Auto3661   "Margin"
#define xx_Auto3661   "Margin"
#define en__Auto3661   ""
#define fr__Auto3661   ""
#define it__Auto3661   ""
#define es__Auto3661   ""
#define de__Auto3661   ""
#define nl__Auto3661   ""
#define pt__Auto3661   ""
#define xx__Auto3661   ""
#define en_Auto3662   "Border"
#define fr_Auto3662   "Border"
#define it_Auto3662   "Border"
#define es_Auto3662   "Border"
#define de_Auto3662   "Border"
#define nl_Auto3662   "Border"
#define pt_Auto3662   "Border"
#define xx_Auto3662   "Border"
#define en__Auto3662   ""
#define en_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define fr_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define it_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define es_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define de_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define nl_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define pt_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define xx_Auto3663   "The term BORDER refers to frame situated between the MARGIN and the CONTENT or PADDING."
#define en__Auto3663   ""
#define en_Auto3664   "colour"
#define fr_Auto3664   "colour"
#define it_Auto3664   "colour"
#define es_Auto3664   "colour"
#define de_Auto3664   "colour"
#define nl_Auto3664   "colour"
#define pt_Auto3664   "colour"
#define xx_Auto3664   "colour"
#define en__Auto3664   ""
#define en_Auto3665   "align"
#define fr_Auto3665   "align"
#define it_Auto3665   "align"
#define es_Auto3665   "align"
#define de_Auto3665   "align"
#define nl_Auto3665   "align"
#define pt_Auto3665   "align"
#define xx_Auto3665   "align"
#define en__Auto3665   ""
#define en_Auto3666   "width"
#define fr_Auto3666   "width"
#define it_Auto3666   "width"
#define es_Auto3666   "width"
#define de_Auto3666   "width"
#define nl_Auto3666   "width"
#define pt_Auto3666   "width"
#define xx_Auto3666   "width"
#define en__Auto3666   ""
#define fr__Auto3666   ""
#define it__Auto3666   ""
#define es__Auto3666   ""
#define de__Auto3666   ""
#define nl__Auto3666   ""
#define pt__Auto3666   ""
#define xx__Auto3666   ""
#define en__bdct   "select the border colour type or name"
#define en_bdcv   ""
#define en__bdcv   "specify the border colour rgb or ihm value"
#define en__bdat   "select the border image alignment type"
#define en_Auto3667   ""
#define en__Auto3667   ""
#define en_Auto3668   ""
#define en__Auto3668   ""
#define en_Auto3669   "left"
#define fr_Auto3669   "left"
#define it_Auto3669   "left"
#define es_Auto3669   "left"
#define de_Auto3669   "left"
#define nl_Auto3669   "left"
#define pt_Auto3669   "left"
#define xx_Auto3669   "left"
#define en__Auto3669   ""
#define fr__Auto3669   ""
#define it__Auto3669   ""
#define es__Auto3669   ""
#define de__Auto3669   ""
#define nl__Auto3669   ""
#define pt__Auto3669   ""
#define xx__Auto3669   ""
#define en_Auto3670   "style"
#define fr_Auto3670   "style"
#define it_Auto3670   "style"
#define es_Auto3670   "style"
#define de_Auto3670   "style"
#define nl_Auto3670   "style"
#define pt_Auto3670   "style"
#define xx_Auto3670   "style"
#define en__Auto3670   ""
#define en_Auto3671   "top-left"
#define fr_Auto3671   "top-left"
#define it_Auto3671   "top-left"
#define es_Auto3671   "top-left"
#define de_Auto3671   "top-left"
#define nl_Auto3671   "top-left"
#define pt_Auto3671   "top-left"
#define xx_Auto3671   "top-left"
#define en__Auto3671   ""
#define en_Auto3672   "url-left"
#define fr_Auto3672   "url-left"
#define it_Auto3672   "url-left"
#define es_Auto3672   "url-left"
#define de_Auto3672   "url-left"
#define nl_Auto3672   "url-left"
#define pt_Auto3672   "url-left"
#define xx_Auto3672   "url-left"
#define en__Auto3672   ""
#define en_blu   ""
#define en__blu   "specify left edge image filename"
#define en_Auto3673   "url-top"
#define fr_Auto3673   "url-top"
#define it_Auto3673   "url-top"
#define es_Auto3673   "url-top"
#define de_Auto3673   "url-top"
#define nl_Auto3673   "url-top"
#define pt_Auto3673   "url-top"
#define xx_Auto3673   "url-top"
#define en__Auto3673   ""
#define en_Auto3674   "url-right"
#define fr_Auto3674   "url-right"
#define it_Auto3674   "url-right"
#define es_Auto3674   "url-right"
#define de_Auto3674   "url-right"
#define nl_Auto3674   "url-right"
#define pt_Auto3674   "url-right"
#define xx_Auto3674   "url-right"
#define en__Auto3674   ""
#define en_btu   ""
#define en__btu   "specify top edge image filename"
#define en_Auto3675   "url-bottom"
#define fr_Auto3675   "url-bottom"
#define it_Auto3675   "url-bottom"
#define es_Auto3675   "url-bottom"
#define de_Auto3675   "url-bottom"
#define nl_Auto3675   "url-bottom"
#define pt_Auto3675   "url-bottom"
#define xx_Auto3675   "url-bottom"
#define en__Auto3675   ""
#define en_bbu   ""
#define en__bbu   "specify bottom edge image filename"
#define en_bru   ""
#define en__bru   "specify right edge image filename"
#define en_Auto3676   "bottom-left"
#define fr_Auto3676   "bottom-left"
#define it_Auto3676   "bottom-left"
#define es_Auto3676   "bottom-left"
#define de_Auto3676   "bottom-left"
#define nl_Auto3676   "bottom-left"
#define pt_Auto3676   "bottom-left"
#define xx_Auto3676   "bottom-left"
#define en__Auto3676   ""
#define en_Auto3677   "top-right"
#define fr_Auto3677   "top-right"
#define it_Auto3677   "top-right"
#define es_Auto3677   "top-right"
#define de_Auto3677   "top-right"
#define nl_Auto3677   "top-right"
#define pt_Auto3677   "top-right"
#define xx_Auto3677   "top-right"
#define en__Auto3677   ""
#define en_Auto3678   "bottom-right"
#define fr_Auto3678   "bottom-right"
#define it_Auto3678   "bottom-right"
#define es_Auto3678   "bottom-right"
#define de_Auto3678   "bottom-right"
#define nl_Auto3678   "bottom-right"
#define pt_Auto3678   "bottom-right"
#define xx_Auto3678   "bottom-right"
#define en__Auto3678   ""
#define en_ctlu   ""
#define en__ctlu   "specify top left corner image"
#define en_ctru   ""
#define en__ctru   "specify top right corner image"
#define en_cblu   ""
#define en__cblu   "specify bottom left corner image"
#define en_cbru   ""
#define en__cbru   "specify bottom right corner image"
#define en_blv   ""
#define en__blv   "specify the left border width value"
#define en__blt   "select the left border width metric"
#define fr__blt   "select the left border width metric"
#define it__blt   "select the left border width metric"
#define es__blt   "select the left border width metric"
#define de__blt   "select the left border width metric"
#define nl__blt   "select the left border width metric"
#define pt__blt   "select the left border width metric"
#define xx__blt   "select the left border width metric"
#define en__bdsv   "select the border style"
#define en_Auto3679   "top"
#define fr_Auto3679   "top"
#define it_Auto3679   "top"
#define es_Auto3679   "top"
#define de_Auto3679   "top"
#define nl_Auto3679   "top"
#define pt_Auto3679   "top"
#define xx_Auto3679   "top"
#define en__Auto3679   ""
#define fr__Auto3679   ""
#define it__Auto3679   ""
#define es__Auto3679   ""
#define de__Auto3679   ""
#define nl__Auto3679   ""
#define pt__Auto3679   ""
#define xx__Auto3679   ""
#define en_btv   ""
#define en__btv   "specify the top border width value"
#define en__btt   "select the top border width metric"
#define fr__btt   "select the top border width metric"
#define it__btt   "select the top border width metric"
#define es__btt   "select the top border width metric"
#define de__btt   "select the top border width metric"
#define nl__btt   "select the top border width metric"
#define pt__btt   "select the top border width metric"
#define xx__btt   "select the top border width metric"
#define en_Auto3680   "right"
#define fr_Auto3680   "right"
#define it_Auto3680   "right"
#define es_Auto3680   "right"
#define de_Auto3680   "right"
#define nl_Auto3680   "right"
#define pt_Auto3680   "right"
#define xx_Auto3680   "right"
#define en__Auto3680   ""
#define fr__Auto3680   ""
#define it__Auto3680   ""
#define es__Auto3680   ""
#define de__Auto3680   ""
#define nl__Auto3680   ""
#define pt__Auto3680   ""
#define xx__Auto3680   ""
#define en_brv   ""
#define en__brv   "specify the right border width value"
#define en_bwv   ""
#define en__bwv   "specify the border width value"
#define en__brt   "select the right border width metric"
#define fr__brt   "select the right border width metric"
#define it__brt   "select the right border width metric"
#define es__brt   "select the right border width metric"
#define de__brt   "select the right border width metric"
#define nl__brt   "select the right border width metric"
#define pt__brt   "select the right border width metric"
#define xx__brt   "select the right border width metric"
#define en__bwt   "select the border width metric"
#define fr__bwt   "select the border width metric"
#define it__bwt   "select the border width metric"
#define es__bwt   "select the border width metric"
#define de__bwt   "select the border width metric"
#define nl__bwt   "select the border width metric"
#define pt__bwt   "select the border width metric"
#define xx__bwt   "select the border width metric"
#define en_Auto3681   "bottom"
#define fr_Auto3681   "bottom"
#define it_Auto3681   "bottom"
#define es_Auto3681   "bottom"
#define de_Auto3681   "bottom"
#define nl_Auto3681   "bottom"
#define pt_Auto3681   "bottom"
#define xx_Auto3681   "bottom"
#define en__Auto3681   ""
#define fr__Auto3681   ""
#define it__Auto3681   ""
#define es__Auto3681   ""
#define de__Auto3681   ""
#define nl__Auto3681   ""
#define pt__Auto3681   ""
#define xx__Auto3681   ""
#define en_bbv   ""
#define en__bbv   "specify the bottom border width value"
#define en__bbt   "select the bottom border width metric"
#define fr__bbt   "select the bottom border width metric"
#define it__bbt   "select the bottom border width metric"
#define es__bbt   "select the bottom border width metric"
#define de__bbt   "select the bottom border width metric"
#define nl__bbt   "select the bottom border width metric"
#define pt__bbt   "select the bottom border width metric"
#define xx__bbt   "select the bottom border width metric"
#define en_PaddingPage   " Padding"
#define fr_PaddingPage   " Padding"
#define it_PaddingPage   " Padding"
#define es_PaddingPage   " Padding"
#define de_PaddingPage   " Padding"
#define nl_PaddingPage   " Padding"
#define pt_PaddingPage   " Padding"
#define xx_PaddingPage   " Padding"
#define en__PaddingPage   ""
#define en_Auto3682   "Margin"
#define fr_Auto3682   "Margin"
#define it_Auto3682   "Margin"
#define es_Auto3682   "Margin"
#define de_Auto3682   "Margin"
#define nl_Auto3682   "Margin"
#define pt_Auto3682   "Margin"
#define xx_Auto3682   "Margin"
#define en__Auto3682   ""
#define fr__Auto3682   ""
#define it__Auto3682   ""
#define es__Auto3682   ""
#define de__Auto3682   ""
#define nl__Auto3682   ""
#define pt__Auto3682   ""
#define xx__Auto3682   ""
#define en_Auto3683   "Border"
#define fr_Auto3683   "Border"
#define it_Auto3683   "Border"
#define es_Auto3683   "Border"
#define de_Auto3683   "Border"
#define nl_Auto3683   "Border"
#define pt_Auto3683   "Border"
#define xx_Auto3683   "Border"
#define en__Auto3683   ""
#define fr__Auto3683   ""
#define it__Auto3683   ""
#define es__Auto3683   ""
#define de__Auto3683   ""
#define nl__Auto3683   ""
#define pt__Auto3683   ""
#define xx__Auto3683   ""
#define en_Auto3684   "Padding"
#define fr_Auto3684   "Padding"
#define it_Auto3684   "Padding"
#define es_Auto3684   "Padding"
#define de_Auto3684   "Padding"
#define nl_Auto3684   "Padding"
#define pt_Auto3684   "Padding"
#define xx_Auto3684   "Padding"
#define en__Auto3684   ""
#define fr__Auto3684   ""
#define it__Auto3684   ""
#define es__Auto3684   ""
#define de__Auto3684   ""
#define nl__Auto3684   ""
#define pt__Auto3684   ""
#define xx__Auto3684   ""
#define en_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define fr_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define it_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define es_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define de_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define nl_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define pt_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define xx_Auto3685   "The term PADDING refers to space situated between the BORDER and the CONTENTS of the cell."
#define en__Auto3685   ""
#define fr__Auto3685   ""
#define it__Auto3685   ""
#define es__Auto3685   ""
#define de__Auto3685   ""
#define nl__Auto3685   ""
#define pt__Auto3685   ""
#define xx__Auto3685   ""
#define en_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define fr_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define it_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define es_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define de_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define nl_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define pt_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define xx_Auto3686   "All padding values may be set at once using the central control, or by using the individual side padding controls."
#define en__Auto3686   ""
#define fr__Auto3686   ""
#define it__Auto3686   ""
#define es__Auto3686   ""
#define de__Auto3686   ""
#define nl__Auto3686   ""
#define pt__Auto3686   ""
#define xx__Auto3686   ""
#define en_Auto3687   ""
#define en__Auto3687   ""
#define en_Auto3688   ""
#define en__Auto3688   ""
#define en_Auto3689   "left"
#define fr_Auto3689   "left"
#define it_Auto3689   "left"
#define es_Auto3689   "left"
#define de_Auto3689   "left"
#define nl_Auto3689   "left"
#define pt_Auto3689   "left"
#define xx_Auto3689   "left"
#define en__Auto3689   ""
#define fr__Auto3689   ""
#define it__Auto3689   ""
#define es__Auto3689   ""
#define de__Auto3689   ""
#define nl__Auto3689   ""
#define pt__Auto3689   ""
#define xx__Auto3689   ""
#define en_Auto3690   "padding"
#define fr_Auto3690   "padding"
#define it_Auto3690   "padding"
#define es_Auto3690   "padding"
#define de_Auto3690   "padding"
#define nl_Auto3690   "padding"
#define pt_Auto3690   "padding"
#define xx_Auto3690   "padding"
#define en__Auto3690   ""
#define fr__Auto3690   ""
#define it__Auto3690   ""
#define es__Auto3690   ""
#define de__Auto3690   ""
#define nl__Auto3690   ""
#define pt__Auto3690   ""
#define xx__Auto3690   ""
#define en_plv   ""
#define en__plv   "specify the left padding value"
#define en__plt   "select the left padding metric"
#define fr__plt   "select the left padding metric"
#define it__plt   "select the left padding metric"
#define es__plt   "select the left padding metric"
#define de__plt   "select the left padding metric"
#define nl__plt   "select the left padding metric"
#define pt__plt   "select the left padding metric"
#define xx__plt   "select the left padding metric"
#define en_pgv   ""
#define en__pgv   "specify the overall padding value"
#define en__pgt   "select the general padding metric"
#define fr__pgt   "select the general padding metric"
#define it__pgt   "select the general padding metric"
#define es__pgt   "select the general padding metric"
#define de__pgt   "select the general padding metric"
#define nl__pgt   "select the general padding metric"
#define pt__pgt   "select the general padding metric"
#define xx__pgt   "select the general padding metric"
#define en_Auto3691   "top"
#define fr_Auto3691   "top"
#define it_Auto3691   "top"
#define es_Auto3691   "top"
#define de_Auto3691   "top"
#define nl_Auto3691   "top"
#define pt_Auto3691   "top"
#define xx_Auto3691   "top"
#define en__Auto3691   ""
#define fr__Auto3691   ""
#define it__Auto3691   ""
#define es__Auto3691   ""
#define de__Auto3691   ""
#define nl__Auto3691   ""
#define pt__Auto3691   ""
#define xx__Auto3691   ""
#define en_ptv   ""
#define en__ptv   "specify the top padding value"
#define en__ptt   "select the top padding metric"
#define fr__ptt   "select the top padding metric"
#define it__ptt   "select the top padding metric"
#define es__ptt   "select the top padding metric"
#define de__ptt   "select the top padding metric"
#define nl__ptt   "select the top padding metric"
#define pt__ptt   "select the top padding metric"
#define xx__ptt   "select the top padding metric"
#define en_Auto3692   "right"
#define fr_Auto3692   "right"
#define it_Auto3692   "right"
#define es_Auto3692   "right"
#define de_Auto3692   "right"
#define nl_Auto3692   "right"
#define pt_Auto3692   "right"
#define xx_Auto3692   "right"
#define en__Auto3692   ""
#define fr__Auto3692   ""
#define it__Auto3692   ""
#define es__Auto3692   ""
#define de__Auto3692   ""
#define nl__Auto3692   ""
#define pt__Auto3692   ""
#define xx__Auto3692   ""
#define en_prv   ""
#define en__prv   "specify the right padding value"
#define en__prt   "select the right padding metric"
#define fr__prt   "select the right padding metric"
#define it__prt   "select the right padding metric"
#define es__prt   "select the right padding metric"
#define de__prt   "select the right padding metric"
#define nl__prt   "select the right padding metric"
#define pt__prt   "select the right padding metric"
#define xx__prt   "select the right padding metric"
#define en_Auto3693   "bottom"
#define fr_Auto3693   "bottom"
#define it_Auto3693   "bottom"
#define es_Auto3693   "bottom"
#define de_Auto3693   "bottom"
#define nl_Auto3693   "bottom"
#define pt_Auto3693   "bottom"
#define xx_Auto3693   "bottom"
#define en__Auto3693   ""
#define fr__Auto3693   ""
#define it__Auto3693   ""
#define es__Auto3693   ""
#define de__Auto3693   ""
#define nl__Auto3693   ""
#define pt__Auto3693   ""
#define xx__Auto3693   ""
#define en_pbv   ""
#define en__pbv   "specify the bottom padding value"
#define en__pbt   "select the bottom padding metric"
#define fr__pbt   "select the bottom padding metric"
#define it__pbt   "select the bottom padding metric"
#define es__pbt   "select the bottom padding metric"
#define de__pbt   "select the bottom padding metric"
#define nl__pbt   "select the bottom padding metric"
#define pt__pbt   "select the bottom padding metric"
#define xx__pbt   "select the bottom padding metric"
#define en_BGPage   " Background"
#define fr_BGPage   " Background"
#define it_BGPage   " Background"
#define es_BGPage   " Background"
#define de_BGPage   " Background"
#define nl_BGPage   " Background"
#define pt_BGPage   " Background"
#define xx_BGPage   " Background"
#define en__BGPage   ""
#define en_Auto3694   "Margin"
#define fr_Auto3694   "Margin"
#define it_Auto3694   "Margin"
#define es_Auto3694   "Margin"
#define de_Auto3694   "Margin"
#define nl_Auto3694   "Margin"
#define pt_Auto3694   "Margin"
#define xx_Auto3694   "Margin"
#define en__Auto3694   ""
#define fr__Auto3694   ""
#define it__Auto3694   ""
#define es__Auto3694   ""
#define de__Auto3694   ""
#define nl__Auto3694   ""
#define pt__Auto3694   ""
#define xx__Auto3694   ""
#define en_Auto3695   "Border"
#define fr_Auto3695   "Border"
#define it_Auto3695   "Border"
#define es_Auto3695   "Border"
#define de_Auto3695   "Border"
#define nl_Auto3695   "Border"
#define pt_Auto3695   "Border"
#define xx_Auto3695   "Border"
#define en__Auto3695   ""
#define fr__Auto3695   ""
#define it__Auto3695   ""
#define es__Auto3695   ""
#define de__Auto3695   ""
#define nl__Auto3695   ""
#define pt__Auto3695   ""
#define xx__Auto3695   ""
#define en_Auto3696   "Padding"
#define fr_Auto3696   "Padding"
#define it_Auto3696   "Padding"
#define es_Auto3696   "Padding"
#define de_Auto3696   "Padding"
#define nl_Auto3696   "Padding"
#define pt_Auto3696   "Padding"
#define xx_Auto3696   "Padding"
#define en__Auto3696   ""
#define fr__Auto3696   ""
#define it__Auto3696   ""
#define es__Auto3696   ""
#define de__Auto3696   ""
#define nl__Auto3696   ""
#define pt__Auto3696   ""
#define xx__Auto3696   ""
#define en_Auto3697   "Background"
#define fr_Auto3697   "Background"
#define it_Auto3697   "Background"
#define es_Auto3697   "Background"
#define de_Auto3697   "Background"
#define nl_Auto3697   "Background"
#define pt_Auto3697   "Background"
#define xx_Auto3697   "Background"
#define en__Auto3697   ""
#define fr__Auto3697   ""
#define it__Auto3697   ""
#define es__Auto3697   ""
#define de__Auto3697   ""
#define nl__Auto3697   ""
#define pt__Auto3697   ""
#define xx__Auto3697   ""
#define en_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define fr_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define it_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define es_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define de_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define nl_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define pt_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define xx_Auto3698   "The term BACKGROUND covers to the area comprising the PADDING and the cell CONTENTS and is inside of the BORDER."
#define en__Auto3698   ""
#define en_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define fr_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define it_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define es_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define de_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define nl_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define pt_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define xx_Auto3699   "The BACKGROUND may be covered by an image or filled using a solid background colour."
#define en__Auto3699   ""
#define en_Auto3700   "image"
#define fr_Auto3700   "image"
#define it_Auto3700   "image"
#define es_Auto3700   "image"
#define de_Auto3700   "image"
#define nl_Auto3700   "image"
#define pt_Auto3700   "image"
#define xx_Auto3700   "image"
#define en__Auto3700   ""
#define en_Auto3701   "align"
#define fr_Auto3701   "align"
#define it_Auto3701   "align"
#define es_Auto3701   "align"
#define de_Auto3701   "align"
#define nl_Auto3701   "align"
#define pt_Auto3701   "align"
#define xx_Auto3701   "align"
#define en__Auto3701   ""
#define fr__Auto3701   ""
#define it__Auto3701   ""
#define es__Auto3701   ""
#define de__Auto3701   ""
#define nl__Auto3701   ""
#define pt__Auto3701   ""
#define xx__Auto3701   ""
#define en_Auto3702   "mode"
#define fr_Auto3702   "mode"
#define it_Auto3702   "mode"
#define es_Auto3702   "mode"
#define de_Auto3702   "mode"
#define nl_Auto3702   "mode"
#define pt_Auto3702   "mode"
#define xx_Auto3702   "mode"
#define en__Auto3702   ""
#define fr__Auto3702   ""
#define it__Auto3702   ""
#define es__Auto3702   ""
#define de__Auto3702   ""
#define nl__Auto3702   ""
#define pt__Auto3702   ""
#define xx__Auto3702   ""
#define en_Auto3703   "colour"
#define fr_Auto3703   "colour"
#define it_Auto3703   "colour"
#define es_Auto3703   "colour"
#define de_Auto3703   "colour"
#define nl_Auto3703   "colour"
#define pt_Auto3703   "colour"
#define xx_Auto3703   "colour"
#define en__Auto3703   ""
#define fr__Auto3703   ""
#define it__Auto3703   ""
#define es__Auto3703   ""
#define de__Auto3703   ""
#define nl__Auto3703   ""
#define pt__Auto3703   ""
#define xx__Auto3703   ""
#define en_bgi   ""
#define en__bgi   "specify the background image filename"
#define en__bgia   "select the background image alignment value"
#define fr__bgia   "select the background image alignment value"
#define it__bgia   "select the background image alignment value"
#define es__bgia   "select the background image alignment value"
#define de__bgia   "select the background image alignment value"
#define nl__bgia   "select the background image alignment value"
#define pt__bgia   "select the background image alignment value"
#define xx__bgia   "select the background image alignment value"
#define en__bgitr   "select the background image display mode"
#define fr__bgitr   "select the background image display mode"
#define it__bgitr   "select the background image display mode"
#define es__bgitr   "select the background image display mode"
#define de__bgitr   "select the background image display mode"
#define nl__bgitr   "select the background image display mode"
#define pt__bgitr   "select the background image display mode"
#define xx__bgitr   "select the background image display mode"
#define en__bgct   "select the background colour type or name"
#define fr__bgct   "select the background colour type or name"
#define it__bgct   "select the background colour type or name"
#define es__bgct   "select the background colour type or name"
#define de__bgct   "select the background colour type or name"
#define nl__bgct   "select the background colour type or name"
#define pt__bgct   "select the background colour type or name"
#define xx__bgct   "select the background colour type or name"
#define en_bgcv   ""
#define en__bgcv   "specify the background colour rgb or ihm value"
#define en_ContentPage   " Content"
#define fr_ContentPage   " Content"
#define it_ContentPage   " Content"
#define es_ContentPage   " Content"
#define de_ContentPage   " Content"
#define nl_ContentPage   " Content"
#define pt_ContentPage   " Content"
#define xx_ContentPage   " Content"
#define en__ContentPage   ""
#define en_Auto3704   "Margin"
#define fr_Auto3704   "Margin"
#define it_Auto3704   "Margin"
#define es_Auto3704   "Margin"
#define de_Auto3704   "Margin"
#define nl_Auto3704   "Margin"
#define pt_Auto3704   "Margin"
#define xx_Auto3704   "Margin"
#define en__Auto3704   ""
#define fr__Auto3704   ""
#define it__Auto3704   ""
#define es__Auto3704   ""
#define de__Auto3704   ""
#define nl__Auto3704   ""
#define pt__Auto3704   ""
#define xx__Auto3704   ""
#define en_Auto3705   "Border"
#define fr_Auto3705   "Border"
#define it_Auto3705   "Border"
#define es_Auto3705   "Border"
#define de_Auto3705   "Border"
#define nl_Auto3705   "Border"
#define pt_Auto3705   "Border"
#define xx_Auto3705   "Border"
#define en__Auto3705   ""
#define fr__Auto3705   ""
#define it__Auto3705   ""
#define es__Auto3705   ""
#define de__Auto3705   ""
#define nl__Auto3705   ""
#define pt__Auto3705   ""
#define xx__Auto3705   ""
#define en_Auto3706   "Padding"
#define fr_Auto3706   "Padding"
#define it_Auto3706   "Padding"
#define es_Auto3706   "Padding"
#define de_Auto3706   "Padding"
#define nl_Auto3706   "Padding"
#define pt_Auto3706   "Padding"
#define xx_Auto3706   "Padding"
#define en__Auto3706   ""
#define fr__Auto3706   ""
#define it__Auto3706   ""
#define es__Auto3706   ""
#define de__Auto3706   ""
#define nl__Auto3706   ""
#define pt__Auto3706   ""
#define xx__Auto3706   ""
#define en_Auto3707   "Text"
#define fr_Auto3707   "Text"
#define it_Auto3707   "Text"
#define es_Auto3707   "Text"
#define de_Auto3707   "Text"
#define nl_Auto3707   "Text"
#define pt_Auto3707   "Text"
#define xx_Auto3707   "Text"
#define en__Auto3707   ""
#define fr__Auto3707   ""
#define it__Auto3707   ""
#define es__Auto3707   ""
#define de__Auto3707   ""
#define nl__Auto3707   ""
#define pt__Auto3707   ""
#define xx__Auto3707   ""
#define en_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define fr_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define it_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define es_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define de_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define nl_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define pt_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define xx_Auto3708   "The term TEXT refers to an eventual textual content payload to be styled withing the cell."
#define en__Auto3708   ""
#define fr__Auto3708   ""
#define it__Auto3708   ""
#define es__Auto3708   ""
#define de__Auto3708   ""
#define nl__Auto3708   ""
#define pt__Auto3708   ""
#define xx__Auto3708   ""
#define en_Auto3709   "font"
#define fr_Auto3709   "font"
#define it_Auto3709   "font"
#define es_Auto3709   "font"
#define de_Auto3709   "font"
#define nl_Auto3709   "font"
#define pt_Auto3709   "font"
#define xx_Auto3709   "font"
#define en__Auto3709   ""
#define fr__Auto3709   ""
#define it__Auto3709   ""
#define es__Auto3709   ""
#define de__Auto3709   ""
#define nl__Auto3709   ""
#define pt__Auto3709   ""
#define xx__Auto3709   ""
#define en_Auto3710   "colour"
#define fr_Auto3710   "colour"
#define it_Auto3710   "colour"
#define es_Auto3710   "colour"
#define de_Auto3710   "colour"
#define nl_Auto3710   "colour"
#define pt_Auto3710   "colour"
#define xx_Auto3710   "colour"
#define en__Auto3710   ""
#define fr__Auto3710   ""
#define it__Auto3710   ""
#define es__Auto3710   ""
#define de__Auto3710   ""
#define nl__Auto3710   ""
#define pt__Auto3710   ""
#define xx__Auto3710   ""
#define en_Auto3711   "align"
#define fr_Auto3711   "align"
#define it_Auto3711   "align"
#define es_Auto3711   "align"
#define de_Auto3711   "align"
#define nl_Auto3711   "align"
#define pt_Auto3711   "align"
#define xx_Auto3711   "align"
#define en__Auto3711   ""
#define fr__Auto3711   ""
#define it__Auto3711   ""
#define es__Auto3711   ""
#define de__Auto3711   ""
#define nl__Auto3711   ""
#define pt__Auto3711   ""
#define xx__Auto3711   ""
#define en_Auto3712   "decoration"
#define fr_Auto3712   "decoration"
#define it_Auto3712   "decoration"
#define es_Auto3712   "decoration"
#define de_Auto3712   "decoration"
#define nl_Auto3712   "decoration"
#define pt_Auto3712   "decoration"
#define xx_Auto3712   "decoration"
#define en__Auto3712   ""
#define fr__Auto3712   ""
#define it__Auto3712   ""
#define es__Auto3712   ""
#define de__Auto3712   ""
#define nl__Auto3712   ""
#define pt__Auto3712   ""
#define xx__Auto3712   ""
#define en_txtol   "Overline"
#define fr_txtol   "Overline"
#define it_txtol   "Overline"
#define es_txtol   "Overline"
#define de_txtol   "Overline"
#define nl_txtol   "Overline"
#define pt_txtol   "Overline"
#define xx_txtol   "Overline"
#define en__txtol   "check this to activate overlining of text"
#define en_txtlt   "Line Through"
#define fr_txtlt   "Line Through"
#define it_txtlt   "Line Through"
#define es_txtlt   "Line Through"
#define de_txtlt   "Line Through"
#define nl_txtlt   "Line Through"
#define pt_txtlt   "Line Through"
#define xx_txtlt   "Line Through"
#define en__txtlt   "check this to activate strike through of text"
#define en_txtul   "Underline"
#define fr_txtul   "Underline"
#define it_txtul   "Underline"
#define es_txtul   "Underline"
#define de_txtul   "Underline"
#define nl_txtul   "Underline"
#define pt_txtul   "Underline"
#define xx_txtul   "Underline"
#define en__txtul   "check this to activate underlining of text"
#define en_txtbo   "Bold"
#define fr_txtbo   "Bold"
#define it_txtbo   "Bold"
#define es_txtbo   "Bold"
#define de_txtbo   "Bold"
#define nl_txtbo   "Bold"
#define pt_txtbo   "Bold"
#define xx_txtbo   "Bold"
#define en__txtbo   "check this to activate bold of text"
#define en_txtsh   "Shadow"
#define fr_txtsh   "Shadow"
#define it_txtsh   "Shadow"
#define es_txtsh   "Shadow"
#define de_txtsh   "Shadow"
#define nl_txtsh   "Shadow"
#define pt_txtsh   "Shadow"
#define xx_txtsh   "Shadow"
#define en__txtsh   "check this to activate shadowed text"
#define en_txtbl   "Blink"
#define fr_txtbl   "Blink"
#define it_txtbl   "Blink"
#define es_txtbl   "Blink"
#define de_txtbl   "Blink"
#define nl_txtbl   "Blink"
#define pt_txtbl   "Blink"
#define xx_txtbl   "Blink"
#define en__txtbl   "check this to activate blinking text"
#define en_Auto3713   "letter-spacing"
#define fr_Auto3713   "letter-spacing"
#define it_Auto3713   "letter-spacing"
#define es_Auto3713   "letter-spacing"
#define de_Auto3713   "letter-spacing"
#define nl_Auto3713   "letter-spacing"
#define pt_Auto3713   "letter-spacing"
#define xx_Auto3713   "letter-spacing"
#define en__Auto3713   ""
#define fr__Auto3713   ""
#define it__Auto3713   ""
#define es__Auto3713   ""
#define de__Auto3713   ""
#define nl__Auto3713   ""
#define pt__Auto3713   ""
#define xx__Auto3713   ""
#define en_Auto3714   "word-spacing"
#define fr_Auto3714   "word-spacing"
#define it_Auto3714   "word-spacing"
#define es_Auto3714   "word-spacing"
#define de_Auto3714   "word-spacing"
#define nl_Auto3714   "word-spacing"
#define pt_Auto3714   "word-spacing"
#define xx_Auto3714   "word-spacing"
#define en__Auto3714   ""
#define fr__Auto3714   ""
#define it__Auto3714   ""
#define es__Auto3714   ""
#define de__Auto3714   ""
#define nl__Auto3714   ""
#define pt__Auto3714   ""
#define xx__Auto3714   ""
#define en_Auto3715   "line-spacing"
#define fr_Auto3715   "line-spacing"
#define it_Auto3715   "line-spacing"
#define es_Auto3715   "line-spacing"
#define de_Auto3715   "line-spacing"
#define nl_Auto3715   "line-spacing"
#define pt_Auto3715   "line-spacing"
#define xx_Auto3715   "line-spacing"
#define en__Auto3715   ""
#define fr__Auto3715   ""
#define it__Auto3715   ""
#define es__Auto3715   ""
#define de__Auto3715   ""
#define nl__Auto3715   ""
#define pt__Auto3715   ""
#define xx__Auto3715   ""
#define en_Auto3716   "test message"
#define fr_Auto3716   "test message"
#define it_Auto3716   "test message"
#define es_Auto3716   "test message"
#define de_Auto3716   "test message"
#define nl_Auto3716   "test message"
#define pt_Auto3716   "test message"
#define xx_Auto3716   "test message"
#define en__Auto3716   ""
#define fr__Auto3716   ""
#define it__Auto3716   ""
#define es__Auto3716   ""
#define de__Auto3716   ""
#define nl__Auto3716   ""
#define pt__Auto3716   ""
#define xx__Auto3716   ""
#define en_txfu   ""
#define en__txfu   "specify the filename of the text font"
#define en__txct   "select the text colour type or value"
#define fr__txct   "select the text colour type or value"
#define it__txct   "select the text colour type or value"
#define es__txct   "select the text colour type or value"
#define de__txct   "select the text colour type or value"
#define nl__txct   "select the text colour type or value"
#define pt__txct   "select the text colour type or value"
#define xx__txct   "select the text colour type or value"
#define en_txcv   ""
#define en__txcv   "specify the rgb or ihm colour value"
#define en__txta   "select the text alignment value"
#define fr__txta   "select the text alignment value"
#define it__txta   "select the text alignment value"
#define es__txta   "select the text alignment value"
#define de__txta   "select the text alignment value"
#define nl__txta   "select the text alignment value"
#define pt__txta   "select the text alignment value"
#define xx__txta   "select the text alignment value"
#define en_ltspv   ""
#define en__ltspv   "specify the letter spacing value"
#define en__ltspt   "select the letter spacing metric"
#define fr__ltspt   "select the letter spacing metric"
#define it__ltspt   "select the letter spacing metric"
#define es__ltspt   "select the letter spacing metric"
#define de__ltspt   "select the letter spacing metric"
#define nl__ltspt   "select the letter spacing metric"
#define pt__ltspt   "select the letter spacing metric"
#define xx__ltspt   "select the letter spacing metric"
#define en_wspv   ""
#define en__wspv   "specify the word spacing value"
#define en__wspt   "select the word spacing metric"
#define fr__wspt   "select the word spacing metric"
#define it__wspt   "select the word spacing metric"
#define es__wspt   "select the word spacing metric"
#define de__wspt   "select the word spacing metric"
#define nl__wspt   "select the word spacing metric"
#define pt__wspt   "select the word spacing metric"
#define xx__wspt   "select the word spacing metric"
#define en_lnspv   ""
#define en__lnspv   "specify the line spacing value"
#define en__lnspt   "select the line spacing metric"
#define fr__lnspt   "select the line spacing metric"
#define it__lnspt   "select the line spacing metric"
#define es__lnspt   "select the line spacing metric"
#define de__lnspt   "select the line spacing metric"
#define nl__lnspt   "select the line spacing metric"
#define pt__lnspt   "select the line spacing metric"
#define xx__lnspt   "select the line spacing metric"
#define en_Message   ""
#define en__Message   "specify the text of the style test message or image"

private struct cstyleman_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[9+1];
	char * msg_Auto3628[8];
	char * hint_Auto3628[8];
	int	x_Auto3628;
	int	y_Auto3628;
	int	w_Auto3628;
	int	h_Auto3628;
	char * msg_Auto3629[8];
	int	trigger_Auto3629;
	char * hint_Auto3629[8];
	char * msg_Trash[8];
	int	trigger_Trash;
	char * hint_Trash[8];
	char * msg_Trace[8];
	int	trigger_Trace;
	char * hint_Trace[8];
	int	s_Trace;
	void *	p_Trace;
	char * msg_Classes[8];
	char * hint_Classes[8];
	char * msg_Files[8];
	char * hint_Files[8];
	char * msg_FileWork[8];
	char * hint_FileWork[8];
	char * msg_ImportFile[8];
	char * hint_ImportFile[8];
	char * msg_Members[8];
	char * hint_Members[8];
	char * msg_ImportMember[8];
	char * hint_ImportMember[8];
	char * msg_Worker[8];
	char * hint_Worker[8];
	char * msg_CLPage[8];
	int	trigger_CLPage;
	char * hint_CLPage[8];
	int	page_number;
	char * msg_ClassList[8];
	char * hint_ClassList[8];
	int	value_ClassList;
	int	column_ClassList;
	char	buffer_ClassList[15][93];
	int	formsort_ClassList;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_ClassList;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_ClassList;	/* numéro d'ordre des elements triés */
	char	*indsort_ClassList;	/* pointeur table intermédiaire de tri */
	int	nelt_ClassList;	/* nombre d'eléments aloués dans tabsort */
	char * row_ClassList;
	char * hint_CLCursor[8];
	int	x_CLCursor;
	int	y_CLCursor;
	int	w_CLCursor;
	int	h_CLCursor;
	int	fg_CLCursor;
	int	bg_CLCursor;
	int	fid_CLCursor;
	char * hint_Action[8];
	int	x_Action;
	int	y_Action;
	int	w_Action;
	int	h_Action;
	int	fg_Action;
	int	bg_Action;
	int	fid_Action;
	int	s_Action;
	void *	p_Action;
	char	buffer_Action[256];
	char * msg_FileList[8];
	char * hint_FileList[8];
	int	value_FileList;
	int	column_FileList;
	char	buffer_FileList[16][47];
	int	formsort_FileList;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_FileList;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_FileList;	/* numéro d'ordre des elements triés */
	char	*indsort_FileList;	/* pointeur table intermédiaire de tri */
	int	nelt_FileList;	/* nombre d'eléments aloués dans tabsort */
	char * row_FileList;
	char * hint_FLCursor[8];
	int	x_FLCursor;
	int	y_FLCursor;
	int	w_FLCursor;
	int	h_FLCursor;
	int	fg_FLCursor;
	int	bg_FLCursor;
	int	fid_FLCursor;
	char * msg_CFList[8];
	char * hint_CFList[8];
	int	value_CFList;
	int	column_CFList;
	char	buffer_CFList[16][43];
	int	formsort_CFList;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_CFList;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_CFList;	/* numéro d'ordre des elements triés */
	char	*indsort_CFList;	/* pointeur table intermédiaire de tri */
	int	nelt_CFList;	/* nombre d'eléments aloués dans tabsort */
	char * row_CFList;
	char * hint_MLCursor[8];
	int	x_MLCursor;
	int	y_MLCursor;
	int	w_MLCursor;
	int	h_MLCursor;
	int	fg_MLCursor;
	int	bg_MLCursor;
	int	fid_MLCursor;
	char * hint_CLBar[8];
	int	value_CLBar;
	int	limit_CLBar;
	int	max_CLBar;
	char * hint_MLBar[8];
	int	value_MLBar;
	int	limit_MLBar;
	int	max_MLBar;
	char * hint_FLBar[8];
	int	value_FLBar;
	int	limit_FLBar;
	int	max_FLBar;
	char * msg_StylePage[8];
	int	trigger_StylePage;
	char * hint_StylePage[8];
	char * hint_Auto3630[8];
	char * msg_ExportNameError[8];
	char * hint_ExportNameError[8];
	char * hint_StatusBar[8];
	char	buffer_StatusBar[256];
	char * msg_Auto3631[8];
	char * hint_Auto3631[8];
	char * msg_Auto3632[8];
	char * hint_Auto3632[8];
	char * msg_Auto3633[8];
	char * hint_Auto3633[8];
	char * msg_Auto3634[8];
	char * hint_Auto3634[8];
	char * msg_Auto3635[8];
	char * hint_Auto3635[8];
	char * msg_Auto3636[8];
	char * hint_Auto3636[8];
	char * msg_Auto3637[8];
	char * hint_Auto3637[8];
	char * hint_ClassName[8];
	char	buffer_ClassName[256];
	char * msg_LoadOperation[8];
	int	trigger_LoadOperation;
	char * hint_LoadOperation[8];
	char * msg_Reset[8];
	int	trigger_Reset;
	char * hint_Reset[8];
	char * hint_BaseClass[8];
	char	buffer_BaseClass[256];
	char * hint_Description[8];
	char	buffer_Description[256];
	char * hint_ClassFile[8];
	char	buffer_ClassFile[256];
	char * msg_SaveOperation[8];
	int	trigger_SaveOperation;
	char * hint_SaveOperation[8];
	char * msg_ViewFile[8];
	int	trigger_ViewFile;
	char * hint_ViewFile[8];
	char * hint_ExportName[8];
	char	buffer_ExportName[256];
	char * msg_ExportOperation[8];
	int	trigger_ExportOperation;
	char * hint_ExportOperation[8];
	char * msg_ViewExport[8];
	int	trigger_ViewExport;
	char * hint_ViewExport[8];
	char * hint_ImportName[8];
	char	buffer_ImportName[256];
	char * msg_ImportOperation[8];
	int	trigger_ImportOperation;
	char * hint_ImportOperation[8];
	char * msg_ViewImport[8];
	int	trigger_ViewImport;
	char * hint_ViewImport[8];
	char * msg_TestPage[8];
	int	trigger_TestPage;
	char * hint_TestPage[8];
	char * msg_Thing[8];
	int	trigger_Thing;
	char * hint_Thing[8];
	int	x_Thing;
	int	y_Thing;
	int	w_Thing;
	int	h_Thing;
	int	fg_Thing;
	int	bg_Thing;
	int	fid_Thing;
	int	s_Thing;
	void *	p_Thing;
	char * msg_Cell[8];
	int	trigger_Cell;
	char * hint_Cell[8];
	char * msg_Auto3638[8];
	char * hint_Auto3638[8];
	char * msg_Auto3639[8];
	char * hint_Auto3639[8];
	char * hint_Auto3640[8];
	char * hint_Auto3641[8];
	char * msg_Auto3642[8];
	char * hint_Auto3642[8];
	char * msg_Auto3643[8];
	char * hint_Auto3643[8];
	char * msg_Auto3644[8];
	char * hint_Auto3644[8];
	char * msg_Auto3645[8];
	char * hint_Auto3645[8];
	char * msg_Auto3646[8];
	char * hint_Auto3646[8];
	char * msg_Auto3647[8];
	char * hint_Auto3647[8];
	char * msg_Auto3648[8];
	char * hint_Auto3648[8];
	char * msg_Auto3649[8];
	char * hint_Auto3649[8];
	char * msg_Auto3650[8];
	char * hint_Auto3650[8];
	char * msg_ct[8];
	char * hint_ct[8];
	int	value_ct;
	char * msg_posv[8];
	char * hint_posv[8];
	int	value_posv;
	char * hint_cwv[8];
	char	buffer_cwv[10];
	char * msg_cwt[8];
	char * hint_cwt[8];
	int	value_cwt;
	char * hint_chv[8];
	char	buffer_chv[10];
	char * msg_cht[8];
	char * hint_cht[8];
	int	value_cht;
	char * hint_cplv[8];
	char	buffer_cplv[10];
	char * msg_cplt[8];
	char * hint_cplt[8];
	int	value_cplt;
	char * hint_cptv[8];
	char	buffer_cptv[10];
	char * hint_cprv[8];
	char	buffer_cprv[10];
	char * hint_cpbv[8];
	char	buffer_cpbv[10];
	char * msg_cptt[8];
	char * hint_cptt[8];
	int	value_cptt;
	char * msg_cprt[8];
	char * hint_cprt[8];
	int	value_cprt;
	char * msg_cpbt[8];
	char * hint_cpbt[8];
	int	value_cpbt;
	char * msg_MarginPage[8];
	int	trigger_MarginPage;
	char * hint_MarginPage[8];
	char * msg_Auto3651[8];
	char * hint_Auto3651[8];
	char * msg_Auto3652[8];
	char * hint_Auto3652[8];
	char * msg_Auto3653[8];
	char * hint_Auto3653[8];
	char * hint_Auto3654[8];
	char * hint_Auto3655[8];
	char * msg_Auto3656[8];
	char * hint_Auto3656[8];
	char * msg_Auto3657[8];
	char * hint_Auto3657[8];
	char * msg_Auto3658[8];
	char * hint_Auto3658[8];
	char * msg_Auto3659[8];
	char * hint_Auto3659[8];
	char * msg_Auto3660[8];
	char * hint_Auto3660[8];
	char * hint_mlv[8];
	char	buffer_mlv[10];
	char * msg_mlt[8];
	char * hint_mlt[8];
	int	value_mlt;
	char * hint_mgv[8];
	char	buffer_mgv[10];
	char * msg_mgt[8];
	char * hint_mgt[8];
	int	value_mgt;
	char * hint_mtv[8];
	char	buffer_mtv[10];
	char * msg_mtt[8];
	char * hint_mtt[8];
	int	value_mtt;
	char * hint_mrv[8];
	char	buffer_mrv[10];
	char * msg_mrt[8];
	char * hint_mrt[8];
	int	value_mrt;
	char * hint_mbv[8];
	char	buffer_mbv[10];
	char * msg_mbt[8];
	char * hint_mbt[8];
	int	value_mbt;
	char * msg_BorderPage[8];
	int	trigger_BorderPage;
	char * hint_BorderPage[8];
	char * msg_Auto3661[8];
	char * hint_Auto3661[8];
	char * msg_Auto3662[8];
	char * hint_Auto3662[8];
	char * msg_Auto3663[8];
	char * hint_Auto3663[8];
	char * msg_Auto3664[8];
	char * hint_Auto3664[8];
	char * msg_Auto3665[8];
	char * hint_Auto3665[8];
	char * msg_Auto3666[8];
	char * hint_Auto3666[8];
	char * msg_bdct[8];
	char * hint_bdct[8];
	int	value_bdct;
	char * hint_bdcv[8];
	char	buffer_bdcv[10];
	char * msg_bdat[8];
	char * hint_bdat[8];
	int	value_bdat;
	char * hint_Auto3667[8];
	char * hint_Auto3668[8];
	char * msg_Auto3669[8];
	char * hint_Auto3669[8];
	char * msg_Auto3670[8];
	char * hint_Auto3670[8];
	char * msg_Auto3671[8];
	char * hint_Auto3671[8];
	char * msg_Auto3672[8];
	char * hint_Auto3672[8];
	char * hint_blu[8];
	char	buffer_blu[256];
	char * msg_Auto3673[8];
	char * hint_Auto3673[8];
	char * msg_Auto3674[8];
	char * hint_Auto3674[8];
	char * hint_btu[8];
	char	buffer_btu[256];
	char * msg_Auto3675[8];
	char * hint_Auto3675[8];
	char * hint_bbu[8];
	char	buffer_bbu[256];
	char * hint_bru[8];
	char	buffer_bru[256];
	char * msg_Auto3676[8];
	char * hint_Auto3676[8];
	char * msg_Auto3677[8];
	char * hint_Auto3677[8];
	char * msg_Auto3678[8];
	char * hint_Auto3678[8];
	char * hint_ctlu[8];
	char	buffer_ctlu[256];
	char * hint_ctru[8];
	char	buffer_ctru[256];
	char * hint_cblu[8];
	char	buffer_cblu[256];
	char * hint_cbru[8];
	char	buffer_cbru[256];
	char * hint_blv[8];
	char	buffer_blv[10];
	char * msg_blt[8];
	char * hint_blt[8];
	int	value_blt;
	char * msg_bdsv[8];
	char * hint_bdsv[8];
	int	value_bdsv;
	char * msg_Auto3679[8];
	char * hint_Auto3679[8];
	char * hint_btv[8];
	char	buffer_btv[10];
	char * msg_btt[8];
	char * hint_btt[8];
	int	value_btt;
	char * msg_Auto3680[8];
	char * hint_Auto3680[8];
	char * hint_brv[8];
	char	buffer_brv[10];
	char * hint_bwv[8];
	char	buffer_bwv[10];
	char * msg_brt[8];
	char * hint_brt[8];
	int	value_brt;
	char * msg_bwt[8];
	char * hint_bwt[8];
	int	value_bwt;
	char * msg_Auto3681[8];
	char * hint_Auto3681[8];
	char * hint_bbv[8];
	char	buffer_bbv[10];
	char * msg_bbt[8];
	char * hint_bbt[8];
	int	value_bbt;
	char * msg_PaddingPage[8];
	int	trigger_PaddingPage;
	char * hint_PaddingPage[8];
	char * msg_Auto3682[8];
	char * hint_Auto3682[8];
	char * msg_Auto3683[8];
	char * hint_Auto3683[8];
	char * msg_Auto3684[8];
	char * hint_Auto3684[8];
	char * msg_Auto3685[8];
	char * hint_Auto3685[8];
	char * msg_Auto3686[8];
	char * hint_Auto3686[8];
	char * hint_Auto3687[8];
	char * hint_Auto3688[8];
	char * msg_Auto3689[8];
	char * hint_Auto3689[8];
	char * msg_Auto3690[8];
	char * hint_Auto3690[8];
	char * hint_plv[8];
	char	buffer_plv[10];
	char * msg_plt[8];
	char * hint_plt[8];
	int	value_plt;
	char * hint_pgv[8];
	char	buffer_pgv[10];
	char * msg_pgt[8];
	char * hint_pgt[8];
	int	value_pgt;
	char * msg_Auto3691[8];
	char * hint_Auto3691[8];
	char * hint_ptv[8];
	char	buffer_ptv[10];
	char * msg_ptt[8];
	char * hint_ptt[8];
	int	value_ptt;
	char * msg_Auto3692[8];
	char * hint_Auto3692[8];
	char * hint_prv[8];
	char	buffer_prv[10];
	char * msg_prt[8];
	char * hint_prt[8];
	int	value_prt;
	char * msg_Auto3693[8];
	char * hint_Auto3693[8];
	char * hint_pbv[8];
	char	buffer_pbv[10];
	char * msg_pbt[8];
	char * hint_pbt[8];
	int	value_pbt;
	char * msg_BGPage[8];
	int	trigger_BGPage;
	char * hint_BGPage[8];
	char * msg_Auto3694[8];
	char * hint_Auto3694[8];
	char * msg_Auto3695[8];
	char * hint_Auto3695[8];
	char * msg_Auto3696[8];
	char * hint_Auto3696[8];
	char * msg_Auto3697[8];
	char * hint_Auto3697[8];
	char * msg_Auto3698[8];
	char * hint_Auto3698[8];
	char * msg_Auto3699[8];
	char * hint_Auto3699[8];
	char * msg_Auto3700[8];
	char * hint_Auto3700[8];
	char * msg_Auto3701[8];
	char * hint_Auto3701[8];
	char * msg_Auto3702[8];
	char * hint_Auto3702[8];
	char * msg_Auto3703[8];
	char * hint_Auto3703[8];
	char * hint_bgi[8];
	char	buffer_bgi[256];
	char * msg_bgia[8];
	char * hint_bgia[8];
	int	value_bgia;
	char * msg_bgitr[8];
	char * hint_bgitr[8];
	int	value_bgitr;
	char * msg_bgct[8];
	char * hint_bgct[8];
	int	value_bgct;
	char * hint_bgcv[8];
	char	buffer_bgcv[11];
	char * msg_ContentPage[8];
	int	trigger_ContentPage;
	char * hint_ContentPage[8];
	char * msg_Auto3704[8];
	char * hint_Auto3704[8];
	char * msg_Auto3705[8];
	char * hint_Auto3705[8];
	char * msg_Auto3706[8];
	char * hint_Auto3706[8];
	char * msg_Auto3707[8];
	char * hint_Auto3707[8];
	char * msg_Auto3708[8];
	char * hint_Auto3708[8];
	char * msg_Auto3709[8];
	char * hint_Auto3709[8];
	char * msg_Auto3710[8];
	char * hint_Auto3710[8];
	char * msg_Auto3711[8];
	char * hint_Auto3711[8];
	char * msg_Auto3712[8];
	char * hint_Auto3712[8];
	char * msg_txtol[8];
	int	trigger_txtol;
	char * hint_txtol[8];
	int	value_txtol;
	char * msg_txtlt[8];
	int	trigger_txtlt;
	char * hint_txtlt[8];
	int	value_txtlt;
	char * msg_txtul[8];
	int	trigger_txtul;
	char * hint_txtul[8];
	int	value_txtul;
	char * msg_txtbo[8];
	int	trigger_txtbo;
	char * hint_txtbo[8];
	int	value_txtbo;
	char * msg_txtsh[8];
	int	trigger_txtsh;
	char * hint_txtsh[8];
	int	value_txtsh;
	char * msg_txtbl[8];
	int	trigger_txtbl;
	char * hint_txtbl[8];
	int	value_txtbl;
	char * msg_Auto3713[8];
	char * hint_Auto3713[8];
	char * msg_Auto3714[8];
	char * hint_Auto3714[8];
	char * msg_Auto3715[8];
	char * hint_Auto3715[8];
	char * msg_Auto3716[8];
	char * hint_Auto3716[8];
	char * hint_txfu[8];
	char	buffer_txfu[256];
	char * msg_txct[8];
	char * hint_txct[8];
	int	value_txct;
	char * hint_txcv[8];
	char	buffer_txcv[10];
	char * msg_txta[8];
	char * hint_txta[8];
	int	value_txta;
	char * hint_ltspv[8];
	char	buffer_ltspv[13];
	char * msg_ltspt[8];
	char * hint_ltspt[8];
	int	value_ltspt;
	char * hint_wspv[8];
	char	buffer_wspv[13];
	char * msg_wspt[8];
	char * hint_wspt[8];
	int	value_wspt;
	char * hint_lnspv[8];
	char	buffer_lnspv[13];
	char * msg_lnspt[8];
	char * hint_lnspt[8];
	int	value_lnspt;
	char * hint_Message[8];
	char	buffer_Message[256];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];
private int on_Trace_show(struct cstyleman_context * _Context);
private int on_ClassList_show(struct cstyleman_context * _Context);
private int on_FileList_show(struct cstyleman_context * _Context);
private int on_CFList_show(struct cstyleman_context * _Context);
private int on_CLBar_show(struct cstyleman_context * _Context);
private int on_MLBar_show(struct cstyleman_context * _Context);
private int on_FLBar_show(struct cstyleman_context * _Context);
private int on_StatusBar_show(struct cstyleman_context * _Context);
private int on_Thing_show(struct cstyleman_context * _Context);
private int on_Auto3629_event(struct cstyleman_context * _Context);
private int on_Trace_event(struct cstyleman_context * _Context);
private int on_ClassList_event(struct cstyleman_context * _Context);
private int on_Action_event(struct cstyleman_context * _Context);
private int on_FileList_event(struct cstyleman_context * _Context);
private int on_CFList_event(struct cstyleman_context * _Context);
private int on_CLBar_event(struct cstyleman_context * _Context);
private int on_MLBar_event(struct cstyleman_context * _Context);
private int on_FLBar_event(struct cstyleman_context * _Context);
private int on_ExportNameError_event(struct cstyleman_context * _Context);
private int on_LoadOperation_event(struct cstyleman_context * _Context);
private int on_Reset_event(struct cstyleman_context * _Context);
private int on_SaveOperation_event(struct cstyleman_context * _Context);
private int on_ViewFile_event(struct cstyleman_context * _Context);
private int on_ExportOperation_event(struct cstyleman_context * _Context);
private int on_ViewExport_event(struct cstyleman_context * _Context);
private int on_ImportOperation_event(struct cstyleman_context * _Context);
private int on_ViewImport_event(struct cstyleman_context * _Context);
private int on_Thing_event(struct cstyleman_context * _Context);
static void	CssValue(struct cstyleman_context * _Context,FILE * Target, char * k, char * vptr, int nature);
static void	CssColour(struct cstyleman_context * _Context,FILE * Target, char * k, char * v, int nature);
static void	CssUrl(struct cstyleman_context * _Context,FILE * Target, char * k, char * v);
static void	CssComment(struct cstyleman_context * _Context,FILE * Target, char * m);
static void	CssContent(struct cstyleman_context * _Context,FILE * Target);
static void	CssBorder(struct cstyleman_context * _Context,FILE * Target);
static void	CssPadding(struct cstyleman_context * _Context,FILE * Target);
static void	CssAlign(struct cstyleman_context * _Context,FILE * Target , char * k, int v);
static void	CssDecoration(struct cstyleman_context * _Context,FILE * Target, char * k);
static void	CssMargin(struct cstyleman_context * _Context,FILE * Target);
static void	ExportCss(struct cstyleman_context * _Context,char * nomfic);
static void	ResetClass(struct cstyleman_context * _Context);
static void	ExportClass(struct cstyleman_context * _Context,FILE * Target);
static void	LoadClass(struct cstyleman_context * _Context,struct element_style* eptr);
static void	GetCssColour(struct cstyleman_context * _Context,struct element_colour * cptr, char * cv, int * ct);
static void	GetCssValue(struct cstyleman_context * _Context,struct element_dimension * dptr, char * dv, int * dt);
static void	GetCssAlign(struct cstyleman_context * _Context,int v, int * av, int jtv);
void	GenerateStyleClass(struct cstyleman_context * _Context,FILE * h, struct element_style * eptr);
static void	onhint(struct cstyleman_context * _Context,char * m);
static void	ExportCollection(struct cstyleman_context * _Context,char * nomfic);
private int  sort_item_ClassList(struct cstyleman_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_ClassList(struct cstyleman_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_ClassList(struct cstyleman_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_ClassList */
private int compare_ClassList(struct cstyleman_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_ClassList */
private int  sort_item_FileList(struct cstyleman_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_FileList(struct cstyleman_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_FileList(struct cstyleman_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_FileList */
private int compare_FileList(struct cstyleman_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_FileList */
private int  sort_item_CFList(struct cstyleman_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_CFList(struct cstyleman_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_CFList(struct cstyleman_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_CFList */
private int compare_CFList(struct cstyleman_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_CFList */

/*	------------------	*/
/*	C s s V a l u e ()	*/
/*	------------------	*/
static void	CssValue(struct cstyleman_context * _Context,FILE * Target, char * k, char * vptr, int nature){
	char v[257];
	int i;
	if(*vptr!=' '){
	for(i=0;i<256;i++){
	if(*(vptr+i)==' ')
	break;
	else if(!(*(vptr+i)))
	break;
	else v[i]=*(vptr+i);
	}
	v[i]=0;
	switch(nature){
	case _styleman_value_px:fprintf(Target,"\t%s: %s%s;\n",k,v,"px");break;
	case _styleman_value_pt:fprintf(Target,"\t%s: %s%s;\n",k,v,"pt");break;
	case _styleman_value_pc:fprintf(Target,"\t%s: %s%s;\n",k,v,"pc");break;
	case _styleman_value_in:fprintf(Target,"\t%s: %s%s;\n",k,v,"in");break;
	case _styleman_value_mm:fprintf(Target,"\t%s: %s%s;\n",k,v,"mm");break;
	case _styleman_value_cm:fprintf(Target,"\t%s: %s%s;\n",k,v,"cm");break;
	case _styleman_value_em:fprintf(Target,"\t%s: %s%s;\n",k,v,"em");break;
	case _styleman_value_plus:fprintf(Target,"\t%s: %s%s;\n",k,v,"+");break;
	case _styleman_value_percent:fprintf(Target,"\t%s: %s%s;\n",k,v,"%");break;
	case _styleman_value_text:fprintf(Target,"\t%s: %s;\n",k,"text");break;
	case _styleman_value_auto:fprintf(Target,"\t%s: %s;\n",k,"auto");break;
	case _styleman_value_cell:fprintf(Target,"\t%s: %s;\n",k,"cell");break;
	case _styleman_value_normal:fprintf(Target,"\t%s: %s;\n",k,"normal");break;
	case _styleman_value_fixed:fprintf(Target,"\t%s: %s;\n",k,"fixed");break;
	default:fprintf(Target,"\t%s: %s;\n",k,v);break;
	}
	}
	else{
	switch(nature){
	case _styleman_value_text:fprintf(Target,"\t%s: %s;\n",k,"text");break;
	case _styleman_value_auto:fprintf(Target,"\t%s: %s;\n",k,"auto");break;
	case _styleman_value_cell:fprintf(Target,"\t%s: %s;\n",k,"cell");break;
	case _styleman_value_normal:fprintf(Target,"\t%s: %s;\n",k,"normal");break;
	case _styleman_value_fixed:fprintf(Target,"\t%s: %s;\n",k,"fixed");break;
	}
	}
	
}

/*	--------------------	*/
/*	C s s C o l o u r ()	*/
/*	--------------------	*/
static void	CssColour(struct cstyleman_context * _Context,FILE * Target, char * k, char * v, int nature){
	if(nature){
	switch(nature){
	case _styleman_rgb:fprintf(Target,"\t%s: rgb(%s);\n",k,v);break;
	case _styleman_ihm:fprintf(Target,"\t%s: ihm(%s);\n",k,v);break;
	case _styleman_colour:fprintf(Target,"\t%s: colour(%s);\n",k,v);break;
	case _styleman_black:fprintf(Target,"\t%s: %s;\n",k,"black");break;
	case _styleman_navy:fprintf(Target,"\t%s: %s;\n",k,"navy");break;
	case _styleman_green:fprintf(Target,"\t%s: %s;\n",k,"green");break;
	case _styleman_cyan:fprintf(Target,"\t%s: %s;\n",k,"cyan");break;
	case _styleman_red:fprintf(Target,"\t%s: %s;\n",k,"red");break;
	case _styleman_magenta:fprintf(Target,"\t%s: %s;\n",k,"magenta");break;
	case _styleman_brown:fprintf(Target,"\t%s: %s;\n",k,"brown");break;
	case _styleman_grey:fprintf(Target,"\t%s: %s;\n",k,"grey");break;
	case _styleman_silver:fprintf(Target,"\t%s: %s;\n",k,"silver");break;
	case _styleman_blue:fprintf(Target,"\t%s: %s;\n",k,"blue");break;
	case _styleman_lime:fprintf(Target,"\t%s: %s;\n",k,"lime");break;
	case _styleman_sky:fprintf(Target,"\t%s: %s;\n",k,"sky");break;
	case _styleman_pink:fprintf(Target,"\t%s: %s;\n",k,"pink");break;
	case _styleman_purple:fprintf(Target,"\t%s: %s;\n",k,"purple");break;
	case _styleman_yellow:fprintf(Target,"\t%s: %s;\n",k,"yellow");break;
	case _styleman_white:fprintf(Target,"\t%s: %s;\n",k,"white");break;
	case _styleman_transparent:fprintf(Target,"\t%s: %s;\n",k,"transparent");break;
	}
	}
	
}

/*	--------------	*/
/*	C s s U r l ()	*/
/*	--------------	*/
static void	CssUrl(struct cstyleman_context * _Context,FILE * Target, char * k, char * v){
	char message[257];
	int i;
	if(*v!=' '){
	for(i=0;i<256;i++){
	if(*(v+i)==' ')
	break;
	else if(!(*(v+i)))
	break;
	else message[i]=*(v+i);
	}
	message[i]=0;
	fprintf(Target,"\t%s: url(%s);\n",k,message);
	}
	
}

/*	----------------------	*/
/*	C s s C o m m e n t ()	*/
/*	----------------------	*/
static void	CssComment(struct cstyleman_context * _Context,FILE * Target, char * m){
	int l;
	int n;
	if(*m!=' '){
	for(l=0,n=0;*(m+n)!=0;n++){
	if(*(m+n)!=' ')
	l=(n+1);
	}
	fprintf(Target,"/* ");
	for(n=0;n<l;n++){fprintf(Target,"-");}
	fprintf(Target," */\n/* ");
	for(n=0;n<l;n++){fprintf(Target,"%c",*(m+n));}
	fprintf(Target," */\n/* ");
	for(n=0;n<l;n++){fprintf(Target,"-");}
	fprintf(Target," */\n");
	}

}

/*	----------------------	*/
/*	C s s C o n t e n t ()	*/
/*	----------------------	*/
static void	CssContent(struct cstyleman_context * _Context,FILE * Target){
	switch(_Context->value_ct){
	case _styleman_content_none:fprintf(Target,"\t%s\n","content: none;");break;
	case _styleman_content_text:fprintf(Target,"\t%s\n","content: text;");break;
	case _styleman_content_url:fprintf(Target,"\t%s\n","content: url; ");break;
	case _styleman_content_auto:fprintf(Target,"\t%s\n","content: auto;");break;
	case _styleman_content_trigger:fprintf(Target,"\t%s\n","content: trigger;");break;
	case _styleman_content_grip:fprintf(Target,"\t%s\n","content: grip;");break;
	case _styleman_content_up:fprintf(Target,"\t%s\n","content: up;");break;
	case _styleman_content_down:fprintf(Target,"\t%s\n","content: down;");break;
	case _styleman_content_left:fprintf(Target,"\t%s\n","content: left;");break;
	case _styleman_content_right:fprintf(Target,"\t%s\n","content: right;");break;
	}
	switch(_Context->value_posv){
	case _styleman_position_cell:fprintf(Target,"\t%s\n","position: cell;");break;
	case _styleman_position_auto:fprintf(Target,"\t%s\n","position: auto;");break;
	case _styleman_position_home:fprintf(Target,"\t%s\n","position: home;");break;
	case _styleman_position_absolute:fprintf(Target,"\t%s\n","position: absolute;");break;
	case _styleman_position_relative:fprintf(Target,"\t%s\n","position: relative;");break;
	case _styleman_position_fixed:fprintf(Target,"\t%s\n","position: fixed;");break;
	case _styleman_position_static:fprintf(Target,"\t%s\n","position: static;");break;
	}
	CssValue(_Context, Target,"width",_Context->buffer_cwv,_Context->value_cwt);
	CssValue(_Context, Target,"height",_Context->buffer_chv,_Context->value_cht);
	CssValue(_Context, Target,"top",_Context->buffer_cptv,_Context->value_cptt);
	CssValue(_Context, Target,"right",_Context->buffer_cprv,_Context->value_cprt);
	CssValue(_Context, Target,"bottom",_Context->buffer_cpbv,_Context->value_cpbt);
	CssValue(_Context, Target,"left",_Context->buffer_cplv,_Context->value_cplt);
	CssUrl(_Context, Target,"background-image",_Context->buffer_bgi);
	CssColour(_Context, Target,"background-colour",_Context->buffer_bgcv,_Context->value_bgct);
	CssAlign(_Context, Target,"background-align",_Context->value_bgia);
	switch(_Context->value_bgitr){
	case _styleman_imagemode_transparent:fprintf(Target,"\t%s\n","background-align: transparent;");break;
	}
	CssUrl(_Context, Target,"text-font",_Context->buffer_txfu);
	CssColour(_Context, Target,"text-colour",_Context->buffer_txcv,_Context->value_txct);
	CssAlign(_Context, Target,"text-align",_Context->value_txta);
	CssDecoration(_Context, Target,"text-decoration");
	CssValue(_Context, Target,"letter-spacing",_Context->buffer_ltspv,_Context->value_ltspt);
	CssValue(_Context, Target,"word-spacing",_Context->buffer_wspv,_Context->value_wspt);
	CssValue(_Context, Target,"line-spacing",_Context->buffer_lnspv,_Context->value_lnspt);
	
}

/*	--------------------	*/
/*	C s s B o r d e r ()	*/
/*	--------------------	*/
static void	CssBorder(struct cstyleman_context * _Context,FILE * Target){
	if(_Context->value_bdsv!=_styleman_frame_url){
	CssColour(_Context, Target,"border-colour",_Context->buffer_bdcv,_Context->value_bdct);
	CssValue(_Context, Target,"border-width",_Context->buffer_bwv,_Context->value_bwt);
	}
	switch(_Context->value_bdsv){
	case _styleman_frame_none:fprintf(Target,"\t%s\n","border-style: none; ");break;
	case _styleman_frame_url:
	CssUrl(_Context, Target,"corner-top-left-style",_Context->buffer_ctlu);
	CssUrl(_Context, Target,"corner-top-right-style",_Context->buffer_ctru);
	CssUrl(_Context, Target,"corner-bottom-left-style",_Context->buffer_cblu);
	CssUrl(_Context, Target,"corner-bottom-right-style",_Context->buffer_cbru);
	CssValue(_Context, Target,"border-top-width",_Context->buffer_btv,_Context->value_btt);
	CssUrl(_Context, Target,"border-top-style",_Context->buffer_btu);
	CssValue(_Context, Target,"border-right-width",_Context->buffer_brv,_Context->value_brt);
	CssUrl(_Context, Target,"border-right-style",_Context->buffer_bru);
	CssValue(_Context, Target,"border-bottom-width",_Context->buffer_bbv,_Context->value_bbt);
	CssUrl(_Context, Target,"border-bottom-style",_Context->buffer_bbu);
	CssValue(_Context, Target,"border-left-width",_Context->buffer_blv,_Context->value_blt);
	CssUrl(_Context, Target,"border-left-style",_Context->buffer_blu);
	break;
	case _styleman_frame_solid:fprintf(Target,"\t%s\n","border-style: solid; ");break;
	case _styleman_frame_double:fprintf(Target,"\t%s\n","border-style: double;");break;
	case _styleman_frame_edit:fprintf(Target,"\t%s\n","border-style: edit;  ");break;
	case _styleman_frame_outset:fprintf(Target,"\t%s\n","border-style: outset;");break;
	case _styleman_frame_inset:fprintf(Target,"\t%s\n","border-style: inset; ");break;
	case _styleman_frame_groove:fprintf(Target,"\t%s\n","border-style: groove;");break;
	case _styleman_frame_ridge:fprintf(Target,"\t%s\n","border-style: ridge; ");break;
	case _styleman_frame_disk:fprintf(Target,"\t%s\n","border-style: disk;  ");break;
	case _styleman_frame_shade:fprintf(Target,"\t%s\n","border-style: shade; ");break;
	case _styleman_frame_hole:fprintf(Target,"\t%s\n","border-style: hole;  ");break;
	case _styleman_frame_rounded:fprintf(Target,"\t%s\n","border-style: rounded;");break;
	case _styleman_frame_convex:fprintf(Target,"\t%s\n","border-style: convex;");break;
	case _styleman_frame_concave:fprintf(Target,"\t%s\n","border-style: concave;");break;
	case _styleman_frame_dashed:fprintf(Target,"\t%s\n","border-style: dashed; ");break;
	case _styleman_frame_dotted:fprintf(Target,"\t%s\n","border-style: dotted; ");break;
	case _styleman_frame_fill:
	fprintf(Target,"\t%s\n","border-style: fill; ");
	CssValue(_Context, Target,"border-bottom-width",_Context->buffer_bbv,_Context->value_bbt);
	CssUrl(_Context, Target,"border-bottom-style",_Context->buffer_bbu);
	CssValue(_Context, Target,"border-left-width",_Context->buffer_blv,_Context->value_blt);
	CssUrl(_Context, Target,"border-left-style",_Context->buffer_blu);
	break;
	}

}

/*	----------------------	*/
/*	C s s P a d d i n g ()	*/
/*	----------------------	*/
static void	CssPadding(struct cstyleman_context * _Context,FILE * Target){
	if(*(_Context->buffer_pgv)!=' '){
	CssValue(_Context, Target,"padding",_Context->buffer_pgv,_Context->value_pgt);
	}
	else{
	CssValue(_Context, Target,"padding-top",_Context->buffer_ptv,_Context->value_ptt);
	CssValue(_Context, Target,"padding-right",_Context->buffer_prv,_Context->value_prt);
	CssValue(_Context, Target,"padding-bottom",_Context->buffer_pbv,_Context->value_pbt);
	CssValue(_Context, Target,"padding-left",_Context->buffer_plv,_Context->value_plt);
	}

}

/*	------------------	*/
/*	C s s A l i g n ()	*/
/*	------------------	*/
static void	CssAlign(struct cstyleman_context * _Context,FILE * Target , char * k, int v){
	switch(v){
	case _styleman_align_none:fprintf(Target,"\t%s: %s;\n",k,"none");break;
	case _styleman_align_left:fprintf(Target,"\t%s: %s;\n",k,"left");break;
	case _styleman_align_right:fprintf(Target,"\t%s: %s;\n",k,"right");break;
	case _styleman_align_center:fprintf(Target,"\t%s: %s;\n",k,"center");break;
	case _styleman_align_justify:fprintf(Target,"\t%s: %s;\n",k,"justify");break;
	case _styleman_align_tile:fprintf(Target,"\t%s: %s;\n",k,"tile");break;
	case _styleman_align_makefit:fprintf(Target,"\t%s: %s;\n",k,"makefit");break;
	case _styleman_align_bestfit:fprintf(Target,"\t%s: %s;\n",k,"bestfit");break;
	}
	
}

/*	----------------------------	*/
/*	C s s D e c o r a t i o n ()	*/
/*	----------------------------	*/
static void	CssDecoration(struct cstyleman_context * _Context,FILE * Target, char * k){
	if(_Context->value_txtbo){fprintf(Target,"\t%s: %s;\n",k,"bold;");}
	if(_Context->value_txtul){fprintf(Target,"\t%s: %s;\n",k,"underline;");}
	if(_Context->value_txtlt){fprintf(Target,"\t%s: %s;\n",k,"line-through;");}
	if(_Context->value_txtol){fprintf(Target,"\t%s: %s;\n",k,"overline;");}
	if(_Context->value_txtbl){fprintf(Target,"\t%s: %s;\n",k,"blink;");}
	if(_Context->value_txtsh){fprintf(Target,"\t%s: %s;\n",k,"shadow;");}
	
}

/*	--------------------	*/
/*	C s s M a r g i n ()	*/
/*	--------------------	*/
static void	CssMargin(struct cstyleman_context * _Context,FILE * Target){
	if(*(_Context->buffer_mgv)!=' '){
	CssValue(_Context, Target,"margin",_Context->buffer_mgv,_Context->value_mgt);
	}
	else{
	CssValue(_Context, Target,"margin-top",_Context->buffer_mtv,_Context->value_mtt);
	CssValue(_Context, Target,"margin-right",_Context->buffer_mrv,_Context->value_mrt);
	CssValue(_Context, Target,"margin-bottom",_Context->buffer_mbv,_Context->value_mbt);
	CssValue(_Context, Target,"margin-left",_Context->buffer_mlv,_Context->value_mlt);
	}

}

/*	--------------------	*/
/*	E x p o r t C s s ()	*/
/*	--------------------	*/
static void	ExportCss(struct cstyleman_context * _Context,char * nomfic){
	FILE*Target;
	if((Target=fopen(nomfic,"w"))!=(FILE*)0){
	CssComment(_Context, Target,_Context->buffer_Description);
	ExportClass(_Context, Target);
	CssComment(_Context, Target,"end of file");
	fclose(Target);
	}

}

/*	----------------------	*/
/*	R e s e t C l a s s ()	*/
/*	----------------------	*/
static void	ResetClass(struct cstyleman_context * _Context){
	/*Base Class and Filename*/
	/*-----------------------*/
	memset(_Context->buffer_BaseClass,' ',255);
	memset(_Context->buffer_ExportName,' ',255);
	/*cell*/
	/*----*/
	memset(_Context->buffer_cwv,' ',9);_Context->value_cwt=0;
	memset(_Context->buffer_chv,' ',9);_Context->value_cht=0;
	_Context->value_posv=0;_Context->value_ct=0;
	memset(_Context->buffer_cplv,' ',9);_Context->value_cplt=0;
	memset(_Context->buffer_cptv,' ',9);_Context->value_cptt=0;
	memset(_Context->buffer_cprv,' ',9);_Context->value_cprt=0;
	memset(_Context->buffer_cpbv,' ',9);_Context->value_cpbt=0;
	/*margin*/
	/*------*/
	memset(_Context->buffer_mlv,' ',9);_Context->value_mlt=0;
	memset(_Context->buffer_mrv,' ',9);_Context->value_mrt=0;
	memset(_Context->buffer_mtv,' ',9);_Context->value_mtt=0;
	memset(_Context->buffer_mbv,' ',9);_Context->value_mbt=0;
	memset(_Context->buffer_mgv,' ',9);_Context->value_mgt=0;
	/*border*/
	/*------*/
	memset(_Context->buffer_bdcv,' ',9);_Context->value_bdct=0;_Context->value_bdat=0;
	memset(_Context->buffer_bwv,' ',9);_Context->value_bwt=0;
	memset(_Context->buffer_blv,' ',9);_Context->value_blt=0;
	memset(_Context->buffer_btv,' ',9);_Context->value_btt=0;
	memset(_Context->buffer_brv,' ',9);_Context->value_brt=0;
	memset(_Context->buffer_bbv,' ',9);_Context->value_bbt=0;
	memset(_Context->buffer_blu,' ',255);
	memset(_Context->buffer_btu,' ',255);
	memset(_Context->buffer_bru,' ',255);
	memset(_Context->buffer_bbu,' ',255);
	memset(_Context->buffer_ctlu,' ',255);
	memset(_Context->buffer_ctru,' ',255);
	memset(_Context->buffer_cblu,' ',255);
	memset(_Context->buffer_cbru,' ',255);
	/*padding*/
	/*-------*/
	memset(_Context->buffer_plv,' ',9);_Context->value_plt=0;
	memset(_Context->buffer_prv,' ',9);_Context->value_prt=0;
	memset(_Context->buffer_ptv,' ',9);_Context->value_ptt=0;
	memset(_Context->buffer_pbv,' ',9);_Context->value_pbt=0;
	memset(_Context->buffer_pgv,' ',9);_Context->value_pgt=0;
	/*background*/
	/*----------*/
	memset(_Context->buffer_bgi,' ',255);
	_Context->value_bgia=0;_Context->value_bgitr=0;
	memset(_Context->buffer_bgcv,' ',10);_Context->value_bgct=0;
		/*content*/
	/*-------*/
	memset(_Context->buffer_txfu,' ',255);
	_Context->value_txta=0;
	_Context->value_txtbo=_Context->value_txtsh=_Context->value_txtbl=
	_Context->value_txtol=_Context->value_txtul=_Context->value_txtlt=0;
	memset(_Context->buffer_txcv,' ',9);_Context->value_txct=0;
	memset(_Context->buffer_ltspv,' ',12);
	memset(_Context->buffer_lnspv,' ',12);
	memset(_Context->buffer_wspv,' ',12);
	_Context->value_ltspt=0;_Context->value_lnspt=0;_Context->value_wspt=0;

}

/*	------------------------	*/
/*	E x p o r t C l a s s ()	*/
/*	------------------------	*/
static void	ExportClass(struct cstyleman_context * _Context,FILE * Target){
	char message[257];
	char buffer[256];
	int i;
	for(i=0;i<256;i++){
	if(*(_Context->buffer_ClassName+i)==' ')
	break;
	else message[i]=*(_Context->buffer_ClassName+i);
	}
	message[i]=0;
	sprintf(buffer,"C L A S S : %s",message);
	CssComment(_Context, Target,buffer);
	fprintf(Target,"%s\t{\n",message);
	if(*(_Context->buffer_BaseClass)!=' '){
	for(i=0;i<256;i++){
	if(*(_Context->buffer_BaseClass+i)==' ')
	break;
	else message[i]=*(_Context->buffer_BaseClass+i);
	}
	message[i]=0;
	fprintf(Target,"\tclass: %s;\n",message);
	}
	CssContent(_Context, Target);
	CssMargin(_Context, Target);
	CssBorder(_Context, Target);
	CssPadding(_Context, Target);
	fprintf(Target,"\t}\n");

}

/*	--------------------	*/
/*	L o a d C l a s s ()	*/
/*	--------------------	*/
static void	LoadClass(struct cstyleman_context * _Context,struct element_style* eptr){
	if(!(eptr))return;
	else ResetClass(_Context);
		if(eptr->basename){strcpy(_Context->buffer_BaseClass,eptr->basename);}
	if(eptr->filename){strcpy(_Context->buffer_ExportName,eptr->filename);}
	/*Content Text or Image*/
	/*---------------------*/
	if(eptr->fontname){strcpy(_Context->buffer_txfu,eptr->fontname);}
	if(eptr->textcolour.type!=-1){
	GetCssColour(_Context,&eptr->textcolour,_Context->buffer_txcv,&_Context->value_txct);
	}
	GetCssAlign(_Context, eptr->textalign,&_Context->value_txta,_styleman_align_justify);
	GetCssValue(_Context,&eptr->letterspacing,_Context->buffer_ltspv,&_Context->value_ltspt);
	GetCssValue(_Context,&eptr->linespacing,_Context->buffer_lnspv,&_Context->value_lnspt);
	GetCssValue(_Context,&eptr->wordspacing,_Context->buffer_wspv,&_Context->value_wspt);
	if(eptr->textatribut&_TEXT_BOLD){_Context->value_txtbo=1;}
	if(eptr->textatribut&_TEXT_SHADOW){_Context->value_txtsh=1;}
	if(eptr->textatribut&_TEXT_BLINK){_Context->value_txtbl=1;}
	if(eptr->textatribut&_TEXT_OVERLINE){_Context->value_txtol=1;}
	if(eptr->textatribut&_TEXT_UNDERLINE){_Context->value_txtul=1;}
	if(eptr->textatribut&_TEXT_STRIKE){_Context->value_txtlt=1;}
	/*Content Background*/
	/*------------------*/
	if(eptr->backgroundimage){strcpy(_Context->buffer_bgi,eptr->backgroundimage);}
	if(eptr->backgroundcolour.type!=-1){
	GetCssColour(_Context,&eptr->backgroundcolour,_Context->buffer_bgcv,&_Context->value_bgct);
	}
	GetCssAlign(_Context, eptr->backgroundalign,&_Context->value_bgia,_styleman_align_tile);
	if(eptr->backgroundalign&_ALIGN_SPRITE){
	_Context->value_bgitr=_styleman_imagemode_transparent;
	}
	/*Padding*/
	/*-------*/
	if((eptr->paddingsize.top.type==eptr->paddingsize.bottom.type)
	&&(eptr->paddingsize.top.type==eptr->paddingsize.left.type)
	&&(eptr->paddingsize.top.type==eptr->paddingsize.right.type)
	&&(eptr->paddingsize.top.value==eptr->paddingsize.bottom.value)
	&&(eptr->paddingsize.top.value==eptr->paddingsize.left.value)
	&&(eptr->paddingsize.top.value==eptr->paddingsize.right.value)){
	GetCssValue(_Context,&eptr->paddingsize.top,_Context->buffer_pgv,&_Context->value_pgt);
	}
	else{
	GetCssValue(_Context,&eptr->paddingsize.top,_Context->buffer_ptv,&_Context->value_ptt);
	GetCssValue(_Context,&eptr->paddingsize.bottom,_Context->buffer_pbv,&_Context->value_pbt);
	GetCssValue(_Context,&eptr->paddingsize.left,_Context->buffer_plv,&_Context->value_plt);
	GetCssValue(_Context,&eptr->paddingsize.right,_Context->buffer_prv,&_Context->value_prt);
	}
	/*Border*/
	/*------*/
	if((eptr->bordersize.top.type==eptr->bordersize.bottom.type)
	&&(eptr->bordersize.top.type==eptr->bordersize.left.type)
	&&(eptr->bordersize.top.type==eptr->bordersize.right.type)
	&&(eptr->bordersize.top.value==eptr->bordersize.bottom.value)
	&&(eptr->bordersize.top.value==eptr->bordersize.left.value)
	&&(eptr->bordersize.top.value==eptr->bordersize.right.value)){
	GetCssValue(_Context,&eptr->bordersize.top,_Context->buffer_bwv,&_Context->value_bwt);
	}
	else{
	GetCssValue(_Context,&eptr->bordersize.top,_Context->buffer_btv,&_Context->value_btt);
	GetCssValue(_Context,&eptr->bordersize.bottom,_Context->buffer_bbv,&_Context->value_bbt);
	GetCssValue(_Context,&eptr->bordersize.left,_Context->buffer_blv,&_Context->value_blt);
	GetCssValue(_Context,&eptr->bordersize.right,_Context->buffer_brv,&_Context->value_brt);
	}
	switch(eptr->bordertype.top){
	case _keyword_none:
	_Context->value_bdsv=_styleman_frame_none;
	break;
	case _keyword_url:
	_Context->value_bdsv=_styleman_frame_url;
	break;
	case _keyword_solid:
	_Context->value_bdsv=_styleman_frame_solid;
	break;
	case _keyword_double:
	_Context->value_bdsv=_styleman_frame_double;
	break;
	case _keyword_edit:
	_Context->value_bdsv=_styleman_frame_edit;
	break;
	case _keyword_outset:
	_Context->value_bdsv=_styleman_frame_outset;
	break;
	case _keyword_inset:
	_Context->value_bdsv=_styleman_frame_inset;
	break;
	case _keyword_ridge:
	_Context->value_bdsv=_styleman_frame_ridge;
	break;
	case _keyword_groove:
	_Context->value_bdsv=_styleman_frame_groove;
	break;
	case _keyword_disk:
	_Context->value_bdsv=_styleman_frame_disk;
	break;
	case _keyword_shade:
	_Context->value_bdsv=_styleman_frame_shade;
	break;
	case _keyword_hole:
	_Context->value_bdsv=_styleman_frame_hole;
	break;
	case _keyword_rounded:
	_Context->value_bdsv=_styleman_frame_rounded;
	break;
	case _keyword_convex:
	_Context->value_bdsv=_styleman_frame_convex;
	break;
	case _keyword_concave:
	_Context->value_bdsv=_styleman_frame_concave;
	break;
	case _keyword_dashed:
	_Context->value_bdsv=_styleman_frame_dashed;
	break;
	case _keyword_dotted:
	_Context->value_bdsv=_styleman_frame_dotted;
	break;
	case _keyword_fill:
	_Context->value_bdsv=_styleman_frame_fill;
	break;
	}
	if(eptr->bordertype.topleftimage){strcpy(_Context->buffer_ctlu,eptr->bordertype.topleftimage);}
	if(eptr->bordertype.topimage){strcpy(_Context->buffer_btu,eptr->bordertype.topimage);}
	if(eptr->bordertype.toprightimage){strcpy(_Context->buffer_ctru,eptr->bordertype.toprightimage);}
	if(eptr->bordertype.rightimage){strcpy(_Context->buffer_bru,eptr->bordertype.rightimage);}
	if(eptr->bordertype.bottomrightimage){strcpy(_Context->buffer_cbru,eptr->bordertype.bottomrightimage);}
	if(eptr->bordertype.bottomimage){strcpy(_Context->buffer_bbu,eptr->bordertype.bottomimage);}
	if(eptr->bordertype.bottomleftimage){strcpy(_Context->buffer_cblu,eptr->bordertype.bottomleftimage);}
	if(eptr->bordertype.leftimage){strcpy(_Context->buffer_blu,eptr->bordertype.leftimage);}
	if(eptr->bordercolour.type!=-1){
	GetCssColour(_Context,&eptr->bordercolour,_Context->buffer_bdcv,&_Context->value_bdct);
	}
	GetCssAlign(_Context, eptr->borderalign,&_Context->value_bdat,_styleman_align_tile);
	/*Margin*/
	/*------*/
	if((eptr->marginsize.top.type==eptr->marginsize.bottom.type)
	&&(eptr->marginsize.top.type==eptr->marginsize.left.type)
	&&(eptr->marginsize.top.type==eptr->marginsize.right.type)
	&&(eptr->marginsize.top.value==eptr->marginsize.bottom.value)
	&&(eptr->marginsize.top.value==eptr->marginsize.left.value)
	&&(eptr->marginsize.top.value==eptr->marginsize.right.value)){
	GetCssValue(_Context,&eptr->marginsize.top,_Context->buffer_mgv,&_Context->value_mgt);
	}
	else{
	GetCssValue(_Context,&eptr->marginsize.top,_Context->buffer_mtv,&_Context->value_mtt);
	GetCssValue(_Context,&eptr->marginsize.bottom,_Context->buffer_mbv,&_Context->value_mbt);
	GetCssValue(_Context,&eptr->marginsize.left,_Context->buffer_mlv,&_Context->value_mlt);
	GetCssValue(_Context,&eptr->marginsize.right,_Context->buffer_mrv,&_Context->value_mrt);
	}
	/*Style Cell*/
	/*----------*/
	GetCssValue(_Context,&eptr->cellwidth,_Context->buffer_cwv,&_Context->value_cwt);
	GetCssValue(_Context,&eptr->cellheight,_Context->buffer_chv,&_Context->value_cht);
	GetCssValue(_Context,&eptr->cellposition.left,_Context->buffer_cplv,&_Context->value_cplt);
	GetCssValue(_Context,&eptr->cellposition.top,_Context->buffer_cptv,&_Context->value_cptt);
	GetCssValue(_Context,&eptr->cellposition.right,_Context->buffer_cprv,&_Context->value_cprt);
	GetCssValue(_Context,&eptr->cellposition.bottom,_Context->buffer_cpbv,&_Context->value_cpbt);
	switch(eptr->cellposition.type){
	case _keyword_home:
	_Context->value_posv=_styleman_position_home;
	break;
	case _keyword_auto:
	_Context->value_posv=_styleman_position_auto;
	break;
	case _keyword_static:
	_Context->value_posv=_styleman_position_static;
	break;
	case _keyword_relative:
	_Context->value_posv=_styleman_position_relative;
	break;
	case _keyword_absolute:
	_Context->value_posv=_styleman_position_absolute;
	break;
	case _keyword_fixed:
	_Context->value_posv=_styleman_position_fixed;
	break;
	}
	switch(eptr->nature){
	case _keyword_grip:
	_Context->value_ct=_styleman_content_grip;
	break;
	case _keyword_up:
	_Context->value_ct=_styleman_content_up;
	break;
	case _keyword_down:
	_Context->value_ct=_styleman_content_down;
	break;
	case _keyword_left:
	_Context->value_ct=_styleman_content_left;
	break;
	case _keyword_right:
	_Context->value_ct=_styleman_content_right;
	break;
	case _keyword_url:
	_Context->value_ct=_styleman_content_url;
	break;
	case _keyword_text:
	_Context->value_ct=_styleman_content_text;
	break;
	case _keyword_trigger:
	_Context->value_ct=_styleman_content_trigger;
	break;
	case _keyword_auto:
	_Context->value_ct=_styleman_content_auto;
	break;
	case _keyword_none:
	_Context->value_ct=_styleman_content_none;
	break;
	}

}

/*	--------------------------	*/
/*	G e t C s s C o l o u r ()	*/
/*	--------------------------	*/
static void	GetCssColour(struct cstyleman_context * _Context,struct element_colour * cptr, char * cv, int * ct){
	switch(cptr->type){
	case _keyword_transparent:*ct=_styleman_transparent;break;
	case _keyword_black:*ct=_styleman_black;break;
	case _keyword_navy:*ct=_styleman_navy;break;
	case _keyword_green:*ct=_styleman_green;break;
	case _keyword_cyan:*ct=_styleman_cyan;break;
	case _keyword_red:*ct=_styleman_red;break;
	case _keyword_magenta:*ct=_styleman_magenta;break;
	case _keyword_brown:*ct=_styleman_brown;break;
	case _keyword_grey:*ct=_styleman_grey;break;
	case _keyword_silver:*ct=_styleman_silver;break;
	case _keyword_blue:*ct=_styleman_blue;break;
	case _keyword_lime:*ct=_styleman_lime;break;
	case _keyword_sky:*ct=_styleman_sky;break;
	case _keyword_pink:*ct=_styleman_pink;break;
	case _keyword_purple:*ct=_styleman_purple;break;
	case _keyword_yellow:*ct=_styleman_yellow;break;
	case _keyword_white:*ct=_styleman_white;break;
	case _keyword_ihm:
	*ct=_styleman_ihm;
	sprintf(cv,"%u",(cptr->entry-16));
	break;
	case _keyword_rgb:
	*ct=_styleman_rgb;
	sprintf(cv,"%02.2X%02.2X%02.2X",cptr->red,cptr->green,cptr->blue);
	break;
	case _keyword_colour:
	*ct=_styleman_colour;
	sprintf(cv,"%u",cptr->entry);
	break;
	default:
	*ct=_styleman_none;
	break;
	}
	
}

/*	------------------------	*/
/*	G e t C s s V a l u e ()	*/
/*	------------------------	*/
static void	GetCssValue(struct cstyleman_context * _Context,struct element_dimension * dptr, char * dv, int * dt){
	if(!(dptr))return;
	if(!(dptr->state))return;
	switch(dptr->type){
	case _IN_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_in;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _MM_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_mm;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _CM_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_cm;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _PT_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_pt;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _PC_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_pc;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _ELEMENT_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_em;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _PIXEL_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_px;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _PERCENT_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_percent;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _PLUS_DIMENSION:
	if(dptr->value){
	*dt=_styleman_value_plus;
	sprintf(dv,"%u",dptr->value);
	}
	break;
	case _AUTO_DIMENSION:
	*dt=_styleman_value_auto;
	break;
	case _TEXT_DIMENSION:
	*dt=_styleman_value_text;
	break;
	case _CELL_DIMENSION:
	*dt=_styleman_value_cell;
	break;
	case _FIXED_DIMENSION:
	*dt=_styleman_value_fixed;
	break;
	}
	
}

/*	------------------------	*/
/*	G e t C s s A l i g n ()	*/
/*	------------------------	*/
static void	GetCssAlign(struct cstyleman_context * _Context,int v, int * av, int jtv){
	switch(v&7){
	case _ALIGN_NONE:*av=_styleman_align_none;break;
	case _ALIGN_RIGHT:*av=_styleman_align_right;break;
	case _ALIGN_LEFT:*av=_styleman_align_left;break;
	case _ALIGN_CENTER:*av=_styleman_align_center;break;
	case _ALIGN_JUSTIFY:*av=jtv;break;
	case _ALIGN_STRETCH:*av=_styleman_align_makefit;break;
	case _ALIGN_ADJUST:*av=_styleman_align_bestfit;break;
	}

}

/*	--------------------------------------	*/
/*	G e n e r a t e S t y l e C l a s s ()	*/
/*	--------------------------------------	*/
void	GenerateStyleClass(struct cstyleman_context * _Context,FILE * h, struct element_style * eptr){
	int transient=0;
	int failure=0;
	/*Build the visual object if required*/
	/*-----------------------------------*/
	if(!(_Context)){
	if(!(failure=cstyleman_create(&_Context)))
	transient=1;
	else return;
	}
	/*Load the class information into the object*/
	/*------------------------------------------*/
	if((eptr!=(struct element_style*)0)
	&&(eptr->name!=(char*)0)){
	memset(_Context->buffer_ClassName,' ',255);
	strcpy(_Context->buffer_ClassName,eptr->name);
	LoadClass(_Context, eptr);
	}
	/*Generate the style class to the file*/
	/*------------------------------------*/
	if(h!=(FILE*)0){
	ExportClass(_Context, h);
	}
	/*Release the visual object if transient*/
	/*--------------------------------------*/
	if(transient){
	failure=cstyleman_remove(_Context);
	}

}

/*	--------------	*/
/*	o n h i n t ()	*/
/*	--------------	*/
static void	onhint(struct cstyleman_context * _Context,char * m){
	int i;
	memset(_Context->buffer_StatusBar,' ',255);
	if(m){
	for(i=0;i<255;i++){
	if(!(*(m+i)))
	break;
	else _Context->buffer_StatusBar[i]=*(m+i);
	}
	}
	on_StatusBar_show(_Context);

}

/*	----------------------------------	*/
/*	E x p o r t C o l l e c t i o n ()	*/
/*	----------------------------------	*/
static void	ExportCollection(struct cstyleman_context * _Context,char * nomfic){
	struct element_file*fptr;
	struct element_class*cptr;
	FILE*Target;
	if((Target=fopen(nomfic,"w"))!=(FILE*)0){
	CssComment(_Context, Target,_Context->buffer_Description);
	if((fptr=resolve_stylefile_name(nomfic))!=(struct element_file*)0){
	for(cptr=fptr->first;
	cptr!=(struct element_class*)0;
	cptr=cptr->next){
	if(!(cptr->style))
	continue;
	else if(!(cptr->style->name))
	continue;
	else{
	memset(_Context->buffer_ClassName,' ',255);
	strcpy(_Context->buffer_ClassName,cptr->style->name);
	LoadClass(_Context, cptr->style);
	ExportClass(_Context, Target);
	}
	}
	}
	CssComment(_Context, Target,"end of file");
	fclose(Target);
	}

}
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_ClassList(struct cstyleman_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_ClassList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_ClassList(struct cstyleman_context * _Context,int nelts)
{
if (_Context->nelt_ClassList<nelts) {
	liberate(_Context->tabsort_ClassList);
	if ((_Context->tabsort_ClassList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_ClassList=0;_Context->nelt_ClassList<nelts;_Context->nelt_ClassList++)
		{ _Context->tabsort_ClassList[_Context->nelt_ClassList]=_Context->nelt_ClassList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_ClassList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_ClassList=allocate(nelts*93)) != NULL)
	memset(_Context->libsort_ClassList,' ',nelts*93);
}

/* ------------------------------------------------------------ */
/* sort the intermediate table into _Context->tabsort_ClassList */
/* ------------------------------------------------------------ */
private void sort_ClassList(struct cstyleman_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_ClassList,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_ClassList[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_ClassList[j]) && (compare_ClassList(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_ClassList[i]=k+1;
	_Context->indsort_ClassList[k]=1;
	};	/* for i */
liberate(_Context->libsort_ClassList);
liberate(_Context->indsort_ClassList);
}

/* ---------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_ClassList */
/* ---------------------------------------------------------- */
private int compare_ClassList(struct cstyleman_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_ClassList[93*a],&_Context->libsort_ClassList[93*b],47);	/* comparaison zone 1 */
switch (_Context->formsort_ClassList) {
	case 1:	/* classname ordre normal */
		return(i);

	case -1:	/* classname ordre inverse */
		return(-i);

	case 2:	/* baseclass ordre normal */
		j=memicmp(&_Context->libsort_ClassList[93*a+47],&_Context->libsort_ClassList[93*b+47],21);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* baseclass ordre inverse */
		j=memicmp(&_Context->libsort_ClassList[93*b+47],&_Context->libsort_ClassList[93*a+47],21);
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
private int  sort_item_FileList(struct cstyleman_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_FileList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_FileList(struct cstyleman_context * _Context,int nelts)
{
if (_Context->nelt_FileList<nelts) {
	liberate(_Context->tabsort_FileList);
	if ((_Context->tabsort_FileList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_FileList=0;_Context->nelt_FileList<nelts;_Context->nelt_FileList++)
		{ _Context->tabsort_FileList[_Context->nelt_FileList]=_Context->nelt_FileList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_FileList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_FileList=allocate(nelts*47)) != NULL)
	memset(_Context->libsort_FileList,' ',nelts*47);
}

/* ----------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_FileList */
/* ----------------------------------------------------------- */
private void sort_FileList(struct cstyleman_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_FileList,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_FileList[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_FileList[j]) && (compare_FileList(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_FileList[i]=k+1;
	_Context->indsort_FileList[k]=1;
	};	/* for i */
liberate(_Context->libsort_FileList);
liberate(_Context->indsort_FileList);
}

/* --------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_FileList */
/* --------------------------------------------------------- */
private int compare_FileList(struct cstyleman_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_FileList[47*a],&_Context->libsort_FileList[47*b],47);	/* comparaison zone 1 */
switch (_Context->formsort_FileList) {
	case 1:	/* filename ordre normal */
		return(i);

	case -1:	/* filename ordre inverse */
		return(-i);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}

/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_CFList(struct cstyleman_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_CFList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_CFList(struct cstyleman_context * _Context,int nelts)
{
if (_Context->nelt_CFList<nelts) {
	liberate(_Context->tabsort_CFList);
	if ((_Context->tabsort_CFList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_CFList=0;_Context->nelt_CFList<nelts;_Context->nelt_CFList++)
		{ _Context->tabsort_CFList[_Context->nelt_CFList]=_Context->nelt_CFList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_CFList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_CFList=allocate(nelts*43)) != NULL)
	memset(_Context->libsort_CFList,' ',nelts*43);
}

/* --------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_CFList */
/* --------------------------------------------------------- */
private void sort_CFList(struct cstyleman_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_CFList,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_CFList[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_CFList[j]) && (compare_CFList(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_CFList[i]=k+1;
	_Context->indsort_CFList[k]=1;
	};	/* for i */
liberate(_Context->libsort_CFList);
liberate(_Context->indsort_CFList);
}

/* ------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_CFList */
/* ------------------------------------------------------- */
private int compare_CFList(struct cstyleman_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_CFList[43*a],&_Context->libsort_CFList[43*b],43);	/* comparaison zone 1 */
switch (_Context->formsort_CFList) {
	case 1:	/* name ordre normal */
		return(i);

	case -1:	/* name ordre inverse */
		return(-i);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}


public	int	cstyleman_create(struct cstyleman_context **cptr)
{

	int i;
	struct cstyleman_context * _Context=(struct cstyleman_context*)0;
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
	if (!(_Context = allocate( sizeof( struct cstyleman_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=112;
	_Context->page_number=1;
	_Context->formsort_ClassList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_ClassList=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_ClassList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_ClassList=0;_Context->nelt_ClassList<512;_Context->nelt_ClassList++)
			{ _Context->tabsort_ClassList[_Context->nelt_ClassList]=_Context->nelt_ClassList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_ClassList=0; /* si problème d'allocation */
_Context->indsort_ClassList=NULL;	/* pas de pointeur de table intermédiaire */		for (i=0; i < 255; i++)  *(_Context->buffer_Action+i)=' ';
	_Context->formsort_FileList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_FileList=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_FileList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_FileList=0;_Context->nelt_FileList<512;_Context->nelt_FileList++)
			{ _Context->tabsort_FileList[_Context->nelt_FileList]=_Context->nelt_FileList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_FileList=0; /* si problème d'allocation */
_Context->indsort_FileList=NULL;	/* pas de pointeur de table intermédiaire */	_Context->formsort_CFList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_CFList=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_CFList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_CFList=0;_Context->nelt_CFList<512;_Context->nelt_CFList++)
			{ _Context->tabsort_CFList[_Context->nelt_CFList]=_Context->nelt_CFList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_CFList=0; /* si problème d'allocation */
_Context->indsort_CFList=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_CLBar=0;
		_Context->limit_CLBar=0;
		_Context->value_CLBar=0;
		_Context->max_MLBar=0;
		_Context->limit_MLBar=0;
		_Context->value_MLBar=0;
		_Context->max_FLBar=0;
		_Context->limit_FLBar=0;
		_Context->value_FLBar=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_StatusBar+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_ClassName+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_BaseClass+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_Description+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_ClassFile+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_ExportName+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_ImportName+i)=' ';
		_Context->value_ct=0;
		_Context->value_posv=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_cwv+i)=' ';
		_Context->value_cwt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_chv+i)=' ';
		_Context->value_cht=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_cplv+i)=' ';
		_Context->value_cplt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_cptv+i)=' ';
		for (i=0; i < 9; i++)  *(_Context->buffer_cprv+i)=' ';
		for (i=0; i < 9; i++)  *(_Context->buffer_cpbv+i)=' ';
		_Context->value_cptt=0;
		_Context->value_cprt=0;
		_Context->value_cpbt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_mlv+i)=' ';
		_Context->value_mlt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_mgv+i)=' ';
		_Context->value_mgt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_mtv+i)=' ';
		_Context->value_mtt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_mrv+i)=' ';
		_Context->value_mrt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_mbv+i)=' ';
		_Context->value_mbt=0;
		_Context->value_bdct=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_bdcv+i)=' ';
		_Context->value_bdat=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_blu+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_btu+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_bbu+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_bru+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_ctlu+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_ctru+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_cblu+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_cbru+i)=' ';
		for (i=0; i < 9; i++)  *(_Context->buffer_blv+i)=' ';
		_Context->value_blt=0;
		_Context->value_bdsv=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_btv+i)=' ';
		_Context->value_btt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_brv+i)=' ';
		for (i=0; i < 9; i++)  *(_Context->buffer_bwv+i)=' ';
		_Context->value_brt=0;
		_Context->value_bwt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_bbv+i)=' ';
		_Context->value_bbt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_plv+i)=' ';
		_Context->value_plt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_pgv+i)=' ';
		_Context->value_pgt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_ptv+i)=' ';
		_Context->value_ptt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_prv+i)=' ';
		_Context->value_prt=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_pbv+i)=' ';
		_Context->value_pbt=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_bgi+i)=' ';
		_Context->value_bgia=0;
		_Context->value_bgitr=0;
		_Context->value_bgct=0;
		for (i=0; i < 10; i++)  *(_Context->buffer_bgcv+i)=' ';
		_Context->value_txtol=0;
		_Context->value_txtlt=0;
		_Context->value_txtul=0;
		_Context->value_txtbo=0;
		_Context->value_txtsh=0;
		_Context->value_txtbl=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_txfu+i)=' ';
		_Context->value_txct=0;
		for (i=0; i < 9; i++)  *(_Context->buffer_txcv+i)=' ';
		_Context->value_txta=0;
		for (i=0; i < 12; i++)  *(_Context->buffer_ltspv+i)=' ';
		_Context->value_ltspt=0;
		for (i=0; i < 12; i++)  *(_Context->buffer_wspv+i)=' ';
		_Context->value_wspt=0;
		for (i=0; i < 12; i++)  *(_Context->buffer_lnspv+i)=' ';
		_Context->value_lnspt=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_Message+i)=' ';
	for (i=0; i < 8; i++)_Context->msg_Auto3628[i]=" ";
	_Context->hint_Auto3628[0]=en__Auto3628;
	_Context->hint_Auto3628[1]=fr__Auto3628;
	_Context->hint_Auto3628[2]=it__Auto3628;
	_Context->hint_Auto3628[3]=es__Auto3628;
	_Context->hint_Auto3628[4]=de__Auto3628;
	_Context->hint_Auto3628[5]=nl__Auto3628;
	_Context->hint_Auto3628[6]=pt__Auto3628;
	_Context->hint_Auto3628[7]=xx__Auto3628;
	_Context->x_Auto3628=107;
	_Context->y_Auto3628=74;
	_Context->w_Auto3628=810;
	_Context->h_Auto3628=620;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3629[i]=" ";
	_Context->msg_Auto3629[0]=en_Auto3629;
	_Context->msg_Auto3629[1]=fr_Auto3629;
	_Context->msg_Auto3629[2]=it_Auto3629;
	_Context->msg_Auto3629[3]=es_Auto3629;
	_Context->msg_Auto3629[4]=de_Auto3629;
	_Context->msg_Auto3629[5]=nl_Auto3629;
	_Context->msg_Auto3629[6]=pt_Auto3629;
	_Context->msg_Auto3629[7]=xx_Auto3629;
	_Context->hint_Auto3629[0]=en__Auto3629;
	_Context->hint_Auto3629[1]=fr__Auto3629;
	_Context->hint_Auto3629[2]=it__Auto3629;
	_Context->hint_Auto3629[3]=es__Auto3629;
	_Context->hint_Auto3629[4]=de__Auto3629;
	_Context->hint_Auto3629[5]=nl__Auto3629;
	_Context->hint_Auto3629[6]=pt__Auto3629;
	_Context->hint_Auto3629[7]=xx__Auto3629;
	for (i=0; i < 8; i++)_Context->msg_Trash[i]=" ";
	_Context->msg_Trash[0]=en_Trash;
	_Context->msg_Trash[1]=fr_Trash;
	_Context->msg_Trash[2]=it_Trash;
	_Context->msg_Trash[3]=es_Trash;
	_Context->msg_Trash[4]=de_Trash;
	_Context->msg_Trash[5]=nl_Trash;
	_Context->msg_Trash[6]=pt_Trash;
	_Context->msg_Trash[7]=xx_Trash;
	_Context->hint_Trash[0]=en__Trash;
	_Context->hint_Trash[1]=fr__Trash;
	_Context->hint_Trash[2]=it__Trash;
	_Context->hint_Trash[3]=es__Trash;
	_Context->hint_Trash[4]=de__Trash;
	_Context->hint_Trash[5]=nl__Trash;
	_Context->hint_Trash[6]=pt__Trash;
	_Context->hint_Trash[7]=xx__Trash;
	for (i=0; i < 8; i++)_Context->msg_Trace[i]=" ";
	_Context->msg_Trace[0]=en_Trace;
	_Context->msg_Trace[1]=fr_Trace;
	_Context->msg_Trace[2]=it_Trace;
	_Context->msg_Trace[3]=es_Trace;
	_Context->msg_Trace[4]=de_Trace;
	_Context->msg_Trace[5]=nl_Trace;
	_Context->msg_Trace[6]=pt_Trace;
	_Context->msg_Trace[7]=xx_Trace;
	_Context->hint_Trace[0]=en__Trace;
	_Context->hint_Trace[1]=fr__Trace;
	_Context->hint_Trace[2]=it__Trace;
	_Context->hint_Trace[3]=es__Trace;
	_Context->hint_Trace[4]=de__Trace;
	_Context->hint_Trace[5]=nl__Trace;
	_Context->hint_Trace[6]=pt__Trace;
	_Context->hint_Trace[7]=xx__Trace;
	_Context->s_Trace=0;
	_Context->p_Trace=visual_buffer(_Context->x_Auto3628+680,_Context->y_Auto3628+30,40+2,40+2);
	for (i=0; i < 8; i++)_Context->msg_Classes[i]=" ";
	_Context->msg_Classes[0]=en_Classes;
	_Context->msg_Classes[1]=fr_Classes;
	_Context->msg_Classes[2]=it_Classes;
	_Context->msg_Classes[3]=es_Classes;
	_Context->msg_Classes[4]=de_Classes;
	_Context->msg_Classes[5]=nl_Classes;
	_Context->msg_Classes[6]=pt_Classes;
	_Context->msg_Classes[7]=xx_Classes;
	_Context->hint_Classes[0]=en__Classes;
	for (i=0; i < 8; i++)_Context->msg_Files[i]=" ";
	_Context->msg_Files[0]=en_Files;
	_Context->msg_Files[1]=fr_Files;
	_Context->msg_Files[2]=it_Files;
	_Context->msg_Files[3]=es_Files;
	_Context->msg_Files[4]=de_Files;
	_Context->msg_Files[5]=nl_Files;
	_Context->msg_Files[6]=pt_Files;
	_Context->msg_Files[7]=xx_Files;
	_Context->hint_Files[0]=en__Files;
	for (i=0; i < 8; i++)_Context->msg_FileWork[i]=" ";
	_Context->msg_FileWork[0]=en_FileWork;
	_Context->hint_FileWork[0]=en__FileWork;
	for (i=0; i < 8; i++)_Context->msg_ImportFile[i]=" ";
	_Context->msg_ImportFile[0]=en_ImportFile;
	_Context->hint_ImportFile[0]=en__ImportFile;
	for (i=0; i < 8; i++)_Context->msg_Members[i]=" ";
	_Context->msg_Members[0]=en_Members;
	_Context->msg_Members[1]=fr_Members;
	_Context->msg_Members[2]=it_Members;
	_Context->msg_Members[3]=es_Members;
	_Context->msg_Members[4]=de_Members;
	_Context->msg_Members[5]=nl_Members;
	_Context->msg_Members[6]=pt_Members;
	_Context->msg_Members[7]=xx_Members;
	_Context->hint_Members[0]=en__Members;
	for (i=0; i < 8; i++)_Context->msg_ImportMember[i]=" ";
	_Context->msg_ImportMember[0]=en_ImportMember;
	_Context->hint_ImportMember[0]=en__ImportMember;
	for (i=0; i < 8; i++)_Context->msg_Worker[i]=" ";
	_Context->msg_Worker[0]=en_Worker;
	_Context->hint_Worker[0]=en__Worker;
	for (i=0; i < 8; i++)_Context->msg_CLPage[i]=" ";
	_Context->msg_CLPage[0]=en_CLPage;
	_Context->msg_CLPage[1]=fr_CLPage;
	_Context->msg_CLPage[2]=it_CLPage;
	_Context->msg_CLPage[3]=es_CLPage;
	_Context->msg_CLPage[4]=de_CLPage;
	_Context->msg_CLPage[5]=nl_CLPage;
	_Context->msg_CLPage[6]=pt_CLPage;
	_Context->msg_CLPage[7]=xx_CLPage;
	_Context->hint_CLPage[0]=en__CLPage;
	_Context->focus_pages[1]=5;
	for (i=0; i < 8; i++)_Context->msg_ClassList[i]=" ";
	_Context->msg_ClassList[0]=en_ClassList;
	_Context->msg_ClassList[1]=fr_ClassList;
	_Context->msg_ClassList[2]=it_ClassList;
	_Context->msg_ClassList[3]=es_ClassList;
	_Context->msg_ClassList[4]=de_ClassList;
	_Context->msg_ClassList[5]=nl_ClassList;
	_Context->msg_ClassList[6]=pt_ClassList;
	_Context->msg_ClassList[7]=xx_ClassList;
	_Context->hint_ClassList[0]=en__ClassList;
	_Context->hint_ClassList[1]=fr__ClassList;
	_Context->hint_ClassList[2]=it__ClassList;
	_Context->hint_ClassList[3]=es__ClassList;
	_Context->hint_ClassList[4]=de__ClassList;
	_Context->hint_ClassList[5]=nl__ClassList;
	_Context->hint_ClassList[6]=pt__ClassList;
	_Context->hint_ClassList[7]=xx__ClassList;
	if ( 0 > 0 ) { _Context->row_ClassList=&_Context->buffer_ClassList[0-1][0]; } ;
	_Context->hint_CLCursor[0]=en__CLCursor;
	_Context->x_CLCursor=_Context->x_Auto3628+20;
	_Context->y_CLCursor=_Context->y_Auto3628+90;
	_Context->w_CLCursor=380;
	_Context->h_CLCursor=20;
	_Context->fg_CLCursor=20;
	_Context->bg_CLCursor=20;
	_Context->fid_CLCursor=1;
	_Context->hint_Action[0]=en__Action;
	_Context->x_Action=_Context->x_Auto3628+20;
	_Context->y_Action=_Context->y_Auto3628+90;
	_Context->w_Action=380;
	_Context->h_Action=20;
	_Context->fg_Action=20;
	_Context->bg_Action=20;
	_Context->fid_Action=1;
	_Context->s_Action=0;
	_Context->p_Action=visual_buffer(_Context->x_Action,_Context->y_Action,_Context->w_Action+2,_Context->h_Action+2);
	for (i=0; i < 8; i++)_Context->msg_FileList[i]=" ";
	_Context->msg_FileList[0]=en_FileList;
	_Context->msg_FileList[1]=fr_FileList;
	_Context->msg_FileList[2]=it_FileList;
	_Context->msg_FileList[3]=es_FileList;
	_Context->msg_FileList[4]=de_FileList;
	_Context->msg_FileList[5]=nl_FileList;
	_Context->msg_FileList[6]=pt_FileList;
	_Context->msg_FileList[7]=xx_FileList;
	_Context->hint_FileList[0]=en__FileList;
	_Context->hint_FileList[1]=fr__FileList;
	_Context->hint_FileList[2]=it__FileList;
	_Context->hint_FileList[3]=es__FileList;
	_Context->hint_FileList[4]=de__FileList;
	_Context->hint_FileList[5]=nl__FileList;
	_Context->hint_FileList[6]=pt__FileList;
	_Context->hint_FileList[7]=xx__FileList;
	if ( 0 > 0 ) { _Context->row_FileList=&_Context->buffer_FileList[0-1][0]; } ;
	_Context->hint_FLCursor[0]=en__FLCursor;
	_Context->x_FLCursor=_Context->x_Auto3628+390;
	_Context->y_FLCursor=_Context->y_Auto3628+340;
	_Context->w_FLCursor=380;
	_Context->h_FLCursor=20;
	_Context->fg_FLCursor=20;
	_Context->bg_FLCursor=20;
	_Context->fid_FLCursor=1;
	for (i=0; i < 8; i++)_Context->msg_CFList[i]=" ";
	_Context->msg_CFList[0]=en_CFList;
	_Context->msg_CFList[1]=fr_CFList;
	_Context->msg_CFList[2]=it_CFList;
	_Context->msg_CFList[3]=es_CFList;
	_Context->msg_CFList[4]=de_CFList;
	_Context->msg_CFList[5]=nl_CFList;
	_Context->msg_CFList[6]=pt_CFList;
	_Context->msg_CFList[7]=xx_CFList;
	_Context->hint_CFList[0]=en__CFList;
	_Context->hint_CFList[1]=fr__CFList;
	_Context->hint_CFList[2]=it__CFList;
	_Context->hint_CFList[3]=es__CFList;
	_Context->hint_CFList[4]=de__CFList;
	_Context->hint_CFList[5]=nl__CFList;
	_Context->hint_CFList[6]=pt__CFList;
	_Context->hint_CFList[7]=xx__CFList;
	if ( 0 > 0 ) { _Context->row_CFList=&_Context->buffer_CFList[0-1][0]; } ;
	_Context->hint_MLCursor[0]=en__MLCursor;
	_Context->x_MLCursor=_Context->x_Auto3628+20;
	_Context->y_MLCursor=_Context->y_Auto3628+340;
	_Context->w_MLCursor=350;
	_Context->h_MLCursor=20;
	_Context->fg_MLCursor=20;
	_Context->bg_MLCursor=20;
	_Context->fid_MLCursor=1;
	_Context->hint_CLBar[0]=en__CLBar;
	_Context->max_CLBar=1;
	_Context->value_CLBar=1;
	_Context->limit_CLBar=1;
	_Context->value_CLBar=0;
	_Context->limit_CLBar=14;
	_Context->max_CLBar=_Context->limit_CLBar;
	_Context->hint_MLBar[0]=en__MLBar;
	_Context->max_MLBar=1;
	_Context->value_MLBar=1;
	_Context->limit_MLBar=1;
	_Context->value_MLBar=0;
	_Context->limit_MLBar=15;
	_Context->max_MLBar=_Context->limit_MLBar;
	_Context->hint_FLBar[0]=en__FLBar;
	_Context->max_FLBar=1;
	_Context->value_FLBar=1;
	_Context->limit_FLBar=1;
	_Context->value_FLBar=0;
	_Context->limit_FLBar=15;
	_Context->max_FLBar=_Context->limit_FLBar;
	for (i=0; i < 8; i++)_Context->msg_StylePage[i]=" ";
	_Context->msg_StylePage[0]=en_StylePage;
	_Context->msg_StylePage[1]=fr_StylePage;
	_Context->msg_StylePage[2]=it_StylePage;
	_Context->msg_StylePage[3]=es_StylePage;
	_Context->msg_StylePage[4]=de_StylePage;
	_Context->msg_StylePage[5]=nl_StylePage;
	_Context->msg_StylePage[6]=pt_StylePage;
	_Context->msg_StylePage[7]=xx_StylePage;
	_Context->hint_StylePage[0]=en__StylePage;
	_Context->focus_pages[2]=12;
	for (i=0; i < 8; i++)_Context->msg_ExportNameError[i]=" ";
	_Context->msg_ExportNameError[0]=en_ExportNameError;
	_Context->msg_ExportNameError[1]=fr_ExportNameError;
	_Context->msg_ExportNameError[2]=it_ExportNameError;
	_Context->msg_ExportNameError[3]=es_ExportNameError;
	_Context->msg_ExportNameError[4]=de_ExportNameError;
	_Context->msg_ExportNameError[5]=nl_ExportNameError;
	_Context->msg_ExportNameError[6]=pt_ExportNameError;
	_Context->msg_ExportNameError[7]=xx_ExportNameError;
	_Context->hint_ExportNameError[0]=en__ExportNameError;
	_Context->hint_ExportNameError[1]=fr__ExportNameError;
	_Context->hint_ExportNameError[2]=it__ExportNameError;
	_Context->hint_ExportNameError[3]=es__ExportNameError;
	_Context->hint_ExportNameError[4]=de__ExportNameError;
	_Context->hint_ExportNameError[5]=nl__ExportNameError;
	_Context->hint_ExportNameError[6]=pt__ExportNameError;
	_Context->hint_ExportNameError[7]=xx__ExportNameError;
	_Context->hint_StatusBar[0]=en__StatusBar;
	for (i=0; i < 8; i++)_Context->msg_Auto3631[i]=" ";
	_Context->msg_Auto3631[0]=en_Auto3631;
	_Context->msg_Auto3631[1]=fr_Auto3631;
	_Context->msg_Auto3631[2]=it_Auto3631;
	_Context->msg_Auto3631[3]=es_Auto3631;
	_Context->msg_Auto3631[4]=de_Auto3631;
	_Context->msg_Auto3631[5]=nl_Auto3631;
	_Context->msg_Auto3631[6]=pt_Auto3631;
	_Context->msg_Auto3631[7]=xx_Auto3631;
	_Context->hint_Auto3631[0]=en__Auto3631;
	_Context->hint_Auto3631[1]=fr__Auto3631;
	_Context->hint_Auto3631[2]=it__Auto3631;
	_Context->hint_Auto3631[3]=es__Auto3631;
	_Context->hint_Auto3631[4]=de__Auto3631;
	_Context->hint_Auto3631[5]=nl__Auto3631;
	_Context->hint_Auto3631[6]=pt__Auto3631;
	_Context->hint_Auto3631[7]=xx__Auto3631;
	for (i=0; i < 8; i++)_Context->msg_Auto3632[i]=" ";
	_Context->msg_Auto3632[0]=en_Auto3632;
	_Context->msg_Auto3632[1]=fr_Auto3632;
	_Context->msg_Auto3632[2]=it_Auto3632;
	_Context->msg_Auto3632[3]=es_Auto3632;
	_Context->msg_Auto3632[4]=de_Auto3632;
	_Context->msg_Auto3632[5]=nl_Auto3632;
	_Context->msg_Auto3632[6]=pt_Auto3632;
	_Context->msg_Auto3632[7]=xx_Auto3632;
	_Context->hint_Auto3632[0]=en__Auto3632;
	_Context->hint_Auto3632[1]=fr__Auto3632;
	_Context->hint_Auto3632[2]=it__Auto3632;
	_Context->hint_Auto3632[3]=es__Auto3632;
	_Context->hint_Auto3632[4]=de__Auto3632;
	_Context->hint_Auto3632[5]=nl__Auto3632;
	_Context->hint_Auto3632[6]=pt__Auto3632;
	_Context->hint_Auto3632[7]=xx__Auto3632;
	for (i=0; i < 8; i++)_Context->msg_Auto3633[i]=" ";
	_Context->msg_Auto3633[0]=en_Auto3633;
	_Context->msg_Auto3633[1]=fr_Auto3633;
	_Context->msg_Auto3633[2]=it_Auto3633;
	_Context->msg_Auto3633[3]=es_Auto3633;
	_Context->msg_Auto3633[4]=de_Auto3633;
	_Context->msg_Auto3633[5]=nl_Auto3633;
	_Context->msg_Auto3633[6]=pt_Auto3633;
	_Context->msg_Auto3633[7]=xx_Auto3633;
	_Context->hint_Auto3633[0]=en__Auto3633;
	_Context->hint_Auto3633[1]=fr__Auto3633;
	_Context->hint_Auto3633[2]=it__Auto3633;
	_Context->hint_Auto3633[3]=es__Auto3633;
	_Context->hint_Auto3633[4]=de__Auto3633;
	_Context->hint_Auto3633[5]=nl__Auto3633;
	_Context->hint_Auto3633[6]=pt__Auto3633;
	_Context->hint_Auto3633[7]=xx__Auto3633;
	for (i=0; i < 8; i++)_Context->msg_Auto3634[i]=" ";
	_Context->msg_Auto3634[0]=en_Auto3634;
	_Context->msg_Auto3634[1]=fr_Auto3634;
	_Context->msg_Auto3634[2]=it_Auto3634;
	_Context->msg_Auto3634[3]=es_Auto3634;
	_Context->msg_Auto3634[4]=de_Auto3634;
	_Context->msg_Auto3634[5]=nl_Auto3634;
	_Context->msg_Auto3634[6]=pt_Auto3634;
	_Context->msg_Auto3634[7]=xx_Auto3634;
	_Context->hint_Auto3634[0]=en__Auto3634;
	_Context->hint_Auto3634[1]=fr__Auto3634;
	_Context->hint_Auto3634[2]=it__Auto3634;
	_Context->hint_Auto3634[3]=es__Auto3634;
	_Context->hint_Auto3634[4]=de__Auto3634;
	_Context->hint_Auto3634[5]=nl__Auto3634;
	_Context->hint_Auto3634[6]=pt__Auto3634;
	_Context->hint_Auto3634[7]=xx__Auto3634;
	for (i=0; i < 8; i++)_Context->msg_Auto3635[i]=" ";
	_Context->msg_Auto3635[0]=en_Auto3635;
	_Context->msg_Auto3635[1]=fr_Auto3635;
	_Context->msg_Auto3635[2]=it_Auto3635;
	_Context->msg_Auto3635[3]=es_Auto3635;
	_Context->msg_Auto3635[4]=de_Auto3635;
	_Context->msg_Auto3635[5]=nl_Auto3635;
	_Context->msg_Auto3635[6]=pt_Auto3635;
	_Context->msg_Auto3635[7]=xx_Auto3635;
	_Context->hint_Auto3635[0]=en__Auto3635;
	_Context->hint_Auto3635[1]=fr__Auto3635;
	_Context->hint_Auto3635[2]=it__Auto3635;
	_Context->hint_Auto3635[3]=es__Auto3635;
	_Context->hint_Auto3635[4]=de__Auto3635;
	_Context->hint_Auto3635[5]=nl__Auto3635;
	_Context->hint_Auto3635[6]=pt__Auto3635;
	_Context->hint_Auto3635[7]=xx__Auto3635;
	for (i=0; i < 8; i++)_Context->msg_Auto3636[i]=" ";
	_Context->msg_Auto3636[0]=en_Auto3636;
	_Context->msg_Auto3636[1]=fr_Auto3636;
	_Context->msg_Auto3636[2]=it_Auto3636;
	_Context->msg_Auto3636[3]=es_Auto3636;
	_Context->msg_Auto3636[4]=de_Auto3636;
	_Context->msg_Auto3636[5]=nl_Auto3636;
	_Context->msg_Auto3636[6]=pt_Auto3636;
	_Context->msg_Auto3636[7]=xx_Auto3636;
	_Context->hint_Auto3636[0]=en__Auto3636;
	_Context->hint_Auto3636[1]=fr__Auto3636;
	_Context->hint_Auto3636[2]=it__Auto3636;
	_Context->hint_Auto3636[3]=es__Auto3636;
	_Context->hint_Auto3636[4]=de__Auto3636;
	_Context->hint_Auto3636[5]=nl__Auto3636;
	_Context->hint_Auto3636[6]=pt__Auto3636;
	_Context->hint_Auto3636[7]=xx__Auto3636;
	for (i=0; i < 8; i++)_Context->msg_Auto3637[i]=" ";
	_Context->msg_Auto3637[0]=en_Auto3637;
	_Context->msg_Auto3637[1]=fr_Auto3637;
	_Context->msg_Auto3637[2]=it_Auto3637;
	_Context->msg_Auto3637[3]=es_Auto3637;
	_Context->msg_Auto3637[4]=de_Auto3637;
	_Context->msg_Auto3637[5]=nl_Auto3637;
	_Context->msg_Auto3637[6]=pt_Auto3637;
	_Context->msg_Auto3637[7]=xx_Auto3637;
	_Context->hint_Auto3637[0]=en__Auto3637;
	_Context->hint_Auto3637[1]=fr__Auto3637;
	_Context->hint_Auto3637[2]=it__Auto3637;
	_Context->hint_Auto3637[3]=es__Auto3637;
	_Context->hint_Auto3637[4]=de__Auto3637;
	_Context->hint_Auto3637[5]=nl__Auto3637;
	_Context->hint_Auto3637[6]=pt__Auto3637;
	_Context->hint_Auto3637[7]=xx__Auto3637;
	_Context->hint_ClassName[0]=en__ClassName;
	for (i=0; i < 8; i++)_Context->msg_LoadOperation[i]=" ";
	_Context->msg_LoadOperation[0]=en_LoadOperation;
	_Context->msg_LoadOperation[1]=fr_LoadOperation;
	_Context->msg_LoadOperation[2]=it_LoadOperation;
	_Context->msg_LoadOperation[3]=es_LoadOperation;
	_Context->msg_LoadOperation[4]=de_LoadOperation;
	_Context->msg_LoadOperation[5]=nl_LoadOperation;
	_Context->msg_LoadOperation[6]=pt_LoadOperation;
	_Context->msg_LoadOperation[7]=xx_LoadOperation;
	_Context->hint_LoadOperation[0]=en__LoadOperation;
	_Context->hint_LoadOperation[1]=fr__LoadOperation;
	_Context->hint_LoadOperation[2]=it__LoadOperation;
	_Context->hint_LoadOperation[3]=es__LoadOperation;
	_Context->hint_LoadOperation[4]=de__LoadOperation;
	_Context->hint_LoadOperation[5]=nl__LoadOperation;
	_Context->hint_LoadOperation[6]=pt__LoadOperation;
	_Context->hint_LoadOperation[7]=xx__LoadOperation;
	for (i=0; i < 8; i++)_Context->msg_Reset[i]=" ";
	_Context->msg_Reset[0]=en_Reset;
	_Context->msg_Reset[1]=fr_Reset;
	_Context->msg_Reset[2]=it_Reset;
	_Context->msg_Reset[3]=es_Reset;
	_Context->msg_Reset[4]=de_Reset;
	_Context->msg_Reset[5]=nl_Reset;
	_Context->msg_Reset[6]=pt_Reset;
	_Context->msg_Reset[7]=xx_Reset;
	_Context->hint_Reset[0]=en__Reset;
	_Context->hint_Reset[1]=fr__Reset;
	_Context->hint_Reset[2]=it__Reset;
	_Context->hint_Reset[3]=es__Reset;
	_Context->hint_Reset[4]=de__Reset;
	_Context->hint_Reset[5]=nl__Reset;
	_Context->hint_Reset[6]=pt__Reset;
	_Context->hint_Reset[7]=xx__Reset;
	_Context->hint_BaseClass[0]=en__BaseClass;
	_Context->hint_Description[0]=en__Description;
	_Context->hint_ClassFile[0]=en__ClassFile;
	for (i=0; i < 8; i++)_Context->msg_SaveOperation[i]=" ";
	_Context->msg_SaveOperation[0]=en_SaveOperation;
	_Context->msg_SaveOperation[1]=fr_SaveOperation;
	_Context->msg_SaveOperation[2]=it_SaveOperation;
	_Context->msg_SaveOperation[3]=es_SaveOperation;
	_Context->msg_SaveOperation[4]=de_SaveOperation;
	_Context->msg_SaveOperation[5]=nl_SaveOperation;
	_Context->msg_SaveOperation[6]=pt_SaveOperation;
	_Context->msg_SaveOperation[7]=xx_SaveOperation;
	_Context->hint_SaveOperation[0]=en__SaveOperation;
	_Context->hint_SaveOperation[1]=fr__SaveOperation;
	_Context->hint_SaveOperation[2]=it__SaveOperation;
	_Context->hint_SaveOperation[3]=es__SaveOperation;
	_Context->hint_SaveOperation[4]=de__SaveOperation;
	_Context->hint_SaveOperation[5]=nl__SaveOperation;
	_Context->hint_SaveOperation[6]=pt__SaveOperation;
	_Context->hint_SaveOperation[7]=xx__SaveOperation;
	for (i=0; i < 8; i++)_Context->msg_ViewFile[i]=" ";
	_Context->msg_ViewFile[0]=en_ViewFile;
	_Context->msg_ViewFile[1]=fr_ViewFile;
	_Context->msg_ViewFile[2]=it_ViewFile;
	_Context->msg_ViewFile[3]=es_ViewFile;
	_Context->msg_ViewFile[4]=de_ViewFile;
	_Context->msg_ViewFile[5]=nl_ViewFile;
	_Context->msg_ViewFile[6]=pt_ViewFile;
	_Context->msg_ViewFile[7]=xx_ViewFile;
	_Context->hint_ViewFile[0]=en__ViewFile;
	_Context->hint_ViewFile[1]=fr__ViewFile;
	_Context->hint_ViewFile[2]=it__ViewFile;
	_Context->hint_ViewFile[3]=es__ViewFile;
	_Context->hint_ViewFile[4]=de__ViewFile;
	_Context->hint_ViewFile[5]=nl__ViewFile;
	_Context->hint_ViewFile[6]=pt__ViewFile;
	_Context->hint_ViewFile[7]=xx__ViewFile;
	_Context->hint_ExportName[0]=en__ExportName;
	for (i=0; i < 8; i++)_Context->msg_ExportOperation[i]=" ";
	_Context->msg_ExportOperation[0]=en_ExportOperation;
	_Context->msg_ExportOperation[1]=fr_ExportOperation;
	_Context->msg_ExportOperation[2]=it_ExportOperation;
	_Context->msg_ExportOperation[3]=es_ExportOperation;
	_Context->msg_ExportOperation[4]=de_ExportOperation;
	_Context->msg_ExportOperation[5]=nl_ExportOperation;
	_Context->msg_ExportOperation[6]=pt_ExportOperation;
	_Context->msg_ExportOperation[7]=xx_ExportOperation;
	_Context->hint_ExportOperation[0]=en__ExportOperation;
	_Context->hint_ExportOperation[1]=fr__ExportOperation;
	_Context->hint_ExportOperation[2]=it__ExportOperation;
	_Context->hint_ExportOperation[3]=es__ExportOperation;
	_Context->hint_ExportOperation[4]=de__ExportOperation;
	_Context->hint_ExportOperation[5]=nl__ExportOperation;
	_Context->hint_ExportOperation[6]=pt__ExportOperation;
	_Context->hint_ExportOperation[7]=xx__ExportOperation;
	for (i=0; i < 8; i++)_Context->msg_ViewExport[i]=" ";
	_Context->msg_ViewExport[0]=en_ViewExport;
	_Context->msg_ViewExport[1]=fr_ViewExport;
	_Context->msg_ViewExport[2]=it_ViewExport;
	_Context->msg_ViewExport[3]=es_ViewExport;
	_Context->msg_ViewExport[4]=de_ViewExport;
	_Context->msg_ViewExport[5]=nl_ViewExport;
	_Context->msg_ViewExport[6]=pt_ViewExport;
	_Context->msg_ViewExport[7]=xx_ViewExport;
	_Context->hint_ViewExport[0]=en__ViewExport;
	_Context->hint_ViewExport[1]=fr__ViewExport;
	_Context->hint_ViewExport[2]=it__ViewExport;
	_Context->hint_ViewExport[3]=es__ViewExport;
	_Context->hint_ViewExport[4]=de__ViewExport;
	_Context->hint_ViewExport[5]=nl__ViewExport;
	_Context->hint_ViewExport[6]=pt__ViewExport;
	_Context->hint_ViewExport[7]=xx__ViewExport;
	_Context->hint_ImportName[0]=en__ImportName;
	for (i=0; i < 8; i++)_Context->msg_ImportOperation[i]=" ";
	_Context->msg_ImportOperation[0]=en_ImportOperation;
	_Context->msg_ImportOperation[1]=fr_ImportOperation;
	_Context->msg_ImportOperation[2]=it_ImportOperation;
	_Context->msg_ImportOperation[3]=es_ImportOperation;
	_Context->msg_ImportOperation[4]=de_ImportOperation;
	_Context->msg_ImportOperation[5]=nl_ImportOperation;
	_Context->msg_ImportOperation[6]=pt_ImportOperation;
	_Context->msg_ImportOperation[7]=xx_ImportOperation;
	_Context->hint_ImportOperation[0]=en__ImportOperation;
	_Context->hint_ImportOperation[1]=fr__ImportOperation;
	_Context->hint_ImportOperation[2]=it__ImportOperation;
	_Context->hint_ImportOperation[3]=es__ImportOperation;
	_Context->hint_ImportOperation[4]=de__ImportOperation;
	_Context->hint_ImportOperation[5]=nl__ImportOperation;
	_Context->hint_ImportOperation[6]=pt__ImportOperation;
	_Context->hint_ImportOperation[7]=xx__ImportOperation;
	for (i=0; i < 8; i++)_Context->msg_ViewImport[i]=" ";
	_Context->msg_ViewImport[0]=en_ViewImport;
	_Context->msg_ViewImport[1]=fr_ViewImport;
	_Context->msg_ViewImport[2]=it_ViewImport;
	_Context->msg_ViewImport[3]=es_ViewImport;
	_Context->msg_ViewImport[4]=de_ViewImport;
	_Context->msg_ViewImport[5]=nl_ViewImport;
	_Context->msg_ViewImport[6]=pt_ViewImport;
	_Context->msg_ViewImport[7]=xx_ViewImport;
	_Context->hint_ViewImport[0]=en__ViewImport;
	_Context->hint_ViewImport[1]=fr__ViewImport;
	_Context->hint_ViewImport[2]=it__ViewImport;
	_Context->hint_ViewImport[3]=es__ViewImport;
	_Context->hint_ViewImport[4]=de__ViewImport;
	_Context->hint_ViewImport[5]=nl__ViewImport;
	_Context->hint_ViewImport[6]=pt__ViewImport;
	_Context->hint_ViewImport[7]=xx__ViewImport;
	for (i=0; i < 8; i++)_Context->msg_TestPage[i]=" ";
	_Context->msg_TestPage[0]=en_TestPage;
	_Context->msg_TestPage[1]=fr_TestPage;
	_Context->msg_TestPage[2]=it_TestPage;
	_Context->msg_TestPage[3]=es_TestPage;
	_Context->msg_TestPage[4]=de_TestPage;
	_Context->msg_TestPage[5]=nl_TestPage;
	_Context->msg_TestPage[6]=pt_TestPage;
	_Context->msg_TestPage[7]=xx_TestPage;
	_Context->hint_TestPage[0]=en__TestPage;
	_Context->focus_pages[3]=27;
	for (i=0; i < 8; i++)_Context->msg_Thing[i]=" ";
	_Context->hint_Thing[0]=en__Thing;
	_Context->x_Thing=_Context->x_Auto3628+30;
	_Context->y_Thing=_Context->y_Auto3628+90;
	_Context->w_Thing=752;
	_Context->h_Thing=496;
	_Context->fg_Thing=496;
	_Context->bg_Thing=496;
	_Context->fid_Thing=1;
	_Context->s_Thing=0;
	_Context->p_Thing=visual_buffer(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing+2,_Context->h_Thing+2);
	for (i=0; i < 8; i++)_Context->msg_Cell[i]=" ";
	_Context->msg_Cell[0]=en_Cell;
	_Context->msg_Cell[1]=fr_Cell;
	_Context->msg_Cell[2]=it_Cell;
	_Context->msg_Cell[3]=es_Cell;
	_Context->msg_Cell[4]=de_Cell;
	_Context->msg_Cell[5]=nl_Cell;
	_Context->msg_Cell[6]=pt_Cell;
	_Context->msg_Cell[7]=xx_Cell;
	_Context->hint_Cell[0]=en__Cell;
	_Context->focus_pages[4]=29;
	for (i=0; i < 8; i++)_Context->msg_Auto3638[i]=" ";
	_Context->msg_Auto3638[0]=en_Auto3638;
	_Context->msg_Auto3638[1]=fr_Auto3638;
	_Context->msg_Auto3638[2]=it_Auto3638;
	_Context->msg_Auto3638[3]=es_Auto3638;
	_Context->msg_Auto3638[4]=de_Auto3638;
	_Context->msg_Auto3638[5]=nl_Auto3638;
	_Context->msg_Auto3638[6]=pt_Auto3638;
	_Context->msg_Auto3638[7]=xx_Auto3638;
	_Context->hint_Auto3638[0]=en__Auto3638;
	for (i=0; i < 8; i++)_Context->msg_Auto3639[i]=" ";
	_Context->msg_Auto3639[0]=en_Auto3639;
	_Context->msg_Auto3639[1]=fr_Auto3639;
	_Context->msg_Auto3639[2]=it_Auto3639;
	_Context->msg_Auto3639[3]=es_Auto3639;
	_Context->msg_Auto3639[4]=de_Auto3639;
	_Context->msg_Auto3639[5]=nl_Auto3639;
	_Context->msg_Auto3639[6]=pt_Auto3639;
	_Context->msg_Auto3639[7]=xx_Auto3639;
	_Context->hint_Auto3639[0]=en__Auto3639;
	_Context->hint_Auto3640[0]=en__Auto3640;
	_Context->hint_Auto3641[0]=en__Auto3641;
	for (i=0; i < 8; i++)_Context->msg_Auto3642[i]=" ";
	_Context->msg_Auto3642[0]=en_Auto3642;
	_Context->msg_Auto3642[1]=fr_Auto3642;
	_Context->msg_Auto3642[2]=it_Auto3642;
	_Context->msg_Auto3642[3]=es_Auto3642;
	_Context->msg_Auto3642[4]=de_Auto3642;
	_Context->msg_Auto3642[5]=nl_Auto3642;
	_Context->msg_Auto3642[6]=pt_Auto3642;
	_Context->msg_Auto3642[7]=xx_Auto3642;
	_Context->hint_Auto3642[0]=en__Auto3642;
	for (i=0; i < 8; i++)_Context->msg_Auto3643[i]=" ";
	_Context->msg_Auto3643[0]=en_Auto3643;
	_Context->msg_Auto3643[1]=fr_Auto3643;
	_Context->msg_Auto3643[2]=it_Auto3643;
	_Context->msg_Auto3643[3]=es_Auto3643;
	_Context->msg_Auto3643[4]=de_Auto3643;
	_Context->msg_Auto3643[5]=nl_Auto3643;
	_Context->msg_Auto3643[6]=pt_Auto3643;
	_Context->msg_Auto3643[7]=xx_Auto3643;
	_Context->hint_Auto3643[0]=en__Auto3643;
	for (i=0; i < 8; i++)_Context->msg_Auto3644[i]=" ";
	_Context->msg_Auto3644[0]=en_Auto3644;
	_Context->msg_Auto3644[1]=fr_Auto3644;
	_Context->msg_Auto3644[2]=it_Auto3644;
	_Context->msg_Auto3644[3]=es_Auto3644;
	_Context->msg_Auto3644[4]=de_Auto3644;
	_Context->msg_Auto3644[5]=nl_Auto3644;
	_Context->msg_Auto3644[6]=pt_Auto3644;
	_Context->msg_Auto3644[7]=xx_Auto3644;
	_Context->hint_Auto3644[0]=en__Auto3644;
	for (i=0; i < 8; i++)_Context->msg_Auto3645[i]=" ";
	_Context->msg_Auto3645[0]=en_Auto3645;
	_Context->msg_Auto3645[1]=fr_Auto3645;
	_Context->msg_Auto3645[2]=it_Auto3645;
	_Context->msg_Auto3645[3]=es_Auto3645;
	_Context->msg_Auto3645[4]=de_Auto3645;
	_Context->msg_Auto3645[5]=nl_Auto3645;
	_Context->msg_Auto3645[6]=pt_Auto3645;
	_Context->msg_Auto3645[7]=xx_Auto3645;
	_Context->hint_Auto3645[0]=en__Auto3645;
	for (i=0; i < 8; i++)_Context->msg_Auto3646[i]=" ";
	_Context->msg_Auto3646[0]=en_Auto3646;
	_Context->msg_Auto3646[1]=fr_Auto3646;
	_Context->msg_Auto3646[2]=it_Auto3646;
	_Context->msg_Auto3646[3]=es_Auto3646;
	_Context->msg_Auto3646[4]=de_Auto3646;
	_Context->msg_Auto3646[5]=nl_Auto3646;
	_Context->msg_Auto3646[6]=pt_Auto3646;
	_Context->msg_Auto3646[7]=xx_Auto3646;
	_Context->hint_Auto3646[0]=en__Auto3646;
	for (i=0; i < 8; i++)_Context->msg_Auto3647[i]=" ";
	_Context->msg_Auto3647[0]=en_Auto3647;
	_Context->msg_Auto3647[1]=fr_Auto3647;
	_Context->msg_Auto3647[2]=it_Auto3647;
	_Context->msg_Auto3647[3]=es_Auto3647;
	_Context->msg_Auto3647[4]=de_Auto3647;
	_Context->msg_Auto3647[5]=nl_Auto3647;
	_Context->msg_Auto3647[6]=pt_Auto3647;
	_Context->msg_Auto3647[7]=xx_Auto3647;
	_Context->hint_Auto3647[0]=en__Auto3647;
	for (i=0; i < 8; i++)_Context->msg_Auto3648[i]=" ";
	_Context->msg_Auto3648[0]=en_Auto3648;
	_Context->msg_Auto3648[1]=fr_Auto3648;
	_Context->msg_Auto3648[2]=it_Auto3648;
	_Context->msg_Auto3648[3]=es_Auto3648;
	_Context->msg_Auto3648[4]=de_Auto3648;
	_Context->msg_Auto3648[5]=nl_Auto3648;
	_Context->msg_Auto3648[6]=pt_Auto3648;
	_Context->msg_Auto3648[7]=xx_Auto3648;
	_Context->hint_Auto3648[0]=en__Auto3648;
	for (i=0; i < 8; i++)_Context->msg_Auto3649[i]=" ";
	_Context->msg_Auto3649[0]=en_Auto3649;
	_Context->msg_Auto3649[1]=fr_Auto3649;
	_Context->msg_Auto3649[2]=it_Auto3649;
	_Context->msg_Auto3649[3]=es_Auto3649;
	_Context->msg_Auto3649[4]=de_Auto3649;
	_Context->msg_Auto3649[5]=nl_Auto3649;
	_Context->msg_Auto3649[6]=pt_Auto3649;
	_Context->msg_Auto3649[7]=xx_Auto3649;
	_Context->hint_Auto3649[0]=en__Auto3649;
	for (i=0; i < 8; i++)_Context->msg_Auto3650[i]=" ";
	_Context->msg_Auto3650[0]=en_Auto3650;
	_Context->msg_Auto3650[1]=fr_Auto3650;
	_Context->msg_Auto3650[2]=it_Auto3650;
	_Context->msg_Auto3650[3]=es_Auto3650;
	_Context->msg_Auto3650[4]=de_Auto3650;
	_Context->msg_Auto3650[5]=nl_Auto3650;
	_Context->msg_Auto3650[6]=pt_Auto3650;
	_Context->msg_Auto3650[7]=xx_Auto3650;
	_Context->hint_Auto3650[0]=en__Auto3650;
	for (i=0; i < 8; i++)_Context->msg_ct[i]=" ";
	_Context->hint_ct[0]=en__ct;
	for (i=0; i < 8; i++)_Context->msg_posv[i]=" ";
	_Context->hint_posv[0]=en__posv;
	_Context->hint_cwv[0]=en__cwv;
	for (i=0; i < 8; i++)_Context->msg_cwt[i]=" ";
	_Context->hint_cwt[0]=en__cwt;
	_Context->hint_cwt[1]=fr__cwt;
	_Context->hint_cwt[2]=it__cwt;
	_Context->hint_cwt[3]=es__cwt;
	_Context->hint_cwt[4]=de__cwt;
	_Context->hint_cwt[5]=nl__cwt;
	_Context->hint_cwt[6]=pt__cwt;
	_Context->hint_cwt[7]=xx__cwt;
	_Context->hint_chv[0]=en__chv;
	for (i=0; i < 8; i++)_Context->msg_cht[i]=" ";
	_Context->hint_cht[0]=en__cht;
	_Context->hint_cht[1]=fr__cht;
	_Context->hint_cht[2]=it__cht;
	_Context->hint_cht[3]=es__cht;
	_Context->hint_cht[4]=de__cht;
	_Context->hint_cht[5]=nl__cht;
	_Context->hint_cht[6]=pt__cht;
	_Context->hint_cht[7]=xx__cht;
	_Context->hint_cplv[0]=en__cplv;
	for (i=0; i < 8; i++)_Context->msg_cplt[i]=" ";
	_Context->hint_cplt[0]=en__cplt;
	_Context->hint_cplt[1]=fr__cplt;
	_Context->hint_cplt[2]=it__cplt;
	_Context->hint_cplt[3]=es__cplt;
	_Context->hint_cplt[4]=de__cplt;
	_Context->hint_cplt[5]=nl__cplt;
	_Context->hint_cplt[6]=pt__cplt;
	_Context->hint_cplt[7]=xx__cplt;
	_Context->hint_cptv[0]=en__cptv;
	_Context->hint_cprv[0]=en__cprv;
	_Context->hint_cpbv[0]=en__cpbv;
	for (i=0; i < 8; i++)_Context->msg_cptt[i]=" ";
	_Context->hint_cptt[0]=en__cptt;
	_Context->hint_cptt[1]=fr__cptt;
	_Context->hint_cptt[2]=it__cptt;
	_Context->hint_cptt[3]=es__cptt;
	_Context->hint_cptt[4]=de__cptt;
	_Context->hint_cptt[5]=nl__cptt;
	_Context->hint_cptt[6]=pt__cptt;
	_Context->hint_cptt[7]=xx__cptt;
	for (i=0; i < 8; i++)_Context->msg_cprt[i]=" ";
	_Context->hint_cprt[0]=en__cprt;
	_Context->hint_cprt[1]=fr__cprt;
	_Context->hint_cprt[2]=it__cprt;
	_Context->hint_cprt[3]=es__cprt;
	_Context->hint_cprt[4]=de__cprt;
	_Context->hint_cprt[5]=nl__cprt;
	_Context->hint_cprt[6]=pt__cprt;
	_Context->hint_cprt[7]=xx__cprt;
	for (i=0; i < 8; i++)_Context->msg_cpbt[i]=" ";
	_Context->hint_cpbt[0]=en__cpbt;
	_Context->hint_cpbt[1]=fr__cpbt;
	_Context->hint_cpbt[2]=it__cpbt;
	_Context->hint_cpbt[3]=es__cpbt;
	_Context->hint_cpbt[4]=de__cpbt;
	_Context->hint_cpbt[5]=nl__cpbt;
	_Context->hint_cpbt[6]=pt__cpbt;
	_Context->hint_cpbt[7]=xx__cpbt;
	for (i=0; i < 8; i++)_Context->msg_MarginPage[i]=" ";
	_Context->msg_MarginPage[0]=en_MarginPage;
	_Context->msg_MarginPage[1]=fr_MarginPage;
	_Context->msg_MarginPage[2]=it_MarginPage;
	_Context->msg_MarginPage[3]=es_MarginPage;
	_Context->msg_MarginPage[4]=de_MarginPage;
	_Context->msg_MarginPage[5]=nl_MarginPage;
	_Context->msg_MarginPage[6]=pt_MarginPage;
	_Context->msg_MarginPage[7]=xx_MarginPage;
	_Context->hint_MarginPage[0]=en__MarginPage;
	_Context->hint_MarginPage[1]=fr__MarginPage;
	_Context->hint_MarginPage[2]=it__MarginPage;
	_Context->hint_MarginPage[3]=es__MarginPage;
	_Context->hint_MarginPage[4]=de__MarginPage;
	_Context->hint_MarginPage[5]=nl__MarginPage;
	_Context->hint_MarginPage[6]=pt__MarginPage;
	_Context->hint_MarginPage[7]=xx__MarginPage;
	_Context->focus_pages[5]=44;
	for (i=0; i < 8; i++)_Context->msg_Auto3651[i]=" ";
	_Context->msg_Auto3651[0]=en_Auto3651;
	_Context->msg_Auto3651[1]=fr_Auto3651;
	_Context->msg_Auto3651[2]=it_Auto3651;
	_Context->msg_Auto3651[3]=es_Auto3651;
	_Context->msg_Auto3651[4]=de_Auto3651;
	_Context->msg_Auto3651[5]=nl_Auto3651;
	_Context->msg_Auto3651[6]=pt_Auto3651;
	_Context->msg_Auto3651[7]=xx_Auto3651;
	_Context->hint_Auto3651[0]=en__Auto3651;
	for (i=0; i < 8; i++)_Context->msg_Auto3652[i]=" ";
	_Context->msg_Auto3652[0]=en_Auto3652;
	_Context->msg_Auto3652[1]=fr_Auto3652;
	_Context->msg_Auto3652[2]=it_Auto3652;
	_Context->msg_Auto3652[3]=es_Auto3652;
	_Context->msg_Auto3652[4]=de_Auto3652;
	_Context->msg_Auto3652[5]=nl_Auto3652;
	_Context->msg_Auto3652[6]=pt_Auto3652;
	_Context->msg_Auto3652[7]=xx_Auto3652;
	_Context->hint_Auto3652[0]=en__Auto3652;
	for (i=0; i < 8; i++)_Context->msg_Auto3653[i]=" ";
	_Context->msg_Auto3653[0]=en_Auto3653;
	_Context->msg_Auto3653[1]=fr_Auto3653;
	_Context->msg_Auto3653[2]=it_Auto3653;
	_Context->msg_Auto3653[3]=es_Auto3653;
	_Context->msg_Auto3653[4]=de_Auto3653;
	_Context->msg_Auto3653[5]=nl_Auto3653;
	_Context->msg_Auto3653[6]=pt_Auto3653;
	_Context->msg_Auto3653[7]=xx_Auto3653;
	_Context->hint_Auto3653[0]=en__Auto3653;
	_Context->hint_Auto3654[0]=en__Auto3654;
	_Context->hint_Auto3655[0]=en__Auto3655;
	for (i=0; i < 8; i++)_Context->msg_Auto3656[i]=" ";
	_Context->msg_Auto3656[0]=en_Auto3656;
	_Context->msg_Auto3656[1]=fr_Auto3656;
	_Context->msg_Auto3656[2]=it_Auto3656;
	_Context->msg_Auto3656[3]=es_Auto3656;
	_Context->msg_Auto3656[4]=de_Auto3656;
	_Context->msg_Auto3656[5]=nl_Auto3656;
	_Context->msg_Auto3656[6]=pt_Auto3656;
	_Context->msg_Auto3656[7]=xx_Auto3656;
	_Context->hint_Auto3656[0]=en__Auto3656;
	_Context->hint_Auto3656[1]=fr__Auto3656;
	_Context->hint_Auto3656[2]=it__Auto3656;
	_Context->hint_Auto3656[3]=es__Auto3656;
	_Context->hint_Auto3656[4]=de__Auto3656;
	_Context->hint_Auto3656[5]=nl__Auto3656;
	_Context->hint_Auto3656[6]=pt__Auto3656;
	_Context->hint_Auto3656[7]=xx__Auto3656;
	for (i=0; i < 8; i++)_Context->msg_Auto3657[i]=" ";
	_Context->msg_Auto3657[0]=en_Auto3657;
	_Context->msg_Auto3657[1]=fr_Auto3657;
	_Context->msg_Auto3657[2]=it_Auto3657;
	_Context->msg_Auto3657[3]=es_Auto3657;
	_Context->msg_Auto3657[4]=de_Auto3657;
	_Context->msg_Auto3657[5]=nl_Auto3657;
	_Context->msg_Auto3657[6]=pt_Auto3657;
	_Context->msg_Auto3657[7]=xx_Auto3657;
	_Context->hint_Auto3657[0]=en__Auto3657;
	_Context->hint_Auto3657[1]=fr__Auto3657;
	_Context->hint_Auto3657[2]=it__Auto3657;
	_Context->hint_Auto3657[3]=es__Auto3657;
	_Context->hint_Auto3657[4]=de__Auto3657;
	_Context->hint_Auto3657[5]=nl__Auto3657;
	_Context->hint_Auto3657[6]=pt__Auto3657;
	_Context->hint_Auto3657[7]=xx__Auto3657;
	for (i=0; i < 8; i++)_Context->msg_Auto3658[i]=" ";
	_Context->msg_Auto3658[0]=en_Auto3658;
	_Context->msg_Auto3658[1]=fr_Auto3658;
	_Context->msg_Auto3658[2]=it_Auto3658;
	_Context->msg_Auto3658[3]=es_Auto3658;
	_Context->msg_Auto3658[4]=de_Auto3658;
	_Context->msg_Auto3658[5]=nl_Auto3658;
	_Context->msg_Auto3658[6]=pt_Auto3658;
	_Context->msg_Auto3658[7]=xx_Auto3658;
	_Context->hint_Auto3658[0]=en__Auto3658;
	_Context->hint_Auto3658[1]=fr__Auto3658;
	_Context->hint_Auto3658[2]=it__Auto3658;
	_Context->hint_Auto3658[3]=es__Auto3658;
	_Context->hint_Auto3658[4]=de__Auto3658;
	_Context->hint_Auto3658[5]=nl__Auto3658;
	_Context->hint_Auto3658[6]=pt__Auto3658;
	_Context->hint_Auto3658[7]=xx__Auto3658;
	for (i=0; i < 8; i++)_Context->msg_Auto3659[i]=" ";
	_Context->msg_Auto3659[0]=en_Auto3659;
	_Context->msg_Auto3659[1]=fr_Auto3659;
	_Context->msg_Auto3659[2]=it_Auto3659;
	_Context->msg_Auto3659[3]=es_Auto3659;
	_Context->msg_Auto3659[4]=de_Auto3659;
	_Context->msg_Auto3659[5]=nl_Auto3659;
	_Context->msg_Auto3659[6]=pt_Auto3659;
	_Context->msg_Auto3659[7]=xx_Auto3659;
	_Context->hint_Auto3659[0]=en__Auto3659;
	_Context->hint_Auto3659[1]=fr__Auto3659;
	_Context->hint_Auto3659[2]=it__Auto3659;
	_Context->hint_Auto3659[3]=es__Auto3659;
	_Context->hint_Auto3659[4]=de__Auto3659;
	_Context->hint_Auto3659[5]=nl__Auto3659;
	_Context->hint_Auto3659[6]=pt__Auto3659;
	_Context->hint_Auto3659[7]=xx__Auto3659;
	for (i=0; i < 8; i++)_Context->msg_Auto3660[i]=" ";
	_Context->msg_Auto3660[0]=en_Auto3660;
	_Context->msg_Auto3660[1]=fr_Auto3660;
	_Context->msg_Auto3660[2]=it_Auto3660;
	_Context->msg_Auto3660[3]=es_Auto3660;
	_Context->msg_Auto3660[4]=de_Auto3660;
	_Context->msg_Auto3660[5]=nl_Auto3660;
	_Context->msg_Auto3660[6]=pt_Auto3660;
	_Context->msg_Auto3660[7]=xx_Auto3660;
	_Context->hint_Auto3660[0]=en__Auto3660;
	_Context->hint_Auto3660[1]=fr__Auto3660;
	_Context->hint_Auto3660[2]=it__Auto3660;
	_Context->hint_Auto3660[3]=es__Auto3660;
	_Context->hint_Auto3660[4]=de__Auto3660;
	_Context->hint_Auto3660[5]=nl__Auto3660;
	_Context->hint_Auto3660[6]=pt__Auto3660;
	_Context->hint_Auto3660[7]=xx__Auto3660;
	_Context->hint_mlv[0]=en__mlv;
	for (i=0; i < 8; i++)_Context->msg_mlt[i]=" ";
	_Context->hint_mlt[0]=en__mlt;
	_Context->hint_mlt[1]=fr__mlt;
	_Context->hint_mlt[2]=it__mlt;
	_Context->hint_mlt[3]=es__mlt;
	_Context->hint_mlt[4]=de__mlt;
	_Context->hint_mlt[5]=nl__mlt;
	_Context->hint_mlt[6]=pt__mlt;
	_Context->hint_mlt[7]=xx__mlt;
	_Context->hint_mgv[0]=en__mgv;
	for (i=0; i < 8; i++)_Context->msg_mgt[i]=" ";
	_Context->hint_mgt[0]=en__mgt;
	_Context->hint_mgt[1]=fr__mgt;
	_Context->hint_mgt[2]=it__mgt;
	_Context->hint_mgt[3]=es__mgt;
	_Context->hint_mgt[4]=de__mgt;
	_Context->hint_mgt[5]=nl__mgt;
	_Context->hint_mgt[6]=pt__mgt;
	_Context->hint_mgt[7]=xx__mgt;
	_Context->hint_mtv[0]=en__mtv;
	for (i=0; i < 8; i++)_Context->msg_mtt[i]=" ";
	_Context->hint_mtt[0]=en__mtt;
	_Context->hint_mtt[1]=fr__mtt;
	_Context->hint_mtt[2]=it__mtt;
	_Context->hint_mtt[3]=es__mtt;
	_Context->hint_mtt[4]=de__mtt;
	_Context->hint_mtt[5]=nl__mtt;
	_Context->hint_mtt[6]=pt__mtt;
	_Context->hint_mtt[7]=xx__mtt;
	_Context->hint_mrv[0]=en__mrv;
	for (i=0; i < 8; i++)_Context->msg_mrt[i]=" ";
	_Context->hint_mrt[0]=en__mrt;
	_Context->hint_mrt[1]=fr__mrt;
	_Context->hint_mrt[2]=it__mrt;
	_Context->hint_mrt[3]=es__mrt;
	_Context->hint_mrt[4]=de__mrt;
	_Context->hint_mrt[5]=nl__mrt;
	_Context->hint_mrt[6]=pt__mrt;
	_Context->hint_mrt[7]=xx__mrt;
	_Context->hint_mbv[0]=en__mbv;
	for (i=0; i < 8; i++)_Context->msg_mbt[i]=" ";
	_Context->hint_mbt[0]=en__mbt;
	_Context->hint_mbt[1]=fr__mbt;
	_Context->hint_mbt[2]=it__mbt;
	_Context->hint_mbt[3]=es__mbt;
	_Context->hint_mbt[4]=de__mbt;
	_Context->hint_mbt[5]=nl__mbt;
	_Context->hint_mbt[6]=pt__mbt;
	_Context->hint_mbt[7]=xx__mbt;
	for (i=0; i < 8; i++)_Context->msg_BorderPage[i]=" ";
	_Context->msg_BorderPage[0]=en_BorderPage;
	_Context->msg_BorderPage[1]=fr_BorderPage;
	_Context->msg_BorderPage[2]=it_BorderPage;
	_Context->msg_BorderPage[3]=es_BorderPage;
	_Context->msg_BorderPage[4]=de_BorderPage;
	_Context->msg_BorderPage[5]=nl_BorderPage;
	_Context->msg_BorderPage[6]=pt_BorderPage;
	_Context->msg_BorderPage[7]=xx_BorderPage;
	_Context->hint_BorderPage[0]=en__BorderPage;
	_Context->hint_BorderPage[1]=fr__BorderPage;
	_Context->hint_BorderPage[2]=it__BorderPage;
	_Context->hint_BorderPage[3]=es__BorderPage;
	_Context->hint_BorderPage[4]=de__BorderPage;
	_Context->hint_BorderPage[5]=nl__BorderPage;
	_Context->hint_BorderPage[6]=pt__BorderPage;
	_Context->hint_BorderPage[7]=xx__BorderPage;
	_Context->focus_pages[6]=55;
	for (i=0; i < 8; i++)_Context->msg_Auto3661[i]=" ";
	_Context->msg_Auto3661[0]=en_Auto3661;
	_Context->msg_Auto3661[1]=fr_Auto3661;
	_Context->msg_Auto3661[2]=it_Auto3661;
	_Context->msg_Auto3661[3]=es_Auto3661;
	_Context->msg_Auto3661[4]=de_Auto3661;
	_Context->msg_Auto3661[5]=nl_Auto3661;
	_Context->msg_Auto3661[6]=pt_Auto3661;
	_Context->msg_Auto3661[7]=xx_Auto3661;
	_Context->hint_Auto3661[0]=en__Auto3661;
	_Context->hint_Auto3661[1]=fr__Auto3661;
	_Context->hint_Auto3661[2]=it__Auto3661;
	_Context->hint_Auto3661[3]=es__Auto3661;
	_Context->hint_Auto3661[4]=de__Auto3661;
	_Context->hint_Auto3661[5]=nl__Auto3661;
	_Context->hint_Auto3661[6]=pt__Auto3661;
	_Context->hint_Auto3661[7]=xx__Auto3661;
	for (i=0; i < 8; i++)_Context->msg_Auto3662[i]=" ";
	_Context->msg_Auto3662[0]=en_Auto3662;
	_Context->msg_Auto3662[1]=fr_Auto3662;
	_Context->msg_Auto3662[2]=it_Auto3662;
	_Context->msg_Auto3662[3]=es_Auto3662;
	_Context->msg_Auto3662[4]=de_Auto3662;
	_Context->msg_Auto3662[5]=nl_Auto3662;
	_Context->msg_Auto3662[6]=pt_Auto3662;
	_Context->msg_Auto3662[7]=xx_Auto3662;
	_Context->hint_Auto3662[0]=en__Auto3662;
	for (i=0; i < 8; i++)_Context->msg_Auto3663[i]=" ";
	_Context->msg_Auto3663[0]=en_Auto3663;
	_Context->msg_Auto3663[1]=fr_Auto3663;
	_Context->msg_Auto3663[2]=it_Auto3663;
	_Context->msg_Auto3663[3]=es_Auto3663;
	_Context->msg_Auto3663[4]=de_Auto3663;
	_Context->msg_Auto3663[5]=nl_Auto3663;
	_Context->msg_Auto3663[6]=pt_Auto3663;
	_Context->msg_Auto3663[7]=xx_Auto3663;
	_Context->hint_Auto3663[0]=en__Auto3663;
	for (i=0; i < 8; i++)_Context->msg_Auto3664[i]=" ";
	_Context->msg_Auto3664[0]=en_Auto3664;
	_Context->msg_Auto3664[1]=fr_Auto3664;
	_Context->msg_Auto3664[2]=it_Auto3664;
	_Context->msg_Auto3664[3]=es_Auto3664;
	_Context->msg_Auto3664[4]=de_Auto3664;
	_Context->msg_Auto3664[5]=nl_Auto3664;
	_Context->msg_Auto3664[6]=pt_Auto3664;
	_Context->msg_Auto3664[7]=xx_Auto3664;
	_Context->hint_Auto3664[0]=en__Auto3664;
	for (i=0; i < 8; i++)_Context->msg_Auto3665[i]=" ";
	_Context->msg_Auto3665[0]=en_Auto3665;
	_Context->msg_Auto3665[1]=fr_Auto3665;
	_Context->msg_Auto3665[2]=it_Auto3665;
	_Context->msg_Auto3665[3]=es_Auto3665;
	_Context->msg_Auto3665[4]=de_Auto3665;
	_Context->msg_Auto3665[5]=nl_Auto3665;
	_Context->msg_Auto3665[6]=pt_Auto3665;
	_Context->msg_Auto3665[7]=xx_Auto3665;
	_Context->hint_Auto3665[0]=en__Auto3665;
	for (i=0; i < 8; i++)_Context->msg_Auto3666[i]=" ";
	_Context->msg_Auto3666[0]=en_Auto3666;
	_Context->msg_Auto3666[1]=fr_Auto3666;
	_Context->msg_Auto3666[2]=it_Auto3666;
	_Context->msg_Auto3666[3]=es_Auto3666;
	_Context->msg_Auto3666[4]=de_Auto3666;
	_Context->msg_Auto3666[5]=nl_Auto3666;
	_Context->msg_Auto3666[6]=pt_Auto3666;
	_Context->msg_Auto3666[7]=xx_Auto3666;
	_Context->hint_Auto3666[0]=en__Auto3666;
	_Context->hint_Auto3666[1]=fr__Auto3666;
	_Context->hint_Auto3666[2]=it__Auto3666;
	_Context->hint_Auto3666[3]=es__Auto3666;
	_Context->hint_Auto3666[4]=de__Auto3666;
	_Context->hint_Auto3666[5]=nl__Auto3666;
	_Context->hint_Auto3666[6]=pt__Auto3666;
	_Context->hint_Auto3666[7]=xx__Auto3666;
	for (i=0; i < 8; i++)_Context->msg_bdct[i]=" ";
	_Context->hint_bdct[0]=en__bdct;
	_Context->hint_bdcv[0]=en__bdcv;
	for (i=0; i < 8; i++)_Context->msg_bdat[i]=" ";
	_Context->hint_bdat[0]=en__bdat;
	_Context->hint_Auto3667[0]=en__Auto3667;
	_Context->hint_Auto3668[0]=en__Auto3668;
	for (i=0; i < 8; i++)_Context->msg_Auto3669[i]=" ";
	_Context->msg_Auto3669[0]=en_Auto3669;
	_Context->msg_Auto3669[1]=fr_Auto3669;
	_Context->msg_Auto3669[2]=it_Auto3669;
	_Context->msg_Auto3669[3]=es_Auto3669;
	_Context->msg_Auto3669[4]=de_Auto3669;
	_Context->msg_Auto3669[5]=nl_Auto3669;
	_Context->msg_Auto3669[6]=pt_Auto3669;
	_Context->msg_Auto3669[7]=xx_Auto3669;
	_Context->hint_Auto3669[0]=en__Auto3669;
	_Context->hint_Auto3669[1]=fr__Auto3669;
	_Context->hint_Auto3669[2]=it__Auto3669;
	_Context->hint_Auto3669[3]=es__Auto3669;
	_Context->hint_Auto3669[4]=de__Auto3669;
	_Context->hint_Auto3669[5]=nl__Auto3669;
	_Context->hint_Auto3669[6]=pt__Auto3669;
	_Context->hint_Auto3669[7]=xx__Auto3669;
	for (i=0; i < 8; i++)_Context->msg_Auto3670[i]=" ";
	_Context->msg_Auto3670[0]=en_Auto3670;
	_Context->msg_Auto3670[1]=fr_Auto3670;
	_Context->msg_Auto3670[2]=it_Auto3670;
	_Context->msg_Auto3670[3]=es_Auto3670;
	_Context->msg_Auto3670[4]=de_Auto3670;
	_Context->msg_Auto3670[5]=nl_Auto3670;
	_Context->msg_Auto3670[6]=pt_Auto3670;
	_Context->msg_Auto3670[7]=xx_Auto3670;
	_Context->hint_Auto3670[0]=en__Auto3670;
	for (i=0; i < 8; i++)_Context->msg_Auto3671[i]=" ";
	_Context->msg_Auto3671[0]=en_Auto3671;
	_Context->msg_Auto3671[1]=fr_Auto3671;
	_Context->msg_Auto3671[2]=it_Auto3671;
	_Context->msg_Auto3671[3]=es_Auto3671;
	_Context->msg_Auto3671[4]=de_Auto3671;
	_Context->msg_Auto3671[5]=nl_Auto3671;
	_Context->msg_Auto3671[6]=pt_Auto3671;
	_Context->msg_Auto3671[7]=xx_Auto3671;
	_Context->hint_Auto3671[0]=en__Auto3671;
	for (i=0; i < 8; i++)_Context->msg_Auto3672[i]=" ";
	_Context->msg_Auto3672[0]=en_Auto3672;
	_Context->msg_Auto3672[1]=fr_Auto3672;
	_Context->msg_Auto3672[2]=it_Auto3672;
	_Context->msg_Auto3672[3]=es_Auto3672;
	_Context->msg_Auto3672[4]=de_Auto3672;
	_Context->msg_Auto3672[5]=nl_Auto3672;
	_Context->msg_Auto3672[6]=pt_Auto3672;
	_Context->msg_Auto3672[7]=xx_Auto3672;
	_Context->hint_Auto3672[0]=en__Auto3672;
	_Context->hint_blu[0]=en__blu;
	for (i=0; i < 8; i++)_Context->msg_Auto3673[i]=" ";
	_Context->msg_Auto3673[0]=en_Auto3673;
	_Context->msg_Auto3673[1]=fr_Auto3673;
	_Context->msg_Auto3673[2]=it_Auto3673;
	_Context->msg_Auto3673[3]=es_Auto3673;
	_Context->msg_Auto3673[4]=de_Auto3673;
	_Context->msg_Auto3673[5]=nl_Auto3673;
	_Context->msg_Auto3673[6]=pt_Auto3673;
	_Context->msg_Auto3673[7]=xx_Auto3673;
	_Context->hint_Auto3673[0]=en__Auto3673;
	for (i=0; i < 8; i++)_Context->msg_Auto3674[i]=" ";
	_Context->msg_Auto3674[0]=en_Auto3674;
	_Context->msg_Auto3674[1]=fr_Auto3674;
	_Context->msg_Auto3674[2]=it_Auto3674;
	_Context->msg_Auto3674[3]=es_Auto3674;
	_Context->msg_Auto3674[4]=de_Auto3674;
	_Context->msg_Auto3674[5]=nl_Auto3674;
	_Context->msg_Auto3674[6]=pt_Auto3674;
	_Context->msg_Auto3674[7]=xx_Auto3674;
	_Context->hint_Auto3674[0]=en__Auto3674;
	_Context->hint_btu[0]=en__btu;
	for (i=0; i < 8; i++)_Context->msg_Auto3675[i]=" ";
	_Context->msg_Auto3675[0]=en_Auto3675;
	_Context->msg_Auto3675[1]=fr_Auto3675;
	_Context->msg_Auto3675[2]=it_Auto3675;
	_Context->msg_Auto3675[3]=es_Auto3675;
	_Context->msg_Auto3675[4]=de_Auto3675;
	_Context->msg_Auto3675[5]=nl_Auto3675;
	_Context->msg_Auto3675[6]=pt_Auto3675;
	_Context->msg_Auto3675[7]=xx_Auto3675;
	_Context->hint_Auto3675[0]=en__Auto3675;
	_Context->hint_bbu[0]=en__bbu;
	_Context->hint_bru[0]=en__bru;
	for (i=0; i < 8; i++)_Context->msg_Auto3676[i]=" ";
	_Context->msg_Auto3676[0]=en_Auto3676;
	_Context->msg_Auto3676[1]=fr_Auto3676;
	_Context->msg_Auto3676[2]=it_Auto3676;
	_Context->msg_Auto3676[3]=es_Auto3676;
	_Context->msg_Auto3676[4]=de_Auto3676;
	_Context->msg_Auto3676[5]=nl_Auto3676;
	_Context->msg_Auto3676[6]=pt_Auto3676;
	_Context->msg_Auto3676[7]=xx_Auto3676;
	_Context->hint_Auto3676[0]=en__Auto3676;
	for (i=0; i < 8; i++)_Context->msg_Auto3677[i]=" ";
	_Context->msg_Auto3677[0]=en_Auto3677;
	_Context->msg_Auto3677[1]=fr_Auto3677;
	_Context->msg_Auto3677[2]=it_Auto3677;
	_Context->msg_Auto3677[3]=es_Auto3677;
	_Context->msg_Auto3677[4]=de_Auto3677;
	_Context->msg_Auto3677[5]=nl_Auto3677;
	_Context->msg_Auto3677[6]=pt_Auto3677;
	_Context->msg_Auto3677[7]=xx_Auto3677;
	_Context->hint_Auto3677[0]=en__Auto3677;
	for (i=0; i < 8; i++)_Context->msg_Auto3678[i]=" ";
	_Context->msg_Auto3678[0]=en_Auto3678;
	_Context->msg_Auto3678[1]=fr_Auto3678;
	_Context->msg_Auto3678[2]=it_Auto3678;
	_Context->msg_Auto3678[3]=es_Auto3678;
	_Context->msg_Auto3678[4]=de_Auto3678;
	_Context->msg_Auto3678[5]=nl_Auto3678;
	_Context->msg_Auto3678[6]=pt_Auto3678;
	_Context->msg_Auto3678[7]=xx_Auto3678;
	_Context->hint_Auto3678[0]=en__Auto3678;
	_Context->hint_ctlu[0]=en__ctlu;
	_Context->hint_ctru[0]=en__ctru;
	_Context->hint_cblu[0]=en__cblu;
	_Context->hint_cbru[0]=en__cbru;
	_Context->hint_blv[0]=en__blv;
	for (i=0; i < 8; i++)_Context->msg_blt[i]=" ";
	_Context->hint_blt[0]=en__blt;
	_Context->hint_blt[1]=fr__blt;
	_Context->hint_blt[2]=it__blt;
	_Context->hint_blt[3]=es__blt;
	_Context->hint_blt[4]=de__blt;
	_Context->hint_blt[5]=nl__blt;
	_Context->hint_blt[6]=pt__blt;
	_Context->hint_blt[7]=xx__blt;
	for (i=0; i < 8; i++)_Context->msg_bdsv[i]=" ";
	_Context->hint_bdsv[0]=en__bdsv;
	for (i=0; i < 8; i++)_Context->msg_Auto3679[i]=" ";
	_Context->msg_Auto3679[0]=en_Auto3679;
	_Context->msg_Auto3679[1]=fr_Auto3679;
	_Context->msg_Auto3679[2]=it_Auto3679;
	_Context->msg_Auto3679[3]=es_Auto3679;
	_Context->msg_Auto3679[4]=de_Auto3679;
	_Context->msg_Auto3679[5]=nl_Auto3679;
	_Context->msg_Auto3679[6]=pt_Auto3679;
	_Context->msg_Auto3679[7]=xx_Auto3679;
	_Context->hint_Auto3679[0]=en__Auto3679;
	_Context->hint_Auto3679[1]=fr__Auto3679;
	_Context->hint_Auto3679[2]=it__Auto3679;
	_Context->hint_Auto3679[3]=es__Auto3679;
	_Context->hint_Auto3679[4]=de__Auto3679;
	_Context->hint_Auto3679[5]=nl__Auto3679;
	_Context->hint_Auto3679[6]=pt__Auto3679;
	_Context->hint_Auto3679[7]=xx__Auto3679;
	_Context->hint_btv[0]=en__btv;
	for (i=0; i < 8; i++)_Context->msg_btt[i]=" ";
	_Context->hint_btt[0]=en__btt;
	_Context->hint_btt[1]=fr__btt;
	_Context->hint_btt[2]=it__btt;
	_Context->hint_btt[3]=es__btt;
	_Context->hint_btt[4]=de__btt;
	_Context->hint_btt[5]=nl__btt;
	_Context->hint_btt[6]=pt__btt;
	_Context->hint_btt[7]=xx__btt;
	for (i=0; i < 8; i++)_Context->msg_Auto3680[i]=" ";
	_Context->msg_Auto3680[0]=en_Auto3680;
	_Context->msg_Auto3680[1]=fr_Auto3680;
	_Context->msg_Auto3680[2]=it_Auto3680;
	_Context->msg_Auto3680[3]=es_Auto3680;
	_Context->msg_Auto3680[4]=de_Auto3680;
	_Context->msg_Auto3680[5]=nl_Auto3680;
	_Context->msg_Auto3680[6]=pt_Auto3680;
	_Context->msg_Auto3680[7]=xx_Auto3680;
	_Context->hint_Auto3680[0]=en__Auto3680;
	_Context->hint_Auto3680[1]=fr__Auto3680;
	_Context->hint_Auto3680[2]=it__Auto3680;
	_Context->hint_Auto3680[3]=es__Auto3680;
	_Context->hint_Auto3680[4]=de__Auto3680;
	_Context->hint_Auto3680[5]=nl__Auto3680;
	_Context->hint_Auto3680[6]=pt__Auto3680;
	_Context->hint_Auto3680[7]=xx__Auto3680;
	_Context->hint_brv[0]=en__brv;
	_Context->hint_bwv[0]=en__bwv;
	for (i=0; i < 8; i++)_Context->msg_brt[i]=" ";
	_Context->hint_brt[0]=en__brt;
	_Context->hint_brt[1]=fr__brt;
	_Context->hint_brt[2]=it__brt;
	_Context->hint_brt[3]=es__brt;
	_Context->hint_brt[4]=de__brt;
	_Context->hint_brt[5]=nl__brt;
	_Context->hint_brt[6]=pt__brt;
	_Context->hint_brt[7]=xx__brt;
	for (i=0; i < 8; i++)_Context->msg_bwt[i]=" ";
	_Context->hint_bwt[0]=en__bwt;
	_Context->hint_bwt[1]=fr__bwt;
	_Context->hint_bwt[2]=it__bwt;
	_Context->hint_bwt[3]=es__bwt;
	_Context->hint_bwt[4]=de__bwt;
	_Context->hint_bwt[5]=nl__bwt;
	_Context->hint_bwt[6]=pt__bwt;
	_Context->hint_bwt[7]=xx__bwt;
	for (i=0; i < 8; i++)_Context->msg_Auto3681[i]=" ";
	_Context->msg_Auto3681[0]=en_Auto3681;
	_Context->msg_Auto3681[1]=fr_Auto3681;
	_Context->msg_Auto3681[2]=it_Auto3681;
	_Context->msg_Auto3681[3]=es_Auto3681;
	_Context->msg_Auto3681[4]=de_Auto3681;
	_Context->msg_Auto3681[5]=nl_Auto3681;
	_Context->msg_Auto3681[6]=pt_Auto3681;
	_Context->msg_Auto3681[7]=xx_Auto3681;
	_Context->hint_Auto3681[0]=en__Auto3681;
	_Context->hint_Auto3681[1]=fr__Auto3681;
	_Context->hint_Auto3681[2]=it__Auto3681;
	_Context->hint_Auto3681[3]=es__Auto3681;
	_Context->hint_Auto3681[4]=de__Auto3681;
	_Context->hint_Auto3681[5]=nl__Auto3681;
	_Context->hint_Auto3681[6]=pt__Auto3681;
	_Context->hint_Auto3681[7]=xx__Auto3681;
	_Context->hint_bbv[0]=en__bbv;
	for (i=0; i < 8; i++)_Context->msg_bbt[i]=" ";
	_Context->hint_bbt[0]=en__bbt;
	_Context->hint_bbt[1]=fr__bbt;
	_Context->hint_bbt[2]=it__bbt;
	_Context->hint_bbt[3]=es__bbt;
	_Context->hint_bbt[4]=de__bbt;
	_Context->hint_bbt[5]=nl__bbt;
	_Context->hint_bbt[6]=pt__bbt;
	_Context->hint_bbt[7]=xx__bbt;
	for (i=0; i < 8; i++)_Context->msg_PaddingPage[i]=" ";
	_Context->msg_PaddingPage[0]=en_PaddingPage;
	_Context->msg_PaddingPage[1]=fr_PaddingPage;
	_Context->msg_PaddingPage[2]=it_PaddingPage;
	_Context->msg_PaddingPage[3]=es_PaddingPage;
	_Context->msg_PaddingPage[4]=de_PaddingPage;
	_Context->msg_PaddingPage[5]=nl_PaddingPage;
	_Context->msg_PaddingPage[6]=pt_PaddingPage;
	_Context->msg_PaddingPage[7]=xx_PaddingPage;
	_Context->hint_PaddingPage[0]=en__PaddingPage;
	_Context->focus_pages[7]=78;
	for (i=0; i < 8; i++)_Context->msg_Auto3682[i]=" ";
	_Context->msg_Auto3682[0]=en_Auto3682;
	_Context->msg_Auto3682[1]=fr_Auto3682;
	_Context->msg_Auto3682[2]=it_Auto3682;
	_Context->msg_Auto3682[3]=es_Auto3682;
	_Context->msg_Auto3682[4]=de_Auto3682;
	_Context->msg_Auto3682[5]=nl_Auto3682;
	_Context->msg_Auto3682[6]=pt_Auto3682;
	_Context->msg_Auto3682[7]=xx_Auto3682;
	_Context->hint_Auto3682[0]=en__Auto3682;
	_Context->hint_Auto3682[1]=fr__Auto3682;
	_Context->hint_Auto3682[2]=it__Auto3682;
	_Context->hint_Auto3682[3]=es__Auto3682;
	_Context->hint_Auto3682[4]=de__Auto3682;
	_Context->hint_Auto3682[5]=nl__Auto3682;
	_Context->hint_Auto3682[6]=pt__Auto3682;
	_Context->hint_Auto3682[7]=xx__Auto3682;
	for (i=0; i < 8; i++)_Context->msg_Auto3683[i]=" ";
	_Context->msg_Auto3683[0]=en_Auto3683;
	_Context->msg_Auto3683[1]=fr_Auto3683;
	_Context->msg_Auto3683[2]=it_Auto3683;
	_Context->msg_Auto3683[3]=es_Auto3683;
	_Context->msg_Auto3683[4]=de_Auto3683;
	_Context->msg_Auto3683[5]=nl_Auto3683;
	_Context->msg_Auto3683[6]=pt_Auto3683;
	_Context->msg_Auto3683[7]=xx_Auto3683;
	_Context->hint_Auto3683[0]=en__Auto3683;
	_Context->hint_Auto3683[1]=fr__Auto3683;
	_Context->hint_Auto3683[2]=it__Auto3683;
	_Context->hint_Auto3683[3]=es__Auto3683;
	_Context->hint_Auto3683[4]=de__Auto3683;
	_Context->hint_Auto3683[5]=nl__Auto3683;
	_Context->hint_Auto3683[6]=pt__Auto3683;
	_Context->hint_Auto3683[7]=xx__Auto3683;
	for (i=0; i < 8; i++)_Context->msg_Auto3684[i]=" ";
	_Context->msg_Auto3684[0]=en_Auto3684;
	_Context->msg_Auto3684[1]=fr_Auto3684;
	_Context->msg_Auto3684[2]=it_Auto3684;
	_Context->msg_Auto3684[3]=es_Auto3684;
	_Context->msg_Auto3684[4]=de_Auto3684;
	_Context->msg_Auto3684[5]=nl_Auto3684;
	_Context->msg_Auto3684[6]=pt_Auto3684;
	_Context->msg_Auto3684[7]=xx_Auto3684;
	_Context->hint_Auto3684[0]=en__Auto3684;
	_Context->hint_Auto3684[1]=fr__Auto3684;
	_Context->hint_Auto3684[2]=it__Auto3684;
	_Context->hint_Auto3684[3]=es__Auto3684;
	_Context->hint_Auto3684[4]=de__Auto3684;
	_Context->hint_Auto3684[5]=nl__Auto3684;
	_Context->hint_Auto3684[6]=pt__Auto3684;
	_Context->hint_Auto3684[7]=xx__Auto3684;
	for (i=0; i < 8; i++)_Context->msg_Auto3685[i]=" ";
	_Context->msg_Auto3685[0]=en_Auto3685;
	_Context->msg_Auto3685[1]=fr_Auto3685;
	_Context->msg_Auto3685[2]=it_Auto3685;
	_Context->msg_Auto3685[3]=es_Auto3685;
	_Context->msg_Auto3685[4]=de_Auto3685;
	_Context->msg_Auto3685[5]=nl_Auto3685;
	_Context->msg_Auto3685[6]=pt_Auto3685;
	_Context->msg_Auto3685[7]=xx_Auto3685;
	_Context->hint_Auto3685[0]=en__Auto3685;
	_Context->hint_Auto3685[1]=fr__Auto3685;
	_Context->hint_Auto3685[2]=it__Auto3685;
	_Context->hint_Auto3685[3]=es__Auto3685;
	_Context->hint_Auto3685[4]=de__Auto3685;
	_Context->hint_Auto3685[5]=nl__Auto3685;
	_Context->hint_Auto3685[6]=pt__Auto3685;
	_Context->hint_Auto3685[7]=xx__Auto3685;
	for (i=0; i < 8; i++)_Context->msg_Auto3686[i]=" ";
	_Context->msg_Auto3686[0]=en_Auto3686;
	_Context->msg_Auto3686[1]=fr_Auto3686;
	_Context->msg_Auto3686[2]=it_Auto3686;
	_Context->msg_Auto3686[3]=es_Auto3686;
	_Context->msg_Auto3686[4]=de_Auto3686;
	_Context->msg_Auto3686[5]=nl_Auto3686;
	_Context->msg_Auto3686[6]=pt_Auto3686;
	_Context->msg_Auto3686[7]=xx_Auto3686;
	_Context->hint_Auto3686[0]=en__Auto3686;
	_Context->hint_Auto3686[1]=fr__Auto3686;
	_Context->hint_Auto3686[2]=it__Auto3686;
	_Context->hint_Auto3686[3]=es__Auto3686;
	_Context->hint_Auto3686[4]=de__Auto3686;
	_Context->hint_Auto3686[5]=nl__Auto3686;
	_Context->hint_Auto3686[6]=pt__Auto3686;
	_Context->hint_Auto3686[7]=xx__Auto3686;
	_Context->hint_Auto3687[0]=en__Auto3687;
	_Context->hint_Auto3688[0]=en__Auto3688;
	for (i=0; i < 8; i++)_Context->msg_Auto3689[i]=" ";
	_Context->msg_Auto3689[0]=en_Auto3689;
	_Context->msg_Auto3689[1]=fr_Auto3689;
	_Context->msg_Auto3689[2]=it_Auto3689;
	_Context->msg_Auto3689[3]=es_Auto3689;
	_Context->msg_Auto3689[4]=de_Auto3689;
	_Context->msg_Auto3689[5]=nl_Auto3689;
	_Context->msg_Auto3689[6]=pt_Auto3689;
	_Context->msg_Auto3689[7]=xx_Auto3689;
	_Context->hint_Auto3689[0]=en__Auto3689;
	_Context->hint_Auto3689[1]=fr__Auto3689;
	_Context->hint_Auto3689[2]=it__Auto3689;
	_Context->hint_Auto3689[3]=es__Auto3689;
	_Context->hint_Auto3689[4]=de__Auto3689;
	_Context->hint_Auto3689[5]=nl__Auto3689;
	_Context->hint_Auto3689[6]=pt__Auto3689;
	_Context->hint_Auto3689[7]=xx__Auto3689;
	for (i=0; i < 8; i++)_Context->msg_Auto3690[i]=" ";
	_Context->msg_Auto3690[0]=en_Auto3690;
	_Context->msg_Auto3690[1]=fr_Auto3690;
	_Context->msg_Auto3690[2]=it_Auto3690;
	_Context->msg_Auto3690[3]=es_Auto3690;
	_Context->msg_Auto3690[4]=de_Auto3690;
	_Context->msg_Auto3690[5]=nl_Auto3690;
	_Context->msg_Auto3690[6]=pt_Auto3690;
	_Context->msg_Auto3690[7]=xx_Auto3690;
	_Context->hint_Auto3690[0]=en__Auto3690;
	_Context->hint_Auto3690[1]=fr__Auto3690;
	_Context->hint_Auto3690[2]=it__Auto3690;
	_Context->hint_Auto3690[3]=es__Auto3690;
	_Context->hint_Auto3690[4]=de__Auto3690;
	_Context->hint_Auto3690[5]=nl__Auto3690;
	_Context->hint_Auto3690[6]=pt__Auto3690;
	_Context->hint_Auto3690[7]=xx__Auto3690;
	_Context->hint_plv[0]=en__plv;
	for (i=0; i < 8; i++)_Context->msg_plt[i]=" ";
	_Context->hint_plt[0]=en__plt;
	_Context->hint_plt[1]=fr__plt;
	_Context->hint_plt[2]=it__plt;
	_Context->hint_plt[3]=es__plt;
	_Context->hint_plt[4]=de__plt;
	_Context->hint_plt[5]=nl__plt;
	_Context->hint_plt[6]=pt__plt;
	_Context->hint_plt[7]=xx__plt;
	_Context->hint_pgv[0]=en__pgv;
	for (i=0; i < 8; i++)_Context->msg_pgt[i]=" ";
	_Context->hint_pgt[0]=en__pgt;
	_Context->hint_pgt[1]=fr__pgt;
	_Context->hint_pgt[2]=it__pgt;
	_Context->hint_pgt[3]=es__pgt;
	_Context->hint_pgt[4]=de__pgt;
	_Context->hint_pgt[5]=nl__pgt;
	_Context->hint_pgt[6]=pt__pgt;
	_Context->hint_pgt[7]=xx__pgt;
	for (i=0; i < 8; i++)_Context->msg_Auto3691[i]=" ";
	_Context->msg_Auto3691[0]=en_Auto3691;
	_Context->msg_Auto3691[1]=fr_Auto3691;
	_Context->msg_Auto3691[2]=it_Auto3691;
	_Context->msg_Auto3691[3]=es_Auto3691;
	_Context->msg_Auto3691[4]=de_Auto3691;
	_Context->msg_Auto3691[5]=nl_Auto3691;
	_Context->msg_Auto3691[6]=pt_Auto3691;
	_Context->msg_Auto3691[7]=xx_Auto3691;
	_Context->hint_Auto3691[0]=en__Auto3691;
	_Context->hint_Auto3691[1]=fr__Auto3691;
	_Context->hint_Auto3691[2]=it__Auto3691;
	_Context->hint_Auto3691[3]=es__Auto3691;
	_Context->hint_Auto3691[4]=de__Auto3691;
	_Context->hint_Auto3691[5]=nl__Auto3691;
	_Context->hint_Auto3691[6]=pt__Auto3691;
	_Context->hint_Auto3691[7]=xx__Auto3691;
	_Context->hint_ptv[0]=en__ptv;
	for (i=0; i < 8; i++)_Context->msg_ptt[i]=" ";
	_Context->hint_ptt[0]=en__ptt;
	_Context->hint_ptt[1]=fr__ptt;
	_Context->hint_ptt[2]=it__ptt;
	_Context->hint_ptt[3]=es__ptt;
	_Context->hint_ptt[4]=de__ptt;
	_Context->hint_ptt[5]=nl__ptt;
	_Context->hint_ptt[6]=pt__ptt;
	_Context->hint_ptt[7]=xx__ptt;
	for (i=0; i < 8; i++)_Context->msg_Auto3692[i]=" ";
	_Context->msg_Auto3692[0]=en_Auto3692;
	_Context->msg_Auto3692[1]=fr_Auto3692;
	_Context->msg_Auto3692[2]=it_Auto3692;
	_Context->msg_Auto3692[3]=es_Auto3692;
	_Context->msg_Auto3692[4]=de_Auto3692;
	_Context->msg_Auto3692[5]=nl_Auto3692;
	_Context->msg_Auto3692[6]=pt_Auto3692;
	_Context->msg_Auto3692[7]=xx_Auto3692;
	_Context->hint_Auto3692[0]=en__Auto3692;
	_Context->hint_Auto3692[1]=fr__Auto3692;
	_Context->hint_Auto3692[2]=it__Auto3692;
	_Context->hint_Auto3692[3]=es__Auto3692;
	_Context->hint_Auto3692[4]=de__Auto3692;
	_Context->hint_Auto3692[5]=nl__Auto3692;
	_Context->hint_Auto3692[6]=pt__Auto3692;
	_Context->hint_Auto3692[7]=xx__Auto3692;
	_Context->hint_prv[0]=en__prv;
	for (i=0; i < 8; i++)_Context->msg_prt[i]=" ";
	_Context->hint_prt[0]=en__prt;
	_Context->hint_prt[1]=fr__prt;
	_Context->hint_prt[2]=it__prt;
	_Context->hint_prt[3]=es__prt;
	_Context->hint_prt[4]=de__prt;
	_Context->hint_prt[5]=nl__prt;
	_Context->hint_prt[6]=pt__prt;
	_Context->hint_prt[7]=xx__prt;
	for (i=0; i < 8; i++)_Context->msg_Auto3693[i]=" ";
	_Context->msg_Auto3693[0]=en_Auto3693;
	_Context->msg_Auto3693[1]=fr_Auto3693;
	_Context->msg_Auto3693[2]=it_Auto3693;
	_Context->msg_Auto3693[3]=es_Auto3693;
	_Context->msg_Auto3693[4]=de_Auto3693;
	_Context->msg_Auto3693[5]=nl_Auto3693;
	_Context->msg_Auto3693[6]=pt_Auto3693;
	_Context->msg_Auto3693[7]=xx_Auto3693;
	_Context->hint_Auto3693[0]=en__Auto3693;
	_Context->hint_Auto3693[1]=fr__Auto3693;
	_Context->hint_Auto3693[2]=it__Auto3693;
	_Context->hint_Auto3693[3]=es__Auto3693;
	_Context->hint_Auto3693[4]=de__Auto3693;
	_Context->hint_Auto3693[5]=nl__Auto3693;
	_Context->hint_Auto3693[6]=pt__Auto3693;
	_Context->hint_Auto3693[7]=xx__Auto3693;
	_Context->hint_pbv[0]=en__pbv;
	for (i=0; i < 8; i++)_Context->msg_pbt[i]=" ";
	_Context->hint_pbt[0]=en__pbt;
	_Context->hint_pbt[1]=fr__pbt;
	_Context->hint_pbt[2]=it__pbt;
	_Context->hint_pbt[3]=es__pbt;
	_Context->hint_pbt[4]=de__pbt;
	_Context->hint_pbt[5]=nl__pbt;
	_Context->hint_pbt[6]=pt__pbt;
	_Context->hint_pbt[7]=xx__pbt;
	for (i=0; i < 8; i++)_Context->msg_BGPage[i]=" ";
	_Context->msg_BGPage[0]=en_BGPage;
	_Context->msg_BGPage[1]=fr_BGPage;
	_Context->msg_BGPage[2]=it_BGPage;
	_Context->msg_BGPage[3]=es_BGPage;
	_Context->msg_BGPage[4]=de_BGPage;
	_Context->msg_BGPage[5]=nl_BGPage;
	_Context->msg_BGPage[6]=pt_BGPage;
	_Context->msg_BGPage[7]=xx_BGPage;
	_Context->hint_BGPage[0]=en__BGPage;
	_Context->focus_pages[8]=89;
	for (i=0; i < 8; i++)_Context->msg_Auto3694[i]=" ";
	_Context->msg_Auto3694[0]=en_Auto3694;
	_Context->msg_Auto3694[1]=fr_Auto3694;
	_Context->msg_Auto3694[2]=it_Auto3694;
	_Context->msg_Auto3694[3]=es_Auto3694;
	_Context->msg_Auto3694[4]=de_Auto3694;
	_Context->msg_Auto3694[5]=nl_Auto3694;
	_Context->msg_Auto3694[6]=pt_Auto3694;
	_Context->msg_Auto3694[7]=xx_Auto3694;
	_Context->hint_Auto3694[0]=en__Auto3694;
	_Context->hint_Auto3694[1]=fr__Auto3694;
	_Context->hint_Auto3694[2]=it__Auto3694;
	_Context->hint_Auto3694[3]=es__Auto3694;
	_Context->hint_Auto3694[4]=de__Auto3694;
	_Context->hint_Auto3694[5]=nl__Auto3694;
	_Context->hint_Auto3694[6]=pt__Auto3694;
	_Context->hint_Auto3694[7]=xx__Auto3694;
	for (i=0; i < 8; i++)_Context->msg_Auto3695[i]=" ";
	_Context->msg_Auto3695[0]=en_Auto3695;
	_Context->msg_Auto3695[1]=fr_Auto3695;
	_Context->msg_Auto3695[2]=it_Auto3695;
	_Context->msg_Auto3695[3]=es_Auto3695;
	_Context->msg_Auto3695[4]=de_Auto3695;
	_Context->msg_Auto3695[5]=nl_Auto3695;
	_Context->msg_Auto3695[6]=pt_Auto3695;
	_Context->msg_Auto3695[7]=xx_Auto3695;
	_Context->hint_Auto3695[0]=en__Auto3695;
	_Context->hint_Auto3695[1]=fr__Auto3695;
	_Context->hint_Auto3695[2]=it__Auto3695;
	_Context->hint_Auto3695[3]=es__Auto3695;
	_Context->hint_Auto3695[4]=de__Auto3695;
	_Context->hint_Auto3695[5]=nl__Auto3695;
	_Context->hint_Auto3695[6]=pt__Auto3695;
	_Context->hint_Auto3695[7]=xx__Auto3695;
	for (i=0; i < 8; i++)_Context->msg_Auto3696[i]=" ";
	_Context->msg_Auto3696[0]=en_Auto3696;
	_Context->msg_Auto3696[1]=fr_Auto3696;
	_Context->msg_Auto3696[2]=it_Auto3696;
	_Context->msg_Auto3696[3]=es_Auto3696;
	_Context->msg_Auto3696[4]=de_Auto3696;
	_Context->msg_Auto3696[5]=nl_Auto3696;
	_Context->msg_Auto3696[6]=pt_Auto3696;
	_Context->msg_Auto3696[7]=xx_Auto3696;
	_Context->hint_Auto3696[0]=en__Auto3696;
	_Context->hint_Auto3696[1]=fr__Auto3696;
	_Context->hint_Auto3696[2]=it__Auto3696;
	_Context->hint_Auto3696[3]=es__Auto3696;
	_Context->hint_Auto3696[4]=de__Auto3696;
	_Context->hint_Auto3696[5]=nl__Auto3696;
	_Context->hint_Auto3696[6]=pt__Auto3696;
	_Context->hint_Auto3696[7]=xx__Auto3696;
	for (i=0; i < 8; i++)_Context->msg_Auto3697[i]=" ";
	_Context->msg_Auto3697[0]=en_Auto3697;
	_Context->msg_Auto3697[1]=fr_Auto3697;
	_Context->msg_Auto3697[2]=it_Auto3697;
	_Context->msg_Auto3697[3]=es_Auto3697;
	_Context->msg_Auto3697[4]=de_Auto3697;
	_Context->msg_Auto3697[5]=nl_Auto3697;
	_Context->msg_Auto3697[6]=pt_Auto3697;
	_Context->msg_Auto3697[7]=xx_Auto3697;
	_Context->hint_Auto3697[0]=en__Auto3697;
	_Context->hint_Auto3697[1]=fr__Auto3697;
	_Context->hint_Auto3697[2]=it__Auto3697;
	_Context->hint_Auto3697[3]=es__Auto3697;
	_Context->hint_Auto3697[4]=de__Auto3697;
	_Context->hint_Auto3697[5]=nl__Auto3697;
	_Context->hint_Auto3697[6]=pt__Auto3697;
	_Context->hint_Auto3697[7]=xx__Auto3697;
	for (i=0; i < 8; i++)_Context->msg_Auto3698[i]=" ";
	_Context->msg_Auto3698[0]=en_Auto3698;
	_Context->msg_Auto3698[1]=fr_Auto3698;
	_Context->msg_Auto3698[2]=it_Auto3698;
	_Context->msg_Auto3698[3]=es_Auto3698;
	_Context->msg_Auto3698[4]=de_Auto3698;
	_Context->msg_Auto3698[5]=nl_Auto3698;
	_Context->msg_Auto3698[6]=pt_Auto3698;
	_Context->msg_Auto3698[7]=xx_Auto3698;
	_Context->hint_Auto3698[0]=en__Auto3698;
	for (i=0; i < 8; i++)_Context->msg_Auto3699[i]=" ";
	_Context->msg_Auto3699[0]=en_Auto3699;
	_Context->msg_Auto3699[1]=fr_Auto3699;
	_Context->msg_Auto3699[2]=it_Auto3699;
	_Context->msg_Auto3699[3]=es_Auto3699;
	_Context->msg_Auto3699[4]=de_Auto3699;
	_Context->msg_Auto3699[5]=nl_Auto3699;
	_Context->msg_Auto3699[6]=pt_Auto3699;
	_Context->msg_Auto3699[7]=xx_Auto3699;
	_Context->hint_Auto3699[0]=en__Auto3699;
	for (i=0; i < 8; i++)_Context->msg_Auto3700[i]=" ";
	_Context->msg_Auto3700[0]=en_Auto3700;
	_Context->msg_Auto3700[1]=fr_Auto3700;
	_Context->msg_Auto3700[2]=it_Auto3700;
	_Context->msg_Auto3700[3]=es_Auto3700;
	_Context->msg_Auto3700[4]=de_Auto3700;
	_Context->msg_Auto3700[5]=nl_Auto3700;
	_Context->msg_Auto3700[6]=pt_Auto3700;
	_Context->msg_Auto3700[7]=xx_Auto3700;
	_Context->hint_Auto3700[0]=en__Auto3700;
	for (i=0; i < 8; i++)_Context->msg_Auto3701[i]=" ";
	_Context->msg_Auto3701[0]=en_Auto3701;
	_Context->msg_Auto3701[1]=fr_Auto3701;
	_Context->msg_Auto3701[2]=it_Auto3701;
	_Context->msg_Auto3701[3]=es_Auto3701;
	_Context->msg_Auto3701[4]=de_Auto3701;
	_Context->msg_Auto3701[5]=nl_Auto3701;
	_Context->msg_Auto3701[6]=pt_Auto3701;
	_Context->msg_Auto3701[7]=xx_Auto3701;
	_Context->hint_Auto3701[0]=en__Auto3701;
	_Context->hint_Auto3701[1]=fr__Auto3701;
	_Context->hint_Auto3701[2]=it__Auto3701;
	_Context->hint_Auto3701[3]=es__Auto3701;
	_Context->hint_Auto3701[4]=de__Auto3701;
	_Context->hint_Auto3701[5]=nl__Auto3701;
	_Context->hint_Auto3701[6]=pt__Auto3701;
	_Context->hint_Auto3701[7]=xx__Auto3701;
	for (i=0; i < 8; i++)_Context->msg_Auto3702[i]=" ";
	_Context->msg_Auto3702[0]=en_Auto3702;
	_Context->msg_Auto3702[1]=fr_Auto3702;
	_Context->msg_Auto3702[2]=it_Auto3702;
	_Context->msg_Auto3702[3]=es_Auto3702;
	_Context->msg_Auto3702[4]=de_Auto3702;
	_Context->msg_Auto3702[5]=nl_Auto3702;
	_Context->msg_Auto3702[6]=pt_Auto3702;
	_Context->msg_Auto3702[7]=xx_Auto3702;
	_Context->hint_Auto3702[0]=en__Auto3702;
	_Context->hint_Auto3702[1]=fr__Auto3702;
	_Context->hint_Auto3702[2]=it__Auto3702;
	_Context->hint_Auto3702[3]=es__Auto3702;
	_Context->hint_Auto3702[4]=de__Auto3702;
	_Context->hint_Auto3702[5]=nl__Auto3702;
	_Context->hint_Auto3702[6]=pt__Auto3702;
	_Context->hint_Auto3702[7]=xx__Auto3702;
	for (i=0; i < 8; i++)_Context->msg_Auto3703[i]=" ";
	_Context->msg_Auto3703[0]=en_Auto3703;
	_Context->msg_Auto3703[1]=fr_Auto3703;
	_Context->msg_Auto3703[2]=it_Auto3703;
	_Context->msg_Auto3703[3]=es_Auto3703;
	_Context->msg_Auto3703[4]=de_Auto3703;
	_Context->msg_Auto3703[5]=nl_Auto3703;
	_Context->msg_Auto3703[6]=pt_Auto3703;
	_Context->msg_Auto3703[7]=xx_Auto3703;
	_Context->hint_Auto3703[0]=en__Auto3703;
	_Context->hint_Auto3703[1]=fr__Auto3703;
	_Context->hint_Auto3703[2]=it__Auto3703;
	_Context->hint_Auto3703[3]=es__Auto3703;
	_Context->hint_Auto3703[4]=de__Auto3703;
	_Context->hint_Auto3703[5]=nl__Auto3703;
	_Context->hint_Auto3703[6]=pt__Auto3703;
	_Context->hint_Auto3703[7]=xx__Auto3703;
	_Context->hint_bgi[0]=en__bgi;
	for (i=0; i < 8; i++)_Context->msg_bgia[i]=" ";
	_Context->hint_bgia[0]=en__bgia;
	_Context->hint_bgia[1]=fr__bgia;
	_Context->hint_bgia[2]=it__bgia;
	_Context->hint_bgia[3]=es__bgia;
	_Context->hint_bgia[4]=de__bgia;
	_Context->hint_bgia[5]=nl__bgia;
	_Context->hint_bgia[6]=pt__bgia;
	_Context->hint_bgia[7]=xx__bgia;
	for (i=0; i < 8; i++)_Context->msg_bgitr[i]=" ";
	_Context->hint_bgitr[0]=en__bgitr;
	_Context->hint_bgitr[1]=fr__bgitr;
	_Context->hint_bgitr[2]=it__bgitr;
	_Context->hint_bgitr[3]=es__bgitr;
	_Context->hint_bgitr[4]=de__bgitr;
	_Context->hint_bgitr[5]=nl__bgitr;
	_Context->hint_bgitr[6]=pt__bgitr;
	_Context->hint_bgitr[7]=xx__bgitr;
	for (i=0; i < 8; i++)_Context->msg_bgct[i]=" ";
	_Context->hint_bgct[0]=en__bgct;
	_Context->hint_bgct[1]=fr__bgct;
	_Context->hint_bgct[2]=it__bgct;
	_Context->hint_bgct[3]=es__bgct;
	_Context->hint_bgct[4]=de__bgct;
	_Context->hint_bgct[5]=nl__bgct;
	_Context->hint_bgct[6]=pt__bgct;
	_Context->hint_bgct[7]=xx__bgct;
	_Context->hint_bgcv[0]=en__bgcv;
	for (i=0; i < 8; i++)_Context->msg_ContentPage[i]=" ";
	_Context->msg_ContentPage[0]=en_ContentPage;
	_Context->msg_ContentPage[1]=fr_ContentPage;
	_Context->msg_ContentPage[2]=it_ContentPage;
	_Context->msg_ContentPage[3]=es_ContentPage;
	_Context->msg_ContentPage[4]=de_ContentPage;
	_Context->msg_ContentPage[5]=nl_ContentPage;
	_Context->msg_ContentPage[6]=pt_ContentPage;
	_Context->msg_ContentPage[7]=xx_ContentPage;
	_Context->hint_ContentPage[0]=en__ContentPage;
	_Context->focus_pages[9]=95;
	for (i=0; i < 8; i++)_Context->msg_Auto3704[i]=" ";
	_Context->msg_Auto3704[0]=en_Auto3704;
	_Context->msg_Auto3704[1]=fr_Auto3704;
	_Context->msg_Auto3704[2]=it_Auto3704;
	_Context->msg_Auto3704[3]=es_Auto3704;
	_Context->msg_Auto3704[4]=de_Auto3704;
	_Context->msg_Auto3704[5]=nl_Auto3704;
	_Context->msg_Auto3704[6]=pt_Auto3704;
	_Context->msg_Auto3704[7]=xx_Auto3704;
	_Context->hint_Auto3704[0]=en__Auto3704;
	_Context->hint_Auto3704[1]=fr__Auto3704;
	_Context->hint_Auto3704[2]=it__Auto3704;
	_Context->hint_Auto3704[3]=es__Auto3704;
	_Context->hint_Auto3704[4]=de__Auto3704;
	_Context->hint_Auto3704[5]=nl__Auto3704;
	_Context->hint_Auto3704[6]=pt__Auto3704;
	_Context->hint_Auto3704[7]=xx__Auto3704;
	for (i=0; i < 8; i++)_Context->msg_Auto3705[i]=" ";
	_Context->msg_Auto3705[0]=en_Auto3705;
	_Context->msg_Auto3705[1]=fr_Auto3705;
	_Context->msg_Auto3705[2]=it_Auto3705;
	_Context->msg_Auto3705[3]=es_Auto3705;
	_Context->msg_Auto3705[4]=de_Auto3705;
	_Context->msg_Auto3705[5]=nl_Auto3705;
	_Context->msg_Auto3705[6]=pt_Auto3705;
	_Context->msg_Auto3705[7]=xx_Auto3705;
	_Context->hint_Auto3705[0]=en__Auto3705;
	_Context->hint_Auto3705[1]=fr__Auto3705;
	_Context->hint_Auto3705[2]=it__Auto3705;
	_Context->hint_Auto3705[3]=es__Auto3705;
	_Context->hint_Auto3705[4]=de__Auto3705;
	_Context->hint_Auto3705[5]=nl__Auto3705;
	_Context->hint_Auto3705[6]=pt__Auto3705;
	_Context->hint_Auto3705[7]=xx__Auto3705;
	for (i=0; i < 8; i++)_Context->msg_Auto3706[i]=" ";
	_Context->msg_Auto3706[0]=en_Auto3706;
	_Context->msg_Auto3706[1]=fr_Auto3706;
	_Context->msg_Auto3706[2]=it_Auto3706;
	_Context->msg_Auto3706[3]=es_Auto3706;
	_Context->msg_Auto3706[4]=de_Auto3706;
	_Context->msg_Auto3706[5]=nl_Auto3706;
	_Context->msg_Auto3706[6]=pt_Auto3706;
	_Context->msg_Auto3706[7]=xx_Auto3706;
	_Context->hint_Auto3706[0]=en__Auto3706;
	_Context->hint_Auto3706[1]=fr__Auto3706;
	_Context->hint_Auto3706[2]=it__Auto3706;
	_Context->hint_Auto3706[3]=es__Auto3706;
	_Context->hint_Auto3706[4]=de__Auto3706;
	_Context->hint_Auto3706[5]=nl__Auto3706;
	_Context->hint_Auto3706[6]=pt__Auto3706;
	_Context->hint_Auto3706[7]=xx__Auto3706;
	for (i=0; i < 8; i++)_Context->msg_Auto3707[i]=" ";
	_Context->msg_Auto3707[0]=en_Auto3707;
	_Context->msg_Auto3707[1]=fr_Auto3707;
	_Context->msg_Auto3707[2]=it_Auto3707;
	_Context->msg_Auto3707[3]=es_Auto3707;
	_Context->msg_Auto3707[4]=de_Auto3707;
	_Context->msg_Auto3707[5]=nl_Auto3707;
	_Context->msg_Auto3707[6]=pt_Auto3707;
	_Context->msg_Auto3707[7]=xx_Auto3707;
	_Context->hint_Auto3707[0]=en__Auto3707;
	_Context->hint_Auto3707[1]=fr__Auto3707;
	_Context->hint_Auto3707[2]=it__Auto3707;
	_Context->hint_Auto3707[3]=es__Auto3707;
	_Context->hint_Auto3707[4]=de__Auto3707;
	_Context->hint_Auto3707[5]=nl__Auto3707;
	_Context->hint_Auto3707[6]=pt__Auto3707;
	_Context->hint_Auto3707[7]=xx__Auto3707;
	for (i=0; i < 8; i++)_Context->msg_Auto3708[i]=" ";
	_Context->msg_Auto3708[0]=en_Auto3708;
	_Context->msg_Auto3708[1]=fr_Auto3708;
	_Context->msg_Auto3708[2]=it_Auto3708;
	_Context->msg_Auto3708[3]=es_Auto3708;
	_Context->msg_Auto3708[4]=de_Auto3708;
	_Context->msg_Auto3708[5]=nl_Auto3708;
	_Context->msg_Auto3708[6]=pt_Auto3708;
	_Context->msg_Auto3708[7]=xx_Auto3708;
	_Context->hint_Auto3708[0]=en__Auto3708;
	_Context->hint_Auto3708[1]=fr__Auto3708;
	_Context->hint_Auto3708[2]=it__Auto3708;
	_Context->hint_Auto3708[3]=es__Auto3708;
	_Context->hint_Auto3708[4]=de__Auto3708;
	_Context->hint_Auto3708[5]=nl__Auto3708;
	_Context->hint_Auto3708[6]=pt__Auto3708;
	_Context->hint_Auto3708[7]=xx__Auto3708;
	for (i=0; i < 8; i++)_Context->msg_Auto3709[i]=" ";
	_Context->msg_Auto3709[0]=en_Auto3709;
	_Context->msg_Auto3709[1]=fr_Auto3709;
	_Context->msg_Auto3709[2]=it_Auto3709;
	_Context->msg_Auto3709[3]=es_Auto3709;
	_Context->msg_Auto3709[4]=de_Auto3709;
	_Context->msg_Auto3709[5]=nl_Auto3709;
	_Context->msg_Auto3709[6]=pt_Auto3709;
	_Context->msg_Auto3709[7]=xx_Auto3709;
	_Context->hint_Auto3709[0]=en__Auto3709;
	_Context->hint_Auto3709[1]=fr__Auto3709;
	_Context->hint_Auto3709[2]=it__Auto3709;
	_Context->hint_Auto3709[3]=es__Auto3709;
	_Context->hint_Auto3709[4]=de__Auto3709;
	_Context->hint_Auto3709[5]=nl__Auto3709;
	_Context->hint_Auto3709[6]=pt__Auto3709;
	_Context->hint_Auto3709[7]=xx__Auto3709;
	for (i=0; i < 8; i++)_Context->msg_Auto3710[i]=" ";
	_Context->msg_Auto3710[0]=en_Auto3710;
	_Context->msg_Auto3710[1]=fr_Auto3710;
	_Context->msg_Auto3710[2]=it_Auto3710;
	_Context->msg_Auto3710[3]=es_Auto3710;
	_Context->msg_Auto3710[4]=de_Auto3710;
	_Context->msg_Auto3710[5]=nl_Auto3710;
	_Context->msg_Auto3710[6]=pt_Auto3710;
	_Context->msg_Auto3710[7]=xx_Auto3710;
	_Context->hint_Auto3710[0]=en__Auto3710;
	_Context->hint_Auto3710[1]=fr__Auto3710;
	_Context->hint_Auto3710[2]=it__Auto3710;
	_Context->hint_Auto3710[3]=es__Auto3710;
	_Context->hint_Auto3710[4]=de__Auto3710;
	_Context->hint_Auto3710[5]=nl__Auto3710;
	_Context->hint_Auto3710[6]=pt__Auto3710;
	_Context->hint_Auto3710[7]=xx__Auto3710;
	for (i=0; i < 8; i++)_Context->msg_Auto3711[i]=" ";
	_Context->msg_Auto3711[0]=en_Auto3711;
	_Context->msg_Auto3711[1]=fr_Auto3711;
	_Context->msg_Auto3711[2]=it_Auto3711;
	_Context->msg_Auto3711[3]=es_Auto3711;
	_Context->msg_Auto3711[4]=de_Auto3711;
	_Context->msg_Auto3711[5]=nl_Auto3711;
	_Context->msg_Auto3711[6]=pt_Auto3711;
	_Context->msg_Auto3711[7]=xx_Auto3711;
	_Context->hint_Auto3711[0]=en__Auto3711;
	_Context->hint_Auto3711[1]=fr__Auto3711;
	_Context->hint_Auto3711[2]=it__Auto3711;
	_Context->hint_Auto3711[3]=es__Auto3711;
	_Context->hint_Auto3711[4]=de__Auto3711;
	_Context->hint_Auto3711[5]=nl__Auto3711;
	_Context->hint_Auto3711[6]=pt__Auto3711;
	_Context->hint_Auto3711[7]=xx__Auto3711;
	for (i=0; i < 8; i++)_Context->msg_Auto3712[i]=" ";
	_Context->msg_Auto3712[0]=en_Auto3712;
	_Context->msg_Auto3712[1]=fr_Auto3712;
	_Context->msg_Auto3712[2]=it_Auto3712;
	_Context->msg_Auto3712[3]=es_Auto3712;
	_Context->msg_Auto3712[4]=de_Auto3712;
	_Context->msg_Auto3712[5]=nl_Auto3712;
	_Context->msg_Auto3712[6]=pt_Auto3712;
	_Context->msg_Auto3712[7]=xx_Auto3712;
	_Context->hint_Auto3712[0]=en__Auto3712;
	_Context->hint_Auto3712[1]=fr__Auto3712;
	_Context->hint_Auto3712[2]=it__Auto3712;
	_Context->hint_Auto3712[3]=es__Auto3712;
	_Context->hint_Auto3712[4]=de__Auto3712;
	_Context->hint_Auto3712[5]=nl__Auto3712;
	_Context->hint_Auto3712[6]=pt__Auto3712;
	_Context->hint_Auto3712[7]=xx__Auto3712;
	for (i=0; i < 8; i++)_Context->msg_txtol[i]=" ";
	_Context->msg_txtol[0]=en_txtol;
	_Context->msg_txtol[1]=fr_txtol;
	_Context->msg_txtol[2]=it_txtol;
	_Context->msg_txtol[3]=es_txtol;
	_Context->msg_txtol[4]=de_txtol;
	_Context->msg_txtol[5]=nl_txtol;
	_Context->msg_txtol[6]=pt_txtol;
	_Context->msg_txtol[7]=xx_txtol;
	_Context->hint_txtol[0]=en__txtol;
	for (i=0; i < 8; i++)_Context->msg_txtlt[i]=" ";
	_Context->msg_txtlt[0]=en_txtlt;
	_Context->msg_txtlt[1]=fr_txtlt;
	_Context->msg_txtlt[2]=it_txtlt;
	_Context->msg_txtlt[3]=es_txtlt;
	_Context->msg_txtlt[4]=de_txtlt;
	_Context->msg_txtlt[5]=nl_txtlt;
	_Context->msg_txtlt[6]=pt_txtlt;
	_Context->msg_txtlt[7]=xx_txtlt;
	_Context->hint_txtlt[0]=en__txtlt;
	for (i=0; i < 8; i++)_Context->msg_txtul[i]=" ";
	_Context->msg_txtul[0]=en_txtul;
	_Context->msg_txtul[1]=fr_txtul;
	_Context->msg_txtul[2]=it_txtul;
	_Context->msg_txtul[3]=es_txtul;
	_Context->msg_txtul[4]=de_txtul;
	_Context->msg_txtul[5]=nl_txtul;
	_Context->msg_txtul[6]=pt_txtul;
	_Context->msg_txtul[7]=xx_txtul;
	_Context->hint_txtul[0]=en__txtul;
	for (i=0; i < 8; i++)_Context->msg_txtbo[i]=" ";
	_Context->msg_txtbo[0]=en_txtbo;
	_Context->msg_txtbo[1]=fr_txtbo;
	_Context->msg_txtbo[2]=it_txtbo;
	_Context->msg_txtbo[3]=es_txtbo;
	_Context->msg_txtbo[4]=de_txtbo;
	_Context->msg_txtbo[5]=nl_txtbo;
	_Context->msg_txtbo[6]=pt_txtbo;
	_Context->msg_txtbo[7]=xx_txtbo;
	_Context->hint_txtbo[0]=en__txtbo;
	for (i=0; i < 8; i++)_Context->msg_txtsh[i]=" ";
	_Context->msg_txtsh[0]=en_txtsh;
	_Context->msg_txtsh[1]=fr_txtsh;
	_Context->msg_txtsh[2]=it_txtsh;
	_Context->msg_txtsh[3]=es_txtsh;
	_Context->msg_txtsh[4]=de_txtsh;
	_Context->msg_txtsh[5]=nl_txtsh;
	_Context->msg_txtsh[6]=pt_txtsh;
	_Context->msg_txtsh[7]=xx_txtsh;
	_Context->hint_txtsh[0]=en__txtsh;
	for (i=0; i < 8; i++)_Context->msg_txtbl[i]=" ";
	_Context->msg_txtbl[0]=en_txtbl;
	_Context->msg_txtbl[1]=fr_txtbl;
	_Context->msg_txtbl[2]=it_txtbl;
	_Context->msg_txtbl[3]=es_txtbl;
	_Context->msg_txtbl[4]=de_txtbl;
	_Context->msg_txtbl[5]=nl_txtbl;
	_Context->msg_txtbl[6]=pt_txtbl;
	_Context->msg_txtbl[7]=xx_txtbl;
	_Context->hint_txtbl[0]=en__txtbl;
	for (i=0; i < 8; i++)_Context->msg_Auto3713[i]=" ";
	_Context->msg_Auto3713[0]=en_Auto3713;
	_Context->msg_Auto3713[1]=fr_Auto3713;
	_Context->msg_Auto3713[2]=it_Auto3713;
	_Context->msg_Auto3713[3]=es_Auto3713;
	_Context->msg_Auto3713[4]=de_Auto3713;
	_Context->msg_Auto3713[5]=nl_Auto3713;
	_Context->msg_Auto3713[6]=pt_Auto3713;
	_Context->msg_Auto3713[7]=xx_Auto3713;
	_Context->hint_Auto3713[0]=en__Auto3713;
	_Context->hint_Auto3713[1]=fr__Auto3713;
	_Context->hint_Auto3713[2]=it__Auto3713;
	_Context->hint_Auto3713[3]=es__Auto3713;
	_Context->hint_Auto3713[4]=de__Auto3713;
	_Context->hint_Auto3713[5]=nl__Auto3713;
	_Context->hint_Auto3713[6]=pt__Auto3713;
	_Context->hint_Auto3713[7]=xx__Auto3713;
	for (i=0; i < 8; i++)_Context->msg_Auto3714[i]=" ";
	_Context->msg_Auto3714[0]=en_Auto3714;
	_Context->msg_Auto3714[1]=fr_Auto3714;
	_Context->msg_Auto3714[2]=it_Auto3714;
	_Context->msg_Auto3714[3]=es_Auto3714;
	_Context->msg_Auto3714[4]=de_Auto3714;
	_Context->msg_Auto3714[5]=nl_Auto3714;
	_Context->msg_Auto3714[6]=pt_Auto3714;
	_Context->msg_Auto3714[7]=xx_Auto3714;
	_Context->hint_Auto3714[0]=en__Auto3714;
	_Context->hint_Auto3714[1]=fr__Auto3714;
	_Context->hint_Auto3714[2]=it__Auto3714;
	_Context->hint_Auto3714[3]=es__Auto3714;
	_Context->hint_Auto3714[4]=de__Auto3714;
	_Context->hint_Auto3714[5]=nl__Auto3714;
	_Context->hint_Auto3714[6]=pt__Auto3714;
	_Context->hint_Auto3714[7]=xx__Auto3714;
	for (i=0; i < 8; i++)_Context->msg_Auto3715[i]=" ";
	_Context->msg_Auto3715[0]=en_Auto3715;
	_Context->msg_Auto3715[1]=fr_Auto3715;
	_Context->msg_Auto3715[2]=it_Auto3715;
	_Context->msg_Auto3715[3]=es_Auto3715;
	_Context->msg_Auto3715[4]=de_Auto3715;
	_Context->msg_Auto3715[5]=nl_Auto3715;
	_Context->msg_Auto3715[6]=pt_Auto3715;
	_Context->msg_Auto3715[7]=xx_Auto3715;
	_Context->hint_Auto3715[0]=en__Auto3715;
	_Context->hint_Auto3715[1]=fr__Auto3715;
	_Context->hint_Auto3715[2]=it__Auto3715;
	_Context->hint_Auto3715[3]=es__Auto3715;
	_Context->hint_Auto3715[4]=de__Auto3715;
	_Context->hint_Auto3715[5]=nl__Auto3715;
	_Context->hint_Auto3715[6]=pt__Auto3715;
	_Context->hint_Auto3715[7]=xx__Auto3715;
	for (i=0; i < 8; i++)_Context->msg_Auto3716[i]=" ";
	_Context->msg_Auto3716[0]=en_Auto3716;
	_Context->msg_Auto3716[1]=fr_Auto3716;
	_Context->msg_Auto3716[2]=it_Auto3716;
	_Context->msg_Auto3716[3]=es_Auto3716;
	_Context->msg_Auto3716[4]=de_Auto3716;
	_Context->msg_Auto3716[5]=nl_Auto3716;
	_Context->msg_Auto3716[6]=pt_Auto3716;
	_Context->msg_Auto3716[7]=xx_Auto3716;
	_Context->hint_Auto3716[0]=en__Auto3716;
	_Context->hint_Auto3716[1]=fr__Auto3716;
	_Context->hint_Auto3716[2]=it__Auto3716;
	_Context->hint_Auto3716[3]=es__Auto3716;
	_Context->hint_Auto3716[4]=de__Auto3716;
	_Context->hint_Auto3716[5]=nl__Auto3716;
	_Context->hint_Auto3716[6]=pt__Auto3716;
	_Context->hint_Auto3716[7]=xx__Auto3716;
	_Context->hint_txfu[0]=en__txfu;
	for (i=0; i < 8; i++)_Context->msg_txct[i]=" ";
	_Context->hint_txct[0]=en__txct;
	_Context->hint_txct[1]=fr__txct;
	_Context->hint_txct[2]=it__txct;
	_Context->hint_txct[3]=es__txct;
	_Context->hint_txct[4]=de__txct;
	_Context->hint_txct[5]=nl__txct;
	_Context->hint_txct[6]=pt__txct;
	_Context->hint_txct[7]=xx__txct;
	_Context->hint_txcv[0]=en__txcv;
	for (i=0; i < 8; i++)_Context->msg_txta[i]=" ";
	_Context->hint_txta[0]=en__txta;
	_Context->hint_txta[1]=fr__txta;
	_Context->hint_txta[2]=it__txta;
	_Context->hint_txta[3]=es__txta;
	_Context->hint_txta[4]=de__txta;
	_Context->hint_txta[5]=nl__txta;
	_Context->hint_txta[6]=pt__txta;
	_Context->hint_txta[7]=xx__txta;
	_Context->hint_ltspv[0]=en__ltspv;
	for (i=0; i < 8; i++)_Context->msg_ltspt[i]=" ";
	_Context->hint_ltspt[0]=en__ltspt;
	_Context->hint_ltspt[1]=fr__ltspt;
	_Context->hint_ltspt[2]=it__ltspt;
	_Context->hint_ltspt[3]=es__ltspt;
	_Context->hint_ltspt[4]=de__ltspt;
	_Context->hint_ltspt[5]=nl__ltspt;
	_Context->hint_ltspt[6]=pt__ltspt;
	_Context->hint_ltspt[7]=xx__ltspt;
	_Context->hint_wspv[0]=en__wspv;
	for (i=0; i < 8; i++)_Context->msg_wspt[i]=" ";
	_Context->hint_wspt[0]=en__wspt;
	_Context->hint_wspt[1]=fr__wspt;
	_Context->hint_wspt[2]=it__wspt;
	_Context->hint_wspt[3]=es__wspt;
	_Context->hint_wspt[4]=de__wspt;
	_Context->hint_wspt[5]=nl__wspt;
	_Context->hint_wspt[6]=pt__wspt;
	_Context->hint_wspt[7]=xx__wspt;
	_Context->hint_lnspv[0]=en__lnspv;
	for (i=0; i < 8; i++)_Context->msg_lnspt[i]=" ";
	_Context->hint_lnspt[0]=en__lnspt;
	_Context->hint_lnspt[1]=fr__lnspt;
	_Context->hint_lnspt[2]=it__lnspt;
	_Context->hint_lnspt[3]=es__lnspt;
	_Context->hint_lnspt[4]=de__lnspt;
	_Context->hint_lnspt[5]=nl__lnspt;
	_Context->hint_lnspt[6]=pt__lnspt;
	_Context->hint_lnspt[7]=xx__lnspt;
	_Context->hint_Message[0]=en__Message;
	strcpy(_Context->buffer_Message,"test message");
		_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3628,_Context->y_Auto3628,810+10,620+10);
	return(0);
}

public 	int	cstyleman_hide(struct cstyleman_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_Thing != (void *) 0)
	&& (_Context->s_Thing != 0)) {
		(void)visual_buffer_put(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
		_Context->s_Thing=0;
		}
	if ((_Context->p_Action != (void *) 0)
	&& (_Context->s_Action != 0)) {
		(void)visual_buffer_put(_Context->p_Action,_Context->x_Action,_Context->y_Action);
		_Context->s_Action=0;
		}
	if ((_Context->p_Trace != (void *) 0)
	&& (_Context->s_Trace != 0)) {
		(void)visual_buffer_put(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
		_Context->s_Trace=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3628,_Context->y_Auto3628);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	cstyleman_remove(struct cstyleman_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_Thing != (void *) 0)
		_Context->p_Thing = visual_drop(_Context->p_Thing);
	if (_Context->p_Action != (void *) 0)
		_Context->p_Action = visual_drop(_Context->p_Action);
	if (_Context->p_Trace != (void *) 0)
		_Context->p_Trace = visual_drop(_Context->p_Trace);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_Trace_show(struct cstyleman_context * _Context) {
	if(consult_style_trace()){
		if ((_Context->p_Trace != (void *) 0)
	&& (_Context->s_Trace == 0)) {
		(void)visual_buffer_get(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
		_Context->s_Trace=1;
		}
	if ((_Context->p_Trace != (void *) 0)
	&& (_Context->s_Trace == 0)) {
		(void)visual_buffer_get(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
		_Context->s_Trace=1;
		}
	_Context->trigger_Trace=visual_trigger_code(_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]));
	visual_button(_Context->x_Auto3628+680,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),1072);
;
	}
	else{
		if ((_Context->p_Trace != (void *) 0)
	&& (_Context->s_Trace != 0)) {
		(void)visual_buffer_put(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
		_Context->s_Trace=0;
		}
;
	}
	return(-1);
}
private int on_ClassList_show(struct cstyleman_context * _Context) {
	int l;
	int n;
	struct element_style*eptr;
	struct element_style*resolve_style_number(int);
	memset(_Context->buffer_ClassList,' ',1302);
	if(!(_Context->value_ClassList)){_Context->value_ClassList=1;}
	for(l=1;l<=14;l++){
	if(!(eptr=resolve_style_number(l+_Context->value_CLBar)))
	continue;
	else{
	if ( l > 0 ) { _Context->row_ClassList=&_Context->buffer_ClassList[l-1][0]; } ;
	strcpy((_Context->row_ClassList+0),eptr->name);
	if(eptr->basename)
	strcpy((_Context->row_ClassList+47),eptr->basename);
	}
	}
		visual_table(_Context->x_Auto3628+20,_Context->y_Auto3628+90,750,250,vfh[1],0,0,_Context->msg_ClassList[_Context->language],_Context->buffer_ClassList,0x4401,"(W20,W20)");
;
	_Context->y_CLCursor=_Context->y_Auto3628+90+(_Context->value_ClassList*16)+2;
	_Context->x_CLCursor=_Context->x_Auto3628+20+2;
	_Context->h_CLCursor=16;
	_Context->w_CLCursor=(8*47);
		visual_filzone(_Context->x_CLCursor,_Context->y_CLCursor,_Context->w_CLCursor,_Context->h_CLCursor,29,16);
;
	return(-1);
}
private int on_FileList_show(struct cstyleman_context * _Context) {
	int indent;
	int l;
	int n;
	struct element_file*fptr;
	struct element_file*resolve_stylefile_number(int);
	memset(_Context->buffer_FileList,' ',705);
	if(!(_Context->value_FileList)){_Context->value_FileList=1;}
	for(l=1;l<=15;l++){
	if(!(fptr=resolve_stylefile_number(l+_Context->value_FLBar)))
	continue;
	else{
	if ( l > 0 ) { _Context->row_FileList=&_Context->buffer_FileList[l-1][0]; } ;
	if(strlen(fptr->name)>47)
	indent=(strlen(fptr->name)-47);
	else indent=0;
	strcpy((_Context->row_FileList+0),(fptr->name+indent));
	}
	}
		visual_table(_Context->x_Auto3628+390,_Context->y_Auto3628+340,380,260,vfh[1],0,0,_Context->msg_FileList[_Context->language],_Context->buffer_FileList,0x4401,"($)");
;
	_Context->y_FLCursor=_Context->y_Auto3628+340+(_Context->value_FileList*16)+2;
	_Context->x_FLCursor=_Context->x_Auto3628+390+2;
	_Context->h_FLCursor=16;
	_Context->w_FLCursor=(8*47);
		visual_filzone(_Context->x_FLCursor,_Context->y_FLCursor,_Context->w_FLCursor,_Context->h_FLCursor,29,16);
;
	if((fptr=resolve_stylefile_number(_Context->value_FileList+_Context->value_FLBar))!=(struct element_file*)0){
	if(fptr->name!=(char*)0){
	memset(_Context->buffer_ExportName,' ',255);
	strcpy(_Context->buffer_ExportName,fptr->name);
	}
	}
	return(-1);
}
private int on_CFList_show(struct cstyleman_context * _Context) {
	int l;
	int n;
	struct element_file*fptr;
	struct element_file*resolve_stylefile_number(int);
	struct element_class*cptr;
	struct element_class*resolve_stylefile_member(struct element_file*,int);
	memset(_Context->buffer_CFList,' ',645);
	if(!(_Context->value_CFList)){_Context->value_CFList=1;}
	if((fptr=resolve_stylefile_number(_Context->value_FileList+_Context->value_FLBar))!=(struct element_file*)0){
	for(l=1;l<=15;l++){
	if(!(cptr=resolve_stylefile_member(fptr,l+_Context->value_MLBar)))
	break;
	else if(!(cptr->style))
	continue;
	else{
	if ( l > 0 ) { _Context->row_CFList=&_Context->buffer_CFList[l-1][0]; } ;
	strcpy((_Context->row_CFList+0),cptr->style->name);
	}
	}
	}
		visual_table(_Context->x_Auto3628+20,_Context->y_Auto3628+340,350,260,vfh[1],0,0,_Context->msg_CFList[_Context->language],_Context->buffer_CFList,0x4401,"($)");
;
	_Context->y_MLCursor=_Context->y_Auto3628+340+(_Context->value_CFList*16)+2;
	_Context->x_MLCursor=_Context->x_Auto3628+20+2;
	_Context->h_MLCursor=16;
	_Context->w_MLCursor=(8*43);
		visual_filzone(_Context->x_MLCursor,_Context->y_MLCursor,_Context->w_MLCursor,_Context->h_MLCursor,29,16);
;
	return(-1);
}
private int on_CLBar_show(struct cstyleman_context * _Context) {
	if((_Context->max_CLBar=style_class_count())<_Context->limit_CLBar)
	_Context->max_CLBar=_Context->limit_CLBar;
		visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);
;
	return(-1);
}
private int on_MLBar_show(struct cstyleman_context * _Context) {
	if((_Context->max_MLBar=style_file_members(_Context->value_FileList+_Context->value_FLBar))<_Context->limit_MLBar)
	_Context->max_MLBar=_Context->limit_MLBar;
		visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);
;
	return(-1);
}
private int on_FLBar_show(struct cstyleman_context * _Context) {
	if((_Context->max_FLBar=style_file_count())<_Context->limit_FLBar)
	_Context->max_FLBar=_Context->limit_FLBar;
		visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);
;
	return(-1);
}
private int on_StatusBar_show(struct cstyleman_context * _Context) {
	if(_Context->page_number>1){
	visual_frame(_Context->x_Auto3628+50,_Context->y_Auto3628+560,712+2,16+2,5);
visual_text(_Context->x_Auto3628+50+1,_Context->y_Auto3628+560+1,712,16,vfh[2],31,2,_Context->buffer_StatusBar,255,3);
;
	}
	return(-1);
}
private int on_Thing_show(struct cstyleman_context * _Context) {
	int i;
	char nomfic[257];
	for(i=0;i<256;i++){
	if(*(_Context->buffer_ClassFile+i)==' ')
	break;
	else nomfic[i]=*(_Context->buffer_ClassFile+i);
	}
	nomfic[i]=0;
	if(i>0){
	load_visual_style(nomfic,i);
	}
		if ((_Context->p_Thing != (void *) 0)
	&& (_Context->s_Thing == 0)) {
		(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
		_Context->s_Thing=1;
		}
	if ((_Context->p_Thing != (void *) 0)
	&& (_Context->s_Thing == 0)) {
		(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
		_Context->s_Thing=1;
		}
	_Context->trigger_Thing=visual_trigger_code(_Context->buffer_Message,strlen(_Context->buffer_Message));
	if (((_Context->status = visual_styled_element(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->buffer_ClassName,_Context->buffer_Message,strlen(_Context->buffer_Message))) != 0)
) {
	visual_button(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->fid_Thing,27,28,_Context->buffer_Message,strlen(_Context->buffer_Message),0);
	}

	return(-1);
}

public	int	cstyleman_show(struct cstyleman_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3628,_Context->y_Auto3628);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3628,_Context->y_Auto3628,810,620,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3628,_Context->y_Auto3628,810,620,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	_Context->trigger_Auto3629=visual_trigger_code(_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]));
	visual_button(_Context->x_Auto3628+760,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]),1072);
	_Context->trigger_Trash=visual_trigger_code(_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]),1072);
	if ((_Context->p_Trace != (void *) 0)
	&& (_Context->s_Trace == 0)) {
		(void)visual_buffer_get(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
		_Context->s_Trace=1;
		}
	(void) on_Trace_show(_Context);
	if (_Context->page_number == 1 ) {
	_Context->trigger_CLPage=visual_trigger_code(_Context->msg_CLPage[_Context->language],strlen(_Context->msg_CLPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_CLPage[_Context->language],strlen(_Context->msg_CLPage[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_CLPage[_Context->language],strlen(_Context->msg_CLPage[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	(void) on_ClassList_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	visual_filzone(_Context->x_CLCursor,_Context->y_CLCursor,_Context->w_CLCursor,_Context->h_CLCursor,29,16);
		}
	if (_Context->page_number == 1 ) {
	(void) on_FileList_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	(void) on_CFList_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	(void) on_CLBar_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	(void) on_MLBar_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	(void) on_FLBar_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_StylePage=visual_trigger_code(_Context->msg_StylePage[_Context->language],strlen(_Context->msg_StylePage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_StylePage[_Context->language],strlen(_Context->msg_StylePage[_Context->language]),79,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_StylePage[_Context->language],strlen(_Context->msg_StylePage[_Context->language]),79,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3628+30,_Context->y_Auto3628+90,750,510,4);
		}
	if (_Context->page_number == 2 ) {
	(void) on_StatusBar_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+140,714,48,vfh[2],16,23,_Context->msg_Auto3631[_Context->language],strlen(_Context->msg_Auto3631[_Context->language]),256);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+100,714,32,vfh[4],16,0,_Context->msg_Auto3632[_Context->language],strlen(_Context->msg_Auto3632[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+350,714,48,vfh[2],16,23,_Context->msg_Auto3633[_Context->language],strlen(_Context->msg_Auto3633[_Context->language]),256);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+420,714,48,vfh[2],16,23,_Context->msg_Auto3634[_Context->language],strlen(_Context->msg_Auto3634[_Context->language]),256);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+490,714,48,vfh[2],16,23,_Context->msg_Auto3635[_Context->language],strlen(_Context->msg_Auto3635[_Context->language]),256);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+210,714,48,vfh[2],16,23,_Context->msg_Auto3636[_Context->language],strlen(_Context->msg_Auto3636[_Context->language]),256);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+280,714,48,vfh[2],16,23,_Context->msg_Auto3637[_Context->language],strlen(_Context->msg_Auto3637[_Context->language]),256);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3628+130,_Context->y_Auto3628+160,552+2,16+2,5);
	visual_text(_Context->x_Auto3628+130+1,_Context->y_Auto3628+160+1,552,16,vfh[1],0,0,_Context->buffer_ClassName,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_LoadOperation=visual_trigger_code(_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]),1296);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),1296);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3628+130,_Context->y_Auto3628+230,552+2,16+2,5);
	visual_text(_Context->x_Auto3628+130+1,_Context->y_Auto3628+230+1,552,16,vfh[1],0,0,_Context->buffer_BaseClass,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3628+130,_Context->y_Auto3628+290,552+2,32+2,5);
	visual_text(_Context->x_Auto3628+130+1,_Context->y_Auto3628+290+1,552,32,vfh[1],0,0,_Context->buffer_Description,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3628+130,_Context->y_Auto3628+370,552+2,16+2,5);
	visual_text(_Context->x_Auto3628+130+1,_Context->y_Auto3628+370+1,552,16,vfh[1],0,0,_Context->buffer_ClassFile,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_SaveOperation=visual_trigger_code(_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]),1296);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ViewFile=visual_trigger_code(_Context->msg_ViewFile[_Context->language],strlen(_Context->msg_ViewFile[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_ViewFile[_Context->language],strlen(_Context->msg_ViewFile[_Context->language]),1296);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3628+130,_Context->y_Auto3628+440,552+2,16+2,5);
	visual_text(_Context->x_Auto3628+130+1,_Context->y_Auto3628+440+1,552,16,vfh[1],0,0,_Context->buffer_ExportName,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ExportOperation=visual_trigger_code(_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]),1296);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ViewExport=visual_trigger_code(_Context->msg_ViewExport[_Context->language],strlen(_Context->msg_ViewExport[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ViewExport[_Context->language],strlen(_Context->msg_ViewExport[_Context->language]),1296);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3628+130,_Context->y_Auto3628+510,552+2,16+2,5);
	visual_text(_Context->x_Auto3628+130+1,_Context->y_Auto3628+510+1,552,16,vfh[1],0,0,_Context->buffer_ImportName,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ImportOperation=visual_trigger_code(_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]),1296);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ViewImport=visual_trigger_code(_Context->msg_ViewImport[_Context->language],strlen(_Context->msg_ViewImport[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ViewImport[_Context->language],strlen(_Context->msg_ViewImport[_Context->language]),1296);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_TestPage=visual_trigger_code(_Context->msg_TestPage[_Context->language],strlen(_Context->msg_TestPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_TestPage[_Context->language],strlen(_Context->msg_TestPage[_Context->language]),142,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_TestPage[_Context->language],strlen(_Context->msg_TestPage[_Context->language]),142,0);
		}
	if (_Context->page_number == 3 ) {
	if ((_Context->p_Thing != (void *) 0)
	&& (_Context->s_Thing == 0)) {
		(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
		_Context->s_Thing=1;
		}
	(void) on_Thing_show(_Context);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_Cell=visual_trigger_code(_Context->msg_Cell[_Context->language],strlen(_Context->msg_Cell[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_Cell[_Context->language],strlen(_Context->msg_Cell[_Context->language]),202,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_Cell[_Context->language],strlen(_Context->msg_Cell[_Context->language]),202,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+30,_Context->y_Auto3628+90,756,512,vfh[2],31,22,_Context->msg_Auto3638[_Context->language],strlen(_Context->msg_Auto3638[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+170,602,48,vfh[2],16,23,_Context->msg_Auto3639[_Context->language],strlen(_Context->msg_Auto3639[_Context->language]),3);
		}
	if (_Context->page_number == 4 ) {
	visual_filzone(_Context->x_Auto3628+300,_Context->y_Auto3628+240,200,210,27,1);
		}
	if (_Context->page_number == 4 ) {
	visual_filzone(_Context->x_Auto3628+100,_Context->y_Auto3628+310,600,70,27,1);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+480,602,48,vfh[2],16,23,_Context->msg_Auto3642[_Context->language],strlen(_Context->msg_Auto3642[_Context->language]),3);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+250,196,48,vfh[2],16,23,_Context->msg_Auto3643[_Context->language],strlen(_Context->msg_Auto3643[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+250,182,48,vfh[2],16,23,_Context->msg_Auto3644[_Context->language],strlen(_Context->msg_Auto3644[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+110,_Context->y_Auto3628+390,182,48,vfh[2],16,23,_Context->msg_Auto3645[_Context->language],strlen(_Context->msg_Auto3645[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+110,_Context->y_Auto3628+320,182,48,vfh[2],16,23,_Context->msg_Auto3646[_Context->language],strlen(_Context->msg_Auto3646[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+250,182,48,vfh[2],16,23,_Context->msg_Auto3647[_Context->language],strlen(_Context->msg_Auto3647[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+390,182,48,vfh[2],16,23,_Context->msg_Auto3648[_Context->language],strlen(_Context->msg_Auto3648[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+320,182,48,vfh[2],16,23,_Context->msg_Auto3649[_Context->language],strlen(_Context->msg_Auto3649[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+390,182,48,vfh[2],16,23,_Context->msg_Auto3650[_Context->language],strlen(_Context->msg_Auto3650[_Context->language]),256);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+120,_Context->y_Auto3628+270,160,208,vfh[1],27,28,parse_selection(_styleman_content,&_Context->value_ct),0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+520,_Context->y_Auto3628+270,160,192,vfh[1],27,28,parse_selection(_styleman_position,&_Context->value_posv),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3628+120,_Context->y_Auto3628+410,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+120+1,_Context->y_Auto3628+410+1,72,16,vfh[1],27,0,_Context->buffer_cwv,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+410,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cwt),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+410,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+410+1,72,16,vfh[1],27,0,_Context->buffer_chv,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+410,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cht),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3628+120,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+120+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_cplv,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+340,72,176,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cplt),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+270,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+270+1,72,16,vfh[1],27,0,_Context->buffer_cptv,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_cprv,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+410,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+410+1,72,16,vfh[1],27,0,_Context->buffer_cpbv,9,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+270,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cptt),0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+340,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cprt),0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+410,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cpbt),0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_MarginPage=visual_trigger_code(_Context->msg_MarginPage[_Context->language],strlen(_Context->msg_MarginPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_MarginPage[_Context->language],strlen(_Context->msg_MarginPage[_Context->language]),256,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_MarginPage[_Context->language],strlen(_Context->msg_MarginPage[_Context->language]),256,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+30,_Context->y_Auto3628+90,756,512,vfh[2],31,19,_Context->msg_Auto3651[_Context->language],strlen(_Context->msg_Auto3651[_Context->language]),256);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+170,602,48,vfh[2],16,23,_Context->msg_Auto3652[_Context->language],strlen(_Context->msg_Auto3652[_Context->language]),3);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+480,602,48,vfh[2],16,23,_Context->msg_Auto3653[_Context->language],strlen(_Context->msg_Auto3653[_Context->language]),3);
		}
	if (_Context->page_number == 5 ) {
	visual_filzone(_Context->x_Auto3628+100,_Context->y_Auto3628+310,600,70,27,1);
		}
	if (_Context->page_number == 5 ) {
	visual_filzone(_Context->x_Auto3628+300,_Context->y_Auto3628+240,200,210,27,1);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+110,_Context->y_Auto3628+320,182,48,vfh[2],16,22,_Context->msg_Auto3656[_Context->language],strlen(_Context->msg_Auto3656[_Context->language]),256);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+320,182,48,vfh[2],16,22,_Context->msg_Auto3657[_Context->language],strlen(_Context->msg_Auto3657[_Context->language]),256);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+250,182,48,vfh[2],16,22,_Context->msg_Auto3658[_Context->language],strlen(_Context->msg_Auto3658[_Context->language]),256);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+320,182,48,vfh[2],16,22,_Context->msg_Auto3659[_Context->language],strlen(_Context->msg_Auto3659[_Context->language]),256);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+390,182,48,vfh[2],16,22,_Context->msg_Auto3660[_Context->language],strlen(_Context->msg_Auto3660[_Context->language]),256);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3628+120,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+120+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_mlv,9,0);
		}
	if (_Context->page_number == 5 ) {
	visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+340,72,192,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mlt),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_mgv,9,0);
		}
	if (_Context->page_number == 5 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+340,72,192,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mgt),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+270,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+270+1,72,16,vfh[1],27,0,_Context->buffer_mtv,9,0);
		}
	if (_Context->page_number == 5 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+270,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mtt),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_mrv,9,0);
		}
	if (_Context->page_number == 5 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+340,72,192,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mrt),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+410,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+410+1,72,16,vfh[1],27,0,_Context->buffer_mbv,9,0);
		}
	if (_Context->page_number == 5 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+410,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mbt),0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_BorderPage=visual_trigger_code(_Context->msg_BorderPage[_Context->language],strlen(_Context->msg_BorderPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_BorderPage[_Context->language],strlen(_Context->msg_BorderPage[_Context->language]),328,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_BorderPage[_Context->language],strlen(_Context->msg_BorderPage[_Context->language]),328,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+30,_Context->y_Auto3628+90,756,512,vfh[2],31,19,_Context->msg_Auto3661[_Context->language],strlen(_Context->msg_Auto3661[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+110,714,480,vfh[2],31,20,_Context->msg_Auto3662[_Context->language],strlen(_Context->msg_Auto3662[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+120,602,32,vfh[2],16,23,_Context->msg_Auto3663[_Context->language],strlen(_Context->msg_Auto3663[_Context->language]),3);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+160,196,32,vfh[2],16,23,_Context->msg_Auto3664[_Context->language],strlen(_Context->msg_Auto3664[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+300,_Context->y_Auto3628+160,196,32,vfh[2],16,23,_Context->msg_Auto3665[_Context->language],strlen(_Context->msg_Auto3665[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+160,196,32,vfh[2],16,23,_Context->msg_Auto3666[_Context->language],strlen(_Context->msg_Auto3666[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+110,_Context->y_Auto3628+170,88,160,vfh[1],27,28,parse_selection(_styleman_colours,&_Context->value_bdct),0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+210,_Context->y_Auto3628+170,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+210+1,_Context->y_Auto3628+170+1,72,16,vfh[1],16,31,_Context->buffer_bdcv,9,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+320,_Context->y_Auto3628+170,160,160,vfh[1],27,28,parse_selection(_styleman_align,&_Context->value_bdat),0);
		}
	if (_Context->page_number == 6 ) {
	visual_filzone(_Context->x_Auto3628+100,_Context->y_Auto3628+270,600,70,27,1);
		}
	if (_Context->page_number == 6 ) {
	visual_filzone(_Context->x_Auto3628+300,_Context->y_Auto3628+200,200,210,27,1);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+110,_Context->y_Auto3628+280,182,48,vfh[2],16,22,_Context->msg_Auto3669[_Context->language],strlen(_Context->msg_Auto3669[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+280,182,48,vfh[2],16,22,_Context->msg_Auto3670[_Context->language],strlen(_Context->msg_Auto3670[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+200,196,64,vfh[2],16,22,_Context->msg_Auto3671[_Context->language],strlen(_Context->msg_Auto3671[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+420,602,32,vfh[2],16,22,_Context->msg_Auto3672[_Context->language],strlen(_Context->msg_Auto3672[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+160,_Context->y_Auto3628+430,536+2,16+2,5);
	visual_text(_Context->x_Auto3628+160+1,_Context->y_Auto3628+430+1,536,16,vfh[1],27,0,_Context->buffer_blu,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+460,602,32,vfh[2],16,22,_Context->msg_Auto3673[_Context->language],strlen(_Context->msg_Auto3673[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+500,602,32,vfh[2],16,22,_Context->msg_Auto3674[_Context->language],strlen(_Context->msg_Auto3674[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+160,_Context->y_Auto3628+470,536+2,16+2,5);
	visual_text(_Context->x_Auto3628+160+1,_Context->y_Auto3628+470+1,536,16,vfh[1],27,0,_Context->buffer_btu,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+540,602,32,vfh[2],16,22,_Context->msg_Auto3675[_Context->language],strlen(_Context->msg_Auto3675[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+160,_Context->y_Auto3628+550,528+2,16+2,5);
	visual_text(_Context->x_Auto3628+160+1,_Context->y_Auto3628+550+1,528,16,vfh[1],27,0,_Context->buffer_bbu,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+160,_Context->y_Auto3628+510,528+2,16+2,5);
	visual_text(_Context->x_Auto3628+160+1,_Context->y_Auto3628+510+1,528,16,vfh[1],27,0,_Context->buffer_bru,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+350,196,64,vfh[2],16,22,_Context->msg_Auto3676[_Context->language],strlen(_Context->msg_Auto3676[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+200,196,64,vfh[2],16,22,_Context->msg_Auto3677[_Context->language],strlen(_Context->msg_Auto3677[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+350,196,64,vfh[2],16,22,_Context->msg_Auto3678[_Context->language],strlen(_Context->msg_Auto3678[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+110,_Context->y_Auto3628+220,176+2,32+2,5);
	visual_text(_Context->x_Auto3628+110+1,_Context->y_Auto3628+220+1,176,32,vfh[1],27,0,_Context->buffer_ctlu,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+220,176+2,32+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+220+1,176,32,vfh[1],27,0,_Context->buffer_ctru,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+110,_Context->y_Auto3628+370,176+2,32+2,5);
	visual_text(_Context->x_Auto3628+110+1,_Context->y_Auto3628+370+1,176,32,vfh[1],27,0,_Context->buffer_cblu,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+370,176+2,32+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+370+1,176,32,vfh[1],27,0,_Context->buffer_cbru,255,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+120,_Context->y_Auto3628+300,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+120+1,_Context->y_Auto3628+300+1,72,16,vfh[1],27,0,_Context->buffer_blv,9,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+300,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_blt),0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+320,_Context->y_Auto3628+300,160,192,vfh[1],27,0,parse_selection(_styleman_frame,&_Context->value_bdsv),0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+210,182,48,vfh[2],16,22,_Context->msg_Auto3679[_Context->language],strlen(_Context->msg_Auto3679[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+230,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+230+1,72,16,vfh[1],27,0,_Context->buffer_btv,9,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+230,72,240,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_btt),0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+280,182,48,vfh[2],16,22,_Context->msg_Auto3680[_Context->language],strlen(_Context->msg_Auto3680[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+300,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+300+1,72,16,vfh[1],27,0,_Context->buffer_brv,9,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+170,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+170+1,72,16,vfh[1],27,0,_Context->buffer_bwv,9,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+300,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_brt),0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+170,72,176,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_bwt),0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+350,182,48,vfh[2],16,22,_Context->msg_Auto3681[_Context->language],strlen(_Context->msg_Auto3681[_Context->language]),256);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+370,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+370+1,72,16,vfh[1],27,0,_Context->buffer_bbv,9,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+370,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_bbt),0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_PaddingPage=visual_trigger_code(_Context->msg_PaddingPage[_Context->language],strlen(_Context->msg_PaddingPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_PaddingPage[_Context->language],strlen(_Context->msg_PaddingPage[_Context->language]),400,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_PaddingPage[_Context->language],strlen(_Context->msg_PaddingPage[_Context->language]),400,0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+30,_Context->y_Auto3628+90,756,512,vfh[2],31,19,_Context->msg_Auto3682[_Context->language],strlen(_Context->msg_Auto3682[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+110,714,480,vfh[2],31,20,_Context->msg_Auto3683[_Context->language],strlen(_Context->msg_Auto3683[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+70,_Context->y_Auto3628+130,672,448,vfh[2],31,21,_Context->msg_Auto3684[_Context->language],strlen(_Context->msg_Auto3684[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+170,602,48,vfh[2],16,23,_Context->msg_Auto3685[_Context->language],strlen(_Context->msg_Auto3685[_Context->language]),3);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+480,602,48,vfh[2],16,23,_Context->msg_Auto3686[_Context->language],strlen(_Context->msg_Auto3686[_Context->language]),3);
		}
	if (_Context->page_number == 7 ) {
	visual_filzone(_Context->x_Auto3628+100,_Context->y_Auto3628+310,600,70,27,1);
		}
	if (_Context->page_number == 7 ) {
	visual_filzone(_Context->x_Auto3628+300,_Context->y_Auto3628+240,200,210,27,1);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+110,_Context->y_Auto3628+320,182,48,vfh[2],16,22,_Context->msg_Auto3689[_Context->language],strlen(_Context->msg_Auto3689[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+320,182,48,vfh[2],16,22,_Context->msg_Auto3690[_Context->language],strlen(_Context->msg_Auto3690[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3628+120,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+120+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_plv,9,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+340,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_plt),0);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_pgv,9,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+340,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_pgt),0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+250,182,48,vfh[2],16,22,_Context->msg_Auto3691[_Context->language],strlen(_Context->msg_Auto3691[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+270,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+270+1,72,16,vfh[1],27,0,_Context->buffer_ptv,9,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+270,72,288,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_ptt),0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+510,_Context->y_Auto3628+320,182,48,vfh[2],16,22,_Context->msg_Auto3692[_Context->language],strlen(_Context->msg_Auto3692[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3628+520,_Context->y_Auto3628+340,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+520+1,_Context->y_Auto3628+340+1,72,16,vfh[1],27,0,_Context->buffer_prv,9,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+340,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_prt),0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3628+310,_Context->y_Auto3628+390,182,48,vfh[2],16,22,_Context->msg_Auto3693[_Context->language],strlen(_Context->msg_Auto3693[_Context->language]),256);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3628+320,_Context->y_Auto3628+410,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+320+1,_Context->y_Auto3628+410+1,72,16,vfh[1],27,0,_Context->buffer_pbv,9,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+410,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_pbt),0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_BGPage=visual_trigger_code(_Context->msg_BGPage[_Context->language],strlen(_Context->msg_BGPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_BGPage[_Context->language],strlen(_Context->msg_BGPage[_Context->language]),479,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_BGPage[_Context->language],strlen(_Context->msg_BGPage[_Context->language]),479,0);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+30,_Context->y_Auto3628+90,756,512,vfh[2],31,19,_Context->msg_Auto3694[_Context->language],strlen(_Context->msg_Auto3694[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+110,714,480,vfh[2],31,20,_Context->msg_Auto3695[_Context->language],strlen(_Context->msg_Auto3695[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+70,_Context->y_Auto3628+130,672,448,vfh[2],31,21,_Context->msg_Auto3696[_Context->language],strlen(_Context->msg_Auto3696[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+90,_Context->y_Auto3628+150,630,416,vfh[2],31,22,_Context->msg_Auto3697[_Context->language],strlen(_Context->msg_Auto3697[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+170,602,48,vfh[2],16,23,_Context->msg_Auto3698[_Context->language],strlen(_Context->msg_Auto3698[_Context->language]),3);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+480,602,48,vfh[2],16,23,_Context->msg_Auto3699[_Context->language],strlen(_Context->msg_Auto3699[_Context->language]),3);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+230,602,32,vfh[2],16,23,_Context->msg_Auto3700[_Context->language],strlen(_Context->msg_Auto3700[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+410,_Context->y_Auto3628+270,294,32,vfh[2],16,23,_Context->msg_Auto3701[_Context->language],strlen(_Context->msg_Auto3701[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+410,_Context->y_Auto3628+310,294,32,vfh[2],16,23,_Context->msg_Auto3702[_Context->language],strlen(_Context->msg_Auto3702[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+270,294,32,vfh[2],16,23,_Context->msg_Auto3703[_Context->language],strlen(_Context->msg_Auto3703[_Context->language]),256);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3628+150,_Context->y_Auto3628+240,536+2,16+2,5);
	visual_text(_Context->x_Auto3628+150+1,_Context->y_Auto3628+240+1,536,16,vfh[1],16,31,_Context->buffer_bgi,255,0);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto3628+500,_Context->y_Auto3628+280,192,160,vfh[1],27,28,parse_selection(_styleman_align,&_Context->value_bgia),0);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto3628+500,_Context->y_Auto3628+320,192,80,vfh[1],27,28,parse_selection(_styleman_imagemode,&_Context->value_bgitr),0);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto3628+150,_Context->y_Auto3628+280,128,160,vfh[1],27,28,parse_selection(_styleman_colours,&_Context->value_bgct),0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3628+290,_Context->y_Auto3628+280,80+2,16+2,5);
	visual_text(_Context->x_Auto3628+290+1,_Context->y_Auto3628+280+1,80,16,vfh[1],16,31,_Context->buffer_bgcv,10,0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_ContentPage=visual_trigger_code(_Context->msg_ContentPage[_Context->language],strlen(_Context->msg_ContentPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_ContentPage[_Context->language],strlen(_Context->msg_ContentPage[_Context->language]),581,2);
	} else {
		visual_tabpage(_Context->x_Auto3628+10,_Context->y_Auto3628+50,790,560,vfh[2],_Context->msg_ContentPage[_Context->language],strlen(_Context->msg_ContentPage[_Context->language]),581,0);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+30,_Context->y_Auto3628+90,756,512,vfh[2],31,19,_Context->msg_Auto3704[_Context->language],strlen(_Context->msg_Auto3704[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+50,_Context->y_Auto3628+110,714,480,vfh[2],31,20,_Context->msg_Auto3705[_Context->language],strlen(_Context->msg_Auto3705[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+70,_Context->y_Auto3628+130,672,448,vfh[2],31,21,_Context->msg_Auto3706[_Context->language],strlen(_Context->msg_Auto3706[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+90,_Context->y_Auto3628+150,630,416,vfh[2],31,22,_Context->msg_Auto3707[_Context->language],strlen(_Context->msg_Auto3707[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+170,602,48,vfh[2],16,23,_Context->msg_Auto3708[_Context->language],strlen(_Context->msg_Auto3708[_Context->language]),3);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+230,602,32,vfh[2],16,23,_Context->msg_Auto3709[_Context->language],strlen(_Context->msg_Auto3709[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+270,294,32,vfh[2],16,23,_Context->msg_Auto3710[_Context->language],strlen(_Context->msg_Auto3710[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+410,_Context->y_Auto3628+270,294,32,vfh[2],16,23,_Context->msg_Auto3711[_Context->language],strlen(_Context->msg_Auto3711[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+310,294,112,vfh[2],16,23,_Context->msg_Auto3712[_Context->language],strlen(_Context->msg_Auto3712[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_txtol=visual_trigger_code(_Context->msg_txtol[_Context->language],strlen(_Context->msg_txtol[_Context->language]));
	visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+340,126,16,vfh[2],27,28,_Context->msg_txtol[_Context->language],strlen(_Context->msg_txtol[_Context->language]),_Context->value_txtol|0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_txtlt=visual_trigger_code(_Context->msg_txtlt[_Context->language],strlen(_Context->msg_txtlt[_Context->language]));
	visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+360,126,16,vfh[2],27,28,_Context->msg_txtlt[_Context->language],strlen(_Context->msg_txtlt[_Context->language]),_Context->value_txtlt|0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_txtul=visual_trigger_code(_Context->msg_txtul[_Context->language],strlen(_Context->msg_txtul[_Context->language]));
	visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+380,126,16,vfh[2],27,28,_Context->msg_txtul[_Context->language],strlen(_Context->msg_txtul[_Context->language]),_Context->value_txtul|0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_txtbo=visual_trigger_code(_Context->msg_txtbo[_Context->language],strlen(_Context->msg_txtbo[_Context->language]));
	visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+340,126,16,vfh[2],27,28,_Context->msg_txtbo[_Context->language],strlen(_Context->msg_txtbo[_Context->language]),_Context->value_txtbo|0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_txtsh=visual_trigger_code(_Context->msg_txtsh[_Context->language],strlen(_Context->msg_txtsh[_Context->language]));
	visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+360,126,16,vfh[2],27,28,_Context->msg_txtsh[_Context->language],strlen(_Context->msg_txtsh[_Context->language]),_Context->value_txtsh|0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_txtbl=visual_trigger_code(_Context->msg_txtbl[_Context->language],strlen(_Context->msg_txtbl[_Context->language]));
	visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+380,126,16,vfh[2],27,28,_Context->msg_txtbl[_Context->language],strlen(_Context->msg_txtbl[_Context->language]),_Context->value_txtbl|0);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+410,_Context->y_Auto3628+310,294,32,vfh[2],16,23,_Context->msg_Auto3713[_Context->language],strlen(_Context->msg_Auto3713[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+410,_Context->y_Auto3628+350,294,32,vfh[2],16,23,_Context->msg_Auto3714[_Context->language],strlen(_Context->msg_Auto3714[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+410,_Context->y_Auto3628+390,294,32,vfh[2],16,23,_Context->msg_Auto3715[_Context->language],strlen(_Context->msg_Auto3715[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto3628+100,_Context->y_Auto3628+470,602,64,vfh[2],16,23,_Context->msg_Auto3716[_Context->language],strlen(_Context->msg_Auto3716[_Context->language]),256);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto3628+150,_Context->y_Auto3628+240,536+2,16+2,5);
	visual_text(_Context->x_Auto3628+150+1,_Context->y_Auto3628+240+1,536,16,vfh[1],16,31,_Context->buffer_txfu,255,0);
		}
	if (_Context->page_number == 9 ) {
	visual_select(_Context->x_Auto3628+150,_Context->y_Auto3628+280,128,256,vfh[1],27,28,parse_selection(_styleman_colours,&_Context->value_txct),0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto3628+290,_Context->y_Auto3628+280,72+2,16+2,5);
	visual_text(_Context->x_Auto3628+290+1,_Context->y_Auto3628+280+1,72,16,vfh[1],16,31,_Context->buffer_txcv,9,0);
		}
	if (_Context->page_number == 9 ) {
	visual_select(_Context->x_Auto3628+500,_Context->y_Auto3628+280,192,208,vfh[1],27,28,parse_selection(_styleman_align,&_Context->value_txta),0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto3628+500,_Context->y_Auto3628+320,96+2,16+2,5);
	visual_text(_Context->x_Auto3628+500+1,_Context->y_Auto3628+320+1,96,16,vfh[1],27,0,_Context->buffer_ltspv,12,0);
		}
	if (_Context->page_number == 9 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+320,80,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_ltspt),0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto3628+500,_Context->y_Auto3628+360,96+2,16+2,5);
	visual_text(_Context->x_Auto3628+500+1,_Context->y_Auto3628+360+1,96,16,vfh[1],27,0,_Context->buffer_wspv,12,0);
		}
	if (_Context->page_number == 9 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+360,80,112,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_wspt),0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto3628+500,_Context->y_Auto3628+400,96+2,16+2,5);
	visual_text(_Context->x_Auto3628+500+1,_Context->y_Auto3628+400+1,96,16,vfh[1],27,0,_Context->buffer_lnspv,12,0);
		}
	if (_Context->page_number == 9 ) {
	visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+400,80,64,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_lnspt),0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto3628+110,_Context->y_Auto3628+490,576+2,32+2,5);
	visual_text(_Context->x_Auto3628+110+1,_Context->y_Auto3628+490+1,576,32,vfh[1],0,0,_Context->buffer_Message,255,0);
		}
	visual_thaw(_Context->x_Auto3628,_Context->y_Auto3628,810,620);

	return(0);
}

private int Auto3629_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This button may be actioned to leave the style editor.   ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Trash_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The trash can push button icon may be used in conjunction with elements ";
			mptr[1]="selected from class or class file lists. The element may be draged ";
			mptr[2]="and dropped on to the trash can to be deleted.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Trace_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]="This button is displayed when errors have been encountered by the ";
			mptr[3]="style parser during style class file parsing operations performed ";
			mptr[4]="during the current sing session.   ";
			mptr[5]=" ";
			mptr[6]="Errors encountered are collected and added to this error trace which ";
			mptr[7]="may be consulted using standard text file tracing techniques for the ";
			mptr[8]="correction of the offending instructions or expressions.  ";
			mptr[9]=" ";
			mptr[10]="A drag and drop action to the trashcan may be performed in order to ";
			mptr[11]="release the current style error trace and reset the mechanism.  ";
			mptr[12]=" ";
			mptr[13]="       ";
			return(visual_online_help(mptr,14));
			}
			break;
		case 1 : 
			{
			char * mptr[1];
			mptr[0] = "  ";
			return(visual_online_help(mptr,1));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CLPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page page presents the three different lists managed by the ";
			mptr[1]="style editor allowing selection of classes and class files for inspection, ";
			mptr[2]="modification  and generation in the following pages of the style editor. ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ClassList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This control presents the complete list of style classes, loaded into ";
			mptr[1]="the low level style application subsystem, for selection using the ";
			mptr[2]="mouse. The left hand column displays the class name whilst the right ";
			mptr[3]="hand column shows the name of an eventual bas class.     ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This list component displays the names of style files that have been ";
			mptr[1]="loaded  by the low level style mechanisms. When an entry is selected ";
			mptr[2]="in this list le collection of style classes that were loaded from ";
			mptr[3]="the corresponding class file are displayed in the left hand list of ";
			mptr[4]="classes.    ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CFList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This list displays the collection of style classes of the style file ";
			mptr[1]="currently selected in the style filenames list to the right.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int StylePage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page presents the name of the current class loaded into the ";
			mptr[1]="class editor definition fields. Other edit fields allow file names ";
			mptr[2]="to be specified for the various operations proposed by the buttons ";
			mptr[3]="offered on this page.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ClassName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field defines the name of the style class currently loading ";
			mptr[1]="into the various fields of the style editor.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Ce champs de saisie d‚finit le nom de la classe de style charg‚ actuellement ";
			mptr[1]="dans les divers champs de l'‚diteur de style.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LoadOperation_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This push button may be actioned to reload the style editor property ";
			mptr[1]="description  fields from the low level visual style application manager. ";
			mptr[2]="This may be necessary in order to restore the original style definition ";
			mptr[3]="after modifications have been made to style editor fields.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Reset_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This button may be actioned to reset all property description fields ";
			mptr[1]=" of the style editor to their initial default values.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BaseClass_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field displays and defines the name of the class from which ";
			mptr[1]="the  current class is defined. All fields of this base class will ";
			mptr[2]="be read into the  style container prior being overloaded by the various ";
			mptr[3]="individual definitions  of the style editor fields.      ";
			return(visual_online_help(mptr,4));
			}
			break;
		case 1 : 
			{
			char * mptr[4];
			mptr[0] = "Ce champs de saisie permet la d‚finition d'un nom de classe de base ";
			mptr[1]="pour la classe courante. Toutes les champs de d‚finition de cette ";
			mptr[2]="classe de base se voient charg‚ avant de se faire surcharger par les ";
			mptr[3]="d‚finitions de la classe en cours.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Description_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows a textual description of the style class to ";
			mptr[1]="be  specified.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ClassFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows a filename to be specified to which the currently ";
			mptr[1]="loaded style class description is to be written and saved.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SaveOperation_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This pushbutton allows the current contents of the style editor property ";
			mptr[1]="description fileds to be generated, using visual style class instructions, ";
			mptr[2]="to the file identified by the contents of the edit field ClassFile.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ViewFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Action this button to open the ClassFile style file for inspection ";
			mptr[1]="and eventual modification using the standard abal text editor.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ExportName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field provides the name of the classfile defining the collection ";
			mptr[1]="of styles classes to be updated to disk. These style class collections ";
			mptr[2]="are described on the preceeding page.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ExportOperation_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This pushbutton allows the collection of style class descriptions ";
			mptr[1]="associated with the style filename  identified by the contents of ";
			mptr[2]="the edit field ExportFile to be generated, using visual style class instructions ";
			mptr[3]="to the corresponding style file.     ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ViewExport_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Action this button to open the ExportFile style file for inspection ";
			mptr[1]="and eventual modification using the standard abal text editor.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImportName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows the name of the file to be specified from which ";
			mptr[1]="the import operation will load all style class descriptions. The collection ";
			mptr[2]="of style classes loaded in this way will form a collection associated ";
			mptr[3]="with the  import filename.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImportOperation_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "When this button is actioned, the collection of style class descriptions ";
			mptr[1]="contained in the file, named by the value of the ImportFile edit field, will be loaded into the low level style application ";
			mptr[2]="subsystem. The collection of classes will be associated with the filename ";
			mptr[3]="from which they are loaded in the appropriate list of thepreceeding ";
			mptr[4]="page.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ViewImport_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Action this button to open the ImportFile style file for inspection ";
			mptr[1]="and eventual modification using the standard abal text editor.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TestPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page allows the visual effect of the current style class ";
			mptr[1]="definition to be  inspected. This is performed by the application ";
			mptr[2]="of the style class using a  VisualStyle instruction for visualisation of the overall effect.  ";
			mptr[3]="  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Cell_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This tab page provides edit and selection controls for consultation ";
			mptr[1]="and modification of the various style properties relating to the overall ";
			mptr[2]="style cell, its position and dimensions.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ct_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control allows the cell content specialisation to be defined. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int posv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This control allows selection of a value for the style cell position ";
			mptr[1]="property. The various values offered here influence the position of ";
			mptr[2]="the cell working in conjunction with the top,left,right,bottom float ";
			mptr[3]="or deplacement values and the style cell dimensions provided by the ";
			mptr[4]="width and height properties.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cwv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to be used to define ";
			mptr[1]="the width of  the style cell.The nature or the metric of this valus ";
			mptr[2]="is described by the select component to the right of the edit field. ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cwt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding style cell width value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int chv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to be used to define ";
			mptr[1]="the height of  the style cell.The nature or the metric of this valus ";
			mptr[2]="is described by the select component to the right of the edit field. ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cht_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding style cell height value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cplv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to be represent the ";
			mptr[1]="distance of the left of the style cell from the left edge of the output ";
			mptr[2]="device or zone. The nature or the metric of this valus is described ";
			mptr[3]="by the select component to the right of the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cplt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding left margin value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cptv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to be represent the ";
			mptr[1]="distance of the top of the style cell from the top edge of the output ";
			mptr[2]="device or zone. The nature or the metric of this valus is described ";
			mptr[3]="by the select component to the right of the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cprv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to be represent the ";
			mptr[1]="distance of the right of the style cell from the right edge of the ";
			mptr[2]="output device or zone. The nature or the metric of this valus is described ";
			mptr[3]="by the select component to the right of the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cpbv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to be represent the ";
			mptr[1]="distance of the bottom of the style cell from the bottom edge of the ";
			mptr[2]="output device or zone. The nature or the metric of this valus is described ";
			mptr[3]="by the select component to the right of the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cptt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding top margin value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cprt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding right margin value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cpbt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding bottom margin value edit field.  ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MarginPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page provides edit and selection controls for consultation ";
			mptr[1]="and modification of the various style properties describing the margin ";
			mptr[2]=" of the style cell. The margin is outermost region of the style cell ";
			mptr[3]="definition.      ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mlv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]="value of the left margin of the style cell.The nature or the metric ";
			mptr[2]="of this valus is  described by the select component to the right of ";
			mptr[3]="the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mlt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding left margin value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mgv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the default ";
			mptr[1]="value of all margins of the style cell.The nature or the metric of ";
			mptr[2]="this valus is  described by the select component to the right of the ";
			mptr[3]="edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mgt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding general margin value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mtv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]="value of the top margin of the style cell.The nature or the metric ";
			mptr[2]="of this valus is  described by the select component to the right of ";
			mptr[3]="the edit field.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mtt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding top margin value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mrv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]="value of the right margin of the style cell.The nature or the metric ";
			mptr[2]="of this valus is  described by the select component to the right of ";
			mptr[3]="the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mrt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding right margin value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mbv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]="value of the bottom margin of the style cell.The nature or the metric ";
			mptr[2]="of this valus is  described by the select component to the right of ";
			mptr[3]="the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int mbt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding bottom margin value edit field.  ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BorderPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page provides edit and selection controls for consultation ";
			mptr[1]="and modification of the various style properties describing the border ";
			mptr[2]="of the style cell. The border is surrounded by the cell margin.   ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bdct_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of a colour type to be used for the ";
			mptr[1]="display of  certain coloured style borders, solid, double, etc.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bdcv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the value component of certain colour types ";
			mptr[1]="to be specified as required by the preceeding colour type selection ";
			mptr[2]="control.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bdat_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This control allows selection of the value to be used in conjunction ";
			mptr[1]="with  the various border and corner image url values for the alignement, ";
			mptr[2]="tiling, stretch/squash operation during display of their corresponding ";
			mptr[3]="images.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int blu_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the left hand border of the current style cell definition. ";
			mptr[2]="   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int btu_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the top border of the current style cell definition. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bbu_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the bottom border of the current style cell definition. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bru_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the right hand border of the current style cell ";
			mptr[2]="definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ctlu_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the top left corner of the the border for the current ";
			mptr[2]="style cell definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ctru_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the top right corner of the the border for the current ";
			mptr[2]="style cell definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cblu_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the bottom left corner of the the border for the ";
			mptr[2]="current style cell definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int cbru_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used, when the border style has been set to url, to represent the bottom right corner of the the border for the ";
			mptr[2]="current style cell definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int blv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the left hand border of the style cell. The nature or the metric ";
			mptr[2]="of this valus is  described by the select component to the right of ";
			mptr[3]="the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int blt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding left border width value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bdsv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or type of border to be ";
			mptr[1]="used by the current style cell definition.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int btv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the top border of the style cell. The nature or the metric of ";
			mptr[2]="this valus is  described by the select component to the right of the ";
			mptr[3]="edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int btt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding top border width value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int brv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the right hand border of the style cell. The nature or the metric ";
			mptr[2]="of this valus is  described by the select component to the right of ";
			mptr[3]="the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bwv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to be used as the default ";
			mptr[1]="width  of the border of the style cell. The nature or the metric of ";
			mptr[2]="this valus is  described by the select component to the right of the ";
			mptr[3]="edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int brt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding right border width value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bwt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding default border width value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bbv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the bottom border of the style cell. The nature or the metric ";
			mptr[2]="of this valus is  described by the select component to the right of ";
			mptr[3]="the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bbt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding bottom border width value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PaddingPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page provides edit and selection controls for consultation ";
			mptr[1]="and modification of the various style properties describing the content ";
			mptr[2]="padding of the style cell. Content padding is between the border and ";
			mptr[3]="the cell content.      ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int plv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the content padding between the left hand border and the left ";
			mptr[2]="edge  of the style cell content region. The nature or the metric of ";
			mptr[3]="this valus is  described by the select component to the right of the ";
			mptr[4]="edit field.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int plt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding left hand content padding value edit ";
			mptr[2]="field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int pgv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the content padding to be used by default between the border and ";
			mptr[2]=" the edges of the style cell content region.  The nature or the metric ";
			mptr[3]="of this valus is  described by the select component to the right of ";
			mptr[4]="the edit field.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int pgt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding general content padding value edit ";
			mptr[2]="field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ptv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the content padding between the top border and the top of the ";
			mptr[2]="style cell contents. The nature or the metric of this valus is  described ";
			mptr[3]="by the select component to the right of the edit field.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ptt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding top content padding value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int prv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the content padding between the right hand border and the right ";
			mptr[2]="edge  of the style cell content region. The nature or the metric of ";
			mptr[3]="this valus is  described by the select component to the right of the ";
			mptr[4]="edit field.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int prt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding right hand content padding value ";
			mptr[2]="edit field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int pbv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows a value to be specified to determine the width ";
			mptr[1]=" of the content padding between the bottom border and the bottom of ";
			mptr[2]="the style cell content region. The nature or the metric of this valus ";
			mptr[3]="is  described by the select component to the right of the edit field. ";
			mptr[4]="  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int pbt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding bottom content padding value edit ";
			mptr[2]="field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BGPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page provides edit and selection controls for consultation ";
			mptr[1]="and modification of the various style properties describing the background ";
			mptr[2]="of the style cell. The background and the content occupy the same ";
			mptr[3]="innermost region inside of the content padding region.       ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bgi_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the name of an image to be specified to be ";
			mptr[1]="used,  as the background image of the style cell content region.  ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bgia_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the value to be used in conjunction ";
			mptr[1]="with  the background image url value for the alignement, tiling, stretch/squash ";
			mptr[2]="operation during display of the style cell content background.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bgitr_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the value to be used in conjunction ";
			mptr[1]="with  the background image url allowing for the display of transparent ";
			mptr[2]="or opaque  style cell content background images.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bgct_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of a colour type to be used for the ";
			mptr[1]="display of  content region background.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int bgcv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the value component of certain colour types ";
			mptr[1]="to be specified as required by the preceeding colour type selection ";
			mptr[2]="control.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ContentPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page provides edit and selection controls for consultation ";
			mptr[1]="and modification of the various style properties describing the content ";
			mptr[2]="of the style cell. The background and the content occupy the same ";
			mptr[3]="innermost region inside of the content padding region.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txtol_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control, when checked, activates the overline decoration attribut ";
			mptr[1]="for the display of textual content by the current style definition. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txtlt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control, when checked, activates the line-through decoration ";
			mptr[1]="attribut for the display of textual content by the current style definition. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txtul_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control, when checked, activates the underline decoration attribut ";
			mptr[1]="for the display of textual content by the current style definition. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txtbo_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control, when checked, activates the bold decoration attribut ";
			mptr[1]="for the display of textual content by the current style definition. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txtsh_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control, when checked, activates the shadow decoration attribut ";
			mptr[1]="for the display of textual content by the current style definition. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txtbl_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control, when checked, activates the blinking decoration attribut ";
			mptr[1]="for the display of textual content by the current style definition. ";
			mptr[2]="Blinking text is not currently available in graphical mode.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txfu_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This editfield allows the font filename to be specified of the font ";
			mptr[1]="to be used  for the display of style cell content text by the current ";
			mptr[2]="style definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txct_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of a colour type to be used for the ";
			mptr[1]="display of  content region text characters.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txcv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the value component of certain colour types ";
			mptr[1]="to be specified as required by the preceeding colour type selection ";
			mptr[2]="control.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int txta_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of analignement value to be used for ";
			mptr[1]="the  display of content text by the current style definition.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ltspv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows a value to be specified to be used to define ";
			mptr[1]="the letter spacing of content text displayed by the current style ";
			mptr[2]="definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ltspt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding letter spacing value edit field. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int wspv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows a value to be specified to be used to define ";
			mptr[1]="the inter word spacing of content text displayed by the current style ";
			mptr[2]="definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int wspt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding word spacing value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int lnspv_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows a value to be specified to be used to define ";
			mptr[1]="the inter line spacing of content text displayed by the current style ";
			mptr[2]="definition.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int lnspt_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This control allows selection of the nature or metric to be used in ";
			mptr[1]="conjunction  with the preceeding line spacing value edit field.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Message_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows a text message to be specified to be used by ";
			mptr[1]="the  style definition testing tab page.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3628action(struct cstyleman_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			cstyleman_hide(_Context);

		_Context->x_Auto3628 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3628 < 0) { _Context->x_Auto3628=0; }
		_Context->y_Auto3628 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3628 < 0) { _Context->y_Auto3628=0; }
			cstyleman_show(_Context);

		visual_thaw(_Context->x_Auto3628,_Context->y_Auto3628,810,620);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Auto3629_event(struct cstyleman_context * _Context) {
	return(27);
	return(-1);
}
private int on_Trace_event(struct cstyleman_context * _Context) {
	if(consult_style_trace()){
	memset(_Context->buffer_Action,' ',255);
	strcpy(_Context->buffer_Action,_Context->hint_Trace[_Context->language]);
	switch(on_Action_event(_Context)){
	case 3:
	release_style_trace();
	on_Trace_show(_Context);
	break;
	case 4:
		cstyleman_hide(_Context);
;
	inspect_style_trace();
		cstyleman_show(_Context);

	break;
	}
	}
	else{
		if ((_Context->p_Trace != (void *) 0)
	&& (_Context->s_Trace != 0)) {
		(void)visual_buffer_put(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
		_Context->s_Trace=0;
		}
;
	}
	return(-1);
}
private int on_ClassList_event(struct cstyleman_context * _Context) {
	int l;
	struct element_style*eptr;
	struct element_style*resolve_style_number(int);
	struct element_file*resolve_stylefile_number(int);
	struct element_file*fptr;
	l=_Context->value_ClassList;
	if(l>0){
	if((eptr=resolve_style_number(l+_Context->value_CLBar))!=(struct element_style*)0){
	if(eptr->name!=(char*)0){
	memset(_Context->buffer_Action,' ',255);
	strcpy(_Context->buffer_Action,eptr->name);
	switch(on_Action_event(_Context)){
	case 3:
	drop_visual_style(eptr->name,strlen(eptr->name));
		cstyleman_show(_Context);
;
	break;
	case 8:
	if((fptr=resolve_stylefile_number(_Context->value_FileList+_Context->value_FLBar))!=(struct element_file*)0){
	style_file_class(fptr,eptr);
		cstyleman_show(_Context);
;
	}
	break;
	default:
	strcpy(_Context->buffer_ClassName,eptr->name);
	on_LoadOperation_event(_Context);
		/* StylePage */
	cstyleman_losefocus(_Context);
	_Context->page_number = 2;
	cstyleman_show(_Context);
	_Context->focus_item=12;
;
	break;
	}
	}
	}
	}
	return(-1);
}
private int on_Action_event(struct cstyleman_context * _Context) {
	int k;
	/*_Context->w_Action=((strlen(_Context->buffer_Action)+3)*8);*/
	while(1){
	_Context->x_Action=visual_event(7);
	_Context->y_Action=visual_event(6);
		if ((_Context->p_Action != (void *) 0)
	&& (_Context->s_Action == 0)) {
		(void)visual_buffer_get(_Context->p_Action,_Context->x_Action,_Context->y_Action);
		_Context->s_Action=1;
		}
	if ((_Context->p_Action != (void *) 0)
	&& (_Context->s_Action == 0)) {
		(void)visual_buffer_get(_Context->p_Action,_Context->x_Action,_Context->y_Action);
		_Context->s_Action=1;
		}
visual_frame(_Context->x_Action,_Context->y_Action,_Context->w_Action+2,_Context->h_Action+2,5);
visual_text(_Context->x_Action+1,_Context->y_Action+1,_Context->w_Action,_Context->h_Action,_Context->fid_Action,0,0,_Context->buffer_Action,255,3);
;
	k=visual_getch();
		if ((_Context->p_Action != (void *) 0)
	&& (_Context->s_Action != 0)) {
		(void)visual_buffer_put(_Context->p_Action,_Context->x_Action,_Context->y_Action);
		_Context->s_Action=0;
		}
;
	if((k==256)
	&&(visual_event(1)==_MIMO_UP))
	return(cstyleman_event(_Context));
	}
	return(-1);
}
private int on_FileList_event(struct cstyleman_context * _Context) {
	int l;
	int n;
	struct element_file*fptr;
	struct element_file*resolve_stylefile_number(int);
	l=_Context->value_FileList;
	if(l>0){
	if((fptr=resolve_stylefile_number(l+_Context->value_FLBar))!=(struct element_file*)0){
	if(fptr->name!=(char*)0){
	memset(_Context->buffer_Action,' ',255);
	strcpy(_Context->buffer_Action,fptr->name);
	switch(on_Action_event(_Context)){
	case 3:
	drop_style_file(fptr->name);
	default:
		cstyleman_show(_Context);
;
	}
	}
	}
	}
	return(-1);
}
private int on_CFList_event(struct cstyleman_context * _Context) {
	int l;
	struct element_file*fptr;
	struct element_file*resolve_stylefile_number(int);
	struct element_style*eptr;
	struct element_style*resolve_style_number(int);
	struct element_class*cptr;
	struct element_class*resolve_stylefile_member(struct element_file*,int);
	l=_Context->value_CFList;
	if(l>0){
	if((fptr=resolve_stylefile_number(_Context->value_FileList+_Context->value_FLBar))!=(struct element_file*)0){
	if((cptr=resolve_stylefile_member(fptr,l+_Context->value_MLBar))!=(struct element_class*)0){
	if((eptr=cptr->style)!=(struct element_style*)0){
	if(eptr->name!=(char*)0){
	strcpy(_Context->buffer_ClassName,eptr->name);
	on_LoadOperation_event(_Context);
		/* StylePage */
	cstyleman_losefocus(_Context);
	_Context->page_number = 2;
	cstyleman_show(_Context);
	_Context->focus_item=12;
;
	}
	}
	}
	}
	}
	return(-1);
}
private int on_CLBar_event(struct cstyleman_context * _Context) {
	on_ClassList_show(_Context);
	return(-1);
}

private int on_CLBar_action(struct cstyleman_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3628+90+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_CLBar -= 1;
		if (_Context->value_CLBar < 0) 
			_Context->value_CLBar = 0;
		(void) on_CLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3628+90+250-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_CLBar += 1;
		if (!(_Context->max_CLBar))
			_Context->value_CLBar = 0;
		else if ((_Context->max_CLBar < _Context->limit_CLBar) 
		&& (_Context->value_CLBar >= _Context->max_CLBar)) 
			_Context->value_CLBar = (_Context->max_CLBar-1);
		else if (_Context->value_CLBar > (_Context->max_CLBar-_Context->limit_CLBar)) 
			_Context->value_CLBar = (_Context->max_CLBar-_Context->limit_CLBar);
		(void) on_CLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_CLBar;
		_Context->value_CLBar = (((visual_event(6) - (_Context->y_Auto3628+90+20)) * _Context->max_CLBar) / (250 - (2 * 20)));
		if (_Context->value_CLBar < 0) 
			_Context->value_CLBar = 0;
		else if (_Context->value_CLBar > (_Context->max_CLBar-_Context->limit_CLBar)) 
			_Context->value_CLBar = (_Context->max_CLBar-_Context->limit_CLBar);
		if (_Context->value_CLBar != aty) {
		(void) on_CLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_CLBar -= (_Context->limit_CLBar/2);
			if (_Context->value_CLBar < 0) 
				_Context->value_CLBar = 0;
		(void) on_CLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_CLBar += (_Context->limit_CLBar/2);
			if (!(_Context->max_CLBar))
				_Context->value_CLBar = 0;
			else if ((_Context->max_CLBar < _Context->limit_CLBar) 
			&& (_Context->value_CLBar >= _Context->max_CLBar)) 
				_Context->value_CLBar = (_Context->max_CLBar-1);
			else if (_Context->value_CLBar > (_Context->max_CLBar-_Context->limit_CLBar)) 
				_Context->value_CLBar = (_Context->max_CLBar-_Context->limit_CLBar);
		(void) on_CLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+90,20,250,vfh[1],0,0,_Context->value_CLBar,_Context->limit_CLBar,_Context->max_CLBar,259);

	return(1);
}
private int on_MLBar_event(struct cstyleman_context * _Context) {
	on_CFList_show(_Context);
	return(-1);
}

private int on_MLBar_action(struct cstyleman_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3628+340+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_MLBar -= 1;
		if (_Context->value_MLBar < 0) 
			_Context->value_MLBar = 0;
		(void) on_MLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3628+340+260-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_MLBar += 1;
		if (!(_Context->max_MLBar))
			_Context->value_MLBar = 0;
		else if ((_Context->max_MLBar < _Context->limit_MLBar) 
		&& (_Context->value_MLBar >= _Context->max_MLBar)) 
			_Context->value_MLBar = (_Context->max_MLBar-1);
		else if (_Context->value_MLBar > (_Context->max_MLBar-_Context->limit_MLBar)) 
			_Context->value_MLBar = (_Context->max_MLBar-_Context->limit_MLBar);
		(void) on_MLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_MLBar;
		_Context->value_MLBar = (((visual_event(6) - (_Context->y_Auto3628+340+20)) * _Context->max_MLBar) / (260 - (2 * 20)));
		if (_Context->value_MLBar < 0) 
			_Context->value_MLBar = 0;
		else if (_Context->value_MLBar > (_Context->max_MLBar-_Context->limit_MLBar)) 
			_Context->value_MLBar = (_Context->max_MLBar-_Context->limit_MLBar);
		if (_Context->value_MLBar != aty) {
		(void) on_MLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_MLBar -= (_Context->limit_MLBar/2);
			if (_Context->value_MLBar < 0) 
				_Context->value_MLBar = 0;
		(void) on_MLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_MLBar += (_Context->limit_MLBar/2);
			if (!(_Context->max_MLBar))
				_Context->value_MLBar = 0;
			else if ((_Context->max_MLBar < _Context->limit_MLBar) 
			&& (_Context->value_MLBar >= _Context->max_MLBar)) 
				_Context->value_MLBar = (_Context->max_MLBar-1);
			else if (_Context->value_MLBar > (_Context->max_MLBar-_Context->limit_MLBar)) 
				_Context->value_MLBar = (_Context->max_MLBar-_Context->limit_MLBar);
		(void) on_MLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3628+370,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_MLBar,_Context->limit_MLBar,_Context->max_MLBar,259);

	return(1);
}
private int on_FLBar_event(struct cstyleman_context * _Context) {
	on_FileList_show(_Context);
	return(-1);
}

private int on_FLBar_action(struct cstyleman_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3628+340+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_FLBar -= 1;
		if (_Context->value_FLBar < 0) 
			_Context->value_FLBar = 0;
		(void) on_FLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3628+340+260-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_FLBar += 1;
		if (!(_Context->max_FLBar))
			_Context->value_FLBar = 0;
		else if ((_Context->max_FLBar < _Context->limit_FLBar) 
		&& (_Context->value_FLBar >= _Context->max_FLBar)) 
			_Context->value_FLBar = (_Context->max_FLBar-1);
		else if (_Context->value_FLBar > (_Context->max_FLBar-_Context->limit_FLBar)) 
			_Context->value_FLBar = (_Context->max_FLBar-_Context->limit_FLBar);
		(void) on_FLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_FLBar;
		_Context->value_FLBar = (((visual_event(6) - (_Context->y_Auto3628+340+20)) * _Context->max_FLBar) / (260 - (2 * 20)));
		if (_Context->value_FLBar < 0) 
			_Context->value_FLBar = 0;
		else if (_Context->value_FLBar > (_Context->max_FLBar-_Context->limit_FLBar)) 
			_Context->value_FLBar = (_Context->max_FLBar-_Context->limit_FLBar);
		if (_Context->value_FLBar != aty) {
		(void) on_FLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);
			}
			}
		}
	while (visual_event(1) != _MIMO_UP);
	switch( visual_event(2) ) {
		case _MIMO_WHEELUP   :
			_Context->value_FLBar -= (_Context->limit_FLBar/2);
			if (_Context->value_FLBar < 0) 
				_Context->value_FLBar = 0;
		(void) on_FLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_FLBar += (_Context->limit_FLBar/2);
			if (!(_Context->max_FLBar))
				_Context->value_FLBar = 0;
			else if ((_Context->max_FLBar < _Context->limit_FLBar) 
			&& (_Context->value_FLBar >= _Context->max_FLBar)) 
				_Context->value_FLBar = (_Context->max_FLBar-1);
			else if (_Context->value_FLBar > (_Context->max_FLBar-_Context->limit_FLBar)) 
				_Context->value_FLBar = (_Context->max_FLBar-_Context->limit_FLBar);
		(void) on_FLBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3628+770,_Context->y_Auto3628+340,20,260,vfh[1],0,0,_Context->value_FLBar,_Context->limit_FLBar,_Context->max_FLBar,259);

	return(1);
}
private int on_ExportNameError_event(struct cstyleman_context * _Context) {
	strcpy(_Context->buffer_StatusBar,_Context->msg_ExportNameError[_Context->language]);
	visual_frame(_Context->x_Auto3628+50,_Context->y_Auto3628+560,712+2,16+2,5);
visual_text(_Context->x_Auto3628+50+1,_Context->y_Auto3628+560+1,712,16,vfh[2],31,2,_Context->buffer_StatusBar,255,3);
;
	return(visual_getch());
	return(-1);
}
private int on_LoadOperation_event(struct cstyleman_context * _Context) {
	struct element_style*resolve_style_class(char*);
	struct element_style*eptr;
	if((eptr=resolve_style_class(_Context->buffer_ClassName))!=(struct element_style*)0){
	LoadClass(_Context, eptr);
		cstyleman_show(_Context);
;
	eptr=(struct element_style*)0;
	}
		return(-1);
}
private int on_Reset_event(struct cstyleman_context * _Context) {
	ResetClass(_Context);
		cstyleman_show(_Context);
;
	return(-1);
}
private int on_SaveOperation_event(struct cstyleman_context * _Context) {
	char xnomfic[512];
	int i;
	for(i=0;*(_Context->buffer_ClassFile+i)!=' ';i++)
	xnomfic[i]=*(_Context->buffer_ClassFile+i);
	xnomfic[i]=0;
	ExportCss(_Context, xnomfic);
	return(-1);
}
private int on_ViewFile_event(struct cstyleman_context * _Context) {
		cstyleman_hide(_Context);
;
	edit_style_file(_Context->buffer_ClassFile,255);
		cstyleman_show(_Context);
;
	return(-1);
}
private int on_ExportOperation_event(struct cstyleman_context * _Context) {
	char holdname[255+1];
	char xnomfic[512];
	int i;
	memcpy(holdname,_Context->buffer_ClassName,255);
	for(i=0;*(_Context->buffer_ExportName+i)!=' ';i++)
	xnomfic[i]=*(_Context->buffer_ExportName+i);
	xnomfic[i]=0;
	if(!(i)){
	on_ExportNameError_event(_Context);
	memcpy(_Context->buffer_ClassName,holdname,255);
	}
	else{
	ExportCollection(_Context, xnomfic);
	memcpy(_Context->buffer_ClassName,holdname,255);
	on_LoadOperation_event(_Context);
	}
	return(-1);
}
private int on_ViewExport_event(struct cstyleman_context * _Context) {
		cstyleman_hide(_Context);
;
	edit_style_file(_Context->buffer_ExportName,255);
		cstyleman_show(_Context);
;
	return(-1);
}
private int on_ImportOperation_event(struct cstyleman_context * _Context) {
	int i;
	char nomfic[257];
	for(i=0;i<256;i++){
	if(*(_Context->buffer_ImportName+i)==' ')
	break;
	else nomfic[i]=*(_Context->buffer_ImportName+i);
	}
	nomfic[i]=0;
	if(i>0){
	load_visual_style(nomfic,i);
		/* CLPage */
	cstyleman_losefocus(_Context);
	_Context->page_number = 1;
	cstyleman_show(_Context);
	_Context->focus_item=5;
;
	}
	return(-1);
}
private int on_ViewImport_event(struct cstyleman_context * _Context) {
		cstyleman_hide(_Context);
;
	edit_style_file(_Context->buffer_ImportName,255);
		cstyleman_show(_Context);
;
	return(-1);
}
private int on_Thing_event(struct cstyleman_context * _Context) {
	while(1){
	if((visual_event(3)>_Context->y_Thing)
	&&(visual_event(4)>_Context->x_Thing)){
		if ((_Context->p_Thing != (void *) 0)
	&& (_Context->s_Thing != 0)) {
		(void)visual_buffer_put(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
		_Context->s_Thing=0;
		}
;
	_Context->w_Thing=(visual_event(4)-_Context->x_Thing);
	_Context->h_Thing=(visual_event(3)-_Context->y_Thing);
		if ((_Context->p_Thing != (void *) 0)
	&& (_Context->s_Thing == 0)) {
		(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
		_Context->s_Thing=1;
		}
	if ((_Context->p_Thing != (void *) 0)
	&& (_Context->s_Thing == 0)) {
		(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
		_Context->s_Thing=1;
		}
	_Context->trigger_Thing=visual_trigger_code(_Context->buffer_Message,strlen(_Context->buffer_Message));
	if (((_Context->status = visual_styled_element(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->buffer_ClassName,_Context->buffer_Message,strlen(_Context->buffer_Message))) != 0)
) {
	visual_button(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->fid_Thing,27,28,_Context->buffer_Message,strlen(_Context->buffer_Message),0);
	}

	}
	if(visual_event(1)==_MIMO_UP)
	break;
	while(visual_getch()!=256);
	}
	return(-1);
}


public	int	cstyleman_event(
struct cstyleman_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3629 == mb ) return(2);
		if (_Context->trigger_Trash == mb ) return(3);
		if (_Context->trigger_Trace == mb ) return(4);
		if (_Context->trigger_CLPage == mb ) return(5);
		if (_Context->trigger_StylePage == mb ) return(12);
		if (_Context->trigger_LoadOperation == mb ) return(14);
		if (_Context->trigger_Reset == mb ) return(15);
		if (_Context->trigger_SaveOperation == mb ) return(19);
		if (_Context->trigger_ViewFile == mb ) return(20);
		if (_Context->trigger_ExportOperation == mb ) return(22);
		if (_Context->trigger_ViewExport == mb ) return(23);
		if (_Context->trigger_ImportOperation == mb ) return(25);
		if (_Context->trigger_ViewImport == mb ) return(26);
		if (_Context->trigger_TestPage == mb ) return(27);
		if (_Context->trigger_Thing == mb ) return(28);
		if (_Context->trigger_Cell == mb ) return(29);
		if (_Context->trigger_MarginPage == mb ) return(44);
		if (_Context->trigger_BorderPage == mb ) return(55);
		if (_Context->trigger_PaddingPage == mb ) return(78);
		if (_Context->trigger_BGPage == mb ) return(89);
		if (_Context->trigger_ContentPage == mb ) return(95);
		if (_Context->trigger_txtol == mb ) return(96);
		if (_Context->trigger_txtlt == mb ) return(97);
		if (_Context->trigger_txtul == mb ) return(98);
		if (_Context->trigger_txtbo == mb ) return(99);
		if (_Context->trigger_txtsh == mb ) return(100);
		if (_Context->trigger_txtbl == mb ) return(101);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3628+789) )  
	&&  (my >= (_Context->y_Auto3628+4) )  
	&&  (mx <= (_Context->x_Auto3628+806) )  
	&&  (my <= (_Context->y_Auto3628+20) )) {
		return(1);	/* Auto3628 */

		}
	if ((mx >= (_Context->x_Auto3628+773) )  
	&&  (my >= (_Context->y_Auto3628+4) )  
	&&  (mx <= (_Context->x_Auto3628+790) )  
	&&  (my <= (_Context->y_Auto3628+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("cstyleman.htm");
			};
		return(-1);	/* Auto3628 */

		}
	if ((mx >= (_Context->x_Auto3628+757) )  
	&&  (my >= (_Context->y_Auto3628+4) )  
	&&  (mx <= (_Context->x_Auto3628+774) )  
	&&  (my <= (_Context->y_Auto3628+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		cstyleman_show(_Context);
		return(-1);	/* Auto3628 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3628+4) )  
		&&  (my >= (_Context->y_Auto3628+4) )  
		&&  (mx <= (_Context->x_Auto3628+742) )  
		&&  (my <= (_Context->y_Auto3628+20) )) {
			return( Auto3628action(_Context) );
			}
		}
	if (( mx >= (_Context->x_Auto3628+760) ) 
	&&  ( my >= (_Context->y_Auto3628+30) ) 
	&&  ( mx <= (_Context->x_Auto3628+760+40) ) 
	&&  ( my <= (_Context->y_Auto3628+30+40))) {
		return(2); /* Auto3629 */
		}
	if (( mx >= (_Context->x_Auto3628+720) ) 
	&&  ( my >= (_Context->y_Auto3628+30) ) 
	&&  ( mx <= (_Context->x_Auto3628+720+40) ) 
	&&  ( my <= (_Context->y_Auto3628+30+40))) {
		return(3); /* Trash */
		}
	if (( mx >= (_Context->x_Auto3628+680) ) 
	&&  ( my >= (_Context->y_Auto3628+30) ) 
	&&  ( mx <= (_Context->x_Auto3628+680+40) ) 
	&&  ( my <= (_Context->y_Auto3628+30+40))) {
		return(4); /* Trace */
		}
	if (( mx >= (_Context->x_Auto3628+100) ) 
	&&  ( my >= (_Context->y_Auto3628+10) ) 
	&&  ( mx <= (_Context->x_Auto3628+100+30) ) 
	&&  ( my <= (_Context->y_Auto3628+10+40))) {
		return(0); /* Worker */
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+0) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+78) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(5); /* CLPage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3628+20) ) 
		&&  ( my >= (_Context->y_Auto3628+90) ) 
		&&  ( mx <= (_Context->x_Auto3628+20+750) ) 
		&&  ( my <= (_Context->y_Auto3628+90+250))) {
			if ((_Context->value_ClassList = ((visual_event(6) - (_Context->y_Auto3628+90)) / 16)) < 1)
				_Context->value_ClassList=0;
else if (_Context->value_ClassList > 14 )
				_Context->value_ClassList=14;
			if ( _Context->value_ClassList > 0 ) { _Context->row_ClassList = &_Context->buffer_ClassList[(_Context->value_ClassList-1)][0]; } 
			_Context->column_ClassList = (visual_event(7) - (_Context->x_Auto3628+20));
			if ( _Context->column_ClassList < 376 ) {
				_Context->column_ClassList = 1;
				}
			else if ( _Context->column_ClassList < 544 ) {
				_Context->column_ClassList = 2;
				}
			if ((!(_Context->value_ClassList)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_ClassList==_Context->column_ClassList) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_ClassList=-_Context->column_ClassList;	/* alors tri décroissant */
				else
					_Context->formsort_ClassList=_Context->column_ClassList; };	/* sinon tri croissant */
			return(6); /* ClassList */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3628+390) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+390+380) ) 
		&&  ( my <= (_Context->y_Auto3628+340+260))) {
			if ((_Context->value_FileList = ((visual_event(6) - (_Context->y_Auto3628+340)) / 16)) < 1)
				_Context->value_FileList=0;
else if (_Context->value_FileList > 15 )
				_Context->value_FileList=15;
			if ( _Context->value_FileList > 0 ) { _Context->row_FileList = &_Context->buffer_FileList[(_Context->value_FileList-1)][0]; } 
			_Context->column_FileList = (visual_event(7) - (_Context->x_Auto3628+390));
			if ( _Context->column_FileList < 376 ) {
				_Context->column_FileList = 1;
				}
			if ((!(_Context->value_FileList)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_FileList==_Context->column_FileList) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_FileList=-_Context->column_FileList;	/* alors tri décroissant */
				else
					_Context->formsort_FileList=_Context->column_FileList; };	/* sinon tri croissant */
			return(7); /* FileList */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3628+20) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+20+350) ) 
		&&  ( my <= (_Context->y_Auto3628+340+260))) {
			if ((_Context->value_CFList = ((visual_event(6) - (_Context->y_Auto3628+340)) / 16)) < 1)
				_Context->value_CFList=0;
else if (_Context->value_CFList > 15 )
				_Context->value_CFList=15;
			if ( _Context->value_CFList > 0 ) { _Context->row_CFList = &_Context->buffer_CFList[(_Context->value_CFList-1)][0]; } 
			_Context->column_CFList = (visual_event(7) - (_Context->x_Auto3628+20));
			if ( _Context->column_CFList < 344 ) {
				_Context->column_CFList = 1;
				}
			if ((!(_Context->value_CFList)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_CFList==_Context->column_CFList) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_CFList=-_Context->column_CFList;	/* alors tri décroissant */
				else
					_Context->formsort_CFList=_Context->column_CFList; };	/* sinon tri croissant */
			return(8); /* CFList */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3628+770) ) 
		&&  ( my >= (_Context->y_Auto3628+90) ) 
		&&  ( mx <= (_Context->x_Auto3628+770+20) ) 
		&&  ( my <= (_Context->y_Auto3628+90+250))) {
			return(9); /* CLBar */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3628+370) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+370+20) ) 
		&&  ( my <= (_Context->y_Auto3628+340+260))) {
			return(10); /* MLBar */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3628+770) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+770+20) ) 
		&&  ( my <= (_Context->y_Auto3628+340+260))) {
			return(11); /* FLBar */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+79) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+141) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(12); /* StylePage */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+130) ) 
		&&  ( my >= (_Context->y_Auto3628+160) ) 
		&&  ( mx <= (_Context->x_Auto3628+130+552) ) 
		&&  ( my <= (_Context->y_Auto3628+160+16))) {
			return(13); /* ClassName */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+690) ) 
		&&  ( my >= (_Context->y_Auto3628+150) ) 
		&&  ( mx <= (_Context->x_Auto3628+690+32) ) 
		&&  ( my <= (_Context->y_Auto3628+150+32))) {
			return(14); /* LoadOperation */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+720) ) 
		&&  ( my >= (_Context->y_Auto3628+150) ) 
		&&  ( mx <= (_Context->x_Auto3628+720+32) ) 
		&&  ( my <= (_Context->y_Auto3628+150+32))) {
			return(15); /* Reset */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+130) ) 
		&&  ( my >= (_Context->y_Auto3628+230) ) 
		&&  ( mx <= (_Context->x_Auto3628+130+552) ) 
		&&  ( my <= (_Context->y_Auto3628+230+16))) {
			return(16); /* BaseClass */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+130) ) 
		&&  ( my >= (_Context->y_Auto3628+290) ) 
		&&  ( mx <= (_Context->x_Auto3628+130+552) ) 
		&&  ( my <= (_Context->y_Auto3628+290+32))) {
			return(17); /* Description */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+130) ) 
		&&  ( my >= (_Context->y_Auto3628+370) ) 
		&&  ( mx <= (_Context->x_Auto3628+130+552) ) 
		&&  ( my <= (_Context->y_Auto3628+370+16))) {
			return(18); /* ClassFile */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+690) ) 
		&&  ( my >= (_Context->y_Auto3628+360) ) 
		&&  ( mx <= (_Context->x_Auto3628+690+32) ) 
		&&  ( my <= (_Context->y_Auto3628+360+32))) {
			return(19); /* SaveOperation */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+720) ) 
		&&  ( my >= (_Context->y_Auto3628+360) ) 
		&&  ( mx <= (_Context->x_Auto3628+720+32) ) 
		&&  ( my <= (_Context->y_Auto3628+360+32))) {
			return(20); /* ViewFile */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+130) ) 
		&&  ( my >= (_Context->y_Auto3628+440) ) 
		&&  ( mx <= (_Context->x_Auto3628+130+552) ) 
		&&  ( my <= (_Context->y_Auto3628+440+16))) {
			return(21); /* ExportName */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+690) ) 
		&&  ( my >= (_Context->y_Auto3628+430) ) 
		&&  ( mx <= (_Context->x_Auto3628+690+32) ) 
		&&  ( my <= (_Context->y_Auto3628+430+32))) {
			return(22); /* ExportOperation */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+720) ) 
		&&  ( my >= (_Context->y_Auto3628+430) ) 
		&&  ( mx <= (_Context->x_Auto3628+720+32) ) 
		&&  ( my <= (_Context->y_Auto3628+430+32))) {
			return(23); /* ViewExport */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+130) ) 
		&&  ( my >= (_Context->y_Auto3628+510) ) 
		&&  ( mx <= (_Context->x_Auto3628+130+552) ) 
		&&  ( my <= (_Context->y_Auto3628+510+16))) {
			return(24); /* ImportName */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+690) ) 
		&&  ( my >= (_Context->y_Auto3628+500) ) 
		&&  ( mx <= (_Context->x_Auto3628+690+32) ) 
		&&  ( my <= (_Context->y_Auto3628+500+32))) {
			return(25); /* ImportOperation */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3628+720) ) 
		&&  ( my >= (_Context->y_Auto3628+500) ) 
		&&  ( mx <= (_Context->x_Auto3628+720+32) ) 
		&&  ( my <= (_Context->y_Auto3628+500+32))) {
			return(26); /* ViewImport */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+142) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+201) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(27); /* TestPage */
			}
		}
	if (_Context->page_number == 3 ) {
		if ((mx >= _Context->x_Thing ) 
		&&  (my >= _Context->y_Thing ) 
		&&  (mx <  (_Context->x_Thing+_Context->w_Thing)) 
		&&  (my <  (_Context->y_Thing+_Context->h_Thing))) {
			return(28); /* Thing */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+202) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+255) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(29); /* Cell */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+120+0) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+120+160) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(30); /* ct */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+520+0) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+160) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(31); /* posv */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+120) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+120+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(32); /* cwv */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+210+0) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+210+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(33); /* cwt */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(34); /* chv */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(35); /* cht */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+120) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+120+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(36); /* cplv */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+210+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+210+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(37); /* cplt */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(38); /* cptv */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(39); /* cprv */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(40); /* cpbv */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(41); /* cptt */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(42); /* cprt */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(43); /* cpbt */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+256) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+327) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(44); /* MarginPage */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+120) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+120+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(45); /* mlv */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+210+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+210+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(46); /* mlt */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(47); /* mgv */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(48); /* mgt */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(49); /* mtv */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(50); /* mtt */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(51); /* mrv */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(52); /* mrt */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(53); /* mbv */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(54); /* mbt */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+328) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+399) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(55); /* BorderPage */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+110+0) ) 
		&&  ( my >= (_Context->y_Auto3628+170) ) 
		&&  ( mx <= (_Context->x_Auto3628+110+88) ) 
		&&  ( my <= (_Context->y_Auto3628+170+16))) {
			return(56); /* bdct */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+210) ) 
		&&  ( my >= (_Context->y_Auto3628+170) ) 
		&&  ( mx <= (_Context->x_Auto3628+210+72) ) 
		&&  ( my <= (_Context->y_Auto3628+170+16))) {
			return(57); /* bdcv */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+320+0) ) 
		&&  ( my >= (_Context->y_Auto3628+170) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+160) ) 
		&&  ( my <= (_Context->y_Auto3628+170+16))) {
			return(58); /* bdat */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+160) ) 
		&&  ( my >= (_Context->y_Auto3628+430) ) 
		&&  ( mx <= (_Context->x_Auto3628+160+536) ) 
		&&  ( my <= (_Context->y_Auto3628+430+16))) {
			return(59); /* blu */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+160) ) 
		&&  ( my >= (_Context->y_Auto3628+470) ) 
		&&  ( mx <= (_Context->x_Auto3628+160+536) ) 
		&&  ( my <= (_Context->y_Auto3628+470+16))) {
			return(60); /* btu */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+160) ) 
		&&  ( my >= (_Context->y_Auto3628+550) ) 
		&&  ( mx <= (_Context->x_Auto3628+160+528) ) 
		&&  ( my <= (_Context->y_Auto3628+550+16))) {
			return(61); /* bbu */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+160) ) 
		&&  ( my >= (_Context->y_Auto3628+510) ) 
		&&  ( mx <= (_Context->x_Auto3628+160+528) ) 
		&&  ( my <= (_Context->y_Auto3628+510+16))) {
			return(62); /* bru */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+110) ) 
		&&  ( my >= (_Context->y_Auto3628+220) ) 
		&&  ( mx <= (_Context->x_Auto3628+110+176) ) 
		&&  ( my <= (_Context->y_Auto3628+220+32))) {
			return(63); /* ctlu */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+220) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+176) ) 
		&&  ( my <= (_Context->y_Auto3628+220+32))) {
			return(64); /* ctru */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+110) ) 
		&&  ( my >= (_Context->y_Auto3628+370) ) 
		&&  ( mx <= (_Context->x_Auto3628+110+176) ) 
		&&  ( my <= (_Context->y_Auto3628+370+32))) {
			return(65); /* cblu */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+370) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+176) ) 
		&&  ( my <= (_Context->y_Auto3628+370+32))) {
			return(66); /* cbru */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+120) ) 
		&&  ( my >= (_Context->y_Auto3628+300) ) 
		&&  ( mx <= (_Context->x_Auto3628+120+72) ) 
		&&  ( my <= (_Context->y_Auto3628+300+16))) {
			return(67); /* blv */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+210+0) ) 
		&&  ( my >= (_Context->y_Auto3628+300) ) 
		&&  ( mx <= (_Context->x_Auto3628+210+72) ) 
		&&  ( my <= (_Context->y_Auto3628+300+16))) {
			return(68); /* blt */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+320+0) ) 
		&&  ( my >= (_Context->y_Auto3628+300) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+160) ) 
		&&  ( my <= (_Context->y_Auto3628+300+16))) {
			return(69); /* bdsv */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+230) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+230+16))) {
			return(70); /* btv */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+230) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+230+16))) {
			return(71); /* btt */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+300) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+72) ) 
		&&  ( my <= (_Context->y_Auto3628+300+16))) {
			return(72); /* brv */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+170) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+72) ) 
		&&  ( my <= (_Context->y_Auto3628+170+16))) {
			return(73); /* bwv */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+300) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+72) ) 
		&&  ( my <= (_Context->y_Auto3628+300+16))) {
			return(74); /* brt */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+170) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+72) ) 
		&&  ( my <= (_Context->y_Auto3628+170+16))) {
			return(75); /* bwt */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+370) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+370+16))) {
			return(76); /* bbv */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+370) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+370+16))) {
			return(77); /* bbt */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+400) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+478) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(78); /* PaddingPage */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+120) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+120+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(79); /* plv */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+210+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+210+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(80); /* plt */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(81); /* pgv */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(82); /* pgt */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(83); /* ptv */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+270) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+270+16))) {
			return(84); /* ptt */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+520) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+520+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(85); /* prv */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+72) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(86); /* prt */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+320) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+320+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(87); /* pbv */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3628+410+0) ) 
		&&  ( my >= (_Context->y_Auto3628+410) ) 
		&&  ( mx <= (_Context->x_Auto3628+410+72) ) 
		&&  ( my <= (_Context->y_Auto3628+410+16))) {
			return(88); /* pbt */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+479) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+580) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(89); /* BGPage */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3628+150) ) 
		&&  ( my >= (_Context->y_Auto3628+240) ) 
		&&  ( mx <= (_Context->x_Auto3628+150+536) ) 
		&&  ( my <= (_Context->y_Auto3628+240+16))) {
			return(90); /* bgi */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3628+500+0) ) 
		&&  ( my >= (_Context->y_Auto3628+280) ) 
		&&  ( mx <= (_Context->x_Auto3628+500+192) ) 
		&&  ( my <= (_Context->y_Auto3628+280+16))) {
			return(91); /* bgia */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3628+500+0) ) 
		&&  ( my >= (_Context->y_Auto3628+320) ) 
		&&  ( mx <= (_Context->x_Auto3628+500+192) ) 
		&&  ( my <= (_Context->y_Auto3628+320+16))) {
			return(92); /* bgitr */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3628+150+0) ) 
		&&  ( my >= (_Context->y_Auto3628+280) ) 
		&&  ( mx <= (_Context->x_Auto3628+150+128) ) 
		&&  ( my <= (_Context->y_Auto3628+280+16))) {
			return(93); /* bgct */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3628+290) ) 
		&&  ( my >= (_Context->y_Auto3628+280) ) 
		&&  ( mx <= (_Context->x_Auto3628+290+80) ) 
		&&  ( my <= (_Context->y_Auto3628+280+16))) {
			return(94); /* bgcv */
			}
		}
	if (_Context->page_number == 9 ) {
	} else {
		if (( mx >= (_Context->x_Auto3628+10+581) ) 
		&&  ( my >= (_Context->y_Auto3628+50) ) 
		&&  ( mx <= (_Context->x_Auto3628+10+659) ) 
		&&  ( my <= (_Context->y_Auto3628+50+24))) {
			return(95); /* ContentPage */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+110) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+110+126) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(96); /* txtol */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+110) ) 
		&&  ( my >= (_Context->y_Auto3628+360) ) 
		&&  ( mx <= (_Context->x_Auto3628+110+126) ) 
		&&  ( my <= (_Context->y_Auto3628+360+16))) {
			return(97); /* txtlt */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+110) ) 
		&&  ( my >= (_Context->y_Auto3628+380) ) 
		&&  ( mx <= (_Context->x_Auto3628+110+126) ) 
		&&  ( my <= (_Context->y_Auto3628+380+16))) {
			return(98); /* txtul */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+250) ) 
		&&  ( my >= (_Context->y_Auto3628+340) ) 
		&&  ( mx <= (_Context->x_Auto3628+250+126) ) 
		&&  ( my <= (_Context->y_Auto3628+340+16))) {
			return(99); /* txtbo */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+250) ) 
		&&  ( my >= (_Context->y_Auto3628+360) ) 
		&&  ( mx <= (_Context->x_Auto3628+250+126) ) 
		&&  ( my <= (_Context->y_Auto3628+360+16))) {
			return(100); /* txtsh */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+250) ) 
		&&  ( my >= (_Context->y_Auto3628+380) ) 
		&&  ( mx <= (_Context->x_Auto3628+250+126) ) 
		&&  ( my <= (_Context->y_Auto3628+380+16))) {
			return(101); /* txtbl */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+150) ) 
		&&  ( my >= (_Context->y_Auto3628+240) ) 
		&&  ( mx <= (_Context->x_Auto3628+150+536) ) 
		&&  ( my <= (_Context->y_Auto3628+240+16))) {
			return(102); /* txfu */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+150+0) ) 
		&&  ( my >= (_Context->y_Auto3628+280) ) 
		&&  ( mx <= (_Context->x_Auto3628+150+128) ) 
		&&  ( my <= (_Context->y_Auto3628+280+16))) {
			return(103); /* txct */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+290) ) 
		&&  ( my >= (_Context->y_Auto3628+280) ) 
		&&  ( mx <= (_Context->x_Auto3628+290+72) ) 
		&&  ( my <= (_Context->y_Auto3628+280+16))) {
			return(104); /* txcv */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+500+0) ) 
		&&  ( my >= (_Context->y_Auto3628+280) ) 
		&&  ( mx <= (_Context->x_Auto3628+500+192) ) 
		&&  ( my <= (_Context->y_Auto3628+280+16))) {
			return(105); /* txta */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+500) ) 
		&&  ( my >= (_Context->y_Auto3628+320) ) 
		&&  ( mx <= (_Context->x_Auto3628+500+96) ) 
		&&  ( my <= (_Context->y_Auto3628+320+16))) {
			return(106); /* ltspv */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+320) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+80) ) 
		&&  ( my <= (_Context->y_Auto3628+320+16))) {
			return(107); /* ltspt */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+500) ) 
		&&  ( my >= (_Context->y_Auto3628+360) ) 
		&&  ( mx <= (_Context->x_Auto3628+500+96) ) 
		&&  ( my <= (_Context->y_Auto3628+360+16))) {
			return(108); /* wspv */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+360) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+80) ) 
		&&  ( my <= (_Context->y_Auto3628+360+16))) {
			return(109); /* wspt */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+500) ) 
		&&  ( my >= (_Context->y_Auto3628+400) ) 
		&&  ( mx <= (_Context->x_Auto3628+500+96) ) 
		&&  ( my <= (_Context->y_Auto3628+400+16))) {
			return(110); /* lnspv */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+610+0) ) 
		&&  ( my >= (_Context->y_Auto3628+400) ) 
		&&  ( mx <= (_Context->x_Auto3628+610+80) ) 
		&&  ( my <= (_Context->y_Auto3628+400+16))) {
			return(111); /* lnspt */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto3628+110) ) 
		&&  ( my >= (_Context->y_Auto3628+490) ) 
		&&  ( mx <= (_Context->x_Auto3628+110+576) ) 
		&&  ( my <= (_Context->y_Auto3628+490+32))) {
			return(112); /* Message */
			}
		}

	return(-1);
}


public	int	cstyleman_losefocus(struct cstyleman_context * _Context)
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
		case 5 : 
			break;
		case 6 : 
			break;
		case 7 : 
			break;
		case 8 : 
			break;
		case 9 : 
			break;

		}
	return(0);

}


public	int	cstyleman_focus(struct cstyleman_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3629 */
				onhint(_Context,_Context->hint_Auto3629[_Context->language]);
				_Context->trigger_Auto3629=visual_trigger_code(_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]));
				visual_button(_Context->x_Auto3628+760,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]),1074);
				_Context->keycode = visual_getch();
				_Context->trigger_Auto3629=visual_trigger_code(_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]));
	visual_button(_Context->x_Auto3628+760,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]),1072);
				break;
			case	0x3 :
				/* Trash */
				onhint(_Context,_Context->hint_Trash[_Context->language]);
				_Context->trigger_Trash=visual_trigger_code(_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]));
				visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]),1074);
				_Context->keycode = visual_getch();
				_Context->trigger_Trash=visual_trigger_code(_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]),1072);
				break;
			case	0x5 :
				/* CLPage */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xd :
				/* ClassName */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_ClassName[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+130+1,_Context->y_Auto3628+160+1,552,16,vfh[1],_Context->buffer_ClassName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* LoadOperation */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_LoadOperation[_Context->language]);
					_Context->trigger_LoadOperation=visual_trigger_code(_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]));
					visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]),1298);
					_Context->keycode = visual_getch();
					_Context->trigger_LoadOperation=visual_trigger_code(_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]),1296);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* Reset */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_Reset[_Context->language]);
					_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
					visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),1298);
					_Context->keycode = visual_getch();
					_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),1296);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* BaseClass */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_BaseClass[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+130+1,_Context->y_Auto3628+230+1,552,16,vfh[1],_Context->buffer_BaseClass,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Description */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_Description[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+130+1,_Context->y_Auto3628+290+1,552,32,vfh[1],_Context->buffer_Description,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* ClassFile */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_ClassFile[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+130+1,_Context->y_Auto3628+370+1,552,16,vfh[1],_Context->buffer_ClassFile,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* SaveOperation */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_SaveOperation[_Context->language]);
					_Context->trigger_SaveOperation=visual_trigger_code(_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]));
					visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]),1298);
					_Context->keycode = visual_getch();
					_Context->trigger_SaveOperation=visual_trigger_code(_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]),1296);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* ExportName */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_ExportName[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+130+1,_Context->y_Auto3628+440+1,552,16,vfh[1],_Context->buffer_ExportName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* ExportOperation */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_ExportOperation[_Context->language]);
					_Context->trigger_ExportOperation=visual_trigger_code(_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]));
					visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]),1298);
					_Context->keycode = visual_getch();
					_Context->trigger_ExportOperation=visual_trigger_code(_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]),1296);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* ImportName */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_ImportName[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+130+1,_Context->y_Auto3628+510+1,552,16,vfh[1],_Context->buffer_ImportName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ImportOperation */
				if (_Context->page_number == 2 ) {
					onhint(_Context,_Context->hint_ImportOperation[_Context->language]);
					_Context->trigger_ImportOperation=visual_trigger_code(_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]));
					visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]),1298);
					_Context->keycode = visual_getch();
					_Context->trigger_ImportOperation=visual_trigger_code(_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]),1296);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* TestPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1c :
				/* Thing */
				if (_Context->page_number == 3 ) {
					if ((_Context->p_Thing != (void *) 0)
					&& (_Context->s_Thing == 0)) {
						(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
						_Context->s_Thing=1;
						}
					_Context->trigger_Thing=visual_trigger_code(_Context->buffer_Message,strlen(_Context->buffer_Message));
					visual_button(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->fid_Thing,27,28,_Context->buffer_Message,strlen(_Context->buffer_Message),2);
					_Context->keycode = visual_getch();
					if ((_Context->p_Thing != (void *) 0)
					&& (_Context->s_Thing == 0)) {
						(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
						_Context->s_Thing=1;
						}
					_Context->trigger_Thing=visual_trigger_code(_Context->buffer_Message,strlen(_Context->buffer_Message));
					if (((_Context->status = visual_styled_element(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->buffer_ClassName,_Context->buffer_Message,strlen(_Context->buffer_Message))) != 0)
) {
	visual_button(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->fid_Thing,27,28,_Context->buffer_Message,strlen(_Context->buffer_Message),0);
					}
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* ct */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_ct[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+120,_Context->y_Auto3628+270,160,208,vfh[1],27,28,parse_selection(_styleman_content,&_Context->value_ct),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* posv */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_posv[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+520,_Context->y_Auto3628+270,160,192,vfh[1],27,28,parse_selection(_styleman_position,&_Context->value_posv),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* cwv */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cwv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+120+1,_Context->y_Auto3628+410+1,72,16,vfh[1],_Context->buffer_cwv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* cwt */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cwt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+410,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cwt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* chv */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_chv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+410+1,72,16,vfh[1],_Context->buffer_chv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* cht */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cht[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+410,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cht),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* cplv */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cplv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+120+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_cplv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* cplt */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cplt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+340,72,176,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cplt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* cptv */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cptv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+270+1,72,16,vfh[1],_Context->buffer_cptv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* cprv */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cprv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_cprv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* cpbv */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cpbv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+410+1,72,16,vfh[1],_Context->buffer_cpbv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* cptt */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cptt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+270,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cptt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* cprt */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cprt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+340,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cprt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* cpbt */
				if (_Context->page_number == 4 ) {
					onhint(_Context,_Context->hint_cpbt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+410,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_cpbt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* mlv */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mlv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+120+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_mlv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* mlt */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mlt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+340,72,192,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mlt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* mgv */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mgv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_mgv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* mgt */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mgt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+340,72,192,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mgt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* mtv */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mtv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+270+1,72,16,vfh[1],_Context->buffer_mtv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* mtt */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mtt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+270,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mtt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* mrv */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mrv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_mrv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* mrt */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mrt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+340,72,192,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mrt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* mbv */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mbv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+410+1,72,16,vfh[1],_Context->buffer_mbv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* mbt */
				if (_Context->page_number == 5 ) {
					onhint(_Context,_Context->hint_mbt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+410,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_mbt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x38 :
				/* bdct */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bdct[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+110,_Context->y_Auto3628+170,88,160,vfh[1],27,28,parse_selection(_styleman_colours,&_Context->value_bdct),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x39 :
				/* bdcv */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bdcv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+210+1,_Context->y_Auto3628+170+1,72,16,vfh[1],_Context->buffer_bdcv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3a :
				/* bdat */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bdat[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+320,_Context->y_Auto3628+170,160,160,vfh[1],27,28,parse_selection(_styleman_align,&_Context->value_bdat),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3b :
				/* blu */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_blu[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+160+1,_Context->y_Auto3628+430+1,536,16,vfh[1],_Context->buffer_blu,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3c :
				/* btu */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_btu[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+160+1,_Context->y_Auto3628+470+1,536,16,vfh[1],_Context->buffer_btu,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3d :
				/* bbu */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bbu[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+160+1,_Context->y_Auto3628+550+1,528,16,vfh[1],_Context->buffer_bbu,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3e :
				/* bru */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bru[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+160+1,_Context->y_Auto3628+510+1,528,16,vfh[1],_Context->buffer_bru,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3f :
				/* ctlu */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_ctlu[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+110+1,_Context->y_Auto3628+220+1,176,32,vfh[1],_Context->buffer_ctlu,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x40 :
				/* ctru */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_ctru[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+220+1,176,32,vfh[1],_Context->buffer_ctru,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x41 :
				/* cblu */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_cblu[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+110+1,_Context->y_Auto3628+370+1,176,32,vfh[1],_Context->buffer_cblu,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x42 :
				/* cbru */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_cbru[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+370+1,176,32,vfh[1],_Context->buffer_cbru,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x43 :
				/* blv */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_blv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+120+1,_Context->y_Auto3628+300+1,72,16,vfh[1],_Context->buffer_blv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x44 :
				/* blt */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_blt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+300,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_blt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x45 :
				/* bdsv */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bdsv[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+320,_Context->y_Auto3628+300,160,192,vfh[1],27,0,parse_selection(_styleman_frame,&_Context->value_bdsv),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x46 :
				/* btv */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_btv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+230+1,72,16,vfh[1],_Context->buffer_btv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x47 :
				/* btt */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_btt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+230,72,240,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_btt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x48 :
				/* brv */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_brv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+300+1,72,16,vfh[1],_Context->buffer_brv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x49 :
				/* bwv */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bwv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+170+1,72,16,vfh[1],_Context->buffer_bwv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4a :
				/* brt */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_brt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+300,72,160,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_brt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4b :
				/* bwt */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bwt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+170,72,176,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_bwt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4c :
				/* bbv */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bbv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+370+1,72,16,vfh[1],_Context->buffer_bbv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4d :
				/* bbt */
				if (_Context->page_number == 6 ) {
					onhint(_Context,_Context->hint_bbt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+370,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_bbt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4f :
				/* plv */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_plv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+120+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_plv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x50 :
				/* plt */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_plt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+210,_Context->y_Auto3628+340,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_plt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x51 :
				/* pgv */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_pgv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_pgv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x52 :
				/* pgt */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_pgt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+340,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_pgt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x53 :
				/* ptv */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_ptv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+270+1,72,16,vfh[1],_Context->buffer_ptv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x54 :
				/* ptt */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_ptt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+270,72,288,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_ptt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x55 :
				/* prv */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_prv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+520+1,_Context->y_Auto3628+340+1,72,16,vfh[1],_Context->buffer_prv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x56 :
				/* prt */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_prt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+340,72,224,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_prt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x57 :
				/* pbv */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_pbv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+320+1,_Context->y_Auto3628+410+1,72,16,vfh[1],_Context->buffer_pbv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x58 :
				/* pbt */
				if (_Context->page_number == 7 ) {
					onhint(_Context,_Context->hint_pbt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+410,_Context->y_Auto3628+410,72,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_pbt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5a :
				/* bgi */
				if (_Context->page_number == 8 ) {
					onhint(_Context,_Context->hint_bgi[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+150+1,_Context->y_Auto3628+240+1,536,16,vfh[1],_Context->buffer_bgi,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5b :
				/* bgia */
				if (_Context->page_number == 8 ) {
					onhint(_Context,_Context->hint_bgia[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+500,_Context->y_Auto3628+280,192,160,vfh[1],27,28,parse_selection(_styleman_align,&_Context->value_bgia),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5c :
				/* bgitr */
				if (_Context->page_number == 8 ) {
					onhint(_Context,_Context->hint_bgitr[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+500,_Context->y_Auto3628+320,192,80,vfh[1],27,28,parse_selection(_styleman_imagemode,&_Context->value_bgitr),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5d :
				/* bgct */
				if (_Context->page_number == 8 ) {
					onhint(_Context,_Context->hint_bgct[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+150,_Context->y_Auto3628+280,128,160,vfh[1],27,28,parse_selection(_styleman_colours,&_Context->value_bgct),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5e :
				/* bgcv */
				if (_Context->page_number == 8 ) {
					onhint(_Context,_Context->hint_bgcv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+290+1,_Context->y_Auto3628+280+1,80,16,vfh[1],_Context->buffer_bgcv,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x60 :
				/* txtol */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txtol[_Context->language]);
				visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+340,126,16,vfh[2],27,28,_Context->msg_txtol[_Context->language],strlen(_Context->msg_txtol[_Context->language]),(_Context->value_txtol |2));
					_Context->keycode = visual_getch();
					_Context->trigger_txtol=visual_trigger_code(_Context->msg_txtol[_Context->language],strlen(_Context->msg_txtol[_Context->language]));
	visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+340,126,16,vfh[2],27,28,_Context->msg_txtol[_Context->language],strlen(_Context->msg_txtol[_Context->language]),_Context->value_txtol|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x61 :
				/* txtlt */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txtlt[_Context->language]);
				visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+360,126,16,vfh[2],27,28,_Context->msg_txtlt[_Context->language],strlen(_Context->msg_txtlt[_Context->language]),(_Context->value_txtlt |2));
					_Context->keycode = visual_getch();
					_Context->trigger_txtlt=visual_trigger_code(_Context->msg_txtlt[_Context->language],strlen(_Context->msg_txtlt[_Context->language]));
	visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+360,126,16,vfh[2],27,28,_Context->msg_txtlt[_Context->language],strlen(_Context->msg_txtlt[_Context->language]),_Context->value_txtlt|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x62 :
				/* txtul */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txtul[_Context->language]);
				visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+380,126,16,vfh[2],27,28,_Context->msg_txtul[_Context->language],strlen(_Context->msg_txtul[_Context->language]),(_Context->value_txtul |2));
					_Context->keycode = visual_getch();
					_Context->trigger_txtul=visual_trigger_code(_Context->msg_txtul[_Context->language],strlen(_Context->msg_txtul[_Context->language]));
	visual_check(_Context->x_Auto3628+110,_Context->y_Auto3628+380,126,16,vfh[2],27,28,_Context->msg_txtul[_Context->language],strlen(_Context->msg_txtul[_Context->language]),_Context->value_txtul|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x63 :
				/* txtbo */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txtbo[_Context->language]);
				visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+340,126,16,vfh[2],27,28,_Context->msg_txtbo[_Context->language],strlen(_Context->msg_txtbo[_Context->language]),(_Context->value_txtbo |2));
					_Context->keycode = visual_getch();
					_Context->trigger_txtbo=visual_trigger_code(_Context->msg_txtbo[_Context->language],strlen(_Context->msg_txtbo[_Context->language]));
	visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+340,126,16,vfh[2],27,28,_Context->msg_txtbo[_Context->language],strlen(_Context->msg_txtbo[_Context->language]),_Context->value_txtbo|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x64 :
				/* txtsh */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txtsh[_Context->language]);
				visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+360,126,16,vfh[2],27,28,_Context->msg_txtsh[_Context->language],strlen(_Context->msg_txtsh[_Context->language]),(_Context->value_txtsh |2));
					_Context->keycode = visual_getch();
					_Context->trigger_txtsh=visual_trigger_code(_Context->msg_txtsh[_Context->language],strlen(_Context->msg_txtsh[_Context->language]));
	visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+360,126,16,vfh[2],27,28,_Context->msg_txtsh[_Context->language],strlen(_Context->msg_txtsh[_Context->language]),_Context->value_txtsh|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x65 :
				/* txtbl */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txtbl[_Context->language]);
				visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+380,126,16,vfh[2],27,28,_Context->msg_txtbl[_Context->language],strlen(_Context->msg_txtbl[_Context->language]),(_Context->value_txtbl |2));
					_Context->keycode = visual_getch();
					_Context->trigger_txtbl=visual_trigger_code(_Context->msg_txtbl[_Context->language],strlen(_Context->msg_txtbl[_Context->language]));
	visual_check(_Context->x_Auto3628+250,_Context->y_Auto3628+380,126,16,vfh[2],27,28,_Context->msg_txtbl[_Context->language],strlen(_Context->msg_txtbl[_Context->language]),_Context->value_txtbl|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x66 :
				/* txfu */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txfu[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+150+1,_Context->y_Auto3628+240+1,536,16,vfh[1],_Context->buffer_txfu,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x67 :
				/* txct */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txct[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+150,_Context->y_Auto3628+280,128,256,vfh[1],27,28,parse_selection(_styleman_colours,&_Context->value_txct),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x68 :
				/* txcv */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txcv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+290+1,_Context->y_Auto3628+280+1,72,16,vfh[1],_Context->buffer_txcv,9);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x69 :
				/* txta */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_txta[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+500,_Context->y_Auto3628+280,192,208,vfh[1],27,28,parse_selection(_styleman_align,&_Context->value_txta),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6a :
				/* ltspv */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_ltspv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+500+1,_Context->y_Auto3628+320+1,96,16,vfh[1],_Context->buffer_ltspv,12);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6b :
				/* ltspt */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_ltspt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+320,80,144,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_ltspt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6c :
				/* wspv */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_wspv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+500+1,_Context->y_Auto3628+360+1,96,16,vfh[1],_Context->buffer_wspv,12);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6d :
				/* wspt */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_wspt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+360,80,112,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_wspt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6e :
				/* lnspv */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_lnspv[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+500+1,_Context->y_Auto3628+400+1,96,16,vfh[1],_Context->buffer_lnspv,12);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6f :
				/* lnspt */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_lnspt[_Context->language]);
					_Context->keycode = visual_select(_Context->x_Auto3628+610,_Context->y_Auto3628+400,80,64,vfh[1],27,0,parse_selection(_styleman_value,&_Context->value_lnspt),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x70 :
				/* Message */
				if (_Context->page_number == 9 ) {
					onhint(_Context,_Context->hint_Message[_Context->language]);
					_Context->keycode = visual_edit(_Context->x_Auto3628+110+1,_Context->y_Auto3628+490+1,576,32,vfh[1],_Context->buffer_Message,255);
				} else {
					_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
retry:
		switch (_Context->keycode) {
		case	0xc :
			cstyleman_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			cstyleman_show(_Context);
			continue;
		case	0x2 :
			cstyleman_losefocus(_Context);
			_Context->page_number=9;
			_Context->focus_item=112;
			cstyleman_show(_Context);
			continue;
		case	0x3 :
			cstyleman_losefocus(_Context);
			if ( _Context->page_number < 9 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			cstyleman_show(_Context);
			continue;
		case	0x12 :
			cstyleman_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			cstyleman_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=cstyleman_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (Auto3629_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (Trash_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (Trace_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (CLPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (ClassList_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (FileList_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (CFList_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (StylePage_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (ClassName_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (LoadOperation_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Reset_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (BaseClass_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Description_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (ClassFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (SaveOperation_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (ViewFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (ExportName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (ExportOperation_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (ViewExport_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (ImportName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (ImportOperation_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (ViewImport_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (TestPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (Cell_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1e :
						if (ct_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1f :
						if (posv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x20 :
						if (cwv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x21 :
						if (cwt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x22 :
						if (chv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x23 :
						if (cht_help(_Context) != 0) { continue; }
						else { break; }
					case	0x24 :
						if (cplv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x25 :
						if (cplt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x26 :
						if (cptv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (cprv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x28 :
						if (cpbv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x29 :
						if (cptt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2a :
						if (cprt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2b :
						if (cpbt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2c :
						if (MarginPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2d :
						if (mlv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2e :
						if (mlt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2f :
						if (mgv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x30 :
						if (mgt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x31 :
						if (mtv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x32 :
						if (mtt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x33 :
						if (mrv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x34 :
						if (mrt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x35 :
						if (mbv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x36 :
						if (mbt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x37 :
						if (BorderPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x38 :
						if (bdct_help(_Context) != 0) { continue; }
						else { break; }
					case	0x39 :
						if (bdcv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3a :
						if (bdat_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3b :
						if (blu_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3c :
						if (btu_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3d :
						if (bbu_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3e :
						if (bru_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3f :
						if (ctlu_help(_Context) != 0) { continue; }
						else { break; }
					case	0x40 :
						if (ctru_help(_Context) != 0) { continue; }
						else { break; }
					case	0x41 :
						if (cblu_help(_Context) != 0) { continue; }
						else { break; }
					case	0x42 :
						if (cbru_help(_Context) != 0) { continue; }
						else { break; }
					case	0x43 :
						if (blv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x44 :
						if (blt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x45 :
						if (bdsv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x46 :
						if (btv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x47 :
						if (btt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x48 :
						if (brv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x49 :
						if (bwv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4a :
						if (brt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4b :
						if (bwt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4c :
						if (bbv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4d :
						if (bbt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4e :
						if (PaddingPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4f :
						if (plv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x50 :
						if (plt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x51 :
						if (pgv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x52 :
						if (pgt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x53 :
						if (ptv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x54 :
						if (ptt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x55 :
						if (prv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x56 :
						if (prt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x57 :
						if (pbv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x58 :
						if (pbt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x59 :
						if (BGPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5a :
						if (bgi_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5b :
						if (bgia_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5c :
						if (bgitr_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5d :
						if (bgct_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5e :
						if (bgcv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5f :
						if (ContentPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x60 :
						if (txtol_help(_Context) != 0) { continue; }
						else { break; }
					case	0x61 :
						if (txtlt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x62 :
						if (txtul_help(_Context) != 0) { continue; }
						else { break; }
					case	0x63 :
						if (txtbo_help(_Context) != 0) { continue; }
						else { break; }
					case	0x64 :
						if (txtsh_help(_Context) != 0) { continue; }
						else { break; }
					case	0x65 :
						if (txtbl_help(_Context) != 0) { continue; }
						else { break; }
					case	0x66 :
						if (txfu_help(_Context) != 0) { continue; }
						else { break; }
					case	0x67 :
						if (txct_help(_Context) != 0) { continue; }
						else { break; }
					case	0x68 :
						if (txcv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x69 :
						if (txta_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6a :
						if (ltspv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6b :
						if (ltspt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6c :
						if (wspv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6d :
						if (wspt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6e :
						if (lnspv_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6f :
						if (lnspt_help(_Context) != 0) { continue; }
						else { break; }
					case	0x70 :
						if (Message_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3628 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3629 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3629=visual_trigger_code(_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]));
						visual_button(_Context->x_Auto3628+760,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]),1074);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3629=visual_trigger_code(_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]));
	visual_button(_Context->x_Auto3628+760,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]),1072);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3629_event(_Context)) != -1) break;

						}
					continue;
				case	0x3 :
					/* Trash */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Trash=visual_trigger_code(_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]));
						visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]),1074);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Trash=visual_trigger_code(_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trash[_Context->language],strlen(_Context->msg_Trash[_Context->language]),1072);
						}
					continue;
				case	0x4 :
					/* Trace */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_Trace != (void *) 0)
						&& (_Context->s_Trace == 0)) {
							(void)visual_buffer_get(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
							_Context->s_Trace=1;
							}
						_Context->trigger_Trace=visual_trigger_code(_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]));
						visual_button(_Context->x_Auto3628+680,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),1074);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_Trace != (void *) 0)
						&& (_Context->s_Trace == 0)) {
							(void)visual_buffer_get(_Context->p_Trace,_Context->x_Auto3628+680,_Context->y_Auto3628+30);
							_Context->s_Trace=1;
							}
						_Context->trigger_Trace=visual_trigger_code(_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]));
	visual_button(_Context->x_Auto3628+680,_Context->y_Auto3628+30,40,40,vfh[1],27,28,_Context->msg_Trace[_Context->language],strlen(_Context->msg_Trace[_Context->language]),1072);
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Trace_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* CLPage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 1;
						cstyleman_show(_Context);
						}
					continue;
				case	0x6 :
					/* ClassList */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_ClassList_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* FileList */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_FileList_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* CFList */
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_CFList_event(_Context)) != -1) break;

						}
					continue;
				case	0x9 :
					/* CLBar */
					(void) on_CLBar_action(_Context);
					continue;
				case	0xa :
					/* MLBar */
					(void) on_MLBar_action(_Context);
					continue;
				case	0xb :
					/* FLBar */
					(void) on_FLBar_action(_Context);
					continue;
				case	0xc :
					/* StylePage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 2;
						cstyleman_show(_Context);
						}
					continue;
				case	0xd :
					/* ClassName */
					continue;
				case	0xe :
					/* LoadOperation */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_LoadOperation=visual_trigger_code(_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]));
						visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_LoadOperation=visual_trigger_code(_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_LoadOperation[_Context->language],strlen(_Context->msg_LoadOperation[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_LoadOperation_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* Reset */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
						visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Reset=visual_trigger_code(_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+150,32,32,vfh[1],27,28,_Context->msg_Reset[_Context->language],strlen(_Context->msg_Reset[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Reset_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* BaseClass */
					continue;
				case	0x11 :
					/* Description */
					continue;
				case	0x12 :
					/* ClassFile */
					continue;
				case	0x13 :
					/* SaveOperation */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SaveOperation=visual_trigger_code(_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]));
						visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SaveOperation=visual_trigger_code(_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_SaveOperation[_Context->language],strlen(_Context->msg_SaveOperation[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_SaveOperation_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* ViewFile */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ViewFile=visual_trigger_code(_Context->msg_ViewFile[_Context->language],strlen(_Context->msg_ViewFile[_Context->language]));
						visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_ViewFile[_Context->language],strlen(_Context->msg_ViewFile[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ViewFile=visual_trigger_code(_Context->msg_ViewFile[_Context->language],strlen(_Context->msg_ViewFile[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+360,32,32,vfh[1],27,28,_Context->msg_ViewFile[_Context->language],strlen(_Context->msg_ViewFile[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ViewFile_event(_Context)) != -1) break;

						}
					continue;
				case	0x15 :
					/* ExportName */
					continue;
				case	0x16 :
					/* ExportOperation */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ExportOperation=visual_trigger_code(_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]));
						visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ExportOperation=visual_trigger_code(_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ExportOperation[_Context->language],strlen(_Context->msg_ExportOperation[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ExportOperation_event(_Context)) != -1) break;

						}
					continue;
				case	0x17 :
					/* ViewExport */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ViewExport=visual_trigger_code(_Context->msg_ViewExport[_Context->language],strlen(_Context->msg_ViewExport[_Context->language]));
						visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ViewExport[_Context->language],strlen(_Context->msg_ViewExport[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ViewExport=visual_trigger_code(_Context->msg_ViewExport[_Context->language],strlen(_Context->msg_ViewExport[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+430,32,32,vfh[1],27,28,_Context->msg_ViewExport[_Context->language],strlen(_Context->msg_ViewExport[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ViewExport_event(_Context)) != -1) break;

						}
					continue;
				case	0x18 :
					/* ImportName */
					continue;
				case	0x19 :
					/* ImportOperation */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ImportOperation=visual_trigger_code(_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]));
						visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ImportOperation=visual_trigger_code(_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]));
	visual_button(_Context->x_Auto3628+690,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ImportOperation[_Context->language],strlen(_Context->msg_ImportOperation[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ImportOperation_event(_Context)) != -1) break;

						}
					continue;
				case	0x1a :
					/* ViewImport */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ViewImport=visual_trigger_code(_Context->msg_ViewImport[_Context->language],strlen(_Context->msg_ViewImport[_Context->language]));
						visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ViewImport[_Context->language],strlen(_Context->msg_ViewImport[_Context->language]),1298);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ViewImport=visual_trigger_code(_Context->msg_ViewImport[_Context->language],strlen(_Context->msg_ViewImport[_Context->language]));
	visual_button(_Context->x_Auto3628+720,_Context->y_Auto3628+500,32,32,vfh[1],27,28,_Context->msg_ViewImport[_Context->language],strlen(_Context->msg_ViewImport[_Context->language]),1296);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ViewImport_event(_Context)) != -1) break;

						}
					continue;
				case	0x1b :
					/* TestPage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 3;
						cstyleman_show(_Context);
						}
					continue;
				case	0x1c :
					/* Thing */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_Thing != (void *) 0)
						&& (_Context->s_Thing == 0)) {
							(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
							_Context->s_Thing=1;
							}
						_Context->trigger_Thing=visual_trigger_code(_Context->buffer_Message,strlen(_Context->buffer_Message));
						visual_button(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->fid_Thing,27,28,_Context->buffer_Message,strlen(_Context->buffer_Message),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_Thing != (void *) 0)
						&& (_Context->s_Thing == 0)) {
							(void)visual_buffer_get(_Context->p_Thing,_Context->x_Thing,_Context->y_Thing);
							_Context->s_Thing=1;
							}
						_Context->trigger_Thing=visual_trigger_code(_Context->buffer_Message,strlen(_Context->buffer_Message));
						if (((_Context->status = visual_styled_element(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->buffer_ClassName,_Context->buffer_Message,strlen(_Context->buffer_Message))) != 0)
) {
	visual_button(_Context->x_Thing,_Context->y_Thing,_Context->w_Thing,_Context->h_Thing,_Context->fid_Thing,27,28,_Context->buffer_Message,strlen(_Context->buffer_Message),0);
						}
						}
					if ( visual_event(1) &  0x10 ) {
					if ((_Context->keycode = on_Thing_event(_Context)) != -1) break;

						}
					continue;
				case	0x1d :
					/* Cell */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 4;
						cstyleman_show(_Context);
						}
					continue;
				case	0x1e :
					/* ct */
					continue;
				case	0x1f :
					/* posv */
					continue;
				case	0x20 :
					/* cwv */
					continue;
				case	0x21 :
					/* cwt */
					continue;
				case	0x22 :
					/* chv */
					continue;
				case	0x23 :
					/* cht */
					continue;
				case	0x24 :
					/* cplv */
					continue;
				case	0x25 :
					/* cplt */
					continue;
				case	0x26 :
					/* cptv */
					continue;
				case	0x27 :
					/* cprv */
					continue;
				case	0x28 :
					/* cpbv */
					continue;
				case	0x29 :
					/* cptt */
					continue;
				case	0x2a :
					/* cprt */
					continue;
				case	0x2b :
					/* cpbt */
					continue;
				case	0x2c :
					/* MarginPage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 5;
						cstyleman_show(_Context);
						}
					continue;
				case	0x2d :
					/* mlv */
					continue;
				case	0x2e :
					/* mlt */
					continue;
				case	0x2f :
					/* mgv */
					continue;
				case	0x30 :
					/* mgt */
					continue;
				case	0x31 :
					/* mtv */
					continue;
				case	0x32 :
					/* mtt */
					continue;
				case	0x33 :
					/* mrv */
					continue;
				case	0x34 :
					/* mrt */
					continue;
				case	0x35 :
					/* mbv */
					continue;
				case	0x36 :
					/* mbt */
					continue;
				case	0x37 :
					/* BorderPage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 6;
						cstyleman_show(_Context);
						}
					continue;
				case	0x38 :
					/* bdct */
					continue;
				case	0x39 :
					/* bdcv */
					continue;
				case	0x3a :
					/* bdat */
					continue;
				case	0x3b :
					/* blu */
					continue;
				case	0x3c :
					/* btu */
					continue;
				case	0x3d :
					/* bbu */
					continue;
				case	0x3e :
					/* bru */
					continue;
				case	0x3f :
					/* ctlu */
					continue;
				case	0x40 :
					/* ctru */
					continue;
				case	0x41 :
					/* cblu */
					continue;
				case	0x42 :
					/* cbru */
					continue;
				case	0x43 :
					/* blv */
					continue;
				case	0x44 :
					/* blt */
					continue;
				case	0x45 :
					/* bdsv */
					continue;
				case	0x46 :
					/* btv */
					continue;
				case	0x47 :
					/* btt */
					continue;
				case	0x48 :
					/* brv */
					continue;
				case	0x49 :
					/* bwv */
					continue;
				case	0x4a :
					/* brt */
					continue;
				case	0x4b :
					/* bwt */
					continue;
				case	0x4c :
					/* bbv */
					continue;
				case	0x4d :
					/* bbt */
					continue;
				case	0x4e :
					/* PaddingPage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 7;
						cstyleman_show(_Context);
						}
					continue;
				case	0x4f :
					/* plv */
					continue;
				case	0x50 :
					/* plt */
					continue;
				case	0x51 :
					/* pgv */
					continue;
				case	0x52 :
					/* pgt */
					continue;
				case	0x53 :
					/* ptv */
					continue;
				case	0x54 :
					/* ptt */
					continue;
				case	0x55 :
					/* prv */
					continue;
				case	0x56 :
					/* prt */
					continue;
				case	0x57 :
					/* pbv */
					continue;
				case	0x58 :
					/* pbt */
					continue;
				case	0x59 :
					/* BGPage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 8;
						cstyleman_show(_Context);
						}
					continue;
				case	0x5a :
					/* bgi */
					continue;
				case	0x5b :
					/* bgia */
					continue;
				case	0x5c :
					/* bgitr */
					continue;
				case	0x5d :
					/* bgct */
					continue;
				case	0x5e :
					/* bgcv */
					continue;
				case	0x5f :
					/* ContentPage */
					if (visual_event(1) & _MIMO_DOWN) {
						cstyleman_losefocus(_Context);
						_Context->page_number = 9;
						cstyleman_show(_Context);
						}
					continue;
				case	0x60 :
					/* txtol */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_txtol += 1;
						_Context->value_txtol &= 1;
						}
					continue;
				case	0x61 :
					/* txtlt */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_txtlt += 1;
						_Context->value_txtlt &= 1;
						}
					continue;
				case	0x62 :
					/* txtul */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_txtul += 1;
						_Context->value_txtul &= 1;
						}
					continue;
				case	0x63 :
					/* txtbo */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_txtbo += 1;
						_Context->value_txtbo &= 1;
						}
					continue;
				case	0x64 :
					/* txtsh */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_txtsh += 1;
						_Context->value_txtsh &= 1;
						}
					continue;
				case	0x65 :
					/* txtbl */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_txtbl += 1;
						_Context->value_txtbl &= 1;
						}
					continue;
				case	0x66 :
					/* txfu */
					continue;
				case	0x67 :
					/* txct */
					continue;
				case	0x68 :
					/* txcv */
					continue;
				case	0x69 :
					/* txta */
					continue;
				case	0x6a :
					/* ltspv */
					continue;
				case	0x6b :
					/* ltspt */
					continue;
				case	0x6c :
					/* wspv */
					continue;
				case	0x6d :
					/* wspt */
					continue;
				case	0x6e :
					/* lnspv */
					continue;
				case	0x6f :
					/* lnspt */
					continue;
				case	0x70 :
					/* Message */
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
				_Context->focus_item=112;
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

public	int	cstyleman()
{
	int	status=0;
	struct cstyleman_context * _Context=(struct cstyleman_context*) 0;
	status = cstyleman_create(&_Context);
	if ( status != 0) return(status);
	status = cstyleman_show(_Context);
		enter_modal();
	status = cstyleman_focus(_Context);
		leave_modal();
	status = cstyleman_hide(_Context);
	status = cstyleman_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _cstyleman_c */
