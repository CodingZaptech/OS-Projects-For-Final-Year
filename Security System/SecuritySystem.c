#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BasicSecurityBackend.c"

int main() {
    int choice;
    char username[50], password[50];

    printf("Welcome to Basic Security System!\n");

    while(1) {
        printf("\n1. Register User\n2. Login\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0;
                registerUser(username, password);
                break;
            case 2:
                printf("Enter username: ");
                fgets(username, sizeof(username), stdin);
                username[strcspn(username, "\n")] = 0;
                printf("Enter password: ");
                fgets(password, sizeof(password), stdin);
                password[strcspn(password, "\n")] = 0;
                if(authenticate(username, password)) {
                    printf("Login successful! Welcome, %s.\n", username);
                } else {
                    printf("Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Exiting Security System...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
