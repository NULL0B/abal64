#define CR	0x0d
#define BS	0x08
unsigned short prndest;
unsigned short prnfid=0;
unsigned short prnleng=0;
unsigned short err_val=0;
unsigned char *prnptr;

void impression()
{
	register i, j;
	char c;
	char nom[162];
	int mode;
	char tmp[60];

	x_clear();
#ifdef INTER
	x_cprintf("designation imprimante ? ");
	for (i = 0; i < 79 && (c = x_getch()) != CR; ) {
		if (c == BS) {
			if (i > 0) {
				nom[--i] = '\0';
				x_putch(BS);
				x_putch(' ');
				x_putch(BS);
			} else
				x_bell();
		} else if (c >= ' ') {
			nom[i++] = c;
			x_putch(c);
		} else
			x_bell();
	}
	nom[i] = '\0';
	x_cprintf("\r\n");
#endif
	if (*nom != '\0') {
#ifdef INTER
		x_cprintf("mode d'ouverture ? ");
		x_putch(mode = x_getch());
		x_cprintf("\r\n");
		if (mode >= '0' && mode <= '9')
			mode -= '0';
		else
			mode = 0;
#endif
		strcpy(nom,"titi(,lp -c $1)");
		prnfid = im_open(nom, mode);
		if (prnfid == -1) {
			x_cprintf("erreur ouverture ");
			x_cprintf(nom);
			x_cprintf(" (");
			x_putch(err_val / 10 + '0');
			x_putch(err_val % 10 + '0');
			x_putch(')');
			err_val = 0;
			while (x_getch() != CR)
				x_bell();
			return;
		} else {
			x_cprintf("\r\n");
			x_cprintf(nom);
			x_cprintf("\r\n");
		}
	} else
		prnfid = 0;
	
	sprintf(tmp,"PRNFID=%i\r\n",prnfid);
	x_cprintf(tmp);

	prndest = 2;
	x_bstart();
	x_clear();
	x_cprintf("1234567890");
	pos(5, 5);
	x_cprintf("[5, 5]\r\n");
	for (i = 0; i < 20; i++) {
		atb(i);
		for (j = 0; j < 80; j++) {
			x_putch(j % 10 + '0');
			if (err_val != 0) {
				err_val = 0;
				prndest = 1;
				x_cprintf("erreur impression\r\n");
				while (x_getch() != CR)
					x_bell();
				return;
			}
		}
		x_cprintf("\r\n\ttest\ttest\r\n");
		atb(0);
	}
	x_cprintf("   |  2  3  4  5  6  7  8  9  a  b  c  d  e  f\r\n");
	x_cprintf("---+------------------------------------------\r\n");
	for (i = 0; i < 16; i++) {
		if (i < 10)
			x_putch(i + '0');
		else
			x_putch(i - 10 + 'a');
		x_cprintf("  |");
		for (j = 2; j < 16; j++) {
			x_cprintf("  ");
			x_putch(j * 16 + i);
		}
		x_cprintf("\r\n");
	}
	x_clear();
	x_bflush();
	im_close();
	prndest = 1;
}


main()
{
int i;
unsigned short int c;
char tmp[20];
	err_val =0;
	prndest=1;
	initerm();
	x_clear();
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");
	x_cprintf("01234567890\n\r");


	c=x_getch();
	x_putch(c);
	c=x_getch();
	x_putch(c);
	c=x_getch();
	x_putch(c);
	c=x_getch();
	x_putch(c);
	finterm(0);
	return;
	while (1) {
/*		x_putch('.'); */
		if ( x_kbhit() ) {
			c = x_getch();
			x_putch(c);
			break;
		}		
	}
	c=x_getch();
	x_putch(c);
	x_putch('\n');
	x_putch('\r');
	c=x_getch();
	x_putch(c);
	x_putch('\n');
	x_putch('\r');
	c=x_getch();
	x_putch(c);
	x_putch('\n');
	x_putch('\r');
	finterm(0);
	return;
	impression();
/*
	sprintf(tmp,"PROCESS=%i",(unsigned short int) x_npos());
	x_cprintf(tmp);
*/
	x_putch('\n');
	x_putch('\r');
	finterm(0);
	return;
/* Probleme */
	x_clear();
	atb(2);
	backgr(1);
	foregr(0);
	for ( i=1; i<30; i++) {
		sprintf(tmp,"%d:",i);
		x_cprintf(tmp);
		x_cprintf("test");
		x_putch('\r');
		x_putch('\n');
		c=x_getch();
	}
	x_push();
	c=x_getch();
	x_clear();
	x_pop();
	c=x_getch();
	finterm(0);
}
