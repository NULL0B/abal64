/******************************************************************************
*
* COMPACTE UNE CHAINE DE CARACTERES:
*   (avec un algo RLE tr�s simple)
* ----------------------------------
*
* Prototypage:  cptsize%=ZRleCpt(acpt$,cpt$,lgacpt%)
*
******************************************************************************/

static int rlecomp(unsigned char * acpt,unsigned char * cpt,int	lgacpt)
{
int rep;

int  i=0;
int  j=0;

  // Mets le car. de compactage RLE:
  cpt[j++]=0x0FE;

  while (i < lgacpt)
  {
      // Caract�re de contr�le:
      if (acpt[i] == 0x0FE)
      {
      cpt[j++]=0x0FE;
      cpt[j++]=0x0FE;
      i++;
      }
      else
      {
      if (cpt[j-1] == acpt[i])  // R�p�tition
      {
        rep=1;      // r�pet = 1
        i++;      // suivant...
        while (rep < 127)
        {
          if (i >= lgacpt) break;   // d�passement maximum autoris�
          if (cpt[j-1] != acpt[i]) break; // si diff�rent, abandonne
          i++;
          rep++;
        }
        cpt[j++]=0x0FE;
        cpt[j++]=(char)rep;
      }       // Pas r�p�tition
      else
        cpt[j++]=acpt[i++];
      }
  }
  cpt[j++]=0x0FE;
  cpt[j++]=0;
  return(j);

}

/******************************************************************************
*
* DECOMPACTE UNE CHAINE DE CARACTERES:
* ------------------------------------
*
* Prototypage:  dcptsize=ZRleDcpt(cpt$,dcpt$,cptsize%)
*
******************************************************************************/

static int rledcomp(unsigned char * cpt,unsigned char * dcpt,int cptsize)
{
int k;
int rep;

int  i=1;
int  j=0;

  // Pas caract�re de contr�le :
  while (1)
  {
      if (cpt[i]==0x0FE)    // FEh
      {
    i++;
    switch (cpt[i])
    {
    case 0 :    // Fin
        return(j);
    case 0x0FE :    // Car de contr�le
        dcpt[j++]=0x0FE;
        i++;
        break;
    default :   // R�p�tition
        rep=cpt[i];
        for (k=0;k<rep;k++)
      dcpt[j++]=cpt[i-2];
        i++;
        break;
    }
      }
      else      // Pas FEh
    dcpt[j++]=cpt[i++];
  }

}


