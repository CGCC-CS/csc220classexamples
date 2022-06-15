#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Returning a string from a function */
char * update_string(char * str, int len) {
    /* Allocate a new string - len + the null terminator */
    char * newstr = malloc ((len+1) * sizeof(char));
    int ii=0;
    /* Change ' ' to _, s to $, a to @, h to # */
    while ( (ii<len) && (str[ii] != '\0')) {
        /* Don't forget: chars are surrounded by single quotes
             'a' -> char
             "a" -> string literal
        */
        newstr[ii] = str[ii];
        if (str[ii] == ' ') { newstr[ii] = '_'; } 
        if (str[ii] == 's') { newstr[ii] = '$'; } 
        if (str[ii] == 'a') { newstr[ii] = '@'; } 
        if (str[ii] == 'h') { newstr[ii] = '#'; } 
        ii++;
    }
    newstr[ii] = '\0';
    return newstr;
}

int main(int argc, char * argv[]) {
    
    char * first_arg;

    /* Two examples - string in a character array & a pointer to a string literal */
    char original_string[] = "Test hash";
    char * another_string = "Yet another test!";
    char * updated_string;

    /* Command line arguments */
    printf ("There were %d command line arguments: \n", argc);
    for (int ii=0;ii<argc;ii++) {
        printf("  %d: %s\n", ii, argv[ii]);
    }

    /* Copying an argument to a pointer */
    if (argc > 1) {
        first_arg = argv[1];
        printf("The first argument is %s\n", first_arg);
    }

    /* Note that the next line of code throws away the value of the pointer 
         creating a memory leak! 
    printf("\"This is a test string for update_string()!\" changes to \"%s\"\n", 
             update_string("This is a test string for update_string()!", 43));
    */

    updated_string = update_string(original_string, strlen(original_string));
    printf("\"%s\" changes to \"%s\"\n", original_string, updated_string);
    free(updated_string);  /* Now no memory leak! */

    updated_string = update_string(another_string, strlen(another_string));
    printf("\"%s\" changes to \"%s\"\n", another_string, updated_string);
    free(updated_string);  /* Now no memory leak! */

    /* Unprintable characters */
    char * chars = "Hello";
    char morechars[6];
    printf("\n");
    for (int ii=0;ii<5;ii++) {
         morechars[ii] = chars[ii] - 100;
    }
    morechars[5] = '\0'; /* don't forget the null terminator! */
    printf("chars: %s\n", chars);
    printf("morechars: %s\n", morechars);
    for (int ii=0;ii<6;ii++) {
        printf("\t%d=[%c]\t\t%d=[%c]\n", chars[ii], chars[ii], morechars[ii], morechars[ii]);
    }
    printf("\n");

    /* Character literals are integers */
    printf("Using character literal '7':\n");
    int val = 'A' * '7';
    printf("%c * %c = %d\n", 'A', '7', val);
    printf("%d * %d = %d\n", 'A', '7', val);
    printf("\n");
    printf("Using integer literal 7:\n");
    val = 'A' * 7;
    printf("%d * %d = %d\n", 'A', 7, val);

    return 0;
}