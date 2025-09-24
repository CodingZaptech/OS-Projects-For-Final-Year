#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SimpleShellBackend.c"

int main() {
    char command[100];

    printf("Welcome to Simple Shell!\n");
    printf("Type 'exit' to quit.\n");

    while(1) {
        printf(">> ");
        fgets(command, sizeof(command), stdin);

        // Exit condition
        if(strncmp(command, "exit", 4) == 0) {
            printf("Exiting Simple Shell...\n");
            break;
        }

        // Execute the entered command
        executeCommand(command);
    }

    return 0;
}
