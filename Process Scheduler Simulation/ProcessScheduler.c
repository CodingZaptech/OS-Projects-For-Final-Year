#include <stdio.h>
#include <stdlib.h>
#include "ProcessSchedulerBackend.c"

int main() {
    int n, pid, burst;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter PID and Burst Time for process %d: ", i+1);
        scanf("%d %d", &pid, &burst);
        addProcess(pid, burst);
    }

    calculateTimes();

    return 0;
}
