#include <stdio.h>
#include <stdlib.h>

struct job {
    int atime;  // Arrival time.
    int btime;  // Burst time.
    int ft;     // Finish time.
    int tat;    // Turnaround time.
    int wt;     // Waiting time.
    int pri;    // Priority variable.
} p[10];

int arr[10], burst[10], n, rq[10], no_rq = 0, time = 0, j = -1;

void addrq();
int selectionjob();
void deleteq(int k);
int fsahll();

void main() {
    int i;
    printf("Enter the job number: ");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Enter the arrival time of p%d: ", i);
        scanf("%d", &p[i].atime);  // Assigning the arrival time.
        arr[i] = p[i].atime;
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Enter the burst time of p%d: ", i);
        scanf("%d", &p[i].btime);  // Assigning the burst time.
        burst[i] = p[i].btime;
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("Enter the priority of p%d: ", i);
        scanf("%d", &p[i].pri);  // Assigning the priority.
    }
    printf("\n");

    addrq();  // Adding the process to the ready queue.
    
    // Process start now.
    while (1) {
        j = selectionjob();  // Search the next process based on priority.

        if (j == -1) {
            printf("CPU is idle\n");
            time++;
            addrq();  // Check if any job arrives during the idle period.
        } else {
            while (burst[j] != 0) {
                printf("\t Executing job %d\n", j);
                burst[j]--;  // Decrease the burst time.
                time++;
                addrq();  // Add new jobs that arrive during the execution.
            }
            p[j].ft = time;  // Set the finish time.
        }

        if (fsahll() == 1)  // Check if all jobs are completed.
            break;
    }

    int Tat = 0, Twt = 0;

    printf("\nJob \t FT \t TAT \t WT\n");
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ft - p[i].atime;
        p[i].wt = p[i].tat - p[i].btime;

        printf("Job %d \t %d \t %d \t %d\n", i, p[i].ft, p[i].tat, p[i].wt);
        Tat += p[i].tat;
        Twt += p[i].wt;
    }

    float avgtat = (float)Tat / n;
    float avgwt = (float)Twt / n;

    printf("\nAverage turnaround time: %f", avgtat);
    printf("\nAverage waiting time: %f", avgwt);
    printf("\n");
}

void addrq() {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == time) {
            rq[no_rq++] = i;
        }
    }
}

int selectionjob() {
    int i, k;

    if (no_rq == 0)
        return -1;  // No job in the ready queue.

    k = rq[0];  // Assume the first job in the ready queue has the highest priority.

    for (i = 1; i < no_rq; i++) {
        if (p[k].pri < p[rq[i]].pri) {  // Compare priorities.
            k = rq[i];  // Update the job with the highest priority.
        }
    }
    deleteq(k);  // Remove the selected job from the ready queue.
    return k;
}

void deleteq(int k) {
    int i, pos = -1;

    // Find the position of the job in the ready queue.
    for (i = 0; i < no_rq; i++) {
        if (rq[i] == k) {
            pos = i;
            break;
        }
    }

    // Shift the elements of the ready queue.
    for (i = pos + 1; i < no_rq; i++) {
        rq[i - 1] = rq[i];
    }
    no_rq--;  // Decrease the count of jobs in the ready queue.
}

int fsahll() {
    int i;
    for (i = 0; i < n; i++) {
        if (burst[i] != 0)
            return -1;  // If any job's burst time is not zero, continue.
    }
    return 1;  // All jobs are completed.
}
