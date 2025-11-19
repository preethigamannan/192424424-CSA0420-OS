#include <stdio.h>

struct block {
    int data;
    int next;
} b[20];

int main() {
    int n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block number and next block (-1 for end):\n");
    for (i = 0; i < n; i++)
        scanf("%d %d", &b[i].data, &b[i].next);

    printf("\nLinked File Allocation:\n");
    int start;
    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("File blocks: ");
    while (start != -1) {
        printf("%d ", start);
        start = b[start].next;
    }
    return 0;
}
