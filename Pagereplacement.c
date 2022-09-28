#include<stdio.h>
void FIFO(int prs[],int n,int frames)
{
  int i,j,k=0,s,pagefault=0,hit=0;
  int temp[frames];


  printf("\nValues\t");
  for(i=1;i<=frames;i++)
  {
   printf("Frame%d\t",i);
  }
  printf("\n");
  for(i=0;i<frames;i++)
  {
    temp[i]=-1;
  }

  for(i=0;i<n;i++)
  {
    s=0;
    printf("\n%d->\t",prs[i]);
    for(j=0;j<frames;j++)
    { 
     if(temp[j]==prs[i])
     s=1;
      
    }
  if(s==0)
  {
    temp[k]=prs[i];
    k=(k+1)%frames;
    pagefault++;
    for(j=0;j<frames;j++)
    {  
      if(temp[j]!=-1)
      printf("%d\t",temp[j]);
    }
  }
  else  printf("\t HIT!!!!");
  }

  printf("\nPagefaults:%d",pagefault);
}

void printed(int frame[],int frames)
{
  for(int i=0;i<frames;i++)
  {
    if(frame[i]!=-1)
   {
      printf("%d\t",frame[i]);
    }
   else
   printf("\t");
  }
}

int findLRU(int time[],int frames)
{
  int pos=0,min;
  min=time[0];
  for(int i=1;i<frames;i++)
  {
    if(time[i]<min)
    {
        pos=i;
        min=time[i];
     }
  }
  return pos;
}

void LRU(int prs[],int n,int frames)
{
  int pos,i,j,flag1=0,flag2=0,counter=0,time[frames],frame[frames],pagefault=0;
  
  printf("\nValues\t");
  for(int i=1;i<=frames;i++)
  {
   printf("Frame%d\t",i);
  }
 
 // printf("\n");
  for(i=0;i<frames;i++)
  {
    frame[i]=-1;
  }
  
  for(i=0;i<n;i++)
  {
    flag1=flag2=0;
    printf("\n%d->\t",prs[i]);
    for(j=0;j<frames;j++)
    {
      if(frame[j]==prs[i])
      {
        counter++;
        time[j]=counter;
        flag1=flag2=1;
        printf("\tHIT!!!\n");
        break;
      }
    }
      
     if(flag1==0)
     {
      for(j=0;j<frames;j++)
      {
       if(frame[j]==-1)
       {
        counter++;
        time[j]=counter;
        pagefault++;
        frame[j]=prs[i];
        flag2=1;
        printed(frame,frames); 
          break;
       }
      }
     }
      if(flag2==0)
      {
       pos=findLRU(time,frames);
       counter++;
       time[j]=counter;
       frame[pos]=prs[i];
       time[pos]=counter;
       printed(frame,frames);
      }
    }
  printf("\nPagefaults:%d",pagefault);
}


 

void main()
{
  int n,frames;
  printf("\nEnter the number of pages:");
  scanf("%d",&n);
  
  int prs[n];
  printf("\n Enter the sequence:");
  for(int i=0;i<n;i++)
  {
   scanf("%d",&prs[i]);
  }

  printf("\nEnter the number of frames:");
  scanf("%d",&frames);

  //FIFO(prs,n,frames);
    LRU(prs,n,frames);
}
