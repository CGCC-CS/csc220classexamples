#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"strings220.h"

#define BUFFERLEN 100

/* Strings read from the file may have a trailing newline this function 
     makes sure the first non-printable character is a NULL */
void strip_trailing_newline(char * str);

int main(int argc, char * argv[]) {

    char buffer[BUFFERLEN];
    char * filename;
    FILE *fp;

    /* Get the filename from the arguments */
    if ( argc < 2 ) {
        fprintf(stderr, "\nERROR: No input file specified!\n\n");
        exit(-1);
    }
    else {
        filename = argv[1];
    }

    /* Open the file */
    if ( (fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "\nERROR: Input file %s does not exist!\n\n", filename);
        exit(-1);
    }

    /* Call the test functions on each string in the file */
    int counter = 1;
    while (fgets(buffer, BUFFERLEN,fp)) {
        strip_trailing_newline(buffer);
        printf("string %d: \"%s\"\n", counter, buffer);
        strnlower(buffer, strlen(buffer));
        printf("   strnlower: [%s]\n", buffer);
        revnstr(buffer);
        printf("     revnstr: [%s]\n", buffer);
        printf("     strnsum: %d", strnsum((buffer), strlen(buffer)));
        printf("   alpha_count_char: %d\n", alpha_char_count(buffer));
        counter ++;
    }

    fclose(fp);
}

void strip_trailing_newline(char * str) {
   while (*str >= 32) {
       str++;
   }
   *str = '\0';
}