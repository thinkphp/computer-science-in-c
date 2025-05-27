#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Student {
    char name[50];
    int age;
    struct Student* next;
} Student;

Student* hashTable[SIZE];

// Funcție hash simplă (suma caracterelor mod SIZE)
unsigned int hash(const char* name) {
    unsigned int sum = 0;
    while (*name) {
        sum += *name++;
    }
    return sum % SIZE;
}

void insertStudent(const char* name, int age) {
    unsigned int index = hash(name);

    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = hashTable[index];

    hashTable[index] = newStudent;
}

Student* searchStudent(const char* name) {
    unsigned int index = hash(name);
    Student* current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printStudent(const char* name) {
    Student* student = searchStudent(name);
    if (student) {
        printf("Student: %s, Age: %d\n", student->name, student->age);
    } else {
        printf("Student %s not found.\n", name);
    }
}

void freeTable() {
    for (int i = 0; i < SIZE; ++i) {
        Student* current = hashTable[i];
        while (current) {
            Student* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    insertStudent("Alice", 20);
    insertStudent("Bob", 22);
    insertStudent("Charlie", 21);

    printStudent("Alice");
    printStudent("Bob");
    printStudent("David");

    freeTable();
    return 0;
}
