#ifndef	_edtabmes_c
#define	_edtabmes_c

#ifndef ver21
#ifdef HX
static VOID initabmes()

/*	Initialisation de la table des messages
 */

{					/* initabmes */
	BYTE XPTR p;
	SWORD	i;

	p = (BYTE XPTR) (&mentete[0][0]);
	for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
		if (i == 1) {
			ryes = (BYTE) tolower(*p);
			rno  = (BYTE) tolower(*(p+1));
		}
		p += strlen(p)+1;	
		while (*p == EOSTR)
			p++;
	}
	for (i = 0 ; i < NBMESS ; i++) {
		edit_msg[i] = p;
		p += strlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}
	for (i = 0; i < MAXCTRL; i++) {
		edit_ctrl[i] = p;
		p += strlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}

	/* message pour les tetons */

	etxmes = p ;
}					/* initabmes */

#else

static VOID initabmes()

/*	Initialisation de la table des messages
 */

{					/* initabmes */
	BYTE XPTR p;
	SWORD	i;

	p = (BYTE XPTR) &mentete[0];
	for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
		p += (SWORD)(Xstrlen(p)+1);
		while (*p == EOSTR)
			p++;
	}
	for (i = 0 ; i < NBMESS ; i++) {
		edit_msg[i] = (BYTE XPTR) (p);
		p += (SWORD) (Xstrlen(p) + 1);
		while (*p == EOSTR)
			p++;
	}
	for (i = 0; i < MCTRL; i++) {
		edit_ctrl[i] = (BYTE XPTR) (p);
		p += (SWORD) (Xstrlen(p) + 1);
		while (*p == EOSTR)
			p++;
	}

	/* message pour les tetons */
	etxmes = p ;

	ryes = (BYTE) tolower(ouinon[0]);
	rno =  (BYTE) tolower(ouinon[1]);

}					/* initabmes */

#endif
#else
#ifdef HX
static VOID initabmes()
 
/*	Initialisation de la table des messages
 */

{					/* initabmes */
	BYTE XPTR p;
	SWORD	i;
	BOOL		other;

	other = FALSE;

	p = (BYTE XPTR) &mentete[0][0];
	for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
		if (i == 1) {
			ryes = (BYTE) tolower(*p);
			rno  = (BYTE) tolower(*(p+1));
			if (*(p+2) == '1') {
				other = TRUE;
				break;
			}
		}
		p += strlen(p)+1;	
		while (*p == EOSTR)
			p++;
	}

	if (other == TRUE) {
		/* autre zone gesmetable */
		p = &oentete[0][0];
		for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
			if (i == 1) {
				ryes = (BYTE) tolower(*p);
				rno  = (BYTE) tolower(*(p+1));
			}
			p += Xstrlen(p)+1;
			while (*p == EOSTR)
				p++;
		}
	}
	for (i = 0 ; i < NBMESS ; i++) {
		edit_msg[i] = p;
		p += strlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}

	for (i = 0; i < MAXCTRL; i++) {
		edit_ctrl[i] = p;
		p += strlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}

#ifdef ver14

	/* message pour les tetons */
	etxmes = p;

#endif

}					/* initabmes */

#else

static VOID initabmes()

/*	Initialisation de la table des messages
 */

{					/* initabmes */
	BYTE XPTR p;
	SWORD	i;
	BOOL	other;

	other = FALSE;

	p = (BYTE XPTR) &mentete[0];

	for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */
		if (i == 1) {
			ryes = (BYTE) tolower(*p);
			rno  = (BYTE) tolower(*(p+1));
			if (*(p+2) == '1') {
				other = TRUE;
				break;
			}
		}
		p += strlen(p)+1;	
		while (*p == EOSTR)
			p++;
	}

	if (other == TRUE) {
		/* autre zone gesmetable */
		p = &oentete[0];
		for (i = 0 ; i < 2 ; i++) {	/* saute en-tete GESMES et O/N */

			if (i == 1) {
				ryes = (BYTE) tolower(*p);
				rno  = (BYTE) tolower(*(p+1));
			}

			p += Xstrlen(p)+1;
			while (*p == EOSTR)
				p++;
		}
	}

	for (i = 0 ; i < NBMESS ; i++) {
		edit_msg[i] = p;
		p += strlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}
	for (i = 0; i < MAXCTRL; i++) {
		edit_ctrl[i] = p;
		p += strlen(p) + 1;
		while (*p == EOSTR)
			p++;
	}

#ifdef ver14
	/* message pour les tetons */
	etxmes = p;
#endif

}					/* initabmes */

#endif
#endif

#endif	/* _edtabmes_c */

