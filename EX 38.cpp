#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, i, j, temp, size, dir, total = 0;

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("Enter direction (1 = right, 0 = left): ");
    scanf("%d", &dir);

    req[n] = head;
    req[n + 1] = (dir == 1) ? size : 0;
    n += 2;

    // Sort
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    int pos;
    for (i = 0; i < n; i++)
        if (req[i] == head) {
            pos = i;
            break;
        }

    printf("\nSCAN Order
