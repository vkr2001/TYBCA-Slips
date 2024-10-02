#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct job {
    int atime;   // Arrival time.
    int btime;   // Burst time (first CPU burst).
    int ft;      // Finish time.
    int tat;     // Turnaround time.
    int wt;      // Waiting time.
    int pri;     // Priority.
    int next_btime; // Next burst time generated randomly.
    int completed;  // Completion flag (1 if completed, 0 otherwise).
} p[10];

int n, rq[10], no_rq = 0, current_time = 0, j = -1;  // Renamed 'time' to 'current_time'
const int IO_WAIT_TIME = 2; // Fixed I/O wait time

void addrq();
int selectionjob();
void deleteq(int k);
int all_completed();
void print_gantt_chart();

int main() {
    srand(time(0));  // Seed the random number generator.

    int i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the arrival time of p%d: ", i);
        scanf("%d", &p[i].atime);

        printf("Enter the burst time of p%d: ", i);
        scanf("%d", &p[i].btime);

        printf("Enter the priority of p%d (lower value = higher priority): ", i);
        scanf("%d", &p[i].pri);

        p[i].completed = 0;  // Mark the process as not completed initially.
        p[i].next_btime = -1; // Placeholder for the next burst time.
    }

    addrq();  // Add the processes to the ready queue.

    printf("\nGantt Chart:\n");
    while (1) {
        j = selectionjob();  // Select the next process based on priority.

        if (j == -1) {
            printf("| Idle ");
            current_time++;  // Use current_time instead of time.
            addrq();  // Check if any process arrives during idle time.
        } else {
            // Process selected: Execute first burst.
            printf("| P%d ", j);
            current_time += p[j].btime;  // Use current_time instead of time.
            p[j].ft = current_time;  // Set finish time after completing the burst.

            // Simulate I/O wait time.
            printf("| IO ");
            current_time += IO_WAIT_TIME;  // Simulate I/O wait.

            // Generate random burst time for the next CPU burst.
            p[j].next_btime = rand() % 5 + 1;  // Random burst between 1 and 5.
            current_time += p[j].next_btime;

            // Mark process as completed.
            p[j].completed = 1;

            addrq();  // Check if any new process arrives during the execution.
        }

        if (all_completed())  // If all processes are completed, exit the loop.
            break;
    }

    printf("|\n\n");

    // Calculate turnaround time and waiting time.
    int total_tat = 0, total_wt = 0;

    printf("Job\tArrival\tBurst\tFinish\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ft - p[i].atime;
        p[i].wt = p[i].tat - p[i].btime;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].atime, p[i].btime, p[i].ft, p[i].tat, p[i].wt);

        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    float avg_tat = (float)total_tat / n;
    float avg_wt = (float)total_wt / n;

    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}

// Function to add processes to the ready queue based on arrival time.
void addrq() {
    int i;
    for (i = 0; i < n; i++) {
        if (p[i].atime == current_time && !p[i].completed) {
            rq[no_rq++] = i;
        }
    }
}

// Function to select the job with the highest priority from the ready queue.
int selectionjob() {
    if (no_rq == 0)
        return -1;  // No process in the ready queue.

    int i, k = rq[0];
    for (i = 1; i < no_rq; i++) {
        if (p[k].pri > p[rq[i]].pri) {  // Compare priorities.
            k = rq[i];  // Select the process with the highest priority.
        }
    }
    deleteq(k);  // Remove the selected job from the ready queue.
    return k;
}

// Function to remove the selected job from the ready queue.
void deleteq(int k) {
    int i, pos = -1;
    for (i = 0; i < no_rq; i++) {
        if (rq[i] == k) {
            pos = i;
            break;
        }
    }
    for (i = pos + 1; i < no_rq; i++) {
        rq[i - 1] = rq[i];
    }
    no_rq--;  // Reduce the size of the ready queue.
}

// Function to check if all processes are completed.
int all_completed() {
    int i;
    for (i = 0; i < n; i++) {
        if (!p[i].completed) {
            return 0;  // If any process is not completed, return 0.
        }
    }
    return 1;  // All processes are completed.
}
