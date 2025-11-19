#include <stdio.h>

int main() {
    int indexBlock, n, blocks[20], i;

    printf("Enter index block number: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter %d block numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndex Block = %d\n", indexBlock);
    printf("Blocks of file: ");
    for (i = 0; i < n; i++)
        printf("%d ", blocks[i]);

    return 0;
}
