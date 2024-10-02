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

int find_optimal(int frames[], int n, int ref_str[], int ref_len, int current) {
    int index = -1, farthest = current;
    
    for (int i = 0; i < n; i++) {
        int j;
        for (j = current; j < ref_len; j++) {
            if (frames[i] == ref_str[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        
        if (j == ref_len) {
            // If the page is not going to be used in the future, return this frame to replace.
            return i;
        }
    }
    
    // If all pages are going to be used in the future, return the one that will be used the farthest.
    return (index == -1) ? 0 : index;
}

int main() {
    int n;  // Number of memory frames
    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    int reference_string[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};  // The given reference string
    int ref_len = sizeof(reference_string) / sizeof(reference_string[0]);  // Length of the reference string

    int frames[n];  // Array to hold the frames in memory
    for (int i = 0; i < n; i++) frames[i] = -1;  // Initialize frames to -1 (empty)

    int page_faults = 0;  // Counter for page faults

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
            if (i < n) {
                // If there's still room in the frames, insert the page into the next available frame
                frames[i] = page;
            } else {
                // If frames are full, use the optimal algorithm to determine the replacement
                int replace_index = find_optimal(frames, n, reference_string, ref_len, i + 1);
                frames[replace_index] = page;
            }

            page_faults++;  // Increment page fault counter

            print_frames(frames, n);  // Print the current state of frames
        }
    }

    printf("\nTotal number of page faults: %d\n", page_faults);

    return 0;
}
