/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : SYNTAXE.H
 *      Version : 2.2b
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions communes aux analyseurs lexical et syntaxique]
 *
 * --------------------------------------------------------------------------
 * 27/10/92 : Debut revision 1.5
 *            Insertion des nouveaux mots cles :
 *            ALIAS (fct), ANY (syn), AS (syn), ASKATB (ins), ASKCOLOR (ins)
 *            CREATE (ins), FORGET (ins), FORWARD (syn), IN (syn), INITGLOBAL (mac)
 *            INITLOCAL (mac), LANG (fct), LIKE (syn), NAME (ins), PARSE (fct)
 *            POWER (fct), CODE (syn), PTR (syn), REAL (fct), REMOVE (ins)
 *            STDFORM (fct), VALIDPTR(fct)
 *
 *	06/09/93 : introduction de LOCAL pour ON LOCAL ERROR
 * 17/02/97 : Debut revision 2.2
 *				  Nouveaux mots cles : ENDSTRUCT, STRUCT
 * 01/04/97 : Nouveaux mots cles : ENDWITH, WITH	
 * 02/06/97 : Ajout de OPT_USE et OPT_DECLARE
 * 27/04/98 : ajout EVENT DONE et refonte des #define
 * -------------------------------------------------------------------------
 * 22/11/99 : (#AT) Enhancement ATR: BINARY keyword.
 *	------------ 2.2b -------------------------------------------------
 */

#ifndef _SYNTAXE_H
#define _SYNTAXE_H

/*              definition du type "code syntaxique"            */
/*              ------------------------------------            */

typedef int Code_Synt;

/*      ATTENTION : Les mots reserves doivent etre en premier, et dans l'ordre
 *                  alphabetique pour respecter le lien avec la table decrite
 *                  dans le fichier LEXICAL.H (a l'exception de READMEM
 *                  et de END.SEG a partir de la version 1.4).
 */

#define ABORT		0
#define ABS			1
#define ALIAS		2
#define ALTER		3
#define AND			4
#define ANY			5
#define ARC			6
#define ARG			7
#define AS			8
#define ASK			9
#define ASKATB		10
#define ASKCOLOR		11
#define ASSIGN		12
#define ATB			13
#define ATN			14
#define ATTACH		15
#define BACKSPACE		16
#define BELL		17
/* #AT: 22/11/99 (begin) */
#define BINARY		18
/* #AT: 22/11/99 (end) */
#define BOX			19
#define BREAK		20
#define CALL		21
#define CASE		22
#define CFILE		23
#define CHAIN		24
#define CHR			25
#define CIRCLE		26
#define CJOIN		27
#define CKEY		28
#define CLEAR		29
#define CLINK		30
#define CLOSE		31
#define CODE		32
#define COL			33
#define CONF		34
#define CONST		35
#define CONV		36
#define COS			37
#define COUNT		38
#define CREATE		39
#define CURDIR		40
#define CURVOL		41
#define DATA		42
#define DATE		43
#define DCL			44
#define DEC			45
#define DEFAULT	46
#define DEFPAINT	47
#define DELETE		48
#define DETTACH	49
#define DFILE		50
#define DISPLAY	51
#define DJOIN		52
#define DO			53
#define DOWN		54
#define ELSE		55
#define END			56
#define ENDIF		57
#define ENDLOC		58
#define ENDPROC	59
#define ENDSEL		60
#define ENDSTRUCT	61
#define ENDWITH	62
#define ENV			63
#define ERRADR		64
#define ERROR		65
#define ESEG		66
#define EVENT		67
#define EVENTADR	68
#define EVENTDONE	69
#define EXIT		70
#define EXP			71
#define EXTEND		72
#define EXTERN		73
#define FIELD		74
#define FFILE		75
#define FILLER		76
#define FIND		77
#define FIX			78
#define FKEY		79
#define FM			80
#define FMT			81
#define FOR			82
#define FORGET		83
#define FORWARD	84
#define FP			85
#define FREEFONT	86
#define GENER		87
#define GOSUB		88
#define GOTO		89
#define GRCONF		90
#define HASH		91
#define HEX			92
#define HOME		93
#define HOTKEY		94
#define IF			95
#define IN_KEYWORD	96
#define INCLUD		97
#define INDEX		98
#define INITGLOBAL	99
#define INITLOCAL	100
#define INSERT		101
#define INSTR		102
#define INT			103
#define INV			104
#define JOIN		105
#define KBF			106
#define KEY			107
#define LANG		108
#define LARGE		109
#define LASER		110
#define LDGOSEG	111
#define LEFT		112
#define LEN			113
#define LFILE		114
#define LIKE		115
#define LIN			116
#define LINE		117
#define LINK		118
#define LJOIN		119
#define LKEY		120
#define LLINK		121
#define LOADGO		122
#ifdef _KEYWORD_LOADUSER
#define _PLOADUSER	1
#define LOADUSER	123
#else
#define _PLOADUSER	0
#endif
#define LOCAL		123 + _PLOADUSER
#define LOG			124 + _PLOADUSER
#define LOOP		125 + _PLOADUSER
#define MASK		126 + _PLOADUSER
#define MOD			127 + _PLOADUSER
#define MODIF		128 + _PLOADUSER
#define MODULE		129 + _PLOADUSER
#define MOVE		130 + _PLOADUSER
#define NAME		131 + _PLOADUSER
#define NEXT		132 + _PLOADUSER
#define NKEY		133 + _PLOADUSER
#define XNULL		134 + _PLOADUSER
#define OF			135 + _PLOADUSER
#define OFF			136 + _PLOADUSER
#define ON			137 + _PLOADUSER
#define OP			138 + _PLOADUSER
#define OPEN		139 + _PLOADUSER
#define OR			140 + _PLOADUSER
#define OX			141 + _PLOADUSER
#define PAGE		142 + _PLOADUSER
#define PAINT		143 + _PLOADUSER
#define PALET		144 + _PLOADUSER
#define PARSE		145 + _PLOADUSER
#define PAUSE		146 + _PLOADUSER
#define PEN			147 + _PLOADUSER
#define PIE			148 + _PLOADUSER
#define POINT		149 + _PLOADUSER
#define POSIT		150 + _PLOADUSER
#define POWER		151 + _PLOADUSER
#define PREAD		152 + _PLOADUSER
#define PRINT		153 + _PLOADUSER
#define PROC		154 + _PLOADUSER
#define PROCESS	155 + _PLOADUSER
#define PROGRAM	156 + _PLOADUSER
#define PTR			157 + _PLOADUSER
#define READ		158 + _PLOADUSER
#define REAL		159 + _PLOADUSER
#define RECORD		160 + _PLOADUSER
#define REMOVE		161 + _PLOADUSER
#define RENAME		162 + _PLOADUSER
#define REPEAT		163 + _PLOADUSER
#define RESTORE	164 + _PLOADUSER
#define RESUME		165 + _PLOADUSER
#define RETSEG		166 + _PLOADUSER
#define RETURN		167 + _PLOADUSER
#define RIGHT		168 + _PLOADUSER
#define RJOIN		169 + _PLOADUSER
#define RKEY		170 + _PLOADUSER
#define RND			171 + _PLOADUSER
#define ROUN		172 + _PLOADUSER
#define SEARCH		173 + _PLOADUSER
#define SEGMENT	174 + _PLOADUSER
#define SELECT		175 + _PLOADUSER
#define SGN			176 + _PLOADUSER
#define SHL			177 + _PLOADUSER
#define SHR			178 + _PLOADUSER
#define SIN			179 + _PLOADUSER
#define SMALL		180 + _PLOADUSER
#define SPACE		181 + _PLOADUSER
#define SQR			182 + _PLOADUSER
#define STAT		183 + _PLOADUSER
#define STDFORM	184 + _PLOADUSER
#define STEP		185 + _PLOADUSER
#define STOP		186 + _PLOADUSER
#define STRN		187 + _PLOADUSER
#define STRUCT		188 + _PLOADUSER
#define SUBSTR		189 + _PLOADUSER
#define SWAP		190 + _PLOADUSER
#define SYSERROR	191 + _PLOADUSER
#define TAB			192 + _PLOADUSER
#define TABV		193 + _PLOADUSER
#define TAN			194 + _PLOADUSER
#define TEXTPEN	195 + _PLOADUSER
#define THEN		196 + _PLOADUSER
#define TIMER		197 + _PLOADUSER
#define TO			198 + _PLOADUSER
#ifdef _KEYWORD_TRACE
#define _PTRACE 1
#define TRACE     199 + _PLOADUSER
#else
#define _PTRACE 0
#endif
#define TRAN		199 + _PLOADUSER + _PTRACE
#define UNTIL		200 + _PLOADUSER + _PTRACE
#define UP			201 + _PLOADUSER + _PTRACE
#define USEFONT	202 + _PLOADUSER + _PTRACE
#define USER		203 + _PLOADUSER + _PTRACE
#define VAL			204 + _PLOADUSER + _PTRACE
#define VALIDPTR	205 + _PLOADUSER + _PTRACE
#define VIEWPORT	206 + _PLOADUSER + _PTRACE
#define VPTR		207 + _PLOADUSER + _PTRACE
#define WAIT		208 + _PLOADUSER + _PTRACE
#define WEND		209 + _PLOADUSER + _PTRACE
#define WHERE		210 + _PLOADUSER + _PTRACE
#define WHILE		211 + _PLOADUSER + _PTRACE
#define WINDOW		212 + _PLOADUSER + _PTRACE
#define WITH		213 + _PLOADUSER + _PTRACE
#define WRITE		214 + _PLOADUSER + _PTRACE
#define XCRI      215 + _PLOADUSER + _PTRACE



/*
 *      unites autres que des mots reserves du langage A.B.A.L.
 */
#define _PEXT           20
#define READMEM         200 + _PEXT
#define ILLEGAL         201 + _PEXT
#define FDLN            202 + _PEXT
#define CBIN            203 + _PEXT
#define CBCD            204 + _PEXT
#define CSTR            205 + _PEXT
#define IDENT           206 + _PEXT
#define ETIQ            207 + _PEXT
#define DIESE           208 + _PEXT
#define PCENT           209 + _PEXT
#define STR             210 + _PEXT
#define PLUS            211 + _PEXT
#define MOINS           212 + _PEXT
#define DIV             213 + _PEXT
#define MUL             214 + _PEXT
#define PAG             215 + _PEXT
#define PAD             216 + _PEXT
#define INF             217 + _PEXT
#define SUP             218 + _PEXT
#define EGAL            219 + _PEXT
#define VIG             220 + _PEXT
#define DPT             221 + _PEXT
#define INFE            222 + _PEXT
#define SUPE            223 + _PEXT
#define DIFF            224 + _PEXT
#define INTERRO         225 + _PEXT
#define EXCLAM          226 + _PEXT
#define CONC            227 + _PEXT     /* special pour concatenation de chaines */
#define SPT             228 + _PEXT     /* simple '.' */
#define NIN             229 + _PEXT     /* non-inclusion chaines */
#define EQSTR           230 + _PEXT     /* egalite stricte chaines */
#define FUSER           231 + _PEXT     /* fonction utilisateur */
#define ENDSEG          232 + _PEXT
#define IDENT_MODULE    233 + _PEXT
#define ENDDPTPROC		234 + _PEXT
#define ENDUSER			235 + _PEXT

/*              definition du type "unite syntaxique"           */
/*              -------------------------------------           */

#define Unit_Synt struct _t_us

Unit_Synt {
        Code_Synt        code;  /* code de l'unite syntaxique */
        Code_Synt        excode;  /* Extension du code de l'unite syntaxique */
        union {
                char     *pval; /* pointeur sur la representation "chaine"*/
                                /* pour constante, etiquette, ou ident    */
                BINAIRE  val;   /* valeur binaire pour constantes de ce type */
                BYTE     *pbcd; /* valeur d'une constante BCD , le 1er octet */
                                /* contenant dans ce cas la longueur utile */
                Tbusr   *ptusr; /* ptr sur le descripteur d'une fonction */
                                /* utilisateur */
        } v;
};

/*              etats du traducteur                      */
/*              -------------------                      */

#define S_DECL  '1'     /* Phase de declaration */
#define S_PARS  '2'     /* Phase de traduction A.B.A.L. */
#define S_MASM  '3'     /* Phase de traduction directe / assemblage T-Code */

/*              type des segments / variables locales           */

#define OPT_RES 1
#define OPT_PUB 2

/*		Symbole utilis‚ ou d‚clar‚ */
#define OPT_NOT_IN_MEMORY 0x04
#define OPT_USE			0x80
#define OPT_NOT_DECLARE	0x40

#endif /* _SYNTAXE_H */

