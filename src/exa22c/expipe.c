#define	EXAOPEN		1	/* Commande Test for Open Possible 	*/
#define	EXACLOSE	2	/* Commande Close the File	   	*/
#define	EXAKILL		4	/* Commande Liberate Job if Possible	*/

#define	SHARELOCK	1	/* Commande Sharelock requested		*/
#define	EXCLUSIVE	2	/* Commande Exclusive locking request	*/

struct exapipe {
	char	lock_cmd;	/* Command to be performed OP/CL/KL 	*/
	char	lock_mode;	/* Opening Mode to Attempt		*/
	int	lock_owner;	/* Process ID requesting Operation	*/
	long	lock_inode;	/* Unique INODE on			*/
	long	lock_dnode;	/* Unique Device			*/
	} bufpipe;		/* Global Structure			*/

struct	lokpipe {
	struct exapipe lock_info; /* Lock Informations			*/
	int    lock_ctrl;	  /* Number of access by same process	*/
	struct lokpipe *fwdptr;	  /* Liste Forward Pointer		*/
	struct lokpipe *bakptr;	  /* Liste Back Wards Pointer		*/
	}

int	idpipe;			/* Global Named Pipe File Handle	*/
int	lock_compt;		/* Number of Lock Structures		*/
struct	lokpipe * lock_liste;	/* Pointer to Liste of Locked Files	*/

static	char	PIPENOMEE[] = "/usr/lib/cico/.exapipe";

int	PipeWork()
{
	struct	lokpipe * wptr;
	struct	lokpipe * hptr;
	int	leng;

	/* Initialise Lock Liste Base Pointer */
	/* ---------------------------------- */	
	lock_liste = (struct lokpipe * ) 0;
	lock_compt = 0;

	/* Try and Create the Pipe */
	/* ----------------------- */
	if ( mknod(PIPENOMEE,S_IFIFO | 0666 , 0) != -1 ) {
		switch ( fork() ) {
			case 0 : /* Fils  */
				break;
			case -1: /* Error */
				return(errno);
			default: /* Pere  */
				return(sleep(1));
			}
		}
	else	{
		return(errno);
		}

	/* Only the Child Arrives Here */
	/* --------------------------- */
	if ( (idpipe = open(PIPENOMEE,O_RDWR)) == -1 ) {
		return( errno );
		}

	/* The Named Pipe is Open so Of We Go */
	/* ---------------------------------- */
	while ( 1 ) {
		do	{
			leng = read( idpipe , bufpipe , sizeof( struct exapipe ) );
			}
		while ( leng == 0 );
		if ( leng == sizeof(struct exapipe) ) {
			switch ( bufpipe.lock_cmd ) {
/* ========================================================================= */
				case EXAOPEN :	/* Request to Lock File */
						/* -------------------- */

x = 0; status = -1;
wptr = lock_liste;
hptr = wptr;
while ( x < lock_compt ) {
	/* Check for File Unique identifier Matching */
	/* ----------------------------------------- */
	if (( wptr->lock_info.lock_inode == bufpipe.lock_inode ) && ( wptr->lock_info.lock_dnode == bufpipe.lock_dnode )) {

		/* Check for Same Owner */
		/* -------------------- */
		if ( wptr->lock_info.lock_owner == bufpipe.lock_owner ) {

			/* Test for Exlusive Requested	    */
			/* -------------------------------- */
			if ( bufpipe.lock_mode == EXCLUSIVE ) {
				status = 0; /* Denied */
				}
			else	{
				if ( wptr->lock_info.lock_mode == EXCLUSIVE ) {
					status = 0; /* Shared Rejected */
					}
				else	{ /* Shared Accepted */
					wptr->lock_ctrl = wptr->ctrl + 1;
					status = 1;
					}
				}
			break;
			}
		else	{
			/* Not the Same Owner */
			/* ------------------ */
			if ( bufpipe.lock_mode == EXCLUSIVE ) {
				/* Exclusivity Demanded Rejected */
				/* ----------------------------- */
				status = 0;
				break;
				}
			/* Test for Already held EXCLUSIVE */
			/* ------------------------------- */
			if ( wptr->lock_info.lock_mode == EXCLUSIVE ) {
				/* Shared Mode Demanded Rejected */
				/* ----------------------------- */
				status = 0;
				break;
				}
			/* ---------------------------------------- */
			/* Arrival Here Means We Can Share the File */
			/* But First we must check to See if there  */
			/* is another record in the Liste for this  */
			/* File for This process		    */
			/* ---------------------------------------- */
			/* Scan Liste for Match Here		    */
			/* ---------------------------------------- */
			status = 1;
			break;
			}
		}
	else	{
		/* File Not Matching So Seek Next */
		x++;
		if ( x < lock_compt ) {
			hptr = wptr;
			wptr = wptr->fwdptr;
			}
		}
	if ( wptr == (struct lokpipe *) 0 ) {
		x = lock_compt;	/* Ensure Exit */
		status = -1;
		}
	}
select ( status ) {
	case 1 :	/* Succesful Completion nothing to Do 	*/
	case 0 :	/* Failure Nothing to Do		*/
		break;
	case -1:	/* Succesful completion add to End of 	*/
		if ( hptr == (struct lokpipe *) 0 ) {
			hptr = (struct lokpipe *) malloc ( sizeof(struct lokpipe) );
			if ( hptr == (struct lokpipe *) 0 ) {
				status = 0;
				}
			else	{
				lock_liste = hptr;
				hptr->fwdptr = (struct lokpipe *) 0;
				hptr->bakptr = (struct lokpipe *) 0;
				hptr->lock_ctrl = 1;
				memcpy(hptr->lock_info,bufpipe,sizeof(struct exapipe));
				status = 1;
				}
			}
		else	{
			wptr = (struct lokpipe *) malloc ( sizeof(struct lokpipe) );
			if ( wptr == (struct lokpipe *) 0 ) {
				status = 0;
				}
			else	{
				hptr->fwdptr = wptr;
				wptr->bakptr = hptr;
				wptr->fwdptr = (struct lokpipe *) 0;
				wptr->lock_ctrl = 1;
				memcpy(hptr->lock_info,bufpipe,sizeof(struct exapipe));
				status = 1;
				}
			}
				
	}
	break;

/* ========================================================================= */
				case EXACLOSE:	/* Request to Unlock File */
						/* ---------------------- */

				case EXAKILL :	/* Request to Liberate JOB */
						/* ----------------------- */

					close( idpipe );
					unlink(PIPENOMEE);
					exit(0);
			}

		/* Status 1 OK request Performed */
		/* ----------------------------- */
		bufpipe.lock_cmd   = status;
		/* If Status 0 then Return Errno */
		/* ----------------------------- */
		bufpipe.lock_owner = errno;
		/* Back Down The Pipe */
		/* ------------------ */
		write(idpipe,bufpipe,sizeof( struct exapipe ));
		}
	
}
