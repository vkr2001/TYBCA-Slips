#include <stdio.h>

int isPresent(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

void printFrames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("- ");
        } else {
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

int main() {
    int n = 3;  // Number of frames
    int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int numPages = sizeof(referenceString) / sizeof(referenceString[0]);

    int frames[n];
    for (int i = 0; i < n; i++) {
        frames[i] = -1;  // Initialize all frames to -1 (empty)
    }

    int pageFaults = 0;
    int index = 0;

    printf("Page reference string: ");
    for (int i = 0; i < numPages; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n\n");

    printf("Page Scheduling:\n");

    for (int i = 0; i < numPages; i++) {
        int currentPage = referenceString[i];

        // Check if the page is already in the frames
        if (!isPresent(frames, n, currentPage)) {
            // Page fault occurred, replace the oldest page using FIFO
            frames[index] = currentPage;
            index = (index + 1) % n;  // Circular index for FIFO
            pageFaults++;
            printf("Page fault: ");
        } else {
            printf("No page fault: ");
        }

        // Print the current state of the frames
        printFrames(frames, n);
    }

    printf("\nTotal number of page faults: %d\n", pageFaults);

   return 0;
}