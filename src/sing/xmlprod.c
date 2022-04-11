/*	------------------------------------	*/
/*	HTML/XML Special Character Mnemonics 	*/
/*	------------------------------------	*/

#define	MAX_MNEMONIC	7

static	char *	Mnemonix[MAX_MNEMONIC] = {
	(char *) "lt",
	(char *) "gt",
	(char *) "amp",
	(char *) "agrave",
	(char *) "egrave",
	(char *) "eacute",
	(char *) "ccedil"
	};

static	int	Mnemonich[MAX_MNEMONIC] = {
	'<',	'>',	'&',
	'…',	'Š',	'‚',	'‡'	
	};


/*	-----------------------		*/
/*	XML PRODUCTION ROUTINES		*/
/*	-----------------------		*/

void	xml_put_string(FILE * h, char * name, char * value, int margin)
{
	if ((!( name )) || (!( value )))
		return;
	indent(h,margin);
	fprintf(h,"<%s>%s</%s>",name,value,name);
	linefeed(h);
	return;
}


void	xml_put_cdata(FILE * h, char * sptr )
{
	int	c;
	int	m;
	while ( *sptr ) {
		c = *(sptr++);
		for ( m=0; m < MAX_MNEMONIC; m++ ) {
			if ( Mnemonich[m] == c ) {
				fprintf(h,"&%s;",Mnemonix[m]);
				break;
				}
			}
		if ( m < MAX_MNEMONIC )
			continue;
		else	{
			fprintf(h,"%c",c);
			continue;
			}
		}
	return;
}

void	xml_put_word(FILE * h, char * name, int value, int margin)
{
	indent(h,margin);
	fprintf(h,"<%s>%u</%s>",name,value,name);
	linefeed(h);
	return;
}


