/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic  .			*/
/*									*/
/*		Module  :	EXPROTO.H  				*/
/*		Version :	1.4a / 2.1a				*/
/*		Date 	:	16/01/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXPROTO_H
#define	_EXPROTO_H

#ifdef	ABAL_CRITERIA
#ifndef	OPTIMISEUR
//#BG#include "exadsqcr.h"
#include "pubexma.h"
#endif
#endif

#ifdef PROLOGUE
#include "exproprl.h"
#endif

#ifdef	WIN16
#include "exprow16.h"
#else
#ifdef	WIN32
#include "exprow32.h"
#else
#ifdef	DOS
#include "exprodos.h"
#endif
#endif
#endif

#ifndef UNIX
#ifndef	PROTOTYPE_ARGS
#define	PROTOTYPE_ARGS
#endif
#else	/* UNIX */
#ifdef	USEIT 
#ifndef	PROTOTYPE_ARGS
#define	PROTOTYPE_ARGS
#endif
#else
#ifdef	HPUX
#ifndef	PROTOTYPE_ARGS
#define	PROTOTYPE_ARGS
#endif
#else 
#ifdef	PROTOTYPE_ARGS
#define	PROTOTYPE_ARGS
#endif
#endif
#endif
#endif

#ifdef	PROTOTYPE_ARGS

/*	---------	*/
/*	EXA$(OBJ)	*/
/*	---------	*/

  VOID    TalkWork(VOID);
  VOID    x_newlyne(VOID);
  VOID    itoxxxx(EXAWORD ,BPTR ,EXAWORD);
  VOID    showword(EXAWORD ,EXAWORD);
  VOID    intvisi(EXAWORD );

#ifdef ABAL14 
  VOID	  banner(VOID);
  VOID    eder(EXAWORD);
#else
#ifdef	ABAL21
  VOID	  banner(VOID);
  VOID    eder(EXAWORD);
#else
  EXAWORD banner(VOID);
  EXAWORD eder(EXAWORD,EXAWORD);
#endif
#endif

  EXAWORD AutoMate(VOID);
  EXAWORD arginit(EXAWORD ,BPTR );
  EXAWORD argdefo(EXAWORD );

  BPTR	init_data(EXAWORD ,EXAWORD ,BPTR );
  BPTR	nomlode(EXAWORD ,EXAWORD );
  VOID	lvnomlode(VOID);
  BPTR	kode_lode(EXAWORD ,EXAWORD );
  VOID	fichferm(VOID);
  VOID	exzero(VOID);
  VOID	exlbsm(VOID);
  EXAWORD	init(VOID);
  BPTR	abal_crypt(unsigned short int, BPTR, unsigned short int,unsigned short int);
  EXAWORD	TcodeHeader(EXAWORD,EX_FILE_HANDLE);
  EXAWORD	tkodgo(EXAWORD ,BPTR );
  EXAWORD	exstop(VOID);

/*	------------	*/
/*	EXCALC$(OBJ)	*/
/*	------------	*/

  EXAWORD TempZone(VOID);
  EXAWORD tkodgeti(VOID);
  VOID    xmemcpy(EXAWORD );
  EXAWORD str0fill(VOID);
  VOID    numclean(VOID);
  EXAWORD varconv(EXAWORD );
  EXAWORD varbset1(VOID);
  EXAWORD varbset2(VOID);
  EXAWORD varbsetw(VOID);
  EXAWORD argtyp(EXAWORD );
  EXAWORD argset(EXAWORD ,EXAWORD ,EXAWORD );
  EXAWORD argset1(EXAWORD ,EXAWORD );
  EXAWORD argset2(EXAWORD ,EXAWORD );
  EXAWORD argset3(EXAWORD ,EXAWORD );
  EXAWORD argsetw(EXAWORD ,EXAWORD );
  EXAWORD vputs(EXAWORD ,EXAWORD );
  EXAWORD negwork(EXAWORD ,EXAWORD );
  EXAWORD varcpy(EXAWORD ,EXAWORD ,EXAWORD ,EXAWORD );
  EXAWORD f_pause(EXAWORD );
  EXAWORD compint(EXAWORD ,BINAIRE ,BINAIRE );
  EXAWORD lenuze(BPTR ,EXAWORD );
  BINAIRE usmemcmp(VOID);
  EXAWORD compstr(EXAWORD );
  int     xmemchr(BPTR ,EXABYTE,EXAWORD );
  EXAWORD strcalc(EXAWORD );
  BINAIRE valcon(EXAWORD );
  BINAIRE valtmp(EXAWORD );
  BINAIRE valvar(EXAWORD ,EXAWORD );
  EXAWORD erreurs(VOID);
  EXAWORD trapgest(EXAWORD ,EXAWORD ,EXAWORD, EXAWORD);
  EXAWORD trapwork(EXAWORD );
  EXAWORD getdata(VOID);
  EXAWORD regdata(EXAWORD );
  EXAWORD setdata(EXAWORD );
  VOID    init_timer(VOID);
  VOID    raz_timer(VOID);
  EXAWORD timerwork(VOID);

/*	------------	*/
/*	EXMATH$(OBJ)	*/
/*	------------	*/

  EXAWORD bcdeval(BPTR ,EXAWORD );
  VOID    bcdetd(BPTR,EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXABYTE,EXAWORD);
  EXAWORD bcdcpr(BPTR,BPTR,EXAWORD,EXAWORD,EXAWORD);
  EXAWORD minimaji(EXAWORD);
  VOID    negbcd(BPTR ,EXAWORD );
  BPTR  negbcdcpy(BPTR,EXAWORD);
  EXAWORD itohex(EXAWORD,BPTR,EXAWORD );
  BINAIRE hextoi(BPTR,EXAWORD);
  EXAWORD atobcd(BPTR,BPTR ,EXAWORD ,EXAWORD );
  EXAWORD bcdtoa(BPTR,EXAWORD,BPTR ,EXAWORD );
  BINAIRE atoi(BPTR ,EXAWORD );
  EXAWORD itoa(BINAIRE ,BPTR ,EXAWORD );
  EXAWORD itobcd(BINAIRE ,BPTR ,EXAWORD );
  EXAWORD ltobcd(EXALONG, BPTR ,EXAWORD );
  BINAIRE bcdtoi(BPTR ,EXAWORD );
  EXAWORD conv(EXAWORD ,EXAWORD );
  BPTR  Squeeze(BPTR ,EXAWORD );
  EXAWORD qcomp(EXAWORD ,EXAWORD ,EXAWORD );
  EXAWORD divsub(BPTR ,BPTR ,EXAWORD );
  EXAWORD bcddiv(EXAWORD ,EXAWORD ,EXAWORD );
  VOID    bcdmod(EXAWORD ,EXAWORD );
  EXAWORD xbcdcalc(EXAWORD );
  EXAWORD bcdarr(BPTR,BPTR,EXAWORD,EXAWORD,EXAWORD);
  EXAWORD bcdfix(BPTR,BPTR,EXAWORD,EXAWORD,EXAWORD,EXAWORD);
  EXAWORD bcdint(BPTR,BPTR,EXAWORD,EXAWORD);
  EXAWORD bcddec(BPTR,BPTR,EXAWORD,EXAWORD);
  int     VerifTcode(VOID);

/*	------------	*/
/*	EXCODE$(OBJ)	*/
/*	------------	*/

  EXAWORD keep_segm(EXAWORD);
  EXAWORD rest_segm(VOID);
  EXAWORD whoops(VOID);
  EXAWORD segm_varb(EXAWORD );
  EXAWORD InitialiseSegmentTable(VOID);
  EXAWORD segt_lode(EXAWORD ,EXAWORD);
  EXAWORD seg_find(EXAWORD );
  EXAWORD getdtcur(EXAWORD );
  EXAWORD setdtcur(EXAWORD );
#ifdef	ABAL21
  EXAWORD seg_load(EXAWORD ,BPTR , BPTR, BPTR);
#else
  EXAWORD seg_load(EXAWORD ,BPTR , BPTR );
#endif
  EXAWORD ldgo_seg(EXAWORD ,EXAWORD );
  EXAWORD ret_seg(EXAWORD);
  EXAWORD procarg(EXAWORD );
  EXAWORD pretval(BPTR,EXAWORD);
  EXAWORD cpymrx(EXAWORD ,EXAWORD ,BPTR ,EXAWORD ,EXAWORD );
  BPTR  vtoproc(EXAWORD ,EXAWORD ,BPTR ,BPTR ,EXAWORD,EXAWORD );
#ifdef	ABAL21
  VOID    procabb2(EXAWORD);
#else
  VOID    procabb2(VOID);
#endif
  EXAWORD procabb(EXAWORD );

/*	---------	*/
/*	EXF$(OBJ)	*/
/*	---------	*/

  EXAWORD call_procedure( VOID );
  EXAWORD procedure_exit( EXAWORD );
  EXAWORD load_procedure_table( VOID );
  EXAWORD Digit(VOID);
  EXAWORD bcd2std(BPTR ,EXAWORD ,BPTR ,EXAWORD );
  BINAIRE bcdpower(BPTR ,EXAWORD );
  EXAWORD std2bcd(BPTR ,EXAWORD ,BPTR ,EXAWORD ,BINAIRE );
  EXAWORD excwdir(BPTR ,EXAWORD ,EXAWORD );
  EXAWORD xrename(BPTR ,BPTR );
  EXAWORD exkbfw(VOID);
  EXAWORD exdatw(VOID);
  VOID ll_wait(EXAWORD,EXAWORD);
  EXAWORD x_exec(BPTR ,BPTR,EXAWORD );
  VOID    isave(EXAWORD,EXAWORD);
  EXAWORD xtrans(BPTR ,BPTR ,EXAWORD ,EXAWORD);
  EXAWORD f_clf7(EXAWORD );
  EXAWORD f_clf8(EXAWORD );
  EXAWORD f_clf9(EXAWORD );
  BPTR  Mgetenv(BPTR );
  EXAWORD ExaEnviron(VOID);
  EXAWORD f_clfa(EXAWORD );
  EXAWORD exvarptr(EXAWORD );
  EXAWORD f_clfb(EXAWORD );
  EXAWORD f_clfc(EXAWORD );
  EXAWORD f_clfd(EXAWORD );
  EXAWORD f_clfe(EXAWORD );
  EXAWORD f_clff(EXAWORD );

#ifdef	DOS
  long	  calcsec( VOID );
#endif
 
/*	------------	*/
/*	EXTVARB(OBJ)	*/
/*	------------	*/

  VOID    	 Semaphon(VOID);
  EXAWORD 	 Semaphoff(EXAWORD );
  EXAWORD 	 indent(EXAWORD,BPTR ,EXAWORD ,LSEEKTYPE PTR );
  EXAWORD 	 rawiofunc(EX_FILE_HANDLE ,BPTR ,EXAWORD ,ULONG ,EXAWORD );
  EXAWORD 	 SectRead(EX_FILE_HANDLE ,BPTR ,EXAWORD ,ULONG );
  EXAWORD 	 VmemExtend(EX_FILE_HANDLE ,EXAWORD ,ULONG );
  EXAWORD 	 SectWrite(EX_FILE_HANDLE ,BPTR ,EXAWORD ,ULONG );
  EX_FILE_HANDLE extopen(EXAWORD ,EXAWORD );
  EXAWORD 	 VmemBuffer(EXAWORD );
  EXAWORD 	 extvarb(EXAWORD ,BPTR ,EXAWORD ,EXAWORD );
  EXAWORD 	 extrite(EXAWORD ,BPTR ,EXAWORD ,BPTR );
  BINAIRE 	 x_rand(BINAIRE );
  LSEEKTYPE    	 atol(BPTR ,EXAWORD );
  LSEEKTYPE    	 bcdtol(BPTR ,EXAWORD );
  EXAWORD    	 xferin(BPTR ,EXAWORD,ULONG);
  EXAWORD    	 xferout(BPTR ,EXAWORD ,ULONG );
  EXAWORD 	 allocetd(EXAWORD );
  EXAWORD 	 readhuge(EXAWORD ,BPTR ,EXAWORD ,EXAWORD );
  BPTR  	 ExtendedMemoryInit( EXAWORD , BPTR );

/*	-----------	*/
/*	EXNGF$(OBJ)	*/
/*	-----------	*/

  VOID    traitfilerror(EXAWORD , int );
  VOID    simcprep(EXAWORD );
  EXAWORD fargset(EXAWORD );
  EXAWORD largset(EXAWORD );
  EXAWORD si_prep(EXAWORD );
  EXAWORD set_file_name(VOID);
  VOID    VmemLiberate(VOID);
  EXAWORD sf_close(VOID);
  EXAWORD razfich(EXAWORD );
  VOID    freefich(VOID);
  EXAWORD f_chgt(VOID);
  EXAWORD f_chain(VOID);
  EXAWORD sf_open(VOID);
  EXAWORD loadfich(VOID);
  EXAWORD savefich(VOID);
  EXAWORD sf_ass(VOID);
  EXAWORD sf_find(VOID);
  EXAWORD ngf_infos(VOID);
  EXAWORD sf_ngf(VOID);
  EXAWORD check_valid_assign_handle( EXAWORD );
  EXAWORD check_integer_assign_handle( EXAWORD );
  VOID close_base_files(EXAWORD);
  EXAWORD fn_parser(BPTR,BPTR,EXAWORD);
  EXAWORD AnalyseTCodeFileName(BPTR,BPTR);
  EXAWORD creat(BPTR,EXAWORD);
  EXAWORD remove_bd_record(EXAWORD,EXAWORD);
  EX_PRINTER_HANDLE printer_open( BPTR, EXAWORD );

/*	----------	*/
/*	EXSQ$(OBJ)	*/
/*	----------	*/

  EXAWORD sq_ctrl(EXAWORD ,EXAWORD );
  EXAWORD sq_posit(EXAWORD ,long );
  EXAWORD sq_open(BPTR ,EXAWORD );
  EXAWORD sq_close(EXAWORD );
  EXAWORD sq_creat(BPTR ,EXAWORD ,EXAWORD );
  EXAWORD sq_read(EXAWORD ,BPTR ,EXAWORD );
  EXAWORD sq_write(EXAWORD ,BPTR ,EXAWORD );
  EXAWORD sq_modif(EXAWORD ,BPTR ,EXAWORD );
  EXAWORD sq_rewind(EXAWORD );
  EXAWORD sq_func(EXAWORD ,BPTR ,EXAWORD ,EXAWORD );

/*	----------	*/
/*	EXMC$(OBJ)	*/
/*	----------	*/
  EXAWORD rubshift(BPTR ,BPTR ,EXAWORD, EXABYTE );
  EXAWORD addrubr(EXAWORD ,EXAWORD ,EXAWORD ,EXAWORD );
  EXAWORD addrubr_auto(BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD);
  EXAWORD rubrdcl(VOID);
  EXAWORD rubrdef(VOID);
  EXAWORD rubrseek(BPTR ,EXAWORD ,BPTR ,EXAWORD );
  EXAWORD rubrctrl(BPTR ,EXAWORD );
  EXAWORD rubrfld(VOID);
  EXAWORD rubrraz(VOID);
  EXAWORD rubrnom(VOID);
  EXAWORD rubrlst(EXAWORD ,EXAWORD );
  EXAWORD setjoin(EXAWORD );
  EXAWORD linkwork(EXAWORD ,EXAWORD );
  EXAWORD mcQtoken(EXAWORD );
  EXAWORD questprep(EXAWORD );
  EXAWORD intero(EXAWORD ,EXAWORD );

/*	----------	*/
/*	EXBD$(OBJ)	*/
/*	----------	*/

  VOID    basefile(EXAWORD );
  EXAWORD makebase(VOID);
  VOID    effrecord(VOID);
  EXAWORD bdrecord(VOID);
  EXAWORD dcljoin(VOID);
  EXAWORD makejoin(VOID);
  EXAWORD suprjoin(VOID);
  EXAWORD namejoin(VOID);
  EXAWORD bd_prep(VOID);

/*	--------------	    ----------	*/
/*	EXFLOPPY$(OBJ)	||  EXSF$(OBJ)	*/
/*	--------------	    ----------	*/
  EXAWORD io_open(BPTR);
  EXAWORD io_func(EXAWORD,EXAWORD,BPTR,EXAWORD,long);


/*	------------	*/
/*	EXFUSE$(OBJ)	*/
/*	------------	*/
/*  EXAWORD fuargset(EXAWORD);
  EXAWORD LibFuse(struct fusework PTR,EXAWORD);
  EXAWORD InitFuse(VOID);
  EXAWORD FuseChck(BPTR ,BPTR);
  EXAWORD MergeFuse(VOID);
#ifdef	ABAL21
  EXAWORD DoFuse(EXAWORD);
#else
  EXAWORD DoFuse(VOID);
#endif
*/

/*	----------	*/
/*	EXIO$(OBJ)	*/
/*	----------	*/
  EXAWORD iof_format_string(BPTR, EXAWORD);
  EXAWORD AskInfos(EXAWORD);
  VOID    x_clear(VOID);
  BPTR  abalfmt(BPTR);
  EXAWORD atofmt(BPTR, EXAWORD, BPTR, EXAWORD);
  VOID    lsyskey(VOID);
  VOID    askvisi(EXABYTE);
  EXAWORD fmtact(EXAWORD );
  VOID    envstr(EXAWORD );
  VOID    iform(EXAWORD);
  VOID    uform(EXAWORD, EXAWORD );
  VOID    envnum(EXAWORD );
  VOID    askbak(VOID);
  EXAWORD sf_atb(EXAWORD );
  EXAWORD sf_fmt(EXAWORD );
  EXAWORD istext(EXABYTE);
  EXAWORD issign(EXABYTE);
  EXAWORD ischiff(EXABYTE);
  EXAWORD iscode(EXABYTE);
  EXAWORD isvirg(EXABYTE);
  EXAWORD kodchk(EXABYTE);
  EXAWORD sf_paint(EXAWORD );
  EXAWORD sf_dev(EXAWORD );
  VOID cleol(VOID);
  EXAWORD fmtverif(EXAWORD );
  EXAWORD fmtotal(EXAWORD );
  EXAWORD askout(EXAWORD, EXAWORD );
  EXAWORD errsaut(VOID);
  VOID bufwipe(VOID);
  EXAWORD hotkey(EXAWORD );
  EXAWORD sf_spex(EXAWORD, EXAWORD );
  EXAWORD init_saut(EXAWORD, EXAWORD );
  EXAWORD chkfmt(EXABYTE );
  VOID    fmtbass(EXAWORD );
  VOID    as_fmt(EXAWORD );
  VOID    pr_fmt(EXAWORD );
  EXAWORD bufend(int);
  EXAWORD maskwork(VOID);
  EXAWORD bufgest(EXABYTE );
  EXAWORD seekfin(EXAWORD);
  EXAWORD ll_ask(EXAWORD );
  VOID vshift(VOID);
  EXAWORD sf_ask(EXAWORD );
  VOID signshow(EXAWORD );
  EXAWORD ngestfmt(VOID);
  EXAWORD nbcddig(VOID);
  VOID visihfill(EXAWORD);
  VOID visihead(EXAWORD, EXAWORD );
  VOID visitail(EXAWORD, EXAWORD );
  EXAWORD numfmt(VOID);
  EXAWORD sf_print(EXAWORD);
  EXAWORD iowork(VOID);

/*	-------------	*/
/*	EXMOTOR$(OBJ)	*/
/*	-------------	*/
	EXAWORD llmotor( VOID );
	EXAWORD motor( VOID );

  VOID    prnclear(VOID);
#ifndef PROLOGUE
  EXAWORD x_npos( VOID );
#endif

/*	----------	*/
/*	EXMA     	*/
/*	----------	*/
//#BG 22/11/11
int	MA_init(void);
void	MA_fin(void);

/*	----------	*/
/*	EXSF$(OBJ)	*/
/*	----------	*/

#ifndef UNIX
#ifndef VMS
//#BG 22/11/11VOID    	si_fin(VOID);
EX_FILE_HANDLE	si_open(BPTR, EXAWORD, EXAWORD);
EXAWORD		si_matb(EX_FILE_HANDLE, EXAWORD);
EXAWORD		si_close(EX_FILE_HANDLE);
EX_FILE_HANDLE	si_create(BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD);
EXAWORD		si_unlink(BPTR, EXAWORD, EXAWORD);
EXAWORD		si_rename(BPTR, BPTR);
EXAWORD		si_up(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXAWORD, BPTR, EXAWORD);
EXAWORD		si_down(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXAWORD, BPTR, EXAWORD);
EXAWORD		si_insert(EX_FILE_HANDLE, BPTR, EXAWORD, BPTR, EXAWORD);
EXAWORD		si_modif(EX_FILE_HANDLE, BPTR, EXAWORD, BPTR, EXAWORD);
EXAWORD		si_search(EX_FILE_HANDLE, EXAWORD, EXAWORD, BPTR, EXAWORD, BPTR, EXAWORD);
EXAWORD		si_delete(EX_FILE_HANDLE, BPTR, EXAWORD);
EXAWORD		si_readzc(EX_FILE_HANDLE, EXAWORD, BPTR, EXAWORD);
EXAWORD		si_writezc(EX_FILE_HANDLE, BPTR, EXAWORD);
#endif
#endif

#ifndef DOS
#ifndef PROLOGUE
int    	si_open(char *,int,int);
int    	si_matb(int,int,int);
int    	si_close(int);
int    	si_create(char *,int,int,int,int,int,int);
int    	si_unlink(char *);
int    	si_rename(char *,char *);
int    	si_up(int,int,int,int,char *,int);
int    	si_down(int,int,int,int,char *,int);
int    	si_insert(int,char *,int,char *,int);
int    	si_modif(int,char *,int,char *,int);
int    	si_search(int,int,int,char *,int,char *,int);
int    	si_delete(int,char *,int);
int    	si_readzc(int,int,char *,char *,int);
int    	si_writezc(int,char *,char *, int);
#endif
#endif

EXAWORD			ngf_rename(BPTR, EXAWORD, EXAWORD);
EXAWORD			frsplit(BPTR);
#ifdef PROLOGUE
EX_PRINTER_HANDLE	im_open(BPTR, EXAWORD, EXAWORD);
#else
EX_PRINTER_HANDLE	im_open(BPTR, EXAWORD);
#endif
EXAWORD			im_close(EX_PRINTER_HANDLE);
EXAWORD			extend(EX_FILE_HANDLE, EXAWORD);
EXAWORD			GetSousRep(BPTR, EXAWORD);
EXAWORD			prlvolif(BPTR,EXAWORD, EXAWORD);
EXALONG			mc_key(EX_FILE_HANDLE, EXAWORD, BPTR, EXAWORD, EXAWORD, EXAWORD);
EXAWORD 		prep(EXAWORD, EXAWORD, BPTR, EXAWORD);
EXAWORD			anajoin(BPTR, BPTR ,EXAWORD);
EXAWORD			killjoin(BPTR);

/*	-------------	*/
/*	EXMMBIB$(OBJ)	*/
/*	-------------	*/
VPTR	Qalloc( EXAWORD );
void	Qfree( BPTR );
VPTR	Mmalloc( unsigned int );
VPTR	Mcalloc( unsigned int, unsigned int );
VOID	Mfree( VPTR );
#ifndef WIN32
VPTR	malloc( unsigned int );
VPTR	calloc( unsigned int, unsigned int );
VOID	free( VPTR );
#endif
#ifdef AIX_VERS
#ifndef UNIXWARE
#endif /* AIX_VERS */
VPTR	Mmemcpy( VPTR, VPTR, unsigned int );
BPTR	Mstrcpy( BPTR, BPTR );
VPTR	Mmemset( VPTR, unsigned int, unsigned int );
unsigned int Mstrlen( BPTR );
#ifdef AIX_VERS
#endif
#endif /* AIX_VERS */
#ifndef	ABAL_RTL
EXAWORD	lenuse( BPTR, EXAWORD );
#endif
EXAWORD	isincl( VOID );
#ifndef	ABAL_CRITERIA
EXAWORD	unlink( BPTR );
#endif
#ifdef UNIX
EXAWORD	matb(BPTR, EXAWORD, EXAWORD, EXAWORD);
#else
EXAWORD	matb(EX_FILE_HANDLE, EXAWORD, EXAWORD, EXAWORD);
#endif
#ifdef UNIX
#ifndef	USEIT
#ifndef	HPUX
long	lseek(int,long,int);
int	read(int,char *,int);
int	write(int,char *,int);
int	open(char *,int,int);
int	create(char *,int);
int	close(int);
#endif
#endif
#else
#ifndef	USEIT
EXALONG		lseek(EX_FILE_HANDLE, EXALONG, int);
EXALONG		read(EX_FILE_HANDLE, BPTR, int);
EXAWORD		write(EX_FILE_HANDLE, BPTR, int);
EX_FILE_HANDLE	open(BPTR, EXAWORD);
EX_FILE_HANDLE	create(BPTR, EXAWORD);
EXAWORD		close(EX_FILE_HANDLE);
#endif
#endif

#ifdef UNIX
int    	Access(char *,int  ,int    );
#else
EXAWORD	Access(BPTR, EXAWORD, EXAWORD);
#endif
EXAWORD	dir_seek(BPTR, EXAWORD, BPTR, EXAWORD, EXAWORD);
EXAWORD	VerifPtr(BPTR);
VOID	ExaDmex( VOID );
VOID	ExaFmex( VOID );
VOID	PrlDate8(BPTR, EXAWORD);

/*	-----------	*/
/*	EXBCD$(OBJ)	*/
/*	-----------	*/
EXAWORD	bcdcalc( EXAWORD );
EXAWORD	bcdcomp( EXAWORD );
BINAIRE	isequalit( VOID );
VOID	clf_left( VOID );
VOID	clf_right( VOID );
VOID	clf_move( VOID );
VOID	clf_substr( VOID );
VOID	clf_shr( VOID );
VOID	clf_shl( VOID );
VOID	clf_inv( VOID );
VOID	clf_large( VOID );
VOID	clf_small( VOID );
VOID	clf_gener( VOID );
VOID	clf_space( VOID );
VOID	clf_chr( VOID );

#ifdef	DOS

VOID	Trap24( VOID );
VOID	UnTrap24( VOID );
VOID	dos_arto( VOID );

#endif


/*	------------	*/
/*	EXAPRL$(LIB)	*/
/*	------------	*/

#ifdef 	PROLOGUE
BPTR	cgets( BPTR );
VOID	arto( BPTR );
VOID	drto( BPTR );
VOID	wait( BPTR  );
EXAWORD	npos( VOID );
EXAWORD	Chargeur(BPTR, BPTR);
EXAWORD	ExecGo(BPTR, BPTR);
EXAWORD 	DisCharge(BPTR);
EXAWORD	renfile(EX_FILE_HANDLE, BPTR);
EXAWORD	check33( VOID );
#endif

EXAWORD	date( EXAWORD );
EXAWORD mdate( EXAWORD, EXAWORD, EXAWORD );
EXAWORD mtime( EXAWORD, EXAWORD, EXAWORD );
EXAWORD fulltime(BPTR, EXAWORD);

	/* ----- */
#else	/* !UNIX */
	/* ----- */

/*	---------	*/
/*	EXA$(OBJ)	*/
/*	---------	*/

  VOID    TalkWork();	/* VOID	*/
  VOID    x_newlyne();	/* VOID	*/
  VOID    itoxxxx();	/* EXAWORD ,BPTR ,EXAWORD	*/
  VOID    showword();	/* EXAWORD ,EXAWORD	*/
  VOID    intvisi();	/* EXAWORD 	*/
#ifdef ABAL14
  VOID    banner();	/* VOID	*/
  VOID    eder();	/* EXAWORD ,EXAWORD 	*/
#else
  EXAWORD banner();
  EXAWORD eder();
#endif
  EXAWORD AutoMate();	/* VOID	*/
  EXAWORD arginit();	/* EXAWORD ,BPTR 	*/
  EXAWORD argdefo();	/* EXAWORD 	*/

  BPTR  init_data();	/* EXAWORD ,EXAWORD ,BPTR 	*/
  BPTR	nomlode();	/* EXAWORD ,EXAWORD 	*/
  VOID  lvnomlode();	/* VOID	*/
  BPTR  kode_lode();	/* EXAWORD ,EXAWORD 	*/
  VOID  fichferm();	/* VOID	*/
  VOID  exzero();	/* VOID	*/
  VOID  exlbsm();	/* VOID	*/
  EXAWORD  init();	/* VOID	*/
  BPTR  abal_crypt();	/* unsigned short int ,BPTR ,unsigned short int ,unsigned short int 	*/
#ifndef	HPUX
  long  lseek();	/* EXAWORD ,long ,EXAWORD 	*/
#endif
  EXAWORD  TcodeHeader();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD  tkodgo();	/* EXAWORD ,BPTR 	*/
  EXAWORD  exstop();	/* VOID	*/

/*	------------	*/
/*	EXCALC$(OBJ)	*/
/*	------------	*/

  EXAWORD TempZone();	/* VOID	*/
  EXAWORD tkodgeti();	/* VOID	*/
  VOID xmemcpy();	/* EXAWORD 	*/
  EXAWORD str0fill();	/* VOID	*/
  VOID numclean();	/* VOID	*/
  EXAWORD varconv();	/* EXAWORD 	*/
  EXAWORD varbset1();	/* VOID	*/
  EXAWORD varbset2();	/* VOID	*/
  EXAWORD varbsetw();	/* VOID	*/
  EXAWORD argtyp();	/* EXAWORD 	*/
  EXAWORD argset();	/* EXAWORD ,EXAWORD ,EXAWORD 	*/
  EXAWORD argset1();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD argset2();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD argset3();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD argsetw();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD vputs();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD negwork();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD varcpy();	/* EXAWORD ,EXAWORD ,EXAWORD ,EXAWORD 	*/
  EXAWORD f_pause();	/* EXAWORD 	*/
  EXAWORD compint();	/* EXAWORD ,BINAIRE ,BINAIRE 	*/
  EXAWORD lenuze();	/* BPTR ,EXAWORD 	*/
  BINAIRE usmemcmp();	/* VOID	*/
  EXAWORD compstr();	/* EXAWORD 	*/
  int  xmemchr();	/* BPTR ,EXABYTE,EXAWORD 	*/
  EXAWORD strcalc();	/* EXAWORD 	*/
  BINAIRE valcon();	/* EXAWORD 	*/
  BINAIRE valtmp();	/* EXAWORD 	*/
  BINAIRE valvar();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD erreurs();	/* VOID	*/
  EXAWORD trapgest();	/* EXAWORD ,EXAWORD ,EXAWORD , EXAWORD */
  EXAWORD trapwork();	/* EXAWORD 	*/
  EXAWORD getdata();	/* VOID	*/
  EXAWORD regdata();	/* EXAWORD 	*/
  EXAWORD setdata();	/* EXAWORD 	*/
  VOID init_timer();	/* VOID	*/
  VOID raz_timer();	/* VOID	*/
  EXAWORD timerwork();	/* VOID	*/

/*	------------	*/
/*	EXMATH$(OBJ)	*/
/*	------------	*/

  EXAWORD bcdeval();	/* BPTR ,EXAWORD 	*/
  VOID bcdetd();	/* BPTR,EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXABYTE,EXAWORD	*/
  EXAWORD bcdcpr();	/* BPTR,BPTR,EXAWORD,EXAWORD,EXAWORD	*/
  EXAWORD minimaji();	/* EXAWORD	*/
  VOID negbcd();	/* BPTR ,EXAWORD 	*/
  BPTR negbcdcpy();	/* BPTR,EXAWORD	*/
  EXAWORD itohex();	/* EXAWORD,BPTR,EXAWORD 	*/
  BINAIRE hextoi();	/* BPTR,EXAWORD	*/
  EXAWORD atobcd();	/* BPTR,BPTR ,EXAWORD ,EXAWORD 	*/
  EXAWORD bcdtoa();	/* BPTR,EXAWORD,BPTR ,EXAWORD 	*/
  BINAIRE atoi();	/* BPTR ,EXAWORD 	*/
  EXAWORD itoa();	/* BINAIRE ,BPTR ,EXAWORD 	*/
  EXAWORD itobcd();	/* BINAIRE ,BPTR ,EXAWORD 	*/
  EXAWORD ltobcd();	/* BPTR ,EXAWORD , long	*/
  BINAIRE bcdtoi();	/* BPTR ,EXAWORD 	*/
  EXAWORD conv();	/* EXAWORD ,EXAWORD 	*/
  BPTR Squeeze();	/* BPTR ,EXAWORD 	*/
  EXAWORD qcomp();	/* EXAWORD ,EXAWORD ,EXAWORD 	*/
  EXAWORD divsub();	/* BPTR ,BPTR ,EXAWORD 	*/
  EXAWORD bcddiv();	/* EXAWORD ,EXAWORD ,EXAWORD 	*/
  VOID bcdmod();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD xbcdcalc();	/* EXAWORD 	*/
  EXAWORD bcdarr();	/* BPTR,BPTR,EXAWORD,EXAWORD,EXAWORD	*/
  EXAWORD bcdfix();	/* BPTR,BPTR,EXAWORD,EXAWORD,EXAWORD,EXAWORD	*/
  EXAWORD bcdint();	/* BPTR,BPTR,EXAWORD,EXAWORD	*/
  EXAWORD bcddec();	/* BPTR,BPTR,EXAWORD,EXAWORD	*/
  int  VerifTcode();	/* VOID	*/

/*	------------	*/
/*	EXCODE$(OBJ)	*/
/*	------------	*/

  EXAWORD keep_segm();	/* EXAWORD	*/
  EXAWORD rest_segm();	/* VOID	*/
  EXAWORD whoops();	/* VOID	*/
  EXAWORD segm_varb();	/* EXAWORD 	*/
  EXAWORD InitialiseSegmentTable();	/* VOID	*/
  EXAWORD segt_lode();	/* EXAWORD ,EXAWORD	*/
  EXAWORD seg_find();	/* EXAWORD 	*/
  EXAWORD getdtcur();	/* EXAWORD 	*/
  EXAWORD setdtcur();	/* EXAWORD 	*/
  EXAWORD seg_load();	/* EXAWORD 	*/
  EXAWORD ldgo_seg();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD ret_seg();	/* EXAWORD */
  EXAWORD procarg();	/* EXAWORD 	*/
  EXAWORD pretval();	/* BPTR,EXAWORD	*/
  EXAWORD cpymrx();	/* EXAWORD ,EXAWORD ,BPTR ,EXAWORD ,EXAWORD 	*/
  BPTR vtoproc();	/* EXAWORD ,EXAWORD ,BPTR ,BPTR ,EXAWORD 	*/
  VOID procabb2();	/* VOID	*/
  EXAWORD procabb();	/* EXAWORD 	*/

/*	---------	*/
/*	EXF$(OBJ)	*/
/*	---------	*/

  EXAWORD call_procedure(); /* VOID */
  EXAWORD procedure_exit(); /* EXAWORD */
  EXAWORD load_procedure_table(); /* VOID */
  EXAWORD Digit();	/* VOID	*/
  EXAWORD bcd2std();	/* BPTR ,EXAWORD ,BPTR ,EXAWORD 	*/
  BINAIRE bcdpower();	/* BPTR ,EXAWORD 	*/
  EXAWORD std2bcd();	/* BPTR ,EXAWORD ,BPTR ,EXAWORD ,BINAIRE 	*/
  EXAWORD excwdir();	/* BPTR ,EXAWORD ,EXAWORD 	*/
  EXAWORD xrename();	/* BPTR ,BPTR 	*/
  EXAWORD exkbfw();	/* VOID	*/
  EXAWORD exdatw();	/* VOID	*/
  VOID    ll_wait();	/* EXAWORD 	*/
  EXAWORD x_exec();	/* BPTR ,BPTR 	*/
  VOID    isave();	/* EXAWORD,EXAWORD	*/
  EXAWORD xtrans();	/* BPTR ,BPTR ,EXAWORD ,EXAWORD	*/
  EXAWORD f_clf7();	/* EXAWORD 	*/
  EXAWORD f_clf8();	/* EXAWORD 	*/
  EXAWORD f_clf9();	/* EXAWORD 	*/
  BPTR  Mgetenv();	/* BPTR 	*/
  EXAWORD ExaEnviron();	/* VOID	*/
  EXAWORD f_clfa();	/* EXAWORD 	*/
  EXAWORD exvarptr();	/* EXAWORD 	*/
  EXAWORD f_clfb();	/* EXAWORD 	*/
  EXAWORD f_clfc();	/* EXAWORD 	*/
  EXAWORD f_clfd();	/* EXAWORD 	*/
  EXAWORD f_clfe();	/* EXAWORD 	*/
  EXAWORD f_clff();	/* EXAWORD 	*/

#ifdef	DOS
  long	  calcsec();	/*  VOID 	*/
#endif
 
/*	------------	*/
/*	EXTVARB$(OBJ)	*/
/*	------------	*/

  VOID    Semaphon();	/* VOID	*/
  EXAWORD Semaphoff();	/* EXAWORD 	*/
  EXAWORD indent();	/* EXAWORD,BPTR ,EXAWORD ,LPTR 	*/
  EXAWORD rawiofunc();	/* EXAWORD ,BPTR ,EXAWORD ,ULONG ,EXAWORD 	*/
  EXAWORD SectRead();	/* EXAWORD ,VPTR ,EXAWORD ,ULONG 	*/
  EXAWORD VmemExtend();	/* EXAWORD ,EXAWORD ,ULONG 	*/
  EXAWORD SectWrite();	/* EXAWORD ,BPTR ,EXAWORD ,ULONG 	*/
  EX_FILE_HANDLE extopen();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD VmemBuffer();	/* EXAWORD 	*/
  EXAWORD extvarb();	/* EXAWORD ,BPTR ,EXAWORD ,EXAWORD 	*/
  EXAWORD extrite();	/* EXAWORD ,BPTR ,EXAWORD ,BPTR 	*/
  BINAIRE x_rand();	/* BINAIRE 	*/
  LSEEKTYPE    atol();	/* BPTR ,EXAWORD 	*/
  LSEEKTYPE    bcdtol();	/* BPTR ,EXAWORD 	*/
  EXAWORD    xferin();	/* BPTR ,EXAWORD,ULONG	*/
  EXAWORD    xferout();	/* BPTR ,EXAWORD ,ULONG 	*/
  EXAWORD	 allocetd();	/* EXAWORD 	*/
  EXAWORD readhuge();	/* EXAWORD ,BPTR ,EXAWORD ,EXAWORD 	*/
  BPTR  ExtendedMemoryInit(); /* EXAWORD , BPTR 		*/

/*	-----------	*/
/*	EXNGF$(OBJ)	*/
/*	-----------	*/

  VOID    traitfilerror();	/* EXAWORD , int */
  VOID    simcprep();	/* EXAWORD */
  EXAWORD fargset();	/* EXAWORD */
  EXAWORD largset( );	/* EXAWORD */
  EXAWORD si_prep( );	/* EXAWORD */
  EXAWORD set_file_name();	/* VOID */
  VOID    VmemLiberate();	/* VOID */
  EXAWORD sf_close();	/* VOID */
  EXAWORD razfich( );	/* EXAWORD */
  VOID    freefich();	/* VOID */
  EXAWORD f_chgt();	/* VOID */
  EXAWORD f_chain();	/* VOID */
  EXAWORD sf_open();	/* VOID */
  EXAWORD loadfich();	/* VOID */
  EXAWORD savefich();	/* VOID */
  EXAWORD sf_ass();	/* VOID */
  EXAWORD sf_find(VOI;	/* VOID */
  EXAWORD ngf_infos();	/* VOID */
  EXAWORD sf_ngf();	/* VOID */
  EXAWORD check_valid_assign_handle(  );	/* EXAWORD */
  EXAWORD check_integer_assign_handle(  );	/* EXAWORD */
  VOID close_base_files();	/* EXAWORD */
  EXAWORD fn_parser();	/* BPTR,BPTR,EXAWORD */
  EXAWORD AnalyseTCodeFileName();	/* BPTR,BPTR */
  EXAWORD creat();	/* BPTR,EXAWORD */
  EXAWORD remove_bd_record();	/* EXAWORD,EXAWORD */
  EX_PRINTER_HANDLE printer_open();	/* BPTR, EXAWORD */

/*	----------	*/
/*	EXSQ$(OBJ)	*/
/*	----------	*/

  EXAWORD sq_ctrl();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD sq_posit();	/* EXAWORD ,long 	*/
  EXAWORD sq_open();	/* BPTR ,EXAWORD 	*/
  EXAWORD sq_close();	/* EXAWORD 	*/
  EXAWORD sq_creat();	/* BPTR ,EXAWORD ,EXAWORD 	*/
  EXAWORD sq_read();	/* EXAWORD ,BPTR ,EXAWORD 	*/
  EXAWORD sq_write();	/* EXAWORD ,BPTR ,EXAWORD 	*/
  EXAWORD sq_modif();	/* EXAWORD ,BPTR ,EXAWORD 	*/
  EXAWORD sq_rewind();	/* EXAWORD 	*/
  EXAWORD sq_func();	/* EXAWORD ,BPTR ,EXAWORD ,EXAWORD 	*/

/*	----------	*/
/*	EXMC$(OBJ)	*/
/*	----------	*/
  EXAWORD rubshift();	/* BPTR ,BPTR ,EXAWORD 	*/
  EXAWORD addrubr();	/* EXAWORD ,EXAWORD ,EXAWORD ,EXAWORD 	*/
  EXAWORD addrubr_auto();	/* BPTR, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD, EXAWORD	*/
  EXAWORD rubrdcl();	/* VOID	*/
  EXAWORD rubrdef();	/* VOID	*/
  EXAWORD rubrseek();	/* BPTR ,EXAWORD ,BPTR ,EXAWORD 	*/
  EXAWORD rubrctrl();	/* BPTR ,EXAWORD 	*/
  EXAWORD rubrfld();	/* VOID	*/
  EXAWORD rubrraz();	/* VOID	*/
  EXAWORD rubrnom();	/* VOID	*/
  EXAWORD rubrlst();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD setjoin();	/* EXAWORD 	*/
  EXAWORD linkwork();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD mcQtoken();	/* EXAWORD 	*/
  EXAWORD questprep();	/* EXAWORD 	*/
  EXAWORD intero();	/* EXAWORD ,EXAWORD 	*/

/*	----------	*/
/*	EXBD$(OBJ)	*/
/*	----------	*/

  VOID    basefile();	/* EXAWORD 	*/
  EXAWORD makebase();	/* VOID	*/
  VOID    effrecord();	/* VOID	*/
  EXAWORD bdrecord();	/* VOID	*/
  EXAWORD dcljoin();	/* VOID	*/
  EXAWORD makejoin();	/* VOID	*/
  EXAWORD suprjoin();	/* VOID	*/
  EXAWORD namejoin();	/* VOID	*/
  EXAWORD bd_prep();	/* VOID	*/

/*	--------------	    ----------	*/
/*	EXFLOPPY$(OBJ)	||  EXSF$(OBJ)	*/
/*	--------------	    ----------	*/
  EXAWORD io_open();	/* BPTR	*/
  EXAWORD io_func();	/* EXAWORD,EXAWORD,BPTR,EXAWORD,long	*/


/*	------------	*/
/*	EXFUSE$(OBJ)	*/
/*	------------	*/
  EXAWORD fuargset();	/* EXAWORD	*/
  EXAWORD LibFuse();	/* EXAWORD	*/
  EXAWORD InitFuse();	/* VOID	*/
  EXAWORD FuseChck();	/* BPTR ,BPTR	*/
  EXAWORD MergeFuse();	/* VOID	*/
#ifdef	ABAL21
  EXAWORD DoFuse();	/* EXAWORD		*/
#else
  EXAWORD DoFuse();	/* VOID			*/
#endif

/*	----------	*/
/*	EXIO$(OBJ)	*/
/*	----------	*/
  EXAWORD iof_format_string();	/* BPTR, EXAWORD */
  EXAWORD AskInfos();	/* EXAWORD	*/
  VOID    x_clear();	/* VOID	*/
  BPTR  abalfmt();	/* BPTR	*/
  EXAWORD atofmt();	/* BPTR,EXAWORD,BPTR,EXAWORD	*/
  VOID    lsyskey();	/* VOID	*/
  VOID    askvisi();	/* EXABYTE	*/
  EXAWORD fmtact();	/* EXAWORD 	*/
  VOID    envstr();	/* EXAWORD 	*/
  VOID    iform();	/* EXAWORD	*/
  VOID    uform();	/* EXAWORD ,EXAWORD 	*/
  VOID    envnum();	/* EXAWORD 	*/
  VOID    askbak();	/* VOID	*/
  EXAWORD sf_atb();	/* EXAWORD 	*/
  EXAWORD sf_fmt();	/* EXAWORD 	*/
  EXAWORD istext();	/* EXABYTE	*/
  EXAWORD issign();	/* EXABYTE	*/
  EXAWORD ischiff();	/* EXABYTE	*/
  EXAWORD iscode();	/* EXABYTE	*/
  EXAWORD isvirg();	/* EXABYTE	*/
  EXAWORD kodchk();	/* EXABYTE	*/
  EXAWORD sf_paint();	/* EXAWORD 	*/
  EXAWORD sf_dev();	/* EXAWORD 	*/
  VOID    cleol();	/* VOID	*/
  EXAWORD fmtverif();	/* EXAWORD 	*/
  EXAWORD fmtotal();	/* EXAWORD 	*/
  EXAWORD askout();	/* EXAWORD 	*/
  EXAWORD errsaut();	/* VOID	*/
  VOID    bufwipe();	/* VOID	*/
  EXAWORD hotkey();	/* EXAWORD 	*/
  EXAWORD sf_spex();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD init_saut();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD chkfmt();	/* EXABYTE 	*/
  VOID    fmtbass();	/* EXAWORD 	*/
  VOID    as_fmt();	/* EXAWORD 	*/
  VOID    pr_fmt();	/* EXAWORD 	*/
  EXAWORD bufend();	/* VOID	*/
  EXAWORD maskwork();	/* VOID	*/
  EXAWORD bufgest();	/* EXABYTE 	*/
  EXAWORD seekfin();	/* VOID	*/
  EXAWORD ll_ask();	/* EXAWORD 	*/
  VOID    vshift();	/* VOID	*/
  EXAWORD sf_ask();	/* EXAWORD 	*/
  VOID    signshow();	/* EXAWORD 	*/
  EXAWORD ngestfmt();	/* VOID	*/
  EXAWORD nbcddig();	/* VOID	*/
  VOID    visihfill();	/* EXAWORD	*/
  VOID    visihead();	/* EXAWORD,EXAWORD 	*/
  VOID    visitail();	/* EXAWORD ,EXAWORD 	*/
  EXAWORD numfmt();	/* VOID	*/
  EXAWORD sf_print();	/* EXAWORD	*/
  EXAWORD iowork();	/* VOID	*/

/*	-------------	*/
/*	EXMOTOR$(OBJ)	*/
/*	-------------	*/
	EXAWORD llmotor();	/*  VOID 	*/
	EXAWORD motor();	/*  VOID 	*/

/*	------------	*/
/*	EXCICO$(OBJ)	*/
/*	------------	*/

  VOID    x_putch();	/* EXAWORD	*/
  VOID    prnclear();	/* VOID	*/
  EXAWORD x_col();	/* VOID	*/
  EXAWORD x_lin();	/* VOID	*/
  VOID    pos();        /* EXAWORD,EXAWORD */
  VOID    atb();        /* EXAWORD */
  EXAWORD x_getch();	/*  VOID 	*/
  EXAWORD opb();	/*  VOID 	*/
  VOID    x_cprintf();	/*  BPTR 	*/
  VOID	  x_bell();	/*  VOID 	*/
  VOID	  x_bstart();	/*  VOID 	*/
  VOID 	  x_bflush();	/*  VOID 	*/
#ifndef PROLOGUE
  EXAWORD x_npos();	/*  VOID 	*/
#endif
  EXAWORD prfo();	/*  EXAWORD , BPTR , EXAWORD 	*/
  EXAWORD lcfo();	/*  EXAWORD , BPTR , EXAWORD 	*/
  EXAWORD x_kbhit();	/*  VOID 	*/		
  EXAWORD conf();	/*  EXAWORD 	*/
  

/*	----------	*/
/*	EXMA     	*/
/*	----------	*/

int	MA_init();
void	MA_fin();

/*	----------	*/
/*	EXSF$(OBJ)	*/
/*	----------	*/

#ifndef UNIX
#ifndef VMS
//#BG 22/11/11	VOID    si_fin();	/* VOID	*/
EXAWORD	si_open();	/* BPTR,EXAWORD,EXAWORD	*/
EXAWORD	si_matb();	/* EXAWORD,EXAWORD	*/
EXAWORD	si_close();	/* EXAWORD	*/
EXAWORD	si_create();	/* BPTR,EXAWORD,EXAWORD,EXAWORD,EXAWORD,EXAWORD	*/
EXAWORD	si_unlink();	/* BPTR,EXAWORD,EXAWORD	*/
EXAWORD	si_rename();	/* BPTR,BPTR	*/
EXAWORD	si_up();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD,BPTR,EXAWORD	*/
EXAWORD	si_down();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD,BPTR,EXAWORD	*/
EXAWORD	si_insert();	/* EXAWORD,BPTR,EXAWORD,BPTR,EXAWORD	*/
EXAWORD	si_modif();	/* EXAWORD,BPTR,EXAWORD,BPTR,EXAWORD	*/
EXAWORD	si_search();	/* EXAWORD,EXAWORD,EXAWORD,BPTR,EXAWORD,BPTR,EXAWORD	*/
EXAWORD	si_delete();	/* EXAWORD,BPTR,EXAWORD	*/
EXAWORD	si_readzc();	/* EXAWORD,EXAWORD,BPTR,EXAWORD	*/
EXAWORD	si_writezc();	/* EXAWORD,BPTR,EXAWORD	*/
#endif
#endif
#ifndef DOS
#ifndef PROLOGUE
int    	si_open();	/* char *,int,int	*/
int    	si_matb();	/* int,int,int	*/
int    	si_close();	/* int	*/
int    	si_create();	/* char *,int,int,int,int,int,int	*/
int    	si_unlink();	/* char *	*/
int    	si_rename();	/* char *,char *	*/
int    	si_up();	/* int,int,int,int,char *,int	*/
int    	si_down();	/* int,int,int,int,char *,int	*/
int    	si_insert();	/* int,char *,int,char *,int	*/
int    	si_modif();	/* int,char *,int,char *,int	*/
int    	si_search();	/* int,int,int,char *,int,char *,int	*/
int    	si_delete();	/* int,char *,int	*/
int    	si_readzc();	/* int,int,char *,char *,int	*/
int    	si_writezc();	/* int,char *,char *, int	*/
#endif
#endif
EXAWORD	ngf_rename();	/* BPTR,EXAWORD,EXAWORD	*/
EXAWORD	frsplit();	/* BPTR	*/
EXAWORD	im_open();	/* BPTR,EXAWORD	*/
EXAWORD	im_close();	/* EXAWORD	*/
EXAWORD	extend();	/* EXAWORD,EXAWORD	*/
EXAWORD	GetSousRep();	/* BPTR,EXAWORD	*/
EXAWORD	prlvolif();	/* BPTR,EXAWORD,EXAWORD	*/
EXALONG	mc_key();	/* EXAWORD,EXAWORD,BPTR,EXAWORD,EXAWORD	*/
EXAWORD prep();		/* EXAWORD,EXAWORD,BPTR,EXAWORD	*/
EXAWORD	anajoin();	/* BPTR,BPTR	*/
EXAWORD	killjoin();	/* BPTR	*/

/*	-------------	*/
/*	EXMMBIB$(OBJ)	*/
/*	-------------	*/
VPTR	Qalloc();	/*  unsigned short int 	*/
VOID	Qfree();	/*  VPTR 		*/
VPTR	Mmalloc();	/*  unsigned int 	*/
VPTR	Mcalloc();	/*  unsigned int, unsigned int 	*/
VOID	Mfree();	/*  VPTR 	*/
#ifndef WIN32
VPTR	malloc();	/*  unsigned int 	*/
VPTR	calloc();	/*  unsigned int, unsigned int 	*/
VOID	free();		/*  VPTR 	*/
#endif
VPTR	Mmemcpy();	/*  VPTR , VPTR , unsigned int 	*/
BPTR	Mstrcpy();	/*  BPTR , BPTR 	*/
VPTR	Mmemset();	/*  VPTR , unsigned int , unsigned int 	*/
unsigned int Mstrlen();	/*  BPTR 	*/
#ifndef	ABAL_RTL
EXAWORD	lenuse();	/*  BPTR , EXAWORD 	*/
#endif
EXAWORD	isincl();	/*  VOID 	*/
#ifdef UNIX
EXAWORD	matb();	/* BPTR,EXAWORD,EXAWORD,EXAWORD	*/
#else
EXAWORD	matb();	/* EXAWORD,EXAWORD,EXAWORD,EXAWORD	*/
#endif
#ifdef	SUPERTEAM
#ifdef UNIX
EXAWORD	unlink();	/*  BPTR 	*/
USINT  	read();	/* USINT,char *,USINT	*/
USINT  	write();	/* USINT,char *,USINT	*/
USINT  	open();	/* char *,USINT,USINT	*/
USINT  	create();	/* char *,USINT  	*/
USINT   close();	/* USINT  	*/
#else
EXAWORD	read();	/* EXAWORD,BPTR,EXAWORD	*/
EXAWORD	write();	/* EXAWORD,BPTR,EXAWORD	*/
EXAWORD	open();	/* BPTR,EXAWORD	*/
EXAWORD	create();	/* BPTR,EXAWORD	*/
EXAWORD	close();	/* EXAWORD	*/
#endif
#endif
#ifdef UNIX
int    	Access();	/* char *,int  ,int    	*/
#else
EXAWORD	Access();	/* BPTR,EXAWORD,EXAWORD	*/
#endif
EXAWORD	dir_seek();	/* BPTR,EXAWORD,BPTR,EXAWORD,EXAWORD	*/
EXAWORD	VerifPtr();	/* VPTR	*/
VOID	ExaDmex();	/*  VOID 	*/
VOID	ExaFmex();	/*  VOID 	*/
VOID	PrlDate8();	/* BPTR,EXAWORD	*/

/*	-----------	*/
/*	EXBCD$(OBJ)	*/
/*	-----------	*/
EXAWORD	bcdcalc();	/*  EXAWORD 	*/
EXAWORD	bcdcomp();	/*  EXAWORD 	*/
BINAIRE	isequalit();	/*  VOID 	*/
VOID	clf_left();	/*  VOID 	*/
VOID	clf_right();	/*  VOID 	*/
VOID	clf_move();	/*  VOID 	*/
VOID	clf_substr();	/*  VOID 	*/
VOID	clf_shr();	/*  VOID 	*/
VOID	clf_shl();	/*  VOID 	*/
VOID	clf_inv();	/*  VOID 	*/
VOID	clf_large();	/*  VOID 	*/
VOID	clf_small();	/*  VOID 	*/
VOID	clf_gener();	/*  VOID 	*/
VOID	clf_space();	/*  VOID 	*/
VOID	clf_chr();	/*  VOID 	*/

#ifdef	DOS

VOID	Trap24();	/*  VOID 	*/
VOID	UnTrap24();	/*  VOID 	*/
VOID	dos_arto();	/*  VOID 	*/

#endif


/*	------------	*/
/*	EXAPRL$(LIB)	*/
/*	------------	*/

#ifdef 	PROLOGUE
BPTR	cgets();	/*  BPTR 	*/
VOID	arto();	/*  BPTR 	*/
VOID	drto();	/*  BPTR 	*/
VOID	wait();	/*  BPTR  	*/
EXAWORD	npos();	/*  VOID 	*/
EXAWORD	Chargeur();	/* BPTR,BPTR	*/
EXAWORD	ExecGo();	/* BPTR,BPTR	*/
EXAWORD DisCharge();	/* BPTR	*/
EXAWORD	renfile();	/* EXAWORD,BPTR	*/
EXAWORD	check33();	/*  VOID 	*/
#endif

EXAWORD	date();	/*  EXAWORD 	*/
EXAWORD mdate();	/*  EXAWORD , EXAWORD , EXAWORD 	*/
EXAWORD mtime();	/*  EXAWORD , EXAWORD , EXAWORD 	*/

#endif	/* UNIX */
	/* ---- */

#include "exmissing.h"

#endif
