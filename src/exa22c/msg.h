/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	MSG - H				*/
/*		Date 	:	08.07.1988				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef ExUserIpc		/* To avoid recursive inclusions */

#define	ExUserIpc		/* Inhibit further includes	 */

/*
 *	MSG.H		Copyright (c)	1988	Amenesik / Sologic s.a.
 *	-----		-------------------------------------
 *
 *	Date	08.07.1988
 *	------------------
 *
 *	Message queue control definitions
 *	---------------------------------
 *
 */

#ifndef	MsgHeaderInc		/* Test for already included		*/
#define	MsgHeaderInc		/* Avoid multiple inclusions		*/

#define	IPC_CREAT	0x08000	/* Create file if Open error = 40	*/
#define	IPC_EXCL	0x04000	/* Exclusive Access rights		*/
#define	IPC_NOWAIT	0x01000	/* Return with error (no sleep)		*/
#define	MSG_NOERROR	0x02000	/* Return and ignore errors		*/

#define	MSG_RMID	0x0020	/* Remove message queue 		*/
#define	MSG_STAT	0x0050	/* Read message queue control values	*/
#define	MSG_SET		0x0090	/* Rewrite message queue control values	*/

/*
 *	Message function prototypes
 *	---------------------------
 */

short int	msgget();	/* Open / Create message queue		*/
short int	msgsnd();	/* Send message to queue		*/
short int	msgrcv();	/* Recieve message from queue		*/
short int	msgctrl();	/* Message queue control options	*/
extern	void		death();	

/*
 *	General message structure
 *	-------------------------
 */

struct	msgbuf	{
	long	msgid;		/* Message identifier number		*/
	char	mstxt[2];	/* Message information data zone	*/
};


/*
 *	Message statistics structure
 *	----------------------------
 */

struct	msqid_ds {
	short int	msgmaxl;
	short int	msgmaxn;
	short int	msgcurn;
	short int	msgperm;
};

#endif
#endif
#ifdef AIX_VERS
ce = 0;
					printf("ermissions (E/R) :\nIPC_NOWAIT ? ");
					c = getch();
					if ( c == 0x000D ) { ipce |= IPC_NOWAIT; }
					printf("\nMSG_NOERROR ? ");
					c = getch();
					if ( c == 0x000D ) { ipce |= MSG_NOERROR; }
					printf("\nCurrent E/R permissions : %04.1X ",ipce);
					c = 'P';
					break;
			case    'Q' 	:
			case    'q' 	:
					c = 'Q';
					printf("uit\n"); break;
			case    0x001B 	:
					break;
			}
		if ( x != 0 ) { printf("\nErreur # %d ",x); }
		}
	while (( c != 0x001B ) && ( c != 'Q' ));
	}
while ( c != 'Q');
return(0);

}

/* 
 *	Ascii to Integer (Signed)
 *	-------------------------
 */

atoi(cp,len)
char	*cp;
int	len;
{
register int x;
	 int y;

x = 0;
if ( *cp == '-' ) { cp++; y = 1; } 
else { y = 0; }
while ( len > 0 ) {
	if (( *cp >= '0' ) && ( *cp <= '9' ) ) {
		x *= 10;
		x += ((int) *cp & 0x000F); len--; cp++;
		}
	else { break; }
	}
if ( y == 1 ) { x = -x; }
return(x);
}

getmsgno()
{
	char	*dzp;
	askbuf[0] = 7;
	dzp = cgets(askbuf);
	return( atoi( dzp, strlen(dzp) ) );

}
#endif /* AIX_VERS */
