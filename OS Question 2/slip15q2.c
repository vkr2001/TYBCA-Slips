#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0, i;
    for (i = 1; i < n; ++i) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int lru_page_replacement(int pages[], int n, int frames) {
    int memory_frames[frames], time[frames], counter = 0, page_faults = 0;
    int i, j, pos;

    // Initialize memory frames and time array
    for (i = 0; i < frames; i++) {
        memory_frames[i] = -1;
        time[i] = 0;
    }

    // Processing the reference string
    for (i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in the memory frames
        for (j = 0; j < frames; j++) {
            if (memory_frames[j] == pages[i]) {
                counter++;
                time[j] = counter; // Update time for the recently used page
                found = 1;
                break;
            }
        }

        if (!found) {
            // If the page is not found, handle the page fault
            page_faults++;
            if (i < frames) {
                // Insert page if there's still room
                memory_frames[i] = pages[i];
                counter++;
                time[i] = counter;
            } else {
                // Find the least recently used page and replace it
                pos = findLRU(time, frames);
                memory_frames[pos] = pages[i];
                counter++;
                time[pos] = counter;
            }
        }

        // Print the current state of the memory frames
        printf("Page %d -> Memory: ", pages[i]);
        for (j = 0; j < frames; j++) {
            if (memory_frames[j] == -1)
                printf("- ");
            else
                printf("%d ", memory_frames[j]);
        }
        printf("\n");
    }

    return page_faults;
}

int main() {
    int frames, page_faults;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; // Reference string
    int n = sizeof(pages) / sizeof(pages[0]); // Number of pages

    // Input number of memory frames
    printf("Enter the number of memory frames: ");
    scanf("%d", &frames);

    // Call LRU page replacement and get the number of page faults
    page_faults = lru_page_replacement(pages, n, frames);

    // Output the total page faults
    printf("Total Page Faults: %d\n", page_faults);

    return 0;
} 