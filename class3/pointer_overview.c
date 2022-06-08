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

/* This function assumes str has at least 3 characters */
void print_string_array(char str[]) {
    printf("print_string_array: %s\n", str);
    printf("     Array indexing: %c %c %c\n", str[0], str[1], str[2]);
    printf(" Pointer arithmetic: %c %c %c\n", *(str+0), *(str+1), *(str+2));
}

void print_string_pointer(char * ptr) {
    printf("print_string_array: %s\n", ptr);
    printf("     Array indexing: %c %c %c\n", ptr[0], ptr[1], ptr[2]);
    printf(" Pointer arithmetic: %c %c %c\n", *(ptr+0), *(ptr+1), *(ptr+2));
}

/* Function to change the value of a pointer */
void change_pointer(void ** into, void * what) {
    *into = what;   /* *into is an alias of the pointer */
}

typedef struct {
    int num;
    char name[LEN];
} mystruct_t;

int main(void) {

    int abc = 100;     /* integer */
    int nums[LEN];     /* array of integers */

    int * iptr = &abc;  /* integer pointer pointing to integer abc */
    int * ptr = nums;   /* integer pointer pointing to array nums */

    char hello[] = "Hello, world!";   /* character array holding a string */
    char * alpha = "ABCDEFGHIJK";     /* character pointer pointing to a string */

    mystruct_t info = {22, "Bob"};
    mystruct_t * sptr;  /* sptr does not point to anything yet */
    sptr = &info;       /* now sptr points to info */

    void * vptr;        /* void pointer */

    /* fill the array */
    for(int ii=0;ii<LEN;ii++) {
        nums[ii] = ii * 11;
    }

    /* print information about the variables & pointers */
    printf("abd=%d &abc=%p sizeof(abc)=%lu\n", abc, (void *) &abc, sizeof(abc));
    printf("iptr=%p &iptr=%p *iptr=%d sizeof(iptr)=%lu\n", (void *) iptr, (void *) &iptr, *iptr, sizeof(iptr));
    printf("\n");

    /* using pointer arithmetic to traverse an array */
    printf("nums:\n");
    for(int ii=0;ii<LEN;ii++) {
        printf("   nums[%d]=%d at %p\t",ii, nums[ii], (void *) &nums[ii]);
        printf("   ptr+ii=%p *(ptr+ii)=%d\n", (void *) (ptr+ii), *(ptr+ii));
    }
    printf("\n");

    /* Function with array parameter */
    printf("print_string_array:\n");
    print_string_array(hello);
    print_string_array(alpha);
    printf("\n");

    printf("print_string_pointer:\n");
    print_string_pointer(hello);
    print_string_pointer(alpha);
    printf("\n");

    /* Working with structures & structure pointers */
    printf("&info=%p : %d %s\n", (void *) &info, info.num, info.name);
    printf(" sptr=%p : %d %s (&sptr=%p)\n", (void *) sptr, sptr->num, sptr->name, (void *) &sptr);

    /* Allocate a new struct */
    printf("Allocating new structure:\n");
    sptr = malloc(sizeof(mystruct_t));   /* Allocates enough memory for a mystruct_t */
    sptr->num = 42;
    strncpy(sptr->name, "Alice", LEN-1);
    printf(" sptr=%p : %d %s (&sptr=%p)\n", (void *) sptr, sptr->num, sptr->name, (void *) &sptr);
    printf("\n");

    /* Working with void pointers */
    printf("vptr=&abc: \n");
    vptr=&abc;
    printf("abd=%d &abc=%p sizeof(abc)=%lu\n", abc, (void *) &abc, sizeof(abc));
    printf("vptr=%p &vptr=%p *vptr=%d\n", (void*) vptr, (void*) &vptr, *((int*) vptr));
    printf("vptr=iptr: \n");
    vptr = iptr;
    printf("iptr=%p &iptr=%p *iptr=%d sizeof(iptr)=%lu\n", (void *) iptr, (void *) &iptr, *iptr, sizeof(iptr));
    printf("vptr=%p &vptr=%p *vptr=%d\n", (void*) vptr, (void*) &vptr, *((int*) vptr));

    printf("\nvptr=sptr.num: \n");
    vptr = &sptr->num;   /* sptr->num is an int */
    printf("sptr=%p : %d %s (&sptr=%p)\n", (void *) sptr, sptr->num, sptr->name, (void *) &sptr);
    printf("vptr=%p &vptr=%p *vptr=%d\n", (void*) vptr, (void*) &vptr, *((int*) vptr));

    printf("vptr=sptr.name: \n");
    vptr = sptr->name;   /* sptr->name is a char pointer */
    printf("sptr=%p : %d %s (&sptr=%p)\n", (void *) sptr, sptr->num, sptr->name, (void *) &sptr);
    printf("vptr=%p &vptr=%p *vptr=%s\n", (void*) vptr, (void*) &vptr, (char*) vptr); 
    
    printf("vptr=sptr: \n");
    vptr = sptr;         /* sptr is a mystruct_t pointer */
    printf("sptr=%p : %d %s (&sptr=%p)\n", (void *) sptr, sptr->num, sptr->name, (void *) &sptr);
    printf("vptr=%p &vptr=%p *vptr=%d\n", (void*) vptr, (void*) &vptr, ((mystruct_t*) vptr)->num);
    printf("vptr=%p &vptr=%p *vptr=%s\n", (void*) vptr, (void*) &vptr, ((mystruct_t*) vptr)->name);

    printf("\n");
    printf("Working with double pointers:\n");
    change_pointer(&vptr, alpha);
    printf("vptr changed to alpha: ");
    printf("vptr=%p &vptr=%p *vptr=%s\n", (void*) vptr, (void*) &vptr, (char *) vptr);
    change_pointer(&vptr, &abc);
    printf("vptr changed to &abc: ");
    printf("vptr=%p &vptr=%p *vptr=%d\n", (void*) vptr, (void*) &vptr, *((int *) vptr));

    return 0;
}