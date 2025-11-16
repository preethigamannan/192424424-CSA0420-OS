#include <stdio.h>
struct P {int id,at,bt,rt,pr,wt,tat;} p[10];
int main() {
    int n,t=0,done=0,sm;
    printf("Enter no. of processes: "); scanf("%d",&n);
    for(int i=0;i<n;i++){p[i].id=i+1;printf("AT BT PR for P%d: ",i+1);
        scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pr);p[i].rt=p[i].bt;}
    while(done<n){
        sm=-1;
        for(int i=0;i<n;i++)
            if(p[i].at<=t && p[i].rt>0 && (sm==-1||p[i].pr<p[sm].pr)) sm=i;
        if(sm==-1){t++;continue;}
        p[sm].rt--; t++;
        if(p[sm].rt==0){done++;p[sm].tat=t-p[sm].at;p[sm].wt=p[sm].tat-p[sm].bt;}
    }
    printf("\nPID\tWT\tTAT\n");
    float aw=0,at=0;
    for(int i=0;i<n;i++){printf("P%d\t%d\t%d\n",p[i].id,p[i].wt,p[i].tat);
        aw+=p[i].wt;at+=p[i].tat;}
    printf("Avg WT=%.2f Avg TAT=%.2f\n",aw/n,at/n);
}
