#include <stdio.h>
#include <string.h>

struct Students {
    char ID[20];
    char Name[50];
    int Age;
    char Grade[20];
    char Gender[10]; 
    float GPA;
};


struct Students st() {
    struct Students st;
    printf("Student ID: ");
    scanf("%s", &st.ID);
    printf("Student Name: ");
    scanf("%s", st.Name);
    gets(st.Name);
    printf("Student Age: ");
    scanf("%d", &st.Age);
    printf("Student Gender: ");
    scanf("%s", st.Gender);
    printf("GPA: ");
    scanf("%f", &st.GPA);
    return st;
}
void displayStudent(struct Students s) {
    printf("\nStudents information:\n");
    printf("Students Name: %s\n", s.Name);
    printf("Students ID: %d\n", s.ID);
    printf("Students Age: %d\n", s.Age);
    printf("Students Gender %s\n", s.Gender);
    printf("Students GPA: %.2f\n", s.GPA);
}
int main(){
	 int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Students Students[n];
	for (int i=0; i<2; i++){
	printf("Enter details for student %d:\n", i + 1);
	Students[i]=st();
}
    for (int i = 0; i < 2; i++) {
        displayStudent(Students[i]);
    }

    return 0;
}



