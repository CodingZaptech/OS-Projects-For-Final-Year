#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulate a system call interface
void sysCallPrint(char *message) {
    printf("[System Call] %s\n", message);
}

int sysCallAdd(int a, int b) {
    return a + b;
}

int sysCallMultiply(int a, int b) {
    return a * b;
}
