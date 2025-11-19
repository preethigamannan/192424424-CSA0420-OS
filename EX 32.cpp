#include <stdio.h>

int findOptimal(int pages[], int frames[], int f, int n, int index) {
    int pos = -1, farthest = index;
    for (int i = 0; i < f; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == n)
            return i; // not used again
    }
    return (pos == -1) ? 0 : pos;
}

int main() {
    int pages[30], frames[10];
    int p, f, i, j, faults = 0;

    printf("Enter no. of frames: ");
    scanf("%d", &f);

    printf("Enter no. of pages: ");
    scanf("%d", &p);

    printf("Enter page numbers:\n");
    for (i = 0; i < p; i++)
        scanf("%d", &pages[i]);

    for (i = 0; i < f; i++) frames[i] = -1;

    for (i = 0; i < p; i++) {
        int found = 0;

        for (j = 0; j < f; j++)
            if (frames[j] == pages[i]) found = 1;

        if (!found) {
            int pos = findOptimal(pages, frames, f, p, i + 1);
            frames[pos] = pages[i];
            faults++;
        }

        printf("\nFrames: ");
        for (j = 0; j < f; j++) printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
