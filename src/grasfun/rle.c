/******************************************************************************
*
* COMPACTE UNE CHAINE DE CARACTERES:
*   (avec un algo RLE très simple)
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
      // Caractère de contrôle:
      if (acpt[i] == 0x0FE)
      {
      cpt[j++]=0x0FE;
      cpt[j++]=0x0FE;
      i++;
      }
      else
      {
      if (cpt[j-1] == acpt[i])  // Répétition
      {
        rep=1;      // répet = 1
        i++;      // suivant...
        while (rep < 127)
        {
          if (i >= lgacpt) break;   // dépassement maximum autorisé
          if (cpt[j-1] != acpt[i]) break; // si différent, abandonne
          i++;
          rep++;
        }
        cpt[j++]=0x0FE;
        cpt[j++]=(char)rep;
      }       // Pas répétition
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

  // Pas caractère de contrôle :
  while (1)
  {
      if (cpt[i]==0x0FE)    // FEh
      {
    i++;
    switch (cpt[i])
    {
    case 0 :    // Fin
        return(j);
    case 0x0FE :    // Car de contrôle
        dcpt[j++]=0x0FE;
        i++;
        break;
    default :   // Répétition
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


