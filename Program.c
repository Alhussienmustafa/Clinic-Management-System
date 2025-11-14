#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Program.h"

#define PASSWORD 1234
#define MAX_TRIALS 3
#define MAX_NAME_LEN 50
#define MAX_GENDER_LEN 10
#define NUM_SLOTS 5

// Patient structure
typedef struct Patient {
    char name[MAX_NAME_LEN];
    int age;
    char gender[MAX_GENDER_LEN];
    int id;
    struct Patient* next;
} Patient;

// Global variables
Patient* head = NULL;   // linked list head
int slots[NUM_SLOTS] = {0, 0, 0, 0, 0}; // 0 = free
const char* slotTimes[NUM_SLOTS] = {
    "2:00pm to 2:30pm",
    "2:30pm to 3:00pm",
    "3:00pm to 3:30pm",
    "4:00pm to 4:30pm",
    "4:30pm to 5:00pm"
};

// find patient by ID
Patient* findPatient(int id) {
    Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Admin functions
void addPatient() {
    Patient* newP = (Patient*)malloc(sizeof(Patient));
    if (!newP) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter patient ID: ");
    scanf("%d", &newP->id);

    if (findPatient(newP->id)) {
        printf("Error: ID already exists!\n");
        free(newP);
        return;
    }

    printf("Enter name: ");
    scanf("%s", newP->name);
    printf("Enter age: ");
    scanf("%d", &newP->age);
    printf("Enter gender: ");
    scanf("%s", newP->gender);

    newP->next = head;
    head = newP;

    printf("Patient added successfully.\n");
}

void editPatient() {
    int id;
    printf("Enter patient ID to edit: ");
    scanf("%d", &id);

    Patient* p = findPatient(id);
    if (!p) {
        printf("Incorrect ID.\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", p->name);
    printf("Enter new age: ");
    scanf("%d", &p->age);
    printf("Enter new gender: ");
    scanf("%s", p->gender);

    printf("Patient record updated.\n");
}

void reserveSlot() {
    printf("Available slots:\n");
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (slots[i] == 0) {
            printf("%d. %s\n", i+1, slotTimes[i]);
        }
    }

    int id, choice;
    printf("Enter patient ID: ");
    scanf("%d", &id);
    if (!findPatient(id)) {
        printf("Incorrect ID.\n");
        return;
    }

    printf("Enter slot number: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > NUM_SLOTS || slots[choice-1] != 0) {
        printf("Invalid or unavailable slot.\n");
        return;
    }

    slots[choice-1] = id;
    printf("Reservation successful.\n");
}

void cancelReservation() {
    int id;
    printf("Enter patient ID to cancel reservation: ");
    scanf("%d", &id);

    for (int i = 0; i < NUM_SLOTS; i++) {
        if (slots[i] == id) {
            slots[i] = 0;
            printf("Reservation cancelled.\n");
            return;
        }
    }
    printf("No reservation found for this ID.\n");
}

// User functions
void viewPatient() {
    int id;
    printf("Enter patient ID: ");
    scanf("%d", &id);

    Patient* p = findPatient(id);
    if (!p) {
        printf("Patient not found.\n");
        return;
    }

    printf("Patient Info:\n");
    printf("ID: %d, Name: %s, Age: %d, Gender: %s\n",
           p->id, p->name, p->age, p->gender);
}

void viewReservations() {
    printf("Today's reservations:\n");
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (slots[i] == 0) {
            printf("%s --> Available\n", slotTimes[i]);
        } else {
            printf("%s --> Reserved (ID: %d)\n", slotTimes[i], slots[i]);
        }
    }
}

// Modes
void adminMode() {
    int pass, trials = 0;
    while (trials < MAX_TRIALS) {
        printf("Enter admin password: ");
        scanf("%d", &pass);
        if (pass == PASSWORD) break;
        else {
            trials++;
            if (trials == MAX_TRIALS) {
                printf("Too many incorrect attempts. System closed.\n");
                exit(0);
            }
            printf("Incorrect password. Try again.\n");
        }
    }

    int choice;
    do {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add new patient\n");
        printf("2. Edit patient\n");
        printf("3. Reserve slot\n");
        printf("4. Cancel reservation\n");
        printf("5. Back to main menu\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addPatient(); break;
            case 2: editPatient(); break;
            case 3: reserveSlot(); break;
            case 4: cancelReservation(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

void userMode() {
    int choice;
    do {
        printf("\n--- User Menu ---\n");
        printf("1. View patient record\n");
        printf("2. View today's reservations\n");
        printf("3. Back to main menu\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: viewPatient(); break;
            case 2: viewReservations(); break;
            case 3: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 3);
}