// Q.1 Write the program to calculate minimum number of resources needed to avoid
// deadlock. 

#include <stdio.h>

// Function to calculate the minimum resources needed to avoid deadlock
void calculateMinimumResources(int processes, int resources, int available[resources], int allocated[processes][resources], int maximum[processes][resources]) {
    int need[processes][resources];
    int work[resources];
    int finish[processes];
    int safe_sequence[processes];
    int work_copy[resources];

    // Initialize work, finish, and safe_sequence arrays
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < processes; i++) {
        finish[i] = 0;
    }

    // Calculate the need matrix
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = maximum[i][j] - allocated[i][j];
        }
    }

    int count = 0;
    while (count < processes) {
        int found = 0;

        for (int i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == resources) {
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocated[i][k];
                    }
                    safe_sequence[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is not in a safe state. Deadlock detected!\n");
            return;
        }
    }

    printf("System is in a safe state. Safe sequence: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", safe_sequence[i]);
    }
    printf("\n");

    printf("Minimum resources needed to avoid deadlock: ");
    for (int i = 0; i < resources; i++) {
        work_copy[i] = available[i];
        for (int j = 0; j < processes; j++) {
            work_copy[i] -= allocated[j][i];
        }
        printf("%d ", work_copy[i]);
    }
    printf("\n");
}

int main() {
    int processes = 5; // Number of processes
    int resources = 3; // Number of resource types

    int available[] = {3, 3, 2};

    int allocated[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    int maximum[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};

    calculateMinimumResources(processes, resources, available, allocated, maximum);

    return 0;
}
