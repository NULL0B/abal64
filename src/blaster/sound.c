void	(*feedback)(void)=0;

char	soundbuffer[MAX_BUFFER_SIZE];
int	bufferindex=0;

int	openoutput(char * device, int speed, int channels, int format, void * v)
{
	int	h;
	int	status;

	if ( sbecho )
		printf("open output : %s , %u, %u, %u \r\n",device,speed,channels,format);

	if (( h = open( device, O_WRONLY, 0)) == -1) {
		if ( sbecho )
			printf("error(%u): open(%s,O_WRONLY)\r\n",errno,device);
		return(h);
		}
#ifdef	SNDCTL_DSP_RESET
	else if ((status = ioctl(h,SNDCTL_DSP_RESET, 0 )) == -1) {
		if ( sbecho )
			printf("error(%u): ioctl(%s,DSP_RESET)\r\n",errno,device);
		close(h);
		return(status);
		}
#endif
#ifdef	SNDCTL_DSP_SETFMT
	else if ((status = ioctl(h,SNDCTL_DSP_SETFMT, &format )) == -1) {
		if ( sbecho )
			printf("error(%u): ioctl(%s,DSP_SETFMT,%u)\r\n",errno,device,format);
		close(h);
		return(status);
		}
#endif
#ifdef	SNDCTL_DSP_CHANNELS
	else if ((status = ioctl(h,SNDCTL_DSP_CHANNELS, &channels )) == -1) {
		if ( sbecho )
			printf("error(%u): ioctl(%s,DSP_CHANNELS,%u)\r\n",errno,device,channels);
		close(h);
		return(status);
		}
#endif
#ifdef	SNDCTL_DSP_SPEED
	else if ((status = ioctl(h,SNDCTL_DSP_SPEED, &speed )) == -1) {
		if ( sbecho )
			printf("error(%u): ioctl(%s,DSP_SPEED,%u)\r\n",errno,device,speed);
		close(h);
		return(status);
		}
#endif
	else	{
		feedback=v;
		bufferindex=0;
		return( h );
		}
}

#define	flushoutput(h)	{ 		\
	if ( bufferindex ) {			\
		if ( write(h,soundbuffer,bufferindex) != bufferindex)\
			printf("error(%u): write(%s,%u)\r\n",errno,bufferindex); \
		else if (feedback)		\
			(*feedback)();		\
		bufferindex =0;			\
		}				\
	}

#define	outputbyte(h, c ) { 		\
	if ( bufferindex >= MAX_BUFFER_SIZE ) {	\
		flushoutput(h);			\
		}				\
	soundbuffer[bufferindex++] = (c);		\
	}

#define	outputword(h, i ) { 		\
	outputbyte(h,((i) & 0x00FF)); 		\
	outputbyte(h,(((i)>>8) & 0x00FF)); 	\
	}

#define	outputlong(h, l ) { 		\
	outputword(h,((l) & 0xFFFF)); 		\
	outputword(h,(((l)>>16) & 0xFFFF));	\
	}

int	closeoutput( int h )
{
	if ( sbecho )
		printf("close output\r\n");
	flushoutput(h);
	feedback=0;
	close(h);
	return(-1);
}


