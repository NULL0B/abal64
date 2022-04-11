WORD compare_tokens(BPTR aptr,BPTR bptr) { return(FAUX); }
WORD uppercase_compare(BPTR aptr,BPTR bptr) { return(FAUX); }
WORD is_level1_keyword(VOID) { return(MOINS_UN); }

VOID uppercase_keyword(VOID) { return; } 
VOID cancel_keyword(BPTR  XPTR kptr) { return; }
VOID set_keyword_status(WORD state) { return; }
BPTR get_class_keyword(WORD n) { return((BPTR) 0); }
BPTR get_ngf_keyword(WORD n) { return((BPTR) 0); }
WORD keyword_hash(BPTR sptr) { return(MOINS_UN); }
WORD is_ngf_keyword(VOID) { return(MOINS_UN); }
#ifdef	WITH_NURAL
WORD is_nural_keyword(VOID) { return(MOINS_UN); }
#endif
WORD is_class_keyword(VOID) { return(MOINS_UN); }
WORD is_iof_keyword(VOID) { return(MOINS_UN); }
WORD is_level2_keyword(VOID) { return(MOINS_UN); }
WORD is_dcl_keyword(VOID) { return(MOINS_UN); }
WORD is_control_keyword(VOID) { return(MOINS_UN); }
WORD is_logical_keyword(VOID) { return(MOINS_UN); }
WORD comparison_operator(WORD mode) { return; }





