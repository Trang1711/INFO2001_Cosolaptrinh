#include <stdio.h>

int main() {
    int arr[10];
    int i;
    float sum = 0;

    // Input
    printf("Enter scores for students in the class:\n");
    for (i = 0; i < 10; i++) {
        printf("Enter score for student %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];  // Calculate the sum of scores
    }

    // Display the original array
    printf("\nScores of the students:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Calculate the average score
    float average = sum / 10;

    // Display the average score
    printf("\nAverage score of the class: %.2f\n", average);

    return 0;
}
