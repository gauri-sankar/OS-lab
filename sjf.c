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

void swap(int n1,int n2)
{
int temp;
temp=n1;
n1=n2;
n2=temp;
}
void sort(int bt[],int n,int p[])
{
 for(int i=1;i<n;i++)
{
 for(int j=0;j<n-i;j++)
 if(bt[j]>bt[j+1])
 {
 // swap(bt[j],bt[j+1]);
  //swap(p[j],p[j+1]);
  int temp;
temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;

temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;



 }
}

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


 
 int totalwt=0,totaltat=0,tat[10],wt[10];

 sort(bt,n,processes);

 Waitingtime(processes,n,wt,bt);

 TurnaroundTime(processes,n,wt,bt,tat);

 printf("\nProcess\tBTime\tWTime\tTATime\n");

 for(int k=0;k<n;k++)
 {
  totalwt=totalwt+wt[k];
  totaltat=totaltat+tat[k];
  printf("%d\t%d\t%d\t%d\n",processes[k],bt[k],wt[k],tat[k]);
 } 
 printf("\nTotal avg waiting time:%d",totalwt);
 printf("\nTotal avg turnaroundtime:%d",totaltat);
}

