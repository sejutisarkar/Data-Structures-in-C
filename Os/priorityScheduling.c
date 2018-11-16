#include<stdio.h>
int main(){
  int wt[10],bt[10],tat[10],pr[10],n,i,total_wt,temp;
  printf("enter the total process");
  scanf("%d\n",&n );
  printf("enter the brust time and priority");
  for(i=0;i<n;i++){
    printf("Burst Time:");
    scanf("%d",&bt[i]);
    printf("Priority:");
    scanf("%d",&pr[i]);
  }
  //sort the process according to the brust time and priority
  for(int i = 0;i<n;i++){
    int min = i;
    for(int j=0;j<n;j++){
      if(pr[j]<pr[min])
        min = j;
    }
    temp = pr[i];
    pr[i] = pr[min];
    pr[min] = temp;

    temp = bt[i];
    bt[i] = bt[min];
    bt[min] = temp;

    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;
  }
  wt[0] = 0;

  for(int i =0;i<n;i++){
    wt[i]=0;
    for(int j =0;j<n;j++){
      wt[i]+=bt[j]
    }
    total_wt+=wt[i];
  }
  int avg_wt = (float)total_wt / (float)n;
  total_wt=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);

    return 0;
}
