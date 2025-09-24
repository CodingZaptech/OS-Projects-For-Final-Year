#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_CONTENT 1024

// Structure to represent a file
typedef struct {
    char name[50];
    char content[MAX_CONTENT];
} File;

// Array to hold files
File files[MAX_FILES];
int fileCount = 0;

// Function to create a file
void createFile(char *name) {
    if(fileCount >= MAX_FILES) {
        printf("Error: File limit reached.\n");
        return;
    }
    strcpy(files[fileCount].name, name);
    files[fileCount].content[0] = '\0'; // Empty content
    fileCount++;
    printf("File '%s' created successfully.\n", name);
}

// Function to write to a file
void writeFile(char *name, char *data) {
    for(int i = 0; i < fileCount; i++) {
        if(strcmp(files[i].name, name) == 0) {
            strcat(files[i].content, data);
            printf("Data written to '%s'.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

// Function to read a file
void readFile(char *name) {
    for(int i = 0; i < fileCount; i++) {
        if(strcmp(files[i].name, name) == 0) {
            printf("Content of '%s':\n%s\n", name, files[i].content);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}

// Function to delete a file
void deleteFile(char *name) {
    for(int i = 0; i < fileCount; i++) {
        if(strcmp(files[i].name, name) == 0) {
            for(int j = i; j < fileCount - 1; j++) {
                files[j] = files[j + 1]; // Shift remaining files
            }
            fileCount--;
            printf("File '%s' deleted successfully.\n", name);
            return;
        }
    }
    printf("Error: File '%s' not found.\n", name);
}
