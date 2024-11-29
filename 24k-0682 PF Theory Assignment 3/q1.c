/*
Name:- Syed Mustafa Bukhari
Roll#:- 24k-0682
Question 1
Pf Assignment 3
*/




#include <stdio.h>
#include <string.h>
typedef struct {
    int employeeCode;
    char employeeName[50];
    int dateOfJoining[3];
} Employee;
void assignEmployeeDetails(Employee *emp) {
    printf("Enter employee code: ");
    scanf("%d", &emp->employeeCode);
    printf("Enter employee name: ");
    scanf(" %[^\n]%*c", emp->employeeName);
    printf("Enter date of joining (dd mm yyyy): ");
    scanf("%d %d %d", &emp->dateOfJoining[0], &emp->dateOfJoining[1], &emp->dateOfJoining[2]);
}
void displayEmployeesWithTenure(Employee employees[], int n) {
    int currentDay, currentMonth, currentYear;
    printf("\nEnter the current date (dd mm yyyy): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    int count = 0;
    printf("\nEmployees with more than 3 years of tenure:\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        int joiningYear = employees[i].dateOfJoining[2];
        int joiningMonth = employees[i].dateOfJoining[1];
        int joiningDay = employees[i].dateOfJoining[0];
        int tenureYears = currentYear - joiningYear;
        if (currentMonth < joiningMonth || (currentMonth == joiningMonth && currentDay < joiningDay)) {
            tenureYears--;
        }
        if (tenureYears > 3) {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %02d-%02d-%d\n\n", joiningDay, joiningMonth, joiningYear);
            count++;
        }
    }

    printf("Total number of employees with more than 3 years of tenure: %d\n", count);
}

int main() {
    Employee employees[4];
    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        assignEmployeeDetails(&employees[i]);
    }
    displayEmployeesWithTenure(employees, 4);

    return 0;
}
