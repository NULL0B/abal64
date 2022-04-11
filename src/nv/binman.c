#ifndef	_html_binman_c
#define _html_binman_c
extern "C" {
int /* _cdecl */	TheBinMen()
{
	return( html_browser::garbage_collector() );
}

void /* _cdecl */	TheStatMan(int i)
{
	if ( i )
		html_statistics::malloc_count++;
	else	html_statistics::free_count++;
	return;
}

	};
#endif	// _html_binman_c

