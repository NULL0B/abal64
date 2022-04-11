
#ifndef _vrefer_c
#define _vrefer_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 1.1a.0.45  */
/* Production     : C  */
/* Project        : vrefer.xml  */
/* Target         : vrefer.c  */
/* Identification : 0.0-1100085277-2982.2981 */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "singprot.h"
#define en_Auto5703   "Sing : Version 1.0a"
#define fr_Auto5703   "Sing : Version 1.0a"
#define en_Auto6246   "skin.gif"
#define fr_Auto6246   "skin.gif"
#define en_General   "&General"
#define fr_General   "&Generaux"
#define en_Auto5988   "General Configuration"
#define en_Auto5994   "FILENAME"
#define fr_Auto5994   "Nom de Fichier"
#define it_Auto5994   ""
#define es_Auto5994   ""
#define de_Auto5994   ""
#define nl_Auto5994   ""
#define pt_Auto5994   ""
#define xx_Auto5994   ""
#define en_Auto5996   "ABALHOST"
#define fr_Auto5996   "ABALHOST"
#define it_Auto5996   "ABALHOST"
#define es_Auto5996   "ABALHOST"
#define de_Auto5996   "ABALHOST"
#define nl_Auto5996   "ABALHOST"
#define pt_Auto5996   "ABALHOST"
#define xx_Auto5996   "ABALHOST"
#define en_Auto5998   "IDENTITY"
#define fr_Auto5998   "Identit‚"
#define xx_Auto5998   "Ainm"
#define en_Auto6000   "REPLAY"
#define fr_Auto6000   "Re-enacter"
#define it_Auto6000   "REPLAY"
#define es_Auto6000   "REPLAY"
#define de_Auto6000   "REPLAY"
#define nl_Auto6000   "REPLAY"
#define pt_Auto6000   "REPLAY"
#define xx_Auto6000   "REPLAY"
#define en_Auto6002   "RECORD"
#define fr_Auto6002   "Enregistrer"
#define it_Auto6002   ""
#define es_Auto6002   ""
#define de_Auto6002   ""
#define nl_Auto6002   ""
#define pt_Auto6002   ""
#define xx_Auto6002   ""
#define en_Abal   "A&bal"
#define fr_Abal   "A&bal"
#define it_Abal   "A&bal"
#define es_Abal   "A&bal"
#define de_Abal   "A&bal"
#define nl_Abal   "A&bal"
#define pt_Abal   "A&bal"
#define xx_Abal   "A&bal"
#define en_Auto6012   "ABAL"
#define fr_Auto6012   "ABAL"
#define it_Auto6012   "ABAL"
#define es_Auto6012   "ABAL"
#define de_Auto6012   "ABAL"
#define nl_Auto6012   "ABAL"
#define pt_Auto6012   "ABAL"
#define xx_Auto6012   "ABAL"
#define en_Auto6014   "ATR"
#define fr_Auto6014   "ATR"
#define it_Auto6014   "ATR"
#define es_Auto6014   "ATR"
#define de_Auto6014   "ATR"
#define nl_Auto6014   "ATR"
#define pt_Auto6014   "ATR"
#define xx_Auto6014   "ATR"
#define en_Auto6016   "ATR.DEFINE"
#define fr_Auto6016   "ATR.DEFINE"
#define it_Auto6016   "ATR.DEFINE"
#define es_Auto6016   "ATR.DEFINE"
#define de_Auto6016   "ATR.DEFINE"
#define nl_Auto6016   "ATR.DEFINE"
#define pt_Auto6016   "ATR.DEFINE"
#define xx_Auto6016   "ATR.DEFINE"
#define en_Auto6018   "ATR.INCLUDE"
#define fr_Auto6018   "ATR.INCLUDE"
#define it_Auto6018   "ATR.INCLUDE"
#define es_Auto6018   "ATR.INCLUDE"
#define de_Auto6018   "ATR.INCLUDE"
#define nl_Auto6018   "ATR.INCLUDE"
#define pt_Auto6018   "ATR.INCLUDE"
#define xx_Auto6018   "ATR.INCLUDE"
#define en_Auto6020   "ATR.OPTIONS"
#define fr_Auto6020   "ATR.OPTIONS"
#define it_Auto6020   "ATR.OPTIONS"
#define es_Auto6020   "ATR.OPTIONS"
#define de_Auto6020   "ATR.OPTIONS"
#define nl_Auto6020   "ATR.OPTIONS"
#define pt_Auto6020   "ATR.OPTIONS"
#define xx_Auto6020   "ATR.OPTIONS"
#define en_Auto6022   "ALD.OPTIONS"
#define fr_Auto6022   "ALD.OPTIONS"
#define it_Auto6022   "ALD.OPTIONS"
#define es_Auto6022   "ALD.OPTIONS"
#define de_Auto6022   "ALD.OPTIONS"
#define nl_Auto6022   "ALD.OPTIONS"
#define pt_Auto6022   "ALD.OPTIONS"
#define xx_Auto6022   "ALD.OPTIONS"
#define en_Auto6024   "ALD"
#define fr_Auto6024   "ALD"
#define it_Auto6024   "ALD"
#define es_Auto6024   "ALD"
#define de_Auto6024   "ALD"
#define nl_Auto6024   "ALD"
#define pt_Auto6024   "ALD"
#define xx_Auto6024   "ALD"
#define en_Auto6038   "ABAL++"
#define fr_Auto6038   "ABAL++"
#define it_Auto6038   "ABAL++"
#define es_Auto6038   "ABAL++"
#define de_Auto6038   "ABAL++"
#define nl_Auto6038   "ABAL++"
#define pt_Auto6038   "ABAL++"
#define xx_Auto6038   "ABAL++"
#define en_Auto6040   "ABAL and ABAL++"
#define fr_Auto6040   "ABAL et ABAL++"
#define it_Auto6040   "ABAL and ABAL++"
#define es_Auto6040   "ABAL and ABAL++"
#define de_Auto6040   "ABAL und ABAL++"
#define nl_Auto6040   "ABAL and ABAL++"
#define pt_Auto6040   "ABAL and ABAL++"
#define xx_Auto6040   "ABAL and ABAL++"
#define en_Auto6042   "OTR"
#define fr_Auto6042   "OTR"
#define it_Auto6042   "OTR"
#define es_Auto6042   "OTR"
#define de_Auto6042   "OTR"
#define nl_Auto6042   "OTR"
#define pt_Auto6042   "OTR"
#define xx_Auto6042   "OTR"
#define en_Auto6044   "OTR.DEFINE"
#define fr_Auto6044   "OTR.DEFINE"
#define it_Auto6044   "OTR.DEFINE"
#define es_Auto6044   "OTR.DEFINE"
#define de_Auto6044   "OTR.DEFINE"
#define nl_Auto6044   "OTR.DEFINE"
#define pt_Auto6044   "OTR.DEFINE"
#define xx_Auto6044   "OTR.DEFINE"
#define en_Auto6046   "OTR.INCLUDE"
#define fr_Auto6046   "OTR.INCLUDE"
#define it_Auto6046   "OTR.INCLUDE"
#define es_Auto6046   "OTR.INCLUDE"
#define de_Auto6046   "OTR.INCLUDE"
#define nl_Auto6046   "OTR.INCLUDE"
#define pt_Auto6046   "OTR.INCLUDE"
#define xx_Auto6046   "OTR.INCLUDE"
#define en_Auto6048   "OTR.OPTIONS"
#define fr_Auto6048   "OTR.OPTIONS"
#define it_Auto6048   "OTR.OPTIONS"
#define es_Auto6048   "OTR.OPTIONS"
#define de_Auto6048   "OTR.OPTIONS"
#define nl_Auto6048   "OTR.OPTIONS"
#define pt_Auto6048   "OTR.OPTIONS"
#define xx_Auto6048   "OTR.OPTIONS"
#define en_Auto6050   "OLD.OPTIONS"
#define fr_Auto6050   "OLD.OPTIONS"
#define it_Auto6050   "OLD.OPTIONS"
#define es_Auto6050   "OLD.OPTIONS"
#define de_Auto6050   "OLD.OPTIONS"
#define nl_Auto6050   "OLD.OPTIONS"
#define pt_Auto6050   "OLD.OPTIONS"
#define xx_Auto6050   "OLD.OPTIONS"
#define en_Auto6052   "OLD"
#define fr_Auto6052   "OLD"
#define it_Auto6052   "OLD"
#define es_Auto6052   "OLD"
#define de_Auto6052   "OLD"
#define nl_Auto6052   "OLD"
#define pt_Auto6052   "OLD"
#define xx_Auto6052   "OLD"
#define en_Auto6054   "EXA"
#define fr_Auto6054   "EXA"
#define it_Auto6054   "EXA"
#define es_Auto6054   "EXA"
#define de_Auto6054   "EXA"
#define nl_Auto6054   "EXA"
#define pt_Auto6054   "EXA"
#define xx_Auto6054   "EXA"
#define en_Auto6056   "EXADB"
#define fr_Auto6056   "EXADB"
#define it_Auto6056   "EXADB"
#define es_Auto6056   "EXADB"
#define de_Auto6056   "EXADB"
#define nl_Auto6056   "EXADB"
#define pt_Auto6056   "EXADB"
#define xx_Auto6056   "EXADB"
#define en_Images   "&Images"
#define fr_Images   "&Images"
#define it_Images   "&Images"
#define es_Images   "&Images"
#define de_Images   "&Images"
#define nl_Images   "&Images"
#define pt_Images   "&Images"
#define xx_Images   "&Images"
#define en_Auto6076   "IMAGEPATH"
#define fr_Auto6076   "IMAGEPATH"
#define it_Auto6076   "IMAGEPATH"
#define es_Auto6076   "IMAGEPATH"
#define de_Auto6076   "IMAGEPATH"
#define nl_Auto6076   "IMAGEPATH"
#define pt_Auto6076   "IMAGEPATH"
#define xx_Auto6076   "IMAGEPATH"
#define en_Auto6080   "ICONPATH"
#define fr_Auto6080   "ICONPATH"
#define it_Auto6080   "ICONPATH"
#define es_Auto6080   "ICONPATH"
#define de_Auto6080   "ICONPATH"
#define nl_Auto6080   "ICONPATH"
#define pt_Auto6080   "ICONPATH"
#define xx_Auto6080   "ICONPATH"
#define en_Auto6082   "PALETTE"
#define fr_Auto6082   "PALETTE"
#define it_Auto6082   "PALETTE"
#define es_Auto6082   "PALETTE"
#define de_Auto6082   "PALETTE"
#define nl_Auto6082   "PALETTE"
#define pt_Auto6082   "PALETTE"
#define xx_Auto6082   "PALETTE"
#define en_Auto6084   "SKIN"
#define fr_Auto6084   "SKIN"
#define it_Auto6084   "SKIN"
#define es_Auto6084   "SKIN"
#define de_Auto6084   "SKIN"
#define nl_Auto6084   "SKIN"
#define pt_Auto6084   "SKIN"
#define xx_Auto6084   "SKIN"
#define en_Auto6086   "TRIGGER.STYLE"
#define fr_Auto6086   "TRIGGER.STYLE"
#define it_Auto6086   "TRIGGER.STYLE"
#define es_Auto6086   "TRIGGER.STYLE"
#define de_Auto6086   "TRIGGER.STYLE"
#define nl_Auto6086   "TRIGGER.STYLE"
#define pt_Auto6086   "TRIGGER.STYLE"
#define xx_Auto6086   "TRIGGER.STYLE"
#define en_Auto6088   "TRIGGER.COLOUR"
#define fr_Auto6088   "TRIGGER.COLOUR"
#define it_Auto6088   "TRIGGER.COLOUR"
#define es_Auto6088   "TRIGGER.COLOUR"
#define de_Auto6088   "TRIGGER.COLOUR"
#define nl_Auto6088   "TRIGGER.COLOUR"
#define pt_Auto6088   "TRIGGER.COLOUR"
#define xx_Auto6088   "TRIGGER.COLOUR"
#define en_TRIGGER_STYLE   "colour|bold|underline"
#define fr_TRIGGER_STYLE   "colour|bold|underline"
#define it_TRIGGER_STYLE   "colour|bold|underline"
#define es_TRIGGER_STYLE   "colour|bold|underline"
#define de_TRIGGER_STYLE   "colour|bold|underline"
#define nl_TRIGGER_STYLE   "colour|bold|underline"
#define pt_TRIGGER_STYLE   "colour|bold|underline"
#define xx_TRIGGER_STYLE   "colour|bold|underline"
#define en_Fonts   "&Fonts"
#define fr_Fonts   "&Fontes"
#define it_Fonts   "&Fonts"
#define es_Fonts   "&Fonts"
#define de_Fonts   "&Fonts"
#define nl_Fonts   "&Fonts"
#define pt_Fonts   "&Fonts"
#define xx_Fonts   "&Fonts"
#define en_Auto6102   "Font Filenames"
#define fr_Auto6102   "Noms de Fichiers de Polices de CaractŠres"
#define it_Auto6102   "Font Filenames"
#define es_Auto6102   "Font Filenames"
#define de_Auto6102   "Font Filenames"
#define nl_Auto6102   "Font Filenames"
#define pt_Auto6102   "Font Filenames"
#define xx_Auto6102   "Font Filenames"
#define en_Auto6104   "FONTPATH"
#define fr_Auto6104   "FONTPATH"
#define it_Auto6104   "FONTPATH"
#define es_Auto6104   "FONTPATH"
#define de_Auto6104   "FONTPATH"
#define nl_Auto6104   "FONTPATH"
#define pt_Auto6104   "FONTPATH"
#define xx_Auto6104   "FONTPATH"
#define en_Auto6106   "FONT1"
#define fr_Auto6106   "FONT1"
#define it_Auto6106   "FONT1"
#define es_Auto6106   "FONT1"
#define de_Auto6106   "FONT1"
#define nl_Auto6106   "FONT1"
#define pt_Auto6106   "FONT1"
#define xx_Auto6106   "FONT1"
#define en_Auto6108   "FONT2"
#define fr_Auto6108   "FONT2"
#define it_Auto6108   "FONT2"
#define es_Auto6108   "FONT2"
#define de_Auto6108   "FONT2"
#define nl_Auto6108   "FONT2"
#define pt_Auto6108   "FONT2"
#define xx_Auto6108   "FONT2"
#define en_Auto6110   "FONT3"
#define fr_Auto6110   "FONT3"
#define it_Auto6110   "FONT3"
#define es_Auto6110   "FONT3"
#define de_Auto6110   "FONT3"
#define nl_Auto6110   "FONT3"
#define pt_Auto6110   "FONT3"
#define xx_Auto6110   "FONT3"
#define en_Auto6112   "FONT4"
#define fr_Auto6112   "FONT4"
#define it_Auto6112   "FONT4"
#define es_Auto6112   "FONT4"
#define de_Auto6112   "FONT4"
#define nl_Auto6112   "FONT4"
#define pt_Auto6112   "FONT4"
#define xx_Auto6112   "FONT4"
#define en_Auto6114   "FONT5"
#define fr_Auto6114   "FONT5"
#define it_Auto6114   "FONT5"
#define es_Auto6114   "FONT5"
#define de_Auto6114   "FONT5"
#define nl_Auto6114   "FONT5"
#define pt_Auto6114   "FONT5"
#define xx_Auto6114   "FONT5"
#define en_Auto6116   "FONT6"
#define fr_Auto6116   "FONT6"
#define it_Auto6116   "FONT6"
#define es_Auto6116   "FONT6"
#define de_Auto6116   "FONT6"
#define nl_Auto6116   "FONT6"
#define pt_Auto6116   "FONT6"
#define xx_Auto6116   "FONT6"
#define en_Auto6118   "FONT7"
#define fr_Auto6118   "FONT7"
#define it_Auto6118   "FONT7"
#define es_Auto6118   "FONT7"
#define de_Auto6118   "FONT7"
#define nl_Auto6118   "FONT7"
#define pt_Auto6118   "FONT7"
#define xx_Auto6118   "FONT7"
#define en_Auto6120   "FONT8"
#define fr_Auto6120   "FONT8"
#define it_Auto6120   "FONT8"
#define es_Auto6120   "FONT8"
#define de_Auto6120   "FONT8"
#define nl_Auto6120   "FONT8"
#define pt_Auto6120   "FONT8"
#define xx_Auto6120   "FONT8"
#define en_Auto6122   "FONT9"
#define fr_Auto6122   "FONT9"
#define it_Auto6122   "FONT9"
#define es_Auto6122   "FONT9"
#define de_Auto6122   "FONT9"
#define nl_Auto6122   "FONT9"
#define pt_Auto6122   "FONT9"
#define xx_Auto6122   "FONT9"
#define en_Auto6124   "FONT10"
#define fr_Auto6124   "FONT10"
#define it_Auto6124   "FONT10"
#define es_Auto6124   "FONT10"
#define de_Auto6124   "FONT10"
#define nl_Auto6124   "FONT10"
#define pt_Auto6124   "FONT10"
#define xx_Auto6124   "FONT10"
#define en_Documents   "&Documents"
#define fr_Documents   "&Documents"
#define it_Documents   "&Documents"
#define es_Documents   "&Documents"
#define de_Documents   "&Documents"
#define nl_Documents   "&Documents"
#define pt_Documents   "&Documents"
#define xx_Documents   "&Documents"
#define en_Auto6150   "Html Document Parameters"
#define fr_Auto6150   "ParamŠters des Documents en Html"
#define it_Auto6150   "Html Document Parameters"
#define es_Auto6150   "Html Document Parameters"
#define de_Auto6150   "Html Document Parameters"
#define nl_Auto6150   "Html Document Parameters"
#define pt_Auto6150   "Html Document Parameters"
#define xx_Auto6150   "Html Document Parameters"
#define en_Auto6152   "HTML.TITLE"
#define fr_Auto6152   "HTML.TITLE"
#define it_Auto6152   "HTML.TITLE"
#define es_Auto6152   "HTML.TITLE"
#define de_Auto6152   "HTML.TITLE"
#define nl_Auto6152   "HTML.TITLE"
#define pt_Auto6152   "HTML.TITLE"
#define xx_Auto6152   "HTML.TITLE"
#define en_Auto6154   "HTML.LOGO"
#define fr_Auto6154   "HTML.LOGO"
#define it_Auto6154   "HTML.LOGO"
#define es_Auto6154   "HTML.LOGO"
#define de_Auto6154   "HTML.LOGO"
#define nl_Auto6154   "HTML.LOGO"
#define pt_Auto6154   "HTML.LOGO"
#define xx_Auto6154   "HTML.LOGO"
#define en_Auto6156   "COPYRIGHT"
#define fr_Auto6156   "COPYRIGHT"
#define it_Auto6156   "COPYRIGHT"
#define es_Auto6156   "COPYRIGHT"
#define de_Auto6156   "COPYRIGHT"
#define nl_Auto6156   "COPYRIGHT"
#define pt_Auto6156   "COPYRIGHT"
#define xx_Auto6156   "COPYRIGHT"
#define en_Auto6158   "SCREEN.CSS"
#define fr_Auto6158   "SCREEN.CSS"
#define it_Auto6158   "SCREEN.CSS"
#define es_Auto6158   "SCREEN.CSS"
#define de_Auto6158   "SCREEN.CSS"
#define nl_Auto6158   "SCREEN.CSS"
#define pt_Auto6158   "SCREEN.CSS"
#define xx_Auto6158   "SCREEN.CSS"
#define en_Auto6160   "PRINT.CSS"
#define fr_Auto6160   "PRINT.CSS"
#define it_Auto6160   "PRINT.CSS"
#define es_Auto6160   "PRINT.CSS"
#define de_Auto6160   "PRINT.CSS"
#define nl_Auto6160   "PRINT.CSS"
#define pt_Auto6160   "PRINT.CSS"
#define xx_Auto6160   "PRINT.CSS"
#define en_Auto6162   "NAVIGATOR"
#define fr_Auto6162   "NAVIGATOR"
#define it_Auto6162   "NAVIGATOR"
#define es_Auto6162   "NAVIGATOR"
#define de_Auto6162   "NAVIGATOR"
#define nl_Auto6162   "NAVIGATOR"
#define pt_Auto6162   "NAVIGATOR"
#define xx_Auto6162   "NAVIGATOR"
#define en_Auto6164   "DOCPATH"
#define fr_Auto6164   "DOCPATH"
#define it_Auto6164   "DOCPATH"
#define es_Auto6164   "DOCPATH"
#define de_Auto6164   "DOCPATH"
#define nl_Auto6164   "DOCPATH"
#define pt_Auto6164   "DOCPATH"
#define xx_Auto6164   "DOCPATH"
#define en_Printing   "&Printing"
#define fr_Printing   "I&mpression"
#define it_Printing   "&Printing"
#define es_Printing   "&Printing"
#define de_Printing   "&Printing"
#define nl_Printing   "&Printing"
#define pt_Printing   "&Printing"
#define xx_Printing   "&Printing"
#define en_Auto6182   "PRINTER"
#define fr_Auto6182   "PRINTER"
#define it_Auto6182   "PRINTER"
#define es_Auto6182   "PRINTER"
#define de_Auto6182   "PRINTER"
#define nl_Auto6182   "PRINTER"
#define pt_Auto6182   "PRINTER"
#define xx_Auto6182   "PRINTER"
#define en_Auto6184   "RESOLUTION"
#define fr_Auto6184   "RESOLUTION"
#define it_Auto6184   "RESOLUTION"
#define es_Auto6184   "RESOLUTION"
#define de_Auto6184   "RESOLUTION"
#define nl_Auto6184   "RESOLUTION"
#define pt_Auto6184   "RESOLUTION"
#define xx_Auto6184   "RESOLUTION"
#define en_Auto6186   "PAPERTYPE"
#define fr_Auto6186   "PAPERTYPE"
#define it_Auto6186   "PAPERTYPE"
#define es_Auto6186   "PAPERTYPE"
#define de_Auto6186   "PAPERTYPE"
#define nl_Auto6186   "PAPERTYPE"
#define pt_Auto6186   "PAPERTYPE"
#define xx_Auto6186   "PAPERTYPE"
#define en_Auto6188   "LAYOUT"
#define fr_Auto6188   "LAYOUT"
#define it_Auto6188   "LAYOUT"
#define es_Auto6188   "LAYOUT"
#define de_Auto6188   "LAYOUT"
#define nl_Auto6188   "LAYOUT"
#define pt_Auto6188   "LAYOUT"
#define xx_Auto6188   "LAYOUT"
#define en_Auto6190   "PAGEFEED"
#define fr_Auto6190   "PAGEFEED"
#define it_Auto6190   "PAGEFEED"
#define es_Auto6190   "PAGEFEED"
#define de_Auto6190   "PAGEFEED"
#define nl_Auto6190   "PAGEFEED"
#define pt_Auto6190   "PAGEFEED"
#define xx_Auto6190   "PAGEFEED"
#define en_LAYOUT   "Portrait|Landscape"
#define fr_LAYOUT   "Portrait|Landscape"
#define it_LAYOUT   "Portrait|Landscape"
#define es_LAYOUT   "Portrait|Landscape"
#define de_LAYOUT   "Portrait|Landscape"
#define nl_LAYOUT   "Portrait|Landscape"
#define pt_LAYOUT   "Portrait|Landscape"
#define xx_LAYOUT   "Portrait|Landscape"
#define en_PAGEFEED   "None|Before|After"
#define fr_PAGEFEED   "None|Before|After"
#define it_PAGEFEED   "None|Before|After"
#define es_PAGEFEED   "None|Before|After"
#define de_PAGEFEED   "None|Before|After"
#define nl_PAGEFEED   "None|Before|After"
#define pt_PAGEFEED   "None|Before|After"
#define xx_PAGEFEED   "None|Before|After"
#define en_Editor   "&Editor"
#define fr_Editor   "&Editeur"
#define en_Auto6204   "AED"
#define fr_Auto6204   "AED"
#define it_Auto6204   "AED"
#define es_Auto6204   "AED"
#define de_Auto6204   "AED"
#define nl_Auto6204   "AED"
#define pt_Auto6204   "AED"
#define xx_Auto6204   "AED"
#define en_Auto6206   "AED.FONT"
#define fr_Auto6206   "AED.FONT"
#define it_Auto6206   "AED.FONT"
#define es_Auto6206   "AED.FONT"
#define de_Auto6206   "AED.FONT"
#define nl_Auto6206   "AED.FONT"
#define pt_Auto6206   "AED.FONT"
#define xx_Auto6206   "AED.FONT"
#define en_Auto6208   "Editor Syntaxical Colours"
#define fr_Auto6208   "Couleurs Syntaxiques de l'Editeur"
#define it_Auto6208   "Editor Syntaxical Colours"
#define es_Auto6208   "Editor Syntaxical Colours"
#define de_Auto6208   "Editor Syntaxical Colours"
#define nl_Auto6208   "Editor Syntaxical Colours"
#define pt_Auto6208   "Editor Syntaxical Colours"
#define xx_Auto6208   "Editor Syntaxical Colours"
#define en_AED_STATE   "AED.STATE"
#define fr_AED_STATE   "AED.STATE"
#define it_AED_STATE   "AED.STATE"
#define es_AED_STATE   "AED.STATE"
#define de_AED_STATE   "AED.STATE"
#define nl_AED_STATE   "AED.STATE"
#define pt_AED_STATE   "AED.STATE"
#define xx_AED_STATE   "AED.STATE"
#define en_AED_SYNTAX   "AED.SYNTAX"
#define fr_AED_SYNTAX   "AED.SYNTAX"
#define it_AED_SYNTAX   "AED.SYNTAX"
#define es_AED_SYNTAX   "AED.SYNTAX"
#define de_AED_SYNTAX   "AED.SYNTAX"
#define nl_AED_SYNTAX   "AED.SYNTAX"
#define pt_AED_SYNTAX   "AED.SYNTAX"
#define xx_AED_SYNTAX   "AED.SYNTAX"
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
#define en_ACCEPT   "&Accept"
#define fr_ACCEPT   "&Valider"
#define en_SAVEFILE   "&SaveFile"
#define fr_SAVEFILE   "E&crireFichier"
#define it_SAVEFILE   "&SaveFile"
#define es_SAVEFILE   "&SaveFile"
#define de_SAVEFILE   "&SaveFile"
#define nl_SAVEFILE   "&SaveFile"
#define pt_SAVEFILE   "&SaveFile"
#define xx_SAVEFILE   "&SaveFile"
#define en_SAVELDAP   "Sa&veLdap"
#define fr_SAVELDAP   "Ec&rireLdap"
#define it_SAVELDAP   "Sa&veLdap"
#define es_SAVELDAP   "Sa&veLdap"
#define de_SAVELDAP   "Sa&veLdap"
#define nl_SAVELDAP   "Sa&veLdap"
#define pt_SAVELDAP   "Sa&veLdap"
#define xx_SAVELDAP   "Sa&veLdap"
#define en_LoadLdap   "L&oadLdap"
#define fr_LoadLdap   "C&hargeLdap"
#define it_LoadLdap   ""
#define es_LoadLdap   ""
#define de_LoadLdap   ""
#define nl_LoadLdap   ""
#define pt_LoadLdap   ""
#define xx_LoadLdap   ""
#define en_EDITFILE   "Edi&tFile"
#define fr_EDITFILE   "Edi&teur"
#define it_EDITFILE   ""
#define es_EDITFILE   ""
#define de_EDITFILE   ""
#define nl_EDITFILE   ""
#define pt_EDITFILE   ""
#define xx_EDITFILE   ""
#define en_DELETE   "&Delete"
#define fr_DELETE   "&Suprimer"
#define it_DELETE   ""
#define es_DELETE   ""
#define de_DELETE   ""
#define nl_DELETE   ""
#define pt_DELETE   ""
#define xx_DELETE   ""
#define en_LOADFILE   "&LoadFile"
#define fr_LOADFILE   "Ch&argeFichier"
#define it_LOADFILE   ""
#define es_LOADFILE   ""
#define de_LOADFILE   ""
#define nl_LOADFILE   ""
#define pt_LOADFILE   ""
#define xx_LOADFILE   ""
#define en_CANCEL   "&Cancel"
#define fr_CANCEL   "A&nnuler"
#define en_Project   "&Project"
#define fr_Project   "&Projet"
#define en_Auto6256   "AMAKE"
#define fr_Auto6256   "AMAKE"
#define it_Auto6256   "AMAKE"
#define es_Auto6256   "AMAKE"
#define de_Auto6256   "AMAKE"
#define nl_Auto6256   "AMAKE"
#define pt_Auto6256   "AMAKE"
#define xx_Auto6256   "AMAKE"
#define en_Auto5671   "AMAKE.OPTIONS"
#define fr_Auto5671   "AMAKE.OPTIONS"
#define it_Auto5671   "AMAKE.OPTIONS"
#define es_Auto5671   "AMAKE.OPTIONS"
#define de_Auto5671   "AMAKE.OPTIONS"
#define nl_Auto5671   "AMAKE.OPTIONS"
#define pt_Auto5671   "AMAKE.OPTIONS"
#define xx_Auto5671   "AMAKE.OPTIONS"
#define en_Auto5675   "AMAKE.DEFINE"
#define fr_Auto5675   "AMAKE.DEFINE"
#define it_Auto5675   "AMAKE.DEFINE"
#define es_Auto5675   "AMAKE.DEFINE"
#define de_Auto5675   "AMAKE.DEFINE"
#define nl_Auto5675   "AMAKE.DEFINE"
#define pt_Auto5675   "AMAKE.DEFINE"
#define xx_Auto5675   "AMAKE.DEFINE"
#define en_Auto5691   "AMAKE.LIST"
#define fr_Auto5691   "AMAKE.LIST"
#define it_Auto5691   "AMAKE.LIST"
#define es_Auto5691   "AMAKE.LIST"
#define de_Auto5691   "AMAKE.LIST"
#define nl_Auto5691   "AMAKE.LIST"
#define pt_Auto5691   "AMAKE.LIST"
#define xx_Auto5691   "AMAKE.LIST"
static int	vfh[10];

private struct accept_configuration_context {
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[8+1];
	char * msg_Auto5703[8];
	int	x_Auto5703;
	int	y_Auto5703;
	int	w_Auto5703;
	int	h_Auto5703;
	char * msg_Auto6246[8];
	char * msg_General[8];
	int	trigger_General;
	int	page_number;
	char * msg_Auto5988[8];
	char	buffer_FILENAME[65];
	char	buffer_ABALHOST[65];
	char * msg_Auto5994[8];
	char * msg_Auto5996[8];
	char * msg_Auto5998[8];
	char * msg_Auto6000[8];
	char * msg_Auto6002[8];
	char	buffer_IDENTITY[66];
	char	buffer_REPLAY[66];
	char	buffer_RECORD[66];
	char * msg_Abal[8];
	int	trigger_Abal;
	char * msg_Auto6012[8];
	char * msg_Auto6014[8];
	char * msg_Auto6016[8];
	char * msg_Auto6018[8];
	char * msg_Auto6020[8];
	char * msg_Auto6022[8];
	char * msg_Auto6024[8];
	char	buffer_ATR[67];
	char	buffer_ATR_DEFINE[67];
	char	buffer_ATR_INCLUDE[67];
	char	buffer_ATR_OPTIONS[67];
	char	buffer_ALD[67];
	char	buffer_ALD_OPTIONS[67];
	char * msg_Auto6038[8];
	char * msg_Auto6040[8];
	char * msg_Auto6042[8];
	char * msg_Auto6044[8];
	char * msg_Auto6046[8];
	char * msg_Auto6048[8];
	char * msg_Auto6050[8];
	char * msg_Auto6052[8];
	char * msg_Auto6054[8];
	char * msg_Auto6056[8];
	char	buffer_OTR[67];
	char	buffer_OTR_DEFINE[67];
	char	buffer_OTR_INCLUDE[67];
	char	buffer_OTR_OPTIONS[67];
	char	buffer_OLD[67];
	char	buffer_OLD_OPTIONS[67];
	char	buffer_EXA[67];
	char	buffer_EXADB[67];
	char * msg_Images[8];
	int	trigger_Images;
	char * msg_Auto6076[8];
	char	buffer_IMAGEPATH[69];
	char * msg_Auto6080[8];
	char * msg_Auto6082[8];
	char * msg_Auto6084[8];
	char * msg_Auto6086[8];
	char * msg_Auto6088[8];
	char	buffer_ICONPATH[69];
	char	buffer_PALETTE[69];
	char	buffer_SKIN[69];
	char * msg_TRIGGER_STYLE[8];
	int	value_TRIGGER_STYLE;
	char	buffer_TRIGGER_COLOUR[12];
	char * msg_Fonts[8];
	int	trigger_Fonts;
	char * msg_Auto6102[8];
	char * msg_Auto6104[8];
	char * msg_Auto6106[8];
	char * msg_Auto6108[8];
	char * msg_Auto6110[8];
	char * msg_Auto6112[8];
	char * msg_Auto6114[8];
	char * msg_Auto6116[8];
	char * msg_Auto6118[8];
	char * msg_Auto6120[8];
	char * msg_Auto6122[8];
	char * msg_Auto6124[8];
	char	buffer_FONTPATH[69];
	char	buffer_FONT1[67];
	char	buffer_FONT2[67];
	char	buffer_FONT3[67];
	char	buffer_FONT4[67];
	char	buffer_FONT5[67];
	char	buffer_FONT6[67];
	char	buffer_FONT7[67];
	char	buffer_FONT8[67];
	char	buffer_FONT9[67];
	char	buffer_FONT10[67];
	char * msg_Documents[8];
	int	trigger_Documents;
	char * msg_Auto6150[8];
	char * msg_Auto6152[8];
	char * msg_Auto6154[8];
	char * msg_Auto6156[8];
	char * msg_Auto6158[8];
	char * msg_Auto6160[8];
	char * msg_Auto6162[8];
	char * msg_Auto6164[8];
	char	buffer_HTML_TITLE[67];
	char	buffer_HTML_LOGO[67];
	char	buffer_HTML_COPYRIGHT[67];
	char	buffer_SCREEN_CSS[67];
	char	buffer_PRINT_CSS[67];
	char	buffer_NAVIGATOR[67];
	char	buffer_DOCPATH[67];
	char * msg_Printing[8];
	int	trigger_Printing;
	char * msg_Auto6182[8];
	char * msg_Auto6184[8];
	char * msg_Auto6186[8];
	char * msg_Auto6188[8];
	char * msg_Auto6190[8];
	char	buffer_PRINTER[69];
	char * msg_PAPERTYPE[8];
	int	value_PAPERTYPE;
	char * msg_LAYOUT[8];
	int	value_LAYOUT;
	char * msg_PAGEFEED[8];
	int	value_PAGEFEED;
	char * msg_RESOLUTION[8];
	int	value_RESOLUTION;
	char * msg_Editor[8];
	int	trigger_Editor;
	char * msg_Auto6204[8];
	char * msg_Auto6206[8];
	char * msg_Auto6208[8];
	char	buffer_AED[67];
	char * msg_AED_FONT[8];
	int	value_AED_FONT;
	char * msg_AED_STATE[8];
	int	trigger_AED_STATE;
	int	value_AED_STATE;
	char * msg_AED_SYNTAX[8];
	int	trigger_AED_SYNTAX;
	int	value_AED_SYNTAX;
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
	char * msg_ACCEPT[8];
	int	trigger_ACCEPT;
	char * msg_SAVEFILE[8];
	int	trigger_SAVEFILE;
	char * msg_SAVELDAP[8];
	int	trigger_SAVELDAP;
	char * msg_LoadLdap[8];
	int	trigger_LoadLdap;
	char * msg_EDITFILE[8];
	int	trigger_EDITFILE;
	char * msg_DELETE[8];
	int	trigger_DELETE;
	char * msg_LOADFILE[8];
	int	trigger_LOADFILE;
	char * msg_CANCEL[8];
	int	trigger_CANCEL;
	char * msg_Project[8];
	int	trigger_Project;
	char * msg_Auto6256[8];
	char * msg_Auto5671[8];
	char * msg_Auto5675[8];
	char * msg_Auto5691[8];
	char	buffer_AMAKE[67];
	char	buffer_AMAKE_OPTIONS[67];
	char	buffer_AMAKE_DEFINE[67];
	char	buffer_AMAKE_LIST[67];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[62];
	};

public	int	accept_configuration_create(
	struct accept_configuration_context ** cptr,
	char * pFILENAME,
	char * pABALHOST,
	char * pIDENTITY,
	char * pREPLAY,
	char * pRECORD,
	char * pATR,
	char * pATR_DEFINE,
	char * pATR_INCLUDE,
	char * pATR_OPTIONS,
	char * pALD,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pFONTPATH,
	char * pFONT1,
	char * pFONT2,
	char * pFONT3,
	char * pFONT4,
	char * pFONT5,
	char * pFONT6,
	char * pFONT7,
	char * pFONT8,
	char * pFONT9,
	char * pFONT10,
	char * pHTML_TITLE,
	char * pHTML_LOGO,
	char * pHTML_COPYRIGHT,
	char * pSCREEN_CSS,
	char * pPRINT_CSS,
	char * pNAVIGATOR,
	char * pDOCPATH,
	char * pPRINTER,
	char * pPAPERTYPE,
	char * pLAYOUT,
	char * pPAGEFEED,
	char * pRESOLUTION,
	char * pAED,
	char * pAED_FONT,
	char * pAED_STATE,
	char * pAED_SYNTAX,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST)
{

	int i;
	struct accept_configuration_context * _Context=(struct accept_configuration_context*)0;
	vfh[1] = visual_font("standard.fmf",12);
	vfh[2] = visual_font("arial2.fmf",10);
	vfh[3] = visual_font("arial3.fmf",10);
	vfh[4] = visual_font("arial4.fmf",10);
	vfh[5] = visual_font("arial5.fmf",10);
	vfh[6] = visual_font("ufjt6.fmf",9);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_configuration_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=78;
	_Context->page_number=1;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FILENAME, 64, pFILENAME);
		visual_transferin(_Context->buffer_ABALHOST, 64, pABALHOST);
		visual_transferin(_Context->buffer_IDENTITY, 65, pIDENTITY);
		visual_transferin(_Context->buffer_REPLAY, 65, pREPLAY);
		visual_transferin(_Context->buffer_RECORD, 65, pRECORD);
		visual_transferin(_Context->buffer_ATR, 66, pATR);
		visual_transferin(_Context->buffer_ATR_DEFINE, 66, pATR_DEFINE);
		visual_transferin(_Context->buffer_ATR_INCLUDE, 66, pATR_INCLUDE);
		visual_transferin(_Context->buffer_ATR_OPTIONS, 66, pATR_OPTIONS);
		visual_transferin(_Context->buffer_ALD, 66, pALD);
		visual_transferin(_Context->buffer_ALD_OPTIONS, 66, pALD_OPTIONS);
		visual_transferin(_Context->buffer_OTR, 66, pOTR);
		visual_transferin(_Context->buffer_OTR_DEFINE, 66, pOTR_DEFINE);
		visual_transferin(_Context->buffer_OTR_INCLUDE, 66, pOTR_INCLUDE);
		visual_transferin(_Context->buffer_OTR_OPTIONS, 66, pOTR_OPTIONS);
		visual_transferin(_Context->buffer_OLD, 66, pOLD);
		visual_transferin(_Context->buffer_OLD_OPTIONS, 66, pOLD_OPTIONS);
		visual_transferin(_Context->buffer_EXA, 66, pEXA);
		visual_transferin(_Context->buffer_EXADB, 66, pEXADB);
		visual_transferin(_Context->buffer_IMAGEPATH, 68, pIMAGEPATH);
		visual_transferin(_Context->buffer_ICONPATH, 68, pICONPATH);
		visual_transferin(_Context->buffer_PALETTE, 68, pPALETTE);
		visual_transferin(_Context->buffer_SKIN, 68, pSKIN);
		visual_transferin((void *) 0, 0, pTRIGGER_STYLE);
		if (!( pTRIGGER_STYLE )) _Context->value_TRIGGER_STYLE=0;
		else	_Context->value_TRIGGER_STYLE = *((int *)pTRIGGER_STYLE);
		visual_transferin(_Context->buffer_TRIGGER_COLOUR, 11, pTRIGGER_COLOUR);
		visual_transferin(_Context->buffer_FONTPATH, 68, pFONTPATH);
		visual_transferin(_Context->buffer_FONT1, 66, pFONT1);
		visual_transferin(_Context->buffer_FONT2, 66, pFONT2);
		visual_transferin(_Context->buffer_FONT3, 66, pFONT3);
		visual_transferin(_Context->buffer_FONT4, 66, pFONT4);
		visual_transferin(_Context->buffer_FONT5, 66, pFONT5);
		visual_transferin(_Context->buffer_FONT6, 66, pFONT6);
		visual_transferin(_Context->buffer_FONT7, 66, pFONT7);
		visual_transferin(_Context->buffer_FONT8, 66, pFONT8);
		visual_transferin(_Context->buffer_FONT9, 66, pFONT9);
		visual_transferin(_Context->buffer_FONT10, 66, pFONT10);
		visual_transferin(_Context->buffer_HTML_TITLE, 66, pHTML_TITLE);
		visual_transferin(_Context->buffer_HTML_LOGO, 66, pHTML_LOGO);
		visual_transferin(_Context->buffer_HTML_COPYRIGHT, 66, pHTML_COPYRIGHT);
		visual_transferin(_Context->buffer_SCREEN_CSS, 66, pSCREEN_CSS);
		visual_transferin(_Context->buffer_PRINT_CSS, 66, pPRINT_CSS);
		visual_transferin(_Context->buffer_NAVIGATOR, 66, pNAVIGATOR);
		visual_transferin(_Context->buffer_DOCPATH, 66, pDOCPATH);
		visual_transferin(_Context->buffer_PRINTER, 68, pPRINTER);
		visual_transferin((void *) 0, 0, pPAPERTYPE);
		if (!( pPAPERTYPE )) _Context->value_PAPERTYPE=0;
		else	_Context->value_PAPERTYPE = *((int *)pPAPERTYPE);
		visual_transferin((void *) 0, 0, pLAYOUT);
		if (!( pLAYOUT )) _Context->value_LAYOUT=0;
		else	_Context->value_LAYOUT = *((int *)pLAYOUT);
		visual_transferin((void *) 0, 0, pPAGEFEED);
		if (!( pPAGEFEED )) _Context->value_PAGEFEED=0;
		else	_Context->value_PAGEFEED = *((int *)pPAGEFEED);
		visual_transferin((void *) 0, 0, pRESOLUTION);
		if (!( pRESOLUTION )) _Context->value_RESOLUTION=0;
		else	_Context->value_RESOLUTION = *((int *)pRESOLUTION);
		visual_transferin(_Context->buffer_AED, 66, pAED);
		visual_transferin((void *) 0, 0, pAED_FONT);
		if (!( pAED_FONT )) _Context->value_AED_FONT=0;
		else	_Context->value_AED_FONT = *((int *)pAED_FONT);
		visual_transferin((void *) 0, 0, pAED_STATE);
		if (!( pAED_STATE )) _Context->value_AED_STATE=0;
		else	_Context->value_AED_STATE = *((int *)pAED_STATE);
		visual_transferin((void *) 0, 0, pAED_SYNTAX);
		if (!( pAED_SYNTAX )) _Context->value_AED_SYNTAX=0;
		else	_Context->value_AED_SYNTAX = *((int *)pAED_SYNTAX);
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
		visual_transferin(_Context->buffer_AMAKE, 66, pAMAKE);
		visual_transferin(_Context->buffer_AMAKE_OPTIONS, 66, pAMAKE_OPTIONS);
		visual_transferin(_Context->buffer_AMAKE_DEFINE, 66, pAMAKE_DEFINE);
		visual_transferin(_Context->buffer_AMAKE_LIST, 66, pAMAKE_LIST);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto5703[i]=" ";
	_Context->msg_Auto5703[0]=en_Auto5703;
	_Context->msg_Auto5703[1]=fr_Auto5703;
	_Context->x_Auto5703=0;
	_Context->y_Auto5703=0;
	_Context->w_Auto5703=790;
	_Context->h_Auto5703=600;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_Auto6246[i]=" ";
	_Context->msg_Auto6246[0]=en_Auto6246;
	_Context->msg_Auto6246[1]=fr_Auto6246;
	for (i=0; i < 8; i++)_Context->msg_General[i]=" ";
	_Context->msg_General[0]=en_General;
	_Context->msg_General[1]=fr_General;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto5988[i]=" ";
	_Context->msg_Auto5988[0]=en_Auto5988;
	for (i=0; i < 8; i++)_Context->msg_Auto5994[i]=" ";
	_Context->msg_Auto5994[0]=en_Auto5994;
	_Context->msg_Auto5994[1]=fr_Auto5994;
	_Context->msg_Auto5994[2]=it_Auto5994;
	_Context->msg_Auto5994[3]=es_Auto5994;
	_Context->msg_Auto5994[4]=de_Auto5994;
	_Context->msg_Auto5994[5]=nl_Auto5994;
	_Context->msg_Auto5994[6]=pt_Auto5994;
	_Context->msg_Auto5994[7]=xx_Auto5994;
	for (i=0; i < 8; i++)_Context->msg_Auto5996[i]=" ";
	_Context->msg_Auto5996[0]=en_Auto5996;
	_Context->msg_Auto5996[1]=fr_Auto5996;
	_Context->msg_Auto5996[2]=it_Auto5996;
	_Context->msg_Auto5996[3]=es_Auto5996;
	_Context->msg_Auto5996[4]=de_Auto5996;
	_Context->msg_Auto5996[5]=nl_Auto5996;
	_Context->msg_Auto5996[6]=pt_Auto5996;
	_Context->msg_Auto5996[7]=xx_Auto5996;
	for (i=0; i < 8; i++)_Context->msg_Auto5998[i]=" ";
	_Context->msg_Auto5998[0]=en_Auto5998;
	_Context->msg_Auto5998[1]=fr_Auto5998;
	_Context->msg_Auto5998[7]=xx_Auto5998;
	for (i=0; i < 8; i++)_Context->msg_Auto6000[i]=" ";
	_Context->msg_Auto6000[0]=en_Auto6000;
	_Context->msg_Auto6000[1]=fr_Auto6000;
	_Context->msg_Auto6000[2]=it_Auto6000;
	_Context->msg_Auto6000[3]=es_Auto6000;
	_Context->msg_Auto6000[4]=de_Auto6000;
	_Context->msg_Auto6000[5]=nl_Auto6000;
	_Context->msg_Auto6000[6]=pt_Auto6000;
	_Context->msg_Auto6000[7]=xx_Auto6000;
	for (i=0; i < 8; i++)_Context->msg_Auto6002[i]=" ";
	_Context->msg_Auto6002[0]=en_Auto6002;
	_Context->msg_Auto6002[1]=fr_Auto6002;
	_Context->msg_Auto6002[2]=it_Auto6002;
	_Context->msg_Auto6002[3]=es_Auto6002;
	_Context->msg_Auto6002[4]=de_Auto6002;
	_Context->msg_Auto6002[5]=nl_Auto6002;
	_Context->msg_Auto6002[6]=pt_Auto6002;
	_Context->msg_Auto6002[7]=xx_Auto6002;
	for (i=0; i < 8; i++)_Context->msg_Abal[i]=" ";
	_Context->msg_Abal[0]=en_Abal;
	_Context->msg_Abal[1]=fr_Abal;
	_Context->msg_Abal[2]=it_Abal;
	_Context->msg_Abal[3]=es_Abal;
	_Context->msg_Abal[4]=de_Abal;
	_Context->msg_Abal[5]=nl_Abal;
	_Context->msg_Abal[6]=pt_Abal;
	_Context->msg_Abal[7]=xx_Abal;
	_Context->focus_pages[2]=8;
	for (i=0; i < 8; i++)_Context->msg_Auto6012[i]=" ";
	_Context->msg_Auto6012[0]=en_Auto6012;
	_Context->msg_Auto6012[1]=fr_Auto6012;
	_Context->msg_Auto6012[2]=it_Auto6012;
	_Context->msg_Auto6012[3]=es_Auto6012;
	_Context->msg_Auto6012[4]=de_Auto6012;
	_Context->msg_Auto6012[5]=nl_Auto6012;
	_Context->msg_Auto6012[6]=pt_Auto6012;
	_Context->msg_Auto6012[7]=xx_Auto6012;
	for (i=0; i < 8; i++)_Context->msg_Auto6014[i]=" ";
	_Context->msg_Auto6014[0]=en_Auto6014;
	_Context->msg_Auto6014[1]=fr_Auto6014;
	_Context->msg_Auto6014[2]=it_Auto6014;
	_Context->msg_Auto6014[3]=es_Auto6014;
	_Context->msg_Auto6014[4]=de_Auto6014;
	_Context->msg_Auto6014[5]=nl_Auto6014;
	_Context->msg_Auto6014[6]=pt_Auto6014;
	_Context->msg_Auto6014[7]=xx_Auto6014;
	for (i=0; i < 8; i++)_Context->msg_Auto6016[i]=" ";
	_Context->msg_Auto6016[0]=en_Auto6016;
	_Context->msg_Auto6016[1]=fr_Auto6016;
	_Context->msg_Auto6016[2]=it_Auto6016;
	_Context->msg_Auto6016[3]=es_Auto6016;
	_Context->msg_Auto6016[4]=de_Auto6016;
	_Context->msg_Auto6016[5]=nl_Auto6016;
	_Context->msg_Auto6016[6]=pt_Auto6016;
	_Context->msg_Auto6016[7]=xx_Auto6016;
	for (i=0; i < 8; i++)_Context->msg_Auto6018[i]=" ";
	_Context->msg_Auto6018[0]=en_Auto6018;
	_Context->msg_Auto6018[1]=fr_Auto6018;
	_Context->msg_Auto6018[2]=it_Auto6018;
	_Context->msg_Auto6018[3]=es_Auto6018;
	_Context->msg_Auto6018[4]=de_Auto6018;
	_Context->msg_Auto6018[5]=nl_Auto6018;
	_Context->msg_Auto6018[6]=pt_Auto6018;
	_Context->msg_Auto6018[7]=xx_Auto6018;
	for (i=0; i < 8; i++)_Context->msg_Auto6020[i]=" ";
	_Context->msg_Auto6020[0]=en_Auto6020;
	_Context->msg_Auto6020[1]=fr_Auto6020;
	_Context->msg_Auto6020[2]=it_Auto6020;
	_Context->msg_Auto6020[3]=es_Auto6020;
	_Context->msg_Auto6020[4]=de_Auto6020;
	_Context->msg_Auto6020[5]=nl_Auto6020;
	_Context->msg_Auto6020[6]=pt_Auto6020;
	_Context->msg_Auto6020[7]=xx_Auto6020;
	for (i=0; i < 8; i++)_Context->msg_Auto6022[i]=" ";
	_Context->msg_Auto6022[0]=en_Auto6022;
	_Context->msg_Auto6022[1]=fr_Auto6022;
	_Context->msg_Auto6022[2]=it_Auto6022;
	_Context->msg_Auto6022[3]=es_Auto6022;
	_Context->msg_Auto6022[4]=de_Auto6022;
	_Context->msg_Auto6022[5]=nl_Auto6022;
	_Context->msg_Auto6022[6]=pt_Auto6022;
	_Context->msg_Auto6022[7]=xx_Auto6022;
	for (i=0; i < 8; i++)_Context->msg_Auto6024[i]=" ";
	_Context->msg_Auto6024[0]=en_Auto6024;
	_Context->msg_Auto6024[1]=fr_Auto6024;
	_Context->msg_Auto6024[2]=it_Auto6024;
	_Context->msg_Auto6024[3]=es_Auto6024;
	_Context->msg_Auto6024[4]=de_Auto6024;
	_Context->msg_Auto6024[5]=nl_Auto6024;
	_Context->msg_Auto6024[6]=pt_Auto6024;
	_Context->msg_Auto6024[7]=xx_Auto6024;
	for (i=0; i < 8; i++)_Context->msg_Auto6038[i]=" ";
	_Context->msg_Auto6038[0]=en_Auto6038;
	_Context->msg_Auto6038[1]=fr_Auto6038;
	_Context->msg_Auto6038[2]=it_Auto6038;
	_Context->msg_Auto6038[3]=es_Auto6038;
	_Context->msg_Auto6038[4]=de_Auto6038;
	_Context->msg_Auto6038[5]=nl_Auto6038;
	_Context->msg_Auto6038[6]=pt_Auto6038;
	_Context->msg_Auto6038[7]=xx_Auto6038;
	for (i=0; i < 8; i++)_Context->msg_Auto6040[i]=" ";
	_Context->msg_Auto6040[0]=en_Auto6040;
	_Context->msg_Auto6040[1]=fr_Auto6040;
	_Context->msg_Auto6040[2]=it_Auto6040;
	_Context->msg_Auto6040[3]=es_Auto6040;
	_Context->msg_Auto6040[4]=de_Auto6040;
	_Context->msg_Auto6040[5]=nl_Auto6040;
	_Context->msg_Auto6040[6]=pt_Auto6040;
	_Context->msg_Auto6040[7]=xx_Auto6040;
	for (i=0; i < 8; i++)_Context->msg_Auto6042[i]=" ";
	_Context->msg_Auto6042[0]=en_Auto6042;
	_Context->msg_Auto6042[1]=fr_Auto6042;
	_Context->msg_Auto6042[2]=it_Auto6042;
	_Context->msg_Auto6042[3]=es_Auto6042;
	_Context->msg_Auto6042[4]=de_Auto6042;
	_Context->msg_Auto6042[5]=nl_Auto6042;
	_Context->msg_Auto6042[6]=pt_Auto6042;
	_Context->msg_Auto6042[7]=xx_Auto6042;
	for (i=0; i < 8; i++)_Context->msg_Auto6044[i]=" ";
	_Context->msg_Auto6044[0]=en_Auto6044;
	_Context->msg_Auto6044[1]=fr_Auto6044;
	_Context->msg_Auto6044[2]=it_Auto6044;
	_Context->msg_Auto6044[3]=es_Auto6044;
	_Context->msg_Auto6044[4]=de_Auto6044;
	_Context->msg_Auto6044[5]=nl_Auto6044;
	_Context->msg_Auto6044[6]=pt_Auto6044;
	_Context->msg_Auto6044[7]=xx_Auto6044;
	for (i=0; i < 8; i++)_Context->msg_Auto6046[i]=" ";
	_Context->msg_Auto6046[0]=en_Auto6046;
	_Context->msg_Auto6046[1]=fr_Auto6046;
	_Context->msg_Auto6046[2]=it_Auto6046;
	_Context->msg_Auto6046[3]=es_Auto6046;
	_Context->msg_Auto6046[4]=de_Auto6046;
	_Context->msg_Auto6046[5]=nl_Auto6046;
	_Context->msg_Auto6046[6]=pt_Auto6046;
	_Context->msg_Auto6046[7]=xx_Auto6046;
	for (i=0; i < 8; i++)_Context->msg_Auto6048[i]=" ";
	_Context->msg_Auto6048[0]=en_Auto6048;
	_Context->msg_Auto6048[1]=fr_Auto6048;
	_Context->msg_Auto6048[2]=it_Auto6048;
	_Context->msg_Auto6048[3]=es_Auto6048;
	_Context->msg_Auto6048[4]=de_Auto6048;
	_Context->msg_Auto6048[5]=nl_Auto6048;
	_Context->msg_Auto6048[6]=pt_Auto6048;
	_Context->msg_Auto6048[7]=xx_Auto6048;
	for (i=0; i < 8; i++)_Context->msg_Auto6050[i]=" ";
	_Context->msg_Auto6050[0]=en_Auto6050;
	_Context->msg_Auto6050[1]=fr_Auto6050;
	_Context->msg_Auto6050[2]=it_Auto6050;
	_Context->msg_Auto6050[3]=es_Auto6050;
	_Context->msg_Auto6050[4]=de_Auto6050;
	_Context->msg_Auto6050[5]=nl_Auto6050;
	_Context->msg_Auto6050[6]=pt_Auto6050;
	_Context->msg_Auto6050[7]=xx_Auto6050;
	for (i=0; i < 8; i++)_Context->msg_Auto6052[i]=" ";
	_Context->msg_Auto6052[0]=en_Auto6052;
	_Context->msg_Auto6052[1]=fr_Auto6052;
	_Context->msg_Auto6052[2]=it_Auto6052;
	_Context->msg_Auto6052[3]=es_Auto6052;
	_Context->msg_Auto6052[4]=de_Auto6052;
	_Context->msg_Auto6052[5]=nl_Auto6052;
	_Context->msg_Auto6052[6]=pt_Auto6052;
	_Context->msg_Auto6052[7]=xx_Auto6052;
	for (i=0; i < 8; i++)_Context->msg_Auto6054[i]=" ";
	_Context->msg_Auto6054[0]=en_Auto6054;
	_Context->msg_Auto6054[1]=fr_Auto6054;
	_Context->msg_Auto6054[2]=it_Auto6054;
	_Context->msg_Auto6054[3]=es_Auto6054;
	_Context->msg_Auto6054[4]=de_Auto6054;
	_Context->msg_Auto6054[5]=nl_Auto6054;
	_Context->msg_Auto6054[6]=pt_Auto6054;
	_Context->msg_Auto6054[7]=xx_Auto6054;
	for (i=0; i < 8; i++)_Context->msg_Auto6056[i]=" ";
	_Context->msg_Auto6056[0]=en_Auto6056;
	_Context->msg_Auto6056[1]=fr_Auto6056;
	_Context->msg_Auto6056[2]=it_Auto6056;
	_Context->msg_Auto6056[3]=es_Auto6056;
	_Context->msg_Auto6056[4]=de_Auto6056;
	_Context->msg_Auto6056[5]=nl_Auto6056;
	_Context->msg_Auto6056[6]=pt_Auto6056;
	_Context->msg_Auto6056[7]=xx_Auto6056;
	for (i=0; i < 8; i++)_Context->msg_Images[i]=" ";
	_Context->msg_Images[0]=en_Images;
	_Context->msg_Images[1]=fr_Images;
	_Context->msg_Images[2]=it_Images;
	_Context->msg_Images[3]=es_Images;
	_Context->msg_Images[4]=de_Images;
	_Context->msg_Images[5]=nl_Images;
	_Context->msg_Images[6]=pt_Images;
	_Context->msg_Images[7]=xx_Images;
	_Context->focus_pages[3]=23;
	for (i=0; i < 8; i++)_Context->msg_Auto6076[i]=" ";
	_Context->msg_Auto6076[0]=en_Auto6076;
	_Context->msg_Auto6076[1]=fr_Auto6076;
	_Context->msg_Auto6076[2]=it_Auto6076;
	_Context->msg_Auto6076[3]=es_Auto6076;
	_Context->msg_Auto6076[4]=de_Auto6076;
	_Context->msg_Auto6076[5]=nl_Auto6076;
	_Context->msg_Auto6076[6]=pt_Auto6076;
	_Context->msg_Auto6076[7]=xx_Auto6076;
	for (i=0; i < 8; i++)_Context->msg_Auto6080[i]=" ";
	_Context->msg_Auto6080[0]=en_Auto6080;
	_Context->msg_Auto6080[1]=fr_Auto6080;
	_Context->msg_Auto6080[2]=it_Auto6080;
	_Context->msg_Auto6080[3]=es_Auto6080;
	_Context->msg_Auto6080[4]=de_Auto6080;
	_Context->msg_Auto6080[5]=nl_Auto6080;
	_Context->msg_Auto6080[6]=pt_Auto6080;
	_Context->msg_Auto6080[7]=xx_Auto6080;
	for (i=0; i < 8; i++)_Context->msg_Auto6082[i]=" ";
	_Context->msg_Auto6082[0]=en_Auto6082;
	_Context->msg_Auto6082[1]=fr_Auto6082;
	_Context->msg_Auto6082[2]=it_Auto6082;
	_Context->msg_Auto6082[3]=es_Auto6082;
	_Context->msg_Auto6082[4]=de_Auto6082;
	_Context->msg_Auto6082[5]=nl_Auto6082;
	_Context->msg_Auto6082[6]=pt_Auto6082;
	_Context->msg_Auto6082[7]=xx_Auto6082;
	for (i=0; i < 8; i++)_Context->msg_Auto6084[i]=" ";
	_Context->msg_Auto6084[0]=en_Auto6084;
	_Context->msg_Auto6084[1]=fr_Auto6084;
	_Context->msg_Auto6084[2]=it_Auto6084;
	_Context->msg_Auto6084[3]=es_Auto6084;
	_Context->msg_Auto6084[4]=de_Auto6084;
	_Context->msg_Auto6084[5]=nl_Auto6084;
	_Context->msg_Auto6084[6]=pt_Auto6084;
	_Context->msg_Auto6084[7]=xx_Auto6084;
	for (i=0; i < 8; i++)_Context->msg_Auto6086[i]=" ";
	_Context->msg_Auto6086[0]=en_Auto6086;
	_Context->msg_Auto6086[1]=fr_Auto6086;
	_Context->msg_Auto6086[2]=it_Auto6086;
	_Context->msg_Auto6086[3]=es_Auto6086;
	_Context->msg_Auto6086[4]=de_Auto6086;
	_Context->msg_Auto6086[5]=nl_Auto6086;
	_Context->msg_Auto6086[6]=pt_Auto6086;
	_Context->msg_Auto6086[7]=xx_Auto6086;
	for (i=0; i < 8; i++)_Context->msg_Auto6088[i]=" ";
	_Context->msg_Auto6088[0]=en_Auto6088;
	_Context->msg_Auto6088[1]=fr_Auto6088;
	_Context->msg_Auto6088[2]=it_Auto6088;
	_Context->msg_Auto6088[3]=es_Auto6088;
	_Context->msg_Auto6088[4]=de_Auto6088;
	_Context->msg_Auto6088[5]=nl_Auto6088;
	_Context->msg_Auto6088[6]=pt_Auto6088;
	_Context->msg_Auto6088[7]=xx_Auto6088;
	for (i=0; i < 8; i++)_Context->msg_TRIGGER_STYLE[i]=" ";
	_Context->msg_TRIGGER_STYLE[0]=en_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[1]=fr_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[2]=it_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[3]=es_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[4]=de_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[5]=nl_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[6]=pt_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[7]=xx_TRIGGER_STYLE;
	for (i=0; i < 8; i++)_Context->msg_Fonts[i]=" ";
	_Context->msg_Fonts[0]=en_Fonts;
	_Context->msg_Fonts[1]=fr_Fonts;
	_Context->msg_Fonts[2]=it_Fonts;
	_Context->msg_Fonts[3]=es_Fonts;
	_Context->msg_Fonts[4]=de_Fonts;
	_Context->msg_Fonts[5]=nl_Fonts;
	_Context->msg_Fonts[6]=pt_Fonts;
	_Context->msg_Fonts[7]=xx_Fonts;
	_Context->focus_pages[4]=30;
	for (i=0; i < 8; i++)_Context->msg_Auto6102[i]=" ";
	_Context->msg_Auto6102[0]=en_Auto6102;
	_Context->msg_Auto6102[1]=fr_Auto6102;
	_Context->msg_Auto6102[2]=it_Auto6102;
	_Context->msg_Auto6102[3]=es_Auto6102;
	_Context->msg_Auto6102[4]=de_Auto6102;
	_Context->msg_Auto6102[5]=nl_Auto6102;
	_Context->msg_Auto6102[6]=pt_Auto6102;
	_Context->msg_Auto6102[7]=xx_Auto6102;
	for (i=0; i < 8; i++)_Context->msg_Auto6104[i]=" ";
	_Context->msg_Auto6104[0]=en_Auto6104;
	_Context->msg_Auto6104[1]=fr_Auto6104;
	_Context->msg_Auto6104[2]=it_Auto6104;
	_Context->msg_Auto6104[3]=es_Auto6104;
	_Context->msg_Auto6104[4]=de_Auto6104;
	_Context->msg_Auto6104[5]=nl_Auto6104;
	_Context->msg_Auto6104[6]=pt_Auto6104;
	_Context->msg_Auto6104[7]=xx_Auto6104;
	for (i=0; i < 8; i++)_Context->msg_Auto6106[i]=" ";
	_Context->msg_Auto6106[0]=en_Auto6106;
	_Context->msg_Auto6106[1]=fr_Auto6106;
	_Context->msg_Auto6106[2]=it_Auto6106;
	_Context->msg_Auto6106[3]=es_Auto6106;
	_Context->msg_Auto6106[4]=de_Auto6106;
	_Context->msg_Auto6106[5]=nl_Auto6106;
	_Context->msg_Auto6106[6]=pt_Auto6106;
	_Context->msg_Auto6106[7]=xx_Auto6106;
	for (i=0; i < 8; i++)_Context->msg_Auto6108[i]=" ";
	_Context->msg_Auto6108[0]=en_Auto6108;
	_Context->msg_Auto6108[1]=fr_Auto6108;
	_Context->msg_Auto6108[2]=it_Auto6108;
	_Context->msg_Auto6108[3]=es_Auto6108;
	_Context->msg_Auto6108[4]=de_Auto6108;
	_Context->msg_Auto6108[5]=nl_Auto6108;
	_Context->msg_Auto6108[6]=pt_Auto6108;
	_Context->msg_Auto6108[7]=xx_Auto6108;
	for (i=0; i < 8; i++)_Context->msg_Auto6110[i]=" ";
	_Context->msg_Auto6110[0]=en_Auto6110;
	_Context->msg_Auto6110[1]=fr_Auto6110;
	_Context->msg_Auto6110[2]=it_Auto6110;
	_Context->msg_Auto6110[3]=es_Auto6110;
	_Context->msg_Auto6110[4]=de_Auto6110;
	_Context->msg_Auto6110[5]=nl_Auto6110;
	_Context->msg_Auto6110[6]=pt_Auto6110;
	_Context->msg_Auto6110[7]=xx_Auto6110;
	for (i=0; i < 8; i++)_Context->msg_Auto6112[i]=" ";
	_Context->msg_Auto6112[0]=en_Auto6112;
	_Context->msg_Auto6112[1]=fr_Auto6112;
	_Context->msg_Auto6112[2]=it_Auto6112;
	_Context->msg_Auto6112[3]=es_Auto6112;
	_Context->msg_Auto6112[4]=de_Auto6112;
	_Context->msg_Auto6112[5]=nl_Auto6112;
	_Context->msg_Auto6112[6]=pt_Auto6112;
	_Context->msg_Auto6112[7]=xx_Auto6112;
	for (i=0; i < 8; i++)_Context->msg_Auto6114[i]=" ";
	_Context->msg_Auto6114[0]=en_Auto6114;
	_Context->msg_Auto6114[1]=fr_Auto6114;
	_Context->msg_Auto6114[2]=it_Auto6114;
	_Context->msg_Auto6114[3]=es_Auto6114;
	_Context->msg_Auto6114[4]=de_Auto6114;
	_Context->msg_Auto6114[5]=nl_Auto6114;
	_Context->msg_Auto6114[6]=pt_Auto6114;
	_Context->msg_Auto6114[7]=xx_Auto6114;
	for (i=0; i < 8; i++)_Context->msg_Auto6116[i]=" ";
	_Context->msg_Auto6116[0]=en_Auto6116;
	_Context->msg_Auto6116[1]=fr_Auto6116;
	_Context->msg_Auto6116[2]=it_Auto6116;
	_Context->msg_Auto6116[3]=es_Auto6116;
	_Context->msg_Auto6116[4]=de_Auto6116;
	_Context->msg_Auto6116[5]=nl_Auto6116;
	_Context->msg_Auto6116[6]=pt_Auto6116;
	_Context->msg_Auto6116[7]=xx_Auto6116;
	for (i=0; i < 8; i++)_Context->msg_Auto6118[i]=" ";
	_Context->msg_Auto6118[0]=en_Auto6118;
	_Context->msg_Auto6118[1]=fr_Auto6118;
	_Context->msg_Auto6118[2]=it_Auto6118;
	_Context->msg_Auto6118[3]=es_Auto6118;
	_Context->msg_Auto6118[4]=de_Auto6118;
	_Context->msg_Auto6118[5]=nl_Auto6118;
	_Context->msg_Auto6118[6]=pt_Auto6118;
	_Context->msg_Auto6118[7]=xx_Auto6118;
	for (i=0; i < 8; i++)_Context->msg_Auto6120[i]=" ";
	_Context->msg_Auto6120[0]=en_Auto6120;
	_Context->msg_Auto6120[1]=fr_Auto6120;
	_Context->msg_Auto6120[2]=it_Auto6120;
	_Context->msg_Auto6120[3]=es_Auto6120;
	_Context->msg_Auto6120[4]=de_Auto6120;
	_Context->msg_Auto6120[5]=nl_Auto6120;
	_Context->msg_Auto6120[6]=pt_Auto6120;
	_Context->msg_Auto6120[7]=xx_Auto6120;
	for (i=0; i < 8; i++)_Context->msg_Auto6122[i]=" ";
	_Context->msg_Auto6122[0]=en_Auto6122;
	_Context->msg_Auto6122[1]=fr_Auto6122;
	_Context->msg_Auto6122[2]=it_Auto6122;
	_Context->msg_Auto6122[3]=es_Auto6122;
	_Context->msg_Auto6122[4]=de_Auto6122;
	_Context->msg_Auto6122[5]=nl_Auto6122;
	_Context->msg_Auto6122[6]=pt_Auto6122;
	_Context->msg_Auto6122[7]=xx_Auto6122;
	for (i=0; i < 8; i++)_Context->msg_Auto6124[i]=" ";
	_Context->msg_Auto6124[0]=en_Auto6124;
	_Context->msg_Auto6124[1]=fr_Auto6124;
	_Context->msg_Auto6124[2]=it_Auto6124;
	_Context->msg_Auto6124[3]=es_Auto6124;
	_Context->msg_Auto6124[4]=de_Auto6124;
	_Context->msg_Auto6124[5]=nl_Auto6124;
	_Context->msg_Auto6124[6]=pt_Auto6124;
	_Context->msg_Auto6124[7]=xx_Auto6124;
	for (i=0; i < 8; i++)_Context->msg_Documents[i]=" ";
	_Context->msg_Documents[0]=en_Documents;
	_Context->msg_Documents[1]=fr_Documents;
	_Context->msg_Documents[2]=it_Documents;
	_Context->msg_Documents[3]=es_Documents;
	_Context->msg_Documents[4]=de_Documents;
	_Context->msg_Documents[5]=nl_Documents;
	_Context->msg_Documents[6]=pt_Documents;
	_Context->msg_Documents[7]=xx_Documents;
	_Context->focus_pages[5]=42;
	for (i=0; i < 8; i++)_Context->msg_Auto6150[i]=" ";
	_Context->msg_Auto6150[0]=en_Auto6150;
	_Context->msg_Auto6150[1]=fr_Auto6150;
	_Context->msg_Auto6150[2]=it_Auto6150;
	_Context->msg_Auto6150[3]=es_Auto6150;
	_Context->msg_Auto6150[4]=de_Auto6150;
	_Context->msg_Auto6150[5]=nl_Auto6150;
	_Context->msg_Auto6150[6]=pt_Auto6150;
	_Context->msg_Auto6150[7]=xx_Auto6150;
	for (i=0; i < 8; i++)_Context->msg_Auto6152[i]=" ";
	_Context->msg_Auto6152[0]=en_Auto6152;
	_Context->msg_Auto6152[1]=fr_Auto6152;
	_Context->msg_Auto6152[2]=it_Auto6152;
	_Context->msg_Auto6152[3]=es_Auto6152;
	_Context->msg_Auto6152[4]=de_Auto6152;
	_Context->msg_Auto6152[5]=nl_Auto6152;
	_Context->msg_Auto6152[6]=pt_Auto6152;
	_Context->msg_Auto6152[7]=xx_Auto6152;
	for (i=0; i < 8; i++)_Context->msg_Auto6154[i]=" ";
	_Context->msg_Auto6154[0]=en_Auto6154;
	_Context->msg_Auto6154[1]=fr_Auto6154;
	_Context->msg_Auto6154[2]=it_Auto6154;
	_Context->msg_Auto6154[3]=es_Auto6154;
	_Context->msg_Auto6154[4]=de_Auto6154;
	_Context->msg_Auto6154[5]=nl_Auto6154;
	_Context->msg_Auto6154[6]=pt_Auto6154;
	_Context->msg_Auto6154[7]=xx_Auto6154;
	for (i=0; i < 8; i++)_Context->msg_Auto6156[i]=" ";
	_Context->msg_Auto6156[0]=en_Auto6156;
	_Context->msg_Auto6156[1]=fr_Auto6156;
	_Context->msg_Auto6156[2]=it_Auto6156;
	_Context->msg_Auto6156[3]=es_Auto6156;
	_Context->msg_Auto6156[4]=de_Auto6156;
	_Context->msg_Auto6156[5]=nl_Auto6156;
	_Context->msg_Auto6156[6]=pt_Auto6156;
	_Context->msg_Auto6156[7]=xx_Auto6156;
	for (i=0; i < 8; i++)_Context->msg_Auto6158[i]=" ";
	_Context->msg_Auto6158[0]=en_Auto6158;
	_Context->msg_Auto6158[1]=fr_Auto6158;
	_Context->msg_Auto6158[2]=it_Auto6158;
	_Context->msg_Auto6158[3]=es_Auto6158;
	_Context->msg_Auto6158[4]=de_Auto6158;
	_Context->msg_Auto6158[5]=nl_Auto6158;
	_Context->msg_Auto6158[6]=pt_Auto6158;
	_Context->msg_Auto6158[7]=xx_Auto6158;
	for (i=0; i < 8; i++)_Context->msg_Auto6160[i]=" ";
	_Context->msg_Auto6160[0]=en_Auto6160;
	_Context->msg_Auto6160[1]=fr_Auto6160;
	_Context->msg_Auto6160[2]=it_Auto6160;
	_Context->msg_Auto6160[3]=es_Auto6160;
	_Context->msg_Auto6160[4]=de_Auto6160;
	_Context->msg_Auto6160[5]=nl_Auto6160;
	_Context->msg_Auto6160[6]=pt_Auto6160;
	_Context->msg_Auto6160[7]=xx_Auto6160;
	for (i=0; i < 8; i++)_Context->msg_Auto6162[i]=" ";
	_Context->msg_Auto6162[0]=en_Auto6162;
	_Context->msg_Auto6162[1]=fr_Auto6162;
	_Context->msg_Auto6162[2]=it_Auto6162;
	_Context->msg_Auto6162[3]=es_Auto6162;
	_Context->msg_Auto6162[4]=de_Auto6162;
	_Context->msg_Auto6162[5]=nl_Auto6162;
	_Context->msg_Auto6162[6]=pt_Auto6162;
	_Context->msg_Auto6162[7]=xx_Auto6162;
	for (i=0; i < 8; i++)_Context->msg_Auto6164[i]=" ";
	_Context->msg_Auto6164[0]=en_Auto6164;
	_Context->msg_Auto6164[1]=fr_Auto6164;
	_Context->msg_Auto6164[2]=it_Auto6164;
	_Context->msg_Auto6164[3]=es_Auto6164;
	_Context->msg_Auto6164[4]=de_Auto6164;
	_Context->msg_Auto6164[5]=nl_Auto6164;
	_Context->msg_Auto6164[6]=pt_Auto6164;
	_Context->msg_Auto6164[7]=xx_Auto6164;
	for (i=0; i < 8; i++)_Context->msg_Printing[i]=" ";
	_Context->msg_Printing[0]=en_Printing;
	_Context->msg_Printing[1]=fr_Printing;
	_Context->msg_Printing[2]=it_Printing;
	_Context->msg_Printing[3]=es_Printing;
	_Context->msg_Printing[4]=de_Printing;
	_Context->msg_Printing[5]=nl_Printing;
	_Context->msg_Printing[6]=pt_Printing;
	_Context->msg_Printing[7]=xx_Printing;
	_Context->focus_pages[6]=50;
	for (i=0; i < 8; i++)_Context->msg_Auto6182[i]=" ";
	_Context->msg_Auto6182[0]=en_Auto6182;
	_Context->msg_Auto6182[1]=fr_Auto6182;
	_Context->msg_Auto6182[2]=it_Auto6182;
	_Context->msg_Auto6182[3]=es_Auto6182;
	_Context->msg_Auto6182[4]=de_Auto6182;
	_Context->msg_Auto6182[5]=nl_Auto6182;
	_Context->msg_Auto6182[6]=pt_Auto6182;
	_Context->msg_Auto6182[7]=xx_Auto6182;
	for (i=0; i < 8; i++)_Context->msg_Auto6184[i]=" ";
	_Context->msg_Auto6184[0]=en_Auto6184;
	_Context->msg_Auto6184[1]=fr_Auto6184;
	_Context->msg_Auto6184[2]=it_Auto6184;
	_Context->msg_Auto6184[3]=es_Auto6184;
	_Context->msg_Auto6184[4]=de_Auto6184;
	_Context->msg_Auto6184[5]=nl_Auto6184;
	_Context->msg_Auto6184[6]=pt_Auto6184;
	_Context->msg_Auto6184[7]=xx_Auto6184;
	for (i=0; i < 8; i++)_Context->msg_Auto6186[i]=" ";
	_Context->msg_Auto6186[0]=en_Auto6186;
	_Context->msg_Auto6186[1]=fr_Auto6186;
	_Context->msg_Auto6186[2]=it_Auto6186;
	_Context->msg_Auto6186[3]=es_Auto6186;
	_Context->msg_Auto6186[4]=de_Auto6186;
	_Context->msg_Auto6186[5]=nl_Auto6186;
	_Context->msg_Auto6186[6]=pt_Auto6186;
	_Context->msg_Auto6186[7]=xx_Auto6186;
	for (i=0; i < 8; i++)_Context->msg_Auto6188[i]=" ";
	_Context->msg_Auto6188[0]=en_Auto6188;
	_Context->msg_Auto6188[1]=fr_Auto6188;
	_Context->msg_Auto6188[2]=it_Auto6188;
	_Context->msg_Auto6188[3]=es_Auto6188;
	_Context->msg_Auto6188[4]=de_Auto6188;
	_Context->msg_Auto6188[5]=nl_Auto6188;
	_Context->msg_Auto6188[6]=pt_Auto6188;
	_Context->msg_Auto6188[7]=xx_Auto6188;
	for (i=0; i < 8; i++)_Context->msg_Auto6190[i]=" ";
	_Context->msg_Auto6190[0]=en_Auto6190;
	_Context->msg_Auto6190[1]=fr_Auto6190;
	_Context->msg_Auto6190[2]=it_Auto6190;
	_Context->msg_Auto6190[3]=es_Auto6190;
	_Context->msg_Auto6190[4]=de_Auto6190;
	_Context->msg_Auto6190[5]=nl_Auto6190;
	_Context->msg_Auto6190[6]=pt_Auto6190;
	_Context->msg_Auto6190[7]=xx_Auto6190;
	for (i=0; i < 8; i++)_Context->msg_PAPERTYPE[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_LAYOUT[i]=" ";
	_Context->msg_LAYOUT[0]=en_LAYOUT;
	_Context->msg_LAYOUT[1]=fr_LAYOUT;
	_Context->msg_LAYOUT[2]=it_LAYOUT;
	_Context->msg_LAYOUT[3]=es_LAYOUT;
	_Context->msg_LAYOUT[4]=de_LAYOUT;
	_Context->msg_LAYOUT[5]=nl_LAYOUT;
	_Context->msg_LAYOUT[6]=pt_LAYOUT;
	_Context->msg_LAYOUT[7]=xx_LAYOUT;
	for (i=0; i < 8; i++)_Context->msg_PAGEFEED[i]=" ";
	_Context->msg_PAGEFEED[0]=en_PAGEFEED;
	_Context->msg_PAGEFEED[1]=fr_PAGEFEED;
	_Context->msg_PAGEFEED[2]=it_PAGEFEED;
	_Context->msg_PAGEFEED[3]=es_PAGEFEED;
	_Context->msg_PAGEFEED[4]=de_PAGEFEED;
	_Context->msg_PAGEFEED[5]=nl_PAGEFEED;
	_Context->msg_PAGEFEED[6]=pt_PAGEFEED;
	_Context->msg_PAGEFEED[7]=xx_PAGEFEED;
	for (i=0; i < 8; i++)_Context->msg_RESOLUTION[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_Editor[i]=" ";
	_Context->msg_Editor[0]=en_Editor;
	_Context->msg_Editor[1]=fr_Editor;
	_Context->focus_pages[7]=56;
	for (i=0; i < 8; i++)_Context->msg_Auto6204[i]=" ";
	_Context->msg_Auto6204[0]=en_Auto6204;
	_Context->msg_Auto6204[1]=fr_Auto6204;
	_Context->msg_Auto6204[2]=it_Auto6204;
	_Context->msg_Auto6204[3]=es_Auto6204;
	_Context->msg_Auto6204[4]=de_Auto6204;
	_Context->msg_Auto6204[5]=nl_Auto6204;
	_Context->msg_Auto6204[6]=pt_Auto6204;
	_Context->msg_Auto6204[7]=xx_Auto6204;
	for (i=0; i < 8; i++)_Context->msg_Auto6206[i]=" ";
	_Context->msg_Auto6206[0]=en_Auto6206;
	_Context->msg_Auto6206[1]=fr_Auto6206;
	_Context->msg_Auto6206[2]=it_Auto6206;
	_Context->msg_Auto6206[3]=es_Auto6206;
	_Context->msg_Auto6206[4]=de_Auto6206;
	_Context->msg_Auto6206[5]=nl_Auto6206;
	_Context->msg_Auto6206[6]=pt_Auto6206;
	_Context->msg_Auto6206[7]=xx_Auto6206;
	for (i=0; i < 8; i++)_Context->msg_Auto6208[i]=" ";
	_Context->msg_Auto6208[0]=en_Auto6208;
	_Context->msg_Auto6208[1]=fr_Auto6208;
	_Context->msg_Auto6208[2]=it_Auto6208;
	_Context->msg_Auto6208[3]=es_Auto6208;
	_Context->msg_Auto6208[4]=de_Auto6208;
	_Context->msg_Auto6208[5]=nl_Auto6208;
	_Context->msg_Auto6208[6]=pt_Auto6208;
	_Context->msg_Auto6208[7]=xx_Auto6208;
	for (i=0; i < 8; i++)_Context->msg_AED_FONT[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AED_STATE[i]=" ";
	_Context->msg_AED_STATE[0]=en_AED_STATE;
	_Context->msg_AED_STATE[1]=fr_AED_STATE;
	_Context->msg_AED_STATE[2]=it_AED_STATE;
	_Context->msg_AED_STATE[3]=es_AED_STATE;
	_Context->msg_AED_STATE[4]=de_AED_STATE;
	_Context->msg_AED_STATE[5]=nl_AED_STATE;
	_Context->msg_AED_STATE[6]=pt_AED_STATE;
	_Context->msg_AED_STATE[7]=xx_AED_STATE;
	for (i=0; i < 8; i++)_Context->msg_AED_SYNTAX[i]=" ";
	_Context->msg_AED_SYNTAX[0]=en_AED_SYNTAX;
	_Context->msg_AED_SYNTAX[1]=fr_AED_SYNTAX;
	_Context->msg_AED_SYNTAX[2]=it_AED_SYNTAX;
	_Context->msg_AED_SYNTAX[3]=es_AED_SYNTAX;
	_Context->msg_AED_SYNTAX[4]=de_AED_SYNTAX;
	_Context->msg_AED_SYNTAX[5]=nl_AED_SYNTAX;
	_Context->msg_AED_SYNTAX[6]=pt_AED_SYNTAX;
	_Context->msg_AED_SYNTAX[7]=xx_AED_SYNTAX;
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
	for (i=0; i < 8; i++)_Context->msg_AED_QUOTE[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AED_KEYWORD[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AED_COMMENT[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AED_PUNCTUATE[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_ACCEPT[i]=" ";
	_Context->msg_ACCEPT[0]=en_ACCEPT;
	_Context->msg_ACCEPT[1]=fr_ACCEPT;
	for (i=0; i < 8; i++)_Context->msg_SAVEFILE[i]=" ";
	_Context->msg_SAVEFILE[0]=en_SAVEFILE;
	_Context->msg_SAVEFILE[1]=fr_SAVEFILE;
	_Context->msg_SAVEFILE[2]=it_SAVEFILE;
	_Context->msg_SAVEFILE[3]=es_SAVEFILE;
	_Context->msg_SAVEFILE[4]=de_SAVEFILE;
	_Context->msg_SAVEFILE[5]=nl_SAVEFILE;
	_Context->msg_SAVEFILE[6]=pt_SAVEFILE;
	_Context->msg_SAVEFILE[7]=xx_SAVEFILE;
	for (i=0; i < 8; i++)_Context->msg_SAVELDAP[i]=" ";
	_Context->msg_SAVELDAP[0]=en_SAVELDAP;
	_Context->msg_SAVELDAP[1]=fr_SAVELDAP;
	_Context->msg_SAVELDAP[2]=it_SAVELDAP;
	_Context->msg_SAVELDAP[3]=es_SAVELDAP;
	_Context->msg_SAVELDAP[4]=de_SAVELDAP;
	_Context->msg_SAVELDAP[5]=nl_SAVELDAP;
	_Context->msg_SAVELDAP[6]=pt_SAVELDAP;
	_Context->msg_SAVELDAP[7]=xx_SAVELDAP;
	for (i=0; i < 8; i++)_Context->msg_LoadLdap[i]=" ";
	_Context->msg_LoadLdap[0]=en_LoadLdap;
	_Context->msg_LoadLdap[1]=fr_LoadLdap;
	_Context->msg_LoadLdap[2]=it_LoadLdap;
	_Context->msg_LoadLdap[3]=es_LoadLdap;
	_Context->msg_LoadLdap[4]=de_LoadLdap;
	_Context->msg_LoadLdap[5]=nl_LoadLdap;
	_Context->msg_LoadLdap[6]=pt_LoadLdap;
	_Context->msg_LoadLdap[7]=xx_LoadLdap;
	for (i=0; i < 8; i++)_Context->msg_EDITFILE[i]=" ";
	_Context->msg_EDITFILE[0]=en_EDITFILE;
	_Context->msg_EDITFILE[1]=fr_EDITFILE;
	_Context->msg_EDITFILE[2]=it_EDITFILE;
	_Context->msg_EDITFILE[3]=es_EDITFILE;
	_Context->msg_EDITFILE[4]=de_EDITFILE;
	_Context->msg_EDITFILE[5]=nl_EDITFILE;
	_Context->msg_EDITFILE[6]=pt_EDITFILE;
	_Context->msg_EDITFILE[7]=xx_EDITFILE;
	for (i=0; i < 8; i++)_Context->msg_DELETE[i]=" ";
	_Context->msg_DELETE[0]=en_DELETE;
	_Context->msg_DELETE[1]=fr_DELETE;
	_Context->msg_DELETE[2]=it_DELETE;
	_Context->msg_DELETE[3]=es_DELETE;
	_Context->msg_DELETE[4]=de_DELETE;
	_Context->msg_DELETE[5]=nl_DELETE;
	_Context->msg_DELETE[6]=pt_DELETE;
	_Context->msg_DELETE[7]=xx_DELETE;
	for (i=0; i < 8; i++)_Context->msg_LOADFILE[i]=" ";
	_Context->msg_LOADFILE[0]=en_LOADFILE;
	_Context->msg_LOADFILE[1]=fr_LOADFILE;
	_Context->msg_LOADFILE[2]=it_LOADFILE;
	_Context->msg_LOADFILE[3]=es_LOADFILE;
	_Context->msg_LOADFILE[4]=de_LOADFILE;
	_Context->msg_LOADFILE[5]=nl_LOADFILE;
	_Context->msg_LOADFILE[6]=pt_LOADFILE;
	_Context->msg_LOADFILE[7]=xx_LOADFILE;
	for (i=0; i < 8; i++)_Context->msg_CANCEL[i]=" ";
	_Context->msg_CANCEL[0]=en_CANCEL;
	_Context->msg_CANCEL[1]=fr_CANCEL;
	for (i=0; i < 8; i++)_Context->msg_Project[i]=" ";
	_Context->msg_Project[0]=en_Project;
	_Context->msg_Project[1]=fr_Project;
	_Context->focus_pages[8]=74;
	for (i=0; i < 8; i++)_Context->msg_Auto6256[i]=" ";
	_Context->msg_Auto6256[0]=en_Auto6256;
	_Context->msg_Auto6256[1]=fr_Auto6256;
	_Context->msg_Auto6256[2]=it_Auto6256;
	_Context->msg_Auto6256[3]=es_Auto6256;
	_Context->msg_Auto6256[4]=de_Auto6256;
	_Context->msg_Auto6256[5]=nl_Auto6256;
	_Context->msg_Auto6256[6]=pt_Auto6256;
	_Context->msg_Auto6256[7]=xx_Auto6256;
	for (i=0; i < 8; i++)_Context->msg_Auto5671[i]=" ";
	_Context->msg_Auto5671[0]=en_Auto5671;
	_Context->msg_Auto5671[1]=fr_Auto5671;
	_Context->msg_Auto5671[2]=it_Auto5671;
	_Context->msg_Auto5671[3]=es_Auto5671;
	_Context->msg_Auto5671[4]=de_Auto5671;
	_Context->msg_Auto5671[5]=nl_Auto5671;
	_Context->msg_Auto5671[6]=pt_Auto5671;
	_Context->msg_Auto5671[7]=xx_Auto5671;
	for (i=0; i < 8; i++)_Context->msg_Auto5675[i]=" ";
	_Context->msg_Auto5675[0]=en_Auto5675;
	_Context->msg_Auto5675[1]=fr_Auto5675;
	_Context->msg_Auto5675[2]=it_Auto5675;
	_Context->msg_Auto5675[3]=es_Auto5675;
	_Context->msg_Auto5675[4]=de_Auto5675;
	_Context->msg_Auto5675[5]=nl_Auto5675;
	_Context->msg_Auto5675[6]=pt_Auto5675;
	_Context->msg_Auto5675[7]=xx_Auto5675;
	for (i=0; i < 8; i++)_Context->msg_Auto5691[i]=" ";
	_Context->msg_Auto5691[0]=en_Auto5691;
	_Context->msg_Auto5691[1]=fr_Auto5691;
	_Context->msg_Auto5691[2]=it_Auto5691;
	_Context->msg_Auto5691[3]=es_Auto5691;
	_Context->msg_Auto5691[4]=de_Auto5691;
	_Context->msg_Auto5691[5]=nl_Auto5691;
	_Context->msg_Auto5691[6]=pt_Auto5691;
	_Context->msg_Auto5691[7]=xx_Auto5691;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto5703,_Context->y_Auto5703,790,600);
	return(0);
}

public 	int	accept_configuration_hide(struct accept_configuration_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto5703,_Context->y_Auto5703);
		_Context->ctrlbuffer=0;
		}

	return(result);
}

public	int	accept_configuration_remove(
	struct accept_configuration_context * _Context,
	char * pFILENAME,
	char * pABALHOST,
	char * pIDENTITY,
	char * pREPLAY,
	char * pRECORD,
	char * pATR,
	char * pATR_DEFINE,
	char * pATR_INCLUDE,
	char * pATR_OPTIONS,
	char * pALD,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pFONTPATH,
	char * pFONT1,
	char * pFONT2,
	char * pFONT3,
	char * pFONT4,
	char * pFONT5,
	char * pFONT6,
	char * pFONT7,
	char * pFONT8,
	char * pFONT9,
	char * pFONT10,
	char * pHTML_TITLE,
	char * pHTML_LOGO,
	char * pHTML_COPYRIGHT,
	char * pSCREEN_CSS,
	char * pPRINT_CSS,
	char * pNAVIGATOR,
	char * pDOCPATH,
	char * pPRINTER,
	char * pPAPERTYPE,
	char * pLAYOUT,
	char * pPAGEFEED,
	char * pRESOLUTION,
	char * pAED,
	char * pAED_FONT,
	char * pAED_STATE,
	char * pAED_SYNTAX,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FILENAME, 64, pFILENAME);
		visual_transferout(_Context->buffer_ABALHOST, 64, pABALHOST);
		visual_transferout(_Context->buffer_IDENTITY, 65, pIDENTITY);
		visual_transferout(_Context->buffer_REPLAY, 65, pREPLAY);
		visual_transferout(_Context->buffer_RECORD, 65, pRECORD);
		visual_transferout(_Context->buffer_ATR, 66, pATR);
		visual_transferout(_Context->buffer_ATR_DEFINE, 66, pATR_DEFINE);
		visual_transferout(_Context->buffer_ATR_INCLUDE, 66, pATR_INCLUDE);
		visual_transferout(_Context->buffer_ATR_OPTIONS, 66, pATR_OPTIONS);
		visual_transferout(_Context->buffer_ALD, 66, pALD);
		visual_transferout(_Context->buffer_ALD_OPTIONS, 66, pALD_OPTIONS);
		visual_transferout(_Context->buffer_OTR, 66, pOTR);
		visual_transferout(_Context->buffer_OTR_DEFINE, 66, pOTR_DEFINE);
		visual_transferout(_Context->buffer_OTR_INCLUDE, 66, pOTR_INCLUDE);
		visual_transferout(_Context->buffer_OTR_OPTIONS, 66, pOTR_OPTIONS);
		visual_transferout(_Context->buffer_OLD, 66, pOLD);
		visual_transferout(_Context->buffer_OLD_OPTIONS, 66, pOLD_OPTIONS);
		visual_transferout(_Context->buffer_EXA, 66, pEXA);
		visual_transferout(_Context->buffer_EXADB, 66, pEXADB);
		visual_transferout(_Context->buffer_IMAGEPATH, 68, pIMAGEPATH);
		visual_transferout(_Context->buffer_ICONPATH, 68, pICONPATH);
		visual_transferout(_Context->buffer_PALETTE, 68, pPALETTE);
		visual_transferout(_Context->buffer_SKIN, 68, pSKIN);
		visual_transferout((void *) 0, 0, pTRIGGER_STYLE);
		if ( pTRIGGER_STYLE != (char *) 0)
			*((int*)pTRIGGER_STYLE) = _Context->value_TRIGGER_STYLE;
		visual_transferout(_Context->buffer_TRIGGER_COLOUR, 11, pTRIGGER_COLOUR);
		visual_transferout(_Context->buffer_FONTPATH, 68, pFONTPATH);
		visual_transferout(_Context->buffer_FONT1, 66, pFONT1);
		visual_transferout(_Context->buffer_FONT2, 66, pFONT2);
		visual_transferout(_Context->buffer_FONT3, 66, pFONT3);
		visual_transferout(_Context->buffer_FONT4, 66, pFONT4);
		visual_transferout(_Context->buffer_FONT5, 66, pFONT5);
		visual_transferout(_Context->buffer_FONT6, 66, pFONT6);
		visual_transferout(_Context->buffer_FONT7, 66, pFONT7);
		visual_transferout(_Context->buffer_FONT8, 66, pFONT8);
		visual_transferout(_Context->buffer_FONT9, 66, pFONT9);
		visual_transferout(_Context->buffer_FONT10, 66, pFONT10);
		visual_transferout(_Context->buffer_HTML_TITLE, 66, pHTML_TITLE);
		visual_transferout(_Context->buffer_HTML_LOGO, 66, pHTML_LOGO);
		visual_transferout(_Context->buffer_HTML_COPYRIGHT, 66, pHTML_COPYRIGHT);
		visual_transferout(_Context->buffer_SCREEN_CSS, 66, pSCREEN_CSS);
		visual_transferout(_Context->buffer_PRINT_CSS, 66, pPRINT_CSS);
		visual_transferout(_Context->buffer_NAVIGATOR, 66, pNAVIGATOR);
		visual_transferout(_Context->buffer_DOCPATH, 66, pDOCPATH);
		visual_transferout(_Context->buffer_PRINTER, 68, pPRINTER);
		visual_transferout((void *) 0, 0, pPAPERTYPE);
		if ( pPAPERTYPE != (char *) 0)
			*((int*)pPAPERTYPE) = _Context->value_PAPERTYPE;
		visual_transferout((void *) 0, 0, pLAYOUT);
		if ( pLAYOUT != (char *) 0)
			*((int*)pLAYOUT) = _Context->value_LAYOUT;
		visual_transferout((void *) 0, 0, pPAGEFEED);
		if ( pPAGEFEED != (char *) 0)
			*((int*)pPAGEFEED) = _Context->value_PAGEFEED;
		visual_transferout((void *) 0, 0, pRESOLUTION);
		if ( pRESOLUTION != (char *) 0)
			*((int*)pRESOLUTION) = _Context->value_RESOLUTION;
		visual_transferout(_Context->buffer_AED, 66, pAED);
		visual_transferout((void *) 0, 0, pAED_FONT);
		if ( pAED_FONT != (char *) 0)
			*((int*)pAED_FONT) = _Context->value_AED_FONT;
		visual_transferout((void *) 0, 0, pAED_STATE);
		if ( pAED_STATE != (char *) 0)
			*((int*)pAED_STATE) = _Context->value_AED_STATE;
		visual_transferout((void *) 0, 0, pAED_SYNTAX);
		if ( pAED_SYNTAX != (char *) 0)
			*((int*)pAED_SYNTAX) = _Context->value_AED_SYNTAX;
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
		visual_transferout(_Context->buffer_AMAKE, 66, pAMAKE);
		visual_transferout(_Context->buffer_AMAKE_OPTIONS, 66, pAMAKE_OPTIONS);
		visual_transferout(_Context->buffer_AMAKE_DEFINE, 66, pAMAKE_DEFINE);
		visual_transferout(_Context->buffer_AMAKE_LIST, 66, pAMAKE_LIST);
		}
	if (_Context->pushbuffer != (void *) 0)
		_Context->pushbuffer = visual_drop(_Context->pushbuffer);
	_Context=liberate(_Context);

	return(result);
}

public	int	accept_configuration_show(struct accept_configuration_context * _Context)
{
	_Context->language = visual_national_language(-1);
	if ((_Context->pushbuffer != (void *) 0)
	&& (!(_Context->ctrlbuffer))) {
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto5703,_Context->y_Auto5703);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	visual_window(_Context->x_Auto5703,_Context->y_Auto5703,790,600,vfh[2],_Context->msg_Auto5703[_Context->language],strlen(_Context->msg_Auto5703[_Context->language]),0x7);
	visual_image(_Context->x_Auto5703+3,_Context->y_Auto5703+21,782,574,_Context->msg_Auto6246[_Context->language],4);
	if (_Context->page_number == 1 ) {
	_Context->trigger_General=visual_trigger_code(_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+90,710,16,vfh[1],27,0,_Context->msg_Auto5988[_Context->language],strlen(_Context->msg_Auto5988[_Context->language]),2);
	visual_frame(_Context->x_Auto5703+40,_Context->y_Auto5703+106,710,414,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto5703+210,_Context->y_Auto5703+150,518+2,16+2,5);
	visual_text(_Context->x_Auto5703+210+1,_Context->y_Auto5703+150+1,518,16,vfh[1],27,28,_Context->buffer_FILENAME,64,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto5703+210,_Context->y_Auto5703+180,518+2,16+2,5);
	visual_text(_Context->x_Auto5703+210+1,_Context->y_Auto5703+180+1,518,16,vfh[1],27,28,_Context->buffer_ABALHOST,64,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto5703+60,_Context->y_Auto5703+150,140,20,vfh[3],27,0,_Context->msg_Auto5994[_Context->language],strlen(_Context->msg_Auto5994[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto5703+60,_Context->y_Auto5703+180,140,20,vfh[3],27,0,_Context->msg_Auto5996[_Context->language],strlen(_Context->msg_Auto5996[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto5703+60,_Context->y_Auto5703+220,144,20,vfh[3],27,0,_Context->msg_Auto5998[_Context->language],strlen(_Context->msg_Auto5998[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto5703+60,_Context->y_Auto5703+250,144,20,vfh[3],27,0,_Context->msg_Auto6000[_Context->language],strlen(_Context->msg_Auto6000[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto5703+60,_Context->y_Auto5703+280,144,20,vfh[3],27,0,_Context->msg_Auto6002[_Context->language],strlen(_Context->msg_Auto6002[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto5703+210,_Context->y_Auto5703+220,520+2,16+2,5);
	visual_text(_Context->x_Auto5703+210+1,_Context->y_Auto5703+220+1,520,16,vfh[1],27,28,_Context->buffer_IDENTITY,65,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto5703+210,_Context->y_Auto5703+250,520+2,16+2,5);
	visual_text(_Context->x_Auto5703+210+1,_Context->y_Auto5703+250+1,520,16,vfh[1],27,28,_Context->buffer_REPLAY,65,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto5703+210,_Context->y_Auto5703+280,520+2,16+2,5);
	visual_text(_Context->x_Auto5703+210+1,_Context->y_Auto5703+280+1,520,16,vfh[1],27,28,_Context->buffer_RECORD,65,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Abal=visual_trigger_code(_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]),95,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]),95,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+80,710,16,vfh[1],27,0,_Context->msg_Auto6012[_Context->language],strlen(_Context->msg_Auto6012[_Context->language]),2);
	visual_frame(_Context->x_Auto5703+40,_Context->y_Auto5703+96,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+110,140,20,vfh[3],27,0,_Context->msg_Auto6014[_Context->language],strlen(_Context->msg_Auto6014[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+130,140,20,vfh[3],27,0,_Context->msg_Auto6016[_Context->language],strlen(_Context->msg_Auto6016[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+150,140,20,vfh[3],27,0,_Context->msg_Auto6018[_Context->language],strlen(_Context->msg_Auto6018[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+170,138,20,vfh[3],27,0,_Context->msg_Auto6020[_Context->language],strlen(_Context->msg_Auto6020[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+220,140,20,vfh[3],27,0,_Context->msg_Auto6022[_Context->language],strlen(_Context->msg_Auto6022[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+200,140,20,vfh[3],27,0,_Context->msg_Auto6024[_Context->language],strlen(_Context->msg_Auto6024[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+110,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,528,16,vfh[1],27,28,_Context->buffer_ATR,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+130,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+130+1,528,16,vfh[1],27,28,_Context->buffer_ATR_DEFINE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+150,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+150+1,528,16,vfh[1],27,28,_Context->buffer_ATR_INCLUDE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+170,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+170+1,528,16,vfh[1],27,28,_Context->buffer_ATR_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+200,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+200+1,528,16,vfh[1],27,28,_Context->buffer_ALD,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+220,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+220+1,528,16,vfh[1],27,28,_Context->buffer_ALD_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+260,710,16,vfh[1],27,0,_Context->msg_Auto6038[_Context->language],strlen(_Context->msg_Auto6038[_Context->language]),2);
	visual_frame(_Context->x_Auto5703+40,_Context->y_Auto5703+276,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+440,710,16,vfh[1],27,0,_Context->msg_Auto6040[_Context->language],strlen(_Context->msg_Auto6040[_Context->language]),2);
	visual_frame(_Context->x_Auto5703+40,_Context->y_Auto5703+456,710,64,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+290,140,20,vfh[3],27,0,_Context->msg_Auto6042[_Context->language],strlen(_Context->msg_Auto6042[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+310,140,20,vfh[3],27,0,_Context->msg_Auto6044[_Context->language],strlen(_Context->msg_Auto6044[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+330,140,20,vfh[3],27,0,_Context->msg_Auto6046[_Context->language],strlen(_Context->msg_Auto6046[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+350,140,20,vfh[3],27,0,_Context->msg_Auto6048[_Context->language],strlen(_Context->msg_Auto6048[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+400,140,20,vfh[3],27,0,_Context->msg_Auto6050[_Context->language],strlen(_Context->msg_Auto6050[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+380,140,20,vfh[3],27,0,_Context->msg_Auto6052[_Context->language],strlen(_Context->msg_Auto6052[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+470,140,20,vfh[3],27,0,_Context->msg_Auto6054[_Context->language],strlen(_Context->msg_Auto6054[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+490,140,20,vfh[3],27,0,_Context->msg_Auto6056[_Context->language],strlen(_Context->msg_Auto6056[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+290,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+290+1,528,16,vfh[1],27,28,_Context->buffer_OTR,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+310,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+310+1,528,16,vfh[1],27,28,_Context->buffer_OTR_DEFINE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+330,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+330+1,528,16,vfh[1],27,28,_Context->buffer_OTR_INCLUDE,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+350,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+350+1,528,16,vfh[1],27,28,_Context->buffer_OTR_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+380,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+380+1,528,16,vfh[1],27,28,_Context->buffer_OLD,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+400,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+400+1,528,16,vfh[1],27,28,_Context->buffer_OLD_OPTIONS,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+470,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+470+1,528,16,vfh[1],27,28,_Context->buffer_EXA,66,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+490,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+490+1,528,16,vfh[1],27,28,_Context->buffer_EXADB,66,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Images=visual_trigger_code(_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]),161,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]),161,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+110,154,20,vfh[3],27,0,_Context->msg_Auto6076[_Context->language],strlen(_Context->msg_Auto6076[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+110,544+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,544,16,vfh[1],27,28,_Context->buffer_IMAGEPATH,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+140,154,20,vfh[3],27,0,_Context->msg_Auto6080[_Context->language],strlen(_Context->msg_Auto6080[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+170,154,20,vfh[3],27,0,_Context->msg_Auto6082[_Context->language],strlen(_Context->msg_Auto6082[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+200,154,20,vfh[3],27,0,_Context->msg_Auto6084[_Context->language],strlen(_Context->msg_Auto6084[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+230,154,20,vfh[3],27,0,_Context->msg_Auto6086[_Context->language],strlen(_Context->msg_Auto6086[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto5703+450,_Context->y_Auto5703+230,184,20,vfh[3],27,0,_Context->msg_Auto6088[_Context->language],strlen(_Context->msg_Auto6088[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+140,544+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+140+1,544,16,vfh[1],27,28,_Context->buffer_ICONPATH,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+170,544+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+170+1,544,16,vfh[1],27,28,_Context->buffer_PALETTE,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+200,544+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+200+1,544,16,vfh[1],27,28,_Context->buffer_SKIN,68,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+230,184,80,vfh[1],27,28,parse_selection(_Context->msg_TRIGGER_STYLE[_Context->language],&_Context->value_TRIGGER_STYLE),512);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto5703+650,_Context->y_Auto5703+230,88+2,16+2,5);
	visual_text(_Context->x_Auto5703+650+1,_Context->y_Auto5703+230+1,88,16,vfh[1],27,28,_Context->buffer_TRIGGER_COLOUR,11,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_Fonts=visual_trigger_code(_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]),241,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]),241,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+150,700,16,vfh[1],27,0,_Context->msg_Auto6102[_Context->language],strlen(_Context->msg_Auto6102[_Context->language]),2);
	visual_frame(_Context->x_Auto5703+40,_Context->y_Auto5703+166,700,314,4);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+110,154,20,vfh[3],27,0,_Context->msg_Auto6104[_Context->language],strlen(_Context->msg_Auto6104[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+180,136,20,vfh[3],27,0,_Context->msg_Auto6106[_Context->language],strlen(_Context->msg_Auto6106[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+210,136,20,vfh[3],27,0,_Context->msg_Auto6108[_Context->language],strlen(_Context->msg_Auto6108[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+240,136,20,vfh[3],27,0,_Context->msg_Auto6110[_Context->language],strlen(_Context->msg_Auto6110[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+270,136,20,vfh[3],27,0,_Context->msg_Auto6112[_Context->language],strlen(_Context->msg_Auto6112[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+300,136,20,vfh[3],27,0,_Context->msg_Auto6114[_Context->language],strlen(_Context->msg_Auto6114[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+330,136,20,vfh[3],27,0,_Context->msg_Auto6116[_Context->language],strlen(_Context->msg_Auto6116[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+360,136,20,vfh[3],27,0,_Context->msg_Auto6118[_Context->language],strlen(_Context->msg_Auto6118[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+390,136,20,vfh[3],27,0,_Context->msg_Auto6120[_Context->language],strlen(_Context->msg_Auto6120[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+420,136,20,vfh[3],27,0,_Context->msg_Auto6122[_Context->language],strlen(_Context->msg_Auto6122[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+450,140,20,vfh[3],27,0,_Context->msg_Auto6124[_Context->language],strlen(_Context->msg_Auto6124[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+110,544+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,544,16,vfh[1],27,28,_Context->buffer_FONTPATH,68,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+180,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+180+1,528,16,vfh[1],27,28,_Context->buffer_FONT1,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+210,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+210+1,528,16,vfh[1],27,28,_Context->buffer_FONT2,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+240,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+240+1,528,16,vfh[1],27,28,_Context->buffer_FONT3,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+270,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+270+1,528,16,vfh[1],27,28,_Context->buffer_FONT4,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+300,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+300+1,528,16,vfh[1],27,28,_Context->buffer_FONT5,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+330,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+330+1,528,16,vfh[1],27,28,_Context->buffer_FONT6,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+360,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+360+1,528,16,vfh[1],27,28,_Context->buffer_FONT7,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+390,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+390+1,528,16,vfh[1],27,28,_Context->buffer_FONT8,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+420,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+420+1,528,16,vfh[1],27,28,_Context->buffer_FONT9,66,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+450,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+450+1,528,16,vfh[1],27,28,_Context->buffer_FONT10,66,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_Documents=visual_trigger_code(_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]),320,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]),320,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+80,710,16,vfh[1],27,0,_Context->msg_Auto6150[_Context->language],strlen(_Context->msg_Auto6150[_Context->language]),2);
	visual_frame(_Context->x_Auto5703+40,_Context->y_Auto5703+96,710,424,4);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+110,140,20,vfh[3],27,0,_Context->msg_Auto6152[_Context->language],strlen(_Context->msg_Auto6152[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+140,140,20,vfh[3],27,0,_Context->msg_Auto6154[_Context->language],strlen(_Context->msg_Auto6154[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+170,140,20,vfh[3],27,0,_Context->msg_Auto6156[_Context->language],strlen(_Context->msg_Auto6156[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+200,140,20,vfh[3],27,0,_Context->msg_Auto6158[_Context->language],strlen(_Context->msg_Auto6158[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+230,140,20,vfh[3],27,0,_Context->msg_Auto6160[_Context->language],strlen(_Context->msg_Auto6160[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+260,140,20,vfh[3],27,0,_Context->msg_Auto6162[_Context->language],strlen(_Context->msg_Auto6162[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+290,140,20,vfh[3],27,0,_Context->msg_Auto6164[_Context->language],strlen(_Context->msg_Auto6164[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+110,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,528,16,vfh[1],27,28,_Context->buffer_HTML_TITLE,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+140,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+140+1,528,16,vfh[1],27,28,_Context->buffer_HTML_LOGO,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+170,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+170+1,528,16,vfh[1],27,28,_Context->buffer_HTML_COPYRIGHT,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+200,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+200+1,528,16,vfh[1],27,28,_Context->buffer_SCREEN_CSS,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+230,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+230+1,528,16,vfh[1],27,28,_Context->buffer_PRINT_CSS,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+260,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+260+1,528,16,vfh[1],27,28,_Context->buffer_NAVIGATOR,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+290,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+290+1,528,16,vfh[1],27,28,_Context->buffer_DOCPATH,66,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_Printing=visual_trigger_code(_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]),425,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]),425,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+110,154,20,vfh[3],27,0,_Context->msg_Auto6182[_Context->language],strlen(_Context->msg_Auto6182[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+150,154,20,vfh[3],27,0,_Context->msg_Auto6184[_Context->language],strlen(_Context->msg_Auto6184[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto5703+440,_Context->y_Auto5703+150,154,20,vfh[3],27,0,_Context->msg_Auto6186[_Context->language],strlen(_Context->msg_Auto6186[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto5703+40,_Context->y_Auto5703+190,154,20,vfh[3],27,0,_Context->msg_Auto6188[_Context->language],strlen(_Context->msg_Auto6188[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto5703+440,_Context->y_Auto5703+190,154,20,vfh[3],27,0,_Context->msg_Auto6190[_Context->language],strlen(_Context->msg_Auto6190[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+110,544+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,544,16,vfh[1],27,28,_Context->buffer_PRINTER,68,0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto5703+590,_Context->y_Auto5703+150,152,48,vfh[1],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+190,144,48,vfh[1],0,0,parse_selection(_Context->msg_LAYOUT[_Context->language],&_Context->value_LAYOUT),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto5703+590,_Context->y_Auto5703+190,152,48,vfh[1],27,0,parse_selection(_Context->msg_PAGEFEED[_Context->language],&_Context->value_PAGEFEED),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+150,144,64,vfh[1],27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),768);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_Editor=visual_trigger_code(_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]),527,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]),527,0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+120,140,20,vfh[3],27,0,_Context->msg_Auto6204[_Context->language],strlen(_Context->msg_Auto6204[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+170,140,20,vfh[3],27,0,_Context->msg_Auto6206[_Context->language],strlen(_Context->msg_Auto6206[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+230,690,16,vfh[1],27,0,_Context->msg_Auto6208[_Context->language],strlen(_Context->msg_Auto6208[_Context->language]),2);
	visual_frame(_Context->x_Auto5703+50,_Context->y_Auto5703+246,690,74,4);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto5703+200,_Context->y_Auto5703+120,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+200+1,_Context->y_Auto5703+120+1,528,16,vfh[1],27,28,_Context->buffer_AED,66,0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+170,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_AED_STATE=visual_trigger_code(_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]));
	visual_check(_Context->x_Auto5703+90,_Context->y_Auto5703+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),_Context->value_AED_STATE|0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_AED_SYNTAX=visual_trigger_code(_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]));
	visual_check(_Context->x_Auto5703+340,_Context->y_Auto5703+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),_Context->value_AED_SYNTAX|0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+60,_Context->y_Auto5703+260,126,16,vfh[2],27,0,_Context->msg_auto6060[_Context->language],strlen(_Context->msg_auto6060[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+200,_Context->y_Auto5703+260,112,16,vfh[2],27,0,_Context->msg_auto6061[_Context->language],strlen(_Context->msg_auto6061[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+340,_Context->y_Auto5703+260,110,20,vfh[2],27,0,_Context->msg_auto6062[_Context->language],strlen(_Context->msg_auto6062[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+470,_Context->y_Auto5703+260,110,20,vfh[2],27,0,_Context->msg_auto6063[_Context->language],strlen(_Context->msg_auto6063[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto5703+600,_Context->y_Auto5703+260,126,16,vfh[2],27,0,_Context->msg_auto6064[_Context->language],strlen(_Context->msg_auto6064[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto5703+60,_Context->y_Auto5703+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto5703+340,_Context->y_Auto5703+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto5703+470,_Context->y_Auto5703+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto5703+600,_Context->y_Auto5703+280,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),768);
		}
	_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
	visual_button(_Context->x_Auto5703+20,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
	_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
	visual_button(_Context->x_Auto5703+120,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
	_Context->trigger_SAVELDAP=visual_trigger_code(_Context->msg_SAVELDAP[_Context->language],strlen(_Context->msg_SAVELDAP[_Context->language]));
	visual_button(_Context->x_Auto5703+220,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_SAVELDAP[_Context->language],strlen(_Context->msg_SAVELDAP[_Context->language]),0);
	_Context->trigger_LoadLdap=visual_trigger_code(_Context->msg_LoadLdap[_Context->language],strlen(_Context->msg_LoadLdap[_Context->language]));
	visual_button(_Context->x_Auto5703+470,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_LoadLdap[_Context->language],strlen(_Context->msg_LoadLdap[_Context->language]),0);
	_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
	visual_button(_Context->x_Auto5703+322,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
	_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
	visual_button(_Context->x_Auto5703+396,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
	_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
	visual_button(_Context->x_Auto5703+570,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
	_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
	visual_button(_Context->x_Auto5703+670,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
	if (_Context->page_number == 8 ) {
	_Context->trigger_Project=visual_trigger_code(_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]));
	visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]),608,2);
	} else {
		visual_tabpage(_Context->x_Auto5703+20,_Context->y_Auto5703+40,750,500,vfh[2],_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]),608,0);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+120,140,20,vfh[3],27,0,_Context->msg_Auto6256[_Context->language],strlen(_Context->msg_Auto6256[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+150,161,20,vfh[3],27,0,_Context->msg_Auto5671[_Context->language],strlen(_Context->msg_Auto5671[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+180,161,20,vfh[3],27,0,_Context->msg_Auto5675[_Context->language],strlen(_Context->msg_Auto5675[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto5703+50,_Context->y_Auto5703+210,161,20,vfh[3],27,0,_Context->msg_Auto5691[_Context->language],strlen(_Context->msg_Auto5691[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto5703+220,_Context->y_Auto5703+120,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+220+1,_Context->y_Auto5703+120+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE,66,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto5703+220,_Context->y_Auto5703+150,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+220+1,_Context->y_Auto5703+150+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE_OPTIONS,66,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto5703+220,_Context->y_Auto5703+180,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+220+1,_Context->y_Auto5703+180+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE_DEFINE,66,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto5703+220,_Context->y_Auto5703+210,528+2,16+2,5);
	visual_text(_Context->x_Auto5703+220+1,_Context->y_Auto5703+210+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE_LIST,66,0);
		}
	visual_thaw(_Context->x_Auto5703,_Context->y_Auto5703,790,600);
	visual_thaw(_Context->x_Auto5703,_Context->y_Auto5703,790,600);

	return(0);
}

private int Auto5703action(struct accept_configuration_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_configuration_hide(_Context);

		_Context->x_Auto5703 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto5703 < 0) { _Context->x_Auto5703=0; }
		_Context->y_Auto5703 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto5703 < 0) { _Context->y_Auto5703=0; }
			accept_configuration_show(_Context);

		visual_thaw(_Context->x_Auto5703,_Context->y_Auto5703,790,600);
		}
	while (visual_event(1) != _MIMO_UP);
	return(-1);
}
private int on_ACCEPT_event(struct accept_configuration_context * _Context) {
	return(13);
	return(-1);
}
private int on_SAVEFILE_event(struct accept_configuration_context * _Context) {
	return('Cs');
	return(-1);
}
private int on_SAVELDAP_event(struct accept_configuration_context * _Context) {
	return('SL');
	return(-1);
}
private int on_LoadLdap_event(struct accept_configuration_context * _Context) {
	return('LL');
	return(-1);
}
private int on_EDITFILE_event(struct accept_configuration_context * _Context) {
	return('Ce');
	return(-1);
}
private int on_DELETE_event(struct accept_configuration_context * _Context) {
	return('ZL');
	return(-1);
}
private int on_LOADFILE_event(struct accept_configuration_context * _Context) {
	return('Cl');
	return(-1);
}
private int on_CANCEL_event(struct accept_configuration_context * _Context) {
	return(27);
	return(-1);
}


public	int	accept_configuration_event(
struct accept_configuration_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_General == mb ) return(2);
		if (_Context->trigger_Abal == mb ) return(8);
		if (_Context->trigger_Images == mb ) return(23);
		if (_Context->trigger_Fonts == mb ) return(30);
		if (_Context->trigger_Documents == mb ) return(42);
		if (_Context->trigger_Printing == mb ) return(50);
		if (_Context->trigger_Editor == mb ) return(56);
		if (_Context->trigger_AED_STATE == mb ) return(59);
		if (_Context->trigger_AED_SYNTAX == mb ) return(60);
		if (_Context->trigger_ACCEPT == mb ) return(66);
		if (_Context->trigger_SAVEFILE == mb ) return(67);
		if (_Context->trigger_SAVELDAP == mb ) return(68);
		if (_Context->trigger_LoadLdap == mb ) return(69);
		if (_Context->trigger_EDITFILE == mb ) return(70);
		if (_Context->trigger_DELETE == mb ) return(71);
		if (_Context->trigger_LOADFILE == mb ) return(72);
		if (_Context->trigger_CANCEL == mb ) return(73);
		if (_Context->trigger_Project == mb ) return(74);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto5703+769) )  
	&&  (my >= (_Context->y_Auto5703+4) )  
	&&  (mx <= (_Context->x_Auto5703+786) )  
	&&  (my <= (_Context->y_Auto5703+20) )) {
		return(1);	/* Auto5703 */

		}
	if ((mx >= (_Context->x_Auto5703+753) )  
	&&  (my >= (_Context->y_Auto5703+4) )  
	&&  (mx <= (_Context->x_Auto5703+770) )  
	&&  (my <= (_Context->y_Auto5703+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrefer.htm");
			};
		return(-1);	/* Auto5703 */

		}
	if ((mx >= (_Context->x_Auto5703+737) )  
	&&  (my >= (_Context->y_Auto5703+4) )  
	&&  (mx <= (_Context->x_Auto5703+754) )  
	&&  (my <= (_Context->y_Auto5703+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_configuration_show(_Context);
		return(-1);	/* Auto5703 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto5703+4) )  
		&&  (my >= (_Context->y_Auto5703+4) )  
		&&  (mx <= (_Context->x_Auto5703+722) )  
		&&  (my <= (_Context->y_Auto5703+20) )) {
			return( Auto5703action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+0) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+94) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(2); /* General */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto5703+210) ) 
		&&  ( my >= (_Context->y_Auto5703+150) ) 
		&&  ( mx <= (_Context->x_Auto5703+210+518) ) 
		&&  ( my <= (_Context->y_Auto5703+150+16))) {
			return(3); /* FILENAME */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto5703+210) ) 
		&&  ( my >= (_Context->y_Auto5703+180) ) 
		&&  ( mx <= (_Context->x_Auto5703+210+518) ) 
		&&  ( my <= (_Context->y_Auto5703+180+16))) {
			return(4); /* ABALHOST */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto5703+210) ) 
		&&  ( my >= (_Context->y_Auto5703+220) ) 
		&&  ( mx <= (_Context->x_Auto5703+210+520) ) 
		&&  ( my <= (_Context->y_Auto5703+220+16))) {
			return(5); /* IDENTITY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto5703+210) ) 
		&&  ( my >= (_Context->y_Auto5703+250) ) 
		&&  ( mx <= (_Context->x_Auto5703+210+520) ) 
		&&  ( my <= (_Context->y_Auto5703+250+16))) {
			return(6); /* REPLAY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto5703+210) ) 
		&&  ( my >= (_Context->y_Auto5703+280) ) 
		&&  ( mx <= (_Context->x_Auto5703+210+520) ) 
		&&  ( my <= (_Context->y_Auto5703+280+16))) {
			return(7); /* RECORD */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+95) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+160) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(8); /* Abal */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+110) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+110+16))) {
			return(9); /* ATR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+130) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+130+16))) {
			return(10); /* ATR_DEFINE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+150) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+150+16))) {
			return(11); /* ATR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+170) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+170+16))) {
			return(12); /* ATR_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+200) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+200+16))) {
			return(13); /* ALD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+220) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+220+16))) {
			return(14); /* ALD_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+290) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+290+16))) {
			return(15); /* OTR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+310) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+310+16))) {
			return(16); /* OTR_DEFINE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+330) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+330+16))) {
			return(17); /* OTR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+350) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+350+16))) {
			return(18); /* OTR_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+380) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+380+16))) {
			return(19); /* OLD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+400) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+400+16))) {
			return(20); /* OLD_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+470) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+470+16))) {
			return(21); /* EXA */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+490) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+490+16))) {
			return(22); /* EXADB */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+161) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+240) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(23); /* Images */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+110) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+544) ) 
		&&  ( my <= (_Context->y_Auto5703+110+16))) {
			return(24); /* IMAGEPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+140) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+544) ) 
		&&  ( my <= (_Context->y_Auto5703+140+16))) {
			return(25); /* ICONPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+170) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+544) ) 
		&&  ( my <= (_Context->y_Auto5703+170+16))) {
			return(26); /* PALETTE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+200) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+544) ) 
		&&  ( my <= (_Context->y_Auto5703+200+16))) {
			return(27); /* SKIN */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto5703+200+0) ) 
		&&  ( my >= (_Context->y_Auto5703+230) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+184) ) 
		&&  ( my <= (_Context->y_Auto5703+230+16))) {
			return(28); /* TRIGGER_STYLE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto5703+650) ) 
		&&  ( my >= (_Context->y_Auto5703+230) ) 
		&&  ( mx <= (_Context->x_Auto5703+650+88) ) 
		&&  ( my <= (_Context->y_Auto5703+230+16))) {
			return(29); /* TRIGGER_COLOUR */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+241) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+319) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(30); /* Fonts */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+110) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+544) ) 
		&&  ( my <= (_Context->y_Auto5703+110+16))) {
			return(31); /* FONTPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+180) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+180+16))) {
			return(32); /* FONT1 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+210) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+210+16))) {
			return(33); /* FONT2 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+240) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+240+16))) {
			return(34); /* FONT3 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+270) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+270+16))) {
			return(35); /* FONT4 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+300) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+300+16))) {
			return(36); /* FONT5 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+330) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+330+16))) {
			return(37); /* FONT6 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+360) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+360+16))) {
			return(38); /* FONT7 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+390) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+390+16))) {
			return(39); /* FONT8 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+420) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+420+16))) {
			return(40); /* FONT9 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+450) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+450+16))) {
			return(41); /* FONT10 */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+320) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+424) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(42); /* Documents */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+110) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+110+16))) {
			return(43); /* HTML_TITLE */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+140) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+140+16))) {
			return(44); /* HTML_LOGO */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+170) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+170+16))) {
			return(45); /* HTML_COPYRIGHT */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+200) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+200+16))) {
			return(46); /* SCREEN_CSS */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+230) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+230+16))) {
			return(47); /* PRINT_CSS */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+260) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+260+16))) {
			return(48); /* NAVIGATOR */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+290) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+290+16))) {
			return(49); /* DOCPATH */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+425) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+526) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(50); /* Printing */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+110) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+544) ) 
		&&  ( my <= (_Context->y_Auto5703+110+16))) {
			return(51); /* PRINTER */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto5703+590+0) ) 
		&&  ( my >= (_Context->y_Auto5703+150) ) 
		&&  ( mx <= (_Context->x_Auto5703+590+152) ) 
		&&  ( my <= (_Context->y_Auto5703+150+16))) {
			return(52); /* PAPERTYPE */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto5703+200+0) ) 
		&&  ( my >= (_Context->y_Auto5703+190) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+144) ) 
		&&  ( my <= (_Context->y_Auto5703+190+16))) {
			return(53); /* LAYOUT */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto5703+590+0) ) 
		&&  ( my >= (_Context->y_Auto5703+190) ) 
		&&  ( mx <= (_Context->x_Auto5703+590+152) ) 
		&&  ( my <= (_Context->y_Auto5703+190+16))) {
			return(54); /* PAGEFEED */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto5703+200+0) ) 
		&&  ( my >= (_Context->y_Auto5703+150) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+144) ) 
		&&  ( my <= (_Context->y_Auto5703+150+16))) {
			return(55); /* RESOLUTION */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+527) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+607) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(56); /* Editor */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+200) ) 
		&&  ( my >= (_Context->y_Auto5703+120) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+528) ) 
		&&  ( my <= (_Context->y_Auto5703+120+16))) {
			return(57); /* AED */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+200+0) ) 
		&&  ( my >= (_Context->y_Auto5703+170) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+150) ) 
		&&  ( my <= (_Context->y_Auto5703+170+16))) {
			return(58); /* AED_FONT */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+90) ) 
		&&  ( my >= (_Context->y_Auto5703+350) ) 
		&&  ( mx <= (_Context->x_Auto5703+90+207) ) 
		&&  ( my <= (_Context->y_Auto5703+350+20))) {
			return(59); /* AED_STATE */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+340) ) 
		&&  ( my >= (_Context->y_Auto5703+350) ) 
		&&  ( mx <= (_Context->x_Auto5703+340+207) ) 
		&&  ( my <= (_Context->y_Auto5703+350+20))) {
			return(60); /* AED_SYNTAX */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+60+0) ) 
		&&  ( my >= (_Context->y_Auto5703+280) ) 
		&&  ( mx <= (_Context->x_Auto5703+60+120) ) 
		&&  ( my <= (_Context->y_Auto5703+280+16))) {
			return(61); /* AED_NORMAL */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+200+0) ) 
		&&  ( my >= (_Context->y_Auto5703+280) ) 
		&&  ( mx <= (_Context->x_Auto5703+200+120) ) 
		&&  ( my <= (_Context->y_Auto5703+280+16))) {
			return(62); /* AED_QUOTE */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+340+0) ) 
		&&  ( my >= (_Context->y_Auto5703+280) ) 
		&&  ( mx <= (_Context->x_Auto5703+340+112) ) 
		&&  ( my <= (_Context->y_Auto5703+280+16))) {
			return(63); /* AED_KEYWORD */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+470+0) ) 
		&&  ( my >= (_Context->y_Auto5703+280) ) 
		&&  ( mx <= (_Context->x_Auto5703+470+112) ) 
		&&  ( my <= (_Context->y_Auto5703+280+16))) {
			return(64); /* AED_COMMENT */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto5703+600+0) ) 
		&&  ( my >= (_Context->y_Auto5703+280) ) 
		&&  ( mx <= (_Context->x_Auto5703+600+120) ) 
		&&  ( my <= (_Context->y_Auto5703+280+16))) {
			return(65); /* AED_PUNCTUATE */
			}
		}
	if (( mx >= (_Context->x_Auto5703+20) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+20+98) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(66); /* ACCEPT */
		}
	if (( mx >= (_Context->x_Auto5703+120) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+120+98) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(67); /* SAVEFILE */
		}
	if (( mx >= (_Context->x_Auto5703+220) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+220+98) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(68); /* SAVELDAP */
		}
	if (( mx >= (_Context->x_Auto5703+470) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+470+98) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(69); /* LoadLdap */
		}
	if (( mx >= (_Context->x_Auto5703+322) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+322+70) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(70); /* EDITFILE */
		}
	if (( mx >= (_Context->x_Auto5703+396) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+396+70) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(71); /* DELETE */
		}
	if (( mx >= (_Context->x_Auto5703+570) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+570+98) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(72); /* LOADFILE */
		}
	if (( mx >= (_Context->x_Auto5703+670) ) 
	&&  ( my >= (_Context->y_Auto5703+550) ) 
	&&  ( mx <= (_Context->x_Auto5703+670+98) ) 
	&&  ( my <= (_Context->y_Auto5703+550+32))) {
		return(73); /* CANCEL */
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto5703+20+608) ) 
		&&  ( my >= (_Context->y_Auto5703+40) ) 
		&&  ( mx <= (_Context->x_Auto5703+20+690) ) 
		&&  ( my <= (_Context->y_Auto5703+40+24))) {
			return(74); /* Project */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto5703+220) ) 
		&&  ( my >= (_Context->y_Auto5703+120) ) 
		&&  ( mx <= (_Context->x_Auto5703+220+528) ) 
		&&  ( my <= (_Context->y_Auto5703+120+16))) {
			return(75); /* AMAKE */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto5703+220) ) 
		&&  ( my >= (_Context->y_Auto5703+150) ) 
		&&  ( mx <= (_Context->x_Auto5703+220+528) ) 
		&&  ( my <= (_Context->y_Auto5703+150+16))) {
			return(76); /* AMAKE_OPTIONS */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto5703+220) ) 
		&&  ( my >= (_Context->y_Auto5703+180) ) 
		&&  ( mx <= (_Context->x_Auto5703+220+528) ) 
		&&  ( my <= (_Context->y_Auto5703+180+16))) {
			return(77); /* AMAKE_DEFINE */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto5703+220) ) 
		&&  ( my >= (_Context->y_Auto5703+210) ) 
		&&  ( mx <= (_Context->x_Auto5703+220+528) ) 
		&&  ( my <= (_Context->y_Auto5703+210+16))) {
			return(78); /* AMAKE_LIST */
			}
		}

	return(-1);
}


public	int	accept_configuration_losefocus(struct accept_configuration_context * _Context)
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

		}
	return(0);

}


public	int	accept_configuration_focus(struct accept_configuration_context * _Context)
{
	int retcode=0;

	while( visual_kbhit() ) (void) visual_getch();

	while(1) {
		switch (_Context->focus_item) {
			case	0x2 :
				/* General */
				if (_Context->page_number == 1 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3 :
				/* FILENAME */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+210+1,_Context->y_Auto5703+150+1,518,16,vfh[1],_Context->buffer_FILENAME,64);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* ABALHOST */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+210+1,_Context->y_Auto5703+180+1,518,16,vfh[1],_Context->buffer_ABALHOST,64);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* IDENTITY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+210+1,_Context->y_Auto5703+220+1,520,16,vfh[1],_Context->buffer_IDENTITY,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* REPLAY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+210+1,_Context->y_Auto5703+250+1,520,16,vfh[1],_Context->buffer_REPLAY,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* RECORD */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+210+1,_Context->y_Auto5703+280+1,520,16,vfh[1],_Context->buffer_RECORD,65);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* Abal */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x9 :
				/* ATR */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,528,16,vfh[1],_Context->buffer_ATR,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xa :
				/* ATR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+130+1,528,16,vfh[1],_Context->buffer_ATR_DEFINE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* ATR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+150+1,528,16,vfh[1],_Context->buffer_ATR_INCLUDE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* ATR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+170+1,528,16,vfh[1],_Context->buffer_ATR_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* ALD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+200+1,528,16,vfh[1],_Context->buffer_ALD,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* ALD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+220+1,528,16,vfh[1],_Context->buffer_ALD_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* OTR */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+290+1,528,16,vfh[1],_Context->buffer_OTR,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* OTR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+310+1,528,16,vfh[1],_Context->buffer_OTR_DEFINE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* OTR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+330+1,528,16,vfh[1],_Context->buffer_OTR_INCLUDE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* OTR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+350+1,528,16,vfh[1],_Context->buffer_OTR_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* OLD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+380+1,528,16,vfh[1],_Context->buffer_OLD,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* OLD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+400+1,528,16,vfh[1],_Context->buffer_OLD_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* EXA */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+470+1,528,16,vfh[1],_Context->buffer_EXA,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* EXADB */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+490+1,528,16,vfh[1],_Context->buffer_EXADB,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* Images */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x18 :
				/* IMAGEPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,544,16,vfh[1],_Context->buffer_IMAGEPATH,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ICONPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+140+1,544,16,vfh[1],_Context->buffer_ICONPATH,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* PALETTE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+170+1,544,16,vfh[1],_Context->buffer_PALETTE,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* SKIN */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+200+1,544,16,vfh[1],_Context->buffer_SKIN,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* TRIGGER_STYLE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+230,184,80,vfh[1],27,28,parse_selection(_Context->msg_TRIGGER_STYLE[_Context->language],&_Context->value_TRIGGER_STYLE),514);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* TRIGGER_COLOUR */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+650+1,_Context->y_Auto5703+230+1,88,16,vfh[1],_Context->buffer_TRIGGER_COLOUR,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* Fonts */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x1f :
				/* FONTPATH */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,544,16,vfh[1],_Context->buffer_FONTPATH,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* FONT1 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+180+1,528,16,vfh[1],_Context->buffer_FONT1,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* FONT2 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+210+1,528,16,vfh[1],_Context->buffer_FONT2,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* FONT3 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+240+1,528,16,vfh[1],_Context->buffer_FONT3,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* FONT4 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+270+1,528,16,vfh[1],_Context->buffer_FONT4,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* FONT5 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+300+1,528,16,vfh[1],_Context->buffer_FONT5,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x25 :
				/* FONT6 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+330+1,528,16,vfh[1],_Context->buffer_FONT6,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* FONT7 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+360+1,528,16,vfh[1],_Context->buffer_FONT7,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* FONT8 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+390+1,528,16,vfh[1],_Context->buffer_FONT8,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* FONT9 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+420+1,528,16,vfh[1],_Context->buffer_FONT9,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* FONT10 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+450+1,528,16,vfh[1],_Context->buffer_FONT10,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* Documents */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x2b :
				/* HTML_TITLE */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,528,16,vfh[1],_Context->buffer_HTML_TITLE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* HTML_LOGO */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+140+1,528,16,vfh[1],_Context->buffer_HTML_LOGO,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* HTML_COPYRIGHT */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+170+1,528,16,vfh[1],_Context->buffer_HTML_COPYRIGHT,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* SCREEN_CSS */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+200+1,528,16,vfh[1],_Context->buffer_SCREEN_CSS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* PRINT_CSS */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+230+1,528,16,vfh[1],_Context->buffer_PRINT_CSS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* NAVIGATOR */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+260+1,528,16,vfh[1],_Context->buffer_NAVIGATOR,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* DOCPATH */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+290+1,528,16,vfh[1],_Context->buffer_DOCPATH,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* Printing */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x33 :
				/* PRINTER */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+110+1,544,16,vfh[1],_Context->buffer_PRINTER,68);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* PAPERTYPE */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+590,_Context->y_Auto5703+150,152,48,vfh[1],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* LAYOUT */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+190,144,48,vfh[1],0,0,parse_selection(_Context->msg_LAYOUT[_Context->language],&_Context->value_LAYOUT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* PAGEFEED */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+590,_Context->y_Auto5703+190,152,48,vfh[1],27,0,parse_selection(_Context->msg_PAGEFEED[_Context->language],&_Context->value_PAGEFEED),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x37 :
				/* RESOLUTION */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+150,144,64,vfh[1],27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x38 :
				/* Editor */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x39 :
				/* AED */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+200+1,_Context->y_Auto5703+120+1,528,16,vfh[1],_Context->buffer_AED,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3a :
				/* AED_FONT */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+170,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3b :
				/* AED_STATE */
				if (_Context->page_number == 7 ) {
				visual_check(_Context->x_Auto5703+90,_Context->y_Auto5703+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),(_Context->value_AED_STATE |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto5703+90,_Context->y_Auto5703+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),(_Context->value_AED_STATE |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3c :
				/* AED_SYNTAX */
				if (_Context->page_number == 7 ) {
				visual_check(_Context->x_Auto5703+340,_Context->y_Auto5703+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),(_Context->value_AED_SYNTAX |2));
					_Context->keycode = visual_getch();
				visual_check(_Context->x_Auto5703+340,_Context->y_Auto5703+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),(_Context->value_AED_SYNTAX |0));
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3d :
				/* AED_NORMAL */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+60,_Context->y_Auto5703+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3e :
				/* AED_QUOTE */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+200,_Context->y_Auto5703+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3f :
				/* AED_KEYWORD */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+340,_Context->y_Auto5703+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x40 :
				/* AED_COMMENT */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+470,_Context->y_Auto5703+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x41 :
				/* AED_PUNCTUATE */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto5703+600,_Context->y_Auto5703+280,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x42 :
				/* ACCEPT */
				visual_button(_Context->x_Auto5703+20,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+20,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
				break;
			case	0x43 :
				/* SAVEFILE */
				visual_button(_Context->x_Auto5703+120,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+120,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
				break;
			case	0x44 :
				/* SAVELDAP */
				visual_button(_Context->x_Auto5703+220,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_SAVELDAP[_Context->language],strlen(_Context->msg_SAVELDAP[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+220,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_SAVELDAP[_Context->language],strlen(_Context->msg_SAVELDAP[_Context->language]),0);
				break;
			case	0x45 :
				/* LoadLdap */
				visual_button(_Context->x_Auto5703+470,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_LoadLdap[_Context->language],strlen(_Context->msg_LoadLdap[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+470,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_LoadLdap[_Context->language],strlen(_Context->msg_LoadLdap[_Context->language]),0);
				break;
			case	0x46 :
				/* EDITFILE */
				visual_button(_Context->x_Auto5703+322,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+322,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
				break;
			case	0x47 :
				/* DELETE */
				visual_button(_Context->x_Auto5703+396,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+396,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
				break;
			case	0x48 :
				/* LOADFILE */
				visual_button(_Context->x_Auto5703+570,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+570,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
				break;
			case	0x49 :
				/* CANCEL */
				visual_button(_Context->x_Auto5703+670,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),2);
				_Context->keycode = visual_getch();
				visual_button(_Context->x_Auto5703+670,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
				break;
			case	0x4a :
				/* Project */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x4b :
				/* AMAKE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+220+1,_Context->y_Auto5703+120+1,528,16,vfh[1],_Context->buffer_AMAKE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4c :
				/* AMAKE_OPTIONS */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+220+1,_Context->y_Auto5703+150+1,528,16,vfh[1],_Context->buffer_AMAKE_OPTIONS,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4d :
				/* AMAKE_DEFINE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+220+1,_Context->y_Auto5703+180+1,528,16,vfh[1],_Context->buffer_AMAKE_DEFINE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4e :
				/* AMAKE_LIST */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto5703+220+1,_Context->y_Auto5703+210+1,528,16,vfh[1],_Context->buffer_AMAKE_LIST,66);
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
			accept_configuration_losefocus(_Context);
			_Context->page_number=1;
			_Context->focus_item=1;
			accept_configuration_show(_Context);
			continue;
		case	0x2 :
			accept_configuration_losefocus(_Context);
			_Context->page_number=8;
			_Context->focus_item=78;
			accept_configuration_show(_Context);
			continue;
		case	0x3 :
			accept_configuration_losefocus(_Context);
			if ( _Context->page_number < 8 )
				_Context->page_number++;
			else	_Context->page_number=1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_configuration_show(_Context);
			continue;
		case	0x12 :
			accept_configuration_losefocus(_Context);
			if (_Context->page_number > 1 )
				_Context->page_number--;
			else	_Context->page_number = 1;
			_Context->focus_item=_Context->focus_pages[_Context->page_number];
			accept_configuration_show(_Context);
			continue;
			case	0x100 :
				if ((retcode=accept_configuration_event(_Context)) == -1)
					continue;
				switch ((_Context->focus_item = retcode)) {
					case	0x1 :
						/* Auto5703 */
						if (visual_event(1) & _MIMO_UP) {
							_Context->keycode=27;
							break;
						} else {
							continue;
							}
					case	0x2 :
						/* General */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 1;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x3 :
						/* FILENAME */
						continue;
					case	0x4 :
						/* ABALHOST */
						continue;
					case	0x5 :
						/* IDENTITY */
						continue;
					case	0x6 :
						/* REPLAY */
						continue;
					case	0x7 :
						/* RECORD */
						continue;
					case	0x8 :
						/* Abal */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 2;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x9 :
						/* ATR */
						continue;
					case	0xa :
						/* ATR_DEFINE */
						continue;
					case	0xb :
						/* ATR_INCLUDE */
						continue;
					case	0xc :
						/* ATR_OPTIONS */
						continue;
					case	0xd :
						/* ALD */
						continue;
					case	0xe :
						/* ALD_OPTIONS */
						continue;
					case	0xf :
						/* OTR */
						continue;
					case	0x10 :
						/* OTR_DEFINE */
						continue;
					case	0x11 :
						/* OTR_INCLUDE */
						continue;
					case	0x12 :
						/* OTR_OPTIONS */
						continue;
					case	0x13 :
						/* OLD */
						continue;
					case	0x14 :
						/* OLD_OPTIONS */
						continue;
					case	0x15 :
						/* EXA */
						continue;
					case	0x16 :
						/* EXADB */
						continue;
					case	0x17 :
						/* Images */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 3;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x18 :
						/* IMAGEPATH */
						continue;
					case	0x19 :
						/* ICONPATH */
						continue;
					case	0x1a :
						/* PALETTE */
						continue;
					case	0x1b :
						/* SKIN */
						continue;
					case	0x1c :
						/* TRIGGER_STYLE */
						continue;
					case	0x1d :
						/* TRIGGER_COLOUR */
						continue;
					case	0x1e :
						/* Fonts */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 4;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x1f :
						/* FONTPATH */
						continue;
					case	0x20 :
						/* FONT1 */
						continue;
					case	0x21 :
						/* FONT2 */
						continue;
					case	0x22 :
						/* FONT3 */
						continue;
					case	0x23 :
						/* FONT4 */
						continue;
					case	0x24 :
						/* FONT5 */
						continue;
					case	0x25 :
						/* FONT6 */
						continue;
					case	0x26 :
						/* FONT7 */
						continue;
					case	0x27 :
						/* FONT8 */
						continue;
					case	0x28 :
						/* FONT9 */
						continue;
					case	0x29 :
						/* FONT10 */
						continue;
					case	0x2a :
						/* Documents */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 5;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x2b :
						/* HTML_TITLE */
						continue;
					case	0x2c :
						/* HTML_LOGO */
						continue;
					case	0x2d :
						/* HTML_COPYRIGHT */
						continue;
					case	0x2e :
						/* SCREEN_CSS */
						continue;
					case	0x2f :
						/* PRINT_CSS */
						continue;
					case	0x30 :
						/* NAVIGATOR */
						continue;
					case	0x31 :
						/* DOCPATH */
						continue;
					case	0x32 :
						/* Printing */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 6;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x33 :
						/* PRINTER */
						continue;
					case	0x34 :
						/* PAPERTYPE */
						continue;
					case	0x35 :
						/* LAYOUT */
						continue;
					case	0x36 :
						/* PAGEFEED */
						continue;
					case	0x37 :
						/* RESOLUTION */
						continue;
					case	0x38 :
						/* Editor */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 7;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x39 :
						/* AED */
						continue;
					case	0x3a :
						/* AED_FONT */
						continue;
					case	0x3b :
						/* AED_STATE */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AED_STATE += 1;
							_Context->value_AED_STATE &= 1;
							}
						continue;
					case	0x3c :
						/* AED_SYNTAX */
						if (visual_event(1) & _MIMO_UP) {
							_Context->value_AED_SYNTAX += 1;
							_Context->value_AED_SYNTAX &= 1;
							}
						continue;
					case	0x3d :
						/* AED_NORMAL */
						continue;
					case	0x3e :
						/* AED_QUOTE */
						continue;
					case	0x3f :
						/* AED_KEYWORD */
						continue;
					case	0x40 :
						/* AED_COMMENT */
						continue;
					case	0x41 :
						/* AED_PUNCTUATE */
						continue;
					case	0x42 :
						/* ACCEPT */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+20,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+20,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_ACCEPT_event(_Context)) != -1) break;

							}
						continue;
					case	0x43 :
						/* SAVEFILE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+120,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+120,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SAVEFILE_event(_Context)) != -1) break;

							}
						continue;
					case	0x44 :
						/* SAVELDAP */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+220,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_SAVELDAP[_Context->language],strlen(_Context->msg_SAVELDAP[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+220,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_SAVELDAP[_Context->language],strlen(_Context->msg_SAVELDAP[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_SAVELDAP_event(_Context)) != -1) break;

							}
						continue;
					case	0x45 :
						/* LoadLdap */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+470,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_LoadLdap[_Context->language],strlen(_Context->msg_LoadLdap[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+470,_Context->y_Auto5703+550,98,32,vfh[2],28,28,_Context->msg_LoadLdap[_Context->language],strlen(_Context->msg_LoadLdap[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_LoadLdap_event(_Context)) != -1) break;

							}
						continue;
					case	0x46 :
						/* EDITFILE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+322,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+322,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_EDITFILE_event(_Context)) != -1) break;

							}
						continue;
					case	0x47 :
						/* DELETE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+396,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+396,_Context->y_Auto5703+550,70,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_DELETE_event(_Context)) != -1) break;

							}
						continue;
					case	0x48 :
						/* LOADFILE */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+570,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+570,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_LOADFILE_event(_Context)) != -1) break;

							}
						continue;
					case	0x49 :
						/* CANCEL */
						if (visual_event(1) & _MIMO_DOWN) {
							visual_button(_Context->x_Auto5703+670,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),2);
							}
						else if (visual_event(1) & _MIMO_UP) {
							visual_button(_Context->x_Auto5703+670,_Context->y_Auto5703+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
							}
						if ( visual_event(1) &  0x20 ) {
						if ((_Context->keycode = on_CANCEL_event(_Context)) != -1) break;

							}
						continue;
					case	0x4a :
						/* Project */
						if (visual_event(1) & _MIMO_DOWN) {
							accept_configuration_losefocus(_Context);
							_Context->page_number = 8;
							accept_configuration_show(_Context);
							}
						continue;
					case	0x4b :
						/* AMAKE */
						continue;
					case	0x4c :
						/* AMAKE_OPTIONS */
						continue;
					case	0x4d :
						/* AMAKE_DEFINE */
						continue;
					case	0x4e :
						/* AMAKE_LIST */
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
				_Context->focus_item=78;
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

public	int	accept_configuration(
	char * pFILENAME,
	char * pABALHOST,
	char * pIDENTITY,
	char * pREPLAY,
	char * pRECORD,
	char * pATR,
	char * pATR_DEFINE,
	char * pATR_INCLUDE,
	char * pATR_OPTIONS,
	char * pALD,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pFONTPATH,
	char * pFONT1,
	char * pFONT2,
	char * pFONT3,
	char * pFONT4,
	char * pFONT5,
	char * pFONT6,
	char * pFONT7,
	char * pFONT8,
	char * pFONT9,
	char * pFONT10,
	char * pHTML_TITLE,
	char * pHTML_LOGO,
	char * pHTML_COPYRIGHT,
	char * pSCREEN_CSS,
	char * pPRINT_CSS,
	char * pNAVIGATOR,
	char * pDOCPATH,
	char * pPRINTER,
	char * pPAPERTYPE,
	char * pLAYOUT,
	char * pPAGEFEED,
	char * pRESOLUTION,
	char * pAED,
	char * pAED_FONT,
	char * pAED_STATE,
	char * pAED_SYNTAX,
	char * pAED_NORMAL,
	char * pAED_QUOTE,
	char * pAED_KEYWORD,
	char * pAED_COMMENT,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST)
{
	int	status=0;
	struct accept_configuration_context * _Context=(struct accept_configuration_context*) 0;
	status = accept_configuration_create(
	&_Context,
	 pFILENAME,
	 pABALHOST,
	 pIDENTITY,
	 pREPLAY,
	 pRECORD,
	 pATR,
	 pATR_DEFINE,
	 pATR_INCLUDE,
	 pATR_OPTIONS,
	 pALD,
	 pALD_OPTIONS,
	 pOTR,
	 pOTR_DEFINE,
	 pOTR_INCLUDE,
	 pOTR_OPTIONS,
	 pOLD,
	 pOLD_OPTIONS,
	 pEXA,
	 pEXADB,
	 pIMAGEPATH,
	 pICONPATH,
	 pPALETTE,
	 pSKIN,
	 pTRIGGER_STYLE,
	 pTRIGGER_COLOUR,
	 pFONTPATH,
	 pFONT1,
	 pFONT2,
	 pFONT3,
	 pFONT4,
	 pFONT5,
	 pFONT6,
	 pFONT7,
	 pFONT8,
	 pFONT9,
	 pFONT10,
	 pHTML_TITLE,
	 pHTML_LOGO,
	 pHTML_COPYRIGHT,
	 pSCREEN_CSS,
	 pPRINT_CSS,
	 pNAVIGATOR,
	 pDOCPATH,
	 pPRINTER,
	 pPAPERTYPE,
	 pLAYOUT,
	 pPAGEFEED,
	 pRESOLUTION,
	 pAED,
	 pAED_FONT,
	 pAED_STATE,
	 pAED_SYNTAX,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pAMAKE,
	 pAMAKE_OPTIONS,
	 pAMAKE_DEFINE,
	 pAMAKE_LIST);
	if ( status != 0) return(status);
	status = accept_configuration_show(_Context);
		enter_modal();
	status = accept_configuration_focus(_Context);
		leave_modal();
	status = accept_configuration_hide(_Context);
	status = accept_configuration_remove(
	_Context,
	 pFILENAME,
	 pABALHOST,
	 pIDENTITY,
	 pREPLAY,
	 pRECORD,
	 pATR,
	 pATR_DEFINE,
	 pATR_INCLUDE,
	 pATR_OPTIONS,
	 pALD,
	 pALD_OPTIONS,
	 pOTR,
	 pOTR_DEFINE,
	 pOTR_INCLUDE,
	 pOTR_OPTIONS,
	 pOLD,
	 pOLD_OPTIONS,
	 pEXA,
	 pEXADB,
	 pIMAGEPATH,
	 pICONPATH,
	 pPALETTE,
	 pSKIN,
	 pTRIGGER_STYLE,
	 pTRIGGER_COLOUR,
	 pFONTPATH,
	 pFONT1,
	 pFONT2,
	 pFONT3,
	 pFONT4,
	 pFONT5,
	 pFONT6,
	 pFONT7,
	 pFONT8,
	 pFONT9,
	 pFONT10,
	 pHTML_TITLE,
	 pHTML_LOGO,
	 pHTML_COPYRIGHT,
	 pSCREEN_CSS,
	 pPRINT_CSS,
	 pNAVIGATOR,
	 pDOCPATH,
	 pPRINTER,
	 pPAPERTYPE,
	 pLAYOUT,
	 pPAGEFEED,
	 pRESOLUTION,
	 pAED,
	 pAED_FONT,
	 pAED_STATE,
	 pAED_SYNTAX,
	 pAED_NORMAL,
	 pAED_QUOTE,
	 pAED_KEYWORD,
	 pAED_COMMENT,
	 pAED_PUNCTUATE,
	 pAMAKE,
	 pAMAKE_OPTIONS,
	 pAMAKE_DEFINE,
	 pAMAKE_LIST);

	while( visual_kbhit() ) (void) visual_getch();
	return(status);
}
/* End of File */

#endif /* _vrefer_c */
