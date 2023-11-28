#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    int id;
    int age;
    float gpa; 
};
// Ham hien thi 
void displayStudent(struct Student s) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s", s.name);
    printf("Ma so: %d\n", s.id);
    printf("Tuoi: %d\n", s.age);
    printf("Diem: %.2f\n", s.gpa);
}
// Ham sap xep sinh vien theo diem so (gpa)
void sortStudentsByGrade(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].gpa > arr[j + 1].gpa) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Ham tim kiem sinh vien theo ten
int searchStudentByName(struct Student arr[], int n, char searchName[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, searchName) == 0) {
            return i;  
        }
    }
    return -1;  
}
// Ham sap xep sinh vien theo ten
void sortStudentsByName(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Ham tim kiem sinh vien theo id
int searchStudentById(struct Student arr[], int n, int searchId) {
    for (int i = 0; i < n; i++) {
        if (arr[i].id == searchId) {
            return i;  
        }
    }
    return -1;  
}



int main() {
    struct Student students[3]; 
    char searchName[50];
    int searchId, result;
    for (int i = 0; i < 3; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        printf("Nhap ten: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        printf("Nhap ma so: ");
        scanf("%d", &students[i].id);
        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);
        printf("Nhap diem (gpa): ");
        scanf("%f", &students[i].gpa);
        getchar();  // Doc ki tu '\n' tu bo nho dem
    }

    // Hien thi thong tin sinh vien truoc khi sap xep
    printf("\nThong tin sinh vien truoc khi sap xep:\n");
    for (int i = 0; i < 3; i++) {
        displayStudent(students[i]);
    }
    // Chon cach sap xep
    int choice;
    printf("\nChon cach sap xep (1: Theo ten, 2: Theo diem): ");
    scanf("%d", &choice);

    // Sap xep sinh vien
    if (choice == 1) {
        sortStudentsByName(students, 3);
    } else if (choice == 2) {
        sortStudentsByGrade(students, 3);
    }

    // Hien thi thong tin sinh vien sau khi sap xep
    printf("\nThong tin sinh vien sau khi sap xep:\n");
    for (int i = 0; i < 3; i++) {
        displayStudent(students[i]);
    }

    // Tim kiem sinh vien
    printf("\nNhap ten sinh vien can tim kiem: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Loai bo ki tu '\n' thua
    result = searchStudentByName(students, 3, searchName);
    if (result != -1) {
        printf("Tim thay sinh vien tai vi tri %d \n", result);
    } else {
        printf("Khong tim thay sinh vien co ten \"%s\"\n", searchName);
    }

    // Tim kiem sinh vien theo id
    printf("\nNhap ma so sinh vien can tim kiem: ");
    scanf("%d", &searchId);
    result = searchStudentById(students, 3, searchId);
    if (result != -1) {
        printf("Tim thay sinh vien tai vi tri %d\n", result);
    } else {
        printf("Khong tim thay sinh vien co ma so %d\n", searchId);
    }

    return 0;
}

