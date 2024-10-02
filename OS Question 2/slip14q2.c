#include <stdio.h>

int main() {
    int n = 3;  // Number of memory frames
    int reference_string[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};  // Given reference string
    int ref_len = sizeof(reference_string) / sizeof(reference_string[0]);  // Length of reference string

    int frames[n];  // Array to hold the memory frames
    for (int i = 0; i < n; i++) frames[i] = -1;  // Initialize frames to -1 (empty)

    int page_faults = 0;  // Counter for page faults
    int index = 0;  // Index to keep track of which frame to replace (FIFO)

    printf("Page Reference String: ");
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
                found = 1;  // Page is already in memory, no page fault
                break;
            }
        }

        if (!found) {
            // Page is not in memory, so replace the page using FIFO
            frames[index] = page;
            index = (index + 1) % n;  // Update the index for the next replacement (FIFO)
            page_faults++;  // Increment the page fault counter

            // Print the current state of the frames
            for (int j = 0; j < n; j++) {
                if (frames[j] == -1)
                    printf(" - ");
                else
                    printf(" %d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("\nTotal number of page faults: %d\n", page_faults);

    return 0;
}
