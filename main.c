/*
 * Clinic Management System
 * Author: AlHussien Mustafa
 */
 
#include <stdio.h>
#include "Program.h"

int main() {
    int mode;
    while (1) {
        printf("\n*** Clinic Management System ***\n");
        printf("1. Admin mode\n");
        printf("2. User mode\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &mode);

        switch(mode) {
            case 1: adminMode(); break;
            case 2: userMode(); break;
            case 3: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
