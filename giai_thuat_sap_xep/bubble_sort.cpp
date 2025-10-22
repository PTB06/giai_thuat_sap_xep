#include <stdio.h>

// Hàm in m?ng
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Hàm hoán ??i
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Hàm Bubble Sort
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Duy?t t? cu?i v? ??u dãy ch?a ???c s?p x?p
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]);
            }
        }

        // In ra m?ng sau m?i l?n "n?i b?t"
        printf("B??c %d: ", i + 1);
        printArray(a, n);
    }
}

int main() {
    int a[] = { 3, 10, 1, 23, 103, 34, 17, 53, 64 };
    int n = sizeof(a) / sizeof(a[0]);

    printf("M?ng ban ??u: ");
    printArray(a, n);

    BubbleSort(a, n);

    printf("M?ng sau khi s?p x?p: ");
    printArray(a, n);

    return 0;
}
