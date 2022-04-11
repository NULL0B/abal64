
#ifndef _vcamera_c
#define _vcamera_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vcamera.xml                                              */
/* Target         : vcamera.c                                                */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#include "choixrepfic.h"
#include "vobjapi.h"
#define en__Auto3536   ""
#define fr__Auto3536   ""
#define it__Auto3536   ""
#define es__Auto3536   ""
#define de__Auto3536   ""
#define nl__Auto3536   ""
#define pt__Auto3536   ""
#define xx__Auto3536   ""
#define en_Auto3537   "&Configuration"
#define fr_Auto3537   "&Configuration"
#define it_Auto3537   "&Configuration"
#define es_Auto3537   "&Configuration"
#define de_Auto3537   "&Configuration"
#define nl_Auto3537   "&Configuration"
#define pt_Auto3537   "&Configuration"
#define xx_Auto3537   "&Configuration"
#define en__Auto3537   ""
#define fr__Auto3537   ""
#define it__Auto3537   ""
#define es__Auto3537   ""
#define de__Auto3537   ""
#define nl__Auto3537   ""
#define pt__Auto3537   ""
#define xx__Auto3537   ""
#define en_Auto3538   "Global Project Configuration"
#define fr_Auto3538   "PropriŠtes de la Vue du Projet"
#define it_Auto3538   "Project 3D Camera Properties"
#define es_Auto3538   "Project 3D Camera Properties"
#define de_Auto3538   "Project 3D Camera Properties"
#define nl_Auto3538   "Project 3D Camera Properties"
#define pt_Auto3538   "Project 3D Camera Properties"
#define xx_Auto3538   "Project 3D Camera Properties"
#define en__Auto3538   ""
#define en_Auto3543   "Configuration"
#define fr_Auto3543   "Configuration"
#define it_Auto3543   "Configuration"
#define es_Auto3543   "Configuration"
#define de_Auto3543   "Configuration"
#define nl_Auto3543   "Configuration"
#define pt_Auto3543   "Configuration"
#define xx_Auto3543   "Configuration"
#define en_TitreDataBase   "Data Base"
#define fr_TitreDataBase   "Base de donn‚es"
#define it_TitreDataBase   "Data Base"
#define es_TitreDataBase   "Data Base"
#define de_TitreDataBase   "Data Base"
#define nl_TitreDataBase   "Data Base"
#define pt_TitreDataBase   "Data Base"
#define xx_TitreDataBase   "Data Base"
#define en__TitreDataBase   ""
#define fr__TitreDataBase   ""
#define it__TitreDataBase   ""
#define es__TitreDataBase   ""
#define de__TitreDataBase   ""
#define nl__TitreDataBase   ""
#define pt__TitreDataBase   ""
#define xx__TitreDataBase   ""
#define en_Auto3544   "Template"
#define fr_Auto3544   "Template"
#define it_Auto3544   "Template"
#define es_Auto3544   "Template"
#define de_Auto3544   "Template"
#define nl_Auto3544   "Template"
#define pt_Auto3544   "Template"
#define xx_Auto3544   "Template"
#define en__Auto3544   ""
#define en_Auto3545   "Modules"
#define fr_Auto3545   "Modules"
#define it_Auto3545   "Modules"
#define es_Auto3545   "Modules"
#define de_Auto3545   "Modules"
#define nl_Auto3545   "Modules"
#define pt_Auto3545   "Modules"
#define xx_Auto3545   "Modules"
#define en__Auto3545   ""
#define fr__Auto3545   ""
#define en_Auto3546   "Components"
#define fr_Auto3546   "Composants"
#define it_Auto3546   "Components"
#define es_Auto3546   "Components"
#define de_Auto3546   "Components"
#define nl_Auto3546   "Components"
#define pt_Auto3546   "Components"
#define xx_Auto3546   "Components"
#define en__Auto3546   ""
#define fr__Auto3546   ""
#define it__Auto3546   ""
#define es__Auto3546   ""
#define de__Auto3546   ""
#define nl__Auto3546   ""
#define pt__Auto3546   ""
#define xx__Auto3546   ""
#define en_Auto3547   "Forms Directory"
#define fr_Auto3547   "R‚p. formulaires"
#define it_Auto3547   "Forms Directory"
#define es_Auto3547   "Forms Directory"
#define de_Auto3547   "Forms Directory"
#define nl_Auto3547   "Forms Directory"
#define pt_Auto3547   "Forms Directory"
#define xx_Auto3547   "Forms Directory"
#define en__Auto3547   ""
#define fr__Auto3547   ""
#define it__Auto3547   ""
#define es__Auto3547   ""
#define de__Auto3547   ""
#define nl__Auto3547   ""
#define pt__Auto3547   ""
#define xx__Auto3547   ""
#define en_Auto3548   "Sources Directory"
#define fr_Auto3548   "R‚p. sources"
#define it_Auto3548   "Sources Directory"
#define es_Auto3548   "Sources Directory"
#define de_Auto3548   "Sources Directory"
#define nl_Auto3548   "Sources Directory"
#define pt_Auto3548   "Sources Directory"
#define xx_Auto3548   "Sources Directory"
#define en__Auto3548   ""
#define fr__Auto3548   ""
#define it__Auto3548   ""
#define es__Auto3548   ""
#define de__Auto3548   ""
#define nl__Auto3548   ""
#define pt__Auto3548   ""
#define xx__Auto3548   ""
#define en_Auto3549   "Binary Directory"
#define fr_Auto3549   "R‚p. binaires"
#define it_Auto3549   "Binary Directory"
#define es_Auto3549   "Binary Directory"
#define de_Auto3549   "Binary Directory"
#define nl_Auto3549   "Binary Directory"
#define pt_Auto3549   "Binary Directory"
#define xx_Auto3549   "Binary Directory"
#define en__Auto3549   ""
#define fr__Auto3549   ""
#define it__Auto3549   ""
#define es__Auto3549   ""
#define de__Auto3549   ""
#define nl__Auto3549   ""
#define pt__Auto3549   ""
#define xx__Auto3549   ""
#define en_Auto3550   "Palette"
#define fr_Auto3550   "Palette"
#define it_Auto3550   "Palette"
#define es_Auto3550   "Palette"
#define de_Auto3550   "Palette"
#define nl_Auto3550   "Palette"
#define pt_Auto3550   "Palette"
#define xx_Auto3550   "Palette"
#define en__Auto3550   ""
#define fr__Auto3550   ""
#define en_Auto3551   "Background Image"
#define fr_Auto3551   "Image de fond"
#define it_Auto3551   "Background Image"
#define es_Auto3551   "Background Image"
#define de_Auto3551   "Background Image"
#define nl_Auto3551   "Background Image"
#define pt_Auto3551   "Background Image"
#define xx_Auto3551   "Background Image"
#define en__Auto3551   ""
#define fr__Auto3551   ""
#define it__Auto3551   ""
#define es__Auto3551   ""
#define de__Auto3551   ""
#define nl__Auto3551   ""
#define pt__Auto3551   ""
#define xx__Auto3551   ""
#define en_Auto3552   "Image Options"
#define fr_Auto3552   "Alignement de l'image"
#define it_Auto3552   "Image Options"
#define es_Auto3552   "Image Options"
#define de_Auto3552   "Image Options"
#define nl_Auto3552   "Image Options"
#define pt_Auto3552   "Image Options"
#define xx_Auto3552   "Image Options"
#define en__Auto3552   ""
#define fr__Auto3552   ""
#define it__Auto3552   ""
#define es__Auto3552   ""
#define de__Auto3552   ""
#define nl__Auto3552   ""
#define pt__Auto3552   ""
#define xx__Auto3552   ""
#define en_auto702   "Background Colour"
#define fr_auto702   "Couleur de fond"
#define it_auto702   "Background colour"
#define es_auto702   "Background Colour"
#define de_auto702   "Background Colour"
#define nl_auto702   "Background Colour"
#define pt_auto702   "Background Colour"
#define xx_auto702   "Dath Teacs"
#define en__auto702   ""
#define fr__auto702   ""
#define it__auto702   ""
#define es__auto702   ""
#define de__auto702   ""
#define nl__auto702   ""
#define pt__auto702   ""
#define xx__auto702   ""
#define en_Auto3553   "Language"
#define fr_Auto3553   "Langage"
#define it_Auto3553   "Language"
#define es_Auto3553   "Language"
#define de_Auto3553   "Sprache"
#define nl_Auto3553   "Sprache"
#define pt_Auto3553   "Language"
#define xx_Auto3553   "Language"
#define en__Auto3553   ""
#define fr__Auto3553   ""
#define it__Auto3553   ""
#define es__Auto3553   ""
#define de__Auto3553   ""
#define nl__Auto3553   ""
#define pt__Auto3553   ""
#define xx__Auto3553   ""
#define en_Auto3554   "Source Extension"
#define fr_Auto3554   "Extension source"
#define it_Auto3554   "Source Extension"
#define es_Auto3554   "Source Extension"
#define de_Auto3554   "Source Extension"
#define nl_Auto3554   "Source Extension"
#define pt_Auto3554   "Source Extension"
#define xx_Auto3554   "Source Extension"
#define en__Auto3554   ""
#define fr__Auto3554   ""
#define it__Auto3554   ""
#define es__Auto3554   ""
#define de__Auto3554   ""
#define nl__Auto3554   ""
#define pt__Auto3554   ""
#define xx__Auto3554   ""
#define en_Configuration   ""
#define en__Configuration   ""
#define en_DataBase   ""
#define en__DataBase   ""
#define en_Template   ""
#define en__Template   ""
#define en_Modules   ""
#define en__Modules   ""
#define en_Components   ""
#define en__Components   ""
#define en_FormsDirectory   ""
#define fr_FormsDirectory   ""
#define en__FormsDirectory   ""
#define fr__FormsDirectory   ""
#define en_SourcesDirectory   ""
#define fr_SourcesDirectory   ""
#define en__SourcesDirectory   ""
#define fr__SourcesDirectory   ""
#define en_ObjectsDirectory   ""
#define fr_ObjectsDirectory   ""
#define en__ObjectsDirectory   ""
#define fr__ObjectsDirectory   ""
#define en_PaletteName   ""
#define fr_PaletteName   ""
#define en__PaletteName   ""
#define fr__PaletteName   ""
#define en_ImageName   ""
#define fr_ImageName   ""
#define en__ImageName   ""
#define fr__ImageName   ""
#define en__ImageType   ""
#define fr__ImageType   ""
#define it__ImageType   ""
#define es__ImageType   ""
#define de__ImageType   ""
#define nl__ImageType   ""
#define pt__ImageType   ""
#define xx__ImageType   ""
#define en_Quality   "&Quality"
#define fr_Quality   "&Qualit‚"
#define it_Quality   "&Quality"
#define es_Quality   "&Quality"
#define de_Quality   "&Quality"
#define nl_Quality   "&Quality"
#define pt_Quality   "&Quality"
#define xx_Quality   "&Quality"
#define en__Quality   ""
#define fr__Quality   ""
#define en_SaveImages   "&Save Images"
#define fr_SaveImages   "&Sauve images"
#define it_SaveImages   "&Save Images"
#define es_SaveImages   "&Save Images"
#define de_SaveImages   "&Save Images"
#define nl_SaveImages   "&Save Images"
#define pt_SaveImages   "&Save Images"
#define xx_SaveImages   "&Save Images"
#define en__SaveImages   ""
#define fr__SaveImages   ""
#define it__SaveImages   ""
#define es__SaveImages   ""
#define de__SaveImages   ""
#define nl__SaveImages   ""
#define pt__SaveImages   ""
#define xx__SaveImages   ""
#define en_Colour   ""
#define fr_Colour   ""
#define en__Colour   ""
#define fr__Colour   ""
#define en_ApplyStyle   "A&pply Style"
#define fr_ApplyStyle   "&Appliquer style"
#define it_ApplyStyle   "&Apply Style"
#define es_ApplyStyle   "&Apply Style"
#define de_ApplyStyle   "&Apply Style"
#define nl_ApplyStyle   "&Apply Style"
#define pt_ApplyStyle   "&Apply Style"
#define xx_ApplyStyle   "&Apply Style"
#define en__ApplyStyle   ""
#define fr__ApplyStyle   ""
#define it__ApplyStyle   ""
#define es__ApplyStyle   ""
#define de__ApplyStyle   ""
#define nl__ApplyStyle   ""
#define pt__ApplyStyle   ""
#define xx__ApplyStyle   ""
#define en_SaveForms   "Sa&ve Forms"
#define fr_SaveForms   "Sa&uve formulaires"
#define it_SaveForms   "Sa&ve Forms"
#define es_SaveForms   "Sa&ve Forms"
#define de_SaveForms   "Sa&ve Forms"
#define nl_SaveForms   "Sa&ve Forms"
#define pt_SaveForms   "Sa&ve Forms"
#define xx_SaveForms   "Sa&ve Forms"
#define en__SaveForms   ""
#define fr__SaveForms   ""
#define it__SaveForms   ""
#define es__SaveForms   ""
#define de__SaveForms   ""
#define nl__SaveForms   ""
#define pt__SaveForms   ""
#define xx__SaveForms   ""
#define en__NationalLanguage   ""
#define fr__NationalLanguage   ""
#define it__NationalLanguage   ""
#define es__NationalLanguage   ""
#define de__NationalLanguage   ""
#define nl__NationalLanguage   ""
#define pt__NationalLanguage   ""
#define xx__NationalLanguage   ""
#define en_RollBack   "&Rollback Undo/Redo"
#define fr_RollBack   "&Rollback"
#define it_RollBack   "&Rollback"
#define es_RollBack   "&Rollback"
#define de_RollBack   "&Rollback"
#define nl_RollBack   "&Rollback"
#define pt_RollBack   "&Rollback"
#define xx_RollBack   "&Rollback"
#define en__RollBack   ""
#define fr__RollBack   ""
#define it__RollBack   ""
#define es__RollBack   ""
#define de__RollBack   ""
#define nl__RollBack   ""
#define pt__RollBack   ""
#define xx__RollBack   ""
#define en_CameraLock   "&Inhibit Modifications"
#define fr_CameraLock   "&Inhiber des modifications"
#define it_CameraLock   "&Inhibit Modifications"
#define es_CameraLock   "&Inhibit Modifications"
#define de_CameraLock   "&Inhibit Modifications"
#define nl_CameraLock   "&Inhibit Modifications"
#define pt_CameraLock   "&Inhibit Modifications"
#define xx_CameraLock   "&Inhibit Modifications"
#define en__CameraLock   ""
#define fr__CameraLock   ""
#define it__CameraLock   ""
#define es__CameraLock   ""
#define de__CameraLock   ""
#define nl__CameraLock   ""
#define pt__CameraLock   ""
#define xx__CameraLock   ""
#define en_Extension   "ABAL|BAL"
#define fr_Extension   "ABAL|BAL"
#define it_Extension   "ABAL|BAL"
#define es_Extension   "ABAL|BAL"
#define de_Extension   "ABAL|BAL"
#define nl_Extension   "ABAL|BAL"
#define pt_Extension   "ABAL|BAL"
#define xx_Extension   "ABAL|BAL"
#define en__Extension   ""
#define fr__Extension   ""
#define it__Extension   ""
#define es__Extension   ""
#define de__Extension   ""
#define nl__Extension   ""
#define pt__Extension   ""
#define xx__Extension   ""
#define en_Select   "&..."
#define fr_Select   "&..."
#define it_Select   "&..."
#define es_Select   "&..."
#define de_Select   "&..."
#define nl_Select   "&..."
#define pt_Select   "&..."
#define xx_Select   "&..."
#define en__Select   ""
#define fr__Select   ""
#define en_Auto3555   "..."
#define fr_Auto3555   "..."
#define it_Auto3555   "..."
#define es_Auto3555   "..."
#define de_Auto3555   "..."
#define nl_Auto3555   "..."
#define pt_Auto3555   "..."
#define xx_Auto3555   "..."
#define en__Auto3555   ""
#define en_fgSelect   "Colors"
#define fr_fgSelect   "Couleurs"
#define it_fgSelect   "Colors"
#define es_fgSelect   "Colors"
#define de_fgSelect   "Colors"
#define nl_fgSelect   "Colors"
#define pt_fgSelect   "Colors"
#define xx_fgSelect   "Colors"
#define en__fgSelect   ""
#define fr__fgSelect   ""
#define it__fgSelect   ""
#define es__fgSelect   ""
#define de__fgSelect   ""
#define nl__fgSelect   ""
#define pt__fgSelect   ""
#define xx__fgSelect   ""
#define en_Choixfconf   "..."
#define fr_Choixfconf   "..."
#define it_Choixfconf   "..."
#define es_Choixfconf   "..."
#define de_Choixfconf   "..."
#define nl_Choixfconf   "..."
#define pt_Choixfconf   "..."
#define xx_Choixfconf   "..."
#define en__Choixfconf   ""
#define en_ChoixBase   "..."
#define fr_ChoixBase   "..."
#define it_ChoixBase   "..."
#define es_ChoixBase   "..."
#define de_ChoixBase   "..."
#define nl_ChoixBase   "..."
#define pt_ChoixBase   "..."
#define xx_ChoixBase   "..."
#define en__ChoixBase   ""
#define en_ChoixTemplate   "..."
#define fr_ChoixTemplate   "..."
#define it_ChoixTemplate   "..."
#define es_ChoixTemplate   "..."
#define de_ChoixTemplate   "..."
#define nl_ChoixTemplate   "..."
#define pt_ChoixTemplate   "..."
#define xx_ChoixTemplate   "..."
#define en__ChoixTemplate   ""
#define en_ChoixModules   "..."
#define fr_ChoixModules   "..."
#define it_ChoixModules   "..."
#define es_ChoixModules   "..."
#define de_ChoixModules   "..."
#define nl_ChoixModules   "..."
#define pt_ChoixModules   "..."
#define xx_ChoixModules   "..."
#define en__ChoixModules   ""
#define en_ChooseComponents   "..."
#define fr_ChooseComponents   "..."
#define it_ChooseComponents   "..."
#define es_ChooseComponents   "..."
#define de_ChooseComponents   "..."
#define nl_ChooseComponents   "..."
#define pt_ChooseComponents   "..."
#define xx_ChooseComponents   "..."
#define en__ChooseComponents   ""
#define en_Auto3556   "..."
#define fr_Auto3556   "..."
#define it_Auto3556   "..."
#define es_Auto3556   "..."
#define de_Auto3556   "..."
#define nl_Auto3556   "..."
#define pt_Auto3556   "..."
#define xx_Auto3556   "..."
#define en__Auto3556   ""
#define fr__Auto3556   ""
#define it__Auto3556   ""
#define es__Auto3556   ""
#define de__Auto3556   ""
#define nl__Auto3556   ""
#define pt__Auto3556   ""
#define xx__Auto3556   ""
#define en_Auto3557   "..."
#define fr_Auto3557   "..."
#define it_Auto3557   "..."
#define es_Auto3557   "..."
#define de_Auto3557   "..."
#define nl_Auto3557   "..."
#define pt_Auto3557   "..."
#define xx_Auto3557   "..."
#define en__Auto3557   ""
#define en_Auto3558   "..."
#define fr_Auto3558   "..."
#define it_Auto3558   "..."
#define es_Auto3558   "..."
#define de_Auto3558   "..."
#define nl_Auto3558   "..."
#define pt_Auto3558   "..."
#define xx_Auto3558   "..."
#define en__Auto3558   ""
#define en_Auto3559   "&3D Viewer"
#define fr_Auto3559   "&3D Viewer"
#define it_Auto3559   "&3D Viewer"
#define es_Auto3559   "&3D Viewer"
#define de_Auto3559   "&3D Viewer"
#define nl_Auto3559   "&3D Viewer"
#define pt_Auto3559   "&3D Viewer"
#define xx_Auto3559   "&3D Viewer"
#define en__Auto3559   ""
#define fr__Auto3559   ""
#define it__Auto3559   ""
#define es__Auto3559   ""
#define de__Auto3559   ""
#define nl__Auto3559   ""
#define pt__Auto3559   ""
#define xx__Auto3559   ""
#define en_Auto3564   "Project 3D Viewer Properties"
#define fr_Auto3564   "PropriŠtes de la vue du projet"
#define it_Auto3564   "Project 3D Camera Properties"
#define es_Auto3564   "Project 3D Camera Properties"
#define de_Auto3564   "Project 3D Camera Properties"
#define nl_Auto3564   "Project 3D Camera Properties"
#define pt_Auto3564   "Project 3D Camera Properties"
#define xx_Auto3564   "Project 3D Camera Properties"
#define en__Auto3564   ""
#define fr__Auto3564   ""
#define it__Auto3564   ""
#define es__Auto3564   ""
#define de__Auto3564   ""
#define nl__Auto3564   ""
#define pt__Auto3564   ""
#define xx__Auto3564   ""
#define en_Auto3565   "3D Viewer Camera Properties"
#define fr_Auto3565   "PropriŠtes de la vue du projet"
#define it_Auto3565   "3D Viewer Camera Properties"
#define es_Auto3565   "3D Viewer Camera Properties"
#define de_Auto3565   "3D Viewer Camera Properties"
#define nl_Auto3565   "3D Viewer Camera Properties"
#define pt_Auto3565   "3D Viewer Camera Properties"
#define xx_Auto3565   "3D Viewer Camera Properties"
#define en__Auto3565   ""
#define fr__Auto3565   ""
#define it__Auto3565   ""
#define es__Auto3565   ""
#define de__Auto3565   ""
#define nl__Auto3565   ""
#define pt__Auto3565   ""
#define xx__Auto3565   ""
#define en_Auto3566   "3D Object Cube Properties"
#define fr_Auto3566   "PropriŠtes de la Vue du Projet"
#define it_Auto3566   "3D Object Cube Properties"
#define es_Auto3566   "3D Object Cube Properties"
#define de_Auto3566   "3D Object Cube Properties"
#define nl_Auto3566   "3D Object Cube Properties"
#define pt_Auto3566   "3D Object Cube Properties"
#define xx_Auto3566   "3D Object Cube Properties"
#define en__Auto3566   ""
#define en_Auto3567   "3D Object Cube Properties"
#define fr_Auto3567   "PropriŠtes de la Vue du Projet"
#define it_Auto3567   "3D Object Cube Properties"
#define es_Auto3567   "3D Object Cube Properties"
#define de_Auto3567   "3D Object Cube Properties"
#define nl_Auto3567   "3D Object Cube Properties"
#define pt_Auto3567   "3D Object Cube Properties"
#define xx_Auto3567   "3D Object Cube Properties"
#define en__Auto3567   ""
#define en_Auto3568   "Forms Model Default Stylesheet"
#define fr_Auto3568   "PropriŠtes de la Vue du Projet"
#define it_Auto3568   "3D Object Cube Properties"
#define es_Auto3568   "3D Object Cube Properties"
#define de_Auto3568   "3D Object Cube Properties"
#define nl_Auto3568   "3D Object Cube Properties"
#define pt_Auto3568   "3D Object Cube Properties"
#define xx_Auto3568   "3D Object Cube Properties"
#define en__Auto3568   ""
#define en_Auto3569   "Project Name"
#define fr_Auto3569   "Nom de projet"
#define it_Auto3569   "Project Name"
#define es_Auto3569   "Project Name"
#define de_Auto3569   "Projekt Name"
#define nl_Auto3569   "Project Name"
#define pt_Auto3569   "Project Name"
#define xx_Auto3569   "Project Name"
#define en__Auto3569   ""
#define fr__Auto3569   ""
#define en_Auto3570   "Position"
#define fr_Auto3570   "Position"
#define it_Auto3570   "Position"
#define es_Auto3570   "Position"
#define de_Auto3570   "Position"
#define nl_Auto3570   "Position"
#define pt_Auto3570   "Position"
#define xx_Auto3570   "Position"
#define en_Auto3571   "Focus"
#define fr_Auto3571   "Focus"
#define it_Auto3571   "Focus"
#define es_Auto3571   "Focus"
#define de_Auto3571   "Focus"
#define nl_Auto3571   "Focus"
#define pt_Auto3571   "Focus"
#define xx_Auto3571   "Focus"
#define en_Auto3572   "Direction"
#define fr_Auto3572   "Direction"
#define it_Auto3572   "Direction"
#define es_Auto3572   "Direction"
#define de_Auto3572   "Direction"
#define nl_Auto3572   "Direction"
#define pt_Auto3572   "Direction"
#define xx_Auto3572   "Direction"
#define en_Auto3573   "Step"
#define fr_Auto3573   "Pas"
#define it_Auto3573   "Step"
#define es_Auto3573   "Step"
#define de_Auto3573   "Step"
#define nl_Auto3573   "Step"
#define pt_Auto3573   "Step"
#define xx_Auto3573   "Step"
#define en__Auto3573   ""
#define fr__Auto3573   ""
#define en_Auto3574   "Image Type"
#define fr_Auto3574   "Type"
#define it_Auto3574   "Type"
#define es_Auto3574   "Type"
#define de_Auto3574   "Type"
#define nl_Auto3574   "Type"
#define pt_Auto3574   "Type"
#define xx_Auto3574   "Type"
#define en__Auto3574   ""
#define fr__Auto3574   ""
#define en_Auto3575   "Default Style"
#define fr_Auto3575   "Type"
#define it_Auto3575   "Type"
#define es_Auto3575   "Type"
#define de_Auto3575   "Type"
#define nl_Auto3575   "Type"
#define pt_Auto3575   "Type"
#define xx_Auto3575   "Type"
#define en__Auto3575   ""
#define fr__Auto3575   ""
#define en_Auto3576   "X"
#define fr_Auto3576   "X"
#define it_Auto3576   "X"
#define es_Auto3576   "X"
#define de_Auto3576   "X"
#define nl_Auto3576   "X"
#define pt_Auto3576   "X"
#define xx_Auto3576   "X"
#define en_Auto3577   "Y"
#define fr_Auto3577   "Y"
#define it_Auto3577   "Y"
#define es_Auto3577   "Y"
#define de_Auto3577   "Y"
#define nl_Auto3577   "Y"
#define pt_Auto3577   "Y"
#define xx_Auto3577   "Y"
#define en_Auto3578   "Z"
#define fr_Auto3578   "Z"
#define it_Auto3578   "Z"
#define es_Auto3578   "Z"
#define de_Auto3578   "Z"
#define nl_Auto3578   "Z"
#define pt_Auto3578   "Z"
#define xx_Auto3578   "Z"
#define en_Auto3579   "X"
#define fr_Auto3579   "X"
#define it_Auto3579   "X"
#define es_Auto3579   "X"
#define de_Auto3579   "X"
#define nl_Auto3579   "X"
#define pt_Auto3579   "X"
#define xx_Auto3579   "X"
#define en_Auto3580   "Y"
#define fr_Auto3580   "Y"
#define it_Auto3580   "Y"
#define es_Auto3580   "Y"
#define de_Auto3580   "Y"
#define nl_Auto3580   "Y"
#define pt_Auto3580   "Y"
#define xx_Auto3580   "Y"
#define en_Auto3581   "Sizes"
#define fr_Auto3581   "Dimensions"
#define it_Auto3581   "Sizes"
#define es_Auto3581   "Sizes"
#define de_Auto3581   "Sizes"
#define nl_Auto3581   "Sizes"
#define pt_Auto3581   "Sizes"
#define xx_Auto3581   "Sizes"
#define en__Auto3581   ""
#define fr__Auto3581   ""
#define en_Auto3582   "Distance"
#define fr_Auto3582   "Distance"
#define it_Auto3582   "Distance"
#define es_Auto3582   "Distance"
#define de_Auto3582   "Distance"
#define nl_Auto3582   "Distance"
#define pt_Auto3582   "Distance"
#define xx_Auto3582   "Distance"
#define en__Auto3582   ""
#define fr__Auto3582   ""
#define en_Auto3583   "X"
#define fr_Auto3583   "X"
#define it_Auto3583   "X"
#define es_Auto3583   "X"
#define de_Auto3583   "X"
#define nl_Auto3583   "X"
#define pt_Auto3583   "X"
#define xx_Auto3583   "X"
#define en__Auto3583   ""
#define fr__Auto3583   ""
#define en_Auto3584   "Y"
#define fr_Auto3584   "Y"
#define it_Auto3584   "Y"
#define es_Auto3584   "Y"
#define de_Auto3584   "Y"
#define nl_Auto3584   "Y"
#define pt_Auto3584   "Y"
#define xx_Auto3584   "Y"
#define en__Auto3584   ""
#define fr__Auto3584   ""
#define en_Auto3585   "Z"
#define fr_Auto3585   "Z"
#define it_Auto3585   "Z"
#define es_Auto3585   "Z"
#define de_Auto3585   "Z"
#define nl_Auto3585   "Z"
#define pt_Auto3585   "Z"
#define xx_Auto3585   "Z"
#define en__Auto3585   ""
#define fr__Auto3585   ""
#define en_Name   ""
#define en_DynamicSize   "&AutoSize"
#define fr_DynamicSize   "Taille &Automatique"
#define it_DynamicSize   "AutoSize"
#define es_DynamicSize   "AutoSize"
#define de_DynamicSize   "AutoSize"
#define nl_DynamicSize   "AutoSize"
#define pt_DynamicSize   "AutoSize"
#define xx_DynamicSize   "AutoSize"
#define en__DynamicSize   ""
#define fr__DynamicSize   ""
#define en_Direction   "forward|backward|left|right|up|down"
#define fr_Direction   "devant|deriŠre|gauche|droite|haut|bas"
#define it_Direction   "forward|backward|left|right|up|down"
#define es_Direction   "forward|backward|left|right|up|down"
#define de_Direction   "forward|backward|left|right|up|down"
#define nl_Direction   "forward|backward|left|right|up|down"
#define pt_Direction   "forward|backward|left|right|up|down"
#define xx_Direction   "forward|backward|left|right|up|down"
#define en__Direction   ""
#define fr__Direction   ""
#define it__Direction   ""
#define es__Direction   ""
#define de__Direction   ""
#define nl__Direction   ""
#define pt__Direction   ""
#define xx__Direction   ""
#define en_Accept   "ok.gif"
#define fr_Accept   "ok.gif"
#define it_Accept   "ok.gif"
#define es_Accept   "ok.gif"
#define de_Accept   "ok.gif"
#define nl_Accept   "ok.gif"
#define pt_Accept   "ok.gif"
#define xx_Accept   "ok.gif"
#define en__Accept   ""
#define fr__Accept   ""
#define it__Accept   ""
#define es__Accept   ""
#define de__Accept   ""
#define nl__Accept   ""
#define pt__Accept   ""
#define xx__Accept   ""
#define en_Cancel   "cancel.gif"
#define fr_Cancel   "cancel.gif"
#define it_Cancel   "cancel.gif"
#define es_Cancel   "cancel.gif"
#define de_Cancel   "cancel.gif"
#define nl_Cancel   "cancel.gif"
#define pt_Cancel   "cancel.gif"
#define xx_Cancel   "cancel.gif"
#define en__Cancel   ""
#define fr__Cancel   ""
#define it__Cancel   ""
#define es__Cancel   ""
#define de__Cancel   ""
#define nl__Cancel   ""
#define pt__Cancel   ""
#define xx__Cancel   ""
#define en_NbX   ""
#define fr_NbX   ""
#define en__NbX   ""
#define fr__NbX   ""
#define en_nbY   ""
#define fr_nbY   ""
#define en__nbY   ""
#define fr__nbY   ""
#define en_NbZ   ""
#define fr_NbZ   ""
#define en__NbZ   ""
#define fr__NbZ   ""
#define en_Step   ""
#define fr_Step   ""
#define en__Step   ""
#define fr__Step   ""
#define en_StepX   ""
#define fr_StepX   ""
#define en__StepX   ""
#define fr__StepX   ""
#define en_StepY   ""
#define fr_StepY   ""
#define en__StepY   ""
#define fr__StepY   ""
#define en_StepZ   ""
#define fr_StepZ   ""
#define en__StepZ   ""
#define fr__StepZ   ""
#define en__ImageFormat   ""
#define fr__ImageFormat   ""
#define it__ImageFormat   ""
#define es__ImageFormat   ""
#define de__ImageFormat   ""
#define nl__ImageFormat   ""
#define pt__ImageFormat   ""
#define xx__ImageFormat   ""
#define en_ForceCIT   "Set Image Types"
#define fr_ForceCIT   "Affecteur types d'images"
#define it_ForceCIT   "Set Image Types"
#define es_ForceCIT   "Set Image Types"
#define de_ForceCIT   "Set Image Types"
#define nl_ForceCIT   "Set Image Types"
#define pt_ForceCIT   "Set Image Types"
#define xx_ForceCIT   "Set Image Types"
#define en__ForceCIT   ""
#define fr__ForceCIT   ""
#define it__ForceCIT   ""
#define es__ForceCIT   ""
#define de__ForceCIT   ""
#define nl__ForceCIT   ""
#define pt__ForceCIT   ""
#define xx__ForceCIT   ""
#define en_DefaultStyle   ""
#define en__DefaultStyle   ""

private struct accept_camera_properties_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[2+1];
	char * msg_Auto3536[8];
	char * hint_Auto3536[8];
	int	x_Auto3536;
	int	y_Auto3536;
	int	w_Auto3536;
	int	h_Auto3536;
	char * msg_Auto3537[8];
	int	trigger_Auto3537;
	char * hint_Auto3537[8];
	int	page_number;
	char * msg_Auto3538[8];
	char * hint_Auto3538[8];
	char * hint_Auto3539[8];
	char * hint_Auto3540[8];
	char * hint_Auto3541[8];
	char * hint_Auto3542[8];
	char * msg_Auto3543[8];
	char * hint_Auto3543[8];
	char * msg_TitreDataBase[8];
	char * hint_TitreDataBase[8];
	char * msg_Auto3544[8];
	char * hint_Auto3544[8];
	char * msg_Auto3545[8];
	char * hint_Auto3545[8];
	char * msg_Auto3546[8];
	char * hint_Auto3546[8];
	char * msg_Auto3547[8];
	char * hint_Auto3547[8];
	char * msg_Auto3548[8];
	char * hint_Auto3548[8];
	char * msg_Auto3549[8];
	char * hint_Auto3549[8];
	char * msg_Auto3550[8];
	char * hint_Auto3550[8];
	char * msg_Auto3551[8];
	char * hint_Auto3551[8];
	char * msg_Auto3552[8];
	char * hint_Auto3552[8];
	char * msg_auto702[8];
	char * hint_auto702[8];
	char * msg_Auto3553[8];
	char * hint_Auto3553[8];
	char * msg_Auto3554[8];
	char * hint_Auto3554[8];
	char * hint_Configuration[8];
	char	buffer_Configuration[256];
	char * hint_DataBase[8];
	char	buffer_DataBase[256];
	char * hint_Template[8];
	char	buffer_Template[256];
	char * hint_Modules[8];
	char	buffer_Modules[401];
	char * hint_Components[8];
	char	buffer_Components[401];
	char * hint_FormsDirectory[8];
	char	buffer_FormsDirectory[256];
	char * hint_SourcesDirectory[8];
	char	buffer_SourcesDirectory[256];
	char * hint_ObjectsDirectory[8];
	char	buffer_ObjectsDirectory[256];
	char * hint_PaletteName[8];
	char	buffer_PaletteName[256];
	char * hint_ImageName[8];
	char	buffer_ImageName[256];
	char * msg_ImageType[8];
	char * hint_ImageType[8];
	int	value_ImageType;
	char * msg_Quality[8];
	int	trigger_Quality;
	char * hint_Quality[8];
	int	value_Quality;
	char * msg_SaveImages[8];
	int	trigger_SaveImages;
	char * hint_SaveImages[8];
	int	value_SaveImages;
	char * hint_Colour[8];
	char	buffer_Colour[11];
	char * msg_ApplyStyle[8];
	int	trigger_ApplyStyle;
	char * hint_ApplyStyle[8];
	int	value_ApplyStyle;
	char * msg_SaveForms[8];
	int	trigger_SaveForms;
	char * hint_SaveForms[8];
	int	value_SaveForms;
	char * msg_NationalLanguage[8];
	char * hint_NationalLanguage[8];
	int	value_NationalLanguage;
	char * msg_RollBack[8];
	int	trigger_RollBack;
	char * hint_RollBack[8];
	int	value_RollBack;
	char * msg_CameraLock[8];
	int	trigger_CameraLock;
	char * hint_CameraLock[8];
	int	value_CameraLock;
	char * msg_Extension[8];
	char * hint_Extension[8];
	int	value_Extension;
	char * msg_Select[8];
	int	trigger_Select;
	char * hint_Select[8];
	char * msg_Auto3555[8];
	int	trigger_Auto3555;
	char * hint_Auto3555[8];
	char * msg_fgSelect[8];
	int	trigger_fgSelect;
	char * hint_fgSelect[8];
	char * msg_Choixfconf[8];
	int	trigger_Choixfconf;
	char * hint_Choixfconf[8];
	char * msg_ChoixBase[8];
	int	trigger_ChoixBase;
	char * hint_ChoixBase[8];
	char * msg_ChoixTemplate[8];
	int	trigger_ChoixTemplate;
	char * hint_ChoixTemplate[8];
	char * msg_ChoixModules[8];
	int	trigger_ChoixModules;
	char * hint_ChoixModules[8];
	char * msg_ChooseComponents[8];
	int	trigger_ChooseComponents;
	char * hint_ChooseComponents[8];
	char * msg_Auto3556[8];
	int	trigger_Auto3556;
	char * hint_Auto3556[8];
	char * msg_Auto3557[8];
	int	trigger_Auto3557;
	char * hint_Auto3557[8];
	char * msg_Auto3558[8];
	int	trigger_Auto3558;
	char * hint_Auto3558[8];
	char * msg_Auto3559[8];
	int	trigger_Auto3559;
	char * hint_Auto3559[8];
	char * hint_Auto3560[8];
	char * hint_Auto3561[8];
	char * hint_Auto3562[8];
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
	char * hint_Auto3568[8];
	char * msg_Auto3569[8];
	char * hint_Auto3569[8];
	char * msg_Auto3570[8];
	char * hint_Auto3570[8];
	char * msg_Auto3571[8];
	char * hint_Auto3571[8];
	char * msg_Auto3572[8];
	char * hint_Auto3572[8];
	char * msg_Auto3573[8];
	char * hint_Auto3573[8];
	char * msg_Auto3574[8];
	char * hint_Auto3574[8];
	char * msg_Auto3575[8];
	char * hint_Auto3575[8];
	char * msg_Auto3576[8];
	char * hint_Auto3576[8];
	char * msg_Auto3577[8];
	char * hint_Auto3577[8];
	char * msg_Auto3578[8];
	char * hint_Auto3578[8];
	char * msg_Auto3579[8];
	char * hint_Auto3579[8];
	char * msg_Auto3580[8];
	char * hint_Auto3580[8];
	char * msg_Auto3581[8];
	char * hint_Auto3581[8];
	char * msg_Auto3582[8];
	char * hint_Auto3582[8];
	char * msg_Auto3583[8];
	char * hint_Auto3583[8];
	char * msg_Auto3584[8];
	char * hint_Auto3584[8];
	char * msg_Auto3585[8];
	char * hint_Auto3585[8];
	char * hint_Name[8];
	char	buffer_Name[256];
	char * hint_AtX[8];
	char	buffer_AtX[12];
	char * hint_AtY[8];
	char	buffer_AtY[12];
	char * hint_AtZ[8];
	char	buffer_AtZ[11];
	char * msg_DynamicSize[8];
	int	trigger_DynamicSize;
	char * hint_DynamicSize[8];
	int	value_DynamicSize;
	char * hint_ToX[8];
	char	buffer_ToX[12];
	char * hint_ToY[8];
	char	buffer_ToY[12];
	char * msg_Direction[8];
	char * hint_Direction[8];
	int	value_Direction;
	char * msg_Accept[8];
	int	trigger_Accept;
	char * hint_Accept[8];
	char * msg_Cancel[8];
	int	trigger_Cancel;
	char * hint_Cancel[8];
	char * hint_NbX[8];
	char	buffer_NbX[12];
	char * hint_nbY[8];
	char	buffer_nbY[12];
	char * hint_NbZ[8];
	char	buffer_NbZ[11];
	char * hint_Step[8];
	char	buffer_Step[12];
	char * hint_StepX[8];
	char	buffer_StepX[12];
	char * hint_StepY[8];
	char	buffer_StepY[12];
	char * hint_StepZ[8];
	char	buffer_StepZ[11];
	char * msg_ImageFormat[8];
	char * hint_ImageFormat[8];
	int	value_ImageFormat;
	char * msg_ForceCIT[8];
	int	trigger_ForceCIT;
	char * hint_ForceCIT[8];
	int	value_ForceCIT;
	char * hint_DefaultStyle[8];
	char	buffer_DefaultStyle[58];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[39];
	};
static int	vfh[16];
private int on_Select_event(struct accept_camera_properties_context * _Context);
private int on_Auto3555_event(struct accept_camera_properties_context * _Context);
private int on_fgSelect_event(struct accept_camera_properties_context * _Context);
private int on_Choixfconf_event(struct accept_camera_properties_context * _Context);
private int on_ChoixBase_event(struct accept_camera_properties_context * _Context);
private int on_ChoixTemplate_event(struct accept_camera_properties_context * _Context);
private int on_ChoixModules_event(struct accept_camera_properties_context * _Context);
private int on_ChooseComponents_event(struct accept_camera_properties_context * _Context);
private int on_Auto3556_event(struct accept_camera_properties_context * _Context);
private int on_Auto3557_event(struct accept_camera_properties_context * _Context);
private int on_Auto3558_event(struct accept_camera_properties_context * _Context);
private int on_Accept_event(struct accept_camera_properties_context * _Context);
private int on_Cancel_event(struct accept_camera_properties_context * _Context);

public	int	accept_camera_properties_create(
	struct accept_camera_properties_context ** cptr,
	char * pConfiguration,
	char * pDataBase,
	char * pTemplate,
	char * pModules,
	char * pComponents,
	char * pFormsDirectory,
	char * pSourcesDirectory,
	char * pObjectsDirectory,
	char * pPaletteName,
	char * pImageName,
	char * pImageType,
	char * pQuality,
	char * pSaveImages,
	char * pColour,
	char * pApplyStyle,
	char * pSaveForms,
	char * pNationalLanguage,
	char * pRollBack,
	char * pCameraLock,
	char * pExtension,
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pDynamicSize,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStep,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pImageFormat,
	char * pForceCIT,
	char * pDefaultStyle)
{

	int i;
	struct accept_camera_properties_context * _Context=(struct accept_camera_properties_context*)0;
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
	if (!(_Context = allocate( sizeof( struct accept_camera_properties_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=54;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSWWWWWWWWWWSWWWWWWWWWWWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_Configuration, 255, pConfiguration);
		visual_transferin(_Context->buffer_DataBase, 255, pDataBase);
		visual_transferin(_Context->buffer_Template, 255, pTemplate);
		visual_transferin(_Context->buffer_Modules, 400, pModules);
		visual_transferin(_Context->buffer_Components, 400, pComponents);
		visual_transferin(_Context->buffer_FormsDirectory, 255, pFormsDirectory);
		visual_transferin(_Context->buffer_SourcesDirectory, 255, pSourcesDirectory);
		visual_transferin(_Context->buffer_ObjectsDirectory, 255, pObjectsDirectory);
		visual_transferin(_Context->buffer_PaletteName, 255, pPaletteName);
		visual_transferin(_Context->buffer_ImageName, 255, pImageName);
		visual_transferin((void *) 0, 0, pImageType);
		if (!( pImageType )) _Context->value_ImageType=0;
		else	_Context->value_ImageType = *((int *)pImageType);
		visual_transferin((void *) 0, 0, pQuality);
		if (!( pQuality )) _Context->value_Quality=0;
		else	_Context->value_Quality = *((int *)pQuality);
		visual_transferin((void *) 0, 0, pSaveImages);
		if (!( pSaveImages )) _Context->value_SaveImages=0;
		else	_Context->value_SaveImages = *((int *)pSaveImages);
		visual_transferin(_Context->buffer_Colour, 10, pColour);
		visual_transferin((void *) 0, 0, pApplyStyle);
		if (!( pApplyStyle )) _Context->value_ApplyStyle=0;
		else	_Context->value_ApplyStyle = *((int *)pApplyStyle);
		visual_transferin((void *) 0, 0, pSaveForms);
		if (!( pSaveForms )) _Context->value_SaveForms=0;
		else	_Context->value_SaveForms = *((int *)pSaveForms);
		visual_transferin((void *) 0, 0, pNationalLanguage);
		if (!( pNationalLanguage )) _Context->value_NationalLanguage=0;
		else	_Context->value_NationalLanguage = *((int *)pNationalLanguage);
		visual_transferin((void *) 0, 0, pRollBack);
		if (!( pRollBack )) _Context->value_RollBack=0;
		else	_Context->value_RollBack = *((int *)pRollBack);
		visual_transferin((void *) 0, 0, pCameraLock);
		if (!( pCameraLock )) _Context->value_CameraLock=0;
		else	_Context->value_CameraLock = *((int *)pCameraLock);
		visual_transferin((void *) 0, 0, pExtension);
		if (!( pExtension )) _Context->value_Extension=0;
		else	_Context->value_Extension = *((int *)pExtension);
		visual_transferin(_Context->buffer_Name, 255, pName);
		visual_transferin(_Context->buffer_AtX, 11, pAtX);
		visual_transferin(_Context->buffer_AtY, 11, pAtY);
		visual_transferin(_Context->buffer_AtZ, 10, pAtZ);
		visual_transferin((void *) 0, 0, pDynamicSize);
		if (!( pDynamicSize )) _Context->value_DynamicSize=0;
		else	_Context->value_DynamicSize = *((int *)pDynamicSize);
		visual_transferin(_Context->buffer_ToX, 11, pToX);
		visual_transferin(_Context->buffer_ToY, 11, pToY);
		visual_transferin((void *) 0, 0, pDirection);
		if (!( pDirection )) _Context->value_Direction=0;
		else	_Context->value_Direction = *((int *)pDirection);
		visual_transferin(_Context->buffer_NbX, 11, pNbX);
		visual_transferin(_Context->buffer_nbY, 11, pnbY);
		visual_transferin(_Context->buffer_NbZ, 10, pNbZ);
		visual_transferin(_Context->buffer_Step, 11, pStep);
		visual_transferin(_Context->buffer_StepX, 11, pStepX);
		visual_transferin(_Context->buffer_StepY, 11, pStepY);
		visual_transferin(_Context->buffer_StepZ, 10, pStepZ);
		visual_transferin((void *) 0, 0, pImageFormat);
		if (!( pImageFormat )) _Context->value_ImageFormat=0;
		else	_Context->value_ImageFormat = *((int *)pImageFormat);
		visual_transferin((void *) 0, 0, pForceCIT);
		if (!( pForceCIT )) _Context->value_ForceCIT=0;
		else	_Context->value_ForceCIT = *((int *)pForceCIT);
		visual_transferin(_Context->buffer_DefaultStyle, 57, pDefaultStyle);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto3536[i]=" ";
	_Context->hint_Auto3536[0]=en__Auto3536;
	_Context->hint_Auto3536[1]=fr__Auto3536;
	_Context->hint_Auto3536[2]=it__Auto3536;
	_Context->hint_Auto3536[3]=es__Auto3536;
	_Context->hint_Auto3536[4]=de__Auto3536;
	_Context->hint_Auto3536[5]=nl__Auto3536;
	_Context->hint_Auto3536[6]=pt__Auto3536;
	_Context->hint_Auto3536[7]=xx__Auto3536;
	_Context->x_Auto3536=85;
	_Context->y_Auto3536=15;
	_Context->w_Auto3536=630;
	_Context->h_Auto3536=570;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto3537[i]=" ";
	_Context->msg_Auto3537[0]=en_Auto3537;
	_Context->msg_Auto3537[1]=fr_Auto3537;
	_Context->msg_Auto3537[2]=it_Auto3537;
	_Context->msg_Auto3537[3]=es_Auto3537;
	_Context->msg_Auto3537[4]=de_Auto3537;
	_Context->msg_Auto3537[5]=nl_Auto3537;
	_Context->msg_Auto3537[6]=pt_Auto3537;
	_Context->msg_Auto3537[7]=xx_Auto3537;
	_Context->hint_Auto3537[0]=en__Auto3537;
	_Context->hint_Auto3537[1]=fr__Auto3537;
	_Context->hint_Auto3537[2]=it__Auto3537;
	_Context->hint_Auto3537[3]=es__Auto3537;
	_Context->hint_Auto3537[4]=de__Auto3537;
	_Context->hint_Auto3537[5]=nl__Auto3537;
	_Context->hint_Auto3537[6]=pt__Auto3537;
	_Context->hint_Auto3537[7]=xx__Auto3537;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto3538[i]=" ";
	_Context->msg_Auto3538[0]=en_Auto3538;
	_Context->msg_Auto3538[1]=fr_Auto3538;
	_Context->msg_Auto3538[2]=it_Auto3538;
	_Context->msg_Auto3538[3]=es_Auto3538;
	_Context->msg_Auto3538[4]=de_Auto3538;
	_Context->msg_Auto3538[5]=nl_Auto3538;
	_Context->msg_Auto3538[6]=pt_Auto3538;
	_Context->msg_Auto3538[7]=xx_Auto3538;
	_Context->hint_Auto3538[0]=en__Auto3538;
	for (i=0; i < 8; i++)_Context->msg_Auto3543[i]=" ";
	_Context->msg_Auto3543[0]=en_Auto3543;
	_Context->msg_Auto3543[1]=fr_Auto3543;
	_Context->msg_Auto3543[2]=it_Auto3543;
	_Context->msg_Auto3543[3]=es_Auto3543;
	_Context->msg_Auto3543[4]=de_Auto3543;
	_Context->msg_Auto3543[5]=nl_Auto3543;
	_Context->msg_Auto3543[6]=pt_Auto3543;
	_Context->msg_Auto3543[7]=xx_Auto3543;
	for (i=0; i < 8; i++)_Context->msg_TitreDataBase[i]=" ";
	_Context->msg_TitreDataBase[0]=en_TitreDataBase;
	_Context->msg_TitreDataBase[1]=fr_TitreDataBase;
	_Context->msg_TitreDataBase[2]=it_TitreDataBase;
	_Context->msg_TitreDataBase[3]=es_TitreDataBase;
	_Context->msg_TitreDataBase[4]=de_TitreDataBase;
	_Context->msg_TitreDataBase[5]=nl_TitreDataBase;
	_Context->msg_TitreDataBase[6]=pt_TitreDataBase;
	_Context->msg_TitreDataBase[7]=xx_TitreDataBase;
	_Context->hint_TitreDataBase[0]=en__TitreDataBase;
	_Context->hint_TitreDataBase[1]=fr__TitreDataBase;
	_Context->hint_TitreDataBase[2]=it__TitreDataBase;
	_Context->hint_TitreDataBase[3]=es__TitreDataBase;
	_Context->hint_TitreDataBase[4]=de__TitreDataBase;
	_Context->hint_TitreDataBase[5]=nl__TitreDataBase;
	_Context->hint_TitreDataBase[6]=pt__TitreDataBase;
	_Context->hint_TitreDataBase[7]=xx__TitreDataBase;
	for (i=0; i < 8; i++)_Context->msg_Auto3544[i]=" ";
	_Context->msg_Auto3544[0]=en_Auto3544;
	_Context->msg_Auto3544[1]=fr_Auto3544;
	_Context->msg_Auto3544[2]=it_Auto3544;
	_Context->msg_Auto3544[3]=es_Auto3544;
	_Context->msg_Auto3544[4]=de_Auto3544;
	_Context->msg_Auto3544[5]=nl_Auto3544;
	_Context->msg_Auto3544[6]=pt_Auto3544;
	_Context->msg_Auto3544[7]=xx_Auto3544;
	_Context->hint_Auto3544[0]=en__Auto3544;
	for (i=0; i < 8; i++)_Context->msg_Auto3545[i]=" ";
	_Context->msg_Auto3545[0]=en_Auto3545;
	_Context->msg_Auto3545[1]=fr_Auto3545;
	_Context->msg_Auto3545[2]=it_Auto3545;
	_Context->msg_Auto3545[3]=es_Auto3545;
	_Context->msg_Auto3545[4]=de_Auto3545;
	_Context->msg_Auto3545[5]=nl_Auto3545;
	_Context->msg_Auto3545[6]=pt_Auto3545;
	_Context->msg_Auto3545[7]=xx_Auto3545;
	_Context->hint_Auto3545[0]=en__Auto3545;
	_Context->hint_Auto3545[1]=fr__Auto3545;
	for (i=0; i < 8; i++)_Context->msg_Auto3546[i]=" ";
	_Context->msg_Auto3546[0]=en_Auto3546;
	_Context->msg_Auto3546[1]=fr_Auto3546;
	_Context->msg_Auto3546[2]=it_Auto3546;
	_Context->msg_Auto3546[3]=es_Auto3546;
	_Context->msg_Auto3546[4]=de_Auto3546;
	_Context->msg_Auto3546[5]=nl_Auto3546;
	_Context->msg_Auto3546[6]=pt_Auto3546;
	_Context->msg_Auto3546[7]=xx_Auto3546;
	_Context->hint_Auto3546[0]=en__Auto3546;
	_Context->hint_Auto3546[1]=fr__Auto3546;
	_Context->hint_Auto3546[2]=it__Auto3546;
	_Context->hint_Auto3546[3]=es__Auto3546;
	_Context->hint_Auto3546[4]=de__Auto3546;
	_Context->hint_Auto3546[5]=nl__Auto3546;
	_Context->hint_Auto3546[6]=pt__Auto3546;
	_Context->hint_Auto3546[7]=xx__Auto3546;
	for (i=0; i < 8; i++)_Context->msg_Auto3547[i]=" ";
	_Context->msg_Auto3547[0]=en_Auto3547;
	_Context->msg_Auto3547[1]=fr_Auto3547;
	_Context->msg_Auto3547[2]=it_Auto3547;
	_Context->msg_Auto3547[3]=es_Auto3547;
	_Context->msg_Auto3547[4]=de_Auto3547;
	_Context->msg_Auto3547[5]=nl_Auto3547;
	_Context->msg_Auto3547[6]=pt_Auto3547;
	_Context->msg_Auto3547[7]=xx_Auto3547;
	_Context->hint_Auto3547[0]=en__Auto3547;
	_Context->hint_Auto3547[1]=fr__Auto3547;
	_Context->hint_Auto3547[2]=it__Auto3547;
	_Context->hint_Auto3547[3]=es__Auto3547;
	_Context->hint_Auto3547[4]=de__Auto3547;
	_Context->hint_Auto3547[5]=nl__Auto3547;
	_Context->hint_Auto3547[6]=pt__Auto3547;
	_Context->hint_Auto3547[7]=xx__Auto3547;
	for (i=0; i < 8; i++)_Context->msg_Auto3548[i]=" ";
	_Context->msg_Auto3548[0]=en_Auto3548;
	_Context->msg_Auto3548[1]=fr_Auto3548;
	_Context->msg_Auto3548[2]=it_Auto3548;
	_Context->msg_Auto3548[3]=es_Auto3548;
	_Context->msg_Auto3548[4]=de_Auto3548;
	_Context->msg_Auto3548[5]=nl_Auto3548;
	_Context->msg_Auto3548[6]=pt_Auto3548;
	_Context->msg_Auto3548[7]=xx_Auto3548;
	_Context->hint_Auto3548[0]=en__Auto3548;
	_Context->hint_Auto3548[1]=fr__Auto3548;
	_Context->hint_Auto3548[2]=it__Auto3548;
	_Context->hint_Auto3548[3]=es__Auto3548;
	_Context->hint_Auto3548[4]=de__Auto3548;
	_Context->hint_Auto3548[5]=nl__Auto3548;
	_Context->hint_Auto3548[6]=pt__Auto3548;
	_Context->hint_Auto3548[7]=xx__Auto3548;
	for (i=0; i < 8; i++)_Context->msg_Auto3549[i]=" ";
	_Context->msg_Auto3549[0]=en_Auto3549;
	_Context->msg_Auto3549[1]=fr_Auto3549;
	_Context->msg_Auto3549[2]=it_Auto3549;
	_Context->msg_Auto3549[3]=es_Auto3549;
	_Context->msg_Auto3549[4]=de_Auto3549;
	_Context->msg_Auto3549[5]=nl_Auto3549;
	_Context->msg_Auto3549[6]=pt_Auto3549;
	_Context->msg_Auto3549[7]=xx_Auto3549;
	_Context->hint_Auto3549[0]=en__Auto3549;
	_Context->hint_Auto3549[1]=fr__Auto3549;
	_Context->hint_Auto3549[2]=it__Auto3549;
	_Context->hint_Auto3549[3]=es__Auto3549;
	_Context->hint_Auto3549[4]=de__Auto3549;
	_Context->hint_Auto3549[5]=nl__Auto3549;
	_Context->hint_Auto3549[6]=pt__Auto3549;
	_Context->hint_Auto3549[7]=xx__Auto3549;
	for (i=0; i < 8; i++)_Context->msg_Auto3550[i]=" ";
	_Context->msg_Auto3550[0]=en_Auto3550;
	_Context->msg_Auto3550[1]=fr_Auto3550;
	_Context->msg_Auto3550[2]=it_Auto3550;
	_Context->msg_Auto3550[3]=es_Auto3550;
	_Context->msg_Auto3550[4]=de_Auto3550;
	_Context->msg_Auto3550[5]=nl_Auto3550;
	_Context->msg_Auto3550[6]=pt_Auto3550;
	_Context->msg_Auto3550[7]=xx_Auto3550;
	_Context->hint_Auto3550[0]=en__Auto3550;
	_Context->hint_Auto3550[1]=fr__Auto3550;
	for (i=0; i < 8; i++)_Context->msg_Auto3551[i]=" ";
	_Context->msg_Auto3551[0]=en_Auto3551;
	_Context->msg_Auto3551[1]=fr_Auto3551;
	_Context->msg_Auto3551[2]=it_Auto3551;
	_Context->msg_Auto3551[3]=es_Auto3551;
	_Context->msg_Auto3551[4]=de_Auto3551;
	_Context->msg_Auto3551[5]=nl_Auto3551;
	_Context->msg_Auto3551[6]=pt_Auto3551;
	_Context->msg_Auto3551[7]=xx_Auto3551;
	_Context->hint_Auto3551[0]=en__Auto3551;
	_Context->hint_Auto3551[1]=fr__Auto3551;
	_Context->hint_Auto3551[2]=it__Auto3551;
	_Context->hint_Auto3551[3]=es__Auto3551;
	_Context->hint_Auto3551[4]=de__Auto3551;
	_Context->hint_Auto3551[5]=nl__Auto3551;
	_Context->hint_Auto3551[6]=pt__Auto3551;
	_Context->hint_Auto3551[7]=xx__Auto3551;
	for (i=0; i < 8; i++)_Context->msg_Auto3552[i]=" ";
	_Context->msg_Auto3552[0]=en_Auto3552;
	_Context->msg_Auto3552[1]=fr_Auto3552;
	_Context->msg_Auto3552[2]=it_Auto3552;
	_Context->msg_Auto3552[3]=es_Auto3552;
	_Context->msg_Auto3552[4]=de_Auto3552;
	_Context->msg_Auto3552[5]=nl_Auto3552;
	_Context->msg_Auto3552[6]=pt_Auto3552;
	_Context->msg_Auto3552[7]=xx_Auto3552;
	_Context->hint_Auto3552[0]=en__Auto3552;
	_Context->hint_Auto3552[1]=fr__Auto3552;
	_Context->hint_Auto3552[2]=it__Auto3552;
	_Context->hint_Auto3552[3]=es__Auto3552;
	_Context->hint_Auto3552[4]=de__Auto3552;
	_Context->hint_Auto3552[5]=nl__Auto3552;
	_Context->hint_Auto3552[6]=pt__Auto3552;
	_Context->hint_Auto3552[7]=xx__Auto3552;
	for (i=0; i < 8; i++)_Context->msg_auto702[i]=" ";
	_Context->msg_auto702[0]=en_auto702;
	_Context->msg_auto702[1]=fr_auto702;
	_Context->msg_auto702[2]=it_auto702;
	_Context->msg_auto702[3]=es_auto702;
	_Context->msg_auto702[4]=de_auto702;
	_Context->msg_auto702[5]=nl_auto702;
	_Context->msg_auto702[6]=pt_auto702;
	_Context->msg_auto702[7]=xx_auto702;
	_Context->hint_auto702[0]=en__auto702;
	_Context->hint_auto702[1]=fr__auto702;
	_Context->hint_auto702[2]=it__auto702;
	_Context->hint_auto702[3]=es__auto702;
	_Context->hint_auto702[4]=de__auto702;
	_Context->hint_auto702[5]=nl__auto702;
	_Context->hint_auto702[6]=pt__auto702;
	_Context->hint_auto702[7]=xx__auto702;
	for (i=0; i < 8; i++)_Context->msg_Auto3553[i]=" ";
	_Context->msg_Auto3553[0]=en_Auto3553;
	_Context->msg_Auto3553[1]=fr_Auto3553;
	_Context->msg_Auto3553[2]=it_Auto3553;
	_Context->msg_Auto3553[3]=es_Auto3553;
	_Context->msg_Auto3553[4]=de_Auto3553;
	_Context->msg_Auto3553[5]=nl_Auto3553;
	_Context->msg_Auto3553[6]=pt_Auto3553;
	_Context->msg_Auto3553[7]=xx_Auto3553;
	_Context->hint_Auto3553[0]=en__Auto3553;
	_Context->hint_Auto3553[1]=fr__Auto3553;
	_Context->hint_Auto3553[2]=it__Auto3553;
	_Context->hint_Auto3553[3]=es__Auto3553;
	_Context->hint_Auto3553[4]=de__Auto3553;
	_Context->hint_Auto3553[5]=nl__Auto3553;
	_Context->hint_Auto3553[6]=pt__Auto3553;
	_Context->hint_Auto3553[7]=xx__Auto3553;
	for (i=0; i < 8; i++)_Context->msg_Auto3554[i]=" ";
	_Context->msg_Auto3554[0]=en_Auto3554;
	_Context->msg_Auto3554[1]=fr_Auto3554;
	_Context->msg_Auto3554[2]=it_Auto3554;
	_Context->msg_Auto3554[3]=es_Auto3554;
	_Context->msg_Auto3554[4]=de_Auto3554;
	_Context->msg_Auto3554[5]=nl_Auto3554;
	_Context->msg_Auto3554[6]=pt_Auto3554;
	_Context->msg_Auto3554[7]=xx_Auto3554;
	_Context->hint_Auto3554[0]=en__Auto3554;
	_Context->hint_Auto3554[1]=fr__Auto3554;
	_Context->hint_Auto3554[2]=it__Auto3554;
	_Context->hint_Auto3554[3]=es__Auto3554;
	_Context->hint_Auto3554[4]=de__Auto3554;
	_Context->hint_Auto3554[5]=nl__Auto3554;
	_Context->hint_Auto3554[6]=pt__Auto3554;
	_Context->hint_Auto3554[7]=xx__Auto3554;
	_Context->hint_Configuration[0]=en__Configuration;
	_Context->hint_DataBase[0]=en__DataBase;
	_Context->hint_Template[0]=en__Template;
	_Context->hint_Modules[0]=en__Modules;
	_Context->hint_Components[0]=en__Components;
	_Context->hint_FormsDirectory[0]=en__FormsDirectory;
	_Context->hint_FormsDirectory[1]=fr__FormsDirectory;
	_Context->hint_SourcesDirectory[0]=en__SourcesDirectory;
	_Context->hint_SourcesDirectory[1]=fr__SourcesDirectory;
	_Context->hint_ObjectsDirectory[0]=en__ObjectsDirectory;
	_Context->hint_ObjectsDirectory[1]=fr__ObjectsDirectory;
	_Context->hint_PaletteName[0]=en__PaletteName;
	_Context->hint_PaletteName[1]=fr__PaletteName;
	_Context->hint_ImageName[0]=en__ImageName;
	_Context->hint_ImageName[1]=fr__ImageName;
	for (i=0; i < 8; i++)_Context->msg_ImageType[i]=" ";
	_Context->hint_ImageType[0]=en__ImageType;
	_Context->hint_ImageType[1]=fr__ImageType;
	_Context->hint_ImageType[2]=it__ImageType;
	_Context->hint_ImageType[3]=es__ImageType;
	_Context->hint_ImageType[4]=de__ImageType;
	_Context->hint_ImageType[5]=nl__ImageType;
	_Context->hint_ImageType[6]=pt__ImageType;
	_Context->hint_ImageType[7]=xx__ImageType;
	for (i=0; i < 8; i++)_Context->msg_Quality[i]=" ";
	_Context->msg_Quality[0]=en_Quality;
	_Context->msg_Quality[1]=fr_Quality;
	_Context->msg_Quality[2]=it_Quality;
	_Context->msg_Quality[3]=es_Quality;
	_Context->msg_Quality[4]=de_Quality;
	_Context->msg_Quality[5]=nl_Quality;
	_Context->msg_Quality[6]=pt_Quality;
	_Context->msg_Quality[7]=xx_Quality;
	_Context->hint_Quality[0]=en__Quality;
	_Context->hint_Quality[1]=fr__Quality;
	for (i=0; i < 8; i++)_Context->msg_SaveImages[i]=" ";
	_Context->msg_SaveImages[0]=en_SaveImages;
	_Context->msg_SaveImages[1]=fr_SaveImages;
	_Context->msg_SaveImages[2]=it_SaveImages;
	_Context->msg_SaveImages[3]=es_SaveImages;
	_Context->msg_SaveImages[4]=de_SaveImages;
	_Context->msg_SaveImages[5]=nl_SaveImages;
	_Context->msg_SaveImages[6]=pt_SaveImages;
	_Context->msg_SaveImages[7]=xx_SaveImages;
	_Context->hint_SaveImages[0]=en__SaveImages;
	_Context->hint_SaveImages[1]=fr__SaveImages;
	_Context->hint_SaveImages[2]=it__SaveImages;
	_Context->hint_SaveImages[3]=es__SaveImages;
	_Context->hint_SaveImages[4]=de__SaveImages;
	_Context->hint_SaveImages[5]=nl__SaveImages;
	_Context->hint_SaveImages[6]=pt__SaveImages;
	_Context->hint_SaveImages[7]=xx__SaveImages;
	_Context->hint_Colour[0]=en__Colour;
	_Context->hint_Colour[1]=fr__Colour;
	for (i=0; i < 8; i++)_Context->msg_ApplyStyle[i]=" ";
	_Context->msg_ApplyStyle[0]=en_ApplyStyle;
	_Context->msg_ApplyStyle[1]=fr_ApplyStyle;
	_Context->msg_ApplyStyle[2]=it_ApplyStyle;
	_Context->msg_ApplyStyle[3]=es_ApplyStyle;
	_Context->msg_ApplyStyle[4]=de_ApplyStyle;
	_Context->msg_ApplyStyle[5]=nl_ApplyStyle;
	_Context->msg_ApplyStyle[6]=pt_ApplyStyle;
	_Context->msg_ApplyStyle[7]=xx_ApplyStyle;
	_Context->hint_ApplyStyle[0]=en__ApplyStyle;
	_Context->hint_ApplyStyle[1]=fr__ApplyStyle;
	_Context->hint_ApplyStyle[2]=it__ApplyStyle;
	_Context->hint_ApplyStyle[3]=es__ApplyStyle;
	_Context->hint_ApplyStyle[4]=de__ApplyStyle;
	_Context->hint_ApplyStyle[5]=nl__ApplyStyle;
	_Context->hint_ApplyStyle[6]=pt__ApplyStyle;
	_Context->hint_ApplyStyle[7]=xx__ApplyStyle;
	for (i=0; i < 8; i++)_Context->msg_SaveForms[i]=" ";
	_Context->msg_SaveForms[0]=en_SaveForms;
	_Context->msg_SaveForms[1]=fr_SaveForms;
	_Context->msg_SaveForms[2]=it_SaveForms;
	_Context->msg_SaveForms[3]=es_SaveForms;
	_Context->msg_SaveForms[4]=de_SaveForms;
	_Context->msg_SaveForms[5]=nl_SaveForms;
	_Context->msg_SaveForms[6]=pt_SaveForms;
	_Context->msg_SaveForms[7]=xx_SaveForms;
	_Context->hint_SaveForms[0]=en__SaveForms;
	_Context->hint_SaveForms[1]=fr__SaveForms;
	_Context->hint_SaveForms[2]=it__SaveForms;
	_Context->hint_SaveForms[3]=es__SaveForms;
	_Context->hint_SaveForms[4]=de__SaveForms;
	_Context->hint_SaveForms[5]=nl__SaveForms;
	_Context->hint_SaveForms[6]=pt__SaveForms;
	_Context->hint_SaveForms[7]=xx__SaveForms;
	for (i=0; i < 8; i++)_Context->msg_NationalLanguage[i]=" ";
	_Context->hint_NationalLanguage[0]=en__NationalLanguage;
	_Context->hint_NationalLanguage[1]=fr__NationalLanguage;
	_Context->hint_NationalLanguage[2]=it__NationalLanguage;
	_Context->hint_NationalLanguage[3]=es__NationalLanguage;
	_Context->hint_NationalLanguage[4]=de__NationalLanguage;
	_Context->hint_NationalLanguage[5]=nl__NationalLanguage;
	_Context->hint_NationalLanguage[6]=pt__NationalLanguage;
	_Context->hint_NationalLanguage[7]=xx__NationalLanguage;
	for (i=0; i < 8; i++)_Context->msg_RollBack[i]=" ";
	_Context->msg_RollBack[0]=en_RollBack;
	_Context->msg_RollBack[1]=fr_RollBack;
	_Context->msg_RollBack[2]=it_RollBack;
	_Context->msg_RollBack[3]=es_RollBack;
	_Context->msg_RollBack[4]=de_RollBack;
	_Context->msg_RollBack[5]=nl_RollBack;
	_Context->msg_RollBack[6]=pt_RollBack;
	_Context->msg_RollBack[7]=xx_RollBack;
	_Context->hint_RollBack[0]=en__RollBack;
	_Context->hint_RollBack[1]=fr__RollBack;
	_Context->hint_RollBack[2]=it__RollBack;
	_Context->hint_RollBack[3]=es__RollBack;
	_Context->hint_RollBack[4]=de__RollBack;
	_Context->hint_RollBack[5]=nl__RollBack;
	_Context->hint_RollBack[6]=pt__RollBack;
	_Context->hint_RollBack[7]=xx__RollBack;
	for (i=0; i < 8; i++)_Context->msg_CameraLock[i]=" ";
	_Context->msg_CameraLock[0]=en_CameraLock;
	_Context->msg_CameraLock[1]=fr_CameraLock;
	_Context->msg_CameraLock[2]=it_CameraLock;
	_Context->msg_CameraLock[3]=es_CameraLock;
	_Context->msg_CameraLock[4]=de_CameraLock;
	_Context->msg_CameraLock[5]=nl_CameraLock;
	_Context->msg_CameraLock[6]=pt_CameraLock;
	_Context->msg_CameraLock[7]=xx_CameraLock;
	_Context->hint_CameraLock[0]=en__CameraLock;
	_Context->hint_CameraLock[1]=fr__CameraLock;
	_Context->hint_CameraLock[2]=it__CameraLock;
	_Context->hint_CameraLock[3]=es__CameraLock;
	_Context->hint_CameraLock[4]=de__CameraLock;
	_Context->hint_CameraLock[5]=nl__CameraLock;
	_Context->hint_CameraLock[6]=pt__CameraLock;
	_Context->hint_CameraLock[7]=xx__CameraLock;
	for (i=0; i < 8; i++)_Context->msg_Extension[i]=" ";
	_Context->msg_Extension[0]=en_Extension;
	_Context->msg_Extension[1]=fr_Extension;
	_Context->msg_Extension[2]=it_Extension;
	_Context->msg_Extension[3]=es_Extension;
	_Context->msg_Extension[4]=de_Extension;
	_Context->msg_Extension[5]=nl_Extension;
	_Context->msg_Extension[6]=pt_Extension;
	_Context->msg_Extension[7]=xx_Extension;
	_Context->hint_Extension[0]=en__Extension;
	_Context->hint_Extension[1]=fr__Extension;
	_Context->hint_Extension[2]=it__Extension;
	_Context->hint_Extension[3]=es__Extension;
	_Context->hint_Extension[4]=de__Extension;
	_Context->hint_Extension[5]=nl__Extension;
	_Context->hint_Extension[6]=pt__Extension;
	_Context->hint_Extension[7]=xx__Extension;
	for (i=0; i < 8; i++)_Context->msg_Select[i]=" ";
	_Context->msg_Select[0]=en_Select;
	_Context->msg_Select[1]=fr_Select;
	_Context->msg_Select[2]=it_Select;
	_Context->msg_Select[3]=es_Select;
	_Context->msg_Select[4]=de_Select;
	_Context->msg_Select[5]=nl_Select;
	_Context->msg_Select[6]=pt_Select;
	_Context->msg_Select[7]=xx_Select;
	_Context->hint_Select[0]=en__Select;
	_Context->hint_Select[1]=fr__Select;
	for (i=0; i < 8; i++)_Context->msg_Auto3555[i]=" ";
	_Context->msg_Auto3555[0]=en_Auto3555;
	_Context->msg_Auto3555[1]=fr_Auto3555;
	_Context->msg_Auto3555[2]=it_Auto3555;
	_Context->msg_Auto3555[3]=es_Auto3555;
	_Context->msg_Auto3555[4]=de_Auto3555;
	_Context->msg_Auto3555[5]=nl_Auto3555;
	_Context->msg_Auto3555[6]=pt_Auto3555;
	_Context->msg_Auto3555[7]=xx_Auto3555;
	_Context->hint_Auto3555[0]=en__Auto3555;
	for (i=0; i < 8; i++)_Context->msg_fgSelect[i]=" ";
	_Context->msg_fgSelect[0]=en_fgSelect;
	_Context->msg_fgSelect[1]=fr_fgSelect;
	_Context->msg_fgSelect[2]=it_fgSelect;
	_Context->msg_fgSelect[3]=es_fgSelect;
	_Context->msg_fgSelect[4]=de_fgSelect;
	_Context->msg_fgSelect[5]=nl_fgSelect;
	_Context->msg_fgSelect[6]=pt_fgSelect;
	_Context->msg_fgSelect[7]=xx_fgSelect;
	_Context->hint_fgSelect[0]=en__fgSelect;
	_Context->hint_fgSelect[1]=fr__fgSelect;
	_Context->hint_fgSelect[2]=it__fgSelect;
	_Context->hint_fgSelect[3]=es__fgSelect;
	_Context->hint_fgSelect[4]=de__fgSelect;
	_Context->hint_fgSelect[5]=nl__fgSelect;
	_Context->hint_fgSelect[6]=pt__fgSelect;
	_Context->hint_fgSelect[7]=xx__fgSelect;
	for (i=0; i < 8; i++)_Context->msg_Choixfconf[i]=" ";
	_Context->msg_Choixfconf[0]=en_Choixfconf;
	_Context->msg_Choixfconf[1]=fr_Choixfconf;
	_Context->msg_Choixfconf[2]=it_Choixfconf;
	_Context->msg_Choixfconf[3]=es_Choixfconf;
	_Context->msg_Choixfconf[4]=de_Choixfconf;
	_Context->msg_Choixfconf[5]=nl_Choixfconf;
	_Context->msg_Choixfconf[6]=pt_Choixfconf;
	_Context->msg_Choixfconf[7]=xx_Choixfconf;
	_Context->hint_Choixfconf[0]=en__Choixfconf;
	for (i=0; i < 8; i++)_Context->msg_ChoixBase[i]=" ";
	_Context->msg_ChoixBase[0]=en_ChoixBase;
	_Context->msg_ChoixBase[1]=fr_ChoixBase;
	_Context->msg_ChoixBase[2]=it_ChoixBase;
	_Context->msg_ChoixBase[3]=es_ChoixBase;
	_Context->msg_ChoixBase[4]=de_ChoixBase;
	_Context->msg_ChoixBase[5]=nl_ChoixBase;
	_Context->msg_ChoixBase[6]=pt_ChoixBase;
	_Context->msg_ChoixBase[7]=xx_ChoixBase;
	_Context->hint_ChoixBase[0]=en__ChoixBase;
	for (i=0; i < 8; i++)_Context->msg_ChoixTemplate[i]=" ";
	_Context->msg_ChoixTemplate[0]=en_ChoixTemplate;
	_Context->msg_ChoixTemplate[1]=fr_ChoixTemplate;
	_Context->msg_ChoixTemplate[2]=it_ChoixTemplate;
	_Context->msg_ChoixTemplate[3]=es_ChoixTemplate;
	_Context->msg_ChoixTemplate[4]=de_ChoixTemplate;
	_Context->msg_ChoixTemplate[5]=nl_ChoixTemplate;
	_Context->msg_ChoixTemplate[6]=pt_ChoixTemplate;
	_Context->msg_ChoixTemplate[7]=xx_ChoixTemplate;
	_Context->hint_ChoixTemplate[0]=en__ChoixTemplate;
	for (i=0; i < 8; i++)_Context->msg_ChoixModules[i]=" ";
	_Context->msg_ChoixModules[0]=en_ChoixModules;
	_Context->msg_ChoixModules[1]=fr_ChoixModules;
	_Context->msg_ChoixModules[2]=it_ChoixModules;
	_Context->msg_ChoixModules[3]=es_ChoixModules;
	_Context->msg_ChoixModules[4]=de_ChoixModules;
	_Context->msg_ChoixModules[5]=nl_ChoixModules;
	_Context->msg_ChoixModules[6]=pt_ChoixModules;
	_Context->msg_ChoixModules[7]=xx_ChoixModules;
	_Context->hint_ChoixModules[0]=en__ChoixModules;
	for (i=0; i < 8; i++)_Context->msg_ChooseComponents[i]=" ";
	_Context->msg_ChooseComponents[0]=en_ChooseComponents;
	_Context->msg_ChooseComponents[1]=fr_ChooseComponents;
	_Context->msg_ChooseComponents[2]=it_ChooseComponents;
	_Context->msg_ChooseComponents[3]=es_ChooseComponents;
	_Context->msg_ChooseComponents[4]=de_ChooseComponents;
	_Context->msg_ChooseComponents[5]=nl_ChooseComponents;
	_Context->msg_ChooseComponents[6]=pt_ChooseComponents;
	_Context->msg_ChooseComponents[7]=xx_ChooseComponents;
	_Context->hint_ChooseComponents[0]=en__ChooseComponents;
	for (i=0; i < 8; i++)_Context->msg_Auto3556[i]=" ";
	_Context->msg_Auto3556[0]=en_Auto3556;
	_Context->msg_Auto3556[1]=fr_Auto3556;
	_Context->msg_Auto3556[2]=it_Auto3556;
	_Context->msg_Auto3556[3]=es_Auto3556;
	_Context->msg_Auto3556[4]=de_Auto3556;
	_Context->msg_Auto3556[5]=nl_Auto3556;
	_Context->msg_Auto3556[6]=pt_Auto3556;
	_Context->msg_Auto3556[7]=xx_Auto3556;
	_Context->hint_Auto3556[0]=en__Auto3556;
	_Context->hint_Auto3556[1]=fr__Auto3556;
	_Context->hint_Auto3556[2]=it__Auto3556;
	_Context->hint_Auto3556[3]=es__Auto3556;
	_Context->hint_Auto3556[4]=de__Auto3556;
	_Context->hint_Auto3556[5]=nl__Auto3556;
	_Context->hint_Auto3556[6]=pt__Auto3556;
	_Context->hint_Auto3556[7]=xx__Auto3556;
	for (i=0; i < 8; i++)_Context->msg_Auto3557[i]=" ";
	_Context->msg_Auto3557[0]=en_Auto3557;
	_Context->msg_Auto3557[1]=fr_Auto3557;
	_Context->msg_Auto3557[2]=it_Auto3557;
	_Context->msg_Auto3557[3]=es_Auto3557;
	_Context->msg_Auto3557[4]=de_Auto3557;
	_Context->msg_Auto3557[5]=nl_Auto3557;
	_Context->msg_Auto3557[6]=pt_Auto3557;
	_Context->msg_Auto3557[7]=xx_Auto3557;
	_Context->hint_Auto3557[0]=en__Auto3557;
	for (i=0; i < 8; i++)_Context->msg_Auto3558[i]=" ";
	_Context->msg_Auto3558[0]=en_Auto3558;
	_Context->msg_Auto3558[1]=fr_Auto3558;
	_Context->msg_Auto3558[2]=it_Auto3558;
	_Context->msg_Auto3558[3]=es_Auto3558;
	_Context->msg_Auto3558[4]=de_Auto3558;
	_Context->msg_Auto3558[5]=nl_Auto3558;
	_Context->msg_Auto3558[6]=pt_Auto3558;
	_Context->msg_Auto3558[7]=xx_Auto3558;
	_Context->hint_Auto3558[0]=en__Auto3558;
	for (i=0; i < 8; i++)_Context->msg_Auto3559[i]=" ";
	_Context->msg_Auto3559[0]=en_Auto3559;
	_Context->msg_Auto3559[1]=fr_Auto3559;
	_Context->msg_Auto3559[2]=it_Auto3559;
	_Context->msg_Auto3559[3]=es_Auto3559;
	_Context->msg_Auto3559[4]=de_Auto3559;
	_Context->msg_Auto3559[5]=nl_Auto3559;
	_Context->msg_Auto3559[6]=pt_Auto3559;
	_Context->msg_Auto3559[7]=xx_Auto3559;
	_Context->hint_Auto3559[0]=en__Auto3559;
	_Context->hint_Auto3559[1]=fr__Auto3559;
	_Context->hint_Auto3559[2]=it__Auto3559;
	_Context->hint_Auto3559[3]=es__Auto3559;
	_Context->hint_Auto3559[4]=de__Auto3559;
	_Context->hint_Auto3559[5]=nl__Auto3559;
	_Context->hint_Auto3559[6]=pt__Auto3559;
	_Context->hint_Auto3559[7]=xx__Auto3559;
	_Context->focus_pages[2]=34;
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
	_Context->hint_Auto3566[0]=en__Auto3566;
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
	_Context->hint_Auto3568[0]=en__Auto3568;
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
	_Context->hint_Auto3573[0]=en__Auto3573;
	_Context->hint_Auto3573[1]=fr__Auto3573;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3580[i]=" ";
	_Context->msg_Auto3580[0]=en_Auto3580;
	_Context->msg_Auto3580[1]=fr_Auto3580;
	_Context->msg_Auto3580[2]=it_Auto3580;
	_Context->msg_Auto3580[3]=es_Auto3580;
	_Context->msg_Auto3580[4]=de_Auto3580;
	_Context->msg_Auto3580[5]=nl_Auto3580;
	_Context->msg_Auto3580[6]=pt_Auto3580;
	_Context->msg_Auto3580[7]=xx_Auto3580;
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
	for (i=0; i < 8; i++)_Context->msg_DynamicSize[i]=" ";
	_Context->msg_DynamicSize[0]=en_DynamicSize;
	_Context->msg_DynamicSize[1]=fr_DynamicSize;
	_Context->msg_DynamicSize[2]=it_DynamicSize;
	_Context->msg_DynamicSize[3]=es_DynamicSize;
	_Context->msg_DynamicSize[4]=de_DynamicSize;
	_Context->msg_DynamicSize[5]=nl_DynamicSize;
	_Context->msg_DynamicSize[6]=pt_DynamicSize;
	_Context->msg_DynamicSize[7]=xx_DynamicSize;
	_Context->hint_DynamicSize[0]=en__DynamicSize;
	_Context->hint_DynamicSize[1]=fr__DynamicSize;
	for (i=0; i < 8; i++)_Context->msg_Direction[i]=" ";
	_Context->msg_Direction[0]=en_Direction;
	_Context->msg_Direction[1]=fr_Direction;
	_Context->msg_Direction[2]=it_Direction;
	_Context->msg_Direction[3]=es_Direction;
	_Context->msg_Direction[4]=de_Direction;
	_Context->msg_Direction[5]=nl_Direction;
	_Context->msg_Direction[6]=pt_Direction;
	_Context->msg_Direction[7]=xx_Direction;
	_Context->hint_Direction[0]=en__Direction;
	_Context->hint_Direction[1]=fr__Direction;
	_Context->hint_Direction[2]=it__Direction;
	_Context->hint_Direction[3]=es__Direction;
	_Context->hint_Direction[4]=de__Direction;
	_Context->hint_Direction[5]=nl__Direction;
	_Context->hint_Direction[6]=pt__Direction;
	_Context->hint_Direction[7]=xx__Direction;
	for (i=0; i < 8; i++)_Context->msg_Accept[i]=" ";
	_Context->msg_Accept[0]=en_Accept;
	_Context->msg_Accept[1]=fr_Accept;
	_Context->msg_Accept[2]=it_Accept;
	_Context->msg_Accept[3]=es_Accept;
	_Context->msg_Accept[4]=de_Accept;
	_Context->msg_Accept[5]=nl_Accept;
	_Context->msg_Accept[6]=pt_Accept;
	_Context->msg_Accept[7]=xx_Accept;
	_Context->hint_Accept[0]=en__Accept;
	_Context->hint_Accept[1]=fr__Accept;
	_Context->hint_Accept[2]=it__Accept;
	_Context->hint_Accept[3]=es__Accept;
	_Context->hint_Accept[4]=de__Accept;
	_Context->hint_Accept[5]=nl__Accept;
	_Context->hint_Accept[6]=pt__Accept;
	_Context->hint_Accept[7]=xx__Accept;
	for (i=0; i < 8; i++)_Context->msg_Cancel[i]=" ";
	_Context->msg_Cancel[0]=en_Cancel;
	_Context->msg_Cancel[1]=fr_Cancel;
	_Context->msg_Cancel[2]=it_Cancel;
	_Context->msg_Cancel[3]=es_Cancel;
	_Context->msg_Cancel[4]=de_Cancel;
	_Context->msg_Cancel[5]=nl_Cancel;
	_Context->msg_Cancel[6]=pt_Cancel;
	_Context->msg_Cancel[7]=xx_Cancel;
	_Context->hint_Cancel[0]=en__Cancel;
	_Context->hint_Cancel[1]=fr__Cancel;
	_Context->hint_Cancel[2]=it__Cancel;
	_Context->hint_Cancel[3]=es__Cancel;
	_Context->hint_Cancel[4]=de__Cancel;
	_Context->hint_Cancel[5]=nl__Cancel;
	_Context->hint_Cancel[6]=pt__Cancel;
	_Context->hint_Cancel[7]=xx__Cancel;
	_Context->hint_NbX[0]=en__NbX;
	_Context->hint_NbX[1]=fr__NbX;
	_Context->hint_nbY[0]=en__nbY;
	_Context->hint_nbY[1]=fr__nbY;
	_Context->hint_NbZ[0]=en__NbZ;
	_Context->hint_NbZ[1]=fr__NbZ;
	_Context->hint_Step[0]=en__Step;
	_Context->hint_Step[1]=fr__Step;
	_Context->hint_StepX[0]=en__StepX;
	_Context->hint_StepX[1]=fr__StepX;
	_Context->hint_StepY[0]=en__StepY;
	_Context->hint_StepY[1]=fr__StepY;
	_Context->hint_StepZ[0]=en__StepZ;
	_Context->hint_StepZ[1]=fr__StepZ;
	for (i=0; i < 8; i++)_Context->msg_ImageFormat[i]=" ";
	_Context->hint_ImageFormat[0]=en__ImageFormat;
	_Context->hint_ImageFormat[1]=fr__ImageFormat;
	_Context->hint_ImageFormat[2]=it__ImageFormat;
	_Context->hint_ImageFormat[3]=es__ImageFormat;
	_Context->hint_ImageFormat[4]=de__ImageFormat;
	_Context->hint_ImageFormat[5]=nl__ImageFormat;
	_Context->hint_ImageFormat[6]=pt__ImageFormat;
	_Context->hint_ImageFormat[7]=xx__ImageFormat;
	for (i=0; i < 8; i++)_Context->msg_ForceCIT[i]=" ";
	_Context->msg_ForceCIT[0]=en_ForceCIT;
	_Context->msg_ForceCIT[1]=fr_ForceCIT;
	_Context->msg_ForceCIT[2]=it_ForceCIT;
	_Context->msg_ForceCIT[3]=es_ForceCIT;
	_Context->msg_ForceCIT[4]=de_ForceCIT;
	_Context->msg_ForceCIT[5]=nl_ForceCIT;
	_Context->msg_ForceCIT[6]=pt_ForceCIT;
	_Context->msg_ForceCIT[7]=xx_ForceCIT;
	_Context->hint_ForceCIT[0]=en__ForceCIT;
	_Context->hint_ForceCIT[1]=fr__ForceCIT;
	_Context->hint_ForceCIT[2]=it__ForceCIT;
	_Context->hint_ForceCIT[3]=es__ForceCIT;
	_Context->hint_ForceCIT[4]=de__ForceCIT;
	_Context->hint_ForceCIT[5]=nl__ForceCIT;
	_Context->hint_ForceCIT[6]=pt__ForceCIT;
	_Context->hint_ForceCIT[7]=xx__ForceCIT;
	_Context->hint_DefaultStyle[0]=en__DefaultStyle;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3536,_Context->y_Auto3536,630+10,570+10);
	return(0);
}

public 	int	accept_camera_properties_hide(struct accept_camera_properties_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3536,_Context->y_Auto3536);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_camera_properties_remove(
	struct accept_camera_properties_context * _Context,
	char * pConfiguration,
	char * pDataBase,
	char * pTemplate,
	char * pModules,
	char * pComponents,
	char * pFormsDirectory,
	char * pSourcesDirectory,
	char * pObjectsDirectory,
	char * pPaletteName,
	char * pImageName,
	char * pImageType,
	char * pQuality,
	char * pSaveImages,
	char * pColour,
	char * pApplyStyle,
	char * pSaveForms,
	char * pNationalLanguage,
	char * pRollBack,
	char * pCameraLock,
	char * pExtension,
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pDynamicSize,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStep,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pImageFormat,
	char * pForceCIT,
	char * pDefaultStyle)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSWWWWWWWWWWSWWWWWWWWWWWWWWWWS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_Configuration, 255, pConfiguration);
		visual_transferout(_Context->buffer_DataBase, 255, pDataBase);
		visual_transferout(_Context->buffer_Template, 255, pTemplate);
		visual_transferout(_Context->buffer_Modules, 400, pModules);
		visual_transferout(_Context->buffer_Components, 400, pComponents);
		visual_transferout(_Context->buffer_FormsDirectory, 255, pFormsDirectory);
		visual_transferout(_Context->buffer_SourcesDirectory, 255, pSourcesDirectory);
		visual_transferout(_Context->buffer_ObjectsDirectory, 255, pObjectsDirectory);
		visual_transferout(_Context->buffer_PaletteName, 255, pPaletteName);
		visual_transferout(_Context->buffer_ImageName, 255, pImageName);
		visual_transferout((void *) 0, 0, pImageType);
		if ( pImageType != (char *) 0)
			*((int*)pImageType) = _Context->value_ImageType;
		visual_transferout((void *) 0, 0, pQuality);
		if ( pQuality != (char *) 0)
			*((int*)pQuality) = _Context->value_Quality;
		visual_transferout((void *) 0, 0, pSaveImages);
		if ( pSaveImages != (char *) 0)
			*((int*)pSaveImages) = _Context->value_SaveImages;
		visual_transferout(_Context->buffer_Colour, 10, pColour);
		visual_transferout((void *) 0, 0, pApplyStyle);
		if ( pApplyStyle != (char *) 0)
			*((int*)pApplyStyle) = _Context->value_ApplyStyle;
		visual_transferout((void *) 0, 0, pSaveForms);
		if ( pSaveForms != (char *) 0)
			*((int*)pSaveForms) = _Context->value_SaveForms;
		visual_transferout((void *) 0, 0, pNationalLanguage);
		if ( pNationalLanguage != (char *) 0)
			*((int*)pNationalLanguage) = _Context->value_NationalLanguage;
		visual_transferout((void *) 0, 0, pRollBack);
		if ( pRollBack != (char *) 0)
			*((int*)pRollBack) = _Context->value_RollBack;
		visual_transferout((void *) 0, 0, pCameraLock);
		if ( pCameraLock != (char *) 0)
			*((int*)pCameraLock) = _Context->value_CameraLock;
		visual_transferout((void *) 0, 0, pExtension);
		if ( pExtension != (char *) 0)
			*((int*)pExtension) = _Context->value_Extension;
		visual_transferout(_Context->buffer_Name, 255, pName);
		visual_transferout(_Context->buffer_AtX, 11, pAtX);
		visual_transferout(_Context->buffer_AtY, 11, pAtY);
		visual_transferout(_Context->buffer_AtZ, 10, pAtZ);
		visual_transferout((void *) 0, 0, pDynamicSize);
		if ( pDynamicSize != (char *) 0)
			*((int*)pDynamicSize) = _Context->value_DynamicSize;
		visual_transferout(_Context->buffer_ToX, 11, pToX);
		visual_transferout(_Context->buffer_ToY, 11, pToY);
		visual_transferout((void *) 0, 0, pDirection);
		if ( pDirection != (char *) 0)
			*((int*)pDirection) = _Context->value_Direction;
		visual_transferout(_Context->buffer_NbX, 11, pNbX);
		visual_transferout(_Context->buffer_nbY, 11, pnbY);
		visual_transferout(_Context->buffer_NbZ, 10, pNbZ);
		visual_transferout(_Context->buffer_Step, 11, pStep);
		visual_transferout(_Context->buffer_StepX, 11, pStepX);
		visual_transferout(_Context->buffer_StepY, 11, pStepY);
		visual_transferout(_Context->buffer_StepZ, 10, pStepZ);
		visual_transferout((void *) 0, 0, pImageFormat);
		if ( pImageFormat != (char *) 0)
			*((int*)pImageFormat) = _Context->value_ImageFormat;
		visual_transferout((void *) 0, 0, pForceCIT);
		if ( pForceCIT != (char *) 0)
			*((int*)pForceCIT) = _Context->value_ForceCIT;
		visual_transferout(_Context->buffer_DefaultStyle, 57, pDefaultStyle);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_camera_properties_show(struct accept_camera_properties_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3536,_Context->y_Auto3536);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3536,_Context->y_Auto3536,630,570,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3536,_Context->y_Auto3536,630,570,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x407);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto3537=visual_trigger_code(_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]));
	visual_tabpage(_Context->x_Auto3536+10,_Context->y_Auto3536+30,610,470,vfh[2],_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto3536+10,_Context->y_Auto3536+30,610,470,vfh[2],_Context->msg_Auto3537[_Context->language],strlen(_Context->msg_Auto3537[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+20,_Context->y_Auto3536+70,575,20,vfh[3],27,0,_Context->msg_Auto3538[_Context->language],strlen(_Context->msg_Auto3538[_Context->language]),1282);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+90,590,120,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+220,590,80,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+310,590,60,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+380,590,110,4);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+100,110,20,vfh[2],27,0,_Context->msg_Auto3543[_Context->language],strlen(_Context->msg_Auto3543[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+120,112,16,vfh[2],27,0,_Context->msg_TitreDataBase[_Context->language],strlen(_Context->msg_TitreDataBase[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+140,112,16,vfh[2],27,0,_Context->msg_Auto3544[_Context->language],strlen(_Context->msg_Auto3544[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+160,112,16,vfh[2],27,0,_Context->msg_Auto3545[_Context->language],strlen(_Context->msg_Auto3545[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+180,112,16,vfh[2],27,0,_Context->msg_Auto3546[_Context->language],strlen(_Context->msg_Auto3546[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+230,110,20,vfh[2],27,0,_Context->msg_Auto3547[_Context->language],strlen(_Context->msg_Auto3547[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+250,110,20,vfh[2],27,0,_Context->msg_Auto3548[_Context->language],strlen(_Context->msg_Auto3548[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+270,110,20,vfh[2],27,0,_Context->msg_Auto3549[_Context->language],strlen(_Context->msg_Auto3549[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+320,112,16,vfh[2],27,0,_Context->msg_Auto3550[_Context->language],strlen(_Context->msg_Auto3550[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+340,112,16,vfh[2],27,0,_Context->msg_Auto3551[_Context->language],strlen(_Context->msg_Auto3551[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+390,140,16,vfh[2],27,0,_Context->msg_Auto3552[_Context->language],strlen(_Context->msg_Auto3552[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+410,112,16,vfh[2],27,0,_Context->msg_auto702[_Context->language],strlen(_Context->msg_auto702[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+440,84,16,vfh[2],27,0,_Context->msg_Auto3553[_Context->language],strlen(_Context->msg_Auto3553[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+460,112,16,vfh[2],27,0,_Context->msg_Auto3554[_Context->language],strlen(_Context->msg_Auto3554[_Context->language]),258);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+100,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+100+1,424,16,vfh[1],26,0,_Context->buffer_Configuration,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+120,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+120+1,424,16,vfh[1],26,0,_Context->buffer_DataBase,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+140,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+140+1,424,16,vfh[1],26,0,_Context->buffer_Template,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+160,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+160+1,424,16,vfh[1],26,0,_Context->buffer_Modules,400,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+180,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+180+1,424,16,vfh[1],26,0,_Context->buffer_Components,400,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+230,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+230+1,424,16,vfh[1],26,0,_Context->buffer_FormsDirectory,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+250,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+250+1,424,16,vfh[1],26,0,_Context->buffer_SourcesDirectory,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+270,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+270+1,424,16,vfh[1],26,0,_Context->buffer_ObjectsDirectory,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+320,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+320+1,424,16,vfh[1],26,0,_Context->buffer_PaletteName,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+150,_Context->y_Auto3536+340,424+2,16+2,5);
	visual_text(_Context->x_Auto3536+150+1,_Context->y_Auto3536+340+1,424,16,vfh[1],26,0,_Context->buffer_ImageName,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto3536+180,_Context->y_Auto3536+390,140,90,vfh[2],0,0,parse_selection(WidgetImageList,&_Context->value_ImageType),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Quality=visual_trigger_code(_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+390,140,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),_Context->value_Quality|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SaveImages=visual_trigger_code(_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+410,140,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),_Context->value_SaveImages|0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3536+180,_Context->y_Auto3536+410,80+2,16+2,5);
	visual_text(_Context->x_Auto3536+180+1,_Context->y_Auto3536+410+1,80,16,vfh[1],26,0,_Context->buffer_Colour,10,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ApplyStyle=visual_trigger_code(_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]));
	visual_check(_Context->x_Auto3536+460,_Context->y_Auto3536+390,140,16,vfh[2],27,28,_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]),_Context->value_ApplyStyle|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_SaveForms=visual_trigger_code(_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]));
	visual_check(_Context->x_Auto3536+460,_Context->y_Auto3536+410,154,16,vfh[2],26,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),_Context->value_SaveForms|0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto3536+180,_Context->y_Auto3536+440,140,80,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),768);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_RollBack=visual_trigger_code(_Context->msg_RollBack[_Context->language],strlen(_Context->msg_RollBack[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+440,238,16,vfh[2],0,0,_Context->msg_RollBack[_Context->language],strlen(_Context->msg_RollBack[_Context->language]),_Context->value_RollBack|0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_CameraLock=visual_trigger_code(_Context->msg_CameraLock[_Context->language],strlen(_Context->msg_CameraLock[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+460,238,16,vfh[2],0,0,_Context->msg_CameraLock[_Context->language],strlen(_Context->msg_CameraLock[_Context->language]),_Context->value_CameraLock|0);
		}
	if (_Context->page_number == 1 ) {
	visual_select(_Context->x_Auto3536+180,_Context->y_Auto3536+460,72,32,vfh[1],0,0,parse_selection(_Context->msg_Extension[_Context->language],&_Context->value_Extension),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+340,20,16,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+320,20,16,vfh[8],27,28,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_Auto3536+263,_Context->y_Auto3536+410,56,16,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixBase=visual_trigger_code(_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+120,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixTemplate=visual_trigger_code(_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+140,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixModules=visual_trigger_code(_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+160,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChooseComponents=visual_trigger_code(_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+180,20,16,vfh[8],27,28,_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto3556=visual_trigger_code(_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+230,20,16,vfh[8],27,28,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+250,20,16,vfh[8],27,28,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+270,20,16,vfh[8],27,28,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Auto3559=visual_trigger_code(_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]));
	visual_tabpage(_Context->x_Auto3536+10,_Context->y_Auto3536+30,610,470,vfh[2],_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),118,2);
	} else {
		visual_tabpage(_Context->x_Auto3536+10,_Context->y_Auto3536+30,610,470,vfh[2],_Context->msg_Auto3559[_Context->language],strlen(_Context->msg_Auto3559[_Context->language]),118,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+100,590,50,4);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+190,590,70,4);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+300,590,100,4);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+20,_Context->y_Auto3536+440,590,50,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+20,_Context->y_Auto3536+70,575,20,vfh[3],27,0,_Context->msg_Auto3564[_Context->language],strlen(_Context->msg_Auto3564[_Context->language]),1282);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+20,_Context->y_Auto3536+170,575,20,vfh[2],27,0,_Context->msg_Auto3565[_Context->language],strlen(_Context->msg_Auto3565[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+20,_Context->y_Auto3536+280,575,20,vfh[2],27,0,_Context->msg_Auto3566[_Context->language],strlen(_Context->msg_Auto3566[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+20,_Context->y_Auto3536+280,575,20,vfh[2],27,0,_Context->msg_Auto3567[_Context->language],strlen(_Context->msg_Auto3567[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+20,_Context->y_Auto3536+420,588,16,vfh[2],27,0,_Context->msg_Auto3568[_Context->language],strlen(_Context->msg_Auto3568[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+120,98,16,vfh[2],27,0,_Context->msg_Auto3569[_Context->language],strlen(_Context->msg_Auto3569[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+210,98,16,vfh[2],27,0,_Context->msg_Auto3570[_Context->language],strlen(_Context->msg_Auto3570[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+230,98,16,vfh[2],27,0,_Context->msg_Auto3571[_Context->language],strlen(_Context->msg_Auto3571[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+380,_Context->y_Auto3536+230,98,16,vfh[2],27,0,_Context->msg_Auto3572[_Context->language],strlen(_Context->msg_Auto3572[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+470,_Context->y_Auto3536+320,42,16,vfh[2],27,0,_Context->msg_Auto3573[_Context->language],strlen(_Context->msg_Auto3573[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+370,98,16,vfh[2],27,0,_Context->msg_Auto3574[_Context->language],strlen(_Context->msg_Auto3574[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+460,98,16,vfh[2],27,0,_Context->msg_Auto3575[_Context->language],strlen(_Context->msg_Auto3575[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+120,_Context->y_Auto3536+210,14,16,vfh[2],27,0,_Context->msg_Auto3576[_Context->language],strlen(_Context->msg_Auto3576[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+240,_Context->y_Auto3536+210,14,16,vfh[2],27,0,_Context->msg_Auto3577[_Context->language],strlen(_Context->msg_Auto3577[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+360,_Context->y_Auto3536+210,14,16,vfh[2],27,0,_Context->msg_Auto3578[_Context->language],strlen(_Context->msg_Auto3578[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+120,_Context->y_Auto3536+230,14,20,vfh[2],27,0,_Context->msg_Auto3579[_Context->language],strlen(_Context->msg_Auto3579[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+240,_Context->y_Auto3536+230,14,16,vfh[2],27,0,_Context->msg_Auto3580[_Context->language],strlen(_Context->msg_Auto3580[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+310,98,16,vfh[2],27,0,_Context->msg_Auto3581[_Context->language],strlen(_Context->msg_Auto3581[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+30,_Context->y_Auto3536+340,98,16,vfh[2],27,0,_Context->msg_Auto3582[_Context->language],strlen(_Context->msg_Auto3582[_Context->language]),258);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+120,_Context->y_Auto3536+320,14,20,vfh[2],27,0,_Context->msg_Auto3583[_Context->language],strlen(_Context->msg_Auto3583[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+240,_Context->y_Auto3536+320,14,16,vfh[2],27,0,_Context->msg_Auto3584[_Context->language],strlen(_Context->msg_Auto3584[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3536+360,_Context->y_Auto3536+320,14,16,vfh[2],27,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),259);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+140,_Context->y_Auto3536+120,456+2,16+2,5);
	visual_text(_Context->x_Auto3536+140+1,_Context->y_Auto3536+120+1,456,16,vfh[1],26,0,_Context->buffer_Name,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+140,_Context->y_Auto3536+210,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+140+1,_Context->y_Auto3536+210+1,88,16,vfh[1],26,0,_Context->buffer_AtX,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+260,_Context->y_Auto3536+210,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+260+1,_Context->y_Auto3536+210+1,88,16,vfh[1],26,0,_Context->buffer_AtY,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+380,_Context->y_Auto3536+210,80+2,16+2,5);
	visual_text(_Context->x_Auto3536+380+1,_Context->y_Auto3536+210+1,80,16,vfh[1],26,0,_Context->buffer_AtZ,10,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_DynamicSize=visual_trigger_code(_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]));
	visual_check(_Context->x_Auto3536+490,_Context->y_Auto3536+210,112,16,vfh[2],26,0,_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]),_Context->value_DynamicSize|0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+140,_Context->y_Auto3536+230,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+140+1,_Context->y_Auto3536+230+1,88,16,vfh[1],26,0,_Context->buffer_ToX,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+260,_Context->y_Auto3536+230,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+260+1,_Context->y_Auto3536+230+1,88,16,vfh[1],26,0,_Context->buffer_ToY,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_select(_Context->x_Auto3536+490,_Context->y_Auto3536+230,112,64,vfh[2],26,0,parse_selection(_Context->msg_Direction[_Context->language],&_Context->value_Direction),768);
		}
	_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3536+10,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
	_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3536+560,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+140,_Context->y_Auto3536+320,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+140+1,_Context->y_Auto3536+320+1,88,16,vfh[1],26,0,_Context->buffer_NbX,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+260,_Context->y_Auto3536+320,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+260+1,_Context->y_Auto3536+320+1,88,16,vfh[1],0,0,_Context->buffer_nbY,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+380,_Context->y_Auto3536+320,80+2,16+2,5);
	visual_text(_Context->x_Auto3536+380+1,_Context->y_Auto3536+320+1,80,16,vfh[1],26,0,_Context->buffer_NbZ,10,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+510,_Context->y_Auto3536+320,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+510+1,_Context->y_Auto3536+320+1,88,16,vfh[1],26,0,_Context->buffer_Step,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+140,_Context->y_Auto3536+340,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+140+1,_Context->y_Auto3536+340+1,88,16,vfh[1],26,0,_Context->buffer_StepX,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+260,_Context->y_Auto3536+340,88+2,16+2,5);
	visual_text(_Context->x_Auto3536+260+1,_Context->y_Auto3536+340+1,88,16,vfh[1],26,0,_Context->buffer_StepY,11,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+380,_Context->y_Auto3536+340,80+2,16+2,5);
	visual_text(_Context->x_Auto3536+380+1,_Context->y_Auto3536+340+1,80,16,vfh[1],26,0,_Context->buffer_StepZ,10,0);
		}
	if (_Context->page_number == 2 ) {
	visual_select(_Context->x_Auto3536+140,_Context->y_Auto3536+370,88,96,vfh[2],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),768);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ForceCIT=visual_trigger_code(_Context->msg_ForceCIT[_Context->language],strlen(_Context->msg_ForceCIT[_Context->language]));
	visual_check(_Context->x_Auto3536+260,_Context->y_Auto3536+370,168,16,vfh[2],16,28,_Context->msg_ForceCIT[_Context->language],strlen(_Context->msg_ForceCIT[_Context->language]),_Context->value_ForceCIT|0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3536+140,_Context->y_Auto3536+460,456+2,16+2,5);
	visual_text(_Context->x_Auto3536+140+1,_Context->y_Auto3536+460+1,456,16,vfh[1],0,0,_Context->buffer_DefaultStyle,57,0);
		}
	visual_thaw(_Context->x_Auto3536,_Context->y_Auto3536,630,570);

	return(0);
}

private int Configuration_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field allows the name of a configuration file or section ";
			mptr[1]="to be specified.  ";
			mptr[2]=" ";
			mptr[3]="When configuration information has been specified for a project in ";
			mptr[4]="this way it will be used conjunctly by the design tool and by all ";
			mptr[5]="of its subsequently produced components.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DataBase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field  allows definition of the name of an XML ressource ";
			mptr[1]="to which all data base record information will be written. The subsequently ";
			mptr[2]="created data base ressource will be attached to the current project ";
			mptr[3]="ressource allowing the database to be shared amongst multiple projects ";
			mptr[4]="or project groups.      ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Template_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field allows a forms model ressource name to be specified ";
			mptr[1]=" to be used as the source of preset or template widget types.  ";
			mptr[2]=" ";
			mptr[3]="When a ressource has been specified in this way, the various different ";
			mptr[4]=" component widgets will be proposed for selection when particular ";
			mptr[5]="new widgets are added to forms models.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Modules_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a list of modules to be declared to be  used ";
			mptr[1]="by default for all abal link operations performed on  source type ";
			mptr[2]="components of the project workspace. This list will not be used for ";
			mptr[3]="link operations performed for forms model components.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Components_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows a list of component project files to be declared ";
			mptr[1]="to be  used by the current project for the resolution of component ";
			mptr[2]="form definitions. The corresponding project model will be loaded after ";
			mptr[3]="the current model  into the threed viewer.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FormsDirectory_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows a directory to be defined in which all forms ";
			mptr[1]="model resource files will be stored.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SourcesDirectory_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows a directory to be defined to which all forms ";
			mptr[1]="model production sources will be generated.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ObjectsDirectory_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows a directory to be defined to which all forms ";
			mptr[1]="model abal translated module and program files will be generated. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
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
			char * mptr[3];
			mptr[0] = "This edit field allows the file name of a palette file to be specified. ";
			mptr[1]="This palette will be loaded and used for all subsequent project models. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImageName_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The IMAGE edit field allows the full path and filename of an image ";
			mptr[1]="to used as the application model background over which the 3d ca mera ";
			mptr[2]=" entities will be projected.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImageType_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[21];
			mptr[0] = "The following image options are available.  ";
			mptr[1]=" ";
			mptr[2]="None ";
			mptr[3]="   no alignment is applied to the image.  ";
			mptr[4]="Right ";
			mptr[5]="   The image will be right aligned in the widget zone.  ";
			mptr[6]="Left ";
			mptr[7]="   The image will be left aligned in the widget zone.  ";
			mptr[8]="Center ";
			mptr[9]="   The image will be centered within the widget zone.  ";
			mptr[10]="Tile ";
			mptr[11]="   This option causes the images, smaller than their  widget zone, to ";
			mptr[12]="be tiled or repeated, to fill the entire  zone.  ";
			mptr[13]="Makefit ";
			mptr[14]="   causes images to be stretched or squashed to fit the entire widget ";
			mptr[15]="zone.  ";
			mptr[16]="Bestfit ";
			mptr[17]="   causes images to stretched and squashed respecting the image proportions. ";
			mptr[18]="The result may stil be smaller than the  widget zone in which case ";
			mptr[19]="it will be centered.  ";
			mptr[20]="    ";
			return(visual_online_help(mptr,21));
			}
			break;
		case 1 : 
			{
			char * mptr[18];
			mptr[0] = "Les options d'image suivants sont possible   ";
			mptr[1]=" ";
			mptr[2]="None ";
			mptr[3]="   pas d'alignement de l'image.  ";
			mptr[4]="Right ";
			mptr[5]="   Alignement … droite de l'image.  ";
			mptr[6]="Left ";
			mptr[7]="   Alignement … gauche de l'image.  ";
			mptr[8]="Center ";
			mptr[9]="   Alignement en mileu.  ";
			mptr[10]="Tile ";
			mptr[11]="   R‚p‚tition de l'image pour couvrir entiŠrement la zone.  ";
			mptr[12]="Makefit ";
			mptr[13]="   Etirement de l'image pour couvrir entiŠrement la zone.  ";
			mptr[14]="Bestfit ";
			mptr[15]="   Etirement de l'image pour couvrir entiŠrement la zone  en respectant ";
			mptr[16]="les proportions d'origine de l'image.  ";
			mptr[17]="    ";
			return(visual_online_help(mptr,18));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Colour_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "The COLOUR edit field allows the current default application model ";
			mptr[1]="   background colour value. This will be used if no background imag ";
			mptr[2]="e has been specified of found to unavailable.          The background ";
			mptr[3]="colour us affected by dynamic selection fro m the       palette bar ";
			mptr[4]="with the right button of the mouse whilst i n the          application ";
			mptr[5]="model editor.  ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ApplyStyle_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The check control may be checked to activate use of style sheets information ";
			mptr[1]="for the display of forms widgets in place of the standard widget drawing ";
			mptr[2]="routines.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SaveForms_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The SAVEIMAGES check box and SAVEFORMS check box provide the defaul ";
			mptr[1]="t beahvious to be used by the application model save operation. The ";
			mptr[2]="y may me overidden by hand in the corresponding visual form.  ";
			return(visual_online_help(mptr,3));
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
			mptr[0] = "This select control allows the default national language of a project ";
			mptr[1]="to be defined. This value will be used for all forms created for the ";
			mptr[2]="project.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RollBack_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This check control allows activation of the new forms roll back/roll ";
			mptr[1]="forward mechanisms. This entails saving forms models after each modification ";
			mptr[2]="to a temporary file. The forms menu option Undo now allows the previous  versions to be restored whilst Redo ";
			mptr[3]="allows the more recent version to be restored.      ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CameraLock_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This check control allows activation of the new camera level locking ";
			mptr[1]="mechanisms which protects against accidental rewrite of modified project ";
			mptr[2]="and forms model ressource files. This flag is raised when component ";
			mptr[3]="project models are loaded  for use by derivative project models. It ";
			mptr[4]="will protect all component forms models of the project model against ";
			mptr[5]="being rewritten to disk as if the corresponding project files were ";
			mptr[6]="read only.      ";
			return(visual_online_help(mptr,7));
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

private int Select_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The Select button allows access yto the file selection dialog frame ";
			mptr[1]="allowing proimpted selection of the filename.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Choixfconf_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the project configuration filename.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ChoixBase_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the full path and filename of the xml file  to which ";
			mptr[2]="database resource information will  be generated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ChoixTemplate_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the full path and filename of an xml forms  model ";
			mptr[2]="resource from which widget templates are to be loaded.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ChoixModules_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the various module localisation paths for eventual ";
			mptr[2]="link operations.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ChooseComponents_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the various module localisation paths for eventual ";
			mptr[2]="link operations.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3556_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the directory in which all forms model resource ";
			mptr[2]="files will be stored.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3557_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the directory to which all forms production source ";
			mptr[2]="files will be generated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3558_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This push button gives access to the File Selection  Dialog box for ";
			mptr[1]="the definition of the directory to which all tcode modules and programs ";
			mptr[2]="will be generated.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AtX_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The POSITION X,Y and Z edit fields give access to the coordinates ";
			mptr[1]="o f  the current application camera position for inspection and modif ";
			mptr[2]="ication.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DynamicSize_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "The AUTOSIZE check box provides the default value to be used when ";
			mptr[1]="   creating new application model entities.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ToX_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The FOCUS X and Y edit fields offer the application camera focus fo ";
			mptr[1]="r  inspection and modification. The Camera Focus implies the deplac ";
			mptr[2]="ment  from the 0,0 center position of the application view.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Direction_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The DIRECTION edit field shows the current camera direction taken ";
			mptr[1]="   from the following : FORWARD, BACKWARD,UP,DOWN LEFT or RIGHT.  ";
			mptr[2]="     Whilst in the Application Viewer the direction may be changed ";
			mptr[3]=" by      simply pressing the first letter of the required direction ";
			mptr[4]=" name.  ";
			return(visual_online_help(mptr,5));
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

private int Cancel_help()
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

private int Step_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "Thre STEP edit field allows the camera movement step value to be  ";
			mptr[1]="   modified for automatic displacment.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int StepX_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The DISTANCE X,Y and Z edit fields provide access to the current  ";
			mptr[1]="  camera movement step values when a camera movement key is action ";
			mptr[2]="ed.   The camera action keys are the PAGEUP and PAGEDOWN keys which ";
			mptr[3]="         move in the current direction which may be toggle by the ";
			mptr[4]="s pace bar    amongst the following values : X,Y or Z direction.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ImageFormat_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This select control allows the image format to be specified. Currently ";
			mptr[1]="the only  formats that may be produced are BMP and GIF. The later producing mush smaller files but may require ";
			mptr[2]="longer image save times.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ForceCIT_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = " ";
			mptr[1]=" ";
			mptr[2]=" This check control when active causes the specified image type to ";
			mptr[3]="be  set as the current image type for all cubes of the camera.  ";
			mptr[4]=" ";
			mptr[5]="   ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto3536action(struct accept_camera_properties_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_camera_properties_hide(_Context);

		_Context->x_Auto3536 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3536 < 0) { _Context->x_Auto3536=0; }
		_Context->y_Auto3536 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3536 < 0) { _Context->y_Auto3536=0; }
			accept_camera_properties_show(_Context);

		visual_thaw(_Context->x_Auto3536,_Context->y_Auto3536,630,570);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_Select_event(struct accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_ImageName,WIDGET_FILE_GIF);
		accept_camera_properties_show(_Context);
;
	return(-1);
}
private int on_Auto3555_event(struct accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_PaletteName,WIDGET_FILE_RGB);
		accept_camera_properties_show(_Context);
;
	return(-1);
}
private int on_fgSelect_event(struct accept_camera_properties_context * _Context) {
	int fgv=0;
	int bgv=0;
	char*sptr;
	int slen;
	int i;
	sptr=_Context->buffer_Colour;
	slen=10;
	for(i=0;i<slen;i++){
	if((*(sptr+i)>='0')
	&&(*(sptr+i)<='9'))
	bgv=((fgv*10)+(*(sptr+i)-'0'));
	}
	fgv=bgv;
	if(accept_visual_colour(&fgv,&bgv)!=27){
	sprintf(_Context->buffer_Colour,"%u",bgv);
	}
	visual_frame(_Context->x_Auto3536+180,_Context->y_Auto3536+410,80+2,16+2,5);
visual_text(_Context->x_Auto3536+180+1,_Context->y_Auto3536+410+1,80,16,vfh[1],26,0,_Context->buffer_Colour,10,0);
;
	return(-1);
}
private int on_Choixfconf_event(struct accept_camera_properties_context * _Context) {
	char fconf[260];
	strcpy(fconf,_Context->buffer_Configuration);
	use_file_selector(fconf,WIDGET_FILE_CFG);
	if(strlen(fconf)>0)
	{
	fn_parser(fconf,_Context->buffer_Configuration,0x000F);
		accept_camera_properties_show(_Context);
;
	};
	return(-1);
}
private int on_ChoixBase_event(struct accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_DataBase,WIDGET_FILE_XML);
		accept_camera_properties_show(_Context);
;
	return(-1);
}
private int on_ChoixTemplate_event(struct accept_camera_properties_context * _Context) {
	use_file_selector(_Context->buffer_Template,WIDGET_FILE_XML);
		accept_camera_properties_show(_Context);
;
	return(-1);
}
private int on_ChoixModules_event(struct accept_camera_properties_context * _Context) {
	char ch_module[260]="\0";
	int i;
	use_file_selector(ch_module,WIDGET_FILE_OBJ);
	if(strlen(ch_module))
	{
	for(i=strlen(_Context->buffer_Modules);(i)&&(_Context->buffer_Modules[i]<=' ');i--);
	if(_Context->buffer_Modules[i]>' ')i++;
	_Context->buffer_Modules[i]=0;
	if(i)strcat(_Context->buffer_Modules,";");
	strcat(_Context->buffer_Modules,ch_module);
		accept_camera_properties_show(_Context);
;
	};
	return(-1);
}
private int on_ChooseComponents_event(struct accept_camera_properties_context * _Context) {
	char ch_module[260]="\0";
	int i;
	use_file_selector(ch_module,WIDGET_FILE_OBJ);
	if(strlen(ch_module))
	{
	for(i=strlen(_Context->buffer_Components);(i)&&(_Context->buffer_Components[i]<=' ');i--);
	if(_Context->buffer_Components[i]>' ')i++;
	_Context->buffer_Components[i]=0;
	if(i)strcat(_Context->buffer_Components,";");
	strcat(_Context->buffer_Components,ch_module);
		accept_camera_properties_show(_Context);
;
	};
	return(-1);
}
private int on_Auto3556_event(struct accept_camera_properties_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_FormsDirectory,"Repertoire de stockage des formulaires"))
		accept_camera_properties_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_FormsDirectory,"Directory for the XML documents"))
		accept_camera_properties_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_Auto3557_event(struct accept_camera_properties_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_SourcesDirectory,"Repertoire de stockage des sources produits"))
		accept_camera_properties_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_SourcesDirectory,"Directory for the AS documents"))
		accept_camera_properties_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_Auto3558_event(struct accept_camera_properties_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_ObjectsDirectory,"Repertoire de stockage des fichiers binaires"))
		accept_camera_properties_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_ObjectsDirectory,"Directory for the binary files products"))
		accept_camera_properties_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_Accept_event(struct accept_camera_properties_context * _Context) {
	return(13);
	return(-1);
}
private int on_Cancel_event(struct accept_camera_properties_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_camera_properties_event(
struct accept_camera_properties_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_Auto3537 == mb ) return(2);
		if (_Context->trigger_Quality == mb ) return(14);
		if (_Context->trigger_SaveImages == mb ) return(15);
		if (_Context->trigger_ApplyStyle == mb ) return(17);
		if (_Context->trigger_SaveForms == mb ) return(18);
		if (_Context->trigger_RollBack == mb ) return(20);
		if (_Context->trigger_CameraLock == mb ) return(21);
		if (_Context->trigger_Select == mb ) return(23);
		if (_Context->trigger_Auto3555 == mb ) return(24);
		if (_Context->trigger_fgSelect == mb ) return(25);
		if (_Context->trigger_Choixfconf == mb ) return(26);
		if (_Context->trigger_ChoixBase == mb ) return(27);
		if (_Context->trigger_ChoixTemplate == mb ) return(28);
		if (_Context->trigger_ChoixModules == mb ) return(29);
		if (_Context->trigger_ChooseComponents == mb ) return(30);
		if (_Context->trigger_Auto3556 == mb ) return(31);
		if (_Context->trigger_Auto3557 == mb ) return(32);
		if (_Context->trigger_Auto3558 == mb ) return(33);
		if (_Context->trigger_Auto3559 == mb ) return(34);
		if (_Context->trigger_DynamicSize == mb ) return(39);
		if (_Context->trigger_Accept == mb ) return(43);
		if (_Context->trigger_Cancel == mb ) return(44);
		if (_Context->trigger_ForceCIT == mb ) return(53);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3536+609) )  
	&&  (my >= (_Context->y_Auto3536+4) )  
	&&  (mx <= (_Context->x_Auto3536+626) )  
	&&  (my <= (_Context->y_Auto3536+20) )) {
		return(1);	/* Auto3536 */

		}
	if ((mx >= (_Context->x_Auto3536+593) )  
	&&  (my >= (_Context->y_Auto3536+4) )  
	&&  (mx <= (_Context->x_Auto3536+610) )  
	&&  (my <= (_Context->y_Auto3536+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vcamera.htm");
			};
		return(-1);	/* Auto3536 */

		}
	if ((mx >= (_Context->x_Auto3536+577) )  
	&&  (my >= (_Context->y_Auto3536+4) )  
	&&  (mx <= (_Context->x_Auto3536+594) )  
	&&  (my <= (_Context->y_Auto3536+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_camera_properties_show(_Context);
		return(-1);	/* Auto3536 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3536+4) )  
		&&  (my >= (_Context->y_Auto3536+4) )  
		&&  (mx <= (_Context->x_Auto3536+562) )  
		&&  (my <= (_Context->y_Auto3536+20) )) {
			return( Auto3536action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3536+10+0) ) 
		&&  ( my >= (_Context->y_Auto3536+30) ) 
		&&  ( mx <= (_Context->x_Auto3536+10+117) ) 
		&&  ( my <= (_Context->y_Auto3536+30+24))) {
			return(2); /* Auto3537 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+100) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+100+16))) {
			return(3); /* Configuration */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+120) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+120+16))) {
			return(4); /* DataBase */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+140) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+140+16))) {
			return(5); /* Template */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+160) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+160+16))) {
			return(6); /* Modules */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+180) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+180+16))) {
			return(7); /* Components */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+230) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+230+16))) {
			return(8); /* FormsDirectory */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+250) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+250+16))) {
			return(9); /* SourcesDirectory */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+270) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+270+16))) {
			return(10); /* ObjectsDirectory */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+320) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+320+16))) {
			return(11); /* PaletteName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+150) ) 
		&&  ( my >= (_Context->y_Auto3536+340) ) 
		&&  ( mx <= (_Context->x_Auto3536+150+424) ) 
		&&  ( my <= (_Context->y_Auto3536+340+16))) {
			return(12); /* ImageName */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+180+0) ) 
		&&  ( my >= (_Context->y_Auto3536+390) ) 
		&&  ( mx <= (_Context->x_Auto3536+180+140) ) 
		&&  ( my <= (_Context->y_Auto3536+390+16))) {
			return(13); /* ImageType */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+330) ) 
		&&  ( my >= (_Context->y_Auto3536+390) ) 
		&&  ( mx <= (_Context->x_Auto3536+330+140) ) 
		&&  ( my <= (_Context->y_Auto3536+390+16))) {
			return(14); /* Quality */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+330) ) 
		&&  ( my >= (_Context->y_Auto3536+410) ) 
		&&  ( mx <= (_Context->x_Auto3536+330+140) ) 
		&&  ( my <= (_Context->y_Auto3536+410+16))) {
			return(15); /* SaveImages */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+180) ) 
		&&  ( my >= (_Context->y_Auto3536+410) ) 
		&&  ( mx <= (_Context->x_Auto3536+180+80) ) 
		&&  ( my <= (_Context->y_Auto3536+410+16))) {
			return(16); /* Colour */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+460) ) 
		&&  ( my >= (_Context->y_Auto3536+390) ) 
		&&  ( mx <= (_Context->x_Auto3536+460+140) ) 
		&&  ( my <= (_Context->y_Auto3536+390+16))) {
			return(17); /* ApplyStyle */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+460) ) 
		&&  ( my >= (_Context->y_Auto3536+410) ) 
		&&  ( mx <= (_Context->x_Auto3536+460+154) ) 
		&&  ( my <= (_Context->y_Auto3536+410+16))) {
			return(18); /* SaveForms */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+180+0) ) 
		&&  ( my >= (_Context->y_Auto3536+440) ) 
		&&  ( mx <= (_Context->x_Auto3536+180+140) ) 
		&&  ( my <= (_Context->y_Auto3536+440+16))) {
			return(19); /* NationalLanguage */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+330) ) 
		&&  ( my >= (_Context->y_Auto3536+440) ) 
		&&  ( mx <= (_Context->x_Auto3536+330+238) ) 
		&&  ( my <= (_Context->y_Auto3536+440+16))) {
			return(20); /* RollBack */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+330) ) 
		&&  ( my >= (_Context->y_Auto3536+460) ) 
		&&  ( mx <= (_Context->x_Auto3536+330+238) ) 
		&&  ( my <= (_Context->y_Auto3536+460+16))) {
			return(21); /* CameraLock */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+180+0) ) 
		&&  ( my >= (_Context->y_Auto3536+460) ) 
		&&  ( mx <= (_Context->x_Auto3536+180+72) ) 
		&&  ( my <= (_Context->y_Auto3536+460+16))) {
			return(22); /* Extension */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+340) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+340+16))) {
			return(23); /* Select */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+320) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+320+16))) {
			return(24); /* Auto3555 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+263) ) 
		&&  ( my >= (_Context->y_Auto3536+410) ) 
		&&  ( mx <= (_Context->x_Auto3536+263+56) ) 
		&&  ( my <= (_Context->y_Auto3536+410+16))) {
			return(25); /* fgSelect */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+100) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+100+16))) {
			return(26); /* Choixfconf */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+120) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+120+16))) {
			return(27); /* ChoixBase */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+140) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+140+16))) {
			return(28); /* ChoixTemplate */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+160) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+160+16))) {
			return(29); /* ChoixModules */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+180) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+180+16))) {
			return(30); /* ChooseComponents */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+230) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+230+16))) {
			return(31); /* Auto3556 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+250) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+250+16))) {
			return(32); /* Auto3557 */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3536+580) ) 
		&&  ( my >= (_Context->y_Auto3536+270) ) 
		&&  ( mx <= (_Context->x_Auto3536+580+20) ) 
		&&  ( my <= (_Context->y_Auto3536+270+16))) {
			return(33); /* Auto3558 */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3536+10+118) ) 
		&&  ( my >= (_Context->y_Auto3536+30) ) 
		&&  ( mx <= (_Context->x_Auto3536+10+219) ) 
		&&  ( my <= (_Context->y_Auto3536+30+24))) {
			return(34); /* Auto3559 */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+140) ) 
		&&  ( my >= (_Context->y_Auto3536+120) ) 
		&&  ( mx <= (_Context->x_Auto3536+140+456) ) 
		&&  ( my <= (_Context->y_Auto3536+120+16))) {
			return(35); /* Name */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+140) ) 
		&&  ( my >= (_Context->y_Auto3536+210) ) 
		&&  ( mx <= (_Context->x_Auto3536+140+88) ) 
		&&  ( my <= (_Context->y_Auto3536+210+16))) {
			return(36); /* AtX */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+260) ) 
		&&  ( my >= (_Context->y_Auto3536+210) ) 
		&&  ( mx <= (_Context->x_Auto3536+260+88) ) 
		&&  ( my <= (_Context->y_Auto3536+210+16))) {
			return(37); /* AtY */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+380) ) 
		&&  ( my >= (_Context->y_Auto3536+210) ) 
		&&  ( mx <= (_Context->x_Auto3536+380+80) ) 
		&&  ( my <= (_Context->y_Auto3536+210+16))) {
			return(38); /* AtZ */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+490) ) 
		&&  ( my >= (_Context->y_Auto3536+210) ) 
		&&  ( mx <= (_Context->x_Auto3536+490+112) ) 
		&&  ( my <= (_Context->y_Auto3536+210+16))) {
			return(39); /* DynamicSize */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+140) ) 
		&&  ( my >= (_Context->y_Auto3536+230) ) 
		&&  ( mx <= (_Context->x_Auto3536+140+88) ) 
		&&  ( my <= (_Context->y_Auto3536+230+16))) {
			return(40); /* ToX */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+260) ) 
		&&  ( my >= (_Context->y_Auto3536+230) ) 
		&&  ( mx <= (_Context->x_Auto3536+260+88) ) 
		&&  ( my <= (_Context->y_Auto3536+230+16))) {
			return(41); /* ToY */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+490+0) ) 
		&&  ( my >= (_Context->y_Auto3536+230) ) 
		&&  ( mx <= (_Context->x_Auto3536+490+112) ) 
		&&  ( my <= (_Context->y_Auto3536+230+16))) {
			return(42); /* Direction */
			}
		}
	if (( mx >= (_Context->x_Auto3536+10) ) 
	&&  ( my >= (_Context->y_Auto3536+510) ) 
	&&  ( mx <= (_Context->x_Auto3536+10+56) ) 
	&&  ( my <= (_Context->y_Auto3536+510+48))) {
		return(43); /* Accept */
		}
	if (( mx >= (_Context->x_Auto3536+560) ) 
	&&  ( my >= (_Context->y_Auto3536+510) ) 
	&&  ( mx <= (_Context->x_Auto3536+560+56) ) 
	&&  ( my <= (_Context->y_Auto3536+510+48))) {
		return(44); /* Cancel */
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+140) ) 
		&&  ( my >= (_Context->y_Auto3536+320) ) 
		&&  ( mx <= (_Context->x_Auto3536+140+88) ) 
		&&  ( my <= (_Context->y_Auto3536+320+16))) {
			return(45); /* NbX */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+260) ) 
		&&  ( my >= (_Context->y_Auto3536+320) ) 
		&&  ( mx <= (_Context->x_Auto3536+260+88) ) 
		&&  ( my <= (_Context->y_Auto3536+320+16))) {
			return(46); /* nbY */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+380) ) 
		&&  ( my >= (_Context->y_Auto3536+320) ) 
		&&  ( mx <= (_Context->x_Auto3536+380+80) ) 
		&&  ( my <= (_Context->y_Auto3536+320+16))) {
			return(47); /* NbZ */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+510) ) 
		&&  ( my >= (_Context->y_Auto3536+320) ) 
		&&  ( mx <= (_Context->x_Auto3536+510+88) ) 
		&&  ( my <= (_Context->y_Auto3536+320+16))) {
			return(48); /* Step */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+140) ) 
		&&  ( my >= (_Context->y_Auto3536+340) ) 
		&&  ( mx <= (_Context->x_Auto3536+140+88) ) 
		&&  ( my <= (_Context->y_Auto3536+340+16))) {
			return(49); /* StepX */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+260) ) 
		&&  ( my >= (_Context->y_Auto3536+340) ) 
		&&  ( mx <= (_Context->x_Auto3536+260+88) ) 
		&&  ( my <= (_Context->y_Auto3536+340+16))) {
			return(50); /* StepY */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+380) ) 
		&&  ( my >= (_Context->y_Auto3536+340) ) 
		&&  ( mx <= (_Context->x_Auto3536+380+80) ) 
		&&  ( my <= (_Context->y_Auto3536+340+16))) {
			return(51); /* StepZ */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+140+0) ) 
		&&  ( my >= (_Context->y_Auto3536+370) ) 
		&&  ( mx <= (_Context->x_Auto3536+140+88) ) 
		&&  ( my <= (_Context->y_Auto3536+370+16))) {
			return(52); /* ImageFormat */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+260) ) 
		&&  ( my >= (_Context->y_Auto3536+370) ) 
		&&  ( mx <= (_Context->x_Auto3536+260+168) ) 
		&&  ( my <= (_Context->y_Auto3536+370+16))) {
			return(53); /* ForceCIT */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3536+140) ) 
		&&  ( my >= (_Context->y_Auto3536+460) ) 
		&&  ( mx <= (_Context->x_Auto3536+140+456) ) 
		&&  ( my <= (_Context->y_Auto3536+460+16))) {
			return(54); /* DefaultStyle */
			}
		}

	return(-1);
}


public	int	accept_camera_properties_losefocus(struct accept_camera_properties_context * _Context)
{
	switch (_Context->page_number) {
		case 1 : 
			break;
		case 2 : 
			break;

		}
	return(0);

}


public	int	accept_camera_properties_focus(struct accept_camera_properties_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* Auto3537 */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* Configuration */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+100+1,424,16,vfh[1],_Context->buffer_Configuration,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* DataBase */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+120+1,424,16,vfh[1],_Context->buffer_DataBase,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* Template */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+140+1,424,16,vfh[1],_Context->buffer_Template,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* Modules */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+160+1,424,16,vfh[1],_Context->buffer_Modules,400);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* Components */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+180+1,424,16,vfh[1],_Context->buffer_Components,400);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* FormsDirectory */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+230+1,424,16,vfh[1],_Context->buffer_FormsDirectory,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* SourcesDirectory */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+250+1,424,16,vfh[1],_Context->buffer_SourcesDirectory,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* ObjectsDirectory */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+270+1,424,16,vfh[1],_Context->buffer_ObjectsDirectory,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* PaletteName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+320+1,424,16,vfh[1],_Context->buffer_PaletteName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* ImageName */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+150+1,_Context->y_Auto3536+340+1,424,16,vfh[1],_Context->buffer_ImageName,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* ImageType */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3536+180,_Context->y_Auto3536+390,140,90,vfh[2],0,0,parse_selection(WidgetImageList,&_Context->value_ImageType),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* Quality */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+390,140,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),(_Context->value_Quality |2));
					_Context->keycode = visual_getch();
					_Context->trigger_Quality=visual_trigger_code(_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+390,140,16,vfh[2],27,28,_Context->msg_Quality[_Context->language],strlen(_Context->msg_Quality[_Context->language]),_Context->value_Quality|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* SaveImages */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+410,140,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),(_Context->value_SaveImages |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SaveImages=visual_trigger_code(_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+410,140,16,vfh[2],26,0,_Context->msg_SaveImages[_Context->language],strlen(_Context->msg_SaveImages[_Context->language]),_Context->value_SaveImages|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* Colour */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+180+1,_Context->y_Auto3536+410+1,80,16,vfh[1],_Context->buffer_Colour,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* ApplyStyle */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3536+460,_Context->y_Auto3536+390,140,16,vfh[2],27,28,_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]),(_Context->value_ApplyStyle |2));
					_Context->keycode = visual_getch();
					_Context->trigger_ApplyStyle=visual_trigger_code(_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]));
	visual_check(_Context->x_Auto3536+460,_Context->y_Auto3536+390,140,16,vfh[2],27,28,_Context->msg_ApplyStyle[_Context->language],strlen(_Context->msg_ApplyStyle[_Context->language]),_Context->value_ApplyStyle|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* SaveForms */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3536+460,_Context->y_Auto3536+410,154,16,vfh[2],26,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),(_Context->value_SaveForms |2));
					_Context->keycode = visual_getch();
					_Context->trigger_SaveForms=visual_trigger_code(_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]));
	visual_check(_Context->x_Auto3536+460,_Context->y_Auto3536+410,154,16,vfh[2],26,0,_Context->msg_SaveForms[_Context->language],strlen(_Context->msg_SaveForms[_Context->language]),_Context->value_SaveForms|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* NationalLanguage */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3536+180,_Context->y_Auto3536+440,140,80,vfh[2],27,0,parse_selection(NationalLanguageList,&_Context->value_NationalLanguage),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* RollBack */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+440,238,16,vfh[2],0,0,_Context->msg_RollBack[_Context->language],strlen(_Context->msg_RollBack[_Context->language]),(_Context->value_RollBack |2));
					_Context->keycode = visual_getch();
					_Context->trigger_RollBack=visual_trigger_code(_Context->msg_RollBack[_Context->language],strlen(_Context->msg_RollBack[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+440,238,16,vfh[2],0,0,_Context->msg_RollBack[_Context->language],strlen(_Context->msg_RollBack[_Context->language]),_Context->value_RollBack|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* CameraLock */
				if (_Context->page_number == 1 ) {
				visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+460,238,16,vfh[2],0,0,_Context->msg_CameraLock[_Context->language],strlen(_Context->msg_CameraLock[_Context->language]),(_Context->value_CameraLock |2));
					_Context->keycode = visual_getch();
					_Context->trigger_CameraLock=visual_trigger_code(_Context->msg_CameraLock[_Context->language],strlen(_Context->msg_CameraLock[_Context->language]));
	visual_check(_Context->x_Auto3536+330,_Context->y_Auto3536+460,238,16,vfh[2],0,0,_Context->msg_CameraLock[_Context->language],strlen(_Context->msg_CameraLock[_Context->language]),_Context->value_CameraLock|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* Extension */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_select(_Context->x_Auto3536+180,_Context->y_Auto3536+460,72,32,vfh[1],0,0,parse_selection(_Context->msg_Extension[_Context->language],&_Context->value_Extension),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* Select */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+340,20,16,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+340,20,16,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* Auto3555 */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+320,20,16,vfh[8],27,28,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+320,20,16,vfh[8],27,28,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* fgSelect */
				if (_Context->page_number == 1 ) {
					_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
					visual_button(_Context->x_Auto3536+263,_Context->y_Auto3536+410,56,16,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_Auto3536+263,_Context->y_Auto3536+410,56,16,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* Choixfconf */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* ChoixBase */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChoixBase=visual_trigger_code(_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+120,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixBase=visual_trigger_code(_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+120,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* ChoixTemplate */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChoixTemplate=visual_trigger_code(_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+140,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixTemplate=visual_trigger_code(_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+140,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* ChoixModules */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChoixModules=visual_trigger_code(_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+160,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixModules=visual_trigger_code(_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+160,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* ChooseComponents */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChooseComponents=visual_trigger_code(_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+180,20,16,vfh[8],27,28,_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChooseComponents=visual_trigger_code(_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+180,20,16,vfh[8],27,28,_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* Auto3556 */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Auto3556=visual_trigger_code(_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+230,20,16,vfh[8],27,28,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3556=visual_trigger_code(_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+230,20,16,vfh[8],27,28,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* Auto3557 */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+250,20,16,vfh[8],27,28,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+250,20,16,vfh[8],27,28,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* Auto3558 */
				if (_Context->page_number == 1 ) {
					_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
					visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+270,20,16,vfh[8],27,28,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+270,20,16,vfh[8],27,28,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* Auto3559 */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x23 :
				/* Name */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+140+1,_Context->y_Auto3536+120+1,456,16,vfh[1],_Context->buffer_Name,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* AtX */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+140+1,_Context->y_Auto3536+210+1,88,16,vfh[1],_Context->buffer_AtX,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* AtY */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+260+1,_Context->y_Auto3536+210+1,88,16,vfh[1],_Context->buffer_AtY,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* AtZ */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+380+1,_Context->y_Auto3536+210+1,80,16,vfh[1],_Context->buffer_AtZ,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* DynamicSize */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3536+490,_Context->y_Auto3536+210,112,16,vfh[2],26,0,_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]),(_Context->value_DynamicSize |2));
					_Context->keycode = visual_getch();
					_Context->trigger_DynamicSize=visual_trigger_code(_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]));
	visual_check(_Context->x_Auto3536+490,_Context->y_Auto3536+210,112,16,vfh[2],26,0,_Context->msg_DynamicSize[_Context->language],strlen(_Context->msg_DynamicSize[_Context->language]),_Context->value_DynamicSize|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* ToX */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+140+1,_Context->y_Auto3536+230+1,88,16,vfh[1],_Context->buffer_ToX,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* ToY */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+260+1,_Context->y_Auto3536+230+1,88,16,vfh[1],_Context->buffer_ToY,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* Direction */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_Auto3536+490,_Context->y_Auto3536+230,112,64,vfh[2],26,0,parse_selection(_Context->msg_Direction[_Context->language],&_Context->value_Direction),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* Accept */
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
				visual_button(_Context->x_Auto3536+10,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3536+10,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
				break;
			case	0x2c :
				/* Cancel */
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
				visual_button(_Context->x_Auto3536+560,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
				_Context->keycode = visual_getch();
				_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3536+560,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
				break;
			case	0x2d :
				/* NbX */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+140+1,_Context->y_Auto3536+320+1,88,16,vfh[1],_Context->buffer_NbX,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* nbY */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+260+1,_Context->y_Auto3536+320+1,88,16,vfh[1],_Context->buffer_nbY,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* NbZ */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+380+1,_Context->y_Auto3536+320+1,80,16,vfh[1],_Context->buffer_NbZ,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* Step */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+510+1,_Context->y_Auto3536+320+1,88,16,vfh[1],_Context->buffer_Step,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* StepX */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+140+1,_Context->y_Auto3536+340+1,88,16,vfh[1],_Context->buffer_StepX,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* StepY */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+260+1,_Context->y_Auto3536+340+1,88,16,vfh[1],_Context->buffer_StepY,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* StepZ */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+380+1,_Context->y_Auto3536+340+1,80,16,vfh[1],_Context->buffer_StepZ,10);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* ImageFormat */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_select(_Context->x_Auto3536+140,_Context->y_Auto3536+370,88,96,vfh[2],0,0,parse_selection(ImageFormatList,&_Context->value_ImageFormat),774);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* ForceCIT */
				if (_Context->page_number == 2 ) {
				visual_check(_Context->x_Auto3536+260,_Context->y_Auto3536+370,168,16,vfh[2],16,28,_Context->msg_ForceCIT[_Context->language],strlen(_Context->msg_ForceCIT[_Context->language]),(_Context->value_ForceCIT |2));
					_Context->keycode = visual_getch();
					_Context->trigger_ForceCIT=visual_trigger_code(_Context->msg_ForceCIT[_Context->language],strlen(_Context->msg_ForceCIT[_Context->language]));
	visual_check(_Context->x_Auto3536+260,_Context->y_Auto3536+370,168,16,vfh[2],16,28,_Context->msg_ForceCIT[_Context->language],strlen(_Context->msg_ForceCIT[_Context->language]),_Context->value_ForceCIT|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* DefaultStyle */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3536+140+1,_Context->y_Auto3536+460+1,456,16,vfh[1],_Context->buffer_DefaultStyle,57);
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
			accept_camera_properties_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_camera_properties_show(_Context);
			continue;
		case	0x2 :
			accept_camera_properties_losefocus(_Context);
			_Context->page_number=2;
			_Context->focus_item=54;
			accept_camera_properties_show(_Context);
			continue;
		case	0x3 :
			accept_camera_properties_losefocus(_Context);
			if ( _Context->page_number < 2 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_camera_properties_show(_Context);
			continue;
		case	0x12 :
			accept_camera_properties_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_camera_properties_show(_Context);
			continue;
		case	0x100 :
			if ((retcode=accept_camera_properties_event(_Context)) == -1)
				continue;
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x3 :
						if (Configuration_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4 :
						if (DataBase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (Template_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (Modules_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (Components_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (FormsDirectory_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (SourcesDirectory_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (ObjectsDirectory_help(_Context) != 0) { continue; }
						else { break; }
					case	0xb :
						if (PaletteName_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (ImageName_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (ImageType_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (Colour_help(_Context) != 0) { continue; }
						else { break; }
					case	0x11 :
						if (ApplyStyle_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (SaveForms_help(_Context) != 0) { continue; }
						else { break; }
					case	0x13 :
						if (NationalLanguage_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (RollBack_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (CameraLock_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (Select_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (Choixfconf_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (ChoixBase_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1c :
						if (ChoixTemplate_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (ChoixModules_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1e :
						if (ChooseComponents_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1f :
						if (Auto3556_help(_Context) != 0) { continue; }
						else { break; }
					case	0x20 :
						if (Auto3557_help(_Context) != 0) { continue; }
						else { break; }
					case	0x21 :
						if (Auto3558_help(_Context) != 0) { continue; }
						else { break; }
					case	0x24 :
						if (AtX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (DynamicSize_help(_Context) != 0) { continue; }
						else { break; }
					case	0x28 :
						if (ToX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2a :
						if (Direction_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2b :
						if (Accept_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2c :
						if (Cancel_help(_Context) != 0) { continue; }
						else { break; }
					case	0x30 :
						if (Step_help(_Context) != 0) { continue; }
						else { break; }
					case	0x31 :
						if (StepX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x34 :
						if (ImageFormat_help(_Context) != 0) { continue; }
						else { break; }
					case	0x35 :
						if (ForceCIT_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3536 */
					if (visual_event(1) & _MIMO_UP) {
						_Context->keycode=27;
						break;
					} else {
						continue;
						}
				case	0x2 :
					/* Auto3537 */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_camera_properties_losefocus(_Context);
						_Context->page_number = 1;
						accept_camera_properties_show(_Context);
						}
					continue;
				case	0x3 :
					/* Configuration */
					continue;
				case	0x4 :
					/* DataBase */
					continue;
				case	0x5 :
					/* Template */
					continue;
				case	0x6 :
					/* Modules */
					continue;
				case	0x7 :
					/* Components */
					continue;
				case	0x8 :
					/* FormsDirectory */
					continue;
				case	0x9 :
					/* SourcesDirectory */
					continue;
				case	0xa :
					/* ObjectsDirectory */
					continue;
				case	0xb :
					/* PaletteName */
					continue;
				case	0xc :
					/* ImageName */
					continue;
				case	0xd :
					/* ImageType */
					continue;
				case	0xe :
					/* Quality */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_Quality += 1;
						_Context->value_Quality &= 1;
						}
					continue;
				case	0xf :
					/* SaveImages */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SaveImages += 1;
						_Context->value_SaveImages &= 1;
						}
					continue;
				case	0x10 :
					/* Colour */
					continue;
				case	0x11 :
					/* ApplyStyle */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ApplyStyle += 1;
						_Context->value_ApplyStyle &= 1;
						}
					continue;
				case	0x12 :
					/* SaveForms */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_SaveForms += 1;
						_Context->value_SaveForms &= 1;
						}
					continue;
				case	0x13 :
					/* NationalLanguage */
					continue;
				case	0x14 :
					/* RollBack */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_RollBack += 1;
						_Context->value_RollBack &= 1;
						}
					continue;
				case	0x15 :
					/* CameraLock */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_CameraLock += 1;
						_Context->value_CameraLock &= 1;
						}
					continue;
				case	0x16 :
					/* Extension */
					continue;
				case	0x17 :
					/* Select */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+340,20,16,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Select=visual_trigger_code(_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+340,20,16,vfh[2],27,24,_Context->msg_Select[_Context->language],strlen(_Context->msg_Select[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Select_event(_Context)) != -1) break;

						}
					continue;
				case	0x18 :
					/* Auto3555 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+320,20,16,vfh[8],27,28,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3555=visual_trigger_code(_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+320,20,16,vfh[8],27,28,_Context->msg_Auto3555[_Context->language],strlen(_Context->msg_Auto3555[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3555_event(_Context)) != -1) break;

						}
					continue;
				case	0x19 :
					/* fgSelect */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
						visual_button(_Context->x_Auto3536+263,_Context->y_Auto3536+410,56,16,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_fgSelect=visual_trigger_code(_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]));
	visual_button(_Context->x_Auto3536+263,_Context->y_Auto3536+410,56,16,vfh[8],16,0,_Context->msg_fgSelect[_Context->language],strlen(_Context->msg_fgSelect[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_fgSelect_event(_Context)) != -1) break;

						}
					continue;
				case	0x1a :
					/* Choixfconf */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Choixfconf=visual_trigger_code(_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+100,20,16,vfh[8],27,28,_Context->msg_Choixfconf[_Context->language],strlen(_Context->msg_Choixfconf[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Choixfconf_event(_Context)) != -1) break;

						}
					continue;
				case	0x1b :
					/* ChoixBase */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixBase=visual_trigger_code(_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+120,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixBase=visual_trigger_code(_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+120,20,16,vfh[8],27,28,_Context->msg_ChoixBase[_Context->language],strlen(_Context->msg_ChoixBase[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixBase_event(_Context)) != -1) break;

						}
					continue;
				case	0x1c :
					/* ChoixTemplate */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixTemplate=visual_trigger_code(_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+140,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixTemplate=visual_trigger_code(_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+140,20,16,vfh[8],27,28,_Context->msg_ChoixTemplate[_Context->language],strlen(_Context->msg_ChoixTemplate[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixTemplate_event(_Context)) != -1) break;

						}
					continue;
				case	0x1d :
					/* ChoixModules */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixModules=visual_trigger_code(_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+160,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixModules=visual_trigger_code(_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+160,20,16,vfh[8],27,28,_Context->msg_ChoixModules[_Context->language],strlen(_Context->msg_ChoixModules[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixModules_event(_Context)) != -1) break;

						}
					continue;
				case	0x1e :
					/* ChooseComponents */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChooseComponents=visual_trigger_code(_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+180,20,16,vfh[8],27,28,_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChooseComponents=visual_trigger_code(_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+180,20,16,vfh[8],27,28,_Context->msg_ChooseComponents[_Context->language],strlen(_Context->msg_ChooseComponents[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChooseComponents_event(_Context)) != -1) break;

						}
					continue;
				case	0x1f :
					/* Auto3556 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3556=visual_trigger_code(_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+230,20,16,vfh[8],27,28,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3556=visual_trigger_code(_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+230,20,16,vfh[8],27,28,_Context->msg_Auto3556[_Context->language],strlen(_Context->msg_Auto3556[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3556_event(_Context)) != -1) break;

						}
					continue;
				case	0x20 :
					/* Auto3557 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+250,20,16,vfh[8],27,28,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3557=visual_trigger_code(_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+250,20,16,vfh[8],27,28,_Context->msg_Auto3557[_Context->language],strlen(_Context->msg_Auto3557[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3557_event(_Context)) != -1) break;

						}
					continue;
				case	0x21 :
					/* Auto3558 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
						visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+270,20,16,vfh[8],27,28,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Auto3558=visual_trigger_code(_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]));
	visual_button(_Context->x_Auto3536+580,_Context->y_Auto3536+270,20,16,vfh[8],27,28,_Context->msg_Auto3558[_Context->language],strlen(_Context->msg_Auto3558[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Auto3558_event(_Context)) != -1) break;

						}
					continue;
				case	0x22 :
					/* Auto3559 */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_camera_properties_losefocus(_Context);
						_Context->page_number = 2;
						accept_camera_properties_show(_Context);
						}
					continue;
				case	0x23 :
					/* Name */
					continue;
				case	0x24 :
					/* AtX */
					continue;
				case	0x25 :
					/* AtY */
					continue;
				case	0x26 :
					/* AtZ */
					continue;
				case	0x27 :
					/* DynamicSize */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_DynamicSize += 1;
						_Context->value_DynamicSize &= 1;
						}
					continue;
				case	0x28 :
					/* ToX */
					continue;
				case	0x29 :
					/* ToY */
					continue;
				case	0x2a :
					/* Direction */
					continue;
				case	0x2b :
					/* Accept */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
						visual_button(_Context->x_Auto3536+10,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Accept=visual_trigger_code(_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]));
	visual_button(_Context->x_Auto3536+10,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Accept[_Context->language],strlen(_Context->msg_Accept[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Accept_event(_Context)) != -1) break;

						}
					continue;
				case	0x2c :
					/* Cancel */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
						visual_button(_Context->x_Auto3536+560,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1042);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_Cancel=visual_trigger_code(_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]));
	visual_button(_Context->x_Auto3536+560,_Context->y_Auto3536+510,56,48,vfh[2],34,0,_Context->msg_Cancel[_Context->language],strlen(_Context->msg_Cancel[_Context->language]),1040);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_Cancel_event(_Context)) != -1) break;

						}
					continue;
				case	0x2d :
					/* NbX */
					continue;
				case	0x2e :
					/* nbY */
					continue;
				case	0x2f :
					/* NbZ */
					continue;
				case	0x30 :
					/* Step */
					continue;
				case	0x31 :
					/* StepX */
					continue;
				case	0x32 :
					/* StepY */
					continue;
				case	0x33 :
					/* StepZ */
					continue;
				case	0x34 :
					/* ImageFormat */
					continue;
				case	0x35 :
					/* ForceCIT */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_ForceCIT += 1;
						_Context->value_ForceCIT &= 1;
						}
					continue;
				case	0x36 :
					/* DefaultStyle */
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

public	int	accept_camera_properties(
	char * pConfiguration,
	char * pDataBase,
	char * pTemplate,
	char * pModules,
	char * pComponents,
	char * pFormsDirectory,
	char * pSourcesDirectory,
	char * pObjectsDirectory,
	char * pPaletteName,
	char * pImageName,
	char * pImageType,
	char * pQuality,
	char * pSaveImages,
	char * pColour,
	char * pApplyStyle,
	char * pSaveForms,
	char * pNationalLanguage,
	char * pRollBack,
	char * pCameraLock,
	char * pExtension,
	char * pName,
	char * pAtX,
	char * pAtY,
	char * pAtZ,
	char * pDynamicSize,
	char * pToX,
	char * pToY,
	char * pDirection,
	char * pNbX,
	char * pnbY,
	char * pNbZ,
	char * pStep,
	char * pStepX,
	char * pStepY,
	char * pStepZ,
	char * pImageFormat,
	char * pForceCIT,
	char * pDefaultStyle)
{
	int	status=0;
	struct accept_camera_properties_context * _Context=(struct accept_camera_properties_context*) 0;
	status = accept_camera_properties_create(
	&_Context,
	 pConfiguration,
	 pDataBase,
	 pTemplate,
	 pModules,
	 pComponents,
	 pFormsDirectory,
	 pSourcesDirectory,
	 pObjectsDirectory,
	 pPaletteName,
	 pImageName,
	 pImageType,
	 pQuality,
	 pSaveImages,
	 pColour,
	 pApplyStyle,
	 pSaveForms,
	 pNationalLanguage,
	 pRollBack,
	 pCameraLock,
	 pExtension,
	 pName,
	 pAtX,
	 pAtY,
	 pAtZ,
	 pDynamicSize,
	 pToX,
	 pToY,
	 pDirection,
	 pNbX,
	 pnbY,
	 pNbZ,
	 pStep,
	 pStepX,
	 pStepY,
	 pStepZ,
	 pImageFormat,
	 pForceCIT,
	 pDefaultStyle);
	if ( status != 0) return(status);
	status = accept_camera_properties_show(_Context);
		enter_modal();
	status = accept_camera_properties_focus(_Context);
		leave_modal();
	status = accept_camera_properties_hide(_Context);
	status = accept_camera_properties_remove(
	_Context,
	 pConfiguration,
	 pDataBase,
	 pTemplate,
	 pModules,
	 pComponents,
	 pFormsDirectory,
	 pSourcesDirectory,
	 pObjectsDirectory,
	 pPaletteName,
	 pImageName,
	 pImageType,
	 pQuality,
	 pSaveImages,
	 pColour,
	 pApplyStyle,
	 pSaveForms,
	 pNationalLanguage,
	 pRollBack,
	 pCameraLock,
	 pExtension,
	 pName,
	 pAtX,
	 pAtY,
	 pAtZ,
	 pDynamicSize,
	 pToX,
	 pToY,
	 pDirection,
	 pNbX,
	 pnbY,
	 pNbZ,
	 pStep,
	 pStepX,
	 pStepY,
	 pStepZ,
	 pImageFormat,
	 pForceCIT,
	 pDefaultStyle);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vcamera_c */
