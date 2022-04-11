#include <windows.h>
#include <stdio.h>

#include "singver.h"

#include "pubmanagercico.h"
#include "pubmanagercico.h"
#include "pubregkey.h" 
#include "guimouse.h"
#include "ctExec.h"

BOOL GetNoWait(void);
void put_palette(void);

// ===================================================================================
// = EXTRAITS D'AUTRES FICHIERS
// ===================================================================================

#define TAMPON			0		/* numero peripherique tampon */
#define ECRAN			1		/* numero peripherique ecran */
#define IMPRIMANTE	2		/* numero peripherique imprimante */

// ===================================================================================
// = SYMBOLES NON RESOLUS
// ===================================================================================

unsigned long		err_val = 0; // wexa cico
unsigned short		prndest = ECRAN; // cico (cicoapi.c wprl2.c) gigo (stdgigo.c)
unsigned long		prnfid  = 0; // cico (wcico.c wprl2.c)
unsigned char *  	prnptr  = 0; // cico (cicoapi.c-local_x_putch)
unsigned short		prnleng = 0; // cico (cicoapi.c-local_x_putch)

int	verbose;

#include <setjmp.h>
jmp_buf	Ed_Exit;

// cico (wcico.c-OnGetImpArray) VERUE
unsigned long GetOriginalHandle( unsigned long lfh )
{	
return 0;
}

// ===================================================================================
// = FONCTIONS NON RESOLUES DANS SINGKERNEL
// ===================================================================================
void usleep( unsigned long microsecond )
{
Sleep( microsecond / 1000 ); // Sleep est en millisecondes
}

void sleep( unsigned long second )
{
Sleep( second * 1000 ); // Sleep est en millisecondes
}

void* select_difference( int p)
{
return 0;
}

int calculate_differences( char* p1, int p2, char* p3, int p4, int p5)
{
return 0;
}

void release_differences()
{}

#ifdef SANS_PAPER_C
void collect_paper_dimensions(  int* h, int* w, int p1, int p2)
{}
#endif

// ===================================================================================
// = FONCTIONS CICO
// ===================================================================================
unsigned short	get_mimo_row()		{ return(x_event(8)); }
unsigned short	get_mimo_column()	{ return(x_event(9)); }

void  put_palette_byexa()
{
	put_palette();
}

int	find_image_byexa( const char * oriname, char * desname )
{
struct x_graph_descriptor xGd;

	xGd.buffer  = (char *) oriname;
	xGd.buffer2 = (char *) desname;
	return( x_graph( _XGR_FINDIMAGE, & xGd ) );
}

int	find_font_byexa( const char * oriname, char * desname )
{
struct x_graph_descriptor xGd;

	xGd.buffer  = (char *) oriname;
	xGd.buffer2 = (char *) desname;
	return( x_graph( _XGR_FINDFONT, & xGd ) );
}

/* FCH22042005 gestion dynamique du charset (ajout du parametre) */
int ClipboardGet_byexa( char* Buf, long lgBuf, unsigned short fcharset)
{
struct x_graph_descriptor xGd;

	xGd.buffer = Buf;
	xGd.length = lgBuf;
	xGd.length2 = 1; /*IsConv*/
	xGd.value  = fcharset;
	return( x_graph( _XGR_PASTE, & xGd ) );
}

/* FCH22042005 gestion dynamique du charset (ajout du parametre) */
int ClipboardSet_byexa( char* Buf, long lgBuf, unsigned short fcharset)
{
struct x_graph_descriptor xGd;
	
	xGd.buffer = Buf;
	xGd.length = lgBuf;
	xGd.length2 = 1; /*IsConv*/
	xGd.value  = fcharset;
	return( x_graph( _XGR_PUBLISH, & xGd ) );
}

/* FCH22042005 gestion dynamique du charset */
int publish_selection( char* Buf, long lgBuf)
{
	return ClipboardSet_byexa(Buf, lgBuf, x_event(EVT_CHARSET));
}

int	iso_conversion_value( int v )
{
return 0;
}

void	dropsysfontlist()
{
}

int	getsysfontlist( void ** vptr, char * wildcards, int wildlen )
{
return 0;
}

void	set_desktop_icon( char * nptr )
{
}

void	set_desktop_name( char * nptr )
{
}

int	use_new_mimo()	{ return(0); }

void *	share_psu(int process)	{	return((void *) 0); 	}
void *	check_psu(void * p)	{	return(p );		}

void	initialise_mouse()
{
init_mimo();
activate_mimo();
}

void	terminate_mouse()
{
inhibit_mimo();
fin_mimo();
}

void	without_mouse_move()
{
set_mimo_mask((
	_MIMO_ALT        |
	_MIMO_WHILE_DOWN |
	_MIMO_DOWN 	 |
	_MIMO_UP 	 |
	_MIMO_CLICK	 |
	_MIMO_SEND_RIGHT |
	_MIMO_SEND_LEFT  |
	_MIMO_SEND_WHEEL 	   ));
}

// ===================================================================================
// = FONCTIONS JPEG pour info si on veut faire une dll
//void	set_image_quality(int v)
//int	get_image_quality()
//int	jpg_create( char * filename, unsigned int w, unsigned int h, int tc, int ps, unsigned char * palette )
//int	jpg_row(int r, unsigned char * rowbuffer, int rl )
//int	jpg_close()
//struct standard_image * jpeg_loader( char * filename )
// ===================================================================================


// ===================================================================================
// = FONCTIONS VIDES EDITEUR INTEGRE
// ===================================================================================

/*
int editorOnLoseFocus()
{
return 0;
}

int editorOnGetFocus()
{
return 0;
}

int editorOnUseString(char* buf)
{
return 0;
}

int editorInitEcran()
{
return 0;
}

int editor_window_connection(char* buf)
{
return 0;
}

int editorOnQuit()
{
return 0;
}

int editorOnHide()
{
return 0;
}

int editorOnUpdate(char* buf)
{
return 0;
}

int editorOnUseEvent(int event)
{
return 0;
}

int editorOnShow()
{
return 0;
}

int editorOnCreate( int argc, char** argv)
{
return 0;
}

int editorOnRemove( int x)
{
return 0;
}

int editorOnHigh( int p1, int p2)
{
return 0;
}

int editorGetToken( char* p1, int p2)
{
return 0;
}

int editorOnColour( int p1, int normal, int string, int keyword, int comment, int punctuation)
{
return 0;
}

int editorOnSeek( int p1, int offset)
{
return 0;
}

int editorCommandWindow()
{
return 0;
}

int editorGetPosition( char** nptr, int* nbl, int* topline, int* endline)
{
return 0;
}

int editorOnSearch( char * cptr, int respect, int direct )
{
return 0;
}

int editorOnReplace( char* sptr, char* rptr, int respect, int direct, int replaceall )
{
return 0;
}

void toggle_colour_control(char*x)
{}

void HyperText()
{}
*/

// ===================================================================================
// = dir_seek
// = PROVENANT DU KERNEL EXECUTEUR avec adaptation pour le mettre dans Sing
// ===================================================================================

// =====================
// Récupérer de exword.h
// =====================

#define	balputw( Vx , Tx )	{\
				*((unsigned char*) (Tx + 1)) = (unsigned char) ( Vx & 0x00FF );\
				*((unsigned char*)  Tx)      = (unsigned char) (( Vx & 0xFF00) >> 8);\
				}
// ====================
// Récupéré de excalc.c
// ====================

static unsigned long lenuzend(unsigned char* cp, unsigned long lenmax)
{ unsigned long i;

	for (i = 0 ; i < lenmax ; i++) {
		if (cp[i] == 0)	break;
	}
	while (i != 0) {
		if (cp[i-1] == ' ')	i--;
		else			break;
	}
	return(i);
}

// =================================
// Récupéré de exllfind.c et exoth.c
// =================================

#define	FICBUFFLEN				276
#define	ATTRIBOFFSET			0
#define	FILENAMEOFFSET			0x0009
#define	FILESIZEHIGHOFFSET	7
#define	FILESIZELOWOFFSET		5
#define	FILEDATEOFFSET			3
#define	FILETIMEOFFSET			1
#define SEEKHANDLEOFFSET		269
#define	INFOTYPEOFFSET			273

/* --------------------------------------------------------------------------
 *
 * FCT FileInfoConv
 *
 *	Converti la structure d'info de fichier WIN32 en une structure
 *	d'information privee.
 *
 *	E/ rien
 *	S/ rien
 *
 *
 */
static void FileInfoConv( unsigned char* FileInfo, const LPWIN32_FIND_DATA pInfo, HANDLE SeekHandle, unsigned long InfoType)
{
	BYTE	attrib;
	WORD 	wr_time,wr_date;
	DWORD	size;
	FILETIME tmpFileTime;

	attrib=0;
	if( pInfo->dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE )
		attrib |= 0x20;		/* attribut d'archive*/
																	
	if( pInfo->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
		attrib |= 0x10;		/* fichier de type repertoire */

	if( pInfo->dwFileAttributes & FILE_ATTRIBUTE_HIDDEN )
		attrib |= 0x02;		/* fichier caché */

	if( pInfo->dwFileAttributes & FILE_ATTRIBUTE_READONLY )
		attrib |= 0x01;		/* attribut de lecture seule*/

	if( pInfo->dwFileAttributes & FILE_ATTRIBUTE_SYSTEM )
		attrib |= 0x04;		/* fichier syteme */


	/* Champs DATE et HEURE */
	FileTimeToLocalFileTime(&(pInfo->ftLastWriteTime),&tmpFileTime);
	FileTimeToDosDateTime(&tmpFileTime,(LPWORD)&(wr_date),(LPWORD)&(wr_time));

	/* Taille du fichier */
	size=pInfo->nFileSizeLow;
	
	/* On rempli le buffer d'info */
	memcpy(FileInfo+ATTRIBOFFSET,(LPSTR)&attrib,sizeof(attrib));
	memcpy(FileInfo+FILESIZELOWOFFSET,(LPSTR)&size,sizeof(size));
	memcpy(FileInfo+FILEDATEOFFSET,(LPSTR)&wr_date,sizeof(wr_date));
	memcpy(FileInfo+FILETIMEOFFSET,(LPSTR)&wr_time,sizeof(wr_time));

	/* Nom du fichier */
	strcpy((LPSTR)(FileInfo+FILENAMEOFFSET),(LPSTR)&(pInfo->cFileName[0]));

	/* Handle de recherche */	
	memcpy(FileInfo+SEEKHANDLEOFFSET,(LPSTR)&SeekHandle,sizeof(SeekHandle));

	/* Type de recherche */	
	memcpy(FileInfo+INFOTYPEOFFSET,(LPSTR)&InfoType,sizeof(InfoType));
}

/* --------------------------------------------------------------------------
 *
 * FCT dir_seek
 *
 *	Adapté du code de l'exécuteur
 *
 */
unsigned long	dir_seek( unsigned char* rptr , unsigned long rlen , unsigned char* pptr , unsigned long plen , unsigned long mode )
{
	unsigned long 	loclen,lerr;
	unsigned long 	ecart=0;
	unsigned long 	temp;
	unsigned char*	tptr;
	unsigned char  c;

	unsigned char  fidbuff[FICBUFFLEN]; 
	unsigned char  askbuf[FICBUFFLEN];

	WIN32_FIND_DATA FindFileData;
	BOOL ret;

	static HANDLE 	SeekHandle; // Static car utilisé d'un appel à l'autre (init par First, puis utilisé par Next)
	
	if (mode & 0x0020) 
	{
		ecart = 11;
		rptr += ecart;
		rlen -= ecart;
	}

	while ( 1 ) {	/* DOS does not separate files from directories */

		/* Separate FIND FIRST from FIND NEXT */
		/* ---------------------------------- */
		if ( (mode & 1 ) == 0 ) 
			{
			/* Check for space in buffer for terminator */
			/* ---------------------------------------- */
			if ((loclen = lenuzend(pptr,plen)) == plen) 
				{
				/* Duplicate in current ASK buffer */
				/* ------------------------------- */
				memcpy(askbuf,pptr,plen); 
				pptr = askbuf;
				}

			/* Collect current last byte and save */
			/* ---------------------------------- */
			c = *(pptr + loclen);

			/* Establish DOS 'C' terminator */
			/* ---------------------------- */
			*(pptr + loclen) = 0;

			/* Perform Operation then replace previous byte */
			/* -------------------------------------------- */
			SeekHandle = FindFirstFile(pptr,&FindFileData);
			if (SeekHandle!=INVALID_HANDLE_VALUE)
				{
				FileInfoConv( fidbuff, &FindFileData, SeekHandle, mode);
				lerr = 0;
				}
			else
				lerr = -1;

			*(pptr + loclen) = c;
			}

		else
			{	
			/* Perform FIND NEXT */
			/* ----------------- */
			ret = FindNextFile(SeekHandle,&FindFileData);
			if (ret)
				{
				FileInfoConv( fidbuff, &FindFileData, SeekHandle, mode);
				lerr = 0;
				}
			else
				lerr = -1;
			}

		mode |= 1;	/* Force to NEXT */

		/* Check for system error */
		/* ---------------------- */
		if ( lerr == 0 ) {

			/* Filter out files if directories required */
			/* ---------------------------------------- */
			if ( (unsigned char)( mode & 0x0010 ) != (unsigned char)(*(fidbuff + ATTRIBOFFSET) & 0x0010))
				continue;

			/* Ok Somethng has been found */
			/* -------------------------- */
			if ((loclen = strlen( (fidbuff + FILENAMEOFFSET) )) > rlen ) {
				errno = 63; 
				lerr = -1;
				loclen = rlen;
				}
			else	errno = 0;

			/* Prewipe buffer with spaces */
			/* -------------------------- */
			if ( rlen   > 0 ) 
				memset( rptr , ' ' , rlen );

			/* Copy found filename to result buffer */
			/* ------------------------------------ */
			if ( loclen > 0 ) 
				memcpy( rptr , (fidbuff + FILENAMEOFFSET ) , loclen );

			if ( ecart != 0 ) {

				/* Informations sur le fichier */
				rptr -= ecart;
				memset( rptr, 0, ecart );
				tptr = fidbuff;
		
				/* File size */
				temp = *((unsigned long*)(tptr+FILESIZEHIGHOFFSET));
				balputw( temp, (rptr + 7) );
				temp = *((unsigned long*)(tptr+FILESIZELOWOFFSET));
				balputw( temp, (rptr + 9) );
		
				/* Date de modif */
				temp = *((unsigned long*)(tptr + FILEDATEOFFSET));
				*(rptr + 3) = (char)(temp & 0x001F);
				*(rptr + 2) = (char)((temp >> 5) & 0x000F);
				temp = ((temp >> 9) & 0x003F);
				temp += 1980;
				balputw( temp, rptr );
		
				/* Heure de modif */
				temp = *((unsigned long*)(tptr + FILETIMEOFFSET));
				*(rptr + 6) = (char)((temp & 0x001F) << 1);
				*(rptr + 5) = (char)((temp >> 5) & 0x003F);
				*(rptr + 4) = (char)((temp >> 11) & 0x001F);	
				}
			return(lerr);
			}
		else	{
			errno = 40;	
			return(-1);  
			}
		}
}

// ===================================================================================
// = windows_create_process
// ===================================================================================
int windows_create_process(char* cmdline, int IsWaiting )
{
	int ret;
	if (IsWaiting)
		ret = ctExecute(cmdline,CT_EXECUTE_AND_WAIT | CT_DISPATCH_MESSAGE ,NULL);
	else
		ret = ctExecute(cmdline,CT_EXECUTE_DO_NOT_WAIT | CT_SHOW_WINDOW ,NULL);
	return ret;
}

// ===================================================================================
// = MyMessageBox
// ===================================================================================
int MyMessageBox(char* msg)
{
	return MessageBox(NULL,msg,"FCH",MB_OK);
}

// ===================================================================================
// = confgetenv
// ===================================================================================
char *confgetenv( const char *varname )
{
	return MgetenvUserOrSys(varname);
}


