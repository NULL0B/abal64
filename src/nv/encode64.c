//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_encode_base64_c
#define _html_encode_base64_c

static	char Base64[64] =       {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
	};

int	encode_base64( char * rptr, char * sptr, int i )
{
	int	j=0;
	int	m=0;
	int	l=0;
	union _triochar
	{
		char Chars[3];
		struct _b6
		{
			unsigned long group3            : 6; // low order
			unsigned long group2            : 6;
			unsigned long group1            : 6;
			unsigned long group0            : 6; // high order
		} b6;
	} triochar;     

	while (j < i)	{		// processes the i chars from SMTPbuf

		if (j+3 <= i)  {	// there are 3 chars, from position j, to be processed
			triochar.Chars[2] = *( sptr + j); 
			triochar.Chars[1] = *( sptr + j+1);
			triochar.Chars[0] = *( sptr + j+2);
			*( rptr + (m++)) = Base64[triochar.b6.group0];
			*( rptr + (m++)) = Base64[triochar.b6.group1];
			*( rptr + (m++)) = Base64[triochar.b6.group2];
			*( rptr + (m++)) = Base64[triochar.b6.group3];
			j = j+3; l = l+3;
			}

		else if (j+2 == i) {	// the last two chars are j, j+1
			triochar.Chars[2] = *( sptr + j);
			triochar.Chars[1] = *( sptr + j+1);
			triochar.Chars[0] = '\0';
			*( rptr + (m++)) = Base64[triochar.b6.group0];
			*( rptr + (m++)) = Base64[triochar.b6.group1];
			*( rptr + (m++)) = Base64[triochar.b6.group2];
			*( rptr + (m++)) = '=';
			j = j+2; l = l+2;
			}

		else 	{		// the last char: j
			triochar.Chars[2] = *( sptr + j);
			triochar.Chars[1] = '\0';
			triochar.Chars[0] = '\0';
			*( rptr + (m++)) = Base64[triochar.b6.group0];
			*( rptr + (m++)) = Base64[triochar.b6.group1];
			*( rptr + (m++)) = '=';
			*( rptr + (m++)) = '=';
			j++; l++;
			}

		}
	*(rptr + m) = 0;
	return(m);
}


#endif	/* _html_encode_base64_c */



