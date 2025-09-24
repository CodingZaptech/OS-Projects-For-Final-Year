#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChatApplicationBackend.c"

int main() {
    char sender[50], message[256];
    int choice;

    printf("Welcome to Local Chat Application!\n");

    while(1) {
        printf("\n1. Send Message\n2. Show Chat History\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch(choice) {
            case 1:
                printf("Enter sender name: ");
                fgets(sender, sizeof(sender), stdin);
                sender[strcspn(sender, "\n")] = 0;
                printf("Enter message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                sendMessage(sender, message);
                break;
            case 2:
                showMessages();
                break;
            case 3:
                printf("Exiting Chat Application...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
