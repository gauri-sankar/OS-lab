#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void main()
{
int n,i,j;
int sumeven=0;
int sumodd=0;
printf("Enter the limit:");
scanf("%d",&n);


int id=fork();
if(id!=0)
{
 for( i=1;i<n;i++)
 {
  if(i%2==1){
  sumodd=sumodd+i;
printf("%d\n",sumodd);
 }
}
printf("\nSum of odd no's is:%d",sumodd);
printf("\nProcess id is %d\n",getppid());
}


 

else 
{
for( j=1;j<n;j++)
{ 
 if(j%2==0){
 sumeven=sumeven+j;
printf("%d\n",sumeven);
}
}
printf("\nSum of even is:%d",sumeven);
printf("\nProcess id is:%d",getpid());
 
 



}
}
