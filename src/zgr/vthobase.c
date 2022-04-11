//      22/06/2001
//      The VAP's Bomb
//      99.9% guarantee of all window operations      
//    No error during SetStack calls.
//     Be careful ;)
//
#include"vthobase.h"
#include"zint.h"
#include"zglobal.h"

#include <string.h>
#include <stdlib.h>

#include "jimage.h"
#include "grapil.h"
#include "zsys.h"
#include "zgui.h"
#include "zintctx.h"
#include "zglobctx.h"
#include "ztools.h"
#include "zext.h"
#include "ztrace.h"
// interface headers
#include "vthologi.h"
#include "vthobbmp.h"
#include "vlink.h"

#define CI_MODULE_ID  0x0040

VTI_APPL  appli;

struct link* stored_zero_window;
//active window index
int     active=0;
WORD    window_counter=0;

const WORD NoButtonType=100;//pseudo button type optimisation

void sdelay();

int GetWindowID(){
  PVTI_WINDOW window=(PVTI_WINDOW)appli.fenetr->data;
  return window->id_number;
}


int compare_str(char *a,char *b,int compare_lenght)
{
// Supprime les blancs en tête
while(*a==' '&&compare_lenght)
   {
   --compare_lenght;
   ++a;
   }

// supprime les blancs en fin 
while(a[compare_lenght-1]==' '&&compare_lenght)
   {
   --compare_lenght;    
   }

// compare
while(--compare_lenght+1)
   {
   if(*a++ != *b++) return 0;
   }

// FCH05112002 (bug micrologic)
// Arrivé ici, on sait que les caractères non blanc de 'a' sont identiques à ceux de 'b'
// mais il est possible que 'b' soit plus long que 'a' (exemple a=='fin' et b=='find\0')
// donc il faut tester le caractère suivant de 'b'
return (*b=='\0') ? 1 : 0;
}


void InitialiseImageSystem(){
  int index;
  for(index=CI_MAXIMG;--index>=0;){
    appli.Image[index].IsDefined=0;
    memcpy(appli.Image[index].Label," ",CI_MAXLABEL_BUTTON);
    appli.Image[index].pImg=0;
    appli.Image[index].BMPWidth=0;
    appli.Image[index].Type=NoButtonType;
  }
}

// window images destroying internal
void DestroyStandardBitmaps(){
  int index;
  for(index=0;index<CI_MAXIMG;index++){
    appli.Image[index].IsDefined=0;
    memcpy(appli.Image[index].Label," ",CI_MAXLABEL_BUTTON);
    DropImage(appli.Image[index].pImg);
    appli.Image[index].pImg=0;
    appli.Image[index].BMPWidth=0;
    appli.Image[index].Type=NoButtonType;
  }
}

// to zinit()
void InitialiseWindowSystem(){
  PVTI_WINDOW zero_window=(PVTI_WINDOW)allocate(sizeof(VTI_WINDOW));
  zero_window->TxCoo.x1=0;
  zero_window->TxCoo.y1=0;
  zero_window->TxCoo.x2=screencols-1;
  zero_window->TxCoo.y2=screenlins-1;
  zero_window->pImg=0;
  zero_window->id_number=window_counter++;
  appli.fenetr=create(zero_window);
  stored_zero_window=appli.fenetr;
  ++g_pPuPo->FrameCreated;
}


void DestroyOtherWindowParameters(PVTI_WINDOW some_window){
  some_window->TxCoo.x1=0;
  some_window->TxCoo.y1=0;
  some_window->TxCoo.x2=0;
    some_window->TxCoo.y2=0;
}



void DestroyWindowSystem(){
  struct link* courante=get_head(appli.fenetr);
  while(courante){
    PVTI_WINDOW window_data=(PVTI_WINDOW)courante->data;
    
    free_windowholder(window_data->pImg);
    ++g_pPuPo->FrameDeleted;
    ++g_pPuPo->FramesKilledByZadapt;
    DestroyOtherWindowParameters(window_data);
    liberate(window_data);
    courante=courante->succ;
  }
  destroy_all_links(appli.fenetr);
}
int CreateNewWindow(WORD x1,WORD y1,WORD x2,WORD y2){
  struct link* stored_link=appli.fenetr;
  PVTI_WINDOW new_window=(PVTI_WINDOW)allocate(sizeof(VTI_WINDOW));
  if(!new_window){ 
      window_error_code=CE_ERR_MEMORY; //VAP 1.6.2000. To return MessBOX return CE_ERR_MEMORY 
    return 0;//no memory to window
  }
    if(x2>screencols) x2=screencols-1;
    if(y2>screenlins) y2=screenlins-1;
    new_window->pImg=0;
  new_window->TxCoo.x1=x1;
  new_window->TxCoo.y1=y1;
  new_window->TxCoo.x2=x2;
  new_window->TxCoo.y2=y2;
    new_window->pImg=capture_window(&new_window->TxCoo);// 1
    if(!new_window->pImg){ 
    liberate(new_window);
      window_error_code=CE_ERR_MEMORY;//VAP 1.6.2000. To return MessBOX return CE_ERR_MEMORY 
    return 0;//no memory for image
  }
  new_window->id_number=window_counter++;
  appli.fenetr=tail_link(appli.fenetr,new_window);
  if(!appli.fenetr){
      free_windowholder(new_window->pImg);
    liberate(new_window);
    appli.fenetr=stored_link;
      window_error_code=CE_ERR_MEMORY;//VAP 1.6.2000. To return MessBOX return CE_ERR_MEMORY 
    return 0;//no memory for linkage
  }
  ++g_pPuPo->FrameCreated;
  ++g_pPuPo->NumBGAllocated;
  return 1;//all OK
}

int DestroyCurrentWindow(){
  struct link* stored_link;
  PVTI_WINDOW window;

  stored_link=appli.fenetr;
  if(appli.fenetr==stored_zero_window){
        return 0;//too many pop. something wrong!!! 
    }
  window=(PVTI_WINDOW)appli.fenetr->data;
  refresh_window(window->pImg);
  free_windowholder(window->pImg);
  liberate(window);
  // my appli.fenetr=destroy_link_and_shift_right(appli.fenetr);
    appli.fenetr=destroy_link_and_shift_left(appli.fenetr);
  ++g_pPuPo->FrameDeleted;
  ++g_pPuPo->NumBGLiberated;
  if(!appli.fenetr){
    appli.fenetr=destroy_link_and_shift_right(stored_link);
    return 2;//we destroy tail
  }else{
    return 1;//we destroy something
  }
  return 0;//something wrong  
}

void SetChangeFlag()
{
// Now, empty funtion.
}
   
//VAP 1.6.2000. Strongly changed function
//Because we can't collapse stupid ABAL calls when no memory NO RETURN NOW!!!(I think it is wrong in ZDLL)
void PileWindow(int flag,int no, WORD x1,WORD y1,WORD x2,WORD y2){
  switch(flag){
      case 1:{
        PVTI_WINDOW window;
      window=(PVTI_WINDOW)appli.fenetr->data;
        window_plank_exchange(window->pImg);
        appli.fenetr=appli.fenetr->prev;
        if(appli.fenetr==0){
          appli.fenetr=stored_zero_window->succ;
        }
        if(appli.fenetr==stored_zero_window){
          appli.fenetr=stored_zero_window->succ;
        }
        }
    break;
    
      case 2:{
        PVTI_WINDOW window;
        appli.fenetr=appli.fenetr->succ;
        if(appli.fenetr==0){
          appli.fenetr=get_tail(stored_zero_window); 
        }
        window=(PVTI_WINDOW)appli.fenetr->data;
      window_plank_exchange(window->pImg);
        }
      break;
    }
  }
//////




void trimmer(char* str,char* trimmed)
{
int lenght=strlen(str);
while(*str++==' ' && --lenght);
--str;
while(*(str+lenght-1)==' ' && --lenght);
memcpy( trimmed,str,lenght);
trimmed[lenght]='\0';
}


//zbutton_bmp prototype
void AssociateImage(int image_index,char* but_label,WORD image_width,WORD but_type)
{
int index=0;
int zero_index=0;
int association_exist=0;
char label[CI_MAXLABEL_BUTTON+2];

if(image_index>CI_MAXIMG) 
   return;

trimmer(but_label,label);

if(!image_width) 
   return;

for(index=0;index<CI_MAXIMG;index++)
   {
   if(appli.Image[index].Type==NoButtonType) 
      break;//stop search No any links between bmp and label
      
   if(appli.Image[index].Type==but_type)
      {  
      if(!strcmp(appli.Image[index].Label,label))
         {
         DropImage(appli.Image[index].pImg);
         appli.Image[index].pImg=export_button_bitmap(image_index);
         
         if(appli.Image[index].pImg==0) 
            return;//no bitmap loaded
         
         appli.Image[index].BMPWidth=image_width;
         association_exist=1;
         break;
         }
      }
   }

if((!association_exist) && (index<CI_MAXIMG))
   {
   for(zero_index=0;zero_index<CI_MAXIMG;++zero_index)
      {
      if(appli.Image[zero_index].pImg==0)
         {
         index=zero_index;
         break;
         } 
      }
   
   appli.Image[index].pImg=export_button_bitmap(image_index);
   
   if(appli.Image[index].pImg==0)
      {
      strcpy(appli.Image[index].Label, " ");
      appli.Image[index].BMPWidth=0;    
      appli.Image[index].LabelWidth=0;
      return;//no bitmap loaded
      }
   
   appli.Image[index].Type=but_type;
   appli.Image[index].BMPWidth=image_width;
   appli.Image[index].LabelWidth=strlen(label);
   //memcpy(appli.Image[index].Label, label,width);
   strcpy(appli.Image[index].Label, label);
   }
}

//Coords functions
TI_RECTANGLE GetActiveWindowCoo()
{
PVTI_WINDOW window=(PVTI_WINDOW)appli.fenetr->data;
return window->TxCoo;
}

int DrawAssociatedImage(PTI_RECTANGLE limit,char* label,WORD but_type,WORD label_width)
{
MI_TRACE_DCL_TFN("DrawAssImage");
int index=0;
WORD height;

for(index=0;index<CI_MAXIMG;index++)
   {
   if(label_width>=appli.Image[index].LabelWidth)
      {
      if(appli.Image[index].Type==but_type||but_type>3)
         {
         if(compare_str(label,appli.Image[index].Label,label_width))
            {
            height=20;   
            if(appli.Image[index].pImg==0)
               {
               MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"NULL"));
               return 0;
               }
            centralize_bitmap(limit,appli.Image[index].pImg,appli.Image[index].BMPWidth,height);//height);
            
            MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"found Width=%d",appli.Image[index].BMPWidth));
            return appli.Image[index].BMPWidth;
            }
         }   
      }
   }
   
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"not found"));
return 0;
}

#define MaxStandardBitmap 14
char* bitmap_names[MaxStandardBitmap]={
    "Esc",//0    +Abandon,Annuler,Tchao,By By,Escape,Cancel
    "O.K",
    "[?]",
    ">>",
    "<<",
    ">³",
    "³<",
    "PgUp",
    "PgDn",
    "Cr‚er",//9  +Creat
    "Modif",//10 +Updat
    "Suppr",//11 +Delet
    "Find",
    "Insert"
};

char* file_names_big[MaxStandardBitmap]={
    "z_escb.gif",
    "z_okb.gif",
    "z_rechb.gif",
    "z_rightb.gif",
    "z_leftb.gif",
    "z_endb.gif",
    "z_homeb.gif",
    "z_pgupb.gif",
    "z_pgdnb.gif",
    "z_creeb.gif",
    "z_modib.gif",
    "z_suppb.gif",
    "z_findb.gif",   
    "z_inserb.gif"
};

void LoadAndAssociateStandardBitmaps(char* EnvPath){
MI_TRACE_DCL_TFN("LdAssStdBitmap");
int image_index;
int image_counter=0;
int ret;

CHAR  PathBMP[CI_MAXPATH];

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"begin"));
InitialiseImageSystem();

for(image_index=0;image_index<MaxStandardBitmap;image_index++)
   {
   ToolsFindFile(PathBMP,file_names_big[image_index], EnvPath);
   
   ret = zbmp_load(image_counter+1,PathBMP,TRUE);
   
   if(ret)
      {
      MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"in loop load OK"));
      AssociateImage(image_counter+1, bitmap_names[image_index],strlen(bitmap_names[image_index]),3);
      AssociateImage(image_counter+1, bitmap_names[image_index],strlen(bitmap_names[image_index]),2);
      if (image_index==0)
         {//for escape
         AssociateImage(image_counter+1, "Annuler",3,3);
         AssociateImage(image_counter+1, "Abandon",3,3);
         AssociateImage(image_counter+1, "Tchao",3,3);
         AssociateImage(image_counter+1, "Cancel",3,3);
         AssociateImage(image_counter+1, "Escape",3,3);
         AssociateImage(image_counter+1, "By By",3,3);
  
         AssociateImage(image_counter+1, "Annuler",3,2);
         AssociateImage(image_counter+1, "Abandon",3,2);
         AssociateImage(image_counter+1, "Tchao",3,2);
         AssociateImage(image_counter+1, "Cancel",3,2);
         AssociateImage(image_counter+1, "Escape",3,2);
         AssociateImage(image_counter+1, "By By",3,2);
         }
      if (image_index==9)
         {//for creat
         AssociateImage(image_counter+1, "Creat",5,3);
         AssociateImage(image_counter+1, "Creat",5,2);
         }
      if (image_index==10)
         {//for updat
         AssociateImage(image_counter+1, "Updat",5,3);
         AssociateImage(image_counter+1, "Updat",5,2);
         }
      if (image_index==11)
         {//for delet
         AssociateImage(image_counter+1, "Delet",5,3);
         AssociateImage(image_counter+1, "Delet",5,2);
         }
      
      zbmp_free(++image_counter);
      }   
   }
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"end"));
}


char* icon_names[3]={
  "zi_quest.gif",
  "zi_astrk.gif",
  "zi_exclm.gif"
};

struct standard_image* icons[3];

void LoadStandardIcons(char* EnvPath)
{
int i;
CHAR  PathBMP[CI_MAXPATH];
  for(i=0;i<3;i++){
    icons[i]=0;
    ToolsFindFile(PathBMP,icon_names[i], EnvPath);
    if(zbmp_load(i+1,PathBMP,TRUE)){
      icons[i]=export_button_bitmap(i+1);
      zbmp_free(i+1);
    }
  }
}

void DestroyStandardIcons(){
  int i;
  for(i=0;i<3;i++)
    DropImage(icons[i]);
}

#define ICON_SIZE 2

void DrawMsgbIcon(WORD x,WORD y,int flag){
  TI_RECTANGLE mbox;
  mbox.x1=(x-1)*cellwidth;
  mbox.y1=(y-1)*cellheight;
  mbox.x2=mbox.x1+2*ICON_SIZE*cellwidth;
  mbox.y2=mbox.y1+ICON_SIZE*cellheight;
  if(flag&ZMB_ICONQUESTION){
    if (icons[0]==0) return;
        centralize_bitmap(&mbox,icons[0],2*ICON_SIZE,ICON_SIZE);
    return;
  }
  if(flag&ZMB_ICONASTERISK){
    if (icons[1]==0) return;
        centralize_bitmap(&mbox,icons[1],2*ICON_SIZE,ICON_SIZE);
    return;
  }
  if(flag&ZMB_ICONEXCLAMATION){
    if (icons[2]==0) return;
          centralize_bitmap(&mbox,icons[2],2*ICON_SIZE,ICON_SIZE);
    return;
  }
}

void sdelay(){
  int i,j;
  for(i=0;i<3000;i++)
  for(j=0;j<5000;j++){};
}





 
void move_it(WORD x,WORD y,WORD ll,WORD hh,WORD nx,WORD ny){
/*  PVTI_WINDOW window=(PVTI_WINDOW)appli.fenetr->data;
  TI_POINT m;
  m.x=nx;
  m.y=ny;

  if(nx==window->TxCoo.x1&&ny==window->TxCoo.y1) return;
//  if(x!=nx||y!=ny){
  if(!window->is_WD_allocated){
        window->is_WD_allocated=1;
            window->pImgWD=capture_screen(&window->TxCoo);
        window->is_changed=0;
    }
    if(window->is_changed){
      recapture_screen(window->pImgWD);
            window->is_changed=0;
    }
 //}
 // if(x==nx && y==ny){
      refresh_screen(window->pImgBG);
      capture_screen_at(&m,window->pImgBG);
      move_screen_at(&m,window->pImgWD);
      ToolsMoveRectangle(&m,&window->TxCoo);
   //   HideCorners();

 // }*/
}



        /*if((window->TxCoo.x1!=x1) &&
          (window->TxCoo.y1!=y1)){
            int gratcol=(x1-1)*cellwidth;
      int gratlin=(y1-1)*cellheight;
            window->TxCoo.x1=x1 ;
          window->TxCoo.y1=y1;
          window->TxCoo.x2=x2 ;
          window->TxCoo.y2=y2;
      commit_pixel_storage(window->pImgBG,gratcol,gratlin);
      commit_pixel_storage(window->pImgWD,gratcol,gratlin);
        }*/

/*WORD DrawImageAndDestroyStorage(STDPSUPTR storage)
{
  if(storage!=0){
      refresh_pixel_storage(storage);
      storage = (STDPSUPTR) liberate_pixel_storage( (STDPSUPTR) storage );
    } 
    return 0;
}*/

//STDPSUPTR SaveImage(WORD x1,WORD y1,WORD x2,WORD y2)
//{
//  int gratcol,gratlin,grnbcol,grnblin;
//  STDPSUPTR  storage=0; 
   //No any Combo Frames!!! it is a real window!!! VAP
//  gratcol=(x1-1)*cellwidth;
//  gratlin=(y1-1)*cellheight;
//  grnbcol=(x2-x1+1)*cellwidth;
//  grnblin=(y2-y1+1)*cellheight;

// if ((storage  = (STDPSUPTR) allocate_graphic_storage( 
//      gratcol,gratlin,
//      grnbcol, grnblin 
//      )) != (STDPSUPTR) 0) 
//      capture_pixel_storage(storage);
//return(storage);
//}

//STDPSUPTR SaveImage2(PTI_RECTANGLE rect  ){
//  return SaveImage(rect->x1,rect->y1,rect->x2,rect->y2);
//}








 
