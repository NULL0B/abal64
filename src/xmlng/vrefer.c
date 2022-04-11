
#ifndef _vrefer_c
#define _vrefer_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.1a.0.37                                                */
/* Production     : C                                                        */
/* Project        : vrefer.xml                                               */
/* Target         : vrefer.c                                                 */
/* Identification : 0.0-1200412358-16141.2413                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singconf.h"
#include "singprot.h"
#define en__Auto459   ""
#define fr__Auto459   ""
#define it__Auto459   ""
#define es__Auto459   ""
#define de__Auto459   ""
#define nl__Auto459   ""
#define pt__Auto459   ""
#define xx__Auto459   ""
#define en_General   "&General"
#define fr_General   "&G‚n‚ral"
#define it_General   "&General"
#define es_General   "&General"
#define de_General   "&General"
#define nl_General   "&General"
#define pt_General   "&General"
#define xx_General   "&General"
#define en_Auto460   "General Configuration"
#define fr_Auto460   "Configuration g‚n‚rale"
#define it_Auto460   "General Configuration"
#define es_Auto460   "General Configuration"
#define de_Auto460   "General Configuration"
#define nl_Auto460   "General Configuration"
#define pt_Auto460   "General Configuration"
#define xx_Auto460   "General Configuration"
#define en_FILENAME   ""
#define en__FILENAME   ""
#define en_ChoixFILENAME   "..."
#define fr_ChoixFILENAME   "..."
#define it_ChoixFILENAME   "..."
#define es_ChoixFILENAME   "..."
#define de_ChoixFILENAME   "..."
#define nl_ChoixFILENAME   "..."
#define pt_ChoixFILENAME   "..."
#define xx_ChoixFILENAME   "..."
#define en__ChoixFILENAME   ""
#define fr__ChoixFILENAME   ""
#define it__ChoixFILENAME   ""
#define es__ChoixFILENAME   ""
#define de__ChoixFILENAME   ""
#define nl__ChoixFILENAME   ""
#define pt__ChoixFILENAME   ""
#define xx__ChoixFILENAME   ""
#define en_ABALHOST   ""
#define en_Auto461   "FILENAME"
#define fr_Auto461   "Nom de fichier"
#define it_Auto461   "FILENAME"
#define es_Auto461   "FILENAME"
#define de_Auto461   "FILENAME"
#define nl_Auto461   "FILENAME"
#define pt_Auto461   "FILENAME"
#define xx_Auto461   "FILENAME"
#define en_Auto462   "ABALHOST"
#define fr_Auto462   "ABALHOST"
#define it_Auto462   "ABALHOST"
#define es_Auto462   "ABALHOST"
#define de_Auto462   "ABALHOST"
#define nl_Auto462   "ABALHOST"
#define pt_Auto462   "ABALHOST"
#define xx_Auto462   "ABALHOST"
#define en_Auto463   "IDENTITY"
#define fr_Auto463   "Identit‚"
#define it_Auto463   "IDENTITY"
#define es_Auto463   "IDENTITY"
#define de_Auto463   "IDENTITY"
#define nl_Auto463   "IDENTITY"
#define pt_Auto463   "IDENTITY"
#define xx_Auto463   "Ainm"
#define en_Auto464   "REPLAY"
#define fr_Auto464   "Refaire"
#define it_Auto464   "Replay"
#define es_Auto464   "Replay"
#define de_Auto464   "Replay"
#define nl_Auto464   "Replay"
#define pt_Auto464   "Replay"
#define xx_Auto464   "Replay"
#define en__Auto464   ""
#define en_Auto465   "RECORD"
#define fr_Auto465   "Enregistrer"
#define it_Auto465   "RECORD"
#define es_Auto465   "RECORD"
#define de_Auto465   "RECORD"
#define nl_Auto465   "RECORD"
#define pt_Auto465   "RECORD"
#define xx_Auto465   "RECORD"
#define en_IDENTITY   ""
#define en_REPLAY   ""
#define en_RECORD   ""
#define en__RECORD   ""
#define en_Abal   "A&bal"
#define fr_Abal   "A&bal"
#define it_Abal   "A&bal"
#define es_Abal   "A&bal"
#define de_Abal   "A&bal"
#define nl_Abal   "A&bal"
#define pt_Abal   "A&bal"
#define xx_Abal   "A&bal"
#define en__Abal   ""
#define en_Auto466   "ABAL"
#define fr_Auto466   "ABAL"
#define it_Auto466   "ABAL"
#define es_Auto466   "ABAL"
#define de_Auto466   "ABAL"
#define nl_Auto466   "ABAL"
#define pt_Auto466   "ABAL"
#define xx_Auto466   "ABAL"
#define en__Auto466   ""
#define en_Auto467   "ATR"
#define fr_Auto467   "ATR"
#define it_Auto467   "ATR"
#define es_Auto467   "ATR"
#define de_Auto467   "ATR"
#define nl_Auto467   "ATR"
#define pt_Auto467   "ATR"
#define xx_Auto467   "ATR"
#define en_Auto468   "ATR.DEFINE"
#define fr_Auto468   "ATR.DEFINE"
#define it_Auto468   "ATR.DEFINE"
#define es_Auto468   "ATR.DEFINE"
#define de_Auto468   "ATR.DEFINE"
#define nl_Auto468   "ATR.DEFINE"
#define pt_Auto468   "ATR.DEFINE"
#define xx_Auto468   "ATR.DEFINE"
#define en_Auto469   "ATR.INCLUDE"
#define fr_Auto469   "ATR.INCLUDE"
#define it_Auto469   "ATR.INCLUDE"
#define es_Auto469   "ATR.INCLUDE"
#define de_Auto469   "ATR.INCLUDE"
#define nl_Auto469   "ATR.INCLUDE"
#define pt_Auto469   "ATR.INCLUDE"
#define xx_Auto469   "ATR.INCLUDE"
#define en_Auto470   "ATR.OPTIONS"
#define fr_Auto470   "ATR.OPTIONS"
#define it_Auto470   "ATR.OPTIONS"
#define es_Auto470   "ATR.OPTIONS"
#define de_Auto470   "ATR.OPTIONS"
#define nl_Auto470   "ATR.OPTIONS"
#define pt_Auto470   "ATR.OPTIONS"
#define xx_Auto470   "ATR.OPTIONS"
#define en_Auto471   "ALD.INCLUDE"
#define fr_Auto471   "ALD.INCLUDE"
#define it_Auto471   "ALD.INCLUDE"
#define es_Auto471   "ALD.INCLUDE"
#define de_Auto471   "ALD.INCLUDE"
#define nl_Auto471   "ALD.INCLUDE"
#define pt_Auto471   "ALD.INCLUDE"
#define xx_Auto471   "ALD.INCLUDE"
#define en__Auto471   ""
#define fr__Auto471   ""
#define it__Auto471   ""
#define es__Auto471   ""
#define de__Auto471   ""
#define nl__Auto471   ""
#define pt__Auto471   ""
#define xx__Auto471   ""
#define en_Auto472   "ALD.OPTIONS"
#define fr_Auto472   "ALD.OPTIONS"
#define it_Auto472   "ALD.OPTIONS"
#define es_Auto472   "ALD.OPTIONS"
#define de_Auto472   "ALD.OPTIONS"
#define nl_Auto472   "ALD.OPTIONS"
#define pt_Auto472   "ALD.OPTIONS"
#define xx_Auto472   "ALD.OPTIONS"
#define en_Auto473   "ALD"
#define fr_Auto473   "ALD"
#define it_Auto473   "ALD"
#define es_Auto473   "ALD"
#define de_Auto473   "ALD"
#define nl_Auto473   "ALD"
#define pt_Auto473   "ALD"
#define xx_Auto473   "ALD"
#define en_ATR   ""
#define en__ATR   ""
#define en_ChoixATR   "..."
#define fr_ChoixATR   "..."
#define it_ChoixATR   "..."
#define es_ChoixATR   "..."
#define de_ChoixATR   "..."
#define nl_ChoixATR   "..."
#define pt_ChoixATR   "..."
#define xx_ChoixATR   "..."
#define en__ChoixATR   ""
#define fr__ChoixATR   ""
#define it__ChoixATR   ""
#define es__ChoixATR   ""
#define de__ChoixATR   ""
#define nl__ChoixATR   ""
#define pt__ChoixATR   ""
#define xx__ChoixATR   ""
#define en_ATR_DEFINE   ""
#define en__ATR_DEFINE   ""
#define en_ATR_INCLUDE   ""
#define en__ATR_INCLUDE   ""
#define en_ChoixATR_INCLUDE   "..."
#define fr_ChoixATR_INCLUDE   "..."
#define it_ChoixATR_INCLUDE   "..."
#define es_ChoixATR_INCLUDE   "..."
#define de_ChoixATR_INCLUDE   "..."
#define nl_ChoixATR_INCLUDE   "..."
#define pt_ChoixATR_INCLUDE   "..."
#define xx_ChoixATR_INCLUDE   "..."
#define en__ChoixATR_INCLUDE   ""
#define fr__ChoixATR_INCLUDE   ""
#define it__ChoixATR_INCLUDE   ""
#define es__ChoixATR_INCLUDE   ""
#define de__ChoixATR_INCLUDE   ""
#define nl__ChoixATR_INCLUDE   ""
#define pt__ChoixATR_INCLUDE   ""
#define xx__ChoixATR_INCLUDE   ""
#define en_ATR_OPTIONS   ""
#define en__ATR_OPTIONS   ""
#define en_ALD   ""
#define en__ALD   ""
#define en_ChoixALD   "..."
#define fr_ChoixALD   "..."
#define it_ChoixALD   "..."
#define es_ChoixALD   "..."
#define de_ChoixALD   "..."
#define nl_ChoixALD   "..."
#define pt_ChoixALD   "..."
#define xx_ChoixALD   "..."
#define en__ChoixALD   ""
#define fr__ChoixALD   ""
#define it__ChoixALD   ""
#define es__ChoixALD   ""
#define de__ChoixALD   ""
#define nl__ChoixALD   ""
#define pt__ChoixALD   ""
#define xx__ChoixALD   ""
#define en_ALD_INCLUDE   ""
#define en__ALD_INCLUDE   ""
#define en_ChoixALD_INCLUDE   "..."
#define fr_ChoixALD_INCLUDE   "..."
#define it_ChoixALD_INCLUDE   "..."
#define es_ChoixALD_INCLUDE   "..."
#define de_ChoixALD_INCLUDE   "..."
#define nl_ChoixALD_INCLUDE   "..."
#define pt_ChoixALD_INCLUDE   "..."
#define xx_ChoixALD_INCLUDE   "..."
#define en__ChoixALD_INCLUDE   ""
#define fr__ChoixALD_INCLUDE   ""
#define it__ChoixALD_INCLUDE   ""
#define es__ChoixALD_INCLUDE   ""
#define de__ChoixALD_INCLUDE   ""
#define nl__ChoixALD_INCLUDE   ""
#define pt__ChoixALD_INCLUDE   ""
#define xx__ChoixALD_INCLUDE   ""
#define en_ALD_OPTIONS   ""
#define en_Auto474   "ABAL++"
#define fr_Auto474   "ABAL++"
#define it_Auto474   "ABAL++"
#define es_Auto474   "ABAL++"
#define de_Auto474   "ABAL++"
#define nl_Auto474   "ABAL++"
#define pt_Auto474   "ABAL++"
#define xx_Auto474   "ABAL++"
#define en__Auto474   ""
#define en_Auto475   "ABAL and ABAL++"
#define fr_Auto475   "ABAL et ABAL++"
#define it_Auto475   "ABAL and ABAL++"
#define es_Auto475   "ABAL and ABAL++"
#define de_Auto475   "ABAL und ABAL++"
#define nl_Auto475   "ABAL and ABAL++"
#define pt_Auto475   "ABAL and ABAL++"
#define xx_Auto475   "ABAL and ABAL++"
#define en__Auto475   ""
#define en_Auto476   "OTR"
#define fr_Auto476   "OTR"
#define it_Auto476   "OTR"
#define es_Auto476   "OTR"
#define de_Auto476   "OTR"
#define nl_Auto476   "OTR"
#define pt_Auto476   "OTR"
#define xx_Auto476   "OTR"
#define en_Auto477   "OTR.DEFINE"
#define fr_Auto477   "OTR.DEFINE"
#define it_Auto477   "OTR.DEFINE"
#define es_Auto477   "OTR.DEFINE"
#define de_Auto477   "OTR.DEFINE"
#define nl_Auto477   "OTR.DEFINE"
#define pt_Auto477   "OTR.DEFINE"
#define xx_Auto477   "OTR.DEFINE"
#define en_Auto478   "OTR.INCLUDE"
#define fr_Auto478   "OTR.INCLUDE"
#define it_Auto478   "OTR.INCLUDE"
#define es_Auto478   "OTR.INCLUDE"
#define de_Auto478   "OTR.INCLUDE"
#define nl_Auto478   "OTR.INCLUDE"
#define pt_Auto478   "OTR.INCLUDE"
#define xx_Auto478   "OTR.INCLUDE"
#define en_Auto479   "OTR.OPTIONS"
#define fr_Auto479   "OTR.OPTIONS"
#define it_Auto479   "OTR.OPTIONS"
#define es_Auto479   "OTR.OPTIONS"
#define de_Auto479   "OTR.OPTIONS"
#define nl_Auto479   "OTR.OPTIONS"
#define pt_Auto479   "OTR.OPTIONS"
#define xx_Auto479   "OTR.OPTIONS"
#define en_Auto480   "OLD.INCLUDE"
#define fr_Auto480   "OLD.INCLUDE"
#define it_Auto480   "OLD.INCLUDE"
#define es_Auto480   "OLD.INCLUDE"
#define de_Auto480   "OLD.INCLUDE"
#define nl_Auto480   "OLD.INCLUDE"
#define pt_Auto480   "OLD.INCLUDE"
#define xx_Auto480   "OLD.INCLUDE"
#define en__Auto480   ""
#define fr__Auto480   ""
#define it__Auto480   ""
#define es__Auto480   ""
#define de__Auto480   ""
#define nl__Auto480   ""
#define pt__Auto480   ""
#define xx__Auto480   ""
#define en_Auto481   "OLD.OPTIONS"
#define fr_Auto481   "OLD.OPTIONS"
#define it_Auto481   "OLD.OPTIONS"
#define es_Auto481   "OLD.OPTIONS"
#define de_Auto481   "OLD.OPTIONS"
#define nl_Auto481   "OLD.OPTIONS"
#define pt_Auto481   "OLD.OPTIONS"
#define xx_Auto481   "OLD.OPTIONS"
#define en_Auto482   "OLD"
#define fr_Auto482   "OLD"
#define it_Auto482   "OLD"
#define es_Auto482   "OLD"
#define de_Auto482   "OLD"
#define nl_Auto482   "OLD"
#define pt_Auto482   "OLD"
#define xx_Auto482   "OLD"
#define en_Auto483   "EXA"
#define fr_Auto483   "EXA"
#define it_Auto483   "EXA"
#define es_Auto483   "EXA"
#define de_Auto483   "EXA"
#define nl_Auto483   "EXA"
#define pt_Auto483   "EXA"
#define xx_Auto483   "EXA"
#define en_Auto484   "EXADB"
#define fr_Auto484   "EXADB"
#define it_Auto484   "EXADB"
#define es_Auto484   "EXADB"
#define de_Auto484   "EXADB"
#define nl_Auto484   "EXADB"
#define pt_Auto484   "EXADB"
#define xx_Auto484   "EXADB"
#define en_OTR   ""
#define en__OTR   ""
#define en_ChoixOTR   "..."
#define fr_ChoixOTR   "..."
#define it_ChoixOTR   "..."
#define es_ChoixOTR   "..."
#define de_ChoixOTR   "..."
#define nl_ChoixOTR   "..."
#define pt_ChoixOTR   "..."
#define xx_ChoixOTR   "..."
#define en__ChoixOTR   ""
#define fr__ChoixOTR   ""
#define it__ChoixOTR   ""
#define es__ChoixOTR   ""
#define de__ChoixOTR   ""
#define nl__ChoixOTR   ""
#define pt__ChoixOTR   ""
#define xx__ChoixOTR   ""
#define en_OTR_DEFINE   ""
#define en__OTR_DEFINE   ""
#define en_OTR_INCLUDE   ""
#define en__OTR_INCLUDE   ""
#define en_ChoixOTR_INCLUDE   "..."
#define fr_ChoixOTR_INCLUDE   "..."
#define it_ChoixOTR_INCLUDE   "..."
#define es_ChoixOTR_INCLUDE   "..."
#define de_ChoixOTR_INCLUDE   "..."
#define nl_ChoixOTR_INCLUDE   "..."
#define pt_ChoixOTR_INCLUDE   "..."
#define xx_ChoixOTR_INCLUDE   "..."
#define en__ChoixOTR_INCLUDE   ""
#define fr__ChoixOTR_INCLUDE   ""
#define it__ChoixOTR_INCLUDE   ""
#define es__ChoixOTR_INCLUDE   ""
#define de__ChoixOTR_INCLUDE   ""
#define nl__ChoixOTR_INCLUDE   ""
#define pt__ChoixOTR_INCLUDE   ""
#define xx__ChoixOTR_INCLUDE   ""
#define en_OTR_OPTIONS   ""
#define en__OTR_OPTIONS   ""
#define en_OLD   ""
#define en__OLD   ""
#define en_ChoixOLD   "..."
#define fr_ChoixOLD   "..."
#define it_ChoixOLD   "..."
#define es_ChoixOLD   "..."
#define de_ChoixOLD   "..."
#define nl_ChoixOLD   "..."
#define pt_ChoixOLD   "..."
#define xx_ChoixOLD   "..."
#define en__ChoixOLD   ""
#define fr__ChoixOLD   ""
#define it__ChoixOLD   ""
#define es__ChoixOLD   ""
#define de__ChoixOLD   ""
#define nl__ChoixOLD   ""
#define pt__ChoixOLD   ""
#define xx__ChoixOLD   ""
#define en_OLD_INCLUDE   ""
#define en__OLD_INCLUDE   ""
#define en_ChoixOLD_INCLUDE   "..."
#define fr_ChoixOLD_INCLUDE   "..."
#define it_ChoixOLD_INCLUDE   "..."
#define es_ChoixOLD_INCLUDE   "..."
#define de_ChoixOLD_INCLUDE   "..."
#define nl_ChoixOLD_INCLUDE   "..."
#define pt_ChoixOLD_INCLUDE   "..."
#define xx_ChoixOLD_INCLUDE   "..."
#define en__ChoixOLD_INCLUDE   ""
#define fr__ChoixOLD_INCLUDE   ""
#define it__ChoixOLD_INCLUDE   ""
#define es__ChoixOLD_INCLUDE   ""
#define de__ChoixOLD_INCLUDE   ""
#define nl__ChoixOLD_INCLUDE   ""
#define pt__ChoixOLD_INCLUDE   ""
#define xx__ChoixOLD_INCLUDE   ""
#define en_OLD_OPTIONS   ""
#define en__OLD_OPTIONS   ""
#define en_EXA   ""
#define en__EXA   ""
#define en_ChoixEXA   "..."
#define fr_ChoixEXA   "..."
#define it_ChoixEXA   "..."
#define es_ChoixEXA   "..."
#define de_ChoixEXA   "..."
#define nl_ChoixEXA   "..."
#define pt_ChoixEXA   "..."
#define xx_ChoixEXA   "..."
#define en__ChoixEXA   ""
#define fr__ChoixEXA   ""
#define it__ChoixEXA   ""
#define es__ChoixEXA   ""
#define de__ChoixEXA   ""
#define nl__ChoixEXA   ""
#define pt__ChoixEXA   ""
#define xx__ChoixEXA   ""
#define en_EXADB   ""
#define en__EXADB   ""
#define en_ChoixEXADB   "..."
#define fr_ChoixEXADB   "..."
#define it_ChoixEXADB   "..."
#define es_ChoixEXADB   "..."
#define de_ChoixEXADB   "..."
#define nl_ChoixEXADB   "..."
#define pt_ChoixEXADB   "..."
#define xx_ChoixEXADB   "..."
#define en__ChoixEXADB   ""
#define fr__ChoixEXADB   ""
#define it__ChoixEXADB   ""
#define es__ChoixEXADB   ""
#define de__ChoixEXADB   ""
#define nl__ChoixEXADB   ""
#define pt__ChoixEXADB   ""
#define xx__ChoixEXADB   ""
#define en_Cpp   "&C++"
#define fr_Cpp   "&C++"
#define it_Cpp   "&C++"
#define es_Cpp   "&C++"
#define de_Cpp   "&C++"
#define nl_Cpp   "&C++"
#define pt_Cpp   "&C++"
#define xx_Cpp   "&C++"
#define en__Cpp   ""
#define fr__Cpp   ""
#define it__Cpp   ""
#define es__Cpp   ""
#define de__Cpp   ""
#define nl__Cpp   ""
#define pt__Cpp   ""
#define xx__Cpp   ""
#define en_Auto485   "C++"
#define fr_Auto485   "C++"
#define it_Auto485   "C++"
#define es_Auto485   "C++"
#define de_Auto485   "C++"
#define nl_Auto485   "C++"
#define pt_Auto485   "C++"
#define xx_Auto485   "C++"
#define en__Auto485   ""
#define fr__Auto485   ""
#define it__Auto485   ""
#define es__Auto485   ""
#define de__Auto485   ""
#define nl__Auto485   ""
#define pt__Auto485   ""
#define xx__Auto485   ""
#define en_Auto486   "C++"
#define fr_Auto486   "C++"
#define it_Auto486   "C++"
#define es_Auto486   "C++"
#define de_Auto486   "C++"
#define nl_Auto486   "C++"
#define pt_Auto486   "C++"
#define xx_Auto486   "C++"
#define en__Auto486   ""
#define fr__Auto486   ""
#define it__Auto486   ""
#define es__Auto486   ""
#define de__Auto486   ""
#define nl__Auto486   ""
#define pt__Auto486   ""
#define xx__Auto486   ""
#define en_Auto487   "C++.DEFINE"
#define fr_Auto487   "C++.DEFINE"
#define it_Auto487   "C++.DEFINE"
#define es_Auto487   "C++.DEFINE"
#define de_Auto487   "C++.DEFINE"
#define nl_Auto487   "C++.DEFINE"
#define pt_Auto487   "C++.DEFINE"
#define xx_Auto487   "C++.DEFINE"
#define en__Auto487   ""
#define fr__Auto487   ""
#define it__Auto487   ""
#define es__Auto487   ""
#define de__Auto487   ""
#define nl__Auto487   ""
#define pt__Auto487   ""
#define xx__Auto487   ""
#define en_Auto488   "C++.INCLUDE"
#define fr_Auto488   "C++.INCLUDE"
#define it_Auto488   "C++.INCLUDE"
#define es_Auto488   "C++.INCLUDE"
#define de_Auto488   "C++.INCLUDE"
#define nl_Auto488   "C++.INCLUDE"
#define pt_Auto488   "C++.INCLUDE"
#define xx_Auto488   "C++.INCLUDE"
#define en__Auto488   ""
#define fr__Auto488   ""
#define it__Auto488   ""
#define es__Auto488   ""
#define de__Auto488   ""
#define nl__Auto488   ""
#define pt__Auto488   ""
#define xx__Auto488   ""
#define en_Auto489   "C++.OPTIONS"
#define fr_Auto489   "C++.OPTIONS"
#define it_Auto489   "C++.OPTIONS"
#define es_Auto489   "C++.OPTIONS"
#define de_Auto489   "C++.OPTIONS"
#define nl_Auto489   "C++.OPTIONS"
#define pt_Auto489   "C++.OPTIONS"
#define xx_Auto489   "C++.OPTIONS"
#define en__Auto489   ""
#define fr__Auto489   ""
#define it__Auto489   ""
#define es__Auto489   ""
#define de__Auto489   ""
#define nl__Auto489   ""
#define pt__Auto489   ""
#define xx__Auto489   ""
#define en_Auto490   "LINK++.INCLUDE"
#define fr_Auto490   "LINK++.INCLUDE"
#define it_Auto490   "LINK++.INCLUDE"
#define es_Auto490   "LINK++.INCLUDE"
#define de_Auto490   "LINK++.INCLUDE"
#define nl_Auto490   "LINK++.INCLUDE"
#define pt_Auto490   "LINK++.INCLUDE"
#define xx_Auto490   "LINK++.INCLUDE"
#define en__Auto490   ""
#define fr__Auto490   ""
#define it__Auto490   ""
#define es__Auto490   ""
#define de__Auto490   ""
#define nl__Auto490   ""
#define pt__Auto490   ""
#define xx__Auto490   ""
#define en_Auto491   "LINK++"
#define fr_Auto491   "LINK++"
#define it_Auto491   "LINK++"
#define es_Auto491   "LINK++"
#define de_Auto491   "LINK++"
#define nl_Auto491   "LINK++"
#define pt_Auto491   "LINK++"
#define xx_Auto491   "LINK++"
#define en__Auto491   ""
#define fr__Auto491   ""
#define it__Auto491   ""
#define es__Auto491   ""
#define de__Auto491   ""
#define nl__Auto491   ""
#define pt__Auto491   ""
#define xx__Auto491   ""
#define en_Auto492   "LINK++.OPTIONS"
#define fr_Auto492   "LINK++.OPTIONS"
#define it_Auto492   "LINK++.OPTIONS"
#define es_Auto492   "LINK++.OPTIONS"
#define de_Auto492   "LINK++.OPTIONS"
#define nl_Auto492   "LINK++.OPTIONS"
#define pt_Auto492   "LINK++.OPTIONS"
#define xx_Auto492   "LINK++.OPTIONS"
#define en__Auto492   ""
#define fr__Auto492   ""
#define it__Auto492   ""
#define es__Auto492   ""
#define de__Auto492   ""
#define nl__Auto492   ""
#define pt__Auto492   ""
#define xx__Auto492   ""
#define en_Auto493   "LINK++.LIBRARY"
#define fr_Auto493   "LINK++.LIBRARY"
#define it_Auto493   "LINK++.LIBRARY"
#define es_Auto493   "LINK++.LIBRARY"
#define de_Auto493   "LINK++.LIBRARY"
#define nl_Auto493   "LINK++.LIBRARY"
#define pt_Auto493   "LINK++.LIBRARY"
#define xx_Auto493   "LINK++.LIBRARY"
#define en__Auto493   ""
#define fr__Auto493   ""
#define it__Auto493   ""
#define es__Auto493   ""
#define de__Auto493   ""
#define nl__Auto493   ""
#define pt__Auto493   ""
#define xx__Auto493   ""
#define en_CPP   ""
#define en__CPP   ""
#define en_ChoixCPP   "..."
#define fr_ChoixCPP   "..."
#define it_ChoixCPP   "..."
#define es_ChoixCPP   "..."
#define de_ChoixCPP   "..."
#define nl_ChoixCPP   "..."
#define pt_ChoixCPP   "..."
#define xx_ChoixCPP   "..."
#define en__ChoixCPP   ""
#define fr__ChoixCPP   ""
#define it__ChoixCPP   ""
#define es__ChoixCPP   ""
#define de__ChoixCPP   ""
#define nl__ChoixCPP   ""
#define pt__ChoixCPP   ""
#define xx__ChoixCPP   ""
#define en_CPP_DEFINE   ""
#define en__CPP_DEFINE   ""
#define en_CPP_INCLUDE   ""
#define en__CPP_INCLUDE   ""
#define en_ChoixCPP_INCLUDE   "..."
#define fr_ChoixCPP_INCLUDE   "..."
#define it_ChoixCPP_INCLUDE   "..."
#define es_ChoixCPP_INCLUDE   "..."
#define de_ChoixCPP_INCLUDE   "..."
#define nl_ChoixCPP_INCLUDE   "..."
#define pt_ChoixCPP_INCLUDE   "..."
#define xx_ChoixCPP_INCLUDE   "..."
#define en__ChoixCPP_INCLUDE   ""
#define fr__ChoixCPP_INCLUDE   ""
#define it__ChoixCPP_INCLUDE   ""
#define es__ChoixCPP_INCLUDE   ""
#define de__ChoixCPP_INCLUDE   ""
#define nl__ChoixCPP_INCLUDE   ""
#define pt__ChoixCPP_INCLUDE   ""
#define xx__ChoixCPP_INCLUDE   ""
#define en_CPP_OPTIONS   ""
#define en__CPP_OPTIONS   ""
#define en_LPP   ""
#define en__LPP   ""
#define en_ChoixLPP   "..."
#define fr_ChoixLPP   "..."
#define it_ChoixLPP   "..."
#define es_ChoixLPP   "..."
#define de_ChoixLPP   "..."
#define nl_ChoixLPP   "..."
#define pt_ChoixLPP   "..."
#define xx_ChoixLPP   "..."
#define en__ChoixLPP   ""
#define fr__ChoixLPP   ""
#define it__ChoixLPP   ""
#define es__ChoixLPP   ""
#define de__ChoixLPP   ""
#define nl__ChoixLPP   ""
#define pt__ChoixLPP   ""
#define xx__ChoixLPP   ""
#define en_LPP_INCLUDE   ""
#define en__LPP_INCLUDE   ""
#define en_ChoixLPP_INCLUDE   "..."
#define fr_ChoixLPP_INCLUDE   "..."
#define it_ChoixLPP_INCLUDE   "..."
#define es_ChoixLPP_INCLUDE   "..."
#define de_ChoixLPP_INCLUDE   "..."
#define nl_ChoixLPP_INCLUDE   "..."
#define pt_ChoixLPP_INCLUDE   "..."
#define xx_ChoixLPP_INCLUDE   "..."
#define en__ChoixLPP_INCLUDE   ""
#define fr__ChoixLPP_INCLUDE   ""
#define it__ChoixLPP_INCLUDE   ""
#define es__ChoixLPP_INCLUDE   ""
#define de__ChoixLPP_INCLUDE   ""
#define nl__ChoixLPP_INCLUDE   ""
#define pt__ChoixLPP_INCLUDE   ""
#define xx__ChoixLPP_INCLUDE   ""
#define en_LPP_OPTIONS   ""
#define en__LPP_OPTIONS   ""
#define en_LPP_LIBRARY   ""
#define en__LPP_LIBRARY   ""
#define en_Auto494   "Library C++"
#define fr_Auto494   "C++"
#define it_Auto494   "C++"
#define es_Auto494   "C++"
#define de_Auto494   "C++"
#define nl_Auto494   "C++"
#define pt_Auto494   "C++"
#define xx_Auto494   "C++"
#define en__Auto494   ""
#define fr__Auto494   ""
#define it__Auto494   ""
#define es__Auto494   ""
#define de__Auto494   ""
#define nl__Auto494   ""
#define pt__Auto494   ""
#define xx__Auto494   ""
#define en_Auto495   "C++"
#define fr_Auto495   "C++"
#define it_Auto495   "C++"
#define es_Auto495   "C++"
#define de_Auto495   "C++"
#define nl_Auto495   "C++"
#define pt_Auto495   "C++"
#define xx_Auto495   "C++"
#define en__Auto495   ""
#define fr__Auto495   ""
#define it__Auto495   ""
#define es__Auto495   ""
#define de__Auto495   ""
#define nl__Auto495   ""
#define pt__Auto495   ""
#define xx__Auto495   ""
#define en_Auto496   "C++.DEFINE"
#define fr_Auto496   "C++.DEFINE"
#define it_Auto496   "C++.DEFINE"
#define es_Auto496   "C++.DEFINE"
#define de_Auto496   "C++.DEFINE"
#define nl_Auto496   "C++.DEFINE"
#define pt_Auto496   "C++.DEFINE"
#define xx_Auto496   "C++.DEFINE"
#define en__Auto496   ""
#define fr__Auto496   ""
#define it__Auto496   ""
#define es__Auto496   ""
#define de__Auto496   ""
#define nl__Auto496   ""
#define pt__Auto496   ""
#define xx__Auto496   ""
#define en_Auto497   "C++.INCLUDE"
#define fr_Auto497   "C++.INCLUDE"
#define it_Auto497   "C++.INCLUDE"
#define es_Auto497   "C++.INCLUDE"
#define de_Auto497   "C++.INCLUDE"
#define nl_Auto497   "C++.INCLUDE"
#define pt_Auto497   "C++.INCLUDE"
#define xx_Auto497   "C++.INCLUDE"
#define en__Auto497   ""
#define fr__Auto497   ""
#define it__Auto497   ""
#define es__Auto497   ""
#define de__Auto497   ""
#define nl__Auto497   ""
#define pt__Auto497   ""
#define xx__Auto497   ""
#define en_Auto498   "C++.OPTIONS"
#define fr_Auto498   "C++.OPTIONS"
#define it_Auto498   "C++.OPTIONS"
#define es_Auto498   "C++.OPTIONS"
#define de_Auto498   "C++.OPTIONS"
#define nl_Auto498   "C++.OPTIONS"
#define pt_Auto498   "C++.OPTIONS"
#define xx_Auto498   "C++.OPTIONS"
#define en__Auto498   ""
#define fr__Auto498   ""
#define it__Auto498   ""
#define es__Auto498   ""
#define de__Auto498   ""
#define nl__Auto498   ""
#define pt__Auto498   ""
#define xx__Auto498   ""
#define en_Auto499   "LINK++.INCLUDE"
#define fr_Auto499   "LINK++.INCLUDE"
#define it_Auto499   "LINK++.INCLUDE"
#define es_Auto499   "LINK++.INCLUDE"
#define de_Auto499   "LINK++.INCLUDE"
#define nl_Auto499   "LINK++.INCLUDE"
#define pt_Auto499   "LINK++.INCLUDE"
#define xx_Auto499   "LINK++.INCLUDE"
#define en__Auto499   ""
#define fr__Auto499   ""
#define it__Auto499   ""
#define es__Auto499   ""
#define de__Auto499   ""
#define nl__Auto499   ""
#define pt__Auto499   ""
#define xx__Auto499   ""
#define en_Auto500   "LINK++"
#define fr_Auto500   "LINK++"
#define it_Auto500   "LINK++"
#define es_Auto500   "LINK++"
#define de_Auto500   "LINK++"
#define nl_Auto500   "LINK++"
#define pt_Auto500   "LINK++"
#define xx_Auto500   "LINK++"
#define en__Auto500   ""
#define fr__Auto500   ""
#define it__Auto500   ""
#define es__Auto500   ""
#define de__Auto500   ""
#define nl__Auto500   ""
#define pt__Auto500   ""
#define xx__Auto500   ""
#define en_Auto501   "LINK++.OPTIONS"
#define fr_Auto501   "LINK++.OPTIONS"
#define it_Auto501   "LINK++.OPTIONS"
#define es_Auto501   "LINK++.OPTIONS"
#define de_Auto501   "LINK++.OPTIONS"
#define nl_Auto501   "LINK++.OPTIONS"
#define pt_Auto501   "LINK++.OPTIONS"
#define xx_Auto501   "LINK++.OPTIONS"
#define en__Auto501   ""
#define fr__Auto501   ""
#define it__Auto501   ""
#define es__Auto501   ""
#define de__Auto501   ""
#define nl__Auto501   ""
#define pt__Auto501   ""
#define xx__Auto501   ""
#define en_Auto502   "LINK++.LIBRARY"
#define fr_Auto502   "LINK++.LIBRARY"
#define it_Auto502   "LINK++.LIBRARY"
#define es_Auto502   "LINK++.LIBRARY"
#define de_Auto502   "LINK++.LIBRARY"
#define nl_Auto502   "LINK++.LIBRARY"
#define pt_Auto502   "LINK++.LIBRARY"
#define xx_Auto502   "LINK++.LIBRARY"
#define en__Auto502   ""
#define fr__Auto502   ""
#define it__Auto502   ""
#define es__Auto502   ""
#define de__Auto502   ""
#define nl__Auto502   ""
#define pt__Auto502   ""
#define xx__Auto502   ""
#define en_DLLCPP   ""
#define en__DLLCPP   ""
#define en_ChoixDLLCPP   "..."
#define fr_ChoixDLLCPP   "..."
#define it_ChoixDLLCPP   "..."
#define es_ChoixDLLCPP   "..."
#define de_ChoixDLLCPP   "..."
#define nl_ChoixDLLCPP   "..."
#define pt_ChoixDLLCPP   "..."
#define xx_ChoixDLLCPP   "..."
#define en__ChoixDLLCPP   ""
#define fr__ChoixDLLCPP   ""
#define it__ChoixDLLCPP   ""
#define es__ChoixDLLCPP   ""
#define de__ChoixDLLCPP   ""
#define nl__ChoixDLLCPP   ""
#define pt__ChoixDLLCPP   ""
#define xx__ChoixDLLCPP   ""
#define en_DLLCPP_DEFINE   ""
#define en__DLLCPP_DEFINE   ""
#define en_DLLCPP_INCLUDE   ""
#define en__DLLCPP_INCLUDE   ""
#define en_ChoixDLLCPP_INCLUDE   "..."
#define fr_ChoixDLLCPP_INCLUDE   "..."
#define it_ChoixDLLCPP_INCLUDE   "..."
#define es_ChoixDLLCPP_INCLUDE   "..."
#define de_ChoixDLLCPP_INCLUDE   "..."
#define nl_ChoixDLLCPP_INCLUDE   "..."
#define pt_ChoixDLLCPP_INCLUDE   "..."
#define xx_ChoixDLLCPP_INCLUDE   "..."
#define en__ChoixDLLCPP_INCLUDE   ""
#define fr__ChoixDLLCPP_INCLUDE   ""
#define it__ChoixDLLCPP_INCLUDE   ""
#define es__ChoixDLLCPP_INCLUDE   ""
#define de__ChoixDLLCPP_INCLUDE   ""
#define nl__ChoixDLLCPP_INCLUDE   ""
#define pt__ChoixDLLCPP_INCLUDE   ""
#define xx__ChoixDLLCPP_INCLUDE   ""
#define en_DLLCPP_OPTIONS   ""
#define en__DLLCPP_OPTIONS   ""
#define en_DLLLPP   ""
#define en__DLLLPP   ""
#define en_ChoixDLLLPP   "..."
#define fr_ChoixDLLLPP   "..."
#define it_ChoixDLLLPP   "..."
#define es_ChoixDLLLPP   "..."
#define de_ChoixDLLLPP   "..."
#define nl_ChoixDLLLPP   "..."
#define pt_ChoixDLLLPP   "..."
#define xx_ChoixDLLLPP   "..."
#define en__ChoixDLLLPP   ""
#define fr__ChoixDLLLPP   ""
#define it__ChoixDLLLPP   ""
#define es__ChoixDLLLPP   ""
#define de__ChoixDLLLPP   ""
#define nl__ChoixDLLLPP   ""
#define pt__ChoixDLLLPP   ""
#define xx__ChoixDLLLPP   ""
#define en_DLLLPP_INCLUDE   ""
#define en__DLLLPP_INCLUDE   ""
#define en_ChoixDLLLPP_INCLUDE   "..."
#define fr_ChoixDLLLPP_INCLUDE   "..."
#define it_ChoixDLLLPP_INCLUDE   "..."
#define es_ChoixDLLLPP_INCLUDE   "..."
#define de_ChoixDLLLPP_INCLUDE   "..."
#define nl_ChoixDLLLPP_INCLUDE   "..."
#define pt_ChoixDLLLPP_INCLUDE   "..."
#define xx_ChoixDLLLPP_INCLUDE   "..."
#define en__ChoixDLLLPP_INCLUDE   ""
#define fr__ChoixDLLLPP_INCLUDE   ""
#define it__ChoixDLLLPP_INCLUDE   ""
#define es__ChoixDLLLPP_INCLUDE   ""
#define de__ChoixDLLLPP_INCLUDE   ""
#define nl__ChoixDLLLPP_INCLUDE   ""
#define pt__ChoixDLLLPP_INCLUDE   ""
#define xx__ChoixDLLLPP_INCLUDE   ""
#define en_DLLLPP_OPTIONS   ""
#define en__DLLLPP_OPTIONS   ""
#define en_DLLLPP_LIBRARY   ""
#define en__DLLLPP_LIBRARY   ""
#define en_Images   "&Images"
#define fr_Images   "&Images"
#define it_Images   "&Images"
#define es_Images   "&Images"
#define de_Images   "&Images"
#define nl_Images   "&Images"
#define pt_Images   "&Images"
#define xx_Images   "&Images"
#define en__Images   ""
#define en_Auto503   "IMAGEPATH"
#define fr_Auto503   "IMAGEPATH"
#define it_Auto503   "IMAGEPATH"
#define es_Auto503   "IMAGEPATH"
#define de_Auto503   "IMAGEPATH"
#define nl_Auto503   "IMAGEPATH"
#define pt_Auto503   "IMAGEPATH"
#define xx_Auto503   "IMAGEPATH"
#define en_IMAGEPATH   ""
#define en__IMAGEPATH   ""
#define en_ChoixIMAGEPATH   "..."
#define fr_ChoixIMAGEPATH   "..."
#define it_ChoixIMAGEPATH   "..."
#define es_ChoixIMAGEPATH   "..."
#define de_ChoixIMAGEPATH   "..."
#define nl_ChoixIMAGEPATH   "..."
#define pt_ChoixIMAGEPATH   "..."
#define xx_ChoixIMAGEPATH   "..."
#define en__ChoixIMAGEPATH   ""
#define fr__ChoixIMAGEPATH   ""
#define it__ChoixIMAGEPATH   ""
#define es__ChoixIMAGEPATH   ""
#define de__ChoixIMAGEPATH   ""
#define nl__ChoixIMAGEPATH   ""
#define pt__ChoixIMAGEPATH   ""
#define xx__ChoixIMAGEPATH   ""
#define en_Auto504   "ICONPATH"
#define fr_Auto504   "ICONPATH"
#define it_Auto504   "ICONPATH"
#define es_Auto504   "ICONPATH"
#define de_Auto504   "ICONPATH"
#define nl_Auto504   "ICONPATH"
#define pt_Auto504   "ICONPATH"
#define xx_Auto504   "ICONPATH"
#define en_Auto505   "PALETTE"
#define fr_Auto505   "PALETTE"
#define it_Auto505   "PALETTE"
#define es_Auto505   "PALETTE"
#define de_Auto505   "PALETTE"
#define nl_Auto505   "PALETTE"
#define pt_Auto505   "PALETTE"
#define xx_Auto505   "PALETTE"
#define en_Auto506   "SKIN"
#define fr_Auto506   "SKIN"
#define it_Auto506   "SKIN"
#define es_Auto506   "SKIN"
#define de_Auto506   "SKIN"
#define nl_Auto506   "SKIN"
#define pt_Auto506   "SKIN"
#define xx_Auto506   "SKIN"
#define en_Auto507   "TRIGGER.STYLE"
#define fr_Auto507   "TRIGGER.STYLE"
#define it_Auto507   "TRIGGER.STYLE"
#define es_Auto507   "TRIGGER.STYLE"
#define de_Auto507   "TRIGGER.STYLE"
#define nl_Auto507   "TRIGGER.STYLE"
#define pt_Auto507   "TRIGGER.STYLE"
#define xx_Auto507   "TRIGGER.STYLE"
#define en_Auto508   "STYLEPATH"
#define fr_Auto508   "STYLEPATH"
#define it_Auto508   "STYLEPATH"
#define es_Auto508   "STYLEPATH"
#define de_Auto508   "STYLEPATH"
#define nl_Auto508   "STYLEPATH"
#define pt_Auto508   "STYLEPATH"
#define xx_Auto508   "STYLEPATH"
#define en__Auto508   ""
#define fr__Auto508   ""
#define it__Auto508   ""
#define es__Auto508   ""
#define de__Auto508   ""
#define nl__Auto508   ""
#define pt__Auto508   ""
#define xx__Auto508   ""
#define en_Auto509   "COMPONENTPATH"
#define fr_Auto509   "COMPONENTPATH"
#define it_Auto509   "COMPONENTPATH"
#define es_Auto509   "COMPONENTPATH"
#define de_Auto509   "COMPONENTPATH"
#define nl_Auto509   "COMPONENTPATH"
#define pt_Auto509   "COMPONENTPATH"
#define xx_Auto509   "COMPONENTPATH"
#define en__Auto509   ""
#define fr__Auto509   ""
#define it__Auto509   ""
#define es__Auto509   ""
#define de__Auto509   ""
#define nl__Auto509   ""
#define pt__Auto509   ""
#define xx__Auto509   ""
#define en_Auto510   "TRIGGER.COLOUR"
#define fr_Auto510   "TRIGGER.COLOUR"
#define it_Auto510   "TRIGGER.COLOUR"
#define es_Auto510   "TRIGGER.COLOUR"
#define de_Auto510   "TRIGGER.COLOUR"
#define nl_Auto510   "TRIGGER.COLOUR"
#define pt_Auto510   "TRIGGER.COLOUR"
#define xx_Auto510   "TRIGGER.COLOUR"
#define en_ICONPATH   ""
#define en__ICONPATH   ""
#define en_ChoixICONPATH   "..."
#define fr_ChoixICONPATH   "..."
#define it_ChoixICONPATH   "..."
#define es_ChoixICONPATH   "..."
#define de_ChoixICONPATH   "..."
#define nl_ChoixICONPATH   "..."
#define pt_ChoixICONPATH   "..."
#define xx_ChoixICONPATH   "..."
#define en__ChoixICONPATH   ""
#define fr__ChoixICONPATH   ""
#define it__ChoixICONPATH   ""
#define es__ChoixICONPATH   ""
#define de__ChoixICONPATH   ""
#define nl__ChoixICONPATH   ""
#define pt__ChoixICONPATH   ""
#define xx__ChoixICONPATH   ""
#define en_PALETTE   ""
#define en__PALETTE   ""
#define en_ChoixPALETTE   "..."
#define fr_ChoixPALETTE   "..."
#define it_ChoixPALETTE   "..."
#define es_ChoixPALETTE   "..."
#define de_ChoixPALETTE   "..."
#define nl_ChoixPALETTE   "..."
#define pt_ChoixPALETTE   "..."
#define xx_ChoixPALETTE   "..."
#define en__ChoixPALETTE   ""
#define fr__ChoixPALETTE   ""
#define it__ChoixPALETTE   ""
#define es__ChoixPALETTE   ""
#define de__ChoixPALETTE   ""
#define nl__ChoixPALETTE   ""
#define pt__ChoixPALETTE   ""
#define xx__ChoixPALETTE   ""
#define en_SKIN   ""
#define en_TRIGGER_STYLE   "colour|bold|underline"
#define fr_TRIGGER_STYLE   "colour|bold|underline"
#define it_TRIGGER_STYLE   "colour|bold|underline"
#define es_TRIGGER_STYLE   "colour|bold|underline"
#define de_TRIGGER_STYLE   "colour|bold|underline"
#define nl_TRIGGER_STYLE   "colour|bold|underline"
#define pt_TRIGGER_STYLE   "colour|bold|underline"
#define xx_TRIGGER_STYLE   "colour|bold|underline"
#define en_STYLEPATH   ""
#define en__STYLEPATH   ""
#define en_COMPONENTPATH   ""
#define en__COMPONENTPATH   ""
#define en_ChoixSTYLEPATH   "..."
#define fr_ChoixSTYLEPATH   "..."
#define it_ChoixSTYLEPATH   "..."
#define es_ChoixSTYLEPATH   "..."
#define de_ChoixSTYLEPATH   "..."
#define nl_ChoixSTYLEPATH   "..."
#define pt_ChoixSTYLEPATH   "..."
#define xx_ChoixSTYLEPATH   "..."
#define en__ChoixSTYLEPATH   ""
#define fr__ChoixSTYLEPATH   ""
#define it__ChoixSTYLEPATH   ""
#define es__ChoixSTYLEPATH   ""
#define de__ChoixSTYLEPATH   ""
#define nl__ChoixSTYLEPATH   ""
#define pt__ChoixSTYLEPATH   ""
#define xx__ChoixSTYLEPATH   ""
#define en_ChoixCOMPPATH   "..."
#define fr_ChoixCOMPPATH   "..."
#define it_ChoixCOMPPATH   "..."
#define es_ChoixCOMPPATH   "..."
#define de_ChoixCOMPPATH   "..."
#define nl_ChoixCOMPPATH   "..."
#define pt_ChoixCOMPPATH   "..."
#define xx_ChoixCOMPPATH   "..."
#define en__ChoixCOMPPATH   ""
#define fr__ChoixCOMPPATH   ""
#define it__ChoixCOMPPATH   ""
#define es__ChoixCOMPPATH   ""
#define de__ChoixCOMPPATH   ""
#define nl__ChoixCOMPPATH   ""
#define pt__ChoixCOMPPATH   ""
#define xx__ChoixCOMPPATH   ""
#define en_Fonts   "&Fonts"
#define fr_Fonts   "P&olices"
#define it_Fonts   "&Fonts"
#define es_Fonts   "&Fonts"
#define de_Fonts   "&Fonts"
#define nl_Fonts   "&Fonts"
#define pt_Fonts   "&Fonts"
#define xx_Fonts   "&Fonts"
#define en__Fonts   ""
#define en_Auto511   "Font Labels and Filenames"
#define fr_Auto511   "Noms de Fichiers de polices de caractŠres"
#define it_Auto511   "Font Filenames"
#define es_Auto511   "Font Filenames"
#define de_Auto511   "Font Filenames"
#define nl_Auto511   "Font Filenames"
#define pt_Auto511   "Font Filenames"
#define xx_Auto511   "Font Filenames"
#define en__Auto511   ""
#define en_Auto512   "FONTPATH"
#define fr_Auto512   "FONTPATH"
#define it_Auto512   "FONTPATH"
#define es_Auto512   "FONTPATH"
#define de_Auto512   "FONTPATH"
#define nl_Auto512   "FONTPATH"
#define pt_Auto512   "FONTPATH"
#define xx_Auto512   "FONTPATH"
#define en_FONTPATH   ""
#define en__FONTPATH   ""
#define en_FONTLAB1   ""
#define en__FONTLAB1   ""
#define en_FONTLAB2   ""
#define en__FONTLAB2   ""
#define en_FONTLAB3   ""
#define en__FONTLAB3   ""
#define en_FONTLAB4   ""
#define en__FONTLAB4   ""
#define en_FONTLAB5   ""
#define en__FONTLAB5   ""
#define en_FONTLAB6   ""
#define en__FONTLAB6   ""
#define en_FONTLAB7   ""
#define en__FONTLAB7   ""
#define en_FONTLAB8   ""
#define en__FONTLAB8   ""
#define en_FONTLAB9   ""
#define en__FONTLAB9   ""
#define en_FONTLAB10   ""
#define en__FONTLAB10   ""
#define en_ChoixFONTPATH   "..."
#define fr_ChoixFONTPATH   "..."
#define it_ChoixFONTPATH   "..."
#define es_ChoixFONTPATH   "..."
#define de_ChoixFONTPATH   "..."
#define nl_ChoixFONTPATH   "..."
#define pt_ChoixFONTPATH   "..."
#define xx_ChoixFONTPATH   "..."
#define en__ChoixFONTPATH   ""
#define fr__ChoixFONTPATH   ""
#define it__ChoixFONTPATH   ""
#define es__ChoixFONTPATH   ""
#define de__ChoixFONTPATH   ""
#define nl__ChoixFONTPATH   ""
#define pt__ChoixFONTPATH   ""
#define xx__ChoixFONTPATH   ""
#define en_FONT1   ""
#define en__FONT1   ""
#define en_ChoixFONT1   "..."
#define fr_ChoixFONT1   "..."
#define it_ChoixFONT1   "..."
#define es_ChoixFONT1   "..."
#define de_ChoixFONT1   "..."
#define nl_ChoixFONT1   "..."
#define pt_ChoixFONT1   "..."
#define xx_ChoixFONT1   "..."
#define en__ChoixFONT1   ""
#define fr__ChoixFONT1   ""
#define it__ChoixFONT1   ""
#define es__ChoixFONT1   ""
#define de__ChoixFONT1   ""
#define nl__ChoixFONT1   ""
#define pt__ChoixFONT1   ""
#define xx__ChoixFONT1   ""
#define en_FONT2   ""
#define en__FONT2   ""
#define en_ChoixFONT2   "..."
#define fr_ChoixFONT2   "..."
#define it_ChoixFONT2   "..."
#define es_ChoixFONT2   "..."
#define de_ChoixFONT2   "..."
#define nl_ChoixFONT2   "..."
#define pt_ChoixFONT2   "..."
#define xx_ChoixFONT2   "..."
#define en__ChoixFONT2   ""
#define fr__ChoixFONT2   ""
#define it__ChoixFONT2   ""
#define es__ChoixFONT2   ""
#define de__ChoixFONT2   ""
#define nl__ChoixFONT2   ""
#define pt__ChoixFONT2   ""
#define xx__ChoixFONT2   ""
#define en_FONT3   ""
#define en__FONT3   ""
#define en_ChoixFONT3   "..."
#define fr_ChoixFONT3   "..."
#define it_ChoixFONT3   "..."
#define es_ChoixFONT3   "..."
#define de_ChoixFONT3   "..."
#define nl_ChoixFONT3   "..."
#define pt_ChoixFONT3   "..."
#define xx_ChoixFONT3   "..."
#define en__ChoixFONT3   ""
#define fr__ChoixFONT3   ""
#define it__ChoixFONT3   ""
#define es__ChoixFONT3   ""
#define de__ChoixFONT3   ""
#define nl__ChoixFONT3   ""
#define pt__ChoixFONT3   ""
#define xx__ChoixFONT3   ""
#define en_FONT4   ""
#define en__FONT4   ""
#define en_ChoixFONT4   "..."
#define fr_ChoixFONT4   "..."
#define it_ChoixFONT4   "..."
#define es_ChoixFONT4   "..."
#define de_ChoixFONT4   "..."
#define nl_ChoixFONT4   "..."
#define pt_ChoixFONT4   "..."
#define xx_ChoixFONT4   "..."
#define en__ChoixFONT4   ""
#define fr__ChoixFONT4   ""
#define it__ChoixFONT4   ""
#define es__ChoixFONT4   ""
#define de__ChoixFONT4   ""
#define nl__ChoixFONT4   ""
#define pt__ChoixFONT4   ""
#define xx__ChoixFONT4   ""
#define en_FONT5   ""
#define en__FONT5   ""
#define en_ChoixFONT5   "..."
#define fr_ChoixFONT5   "..."
#define it_ChoixFONT5   "..."
#define es_ChoixFONT5   "..."
#define de_ChoixFONT5   "..."
#define nl_ChoixFONT5   "..."
#define pt_ChoixFONT5   "..."
#define xx_ChoixFONT5   "..."
#define en__ChoixFONT5   ""
#define fr__ChoixFONT5   ""
#define it__ChoixFONT5   ""
#define es__ChoixFONT5   ""
#define de__ChoixFONT5   ""
#define nl__ChoixFONT5   ""
#define pt__ChoixFONT5   ""
#define xx__ChoixFONT5   ""
#define en_FONT6   ""
#define en__FONT6   ""
#define en_ChoixFONT6   "..."
#define fr_ChoixFONT6   "..."
#define it_ChoixFONT6   "..."
#define es_ChoixFONT6   "..."
#define de_ChoixFONT6   "..."
#define nl_ChoixFONT6   "..."
#define pt_ChoixFONT6   "..."
#define xx_ChoixFONT6   "..."
#define en__ChoixFONT6   ""
#define fr__ChoixFONT6   ""
#define it__ChoixFONT6   ""
#define es__ChoixFONT6   ""
#define de__ChoixFONT6   ""
#define nl__ChoixFONT6   ""
#define pt__ChoixFONT6   ""
#define xx__ChoixFONT6   ""
#define en_FONT7   ""
#define en__FONT7   ""
#define en_ChoixFONT7   "..."
#define fr_ChoixFONT7   "..."
#define it_ChoixFONT7   "..."
#define es_ChoixFONT7   "..."
#define de_ChoixFONT7   "..."
#define nl_ChoixFONT7   "..."
#define pt_ChoixFONT7   "..."
#define xx_ChoixFONT7   "..."
#define en__ChoixFONT7   ""
#define fr__ChoixFONT7   ""
#define it__ChoixFONT7   ""
#define es__ChoixFONT7   ""
#define de__ChoixFONT7   ""
#define nl__ChoixFONT7   ""
#define pt__ChoixFONT7   ""
#define xx__ChoixFONT7   ""
#define en_FONT8   ""
#define en__FONT8   ""
#define en_ChoixFONT8   "..."
#define fr_ChoixFONT8   "..."
#define it_ChoixFONT8   "..."
#define es_ChoixFONT8   "..."
#define de_ChoixFONT8   "..."
#define nl_ChoixFONT8   "..."
#define pt_ChoixFONT8   "..."
#define xx_ChoixFONT8   "..."
#define en__ChoixFONT8   ""
#define fr__ChoixFONT8   ""
#define it__ChoixFONT8   ""
#define es__ChoixFONT8   ""
#define de__ChoixFONT8   ""
#define nl__ChoixFONT8   ""
#define pt__ChoixFONT8   ""
#define xx__ChoixFONT8   ""
#define en_FONT9   ""
#define en__FONT9   ""
#define en_ChoixFONT9   "..."
#define fr_ChoixFONT9   "..."
#define it_ChoixFONT9   "..."
#define es_ChoixFONT9   "..."
#define de_ChoixFONT9   "..."
#define nl_ChoixFONT9   "..."
#define pt_ChoixFONT9   "..."
#define xx_ChoixFONT9   "..."
#define en__ChoixFONT9   ""
#define fr__ChoixFONT9   ""
#define it__ChoixFONT9   ""
#define es__ChoixFONT9   ""
#define de__ChoixFONT9   ""
#define nl__ChoixFONT9   ""
#define pt__ChoixFONT9   ""
#define xx__ChoixFONT9   ""
#define en_FONT10   ""
#define en__FONT10   ""
#define en_ChoixFONT10   "..."
#define fr_ChoixFONT10   "..."
#define it_ChoixFONT10   "..."
#define es_ChoixFONT10   "..."
#define de_ChoixFONT10   "..."
#define nl_ChoixFONT10   "..."
#define pt_ChoixFONT10   "..."
#define xx_ChoixFONT10   "..."
#define en__ChoixFONT10   ""
#define fr__ChoixFONT10   ""
#define it__ChoixFONT10   ""
#define es__ChoixFONT10   ""
#define de__ChoixFONT10   ""
#define nl__ChoixFONT10   ""
#define pt__ChoixFONT10   ""
#define xx__ChoixFONT10   ""
#define en_Documents   "&Documents"
#define fr_Documents   "&Documents"
#define it_Documents   "&Documents"
#define es_Documents   "&Documents"
#define de_Documents   "&Documents"
#define nl_Documents   "&Documents"
#define pt_Documents   "&Documents"
#define xx_Documents   "&Documents"
#define en__Documents   ""
#define en_Auto513   "Html Document Parameters"
#define fr_Auto513   "ParamŠtres des documents Html"
#define it_Auto513   "Html Document Parameters"
#define es_Auto513   "Html Document Parameters"
#define de_Auto513   "Html Document Parameters"
#define nl_Auto513   "Html Document Parameters"
#define pt_Auto513   "Html Document Parameters"
#define xx_Auto513   "Html Document Parameters"
#define en__Auto513   ""
#define en_Auto514   "HTML.TITLE"
#define fr_Auto514   "HTML.TITLE"
#define it_Auto514   "HTML.TITLE"
#define es_Auto514   "HTML.TITLE"
#define de_Auto514   "HTML.TITLE"
#define nl_Auto514   "HTML.TITLE"
#define pt_Auto514   "HTML.TITLE"
#define xx_Auto514   "HTML.TITLE"
#define en_Auto515   "HTML.LOGO"
#define fr_Auto515   "HTML.LOGO"
#define it_Auto515   "HTML.LOGO"
#define es_Auto515   "HTML.LOGO"
#define de_Auto515   "HTML.LOGO"
#define nl_Auto515   "HTML.LOGO"
#define pt_Auto515   "HTML.LOGO"
#define xx_Auto515   "HTML.LOGO"
#define en_Auto516   "COPYRIGHT"
#define fr_Auto516   "COPYRIGHT"
#define it_Auto516   "COPYRIGHT"
#define es_Auto516   "COPYRIGHT"
#define de_Auto516   "COPYRIGHT"
#define nl_Auto516   "COPYRIGHT"
#define pt_Auto516   "COPYRIGHT"
#define xx_Auto516   "COPYRIGHT"
#define en_Auto517   "SCREEN.CSS"
#define fr_Auto517   "SCREEN.CSS"
#define it_Auto517   "SCREEN.CSS"
#define es_Auto517   "SCREEN.CSS"
#define de_Auto517   "SCREEN.CSS"
#define nl_Auto517   "SCREEN.CSS"
#define pt_Auto517   "SCREEN.CSS"
#define xx_Auto517   "SCREEN.CSS"
#define en_Auto518   "PRINT.CSS"
#define fr_Auto518   "PRINT.CSS"
#define it_Auto518   "PRINT.CSS"
#define es_Auto518   "PRINT.CSS"
#define de_Auto518   "PRINT.CSS"
#define nl_Auto518   "PRINT.CSS"
#define pt_Auto518   "PRINT.CSS"
#define xx_Auto518   "PRINT.CSS"
#define en_Auto519   "NAVIGATOR"
#define fr_Auto519   "NAVIGATOR"
#define it_Auto519   "NAVIGATOR"
#define es_Auto519   "NAVIGATOR"
#define de_Auto519   "NAVIGATOR"
#define nl_Auto519   "NAVIGATOR"
#define pt_Auto519   "NAVIGATOR"
#define xx_Auto519   "NAVIGATOR"
#define en_Auto520   "DOCPATH"
#define fr_Auto520   "DOCPATH"
#define it_Auto520   "DOCPATH"
#define es_Auto520   "DOCPATH"
#define de_Auto520   "DOCPATH"
#define nl_Auto520   "DOCPATH"
#define pt_Auto520   "DOCPATH"
#define xx_Auto520   "DOCPATH"
#define en_HTML_TITLE   ""
#define en__HTML_TITLE   ""
#define en_HTML_LOGO   ""
#define en__HTML_LOGO   ""
#define en_HTML_COPYRIGHT   ""
#define en__HTML_COPYRIGHT   ""
#define en_SCREEN_CSS   ""
#define en__SCREEN_CSS   ""
#define en_ChoixSCREEN_CSS   "..."
#define fr_ChoixSCREEN_CSS   "..."
#define it_ChoixSCREEN_CSS   "..."
#define es_ChoixSCREEN_CSS   "..."
#define de_ChoixSCREEN_CSS   "..."
#define nl_ChoixSCREEN_CSS   "..."
#define pt_ChoixSCREEN_CSS   "..."
#define xx_ChoixSCREEN_CSS   "..."
#define en__ChoixSCREEN_CSS   ""
#define fr__ChoixSCREEN_CSS   ""
#define it__ChoixSCREEN_CSS   ""
#define es__ChoixSCREEN_CSS   ""
#define de__ChoixSCREEN_CSS   ""
#define nl__ChoixSCREEN_CSS   ""
#define pt__ChoixSCREEN_CSS   ""
#define xx__ChoixSCREEN_CSS   ""
#define en_PRINT_CSS   ""
#define en__PRINT_CSS   ""
#define en_ChoixPRINT_CSS   "..."
#define fr_ChoixPRINT_CSS   "..."
#define it_ChoixPRINT_CSS   "..."
#define es_ChoixPRINT_CSS   "..."
#define de_ChoixPRINT_CSS   "..."
#define nl_ChoixPRINT_CSS   "..."
#define pt_ChoixPRINT_CSS   "..."
#define xx_ChoixPRINT_CSS   "..."
#define en__ChoixPRINT_CSS   ""
#define fr__ChoixPRINT_CSS   ""
#define it__ChoixPRINT_CSS   ""
#define es__ChoixPRINT_CSS   ""
#define de__ChoixPRINT_CSS   ""
#define nl__ChoixPRINT_CSS   ""
#define pt__ChoixPRINT_CSS   ""
#define xx__ChoixPRINT_CSS   ""
#define en_NAVIGATOR   ""
#define en__NAVIGATOR   ""
#define en_ChoixNAVIGATOR   "..."
#define fr_ChoixNAVIGATOR   "..."
#define it_ChoixNAVIGATOR   "..."
#define es_ChoixNAVIGATOR   "..."
#define de_ChoixNAVIGATOR   "..."
#define nl_ChoixNAVIGATOR   "..."
#define pt_ChoixNAVIGATOR   "..."
#define xx_ChoixNAVIGATOR   "..."
#define en__ChoixNAVIGATOR   ""
#define fr__ChoixNAVIGATOR   ""
#define it__ChoixNAVIGATOR   ""
#define es__ChoixNAVIGATOR   ""
#define de__ChoixNAVIGATOR   ""
#define nl__ChoixNAVIGATOR   ""
#define pt__ChoixNAVIGATOR   ""
#define xx__ChoixNAVIGATOR   ""
#define en_DOCPATH   ""
#define en__DOCPATH   ""
#define en_ChoixDOCPATH   "..."
#define fr_ChoixDOCPATH   "..."
#define it_ChoixDOCPATH   "..."
#define es_ChoixDOCPATH   "..."
#define de_ChoixDOCPATH   "..."
#define nl_ChoixDOCPATH   "..."
#define pt_ChoixDOCPATH   "..."
#define xx_ChoixDOCPATH   "..."
#define en__ChoixDOCPATH   ""
#define fr__ChoixDOCPATH   ""
#define it__ChoixDOCPATH   ""
#define es__ChoixDOCPATH   ""
#define de__ChoixDOCPATH   ""
#define nl__ChoixDOCPATH   ""
#define pt__ChoixDOCPATH   ""
#define xx__ChoixDOCPATH   ""
#define en_Printing   "&Printing"
#define fr_Printing   "I&mpression"
#define it_Printing   "&Printing"
#define es_Printing   "&Printing"
#define de_Printing   "&Printing"
#define nl_Printing   "&Printing"
#define pt_Printing   "&Printing"
#define xx_Printing   "&Printing"
#define en__Printing   ""
#define en_Auto521   "PRINTER"
#define fr_Auto521   "PRINTER"
#define it_Auto521   "PRINTER"
#define es_Auto521   "PRINTER"
#define de_Auto521   "PRINTER"
#define nl_Auto521   "PRINTER"
#define pt_Auto521   "PRINTER"
#define xx_Auto521   "PRINTER"
#define en_Auto522   "RESOLUTION"
#define fr_Auto522   "RESOLUTION"
#define it_Auto522   "RESOLUTION"
#define es_Auto522   "RESOLUTION"
#define de_Auto522   "RESOLUTION"
#define nl_Auto522   "RESOLUTION"
#define pt_Auto522   "RESOLUTION"
#define xx_Auto522   "RESOLUTION"
#define en__Auto522   ""
#define en_Auto523   "PAPERTYPE"
#define fr_Auto523   "PAPERTYPE"
#define it_Auto523   "PAPERTYPE"
#define es_Auto523   "PAPERTYPE"
#define de_Auto523   "PAPERTYPE"
#define nl_Auto523   "PAPERTYPE"
#define pt_Auto523   "PAPERTYPE"
#define xx_Auto523   "PAPERTYPE"
#define en__Auto523   ""
#define en_Auto524   "LAYOUT"
#define fr_Auto524   "LAYOUT"
#define it_Auto524   "LAYOUT"
#define es_Auto524   "LAYOUT"
#define de_Auto524   "LAYOUT"
#define nl_Auto524   "LAYOUT"
#define pt_Auto524   "LAYOUT"
#define xx_Auto524   "LAYOUT"
#define en__Auto524   ""
#define en_Auto525   "PAGEFEED"
#define fr_Auto525   "PAGEFEED"
#define it_Auto525   "PAGEFEED"
#define es_Auto525   "PAGEFEED"
#define de_Auto525   "PAGEFEED"
#define nl_Auto525   "PAGEFEED"
#define pt_Auto525   "PAGEFEED"
#define xx_Auto525   "PAGEFEED"
#define en__Auto525   ""
#define en_PRINTER   ""
#define en__PRINTER   ""
#define en_ChoixPRINTER   "..."
#define fr_ChoixPRINTER   "..."
#define it_ChoixPRINTER   "..."
#define es_ChoixPRINTER   "..."
#define de_ChoixPRINTER   "..."
#define nl_ChoixPRINTER   "..."
#define pt_ChoixPRINTER   "..."
#define xx_ChoixPRINTER   "..."
#define en__ChoixPRINTER   ""
#define fr__ChoixPRINTER   ""
#define it__ChoixPRINTER   ""
#define es__ChoixPRINTER   ""
#define de__ChoixPRINTER   ""
#define nl__ChoixPRINTER   ""
#define pt__ChoixPRINTER   ""
#define xx__ChoixPRINTER   ""
#define en__PAPERTYPE   ""
#define en_LAYOUT   "Portrait|Landscape"
#define fr_LAYOUT   "Portrait|Landscape"
#define it_LAYOUT   "Portrait|Landscape"
#define es_LAYOUT   "Portrait|Landscape"
#define de_LAYOUT   "Portrait|Landscape"
#define nl_LAYOUT   "Portrait|Landscape"
#define pt_LAYOUT   "Portrait|Landscape"
#define xx_LAYOUT   "Portrait|Landscape"
#define en__LAYOUT   ""
#define en_PAGEFEED   "None|Before|After"
#define fr_PAGEFEED   "None|Before|After"
#define it_PAGEFEED   "None|Before|After"
#define es_PAGEFEED   "None|Before|After"
#define de_PAGEFEED   "None|Before|After"
#define nl_PAGEFEED   "None|Before|After"
#define pt_PAGEFEED   "None|Before|After"
#define xx_PAGEFEED   "None|Before|After"
#define en__PAGEFEED   ""
#define en__RESOLUTION   ""
#define en_Editor   "&Editor"
#define fr_Editor   "&Editeur"
#define it_Editor   "&Editor"
#define es_Editor   "&Editor"
#define de_Editor   "&Editor"
#define nl_Editor   "&Editor"
#define pt_Editor   "&Editor"
#define xx_Editor   "&Editor"
#define en__Editor   ""
#define en_Auto526   "AED"
#define fr_Auto526   "AED"
#define it_Auto526   "AED"
#define es_Auto526   "AED"
#define de_Auto526   "AED"
#define nl_Auto526   "AED"
#define pt_Auto526   "AED"
#define xx_Auto526   "AED"
#define en_Auto527   "AED.FONT"
#define fr_Auto527   "AED.FONT"
#define it_Auto527   "AED.FONT"
#define es_Auto527   "AED.FONT"
#define de_Auto527   "AED.FONT"
#define nl_Auto527   "AED.FONT"
#define pt_Auto527   "AED.FONT"
#define xx_Auto527   "AED.FONT"
#define en_Auto528   "Editor Syntaxical Colours"
#define fr_Auto528   "Couloration syntaxique de l'‚diteur"
#define it_Auto528   "Editor Syntaxical Colours"
#define es_Auto528   "Editor Syntaxical Colours"
#define de_Auto528   "Editor Syntaxical Colours"
#define nl_Auto528   "Editor Syntaxical Colours"
#define pt_Auto528   "Editor Syntaxical Colours"
#define xx_Auto528   "Editor Syntaxical Colours"
#define en__Auto528   ""
#define en_AED   ""
#define en_ChoixAED   "..."
#define fr_ChoixAED   "..."
#define it_ChoixAED   "..."
#define es_ChoixAED   "..."
#define de_ChoixAED   "..."
#define nl_ChoixAED   "..."
#define pt_ChoixAED   "..."
#define xx_ChoixAED   "..."
#define en__ChoixAED   ""
#define fr__ChoixAED   ""
#define it__ChoixAED   ""
#define es__ChoixAED   ""
#define de__ChoixAED   ""
#define nl__ChoixAED   ""
#define pt__ChoixAED   ""
#define xx__ChoixAED   ""
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
#define it_ACCEPT   "&Accept"
#define es_ACCEPT   "&Accept"
#define de_ACCEPT   "&Accept"
#define nl_ACCEPT   "&Accept"
#define pt_ACCEPT   "&Accept"
#define xx_ACCEPT   "&Accept"
#define en_SAVEFILE   "&Save File"
#define fr_SAVEFILE   "E&crire Fichier"
#define it_SAVEFILE   "&SaveFile"
#define es_SAVEFILE   "&SaveFile"
#define de_SAVEFILE   "&SaveFile"
#define nl_SAVEFILE   "&SaveFile"
#define pt_SAVEFILE   "&SaveFile"
#define xx_SAVEFILE   "&SaveFile"
#define en__SAVEFILE   ""
#define en__SAVELDAP   ""
#define fr__SAVELDAP   ""
#define it__SAVELDAP   ""
#define es__SAVELDAP   ""
#define de__SAVELDAP   ""
#define nl__SAVELDAP   ""
#define pt__SAVELDAP   ""
#define xx__SAVELDAP   ""
#define en__LoadLdap   ""
#define fr__LoadLdap   ""
#define it__LoadLdap   ""
#define es__LoadLdap   ""
#define de__LoadLdap   ""
#define nl__LoadLdap   ""
#define pt__LoadLdap   ""
#define xx__LoadLdap   ""
#define en_EDITFILE   "Edi&t File"
#define fr_EDITFILE   "Edi&teur"
#define it_EDITFILE   "Edi&tFile"
#define es_EDITFILE   "Edi&tFile"
#define de_EDITFILE   "Edi&tFile"
#define nl_EDITFILE   "Edi&tFile"
#define pt_EDITFILE   "Edi&tFile"
#define xx_EDITFILE   "Edi&tFile"
#define en__EDITFILE   ""
#define fr__EDITFILE   ""
#define en_DELETE   "&Delete"
#define fr_DELETE   "&Suprimer"
#define it_DELETE   "&Delete"
#define es_DELETE   "&Delete"
#define de_DELETE   "&Delete"
#define nl_DELETE   "&Delete"
#define pt_DELETE   "&Delete"
#define xx_DELETE   "&Delete"
#define fr__DELETE   ""
#define en_LOADFILE   "&Load File"
#define fr_LOADFILE   "&Lire Fichier"
#define it_LOADFILE   "&LoadFile"
#define es_LOADFILE   "&LoadFile"
#define de_LOADFILE   "&LoadFile"
#define nl_LOADFILE   "&LoadFile"
#define pt_LOADFILE   "&LoadFile"
#define xx_LOADFILE   "&LoadFile"
#define en__LOADFILE   ""
#define fr__LOADFILE   ""
#define it__LOADFILE   ""
#define es__LOADFILE   ""
#define de__LOADFILE   ""
#define nl__LOADFILE   ""
#define pt__LOADFILE   ""
#define xx__LOADFILE   ""
#define en_CANCEL   "&Cancel"
#define fr_CANCEL   "A&nnuler"
#define it_CANCEL   "&Cancel"
#define es_CANCEL   "&Cancel"
#define de_CANCEL   "&Cancel"
#define nl_CANCEL   "&Cancel"
#define pt_CANCEL   "&Cancel"
#define xx_CANCEL   "&Cancel"
#define en_Project   "&Project"
#define fr_Project   "&Projet"
#define it_Project   "&Project"
#define es_Project   "&Project"
#define de_Project   "&Project"
#define nl_Project   "&Project"
#define pt_Project   "&Project"
#define xx_Project   "&Project"
#define en__Project   ""
#define en_Auto529   "AMAKE"
#define fr_Auto529   "AMAKE"
#define it_Auto529   "AMAKE"
#define es_Auto529   "AMAKE"
#define de_Auto529   "AMAKE"
#define nl_Auto529   "AMAKE"
#define pt_Auto529   "AMAKE"
#define xx_Auto529   "AMAKE"
#define en_Auto530   "AMAKE.OPTIONS"
#define fr_Auto530   "AMAKE.OPTIONS"
#define it_Auto530   "AMAKE.OPTIONS"
#define es_Auto530   "AMAKE.OPTIONS"
#define de_Auto530   "AMAKE.OPTIONS"
#define nl_Auto530   "AMAKE.OPTIONS"
#define pt_Auto530   "AMAKE.OPTIONS"
#define xx_Auto530   "AMAKE.OPTIONS"
#define en_Auto531   "AMAKE.DEFINE"
#define fr_Auto531   "AMAKE.DEFINE"
#define it_Auto531   "AMAKE.DEFINE"
#define es_Auto531   "AMAKE.DEFINE"
#define de_Auto531   "AMAKE.DEFINE"
#define nl_Auto531   "AMAKE.DEFINE"
#define pt_Auto531   "AMAKE.DEFINE"
#define xx_Auto531   "AMAKE.DEFINE"
#define en_Auto532   "AMAKE.LIST"
#define fr_Auto532   "AMAKE.LIST"
#define it_Auto532   "AMAKE.LIST"
#define es_Auto532   "AMAKE.LIST"
#define de_Auto532   "AMAKE.LIST"
#define nl_Auto532   "AMAKE.LIST"
#define pt_Auto532   "AMAKE.LIST"
#define xx_Auto532   "AMAKE.LIST"
#define en_AMAKE   ""
#define en__AMAKE   ""
#define en_choixAMAKE   "..."
#define fr_choixAMAKE   "..."
#define it_choixAMAKE   "..."
#define es_choixAMAKE   "..."
#define de_choixAMAKE   "..."
#define nl_choixAMAKE   "..."
#define pt_choixAMAKE   "..."
#define xx_choixAMAKE   "..."
#define en__choixAMAKE   ""
#define en_AMAKE_OPTIONS   ""
#define en__AMAKE_OPTIONS   ""
#define en_AMAKE_DEFINE   ""
#define en__AMAKE_DEFINE   ""
#define en_AMAKE_LIST   ""
#define en__AMAKE_LIST   ""
#define en_choixAMAKE_LIST   "..."
#define fr_choixAMAKE_LIST   "..."
#define it_choixAMAKE_LIST   "..."
#define es_choixAMAKE_LIST   "..."
#define de_choixAMAKE_LIST   "..."
#define nl_choixAMAKE_LIST   "..."
#define pt_choixAMAKE_LIST   "..."
#define xx_choixAMAKE_LIST   "..."
#define en__choixAMAKE_LIST   ""
#define fr__choixAMAKE_LIST   ""
#define it__choixAMAKE_LIST   ""
#define es__choixAMAKE_LIST   ""
#define de__choixAMAKE_LIST   ""
#define nl__choixAMAKE_LIST   ""
#define pt__choixAMAKE_LIST   ""
#define xx__choixAMAKE_LIST   ""

private struct accept_configuration_context {
	int	status;
	int	keycode;
	int	focus_item;
	int	focus_items;
	int	window_col;
	int	window_row;
	int	language;
	int	focus_pages[9+1];
	char * msg_Auto459[8];
	char * hint_Auto459[8];
	int	x_Auto459;
	int	y_Auto459;
	int	w_Auto459;
	int	h_Auto459;
	char * msg_General[8];
	int	trigger_General;
	char * hint_General[8];
	int	page_number;
	char * msg_Auto460[8];
	char * hint_Auto460[8];
	char * hint_FILENAME[8];
	char	buffer_FILENAME[260];
	char * msg_ChoixFILENAME[8];
	int	trigger_ChoixFILENAME;
	char * hint_ChoixFILENAME[8];
	char * hint_ABALHOST[8];
	char	buffer_ABALHOST[256];
	char * msg_Auto461[8];
	char * hint_Auto461[8];
	char * msg_Auto462[8];
	char * hint_Auto462[8];
	char * msg_Auto463[8];
	char * hint_Auto463[8];
	char * msg_Auto464[8];
	char * hint_Auto464[8];
	char * msg_Auto465[8];
	char * hint_Auto465[8];
	char * hint_IDENTITY[8];
	char	buffer_IDENTITY[256];
	char * hint_REPLAY[8];
	char	buffer_REPLAY[256];
	char * hint_RECORD[8];
	char	buffer_RECORD[256];
	char * msg_Abal[8];
	int	trigger_Abal;
	char * hint_Abal[8];
	char * msg_Auto466[8];
	char * hint_Auto466[8];
	char * msg_Auto467[8];
	char * hint_Auto467[8];
	char * msg_Auto468[8];
	char * hint_Auto468[8];
	char * msg_Auto469[8];
	char * hint_Auto469[8];
	char * msg_Auto470[8];
	char * hint_Auto470[8];
	char * msg_Auto471[8];
	char * hint_Auto471[8];
	char * msg_Auto472[8];
	char * hint_Auto472[8];
	char * msg_Auto473[8];
	char * hint_Auto473[8];
	char * hint_ATR[8];
	char	buffer_ATR[256];
	char * msg_ChoixATR[8];
	int	trigger_ChoixATR;
	char * hint_ChoixATR[8];
	char * hint_ATR_DEFINE[8];
	char	buffer_ATR_DEFINE[256];
	char * hint_ATR_INCLUDE[8];
	char	buffer_ATR_INCLUDE[1025];
	char * msg_ChoixATR_INCLUDE[8];
	int	trigger_ChoixATR_INCLUDE;
	char * hint_ChoixATR_INCLUDE[8];
	char * hint_ATR_OPTIONS[8];
	char	buffer_ATR_OPTIONS[256];
	char * hint_ALD[8];
	char	buffer_ALD[256];
	char * msg_ChoixALD[8];
	int	trigger_ChoixALD;
	char * hint_ChoixALD[8];
	char * hint_ALD_INCLUDE[8];
	char	buffer_ALD_INCLUDE[256];
	char * msg_ChoixALD_INCLUDE[8];
	int	trigger_ChoixALD_INCLUDE;
	char * hint_ChoixALD_INCLUDE[8];
	char * hint_ALD_OPTIONS[8];
	char	buffer_ALD_OPTIONS[256];
	char * msg_Auto474[8];
	char * hint_Auto474[8];
	char * msg_Auto475[8];
	char * hint_Auto475[8];
	char * msg_Auto476[8];
	char * hint_Auto476[8];
	char * msg_Auto477[8];
	char * hint_Auto477[8];
	char * msg_Auto478[8];
	char * hint_Auto478[8];
	char * msg_Auto479[8];
	char * hint_Auto479[8];
	char * msg_Auto480[8];
	char * hint_Auto480[8];
	char * msg_Auto481[8];
	char * hint_Auto481[8];
	char * msg_Auto482[8];
	char * hint_Auto482[8];
	char * msg_Auto483[8];
	char * hint_Auto483[8];
	char * msg_Auto484[8];
	char * hint_Auto484[8];
	char * hint_OTR[8];
	char	buffer_OTR[256];
	char * msg_ChoixOTR[8];
	int	trigger_ChoixOTR;
	char * hint_ChoixOTR[8];
	char * hint_OTR_DEFINE[8];
	char	buffer_OTR_DEFINE[256];
	char * hint_OTR_INCLUDE[8];
	char	buffer_OTR_INCLUDE[256];
	char * msg_ChoixOTR_INCLUDE[8];
	int	trigger_ChoixOTR_INCLUDE;
	char * hint_ChoixOTR_INCLUDE[8];
	char * hint_OTR_OPTIONS[8];
	char	buffer_OTR_OPTIONS[256];
	char * hint_OLD[8];
	char	buffer_OLD[256];
	char * msg_ChoixOLD[8];
	int	trigger_ChoixOLD;
	char * hint_ChoixOLD[8];
	char * hint_OLD_INCLUDE[8];
	char	buffer_OLD_INCLUDE[256];
	char * msg_ChoixOLD_INCLUDE[8];
	int	trigger_ChoixOLD_INCLUDE;
	char * hint_ChoixOLD_INCLUDE[8];
	char * hint_OLD_OPTIONS[8];
	char	buffer_OLD_OPTIONS[256];
	char * hint_EXA[8];
	char	buffer_EXA[256];
	char * msg_ChoixEXA[8];
	int	trigger_ChoixEXA;
	char * hint_ChoixEXA[8];
	char * hint_EXADB[8];
	char	buffer_EXADB[256];
	char * msg_ChoixEXADB[8];
	int	trigger_ChoixEXADB;
	char * hint_ChoixEXADB[8];
	char * msg_Cpp[8];
	int	trigger_Cpp;
	char * hint_Cpp[8];
	char * msg_Auto485[8];
	char * hint_Auto485[8];
	char * msg_Auto486[8];
	char * hint_Auto486[8];
	char * msg_Auto487[8];
	char * hint_Auto487[8];
	char * msg_Auto488[8];
	char * hint_Auto488[8];
	char * msg_Auto489[8];
	char * hint_Auto489[8];
	char * msg_Auto490[8];
	char * hint_Auto490[8];
	char * msg_Auto491[8];
	char * hint_Auto491[8];
	char * msg_Auto492[8];
	char * hint_Auto492[8];
	char * msg_Auto493[8];
	char * hint_Auto493[8];
	char * hint_CPP[8];
	char	buffer_CPP[256];
	char * msg_ChoixCPP[8];
	int	trigger_ChoixCPP;
	char * hint_ChoixCPP[8];
	char * hint_CPP_DEFINE[8];
	char	buffer_CPP_DEFINE[256];
	char * hint_CPP_INCLUDE[8];
	char	buffer_CPP_INCLUDE[1025];
	char * msg_ChoixCPP_INCLUDE[8];
	int	trigger_ChoixCPP_INCLUDE;
	char * hint_ChoixCPP_INCLUDE[8];
	char * hint_CPP_OPTIONS[8];
	char	buffer_CPP_OPTIONS[256];
	char * hint_LPP[8];
	char	buffer_LPP[256];
	char * msg_ChoixLPP[8];
	int	trigger_ChoixLPP;
	char * hint_ChoixLPP[8];
	char * hint_LPP_INCLUDE[8];
	char	buffer_LPP_INCLUDE[256];
	char * msg_ChoixLPP_INCLUDE[8];
	int	trigger_ChoixLPP_INCLUDE;
	char * hint_ChoixLPP_INCLUDE[8];
	char * hint_LPP_OPTIONS[8];
	char	buffer_LPP_OPTIONS[256];
	char * hint_LPP_LIBRARY[8];
	char	buffer_LPP_LIBRARY[256];
	char * msg_Auto494[8];
	char * hint_Auto494[8];
	char * msg_Auto495[8];
	char * hint_Auto495[8];
	char * msg_Auto496[8];
	char * hint_Auto496[8];
	char * msg_Auto497[8];
	char * hint_Auto497[8];
	char * msg_Auto498[8];
	char * hint_Auto498[8];
	char * msg_Auto499[8];
	char * hint_Auto499[8];
	char * msg_Auto500[8];
	char * hint_Auto500[8];
	char * msg_Auto501[8];
	char * hint_Auto501[8];
	char * msg_Auto502[8];
	char * hint_Auto502[8];
	char * hint_DLLCPP[8];
	char	buffer_DLLCPP[256];
	char * msg_ChoixDLLCPP[8];
	int	trigger_ChoixDLLCPP;
	char * hint_ChoixDLLCPP[8];
	char * hint_DLLCPP_DEFINE[8];
	char	buffer_DLLCPP_DEFINE[256];
	char * hint_DLLCPP_INCLUDE[8];
	char	buffer_DLLCPP_INCLUDE[1025];
	char * msg_ChoixDLLCPP_INCLUDE[8];
	int	trigger_ChoixDLLCPP_INCLUDE;
	char * hint_ChoixDLLCPP_INCLUDE[8];
	char * hint_DLLCPP_OPTIONS[8];
	char	buffer_DLLCPP_OPTIONS[256];
	char * hint_DLLLPP[8];
	char	buffer_DLLLPP[256];
	char * msg_ChoixDLLLPP[8];
	int	trigger_ChoixDLLLPP;
	char * hint_ChoixDLLLPP[8];
	char * hint_DLLLPP_INCLUDE[8];
	char	buffer_DLLLPP_INCLUDE[256];
	char * msg_ChoixDLLLPP_INCLUDE[8];
	int	trigger_ChoixDLLLPP_INCLUDE;
	char * hint_ChoixDLLLPP_INCLUDE[8];
	char * hint_DLLLPP_OPTIONS[8];
	char	buffer_DLLLPP_OPTIONS[256];
	char * hint_DLLLPP_LIBRARY[8];
	char	buffer_DLLLPP_LIBRARY[256];
	char * msg_Images[8];
	int	trigger_Images;
	char * hint_Images[8];
	char * msg_Auto503[8];
	char * hint_Auto503[8];
	char * hint_IMAGEPATH[8];
	char	buffer_IMAGEPATH[256];
	char * msg_ChoixIMAGEPATH[8];
	int	trigger_ChoixIMAGEPATH;
	char * hint_ChoixIMAGEPATH[8];
	char * msg_Auto504[8];
	char * hint_Auto504[8];
	char * msg_Auto505[8];
	char * hint_Auto505[8];
	char * msg_Auto506[8];
	char * hint_Auto506[8];
	char * msg_Auto507[8];
	char * hint_Auto507[8];
	char * msg_Auto508[8];
	char * hint_Auto508[8];
	char * msg_Auto509[8];
	char * hint_Auto509[8];
	char * msg_Auto510[8];
	char * hint_Auto510[8];
	char * hint_ICONPATH[8];
	char	buffer_ICONPATH[256];
	char * msg_ChoixICONPATH[8];
	int	trigger_ChoixICONPATH;
	char * hint_ChoixICONPATH[8];
	char * hint_PALETTE[8];
	char	buffer_PALETTE[256];
	char * msg_ChoixPALETTE[8];
	int	trigger_ChoixPALETTE;
	char * hint_ChoixPALETTE[8];
	char * hint_SKIN[8];
	char	buffer_SKIN[256];
	char * msg_TRIGGER_STYLE[8];
	char * hint_TRIGGER_STYLE[8];
	int	value_TRIGGER_STYLE;
	char * hint_TRIGGER_COLOUR[8];
	char	buffer_TRIGGER_COLOUR[12];
	char * hint_STYLEPATH[8];
	char	buffer_STYLEPATH[256];
	char * hint_COMPONENTPATH[8];
	char	buffer_COMPONENTPATH[256];
	char * msg_ChoixSTYLEPATH[8];
	int	trigger_ChoixSTYLEPATH;
	char * hint_ChoixSTYLEPATH[8];
	char * msg_ChoixCOMPPATH[8];
	int	trigger_ChoixCOMPPATH;
	char * hint_ChoixCOMPPATH[8];
	char * msg_Fonts[8];
	int	trigger_Fonts;
	char * hint_Fonts[8];
	char * msg_Auto511[8];
	char * hint_Auto511[8];
	char * msg_Auto512[8];
	char * hint_Auto512[8];
	char * hint_FONTPATH[8];
	char	buffer_FONTPATH[256];
	char * hint_FONTLAB1[8];
	char	buffer_FONTLAB1[33];
	char * hint_FONTLAB2[8];
	char	buffer_FONTLAB2[33];
	char * hint_FONTLAB3[8];
	char	buffer_FONTLAB3[33];
	char * hint_FONTLAB4[8];
	char	buffer_FONTLAB4[33];
	char * hint_FONTLAB5[8];
	char	buffer_FONTLAB5[33];
	char * hint_FONTLAB6[8];
	char	buffer_FONTLAB6[33];
	char * hint_FONTLAB7[8];
	char	buffer_FONTLAB7[33];
	char * hint_FONTLAB8[8];
	char	buffer_FONTLAB8[33];
	char * hint_FONTLAB9[8];
	char	buffer_FONTLAB9[33];
	char * hint_FONTLAB10[8];
	char	buffer_FONTLAB10[33];
	char * msg_ChoixFONTPATH[8];
	int	trigger_ChoixFONTPATH;
	char * hint_ChoixFONTPATH[8];
	char * hint_FONT1[8];
	char	buffer_FONT1[260];
	char * msg_ChoixFONT1[8];
	int	trigger_ChoixFONT1;
	char * hint_ChoixFONT1[8];
	char * hint_FONT2[8];
	char	buffer_FONT2[260];
	char * msg_ChoixFONT2[8];
	int	trigger_ChoixFONT2;
	char * hint_ChoixFONT2[8];
	char * hint_FONT3[8];
	char	buffer_FONT3[260];
	char * msg_ChoixFONT3[8];
	int	trigger_ChoixFONT3;
	char * hint_ChoixFONT3[8];
	char * hint_FONT4[8];
	char	buffer_FONT4[260];
	char * msg_ChoixFONT4[8];
	int	trigger_ChoixFONT4;
	char * hint_ChoixFONT4[8];
	char * hint_FONT5[8];
	char	buffer_FONT5[260];
	char * msg_ChoixFONT5[8];
	int	trigger_ChoixFONT5;
	char * hint_ChoixFONT5[8];
	char * hint_FONT6[8];
	char	buffer_FONT6[260];
	char * msg_ChoixFONT6[8];
	int	trigger_ChoixFONT6;
	char * hint_ChoixFONT6[8];
	char * hint_FONT7[8];
	char	buffer_FONT7[260];
	char * msg_ChoixFONT7[8];
	int	trigger_ChoixFONT7;
	char * hint_ChoixFONT7[8];
	char * hint_FONT8[8];
	char	buffer_FONT8[260];
	char * msg_ChoixFONT8[8];
	int	trigger_ChoixFONT8;
	char * hint_ChoixFONT8[8];
	char * hint_FONT9[8];
	char	buffer_FONT9[260];
	char * msg_ChoixFONT9[8];
	int	trigger_ChoixFONT9;
	char * hint_ChoixFONT9[8];
	char * hint_FONT10[8];
	char	buffer_FONT10[260];
	char * msg_ChoixFONT10[8];
	int	trigger_ChoixFONT10;
	char * hint_ChoixFONT10[8];
	char * msg_Documents[8];
	int	trigger_Documents;
	char * hint_Documents[8];
	char * msg_Auto513[8];
	char * hint_Auto513[8];
	char * msg_Auto514[8];
	char * hint_Auto514[8];
	char * msg_Auto515[8];
	char * hint_Auto515[8];
	char * msg_Auto516[8];
	char * hint_Auto516[8];
	char * msg_Auto517[8];
	char * hint_Auto517[8];
	char * msg_Auto518[8];
	char * hint_Auto518[8];
	char * msg_Auto519[8];
	char * hint_Auto519[8];
	char * msg_Auto520[8];
	char * hint_Auto520[8];
	char * hint_HTML_TITLE[8];
	char	buffer_HTML_TITLE[67];
	char * hint_HTML_LOGO[8];
	char	buffer_HTML_LOGO[67];
	char * hint_HTML_COPYRIGHT[8];
	char	buffer_HTML_COPYRIGHT[67];
	char * hint_SCREEN_CSS[8];
	char	buffer_SCREEN_CSS[260];
	char * msg_ChoixSCREEN_CSS[8];
	int	trigger_ChoixSCREEN_CSS;
	char * hint_ChoixSCREEN_CSS[8];
	char * hint_PRINT_CSS[8];
	char	buffer_PRINT_CSS[260];
	char * msg_ChoixPRINT_CSS[8];
	int	trigger_ChoixPRINT_CSS;
	char * hint_ChoixPRINT_CSS[8];
	char * hint_NAVIGATOR[8];
	char	buffer_NAVIGATOR[256];
	char * msg_ChoixNAVIGATOR[8];
	int	trigger_ChoixNAVIGATOR;
	char * hint_ChoixNAVIGATOR[8];
	char * hint_DOCPATH[8];
	char	buffer_DOCPATH[256];
	char * msg_ChoixDOCPATH[8];
	int	trigger_ChoixDOCPATH;
	char * hint_ChoixDOCPATH[8];
	char * msg_Printing[8];
	int	trigger_Printing;
	char * hint_Printing[8];
	char * msg_Auto521[8];
	char * hint_Auto521[8];
	char * msg_Auto522[8];
	char * hint_Auto522[8];
	char * msg_Auto523[8];
	char * hint_Auto523[8];
	char * msg_Auto524[8];
	char * hint_Auto524[8];
	char * msg_Auto525[8];
	char * hint_Auto525[8];
	char * hint_PRINTER[8];
	char	buffer_PRINTER[260];
	char * msg_ChoixPRINTER[8];
	int	trigger_ChoixPRINTER;
	char * hint_ChoixPRINTER[8];
	char * msg_PAPERTYPE[8];
	char * hint_PAPERTYPE[8];
	int	value_PAPERTYPE;
	char * msg_LAYOUT[8];
	char * hint_LAYOUT[8];
	int	value_LAYOUT;
	char * msg_PAGEFEED[8];
	char * hint_PAGEFEED[8];
	int	value_PAGEFEED;
	char * msg_RESOLUTION[8];
	char * hint_RESOLUTION[8];
	int	value_RESOLUTION;
	char * msg_Editor[8];
	int	trigger_Editor;
	char * hint_Editor[8];
	char * msg_Auto526[8];
	char * hint_Auto526[8];
	char * msg_Auto527[8];
	char * hint_Auto527[8];
	char * msg_Auto528[8];
	char * hint_Auto528[8];
	char * hint_AED[8];
	char	buffer_AED[256];
	char * msg_ChoixAED[8];
	int	trigger_ChoixAED;
	char * hint_ChoixAED[8];
	char * msg_AED_FONT[8];
	char * hint_AED_FONT[8];
	int	value_AED_FONT;
	char * msg_AED_STATE[8];
	int	trigger_AED_STATE;
	char * hint_AED_STATE[8];
	int	value_AED_STATE;
	char * msg_AED_SYNTAX[8];
	int	trigger_AED_SYNTAX;
	char * hint_AED_SYNTAX[8];
	int	value_AED_SYNTAX;
	char * msg_auto6060[8];
	char * hint_auto6060[8];
	char * msg_auto6061[8];
	char * hint_auto6061[8];
	char * msg_auto6062[8];
	char * hint_auto6062[8];
	char * msg_auto6063[8];
	char * hint_auto6063[8];
	char * msg_auto6064[8];
	char * hint_auto6064[8];
	char * msg_AED_NORMAL[8];
	char * hint_AED_NORMAL[8];
	int	value_AED_NORMAL;
	char * msg_AED_QUOTE[8];
	char * hint_AED_QUOTE[8];
	int	value_AED_QUOTE;
	char * msg_AED_COMMENT[8];
	char * hint_AED_COMMENT[8];
	int	value_AED_COMMENT;
	char * msg_AED_KEYWORD[8];
	char * hint_AED_KEYWORD[8];
	int	value_AED_KEYWORD;
	char * msg_AED_PUNCTUATE[8];
	char * hint_AED_PUNCTUATE[8];
	int	value_AED_PUNCTUATE;
	char * msg_ACCEPT[8];
	int	trigger_ACCEPT;
	char * hint_ACCEPT[8];
	char * msg_SAVEFILE[8];
	int	trigger_SAVEFILE;
	char * hint_SAVEFILE[8];
	char * msg_SAVELDAP[8];
	int	trigger_SAVELDAP;
	char * hint_SAVELDAP[8];
	char * msg_LoadLdap[8];
	int	trigger_LoadLdap;
	char * hint_LoadLdap[8];
	char * msg_EDITFILE[8];
	int	trigger_EDITFILE;
	char * hint_EDITFILE[8];
	char * msg_DELETE[8];
	int	trigger_DELETE;
	char * hint_DELETE[8];
	char * msg_LOADFILE[8];
	int	trigger_LOADFILE;
	char * hint_LOADFILE[8];
	char * msg_CANCEL[8];
	int	trigger_CANCEL;
	char * hint_CANCEL[8];
	char * msg_Project[8];
	int	trigger_Project;
	char * hint_Project[8];
	char * msg_Auto529[8];
	char * hint_Auto529[8];
	char * msg_Auto530[8];
	char * hint_Auto530[8];
	char * msg_Auto531[8];
	char * hint_Auto531[8];
	char * msg_Auto532[8];
	char * hint_Auto532[8];
	char * hint_AMAKE[8];
	char	buffer_AMAKE[256];
	char * msg_choixAMAKE[8];
	int	trigger_choixAMAKE;
	char * hint_choixAMAKE[8];
	char * hint_AMAKE_OPTIONS[8];
	char	buffer_AMAKE_OPTIONS[256];
	char * hint_AMAKE_DEFINE[8];
	char	buffer_AMAKE_DEFINE[256];
	char * hint_AMAKE_LIST[8];
	char	buffer_AMAKE_LIST[256];
	char * msg_choixAMAKE_LIST[8];
	int	trigger_choixAMAKE_LIST;
	char * hint_choixAMAKE_LIST[8];
	int	ctrlbuffer;
	void * pushbuffer;
	char	signature[82];
	};
static int	vfh[16];

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
	char * pALD_INCLUDE,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_INCLUDE,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pCPP,
	char * pCPP_DEFINE,
	char * pCPP_INCLUDE,
	char * pCPP_OPTIONS,
	char * pLPP,
	char * pLPP_INCLUDE,
	char * pLPP_OPTIONS,
	char * pLPP_LIBRARY,
	char * pDLLCPP,
	char * pDLLCPP_DEFINE,
	char * pDLLCPP_INCLUDE,
	char * pDLLCPP_OPTIONS,
	char * pDLLLPP,
	char * pDLLLPP_INCLUDE,
	char * pDLLLPP_OPTIONS,
	char * pDLLLPP_LIBRARY,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pSTYLEPATH,
	char * pCOMPONENTPATH,
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
	char * pAED_COMMENT,
	char * pAED_KEYWORD,
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
	vfh[6] = visual_font("arial6.fmf",10);
	vfh[7] = visual_font("font7.fmf",9);
	vfh[8] = visual_font("font8.fmf",9);
	vfh[9] = visual_font("font9.fmf",9);
	vfh[10] = visual_font("font10.fmf",10);
	if (!(_Context = allocate( sizeof( struct accept_configuration_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=152;
	_Context->page_number=1;
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB1+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB2+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB3+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB4+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB5+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB6+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB7+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB8+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB9+i)=' ';
		for (i=0; i < 32; i++)  *(_Context->buffer_FONTLAB10+i)=' ';
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferin(_Context->buffer_FILENAME, 259, pFILENAME);
		visual_transferin(_Context->buffer_ABALHOST, 255, pABALHOST);
		visual_transferin(_Context->buffer_IDENTITY, 255, pIDENTITY);
		visual_transferin(_Context->buffer_REPLAY, 255, pREPLAY);
		visual_transferin(_Context->buffer_RECORD, 255, pRECORD);
		visual_transferin(_Context->buffer_ATR, 255, pATR);
		visual_transferin(_Context->buffer_ATR_DEFINE, 255, pATR_DEFINE);
		visual_transferin(_Context->buffer_ATR_INCLUDE, 1024, pATR_INCLUDE);
		visual_transferin(_Context->buffer_ATR_OPTIONS, 255, pATR_OPTIONS);
		visual_transferin(_Context->buffer_ALD, 255, pALD);
		visual_transferin(_Context->buffer_ALD_INCLUDE, 255, pALD_INCLUDE);
		visual_transferin(_Context->buffer_ALD_OPTIONS, 255, pALD_OPTIONS);
		visual_transferin(_Context->buffer_OTR, 255, pOTR);
		visual_transferin(_Context->buffer_OTR_DEFINE, 255, pOTR_DEFINE);
		visual_transferin(_Context->buffer_OTR_INCLUDE, 255, pOTR_INCLUDE);
		visual_transferin(_Context->buffer_OTR_OPTIONS, 255, pOTR_OPTIONS);
		visual_transferin(_Context->buffer_OLD, 255, pOLD);
		visual_transferin(_Context->buffer_OLD_INCLUDE, 255, pOLD_INCLUDE);
		visual_transferin(_Context->buffer_OLD_OPTIONS, 255, pOLD_OPTIONS);
		visual_transferin(_Context->buffer_EXA, 255, pEXA);
		visual_transferin(_Context->buffer_EXADB, 255, pEXADB);
		visual_transferin(_Context->buffer_CPP, 255, pCPP);
		visual_transferin(_Context->buffer_CPP_DEFINE, 255, pCPP_DEFINE);
		visual_transferin(_Context->buffer_CPP_INCLUDE, 1024, pCPP_INCLUDE);
		visual_transferin(_Context->buffer_CPP_OPTIONS, 255, pCPP_OPTIONS);
		visual_transferin(_Context->buffer_LPP, 255, pLPP);
		visual_transferin(_Context->buffer_LPP_INCLUDE, 255, pLPP_INCLUDE);
		visual_transferin(_Context->buffer_LPP_OPTIONS, 255, pLPP_OPTIONS);
		visual_transferin(_Context->buffer_LPP_LIBRARY, 255, pLPP_LIBRARY);
		visual_transferin(_Context->buffer_DLLCPP, 255, pDLLCPP);
		visual_transferin(_Context->buffer_DLLCPP_DEFINE, 255, pDLLCPP_DEFINE);
		visual_transferin(_Context->buffer_DLLCPP_INCLUDE, 1024, pDLLCPP_INCLUDE);
		visual_transferin(_Context->buffer_DLLCPP_OPTIONS, 255, pDLLCPP_OPTIONS);
		visual_transferin(_Context->buffer_DLLLPP, 255, pDLLLPP);
		visual_transferin(_Context->buffer_DLLLPP_INCLUDE, 255, pDLLLPP_INCLUDE);
		visual_transferin(_Context->buffer_DLLLPP_OPTIONS, 255, pDLLLPP_OPTIONS);
		visual_transferin(_Context->buffer_DLLLPP_LIBRARY, 255, pDLLLPP_LIBRARY);
		visual_transferin(_Context->buffer_IMAGEPATH, 255, pIMAGEPATH);
		visual_transferin(_Context->buffer_ICONPATH, 255, pICONPATH);
		visual_transferin(_Context->buffer_PALETTE, 255, pPALETTE);
		visual_transferin(_Context->buffer_SKIN, 255, pSKIN);
		visual_transferin((void *) 0, 0, pTRIGGER_STYLE);
		if (!( pTRIGGER_STYLE )) _Context->value_TRIGGER_STYLE=0;
		else	_Context->value_TRIGGER_STYLE = *((int *)pTRIGGER_STYLE);
		visual_transferin(_Context->buffer_TRIGGER_COLOUR, 11, pTRIGGER_COLOUR);
		visual_transferin(_Context->buffer_STYLEPATH, 255, pSTYLEPATH);
		visual_transferin(_Context->buffer_COMPONENTPATH, 255, pCOMPONENTPATH);
		visual_transferin(_Context->buffer_FONTPATH, 255, pFONTPATH);
		visual_transferin(_Context->buffer_FONT1, 259, pFONT1);
		visual_transferin(_Context->buffer_FONT2, 259, pFONT2);
		visual_transferin(_Context->buffer_FONT3, 259, pFONT3);
		visual_transferin(_Context->buffer_FONT4, 259, pFONT4);
		visual_transferin(_Context->buffer_FONT5, 259, pFONT5);
		visual_transferin(_Context->buffer_FONT6, 259, pFONT6);
		visual_transferin(_Context->buffer_FONT7, 259, pFONT7);
		visual_transferin(_Context->buffer_FONT8, 259, pFONT8);
		visual_transferin(_Context->buffer_FONT9, 259, pFONT9);
		visual_transferin(_Context->buffer_FONT10, 259, pFONT10);
		visual_transferin(_Context->buffer_HTML_TITLE, 66, pHTML_TITLE);
		visual_transferin(_Context->buffer_HTML_LOGO, 66, pHTML_LOGO);
		visual_transferin(_Context->buffer_HTML_COPYRIGHT, 66, pHTML_COPYRIGHT);
		visual_transferin(_Context->buffer_SCREEN_CSS, 259, pSCREEN_CSS);
		visual_transferin(_Context->buffer_PRINT_CSS, 259, pPRINT_CSS);
		visual_transferin(_Context->buffer_NAVIGATOR, 255, pNAVIGATOR);
		visual_transferin(_Context->buffer_DOCPATH, 255, pDOCPATH);
		visual_transferin(_Context->buffer_PRINTER, 259, pPRINTER);
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
		visual_transferin(_Context->buffer_AED, 255, pAED);
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
		visual_transferin((void *) 0, 0, pAED_COMMENT);
		if (!( pAED_COMMENT )) _Context->value_AED_COMMENT=0;
		else	_Context->value_AED_COMMENT = *((int *)pAED_COMMENT);
		visual_transferin((void *) 0, 0, pAED_KEYWORD);
		if (!( pAED_KEYWORD )) _Context->value_AED_KEYWORD=0;
		else	_Context->value_AED_KEYWORD = *((int *)pAED_KEYWORD);
		visual_transferin((void *) 0, 0, pAED_PUNCTUATE);
		if (!( pAED_PUNCTUATE )) _Context->value_AED_PUNCTUATE=0;
		else	_Context->value_AED_PUNCTUATE = *((int *)pAED_PUNCTUATE);
		visual_transferin(_Context->buffer_AMAKE, 255, pAMAKE);
		visual_transferin(_Context->buffer_AMAKE_OPTIONS, 255, pAMAKE_OPTIONS);
		visual_transferin(_Context->buffer_AMAKE_DEFINE, 255, pAMAKE_DEFINE);
		visual_transferin(_Context->buffer_AMAKE_LIST, 255, pAMAKE_LIST);
		}
	for (i=0; i < 8; i++)_Context->msg_Auto459[i]=" ";
	_Context->hint_Auto459[0]=en__Auto459;
	_Context->hint_Auto459[1]=fr__Auto459;
	_Context->hint_Auto459[2]=it__Auto459;
	_Context->hint_Auto459[3]=es__Auto459;
	_Context->hint_Auto459[4]=de__Auto459;
	_Context->hint_Auto459[5]=nl__Auto459;
	_Context->hint_Auto459[6]=pt__Auto459;
	_Context->hint_Auto459[7]=xx__Auto459;
	_Context->x_Auto459=0;
	_Context->y_Auto459=0;
	_Context->w_Auto459=790;
	_Context->h_Auto459=600;
	_Context->window_col=0;
	_Context->window_row=0;
	for (i=0; i < 8; i++)_Context->msg_General[i]=" ";
	_Context->msg_General[0]=en_General;
	_Context->msg_General[1]=fr_General;
	_Context->msg_General[2]=it_General;
	_Context->msg_General[3]=es_General;
	_Context->msg_General[4]=de_General;
	_Context->msg_General[5]=nl_General;
	_Context->msg_General[6]=pt_General;
	_Context->msg_General[7]=xx_General;
	_Context->focus_pages[1]=2;
	for (i=0; i < 8; i++)_Context->msg_Auto460[i]=" ";
	_Context->msg_Auto460[0]=en_Auto460;
	_Context->msg_Auto460[1]=fr_Auto460;
	_Context->msg_Auto460[2]=it_Auto460;
	_Context->msg_Auto460[3]=es_Auto460;
	_Context->msg_Auto460[4]=de_Auto460;
	_Context->msg_Auto460[5]=nl_Auto460;
	_Context->msg_Auto460[6]=pt_Auto460;
	_Context->msg_Auto460[7]=xx_Auto460;
	_Context->hint_FILENAME[0]=en__FILENAME;
	for (i=0; i < 8; i++)_Context->msg_ChoixFILENAME[i]=" ";
	_Context->msg_ChoixFILENAME[0]=en_ChoixFILENAME;
	_Context->msg_ChoixFILENAME[1]=fr_ChoixFILENAME;
	_Context->msg_ChoixFILENAME[2]=it_ChoixFILENAME;
	_Context->msg_ChoixFILENAME[3]=es_ChoixFILENAME;
	_Context->msg_ChoixFILENAME[4]=de_ChoixFILENAME;
	_Context->msg_ChoixFILENAME[5]=nl_ChoixFILENAME;
	_Context->msg_ChoixFILENAME[6]=pt_ChoixFILENAME;
	_Context->msg_ChoixFILENAME[7]=xx_ChoixFILENAME;
	_Context->hint_ChoixFILENAME[0]=en__ChoixFILENAME;
	_Context->hint_ChoixFILENAME[1]=fr__ChoixFILENAME;
	_Context->hint_ChoixFILENAME[2]=it__ChoixFILENAME;
	_Context->hint_ChoixFILENAME[3]=es__ChoixFILENAME;
	_Context->hint_ChoixFILENAME[4]=de__ChoixFILENAME;
	_Context->hint_ChoixFILENAME[5]=nl__ChoixFILENAME;
	_Context->hint_ChoixFILENAME[6]=pt__ChoixFILENAME;
	_Context->hint_ChoixFILENAME[7]=xx__ChoixFILENAME;
	for (i=0; i < 8; i++)_Context->msg_Auto461[i]=" ";
	_Context->msg_Auto461[0]=en_Auto461;
	_Context->msg_Auto461[1]=fr_Auto461;
	_Context->msg_Auto461[2]=it_Auto461;
	_Context->msg_Auto461[3]=es_Auto461;
	_Context->msg_Auto461[4]=de_Auto461;
	_Context->msg_Auto461[5]=nl_Auto461;
	_Context->msg_Auto461[6]=pt_Auto461;
	_Context->msg_Auto461[7]=xx_Auto461;
	for (i=0; i < 8; i++)_Context->msg_Auto462[i]=" ";
	_Context->msg_Auto462[0]=en_Auto462;
	_Context->msg_Auto462[1]=fr_Auto462;
	_Context->msg_Auto462[2]=it_Auto462;
	_Context->msg_Auto462[3]=es_Auto462;
	_Context->msg_Auto462[4]=de_Auto462;
	_Context->msg_Auto462[5]=nl_Auto462;
	_Context->msg_Auto462[6]=pt_Auto462;
	_Context->msg_Auto462[7]=xx_Auto462;
	for (i=0; i < 8; i++)_Context->msg_Auto463[i]=" ";
	_Context->msg_Auto463[0]=en_Auto463;
	_Context->msg_Auto463[1]=fr_Auto463;
	_Context->msg_Auto463[2]=it_Auto463;
	_Context->msg_Auto463[3]=es_Auto463;
	_Context->msg_Auto463[4]=de_Auto463;
	_Context->msg_Auto463[5]=nl_Auto463;
	_Context->msg_Auto463[6]=pt_Auto463;
	_Context->msg_Auto463[7]=xx_Auto463;
	for (i=0; i < 8; i++)_Context->msg_Auto464[i]=" ";
	_Context->msg_Auto464[0]=en_Auto464;
	_Context->msg_Auto464[1]=fr_Auto464;
	_Context->msg_Auto464[2]=it_Auto464;
	_Context->msg_Auto464[3]=es_Auto464;
	_Context->msg_Auto464[4]=de_Auto464;
	_Context->msg_Auto464[5]=nl_Auto464;
	_Context->msg_Auto464[6]=pt_Auto464;
	_Context->msg_Auto464[7]=xx_Auto464;
	_Context->hint_Auto464[0]=en__Auto464;
	for (i=0; i < 8; i++)_Context->msg_Auto465[i]=" ";
	_Context->msg_Auto465[0]=en_Auto465;
	_Context->msg_Auto465[1]=fr_Auto465;
	_Context->msg_Auto465[2]=it_Auto465;
	_Context->msg_Auto465[3]=es_Auto465;
	_Context->msg_Auto465[4]=de_Auto465;
	_Context->msg_Auto465[5]=nl_Auto465;
	_Context->msg_Auto465[6]=pt_Auto465;
	_Context->msg_Auto465[7]=xx_Auto465;
	_Context->hint_RECORD[0]=en__RECORD;
	for (i=0; i < 8; i++)_Context->msg_Abal[i]=" ";
	_Context->msg_Abal[0]=en_Abal;
	_Context->msg_Abal[1]=fr_Abal;
	_Context->msg_Abal[2]=it_Abal;
	_Context->msg_Abal[3]=es_Abal;
	_Context->msg_Abal[4]=de_Abal;
	_Context->msg_Abal[5]=nl_Abal;
	_Context->msg_Abal[6]=pt_Abal;
	_Context->msg_Abal[7]=xx_Abal;
	_Context->hint_Abal[0]=en__Abal;
	_Context->focus_pages[2]=9;
	for (i=0; i < 8; i++)_Context->msg_Auto466[i]=" ";
	_Context->msg_Auto466[0]=en_Auto466;
	_Context->msg_Auto466[1]=fr_Auto466;
	_Context->msg_Auto466[2]=it_Auto466;
	_Context->msg_Auto466[3]=es_Auto466;
	_Context->msg_Auto466[4]=de_Auto466;
	_Context->msg_Auto466[5]=nl_Auto466;
	_Context->msg_Auto466[6]=pt_Auto466;
	_Context->msg_Auto466[7]=xx_Auto466;
	_Context->hint_Auto466[0]=en__Auto466;
	for (i=0; i < 8; i++)_Context->msg_Auto467[i]=" ";
	_Context->msg_Auto467[0]=en_Auto467;
	_Context->msg_Auto467[1]=fr_Auto467;
	_Context->msg_Auto467[2]=it_Auto467;
	_Context->msg_Auto467[3]=es_Auto467;
	_Context->msg_Auto467[4]=de_Auto467;
	_Context->msg_Auto467[5]=nl_Auto467;
	_Context->msg_Auto467[6]=pt_Auto467;
	_Context->msg_Auto467[7]=xx_Auto467;
	for (i=0; i < 8; i++)_Context->msg_Auto468[i]=" ";
	_Context->msg_Auto468[0]=en_Auto468;
	_Context->msg_Auto468[1]=fr_Auto468;
	_Context->msg_Auto468[2]=it_Auto468;
	_Context->msg_Auto468[3]=es_Auto468;
	_Context->msg_Auto468[4]=de_Auto468;
	_Context->msg_Auto468[5]=nl_Auto468;
	_Context->msg_Auto468[6]=pt_Auto468;
	_Context->msg_Auto468[7]=xx_Auto468;
	for (i=0; i < 8; i++)_Context->msg_Auto469[i]=" ";
	_Context->msg_Auto469[0]=en_Auto469;
	_Context->msg_Auto469[1]=fr_Auto469;
	_Context->msg_Auto469[2]=it_Auto469;
	_Context->msg_Auto469[3]=es_Auto469;
	_Context->msg_Auto469[4]=de_Auto469;
	_Context->msg_Auto469[5]=nl_Auto469;
	_Context->msg_Auto469[6]=pt_Auto469;
	_Context->msg_Auto469[7]=xx_Auto469;
	for (i=0; i < 8; i++)_Context->msg_Auto470[i]=" ";
	_Context->msg_Auto470[0]=en_Auto470;
	_Context->msg_Auto470[1]=fr_Auto470;
	_Context->msg_Auto470[2]=it_Auto470;
	_Context->msg_Auto470[3]=es_Auto470;
	_Context->msg_Auto470[4]=de_Auto470;
	_Context->msg_Auto470[5]=nl_Auto470;
	_Context->msg_Auto470[6]=pt_Auto470;
	_Context->msg_Auto470[7]=xx_Auto470;
	for (i=0; i < 8; i++)_Context->msg_Auto471[i]=" ";
	_Context->msg_Auto471[0]=en_Auto471;
	_Context->msg_Auto471[1]=fr_Auto471;
	_Context->msg_Auto471[2]=it_Auto471;
	_Context->msg_Auto471[3]=es_Auto471;
	_Context->msg_Auto471[4]=de_Auto471;
	_Context->msg_Auto471[5]=nl_Auto471;
	_Context->msg_Auto471[6]=pt_Auto471;
	_Context->msg_Auto471[7]=xx_Auto471;
	_Context->hint_Auto471[0]=en__Auto471;
	_Context->hint_Auto471[1]=fr__Auto471;
	_Context->hint_Auto471[2]=it__Auto471;
	_Context->hint_Auto471[3]=es__Auto471;
	_Context->hint_Auto471[4]=de__Auto471;
	_Context->hint_Auto471[5]=nl__Auto471;
	_Context->hint_Auto471[6]=pt__Auto471;
	_Context->hint_Auto471[7]=xx__Auto471;
	for (i=0; i < 8; i++)_Context->msg_Auto472[i]=" ";
	_Context->msg_Auto472[0]=en_Auto472;
	_Context->msg_Auto472[1]=fr_Auto472;
	_Context->msg_Auto472[2]=it_Auto472;
	_Context->msg_Auto472[3]=es_Auto472;
	_Context->msg_Auto472[4]=de_Auto472;
	_Context->msg_Auto472[5]=nl_Auto472;
	_Context->msg_Auto472[6]=pt_Auto472;
	_Context->msg_Auto472[7]=xx_Auto472;
	for (i=0; i < 8; i++)_Context->msg_Auto473[i]=" ";
	_Context->msg_Auto473[0]=en_Auto473;
	_Context->msg_Auto473[1]=fr_Auto473;
	_Context->msg_Auto473[2]=it_Auto473;
	_Context->msg_Auto473[3]=es_Auto473;
	_Context->msg_Auto473[4]=de_Auto473;
	_Context->msg_Auto473[5]=nl_Auto473;
	_Context->msg_Auto473[6]=pt_Auto473;
	_Context->msg_Auto473[7]=xx_Auto473;
	_Context->hint_ATR[0]=en__ATR;
	for (i=0; i < 8; i++)_Context->msg_ChoixATR[i]=" ";
	_Context->msg_ChoixATR[0]=en_ChoixATR;
	_Context->msg_ChoixATR[1]=fr_ChoixATR;
	_Context->msg_ChoixATR[2]=it_ChoixATR;
	_Context->msg_ChoixATR[3]=es_ChoixATR;
	_Context->msg_ChoixATR[4]=de_ChoixATR;
	_Context->msg_ChoixATR[5]=nl_ChoixATR;
	_Context->msg_ChoixATR[6]=pt_ChoixATR;
	_Context->msg_ChoixATR[7]=xx_ChoixATR;
	_Context->hint_ChoixATR[0]=en__ChoixATR;
	_Context->hint_ChoixATR[1]=fr__ChoixATR;
	_Context->hint_ChoixATR[2]=it__ChoixATR;
	_Context->hint_ChoixATR[3]=es__ChoixATR;
	_Context->hint_ChoixATR[4]=de__ChoixATR;
	_Context->hint_ChoixATR[5]=nl__ChoixATR;
	_Context->hint_ChoixATR[6]=pt__ChoixATR;
	_Context->hint_ChoixATR[7]=xx__ChoixATR;
	_Context->hint_ATR_DEFINE[0]=en__ATR_DEFINE;
	_Context->hint_ATR_INCLUDE[0]=en__ATR_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixATR_INCLUDE[i]=" ";
	_Context->msg_ChoixATR_INCLUDE[0]=en_ChoixATR_INCLUDE;
	_Context->msg_ChoixATR_INCLUDE[1]=fr_ChoixATR_INCLUDE;
	_Context->msg_ChoixATR_INCLUDE[2]=it_ChoixATR_INCLUDE;
	_Context->msg_ChoixATR_INCLUDE[3]=es_ChoixATR_INCLUDE;
	_Context->msg_ChoixATR_INCLUDE[4]=de_ChoixATR_INCLUDE;
	_Context->msg_ChoixATR_INCLUDE[5]=nl_ChoixATR_INCLUDE;
	_Context->msg_ChoixATR_INCLUDE[6]=pt_ChoixATR_INCLUDE;
	_Context->msg_ChoixATR_INCLUDE[7]=xx_ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[0]=en__ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[1]=fr__ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[2]=it__ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[3]=es__ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[4]=de__ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[5]=nl__ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[6]=pt__ChoixATR_INCLUDE;
	_Context->hint_ChoixATR_INCLUDE[7]=xx__ChoixATR_INCLUDE;
	_Context->hint_ATR_OPTIONS[0]=en__ATR_OPTIONS;
	_Context->hint_ALD[0]=en__ALD;
	for (i=0; i < 8; i++)_Context->msg_ChoixALD[i]=" ";
	_Context->msg_ChoixALD[0]=en_ChoixALD;
	_Context->msg_ChoixALD[1]=fr_ChoixALD;
	_Context->msg_ChoixALD[2]=it_ChoixALD;
	_Context->msg_ChoixALD[3]=es_ChoixALD;
	_Context->msg_ChoixALD[4]=de_ChoixALD;
	_Context->msg_ChoixALD[5]=nl_ChoixALD;
	_Context->msg_ChoixALD[6]=pt_ChoixALD;
	_Context->msg_ChoixALD[7]=xx_ChoixALD;
	_Context->hint_ChoixALD[0]=en__ChoixALD;
	_Context->hint_ChoixALD[1]=fr__ChoixALD;
	_Context->hint_ChoixALD[2]=it__ChoixALD;
	_Context->hint_ChoixALD[3]=es__ChoixALD;
	_Context->hint_ChoixALD[4]=de__ChoixALD;
	_Context->hint_ChoixALD[5]=nl__ChoixALD;
	_Context->hint_ChoixALD[6]=pt__ChoixALD;
	_Context->hint_ChoixALD[7]=xx__ChoixALD;
	_Context->hint_ALD_INCLUDE[0]=en__ALD_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixALD_INCLUDE[i]=" ";
	_Context->msg_ChoixALD_INCLUDE[0]=en_ChoixALD_INCLUDE;
	_Context->msg_ChoixALD_INCLUDE[1]=fr_ChoixALD_INCLUDE;
	_Context->msg_ChoixALD_INCLUDE[2]=it_ChoixALD_INCLUDE;
	_Context->msg_ChoixALD_INCLUDE[3]=es_ChoixALD_INCLUDE;
	_Context->msg_ChoixALD_INCLUDE[4]=de_ChoixALD_INCLUDE;
	_Context->msg_ChoixALD_INCLUDE[5]=nl_ChoixALD_INCLUDE;
	_Context->msg_ChoixALD_INCLUDE[6]=pt_ChoixALD_INCLUDE;
	_Context->msg_ChoixALD_INCLUDE[7]=xx_ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[0]=en__ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[1]=fr__ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[2]=it__ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[3]=es__ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[4]=de__ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[5]=nl__ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[6]=pt__ChoixALD_INCLUDE;
	_Context->hint_ChoixALD_INCLUDE[7]=xx__ChoixALD_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_Auto474[i]=" ";
	_Context->msg_Auto474[0]=en_Auto474;
	_Context->msg_Auto474[1]=fr_Auto474;
	_Context->msg_Auto474[2]=it_Auto474;
	_Context->msg_Auto474[3]=es_Auto474;
	_Context->msg_Auto474[4]=de_Auto474;
	_Context->msg_Auto474[5]=nl_Auto474;
	_Context->msg_Auto474[6]=pt_Auto474;
	_Context->msg_Auto474[7]=xx_Auto474;
	_Context->hint_Auto474[0]=en__Auto474;
	for (i=0; i < 8; i++)_Context->msg_Auto475[i]=" ";
	_Context->msg_Auto475[0]=en_Auto475;
	_Context->msg_Auto475[1]=fr_Auto475;
	_Context->msg_Auto475[2]=it_Auto475;
	_Context->msg_Auto475[3]=es_Auto475;
	_Context->msg_Auto475[4]=de_Auto475;
	_Context->msg_Auto475[5]=nl_Auto475;
	_Context->msg_Auto475[6]=pt_Auto475;
	_Context->msg_Auto475[7]=xx_Auto475;
	_Context->hint_Auto475[0]=en__Auto475;
	for (i=0; i < 8; i++)_Context->msg_Auto476[i]=" ";
	_Context->msg_Auto476[0]=en_Auto476;
	_Context->msg_Auto476[1]=fr_Auto476;
	_Context->msg_Auto476[2]=it_Auto476;
	_Context->msg_Auto476[3]=es_Auto476;
	_Context->msg_Auto476[4]=de_Auto476;
	_Context->msg_Auto476[5]=nl_Auto476;
	_Context->msg_Auto476[6]=pt_Auto476;
	_Context->msg_Auto476[7]=xx_Auto476;
	for (i=0; i < 8; i++)_Context->msg_Auto477[i]=" ";
	_Context->msg_Auto477[0]=en_Auto477;
	_Context->msg_Auto477[1]=fr_Auto477;
	_Context->msg_Auto477[2]=it_Auto477;
	_Context->msg_Auto477[3]=es_Auto477;
	_Context->msg_Auto477[4]=de_Auto477;
	_Context->msg_Auto477[5]=nl_Auto477;
	_Context->msg_Auto477[6]=pt_Auto477;
	_Context->msg_Auto477[7]=xx_Auto477;
	for (i=0; i < 8; i++)_Context->msg_Auto478[i]=" ";
	_Context->msg_Auto478[0]=en_Auto478;
	_Context->msg_Auto478[1]=fr_Auto478;
	_Context->msg_Auto478[2]=it_Auto478;
	_Context->msg_Auto478[3]=es_Auto478;
	_Context->msg_Auto478[4]=de_Auto478;
	_Context->msg_Auto478[5]=nl_Auto478;
	_Context->msg_Auto478[6]=pt_Auto478;
	_Context->msg_Auto478[7]=xx_Auto478;
	for (i=0; i < 8; i++)_Context->msg_Auto479[i]=" ";
	_Context->msg_Auto479[0]=en_Auto479;
	_Context->msg_Auto479[1]=fr_Auto479;
	_Context->msg_Auto479[2]=it_Auto479;
	_Context->msg_Auto479[3]=es_Auto479;
	_Context->msg_Auto479[4]=de_Auto479;
	_Context->msg_Auto479[5]=nl_Auto479;
	_Context->msg_Auto479[6]=pt_Auto479;
	_Context->msg_Auto479[7]=xx_Auto479;
	for (i=0; i < 8; i++)_Context->msg_Auto480[i]=" ";
	_Context->msg_Auto480[0]=en_Auto480;
	_Context->msg_Auto480[1]=fr_Auto480;
	_Context->msg_Auto480[2]=it_Auto480;
	_Context->msg_Auto480[3]=es_Auto480;
	_Context->msg_Auto480[4]=de_Auto480;
	_Context->msg_Auto480[5]=nl_Auto480;
	_Context->msg_Auto480[6]=pt_Auto480;
	_Context->msg_Auto480[7]=xx_Auto480;
	_Context->hint_Auto480[0]=en__Auto480;
	_Context->hint_Auto480[1]=fr__Auto480;
	_Context->hint_Auto480[2]=it__Auto480;
	_Context->hint_Auto480[3]=es__Auto480;
	_Context->hint_Auto480[4]=de__Auto480;
	_Context->hint_Auto480[5]=nl__Auto480;
	_Context->hint_Auto480[6]=pt__Auto480;
	_Context->hint_Auto480[7]=xx__Auto480;
	for (i=0; i < 8; i++)_Context->msg_Auto481[i]=" ";
	_Context->msg_Auto481[0]=en_Auto481;
	_Context->msg_Auto481[1]=fr_Auto481;
	_Context->msg_Auto481[2]=it_Auto481;
	_Context->msg_Auto481[3]=es_Auto481;
	_Context->msg_Auto481[4]=de_Auto481;
	_Context->msg_Auto481[5]=nl_Auto481;
	_Context->msg_Auto481[6]=pt_Auto481;
	_Context->msg_Auto481[7]=xx_Auto481;
	for (i=0; i < 8; i++)_Context->msg_Auto482[i]=" ";
	_Context->msg_Auto482[0]=en_Auto482;
	_Context->msg_Auto482[1]=fr_Auto482;
	_Context->msg_Auto482[2]=it_Auto482;
	_Context->msg_Auto482[3]=es_Auto482;
	_Context->msg_Auto482[4]=de_Auto482;
	_Context->msg_Auto482[5]=nl_Auto482;
	_Context->msg_Auto482[6]=pt_Auto482;
	_Context->msg_Auto482[7]=xx_Auto482;
	for (i=0; i < 8; i++)_Context->msg_Auto483[i]=" ";
	_Context->msg_Auto483[0]=en_Auto483;
	_Context->msg_Auto483[1]=fr_Auto483;
	_Context->msg_Auto483[2]=it_Auto483;
	_Context->msg_Auto483[3]=es_Auto483;
	_Context->msg_Auto483[4]=de_Auto483;
	_Context->msg_Auto483[5]=nl_Auto483;
	_Context->msg_Auto483[6]=pt_Auto483;
	_Context->msg_Auto483[7]=xx_Auto483;
	for (i=0; i < 8; i++)_Context->msg_Auto484[i]=" ";
	_Context->msg_Auto484[0]=en_Auto484;
	_Context->msg_Auto484[1]=fr_Auto484;
	_Context->msg_Auto484[2]=it_Auto484;
	_Context->msg_Auto484[3]=es_Auto484;
	_Context->msg_Auto484[4]=de_Auto484;
	_Context->msg_Auto484[5]=nl_Auto484;
	_Context->msg_Auto484[6]=pt_Auto484;
	_Context->msg_Auto484[7]=xx_Auto484;
	_Context->hint_OTR[0]=en__OTR;
	for (i=0; i < 8; i++)_Context->msg_ChoixOTR[i]=" ";
	_Context->msg_ChoixOTR[0]=en_ChoixOTR;
	_Context->msg_ChoixOTR[1]=fr_ChoixOTR;
	_Context->msg_ChoixOTR[2]=it_ChoixOTR;
	_Context->msg_ChoixOTR[3]=es_ChoixOTR;
	_Context->msg_ChoixOTR[4]=de_ChoixOTR;
	_Context->msg_ChoixOTR[5]=nl_ChoixOTR;
	_Context->msg_ChoixOTR[6]=pt_ChoixOTR;
	_Context->msg_ChoixOTR[7]=xx_ChoixOTR;
	_Context->hint_ChoixOTR[0]=en__ChoixOTR;
	_Context->hint_ChoixOTR[1]=fr__ChoixOTR;
	_Context->hint_ChoixOTR[2]=it__ChoixOTR;
	_Context->hint_ChoixOTR[3]=es__ChoixOTR;
	_Context->hint_ChoixOTR[4]=de__ChoixOTR;
	_Context->hint_ChoixOTR[5]=nl__ChoixOTR;
	_Context->hint_ChoixOTR[6]=pt__ChoixOTR;
	_Context->hint_ChoixOTR[7]=xx__ChoixOTR;
	_Context->hint_OTR_DEFINE[0]=en__OTR_DEFINE;
	_Context->hint_OTR_INCLUDE[0]=en__OTR_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixOTR_INCLUDE[i]=" ";
	_Context->msg_ChoixOTR_INCLUDE[0]=en_ChoixOTR_INCLUDE;
	_Context->msg_ChoixOTR_INCLUDE[1]=fr_ChoixOTR_INCLUDE;
	_Context->msg_ChoixOTR_INCLUDE[2]=it_ChoixOTR_INCLUDE;
	_Context->msg_ChoixOTR_INCLUDE[3]=es_ChoixOTR_INCLUDE;
	_Context->msg_ChoixOTR_INCLUDE[4]=de_ChoixOTR_INCLUDE;
	_Context->msg_ChoixOTR_INCLUDE[5]=nl_ChoixOTR_INCLUDE;
	_Context->msg_ChoixOTR_INCLUDE[6]=pt_ChoixOTR_INCLUDE;
	_Context->msg_ChoixOTR_INCLUDE[7]=xx_ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[0]=en__ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[1]=fr__ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[2]=it__ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[3]=es__ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[4]=de__ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[5]=nl__ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[6]=pt__ChoixOTR_INCLUDE;
	_Context->hint_ChoixOTR_INCLUDE[7]=xx__ChoixOTR_INCLUDE;
	_Context->hint_OTR_OPTIONS[0]=en__OTR_OPTIONS;
	_Context->hint_OLD[0]=en__OLD;
	for (i=0; i < 8; i++)_Context->msg_ChoixOLD[i]=" ";
	_Context->msg_ChoixOLD[0]=en_ChoixOLD;
	_Context->msg_ChoixOLD[1]=fr_ChoixOLD;
	_Context->msg_ChoixOLD[2]=it_ChoixOLD;
	_Context->msg_ChoixOLD[3]=es_ChoixOLD;
	_Context->msg_ChoixOLD[4]=de_ChoixOLD;
	_Context->msg_ChoixOLD[5]=nl_ChoixOLD;
	_Context->msg_ChoixOLD[6]=pt_ChoixOLD;
	_Context->msg_ChoixOLD[7]=xx_ChoixOLD;
	_Context->hint_ChoixOLD[0]=en__ChoixOLD;
	_Context->hint_ChoixOLD[1]=fr__ChoixOLD;
	_Context->hint_ChoixOLD[2]=it__ChoixOLD;
	_Context->hint_ChoixOLD[3]=es__ChoixOLD;
	_Context->hint_ChoixOLD[4]=de__ChoixOLD;
	_Context->hint_ChoixOLD[5]=nl__ChoixOLD;
	_Context->hint_ChoixOLD[6]=pt__ChoixOLD;
	_Context->hint_ChoixOLD[7]=xx__ChoixOLD;
	_Context->hint_OLD_INCLUDE[0]=en__OLD_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixOLD_INCLUDE[i]=" ";
	_Context->msg_ChoixOLD_INCLUDE[0]=en_ChoixOLD_INCLUDE;
	_Context->msg_ChoixOLD_INCLUDE[1]=fr_ChoixOLD_INCLUDE;
	_Context->msg_ChoixOLD_INCLUDE[2]=it_ChoixOLD_INCLUDE;
	_Context->msg_ChoixOLD_INCLUDE[3]=es_ChoixOLD_INCLUDE;
	_Context->msg_ChoixOLD_INCLUDE[4]=de_ChoixOLD_INCLUDE;
	_Context->msg_ChoixOLD_INCLUDE[5]=nl_ChoixOLD_INCLUDE;
	_Context->msg_ChoixOLD_INCLUDE[6]=pt_ChoixOLD_INCLUDE;
	_Context->msg_ChoixOLD_INCLUDE[7]=xx_ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[0]=en__ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[1]=fr__ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[2]=it__ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[3]=es__ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[4]=de__ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[5]=nl__ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[6]=pt__ChoixOLD_INCLUDE;
	_Context->hint_ChoixOLD_INCLUDE[7]=xx__ChoixOLD_INCLUDE;
	_Context->hint_OLD_OPTIONS[0]=en__OLD_OPTIONS;
	_Context->hint_EXA[0]=en__EXA;
	for (i=0; i < 8; i++)_Context->msg_ChoixEXA[i]=" ";
	_Context->msg_ChoixEXA[0]=en_ChoixEXA;
	_Context->msg_ChoixEXA[1]=fr_ChoixEXA;
	_Context->msg_ChoixEXA[2]=it_ChoixEXA;
	_Context->msg_ChoixEXA[3]=es_ChoixEXA;
	_Context->msg_ChoixEXA[4]=de_ChoixEXA;
	_Context->msg_ChoixEXA[5]=nl_ChoixEXA;
	_Context->msg_ChoixEXA[6]=pt_ChoixEXA;
	_Context->msg_ChoixEXA[7]=xx_ChoixEXA;
	_Context->hint_ChoixEXA[0]=en__ChoixEXA;
	_Context->hint_ChoixEXA[1]=fr__ChoixEXA;
	_Context->hint_ChoixEXA[2]=it__ChoixEXA;
	_Context->hint_ChoixEXA[3]=es__ChoixEXA;
	_Context->hint_ChoixEXA[4]=de__ChoixEXA;
	_Context->hint_ChoixEXA[5]=nl__ChoixEXA;
	_Context->hint_ChoixEXA[6]=pt__ChoixEXA;
	_Context->hint_ChoixEXA[7]=xx__ChoixEXA;
	_Context->hint_EXADB[0]=en__EXADB;
	for (i=0; i < 8; i++)_Context->msg_ChoixEXADB[i]=" ";
	_Context->msg_ChoixEXADB[0]=en_ChoixEXADB;
	_Context->msg_ChoixEXADB[1]=fr_ChoixEXADB;
	_Context->msg_ChoixEXADB[2]=it_ChoixEXADB;
	_Context->msg_ChoixEXADB[3]=es_ChoixEXADB;
	_Context->msg_ChoixEXADB[4]=de_ChoixEXADB;
	_Context->msg_ChoixEXADB[5]=nl_ChoixEXADB;
	_Context->msg_ChoixEXADB[6]=pt_ChoixEXADB;
	_Context->msg_ChoixEXADB[7]=xx_ChoixEXADB;
	_Context->hint_ChoixEXADB[0]=en__ChoixEXADB;
	_Context->hint_ChoixEXADB[1]=fr__ChoixEXADB;
	_Context->hint_ChoixEXADB[2]=it__ChoixEXADB;
	_Context->hint_ChoixEXADB[3]=es__ChoixEXADB;
	_Context->hint_ChoixEXADB[4]=de__ChoixEXADB;
	_Context->hint_ChoixEXADB[5]=nl__ChoixEXADB;
	_Context->hint_ChoixEXADB[6]=pt__ChoixEXADB;
	_Context->hint_ChoixEXADB[7]=xx__ChoixEXADB;
	for (i=0; i < 8; i++)_Context->msg_Cpp[i]=" ";
	_Context->msg_Cpp[0]=en_Cpp;
	_Context->msg_Cpp[1]=fr_Cpp;
	_Context->msg_Cpp[2]=it_Cpp;
	_Context->msg_Cpp[3]=es_Cpp;
	_Context->msg_Cpp[4]=de_Cpp;
	_Context->msg_Cpp[5]=nl_Cpp;
	_Context->msg_Cpp[6]=pt_Cpp;
	_Context->msg_Cpp[7]=xx_Cpp;
	_Context->hint_Cpp[0]=en__Cpp;
	_Context->hint_Cpp[1]=fr__Cpp;
	_Context->hint_Cpp[2]=it__Cpp;
	_Context->hint_Cpp[3]=es__Cpp;
	_Context->hint_Cpp[4]=de__Cpp;
	_Context->hint_Cpp[5]=nl__Cpp;
	_Context->hint_Cpp[6]=pt__Cpp;
	_Context->hint_Cpp[7]=xx__Cpp;
	_Context->focus_pages[3]=36;
	for (i=0; i < 8; i++)_Context->msg_Auto485[i]=" ";
	_Context->msg_Auto485[0]=en_Auto485;
	_Context->msg_Auto485[1]=fr_Auto485;
	_Context->msg_Auto485[2]=it_Auto485;
	_Context->msg_Auto485[3]=es_Auto485;
	_Context->msg_Auto485[4]=de_Auto485;
	_Context->msg_Auto485[5]=nl_Auto485;
	_Context->msg_Auto485[6]=pt_Auto485;
	_Context->msg_Auto485[7]=xx_Auto485;
	_Context->hint_Auto485[0]=en__Auto485;
	_Context->hint_Auto485[1]=fr__Auto485;
	_Context->hint_Auto485[2]=it__Auto485;
	_Context->hint_Auto485[3]=es__Auto485;
	_Context->hint_Auto485[4]=de__Auto485;
	_Context->hint_Auto485[5]=nl__Auto485;
	_Context->hint_Auto485[6]=pt__Auto485;
	_Context->hint_Auto485[7]=xx__Auto485;
	for (i=0; i < 8; i++)_Context->msg_Auto486[i]=" ";
	_Context->msg_Auto486[0]=en_Auto486;
	_Context->msg_Auto486[1]=fr_Auto486;
	_Context->msg_Auto486[2]=it_Auto486;
	_Context->msg_Auto486[3]=es_Auto486;
	_Context->msg_Auto486[4]=de_Auto486;
	_Context->msg_Auto486[5]=nl_Auto486;
	_Context->msg_Auto486[6]=pt_Auto486;
	_Context->msg_Auto486[7]=xx_Auto486;
	_Context->hint_Auto486[0]=en__Auto486;
	_Context->hint_Auto486[1]=fr__Auto486;
	_Context->hint_Auto486[2]=it__Auto486;
	_Context->hint_Auto486[3]=es__Auto486;
	_Context->hint_Auto486[4]=de__Auto486;
	_Context->hint_Auto486[5]=nl__Auto486;
	_Context->hint_Auto486[6]=pt__Auto486;
	_Context->hint_Auto486[7]=xx__Auto486;
	for (i=0; i < 8; i++)_Context->msg_Auto487[i]=" ";
	_Context->msg_Auto487[0]=en_Auto487;
	_Context->msg_Auto487[1]=fr_Auto487;
	_Context->msg_Auto487[2]=it_Auto487;
	_Context->msg_Auto487[3]=es_Auto487;
	_Context->msg_Auto487[4]=de_Auto487;
	_Context->msg_Auto487[5]=nl_Auto487;
	_Context->msg_Auto487[6]=pt_Auto487;
	_Context->msg_Auto487[7]=xx_Auto487;
	_Context->hint_Auto487[0]=en__Auto487;
	_Context->hint_Auto487[1]=fr__Auto487;
	_Context->hint_Auto487[2]=it__Auto487;
	_Context->hint_Auto487[3]=es__Auto487;
	_Context->hint_Auto487[4]=de__Auto487;
	_Context->hint_Auto487[5]=nl__Auto487;
	_Context->hint_Auto487[6]=pt__Auto487;
	_Context->hint_Auto487[7]=xx__Auto487;
	for (i=0; i < 8; i++)_Context->msg_Auto488[i]=" ";
	_Context->msg_Auto488[0]=en_Auto488;
	_Context->msg_Auto488[1]=fr_Auto488;
	_Context->msg_Auto488[2]=it_Auto488;
	_Context->msg_Auto488[3]=es_Auto488;
	_Context->msg_Auto488[4]=de_Auto488;
	_Context->msg_Auto488[5]=nl_Auto488;
	_Context->msg_Auto488[6]=pt_Auto488;
	_Context->msg_Auto488[7]=xx_Auto488;
	_Context->hint_Auto488[0]=en__Auto488;
	_Context->hint_Auto488[1]=fr__Auto488;
	_Context->hint_Auto488[2]=it__Auto488;
	_Context->hint_Auto488[3]=es__Auto488;
	_Context->hint_Auto488[4]=de__Auto488;
	_Context->hint_Auto488[5]=nl__Auto488;
	_Context->hint_Auto488[6]=pt__Auto488;
	_Context->hint_Auto488[7]=xx__Auto488;
	for (i=0; i < 8; i++)_Context->msg_Auto489[i]=" ";
	_Context->msg_Auto489[0]=en_Auto489;
	_Context->msg_Auto489[1]=fr_Auto489;
	_Context->msg_Auto489[2]=it_Auto489;
	_Context->msg_Auto489[3]=es_Auto489;
	_Context->msg_Auto489[4]=de_Auto489;
	_Context->msg_Auto489[5]=nl_Auto489;
	_Context->msg_Auto489[6]=pt_Auto489;
	_Context->msg_Auto489[7]=xx_Auto489;
	_Context->hint_Auto489[0]=en__Auto489;
	_Context->hint_Auto489[1]=fr__Auto489;
	_Context->hint_Auto489[2]=it__Auto489;
	_Context->hint_Auto489[3]=es__Auto489;
	_Context->hint_Auto489[4]=de__Auto489;
	_Context->hint_Auto489[5]=nl__Auto489;
	_Context->hint_Auto489[6]=pt__Auto489;
	_Context->hint_Auto489[7]=xx__Auto489;
	for (i=0; i < 8; i++)_Context->msg_Auto490[i]=" ";
	_Context->msg_Auto490[0]=en_Auto490;
	_Context->msg_Auto490[1]=fr_Auto490;
	_Context->msg_Auto490[2]=it_Auto490;
	_Context->msg_Auto490[3]=es_Auto490;
	_Context->msg_Auto490[4]=de_Auto490;
	_Context->msg_Auto490[5]=nl_Auto490;
	_Context->msg_Auto490[6]=pt_Auto490;
	_Context->msg_Auto490[7]=xx_Auto490;
	_Context->hint_Auto490[0]=en__Auto490;
	_Context->hint_Auto490[1]=fr__Auto490;
	_Context->hint_Auto490[2]=it__Auto490;
	_Context->hint_Auto490[3]=es__Auto490;
	_Context->hint_Auto490[4]=de__Auto490;
	_Context->hint_Auto490[5]=nl__Auto490;
	_Context->hint_Auto490[6]=pt__Auto490;
	_Context->hint_Auto490[7]=xx__Auto490;
	for (i=0; i < 8; i++)_Context->msg_Auto491[i]=" ";
	_Context->msg_Auto491[0]=en_Auto491;
	_Context->msg_Auto491[1]=fr_Auto491;
	_Context->msg_Auto491[2]=it_Auto491;
	_Context->msg_Auto491[3]=es_Auto491;
	_Context->msg_Auto491[4]=de_Auto491;
	_Context->msg_Auto491[5]=nl_Auto491;
	_Context->msg_Auto491[6]=pt_Auto491;
	_Context->msg_Auto491[7]=xx_Auto491;
	_Context->hint_Auto491[0]=en__Auto491;
	_Context->hint_Auto491[1]=fr__Auto491;
	_Context->hint_Auto491[2]=it__Auto491;
	_Context->hint_Auto491[3]=es__Auto491;
	_Context->hint_Auto491[4]=de__Auto491;
	_Context->hint_Auto491[5]=nl__Auto491;
	_Context->hint_Auto491[6]=pt__Auto491;
	_Context->hint_Auto491[7]=xx__Auto491;
	for (i=0; i < 8; i++)_Context->msg_Auto492[i]=" ";
	_Context->msg_Auto492[0]=en_Auto492;
	_Context->msg_Auto492[1]=fr_Auto492;
	_Context->msg_Auto492[2]=it_Auto492;
	_Context->msg_Auto492[3]=es_Auto492;
	_Context->msg_Auto492[4]=de_Auto492;
	_Context->msg_Auto492[5]=nl_Auto492;
	_Context->msg_Auto492[6]=pt_Auto492;
	_Context->msg_Auto492[7]=xx_Auto492;
	_Context->hint_Auto492[0]=en__Auto492;
	_Context->hint_Auto492[1]=fr__Auto492;
	_Context->hint_Auto492[2]=it__Auto492;
	_Context->hint_Auto492[3]=es__Auto492;
	_Context->hint_Auto492[4]=de__Auto492;
	_Context->hint_Auto492[5]=nl__Auto492;
	_Context->hint_Auto492[6]=pt__Auto492;
	_Context->hint_Auto492[7]=xx__Auto492;
	for (i=0; i < 8; i++)_Context->msg_Auto493[i]=" ";
	_Context->msg_Auto493[0]=en_Auto493;
	_Context->msg_Auto493[1]=fr_Auto493;
	_Context->msg_Auto493[2]=it_Auto493;
	_Context->msg_Auto493[3]=es_Auto493;
	_Context->msg_Auto493[4]=de_Auto493;
	_Context->msg_Auto493[5]=nl_Auto493;
	_Context->msg_Auto493[6]=pt_Auto493;
	_Context->msg_Auto493[7]=xx_Auto493;
	_Context->hint_Auto493[0]=en__Auto493;
	_Context->hint_Auto493[1]=fr__Auto493;
	_Context->hint_Auto493[2]=it__Auto493;
	_Context->hint_Auto493[3]=es__Auto493;
	_Context->hint_Auto493[4]=de__Auto493;
	_Context->hint_Auto493[5]=nl__Auto493;
	_Context->hint_Auto493[6]=pt__Auto493;
	_Context->hint_Auto493[7]=xx__Auto493;
	_Context->hint_CPP[0]=en__CPP;
	for (i=0; i < 8; i++)_Context->msg_ChoixCPP[i]=" ";
	_Context->msg_ChoixCPP[0]=en_ChoixCPP;
	_Context->msg_ChoixCPP[1]=fr_ChoixCPP;
	_Context->msg_ChoixCPP[2]=it_ChoixCPP;
	_Context->msg_ChoixCPP[3]=es_ChoixCPP;
	_Context->msg_ChoixCPP[4]=de_ChoixCPP;
	_Context->msg_ChoixCPP[5]=nl_ChoixCPP;
	_Context->msg_ChoixCPP[6]=pt_ChoixCPP;
	_Context->msg_ChoixCPP[7]=xx_ChoixCPP;
	_Context->hint_ChoixCPP[0]=en__ChoixCPP;
	_Context->hint_ChoixCPP[1]=fr__ChoixCPP;
	_Context->hint_ChoixCPP[2]=it__ChoixCPP;
	_Context->hint_ChoixCPP[3]=es__ChoixCPP;
	_Context->hint_ChoixCPP[4]=de__ChoixCPP;
	_Context->hint_ChoixCPP[5]=nl__ChoixCPP;
	_Context->hint_ChoixCPP[6]=pt__ChoixCPP;
	_Context->hint_ChoixCPP[7]=xx__ChoixCPP;
	_Context->hint_CPP_DEFINE[0]=en__CPP_DEFINE;
	_Context->hint_CPP_INCLUDE[0]=en__CPP_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixCPP_INCLUDE[i]=" ";
	_Context->msg_ChoixCPP_INCLUDE[0]=en_ChoixCPP_INCLUDE;
	_Context->msg_ChoixCPP_INCLUDE[1]=fr_ChoixCPP_INCLUDE;
	_Context->msg_ChoixCPP_INCLUDE[2]=it_ChoixCPP_INCLUDE;
	_Context->msg_ChoixCPP_INCLUDE[3]=es_ChoixCPP_INCLUDE;
	_Context->msg_ChoixCPP_INCLUDE[4]=de_ChoixCPP_INCLUDE;
	_Context->msg_ChoixCPP_INCLUDE[5]=nl_ChoixCPP_INCLUDE;
	_Context->msg_ChoixCPP_INCLUDE[6]=pt_ChoixCPP_INCLUDE;
	_Context->msg_ChoixCPP_INCLUDE[7]=xx_ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[0]=en__ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[1]=fr__ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[2]=it__ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[3]=es__ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[4]=de__ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[5]=nl__ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[6]=pt__ChoixCPP_INCLUDE;
	_Context->hint_ChoixCPP_INCLUDE[7]=xx__ChoixCPP_INCLUDE;
	_Context->hint_CPP_OPTIONS[0]=en__CPP_OPTIONS;
	_Context->hint_LPP[0]=en__LPP;
	for (i=0; i < 8; i++)_Context->msg_ChoixLPP[i]=" ";
	_Context->msg_ChoixLPP[0]=en_ChoixLPP;
	_Context->msg_ChoixLPP[1]=fr_ChoixLPP;
	_Context->msg_ChoixLPP[2]=it_ChoixLPP;
	_Context->msg_ChoixLPP[3]=es_ChoixLPP;
	_Context->msg_ChoixLPP[4]=de_ChoixLPP;
	_Context->msg_ChoixLPP[5]=nl_ChoixLPP;
	_Context->msg_ChoixLPP[6]=pt_ChoixLPP;
	_Context->msg_ChoixLPP[7]=xx_ChoixLPP;
	_Context->hint_ChoixLPP[0]=en__ChoixLPP;
	_Context->hint_ChoixLPP[1]=fr__ChoixLPP;
	_Context->hint_ChoixLPP[2]=it__ChoixLPP;
	_Context->hint_ChoixLPP[3]=es__ChoixLPP;
	_Context->hint_ChoixLPP[4]=de__ChoixLPP;
	_Context->hint_ChoixLPP[5]=nl__ChoixLPP;
	_Context->hint_ChoixLPP[6]=pt__ChoixLPP;
	_Context->hint_ChoixLPP[7]=xx__ChoixLPP;
	_Context->hint_LPP_INCLUDE[0]=en__LPP_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixLPP_INCLUDE[i]=" ";
	_Context->msg_ChoixLPP_INCLUDE[0]=en_ChoixLPP_INCLUDE;
	_Context->msg_ChoixLPP_INCLUDE[1]=fr_ChoixLPP_INCLUDE;
	_Context->msg_ChoixLPP_INCLUDE[2]=it_ChoixLPP_INCLUDE;
	_Context->msg_ChoixLPP_INCLUDE[3]=es_ChoixLPP_INCLUDE;
	_Context->msg_ChoixLPP_INCLUDE[4]=de_ChoixLPP_INCLUDE;
	_Context->msg_ChoixLPP_INCLUDE[5]=nl_ChoixLPP_INCLUDE;
	_Context->msg_ChoixLPP_INCLUDE[6]=pt_ChoixLPP_INCLUDE;
	_Context->msg_ChoixLPP_INCLUDE[7]=xx_ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[0]=en__ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[1]=fr__ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[2]=it__ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[3]=es__ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[4]=de__ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[5]=nl__ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[6]=pt__ChoixLPP_INCLUDE;
	_Context->hint_ChoixLPP_INCLUDE[7]=xx__ChoixLPP_INCLUDE;
	_Context->hint_LPP_OPTIONS[0]=en__LPP_OPTIONS;
	_Context->hint_LPP_LIBRARY[0]=en__LPP_LIBRARY;
	for (i=0; i < 8; i++)_Context->msg_Auto494[i]=" ";
	_Context->msg_Auto494[0]=en_Auto494;
	_Context->msg_Auto494[1]=fr_Auto494;
	_Context->msg_Auto494[2]=it_Auto494;
	_Context->msg_Auto494[3]=es_Auto494;
	_Context->msg_Auto494[4]=de_Auto494;
	_Context->msg_Auto494[5]=nl_Auto494;
	_Context->msg_Auto494[6]=pt_Auto494;
	_Context->msg_Auto494[7]=xx_Auto494;
	_Context->hint_Auto494[0]=en__Auto494;
	_Context->hint_Auto494[1]=fr__Auto494;
	_Context->hint_Auto494[2]=it__Auto494;
	_Context->hint_Auto494[3]=es__Auto494;
	_Context->hint_Auto494[4]=de__Auto494;
	_Context->hint_Auto494[5]=nl__Auto494;
	_Context->hint_Auto494[6]=pt__Auto494;
	_Context->hint_Auto494[7]=xx__Auto494;
	for (i=0; i < 8; i++)_Context->msg_Auto495[i]=" ";
	_Context->msg_Auto495[0]=en_Auto495;
	_Context->msg_Auto495[1]=fr_Auto495;
	_Context->msg_Auto495[2]=it_Auto495;
	_Context->msg_Auto495[3]=es_Auto495;
	_Context->msg_Auto495[4]=de_Auto495;
	_Context->msg_Auto495[5]=nl_Auto495;
	_Context->msg_Auto495[6]=pt_Auto495;
	_Context->msg_Auto495[7]=xx_Auto495;
	_Context->hint_Auto495[0]=en__Auto495;
	_Context->hint_Auto495[1]=fr__Auto495;
	_Context->hint_Auto495[2]=it__Auto495;
	_Context->hint_Auto495[3]=es__Auto495;
	_Context->hint_Auto495[4]=de__Auto495;
	_Context->hint_Auto495[5]=nl__Auto495;
	_Context->hint_Auto495[6]=pt__Auto495;
	_Context->hint_Auto495[7]=xx__Auto495;
	for (i=0; i < 8; i++)_Context->msg_Auto496[i]=" ";
	_Context->msg_Auto496[0]=en_Auto496;
	_Context->msg_Auto496[1]=fr_Auto496;
	_Context->msg_Auto496[2]=it_Auto496;
	_Context->msg_Auto496[3]=es_Auto496;
	_Context->msg_Auto496[4]=de_Auto496;
	_Context->msg_Auto496[5]=nl_Auto496;
	_Context->msg_Auto496[6]=pt_Auto496;
	_Context->msg_Auto496[7]=xx_Auto496;
	_Context->hint_Auto496[0]=en__Auto496;
	_Context->hint_Auto496[1]=fr__Auto496;
	_Context->hint_Auto496[2]=it__Auto496;
	_Context->hint_Auto496[3]=es__Auto496;
	_Context->hint_Auto496[4]=de__Auto496;
	_Context->hint_Auto496[5]=nl__Auto496;
	_Context->hint_Auto496[6]=pt__Auto496;
	_Context->hint_Auto496[7]=xx__Auto496;
	for (i=0; i < 8; i++)_Context->msg_Auto497[i]=" ";
	_Context->msg_Auto497[0]=en_Auto497;
	_Context->msg_Auto497[1]=fr_Auto497;
	_Context->msg_Auto497[2]=it_Auto497;
	_Context->msg_Auto497[3]=es_Auto497;
	_Context->msg_Auto497[4]=de_Auto497;
	_Context->msg_Auto497[5]=nl_Auto497;
	_Context->msg_Auto497[6]=pt_Auto497;
	_Context->msg_Auto497[7]=xx_Auto497;
	_Context->hint_Auto497[0]=en__Auto497;
	_Context->hint_Auto497[1]=fr__Auto497;
	_Context->hint_Auto497[2]=it__Auto497;
	_Context->hint_Auto497[3]=es__Auto497;
	_Context->hint_Auto497[4]=de__Auto497;
	_Context->hint_Auto497[5]=nl__Auto497;
	_Context->hint_Auto497[6]=pt__Auto497;
	_Context->hint_Auto497[7]=xx__Auto497;
	for (i=0; i < 8; i++)_Context->msg_Auto498[i]=" ";
	_Context->msg_Auto498[0]=en_Auto498;
	_Context->msg_Auto498[1]=fr_Auto498;
	_Context->msg_Auto498[2]=it_Auto498;
	_Context->msg_Auto498[3]=es_Auto498;
	_Context->msg_Auto498[4]=de_Auto498;
	_Context->msg_Auto498[5]=nl_Auto498;
	_Context->msg_Auto498[6]=pt_Auto498;
	_Context->msg_Auto498[7]=xx_Auto498;
	_Context->hint_Auto498[0]=en__Auto498;
	_Context->hint_Auto498[1]=fr__Auto498;
	_Context->hint_Auto498[2]=it__Auto498;
	_Context->hint_Auto498[3]=es__Auto498;
	_Context->hint_Auto498[4]=de__Auto498;
	_Context->hint_Auto498[5]=nl__Auto498;
	_Context->hint_Auto498[6]=pt__Auto498;
	_Context->hint_Auto498[7]=xx__Auto498;
	for (i=0; i < 8; i++)_Context->msg_Auto499[i]=" ";
	_Context->msg_Auto499[0]=en_Auto499;
	_Context->msg_Auto499[1]=fr_Auto499;
	_Context->msg_Auto499[2]=it_Auto499;
	_Context->msg_Auto499[3]=es_Auto499;
	_Context->msg_Auto499[4]=de_Auto499;
	_Context->msg_Auto499[5]=nl_Auto499;
	_Context->msg_Auto499[6]=pt_Auto499;
	_Context->msg_Auto499[7]=xx_Auto499;
	_Context->hint_Auto499[0]=en__Auto499;
	_Context->hint_Auto499[1]=fr__Auto499;
	_Context->hint_Auto499[2]=it__Auto499;
	_Context->hint_Auto499[3]=es__Auto499;
	_Context->hint_Auto499[4]=de__Auto499;
	_Context->hint_Auto499[5]=nl__Auto499;
	_Context->hint_Auto499[6]=pt__Auto499;
	_Context->hint_Auto499[7]=xx__Auto499;
	for (i=0; i < 8; i++)_Context->msg_Auto500[i]=" ";
	_Context->msg_Auto500[0]=en_Auto500;
	_Context->msg_Auto500[1]=fr_Auto500;
	_Context->msg_Auto500[2]=it_Auto500;
	_Context->msg_Auto500[3]=es_Auto500;
	_Context->msg_Auto500[4]=de_Auto500;
	_Context->msg_Auto500[5]=nl_Auto500;
	_Context->msg_Auto500[6]=pt_Auto500;
	_Context->msg_Auto500[7]=xx_Auto500;
	_Context->hint_Auto500[0]=en__Auto500;
	_Context->hint_Auto500[1]=fr__Auto500;
	_Context->hint_Auto500[2]=it__Auto500;
	_Context->hint_Auto500[3]=es__Auto500;
	_Context->hint_Auto500[4]=de__Auto500;
	_Context->hint_Auto500[5]=nl__Auto500;
	_Context->hint_Auto500[6]=pt__Auto500;
	_Context->hint_Auto500[7]=xx__Auto500;
	for (i=0; i < 8; i++)_Context->msg_Auto501[i]=" ";
	_Context->msg_Auto501[0]=en_Auto501;
	_Context->msg_Auto501[1]=fr_Auto501;
	_Context->msg_Auto501[2]=it_Auto501;
	_Context->msg_Auto501[3]=es_Auto501;
	_Context->msg_Auto501[4]=de_Auto501;
	_Context->msg_Auto501[5]=nl_Auto501;
	_Context->msg_Auto501[6]=pt_Auto501;
	_Context->msg_Auto501[7]=xx_Auto501;
	_Context->hint_Auto501[0]=en__Auto501;
	_Context->hint_Auto501[1]=fr__Auto501;
	_Context->hint_Auto501[2]=it__Auto501;
	_Context->hint_Auto501[3]=es__Auto501;
	_Context->hint_Auto501[4]=de__Auto501;
	_Context->hint_Auto501[5]=nl__Auto501;
	_Context->hint_Auto501[6]=pt__Auto501;
	_Context->hint_Auto501[7]=xx__Auto501;
	for (i=0; i < 8; i++)_Context->msg_Auto502[i]=" ";
	_Context->msg_Auto502[0]=en_Auto502;
	_Context->msg_Auto502[1]=fr_Auto502;
	_Context->msg_Auto502[2]=it_Auto502;
	_Context->msg_Auto502[3]=es_Auto502;
	_Context->msg_Auto502[4]=de_Auto502;
	_Context->msg_Auto502[5]=nl_Auto502;
	_Context->msg_Auto502[6]=pt_Auto502;
	_Context->msg_Auto502[7]=xx_Auto502;
	_Context->hint_Auto502[0]=en__Auto502;
	_Context->hint_Auto502[1]=fr__Auto502;
	_Context->hint_Auto502[2]=it__Auto502;
	_Context->hint_Auto502[3]=es__Auto502;
	_Context->hint_Auto502[4]=de__Auto502;
	_Context->hint_Auto502[5]=nl__Auto502;
	_Context->hint_Auto502[6]=pt__Auto502;
	_Context->hint_Auto502[7]=xx__Auto502;
	_Context->hint_DLLCPP[0]=en__DLLCPP;
	for (i=0; i < 8; i++)_Context->msg_ChoixDLLCPP[i]=" ";
	_Context->msg_ChoixDLLCPP[0]=en_ChoixDLLCPP;
	_Context->msg_ChoixDLLCPP[1]=fr_ChoixDLLCPP;
	_Context->msg_ChoixDLLCPP[2]=it_ChoixDLLCPP;
	_Context->msg_ChoixDLLCPP[3]=es_ChoixDLLCPP;
	_Context->msg_ChoixDLLCPP[4]=de_ChoixDLLCPP;
	_Context->msg_ChoixDLLCPP[5]=nl_ChoixDLLCPP;
	_Context->msg_ChoixDLLCPP[6]=pt_ChoixDLLCPP;
	_Context->msg_ChoixDLLCPP[7]=xx_ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[0]=en__ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[1]=fr__ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[2]=it__ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[3]=es__ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[4]=de__ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[5]=nl__ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[6]=pt__ChoixDLLCPP;
	_Context->hint_ChoixDLLCPP[7]=xx__ChoixDLLCPP;
	_Context->hint_DLLCPP_DEFINE[0]=en__DLLCPP_DEFINE;
	_Context->hint_DLLCPP_INCLUDE[0]=en__DLLCPP_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixDLLCPP_INCLUDE[i]=" ";
	_Context->msg_ChoixDLLCPP_INCLUDE[0]=en_ChoixDLLCPP_INCLUDE;
	_Context->msg_ChoixDLLCPP_INCLUDE[1]=fr_ChoixDLLCPP_INCLUDE;
	_Context->msg_ChoixDLLCPP_INCLUDE[2]=it_ChoixDLLCPP_INCLUDE;
	_Context->msg_ChoixDLLCPP_INCLUDE[3]=es_ChoixDLLCPP_INCLUDE;
	_Context->msg_ChoixDLLCPP_INCLUDE[4]=de_ChoixDLLCPP_INCLUDE;
	_Context->msg_ChoixDLLCPP_INCLUDE[5]=nl_ChoixDLLCPP_INCLUDE;
	_Context->msg_ChoixDLLCPP_INCLUDE[6]=pt_ChoixDLLCPP_INCLUDE;
	_Context->msg_ChoixDLLCPP_INCLUDE[7]=xx_ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[0]=en__ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[1]=fr__ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[2]=it__ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[3]=es__ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[4]=de__ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[5]=nl__ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[6]=pt__ChoixDLLCPP_INCLUDE;
	_Context->hint_ChoixDLLCPP_INCLUDE[7]=xx__ChoixDLLCPP_INCLUDE;
	_Context->hint_DLLCPP_OPTIONS[0]=en__DLLCPP_OPTIONS;
	_Context->hint_DLLLPP[0]=en__DLLLPP;
	for (i=0; i < 8; i++)_Context->msg_ChoixDLLLPP[i]=" ";
	_Context->msg_ChoixDLLLPP[0]=en_ChoixDLLLPP;
	_Context->msg_ChoixDLLLPP[1]=fr_ChoixDLLLPP;
	_Context->msg_ChoixDLLLPP[2]=it_ChoixDLLLPP;
	_Context->msg_ChoixDLLLPP[3]=es_ChoixDLLLPP;
	_Context->msg_ChoixDLLLPP[4]=de_ChoixDLLLPP;
	_Context->msg_ChoixDLLLPP[5]=nl_ChoixDLLLPP;
	_Context->msg_ChoixDLLLPP[6]=pt_ChoixDLLLPP;
	_Context->msg_ChoixDLLLPP[7]=xx_ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[0]=en__ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[1]=fr__ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[2]=it__ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[3]=es__ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[4]=de__ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[5]=nl__ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[6]=pt__ChoixDLLLPP;
	_Context->hint_ChoixDLLLPP[7]=xx__ChoixDLLLPP;
	_Context->hint_DLLLPP_INCLUDE[0]=en__DLLLPP_INCLUDE;
	for (i=0; i < 8; i++)_Context->msg_ChoixDLLLPP_INCLUDE[i]=" ";
	_Context->msg_ChoixDLLLPP_INCLUDE[0]=en_ChoixDLLLPP_INCLUDE;
	_Context->msg_ChoixDLLLPP_INCLUDE[1]=fr_ChoixDLLLPP_INCLUDE;
	_Context->msg_ChoixDLLLPP_INCLUDE[2]=it_ChoixDLLLPP_INCLUDE;
	_Context->msg_ChoixDLLLPP_INCLUDE[3]=es_ChoixDLLLPP_INCLUDE;
	_Context->msg_ChoixDLLLPP_INCLUDE[4]=de_ChoixDLLLPP_INCLUDE;
	_Context->msg_ChoixDLLLPP_INCLUDE[5]=nl_ChoixDLLLPP_INCLUDE;
	_Context->msg_ChoixDLLLPP_INCLUDE[6]=pt_ChoixDLLLPP_INCLUDE;
	_Context->msg_ChoixDLLLPP_INCLUDE[7]=xx_ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[0]=en__ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[1]=fr__ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[2]=it__ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[3]=es__ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[4]=de__ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[5]=nl__ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[6]=pt__ChoixDLLLPP_INCLUDE;
	_Context->hint_ChoixDLLLPP_INCLUDE[7]=xx__ChoixDLLLPP_INCLUDE;
	_Context->hint_DLLLPP_OPTIONS[0]=en__DLLLPP_OPTIONS;
	_Context->hint_DLLLPP_LIBRARY[0]=en__DLLLPP_LIBRARY;
	for (i=0; i < 8; i++)_Context->msg_Images[i]=" ";
	_Context->msg_Images[0]=en_Images;
	_Context->msg_Images[1]=fr_Images;
	_Context->msg_Images[2]=it_Images;
	_Context->msg_Images[3]=es_Images;
	_Context->msg_Images[4]=de_Images;
	_Context->msg_Images[5]=nl_Images;
	_Context->msg_Images[6]=pt_Images;
	_Context->msg_Images[7]=xx_Images;
	_Context->hint_Images[0]=en__Images;
	_Context->focus_pages[4]=61;
	for (i=0; i < 8; i++)_Context->msg_Auto503[i]=" ";
	_Context->msg_Auto503[0]=en_Auto503;
	_Context->msg_Auto503[1]=fr_Auto503;
	_Context->msg_Auto503[2]=it_Auto503;
	_Context->msg_Auto503[3]=es_Auto503;
	_Context->msg_Auto503[4]=de_Auto503;
	_Context->msg_Auto503[5]=nl_Auto503;
	_Context->msg_Auto503[6]=pt_Auto503;
	_Context->msg_Auto503[7]=xx_Auto503;
	_Context->hint_IMAGEPATH[0]=en__IMAGEPATH;
	for (i=0; i < 8; i++)_Context->msg_ChoixIMAGEPATH[i]=" ";
	_Context->msg_ChoixIMAGEPATH[0]=en_ChoixIMAGEPATH;
	_Context->msg_ChoixIMAGEPATH[1]=fr_ChoixIMAGEPATH;
	_Context->msg_ChoixIMAGEPATH[2]=it_ChoixIMAGEPATH;
	_Context->msg_ChoixIMAGEPATH[3]=es_ChoixIMAGEPATH;
	_Context->msg_ChoixIMAGEPATH[4]=de_ChoixIMAGEPATH;
	_Context->msg_ChoixIMAGEPATH[5]=nl_ChoixIMAGEPATH;
	_Context->msg_ChoixIMAGEPATH[6]=pt_ChoixIMAGEPATH;
	_Context->msg_ChoixIMAGEPATH[7]=xx_ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[0]=en__ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[1]=fr__ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[2]=it__ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[3]=es__ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[4]=de__ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[5]=nl__ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[6]=pt__ChoixIMAGEPATH;
	_Context->hint_ChoixIMAGEPATH[7]=xx__ChoixIMAGEPATH;
	for (i=0; i < 8; i++)_Context->msg_Auto504[i]=" ";
	_Context->msg_Auto504[0]=en_Auto504;
	_Context->msg_Auto504[1]=fr_Auto504;
	_Context->msg_Auto504[2]=it_Auto504;
	_Context->msg_Auto504[3]=es_Auto504;
	_Context->msg_Auto504[4]=de_Auto504;
	_Context->msg_Auto504[5]=nl_Auto504;
	_Context->msg_Auto504[6]=pt_Auto504;
	_Context->msg_Auto504[7]=xx_Auto504;
	for (i=0; i < 8; i++)_Context->msg_Auto505[i]=" ";
	_Context->msg_Auto505[0]=en_Auto505;
	_Context->msg_Auto505[1]=fr_Auto505;
	_Context->msg_Auto505[2]=it_Auto505;
	_Context->msg_Auto505[3]=es_Auto505;
	_Context->msg_Auto505[4]=de_Auto505;
	_Context->msg_Auto505[5]=nl_Auto505;
	_Context->msg_Auto505[6]=pt_Auto505;
	_Context->msg_Auto505[7]=xx_Auto505;
	for (i=0; i < 8; i++)_Context->msg_Auto506[i]=" ";
	_Context->msg_Auto506[0]=en_Auto506;
	_Context->msg_Auto506[1]=fr_Auto506;
	_Context->msg_Auto506[2]=it_Auto506;
	_Context->msg_Auto506[3]=es_Auto506;
	_Context->msg_Auto506[4]=de_Auto506;
	_Context->msg_Auto506[5]=nl_Auto506;
	_Context->msg_Auto506[6]=pt_Auto506;
	_Context->msg_Auto506[7]=xx_Auto506;
	for (i=0; i < 8; i++)_Context->msg_Auto507[i]=" ";
	_Context->msg_Auto507[0]=en_Auto507;
	_Context->msg_Auto507[1]=fr_Auto507;
	_Context->msg_Auto507[2]=it_Auto507;
	_Context->msg_Auto507[3]=es_Auto507;
	_Context->msg_Auto507[4]=de_Auto507;
	_Context->msg_Auto507[5]=nl_Auto507;
	_Context->msg_Auto507[6]=pt_Auto507;
	_Context->msg_Auto507[7]=xx_Auto507;
	for (i=0; i < 8; i++)_Context->msg_Auto508[i]=" ";
	_Context->msg_Auto508[0]=en_Auto508;
	_Context->msg_Auto508[1]=fr_Auto508;
	_Context->msg_Auto508[2]=it_Auto508;
	_Context->msg_Auto508[3]=es_Auto508;
	_Context->msg_Auto508[4]=de_Auto508;
	_Context->msg_Auto508[5]=nl_Auto508;
	_Context->msg_Auto508[6]=pt_Auto508;
	_Context->msg_Auto508[7]=xx_Auto508;
	_Context->hint_Auto508[0]=en__Auto508;
	_Context->hint_Auto508[1]=fr__Auto508;
	_Context->hint_Auto508[2]=it__Auto508;
	_Context->hint_Auto508[3]=es__Auto508;
	_Context->hint_Auto508[4]=de__Auto508;
	_Context->hint_Auto508[5]=nl__Auto508;
	_Context->hint_Auto508[6]=pt__Auto508;
	_Context->hint_Auto508[7]=xx__Auto508;
	for (i=0; i < 8; i++)_Context->msg_Auto509[i]=" ";
	_Context->msg_Auto509[0]=en_Auto509;
	_Context->msg_Auto509[1]=fr_Auto509;
	_Context->msg_Auto509[2]=it_Auto509;
	_Context->msg_Auto509[3]=es_Auto509;
	_Context->msg_Auto509[4]=de_Auto509;
	_Context->msg_Auto509[5]=nl_Auto509;
	_Context->msg_Auto509[6]=pt_Auto509;
	_Context->msg_Auto509[7]=xx_Auto509;
	_Context->hint_Auto509[0]=en__Auto509;
	_Context->hint_Auto509[1]=fr__Auto509;
	_Context->hint_Auto509[2]=it__Auto509;
	_Context->hint_Auto509[3]=es__Auto509;
	_Context->hint_Auto509[4]=de__Auto509;
	_Context->hint_Auto509[5]=nl__Auto509;
	_Context->hint_Auto509[6]=pt__Auto509;
	_Context->hint_Auto509[7]=xx__Auto509;
	for (i=0; i < 8; i++)_Context->msg_Auto510[i]=" ";
	_Context->msg_Auto510[0]=en_Auto510;
	_Context->msg_Auto510[1]=fr_Auto510;
	_Context->msg_Auto510[2]=it_Auto510;
	_Context->msg_Auto510[3]=es_Auto510;
	_Context->msg_Auto510[4]=de_Auto510;
	_Context->msg_Auto510[5]=nl_Auto510;
	_Context->msg_Auto510[6]=pt_Auto510;
	_Context->msg_Auto510[7]=xx_Auto510;
	_Context->hint_ICONPATH[0]=en__ICONPATH;
	for (i=0; i < 8; i++)_Context->msg_ChoixICONPATH[i]=" ";
	_Context->msg_ChoixICONPATH[0]=en_ChoixICONPATH;
	_Context->msg_ChoixICONPATH[1]=fr_ChoixICONPATH;
	_Context->msg_ChoixICONPATH[2]=it_ChoixICONPATH;
	_Context->msg_ChoixICONPATH[3]=es_ChoixICONPATH;
	_Context->msg_ChoixICONPATH[4]=de_ChoixICONPATH;
	_Context->msg_ChoixICONPATH[5]=nl_ChoixICONPATH;
	_Context->msg_ChoixICONPATH[6]=pt_ChoixICONPATH;
	_Context->msg_ChoixICONPATH[7]=xx_ChoixICONPATH;
	_Context->hint_ChoixICONPATH[0]=en__ChoixICONPATH;
	_Context->hint_ChoixICONPATH[1]=fr__ChoixICONPATH;
	_Context->hint_ChoixICONPATH[2]=it__ChoixICONPATH;
	_Context->hint_ChoixICONPATH[3]=es__ChoixICONPATH;
	_Context->hint_ChoixICONPATH[4]=de__ChoixICONPATH;
	_Context->hint_ChoixICONPATH[5]=nl__ChoixICONPATH;
	_Context->hint_ChoixICONPATH[6]=pt__ChoixICONPATH;
	_Context->hint_ChoixICONPATH[7]=xx__ChoixICONPATH;
	_Context->hint_PALETTE[0]=en__PALETTE;
	for (i=0; i < 8; i++)_Context->msg_ChoixPALETTE[i]=" ";
	_Context->msg_ChoixPALETTE[0]=en_ChoixPALETTE;
	_Context->msg_ChoixPALETTE[1]=fr_ChoixPALETTE;
	_Context->msg_ChoixPALETTE[2]=it_ChoixPALETTE;
	_Context->msg_ChoixPALETTE[3]=es_ChoixPALETTE;
	_Context->msg_ChoixPALETTE[4]=de_ChoixPALETTE;
	_Context->msg_ChoixPALETTE[5]=nl_ChoixPALETTE;
	_Context->msg_ChoixPALETTE[6]=pt_ChoixPALETTE;
	_Context->msg_ChoixPALETTE[7]=xx_ChoixPALETTE;
	_Context->hint_ChoixPALETTE[0]=en__ChoixPALETTE;
	_Context->hint_ChoixPALETTE[1]=fr__ChoixPALETTE;
	_Context->hint_ChoixPALETTE[2]=it__ChoixPALETTE;
	_Context->hint_ChoixPALETTE[3]=es__ChoixPALETTE;
	_Context->hint_ChoixPALETTE[4]=de__ChoixPALETTE;
	_Context->hint_ChoixPALETTE[5]=nl__ChoixPALETTE;
	_Context->hint_ChoixPALETTE[6]=pt__ChoixPALETTE;
	_Context->hint_ChoixPALETTE[7]=xx__ChoixPALETTE;
	for (i=0; i < 8; i++)_Context->msg_TRIGGER_STYLE[i]=" ";
	_Context->msg_TRIGGER_STYLE[0]=en_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[1]=fr_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[2]=it_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[3]=es_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[4]=de_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[5]=nl_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[6]=pt_TRIGGER_STYLE;
	_Context->msg_TRIGGER_STYLE[7]=xx_TRIGGER_STYLE;
	_Context->hint_STYLEPATH[0]=en__STYLEPATH;
	_Context->hint_COMPONENTPATH[0]=en__COMPONENTPATH;
	for (i=0; i < 8; i++)_Context->msg_ChoixSTYLEPATH[i]=" ";
	_Context->msg_ChoixSTYLEPATH[0]=en_ChoixSTYLEPATH;
	_Context->msg_ChoixSTYLEPATH[1]=fr_ChoixSTYLEPATH;
	_Context->msg_ChoixSTYLEPATH[2]=it_ChoixSTYLEPATH;
	_Context->msg_ChoixSTYLEPATH[3]=es_ChoixSTYLEPATH;
	_Context->msg_ChoixSTYLEPATH[4]=de_ChoixSTYLEPATH;
	_Context->msg_ChoixSTYLEPATH[5]=nl_ChoixSTYLEPATH;
	_Context->msg_ChoixSTYLEPATH[6]=pt_ChoixSTYLEPATH;
	_Context->msg_ChoixSTYLEPATH[7]=xx_ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[0]=en__ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[1]=fr__ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[2]=it__ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[3]=es__ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[4]=de__ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[5]=nl__ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[6]=pt__ChoixSTYLEPATH;
	_Context->hint_ChoixSTYLEPATH[7]=xx__ChoixSTYLEPATH;
	for (i=0; i < 8; i++)_Context->msg_ChoixCOMPPATH[i]=" ";
	_Context->msg_ChoixCOMPPATH[0]=en_ChoixCOMPPATH;
	_Context->msg_ChoixCOMPPATH[1]=fr_ChoixCOMPPATH;
	_Context->msg_ChoixCOMPPATH[2]=it_ChoixCOMPPATH;
	_Context->msg_ChoixCOMPPATH[3]=es_ChoixCOMPPATH;
	_Context->msg_ChoixCOMPPATH[4]=de_ChoixCOMPPATH;
	_Context->msg_ChoixCOMPPATH[5]=nl_ChoixCOMPPATH;
	_Context->msg_ChoixCOMPPATH[6]=pt_ChoixCOMPPATH;
	_Context->msg_ChoixCOMPPATH[7]=xx_ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[0]=en__ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[1]=fr__ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[2]=it__ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[3]=es__ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[4]=de__ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[5]=nl__ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[6]=pt__ChoixCOMPPATH;
	_Context->hint_ChoixCOMPPATH[7]=xx__ChoixCOMPPATH;
	for (i=0; i < 8; i++)_Context->msg_Fonts[i]=" ";
	_Context->msg_Fonts[0]=en_Fonts;
	_Context->msg_Fonts[1]=fr_Fonts;
	_Context->msg_Fonts[2]=it_Fonts;
	_Context->msg_Fonts[3]=es_Fonts;
	_Context->msg_Fonts[4]=de_Fonts;
	_Context->msg_Fonts[5]=nl_Fonts;
	_Context->msg_Fonts[6]=pt_Fonts;
	_Context->msg_Fonts[7]=xx_Fonts;
	_Context->hint_Fonts[0]=en__Fonts;
	_Context->focus_pages[5]=75;
	for (i=0; i < 8; i++)_Context->msg_Auto511[i]=" ";
	_Context->msg_Auto511[0]=en_Auto511;
	_Context->msg_Auto511[1]=fr_Auto511;
	_Context->msg_Auto511[2]=it_Auto511;
	_Context->msg_Auto511[3]=es_Auto511;
	_Context->msg_Auto511[4]=de_Auto511;
	_Context->msg_Auto511[5]=nl_Auto511;
	_Context->msg_Auto511[6]=pt_Auto511;
	_Context->msg_Auto511[7]=xx_Auto511;
	_Context->hint_Auto511[0]=en__Auto511;
	for (i=0; i < 8; i++)_Context->msg_Auto512[i]=" ";
	_Context->msg_Auto512[0]=en_Auto512;
	_Context->msg_Auto512[1]=fr_Auto512;
	_Context->msg_Auto512[2]=it_Auto512;
	_Context->msg_Auto512[3]=es_Auto512;
	_Context->msg_Auto512[4]=de_Auto512;
	_Context->msg_Auto512[5]=nl_Auto512;
	_Context->msg_Auto512[6]=pt_Auto512;
	_Context->msg_Auto512[7]=xx_Auto512;
	_Context->hint_FONTPATH[0]=en__FONTPATH;
	_Context->hint_FONTLAB1[0]=en__FONTLAB1;
	GetFontLabel(1,_Context->buffer_FONTLAB1,32);
	_Context->hint_FONTLAB2[0]=en__FONTLAB2;
	GetFontLabel(2,_Context->buffer_FONTLAB2,32);
	_Context->hint_FONTLAB3[0]=en__FONTLAB3;
	GetFontLabel(3,_Context->buffer_FONTLAB3,32);
	_Context->hint_FONTLAB4[0]=en__FONTLAB4;
	GetFontLabel(4,_Context->buffer_FONTLAB4,32);
	_Context->hint_FONTLAB5[0]=en__FONTLAB5;
	GetFontLabel(5,_Context->buffer_FONTLAB5,32);
	_Context->hint_FONTLAB6[0]=en__FONTLAB6;
	GetFontLabel(6,_Context->buffer_FONTLAB6,32);
	_Context->hint_FONTLAB7[0]=en__FONTLAB7;
	GetFontLabel(7,_Context->buffer_FONTLAB7,32);
	_Context->hint_FONTLAB8[0]=en__FONTLAB8;
	GetFontLabel(8,_Context->buffer_FONTLAB8,32);
	_Context->hint_FONTLAB9[0]=en__FONTLAB9;
	GetFontLabel(9,_Context->buffer_FONTLAB9,32);
	_Context->hint_FONTLAB10[0]=en__FONTLAB10;
	GetFontLabel(10,_Context->buffer_FONTLAB10,32);
	for (i=0; i < 8; i++)_Context->msg_ChoixFONTPATH[i]=" ";
	_Context->msg_ChoixFONTPATH[0]=en_ChoixFONTPATH;
	_Context->msg_ChoixFONTPATH[1]=fr_ChoixFONTPATH;
	_Context->msg_ChoixFONTPATH[2]=it_ChoixFONTPATH;
	_Context->msg_ChoixFONTPATH[3]=es_ChoixFONTPATH;
	_Context->msg_ChoixFONTPATH[4]=de_ChoixFONTPATH;
	_Context->msg_ChoixFONTPATH[5]=nl_ChoixFONTPATH;
	_Context->msg_ChoixFONTPATH[6]=pt_ChoixFONTPATH;
	_Context->msg_ChoixFONTPATH[7]=xx_ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[0]=en__ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[1]=fr__ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[2]=it__ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[3]=es__ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[4]=de__ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[5]=nl__ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[6]=pt__ChoixFONTPATH;
	_Context->hint_ChoixFONTPATH[7]=xx__ChoixFONTPATH;
	_Context->hint_FONT1[0]=en__FONT1;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT1[i]=" ";
	_Context->msg_ChoixFONT1[0]=en_ChoixFONT1;
	_Context->msg_ChoixFONT1[1]=fr_ChoixFONT1;
	_Context->msg_ChoixFONT1[2]=it_ChoixFONT1;
	_Context->msg_ChoixFONT1[3]=es_ChoixFONT1;
	_Context->msg_ChoixFONT1[4]=de_ChoixFONT1;
	_Context->msg_ChoixFONT1[5]=nl_ChoixFONT1;
	_Context->msg_ChoixFONT1[6]=pt_ChoixFONT1;
	_Context->msg_ChoixFONT1[7]=xx_ChoixFONT1;
	_Context->hint_ChoixFONT1[0]=en__ChoixFONT1;
	_Context->hint_ChoixFONT1[1]=fr__ChoixFONT1;
	_Context->hint_ChoixFONT1[2]=it__ChoixFONT1;
	_Context->hint_ChoixFONT1[3]=es__ChoixFONT1;
	_Context->hint_ChoixFONT1[4]=de__ChoixFONT1;
	_Context->hint_ChoixFONT1[5]=nl__ChoixFONT1;
	_Context->hint_ChoixFONT1[6]=pt__ChoixFONT1;
	_Context->hint_ChoixFONT1[7]=xx__ChoixFONT1;
	_Context->hint_FONT2[0]=en__FONT2;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT2[i]=" ";
	_Context->msg_ChoixFONT2[0]=en_ChoixFONT2;
	_Context->msg_ChoixFONT2[1]=fr_ChoixFONT2;
	_Context->msg_ChoixFONT2[2]=it_ChoixFONT2;
	_Context->msg_ChoixFONT2[3]=es_ChoixFONT2;
	_Context->msg_ChoixFONT2[4]=de_ChoixFONT2;
	_Context->msg_ChoixFONT2[5]=nl_ChoixFONT2;
	_Context->msg_ChoixFONT2[6]=pt_ChoixFONT2;
	_Context->msg_ChoixFONT2[7]=xx_ChoixFONT2;
	_Context->hint_ChoixFONT2[0]=en__ChoixFONT2;
	_Context->hint_ChoixFONT2[1]=fr__ChoixFONT2;
	_Context->hint_ChoixFONT2[2]=it__ChoixFONT2;
	_Context->hint_ChoixFONT2[3]=es__ChoixFONT2;
	_Context->hint_ChoixFONT2[4]=de__ChoixFONT2;
	_Context->hint_ChoixFONT2[5]=nl__ChoixFONT2;
	_Context->hint_ChoixFONT2[6]=pt__ChoixFONT2;
	_Context->hint_ChoixFONT2[7]=xx__ChoixFONT2;
	_Context->hint_FONT3[0]=en__FONT3;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT3[i]=" ";
	_Context->msg_ChoixFONT3[0]=en_ChoixFONT3;
	_Context->msg_ChoixFONT3[1]=fr_ChoixFONT3;
	_Context->msg_ChoixFONT3[2]=it_ChoixFONT3;
	_Context->msg_ChoixFONT3[3]=es_ChoixFONT3;
	_Context->msg_ChoixFONT3[4]=de_ChoixFONT3;
	_Context->msg_ChoixFONT3[5]=nl_ChoixFONT3;
	_Context->msg_ChoixFONT3[6]=pt_ChoixFONT3;
	_Context->msg_ChoixFONT3[7]=xx_ChoixFONT3;
	_Context->hint_ChoixFONT3[0]=en__ChoixFONT3;
	_Context->hint_ChoixFONT3[1]=fr__ChoixFONT3;
	_Context->hint_ChoixFONT3[2]=it__ChoixFONT3;
	_Context->hint_ChoixFONT3[3]=es__ChoixFONT3;
	_Context->hint_ChoixFONT3[4]=de__ChoixFONT3;
	_Context->hint_ChoixFONT3[5]=nl__ChoixFONT3;
	_Context->hint_ChoixFONT3[6]=pt__ChoixFONT3;
	_Context->hint_ChoixFONT3[7]=xx__ChoixFONT3;
	_Context->hint_FONT4[0]=en__FONT4;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT4[i]=" ";
	_Context->msg_ChoixFONT4[0]=en_ChoixFONT4;
	_Context->msg_ChoixFONT4[1]=fr_ChoixFONT4;
	_Context->msg_ChoixFONT4[2]=it_ChoixFONT4;
	_Context->msg_ChoixFONT4[3]=es_ChoixFONT4;
	_Context->msg_ChoixFONT4[4]=de_ChoixFONT4;
	_Context->msg_ChoixFONT4[5]=nl_ChoixFONT4;
	_Context->msg_ChoixFONT4[6]=pt_ChoixFONT4;
	_Context->msg_ChoixFONT4[7]=xx_ChoixFONT4;
	_Context->hint_ChoixFONT4[0]=en__ChoixFONT4;
	_Context->hint_ChoixFONT4[1]=fr__ChoixFONT4;
	_Context->hint_ChoixFONT4[2]=it__ChoixFONT4;
	_Context->hint_ChoixFONT4[3]=es__ChoixFONT4;
	_Context->hint_ChoixFONT4[4]=de__ChoixFONT4;
	_Context->hint_ChoixFONT4[5]=nl__ChoixFONT4;
	_Context->hint_ChoixFONT4[6]=pt__ChoixFONT4;
	_Context->hint_ChoixFONT4[7]=xx__ChoixFONT4;
	_Context->hint_FONT5[0]=en__FONT5;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT5[i]=" ";
	_Context->msg_ChoixFONT5[0]=en_ChoixFONT5;
	_Context->msg_ChoixFONT5[1]=fr_ChoixFONT5;
	_Context->msg_ChoixFONT5[2]=it_ChoixFONT5;
	_Context->msg_ChoixFONT5[3]=es_ChoixFONT5;
	_Context->msg_ChoixFONT5[4]=de_ChoixFONT5;
	_Context->msg_ChoixFONT5[5]=nl_ChoixFONT5;
	_Context->msg_ChoixFONT5[6]=pt_ChoixFONT5;
	_Context->msg_ChoixFONT5[7]=xx_ChoixFONT5;
	_Context->hint_ChoixFONT5[0]=en__ChoixFONT5;
	_Context->hint_ChoixFONT5[1]=fr__ChoixFONT5;
	_Context->hint_ChoixFONT5[2]=it__ChoixFONT5;
	_Context->hint_ChoixFONT5[3]=es__ChoixFONT5;
	_Context->hint_ChoixFONT5[4]=de__ChoixFONT5;
	_Context->hint_ChoixFONT5[5]=nl__ChoixFONT5;
	_Context->hint_ChoixFONT5[6]=pt__ChoixFONT5;
	_Context->hint_ChoixFONT5[7]=xx__ChoixFONT5;
	_Context->hint_FONT6[0]=en__FONT6;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT6[i]=" ";
	_Context->msg_ChoixFONT6[0]=en_ChoixFONT6;
	_Context->msg_ChoixFONT6[1]=fr_ChoixFONT6;
	_Context->msg_ChoixFONT6[2]=it_ChoixFONT6;
	_Context->msg_ChoixFONT6[3]=es_ChoixFONT6;
	_Context->msg_ChoixFONT6[4]=de_ChoixFONT6;
	_Context->msg_ChoixFONT6[5]=nl_ChoixFONT6;
	_Context->msg_ChoixFONT6[6]=pt_ChoixFONT6;
	_Context->msg_ChoixFONT6[7]=xx_ChoixFONT6;
	_Context->hint_ChoixFONT6[0]=en__ChoixFONT6;
	_Context->hint_ChoixFONT6[1]=fr__ChoixFONT6;
	_Context->hint_ChoixFONT6[2]=it__ChoixFONT6;
	_Context->hint_ChoixFONT6[3]=es__ChoixFONT6;
	_Context->hint_ChoixFONT6[4]=de__ChoixFONT6;
	_Context->hint_ChoixFONT6[5]=nl__ChoixFONT6;
	_Context->hint_ChoixFONT6[6]=pt__ChoixFONT6;
	_Context->hint_ChoixFONT6[7]=xx__ChoixFONT6;
	_Context->hint_FONT7[0]=en__FONT7;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT7[i]=" ";
	_Context->msg_ChoixFONT7[0]=en_ChoixFONT7;
	_Context->msg_ChoixFONT7[1]=fr_ChoixFONT7;
	_Context->msg_ChoixFONT7[2]=it_ChoixFONT7;
	_Context->msg_ChoixFONT7[3]=es_ChoixFONT7;
	_Context->msg_ChoixFONT7[4]=de_ChoixFONT7;
	_Context->msg_ChoixFONT7[5]=nl_ChoixFONT7;
	_Context->msg_ChoixFONT7[6]=pt_ChoixFONT7;
	_Context->msg_ChoixFONT7[7]=xx_ChoixFONT7;
	_Context->hint_ChoixFONT7[0]=en__ChoixFONT7;
	_Context->hint_ChoixFONT7[1]=fr__ChoixFONT7;
	_Context->hint_ChoixFONT7[2]=it__ChoixFONT7;
	_Context->hint_ChoixFONT7[3]=es__ChoixFONT7;
	_Context->hint_ChoixFONT7[4]=de__ChoixFONT7;
	_Context->hint_ChoixFONT7[5]=nl__ChoixFONT7;
	_Context->hint_ChoixFONT7[6]=pt__ChoixFONT7;
	_Context->hint_ChoixFONT7[7]=xx__ChoixFONT7;
	_Context->hint_FONT8[0]=en__FONT8;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT8[i]=" ";
	_Context->msg_ChoixFONT8[0]=en_ChoixFONT8;
	_Context->msg_ChoixFONT8[1]=fr_ChoixFONT8;
	_Context->msg_ChoixFONT8[2]=it_ChoixFONT8;
	_Context->msg_ChoixFONT8[3]=es_ChoixFONT8;
	_Context->msg_ChoixFONT8[4]=de_ChoixFONT8;
	_Context->msg_ChoixFONT8[5]=nl_ChoixFONT8;
	_Context->msg_ChoixFONT8[6]=pt_ChoixFONT8;
	_Context->msg_ChoixFONT8[7]=xx_ChoixFONT8;
	_Context->hint_ChoixFONT8[0]=en__ChoixFONT8;
	_Context->hint_ChoixFONT8[1]=fr__ChoixFONT8;
	_Context->hint_ChoixFONT8[2]=it__ChoixFONT8;
	_Context->hint_ChoixFONT8[3]=es__ChoixFONT8;
	_Context->hint_ChoixFONT8[4]=de__ChoixFONT8;
	_Context->hint_ChoixFONT8[5]=nl__ChoixFONT8;
	_Context->hint_ChoixFONT8[6]=pt__ChoixFONT8;
	_Context->hint_ChoixFONT8[7]=xx__ChoixFONT8;
	_Context->hint_FONT9[0]=en__FONT9;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT9[i]=" ";
	_Context->msg_ChoixFONT9[0]=en_ChoixFONT9;
	_Context->msg_ChoixFONT9[1]=fr_ChoixFONT9;
	_Context->msg_ChoixFONT9[2]=it_ChoixFONT9;
	_Context->msg_ChoixFONT9[3]=es_ChoixFONT9;
	_Context->msg_ChoixFONT9[4]=de_ChoixFONT9;
	_Context->msg_ChoixFONT9[5]=nl_ChoixFONT9;
	_Context->msg_ChoixFONT9[6]=pt_ChoixFONT9;
	_Context->msg_ChoixFONT9[7]=xx_ChoixFONT9;
	_Context->hint_ChoixFONT9[0]=en__ChoixFONT9;
	_Context->hint_ChoixFONT9[1]=fr__ChoixFONT9;
	_Context->hint_ChoixFONT9[2]=it__ChoixFONT9;
	_Context->hint_ChoixFONT9[3]=es__ChoixFONT9;
	_Context->hint_ChoixFONT9[4]=de__ChoixFONT9;
	_Context->hint_ChoixFONT9[5]=nl__ChoixFONT9;
	_Context->hint_ChoixFONT9[6]=pt__ChoixFONT9;
	_Context->hint_ChoixFONT9[7]=xx__ChoixFONT9;
	_Context->hint_FONT10[0]=en__FONT10;
	for (i=0; i < 8; i++)_Context->msg_ChoixFONT10[i]=" ";
	_Context->msg_ChoixFONT10[0]=en_ChoixFONT10;
	_Context->msg_ChoixFONT10[1]=fr_ChoixFONT10;
	_Context->msg_ChoixFONT10[2]=it_ChoixFONT10;
	_Context->msg_ChoixFONT10[3]=es_ChoixFONT10;
	_Context->msg_ChoixFONT10[4]=de_ChoixFONT10;
	_Context->msg_ChoixFONT10[5]=nl_ChoixFONT10;
	_Context->msg_ChoixFONT10[6]=pt_ChoixFONT10;
	_Context->msg_ChoixFONT10[7]=xx_ChoixFONT10;
	_Context->hint_ChoixFONT10[0]=en__ChoixFONT10;
	_Context->hint_ChoixFONT10[1]=fr__ChoixFONT10;
	_Context->hint_ChoixFONT10[2]=it__ChoixFONT10;
	_Context->hint_ChoixFONT10[3]=es__ChoixFONT10;
	_Context->hint_ChoixFONT10[4]=de__ChoixFONT10;
	_Context->hint_ChoixFONT10[5]=nl__ChoixFONT10;
	_Context->hint_ChoixFONT10[6]=pt__ChoixFONT10;
	_Context->hint_ChoixFONT10[7]=xx__ChoixFONT10;
	for (i=0; i < 8; i++)_Context->msg_Documents[i]=" ";
	_Context->msg_Documents[0]=en_Documents;
	_Context->msg_Documents[1]=fr_Documents;
	_Context->msg_Documents[2]=it_Documents;
	_Context->msg_Documents[3]=es_Documents;
	_Context->msg_Documents[4]=de_Documents;
	_Context->msg_Documents[5]=nl_Documents;
	_Context->msg_Documents[6]=pt_Documents;
	_Context->msg_Documents[7]=xx_Documents;
	_Context->hint_Documents[0]=en__Documents;
	_Context->focus_pages[6]=108;
	for (i=0; i < 8; i++)_Context->msg_Auto513[i]=" ";
	_Context->msg_Auto513[0]=en_Auto513;
	_Context->msg_Auto513[1]=fr_Auto513;
	_Context->msg_Auto513[2]=it_Auto513;
	_Context->msg_Auto513[3]=es_Auto513;
	_Context->msg_Auto513[4]=de_Auto513;
	_Context->msg_Auto513[5]=nl_Auto513;
	_Context->msg_Auto513[6]=pt_Auto513;
	_Context->msg_Auto513[7]=xx_Auto513;
	_Context->hint_Auto513[0]=en__Auto513;
	for (i=0; i < 8; i++)_Context->msg_Auto514[i]=" ";
	_Context->msg_Auto514[0]=en_Auto514;
	_Context->msg_Auto514[1]=fr_Auto514;
	_Context->msg_Auto514[2]=it_Auto514;
	_Context->msg_Auto514[3]=es_Auto514;
	_Context->msg_Auto514[4]=de_Auto514;
	_Context->msg_Auto514[5]=nl_Auto514;
	_Context->msg_Auto514[6]=pt_Auto514;
	_Context->msg_Auto514[7]=xx_Auto514;
	for (i=0; i < 8; i++)_Context->msg_Auto515[i]=" ";
	_Context->msg_Auto515[0]=en_Auto515;
	_Context->msg_Auto515[1]=fr_Auto515;
	_Context->msg_Auto515[2]=it_Auto515;
	_Context->msg_Auto515[3]=es_Auto515;
	_Context->msg_Auto515[4]=de_Auto515;
	_Context->msg_Auto515[5]=nl_Auto515;
	_Context->msg_Auto515[6]=pt_Auto515;
	_Context->msg_Auto515[7]=xx_Auto515;
	for (i=0; i < 8; i++)_Context->msg_Auto516[i]=" ";
	_Context->msg_Auto516[0]=en_Auto516;
	_Context->msg_Auto516[1]=fr_Auto516;
	_Context->msg_Auto516[2]=it_Auto516;
	_Context->msg_Auto516[3]=es_Auto516;
	_Context->msg_Auto516[4]=de_Auto516;
	_Context->msg_Auto516[5]=nl_Auto516;
	_Context->msg_Auto516[6]=pt_Auto516;
	_Context->msg_Auto516[7]=xx_Auto516;
	for (i=0; i < 8; i++)_Context->msg_Auto517[i]=" ";
	_Context->msg_Auto517[0]=en_Auto517;
	_Context->msg_Auto517[1]=fr_Auto517;
	_Context->msg_Auto517[2]=it_Auto517;
	_Context->msg_Auto517[3]=es_Auto517;
	_Context->msg_Auto517[4]=de_Auto517;
	_Context->msg_Auto517[5]=nl_Auto517;
	_Context->msg_Auto517[6]=pt_Auto517;
	_Context->msg_Auto517[7]=xx_Auto517;
	for (i=0; i < 8; i++)_Context->msg_Auto518[i]=" ";
	_Context->msg_Auto518[0]=en_Auto518;
	_Context->msg_Auto518[1]=fr_Auto518;
	_Context->msg_Auto518[2]=it_Auto518;
	_Context->msg_Auto518[3]=es_Auto518;
	_Context->msg_Auto518[4]=de_Auto518;
	_Context->msg_Auto518[5]=nl_Auto518;
	_Context->msg_Auto518[6]=pt_Auto518;
	_Context->msg_Auto518[7]=xx_Auto518;
	for (i=0; i < 8; i++)_Context->msg_Auto519[i]=" ";
	_Context->msg_Auto519[0]=en_Auto519;
	_Context->msg_Auto519[1]=fr_Auto519;
	_Context->msg_Auto519[2]=it_Auto519;
	_Context->msg_Auto519[3]=es_Auto519;
	_Context->msg_Auto519[4]=de_Auto519;
	_Context->msg_Auto519[5]=nl_Auto519;
	_Context->msg_Auto519[6]=pt_Auto519;
	_Context->msg_Auto519[7]=xx_Auto519;
	for (i=0; i < 8; i++)_Context->msg_Auto520[i]=" ";
	_Context->msg_Auto520[0]=en_Auto520;
	_Context->msg_Auto520[1]=fr_Auto520;
	_Context->msg_Auto520[2]=it_Auto520;
	_Context->msg_Auto520[3]=es_Auto520;
	_Context->msg_Auto520[4]=de_Auto520;
	_Context->msg_Auto520[5]=nl_Auto520;
	_Context->msg_Auto520[6]=pt_Auto520;
	_Context->msg_Auto520[7]=xx_Auto520;
	_Context->hint_HTML_TITLE[0]=en__HTML_TITLE;
	_Context->hint_HTML_LOGO[0]=en__HTML_LOGO;
	_Context->hint_HTML_COPYRIGHT[0]=en__HTML_COPYRIGHT;
	_Context->hint_SCREEN_CSS[0]=en__SCREEN_CSS;
	for (i=0; i < 8; i++)_Context->msg_ChoixSCREEN_CSS[i]=" ";
	_Context->msg_ChoixSCREEN_CSS[0]=en_ChoixSCREEN_CSS;
	_Context->msg_ChoixSCREEN_CSS[1]=fr_ChoixSCREEN_CSS;
	_Context->msg_ChoixSCREEN_CSS[2]=it_ChoixSCREEN_CSS;
	_Context->msg_ChoixSCREEN_CSS[3]=es_ChoixSCREEN_CSS;
	_Context->msg_ChoixSCREEN_CSS[4]=de_ChoixSCREEN_CSS;
	_Context->msg_ChoixSCREEN_CSS[5]=nl_ChoixSCREEN_CSS;
	_Context->msg_ChoixSCREEN_CSS[6]=pt_ChoixSCREEN_CSS;
	_Context->msg_ChoixSCREEN_CSS[7]=xx_ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[0]=en__ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[1]=fr__ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[2]=it__ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[3]=es__ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[4]=de__ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[5]=nl__ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[6]=pt__ChoixSCREEN_CSS;
	_Context->hint_ChoixSCREEN_CSS[7]=xx__ChoixSCREEN_CSS;
	_Context->hint_PRINT_CSS[0]=en__PRINT_CSS;
	for (i=0; i < 8; i++)_Context->msg_ChoixPRINT_CSS[i]=" ";
	_Context->msg_ChoixPRINT_CSS[0]=en_ChoixPRINT_CSS;
	_Context->msg_ChoixPRINT_CSS[1]=fr_ChoixPRINT_CSS;
	_Context->msg_ChoixPRINT_CSS[2]=it_ChoixPRINT_CSS;
	_Context->msg_ChoixPRINT_CSS[3]=es_ChoixPRINT_CSS;
	_Context->msg_ChoixPRINT_CSS[4]=de_ChoixPRINT_CSS;
	_Context->msg_ChoixPRINT_CSS[5]=nl_ChoixPRINT_CSS;
	_Context->msg_ChoixPRINT_CSS[6]=pt_ChoixPRINT_CSS;
	_Context->msg_ChoixPRINT_CSS[7]=xx_ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[0]=en__ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[1]=fr__ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[2]=it__ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[3]=es__ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[4]=de__ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[5]=nl__ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[6]=pt__ChoixPRINT_CSS;
	_Context->hint_ChoixPRINT_CSS[7]=xx__ChoixPRINT_CSS;
	_Context->hint_NAVIGATOR[0]=en__NAVIGATOR;
	for (i=0; i < 8; i++)_Context->msg_ChoixNAVIGATOR[i]=" ";
	_Context->msg_ChoixNAVIGATOR[0]=en_ChoixNAVIGATOR;
	_Context->msg_ChoixNAVIGATOR[1]=fr_ChoixNAVIGATOR;
	_Context->msg_ChoixNAVIGATOR[2]=it_ChoixNAVIGATOR;
	_Context->msg_ChoixNAVIGATOR[3]=es_ChoixNAVIGATOR;
	_Context->msg_ChoixNAVIGATOR[4]=de_ChoixNAVIGATOR;
	_Context->msg_ChoixNAVIGATOR[5]=nl_ChoixNAVIGATOR;
	_Context->msg_ChoixNAVIGATOR[6]=pt_ChoixNAVIGATOR;
	_Context->msg_ChoixNAVIGATOR[7]=xx_ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[0]=en__ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[1]=fr__ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[2]=it__ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[3]=es__ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[4]=de__ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[5]=nl__ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[6]=pt__ChoixNAVIGATOR;
	_Context->hint_ChoixNAVIGATOR[7]=xx__ChoixNAVIGATOR;
	_Context->hint_DOCPATH[0]=en__DOCPATH;
	for (i=0; i < 8; i++)_Context->msg_ChoixDOCPATH[i]=" ";
	_Context->msg_ChoixDOCPATH[0]=en_ChoixDOCPATH;
	_Context->msg_ChoixDOCPATH[1]=fr_ChoixDOCPATH;
	_Context->msg_ChoixDOCPATH[2]=it_ChoixDOCPATH;
	_Context->msg_ChoixDOCPATH[3]=es_ChoixDOCPATH;
	_Context->msg_ChoixDOCPATH[4]=de_ChoixDOCPATH;
	_Context->msg_ChoixDOCPATH[5]=nl_ChoixDOCPATH;
	_Context->msg_ChoixDOCPATH[6]=pt_ChoixDOCPATH;
	_Context->msg_ChoixDOCPATH[7]=xx_ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[0]=en__ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[1]=fr__ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[2]=it__ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[3]=es__ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[4]=de__ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[5]=nl__ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[6]=pt__ChoixDOCPATH;
	_Context->hint_ChoixDOCPATH[7]=xx__ChoixDOCPATH;
	for (i=0; i < 8; i++)_Context->msg_Printing[i]=" ";
	_Context->msg_Printing[0]=en_Printing;
	_Context->msg_Printing[1]=fr_Printing;
	_Context->msg_Printing[2]=it_Printing;
	_Context->msg_Printing[3]=es_Printing;
	_Context->msg_Printing[4]=de_Printing;
	_Context->msg_Printing[5]=nl_Printing;
	_Context->msg_Printing[6]=pt_Printing;
	_Context->msg_Printing[7]=xx_Printing;
	_Context->hint_Printing[0]=en__Printing;
	_Context->focus_pages[7]=120;
	for (i=0; i < 8; i++)_Context->msg_Auto521[i]=" ";
	_Context->msg_Auto521[0]=en_Auto521;
	_Context->msg_Auto521[1]=fr_Auto521;
	_Context->msg_Auto521[2]=it_Auto521;
	_Context->msg_Auto521[3]=es_Auto521;
	_Context->msg_Auto521[4]=de_Auto521;
	_Context->msg_Auto521[5]=nl_Auto521;
	_Context->msg_Auto521[6]=pt_Auto521;
	_Context->msg_Auto521[7]=xx_Auto521;
	for (i=0; i < 8; i++)_Context->msg_Auto522[i]=" ";
	_Context->msg_Auto522[0]=en_Auto522;
	_Context->msg_Auto522[1]=fr_Auto522;
	_Context->msg_Auto522[2]=it_Auto522;
	_Context->msg_Auto522[3]=es_Auto522;
	_Context->msg_Auto522[4]=de_Auto522;
	_Context->msg_Auto522[5]=nl_Auto522;
	_Context->msg_Auto522[6]=pt_Auto522;
	_Context->msg_Auto522[7]=xx_Auto522;
	_Context->hint_Auto522[0]=en__Auto522;
	for (i=0; i < 8; i++)_Context->msg_Auto523[i]=" ";
	_Context->msg_Auto523[0]=en_Auto523;
	_Context->msg_Auto523[1]=fr_Auto523;
	_Context->msg_Auto523[2]=it_Auto523;
	_Context->msg_Auto523[3]=es_Auto523;
	_Context->msg_Auto523[4]=de_Auto523;
	_Context->msg_Auto523[5]=nl_Auto523;
	_Context->msg_Auto523[6]=pt_Auto523;
	_Context->msg_Auto523[7]=xx_Auto523;
	_Context->hint_Auto523[0]=en__Auto523;
	for (i=0; i < 8; i++)_Context->msg_Auto524[i]=" ";
	_Context->msg_Auto524[0]=en_Auto524;
	_Context->msg_Auto524[1]=fr_Auto524;
	_Context->msg_Auto524[2]=it_Auto524;
	_Context->msg_Auto524[3]=es_Auto524;
	_Context->msg_Auto524[4]=de_Auto524;
	_Context->msg_Auto524[5]=nl_Auto524;
	_Context->msg_Auto524[6]=pt_Auto524;
	_Context->msg_Auto524[7]=xx_Auto524;
	_Context->hint_Auto524[0]=en__Auto524;
	for (i=0; i < 8; i++)_Context->msg_Auto525[i]=" ";
	_Context->msg_Auto525[0]=en_Auto525;
	_Context->msg_Auto525[1]=fr_Auto525;
	_Context->msg_Auto525[2]=it_Auto525;
	_Context->msg_Auto525[3]=es_Auto525;
	_Context->msg_Auto525[4]=de_Auto525;
	_Context->msg_Auto525[5]=nl_Auto525;
	_Context->msg_Auto525[6]=pt_Auto525;
	_Context->msg_Auto525[7]=xx_Auto525;
	_Context->hint_Auto525[0]=en__Auto525;
	_Context->hint_PRINTER[0]=en__PRINTER;
	for (i=0; i < 8; i++)_Context->msg_ChoixPRINTER[i]=" ";
	_Context->msg_ChoixPRINTER[0]=en_ChoixPRINTER;
	_Context->msg_ChoixPRINTER[1]=fr_ChoixPRINTER;
	_Context->msg_ChoixPRINTER[2]=it_ChoixPRINTER;
	_Context->msg_ChoixPRINTER[3]=es_ChoixPRINTER;
	_Context->msg_ChoixPRINTER[4]=de_ChoixPRINTER;
	_Context->msg_ChoixPRINTER[5]=nl_ChoixPRINTER;
	_Context->msg_ChoixPRINTER[6]=pt_ChoixPRINTER;
	_Context->msg_ChoixPRINTER[7]=xx_ChoixPRINTER;
	_Context->hint_ChoixPRINTER[0]=en__ChoixPRINTER;
	_Context->hint_ChoixPRINTER[1]=fr__ChoixPRINTER;
	_Context->hint_ChoixPRINTER[2]=it__ChoixPRINTER;
	_Context->hint_ChoixPRINTER[3]=es__ChoixPRINTER;
	_Context->hint_ChoixPRINTER[4]=de__ChoixPRINTER;
	_Context->hint_ChoixPRINTER[5]=nl__ChoixPRINTER;
	_Context->hint_ChoixPRINTER[6]=pt__ChoixPRINTER;
	_Context->hint_ChoixPRINTER[7]=xx__ChoixPRINTER;
	for (i=0; i < 8; i++)_Context->msg_PAPERTYPE[i]=" ";
	_Context->hint_PAPERTYPE[0]=en__PAPERTYPE;
	for (i=0; i < 8; i++)_Context->msg_LAYOUT[i]=" ";
	_Context->msg_LAYOUT[0]=en_LAYOUT;
	_Context->msg_LAYOUT[1]=fr_LAYOUT;
	_Context->msg_LAYOUT[2]=it_LAYOUT;
	_Context->msg_LAYOUT[3]=es_LAYOUT;
	_Context->msg_LAYOUT[4]=de_LAYOUT;
	_Context->msg_LAYOUT[5]=nl_LAYOUT;
	_Context->msg_LAYOUT[6]=pt_LAYOUT;
	_Context->msg_LAYOUT[7]=xx_LAYOUT;
	_Context->hint_LAYOUT[0]=en__LAYOUT;
	for (i=0; i < 8; i++)_Context->msg_PAGEFEED[i]=" ";
	_Context->msg_PAGEFEED[0]=en_PAGEFEED;
	_Context->msg_PAGEFEED[1]=fr_PAGEFEED;
	_Context->msg_PAGEFEED[2]=it_PAGEFEED;
	_Context->msg_PAGEFEED[3]=es_PAGEFEED;
	_Context->msg_PAGEFEED[4]=de_PAGEFEED;
	_Context->msg_PAGEFEED[5]=nl_PAGEFEED;
	_Context->msg_PAGEFEED[6]=pt_PAGEFEED;
	_Context->msg_PAGEFEED[7]=xx_PAGEFEED;
	_Context->hint_PAGEFEED[0]=en__PAGEFEED;
	for (i=0; i < 8; i++)_Context->msg_RESOLUTION[i]=" ";
	_Context->hint_RESOLUTION[0]=en__RESOLUTION;
	for (i=0; i < 8; i++)_Context->msg_Editor[i]=" ";
	_Context->msg_Editor[0]=en_Editor;
	_Context->msg_Editor[1]=fr_Editor;
	_Context->msg_Editor[2]=it_Editor;
	_Context->msg_Editor[3]=es_Editor;
	_Context->msg_Editor[4]=de_Editor;
	_Context->msg_Editor[5]=nl_Editor;
	_Context->msg_Editor[6]=pt_Editor;
	_Context->msg_Editor[7]=xx_Editor;
	_Context->hint_Editor[0]=en__Editor;
	_Context->focus_pages[8]=127;
	for (i=0; i < 8; i++)_Context->msg_Auto526[i]=" ";
	_Context->msg_Auto526[0]=en_Auto526;
	_Context->msg_Auto526[1]=fr_Auto526;
	_Context->msg_Auto526[2]=it_Auto526;
	_Context->msg_Auto526[3]=es_Auto526;
	_Context->msg_Auto526[4]=de_Auto526;
	_Context->msg_Auto526[5]=nl_Auto526;
	_Context->msg_Auto526[6]=pt_Auto526;
	_Context->msg_Auto526[7]=xx_Auto526;
	for (i=0; i < 8; i++)_Context->msg_Auto527[i]=" ";
	_Context->msg_Auto527[0]=en_Auto527;
	_Context->msg_Auto527[1]=fr_Auto527;
	_Context->msg_Auto527[2]=it_Auto527;
	_Context->msg_Auto527[3]=es_Auto527;
	_Context->msg_Auto527[4]=de_Auto527;
	_Context->msg_Auto527[5]=nl_Auto527;
	_Context->msg_Auto527[6]=pt_Auto527;
	_Context->msg_Auto527[7]=xx_Auto527;
	for (i=0; i < 8; i++)_Context->msg_Auto528[i]=" ";
	_Context->msg_Auto528[0]=en_Auto528;
	_Context->msg_Auto528[1]=fr_Auto528;
	_Context->msg_Auto528[2]=it_Auto528;
	_Context->msg_Auto528[3]=es_Auto528;
	_Context->msg_Auto528[4]=de_Auto528;
	_Context->msg_Auto528[5]=nl_Auto528;
	_Context->msg_Auto528[6]=pt_Auto528;
	_Context->msg_Auto528[7]=xx_Auto528;
	_Context->hint_Auto528[0]=en__Auto528;
	for (i=0; i < 8; i++)_Context->msg_ChoixAED[i]=" ";
	_Context->msg_ChoixAED[0]=en_ChoixAED;
	_Context->msg_ChoixAED[1]=fr_ChoixAED;
	_Context->msg_ChoixAED[2]=it_ChoixAED;
	_Context->msg_ChoixAED[3]=es_ChoixAED;
	_Context->msg_ChoixAED[4]=de_ChoixAED;
	_Context->msg_ChoixAED[5]=nl_ChoixAED;
	_Context->msg_ChoixAED[6]=pt_ChoixAED;
	_Context->msg_ChoixAED[7]=xx_ChoixAED;
	_Context->hint_ChoixAED[0]=en__ChoixAED;
	_Context->hint_ChoixAED[1]=fr__ChoixAED;
	_Context->hint_ChoixAED[2]=it__ChoixAED;
	_Context->hint_ChoixAED[3]=es__ChoixAED;
	_Context->hint_ChoixAED[4]=de__ChoixAED;
	_Context->hint_ChoixAED[5]=nl__ChoixAED;
	_Context->hint_ChoixAED[6]=pt__ChoixAED;
	_Context->hint_ChoixAED[7]=xx__ChoixAED;
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
	for (i=0; i < 8; i++)_Context->msg_AED_COMMENT[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AED_KEYWORD[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_AED_PUNCTUATE[i]=" ";
	for (i=0; i < 8; i++)_Context->msg_ACCEPT[i]=" ";
	_Context->msg_ACCEPT[0]=en_ACCEPT;
	_Context->msg_ACCEPT[1]=fr_ACCEPT;
	_Context->msg_ACCEPT[2]=it_ACCEPT;
	_Context->msg_ACCEPT[3]=es_ACCEPT;
	_Context->msg_ACCEPT[4]=de_ACCEPT;
	_Context->msg_ACCEPT[5]=nl_ACCEPT;
	_Context->msg_ACCEPT[6]=pt_ACCEPT;
	_Context->msg_ACCEPT[7]=xx_ACCEPT;
	for (i=0; i < 8; i++)_Context->msg_SAVEFILE[i]=" ";
	_Context->msg_SAVEFILE[0]=en_SAVEFILE;
	_Context->msg_SAVEFILE[1]=fr_SAVEFILE;
	_Context->msg_SAVEFILE[2]=it_SAVEFILE;
	_Context->msg_SAVEFILE[3]=es_SAVEFILE;
	_Context->msg_SAVEFILE[4]=de_SAVEFILE;
	_Context->msg_SAVEFILE[5]=nl_SAVEFILE;
	_Context->msg_SAVEFILE[6]=pt_SAVEFILE;
	_Context->msg_SAVEFILE[7]=xx_SAVEFILE;
	_Context->hint_SAVEFILE[0]=en__SAVEFILE;
	for (i=0; i < 8; i++)_Context->msg_SAVELDAP[i]=" ";
	_Context->hint_SAVELDAP[0]=en__SAVELDAP;
	_Context->hint_SAVELDAP[1]=fr__SAVELDAP;
	_Context->hint_SAVELDAP[2]=it__SAVELDAP;
	_Context->hint_SAVELDAP[3]=es__SAVELDAP;
	_Context->hint_SAVELDAP[4]=de__SAVELDAP;
	_Context->hint_SAVELDAP[5]=nl__SAVELDAP;
	_Context->hint_SAVELDAP[6]=pt__SAVELDAP;
	_Context->hint_SAVELDAP[7]=xx__SAVELDAP;
	for (i=0; i < 8; i++)_Context->msg_LoadLdap[i]=" ";
	_Context->hint_LoadLdap[0]=en__LoadLdap;
	_Context->hint_LoadLdap[1]=fr__LoadLdap;
	_Context->hint_LoadLdap[2]=it__LoadLdap;
	_Context->hint_LoadLdap[3]=es__LoadLdap;
	_Context->hint_LoadLdap[4]=de__LoadLdap;
	_Context->hint_LoadLdap[5]=nl__LoadLdap;
	_Context->hint_LoadLdap[6]=pt__LoadLdap;
	_Context->hint_LoadLdap[7]=xx__LoadLdap;
	for (i=0; i < 8; i++)_Context->msg_EDITFILE[i]=" ";
	_Context->msg_EDITFILE[0]=en_EDITFILE;
	_Context->msg_EDITFILE[1]=fr_EDITFILE;
	_Context->msg_EDITFILE[2]=it_EDITFILE;
	_Context->msg_EDITFILE[3]=es_EDITFILE;
	_Context->msg_EDITFILE[4]=de_EDITFILE;
	_Context->msg_EDITFILE[5]=nl_EDITFILE;
	_Context->msg_EDITFILE[6]=pt_EDITFILE;
	_Context->msg_EDITFILE[7]=xx_EDITFILE;
	_Context->hint_EDITFILE[0]=en__EDITFILE;
	_Context->hint_EDITFILE[1]=fr__EDITFILE;
	for (i=0; i < 8; i++)_Context->msg_DELETE[i]=" ";
	_Context->msg_DELETE[0]=en_DELETE;
	_Context->msg_DELETE[1]=fr_DELETE;
	_Context->msg_DELETE[2]=it_DELETE;
	_Context->msg_DELETE[3]=es_DELETE;
	_Context->msg_DELETE[4]=de_DELETE;
	_Context->msg_DELETE[5]=nl_DELETE;
	_Context->msg_DELETE[6]=pt_DELETE;
	_Context->msg_DELETE[7]=xx_DELETE;
	_Context->hint_DELETE[1]=fr__DELETE;
	for (i=0; i < 8; i++)_Context->msg_LOADFILE[i]=" ";
	_Context->msg_LOADFILE[0]=en_LOADFILE;
	_Context->msg_LOADFILE[1]=fr_LOADFILE;
	_Context->msg_LOADFILE[2]=it_LOADFILE;
	_Context->msg_LOADFILE[3]=es_LOADFILE;
	_Context->msg_LOADFILE[4]=de_LOADFILE;
	_Context->msg_LOADFILE[5]=nl_LOADFILE;
	_Context->msg_LOADFILE[6]=pt_LOADFILE;
	_Context->msg_LOADFILE[7]=xx_LOADFILE;
	_Context->hint_LOADFILE[0]=en__LOADFILE;
	_Context->hint_LOADFILE[1]=fr__LOADFILE;
	_Context->hint_LOADFILE[2]=it__LOADFILE;
	_Context->hint_LOADFILE[3]=es__LOADFILE;
	_Context->hint_LOADFILE[4]=de__LOADFILE;
	_Context->hint_LOADFILE[5]=nl__LOADFILE;
	_Context->hint_LOADFILE[6]=pt__LOADFILE;
	_Context->hint_LOADFILE[7]=xx__LOADFILE;
	for (i=0; i < 8; i++)_Context->msg_CANCEL[i]=" ";
	_Context->msg_CANCEL[0]=en_CANCEL;
	_Context->msg_CANCEL[1]=fr_CANCEL;
	_Context->msg_CANCEL[2]=it_CANCEL;
	_Context->msg_CANCEL[3]=es_CANCEL;
	_Context->msg_CANCEL[4]=de_CANCEL;
	_Context->msg_CANCEL[5]=nl_CANCEL;
	_Context->msg_CANCEL[6]=pt_CANCEL;
	_Context->msg_CANCEL[7]=xx_CANCEL;
	for (i=0; i < 8; i++)_Context->msg_Project[i]=" ";
	_Context->msg_Project[0]=en_Project;
	_Context->msg_Project[1]=fr_Project;
	_Context->msg_Project[2]=it_Project;
	_Context->msg_Project[3]=es_Project;
	_Context->msg_Project[4]=de_Project;
	_Context->msg_Project[5]=nl_Project;
	_Context->msg_Project[6]=pt_Project;
	_Context->msg_Project[7]=xx_Project;
	_Context->hint_Project[0]=en__Project;
	_Context->focus_pages[9]=146;
	for (i=0; i < 8; i++)_Context->msg_Auto529[i]=" ";
	_Context->msg_Auto529[0]=en_Auto529;
	_Context->msg_Auto529[1]=fr_Auto529;
	_Context->msg_Auto529[2]=it_Auto529;
	_Context->msg_Auto529[3]=es_Auto529;
	_Context->msg_Auto529[4]=de_Auto529;
	_Context->msg_Auto529[5]=nl_Auto529;
	_Context->msg_Auto529[6]=pt_Auto529;
	_Context->msg_Auto529[7]=xx_Auto529;
	for (i=0; i < 8; i++)_Context->msg_Auto530[i]=" ";
	_Context->msg_Auto530[0]=en_Auto530;
	_Context->msg_Auto530[1]=fr_Auto530;
	_Context->msg_Auto530[2]=it_Auto530;
	_Context->msg_Auto530[3]=es_Auto530;
	_Context->msg_Auto530[4]=de_Auto530;
	_Context->msg_Auto530[5]=nl_Auto530;
	_Context->msg_Auto530[6]=pt_Auto530;
	_Context->msg_Auto530[7]=xx_Auto530;
	for (i=0; i < 8; i++)_Context->msg_Auto531[i]=" ";
	_Context->msg_Auto531[0]=en_Auto531;
	_Context->msg_Auto531[1]=fr_Auto531;
	_Context->msg_Auto531[2]=it_Auto531;
	_Context->msg_Auto531[3]=es_Auto531;
	_Context->msg_Auto531[4]=de_Auto531;
	_Context->msg_Auto531[5]=nl_Auto531;
	_Context->msg_Auto531[6]=pt_Auto531;
	_Context->msg_Auto531[7]=xx_Auto531;
	for (i=0; i < 8; i++)_Context->msg_Auto532[i]=" ";
	_Context->msg_Auto532[0]=en_Auto532;
	_Context->msg_Auto532[1]=fr_Auto532;
	_Context->msg_Auto532[2]=it_Auto532;
	_Context->msg_Auto532[3]=es_Auto532;
	_Context->msg_Auto532[4]=de_Auto532;
	_Context->msg_Auto532[5]=nl_Auto532;
	_Context->msg_Auto532[6]=pt_Auto532;
	_Context->msg_Auto532[7]=xx_Auto532;
	_Context->hint_AMAKE[0]=en__AMAKE;
	for (i=0; i < 8; i++)_Context->msg_choixAMAKE[i]=" ";
	_Context->msg_choixAMAKE[0]=en_choixAMAKE;
	_Context->msg_choixAMAKE[1]=fr_choixAMAKE;
	_Context->msg_choixAMAKE[2]=it_choixAMAKE;
	_Context->msg_choixAMAKE[3]=es_choixAMAKE;
	_Context->msg_choixAMAKE[4]=de_choixAMAKE;
	_Context->msg_choixAMAKE[5]=nl_choixAMAKE;
	_Context->msg_choixAMAKE[6]=pt_choixAMAKE;
	_Context->msg_choixAMAKE[7]=xx_choixAMAKE;
	_Context->hint_choixAMAKE[0]=en__choixAMAKE;
	_Context->hint_AMAKE_OPTIONS[0]=en__AMAKE_OPTIONS;
	_Context->hint_AMAKE_DEFINE[0]=en__AMAKE_DEFINE;
	_Context->hint_AMAKE_LIST[0]=en__AMAKE_LIST;
	for (i=0; i < 8; i++)_Context->msg_choixAMAKE_LIST[i]=" ";
	_Context->msg_choixAMAKE_LIST[0]=en_choixAMAKE_LIST;
	_Context->msg_choixAMAKE_LIST[1]=fr_choixAMAKE_LIST;
	_Context->msg_choixAMAKE_LIST[2]=it_choixAMAKE_LIST;
	_Context->msg_choixAMAKE_LIST[3]=es_choixAMAKE_LIST;
	_Context->msg_choixAMAKE_LIST[4]=de_choixAMAKE_LIST;
	_Context->msg_choixAMAKE_LIST[5]=nl_choixAMAKE_LIST;
	_Context->msg_choixAMAKE_LIST[6]=pt_choixAMAKE_LIST;
	_Context->msg_choixAMAKE_LIST[7]=xx_choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[0]=en__choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[1]=fr__choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[2]=it__choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[3]=es__choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[4]=de__choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[5]=nl__choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[6]=pt__choixAMAKE_LIST;
	_Context->hint_choixAMAKE_LIST[7]=xx__choixAMAKE_LIST;
	_Context->ctrlbuffer=0;
	_Context->pushbuffer=visual_buffer(_Context->x_Auto459,_Context->y_Auto459,790,600);
	return(0);
}

public 	int	accept_configuration_hide(struct accept_configuration_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto459,_Context->y_Auto459);
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
	char * pALD_INCLUDE,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_INCLUDE,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pCPP,
	char * pCPP_DEFINE,
	char * pCPP_INCLUDE,
	char * pCPP_OPTIONS,
	char * pLPP,
	char * pLPP_INCLUDE,
	char * pLPP_OPTIONS,
	char * pLPP_LIBRARY,
	char * pDLLCPP,
	char * pDLLCPP_DEFINE,
	char * pDLLCPP_INCLUDE,
	char * pDLLCPP_OPTIONS,
	char * pDLLLPP,
	char * pDLLLPP_INCLUDE,
	char * pDLLLPP_OPTIONS,
	char * pDLLLPP_LIBRARY,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pSTYLEPATH,
	char * pCOMPONENTPATH,
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
	char * pAED_COMMENT,
	char * pAED_KEYWORD,
	char * pAED_PUNCTUATE,
	char * pAMAKE,
	char * pAMAKE_OPTIONS,
	char * pAMAKE_DEFINE,
	char * pAMAKE_LIST)
{

	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	SetFontLabel(10,_Context->buffer_FONTLAB10,32);
	SetFontLabel(9,_Context->buffer_FONTLAB9,32);
	SetFontLabel(8,_Context->buffer_FONTLAB8,32);
	SetFontLabel(7,_Context->buffer_FONTLAB7,32);
	SetFontLabel(6,_Context->buffer_FONTLAB6,32);
	SetFontLabel(5,_Context->buffer_FONTLAB5,32);
	SetFontLabel(4,_Context->buffer_FONTLAB4,32);
	SetFontLabel(3,_Context->buffer_FONTLAB3,32);
	SetFontLabel(2,_Context->buffer_FONTLAB2,32);
	SetFontLabel(1,_Context->buffer_FONTLAB1,32);
	if (_Context->keycode != 27 ) {
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
		visual_signature(_Context->signature,_Context->signature);
		visual_transferout(_Context->buffer_FILENAME, 259, pFILENAME);
		visual_transferout(_Context->buffer_ABALHOST, 255, pABALHOST);
		visual_transferout(_Context->buffer_IDENTITY, 255, pIDENTITY);
		visual_transferout(_Context->buffer_REPLAY, 255, pREPLAY);
		visual_transferout(_Context->buffer_RECORD, 255, pRECORD);
		visual_transferout(_Context->buffer_ATR, 255, pATR);
		visual_transferout(_Context->buffer_ATR_DEFINE, 255, pATR_DEFINE);
		visual_transferout(_Context->buffer_ATR_INCLUDE, 1024, pATR_INCLUDE);
		visual_transferout(_Context->buffer_ATR_OPTIONS, 255, pATR_OPTIONS);
		visual_transferout(_Context->buffer_ALD, 255, pALD);
		visual_transferout(_Context->buffer_ALD_INCLUDE, 255, pALD_INCLUDE);
		visual_transferout(_Context->buffer_ALD_OPTIONS, 255, pALD_OPTIONS);
		visual_transferout(_Context->buffer_OTR, 255, pOTR);
		visual_transferout(_Context->buffer_OTR_DEFINE, 255, pOTR_DEFINE);
		visual_transferout(_Context->buffer_OTR_INCLUDE, 255, pOTR_INCLUDE);
		visual_transferout(_Context->buffer_OTR_OPTIONS, 255, pOTR_OPTIONS);
		visual_transferout(_Context->buffer_OLD, 255, pOLD);
		visual_transferout(_Context->buffer_OLD_INCLUDE, 255, pOLD_INCLUDE);
		visual_transferout(_Context->buffer_OLD_OPTIONS, 255, pOLD_OPTIONS);
		visual_transferout(_Context->buffer_EXA, 255, pEXA);
		visual_transferout(_Context->buffer_EXADB, 255, pEXADB);
		visual_transferout(_Context->buffer_CPP, 255, pCPP);
		visual_transferout(_Context->buffer_CPP_DEFINE, 255, pCPP_DEFINE);
		visual_transferout(_Context->buffer_CPP_INCLUDE, 1024, pCPP_INCLUDE);
		visual_transferout(_Context->buffer_CPP_OPTIONS, 255, pCPP_OPTIONS);
		visual_transferout(_Context->buffer_LPP, 255, pLPP);
		visual_transferout(_Context->buffer_LPP_INCLUDE, 255, pLPP_INCLUDE);
		visual_transferout(_Context->buffer_LPP_OPTIONS, 255, pLPP_OPTIONS);
		visual_transferout(_Context->buffer_LPP_LIBRARY, 255, pLPP_LIBRARY);
		visual_transferout(_Context->buffer_DLLCPP, 255, pDLLCPP);
		visual_transferout(_Context->buffer_DLLCPP_DEFINE, 255, pDLLCPP_DEFINE);
		visual_transferout(_Context->buffer_DLLCPP_INCLUDE, 1024, pDLLCPP_INCLUDE);
		visual_transferout(_Context->buffer_DLLCPP_OPTIONS, 255, pDLLCPP_OPTIONS);
		visual_transferout(_Context->buffer_DLLLPP, 255, pDLLLPP);
		visual_transferout(_Context->buffer_DLLLPP_INCLUDE, 255, pDLLLPP_INCLUDE);
		visual_transferout(_Context->buffer_DLLLPP_OPTIONS, 255, pDLLLPP_OPTIONS);
		visual_transferout(_Context->buffer_DLLLPP_LIBRARY, 255, pDLLLPP_LIBRARY);
		visual_transferout(_Context->buffer_IMAGEPATH, 255, pIMAGEPATH);
		visual_transferout(_Context->buffer_ICONPATH, 255, pICONPATH);
		visual_transferout(_Context->buffer_PALETTE, 255, pPALETTE);
		visual_transferout(_Context->buffer_SKIN, 255, pSKIN);
		visual_transferout((void *) 0, 0, pTRIGGER_STYLE);
		if ( pTRIGGER_STYLE != (char *) 0)
			*((int*)pTRIGGER_STYLE) = _Context->value_TRIGGER_STYLE;
		visual_transferout(_Context->buffer_TRIGGER_COLOUR, 11, pTRIGGER_COLOUR);
		visual_transferout(_Context->buffer_STYLEPATH, 255, pSTYLEPATH);
		visual_transferout(_Context->buffer_COMPONENTPATH, 255, pCOMPONENTPATH);
		visual_transferout(_Context->buffer_FONTPATH, 255, pFONTPATH);
		visual_transferout(_Context->buffer_FONT1, 259, pFONT1);
		visual_transferout(_Context->buffer_FONT2, 259, pFONT2);
		visual_transferout(_Context->buffer_FONT3, 259, pFONT3);
		visual_transferout(_Context->buffer_FONT4, 259, pFONT4);
		visual_transferout(_Context->buffer_FONT5, 259, pFONT5);
		visual_transferout(_Context->buffer_FONT6, 259, pFONT6);
		visual_transferout(_Context->buffer_FONT7, 259, pFONT7);
		visual_transferout(_Context->buffer_FONT8, 259, pFONT8);
		visual_transferout(_Context->buffer_FONT9, 259, pFONT9);
		visual_transferout(_Context->buffer_FONT10, 259, pFONT10);
		visual_transferout(_Context->buffer_HTML_TITLE, 66, pHTML_TITLE);
		visual_transferout(_Context->buffer_HTML_LOGO, 66, pHTML_LOGO);
		visual_transferout(_Context->buffer_HTML_COPYRIGHT, 66, pHTML_COPYRIGHT);
		visual_transferout(_Context->buffer_SCREEN_CSS, 259, pSCREEN_CSS);
		visual_transferout(_Context->buffer_PRINT_CSS, 259, pPRINT_CSS);
		visual_transferout(_Context->buffer_NAVIGATOR, 255, pNAVIGATOR);
		visual_transferout(_Context->buffer_DOCPATH, 255, pDOCPATH);
		visual_transferout(_Context->buffer_PRINTER, 259, pPRINTER);
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
		visual_transferout(_Context->buffer_AED, 255, pAED);
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
		visual_transferout((void *) 0, 0, pAED_COMMENT);
		if ( pAED_COMMENT != (char *) 0)
			*((int*)pAED_COMMENT) = _Context->value_AED_COMMENT;
		visual_transferout((void *) 0, 0, pAED_KEYWORD);
		if ( pAED_KEYWORD != (char *) 0)
			*((int*)pAED_KEYWORD) = _Context->value_AED_KEYWORD;
		visual_transferout((void *) 0, 0, pAED_PUNCTUATE);
		if ( pAED_PUNCTUATE != (char *) 0)
			*((int*)pAED_PUNCTUATE) = _Context->value_AED_PUNCTUATE;
		visual_transferout(_Context->buffer_AMAKE, 255, pAMAKE);
		visual_transferout(_Context->buffer_AMAKE_OPTIONS, 255, pAMAKE_OPTIONS);
		visual_transferout(_Context->buffer_AMAKE_DEFINE, 255, pAMAKE_DEFINE);
		visual_transferout(_Context->buffer_AMAKE_LIST, 255, pAMAKE_LIST);
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto459,_Context->y_Auto459);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto459,_Context->y_Auto459,790,600,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto459,_Context->y_Auto459,790,600,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x7);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_General=visual_trigger_code(_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+90,710,16,vfh[1],27,0,_Context->msg_Auto460[_Context->language],strlen(_Context->msg_Auto460[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+106,710,414,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+150,493+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+150+1,493,16,vfh[1],27,28,_Context->buffer_FILENAME,259,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+180,520+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+180+1,520,16,vfh[1],27,28,_Context->buffer_ABALHOST,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto459+60,_Context->y_Auto459+150,140,20,vfh[3],27,0,_Context->msg_Auto461[_Context->language],strlen(_Context->msg_Auto461[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto459+60,_Context->y_Auto459+180,140,20,vfh[3],27,0,_Context->msg_Auto462[_Context->language],strlen(_Context->msg_Auto462[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto459+60,_Context->y_Auto459+210,144,20,vfh[3],27,0,_Context->msg_Auto463[_Context->language],strlen(_Context->msg_Auto463[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto459+60,_Context->y_Auto459+250,144,20,vfh[3],27,0,_Context->msg_Auto464[_Context->language],strlen(_Context->msg_Auto464[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto459+60,_Context->y_Auto459+280,144,20,vfh[3],27,0,_Context->msg_Auto465[_Context->language],strlen(_Context->msg_Auto465[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+210,520+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+210+1,520,16,vfh[1],27,28,_Context->buffer_IDENTITY,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+250,520+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+250+1,520,16,vfh[1],27,28,_Context->buffer_REPLAY,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+280,520+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+280+1,520,16,vfh[1],27,28,_Context->buffer_RECORD,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Abal=visual_trigger_code(_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]),84,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]),84,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+80,710,16,vfh[2],27,0,_Context->msg_Auto466[_Context->language],strlen(_Context->msg_Auto466[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+96,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+100,140,20,vfh[3],27,0,_Context->msg_Auto467[_Context->language],strlen(_Context->msg_Auto467[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+120,140,20,vfh[3],27,0,_Context->msg_Auto468[_Context->language],strlen(_Context->msg_Auto468[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+140,140,20,vfh[3],27,0,_Context->msg_Auto469[_Context->language],strlen(_Context->msg_Auto469[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+160,138,20,vfh[3],27,0,_Context->msg_Auto470[_Context->language],strlen(_Context->msg_Auto470[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+200,140,20,vfh[3],27,0,_Context->msg_Auto471[_Context->language],strlen(_Context->msg_Auto471[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+220,140,20,vfh[3],27,0,_Context->msg_Auto472[_Context->language],strlen(_Context->msg_Auto472[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+180,140,20,vfh[3],27,0,_Context->msg_Auto473[_Context->language],strlen(_Context->msg_Auto473[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+100,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+100+1,503,16,vfh[1],27,28,_Context->buffer_ATR,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+120,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+120+1,528,16,vfh[1],27,28,_Context->buffer_ATR_DEFINE,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+140,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+140+1,503,16,vfh[1],27,28,_Context->buffer_ATR_INCLUDE,1024,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+160,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+160+1,528,16,vfh[1],27,28,_Context->buffer_ATR_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+180,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+180+1,503,16,vfh[1],27,28,_Context->buffer_ALD,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+200,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+200+1,503,16,vfh[1],27,28,_Context->buffer_ALD_INCLUDE,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+220,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+220+1,528,16,vfh[1],27,28,_Context->buffer_ALD_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+260,710,16,vfh[2],27,0,_Context->msg_Auto474[_Context->language],strlen(_Context->msg_Auto474[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+276,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+440,710,16,vfh[2],27,0,_Context->msg_Auto475[_Context->language],strlen(_Context->msg_Auto475[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+456,710,64,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+280,140,20,vfh[3],27,0,_Context->msg_Auto476[_Context->language],strlen(_Context->msg_Auto476[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+300,140,20,vfh[3],27,0,_Context->msg_Auto477[_Context->language],strlen(_Context->msg_Auto477[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+320,140,20,vfh[3],27,0,_Context->msg_Auto478[_Context->language],strlen(_Context->msg_Auto478[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+340,140,20,vfh[3],27,0,_Context->msg_Auto479[_Context->language],strlen(_Context->msg_Auto479[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+380,140,20,vfh[3],27,0,_Context->msg_Auto480[_Context->language],strlen(_Context->msg_Auto480[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+400,140,20,vfh[3],27,0,_Context->msg_Auto481[_Context->language],strlen(_Context->msg_Auto481[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+360,140,20,vfh[3],27,0,_Context->msg_Auto482[_Context->language],strlen(_Context->msg_Auto482[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+470,140,20,vfh[3],27,0,_Context->msg_Auto483[_Context->language],strlen(_Context->msg_Auto483[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+490,140,20,vfh[3],27,0,_Context->msg_Auto484[_Context->language],strlen(_Context->msg_Auto484[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+280,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+280+1,503,16,vfh[1],27,28,_Context->buffer_OTR,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+300,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+300+1,528,16,vfh[1],27,28,_Context->buffer_OTR_DEFINE,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+320,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+320+1,503,16,vfh[1],27,28,_Context->buffer_OTR_INCLUDE,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+340,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+340+1,528,16,vfh[1],27,28,_Context->buffer_OTR_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+360,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+360+1,503,16,vfh[1],27,28,_Context->buffer_OLD,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+380,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+380+1,503,16,vfh[1],27,28,_Context->buffer_OLD_INCLUDE,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+400,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+400+1,528,16,vfh[1],27,28,_Context->buffer_OLD_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+470,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+470+1,503,16,vfh[1],27,28,_Context->buffer_EXA,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+490,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+490+1,503,16,vfh[1],27,28,_Context->buffer_EXADB,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Cpp=visual_trigger_code(_Context->msg_Cpp[_Context->language],strlen(_Context->msg_Cpp[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Cpp[_Context->language],strlen(_Context->msg_Cpp[_Context->language]),150,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Cpp[_Context->language],strlen(_Context->msg_Cpp[_Context->language]),150,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+80,710,16,vfh[2],27,0,_Context->msg_Auto485[_Context->language],strlen(_Context->msg_Auto485[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+96,710,174,4);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+100,140,20,vfh[3],27,0,_Context->msg_Auto486[_Context->language],strlen(_Context->msg_Auto486[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+120,140,20,vfh[3],27,0,_Context->msg_Auto487[_Context->language],strlen(_Context->msg_Auto487[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+140,140,20,vfh[3],27,0,_Context->msg_Auto488[_Context->language],strlen(_Context->msg_Auto488[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+160,138,20,vfh[3],27,0,_Context->msg_Auto489[_Context->language],strlen(_Context->msg_Auto489[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+200,160,20,vfh[3],27,0,_Context->msg_Auto490[_Context->language],strlen(_Context->msg_Auto490[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+180,140,20,vfh[3],27,0,_Context->msg_Auto491[_Context->language],strlen(_Context->msg_Auto491[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+220,150,20,vfh[3],27,0,_Context->msg_Auto492[_Context->language],strlen(_Context->msg_Auto492[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+240,150,20,vfh[3],27,0,_Context->msg_Auto493[_Context->language],strlen(_Context->msg_Auto493[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+100,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+100+1,503,16,vfh[1],27,28,_Context->buffer_CPP,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixCPP=visual_trigger_code(_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+120,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+120+1,528,16,vfh[1],27,28,_Context->buffer_CPP_DEFINE,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+140,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+140+1,503,16,vfh[1],27,28,_Context->buffer_CPP_INCLUDE,1024,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+160,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+160+1,528,16,vfh[1],27,28,_Context->buffer_CPP_OPTIONS,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+180,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+180+1,503,16,vfh[1],27,28,_Context->buffer_LPP,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixLPP=visual_trigger_code(_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+200,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+200+1,503,16,vfh[1],27,28,_Context->buffer_LPP_INCLUDE,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+220,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+220+1,528,16,vfh[1],27,28,_Context->buffer_LPP_OPTIONS,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+240,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+240+1,528,16,vfh[1],27,28,_Context->buffer_LPP_LIBRARY,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+300,710,16,vfh[2],27,0,_Context->msg_Auto494[_Context->language],strlen(_Context->msg_Auto494[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+316,710,174,4);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+320,140,20,vfh[3],27,0,_Context->msg_Auto495[_Context->language],strlen(_Context->msg_Auto495[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+340,140,20,vfh[3],27,0,_Context->msg_Auto496[_Context->language],strlen(_Context->msg_Auto496[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+360,140,20,vfh[3],27,0,_Context->msg_Auto497[_Context->language],strlen(_Context->msg_Auto497[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+380,138,20,vfh[3],27,0,_Context->msg_Auto498[_Context->language],strlen(_Context->msg_Auto498[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+420,160,20,vfh[3],27,0,_Context->msg_Auto499[_Context->language],strlen(_Context->msg_Auto499[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+400,140,20,vfh[3],27,0,_Context->msg_Auto500[_Context->language],strlen(_Context->msg_Auto500[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+440,150,20,vfh[3],27,0,_Context->msg_Auto501[_Context->language],strlen(_Context->msg_Auto501[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+460,150,20,vfh[3],27,0,_Context->msg_Auto502[_Context->language],strlen(_Context->msg_Auto502[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+320,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+320+1,503,16,vfh[1],27,28,_Context->buffer_DLLCPP,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixDLLCPP=visual_trigger_code(_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+340,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+340+1,528,16,vfh[1],27,28,_Context->buffer_DLLCPP_DEFINE,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+360,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+360+1,503,16,vfh[1],27,28,_Context->buffer_DLLCPP_INCLUDE,1024,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixDLLCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+380,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+380+1,528,16,vfh[1],27,28,_Context->buffer_DLLCPP_OPTIONS,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+400,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+400+1,503,16,vfh[1],27,28,_Context->buffer_DLLLPP,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixDLLLPP=visual_trigger_code(_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+400,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+420,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+420+1,503,16,vfh[1],27,28,_Context->buffer_DLLLPP_INCLUDE,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixDLLLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+440,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+440+1,528,16,vfh[1],27,28,_Context->buffer_DLLLPP_OPTIONS,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+460,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+460+1,528,16,vfh[1],27,28,_Context->buffer_DLLLPP_LIBRARY,255,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_Images=visual_trigger_code(_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]),213,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]),213,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+30,_Context->y_Auto459+110,154,20,vfh[3],27,0,_Context->msg_Auto503[_Context->language],strlen(_Context->msg_Auto503[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+110,519+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+110+1,519,16,vfh[1],27,28,_Context->buffer_IMAGEPATH,255,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+30,_Context->y_Auto459+140,154,20,vfh[3],27,0,_Context->msg_Auto504[_Context->language],strlen(_Context->msg_Auto504[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+30,_Context->y_Auto459+170,154,20,vfh[3],27,0,_Context->msg_Auto505[_Context->language],strlen(_Context->msg_Auto505[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+30,_Context->y_Auto459+200,184,20,vfh[3],27,0,_Context->msg_Auto506[_Context->language],strlen(_Context->msg_Auto506[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+30,_Context->y_Auto459+230,154,20,vfh[3],27,0,_Context->msg_Auto507[_Context->language],strlen(_Context->msg_Auto507[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+30,_Context->y_Auto459+260,138,20,vfh[3],27,0,_Context->msg_Auto508[_Context->language],strlen(_Context->msg_Auto508[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+30,_Context->y_Auto459+290,184,20,vfh[3],27,0,_Context->msg_Auto509[_Context->language],strlen(_Context->msg_Auto509[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto459+460,_Context->y_Auto459+230,184,20,vfh[3],27,0,_Context->msg_Auto510[_Context->language],strlen(_Context->msg_Auto510[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+140,519+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+140+1,519,16,vfh[1],27,28,_Context->buffer_ICONPATH,255,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+170,519+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+170+1,519,16,vfh[1],27,28,_Context->buffer_PALETTE,255,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+200,544+2,15+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+200+1,544,15,vfh[1],27,28,_Context->buffer_SKIN,255,0);
		}
	if (_Context->page_number == 4 ) {
	visual_select(_Context->x_Auto459+210,_Context->y_Auto459+230,184,80,vfh[1],27,28,parse_selection(_Context->msg_TRIGGER_STYLE[_Context->language],&_Context->value_TRIGGER_STYLE),512);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto459+660,_Context->y_Auto459+230,88+2,16+2,5);
	visual_text(_Context->x_Auto459+660+1,_Context->y_Auto459+230+1,88,16,vfh[1],27,28,_Context->buffer_TRIGGER_COLOUR,11,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+260,520+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+260+1,520,16,vfh[1],27,28,_Context->buffer_STYLEPATH,255,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto459+210,_Context->y_Auto459+290,520+2,16+2,5);
	visual_text(_Context->x_Auto459+210+1,_Context->y_Auto459+290+1,520,16,vfh[1],27,28,_Context->buffer_COMPONENTPATH,255,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_Fonts=visual_trigger_code(_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]),293,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]),293,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+150,700,16,vfh[2],27,0,_Context->msg_Auto511[_Context->language],strlen(_Context->msg_Auto511[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+166,700,314,4);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+110,154,20,vfh[3],27,0,_Context->msg_Auto512[_Context->language],strlen(_Context->msg_Auto512[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+110,519+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+110+1,519,16,vfh[1],27,28,_Context->buffer_FONTPATH,255,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+180,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+180+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB1,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+210,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+210+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB2,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+240,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+240+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB3,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+270,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+270+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB4,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+300,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+300+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB5,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+330,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+330+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB6,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+360,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+360+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB7,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+390,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+390+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB8,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+420,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+420+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB9,32,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+450,144+2,16+2,5);
	visual_text(_Context->x_Auto459+50+1,_Context->y_Auto459+450+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB10,32,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
	visual_button(_Context->x_Auto459+725,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+180,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+180+1,503,16,vfh[1],27,28,_Context->buffer_FONT1,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+210,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+210+1,503,16,vfh[1],27,28,_Context->buffer_FONT2,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+240,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+240+1,503,16,vfh[1],27,28,_Context->buffer_FONT3,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+270,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+270+1,503,16,vfh[1],27,28,_Context->buffer_FONT4,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+300,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+300+1,503,16,vfh[1],27,28,_Context->buffer_FONT5,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+330,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+330+1,503,16,vfh[1],27,28,_Context->buffer_FONT6,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+360,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+360+1,503,16,vfh[1],27,28,_Context->buffer_FONT7,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+390,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+390+1,503,16,vfh[1],27,28,_Context->buffer_FONT8,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+420,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+420+1,503,16,vfh[1],27,28,_Context->buffer_FONT9,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+450,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+450+1,503,16,vfh[1],27,28,_Context->buffer_FONT10,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_Documents=visual_trigger_code(_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]),374,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]),374,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+80,710,16,vfh[2],27,0,_Context->msg_Auto513[_Context->language],strlen(_Context->msg_Auto513[_Context->language]),2);
	visual_frame(_Context->x_Auto459+40,_Context->y_Auto459+96,710,424,4);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+110,140,20,vfh[3],27,0,_Context->msg_Auto514[_Context->language],strlen(_Context->msg_Auto514[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+140,140,20,vfh[3],27,0,_Context->msg_Auto515[_Context->language],strlen(_Context->msg_Auto515[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+170,140,20,vfh[3],27,0,_Context->msg_Auto516[_Context->language],strlen(_Context->msg_Auto516[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+200,140,20,vfh[3],27,0,_Context->msg_Auto517[_Context->language],strlen(_Context->msg_Auto517[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+230,140,20,vfh[3],27,0,_Context->msg_Auto518[_Context->language],strlen(_Context->msg_Auto518[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+260,140,20,vfh[3],27,0,_Context->msg_Auto519[_Context->language],strlen(_Context->msg_Auto519[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+290,140,20,vfh[3],27,0,_Context->msg_Auto520[_Context->language],strlen(_Context->msg_Auto520[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+110,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+110+1,528,16,vfh[1],27,28,_Context->buffer_HTML_TITLE,66,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+140,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+140+1,528,16,vfh[1],27,28,_Context->buffer_HTML_LOGO,66,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+170,528+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+170+1,528,16,vfh[1],27,28,_Context->buffer_HTML_COPYRIGHT,66,0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+200,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+200+1,503,16,vfh[1],27,28,_Context->buffer_SCREEN_CSS,259,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+230,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+230+1,503,16,vfh[1],27,28,_Context->buffer_PRINT_CSS,259,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+260,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+260+1,503,16,vfh[1],27,28,_Context->buffer_NAVIGATOR,255,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),0);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+290,503+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+290+1,503,16,vfh[1],27,28,_Context->buffer_DOCPATH,255,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_Printing=visual_trigger_code(_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]),479,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]),479,0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+110,154,20,vfh[3],27,0,_Context->msg_Auto521[_Context->language],strlen(_Context->msg_Auto521[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+150,154,20,vfh[3],27,0,_Context->msg_Auto522[_Context->language],strlen(_Context->msg_Auto522[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto459+440,_Context->y_Auto459+150,154,20,vfh[3],27,0,_Context->msg_Auto523[_Context->language],strlen(_Context->msg_Auto523[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto459+40,_Context->y_Auto459+190,154,20,vfh[3],27,0,_Context->msg_Auto524[_Context->language],strlen(_Context->msg_Auto524[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto459+440,_Context->y_Auto459+190,154,20,vfh[3],27,0,_Context->msg_Auto525[_Context->language],strlen(_Context->msg_Auto525[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto459+200,_Context->y_Auto459+110,504+2,16+2,5);
	visual_text(_Context->x_Auto459+200+1,_Context->y_Auto459+110+1,504,16,vfh[1],27,28,_Context->buffer_PRINTER,259,0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto459+590,_Context->y_Auto459+150,152,48,vfh[1],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto459+200,_Context->y_Auto459+190,144,48,vfh[1],0,0,parse_selection(_Context->msg_LAYOUT[_Context->language],&_Context->value_LAYOUT),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto459+590,_Context->y_Auto459+190,152,48,vfh[1],27,0,parse_selection(_Context->msg_PAGEFEED[_Context->language],&_Context->value_PAGEFEED),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto459+200,_Context->y_Auto459+150,144,64,vfh[1],27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),768);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_Editor=visual_trigger_code(_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]),581,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]),581,0);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+120,140,20,vfh[3],27,0,_Context->msg_Auto526[_Context->language],strlen(_Context->msg_Auto526[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+170,140,20,vfh[3],27,0,_Context->msg_Auto527[_Context->language],strlen(_Context->msg_Auto527[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+230,690,16,vfh[2],27,0,_Context->msg_Auto528[_Context->language],strlen(_Context->msg_Auto528[_Context->language]),2);
	visual_frame(_Context->x_Auto459+50,_Context->y_Auto459+246,690,74,4);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto459+220,_Context->y_Auto459+120,496+2,16+2,5);
	visual_text(_Context->x_Auto459+220+1,_Context->y_Auto459+120+1,496,16,vfh[1],27,28,_Context->buffer_AED,255,0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),0);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto459+220,_Context->y_Auto459+170,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_AED_STATE=visual_trigger_code(_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]));
	visual_check(_Context->x_Auto459+90,_Context->y_Auto459+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),_Context->value_AED_STATE|0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_AED_SYNTAX=visual_trigger_code(_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]));
	visual_check(_Context->x_Auto459+340,_Context->y_Auto459+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),_Context->value_AED_SYNTAX|0);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+60,_Context->y_Auto459+260,126,16,vfh[2],27,0,_Context->msg_auto6060[_Context->language],strlen(_Context->msg_auto6060[_Context->language]),259);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+200,_Context->y_Auto459+260,112,16,vfh[2],27,0,_Context->msg_auto6061[_Context->language],strlen(_Context->msg_auto6061[_Context->language]),259);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+340,_Context->y_Auto459+260,110,20,vfh[2],27,0,_Context->msg_auto6062[_Context->language],strlen(_Context->msg_auto6062[_Context->language]),259);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+470,_Context->y_Auto459+260,110,20,vfh[2],27,0,_Context->msg_auto6063[_Context->language],strlen(_Context->msg_auto6063[_Context->language]),259);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto459+600,_Context->y_Auto459+260,126,16,vfh[2],27,0,_Context->msg_auto6064[_Context->language],strlen(_Context->msg_auto6064[_Context->language]),259);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto459+60,_Context->y_Auto459+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),768);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto459+200,_Context->y_Auto459+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),768);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto459+470,_Context->y_Auto459+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),768);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto459+340,_Context->y_Auto459+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),768);
		}
	if (_Context->page_number == 8 ) {
	visual_select(_Context->x_Auto459+600,_Context->y_Auto459+280,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),768);
		}
	_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
	visual_button(_Context->x_Auto459+20,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
	_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
	visual_button(_Context->x_Auto459+120,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
	_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
	visual_button(_Context->x_Auto459+220,_Context->y_Auto459+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),0);
	_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
	visual_button(_Context->x_Auto459+470,_Context->y_Auto459+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),0);
	_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
	visual_button(_Context->x_Auto459+324,_Context->y_Auto459+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
	_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
	visual_button(_Context->x_Auto459+396,_Context->y_Auto459+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
	_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
	visual_button(_Context->x_Auto459+570,_Context->y_Auto459+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
	_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
	visual_button(_Context->x_Auto459+672,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
	if (_Context->page_number == 9 ) {
	_Context->trigger_Project=visual_trigger_code(_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]));
	visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]),662,2);
	} else {
		visual_tabpage(_Context->x_Auto459+20,_Context->y_Auto459+40,750,500,vfh[2],_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]),662,0);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+120,140,20,vfh[3],27,0,_Context->msg_Auto529[_Context->language],strlen(_Context->msg_Auto529[_Context->language]),2);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+150,161,20,vfh[3],27,0,_Context->msg_Auto530[_Context->language],strlen(_Context->msg_Auto530[_Context->language]),2);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+180,161,20,vfh[3],27,0,_Context->msg_Auto531[_Context->language],strlen(_Context->msg_Auto531[_Context->language]),2);
		}
	if (_Context->page_number == 9 ) {
	visual_text(_Context->x_Auto459+50,_Context->y_Auto459+210,161,20,vfh[3],27,0,_Context->msg_Auto532[_Context->language],strlen(_Context->msg_Auto532[_Context->language]),2);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto459+220,_Context->y_Auto459+120,496+2,16+2,5);
	visual_text(_Context->x_Auto459+220+1,_Context->y_Auto459+120+1,496,16,vfh[1],27,28,_Context->buffer_AMAKE,255,0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto459+220,_Context->y_Auto459+150,528+2,16+2,5);
	visual_text(_Context->x_Auto459+220+1,_Context->y_Auto459+150+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE_OPTIONS,255,0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto459+220,_Context->y_Auto459+180,528+2,16+2,5);
	visual_text(_Context->x_Auto459+220+1,_Context->y_Auto459+180+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE_DEFINE,255,0);
		}
	if (_Context->page_number == 9 ) {
	visual_frame(_Context->x_Auto459+220,_Context->y_Auto459+210,496+2,16+2,5);
	visual_text(_Context->x_Auto459+220+1,_Context->y_Auto459+210+1,496,16,vfh[1],27,28,_Context->buffer_AMAKE_LIST,255,0);
		}
	if (_Context->page_number == 9 ) {
	_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),0);
		}
	visual_thaw(_Context->x_Auto459,_Context->y_Auto459,790,600);

	return(0);
}

private int General_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This page presents the various parameters controlling the configuration ";
			mptr[1]="operations and runtime animation scripts.   ";
			mptr[2]=" ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FILENAME_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This edit field displays and offers for modification the configuration ";
			mptr[1]="localisation  identifier or name.  ";
			mptr[2]=" ";
			mptr[3]=" The value of this field will be used as the name of the configuration ";
			mptr[4]="file, postfixed with .cfg, by the configuration file operations, load, save and edit. It ";
			mptr[5]="will also be used in the construction of the distinguished name,  ";
			mptr[6]="prefixed with config,  by ldap configuration operations ldap load and ldap save. ";
			mptr[7]="  ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ABALHOST_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This edit field defines the source and target host machine to be used ";
			mptr[1]="for subsequent ldap configuration operations. ";
			mptr[2]=" ";
			mptr[3]=" It receives its initial value at startup from the environment variable ";
			mptr[4]="of the same  name, which when legal and not null, activates ldap configuration ";
			mptr[5]="loading. ";
			mptr[6]=" ";
			mptr[7]="   ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IDENTITY_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This field simply provides an identification string to be displayed ";
			mptr[1]="in the tree view mechanisms simply for configuration recognition purposes. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int REPLAY_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows an animation replay script filename to be defined ";
			mptr[1]="for the automation of a visual applications. For more details concerning ";
			mptr[2]="animation scripts please refer to the document to this effect.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RECORD_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows an animation recording script filename to be ";
			mptr[1]="defined for use by  visual applications. All keyboard and mouse activity ";
			mptr[2]="will be recorded to the  specified file during the execution of the ";
			mptr[3]="application.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Abal_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This page presents the default values of the collection of parameters ";
			mptr[1]="controlling  ABAL source translation, object module linking, program ";
			mptr[2]="execution and debugging.  ";
			mptr[3]=" ";
			mptr[4]="     ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ATR_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This field defines the default full path and file name of the ABAL ";
			mptr[1]="translator to be used for the translation of all standard ABAL syntax ";
			mptr[2]="production streams.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ATR_DEFINE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "In conjuction with the preceeding field this field accepts the various ";
			mptr[1]="command line definitions required for the translation of standard ";
			mptr[2]="ABAL syntax production streams. They should be presented as a space ";
			mptr[3]="or comma separated list of definition names or  definition name=value ";
			mptr[4]="pairs. The list will be parsed to generate the standard abal  definition ";
			mptr[5]="command line syntax.     ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ATR_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows a space or comma separated list of include ";
			mptr[1]="paths to  be defined for the localisation of incluse files during ";
			mptr[2]="the translation operation. The list will be parsed to generate the ";
			mptr[3]="standard abal command line syntax. The defined order of the various ";
			mptr[4]="paths will be respected.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ATR_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This field allows default values to be specified for the command line ";
			mptr[1]="switchs  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" O when activated this will inhibit optimisation of the generated tcode. ";
			mptr[5]=" ";
			mptr[6]=" M when activated causes generation of symbolic information for debug. ";
			mptr[7]="  ";
			mptr[8]=" V Activates verbose messages displayed to the system text screen.  ";
			mptr[9]=" T Activate error tracing using the internal error tracing mechanisms. ";
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

private int ALD_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This will provides the full path and file name of the module linker ";
			mptr[1]="to be used for of programs, resulting from standard ABAL syntax translation, ";
			mptr[2]="and requiring  to be linked with object modules for the production ";
			mptr[3]="of their executable result.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ALD_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows a collection of search path components to be defined ";
			mptr[1]="for the localisation of object modules.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ALD_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This field allows the default values of the various linker option ";
			mptr[1]="switchs to be defined.  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" M this option activates inclusion of modular symbolic information in ";
			mptr[5]="the  final program.  ";
			mptr[6]=" V controls display of informational messages to the system text screen. ";
			mptr[7]=" ";
			mptr[8]=" S controls display of source phase tracing messages to the system text ";
			mptr[9]="screen.  ";
			mptr[10]=" T controls display of target phase tracing messages to the system text ";
			mptr[11]="screen.   ";
			mptr[12]=" ";
			mptr[13]="   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OTR_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "As for the ATR field above, this field allows the full path and file ";
			mptr[1]="name of the translator to be used for the translation of ABAL++ class ";
			mptr[2]="syntax production streams.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OTR_DEFINE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This fields allows for the specification of control definitions for ";
			mptr[1]="the translation of class object production streams.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OTR_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "In an identical fashion to the standard ABAL INCLUDE above, this field ";
			mptr[1]="allows  the list of search paths to be specified for included files. ";
			mptr[2]="It will also be used as a base for the library search path for object ";
			mptr[3]="libraries.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OTR_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This field allows definition of the default values of the command ";
			mptr[1]="line switchs defined above concerning the standard ABAL syntax translation ";
			mptr[2]="values.    ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OLD_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field allows the full path and filename of the object module ";
			mptr[1]="linker to be defined for programs resulting from the class object ";
			mptr[2]="production streams.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OLD_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows a collection of search path components to be defined ";
			mptr[1]="for the localisation of object modules.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int OLD_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the object linker command line switch default ";
			mptr[1]="values to be defined.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EXA_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field allows the full path and filename of the ABAL runtime ";
			mptr[1]="or executer to be defined.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EXADB_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field accepts the definition of the fill path and filename ";
			mptr[1]="of the ABAL debug utility to be used for the debug of visual programs. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Cpp_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This page presents the default values of the collection of parameters ";
			mptr[1]="controlling  ABAL source translation, object module linking, program ";
			mptr[2]="execution and debugging.  ";
			mptr[3]=" ";
			mptr[4]="     ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CPP_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This field defines the default full path and file name of the ABAL ";
			mptr[1]="translator to be used for the translation of all standard ABAL syntax ";
			mptr[2]="production streams.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CPP_DEFINE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "In conjuction with the preceeding field this field accepts the various ";
			mptr[1]="command line definitions required for the translation of standard ";
			mptr[2]="ABAL syntax production streams. They should be presented as a space ";
			mptr[3]="or comma separated list of definition names or  definition name=value ";
			mptr[4]="pairs. The list will be parsed to generate the standard abal  definition ";
			mptr[5]="command line syntax.     ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CPP_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows a space or comma separated list of include ";
			mptr[1]="paths to  be defined for the localisation of incluse files during ";
			mptr[2]="the translation operation. The list will be parsed to generate the ";
			mptr[3]="standard abal command line syntax. The defined order of the various ";
			mptr[4]="paths will be respected.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CPP_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This field allows default values to be specified for the command line ";
			mptr[1]="switchs  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" O when activated this will inhibit optimisation of the generated tcode. ";
			mptr[5]=" ";
			mptr[6]=" M when activated causes generation of symbolic information for debug. ";
			mptr[7]="  ";
			mptr[8]=" V Activates verbose messages displayed to the system text screen.  ";
			mptr[9]=" T Activate error tracing using the internal error tracing mechanisms. ";
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

private int LPP_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This will provides the full path and file name of the module linker ";
			mptr[1]="to be used for of programs, resulting from standard ABAL syntax translation, ";
			mptr[2]="and requiring  to be linked with object modules for the production ";
			mptr[3]="of their executable result.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LPP_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows a collection of search path components to be defined ";
			mptr[1]="for the localisation of object modules.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LPP_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This field allows the default values of the various linker option ";
			mptr[1]="switchs to be defined.  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" M this option activates inclusion of modular symbolic information in ";
			mptr[5]="the  final program.  ";
			mptr[6]=" V controls display of informational messages to the system text screen. ";
			mptr[7]=" ";
			mptr[8]=" S controls display of source phase tracing messages to the system text ";
			mptr[9]="screen.  ";
			mptr[10]=" T controls display of target phase tracing messages to the system text ";
			mptr[11]="screen.   ";
			mptr[12]=" ";
			mptr[13]="   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LPP_LIBRARY_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This field allows the default values of the various linker option ";
			mptr[1]="switchs to be defined.  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" M this option activates inclusion of modular symbolic information in ";
			mptr[5]="the  final program.  ";
			mptr[6]=" V controls display of informational messages to the system text screen. ";
			mptr[7]=" ";
			mptr[8]=" S controls display of source phase tracing messages to the system text ";
			mptr[9]="screen.  ";
			mptr[10]=" T controls display of target phase tracing messages to the system text ";
			mptr[11]="screen.   ";
			mptr[12]=" ";
			mptr[13]="   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DLLCPP_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This field defines the default full path and file name of the ABAL ";
			mptr[1]="translator to be used for the translation of all standard ABAL syntax ";
			mptr[2]="production streams.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DLLCPP_DEFINE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "In conjuction with the preceeding field this field accepts the various ";
			mptr[1]="command line definitions required for the translation of standard ";
			mptr[2]="ABAL syntax production streams. They should be presented as a space ";
			mptr[3]="or comma separated list of definition names or  definition name=value ";
			mptr[4]="pairs. The list will be parsed to generate the standard abal  definition ";
			mptr[5]="command line syntax.     ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DLLCPP_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows a space or comma separated list of include ";
			mptr[1]="paths to  be defined for the localisation of incluse files during ";
			mptr[2]="the translation operation. The list will be parsed to generate the ";
			mptr[3]="standard abal command line syntax. The defined order of the various ";
			mptr[4]="paths will be respected.  ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DLLCPP_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[13];
			mptr[0] = "This field allows default values to be specified for the command line ";
			mptr[1]="switchs  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" O when activated this will inhibit optimisation of the generated tcode. ";
			mptr[5]=" ";
			mptr[6]=" M when activated causes generation of symbolic information for debug. ";
			mptr[7]="  ";
			mptr[8]=" V Activates verbose messages displayed to the system text screen.  ";
			mptr[9]=" T Activate error tracing using the internal error tracing mechanisms. ";
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

private int DLLLPP_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This will provides the full path and file name of the module linker ";
			mptr[1]="to be used for of programs, resulting from standard ABAL syntax translation, ";
			mptr[2]="and requiring  to be linked with object modules for the production ";
			mptr[3]="of their executable result.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DLLLPP_INCLUDE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This field allows a collection of search path components to be defined ";
			mptr[1]="for the localisation of object modules.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DLLLPP_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This field allows the default values of the various linker option ";
			mptr[1]="switchs to be defined.  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" M this option activates inclusion of modular symbolic information in ";
			mptr[5]="the  final program.  ";
			mptr[6]=" V controls display of informational messages to the system text screen. ";
			mptr[7]=" ";
			mptr[8]=" S controls display of source phase tracing messages to the system text ";
			mptr[9]="screen.  ";
			mptr[10]=" T controls display of target phase tracing messages to the system text ";
			mptr[11]="screen.   ";
			mptr[12]=" ";
			mptr[13]="   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DLLLPP_LIBRARY_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This field allows the default values of the various linker option ";
			mptr[1]="switchs to be defined.  ";
			mptr[2]=" ";
			mptr[3]="   ";
			mptr[4]=" M this option activates inclusion of modular symbolic information in ";
			mptr[5]="the  final program.  ";
			mptr[6]=" V controls display of informational messages to the system text screen. ";
			mptr[7]=" ";
			mptr[8]=" S controls display of source phase tracing messages to the system text ";
			mptr[9]="screen.  ";
			mptr[10]=" T controls display of target phase tracing messages to the system text ";
			mptr[11]="screen.   ";
			mptr[12]=" ";
			mptr[13]="   ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Images_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This page provides the collection of parameters to be used by the ";
			mptr[1]="visual subsystem for the retrieval of images, definition of colours ";
			mptr[2]="and other widget oriented options.  ";
			mptr[3]=" ";
			mptr[4]="   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int IMAGEPATH_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows definition of the space or comma separated ";
			mptr[1]="list of search paths to be used for the localisation of the various ";
			mptr[2]="image files required by the visual tools and visual applications. ";
			mptr[3]="The image file search mechanisms will respect the order defined by ";
			mptr[4]="this value.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ICONPATH_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field defines the single icon image search path as used ";
			mptr[1]="by the visual tools for the retrieval of the various icon image files. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PALETTE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = "This edit field defines the full path and file name of the colour ";
			mptr[1]="map palette to be loaded and used for the definition of the 256 colours ";
			mptr[2]="of the graphical subsystem. These palettes are a PROLOGUE standard ";
			mptr[3]="derivation of the standard GIF palette. The first 16 colours are reserved ";
			mptr[4]="for use by the standard ABAL and CICO colour  instructions, the 16 ";
			mptr[5]="colours which follow are reserved for use by the visual  user interface ";
			mptr[6]="mechanisms affording a high degree of colour conformity accross the ";
			mptr[7]="range of visual widgets. The remaining colours are the standand values ";
			mptr[8]="of the  internationl JPEG/GIF 256 colour map palette.      ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SKIN_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows the full path and file name of an image to ";
			mptr[1]="be used for  surface tiling to be defined. Surface tiling implies ";
			mptr[2]="the horizontal and vertical repetition of a smaller image unit in ";
			mptr[3]="order to cover the entire surface with a  consistant texture.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TRIGGER_STYLE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This select control allows the default trigger value to de selected. ";
			mptr[1]="Trigger components, tab pages, buttons check boxs and radio buttons, ";
			mptr[2]="may specify an ALT key trigger by prefixing the corresponding character ";
			mptr[3]="of their label by the ampersand character. The trigger component may ";
			mptr[4]="specify the trigger character display format by setting either of ";
			mptr[5]="the BOLD or UNDERLINE atributs of its option mask parameter. When ";
			mptr[6]="neither is specified the default value provided by this parameter ";
			mptr[7]="will take effect.   ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int TRIGGER_COLOUR_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the colour to be used for default trigger ";
			mptr[1]="display when the trigger format is set to COLOUR.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int STYLEPATH_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows definition of the space or comma separated ";
			mptr[1]="list of search paths to be used for the localisation of the various ";
			mptr[2]="style sheet files required  by the visual tools and visual applications. ";
			mptr[3]="The style file search mechanisms will respect the order defined by ";
			mptr[4]="this value.   ";
			return(visual_online_help(mptr,5));
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

private int COMPONENTPATH_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field allows definition of the space or comma separated ";
			mptr[1]="list of search paths to be used for the localisation of the component ";
			mptr[2]="project xml files required  to be loaded for the current project. ";
			mptr[3]="The component file search mechanisms will respect the order defined ";
			mptr[4]="by this value.   ";
			return(visual_online_help(mptr,5));
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

private int Fonts_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This page presents the collection of default values used by the visual ";
			mptr[1]="font management  subsystem. Values defined here include the font search ";
			mptr[2]="path and the various font file names of the fonts loaded into the ";
			mptr[3]="font slots of the font manager mechanisms.  ";
			mptr[4]=" ";
			mptr[5]="  ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONTPATH_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field defines the search path to be used for all font load ";
			mptr[1]=" and save operations for filenames which do not specify an explisite ";
			mptr[2]="path component.  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT1_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field allows the font file name of the fixed pitch standard ";
			mptr[1]="edit font to be specified. This font is used in all edit fields of ";
			mptr[2]="the visual design tool and should be at most 10 pixels wide by 16 ";
			mptr[3]="pixels. high.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT2_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "This edit field provides the name of the font file loaded into the ";
			mptr[1]="second font slot of the visual design tool font management mechanisms. ";
			mptr[2]="This font is used by the visual design tool for all control widgets, ";
			mptr[3]="menu options, push buttons, tab frames, check boxs and radio buttons. ";
			mptr[4]="It should be a proportional spaced font of varying width somewhere ";
			mptr[5]="between 16 and 24 pixels in height.    ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT3_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field controls the name of the font loaded into the third ";
			mptr[1]="font slot. This should be a proportional spaced font slightly larger ";
			mptr[2]="than  that present in font slot two.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT4_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit defines the filename of the font loaded into slot 4, again ";
			mptr[1]="proportionaly spaced and slight larger than that in slot 3.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT5_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "The file name of the font loaded into slot 5 is defined here. Again ";
			mptr[1]="it should be preoprtionaly spaced and slightly larger than the font ";
			mptr[2]="present in font slot 4.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT6_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field defines the name of the font to be loaded into the ";
			mptr[1]="font slot 6. This is to be largest of the title fonts, being larger ";
			mptr[2]="than the font loaded into slot 5 and as for the others proportional ";
			mptr[3]="spaced.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT7_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field defines the name of the font loaded into font slot ";
			mptr[1]=" 7. This font has no reserved usage and is initially a fixed pitch ";
			mptr[2]="font of 10 pixels wide and 24 pixels high. It provides a larger standard ";
			mptr[3]="edit font for certain applications.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT8_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "The file to be loaded into font slot 8 is defined here. This is reserved ";
			mptr[1]="as the small texts font, used on window buttons for the exit and help ";
			mptr[2]="characters and in other tool icon buttons of the visual design tool. ";
			mptr[3]="It should be as small as possible, by default a font of 4 pixels wide ";
			mptr[4]="by 8 pixels high is loaded.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT9_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field defines the name of the font loaded into font slot ";
			mptr[1]="9, a variation of the font in slot 7, it has no reserved application. ";
			mptr[2]=" ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int FONT10_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field defines the font loaded into font slot 10. This font ";
			mptr[1]="is currently undefined and unused.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Documents_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This page presents the default values of the various parameters involved ";
			mptr[1]="in the  Html Docuement Production mechanisms of the visual design tool.  ";
			mptr[2]=" ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HTML_TITLE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This edit field provides the value of the message to be used in the ";
			mptr[1]="Html Docuement TITLE and page HEADER constructions.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HTML_LOGO_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field defines the name of an image file to be used as the ";
			mptr[1]="document header logo in the document header and table of contents. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int HTML_COPYRIGHT_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field provides a text to be used in the generation of the ";
			mptr[1]="document copyright section, or legal notice, at the foot of each document. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SCREEN_CSS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[7];
			mptr[0] = "This edit field provides the url or file name of the style sheet to ";
			mptr[1]="be referenced by the screen style instructions of the generated document. ";
			mptr[2]=" Style sheets are used in document production allowing full externalisation ";
			mptr[3]="of  all aspects of final document style. ";
			mptr[4]=" For more information to this effect please consult the corresponding ";
			mptr[5]="documents concerning Cascading Style Sheets at the world wide web consortium site. ";
			mptr[6]="    ";
			return(visual_online_help(mptr,7));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PRINT_CSS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This edit field defines the style sheet to be used in the style expressions ";
			mptr[1]="relating to html document printing by the eventual document navigator. ";
			mptr[2]="  ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int NAVIGATOR_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field provides the name and full path name of a system utility ";
			mptr[1]="to be used for Html Document Navigation and Inspection. ";
			mptr[2]=" ";
			mptr[3]=" Under Useit this would be mozilla, and under Twin Server the Twinternet ";
			mptr[4]="Navigator nv.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DOCPATH_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This edit field defines the search path name prefix for all Html docement ";
			mptr[1]="activation operations using the above defined navigator. This may ";
			mptr[2]="equally well be an url of the type http://server/path/ or a simple local directory path prefixed by the ";
			mptr[3]="standard file service prefix file:///.      ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Printing_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This page presents the default values of the various parameters used ";
			mptr[1]="in the production of application component graphical documents.  ";
			mptr[2]=" ";
			mptr[3]="   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PRINTER_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[8];
			mptr[0] = "This edit field defines the full path and filename of the ABAL Overlay ";
			mptr[1]="program to be as the print controller in the production of application ";
			mptr[2]="document components.  ";
			mptr[3]=" ";
			mptr[4]="The sources of the default value program printer.at are supplied in ";
			mptr[5]="the  home abal3 class directory in the form of the class file gprinter.as. This is an ABAL++ Object Overlay Program that may be ";
			mptr[6]="used equally well from  standard ABAL syntax as from ABAL++ Class ";
			mptr[7]="Object production scenarios.    ";
			return(visual_online_help(mptr,8));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PAPERTYPE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This select control allows selection of the paper size from the following ";
			mptr[1]="table of standard values, showing also the total number of dots in ";
			mptr[2]="both horizontal and vertical directions.  ";
			mptr[3]=" ";
			mptr[4]="   ";
			mptr[5]=" PAPER 75 100 150 300 600 1200  ";
			mptr[6]=" A4  ";
			mptr[7]=" A3  ";
			mptr[8]=" A2  ";
			mptr[9]=" A1   ";
			mptr[10]=" ";
			mptr[11]="   ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LAYOUT_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[12];
			mptr[0] = "This select control allows choice of the paper layout or orientation. ";
			mptr[1]=" ";
			mptr[2]="  ";
			mptr[3]=" ";
			mptr[4]="  ";
			mptr[5]="  ";
			mptr[6]=" - Portrait being the standard vertical layout  ";
			mptr[7]=" - Landscape the alternative horizontal layout.  ";
			mptr[8]="  ";
			mptr[9]=" ";
			mptr[10]=" The underlying printer mechanisms will perform the various image ";
			mptr[11]="transformations as required by the value of this parameter.   ";
			return(visual_online_help(mptr,12));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int PAGEFEED_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[15];
			mptr[0] = "This select control allows choice of page feed behaviour. This is ";
			mptr[1]="printer and environment dependant and may chosen from amongst the ";
			mptr[2]="following   ";
			mptr[3]=" ";
			mptr[4]="  ";
			mptr[5]="  ";
			mptr[6]=" - None, no page feed is generated , the printer will eject the page ";
			mptr[7]="when complete.  ";
			mptr[8]=" - Before,a page feed is generated prior to starting page output.  ";
			mptr[9]=" - After,a page feed is required to eject the page when a page of data ";
			mptr[10]="has been sent.  ";
			mptr[11]="  ";
			mptr[12]=" ";
			mptr[13]=" Consultation of the printer manual may be necessary for the choice ";
			mptr[14]="of this parameter.   ";
			return(visual_online_help(mptr,15));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int RESOLUTION_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[15];
			mptr[0] = "This select control provides the default value to be used for application ";
			mptr[1]="document components for their graphical print resolution.   ";
			mptr[2]=" ";
			mptr[3]=" This value is in dots per inch.   ";
			mptr[4]=" ";
			mptr[5]="It defines the overall print density and consequently controls the ";
			mptr[6]="total number of dots available per line and page.  ";
			mptr[7]=" ";
			mptr[8]="This number of dots will be used in conjunction with the actual application ";
			mptr[9]="component width and height, and the paper size parameter, to calculate ";
			mptr[10]="the  most appropriate number of dots or bits to be used to represent ";
			mptr[11]="each source  pixel in the final printed image.  ";
			mptr[12]=" ";
			mptr[13]="The greater the resolution or density, the greater the acuracy of ";
			mptr[14]="the final grey shade or colour scale conversion.     ";
			return(visual_online_help(mptr,15));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Editor_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This page presents the default and current values of the various parameters ";
			mptr[1]="used by the version of the ABAL text editor, aed, internal to the visual design tool.  ";
			mptr[2]=" ";
			mptr[3]="      ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[9];
			mptr[0] = "This edit field defines the full path and filename of the editor to ";
			mptr[1]="use for all source and html text editing operations. ";
			mptr[2]=" ";
			mptr[3]=" If the first character of the string is a ! or exclamation mark, ";
			mptr[4]="the internal ABAL editor will be used for editing purposes. ";
			mptr[5]=" ";
			mptr[6]=" When an external editor is defined for use, under Useit, it will ";
			mptr[7]="be opened in a new  system window and launched with an independant ";
			mptr[8]="system process.   ";
			return(visual_online_help(mptr,9));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_FONT_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This select control allows selection of the font to be used by the ";
			mptr[1]="internal ABAL text editor. The use of fixed pitch fonts is strongly ";
			mptr[2]="recomended.     ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_STATE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This check control when active inhibits the display of the editor ";
			mptr[1]="configuration pannel prior to startup of a text editor operation. ";
			mptr[2]="When unset the control pannel will be presented for configuration ";
			mptr[3]="parameter confirmation.   ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_SYNTAX_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This check control,when set, activates the syntaxical colouration ";
			mptr[1]="of the source during the internal editor operation. When unset, syntaxical ";
			mptr[2]="colouration will be inhibited.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_NORMAL_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "This select control allows selection of the colour to be used by the ";
			mptr[1]="internal ABAL text editor to represent normal text, user defined naming ";
			mptr[2]="tokens for variables, procedures and functions.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_QUOTE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control defines the colour to be used to represent quoted ";
			mptr[1]="string literal values.  ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_COMMENT_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control defines the value to be used to represent language ";
			mptr[1]="dependant commentary blocks.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_KEYWORD_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[14];
			mptr[0] = "This select control defines the colour to be used to represent language ";
			mptr[1]="keywords. ";
			mptr[2]=" ";
			mptr[3]=" The internal ABAL text editor may operate with syntaxical colouration ";
			mptr[4]="for the following source languages :  ";
			mptr[5]=" ";
			mptr[6]=" ";
			mptr[7]=" ";
			mptr[8]=" - ABAL and ABAL++  ";
			mptr[9]=" - C and C++  ";
			mptr[10]=" - HTML  ";
			mptr[11]="  ";
			mptr[12]=" ";
			mptr[13]="  ";
			return(visual_online_help(mptr,14));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AED_PUNCTUATE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[2];
			mptr[0] = "This select control defines the colourto be used to represent standard ";
			mptr[1]="punctuation characters,arithmetical and comparision operators.   ";
			return(visual_online_help(mptr,2));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int ACCEPT_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "By clicking on this button the current values of all configuration ";
			mptr[1]="parameters will be accepted and made available to the visual desing ";
			mptr[2]="tool replacing the current active values prior to termination of the ";
			mptr[3]=" configuration dialog box activity.  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SAVEFILE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "When this push button is actioned the collection of configuration ";
			mptr[1]="parameters will be accepted and written out to the filename  identified ";
			mptr[2]="by the configuration parameter FILENAME of the  first page. ";
			mptr[3]=" ";
			mptr[4]=" Once the file save has completed, control will be returned to the ";
			mptr[5]="configuration dialog box.     ";
			return(visual_online_help(mptr,6));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int SAVELDAP_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[6];
			mptr[0] = "By clicking on this button the current values of the configuration ";
			mptr[1]="parameters will be written to either the LDAP Directory on the network ";
			mptr[2]="host identified by the IP Address taken from the configuration parameter ";
			mptr[3]="ABALHOST, or the system Registry. The value of the field FILENAME ";
			mptr[4]="will be used, prefixed by config , to identify the collection of configuration in the directory. ";
			mptr[5]="  ";
			return(visual_online_help(mptr,6));
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

private int LoadLdap_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This push button provides the complementary action to the Save Ldap ";
			mptr[1]=" or Save Registry push button. with the ABALHOST parameter being used ";
			mptr[2]="to identity, in the case of LDAP usage, the LDAP host. In both cases, ";
			mptr[3]="LDAP and Registry, the FILENAME parameter identifies  the configuration collection.    ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int EDITFILE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this push button is pressed, the file identified by the configuration ";
			mptr[1]="parameter FILENAME will be open using the  standard text editor mechanism for ";
			mptr[2]="inspection and eventual  modification.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int DELETE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "When this push button is pressed, the configuration collection identified ";
			mptr[1]="by the FILENAME parameter will be deleted from the LDAP directory on the ";
			mptr[2]="host defined by the ABALHOST parameter.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int LOADFILE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "Activation of this push button will cause the file identified by the ";
			mptr[1]="configuration paramater FILENAME to loading into the configuration manager and made available ";
			mptr[2]="for inspection and  modification by the configuration dialog box. ";
			mptr[3]="  ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int CANCEL_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[3];
			mptr[0] = "By clicking on this push button any modifications to the  configuration ";
			mptr[1]="parameter set will be discarded prior to leaving the configuration ";
			mptr[2]="dialog box.   ";
			return(visual_online_help(mptr,3));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Project_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[4];
			mptr[0] = "This page presents the default and current values of the various parameters ";
			mptr[1]="used by the ABAL project update tool amake,  ";
			mptr[2]=" ";
			mptr[3]="      ";
			return(visual_online_help(mptr,4));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AMAKE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field defines the full path and filename of the ABAL amake ";
			mptr[1]="utility.  ";
			mptr[2]=" ";
			mptr[3]="This tool will be activated in response to clicking on the Execution ";
			mptr[4]="button of the menu tool bar for any source file item named makefile or with the .mf or .mak file extension.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AMAKE_OPTIONS_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field defines the full path and filename of the ABAL amake ";
			mptr[1]="utility.  ";
			mptr[2]=" ";
			mptr[3]="This tool will be activated in response to clicking on the Execution ";
			mptr[4]="button of the menu tool bar for any source file item named makefile or with the .mf or .mak file extension.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AMAKE_DEFINE_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field defines the full path and filename of the ABAL amake ";
			mptr[1]="utility.  ";
			mptr[2]=" ";
			mptr[3]="This tool will be activated in response to clicking on the Execution ";
			mptr[4]="button of the menu tool bar for any source file item named makefile or with the .mf or .mak file extension.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int AMAKE_LIST_help()
{
	switch (visual_national_language(-1)) {
		case 0 : 
			{
			char * mptr[5];
			mptr[0] = "This edit field defines the full path and filename of the ABAL amake ";
			mptr[1]="utility.  ";
			mptr[2]=" ";
			mptr[3]="This tool will be activated in response to clicking on the Execution ";
			mptr[4]="button of the menu tool bar for any source file item named makefile or with the .mf or .mak file extension.   ";
			return(visual_online_help(mptr,5));
			}
			break;
		default : return(0);
		}
	return(0);
}

private int Auto459action(struct accept_configuration_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_configuration_hide(_Context);

		_Context->x_Auto459 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto459 < 0) { _Context->x_Auto459=0; }
		_Context->y_Auto459 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto459 < 0) { _Context->y_Auto459=0; }
			accept_configuration_show(_Context);

		visual_thaw(_Context->x_Auto459,_Context->y_Auto459,790,600);
		}
	while ((visual_event(1) & _MIMO_UP) != _MIMO_UP);
	return(-1);
}
private int on_ChoixFILENAME_event(struct accept_configuration_context * _Context) {
	char fconf[260];
	strcpy(fconf,_Context->buffer_FILENAME);
	use_file_selector(fconf,WIDGET_FILE_CFG);
	if(strlen(fconf)>0)
	{
	fn_parser(fconf,_Context->buffer_FILENAME,0x000F);
		accept_configuration_show(_Context);
;
	};
	return(-1);
}
private int on_ChoixATR_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_ATR,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixATR_INCLUDE_event(struct accept_configuration_context * _Context) {
	char*message;
	switch(visual_national_language(-1))
	{
	case 1:
	message="Repertoire des fichiers de d‚finition ABAL";
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	message="Directory for the include files";
	break;
	};
	if(ChoixRepPlus(_Context->buffer_ATR_INCLUDE,message))
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixALD_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_ALD,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixALD_INCLUDE_event(struct accept_configuration_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRepPlus(_Context->buffer_ALD_INCLUDE,"Repertoire des fichiers objects ABAL"))
		accept_configuration_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRepPlus(_Context->buffer_ALD_INCLUDE,"Directory for the include objects files"))
		accept_configuration_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixOTR_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_OTR,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixOTR_INCLUDE_event(struct accept_configuration_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRepPlus(_Context->buffer_OTR_INCLUDE,"Repertoire des fichiers de d‚finition ABAL"))
		accept_configuration_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRepPlus(_Context->buffer_OTR_INCLUDE,"Directory for the include files"))
		accept_configuration_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixOLD_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_OLD,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixOLD_INCLUDE_event(struct accept_configuration_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRepPlus(_Context->buffer_OLD_INCLUDE,"Repertoire des fichiers objects ABAL"))
		accept_configuration_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRepPlus(_Context->buffer_OLD_INCLUDE,"Directory for the include objects files"))
		accept_configuration_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixEXA_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_EXA,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixEXADB_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_EXADB,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixCPP_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_CPP,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixCPP_INCLUDE_event(struct accept_configuration_context * _Context) {
	char*message;
	switch(visual_national_language(-1))
	{
	case 1:
	message="Repertoire des fichiers de d‚finition C++";
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	message="Directory for the include files";
	break;
	};
	if(ChoixRepPlus(_Context->buffer_CPP_INCLUDE,message))
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixLPP_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_LPP,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixLPP_INCLUDE_event(struct accept_configuration_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRepPlus(_Context->buffer_LPP_INCLUDE,"Repertoire des fichiers objects C++"))
		accept_configuration_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRepPlus(_Context->buffer_LPP_INCLUDE,"Directory for the include objects files"))
		accept_configuration_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixDLLCPP_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_DLLCPP,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixDLLCPP_INCLUDE_event(struct accept_configuration_context * _Context) {
	char*message;
	switch(visual_national_language(-1))
	{
	case 1:
	message="Repertoire des fichiers de d‚finition C++";
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	message="Directory for the include files";
	break;
	};
	if(ChoixRepPlus(_Context->buffer_DLLCPP_INCLUDE,message))
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixDLLLPP_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_DLLLPP,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixDLLLPP_INCLUDE_event(struct accept_configuration_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRepPlus(_Context->buffer_LPP_INCLUDE,"Repertoire des fichiers objects C++"))
		accept_configuration_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRepPlus(_Context->buffer_DLLLPP_INCLUDE,"Directory for the include objects files"))
		accept_configuration_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixIMAGEPATH_event(struct accept_configuration_context * _Context) {
	int status;/*GWB le 14/09/2006*/
	switch(visual_national_language(-1))
	{
	case 1:
	status=ChoixRep(_Context->buffer_IMAGEPATH,"Repertoire de stockage des images");
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	status=ChoixRep(_Context->buffer_IMAGEPATH,"Directory for the images files");
	break;
	};
	#ifdef WIN32
	if(_Context->buffer_IMAGEPATH[strlen(_Context->buffer_IMAGEPATH)-1]!='\\')
	strcat(_Context->buffer_IMAGEPATH,"\\");
	#else
	if(_Context->buffer_IMAGEPATH[strlen(_Context->buffer_IMAGEPATH)-1]!='/')
	strcat(_Context->buffer_IMAGEPATH,"/");
	#endif
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixICONPATH_event(struct accept_configuration_context * _Context) {
	int status;/*GWB le 14/09/2006*/
	switch(visual_national_language(-1))
	{
	case 1:
	status=ChoixRep(_Context->buffer_ICONPATH,"Repertoire de stockage des images");
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	status=ChoixRep(_Context->buffer_ICONPATH,"Directory for the images files");
	break;
	};
	#ifdef WIN32
	if(_Context->buffer_ICONPATH[strlen(_Context->buffer_ICONPATH)-1]!='\\')
	strcat(_Context->buffer_ICONPATH,"\\");
	#else
	if(_Context->buffer_ICONPATH[strlen(_Context->buffer_ICONPATH)-1]!='/')
	strcat(_Context->buffer_ICONPATH,"/");
	#endif
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixPALETTE_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_PALETTE,WIDGET_FILE_RGB);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixSTYLEPATH_event(struct accept_configuration_context * _Context) {
	int status;/*GWB le 14/09/2006*/
	switch(visual_national_language(-1))
	{
	case 1:
	status=ChoixRep(_Context->buffer_STYLEPATH,"Repertoire de stockage des styles");
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	status=ChoixRep(_Context->buffer_STYLEPATH,"Directory for the style files");
	break;
	};
	#ifdef WIN32
	if(_Context->buffer_STYLEPATH[strlen(_Context->buffer_STYLEPATH)-1]!='\\')
	strcat(_Context->buffer_STYLEPATH,"\\");
	#else
	if(_Context->buffer_STYLEPATH[strlen(_Context->buffer_STYLEPATH)-1]!='/')
	strcat(_Context->buffer_STYLEPATH,"/");
	#endif
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixCOMPPATH_event(struct accept_configuration_context * _Context) {
	int status;
	switch(visual_national_language(-1)){
	case 1:
	status=ChoixRep(_Context->buffer_COMPONENTPATH,"Repertoire de stockage des composants");
	break;
	case 0:
	default:
	status=ChoixRep(_Context->buffer_COMPONENTPATH,"Component search directory");
	break;
	};
	#ifdef WIN32
	if(_Context->buffer_COMPONENTPATH[strlen(_Context->buffer_COMPONENTPATH)-1]!='\\')
	strcat(_Context->buffer_COMPONENTPATH,"\\");
	#else
	if(_Context->buffer_COMPONENTPATH[strlen(_Context->buffer_COMPONENTPATH)-1]!='/')
	strcat(_Context->buffer_COMPONENTPATH,"/");
	#endif
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONTPATH_event(struct accept_configuration_context * _Context) {
	char*message;
	switch(visual_national_language(-1))
	{
	case 1:
	message=allocate_string("Repertoire de stockage des fichiers fontes");
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	message=allocate_string("Directory for the font documents");
	break;
	};
	if(!message)return(-1);
	if(ChoixRep(_Context->buffer_FONTPATH,message))
	{
	liberate(message);
	#ifdef WIN32
	if(_Context->buffer_FONTPATH[strlen(_Context->buffer_FONTPATH)-1]!='\\')
	strcat(_Context->buffer_FONTPATH,"\\");
	#else
	if(_Context->buffer_FONTPATH[strlen(_Context->buffer_FONTPATH)-1]!='/')
	strcat(_Context->buffer_FONTPATH,"/");
	#endif
		accept_configuration_show(_Context);
;
	if(method_is_valid(SingConf->fontpath))
	liberate(SingConf->fontpath);
	SingConf->fontpath=allocate_string(_Context->buffer_FONTPATH);
	};
	return(-1);
}
private int on_ChoixFONT1_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT1,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT2_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT2,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT3_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT3,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT4_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT4,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT5_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT5,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT6_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT6,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT7_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT7,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT8_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT8,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT9_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT9,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixFONT10_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_FONT10,WIDGET_FILE_FMF);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixSCREEN_CSS_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_SCREEN_CSS,WIDGET_FILE_CSS);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixPRINT_CSS_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_PRINT_CSS,WIDGET_FILE_CSS);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixNAVIGATOR_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_NAVIGATOR,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixDOCPATH_event(struct accept_configuration_context * _Context) {
	switch(visual_national_language(-1))
	{
	case 1:
	if(ChoixRep(_Context->buffer_DOCPATH,"Repertoire de stockage des fichiers HTML"))
		accept_configuration_show(_Context);
;
	break;
	case 0:
	default:/*anglais pour les autres langues*/
	if(ChoixRep(_Context->buffer_DOCPATH,"Directory for the HTML documents"))
		accept_configuration_show(_Context);
;
	break;
	};
	return(-1);
}
private int on_ChoixPRINTER_event(struct accept_configuration_context * _Context) {
	extern struct screen_control Context;
	char*sav_context_file_path;
	char atr_path[260];
	sav_context_file_path=Context.file_path[WIDGET_FILE_AT];
	fn_parser(_Context->buffer_EXA,atr_path,7);
	Context.file_path[WIDGET_FILE_AT]=atr_path;
	use_file_selector(_Context->buffer_PRINTER,WIDGET_FILE_AT);
	Context.file_path[WIDGET_FILE_AT]=sav_context_file_path;
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_ChoixAED_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_AED,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
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
private int on_choixAMAKE_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_AMAKE,WIDGET_FILE_EXE);
		accept_configuration_show(_Context);
;
	return(-1);
}
private int on_choixAMAKE_LIST_event(struct accept_configuration_context * _Context) {
	use_file_selector(_Context->buffer_AMAKE_LIST,WIDGET_FILE_ANY);
		accept_configuration_show(_Context);
;
	return(-1);
}


public	int	accept_configuration_event(
struct accept_configuration_context * _Context){
	int	mx,my,mt,mb;
	if (visual_event(1) & _MIMO_ALT) {
		if (((mb = (visual_event(2) & 0x00FF)) >= 'a') && (mb <= 'z')) mb -= ('a' - 'A');
		if (_Context->trigger_General == mb ) return(2);
		if (_Context->trigger_ChoixFILENAME == mb ) return(4);
		if (_Context->trigger_Abal == mb ) return(9);
		if (_Context->trigger_ChoixATR == mb ) return(11);
		if (_Context->trigger_ChoixATR_INCLUDE == mb ) return(14);
		if (_Context->trigger_ChoixALD == mb ) return(17);
		if (_Context->trigger_ChoixALD_INCLUDE == mb ) return(19);
		if (_Context->trigger_ChoixOTR == mb ) return(22);
		if (_Context->trigger_ChoixOTR_INCLUDE == mb ) return(25);
		if (_Context->trigger_ChoixOLD == mb ) return(28);
		if (_Context->trigger_ChoixOLD_INCLUDE == mb ) return(30);
		if (_Context->trigger_ChoixEXA == mb ) return(33);
		if (_Context->trigger_ChoixEXADB == mb ) return(35);
		if (_Context->trigger_Cpp == mb ) return(36);
		if (_Context->trigger_ChoixCPP == mb ) return(38);
		if (_Context->trigger_ChoixCPP_INCLUDE == mb ) return(41);
		if (_Context->trigger_ChoixLPP == mb ) return(44);
		if (_Context->trigger_ChoixLPP_INCLUDE == mb ) return(46);
		if (_Context->trigger_ChoixDLLCPP == mb ) return(50);
		if (_Context->trigger_ChoixDLLCPP_INCLUDE == mb ) return(53);
		if (_Context->trigger_ChoixDLLLPP == mb ) return(56);
		if (_Context->trigger_ChoixDLLLPP_INCLUDE == mb ) return(58);
		if (_Context->trigger_Images == mb ) return(61);
		if (_Context->trigger_ChoixIMAGEPATH == mb ) return(63);
		if (_Context->trigger_ChoixICONPATH == mb ) return(65);
		if (_Context->trigger_ChoixPALETTE == mb ) return(67);
		if (_Context->trigger_ChoixSTYLEPATH == mb ) return(73);
		if (_Context->trigger_ChoixCOMPPATH == mb ) return(74);
		if (_Context->trigger_Fonts == mb ) return(75);
		if (_Context->trigger_ChoixFONTPATH == mb ) return(87);
		if (_Context->trigger_ChoixFONT1 == mb ) return(89);
		if (_Context->trigger_ChoixFONT2 == mb ) return(91);
		if (_Context->trigger_ChoixFONT3 == mb ) return(93);
		if (_Context->trigger_ChoixFONT4 == mb ) return(95);
		if (_Context->trigger_ChoixFONT5 == mb ) return(97);
		if (_Context->trigger_ChoixFONT6 == mb ) return(99);
		if (_Context->trigger_ChoixFONT7 == mb ) return(101);
		if (_Context->trigger_ChoixFONT8 == mb ) return(103);
		if (_Context->trigger_ChoixFONT9 == mb ) return(105);
		if (_Context->trigger_ChoixFONT10 == mb ) return(107);
		if (_Context->trigger_Documents == mb ) return(108);
		if (_Context->trigger_ChoixSCREEN_CSS == mb ) return(113);
		if (_Context->trigger_ChoixPRINT_CSS == mb ) return(115);
		if (_Context->trigger_ChoixNAVIGATOR == mb ) return(117);
		if (_Context->trigger_ChoixDOCPATH == mb ) return(119);
		if (_Context->trigger_Printing == mb ) return(120);
		if (_Context->trigger_ChoixPRINTER == mb ) return(122);
		if (_Context->trigger_Editor == mb ) return(127);
		if (_Context->trigger_ChoixAED == mb ) return(129);
		if (_Context->trigger_AED_STATE == mb ) return(131);
		if (_Context->trigger_AED_SYNTAX == mb ) return(132);
		if (_Context->trigger_ACCEPT == mb ) return(138);
		if (_Context->trigger_SAVEFILE == mb ) return(139);
		if (_Context->trigger_SAVELDAP == mb ) return(140);
		if (_Context->trigger_LoadLdap == mb ) return(141);
		if (_Context->trigger_EDITFILE == mb ) return(142);
		if (_Context->trigger_DELETE == mb ) return(143);
		if (_Context->trigger_LOADFILE == mb ) return(144);
		if (_Context->trigger_CANCEL == mb ) return(145);
		if (_Context->trigger_Project == mb ) return(146);
		if (_Context->trigger_choixAMAKE == mb ) return(148);
		if (_Context->trigger_choixAMAKE_LIST == mb ) return(152);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto459+769) )  
	&&  (my >= (_Context->y_Auto459+4) )  
	&&  (mx <= (_Context->x_Auto459+786) )  
	&&  (my <= (_Context->y_Auto459+20) )) {
		return(1);	/* Auto459 */

		}
	if ((mx >= (_Context->x_Auto459+753) )  
	&&  (my >= (_Context->y_Auto459+4) )  
	&&  (mx <= (_Context->x_Auto459+770) )  
	&&  (my <= (_Context->y_Auto459+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrefer.htm");
			};
		return(-1);	/* Auto459 */

		}
	if ((mx >= (_Context->x_Auto459+737) )  
	&&  (my >= (_Context->y_Auto459+4) )  
	&&  (mx <= (_Context->x_Auto459+754) )  
	&&  (my <= (_Context->y_Auto459+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_configuration_show(_Context);
		return(-1);	/* Auto459 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto459+4) )  
		&&  (my >= (_Context->y_Auto459+4) )  
		&&  (mx <= (_Context->x_Auto459+722) )  
		&&  (my <= (_Context->y_Auto459+20) )) {
			return( Auto459action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+0) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+83) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(2); /* General */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+150) ) 
		&&  ( mx <= (_Context->x_Auto459+210+493) ) 
		&&  ( my <= (_Context->y_Auto459+150+16))) {
			return(3); /* FILENAME */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+150) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+150+18))) {
			return(4); /* ChoixFILENAME */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+210+520) ) 
		&&  ( my <= (_Context->y_Auto459+180+16))) {
			return(5); /* ABALHOST */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+210) ) 
		&&  ( mx <= (_Context->x_Auto459+210+520) ) 
		&&  ( my <= (_Context->y_Auto459+210+16))) {
			return(6); /* IDENTITY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+250) ) 
		&&  ( mx <= (_Context->x_Auto459+210+520) ) 
		&&  ( my <= (_Context->y_Auto459+250+16))) {
			return(7); /* REPLAY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+210+520) ) 
		&&  ( my <= (_Context->y_Auto459+280+16))) {
			return(8); /* RECORD */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+84) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+149) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(9); /* Abal */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+100) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+100+16))) {
			return(10); /* ATR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+100) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+100+18))) {
			return(11); /* ChoixATR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+120) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+120+16))) {
			return(12); /* ATR_DEFINE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+140) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+140+16))) {
			return(13); /* ATR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+140) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+140+18))) {
			return(14); /* ChoixATR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+160) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+160+16))) {
			return(15); /* ATR_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+180+16))) {
			return(16); /* ALD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+180+18))) {
			return(17); /* ChoixALD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+200) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+200+16))) {
			return(18); /* ALD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+200) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+200+18))) {
			return(19); /* ChoixALD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+220) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+220+16))) {
			return(20); /* ALD_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+280+16))) {
			return(21); /* OTR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+280+18))) {
			return(22); /* ChoixOTR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+300) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+300+16))) {
			return(23); /* OTR_DEFINE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+320) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+320+16))) {
			return(24); /* OTR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+320) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+320+18))) {
			return(25); /* ChoixOTR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+340) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+340+16))) {
			return(26); /* OTR_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+360) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+360+16))) {
			return(27); /* OLD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+360) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+360+18))) {
			return(28); /* ChoixOLD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+380) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+380+16))) {
			return(29); /* OLD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+380) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+380+18))) {
			return(30); /* ChoixOLD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+400) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+400+16))) {
			return(31); /* OLD_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+470) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+470+16))) {
			return(32); /* EXA */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+470) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+470+18))) {
			return(33); /* ChoixEXA */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+490) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+490+16))) {
			return(34); /* EXADB */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+490) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+490+18))) {
			return(35); /* ChoixEXADB */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+150) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+212) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(36); /* Cpp */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+100) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+100+16))) {
			return(37); /* CPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+100) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+100+18))) {
			return(38); /* ChoixCPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+120) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+120+16))) {
			return(39); /* CPP_DEFINE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+140) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+140+16))) {
			return(40); /* CPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+140) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+140+18))) {
			return(41); /* ChoixCPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+160) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+160+16))) {
			return(42); /* CPP_OPTIONS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+180+16))) {
			return(43); /* LPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+180+18))) {
			return(44); /* ChoixLPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+200) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+200+16))) {
			return(45); /* LPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+200) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+200+18))) {
			return(46); /* ChoixLPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+220) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+220+16))) {
			return(47); /* LPP_OPTIONS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+240) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+240+16))) {
			return(48); /* LPP_LIBRARY */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+320) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+320+16))) {
			return(49); /* DLLCPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+320) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+320+18))) {
			return(50); /* ChoixDLLCPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+340) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+340+16))) {
			return(51); /* DLLCPP_DEFINE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+360) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+360+16))) {
			return(52); /* DLLCPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+360) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+360+18))) {
			return(53); /* ChoixDLLCPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+380) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+380+16))) {
			return(54); /* DLLCPP_OPTIONS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+400) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+400+16))) {
			return(55); /* DLLLPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+400) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+400+18))) {
			return(56); /* ChoixDLLLPP */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+420) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+420+16))) {
			return(57); /* DLLLPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+420) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+420+18))) {
			return(58); /* ChoixDLLLPP_INCLUDE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+440) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+440+16))) {
			return(59); /* DLLLPP_OPTIONS */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+460) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+460+16))) {
			return(60); /* DLLLPP_LIBRARY */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+213) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+292) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(61); /* Images */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+110) ) 
		&&  ( mx <= (_Context->x_Auto459+210+519) ) 
		&&  ( my <= (_Context->y_Auto459+110+16))) {
			return(62); /* IMAGEPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+735) ) 
		&&  ( my >= (_Context->y_Auto459+110) ) 
		&&  ( mx <= (_Context->x_Auto459+735+20) ) 
		&&  ( my <= (_Context->y_Auto459+110+18))) {
			return(63); /* ChoixIMAGEPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+140) ) 
		&&  ( mx <= (_Context->x_Auto459+210+519) ) 
		&&  ( my <= (_Context->y_Auto459+140+16))) {
			return(64); /* ICONPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+735) ) 
		&&  ( my >= (_Context->y_Auto459+140) ) 
		&&  ( mx <= (_Context->x_Auto459+735+20) ) 
		&&  ( my <= (_Context->y_Auto459+140+18))) {
			return(65); /* ChoixICONPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+170) ) 
		&&  ( mx <= (_Context->x_Auto459+210+519) ) 
		&&  ( my <= (_Context->y_Auto459+170+16))) {
			return(66); /* PALETTE */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+735) ) 
		&&  ( my >= (_Context->y_Auto459+170) ) 
		&&  ( mx <= (_Context->x_Auto459+735+20) ) 
		&&  ( my <= (_Context->y_Auto459+170+18))) {
			return(67); /* ChoixPALETTE */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+200) ) 
		&&  ( mx <= (_Context->x_Auto459+210+544) ) 
		&&  ( my <= (_Context->y_Auto459+200+15))) {
			return(68); /* SKIN */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+210+0) ) 
		&&  ( my >= (_Context->y_Auto459+230) ) 
		&&  ( mx <= (_Context->x_Auto459+210+184) ) 
		&&  ( my <= (_Context->y_Auto459+230+16))) {
			return(69); /* TRIGGER_STYLE */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+660) ) 
		&&  ( my >= (_Context->y_Auto459+230) ) 
		&&  ( mx <= (_Context->x_Auto459+660+88) ) 
		&&  ( my <= (_Context->y_Auto459+230+16))) {
			return(70); /* TRIGGER_COLOUR */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+260) ) 
		&&  ( mx <= (_Context->x_Auto459+210+520) ) 
		&&  ( my <= (_Context->y_Auto459+260+16))) {
			return(71); /* STYLEPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+210) ) 
		&&  ( my >= (_Context->y_Auto459+290) ) 
		&&  ( mx <= (_Context->x_Auto459+210+520) ) 
		&&  ( my <= (_Context->y_Auto459+290+16))) {
			return(72); /* COMPONENTPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+735) ) 
		&&  ( my >= (_Context->y_Auto459+260) ) 
		&&  ( mx <= (_Context->x_Auto459+735+20) ) 
		&&  ( my <= (_Context->y_Auto459+260+18))) {
			return(73); /* ChoixSTYLEPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto459+735) ) 
		&&  ( my >= (_Context->y_Auto459+289) ) 
		&&  ( mx <= (_Context->x_Auto459+735+20) ) 
		&&  ( my <= (_Context->y_Auto459+289+18))) {
			return(74); /* ChoixCOMPPATH */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+293) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+373) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(75); /* Fonts */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+110) ) 
		&&  ( mx <= (_Context->x_Auto459+200+519) ) 
		&&  ( my <= (_Context->y_Auto459+110+16))) {
			return(76); /* FONTPATH */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+180+16))) {
			return(77); /* FONTLAB1 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+210) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+210+16))) {
			return(78); /* FONTLAB2 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+240) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+240+16))) {
			return(79); /* FONTLAB3 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+270) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+270+16))) {
			return(80); /* FONTLAB4 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+300) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+300+16))) {
			return(81); /* FONTLAB5 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+330) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+330+16))) {
			return(82); /* FONTLAB6 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+360) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+360+16))) {
			return(83); /* FONTLAB7 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+390) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+390+16))) {
			return(84); /* FONTLAB8 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+420) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+420+16))) {
			return(85); /* FONTLAB9 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+50) ) 
		&&  ( my >= (_Context->y_Auto459+450) ) 
		&&  ( mx <= (_Context->x_Auto459+50+144) ) 
		&&  ( my <= (_Context->y_Auto459+450+16))) {
			return(86); /* FONTLAB10 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+725) ) 
		&&  ( my >= (_Context->y_Auto459+110) ) 
		&&  ( mx <= (_Context->x_Auto459+725+20) ) 
		&&  ( my <= (_Context->y_Auto459+110+18))) {
			return(87); /* ChoixFONTPATH */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+180+16))) {
			return(88); /* FONT1 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+180+18))) {
			return(89); /* ChoixFONT1 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+210) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+210+16))) {
			return(90); /* FONT2 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+210) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+210+18))) {
			return(91); /* ChoixFONT2 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+240) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+240+16))) {
			return(92); /* FONT3 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+240) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+240+18))) {
			return(93); /* ChoixFONT3 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+270) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+270+16))) {
			return(94); /* FONT4 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+270) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+270+18))) {
			return(95); /* ChoixFONT4 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+300) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+300+16))) {
			return(96); /* FONT5 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+300) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+300+18))) {
			return(97); /* ChoixFONT5 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+330) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+330+16))) {
			return(98); /* FONT6 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+330) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+330+18))) {
			return(99); /* ChoixFONT6 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+360) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+360+16))) {
			return(100); /* FONT7 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+360) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+360+18))) {
			return(101); /* ChoixFONT7 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+390) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+390+16))) {
			return(102); /* FONT8 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+390) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+390+18))) {
			return(103); /* ChoixFONT8 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+420) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+420+16))) {
			return(104); /* FONT9 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+420) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+420+18))) {
			return(105); /* ChoixFONT9 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+450) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+450+16))) {
			return(106); /* FONT10 */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto459+708) ) 
		&&  ( my >= (_Context->y_Auto459+450) ) 
		&&  ( mx <= (_Context->x_Auto459+708+20) ) 
		&&  ( my <= (_Context->y_Auto459+450+18))) {
			return(107); /* ChoixFONT10 */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+374) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+478) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(108); /* Documents */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+110) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+110+16))) {
			return(109); /* HTML_TITLE */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+140) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+140+16))) {
			return(110); /* HTML_LOGO */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+170) ) 
		&&  ( mx <= (_Context->x_Auto459+200+528) ) 
		&&  ( my <= (_Context->y_Auto459+170+16))) {
			return(111); /* HTML_COPYRIGHT */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+200) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+200+16))) {
			return(112); /* SCREEN_CSS */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+200) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+200+18))) {
			return(113); /* ChoixSCREEN_CSS */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+230) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+230+16))) {
			return(114); /* PRINT_CSS */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+230) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+230+18))) {
			return(115); /* ChoixPRINT_CSS */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+260) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+260+16))) {
			return(116); /* NAVIGATOR */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+260) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+260+18))) {
			return(117); /* ChoixNAVIGATOR */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+290) ) 
		&&  ( mx <= (_Context->x_Auto459+200+503) ) 
		&&  ( my <= (_Context->y_Auto459+290+16))) {
			return(118); /* DOCPATH */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+290) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+290+18))) {
			return(119); /* ChoixDOCPATH */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+479) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+580) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(120); /* Printing */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto459+200) ) 
		&&  ( my >= (_Context->y_Auto459+110) ) 
		&&  ( mx <= (_Context->x_Auto459+200+504) ) 
		&&  ( my <= (_Context->y_Auto459+110+16))) {
			return(121); /* PRINTER */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto459+710) ) 
		&&  ( my >= (_Context->y_Auto459+110) ) 
		&&  ( mx <= (_Context->x_Auto459+710+20) ) 
		&&  ( my <= (_Context->y_Auto459+110+18))) {
			return(122); /* ChoixPRINTER */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto459+590+0) ) 
		&&  ( my >= (_Context->y_Auto459+150) ) 
		&&  ( mx <= (_Context->x_Auto459+590+152) ) 
		&&  ( my <= (_Context->y_Auto459+150+16))) {
			return(123); /* PAPERTYPE */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto459+200+0) ) 
		&&  ( my >= (_Context->y_Auto459+190) ) 
		&&  ( mx <= (_Context->x_Auto459+200+144) ) 
		&&  ( my <= (_Context->y_Auto459+190+16))) {
			return(124); /* LAYOUT */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto459+590+0) ) 
		&&  ( my >= (_Context->y_Auto459+190) ) 
		&&  ( mx <= (_Context->x_Auto459+590+152) ) 
		&&  ( my <= (_Context->y_Auto459+190+16))) {
			return(125); /* PAGEFEED */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto459+200+0) ) 
		&&  ( my >= (_Context->y_Auto459+150) ) 
		&&  ( mx <= (_Context->x_Auto459+200+144) ) 
		&&  ( my <= (_Context->y_Auto459+150+16))) {
			return(126); /* RESOLUTION */
			}
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+581) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+661) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(127); /* Editor */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+220) ) 
		&&  ( my >= (_Context->y_Auto459+120) ) 
		&&  ( mx <= (_Context->x_Auto459+220+496) ) 
		&&  ( my <= (_Context->y_Auto459+120+16))) {
			return(128); /* AED */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+720) ) 
		&&  ( my >= (_Context->y_Auto459+120) ) 
		&&  ( mx <= (_Context->x_Auto459+720+20) ) 
		&&  ( my <= (_Context->y_Auto459+120+18))) {
			return(129); /* ChoixAED */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+220+0) ) 
		&&  ( my >= (_Context->y_Auto459+170) ) 
		&&  ( mx <= (_Context->x_Auto459+220+150) ) 
		&&  ( my <= (_Context->y_Auto459+170+16))) {
			return(130); /* AED_FONT */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+90) ) 
		&&  ( my >= (_Context->y_Auto459+350) ) 
		&&  ( mx <= (_Context->x_Auto459+90+207) ) 
		&&  ( my <= (_Context->y_Auto459+350+20))) {
			return(131); /* AED_STATE */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+340) ) 
		&&  ( my >= (_Context->y_Auto459+350) ) 
		&&  ( mx <= (_Context->x_Auto459+340+207) ) 
		&&  ( my <= (_Context->y_Auto459+350+20))) {
			return(132); /* AED_SYNTAX */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+60+0) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+60+120) ) 
		&&  ( my <= (_Context->y_Auto459+280+16))) {
			return(133); /* AED_NORMAL */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+200+0) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+200+120) ) 
		&&  ( my <= (_Context->y_Auto459+280+16))) {
			return(134); /* AED_QUOTE */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+470+0) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+470+112) ) 
		&&  ( my <= (_Context->y_Auto459+280+16))) {
			return(135); /* AED_COMMENT */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+340+0) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+340+112) ) 
		&&  ( my <= (_Context->y_Auto459+280+16))) {
			return(136); /* AED_KEYWORD */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto459+600+0) ) 
		&&  ( my >= (_Context->y_Auto459+280) ) 
		&&  ( mx <= (_Context->x_Auto459+600+120) ) 
		&&  ( my <= (_Context->y_Auto459+280+16))) {
			return(137); /* AED_PUNCTUATE */
			}
		}
	if (( mx >= (_Context->x_Auto459+20) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+20+98) ) 
	&&  ( my <= (_Context->y_Auto459+550+32))) {
		return(138); /* ACCEPT */
		}
	if (( mx >= (_Context->x_Auto459+120) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+120+98) ) 
	&&  ( my <= (_Context->y_Auto459+550+32))) {
		return(139); /* SAVEFILE */
		}
	if (( mx >= (_Context->x_Auto459+220) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+220+102) ) 
	&&  ( my <= (_Context->y_Auto459+550+33))) {
		return(140); /* SAVELDAP */
		}
	if (( mx >= (_Context->x_Auto459+470) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+470+98) ) 
	&&  ( my <= (_Context->y_Auto459+550+32))) {
		return(141); /* LoadLdap */
		}
	if (( mx >= (_Context->x_Auto459+324) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+324+70) ) 
	&&  ( my <= (_Context->y_Auto459+550+32))) {
		return(142); /* EDITFILE */
		}
	if (( mx >= (_Context->x_Auto459+396) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+396+72) ) 
	&&  ( my <= (_Context->y_Auto459+550+32))) {
		return(143); /* DELETE */
		}
	if (( mx >= (_Context->x_Auto459+570) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+570+100) ) 
	&&  ( my <= (_Context->y_Auto459+550+32))) {
		return(144); /* LOADFILE */
		}
	if (( mx >= (_Context->x_Auto459+672) ) 
	&&  ( my >= (_Context->y_Auto459+550) ) 
	&&  ( mx <= (_Context->x_Auto459+672+98) ) 
	&&  ( my <= (_Context->y_Auto459+550+32))) {
		return(145); /* CANCEL */
		}
	if (_Context->page_number == 9 ) {
	} else {
		if (( mx >= (_Context->x_Auto459+20+662) ) 
		&&  ( my >= (_Context->y_Auto459+40) ) 
		&&  ( mx <= (_Context->x_Auto459+20+744) ) 
		&&  ( my <= (_Context->y_Auto459+40+24))) {
			return(146); /* Project */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto459+220) ) 
		&&  ( my >= (_Context->y_Auto459+120) ) 
		&&  ( mx <= (_Context->x_Auto459+220+496) ) 
		&&  ( my <= (_Context->y_Auto459+120+16))) {
			return(147); /* AMAKE */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto459+720) ) 
		&&  ( my >= (_Context->y_Auto459+120) ) 
		&&  ( mx <= (_Context->x_Auto459+720+20) ) 
		&&  ( my <= (_Context->y_Auto459+120+18))) {
			return(148); /* choixAMAKE */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto459+220) ) 
		&&  ( my >= (_Context->y_Auto459+150) ) 
		&&  ( mx <= (_Context->x_Auto459+220+528) ) 
		&&  ( my <= (_Context->y_Auto459+150+16))) {
			return(149); /* AMAKE_OPTIONS */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto459+220) ) 
		&&  ( my >= (_Context->y_Auto459+180) ) 
		&&  ( mx <= (_Context->x_Auto459+220+528) ) 
		&&  ( my <= (_Context->y_Auto459+180+16))) {
			return(150); /* AMAKE_DEFINE */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto459+220) ) 
		&&  ( my >= (_Context->y_Auto459+210) ) 
		&&  ( mx <= (_Context->x_Auto459+220+496) ) 
		&&  ( my <= (_Context->y_Auto459+210+16))) {
			return(151); /* AMAKE_LIST */
			}
		}
	if (_Context->page_number == 9 ) {
		if (( mx >= (_Context->x_Auto459+720) ) 
		&&  ( my >= (_Context->y_Auto459+210) ) 
		&&  ( mx <= (_Context->x_Auto459+720+20) ) 
		&&  ( my <= (_Context->y_Auto459+210+18))) {
			return(152); /* choixAMAKE_LIST */
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
		case 9 : 
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
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+150+1,493,16,vfh[1],_Context->buffer_FILENAME,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* ChoixFILENAME */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* ABALHOST */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+180+1,520,16,vfh[1],_Context->buffer_ABALHOST,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* IDENTITY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+210+1,520,16,vfh[1],_Context->buffer_IDENTITY,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* REPLAY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+250+1,520,16,vfh[1],_Context->buffer_REPLAY,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* RECORD */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+280+1,520,16,vfh[1],_Context->buffer_RECORD,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x9 :
				/* Abal */
				if (_Context->page_number == 2 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0xa :
				/* ATR */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+100+1,503,16,vfh[1],_Context->buffer_ATR,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* ChoixATR */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* ATR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+120+1,528,16,vfh[1],_Context->buffer_ATR_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* ATR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+140+1,503,16,vfh[1],_Context->buffer_ATR_INCLUDE,1024);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* ChoixATR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* ATR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+160+1,528,16,vfh[1],_Context->buffer_ATR_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* ALD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+180+1,503,16,vfh[1],_Context->buffer_ALD,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* ChoixALD */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* ALD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+200+1,503,16,vfh[1],_Context->buffer_ALD_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* ChoixALD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* ALD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+220+1,528,16,vfh[1],_Context->buffer_ALD_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* OTR */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+280+1,503,16,vfh[1],_Context->buffer_OTR,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* ChoixOTR */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* OTR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+300+1,528,16,vfh[1],_Context->buffer_OTR_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* OTR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+320+1,503,16,vfh[1],_Context->buffer_OTR_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ChoixOTR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* OTR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+340+1,528,16,vfh[1],_Context->buffer_OTR_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* OLD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+360+1,503,16,vfh[1],_Context->buffer_OLD,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* ChoixOLD */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* OLD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+380+1,503,16,vfh[1],_Context->buffer_OLD_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* ChoixOLD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* OLD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+400+1,528,16,vfh[1],_Context->buffer_OLD_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* EXA */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+470+1,503,16,vfh[1],_Context->buffer_EXA,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* ChoixEXA */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* EXADB */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+490+1,503,16,vfh[1],_Context->buffer_EXADB,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* ChoixEXADB */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* Cpp */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x25 :
				/* CPP */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+100+1,503,16,vfh[1],_Context->buffer_CPP,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* ChoixCPP */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixCPP=visual_trigger_code(_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixCPP=visual_trigger_code(_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* CPP_DEFINE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+120+1,528,16,vfh[1],_Context->buffer_CPP_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* CPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+140+1,503,16,vfh[1],_Context->buffer_CPP_INCLUDE,1024);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* ChoixCPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* CPP_OPTIONS */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+160+1,528,16,vfh[1],_Context->buffer_CPP_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* LPP */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+180+1,503,16,vfh[1],_Context->buffer_LPP,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* ChoixLPP */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixLPP=visual_trigger_code(_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixLPP=visual_trigger_code(_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* LPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+200+1,503,16,vfh[1],_Context->buffer_LPP_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* ChoixLPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* LPP_OPTIONS */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+220+1,528,16,vfh[1],_Context->buffer_LPP_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* LPP_LIBRARY */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+240+1,528,16,vfh[1],_Context->buffer_LPP_LIBRARY,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* DLLCPP */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+320+1,503,16,vfh[1],_Context->buffer_DLLCPP,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* ChoixDLLCPP */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixDLLCPP=visual_trigger_code(_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixDLLCPP=visual_trigger_code(_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x33 :
				/* DLLCPP_DEFINE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+340+1,528,16,vfh[1],_Context->buffer_DLLCPP_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* DLLCPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+360+1,503,16,vfh[1],_Context->buffer_DLLCPP_INCLUDE,1024);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* ChoixDLLCPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixDLLCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixDLLCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* DLLCPP_OPTIONS */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+380+1,528,16,vfh[1],_Context->buffer_DLLCPP_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x37 :
				/* DLLLPP */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+400+1,503,16,vfh[1],_Context->buffer_DLLLPP,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x38 :
				/* ChoixDLLLPP */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixDLLLPP=visual_trigger_code(_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+400,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixDLLLPP=visual_trigger_code(_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+400,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x39 :
				/* DLLLPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+420+1,503,16,vfh[1],_Context->buffer_DLLLPP_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3a :
				/* ChoixDLLLPP_INCLUDE */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixDLLLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixDLLLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3b :
				/* DLLLPP_OPTIONS */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+440+1,528,16,vfh[1],_Context->buffer_DLLLPP_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3c :
				/* DLLLPP_LIBRARY */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+460+1,528,16,vfh[1],_Context->buffer_DLLLPP_LIBRARY,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3d :
				/* Images */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x3e :
				/* IMAGEPATH */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+110+1,519,16,vfh[1],_Context->buffer_IMAGEPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3f :
				/* ChoixIMAGEPATH */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
					visual_button(_Context->x_Auto459+735,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x40 :
				/* ICONPATH */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+140+1,519,16,vfh[1],_Context->buffer_ICONPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x41 :
				/* ChoixICONPATH */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
					visual_button(_Context->x_Auto459+735,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x42 :
				/* PALETTE */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+170+1,519,16,vfh[1],_Context->buffer_PALETTE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x43 :
				/* ChoixPALETTE */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
					visual_button(_Context->x_Auto459+735,_Context->y_Auto459+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x44 :
				/* SKIN */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+200+1,544,15,vfh[1],_Context->buffer_SKIN,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x45 :
				/* TRIGGER_STYLE */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+210,_Context->y_Auto459+230,184,80,vfh[1],27,28,parse_selection(_Context->msg_TRIGGER_STYLE[_Context->language],&_Context->value_TRIGGER_STYLE),514);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x46 :
				/* TRIGGER_COLOUR */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+660+1,_Context->y_Auto459+230+1,88,16,vfh[1],_Context->buffer_TRIGGER_COLOUR,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x47 :
				/* STYLEPATH */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+260+1,520,16,vfh[1],_Context->buffer_STYLEPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x48 :
				/* COMPONENTPATH */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+210+1,_Context->y_Auto459+290+1,520,16,vfh[1],_Context->buffer_COMPONENTPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x49 :
				/* ChoixSTYLEPATH */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
					visual_button(_Context->x_Auto459+735,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4a :
				/* ChoixCOMPPATH */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
					visual_button(_Context->x_Auto459+735,_Context->y_Auto459+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4b :
				/* Fonts */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x4c :
				/* FONTPATH */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+110+1,519,16,vfh[1],_Context->buffer_FONTPATH,255);
					/*GWB le 20/06/2006*/
					if(method_is_valid(SingConf->fontpath))
					liberate(SingConf->fontpath);
					SingConf->fontpath=allocate_string(_Context->buffer_FONTPATH);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4d :
				/* FONTLAB1 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+180+1,144,16,vfh[1],_Context->buffer_FONTLAB1,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4e :
				/* FONTLAB2 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+210+1,144,16,vfh[1],_Context->buffer_FONTLAB2,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4f :
				/* FONTLAB3 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+240+1,144,16,vfh[1],_Context->buffer_FONTLAB3,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x50 :
				/* FONTLAB4 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+270+1,144,16,vfh[1],_Context->buffer_FONTLAB4,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x51 :
				/* FONTLAB5 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+300+1,144,16,vfh[1],_Context->buffer_FONTLAB5,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x52 :
				/* FONTLAB6 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+330+1,144,16,vfh[1],_Context->buffer_FONTLAB6,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x53 :
				/* FONTLAB7 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+360+1,144,16,vfh[1],_Context->buffer_FONTLAB7,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x54 :
				/* FONTLAB8 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+390+1,144,16,vfh[1],_Context->buffer_FONTLAB8,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x55 :
				/* FONTLAB9 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+420+1,144,16,vfh[1],_Context->buffer_FONTLAB9,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x56 :
				/* FONTLAB10 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+50+1,_Context->y_Auto459+450+1,144,16,vfh[1],_Context->buffer_FONTLAB10,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x57 :
				/* ChoixFONTPATH */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
					visual_button(_Context->x_Auto459+725,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
	visual_button(_Context->x_Auto459+725,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x58 :
				/* FONT1 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+180+1,503,16,vfh[1],_Context->buffer_FONT1,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x59 :
				/* ChoixFONT1 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5a :
				/* FONT2 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+210+1,503,16,vfh[1],_Context->buffer_FONT2,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5b :
				/* ChoixFONT2 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5c :
				/* FONT3 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+240+1,503,16,vfh[1],_Context->buffer_FONT3,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5d :
				/* ChoixFONT3 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5e :
				/* FONT4 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+270+1,503,16,vfh[1],_Context->buffer_FONT4,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5f :
				/* ChoixFONT4 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x60 :
				/* FONT5 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+300+1,503,16,vfh[1],_Context->buffer_FONT5,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x61 :
				/* ChoixFONT5 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x62 :
				/* FONT6 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+330+1,503,16,vfh[1],_Context->buffer_FONT6,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x63 :
				/* ChoixFONT6 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x64 :
				/* FONT7 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+360+1,503,16,vfh[1],_Context->buffer_FONT7,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x65 :
				/* ChoixFONT7 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x66 :
				/* FONT8 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+390+1,503,16,vfh[1],_Context->buffer_FONT8,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x67 :
				/* ChoixFONT8 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x68 :
				/* FONT9 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+420+1,503,16,vfh[1],_Context->buffer_FONT9,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x69 :
				/* ChoixFONT9 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6a :
				/* FONT10 */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+450+1,503,16,vfh[1],_Context->buffer_FONT10,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6b :
				/* ChoixFONT10 */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
					visual_button(_Context->x_Auto459+708,_Context->y_Auto459+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6c :
				/* Documents */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x6d :
				/* HTML_TITLE */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+110+1,528,16,vfh[1],_Context->buffer_HTML_TITLE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6e :
				/* HTML_LOGO */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+140+1,528,16,vfh[1],_Context->buffer_HTML_LOGO,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6f :
				/* HTML_COPYRIGHT */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+170+1,528,16,vfh[1],_Context->buffer_HTML_COPYRIGHT,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x70 :
				/* SCREEN_CSS */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+200+1,503,16,vfh[1],_Context->buffer_SCREEN_CSS,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x71 :
				/* ChoixSCREEN_CSS */
				if (_Context->page_number == 6 ) {
					_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x72 :
				/* PRINT_CSS */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+230+1,503,16,vfh[1],_Context->buffer_PRINT_CSS,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x73 :
				/* ChoixPRINT_CSS */
				if (_Context->page_number == 6 ) {
					_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x74 :
				/* NAVIGATOR */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+260+1,503,16,vfh[1],_Context->buffer_NAVIGATOR,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x75 :
				/* ChoixNAVIGATOR */
				if (_Context->page_number == 6 ) {
					_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x76 :
				/* DOCPATH */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+290+1,503,16,vfh[1],_Context->buffer_DOCPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x77 :
				/* ChoixDOCPATH */
				if (_Context->page_number == 6 ) {
					_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x78 :
				/* Printing */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x79 :
				/* PRINTER */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+200+1,_Context->y_Auto459+110+1,504,16,vfh[1],_Context->buffer_PRINTER,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7a :
				/* ChoixPRINTER */
				if (_Context->page_number == 7 ) {
					_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
					visual_button(_Context->x_Auto459+710,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7b :
				/* PAPERTYPE */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+590,_Context->y_Auto459+150,152,48,vfh[1],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7c :
				/* LAYOUT */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+200,_Context->y_Auto459+190,144,48,vfh[1],0,0,parse_selection(_Context->msg_LAYOUT[_Context->language],&_Context->value_LAYOUT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7d :
				/* PAGEFEED */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+590,_Context->y_Auto459+190,152,48,vfh[1],27,0,parse_selection(_Context->msg_PAGEFEED[_Context->language],&_Context->value_PAGEFEED),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7e :
				/* RESOLUTION */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+200,_Context->y_Auto459+150,144,64,vfh[1],27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7f :
				/* Editor */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x80 :
				/* AED */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+220+1,_Context->y_Auto459+120+1,496,16,vfh[1],_Context->buffer_AED,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x81 :
				/* ChoixAED */
				if (_Context->page_number == 8 ) {
					_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
					visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x82 :
				/* AED_FONT */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+220,_Context->y_Auto459+170,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x83 :
				/* AED_STATE */
				if (_Context->page_number == 8 ) {
				visual_check(_Context->x_Auto459+90,_Context->y_Auto459+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),(_Context->value_AED_STATE |2));
					_Context->keycode = visual_getch();
					_Context->trigger_AED_STATE=visual_trigger_code(_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]));
	visual_check(_Context->x_Auto459+90,_Context->y_Auto459+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),_Context->value_AED_STATE|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x84 :
				/* AED_SYNTAX */
				if (_Context->page_number == 8 ) {
				visual_check(_Context->x_Auto459+340,_Context->y_Auto459+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),(_Context->value_AED_SYNTAX |2));
					_Context->keycode = visual_getch();
					_Context->trigger_AED_SYNTAX=visual_trigger_code(_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]));
	visual_check(_Context->x_Auto459+340,_Context->y_Auto459+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),_Context->value_AED_SYNTAX|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x85 :
				/* AED_NORMAL */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+60,_Context->y_Auto459+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x86 :
				/* AED_QUOTE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+200,_Context->y_Auto459+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x87 :
				/* AED_COMMENT */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+470,_Context->y_Auto459+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x88 :
				/* AED_KEYWORD */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+340,_Context->y_Auto459+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x89 :
				/* AED_PUNCTUATE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_select(_Context->x_Auto459+600,_Context->y_Auto459+280,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x8a :
				/* ACCEPT */
				_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
				visual_button(_Context->x_Auto459+20,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
	visual_button(_Context->x_Auto459+20,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
				break;
			case	0x8b :
				/* SAVEFILE */
				_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
				visual_button(_Context->x_Auto459+120,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
	visual_button(_Context->x_Auto459+120,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
				break;
			case	0x8c :
				/* SAVELDAP */
				_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
				visual_button(_Context->x_Auto459+220,_Context->y_Auto459+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),2);
				_Context->keycode = visual_getch();
				_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
	visual_button(_Context->x_Auto459+220,_Context->y_Auto459+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),0);
				break;
			case	0x8d :
				/* LoadLdap */
				_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
				visual_button(_Context->x_Auto459+470,_Context->y_Auto459+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),2);
				_Context->keycode = visual_getch();
				_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
	visual_button(_Context->x_Auto459+470,_Context->y_Auto459+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),0);
				break;
			case	0x8e :
				/* EDITFILE */
				_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
				visual_button(_Context->x_Auto459+324,_Context->y_Auto459+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
	visual_button(_Context->x_Auto459+324,_Context->y_Auto459+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
				break;
			case	0x8f :
				/* DELETE */
				_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
				visual_button(_Context->x_Auto459+396,_Context->y_Auto459+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
	visual_button(_Context->x_Auto459+396,_Context->y_Auto459+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
				break;
			case	0x90 :
				/* LOADFILE */
				_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
				visual_button(_Context->x_Auto459+570,_Context->y_Auto459+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
	visual_button(_Context->x_Auto459+570,_Context->y_Auto459+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
				break;
			case	0x91 :
				/* CANCEL */
				_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
				visual_button(_Context->x_Auto459+672,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
	visual_button(_Context->x_Auto459+672,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
				break;
			case	0x92 :
				/* Project */
				if (_Context->page_number == 9 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x93 :
				/* AMAKE */
				if (_Context->page_number == 9 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+220+1,_Context->y_Auto459+120+1,496,16,vfh[1],_Context->buffer_AMAKE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x94 :
				/* choixAMAKE */
				if (_Context->page_number == 9 ) {
					_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
					visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x95 :
				/* AMAKE_OPTIONS */
				if (_Context->page_number == 9 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+220+1,_Context->y_Auto459+150+1,528,16,vfh[1],_Context->buffer_AMAKE_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x96 :
				/* AMAKE_DEFINE */
				if (_Context->page_number == 9 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+220+1,_Context->y_Auto459+180+1,528,16,vfh[1],_Context->buffer_AMAKE_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x97 :
				/* AMAKE_LIST */
				if (_Context->page_number == 9 ) {
					_Context->keycode = visual_edit(_Context->x_Auto459+220+1,_Context->y_Auto459+210+1,496,16,vfh[1],_Context->buffer_AMAKE_LIST,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x98 :
				/* choixAMAKE_LIST */
				if (_Context->page_number == 9 ) {
					_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
					visual_button(_Context->x_Auto459+720,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),0);
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
			_Context->page_number=9;
			_Context->focus_item=152;
			accept_configuration_show(_Context);
			continue;
		case	0x3 :
			accept_configuration_losefocus(_Context);
			if ( _Context->page_number < 9 )
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
			if (( visual_event(1) == _MIMO_DOWN ) && ( visual_event(2) == _MIMO_RIGHT)) {
				switch ((_Context->focus_item = retcode)) {
					case	0x2 :
						if (General_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3 :
						if (FILENAME_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5 :
						if (ABALHOST_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6 :
						if (IDENTITY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7 :
						if (REPLAY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8 :
						if (RECORD_help(_Context) != 0) { continue; }
						else { break; }
					case	0x9 :
						if (Abal_help(_Context) != 0) { continue; }
						else { break; }
					case	0xa :
						if (ATR_help(_Context) != 0) { continue; }
						else { break; }
					case	0xc :
						if (ATR_DEFINE_help(_Context) != 0) { continue; }
						else { break; }
					case	0xd :
						if (ATR_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0xf :
						if (ATR_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x10 :
						if (ALD_help(_Context) != 0) { continue; }
						else { break; }
					case	0x12 :
						if (ALD_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x14 :
						if (ALD_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x15 :
						if (OTR_help(_Context) != 0) { continue; }
						else { break; }
					case	0x17 :
						if (OTR_DEFINE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x18 :
						if (OTR_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1a :
						if (OTR_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1b :
						if (OLD_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1d :
						if (OLD_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x1f :
						if (OLD_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x20 :
						if (EXA_help(_Context) != 0) { continue; }
						else { break; }
					case	0x22 :
						if (EXADB_help(_Context) != 0) { continue; }
						else { break; }
					case	0x24 :
						if (Cpp_help(_Context) != 0) { continue; }
						else { break; }
					case	0x25 :
						if (CPP_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (CPP_DEFINE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x28 :
						if (CPP_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2a :
						if (CPP_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2b :
						if (LPP_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2d :
						if (LPP_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2f :
						if (LPP_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x30 :
						if (LPP_LIBRARY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x31 :
						if (DLLCPP_help(_Context) != 0) { continue; }
						else { break; }
					case	0x33 :
						if (DLLCPP_DEFINE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x34 :
						if (DLLCPP_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x36 :
						if (DLLCPP_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x37 :
						if (DLLLPP_help(_Context) != 0) { continue; }
						else { break; }
					case	0x39 :
						if (DLLLPP_INCLUDE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3b :
						if (DLLLPP_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3c :
						if (DLLLPP_LIBRARY_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3d :
						if (Images_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3e :
						if (IMAGEPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x40 :
						if (ICONPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x42 :
						if (PALETTE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x44 :
						if (SKIN_help(_Context) != 0) { continue; }
						else { break; }
					case	0x45 :
						if (TRIGGER_STYLE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x46 :
						if (TRIGGER_COLOUR_help(_Context) != 0) { continue; }
						else { break; }
					case	0x47 :
						if (STYLEPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x48 :
						if (COMPONENTPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4b :
						if (Fonts_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4c :
						if (FONTPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x58 :
						if (FONT1_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5a :
						if (FONT2_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5c :
						if (FONT3_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5e :
						if (FONT4_help(_Context) != 0) { continue; }
						else { break; }
					case	0x60 :
						if (FONT5_help(_Context) != 0) { continue; }
						else { break; }
					case	0x62 :
						if (FONT6_help(_Context) != 0) { continue; }
						else { break; }
					case	0x64 :
						if (FONT7_help(_Context) != 0) { continue; }
						else { break; }
					case	0x66 :
						if (FONT8_help(_Context) != 0) { continue; }
						else { break; }
					case	0x68 :
						if (FONT9_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6a :
						if (FONT10_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6c :
						if (Documents_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6d :
						if (HTML_TITLE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6e :
						if (HTML_LOGO_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6f :
						if (HTML_COPYRIGHT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x70 :
						if (SCREEN_CSS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x72 :
						if (PRINT_CSS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x74 :
						if (NAVIGATOR_help(_Context) != 0) { continue; }
						else { break; }
					case	0x76 :
						if (DOCPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x78 :
						if (Printing_help(_Context) != 0) { continue; }
						else { break; }
					case	0x79 :
						if (PRINTER_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7b :
						if (PAPERTYPE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7c :
						if (LAYOUT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7d :
						if (PAGEFEED_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7e :
						if (RESOLUTION_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7f :
						if (Editor_help(_Context) != 0) { continue; }
						else { break; }
					case	0x80 :
						if (AED_help(_Context) != 0) { continue; }
						else { break; }
					case	0x82 :
						if (AED_FONT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x83 :
						if (AED_STATE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x84 :
						if (AED_SYNTAX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x85 :
						if (AED_NORMAL_help(_Context) != 0) { continue; }
						else { break; }
					case	0x86 :
						if (AED_QUOTE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x87 :
						if (AED_COMMENT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x88 :
						if (AED_KEYWORD_help(_Context) != 0) { continue; }
						else { break; }
					case	0x89 :
						if (AED_PUNCTUATE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8a :
						if (ACCEPT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8b :
						if (SAVEFILE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8c :
						if (SAVELDAP_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8d :
						if (LoadLdap_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8e :
						if (EDITFILE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x8f :
						if (DELETE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x90 :
						if (LOADFILE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x91 :
						if (CANCEL_help(_Context) != 0) { continue; }
						else { break; }
					case	0x92 :
						if (Project_help(_Context) != 0) { continue; }
						else { break; }
					case	0x93 :
						if (AMAKE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x95 :
						if (AMAKE_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x96 :
						if (AMAKE_DEFINE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x97 :
						if (AMAKE_LIST_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto459 */
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
					/* ChoixFILENAME */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFILENAME_event(_Context)) != -1) break;

						}
					continue;
				case	0x5 :
					/* ABALHOST */
					continue;
				case	0x6 :
					/* IDENTITY */
					continue;
				case	0x7 :
					/* REPLAY */
					continue;
				case	0x8 :
					/* RECORD */
					continue;
				case	0x9 :
					/* Abal */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 2;
						accept_configuration_show(_Context);
						}
					continue;
				case	0xa :
					/* ATR */
					continue;
				case	0xb :
					/* ChoixATR */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixATR_event(_Context)) != -1) break;

						}
					continue;
				case	0xc :
					/* ATR_DEFINE */
					continue;
				case	0xd :
					/* ATR_INCLUDE */
					continue;
				case	0xe :
					/* ChoixATR_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixATR_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0xf :
					/* ATR_OPTIONS */
					continue;
				case	0x10 :
					/* ALD */
					continue;
				case	0x11 :
					/* ChoixALD */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixALD_event(_Context)) != -1) break;

						}
					continue;
				case	0x12 :
					/* ALD_INCLUDE */
					continue;
				case	0x13 :
					/* ChoixALD_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixALD_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0x14 :
					/* ALD_OPTIONS */
					continue;
				case	0x15 :
					/* OTR */
					continue;
				case	0x16 :
					/* ChoixOTR */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixOTR_event(_Context)) != -1) break;

						}
					continue;
				case	0x17 :
					/* OTR_DEFINE */
					continue;
				case	0x18 :
					/* OTR_INCLUDE */
					continue;
				case	0x19 :
					/* ChoixOTR_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixOTR_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0x1a :
					/* OTR_OPTIONS */
					continue;
				case	0x1b :
					/* OLD */
					continue;
				case	0x1c :
					/* ChoixOLD */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixOLD_event(_Context)) != -1) break;

						}
					continue;
				case	0x1d :
					/* OLD_INCLUDE */
					continue;
				case	0x1e :
					/* ChoixOLD_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixOLD_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0x1f :
					/* OLD_OPTIONS */
					continue;
				case	0x20 :
					/* EXA */
					continue;
				case	0x21 :
					/* ChoixEXA */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixEXA_event(_Context)) != -1) break;

						}
					continue;
				case	0x22 :
					/* EXADB */
					continue;
				case	0x23 :
					/* ChoixEXADB */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixEXADB_event(_Context)) != -1) break;

						}
					continue;
				case	0x24 :
					/* Cpp */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 3;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x25 :
					/* CPP */
					continue;
				case	0x26 :
					/* ChoixCPP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixCPP=visual_trigger_code(_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixCPP=visual_trigger_code(_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+100,20,18,vfh[1],27,28,_Context->msg_ChoixCPP[_Context->language],strlen(_Context->msg_ChoixCPP[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixCPP_event(_Context)) != -1) break;

						}
					continue;
				case	0x27 :
					/* CPP_DEFINE */
					continue;
				case	0x28 :
					/* CPP_INCLUDE */
					continue;
				case	0x29 :
					/* ChoixCPP_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixCPP_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixCPP_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0x2a :
					/* CPP_OPTIONS */
					continue;
				case	0x2b :
					/* LPP */
					continue;
				case	0x2c :
					/* ChoixLPP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixLPP=visual_trigger_code(_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixLPP=visual_trigger_code(_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixLPP[_Context->language],strlen(_Context->msg_ChoixLPP[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixLPP_event(_Context)) != -1) break;

						}
					continue;
				case	0x2d :
					/* LPP_INCLUDE */
					continue;
				case	0x2e :
					/* ChoixLPP_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixLPP_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixLPP_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0x2f :
					/* LPP_OPTIONS */
					continue;
				case	0x30 :
					/* LPP_LIBRARY */
					continue;
				case	0x31 :
					/* DLLCPP */
					continue;
				case	0x32 :
					/* ChoixDLLCPP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDLLCPP=visual_trigger_code(_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDLLCPP=visual_trigger_code(_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+320,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP[_Context->language],strlen(_Context->msg_ChoixDLLCPP[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDLLCPP_event(_Context)) != -1) break;

						}
					continue;
				case	0x33 :
					/* DLLCPP_DEFINE */
					continue;
				case	0x34 :
					/* DLLCPP_INCLUDE */
					continue;
				case	0x35 :
					/* ChoixDLLCPP_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDLLCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDLLCPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLCPP_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDLLCPP_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0x36 :
					/* DLLCPP_OPTIONS */
					continue;
				case	0x37 :
					/* DLLLPP */
					continue;
				case	0x38 :
					/* ChoixDLLLPP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDLLLPP=visual_trigger_code(_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+400,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDLLLPP=visual_trigger_code(_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+400,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP[_Context->language],strlen(_Context->msg_ChoixDLLLPP[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDLLLPP_event(_Context)) != -1) break;

						}
					continue;
				case	0x39 :
					/* DLLLPP_INCLUDE */
					continue;
				case	0x3a :
					/* ChoixDLLLPP_INCLUDE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDLLLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDLLLPP_INCLUDE=visual_trigger_code(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language],strlen(_Context->msg_ChoixDLLLPP_INCLUDE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDLLLPP_INCLUDE_event(_Context)) != -1) break;

						}
					continue;
				case	0x3b :
					/* DLLLPP_OPTIONS */
					continue;
				case	0x3c :
					/* DLLLPP_LIBRARY */
					continue;
				case	0x3d :
					/* Images */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 4;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x3e :
					/* IMAGEPATH */
					continue;
				case	0x3f :
					/* ChoixIMAGEPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
						visual_button(_Context->x_Auto459+735,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixIMAGEPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x40 :
					/* ICONPATH */
					continue;
				case	0x41 :
					/* ChoixICONPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
						visual_button(_Context->x_Auto459+735,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixICONPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x42 :
					/* PALETTE */
					continue;
				case	0x43 :
					/* ChoixPALETTE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
						visual_button(_Context->x_Auto459+735,_Context->y_Auto459+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixPALETTE_event(_Context)) != -1) break;

						}
					continue;
				case	0x44 :
					/* SKIN */
					continue;
				case	0x45 :
					/* TRIGGER_STYLE */
					continue;
				case	0x46 :
					/* TRIGGER_COLOUR */
					continue;
				case	0x47 :
					/* STYLEPATH */
					continue;
				case	0x48 :
					/* COMPONENTPATH */
					continue;
				case	0x49 :
					/* ChoixSTYLEPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
						visual_button(_Context->x_Auto459+735,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixSTYLEPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x4a :
					/* ChoixCOMPPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
						visual_button(_Context->x_Auto459+735,_Context->y_Auto459+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
	visual_button(_Context->x_Auto459+735,_Context->y_Auto459+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixCOMPPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x4b :
					/* Fonts */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 5;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x4c :
					/* FONTPATH */
					continue;
				case	0x4d :
					/* FONTLAB1 */
					continue;
				case	0x4e :
					/* FONTLAB2 */
					continue;
				case	0x4f :
					/* FONTLAB3 */
					continue;
				case	0x50 :
					/* FONTLAB4 */
					continue;
				case	0x51 :
					/* FONTLAB5 */
					continue;
				case	0x52 :
					/* FONTLAB6 */
					continue;
				case	0x53 :
					/* FONTLAB7 */
					continue;
				case	0x54 :
					/* FONTLAB8 */
					continue;
				case	0x55 :
					/* FONTLAB9 */
					continue;
				case	0x56 :
					/* FONTLAB10 */
					continue;
				case	0x57 :
					/* ChoixFONTPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
						visual_button(_Context->x_Auto459+725,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
	visual_button(_Context->x_Auto459+725,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONTPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x58 :
					/* FONT1 */
					continue;
				case	0x59 :
					/* ChoixFONT1 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT1_event(_Context)) != -1) break;

						}
					continue;
				case	0x5a :
					/* FONT2 */
					continue;
				case	0x5b :
					/* ChoixFONT2 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT2_event(_Context)) != -1) break;

						}
					continue;
				case	0x5c :
					/* FONT3 */
					continue;
				case	0x5d :
					/* ChoixFONT3 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT3_event(_Context)) != -1) break;

						}
					continue;
				case	0x5e :
					/* FONT4 */
					continue;
				case	0x5f :
					/* ChoixFONT4 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT4_event(_Context)) != -1) break;

						}
					continue;
				case	0x60 :
					/* FONT5 */
					continue;
				case	0x61 :
					/* ChoixFONT5 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT5_event(_Context)) != -1) break;

						}
					continue;
				case	0x62 :
					/* FONT6 */
					continue;
				case	0x63 :
					/* ChoixFONT6 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT6_event(_Context)) != -1) break;

						}
					continue;
				case	0x64 :
					/* FONT7 */
					continue;
				case	0x65 :
					/* ChoixFONT7 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT7_event(_Context)) != -1) break;

						}
					continue;
				case	0x66 :
					/* FONT8 */
					continue;
				case	0x67 :
					/* ChoixFONT8 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT8_event(_Context)) != -1) break;

						}
					continue;
				case	0x68 :
					/* FONT9 */
					continue;
				case	0x69 :
					/* ChoixFONT9 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT9_event(_Context)) != -1) break;

						}
					continue;
				case	0x6a :
					/* FONT10 */
					continue;
				case	0x6b :
					/* ChoixFONT10 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
						visual_button(_Context->x_Auto459+708,_Context->y_Auto459+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
	visual_button(_Context->x_Auto459+708,_Context->y_Auto459+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT10_event(_Context)) != -1) break;

						}
					continue;
				case	0x6c :
					/* Documents */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 6;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x6d :
					/* HTML_TITLE */
					continue;
				case	0x6e :
					/* HTML_LOGO */
					continue;
				case	0x6f :
					/* HTML_COPYRIGHT */
					continue;
				case	0x70 :
					/* SCREEN_CSS */
					continue;
				case	0x71 :
					/* ChoixSCREEN_CSS */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixSCREEN_CSS_event(_Context)) != -1) break;

						}
					continue;
				case	0x72 :
					/* PRINT_CSS */
					continue;
				case	0x73 :
					/* ChoixPRINT_CSS */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixPRINT_CSS_event(_Context)) != -1) break;

						}
					continue;
				case	0x74 :
					/* NAVIGATOR */
					continue;
				case	0x75 :
					/* ChoixNAVIGATOR */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixNAVIGATOR_event(_Context)) != -1) break;

						}
					continue;
				case	0x76 :
					/* DOCPATH */
					continue;
				case	0x77 :
					/* ChoixDOCPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDOCPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x78 :
					/* Printing */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 7;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x79 :
					/* PRINTER */
					continue;
				case	0x7a :
					/* ChoixPRINTER */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
						visual_button(_Context->x_Auto459+710,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
	visual_button(_Context->x_Auto459+710,_Context->y_Auto459+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixPRINTER_event(_Context)) != -1) break;

						}
					continue;
				case	0x7b :
					/* PAPERTYPE */
					continue;
				case	0x7c :
					/* LAYOUT */
					continue;
				case	0x7d :
					/* PAGEFEED */
					continue;
				case	0x7e :
					/* RESOLUTION */
					continue;
				case	0x7f :
					/* Editor */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 8;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x80 :
					/* AED */
					continue;
				case	0x81 :
					/* ChoixAED */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
						visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixAED_event(_Context)) != -1) break;

						}
					continue;
				case	0x82 :
					/* AED_FONT */
					continue;
				case	0x83 :
					/* AED_STATE */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_AED_STATE += 1;
						_Context->value_AED_STATE &= 1;
						}
					continue;
				case	0x84 :
					/* AED_SYNTAX */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_AED_SYNTAX += 1;
						_Context->value_AED_SYNTAX &= 1;
						}
					continue;
				case	0x85 :
					/* AED_NORMAL */
					continue;
				case	0x86 :
					/* AED_QUOTE */
					continue;
				case	0x87 :
					/* AED_COMMENT */
					continue;
				case	0x88 :
					/* AED_KEYWORD */
					continue;
				case	0x89 :
					/* AED_PUNCTUATE */
					continue;
				case	0x8a :
					/* ACCEPT */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
						visual_button(_Context->x_Auto459+20,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
	visual_button(_Context->x_Auto459+20,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ACCEPT_event(_Context)) != -1) break;

						}
					continue;
				case	0x8b :
					/* SAVEFILE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
						visual_button(_Context->x_Auto459+120,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
	visual_button(_Context->x_Auto459+120,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SAVEFILE_event(_Context)) != -1) break;

						}
					continue;
				case	0x8c :
					/* SAVELDAP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
						visual_button(_Context->x_Auto459+220,_Context->y_Auto459+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
	visual_button(_Context->x_Auto459+220,_Context->y_Auto459+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SAVELDAP_event(_Context)) != -1) break;

						}
					continue;
				case	0x8d :
					/* LoadLdap */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
						visual_button(_Context->x_Auto459+470,_Context->y_Auto459+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
	visual_button(_Context->x_Auto459+470,_Context->y_Auto459+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_LoadLdap_event(_Context)) != -1) break;

						}
					continue;
				case	0x8e :
					/* EDITFILE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
						visual_button(_Context->x_Auto459+324,_Context->y_Auto459+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
	visual_button(_Context->x_Auto459+324,_Context->y_Auto459+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EDITFILE_event(_Context)) != -1) break;

						}
					continue;
				case	0x8f :
					/* DELETE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
						visual_button(_Context->x_Auto459+396,_Context->y_Auto459+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
	visual_button(_Context->x_Auto459+396,_Context->y_Auto459+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DELETE_event(_Context)) != -1) break;

						}
					continue;
				case	0x90 :
					/* LOADFILE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
						visual_button(_Context->x_Auto459+570,_Context->y_Auto459+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
	visual_button(_Context->x_Auto459+570,_Context->y_Auto459+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_LOADFILE_event(_Context)) != -1) break;

						}
					continue;
				case	0x91 :
					/* CANCEL */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
						visual_button(_Context->x_Auto459+672,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
	visual_button(_Context->x_Auto459+672,_Context->y_Auto459+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CANCEL_event(_Context)) != -1) break;

						}
					continue;
				case	0x92 :
					/* Project */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 9;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x93 :
					/* AMAKE */
					continue;
				case	0x94 :
					/* choixAMAKE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
						visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_choixAMAKE_event(_Context)) != -1) break;

						}
					continue;
				case	0x95 :
					/* AMAKE_OPTIONS */
					continue;
				case	0x96 :
					/* AMAKE_DEFINE */
					continue;
				case	0x97 :
					/* AMAKE_LIST */
					continue;
				case	0x98 :
					/* choixAMAKE_LIST */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
						visual_button(_Context->x_Auto459+720,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
	visual_button(_Context->x_Auto459+720,_Context->y_Auto459+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_choixAMAKE_LIST_event(_Context)) != -1) break;

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
				_Context->focus_item=152;
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
	char * pALD_INCLUDE,
	char * pALD_OPTIONS,
	char * pOTR,
	char * pOTR_DEFINE,
	char * pOTR_INCLUDE,
	char * pOTR_OPTIONS,
	char * pOLD,
	char * pOLD_INCLUDE,
	char * pOLD_OPTIONS,
	char * pEXA,
	char * pEXADB,
	char * pCPP,
	char * pCPP_DEFINE,
	char * pCPP_INCLUDE,
	char * pCPP_OPTIONS,
	char * pLPP,
	char * pLPP_INCLUDE,
	char * pLPP_OPTIONS,
	char * pLPP_LIBRARY,
	char * pDLLCPP,
	char * pDLLCPP_DEFINE,
	char * pDLLCPP_INCLUDE,
	char * pDLLCPP_OPTIONS,
	char * pDLLLPP,
	char * pDLLLPP_INCLUDE,
	char * pDLLLPP_OPTIONS,
	char * pDLLLPP_LIBRARY,
	char * pIMAGEPATH,
	char * pICONPATH,
	char * pPALETTE,
	char * pSKIN,
	char * pTRIGGER_STYLE,
	char * pTRIGGER_COLOUR,
	char * pSTYLEPATH,
	char * pCOMPONENTPATH,
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
	char * pAED_COMMENT,
	char * pAED_KEYWORD,
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
	 pALD_INCLUDE,
	 pALD_OPTIONS,
	 pOTR,
	 pOTR_DEFINE,
	 pOTR_INCLUDE,
	 pOTR_OPTIONS,
	 pOLD,
	 pOLD_INCLUDE,
	 pOLD_OPTIONS,
	 pEXA,
	 pEXADB,
	 pCPP,
	 pCPP_DEFINE,
	 pCPP_INCLUDE,
	 pCPP_OPTIONS,
	 pLPP,
	 pLPP_INCLUDE,
	 pLPP_OPTIONS,
	 pLPP_LIBRARY,
	 pDLLCPP,
	 pDLLCPP_DEFINE,
	 pDLLCPP_INCLUDE,
	 pDLLCPP_OPTIONS,
	 pDLLLPP,
	 pDLLLPP_INCLUDE,
	 pDLLLPP_OPTIONS,
	 pDLLLPP_LIBRARY,
	 pIMAGEPATH,
	 pICONPATH,
	 pPALETTE,
	 pSKIN,
	 pTRIGGER_STYLE,
	 pTRIGGER_COLOUR,
	 pSTYLEPATH,
	 pCOMPONENTPATH,
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
	 pAED_COMMENT,
	 pAED_KEYWORD,
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
	 pALD_INCLUDE,
	 pALD_OPTIONS,
	 pOTR,
	 pOTR_DEFINE,
	 pOTR_INCLUDE,
	 pOTR_OPTIONS,
	 pOLD,
	 pOLD_INCLUDE,
	 pOLD_OPTIONS,
	 pEXA,
	 pEXADB,
	 pCPP,
	 pCPP_DEFINE,
	 pCPP_INCLUDE,
	 pCPP_OPTIONS,
	 pLPP,
	 pLPP_INCLUDE,
	 pLPP_OPTIONS,
	 pLPP_LIBRARY,
	 pDLLCPP,
	 pDLLCPP_DEFINE,
	 pDLLCPP_INCLUDE,
	 pDLLCPP_OPTIONS,
	 pDLLLPP,
	 pDLLLPP_INCLUDE,
	 pDLLLPP_OPTIONS,
	 pDLLLPP_LIBRARY,
	 pIMAGEPATH,
	 pICONPATH,
	 pPALETTE,
	 pSKIN,
	 pTRIGGER_STYLE,
	 pTRIGGER_COLOUR,
	 pSTYLEPATH,
	 pCOMPONENTPATH,
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
	 pAED_COMMENT,
	 pAED_KEYWORD,
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
