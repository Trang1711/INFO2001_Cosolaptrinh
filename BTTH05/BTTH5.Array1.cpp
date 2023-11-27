#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Bubble Sort (to sort the array before performing Binary Search)
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
            return mid;  // Return the index if found
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Return -1 if not found
}

int main() {
    int arr[10];
    int i, searchValue;

    // Input
    printf("Enter values for the elements of the array:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the original array
    printf("\nOriginal array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Linear Search
    printf("\nEnter the value to search: ");
    scanf("%d", &searchValue);
    int linearSearchResult = linearSearch(arr, 10, searchValue);
    if (linearSearchResult != -1) {
        printf("Found at index %d (starting from 0)\n", linearSearchResult);
    } else {
        printf("Value not found.\n");
    }

    // Sorting for Binary Search
    bubbleSort(arr, 10);

    // Display the sorted array
    printf("\nArray after sorting (Bubble Sort):\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Binary Search
    printf("\nEnter the value to search (using Binary Search): ");
    scanf("%d", &searchValue);
    int binarySearchResult = binarySearch(arr, 0, 9, searchValue);
    if (binarySearchResult != -1) {
        printf("Found at index %d (starting from 0)\n", binarySearchResult);
    } else {
        printf("Value not found.\n");
    }

    return 0;
}
