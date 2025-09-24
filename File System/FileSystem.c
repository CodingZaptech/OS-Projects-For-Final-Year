#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50

typedef struct {
    char name[MAX_FILENAME];
    int size; // Size in bytes
} File;

File fileSystem[MAX_FILES];
int fileCount = 0;

// Function declarations
void createFile();
void displayFiles();
void deleteFile();

int main() {
    int choice;

    printf("Welcome to Simple File System Simulator!\n");

    while (1) {
        printf("\n--- File System Menu ---\n");
        printf("1. Create File\n2. Display Files\n3. Delete File\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: createFile(); break;
            case 2: displayFiles(); break;
            case 3: deleteFile(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void createFile() {
    if (fileCount >= MAX_FILES) {
        printf("File system full!\n");
        return;
    }

    printf("Enter file name: ");
    fgets(fileSystem[fileCount].name, MAX_FILENAME, stdin);
    fileSystem[fileCount].name[strcspn(fileSystem[fileCount].name, "\n")] = 0; // remove newline

    printf("Enter file size (bytes): ");
    scanf("%d", &fileSystem[fileCount].size);
    getchar(); // consume newline

    fileCount++;
    printf("File created successfully!\n");
}

void displayFiles() {
    if (fileCount == 0) {
        printf("No files found.\n");
        return;
    }

    printf("\n--- Files in File System ---\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%d. %s (%d bytes)\n", i + 1, fileSystem[i].name, fileSystem[i].size);
    }
}

void deleteFile() {
    if (fileCount == 0) {
        printf("No files to delete.\n");
        return;
    }

    char filename[MAX_FILENAME];
    printf("Enter file name to delete: ");
    fgets(filename, MAX_FILENAME, stdin);
    filename[strcspn(filename, "\n")] = 0;

    for (int i = 0; i < fileCount; i++) {
        if (strcmp(fileSystem[i].name, filename) == 0) {
            for (int j = i; j < fileCount - 1; j++) {
                fileSystem[j] = fileSystem[j + 1];
            }
            fileCount--;
            printf("File deleted successfully!\n");
            return;
        }
    }

    printf("File not found!\n");
}
