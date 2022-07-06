
#include<stdio.h>
#include<string.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
  int i, j;
  int temp[m];
  for(int a=0;a<m;a++)
  {
    temp[a]=blockSize[a];
  }
  int allocation[n];

  for(i = 0; i < n; i++)
  {
    allocation[i] = -1;
  }

  for (i = 0; i < n; i++)   
  {
    for (j = 0; j < m; j++) 
    {
      if (temp[j] >= processSize[i])
      {
        allocation[i] = j;

        temp[j] -= processSize[i];

        break; }
    }
  }

  printf("\nProcess No.\tProcess Size\tBlock no.\n");
  for (int i = 0; i < n; i++)
  {
    printf(" %i\t\t\t", i+1);
    printf("%i\t\t\t\t", processSize[i]);
    if (allocation[i] != -1)
      printf("%i", allocation[i] + 1);
    else
      printf("Not Allocated");
    printf("\n");
  }
}

void worstfit(int blocksize[],int m,int processSize[],int n)
{
  int allocation[n];
  int i,j;
  int temp[m];
  for(int a=0;a<m;a++)
  {
    temp[a]=blocksize[a];
  }
   for(i = 0; i < n; i++)
  {
    allocation[i] = -1;
  }

 for(i=0;i<n;i++)
  {
   int wrstidx=-1;
   for(j=0;j<m;j++)
   {
    if(temp[j]>=processSize[i])
    {
      if(wrstidx==-1)
       wrstidx=j;
      else if (temp[wrstidx]<blocksize[j])
      {
        
         wrstidx=j;
      }
    }
    }
    if(wrstidx!=-1)
    {
      allocation[i]=wrstidx;
      temp[wrstidx]-=processSize[i];
    }
   }
  printf("\nProcess No:\t Process Size\tBlock no:\n");
  for(int k=0;k<n;k++)
  {
   printf("%d\t\t\t",k+1);
   printf("%d\t\t\t\t",processSize[k]);
   if(allocation[k]!=-1)
    printf("%d",allocation[k]+1);
   else
    printf("Not allocated");
      printf("\n");
  }

}

void bestfit(int blocksize[],int m,int processsize[],int n)
{
  int allocation[n];
  int i,j;
  int temp[m];
  for(int a=0;a<m;a++)
  {
    temp[a]=blocksize[a];
  }
  
  for(i = 0; i < n; i++)
  {
    allocation[i] = -1;
  }

  
 
  for(i=0;i<n;i++)
  {
   int bstindx=-1;
   for(j=0;j<m;j++)
    {
     if(temp[j]>=processsize[i])
     {
       if(bstindx==-1)
       bstindx=j;
       else
       {
         if(temp[bstindx]>blocksize[j])
         bstindx=j;
        }
     }
    }
   if(bstindx!=-1)
   {
    allocation[i]=bstindx;
    temp[bstindx]-=processsize[i];
   }
  }
  printf("\nProcess No:\t Process Size\tBlock no:\n");
  for(int k=0;k<n;k++)
  {
   printf("%d\t\t\t",k+1);
   printf("%d\t\t\t\t",processsize[k]);
   if(allocation[k]!=-1)
    printf("%d",allocation[k]+1);
   else
    printf("Not allocated");
      printf("\n");
  }
  
}

int main()
{
  int m; 
  int n; 
  int blockSize1[] = {100, 500, 200, 300, 600};
  int processSize[] = {212, 417, 112, 426};
  m = sizeof(blockSize1) / sizeof(blockSize1[0]);
  n = sizeof(processSize) / sizeof(processSize[0]);

  firstFit(blockSize1, m, processSize, n);
  worstfit(blockSize1,m,processSize,n);
  bestfit(blockSize1,m,processSize,n);

  return 0 ;
}

