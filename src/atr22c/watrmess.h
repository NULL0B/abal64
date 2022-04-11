/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1995
 *	Module  : ATR
 *	Fichier : WATRMESS.H
 *	Version : 2.2a
 *	Date    : 24/09/97
 *	Systeme : W95/NT
 *
 *	Message du traducteur dans un output
 *
 *	[Definitions privees]
 *
 */


#ifndef __WATRMESS_H__
#define __WATRMESS_H__

//Traitement de l'option -J
////////////////////////////////////////////////////////////////////////////////////
BOOL ctReOpenDiagnostic(int JuneHandle);


BOOL ctOutputErrorDiagnostic2
		(
		int					Level,
		ctConstStr			FileName,
		long				Line,
		long				Column,
		ctConstStr			ShortMessage,
		ctConstStr			MessageStr
		);

BOOL ctOutputWarningDiagnostic2
		(
		int					Level,
		ctConstStr			FileName,
		long				Line,
		long				Column,
		ctConstStr			ShortMessage,
		ctConstStr			MessageStr
		);

BOOL ctOutputMessageDiagnostic2
		(
		ctConstStr			ShortMessage,
		ctConstStr			MessageStr
		);

void ctSetToolName (ctConstStr ToolName);

char ouinonInMsgBox(const char* message, char* FileName, char* VarName, char ryes, char rno, int askToContinue);

BOOL TranslateForWindows(char* message);

#ifdef USE_LONG_NAMES // Non défini
void lnLongToShort2
		(
		ctConstStr		LongName,
		ctStr				ShortName,
		long			ShortNameLength
		);

 void lnIsLong2
		(
		ctConstStr		ShortName,
		ctBoolean *		IsResult
		);
#endif

#endif  /* __WATRMESS_H__ */
