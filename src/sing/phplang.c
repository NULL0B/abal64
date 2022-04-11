#ifndef	_phplang_c
#define	_phplang_c

public	void	php_start( FILE * h )
{
	FILE * hh;
	int	c;
	fprintf(h,"<?php\n");
	if ((hh = fopen( "license.txt", "r")) != (FILE *) 0)
	{
		while ((c = fgetc(hh)) != -1)
			fputc(c,h);
		fclose(hh);
	}
	return;
}

public	void	php_open_exclusion( FILE * h, char * sptr )
{
	fprintf(h,"\nif (!( isset($_%s_) ))\n{\n",sptr);
	return;
}

public	void	php_require( FILE * h, char * nptr )
{
	fprintf(h,"\trequire_once(%c%s%c);\n",__QUOTE,nptr,__QUOTE);
	return;
}

public	void	php_class( FILE * h, char * nptr )
{
	fprintf(h,"\n// c l a s s   :  %s\n",nptr);
	fprintf(h,"\nclass %s\n{\n",nptr);
	return;
}

public	void	php_extends( FILE * h, char * nptr, char * dptr )
{
	fprintf(h,"\n// c l a s s   :  %s\n",nptr);
	fprintf(h,"\nclass %s extends %s\n{\n",nptr,dptr);
	return;
}

public	void	php_endclass( FILE * h, char * nptr )
{
	fprintf(h,"\n} // %s \n",nptr);
	return;
}

public	void	php_close_exclusion( FILE * h, char * sptr )
{
	fprintf(h,"\n$_%s_ = 1;\n}\n",sptr);
	return;
}

public	void	php_end( FILE * h )
{
	fprintf(h,"\n?>");
	return;
}

#endif	/* _phplang_c */
	/* ---------- */

