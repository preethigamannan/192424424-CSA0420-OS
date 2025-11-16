#include <stdio.h>
int main() {
    int n,i,bt[10],wt[10],tat[10];
    float avgw=0,avgt=0;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    printf("Enter burst times:\n");
    for(i=0;i<n;i++) scanf("%d",&bt[i]);
    wt[0]=0;
    for(i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];
    for(i=0;i<n;i++) tat[i]=wt[i]+bt[i];
    for(i=0;i<n;i++){ avgw+=wt[i]; avgt+=tat[i]; }
    printf("\nP\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++) printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    printf("Avg WT=%.2f  Avg TAT=%.2f",avgw/n,avgt/n);
    return 0;
}
