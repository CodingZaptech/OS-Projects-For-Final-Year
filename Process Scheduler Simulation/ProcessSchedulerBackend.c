#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int pid;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

Process processes[100];
int processCount = 0;

// Function to add a process
void addProcess(int pid, int burstTime) {
    processes[processCount].pid = pid;
    processes[processCount].burstTime = burstTime;
    processes[processCount].waitingTime = 0;
    processes[processCount].turnaroundTime = 0;
    processCount++;
}

// Function to calculate waiting and turnaround time using FCFS
void calculateTimes() {
    int totalWait = 0, totalTurnaround = 0;
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;

    for(int i = 1; i < processCount; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    printf("\nPID\tBurst\tWaiting\tTurnaround\n");
    for(int i = 0; i < processCount; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
        totalWait += processes[i].waitingTime;
        totalTurnaround += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWait / processCount);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaround / processCount);
}
