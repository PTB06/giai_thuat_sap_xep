#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Hoán đổi phần tử nhỏ nhất với phần tử ở vị trí i
        int c = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = c;

        // In mảng sau mỗi bước sắp xếp
        printf("Bước %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    int a[] = { 3, 10, 1, 23, 103, 34, 17, 53, 64 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("Mảng ban đầu: ");
    printArray(a, n);

    selectionSort(a, n);

    printf("Mảng sau khi sắp xếp: ");
    printArray(a, n);

    return 0;
}
