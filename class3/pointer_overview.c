#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Pointer examples:
 *   - introduction
 *   - struct pointers
 *   - array pointers
 *   - pointer & array function parameters
 *   - void pointers
 *   - double pointers
 */

#define LEN 10

typedef struct {
    int num;
    char name[LEN];
} mystruct_t;

/* This assumes str has 6 characters! */
void print_string_array(char str[]) {
    printf("print_string_array: %s\n", str);
    printf("  %c %c %c\n", str[0], str[1], str[2]);
    printf("  %c %c %c\n", *(str+3), *(str+4), *(str+5));
}

void print_string_pointer(char * ptr) {
    printf("print_string_pointer: %s\n", ptr);
    printf("  %c %c %c\n", *(ptr+0), *(ptr+1), *(ptr+2));
    printf("  %c %c %c\n", ptr[3], ptr[4], ptr[5]);
}

void change_pointer(void ** into, void * what) {
    *into = what;
}

int main(void) {

    int abc = 100;
    int nums[LEN];

    int * iptr = &abc;
    int * ptr = nums;  

    char hello[] = "Hello, World!";
    char * alpha = "ABCDEFGHIJK";

    mystruct_t info = {15, "Bob"};
    mystruct_t * sptr;  /* sptr doesn't point to anything yet! */
    sptr = &info;       /* sptr points to info */

    void * vptr;   /* void pointer */

    /* fill the array */
    for(int ii=0;ii<LEN;ii++) {
        nums[ii]=ii*11;
    }

    /* Print information about the pointers */
    printf("abc=%d &abc=%p sizeof(abc)=%lu\n", abc, (void *) &abc, sizeof(abc));
    printf("iptr=%p *iptr=%d &iptr=%p sizeof(iptr)=%lu\n", (void*) iptr, *iptr, (void *) &iptr, sizeof(iptr));

    /* Go through array with pointer */
    printf("\n");
    for(int ii=0;ii<LEN;ii++) {
        printf("nums[%d]=%d at %p\n", ii, *(ptr+ii), (void *) (ptr+ii));
    }
    
    /* Working with strings */
    printf("\n");
    print_string_array(hello); 
    print_string_array(alpha); 

    printf("\n");
    print_string_pointer(hello); 
    print_string_pointer(alpha); 

    /* Working with structures */
    printf("\n");
    printf("info[%p]: %d %s\n", (void*) &info, info.num, info.name);
    printf("sptr[%p]: *sptr=%p %d %s\n", (void*) &sptr, (void*) sptr, sptr->num, sptr->name);
    /* Allocating a new struct */
    sptr = malloc(sizeof(mystruct_t));  /* Allocates enough memory for a stuct */
    printf("Allocating new structure...\n");
    sptr->num = 21;
    strncpy(sptr->name, "Joe", LEN-1);
    printf("sptr[%p]: *sptr=%p %d %s\n", (void*) &sptr, (void*) sptr, sptr->num, sptr->name);

    /* Working with void pointers */
    printf("\n");
    vptr = iptr;
    printf("vptr=iptr: vptr=%p &vptr=%p *vptr=%d\n", (void*)vptr, (void*)&vptr, *((int *)vptr));
    vptr = &info.num;
    printf("vptr=&info.num: vptr=%p &vptr=%p *vptr=%d\n", (void*)vptr, (void*)&vptr, *((int *)vptr));
    vptr = &info.name;
    printf("vptr=&info.name: vptr=%p &vptr=%p *vptr=%s\n", (void*)vptr, (void*)&vptr, (char *)vptr);

    printf("\nWorking with double pointers:\n");
    change_pointer(&vptr, alpha);
    printf("vptr swapped with alpha: vptr=%p &vptr=%p *vptr=%s\n", (void*)vptr, (void*)&vptr, (char *)vptr);
    change_pointer(&vptr, &abc);
    printf("vptr swapped with &abc: vptr=%p &vptr=%p *vptr=%d\n", (void*)vptr, (void*)&vptr, *((int *)vptr));

    return 0;
}