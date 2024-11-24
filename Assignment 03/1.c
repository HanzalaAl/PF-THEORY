#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    int dayOfJoining;
    int monthOfJoining;
    int yearOfJoining;
};

void assignValues(struct Employee *e) {
    printf("Enter Employee Code: ");
    scanf("%d", &e->employeeCode);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", e->employeeName); 
    printf("Enter Date of Joining (DD MM YYYY): ");
    scanf("%d %d %d", &e->dayOfJoining, &e->monthOfJoining, &e->yearOfJoining);
}

void displayLongTenureEmployees(struct Employee employees[], int size) {
    int currentDay, currentMonth, currentYear;
    printf("Enter the current date (DD MM YYYY): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    int count = 0;
    printf("\nEmployees with tenure of more than 3 years:\n");
    for (int i = 0; i < size; i++) {
        int tenureYears = currentYear - employees[i].yearOfJoining;
        if (currentMonth < employees[i].monthOfJoining || 
            (currentMonth == employees[i].monthOfJoining && currentDay < employees[i].dayOfJoining)) {
            tenureYears--;
        }
        if (tenureYears > 3) {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %02d/%02d/%04d\n", employees[i].dayOfJoining, employees[i].monthOfJoining, employees[i].yearOfJoining);
            printf("Tenure: %d years\n\n", tenureYears);
            count++;
        }
    }
    printf("Total employees with tenure > 3 years: %d\n", count);
}

int main() {
    struct Employee employees[4];

    printf("Enter details for 4 employees:\n");
    for (int i = 0; i < 4; i++) {
        printf("\nEmployee %d:\n", i + 1);
        assignValues(&employees[i]);
    }
    
    displayLongTenureEmployees(employees, 4);

    return 0;
}
