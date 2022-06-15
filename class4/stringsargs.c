#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUM 10

/* Returning a string from a function */
char * update_string(char * str, int len) {
    /* Allocate a new string with size len + the null terminator*/
    char * newstr = malloc((len+1) * sizeof(char));
    int ii=0;
    /* change ' ' to _, s to $, a to @, h to # */
    while ( (ii < len) && (str[ii] != '\0')) {
        if (str[ii] == ' ') { newstr[ii] = '_'; }
        else if (str[ii] == 's') { newstr[ii] = '$'; }
        else if (str[ii] == 'a') { newstr[ii] = '@'; }
        else if (str[ii] == 'h') { newstr[ii] = '#'; }
        else { newstr[ii] = str[ii];}
        ii++;
    }
    newstr[ii] = '\0';
    return newstr;
}

int main(int argc, char * argv[]) {

    int a = NUM;
    int b = 0;
    char * executable_name;

    /* Strings & char pointers */
    char original_string[] = "Test hash";
    char * another_string = "Yet another test!";
    char * updated_string;

    /* Copying an argument to a pointer */
    executable_name = argv[0];
    printf("\nYou executed program %s\n", executable_name);

    printf("There were %d command line arguments:\n", argc);
    for (int ii=0;ii<argc;ii++) {
        printf("  %d: %s\n", ii, argv[ii]);
    }

    /* Get an integer parameter */
    if (argc > 1) {
        b = atoi(argv[1]);
    }
    else {
        fprintf(stderr, "You dont have enough arguments\n");
    }

    printf("a + b = %d\n", a+b);

    /* This is a memory leak! */     
    printf("\"This is a test string!\" changes to \"%s\"\n", 
         update_string("This is a test string!", 22));  /* String is 22 characters long */
    
    updated_string = update_string(original_string, strlen(original_string));
    printf("\"%s\" changes to \"%s\"\n", original_string, updated_string);
    free(updated_string);  /* no memory leak! */

    updated_string = update_string(another_string, strlen(another_string));
    printf("\"%s\" changes to \"%s\"\n", another_string, updated_string);
    free(updated_string);  /* no memory leak! */

    return 0;
}