#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int requests[MAX_REQUESTS];
int requestCount = 0;

// Function to add disk request
void addRequest(int track) {
    requests[requestCount++] = track;
}

// FCFS Disk Scheduling with detailed tracking and seek visualization
void FCFS(int head) {
    int totalSeek = 0;
    printf("\n--- FCFS Disk Scheduling ---\n");
    printf("Head starts at: %d\n", head);
    printf("Order of service:\n");

    for(int i = 0; i < requestCount; i++) {
        int seek = abs(head - requests[i]);
        printf("Move from %d -> %d | Seek: %d\n", head, requests[i], seek);
        totalSeek += seek;
        head = requests[i];
    }

    printf("Total seek operations: %d\n", totalSeek);
    printf("Average seek length: %.2f\n", (float)totalSeek / requestCount);

    // Graphical representation (simple horizontal chart)
    printf("\nDisk Head Movement Chart:\n");
    for(int i = 0; i < requestCount; i++) {
        printf("%d: ", requests[i]);
        for(int j = 0; j < requests[i]; j += 5) { // Scale factor for visualization
            printf("-");
        }
        printf("|\n");
    }
}
