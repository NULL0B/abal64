#ifndef	_edbann_c
#define	_edbann_c

static char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		if ( VersionStatus[15] > '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = '.';
			LaVersion[7] = LaPaterne[16];
			LaVersion[8] = LaPaterne[17];
			LaVersion[9] = 0;
			}
		else if ( LaPaterne[15] > '0' ) {
			LaVersion[4] = '.';
			LaVersion[5] = LaPaterne[15];
			LaVersion[6] = 0;
			}
		else	LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}


VOID banniere ()

/*	affichage de la banniere du programme
 */
{					/* banniere */
	SWORD lg,i;

	printf("   %s",edit_msg[titre]);
	printf(" %s",version);
#ifdef	OLD_AED
	printf("%c.%c%c",ved,ied,red);
	printf(" -X11 ");
#ifdef prl3
	printf("-P3");
#endif
	printf("   %s",prov);
#else
	printf("%s",getpatternversion());
	if (VersionStatus[15] == '2' )
		printf("   %s",prov);
#endif

#ifndef ver11
	printf("\n   %s",edit_msg[banenv]);
	printf(" %s",version);
	printf("%c.%c%c",vved,vied,vred);
	printf("%s",vpro);
#endif
	printf("\n   %s\n",copyright);
#ifdef ver14
	if ( etxmes ) {
		lg = (SWORD) (Xstrlen(etxmes));
		if (lg > 1) {
			for (i = 0; i < lg; i++) {
				printf("%c",*(etxmes + i));
				}	
			printf("\n");
			}
		}
#endif

}

#endif	/* _edbann_c */
	/* --------- */

