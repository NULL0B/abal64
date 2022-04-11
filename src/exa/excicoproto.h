#ifndef _excicoproto_h
#define	_excicoproto_h

#ifndef	public
#define	public
#endif

public EXAWORD  initerm();
public EXAWORD  x_lin(EXAWORD);
public EXAWORD  x_col(EXAWORD);
public EXAWORD  conf(EXAWORD);
public EXAWORD  mimo_getch();
public EXAWORD  x_npos();
public void     x_clear();
public void     x_wipe();
public void     x_bflush();
public EXAWORD  x_kbhit();
public EXAWORD  x_getch();
public void     x_bstart();
public void     x_cprintf(BPTR);
public void     finterm();

#endif	/* _excicoproto_h */

