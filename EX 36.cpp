#include <stdio.h>

int main() {
    int req[20], n, head, i, movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of access: %d ", head);
    for (i = 0; i < n; i++) {
        movement += abs(req[i] - head);
        head = req[i];
        printf("-> %d ", head);
    }

    printf("\nTotal head movement = %d\n", movement);
    return 0;
}
