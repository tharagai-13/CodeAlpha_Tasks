#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char dept[20];
};

void getFileName(char *fname);
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void updateStudent();

int main() {
    int choice;

    while (1) {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Ask user for file name
void getFileName(char *fname) {
    printf("Enter file name: ");
    scanf("%s", fname);
}

//ADD STUDENT

void addStudent() {
    char filename[100];
    getFileName(filename);

    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        char ch;
        printf("\nFile does not exist! Create new file? (y/n): ");
        scanf(" %c", &ch);

        if (ch == 'y' || ch == 'Y') {
            fp = fopen(filename, "wb"); 
            fclose(fp);
            printf("New file created.\n");
        } else {
            printf("Add operation cancelled.\n");
            return;
        }
    } else {
        fclose(fp);
    }

    fp = fopen(filename, "ab");

    struct Student s;

    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Department: ");
    scanf("%s", s.dept);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student Added Successfully to %s\n", filename);
}

//DISPLAY 

void displayStudents() {
    char filename[100];
    getFileName(filename);

    FILE *fp = fopen(filename, "rb");
    struct Student s;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\n--- Records in %s ---\n", filename);

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nID: %d\nName: %s\nAge: %d\nDepartment: %s\n",
               s.id, s.name, s.age, s.dept);
    }

    fclose(fp);
}

//SEARCH

void searchStudent() {
    char filename[100];
    getFileName(filename);

    FILE *fp = fopen(filename, "rb");
    struct Student s;
    int id, found = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter ID to Search: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("\nID: %d\nName: %s\nAge: %d\nDepartment: %s\n",
                   s.id, s.name, s.age, s.dept);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Record not found!\n");
}

//DELETE

void deleteStudent() {
    char filename[100];
    getFileName(filename);

    FILE *fp = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Student s;
    int id, found = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter ID to Delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(filename);
    rename("temp.dat", filename);

    if (found)
        printf("Record Deleted Successfully!\n");
    else
        printf("Record Not Found!\n");
}

// --------------- UPDATE ----------------

void updateStudent() {
    char filename[100];
    getFileName(filename);

    FILE *fp = fopen(filename, "rb+");
    struct Student s;
    int id, found = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\nEnter ID to Update: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("Enter New Name: ");
            scanf("%s", s.name);

            printf("Enter New Age: ");
            scanf("%d", &s.age);

            printf("Enter New Department: ");
            scanf("%s", s.dept);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);

            found = 1;
            printf("Record Updated Successfully!\n");
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Record Not Found!\n");
}
