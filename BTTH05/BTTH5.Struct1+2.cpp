
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Student {
    char name[30];
    char gender[5];
    int age;
    float Math, Physics, Chemistry;
    float gpa = 0;
};

typedef Student SV;

void input(SV &sv);
void inputMultiple(SV a[], int n);
void display(SV sv);
void displayMultiple(SV a[], int n);
void calculateGPA(SV &sv);
void sort(SV a[], int n);
void classify(SV a);
void classifyMultiple(SV a[], int n);

int main() {
    int key;
    char fileName[] = "StudentList.txt";
    int n;
    bool hasInput = false;

    do {
        printf("\nEnter the number of students: ");
        scanf("%d", &n);
    } while (n <= 0);

    SV a[n];

    while (true) {
        system("cls");
        printf("   STUDENT MANAGEMENT PROGRAM   \n");
        printf("      1. Input data              \n");
        printf("      2. Display student list    \n");
        printf("      3. Sort students by GPA    \n");
        printf("      4. Classify students       \n");
        printf("      5. Search for a student    \n");
        printf("      0. Exit                    \n");
        printf("   Enter your choice:            \n");
        scanf("%d", &key);

        switch (key) {
            case 1:
                printf("\nYou have chosen to input the student list!");
                inputMultiple(a, n);
                printf("\nInput successful!");
                hasInput = true;
                printf("\nPress any key to continue!");
                getch();
                break;
            case 2:
                if (hasInput) {
                    printf("\nYou have chosen to display the student list!");
                    displayMultiple(a, n);
                } else {
                    printf("\nInput the student list first!!!!");
                }
                printf("\nPress any key to continue!");
                getch();
                break;
            case 3:
                if (hasInput) {
                    printf("\nYou have chosen to sort students by GPA!");
                    sort(a, n);
                    displayMultiple(a, n);
                } else {
                    printf("\nInput the student list first!!!!");
                }
                printf("\nPress any key to continue!");
                getch();
                break;
            case 4:
                if (hasInput) {
                    printf("\nYou have chosen to classify students!");
                    classifyMultiple(a, n);
                } else {
                    printf("\nInput the student list first!!!!");
                }
                printf("\nPress any key to continue!");
                getch();
                break;
            case 0:
                printf("\nYou have chosen to exit the program!");
                getch();
                return 0;
            default:
                printf("\nInvalid choice!");
                printf("\nPress any key to continue!");
                getch();
                break;
        }
    }
}

void calculateGPA(SV &sv) {
    sv.gpa = (sv.Math + sv.Physics + sv.Chemistry) / 3;
}

void input(SV &sv) {
    printf("\nEnter name: ");
    fflush(stdin);
    gets(sv.name);
    printf("\nEnter gender: ");
    gets(sv.gender);
    printf("\nEnter age: ");
    scanf("%d", &sv.age);
    printf("\nEnter scores for Math, Physics, Chemistry: ");
    scanf("%f%f%f", &sv.Math, &sv.Physics, &sv.Chemistry);
    calculateGPA(sv);
}

void inputMultiple(SV a[], int n) {
    printf("\n____________________________________\n");
    for (int i = 0; i < n; ++i) {
        printf("\nEnter information for student %d:", i + 1);
        input(a[i]);
    }
    printf("\n____________________________________\n");
}

void display(SV sv) {
    printf("\nName: %s", sv.name);
    printf("\nGender: %s", sv.gender);
    printf("\nAge: %d", sv.age);
    printf("\nScores - Math, Physics, Chemistry: %.2f - %.2f - %.2f", sv.Math, sv.Physics, sv.Chemistry);
    printf("\nGPA: %.2f", sv.gpa);
}

void displayMultiple(SV a[], int n) {
    printf("\n____________________________________\n");
    for (int i = 0; i < n; ++i) {
        printf("\nInformation for student %d:", i + 1);
        display(a[i]);
    }
    printf("\n____________________________________\n");
}

void sort(SV a[], int n){
    // Sort in ascending order based on GPA
    SV tmp;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(a[i].gpa > a[j].gpa){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void classify(SV sv){
    if(sv.gpa >= 8) printf("Excellent");
    else if(sv.gpa >= 6.5) printf("Good");
    else if(sv.gpa >= 4) printf("Average");
    else printf("Poor");
}

void classifyMultiple(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i < n; ++i){
        printf("\nClassification of student %d: ", i+1);
        classify(a[i]);
    }
    printf("\n____________________________________\n");
}
