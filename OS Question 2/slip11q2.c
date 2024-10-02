#include <stdio.h>

void print_frames(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int main() {
    int n;  // Number of memory frames
    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    int reference_string[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};  // The given reference string
    int ref_len = sizeof(reference_string) / sizeof(reference_string[0]);  // Length of the reference string

    int frames[n];  // Array to hold the frames in memory
    for (int i = 0; i < n; i++) frames[i] = -1;  // Initialize frames to -1 (empty)

    int page_faults = 0;  // Counter for page faults
    int next_to_replace = 0;  // FIFO replacement index

    printf("\nPage Reference String: ");
    for (int i = 0; i < ref_len; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\n\nPage Scheduling:\n");

    for (int i = 0; i < ref_len; i++) {
        int page = reference_string[i];
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < n; j++) {
            if (frames[j] == page) {
                found = 1;  // Page is found in memory, no page fault
                break;
            }
        }

        if (!found) {
            // Page is not found in memory, page fault occurs
            frames[next_to_replace] = page;  // Replace the oldest page
            next_to_replace = (next_to_replace + 1) % n;  // Update the replacement pointer
            page_faults++;  // Increment page fault counter

            print_frames(frames, n);  // Print the current state of frames
        }
    }

    printf("\nTotal number of page faults: %d\n", page_faults);

    return 0;
}
