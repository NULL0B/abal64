/* ---------------------------------------------------------------------- */
/* aconf.h							13/04/94  */
/* ---------------------------------------------------------------------- */

#define ACONF_MAX_NAME 80
#define ACONF_MAX_PATH 80

/* PROCESS */
/* ------- */

static BOOL abc_process_flag = FALSE;
static WORD abc_process_number = 0;

/* SCREEN */
/* ------ */

static BOOL abc_screen_flag = FALSE;
static BYTE abc_screen_name[ACONF_MAX_NAME];
static BYTE abc_screen_path[ACONF_MAX_PATH];
static WORD abc_screen_tempo = 1;
static WORD abc_screen_nbl = 0;	/* CONF(1) */
static WORD abc_screen_nbc = 0;	/* CONF(2) */

/* PRINTER */
/* ------- */

static BOOL abc_printer_flag = FALSE;
static BYTE abc_printer_name[ACONF_MAX_NAME];
static BYTE abc_printer_path[ACONF_MAX_PATH];
static WORD abc_printer_nbl = 66;		/* CONF(3) */
static WORD abc_printer_nbc = 132;		/* CONF(4) */

/* LANGUAGE */
/* -------- */

static BOOL abc_language_flag = FALSE;
static WORD abc_language = 0;			/* FRENCH */

/* COLORS */
/* ------ */

static BOOL abc_color_flag = FALSE;
static WORD abc_color_char = 2;		/* C_GREEN */
static WORD abc_color_back = 0;		/* C_BLACK */

#ifdef SHAREDLO

/* SHAREDLO */
/*----------*/

static BOOL abc_sharedlo_flag = FALSE;
static BOOL abc_noreset_flag = FALSE;

#endif

/* FUNCTIONS */
/* --------- */

#ifdef LINT_ARGS
static int lex(FILE *, char *);
static void establish_config(char *);
#else
static int lex();
static void establish_config();
#endif /* LINT_ARGS */

/* --------- Fin de fichier : aconf.h ----------------------------------- */
