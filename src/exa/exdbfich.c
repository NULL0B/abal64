VOID	fichview( cmdptr )
BPTR	cmdptr;
{
	EXAWORD xl,lno;

	while (( *cmdptr == IO_ESP ) && ( *cmdptr != IO_NUL)) { cmdptr++; }

	if ( *cmdptr == IO_NUL ) { return; }

	if ( *cmdptr == '?' ) 	 {

		/* Display Assign MAP 	*/
		/* ------------------ 	*/
		/* AssignMap(); 	*/
		/* ------------ 	*/
		return;

		}

	xl = strlen(cmdptr); lfh = atoi(cmdptr,xl);

	if ( lfh > diezfic ) {	return; }

	if ((err_val = loadfich()) != 0)
		return;

	if ( fidname == (BPTR) 0) { return; }

	/* Save Window Zone and display window */
	/* ----------------------------------- */
	if (PushZone(2,2,7,(ScreenCol - 2),0x0013,Couleurs[0][0],Couleurs[0][1]) != 0) {
		Debordement();
		return;
		}

	lno = 3;
	db_xpos(lno++,4);	db_xcprintf((BPTR)"ASSIGN  : ");
				intvisi( lfh );
	db_xpos(lno++,4);	db_xcprintf((BPTR)"Fichier : "); 
				db_xcprintf((BPTR) fidname );
	db_xpos(lno++,4);	db_xcprintf((BPTR)"F.I.D.  : ");
				if (( fidreel != 0 ) && ( fidreel != MOINS_UN)) {
					db_xcprintf((BPTR)"OPEN(");
					intvisi(fidreel);
					db_xputch(')');
					}
	db_xpos(lno++,4);	db_xcprintf((BPTR)"Options : ");

	if ( fidperm & 1 ) { db_xcprintf((BPTR) "WR "); }
	if ( fidperm & 2 ) { db_xcprintf((BPTR)"EX "); }
	if ( fidperm & 4 ) { db_xcprintf((BPTR)"C  "); }
	if ( fidperm & 8 ) { db_xcprintf((BPTR)"DF "); }
	if ( fidperm & 16) { db_xcprintf((BPTR)"DV "); }
	else 	{
		switch (( fidperm & 0x00E0 ) >> 5 ) {		
			case 0 : db_xcprintf((BPTR)"AD "); break;
			case 1 : db_xcprintf((BPTR)"SQ "); break;
			case 2 : db_xcprintf((BPTR)"SI "); break;
			case 3 : db_xcprintf((BPTR)"MC "); break;
			case 4 : db_xcprintf((BPTR)"BD "); break;
			case 7 : db_xcprintf((BPTR)"MC("); intvisi( fidbd ); 
				 db_xputch(')'); break;
			}
		}
	switch ( ExitMethod(1)) {
		case 0 : PopZone(); break;
		case 1 : LibZone(); break;
		}
	return;
}
