/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Object pre-processer			*/
/*									*/
/*		 Copyright (c) 1990, 1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	TRNGF.H    				*/
/*		Version :	2.1d					*/
/*		Date	:	20/12/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_TRNGF_H
#define	_TRNGF_H

#define	_SQ_READ	0x0061
#define	_SQ_WRITE	0x00A5
#define	_SQ_MODIF	0x00A1

#define	_NGF_L		0x8000
#define	_NGF_WR		0x0001
#define	_NGF_EX		0x0002  
#define	_NGF_C		0x0004
#define	_NGF_DF		0x0008	

#define	_NGF_IO		0x0000
#define	_NGF_SQ		0x0020
#define	_NGF_SI		0x0040	
#define	_NGF_MC		0x0060  
#define	_NGF_DB		0x0080	
#define	_NGF_DBF 	0x00E0	
#define	_NGF_SQL 	0x00C0	
#define	_NGF_XML 	0x00A0	

#define	_NGF_DV		0x0010	
#define	_NGF_GR		0x0030	
#define	_NGF_IM		0x0050
#define	_NGF_IPC	0x0070	

#define	_ISAM_VD	0x0001
#define	_ISAM_LK	0x0002
#define	_ISAM_RK	0x0006

#define	_ISAM_M		0x0010
#define	_ISAM_L		0x0020
#define	_ISAM_ML	0x0030

#define	_ISAM_SM	0x0030
#define	_ISAM_SL	0x0040
#define	_ISAM_SML	0x0050

#define	_ISAM_PI	0x0001
#define	_ISAM_MQ	0x0002
#define	_ISAM_DR	0x0004
#define	_ISAM_DL	0x0008

#define	_MISAM_D	0x0001

struct	ngf_control	{
	WORD		Colon;
	WORD		Operation;
	WORD		Special;
	WORD		Parameters;
	WORD		ErrorFlag;
	WORD		ErrorAdr;
#ifndef	_TRRTLNGF_C
	RESULTPTR	DataBase;
	RESULTPTR	Error;
	RESULTPTR	Parameter[16];
#else	
	BPTR		DataBase;
	BPTR		Error;
	BPTR		Parameter[16];
#endif
	BYTE		ErrorLabel[32];
	BYTE		Descriptor[32];
	};

#ifdef	_TRNGF_C
struct	ngf_control NGF;	
#endif

#ifndef	UNIX
WORD	ngf_explicite_label();
WORD	ngf_implicite_label( WORD );
WORD	is_mnemonic_next();
WORD	is_mnemonic_break();
WORD	is_mnemonic_label();
WORD	translate_assign( WORD );
WORD	translate_load_chain( WORD );
WORD	translate_find( WORD );
WORD	translate_cfile( WORD );
WORD	translate_dfile( WORD );
WORD	translate_rename( WORD );
WORD	translate_open_close( WORD );
WORD	translate_read_write( WORD );
WORD	ngf_operand();
WORD	key_type();
WORD	translate_key(  WORD  );
WORD	collect_possible_jointure( WORD );
WORD	translate_join(  WORD  );
WORD	translate_list(  WORD  );
WORD	link_option();
WORD	translate_link(  WORD  );
WORD	posit_option();
WORD	question_jointure();
RESULTPTR	question_option();
WORD	question_target();
WORD	translate_question(  WORD  );
WORD	atb_options();
WORD	translate_divers(  WORD  );
WORD	translate_ngf();
#else
WORD	translate_ngf();
#endif
WORD	translate_sql_select();

#endif	/* _TRNGF_H */
	/* -------- */
