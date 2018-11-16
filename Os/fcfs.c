#include<stdio.h>

void findWaitingTime(int procces[], int n, int bt[],int wt[]){
  wt[0] = 0;
  for(int i=1;i<n;i++){
    wt[i] = bt[i-1] + wt[i-1];
  }
}

void findTAT(int process[], int n, int wt[], int bt[], int tat[]){
  for(int i=0;i<n;i++){
    tat[i]=bt[i]+wt[i];
  }
}

void findAvgTime(int process[], int n, int bt[]){
  int wt[n], tat[n], total_wt=0, total_tat=0;
  findWaitingTime(process,n,bt,wt);
  findTAT(process,n,wt,bt,tat);

  printf("process   brusttime   waitingtime   tat");
  for(int i=0;i<n;i++){
    total_wt = total_wt+wt[i];
    total_tat = total_tat+wt[i];
    printf(" %d",(i+1));
    printf("    %d",bt[i]);
    printf("    %d",wt[i]);
    printf("    %d",tat[i]);
  }
  int avg_wt = (float)total_wt / (float)n;
  int avg_tat = (float)total_tat / (float)n;
  printf("%d \n",avg_wt);
  printf("%d \n",avg_tat);
}
int main(){
  int process[] = {1,2,3};
  int n = sizeof process / sizeof process[0];
  int brusttime[] = {12,32,11};
  findAvgTime(process,n,brusttime);
  return 0;
}
