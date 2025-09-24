#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int memory; // Memory in MB
    int cpuUsage; // CPU usage in percentage
} VirtualOS;

VirtualOS voses[10];
int vosCount = 0;

// Function to add a virtual OS
void addVirtualOS(char *name, int memory, int cpuUsage) {
    strcpy(voses[vosCount].name, name);
    voses[vosCount].memory = memory;
    voses[vosCount].cpuUsage = cpuUsage;
    vosCount++;
    printf("Virtual OS '%s' added successfully.\n", name);
}

// Function to display all virtual OSes
void displayVirtualOSes() {
    printf("\nName\tMemory(MB)\tCPU Usage(%%)\n");
    for(int i = 0; i < vosCount; i++) {
        printf("%s\t%d\t\t%d\n", voses[i].name, voses[i].memory, voses[i].cpuUsage);
    }
}

// Function to terminate a virtual OS
void terminateVirtualOS(char *name) {
    for(int i = 0; i < vosCount; i++) {
        if(strcmp(voses[i].name, name) == 0) {
            for(int j = i; j < vosCount - 1; j++) {
                voses[j] = voses[j+1];
            }
            vosCount--;
            printf("Virtual OS '%s' terminated.\n", name);
            return;
        }
    }
    printf("Error: Virtual OS '%s' not found.\n", name);
}
