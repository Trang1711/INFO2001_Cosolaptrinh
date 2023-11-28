#include <stdio.h>
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1;  
}

// Bubble Sort 
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// Binary Search
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid; 
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  
}

int main() {
    int arr[10];
    int i, searchValue;

    
    printf("Nhap gia tri cho cac phan tu trong mang:\n");
    for (i = 0; i < 10; i++) {
        printf("Nhap gia tri cho phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    printf("\nMang vua nhap:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    
    printf("\nNhap gia tri can tim kiem: ");
    scanf("%d", &searchValue);
    int linearSearchResult = linearSearch(arr, 10, searchValue);
    if (linearSearchResult != -1) {
        printf("Tim thay tai vi tri %d (tinh tu 0)\n", linearSearchResult);
    } else {
        printf("Khong tim thay gia tri can tim kiem.\n");
    }

    
    bubbleSort(arr, 10);
    
    printf("\nMang sau khi sap xep (Bubble Sort):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    
    printf("\nNhap gia tri can tim kiem (su dung Binary Search): ");
    scanf("%d", &searchValue);
    int binarySearchResult = binarySearch(arr, 0, 9, searchValue);
    if (binarySearchResult != -1) {
        printf("Tim thay tai vi tri %d (tinh tu 0)\n", binarySearchResult);
    } else {
        printf("Khong tim thay gia tri can tim kiem.\n");
    }

    return 0;
}

