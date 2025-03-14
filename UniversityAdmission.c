#include <stdio.h>
#include <string.h>

#define MAX_PROGRAMS 5

// Available engineering programs
const char *programs[MAX_PROGRAMS] = {
    "1. Computer Science and Engineering",
    "2. Electrical and Electronic Engineering",
    "3. Mechanical Engineering",
    "4. Civil Engineering",
    "5. Industrial Engineering"
};

void displayPrograms() {
    printf("Available Engineering Programs:\n");
    for (int i = 0; i < MAX_PROGRAMS; i++) {
        printf("%s\n", programs[i]);
    }
}

void universityAdmission() {
    char name[50], fatherName[50], motherName[50], selectedProgram[100];
    int age, programChoice;
    float admissionFee = 500.0, semesterFee = 2000.0, totalFee, amountPaid;

    printf("Enter your name: ");
    scanf(" %s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your father's name: ");
    scanf(" %s", fatherName);
    printf("Enter your mother's name: ");
    scanf(" %s", motherName);

    displayPrograms();
    printf("Select your program (Enter number): ");
    scanf("%d", &programChoice);
    if (programChoice < 1 || programChoice > MAX_PROGRAMS) {
        printf("Invalid choice! Exiting...\n");
        return;
    }
    strcpy(selectedProgram, programs[programChoice - 1]);

    totalFee = admissionFee + semesterFee;
    printf("\nYou need to pay Admission Fee: $%.2f and Semester Fee: $%.2f\n", admissionFee, semesterFee);
    printf("Total Amount to Pay: $%.2f\n", totalFee);

    // Payment process
    printf("\nEnter amount to pay: $");
    scanf("%f", &amountPaid);

    if (amountPaid >= totalFee) {
        printf("\nPayment successful! Admission confirmed.\n");
        if (amountPaid > totalFee) {
            printf("Refund Amount: $%.2f\n", amountPaid - totalFee);
        }
        printf("\nAdmission Successful! Here is your receipt:\n");
        printf("-------------------------------------\n");
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("Father's Name: %s\n", fatherName);
        printf("Mother's Name: %s\n", motherName);
        printf("Selected Program: %s\n", selectedProgram);
        printf("Total Fees Paid: $%.2f\n", totalFee);
        printf("-------------------------------------\n");
    } else {
        printf("\nInsufficient payment! Admission cancelled.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nUniversity Admission System\n");
        printf("==========================\n");
        printf("1. Apply for Admission\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                universityAdmission();
                break;
            case 2:
                printf("Exiting the system...\n");
                printf("Thank you for using our admission service!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}
