#ifndef	_sfc_c
#define	_sfc_c

static	int	configuration_ready=0;

static	struct	flfile_configuration {
	int	permissions;
	int	caseconversion;
	int	memorysize;
	char	username[72];
	char	groupname[72];
	} FlFileConfig = { 
		0, 0, 0
		};

static	char	cmd[1024];

static	int	flfile_read_integer(FILE * h)
{
	int	c;
	int	v=0;
	while ((c = fgetc(h)) > 0) {
		if ((c >= '0' )&&(c <= '7' ))
			v = ((v * 8) + (c - '0'));
		else	break;
		}
	return(v);
}

static	int	flfile_read_string(FILE * h,char * nptr, int nlen)
{
	int	c;
	int	i=0;
	while ((c = fgetc(h)) > 0) {
		if ((( c >= 'a' )
		&&  ( c <= 'z' ))
		|| (( c >= 'A' )
		&&  ( c <= 'Z' ))
		||  ( c == '_' )
		||  ( c == '.' )) {
			if ( i < nlen ) {
 				*(nptr+i) = c;
				i++;
				continue;
				}
			}
		break;
		}
	*(nptr+i) = 0;
	return(i);
}

static	void	flfile_read_configuration()
{
	FILE * 	h;
	int	c;
	int	v;

	configuration_ready=1;

	FlFileConfig.groupname[0] = 0;
	FlFileConfig.username[0]  = 0;

	if (!(h = fopen("/etc/criteria.cfg","r")))
		return;
	else	{	
	        while ((c = fgetc(h)) > 0) {
           		if ( (c == ' ') ||  (c == '\n') ||  (c == '\r') ||  (c == '\t') )
                		continue;
            		else if ( c == '#' ) {
				/* scan past comment to end of line */
				/* -------------------------------- */
		                while ((c = fgetc(h)) > 0) if ( c == '\n' ) break;
				/* if not end of line : end of file */
				/* -------------------------------- */
				if ( c == '\n' ) continue; else break;
				}
			else if ( c != '-' ) {
				/* its not an option ! */
				/* ------------------- */
				break;
				}
			else	{
				if ((c = fgetc(h)) < 0)
					break;
				switch (c) {

					case    'l' :
					case    'L' :
						FlFileConfig.caseconversion = 'L';
						continue;						

					case    'u' :
					case    'U' :
						FlFileConfig.caseconversion = 'U';
						continue;						

					case    's' :
					case    'S' :
						FlFileConfig.memorysize = flfile_read_integer(h);
						continue;						

					case    'g' :
					case    'G' :
						flfile_read_string( h,FlFileConfig.groupname, 64 );
						continue;						

					case    'o' :
					case    'O' :
						flfile_read_string( h,FlFileConfig.username, 64 );
						continue;						

					case	'p' :
					case	'P' :
						FlFileConfig.permissions = flfile_read_integer(h);
						continue;
					default :
						break;
					}
				break;
				}
			}
		fclose(h);
		}
	return;
}

int	flfile_set_permissions( char * nptr )
{
	if (!( configuration_ready ))
		flfile_read_configuration();
	if ( FlFileConfig.permissions )
		return( chmod( nptr, FlFileConfig.permissions ) );
	else	return( 0 );
}

int	flfile_get_permissions()
{
	if (!( configuration_ready ))
		flfile_read_configuration();
	return( FlFileConfig.permissions );
}

static	int	flfile_set_owner_group( char * nptr )
{
	if (!( configuration_ready ))
		flfile_read_configuration();
	if ( strlen(FlFileConfig.groupname) != 0 ) {
		sprintf(cmd,"chgrp %s %s 2>/dev/null",FlFileConfig.groupname,nptr);
		system( cmd );
		}
	if ( strlen(FlFileConfig.username)  != 0 ) {
		sprintf(cmd,"chown %s %s 2>/dev/null",FlFileConfig.username,nptr);
		system( cmd );
		}
	return(0);
}

#endif	/* _sfc_c */
	/* ------ */

