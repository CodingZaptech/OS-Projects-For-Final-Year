#include <stdio.h>
#include <stdlib.h>
#include "DiskSchedulingBackend.c"

int main() {
    int n, track, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests (track numbers 0-199):\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &track);
        addRequest(track);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    FCFS(head);

    return 0;
}
