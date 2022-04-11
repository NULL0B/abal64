/* --------------------------------------------------------------------	*/
/* aconf.c						14/04/94	*/
/* --------------------------------------------------------------------	*/
/* S Barthe 02!09!97 ajout ifdef SHAREDLO pour partageabilit‚ imprimante */
/* S Barthe 07!12!00 ajout       ABALNORESET pour pas d'ioctl STDIN      */
/* --------------------------------------------------------------------	*/

#ifdef DEBUG2
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utmp.h>
#include <ctype.h>

#include "allocate.h"
#include "_type_std.h"
#include "aconf.h"

#endif /* DEBUG */

#define STDIN 0
#define TRUE 1

#ifdef SHAREDLO
#undef SHAREDLO
#define NBMOT 13

#define PROCESS 0
#define SCREEN 1
#define PRINTER 2
#define LANGUAGE 3
#define COLORS 4
#define DEVICE 5
#define COMMENTAIRE 6
#define END 7
#define USERID 8
#define BEFORE15 9
#define DEFAULT 10
#define SHAREDLO 11
#define ABALNORESET 12

static char *STRLEX[NBMOT]={
	"PROCESS",
	"SCREEN",
	"PRINTER",
	"LANGUAGE",
	"COLORS",
	"/dev/",
	"#",
	"END",		
	"USERID",
	"BEFORE15",
	"DEFAULT",
	"SHAREDLO",
	"ABALNORESET"
};

static int LGLEX[NBMOT]={7,6,7,8,6,5,1,3,6,8,7,8};
#else
#define NBMOT 11

#define PROCESS 0
#define SCREEN 1
#define PRINTER 2
#define LANGUAGE 3
#define COLORS 4
#define DEVICE 5
#define COMMENTAIRE 6
#define END 7
#define USERID 8
#define BEFORE15 9
#define DEFAULT 10

static char *STRLEX[NBMOT]={
	"PROCESS",
	"SCREEN",
	"PRINTER",
	"LANGUAGE",
	"COLORS",
	"/dev/",
	"#",
	"END",		
	"USERID",
	"BEFORE15",
	"DEFAULT"
};

static int LGLEX[NBMOT]={7,6,7,8,6,5,1,3,6,8,7};
#endif		/* SHAREDLO */

static int lex(handle,buf)
FILE *handle;
char *buf;
{
int i;

	fscanf(handle,"%s",buf);
	if ( feof(handle) ) {
		return(END);
	}
	i=0;
	while ( i < NBMOT ) {
		if ( ! strncmp(buf,STRLEX[i],LGLEX[i]) )
			break;
		i++;
	}
	return(i);
}

static void establish_config(file_name)
char *file_name;
{
FILE *handle;
char buf[256];
char *dev;
int l,isdev;

int never=1;

	if ((handle = fopen( file_name, "r" )) != (FILE *) 0) {
	abc_screen_nbl = 24;
	abc_screen_nbc = 80;
	isdev=0;
	if ( (dev = ttyname(STDIN)) != NULL ) {
		while ( 1 ) {
			l = lex(handle,buf);

			if ( (l == DEFAULT) && (never==1) ) {
#ifdef DEBUG
				printf("\nDEFAULT");
#endif /* DEBUG */
				isdev = 1;
			}
			if ( l == DEVICE ) {
				if ( ! strcmp(dev,buf) ) {
#ifdef DEBUG
					printf("\nDEVICE:%s ",buf);
#endif /* DEBUG */
					isdev = 1;
					never=0;
				} else {
					isdev = 0;
				}
			}		
			if ( isdev ) {
			switch(l) {
				case PROCESS:
#ifdef DEBUG	
					printf("\nPROCESS ");
#endif /* DEBUG */
					abc_process_flag = TRUE;
					l = lex(handle,buf);
					if ( l == USERID ) {
						abc_process_number = (WORD) getuid();
#ifdef DEBUG
						printf("Userid=");
#endif /* DEBUG */
					} else {
						if ( l == BEFORE15 ) {
							abc_process_number = 0;
							abc_process_flag = FALSE;
#ifdef DEBUG
							printf("Old Method:");
#endif /* DEBUG */
						} else {
							if ( isalpha(buf[0]) ) {
								abc_process_number = (WORD) atoi(getenv(buf));
#ifdef DEBUG
								printf("Var env=");
#endif /* DEBUG */
							} else { 
								abc_process_number = (WORD) atoi(buf);
#ifdef DEBUG
								printf("Constante=");
#endif /* DEBUG */
							}
						}
					}
#ifdef DEBUG
					printf("%d",abc_process_number);
#endif /* DEBUG */
					break;
				case SCREEN:
#ifdef DEBUG
					printf("\nSCREEN ");
#endif /* DEBUG */
					if ( fscanf(handle,"%s%s%d",abc_screen_name,abc_screen_path,&abc_screen_tempo) == 3 ) {
#ifdef DEBUG
						printf("\nTERM=%s",abc_screen_name);
						printf("\nPATH=%s",abc_screen_path);
						printf("\nTEMPO=%d",abc_screen_tempo);
#endif /* DEBUG */
						if ( fscanf(handle,"%d%d",&abc_screen_nbl,&abc_screen_nbc) == 2 ) {
#ifdef DEBUG
							printf("\nNB LIGNES=%d",abc_screen_nbl);
							printf("\nNB COLONNES=%d",abc_screen_nbc);
#endif /* DEBUG */
						}
						abc_screen_flag = TRUE;
					} else {
						printf("Erreur description terminal\n");
						exit(1);
					}
					break;
				case LANGUAGE:
#ifdef DEBUG
					printf("\nLANGUAGE ");
#endif /* DEBUG */
					if ( fscanf(handle,"%d",&abc_language) != 1 ) {
						printf("Erreur description langage\n");
						exit(1);
					} else {
#ifdef DEBUG
						printf("%d",abc_language);
#endif /* DEBUG */
						abc_language_flag = TRUE;
					}
					break;
				case PRINTER:
#ifdef DEBUG
					printf("\nPRINTER ");
#endif /* DEBUG */
					if ( fscanf(handle,"%s%s",abc_printer_name,abc_printer_path) == 2 ) {
#ifdef DEBUG
						printf("\nNAME=%s",abc_printer_name);
						printf("\nPATH=%s",abc_printer_path);
#endif /* DEBUG */
						if ( fscanf(handle,"%d%d",&abc_printer_nbl,&abc_printer_nbc) == 2 ) {
#ifdef DEBUG
							printf("\nNB LIGNES=%d",abc_printer_nbl);
							printf("\nNB COLONNES=%d",abc_printer_nbc);
#endif /* DEBUG */
						}
						abc_printer_flag = TRUE;
					} else {
						printf("Erreur description imprimante\n");
						exit(1);
					}
					break;
				case COLORS:
#ifdef DEBUG
					printf("\nCOLORS ");
#endif /* DEBUG */
					if ( fscanf(handle,"%d%d",&abc_color_char,&abc_color_back) != 2 ) {
						printf("Erreur couleur\n");
						exit(1);
					} else {
#ifdef DEBUG
						printf("%d,%d",abc_color_char,abc_color_back);	
#endif /* DEBUG */
						abc_color_flag = TRUE;
					}
					break;
			}
		}
		switch(l) {
			case COMMENTAIRE:
				while ( fgetc(handle) != '\n' );
				break;
#ifdef SHAREDLO
			case SHAREDLO:
				abc_sharedlo_flag = TRUE;
				break;
			case ABALNORESET:
				abc_noreset_flag = TRUE;
				break;
#endif
			case END:
#ifdef DEBUG
				printf("\nEND\n");
#endif /* DEBUG */
				break;
		}
		if ( l == END ) {
#ifdef DEBUG
			printf("process=%d\n",abc_process_flag);
			printf("screen=%d\n",abc_screen_flag);
			printf("printer=%d\n",abc_printer_flag);
			printf("language=%d\n",abc_language_flag);
			printf("colors=%d\n",abc_color_flag);
#ifdef SHAREDLO
			printf("sharedlo=%d\n",abc_sharedlo_flag);
			printf("abalnoreset=%d\n",abc_noreset_flag);
#endif

#endif /* DEBUG */
			break;
		}
	}
	}
	fclose(handle);
	}
}

#ifdef DEBUG_MAIN
main()
{
	establish_config("aconf");
}
#endif /* DEBUG */

/* -------- Fin de fichier : aconf.c ----------------------------------	*/
