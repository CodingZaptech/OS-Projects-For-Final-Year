#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VirtualOSManagerBackend.c"

int main() {
    int choice, memory, cpu;
    char name[50];

    printf("Welcome to Virtual OS Manager!\n");

    while(1) {
        printf("\n1. Add Virtual OS\n2. Display Virtual OSes\n3. Terminate Virtual OS\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch(choice) {
            case 1:
                printf("Enter OS name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter memory (MB) and CPU usage (%%): ");
                scanf("%d %d", &memory, &cpu);
                addVirtualOS(name, memory, cpu);
                break;
            case 2:
                displayVirtualOSes();
                break;
            case 3:
                printf("Enter OS name to terminate: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                terminateVirtualOS(name);
                break;
            case 4:
                printf("Exiting Virtual OS Manager...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
