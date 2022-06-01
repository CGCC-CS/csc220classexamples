#include<stdio.h>

int main(void) {

    /* Declaring variables */
    int number = 10;
    double percent = 32.348;
    char level = 'A';

    /* Printing variables */
    printf("number=%d\n", number);
    printf("percent=%.2f\n", percent);
    printf("level=%c\n", level);
 
    /* In just one line */
    printf("number=%d percent=%.2f level=%c \n", number, percent, level);

    return(0);
}