#include<stdio.h>
#include<stdlib.h>

#define ROWS 4
#define COLS 3

int main (void) {

    /* Two-dimensional array */
    char arr1[ROWS][COLS];

    /* One-dimensional array that we treat like it is 2D */
    char arr2[ROWS*COLS];

    /* pointer to array of pointers */
    int ** ptr1;
    ptr1 = malloc(4 * sizeof (int *));      /* allocates an array of pointers to rows */
    for(int ii=0;ii<ROWS;ii++){ 
        ptr1[ii] = malloc(3 * sizeof(int)); /* allocates a row */
    }

    /* pointer to array of ints */
    int * ptr2;
    ptr2 = malloc(ROWS * COLS * sizeof(int));


    /* Note that for row r and col c, r * COLS + c is a unique number */
    
    /* Initialize & print array 1*/
    printf("Array 1:\n");
    for (int ii=0;ii<ROWS;ii++) {
        for(int jj=0;jj<COLS;jj++) {
            arr1[ii][jj]='A'+(ii*COLS)+jj;
            printf("%4c", (arr1[ii][jj]));
        }
        printf("\n");
    }

    /* Initialize & print array 2*/
    printf("\n");
    printf("Array 2:\n");
    for (int ii=0;ii<ROWS*COLS;ii++) {
        arr2[ii] = 'N' + ii;
        printf("%4c", (arr2[ii]));
        if(((ii+1) % COLS) == 0) {
            printf("\n");
        }
    }

    /* Initialize & print pointer 1*/
    printf("\n");
    printf("Pointer 1:\n");
    for (int ii=0;ii<ROWS;ii++) {
        for(int jj=0;jj<COLS;jj++) {
            ptr1[ii][jj]='A'+(ii*COLS)+jj;
            printf("%4c", (ptr1[ii][jj]));
        }
        printf("\n");
    }

    /* Initialize & print pointer 2*/
    printf("\n");
    printf("Pointer 2:\n");
    for (int ii=0;ii<ROWS*COLS;ii++) {
        ptr2[ii] = 'N' + ii;
        printf("%4c", (ptr2[ii]));
        if(((ii+1) % COLS) == 0) {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}