#include <stdio.h>

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Trộn 2 dãy con đã được sắp xếp trong A
// L1 = A[m..n], L2 = A[n+1..p]
void MergeArrays(int A[], int m, int n, int p, int N) {
    int i = m, j = n + 1;

    while (i < j && j <= p) {
        if (A[i] <= A[j]) {
            i++;
        }
        else {
            // chèn A[j] vào vị trí i
            int x = A[j];
            for (int k = j - 1; k >= i; k--) {
                A[k + 1] = A[k];
            }
            A[i] = x;
            i++;
            j++;
        }
    }

    printf("Sau khi tron [%d..%d] va [%d..%d]: ", m, n, n + 1, p);
    printArray(A, N);
}

void Split_Merg(int A[], int first, int last, int N) {
    if (first >= last) return;

    int m = (first + last) / 2;

    Split_Merg(A, first, m, N);    // tách nửa trái
    Split_Merg(A, m + 1, last, N); // tách nửa phải
    MergeArrays(A, first, m, last, N); // ghép 2 nửa
}

void MergeSort(int A[], int N) {
    if (N < 2) return;
    Split_Merg(A, 0, N - 1, N);
}

int main() {
    int A[] = { 3, 10, 1, 23, 103, 34, 17, 53, 64, 71 };
    int N = sizeof(A) / sizeof(A[0]);

    printf("Mang ban dau: ");
    printArray(A, N);

    MergeSort(A, N);

    printf("\nMang sau khi sap xep: ");
    printArray(A, N);

    return 0;
}
