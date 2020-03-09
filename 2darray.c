#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int* addressOfArrayR(int, int, int);
int* addressOfArrayC(int, int, int);

//example array
int arr[2][3] = {{0, 1, 2}, {3, 4, 5}};

int main() {
    printf("%d", *addressOfArrayR(1,2,3));
    return 0;
}

//By Row Major Order
int* addressOfArrayR(int i, int j, int c) {
// Address(a[i][j]) = B. A. + (i * c + j) * size
    return (&arr[0][0]+ (i*c+j));
}

//By Column major order
int* addressOfArrayC(int i, int j, int r) {
// Address(a[i][j]) = B. A. + (j * r + i) * size
    return &arr[0][0]+ (j*r+i);
}
