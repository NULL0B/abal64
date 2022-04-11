/*  Copyright (c) 2004 Amenesik / Sologic Technologies
 *
 *  Project  : TTY
 *  Module   : tracetty, conversion fichier trace binaire .bin construit par
 *             tty.so en fichier texte .txt.
 *  File     : tracetty.c
 *  Date     : 09/03/2004
 *  System   : UseIT
 *
 */

/* ----------------------------------------------------------------------
 *
 *  Version       Date      Auteur     Modifications
 *  -------       ----      ------     -------------
 *  1.1a.0.01  	13/01/2004  Chris      - Creation.
 *  1.1a.0.01  	21/01/2004  Chris      - Amelioration du temoin d'activite
 *                                       desormais sur une seule ligne.
 *  1.1a.0.01  	22/01/2004  Chris      - Ajout compteur du point de trace.
 *  1.1a.0.01  	03/02/2004  Chris      - Ajout fonction 0 pour avoir la verion
 *                                       de tty.so.
 *
 *  1.1a.0.02  	24/02/2004  Chris      - Modification de la fonction 0 et de
 *                                       la prise en compte de ttyopen pour
 *                                       gerer la valeur de BDATTYMODE.
 *  1.1a.0.02	04/03/2004  Chris      - Prise en compte nouveau codage de
 *                                       la valeur de BDATTYMODE.
 *                                     - Ajout date apres numero de version.
 *  1.1a.0.02	09/03/2004  Chris      - connect : prise en compte des anciens
 *                                       modes de liaison avec BDATTYMODE=1.
 */

#define	VERSION	"1.1a.0.02 - 09.03.2004"
#define	MAX_BUFFER	32767

/* Fichiers include */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "_type.h"

/*
 *	The buffer of trace is structured with blocks. Format of block is :
 *
 *	time_t : date of call TTY function
 *	function : function number, 1 = open, 2 = close, ...
 *	retcode : value returned to application
 *	nlog : handle returned from open et used by others functions
 *	maxlength : length of application buffer
 *	uselength : length of optional buffer, 0 means without associated data
 *	data : optional datas
 *
 *	The original definition of this structure is in the file utty.h
*/

#pragma	pack(1)
typedef struct {
	time_t	date;		/* Seconds since 01/01/1970	*/
	BYTE	function;	/* TTY function number		*/
	WORD	retcode;	/* Return code of TTY function	*/
	WORD	nlog;		/* handle number of TTY channel	*/
	WORD	maxlength;	/* maximum length of user buffer */
	WORD	uselength;	/* length of next bytes		*/
} TRACE_BIN;
#pragma	pack()


/*
	Fonctions incluses
*/

VOID connect(FILE *,BYTE *,SWORD,WORD);
VOID retour(FILE *,TRACE_BIN,BYTE);
VOID dump(FILE *,BYTE *,WORD);

/*
	Debut du programme
*/

int main(int argc, char * argv [])
{
WORD i,j;
CHAR fname[256];
CHAR buffer[MAX_BUFFER];
CHAR version[33];
WORD compteur=1;
WORD activite=0;
CHAR cactivite='<';
CHAR * pointer;
FILE * finput=(FILE*) 0;
FILE * foutput=(FILE*) 0;
TRACE_BIN point;
struct tm* temps;
WORD bdattymode=0;

/*
	Banniere
*/

	printf("\r\ntracetty : Conversion of binary file from trace of tty.so to text file");
	printf("\r\nSyntax : tracetty file_name.bin");
	printf("\r\nVersion %s",VERSION);
	printf("\r\nCopyright (c) 2004 Amenesik / Sologic Technologies\r\n");

	if ( argv[1] == NULL ) return (0);

	version[0] = '\0';

/*
	Ouvrir le fichier .bin en lecture
*/

	pointer = argv[1];
	for (i=0;i<252;i++)
	{
		fname[i] = *pointer++;
		if (fname[i] == '\0') break;
	}
	if ( i > 4)
	{
		if ( ( fname[i-4] == '.' )
		  && ( fname[i-3] == 'b' )
		  && ( fname[i-2] == 'i' )
		  && ( fname[i-1] == 'n' ) )
		{
			i = i - 4;
		}
		else
		{
			fname[i] = '.';
			fname[i+1] = 'b';
			fname[i+2] = 'i';
			fname[i+3] = 'n';
			fname[i+4] = '\0';
		}
	}

	finput=fopen(fname,"r");
	if ( finput == (FILE *) 0 )
	{
		printf("\r\nOpen file %s is refused by system.",fname);
		goto termine;
	}
	printf("\r\nConversion of file %s is in progress:\r\n",fname);

/*
	Creer le fichier .txt
*/

	fname[i] = '.';
	fname[i+1] = 't';
	fname[i+2] = 'x';
	fname[i+3] = 't';
	fname[i+4] = '\0';

	foutput=fopen(fname,"w");
	if ( foutput == (FILE *) 0 )
	{
		printf("\r\nCreate file %s is refused by system.",fname);
		goto termine;
	}
	fprintf(foutput,"File %s",fname);
	fprintf(foutput,"\r\n---------------------------------------------------------------------------");
	fprintf(foutput,"\r\ntracetty  v%s  Copyright (c) 2004 Amenesik / Sologic Technologies ",VERSION);
	fprintf(foutput,"\r\n---------------------------------------------------------------------------");
	fprintf(foutput,"\r\nInvalid return codes are marked ALERT !!!");

/*
	Lecture du fichier .bin et ecriture du fichier .txt
*/

boucle:
	j = sizeof(TRACE_BIN);
	i = fread((VOID *)&point,1,j,finput);

	if ( i == j )
	{
		if (point.uselength != 0)
		{
			j = point.uselength;
			if ( j > MAX_BUFFER )
			{
				printf("\r\nConvertion aborted, one data buffer is greater than %u.",MAX_BUFFER);
				fprintf(foutput,"\r\nConvertion aborted, one buffer is greater than %u.",MAX_BUFFER);
				goto termine;
			}

			i = fread(buffer,1,j,finput);
		}
	}

	if ( i != j )
	{
		if ( feof(finput) == 0 )
		{
			printf("\r\nRead file is refused by system.");
		}
		else
		{
			if ( compteur > 1 )
			{
				fprintf(foutput,"\r\n======= %02d/%02d/%02d %02d:%02d:%02d ",temps->tm_mday,temps->tm_mon+1,temps->tm_year-100,temps->tm_hour,temps->tm_min,temps->tm_sec);
				fprintf(foutput,"================================================\r\n");
			}
			printf("\r\n\nConversion in file %s is finished.",fname);
		}
		goto termine;
	}

	if (point.function == 0)
	{
		/* Garder la valeur de BDATTYMODE */
		bdattymode = point.retcode;
		i = point.uselength;
		if (i > 32) i = 32;
		buffer[i] = '\0';
		/* Verifier si la version change en cours de journee */
		if ( strcmp(buffer,version) != 0 )
		{
			fprintf(foutput,"\r\n----------------------------------------------------------");
			fprintf(foutput,"\r\nVersion of library tty : %s",buffer);
			fprintf(foutput,"\r\n----------------------------------------------------------\r\n");
			for (j=0;j<i;j++)
			{
				version[j] = buffer[j];
			}
			version[i] = '\0';
		}
		goto boucle;
	}

	temps=localtime(&point.date);

	if (point.function == 1)
	{
		fprintf(foutput,"\r\n======= %02d/%02d/%02d %02d:%02d:%02d ",temps->tm_mday,temps->tm_mon+1,temps->tm_year-100,temps->tm_hour,temps->tm_min,temps->tm_sec);
		fprintf(foutput,"================================================\r\n");
	}

	fprintf(foutput,"\r\n[%05d] %02d:%02d:%02d -> ",compteur,temps->tm_hour,temps->tm_min,temps->tm_sec);
	compteur = compteur + 1;

	switch (point.function )
	{
		case 1 :
			fprintf(foutput,"ttyopen( %u , ",point.nlog);
			for (i=0;i<point.uselength;i++)
			{
				fprintf(foutput,"%c",buffer[i]);
			}
			fprintf(foutput," )");
			retour(foutput,point,0);
			/* Afficher BDATTYMODE si valeur differente de 0 */
			if ( bdattymode != 0 )
			{
				fprintf(foutput,"\r\n  Caution = export BDATTYMODE=%d",bdattymode);
			}
			fprintf(foutput,"\r\n");
			break;
		case 2 :
			fprintf(foutput,"ttyclose( %u )",point.nlog);
			retour(foutput,point,1);
			break;
		case 3 :
			fprintf(foutput,"ttyconnect( %u , Data , %u )",point.nlog,point.uselength);
			retour(foutput,point,1);
			connect(foutput,buffer,point.uselength,bdattymode);
			dump(foutput,buffer,point.uselength);
			fprintf(foutput,"\r\n") ;
			break;
		case 4 :
			fprintf(foutput,"ttydcn( %u )",point.nlog);
			retour(foutput,point,1);
			break;
		case 5 :
		case 0x85 :
			fprintf(foutput,"ttywrite( %u , ",point.nlog);
			if ( point.function == 5 )
			{
				fprintf(foutput,"Normal");
			}
			else
			{
				fprintf(foutput,"Echo");
			}

			fprintf(foutput," , Data , %u )",point.uselength);
			retour(foutput,point,0);
			dump(foutput,buffer,point.uselength);
			fprintf(foutput,"\r\n") ;
			break;
		case 6 :
			fprintf(foutput,"ttyread( %u , Buff , %u )",point.nlog,point.maxlength);
			point.uselength -= 2;
			fprintf(foutput,"\r\n  Lg Data = %u",point.uselength);
			if (point.uselength != 0)
			{
				fprintf(foutput,"\r\n  Lg Read = %u",point.uselength+2);
			}
			retour(foutput,point,0);
			dump(foutput,buffer+2,point.uselength);
			fprintf(foutput,"\r\n") ;
			break;
		case 7 :
			fprintf(foutput,"ttybuffer( %u , %u )",point.nlog,point.maxlength);
			retour(foutput,point,1);
			break;
		default :
			fprintf(foutput,"UNKNOWN FUNCTION (%u)    ALERT !!!\r\n",point.function);
			break;
	}

	/* Affichage du temoin d'activite sur une ligne */

	activite = activite + 1 ;
	if ( activite == 79 )
	{
		activite = 0 ;
		if ( cactivite == '<' )
		{
			cactivite = '>' ;
		}
		else
		{
			cactivite = '<' ;
		}
	}
	if ( activite == 0 ) printf("\r");
	printf("%c",cactivite);

	goto boucle;

/*
	Fin du programme
*/

termine:
	printf("\r\n");

	if ( finput != (FILE *) 0 )
	{
		fclose(finput);
	}
	if ( foutput != (FILE *) 0 )
	{
		fprintf(foutput,"\r\n");
		fclose(foutput);
	}

	return(0);
}

/*
	connect : ajoute les parametres de connexion dans la trace
	-------
*/

VOID connect(handle,buffer,lg,ttymode)
FILE * handle;
BYTE * buffer;
SWORD lg;
WORD ttymode;
{
WORD vitesse=0;
WORD nb;
WORD i;

	/* absence de tampon de connexion */

	if (lg == 0)
	{
		lg = 8;
		buffer[0] = 10;
		buffer[1] = 0x4c;
		buffer[2] = 0x0d;
		buffer[3] = 0x1a;
		buffer[4] = 0;
		buffer[5] = 200;
		buffer[6] = 0;
		buffer[7] = 0;
	}

	/* Controle et prise en compte de la vitesse de transmission */

	switch(buffer[0])
	{
		case 0 : vitesse = 50;
			 break;
		case 1 : vitesse = 75;
			 break;
		case 2 : vitesse = 110;
			 break;
		case 3 : vitesse = 134;
			 break;
		case 4 : vitesse = 150;
			 break;
		case 5 : vitesse = 300;
			 break;
		case 6 : vitesse = 600;
			 break;
		case 7 : vitesse = 1200;
			 break;
		case 8 : vitesse = 1800;
			 break;
		case 10 : vitesse = 2400;
			  break;
		case 12 : vitesse = 4800;
			  break;
		case 14 : vitesse = 9600;
			  break;
		case 15 : vitesse = 19200;
			  break;
		case 16 : vitesse = 38400;
			  break;
		case 17 : vitesse = 57600;
			  break;
	}

	if (vitesse == 0)
	{
		/* Autres valeurs et 2000, 3600 et 7200 bits/s non supportes */
		fprintf(handle,"\r\n  Speed  = value NOT MANAGED");
	}
	else
	{
		fprintf(handle,"\r\n  Speed  = %u",vitesse);
	}

	if (--lg == 0 ) return;

	/* Format du caractere */

	switch(buffer[1] & 0x0c)
	{
		case 0x00 : nb = 5;
			    break;
		case 0x04 : nb = 6;
			    break;
		case 0x08 : nb = 7;
			    break;
		case 0x0c : nb = 8;
			    break;
	}
	fprintf(handle,"\r\n  Format = %u bits, ",nb);

	switch(buffer[1] & 0x30)
	{
		case 0x00 : fprintf(handle,"without parity, ");
			    break;
		case 0x10 : fprintf(handle,"with odd parity, ");
			    break;
		case 0x20 : fprintf(handle,"with UNKNOWN parity, ");
			    break;
		case 0x30 : fprintf(handle,"with even parity, ");
			    break;
	}

	switch(buffer[1] & 0xc0)
	{
		case 0x00 : fprintf(handle,"UNKNOWN bit stop number");
			    break;
		case 0x40 : fprintf(handle,"1 bit stop");
			    break;
		case 0x80 : fprintf(handle,"1,5 bit stop NOT MANAGED");
			    break;
		case 0xc0 : fprintf(handle,"2 bits stop");
			    break;
	}

	if ( (buffer[1] & 0x03) != 0 )
	{
		fprintf(handle,"\r\n  Warning : bits 0 and 1 of format of character are not 0");
	}

	if (--lg == 0 ) return;

	/* Caractere fin enregistrement */

	fprintf(handle,"\r\n  Field  = /%02X",(buffer[2] & 0x00ff));

	if (--lg == 0 ) return;

	/* Caractere fin de fichier */

	fprintf(handle,"\r\n  E.O.F. = /%02X",(buffer[3] & 0x00ff));

	if (--lg == 0 ) return;

	/* Time-out de reception */

	fprintf(handle,"\r\n  Timer  = %u",(((buffer[4] & 0x00ff)*256)+(buffer[5] & 0x0ff)));

	lg = lg - 2;
	if (lg < 0) return;
	if (lg == 0)
	{
		lg = 1;
		buffer[6] = 0;
	}

	/* Mode transparent */

	fprintf(handle,"\r\n  Transp = %u, ",(buffer[6] &0x00ff));
	switch(buffer[6])
	{
		case 0 :
			fprintf(handle,"the parameters Field and E.O.F are managed");
			break;
		case 1 :
			fprintf(handle,"the parameters Field and E.O.F are ignored");
			break;
		default :
			fprintf(handle,"the parameters Field and E.O.F are managed");
			fprintf(handle,"\r\n           but the value of this parameter is NOT VALID");
	}

	if (--lg == 0)
	{
		lg = 1;
		buffer[7] = 0;
	}

	/* Mode de transmission */

	i = buffer[7] & 0x00ff;	/* ne pas changer buffer[7] pour le dump tampon */
	fprintf(handle,"\r\n  Mode   = %u, ",i);
	if ( (ttymode & 0x0001) != 0 )
	{
		/* BDATTYMODE=1 : permutation des modes 1 et 2 */
		switch(i)
		{
			case 1 : i= 2;
			 	 break;
			case 2 : i= 1;
				 break;
		}
	}
	switch(i)
	{
		case 0 : fprintf(handle,"half-duplex with V24 signals");
			 fprintf(handle,"\r\n           this mode is not always well supported");
			 break;
		case 1 : fprintf(handle,"full-duplex with V24 signals");
			 break;
		case 2 : fprintf(handle,"full-duplex without V24 signals");
			 break;
		case 3 : fprintf(handle,"full-duplex without V24 signals with X-ON/X-OFF regulation");
			 fprintf(handle,"\r\n           this mode is not always well supported");
			 break;
		default : fprintf(handle,"UNKNOWN, INVALID VALUE");
			  break;
	}
	if ( (ttymode & 0x0001) != 0 )
	{
		if ( (i == 1) || (i == 2) )
		{
			fprintf(handle," (BDATTYMODE=1)");
		}
	}

	if (--lg != 0)
	{
		fprintf(handle,"\r\n  Warning : the others parameters are ignored");
	}

	return;
}

/*
	retour : ajoute la ligne ret = xx dans la trace
	------
*/

VOID retour(handle,point,type)
FILE * handle;
TRACE_BIN point;
BYTE type;
{
	fprintf(handle,"\r\n  RetCode = %u",point.retcode);
	if ( point.retcode != 0 )
	{
		if ( (point.function != 6) || (point.retcode != 91) )
		{
			fprintf(handle,"  ALERT !!!") ;
		}
	}
	if ( type == 1 )
	{
		fprintf(handle,"\r\n") ;
	}

	return;
}

/*
	dump : affiche sous forme dump hexa+ascii le contenu d'un buffer
	----
*/

VOID	dump(handle,buffer,lg)
FILE * handle;
BYTE * buffer;
WORD lg;
{
CHAR bufascii[17];
BYTE * pointer;
BYTE car;
WORD i;			/* compteur pour une ligne */
WORD j=0;		/* adresse debut de ligne */

	if ( lg == 0 ) return;

	fprintf(handle,"\r\n\r\n  Data= 00 01 02 03 04 05 06 07  08 09 0A 0B 0C 0D 0E 0F  0123456789ABCDEF") ;
 	fprintf(handle,"\r\n        --+--+--+--+--+--+--+--  --+--+--+--+--+--+--+--  -+-+-+-+-+-+-+-+\r\n  %04X  ",j) ;

	bufascii[16] = '\0';
	pointer = buffer;
	i = 0;

	while ( lg-- > 0 )
	{
		if ( i == 8 )
		{
			fprintf(handle," ");
		}
		car = ((*pointer++) & 0x00ff);
		fprintf(handle,"%02X ",car);
		if ( ( car > 0x20 ) && ( car < 0x7e ) )
		{
			bufascii[i++] = car ;
		}
		else
		{
			bufascii[i++] = '.' ;
		}
		if ( i == 16 )
		{
			j = j + 16;
			fprintf(handle," %s\r\n  %04X  ",bufascii,j);
			i = 0;
		}
	}

	if ( i != 0 )
	{
		bufascii[i] = '\0';
		if ( i <= 8 ) fprintf(handle," ");
		while( i++ != 16)
		{
			fprintf(handle,"   ");
		}
		fprintf(handle," %s",bufascii);
	}

	return;
}

