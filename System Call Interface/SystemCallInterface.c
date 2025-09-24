#include <stdio.h>
#include <stdlib.h>
#include "SystemCallInterfaceBackend.c"

int main() {
    int a, b;
    printf("Welcome to System Call Interface Simulation!\n");

    sysCallPrint("This message is from a system call simulation.");

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Addition: %d\n", sysCallAdd(a, b));
    printf("Multiplication: %d\n", sysCallMultiply(a, b));

    return 0;
}
