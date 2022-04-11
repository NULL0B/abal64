/*
 *	Definitions generales pour les entrees / sorties standards
 *	
 *	Bibliotheque d'exploitation du C sous Amenesik / Sologic - Version 1.1x -
 *		(C) 1987 Copyright Amenesik / Sologic s.a. 
 */

/* bloc de controle d'un fichier bufferise */
struct _fcb
{
	char _flag;		/* etat courant de l'acces		*/
	char *_pch;		/* pointeur to car courant ds buffer	*/
	int _cnt;		/* nb octets restants ds buffer read/write */
	char *_buf;		/* adresse buffer			*/
	int _bufsize;		/* taille buffer			*/
	int _numbuf;		/* numero de bloc 			*/
	char _fd;		/* numero logique / file handle 	*/
} ;

#define EOF (-1)
#define NULL 0

#define TRUE	1
#define FALSE	0

#define bell() putch(0x07)

#define FILE struct _fcb
#define NFILES 15

extern FILE _fcb[NFILES];

#define	stdin  (&_fcb[0])
#define	stdout (&_fcb[1])
#define	stderr (&_fcb[2])
#define stdaux (&_fcb[3])
#define	stdprn (&_fcb[4])

#define  getchar()   fgetc(stdin)
#define  putchar(c)  fputc((c),stdout)

/* parametres gestion des fichiers bufferises */

#define BUFSIZ 256

/* masques pour les verifs d'acces */

#define READ	0x01
#define WRITE	0x02
#define MODIFY	0x04

#define BINARY	0x08
#define USERBUF 0x10

#define FEOF	0x20
#define FERR	0x40

/* Masques pour la fonction open */

#define	O_RDONLY	0x0000
#define	O_WRONLY	0x0001
#define	O_RDWR		0x0002
#define	O_APPEND	0x0008	/* Ecriture en fin de fichier (non gere) */

#define	O_CREAT		0x0100	/* Creation et ouverture */
#define	O_TRUNC		0x0200	/* Supprimer le fichier s'il existe */
#define	O_EXCL		0x0400	/* indiquer erreur si fichier existant */
#define	O_TEXT		0x4000	/* mode texte (non supporte) */
#define	O_BINARY	0x8000	/* mode binaire */



#define	 getc(fp)    fgetc(fp)
#define  feof(f)     ((f)->_flag & FEOF)
#define  ferror(f)   ((f)->_flag & FERR)
#define  fileno(f)   ((f)->_fd)
#define  putc(c,fp)    fputc(c,fp)
#define  clearerr(f) ((f)->_flag &= (~(FERR | FEOF)))

/* masque pour LSEEK  */

#define	SEEK_SET	0
#define	SEEK_CUR	1

#ifdef ALLALA
#ifdef LINT_ARGS	/* Test des arguments */
int 	fclose(FILE *);
FILE * 	fdopen(int, char *);
int 	fflush(FILE *);
int 	fgetc(FILE *);
char * 	fgets(char *, int, FILE *);
FILE * 	fopen(char *, char *);
int 	fprintf(FILE *, char *, ...);
int 	fputc(int, FILE *);
int 	fputs(char *, FILE *);
int 	fread(char *, int, int, FILE *);
int 	fscanf(FILE *, char *, ...);
int 	fseek(FILE *, long, int);
long 	ftell(FILE *);
int 	fwrite(char *, int, int, FILE *);
char * 	gets(char *);
int 	getw(FILE *);
void 	perror(char *);
int 	printf(char *, ...);
int 	puts(char *);
int 	putw(int, FILE *);
int 	rename(char *, char *);
void 	rewind(FILE *);
int 	scanf(char *, ...);
void 	setbuf(FILE *, char *);
int 	ungetc(int, FILE *);
int 	unlink(char *);

#else

int 	fclose();
FILE * 	fdopen();
int 	fflush();
int 	fgetc();
char * 	fgets();
FILE * 	fopen();
int 	fprintf();
int 	fputc();
int 	fputs();
int 	fread();
int 	fscanf();
int 	fseek();
long 	ftell();
int 	fwrite();
char * 	gets();
int 	getw();
void 	perror();
int 	printf();
int 	puts();
int 	putw();
int 	rename();
void 	rewind();
int 	scanf();
void 	setbuf();
int 	ungetc();
int 	unlink();

#endif
#endif

