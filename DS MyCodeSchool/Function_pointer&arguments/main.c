#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void A() {
    printf("Hello");
}

void B(void (*ptr_fun)()){
    ptr_fun();
}

int compare(int a, int b) {
    if(a>b) return 1;
    else return -1;
}

int abs_compare(int a, int b) {
    if(abs(a) > abs(b)) return 1;
    else return -1;

}

void bubble_sort(int *a, int n, int (*compare)(int,int)) {
    int temp;
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j < n; j++) {
            if(compare(a[i], a[j])>0) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

//qsort compare
int qsort_comp(const void* a, const void* b) {
    int A = *((int*)a);
    int B = *((int*)b);
    return A-B;
}

int main()
{
    //B(A);

    int a[] = {47,4,57,-56,-6};
    bubble_sort(a, 5, abs_compare);
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    //qsort
    printf("\nqsort\n");
    int qa[] = {47,-4,57,-56,-6, 10};
    qsort(qa, 6, sizeof(int), qsort_comp);
    for(int i = 0; i<6; i++) printf("%d ", qa[i]);

}



