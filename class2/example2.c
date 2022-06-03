#include<stdio.h>

void print_numbers(int limit);  /* Forward declaration (or prototype) */

int main(void) {
    int num = 44;       /* Integer variable */
    int hexnum = 0x44;  /* Integer variable & hexidecimal literal */
    double val = 123.456;  /* Floating-point variable */
    char ch = 'A';      /* Character variable */

    int a=7, b=20, c;   /* Three integer variables declare */
    c = a + b;

    int numbers[] = {2, 5, 8, 10, 20};   /* Array of 5 integers */
    int multiples[10];                  /* Array of 10 integers */

    char str[] = "A string";  /* Character array */

    /* Initialize an integer array */
    for (int ii=0;ii<10;ii++) {
        multiples[ii] = (ii+1) * 10;
    }

    printf("CSC220 Class 2 Examples\n");
    printf("\n");

    /* print variable s*/
    printf("a=%d b=%d c=%d\n", a, b, c); 
    printf("num: %d %o %X\n", num, num, num);  /* %d - decimal,  %o - octal */
    printf("hexnum: %d %o %X\n", hexnum, hexnum, hexnum);  /* %X - hexdecimal */
    printf("val: %f %.1f\n", val, val);  /*%.1f - print 1 decimal place */
    printf("\n");

    /* char is an integer type */
    printf("ch: %c %d %X\n", ch, ch, ch);  /* %c - character */
    printf("ch+1: %c %d %X\n", ch+1, ch+1, ch+1); 
    printf("'M': %c %d %X\n", 'M', 'M', 'M'); 
    printf("75: %c %d %X\n", 75, 75, 75); 

    /* Print each element of an array */
    printf("\n");
    printf("Array \"numbers\" : ");
    for(int ii=0;ii<5;ii++) {
        printf("[%d]=%d ", ii, numbers[ii]);
    }
    printf("\n");
    printf("Array \"multiples\" : ");
    for(int ii=0;ii<10;ii++) {
        printf("[%d]=%d ", ii, multiples[ii]);
    }

    /* Print a string */
    printf("str: %s\n", str);   /* %s - string */
    printf("str[3]: %c %d %X\n", str[3], str[3], str[3]);
    printf("\n");

    /* Calling a function */
    printf("print_numbers(12): ");
    print_numbers(12);
    printf("\n");
    printf("print_numbers(a): ");
    print_numbers(a);
    printf("\n");
    printf("print_numbers(numbers[2]): ");
    print_numbers(numbers[2]);
    printf("\n");
    for(int kk=1;kk<20;kk+=3) {  /* For loops can start at 1, skip 3 */
        printf("  %d: ", kk);
        print_numbers(kk);
        printf("\n");
    }

    return 0;
}

void print_numbers(int limit) {
    for(int jj=1; jj<=limit; jj++) {
        printf("%d ", jj);
    }
}