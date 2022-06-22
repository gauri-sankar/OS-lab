#include <stdio.h>


void main()
{
 int Wtime,TAtime,temp[10],count,n,sum,y,i,quant,processes[10],bt[10],wt[10],at[10],tat[10];

 printf("Enter the number of processes:");
 scanf("%d",&n);

 y=n;
 
 printf("\nEnter the quantum time:");
 scanf("%d",&quant);

 for(int i=0;i<n;i++){
 printf("\nProcess:%d",i);
 printf("\n Enter the arrival time :");
 scanf("%d",&at[i]);
 printf("\nBurst time:");
 scanf("%d",&bt[i]);
 temp[i]=bt[i];
 }
 
 printf("\nProcess\t\tBtime\t\tWtime\t\tAtime\t\tTATime\n");
 for(i=0,sum=0;y!=0;)
 {
  if((temp[i]>0)&&(temp[i]<=quant))
  {
   sum=sum+temp[i];
   temp[i]=0;
   count=1;
  }
  else if(temp[i]>0)
 {
  sum=sum+quant;
  temp[i]=temp[i]-quant;
  
 }

 if((temp[i]==0)&&(count==1))
 {
  y--;
  printf("\n%d\t%d\t%d\t%d\t%d\t",i,bt[i],sum-at[i]-bt[i],at[i],sum-at[i]);
  Wtime=Wtime+(sum-at[i]-bt[i]);
  TAtime=TAtime+(sum-at[i]);
  count=0;
 }

 if(i==n-1)
 {
  i=0;
 }
 else if(at[i+1]<=sum)
 {
  i++;
 }

 else
 {
  i==0;
 }
 }

 printf("\nAvg waiting time:%d",Wtime/n);
 printf("\nAvg turnaround time:%d",TAtime/n);
}
