#include <stdio.h>

int main() {
    int pages[20], frames[10], f, p, i, j, k = 0, faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter number of pages: ");
    scanf("%d", &p);

    printf("Enter page numbers:\n");
    for (i = 0; i < p; i++)
        scanf("%d", &pages[i]);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    for (i = 0; i < p; i++) {
        int hit = 0;

        for (j = 0; j < f; j++)
            if (frames[j] == pages[i])
                hit = 1;

        if (!hit) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("\nFrames: ");
        for (j = 0; j < f; j++)
            printf("%d ", frames[j]);
    }

    printf("\n\nTotal Page Faults = %d\n", faults);
    return 0;
}
