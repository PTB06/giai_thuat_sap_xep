#include <stdio.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int PartitionFunc(int A[], int left, int right, int n) {
    int pivot = left;        // chọn phần tử đầu làm pivot
    int i = left + 1;
    int j = right;
    printf("\n--> Partition tu %d den %d (pivot = %d)\n", left, right, A[pivot]);
    while (i <= j) {
        while (i <= right && A[i] < A[pivot]) i++;
        while (j >= left && A[j] > A[pivot]) j--;
        if (i < j) {
            swap(&A[i], &A[j]);
            i++;
            j--;
            printf("Sau khi swap: ");
            printArray(A, n);
        }
        else {
            break;
        }
    }
    swap(&A[left], &A[j]);
    printf("Sau khi dua pivot vao vi tri dung: ");
    printArray(A, n);
    return j; // vị trí mới của pivot
}
void QuickSort(int A[], int left, int right, int n) {
    if (right - left <= 0) {
        return;
    }
    else {
        int partition = PartitionFunc(A, left, right, n);
        QuickSort(A, left, partition - 1, n);
        QuickSort(A, partition + 1, right, n);
    }
}

int main() {
    int A[] = { 3, 10, 1, 23, 103, 34, 17, 53, 64, 71 };
    int n = sizeof(A) / sizeof(A[0]);
    printf("Mang ban dau: ");
    printArray(A, n);
    QuickSort(A, 0, n - 1, n);
    printf("\nMang sau khi sap xep: ");
    printArray(A, n);
    return 0;
}
