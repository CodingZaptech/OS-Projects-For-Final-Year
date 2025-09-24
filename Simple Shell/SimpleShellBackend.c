#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to execute a command
void executeCommand(char *command) {
    char *args[10]; // Array to hold command and arguments
    int i = 0;

    // Split command into arguments using space
    args[i] = strtok(command, " \n");
    while(args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \n");
    }

    // Fork a child process to execute the command
    pid_t pid = fork();
    if(pid < 0) {
        perror("Fork failed");
        return;
    }
    if(pid == 0) {
        // Child process executes the command
        if(execvp(args[0], args) < 0) {
            perror("Execution failed");
        }
        exit(0);
    } else {
        // Parent waits for child to finish
        wait(NULL);
    }
}
