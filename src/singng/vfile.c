
#ifndef _vfile_c
#define _vfile_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.36                                                */
/* Production     : C                                                        */
/* Project        : vfile.xml                                                */
/* Target         : vfile.c                                                  */
/* Identification : 0.0-1197067376-3241.3240                                 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singfile.h"
#include "singprot.h"
#define en__Auto3333   ""
#define fr__Auto3333   ""
#define it__Auto3333   ""
#define es__Auto3333   ""
#define de__Auto3333   ""
#define nl__Auto3333   ""
#define pt__Auto3333   ""
#define xx__Auto3333   ""
#define en_ListPage   "List"
#define fr_ListPage   "Liste"
#define it_ListPage   "List"
#define es_ListPage   "List"
#define de_ListPage   "List"
#define nl_ListPage   "List"
#define pt_ListPage   "List"
#define xx_ListPage   "List"
#define en_Auto3334   "Database"
#define fr_Auto3334   "Base de Donn‚es"
#define it_Auto3334   "Database"
#define es_Auto3334   "Database"
#define de_Auto3334   "Database"
#define nl_Auto3334   "Database"
#define pt_Auto3334   "Database"
#define xx_Auto3334   "Database"
#define en__Auto3334   ""
#define fr__Auto3334   ""
#define it__Auto3334   ""
#define es__Auto3334   ""
#define de__Auto3334   ""
#define nl__Auto3334   ""
#define pt__Auto3334   ""
#define xx__Auto3334   ""
#define en_Auto3335   "Usage"
#define fr_Auto3335   "Utilisation"
#define it_Auto3335   "Usage"
#define es_Auto3335   "Usage"
#define de_Auto3335   "Usage"
#define nl_Auto3335   "Usage"
#define pt_Auto3335   "Usage"
#define xx_Auto3335   "Usage"
#define en__Auto3335   ""
#define fr__Auto3335   ""
#define it__Auto3335   ""
#define es__Auto3335   ""
#define de__Auto3335   ""
#define nl__Auto3335   ""
#define pt__Auto3335   ""
#define xx__Auto3335   ""
#define en_BaseName   ""
#define en__BaseName   ""
#define en_BaseUsers   ""
#define en__BaseUsers   ""
#define en_FileList   "Class|Instance|Record|Index"
#define fr_FileList   "Class|Instance|Donn‚es|Index"
#define it_FileList   "Class|Instance|Record|Index"
#define es_FileList   "Class|Instance|Record|Index"
#define de_FileList   "Class|Instance|Record|Index"
#define nl_FileList   "Class|Instance|Record|Index"
#define pt_FileList   "Class|Instance|Record|Index"
#define xx_FileList   "Class|Instance|Record|Index"
#define en__FileList   ""
#define en_Mursor   ""
#define en__Mursor   ""
#define en_Auto3336   "a"
#define fr_Auto3336   "a"
#define it_Auto3336   "a"
#define es_Auto3336   "a"
#define de_Auto3336   "a"
#define nl_Auto3336   "a"
#define pt_Auto3336   "a"
#define xx_Auto3336   "a"
#define en_ScrollBar   ""
#define en__ScrollBar   ""
#define en_CopyFile   "Copy File"
#define fr_CopyFile   "Copier Fichier"
#define it_CopyFile   "Copy File"
#define es_CopyFile   "Copy File"
#define de_CopyFile   "Kopieren Datei"
#define nl_CopyFile   "Copy File"
#define pt_CopyFile   "Copy File"
#define xx_CopyFile   "Copy File"
#define en__CopyFile   ""
#define fr__CopyFile   ""
#define it__CopyFile   ""
#define es__CopyFile   ""
#define de__CopyFile   ""
#define nl__CopyFile   ""
#define pt__CopyFile   ""
#define xx__CopyFile   ""
#define en_DeleteFile   "Delete File"
#define fr_DeleteFile   "Supprime Fichier"
#define it_DeleteFile   "Delete File"
#define es_DeleteFile   "Delete File"
#define de_DeleteFile   "Delete File"
#define nl_DeleteFile   "Delete File"
#define pt_DeleteFile   "Delete File"
#define xx_DeleteFile   "Delete File"
#define en__DeleteFile   ""
#define fr__DeleteFile   ""
#define it__DeleteFile   ""
#define es__DeleteFile   ""
#define de__DeleteFile   ""
#define nl__DeleteFile   ""
#define pt__DeleteFile   ""
#define xx__DeleteFile   ""
#define en_PasteFile   "Paste File"
#define fr_PasteFile   "Coller Fichier"
#define it_PasteFile   "Paste File"
#define es_PasteFile   "Paste File"
#define de_PasteFile   "Paste File"
#define nl_PasteFile   "Paste File"
#define pt_PasteFile   "Paste File"
#define xx_PasteFile   "Paste File"
#define en__PasteFile   ""
#define fr__PasteFile   ""
#define it__PasteFile   ""
#define es__PasteFile   ""
#define de__PasteFile   ""
#define nl__PasteFile   ""
#define pt__PasteFile   ""
#define xx__PasteFile   ""
#define en_FilePage   "File"
#define fr_FilePage   "Fichier"
#define it_FilePage   "File"
#define es_FilePage   "File"
#define de_FilePage   "File"
#define nl_FilePage   "File"
#define pt_FilePage   "File"
#define xx_FilePage   "File"
#define en__FilePage   ""
#define en_Auto3339   "Class"
#define fr_Auto3339   "Class"
#define it_Auto3339   "Class"
#define es_Auto3339   "Class"
#define de_Auto3339   "Class"
#define nl_Auto3339   "Class"
#define pt_Auto3339   "Class"
#define xx_Auto3339   "Class"
#define en_Auto3340   "Members"
#define fr_Auto3340   "Membres"
#define it_Auto3340   "Primary Index Members"
#define es_Auto3340   "Primary Index Members"
#define de_Auto3340   "Primary Index Members"
#define nl_Auto3340   "Primary Index Members"
#define pt_Auto3340   "Primary Index Members"
#define xx_Auto3340   "Primary Index Members"
#define en_Auto3341   "Size"
#define fr_Auto3341   "Taille"
#define it_Auto3341   "Size"
#define es_Auto3341   "Size"
#define de_Auto3341   "Size"
#define nl_Auto3341   "Size"
#define pt_Auto3341   "Size"
#define xx_Auto3341   "Size"
#define en_ClassName   ""
#define en__ClassName   ""
#define en_Instance   ""
#define en__Instance   ""
#define en_Filename   ""
#define en__Filename   ""
#define en__FileType   ""
#define en_IndexType   "K=|LK=|RK="
#define fr_IndexType   "K=|LK=|RK="
#define it_IndexType   "K=|LK=|RK="
#define es_IndexType   "K=|LK=|RK="
#define de_IndexType   "K=|LK=|RK="
#define nl_IndexType   "K=|LK=|RK="
#define pt_IndexType   "K=|LK=|RK="
#define xx_IndexType   "K=|LK=|RK="
#define en_IndexSize   ""
#define en__IndexSize   ""
#define en_Auto3342   "-"
#define fr_Auto3342   "-"
#define it_Auto3342   "-"
#define es_Auto3342   "-"
#define de_Auto3342   "-"
#define nl_Auto3342   "-"
#define pt_Auto3342   "-"
#define xx_Auto3342   "-"
#define en_NbIndex   ""
#define en__NbIndex   ""
#define en_Auto3343   "+"
#define fr_Auto3343   "+"
#define it_Auto3343   "+"
#define es_Auto3343   "+"
#define de_Auto3343   "+"
#define nl_Auto3343   "+"
#define pt_Auto3343   "+"
#define xx_Auto3343   "+"
#define en_RecordType   "VD"
#define fr_RecordType   "VD="
#define it_RecordType   "VD="
#define es_RecordType   "VD="
#define de_RecordType   "VD="
#define nl_RecordType   "VD="
#define pt_RecordType   "VD="
#define xx_RecordType   "VD="
#define en_MarkerUseage   "MQ"
#define fr_MarkerUseage   "VD="
#define it_MarkerUseage   "VD="
#define es_MarkerUseage   "VD="
#define de_MarkerUseage   "VD="
#define nl_MarkerUseage   "VD="
#define pt_MarkerUseage   "VD="
#define xx_MarkerUseage   "VD="
#define en_Modext   "MODEXT"
#define fr_Modext   "MODEXT"
#define it_Modext   "MODEXT"
#define es_Modext   "MODEXT"
#define de_Modext   "MODEXT"
#define nl_Modext   "MODEXT"
#define pt_Modext   "MODEXT"
#define xx_Modext   "MODEXT"
#define en_RecordSize   ""
#define en__RecordSize   ""
#define en_Auto3344   "-"
#define fr_Auto3344   "-"
#define it_Auto3344   "-"
#define es_Auto3344   "-"
#define de_Auto3344   "-"
#define nl_Auto3344   "-"
#define pt_Auto3344   "-"
#define xx_Auto3344   "-"
#define en_NbData   ""
#define en__NbData   ""
#define en_Auto3345   "+"
#define fr_Auto3345   "+"
#define it_Auto3345   "+"
#define es_Auto3345   "+"
#define de_Auto3345   "+"
#define nl_Auto3345   "+"
#define pt_Auto3345   "+"
#define xx_Auto3345   "+"
#define en_Accept   "Accept"
#define fr_Accept   "Valider"
#define it_Accept   "Accept"
#define es_Accept   "Accept"
#define de_Accept   "Accept"
#define nl_Accept   "Accept"
#define pt_Accept   "Accept"
#define xx_Accept   "Accept"
#define en_FileUsers   "Users"
#define fr_FileUsers   "Acc‚s"
#define it_FileUsers   "Users"
#define es_FileUsers   "Users"
#define de_FileUsers   "Users"
#define nl_FileUsers   "Users"
#define pt_FileUsers   "Users"
#define xx_FileUsers   "Users"
#define en_Auto3346   "Filetype"
#define fr_Auto3346   "M‚thode"
#define it_Auto3346   "Format"
#define es_Auto3346   "Format"
#define de_Auto3346   "Format"
#define nl_Auto3346   "Format"
#define pt_Auto3346   "Format"
#define xx_Auto3346   "Format"
#define en_Auto3347   "Align"
#define fr_Auto3347   "Align."
#define it_Auto3347   "Align"
#define es_Auto3347   "Align"
#define de_Auto3347   "Align"
#define nl_Auto3347   "Align"
#define pt_Auto3347   "Align"
#define xx_Auto3347   "Align"
#define fr_Auto3348   "Index Primaire"
#define it_Auto3348   "Primary Index Size"
#define es_Auto3348   "Primary Index Size"
#define de_Auto3348   "Primary Index Size"
#define nl_Auto3348   "Primary Index Size"
#define pt_Auto3348   "Primary Index Size"
#define xx_Auto3348   "Primary Index Size"
#define fr_Auto3349   "Enregistrement"
#define it_Auto3349   "Data Record Size"
#define es_Auto3349   "Data Record Size"
#define de_Auto3349   "Data Record Size"
#define nl_Auto3349   "Data Record Size"
#define pt_Auto3349   "Data Record Size"
#define xx_Auto3349   "Data Record Size"
#define en_Auto3350   "Instance"
#define fr_Auto3350   "Instance"
#define it_Auto3350   "Instance"
#define es_Auto3350   "Instance"
#define de_Auto3350   "Instance"
#define nl_Auto3350   "Instance"
#define pt_Auto3350   "Instance"
#define xx_Auto3350   "Instance"
#define en_Auto3351   "Filename"
#define fr_Auto3351   "Fichier"
#define it_Auto3351   "File"
#define es_Auto3351   "File"
#define de_Auto3351   "Filename"
#define nl_Auto3351   "Filename"
#define pt_Auto3351   "Filename"
#define xx_Auto3351   "Filename"
#define en_IndexMembers   "Name|Type|Length|1st|2nd|N|Y"
#define fr_IndexMembers   "Nom|Type|Long.|1Šre|2eme|!"
#define it_IndexMembers   "Name|Type|Length|1st|2nd|!"
#define es_IndexMembers   "Name|Type|Length|1st|2nd|!"
#define de_IndexMembers   "Name|Type|Length|1st|2nd|!"
#define nl_IndexMembers   "Name|Type|Length|1st|2nd|!"
#define pt_IndexMembers   "Name|Type|Length|1st|2nd|!"
#define xx_IndexMembers   "Name|Type|Length|1st|2nd|!"
#define en__IndexMembers   ""
#define fr__IndexMembers   ""
#define it__IndexMembers   ""
#define es__IndexMembers   ""
#define de__IndexMembers   ""
#define nl__IndexMembers   ""
#define pt__IndexMembers   ""
#define xx__IndexMembers   ""
#define en_Cursor   ""
#define en__Cursor   ""
#define en_IsLink   "cancel.gif"
#define en__IsLink   ""
#define en_IsList   "ok.gif"
#define en__IsList   ""
#define en_IndexBar   ""
#define en_DataMembers   "Name|Type|Length|1st|2nd|N|Y"
#define fr_DataMembers   "Nom|Type|Long.|1Šre|2eme|!"
#define it_DataMembers   "Name|Type|Length|1st|2nd|!"
#define es_DataMembers   "Name|Type|Length|1st|2nd|!"
#define de_DataMembers   "Name|Type|Length|1st|2nd|!"
#define nl_DataMembers   "Name|Type|Length|1st|2nd|!"
#define pt_DataMembers   "Name|Type|Length|1st|2nd|!"
#define xx_DataMembers   "Name|Type|Length|1st|2nd|!"
#define en__DataMembers   ""
#define fr__DataMembers   ""
#define it__DataMembers   ""
#define es__DataMembers   ""
#define de__DataMembers   ""
#define nl__DataMembers   ""
#define pt__DataMembers   ""
#define xx__DataMembers   ""
#define en_Kursor   ""
#define en__Kursor   ""
#define en_DataBar   ""
#define en_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define fr_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define it_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define es_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define de_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define nl_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define pt_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define xx_TypeSelect   "int8#|int16|bcd|string|int32|field|filler|instance"
#define en__TypeSelect   ""
#define fr__TypeSelect   ""
#define it__TypeSelect   ""
#define es__TypeSelect   ""
#define de__TypeSelect   ""
#define nl__TypeSelect   ""
#define pt__TypeSelect   ""
#define xx__TypeSelect   ""
#define en_MaskPage   "Operations"
#define fr_MaskPage   "Op‚rations"
#define it_MaskPage   "Operations"
#define es_MaskPage   "Operations"
#define de_MaskPage   "Operations"
#define nl_MaskPage   "Operations"
#define pt_MaskPage   "Operations"
#define xx_MaskPage   "Operations"
#define en__MaskPage   ""
#define en_Auto3353   "Data File Mask Form"
#define fr_Auto3353   "Formulaire Masque Fichier"
#define it_Auto3353   "Data File Mask Form"
#define es_Auto3353   "Data File Mask Form"
#define de_Auto3353   "Data File Mask Form"
#define nl_Auto3353   "Data File Mask Form"
#define pt_Auto3353   "Data File Mask Form"
#define xx_Auto3353   "Data File Mask Form"
#define en__Auto3353   ""
#define fr__Auto3353   ""
#define it__Auto3353   ""
#define es__Auto3353   ""
#define de__Auto3353   ""
#define nl__Auto3353   ""
#define pt__Auto3353   ""
#define xx__Auto3353   ""
#define en_Auto3354   "Data File Print Form"
#define fr_Auto3354   "Formulaire Edition Fichier"
#define it_Auto3354   "Data File Print Form"
#define es_Auto3354   "Data File Print Form"
#define de_Auto3354   "Data File Print Form"
#define nl_Auto3354   "Data File Print Form"
#define pt_Auto3354   "Data File Print Form"
#define xx_Auto3354   "Data File Print Form"
#define en__Auto3354   ""
#define fr__Auto3354   ""
#define it__Auto3354   ""
#define es__Auto3354   ""
#define de__Auto3354   ""
#define nl__Auto3354   ""
#define pt__Auto3354   ""
#define xx__Auto3354   ""
#define en_Auto3355   "Data File List Form"
#define fr_Auto3355   "Formulaire Liste Fichier"
#define it_Auto3355   "Data File List Form"
#define es_Auto3355   "Data File List Form"
#define de_Auto3355   "Data File List Form"
#define nl_Auto3355   "Data File List Form"
#define pt_Auto3355   "Data File List Form"
#define xx_Auto3355   "Data File List Form"
#define en__Auto3355   ""
#define fr__Auto3355   ""
#define it__Auto3355   ""
#define es__Auto3355   ""
#define de__Auto3355   ""
#define nl__Auto3355   ""
#define pt__Auto3355   ""
#define xx__Auto3355   ""
#define en_Auto3357   ""
#define en_Auto3358   "Data Object Form Production Operations"
#define fr_Auto3358   "G‚n‚ration du formulaire de gestion d'un fichier"
#define it_Auto3358   "Data Object Form Generation"
#define es_Auto3358   "Data Object Form Generation"
#define de_Auto3358   "Data Object Form Generation"
#define nl_Auto3358   "Data Object Form Generation"
#define pt_Auto3358   "Data Object Form Generation"
#define xx_Auto3358   "Data Object Form Generation"
#define en__Auto3358   ""
#define en_Auto3359   "Data Base Import/Export/list"
#define fr_Auto3359   "Import/Export/Liste d'une Base de Donn‚es"
#define it_Auto3359   "Data Base Import/Export/list"
#define es_Auto3359   "Data Base Import/Export/list"
#define de_Auto3359   "Data Base Import/Export/list"
#define nl_Auto3359   "Data Base Import/Export/list"
#define pt_Auto3359   "Data Base Import/Export/list"
#define xx_Auto3359   "Data Base Import/Export/list"
#define en__Auto3359   ""
#define fr__Auto3359   ""
#define it__Auto3359   ""
#define es__Auto3359   ""
#define de__Auto3359   ""
#define nl__Auto3359   ""
#define pt__Auto3359   ""
#define xx__Auto3359   ""
#define en_Auto3360   "Filename Stub ( without extension )"
#define fr_Auto3360   "Racine de nom du fichier ( sans extension )"
#define it_Auto3360   "Filename Stub ( without extension )"
#define es_Auto3360   "Filename Stub ( without extension )"
#define de_Auto3360   "Filename Stub ( without extension )"
#define nl_Auto3360   "Filename Stub ( without extension )"
#define pt_Auto3360   "Filename Stub ( without extension )"
#define xx_Auto3360   "Filename Stub ( without extension )"
#define en__Auto3360   ""
#define fr__Auto3360   ""
#define it__Auto3360   ""
#define es__Auto3360   ""
#define de__Auto3360   ""
#define nl__Auto3360   ""
#define pt__Auto3360   ""
#define xx__Auto3360   ""
#define en_Auto3361   "Database Ressource Filename"
#define fr_Auto3361   "Nom du fichier d'import/export"
#define it_Auto3361   "Database Ressource Filename"
#define es_Auto3361   "Database Ressource Filename"
#define de_Auto3361   "Database Ressource Filename"
#define nl_Auto3361   "Database Ressource Filename"
#define pt_Auto3361   "Database Ressource Filename"
#define xx_Auto3361   "Database Ressource Filename"
#define en_Auto3362   "Forms model name"
#define fr_Auto3362   "Nom du modŠle de formulaires"
#define it_Auto3362   "Database Ressource Filename"
#define es_Auto3362   "Database Ressource Filename"
#define de_Auto3362   "Database Ressource Filename"
#define nl_Auto3362   "Database Ressource Filename"
#define pt_Auto3362   "Database Ressource Filename"
#define xx_Auto3362   "Database Ressource Filename"
#define en_Auto3363   "Html List filename"
#define fr_Auto3363   "Nom de fichier List Html"
#define it_Auto3363   "Html List filename"
#define es_Auto3363   "Html List filename"
#define de_Auto3363   "Html List filename"
#define nl_Auto3363   "Html List filename"
#define pt_Auto3363   "Html List filename"
#define xx_Auto3363   "Html List filename"
#define en__Auto3363   ""
#define fr__Auto3363   ""
#define it__Auto3363   ""
#define es__Auto3363   ""
#define de__Auto3363   ""
#define nl__Auto3363   ""
#define pt__Auto3363   ""
#define xx__Auto3363   ""
#define en_Auto3364   "Window Title"
#define fr_Auto3364   "Titre du formulaire"
#define it_Auto3364   "Title"
#define es_Auto3364   "Title"
#define de_Auto3364   "Title"
#define nl_Auto3364   "Title"
#define pt_Auto3364   "Title"
#define xx_Auto3364   "Title"
#define en_Auto3365   "Production Model"
#define fr_Auto3365   "Production"
#define it_Auto3365   "Production"
#define es_Auto3365   "Production"
#define de_Auto3365   "Production"
#define nl_Auto3365   "Production"
#define pt_Auto3365   "Production"
#define xx_Auto3365   "Production"
#define en__Auto3365   ""
#define en_Auto3366   "Page Items"
#define fr_Auto3366   "Items Page / Onglet"
#define it_Auto3366   "Page Items"
#define es_Auto3366   "Page Items"
#define de_Auto3366   "Page Items"
#define nl_Auto3366   "Page Items"
#define pt_Auto3366   "Page Items"
#define xx_Auto3366   "Page Items"
#define en__Auto3366   ""
#define fr__Auto3366   ""
#define it__Auto3366   ""
#define es__Auto3366   ""
#define de__Auto3366   ""
#define nl__Auto3366   ""
#define pt__Auto3366   ""
#define xx__Auto3366   ""
#define en_Auto3367   "List Lines"
#define fr_Auto3367   "Nombre de Lignes"
#define it_Auto3367   "Production"
#define es_Auto3367   "Production"
#define de_Auto3367   "Production"
#define nl_Auto3367   "Production"
#define pt_Auto3367   "Production"
#define xx_Auto3367   "Production"
#define en__Auto3367   ""
#define fr__Auto3367   ""
#define en_Auto3368   "List Columns"
#define fr_Auto3368   "Colonnes Texte"
#define it_Auto3368   "Production"
#define es_Auto3368   "Production"
#define de_Auto3368   "Production"
#define nl_Auto3368   "Production"
#define pt_Auto3368   "Production"
#define xx_Auto3368   "Production"
#define en__Auto3368   ""
#define fr__Auto3368   ""
#define en_Auto3369   "Column Width Limit"
#define fr_Auto3369   "Largeur Max Colonne"
#define it_Auto3369   "Production"
#define es_Auto3369   "Production"
#define de_Auto3369   "Production"
#define nl_Auto3369   "Production"
#define pt_Auto3369   "Production"
#define xx_Auto3369   "Production"
#define en__Auto3369   ""
#define fr__Auto3369   ""
#define en_StubName   ""
#define fr_StubName   ""
#define en__StubName   ""
#define en_EditBase   "bille.gif"
#define fr_EditBase   "bille.gif"
#define it_EditBase   "bille.gif"
#define es_EditBase   "bille.gif"
#define de_EditBase   "bille.gif"
#define nl_EditBase   "bille.gif"
#define pt_EditBase   "bille.gif"
#define xx_EditBase   "bille.gif"
#define en_ViewList   "bille.gif"
#define fr_ViewList   "bille.gif"
#define it_ViewList   "bille.gif"
#define es_ViewList   "bille.gif"
#define de_ViewList   "bille.gif"
#define nl_ViewList   "bille.gif"
#define pt_ViewList   "bille.gif"
#define xx_ViewList   "bille.gif"
#define en__ViewList   ""
#define en_BaseFile   ""
#define en_FormName   ""
#define en_ListName   ""
#define en__ListName   ""
#define en_EditFile   "bille.gif"
#define fr_EditFile   "bille.gif"
#define it_EditFile   "bille.gif"
#define es_EditFile   "bille.gif"
#define de_EditFile   "bille.gif"
#define nl_EditFile   "bille.gif"
#define pt_EditFile   "bille.gif"
#define xx_EditFile   "bille.gif"
#define en_Title   ""
#define en_Language   "Program|Overlay|Module|File"
#define fr_Language   "Program|Overlay|Module|File"
#define it_Language   "Program|Overlay|Module|File"
#define es_Language   "Program|Overlay|Module|File"
#define de_Language   "Program|Overlay|Module|File"
#define nl_Language   "Program|Overlay|Module|File"
#define pt_Language   "Program|Overlay|Module|File"
#define xx_Language   "Program|Overlay|Module|File"
#define en__Language   ""
#define en_PageItems   ""
#define en__PageItems   ""
#define en_ListLines   ""
#define fr_ListLines   ""
#define en__ListLines   ""
#define fr__ListLines   ""
#define en_ListColumns   ""
#define en__ListColumns   ""
#define en_MaxColumn   ""
#define fr_MaxColumn   ""
#define en__MaxColumn   ""
#define fr__MaxColumn   ""
#define en_GenerateMask   "Generate File &Mask"
#define fr_GenerateMask   "G‚n‚rer Masque Fichier"
#define it_GenerateMask   "Generate"
#define es_GenerateMask   "Generate"
#define de_GenerateMask   "Generate"
#define nl_GenerateMask   "Generate"
#define pt_GenerateMask   "Generate"
#define xx_GenerateMask   "Generate"
#define en__GenerateMask   ""
#define fr__GenerateMask   ""
#define en_GeneratePage   "Generate File &Printout"
#define fr_GeneratePage   "G‚n‚rer Edition Fichier"
#define it_GeneratePage   "Generate"
#define es_GeneratePage   "Generate"
#define de_GeneratePage   "Generate"
#define nl_GeneratePage   "Generate"
#define pt_GeneratePage   "Generate"
#define xx_GeneratePage   "Generate"
#define en__GeneratePage   ""
#define fr__GeneratePage   ""
#define en_GenerateList   "&Generate File List"
#define fr_GenerateList   "G‚n‚rer Liste Fichier"
#define it_GenerateList   "Generate"
#define es_GenerateList   "Generate"
#define de_GenerateList   "Generate"
#define nl_GenerateList   "Generate"
#define pt_GenerateList   "Generate"
#define xx_GenerateList   "Generate"
#define en__GenerateList   ""
#define fr__GenerateList   ""
#define en_ImportBase   "&Import"
#define fr_ImportBase   "Import"
#define it_ImportBase   "Import"
#define es_ImportBase   "Import"
#define de_ImportBase   "Import"
#define nl_ImportBase   "Import"
#define pt_ImportBase   "Import"
#define xx_ImportBase   "Import"
#define en__ImportBase   ""
#define en_ExportBase   "&Export"
#define fr_ExportBase   "Export"
#define it_ExportBase   "Export"
#define es_ExportBase   "Export"
#define de_ExportBase   "Export"
#define nl_ExportBase   "Export"
#define pt_ExportBase   "Export"
#define xx_ExportBase   "Export"
#define en__ExportBase   ""
#define en_ListBase   "List"
#define fr_ListBase   "Liste"
#define it_ListBase   "List"
#define es_ListBase   "List"
#define de_ListBase   "List"
#define nl_ListBase   "List"
#define pt_ListBase   "List"
#define xx_ListBase   "List"
#define en__ListBase   ""
#define fr__ListBase   ""
#define it__ListBase   ""
#define es__ListBase   ""
#define de__ListBase   ""
#define nl__ListBase   ""
#define pt__ListBase   ""
#define xx__ListBase   ""
#define en_NationalHelptext   "natlang.gif"
#define fr_NationalHelptext   "natlang.gif"
#define it_NationalHelptext   "natlang.gif"
#define es_NationalHelptext   "natlang.gif"
#define de_NationalHelptext   "natlang.gif"
#define nl_NationalHelptext   "natlang.gif"
#define pt_NationalHelptext   "natlang.gif"
#define xx_NationalHelptext   "natlang.gif"
#define en__NationalHelptext   ""
#define fr__NationalHelptext   ""
#define it__NationalHelptext   ""
#define es__NationalHelptext   ""
#define de__NationalHelptext   ""
#define nl__NationalHelptext   ""
#define pt__NationalHelptext   ""
#define xx__NationalHelptext   ""
#define en_ExportForm   "Form Data Collection"
#define fr_ExportForm   "Structure d'un formulaire"
#define it_ExportForm   "Form Data Collection"
#define es_ExportForm   "Form Data Collection"
#define de_ExportForm   "Form Data Collection"
#define nl_ExportForm   "Form Data Collection"
#define pt_ExportForm   "Form Data Collection"
#define xx_ExportForm   "Form Data Collection"
#define en__ExportForm   ""
#define fr__ExportForm   ""
#define it__ExportForm   ""
#define es__ExportForm   ""
#define de__ExportForm   ""
#define nl__ExportForm   ""
#define pt__ExportForm   ""
#define xx__ExportForm   ""
#define en_DeleteBase   "Reset &Database"
#define fr_DeleteBase   "RAZ de la Base"
#define it_DeleteBase   "Reset Database"
#define es_DeleteBase   "Reset Database"
#define de_DeleteBase   "Reset Database"
#define nl_DeleteBase   "Reset Database"
#define pt_DeleteBase   "Reset Database"
#define xx_DeleteBase   "Reset Database"
#define en__DeleteBase   ""
#define fr__DeleteBase   ""
#define it__DeleteBase   ""
#define es__DeleteBase   ""
#define de__DeleteBase   ""
#define nl__DeleteBase   ""
#define pt__DeleteBase   ""
#define xx__DeleteBase   ""

private struct old_database_editor_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[3+1];
	char * msg_Auto3333[8];
	char * hint_Auto3333[8];
	int	x_Auto3333;
	int	y_Auto3333;
	int	w_Auto3333;
	int	h_Auto3333;
	char * msg_ListPage[8];
	int	trigger_ListPage;
	char * hint_ListPage[8];
	int	page_number;
	char * msg_Auto3334[8];
	char * hint_Auto3334[8];
	char * msg_Auto3335[8];
	char * hint_Auto3335[8];
	char * hint_BaseName[8];
	char	buffer_BaseName[50];
	char * hint_BaseUsers[8];
	char	buffer_BaseUsers[8];
	char * msg_FileList[8];
	char * hint_FileList[8];
	int	value_FileList;
	int	column_FileList;
	char	buffer_FileList[27][88];
	int	formsort_FileList;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_FileList;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_FileList;	/* numéro d'ordre des elements triés */
	char	*indsort_FileList;	/* pointeur table intermédiaire de tri */
	int	nelt_FileList;	/* nombre d'eléments aloués dans tabsort */
	char * row_FileList;
	char * hint_Mursor[8];
	int	x_Mursor;
	int	y_Mursor;
	int	w_Mursor;
	int	h_Mursor;
	int	fg_Mursor;
	int	bg_Mursor;
	int	fid_Mursor;
	char * msg_Auto3336[8];
	char * hint_Auto3336[8];
	char * hint_ScrollBar[8];
	int	value_ScrollBar;
	int	limit_ScrollBar;
	int	max_ScrollBar;
	char * msg_CopyFile[8];
	int	trigger_CopyFile;
	char * hint_CopyFile[8];
	char * msg_DeleteFile[8];
	int	trigger_DeleteFile;
	char * hint_DeleteFile[8];
	char * msg_PasteFile[8];
	int	trigger_PasteFile;
	char * hint_PasteFile[8];
	int	s_PasteFile;
	void *	p_PasteFile;
	char * msg_FilePage[8];
	int	trigger_FilePage;
	char * hint_FilePage[8];
	char * hint_Auto3337[8];
	char * hint_Auto3338[8];
	char * msg_Auto3339[8];
	char * hint_Auto3339[8];
	char * msg_Auto3340[8];
	char * hint_Auto3340[8];
	char * msg_Auto3341[8];
	char * hint_Auto3341[8];
	char * hint_ClassName[8];
	char	buffer_ClassName[256];
	char * hint_Instance[8];
	char	buffer_Instance[256];
	char * hint_Filename[8];
	char	buffer_Filename[256];
	char * msg_FileType[8];
	char * hint_FileType[8];
	int	value_FileType;
	char * msg_IndexType[8];
	char * hint_IndexType[8];
	int	value_IndexType;
	char * hint_IndexSize[8];
	char	buffer_IndexSize[9];
	char * msg_Auto3342[8];
	int	trigger_Auto3342;
	char * hint_Auto3342[8];
	char * hint_NbIndex[8];
	char	buffer_NbIndex[6];
	char * msg_Auto3343[8];
	int	trigger_Auto3343;
	char * hint_Auto3343[8];
	char * msg_RecordType[8];
	int	trigger_RecordType;
	char * hint_RecordType[8];
	int	value_RecordType;
	char * msg_MarkerUseage[8];
	int	trigger_MarkerUseage;
	char * hint_MarkerUseage[8];
	int	value_MarkerUseage;
	char * msg_Modext[8];
	int	trigger_Modext;
	char * hint_Modext[8];
	int	value_Modext;
	char * hint_RecordSize[8];
	char	buffer_RecordSize[9];
	char * msg_Auto3344[8];
	int	trigger_Auto3344;
	char * hint_Auto3344[8];
	char * hint_NbData[8];
	char	buffer_NbData[6];
	char * msg_Auto3345[8];
	int	trigger_Auto3345;
	char * hint_Auto3345[8];
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_FileUsers[8];
	int	trigger_FileUsers;
	char * hint_FileUsers[8];
	char * msg_Auto3346[8];
	char * hint_Auto3346[8];
	char * msg_Auto3347[8];
	char * hint_Auto3347[8];
	char * msg_Auto3348[8];
	char * hint_Auto3348[8];
	char * msg_Auto3349[8];
	char * hint_Auto3349[8];
	char * msg_Auto3350[8];
	char * hint_Auto3350[8];
	char * msg_Auto3351[8];
	char * hint_Auto3351[8];
	char * msg_IndexMembers[8];
	char * hint_IndexMembers[8];
	int	value_IndexMembers;
	int	column_IndexMembers;
	char	buffer_IndexMembers[5][87];
	int	formsort_IndexMembers;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_IndexMembers;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_IndexMembers;	/* numéro d'ordre des elements triés */
	char	*indsort_IndexMembers;	/* pointeur table intermédiaire de tri */
	int	nelt_IndexMembers;	/* nombre d'eléments aloués dans tabsort */
	char * row_IndexMembers;
	char * hint_Cursor[8];
	int	x_Cursor;
	int	y_Cursor;
	int	w_Cursor;
	int	h_Cursor;
	int	fg_Cursor;
	int	bg_Cursor;
	int	fid_Cursor;
	char * msg_IsLink[8];
	char * hint_IsLink[8];
	int	x_IsLink;
	int	y_IsLink;
	int	w_IsLink;
	int	h_IsLink;
	int	fg_IsLink;
	int	bg_IsLink;
	int	fid_IsLink;
	char * msg_IsList[8];
	char * hint_IsList[8];
	int	x_IsList;
	int	y_IsList;
	int	w_IsList;
	int	h_IsList;
	int	fg_IsList;
	int	bg_IsList;
	int	fid_IsList;
	char * hint_IndexBar[8];
	int	value_IndexBar;
	int	limit_IndexBar;
	int	max_IndexBar;
	char * msg_DataMembers[8];
	char * hint_DataMembers[8];
	int	value_DataMembers;
	int	column_DataMembers;
	char	buffer_DataMembers[17][87];
	int	formsort_DataMembers;	/* sort 0 rien, positif numéro de colonne, négatif, numéro de colonne tri decroissant */
	char	*libsort_DataMembers;	/* table intermédiaire contenant la liste des éléments a trier */
	int	*tabsort_DataMembers;	/* numéro d'ordre des elements triés */
	char	*indsort_DataMembers;	/* pointeur table intermédiaire de tri */
	int	nelt_DataMembers;	/* nombre d'eléments aloués dans tabsort */
	char * row_DataMembers;
	char * hint_Kursor[8];
	int	x_Kursor;
	int	y_Kursor;
	int	w_Kursor;
	int	h_Kursor;
	int	fg_Kursor;
	int	bg_Kursor;
	int	fid_Kursor;
	char * hint_DataBar[8];
	int	value_DataBar;
	int	limit_DataBar;
	int	max_DataBar;
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
	char * msg_MaskPage[8];
	int	trigger_MaskPage;
	char * hint_MaskPage[8];
	char * hint_Auto3352[8];
	char * msg_Auto3353[8];
	char * hint_Auto3353[8];
	char * msg_Auto3354[8];
	char * hint_Auto3354[8];
	char * msg_Auto3355[8];
	char * hint_Auto3355[8];
	char * hint_Auto3356[8];
	char * hint_Auto3357[8];
	char * msg_Auto3358[8];
	char * hint_Auto3358[8];
	char * msg_Auto3359[8];
	char * hint_Auto3359[8];
	char * msg_Auto3360[8];
	char * hint_Auto3360[8];
	char * msg_Auto3361[8];
	char * hint_Auto3361[8];
	char * msg_Auto3362[8];
	char * hint_Auto3362[8];
	char * msg_Auto3363[8];
	char * hint_Auto3363[8];
	char * msg_Auto3364[8];
	char * hint_Auto3364[8];
	char * msg_Auto3365[8];
	char * hint_Auto3365[8];
	char * msg_Auto3366[8];
	char * hint_Auto3366[8];
	char * msg_Auto3367[8];
	char * hint_Auto3367[8];
	char * msg_Auto3368[8];
	char * hint_Auto3368[8];
	char * msg_Auto3369[8];
	char * hint_Auto3369[8];
	char * hint_StubName[8];
	char	buffer_StubName[256];
	char * msg_EditBase[8];
	int	trigger_EditBase;
	char * hint_EditBase[8];
	char * msg_ViewList[8];
	int	trigger_ViewList;
	char * hint_ViewList[8];
	char * hint_BaseFile[8];
	char	buffer_BaseFile[256];
	char * hint_FormName[8];
	char	buffer_FormName[256];
	char * hint_ListName[8];
	char	buffer_ListName[256];
	char * msg_EditFile[8];
	int	trigger_EditFile;
	char * hint_EditFile[8];
	char * hint_Title[8];
	char	buffer_Title[256];
	char * msg_Language[8];
	char * hint_Language[8];
	int	value_Language;
	char * hint_PageItems[8];
	char	buffer_PageItems[8];
	char * hint_ListLines[8];
	char	buffer_ListLines[8];
	char * hint_ListColumns[8];
	char	buffer_ListColumns[8];
	char * hint_MaxColumn[8];
	char	buffer_MaxColumn[8];
	char * msg_GenerateMask[8];
	int	trigger_GenerateMask;
	char * hint_GenerateMask[8];
	char * msg_GeneratePage[8];
	int	trigger_GeneratePage;
	char * hint_GeneratePage[8];
	char * msg_GenerateList[8];
	int	trigger_GenerateList;
	char * hint_GenerateList[8];
	char * msg_ImportBase[8];
	int	trigger_ImportBase;
	char * hint_ImportBase[8];
	char * msg_ExportBase[8];
	int	trigger_ExportBase;
	char * hint_ExportBase[8];
	char * msg_ListBase[8];
	int	trigger_ListBase;
	char * hint_ListBase[8];
	char * msg_NationalHelptext[8];
	int	trigger_NationalHelptext;
	char * hint_NationalHelptext[8];
	char * msg_ExportForm[8];
	int	trigger_ExportForm;
	char * hint_ExportForm[8];
	char * msg_DeleteBase[8];
	int	trigger_DeleteBase;
	char * hint_DeleteBase[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[1];
	};
static int	vfh[16];
struct file_control  * allocate_file_control(struct old_database_editor_context * _Context);
void	liberate_file_control(struct old_database_editor_context * _Context,struct file_control * fptr);
void	initialise_file_manager(struct old_database_editor_context * _Context);
void	liberate_file_manager(struct old_database_editor_context * _Context,struct file_manager * fmptr);
static struct file_control  * locate_file(struct old_database_editor_context * _Context,int number);
static void	putstring(struct old_database_editor_context * _Context,char * rptr, int rlen, char * sptr);
static char	 * copystring(struct old_database_editor_context * _Context,char * sptr, int slen);
void	AddFileMember(struct old_database_editor_context * _Context,char * iptr, char * nptr, char * format,                   char * hptr, char * cptr, int type);
short	convert_integer(struct old_database_editor_context * _Context,char * sptr, int slen);
static void	reallocate(struct old_database_editor_context * _Context,char ** rptr, char * sptr, int slen);
struct file_control  * AddFileClass(struct old_database_editor_context * _Context,int type, char * cname, char * oname,                      char * fname, char * format);
char	 * AddFileObject(struct old_database_editor_context * _Context,int type, char * iname, char * fname, char * format,       char * hname);
static void	adjust_members(struct old_database_editor_context * _Context,int operation);
void	use_data_selector(struct old_database_editor_context * _Context,char * rptr,int rlen,                                      char * iptr,int ilen,                                      char * nptr, int nlen);
static short	locate_class(struct old_database_editor_context * _Context,char * nptr, int nlen);
struct data_control  * resolve_class_data(struct old_database_editor_context * _Context,char * classname);
void	mask_progression(struct old_database_editor_context * _Context,int value, int max);
static char	 * DataRecordLabel(struct old_database_editor_context * _Context);
static char	 * PrimaryIndexLabel(struct old_database_editor_context * _Context);
static void	reset_database(struct old_database_editor_context * _Context);
static short	GetFileNumber(struct old_database_editor_context * _Context);
void	check_file_datalength(struct old_database_editor_context * _Context);
struct file_manager  * allocate_file_manager(struct old_database_editor_context * _Context,char * nptr);
void	release_file_manager(struct old_database_editor_context * _Context,struct file_manager * fptr);
void	check_file_indexlength(struct old_database_editor_context * _Context);
void	use_file_manager(struct old_database_editor_context * _Context,struct file_manager * fptr);
void	file_manager_usage(struct old_database_editor_context * _Context,struct file_manager * fptr);
struct file_manager  * resolve_file_manager(struct old_database_editor_context * _Context,char * nptr);
static void	copy_file_control(struct old_database_editor_context * _Context);
void	drop_file_control(struct old_database_editor_context * _Context,struct file_control * fptr);
void	duplicate_file_comment(struct old_database_editor_context * _Context,struct file_control * rptr, struct file_control * sptr);
void	transfer_file_comment(struct old_database_editor_context * _Context,struct file_control * rptr, struct file_control * sptr);
struct file_control  * duplicate_file_control(struct old_database_editor_context * _Context,struct file_control * xptr);
static short	convert_decimal(struct old_database_editor_context * _Context,char * sptr, int slen, int decimal);
private int  sort_item_FileList(struct old_database_editor_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_FileList(struct old_database_editor_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_FileList(struct old_database_editor_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_FileList */
private int compare_FileList(struct old_database_editor_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_FileList */
private int  sort_item_IndexMembers(struct old_database_editor_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_IndexMembers(struct old_database_editor_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_IndexMembers(struct old_database_editor_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_IndexMembers */
private int compare_IndexMembers(struct old_database_editor_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_IndexMembers */
private int  sort_item_DataMembers(struct old_database_editor_context * _Context,int nelts);	/* returns resolved sort item */
private void start_sort_DataMembers(struct old_database_editor_context * _Context,int nelts);	/* allocate intermediate sort table */
private void sort_DataMembers(struct old_database_editor_context * _Context,int nelts);	/* sort the intermediate table into _Context->tabsort_DataMembers */
private int compare_DataMembers(struct old_database_editor_context * _Context,int a,int b);	/* compare the elements a et b of _Context->libsort_DataMembers */

/*	--------------------------------------------	*/
/*	a l l o c a t e _ f i l e _ c o n t r o l ()	*/
/*	--------------------------------------------	*/
struct file_control  * allocate_file_control(struct old_database_editor_context * _Context){
	int i;
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
	fptr->doctool=0;
	fptr->x=fptr->y=-1;
	fptr->state=0;
	for(i=0;i<8;i++){fptr->document[i]=(char*)0;}
	return(fptr);

}

/*	--------------------------------------------	*/
/*	l i b e r a t e _ f i l e _ c o n t r o l ()	*/
/*	--------------------------------------------	*/
void	liberate_file_control(struct old_database_editor_context * _Context,struct file_control * fptr){
	int i;
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
	for(i=0;i<8;i++){
	if(fptr->document[i]){
	liberate(fptr->document[i]);
	}
	}
	liberate(fptr);
	}
	return;

}

/*	------------------------------------------------	*/
/*	i n i t i a l i s e _ f i l e _ m a n a g e r ()	*/
/*	------------------------------------------------	*/
void	initialise_file_manager(struct old_database_editor_context * _Context){
	FileManager->firstlink=
	FileManager->lastlink=(struct link_control*)0;
	FileManager->first=
	FileManager->current=
	FileManager->last=(struct file_control*)0;
	return;

}

/*	--------------------------------------------	*/
/*	l i b e r a t e _ f i l e _ m a n a g e r ()	*/
/*	--------------------------------------------	*/
void	liberate_file_manager(struct old_database_editor_context * _Context,struct file_manager * fmptr){
	struct file_control*fptr;
	if(fmptr){
	while((fptr=fmptr->first)!=(struct file_control*)0){
	fmptr->first=fptr->next;
	liberate_file_control(_Context, fptr);
	}
	liberate(fmptr);
	}
	return;

}

/*	------------------------	*/
/*	l o c a t e _ f i l e ()	*/
/*	------------------------	*/
static struct file_control  * locate_file(struct old_database_editor_context * _Context,int number){
	struct file_control*fptr;
	struct file_control*xptr;
	for(fptr=FileManager->first;
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
	FileManager->first=xptr;
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
	if(!(fptr->previous=FileManager->last))
	FileManager->last=fptr;
	else fptr->previous->next=fptr;
	if(!(FileManager->first)){
	FileManager->first=fptr;
	FileManager->current=fptr;
	}
	FileManager->last=fptr;
	fptr->payload=analyse_data_control(" ");
	}
	}
	return(fptr);

}

/*	--------------------	*/
/*	p u t s t r i n g ()	*/
/*	--------------------	*/
static void	putstring(struct old_database_editor_context * _Context,char * rptr, int rlen, char * sptr){
	int i;
	if(!(sptr))
	return;
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
static char	 * copystring(struct old_database_editor_context * _Context,char * sptr, int slen){
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
void	AddFileMember(struct old_database_editor_context * _Context,char * iptr, char * nptr, char * format,                   char * hptr, char * cptr, int type){
	return;

}

/*	--------------------------------	*/
/*	c o n v e r t _ i n t e g e r ()	*/
/*	--------------------------------	*/
short	convert_integer(struct old_database_editor_context * _Context,char * sptr, int slen){
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
	else break;
	}
	return(l);

}

/*	----------------------	*/
/*	r e a l l o c a t e ()	*/
/*	----------------------	*/
static void	reallocate(struct old_database_editor_context * _Context,char ** rptr, char * sptr, int slen){
	int i;
	int l;
	char*vptr;
	if(*rptr){
	liberate(*rptr);
	*rptr=(char*)0;
	}
	for(l=0,i=0;i<slen;i++){
	if(!(*(sptr+i)))
	break;
	else if(*(sptr+i)!=' ')
	l=(i+1);
	}
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
struct file_control  * AddFileClass(struct old_database_editor_context * _Context,int type, char * cname, char * oname,                      char * fname, char * format){
	int number=0;
	struct file_control*fptr;
	/*--------------------------------------------*/
	/*Called from the XML DATABASE Application*/
	/*Parser to Add a database file class*/
	/*search for a similar named class*/
	/*--------------------------------------------*/
	if(!(cname))
	return((struct file_control*)0);
	for(fptr=FileManager->first;
	fptr!=(struct file_control*)0;
	fptr=fptr->next){
	if(!(fptr->classname)){
	number=fptr->number;
	break;
	}
	else if(strcmp(fptr->classname,cname)==0)
	return(fptr);
	else continue;
	}
	if(!(number)){
	if(!(FileManager->last))
	number=1;
	else number=(FileManager->last->number+1);
	}
	if(!(fptr=locate_file(_Context, number)))
	return(fptr);
	else{
	if(fptr->classname)
	liberate(fptr->classname);
	if(!(fptr->classname=allocate_string(cname)))
	return(fptr);
	if(oname){
	if(fptr->identity)
	liberate(fptr->identity);
	fptr->identity=allocate_string(oname);
	}
	if(fname){
	if(fptr->filename)
	liberate(fptr->filename);
	fptr->filename=allocate_string(fname);
	}
	if(format){
	if(fptr->format)
	liberate(fptr->format);
	fptr->format=allocate_string(format);
	}
	fptr->nature=type;
	if(fptr->payload)
	drop_data_control(fptr->payload);
	fptr->payload=analyse_data_control(fptr->format);
	return(fptr);
	}

}

/*	----------------------------	*/
/*	A d d F i l e O b j e c t ()	*/
/*	----------------------------	*/
char	 * AddFileObject(struct old_database_editor_context * _Context,int type, char * iname, char * fname, char * format,       char * hname){
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
	for(fptr=FileManager->first;
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
	if(!(FileManager->last))
	number=1;
	else number=(FileManager->last->number+1);
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
static void	adjust_members(struct old_database_editor_context * _Context,int operation){
	int i;
	struct data_control*dptr;
	char buffer[64];
	if(!(FileManager->current))
	return;
	else if(!(dptr=FileManager->current->payload))
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
void	use_data_selector(struct old_database_editor_context * _Context,char * rptr,int rlen,                                      char * iptr,int ilen,                                      char * nptr, int nlen){
	char buffer[256];
	if(*rptr=='(')
	locate_class(_Context, rptr,rlen);
	if(old_database_editor()!=27){
	if((FileManager->current)
	&&(FileManager->current->classname)){
	if(rlen){
	sprintf(buffer,"(%s)",FileManager->current->classname);
	putstring(_Context, rptr,rlen,buffer);
	}
	if(ilen){
	putstring(_Context, iptr,ilen,FileManager->current->identity);
	}
	if(nlen){
	putstring(_Context, nptr,nlen,FileManager->current->filename);
	}
	}
	}

}

/*	--------------------------	*/
/*	l o c a t e _ c l a s s ()	*/
/*	--------------------------	*/
static short	locate_class(struct old_database_editor_context * _Context,char * nptr, int nlen){
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
	for(fptr=FileManager->first;
	fptr!=(struct file_control*)0;
	fptr=fptr->next){
	if(!(fptr->classname))
	continue;
	else if(strcmp(fptr->classname,cname)==0){
	FileManager->current=fptr;
	return(1);
	}
	else continue;
	}
	return(0);

}

/*	--------------------------------------	*/
/*	r e s o l v e _ c l a s s _ d a t a ()	*/
/*	--------------------------------------	*/
struct data_control  * resolve_class_data(struct old_database_editor_context * _Context,char * classname){
	if(!(classname))
	return((struct data_control*)0);
	else if(!(locate_class(_Context, classname,strlen(classname))))
	return((struct data_control*)0);
	else if(!(FileManager->current))
	return((struct data_control*)0);
	else return(FileManager->current->payload);
	
}

/*	----------------------------------	*/
/*	m a s k _ p r o g r e s s i o n ()	*/
/*	----------------------------------	*/
void	mask_progression(struct old_database_editor_context * _Context,int value, int max){
	;

}

/*	--------------------------------	*/
/*	D a t a R e c o r d L a b e l ()	*/
/*	--------------------------------	*/
static char	 * DataRecordLabel(struct old_database_editor_context * _Context){
	switch(_Context->value_FileType){
	case 5:
	return("File Handle");
	case 3:
	case 4:
	case 6:
	case 7:
	return("Data Record");
	default:
	return("N/A");
	}

}

/*	------------------------------------	*/
/*	P r i m a r y I n d e x L a b e l ()	*/
/*	------------------------------------	*/
static char	 * PrimaryIndexLabel(struct old_database_editor_context * _Context){
	switch(_Context->value_FileType){
	case 3:
	case 4:
	case 7:
	return("Primary Index");
	default:
	return("N/A");
	}

}

/*	------------------------------	*/
/*	r e s e t _ d a t a b a s e ()	*/
/*	------------------------------	*/
static void	reset_database(struct old_database_editor_context * _Context){
	struct file_control*fptr;
	for(fptr=FileManager->first;
	fptr!=(struct file_control*)0;
	fptr=fptr->next){
	if(fptr->classname){
	liberate(fptr->classname);
	fptr->classname=(char*)0;
	}
	if(fptr->identity){
	liberate(fptr->identity);
	fptr->identity=(char*)0;
	}
	if(fptr->filename){
	liberate(fptr->filename);
	fptr->filename=(char*)0;
	}
	if(fptr->format){
	liberate(fptr->format);
	fptr->format=(char*)0;
	}
	if(fptr->payload){
	fptr->payload=(void*)0;
	}
	if(fptr->indextype){
	liberate(fptr->indextype);
	fptr->indextype=(char*)0;
	}
	if(fptr->recordtype){
	liberate(fptr->recordtype);
	fptr->recordtype=(char*)0;
	}
	}
	return;

}

/*	----------------------------	*/
/*	G e t F i l e N u m b e r ()	*/
/*	----------------------------	*/
static short	GetFileNumber(struct old_database_editor_context * _Context){
	int max=0;
	struct file_control*fptr;
	for(fptr=FileManager->first;fptr!=(struct file_control*)NULL;fptr=fptr->next)
	{
	if(((fptr->classname)||(fptr->identity))&&
	(max<fptr->number))
	max=fptr->number;
	};
	return(max);

}

/*	--------------------------------------------	*/
/*	c h e c k _ f i l e _ d a t a l e n g t h ()	*/
/*	--------------------------------------------	*/
void	check_file_datalength(struct old_database_editor_context * _Context){
	int j;
	int i;
	int l=0;
	int recordsize=0;
	int fieldsize=0;
	int offset=0;
	struct data_control*dptr;
	if(!(dptr=FileManager->current->payload)){
	return;
	}
	else if(!(dptr->datafields)){
	return;
	}
	for(i=0;i<dptr->datafields;i++){
	if(dptr->type[i+dptr->indexfields]==_ABAL_FIELD){
	for(j=0;j<i;j++){
	if(!(strcmp(dptr->name[j+dptr->indexfields],dptr->name[i+dptr->indexfields]))){
	/*fieldsize=dptr->width[j+dptr->indexfields];*/
	offset=dptr->offset[j+dptr->indexfields];
	break;
	}
	}
	continue;
	}
	else{
	dptr->offset[i+dptr->indexfields]=offset;
	l=dptr->width[i+dptr->indexfields];
	if(dptr->first[i+dptr->indexfields]){
	l*=dptr->first[i+dptr->indexfields];
	if(dptr->second[i+dptr->indexfields]){
	l*=dptr->second[i+dptr->indexfields];
	}
	}
	offset+=l;
	if(offset>recordsize)
	recordsize=offset;
	#ifdef OLD_SIZE_CALCULATIONS
	if(!(fieldsize))
	recordsize+=l;
	else if(l<fieldsize)
	fieldsize-=l;
	else{
	l-=fieldsize;
	fieldsize=0;
	recordsize+=l;
	}
	#endif
	}
	}
	if(dptr->datalength<recordsize){
	dptr->datalength=recordsize;
	}
	return;

}

/*	--------------------------------------------	*/
/*	a l l o c a t e _ f i l e _ m a n a g e r ()	*/
/*	--------------------------------------------	*/
struct file_manager  * allocate_file_manager(struct old_database_editor_context * _Context,char * nptr){
	struct file_manager*fptr;
	if(!(fptr=allocate(sizeof(struct file_manager))))
	return(fptr);
	else if(!(fptr->name=allocate(strlen(nptr)+1))){
	liberate(fptr);
	return((struct file_manager*)0);
	}
	else{
	strcpy(fptr->name,nptr);
	fptr->usage=0;
	fptr->first=
	fptr->last=
	fptr->current=(struct file_control*)0;
	fptr->firstlink=
	fptr->lastlink=(struct link_control*)0;
	fptr->previous=
	fptr->next=(struct file_manager*)0;
	if(!(fptr->previous=BaseManager.last))
	BaseManager.first=fptr;
	else BaseManager.last->next=fptr;
	BaseManager.last=fptr;
	return(fptr);
	}

}

/*	------------------------------------------	*/
/*	r e l e a s e _ f i l e _ m a n a g e r ()	*/
/*	------------------------------------------	*/
void	release_file_manager(struct old_database_editor_context * _Context,struct file_manager * fptr){
	if(fptr){
	if(fptr->usage)
	fptr->usage--;
	if(!(fptr->usage)){
	/*release the file manager contents*/
	/*---------------------------------*/
	if(fptr->name)
	fptr->name=liberate(fptr->name);
		/*disconnect it from the data base list*/
	/*-------------------------------------*/
	if(!(fptr->previous))
	BaseManager.first=fptr->next;
	else fptr->previous->next=fptr->next;
	if(!(fptr->next))
	BaseManager.last=fptr->previous;
	else fptr->next->previous=fptr->previous;
	liberate_file_manager(_Context, fptr);
		}
	}
	
}

/*	----------------------------------------------	*/
/*	c h e c k _ f i l e _ i n d e x l e n g t h ()	*/
/*	----------------------------------------------	*/
void	check_file_indexlength(struct old_database_editor_context * _Context){
	int j;
	int i;
	int l=0;
	int recordsize=0;
	int fieldsize=0;
	int offset=0;
	struct data_control*dptr;
	if(!(dptr=FileManager->current->payload)){
	return;
	}
	else if(!(dptr->indexfields)){
	return;
	}
	for(i=0;
	i<dptr->indexfields;
	i++){
	if(dptr->type[i]==_ABAL_FIELD){
	for(j=0;
	j<i;
	j++){
	if(!(strcmp(dptr->name[j],dptr->name[i]))){
	/*fieldsize=dptr->width[j];*/
	offset=dptr->offset[j];
	break;
	}
	}
	continue;
	}
	else{
	l=dptr->width[i];
	dptr->offset[i]=offset;
	if(dptr->first[i]){
	l*=dptr->first[i];
	if(dptr->second[i]){
	l*=dptr->second[i];
	}
	}
	offset+=l;
	if(offset>recordsize)
	recordsize=offset;
	#ifdef OLD_SIZE_CALCULATIONS
	if(!(fieldsize))
	recordsize+=l;
	else if(l<fieldsize)
	fieldsize-=l;
	else{
	l-=fieldsize;
	fieldsize=0;
	recordsize+=l;
	}
	#endif
	}
	}
	if(dptr->indexlength<recordsize){
	dptr->indexlength=recordsize;
	}
	return;

}

/*	----------------------------------	*/
/*	u s e _ f i l e _ m a n a g e r ()	*/
/*	----------------------------------	*/
void	use_file_manager(struct old_database_editor_context * _Context,struct file_manager * fptr){
	if(!(BaseManager.current=FileManager=fptr)){
	FileManager=&xFileManager;
	}
	return;

}

/*	--------------------------------------	*/
/*	f i l e _ m a n a g e r _ u s a g e ()	*/
/*	--------------------------------------	*/
void	file_manager_usage(struct old_database_editor_context * _Context,struct file_manager * fptr){
	if(fptr)
	fptr->usage++;

}

/*	------------------------------------------	*/
/*	r e s o l v e _ f i l e _ m a n a g e r ()	*/
/*	------------------------------------------	*/
struct file_manager  * resolve_file_manager(struct old_database_editor_context * _Context,char * nptr){
	struct file_manager*fptr;
	if(!(nptr))
	return((struct file_manager*)0);
	for(fptr=BaseManager.first;
	fptr!=(struct file_manager*)0;
	fptr=fptr->next){
	if(!(fptr->name))
	continue;
	else if(!(strcmp(fptr->name,nptr)))
	break;
	}
	return(fptr);
	
}

/*	------------------------------------	*/
/*	c o p y _ f i l e _ c o n t r o l ()	*/
/*	------------------------------------	*/
static void	copy_file_control(struct old_database_editor_context * _Context){
	struct file_control*xptr;
	if(!(xptr=BaseManager.CopyFile))
	return;
	duplicate_file_control(_Context, xptr);
		old_database_editor_show(_Context);
;

}

/*	------------------------------------	*/
/*	d r o p _ f i l e _ c o n t r o l ()	*/
/*	------------------------------------	*/
void	drop_file_control(struct old_database_editor_context * _Context,struct file_control * fptr){
	if(!(fptr))
	return;
	else if(!(FileManager))
	return;
	if(!(fptr->previous))
	FileManager->first=fptr->next;
	else fptr->previous->next=fptr->next;
	if(!(fptr->next))
	FileManager->last=fptr->previous;
	else fptr->next->previous=fptr->previous;
	BaseManager.CopyFile=(struct file_control*)0;
	liberate_file_control(_Context, fptr);

}

/*	----------------------------------------------	*/
/*	d u p l i c a t e _ f i l e _ c o m m e n t ()	*/
/*	----------------------------------------------	*/
void	duplicate_file_comment(struct old_database_editor_context * _Context,struct file_control * rptr, struct file_control * sptr){
	int i;
	char*tptr;
	for(i=0;i<MAXNATLANG;i++){
	if(!(sptr->document[i]))
	continue;
	if(rptr->document[i])
	continue;
	rptr->document[i]=allocate_string(sptr->document[i]);
	}
	rptr->x=sptr->x;
	rptr->y=sptr->y;
	return;

}

/*	--------------------------------------------	*/
/*	t r a n s f e r _ f i l e _ c o m m e n t ()	*/
/*	--------------------------------------------	*/
void	transfer_file_comment(struct old_database_editor_context * _Context,struct file_control * rptr, struct file_control * sptr){
	int i;
	char*tptr;
	for(i=0;i<MAXNATLANG;i++){
	if(!(sptr->document[i]))
	continue;
	if(rptr->document[i])
	continue;
	rptr->document[i]=sptr->document[i];
	sptr->document[i]=(char*)0;
	}
	return;

}

/*	----------------------------------------------	*/
/*	d u p l i c a t e _ f i l e _ c o n t r o l ()	*/
/*	----------------------------------------------	*/
struct file_control  * duplicate_file_control(struct old_database_editor_context * _Context,struct file_control * xptr){
	char xclassname[256];
	int xnumber=0;
	struct file_control*xxptr;
	sprintf(xclassname,"%s",xptr->classname);
	while(locate_class(_Context, xclassname,strlen(xclassname))!=0){
	xnumber+=1;
	sprintf(xclassname,"%s_%u",xptr->classname,xnumber);
	}
	if((xxptr=AddFileClass(_Context,
	xptr->nature,
	xclassname,
	xptr->identity,
	xptr->filename,
	xptr->format))!=(struct file_control*)0){
	duplicate_file_comment(_Context, xxptr,xptr);
	xxptr->x=xptr->x;
	xxptr->y=xptr->y;
	xxptr->state=xptr->state;
	}
	return(xxptr);

}

/*	--------------------------------	*/
/*	c o n v e r t _ d e c i m a l ()	*/
/*	--------------------------------	*/
static short	convert_decimal(struct old_database_editor_context * _Context,char * sptr, int slen, int decimal){
	int i;
	for(i=0;i<slen;i++)
	if(*(sptr+i)=='.')
	return(convert_integer(_Context,(sptr+i+1),(slen-i)));
	return(decimal);

}
/* ------------------- */
/* resolve sorted item */
/* ------------------- */
private int  sort_item_FileList(struct old_database_editor_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_FileList[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_FileList(struct old_database_editor_context * _Context,int nelts)
{
if (_Context->nelt_FileList<nelts) {
	liberate(_Context->tabsort_FileList);
	if ((_Context->tabsort_FileList=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_FileList=0;_Context->nelt_FileList<nelts;_Context->nelt_FileList++)
		{ _Context->tabsort_FileList[_Context->nelt_FileList]=_Context->nelt_FileList+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_FileList=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_FileList=allocate(nelts*88)) != NULL)
	memset(_Context->libsort_FileList,' ',nelts*88);
}

/* ----------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_FileList */
/* ----------------------------------------------------------- */
private void sort_FileList(struct old_database_editor_context * _Context,int nelts)
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
private int compare_FileList(struct old_database_editor_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_FileList[88*a],&_Context->libsort_FileList[88*b],33);	/* comparaison zone 1 */
switch (_Context->formsort_FileList) {
	case 1:	/* Class ordre normal */
		return(i);

	case -1:	/* Class ordre inverse */
		return(-i);

	case 2:	/* Instance ordre normal */
		j=memicmp(&_Context->libsort_FileList[88*a+33],&_Context->libsort_FileList[88*b+33],33);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Instance ordre inverse */
		j=memicmp(&_Context->libsort_FileList[88*b+33],&_Context->libsort_FileList[88*a+33],33);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Record ordre normal */
		j=memicmp(&_Context->libsort_FileList[88*a+66],&_Context->libsort_FileList[88*b+66],11);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Record ordre inverse */
		j=memicmp(&_Context->libsort_FileList[88*b+66],&_Context->libsort_FileList[88*a+66],11);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* Index ordre normal */
		j=memicmp(&_Context->libsort_FileList[88*a+77],&_Context->libsort_FileList[88*b+77],11);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* Index ordre inverse */
		j=memicmp(&_Context->libsort_FileList[88*b+77],&_Context->libsort_FileList[88*a+77],11);
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
private int  sort_item_IndexMembers(struct old_database_editor_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_IndexMembers[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_IndexMembers(struct old_database_editor_context * _Context,int nelts)
{
if (_Context->nelt_IndexMembers<nelts) {
	liberate(_Context->tabsort_IndexMembers);
	if ((_Context->tabsort_IndexMembers=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_IndexMembers=0;_Context->nelt_IndexMembers<nelts;_Context->nelt_IndexMembers++)
		{ _Context->tabsort_IndexMembers[_Context->nelt_IndexMembers]=_Context->nelt_IndexMembers+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_IndexMembers=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_IndexMembers=allocate(nelts*87)) != NULL)
	memset(_Context->libsort_IndexMembers,' ',nelts*87);
}

/* --------------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_IndexMembers */
/* --------------------------------------------------------------- */
private void sort_IndexMembers(struct old_database_editor_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_IndexMembers,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_IndexMembers[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_IndexMembers[j]) && (compare_IndexMembers(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_IndexMembers[i]=k+1;
	_Context->indsort_IndexMembers[k]=1;
	};	/* for i */
liberate(_Context->libsort_IndexMembers);
liberate(_Context->indsort_IndexMembers);
}

/* ------------------------------------------------------------- */
/* compare the elements a et b of _Context->libsort_IndexMembers */
/* ------------------------------------------------------------- */
private int compare_IndexMembers(struct old_database_editor_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_IndexMembers[87*a],&_Context->libsort_IndexMembers[87*b],56);	/* comparaison zone 1 */
switch (_Context->formsort_IndexMembers) {
	case 1:	/* Name ordre normal */
		return(i);

	case -1:	/* Name ordre inverse */
		return(-i);

	case 2:	/* Type ordre normal */
		j=memicmp(&_Context->libsort_IndexMembers[87*a+56],&_Context->libsort_IndexMembers[87*b+56],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Type ordre inverse */
		j=memicmp(&_Context->libsort_IndexMembers[87*b+56],&_Context->libsort_IndexMembers[87*a+56],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Length ordre normal */
		j=memicmp(&_Context->libsort_IndexMembers[87*a+65],&_Context->libsort_IndexMembers[87*b+65],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Length ordre inverse */
		j=memicmp(&_Context->libsort_IndexMembers[87*b+65],&_Context->libsort_IndexMembers[87*a+65],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* 1st ordre normal */
		j=memicmp(&_Context->libsort_IndexMembers[87*a+71],&_Context->libsort_IndexMembers[87*b+71],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* 1st ordre inverse */
		j=memicmp(&_Context->libsort_IndexMembers[87*b+71],&_Context->libsort_IndexMembers[87*a+71],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 5:	/* 2nd ordre normal */
		j=memicmp(&_Context->libsort_IndexMembers[87*a+77],&_Context->libsort_IndexMembers[87*b+77],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -5:	/* 2nd ordre inverse */
		j=memicmp(&_Context->libsort_IndexMembers[87*b+77],&_Context->libsort_IndexMembers[87*a+77],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 6:	/* N ordre normal */
		j=memicmp(&_Context->libsort_IndexMembers[87*a+83],&_Context->libsort_IndexMembers[87*b+83],2);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -6:	/* N ordre inverse */
		j=memicmp(&_Context->libsort_IndexMembers[87*b+83],&_Context->libsort_IndexMembers[87*a+83],2);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 7:	/* Y ordre normal */
		j=memicmp(&_Context->libsort_IndexMembers[87*a+85],&_Context->libsort_IndexMembers[87*b+85],2);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -7:	/* Y ordre inverse */
		j=memicmp(&_Context->libsort_IndexMembers[87*b+85],&_Context->libsort_IndexMembers[87*a+85],2);
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
private int  sort_item_DataMembers(struct old_database_editor_context * _Context,int nelt)	/* returns resolved sort item */
{
	if (!( nelt )) { return(nelt); }
	else {
		return( _Context->tabsort_DataMembers[(nelt-1)] );
	}
}

/* ------------------------------------- */
/* allocate the intermediate sort table  */
/* ------------------------------------- */
private void start_sort_DataMembers(struct old_database_editor_context * _Context,int nelts)
{
if (_Context->nelt_DataMembers<nelts) {
	liberate(_Context->tabsort_DataMembers);
	if ((_Context->tabsort_DataMembers=allocate(nelts*sizeof(int))) == NULL) return;
	for (_Context->nelt_DataMembers=0;_Context->nelt_DataMembers<nelts;_Context->nelt_DataMembers++)
		{ _Context->tabsort_DataMembers[_Context->nelt_DataMembers]=_Context->nelt_DataMembers+1; };	/* initialisation tableau sans tri */
	};
if ((_Context->indsort_DataMembers=allocate(nelts*sizeof(char))) == NULL) return;
if ((_Context->libsort_DataMembers=allocate(nelts*87)) != NULL)
	memset(_Context->libsort_DataMembers,' ',nelts*87);
}

/* -------------------------------------------------------------- */
/* sort the intermediate table into _Context->tabsort_DataMembers */
/* -------------------------------------------------------------- */
private void sort_DataMembers(struct old_database_editor_context * _Context,int nelts)
{
int	i,j,k;
memset(_Context->indsort_DataMembers,0,nelts);

for (i=0;i<nelts;i++) {
	for (k=0;(k<nelts) && (_Context->indsort_DataMembers[k]);k++);
	if (k<nelts-1) {
		for (j=k+1;j<nelts;j++) {
			if ((!_Context->indsort_DataMembers[j]) && (compare_DataMembers(_Context,j,k)<0)) k=j;
			};	/* for j */
		};	/* if k<nbelt-1 */
	_Context->tabsort_DataMembers[i]=k+1;
	_Context->indsort_DataMembers[k]=1;
	};	/* for i */
liberate(_Context->libsort_DataMembers);
liberate(_Context->indsort_DataMembers);
}

/* ------------------------------------------------------------ */
/* compare the elements a et b of _Context->libsort_DataMembers */
/* ------------------------------------------------------------ */
private int compare_DataMembers(struct old_database_editor_context * _Context,int a,int b) {
int i,j;

i=memicmp(&_Context->libsort_DataMembers[87*a],&_Context->libsort_DataMembers[87*b],56);	/* comparaison zone 1 */
switch (_Context->formsort_DataMembers) {
	case 1:	/* Name ordre normal */
		return(i);

	case -1:	/* Name ordre inverse */
		return(-i);

	case 2:	/* Type ordre normal */
		j=memicmp(&_Context->libsort_DataMembers[87*a+56],&_Context->libsort_DataMembers[87*b+56],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -2:	/* Type ordre inverse */
		j=memicmp(&_Context->libsort_DataMembers[87*b+56],&_Context->libsort_DataMembers[87*a+56],9);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 3:	/* Length ordre normal */
		j=memicmp(&_Context->libsort_DataMembers[87*a+65],&_Context->libsort_DataMembers[87*b+65],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -3:	/* Length ordre inverse */
		j=memicmp(&_Context->libsort_DataMembers[87*b+65],&_Context->libsort_DataMembers[87*a+65],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 4:	/* 1st ordre normal */
		j=memicmp(&_Context->libsort_DataMembers[87*a+71],&_Context->libsort_DataMembers[87*b+71],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -4:	/* 1st ordre inverse */
		j=memicmp(&_Context->libsort_DataMembers[87*b+71],&_Context->libsort_DataMembers[87*a+71],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 5:	/* 2nd ordre normal */
		j=memicmp(&_Context->libsort_DataMembers[87*a+77],&_Context->libsort_DataMembers[87*b+77],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -5:	/* 2nd ordre inverse */
		j=memicmp(&_Context->libsort_DataMembers[87*b+77],&_Context->libsort_DataMembers[87*a+77],6);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 6:	/* N ordre normal */
		j=memicmp(&_Context->libsort_DataMembers[87*a+83],&_Context->libsort_DataMembers[87*b+83],2);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -6:	/* N ordre inverse */
		j=memicmp(&_Context->libsort_DataMembers[87*b+83],&_Context->libsort_DataMembers[87*a+83],2);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case 7:	/* Y ordre normal */
		j=memicmp(&_Context->libsort_DataMembers[87*a+85],&_Context->libsort_DataMembers[87*b+85],2);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);

	case -7:	/* Y ordre inverse */
		j=memicmp(&_Context->libsort_DataMembers[87*b+85],&_Context->libsort_DataMembers[87*a+85],2);
		if (!j) return(i);	/* si zones égales, alors comparaison sur colonne 1 */
		return(j);
	default:		/* pas de tri */
		if (a<b) return(-1);
		return(1);
	}; /* fin du switch */
}


public	int	old_database_editor_create(struct old_database_editor_context **cptr)
{

	int i;
	struct old_database_editor_context * _Context=(struct old_database_editor_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct old_database_editor_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=54;
	_Context->page_number=1;
		for (i=0; i < 49; i++)  *(_Context->buffer_BaseName+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_BaseUsers+i)=' ';
	_Context->formsort_FileList=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_FileList=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_FileList=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_FileList=0;_Context->nelt_FileList<512;_Context->nelt_FileList++)
			{ _Context->tabsort_FileList[_Context->nelt_FileList]=_Context->nelt_FileList+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_FileList=0; /* si problème d'allocation */
_Context->indsort_FileList=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_ScrollBar=0;
		_Context->limit_ScrollBar=0;
		_Context->value_ScrollBar=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_ClassName+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_Instance+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_Filename+i)=' ';
		_Context->value_FileType=0;
		_Context->value_IndexType=0;
		for (i=0; i < 8; i++)  *(_Context->buffer_IndexSize+i)=' ';
		for (i=0; i < 5; i++)  *(_Context->buffer_NbIndex+i)=' ';
		_Context->value_RecordType=0;
		_Context->value_MarkerUseage=0;
		_Context->value_Modext=0;
		for (i=0; i < 8; i++)  *(_Context->buffer_RecordSize+i)=' ';
		for (i=0; i < 5; i++)  *(_Context->buffer_NbData+i)=' ';
	_Context->formsort_IndexMembers=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_IndexMembers=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_IndexMembers=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_IndexMembers=0;_Context->nelt_IndexMembers<512;_Context->nelt_IndexMembers++)
			{ _Context->tabsort_IndexMembers[_Context->nelt_IndexMembers]=_Context->nelt_IndexMembers+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_IndexMembers=0; /* si problème d'allocation */
_Context->indsort_IndexMembers=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_IndexBar=0;
		_Context->limit_IndexBar=0;
		_Context->value_IndexBar=0;
	_Context->formsort_DataMembers=0;	/* valeur initiale du tri : aucun */
	_Context->libsort_DataMembers=NULL;	/* pas de table intermédiaire de tri */
	if ((_Context->tabsort_DataMembers=allocate(512*sizeof(int))) != NULL) {	/* taille de la table des elements */
		for (_Context->nelt_DataMembers=0;_Context->nelt_DataMembers<512;_Context->nelt_DataMembers++)
			{ _Context->tabsort_DataMembers[_Context->nelt_DataMembers]=_Context->nelt_DataMembers+1; };	/* initialisation tableau sans tri */
	} else _Context->nelt_DataMembers=0; /* si problème d'allocation */
_Context->indsort_DataMembers=NULL;	/* pas de pointeur de table intermédiaire */		_Context->max_DataBar=0;
		_Context->limit_DataBar=0;
		_Context->value_DataBar=0;
		_Context->value_TypeSelect=0;
		for (i=0; i < 255; i++)  *(_Context->buffer_StubName+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_BaseFile+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_FormName+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_ListName+i)=' ';
		for (i=0; i < 255; i++)  *(_Context->buffer_Title+i)=' ';
		_Context->value_Language=0;
		for (i=0; i < 7; i++)  *(_Context->buffer_PageItems+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_ListLines+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_ListColumns+i)=' ';
		for (i=0; i < 7; i++)  *(_Context->buffer_MaxColumn+i)=' ';
	for (i=0; i < 8; i++)_Context->msg_Auto3333[i]=" ";
	_Context->hint_Auto3333[0]=en__Auto3333;
	_Context->hint_Auto3333[1]=fr__Auto3333;
	_Context->hint_Auto3333[2]=it__Auto3333;
	_Context->hint_Auto3333[3]=es__Auto3333;
	_Context->hint_Auto3333[4]=de__Auto3333;
	_Context->hint_Auto3333[5]=nl__Auto3333;
	_Context->hint_Auto3333[6]=pt__Auto3333;
	_Context->hint_Auto3333[7]=xx__Auto3333;
	_Context->x_Auto3333=0;
	_Context->y_Auto3333=0;
	_Context->w_Auto3333=790;
	_Context->h_Auto3333=590;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3334[i]=" ";
	_Context->msg_Auto3334[0]=en_Auto3334;
	_Context->msg_Auto3334[1]=fr_Auto3334;
	_Context->msg_Auto3334[2]=it_Auto3334;
	_Context->msg_Auto3334[3]=es_Auto3334;
	_Context->msg_Auto3334[4]=de_Auto3334;
	_Context->msg_Auto3334[5]=nl_Auto3334;
	_Context->msg_Auto3334[6]=pt_Auto3334;
	_Context->msg_Auto3334[7]=xx_Auto3334;
	_Context->hint_Auto3334[0]=en__Auto3334;
	_Context->hint_Auto3334[1]=fr__Auto3334;
	_Context->hint_Auto3334[2]=it__Auto3334;
	_Context->hint_Auto3334[3]=es__Auto3334;
	_Context->hint_Auto3334[4]=de__Auto3334;
	_Context->hint_Auto3334[5]=nl__Auto3334;
	_Context->hint_Auto3334[6]=pt__Auto3334;
	_Context->hint_Auto3334[7]=xx__Auto3334;
	for (i=0; i < 8; i++)_Context->msg_Auto3335[i]=" ";
	_Context->msg_Auto3335[0]=en_Auto3335;
	_Context->msg_Auto3335[1]=fr_Auto3335;
	_Context->msg_Auto3335[2]=it_Auto3335;
	_Context->msg_Auto3335[3]=es_Auto3335;
	_Context->msg_Auto3335[4]=de_Auto3335;
	_Context->msg_Auto3335[5]=nl_Auto3335;
	_Context->msg_Auto3335[6]=pt_Auto3335;
	_Context->msg_Auto3335[7]=xx_Auto3335;
	_Context->hint_Auto3335[0]=en__Auto3335;
	_Context->hint_Auto3335[1]=fr__Auto3335;
	_Context->hint_Auto3335[2]=it__Auto3335;
	_Context->hint_Auto3335[3]=es__Auto3335;
	_Context->hint_Auto3335[4]=de__Auto3335;
	_Context->hint_Auto3335[5]=nl__Auto3335;
	_Context->hint_Auto3335[6]=pt__Auto3335;
	_Context->hint_Auto3335[7]=xx__Auto3335;
	_Context->hint_BaseName[0]=en__BaseName;
	_Context->hint_BaseUsers[0]=en__BaseUsers;
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
	if ( 0 > 0 ) { _Context->row_FileList=&_Context->buffer_FileList[0-1][0]; } ;
	_Context->hint_Mursor[0]=en__Mursor;
	_Context->x_Mursor=_Context->x_Auto3333+30;
	_Context->y_Mursor=_Context->y_Auto3333+90;
	_Context->w_Mursor=710;
	_Context->h_Mursor=20;
	_Context->fg_Mursor=20;
	_Context->bg_Mursor=20;
	_Context->fid_Mursor=1;
	for (i=0; i < 8; i++)_Context->msg_Auto3336[i]=" ";
	_Context->msg_Auto3336[0]=en_Auto3336;
	_Context->msg_Auto3336[1]=fr_Auto3336;
	_Context->msg_Auto3336[2]=it_Auto3336;
	_Context->msg_Auto3336[3]=es_Auto3336;
	_Context->msg_Auto3336[4]=de_Auto3336;
	_Context->msg_Auto3336[5]=nl_Auto3336;
	_Context->msg_Auto3336[6]=pt_Auto3336;
	_Context->msg_Auto3336[7]=xx_Auto3336;
	_Context->hint_ScrollBar[0]=en__ScrollBar;
	_Context->max_ScrollBar=1;
	_Context->value_ScrollBar=1;
	_Context->limit_ScrollBar=1;
	_Context->limit_ScrollBar=26;
	_Context->value_ScrollBar=0;
	_Context->max_ScrollBar=100;
	if((FileManager)&&(FileManager->current)){
	if(FileManager->current->number<26){
	_Context->value_ScrollBar=0;
	_Context->value_FileList=FileManager->current->number;
	}
	else{
	_Context->value_ScrollBar=(FileManager->current->number-1);
	_Context->value_FileList=1;
	}
	}
	for (i=0; i < 8; i++)_Context->msg_CopyFile[i]=" ";
	_Context->msg_CopyFile[0]=en_CopyFile;
	_Context->msg_CopyFile[1]=fr_CopyFile;
	_Context->msg_CopyFile[2]=it_CopyFile;
	_Context->msg_CopyFile[3]=es_CopyFile;
	_Context->msg_CopyFile[4]=de_CopyFile;
	_Context->msg_CopyFile[5]=nl_CopyFile;
	_Context->msg_CopyFile[6]=pt_CopyFile;
	_Context->msg_CopyFile[7]=xx_CopyFile;
	_Context->hint_CopyFile[0]=en__CopyFile;
	_Context->hint_CopyFile[1]=fr__CopyFile;
	_Context->hint_CopyFile[2]=it__CopyFile;
	_Context->hint_CopyFile[3]=es__CopyFile;
	_Context->hint_CopyFile[4]=de__CopyFile;
	_Context->hint_CopyFile[5]=nl__CopyFile;
	_Context->hint_CopyFile[6]=pt__CopyFile;
	_Context->hint_CopyFile[7]=xx__CopyFile;
	for (i=0; i < 8; i++)_Context->msg_DeleteFile[i]=" ";
	_Context->msg_DeleteFile[0]=en_DeleteFile;
	_Context->msg_DeleteFile[1]=fr_DeleteFile;
	_Context->msg_DeleteFile[2]=it_DeleteFile;
	_Context->msg_DeleteFile[3]=es_DeleteFile;
	_Context->msg_DeleteFile[4]=de_DeleteFile;
	_Context->msg_DeleteFile[5]=nl_DeleteFile;
	_Context->msg_DeleteFile[6]=pt_DeleteFile;
	_Context->msg_DeleteFile[7]=xx_DeleteFile;
	_Context->hint_DeleteFile[0]=en__DeleteFile;
	_Context->hint_DeleteFile[1]=fr__DeleteFile;
	_Context->hint_DeleteFile[2]=it__DeleteFile;
	_Context->hint_DeleteFile[3]=es__DeleteFile;
	_Context->hint_DeleteFile[4]=de__DeleteFile;
	_Context->hint_DeleteFile[5]=nl__DeleteFile;
	_Context->hint_DeleteFile[6]=pt__DeleteFile;
	_Context->hint_DeleteFile[7]=xx__DeleteFile;
	for (i=0; i < 8; i++)_Context->msg_PasteFile[i]=" ";
	_Context->msg_PasteFile[0]=en_PasteFile;
	_Context->msg_PasteFile[1]=fr_PasteFile;
	_Context->msg_PasteFile[2]=it_PasteFile;
	_Context->msg_PasteFile[3]=es_PasteFile;
	_Context->msg_PasteFile[4]=de_PasteFile;
	_Context->msg_PasteFile[5]=nl_PasteFile;
	_Context->msg_PasteFile[6]=pt_PasteFile;
	_Context->msg_PasteFile[7]=xx_PasteFile;
	_Context->hint_PasteFile[0]=en__PasteFile;
	_Context->hint_PasteFile[1]=fr__PasteFile;
	_Context->hint_PasteFile[2]=it__PasteFile;
	_Context->hint_PasteFile[3]=es__PasteFile;
	_Context->hint_PasteFile[4]=de__PasteFile;
	_Context->hint_PasteFile[5]=nl__PasteFile;
	_Context->hint_PasteFile[6]=pt__PasteFile;
	_Context->hint_PasteFile[7]=xx__PasteFile;
	_Context->s_PasteFile=0;
	_Context->p_PasteFile=visual_buffer(_Context->x_Auto3333+280,_Context->y_Auto3333+540,208+2,30+2);
	for (i=0; i < 8; i++)_Context->msg_FilePage[i]=" ";
	_Context->msg_FilePage[0]=en_FilePage;
	_Context->msg_FilePage[1]=fr_FilePage;
	_Context->msg_FilePage[2]=it_FilePage;
	_Context->msg_FilePage[3]=es_FilePage;
	_Context->msg_FilePage[4]=de_FilePage;
	_Context->msg_FilePage[5]=nl_FilePage;
	_Context->msg_FilePage[6]=pt_FilePage;
	_Context->msg_FilePage[7]=xx_FilePage;
	_Context->hint_FilePage[0]=en__FilePage;
	_Context->focus_pages[2]=8;
	for (i=0; i < 8; i++)_Context->msg_Auto3339[i]=" ";
	_Context->msg_Auto3339[0]=en_Auto3339;
	_Context->msg_Auto3339[1]=fr_Auto3339;
	_Context->msg_Auto3339[2]=it_Auto3339;
	_Context->msg_Auto3339[3]=es_Auto3339;
	_Context->msg_Auto3339[4]=de_Auto3339;
	_Context->msg_Auto3339[5]=nl_Auto3339;
	_Context->msg_Auto3339[6]=pt_Auto3339;
	_Context->msg_Auto3339[7]=xx_Auto3339;
	for (i=0; i < 8; i++)_Context->msg_Auto3340[i]=" ";
	_Context->msg_Auto3340[0]=en_Auto3340;
	_Context->msg_Auto3340[1]=fr_Auto3340;
	_Context->msg_Auto3340[2]=it_Auto3340;
	_Context->msg_Auto3340[3]=es_Auto3340;
	_Context->msg_Auto3340[4]=de_Auto3340;
	_Context->msg_Auto3340[5]=nl_Auto3340;
	_Context->msg_Auto3340[6]=pt_Auto3340;
	_Context->msg_Auto3340[7]=xx_Auto3340;
	for (i=0; i < 8; i++)_Context->msg_Auto3341[i]=" ";
	_Context->msg_Auto3341[0]=en_Auto3341;
	_Context->msg_Auto3341[1]=fr_Auto3341;
	_Context->msg_Auto3341[2]=it_Auto3341;
	_Context->msg_Auto3341[3]=es_Auto3341;
	_Context->msg_Auto3341[4]=de_Auto3341;
	_Context->msg_Auto3341[5]=nl_Auto3341;
	_Context->msg_Auto3341[6]=pt_Auto3341;
	_Context->msg_Auto3341[7]=xx_Auto3341;
	_Context->hint_ClassName[0]=en__ClassName;
	_Context->hint_Instance[0]=en__Instance;
	_Context->hint_Filename[0]=en__Filename;
	for (i=0; i < 8; i++)_Context->msg_FileType[i]=" ";
	_Context->hint_FileType[0]=en__FileType;
	for (i=0; i < 8; i++)_Context->msg_IndexType[i]=" ";
	_Context->msg_IndexType[0]=en_IndexType;
	_Context->msg_IndexType[1]=fr_IndexType;
	_Context->msg_IndexType[2]=it_IndexType;
	_Context->msg_IndexType[3]=es_IndexType;
	_Context->msg_IndexType[4]=de_IndexType;
	_Context->msg_IndexType[5]=nl_IndexType;
	_Context->msg_IndexType[6]=pt_IndexType;
	_Context->msg_IndexType[7]=xx_IndexType;
	_Context->hint_IndexSize[0]=en__IndexSize;
	for (i=0; i < 8; i++)_Context->msg_Auto3342[i]=" ";
	_Context->msg_Auto3342[0]=en_Auto3342;
	_Context->msg_Auto3342[1]=fr_Auto3342;
	_Context->msg_Auto3342[2]=it_Auto3342;
	_Context->msg_Auto3342[3]=es_Auto3342;
	_Context->msg_Auto3342[4]=de_Auto3342;
	_Context->msg_Auto3342[5]=nl_Auto3342;
	_Context->msg_Auto3342[6]=pt_Auto3342;
	_Context->msg_Auto3342[7]=xx_Auto3342;
	_Context->hint_NbIndex[0]=en__NbIndex;
	for (i=0; i < 8; i++)_Context->msg_Auto3343[i]=" ";
	_Context->msg_Auto3343[0]=en_Auto3343;
	_Context->msg_Auto3343[1]=fr_Auto3343;
	_Context->msg_Auto3343[2]=it_Auto3343;
	_Context->msg_Auto3343[3]=es_Auto3343;
	_Context->msg_Auto3343[4]=de_Auto3343;
	_Context->msg_Auto3343[5]=nl_Auto3343;
	_Context->msg_Auto3343[6]=pt_Auto3343;
	_Context->msg_Auto3343[7]=xx_Auto3343;
	for (i=0; i < 8; i++)_Context->msg_RecordType[i]=" ";
	_Context->msg_RecordType[0]=en_RecordType;
	_Context->msg_RecordType[1]=fr_RecordType;
	_Context->msg_RecordType[2]=it_RecordType;
	_Context->msg_RecordType[3]=es_RecordType;
	_Context->msg_RecordType[4]=de_RecordType;
	_Context->msg_RecordType[5]=nl_RecordType;
	_Context->msg_RecordType[6]=pt_RecordType;
	_Context->msg_RecordType[7]=xx_RecordType;
	for (i=0; i < 8; i++)_Context->msg_MarkerUseage[i]=" ";
	_Context->msg_MarkerUseage[0]=en_MarkerUseage;
	_Context->msg_MarkerUseage[1]=fr_MarkerUseage;
	_Context->msg_MarkerUseage[2]=it_MarkerUseage;
	_Context->msg_MarkerUseage[3]=es_MarkerUseage;
	_Context->msg_MarkerUseage[4]=de_MarkerUseage;
	_Context->msg_MarkerUseage[5]=nl_MarkerUseage;
	_Context->msg_MarkerUseage[6]=pt_MarkerUseage;
	_Context->msg_MarkerUseage[7]=xx_MarkerUseage;
	for (i=0; i < 8; i++)_Context->msg_Modext[i]=" ";
	_Context->msg_Modext[0]=en_Modext;
	_Context->msg_Modext[1]=fr_Modext;
	_Context->msg_Modext[2]=it_Modext;
	_Context->msg_Modext[3]=es_Modext;
	_Context->msg_Modext[4]=de_Modext;
	_Context->msg_Modext[5]=nl_Modext;
	_Context->msg_Modext[6]=pt_Modext;
	_Context->msg_Modext[7]=xx_Modext;
	_Context->hint_RecordSize[0]=en__RecordSize;
	for (i=0; i < 8; i++)_Context->msg_Auto3344[i]=" ";
	_Context->msg_Auto3344[0]=en_Auto3344;
	_Context->msg_Auto3344[1]=fr_Auto3344;
	_Context->msg_Auto3344[2]=it_Auto3344;
	_Context->msg_Auto3344[3]=es_Auto3344;
	_Context->msg_Auto3344[4]=de_Auto3344;
	_Context->msg_Auto3344[5]=nl_Auto3344;
	_Context->msg_Auto3344[6]=pt_Auto3344;
	_Context->msg_Auto3344[7]=xx_Auto3344;
	_Context->hint_NbData[0]=en__NbData;
	for (i=0; i < 8; i++)_Context->msg_Auto3345[i]=" ";
	_Context->msg_Auto3345[0]=en_Auto3345;
	_Context->msg_Auto3345[1]=fr_Auto3345;
	_Context->msg_Auto3345[2]=it_Auto3345;
	_Context->msg_Auto3345[3]=es_Auto3345;
	_Context->msg_Auto3345[4]=de_Auto3345;
	_Context->msg_Auto3345[5]=nl_Auto3345;
	_Context->msg_Auto3345[6]=pt_Auto3345;
	_Context->msg_Auto3345[7]=xx_Auto3345;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	for (i=0; i < 8; i++)_Context->msg_FileUsers[i]=" ";
	_Context->msg_FileUsers[0]=en_FileUsers;
	_Context->msg_FileUsers[1]=fr_FileUsers;
	_Context->msg_FileUsers[2]=it_FileUsers;
	_Context->msg_FileUsers[3]=es_FileUsers;
	_Context->msg_FileUsers[4]=de_FileUsers;
	_Context->msg_FileUsers[5]=nl_FileUsers;
	_Context->msg_FileUsers[6]=pt_FileUsers;
	_Context->msg_FileUsers[7]=xx_FileUsers;
	for (i=0; i < 8; i++)_Context->msg_Auto3346[i]=" ";
	_Context->msg_Auto3346[0]=en_Auto3346;
	_Context->msg_Auto3346[1]=fr_Auto3346;
	_Context->msg_Auto3346[2]=it_Auto3346;
	_Context->msg_Auto3346[3]=es_Auto3346;
	_Context->msg_Auto3346[4]=de_Auto3346;
	_Context->msg_Auto3346[5]=nl_Auto3346;
	_Context->msg_Auto3346[6]=pt_Auto3346;
	_Context->msg_Auto3346[7]=xx_Auto3346;
	for (i=0; i < 8; i++)_Context->msg_Auto3347[i]=" ";
	_Context->msg_Auto3347[0]=en_Auto3347;
	_Context->msg_Auto3347[1]=fr_Auto3347;
	_Context->msg_Auto3347[2]=it_Auto3347;
	_Context->msg_Auto3347[3]=es_Auto3347;
	_Context->msg_Auto3347[4]=de_Auto3347;
	_Context->msg_Auto3347[5]=nl_Auto3347;
	_Context->msg_Auto3347[6]=pt_Auto3347;
	_Context->msg_Auto3347[7]=xx_Auto3347;
	for (i=0; i < 8; i++)_Context->msg_Auto3348[i]=" ";
	_Context->msg_Auto3348[1]=fr_Auto3348;
	_Context->msg_Auto3348[2]=it_Auto3348;
	_Context->msg_Auto3348[3]=es_Auto3348;
	_Context->msg_Auto3348[4]=de_Auto3348;
	_Context->msg_Auto3348[5]=nl_Auto3348;
	_Context->msg_Auto3348[6]=pt_Auto3348;
	_Context->msg_Auto3348[7]=xx_Auto3348;
	for (i=0; i < 8; i++)_Context->msg_Auto3349[i]=" ";
	_Context->msg_Auto3349[1]=fr_Auto3349;
	_Context->msg_Auto3349[2]=it_Auto3349;
	_Context->msg_Auto3349[3]=es_Auto3349;
	_Context->msg_Auto3349[4]=de_Auto3349;
	_Context->msg_Auto3349[5]=nl_Auto3349;
	_Context->msg_Auto3349[6]=pt_Auto3349;
	_Context->msg_Auto3349[7]=xx_Auto3349;
	for (i=0; i < 8; i++)_Context->msg_Auto3350[i]=" ";
	_Context->msg_Auto3350[0]=en_Auto3350;
	_Context->msg_Auto3350[1]=fr_Auto3350;
	_Context->msg_Auto3350[2]=it_Auto3350;
	_Context->msg_Auto3350[3]=es_Auto3350;
	_Context->msg_Auto3350[4]=de_Auto3350;
	_Context->msg_Auto3350[5]=nl_Auto3350;
	_Context->msg_Auto3350[6]=pt_Auto3350;
	_Context->msg_Auto3350[7]=xx_Auto3350;
	for (i=0; i < 8; i++)_Context->msg_Auto3351[i]=" ";
	_Context->msg_Auto3351[0]=en_Auto3351;
	_Context->msg_Auto3351[1]=fr_Auto3351;
	_Context->msg_Auto3351[2]=it_Auto3351;
	_Context->msg_Auto3351[3]=es_Auto3351;
	_Context->msg_Auto3351[4]=de_Auto3351;
	_Context->msg_Auto3351[5]=nl_Auto3351;
	_Context->msg_Auto3351[6]=pt_Auto3351;
	_Context->msg_Auto3351[7]=xx_Auto3351;
	for (i=0; i < 8; i++)_Context->msg_IndexMembers[i]=" ";
	_Context->msg_IndexMembers[0]=en_IndexMembers;
	_Context->msg_IndexMembers[1]=fr_IndexMembers;
	_Context->msg_IndexMembers[2]=it_IndexMembers;
	_Context->msg_IndexMembers[3]=es_IndexMembers;
	_Context->msg_IndexMembers[4]=de_IndexMembers;
	_Context->msg_IndexMembers[5]=nl_IndexMembers;
	_Context->msg_IndexMembers[6]=pt_IndexMembers;
	_Context->msg_IndexMembers[7]=xx_IndexMembers;
	_Context->hint_IndexMembers[0]=en__IndexMembers;
	_Context->hint_IndexMembers[1]=fr__IndexMembers;
	_Context->hint_IndexMembers[2]=it__IndexMembers;
	_Context->hint_IndexMembers[3]=es__IndexMembers;
	_Context->hint_IndexMembers[4]=de__IndexMembers;
	_Context->hint_IndexMembers[5]=nl__IndexMembers;
	_Context->hint_IndexMembers[6]=pt__IndexMembers;
	_Context->hint_IndexMembers[7]=xx__IndexMembers;
	if ( 0 > 0 ) { _Context->row_IndexMembers=&_Context->buffer_IndexMembers[0-1][0]; } ;
	_Context->hint_Cursor[0]=en__Cursor;
	_Context->x_Cursor=_Context->x_Auto3333+40;
	_Context->y_Cursor=_Context->y_Auto3333+180;
	_Context->w_Cursor=700;
	_Context->h_Cursor=20;
	_Context->fg_Cursor=20;
	_Context->bg_Cursor=20;
	_Context->fid_Cursor=1;
	for (i=0; i < 8; i++)_Context->msg_IsLink[i]=" ";
	_Context->msg_IsLink[0]=en_IsLink;
	_Context->hint_IsLink[0]=en__IsLink;
	_Context->x_IsLink=_Context->x_Auto3333+706;
	_Context->y_IsLink=_Context->y_Auto3333+181;
	_Context->w_IsLink=16;
	_Context->h_IsLink=16;
	_Context->fg_IsLink=16;
	_Context->bg_IsLink=16;
	_Context->fid_IsLink=1;
	for (i=0; i < 8; i++)_Context->msg_IsList[i]=" ";
	_Context->msg_IsList[0]=en_IsList;
	_Context->hint_IsList[0]=en__IsList;
	_Context->x_IsList=_Context->x_Auto3333+722;
	_Context->y_IsList=_Context->y_Auto3333+181;
	_Context->w_IsList=16;
	_Context->h_IsList=16;
	_Context->fg_IsList=16;
	_Context->bg_IsList=16;
	_Context->fid_IsList=1;
	_Context->max_IndexBar=1;
	_Context->value_IndexBar=1;
	_Context->limit_IndexBar=1;
	_Context->value_IndexBar=0;
	_Context->limit_IndexBar=4;
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
	_Context->hint_DataMembers[0]=en__DataMembers;
	_Context->hint_DataMembers[1]=fr__DataMembers;
	_Context->hint_DataMembers[2]=it__DataMembers;
	_Context->hint_DataMembers[3]=es__DataMembers;
	_Context->hint_DataMembers[4]=de__DataMembers;
	_Context->hint_DataMembers[5]=nl__DataMembers;
	_Context->hint_DataMembers[6]=pt__DataMembers;
	_Context->hint_DataMembers[7]=xx__DataMembers;
	if ( 0 > 0 ) { _Context->row_DataMembers=&_Context->buffer_DataMembers[0-1][0]; } ;
	_Context->hint_Kursor[0]=en__Kursor;
	_Context->x_Kursor=_Context->x_Auto3333+40;
	_Context->y_Kursor=_Context->y_Auto3333+280;
	_Context->w_Kursor=700;
	_Context->h_Kursor=20;
	_Context->fg_Kursor=20;
	_Context->bg_Kursor=20;
	_Context->fid_Kursor=1;
	_Context->max_DataBar=1;
	_Context->value_DataBar=1;
	_Context->limit_DataBar=1;
	_Context->value_DataBar=0;
	_Context->limit_DataBar=16;
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
	_Context->hint_TypeSelect[0]=en__TypeSelect;
	_Context->hint_TypeSelect[1]=fr__TypeSelect;
	_Context->hint_TypeSelect[2]=it__TypeSelect;
	_Context->hint_TypeSelect[3]=es__TypeSelect;
	_Context->hint_TypeSelect[4]=de__TypeSelect;
	_Context->hint_TypeSelect[5]=nl__TypeSelect;
	_Context->hint_TypeSelect[6]=pt__TypeSelect;
	_Context->hint_TypeSelect[7]=xx__TypeSelect;
	_Context->x_TypeSelect=_Context->x_Auto3333+506;
	_Context->y_TypeSelect=_Context->y_Auto3333+150;
	_Context->w_TypeSelect=72;
	_Context->h_TypeSelect=100;
	_Context->fg_TypeSelect=100;
	_Context->bg_TypeSelect=100;
	_Context->fid_TypeSelect=2;
	_Context->s_TypeSelect=0;
	_Context->p_TypeSelect=visual_buffer(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect+2,_Context->h_TypeSelect+2);
	for (i=0; i < 8; i++)_Context->msg_MaskPage[i]=" ";
	_Context->msg_MaskPage[0]=en_MaskPage;
	_Context->msg_MaskPage[1]=fr_MaskPage;
	_Context->msg_MaskPage[2]=it_MaskPage;
	_Context->msg_MaskPage[3]=es_MaskPage;
	_Context->msg_MaskPage[4]=de_MaskPage;
	_Context->msg_MaskPage[5]=nl_MaskPage;
	_Context->msg_MaskPage[6]=pt_MaskPage;
	_Context->msg_MaskPage[7]=xx_MaskPage;
	_Context->hint_MaskPage[0]=en__MaskPage;
	_Context->focus_pages[3]=32;
	for (i=0; i < 8; i++)_Context->msg_Auto3353[i]=" ";
	_Context->msg_Auto3353[0]=en_Auto3353;
	_Context->msg_Auto3353[1]=fr_Auto3353;
	_Context->msg_Auto3353[2]=it_Auto3353;
	_Context->msg_Auto3353[3]=es_Auto3353;
	_Context->msg_Auto3353[4]=de_Auto3353;
	_Context->msg_Auto3353[5]=nl_Auto3353;
	_Context->msg_Auto3353[6]=pt_Auto3353;
	_Context->msg_Auto3353[7]=xx_Auto3353;
	_Context->hint_Auto3353[0]=en__Auto3353;
	_Context->hint_Auto3353[1]=fr__Auto3353;
	_Context->hint_Auto3353[2]=it__Auto3353;
	_Context->hint_Auto3353[3]=es__Auto3353;
	_Context->hint_Auto3353[4]=de__Auto3353;
	_Context->hint_Auto3353[5]=nl__Auto3353;
	_Context->hint_Auto3353[6]=pt__Auto3353;
	_Context->hint_Auto3353[7]=xx__Auto3353;
	for (i=0; i < 8; i++)_Context->msg_Auto3354[i]=" ";
	_Context->msg_Auto3354[0]=en_Auto3354;
	_Context->msg_Auto3354[1]=fr_Auto3354;
	_Context->msg_Auto3354[2]=it_Auto3354;
	_Context->msg_Auto3354[3]=es_Auto3354;
	_Context->msg_Auto3354[4]=de_Auto3354;
	_Context->msg_Auto3354[5]=nl_Auto3354;
	_Context->msg_Auto3354[6]=pt_Auto3354;
	_Context->msg_Auto3354[7]=xx_Auto3354;
	_Context->hint_Auto3354[0]=en__Auto3354;
	_Context->hint_Auto3354[1]=fr__Auto3354;
	_Context->hint_Auto3354[2]=it__Auto3354;
	_Context->hint_Auto3354[3]=es__Auto3354;
	_Context->hint_Auto3354[4]=de__Auto3354;
	_Context->hint_Auto3354[5]=nl__Auto3354;
	_Context->hint_Auto3354[6]=pt__Auto3354;
	_Context->hint_Auto3354[7]=xx__Auto3354;
	for (i=0; i < 8; i++)_Context->msg_Auto3355[i]=" ";
	_Context->msg_Auto3355[0]=en_Auto3355;
	_Context->msg_Auto3355[1]=fr_Auto3355;
	_Context->msg_Auto3355[2]=it_Auto3355;
	_Context->msg_Auto3355[3]=es_Auto3355;
	_Context->msg_Auto3355[4]=de_Auto3355;
	_Context->msg_Auto3355[5]=nl_Auto3355;
	_Context->msg_Auto3355[6]=pt_Auto3355;
	_Context->msg_Auto3355[7]=xx_Auto3355;
	_Context->hint_Auto3355[0]=en__Auto3355;
	_Context->hint_Auto3355[1]=fr__Auto3355;
	_Context->hint_Auto3355[2]=it__Auto3355;
	_Context->hint_Auto3355[3]=es__Auto3355;
	_Context->hint_Auto3355[4]=de__Auto3355;
	_Context->hint_Auto3355[5]=nl__Auto3355;
	_Context->hint_Auto3355[6]=pt__Auto3355;
	_Context->hint_Auto3355[7]=xx__Auto3355;
	for (i=0; i < 8; i++)_Context->msg_Auto3358[i]=" ";
	_Context->msg_Auto3358[0]=en_Auto3358;
	_Context->msg_Auto3358[1]=fr_Auto3358;
	_Context->msg_Auto3358[2]=it_Auto3358;
	_Context->msg_Auto3358[3]=es_Auto3358;
	_Context->msg_Auto3358[4]=de_Auto3358;
	_Context->msg_Auto3358[5]=nl_Auto3358;
	_Context->msg_Auto3358[6]=pt_Auto3358;
	_Context->msg_Auto3358[7]=xx_Auto3358;
	_Context->hint_Auto3358[0]=en__Auto3358;
	for (i=0; i < 8; i++)_Context->msg_Auto3359[i]=" ";
	_Context->msg_Auto3359[0]=en_Auto3359;
	_Context->msg_Auto3359[1]=fr_Auto3359;
	_Context->msg_Auto3359[2]=it_Auto3359;
	_Context->msg_Auto3359[3]=es_Auto3359;
	_Context->msg_Auto3359[4]=de_Auto3359;
	_Context->msg_Auto3359[5]=nl_Auto3359;
	_Context->msg_Auto3359[6]=pt_Auto3359;
	_Context->msg_Auto3359[7]=xx_Auto3359;
	_Context->hint_Auto3359[0]=en__Auto3359;
	_Context->hint_Auto3359[1]=fr__Auto3359;
	_Context->hint_Auto3359[2]=it__Auto3359;
	_Context->hint_Auto3359[3]=es__Auto3359;
	_Context->hint_Auto3359[4]=de__Auto3359;
	_Context->hint_Auto3359[5]=nl__Auto3359;
	_Context->hint_Auto3359[6]=pt__Auto3359;
	_Context->hint_Auto3359[7]=xx__Auto3359;
	for (i=0; i < 8; i++)_Context->msg_Auto3360[i]=" ";
	_Context->msg_Auto3360[0]=en_Auto3360;
	_Context->msg_Auto3360[1]=fr_Auto3360;
	_Context->msg_Auto3360[2]=it_Auto3360;
	_Context->msg_Auto3360[3]=es_Auto3360;
	_Context->msg_Auto3360[4]=de_Auto3360;
	_Context->msg_Auto3360[5]=nl_Auto3360;
	_Context->msg_Auto3360[6]=pt_Auto3360;
	_Context->msg_Auto3360[7]=xx_Auto3360;
	_Context->hint_Auto3360[0]=en__Auto3360;
	_Context->hint_Auto3360[1]=fr__Auto3360;
	_Context->hint_Auto3360[2]=it__Auto3360;
	_Context->hint_Auto3360[3]=es__Auto3360;
	_Context->hint_Auto3360[4]=de__Auto3360;
	_Context->hint_Auto3360[5]=nl__Auto3360;
	_Context->hint_Auto3360[6]=pt__Auto3360;
	_Context->hint_Auto3360[7]=xx__Auto3360;
	for (i=0; i < 8; i++)_Context->msg_Auto3361[i]=" ";
	_Context->msg_Auto3361[0]=en_Auto3361;
	_Context->msg_Auto3361[1]=fr_Auto3361;
	_Context->msg_Auto3361[2]=it_Auto3361;
	_Context->msg_Auto3361[3]=es_Auto3361;
	_Context->msg_Auto3361[4]=de_Auto3361;
	_Context->msg_Auto3361[5]=nl_Auto3361;
	_Context->msg_Auto3361[6]=pt_Auto3361;
	_Context->msg_Auto3361[7]=xx_Auto3361;
	for (i=0; i < 8; i++)_Context->msg_Auto3362[i]=" ";
	_Context->msg_Auto3362[0]=en_Auto3362;
	_Context->msg_Auto3362[1]=fr_Auto3362;
	_Context->msg_Auto3362[2]=it_Auto3362;
	_Context->msg_Auto3362[3]=es_Auto3362;
	_Context->msg_Auto3362[4]=de_Auto3362;
	_Context->msg_Auto3362[5]=nl_Auto3362;
	_Context->msg_Auto3362[6]=pt_Auto3362;
	_Context->msg_Auto3362[7]=xx_Auto3362;
	for (i=0; i < 8; i++)_Context->msg_Auto3363[i]=" ";
	_Context->msg_Auto3363[0]=en_Auto3363;
	_Context->msg_Auto3363[1]=fr_Auto3363;
	_Context->msg_Auto3363[2]=it_Auto3363;
	_Context->msg_Auto3363[3]=es_Auto3363;
	_Context->msg_Auto3363[4]=de_Auto3363;
	_Context->msg_Auto3363[5]=nl_Auto3363;
	_Context->msg_Auto3363[6]=pt_Auto3363;
	_Context->msg_Auto3363[7]=xx_Auto3363;
	_Context->hint_Auto3363[0]=en__Auto3363;
	_Context->hint_Auto3363[1]=fr__Auto3363;
	_Context->hint_Auto3363[2]=it__Auto3363;
	_Context->hint_Auto3363[3]=es__Auto3363;
	_Context->hint_Auto3363[4]=de__Auto3363;
	_Context->hint_Auto3363[5]=nl__Auto3363;
	_Context->hint_Auto3363[6]=pt__Auto3363;
	_Context->hint_Auto3363[7]=xx__Auto3363;
	for (i=0; i < 8; i++)_Context->msg_Auto3364[i]=" ";
	_Context->msg_Auto3364[0]=en_Auto3364;
	_Context->msg_Auto3364[1]=fr_Auto3364;
	_Context->msg_Auto3364[2]=it_Auto3364;
	_Context->msg_Auto3364[3]=es_Auto3364;
	_Context->msg_Auto3364[4]=de_Auto3364;
	_Context->msg_Auto3364[5]=nl_Auto3364;
	_Context->msg_Auto3364[6]=pt_Auto3364;
	_Context->msg_Auto3364[7]=xx_Auto3364;
	for (i=0; i < 8; i++)_Context->msg_Auto3365[i]=" ";
	_Context->msg_Auto3365[0]=en_Auto3365;
	_Context->msg_Auto3365[1]=fr_Auto3365;
	_Context->msg_Auto3365[2]=it_Auto3365;
	_Context->msg_Auto3365[3]=es_Auto3365;
	_Context->msg_Auto3365[4]=de_Auto3365;
	_Context->msg_Auto3365[5]=nl_Auto3365;
	_Context->msg_Auto3365[6]=pt_Auto3365;
	_Context->msg_Auto3365[7]=xx_Auto3365;
	_Context->hint_Auto3365[0]=en__Auto3365;
	for (i=0; i < 8; i++)_Context->msg_Auto3366[i]=" ";
	_Context->msg_Auto3366[0]=en_Auto3366;
	_Context->msg_Auto3366[1]=fr_Auto3366;
	_Context->msg_Auto3366[2]=it_Auto3366;
	_Context->msg_Auto3366[3]=es_Auto3366;
	_Context->msg_Auto3366[4]=de_Auto3366;
	_Context->msg_Auto3366[5]=nl_Auto3366;
	_Context->msg_Auto3366[6]=pt_Auto3366;
	_Context->msg_Auto3366[7]=xx_Auto3366;
	_Context->hint_Auto3366[0]=en__Auto3366;
	_Context->hint_Auto3366[1]=fr__Auto3366;
	_Context->hint_Auto3366[2]=it__Auto3366;
	_Context->hint_Auto3366[3]=es__Auto3366;
	_Context->hint_Auto3366[4]=de__Auto3366;
	_Context->hint_Auto3366[5]=nl__Auto3366;
	_Context->hint_Auto3366[6]=pt__Auto3366;
	_Context->hint_Auto3366[7]=xx__Auto3366;
	for (i=0; i < 8; i++)_Context->msg_Auto3367[i]=" ";
	_Context->msg_Auto3367[0]=en_Auto3367;
	_Context->msg_Auto3367[1]=fr_Auto3367;
	_Context->msg_Auto3367[2]=it_Auto3367;
	_Context->msg_Auto3367[3]=es_Auto3367;
	_Context->msg_Auto3367[4]=de_Auto3367;
	_Context->msg_Auto3367[5]=nl_Auto3367;
	_Context->msg_Auto3367[6]=pt_Auto3367;
	_Context->msg_Auto3367[7]=xx_Auto3367;
	_Context->hint_Auto3367[0]=en__Auto3367;
	_Context->hint_Auto3367[1]=fr__Auto3367;
	for (i=0; i < 8; i++)_Context->msg_Auto3368[i]=" ";
	_Context->msg_Auto3368[0]=en_Auto3368;
	_Context->msg_Auto3368[1]=fr_Auto3368;
	_Context->msg_Auto3368[2]=it_Auto3368;
	_Context->msg_Auto3368[3]=es_Auto3368;
	_Context->msg_Auto3368[4]=de_Auto3368;
	_Context->msg_Auto3368[5]=nl_Auto3368;
	_Context->msg_Auto3368[6]=pt_Auto3368;
	_Context->msg_Auto3368[7]=xx_Auto3368;
	_Context->hint_Auto3368[0]=en__Auto3368;
	_Context->hint_Auto3368[1]=fr__Auto3368;
	for (i=0; i < 8; i++)_Context->msg_Auto3369[i]=" ";
	_Context->msg_Auto3369[0]=en_Auto3369;
	_Context->msg_Auto3369[1]=fr_Auto3369;
	_Context->msg_Auto3369[2]=it_Auto3369;
	_Context->msg_Auto3369[3]=es_Auto3369;
	_Context->msg_Auto3369[4]=de_Auto3369;
	_Context->msg_Auto3369[5]=nl_Auto3369;
	_Context->msg_Auto3369[6]=pt_Auto3369;
	_Context->msg_Auto3369[7]=xx_Auto3369;
	_Context->hint_Auto3369[0]=en__Auto3369;
	_Context->hint_Auto3369[1]=fr__Auto3369;
	_Context->hint_StubName[0]=en__StubName;
	for (i=0; i < 8; i++)_Context->msg_EditBase[i]=" ";
	_Context->msg_EditBase[0]=en_EditBase;
	_Context->msg_EditBase[1]=fr_EditBase;
	_Context->msg_EditBase[2]=it_EditBase;
	_Context->msg_EditBase[3]=es_EditBase;
	_Context->msg_EditBase[4]=de_EditBase;
	_Context->msg_EditBase[5]=nl_EditBase;
	_Context->msg_EditBase[6]=pt_EditBase;
	_Context->msg_EditBase[7]=xx_EditBase;
	for (i=0; i < 8; i++)_Context->msg_ViewList[i]=" ";
	_Context->msg_ViewList[0]=en_ViewList;
	_Context->msg_ViewList[1]=fr_ViewList;
	_Context->msg_ViewList[2]=it_ViewList;
	_Context->msg_ViewList[3]=es_ViewList;
	_Context->msg_ViewList[4]=de_ViewList;
	_Context->msg_ViewList[5]=nl_ViewList;
	_Context->msg_ViewList[6]=pt_ViewList;
	_Context->msg_ViewList[7]=xx_ViewList;
	_Context->hint_ViewList[0]=en__ViewList;
	_Context->hint_ListName[0]=en__ListName;
	for (i=0; i < 8; i++)_Context->msg_EditFile[i]=" ";
	_Context->msg_EditFile[0]=en_EditFile;
	_Context->msg_EditFile[1]=fr_EditFile;
	_Context->msg_EditFile[2]=it_EditFile;
	_Context->msg_EditFile[3]=es_EditFile;
	_Context->msg_EditFile[4]=de_EditFile;
	_Context->msg_EditFile[5]=nl_EditFile;
	_Context->msg_EditFile[6]=pt_EditFile;
	_Context->msg_EditFile[7]=xx_EditFile;
	for (i=0; i < 8; i++)_Context->msg_Language[i]=" ";
	_Context->msg_Language[0]=en_Language;
	_Context->msg_Language[1]=fr_Language;
	_Context->msg_Language[2]=it_Language;
	_Context->msg_Language[3]=es_Language;
	_Context->msg_Language[4]=de_Language;
	_Context->msg_Language[5]=nl_Language;
	_Context->msg_Language[6]=pt_Language;
	_Context->msg_Language[7]=xx_Language;
	_Context->hint_Language[0]=en__Language;
	_Context->hint_PageItems[0]=en__PageItems;
	sprintf(_Context->buffer_PageItems,"%u",32);
	_Context->hint_ListLines[0]=en__ListLines;
	_Context->hint_ListLines[1]=fr__ListLines;
	sprintf(_Context->buffer_ListLines,"%u",24);
	_Context->hint_ListColumns[0]=en__ListColumns;
	sprintf(_Context->buffer_ListColumns,"%u",100);
	_Context->hint_MaxColumn[0]=en__MaxColumn;
	_Context->hint_MaxColumn[1]=fr__MaxColumn;
	sprintf(_Context->buffer_MaxColumn,"%u",24);
	for (i=0; i < 8; i++)_Context->msg_GenerateMask[i]=" ";
	_Context->msg_GenerateMask[0]=en_GenerateMask;
	_Context->msg_GenerateMask[1]=fr_GenerateMask;
	_Context->msg_GenerateMask[2]=it_GenerateMask;
	_Context->msg_GenerateMask[3]=es_GenerateMask;
	_Context->msg_GenerateMask[4]=de_GenerateMask;
	_Context->msg_GenerateMask[5]=nl_GenerateMask;
	_Context->msg_GenerateMask[6]=pt_GenerateMask;
	_Context->msg_GenerateMask[7]=xx_GenerateMask;
	_Context->hint_GenerateMask[0]=en__GenerateMask;
	_Context->hint_GenerateMask[1]=fr__GenerateMask;
	for (i=0; i < 8; i++)_Context->msg_GeneratePage[i]=" ";
	_Context->msg_GeneratePage[0]=en_GeneratePage;
	_Context->msg_GeneratePage[1]=fr_GeneratePage;
	_Context->msg_GeneratePage[2]=it_GeneratePage;
	_Context->msg_GeneratePage[3]=es_GeneratePage;
	_Context->msg_GeneratePage[4]=de_GeneratePage;
	_Context->msg_GeneratePage[5]=nl_GeneratePage;
	_Context->msg_GeneratePage[6]=pt_GeneratePage;
	_Context->msg_GeneratePage[7]=xx_GeneratePage;
	_Context->hint_GeneratePage[0]=en__GeneratePage;
	_Context->hint_GeneratePage[1]=fr__GeneratePage;
	for (i=0; i < 8; i++)_Context->msg_GenerateList[i]=" ";
	_Context->msg_GenerateList[0]=en_GenerateList;
	_Context->msg_GenerateList[1]=fr_GenerateList;
	_Context->msg_GenerateList[2]=it_GenerateList;
	_Context->msg_GenerateList[3]=es_GenerateList;
	_Context->msg_GenerateList[4]=de_GenerateList;
	_Context->msg_GenerateList[5]=nl_GenerateList;
	_Context->msg_GenerateList[6]=pt_GenerateList;
	_Context->msg_GenerateList[7]=xx_GenerateList;
	_Context->hint_GenerateList[0]=en__GenerateList;
	_Context->hint_GenerateList[1]=fr__GenerateList;
	for (i=0; i < 8; i++)_Context->msg_ImportBase[i]=" ";
	_Context->msg_ImportBase[0]=en_ImportBase;
	_Context->msg_ImportBase[1]=fr_ImportBase;
	_Context->msg_ImportBase[2]=it_ImportBase;
	_Context->msg_ImportBase[3]=es_ImportBase;
	_Context->msg_ImportBase[4]=de_ImportBase;
	_Context->msg_ImportBase[5]=nl_ImportBase;
	_Context->msg_ImportBase[6]=pt_ImportBase;
	_Context->msg_ImportBase[7]=xx_ImportBase;
	_Context->hint_ImportBase[0]=en__ImportBase;
	for (i=0; i < 8; i++)_Context->msg_ExportBase[i]=" ";
	_Context->msg_ExportBase[0]=en_ExportBase;
	_Context->msg_ExportBase[1]=fr_ExportBase;
	_Context->msg_ExportBase[2]=it_ExportBase;
	_Context->msg_ExportBase[3]=es_ExportBase;
	_Context->msg_ExportBase[4]=de_ExportBase;
	_Context->msg_ExportBase[5]=nl_ExportBase;
	_Context->msg_ExportBase[6]=pt_ExportBase;
	_Context->msg_ExportBase[7]=xx_ExportBase;
	_Context->hint_ExportBase[0]=en__ExportBase;
	for (i=0; i < 8; i++)_Context->msg_ListBase[i]=" ";
	_Context->msg_ListBase[0]=en_ListBase;
	_Context->msg_ListBase[1]=fr_ListBase;
	_Context->msg_ListBase[2]=it_ListBase;
	_Context->msg_ListBase[3]=es_ListBase;
	_Context->msg_ListBase[4]=de_ListBase;
	_Context->msg_ListBase[5]=nl_ListBase;
	_Context->msg_ListBase[6]=pt_ListBase;
	_Context->msg_ListBase[7]=xx_ListBase;
	_Context->hint_ListBase[0]=en__ListBase;
	_Context->hint_ListBase[1]=fr__ListBase;
	_Context->hint_ListBase[2]=it__ListBase;
	_Context->hint_ListBase[3]=es__ListBase;
	_Context->hint_ListBase[4]=de__ListBase;
	_Context->hint_ListBase[5]=nl__ListBase;
	_Context->hint_ListBase[6]=pt__ListBase;
	_Context->hint_ListBase[7]=xx__ListBase;
	for (i=0; i < 8; i++)_Context->msg_NationalHelptext[i]=" ";
	_Context->msg_NationalHelptext[0]=en_NationalHelptext;
	_Context->msg_NationalHelptext[1]=fr_NationalHelptext;
	_Context->msg_NationalHelptext[2]=it_NationalHelptext;
	_Context->msg_NationalHelptext[3]=es_NationalHelptext;
	_Context->msg_NationalHelptext[4]=de_NationalHelptext;
	_Context->msg_NationalHelptext[5]=nl_NationalHelptext;
	_Context->msg_NationalHelptext[6]=pt_NationalHelptext;
	_Context->msg_NationalHelptext[7]=xx_NationalHelptext;
	_Context->hint_NationalHelptext[0]=en__NationalHelptext;
	_Context->hint_NationalHelptext[1]=fr__NationalHelptext;
	_Context->hint_NationalHelptext[2]=it__NationalHelptext;
	_Context->hint_NationalHelptext[3]=es__NationalHelptext;
	_Context->hint_NationalHelptext[4]=de__NationalHelptext;
	_Context->hint_NationalHelptext[5]=nl__NationalHelptext;
	_Context->hint_NationalHelptext[6]=pt__NationalHelptext;
	_Context->hint_NationalHelptext[7]=xx__NationalHelptext;
	for (i=0; i < 8; i++)_Context->msg_ExportForm[i]=" ";
	_Context->msg_ExportForm[0]=en_ExportForm;
	_Context->msg_ExportForm[1]=fr_ExportForm;
	_Context->msg_ExportForm[2]=it_ExportForm;
	_Context->msg_ExportForm[3]=es_ExportForm;
	_Context->msg_ExportForm[4]=de_ExportForm;
	_Context->msg_ExportForm[5]=nl_ExportForm;
	_Context->msg_ExportForm[6]=pt_ExportForm;
	_Context->msg_ExportForm[7]=xx_ExportForm;
	_Context->hint_ExportForm[0]=en__ExportForm;
	_Context->hint_ExportForm[1]=fr__ExportForm;
	_Context->hint_ExportForm[2]=it__ExportForm;
	_Context->hint_ExportForm[3]=es__ExportForm;
	_Context->hint_ExportForm[4]=de__ExportForm;
	_Context->hint_ExportForm[5]=nl__ExportForm;
	_Context->hint_ExportForm[6]=pt__ExportForm;
	_Context->hint_ExportForm[7]=xx__ExportForm;
	for (i=0; i < 8; i++)_Context->msg_DeleteBase[i]=" ";
	_Context->msg_DeleteBase[0]=en_DeleteBase;
	_Context->msg_DeleteBase[1]=fr_DeleteBase;
	_Context->msg_DeleteBase[2]=it_DeleteBase;
	_Context->msg_DeleteBase[3]=es_DeleteBase;
	_Context->msg_DeleteBase[4]=de_DeleteBase;
	_Context->msg_DeleteBase[5]=nl_DeleteBase;
	_Context->msg_DeleteBase[6]=pt_DeleteBase;
	_Context->msg_DeleteBase[7]=xx_DeleteBase;
	_Context->hint_DeleteBase[0]=en__DeleteBase;
	_Context->hint_DeleteBase[1]=fr__DeleteBase;
	_Context->hint_DeleteBase[2]=it__DeleteBase;
	_Context->hint_DeleteBase[3]=es__DeleteBase;
	_Context->hint_DeleteBase[4]=de__DeleteBase;
	_Context->hint_DeleteBase[5]=nl__DeleteBase;
	_Context->hint_DeleteBase[6]=pt__DeleteBase;
	_Context->hint_DeleteBase[7]=xx__DeleteBase;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3333,_Context->y_Auto3333,790+10,590+10);
	return(0);
}

public 	int	old_database_editor_hide(struct old_database_editor_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->p_TypeSelect != (void *) 0)
	&& (_Context->s_TypeSelect != 0)) {
		(void)visual_buffer_put(_Context->p_TypeSelect,_Context->x_TypeSelect,_Context->y_TypeSelect);
		_Context->s_TypeSelect=0;
		}
	if ((_Context->p_PasteFile != (void *) 0)
	&& (_Context->s_PasteFile != 0)) {
		(void)visual_buffer_put(_Context->p_PasteFile,_Context->x_Auto3333+280,_Context->y_Auto3333+540);
		_Context->s_PasteFile=0;
		}
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3333,_Context->y_Auto3333);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	old_database_editor_remove(struct old_database_editor_context * _Context)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->p_TypeSelect != (void *) 0)
		_Context->p_TypeSelect = visual_drop(_Context->p_TypeSelect);
	if (_Context->p_PasteFile != (void *) 0)
		_Context->p_PasteFile = visual_drop(_Context->p_PasteFile);
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}
private int on_BaseName_show(struct old_database_editor_context * _Context) {
	if((FileManager)&&(FileManager->name))
	strcpy(_Context->buffer_BaseName,FileManager->name);
	else strcpy(_Context->buffer_BaseName," ");
	visual_frame(_Context->x_Auto3333+170,_Context->y_Auto3333+70,392+2,15+2,5);
visual_text(_Context->x_Auto3333+170+1,_Context->y_Auto3333+70+1,392,15,vfh[1],16,0,_Context->buffer_BaseName,49,3);
;
	return(-1);
}
private int on_BaseUsers_show(struct old_database_editor_context * _Context) {
	if((FileManager))
	sprintf(_Context->buffer_BaseUsers,"%u",FileManager->usage);
	else sprintf(_Context->buffer_BaseUsers,"%u",0);
	visual_frame(_Context->x_Auto3333+680,_Context->y_Auto3333+70,56+2,15+2,5);
visual_text(_Context->x_Auto3333+680+1,_Context->y_Auto3333+70+1,56,15,vfh[1],16,0,_Context->buffer_BaseUsers,7,3);
;
	return(-1);
}
private int on_FileList_show(struct old_database_editor_context * _Context) {
	int m;
	int n;
	int l;
	int item;
	struct file_control*fptr;
	struct data_control*dptr;
	if(n=GetFileNumber(_Context))
	{
	start_sort_FileList(_Context,n);
	for(l=1;l<=n;l++){
	if((fptr=locate_file(_Context, l))){
	if ( l > 0 ) { _Context->row_FileList=&_Context->libsort_FileList[(l-1)*88]; } ;
	if(fptr->classname)
	putstring(_Context, (_Context->row_FileList+0),33,fptr->classname);
	if(fptr->identity)
	putstring(_Context, (_Context->row_FileList+33),33,fptr->identity);
	if((dptr=fptr->payload)!=(struct data_control*)0){
	if(dptr->datalength>0){
	if(fptr->nature==5/*_VMEMORY_FRAME*/){
	sprintf((_Context->row_FileList+66),"F=%u(%u)",dptr->datalength,dptr->datafields);
	}
	else{
	sprintf((_Context->row_FileList+66),"D=%u(%u)",dptr->datalength,dptr->datafields);
	}
	}
	if(dptr->indexlength>0){
	if(dptr->option&_A_LEFT){
	sprintf((_Context->row_FileList+77),"LK=%u(%u)",dptr->indexlength,dptr->indexfields);
	}
	else if(dptr->option&_A_RIGHT){
	sprintf((_Context->row_FileList+77),"RK=%u(%u)",dptr->indexlength,dptr->indexfields);
	}
	else{
	sprintf((_Context->row_FileList+77),"K=%u(%u)",dptr->indexlength,dptr->indexfields);
	}
	}
	}
	}
	}
	sort_FileList(_Context,n);
	}
	if(!(m=_Context->value_FileList))
	m=1;
	memset(_Context->buffer_FileList,' ',2288);
	for(l=1;
	l<=26;
	l++){
	n=(_Context->value_ScrollBar+l);
	item=sort_item_FileList(_Context,n);
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
	if(fptr->nature==5/*_VMEMORY_FRAME*/){
	sprintf((_Context->row_FileList+66),"F=%u(%u)",dptr->datalength,dptr->datafields);
	}
	else{
	sprintf((_Context->row_FileList+66),"D=%u(%u)",dptr->datalength,dptr->datafields);
	}
	}
	if(dptr->indexlength>0){
	if(dptr->option&_A_LEFT){
	sprintf((_Context->row_FileList+77),"LK=%u(%u)",dptr->indexlength,dptr->indexfields);
	}
	else if(dptr->option&_A_RIGHT){
	sprintf((_Context->row_FileList+77),"RK=%u(%u)",dptr->indexlength,dptr->indexfields);
	}
	else{
	sprintf((_Context->row_FileList+77),"K=%u(%u)",dptr->indexlength,dptr->indexfields);
	}
	}
	}
	}
	}
		visual_table(_Context->x_Auto3333+30,_Context->y_Auto3333+90,710,450,vfh[1],27,28,_Context->msg_FileList[_Context->language],_Context->buffer_FileList,0x4401,"($,W32,W10,W10)");
;
	_Context->x_Mursor=_Context->x_Auto3333+30;
	_Context->y_Mursor=_Context->y_Auto3333+90+(m*16);
		visual_filzone(_Context->x_Mursor,_Context->y_Mursor,_Context->w_Mursor,_Context->h_Mursor,7453,16);

	_Context->value_FileList=m;
	return(-1);
}
private int on_PasteFile_show(struct old_database_editor_context * _Context) {
	if(BaseManager.CopyFile){
		if ((_Context->p_PasteFile != (void *) 0)
	&& (_Context->s_PasteFile == 0)) {
		(void)visual_buffer_get(_Context->p_PasteFile,_Context->x_Auto3333+280,_Context->y_Auto3333+540);
		_Context->s_PasteFile=1;
		}
	if ((_Context->p_PasteFile != (void *) 0)
	&& (_Context->s_PasteFile == 0)) {
		(void)visual_buffer_get(_Context->p_PasteFile,_Context->x_Auto3333+280,_Context->y_Auto3333+540);
		_Context->s_PasteFile=1;
		}
	_Context->trigger_PasteFile=visual_trigger_code(_Context->msg_PasteFile[_Context->language],strlen(_Context->msg_PasteFile[_Context->language]));
	visual_button(_Context->x_Auto3333+280,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_PasteFile[_Context->language],strlen(_Context->msg_PasteFile[_Context->language]),0);
;
	}
	else{
		if ((_Context->p_PasteFile != (void *) 0)
	&& (_Context->s_PasteFile != 0)) {
		(void)visual_buffer_put(_Context->p_PasteFile,_Context->x_Auto3333+280,_Context->y_Auto3333+540);
		_Context->s_PasteFile=0;
		}
;
	}
	return(-1);
}
private int on_ClassName_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->classname))
	putstring(_Context, _Context->buffer_ClassName,255,FileManager->current->classname);
	else putstring(_Context, _Context->buffer_ClassName,255," ");
	visual_frame(_Context->x_Auto3333+110,_Context->y_Auto3333+80,328+2,16+2,5);
visual_text(_Context->x_Auto3333+110+1,_Context->y_Auto3333+80+1,328,16,vfh[1],16,0,_Context->buffer_ClassName,255,0);
;
	return(-1);
}
private int on_Instance_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->identity))
	putstring(_Context, _Context->buffer_Instance,255,FileManager->current->identity);
	else putstring(_Context, _Context->buffer_Instance,255," ");
	visual_frame(_Context->x_Auto3333+110,_Context->y_Auto3333+100,328+2,16+2,5);
visual_text(_Context->x_Auto3333+110+1,_Context->y_Auto3333+100+1,328,16,vfh[1],16,0,_Context->buffer_Instance,255,0);
;
	return(-1);
}
private int on_Filename_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->filename))
	putstring(_Context, _Context->buffer_Filename,255,FileManager->current->filename);
	else putstring(_Context, _Context->buffer_Filename,255," ");
	visual_frame(_Context->x_Auto3333+110,_Context->y_Auto3333+120,328+2,16+2,5);
visual_text(_Context->x_Auto3333+110+1,_Context->y_Auto3333+120+1,328,16,vfh[1],16,0,_Context->buffer_Filename,255,0);
;
	return(-1);
}
private int on_FileType_show(struct old_database_editor_context * _Context) {
	if(FileManager->current)
	_Context->value_FileType=FileManager->current->nature;
	else _Context->value_FileType=2;
		visual_select(_Context->x_Auto3333+110,_Context->y_Auto3333+140,96,64,vfh[2],0,28,parse_selection(WidgetDataList,&_Context->value_FileType),768);

	return(-1);
}
private int on_IndexType_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(FileManager->current->payload->option&_A_LEFT)
	_Context->value_IndexType=1;
	else if(FileManager->current->payload->option&_A_RIGHT)
	_Context->value_IndexType=2;
	else _Context->value_IndexType=0;
	}
		visual_select(_Context->x_Auto3333+260,_Context->y_Auto3333+140,48,64,vfh[1],0,0,parse_selection(_Context->msg_IndexType[_Context->language],&_Context->value_IndexType),0);
;
	return(-1);
}
private int on_IndexSize_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if((FileManager->current->nature==_MCFILE_FRAME)
	||(FileManager->current->nature==_SIFILE_FRAME))
	check_file_indexlength(_Context);
	sprintf(_Context->buffer_IndexSize,"%u",FileManager->current->payload->indexlength);
	}
	else strcpy(_Context->buffer_IndexSize," ");
	visual_frame(_Context->x_Auto3333+580,_Context->y_Auto3333+100,64+2,16+2,5);
visual_text(_Context->x_Auto3333+580+1,_Context->y_Auto3333+100+1,64,16,vfh[1],16,0,_Context->buffer_IndexSize,8,0);
;
	return(-1);
}
private int on_NbIndex_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload))
	sprintf(_Context->buffer_NbIndex,"%u",FileManager->current->payload->indexfields);
	else strcpy(_Context->buffer_NbIndex," ");
	visual_frame(_Context->x_Auto3333+680,_Context->y_Auto3333+100,40+2,16+2,5);
visual_text(_Context->x_Auto3333+680+1,_Context->y_Auto3333+100+1,40,16,vfh[1],16,0,_Context->buffer_NbIndex,5,0);

	return(-1);
}
private int on_RecordType_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(FileManager->current->payload->option&_A_BOLD)
	_Context->value_RecordType=1;
	else _Context->value_RecordType=0;
	}
		_Context->trigger_RecordType=visual_trigger_code(_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]));
	visual_switch(_Context->x_Auto3333+312,_Context->y_Auto3333+140,30,22,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),_Context->value_RecordType| 0x0030);
;
	return(-1);
}
private int on_MarkerUseage_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(FileManager->current->payload->option&_A_SHADOW)
	_Context->value_MarkerUseage=1;
	else _Context->value_MarkerUseage=0;
	}
		_Context->trigger_MarkerUseage=visual_trigger_code(_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]));
	visual_switch(_Context->x_Auto3333+410,_Context->y_Auto3333+140,30,22,vfh[2],27,28,_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]),_Context->value_MarkerUseage| 0x0030);
;
	return(-1);
}
private int on_Modext_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(FileManager->current->payload->option&_A_LINE)
	_Context->value_Modext=1;
	else _Context->value_Modext=0;
	}
		_Context->trigger_Modext=visual_trigger_code(_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]));
	visual_switch(_Context->x_Auto3333+344,_Context->y_Auto3333+140,65,22,vfh[2],27,28,_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]),_Context->value_Modext| 0x0030);
;
	return(-1);
}
private int on_RecordSize_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(FileManager->current->nature!=_VMEMORY_FRAME)
	check_file_datalength(_Context);
	sprintf(_Context->buffer_RecordSize,"%u",FileManager->current->payload->datalength);
	}
	else strcpy(_Context->buffer_RecordSize," ");
	visual_frame(_Context->x_Auto3333+580,_Context->y_Auto3333+120,64+2,16+2,5);
visual_text(_Context->x_Auto3333+580+1,_Context->y_Auto3333+120+1,64,16,vfh[1],16,0,_Context->buffer_RecordSize,8,0);
;
	return(-1);
}
private int on_NbData_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload))
	sprintf(_Context->buffer_NbData,"%u",FileManager->current->payload->datafields);
	else strcpy(_Context->buffer_NbData," ");
	visual_frame(_Context->x_Auto3333+680,_Context->y_Auto3333+120,40+2,16+2,5);
visual_text(_Context->x_Auto3333+680+1,_Context->y_Auto3333+120+1,40,16,vfh[1],16,0,_Context->buffer_NbData,5,0);

	return(-1);
}
private int on_IndexMembers_show(struct old_database_editor_context * _Context) {
	struct data_control*dptr;
	int i;
	int l;
	int n;
	if(!(n=_Context->value_IndexMembers))
	n=1;
	memset(_Context->buffer_IndexMembers,' ',348);
	if((!(FileManager->current))
	||(!(dptr=FileManager->current->payload)))
	return(0);
	else{
	if((_Context->max_IndexBar=dptr->indexfields)>0){
	for(l=1;l<=4;l++){
	if((i=((l-1)+_Context->value_IndexBar))>=dptr->indexfields)
	break;
	else{
	if ( l > 0 ) { _Context->row_IndexMembers=&_Context->buffer_IndexMembers[l-1][0]; } ;
	putstring(_Context, (_Context->row_IndexMembers+0),56,dptr->name[i]);
	switch(dptr->type[i]){
	case _ABAL_FIELD:
	putstring(_Context, (_Context->row_IndexMembers+56),9,"field");
	break;
	case _ABAL_FILLER:
	putstring(_Context, (_Context->row_IndexMembers+56),9,"filler");
	sprintf((_Context->row_IndexMembers+65),"%u",dptr->width[i]);
	break;
	case _ABAL_BYTE:
	putstring(_Context, (_Context->row_IndexMembers+56),9,"int8");
	sprintf((_Context->row_IndexMembers+65),"%u",1);
	break;
	case _ABAL_WORD:
	putstring(_Context, (_Context->row_IndexMembers+56),9,"int16");
	sprintf((_Context->row_IndexMembers+65),"%u",2);
	break;
	case _ABAL_LONG:
	putstring(_Context, (_Context->row_IndexMembers+56),9,"int32");
	sprintf((_Context->row_IndexMembers+65),"%u",4);
	break;
	case _ABAL_BCD:
	putstring(_Context, (_Context->row_IndexMembers+56),9,"bcd");
	if(dptr->decimal[i])
	sprintf((_Context->row_IndexMembers+65),"%u.%u",dptr->width[i],dptr->decimal[i]);
	else sprintf((_Context->row_IndexMembers+65),"%u",dptr->width[i]);
	break;
	case _ABAL_STRING:
	putstring(_Context, (_Context->row_IndexMembers+56),9,"string");
	sprintf((_Context->row_IndexMembers+65),"%u",dptr->width[i]);
	break;
	}
	sprintf((_Context->row_IndexMembers+71),"%u",dptr->first[i]);
	sprintf((_Context->row_IndexMembers+77),"%u",dptr->second[i]);
	}
	}
		visual_table(_Context->x_Auto3333+40,_Context->y_Auto3333+180,700,90,vfh[1],0,0,_Context->msg_IndexMembers[_Context->language],_Context->buffer_IndexMembers,0x4401,"($,W8,N4Z,N4Z,N4Z,W,W)");
;
	for(l=1;l<=4;l++){
	if((i=((l-1)+_Context->value_IndexBar))>=dptr->indexfields)
	break;
	if(dptr->special[i]&1){
	_Context->y_IsLink=_Context->y_Auto3333+180+(l*16);
		visual_image(_Context->x_IsLink,_Context->y_IsLink,_Context->w_IsLink,_Context->h_IsLink,_Context->msg_IsLink[_Context->language],1541);
;
	}
	if(dptr->special[i]&2){
	_Context->y_IsList=_Context->y_Auto3333+180+(l*16);
		visual_image(_Context->x_IsList,_Context->y_IsList,_Context->w_IsList,_Context->h_IsList,_Context->msg_IsList[_Context->language],1541);
;
	}
	}
	_Context->x_Cursor=_Context->x_Auto3333+40;
	_Context->y_Cursor=_Context->y_Auto3333+180+(n*16);
		visual_filzone(_Context->x_Cursor,_Context->y_Cursor,_Context->w_Cursor,_Context->h_Cursor,7453,16);

	_Context->value_IndexMembers=n;
	}
	}
		return(-1);
}
private int on_IndexBar_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)
	&&((_Context->max_IndexBar=FileManager->current->payload->indexfields)!=0)){
		visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
;
	}
	return(-1);
}
private int on_DataMembers_show(struct old_database_editor_context * _Context) {
	struct data_control*dptr;
	int i;
	int l;
	int n;
	if(!(n=_Context->value_DataMembers))
	n=1;
	memset(_Context->buffer_DataMembers,' ',1392);
	if((!(FileManager->current))
	||(!(dptr=FileManager->current->payload)))
	return(0);
	else{
	if((_Context->max_DataBar=dptr->datafields)>0){
	for(l=1;l<=16;l++){
	if((i=((l-1)+_Context->value_DataBar))>=dptr->datafields)
	break;
	else{
	if ( l > 0 ) { _Context->row_DataMembers=&_Context->buffer_DataMembers[l-1][0]; } ;
	putstring(_Context, (_Context->row_DataMembers+0),56,dptr->name[i+dptr->indexfields]);
	switch(dptr->type[i+dptr->indexfields]){
	case _ABAL_FIELD:
	putstring(_Context, (_Context->row_DataMembers+56),9,"field");
	break;
	case _ABAL_FILLER:
	putstring(_Context, (_Context->row_DataMembers+56),9,"filler");
	sprintf((_Context->row_DataMembers+65),"%u",dptr->width[i+dptr->indexfields]);
	break;
	case _ABAL_BYTE:
	putstring(_Context, (_Context->row_DataMembers+56),9,"int8");
	sprintf((_Context->row_DataMembers+65),"%u",1);
	break;
	case _ABAL_WORD:
	putstring(_Context, (_Context->row_DataMembers+56),9,"int16");
	sprintf((_Context->row_DataMembers+65),"%u",2);
	break;
	case _ABAL_LONG:
	putstring(_Context, (_Context->row_DataMembers+56),9,"int32");
	sprintf((_Context->row_DataMembers+65),"%u",4);
	break;
	case _ABAL_BCD:
	putstring(_Context, (_Context->row_DataMembers+56),9,"bcd");
	if(dptr->decimal[i+dptr->indexfields])
	sprintf((_Context->row_DataMembers+65),"%u.%u",dptr->width[i+dptr->indexfields],dptr->decimal[i+dptr->indexfields]);
	else sprintf((_Context->row_DataMembers+65),"%u",dptr->width[i+dptr->indexfields]);
	break;
	case _ABAL_STRING:
	putstring(_Context, (_Context->row_DataMembers+56),9,"string");
	sprintf((_Context->row_DataMembers+65),"%u",dptr->width[i+dptr->indexfields]);
	break;
	}
	sprintf((_Context->row_DataMembers+71),"%u",dptr->first[i+dptr->indexfields]);
	sprintf((_Context->row_DataMembers+77),"%u",dptr->second[i+dptr->indexfields]);
	}
	}
		visual_table(_Context->x_Auto3333+40,_Context->y_Auto3333+280,700,280,vfh[1],0,0,_Context->msg_DataMembers[_Context->language],_Context->buffer_DataMembers,0x4401,"($,W8,N4Z,N4Z,N4Z,W,W)");
;
	for(l=1;l<=16;l++){
	if((i=((l-1)+_Context->value_DataBar))>=dptr->datafields)
	break;
	if(dptr->special[i+dptr->indexfields]&1){
	_Context->y_IsLink=_Context->y_Auto3333+280+(l*16);
		visual_image(_Context->x_IsLink,_Context->y_IsLink,_Context->w_IsLink,_Context->h_IsLink,_Context->msg_IsLink[_Context->language],1541);
;
	}
	if(dptr->special[i+dptr->indexfields]&2){
	_Context->y_IsList=_Context->y_Auto3333+280+(l*16);
		visual_image(_Context->x_IsList,_Context->y_IsList,_Context->w_IsList,_Context->h_IsList,_Context->msg_IsList[_Context->language],1541);
;
	}
	}
	_Context->x_Kursor=_Context->x_Auto3333+40;
	_Context->y_Kursor=_Context->y_Auto3333+280+(n*16);
		visual_filzone(_Context->x_Kursor,_Context->y_Kursor,_Context->w_Kursor,_Context->h_Kursor,7453,16);

	_Context->value_DataMembers=n;
	}
	}
	return(-1);
}
private int on_DataBar_show(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)
	&&((_Context->max_DataBar=FileManager->current->payload->datafields)!=0)){
		visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
;
	}
	return(-1);
}

public	int	old_database_editor_show(struct old_database_editor_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3333,_Context->y_Auto3333);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3333,_Context->y_Auto3333,790,590,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3333,_Context->y_Auto3333,790,590,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ListPage=visual_trigger_code(_Context->msg_ListPage[_Context->language],strlen(_Context->msg_ListPage[_Context->language]));
	visual_tabpage(_Context->x_Auto3333+20,_Context->y_Auto3333+40,750,540,vfh[2],_Context->msg_ListPage[_Context->language],strlen(_Context->msg_ListPage[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto3333+20,_Context->y_Auto3333+40,750,540,vfh[2],_Context->msg_ListPage[_Context->language],strlen(_Context->msg_ListPage[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3333+30,_Context->y_Auto3333+70,126,16,vfh[2],16,0,_Context->msg_Auto3334[_Context->language],strlen(_Context->msg_Auto3334[_Context->language]),1);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3333+570,_Context->y_Auto3333+70,98,16,vfh[2],16,0,_Context->msg_Auto3335[_Context->language],strlen(_Context->msg_Auto3335[_Context->language]),1);
		}
	if (_Context->page_number == 1 ) {
	(void) on_BaseName_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	(void) on_BaseUsers_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	(void) on_FileList_show(_Context);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3333+740,_Context->y_Auto3333+180,8,16,vfh[1],27,28,_Context->msg_Auto3336[_Context->language],strlen(_Context->msg_Auto3336[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_CopyFile=visual_trigger_code(_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]));
	visual_button(_Context->x_Auto3333+30,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_DeleteFile=visual_trigger_code(_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]));
	visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	if ((_Context->p_PasteFile != (void *) 0)
	&& (_Context->s_PasteFile == 0)) {
		(void)visual_buffer_get(_Context->p_PasteFile,_Context->x_Auto3333+280,_Context->y_Auto3333+540);
		_Context->s_PasteFile=1;
		}
	(void) on_PasteFile_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_FilePage=visual_trigger_code(_Context->msg_FilePage[_Context->language],strlen(_Context->msg_FilePage[_Context->language]));
	visual_tabpage(_Context->x_Auto3333+20,_Context->y_Auto3333+40,750,540,vfh[2],_Context->msg_FilePage[_Context->language],strlen(_Context->msg_FilePage[_Context->language]),59,2);
	} else {
		visual_tabpage(_Context->x_Auto3333+20,_Context->y_Auto3333+40,750,540,vfh[2],_Context->msg_FilePage[_Context->language],strlen(_Context->msg_FilePage[_Context->language]),59,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3333+40,_Context->y_Auto3333+70,410,100,4);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3333+450,_Context->y_Auto3333+70,310,100,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+30,_Context->y_Auto3333+80,70,16,vfh[2],16,0,_Context->msg_Auto3339[_Context->language],strlen(_Context->msg_Auto3339[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+660,_Context->y_Auto3333+80,84,16,vfh[2],16,0,_Context->msg_Auto3340[_Context->language],strlen(_Context->msg_Auto3340[_Context->language]),1283);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+580,_Context->y_Auto3333+80,70,16,vfh[2],16,0,_Context->msg_Auto3341[_Context->language],strlen(_Context->msg_Auto3341[_Context->language]),1283);
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
	_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
	visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_NbIndex_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_RecordType_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_MarkerUseage_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_Modext_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	(void) on_RecordSize_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto3344=visual_trigger_code(_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]));
	visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	(void) on_NbData_show(_Context);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto3345=visual_trigger_code(_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3333+580,_Context->y_Auto3333+140,97,27,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_FileUsers=visual_trigger_code(_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]));
	visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+139,66,28,vfh[2],27,28,_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+30,_Context->y_Auto3333+140,70,16,vfh[2],16,0,_Context->msg_Auto3346[_Context->language],strlen(_Context->msg_Auto3346[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+210,_Context->y_Auto3333+140,42,16,vfh[2],16,0,_Context->msg_Auto3347[_Context->language],strlen(_Context->msg_Auto3347[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+460,_Context->y_Auto3333+100,112,16,vfh[2],16,0,PrimaryIndexLabel(_Context),strlen(PrimaryIndexLabel(_Context)),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+460,_Context->y_Auto3333+120,112,16,vfh[2],16,0,DataRecordLabel(_Context),strlen(DataRecordLabel(_Context)),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+30,_Context->y_Auto3333+100,70,16,vfh[2],16,0,_Context->msg_Auto3350[_Context->language],strlen(_Context->msg_Auto3350[_Context->language]),1281);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3333+30,_Context->y_Auto3333+120,70,16,vfh[2],16,0,_Context->msg_Auto3351[_Context->language],strlen(_Context->msg_Auto3351[_Context->language]),1281);
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
	visual_tabpage(_Context->x_Auto3333+20,_Context->y_Auto3333+40,750,540,vfh[2],_Context->msg_MaskPage[_Context->language],strlen(_Context->msg_MaskPage[_Context->language]),128,2);
	} else {
		visual_tabpage(_Context->x_Auto3333+20,_Context->y_Auto3333+40,750,540,vfh[2],_Context->msg_MaskPage[_Context->language],strlen(_Context->msg_MaskPage[_Context->language]),128,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+30,_Context->y_Auto3333+80,730,280,4);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+40,_Context->y_Auto3333+210,230,16,vfh[2],16,0,_Context->msg_Auto3353[_Context->language],strlen(_Context->msg_Auto3353[_Context->language]),1282);
	visual_frame(_Context->x_Auto3333+40,_Context->y_Auto3333+226,230,124,2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+520,_Context->y_Auto3333+210,230,16,vfh[2],16,0,_Context->msg_Auto3354[_Context->language],strlen(_Context->msg_Auto3354[_Context->language]),1282);
	visual_frame(_Context->x_Auto3333+520,_Context->y_Auto3333+226,230,124,2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+280,_Context->y_Auto3333+210,230,16,vfh[2],16,0,_Context->msg_Auto3355[_Context->language],strlen(_Context->msg_Auto3355[_Context->language]),1282);
	visual_frame(_Context->x_Auto3333+280,_Context->y_Auto3333+226,230,124,2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+30,_Context->y_Auto3333+360,730,210,4);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+50,_Context->y_Auto3333+510,620,50,4);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+40,_Context->y_Auto3333+90,713,20,vfh[3],16,0,_Context->msg_Auto3358[_Context->language],strlen(_Context->msg_Auto3358[_Context->language]),1283);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+40,_Context->y_Auto3333+370,713,20,vfh[3],16,0,_Context->msg_Auto3359[_Context->language],strlen(_Context->msg_Auto3359[_Context->language]),1283);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+40,_Context->y_Auto3333+120,700,16,vfh[2],16,0,_Context->msg_Auto3360[_Context->language],strlen(_Context->msg_Auto3360[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+50,_Context->y_Auto3333+420,238,16,vfh[2],16,0,_Context->msg_Auto3361[_Context->language],strlen(_Context->msg_Auto3361[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+50,_Context->y_Auto3333+450,238,16,vfh[2],16,0,_Context->msg_Auto3362[_Context->language],strlen(_Context->msg_Auto3362[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+50,_Context->y_Auto3333+480,238,16,vfh[2],16,0,_Context->msg_Auto3363[_Context->language],strlen(_Context->msg_Auto3363[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+40,_Context->y_Auto3333+160,462,16,vfh[2],16,0,_Context->msg_Auto3364[_Context->language],strlen(_Context->msg_Auto3364[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+520,_Context->y_Auto3333+160,224,16,vfh[2],16,0,_Context->msg_Auto3365[_Context->language],strlen(_Context->msg_Auto3365[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+50,_Context->y_Auto3333+240,140,16,vfh[2],16,0,_Context->msg_Auto3366[_Context->language],strlen(_Context->msg_Auto3366[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+290,_Context->y_Auto3333+240,140,16,vfh[2],16,0,_Context->msg_Auto3367[_Context->language],strlen(_Context->msg_Auto3367[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+290,_Context->y_Auto3333+260,140,16,vfh[2],16,0,_Context->msg_Auto3368[_Context->language],strlen(_Context->msg_Auto3368[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3333+290,_Context->y_Auto3333+280,140,16,vfh[2],16,0,_Context->msg_Auto3369[_Context->language],strlen(_Context->msg_Auto3369[_Context->language]),1282);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+40,_Context->y_Auto3333+140,688+2,16+2,5);
	visual_text(_Context->x_Auto3333+40+1,_Context->y_Auto3333+140+1,688,16,vfh[1],16,0,_Context->buffer_StubName,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_EditBase=visual_trigger_code(_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]));
	visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+420,16,16,vfh[8],27,28,_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]),784);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ViewList=visual_trigger_code(_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]));
	visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+480,16,16,vfh[8],27,28,_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]),784);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+290,_Context->y_Auto3333+420,424+2,16+2,5);
	visual_text(_Context->x_Auto3333+290+1,_Context->y_Auto3333+420+1,424,16,vfh[1],16,0,_Context->buffer_BaseFile,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+290,_Context->y_Auto3333+450,424+2,16+2,5);
	visual_text(_Context->x_Auto3333+290+1,_Context->y_Auto3333+450+1,424,16,vfh[1],16,0,_Context->buffer_FormName,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+290,_Context->y_Auto3333+480,424+2,16+2,5);
	visual_text(_Context->x_Auto3333+290+1,_Context->y_Auto3333+480+1,424,16,vfh[1],16,0,_Context->buffer_ListName,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_EditFile=visual_trigger_code(_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+140,16,16,vfh[8],27,28,_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]),784);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+40,_Context->y_Auto3333+180,472+2,16+2,5);
	visual_text(_Context->x_Auto3333+40+1,_Context->y_Auto3333+180+1,472,16,vfh[1],16,0,_Context->buffer_Title,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(_Context->x_Auto3333+520,_Context->y_Auto3333+180,230,90,vfh[2],16,0,parse_selection(_Context->msg_Language[_Context->language],&_Context->value_Language),768);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+200,_Context->y_Auto3333+240,56+2,16+2,5);
	visual_text(_Context->x_Auto3333+200+1,_Context->y_Auto3333+240+1,56,16,vfh[1],0,0,_Context->buffer_PageItems,7,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+440,_Context->y_Auto3333+240,56+2,16+2,5);
	visual_text(_Context->x_Auto3333+440+1,_Context->y_Auto3333+240+1,56,16,vfh[1],0,0,_Context->buffer_ListLines,7,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+440,_Context->y_Auto3333+260,56+2,16+2,5);
	visual_text(_Context->x_Auto3333+440+1,_Context->y_Auto3333+260+1,56,16,vfh[1],0,0,_Context->buffer_ListColumns,7,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3333+440,_Context->y_Auto3333+280,56+2,16+2,5);
	visual_text(_Context->x_Auto3333+440+1,_Context->y_Auto3333+280+1,56,16,vfh[1],0,0,_Context->buffer_MaxColumn,7,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_GenerateMask=visual_trigger_code(_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]));
	visual_button(_Context->x_Auto3333+50,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_GeneratePage=visual_trigger_code(_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]));
	visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_GenerateList=visual_trigger_code(_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]));
	visual_button(_Context->x_Auto3333+290,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ImportBase=visual_trigger_code(_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]));
	visual_button(_Context->x_Auto3333+60,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ExportBase=visual_trigger_code(_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]));
	visual_button(_Context->x_Auto3333+160,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ListBase=visual_trigger_code(_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]));
	visual_button(_Context->x_Auto3333+560,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_NationalHelptext=visual_trigger_code(_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]));
	visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+510,56,48,vfh[2],28,28,_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]),16);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ExportForm=visual_trigger_code(_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]));
	visual_button(_Context->x_Auto3333+390,_Context->y_Auto3333+520,168,32,vfh[2],16,0,_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_DeleteBase=visual_trigger_code(_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]));
	visual_button(_Context->x_Auto3333+260,_Context->y_Auto3333+520,126,32,vfh[2],16,0,_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]),0);
		}
	visual_thaw(_Context->x_Auto3333,_Context->y_Auto3333,790,590);

	return(0);
}

private int ListPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[1];
			mptr[0] = "This tab page presents the list of all data base items.   ";
			return(visual_online_help(mptr,1));
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
			char * mptr[4];
			mptr[0] = "The item list displays the various file or data entities and a summary ";
			mptr[1]="of their overall basic type. By clicking on a selection with the mouse ";
			mptr[2]="it will be made available in the file data page for inpsection and ";
			mptr[3]="modification.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ScrollBar_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The scroll bar control may be used to scroll through data base information ";
			mptr[1]=" exceeding the visual page size.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CopyFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "When this push button is activated, the current file description, ";
			mptr[1]="of the current database file manager, will be copied allowing it to ";
			mptr[2]="be pasted into the database manager of another project.   ";
			mptr[3]=" ";
			mptr[4]=" The Paste button will be activated to show that a file description ";
			mptr[5]="is available for pasting.  ";
			mptr[6]=" ";
			mptr[7]=" If a file description has already been selected for pasting, prior ";
			mptr[8]="to activation of this button, it will be replaced by the most recently ";
			mptr[9]="selected file description.  ";
			mptr[10]=" ";
			mptr[11]="    ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DeleteFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button may be actioned to delete the currently selected ";
			mptr[1]="file description from the current database manager.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PasteFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[10];
			mptr[0] = "When this button is visible it may be actioned to paste the currently ";
			mptr[1]="selected file description into the current database manager.   ";
			mptr[2]=" ";
			mptr[3]=" File class identifiers are unique.   ";
			mptr[4]=" ";
			mptr[5]="Consequently the pasting of a file class description to a database ";
			mptr[6]="manager will overwrite an existing version of thesame class name. ";
			mptr[7]=" ";
			mptr[8]=" ";
			mptr[9]="     ";
			return(visual_online_help(mptr,10));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FilePage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This tab page presents the individual information pertaining to one ";
			mptr[1]="data or file item of the database collection.  ";
			return(visual_online_help(mptr,2));
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
			char * mptr[3];
			mptr[0] = "This edit field provides the public class name of the data description, ";
			mptr[1]="by which it will be made available to the data widgets of the client ";
			mptr[2]="forms.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Instance_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows an advisory or standard instance name by which ";
			mptr[1]="the data will be accessed.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Filename_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field provides the advisory file name in which the data ";
			mptr[1]="records will usually be stored. This and the instance name may be ";
			mptr[2]="over-ridden as required by the corresponding fields of the client ";
			mptr[3]="data widget.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This selection control allows the basic data or file type to be specified. ";
			mptr[1]="  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IndexType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This selection provides the optional primary index characteristics ";
			mptr[1]="required for sequential indexed and multiple indexed file types.  ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IndexSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the overall size in bytes of the primary index, ";
			mptr[1]="of sequential indexed and multiple indexed files, to be specified. ";
			mptr[2]="This field is of no importance to other data types.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3342_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The data record member count may be decremented by clicking on this ";
			mptr[1]="button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NbIndex_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the current number of members comprising ";
			mptr[1]="the primary index.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3343_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The primary index member count may be incremented by clicking on this ";
			mptr[1]="button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RecordType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The data record of sequential indexex and multiple indexed files may ";
			mptr[1]="be declared to be of variable length by means of this check control. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MarkerUseage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The data record of sequential indexex and multiple indexed files may ";
			mptr[1]="be declared to be of variable length by means of this check control. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Modext_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This check control, when activated, indicates that primary index members ";
			mptr[1]="are to be declared for use in multiple indexed questions via the MODEXT extensions to the abal language.     ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RecordSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field allows the overall size in bytes of the data record ";
			mptr[1]="to be  specified for sequential, sequential indexed and multiple indexed ";
			mptr[2]="files.  ";
			mptr[3]=" ";
			mptr[4]="It will provide the storage handle, a number between 31 and 63, for ";
			mptr[5]="virtual memory files.   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3344_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The primary index member count may be decremented by clicking on this ";
			mptr[1]="button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NbData_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field displays the current number of members comprising ";
			mptr[1]="the data record.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3345_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The data record member count may be incremented by clicking on this ";
			mptr[1]="button.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Accept_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This button may be activated allowing the current contents selected ";
			mptr[1]="by the data  file mechanisms, to be returned as the corresponding ";
			mptr[2]="class identifier to the client form data widget.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FileUsers_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This button may be activated allowing the current file class to be ";
			mptr[1]="submitted for the retrieval of the list of forms models instancing ";
			mptr[2]="file access widgets of the current  class. ";
			mptr[3]=" ";
			mptr[4]=" Access will be given to the File References dialog box for inspection ";
			mptr[5]="and navigation of the results. ";
			mptr[6]=" ";
			mptr[7]="     ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IndexMembers_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This table will be displayed when the primary index member count is ";
			mptr[1]="greater than zero indicating the presence of primary index member ";
			mptr[2]="information.  ";
			mptr[3]=" ";
			mptr[4]="The various columns of valid member items may be modified as required. ";
			mptr[5]=" ";
			mptr[6]=" ";
			mptr[7]="Clicking in the type field will make a selection control appear for ";
			mptr[8]="the  prompted selection of the member data type.  ";
			mptr[9]=" ";
			mptr[10]="Data input in the name field will be analysed for standard abal variable ";
			mptr[11]="declaration syntax.     ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DataMembers_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This table will be displayed when the data record member count is ";
			mptr[1]="greater than zero indicating the presence of data record member information. ";
			mptr[2]="As for the index member information, the various columns of valid ";
			mptr[3]="member items  may be modified as required.  ";
			mptr[4]=" ";
			mptr[5]=" Clicking in the type field will make a selection control appear for ";
			mptr[6]="the  prompted selection of the member data type.  ";
			mptr[7]=" ";
			mptr[8]="The right most column allows inhibition of link generation for the ";
			mptr[9]="corresponding members by the presence of the ! not symbol.  ";
			mptr[10]=" ";
			mptr[11]="Data input in the name field will be analysed for standard abal variable ";
			mptr[12]="declaration syntax.       ";
			return(visual_online_help(mptr,13));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MaskPage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This tab page gives access to the data mask generation controls for ";
			mptr[1]=" this data file. It allows the generation of a forms model component ";
			mptr[2]=" providing the various fields and push buttons required for the complete ";
			mptr[3]="management of this type of database file.       ";
			return(visual_online_help(mptr,4));
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

private int StubName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "Here you must specify the filename stub, without extensions, to be ";
			mptr[1]="used for the xml ressource filename to which the mask will be generated. ";
			mptr[2]="This field will also be used for the construction of the production ";
			mptr[3]="target filename of the forms model.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditBase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The database ressource file  may be opened for inspection  activetool the ";
			mptr[1]="standard editor by pressing on this button.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ViewList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The database ressource file  may be opened for inspection  activetool the ";
			mptr[1]="standard editor by pressing on this button.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int BaseFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Here you must specify the filename of the data base ressource file ";
			mptr[1]="to be imported or exported.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FormName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Here you must specify the filename of the data base ressource file ";
			mptr[1]="to be imported or exported.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ListName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Here you must specify the filename of the data base ressource file ";
			mptr[1]="to be imported or exported.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EditFile_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The database ressource file  may be opened for inspection  activetool the ";
			mptr[1]="standard editor by pressing on this button.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Title_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field requires the title of the forms model, displayed in ";
			mptr[1]="the form window, to be specified.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Language_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This control allows selection of the production packaging required ";
			mptr[1]="for the  generation of the mask model. You may chosse one of the following ";
			mptr[2]="production packages  ";
			mptr[3]=" ";
			mptr[4]="  ";
			mptr[5]=" ";
			mptr[6]=" - Program ";
			mptr[7]=" - Module ";
			mptr[8]=" - Overlay ";
			mptr[9]=" - Inclusion ";
			mptr[10]="  ";
			mptr[11]=" ";
			mptr[12]="   ";
			return(visual_online_help(mptr,13));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PageItems_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "For database file with very many record member fields, it will be ";
			mptr[1]="necessary to indicate the number of items required per page by means ";
			mptr[2]="of this edit control. A tab page type forms model will result with ";
			mptr[3]="up this number of items per page.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ListLines_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" Here you may specify the height of the list component in terms of ";
			mptr[3]="the number  of lines of data to be displayed. This value does not ";
			mptr[4]="include the title line.  ";
			mptr[5]=" ";
			mptr[6]="   ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int MaxColumn_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" The value provided by this edit field will be used to limit the maximum ";
			mptr[3]="width of individual list columns.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GenerateMask_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "Press on this button when you are ready to generate the database mask. ";
			mptr[1]="A forms ressource file will be created with all the widgets required ";
			mptr[2]="for the management of the database file. Once generation is complete ";
			mptr[3]="the forms model will be loaded and appended to the  current project ";
			mptr[4]="model.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GeneratePage_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "Press on this button when you are ready to generate the database mask. ";
			mptr[1]="A forms ressource file will be created with all the widgets required ";
			mptr[2]="for the management of the database file. Once generation is complete ";
			mptr[3]="the forms model will be loaded and appended to the  current project ";
			mptr[4]="model.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int GenerateList_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "Press on this button when you are ready to generate the database file ";
			mptr[1]="list. Once generation is complete the forms model will be loaded and ";
			mptr[2]="appended to the  current project model.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImportBase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "By pressing on this button the database manager will  load all database ";
			mptr[1]="records from the filename identified by the database  ressource filename ";
			mptr[2]="field.  ";
			mptr[3]=" ";
			mptr[4]="File descriptions loaded in this way will be appended to the current ";
			mptr[5]="database.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ExportBase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "By pressing on this button the current contents of the database manager ";
			mptr[1]="will  be saved to the filename identified by the database ressource ";
			mptr[2]="filename field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ListBase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing on this button the entire database contents will be listed ";
			mptr[1]="to produce the html document defined by the string value of the ListName data input field for printing or inspection.    ";
			return(visual_online_help(mptr,2));
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

private int NationalHelptext_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This push button gives access to the National Language Help Texts ";
			mptr[1]="dialog box for consultation and modification of the different national ";
			mptr[2]="help texts for the current database file. Information provided in ";
			mptr[3]="this way will be generated to the database list document for the current ";
			mptr[4]="national language.     ";
			return(visual_online_help(mptr,5));
			}
			break;
		case 1 : 
			{
			char * mptr[2];
			mptr[0] = "Presser ce bouton pour acceder a la boite de dialog de l'editeur des ";
			mptr[1]="textes d'aide en ligne multinationales.    ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ExportForm_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "By pressing on this button the current contents of the database manager ";
			mptr[1]="will  be saved to the filename identified by the database ressource ";
			mptr[2]="filename field.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DeleteBase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "By pressing on this button the current contents of the database manager ";
			mptr[1]="will  be reset and all file structure records will be removed.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3333action(struct old_database_editor_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			old_database_editor_hide(_Context);

		_Context->x_Auto3333 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3333 < 0) { _Context->x_Auto3333=0; }
		_Context->y_Auto3333 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3333 < 0) { _Context->y_Auto3333=0; }
			old_database_editor_show(_Context);

		visual_thaw(_Context->x_Auto3333,_Context->y_Auto3333,790,590);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_FileList_event(struct old_database_editor_context * _Context) {
	int l;
	struct file_control*fptr;
	l=_Context->value_FileList;
	on_FileList_show(_Context);
	if(l>0){
	l+=_Context->value_ScrollBar;
	l=sort_item_FileList(_Context,l);
	if((fptr=locate_file(_Context, l))!=(struct file_control*)0){
	FileManager->current=fptr;
	if(visual_event(2)==_MIMO_RIGHT){
	while((visual_getch()!=256)
	&&(visual_event(1)!=32));
		/* FilePage */
	old_database_editor_losefocus(_Context);
	_Context->page_number = 2;
	old_database_editor_show(_Context);
	_Context->focus_item=8;
;
	}
	}
	}
	return(-1);
}
private int on_ScrollBar_event(struct old_database_editor_context * _Context) {
	on_FileList_show(_Context);
	return(-1);
}

private int on_ScrollBar_action(struct old_database_editor_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3333+90+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_ScrollBar -= 1;
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
		(void) on_ScrollBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3333+90+450-20) ) {
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
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_ScrollBar;
		_Context->value_ScrollBar = (((visual_event(6) - (_Context->y_Auto3333+90+20)) * _Context->max_ScrollBar) / (450 - (2 * 20)));
		if (_Context->value_ScrollBar < 0) 
			_Context->value_ScrollBar = 0;
		else if (_Context->value_ScrollBar > (_Context->max_ScrollBar-_Context->limit_ScrollBar)) 
			_Context->value_ScrollBar = (_Context->max_ScrollBar-_Context->limit_ScrollBar);
		if (_Context->value_ScrollBar != aty) {
		(void) on_ScrollBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
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
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
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
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+90,20,450,vfh[1],27,28,_Context->value_ScrollBar,_Context->limit_ScrollBar,_Context->max_ScrollBar,259);

	return(1);
}
private int on_CopyFile_event(struct old_database_editor_context * _Context) {
	int l;
	struct file_control*fptr;
	l=_Context->value_FileList;
	if(l>0){
	l+=_Context->value_ScrollBar;
	l=sort_item_FileList(_Context,l);
	if((fptr=locate_file(_Context, l))!=(struct file_control*)0)
	BaseManager.CopyFile=fptr;
	else BaseManager.CopyFile=(struct file_control*)0;
	on_PasteFile_show(_Context);
	}
	return(-1);
}
private int on_DeleteFile_event(struct old_database_editor_context * _Context) {
	int l;
	struct file_control*fptr;
	l=_Context->value_FileList;
	if(l>0){
	l+=_Context->value_ScrollBar;
	l=sort_item_FileList(_Context,l);
	if((fptr=locate_file(_Context, l))!=(struct file_control*)0){
	if(!(file_control_users(fptr)))
	drop_file_control(_Context, fptr);
	else database_delete_failure(fptr->classname);
		old_database_editor_show(_Context);
;
	}
	}
	return(-1);
}
private int on_PasteFile_event(struct old_database_editor_context * _Context) {
	int l;
	if(BaseManager.CopyFile){
	if(visual_event(1)==_MIMO_UP){
	copy_file_control(_Context);
	}
	}
		/* CopyFile */
	/* ListPage */
	old_database_editor_losefocus(_Context);
	_Context->page_number = 1;
	old_database_editor_show(_Context);
	_Context->focus_item=2;
	old_database_editor_show(_Context);
	_Context->focus_item=5;
;
	return(-1);
}
private int on_Auto3342_event(struct old_database_editor_context * _Context) {
	adjust_members(_Context, 2);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3343_event(struct old_database_editor_context * _Context) {
	adjust_members(_Context, 1);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3344_event(struct old_database_editor_context * _Context) {
	adjust_members(_Context, 0);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_Auto3345_event(struct old_database_editor_context * _Context) {
	adjust_members(_Context, 3);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_Accept_event(struct old_database_editor_context * _Context) {
	return(13);
	return(-1);
}
private int on_FileUsers_event(struct old_database_editor_context * _Context) {
		old_database_editor_hide(_Context);
;
	locate_file_instance(_Context->buffer_ClassName,255);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_IndexMembers_event(struct old_database_editor_context * _Context) {
	int i;
	int l;
	struct data_control*dptr;
	if((!(FileManager->current))
	||(!(dptr=FileManager->current->payload)))
	return(-1);
	switch(_Context->column_IndexMembers){
	case 6:
	if(visual_event(1)==_MIMO_UP){
	l=_Context->value_IndexMembers;
	if((i=((l-1)+_Context->value_IndexBar))>=dptr->indexfields)
	break;
	else if(dptr->special[i]&1)
	dptr->special[i]&=~1;
	else dptr->special[i]|=1;
	}
	_Context->column_IndexMembers=5;
	break;
	case 7:
	if(visual_event(1)==_MIMO_UP){
	l=_Context->value_IndexMembers;
	if((i=((l-1)+_Context->value_IndexBar))>=dptr->indexfields)
	break;
	else if(dptr->special[i]&2)
	dptr->special[i]&=~2;
	else dptr->special[i]|=2;
	}
	_Context->column_IndexMembers=5;
	break;
	}
	on_IndexMembers_show(_Context);
	return(-1);
}
private int on_IndexBar_event(struct old_database_editor_context * _Context) {
	on_IndexMembers_show(_Context);
	return(-1);
}

private int on_IndexBar_action(struct old_database_editor_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3333+180+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_IndexBar -= 1;
		if (_Context->value_IndexBar < 0) 
			_Context->value_IndexBar = 0;
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3333+180+90-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_IndexBar += 1;
		if (!(_Context->max_IndexBar))
			_Context->value_IndexBar = 0;
		else if ((_Context->max_IndexBar < _Context->limit_IndexBar) 
		&& (_Context->value_IndexBar >= _Context->max_IndexBar)) 
			_Context->value_IndexBar = (_Context->max_IndexBar-1);
		else if (_Context->value_IndexBar > (_Context->max_IndexBar-_Context->limit_IndexBar)) 
			_Context->value_IndexBar = (_Context->max_IndexBar-_Context->limit_IndexBar);
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_IndexBar;
		_Context->value_IndexBar = (((visual_event(6) - (_Context->y_Auto3333+180+20)) * _Context->max_IndexBar) / (90 - (2 * 20)));
		if (_Context->value_IndexBar < 0) 
			_Context->value_IndexBar = 0;
		else if (_Context->value_IndexBar > (_Context->max_IndexBar-_Context->limit_IndexBar)) 
			_Context->value_IndexBar = (_Context->max_IndexBar-_Context->limit_IndexBar);
		if (_Context->value_IndexBar != aty) {
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
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
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_IndexBar += (_Context->limit_IndexBar/2);
			if (!(_Context->max_IndexBar))
				_Context->value_IndexBar = 0;
			else if ((_Context->max_IndexBar < _Context->limit_IndexBar) 
			&& (_Context->value_IndexBar >= _Context->max_IndexBar)) 
				_Context->value_IndexBar = (_Context->max_IndexBar-1);
			else if (_Context->value_IndexBar > (_Context->max_IndexBar-_Context->limit_IndexBar)) 
				_Context->value_IndexBar = (_Context->max_IndexBar-_Context->limit_IndexBar);
		(void) on_IndexBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+180,20,90,vfh[1],0,0,_Context->value_IndexBar,_Context->limit_IndexBar,_Context->max_IndexBar,259);

	return(1);
}
private int on_DataMembers_event(struct old_database_editor_context * _Context) {
	int i;
	int l;
	struct data_control*dptr;
	if((!(FileManager->current))
	||(!(dptr=FileManager->current->payload)))
	return(-1);
	switch(_Context->column_DataMembers){
	case 6:
	if(visual_event(1)==_MIMO_UP){
	l=_Context->value_DataMembers;
	if((i=((l-1)+_Context->value_DataBar))>=dptr->datafields)
	break;
	else if(dptr->special[i+dptr->indexfields]&1)
	dptr->special[i+dptr->indexfields]&=~1;
	else dptr->special[i+dptr->indexfields]|=1;
	}
	_Context->column_DataMembers=5;
	break;
	case 7:
	if(visual_event(1)==_MIMO_UP){
	l=_Context->value_DataMembers;
	if((i=((l-1)+_Context->value_DataBar))>=dptr->datafields)
	break;
	else if(dptr->special[i+dptr->indexfields]&2)
	dptr->special[i+dptr->indexfields]&=~2;
	else dptr->special[i+dptr->indexfields]|=2;
	}
	_Context->column_DataMembers=5;
	break;
	}
	on_DataMembers_show(_Context);
	return(-1);
}
private int on_DataBar_event(struct old_database_editor_context * _Context) {
	on_DataMembers_show(_Context);
	return(-1);
}

private int on_DataBar_action(struct old_database_editor_context * _Context) {
	int status;
	int aty=visual_event(6);
	int toy=visual_event(6);
	if ( visual_event(1) !=_MIMO_DOWN) { return(0); }
	if ( visual_event(6) < (_Context->y_Auto3333+280+20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_DataBar -= 1;
		if (_Context->value_DataBar < 0) 
			_Context->value_DataBar = 0;
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
		return(-1);
		}
	if ( visual_event(6) > (_Context->y_Auto3333+280+280-20) ) {
		do { while( visual_getch() != 256); } while ( visual_event(1)  != _MIMO_UP );
		_Context->value_DataBar += 1;
		if (!(_Context->max_DataBar))
			_Context->value_DataBar = 0;
		else if ((_Context->max_DataBar < _Context->limit_DataBar) 
		&& (_Context->value_DataBar >= _Context->max_DataBar)) 
			_Context->value_DataBar = (_Context->max_DataBar-1);
		else if (_Context->value_DataBar > (_Context->max_DataBar-_Context->limit_DataBar)) 
			_Context->value_DataBar = (_Context->max_DataBar-_Context->limit_DataBar);
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
		return(-1);
		}
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);

	do {
		while(visual_getch() != 256);
		switch( visual_event(2) ) {
		case _MIMO_LEFT  :
		case _MIMO_RIGHT :
		aty = _Context->value_DataBar;
		_Context->value_DataBar = (((visual_event(6) - (_Context->y_Auto3333+280+20)) * _Context->max_DataBar) / (280 - (2 * 20)));
		if (_Context->value_DataBar < 0) 
			_Context->value_DataBar = 0;
		else if (_Context->value_DataBar > (_Context->max_DataBar-_Context->limit_DataBar)) 
			_Context->value_DataBar = (_Context->max_DataBar-_Context->limit_DataBar);
		if (_Context->value_DataBar != aty) {
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
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
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
			break;
		case _MIMO_WHEELDOWN :
			_Context->value_DataBar += (_Context->limit_DataBar/2);
			if (!(_Context->max_DataBar))
				_Context->value_DataBar = 0;
			else if ((_Context->max_DataBar < _Context->limit_DataBar) 
			&& (_Context->value_DataBar >= _Context->max_DataBar)) 
				_Context->value_DataBar = (_Context->max_DataBar-1);
			else if (_Context->value_DataBar > (_Context->max_DataBar-_Context->limit_DataBar)) 
				_Context->value_DataBar = (_Context->max_DataBar-_Context->limit_DataBar);
		(void) on_DataBar_event(_Context);
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);
			break;
		}
	visual_scrollbar(_Context->x_Auto3333+740,_Context->y_Auto3333+280,20,280,vfh[1],0,0,_Context->value_DataBar,_Context->limit_DataBar,_Context->max_DataBar,259);

	return(1);
}
private int on_EditBase_event(struct old_database_editor_context * _Context) {
		old_database_editor_hide(_Context);
;
	standard_text_editor(_Context->buffer_BaseFile,255);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_ViewList_event(struct old_database_editor_context * _Context) {
		old_database_editor_hide(_Context);
;
	use_navigator(_Context->buffer_ListName,255);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_EditFile_event(struct old_database_editor_context * _Context) {
		old_database_editor_hide(_Context);
;
	standard_text_editor(_Context->buffer_StubName,255);
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_GenerateMask_event(struct old_database_editor_context * _Context) {
	int result;
	int pitems=0;
	int i;
	struct data_control*dptr;
	char*pptr;
	if((!(FileManager->current))
	||(!(dptr=FileManager->current->payload)))
	return(-1);
	for(pptr=_Context->buffer_PageItems,i=0;i<7;i++){
	if((*(pptr+i)>='0')&&(*(pptr+i)<='9'))
	pitems=((pitems*10)+(*(pptr+i)-'0'));
	else break;
	}
	result=generate_data_mask(FileManager->current,&_Context->buffer_StubName,255,&_Context->buffer_Title,255,_Context->value_Language,pitems);
		old_database_editor_hide(_Context);
;
	draw_console();
	return(result);
	return(-1);
}
private int on_GeneratePage_event(struct old_database_editor_context * _Context) {
	int result;
	int pitems=0;
	int litems=0;
	int i;
	struct data_control*dptr;
	char*pptr;
	if((!(FileManager->current))
	||(!(dptr=FileManager->current->payload)))
	return(-1);
	for(pptr=_Context->buffer_PageItems,i=0;i<7;i++){
	if((*(pptr+i)>='0')&&(*(pptr+i)<='9'))
	pitems=((pitems*10)+(*(pptr+i)-'0'));
	else break;
	}
	result=generate_data_page(FileManager->current,&_Context->buffer_StubName,255,&_Context->buffer_Title,255,_Context->value_Language,pitems);
		old_database_editor_hide(_Context);
;
	draw_console();
	return(result);
	return(-1);
}
private int on_GenerateList_event(struct old_database_editor_context * _Context) {
	int result;
	int pitems=0;
	int litems=0;
	int maxcol=0;
	int i;
	struct data_control*dptr;
	char*pptr;
	if((!(FileManager->current))
	||(!(dptr=FileManager->current->payload)))
	return(-1);
	for(pptr=_Context->buffer_ListLines,i=0;i<7;i++){
	if((*(pptr+i)>='0')&&(*(pptr+i)<='9'))
	pitems=((pitems*10)+(*(pptr+i)-'0'));
	else break;
	}
	for(pptr=_Context->buffer_ListColumns,i=0;i<7;i++){
	if((*(pptr+i)>='0')&&(*(pptr+i)<='9'))
	litems=((litems*10)+(*(pptr+i)-'0'));
	else break;
	}
	for(pptr=_Context->buffer_MaxColumn,i=0;i<7;i++){
	if((*(pptr+i)>='0')&&(*(pptr+i)<='9'))
	maxcol=((maxcol*10)+(*(pptr+i)-'0'));
	else break;
	}
	result=generate_data_list(FileManager->current,&_Context->buffer_StubName,255,&_Context->buffer_Title,255,_Context->value_Language,pitems,litems,maxcol);
		old_database_editor_hide(_Context);
;
	draw_console();
	return(result);
	return(-1);
}
private int on_ImportBase_event(struct old_database_editor_context * _Context) {
	import_database(_Context->buffer_BaseFile,255);
	return(-1);
}
private int on_ExportBase_event(struct old_database_editor_context * _Context) {
	export_database(_Context->buffer_BaseFile,255);
	return(-1);
}
private int on_ListBase_event(struct old_database_editor_context * _Context) {
	list_database(_Context->buffer_ListName,255);
	return(-1);
}
private int on_NationalHelptext_event(struct old_database_editor_context * _Context) {
	if(FileManager->current){
		old_database_editor_hide(_Context);
;
	edit_database_helptext(FileManager->current);
		old_database_editor_show(_Context);
;
	}
	return(-1);
}
private int on_ExportForm_event(struct old_database_editor_context * _Context) {
	Xml_form_data_collection(_Context->buffer_BaseFile,255,
	_Context->buffer_FormName,255);
	return(-1);
}
private int on_DeleteBase_event(struct old_database_editor_context * _Context) {
	reset_database(_Context);
	return(-1);
}


public	int	old_database_editor_event(
struct old_database_editor_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_ListPage == mb ) return(2);
		if (_Context->trigger_CopyFile == mb ) return(5);
		if (_Context->trigger_DeleteFile == mb ) return(6);
		if (_Context->trigger_PasteFile == mb ) return(7);
		if (_Context->trigger_FilePage == mb ) return(8);
		if (_Context->trigger_Auto3342 == mb ) return(15);
		if (_Context->trigger_Auto3343 == mb ) return(17);
		if (_Context->trigger_RecordType == mb ) return(18);
		if (_Context->trigger_MarkerUseage == mb ) return(19);
		if (_Context->trigger_Modext == mb ) return(20);
		if (_Context->trigger_Auto3344 == mb ) return(22);
		if (_Context->trigger_Auto3345 == mb ) return(24);
		if (_Context->trigger_Accept == mb ) return(25);
		if (_Context->trigger_FileUsers == mb ) return(26);
		if (_Context->trigger_MaskPage == mb ) return(32);
		if (_Context->trigger_EditBase == mb ) return(34);
		if (_Context->trigger_ViewList == mb ) return(35);
		if (_Context->trigger_EditFile == mb ) return(39);
		if (_Context->trigger_GenerateMask == mb ) return(46);
		if (_Context->trigger_GeneratePage == mb ) return(47);
		if (_Context->trigger_GenerateList == mb ) return(48);
		if (_Context->trigger_ImportBase == mb ) return(49);
		if (_Context->trigger_ExportBase == mb ) return(50);
		if (_Context->trigger_ListBase == mb ) return(51);
		if (_Context->trigger_NationalHelptext == mb ) return(52);
		if (_Context->trigger_ExportForm == mb ) return(53);
		if (_Context->trigger_DeleteBase == mb ) return(54);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3033)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3333+769) )  
	&&  (my >= (_Context->y_Auto3333+4) )  
	&&  (mx <= (_Context->x_Auto3333+786) )  
	&&  (my <= (_Context->y_Auto3333+20) )) {
		return(1);	/* Auto3333 */

		}
	if ((mx >= (_Context->x_Auto3333+753) )  
	&&  (my >= (_Context->y_Auto3333+4) )  
	&&  (mx <= (_Context->x_Auto3333+770) )  
	&&  (my <= (_Context->y_Auto3333+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vfile.htm");
			};
		return(-1);	/* Auto3333 */

		}
	if ((mx >= (_Context->x_Auto3333+737) )  
	&&  (my >= (_Context->y_Auto3333+4) )  
	&&  (mx <= (_Context->x_Auto3333+754) )  
	&&  (my <= (_Context->y_Auto3333+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		old_database_editor_show(_Context);
		return(-1);	/* Auto3333 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3333+4) )  
		&&  (my >= (_Context->y_Auto3333+4) )  
		&&  (mx <= (_Context->x_Auto3333+722) )  
		&&  (my <= (_Context->y_Auto3333+20) )) {
			return( Auto3333action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3333+20+0) ) 
		&&  ( my >= (_Context->y_Auto3333+40) ) 
		&&  ( mx <= (_Context->x_Auto3333+20+58) ) 
		&&  ( my <= (_Context->y_Auto3333+40+24))) {
			return(2); /* ListPage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3333+30) ) 
		&&  ( my >= (_Context->y_Auto3333+90) ) 
		&&  ( mx <= (_Context->x_Auto3333+30+710) ) 
		&&  ( my <= (_Context->y_Auto3333+90+450))) {
			if ((_Context->value_FileList = ((visual_event(6) - (_Context->y_Auto3333+90)) / 16)) < 1)
				_Context->value_FileList=0;
else if (_Context->value_FileList > 26 )
				_Context->value_FileList=26;
			if ( _Context->value_FileList > 0 ) { _Context->row_FileList = &_Context->buffer_FileList[(_Context->value_FileList-1)][0]; } 
			_Context->column_FileList = (visual_event(7) - (_Context->x_Auto3333+30));
			if ( _Context->column_FileList < 264 ) {
				_Context->column_FileList = 1;
				}
			else if ( _Context->column_FileList < 528 ) {
				_Context->column_FileList = 2;
				}
			else if ( _Context->column_FileList < 616 ) {
				_Context->column_FileList = 3;
				}
			else if ( _Context->column_FileList < 704 ) {
				_Context->column_FileList = 4;
				}
			if ((!(_Context->value_FileList)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_FileList==_Context->column_FileList) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_FileList=-_Context->column_FileList;	/* alors tri décroissant */
				else
					_Context->formsort_FileList=_Context->column_FileList; };	/* sinon tri croissant */
			return(3); /* FileList */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3333+740) ) 
		&&  ( my >= (_Context->y_Auto3333+90) ) 
		&&  ( mx <= (_Context->x_Auto3333+740+20) ) 
		&&  ( my <= (_Context->y_Auto3333+90+450))) {
			return(4); /* ScrollBar */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3333+30) ) 
		&&  ( my >= (_Context->y_Auto3333+540) ) 
		&&  ( mx <= (_Context->x_Auto3333+30+208) ) 
		&&  ( my <= (_Context->y_Auto3333+540+30))) {
			return(5); /* CopyFile */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3333+530) ) 
		&&  ( my >= (_Context->y_Auto3333+540) ) 
		&&  ( mx <= (_Context->x_Auto3333+530+208) ) 
		&&  ( my <= (_Context->y_Auto3333+540+30))) {
			return(6); /* DeleteFile */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3333+280) ) 
		&&  ( my >= (_Context->y_Auto3333+540) ) 
		&&  ( mx <= (_Context->x_Auto3333+280+208) ) 
		&&  ( my <= (_Context->y_Auto3333+540+30))) {
			return(7); /* PasteFile */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3333+20+59) ) 
		&&  ( my >= (_Context->y_Auto3333+40) ) 
		&&  ( mx <= (_Context->x_Auto3333+20+127) ) 
		&&  ( my <= (_Context->y_Auto3333+40+24))) {
			return(8); /* FilePage */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+110) ) 
		&&  ( my >= (_Context->y_Auto3333+80) ) 
		&&  ( mx <= (_Context->x_Auto3333+110+328) ) 
		&&  ( my <= (_Context->y_Auto3333+80+16))) {
			return(9); /* ClassName */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+110) ) 
		&&  ( my >= (_Context->y_Auto3333+100) ) 
		&&  ( mx <= (_Context->x_Auto3333+110+328) ) 
		&&  ( my <= (_Context->y_Auto3333+100+16))) {
			return(10); /* Instance */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+110) ) 
		&&  ( my >= (_Context->y_Auto3333+120) ) 
		&&  ( mx <= (_Context->x_Auto3333+110+328) ) 
		&&  ( my <= (_Context->y_Auto3333+120+16))) {
			return(11); /* Filename */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+110+0) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+110+96) ) 
		&&  ( my <= (_Context->y_Auto3333+140+16))) {
			return(12); /* FileType */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+260+0) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+260+48) ) 
		&&  ( my <= (_Context->y_Auto3333+140+16))) {
			return(13); /* IndexType */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+580) ) 
		&&  ( my >= (_Context->y_Auto3333+100) ) 
		&&  ( mx <= (_Context->x_Auto3333+580+64) ) 
		&&  ( my <= (_Context->y_Auto3333+100+16))) {
			return(14); /* IndexSize */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+660) ) 
		&&  ( my >= (_Context->y_Auto3333+120) ) 
		&&  ( mx <= (_Context->x_Auto3333+660+16) ) 
		&&  ( my <= (_Context->y_Auto3333+120+18))) {
			return(15); /* Auto3342 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+680) ) 
		&&  ( my >= (_Context->y_Auto3333+100) ) 
		&&  ( mx <= (_Context->x_Auto3333+680+40) ) 
		&&  ( my <= (_Context->y_Auto3333+100+16))) {
			return(16); /* NbIndex */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+730) ) 
		&&  ( my >= (_Context->y_Auto3333+100) ) 
		&&  ( mx <= (_Context->x_Auto3333+730+16) ) 
		&&  ( my <= (_Context->y_Auto3333+100+18))) {
			return(17); /* Auto3343 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+312) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+312+30) ) 
		&&  ( my <= (_Context->y_Auto3333+140+22))) {
			return(18); /* RecordType */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+410) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+410+30) ) 
		&&  ( my <= (_Context->y_Auto3333+140+22))) {
			return(19); /* MarkerUseage */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+344) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+344+65) ) 
		&&  ( my <= (_Context->y_Auto3333+140+22))) {
			return(20); /* Modext */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+580) ) 
		&&  ( my >= (_Context->y_Auto3333+120) ) 
		&&  ( mx <= (_Context->x_Auto3333+580+64) ) 
		&&  ( my <= (_Context->y_Auto3333+120+16))) {
			return(21); /* RecordSize */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+660) ) 
		&&  ( my >= (_Context->y_Auto3333+100) ) 
		&&  ( mx <= (_Context->x_Auto3333+660+16) ) 
		&&  ( my <= (_Context->y_Auto3333+100+18))) {
			return(22); /* Auto3344 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+680) ) 
		&&  ( my >= (_Context->y_Auto3333+120) ) 
		&&  ( mx <= (_Context->x_Auto3333+680+40) ) 
		&&  ( my <= (_Context->y_Auto3333+120+16))) {
			return(23); /* NbData */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+730) ) 
		&&  ( my >= (_Context->y_Auto3333+120) ) 
		&&  ( mx <= (_Context->x_Auto3333+730+16) ) 
		&&  ( my <= (_Context->y_Auto3333+120+18))) {
			return(24); /* Auto3345 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+580) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+580+97) ) 
		&&  ( my <= (_Context->y_Auto3333+140+27))) {
			return(25); /* Accept */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+680) ) 
		&&  ( my >= (_Context->y_Auto3333+139) ) 
		&&  ( mx <= (_Context->x_Auto3333+680+66) ) 
		&&  ( my <= (_Context->y_Auto3333+139+28))) {
			return(26); /* FileUsers */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+40) ) 
		&&  ( my >= (_Context->y_Auto3333+180) ) 
		&&  ( mx <= (_Context->x_Auto3333+40+700) ) 
		&&  ( my <= (_Context->y_Auto3333+180+90))) {
			if ((_Context->value_IndexMembers = ((visual_event(6) - (_Context->y_Auto3333+180)) / 16)) < 1)
				_Context->value_IndexMembers=0;
else if (_Context->value_IndexMembers > 4 )
				_Context->value_IndexMembers=4;
			if ( _Context->value_IndexMembers > 0 ) { _Context->row_IndexMembers = &_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0]; } 
			_Context->column_IndexMembers = (visual_event(7) - (_Context->x_Auto3333+40));
			if ( _Context->column_IndexMembers < 448 ) {
				_Context->column_IndexMembers = 1;
				}
			else if ( _Context->column_IndexMembers < 520 ) {
				_Context->column_IndexMembers = 2;
				}
			else if ( _Context->column_IndexMembers < 568 ) {
				_Context->column_IndexMembers = 3;
				}
			else if ( _Context->column_IndexMembers < 616 ) {
				_Context->column_IndexMembers = 4;
				}
			else if ( _Context->column_IndexMembers < 664 ) {
				_Context->column_IndexMembers = 5;
				}
			else if ( _Context->column_IndexMembers < 680 ) {
				_Context->column_IndexMembers = 6;
				}
			else if ( _Context->column_IndexMembers < 696 ) {
				_Context->column_IndexMembers = 7;
				}
			if ((!(_Context->value_IndexMembers)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_IndexMembers==_Context->column_IndexMembers) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_IndexMembers=-_Context->column_IndexMembers;	/* alors tri décroissant */
				else
					_Context->formsort_IndexMembers=_Context->column_IndexMembers; };	/* sinon tri croissant */
			return(27); /* IndexMembers */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+740) ) 
		&&  ( my >= (_Context->y_Auto3333+180) ) 
		&&  ( mx <= (_Context->x_Auto3333+740+20) ) 
		&&  ( my <= (_Context->y_Auto3333+180+90))) {
			return(28); /* IndexBar */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+40) ) 
		&&  ( my >= (_Context->y_Auto3333+280) ) 
		&&  ( mx <= (_Context->x_Auto3333+40+700) ) 
		&&  ( my <= (_Context->y_Auto3333+280+280))) {
			if ((_Context->value_DataMembers = ((visual_event(6) - (_Context->y_Auto3333+280)) / 16)) < 1)
				_Context->value_DataMembers=0;
else if (_Context->value_DataMembers > 16 )
				_Context->value_DataMembers=16;
			if ( _Context->value_DataMembers > 0 ) { _Context->row_DataMembers = &_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0]; } 
			_Context->column_DataMembers = (visual_event(7) - (_Context->x_Auto3333+40));
			if ( _Context->column_DataMembers < 448 ) {
				_Context->column_DataMembers = 1;
				}
			else if ( _Context->column_DataMembers < 520 ) {
				_Context->column_DataMembers = 2;
				}
			else if ( _Context->column_DataMembers < 568 ) {
				_Context->column_DataMembers = 3;
				}
			else if ( _Context->column_DataMembers < 616 ) {
				_Context->column_DataMembers = 4;
				}
			else if ( _Context->column_DataMembers < 664 ) {
				_Context->column_DataMembers = 5;
				}
			else if ( _Context->column_DataMembers < 680 ) {
				_Context->column_DataMembers = 6;
				}
			else if ( _Context->column_DataMembers < 696 ) {
				_Context->column_DataMembers = 7;
				}
			if ((!(_Context->value_DataMembers)) && (visual_event(1)==_MIMO_DOWN)) {	/* si clic sur titre */
				if (_Context->formsort_DataMembers==_Context->column_DataMembers) /* si colonne choisie concerne déjà le tri */
					_Context->formsort_DataMembers=-_Context->column_DataMembers;	/* alors tri décroissant */
				else
					_Context->formsort_DataMembers=_Context->column_DataMembers; };	/* sinon tri croissant */
			return(29); /* DataMembers */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3333+740) ) 
		&&  ( my >= (_Context->y_Auto3333+280) ) 
		&&  ( mx <= (_Context->x_Auto3333+740+20) ) 
		&&  ( my <= (_Context->y_Auto3333+280+280))) {
			return(30); /* DataBar */
			}
		}
	if (_Context->page_number == 2 ) {
		if ((mx >= _Context->x_TypeSelect ) 
		&&  (my >= _Context->y_TypeSelect ) 
		&&  (mx <  (_Context->x_TypeSelect+_Context->w_TypeSelect)) 
		&&  (my <  (_Context->y_TypeSelect+_Context->h_TypeSelect))) {
			return(31); /* TypeSelect */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto3333+20+128) ) 
		&&  ( my >= (_Context->y_Auto3333+40) ) 
		&&  ( mx <= (_Context->x_Auto3333+20+221) ) 
		&&  ( my <= (_Context->y_Auto3333+40+24))) {
			return(32); /* MaskPage */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+40) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+40+688) ) 
		&&  ( my <= (_Context->y_Auto3333+140+16))) {
			return(33); /* StubName */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+720) ) 
		&&  ( my >= (_Context->y_Auto3333+420) ) 
		&&  ( mx <= (_Context->x_Auto3333+720+16) ) 
		&&  ( my <= (_Context->y_Auto3333+420+16))) {
			return(34); /* EditBase */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+720) ) 
		&&  ( my >= (_Context->y_Auto3333+480) ) 
		&&  ( mx <= (_Context->x_Auto3333+720+16) ) 
		&&  ( my <= (_Context->y_Auto3333+480+16))) {
			return(35); /* ViewList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+290) ) 
		&&  ( my >= (_Context->y_Auto3333+420) ) 
		&&  ( mx <= (_Context->x_Auto3333+290+424) ) 
		&&  ( my <= (_Context->y_Auto3333+420+16))) {
			return(36); /* BaseFile */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+290) ) 
		&&  ( my >= (_Context->y_Auto3333+450) ) 
		&&  ( mx <= (_Context->x_Auto3333+290+424) ) 
		&&  ( my <= (_Context->y_Auto3333+450+16))) {
			return(37); /* FormName */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+290) ) 
		&&  ( my >= (_Context->y_Auto3333+480) ) 
		&&  ( mx <= (_Context->x_Auto3333+290+424) ) 
		&&  ( my <= (_Context->y_Auto3333+480+16))) {
			return(38); /* ListName */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+730) ) 
		&&  ( my >= (_Context->y_Auto3333+140) ) 
		&&  ( mx <= (_Context->x_Auto3333+730+16) ) 
		&&  ( my <= (_Context->y_Auto3333+140+16))) {
			return(39); /* EditFile */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+40) ) 
		&&  ( my >= (_Context->y_Auto3333+180) ) 
		&&  ( mx <= (_Context->x_Auto3333+40+472) ) 
		&&  ( my <= (_Context->y_Auto3333+180+16))) {
			return(40); /* Title */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+520+0) ) 
		&&  ( my >= (_Context->y_Auto3333+180) ) 
		&&  ( mx <= (_Context->x_Auto3333+520+230) ) 
		&&  ( my <= (_Context->y_Auto3333+180+16))) {
			return(41); /* Language */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+200) ) 
		&&  ( my >= (_Context->y_Auto3333+240) ) 
		&&  ( mx <= (_Context->x_Auto3333+200+56) ) 
		&&  ( my <= (_Context->y_Auto3333+240+16))) {
			return(42); /* PageItems */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+440) ) 
		&&  ( my >= (_Context->y_Auto3333+240) ) 
		&&  ( mx <= (_Context->x_Auto3333+440+56) ) 
		&&  ( my <= (_Context->y_Auto3333+240+16))) {
			return(43); /* ListLines */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+440) ) 
		&&  ( my >= (_Context->y_Auto3333+260) ) 
		&&  ( mx <= (_Context->x_Auto3333+440+56) ) 
		&&  ( my <= (_Context->y_Auto3333+260+16))) {
			return(44); /* ListColumns */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+440) ) 
		&&  ( my >= (_Context->y_Auto3333+280) ) 
		&&  ( mx <= (_Context->x_Auto3333+440+56) ) 
		&&  ( my <= (_Context->y_Auto3333+280+16))) {
			return(45); /* MaxColumn */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+50) ) 
		&&  ( my >= (_Context->y_Auto3333+310) ) 
		&&  ( mx <= (_Context->x_Auto3333+50+210) ) 
		&&  ( my <= (_Context->y_Auto3333+310+32))) {
			return(46); /* GenerateMask */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+530) ) 
		&&  ( my >= (_Context->y_Auto3333+310) ) 
		&&  ( mx <= (_Context->x_Auto3333+530+210) ) 
		&&  ( my <= (_Context->y_Auto3333+310+32))) {
			return(47); /* GeneratePage */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+290) ) 
		&&  ( my >= (_Context->y_Auto3333+310) ) 
		&&  ( mx <= (_Context->x_Auto3333+290+210) ) 
		&&  ( my <= (_Context->y_Auto3333+310+32))) {
			return(48); /* GenerateList */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+60) ) 
		&&  ( my >= (_Context->y_Auto3333+520) ) 
		&&  ( mx <= (_Context->x_Auto3333+60+98) ) 
		&&  ( my <= (_Context->y_Auto3333+520+32))) {
			return(49); /* ImportBase */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+160) ) 
		&&  ( my >= (_Context->y_Auto3333+520) ) 
		&&  ( mx <= (_Context->x_Auto3333+160+98) ) 
		&&  ( my <= (_Context->y_Auto3333+520+32))) {
			return(50); /* ExportBase */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+560) ) 
		&&  ( my >= (_Context->y_Auto3333+520) ) 
		&&  ( mx <= (_Context->x_Auto3333+560+98) ) 
		&&  ( my <= (_Context->y_Auto3333+520+32))) {
			return(51); /* ListBase */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+680) ) 
		&&  ( my >= (_Context->y_Auto3333+510) ) 
		&&  ( mx <= (_Context->x_Auto3333+680+56) ) 
		&&  ( my <= (_Context->y_Auto3333+510+48))) {
			return(52); /* NationalHelptext */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+390) ) 
		&&  ( my >= (_Context->y_Auto3333+520) ) 
		&&  ( mx <= (_Context->x_Auto3333+390+168) ) 
		&&  ( my <= (_Context->y_Auto3333+520+32))) {
			return(53); /* ExportForm */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3333+260) ) 
		&&  ( my >= (_Context->y_Auto3333+520) ) 
		&&  ( mx <= (_Context->x_Auto3333+260+126) ) 
		&&  ( my <= (_Context->y_Auto3333+520+32))) {
			return(54); /* DeleteBase */
			}
		}

	return(-1);
}
private int on_FileList_losefocus(struct old_database_editor_context * _Context) {
	int l;
	struct file_control*fptr;
	l=_Context->value_FileList;
	if(l>0){
	l+=_Context->value_ScrollBar;
	l=sort_item_FileList(_Context,l);
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
private int on_ClassName_losefocus(struct old_database_editor_context * _Context) {
	if(FileManager->current){
	reallocate(_Context,&FileManager->current->classname,_Context->buffer_ClassName,255);
	}
	return(-1);
}
private int on_Instance_losefocus(struct old_database_editor_context * _Context) {
	if(FileManager->current){
	reallocate(_Context,&FileManager->current->identity,_Context->buffer_Instance,255);
	}
	return(-1);
}
private int on_Filename_losefocus(struct old_database_editor_context * _Context) {
	if(FileManager->current){
	reallocate(_Context,&FileManager->current->filename,_Context->buffer_Filename,255);
	}
	return(-1);
}
private int on_FileType_losefocus(struct old_database_editor_context * _Context) {
	if(FileManager->current)
	FileManager->current->nature=_Context->value_FileType;
		old_database_editor_show(_Context);
;
	return(-1);
}
private int on_IndexType_losefocus(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	FileManager->current->payload->option&=~(_A_LEFT|_A_RIGHT);
	switch(_Context->value_IndexType){
	case 1:
	FileManager->current->payload->option|=_A_LEFT;
	break;
	case 2:
	FileManager->current->payload->option|=_A_RIGHT;
	break;
	}
	}
	return(-1);
}
private int on_IndexSize_losefocus(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	FileManager->current->payload->indexlength=convert_integer(_Context, _Context->buffer_IndexSize,8);
	}
	return(-1);
}
private int on_RecordType_losefocus(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(_Context->value_RecordType)
	FileManager->current->payload->option|=_A_BOLD;
	else FileManager->current->payload->option&=~_A_BOLD;
	}
	return(-1);
}
private int on_MarkerUseage_losefocus(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(_Context->value_MarkerUseage)
	FileManager->current->payload->option|=_A_SHADOW;
	else FileManager->current->payload->option&=~_A_SHADOW;
	}
	return(-1);
}
private int on_Modext_losefocus(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	if(_Context->value_Modext)
	FileManager->current->payload->option|=_A_LINE;
	else FileManager->current->payload->option&=~_A_LINE;
	}
	return(-1);
}
private int on_RecordSize_losefocus(struct old_database_editor_context * _Context) {
	if((FileManager->current)
	&&(FileManager->current->payload)){
	FileManager->current->payload->datalength=convert_integer(_Context, _Context->buffer_RecordSize,8);
	}
	return(-1);
}
private int on_IndexMembers_losefocus(struct old_database_editor_context * _Context) {
	struct data_control*dptr;
	int l;
	int i;
	int n;
	char*cptr;
	l=_Context->value_IndexMembers;
	if(l>0){
	if((FileManager->current!=(struct file_control*)0)
	&&((dptr=FileManager->current->payload)!=(struct data_control*)0)){
	if ( l > 0 ) { _Context->row_IndexMembers=&_Context->buffer_IndexMembers[l-1][0]; } ;
	i=((l-1)+_Context->value_IndexBar);
	if(_Context->keycode==0x000E)
	insert_database_item(dptr,i);
	else if(_Context->keycode==0x0019)
	delete_database_item(dptr,i);
	else switch(_Context->column_IndexMembers){
	case 1:/*name*/
	analyse_variable_expression(
	(_Context->row_IndexMembers+0),56,
	&dptr->type[i],&dptr->width[i],
	&dptr->first[i],&dptr->second[i],
	&dptr->decimal[i],1
	);
	#ifdef need_this_bit
	for(cptr=(_Context->row_IndexMembers+0),n=0;n<56;n++){
	switch(*(cptr+n)){
	case '#':dptr->type[i]=_ABAL_BYTE;*(cptr+n)=0;break;
	case '%':dptr->type[i]=_ABAL_WORD;*(cptr+n)=0;break;
	case ':':dptr->type[i]=_ABAL_LONG;*(cptr+n)=0;break;
	case '$':dptr->type[i]=_ABAL_STRING;*(cptr+n)=0;break;
	case '*':dptr->type[i]=_ABAL_BCD;*(cptr+n)=0;break;
	case '=':
	*(cptr+n)=0;
	dptr->width[i]=convert_integer(_Context, (_Context->row_IndexMembers+0)+(n+1),56-(n+1));
	break;
	case '(':
	*(cptr+n)=0;
	dptr->first[i]=convert_integer(_Context, (_Context->row_IndexMembers+0)+(n+1),56-(n+1));
	break;
	case ')':*(cptr+n)=' ';break;
	case ',':*(cptr+n)=0;
	dptr->second[i]=convert_integer(_Context, (_Context->row_IndexMembers+0)+(n+1),56-(n+1));
	}
	}
	#endif
	for(cptr=(_Context->row_IndexMembers+0),n=0;n<56;n++){
	if(!(*(cptr+n))){
	while(n<56){
	*(cptr+n)=' ';
	n++;
	}
	break;
	}
	}
		reallocate(_Context,
	&dptr->name[i],
	(_Context->row_IndexMembers+0),
	56);
	break;
	case 2:/*type*/
	break;
	case 3:/*length*/
	dptr->width[i]=convert_integer(_Context, (_Context->row_IndexMembers+65),6);
	if(dptr->type[i]==_ABAL_BCD){
	dptr->decimal[i]=convert_decimal(_Context, (_Context->row_IndexMembers+65),6,dptr->decimal[i]);
	}
	break;
	case 4:/*primary dimension*/
	dptr->first[i]=convert_integer(_Context, (_Context->row_IndexMembers+71),6);
	break;
	case 5:/*second dimension*/
	dptr->second[i]=convert_integer(_Context, (_Context->row_IndexMembers+77),6);
	break;
	case 6:/*special flag*/
	if(*((_Context->row_IndexMembers+83))=='!')
	dptr->special[i]|=1;
	else dptr->special[i]&=~1;
	break;
	}
	}
		old_database_editor_show(_Context);
;
	}
	return(-1);
}
private int on_DataMembers_losefocus(struct old_database_editor_context * _Context) {
	struct data_control*dptr;
	int l;
	int i;
	int n;
	char*cptr;
	l=_Context->value_DataMembers;
	if(l>0){
	if((FileManager->current!=(struct file_control*)0)
	&&((dptr=FileManager->current->payload)!=(struct data_control*)0)){
	if ( l > 0 ) { _Context->row_DataMembers=&_Context->buffer_DataMembers[l-1][0]; } ;
	i=((l-1)+_Context->value_DataBar);
	if(_Context->keycode==0x000E)
	insert_database_item(dptr,i+dptr->indexfields);
	else if(_Context->keycode==0x0019)
	delete_database_item(dptr,i+dptr->indexfields);
	else switch(_Context->column_DataMembers){
	case 1:/*name*/
	analyse_variable_expression(
	(_Context->row_DataMembers+0),56,
	&dptr->type[i+dptr->indexfields],&dptr->width[i+dptr->indexfields],
	&dptr->first[i+dptr->indexfields],&dptr->second[i+dptr->indexfields],
	&dptr->decimal[i+dptr->indexfields],1
	);
	#ifdef need_this_bit
	for(cptr=(_Context->row_DataMembers+0),n=0;n<56;n++){
	switch(*(cptr+n)){
	case '#':dptr->type[i+dptr->indexfields]=_ABAL_BYTE;*(cptr+n)=0;break;
	case '%':dptr->type[i+dptr->indexfields]=_ABAL_WORD;*(cptr+n)=0;break;
	case ':':dptr->type[i+dptr->indexfields]=_ABAL_LONG;*(cptr+n)=0;break;
	case '$':dptr->type[i+dptr->indexfields]=_ABAL_STRING;*(cptr+n)=0;break;
	case '*':dptr->type[i+dptr->indexfields]=_ABAL_BCD;*(cptr+n)=0;break;
	case '=':
	*(cptr+n)=0;
	dptr->width[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+0)+(n+1),56-(n+1));
	break;
	case '(':
	*(cptr+n)=0;
	dptr->first[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+0)+(n+1),56-(n+1));
	break;
	case ')':*(cptr+n)=' ';break;
	case ',':*(cptr+n)=0;
	dptr->second[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+0)+(n+1),56-(n+1));
	}
	}
	#endif
	for(cptr=(_Context->row_DataMembers+0),n=0;n<56;n++){
	if(!(*(cptr+n))){
	while(n<56){
	*(cptr+n)=' ';
	n++;
	}
	break;
	}
	}
	reallocate(_Context,
	&dptr->name[i+dptr->indexfields],
	(_Context->row_DataMembers+0),
	56);
	break;
	case 2:/*type*/
	break;
	case 3:/*length*/
	dptr->width[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+65),6);
	if(dptr->type[i+dptr->indexfields]==_ABAL_BCD){
	dptr->decimal[i+dptr->indexfields]=convert_decimal(_Context, (_Context->row_DataMembers+65),6,dptr->decimal[i+dptr->indexfields]);
	}
	break;
	case 4:/*primary dimension*/
	dptr->first[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+71),6);
	break;
	case 5:/*second dimension*/
	dptr->second[i+dptr->indexfields]=convert_integer(_Context, (_Context->row_DataMembers+77),6);
	break;
	case 6:/*special flag*/
	if(*((_Context->row_DataMembers+83))=='!')
	dptr->special[i+dptr->indexfields]|=1;
	else dptr->special[i+dptr->indexfields]&=~1;
	break;
	}
	}
		old_database_editor_show(_Context);
;
		}
		return(-1);
}


public	int	old_database_editor_losefocus(struct old_database_editor_context * _Context)
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
private int on_IndexMembers_getfocus(struct old_database_editor_context * _Context) {
	char wbuffer[320];
	int l;
	int i;
	struct data_control*dptr;
	if(!(dptr=FileManager->current->payload)){
		/* ClassName */
	/* FilePage */
	old_database_editor_losefocus(_Context);
	_Context->page_number = 2;
	old_database_editor_show(_Context);
	_Context->focus_item=8;
	old_database_editor_show(_Context);
	_Context->focus_item=9;
;
	return((_Context->keycode=0));
	}
	else if(!(dptr->indexfields)){
		/* ClassName */
	/* FilePage */
	old_database_editor_losefocus(_Context);
	_Context->page_number = 2;
	old_database_editor_show(_Context);
	_Context->focus_item=8;
	old_database_editor_show(_Context);
	_Context->focus_item=9;
;
	return((_Context->keycode=0));
	}
	else if(_Context->column_IndexMembers==2){
	l=_Context->value_IndexMembers;
	if((i=((l-1)+_Context->value_IndexBar))<=dptr->indexfields){
	switch(dptr->type[i]){
	case _ABAL_BYTE:_Context->value_TypeSelect=0;break;
	case _ABAL_WORD:_Context->value_TypeSelect=1;break;
	case _ABAL_BCD:_Context->value_TypeSelect=2;break;
	case _ABAL_STRING:_Context->value_TypeSelect=3;break;
	case _ABAL_LONG:_Context->value_TypeSelect=4;break;
	case _ABAL_FIELD:_Context->value_TypeSelect=5;break;
	case _ABAL_FILLER:_Context->value_TypeSelect=6;break;
	}
	}
	else _Context->value_TypeSelect=0;
	_Context->x_TypeSelect=_Context->x_Auto3333+40+(56*8);
	_Context->y_TypeSelect=_Context->y_Auto3333+180+(l*16);
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
	visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),768);
;
		_Context->keycode = visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),770);
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
	case 5:dptr->type[i]=_ABAL_FIELD;break;
	case 6:dptr->type[i]=_ABAL_FILLER;break;
	}
		visual_table(_Context->x_Auto3333+40,_Context->y_Auto3333+180,700,90,vfh[1],0,0,_Context->msg_IndexMembers[_Context->language],_Context->buffer_IndexMembers,0x4401,"($,W8,N4Z,N4Z,N4Z,W,W)");
;
	}
	}
	else{
	if(_Context->column_IndexMembers==1){
	dptr=FileManager->current->payload;
	l=_Context->value_IndexMembers;
	if((i=((l-1)+_Context->value_IndexBar))<=dptr->indexfields){
	string_print_dcl(wbuffer,"\0",
	dptr->name[i],dptr->type[i],
	dptr->width[i],
	dptr->first[i],dptr->second[i],
	dptr->special[i],dptr->decimal[i]
	);
	if ( l > 0 ) { _Context->row_IndexMembers=&_Context->buffer_IndexMembers[l-1][0]; } ;
	putstring(_Context, (_Context->row_IndexMembers+0),56,wbuffer);
	}
	}
		if (!_Context->value_IndexMembers) _Context->value_IndexMembers=1;	/* pour etre sur qu'on edite pas le titre */
	_Context->row_IndexMembers = &_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0];
	switch (_Context->column_IndexMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+2),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),440,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0],55);
	visual_text((_Context->x_Auto3333+40+2),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),440,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][0],55,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+450),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),64,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][56],8);
	visual_text((_Context->x_Auto3333+40+450),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][56],8,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+522),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][65],5);
	visual_text((_Context->x_Auto3333+40+522),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][65],5,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+570),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][71],5);
	visual_text((_Context->x_Auto3333+40+570),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][71],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+618),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][77],5);
	visual_text((_Context->x_Auto3333+40+618),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][77],5,0);
		break;
	case	0x6 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+666),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),8,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][83],1);
	visual_text((_Context->x_Auto3333+40+666),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),8,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][83],1,0);
		break;
	case	0x7 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+682),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),8,16,vfh[1],&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][85],1);
	visual_text((_Context->x_Auto3333+40+682),(_Context->y_Auto3333+180+(_Context->value_IndexMembers*16)+2),8,16,vfh[1],0,(24-((_Context->value_IndexMembers-1)&1)),&_Context->buffer_IndexMembers[(_Context->value_IndexMembers-1)][85],1,0);
		break;
		}
;
	}
	return(-1);
}
private int on_DataMembers_getfocus(struct old_database_editor_context * _Context) {
	char wbuffer[320];
	int l;
	int i;
	struct data_control*dptr;
	if(!(dptr=FileManager->current->payload)){
		/* ClassName */
	/* FilePage */
	old_database_editor_losefocus(_Context);
	_Context->page_number = 2;
	old_database_editor_show(_Context);
	_Context->focus_item=8;
	old_database_editor_show(_Context);
	_Context->focus_item=9;
;
	return((_Context->keycode=0));
	}
	else if(!(dptr->datafields)){
		/* ClassName */
	/* FilePage */
	old_database_editor_losefocus(_Context);
	_Context->page_number = 2;
	old_database_editor_show(_Context);
	_Context->focus_item=8;
	old_database_editor_show(_Context);
	_Context->focus_item=9;
;
	return((_Context->keycode=0));
	}
	if(_Context->column_DataMembers==2){
	dptr=FileManager->current->payload;
	l=_Context->value_DataMembers;
	if((i=((l-1)+_Context->value_DataBar))<=dptr->datafields){
	switch(dptr->type[i+dptr->indexfields]){
	case _ABAL_BYTE:_Context->value_TypeSelect=0;break;
	case _ABAL_WORD:_Context->value_TypeSelect=1;break;
	case _ABAL_BCD:_Context->value_TypeSelect=2;break;
	case _ABAL_STRING:_Context->value_TypeSelect=3;break;
	case _ABAL_LONG:_Context->value_TypeSelect=4;break;
	case _ABAL_FIELD:_Context->value_TypeSelect=5;break;
	case _ABAL_FILLER:_Context->value_TypeSelect=6;break;
	}
	}
	else _Context->value_TypeSelect=0;
	_Context->x_TypeSelect=_Context->x_Auto3333+40+(56*8);
	_Context->y_TypeSelect=_Context->y_Auto3333+280+(l*16);
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
	visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),768);
;
		_Context->keycode = visual_select(_Context->x_TypeSelect,_Context->y_TypeSelect,_Context->w_TypeSelect,_Context->h_TypeSelect,_Context->fid_TypeSelect,0,0,parse_selection(_Context->msg_TypeSelect[_Context->language],&_Context->value_TypeSelect),770);
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
	case 5:dptr->type[i+dptr->indexfields]=_ABAL_FIELD;break;
	case 6:dptr->type[i+dptr->indexfields]=_ABAL_FILLER;break;
	}
		visual_table(_Context->x_Auto3333+40,_Context->y_Auto3333+280,700,280,vfh[1],0,0,_Context->msg_DataMembers[_Context->language],_Context->buffer_DataMembers,0x4401,"($,W8,N4Z,N4Z,N4Z,W,W)");
;
	}
	}
	else{
	if(_Context->column_DataMembers==1){
	dptr=FileManager->current->payload;
	l=_Context->value_DataMembers;
	if((i=((l-1)+_Context->value_DataBar))<=dptr->datafields){
	string_print_dcl(wbuffer,"\0",
	dptr->name[i+dptr->indexfields],dptr->type[i+dptr->indexfields],
	dptr->width[i+dptr->indexfields],
	dptr->first[i+dptr->indexfields],dptr->second[i+dptr->indexfields],
	dptr->special[i+dptr->indexfields],dptr->decimal[i+dptr->indexfields]
	);
	if ( l > 0 ) { _Context->row_DataMembers=&_Context->buffer_DataMembers[l-1][0]; } ;
	putstring(_Context, (_Context->row_DataMembers+0),56,wbuffer);
	}
	}
		if (!_Context->value_DataMembers) _Context->value_DataMembers=1;	/* pour etre sur qu'on edite pas le titre */
	_Context->row_DataMembers = &_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0];
	switch (_Context->column_DataMembers) {
	case	0x1 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+2),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),440,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0],55);
	visual_text((_Context->x_Auto3333+40+2),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),440,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][0],55,0);
		break;
	case	0x2 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+450),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),64,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][56],8);
	visual_text((_Context->x_Auto3333+40+450),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),64,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][56],8,0);
		break;
	case	0x3 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+522),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][65],5);
	visual_text((_Context->x_Auto3333+40+522),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][65],5,0);
		break;
	case	0x4 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+570),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][71],5);
	visual_text((_Context->x_Auto3333+40+570),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][71],5,0);
		break;
	case	0x5 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+618),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][77],5);
	visual_text((_Context->x_Auto3333+40+618),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),40,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][77],5,0);
		break;
	case	0x6 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+666),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),8,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][83],1);
	visual_text((_Context->x_Auto3333+40+666),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),8,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][83],1,0);
		break;
	case	0x7 :
		_Context->keycode=visual_edit((_Context->x_Auto3333+40+682),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),8,16,vfh[1],&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][85],1);
	visual_text((_Context->x_Auto3333+40+682),(_Context->y_Auto3333+280+(_Context->value_DataMembers*16)+2),8,16,vfh[1],0,(24-((_Context->value_DataMembers-1)&1)),&_Context->buffer_DataMembers[(_Context->value_DataMembers-1)][85],1,0);
		break;
		}
;
	}
	return(-1);
}


public	int	old_database_editor_focus(struct old_database_editor_context * _Context)
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
					if (!_Context->value_FileList) _Context->value_FileList=1;	/* pour etre sur qu'on edite pas le titre */
					_Context->row_FileList = &_Context->buffer_FileList[(_Context->value_FileList-1)][0];
					switch (_Context->column_FileList) {
					case	0x1 :
						_Context->keycode=visual_edit((_Context->x_Auto3333+30+2),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),256,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][0],32);
					visual_text((_Context->x_Auto3333+30+2),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),256,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][0],32,0);
						break;
					case	0x2 :
						_Context->keycode=visual_edit((_Context->x_Auto3333+30+266),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),256,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][33],32);
					visual_text((_Context->x_Auto3333+30+266),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),256,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][33],32,0);
						break;
					case	0x3 :
						_Context->keycode=visual_edit((_Context->x_Auto3333+30+530),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),80,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][66],10);
					visual_text((_Context->x_Auto3333+30+530),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),80,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][66],10,0);
						break;
					case	0x4 :
						_Context->keycode=visual_edit((_Context->x_Auto3333+30+618),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),80,16,vfh[1],&_Context->buffer_FileList[(_Context->value_FileList-1)][77],10);
					visual_text((_Context->x_Auto3333+30+618),(_Context->y_Auto3333+90+(_Context->value_FileList*16)+2),80,16,vfh[1],27,(24-((_Context->value_FileList-1)&1)),&_Context->buffer_FileList[(_Context->value_FileList-1)][77],10,0);
						break;
						}
					(void) on_FileList_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* ScrollBar */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x5 :
				/* CopyFile */
				if (_Context->page_number == 1 ) {
					_Context->trigger_CopyFile=visual_trigger_code(_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]));
					visual_button(_Context->x_Auto3333+30,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_CopyFile=visual_trigger_code(_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]));
	visual_button(_Context->x_Auto3333+30,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* DeleteFile */
				if (_Context->page_number == 1 ) {
					_Context->trigger_DeleteFile=visual_trigger_code(_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]));
					visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_DeleteFile=visual_trigger_code(_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]));
	visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* FilePage */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x9 :
				/* ClassName */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+110+1,_Context->y_Auto3333+80+1,328,16,vfh[1],_Context->buffer_ClassName,255);
					(void) on_ClassName_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* Instance */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+110+1,_Context->y_Auto3333+100+1,328,16,vfh[1],_Context->buffer_Instance,255);
					(void) on_Instance_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* Filename */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+110+1,_Context->y_Auto3333+120+1,328,16,vfh[1],_Context->buffer_Filename,255);
					(void) on_Filename_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* FileType */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_Auto3333+110,_Context->y_Auto3333+140,96,64,vfh[2],0,28,parse_selection(WidgetDataList,&_Context->value_FileType),770);
					(void) on_FileType_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* IndexType */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_Auto3333+260,_Context->y_Auto3333+140,48,64,vfh[1],0,0,parse_selection(_Context->msg_IndexType[_Context->language],&_Context->value_IndexType),2);
					(void) on_IndexType_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* IndexSize */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+580+1,_Context->y_Auto3333+100+1,64,16,vfh[1],_Context->buffer_IndexSize,8);
					(void) on_IndexSize_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* Auto3342 */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
					visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
	visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* Auto3343 */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
					visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* RecordType */
				if (_Context->page_number == 2 ) {
				visual_switch(_Context->x_Auto3333+312,_Context->y_Auto3333+140,30,22,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),(_Context->value_RecordType | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_RecordType=visual_trigger_code(_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]));
	visual_switch(_Context->x_Auto3333+312,_Context->y_Auto3333+140,30,22,vfh[2],27,28,_Context->msg_RecordType[_Context->language],strlen(_Context->msg_RecordType[_Context->language]),_Context->value_RecordType| 0x0030);
					(void) on_RecordType_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* MarkerUseage */
				if (_Context->page_number == 2 ) {
				visual_switch(_Context->x_Auto3333+410,_Context->y_Auto3333+140,30,22,vfh[2],27,28,_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]),(_Context->value_MarkerUseage | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_MarkerUseage=visual_trigger_code(_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]));
	visual_switch(_Context->x_Auto3333+410,_Context->y_Auto3333+140,30,22,vfh[2],27,28,_Context->msg_MarkerUseage[_Context->language],strlen(_Context->msg_MarkerUseage[_Context->language]),_Context->value_MarkerUseage| 0x0030);
					(void) on_MarkerUseage_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* Modext */
				if (_Context->page_number == 2 ) {
				visual_switch(_Context->x_Auto3333+344,_Context->y_Auto3333+140,65,22,vfh[2],27,28,_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]),(_Context->value_Modext | 2 | 0x0030 ));
					_Context->keycode = visual_getch();
					_Context->trigger_Modext=visual_trigger_code(_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]));
	visual_switch(_Context->x_Auto3333+344,_Context->y_Auto3333+140,65,22,vfh[2],27,28,_Context->msg_Modext[_Context->language],strlen(_Context->msg_Modext[_Context->language]),_Context->value_Modext| 0x0030);
					(void) on_Modext_losefocus(_Context);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* RecordSize */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+580+1,_Context->y_Auto3333+120+1,64,16,vfh[1],_Context->buffer_RecordSize,8);
					(void) on_RecordSize_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* Auto3344 */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Auto3344=visual_trigger_code(_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]));
					visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3344=visual_trigger_code(_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]));
	visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* Auto3345 */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Auto3345=visual_trigger_code(_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]));
					visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3345=visual_trigger_code(_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* Accept */
				if (_Context->page_number == 2 ) {
					_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
					visual_button(_Context->x_Auto3333+580,_Context->y_Auto3333+140,97,27,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3333+580,_Context->y_Auto3333+140,97,27,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* FileUsers */
				if (_Context->page_number == 2 ) {
					_Context->trigger_FileUsers=visual_trigger_code(_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]));
					visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+139,66,28,vfh[2],27,28,_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_FileUsers=visual_trigger_code(_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]));
	visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+139,66,28,vfh[2],27,28,_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* IndexMembers */
				if (_Context->page_number == 2 ) {
					(void) on_IndexMembers_getfocus(_Context);
					(void) on_IndexMembers_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* IndexBar */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1d :
				/* DataMembers */
				if (_Context->page_number == 2 ) {
					(void) on_DataMembers_getfocus(_Context);
					(void) on_DataMembers_losefocus(_Context);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* DataBar */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x20 :
				/* MaskPage */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x21 :
				/* StubName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+40+1,_Context->y_Auto3333+140+1,688,16,vfh[1],_Context->buffer_StubName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* EditBase */
				if (_Context->page_number == 3 ) {
					_Context->trigger_EditBase=visual_trigger_code(_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]));
					visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+420,16,16,vfh[8],27,28,_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]),786);
					_Context->keycode = visual_getch();
					_Context->trigger_EditBase=visual_trigger_code(_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]));
	visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+420,16,16,vfh[8],27,28,_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]),784);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* ViewList */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ViewList=visual_trigger_code(_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]));
					visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+480,16,16,vfh[8],27,28,_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]),786);
					_Context->keycode = visual_getch();
					_Context->trigger_ViewList=visual_trigger_code(_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]));
	visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+480,16,16,vfh[8],27,28,_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]),784);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* BaseFile */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+290+1,_Context->y_Auto3333+420+1,424,16,vfh[1],_Context->buffer_BaseFile,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* FormName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+290+1,_Context->y_Auto3333+450+1,424,16,vfh[1],_Context->buffer_FormName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* ListName */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+290+1,_Context->y_Auto3333+480+1,424,16,vfh[1],_Context->buffer_ListName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* EditFile */
				if (_Context->page_number == 3 ) {
					_Context->trigger_EditFile=visual_trigger_code(_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]));
					visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+140,16,16,vfh[8],27,28,_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]),786);
					_Context->keycode = visual_getch();
					_Context->trigger_EditFile=visual_trigger_code(_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+140,16,16,vfh[8],27,28,_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]),784);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* Title */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+40+1,_Context->y_Auto3333+180+1,472,16,vfh[1],_Context->buffer_Title,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* Language */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_Auto3333+520,_Context->y_Auto3333+180,230,90,vfh[2],16,0,parse_selection(_Context->msg_Language[_Context->language],&_Context->value_Language),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* PageItems */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+200+1,_Context->y_Auto3333+240+1,56,16,vfh[1],_Context->buffer_PageItems,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* ListLines */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+440+1,_Context->y_Auto3333+240+1,56,16,vfh[1],_Context->buffer_ListLines,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* ListColumns */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+440+1,_Context->y_Auto3333+260+1,56,16,vfh[1],_Context->buffer_ListColumns,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* MaxColumn */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3333+440+1,_Context->y_Auto3333+280+1,56,16,vfh[1],_Context->buffer_MaxColumn,7);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* GenerateMask */
				if (_Context->page_number == 3 ) {
					_Context->trigger_GenerateMask=visual_trigger_code(_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]));
					visual_button(_Context->x_Auto3333+50,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_GenerateMask=visual_trigger_code(_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]));
	visual_button(_Context->x_Auto3333+50,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* GeneratePage */
				if (_Context->page_number == 3 ) {
					_Context->trigger_GeneratePage=visual_trigger_code(_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]));
					visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_GeneratePage=visual_trigger_code(_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]));
	visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* GenerateList */
				if (_Context->page_number == 3 ) {
					_Context->trigger_GenerateList=visual_trigger_code(_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]));
					visual_button(_Context->x_Auto3333+290,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_GenerateList=visual_trigger_code(_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]));
	visual_button(_Context->x_Auto3333+290,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* ImportBase */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ImportBase=visual_trigger_code(_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]));
					visual_button(_Context->x_Auto3333+60,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ImportBase=visual_trigger_code(_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]));
	visual_button(_Context->x_Auto3333+60,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* ExportBase */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ExportBase=visual_trigger_code(_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]));
					visual_button(_Context->x_Auto3333+160,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ExportBase=visual_trigger_code(_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]));
	visual_button(_Context->x_Auto3333+160,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* ListBase */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ListBase=visual_trigger_code(_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]));
					visual_button(_Context->x_Auto3333+560,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ListBase=visual_trigger_code(_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]));
	visual_button(_Context->x_Auto3333+560,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* ExportForm */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ExportForm=visual_trigger_code(_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]));
					visual_button(_Context->x_Auto3333+390,_Context->y_Auto3333+520,168,32,vfh[2],16,0,_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ExportForm=visual_trigger_code(_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]));
	visual_button(_Context->x_Auto3333+390,_Context->y_Auto3333+520,168,32,vfh[2],16,0,_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* DeleteBase */
				if (_Context->page_number == 3 ) {
					_Context->trigger_DeleteBase=visual_trigger_code(_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]));
					visual_button(_Context->x_Auto3333+260,_Context->y_Auto3333+520,126,32,vfh[2],16,0,_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_DeleteBase=visual_trigger_code(_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]));
	visual_button(_Context->x_Auto3333+260,_Context->y_Auto3333+520,126,32,vfh[2],16,0,_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;

			default :
				_Context->keycode=5;
			}
		switch (_Context->keycode) {
		case	0xc :
			old_database_editor_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			old_database_editor_show(_Context);
			continue;
		case	0x2 :
			old_database_editor_losefocus(_Context);
			_Context->page_number=3;
			_Context->focus_item=54;
			old_database_editor_show(_Context);
			continue;
		case	0x3 :
			old_database_editor_losefocus(_Context);
			if ( _Context->page_number < 3 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			old_database_editor_show(_Context);
			continue;
		case	0x12 :
			old_database_editor_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			old_database_editor_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=old_database_editor_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (ListPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (FileList_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (ScrollBar_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (CopyFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (DeleteFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (PasteFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (FilePage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (ClassName_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (Instance_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (Filename_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (FileType_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (IndexType_help(_Context) != 0) { continue; }
						else { break; }
					case	0xe :
						if (IndexSize_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (Auto3342_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (NbIndex_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (Auto3343_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (RecordType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (MarkerUseage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (Modext_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (RecordSize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x16 :
						if (Auto3344_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (NbData_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (Auto3345_help(_Context) != 0) { continue; }
						else { break; }
					case	0x19 :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (FileUsers_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (IndexMembers_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (DataMembers_help(_Context) != 0) { continue; }
						else { break; }
					case	0x20 :
						if (MaskPage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x21 :
						if (StubName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x22 :
						if (EditBase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x23 :
						if (ViewList_help(_Context) != 0) { continue; }
						else { break; }
					case	0x24 :
						if (BaseFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x25 :
						if (FormName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x26 :
						if (ListName_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (EditFile_help(_Context) != 0) { continue; }
						else { break; }
					case	0x28 :
						if (Title_help(_Context) != 0) { continue; }
						else { break; }
					case	0x29 :
						if (Language_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2a :
						if (PageItems_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2b :
						if (ListLines_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2d :
						if (MaxColumn_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2e :
						if (GenerateMask_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2f :
						if (GeneratePage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x30 :
						if (GenerateList_help(_Context) != 0) { continue; }
						else { break; }
					case	0x31 :
						if (ImportBase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x32 :
						if (ExportBase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x33 :
						if (ListBase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x34 :
						if (NationalHelptext_help(_Context) != 0) { continue; }
						else { break; }
					case	0x35 :
						if (ExportForm_help(_Context) != 0) { continue; }
						else { break; }
					case	0x36 :
						if (DeleteBase_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3333 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* ListPage */
					if (visual_event(1) & _MIMO_DOWN) {
						old_database_editor_losefocus(_Context);
						_Context->page_number = 1;
						old_database_editor_show(_Context);
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
					/* CopyFile */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_CopyFile=visual_trigger_code(_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]));
						visual_button(_Context->x_Auto3333+30,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_CopyFile=visual_trigger_code(_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]));
	visual_button(_Context->x_Auto3333+30,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_CopyFile[_Context->language],strlen(_Context->msg_CopyFile[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CopyFile_event(_Context)) != -1) break;

						}
					continue;
				case	0x6 :
					/* DeleteFile */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DeleteFile=visual_trigger_code(_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]));
						visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DeleteFile=visual_trigger_code(_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]));
	visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_DeleteFile[_Context->language],strlen(_Context->msg_DeleteFile[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DeleteFile_event(_Context)) != -1) break;

						}
					continue;
				case	0x7 :
					/* PasteFile */
					if (visual_event(1) & _MIMO_DOWN) {
						if ((_Context->p_PasteFile != (void *) 0)
						&& (_Context->s_PasteFile == 0)) {
							(void)visual_buffer_get(_Context->p_PasteFile,_Context->x_Auto3333+280,_Context->y_Auto3333+540);
							_Context->s_PasteFile=1;
							}
						_Context->trigger_PasteFile=visual_trigger_code(_Context->msg_PasteFile[_Context->language],strlen(_Context->msg_PasteFile[_Context->language]));
						visual_button(_Context->x_Auto3333+280,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_PasteFile[_Context->language],strlen(_Context->msg_PasteFile[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						if ((_Context->p_PasteFile != (void *) 0)
						&& (_Context->s_PasteFile == 0)) {
							(void)visual_buffer_get(_Context->p_PasteFile,_Context->x_Auto3333+280,_Context->y_Auto3333+540);
							_Context->s_PasteFile=1;
							}
						_Context->trigger_PasteFile=visual_trigger_code(_Context->msg_PasteFile[_Context->language],strlen(_Context->msg_PasteFile[_Context->language]));
	visual_button(_Context->x_Auto3333+280,_Context->y_Auto3333+540,208,30,vfh[2],27,28,_Context->msg_PasteFile[_Context->language],strlen(_Context->msg_PasteFile[_Context->language]),0);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_PasteFile_event(_Context)) != -1) break;

						}
					continue;
				case	0x8 :
					/* FilePage */
					if (visual_event(1) & _MIMO_DOWN) {
						old_database_editor_losefocus(_Context);
						_Context->page_number = 2;
						old_database_editor_show(_Context);
						}
					continue;
				case	0x9 :
					/* ClassName */
					continue;
				case	0xa :
					/* Instance */
					continue;
				case	0xb :
					/* Filename */
					continue;
				case	0xc :
					/* FileType */
					continue;
				case	0xd :
					/* IndexType */
					continue;
				case	0xe :
					/* IndexSize */
					continue;
				case	0xf :
					/* Auto3342 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
						visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3342=visual_trigger_code(_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]));
	visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3342[_Context->language],strlen(_Context->msg_Auto3342[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3342_event(_Context)) != -1) break;

						}
					continue;
				case	0x10 :
					/* NbIndex */
					continue;
				case	0x11 :
					/* Auto3343 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
						visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3343=visual_trigger_code(_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3343[_Context->language],strlen(_Context->msg_Auto3343[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3343_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* RecordType */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_RecordType += 1;
						_Context->value_RecordType &= 1;
						}
					continue;
				case	0x13 :
					/* MarkerUseage */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_MarkerUseage += 1;
						_Context->value_MarkerUseage &= 1;
						}
					continue;
				case	0x14 :
					/* Modext */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Modext += 1;
						_Context->value_Modext &= 1;
						}
					continue;
				case	0x15 :
					/* RecordSize */
					continue;
				case	0x16 :
					/* Auto3344 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3344=visual_trigger_code(_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]));
						visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3344=visual_trigger_code(_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]));
	visual_button(_Context->x_Auto3333+660,_Context->y_Auto3333+100,16,18,vfh[8],27,28,_Context->msg_Auto3344[_Context->language],strlen(_Context->msg_Auto3344[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3344_event(_Context)) != -1) break;

						}
					continue;
				case	0x17 :
					/* NbData */
					continue;
				case	0x18 :
					/* Auto3345 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3345=visual_trigger_code(_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]));
						visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3345=visual_trigger_code(_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+120,16,18,vfh[8],27,28,_Context->msg_Auto3345[_Context->language],strlen(_Context->msg_Auto3345[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3345_event(_Context)) != -1) break;

						}
					continue;
				case	0x19 :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3333+580,_Context->y_Auto3333+140,97,27,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3333+580,_Context->y_Auto3333+140,97,27,vfh[2],27,28,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x1a :
					/* FileUsers */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_FileUsers=visual_trigger_code(_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]));
						visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+139,66,28,vfh[2],27,28,_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_FileUsers=visual_trigger_code(_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]));
	visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+139,66,28,vfh[2],27,28,_Context->msg_FileUsers[_Context->language],strlen(_Context->msg_FileUsers[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_FileUsers_event(_Context)) != -1) break;

						}
					continue;
				case	0x1b :
					/* IndexMembers */
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_IndexMembers_event(_Context)) != -1) break;

						}
					continue;
				case	0x1c :
					/* IndexBar */
					(void) on_IndexBar_action(_Context);
					continue;
				case	0x1d :
					/* DataMembers */
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_DataMembers_event(_Context)) != -1) break;

						}
					continue;
				case	0x1e :
					/* DataBar */
					(void) on_DataBar_action(_Context);
					continue;
				case	0x1f :
					/* TypeSelect */
					continue;
				case	0x20 :
					/* MaskPage */
					if (visual_event(1) & _MIMO_DOWN) {
						old_database_editor_losefocus(_Context);
						_Context->page_number = 3;
						old_database_editor_show(_Context);
						}
					continue;
				case	0x21 :
					/* StubName */
					continue;
				case	0x22 :
					/* EditBase */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditBase=visual_trigger_code(_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]));
						visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+420,16,16,vfh[8],27,28,_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]),786);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditBase=visual_trigger_code(_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]));
	visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+420,16,16,vfh[8],27,28,_Context->msg_EditBase[_Context->language],strlen(_Context->msg_EditBase[_Context->language]),784);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditBase_event(_Context)) != -1) break;

						}
					continue;
				case	0x23 :
					/* ViewList */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ViewList=visual_trigger_code(_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]));
						visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+480,16,16,vfh[8],27,28,_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]),786);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ViewList=visual_trigger_code(_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]));
	visual_button(_Context->x_Auto3333+720,_Context->y_Auto3333+480,16,16,vfh[8],27,28,_Context->msg_ViewList[_Context->language],strlen(_Context->msg_ViewList[_Context->language]),784);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ViewList_event(_Context)) != -1) break;

						}
					continue;
				case	0x24 :
					/* BaseFile */
					continue;
				case	0x25 :
					/* FormName */
					continue;
				case	0x26 :
					/* ListName */
					continue;
				case	0x27 :
					/* EditFile */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EditFile=visual_trigger_code(_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]));
						visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+140,16,16,vfh[8],27,28,_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]),786);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EditFile=visual_trigger_code(_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]));
	visual_button(_Context->x_Auto3333+730,_Context->y_Auto3333+140,16,16,vfh[8],27,28,_Context->msg_EditFile[_Context->language],strlen(_Context->msg_EditFile[_Context->language]),784);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EditFile_event(_Context)) != -1) break;

						}
					continue;
				case	0x28 :
					/* Title */
					continue;
				case	0x29 :
					/* Language */
					continue;
				case	0x2a :
					/* PageItems */
					continue;
				case	0x2b :
					/* ListLines */
					continue;
				case	0x2c :
					/* ListColumns */
					continue;
				case	0x2d :
					/* MaxColumn */
					continue;
				case	0x2e :
					/* GenerateMask */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_GenerateMask=visual_trigger_code(_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]));
						visual_button(_Context->x_Auto3333+50,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_GenerateMask=visual_trigger_code(_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]));
	visual_button(_Context->x_Auto3333+50,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateMask[_Context->language],strlen(_Context->msg_GenerateMask[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_GenerateMask_event(_Context)) != -1) break;

						}
					continue;
				case	0x2f :
					/* GeneratePage */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_GeneratePage=visual_trigger_code(_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]));
						visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_GeneratePage=visual_trigger_code(_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]));
	visual_button(_Context->x_Auto3333+530,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GeneratePage[_Context->language],strlen(_Context->msg_GeneratePage[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_GeneratePage_event(_Context)) != -1) break;

						}
					continue;
				case	0x30 :
					/* GenerateList */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_GenerateList=visual_trigger_code(_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]));
						visual_button(_Context->x_Auto3333+290,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_GenerateList=visual_trigger_code(_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]));
	visual_button(_Context->x_Auto3333+290,_Context->y_Auto3333+310,210,32,vfh[2],16,0,_Context->msg_GenerateList[_Context->language],strlen(_Context->msg_GenerateList[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_GenerateList_event(_Context)) != -1) break;

						}
					continue;
				case	0x31 :
					/* ImportBase */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ImportBase=visual_trigger_code(_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]));
						visual_button(_Context->x_Auto3333+60,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ImportBase=visual_trigger_code(_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]));
	visual_button(_Context->x_Auto3333+60,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ImportBase[_Context->language],strlen(_Context->msg_ImportBase[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ImportBase_event(_Context)) != -1) break;

						}
					continue;
				case	0x32 :
					/* ExportBase */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ExportBase=visual_trigger_code(_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]));
						visual_button(_Context->x_Auto3333+160,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ExportBase=visual_trigger_code(_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]));
	visual_button(_Context->x_Auto3333+160,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ExportBase[_Context->language],strlen(_Context->msg_ExportBase[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ExportBase_event(_Context)) != -1) break;

						}
					continue;
				case	0x33 :
					/* ListBase */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ListBase=visual_trigger_code(_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]));
						visual_button(_Context->x_Auto3333+560,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ListBase=visual_trigger_code(_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]));
	visual_button(_Context->x_Auto3333+560,_Context->y_Auto3333+520,98,32,vfh[2],16,0,_Context->msg_ListBase[_Context->language],strlen(_Context->msg_ListBase[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ListBase_event(_Context)) != -1) break;

						}
					continue;
				case	0x34 :
					/* NationalHelptext */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_NationalHelptext=visual_trigger_code(_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]));
						visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+510,56,48,vfh[2],28,28,_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]),18);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_NationalHelptext=visual_trigger_code(_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]));
	visual_button(_Context->x_Auto3333+680,_Context->y_Auto3333+510,56,48,vfh[2],28,28,_Context->msg_NationalHelptext[_Context->language],strlen(_Context->msg_NationalHelptext[_Context->language]),16);
						}
					if ( visual_event(1) &  0x30 ) {
					if ((_Context->keycode = on_NationalHelptext_event(_Context)) != -1) break;

						}
					continue;
				case	0x35 :
					/* ExportForm */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ExportForm=visual_trigger_code(_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]));
						visual_button(_Context->x_Auto3333+390,_Context->y_Auto3333+520,168,32,vfh[2],16,0,_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ExportForm=visual_trigger_code(_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]));
	visual_button(_Context->x_Auto3333+390,_Context->y_Auto3333+520,168,32,vfh[2],16,0,_Context->msg_ExportForm[_Context->language],strlen(_Context->msg_ExportForm[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ExportForm_event(_Context)) != -1) break;

						}
					continue;
				case	0x36 :
					/* DeleteBase */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DeleteBase=visual_trigger_code(_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]));
						visual_button(_Context->x_Auto3333+260,_Context->y_Auto3333+520,126,32,vfh[2],16,0,_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DeleteBase=visual_trigger_code(_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]));
	visual_button(_Context->x_Auto3333+260,_Context->y_Auto3333+520,126,32,vfh[2],16,0,_Context->msg_DeleteBase[_Context->language],strlen(_Context->msg_DeleteBase[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DeleteBase_event(_Context)) != -1) break;

						}
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
				_Context->focus_item=54;
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

public	int	old_database_editor()
{
	int	status=0;
	struct old_database_editor_context * _Context=(struct old_database_editor_context*) 0;
	status = old_database_editor_create(&_Context);
	if ( status != 0) return(status);
	status = old_database_editor_show(_Context);
		enter_modal();
	status = old_database_editor_focus(_Context);
		leave_modal();
	status = old_database_editor_hide(_Context);
	status = old_database_editor_remove(_Context);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vfile_c */
