#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileSystemBackend.c"

int main() {
    int choice;
    char name[50], data[500];

    printf("Welcome to Simple File System!\n");

    while(1) {
        printf("\n--- File System Menu ---\n");
        printf("1. Create File\n2. Write File\n3. Read File\n4. Delete File\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch(choice) {
            case 1:
                printf("Enter file name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                createFile(name);
                break;
            case 2:
                printf("Enter file name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter data to write: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = 0;
                writeFile(name, data);
                break;
            case 3:
                printf("Enter file name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                readFile(name);
                break;
            case 4:
                printf("Enter file name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                deleteFile(name);
                break;
            case 5:
                printf("Exiting File System...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
