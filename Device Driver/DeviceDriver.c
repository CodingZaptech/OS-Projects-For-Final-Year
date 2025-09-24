#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DeviceDriverBackend.c"

int main() {
    int choice;
    char name[50];

    printf("Welcome to Device Driver Simulation!\n");

    while(1) {
        printf("\n1. Register Device\n2. Turn ON Device\n3. Turn OFF Device\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Enter device name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                registerDevice(name);
                break;
            case 2:
                printf("Enter device name to turn ON: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                turnOnDevice(name);
                break;
            case 3:
                printf("Enter device name to turn OFF: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                turnOffDevice(name);
                break;
            case 4:
                printf("Exiting Device Driver Simulation...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
