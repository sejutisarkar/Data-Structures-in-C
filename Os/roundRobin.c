#include<stdio.h>
#include<stdbool.h>

void findWaitingTime(int process,int n, int wt[], int bt[], int quantum){
  int rem_bt[n];
  for(int i=0;i<n;i++){
    rem_bt[i]=bt[i];
  }
  int t=0;
  //traverse the whole process
  while(1){
    bool done=true;
    for(int i=0;i<n;i++){
      if(rem_bt[i] > 0){
        bool done = false;
        if(rem_bt[i] > quantum){
          t+= quantum;
          rem_bt[i]-=quantum;
        }else{
          t=t+rem_bt[i];
          wt[i]=t-bt[i];
          rem_bt[i]=0;
        }
      }
    }
    if(done == true){
      break;
    }
  }
}

void findTAT(int procces, int n,int wt[],int bt[], int tat[]){
  for(int i=0;i<n;i++){
    tat[i] = wt[i] + bt[i];
  }
}

void findAvgTime(int procces, int n, int bt[], int quantum){
  int wt[n], tat[n], total_wt = 0, total_tat=0;
  findWaitingTime(procces,n,wt,bt,quantum);
  findTAT(procces,n,wt,bt,tat);
  printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
  for(int i =0;i<n;i++){
    total_wt = total_wt + wt[i];
    total_tat = total_tat + tat[i]; 
    printf("\n[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
  }

int main(){
  int procces[] = {1,2,3};
  int n = sizeof procces / sizeof procces[0];
  int brusttime[] = {10,5,8};
  int quantum = 2;
  findAvgTime(procces,n,brusttime,quantum);
  return 0;
}
