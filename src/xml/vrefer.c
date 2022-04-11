
#ifndef _vrefer_c
#define _vrefer_c
/* ------------------------------------------------------------------------- */
/* Warning : this file has been generated and should not be modified by hand */
/* ------------------------------------------------------------------------- */
/* Sing Version   : 2.2a.0.08                                                */
/* Production     : C                                                        */
/* Project        : vrefer.xml                                               */
/* Target         : vrefer.c                                                 */
/* Identification : 0.0-1334659659-14025.1163                                */
/* ------------------------------------------------------------------------- */

#include <stdio.h>
#include "visual.h"
#include "sing.h"
#include "singconf.h"
#include "singprot.h"
#define en__Auto3584   ""
#define fr__Auto3584   ""
#define it__Auto3584   ""
#define es__Auto3584   ""
#define de__Auto3584   ""
#define nl__Auto3584   ""
#define pt__Auto3584   ""
#define xx__Auto3584   ""
#define en_General   "&General"
#define fr_General   "&G‚n‚ral"
#define it_General   "&General"
#define es_General   "&General"
#define de_General   "&General"
#define nl_General   "&General"
#define pt_General   "&General"
#define xx_General   "&General"
#define en_Auto3585   "General Configuration"
#define fr_Auto3585   "Configuration g‚n‚rale"
#define it_Auto3585   "General Configuration"
#define es_Auto3585   "General Configuration"
#define de_Auto3585   "General Configuration"
#define nl_Auto3585   "General Configuration"
#define pt_Auto3585   "General Configuration"
#define xx_Auto3585   "General Configuration"
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
#define en_Auto3586   "FILENAME"
#define fr_Auto3586   "Nom de fichier"
#define it_Auto3586   "FILENAME"
#define es_Auto3586   "FILENAME"
#define de_Auto3586   "FILENAME"
#define nl_Auto3586   "FILENAME"
#define pt_Auto3586   "FILENAME"
#define xx_Auto3586   "FILENAME"
#define en_Auto3587   "ABALHOST"
#define fr_Auto3587   "ABALHOST"
#define it_Auto3587   "ABALHOST"
#define es_Auto3587   "ABALHOST"
#define de_Auto3587   "ABALHOST"
#define nl_Auto3587   "ABALHOST"
#define pt_Auto3587   "ABALHOST"
#define xx_Auto3587   "ABALHOST"
#define en_Auto3588   "IDENTITY"
#define fr_Auto3588   "Identit‚"
#define it_Auto3588   "IDENTITY"
#define es_Auto3588   "IDENTITY"
#define de_Auto3588   "IDENTITY"
#define nl_Auto3588   "IDENTITY"
#define pt_Auto3588   "IDENTITY"
#define xx_Auto3588   "Ainm"
#define en_Auto3589   "REPLAY"
#define fr_Auto3589   "Refaire"
#define it_Auto3589   "Replay"
#define es_Auto3589   "Replay"
#define de_Auto3589   "Replay"
#define nl_Auto3589   "Replay"
#define pt_Auto3589   "Replay"
#define xx_Auto3589   "Replay"
#define en__Auto3589   ""
#define en_Auto3590   "RECORD"
#define fr_Auto3590   "Enregistrer"
#define it_Auto3590   "RECORD"
#define es_Auto3590   "RECORD"
#define de_Auto3590   "RECORD"
#define nl_Auto3590   "RECORD"
#define pt_Auto3590   "RECORD"
#define xx_Auto3590   "RECORD"
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
#define en_Auto3591   "ABAL"
#define fr_Auto3591   "ABAL"
#define it_Auto3591   "ABAL"
#define es_Auto3591   "ABAL"
#define de_Auto3591   "ABAL"
#define nl_Auto3591   "ABAL"
#define pt_Auto3591   "ABAL"
#define xx_Auto3591   "ABAL"
#define en__Auto3591   ""
#define en_Auto3592   "ATR"
#define fr_Auto3592   "ATR"
#define it_Auto3592   "ATR"
#define es_Auto3592   "ATR"
#define de_Auto3592   "ATR"
#define nl_Auto3592   "ATR"
#define pt_Auto3592   "ATR"
#define xx_Auto3592   "ATR"
#define en_Auto3593   "ATR.DEFINE"
#define fr_Auto3593   "ATR.DEFINE"
#define it_Auto3593   "ATR.DEFINE"
#define es_Auto3593   "ATR.DEFINE"
#define de_Auto3593   "ATR.DEFINE"
#define nl_Auto3593   "ATR.DEFINE"
#define pt_Auto3593   "ATR.DEFINE"
#define xx_Auto3593   "ATR.DEFINE"
#define en_Auto3594   "ATR.INCLUDE"
#define fr_Auto3594   "ATR.INCLUDE"
#define it_Auto3594   "ATR.INCLUDE"
#define es_Auto3594   "ATR.INCLUDE"
#define de_Auto3594   "ATR.INCLUDE"
#define nl_Auto3594   "ATR.INCLUDE"
#define pt_Auto3594   "ATR.INCLUDE"
#define xx_Auto3594   "ATR.INCLUDE"
#define en_Auto3595   "ATR.OPTIONS"
#define fr_Auto3595   "ATR.OPTIONS"
#define it_Auto3595   "ATR.OPTIONS"
#define es_Auto3595   "ATR.OPTIONS"
#define de_Auto3595   "ATR.OPTIONS"
#define nl_Auto3595   "ATR.OPTIONS"
#define pt_Auto3595   "ATR.OPTIONS"
#define xx_Auto3595   "ATR.OPTIONS"
#define en_Auto3596   "ALD.INCLUDE"
#define fr_Auto3596   "ALD.INCLUDE"
#define it_Auto3596   "ALD.INCLUDE"
#define es_Auto3596   "ALD.INCLUDE"
#define de_Auto3596   "ALD.INCLUDE"
#define nl_Auto3596   "ALD.INCLUDE"
#define pt_Auto3596   "ALD.INCLUDE"
#define xx_Auto3596   "ALD.INCLUDE"
#define en__Auto3596   ""
#define fr__Auto3596   ""
#define it__Auto3596   ""
#define es__Auto3596   ""
#define de__Auto3596   ""
#define nl__Auto3596   ""
#define pt__Auto3596   ""
#define xx__Auto3596   ""
#define en_Auto3597   "ALD.OPTIONS"
#define fr_Auto3597   "ALD.OPTIONS"
#define it_Auto3597   "ALD.OPTIONS"
#define es_Auto3597   "ALD.OPTIONS"
#define de_Auto3597   "ALD.OPTIONS"
#define nl_Auto3597   "ALD.OPTIONS"
#define pt_Auto3597   "ALD.OPTIONS"
#define xx_Auto3597   "ALD.OPTIONS"
#define en_Auto3598   "ALD"
#define fr_Auto3598   "ALD"
#define it_Auto3598   "ALD"
#define es_Auto3598   "ALD"
#define de_Auto3598   "ALD"
#define nl_Auto3598   "ALD"
#define pt_Auto3598   "ALD"
#define xx_Auto3598   "ALD"
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
#define en_Auto3599   "ABAL++"
#define fr_Auto3599   "ABAL++"
#define it_Auto3599   "ABAL++"
#define es_Auto3599   "ABAL++"
#define de_Auto3599   "ABAL++"
#define nl_Auto3599   "ABAL++"
#define pt_Auto3599   "ABAL++"
#define xx_Auto3599   "ABAL++"
#define en__Auto3599   ""
#define en_Auto3600   "ABAL and ABAL++"
#define fr_Auto3600   "ABAL et ABAL++"
#define it_Auto3600   "ABAL and ABAL++"
#define es_Auto3600   "ABAL and ABAL++"
#define de_Auto3600   "ABAL und ABAL++"
#define nl_Auto3600   "ABAL and ABAL++"
#define pt_Auto3600   "ABAL and ABAL++"
#define xx_Auto3600   "ABAL and ABAL++"
#define en__Auto3600   ""
#define en_Auto3601   "OTR"
#define fr_Auto3601   "OTR"
#define it_Auto3601   "OTR"
#define es_Auto3601   "OTR"
#define de_Auto3601   "OTR"
#define nl_Auto3601   "OTR"
#define pt_Auto3601   "OTR"
#define xx_Auto3601   "OTR"
#define en_Auto3602   "OTR.DEFINE"
#define fr_Auto3602   "OTR.DEFINE"
#define it_Auto3602   "OTR.DEFINE"
#define es_Auto3602   "OTR.DEFINE"
#define de_Auto3602   "OTR.DEFINE"
#define nl_Auto3602   "OTR.DEFINE"
#define pt_Auto3602   "OTR.DEFINE"
#define xx_Auto3602   "OTR.DEFINE"
#define en_Auto3603   "OTR.INCLUDE"
#define fr_Auto3603   "OTR.INCLUDE"
#define it_Auto3603   "OTR.INCLUDE"
#define es_Auto3603   "OTR.INCLUDE"
#define de_Auto3603   "OTR.INCLUDE"
#define nl_Auto3603   "OTR.INCLUDE"
#define pt_Auto3603   "OTR.INCLUDE"
#define xx_Auto3603   "OTR.INCLUDE"
#define en_Auto3604   "OTR.OPTIONS"
#define fr_Auto3604   "OTR.OPTIONS"
#define it_Auto3604   "OTR.OPTIONS"
#define es_Auto3604   "OTR.OPTIONS"
#define de_Auto3604   "OTR.OPTIONS"
#define nl_Auto3604   "OTR.OPTIONS"
#define pt_Auto3604   "OTR.OPTIONS"
#define xx_Auto3604   "OTR.OPTIONS"
#define en_Auto3605   "OLD.INCLUDE"
#define fr_Auto3605   "OLD.INCLUDE"
#define it_Auto3605   "OLD.INCLUDE"
#define es_Auto3605   "OLD.INCLUDE"
#define de_Auto3605   "OLD.INCLUDE"
#define nl_Auto3605   "OLD.INCLUDE"
#define pt_Auto3605   "OLD.INCLUDE"
#define xx_Auto3605   "OLD.INCLUDE"
#define en__Auto3605   ""
#define fr__Auto3605   ""
#define it__Auto3605   ""
#define es__Auto3605   ""
#define de__Auto3605   ""
#define nl__Auto3605   ""
#define pt__Auto3605   ""
#define xx__Auto3605   ""
#define en_Auto3606   "OLD.OPTIONS"
#define fr_Auto3606   "OLD.OPTIONS"
#define it_Auto3606   "OLD.OPTIONS"
#define es_Auto3606   "OLD.OPTIONS"
#define de_Auto3606   "OLD.OPTIONS"
#define nl_Auto3606   "OLD.OPTIONS"
#define pt_Auto3606   "OLD.OPTIONS"
#define xx_Auto3606   "OLD.OPTIONS"
#define en_Auto3607   "OLD"
#define fr_Auto3607   "OLD"
#define it_Auto3607   "OLD"
#define es_Auto3607   "OLD"
#define de_Auto3607   "OLD"
#define nl_Auto3607   "OLD"
#define pt_Auto3607   "OLD"
#define xx_Auto3607   "OLD"
#define en_Auto3608   "EXA"
#define fr_Auto3608   "EXA"
#define it_Auto3608   "EXA"
#define es_Auto3608   "EXA"
#define de_Auto3608   "EXA"
#define nl_Auto3608   "EXA"
#define pt_Auto3608   "EXA"
#define xx_Auto3608   "EXA"
#define en_Auto3609   "EXADB"
#define fr_Auto3609   "EXADB"
#define it_Auto3609   "EXADB"
#define es_Auto3609   "EXADB"
#define de_Auto3609   "EXADB"
#define nl_Auto3609   "EXADB"
#define pt_Auto3609   "EXADB"
#define xx_Auto3609   "EXADB"
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
#define en_Images   "&Images"
#define fr_Images   "&Images"
#define it_Images   "&Images"
#define es_Images   "&Images"
#define de_Images   "&Images"
#define nl_Images   "&Images"
#define pt_Images   "&Images"
#define xx_Images   "&Images"
#define en__Images   ""
#define en_Auto3610   "IMAGEPATH"
#define fr_Auto3610   "IMAGEPATH"
#define it_Auto3610   "IMAGEPATH"
#define es_Auto3610   "IMAGEPATH"
#define de_Auto3610   "IMAGEPATH"
#define nl_Auto3610   "IMAGEPATH"
#define pt_Auto3610   "IMAGEPATH"
#define xx_Auto3610   "IMAGEPATH"
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
#define en_Auto3611   "ICONPATH"
#define fr_Auto3611   "ICONPATH"
#define it_Auto3611   "ICONPATH"
#define es_Auto3611   "ICONPATH"
#define de_Auto3611   "ICONPATH"
#define nl_Auto3611   "ICONPATH"
#define pt_Auto3611   "ICONPATH"
#define xx_Auto3611   "ICONPATH"
#define en_Auto3612   "PALETTE"
#define fr_Auto3612   "PALETTE"
#define it_Auto3612   "PALETTE"
#define es_Auto3612   "PALETTE"
#define de_Auto3612   "PALETTE"
#define nl_Auto3612   "PALETTE"
#define pt_Auto3612   "PALETTE"
#define xx_Auto3612   "PALETTE"
#define en_Auto3613   "SKIN"
#define fr_Auto3613   "SKIN"
#define it_Auto3613   "SKIN"
#define es_Auto3613   "SKIN"
#define de_Auto3613   "SKIN"
#define nl_Auto3613   "SKIN"
#define pt_Auto3613   "SKIN"
#define xx_Auto3613   "SKIN"
#define en_Auto3614   "TRIGGER.STYLE"
#define fr_Auto3614   "TRIGGER.STYLE"
#define it_Auto3614   "TRIGGER.STYLE"
#define es_Auto3614   "TRIGGER.STYLE"
#define de_Auto3614   "TRIGGER.STYLE"
#define nl_Auto3614   "TRIGGER.STYLE"
#define pt_Auto3614   "TRIGGER.STYLE"
#define xx_Auto3614   "TRIGGER.STYLE"
#define en_Auto3615   "STYLEPATH"
#define fr_Auto3615   "STYLEPATH"
#define it_Auto3615   "STYLEPATH"
#define es_Auto3615   "STYLEPATH"
#define de_Auto3615   "STYLEPATH"
#define nl_Auto3615   "STYLEPATH"
#define pt_Auto3615   "STYLEPATH"
#define xx_Auto3615   "STYLEPATH"
#define en__Auto3615   ""
#define fr__Auto3615   ""
#define it__Auto3615   ""
#define es__Auto3615   ""
#define de__Auto3615   ""
#define nl__Auto3615   ""
#define pt__Auto3615   ""
#define xx__Auto3615   ""
#define en_Auto3616   "COMPONENTPATH"
#define fr_Auto3616   "COMPONENTPATH"
#define it_Auto3616   "COMPONENTPATH"
#define es_Auto3616   "COMPONENTPATH"
#define de_Auto3616   "COMPONENTPATH"
#define nl_Auto3616   "COMPONENTPATH"
#define pt_Auto3616   "COMPONENTPATH"
#define xx_Auto3616   "COMPONENTPATH"
#define en__Auto3616   ""
#define fr__Auto3616   ""
#define it__Auto3616   ""
#define es__Auto3616   ""
#define de__Auto3616   ""
#define nl__Auto3616   ""
#define pt__Auto3616   ""
#define xx__Auto3616   ""
#define en_Auto3617   "TRIGGER.COLOUR"
#define fr_Auto3617   "TRIGGER.COLOUR"
#define it_Auto3617   "TRIGGER.COLOUR"
#define es_Auto3617   "TRIGGER.COLOUR"
#define de_Auto3617   "TRIGGER.COLOUR"
#define nl_Auto3617   "TRIGGER.COLOUR"
#define pt_Auto3617   "TRIGGER.COLOUR"
#define xx_Auto3617   "TRIGGER.COLOUR"
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
#define en_Auto3618   "Font Labels and Filenames"
#define fr_Auto3618   "Noms de Fichiers de polices de caractŠres"
#define it_Auto3618   "Font Filenames"
#define es_Auto3618   "Font Filenames"
#define de_Auto3618   "Font Filenames"
#define nl_Auto3618   "Font Filenames"
#define pt_Auto3618   "Font Filenames"
#define xx_Auto3618   "Font Filenames"
#define en__Auto3618   ""
#define en_Auto3619   "FONTPATH"
#define fr_Auto3619   "FONTPATH"
#define it_Auto3619   "FONTPATH"
#define es_Auto3619   "FONTPATH"
#define de_Auto3619   "FONTPATH"
#define nl_Auto3619   "FONTPATH"
#define pt_Auto3619   "FONTPATH"
#define xx_Auto3619   "FONTPATH"
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
#define en_Auto3620   "Html Document Parameters"
#define fr_Auto3620   "ParamŠtres des documents Html"
#define it_Auto3620   "Html Document Parameters"
#define es_Auto3620   "Html Document Parameters"
#define de_Auto3620   "Html Document Parameters"
#define nl_Auto3620   "Html Document Parameters"
#define pt_Auto3620   "Html Document Parameters"
#define xx_Auto3620   "Html Document Parameters"
#define en__Auto3620   ""
#define en_Auto3621   "HTML.TITLE"
#define fr_Auto3621   "HTML.TITLE"
#define it_Auto3621   "HTML.TITLE"
#define es_Auto3621   "HTML.TITLE"
#define de_Auto3621   "HTML.TITLE"
#define nl_Auto3621   "HTML.TITLE"
#define pt_Auto3621   "HTML.TITLE"
#define xx_Auto3621   "HTML.TITLE"
#define en_Auto3622   "HTML.LOGO"
#define fr_Auto3622   "HTML.LOGO"
#define it_Auto3622   "HTML.LOGO"
#define es_Auto3622   "HTML.LOGO"
#define de_Auto3622   "HTML.LOGO"
#define nl_Auto3622   "HTML.LOGO"
#define pt_Auto3622   "HTML.LOGO"
#define xx_Auto3622   "HTML.LOGO"
#define en_Auto3623   "COPYRIGHT"
#define fr_Auto3623   "COPYRIGHT"
#define it_Auto3623   "COPYRIGHT"
#define es_Auto3623   "COPYRIGHT"
#define de_Auto3623   "COPYRIGHT"
#define nl_Auto3623   "COPYRIGHT"
#define pt_Auto3623   "COPYRIGHT"
#define xx_Auto3623   "COPYRIGHT"
#define en_Auto3624   "SCREEN.CSS"
#define fr_Auto3624   "SCREEN.CSS"
#define it_Auto3624   "SCREEN.CSS"
#define es_Auto3624   "SCREEN.CSS"
#define de_Auto3624   "SCREEN.CSS"
#define nl_Auto3624   "SCREEN.CSS"
#define pt_Auto3624   "SCREEN.CSS"
#define xx_Auto3624   "SCREEN.CSS"
#define en_Auto3625   "PRINT.CSS"
#define fr_Auto3625   "PRINT.CSS"
#define it_Auto3625   "PRINT.CSS"
#define es_Auto3625   "PRINT.CSS"
#define de_Auto3625   "PRINT.CSS"
#define nl_Auto3625   "PRINT.CSS"
#define pt_Auto3625   "PRINT.CSS"
#define xx_Auto3625   "PRINT.CSS"
#define en_Auto3626   "NAVIGATOR"
#define fr_Auto3626   "NAVIGATOR"
#define it_Auto3626   "NAVIGATOR"
#define es_Auto3626   "NAVIGATOR"
#define de_Auto3626   "NAVIGATOR"
#define nl_Auto3626   "NAVIGATOR"
#define pt_Auto3626   "NAVIGATOR"
#define xx_Auto3626   "NAVIGATOR"
#define en_Auto3627   "DOCPATH"
#define fr_Auto3627   "DOCPATH"
#define it_Auto3627   "DOCPATH"
#define es_Auto3627   "DOCPATH"
#define de_Auto3627   "DOCPATH"
#define nl_Auto3627   "DOCPATH"
#define pt_Auto3627   "DOCPATH"
#define xx_Auto3627   "DOCPATH"
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
#define en_Auto3628   "PRINTER"
#define fr_Auto3628   "PRINTER"
#define it_Auto3628   "PRINTER"
#define es_Auto3628   "PRINTER"
#define de_Auto3628   "PRINTER"
#define nl_Auto3628   "PRINTER"
#define pt_Auto3628   "PRINTER"
#define xx_Auto3628   "PRINTER"
#define en_Auto3629   "RESOLUTION"
#define fr_Auto3629   "RESOLUTION"
#define it_Auto3629   "RESOLUTION"
#define es_Auto3629   "RESOLUTION"
#define de_Auto3629   "RESOLUTION"
#define nl_Auto3629   "RESOLUTION"
#define pt_Auto3629   "RESOLUTION"
#define xx_Auto3629   "RESOLUTION"
#define en__Auto3629   ""
#define en_Auto3630   "PAPERTYPE"
#define fr_Auto3630   "PAPERTYPE"
#define it_Auto3630   "PAPERTYPE"
#define es_Auto3630   "PAPERTYPE"
#define de_Auto3630   "PAPERTYPE"
#define nl_Auto3630   "PAPERTYPE"
#define pt_Auto3630   "PAPERTYPE"
#define xx_Auto3630   "PAPERTYPE"
#define en__Auto3630   ""
#define en_Auto3631   "LAYOUT"
#define fr_Auto3631   "LAYOUT"
#define it_Auto3631   "LAYOUT"
#define es_Auto3631   "LAYOUT"
#define de_Auto3631   "LAYOUT"
#define nl_Auto3631   "LAYOUT"
#define pt_Auto3631   "LAYOUT"
#define xx_Auto3631   "LAYOUT"
#define en__Auto3631   ""
#define en_Auto3632   "PAGEFEED"
#define fr_Auto3632   "PAGEFEED"
#define it_Auto3632   "PAGEFEED"
#define es_Auto3632   "PAGEFEED"
#define de_Auto3632   "PAGEFEED"
#define nl_Auto3632   "PAGEFEED"
#define pt_Auto3632   "PAGEFEED"
#define xx_Auto3632   "PAGEFEED"
#define en__Auto3632   ""
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
#define en_Auto3633   "AED"
#define fr_Auto3633   "AED"
#define it_Auto3633   "AED"
#define es_Auto3633   "AED"
#define de_Auto3633   "AED"
#define nl_Auto3633   "AED"
#define pt_Auto3633   "AED"
#define xx_Auto3633   "AED"
#define en_Auto3634   "AED.FONT"
#define fr_Auto3634   "AED.FONT"
#define it_Auto3634   "AED.FONT"
#define es_Auto3634   "AED.FONT"
#define de_Auto3634   "AED.FONT"
#define nl_Auto3634   "AED.FONT"
#define pt_Auto3634   "AED.FONT"
#define xx_Auto3634   "AED.FONT"
#define en_Auto3635   "Editor Syntaxical Colours"
#define fr_Auto3635   "Couloration syntaxique de l'‚diteur"
#define it_Auto3635   "Editor Syntaxical Colours"
#define es_Auto3635   "Editor Syntaxical Colours"
#define de_Auto3635   "Editor Syntaxical Colours"
#define nl_Auto3635   "Editor Syntaxical Colours"
#define pt_Auto3635   "Editor Syntaxical Colours"
#define xx_Auto3635   "Editor Syntaxical Colours"
#define en__Auto3635   ""
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
#define en_Auto3636   "AMAKE"
#define fr_Auto3636   "AMAKE"
#define it_Auto3636   "AMAKE"
#define es_Auto3636   "AMAKE"
#define de_Auto3636   "AMAKE"
#define nl_Auto3636   "AMAKE"
#define pt_Auto3636   "AMAKE"
#define xx_Auto3636   "AMAKE"
#define en_Auto3637   "AMAKE.OPTIONS"
#define fr_Auto3637   "AMAKE.OPTIONS"
#define it_Auto3637   "AMAKE.OPTIONS"
#define es_Auto3637   "AMAKE.OPTIONS"
#define de_Auto3637   "AMAKE.OPTIONS"
#define nl_Auto3637   "AMAKE.OPTIONS"
#define pt_Auto3637   "AMAKE.OPTIONS"
#define xx_Auto3637   "AMAKE.OPTIONS"
#define en_Auto3638   "AMAKE.DEFINE"
#define fr_Auto3638   "AMAKE.DEFINE"
#define it_Auto3638   "AMAKE.DEFINE"
#define es_Auto3638   "AMAKE.DEFINE"
#define de_Auto3638   "AMAKE.DEFINE"
#define nl_Auto3638   "AMAKE.DEFINE"
#define pt_Auto3638   "AMAKE.DEFINE"
#define xx_Auto3638   "AMAKE.DEFINE"
#define en_Auto3639   "AMAKE.LIST"
#define fr_Auto3639   "AMAKE.LIST"
#define it_Auto3639   "AMAKE.LIST"
#define es_Auto3639   "AMAKE.LIST"
#define de_Auto3639   "AMAKE.LIST"
#define nl_Auto3639   "AMAKE.LIST"
#define pt_Auto3639   "AMAKE.LIST"
#define xx_Auto3639   "AMAKE.LIST"
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
	int	focus_pages[8+1];
	char * msg_Auto3584[8];
	char * hint_Auto3584[8];
	int	x_Auto3584;
	int	y_Auto3584;
	int	w_Auto3584;
	int	h_Auto3584;
	char * msg_General[8];
	int	trigger_General;
	char * hint_General[8];
	int	page_number;
	char * msg_Auto3585[8];
	char * hint_Auto3585[8];
	char * hint_FILENAME[8];
	char	buffer_FILENAME[260];
	char * msg_ChoixFILENAME[8];
	int	trigger_ChoixFILENAME;
	char * hint_ChoixFILENAME[8];
	char * hint_ABALHOST[8];
	char	buffer_ABALHOST[256];
	char * msg_Auto3586[8];
	char * hint_Auto3586[8];
	char * msg_Auto3587[8];
	char * hint_Auto3587[8];
	char * msg_Auto3588[8];
	char * hint_Auto3588[8];
	char * msg_Auto3589[8];
	char * hint_Auto3589[8];
	char * msg_Auto3590[8];
	char * hint_Auto3590[8];
	char * hint_IDENTITY[8];
	char	buffer_IDENTITY[256];
	char * hint_REPLAY[8];
	char	buffer_REPLAY[256];
	char * hint_RECORD[8];
	char	buffer_RECORD[256];
	char * msg_Abal[8];
	int	trigger_Abal;
	char * hint_Abal[8];
	char * msg_Auto3591[8];
	char * hint_Auto3591[8];
	char * msg_Auto3592[8];
	char * hint_Auto3592[8];
	char * msg_Auto3593[8];
	char * hint_Auto3593[8];
	char * msg_Auto3594[8];
	char * hint_Auto3594[8];
	char * msg_Auto3595[8];
	char * hint_Auto3595[8];
	char * msg_Auto3596[8];
	char * hint_Auto3596[8];
	char * msg_Auto3597[8];
	char * hint_Auto3597[8];
	char * msg_Auto3598[8];
	char * hint_Auto3598[8];
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
	char * msg_Auto3599[8];
	char * hint_Auto3599[8];
	char * msg_Auto3600[8];
	char * hint_Auto3600[8];
	char * msg_Auto3601[8];
	char * hint_Auto3601[8];
	char * msg_Auto3602[8];
	char * hint_Auto3602[8];
	char * msg_Auto3603[8];
	char * hint_Auto3603[8];
	char * msg_Auto3604[8];
	char * hint_Auto3604[8];
	char * msg_Auto3605[8];
	char * hint_Auto3605[8];
	char * msg_Auto3606[8];
	char * hint_Auto3606[8];
	char * msg_Auto3607[8];
	char * hint_Auto3607[8];
	char * msg_Auto3608[8];
	char * hint_Auto3608[8];
	char * msg_Auto3609[8];
	char * hint_Auto3609[8];
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
	char * msg_Images[8];
	int	trigger_Images;
	char * hint_Images[8];
	char * msg_Auto3610[8];
	char * hint_Auto3610[8];
	char * hint_IMAGEPATH[8];
	char	buffer_IMAGEPATH[256];
	char * msg_ChoixIMAGEPATH[8];
	int	trigger_ChoixIMAGEPATH;
	char * hint_ChoixIMAGEPATH[8];
	char * msg_Auto3611[8];
	char * hint_Auto3611[8];
	char * msg_Auto3612[8];
	char * hint_Auto3612[8];
	char * msg_Auto3613[8];
	char * hint_Auto3613[8];
	char * msg_Auto3614[8];
	char * hint_Auto3614[8];
	char * msg_Auto3615[8];
	char * hint_Auto3615[8];
	char * msg_Auto3616[8];
	char * hint_Auto3616[8];
	char * msg_Auto3617[8];
	char * hint_Auto3617[8];
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
	char * msg_Auto3618[8];
	char * hint_Auto3618[8];
	char * msg_Auto3619[8];
	char * hint_Auto3619[8];
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
	char * msg_Auto3620[8];
	char * hint_Auto3620[8];
	char * msg_Auto3621[8];
	char * hint_Auto3621[8];
	char * msg_Auto3622[8];
	char * hint_Auto3622[8];
	char * msg_Auto3623[8];
	char * hint_Auto3623[8];
	char * msg_Auto3624[8];
	char * hint_Auto3624[8];
	char * msg_Auto3625[8];
	char * hint_Auto3625[8];
	char * msg_Auto3626[8];
	char * hint_Auto3626[8];
	char * msg_Auto3627[8];
	char * hint_Auto3627[8];
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
	char * msg_Auto3628[8];
	char * hint_Auto3628[8];
	char * msg_Auto3629[8];
	char * hint_Auto3629[8];
	char * msg_Auto3630[8];
	char * hint_Auto3630[8];
	char * msg_Auto3631[8];
	char * hint_Auto3631[8];
	char * msg_Auto3632[8];
	char * hint_Auto3632[8];
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
	char * msg_Auto3633[8];
	char * hint_Auto3633[8];
	char * msg_Auto3634[8];
	char * hint_Auto3634[8];
	char * msg_Auto3635[8];
	char * hint_Auto3635[8];
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
	char * msg_Auto3636[8];
	char * hint_Auto3636[8];
	char * msg_Auto3637[8];
	char * hint_Auto3637[8];
	char * msg_Auto3638[8];
	char * hint_Auto3638[8];
	char * msg_Auto3639[8];
	char * hint_Auto3639[8];
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
	char	signature[66];
	};
static int	vfh[16];
private int on_ChoixFILENAME_event(struct accept_configuration_context * _Context);
private int on_ChoixATR_event(struct accept_configuration_context * _Context);
private int on_ChoixATR_INCLUDE_event(struct accept_configuration_context * _Context);
private int on_ChoixALD_event(struct accept_configuration_context * _Context);
private int on_ChoixALD_INCLUDE_event(struct accept_configuration_context * _Context);
private int on_ChoixOTR_event(struct accept_configuration_context * _Context);
private int on_ChoixOTR_INCLUDE_event(struct accept_configuration_context * _Context);
private int on_ChoixOLD_event(struct accept_configuration_context * _Context);
private int on_ChoixOLD_INCLUDE_event(struct accept_configuration_context * _Context);
private int on_ChoixEXA_event(struct accept_configuration_context * _Context);
private int on_ChoixEXADB_event(struct accept_configuration_context * _Context);
private int on_ChoixIMAGEPATH_event(struct accept_configuration_context * _Context);
private int on_ChoixICONPATH_event(struct accept_configuration_context * _Context);
private int on_ChoixPALETTE_event(struct accept_configuration_context * _Context);
private int on_ChoixSTYLEPATH_event(struct accept_configuration_context * _Context);
private int on_ChoixCOMPPATH_event(struct accept_configuration_context * _Context);
private int on_ChoixFONTPATH_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT1_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT2_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT3_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT4_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT5_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT6_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT7_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT8_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT9_event(struct accept_configuration_context * _Context);
private int on_ChoixFONT10_event(struct accept_configuration_context * _Context);
private int on_ChoixSCREEN_CSS_event(struct accept_configuration_context * _Context);
private int on_ChoixPRINT_CSS_event(struct accept_configuration_context * _Context);
private int on_ChoixNAVIGATOR_event(struct accept_configuration_context * _Context);
private int on_ChoixDOCPATH_event(struct accept_configuration_context * _Context);
private int on_ChoixPRINTER_event(struct accept_configuration_context * _Context);
private int on_ChoixAED_event(struct accept_configuration_context * _Context);
private int on_ACCEPT_event(struct accept_configuration_context * _Context);
private int on_SAVEFILE_event(struct accept_configuration_context * _Context);
private int on_SAVELDAP_event(struct accept_configuration_context * _Context);
private int on_LoadLdap_event(struct accept_configuration_context * _Context);
private int on_EDITFILE_event(struct accept_configuration_context * _Context);
private int on_DELETE_event(struct accept_configuration_context * _Context);
private int on_LOADFILE_event(struct accept_configuration_context * _Context);
private int on_CANCEL_event(struct accept_configuration_context * _Context);
private int on_choixAMAKE_event(struct accept_configuration_context * _Context);
private int on_choixAMAKE_LIST_event(struct accept_configuration_context * _Context);

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
	vfh[10] = visual_font("bmap0414.fmf",12);
	if (!(_Context = allocate( sizeof( struct accept_configuration_context ) ) ))
		return(27);
	else	*cptr=_Context;
	_Context->language = visual_national_language(-1);
	_Context->keycode=0;
	_Context->focus_item=1;
	_Context->focus_items=127;
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
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
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
	for (i=0; i < 8; i++)_Context->msg_Auto3584[i]=" ";
	_Context->hint_Auto3584[0]=en__Auto3584;
	_Context->hint_Auto3584[1]=fr__Auto3584;
	_Context->hint_Auto3584[2]=it__Auto3584;
	_Context->hint_Auto3584[3]=es__Auto3584;
	_Context->hint_Auto3584[4]=de__Auto3584;
	_Context->hint_Auto3584[5]=nl__Auto3584;
	_Context->hint_Auto3584[6]=pt__Auto3584;
	_Context->hint_Auto3584[7]=xx__Auto3584;
	_Context->x_Auto3584=0;
	_Context->y_Auto3584=0;
	_Context->w_Auto3584=790;
	_Context->h_Auto3584=600;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3585[i]=" ";
	_Context->msg_Auto3585[0]=en_Auto3585;
	_Context->msg_Auto3585[1]=fr_Auto3585;
	_Context->msg_Auto3585[2]=it_Auto3585;
	_Context->msg_Auto3585[3]=es_Auto3585;
	_Context->msg_Auto3585[4]=de_Auto3585;
	_Context->msg_Auto3585[5]=nl_Auto3585;
	_Context->msg_Auto3585[6]=pt_Auto3585;
	_Context->msg_Auto3585[7]=xx_Auto3585;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3586[i]=" ";
	_Context->msg_Auto3586[0]=en_Auto3586;
	_Context->msg_Auto3586[1]=fr_Auto3586;
	_Context->msg_Auto3586[2]=it_Auto3586;
	_Context->msg_Auto3586[3]=es_Auto3586;
	_Context->msg_Auto3586[4]=de_Auto3586;
	_Context->msg_Auto3586[5]=nl_Auto3586;
	_Context->msg_Auto3586[6]=pt_Auto3586;
	_Context->msg_Auto3586[7]=xx_Auto3586;
	for (i=0; i < 8; i++)_Context->msg_Auto3587[i]=" ";
	_Context->msg_Auto3587[0]=en_Auto3587;
	_Context->msg_Auto3587[1]=fr_Auto3587;
	_Context->msg_Auto3587[2]=it_Auto3587;
	_Context->msg_Auto3587[3]=es_Auto3587;
	_Context->msg_Auto3587[4]=de_Auto3587;
	_Context->msg_Auto3587[5]=nl_Auto3587;
	_Context->msg_Auto3587[6]=pt_Auto3587;
	_Context->msg_Auto3587[7]=xx_Auto3587;
	for (i=0; i < 8; i++)_Context->msg_Auto3588[i]=" ";
	_Context->msg_Auto3588[0]=en_Auto3588;
	_Context->msg_Auto3588[1]=fr_Auto3588;
	_Context->msg_Auto3588[2]=it_Auto3588;
	_Context->msg_Auto3588[3]=es_Auto3588;
	_Context->msg_Auto3588[4]=de_Auto3588;
	_Context->msg_Auto3588[5]=nl_Auto3588;
	_Context->msg_Auto3588[6]=pt_Auto3588;
	_Context->msg_Auto3588[7]=xx_Auto3588;
	for (i=0; i < 8; i++)_Context->msg_Auto3589[i]=" ";
	_Context->msg_Auto3589[0]=en_Auto3589;
	_Context->msg_Auto3589[1]=fr_Auto3589;
	_Context->msg_Auto3589[2]=it_Auto3589;
	_Context->msg_Auto3589[3]=es_Auto3589;
	_Context->msg_Auto3589[4]=de_Auto3589;
	_Context->msg_Auto3589[5]=nl_Auto3589;
	_Context->msg_Auto3589[6]=pt_Auto3589;
	_Context->msg_Auto3589[7]=xx_Auto3589;
	_Context->hint_Auto3589[0]=en__Auto3589;
	for (i=0; i < 8; i++)_Context->msg_Auto3590[i]=" ";
	_Context->msg_Auto3590[0]=en_Auto3590;
	_Context->msg_Auto3590[1]=fr_Auto3590;
	_Context->msg_Auto3590[2]=it_Auto3590;
	_Context->msg_Auto3590[3]=es_Auto3590;
	_Context->msg_Auto3590[4]=de_Auto3590;
	_Context->msg_Auto3590[5]=nl_Auto3590;
	_Context->msg_Auto3590[6]=pt_Auto3590;
	_Context->msg_Auto3590[7]=xx_Auto3590;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3591[i]=" ";
	_Context->msg_Auto3591[0]=en_Auto3591;
	_Context->msg_Auto3591[1]=fr_Auto3591;
	_Context->msg_Auto3591[2]=it_Auto3591;
	_Context->msg_Auto3591[3]=es_Auto3591;
	_Context->msg_Auto3591[4]=de_Auto3591;
	_Context->msg_Auto3591[5]=nl_Auto3591;
	_Context->msg_Auto3591[6]=pt_Auto3591;
	_Context->msg_Auto3591[7]=xx_Auto3591;
	_Context->hint_Auto3591[0]=en__Auto3591;
	for (i=0; i < 8; i++)_Context->msg_Auto3592[i]=" ";
	_Context->msg_Auto3592[0]=en_Auto3592;
	_Context->msg_Auto3592[1]=fr_Auto3592;
	_Context->msg_Auto3592[2]=it_Auto3592;
	_Context->msg_Auto3592[3]=es_Auto3592;
	_Context->msg_Auto3592[4]=de_Auto3592;
	_Context->msg_Auto3592[5]=nl_Auto3592;
	_Context->msg_Auto3592[6]=pt_Auto3592;
	_Context->msg_Auto3592[7]=xx_Auto3592;
	for (i=0; i < 8; i++)_Context->msg_Auto3593[i]=" ";
	_Context->msg_Auto3593[0]=en_Auto3593;
	_Context->msg_Auto3593[1]=fr_Auto3593;
	_Context->msg_Auto3593[2]=it_Auto3593;
	_Context->msg_Auto3593[3]=es_Auto3593;
	_Context->msg_Auto3593[4]=de_Auto3593;
	_Context->msg_Auto3593[5]=nl_Auto3593;
	_Context->msg_Auto3593[6]=pt_Auto3593;
	_Context->msg_Auto3593[7]=xx_Auto3593;
	for (i=0; i < 8; i++)_Context->msg_Auto3594[i]=" ";
	_Context->msg_Auto3594[0]=en_Auto3594;
	_Context->msg_Auto3594[1]=fr_Auto3594;
	_Context->msg_Auto3594[2]=it_Auto3594;
	_Context->msg_Auto3594[3]=es_Auto3594;
	_Context->msg_Auto3594[4]=de_Auto3594;
	_Context->msg_Auto3594[5]=nl_Auto3594;
	_Context->msg_Auto3594[6]=pt_Auto3594;
	_Context->msg_Auto3594[7]=xx_Auto3594;
	for (i=0; i < 8; i++)_Context->msg_Auto3595[i]=" ";
	_Context->msg_Auto3595[0]=en_Auto3595;
	_Context->msg_Auto3595[1]=fr_Auto3595;
	_Context->msg_Auto3595[2]=it_Auto3595;
	_Context->msg_Auto3595[3]=es_Auto3595;
	_Context->msg_Auto3595[4]=de_Auto3595;
	_Context->msg_Auto3595[5]=nl_Auto3595;
	_Context->msg_Auto3595[6]=pt_Auto3595;
	_Context->msg_Auto3595[7]=xx_Auto3595;
	for (i=0; i < 8; i++)_Context->msg_Auto3596[i]=" ";
	_Context->msg_Auto3596[0]=en_Auto3596;
	_Context->msg_Auto3596[1]=fr_Auto3596;
	_Context->msg_Auto3596[2]=it_Auto3596;
	_Context->msg_Auto3596[3]=es_Auto3596;
	_Context->msg_Auto3596[4]=de_Auto3596;
	_Context->msg_Auto3596[5]=nl_Auto3596;
	_Context->msg_Auto3596[6]=pt_Auto3596;
	_Context->msg_Auto3596[7]=xx_Auto3596;
	_Context->hint_Auto3596[0]=en__Auto3596;
	_Context->hint_Auto3596[1]=fr__Auto3596;
	_Context->hint_Auto3596[2]=it__Auto3596;
	_Context->hint_Auto3596[3]=es__Auto3596;
	_Context->hint_Auto3596[4]=de__Auto3596;
	_Context->hint_Auto3596[5]=nl__Auto3596;
	_Context->hint_Auto3596[6]=pt__Auto3596;
	_Context->hint_Auto3596[7]=xx__Auto3596;
	for (i=0; i < 8; i++)_Context->msg_Auto3597[i]=" ";
	_Context->msg_Auto3597[0]=en_Auto3597;
	_Context->msg_Auto3597[1]=fr_Auto3597;
	_Context->msg_Auto3597[2]=it_Auto3597;
	_Context->msg_Auto3597[3]=es_Auto3597;
	_Context->msg_Auto3597[4]=de_Auto3597;
	_Context->msg_Auto3597[5]=nl_Auto3597;
	_Context->msg_Auto3597[6]=pt_Auto3597;
	_Context->msg_Auto3597[7]=xx_Auto3597;
	for (i=0; i < 8; i++)_Context->msg_Auto3598[i]=" ";
	_Context->msg_Auto3598[0]=en_Auto3598;
	_Context->msg_Auto3598[1]=fr_Auto3598;
	_Context->msg_Auto3598[2]=it_Auto3598;
	_Context->msg_Auto3598[3]=es_Auto3598;
	_Context->msg_Auto3598[4]=de_Auto3598;
	_Context->msg_Auto3598[5]=nl_Auto3598;
	_Context->msg_Auto3598[6]=pt_Auto3598;
	_Context->msg_Auto3598[7]=xx_Auto3598;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3599[i]=" ";
	_Context->msg_Auto3599[0]=en_Auto3599;
	_Context->msg_Auto3599[1]=fr_Auto3599;
	_Context->msg_Auto3599[2]=it_Auto3599;
	_Context->msg_Auto3599[3]=es_Auto3599;
	_Context->msg_Auto3599[4]=de_Auto3599;
	_Context->msg_Auto3599[5]=nl_Auto3599;
	_Context->msg_Auto3599[6]=pt_Auto3599;
	_Context->msg_Auto3599[7]=xx_Auto3599;
	_Context->hint_Auto3599[0]=en__Auto3599;
	for (i=0; i < 8; i++)_Context->msg_Auto3600[i]=" ";
	_Context->msg_Auto3600[0]=en_Auto3600;
	_Context->msg_Auto3600[1]=fr_Auto3600;
	_Context->msg_Auto3600[2]=it_Auto3600;
	_Context->msg_Auto3600[3]=es_Auto3600;
	_Context->msg_Auto3600[4]=de_Auto3600;
	_Context->msg_Auto3600[5]=nl_Auto3600;
	_Context->msg_Auto3600[6]=pt_Auto3600;
	_Context->msg_Auto3600[7]=xx_Auto3600;
	_Context->hint_Auto3600[0]=en__Auto3600;
	for (i=0; i < 8; i++)_Context->msg_Auto3601[i]=" ";
	_Context->msg_Auto3601[0]=en_Auto3601;
	_Context->msg_Auto3601[1]=fr_Auto3601;
	_Context->msg_Auto3601[2]=it_Auto3601;
	_Context->msg_Auto3601[3]=es_Auto3601;
	_Context->msg_Auto3601[4]=de_Auto3601;
	_Context->msg_Auto3601[5]=nl_Auto3601;
	_Context->msg_Auto3601[6]=pt_Auto3601;
	_Context->msg_Auto3601[7]=xx_Auto3601;
	for (i=0; i < 8; i++)_Context->msg_Auto3602[i]=" ";
	_Context->msg_Auto3602[0]=en_Auto3602;
	_Context->msg_Auto3602[1]=fr_Auto3602;
	_Context->msg_Auto3602[2]=it_Auto3602;
	_Context->msg_Auto3602[3]=es_Auto3602;
	_Context->msg_Auto3602[4]=de_Auto3602;
	_Context->msg_Auto3602[5]=nl_Auto3602;
	_Context->msg_Auto3602[6]=pt_Auto3602;
	_Context->msg_Auto3602[7]=xx_Auto3602;
	for (i=0; i < 8; i++)_Context->msg_Auto3603[i]=" ";
	_Context->msg_Auto3603[0]=en_Auto3603;
	_Context->msg_Auto3603[1]=fr_Auto3603;
	_Context->msg_Auto3603[2]=it_Auto3603;
	_Context->msg_Auto3603[3]=es_Auto3603;
	_Context->msg_Auto3603[4]=de_Auto3603;
	_Context->msg_Auto3603[5]=nl_Auto3603;
	_Context->msg_Auto3603[6]=pt_Auto3603;
	_Context->msg_Auto3603[7]=xx_Auto3603;
	for (i=0; i < 8; i++)_Context->msg_Auto3604[i]=" ";
	_Context->msg_Auto3604[0]=en_Auto3604;
	_Context->msg_Auto3604[1]=fr_Auto3604;
	_Context->msg_Auto3604[2]=it_Auto3604;
	_Context->msg_Auto3604[3]=es_Auto3604;
	_Context->msg_Auto3604[4]=de_Auto3604;
	_Context->msg_Auto3604[5]=nl_Auto3604;
	_Context->msg_Auto3604[6]=pt_Auto3604;
	_Context->msg_Auto3604[7]=xx_Auto3604;
	for (i=0; i < 8; i++)_Context->msg_Auto3605[i]=" ";
	_Context->msg_Auto3605[0]=en_Auto3605;
	_Context->msg_Auto3605[1]=fr_Auto3605;
	_Context->msg_Auto3605[2]=it_Auto3605;
	_Context->msg_Auto3605[3]=es_Auto3605;
	_Context->msg_Auto3605[4]=de_Auto3605;
	_Context->msg_Auto3605[5]=nl_Auto3605;
	_Context->msg_Auto3605[6]=pt_Auto3605;
	_Context->msg_Auto3605[7]=xx_Auto3605;
	_Context->hint_Auto3605[0]=en__Auto3605;
	_Context->hint_Auto3605[1]=fr__Auto3605;
	_Context->hint_Auto3605[2]=it__Auto3605;
	_Context->hint_Auto3605[3]=es__Auto3605;
	_Context->hint_Auto3605[4]=de__Auto3605;
	_Context->hint_Auto3605[5]=nl__Auto3605;
	_Context->hint_Auto3605[6]=pt__Auto3605;
	_Context->hint_Auto3605[7]=xx__Auto3605;
	for (i=0; i < 8; i++)_Context->msg_Auto3606[i]=" ";
	_Context->msg_Auto3606[0]=en_Auto3606;
	_Context->msg_Auto3606[1]=fr_Auto3606;
	_Context->msg_Auto3606[2]=it_Auto3606;
	_Context->msg_Auto3606[3]=es_Auto3606;
	_Context->msg_Auto3606[4]=de_Auto3606;
	_Context->msg_Auto3606[5]=nl_Auto3606;
	_Context->msg_Auto3606[6]=pt_Auto3606;
	_Context->msg_Auto3606[7]=xx_Auto3606;
	for (i=0; i < 8; i++)_Context->msg_Auto3607[i]=" ";
	_Context->msg_Auto3607[0]=en_Auto3607;
	_Context->msg_Auto3607[1]=fr_Auto3607;
	_Context->msg_Auto3607[2]=it_Auto3607;
	_Context->msg_Auto3607[3]=es_Auto3607;
	_Context->msg_Auto3607[4]=de_Auto3607;
	_Context->msg_Auto3607[5]=nl_Auto3607;
	_Context->msg_Auto3607[6]=pt_Auto3607;
	_Context->msg_Auto3607[7]=xx_Auto3607;
	for (i=0; i < 8; i++)_Context->msg_Auto3608[i]=" ";
	_Context->msg_Auto3608[0]=en_Auto3608;
	_Context->msg_Auto3608[1]=fr_Auto3608;
	_Context->msg_Auto3608[2]=it_Auto3608;
	_Context->msg_Auto3608[3]=es_Auto3608;
	_Context->msg_Auto3608[4]=de_Auto3608;
	_Context->msg_Auto3608[5]=nl_Auto3608;
	_Context->msg_Auto3608[6]=pt_Auto3608;
	_Context->msg_Auto3608[7]=xx_Auto3608;
	for (i=0; i < 8; i++)_Context->msg_Auto3609[i]=" ";
	_Context->msg_Auto3609[0]=en_Auto3609;
	_Context->msg_Auto3609[1]=fr_Auto3609;
	_Context->msg_Auto3609[2]=it_Auto3609;
	_Context->msg_Auto3609[3]=es_Auto3609;
	_Context->msg_Auto3609[4]=de_Auto3609;
	_Context->msg_Auto3609[5]=nl_Auto3609;
	_Context->msg_Auto3609[6]=pt_Auto3609;
	_Context->msg_Auto3609[7]=xx_Auto3609;
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
	_Context->focus_pages[3]=36;
	for (i=0; i < 8; i++)_Context->msg_Auto3610[i]=" ";
	_Context->msg_Auto3610[0]=en_Auto3610;
	_Context->msg_Auto3610[1]=fr_Auto3610;
	_Context->msg_Auto3610[2]=it_Auto3610;
	_Context->msg_Auto3610[3]=es_Auto3610;
	_Context->msg_Auto3610[4]=de_Auto3610;
	_Context->msg_Auto3610[5]=nl_Auto3610;
	_Context->msg_Auto3610[6]=pt_Auto3610;
	_Context->msg_Auto3610[7]=xx_Auto3610;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3611[i]=" ";
	_Context->msg_Auto3611[0]=en_Auto3611;
	_Context->msg_Auto3611[1]=fr_Auto3611;
	_Context->msg_Auto3611[2]=it_Auto3611;
	_Context->msg_Auto3611[3]=es_Auto3611;
	_Context->msg_Auto3611[4]=de_Auto3611;
	_Context->msg_Auto3611[5]=nl_Auto3611;
	_Context->msg_Auto3611[6]=pt_Auto3611;
	_Context->msg_Auto3611[7]=xx_Auto3611;
	for (i=0; i < 8; i++)_Context->msg_Auto3612[i]=" ";
	_Context->msg_Auto3612[0]=en_Auto3612;
	_Context->msg_Auto3612[1]=fr_Auto3612;
	_Context->msg_Auto3612[2]=it_Auto3612;
	_Context->msg_Auto3612[3]=es_Auto3612;
	_Context->msg_Auto3612[4]=de_Auto3612;
	_Context->msg_Auto3612[5]=nl_Auto3612;
	_Context->msg_Auto3612[6]=pt_Auto3612;
	_Context->msg_Auto3612[7]=xx_Auto3612;
	for (i=0; i < 8; i++)_Context->msg_Auto3613[i]=" ";
	_Context->msg_Auto3613[0]=en_Auto3613;
	_Context->msg_Auto3613[1]=fr_Auto3613;
	_Context->msg_Auto3613[2]=it_Auto3613;
	_Context->msg_Auto3613[3]=es_Auto3613;
	_Context->msg_Auto3613[4]=de_Auto3613;
	_Context->msg_Auto3613[5]=nl_Auto3613;
	_Context->msg_Auto3613[6]=pt_Auto3613;
	_Context->msg_Auto3613[7]=xx_Auto3613;
	for (i=0; i < 8; i++)_Context->msg_Auto3614[i]=" ";
	_Context->msg_Auto3614[0]=en_Auto3614;
	_Context->msg_Auto3614[1]=fr_Auto3614;
	_Context->msg_Auto3614[2]=it_Auto3614;
	_Context->msg_Auto3614[3]=es_Auto3614;
	_Context->msg_Auto3614[4]=de_Auto3614;
	_Context->msg_Auto3614[5]=nl_Auto3614;
	_Context->msg_Auto3614[6]=pt_Auto3614;
	_Context->msg_Auto3614[7]=xx_Auto3614;
	for (i=0; i < 8; i++)_Context->msg_Auto3615[i]=" ";
	_Context->msg_Auto3615[0]=en_Auto3615;
	_Context->msg_Auto3615[1]=fr_Auto3615;
	_Context->msg_Auto3615[2]=it_Auto3615;
	_Context->msg_Auto3615[3]=es_Auto3615;
	_Context->msg_Auto3615[4]=de_Auto3615;
	_Context->msg_Auto3615[5]=nl_Auto3615;
	_Context->msg_Auto3615[6]=pt_Auto3615;
	_Context->msg_Auto3615[7]=xx_Auto3615;
	_Context->hint_Auto3615[0]=en__Auto3615;
	_Context->hint_Auto3615[1]=fr__Auto3615;
	_Context->hint_Auto3615[2]=it__Auto3615;
	_Context->hint_Auto3615[3]=es__Auto3615;
	_Context->hint_Auto3615[4]=de__Auto3615;
	_Context->hint_Auto3615[5]=nl__Auto3615;
	_Context->hint_Auto3615[6]=pt__Auto3615;
	_Context->hint_Auto3615[7]=xx__Auto3615;
	for (i=0; i < 8; i++)_Context->msg_Auto3616[i]=" ";
	_Context->msg_Auto3616[0]=en_Auto3616;
	_Context->msg_Auto3616[1]=fr_Auto3616;
	_Context->msg_Auto3616[2]=it_Auto3616;
	_Context->msg_Auto3616[3]=es_Auto3616;
	_Context->msg_Auto3616[4]=de_Auto3616;
	_Context->msg_Auto3616[5]=nl_Auto3616;
	_Context->msg_Auto3616[6]=pt_Auto3616;
	_Context->msg_Auto3616[7]=xx_Auto3616;
	_Context->hint_Auto3616[0]=en__Auto3616;
	_Context->hint_Auto3616[1]=fr__Auto3616;
	_Context->hint_Auto3616[2]=it__Auto3616;
	_Context->hint_Auto3616[3]=es__Auto3616;
	_Context->hint_Auto3616[4]=de__Auto3616;
	_Context->hint_Auto3616[5]=nl__Auto3616;
	_Context->hint_Auto3616[6]=pt__Auto3616;
	_Context->hint_Auto3616[7]=xx__Auto3616;
	for (i=0; i < 8; i++)_Context->msg_Auto3617[i]=" ";
	_Context->msg_Auto3617[0]=en_Auto3617;
	_Context->msg_Auto3617[1]=fr_Auto3617;
	_Context->msg_Auto3617[2]=it_Auto3617;
	_Context->msg_Auto3617[3]=es_Auto3617;
	_Context->msg_Auto3617[4]=de_Auto3617;
	_Context->msg_Auto3617[5]=nl_Auto3617;
	_Context->msg_Auto3617[6]=pt_Auto3617;
	_Context->msg_Auto3617[7]=xx_Auto3617;
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
	_Context->focus_pages[4]=50;
	for (i=0; i < 8; i++)_Context->msg_Auto3618[i]=" ";
	_Context->msg_Auto3618[0]=en_Auto3618;
	_Context->msg_Auto3618[1]=fr_Auto3618;
	_Context->msg_Auto3618[2]=it_Auto3618;
	_Context->msg_Auto3618[3]=es_Auto3618;
	_Context->msg_Auto3618[4]=de_Auto3618;
	_Context->msg_Auto3618[5]=nl_Auto3618;
	_Context->msg_Auto3618[6]=pt_Auto3618;
	_Context->msg_Auto3618[7]=xx_Auto3618;
	_Context->hint_Auto3618[0]=en__Auto3618;
	for (i=0; i < 8; i++)_Context->msg_Auto3619[i]=" ";
	_Context->msg_Auto3619[0]=en_Auto3619;
	_Context->msg_Auto3619[1]=fr_Auto3619;
	_Context->msg_Auto3619[2]=it_Auto3619;
	_Context->msg_Auto3619[3]=es_Auto3619;
	_Context->msg_Auto3619[4]=de_Auto3619;
	_Context->msg_Auto3619[5]=nl_Auto3619;
	_Context->msg_Auto3619[6]=pt_Auto3619;
	_Context->msg_Auto3619[7]=xx_Auto3619;
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
	_Context->focus_pages[5]=83;
	for (i=0; i < 8; i++)_Context->msg_Auto3620[i]=" ";
	_Context->msg_Auto3620[0]=en_Auto3620;
	_Context->msg_Auto3620[1]=fr_Auto3620;
	_Context->msg_Auto3620[2]=it_Auto3620;
	_Context->msg_Auto3620[3]=es_Auto3620;
	_Context->msg_Auto3620[4]=de_Auto3620;
	_Context->msg_Auto3620[5]=nl_Auto3620;
	_Context->msg_Auto3620[6]=pt_Auto3620;
	_Context->msg_Auto3620[7]=xx_Auto3620;
	_Context->hint_Auto3620[0]=en__Auto3620;
	for (i=0; i < 8; i++)_Context->msg_Auto3621[i]=" ";
	_Context->msg_Auto3621[0]=en_Auto3621;
	_Context->msg_Auto3621[1]=fr_Auto3621;
	_Context->msg_Auto3621[2]=it_Auto3621;
	_Context->msg_Auto3621[3]=es_Auto3621;
	_Context->msg_Auto3621[4]=de_Auto3621;
	_Context->msg_Auto3621[5]=nl_Auto3621;
	_Context->msg_Auto3621[6]=pt_Auto3621;
	_Context->msg_Auto3621[7]=xx_Auto3621;
	for (i=0; i < 8; i++)_Context->msg_Auto3622[i]=" ";
	_Context->msg_Auto3622[0]=en_Auto3622;
	_Context->msg_Auto3622[1]=fr_Auto3622;
	_Context->msg_Auto3622[2]=it_Auto3622;
	_Context->msg_Auto3622[3]=es_Auto3622;
	_Context->msg_Auto3622[4]=de_Auto3622;
	_Context->msg_Auto3622[5]=nl_Auto3622;
	_Context->msg_Auto3622[6]=pt_Auto3622;
	_Context->msg_Auto3622[7]=xx_Auto3622;
	for (i=0; i < 8; i++)_Context->msg_Auto3623[i]=" ";
	_Context->msg_Auto3623[0]=en_Auto3623;
	_Context->msg_Auto3623[1]=fr_Auto3623;
	_Context->msg_Auto3623[2]=it_Auto3623;
	_Context->msg_Auto3623[3]=es_Auto3623;
	_Context->msg_Auto3623[4]=de_Auto3623;
	_Context->msg_Auto3623[5]=nl_Auto3623;
	_Context->msg_Auto3623[6]=pt_Auto3623;
	_Context->msg_Auto3623[7]=xx_Auto3623;
	for (i=0; i < 8; i++)_Context->msg_Auto3624[i]=" ";
	_Context->msg_Auto3624[0]=en_Auto3624;
	_Context->msg_Auto3624[1]=fr_Auto3624;
	_Context->msg_Auto3624[2]=it_Auto3624;
	_Context->msg_Auto3624[3]=es_Auto3624;
	_Context->msg_Auto3624[4]=de_Auto3624;
	_Context->msg_Auto3624[5]=nl_Auto3624;
	_Context->msg_Auto3624[6]=pt_Auto3624;
	_Context->msg_Auto3624[7]=xx_Auto3624;
	for (i=0; i < 8; i++)_Context->msg_Auto3625[i]=" ";
	_Context->msg_Auto3625[0]=en_Auto3625;
	_Context->msg_Auto3625[1]=fr_Auto3625;
	_Context->msg_Auto3625[2]=it_Auto3625;
	_Context->msg_Auto3625[3]=es_Auto3625;
	_Context->msg_Auto3625[4]=de_Auto3625;
	_Context->msg_Auto3625[5]=nl_Auto3625;
	_Context->msg_Auto3625[6]=pt_Auto3625;
	_Context->msg_Auto3625[7]=xx_Auto3625;
	for (i=0; i < 8; i++)_Context->msg_Auto3626[i]=" ";
	_Context->msg_Auto3626[0]=en_Auto3626;
	_Context->msg_Auto3626[1]=fr_Auto3626;
	_Context->msg_Auto3626[2]=it_Auto3626;
	_Context->msg_Auto3626[3]=es_Auto3626;
	_Context->msg_Auto3626[4]=de_Auto3626;
	_Context->msg_Auto3626[5]=nl_Auto3626;
	_Context->msg_Auto3626[6]=pt_Auto3626;
	_Context->msg_Auto3626[7]=xx_Auto3626;
	for (i=0; i < 8; i++)_Context->msg_Auto3627[i]=" ";
	_Context->msg_Auto3627[0]=en_Auto3627;
	_Context->msg_Auto3627[1]=fr_Auto3627;
	_Context->msg_Auto3627[2]=it_Auto3627;
	_Context->msg_Auto3627[3]=es_Auto3627;
	_Context->msg_Auto3627[4]=de_Auto3627;
	_Context->msg_Auto3627[5]=nl_Auto3627;
	_Context->msg_Auto3627[6]=pt_Auto3627;
	_Context->msg_Auto3627[7]=xx_Auto3627;
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
	_Context->focus_pages[6]=95;
	for (i=0; i < 8; i++)_Context->msg_Auto3628[i]=" ";
	_Context->msg_Auto3628[0]=en_Auto3628;
	_Context->msg_Auto3628[1]=fr_Auto3628;
	_Context->msg_Auto3628[2]=it_Auto3628;
	_Context->msg_Auto3628[3]=es_Auto3628;
	_Context->msg_Auto3628[4]=de_Auto3628;
	_Context->msg_Auto3628[5]=nl_Auto3628;
	_Context->msg_Auto3628[6]=pt_Auto3628;
	_Context->msg_Auto3628[7]=xx_Auto3628;
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
	for (i=0; i < 8; i++)_Context->msg_Auto3630[i]=" ";
	_Context->msg_Auto3630[0]=en_Auto3630;
	_Context->msg_Auto3630[1]=fr_Auto3630;
	_Context->msg_Auto3630[2]=it_Auto3630;
	_Context->msg_Auto3630[3]=es_Auto3630;
	_Context->msg_Auto3630[4]=de_Auto3630;
	_Context->msg_Auto3630[5]=nl_Auto3630;
	_Context->msg_Auto3630[6]=pt_Auto3630;
	_Context->msg_Auto3630[7]=xx_Auto3630;
	_Context->hint_Auto3630[0]=en__Auto3630;
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
	_Context->focus_pages[7]=102;
	for (i=0; i < 8; i++)_Context->msg_Auto3633[i]=" ";
	_Context->msg_Auto3633[0]=en_Auto3633;
	_Context->msg_Auto3633[1]=fr_Auto3633;
	_Context->msg_Auto3633[2]=it_Auto3633;
	_Context->msg_Auto3633[3]=es_Auto3633;
	_Context->msg_Auto3633[4]=de_Auto3633;
	_Context->msg_Auto3633[5]=nl_Auto3633;
	_Context->msg_Auto3633[6]=pt_Auto3633;
	_Context->msg_Auto3633[7]=xx_Auto3633;
	for (i=0; i < 8; i++)_Context->msg_Auto3634[i]=" ";
	_Context->msg_Auto3634[0]=en_Auto3634;
	_Context->msg_Auto3634[1]=fr_Auto3634;
	_Context->msg_Auto3634[2]=it_Auto3634;
	_Context->msg_Auto3634[3]=es_Auto3634;
	_Context->msg_Auto3634[4]=de_Auto3634;
	_Context->msg_Auto3634[5]=nl_Auto3634;
	_Context->msg_Auto3634[6]=pt_Auto3634;
	_Context->msg_Auto3634[7]=xx_Auto3634;
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
	_Context->focus_pages[8]=121;
	for (i=0; i < 8; i++)_Context->msg_Auto3636[i]=" ";
	_Context->msg_Auto3636[0]=en_Auto3636;
	_Context->msg_Auto3636[1]=fr_Auto3636;
	_Context->msg_Auto3636[2]=it_Auto3636;
	_Context->msg_Auto3636[3]=es_Auto3636;
	_Context->msg_Auto3636[4]=de_Auto3636;
	_Context->msg_Auto3636[5]=nl_Auto3636;
	_Context->msg_Auto3636[6]=pt_Auto3636;
	_Context->msg_Auto3636[7]=xx_Auto3636;
	for (i=0; i < 8; i++)_Context->msg_Auto3637[i]=" ";
	_Context->msg_Auto3637[0]=en_Auto3637;
	_Context->msg_Auto3637[1]=fr_Auto3637;
	_Context->msg_Auto3637[2]=it_Auto3637;
	_Context->msg_Auto3637[3]=es_Auto3637;
	_Context->msg_Auto3637[4]=de_Auto3637;
	_Context->msg_Auto3637[5]=nl_Auto3637;
	_Context->msg_Auto3637[6]=pt_Auto3637;
	_Context->msg_Auto3637[7]=xx_Auto3637;
	for (i=0; i < 8; i++)_Context->msg_Auto3638[i]=" ";
	_Context->msg_Auto3638[0]=en_Auto3638;
	_Context->msg_Auto3638[1]=fr_Auto3638;
	_Context->msg_Auto3638[2]=it_Auto3638;
	_Context->msg_Auto3638[3]=es_Auto3638;
	_Context->msg_Auto3638[4]=de_Auto3638;
	_Context->msg_Auto3638[5]=nl_Auto3638;
	_Context->msg_Auto3638[6]=pt_Auto3638;
	_Context->msg_Auto3638[7]=xx_Auto3638;
	for (i=0; i < 8; i++)_Context->msg_Auto3639[i]=" ";
	_Context->msg_Auto3639[0]=en_Auto3639;
	_Context->msg_Auto3639[1]=fr_Auto3639;
	_Context->msg_Auto3639[2]=it_Auto3639;
	_Context->msg_Auto3639[3]=es_Auto3639;
	_Context->msg_Auto3639[4]=de_Auto3639;
	_Context->msg_Auto3639[5]=nl_Auto3639;
	_Context->msg_Auto3639[6]=pt_Auto3639;
	_Context->msg_Auto3639[7]=xx_Auto3639;
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
	_Context->pushbuffer=visual_buffer(_Context->x_Auto3584,_Context->y_Auto3584,790,600);
	return(0);
}

public 	int	accept_configuration_hide(struct accept_configuration_context * _Context)
{
	int	result;
	if (!( _Context )) { return(0); }
	result=_Context->keycode;
	if ((_Context->pushbuffer != (void *) 0)
	&& (_Context->ctrlbuffer != 0)) {
		(void)visual_buffer_put(_Context->pushbuffer,_Context->x_Auto3584,_Context->y_Auto3584);
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
		strcpy(_Context->signature,"SSSSSSSSSSSSSSSSSSSSSSSSSSWSSSSSSSSSSSSSSSSSSSSSWWWWSWWWWWWWWSSSS");
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
		(void)visual_buffer_get(_Context->pushbuffer,_Context->x_Auto3584,_Context->y_Auto3584);
		_Context->ctrlbuffer=1;
		}
	visual_freeze();
	if (((_Context->status = visual_styled_element(_Context->x_Auto3584,_Context->y_Auto3584,790,600,GetWidgetStyle(0),GetWindowVersion(),strlen(GetWindowVersion()))) != 0)
) {
		visual_window(_Context->x_Auto3584,_Context->y_Auto3584,790,600,vfh[2],GetWindowVersion(),strlen(GetWindowVersion()),0x7);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_General=visual_trigger_code(_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_General[_Context->language],strlen(_Context->msg_General[_Context->language]),0,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+90,710,16,vfh[1],27,0,_Context->msg_Auto3585[_Context->language],strlen(_Context->msg_Auto3585[_Context->language]),2);
	visual_frame(_Context->x_Auto3584+40,_Context->y_Auto3584+106,710,414,4);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+150,493+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+150+1,493,16,vfh[1],27,28,_Context->buffer_FILENAME,259,0);
		}
	if (_Context->page_number == 1 ) {
	_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+180,520+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+180+1,520,16,vfh[1],27,28,_Context->buffer_ABALHOST,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3584+60,_Context->y_Auto3584+150,140,20,vfh[3],27,0,_Context->msg_Auto3586[_Context->language],strlen(_Context->msg_Auto3586[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3584+60,_Context->y_Auto3584+180,140,20,vfh[3],27,0,_Context->msg_Auto3587[_Context->language],strlen(_Context->msg_Auto3587[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3584+60,_Context->y_Auto3584+210,144,20,vfh[3],27,0,_Context->msg_Auto3588[_Context->language],strlen(_Context->msg_Auto3588[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3584+60,_Context->y_Auto3584+250,144,20,vfh[3],27,0,_Context->msg_Auto3589[_Context->language],strlen(_Context->msg_Auto3589[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_text(_Context->x_Auto3584+60,_Context->y_Auto3584+280,144,20,vfh[3],27,0,_Context->msg_Auto3590[_Context->language],strlen(_Context->msg_Auto3590[_Context->language]),2);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+210,520+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+210+1,520,16,vfh[1],27,28,_Context->buffer_IDENTITY,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+250,520+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+250+1,520,16,vfh[1],27,28,_Context->buffer_REPLAY,255,0);
		}
	if (_Context->page_number == 1 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+280,520+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+280+1,520,16,vfh[1],27,28,_Context->buffer_RECORD,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_Abal=visual_trigger_code(_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]),84,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Abal[_Context->language],strlen(_Context->msg_Abal[_Context->language]),84,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+80,710,16,vfh[2],27,0,_Context->msg_Auto3591[_Context->language],strlen(_Context->msg_Auto3591[_Context->language]),2);
	visual_frame(_Context->x_Auto3584+40,_Context->y_Auto3584+96,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+100,140,20,vfh[3],27,0,_Context->msg_Auto3592[_Context->language],strlen(_Context->msg_Auto3592[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+120,140,20,vfh[3],27,0,_Context->msg_Auto3593[_Context->language],strlen(_Context->msg_Auto3593[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+140,140,20,vfh[3],27,0,_Context->msg_Auto3594[_Context->language],strlen(_Context->msg_Auto3594[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+160,138,20,vfh[3],27,0,_Context->msg_Auto3595[_Context->language],strlen(_Context->msg_Auto3595[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+200,140,20,vfh[3],27,0,_Context->msg_Auto3596[_Context->language],strlen(_Context->msg_Auto3596[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+220,140,20,vfh[3],27,0,_Context->msg_Auto3597[_Context->language],strlen(_Context->msg_Auto3597[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+180,140,20,vfh[3],27,0,_Context->msg_Auto3598[_Context->language],strlen(_Context->msg_Auto3598[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+100,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+100+1,503,16,vfh[1],27,28,_Context->buffer_ATR,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+120,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+120+1,528,16,vfh[1],27,28,_Context->buffer_ATR_DEFINE,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+140,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+140+1,503,16,vfh[1],27,28,_Context->buffer_ATR_INCLUDE,1024,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+160,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+160+1,528,16,vfh[1],27,28,_Context->buffer_ATR_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+180,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+180+1,503,16,vfh[1],27,28,_Context->buffer_ALD,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+200,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+200+1,503,16,vfh[1],27,28,_Context->buffer_ALD_INCLUDE,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+220,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+220+1,528,16,vfh[1],27,28,_Context->buffer_ALD_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+260,710,16,vfh[2],27,0,_Context->msg_Auto3599[_Context->language],strlen(_Context->msg_Auto3599[_Context->language]),2);
	visual_frame(_Context->x_Auto3584+40,_Context->y_Auto3584+276,710,154,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+440,710,16,vfh[2],27,0,_Context->msg_Auto3600[_Context->language],strlen(_Context->msg_Auto3600[_Context->language]),2);
	visual_frame(_Context->x_Auto3584+40,_Context->y_Auto3584+456,710,64,4);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+280,140,20,vfh[3],27,0,_Context->msg_Auto3601[_Context->language],strlen(_Context->msg_Auto3601[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+300,140,20,vfh[3],27,0,_Context->msg_Auto3602[_Context->language],strlen(_Context->msg_Auto3602[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+320,140,20,vfh[3],27,0,_Context->msg_Auto3603[_Context->language],strlen(_Context->msg_Auto3603[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+340,140,20,vfh[3],27,0,_Context->msg_Auto3604[_Context->language],strlen(_Context->msg_Auto3604[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+380,140,20,vfh[3],27,0,_Context->msg_Auto3605[_Context->language],strlen(_Context->msg_Auto3605[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+400,140,20,vfh[3],27,0,_Context->msg_Auto3606[_Context->language],strlen(_Context->msg_Auto3606[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+360,140,20,vfh[3],27,0,_Context->msg_Auto3607[_Context->language],strlen(_Context->msg_Auto3607[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+470,140,20,vfh[3],27,0,_Context->msg_Auto3608[_Context->language],strlen(_Context->msg_Auto3608[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+490,140,20,vfh[3],27,0,_Context->msg_Auto3609[_Context->language],strlen(_Context->msg_Auto3609[_Context->language]),2);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+280,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+280+1,503,16,vfh[1],27,28,_Context->buffer_OTR,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+300,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+300+1,528,16,vfh[1],27,28,_Context->buffer_OTR_DEFINE,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+320,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+320+1,503,16,vfh[1],27,28,_Context->buffer_OTR_INCLUDE,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+340,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+340+1,528,16,vfh[1],27,28,_Context->buffer_OTR_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+360,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+360+1,503,16,vfh[1],27,28,_Context->buffer_OLD,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+380,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+380+1,503,16,vfh[1],27,28,_Context->buffer_OLD_INCLUDE,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+400,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+400+1,528,16,vfh[1],27,28,_Context->buffer_OLD_OPTIONS,255,0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+470,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+470+1,503,16,vfh[1],27,28,_Context->buffer_EXA,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),0);
		}
	if (_Context->page_number == 2 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+490,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+490+1,503,16,vfh[1],27,28,_Context->buffer_EXADB,255,0);
		}
	if (_Context->page_number == 2 ) {
	_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_Images=visual_trigger_code(_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]),150,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Images[_Context->language],strlen(_Context->msg_Images[_Context->language]),150,0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+30,_Context->y_Auto3584+110,154,20,vfh[3],27,0,_Context->msg_Auto3610[_Context->language],strlen(_Context->msg_Auto3610[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+110,519+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+110+1,519,16,vfh[1],27,28,_Context->buffer_IMAGEPATH,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+30,_Context->y_Auto3584+140,154,20,vfh[3],27,0,_Context->msg_Auto3611[_Context->language],strlen(_Context->msg_Auto3611[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+30,_Context->y_Auto3584+170,154,20,vfh[3],27,0,_Context->msg_Auto3612[_Context->language],strlen(_Context->msg_Auto3612[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+30,_Context->y_Auto3584+200,184,20,vfh[3],27,0,_Context->msg_Auto3613[_Context->language],strlen(_Context->msg_Auto3613[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+30,_Context->y_Auto3584+230,154,20,vfh[3],27,0,_Context->msg_Auto3614[_Context->language],strlen(_Context->msg_Auto3614[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+30,_Context->y_Auto3584+260,138,20,vfh[3],27,0,_Context->msg_Auto3615[_Context->language],strlen(_Context->msg_Auto3615[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+30,_Context->y_Auto3584+290,184,20,vfh[3],27,0,_Context->msg_Auto3616[_Context->language],strlen(_Context->msg_Auto3616[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_text(_Context->x_Auto3584+460,_Context->y_Auto3584+230,184,20,vfh[3],27,0,_Context->msg_Auto3617[_Context->language],strlen(_Context->msg_Auto3617[_Context->language]),2);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+140,519+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+140+1,519,16,vfh[1],27,28,_Context->buffer_ICONPATH,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+170,519+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+170+1,519,16,vfh[1],27,28,_Context->buffer_PALETTE,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+200,544+2,15+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+200+1,544,15,vfh[1],27,28,_Context->buffer_SKIN,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_select(_Context->x_Auto3584+210,_Context->y_Auto3584+230,184,80,vfh[1],27,28,parse_selection(_Context->msg_TRIGGER_STYLE[_Context->language],&_Context->value_TRIGGER_STYLE),512);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3584+660,_Context->y_Auto3584+230,88+2,16+2,5);
	visual_text(_Context->x_Auto3584+660+1,_Context->y_Auto3584+230+1,88,16,vfh[1],27,28,_Context->buffer_TRIGGER_COLOUR,11,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+260,520+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+260+1,520,16,vfh[1],27,28,_Context->buffer_STYLEPATH,255,0);
		}
	if (_Context->page_number == 3 ) {
	visual_frame(_Context->x_Auto3584+210,_Context->y_Auto3584+290,520+2,16+2,5);
	visual_text(_Context->x_Auto3584+210+1,_Context->y_Auto3584+290+1,520,16,vfh[1],27,28,_Context->buffer_COMPONENTPATH,255,0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),0);
		}
	if (_Context->page_number == 3 ) {
	_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_Fonts=visual_trigger_code(_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]),230,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Fonts[_Context->language],strlen(_Context->msg_Fonts[_Context->language]),230,0);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+150,700,16,vfh[2],27,0,_Context->msg_Auto3618[_Context->language],strlen(_Context->msg_Auto3618[_Context->language]),2);
	visual_frame(_Context->x_Auto3584+40,_Context->y_Auto3584+166,700,314,4);
		}
	if (_Context->page_number == 4 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+110,154,20,vfh[3],27,0,_Context->msg_Auto3619[_Context->language],strlen(_Context->msg_Auto3619[_Context->language]),2);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+110,519+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+110+1,519,16,vfh[1],27,28,_Context->buffer_FONTPATH,255,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+180,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+180+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB1,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+210,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+210+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB2,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+240,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+240+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB3,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+270,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+270+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB4,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+300,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+300+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB5,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+330,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+330+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB6,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+360,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+360+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB7,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+390,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+390+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB8,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+420,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+420+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB9,32,0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+450,144+2,16+2,5);
	visual_text(_Context->x_Auto3584+50+1,_Context->y_Auto3584+450+1,144,16,vfh[1],0,0,_Context->buffer_FONTLAB10,32,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+725,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+180,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+180+1,503,16,vfh[1],27,28,_Context->buffer_FONT1,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+210,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+210+1,503,16,vfh[1],27,28,_Context->buffer_FONT2,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+240,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+240+1,503,16,vfh[1],27,28,_Context->buffer_FONT3,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+270,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+270+1,503,16,vfh[1],27,28,_Context->buffer_FONT4,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+300,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+300+1,503,16,vfh[1],27,28,_Context->buffer_FONT5,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+330,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+330+1,503,16,vfh[1],27,28,_Context->buffer_FONT6,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+360,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+360+1,503,16,vfh[1],27,28,_Context->buffer_FONT7,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+390,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+390+1,503,16,vfh[1],27,28,_Context->buffer_FONT8,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+420,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+420+1,503,16,vfh[1],27,28,_Context->buffer_FONT9,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),0);
		}
	if (_Context->page_number == 4 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+450,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+450+1,503,16,vfh[1],27,28,_Context->buffer_FONT10,259,0);
		}
	if (_Context->page_number == 4 ) {
	_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_Documents=visual_trigger_code(_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]),311,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Documents[_Context->language],strlen(_Context->msg_Documents[_Context->language]),311,0);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+80,710,16,vfh[2],27,0,_Context->msg_Auto3620[_Context->language],strlen(_Context->msg_Auto3620[_Context->language]),2);
	visual_frame(_Context->x_Auto3584+40,_Context->y_Auto3584+96,710,424,4);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+110,140,20,vfh[3],27,0,_Context->msg_Auto3621[_Context->language],strlen(_Context->msg_Auto3621[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+140,140,20,vfh[3],27,0,_Context->msg_Auto3622[_Context->language],strlen(_Context->msg_Auto3622[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+170,140,20,vfh[3],27,0,_Context->msg_Auto3623[_Context->language],strlen(_Context->msg_Auto3623[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+200,140,20,vfh[3],27,0,_Context->msg_Auto3624[_Context->language],strlen(_Context->msg_Auto3624[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+230,140,20,vfh[3],27,0,_Context->msg_Auto3625[_Context->language],strlen(_Context->msg_Auto3625[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+260,140,20,vfh[3],27,0,_Context->msg_Auto3626[_Context->language],strlen(_Context->msg_Auto3626[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+290,140,20,vfh[3],27,0,_Context->msg_Auto3627[_Context->language],strlen(_Context->msg_Auto3627[_Context->language]),2);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+110,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+110+1,528,16,vfh[1],27,28,_Context->buffer_HTML_TITLE,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+140,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+140+1,528,16,vfh[1],27,28,_Context->buffer_HTML_LOGO,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+170,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+170+1,528,16,vfh[1],27,28,_Context->buffer_HTML_COPYRIGHT,66,0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+200,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+200+1,503,16,vfh[1],27,28,_Context->buffer_SCREEN_CSS,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+230,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+230+1,503,16,vfh[1],27,28,_Context->buffer_PRINT_CSS,259,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+260,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+260+1,503,16,vfh[1],27,28,_Context->buffer_NAVIGATOR,255,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),0);
		}
	if (_Context->page_number == 5 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+290,503+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+290+1,503,16,vfh[1],27,28,_Context->buffer_DOCPATH,255,0);
		}
	if (_Context->page_number == 5 ) {
	_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_Printing=visual_trigger_code(_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]),416,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Printing[_Context->language],strlen(_Context->msg_Printing[_Context->language]),416,0);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+110,154,20,vfh[3],27,0,_Context->msg_Auto3628[_Context->language],strlen(_Context->msg_Auto3628[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+150,154,20,vfh[3],27,0,_Context->msg_Auto3629[_Context->language],strlen(_Context->msg_Auto3629[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3584+440,_Context->y_Auto3584+150,154,20,vfh[3],27,0,_Context->msg_Auto3630[_Context->language],strlen(_Context->msg_Auto3630[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3584+40,_Context->y_Auto3584+190,154,20,vfh[3],27,0,_Context->msg_Auto3631[_Context->language],strlen(_Context->msg_Auto3631[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_text(_Context->x_Auto3584+440,_Context->y_Auto3584+190,154,20,vfh[3],27,0,_Context->msg_Auto3632[_Context->language],strlen(_Context->msg_Auto3632[_Context->language]),2);
		}
	if (_Context->page_number == 6 ) {
	visual_frame(_Context->x_Auto3584+200,_Context->y_Auto3584+110,504+2,16+2,5);
	visual_text(_Context->x_Auto3584+200+1,_Context->y_Auto3584+110+1,504,16,vfh[1],27,28,_Context->buffer_PRINTER,259,0);
		}
	if (_Context->page_number == 6 ) {
	_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),0);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3584+590,_Context->y_Auto3584+150,152,48,vfh[1],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3584+200,_Context->y_Auto3584+190,144,48,vfh[1],0,0,parse_selection(_Context->msg_LAYOUT[_Context->language],&_Context->value_LAYOUT),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3584+590,_Context->y_Auto3584+190,152,48,vfh[1],27,0,parse_selection(_Context->msg_PAGEFEED[_Context->language],&_Context->value_PAGEFEED),768);
		}
	if (_Context->page_number == 6 ) {
	visual_select(_Context->x_Auto3584+200,_Context->y_Auto3584+150,144,64,vfh[1],27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),768);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_Editor=visual_trigger_code(_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]),518,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Editor[_Context->language],strlen(_Context->msg_Editor[_Context->language]),518,0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+120,140,20,vfh[3],27,0,_Context->msg_Auto3633[_Context->language],strlen(_Context->msg_Auto3633[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+170,140,20,vfh[3],27,0,_Context->msg_Auto3634[_Context->language],strlen(_Context->msg_Auto3634[_Context->language]),2);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+230,690,16,vfh[2],27,0,_Context->msg_Auto3635[_Context->language],strlen(_Context->msg_Auto3635[_Context->language]),2);
	visual_frame(_Context->x_Auto3584+50,_Context->y_Auto3584+246,690,74,4);
		}
	if (_Context->page_number == 7 ) {
	visual_frame(_Context->x_Auto3584+220,_Context->y_Auto3584+120,496+2,16+2,5);
	visual_text(_Context->x_Auto3584+220+1,_Context->y_Auto3584+120+1,496,16,vfh[1],27,28,_Context->buffer_AED,255,0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),0);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3584+220,_Context->y_Auto3584+170,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_AED_STATE=visual_trigger_code(_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]));
	visual_check(_Context->x_Auto3584+90,_Context->y_Auto3584+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),_Context->value_AED_STATE|0);
		}
	if (_Context->page_number == 7 ) {
	_Context->trigger_AED_SYNTAX=visual_trigger_code(_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]));
	visual_check(_Context->x_Auto3584+340,_Context->y_Auto3584+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),_Context->value_AED_SYNTAX|0);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+60,_Context->y_Auto3584+260,126,16,vfh[2],27,0,_Context->msg_auto6060[_Context->language],strlen(_Context->msg_auto6060[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+200,_Context->y_Auto3584+260,112,16,vfh[2],27,0,_Context->msg_auto6061[_Context->language],strlen(_Context->msg_auto6061[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+340,_Context->y_Auto3584+260,110,20,vfh[2],27,0,_Context->msg_auto6062[_Context->language],strlen(_Context->msg_auto6062[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+470,_Context->y_Auto3584+260,110,20,vfh[2],27,0,_Context->msg_auto6063[_Context->language],strlen(_Context->msg_auto6063[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_text(_Context->x_Auto3584+600,_Context->y_Auto3584+260,126,16,vfh[2],27,0,_Context->msg_auto6064[_Context->language],strlen(_Context->msg_auto6064[_Context->language]),259);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3584+60,_Context->y_Auto3584+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3584+200,_Context->y_Auto3584+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3584+470,_Context->y_Auto3584+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3584+340,_Context->y_Auto3584+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),768);
		}
	if (_Context->page_number == 7 ) {
	visual_select(_Context->x_Auto3584+600,_Context->y_Auto3584+280,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),768);
		}
	_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
	visual_button(_Context->x_Auto3584+20,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
	_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+120,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
	_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
	visual_button(_Context->x_Auto3584+220,_Context->y_Auto3584+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),0);
	_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
	visual_button(_Context->x_Auto3584+470,_Context->y_Auto3584+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),0);
	_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+324,_Context->y_Auto3584+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
	_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
	visual_button(_Context->x_Auto3584+396,_Context->y_Auto3584+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
	_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+570,_Context->y_Auto3584+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
	_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
	visual_button(_Context->x_Auto3584+672,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
	if (_Context->page_number == 8 ) {
	_Context->trigger_Project=visual_trigger_code(_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]));
	visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]),599,2);
	} else {
		visual_tabpage(_Context->x_Auto3584+20,_Context->y_Auto3584+40,750,500,vfh[2],_Context->msg_Project[_Context->language],strlen(_Context->msg_Project[_Context->language]),599,0);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+120,140,20,vfh[3],27,0,_Context->msg_Auto3636[_Context->language],strlen(_Context->msg_Auto3636[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+150,161,20,vfh[3],27,0,_Context->msg_Auto3637[_Context->language],strlen(_Context->msg_Auto3637[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+180,161,20,vfh[3],27,0,_Context->msg_Auto3638[_Context->language],strlen(_Context->msg_Auto3638[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_text(_Context->x_Auto3584+50,_Context->y_Auto3584+210,161,20,vfh[3],27,0,_Context->msg_Auto3639[_Context->language],strlen(_Context->msg_Auto3639[_Context->language]),2);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3584+220,_Context->y_Auto3584+120,496+2,16+2,5);
	visual_text(_Context->x_Auto3584+220+1,_Context->y_Auto3584+120+1,496,16,vfh[1],27,28,_Context->buffer_AMAKE,255,0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3584+220,_Context->y_Auto3584+150,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+220+1,_Context->y_Auto3584+150+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE_OPTIONS,255,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3584+220,_Context->y_Auto3584+180,528+2,16+2,5);
	visual_text(_Context->x_Auto3584+220+1,_Context->y_Auto3584+180+1,528,16,vfh[1],27,28,_Context->buffer_AMAKE_DEFINE,255,0);
		}
	if (_Context->page_number == 8 ) {
	visual_frame(_Context->x_Auto3584+220,_Context->y_Auto3584+210,496+2,16+2,5);
	visual_text(_Context->x_Auto3584+220+1,_Context->y_Auto3584+210+1,496,16,vfh[1],27,28,_Context->buffer_AMAKE_LIST,255,0);
		}
	if (_Context->page_number == 8 ) {
	_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),0);
		}
	visual_thaw(_Context->x_Auto3584,_Context->y_Auto3584,790,600);

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

private int Auto3584action(struct accept_configuration_context * _Context) {
	int x=visual_event(7);
	int y=visual_event(6);
	do {
		do {

			while(visual_getch() != 256);
			}
		while( visual_kbhit() );
		visual_freeze();
			accept_configuration_hide(_Context);

		_Context->x_Auto3584 += (visual_event(7)-x);
		x=visual_event(7);
		if (_Context->x_Auto3584 < 0) { _Context->x_Auto3584=0; }
		_Context->y_Auto3584 += (visual_event(6)-y);
		y=visual_event(6);
		if (_Context->y_Auto3584 < 0) { _Context->y_Auto3584=0; }
			accept_configuration_show(_Context);

		visual_thaw(_Context->x_Auto3584,_Context->y_Auto3584,790,600);
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
		if (_Context->trigger_Images == mb ) return(36);
		if (_Context->trigger_ChoixIMAGEPATH == mb ) return(38);
		if (_Context->trigger_ChoixICONPATH == mb ) return(40);
		if (_Context->trigger_ChoixPALETTE == mb ) return(42);
		if (_Context->trigger_ChoixSTYLEPATH == mb ) return(48);
		if (_Context->trigger_ChoixCOMPPATH == mb ) return(49);
		if (_Context->trigger_Fonts == mb ) return(50);
		if (_Context->trigger_ChoixFONTPATH == mb ) return(62);
		if (_Context->trigger_ChoixFONT1 == mb ) return(64);
		if (_Context->trigger_ChoixFONT2 == mb ) return(66);
		if (_Context->trigger_ChoixFONT3 == mb ) return(68);
		if (_Context->trigger_ChoixFONT4 == mb ) return(70);
		if (_Context->trigger_ChoixFONT5 == mb ) return(72);
		if (_Context->trigger_ChoixFONT6 == mb ) return(74);
		if (_Context->trigger_ChoixFONT7 == mb ) return(76);
		if (_Context->trigger_ChoixFONT8 == mb ) return(78);
		if (_Context->trigger_ChoixFONT9 == mb ) return(80);
		if (_Context->trigger_ChoixFONT10 == mb ) return(82);
		if (_Context->trigger_Documents == mb ) return(83);
		if (_Context->trigger_ChoixSCREEN_CSS == mb ) return(88);
		if (_Context->trigger_ChoixPRINT_CSS == mb ) return(90);
		if (_Context->trigger_ChoixNAVIGATOR == mb ) return(92);
		if (_Context->trigger_ChoixDOCPATH == mb ) return(94);
		if (_Context->trigger_Printing == mb ) return(95);
		if (_Context->trigger_ChoixPRINTER == mb ) return(97);
		if (_Context->trigger_Editor == mb ) return(102);
		if (_Context->trigger_ChoixAED == mb ) return(104);
		if (_Context->trigger_AED_STATE == mb ) return(106);
		if (_Context->trigger_AED_SYNTAX == mb ) return(107);
		if (_Context->trigger_ACCEPT == mb ) return(113);
		if (_Context->trigger_SAVEFILE == mb ) return(114);
		if (_Context->trigger_SAVELDAP == mb ) return(115);
		if (_Context->trigger_LoadLdap == mb ) return(116);
		if (_Context->trigger_EDITFILE == mb ) return(117);
		if (_Context->trigger_DELETE == mb ) return(118);
		if (_Context->trigger_LOADFILE == mb ) return(119);
		if (_Context->trigger_CANCEL == mb ) return(120);
		if (_Context->trigger_Project == mb ) return(121);
		if (_Context->trigger_choixAMAKE == mb ) return(123);
		if (_Context->trigger_choixAMAKE_LIST == mb ) return(127);
		return(-1);
		}
	if (!((mt = visual_event(1)) & 0x3031)) return(-1); 
	mx = visual_event(7);
	my = visual_event(6);
	switch (mt) {
	case _MIMO_UP :
	if ((mx >= (_Context->x_Auto3584+769) )  
	&&  (my >= (_Context->y_Auto3584+4) )  
	&&  (mx <= (_Context->x_Auto3584+786) )  
	&&  (my <= (_Context->y_Auto3584+20) )) {
		return(1);	/* Auto3584 */

		}
	if ((mx >= (_Context->x_Auto3584+753) )  
	&&  (my >= (_Context->y_Auto3584+4) )  
	&&  (mx <= (_Context->x_Auto3584+770) )  
	&&  (my <= (_Context->y_Auto3584+20) )) {
				if ( visual_event(1) & _MIMO_UP ) {
			visual_help("vrefer.htm");
			};
		return(-1);	/* Auto3584 */

		}
	if ((mx >= (_Context->x_Auto3584+737) )  
	&&  (my >= (_Context->y_Auto3584+4) )  
	&&  (mx <= (_Context->x_Auto3584+754) )  
	&&  (my <= (_Context->y_Auto3584+20) )) {
				if (visual_event(2) ==_MIMO_LEFT) {
			_Context->language++; _Context->language %=8;
			}
		else {
		if ( _Context->language > 0 ) { _Context->language--; _Context->language %=8; }
		else { _Context->language=7; }
			}
		(void) visual_national_language(_Context->language);
		accept_configuration_show(_Context);
		return(-1);	/* Auto3584 */

		}
	case _MIMO_DOWN :
		if ((mx >= (_Context->x_Auto3584+4) )  
		&&  (my >= (_Context->y_Auto3584+4) )  
		&&  (mx <= (_Context->x_Auto3584+722) )  
		&&  (my <= (_Context->y_Auto3584+20) )) {
			return( Auto3584action(_Context) );
			}
		}
	if (_Context->page_number == 1 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+0) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+83) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(2); /* General */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+150) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+493) ) 
		&&  ( my <= (_Context->y_Auto3584+150+16))) {
			return(3); /* FILENAME */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+150) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+150+18))) {
			return(4); /* ChoixFILENAME */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+180) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+520) ) 
		&&  ( my <= (_Context->y_Auto3584+180+16))) {
			return(5); /* ABALHOST */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+210) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+520) ) 
		&&  ( my <= (_Context->y_Auto3584+210+16))) {
			return(6); /* IDENTITY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+250) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+520) ) 
		&&  ( my <= (_Context->y_Auto3584+250+16))) {
			return(7); /* REPLAY */
			}
		}
	if (_Context->page_number == 1 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+520) ) 
		&&  ( my <= (_Context->y_Auto3584+280+16))) {
			return(8); /* RECORD */
			}
		}
	if (_Context->page_number == 2 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+84) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+149) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(9); /* Abal */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+100) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+100+16))) {
			return(10); /* ATR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+100) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+100+18))) {
			return(11); /* ChoixATR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+120) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+120+16))) {
			return(12); /* ATR_DEFINE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+140) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+140+16))) {
			return(13); /* ATR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+140) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+140+18))) {
			return(14); /* ChoixATR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+160) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+160+16))) {
			return(15); /* ATR_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+180) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+180+16))) {
			return(16); /* ALD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+180) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+180+18))) {
			return(17); /* ChoixALD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+200) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+200+16))) {
			return(18); /* ALD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+200) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+200+18))) {
			return(19); /* ChoixALD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+220) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+220+16))) {
			return(20); /* ALD_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+280+16))) {
			return(21); /* OTR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+280+18))) {
			return(22); /* ChoixOTR */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+300) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+300+16))) {
			return(23); /* OTR_DEFINE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+320) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+320+16))) {
			return(24); /* OTR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+320) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+320+18))) {
			return(25); /* ChoixOTR_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+340) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+340+16))) {
			return(26); /* OTR_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+360) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+360+16))) {
			return(27); /* OLD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+360) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+360+18))) {
			return(28); /* ChoixOLD */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+380) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+380+16))) {
			return(29); /* OLD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+380) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+380+18))) {
			return(30); /* ChoixOLD_INCLUDE */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+400) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+400+16))) {
			return(31); /* OLD_OPTIONS */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+470) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+470+16))) {
			return(32); /* EXA */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+470) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+470+18))) {
			return(33); /* ChoixEXA */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+490) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+490+16))) {
			return(34); /* EXADB */
			}
		}
	if (_Context->page_number == 2 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+490) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+490+18))) {
			return(35); /* ChoixEXADB */
			}
		}
	if (_Context->page_number == 3 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+150) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+229) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(36); /* Images */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+110) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+519) ) 
		&&  ( my <= (_Context->y_Auto3584+110+16))) {
			return(37); /* IMAGEPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+735) ) 
		&&  ( my >= (_Context->y_Auto3584+110) ) 
		&&  ( mx <= (_Context->x_Auto3584+735+20) ) 
		&&  ( my <= (_Context->y_Auto3584+110+18))) {
			return(38); /* ChoixIMAGEPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+140) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+519) ) 
		&&  ( my <= (_Context->y_Auto3584+140+16))) {
			return(39); /* ICONPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+735) ) 
		&&  ( my >= (_Context->y_Auto3584+140) ) 
		&&  ( mx <= (_Context->x_Auto3584+735+20) ) 
		&&  ( my <= (_Context->y_Auto3584+140+18))) {
			return(40); /* ChoixICONPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+170) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+519) ) 
		&&  ( my <= (_Context->y_Auto3584+170+16))) {
			return(41); /* PALETTE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+735) ) 
		&&  ( my >= (_Context->y_Auto3584+170) ) 
		&&  ( mx <= (_Context->x_Auto3584+735+20) ) 
		&&  ( my <= (_Context->y_Auto3584+170+18))) {
			return(42); /* ChoixPALETTE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+200) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+544) ) 
		&&  ( my <= (_Context->y_Auto3584+200+15))) {
			return(43); /* SKIN */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+210+0) ) 
		&&  ( my >= (_Context->y_Auto3584+230) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+184) ) 
		&&  ( my <= (_Context->y_Auto3584+230+16))) {
			return(44); /* TRIGGER_STYLE */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+660) ) 
		&&  ( my >= (_Context->y_Auto3584+230) ) 
		&&  ( mx <= (_Context->x_Auto3584+660+88) ) 
		&&  ( my <= (_Context->y_Auto3584+230+16))) {
			return(45); /* TRIGGER_COLOUR */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+260) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+520) ) 
		&&  ( my <= (_Context->y_Auto3584+260+16))) {
			return(46); /* STYLEPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+210) ) 
		&&  ( my >= (_Context->y_Auto3584+290) ) 
		&&  ( mx <= (_Context->x_Auto3584+210+520) ) 
		&&  ( my <= (_Context->y_Auto3584+290+16))) {
			return(47); /* COMPONENTPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+735) ) 
		&&  ( my >= (_Context->y_Auto3584+260) ) 
		&&  ( mx <= (_Context->x_Auto3584+735+20) ) 
		&&  ( my <= (_Context->y_Auto3584+260+18))) {
			return(48); /* ChoixSTYLEPATH */
			}
		}
	if (_Context->page_number == 3 ) {
		if (( mx >= (_Context->x_Auto3584+735) ) 
		&&  ( my >= (_Context->y_Auto3584+289) ) 
		&&  ( mx <= (_Context->x_Auto3584+735+20) ) 
		&&  ( my <= (_Context->y_Auto3584+289+18))) {
			return(49); /* ChoixCOMPPATH */
			}
		}
	if (_Context->page_number == 4 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+230) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+310) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(50); /* Fonts */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+110) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+519) ) 
		&&  ( my <= (_Context->y_Auto3584+110+16))) {
			return(51); /* FONTPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+180) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+180+16))) {
			return(52); /* FONTLAB1 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+210) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+210+16))) {
			return(53); /* FONTLAB2 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+240) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+240+16))) {
			return(54); /* FONTLAB3 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+270) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+270+16))) {
			return(55); /* FONTLAB4 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+300) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+300+16))) {
			return(56); /* FONTLAB5 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+330) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+330+16))) {
			return(57); /* FONTLAB6 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+360) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+360+16))) {
			return(58); /* FONTLAB7 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+390) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+390+16))) {
			return(59); /* FONTLAB8 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+420) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+420+16))) {
			return(60); /* FONTLAB9 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+50) ) 
		&&  ( my >= (_Context->y_Auto3584+450) ) 
		&&  ( mx <= (_Context->x_Auto3584+50+144) ) 
		&&  ( my <= (_Context->y_Auto3584+450+16))) {
			return(61); /* FONTLAB10 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+725) ) 
		&&  ( my >= (_Context->y_Auto3584+110) ) 
		&&  ( mx <= (_Context->x_Auto3584+725+20) ) 
		&&  ( my <= (_Context->y_Auto3584+110+18))) {
			return(62); /* ChoixFONTPATH */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+180) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+180+16))) {
			return(63); /* FONT1 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+180) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+180+18))) {
			return(64); /* ChoixFONT1 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+210) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+210+16))) {
			return(65); /* FONT2 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+210) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+210+18))) {
			return(66); /* ChoixFONT2 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+240) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+240+16))) {
			return(67); /* FONT3 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+240) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+240+18))) {
			return(68); /* ChoixFONT3 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+270) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+270+16))) {
			return(69); /* FONT4 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+270) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+270+18))) {
			return(70); /* ChoixFONT4 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+300) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+300+16))) {
			return(71); /* FONT5 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+300) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+300+18))) {
			return(72); /* ChoixFONT5 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+330) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+330+16))) {
			return(73); /* FONT6 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+330) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+330+18))) {
			return(74); /* ChoixFONT6 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+360) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+360+16))) {
			return(75); /* FONT7 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+360) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+360+18))) {
			return(76); /* ChoixFONT7 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+390) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+390+16))) {
			return(77); /* FONT8 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+390) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+390+18))) {
			return(78); /* ChoixFONT8 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+420) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+420+16))) {
			return(79); /* FONT9 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+420) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+420+18))) {
			return(80); /* ChoixFONT9 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+450) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+450+16))) {
			return(81); /* FONT10 */
			}
		}
	if (_Context->page_number == 4 ) {
		if (( mx >= (_Context->x_Auto3584+708) ) 
		&&  ( my >= (_Context->y_Auto3584+450) ) 
		&&  ( mx <= (_Context->x_Auto3584+708+20) ) 
		&&  ( my <= (_Context->y_Auto3584+450+18))) {
			return(82); /* ChoixFONT10 */
			}
		}
	if (_Context->page_number == 5 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+311) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+415) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(83); /* Documents */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+110) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+110+16))) {
			return(84); /* HTML_TITLE */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+140) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+140+16))) {
			return(85); /* HTML_LOGO */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+170) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+528) ) 
		&&  ( my <= (_Context->y_Auto3584+170+16))) {
			return(86); /* HTML_COPYRIGHT */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+200) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+200+16))) {
			return(87); /* SCREEN_CSS */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+200) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+200+18))) {
			return(88); /* ChoixSCREEN_CSS */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+230) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+230+16))) {
			return(89); /* PRINT_CSS */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+230) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+230+18))) {
			return(90); /* ChoixPRINT_CSS */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+260) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+260+16))) {
			return(91); /* NAVIGATOR */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+260) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+260+18))) {
			return(92); /* ChoixNAVIGATOR */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+290) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+503) ) 
		&&  ( my <= (_Context->y_Auto3584+290+16))) {
			return(93); /* DOCPATH */
			}
		}
	if (_Context->page_number == 5 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+290) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+290+18))) {
			return(94); /* ChoixDOCPATH */
			}
		}
	if (_Context->page_number == 6 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+416) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+517) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(95); /* Printing */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3584+200) ) 
		&&  ( my >= (_Context->y_Auto3584+110) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+504) ) 
		&&  ( my <= (_Context->y_Auto3584+110+16))) {
			return(96); /* PRINTER */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3584+710) ) 
		&&  ( my >= (_Context->y_Auto3584+110) ) 
		&&  ( mx <= (_Context->x_Auto3584+710+20) ) 
		&&  ( my <= (_Context->y_Auto3584+110+18))) {
			return(97); /* ChoixPRINTER */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3584+590+0) ) 
		&&  ( my >= (_Context->y_Auto3584+150) ) 
		&&  ( mx <= (_Context->x_Auto3584+590+152) ) 
		&&  ( my <= (_Context->y_Auto3584+150+16))) {
			return(98); /* PAPERTYPE */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3584+200+0) ) 
		&&  ( my >= (_Context->y_Auto3584+190) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+144) ) 
		&&  ( my <= (_Context->y_Auto3584+190+16))) {
			return(99); /* LAYOUT */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3584+590+0) ) 
		&&  ( my >= (_Context->y_Auto3584+190) ) 
		&&  ( mx <= (_Context->x_Auto3584+590+152) ) 
		&&  ( my <= (_Context->y_Auto3584+190+16))) {
			return(100); /* PAGEFEED */
			}
		}
	if (_Context->page_number == 6 ) {
		if (( mx >= (_Context->x_Auto3584+200+0) ) 
		&&  ( my >= (_Context->y_Auto3584+150) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+144) ) 
		&&  ( my <= (_Context->y_Auto3584+150+16))) {
			return(101); /* RESOLUTION */
			}
		}
	if (_Context->page_number == 7 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+518) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+598) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(102); /* Editor */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+220) ) 
		&&  ( my >= (_Context->y_Auto3584+120) ) 
		&&  ( mx <= (_Context->x_Auto3584+220+496) ) 
		&&  ( my <= (_Context->y_Auto3584+120+16))) {
			return(103); /* AED */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+720) ) 
		&&  ( my >= (_Context->y_Auto3584+120) ) 
		&&  ( mx <= (_Context->x_Auto3584+720+20) ) 
		&&  ( my <= (_Context->y_Auto3584+120+18))) {
			return(104); /* ChoixAED */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+220+0) ) 
		&&  ( my >= (_Context->y_Auto3584+170) ) 
		&&  ( mx <= (_Context->x_Auto3584+220+150) ) 
		&&  ( my <= (_Context->y_Auto3584+170+16))) {
			return(105); /* AED_FONT */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+90) ) 
		&&  ( my >= (_Context->y_Auto3584+350) ) 
		&&  ( mx <= (_Context->x_Auto3584+90+207) ) 
		&&  ( my <= (_Context->y_Auto3584+350+20))) {
			return(106); /* AED_STATE */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+340) ) 
		&&  ( my >= (_Context->y_Auto3584+350) ) 
		&&  ( mx <= (_Context->x_Auto3584+340+207) ) 
		&&  ( my <= (_Context->y_Auto3584+350+20))) {
			return(107); /* AED_SYNTAX */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+60+0) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+60+120) ) 
		&&  ( my <= (_Context->y_Auto3584+280+16))) {
			return(108); /* AED_NORMAL */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+200+0) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+200+120) ) 
		&&  ( my <= (_Context->y_Auto3584+280+16))) {
			return(109); /* AED_QUOTE */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+470+0) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+470+112) ) 
		&&  ( my <= (_Context->y_Auto3584+280+16))) {
			return(110); /* AED_COMMENT */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+340+0) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+340+112) ) 
		&&  ( my <= (_Context->y_Auto3584+280+16))) {
			return(111); /* AED_KEYWORD */
			}
		}
	if (_Context->page_number == 7 ) {
		if (( mx >= (_Context->x_Auto3584+600+0) ) 
		&&  ( my >= (_Context->y_Auto3584+280) ) 
		&&  ( mx <= (_Context->x_Auto3584+600+120) ) 
		&&  ( my <= (_Context->y_Auto3584+280+16))) {
			return(112); /* AED_PUNCTUATE */
			}
		}
	if (( mx >= (_Context->x_Auto3584+20) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+20+98) ) 
	&&  ( my <= (_Context->y_Auto3584+550+32))) {
		return(113); /* ACCEPT */
		}
	if (( mx >= (_Context->x_Auto3584+120) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+120+98) ) 
	&&  ( my <= (_Context->y_Auto3584+550+32))) {
		return(114); /* SAVEFILE */
		}
	if (( mx >= (_Context->x_Auto3584+220) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+220+102) ) 
	&&  ( my <= (_Context->y_Auto3584+550+33))) {
		return(115); /* SAVELDAP */
		}
	if (( mx >= (_Context->x_Auto3584+470) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+470+98) ) 
	&&  ( my <= (_Context->y_Auto3584+550+32))) {
		return(116); /* LoadLdap */
		}
	if (( mx >= (_Context->x_Auto3584+324) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+324+70) ) 
	&&  ( my <= (_Context->y_Auto3584+550+32))) {
		return(117); /* EDITFILE */
		}
	if (( mx >= (_Context->x_Auto3584+396) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+396+72) ) 
	&&  ( my <= (_Context->y_Auto3584+550+32))) {
		return(118); /* DELETE */
		}
	if (( mx >= (_Context->x_Auto3584+570) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+570+100) ) 
	&&  ( my <= (_Context->y_Auto3584+550+32))) {
		return(119); /* LOADFILE */
		}
	if (( mx >= (_Context->x_Auto3584+672) ) 
	&&  ( my >= (_Context->y_Auto3584+550) ) 
	&&  ( mx <= (_Context->x_Auto3584+672+98) ) 
	&&  ( my <= (_Context->y_Auto3584+550+32))) {
		return(120); /* CANCEL */
		}
	if (_Context->page_number == 8 ) {
	} else {
		if (( mx >= (_Context->x_Auto3584+20+599) ) 
		&&  ( my >= (_Context->y_Auto3584+40) ) 
		&&  ( mx <= (_Context->x_Auto3584+20+681) ) 
		&&  ( my <= (_Context->y_Auto3584+40+24))) {
			return(121); /* Project */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3584+220) ) 
		&&  ( my >= (_Context->y_Auto3584+120) ) 
		&&  ( mx <= (_Context->x_Auto3584+220+496) ) 
		&&  ( my <= (_Context->y_Auto3584+120+16))) {
			return(122); /* AMAKE */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3584+720) ) 
		&&  ( my >= (_Context->y_Auto3584+120) ) 
		&&  ( mx <= (_Context->x_Auto3584+720+20) ) 
		&&  ( my <= (_Context->y_Auto3584+120+18))) {
			return(123); /* choixAMAKE */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3584+220) ) 
		&&  ( my >= (_Context->y_Auto3584+150) ) 
		&&  ( mx <= (_Context->x_Auto3584+220+528) ) 
		&&  ( my <= (_Context->y_Auto3584+150+16))) {
			return(124); /* AMAKE_OPTIONS */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3584+220) ) 
		&&  ( my >= (_Context->y_Auto3584+180) ) 
		&&  ( mx <= (_Context->x_Auto3584+220+528) ) 
		&&  ( my <= (_Context->y_Auto3584+180+16))) {
			return(125); /* AMAKE_DEFINE */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3584+220) ) 
		&&  ( my >= (_Context->y_Auto3584+210) ) 
		&&  ( mx <= (_Context->x_Auto3584+220+496) ) 
		&&  ( my <= (_Context->y_Auto3584+210+16))) {
			return(126); /* AMAKE_LIST */
			}
		}
	if (_Context->page_number == 8 ) {
		if (( mx >= (_Context->x_Auto3584+720) ) 
		&&  ( my >= (_Context->y_Auto3584+210) ) 
		&&  ( mx <= (_Context->x_Auto3584+720+20) ) 
		&&  ( my <= (_Context->y_Auto3584+210+18))) {
			return(127); /* choixAMAKE_LIST */
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
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+150+1,493,16,vfh[1],_Context->buffer_FILENAME,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4 :
				/* ChoixFILENAME */
				if (_Context->page_number == 1 ) {
					_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5 :
				/* ABALHOST */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+180+1,520,16,vfh[1],_Context->buffer_ABALHOST,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x6 :
				/* IDENTITY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+210+1,520,16,vfh[1],_Context->buffer_IDENTITY,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7 :
				/* REPLAY */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+250+1,520,16,vfh[1],_Context->buffer_REPLAY,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x8 :
				/* RECORD */
				if (_Context->page_number == 1 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+280+1,520,16,vfh[1],_Context->buffer_RECORD,255);
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
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+100+1,503,16,vfh[1],_Context->buffer_ATR,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xb :
				/* ChoixATR */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xc :
				/* ATR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+120+1,528,16,vfh[1],_Context->buffer_ATR_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xd :
				/* ATR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+140+1,503,16,vfh[1],_Context->buffer_ATR_INCLUDE,1024);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0xe :
				/* ChoixATR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0xf :
				/* ATR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+160+1,528,16,vfh[1],_Context->buffer_ATR_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x10 :
				/* ALD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+180+1,503,16,vfh[1],_Context->buffer_ALD,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x11 :
				/* ChoixALD */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x12 :
				/* ALD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+200+1,503,16,vfh[1],_Context->buffer_ALD_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x13 :
				/* ChoixALD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x14 :
				/* ALD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+220+1,528,16,vfh[1],_Context->buffer_ALD_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x15 :
				/* OTR */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+280+1,503,16,vfh[1],_Context->buffer_OTR,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x16 :
				/* ChoixOTR */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x17 :
				/* OTR_DEFINE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+300+1,528,16,vfh[1],_Context->buffer_OTR_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x18 :
				/* OTR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+320+1,503,16,vfh[1],_Context->buffer_OTR_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x19 :
				/* ChoixOTR_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1a :
				/* OTR_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+340+1,528,16,vfh[1],_Context->buffer_OTR_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1b :
				/* OLD */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+360+1,503,16,vfh[1],_Context->buffer_OLD,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1c :
				/* ChoixOLD */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1d :
				/* OLD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+380+1,503,16,vfh[1],_Context->buffer_OLD_INCLUDE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x1e :
				/* ChoixOLD_INCLUDE */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x1f :
				/* OLD_OPTIONS */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+400+1,528,16,vfh[1],_Context->buffer_OLD_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x20 :
				/* EXA */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+470+1,503,16,vfh[1],_Context->buffer_EXA,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x21 :
				/* ChoixEXA */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x22 :
				/* EXADB */
				if (_Context->page_number == 2 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+490+1,503,16,vfh[1],_Context->buffer_EXADB,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x23 :
				/* ChoixEXADB */
				if (_Context->page_number == 2 ) {
					_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x24 :
				/* Images */
				if (_Context->page_number == 3 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x25 :
				/* IMAGEPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+110+1,519,16,vfh[1],_Context->buffer_IMAGEPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x26 :
				/* ChoixIMAGEPATH */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
					visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x27 :
				/* ICONPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+140+1,519,16,vfh[1],_Context->buffer_ICONPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x28 :
				/* ChoixICONPATH */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
					visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x29 :
				/* PALETTE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+170+1,519,16,vfh[1],_Context->buffer_PALETTE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2a :
				/* ChoixPALETTE */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
					visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2b :
				/* SKIN */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+200+1,544,15,vfh[1],_Context->buffer_SKIN,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2c :
				/* TRIGGER_STYLE */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+210,_Context->y_Auto3584+230,184,80,vfh[1],27,28,parse_selection(_Context->msg_TRIGGER_STYLE[_Context->language],&_Context->value_TRIGGER_STYLE),514);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x2d :
				/* TRIGGER_COLOUR */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+660+1,_Context->y_Auto3584+230+1,88,16,vfh[1],_Context->buffer_TRIGGER_COLOUR,11);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2e :
				/* STYLEPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+260+1,520,16,vfh[1],_Context->buffer_STYLEPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x2f :
				/* COMPONENTPATH */
				if (_Context->page_number == 3 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+210+1,_Context->y_Auto3584+290+1,520,16,vfh[1],_Context->buffer_COMPONENTPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x30 :
				/* ChoixSTYLEPATH */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
					visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x31 :
				/* ChoixCOMPPATH */
				if (_Context->page_number == 3 ) {
					_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
					visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x32 :
				/* Fonts */
				if (_Context->page_number == 4 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x33 :
				/* FONTPATH */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+110+1,519,16,vfh[1],_Context->buffer_FONTPATH,255);
					/*GWB le 20/06/2006*/
					if(method_is_valid(SingConf->fontpath))
					liberate(SingConf->fontpath);
					SingConf->fontpath=allocate_string(_Context->buffer_FONTPATH);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x34 :
				/* FONTLAB1 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+180+1,144,16,vfh[1],_Context->buffer_FONTLAB1,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x35 :
				/* FONTLAB2 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+210+1,144,16,vfh[1],_Context->buffer_FONTLAB2,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x36 :
				/* FONTLAB3 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+240+1,144,16,vfh[1],_Context->buffer_FONTLAB3,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x37 :
				/* FONTLAB4 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+270+1,144,16,vfh[1],_Context->buffer_FONTLAB4,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x38 :
				/* FONTLAB5 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+300+1,144,16,vfh[1],_Context->buffer_FONTLAB5,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x39 :
				/* FONTLAB6 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+330+1,144,16,vfh[1],_Context->buffer_FONTLAB6,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3a :
				/* FONTLAB7 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+360+1,144,16,vfh[1],_Context->buffer_FONTLAB7,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3b :
				/* FONTLAB8 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+390+1,144,16,vfh[1],_Context->buffer_FONTLAB8,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3c :
				/* FONTLAB9 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+420+1,144,16,vfh[1],_Context->buffer_FONTLAB9,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3d :
				/* FONTLAB10 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+50+1,_Context->y_Auto3584+450+1,144,16,vfh[1],_Context->buffer_FONTLAB10,32);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x3e :
				/* ChoixFONTPATH */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
					visual_button(_Context->x_Auto3584+725,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+725,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x3f :
				/* FONT1 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+180+1,503,16,vfh[1],_Context->buffer_FONT1,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x40 :
				/* ChoixFONT1 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x41 :
				/* FONT2 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+210+1,503,16,vfh[1],_Context->buffer_FONT2,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x42 :
				/* ChoixFONT2 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x43 :
				/* FONT3 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+240+1,503,16,vfh[1],_Context->buffer_FONT3,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x44 :
				/* ChoixFONT3 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x45 :
				/* FONT4 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+270+1,503,16,vfh[1],_Context->buffer_FONT4,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x46 :
				/* ChoixFONT4 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x47 :
				/* FONT5 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+300+1,503,16,vfh[1],_Context->buffer_FONT5,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x48 :
				/* ChoixFONT5 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x49 :
				/* FONT6 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+330+1,503,16,vfh[1],_Context->buffer_FONT6,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4a :
				/* ChoixFONT6 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4b :
				/* FONT7 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+360+1,503,16,vfh[1],_Context->buffer_FONT7,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4c :
				/* ChoixFONT7 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4d :
				/* FONT8 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+390+1,503,16,vfh[1],_Context->buffer_FONT8,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x4e :
				/* ChoixFONT8 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x4f :
				/* FONT9 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+420+1,503,16,vfh[1],_Context->buffer_FONT9,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x50 :
				/* ChoixFONT9 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x51 :
				/* FONT10 */
				if (_Context->page_number == 4 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+450+1,503,16,vfh[1],_Context->buffer_FONT10,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x52 :
				/* ChoixFONT10 */
				if (_Context->page_number == 4 ) {
					_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
					visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x53 :
				/* Documents */
				if (_Context->page_number == 5 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x54 :
				/* HTML_TITLE */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+110+1,528,16,vfh[1],_Context->buffer_HTML_TITLE,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x55 :
				/* HTML_LOGO */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+140+1,528,16,vfh[1],_Context->buffer_HTML_LOGO,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x56 :
				/* HTML_COPYRIGHT */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+170+1,528,16,vfh[1],_Context->buffer_HTML_COPYRIGHT,66);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x57 :
				/* SCREEN_CSS */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+200+1,503,16,vfh[1],_Context->buffer_SCREEN_CSS,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x58 :
				/* ChoixSCREEN_CSS */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x59 :
				/* PRINT_CSS */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+230+1,503,16,vfh[1],_Context->buffer_PRINT_CSS,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5a :
				/* ChoixPRINT_CSS */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5b :
				/* NAVIGATOR */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+260+1,503,16,vfh[1],_Context->buffer_NAVIGATOR,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5c :
				/* ChoixNAVIGATOR */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5d :
				/* DOCPATH */
				if (_Context->page_number == 5 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+290+1,503,16,vfh[1],_Context->buffer_DOCPATH,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x5e :
				/* ChoixDOCPATH */
				if (_Context->page_number == 5 ) {
					_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x5f :
				/* Printing */
				if (_Context->page_number == 6 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x60 :
				/* PRINTER */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+200+1,_Context->y_Auto3584+110+1,504,16,vfh[1],_Context->buffer_PRINTER,259);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x61 :
				/* ChoixPRINTER */
				if (_Context->page_number == 6 ) {
					_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
					visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x62 :
				/* PAPERTYPE */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+590,_Context->y_Auto3584+150,152,48,vfh[1],27,26,parse_selection(WidgetPaperTypes,&_Context->value_PAPERTYPE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x63 :
				/* LAYOUT */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+200,_Context->y_Auto3584+190,144,48,vfh[1],0,0,parse_selection(_Context->msg_LAYOUT[_Context->language],&_Context->value_LAYOUT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x64 :
				/* PAGEFEED */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+590,_Context->y_Auto3584+190,152,48,vfh[1],27,0,parse_selection(_Context->msg_PAGEFEED[_Context->language],&_Context->value_PAGEFEED),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x65 :
				/* RESOLUTION */
				if (_Context->page_number == 6 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+200,_Context->y_Auto3584+150,144,64,vfh[1],27,26,parse_selection(WidgetPrintResolution,&_Context->value_RESOLUTION),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x66 :
				/* Editor */
				if (_Context->page_number == 7 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x67 :
				/* AED */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+220+1,_Context->y_Auto3584+120+1,496,16,vfh[1],_Context->buffer_AED,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x68 :
				/* ChoixAED */
				if (_Context->page_number == 7 ) {
					_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
					visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x69 :
				/* AED_FONT */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+220,_Context->y_Auto3584+170,150,70,vfh[1],0,0,parse_selection(TextFontList,&_Context->value_AED_FONT),2);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6a :
				/* AED_STATE */
				if (_Context->page_number == 7 ) {
				visual_check(_Context->x_Auto3584+90,_Context->y_Auto3584+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),(_Context->value_AED_STATE |2));
					_Context->keycode = visual_getch();
					_Context->trigger_AED_STATE=visual_trigger_code(_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]));
	visual_check(_Context->x_Auto3584+90,_Context->y_Auto3584+350,207,20,vfh[3],27,0,_Context->msg_AED_STATE[_Context->language],strlen(_Context->msg_AED_STATE[_Context->language]),_Context->value_AED_STATE|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6b :
				/* AED_SYNTAX */
				if (_Context->page_number == 7 ) {
				visual_check(_Context->x_Auto3584+340,_Context->y_Auto3584+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),(_Context->value_AED_SYNTAX |2));
					_Context->keycode = visual_getch();
					_Context->trigger_AED_SYNTAX=visual_trigger_code(_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]));
	visual_check(_Context->x_Auto3584+340,_Context->y_Auto3584+350,207,20,vfh[3],27,0,_Context->msg_AED_SYNTAX[_Context->language],strlen(_Context->msg_AED_SYNTAX[_Context->language]),_Context->value_AED_SYNTAX|0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6c :
				/* AED_NORMAL */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+60,_Context->y_Auto3584+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_NORMAL),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6d :
				/* AED_QUOTE */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+200,_Context->y_Auto3584+280,120,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_QUOTE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6e :
				/* AED_COMMENT */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+470,_Context->y_Auto3584+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_COMMENT),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x6f :
				/* AED_KEYWORD */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+340,_Context->y_Auto3584+280,112,96,vfh[1],27,0,parse_selection(CicoColourList,&_Context->value_AED_KEYWORD),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x70 :
				/* AED_PUNCTUATE */
				if (_Context->page_number == 7 ) {
					_Context->keycode = visual_select(_Context->x_Auto3584+600,_Context->y_Auto3584+280,120,96,vfh[1],28,28,parse_selection(CicoColourList,&_Context->value_AED_PUNCTUATE),770);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x71 :
				/* ACCEPT */
				_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
				visual_button(_Context->x_Auto3584+20,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
	visual_button(_Context->x_Auto3584+20,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
				break;
			case	0x72 :
				/* SAVEFILE */
				_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
				visual_button(_Context->x_Auto3584+120,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+120,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
				break;
			case	0x73 :
				/* SAVELDAP */
				_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
				visual_button(_Context->x_Auto3584+220,_Context->y_Auto3584+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),2);
				_Context->keycode = visual_getch();
				_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
	visual_button(_Context->x_Auto3584+220,_Context->y_Auto3584+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),0);
				break;
			case	0x74 :
				/* LoadLdap */
				_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
				visual_button(_Context->x_Auto3584+470,_Context->y_Auto3584+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),2);
				_Context->keycode = visual_getch();
				_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
	visual_button(_Context->x_Auto3584+470,_Context->y_Auto3584+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),0);
				break;
			case	0x75 :
				/* EDITFILE */
				_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
				visual_button(_Context->x_Auto3584+324,_Context->y_Auto3584+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+324,_Context->y_Auto3584+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
				break;
			case	0x76 :
				/* DELETE */
				_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
				visual_button(_Context->x_Auto3584+396,_Context->y_Auto3584+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
	visual_button(_Context->x_Auto3584+396,_Context->y_Auto3584+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
				break;
			case	0x77 :
				/* LOADFILE */
				_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
				visual_button(_Context->x_Auto3584+570,_Context->y_Auto3584+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+570,_Context->y_Auto3584+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
				break;
			case	0x78 :
				/* CANCEL */
				_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
				visual_button(_Context->x_Auto3584+672,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),2);
				_Context->keycode = visual_getch();
				_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
	visual_button(_Context->x_Auto3584+672,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
				break;
			case	0x79 :
				/* Project */
				if (_Context->page_number == 8 ) {
					_Context->keycode=visual_getch();
				} else {
					_Context->keycode=5;
					}
				break;
			case	0x7a :
				/* AMAKE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+220+1,_Context->y_Auto3584+120+1,496,16,vfh[1],_Context->buffer_AMAKE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7b :
				/* choixAMAKE */
				if (_Context->page_number == 8 ) {
					_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
					visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),0);
				} else {
				_Context->keycode = 5;
					}
				break;
			case	0x7c :
				/* AMAKE_OPTIONS */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+220+1,_Context->y_Auto3584+150+1,528,16,vfh[1],_Context->buffer_AMAKE_OPTIONS,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7d :
				/* AMAKE_DEFINE */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+220+1,_Context->y_Auto3584+180+1,528,16,vfh[1],_Context->buffer_AMAKE_DEFINE,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7e :
				/* AMAKE_LIST */
				if (_Context->page_number == 8 ) {
					_Context->keycode = visual_edit(_Context->x_Auto3584+220+1,_Context->y_Auto3584+210+1,496,16,vfh[1],_Context->buffer_AMAKE_LIST,255);
				} else {
					_Context->keycode = 5;
					}
				break;
			case	0x7f :
				/* choixAMAKE_LIST */
				if (_Context->page_number == 8 ) {
					_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
					visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),2);
					_Context->keycode = visual_getch();
					_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),0);
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
			_Context->focus_item=127;
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
						if (Images_help(_Context) != 0) { continue; }
						else { break; }
					case	0x25 :
						if (IMAGEPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x27 :
						if (ICONPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x29 :
						if (PALETTE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2b :
						if (SKIN_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2c :
						if (TRIGGER_STYLE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2d :
						if (TRIGGER_COLOUR_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2e :
						if (STYLEPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x2f :
						if (COMPONENTPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x32 :
						if (Fonts_help(_Context) != 0) { continue; }
						else { break; }
					case	0x33 :
						if (FONTPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x3f :
						if (FONT1_help(_Context) != 0) { continue; }
						else { break; }
					case	0x41 :
						if (FONT2_help(_Context) != 0) { continue; }
						else { break; }
					case	0x43 :
						if (FONT3_help(_Context) != 0) { continue; }
						else { break; }
					case	0x45 :
						if (FONT4_help(_Context) != 0) { continue; }
						else { break; }
					case	0x47 :
						if (FONT5_help(_Context) != 0) { continue; }
						else { break; }
					case	0x49 :
						if (FONT6_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4b :
						if (FONT7_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4d :
						if (FONT8_help(_Context) != 0) { continue; }
						else { break; }
					case	0x4f :
						if (FONT9_help(_Context) != 0) { continue; }
						else { break; }
					case	0x51 :
						if (FONT10_help(_Context) != 0) { continue; }
						else { break; }
					case	0x53 :
						if (Documents_help(_Context) != 0) { continue; }
						else { break; }
					case	0x54 :
						if (HTML_TITLE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x55 :
						if (HTML_LOGO_help(_Context) != 0) { continue; }
						else { break; }
					case	0x56 :
						if (HTML_COPYRIGHT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x57 :
						if (SCREEN_CSS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x59 :
						if (PRINT_CSS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5b :
						if (NAVIGATOR_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5d :
						if (DOCPATH_help(_Context) != 0) { continue; }
						else { break; }
					case	0x5f :
						if (Printing_help(_Context) != 0) { continue; }
						else { break; }
					case	0x60 :
						if (PRINTER_help(_Context) != 0) { continue; }
						else { break; }
					case	0x62 :
						if (PAPERTYPE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x63 :
						if (LAYOUT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x64 :
						if (PAGEFEED_help(_Context) != 0) { continue; }
						else { break; }
					case	0x65 :
						if (RESOLUTION_help(_Context) != 0) { continue; }
						else { break; }
					case	0x66 :
						if (Editor_help(_Context) != 0) { continue; }
						else { break; }
					case	0x67 :
						if (AED_help(_Context) != 0) { continue; }
						else { break; }
					case	0x69 :
						if (AED_FONT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6a :
						if (AED_STATE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6b :
						if (AED_SYNTAX_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6c :
						if (AED_NORMAL_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6d :
						if (AED_QUOTE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6e :
						if (AED_COMMENT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x6f :
						if (AED_KEYWORD_help(_Context) != 0) { continue; }
						else { break; }
					case	0x70 :
						if (AED_PUNCTUATE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x71 :
						if (ACCEPT_help(_Context) != 0) { continue; }
						else { break; }
					case	0x72 :
						if (SAVEFILE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x73 :
						if (SAVELDAP_help(_Context) != 0) { continue; }
						else { break; }
					case	0x74 :
						if (LoadLdap_help(_Context) != 0) { continue; }
						else { break; }
					case	0x75 :
						if (EDITFILE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x76 :
						if (DELETE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x77 :
						if (LOADFILE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x78 :
						if (CANCEL_help(_Context) != 0) { continue; }
						else { break; }
					case	0x79 :
						if (Project_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7a :
						if (AMAKE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7c :
						if (AMAKE_OPTIONS_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7d :
						if (AMAKE_DEFINE_help(_Context) != 0) { continue; }
						else { break; }
					case	0x7e :
						if (AMAKE_LIST_help(_Context) != 0) { continue; }
						else { break; }
					}
				}
			switch ((_Context->focus_item = retcode)) {
				case	0x1 :
					/* Auto3584 */
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFILENAME=visual_trigger_code(_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+150,20,18,vfh[1],27,28,_Context->msg_ChoixFILENAME[_Context->language],strlen(_Context->msg_ChoixFILENAME[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixATR=visual_trigger_code(_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+100,20,18,vfh[1],27,28,_Context->msg_ChoixATR[_Context->language],strlen(_Context->msg_ChoixATR[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixATR_INCLUDE=visual_trigger_code(_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixATR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixATR_INCLUDE[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixALD=visual_trigger_code(_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixALD[_Context->language],strlen(_Context->msg_ChoixALD[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixALD_INCLUDE=visual_trigger_code(_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixALD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixALD_INCLUDE[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOTR=visual_trigger_code(_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+280,20,18,vfh[1],27,28,_Context->msg_ChoixOTR[_Context->language],strlen(_Context->msg_ChoixOTR[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOTR_INCLUDE=visual_trigger_code(_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+320,20,18,vfh[1],27,28,_Context->msg_ChoixOTR_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOTR_INCLUDE[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOLD=visual_trigger_code(_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixOLD[_Context->language],strlen(_Context->msg_ChoixOLD[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixOLD_INCLUDE=visual_trigger_code(_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+380,20,18,vfh[1],27,28,_Context->msg_ChoixOLD_INCLUDE[_Context->language],strlen(_Context->msg_ChoixOLD_INCLUDE[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixEXA=visual_trigger_code(_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+470,20,18,vfh[1],27,28,_Context->msg_ChoixEXA[_Context->language],strlen(_Context->msg_ChoixEXA[_Context->language]),0);
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
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixEXADB=visual_trigger_code(_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+490,20,18,vfh[1],27,28,_Context->msg_ChoixEXADB[_Context->language],strlen(_Context->msg_ChoixEXADB[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixEXADB_event(_Context)) != -1) break;

						}
					continue;
				case	0x24 :
					/* Images */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 3;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x25 :
					/* IMAGEPATH */
					continue;
				case	0x26 :
					/* ChoixIMAGEPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
						visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixIMAGEPATH=visual_trigger_code(_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixIMAGEPATH[_Context->language],strlen(_Context->msg_ChoixIMAGEPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixIMAGEPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x27 :
					/* ICONPATH */
					continue;
				case	0x28 :
					/* ChoixICONPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
						visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixICONPATH=visual_trigger_code(_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+140,20,18,vfh[1],27,28,_Context->msg_ChoixICONPATH[_Context->language],strlen(_Context->msg_ChoixICONPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixICONPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x29 :
					/* PALETTE */
					continue;
				case	0x2a :
					/* ChoixPALETTE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
						visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixPALETTE=visual_trigger_code(_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+170,20,18,vfh[1],27,28,_Context->msg_ChoixPALETTE[_Context->language],strlen(_Context->msg_ChoixPALETTE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixPALETTE_event(_Context)) != -1) break;

						}
					continue;
				case	0x2b :
					/* SKIN */
					continue;
				case	0x2c :
					/* TRIGGER_STYLE */
					continue;
				case	0x2d :
					/* TRIGGER_COLOUR */
					continue;
				case	0x2e :
					/* STYLEPATH */
					continue;
				case	0x2f :
					/* COMPONENTPATH */
					continue;
				case	0x30 :
					/* ChoixSTYLEPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
						visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixSTYLEPATH=visual_trigger_code(_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixSTYLEPATH[_Context->language],strlen(_Context->msg_ChoixSTYLEPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixSTYLEPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x31 :
					/* ChoixCOMPPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
						visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixCOMPPATH=visual_trigger_code(_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+735,_Context->y_Auto3584+289,20,18,vfh[1],27,28,_Context->msg_ChoixCOMPPATH[_Context->language],strlen(_Context->msg_ChoixCOMPPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixCOMPPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x32 :
					/* Fonts */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 4;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x33 :
					/* FONTPATH */
					continue;
				case	0x34 :
					/* FONTLAB1 */
					continue;
				case	0x35 :
					/* FONTLAB2 */
					continue;
				case	0x36 :
					/* FONTLAB3 */
					continue;
				case	0x37 :
					/* FONTLAB4 */
					continue;
				case	0x38 :
					/* FONTLAB5 */
					continue;
				case	0x39 :
					/* FONTLAB6 */
					continue;
				case	0x3a :
					/* FONTLAB7 */
					continue;
				case	0x3b :
					/* FONTLAB8 */
					continue;
				case	0x3c :
					/* FONTLAB9 */
					continue;
				case	0x3d :
					/* FONTLAB10 */
					continue;
				case	0x3e :
					/* ChoixFONTPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
						visual_button(_Context->x_Auto3584+725,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONTPATH=visual_trigger_code(_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+725,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixFONTPATH[_Context->language],strlen(_Context->msg_ChoixFONTPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONTPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x3f :
					/* FONT1 */
					continue;
				case	0x40 :
					/* ChoixFONT1 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT1=visual_trigger_code(_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+180,20,18,vfh[1],27,28,_Context->msg_ChoixFONT1[_Context->language],strlen(_Context->msg_ChoixFONT1[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT1_event(_Context)) != -1) break;

						}
					continue;
				case	0x41 :
					/* FONT2 */
					continue;
				case	0x42 :
					/* ChoixFONT2 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT2=visual_trigger_code(_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_ChoixFONT2[_Context->language],strlen(_Context->msg_ChoixFONT2[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT2_event(_Context)) != -1) break;

						}
					continue;
				case	0x43 :
					/* FONT3 */
					continue;
				case	0x44 :
					/* ChoixFONT3 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT3=visual_trigger_code(_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+240,20,18,vfh[1],27,28,_Context->msg_ChoixFONT3[_Context->language],strlen(_Context->msg_ChoixFONT3[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT3_event(_Context)) != -1) break;

						}
					continue;
				case	0x45 :
					/* FONT4 */
					continue;
				case	0x46 :
					/* ChoixFONT4 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT4=visual_trigger_code(_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+270,20,18,vfh[1],27,28,_Context->msg_ChoixFONT4[_Context->language],strlen(_Context->msg_ChoixFONT4[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT4_event(_Context)) != -1) break;

						}
					continue;
				case	0x47 :
					/* FONT5 */
					continue;
				case	0x48 :
					/* ChoixFONT5 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT5=visual_trigger_code(_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+300,20,18,vfh[1],27,28,_Context->msg_ChoixFONT5[_Context->language],strlen(_Context->msg_ChoixFONT5[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT5_event(_Context)) != -1) break;

						}
					continue;
				case	0x49 :
					/* FONT6 */
					continue;
				case	0x4a :
					/* ChoixFONT6 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT6=visual_trigger_code(_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+330,20,18,vfh[1],27,28,_Context->msg_ChoixFONT6[_Context->language],strlen(_Context->msg_ChoixFONT6[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT6_event(_Context)) != -1) break;

						}
					continue;
				case	0x4b :
					/* FONT7 */
					continue;
				case	0x4c :
					/* ChoixFONT7 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT7=visual_trigger_code(_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+360,20,18,vfh[1],27,28,_Context->msg_ChoixFONT7[_Context->language],strlen(_Context->msg_ChoixFONT7[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT7_event(_Context)) != -1) break;

						}
					continue;
				case	0x4d :
					/* FONT8 */
					continue;
				case	0x4e :
					/* ChoixFONT8 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT8=visual_trigger_code(_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+390,20,18,vfh[1],27,28,_Context->msg_ChoixFONT8[_Context->language],strlen(_Context->msg_ChoixFONT8[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT8_event(_Context)) != -1) break;

						}
					continue;
				case	0x4f :
					/* FONT9 */
					continue;
				case	0x50 :
					/* ChoixFONT9 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT9=visual_trigger_code(_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+420,20,18,vfh[1],27,28,_Context->msg_ChoixFONT9[_Context->language],strlen(_Context->msg_ChoixFONT9[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT9_event(_Context)) != -1) break;

						}
					continue;
				case	0x51 :
					/* FONT10 */
					continue;
				case	0x52 :
					/* ChoixFONT10 */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
						visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixFONT10=visual_trigger_code(_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]));
	visual_button(_Context->x_Auto3584+708,_Context->y_Auto3584+450,20,18,vfh[1],27,28,_Context->msg_ChoixFONT10[_Context->language],strlen(_Context->msg_ChoixFONT10[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixFONT10_event(_Context)) != -1) break;

						}
					continue;
				case	0x53 :
					/* Documents */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 5;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x54 :
					/* HTML_TITLE */
					continue;
				case	0x55 :
					/* HTML_LOGO */
					continue;
				case	0x56 :
					/* HTML_COPYRIGHT */
					continue;
				case	0x57 :
					/* SCREEN_CSS */
					continue;
				case	0x58 :
					/* ChoixSCREEN_CSS */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixSCREEN_CSS=visual_trigger_code(_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+200,20,18,vfh[1],27,28,_Context->msg_ChoixSCREEN_CSS[_Context->language],strlen(_Context->msg_ChoixSCREEN_CSS[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixSCREEN_CSS_event(_Context)) != -1) break;

						}
					continue;
				case	0x59 :
					/* PRINT_CSS */
					continue;
				case	0x5a :
					/* ChoixPRINT_CSS */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixPRINT_CSS=visual_trigger_code(_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+230,20,18,vfh[1],27,28,_Context->msg_ChoixPRINT_CSS[_Context->language],strlen(_Context->msg_ChoixPRINT_CSS[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixPRINT_CSS_event(_Context)) != -1) break;

						}
					continue;
				case	0x5b :
					/* NAVIGATOR */
					continue;
				case	0x5c :
					/* ChoixNAVIGATOR */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixNAVIGATOR=visual_trigger_code(_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+260,20,18,vfh[1],27,28,_Context->msg_ChoixNAVIGATOR[_Context->language],strlen(_Context->msg_ChoixNAVIGATOR[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixNAVIGATOR_event(_Context)) != -1) break;

						}
					continue;
				case	0x5d :
					/* DOCPATH */
					continue;
				case	0x5e :
					/* ChoixDOCPATH */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixDOCPATH=visual_trigger_code(_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+290,20,18,vfh[1],27,28,_Context->msg_ChoixDOCPATH[_Context->language],strlen(_Context->msg_ChoixDOCPATH[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixDOCPATH_event(_Context)) != -1) break;

						}
					continue;
				case	0x5f :
					/* Printing */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 6;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x60 :
					/* PRINTER */
					continue;
				case	0x61 :
					/* ChoixPRINTER */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
						visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixPRINTER=visual_trigger_code(_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]));
	visual_button(_Context->x_Auto3584+710,_Context->y_Auto3584+110,20,18,vfh[1],27,28,_Context->msg_ChoixPRINTER[_Context->language],strlen(_Context->msg_ChoixPRINTER[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixPRINTER_event(_Context)) != -1) break;

						}
					continue;
				case	0x62 :
					/* PAPERTYPE */
					continue;
				case	0x63 :
					/* LAYOUT */
					continue;
				case	0x64 :
					/* PAGEFEED */
					continue;
				case	0x65 :
					/* RESOLUTION */
					continue;
				case	0x66 :
					/* Editor */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 7;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x67 :
					/* AED */
					continue;
				case	0x68 :
					/* ChoixAED */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
						visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ChoixAED=visual_trigger_code(_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_ChoixAED[_Context->language],strlen(_Context->msg_ChoixAED[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ChoixAED_event(_Context)) != -1) break;

						}
					continue;
				case	0x69 :
					/* AED_FONT */
					continue;
				case	0x6a :
					/* AED_STATE */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_AED_STATE += 1;
						_Context->value_AED_STATE &= 1;
						}
					continue;
				case	0x6b :
					/* AED_SYNTAX */
					if (visual_event(1) & _MIMO_UP) {
						_Context->value_AED_SYNTAX += 1;
						_Context->value_AED_SYNTAX &= 1;
						}
					continue;
				case	0x6c :
					/* AED_NORMAL */
					continue;
				case	0x6d :
					/* AED_QUOTE */
					continue;
				case	0x6e :
					/* AED_COMMENT */
					continue;
				case	0x6f :
					/* AED_KEYWORD */
					continue;
				case	0x70 :
					/* AED_PUNCTUATE */
					continue;
				case	0x71 :
					/* ACCEPT */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
						visual_button(_Context->x_Auto3584+20,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_ACCEPT=visual_trigger_code(_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]));
	visual_button(_Context->x_Auto3584+20,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_ACCEPT[_Context->language],strlen(_Context->msg_ACCEPT[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_ACCEPT_event(_Context)) != -1) break;

						}
					continue;
				case	0x72 :
					/* SAVEFILE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
						visual_button(_Context->x_Auto3584+120,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SAVEFILE=visual_trigger_code(_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+120,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_SAVEFILE[_Context->language],strlen(_Context->msg_SAVEFILE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SAVEFILE_event(_Context)) != -1) break;

						}
					continue;
				case	0x73 :
					/* SAVELDAP */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
						visual_button(_Context->x_Auto3584+220,_Context->y_Auto3584+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_SAVELDAP=visual_trigger_code(save_ldap_label(),strlen(save_ldap_label()));
	visual_button(_Context->x_Auto3584+220,_Context->y_Auto3584+550,102,33,vfh[2],28,28,save_ldap_label(),strlen(save_ldap_label()),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_SAVELDAP_event(_Context)) != -1) break;

						}
					continue;
				case	0x74 :
					/* LoadLdap */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
						visual_button(_Context->x_Auto3584+470,_Context->y_Auto3584+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_LoadLdap=visual_trigger_code(load_ldap_label(),strlen(load_ldap_label()));
	visual_button(_Context->x_Auto3584+470,_Context->y_Auto3584+550,98,32,vfh[2],28,28,load_ldap_label(),strlen(load_ldap_label()),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_LoadLdap_event(_Context)) != -1) break;

						}
					continue;
				case	0x75 :
					/* EDITFILE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
						visual_button(_Context->x_Auto3584+324,_Context->y_Auto3584+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_EDITFILE=visual_trigger_code(_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+324,_Context->y_Auto3584+550,70,32,vfh[2],27,28,_Context->msg_EDITFILE[_Context->language],strlen(_Context->msg_EDITFILE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_EDITFILE_event(_Context)) != -1) break;

						}
					continue;
				case	0x76 :
					/* DELETE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
						visual_button(_Context->x_Auto3584+396,_Context->y_Auto3584+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_DELETE=visual_trigger_code(_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]));
	visual_button(_Context->x_Auto3584+396,_Context->y_Auto3584+550,72,32,vfh[2],27,28,_Context->msg_DELETE[_Context->language],strlen(_Context->msg_DELETE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_DELETE_event(_Context)) != -1) break;

						}
					continue;
				case	0x77 :
					/* LOADFILE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
						visual_button(_Context->x_Auto3584+570,_Context->y_Auto3584+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_LOADFILE=visual_trigger_code(_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]));
	visual_button(_Context->x_Auto3584+570,_Context->y_Auto3584+550,100,32,vfh[2],27,28,_Context->msg_LOADFILE[_Context->language],strlen(_Context->msg_LOADFILE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_LOADFILE_event(_Context)) != -1) break;

						}
					continue;
				case	0x78 :
					/* CANCEL */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
						visual_button(_Context->x_Auto3584+672,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_CANCEL=visual_trigger_code(_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]));
	visual_button(_Context->x_Auto3584+672,_Context->y_Auto3584+550,98,32,vfh[2],27,28,_Context->msg_CANCEL[_Context->language],strlen(_Context->msg_CANCEL[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_CANCEL_event(_Context)) != -1) break;

						}
					continue;
				case	0x79 :
					/* Project */
					if (visual_event(1) & _MIMO_DOWN) {
						accept_configuration_losefocus(_Context);
						_Context->page_number = 8;
						accept_configuration_show(_Context);
						}
					continue;
				case	0x7a :
					/* AMAKE */
					continue;
				case	0x7b :
					/* choixAMAKE */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
						visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixAMAKE=visual_trigger_code(_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+120,20,18,vfh[1],27,28,_Context->msg_choixAMAKE[_Context->language],strlen(_Context->msg_choixAMAKE[_Context->language]),0);
						}
					if ( visual_event(1) &  0x20 ) {
					if ((_Context->keycode = on_choixAMAKE_event(_Context)) != -1) break;

						}
					continue;
				case	0x7c :
					/* AMAKE_OPTIONS */
					continue;
				case	0x7d :
					/* AMAKE_DEFINE */
					continue;
				case	0x7e :
					/* AMAKE_LIST */
					continue;
				case	0x7f :
					/* choixAMAKE_LIST */
					if (visual_event(1) & _MIMO_DOWN) {
						_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
						visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),2);
						}
					else if (visual_event(1) & _MIMO_UP) {
						_Context->trigger_choixAMAKE_LIST=visual_trigger_code(_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]));
	visual_button(_Context->x_Auto3584+720,_Context->y_Auto3584+210,20,18,vfh[1],27,28,_Context->msg_choixAMAKE_LIST[_Context->language],strlen(_Context->msg_choixAMAKE_LIST[_Context->language]),0);
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
				_Context->focus_item=127;
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
