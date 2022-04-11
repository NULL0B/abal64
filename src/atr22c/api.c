#include <windows.h>

extern int majn(int, LPSTR *);

__declspec(dllexport) VOID WINAPI Traduction(lpCmdLine)
LPSTR lpCmdLine;
{
	LPSTR	arg[2];

	arg[0] = "atr";
	arg[1] = lpCmdLine;

	if (lstrlen(lpCmdLine) == 0)		majn(1,arg);
	else								majn(2,arg);
}
