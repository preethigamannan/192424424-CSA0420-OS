#include <stdio.h>

int main() {
    int blockSize[10], processSize[10], b, p;
    int allocation[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &b);
    printf("Enter block sizes:\n");
    for(int i = 0; i < b; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter process sizes:\n");
    for(int i = 0; i < p; i++)
        scanf("%d", &processSize[i]);

    for(int i = 0; i < p; i++)
        allocation[i] = -1;

    // Worst Fit Allocation
    for(int i = 0; i < p; i++) {
        int worstIdx = -1;

        for(int j = 0; j < b; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if(worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock Allocated\n");
    for(int i = 0; i < p; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
