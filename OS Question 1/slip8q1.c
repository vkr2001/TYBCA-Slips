// Q.1 Write a C program to accept the number of process and resources and find the need matrix
// content and display it

#include <stdio.h>

void calculateNeedMatrix(int need[][10], int max[][10], int allocation[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void displayMatrix(int matrix[][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m; // n = number of processes, m = number of resources

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[10][10], max[10][10], need[10][10];

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the Maximum Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    calculateNeedMatrix(need, max, allocation, n, m);

    printf("Need Matrix:\n");
    displayMatrix(need, n, m);

    return 0;
}
