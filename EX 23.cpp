#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], allocation[10];
    int b, p;

    printf("Enter number of memory blocks: ");
    scanf("%d", &b);
    printf("Enter block sizes:\n");
    for (int i = 0; i < b; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter process sizes:\n");
    for (int i = 0; i < p; i++)
        scanf("%d", &processSize[i]);

    // Initially, no process is allocated
    for (int i = 0; i < p; i++)
        allocation[i] = -1;

    // First Fit Allocation
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < b; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;  // stop at the first suitable block
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock Allocated\n");
    for (int i = 0; i < p; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
