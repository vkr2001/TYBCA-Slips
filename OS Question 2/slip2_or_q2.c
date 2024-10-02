#include <stdio.h>

#define PROCESSES 5
#define RESOURCES 4

// slip2_or_q2

// Function to calculate the need matrix
void calculateNeed(int need[PROCESSES][RESOURCES], int max[PROCESSES][RESOURCES], int allocation[PROCESSES][RESOURCES]) {
         int i,j;
	for ( i = 0; i < PROCESSES; i++) {
          for ( j = 0; j < RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to check if the system is in a safe state
int isSafe(int available[RESOURCES], int max[PROCESSES][RESOURCES], int allocation[PROCESSES][RESOURCES]) {
    int work[RESOURCES];
    int finish[PROCESSES] = {0};  // Replace bool array with int array initialized to 0
    int need[PROCESSES][RESOURCES];

    calculateNeed(need, max, allocation);

    // Initialize work as a copy of available
        int i;
	for ( i = 0; i < RESOURCES; i++) {
        work[i] = available[i];
    }

    int safeSequence[PROCESSES];
    int count = 0;

    while (count < PROCESSES) {
        int found = 0;  // Replace bool with int (0 for false, 1 for true)
         int p;
	for (p = 0; p < PROCESSES; p++) {
            if (finish[p] == 0) {  // Check if process is not finished
                int j;
                for (j = 0; j < RESOURCES; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }

                // If all resources for P are satisfied
                if (j == RESOURCES) {
                   int k;
		 for ( k = 0; k < RESOURCES; k++) {
                        work[k] += allocation[p][k];
                    }

                    safeSequence[count++] = p;
                    finish[p] = 1;  // Mark process as finished
                    found = 1;  // Set found to true
                }
            }
        }

        if (found == 0) {
            printf("System is not in a safe state.\n");
            return 0;  // Return false
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
   	
	 for ( i = 0; i < PROCESSES; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;  // Return true
}

// Function to check if the request can be granted
int requestResource(int process, int request[], int available[], int max[][RESOURCES], int allocation[][RESOURCES]) {
    int need[PROCESSES][RESOURCES];
    calculateNeed(need, max, allocation);

    // Check if request is less than need
   	  int i;
	 for (i = 0; i < RESOURCES; i++) {
        if (request[i] > need[process][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return 0;  // Return false
        }
    }

    // Check if request is less than available
    	
	for ( i = 0; i < RESOURCES; i++) {
        if (request[i] > available[i]) {
            printf("Error: Resources are not available.\n");
            return 0;  // Return false
        }
    }

    // Pretend to allocate requested resources
    for (i = 0; i < RESOURCES; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
    }

    // Check if system is in a safe state after allocation
    if (isSafe(available, max, allocation)) {
        printf("The request can be granted.\n");
        return 1;  // Return true
    } else {
        // Revert the allocation if it leads to an unsafe state
        for ( i = 0; i < RESOURCES; i++) {
            available[i] += request[i];
            allocation[process][i] -= request[i];
        }
        printf("The request cannot be granted as it leads to an unsafe state.\n");
        return 0;  // Return false
    }
}

int main() {
    int available[RESOURCES] = {1, 5, 2, 0};  // Available resources

    int max[PROCESSES][RESOURCES] = { // Maximum demand of each process
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6}
    };

    int allocation[PROCESSES][RESOURCES] = { // Resources allocated to each process
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4}
    };

    // Display the need matrix
    int need[PROCESSES][RESOURCES];
    calculateNeed(need, max, allocation);
    printf("Need matrix:\n");
     int i , j;
     for ( i = 0; i < PROCESSES; i++) {
        for ( j = 0; j < RESOURCES; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Check if the system is in a safe state
    isSafe(available, max, allocation);

    // Request for resources by P1
    int request[RESOURCES] = {0, 4, 2, 0};
    printf("\nRequest from P1 for resources (0, 4, 2, 0):\n");
    requestResource(1, request, available, max, allocation);

   return 0;
}