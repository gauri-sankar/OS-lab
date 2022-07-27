// Banker's Algorithm
#include <stdio.h>
int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, m, i, j, k;
	 int avail[m],need[n][m],alloc[n][m],max[n][m];
	 printf("\nEnter the number of processes:");
	scanf("%d",&n);
   	 printf("\nEnter the number of resources:");
	scanf("%d",&m);
         
        printf("\nEnter the number of allocated resources for each processes:");
        for(i=0;i<n;i++)
        {printf("\n Process %d",i+1);
           for(j=0;j<m;j++)
         {
           scanf("%d",&alloc[i][j]);
         } 
         }
	
	printf("Enter the max available resource for each process:");
 	for(i=0;i<n;i++)
  	{printf("\nProcess %d",i+1);
 	  for(j=0;j<m;j++)
         {
	   scanf("%d",&max[i][j]);
	  }
	}

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}

        for(i=0;i<n;i++)
        {
         printf("\n");
         for(j=0;j<m;j++)
         {
 	  printf("%d",need[i][j]);
         }
         }
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(f[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}
	

	return (0);


}

