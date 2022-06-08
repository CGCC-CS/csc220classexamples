#ifndef STRINGS220_H
#define STRINGS220_H

/* Count the number of alpha characters in a string */
int alpha_char_count(char * str);

/* Return the sum of the ASCII values of each character in the string */
int strnsum(char * str, int len);

/* Convert a string to all lowercase */
void strnlower(char * str, int len);

/* Reverse the string in-place */
void revnstr(char * str);

#endif