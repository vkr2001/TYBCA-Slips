#include <stdio.h>
#include <stdlib.h>

#define IO_WAIT_TIME 2  // Fixed IO waiting time (2 units)

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

void roundRobin(int n, int arrivalTime[], int burstTime[], int timeQuantum) {
    int waitingTime[n], turnaroundTime[n], remainingBurstTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int currentTime = 0, completed = 0, i;

    // Copy burst times to remaining burst times
    for (i = 0; i < n; i++) {
        remainingBurstTime[i] = burstTime[i];
        waitingTime[i] = 0;  // Initialize waiting times to 0
    }

    printf("Gantt Chart:\n");
    printf("0");  // Starting time of Gantt chart

    // Process until all processes are completed
    while (completed < n) {
        int allDone = 1;

        for (i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                allDone = 0;  // At least one process is still remaining

                // Check if the process has arrived
                if (arrivalTime[i] <= currentTime) {
                    int timeUsed = (remainingBurstTime[i] <= timeQuantum) ? remainingBurstTime[i] : timeQuantum;
                    
                    // Process execution in Gantt chart
                    currentTime += timeUsed;
                    remainingBurstTime[i] -= timeUsed;
                    printf(" -> P%d -> %d", i + 1, currentTime);  // Gantt Chart representation

                    // If the process is completed
                    if (remainingBurstTime[i] == 0) {
                        completed++;
                        turnaroundTime[i] = currentTime - arrivalTime[i];
                        waitingTime[i] = turnaroundTime[i] - burstTime[i];
                        totalWaitingTime += waitingTime[i];
                        totalTurnaroundTime += turnaroundTime[i];
                    } else {
                        // I/O wait time is added if process has to wait after execution slice
                        currentTime += IO_WAIT_TIME;
                    }
                }
            }
        }

        // If no process has arrived by currentTime, move to the next arrival time
        if (allDone) {
            currentTime++;
        }
    }

    printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n, i, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n];

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d Arrival Time: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Process P%d Burst Time: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    roundRobin(n, arrivalTime, burstTime, timeQuantum);

  return 0;
}