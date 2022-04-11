				/* test for member methods */
				/* ----------------------- */
				else if ( string_compare(&Token.buffer[i+1],"oncreate") )
					fprintf(h,"%u",iptr->Contents.x);
				else if ( string_compare(&Token.buffer[i+1],"onshow") )
					fprintf(h,"%u",iptr->Contents.x);
				else if ( string_compare(&Token.buffer[i+1],"ongetfocus") )
					fprintf(h,"%u",iptr->Contents.x);
				else if ( string_compare(&Token.buffer[i+1],"onlosefocus") )
					fprintf(h,"%u",iptr->Contents.x);
				else if ( string_compare(&Token.buffer[i+1],"onevent") )
					fprintf(h,"%u",iptr->Contents.x);
				else if ( string_compare(&Token.buffer[i+1],"onhide") )
					fprintf(h,"%u",iptr->Contents.x);
				else if ( string_compare(&Token.buffer[i+1],"onremove") )
					fprintf(h,"%u",iptr->Contents.x);


