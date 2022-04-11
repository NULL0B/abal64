#ifndef	_decode64_c
#define	_decode64_c

#include "decode64.h"

signed short int DecodeBase64(
	char FAR * sOutput ,
	char FAR * sInput, 
	unsigned short int l)
{
	signed short int iError = OK, i, j;

	union _triochar {
		char Chars[3];
		struct _b6 {
			unsigned long group3		: 6; // low order
			unsigned long group2		: 6;
			unsigned long	group1		: 6;
			unsigned long	group0		: 6; // high order
			} b6;
		} triochar;	

	if ((l % 4) != 0) 
		return(0);

	else	{
	  	for(	j=0,i=0; 
			i < l; 
			i += 4) {
			if (((FromBase64[sInput[i]]   == BB64C) 
			||   (FromBase64[sInput[i+1]] == BB64C) 
			||   (FromBase64[sInput[i+2]] == BB64C) 
			||   (FromBase64[sInput[i+3]] == BB64C)) 
			||  (sInput[i]   == '=') 
			||  (sInput[i+1] == '=')
			||  ((sInput[i+2] == '=') && (sInput[i+3] != '=')) 
			||  ((sInput[i+2] == '=') && (sInput[i+3] == '=') && ((i+4) != l))
			||  ((sInput[i+3] == '=') && ((i+4) != l))) 
				return(0);

			triochar.b6.group0 = FromBase64[sInput[i]];
			triochar.b6.group1 = FromBase64[sInput[i+1]];
			triochar.b6.group2 = FromBase64[sInput[i+2]];
			triochar.b6.group3 = FromBase64[sInput[i+3]];
			sOutput[j] = triochar.Chars[2];
			j++;
			if (sInput[i + 2] != '=')
				sOutput[j++] = triochar.Chars[1];
			if (sInput[i + 3] != '=')
				sOutput[j++] = triochar.Chars[0];
			}
		}
	return(j);
}

#endif	// _decode64_h


