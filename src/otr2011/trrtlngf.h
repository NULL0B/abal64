#ifndef	_TRRTLNGF_H
#define	_TRRTLNGF_H

static	WORD	rtlngf_args[0x0030] = {
	4,2,2,1,1,4,4,1,
	1,1,1,1,1,2,1,2,
	6,2,2,2,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1
	};

static	BPTR	rtlngf_names[0x0030] = {
	(BPTR)	"ngf_cfile",		/* 0x0000 */
	(BPTR)	"ngf_dfile",		/* 0x0001 */
	(BPTR)	"ngf_rename",		/* 0x0002 */
	(BPTR)	"ngf_open",			/* 0x0003 */
	(BPTR)	"ngf_close",		/* 0x0004 */
	(BPTR)	"ngf_read",			/* 0x0005 */
	(BPTR)	"ngf_write",		/* 0x0006 */
	(BPTR)	"ngf_insert",		/* 0x0007 */
	(BPTR)	"ngf_modif",		/* 0x0008 */
	(BPTR)	"ngf_delete",		/* 0x0009 */
	(BPTR)	"ngf_search",		/* 0x000A */
	(BPTR)	"ngf_down",			/* 0x000B */
	(BPTR)	"ngf_up",			/* 0x000C */
	(BPTR)	"ngf_atb",		/* 0x000D */
	(BPTR)	"ngf_backspace",	/* 0x000E */
	(BPTR)	"ngf_extend",		/* 0x000F */
	(BPTR)	"ngf_assign",		/* 0x0010 */
	(BPTR)	"ngf_load",		/* 0x0011 */
	(BPTR)	"ngf_xcri",		/* 0x0012 */
	(BPTR)	"ngf_chain"	,	/* 0x0013 */
	(BPTR)	"ngf_key",		/* 0x0014 */
	(BPTR)	"ngf_ckey",		/* 0x0015 */
	(BPTR)	"ngf_rkey",		/* 0x0016 */
	(BPTR)	"ngf_fkey",		/* 0x0017 */
	(BPTR)	"ngf_nkey",		/* 0x0018 */
	(BPTR)	"ngf_lkey",		/* 0x0019 */
	(BPTR)	"ngf_link",		/* 0x001A */
	(BPTR)	"ngf_clink",	/* 0x001B */
	(BPTR)	"ngf_llink",	/* 0x001C */
	(BPTR)	"ngf_posit",	/* 0x001D */
	(BPTR)	"ngf_count",	/* 0x001E */
	(BPTR)	"ngf_stat",		/* 0x001F */
	(BPTR)	"ngf_record",	/* 0x0020 */
	(BPTR)	"ngf_join",		/* 0x0021 */
	(BPTR)	"ngf_cjoin",	/* 0x0022 */
	(BPTR)	"ngf_djoin",	/* 0x0023 */
	(BPTR)	"ngf_rjoin",	/* 0x0024 */ 
	(BPTR)	"ngf_ljoin",	/* 0x0025 */
	(BPTR)	"ngf_lfile",	/* 0x0026 */
	(BPTR)	"ngf_find",		/* 0x0027 */
	(BPTR)	"ngf_core",		/* 0x0028 */
	(BPTR)	"ngf_name"		/* 0x0029 */
	};

#endif	/* _TRRTLNGF_H */
	/* ----------- */

