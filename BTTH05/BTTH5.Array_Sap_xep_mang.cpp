#include <stdio.h>
#include <time.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int main() {
    int arr[10];
    int i;

   
    printf("Nhap gia tri cho cac phan tu trong mang:\n");
    for (i = 0; i < 10; i++) {
        printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

   
    printf("\nMang vua nhap:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble Sort
    clock_t start_bubble = clock();
    bubbleSort(arr, 10);
    clock_t end_bubble = clock();

    // In mang
    printf("\nMang sau khi sap xep (Bubble Sort):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nThoi gian thuc thi Bubble Sort: %f giay\n", ((double)end_bubble - start_bubble) / CLOCKS_PER_SEC);

    printf("\nReset mang ve trang thai ban dau:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    clock_t start_selection = clock();
    selectionSort(arr, 10);
    clock_t end_selection = clock();

    // in mang
    printf("\nMang sau khi sap xep (Selection Sort):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nThoi gian thuc thi Selection Sort: %f giay\n", ((double)end_selection - start_selection) / CLOCKS_PER_SEC);

    return 0;
}

