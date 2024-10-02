#include <stdio.h>
#include <stdlib.h>

// slip1_or_q2

#define MAX_PROCESSES 10
#define MAX_RESOURCES 3

void getMatrix(int matrix[MAX_PROCESSES][MAX_RESOURCES], int rows, int cols, const char* name) {
	int i,j;
    printf("Enter the %s matrix:\n", name);
    for (i = 0; i < rows; i++) {
        printf("Enter row %d (space-separated values): ", i + 1);
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_PROCESSES][MAX_RESOURCES], int rows, int cols, const char* name) {
	int i,j;
    printf("\n%s matrix:\n", name);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int allocation[MAX_PROCESSES][MAX_RESOURCES], int numProcesses, int numResources) {
	int i,j;
    for (i = 0; i < numProcesses; i++) {
        for (j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void displayAvailable(int available[MAX_RESOURCES], int numResources) {
	int i;
    printf("\nAvailable resources:\n");
    for (i = 0; i < numResources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

int main() {
	int i;
    int numProcesses, numResources = MAX_RESOURCES;
    int available[MAX_RESOURCES] = {7, 2, 6};  
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];

    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);
    if (numProcesses > MAX_PROCESSES || numProcesses <= 0) {
        printf("Error: Invalid number of processes. Exiting.\n");
        return 1;
    }

    printf("Enter the available resources A, B, C (space-separated): ");
    for (i = 0; i < numResources; i++) {
        scanf("%d", &available[i]);
    }
    
   
    getMatrix(allocation, numProcesses, numResources, "Allocation");
    getMatrix(max, numProcesses, numResources, "Max");


    calculateNeed(need, max, allocation, numProcesses, numResources);

    displayAvailable(available, numResources);
    printMatrix(allocation, numProcesses, numResources, "Allocation");
    printMatrix(max, numProcesses, numResources, "Max");
    printMatrix(need, numProcesses, numResources, "Need");

   return 0;
}