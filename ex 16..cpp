#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    float salary;
} Employee;

void addEmployee() {
    FILE *fp = fopen("employee.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Employee e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf("%s", e.name);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    fwrite(&e, sizeof(Employee), 1, fp);
    fclose(fp);
    printf("Record Added Successfully!\n");
}

void displayEmployees() {
    FILE *fp = fopen("employee.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    Employee e;
    printf("\n--- Employee Records ---\n");
    while (fread(&e, sizeof(Employee), 1, fp)) {
        printf("\nID: %d\nName: %s\nSalary: %.2f\n", e.id, e.name, e.salary);
    }

    fclose(fp);
}

void searchEmployee() {
    FILE *fp = fopen("employee.dat", "rb");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    int id, found = 0;
    Employee e;

    printf("Enter Employee ID to Search: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (e.id == id) {
            printf("\nRecord Found!\n");
            printf("ID: %d\nName: %s\nSalary: %.2f\n", e.id, e.name, e.salary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No Record Found!\n");

    fclose(fp);
}

void updateSalary() {
    FILE *fp = fopen("employee.dat", "rb+");
    if (!fp) {
        printf("No records found!\n");
        return;
    }

    int id, found = 0;
    Employee e;

    printf("Enter Employee ID to Update Salary: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Employee), 1, fp)) {
        if (e.id == id) {
            printf("Current Salary: %.2f\n", e.salary);
            printf("Enter New Salary: ");
            scanf("%f", &e.salary);

            fseek(fp, -sizeof(Employee), SEEK_CUR); // move pointer back
            fwrite(&e, sizeof(Employee), 1, fp);

            printf("Salary Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found!\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Employee Random Access File ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateSalary(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}
