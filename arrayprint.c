#include<stdio.h>
void main()
{
 int a[100],n;
 printf("Enter the no of elements:");
 scanf("%d",&n);

 printf("\nEnter the process numbers:");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("\nEnter the burst times:");
 for(int j=0;j<n;j++)
 {
  printf("%d",a[j]);
 }

//printf("\nEnter the process numbers:");
 //for(int i=0;i<n;i++){
 //scanf("%n",&processes[i]);}
 //printf("\nEnter the burst times:");
 //for(int j=0;j<n;j++){
 //scanf("%n",&bt[j]);}

}
