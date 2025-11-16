#include <stdio.h>
struct P { int id, bt, pr, wt, tat; } p[10];
int main() {
    int n, i, j;
    float awt = 0, atat = 0;
    struct P temp;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter burst time and priority for P%d: ", i + 1);
        scanf("%d%d", &p[i].bt, &p[i].pr);
    }
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (p[i].pr < p[j].pr) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
    p[0].wt = 0;
    for (i = 1; i < n; i++)
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    for (i = 0; i < n; i++)
        p[i].tat = p[i].wt + p[i].bt;
    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
        awt += p[i].wt;
        atat += p[i].tat;
    }
    printf("\nAvg WT = %.2f\tAvg TAT = %.2f\n", awt / n, atat / n);
    return 0;
}