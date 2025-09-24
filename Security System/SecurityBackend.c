#include <stdio.h>
#include <string.h>

#define MAX_USERS 5

typedef struct {
    char username[50];
    char password[50];
} User;

User users[MAX_USERS];
int userCount = 0;

// Function to register a user
void registerUser(char *username, char *password) {
    if(userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    userCount++;
    printf("User '%s' registered successfully.\n", username);
}

// Function to authenticate a user
int authenticate(char *username, char *password) {
    for(int i = 0; i < userCount; i++) {
        if(strcmp(users[i].username, username) == 0 &&
           strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}
