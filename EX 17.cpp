#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], avail[m];
    int finish[n], safeSeq[n];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    int need[n][m];
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;
    printf("\nSafe Sequence: ");

    while (count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 1;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if(flag) {
                    for(k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found) {
            printf("\nSystem is in DEADLOCK!\n");
            return 0;
        }
    }

    for(i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);

    printf("\nSystem is in SAFE STATE.\n");

    return 0;
}
