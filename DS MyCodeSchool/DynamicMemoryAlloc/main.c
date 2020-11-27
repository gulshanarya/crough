#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = malloc(4*sizeof(int));
    for(int i =0; i< 4; i++) {
        *(a+i) = i+1;
    }

    int *b = realloc(a, 35*sizeof(int));
    //int *b = realloc(a, 0); //equivalent to free(a)
    //int *b = realloc(NULL, 4*sizeof(int)); //equivalent to malloc

    printf("old address: %d new add: %d\n", a,b);
    for(int i =0; i< 10; i++) {
        printf("%d\n", *(b+i));
    }
    return 0;
}

