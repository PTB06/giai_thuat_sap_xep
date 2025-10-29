#include <stdio.h>

// In mảng hiện tại
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Hàm heapify để duy trì tính chất heap
void heapify(int A[], int n, int i, int N) {
    int largest = i;      // gốc
    int left = 2 * i + 1; // con trái
    int right = 2 * i + 2; // con phải

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    // Nếu phần tử con lớn hơn gốc
    if (largest != i) {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        printf("Sau khi hoan doi (%d <-> %d): ", i, largest);
        printArray(A, N);

        // Gọi đệ quy để đảm bảo cây con vẫn là heap
        heapify(A, n, largest, N);
    }
}

// Hàm HeapSort
void heapSort(int A[], int N) {
    // B1: Xây dựng heap (heapify từ giữa về đầu)
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(A, N, i, N);
    }

    printf("\nSau khi tao heap ban dau: ");
    printArray(A, N);

    // B2: Trích từng phần tử khỏi heap
    for (int i = N - 1; i > 0; i--) {
        // Đưa phần tử lớn nhất (gốc) về cuối
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        printf("Sau khi dua max (%d) ra cuoi: ", A[i]);
        printArray(A, N);

        // Gọi heapify cho phần còn lại
        heapify(A, i, 0, N);
    }
}

int main() {
    int A[] = { 3, 10, 1, 23, 103, 34, 17, 53, 64, 71 };
    int N = sizeof(A) / sizeof(A[0]);

    printf("Mang ban dau: ");
    printArray(A, N);

    heapSort(A, N);

    printf("\nMang sau khi sap xep: ");
    printArray(A, N);

    return 0;
}
