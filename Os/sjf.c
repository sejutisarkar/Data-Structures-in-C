#include<stdio.h>

void findWaitingTime(int procces,int n, int wt[], int bt[]){
  wt[0] = 0;
  for(int i=1;i<n;i++){
    wt[i] = wt[i-1]+bt[i-1];
  }
}
void findTAT(int process[], int n, int wt[], int bt[], int tat[]){
  for(int i=0;i<n;i++){
    tat[i]=bt[i]+wt[i];
  }
}
void findAvgTime(int procces, int n, int bt[]){
  int wt[n], tat[n], total_wt=0, total_tat=0;

  //sort
  int min;
  for(int i=0;i<n;i++){
    min=i;
    for(int j=i+1;j<n;j++){
      if(bt[j]<bt[min])
      min=j;
    }
    int temp =bt[i];
    bt[i]=bt[min];
    bt[min]=temp;
  }
  findWaitingTime(procces,n,wt,bt);
  findTAT(procces,n,wt,bt,tat);
  for(int i =0;i<n;i++){
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i];
    printf("  %d",(i+1));
    printf("  %d",wt[i]);
    printf("  %d",tat[i]);
    printf("  %d", bt[i]);
  }
}

int main(){
  int procces[] = {1,2,3};
  int brusttime[] = {20,12,33};
  int n = sizeof procces / sizeof procces[0];
  // sort(procces,brusttime);
  findAvgTime(procces,n,brusttime);
  return 0;
}
