#include<stdio.h>
#include<stdlib.h>

#define ROWS 3
#define COLS 7

int main (void) {

    int * array1D = malloc(COLS * (sizeof(int)));
    int * array2D[ROWS];

    /* Allocating memory for array2D - allocate each row 
        each row is a pointer to an array of integers */
    for(int ii=0;ii<ROWS;ii++) {
        array2D[ii] = malloc(COLS * (sizeof(int)));
    }

    for(int ii=0;ii<COLS;ii++) {
        array1D[ii] = ii;      /* Can use array indexing for a pointer */
    }
    for(int ii=0;ii<ROWS;ii++) {
        for (int jj=0;jj<COLS;jj++) {
            array2D[ii][jj] = ii*10 + jj;
        }
    }

    printf("array1d: ");
    for(int ii=0;ii<COLS;ii++) {
        printf("%d ", *(array1D+ii));  /* Or I can use pointer arithmetic */
    }
    printf("\n");

    printf("array2D: \n");
    for(int ii=0;ii<ROWS;ii++) {
        for (int jj=0;jj<COLS;jj++) {
            printf("%3d ", array2D[ii][jj]);
        }
        printf("\n");
    }
    return 0;
}