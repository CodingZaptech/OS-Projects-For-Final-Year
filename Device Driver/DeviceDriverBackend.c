#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char deviceName[50];
    int status; // 0 = off, 1 = on
} Device;

Device devices[10];
int deviceCount = 0;

// Function to register device
void registerDevice(char *name) {
    strcpy(devices[deviceCount].deviceName, name);
    devices[deviceCount].status = 0;
    deviceCount++;
    printf("Device '%s' registered.\n", name);
}

// Function to turn on device
void turnOnDevice(char *name) {
    for(int i = 0; i < deviceCount; i++) {
        if(strcmp(devices[i].deviceName, name) == 0) {
            devices[i].status = 1;
            printf("Device '%s' turned ON.\n", name);
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}

// Function to turn off device
void turnOffDevice(char *name) {
    for(int i = 0; i < deviceCount; i++) {
        if(strcmp(devices[i].deviceName, name) == 0) {
            devices[i].status = 0;
            printf("Device '%s' turned OFF.\n", name);
            return;
        }
    }
    printf("Device '%s' not found!\n", name);
}
