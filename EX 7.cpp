#include <stdio.h>
struct P{int id,at,bt,wt,tat;}p[10];
int main(){
 int n,t=0,done=0,sm; 
 printf("Enter no. of processes: "); scanf("%d",&n);
 for(int i=0;i<n;i++){p[i].id=i+1;printf("AT BT for P%d: ",i+1);
  scanf("%d%d",&p[i].at,&p[i].bt);}
 while(done<n){
  sm=-1;
  for(int i=0;i<n;i++)
   if(p[i].at<=t && p[i].bt>0 && (sm==-1||p[i].bt<p[sm].bt)) sm=i;
  if(sm==-1){t++;continue;}
  p[sm].wt=t-p[sm].at; t+=p[sm].bt;
  p[sm].tat=t-p[sm].at; p[sm].bt=0; done++;
 }
 printf("\nPID\tWT\tTAT\n");
 float aw=0,at=0;
 for(int i=0;i<n;i++){printf("P%d\t%d\t%d\n",p[i].id,p[i].wt,p[i].tat);
  aw+=p[i].wt; at+=p[i].tat;}
 printf("Avg WT=%.2f Avg TAT=%.2f\n",aw/n,at/n);
}
