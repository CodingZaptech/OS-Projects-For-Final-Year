#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGES 100
#define MAX_LEN 256

typedef struct {
    char sender[50];
    char message[MAX_LEN];
} ChatMessage;

ChatMessage messages[MAX_MESSAGES];
int msgCount = 0;

// Function to send message
void sendMessage(char *sender, char *message) {
    if(msgCount >= MAX_MESSAGES) {
        printf("Message storage full!\n");
        return;
    }
    strcpy(messages[msgCount].sender, sender);
    strcpy(messages[msgCount].message, message);
    msgCount++;
}

// Function to display chat history
void showMessages() {
    printf("\n--- Chat History ---\n");
    for(int i = 0; i < msgCount; i++) {
        printf("%s: %s\n", messages[i].sender, messages[i].message);
    }
}
