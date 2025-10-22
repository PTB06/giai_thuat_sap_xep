#include <stdio.h>

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void InsertionSort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int x = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;

        // In mảng sau mỗi bước chèn
        printf("Bước %d: ", i);
        printArray(A, n);
    }
}

int main() {
    int A[] = { 3, 10, 1, 23, 103, 34, 17, 53, 64 };
    int n = sizeof(A) / sizeof(A[0]);

    printf("Mảng ban đầu: ");
    printArray(A, n);

    InsertionSort(A, n);

    printf("Mảng sau khi sắp xếp: ");
    printArray(A, n);

    return 0;
}
