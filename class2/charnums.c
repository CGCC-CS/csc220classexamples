#include<stdio.h>

/* Function declared before use, so we don't need a forward declaration */
void print_first_n_letters(int count) {
    for (int ii=0;ii<count;ii++) {
        printf("%c ", 'A' + ii);   /* 'A'+1 is 'B', +4 is 'D', and so on */
    }
    printf("\n");
}

int main(void) {
    char string_of_nums[] = "3428"; /* 5 characters: 3-4-2-8-NULL */
    int sum = 0;

    printf("string_of_nums: \"%s\"\n", string_of_nums);
    printf("\n");
    /* print the characters */
    printf("individual characters:\n");
    for (int ii=0;ii<5;ii++) {
        /* Print the character (%c) & ASCII decimal (%d) value of each character */
        printf("  string_of_num[%d] = %c [%d]\n", ii, string_of_nums[ii], 
                                                    string_of_nums[ii]);
    }
    printf("\n");

    /* sum of values */
    for (int jj=0;jj<5;jj++) {
        sum += string_of_nums[jj];
    }
    printf("Sum of characters = %d\n", sum);


    sum=0;
    /* subtracting the character literal '0' from a number character 
        * converts it to its integer equvialent.  For example:
        *     '7' - '0' = 7 since
        *      55 -  48 = 7 ('7' is 55 ASCII, '0' is 48 ASCII)
        */
    for (int jj=0;jj<4;jj++) {  /* don't include the NULL! */
        sum += string_of_nums[jj] - '0';
    }
    printf("Sum of characters - '0' = %d\n", sum);

    printf("\n");
    printf("Print first N letters:\n");
    printf("3: ");
    print_first_n_letters(3);
    printf("17: ");
    print_first_n_letters(17);
    printf("37: ");
    print_first_n_letters(37);  /* Prints characters after end of alphabet */
    return 0;
    return 0;
}
