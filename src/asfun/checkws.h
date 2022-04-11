#ifdef 	EXAWORD
#define	CheckWordSize( m ) printf("\r\n%s(xws=%u,gws=%u)\r\n",m,sizeof( EXAWORD ),sizeof( WORD ));
#else 
#define	CheckWordSize( m ) printf("\r\n%s(xws=???,gws=%u)\r\n",m,sizeof( WORD ));
#endif


