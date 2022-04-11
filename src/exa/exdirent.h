typedef struct {
	int dirlog;
	long dirpos;
	} DIR;

extern	DIR *	opendir();
extern	long	telldir();
extern	void	seekdir();
extern	int	closedir();
extern 	struct dirent *readdir();

