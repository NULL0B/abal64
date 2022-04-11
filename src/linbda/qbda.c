#include <stdio.h>

#define	EXAWORD unsigned long long
#define	public
#define BYTE unsigned char
#define	FAR
#define PTR *

public EXAWORD GetAbalInt8(BYTE FAR PTR bptr) { return(*bptr); }
public EXAWORD GetAbalInt16(BYTE FAR PTR wptr)
{
        return(((*wptr<< 8)|*(wptr+1)));
}
public EXAWORD GetAbalInt32(BYTE FAR PTR wptr)
{
        int length=4;
        EXAWORD result=0;
        while ( length-- ) result = ((result << 8) | (*(wptr++) & 0x00FF));
        return(result);
}
public EXAWORD GetAbalInt64(BYTE FAR PTR wptr)
{
        int length=8;
        EXAWORD result=0;
        while ( length-- ) result = ((result << 8) | (*(wptr++) & 0x00FF));
        return(result);
}
public void PutAbalInt8(BYTE FAR * wptr, EXAWORD v)
{
        *wptr = (v & 0x00FF);
        return;
}
public void PutAbalInt16(BYTE FAR * wptr, EXAWORD v)
{
        int length=2;
        while ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }
        return;
}
public void PutAbalInt32(BYTE FAR * wptr, EXAWORD v)
{
        int length=4;
        while ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }
        return;
}
public void PutAbalInt64(BYTE FAR * wptr, EXAWORD v)
{
        int length=8;
        while ( length-- ) { *(wptr +length) = (v & 0x00FF); v >>= 8; }
        return;
}
int	main(int argc, char * argv[])
{
	EXAWORD	v;
	EXAWORD	i;
	BYTE	b[8];;
	printf("testing int 8 ...`\n");
	for ( i = 0; i < 0x100; i++ )
	{
		PutAbalInt8(b,i);
		if ( GetAbalInt8(b) != i )
		{
			printf("INT8 Whoops : %llu != %llu \n", GetAbalInt8(b), i);
			break;
		}
	}
	printf("testing int 16 ...`\n");
	for ( i = 0; i < 0x10000; i++ )
	{
		PutAbalInt16(b,i);
		if ( GetAbalInt16(b) != i )
		{
			printf("INT16 Whoops : %llu != %llu \n", GetAbalInt16(b), i);
			break;
		}
	}
	printf("testing int 32 ...`\n");
	for ( i = 0; i < 0x10000000; i++ )
	{
		PutAbalInt32(b,i);
		if ( GetAbalInt32(b) != i )
		{
			printf("INT32 Whoops : %llu != %llu \n", GetAbalInt32(b), i);
			break;
		}
	}
	printf("testing int 64 ...`\n");
	for ( i = 0; i < 0xFFFFFFFFFFFFFFFF; i++ )
	{
		PutAbalInt64(b,i);
		if ( GetAbalInt64(b) != i )
		{
			printf("INT64 Whoops : %llu != %llu \n", GetAbalInt64(b), i);
			break;
		}
	}
	printf("testing complete`\n");
	return(0);
}

