#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to store employee details
typedef struct {
    int emp_id;
    char name[50];
    float basic_salary;
    float allowances;
} Employee;

// Function to compute gross salary
float computeGrossSalary(Employee emp) {
    return emp.basic_salary + emp.allowances;
}

// Function to save employee payroll data to a file
void saveToFile(Employee employees[], int count) {
    FILE *file = fopen("payroll.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Emp ID, Name, Gross Salary\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d, %s, ₹%.2f\n", employees[i].emp_id, employees[i].name, computeGrossSalary(employees[i]));
    }
    
    fclose(file);
    printf("\nRecords saved in \"payroll.txt\"\n");
}

// Function to retrieve an employee's salary
void searchEmployee(Employee employees[], int count) {
    int emp_id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &emp_id);

    for (int i = 0; i < count; i++) {
        if (employees[i].emp_id == emp_id) {
            printf("\nEmployee: %s\n", employees[i].name);
            printf("Gross Salary: ₹%.2f\n", computeGrossSalary(employees[i]));
            return;
        }
    }
    printf("Employee ID not found!\n");
}

int main() {
    int n;
    Employee employees[MAX];

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Emp ID: ");
        scanf("%d", &employees[i].emp_id);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name);
        printf("Basic Salary (₹): ");
        scanf("%f", &employees[i].basic_salary);
        printf("Allowances (₹): ");
        scanf("%f", &employees[i].allowances);
    }

    // Save payroll data to file
    saveToFile(employees, n);

    // Search for an employee's salary
    searchEmployee(employees, n);

    return 0;
}
