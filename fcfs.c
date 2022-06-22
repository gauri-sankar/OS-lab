#include<stdio.h>

void Waitingtime(int processes[],int n,int wt[],int bt[])
{wt[0]=0;
 for(int i=1;i<n;i++)
 wt[i]=bt[i-1]+wt[i-1];
}

void TurnaroundTime(int processes[],int n,int wt[],int bt[],int tat[])
{
 for(int i=0;i<n;i++)
 tat[i]=bt[i]+wt[i];
}

void main()
{  int n,processes[10],bt[10];
 printf("Enter the number of processes:");
 scanf("%d",&n);
 
 printf("\nEnter the process numbers:");
 for(int i=0;i<n;i++){
 scanf("%d",&processes[i]);}
 printf("\nEnter the burst times:");
 for(int j=0;j<n;j++){
 scanf("%d",&bt[j]);}
 //int processes[]={1,2,3};

 //int bt[]={12,43,22};
 int tat[10],wt[10];
 float totalwt=0,totaltat=0;
 Waitingtime(processes,n,wt,bt);

 TurnaroundTime(processes,n,wt,bt,tat);

 printf("\nProcess\tBTime\tWTime\tTATime\n");

 for(int k=0;k<n;k++)
 {
  totalwt=totalwt+wt[k];
  totaltat=totaltat+tat[k];
  printf("%d\t%d\t%d\t%d\n",processes[k],bt[k],wt[k],tat[k]);
 } 
 printf("\nTotal avg waiting time:%f",totalwt/n);
 printf("\nTotal avg turnaroundtime:%f",totaltat/n);
}

