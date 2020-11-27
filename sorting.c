#include<stdlib.h>
#include<stdio.h>

int* Bubblesort(int arr[], int n) {
    printf("%d\n", n/2+1);
    for(int i =0; i < n; i++) {
        for(int j =i+1; j<n; j++) {
            if(arr[i]>arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    return arr;
}

int BinarySearch(int arr[], int upper_bound, int lower_bound, int val) {
    int mid = (upper_bound+lower_bound)/2;
    while(mid != lower_bound || mid != upper_bound) {
        mid = (upper_bound+lower_bound)/2;
        if(val == arr[mid]) return mid;
        if(val<arr[mid]) {
            upper_bound = mid-1;
        } else {
            lower_bound = mid+1;
        }
    }
    printf("Not Found");
    return -1;
}

int* selectionSort(int arr[], int n) {

    for(int i = 0; i <= n-2; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return arr;
}

int* insertionSort(int arr[], int n) {
    //best case: O(n), worst case when descending sorted
                //O(n^2)
    //better than selection and bubble sort
    for(int i = 1; i<n; i++) {
        int hole = i;
        int value = arr[i];
        while(hole>0 && arr[hole-1]>value) {
            arr[hole] = arr[hole-1];
            hole -= 1;
        }
        arr[hole] = value;
    }
    return arr;
}

void merge(int L[],int R[], int A[]) {
    int nL = sizeof(L)/sizeof(int);
    int nR = sizeof(L)/sizeof(int);
    int i,j,k;
    i = j = k = 0;
    while(i<nL && j<nR) {
        if(L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }
    while(i<nL) {
        A[k++] = L[i++];
    }
    while(j<nR) {
        A[k++] = L[j++];
    }
}

int* mergeSort(int arr[]) {
    int n = sizeof(arr)/sizeof(int);
    if(n < 2) {
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for(int i = 0; i<mid; i++) {
        left[i] = arr[i];
    }
    for(int i = mid; i<n; i++) {
        right[i-mid] = arr[i];
    }
    mergeSort(left);
    mergeSort(right);
    merge(left,right,arr);
}

int partion(int arr[], int start, int end) {
    int pivot = arr[end];
    int pIndex = start;
    for(int i = 0; i<end; i++) {
        if(arr[i]<=pivot) {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    arr[end] = arr[pIndex];
    arr[pIndex] = pivot;
    return pIndex;
}
v
oid quickSort(int arr[], int start, int end) {
    if(start<end) {
        int pindex = partion(arr,start, end);
        quickSort(arr,start, pindex-1);
        quickSort(arr, pindex+1, end);
    }
}

int main() {
    int arr[] = {10, 9, 7, 101, 23, 44, 12, 78, 34, 23};
    int *arrp = insertionSort(arr, 10);
    for(int i =0; i<10; i++) {
        printf("%d ", arrp[i]);
    }
    //printf("\n%d",BinarySearch(arrp, 9, 0, 12));
}
