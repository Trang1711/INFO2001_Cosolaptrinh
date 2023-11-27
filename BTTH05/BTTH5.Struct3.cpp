#include <stdio.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    int employeeId;      // Employee ID
    char name[50];       // Employee name
    char position[50];   // Position
    float salary;        // Salary
};

// Function to input employee information
struct Employee inputEmployee() {
    struct Employee e;

    printf("Enter employee ID: ");
    scanf("%d", &e.employeeId);
    getchar();  // Read and discard the newline character from the input buffer

    printf("Enter employee name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';  // Remove any trailing newline character

    printf("Enter position: ");
    fgets(e.position, sizeof(e.position), stdin);
    e.position[strcspn(e.position, "\n")] = '\0';  // Remove any trailing newline character

    printf("Enter salary: ");
    scanf("%f", &e.salary);

    return e;
}

// Function to display employee information
void displayEmployee(struct Employee e) {
    printf("\nEmployee information:\n");
    printf("Employee ID: %d\n", e.employeeId);
    printf("Name: %s\n", e.name);
    printf("Position: %s\n", e.position);
    printf("Salary: %.2f\n", e.salary);
}

// Function to add an employee to the array
void addEmployee(struct Employee arr[], int *n) {
    if (*n < 10) {
        arr[*n] = inputEmployee();
        (*n)++;
        printf("Employee added successfully!\n");
    } else {
        printf("Employee list is full. Cannot add a new employee!\n");
    }
}

// Function to delete an employee based on employee ID
int deleteEmployee(struct Employee arr[], int *n, int employeeId) {
    int found = 0;
    int newCount = 0;  // Counter for the new number of employees after deletion

    for (int i = 0; i < *n; i++) {
        if (arr[i].employeeId == employeeId) {
            found = 1;
        } else {
            arr[newCount] = arr[i];
            newCount++;
        }
    }

    if (found) {
        (*n)--;
        printf("Employee with employee ID %d deleted!\n", employeeId);
        return 1;  // Return 1 if deletion is successful
    } else {
        printf("No employee with employee ID %d found!\n", employeeId);
        return 0;  // Return 0 if no employee is found
    }
}

// Function to sort employees by employee ID
void sortEmployeesById(struct Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].employeeId > arr[j + 1].employeeId) {
                struct Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Employee employees[10];  // Array of 10 employees
    int employeeCount = 0;  // Current number of employees

    // Add an employee
    addEmployee(employees, &employeeCount);

    // Display employee information
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    // Add another employee
    addEmployee(employees, &employeeCount);

    // Display employee information
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    // Delete an employee by employee ID
    int employeeIdToDelete;
    printf("Enter the employee ID to delete: ");
    scanf("%d", &employeeIdToDelete);
    deleteEmployee(employees, &employeeCount, employeeIdToDelete);

    // Display employee information after deletion
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    // Sort employees by employee ID
    sortEmployeesById(employees, employeeCount);

    // Display employee information after sorting
    printf("\nEmployee list after sorting by employee ID:\n");
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    return 0;
}
