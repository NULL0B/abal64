

#ifndef	_jsp_native_h
#define	_jsp_native_h

#define	MAX_NATIVE	1

//	Function Prototypes for the native functions
//	--------------------------------------------
int	document_write();

//	External Names of Internal Native Functions
//	-------------------------------------------
char *	NativeName[MAX_NATIVE] = {
	(char *) "document_write"
	};

//	Pointers to Internal Native Functions
//	-------------------------------------
void *	NativeFunction[MAX_NATIVE] = {
	document_write
	};


#endif	// _jsp_native_h

