// ****************************************************************************
// * zIntCtx.h
// * Constants, types,... for internal context
// ****************************************************************************
#ifndef VTHOBASE_H
#define VTHOBASE_H

#include"wdef.h"
#include"zint.h"
#include "jstdpsu.h"
#include "vlink.h"
#include "vgrhold.h"

// *******************************************************
// * CONSTANTS
// *******************************************************


#define CI_MAXLABEL_BUTTON  50
#define CI_MAXWIN           65
#define CI_MAXFONT          32
#define CI_MAXIMG           120

// ---------------------------------------------------------------------------------------
// Descriptors
// ---------------------------------------------------------------------------------------

	
typedef struct{
	WORD Fore;
	WORD Back;
}VTI_COLOR,FAR PVTI_COLOR;

// State of the caret
typedef struct{
  TI_POINT Txt;                    
  WORD  IsShow;                    
} VTI_CARET, FAR PTR PVTI_CARET;

// Descriptor of button associations label / image
typedef struct{
	WORD					IsDefined;                  
	char					Label[CI_MAXLABEL_BUTTON];  
	struct standard_image   *pImg;                       
	WORD					Type;                       
	WORD					BMPWidth;  //width of image?
	WORD					LabelWidth;
} VTI_IMAGE, FAR PTR PVTI_IMAGE;


typedef struct standard_image* pstandard_image;
// Descriptor of a window
typedef struct{
	PTI_WINDOWHOLDER		pImg;
	int						is_WD_allocated;
	int 					id_number;
  	TI_RECTANGLE			TxCoo;
} VTI_WINDOW,FAR PTR PVTI_WINDOW;

typedef struct{
	struct link*	fenetr;
	VTI_IMAGE		Image[CI_MAXIMG];
}VTI_APPL,FAR PTR PVTI_APPL;




#endif

