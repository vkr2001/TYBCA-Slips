#include <stdio.h>

#define MAX 20 // Maximum number of pages in the reference string

// Function to find the optimal page to replace
int findOptimal(int frames[], int ref[], int n, int index) {
    int pos = -1, farthest = index;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = index; j < MAX; j++) {
            if (frames[i] == ref[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        // If a frame is not going to be used in the future, return its index
        if (j == MAX)
            return i;
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int ref[MAX] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8}; // Reference string
    int frames[3]; // Memory frames (3 frames)
    int pageFaults = 0, m = 3; // Number of page faults and frame size
    int index = 0;

    // Initialize all frames to -1 (indicating empty)
    for (int i = 0; i < m; i++)
        frames[i] = -1;

    printf("Page Reference\tMemory Frames\n");
    for (int i = 0; i < MAX; i++) {
        int flag = 0;
        // Check if page is already in memory
        for (int j = 0; j < m; j++) {
            if (frames[j] == ref[i]) {
                flag = 1;
                break;
            }
        }
        // Page fault occurs
        if (flag == 0) {
            if (index < m) {
                frames[index++] = ref[i]; // Fill empty frames first
            } else {
                // Replace the page using the optimal algorithm
                int optIndex = findOptimal(frames, ref, m, i + 1);
                frames[optIndex] = ref[i];
            }
            pageFaults++;
        }
        
        // Print current state of frames
        printf("%d\t\t", ref[i]);
        for (int k = 0; k < m; k++) {
            if (frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;

}