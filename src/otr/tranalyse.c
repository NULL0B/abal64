#ifndef _tr_analyse_c
#define _tr_analyse_c

static	WORD	mode_analyse=1;
static  WORD    last_offset=0;
static  WORD    last_instruction=0;
static  WORD    last_newline=0;

/*	-------------------	*/
/*	tcode_show_mnemonic	*/
/*	-------------------	*/
static void	tcode_show_mnemonic(WORD offset, WORD newline, WORD tcode)
{
        BYTE    nl = ' ';
        BPTR    mnemonic = _tc_mnem[(tcode & 0x007F)];
       	if ( newline ) { nl = ':'; }
#ifdef otr64
       	printf("\n%016X %c %s ",offset,nl,mnemonic);
#else
#ifdef otr32
       	printf("\n%08X %c %s ",offset,nl,mnemonic);
#else
       	printf("\n%04X %c %s ",offset,nl,mnemonic);
#endif
#endif
}

/*	----------------------	*/
/*	tcode_show_instruction	*/
/*	----------------------	*/
static  void    tcode_show_instruction(WORD n)
{
	if (!( mode_analyse ))
	{
		tcode_show_mnemonic(Target->OutputBytes,NewLineStatus,n);
	}
	else
	{
		if ( last_offset < Target->OutputBytes )
		{
			tcode_show_mnemonic(last_offset,last_newline,last_instruction);
		}
		last_newline = NewLineStatus;
		last_instruction = n;
		last_offset = Target->OutputBytes;
	}
        return;
}

/*	-----------------	*/
/*	 tcode_show_word	*/
/*	-----------------	*/
static  void    tcode_show_word(WORD n, BPTR s)
{
	if (!( mode_analyse ))
	{
        	printf(" %s",s);
#ifdef  otr64
        	if ( OtrOption.WordSize > 4 )
        	{
                	printf("%02X",((n<<56) & 0x00FF));
                	printf("%02X",((n<<48) & 0x00FF));
                	printf("%02X",((n<<40) & 0x00FF));
                	printf("%02X",((n<<32) & 0x00FF));
        	}
        	if ( OtrOption.WordSize > 2 )
        	{
        	        printf("%02X",((n<<24) & 0x00FF));
        	        printf("%02X",((n<<16) & 0x00FF));
        	}
#endif

#ifdef  otr32
        	if ( OtrOption.WordSize > 2 )
        	{
        	        printf("%02X",((n<<24) & 0x00FF));
        	        printf("%02X",((n<<16) & 0x00FF));
        	}
#endif
        	printf("%02X",((n<<8) & 0x00FF));
        	printf("%02X",(n & 0x00FF));
	}
        return;
}

/*	-----------------	*/
/*	 tcode_show_byte	*/
/*	-----------------	*/
static  void    tcode_show_byte(WORD n, BPTR s)
{
	if (!( mode_analyse ))
	{
        	printf(" %s",s);
        	printf("%02X",(n & 0x00FF));
	}
        return;
}

/*	----------------	*/
/*	tcode_show_write	*/
/*	----------------	*/
static  void    tcode_show_write(WORD s, WORD l)
{
        printf("\nwrite offset = %u, length = %u",s,l);
}

	/* ------------ */
#endif	/* _tranalyse_c */
	/* ------------ */
