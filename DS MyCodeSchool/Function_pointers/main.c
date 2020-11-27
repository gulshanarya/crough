#include <stdio.h>
#include <stdlib.h>

int c;
int add(int a, int b) {
    c = a+b;
    return c;
}
int main()
{
    int (*padd)(int,int); //declaring a function pointer
    padd = &add; //also simple as 'add'

    int c = (*padd)(4,5); //dereference and executing the function and also padd(4,5) is similar
    printf("%d", c);

    return 0;
}

