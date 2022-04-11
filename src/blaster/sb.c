#ifndef	_soundblaster_c
#define	_soundblaster_c

#include "sb.h"

char	WorkBuffer[MAX_BUFFER_SIZE];
char	NameBuffer[256];
int	Queue=-1;
int	BlasterStatus=0;
int	BlasterJob=0;
int	ChildDeath=0;
int	ChildWriteHandle=-1;
int	ChildReadHandle=-1;
int	ReadHandle=-1;
int	WriteHandle=-1;
int	MixerHandle=-1;
int	SynthHandle=-1;
int	MixerMask=0;
int	MixerRecord=0;
int	outputhandle=-1;
unsigned long PlayStart=0L;
int	echogr=0;
int	sbecho=0;

#define	_DSP_DEVICE "/dev/dsp"
#define	_MIXER_DEVICE "/dev/mixer"
#define	_SEQUENCER_DEVICE "/dev/sequence"
static	char * target=(char *) 0;
static	char * mixer=(char *) 0;
static	char * synth=(char *) 0;

struct	wave_handle * 	Recording=(struct wave_handle *) 0;
struct	wave_handle *	Output=(struct wave_handle *) 0;
int			Tracks=0;
unsigned long		MaxSamples=0L;
struct	track_control	Track[MAX_TRACKS];

WORD	Audio_multi(WORD lvolume,WORD rvolume);

#include "wave.c"

#define	INTERFACE	


/*	------------------------------------	*/
/*	 g e t _ m i x e r _ h a n d l e ()	*/
/*	------------------------------------	*/
/*	opens and resets the FM Mixer Device
/*	------------------------------------	*/

static	int	get_mixer_handle()
{
	if (!( mixer ))
		return( MixerHandle );
	else if ( MixerHandle != -1 )
		return( MixerHandle );
	else if ((MixerHandle = open( mixer, O_RDWR, 0)) == -1)
		return( MixerHandle );
#ifdef	SOUND_MIXER_READ_RECMASK
	else if ( ioctl( MixerHandle, SOUND_MIXER_READ_RECMASK, &MixerMask ) == -1 )
		return( MixerHandle );
#endif
#ifdef	SOUND_MIXER_READ_RECSRC
	else if ( ioctl( MixerHandle, SOUND_MIXER_READ_RECSRC, &MixerRecord) == -1 )
		return( MixerHandle );
#endif
	else	{
		return( MixerHandle );
		}
}

/*	------------------------------------	*/
/*	 g e t _ s y n t h _ h a n d l e ()	*/
/*	------------------------------------	*/
/*	opens and resets the FM Synth Device
/*	------------------------------------	*/

static	int	get_synth_handle()
{
	if (!( synth ))
		return( SynthHandle );
	else if ( SynthHandle != -1 )
		return( SynthHandle );
	else if ((SynthHandle = open( synth, O_RDWR, 0)) == -1)
		return( SynthHandle );
	else	return( SynthHandle );
	
}

/*	-----------------------------------------	*/
/*		Signal Catcher Functions		*/
/*	-----------------------------------------	*/

/*	-----------------------------------------	*/
/*	This function receives feed back from an	*/
/*	exiting background play job process		*/
/*	-----------------------------------------	*/

void	childcatcher(int sigid)
{
	if ( sbecho )
		printf("ChildDeathEvent\r\n");
	ChildDeath=1;
	return;
}

/*	-----------------------------------------	*/
/*	This function provides signal reception		*/
/*	in back ground play mode allowing the job	*/
/*	to be aborted					*/
/*	-----------------------------------------	*/
void	playcatcher(int sigid)
{
	if ( ChildWriteHandle != -1 ) {
#ifdef	SNDCTL_DSP_SYNC
		ioctl(ChildWriteHandle,SNDCTL_DSP_SYNC,0);
#endif
		closeoutput(ChildWriteHandle);
		ChildWriteHandle = -1;
		}
	ChildWriteHandle = -1;
	exit(0);
}

/*	-----------------------------------------	*/
/*	This function provides signal reception		*/
/*	in back ground record mode allowing the job	*/
/*	to be aborted					*/
/*	-----------------------------------------	*/
void	recordcatcher(int sigid)
{
	if ( sbecho )
		printf("record catcher \r\n");
	if ( ChildReadHandle != -1 ) {
#ifdef	SNDCTL_DSP_SYNC
		ioctl(ChildReadHandle,SNDCTL_DSP_SYNC,0);
#endif
		close(ChildReadHandle);
		if ( Recording ) {
			Recording = terminate_wave_file( Recording );
			}
		}
	ChildReadHandle = -1;
	exit(0);
}

/*	-----------------------------------------------------------------	*/
/*	s u b m i t _ t r a c k ( number, filename, level, pan, options )	*/
/*	-----------------------------------------------------------------	*/
/*										*/
/*	Sets up the track controller for the specified track with the		*/
/*	provided wave file and play back information.				*/
/*										*/
/*	Returns the total number of samples to be played,(outside of any	*/
/*	subsequent looping) 							*/
/*	-----------------------------------------------------------------	*/

unsigned	long	submit_track( WORD number, BPTR nptr, WORD level, WORD pan, WORD options )
{
	struct	wave_handle * wptr;

	if ( sbecho )
		printf("submit_track(%u,%s,%u,%u,%u)\r\n",number,nptr,level,pan,options);

	if (!( wptr = open_wave_file( nptr ))) {
		return( 0 );
		}
	else	{
		if ( Track[(number-1)].sample )
			Track[(number-1)].sample = close_wave_file( Track[(number-1)].sample );
		Track[(number-1)].mute = (options&1);
		Track[(number-1)].loop = (options&2);
		Track[(number-1)].solo = 0;
		Track[(number-1)].pan  = pan;
		Track[(number-1)].left = 80-pan;
		Track[(number-1)].right = pan;
		Track[(number-1)].active=1;
		Track[(number-1)].level=level;
		Track[(number-1)].sample = wptr;
		if ( number > Tracks )
			Tracks = number;
		if ( wptr->samples > MaxSamples )
			MaxSamples = wptr->samples;
		if ( sbecho > 1 )
			show_wave_header( wptr );
		if ( sbecho )
			printf("Success : Tracks=%u, MaxSamples=%u \r\n",Tracks,MaxSamples);
		return(wptr->samples);
		}
}

/*	--------------------------------------		*/
/*	A b a l B l a s t e r _ s t a t u s ()		*/
/*	--------------------------------------		*/
/*							*/
/*	Resturns the current state of the sound		*/
/*	subsystem.					*/
/*		0 : IDLE				*/
/*		1 : SIMPLE PLAY				*/
/*		2 : MULTI  PLAY				*/
/*	--------------------------------------		*/

INTERFACE	WORD	Audio_status() 
{
	void	*	sigholder;
	int		status;
	int		result;
	if (( BlasterStatus ) && ( BlasterJob )) {
		if ( ChildDeath ) {
			if ((result = waitpid( BlasterJob, & status, 0 )) == BlasterJob) {
				if ( WIFEXITED(status) ) {
					status = WEXITSTATUS(status);
					BlasterJob=BlasterStatus=0;
					ChildDeath=0;
					}
				else if ( WIFSIGNALED(status) ) {
					status = WTERMSIG(status);	
					}
				}
			else	{
				ChildDeath=0;
				signal(SIGCLD,childcatcher);
				}
			}
		}
	return( BlasterStatus );
}

/*	------------------------------------		*/
/*	A b a l B l a s t e r _ r e s e t ()		*/
/*	------------------------------------		*/

WORD	Audio_reset()
{
	if ( sbecho )
		printf("Audio_reset(): \r\n",BlasterStatus);
	if (( BlasterJob ) && ( BlasterStatus )) {
		if ( sbecho )
			printf("..kill(%u)\r\n",BlasterJob);
		if ( kill(BlasterJob,SIGUSR1) == -1 ) {
			usleep(74);
			return(33);
			}
		else	{
			while (Audio_status()!=0) { usleep(74); }
			usleep(74);
			}
		}
	if ( WriteHandle != -1 ) {
		if ( sbecho )
			printf("close Write Handle\r\n");
		close( WriteHandle );
		WriteHandle = -1;
		}
	
	if ( ReadHandle != -1 ) {
		if ( sbecho )
			printf("close Read Handle\r\n");
		close( ReadHandle );
		ReadHandle = -1;
		}
	
	return( 0 );
}

/*	--------------------------------------------		*/
/*	A b a l B l a s t e r _ i n i t (p1,p2,p3)		*/
/*	--------------------------------------------		*/

WORD	Audio_init(WORD p1,WORD p2,WORD p3)
{
	char 	buffer[256];
	sprintf(buffer,"%s%u",_DSP_DEVICE,p1&3);
	if (!( target = malloc( strlen( buffer ) + 1 )))
		return(27);
	else	strcpy(target,buffer);
	sprintf(buffer,"%s%u",_MIXER_DEVICE,p1&3);
	if (!( mixer = malloc( strlen( buffer ) + 1 )))
		return(27);
	else	strcpy(mixer,buffer);
	sprintf(buffer,"%s%u",_SEQUENCER_DEVICE,p1&3);
	if (!( synth = malloc( strlen( buffer ) + 1 )))
		return(27);
	else	strcpy(synth,buffer);
	BlasterJob = BlasterStatus = ChildDeath = 0;
	MixerHandle = -1;
	SynthHandle = -1;
	WriteHandle = -1;
	ReadHandle = -1;
	ChildWriteHandle = -1;
	ChildReadHandle = -1;
	return( 0x2040 );
}

WORD	Audio_liber()
{
	if (( BlasterJob ) && ( BlasterStatus ))
		Audio_reset();

	if ( target ) {
		free( target );
		target = (char *) 0;
		}

	if ( mixer ) {
		free( mixer );
		mixer = (char *) 0;
		}

	if ( synth ) {
		free( synth );
		synth = (char *) 0;
		}

	return( 0 );
}

WORD	Audio_putb(WORD p)
{
	return( 0 );
}

WORD	Audio_putz(WORD p,BPTR bptr)
{
	return( 0 );
}

/*	--------------------------------------------		*/
/*	A b a l B l a s t e r _ s e n d (n, buffer )		*/
/*	--------------------------------------------		*/

WORD	Audio_send(WORD n,BPTR bptr)
{
	int	mode=0;
	int	status=0;

	/* Attempt to open output device */
	/* ----------------------------- */
	if ( WriteHandle == -1 )  {
		if (!( target ))
			return( 56 );
		else if (( WriteHandle = open( target, O_WRONLY, 0)) == -1)
			return(200);
		}
	/* Write to output device */
	/* ---------------------- */
	else if ((status =write(WriteHandle,bptr,n)) != n) {
		return(202);
		}
	return( 0 );
}

/*	--------------------------------------------		*/
/*	A b a l B l a s t e r _ t e m p o (n,c,b) 		*/
/*	--------------------------------------------		*/

WORD	Audio_tempo(WORD n,WORD c,WORD b)
{
	int	speed=n;
	int	mode=0;
	int	status=0;
	int	channels=c;
	int	format=b;
	speed *= (_SAMPLE_RATE/302);

	if (  b <= 8) {
#ifdef	AFMT_U8
		format = AFMT_U8;
#else
		format = 0;
#endif		
		}
	else if ( b <= 16 ) {
#ifdef	AFMT_S16_LE
		format = AFMT_S16_LE;
#else
		format = 0;
#endif		
		}
	else if ( b <= 24 ) {
#ifdef	AFMT_S24_LE
		format = AFMT_S24_LE;
#else
		format = 0;
#endif		
		}
	else if ( b <= 32 ) {
#ifdef	AFMT_S32_LE
		format = AFMT_S32_LE;
#else
		format = 0;
#endif		
		}
	else	{
#ifdef	AFMT_U8
		format = AFMT_U8;
#else
		format = 0;
#endif		
		}

	/* Attempt to open output device */
	/* ----------------------------- */
	if ( WriteHandle == -1 ) {
		if (!( target ))
			return(56);
		else if (( WriteHandle = open( target, O_WRONLY, 0)) == -1)
			return(200);
		}
#ifdef	SNDCTL_DSP_RESET
	else if ((status = ioctl(WriteHandle,SNDCTL_DSP_RESET, 0 )) == -1) {
		return(201);
		}
#endif
#ifdef	SNDCTL_DSP_SETFMT
	else if ((status = ioctl(WriteHandle,SNDCTL_DSP_SETFMT, &format )) == -1) {
		return(202);
		}
#endif
#ifdef	SNDCTL_DSP_CHANNELS
	else if ((status = ioctl(WriteHandle,SNDCTL_DSP_CHANNELS, &channels )) == -1) {
		return(203);
		}
#endif
#ifdef	SNDCTL_DSP_SPEED
	else if ((status = ioctl(WriteHandle,SNDCTL_DSP_SPEED, &speed )) == -1) {
		return(204);
		}
#endif

	if  ( ReadHandle == -1 ) {
		if (!( target ))
			return( 56 );
		else if (( ReadHandle = open( target, O_RDONLY, 0)) == -1) 
			return(200);
		}
#ifdef	SNDCTL_DSP_RESET
	else if ((status = ioctl(ReadHandle,SNDCTL_DSP_RESET, 0 )) == -1) {
		return(201);
		}
#endif
#ifdef	SNDCTL_DSP_SETFMT
	else if ((status = ioctl(ReadHandle,SNDCTL_DSP_SETFMT, &format )) == -1) {
		return(202);
		}
#endif
#ifdef	SNDCTL_DSP_CHANNELS
	else if ((status = ioctl(ReadHandle,SNDCTL_DSP_CHANNELS, &channels )) == -1) {
		return(203);
		}
#endif
#ifdef	SNDCTL_DSP_SPEED
	else if ((status = ioctl(ReadHandle,SNDCTL_DSP_SPEED, &speed )) == -1) {
		return(204);
		}
#endif
	return( 0 );
}

WORD	Audio_recv(WORD n,BPTR bptr)
{
	int	mode=0;
	int	status=0;

	/* Attempt to open output device */
	/* ----------------------------- */
	if ( ReadHandle == -1 ) {
		if (!( target ))
			return( 56 );
		else if (( ReadHandle = open( target, O_RDONLY, 0)) == -1)
			return(200);
		}
	/* Write to output device */
	/* ---------------------- */
	else if ((status =read (ReadHandle,bptr,n)) != n) {
		if ( sbecho )
			printf("read error %u\r\n",errno);
		return(202);
		}
	return( 0 );
}

WORD	Audio_getz(WORD p,BPTR bptr)
{
	return( 0 );
}

WORD	Audio_getb()
{
	return( 0 );
}

WORD	Audio_sound(WORD p)
{
	return( 0 );
}

WORD	Audio_dmastate()
{
	return( 0 );
}


/*	--------------------------------------------		*/
/*	A b a l B l a s t e r _ a l s m (buffer,nb )		*/
/*	--------------------------------------------		*/

WORD	Audio_alsm(BPTR bptr,WORD p)
{
	char ** pptr;
	char *	rptr;
	rptr = malloc( (p*16) );
	*(bptr++)=3;
	pptr = (char **) bptr;
	*pptr= rptr;
	return( 0 );
}

/*	--------------------------------------------		*/
/*	A b a l B l a s t e r _ l b s m ( buffer )		*/
/*	--------------------------------------------		*/

WORD	Audio_lbsm(BPTR bptr) 
{
	char ** pptr;
	char *	rptr;
	if ( *(bptr++) != 0 ) {
		pptr = (char **) bptr;
		rptr = *pptr;
		free( rptr );
		rptr = (char *) 0;
		*pptr = rptr;
		bptr--;
		*bptr = 0;
		}
	return( 0 );
}


/*	--------------------------------------------		*/
/*	A b a l B l a s t e r _ g e t m i x (p1, p2)		*/
/*	--------------------------------------------		*/

WORD	Audio_getmix(WORD p)
{
	int	h;
	int	v=0;
	int	r=0;
	if ((h = get_mixer_handle()) == -1)
		return( 200 );

	switch ( p ) {
		case		__SB_RECORD_SOURCE	:	// 0x000C
#ifdef	SOUND_MIXER_READ_RECSRC
			if ( ioctl( MixerHandle, SOUND_MIXER_READ_RECSRC, &MixerRecord) == -1 )
				return( 201 );
			if ( MixerRecord & 0x0040 )
				r = 0x0002;
			else if ( MixerRecord & 0x0080 )
				r = 0x0004;
			else if ( MixerRecord & 0x0100 )
				r = 0x0006;
			else	r = 0x0004;

			return( r );
#else
			return(56);
#endif

		case		__SB_VOICE_LEVEL	:	// 0x0004
#ifdef	SOUND_MIXER_PCM
			if (ioctl(h,MIXER_READ(SOUND_MIXER_PCM),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif


		case		__SB_MIC_LEVEL		:	// 0x000A	MIC
#ifdef	SOUND_MIXER_MIC
			if (ioctl(h,	MIXER_READ(SOUND_MIXER_MIC),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif

		case		__SB_MASTER_LEVEL	:	// 0x0022
#ifdef	SOUND_MIXER_VOLUME
			if (ioctl(h,	MIXER_READ(SOUND_MIXER_VOLUME),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif

		case		__SB_FM_LEVEL		:	// 0x0026
#ifdef	SOUND_MIXER_LINE2
			if (ioctl(h,	MIXER_READ(SOUND_MIXER_LINE2),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif

		case		__SB_CD_LEVEL		:	// 0x0028 	CD
#ifdef	SOUND_MIXER_CD
			if (ioctl(h,	MIXER_READ(SOUND_MIXER_CD),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif

		case		__SB_LINE_LEVEL		:	// 0x002E	LINE
#ifdef	SOUND_MIXER_LINE1
			if (ioctl(h,	MIXER_READ(SOUND_MIXER_LINE1),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif


		}
	r = ((((v & 0x00FF)*15)/100) | (((((v & 0xFF00) >> 8)*15)/100)<<4));
	return( r );
}

/*	--------------------------------------------		*/
/*	A b a l B l a s t e r _ p u t m i x (p1, p2)		*/
/*	--------------------------------------------		*/

WORD	Audio_putmix(WORD p1,WORD p2)
{
	int	h;
	int	v;

	if ((h = get_mixer_handle()) == -1)
		return( 200 );
	else	v = ((((p2 & 0x00F)*100)/15) | (((((p2 & 0x00F0) >> 4)*100)/15)<<8));

	switch ( p1 ) {
		case		__SB_RECORD_SOURCE	:	// 0x000C
			switch ((p2 & 0x0006) >> 1) {
				case	0	:
				case	2	: v = 0x0080; break;
				case	1	: v = 0x0040; break;
				case	3	: v = 0x0100; break;
				}
			MixerRecord = v;
#ifdef	SOUND_MIXER_WRITE_RECSRC
			if ( ioctl( MixerHandle, SOUND_MIXER_WRITE_RECSRC, &MixerRecord) == -1 )
				return( 201 );
			else	break;
#else
			return(56);
#endif


		case		__SB_VOICE_LEVEL	:	// 0x0004
#ifdef	SOUND_MIXER_PCM
			if (ioctl(h,MIXER_WRITE(SOUND_MIXER_PCM),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif



		case		__SB_MIC_LEVEL		:	// 0x000A
#ifdef	SOUND_MIXER_MIC
			if (ioctl(h,	MIXER_WRITE(SOUND_MIXER_MIC),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif


		case		__SB_MASTER_LEVEL	:	// 0x0022
#ifdef	SOUND_MIXER_VOLUME
			if (ioctl(h,	MIXER_WRITE(SOUND_MIXER_VOLUME),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif


		case		__SB_FM_LEVEL		:	// 0x0026
#ifdef	SOUND_MIXER_LINE2
			if (ioctl(h,	MIXER_WRITE(SOUND_MIXER_LINE2),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif


		case		__SB_CD_LEVEL		:	// 0x0028
#ifdef	SOUND_MIXER_CD
			if (ioctl(h,	MIXER_WRITE(SOUND_MIXER_CD),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif


		case		__SB_LINE_LEVEL		:	// 0x002E
#ifdef	SOUND_MIXER_LINE1
			if (ioctl(h,	MIXER_WRITE(SOUND_MIXER_LINE1),&v)==-1)
				return(201);
			else	break;
#else
			return(56);
#endif



		}
	return( 0 );
}

/*	-------------------------------------------		*/
/*	A b a l B l a s t e r _ p u t o p l   ( p )		*/
/*	-------------------------------------------		*/

WORD	Audio_putopl(WORD p1,WORD p2)
{
	int	h;
	if ((h = get_synth_handle()) == -1 )
		return(200);

	return( 0 );
}

/*	-------------------------------------------		*/
/*	A b a l B l a s t e r _ o p l n o t e ( p )		*/
/*	-------------------------------------------		*/

WORD	Audio_oplnote(WORD p1,WORD p2,WORD p3,WORD p4)
{
	int	h;
	if ((h = get_synth_handle()) == -1 )
		return(200);
	return( 0 );
}

/*	-------------------------------------------		*/
/*	A b a l B l a s t e r _ o p l m o d e ( p )		*/
/*	-------------------------------------------		*/

WORD	Audio_oplmode(WORD p1,WORD p2)
{
	int	h;
	if ((h = get_synth_handle()) == -1 )
		return(200);
	return( 0 );
}

/*	-------------------------------------------		*/
/*	A b a l B l a s t e r _ o p l c t r l ( p )		*/
/*	-------------------------------------------		*/

WORD	Audio_oplctrl(WORD p)
{
	int	h;
	if ((h = get_synth_handle()) == -1 )
		return(200);
	return( 0 );
}

#define	failure(n) if ( mode ) { exit(n); } else { status = n; }

WORD	track_message(BPTR nptr)
{
	int	status=0;
	struct	control_message Message;
	if ( sbecho )
		printf("track_message(%s)\r\n",nptr);

	Message.type = 1L;
	Message.track= 0;
	Message.item = 0;
	Message.value= 0;
	Message.extra= 0;
	strcpy(Message.nomfic,nptr );

	if ( Queue == -1) {
		return(56); 
		}
	else if ( msgsnd(Queue,&Message,sizeof( struct control_message ),IPC_NOWAIT) != -1 )
		return(0);
	else	return(55);
}

static	int	add_new_track( BPTR nptr )
{
	int	i;
	for ( i=0; i < MAX_TRACKS; i++ ) {
		if (!( Track[i].sample ))
			break;
		else if (!( Track[i].active ))
			break;
		}
	if ( sbecho )
		printf("add_new_track(%u,%s)\r\n",i+1,nptr);
	if ( i < MAX_TRACKS ) {
		submit_track( (i+1), nptr, 80, 50, 0 );
		return((i+1));
		}
	else	return(0);
}

/*	-----------------------------------------------------------	*/
/*	A b a l B l a s t e r _ p l a y f i l e (filename, length )	*/
/*	-----------------------------------------------------------	*/
WORD	ComplexPlay( char * nptr )
{
	int	i;
	if ( BlasterStatus == 2 ) {
		track_message( nptr );
		}
	else if ( add_new_track( nptr ) != 0 ) {
		Audio_multi(80,80);
		}
	return(0);
}



WORD	Audio_playfile(BPTR filename, WORD namelen, WORD mode)
{
	FILE * h;
	int	speed=_SAMPLE_RATE;
	int	reset=0;
	int	format=0;
	int	channels=0;
	int	status=0;
	int	o;
	int	c,n;
	int	i;
	long	total=0L;
	struct	wave_handle * wptr;

	if (( BlasterStatus ) || ( BlasterJob )) {
		if ( mode != 2 )
			return( 204 );
		}
	else	ChildDeath=0;

	for (i=0; i < namelen; i++ )
		if ((NameBuffer[i] =  *(filename+i)) <= ' ' )
			break;

	NameBuffer[i] = 0;
	
	if ( sbecho )
		printf("Audio_playfile(%s,%u)\r\n",NameBuffer,mode);

	if ( mode != 2 )
		PlayStart = time((unsigned long*)0);

	/* Test for background operation */
	/* ----------------------------- */
	switch ( mode ) {
		case	2 :	
			return( ComplexPlay( NameBuffer ) );

		case	1 :
#ifdef	UNIX
		/* Allow signal catching */
		/* --------------------- */
		signal(SIGCLD,childcatcher);

		switch ((BlasterJob = fork())) {
			case	-1	:	return( 203 );
			case	 0	:	break;
			default		:	

				if ( sbecho )
					printf("Play Job : %u : Active\r\n",BlasterJob);
				BlasterStatus=1;
				return( 0 );
			}
#else
		return( 203 );
#endif
		}


		
	/* Attempt to open source file */
	/* --------------------------- */
	if (!( wptr = open_wave_file( NameBuffer ) )) {
  		failure(40);
		}

	else 	{

		speed  	= wptr->samplerate;
		format  = wptr->format;
		channels= wptr->channels;

		if ( sbecho )	
			printf("Playing Wave file %s : %u, %u, %u \r\n",NameBuffer,speed,format,channels);

		if (!( target ))
			failure( 56 );

		/* Attempt to open output device */
		/* ----------------------------- */
		if (( o  = open( target, O_WRONLY, 0)) == -1) {
			failure(200);
			}
		/* Change sample rate */
		/* ------------------ */
#ifdef	SNDCTL_DSP_RESET	
		else if ((status = ioctl(o,SNDCTL_DSP_RESET, 0 )) == -1) {
			failure(201);
			}
#endif
#ifdef	SNDCTL_DSP_SETFMT
		else if ((status = ioctl(o,SNDCTL_DSP_SETFMT, &format )) == -1) {
			failure(202);
			}
#endif
#ifdef	SNDCTL_DSP_CHANNELS
		else if ((status = ioctl(o,SNDCTL_DSP_CHANNELS, &channels )) == -1) {
			failure(203);
			}
#endif
#ifdef	SNDCTL_DSP_SPEED
		else if ((status = ioctl(o,SNDCTL_DSP_SPEED, &speed )) == -1) {
			failure(204);
			}
#endif
		else	{
			/* Allow signal catching */
			/* --------------------- */
			ChildWriteHandle = o;
			signal(SIGUSR1,playcatcher);

			if ( sbecho )	
				printf("read/write till end of file\r\n");
			/* Read from source */
			/* ---------------- */
			while ((n = read_wave_block(wptr, WorkBuffer, MAX_BUFFER_SIZE )) > 0) {

				/* Write to output device */
				/* ---------------------- */
				if ((status =write(o,WorkBuffer,n)) != n) {
					failure(205);
					break;
					}
				else	{
					total += n;
					}
				}
			/* Close output */
			/* ------------ */
			close(o);
			ChildWriteHandle = -1;
			}
		
		/* Close Source */
		/* ------------ */
		close_wave_file(wptr);		
		if ( sbecho )	
			printf("end of play function\r\n");

		}
	if ( mode ) {
		exit( status );
		}
	else	return( status );
}

/*	--------------------------------------------------------	*/
/*	A b a l B l a s t e r _ r e c o r d ( filename, length )	*/
/*	--------------------------------------------------------	*/
#ifdef	failure
#undef 	failure
#endif

void	failure(n) 
{
	if ( sbecho )
		printf("\r\n record failure : %u\r\n",n);
	exit(n); 
}

WORD	Audio_record(BPTR filename, WORD namelen, WORD speed, WORD format, WORD channels)
{
	FILE * h;
	int	reset=0;
	int	status=0;
	int	o;
	int	c,n;
	int	i;
	long	total=0L;
	struct	wave_handle * wptr;

	if ( sbecho )
		printf("Audio_record \r\n");

	if (( BlasterStatus ) || ( BlasterJob ))
		return( 204 );
	else	ChildDeath=0;

	for (i=0; i < namelen; i++ )
		if ((NameBuffer[i] =  *(filename+i)) <= ' ' )
			break;

	NameBuffer[i] = 0;

#ifdef	UNIX
	/* Allow signal catching */
	/* --------------------- */
	signal(SIGCLD,childcatcher);

	switch ((BlasterJob = fork())) {
		case	-1	:	return( 203 );
		case	 0	:	break;
		default		:	
			BlasterStatus=1;
			return( 0 );
		}
#else
	return( 203 );
#endif

		
	/* Attempt to open source file */
	/* --------------------------- */
	if (!( wptr = create_wave_file( NameBuffer, speed, format, channels ) )) {
  		exit(46);
		}

	else 	{

		speed  	= wptr->samplerate;
		format  = wptr->format;
		channels= wptr->channels;

		if ( sbecho )
			printf("record attempt :speed=%u, format=%u, channels=%u\r\n",speed,format,channels);

		if (!( target ))
			failure( 56 );

		/* Attempt to open output device */
		/* ----------------------------- */
		if (( o  = open( target, O_RDONLY, 0)) == -1) {
			failure(200);
			}
		/* Change sample rate */
		/* ------------------ */
#ifdef	SNDCTL_DSP_RESET
		else if ((status = ioctl(o,SNDCTL_DSP_RESET, 0 )) == -1) {
			failure(201);
			}
#endif
#ifdef	SNDCTL_DSP_SETFMT
		else if ((status = ioctl(o,SNDCTL_DSP_SETFMT, &format )) == -1) {
			failure(202);
			}
#endif
#ifdef	SNDCTL_DSP_CHANNELS
		else if ((status = ioctl(o,SNDCTL_DSP_CHANNELS, &channels )) == -1) {
			failure(203);
			}
#endif
#ifdef	SNDCTL_DSP_SPEED
		else if ((status = ioctl(o,SNDCTL_DSP_SPEED, &speed )) == -1) {
			failure(204);
			}
#endif
		else	{
			if ( sbecho )
				printf("record params  :speed=%u, format=%u, channels=%u\r\n",speed,format,channels);
			/* Allow signal catching */
			/* --------------------- */
			ChildReadHandle = o;
			Recording = wptr;
			signal(SIGUSR1,recordcatcher);

			/* Read from source */
			/* ---------------- */
			while (1) {
				if  ((n = read( ChildReadHandle,WorkBuffer,MAX_BUFFER_SIZE)) <= 0)
					break;
				else if ((status = fwrite(WorkBuffer,1,n,wptr->handle)) <= 0 )
					break;
				else	wptr->datasize += n;
				}
			/* Close output */
			/* ------------ */
			close(o);
			ChildWriteHandle = -1;
			}
		
		/* Close Source */
		/* ------------ */
		Recording = (struct wave_handle *) 0;
		terminate_wave_file(wptr);		

		}
	exit( status );
}

void	initialise()
{
	int	i;
	if ( sbecho )
		printf("blaster::initialise()\r\n");
	for ( i=0; i < Tracks; i++ ) {
		Track[i].name   = (char *) 0;
		Track[i].sample = (struct wave_handle *) 0;
		Track[i].solo=0;
		Track[i].loop=0;
		Track[i].mute=0;
		Track[i].left=0;
		Track[i].right=0;
		Track[i].level=0;
		Track[i].active=1;
		}
	Output=(struct wave_handle *) 0;
	Queue = msgget(53,IPC_CREAT);
	if (!( getenv("SBECHO")))
		sbecho=0;
	else	sbecho=1;
	Tracks=0;
	return;
}

void	terminate()
{
	int	i;

	if ( sbecho )
		printf("blaster::terminate()\r\n");

	for ( i=0; i < Tracks; i++ ) {
		if (!( Track[i].sample ))
			continue;
		else	Track[i].sample = close_wave_file( Track[i].sample );
		}
	if ( outputhandle != -1 )
		outputhandle = closeoutput( outputhandle );
	if ( Output )
		Output = terminate_wave_file( Output );
	if ( Queue != -1 ) {
		msgctl(Queue,IPC_RMID,(void*)0);
		Queue = -1;
		}
	Tracks=0;
	return;
}

unsigned long	Audio_track(WORD number, BPTR filename, WORD namelen, WORD level,WORD pan, WORD mute )
{
	int	i;
	for (i=0; i < namelen; i++ ) {
		if ( (i+1) < MAX_BUFFER_SIZE ) {
			if (!( WorkBuffer[i] = *(filename+i) ))
				break;
			else if ( WorkBuffer[i] == ' ' )
				break;
			}
		else	break;
		}
	WorkBuffer[i] = 0;
	if ( sbecho )
		printf("Audio_track(%u,%s,%u)\r\n",number,WorkBuffer,level);
	if ( number >= MAX_TRACKS )
		return( 0 );
	else	return( submit_track( number, WorkBuffer, level,pan, mute ) );
}

static	int	tone_generator( int * buffer, int buflen, int value )
{
	int	i;
	int	v;
	int	a=0;
	int	s;
	int	n;
	int	qc=buflen/4;
	value = 100-value;
	v = value-50;
	if ( sbecho )
		printf("calculate_graphic_eq(samples=%u, value=%u, v=%d)\r\n",buflen,value,v);
	*buffer = 0;
	if (!( v ))
		return(0);
	v = ((0x7FFF*v)/100);
	for ( i=0; i < qc; i++ ) {
		n = ((v*i) / qc);
		*(buffer+i) = n;
		*(buffer+((qc*2)-i)) = n;
		*(buffer+i+(qc*2)) = -n;
		*(buffer+(buflen-i)) = -n;
		}
	return( buflen );;
}

static	int	calculate_graphic_eq( int * buffer, int buflen, int value )
{
	int	i;
	int	v;
	int	a=0;
	int	s;
	int	n;
	int	qc=buflen/4;
	value = 100-value;
	v = value-50;
	if ( sbecho )
		printf("calculate_graphic_eq(samples=%u, value=%u, v=%d)\r\n",buflen,value,v);
	*buffer = 0;
	if (!( v ))
		return(0);
	for ( i=0; i < qc; i++ ) {
		n = ((v*i) / qc);
		*(buffer+i) = n;
		*(buffer+((qc*2)-i)) = n;
		*(buffer+i+(qc*2)) = -n;
		*(buffer+(buflen-i)) = -n;
		}
	return( buflen );;
}

static	int	use_control_message( struct control_message * mptr )
{
	if (!( mptr->track )) {
		/* Master volume control */
		switch ( mptr->item ) {

			case	0 :	/* Contents	*/
				add_new_track( mptr->nomfic );
				return(0);
			case	1 :	/* left  volume */
				Master.left = mptr->value;
				return(0);
			case	2 :	/* right volume */
				Master.right = mptr->value;
				return(0);
			case	3 :	/* left graphic */
				if (( mptr->extra > 0 ) && ( mptr->extra < 10 )) {
					Master.graphic[(mptr->extra-1)][0] = mptr->value;
					switch ( mptr->extra ) {
						case	1 :	Master.eql.max50    = calculate_graphic_eq(Master.eql.hz50,_MAX_50,mptr->value); 	break;
						case	2 :	Master.eql.max100   = calculate_graphic_eq(Master.eql.hz100,_MAX_100,mptr->value); 	break;
						case	3 :	Master.eql.max200   = calculate_graphic_eq(Master.eql.hz200,_MAX_200,mptr->value); 	break;
						case	4 :	Master.eql.max400   = calculate_graphic_eq(Master.eql.hz400,_MAX_400,mptr->value); 	break;
						case	5 :	Master.eql.max800   = calculate_graphic_eq(Master.eql.hz800,_MAX_800,mptr->value); 	break;
						case	6 :	Master.eql.max1600  = calculate_graphic_eq(Master.eql.hz1600,_MAX_1600,mptr->value); 	break;
						case	7 :	Master.eql.max3200  = calculate_graphic_eq(Master.eql.hz3200,_MAX_3200,mptr->value); 	break;
						case	8 :	Master.eql.max6400  = calculate_graphic_eq(Master.eql.hz6400,_MAX_6400,mptr->value); 	break;
						case	9 :	Master.eql.max12800 = calculate_graphic_eq(Master.eql.hz12800,_MAX_12800,mptr->value); break;
						}
					}
				else if ( mptr->extra == 10 )
					Master.eql.mute=mptr->value;
	
				return(0);
			case	4 :	/* right graphic*/
				if (( mptr->extra > 0 ) && ( mptr->extra < 10 )) {
					Master.graphic[(mptr->extra-1)][1] = mptr->value;
					switch ( mptr->extra ) {
						case	1 :	Master.eqr.max50    = calculate_graphic_eq(Master.eqr.hz50,_MAX_50,mptr->value); 	break;
						case	2 :	Master.eqr.max100   = calculate_graphic_eq(Master.eqr.hz100,_MAX_100,mptr->value); 	break;
						case	3 :	Master.eqr.max200   = calculate_graphic_eq(Master.eqr.hz200,_MAX_200,mptr->value); 	break;
						case	4 :	Master.eqr.max400   = calculate_graphic_eq(Master.eqr.hz400,_MAX_400,mptr->value); 	break;
						case	5 :	Master.eqr.max800   = calculate_graphic_eq(Master.eqr.hz800,_MAX_800,mptr->value); 	break;
						case	6 :	Master.eqr.max1600  = calculate_graphic_eq(Master.eqr.hz1600,_MAX_1600,mptr->value); 	break;
						case	7 :	Master.eqr.max3200  = calculate_graphic_eq(Master.eqr.hz3200,_MAX_3200,mptr->value); 	break;
						case	8 :	Master.eqr.max6400  = calculate_graphic_eq(Master.eqr.hz6400,_MAX_6400,mptr->value); 	break;
						case	9 :	Master.eqr.max12800 = calculate_graphic_eq(Master.eqr.hz12800,_MAX_12800,mptr->value); break;
						}
					}
				else if ( mptr->extra == 10)
					Master.eqr.mute=mptr->value;
				return(0);
			}
		}
	else	{
		/* Track control */
		switch ( mptr->item ) {
			case	1 :	/* mute  */
				Track[(mptr->track-1)].mute = mptr->value&1;
				Track[(mptr->track-1)].loop = mptr->value&2;
				return(0);
			case	2 :	/* pan   */
				Track[(mptr->track-1)].left  = (80-mptr->value);
				Track[(mptr->track-1)].right = mptr->value;
				return(0);
			case	3 :	/* level */
				Track[(mptr->track-1)].level = mptr->value;
				return(0);
			}
		}
	return(30);
}

int	postflush()
{
	long	Type=1L;
	struct	control_message Message;
	if ( Queue != -1 ) {
		while ( msgrcv(Queue,&Message,sizeof( struct control_message ),Type,IPC_NOWAIT) != -1 ) {
			if ( sbecho )
				printf("message received : track=%u, item=%u, value=%u\r\n",Message.track,Message.item,Message.value);
			if ( use_control_message( &Message ) )
				break;
			}
		}
	return(0);
}

void	equalise(int * lptr, int * rptr )
{
	register int 	lsample=*lptr;
	register int 	rsample=*rptr;
	int	lbefore=lsample;
	int	rbefore=rsample;
	if (!( Master.eql.mute )) {
		if (Master.eql.ech50 >= Master.eql.max50 )
			Master.eql.ech50=0;
		lsample += Master.eql.hz50[Master.eql.ech50++];
		if (Master.eql.ech100 >= Master.eql.max100 )
			Master.eql.ech100=0;
		lsample += Master.eql.hz100[Master.eql.ech100++];
		if (Master.eql.ech200 >= Master.eql.max200 )
			Master.eql.ech200=0;
		lsample += Master.eql.hz200[Master.eql.ech200++];
		if (Master.eql.ech400 >= Master.eql.max400 )
			Master.eql.ech400=0;
		lsample += Master.eql.hz400[Master.eql.ech400++];
		if (Master.eql.ech800 >= Master.eql.max800 )
			Master.eql.ech800=0;
		lsample += Master.eql.hz800[Master.eql.ech800++];
		if (Master.eql.ech1600 >= Master.eql.max1600 )
			Master.eql.ech1600=0;
		lsample += Master.eql.hz1600[Master.eql.ech1600++];
		if (Master.eql.ech3200 >= Master.eql.max3200 )
			Master.eql.ech3200=0;
		lsample += Master.eql.hz3200[Master.eql.ech3200++];
		if (Master.eql.ech6400 >= Master.eql.max6400 )
			Master.eql.ech6400=0;
		lsample += Master.eql.hz6400[Master.eql.ech6400++];
		if (Master.eql.ech12800 >= Master.eql.max12800 )
			Master.eql.ech12800=0;
		lsample += Master.eql.hz12800[Master.eql.ech12800++];
		}
	*lptr = lsample;
	if (!( Master.eqr.mute )) {
		if (Master.eqr.ech50 >= Master.eqr.max50 )
			Master.eqr.ech50=0;
		rsample += Master.eqr.hz50[Master.eqr.ech50++];
		if (Master.eqr.ech100 >= Master.eqr.max100 )
			Master.eqr.ech100=0;
		rsample += Master.eqr.hz100[Master.eqr.ech100++];
		if (Master.eqr.ech200 >= Master.eqr.max200 )
			Master.eqr.ech200=0;
		rsample += Master.eqr.hz200[Master.eqr.ech200++];
		if (Master.eqr.ech400 >= Master.eqr.max400 )
			Master.eqr.ech400=0;
		rsample += Master.eqr.hz400[Master.eqr.ech400++];
		if (Master.eqr.ech800 >= Master.eqr.max800 )
			Master.eqr.ech800=0;
		rsample += Master.eqr.hz800[Master.eqr.ech800++];
		if (Master.eqr.ech1600 >= Master.eqr.max1600 )
			Master.eqr.ech1600=0;
		rsample += Master.eqr.hz1600[Master.eqr.ech1600++];
		if (Master.eqr.ech3200 >= Master.eqr.max3200 )
			Master.eqr.ech3200=0;
		rsample += Master.eqr.hz3200[Master.eqr.ech3200++];
		if (Master.eqr.ech6400 >= Master.eqr.max6400 )
			Master.eqr.ech6400=0;
		rsample += Master.eqr.hz6400[Master.eqr.ech6400++];
		if (Master.eqr.ech12800 >= Master.eqr.max12800 )
			Master.eqr.ech12800=0;
		rsample += Master.eqr.hz12800[Master.eqr.ech12800++];
		}
	*rptr = rsample;
	if ( echogr )
		printf("eq: %d,%d -> %d,%d \r\n",lbefore,rbefore,lsample,rsample);
}

int	directaction()
{
	struct 	wave_handle * wptr;
	int	level;
	int	lv;
	int	rv;
	int	i;
	int	v;
	int	lsample,rsample;

	if ( sbecho )
		printf("directaction()\r\n");
	if (!( Tracks )) {
		if ( sbecho )
			printf("no tracks to be played : %s \r\n","output.wav");
		return(0);
		}
	if (!( target ))
		return( 56 );
	if (!( Output = create_wave_file( "output.wav", _SAMPLE_RATE,2,2 ) )) {
		if ( sbecho )
			printf("error creating wave file : %s \r\n","output.wav");
		return(27);
		}
	else if ((outputhandle = openoutput(target,Output->samplerate,Output->channels,Output->format,postflush)) == -1) {
		if ( sbecho )
			printf("error opening output device : %s \r\n",target);
		return(56);
		}

	ChildWriteHandle = outputhandle;
	signal(SIGUSR1,playcatcher);
	while (1) {
		lsample=rsample=0;
		for (i=0; i < Tracks; i++ ) {
			if (!( Track[i].active ))
				continue;
			else if (!( wptr = Track[i].sample ))
				continue;

			else if (!( get_wave_sample( wptr, &lv, &rv ) )) {
				if (!( Track[i].loop )) 
					Track[i].active=0;
				else	{
					submit_track( (i+1), wptr->name, Track[i].level, Track[i].pan, Track[i].loop );
					}
				}
			else	{
				if (!( Track[i].mute )) {
					lv = ((lv * Track[i].left)/80);
					lsample += ((lv * Track[i].level)/80);
					}
				if (!( Track[i].mute )) {
					rv = ((rv * Track[i].right)/80);
					rsample += ((rv * Track[i].level)/80);
					}
				}
			}
		lsample = ((lsample * Master.left) / 100);
		rsample = ((rsample * Master.right) / 100);

		equalise(&lsample,&rsample);

		put_wave_sample( Output, outputhandle, lsample, rsample );

		}
	if ( sbecho )
		printf("closing output device : %s \r\n",target);
	closeoutput(outputhandle);
	ChildWriteHandle = -1;
	return(0);

}

WORD	Audio_control(WORD track, WORD item, WORD value, WORD extra )
{
	int	status=0;
	struct	control_message Message;
	if ( sbecho )
		printf("Audio_control(%u,%u,%u,%u)\r\n",track,item,value,extra);
	Message.type = 1L;
	Message.track= track;
	Message.item = item;
	Message.value= value;
	Message.extra= extra;
	if ((status = use_control_message( &Message )) != 0)
		return(status );
	else if ( BlasterStatus != 2 )
		return(0);
	else if ( Queue == -1 ) { 
		return(56); 
		}
	else if ( msgsnd(Queue,&Message,sizeof( struct control_message ),IPC_NOWAIT) != -1 )
		return(0);
	else	return(55);
}


WORD	Audio_multi(WORD lvolume,WORD rvolume)
{
	int	status=0;

	if ( sbecho )
		printf("Audio_multi(%u,%u) : tracks %u \r\n",lvolume,rvolume,Tracks);

	if (( BlasterStatus ) || ( BlasterJob ))
		return( 204 );
	else	ChildDeath=0;

	Master.left=lvolume;
	Master.right=rvolume;

	Master.eql.ech50   = Master.eql.ech100  =
	Master.eql.ech200  = Master.eql.ech400  =
	Master.eql.ech800  = Master.eql.ech1600 =
	Master.eql.ech3200 = Master.eql.ech6400 =
	Master.eql.ech12800= 0;

	Master.eqr.ech50   = Master.eqr.ech100  =
	Master.eqr.ech200  = Master.eqr.ech400  =
	Master.eqr.ech800  = Master.eqr.ech1600 =
	Master.eqr.ech3200 = Master.eqr.ech6400 =
	Master.eqr.ech12800= 0;

	
	PlayStart = time((unsigned long*)0);

	/* Test for background operation */
	/* ----------------------------- */
#ifdef	UNIX
	/* Allow signal catching */
	/* --------------------- */
	signal(SIGCLD,childcatcher);

	switch ((BlasterJob = fork())) {
		case	-1	:	return( 203 );
		case	 0	:	break;
		default		:	
			if ( sbecho )
				printf("Audio_multi : Active \r\n");
			BlasterStatus=2;
			return( 0 );
		}
#else
	return( 203 );
#endif
	if ( sbecho )
		printf("background play staring\r\n",status);
	status = directaction();
	if ( sbecho )
		printf("background play exit(%u)\r\n",status);
	exit(status);
}

WORD	Audio_info()
{
	return(0);
}

/* DLL Pattern Management */
/* ---------------------- */

static	char 	LaPaterne[16] = { 
	'*','P','R','L','@','I','N','F','O','*',
	'#',3,
	__DRIVER_MAJOR,__DRIVER_MINOR,__DRIVER_INDEX,
	0 };

static	char *	LaPointeur=(char*)0;
static	char 	LaVersion[8];
char *	getpatternversion()
{
	if (!( LaPointeur )) {
		LaVersion[0] = LaPaterne[12];
		LaVersion[1] = '.';
		LaVersion[2] = LaPaterne[13];
		LaVersion[3] = LaPaterne[14];
		LaVersion[4] = 0;
		LaPointeur = LaVersion;
		}
	return( LaPointeur );

}

/* ------------------ */
/* DLL initialisation */
/* ------------------ */
VOID FAR PTR InitRelais()
{ 
	int	i;
	if (rt_init != (VOID FAR PTR) 0L)
		rt_init->ordinaire.signature = BDA_ORDINAIRE;

	desrt.banniere = (VOID (FAR PTR)()) banniere;
	desrt.fin = (VOID (FAR PTR)()) terminate;
	desrt.nombre = 26;

#ifdef vms

	for ( i=0; i < 26; i++ )
		desrt.nom[i] 	= (BYTE FAR PTR) "_BlasterBidon";



	/* ----- */
#else 	/* ! vms */
	/* ----- */

	desrt.reserve = (VOID FAR PTR) 0L;
	desrt.fonction[0] = (WORD (FAR PTR)()) Audio_init;
	desrt.fonction[1] = (WORD (FAR PTR)()) Audio_liber;
	desrt.fonction[2] = (WORD (FAR PTR)()) Audio_putb;
	desrt.fonction[3] = (WORD (FAR PTR)()) Audio_putz;
	desrt.fonction[4] = (WORD (FAR PTR)()) Audio_send;
	desrt.fonction[5] = (WORD (FAR PTR)()) Audio_status;
	desrt.fonction[6] = (WORD (FAR PTR)()) Audio_reset;
	desrt.fonction[7] = (WORD (FAR PTR)()) Audio_tempo;
	desrt.fonction[8] = (WORD (FAR PTR)()) Audio_recv;
	desrt.fonction[9] = (WORD (FAR PTR)()) Audio_getz;
	desrt.fonction[10] = (WORD (FAR PTR)()) Audio_getb;
	desrt.fonction[11] = (WORD (FAR PTR)()) Audio_sound;
	desrt.fonction[12] = (WORD (FAR PTR)()) Audio_dmastate;
	desrt.fonction[13] = (WORD (FAR PTR)()) Audio_alsm;
	desrt.fonction[14] = (WORD (FAR PTR)()) Audio_lbsm;
	desrt.fonction[15] = (WORD (FAR PTR)()) Audio_getmix;
	desrt.fonction[16] = (WORD (FAR PTR)()) Audio_putmix;
	desrt.fonction[17] = (WORD (FAR PTR)()) Audio_putopl;
	desrt.fonction[18] = (WORD (FAR PTR)()) Audio_oplnote;
	desrt.fonction[19] = (WORD (FAR PTR)()) Audio_oplmode;
	desrt.fonction[20] = (WORD (FAR PTR)()) Audio_oplctrl;
	desrt.fonction[21] = (WORD (FAR PTR)()) Audio_playfile;
	desrt.fonction[22] = (WORD (FAR PTR)()) Audio_record;
	desrt.fonction[23] = (WORD (FAR PTR)()) Audio_track;
	desrt.fonction[24] = (WORD (FAR PTR)()) Audio_multi;
	desrt.fonction[25] = (WORD (FAR PTR)()) Audio_control;
	desrt.fonction[26] = (WORD (FAR PTR)()) Audio_info;


#endif /* vms */

	initialise();

	return((VOID FAR PTR) &desrt);

}

/* ---------------------- */
/* Library identification */
/* ---------------------- */
static VOID FAR banniere()
{ 
	printf("\n   Abal Sound Driver : %s ",__DRIVER_NAME);
	printf("\n   Version %s ",getpatternversion());
	printf("\n   Provisoire du %s ",__DRIVER_DATE);
	printf("\n   Copyright (c) 2000 Amenesik / Sologic \n");
	return;
}

#endif	/* _soundblaster_c */



