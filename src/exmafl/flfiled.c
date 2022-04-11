/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1997
 *	Module  : EXA
 *	Fichier : FLFILED.C
 *	Version : 1.1b
 *	Date    : 10/04/97
 *	Systeme : Windows 3 / NT / MS-DOS / Unix
 *
 *	Methodes d'acces
 *
 *	[DLL acces direct + sequentiel - Code pour version de debug]
 *
 */

#ifndef __DEBUG__

/* Hors mise au point : on utilise directement les fonctions */

#define _FFbegin   FFbegin
#define _FFend     FFend
#define _FFopen    FFopen
#define _FFcreate  FFcreate
#define _FFclose   FFclose
#define _FFaccess  FFaccess
#define _FFunlink  FFunlink
#define _FFatbopen FFatbopen
#ifndef	VERSION666
#define _FFread    FFread
#define _FFwrite   FFwrite
#else
#define _FFread    FFread64
#define _FFwrite   FFwrite64
#endif
#define _FFextend  FFextend
#define _FFrename  FFrename
#define _SQopen    SQopen
#define _SQcreate  SQcreate
#define _SQclose   SQclose  
#define _SQunlink  SQunlink 
#define _SQatbopen SQatbopen
#define _SQread    SQread
#define _SQwrite   SQwrite
#define _SQmodif   SQmodif
#define _SQrewind  SQrewind
#define _SQrename  SQrename

#else /* __DEBUG__ */

/* En mise au point : on utilise des fonctions d'entete */

/* --------------------------------------------------------------------------
 *
 * Pour chaque fonction exportee, on cree une fonction d'entete qui
 * affiche sur le terminal de debug, les arguments d'entree et la
 * valeur de retour.
 *
 * -------------------------------------------------------------------------- */

int WINAPI FFbegin(flconf,lpABQT)
FLCONF SPTR flconf;
FARPROC lpABQT;
{ int r;
  U8 b[128];

	fl_xsprintf((CPTR)b,"\n-----------[ Nouvelle session FFbegin %0.8lX]-----------",(FARPROC)*FFbegin);
	ReqTrace((CPTR)b);

	r = _FFbegin(flconf,lpABQT);

	return(r);
}

int WINAPI FFend(cnx)
EHANDLE cnx;
{ int r;
  U8 b[128];


	r = _FFend(cnx);

	fl_xsprintf((LPSTR)b,"\nFFend(%0.8lX)=%d",(EHANDLE)cnx,r);
	ReqTrace((LPSTR)b);

#ifdef WIN1632
	fl_xsprintf((LPSTR)b,"\nFFend - Tas : %d",wmalloc_state());
	ReqTrace((LPSTR)b);
#endif
	fl_xsprintf((LPSTR)b,"\n-----------[ Fin de session FFend]------------\n");
	ReqTrace((LPSTR)b);

	return(r);
}

EHANDLE WINAPI FFopen(nom,ex,cop,erreur)
LPSTR nom;
int ex;
int cop;
LPINT erreur;
{ EHANDLE r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nFFopen('%s',%d,%d,%0.8lX)",nom,ex,cop,erreur);
	ReqTrace((LPSTR)b);

	r = _FFopen(nom,ex,cop,erreur);

	fl_xsprintf((LPSTR)b," = {%0.8lX},%d",r,*erreur);
	ReqTrace((LPSTR)b);
#ifdef WIN1632
	fl_xsprintf((LPSTR)b,"\nFFopen - Tas : %d",wmalloc_state());
	ReqTrace((LPSTR)b);
#endif

	return(r);
}

EHANDLE WINAPI FFcreate(nom,ex,cop,erreur)
LPSTR nom;
int ex;
int cop;
LPINT erreur;
{ EHANDLE r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nFFcreate('%s',%d,%d,%0.8lX)",nom,ex,cop,erreur);
	ReqTrace((LPSTR)b);

	r = _FFcreate(nom,ex,cop,erreur);

	fl_xsprintf((LPSTR)b," = {%0.8lX},%d",r,*erreur);
	ReqTrace((LPSTR)b);
#ifdef WIN1632
	fl_xsprintf((LPSTR)b,"\nFFcreate - Tas : %d",wmalloc_state());
	ReqTrace((LPSTR)b);
#endif
	return(r);
}

int WINAPI FFclose(ExternalHandle)
EHANDLE ExternalHandle;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nFFclose({%0.8lX})",ExternalHandle);
	ReqTrace((LPSTR)b);

	r = _FFclose(ExternalHandle);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
#ifdef WIN1632
	fl_xsprintf((LPSTR)b,"\nFFclose - Tas : %d",wmalloc_state());
	ReqTrace((LPSTR)b);
#endif
	return(r);
}

int WINAPI FFaccess(nom,ex)
LPSTR nom;
int ex;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nFFaccess('%s',%d)",nom,ex);
	ReqTrace((LPSTR)b);

	r = _FFaccess(nom,ex);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI FFunlink(nom)
LPSTR nom;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nFFunlink('%s')",nom);
	ReqTrace((LPSTR)b);

	r = _FFunlink(nom);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI FFatbopen(ExternalHandle,val,type)
EHANDLE ExternalHandle;
int val;
int type;
{ int r;
  U8 b[128];


	fl_xsprintf((LPSTR)b,"\nFFatbopen({%0.8lX},%d,%d)",ExternalHandle,val,type);
	ReqTrace((LPSTR)b);

	r = _FFatbopen(ExternalHandle,val,type);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI FFread(ExternalHandle,position,buffer,buflen,lu)
EHANDLE ExternalHandle;
LSEEKTYPE position;
CPTR buffer;
int buflen;
LPINT lu;
{ int r;
  U8 b[128];
  LSEEKTYPE x = 0L;

#ifdef WIN32
	x = GetCurrentThreadId();
#endif	
	fl_xsprintf((LPSTR)b,"\nThread :%0.8lX - FFread({%0.8lX},%ld,%0.8lX,%d,%0.8lX)",
		x,ExternalHandle,position,buffer,buflen,lu);
	ReqTrace((LPSTR)b);

	r = _FFread(ExternalHandle,position,buffer,buflen,lu);

	fl_xsprintf((LPSTR)b," = %d, lu=%d ",r,*lu);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI FFwrite(ExternalHandle,position,buffer,buflen,ecrit)
EHANDLE ExternalHandle;
LSEEKTYPE position;
CPTR buffer;
int buflen;
LPINT ecrit;
{ int r;
  U8 b[128];
  LSEEKTYPE x = 0L;

#ifdef WIN32
	x = GetCurrentThreadId();
#endif	

	fl_xsprintf((LPSTR)b,"\nThread :%0.8lX - FFwrite({%0.8lX},%ld,%0.8lX,%d,%0.8lX)",
		x,ExternalHandle,position,buffer,buflen,ecrit);
	ReqTrace((LPSTR)b);

	r = _FFwrite(ExternalHandle,position,buffer,buflen,ecrit);

	fl_xsprintf((LPSTR)b," = %d, ec=%d",r,*ecrit);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI FFextend(ExternalHandle,len)
EHANDLE ExternalHandle;
LSEEKTYPE len;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nFFextend({%0.8lX},%d)",ExternalHandle,len);
	ReqTrace((LPSTR)b);

	r = _FFextend(ExternalHandle,len);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI FFrename(ExternalHandle,NewName)
EHANDLE ExternalHandle;
LPSTR NewName;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nFFrename({%0.8lX},'%s')",ExternalHandle,NewName);
	ReqTrace((LPSTR)b);

	r = _FFrename(ExternalHandle,NewName);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
#ifndef WIN32
	if (r != 0) {
		fl_xsprintf((LPSTR)b,", errno = %d",errno);
        	ReqTrace((LPSTR)b);
	}
#endif
	return(r);
}

EHANDLE WINAPI SQopen(nom,ex,cop,ldata,erreur)
LPSTR nom;
int ex;
int cop;
LPINT ldata;
LPINT erreur;
{ EHANDLE r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQopen('%s',%d,%d,%0.8lX,%0.8lX)",nom,ex,cop,ldata,erreur);
	ReqTrace((LPSTR)b);

	r = _SQopen(nom,ex,cop,ldata,erreur);

	fl_xsprintf((LPSTR)b," = {%0.8lX},%d,%d",r,*ldata,*erreur);
	ReqTrace((LPSTR)b);
	return(r);
}

EHANDLE WINAPI SQcreate(nom,ex,cop,len,erreur)
LPSTR nom;
int ex;
int cop;
int len;
LPINT erreur;
{ EHANDLE r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQcreate('%s',%d,%d,%d,%0.8lX)",nom,ex,cop,len,erreur);
	ReqTrace((LPSTR)b);

	r = _SQcreate(nom,ex,cop,len,erreur);

	fl_xsprintf((LPSTR)b," = {%0.8lX},%d",r,*erreur);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQclose(ExternalHandle)
EHANDLE ExternalHandle;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQclose({%0.8lX})",ExternalHandle);
	ReqTrace((LPSTR)b);

	r = _SQclose(ExternalHandle);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQunlink(nom)
LPSTR nom;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQunlink('%s')",nom);
	ReqTrace((LPSTR)b);

	r = _SQunlink(nom);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQatbopen(ExternalHandle,val,type)
EHANDLE ExternalHandle;
int val;
int type;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQatbopen({%0.8lX},%d,%d)",ExternalHandle,val,type);
	ReqTrace((LPSTR)b);

	r = _SQatbopen(ExternalHandle,val,type);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQread(ExternalHandle,buffer,buflen)
EHANDLE ExternalHandle;
CPTR buffer;
int buflen;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQread({%0.8lX},%0.8lX,%d)",ExternalHandle,buffer,buflen);
	ReqTrace((LPSTR)b);

	r = _SQread(ExternalHandle,buffer,buflen);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQwrite(ExternalHandle,buffer,buflen)
EHANDLE ExternalHandle;
CPTR buffer;
int buflen;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQwrite({%0.8lX},%0.8lX,%d)",ExternalHandle,buffer,buflen);
	ReqTrace((LPSTR)b);

	r = _SQwrite(ExternalHandle,buffer,buflen);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQmodif(ExternalHandle,buffer,buflen)
EHANDLE ExternalHandle;
CPTR buffer;
int buflen;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQmodif({%0.8lX},%0.8lX,%d)",ExternalHandle,buffer,buflen);
	ReqTrace((LPSTR)b);

	r = _SQmodif(ExternalHandle,buffer,buflen);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQrewind(ExternalHandle)
EHANDLE ExternalHandle;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQrewind({%0.8lX})",ExternalHandle);
	ReqTrace((LPSTR)b);

	r = _SQrewind(ExternalHandle);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}

int WINAPI SQrename(ExternalHandle,nom)
EHANDLE ExternalHandle;
LPSTR nom;
{ int r;
  U8 b[128];

	fl_xsprintf((LPSTR)b,"\nSQrename({%0.8lX},'%s'",ExternalHandle,nom);
	ReqTrace((LPSTR)b);

	r = _SQrename(ExternalHandle,nom);

	fl_xsprintf((LPSTR)b," = %d",r);
	ReqTrace((LPSTR)b);
	return(r);
}


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			TRACE DES REQUETES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT ReqTraceBegin
 *
 *	Cree le fichier de trace des requetes AD et SQ.
 *
 *	E/ rien
 *	S/ rien
 *
 */
static void ReqTraceBegin(void)
{
#ifndef __WIN_DEBUG__
  HNLOG TraceFile;
  S16 erreur;

	TraceFile= fl_xcreate((CPTR)"\\flfile.trc",(S16)0,(S16)0,(S16PTR)&erreur);
	if (TraceFile != HNLOG_ERROR)
		{
		fl_xclose(TraceFile);
#ifdef ISUNIX
		liberlox((char *)"\\flfile.trc");
#endif
		}
#endif
}

/* --------------------------------------------------------------------------
 *
 * FCT ReqTrace
 *
 *	Effectue la trace d'une requete AD ou SQ.
 *
 *	E/ pointeur sur le texte de la requete a tracer
 *	S/ rien
 *
 */
static void ReqTrace(Req)
CPTR Req;
{
#ifdef __WIN_DEBUG__
	OutputDebugString(Req);
#else
  HNLOG TraceFile;
  S16 erreur;

	TraceFile = fl_xopen((CPTR)"\\flfile.trc",0,0,(S16PTR)&erreur);

	if (TraceFile != HNLOG_ERROR) {
		(void) fl_xlseek(TraceFile,(LSEEKTYPE)0,SEEK_END);
		(void) fl_xwrite(TraceFile,Req,fl_xstrlen(Req));
		(void) fl_xclose(TraceFile);
#ifdef ISUNIX
		liberlox((char *)"\\flfile.trc");
#endif
		}
#endif
}

#endif /* __DEBUG__ */

