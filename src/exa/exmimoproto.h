#ifndef _exmimoproto_h
#define _exmimoproto_h

#ifndef public
#define public
#endif

public EXAWORD  init_mimo();
public void     save_mimo_context(BPTR);
public void     restore_mimo_context(BPTR);
public void     release_input_focus();
public void     restore_input_focus();
public EXAWORD	fin_mimo();

	/* -------------- */
#endif	/* _exmimoproto_h */
	/* -------------- */

