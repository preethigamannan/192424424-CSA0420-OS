#include <stdio.h>
struct P{int id,bt,rt,wt,tat;}p[10];
int main(){
 int n,qt,t=0,done=0;
 printf("Enter no. of processes: "); scanf("%d",&n);
 printf("Enter time quantum: "); scanf("%d",&qt);
 for(int i=0;i<n;i++){p[i].id=i+1;printf("BT for P%d: ",i+1);
  scanf("%d",&p[i].bt);p[i].rt=p[i].bt;}
 while(done<n){
  for(int i=0;i<n;i++){
   if(p[i].rt>0){
    if(p[i].rt>qt){t+=qt;p[i].rt-=qt;}
    else{t+=p[i].rt;p[i].wt=t-p[i].bt;p[i].rt=0;done++;}
   }
  }
 }
 printf("\nPID\tWT\tTAT\n");
 float aw=0,at=0;
 for(int i=0;i<n;i++){p[i].tat=p[i].wt+p[i].bt;
  printf("P%d\t%d\t%d\n",p[i].id,p[i].wt,p[i].tat);
  aw+=p[i].wt;at+=p[i].tat;}
 printf("Avg WT=%.2f Avg TAT=%.2f\n",aw/n,at/n);
}
