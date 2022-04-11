// ****************************************************************************
// * TraCtx.c
// * Gestion des contextes de trace     
// ****************************************************************************

#include <string.h>
#include <stdlib.h>

#include "wdef.h"
#include "trace.h"
#include "tractx.h"

#define CI_MAX_TRA   64

TI_TRA_CTX* s_TabTraCtx[CI_MAX_TRA];

// ****************************************************************************
// * InitTabTra
// * Tous les index � NULL
// * sauf le n�1 (contexte par d�faut)
// ****************************************************************************
void InitTabTra()
{
WORD i;
s_TabTraCtx[0] = NULL;
s_TabTraCtx[1] = &g_TraCtx;
for(i=2 ; i<CI_MAX_TRA ; i++)
   s_TabTraCtx[i] = NULL;
}

// ****************************************************************************
// * CreateIndex
// * Alloue un nouveau contexte
// *
// * Si le n� est 0xFFFF, on prend le 1er disponible � partir de 2
// * Si l'index est d�j� affect�, on ne fait rien
// * Sinon, on alloue un contexte � cet index
// *
// * Quand �a ne marche pas, on renvoie l'index du contexte par d�faut
// ****************************************************************************
WORD CreateIndex(WORD i)
{
if (i==0xFFFF)
   {
   for(i=2 ; i<CI_MAX_TRA ; i++)
      if (s_TabTraCtx[i] == NULL)
         {
         TI_TRA_CTX* p = (TI_TRA_CTX*)malloc(sizeof(TI_TRA_CTX));
         if (p)
            s_TabTraCtx[i] = p; 
         else
            i=1;
         break;
         }
   return i;
   }

if ((i<CI_MAX_TRA) && (s_TabTraCtx[i]==NULL))
   {
   TI_TRA_CTX* p = (TI_TRA_CTX*)malloc(sizeof(TI_TRA_CTX));
   if (p)
      {
      memset(p,0xAA,sizeof(TI_TRA_CTX));
      s_TabTraCtx[i] = p;
      }
   else
      i=1;
   return i;
   }

return 1;
}

// ****************************************************************************
// * DeleteIndex
// * Lib�re le contexte de l'index (sauf le n�1)
// ****************************************************************************
void DeleteIndex( WORD i)
{
if ((i!=1) && (i<CI_MAX_TRA) && (s_TabTraCtx[i]!=NULL))
   {
   free(s_TabTraCtx[i]);
   s_TabTraCtx[i] = NULL;
   }
}

// ****************************************************************************
// * DeleteAll
// * Lib�re tous les contextes (sauf le n�1)
// ****************************************************************************
void DeleteAll()
{
WORD i;

free(s_TabTraCtx[0]);
s_TabTraCtx[0] = NULL;

for(i=2 ; i<CI_MAX_TRA ; i++)
   {
   free(s_TabTraCtx[i]);
   s_TabTraCtx[i] = NULL;
   }
}

// ****************************************************************************
// * GetCtx
// * Renvoie un pointeur sur le contexte demand�.
// * Quand �a ne marche pas, on renvoie un pointeur sur le contexte par d�faut
// ****************************************************************************
TI_TRA_CTX* GetCtx( WORD i )
{
return ((i<CI_MAX_TRA) && (s_TabTraCtx[i]!=NULL)) ? s_TabTraCtx[i] : s_TabTraCtx[1];
}

