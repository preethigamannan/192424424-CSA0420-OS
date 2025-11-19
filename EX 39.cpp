#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[20], n, head, i, j, temp, size, total = 0;

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    req[n] = head;
    req[n + 1] = size;
    req[n + 2] = 0;
    n += 3;

    // Sort requests
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

    printf("\nC-SCAN Order:\n");

    for (i = pos; i < n; i++) {
        printf("%d ", req[i]);
        if (i > pos) total += abs(req[i] - req[i - 1]);
    }

    total += abs(size - 0);  // Jump

    for (i = 0; i < pos; i++) {
        printf("%d ", req[i]);
        if (i > 0) total += abs(req[i] - req[i - 1]);
    }

    printf("\nTotal Head Movement = %d\n", total);
    return 0;
}
