/*
==============================================================
        SORTING STUDENT MARKS SYSTEM
==============================================================
Features:
1. Add Student (Roll No, Name, Marks)
2. Display Sorted Report
3. Search by Name or Roll Number
4. Exit
==============================================================
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int roll;
    char name[50];
    int marks;
} Student;

Student s[MAX];
int count = 0;

// Validate Name (only alphabets + space)
int isValidName(char name[]) {
    for(int i = 0; name[i] != '\0'; i++) {
        if(!(isalpha(name[i]) || name[i] == ' '))
            return 0;
    }
    return 1;
}

// Validate Number Input (for roll & marks)
int isValidNumber(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Add Student
void addStudent() {
    if(count >= MAX) {
        printf("❌ Database Full!\n");
        return;
    }

    char input[50];

    // Roll Number Input
    while(1) {
        printf("\nEnter Roll Number: ");
        scanf("%s", input);

        if(isValidNumber(input)) {
            s[count].roll = atoi(input);
            break;
        } else {
            printf("❌ Error: Roll Number must be numeric only!\n");
        }
    }

    getchar(); // clear buffer

    // Name Input
    while(1) {
        printf("Enter Name: ");
        fgets(s[count].name, sizeof(s[count].name), stdin);
        s[count].name[strcspn(s[count].name, "\n")] = 0;

        if(isValidName(s[count].name)) {
            break;
        } else {
            printf("❌ Error: Name must contain only alphabets!\n");
        }
    }

    // Marks Input
    while(1) {
        printf("Enter Marks: ");
        scanf("%s", input);

        if(isValidNumber(input)) {
            s[count].marks = atoi(input);
            break;
        } else {
            printf("❌ Error: Marks must be numeric only!\n");
        }
    }

    count++;
    printf("✅ Student added successfully!\n");
}

// Sort by Marks (Descending)
void sortStudents() {
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(s[j].marks < s[j + 1].marks) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// Display Report
void displayStudents() {
    if(count == 0) {
        printf("❌ No records found!\n");
        return;
    }

    sortStudents();

    printf("\n=========== SORTED STUDENT REPORT ===========\n");
    printf("Rank\tRoll\tName\t\tMarks\n");
    printf("------------------------------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%d\t%d\t%-15s\t%d\n",
               i + 1, s[i].roll, s[i].name, s[i].marks);
    }
}

// Search (Name or Roll)
void searchStudent() {
    if(count == 0) {
        printf("❌ No records available!\n");
        return;
    }

    char input[50];
    int found = 0;

    printf("Enter Name OR Roll Number: ");
    scanf("%s", input);

    sortStudents();

    if(isValidNumber(input)) {
        int roll = atoi(input);

        for(int i = 0; i < count; i++) {
            if(s[i].roll == roll) {
                printf("\n✅ Record Found!\n");
                printf("Roll  : %d\nName  : %s\nMarks : %d\nRank  : %d\n",
                       s[i].roll, s[i].name, s[i].marks, i + 1);
                found = 1;
                break;
            }
        }
    } else {
        for(int i = 0; i < count; i++) {
            if(strcmp(s[i].name, input) == 0) {
                printf("\n✅ Record Found!\n");
                printf("Roll  : %d\nName  : %s\nMarks : %d\nRank  : %d\n",
                       s[i].roll, s[i].name, s[i].marks, i + 1);
                found = 1;
            }
        }
    }

    if(!found)
        printf("❌ Record not found!\n");
}

// Main
int main() {
    int choice;

    printf("\n================================================\n");
    printf("        SORTING STUDENT MARKS SYSTEM\n");
    printf("================================================\n");

    while(1) {
        printf("\n1. Add Student");
        printf("\n2. Display Sorted Report");
        printf("\n3. Search");
        printf("\n4. Exit");
        printf("\nEnter choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: printf("✅ Exiting...\n"); return 0;
            default: printf("❌ Invalid choice!\n");
        }
    }

    return 0;
}