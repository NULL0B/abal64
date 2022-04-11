#ifndef	_wave_h
#define	_wave_h

#define	_FORMAT_NULL	0
#define	_FORMAT_WAVE	1
#define	_FORMAT_AIFF	2
#define	_FORMAT_MP3 	3
#define	_FORMAT_OGG 	4


struct	wave_handle	{

	struct wave_handle * 	next;
	FILE *			handle;
	char *			name;
	unsigned long		filesize;
	unsigned long		datasize;
	unsigned long		fileoffset;
	unsigned long		samples;
	int			nature;			/* WAVE : 0, AIFF : 1					*/
	int			format;
	unsigned short		formattag;		/* indicates compression	: 1 :	no compression 	*/
	unsigned short  	channels;		/* channel count interlaced				*/
	unsigned long		samplerate;		/* number of samples per sec				*/
	unsigned long		byterate;		/* average   bytes per sec				*/
	unsigned short		blockalign;		/* frame or block alignment				*/
	unsigned short		bitspersample;		/* bits per sample					*/
	void		*	complex;		/* pointer for other complex type, mp3, ogg etc		*/

	};

struct	wave_handle * 	close_wave_file( struct wave_handle * wptr );
struct	wave_handle *	open_wave_file( char * nptr );
void	show_wave_header( struct wave_handle * wptr );
struct	wave_handle *	allocate_wave_handle();
struct	wave_handle * 	terminate_wave_file( struct wave_handle * wptr );


#endif	/* _wave_h */
	/* ------- */






















