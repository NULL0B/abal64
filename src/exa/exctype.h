/*
 *	definitions standards pour la classification des caracteres
 *	
 *	Bibliotheque d'exploitation du C sous Amenesik / Sologic - Version 1.1x -
 *		(C) 1987 Copyright Amenesik / Sologic s.a. 
 *
 */

#define isalpha(c) (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 0 : 1)
#define isdigit(c) ((c >= '0' && c <= '9') ? 0 : 1)
#define isxdigit(c) ((( c >= 'A' && c <= 'F') || (c >= 'a' && c<= 'f')) ? 0 : 1)
#define isprint(c) (c >= ' ' && c <= '~')
#define isalnum(c) (isalpha(c) || isdigit(c))
#define isupper(c) (c >= 'A' && c <= 'Z')
#define islower(c) (c >= 'a' && c <= 'z')
#define isspace(c) ((c == ' ' || c == '\t' || c == '\n') ? 0 : 1)
#define iscntrl(c) (((c >= (char) 0 && c <= (char) 31) || c == (char) 127) ? 0 : 1)
#define ispunct(c) ((isprint(c) && !isalnum(c)) ? 0 : 1)
#define isascii(c) ((unsigned)(c) <= 127)
#define iscsym(c)  (isalnum(c)||(((c)&127)==0x5F))
#define iscsymf(c) (isalpha(c)||(((c)&127)==0x5F))
#define toupper(c) ((c >= 'a' && c <= 'z') ? (c - ('a' - 'A')) : (c))
#define toascii(c) ((c) & 0x7F)
#define tolower(c) ((c >= 'A' && c <= 'Z') ? (c - ('A' - 'a')) : (c))

